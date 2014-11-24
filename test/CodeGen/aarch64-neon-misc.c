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

begin_comment
comment|// CHECK-LABEL: test_vceqz_s8
end_comment

begin_comment
comment|// CHECK: cmeq  {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, #{{0x0|0}}
end_comment

begin_function
name|uint8x8_t
name|test_vceqz_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
return|return
name|vceqz_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vceqz_s16
end_comment

begin_comment
comment|// CHECK: cmeq  {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, #{{0x0|0}}
end_comment

begin_function
name|uint16x4_t
name|test_vceqz_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|)
block|{
return|return
name|vceqz_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vceqz_s32
end_comment

begin_comment
comment|// CHECK: cmeq  {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, #{{0x0|0}}
end_comment

begin_function
name|uint32x2_t
name|test_vceqz_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|)
block|{
return|return
name|vceqz_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vceqz_s64
end_comment

begin_comment
comment|// CHECK: cmeq {{d[0-9]+}}, {{d[0-9]+}}, #{{0x0|0}}
end_comment

begin_function
name|uint64x1_t
name|test_vceqz_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|)
block|{
return|return
name|vceqz_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vceqz_u64
end_comment

begin_comment
comment|// CHECK: cmeq {{d[0-9]+}}, {{d[0-9]+}}, #{{0x0|0}}
end_comment

begin_function
name|uint64x1_t
name|test_vceqz_u64
parameter_list|(
name|uint64x1_t
name|a
parameter_list|)
block|{
return|return
name|vceqz_u64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vceqz_p64
end_comment

begin_comment
comment|// CHECK: cmeq {{d[0-9]+}}, {{d[0-9]+}}, #{{0x0|0}}
end_comment

begin_function
name|uint64x1_t
name|test_vceqz_p64
parameter_list|(
name|poly64x1_t
name|a
parameter_list|)
block|{
return|return
name|vceqz_p64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vceqzq_s8
end_comment

begin_comment
comment|// CHECK: cmeq  {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, #{{0x0|0}}
end_comment

begin_function
name|uint8x16_t
name|test_vceqzq_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
return|return
name|vceqzq_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vceqzq_s16
end_comment

begin_comment
comment|// CHECK: cmeq  {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, #{{0x0|0}}
end_comment

begin_function
name|uint16x8_t
name|test_vceqzq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
return|return
name|vceqzq_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vceqzq_s32
end_comment

begin_comment
comment|// CHECK: cmeq  {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, #{{0x0|0}}
end_comment

begin_function
name|uint32x4_t
name|test_vceqzq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
return|return
name|vceqzq_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vceqzq_s64
end_comment

begin_comment
comment|// CHECK: cmeq  {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, #{{0x0|0}}
end_comment

begin_function
name|uint64x2_t
name|test_vceqzq_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|)
block|{
return|return
name|vceqzq_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vceqz_u8
end_comment

begin_comment
comment|// CHECK: cmeq  {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, #{{0x0|0}}
end_comment

begin_function
name|uint8x8_t
name|test_vceqz_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|)
block|{
return|return
name|vceqz_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vceqz_u16
end_comment

begin_comment
comment|// CHECK: cmeq  {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, #{{0x0|0}}
end_comment

begin_function
name|uint16x4_t
name|test_vceqz_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|)
block|{
return|return
name|vceqz_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vceqz_u32
end_comment

begin_comment
comment|// CHECK: cmeq  {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, #{{0x0|0}}
end_comment

begin_function
name|uint32x2_t
name|test_vceqz_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|)
block|{
return|return
name|vceqz_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vceqzq_u8
end_comment

begin_comment
comment|// CHECK: cmeq  {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, #{{0x0|0}}
end_comment

begin_function
name|uint8x16_t
name|test_vceqzq_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|)
block|{
return|return
name|vceqzq_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vceqzq_u16
end_comment

begin_comment
comment|// CHECK: cmeq  {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, #{{0x0|0}}
end_comment

begin_function
name|uint16x8_t
name|test_vceqzq_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|)
block|{
return|return
name|vceqzq_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vceqzq_u32
end_comment

begin_comment
comment|// CHECK: cmeq  {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, #{{0x0|0}}
end_comment

begin_function
name|uint32x4_t
name|test_vceqzq_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|)
block|{
return|return
name|vceqzq_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vceqzq_u64
end_comment

begin_comment
comment|// CHECK: cmeq  {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, #{{0x0|0}}
end_comment

begin_function
name|uint64x2_t
name|test_vceqzq_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|)
block|{
return|return
name|vceqzq_u64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vceqz_f32
end_comment

begin_comment
comment|// CHECK: fcmeq  {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, #0
end_comment

begin_function
name|uint32x2_t
name|test_vceqz_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
return|return
name|vceqz_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vceqz_f64
end_comment

begin_comment
comment|// CHECK: fcmeq  {{d[0-9]+}}, {{d[0-9]+}}, #0
end_comment

begin_function
name|uint64x1_t
name|test_vceqz_f64
parameter_list|(
name|float64x1_t
name|a
parameter_list|)
block|{
return|return
name|vceqz_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vceqzq_f32
end_comment

begin_comment
comment|// CHECK: fcmeq  {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, #0
end_comment

begin_function
name|uint32x4_t
name|test_vceqzq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
return|return
name|vceqzq_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vceqz_p8
end_comment

begin_comment
comment|// CHECK: cmeq  {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, #{{0x0|0}}
end_comment

begin_function
name|uint8x8_t
name|test_vceqz_p8
parameter_list|(
name|poly8x8_t
name|a
parameter_list|)
block|{
return|return
name|vceqz_p8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vceqzq_p8
end_comment

begin_comment
comment|// CHECK: cmeq  {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, #{{0x0|0}}
end_comment

begin_function
name|uint8x16_t
name|test_vceqzq_p8
parameter_list|(
name|poly8x16_t
name|a
parameter_list|)
block|{
return|return
name|vceqzq_p8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vceqz_p16
end_comment

begin_comment
comment|// CHECK: cmeq  {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, #{{0x0|0}}
end_comment

begin_function
name|uint16x4_t
name|test_vceqz_p16
parameter_list|(
name|poly16x4_t
name|a
parameter_list|)
block|{
return|return
name|vceqz_p16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vceqzq_p16
end_comment

begin_comment
comment|// CHECK: cmeq  {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, #{{0x0|0}}
end_comment

begin_function
name|uint16x8_t
name|test_vceqzq_p16
parameter_list|(
name|poly16x8_t
name|a
parameter_list|)
block|{
return|return
name|vceqzq_p16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vceqzq_f64
end_comment

begin_comment
comment|// CHECK: fcmeq  {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, #0
end_comment

begin_function
name|uint64x2_t
name|test_vceqzq_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|)
block|{
return|return
name|vceqzq_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vceqzq_p64
end_comment

begin_comment
comment|// CHECK: cmeq  {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, #0
end_comment

begin_function
name|uint64x2_t
name|test_vceqzq_p64
parameter_list|(
name|poly64x2_t
name|a
parameter_list|)
block|{
return|return
name|vceqzq_p64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcgez_s8
end_comment

begin_comment
comment|// CHECK: cmge  {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, #{{0x0|0}}
end_comment

begin_function
name|uint8x8_t
name|test_vcgez_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
return|return
name|vcgez_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcgez_s16
end_comment

begin_comment
comment|// CHECK: cmge  {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, #{{0x0|0}}
end_comment

begin_function
name|uint16x4_t
name|test_vcgez_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|)
block|{
return|return
name|vcgez_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcgez_s32
end_comment

begin_comment
comment|// CHECK: cmge  {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, #{{0x0|0}}
end_comment

begin_function
name|uint32x2_t
name|test_vcgez_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|)
block|{
return|return
name|vcgez_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcgez_s64
end_comment

begin_comment
comment|// CHECK: cmge {{d[0-9]+}}, {{d[0-9]+}}, #{{0x0|0}}
end_comment

begin_function
name|uint64x1_t
name|test_vcgez_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|)
block|{
return|return
name|vcgez_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcgezq_s8
end_comment

begin_comment
comment|// CHECK: cmge  {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, #{{0x0|0}}
end_comment

begin_function
name|uint8x16_t
name|test_vcgezq_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
return|return
name|vcgezq_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcgezq_s16
end_comment

begin_comment
comment|// CHECK: cmge  {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, #{{0x0|0}}
end_comment

begin_function
name|uint16x8_t
name|test_vcgezq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
return|return
name|vcgezq_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcgezq_s32
end_comment

begin_comment
comment|// CHECK: cmge  {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, #{{0x0|0}}
end_comment

begin_function
name|uint32x4_t
name|test_vcgezq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
return|return
name|vcgezq_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcgezq_s64
end_comment

begin_comment
comment|// CHECK: cmge  {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, #{{0x0|0}}
end_comment

begin_function
name|uint64x2_t
name|test_vcgezq_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|)
block|{
return|return
name|vcgezq_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcgez_f32
end_comment

begin_comment
comment|// CHECK: fcmge  {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, #0
end_comment

begin_function
name|uint32x2_t
name|test_vcgez_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
return|return
name|vcgez_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcgez_f64
end_comment

begin_comment
comment|// CHECK: fcmge  {{d[0-9]+}}, {{d[0-9]+}}, #0
end_comment

begin_function
name|uint64x1_t
name|test_vcgez_f64
parameter_list|(
name|float64x1_t
name|a
parameter_list|)
block|{
return|return
name|vcgez_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcgezq_f32
end_comment

begin_comment
comment|// CHECK: fcmge  {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, #0
end_comment

begin_function
name|uint32x4_t
name|test_vcgezq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
return|return
name|vcgezq_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcgezq_f64
end_comment

begin_comment
comment|// CHECK: fcmge  {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, #0
end_comment

begin_function
name|uint64x2_t
name|test_vcgezq_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|)
block|{
return|return
name|vcgezq_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vclez_s8
end_comment

begin_comment
comment|// CHECK: cmle  {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, #{{0x0|0}}
end_comment

begin_function
name|uint8x8_t
name|test_vclez_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
return|return
name|vclez_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vclez_s16
end_comment

begin_comment
comment|// CHECK: cmle  {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, #{{0x0|0}}
end_comment

begin_function
name|uint16x4_t
name|test_vclez_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|)
block|{
return|return
name|vclez_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vclez_s32
end_comment

begin_comment
comment|// CHECK: cmle  {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, #{{0x0|0}}
end_comment

begin_function
name|uint32x2_t
name|test_vclez_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|)
block|{
return|return
name|vclez_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vclez_s64
end_comment

begin_comment
comment|// CHECK: cmle {{d[0-9]+}}, {{d[0-9]+}}, #{{0x0|0}}
end_comment

begin_function
name|uint64x1_t
name|test_vclez_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|)
block|{
return|return
name|vclez_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vclezq_s8
end_comment

begin_comment
comment|// CHECK: cmle  {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, #{{0x0|0}}
end_comment

begin_function
name|uint8x16_t
name|test_vclezq_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
return|return
name|vclezq_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vclezq_s16
end_comment

begin_comment
comment|// CHECK: cmle  {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, #{{0x0|0}}
end_comment

begin_function
name|uint16x8_t
name|test_vclezq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
return|return
name|vclezq_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vclezq_s32
end_comment

begin_comment
comment|// CHECK: cmle  {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, #{{0x0|0}}
end_comment

begin_function
name|uint32x4_t
name|test_vclezq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
return|return
name|vclezq_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vclezq_s64
end_comment

begin_comment
comment|// CHECK: cmle  {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, #{{0x0|0}}
end_comment

begin_function
name|uint64x2_t
name|test_vclezq_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|)
block|{
return|return
name|vclezq_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vclez_f32
end_comment

begin_comment
comment|// CHECK: fcmle  {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, #0
end_comment

begin_function
name|uint32x2_t
name|test_vclez_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
return|return
name|vclez_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vclez_f64
end_comment

begin_comment
comment|// CHECK: fcmle  {{d[0-9]+}}, {{d[0-9]+}}, #0
end_comment

begin_function
name|uint64x1_t
name|test_vclez_f64
parameter_list|(
name|float64x1_t
name|a
parameter_list|)
block|{
return|return
name|vclez_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vclezq_f32
end_comment

begin_comment
comment|// CHECK: fcmle  {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, #0
end_comment

begin_function
name|uint32x4_t
name|test_vclezq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
return|return
name|vclezq_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vclezq_f64
end_comment

begin_comment
comment|// CHECK: fcmle  {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, #0
end_comment

begin_function
name|uint64x2_t
name|test_vclezq_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|)
block|{
return|return
name|vclezq_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcgtz_s8
end_comment

begin_comment
comment|// CHECK: cmgt  {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, #{{0x0|0}}
end_comment

begin_function
name|uint8x8_t
name|test_vcgtz_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
return|return
name|vcgtz_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcgtz_s16
end_comment

begin_comment
comment|// CHECK: cmgt  {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, #{{0x0|0}}
end_comment

begin_function
name|uint16x4_t
name|test_vcgtz_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|)
block|{
return|return
name|vcgtz_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcgtz_s32
end_comment

begin_comment
comment|// CHECK: cmgt  {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, #{{0x0|0}}
end_comment

begin_function
name|uint32x2_t
name|test_vcgtz_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|)
block|{
return|return
name|vcgtz_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcgtz_s64
end_comment

begin_comment
comment|// CHECK: cmgt {{d[0-9]+}}, {{d[0-9]+}}, #{{0x0|0}}
end_comment

begin_function
name|uint64x1_t
name|test_vcgtz_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|)
block|{
return|return
name|vcgtz_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcgtzq_s8
end_comment

begin_comment
comment|// CHECK: cmgt  {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, #{{0x0|0}}
end_comment

begin_function
name|uint8x16_t
name|test_vcgtzq_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
return|return
name|vcgtzq_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcgtzq_s16
end_comment

begin_comment
comment|// CHECK: cmgt  {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, #{{0x0|0}}
end_comment

begin_function
name|uint16x8_t
name|test_vcgtzq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
return|return
name|vcgtzq_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcgtzq_s32
end_comment

begin_comment
comment|// CHECK: cmgt  {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, #{{0x0|0}}
end_comment

begin_function
name|uint32x4_t
name|test_vcgtzq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
return|return
name|vcgtzq_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcgtzq_s64
end_comment

begin_comment
comment|// CHECK: cmgt  {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, #{{0x0|0}}
end_comment

begin_function
name|uint64x2_t
name|test_vcgtzq_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|)
block|{
return|return
name|vcgtzq_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcgtz_f32
end_comment

begin_comment
comment|// CHECK: fcmgt  {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, #0
end_comment

begin_function
name|uint32x2_t
name|test_vcgtz_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
return|return
name|vcgtz_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcgtz_f64
end_comment

begin_comment
comment|// CHECK: fcmgt  {{d[0-9]+}}, {{d[0-9]+}}, #0
end_comment

begin_function
name|uint64x1_t
name|test_vcgtz_f64
parameter_list|(
name|float64x1_t
name|a
parameter_list|)
block|{
return|return
name|vcgtz_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcgtzq_f32
end_comment

begin_comment
comment|// CHECK: fcmgt  {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, #0
end_comment

begin_function
name|uint32x4_t
name|test_vcgtzq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
return|return
name|vcgtzq_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcgtzq_f64
end_comment

begin_comment
comment|// CHECK: fcmgt  {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, #0
end_comment

begin_function
name|uint64x2_t
name|test_vcgtzq_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|)
block|{
return|return
name|vcgtzq_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcltz_s8
end_comment

begin_comment
comment|// CHECK: sshr  {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, #7
end_comment

begin_function
name|uint8x8_t
name|test_vcltz_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
return|return
name|vcltz_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcltz_s16
end_comment

begin_comment
comment|// CHECK: sshr  {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, #15
end_comment

begin_function
name|uint16x4_t
name|test_vcltz_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|)
block|{
return|return
name|vcltz_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcltz_s32
end_comment

begin_comment
comment|// CHECK: sshr  {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, #31
end_comment

begin_function
name|uint32x2_t
name|test_vcltz_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|)
block|{
return|return
name|vcltz_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcltz_s64
end_comment

begin_comment
comment|// CHECK: sshr {{d[0-9]+}}, {{d[0-9]+}}, #63
end_comment

begin_function
name|uint64x1_t
name|test_vcltz_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|)
block|{
return|return
name|vcltz_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcltzq_s8
end_comment

begin_comment
comment|// CHECK: sshr  {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, #7
end_comment

begin_function
name|uint8x16_t
name|test_vcltzq_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
return|return
name|vcltzq_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcltzq_s16
end_comment

begin_comment
comment|// CHECK: sshr  {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, #15
end_comment

begin_function
name|uint16x8_t
name|test_vcltzq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
return|return
name|vcltzq_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcltzq_s32
end_comment

begin_comment
comment|// CHECK: sshr  {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, #31
end_comment

begin_function
name|uint32x4_t
name|test_vcltzq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
return|return
name|vcltzq_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcltzq_s64
end_comment

begin_comment
comment|// CHECK: sshr  {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, #63
end_comment

begin_function
name|uint64x2_t
name|test_vcltzq_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|)
block|{
return|return
name|vcltzq_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcltz_f32
end_comment

begin_comment
comment|// CHECK: fcmlt  {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, #0
end_comment

begin_function
name|uint32x2_t
name|test_vcltz_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
return|return
name|vcltz_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcltz_f64
end_comment

begin_comment
comment|// CHECK: fcmlt  {{d[0-9]+}}, {{d[0-9]+}}, #0
end_comment

begin_function
name|uint64x1_t
name|test_vcltz_f64
parameter_list|(
name|float64x1_t
name|a
parameter_list|)
block|{
return|return
name|vcltz_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcltzq_f32
end_comment

begin_comment
comment|// CHECK: fcmlt  {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, #0
end_comment

begin_function
name|uint32x4_t
name|test_vcltzq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
return|return
name|vcltzq_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcltzq_f64
end_comment

begin_comment
comment|// CHECK: fcmlt  {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, #0
end_comment

begin_function
name|uint64x2_t
name|test_vcltzq_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|)
block|{
return|return
name|vcltzq_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrev16_s8
end_comment

begin_comment
comment|// CHECK: rev16 v{{[0-9]+}}.8b, v{{[0-9]+}}.8b
end_comment

begin_function
name|int8x8_t
name|test_vrev16_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
return|return
name|vrev16_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrev16_u8
end_comment

begin_comment
comment|// CHECK: rev16 v{{[0-9]+}}.8b, v{{[0-9]+}}.8b
end_comment

begin_function
name|uint8x8_t
name|test_vrev16_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|)
block|{
return|return
name|vrev16_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrev16_p8
end_comment

begin_comment
comment|// CHECK: rev16 v{{[0-9]+}}.8b, v{{[0-9]+}}.8b
end_comment

begin_function
name|poly8x8_t
name|test_vrev16_p8
parameter_list|(
name|poly8x8_t
name|a
parameter_list|)
block|{
return|return
name|vrev16_p8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrev16q_s8
end_comment

begin_comment
comment|// CHECK: rev16 v{{[0-9]+}}.16b, v{{[0-9]+}}.16b
end_comment

begin_function
name|int8x16_t
name|test_vrev16q_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
return|return
name|vrev16q_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrev16q_u8
end_comment

begin_comment
comment|// CHECK: rev16 v{{[0-9]+}}.16b, v{{[0-9]+}}.16b
end_comment

begin_function
name|uint8x16_t
name|test_vrev16q_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|)
block|{
return|return
name|vrev16q_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrev16q_p8
end_comment

begin_comment
comment|// CHECK: rev16 v{{[0-9]+}}.16b, v{{[0-9]+}}.16b
end_comment

begin_function
name|poly8x16_t
name|test_vrev16q_p8
parameter_list|(
name|poly8x16_t
name|a
parameter_list|)
block|{
return|return
name|vrev16q_p8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrev32_s8
end_comment

begin_comment
comment|// CHECK: rev32 v{{[0-9]+}}.8b, v{{[0-9]+}}.8b
end_comment

begin_function
name|int8x8_t
name|test_vrev32_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
return|return
name|vrev32_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrev32_s16
end_comment

begin_comment
comment|// CHECK: rev32 v{{[0-9]+}}.4h, v{{[0-9]+}}.4h
end_comment

begin_function
name|int16x4_t
name|test_vrev32_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|)
block|{
return|return
name|vrev32_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrev32_u8
end_comment

begin_comment
comment|// CHECK: rev32 v{{[0-9]+}}.8b, v{{[0-9]+}}.8b
end_comment

begin_function
name|uint8x8_t
name|test_vrev32_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|)
block|{
return|return
name|vrev32_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrev32_u16
end_comment

begin_comment
comment|// CHECK: rev32 v{{[0-9]+}}.4h, v{{[0-9]+}}.4h
end_comment

begin_function
name|uint16x4_t
name|test_vrev32_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|)
block|{
return|return
name|vrev32_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrev32_p8
end_comment

begin_comment
comment|// CHECK: rev32 v{{[0-9]+}}.8b, v{{[0-9]+}}.8b
end_comment

begin_function
name|poly8x8_t
name|test_vrev32_p8
parameter_list|(
name|poly8x8_t
name|a
parameter_list|)
block|{
return|return
name|vrev32_p8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrev32_p16
end_comment

begin_comment
comment|// CHECK: rev32 v{{[0-9]+}}.4h, v{{[0-9]+}}.4h
end_comment

begin_function
name|poly16x4_t
name|test_vrev32_p16
parameter_list|(
name|poly16x4_t
name|a
parameter_list|)
block|{
return|return
name|vrev32_p16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrev32q_s8
end_comment

begin_comment
comment|// CHECK: rev32 v{{[0-9]+}}.16b, v{{[0-9]+}}.16b
end_comment

begin_function
name|int8x16_t
name|test_vrev32q_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
return|return
name|vrev32q_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrev32q_s16
end_comment

begin_comment
comment|// CHECK: rev32 v{{[0-9]+}}.8h, v{{[0-9]+}}.8h
end_comment

begin_function
name|int16x8_t
name|test_vrev32q_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
return|return
name|vrev32q_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrev32q_u8
end_comment

begin_comment
comment|// CHECK: rev32 v{{[0-9]+}}.16b, v{{[0-9]+}}.16b
end_comment

begin_function
name|uint8x16_t
name|test_vrev32q_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|)
block|{
return|return
name|vrev32q_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrev32q_u16
end_comment

begin_comment
comment|// CHECK: rev32 v{{[0-9]+}}.8h, v{{[0-9]+}}.8h
end_comment

begin_function
name|uint16x8_t
name|test_vrev32q_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|)
block|{
return|return
name|vrev32q_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrev32q_p8
end_comment

begin_comment
comment|// CHECK: rev32 v{{[0-9]+}}.16b, v{{[0-9]+}}.16b
end_comment

begin_function
name|poly8x16_t
name|test_vrev32q_p8
parameter_list|(
name|poly8x16_t
name|a
parameter_list|)
block|{
return|return
name|vrev32q_p8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrev32q_p16
end_comment

begin_comment
comment|// CHECK: rev32 v{{[0-9]+}}.8h, v{{[0-9]+}}.8h
end_comment

begin_function
name|poly16x8_t
name|test_vrev32q_p16
parameter_list|(
name|poly16x8_t
name|a
parameter_list|)
block|{
return|return
name|vrev32q_p16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrev64_s8
end_comment

begin_comment
comment|// CHECK: rev64 v{{[0-9]+}}.8b, v{{[0-9]+}}.8b
end_comment

begin_function
name|int8x8_t
name|test_vrev64_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
return|return
name|vrev64_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrev64_s16
end_comment

begin_comment
comment|// CHECK: rev64 v{{[0-9]+}}.4h, v{{[0-9]+}}.4h
end_comment

begin_function
name|int16x4_t
name|test_vrev64_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|)
block|{
return|return
name|vrev64_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrev64_s32
end_comment

begin_comment
comment|// CHECK: rev64 v{{[0-9]+}}.2s, v{{[0-9]+}}.2s
end_comment

begin_function
name|int32x2_t
name|test_vrev64_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|)
block|{
return|return
name|vrev64_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrev64_u8
end_comment

begin_comment
comment|// CHECK: rev64 v{{[0-9]+}}.8b, v{{[0-9]+}}.8b
end_comment

begin_function
name|uint8x8_t
name|test_vrev64_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|)
block|{
return|return
name|vrev64_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrev64_u16
end_comment

begin_comment
comment|// CHECK: rev64 v{{[0-9]+}}.4h, v{{[0-9]+}}.4h
end_comment

begin_function
name|uint16x4_t
name|test_vrev64_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|)
block|{
return|return
name|vrev64_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrev64_u32
end_comment

begin_comment
comment|// CHECK: rev64 v{{[0-9]+}}.2s, v{{[0-9]+}}.2s
end_comment

begin_function
name|uint32x2_t
name|test_vrev64_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|)
block|{
return|return
name|vrev64_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrev64_p8
end_comment

begin_comment
comment|// CHECK: rev64 v{{[0-9]+}}.8b, v{{[0-9]+}}.8b
end_comment

begin_function
name|poly8x8_t
name|test_vrev64_p8
parameter_list|(
name|poly8x8_t
name|a
parameter_list|)
block|{
return|return
name|vrev64_p8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrev64_p16
end_comment

begin_comment
comment|// CHECK: rev64 v{{[0-9]+}}.4h, v{{[0-9]+}}.4h
end_comment

begin_function
name|poly16x4_t
name|test_vrev64_p16
parameter_list|(
name|poly16x4_t
name|a
parameter_list|)
block|{
return|return
name|vrev64_p16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrev64_f32
end_comment

begin_comment
comment|// CHECK: rev64 v{{[0-9]+}}.2s, v{{[0-9]+}}.2s
end_comment

begin_function
name|float32x2_t
name|test_vrev64_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
return|return
name|vrev64_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrev64q_s8
end_comment

begin_comment
comment|// CHECK: rev64 v{{[0-9]+}}.16b, v{{[0-9]+}}.16b
end_comment

begin_function
name|int8x16_t
name|test_vrev64q_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
return|return
name|vrev64q_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrev64q_s16
end_comment

begin_comment
comment|// CHECK: rev64 v{{[0-9]+}}.8h, v{{[0-9]+}}.8h
end_comment

begin_function
name|int16x8_t
name|test_vrev64q_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
return|return
name|vrev64q_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrev64q_s32
end_comment

begin_comment
comment|// CHECK: rev64 v{{[0-9]+}}.4s, v{{[0-9]+}}.4s
end_comment

begin_function
name|int32x4_t
name|test_vrev64q_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
return|return
name|vrev64q_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrev64q_u8
end_comment

begin_comment
comment|// CHECK: rev64 v{{[0-9]+}}.16b, v{{[0-9]+}}.16b
end_comment

begin_function
name|uint8x16_t
name|test_vrev64q_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|)
block|{
return|return
name|vrev64q_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrev64q_u16
end_comment

begin_comment
comment|// CHECK: rev64 v{{[0-9]+}}.8h, v{{[0-9]+}}.8h
end_comment

begin_function
name|uint16x8_t
name|test_vrev64q_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|)
block|{
return|return
name|vrev64q_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrev64q_u32
end_comment

begin_comment
comment|// CHECK: rev64 v{{[0-9]+}}.4s, v{{[0-9]+}}.4s
end_comment

begin_function
name|uint32x4_t
name|test_vrev64q_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|)
block|{
return|return
name|vrev64q_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrev64q_p8
end_comment

begin_comment
comment|// CHECK: rev64 v{{[0-9]+}}.16b, v{{[0-9]+}}.16b
end_comment

begin_function
name|poly8x16_t
name|test_vrev64q_p8
parameter_list|(
name|poly8x16_t
name|a
parameter_list|)
block|{
return|return
name|vrev64q_p8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrev64q_p16
end_comment

begin_comment
comment|// CHECK: rev64 v{{[0-9]+}}.8h, v{{[0-9]+}}.8h
end_comment

begin_function
name|poly16x8_t
name|test_vrev64q_p16
parameter_list|(
name|poly16x8_t
name|a
parameter_list|)
block|{
return|return
name|vrev64q_p16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrev64q_f32
end_comment

begin_comment
comment|// CHECK: rev64 v{{[0-9]+}}.4s, v{{[0-9]+}}.4s
end_comment

begin_function
name|float32x4_t
name|test_vrev64q_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
return|return
name|vrev64q_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|int16x4_t
name|test_vpaddl_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vpaddl_s8
return|return
name|vpaddl_s8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: saddlp v{{[0-9]+}}.4h, v{{[0-9]+}}.8b
block|}
end_function

begin_function
name|int32x2_t
name|test_vpaddl_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vpaddl_s16
return|return
name|vpaddl_s16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: saddlp v{{[0-9]+}}.2s, v{{[0-9]+}}.4h
block|}
end_function

begin_function
name|int64x1_t
name|test_vpaddl_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vpaddl_s32
return|return
name|vpaddl_s32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: saddlp v{{[0-9]+}}.1d, v{{[0-9]+}}.2s
block|}
end_function

begin_function
name|uint16x4_t
name|test_vpaddl_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vpaddl_u8
return|return
name|vpaddl_u8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: uaddlp v{{[0-9]+}}.4h, v{{[0-9]+}}.8b
block|}
end_function

begin_function
name|uint32x2_t
name|test_vpaddl_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vpaddl_u16
return|return
name|vpaddl_u16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: uaddlp v{{[0-9]+}}.2s, v{{[0-9]+}}.4h
block|}
end_function

begin_function
name|uint64x1_t
name|test_vpaddl_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vpaddl_u32
return|return
name|vpaddl_u32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: uaddlp v{{[0-9]+}}.1d, v{{[0-9]+}}.2s
block|}
end_function

begin_function
name|int16x8_t
name|test_vpaddlq_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vpaddlq_s8
return|return
name|vpaddlq_s8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: saddlp v{{[0-9]+}}.8h, v{{[0-9]+}}.16b
block|}
end_function

begin_function
name|int32x4_t
name|test_vpaddlq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vpaddlq_s16
return|return
name|vpaddlq_s16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: saddlp v{{[0-9]+}}.4s, v{{[0-9]+}}.8h
block|}
end_function

begin_function
name|int64x2_t
name|test_vpaddlq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vpaddlq_s32
return|return
name|vpaddlq_s32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: saddlp v{{[0-9]+}}.2d, v{{[0-9]+}}.4s
block|}
end_function

begin_function
name|uint16x8_t
name|test_vpaddlq_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vpaddlq_u8
return|return
name|vpaddlq_u8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: uaddlp v{{[0-9]+}}.8h, v{{[0-9]+}}.16b
block|}
end_function

begin_function
name|uint32x4_t
name|test_vpaddlq_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vpaddlq_u16
return|return
name|vpaddlq_u16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: uaddlp v{{[0-9]+}}.4s, v{{[0-9]+}}.8h
block|}
end_function

begin_function
name|uint64x2_t
name|test_vpaddlq_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vpaddlq_u32
return|return
name|vpaddlq_u32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: uaddlp v{{[0-9]+}}.2d, v{{[0-9]+}}.4s
block|}
end_function

begin_function
name|int16x4_t
name|test_vpadal_s8
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vpadal_s8
return|return
name|vpadal_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sadalp v{{[0-9]+}}.4h, v{{[0-9]+}}.8b
block|}
end_function

begin_function
name|int32x2_t
name|test_vpadal_s16
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vpadal_s16
return|return
name|vpadal_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sadalp v{{[0-9]+}}.2s, v{{[0-9]+}}.4h
block|}
end_function

begin_function
name|int64x1_t
name|test_vpadal_s32
parameter_list|(
name|int64x1_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vpadal_s32
return|return
name|vpadal_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sadalp v{{[0-9]+}}.1d, v{{[0-9]+}}.2s
block|}
end_function

begin_function
name|uint16x4_t
name|test_vpadal_u8
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vpadal_u8
return|return
name|vpadal_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uadalp v{{[0-9]+}}.4h, v{{[0-9]+}}.8b
block|}
end_function

begin_function
name|uint32x2_t
name|test_vpadal_u16
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vpadal_u16
return|return
name|vpadal_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uadalp v{{[0-9]+}}.2s, v{{[0-9]+}}.4h
block|}
end_function

begin_function
name|uint64x1_t
name|test_vpadal_u32
parameter_list|(
name|uint64x1_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vpadal_u32
return|return
name|vpadal_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uadalp v{{[0-9]+}}.1d, v{{[0-9]+}}.2s
block|}
end_function

begin_function
name|int16x8_t
name|test_vpadalq_s8
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vpadalq_s8
return|return
name|vpadalq_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sadalp v{{[0-9]+}}.8h, v{{[0-9]+}}.16b
block|}
end_function

begin_function
name|int32x4_t
name|test_vpadalq_s16
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vpadalq_s16
return|return
name|vpadalq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sadalp v{{[0-9]+}}.4s, v{{[0-9]+}}.8h
block|}
end_function

begin_function
name|int64x2_t
name|test_vpadalq_s32
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vpadalq_s32
return|return
name|vpadalq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sadalp v{{[0-9]+}}.2d, v{{[0-9]+}}.4s
block|}
end_function

begin_function
name|uint16x8_t
name|test_vpadalq_u8
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint8x16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vpadalq_u8
return|return
name|vpadalq_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uadalp v{{[0-9]+}}.8h, v{{[0-9]+}}.16b
block|}
end_function

begin_function
name|uint32x4_t
name|test_vpadalq_u16
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vpadalq_u16
return|return
name|vpadalq_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uadalp v{{[0-9]+}}.4s, v{{[0-9]+}}.8h
block|}
end_function

begin_function
name|uint64x2_t
name|test_vpadalq_u32
parameter_list|(
name|uint64x2_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vpadalq_u32
return|return
name|vpadalq_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uadalp v{{[0-9]+}}.2d, v{{[0-9]+}}.4s
block|}
end_function

begin_function
name|int8x8_t
name|test_vqabs_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqabs_s8
return|return
name|vqabs_s8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: sqabs v{{[0-9]+}}.8b, v{{[0-9]+}}.8b
block|}
end_function

begin_function
name|int8x16_t
name|test_vqabsq_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqabsq_s8
return|return
name|vqabsq_s8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: sqabs v{{[0-9]+}}.16b, v{{[0-9]+}}.16b
block|}
end_function

