// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py UTC_ARGS: --function-signature --include-generated-funcs
// RUN: %clang_cc1 -fopenmp-enable-irbuilder -verify -fopenmp -fopenmp-version=51 -x c -triple x86_64-unknown-unknown -emit-llvm %s -o - | FileCheck %s
// expected-no-diagnostics

// REQUIRES: x86-registered-target

#ifndef HEADER
#define HEADER

double sind(double);

// CHECK-LABEL: define {{.*}}@unroll_partial_heuristic_runtime_for(
// CHECK-NEXT:  [[ENTRY:.*]]:
// CHECK-NEXT:    %[[N_ADDR:.+]] = alloca i32, align 4
// CHECK-NEXT:    %[[A_ADDR:.+]] = alloca float*, align 8
// CHECK-NEXT:    %[[B_ADDR:.+]] = alloca float*, align 8
// CHECK-NEXT:    %[[C_ADDR:.+]] = alloca float*, align 8
// CHECK-NEXT:    %[[D_ADDR:.+]] = alloca float*, align 8
// CHECK-NEXT:    %[[E_ADDR:.+]] = alloca float*, align 8
// CHECK-NEXT:    %[[OFFSET_ADDR:.+]] = alloca float, align 4
// CHECK-NEXT:    %[[I:.+]] = alloca i32, align 4
// CHECK-NEXT:    %[[AGG_CAPTURED:.+]] = alloca %struct.anon, align 8
// CHECK-NEXT:    %[[AGG_CAPTURED1:.+]] = alloca %struct.anon.0, align 4
// CHECK-NEXT:    %[[DOTCOUNT_ADDR:.+]] = alloca i32, align 4
// CHECK-NEXT:    %[[P_LASTITER:.+]] = alloca i32, align 4
// CHECK-NEXT:    %[[P_LOWERBOUND:.+]] = alloca i32, align 4
// CHECK-NEXT:    %[[P_UPPERBOUND:.+]] = alloca i32, align 4
// CHECK-NEXT:    %[[P_STRIDE:.+]] = alloca i32, align 4
// CHECK-NEXT:    store i32 %[[N:.+]], i32* %[[N_ADDR]], align 4
// CHECK-NEXT:    store float* %[[A:.+]], float** %[[A_ADDR]], align 8
// CHECK-NEXT:    store float* %[[B:.+]], float** %[[B_ADDR]], align 8
// CHECK-NEXT:    store float* %[[C:.+]], float** %[[C_ADDR]], align 8
// CHECK-NEXT:    store float* %[[D:.+]], float** %[[D_ADDR]], align 8
// CHECK-NEXT:    store float* %[[E:.+]], float** %[[E_ADDR]], align 8
// CHECK-NEXT:    store float %[[OFFSET:.+]], float* %[[OFFSET_ADDR]], align 4
// CHECK-NEXT:    store i32 0, i32* %[[I]], align 4
// CHECK-NEXT:    %[[TMP0:.+]] = getelementptr inbounds %struct.anon, %struct.anon* %[[AGG_CAPTURED]], i32 0, i32 0
// CHECK-NEXT:    store i32* %[[I]], i32** %[[TMP0]], align 8
// CHECK-NEXT:    %[[TMP1:.+]] = getelementptr inbounds %struct.anon, %struct.anon* %[[AGG_CAPTURED]], i32 0, i32 1
// CHECK-NEXT:    store i32* %[[N_ADDR]], i32** %[[TMP1]], align 8
// CHECK-NEXT:    %[[TMP2:.+]] = getelementptr inbounds %struct.anon.0, %struct.anon.0* %[[AGG_CAPTURED1]], i32 0, i32 0
// CHECK-NEXT:    %[[TMP3:.+]] = load i32, i32* %[[I]], align 4
// CHECK-NEXT:    store i32 %[[TMP3]], i32* %[[TMP2]], align 4
// CHECK-NEXT:    call void @__captured_stmt(i32* %[[DOTCOUNT_ADDR]], %struct.anon* %[[AGG_CAPTURED]])
// CHECK-NEXT:    %[[DOTCOUNT:.+]] = load i32, i32* %[[DOTCOUNT_ADDR]], align 4
// CHECK-NEXT:    br label %[[OMP_LOOP_PREHEADER:.+]]
// CHECK-EMPTY:
// CHECK-NEXT:  [[OMP_LOOP_PREHEADER]]:
// CHECK-NEXT:    %[[TMP4:.+]] = udiv i32 %[[DOTCOUNT]], 4
// CHECK-NEXT:    %[[TMP5:.+]] = urem i32 %[[DOTCOUNT]], 4
// CHECK-NEXT:    %[[TMP6:.+]] = icmp ne i32 %[[TMP5]], 0
// CHECK-NEXT:    %[[TMP7:.+]] = zext i1 %[[TMP6]] to i32
// CHECK-NEXT:    %[[OMP_FLOOR0_TRIPCOUNT:.+]] = add nuw i32 %[[TMP4]], %[[TMP7]]
// CHECK-NEXT:    br label %[[OMP_FLOOR0_PREHEADER:.+]]
// CHECK-EMPTY:
// CHECK-NEXT:  [[OMP_FLOOR0_PREHEADER]]:
// CHECK-NEXT:    store i32 0, i32* %[[P_LOWERBOUND]], align 4
// CHECK-NEXT:    %[[TMP8:.+]] = sub i32 %[[OMP_FLOOR0_TRIPCOUNT]], 1
// CHECK-NEXT:    store i32 %[[TMP8]], i32* %[[P_UPPERBOUND]], align 4
// CHECK-NEXT:    store i32 1, i32* %[[P_STRIDE]], align 4
// CHECK-NEXT:    %[[OMP_GLOBAL_THREAD_NUM:.+]] = call i32 @__kmpc_global_thread_num(%struct.ident_t* @1)
// CHECK-NEXT:    call void @__kmpc_for_static_init_4u(%struct.ident_t* @1, i32 %[[OMP_GLOBAL_THREAD_NUM]], i32 34, i32* %[[P_LASTITER]], i32* %[[P_LOWERBOUND]], i32* %[[P_UPPERBOUND]], i32* %[[P_STRIDE]], i32 1, i32 0)
// CHECK-NEXT:    %[[TMP9:.+]] = load i32, i32* %[[P_LOWERBOUND]], align 4
// CHECK-NEXT:    %[[TMP10:.+]] = load i32, i32* %[[P_UPPERBOUND]], align 4
// CHECK-NEXT:    %[[TMP11:.+]] = sub i32 %[[TMP10]], %[[TMP9]]
// CHECK-NEXT:    %[[TMP12:.+]] = add i32 %[[TMP11]], 1
// CHECK-NEXT:    br label %[[OMP_FLOOR0_HEADER:.+]]
// CHECK-EMPTY:
// CHECK-NEXT:  [[OMP_FLOOR0_HEADER]]:
// CHECK-NEXT:    %[[OMP_FLOOR0_IV:.+]] = phi i32 [ 0, %[[OMP_FLOOR0_PREHEADER]] ], [ %[[OMP_FLOOR0_NEXT:.+]], %[[OMP_FLOOR0_INC:.+]] ]
// CHECK-NEXT:    br label %[[OMP_FLOOR0_COND:.+]]
// CHECK-EMPTY:
// CHECK-NEXT:  [[OMP_FLOOR0_COND]]:
// CHECK-NEXT:    %[[OMP_FLOOR0_CMP:.+]] = icmp ult i32 %[[OMP_FLOOR0_IV]], %[[TMP12]]
// CHECK-NEXT:    br i1 %[[OMP_FLOOR0_CMP]], label %[[OMP_FLOOR0_BODY:.+]], label %[[OMP_FLOOR0_EXIT:.+]]
// CHECK-EMPTY:
// CHECK-NEXT:  [[OMP_FLOOR0_BODY]]:
// CHECK-NEXT:    %[[TMP13:.+]] = add i32 %[[OMP_FLOOR0_IV]], %[[TMP9]]
// CHECK-NEXT:    %[[TMP14:.+]] = icmp eq i32 %[[TMP13]], %[[OMP_FLOOR0_TRIPCOUNT]]
// CHECK-NEXT:    %[[TMP15:.+]] = select i1 %[[TMP14]], i32 %[[TMP5]], i32 4
// CHECK-NEXT:    br label %[[OMP_TILE0_PREHEADER:.+]]
// CHECK-EMPTY:
// CHECK-NEXT:  [[OMP_TILE0_PREHEADER]]:
// CHECK-NEXT:    br label %[[OMP_TILE0_HEADER:.+]]
// CHECK-EMPTY:
// CHECK-NEXT:  [[OMP_TILE0_HEADER]]:
// CHECK-NEXT:    %[[OMP_TILE0_IV:.+]] = phi i32 [ 0, %[[OMP_TILE0_PREHEADER]] ], [ %[[OMP_TILE0_NEXT:.+]], %[[OMP_TILE0_INC:.+]] ]
// CHECK-NEXT:    br label %[[OMP_TILE0_COND:.+]]
// CHECK-EMPTY:
// CHECK-NEXT:  [[OMP_TILE0_COND]]:
// CHECK-NEXT:    %[[OMP_TILE0_CMP:.+]] = icmp ult i32 %[[OMP_TILE0_IV]], %[[TMP15]]
// CHECK-NEXT:    br i1 %[[OMP_TILE0_CMP]], label %[[OMP_TILE0_BODY:.+]], label %[[OMP_TILE0_EXIT:.+]]
// CHECK-EMPTY:
// CHECK-NEXT:  [[OMP_TILE0_BODY]]:
// CHECK-NEXT:    %[[TMP16:.+]] = mul nuw i32 4, %[[TMP13]]
// CHECK-NEXT:    %[[TMP17:.+]] = add nuw i32 %[[TMP16]], %[[OMP_TILE0_IV]]
// CHECK-NEXT:    br label %[[OMP_LOOP_BODY:.+]]
// CHECK-EMPTY:
// CHECK-NEXT:  [[OMP_LOOP_BODY]]:
// CHECK-NEXT:    call void @__captured_stmt.1(i32* %[[I]], i32 %[[TMP17]], %struct.anon.0* %[[AGG_CAPTURED1]])
// CHECK-NEXT:    %[[TMP18:.+]] = load float*, float** %[[B_ADDR]], align 8
// CHECK-NEXT:    %[[TMP19:.+]] = load i32, i32* %[[I]], align 4
// CHECK-NEXT:    %[[IDXPROM:.+]] = sext i32 %[[TMP19]] to i64
// CHECK-NEXT:    %[[ARRAYIDX:.+]] = getelementptr inbounds float, float* %[[TMP18]], i64 %[[IDXPROM]]
// CHECK-NEXT:    %[[TMP20:.+]] = load float, float* %[[ARRAYIDX]], align 4
// CHECK-NEXT:    %[[CONV:.+]] = fpext float %[[TMP20]] to double
// CHECK-NEXT:    %[[CALL:.+]] = call double @sind(double noundef %[[CONV]])
// CHECK-NEXT:    %[[TMP21:.+]] = load float*, float** %[[C_ADDR]], align 8
// CHECK-NEXT:    %[[TMP22:.+]] = load i32, i32* %[[I]], align 4
// CHECK-NEXT:    %[[IDXPROM2:.+]] = sext i32 %[[TMP22]] to i64
// CHECK-NEXT:    %[[ARRAYIDX3:.+]] = getelementptr inbounds float, float* %[[TMP21]], i64 %[[IDXPROM2]]
// CHECK-NEXT:    %[[TMP23:.+]] = load float, float* %[[ARRAYIDX3]], align 4
// CHECK-NEXT:    %[[CONV4:.+]] = fpext float %[[TMP23]] to double
// CHECK-NEXT:    %[[MUL:.+]] = fmul double %[[CALL]], %[[CONV4]]
// CHECK-NEXT:    %[[TMP24:.+]] = load float*, float** %[[D_ADDR]], align 8
// CHECK-NEXT:    %[[TMP25:.+]] = load i32, i32* %[[I]], align 4
// CHECK-NEXT:    %[[IDXPROM5:.+]] = sext i32 %[[TMP25]] to i64
// CHECK-NEXT:    %[[ARRAYIDX6:.+]] = getelementptr inbounds float, float* %[[TMP24]], i64 %[[IDXPROM5]]
// CHECK-NEXT:    %[[TMP26:.+]] = load float, float* %[[ARRAYIDX6]], align 4
// CHECK-NEXT:    %[[CONV7:.+]] = fpext float %[[TMP26]] to double
// CHECK-NEXT:    %[[MUL8:.+]] = fmul double %[[MUL]], %[[CONV7]]
// CHECK-NEXT:    %[[TMP27:.+]] = load float*, float** %[[E_ADDR]], align 8
// CHECK-NEXT:    %[[TMP28:.+]] = load i32, i32* %[[I]], align 4
// CHECK-NEXT:    %[[IDXPROM9:.+]] = sext i32 %[[TMP28]] to i64
// CHECK-NEXT:    %[[ARRAYIDX10:.+]] = getelementptr inbounds float, float* %[[TMP27]], i64 %[[IDXPROM9]]
// CHECK-NEXT:    %[[TMP29:.+]] = load float, float* %[[ARRAYIDX10]], align 4
// CHECK-NEXT:    %[[CONV11:.+]] = fpext float %[[TMP29]] to double
// CHECK-NEXT:    %[[MUL12:.+]] = fmul double %[[MUL8]], %[[CONV11]]
// CHECK-NEXT:    %[[TMP30:.+]] = load float, float* %[[OFFSET_ADDR]], align 4
// CHECK-NEXT:    %[[CONV13:.+]] = fpext float %[[TMP30]] to double
// CHECK-NEXT:    %[[ADD:.+]] = fadd double %[[MUL12]], %[[CONV13]]
// CHECK-NEXT:    %[[TMP31:.+]] = load float*, float** %[[A_ADDR]], align 8
// CHECK-NEXT:    %[[TMP32:.+]] = load i32, i32* %[[I]], align 4
// CHECK-NEXT:    %[[IDXPROM14:.+]] = sext i32 %[[TMP32]] to i64
// CHECK-NEXT:    %[[ARRAYIDX15:.+]] = getelementptr inbounds float, float* %[[TMP31]], i64 %[[IDXPROM14]]
// CHECK-NEXT:    %[[TMP33:.+]] = load float, float* %[[ARRAYIDX15]], align 4
// CHECK-NEXT:    %[[CONV16:.+]] = fpext float %[[TMP33]] to double
// CHECK-NEXT:    %[[ADD17:.+]] = fadd double %[[CONV16]], %[[ADD]]
// CHECK-NEXT:    %[[CONV18:.+]] = fptrunc double %[[ADD17]] to float
// CHECK-NEXT:    store float %[[CONV18]], float* %[[ARRAYIDX15]], align 4
// CHECK-NEXT:    br label %[[OMP_TILE0_INC]]
// CHECK-EMPTY:
// CHECK-NEXT:  [[OMP_TILE0_INC]]:
// CHECK-NEXT:    %[[OMP_TILE0_NEXT]] = add nuw i32 %[[OMP_TILE0_IV]], 1
// CHECK-NEXT:    br label %[[OMP_TILE0_HEADER]], !llvm.loop ![[LOOP3:[0-9]+]]
// CHECK-EMPTY:
// CHECK-NEXT:  [[OMP_TILE0_EXIT]]:
// CHECK-NEXT:    br label %[[OMP_TILE0_AFTER:.+]]
// CHECK-EMPTY:
// CHECK-NEXT:  [[OMP_TILE0_AFTER]]:
// CHECK-NEXT:    br label %[[OMP_FLOOR0_INC]]
// CHECK-EMPTY:
// CHECK-NEXT:  [[OMP_FLOOR0_INC]]:
// CHECK-NEXT:    %[[OMP_FLOOR0_NEXT]] = add nuw i32 %[[OMP_FLOOR0_IV]], 1
// CHECK-NEXT:    br label %[[OMP_FLOOR0_HEADER]]
// CHECK-EMPTY:
// CHECK-NEXT:  [[OMP_FLOOR0_EXIT]]:
// CHECK-NEXT:    call void @__kmpc_for_static_fini(%struct.ident_t* @1, i32 %[[OMP_GLOBAL_THREAD_NUM]])
// CHECK-NEXT:    %[[OMP_GLOBAL_THREAD_NUM19:.+]] = call i32 @__kmpc_global_thread_num(%struct.ident_t* @1)
// CHECK-NEXT:    call void @__kmpc_barrier(%struct.ident_t* @2, i32 %[[OMP_GLOBAL_THREAD_NUM19]])
// CHECK-NEXT:    br label %[[OMP_FLOOR0_AFTER:.+]]
// CHECK-EMPTY:
// CHECK-NEXT:  [[OMP_FLOOR0_AFTER]]:
// CHECK-NEXT:    br label %[[OMP_LOOP_AFTER:.+]]
// CHECK-EMPTY:
// CHECK-NEXT:  [[OMP_LOOP_AFTER]]:
// CHECK-NEXT:    ret void
// CHECK-NEXT:  }

