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
name|test_vext_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vext_s8
return|return
name|vext_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|2
argument_list|)
return|;
comment|// CHECK: ext {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, #{{(0x)?2}}
block|}
end_function

begin_function
name|int16x4_t
name|test_vext_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vext_s16
return|return
name|vext_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: ext {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, #{{(0x)?6}}
block|}
end_function

begin_function
name|int32x2_t
name|test_vext_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vext_s32
return|return
name|vext_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: ext {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, #{{(0x)?4}}
block|}
end_function

begin_function
name|int64x1_t
name|test_vext_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|,
name|int64x1_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vext_s64
return|return
name|vext_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|int8x16_t
name|test_vextq_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vextq_s8
return|return
name|vextq_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|2
argument_list|)
return|;
comment|// CHECK: ext {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, #{{(0x)?2}}
block|}
end_function

begin_function
name|int16x8_t
name|test_vextq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vextq_s16
return|return
name|vextq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: ext {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, #{{(0x)?6}}
block|}
end_function

begin_function
name|int32x4_t
name|test_vextq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vextq_s32
return|return
name|vextq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: ext {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, #{{(0x)?4}}
block|}
end_function

begin_function
name|int64x2_t
name|test_vextq_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vextq_s64
return|return
name|vextq_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: ext {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, #{{(0x)?8}}
block|}
end_function

begin_function
name|uint8x8_t
name|test_vext_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vext_u8
return|return
name|vext_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|2
argument_list|)
return|;
comment|// CHECK: ext {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, #{{(0x)?2}}
block|}
end_function

begin_function
name|uint16x4_t
name|test_vext_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vext_u16
return|return
name|vext_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: ext {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, #{{(0x)?6}}
block|}
end_function

begin_function
name|uint32x2_t
name|test_vext_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vext_u32
return|return
name|vext_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: ext {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, #{{(0x)?4}}
block|}
end_function

begin_function
name|uint64x1_t
name|test_vext_u64
parameter_list|(
name|uint64x1_t
name|a
parameter_list|,
name|uint64x1_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vext_u64
return|return
name|vext_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|uint8x16_t
name|test_vextq_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|,
name|uint8x16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vextq_u8
return|return
name|vextq_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|2
argument_list|)
return|;
comment|// CHECK: ext {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, #{{(0x)?2}}
block|}
end_function

begin_function
name|uint16x8_t
name|test_vextq_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vextq_u16
return|return
name|vextq_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: ext {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, #{{(0x)?6}}
block|}
end_function

begin_function
name|uint32x4_t
name|test_vextq_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vextq_u32
return|return
name|vextq_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: ext {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, #{{(0x)?4}}
block|}
end_function

begin_function
name|uint64x2_t
name|test_vextq_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|,
name|uint64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vextq_u64
return|return
name|vextq_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: ext {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, #{{(0x)?8}}
block|}
end_function

begin_function
name|float32x2_t
name|test_vext_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vext_f32
return|return
name|vext_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: ext {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, #{{(0x)?4}}
block|}
end_function

begin_function
name|float64x1_t
name|test_vext_f64
parameter_list|(
name|float64x1_t
name|a
parameter_list|,
name|float64x1_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vext_f64
return|return
name|vext_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|float32x4_t
name|test_vextq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|,
name|float32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vextq_f32
return|return
name|vextq_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: ext {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, #{{(0x)?4}}
block|}
end_function

begin_function
name|float64x2_t
name|test_vextq_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|,
name|float64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vextq_f64
return|return
name|vextq_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: ext {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, #{{(0x)?8}}
block|}
end_function

begin_function
name|poly8x8_t
name|test_vext_p8
parameter_list|(
name|poly8x8_t
name|a
parameter_list|,
name|poly8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vext_p8
return|return
name|vext_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|2
argument_list|)
return|;
comment|// CHECK: ext {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, #{{(0x)?2}}
block|}
end_function

begin_function
name|poly16x4_t
name|test_vext_p16
parameter_list|(
name|poly16x4_t
name|a
parameter_list|,
name|poly16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vext_p16
return|return
name|vext_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: ext {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, #{{(0x)?6}}
block|}
end_function

begin_function
name|poly8x16_t
name|test_vextq_p8
parameter_list|(
name|poly8x16_t
name|a
parameter_list|,
name|poly8x16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vextq_p8
return|return
name|vextq_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|2
argument_list|)
return|;
comment|// CHECK: ext {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, #{{(0x)?2}}
block|}
end_function

begin_function
name|poly16x8_t
name|test_vextq_p16
parameter_list|(
name|poly16x8_t
name|a
parameter_list|,
name|poly16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vextq_p16
return|return
name|vextq_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: ext {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, #{{(0x)?6}}
block|}
end_function

end_unit

