; NOTE: Assertions have been autogenerated by utils/update_mir_test_checks.py
; RUN: llc -mtriple=amdgcn-amd-amdhsa -mcpu=gfx900 -stop-after=finalize-isel -o - %s | FileCheck -check-prefix=GCN %s

; Make sure nofpexcept flags are emitted when lowering a
; non-constrained fdiv.

define float @fdiv_f32(float %a, float %b) #0 {
  ; GCN-LABEL: name: fdiv_f32
  ; GCN: bb.0.entry:
  ; GCN-NEXT:   liveins: $vgpr0, $vgpr1
  ; GCN-NEXT: {{  $}}
  ; GCN-NEXT:   [[COPY:%[0-9]+]]:vgpr_32 = COPY $vgpr1
  ; GCN-NEXT:   [[COPY1:%[0-9]+]]:vgpr_32 = COPY $vgpr0
  ; GCN-NEXT:   %4:vgpr_32, %5:sreg_64 = nofpexcept V_DIV_SCALE_F32_e64 0, [[COPY1]], 0, [[COPY]], 0, [[COPY1]], 0, 0, implicit $mode, implicit $exec
  ; GCN-NEXT:   %6:vgpr_32, %7:sreg_64 = nofpexcept V_DIV_SCALE_F32_e64 0, [[COPY]], 0, [[COPY]], 0, [[COPY1]], 0, 0, implicit $mode, implicit $exec
  ; GCN-NEXT:   %8:vgpr_32 = nofpexcept V_RCP_F32_e64 0, %6, 0, 0, implicit $mode, implicit $exec
  ; GCN-NEXT:   [[S_MOV_B32_:%[0-9]+]]:sreg_32 = S_MOV_B32 3
  ; GCN-NEXT:   [[S_MOV_B32_1:%[0-9]+]]:sgpr_32 = S_MOV_B32 1065353216
  ; GCN-NEXT:   [[S_MOV_B32_2:%[0-9]+]]:sreg_32 = S_MOV_B32 0
  ; GCN-NEXT:   S_SETREG_B32_mode killed [[S_MOV_B32_]], 2305, implicit-def $mode, implicit $mode
  ; GCN-NEXT:   %12:vgpr_32 = nofpexcept V_FMA_F32_e64 1, %6, 0, %8, 0, killed [[S_MOV_B32_1]], 0, 0, implicit $mode, implicit $exec
  ; GCN-NEXT:   %13:vgpr_32 = nofpexcept V_FMA_F32_e64 0, killed %12, 0, %8, 0, %8, 0, 0, implicit $mode, implicit $exec
  ; GCN-NEXT:   %14:vgpr_32 = nofpexcept V_MUL_F32_e64 0, %4, 0, %13, 0, 0, implicit $mode, implicit $exec
  ; GCN-NEXT:   %15:vgpr_32 = nofpexcept V_FMA_F32_e64 1, %6, 0, %14, 0, %4, 0, 0, implicit $mode, implicit $exec
  ; GCN-NEXT:   %16:vgpr_32 = nofpexcept V_FMA_F32_e64 0, killed %15, 0, %13, 0, %14, 0, 0, implicit $mode, implicit $exec
  ; GCN-NEXT:   %17:vgpr_32 = nofpexcept V_FMA_F32_e64 1, %6, 0, %16, 0, %4, 0, 0, implicit $mode, implicit $exec
  ; GCN-NEXT:   S_SETREG_B32_mode killed [[S_MOV_B32_2]], 2305, implicit-def dead $mode, implicit $mode
  ; GCN-NEXT:   $vcc = COPY %5
  ; GCN-NEXT:   %18:vgpr_32 = nofpexcept V_DIV_FMAS_F32_e64 0, killed %17, 0, %13, 0, %16, 0, 0, implicit $mode, implicit $vcc, implicit $exec
  ; GCN-NEXT:   %19:vgpr_32 = nofpexcept V_DIV_FIXUP_F32_e64 0, killed %18, 0, [[COPY]], 0, [[COPY1]], 0, 0, implicit $mode, implicit $exec
  ; GCN-NEXT:   $vgpr0 = COPY %19
  ; GCN-NEXT:   SI_RETURN implicit $vgpr0