void unroll_partial_heuristic_runtime_for(int n, float *a, float *b, float *c, float *d, float *e, float offset) {
#pragma omp for
#pragma omp unroll partial
  for (int i = 0; i < n; i++) {
    a[i] += sind(b[i]) * c[i] * d[i] * e[i] + offset;
  }
}

#endif // HEADER

// CHECK-LABEL: define {{.*}}@__captured_stmt(
// CHECK-NEXT:  [[ENTRY:.*]]:
// CHECK-NEXT:    %[[DISTANCE_ADDR:.+]] = alloca i32*, align 8
// CHECK-NEXT:    %[[__CONTEXT_ADDR:.+]] = alloca %struct.anon*, align 8
// CHECK-NEXT:    %[[DOTSTART:.+]] = alloca i32, align 4
// CHECK-NEXT:    %[[DOTSTOP:.+]] = alloca i32, align 4
// CHECK-NEXT:    %[[DOTSTEP:.+]] = alloca i32, align 4
// CHECK-NEXT:    store i32* %[[DISTANCE:.+]], i32** %[[DISTANCE_ADDR]], align 8
// CHECK-NEXT:    store %struct.anon* %[[__CONTEXT:.+]], %struct.anon** %[[__CONTEXT_ADDR]], align 8
// CHECK-NEXT:    %[[TMP0:.+]] = load %struct.anon*, %struct.anon** %[[__CONTEXT_ADDR]], align 8
// CHECK-NEXT:    %[[TMP1:.+]] = getelementptr inbounds %struct.anon, %struct.anon* %[[TMP0]], i32 0, i32 0
// CHECK-NEXT:    %[[TMP2:.+]] = load i32*, i32** %[[TMP1]], align 8
// CHECK-NEXT:    %[[TMP3:.+]] = load i32, i32* %[[TMP2]], align 4
// CHECK-NEXT:    store i32 %[[TMP3]], i32* %[[DOTSTART]], align 4
// CHECK-NEXT:    %[[TMP4:.+]] = getelementptr inbounds %struct.anon, %struct.anon* %[[TMP0]], i32 0, i32 1
// CHECK-NEXT:    %[[TMP5:.+]] = load i32*, i32** %[[TMP4]], align 8
// CHECK-NEXT:    %[[TMP6:.+]] = load i32, i32* %[[TMP5]], align 4
// CHECK-NEXT:    store i32 %[[TMP6]], i32* %[[DOTSTOP]], align 4
// CHECK-NEXT:    store i32 1, i32* %[[DOTSTEP]], align 4
// CHECK-NEXT:    %[[TMP7:.+]] = load i32, i32* %[[DOTSTART]], align 4
// CHECK-NEXT:    %[[TMP8:.+]] = load i32, i32* %[[DOTSTOP]], align 4
// CHECK-NEXT:    %[[CMP:.+]] = icmp slt i32 %[[TMP7]], %[[TMP8]]
// CHECK-NEXT:    br i1 %[[CMP]], label %[[COND_TRUE:.+]], label %[[COND_FALSE:.+]]
// CHECK-EMPTY:
// CHECK-NEXT:  [[COND_TRUE]]:
// CHECK-NEXT:    %[[TMP9:.+]] = load i32, i32* %[[DOTSTOP]], align 4
// CHECK-NEXT:    %[[TMP10:.+]] = load i32, i32* %[[DOTSTART]], align 4
// CHECK-NEXT:    %[[SUB:.+]] = sub nsw i32 %[[TMP9]], %[[TMP10]]
// CHECK-NEXT:    %[[TMP11:.+]] = load i32, i32* %[[DOTSTEP]], align 4
// CHECK-NEXT:    %[[SUB1:.+]] = sub i32 %[[TMP11]], 1
// CHECK-NEXT:    %[[ADD:.+]] = add i32 %[[SUB]], %[[SUB1]]
// CHECK-NEXT:    %[[TMP12:.+]] = load i32, i32* %[[DOTSTEP]], align 4
// CHECK-NEXT:    %[[DIV:.+]] = udiv i32 %[[ADD]], %[[TMP12]]
// CHECK-NEXT:    br label %[[COND_END:.+]]
// CHECK-EMPTY:
// CHECK-NEXT:  [[COND_FALSE]]:
// CHECK-NEXT:    br label %[[COND_END]]
// CHECK-EMPTY:
// CHECK-NEXT:  [[COND_END]]:
// CHECK-NEXT:    %[[COND:.+]] = phi i32 [ %[[DIV]], %[[COND_TRUE]] ], [ 0, %[[COND_FALSE]] ]
// CHECK-NEXT:    %[[TMP13:.+]] = load i32*, i32** %[[DISTANCE_ADDR]], align 8
// CHECK-NEXT:    store i32 %[[COND]], i32* %[[TMP13]], align 4
// CHECK-NEXT:    ret void
// CHECK-NEXT:  }