begin_function
name|int16x4_t
name|test_vqabs_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqabs_s16
return|return
name|vqabs_s16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: sqabs v{{[0-9]+}}.4h, v{{[0-9]+}}.4h
block|}
end_function

begin_function
name|int16x8_t
name|test_vqabsq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqabsq_s16
return|return
name|vqabsq_s16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: sqabs v{{[0-9]+}}.8h, v{{[0-9]+}}.8h
block|}
end_function

begin_function
name|int32x2_t
name|test_vqabs_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqabs_s32
return|return
name|vqabs_s32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: sqabs v{{[0-9]+}}.2s, v{{[0-9]+}}.2s
block|}
end_function

begin_function
name|int32x4_t
name|test_vqabsq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqabsq_s32
return|return
name|vqabsq_s32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: sqabs v{{[0-9]+}}.4s, v{{[0-9]+}}.4s
block|}
end_function

begin_function
name|int64x2_t
name|test_vqabsq_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqabsq_s64
return|return
name|vqabsq_s64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: sqabs v{{[0-9]+}}.2d, v{{[0-9]+}}.2d
block|}
end_function

begin_function
name|int8x8_t
name|test_vqneg_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqneg_s8
return|return
name|vqneg_s8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: sqneg v{{[0-9]+}}.8b, v{{[0-9]+}}.8b
block|}
end_function

