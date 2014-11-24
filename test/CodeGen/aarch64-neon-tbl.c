begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: aarch64-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple arm64-none-linux-gnu -target-feature +neon \
end_comment

begin_comment
comment|// RUN:   -ffp-contract=fast -S -O3 -o - %s | FileCheck %s
end_comment

begin_comment
comment|// Test new aarch64 intrinsics and types
end_comment

begin_include
include|#
directive|include
file|<arm_neon.h>
end_include

begin_function
name|int8x8_t
name|test_vtbl1_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtbl1_s8
return|return
name|vtbl1_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: tbl {{v[0-9]+}}.8b, {{{ ?v[0-9]+.16b ?}}}, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|int8x8_t
name|test_vqtbl1_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqtbl1_s8
return|return
name|vqtbl1_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: tbl {{v[0-9]+}}.8b, {{{ ?v[0-9]+.16b ?}}}, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|int8x8_t
name|test_vtbl2_s8
parameter_list|(
name|int8x8x2_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtbl2_s8
return|return
name|vtbl2_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: tbl {{v[0-9]+}}.8b, {{{ ?v[0-9]+.16b ?}}}, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|int8x8_t
name|test_vqtbl2_s8
parameter_list|(
name|int8x16x2_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqtbl2_s8
return|return
name|vqtbl2_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: tbl {{v[0-9]+}}.8b, {{{ ?v[0-9]+.16b, v[0-9]+.16b ?}}}, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|int8x8_t
name|test_vtbl3_s8
parameter_list|(
name|int8x8x3_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtbl3_s8
return|return
name|vtbl3_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: tbl {{v[0-9]+}}.8b, {{{ ?v[0-9]+.16b, v[0-9]+.16b ?}}}, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|int8x8_t
name|test_vqtbl3_s8
parameter_list|(
name|int8x16x3_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqtbl3_s8
return|return
name|vqtbl3_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: tbl {{v[0-9]+}}.8b, {{{ ?v[0-9]+.16b, v[0-9]+.16b, v[0-9]+.16b ?}}}, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|int8x8_t
name|test_vtbl4_s8
parameter_list|(
name|int8x8x4_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtbl4_s8
return|return
name|vtbl4_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: tbl {{v[0-9]+}}.8b, {{{ ?v[0-9]+.16b, v[0-9]+.16b ?}}}, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|int8x8_t
name|test_vqtbl4_s8
parameter_list|(
name|int8x16x4_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqtbl4_s8
return|return
name|vqtbl4_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: tbl {{v[0-9]+}}.8b, {{{ ?v[0-9]+.16b, v[0-9]+.16b, v[0-9]+.16b, v[0-9]+.16b ?}}}, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|int8x16_t
name|test_vqtbl1q_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqtbl1q_s8
return|return
name|vqtbl1q_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: tbl {{v[0-9]+}}.16b, {{{ ?v[0-9]+.16b ?}}}, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|int8x16_t
name|test_vqtbl2q_s8
parameter_list|(
name|int8x16x2_t
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqtbl2q_s8
return|return
name|vqtbl2q_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: tbl {{v[0-9]+}}.16b, {{{ ?v[0-9]+.16b, v[0-9]+.16b ?}}}, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|int8x16_t
name|test_vqtbl3q_s8
parameter_list|(
name|int8x16x3_t
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqtbl3q_s8
return|return
name|vqtbl3q_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: tbl {{v[0-9]+}}.16b, {{{ ?v[0-9]+.16b, v[0-9]+.16b, v[0-9]+.16b ?}}}, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|int8x16_t
name|test_vqtbl4q_s8
parameter_list|(
name|int8x16x4_t
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqtbl4q_s8
return|return
name|vqtbl4q_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: tbl {{v[0-9]+}}.16b, {{{ ?v[0-9]+.16b, v[0-9]+.16b, v[0-9]+.16b, v[0-9]+.16b ?}}}, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|int8x8_t
name|test_vtbx1_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|,
name|int8x8_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtbx1_s8
return|return
name|vtbx1_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: movi {{v[0-9]+.8b|d[0-9]+}}, #0
comment|// CHECK: ins {{v[0-9]+}}.d[1], {{v[0-9]+}}.d[0]
comment|// CHECK: tbl {{v[0-9]+}}.8b, {{{ ?v[0-9]+.16b ?}}}, {{v[0-9]+}}.8b
comment|// CHECK: cmhs {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
comment|// CHECK: bsl {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|int8x8_t
name|test_vtbx2_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int8x8x2_t
name|b
parameter_list|,
name|int8x8_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtbx2_s8
return|return
name|vtbx2_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: tbx {{v[0-9]+}}.8b, {{{ ?v[0-9]+.16b ?}}}, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|int8x8_t
name|test_vtbx3_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int8x8x3_t
name|b
parameter_list|,
name|int8x8_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtbx3_s8
return|return
name|vtbx3_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: movi {{v[0-9]+.8b|d[0-9]+}}, #0
comment|// CHECK: ins {{v[0-9]+}}.d[1], {{v[0-9]+}}.d[0]
comment|// CHECK: tbl {{v[0-9]+}}.8b, {{{ ?v[0-9]+.16b, v[0-9]+.16b ?}}}, {{v[0-9]+}}.8b
comment|// CHECK: cmhs {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
comment|// CHECK: bsl {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|int8x8_t
name|test_vtbx4_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int8x8x4_t
name|b
parameter_list|,
name|int8x8_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtbx4_s8
return|return
name|vtbx4_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: tbx {{v[0-9]+}}.8b, {{{ ?v[0-9]+.16b, v[0-9]+.16b ?}}}, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|int8x8_t
name|test_vqtbx1_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|,
name|int8x8_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqtbx1_s8
return|return
name|vqtbx1_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: tbx {{v[0-9]+}}.8b, {{{ ?v[0-9]+.16b ?}}}, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|int8x8_t
name|test_vqtbx2_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int8x16x2_t
name|b
parameter_list|,
name|int8x8_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqtbx2_s8
return|return
name|vqtbx2_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: tbx {{v[0-9]+}}.8b, {{{ ?v[0-9]+.16b, v[0-9]+.16b ?}}}, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|int8x8_t
name|test_vqtbx3_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int8x16x3_t
name|b
parameter_list|,
name|int8x8_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqtbx3_s8
return|return
name|vqtbx3_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: tbx {{v[0-9]+}}.8b, {{{ ?v[0-9]+.16b, v[0-9]+.16b, v[0-9]+.16b ?}}}, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|int8x8_t
name|test_vqtbx4_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int8x16x4_t
name|b
parameter_list|,
name|int8x8_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqtbx4_s8
return|return
name|vqtbx4_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: tbx {{v[0-9]+}}.8b, {{{ ?v[0-9]+.16b, v[0-9]+.16b, v[0-9]+.16b, v[0-9]+.16b ?}}}, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|int8x16_t
name|test_vqtbx1q_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|,
name|int8x16_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqtbx1q_s8
return|return
name|vqtbx1q_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: tbx {{v[0-9]+}}.16b, {{{ ?v[0-9]+.16b ?}}}, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|int8x16_t
name|test_vqtbx2q_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|,
name|int8x16x2_t
name|b
parameter_list|,
name|int8x16_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqtbx2q_s8
return|return
name|vqtbx2q_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: tbx {{v[0-9]+}}.16b, {{{ ?v[0-9]+.16b, v[0-9]+.16b ?}}}, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|int8x16_t
name|test_vqtbx3q_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|,
name|int8x16x3_t
name|b
parameter_list|,
name|int8x16_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqtbx3q_s8
return|return
name|vqtbx3q_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: tbx {{v[0-9]+}}.16b, {{{ ?v[0-9]+.16b, v[0-9]+.16b, v[0-9]+.16b ?}}}, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|int8x16_t
name|test_vqtbx4q_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|,
name|int8x16x4_t
name|b
parameter_list|,
name|int8x16_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqtbx4q_s8
return|return
name|vqtbx4q_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: tbx {{v[0-9]+}}.16b, {{{ ?v[0-9]+.16b, v[0-9]+.16b, v[0-9]+.16b, v[0-9]+.16b ?}}}, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|uint8x8_t
name|test_vtbl1_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtbl1_u8
return|return
name|vtbl1_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: tbl {{v[0-9]+}}.8b, {{{ ?v[0-9]+.16b ?}}}, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|uint8x8_t
name|test_vqtbl1_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqtbl1_u8
return|return
name|vqtbl1_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: tbl {{v[0-9]+}}.8b, {{{ ?v[0-9]+.16b ?}}}, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|uint8x8_t
name|test_vtbl2_u8
parameter_list|(
name|uint8x8x2_t
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtbl2_u8
return|return
name|vtbl2_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: tbl {{v[0-9]+}}.8b, {{{ ?v[0-9]+.16b ?}}}, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|uint8x8_t
name|test_vqtbl2_u8
parameter_list|(
name|uint8x16x2_t
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqtbl2_u8
return|return
name|vqtbl2_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: tbl {{v[0-9]+}}.8b, {{{ ?v[0-9]+.16b, v[0-9]+.16b ?}}}, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|uint8x8_t
name|test_vtbl3_u8
parameter_list|(
name|uint8x8x3_t
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtbl3_u8
return|return
name|vtbl3_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: tbl {{v[0-9]+}}.8b, {{{ ?v[0-9]+.16b, v[0-9]+.16b ?}}}, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|uint8x8_t
name|test_vqtbl3_u8
parameter_list|(
name|uint8x16x3_t
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqtbl3_u8
return|return
name|vqtbl3_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: tbl {{v[0-9]+}}.8b, {{{ ?v[0-9]+.16b, v[0-9]+.16b, v[0-9]+.16b ?}}}, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|uint8x8_t
name|test_vtbl4_u8
parameter_list|(
name|uint8x8x4_t
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtbl4_u8
return|return
name|vtbl4_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: tbl {{v[0-9]+}}.8b, {{{ ?v[0-9]+.16b, v[0-9]+.16b ?}}}, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|uint8x8_t
name|test_vqtbl4_u8
parameter_list|(
name|uint8x16x4_t
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqtbl4_u8
return|return
name|vqtbl4_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: tbl {{v[0-9]+}}.8b, {{{ ?v[0-9]+.16b, v[0-9]+.16b, v[0-9]+.16b, v[0-9]+.16b ?}}}, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|uint8x16_t
name|test_vqtbl1q_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|,
name|uint8x16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqtbl1q_u8
return|return
name|vqtbl1q_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: tbl {{v[0-9]+}}.16b, {{{ ?v[0-9]+.16b ?}}}, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|uint8x16_t
name|test_vqtbl2q_u8
parameter_list|(
name|uint8x16x2_t
name|a
parameter_list|,
name|uint8x16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqtbl2q_u8
return|return
name|vqtbl2q_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: tbl {{v[0-9]+}}.16b, {{{ ?v[0-9]+.16b, v[0-9]+.16b ?}}}, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|uint8x16_t
name|test_vqtbl3q_u8
parameter_list|(
name|uint8x16x3_t
name|a
parameter_list|,
name|uint8x16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqtbl3q_u8
return|return
name|vqtbl3q_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: tbl {{v[0-9]+}}.16b, {{{ ?v[0-9]+.16b, v[0-9]+.16b, v[0-9]+.16b ?}}}, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|uint8x16_t
name|test_vqtbl4q_u8
parameter_list|(
name|uint8x16x4_t
name|a
parameter_list|,
name|uint8x16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqtbl4q_u8
return|return
name|vqtbl4q_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: tbl {{v[0-9]+}}.16b, {{{ ?v[0-9]+.16b, v[0-9]+.16b, v[0-9]+.16b, v[0-9]+.16b ?}}}, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|uint8x8_t
name|test_vtbx1_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|,
name|uint8x8_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtbx1_u8
return|return
name|vtbx1_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: movi {{v[0-9]+.8b|d[0-9]+}}, #0
comment|// CHECK: ins {{v[0-9]+}}.d[1], {{v[0-9]+}}.d[0]
comment|// CHECK: tbl {{v[0-9]+}}.8b, {{{ ?v[0-9]+.16b ?}}}, {{v[0-9]+}}.8b
comment|// CHECK: cmhs {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
comment|// CHECK: bsl {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|uint8x8_t
name|test_vtbx2_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|,
name|uint8x8x2_t
name|b
parameter_list|,
name|uint8x8_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtbx2_u8
return|return
name|vtbx2_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: tbx {{v[0-9]+}}.8b, {{{ ?v[0-9]+.16b ?}}}, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|uint8x8_t
name|test_vtbx3_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|,
name|uint8x8x3_t
name|b
parameter_list|,
name|uint8x8_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtbx3_u8
return|return
name|vtbx3_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: movi {{v[0-9]+.8b|d[0-9]+}}, #0
comment|// CHECK: ins {{v[0-9]+}}.d[1], {{v[0-9]+}}.d[0]
comment|// CHECK: tbl {{v[0-9]+}}.8b, {{{ ?v[0-9]+.16b, v[0-9]+.16b ?}}}, {{v[0-9]+}}.8b
comment|// CHECK: cmhs {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
comment|// CHECK: bsl {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|uint8x8_t
name|test_vtbx4_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|,
name|uint8x8x4_t
name|b
parameter_list|,
name|uint8x8_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtbx4_u8
return|return
name|vtbx4_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: tbx {{v[0-9]+}}.8b, {{{ ?v[0-9]+.16b, v[0-9]+.16b ?}}}, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|uint8x8_t
name|test_vqtbx1_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|,
name|uint8x16_t
name|b
parameter_list|,
name|uint8x8_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqtbx1_u8
return|return
name|vqtbx1_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: tbx {{v[0-9]+}}.8b, {{{ ?v[0-9]+.16b ?}}}, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|uint8x8_t
name|test_vqtbx2_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|,
name|uint8x16x2_t
name|b
parameter_list|,
name|uint8x8_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqtbx2_u8
return|return
name|vqtbx2_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: tbx {{v[0-9]+}}.8b, {{{ ?v[0-9]+.16b, v[0-9]+.16b ?}}}, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|uint8x8_t
name|test_vqtbx3_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|,
name|uint8x16x3_t
name|b
parameter_list|,
name|uint8x8_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqtbx3_u8
return|return
name|vqtbx3_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: tbx {{v[0-9]+}}.8b, {{{ ?v[0-9]+.16b, v[0-9]+.16b, v[0-9]+.16b ?}}}, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|uint8x8_t
name|test_vqtbx4_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|,
name|uint8x16x4_t
name|b
parameter_list|,
name|uint8x8_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqtbx4_u8
return|return
name|vqtbx4_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: tbx {{v[0-9]+}}.8b, {{{ ?v[0-9]+.16b, v[0-9]+.16b, v[0-9]+.16b, v[0-9]+.16b ?}}}, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|uint8x16_t
name|test_vqtbx1q_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|,
name|uint8x16_t
name|b
parameter_list|,
name|uint8x16_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqtbx1q_u8
return|return
name|vqtbx1q_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: tbx {{v[0-9]+}}.16b, {{{ ?v[0-9]+.16b ?}}}, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|uint8x16_t
name|test_vqtbx2q_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|,
name|uint8x16x2_t
name|b
parameter_list|,
name|uint8x16_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqtbx2q_u8
return|return
name|vqtbx2q_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: tbx {{v[0-9]+}}.16b, {{{ ?v[0-9]+.16b, v[0-9]+.16b ?}}}, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|uint8x16_t
name|test_vqtbx3q_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|,
name|uint8x16x3_t
name|b
parameter_list|,
name|uint8x16_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqtbx3q_u8
return|return
name|vqtbx3q_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: tbx {{v[0-9]+}}.16b, {{{ ?v[0-9]+.16b, v[0-9]+.16b, v[0-9]+.16b ?}}}, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|uint8x16_t
name|test_vqtbx4q_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|,
name|uint8x16x4_t
name|b
parameter_list|,
name|uint8x16_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqtbx4q_u8
return|return
name|vqtbx4q_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: tbx {{v[0-9]+}}.16b, {{{ ?v[0-9]+.16b, v[0-9]+.16b, v[0-9]+.16b, v[0-9]+.16b ?}}}, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|poly8x8_t
name|test_vtbl1_p8
parameter_list|(
name|poly8x8_t
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtbl1_p8
return|return
name|vtbl1_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: tbl {{v[0-9]+}}.8b, {{{ ?v[0-9]+.16b ?}}}, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|poly8x8_t
name|test_vqtbl1_p8
parameter_list|(
name|poly8x16_t
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqtbl1_p8
return|return
name|vqtbl1_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: tbl {{v[0-9]+}}.8b, {{{ ?v[0-9]+.16b ?}}}, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|poly8x8_t
name|test_vtbl2_p8
parameter_list|(
name|poly8x8x2_t
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtbl2_p8
return|return
name|vtbl2_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: tbl {{v[0-9]+}}.8b, {{{ ?v[0-9]+.16b ?}}}, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|poly8x8_t
name|test_vqtbl2_p8
parameter_list|(
name|poly8x16x2_t
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqtbl2_p8
return|return
name|vqtbl2_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: tbl {{v[0-9]+}}.8b, {{{ ?v[0-9]+.16b, v[0-9]+.16b ?}}}, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|poly8x8_t
name|test_vtbl3_p8
parameter_list|(
name|poly8x8x3_t
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtbl3_p8
return|return
name|vtbl3_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: tbl {{v[0-9]+}}.8b, {{{ ?v[0-9]+.16b, v[0-9]+.16b ?}}}, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|poly8x8_t
name|test_vqtbl3_p8
parameter_list|(
name|poly8x16x3_t
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqtbl3_p8
return|return
name|vqtbl3_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: tbl {{v[0-9]+}}.8b, {{{ ?v[0-9]+.16b, v[0-9]+.16b, v[0-9]+.16b ?}}}, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|poly8x8_t
name|test_vtbl4_p8
parameter_list|(
name|poly8x8x4_t
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtbl4_p8
return|return
name|vtbl4_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: tbl {{v[0-9]+}}.8b, {{{ ?v[0-9]+.16b, v[0-9]+.16b ?}}}, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|poly8x8_t
name|test_vqtbl4_p8
parameter_list|(
name|poly8x16x4_t
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqtbl4_p8
return|return
name|vqtbl4_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: tbl {{v[0-9]+}}.8b, {{{ ?v[0-9]+.16b, v[0-9]+.16b, v[0-9]+.16b, v[0-9]+.16b ?}}}, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|poly8x16_t
name|test_vqtbl1q_p8
parameter_list|(
name|poly8x16_t
name|a
parameter_list|,
name|uint8x16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqtbl1q_p8
return|return
name|vqtbl1q_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: tbl {{v[0-9]+}}.16b, {{{ ?v[0-9]+.16b ?}}}, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|poly8x16_t
name|test_vqtbl2q_p8
parameter_list|(
name|poly8x16x2_t
name|a
parameter_list|,
name|uint8x16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqtbl2q_p8
return|return
name|vqtbl2q_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: tbl {{v[0-9]+}}.16b, {{{ ?v[0-9]+.16b, v[0-9]+.16b ?}}}, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|poly8x16_t
name|test_vqtbl3q_p8
parameter_list|(
name|poly8x16x3_t
name|a
parameter_list|,
name|uint8x16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqtbl3q_p8
return|return
name|vqtbl3q_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: tbl {{v[0-9]+}}.16b, {{{ ?v[0-9]+.16b, v[0-9]+.16b, v[0-9]+.16b ?}}}, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|poly8x16_t
name|test_vqtbl4q_p8
parameter_list|(
name|poly8x16x4_t
name|a
parameter_list|,
name|uint8x16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqtbl4q_p8
return|return
name|vqtbl4q_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: tbl {{v[0-9]+}}.16b, {{{ ?v[0-9]+.16b, v[0-9]+.16b, v[0-9]+.16b, v[0-9]+.16b ?}}}, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|poly8x8_t
name|test_vtbx1_p8
parameter_list|(
name|poly8x8_t
name|a
parameter_list|,
name|poly8x8_t
name|b
parameter_list|,
name|uint8x8_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtbx1_p8
return|return
name|vtbx1_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: movi {{v[0-9]+.8b|d[0-9]+}}, #0
comment|// CHECK: ins {{v[0-9]+}}.d[1], {{v[0-9]+}}.d[0]
comment|// CHECK: tbl {{v[0-9]+}}.8b, {{{ ?v[0-9]+.16b ?}}}, {{v[0-9]+}}.8b
comment|// CHECK: cmhs {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
comment|// CHECK: bsl {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|poly8x8_t
name|test_vtbx2_p8
parameter_list|(
name|poly8x8_t
name|a
parameter_list|,
name|poly8x8x2_t
name|b
parameter_list|,
name|uint8x8_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtbx2_p8
return|return
name|vtbx2_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: tbx {{v[0-9]+}}.8b, {{{ ?v[0-9]+.16b ?}}}, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|poly8x8_t
name|test_vtbx3_p8
parameter_list|(
name|poly8x8_t
name|a
parameter_list|,
name|poly8x8x3_t
name|b
parameter_list|,
name|uint8x8_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtbx3_p8
return|return
name|vtbx3_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: movi {{v[0-9]+.8b|d[0-9]+}}, #0
comment|// CHECK: ins {{v[0-9]+}}.d[1], {{v[0-9]+}}.d[0]
comment|// CHECK: tbl {{v[0-9]+}}.8b, {{{ ?v[0-9]+.16b, v[0-9]+.16b ?}}}, {{v[0-9]+}}.8b
comment|// CHECK: cmhs {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
comment|// CHECK: bsl {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|poly8x8_t
name|test_vtbx4_p8
parameter_list|(
name|poly8x8_t
name|a
parameter_list|,
name|poly8x8x4_t
name|b
parameter_list|,
name|uint8x8_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtbx4_p8
return|return
name|vtbx4_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: tbx {{v[0-9]+}}.8b, {{{ ?v[0-9]+.16b, v[0-9]+.16b ?}}}, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|poly8x8_t
name|test_vqtbx1_p8
parameter_list|(
name|poly8x8_t
name|a
parameter_list|,
name|uint8x16_t
name|b
parameter_list|,
name|uint8x8_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqtbx1_p8
return|return
name|vqtbx1_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: tbx {{v[0-9]+}}.8b, {{{ ?v[0-9]+.16b ?}}}, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|poly8x8_t
name|test_vqtbx2_p8
parameter_list|(
name|poly8x8_t
name|a
parameter_list|,
name|poly8x16x2_t
name|b
parameter_list|,
name|uint8x8_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqtbx2_p8
return|return
name|vqtbx2_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: tbx {{v[0-9]+}}.8b, {{{ ?v[0-9]+.16b, v[0-9]+.16b ?}}}, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|poly8x8_t
name|test_vqtbx3_p8
parameter_list|(
name|poly8x8_t
name|a
parameter_list|,
name|poly8x16x3_t
name|b
parameter_list|,
name|uint8x8_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqtbx3_p8
return|return
name|vqtbx3_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: tbx {{v[0-9]+}}.8b, {{{ ?v[0-9]+.16b, v[0-9]+.16b, v[0-9]+.16b ?}}}, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|poly8x8_t
name|test_vqtbx4_p8
parameter_list|(
name|poly8x8_t
name|a
parameter_list|,
name|poly8x16x4_t
name|b
parameter_list|,
name|uint8x8_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqtbx4_p8
return|return
name|vqtbx4_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: tbx {{v[0-9]+}}.8b, {{{ ?v[0-9]+.16b, v[0-9]+.16b, v[0-9]+.16b, v[0-9]+.16b ?}}}, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|poly8x16_t
name|test_vqtbx1q_p8
parameter_list|(
name|poly8x16_t
name|a
parameter_list|,
name|uint8x16_t
name|b
parameter_list|,
name|uint8x16_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqtbx1q_p8
return|return
name|vqtbx1q_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: tbx {{v[0-9]+}}.16b, {{{ ?v[0-9]+.16b ?}}}, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|poly8x16_t
name|test_vqtbx2q_p8
parameter_list|(
name|poly8x16_t
name|a
parameter_list|,
name|poly8x16x2_t
name|b
parameter_list|,
name|uint8x16_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqtbx2q_p8
return|return
name|vqtbx2q_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: tbx {{v[0-9]+}}.16b, {{{ ?v[0-9]+.16b, v[0-9]+.16b ?}}}, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|poly8x16_t
name|test_vqtbx3q_p8
parameter_list|(
name|poly8x16_t
name|a
parameter_list|,
name|poly8x16x3_t
name|b
parameter_list|,
name|uint8x16_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqtbx3q_p8
return|return
name|vqtbx3q_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: tbx {{v[0-9]+}}.16b, {{{ ?v[0-9]+.16b, v[0-9]+.16b, v[0-9]+.16b ?}}}, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|poly8x16_t
name|test_vqtbx4q_p8
parameter_list|(
name|poly8x16_t
name|a
parameter_list|,
name|poly8x16x4_t
name|b
parameter_list|,
name|uint8x16_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqtbx4q_p8
return|return
name|vqtbx4q_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: tbx {{v[0-9]+}}.16b, {{{ ?v[0-9]+.16b, v[0-9]+.16b, v[0-9]+.16b, v[0-9]+.16b ?}}}, {{v[0-9]+}}.16b
block|}
end_function

end_unit