// CHECK-LABEL: define {{.*}}@__captured_stmt.1(
// CHECK-NEXT:  [[ENTRY:.*]]:
// CHECK-NEXT:    %[[LOOPVAR_ADDR:.+]] = alloca i32*, align 8
// CHECK-NEXT:    %[[LOGICAL_ADDR:.+]] = alloca i32, align 4
// CHECK-NEXT:    %[[__CONTEXT_ADDR:.+]] = alloca %struct.anon.0*, align 8
// CHECK-NEXT:    store i32* %[[LOOPVAR:.+]], i32** %[[LOOPVAR_ADDR]], align 8
// CHECK-NEXT:    store i32 %[[LOGICAL:.+]], i32* %[[LOGICAL_ADDR]], align 4
// CHECK-NEXT:    store %struct.anon.0* %[[__CONTEXT:.+]], %struct.anon.0** %[[__CONTEXT_ADDR]], align 8
// CHECK-NEXT:    %[[TMP0:.+]] = load %struct.anon.0*, %struct.anon.0** %[[__CONTEXT_ADDR]], align 8
// CHECK-NEXT:    %[[TMP1:.+]] = getelementptr inbounds %struct.anon.0, %struct.anon.0* %[[TMP0]], i32 0, i32 0
// CHECK-NEXT:    %[[TMP2:.+]] = load i32, i32* %[[TMP1]], align 4
// CHECK-NEXT:    %[[TMP3:.+]] = load i32, i32* %[[LOGICAL_ADDR]], align 4
// CHECK-NEXT:    %[[MUL:.+]] = mul i32 1, %[[TMP3]]
// CHECK-NEXT:    %[[ADD:.+]] = add i32 %[[TMP2]], %[[MUL]]
// CHECK-NEXT:    %[[TMP4:.+]] = load i32*, i32** %[[LOOPVAR_ADDR]], align 8
// CHECK-NEXT:    store i32 %[[ADD]], i32* %[[TMP4]], align 4
// CHECK-NEXT:    ret void
// CHECK-NEXT:  }


// CHECK: ![[META0:[0-9]+]] = !{i32 1, !"wchar_size", i32 4}
// CHECK: ![[META1:[0-9]+]] = !{i32 7, !"openmp", i32 51}
// CHECK: ![[META2:[0-9]+]] =
// CHECK: ![[LOOP3]] = distinct !{![[LOOP3]], ![[LOOPPROP4:[0-9]+]], ![[LOOPPROP5:[0-9]+]]}
// CHECK: ![[LOOPPROP4]] = !{!"llvm.loop.unroll.enable"}
// CHECK: ![[LOOPPROP5]] = !{!"llvm.loop.unroll.count", i32 4}