begin_function
name|int8x16_t
name|test_vqnegq_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqnegq_s8
return|return
name|vqnegq_s8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: sqneg v{{[0-9]+}}.16b, v{{[0-9]+}}.16b
block|}
end_function

begin_function
name|int16x4_t
name|test_vqneg_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqneg_s16
return|return
name|vqneg_s16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: sqneg v{{[0-9]+}}.4h, v{{[0-9]+}}.4h
block|}
end_function

begin_function
name|int16x8_t
name|test_vqnegq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqnegq_s16
return|return
name|vqnegq_s16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: sqneg v{{[0-9]+}}.8h, v{{[0-9]+}}.8h
block|}
end_function

begin_function
name|int32x2_t
name|test_vqneg_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqneg_s32
return|return
name|vqneg_s32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: sqneg v{{[0-9]+}}.2s, v{{[0-9]+}}.2s
block|}
end_function

begin_function
name|int32x4_t
name|test_vqnegq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqnegq_s32
return|return
name|vqnegq_s32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: sqneg v{{[0-9]+}}.4s, v{{[0-9]+}}.4s
block|}
end_function

begin_function
name|int64x2_t
name|test_vqnegq_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqnegq_s64
return|return
name|vqnegq_s64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: sqneg v{{[0-9]+}}.2d, v{{[0-9]+}}.2d
block|}
end_function

