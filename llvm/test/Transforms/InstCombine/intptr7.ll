; NOTE: Assertions have been autogenerated by utils/update_test_checks.py
; RUN: opt < %s  -passes=instcombine -S | FileCheck %s

define void @matching_phi(i64 %a, float* %b, i1 %cond) {
; CHECK-LABEL: @matching_phi(
; CHECK-NEXT:  entry:
; CHECK-NEXT:    br i1 [[COND:%.*]], label [[BB2:%.*]], label [[BB1:%.*]]
; CHECK:       bb1:
; CHECK-NEXT:    [[ADDB:%.*]] = getelementptr inbounds float, float* [[B:%.*]], i64 2
; CHECK-NEXT:    br label [[BB3:%.*]]
; CHECK:       bb2:
; CHECK-NEXT:    [[ADD_INT:%.*]] = add i64 [[A:%.*]], 1
; CHECK-NEXT:    [[ADD:%.*]] = inttoptr i64 [[ADD_INT]] to float*
; CHECK-NEXT:    store float 1.000000e+01, float* [[ADD]], align 4
; CHECK-NEXT:    br label [[BB3]]
; CHECK:       bb3:
; CHECK-NEXT:    [[A_ADDR_03:%.*]] = phi float* [ [[ADDB]], [[BB1]] ], [ [[ADD]], [[BB2]] ]
; CHECK-NEXT:    [[I1:%.*]] = load float, float* [[A_ADDR_03]], align 4
; CHECK-NEXT:    [[MUL_I:%.*]] = fmul float [[I1]], 4.200000e+01
; CHECK-NEXT:    store float [[MUL_I]], float* [[A_ADDR_03]], align 4
; CHECK-NEXT:    ret void
;
entry:
  %cmp1 = icmp  eq i1 %cond, 0
  %add.int = add i64 %a, 1
  %add = inttoptr i64 %add.int to float *

  %addb = getelementptr inbounds float, float* %b, i64 2
  %addb.int = ptrtoint float* %addb to i64
  br i1 %cmp1, label %bb1, label %bb2
bb1:
  br label %bb3
bb2:
  store float 1.0e+01, float* %add, align 4
  br label %bb3

bb3:
  %a.addr.03 = phi float* [ %addb, %bb1 ], [ %add, %bb2 ]
  %b.addr.02 = phi i64 [ %addb.int, %bb1 ], [ %add.int, %bb2 ]
  %i0 = inttoptr i64 %b.addr.02 to float*
  %i1 = load float, float* %i0, align 4
  %mul.i = fmul float %i1, 4.200000e+01
  store float %mul.i, float* %a.addr.03, align 4
  ret void
}

define void @no_matching_phi(i64 %a, float* %b, i1 %cond) {
; CHECK-LABEL: @no_matching_phi(
; CHECK-NEXT:  entry:
; CHECK-NEXT:    [[ADD_INT:%.*]] = add i64 [[A:%.*]], 1
; CHECK-NEXT:    [[ADDB:%.*]] = getelementptr inbounds float, float* [[B:%.*]], i64 2
; CHECK-NEXT:    br i1 [[COND:%.*]], label [[B:%.*]], label [[A:%.*]]
; CHECK:       A:
; CHECK-NEXT:    br label [[C:%.*]]
; CHECK:       B:
; CHECK-NEXT:    [[ADDB_INT:%.*]] = ptrtoint float* [[ADDB]] to i64
; CHECK-NEXT:    [[ADD:%.*]] = inttoptr i64 [[ADD_INT]] to float*
; CHECK-NEXT:    store float 1.000000e+01, float* [[ADD]], align 4
; CHECK-NEXT:    br label [[C]]
; CHECK:       C:
; CHECK-NEXT:    [[A_ADDR_03:%.*]] = phi float* [ [[ADDB]], [[A]] ], [ [[ADD]], [[B]] ]
; CHECK-NEXT:    [[B_ADDR_02:%.*]] = phi i64 [ [[ADD_INT]], [[A]] ], [ [[ADDB_INT]], [[B]] ]
; CHECK-NEXT:    [[I0:%.*]] = inttoptr i64 [[B_ADDR_02]] to float*
; CHECK-NEXT:    [[I1:%.*]] = load float, float* [[I0]], align 4
; CHECK-NEXT:    [[MUL_I:%.*]] = fmul float [[I1]], 4.200000e+01
; CHECK-NEXT:    store float [[MUL_I]], float* [[A_ADDR_03]], align 4
; CHECK-NEXT:    ret void
;
entry:
  %cmp1 = icmp  eq i1 %cond, 0
  %add.int = add i64 %a, 1
  %add = inttoptr i64 %add.int to float *

  %addb = getelementptr inbounds float, float* %b, i64 2
  %addb.int = ptrtoint float* %addb to i64
  br i1 %cmp1, label %A, label %B
A:
  br label %C
B:
  store float 1.0e+01, float* %add, align 4
  br label %C

C:
  %a.addr.03 = phi float* [ %addb, %A ], [ %add, %B ]
  %b.addr.02 = phi i64 [ %addb.int, %B ], [ %add.int, %A ]
  %i0 = inttoptr i64 %b.addr.02 to float*
  %i1 = load float, float* %i0, align 4
  %mul.i = fmul float %i1, 4.200000e+01
  store float %mul.i, float* %a.addr.03, align 4
  ret void
}
