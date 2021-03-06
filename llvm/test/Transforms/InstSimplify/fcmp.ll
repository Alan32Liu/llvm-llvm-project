; NOTE: Assertions have been autogenerated by utils/update_test_checks.py
; RUN: opt < %s -passes=instsimplify -S | FileCheck %s

define i1 @poison(float %x) {
; CHECK-LABEL: @poison(
; CHECK-NEXT:    ret i1 poison
;
  %v = fcmp oeq float %x, poison
  ret i1 %v
}

define i1 @poison2(float %x) {
; CHECK-LABEL: @poison2(
; CHECK-NEXT:    ret i1 poison
;
  %v = fcmp ueq float %x, poison
  ret i1 %v
}