begin_function
name|int8x8_t
name|test_vneg_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vneg_s8
return|return
name|vneg_s8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: neg v{{[0-9]+}}.8b, v{{[0-9]+}}.8b
block|}
end_function

begin_function
name|int8x16_t
name|test_vnegq_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vnegq_s8
return|return
name|vnegq_s8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: neg v{{[0-9]+}}.16b, v{{[0-9]+}}.16b
block|}
end_function

begin_function
name|int16x4_t
name|test_vneg_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vneg_s16
return|return
name|vneg_s16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: neg v{{[0-9]+}}.4h, v{{[0-9]+}}.4h
block|}
end_function

begin_function
name|int16x8_t
name|test_vnegq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vnegq_s16
return|return
name|vnegq_s16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: neg v{{[0-9]+}}.8h, v{{[0-9]+}}.8h
block|}
end_function

begin_function
name|int32x2_t
name|test_vneg_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vneg_s32
return|return
name|vneg_s32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: neg v{{[0-9]+}}.2s, v{{[0-9]+}}.2s
block|}
end_function

begin_function
name|int32x4_t
name|test_vnegq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vnegq_s32
return|return
name|vnegq_s32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: neg v{{[0-9]+}}.4s, v{{[0-9]+}}.4s
block|}
end_function

begin_function
name|int64x2_t
name|test_vnegq_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vnegq_s64
return|return
name|vnegq_s64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: neg v{{[0-9]+}}.2d, v{{[0-9]+}}.2d
block|}
end_function

begin_function
name|float32x2_t
name|test_vneg_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vneg_f32
return|return
name|vneg_f32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: fneg v{{[0-9]+}}.2s, v{{[0-9]+}}.2s
block|}
end_function

begin_function
name|float32x4_t
name|test_vnegq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vnegq_f32
return|return
name|vnegq_f32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: fneg v{{[0-9]+}}.4s, v{{[0-9]+}}.4s
block|}
end_function

begin_function
name|float64x2_t
name|test_vnegq_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vnegq_f64
return|return
name|vnegq_f64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: fneg v{{[0-9]+}}.2d, v{{[0-9]+}}.2d
block|}
end_function

begin_function
name|int8x8_t
name|test_vabs_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vabs_s8
return|return
name|vabs_s8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: abs v{{[0-9]+}}.8b, v{{[0-9]+}}.8b
block|}
end_function

begin_function
name|int8x16_t
name|test_vabsq_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vabsq_s8
return|return
name|vabsq_s8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: abs v{{[0-9]+}}.16b, v{{[0-9]+}}.16b
block|}
end_function

begin_function
name|int16x4_t
name|test_vabs_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vabs_s16
return|return
name|vabs_s16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: abs v{{[0-9]+}}.4h, v{{[0-9]+}}.4h
block|}
end_function

begin_function
name|int16x8_t
name|test_vabsq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vabsq_s16
return|return
name|vabsq_s16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: abs v{{[0-9]+}}.8h, v{{[0-9]+}}.8h
block|}
end_function

begin_function
name|int32x2_t
name|test_vabs_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vabs_s32
return|return
name|vabs_s32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: abs v{{[0-9]+}}.2s, v{{[0-9]+}}.2s
block|}
end_function

begin_function
name|int32x4_t
name|test_vabsq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vabsq_s32
return|return
name|vabsq_s32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: abs v{{[0-9]+}}.4s, v{{[0-9]+}}.4s
block|}
end_function

begin_function
name|int64x2_t
name|test_vabsq_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vabsq_s64
return|return
name|vabsq_s64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: abs v{{[0-9]+}}.2d, v{{[0-9]+}}.2d
block|}
end_function

begin_function
name|float32x2_t
name|test_vabs_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vabs_f32
return|return
name|vabs_f32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: fabs v{{[0-9]+}}.2s, v{{[0-9]+}}.2s
block|}
end_function

begin_function
name|float32x4_t
name|test_vabsq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vabsq_f32
return|return
name|vabsq_f32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: fabs v{{[0-9]+}}.4s, v{{[0-9]+}}.4s
block|}
end_function

begin_function
name|float64x2_t
name|test_vabsq_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vabsq_f64
return|return
name|vabsq_f64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: fabs v{{[0-9]+}}.2d, v{{[0-9]+}}.2d
block|}
end_function

begin_function
name|int8x8_t
name|test_vuqadd_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vuqadd_s8
return|return
name|vuqadd_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: suqadd v{{[0-9]+}}.8b, v{{[0-9]+}}.8b
block|}
end_function

begin_function
name|int8x16_t
name|test_vuqaddq_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vuqaddq_s8
return|return
name|vuqaddq_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: suqadd v{{[0-9]+}}.16b, v{{[0-9]+}}.16b
block|}
end_function

begin_function
name|int16x4_t
name|test_vuqadd_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vuqadd_s16
return|return
name|vuqadd_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: suqadd v{{[0-9]+}}.4h, v{{[0-9]+}}.4h
block|}
end_function

begin_function
name|int16x8_t
name|test_vuqaddq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vuqaddq_s16
return|return
name|vuqaddq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: suqadd v{{[0-9]+}}.8h, v{{[0-9]+}}.8h
block|}
end_function

begin_function
name|int32x2_t
name|test_vuqadd_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vuqadd_s32
return|return
name|vuqadd_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: suqadd v{{[0-9]+}}.2s, v{{[0-9]+}}.2s
block|}
end_function

begin_function
name|int32x4_t
name|test_vuqaddq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vuqaddq_s32
return|return
name|vuqaddq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: suqadd v{{[0-9]+}}.4s, v{{[0-9]+}}.4s
block|}
end_function

begin_function
name|int64x2_t
name|test_vuqaddq_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vuqaddq_s64
return|return
name|vuqaddq_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: suqadd v{{[0-9]+}}.2d, v{{[0-9]+}}.2d
block|}
end_function

begin_function
name|int8x8_t
name|test_vcls_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcls_s8
return|return
name|vcls_s8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: cls v{{[0-9]+}}.8b, v{{[0-9]+}}.8b
block|}
end_function

begin_function
name|int8x16_t
name|test_vclsq_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vclsq_s8
return|return
name|vclsq_s8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: cls v{{[0-9]+}}.16b, v{{[0-9]+}}.16b
block|}
end_function

begin_function
name|int16x4_t
name|test_vcls_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcls_s16
return|return
name|vcls_s16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: cls v{{[0-9]+}}.4h, v{{[0-9]+}}.4h
block|}
end_function