entry:
  %fdiv = fdiv float %a, %b
  ret float %fdiv
}

define float @fdiv_nnan_f32(float %a, float %b) #0 {
  ; GCN-LABEL: name: fdiv_nnan_f32
  ; GCN: bb.0.entry:
  ; GCN-NEXT:   liveins: $vgpr0, $vgpr1
  ; GCN-NEXT: {{  $}}
  ; GCN-NEXT:   [[COPY:%[0-9]+]]:vgpr_32 = COPY $vgpr1
  ; GCN-NEXT:   [[COPY1:%[0-9]+]]:vgpr_32 = COPY $vgpr0
  ; GCN-NEXT:   %4:vgpr_32, %5:sreg_64 = nnan nofpexcept V_DIV_SCALE_F32_e64 0, [[COPY1]], 0, [[COPY]], 0, [[COPY1]], 0, 0, implicit $mode, implicit $exec
  ; GCN-NEXT:   %6:vgpr_32, %7:sreg_64 = nnan nofpexcept V_DIV_SCALE_F32_e64 0, [[COPY]], 0, [[COPY]], 0, [[COPY1]], 0, 0, implicit $mode, implicit $exec
  ; GCN-NEXT:   %8:vgpr_32 = nnan nofpexcept V_RCP_F32_e64 0, %6, 0, 0, implicit $mode, implicit $exec
  ; GCN-NEXT:   [[S_MOV_B32_:%[0-9]+]]:sreg_32 = S_MOV_B32 3
  ; GCN-NEXT:   [[S_MOV_B32_1:%[0-9]+]]:sgpr_32 = S_MOV_B32 1065353216
  ; GCN-NEXT:   [[S_MOV_B32_2:%[0-9]+]]:sreg_32 = S_MOV_B32 0
  ; GCN-NEXT:   S_SETREG_B32_mode killed [[S_MOV_B32_]], 2305, implicit-def $mode, implicit $mode
  ; GCN-NEXT:   %12:vgpr_32 = nnan nofpexcept V_FMA_F32_e64 1, %6, 0, %8, 0, killed [[S_MOV_B32_1]], 0, 0, implicit $mode, implicit $exec
  ; GCN-NEXT:   %13:vgpr_32 = nnan nofpexcept V_FMA_F32_e64 0, killed %12, 0, %8, 0, %8, 0, 0, implicit $mode, implicit $exec
  ; GCN-NEXT:   %14:vgpr_32 = nnan nofpexcept V_MUL_F32_e64 0, %4, 0, %13, 0, 0, implicit $mode, implicit $exec
  ; GCN-NEXT:   %15:vgpr_32 = nnan nofpexcept V_FMA_F32_e64 1, %6, 0, %14, 0, %4, 0, 0, implicit $mode, implicit $exec
  ; GCN-NEXT:   %16:vgpr_32 = nnan nofpexcept V_FMA_F32_e64 0, killed %15, 0, %13, 0, %14, 0, 0, implicit $mode, implicit $exec
  ; GCN-NEXT:   %17:vgpr_32 = nnan nofpexcept V_FMA_F32_e64 1, %6, 0, %16, 0, %4, 0, 0, implicit $mode, implicit $exec
  ; GCN-NEXT:   S_SETREG_B32_mode killed [[S_MOV_B32_2]], 2305, implicit-def dead $mode, implicit $mode
  ; GCN-NEXT:   $vcc = COPY %5
  ; GCN-NEXT:   %18:vgpr_32 = nnan nofpexcept V_DIV_FMAS_F32_e64 0, killed %17, 0, %13, 0, %16, 0, 0, implicit $mode, implicit $vcc, implicit $exec
  ; GCN-NEXT:   %19:vgpr_32 = nnan nofpexcept V_DIV_FIXUP_F32_e64 0, killed %18, 0, [[COPY]], 0, [[COPY1]], 0, 0, implicit $mode, implicit $exec
  ; GCN-NEXT:   $vgpr0 = COPY %19
  ; GCN-NEXT:   SI_RETURN implicit $vgpr0
entry:
  %fdiv = fdiv nnan float %a, %b
  ret float %fdiv
}

attributes #0 = { nounwind "denormal-fp-math-f32"="preserve-sign,preserve-sign" }
