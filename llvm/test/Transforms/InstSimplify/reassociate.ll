; NOTE: Assertions have been autogenerated by utils/update_test_checks.py
; RUN: opt < %s -passes=instsimplify -S | FileCheck %s

define i32 @add1(i32 %x) {
; CHECK-LABEL: @add1(
; CHECK-NEXT:    ret i32 [[X:%.*]]
;
; (X + -1) + 1 -> X
  %l = add i32 %x, -1
  %r = add i32 %l, 1
  ret i32 %r
}

define i32 @and1(i32 %x, i32 %y) {
; CHECK-LABEL: @and1(
; CHECK-NEXT:    [[L:%.*]] = and i32 [[X:%.*]], [[Y:%.*]]
; CHECK-NEXT:    ret i32 [[L]]
;
; (X & Y) & X -> X & Y
  %l = and i32 %x, %y
  %r = and i32 %l, %x
  ret i32 %r
}

define i32 @and2(i32 %x, i32 %y) {
; CHECK-LABEL: @and2(
; CHECK-NEXT:    [[R:%.*]] = and i32 [[X:%.*]], [[Y:%.*]]
; CHECK-NEXT:    ret i32 [[R]]
;
; X & (X & Y) -> X & Y
  %r = and i32 %x, %y
  %l = and i32 %x, %r
  ret i32 %l
}

define i32 @or1(i32 %x, i32 %y) {
; CHECK-LABEL: @or1(
; CHECK-NEXT:    [[L:%.*]] = or i32 [[X:%.*]], [[Y:%.*]]
; CHECK-NEXT:    ret i32 [[L]]
;
; (X | Y) | X -> X | Y
  %l = or i32 %x, %y
  %r = or i32 %l, %x
  ret i32 %r
}

define i32 @or2(i32 %x, i32 %y) {
; CHECK-LABEL: @or2(
; CHECK-NEXT:    [[R:%.*]] = or i32 [[X:%.*]], [[Y:%.*]]
; CHECK-NEXT:    ret i32 [[R]]
;
; X | (X | Y) -> X | Y
  %r = or i32 %x, %y
  %l = or i32 %x, %r
  ret i32 %l
}

define i32 @xor1(i32 %x, i32 %y) {
; CHECK-LABEL: @xor1(
; CHECK-NEXT:    ret i32 [[Y:%.*]]
;
; (X ^ Y) ^ X = Y
  %l = xor i32 %x, %y
  %r = xor i32 %l, %x
  ret i32 %r
}

define i32 @xor2(i32 %x, i32 %y) {
; CHECK-LABEL: @xor2(
; CHECK-NEXT:    ret i32 [[Y:%.*]]
;
; X ^ (X ^ Y) = Y
  %r = xor i32 %x, %y
  %l = xor i32 %x, %r
  ret i32 %l
}

define i32 @sub1(i32 %x, i32 %y) {
; CHECK-LABEL: @sub1(
; CHECK-NEXT:    ret i32 [[Y:%.*]]
;
  %d = sub i32 %x, %y
  %r = sub i32 %x, %d
  ret i32 %r
}

define i32 @sub2(i32 %x) {
; CHECK-LABEL: @sub2(
; CHECK-NEXT:    ret i32 -1
;
; X - (X + 1) -> -1
  %xp1 = add i32 %x, 1
  %r = sub i32 %x, %xp1
  ret i32 %r
}

define i32 @sub3(i32 %x, i32 %y) {
; CHECK-LABEL: @sub3(
; CHECK-NEXT:    ret i32 [[X:%.*]]
;
; ((X + 1) + Y) - (Y + 1) -> X
  %xp1 = add i32 %x, 1
  %lhs = add i32 %xp1, %y
  %rhs = add i32 %y, 1
  %r = sub i32 %lhs, %rhs
  ret i32 %r
}

; (no overflow X * Y) / Y -> X

define i32 @mulnsw_sdiv(i32 %x, i32 %y) {
; CHECK-LABEL: @mulnsw_sdiv(
; CHECK-NEXT:    ret i32 [[X:%.*]]
;
  %mul = mul nsw i32 %x, %y
  %r = sdiv i32 %mul, %y
  ret i32 %r
}

define <2 x i32> @mulnsw_sdiv_commute(<2 x i32> %x, <2 x i32> %y) {
; CHECK-LABEL: @mulnsw_sdiv_commute(
; CHECK-NEXT:    ret <2 x i32> [[X:%.*]]
;
  %mul = mul nsw <2 x i32> %y, %x
  %r = sdiv <2 x i32> %mul, %y
  ret <2 x i32> %r
}

; (no overflow X * Y) / Y -> X

define <2 x i8> @mulnuw_udiv(<2 x i8> %x, <2 x i8> %y) {
; CHECK-LABEL: @mulnuw_udiv(
; CHECK-NEXT:    ret <2 x i8> [[X:%.*]]
;
  %mul = mul nuw <2 x i8> %x, %y
  %r = udiv <2 x i8> %mul, %y
  ret <2 x i8> %r
}

define i32 @mulnuw_udiv_commute(i32 %x, i32 %y) {
; CHECK-LABEL: @mulnuw_udiv_commute(
; CHECK-NEXT:    ret i32 [[X:%.*]]
;
  %mul = mul nuw i32 %y, %x
  %r = udiv i32 %mul, %y
  ret i32 %r
}

; (((X / Y) * Y) / Y) -> X / Y

define i32 @sdiv_mul_sdiv(i32 %x, i32 %y) {
; CHECK-LABEL: @sdiv_mul_sdiv(
; CHECK-NEXT:    [[DIV:%.*]] = sdiv i32 [[X:%.*]], [[Y:%.*]]
; CHECK-NEXT:    ret i32 [[DIV]]
;
  %div = sdiv i32 %x, %y
  %mul = mul i32 %div, %y
  %r = sdiv i32 %mul, %y
  ret i32 %r
}

define i32 @sdiv_mul_sdiv_commute(i32 %x, i32 %y) {
; CHECK-LABEL: @sdiv_mul_sdiv_commute(
; CHECK-NEXT:    [[DIV:%.*]] = sdiv i32 [[X:%.*]], [[Y:%.*]]
; CHECK-NEXT:    ret i32 [[DIV]]
;
  %div = sdiv i32 %x, %y
  %mul = mul i32 %y, %div
  %r = sdiv i32 %mul, %y
  ret i32 %r
}

; (((X / Y) * Y) / Y) -> X / Y

define i32 @udiv_mul_udiv(i32 %x, i32 %y) {
; CHECK-LABEL: @udiv_mul_udiv(
; CHECK-NEXT:    [[DIV:%.*]] = udiv i32 [[X:%.*]], [[Y:%.*]]
; CHECK-NEXT:    ret i32 [[DIV]]
;
  %div = udiv i32 %x, %y
  %mul = mul i32 %div, %y
  %r = udiv i32 %mul, %y
  ret i32 %r
}

define i32 @udiv_mul_udiv_commute(i32 %x, i32 %y) {
; CHECK-LABEL: @udiv_mul_udiv_commute(
; CHECK-NEXT:    [[DIV:%.*]] = udiv i32 [[X:%.*]], [[Y:%.*]]
; CHECK-NEXT:    ret i32 [[DIV]]
;
  %div = udiv i32 %x, %y
  %mul = mul i32 %y, %div
  %r = udiv i32 %mul, %y
  ret i32 %r
}

define i32 @sdiv3(i32 %x, i32 %y) {
; CHECK-LABEL: @sdiv3(
; CHECK-NEXT:    ret i32 0
;
; (X rem Y) / Y -> 0
  %rem = srem i32 %x, %y
  %div = sdiv i32 %rem, %y
  ret i32 %div
}

define i32 @sdiv4(i32 %x, i32 %y) {
; CHECK-LABEL: @sdiv4(
; CHECK-NEXT:    ret i32 [[X:%.*]]
;
; (X / Y) * Y -> X if the division is exact
  %div = sdiv exact i32 %x, %y
  %mul = mul i32 %div, %y
  ret i32 %mul
}

define i32 @sdiv5(i32 %x, i32 %y) {
; CHECK-LABEL: @sdiv5(
; CHECK-NEXT:    ret i32 [[X:%.*]]
;
; Y * (X / Y) -> X if the division is exact
  %div = sdiv exact i32 %x, %y
  %mul = mul i32 %y, %div
  ret i32 %mul
}

define i32 @udiv3(i32 %x, i32 %y) {
; CHECK-LABEL: @udiv3(
; CHECK-NEXT:    ret i32 0
;
; (X rem Y) / Y -> 0
  %rem = urem i32 %x, %y
  %div = udiv i32 %rem, %y
  ret i32 %div
}

define i32 @udiv4(i32 %x, i32 %y) {
; CHECK-LABEL: @udiv4(
; CHECK-NEXT:    ret i32 [[X:%.*]]
;
; (X / Y) * Y -> X if the division is exact
  %div = udiv exact i32 %x, %y
  %mul = mul i32 %div, %y
  ret i32 %mul
}

define i32 @udiv5(i32 %x, i32 %y) {
; CHECK-LABEL: @udiv5(
; CHECK-NEXT:    ret i32 [[X:%.*]]
;
; Y * (X / Y) -> X if the division is exact
  %div = udiv exact i32 %x, %y
  %mul = mul i32 %y, %div
  ret i32 %mul
}

define i16 @trunc1(i32 %x) {
; CHECK-LABEL: @trunc1(
; CHECK-NEXT:    ret i16 1
;
  %y = add i32 %x, 1
  %tx = trunc i32 %x to i16
  %ty = trunc i32 %y to i16
  %d = sub i16 %ty, %tx
  ret i16 %d
}