begin_function
name|int16x8_t
name|test_vclsq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vclsq_s16
return|return
name|vclsq_s16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: cls v{{[0-9]+}}.8h, v{{[0-9]+}}.8h
block|}
end_function

begin_function
name|int32x2_t
name|test_vcls_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcls_s32
return|return
name|vcls_s32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: cls v{{[0-9]+}}.2s, v{{[0-9]+}}.2s
block|}
end_function

begin_function
name|int32x4_t
name|test_vclsq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vclsq_s32
return|return
name|vclsq_s32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: cls v{{[0-9]+}}.4s, v{{[0-9]+}}.4s
block|}
end_function

begin_function
name|int8x8_t
name|test_vclz_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vclz_s8
return|return
name|vclz_s8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: clz v{{[0-9]+}}.8b, v{{[0-9]+}}.8b
block|}
end_function

begin_function
name|int8x16_t
name|test_vclzq_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vclzq_s8
return|return
name|vclzq_s8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: clz v{{[0-9]+}}.16b, v{{[0-9]+}}.16b
block|}
end_function

begin_function
name|int16x4_t
name|test_vclz_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vclz_s16
return|return
name|vclz_s16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: clz v{{[0-9]+}}.4h, v{{[0-9]+}}.4h
block|}
end_function

begin_function
name|int16x8_t
name|test_vclzq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vclzq_s16
return|return
name|vclzq_s16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: clz v{{[0-9]+}}.8h, v{{[0-9]+}}.8h
block|}
end_function

begin_function
name|int32x2_t
name|test_vclz_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vclz_s32
return|return
name|vclz_s32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: clz v{{[0-9]+}}.2s, v{{[0-9]+}}.2s
block|}
end_function

begin_function
name|int32x4_t
name|test_vclzq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vclzq_s32
return|return
name|vclzq_s32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: clz v{{[0-9]+}}.4s, v{{[0-9]+}}.4s
block|}
end_function

begin_function
name|uint8x8_t
name|test_vclz_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vclz_u8
return|return
name|vclz_u8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: clz v{{[0-9]+}}.8b, v{{[0-9]+}}.8b
block|}
end_function

begin_function
name|uint8x16_t
name|test_vclzq_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vclzq_u8
return|return
name|vclzq_u8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: clz v{{[0-9]+}}.16b, v{{[0-9]+}}.16b
block|}
end_function

begin_function
name|uint16x4_t
name|test_vclz_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vclz_u16
return|return
name|vclz_u16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: clz v{{[0-9]+}}.4h, v{{[0-9]+}}.4h
block|}
end_function

begin_function
name|uint16x8_t
name|test_vclzq_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vclzq_u16
return|return
name|vclzq_u16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: clz v{{[0-9]+}}.8h, v{{[0-9]+}}.8h
block|}
end_function

begin_function
name|uint32x2_t
name|test_vclz_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vclz_u32
return|return
name|vclz_u32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: clz v{{[0-9]+}}.2s, v{{[0-9]+}}.2s
block|}
end_function

begin_function
name|uint32x4_t
name|test_vclzq_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vclzq_u32
return|return
name|vclzq_u32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: clz v{{[0-9]+}}.4s, v{{[0-9]+}}.4s
block|}
end_function

begin_function
name|int8x8_t
name|test_vcnt_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcnt_s8
return|return
name|vcnt_s8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: cnt v{{[0-9]+}}.8b, v{{[0-9]+}}.8b
block|}
end_function

begin_function
name|int8x16_t
name|test_vcntq_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcntq_s8
return|return
name|vcntq_s8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: cnt v{{[0-9]+}}.16b, v{{[0-9]+}}.16b
block|}
end_function

begin_function
name|uint8x8_t
name|test_vcnt_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcnt_u8
return|return
name|vcnt_u8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: cnt v{{[0-9]+}}.8b, v{{[0-9]+}}.8b
block|}
end_function

begin_function
name|uint8x16_t
name|test_vcntq_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcntq_u8
return|return
name|vcntq_u8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: cnt v{{[0-9]+}}.16b, v{{[0-9]+}}.16b
block|}
end_function

begin_function
name|poly8x8_t
name|test_vcnt_p8
parameter_list|(
name|poly8x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcnt_p8
return|return
name|vcnt_p8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: cnt v{{[0-9]+}}.8b, v{{[0-9]+}}.8b
block|}
end_function

begin_function
name|poly8x16_t
name|test_vcntq_p8
parameter_list|(
name|poly8x16_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcntq_p8
return|return
name|vcntq_p8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: cnt v{{[0-9]+}}.16b, v{{[0-9]+}}.16b
block|}
end_function

begin_function
name|int8x8_t
name|test_vmvn_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmvn_s8
return|return
name|vmvn_s8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: {{mvn|not}} v{{[0-9]+}}.8b, v{{[0-9]+}}.8b
block|}
end_function

begin_function
name|int8x16_t
name|test_vmvnq_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmvnq_s8
return|return
name|vmvnq_s8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: {{mvn|not}} v{{[0-9]+}}.16b, v{{[0-9]+}}.16b
block|}
end_function

begin_function
name|int16x4_t
name|test_vmvn_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmvn_s16
return|return
name|vmvn_s16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: {{mvn|not}} v{{[0-9]+}}.8b, v{{[0-9]+}}.8b
block|}
end_function

begin_function
name|int16x8_t
name|test_vmvnq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmvnq_s16
return|return
name|vmvnq_s16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: {{mvn|not}} v{{[0-9]+}}.16b, v{{[0-9]+}}.16b
block|}
end_function

begin_function
name|int32x2_t
name|test_vmvn_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmvn_s32
return|return
name|vmvn_s32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: {{mvn|not}} v{{[0-9]+}}.8b, v{{[0-9]+}}.8b
block|}
end_function

begin_function
name|int32x4_t
name|test_vmvnq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmvnq_s32
return|return
name|vmvnq_s32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: {{mvn|not}} v{{[0-9]+}}.16b, v{{[0-9]+}}.16b
block|}
end_function

begin_function
name|uint8x8_t
name|test_vmvn_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmvn_u8
return|return
name|vmvn_u8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: {{mvn|not}} v{{[0-9]+}}.8b, v{{[0-9]+}}.8b
block|}
end_function

begin_function
name|uint8x16_t
name|test_vmvnq_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmvnq_u8
return|return
name|vmvnq_u8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: {{mvn|not}} v{{[0-9]+}}.16b, v{{[0-9]+}}.16b
block|}
end_function

begin_function
name|uint16x4_t
name|test_vmvn_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmvn_u16
return|return
name|vmvn_u16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: {{mvn|not}} v{{[0-9]+}}.8b, v{{[0-9]+}}.8b
block|}
end_function

begin_function
name|uint16x8_t
name|test_vmvnq_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmvnq_u16
return|return
name|vmvnq_u16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: {{mvn|not}} v{{[0-9]+}}.16b, v{{[0-9]+}}.16b
block|}
end_function

begin_function
name|uint32x2_t
name|test_vmvn_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmvn_u32
return|return
name|vmvn_u32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: {{mvn|not}} v{{[0-9]+}}.8b, v{{[0-9]+}}.8b
block|}
end_function

begin_function
name|uint32x4_t
name|test_vmvnq_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmvnq_u32
return|return
name|vmvnq_u32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: {{mvn|not}} v{{[0-9]+}}.16b, v{{[0-9]+}}.16b
block|}
end_function

begin_function
name|poly8x8_t
name|test_vmvn_p8
parameter_list|(
name|poly8x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmvn_p8
return|return
name|vmvn_p8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: {{mvn|not}} v{{[0-9]+}}.8b, v{{[0-9]+}}.8b
block|}
end_function

begin_function
name|poly8x16_t
name|test_vmvnq_p8
parameter_list|(
name|poly8x16_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmvnq_p8
return|return
name|vmvnq_p8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: {{mvn|not}} v{{[0-9]+}}.16b, v{{[0-9]+}}.16b
block|}
end_function

begin_function
name|int8x8_t
name|test_vrbit_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrbit_s8
return|return
name|vrbit_s8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: rbit v{{[0-9]+}}.8b, v{{[0-9]+}}.8b
block|}
end_function

begin_function
name|int8x16_t
name|test_vrbitq_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrbitq_s8
return|return
name|vrbitq_s8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: rbit v{{[0-9]+}}.16b, v{{[0-9]+}}.16b
block|}
end_function

begin_function
name|uint8x8_t
name|test_vrbit_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrbit_u8
return|return
name|vrbit_u8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: rbit v{{[0-9]+}}.8b, v{{[0-9]+}}.8b
block|}
end_function

begin_function
name|uint8x16_t
name|test_vrbitq_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrbitq_u8
return|return
name|vrbitq_u8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: rbit v{{[0-9]+}}.16b, v{{[0-9]+}}.16b
block|}
end_function

begin_function
name|poly8x8_t
name|test_vrbit_p8
parameter_list|(
name|poly8x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrbit_p8
return|return
name|vrbit_p8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: rbit v{{[0-9]+}}.8b, v{{[0-9]+}}.8b
block|}
end_function

begin_function
name|poly8x16_t
name|test_vrbitq_p8
parameter_list|(
name|poly8x16_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrbitq_p8
return|return
name|vrbitq_p8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: rbit v{{[0-9]+}}.16b, v{{[0-9]+}}.16b
block|}
end_function

begin_function
name|int8x8_t
name|test_vmovn_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmovn_s16
return|return
name|vmovn_s16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: xtn v{{[0-9]+}}.8b, v{{[0-9]+}}.8h
block|}
end_function

begin_function
name|int16x4_t
name|test_vmovn_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmovn_s32
return|return
name|vmovn_s32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: xtn v{{[0-9]+}}.4h, v{{[0-9]+}}.4s
block|}
end_function

begin_function
name|int32x2_t
name|test_vmovn_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmovn_s64
return|return
name|vmovn_s64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: xtn v{{[0-9]+}}.2s, v{{[0-9]+}}.2d
block|}
end_function

begin_function
name|uint8x8_t
name|test_vmovn_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmovn_u16
return|return
name|vmovn_u16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: xtn v{{[0-9]+}}.8b, v{{[0-9]+}}.8h
block|}
end_function

begin_function
name|uint16x4_t
name|test_vmovn_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmovn_u32
return|return
name|vmovn_u32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: xtn v{{[0-9]+}}.4h, v{{[0-9]+}}.4s
block|}
end_function

begin_function
name|uint32x2_t
name|test_vmovn_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmovn_u64
return|return
name|vmovn_u64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: xtn v{{[0-9]+}}.2s, v{{[0-9]+}}.2d
block|}
end_function

begin_function
name|int8x16_t
name|test_vmovn_high_s16
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmovn_high_s16
return|return
name|vmovn_high_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: xtn2 v{{[0-9]+}}.16b, v{{[0-9]+}}.8h
block|}
end_function

begin_function
name|int16x8_t
name|test_vmovn_high_s32
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmovn_high_s32
return|return
name|vmovn_high_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: xtn2 v{{[0-9]+}}.8h, v{{[0-9]+}}.4s
block|}
end_function

begin_function
name|int32x4_t
name|test_vmovn_high_s64
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmovn_high_s64
return|return
name|vmovn_high_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: xtn2 v{{[0-9]+}}.4s, v{{[0-9]+}}.2d
block|}
end_function

begin_function
name|int8x16_t
name|test_vmovn_high_u16
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmovn_high_u16
return|return
name|vmovn_high_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: xtn2 v{{[0-9]+}}.16b, v{{[0-9]+}}.8h
block|}
end_function

begin_function
name|int16x8_t
name|test_vmovn_high_u32
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmovn_high_u32
return|return
name|vmovn_high_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: xtn2 v{{[0-9]+}}.8h, v{{[0-9]+}}.4s
block|}
end_function

begin_function
name|int32x4_t
name|test_vmovn_high_u64
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmovn_high_u64
return|return
name|vmovn_high_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: xtn2 v{{[0-9]+}}.4s, v{{[0-9]+}}.2d
block|}
end_function

begin_function
name|int8x8_t
name|test_vqmovun_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqmovun_s16
return|return
name|vqmovun_s16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: sqxtun v{{[0-9]+}}.8b, v{{[0-9]+}}.8h
block|}
end_function

begin_function
name|int16x4_t
name|test_vqmovun_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqmovun_s32
return|return
name|vqmovun_s32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: sqxtun v{{[0-9]+}}.4h, v{{[0-9]+}}.4s
block|}
end_function

begin_function
name|int32x2_t
name|test_vqmovun_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqmovun_s64
return|return
name|vqmovun_s64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: sqxtun v{{[0-9]+}}.2s, v{{[0-9]+}}.2d
block|}
end_function

begin_function
name|int8x16_t
name|test_vqmovun_high_s16
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqmovun_high_s16
return|return
name|vqmovun_high_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sqxtun2 v{{[0-9]+}}.16b, v{{[0-9]+}}.8h
block|}
end_function

begin_function
name|int16x8_t
name|test_vqmovun_high_s32
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqmovun_high_s32
return|return
name|vqmovun_high_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sqxtun2 v{{[0-9]+}}.8h, v{{[0-9]+}}.4s
block|}
end_function

begin_function
name|int32x4_t
name|test_vqmovun_high_s64
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqmovun_high_s64
return|return
name|vqmovun_high_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sqxtun2 v{{[0-9]+}}.4s, v{{[0-9]+}}.2d
block|}
end_function

begin_function
name|int8x8_t
name|test_vqmovn_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqmovn_s16
return|return
name|vqmovn_s16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: sqxtn v{{[0-9]+}}.8b, v{{[0-9]+}}.8h
block|}
end_function

begin_function
name|int16x4_t
name|test_vqmovn_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqmovn_s32
return|return
name|vqmovn_s32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: sqxtn v{{[0-9]+}}.4h, v{{[0-9]+}}.4s
block|}
end_function

begin_function
name|int32x2_t
name|test_vqmovn_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqmovn_s64
return|return
name|vqmovn_s64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: sqxtn v{{[0-9]+}}.2s, v{{[0-9]+}}.2d
block|}
end_function

begin_function
name|int8x16_t
name|test_vqmovn_high_s16
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqmovn_high_s16
return|return
name|vqmovn_high_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sqxtn2 v{{[0-9]+}}.16b, v{{[0-9]+}}.8h
block|}
end_function

begin_function
name|int16x8_t
name|test_vqmovn_high_s32
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqmovn_high_s32
return|return
name|vqmovn_high_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sqxtn2 v{{[0-9]+}}.8h, v{{[0-9]+}}.4s
block|}
end_function

begin_function
name|int32x4_t
name|test_vqmovn_high_s64
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqmovn_high_s64
return|return
name|vqmovn_high_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sqxtn2 v{{[0-9]+}}.4s, v{{[0-9]+}}.2d
block|}
end_function

begin_function
name|uint8x8_t
name|test_vqmovn_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqmovn_u16
return|return
name|vqmovn_u16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: uqxtn v{{[0-9]+}}.8b, v{{[0-9]+}}.8h
block|}
end_function

begin_function
name|uint16x4_t
name|test_vqmovn_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqmovn_u32
return|return
name|vqmovn_u32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: uqxtn v{{[0-9]+}}.4h, v{{[0-9]+}}.4s
block|}
end_function

begin_function
name|uint32x2_t
name|test_vqmovn_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqmovn_u64
return|return
name|vqmovn_u64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: uqxtn v{{[0-9]+}}.2s, v{{[0-9]+}}.2d
block|}
end_function

begin_function
name|uint8x16_t
name|test_vqmovn_high_u16
parameter_list|(
name|uint8x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqmovn_high_u16
return|return
name|vqmovn_high_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uqxtn2 v{{[0-9]+}}.16b, v{{[0-9]+}}.8h
block|}
end_function

begin_function
name|uint16x8_t
name|test_vqmovn_high_u32
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqmovn_high_u32
return|return
name|vqmovn_high_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uqxtn2 v{{[0-9]+}}.8h, v{{[0-9]+}}.4s
block|}
end_function

begin_function
name|uint32x4_t
name|test_vqmovn_high_u64
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqmovn_high_u64
return|return
name|vqmovn_high_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uqxtn2 v{{[0-9]+}}.4s, v{{[0-9]+}}.2d
block|}
end_function

begin_function
name|int16x8_t
name|test_vshll_n_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vshll_n_s8
return|return
name|vshll_n_s8
argument_list|(
name|a
argument_list|,
literal|8
argument_list|)
return|;
comment|// CHECK: shll {{v[0-9]+}}.8h, {{v[0-9]+}}.8b, #8
block|}
end_function

begin_function
name|int32x4_t
name|test_vshll_n_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vshll_n_s16
return|return
name|vshll_n_s16
argument_list|(
name|a
argument_list|,
literal|16
argument_list|)
return|;
comment|// CHECK: shll {{v[0-9]+}}.4s, {{v[0-9]+}}.4h, #16
block|}
end_function

begin_function
name|int64x2_t
name|test_vshll_n_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vshll_n_s32
return|return
name|vshll_n_s32
argument_list|(
name|a
argument_list|,
literal|32
argument_list|)
return|;
comment|// CHECK: shll {{v[0-9]+}}.2d, {{v[0-9]+}}.2s, #32
block|}
end_function

begin_function
name|uint16x8_t
name|test_vshll_n_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vshll_n_u8
return|return
name|vshll_n_u8
argument_list|(
name|a
argument_list|,
literal|8
argument_list|)
return|;
comment|// CHECK: shll {{v[0-9]+}}.8h, {{v[0-9]+}}.8b, #8
block|}
end_function

begin_function
name|uint32x4_t
name|test_vshll_n_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vshll_n_u16
return|return
name|vshll_n_u16
argument_list|(
name|a
argument_list|,
literal|16
argument_list|)
return|;
comment|// CHECK: shll {{v[0-9]+}}.4s, {{v[0-9]+}}.4h, #16
block|}
end_function

begin_function
name|uint64x2_t
name|test_vshll_n_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vshll_n_u32
return|return
name|vshll_n_u32
argument_list|(
name|a
argument_list|,
literal|32
argument_list|)
return|;
comment|// CHECK: shll {{v[0-9]+}}.2d, {{v[0-9]+}}.2s, #32
block|}
end_function

begin_function
name|int16x8_t
name|test_vshll_high_n_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vshll_high_n_s8
return|return
name|vshll_high_n_s8
argument_list|(
name|a
argument_list|,
literal|8
argument_list|)
return|;
comment|// CHECK: shll2 {{v[0-9]+}}.8h, {{v[0-9]+}}.16b, #8
block|}
end_function

begin_function
name|int32x4_t
name|test_vshll_high_n_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vshll_high_n_s16
return|return
name|vshll_high_n_s16
argument_list|(
name|a
argument_list|,
literal|16
argument_list|)
return|;
comment|// CHECK: shll2 {{v[0-9]+}}.4s, {{v[0-9]+}}.8h, #16
block|}
end_function

begin_function
name|int64x2_t
name|test_vshll_high_n_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vshll_high_n_s32
return|return
name|vshll_high_n_s32
argument_list|(
name|a
argument_list|,
literal|32
argument_list|)
return|;
comment|// CHECK: shll2 {{v[0-9]+}}.2d, {{v[0-9]+}}.4s, #32
block|}
end_function

begin_function
name|uint16x8_t
name|test_vshll_high_n_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vshll_high_n_u8
return|return
name|vshll_high_n_u8
argument_list|(
name|a
argument_list|,
literal|8
argument_list|)
return|;
comment|// CHECK: shll2 {{v[0-9]+}}.8h, {{v[0-9]+}}.16b, #8
block|}
end_function

begin_function
name|uint32x4_t
name|test_vshll_high_n_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vshll_high_n_u16
return|return
name|vshll_high_n_u16
argument_list|(
name|a
argument_list|,
literal|16
argument_list|)
return|;
comment|// CHECK: shll2 {{v[0-9]+}}.4s, {{v[0-9]+}}.8h, #16
block|}
end_function

begin_function
name|uint64x2_t
name|test_vshll_high_n_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vshll_high_n_u32
return|return
name|vshll_high_n_u32
argument_list|(
name|a
argument_list|,
literal|32
argument_list|)
return|;
comment|// CHECK: shll2 {{v[0-9]+}}.2d, {{v[0-9]+}}.4s, #32
block|}
end_function

begin_function
name|float16x4_t
name|test_vcvt_f16_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
comment|//CHECK-LABEL: test_vcvt_f16_f32
return|return
name|vcvt_f16_f32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: fcvtn v{{[0-9]+}}.4h, v{{[0-9]+}}.4s
block|}
end_function

begin_function
name|float16x8_t
name|test_vcvt_high_f16_f32
parameter_list|(
name|float16x4_t
name|a
parameter_list|,
name|float32x4_t
name|b
parameter_list|)
block|{
comment|//CHECK-LABEL: test_vcvt_high_f16_f32
return|return
name|vcvt_high_f16_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: fcvtn2 v{{[0-9]+}}.8h, v{{[0-9]+}}.4s
block|}
end_function

begin_function
name|float32x2_t
name|test_vcvt_f32_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|)
block|{
comment|//CHECK-LABEL: test_vcvt_f32_f64
return|return
name|vcvt_f32_f64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: fcvtn v{{[0-9]+}}.2s, v{{[0-9]+}}.2d
block|}
end_function

begin_function
name|float32x4_t
name|test_vcvt_high_f32_f64
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float64x2_t
name|b
parameter_list|)
block|{
comment|//CHECK-LABEL: test_vcvt_high_f32_f64
return|return
name|vcvt_high_f32_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: fcvtn2 v{{[0-9]+}}.4s, v{{[0-9]+}}.2d
block|}
end_function

begin_function
name|float32x2_t
name|test_vcvtx_f32_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|)
block|{
comment|//CHECK-LABEL: test_vcvtx_f32_f64
return|return
name|vcvtx_f32_f64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: fcvtxn v{{[0-9]+}}.2s, v{{[0-9]+}}.2d
block|}
end_function

begin_function
name|float32x4_t
name|test_vcvtx_high_f32_f64
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float64x2_t
name|b
parameter_list|)
block|{
comment|//CHECK-LABEL: test_vcvtx_high_f32_f64
return|return
name|vcvtx_high_f32_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: fcvtxn2 v{{[0-9]+}}.4s, v{{[0-9]+}}.2d
block|}
end_function

begin_function
name|float32x4_t
name|test_vcvt_f32_f16
parameter_list|(
name|float16x4_t
name|a
parameter_list|)
block|{
comment|//CHECK-LABEL: test_vcvt_f32_f16
return|return
name|vcvt_f32_f16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: fcvtl v{{[0-9]+}}.4s, v{{[0-9]+}}.4h
block|}
end_function

begin_function
name|float32x4_t
name|test_vcvt_high_f32_f16
parameter_list|(
name|float16x8_t
name|a
parameter_list|)
block|{
comment|//CHECK-LABEL: test_vcvt_high_f32_f16
return|return
name|vcvt_high_f32_f16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: fcvtl2 v{{[0-9]+}}.4s, v{{[0-9]+}}.8h
block|}
end_function

begin_function
name|float64x2_t
name|test_vcvt_f64_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
comment|//CHECK-LABEL: test_vcvt_f64_f32
return|return
name|vcvt_f64_f32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: fcvtl v{{[0-9]+}}.2d, v{{[0-9]+}}.2s
block|}
end_function

begin_function
name|float64x2_t
name|test_vcvt_high_f64_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
comment|//CHECK-LABEL: test_vcvt_high_f64_f32
return|return
name|vcvt_high_f64_f32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: fcvtl2 v{{[0-9]+}}.2d, v{{[0-9]+}}.4s
block|}
end_function

begin_function
name|float32x2_t
name|test_vrndn_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
comment|//CHECK-LABEL: test_vrndn_f32
return|return
name|vrndn_f32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: frintn v{{[0-9]+}}.2s, v{{[0-9]+}}.2s
block|}
end_function

begin_function
name|float32x4_t
name|test_vrndnq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
comment|//CHECK-LABEL: test_vrndnq_f32
return|return
name|vrndnq_f32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: frintn v{{[0-9]+}}.4s, v{{[0-9]+}}.4s
block|}
end_function

begin_function
name|float64x2_t
name|test_vrndnq_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|)
block|{
comment|//CHECK-LABEL: test_vrndnq_f64
return|return
name|vrndnq_f64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: frintn v{{[0-9]+}}.2d, v{{[0-9]+}}.2d
block|}
end_function

begin_function
name|float32x2_t
name|test_vrnda_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
comment|//CHECK-LABEL: test_vrnda_f32
return|return
name|vrnda_f32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: frinta v{{[0-9]+}}.2s, v{{[0-9]+}}.2s
block|}
end_function

begin_function
name|float32x4_t
name|test_vrndaq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
comment|//CHECK-LABEL: test_vrndaq_f32
return|return
name|vrndaq_f32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: frinta v{{[0-9]+}}.4s, v{{[0-9]+}}.4s
block|}
end_function

begin_function
name|float64x2_t
name|test_vrndaq_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|)
block|{
comment|//CHECK-LABEL: test_vrndaq_f64
return|return
name|vrndaq_f64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: frinta v{{[0-9]+}}.2d, v{{[0-9]+}}.2d
block|}
end_function

begin_function
name|float32x2_t
name|test_vrndp_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
comment|//CHECK-LABEL: test_vrndp_f32
return|return
name|vrndp_f32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: frintp v{{[0-9]+}}.2s, v{{[0-9]+}}.2s
block|}
end_function

begin_function
name|float32x4_t
name|test_vrndpq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
comment|//CHECK-LABEL: test_vrndpq_f32
return|return
name|vrndpq_f32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: frintp v{{[0-9]+}}.4s, v{{[0-9]+}}.4s
block|}
end_function

begin_function
name|float64x2_t
name|test_vrndpq_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|)
block|{
comment|//CHECK-LABEL: test_vrndpq_f64
return|return
name|vrndpq_f64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: frintp v{{[0-9]+}}.2d, v{{[0-9]+}}.2d
block|}
end_function

begin_function
name|float32x2_t
name|test_vrndm_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
comment|//CHECK-LABEL: test_vrndm_f32
return|return
name|vrndm_f32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: frintm v{{[0-9]+}}.2s, v{{[0-9]+}}.2s
block|}
end_function

begin_function
name|float32x4_t
name|test_vrndmq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
comment|//CHECK-LABEL: test_vrndmq_f32
return|return
name|vrndmq_f32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: frintm v{{[0-9]+}}.4s, v{{[0-9]+}}.4s
block|}
end_function

begin_function
name|float64x2_t
name|test_vrndmq_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|)
block|{
comment|//CHECK-LABEL: test_vrndmq_f64
return|return
name|vrndmq_f64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: frintm v{{[0-9]+}}.2d, v{{[0-9]+}}.2d
block|}
end_function

begin_function
name|float32x2_t
name|test_vrndx_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
comment|//CHECK-LABEL: test_vrndx_f32
return|return
name|vrndx_f32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: frintx v{{[0-9]+}}.2s, v{{[0-9]+}}.2s
block|}
end_function

begin_function
name|float32x4_t
name|test_vrndxq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
comment|//CHECK-LABEL: test_vrndxq_f32
return|return
name|vrndxq_f32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: frintx v{{[0-9]+}}.4s, v{{[0-9]+}}.4s
block|}
end_function

begin_function
name|float64x2_t
name|test_vrndxq_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|)
block|{
comment|//CHECK-LABEL: test_vrndxq_f64
return|return
name|vrndxq_f64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: frintx v{{[0-9]+}}.2d, v{{[0-9]+}}.2d
block|}
end_function

begin_function
name|float32x2_t
name|test_vrnd_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
comment|//CHECK-LABEL: test_vrnd_f32
return|return
name|vrnd_f32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: frintz v{{[0-9]+}}.2s, v{{[0-9]+}}.2s
block|}
end_function

begin_function
name|float32x4_t
name|test_vrndq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
comment|//CHECK-LABEL: test_vrndq_f32
return|return
name|vrndq_f32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: frintz v{{[0-9]+}}.4s, v{{[0-9]+}}.4s
block|}
end_function

begin_function
name|float64x2_t
name|test_vrndq_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|)
block|{
comment|//CHECK-LABEL: test_vrndq_f64
return|return
name|vrndq_f64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: frintz v{{[0-9]+}}.2d, v{{[0-9]+}}.2d
block|}
end_function

begin_function
name|float32x2_t
name|test_vrndi_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
comment|//CHECK-LABEL: test_vrndi_f32
return|return
name|vrndi_f32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: frinti v{{[0-9]+}}.2s, v{{[0-9]+}}.2s
block|}
end_function

begin_function
name|float32x4_t
name|test_vrndiq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
comment|//CHECK-LABEL: test_vrndiq_f32
return|return
name|vrndiq_f32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: frinti v{{[0-9]+}}.4s, v{{[0-9]+}}.4s
block|}
end_function

begin_function
name|float64x2_t
name|test_vrndiq_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|)
block|{
comment|//CHECK-LABEL: test_vrndiq_f64
return|return
name|vrndiq_f64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: frinti v{{[0-9]+}}.2d, v{{[0-9]+}}.2d
block|}
end_function

begin_function
name|int32x2_t
name|test_vcvt_s32_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
comment|//CHECK-LABEL: test_vcvt_s32_f32
return|return
name|vcvt_s32_f32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: fcvtzs v{{[0-9]+}}.2s, v{{[0-9]+}}.2s
block|}
end_function

begin_function
name|int32x4_t
name|test_vcvtq_s32_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
comment|//CHECK-LABEL: test_vcvtq_s32_f32
return|return
name|vcvtq_s32_f32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: fcvtzs v{{[0-9]+}}.4s, v{{[0-9]+}}.4s
block|}
end_function

begin_function
name|int64x2_t
name|test_vcvtq_s64_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|)
block|{
comment|//CHECK-LABEL: test_vcvtq_s64_f64
return|return
name|vcvtq_s64_f64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: fcvtzs v{{[0-9]+}}.2d, v{{[0-9]+}}.2d
block|}
end_function

begin_function
name|uint32x2_t
name|test_vcvt_u32_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
comment|//CHECK-LABEL: test_vcvt_u32_f32
return|return
name|vcvt_u32_f32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: fcvtzu v{{[0-9]+}}.2s, v{{[0-9]+}}.2s
block|}
end_function

begin_function
name|uint32x4_t
name|test_vcvtq_u32_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
comment|//CHECK-LABEL: test_vcvtq_u32_f32
return|return
name|vcvtq_u32_f32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: fcvtzu v{{[0-9]+}}.4s, v{{[0-9]+}}.4s
block|}
end_function

begin_function
name|uint64x2_t
name|test_vcvtq_u64_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|)
block|{
comment|//CHECK-LABEL: test_vcvtq_u64_f64
return|return
name|vcvtq_u64_f64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: fcvtzu v{{[0-9]+}}.2d, v{{[0-9]+}}.2d
block|}
end_function

begin_function
name|int32x2_t
name|test_vcvtn_s32_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
comment|//CHECK-LABEL: test_vcvtn_s32_f32
return|return
name|vcvtn_s32_f32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: fcvtns v{{[0-9]+}}.2s, v{{[0-9]+}}.2s
block|}
end_function

begin_function
name|int32x4_t
name|test_vcvtnq_s32_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
comment|//CHECK-LABEL: test_vcvtnq_s32_f32
return|return
name|vcvtnq_s32_f32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: fcvtns v{{[0-9]+}}.4s, v{{[0-9]+}}.4s
block|}
end_function

begin_function
name|int64x2_t
name|test_vcvtnq_s64_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|)
block|{
comment|//CHECK-LABEL: test_vcvtnq_s64_f64
return|return
name|vcvtnq_s64_f64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: fcvtns v{{[0-9]+}}.2d, v{{[0-9]+}}.2d
block|}
end_function

begin_function
name|uint32x2_t
name|test_vcvtn_u32_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
comment|//CHECK-LABEL: test_vcvtn_u32_f32
return|return
name|vcvtn_u32_f32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: fcvtnu v{{[0-9]+}}.2s, v{{[0-9]+}}.2s
block|}
end_function

begin_function
name|uint32x4_t
name|test_vcvtnq_u32_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
comment|//CHECK-LABEL: test_vcvtnq_u32_f32
return|return
name|vcvtnq_u32_f32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: fcvtnu v{{[0-9]+}}.4s, v{{[0-9]+}}.4s
block|}
end_function

begin_function
name|uint64x2_t
name|test_vcvtnq_u64_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|)
block|{
comment|//CHECK-LABEL: test_vcvtnq_u64_f64
return|return
name|vcvtnq_u64_f64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: fcvtnu v{{[0-9]+}}.2d, v{{[0-9]+}}.2d
block|}
end_function

begin_function
name|int32x2_t
name|test_vcvtp_s32_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
comment|//CHECK-LABEL: test_vcvtp_s32_f32
return|return
name|vcvtp_s32_f32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: fcvtps v{{[0-9]+}}.2s, v{{[0-9]+}}.2s
block|}
end_function

begin_function
name|int32x4_t
name|test_vcvtpq_s32_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
comment|//CHECK-LABEL: test_vcvtpq_s32_f32
return|return
name|vcvtpq_s32_f32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: fcvtps v{{[0-9]+}}.4s, v{{[0-9]+}}.4s
block|}
end_function

begin_function
name|int64x2_t
name|test_vcvtpq_s64_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|)
block|{
comment|//CHECK-LABEL: test_vcvtpq_s64_f64
return|return
name|vcvtpq_s64_f64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: fcvtps v{{[0-9]+}}.2d, v{{[0-9]+}}.2d
block|}
end_function

begin_function
name|uint32x2_t
name|test_vcvtp_u32_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
comment|//CHECK-LABEL: test_vcvtp_u32_f32
return|return
name|vcvtp_u32_f32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: fcvtpu v{{[0-9]+}}.2s, v{{[0-9]+}}.2s
block|}
end_function

begin_function
name|uint32x4_t
name|test_vcvtpq_u32_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
comment|//CHECK-LABEL: test_vcvtpq_u32_f32
return|return
name|vcvtpq_u32_f32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: fcvtpu v{{[0-9]+}}.4s, v{{[0-9]+}}.4s
block|}
end_function

begin_function
name|uint64x2_t
name|test_vcvtpq_u64_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|)
block|{
comment|//CHECK-LABEL: test_vcvtpq_u64_f64
return|return
name|vcvtpq_u64_f64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: fcvtpu v{{[0-9]+}}.2d, v{{[0-9]+}}.2d
block|}
end_function

begin_function
name|int32x2_t
name|test_vcvtm_s32_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
comment|//CHECK-LABEL: test_vcvtm_s32_f32
return|return
name|vcvtm_s32_f32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: fcvtms v{{[0-9]+}}.2s, v{{[0-9]+}}.2s
block|}
end_function

begin_function
name|int32x4_t
name|test_vcvtmq_s32_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
comment|//CHECK-LABEL: test_vcvtmq_s32_f32
return|return
name|vcvtmq_s32_f32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: fcvtms v{{[0-9]+}}.4s, v{{[0-9]+}}.4s
block|}
end_function

begin_function
name|int64x2_t
name|test_vcvtmq_s64_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|)
block|{
comment|//CHECK-LABEL: test_vcvtmq_s64_f64
return|return
name|vcvtmq_s64_f64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: fcvtms v{{[0-9]+}}.2d, v{{[0-9]+}}.2d
block|}
end_function

begin_function
name|uint32x2_t
name|test_vcvtm_u32_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
comment|//CHECK-LABEL: test_vcvtm_u32_f32
return|return
name|vcvtm_u32_f32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: fcvtmu v{{[0-9]+}}.2s, v{{[0-9]+}}.2s
block|}
end_function

begin_function
name|uint32x4_t
name|test_vcvtmq_u32_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
comment|//CHECK-LABEL: test_vcvtmq_u32_f32
return|return
name|vcvtmq_u32_f32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: fcvtmu v{{[0-9]+}}.4s, v{{[0-9]+}}.4s
block|}
end_function

begin_function
name|uint64x2_t
name|test_vcvtmq_u64_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|)
block|{
comment|//CHECK-LABEL: test_vcvtmq_u64_f64
return|return
name|vcvtmq_u64_f64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: fcvtmu v{{[0-9]+}}.2d, v{{[0-9]+}}.2d
block|}
end_function

begin_function
name|int32x2_t
name|test_vcvta_s32_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
comment|//CHECK-LABEL: test_vcvta_s32_f32
return|return
name|vcvta_s32_f32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: fcvtas v{{[0-9]+}}.2s, v{{[0-9]+}}.2s
block|}
end_function

begin_function
name|int32x4_t
name|test_vcvtaq_s32_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
comment|//CHECK-LABEL: test_vcvtaq_s32_f32
return|return
name|vcvtaq_s32_f32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: fcvtas v{{[0-9]+}}.4s, v{{[0-9]+}}.4s
block|}
end_function

begin_function
name|int64x2_t
name|test_vcvtaq_s64_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|)
block|{
comment|//CHECK-LABEL: test_vcvtaq_s64_f64
return|return
name|vcvtaq_s64_f64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: fcvtas v{{[0-9]+}}.2d, v{{[0-9]+}}.2d
block|}
end_function

begin_function
name|uint32x2_t
name|test_vcvta_u32_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
comment|//CHECK-LABEL: test_vcvta_u32_f32
return|return
name|vcvta_u32_f32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: fcvtau v{{[0-9]+}}.2s, v{{[0-9]+}}.2s
block|}
end_function

begin_function
name|uint32x4_t
name|test_vcvtaq_u32_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
comment|//CHECK-LABEL: test_vcvtaq_u32_f32
return|return
name|vcvtaq_u32_f32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: fcvtau v{{[0-9]+}}.4s, v{{[0-9]+}}.4s
block|}
end_function

begin_function
name|uint64x2_t
name|test_vcvtaq_u64_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|)
block|{
comment|//CHECK-LABEL: test_vcvtaq_u64_f64
return|return
name|vcvtaq_u64_f64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: fcvtau v{{[0-9]+}}.2d, v{{[0-9]+}}.2d
block|}
end_function

begin_function
name|float32x2_t
name|test_vrsqrte_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
comment|//CHECK-LABEL: test_vrsqrte_f32
return|return
name|vrsqrte_f32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: frsqrte v{{[0-9]+}}.2s, v{{[0-9]+}}.2s
block|}
end_function

begin_function
name|float32x4_t
name|test_vrsqrteq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
comment|//CHECK-LABEL: test_vrsqrteq_f32
return|return
name|vrsqrteq_f32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: frsqrte v{{[0-9]+}}.4s, v{{[0-9]+}}.4s
block|}
end_function

begin_function
name|float64x2_t
name|test_vrsqrteq_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|)
block|{
comment|//CHECK-LABEL: test_vrsqrteq_f64
return|return
name|vrsqrteq_f64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: frsqrte v{{[0-9]+}}.2d, v{{[0-9]+}}.2d
block|}
end_function

begin_function
name|float32x2_t
name|test_vrecpe_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
comment|//CHECK-LABEL: test_vrecpe_f32
return|return
name|vrecpe_f32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: frecpe v{{[0-9]+}}.2s, v{{[0-9]+}}.2s
block|}
end_function

begin_function
name|float32x4_t
name|test_vrecpeq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
comment|//CHECK-LABEL: test_vrecpeq_f32
return|return
name|vrecpeq_f32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: frecpe v{{[0-9]+}}.4s, v{{[0-9]+}}.4s
block|}
end_function

begin_function
name|float64x2_t
name|test_vrecpeq_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|)
block|{
comment|//CHECK-LABEL: test_vrecpeq_f64
return|return
name|vrecpeq_f64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: frecpe v{{[0-9]+}}.2d, v{{[0-9]+}}.2d
block|}
end_function

begin_function
name|uint32x2_t
name|test_vrecpe_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|)
block|{
comment|//CHECK-LABEL: test_vrecpe_u32
return|return
name|vrecpe_u32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: urecpe v{{[0-9]+}}.2s, v{{[0-9]+}}.2s
block|}
end_function

begin_function
name|uint32x4_t
name|test_vrecpeq_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|)
block|{
comment|//CHECK-LABEL: test_vrecpeq_u32
return|return
name|vrecpeq_u32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: urecpe v{{[0-9]+}}.4s, v{{[0-9]+}}.4s
block|}
end_function

begin_function
name|float32x2_t
name|test_vsqrt_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
comment|//CHECK-LABEL: test_vsqrt_f32
return|return
name|vsqrt_f32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: fsqrt v{{[0-9]+}}.2s, v{{[0-9]+}}.2s
block|}
end_function

begin_function
name|float32x4_t
name|test_vsqrtq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
comment|//CHECK-LABEL: test_vsqrtq_f32
return|return
name|vsqrtq_f32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: fsqrt v{{[0-9]+}}.4s, v{{[0-9]+}}.4s
block|}
end_function

begin_function
name|float64x2_t
name|test_vsqrtq_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|)
block|{
comment|//CHECK-LABEL: test_vsqrtq_f64
return|return
name|vsqrtq_f64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: fsqrt v{{[0-9]+}}.2d, v{{[0-9]+}}.2d
block|}
end_function

begin_function
name|float32x2_t
name|test_vcvt_f32_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|)
block|{
comment|//CHECK-LABEL: test_vcvt_f32_s32
return|return
name|vcvt_f32_s32
argument_list|(
name|a
argument_list|)
return|;
comment|//CHECK: scvtf v{{[0-9]+}}.2s, v{{[0-9]+}}.2s
block|}
end_function

begin_function
name|float32x2_t
name|test_vcvt_f32_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|)
block|{
comment|//CHECK-LABEL: test_vcvt_f32_u32
return|return
name|vcvt_f32_u32
argument_list|(
name|a
argument_list|)
return|;
comment|//CHECK: ucvtf v{{[0-9]+}}.2s, v{{[0-9]+}}.2s
block|}
end_function

begin_function
name|float32x4_t
name|test_vcvtq_f32_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
comment|//CHECK-LABEL: test_vcvtq_f32_s32
return|return
name|vcvtq_f32_s32
argument_list|(
name|a
argument_list|)
return|;
comment|//CHECK: scvtf v{{[0-9]+}}.4s, v{{[0-9]+}}.4s
block|}
end_function

begin_function
name|float32x4_t
name|test_vcvtq_f32_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|)
block|{
comment|//CHECK-LABEL: test_vcvtq_f32_u32
return|return
name|vcvtq_f32_u32
argument_list|(
name|a
argument_list|)
return|;
comment|//CHECK: ucvtf v{{[0-9]+}}.4s, v{{[0-9]+}}.4s
block|}
end_function

begin_function
name|float64x2_t
name|test_vcvtq_f64_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|)
block|{
comment|//CHECK-LABEL: test_vcvtq_f64_s64
return|return
name|vcvtq_f64_s64
argument_list|(
name|a
argument_list|)
return|;
comment|//CHECK: scvtf v{{[0-9]+}}.2d, v{{[0-9]+}}.2d
block|}
end_function

begin_function
name|float64x2_t
name|test_vcvtq_f64_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|)
block|{
comment|//CHECK-LABEL: test_vcvtq_f64_u64
return|return
name|vcvtq_f64_u64
argument_list|(
name|a
argument_list|)
return|;
comment|//CHECK: ucvtf v{{[0-9]+}}.2d, v{{[0-9]+}}.2d
block|}
end_function

end_unit

