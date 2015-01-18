begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple thumbv7s-apple-darwin -target-abi apcs-gnu\
end_comment

begin_comment
comment|// RUN:  -target-cpu swift -ffreestanding -Os -S -o - %s\
end_comment

begin_comment
comment|// RUN:  | FileCheck %s --check-prefix=CHECK --check-prefix=CHECK-SWIFT
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple armv8-linux-gnu \
end_comment

begin_comment
comment|// RUN:  -target-cpu cortex-a57 -mfloat-abi soft -ffreestanding -Os -S -o - %s\
end_comment

begin_comment
comment|// RUN:  | FileCheck %s --check-prefix=CHECK --check-prefix=CHECK-A57
end_comment

begin_comment
comment|// REQUIRES: long_tests
end_comment

begin_include
include|#
directive|include
file|<arm_neon.h>
end_include

begin_comment
comment|// CHECK-LABEL: test_vaba_s8
end_comment

begin_comment
comment|// CHECK: vaba.s8 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int8x8_t
name|test_vaba_s8
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
return|return
name|vaba_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vaba_s16
end_comment

begin_comment
comment|// CHECK: vaba.s16 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int16x4_t
name|test_vaba_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|,
name|int16x4_t
name|c
parameter_list|)
block|{
return|return
name|vaba_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vaba_s32
end_comment

begin_comment
comment|// CHECK: vaba.s32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int32x2_t
name|test_vaba_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|,
name|int32x2_t
name|c
parameter_list|)
block|{
return|return
name|vaba_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vaba_u8
end_comment

begin_comment
comment|// CHECK: vaba.u8 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint8x8_t
name|test_vaba_u8
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
return|return
name|vaba_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vaba_u16
end_comment

begin_comment
comment|// CHECK: vaba.u16 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint16x4_t
name|test_vaba_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|,
name|uint16x4_t
name|c
parameter_list|)
block|{
return|return
name|vaba_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vaba_u32
end_comment

begin_comment
comment|// CHECK: vaba.u32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint32x2_t
name|test_vaba_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|,
name|uint32x2_t
name|c
parameter_list|)
block|{
return|return
name|vaba_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vabaq_s8
end_comment

begin_comment
comment|// CHECK: vaba.s8 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int8x16_t
name|test_vabaq_s8
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
return|return
name|vabaq_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vabaq_s16
end_comment

begin_comment
comment|// CHECK: vaba.s16 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int16x8_t
name|test_vabaq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|,
name|int16x8_t
name|c
parameter_list|)
block|{
return|return
name|vabaq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vabaq_s32
end_comment

begin_comment
comment|// CHECK: vaba.s32 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int32x4_t
name|test_vabaq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|,
name|int32x4_t
name|c
parameter_list|)
block|{
return|return
name|vabaq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vabaq_u8
end_comment

begin_comment
comment|// CHECK: vaba.u8 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint8x16_t
name|test_vabaq_u8
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
return|return
name|vabaq_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vabaq_u16
end_comment

begin_comment
comment|// CHECK: vaba.u16 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint16x8_t
name|test_vabaq_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|,
name|uint16x8_t
name|c
parameter_list|)
block|{
return|return
name|vabaq_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vabaq_u32
end_comment

begin_comment
comment|// CHECK: vaba.u32 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint32x4_t
name|test_vabaq_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|,
name|uint32x4_t
name|c
parameter_list|)
block|{
return|return
name|vabaq_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vabal_s8
end_comment

begin_comment
comment|// CHECK: vabal.s8 q{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int16x8_t
name|test_vabal_s8
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|,
name|int8x8_t
name|c
parameter_list|)
block|{
return|return
name|vabal_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vabal_s16
end_comment

begin_comment
comment|// CHECK: vabal.s16 q{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int32x4_t
name|test_vabal_s16
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|,
name|int16x4_t
name|c
parameter_list|)
block|{
return|return
name|vabal_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vabal_s32
end_comment

begin_comment
comment|// CHECK: vabal.s32 q{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int64x2_t
name|test_vabal_s32
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|,
name|int32x2_t
name|c
parameter_list|)
block|{
return|return
name|vabal_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vabal_u8
end_comment

begin_comment
comment|// CHECK: vabal.u8 q{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint16x8_t
name|test_vabal_u8
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|,
name|uint8x8_t
name|c
parameter_list|)
block|{
return|return
name|vabal_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vabal_u16
end_comment

begin_comment
comment|// CHECK: vabal.u16 q{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint32x4_t
name|test_vabal_u16
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|,
name|uint16x4_t
name|c
parameter_list|)
block|{
return|return
name|vabal_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vabal_u32
end_comment

begin_comment
comment|// CHECK: vabal.u32 q{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint64x2_t
name|test_vabal_u32
parameter_list|(
name|uint64x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|,
name|uint32x2_t
name|c
parameter_list|)
block|{
return|return
name|vabal_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vabd_s8
end_comment

begin_comment
comment|// CHECK: vabd.s8 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int8x8_t
name|test_vabd_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
return|return
name|vabd_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vabd_s16
end_comment

begin_comment
comment|// CHECK: vabd.s16 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int16x4_t
name|test_vabd_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
return|return
name|vabd_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vabd_s32
end_comment

begin_comment
comment|// CHECK: vabd.s32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int32x2_t
name|test_vabd_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
return|return
name|vabd_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vabd_u8
end_comment

begin_comment
comment|// CHECK: vabd.u8 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint8x8_t
name|test_vabd_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|)
block|{
return|return
name|vabd_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vabd_u16
end_comment

begin_comment
comment|// CHECK: vabd.u16 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint16x4_t
name|test_vabd_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|)
block|{
return|return
name|vabd_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vabd_u32
end_comment

begin_comment
comment|// CHECK: vabd.u32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint32x2_t
name|test_vabd_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|)
block|{
return|return
name|vabd_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vabd_f32
end_comment

begin_comment
comment|// CHECK: vabd.f32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|float32x2_t
name|test_vabd_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32x2_t
name|b
parameter_list|)
block|{
return|return
name|vabd_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vabdq_s8
end_comment

begin_comment
comment|// CHECK: vabd.s8 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int8x16_t
name|test_vabdq_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|)
block|{
return|return
name|vabdq_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vabdq_s16
end_comment

begin_comment
comment|// CHECK: vabd.s16 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int16x8_t
name|test_vabdq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
return|return
name|vabdq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vabdq_s32
end_comment

begin_comment
comment|// CHECK: vabd.s32 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int32x4_t
name|test_vabdq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
return|return
name|vabdq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vabdq_u8
end_comment

begin_comment
comment|// CHECK: vabd.u8 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint8x16_t
name|test_vabdq_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|,
name|uint8x16_t
name|b
parameter_list|)
block|{
return|return
name|vabdq_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vabdq_u16
end_comment

begin_comment
comment|// CHECK: vabd.u16 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint16x8_t
name|test_vabdq_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|)
block|{
return|return
name|vabdq_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vabdq_u32
end_comment

begin_comment
comment|// CHECK: vabd.u32 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint32x4_t
name|test_vabdq_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|)
block|{
return|return
name|vabdq_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vabdq_f32
end_comment

begin_comment
comment|// CHECK: vabd.f32 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|float32x4_t
name|test_vabdq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|,
name|float32x4_t
name|b
parameter_list|)
block|{
return|return
name|vabdq_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vabdl_s8
end_comment

begin_comment
comment|// CHECK: vabdl.s8 q{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int16x8_t
name|test_vabdl_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
return|return
name|vabdl_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vabdl_s16
end_comment

begin_comment
comment|// CHECK: vabdl.s16 q{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int32x4_t
name|test_vabdl_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
return|return
name|vabdl_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vabdl_s32
end_comment

begin_comment
comment|// CHECK: vabdl.s32 q{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int64x2_t
name|test_vabdl_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
return|return
name|vabdl_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vabdl_u8
end_comment

begin_comment
comment|// CHECK: vabdl.u8 q{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint16x8_t
name|test_vabdl_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|)
block|{
return|return
name|vabdl_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vabdl_u16
end_comment

begin_comment
comment|// CHECK: vabdl.u16 q{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint32x4_t
name|test_vabdl_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|)
block|{
return|return
name|vabdl_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vabdl_u32
end_comment

begin_comment
comment|// CHECK: vabdl.u32 q{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint64x2_t
name|test_vabdl_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|)
block|{
return|return
name|vabdl_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vabs_s8
end_comment

begin_comment
comment|// CHECK: vabs.s8 d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int8x8_t
name|test_vabs_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
return|return
name|vabs_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vabs_s16
end_comment

begin_comment
comment|// CHECK: vabs.s16 d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int16x4_t
name|test_vabs_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|)
block|{
return|return
name|vabs_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vabs_s32
end_comment

begin_comment
comment|// CHECK: vabs.s32 d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int32x2_t
name|test_vabs_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|)
block|{
return|return
name|vabs_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vabs_f32
end_comment

begin_comment
comment|// CHECK: vabs.f32 d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|float32x2_t
name|test_vabs_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
return|return
name|vabs_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vabsq_s8
end_comment

begin_comment
comment|// CHECK: vabs.s8 q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int8x16_t
name|test_vabsq_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
return|return
name|vabsq_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vabsq_s16
end_comment

begin_comment
comment|// CHECK: vabs.s16 q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int16x8_t
name|test_vabsq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
return|return
name|vabsq_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vabsq_s32
end_comment

begin_comment
comment|// CHECK: vabs.s32 q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int32x4_t
name|test_vabsq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
return|return
name|vabsq_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vabsq_f32
end_comment

begin_comment
comment|// CHECK: vabs.f32 q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|float32x4_t
name|test_vabsq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
return|return
name|vabsq_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vadd_s8
end_comment

begin_comment
comment|// CHECK: vadd.i8 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int8x8_t
name|test_vadd_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
return|return
name|vadd_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vadd_s16
end_comment

begin_comment
comment|// CHECK: vadd.i16 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int16x4_t
name|test_vadd_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
return|return
name|vadd_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vadd_s32
end_comment

begin_comment
comment|// CHECK: vadd.i32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int32x2_t
name|test_vadd_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
return|return
name|vadd_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vadd_s64
end_comment

begin_comment
comment|// CHECK: vadd.i64 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int64x1_t
name|test_vadd_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|,
name|int64x1_t
name|b
parameter_list|)
block|{
return|return
name|vadd_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vadd_f32
end_comment

begin_comment
comment|// CHECK: vadd.f32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|float32x2_t
name|test_vadd_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32x2_t
name|b
parameter_list|)
block|{
return|return
name|vadd_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vadd_u8
end_comment

begin_comment
comment|// CHECK: vadd.i8 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint8x8_t
name|test_vadd_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|)
block|{
return|return
name|vadd_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vadd_u16
end_comment

begin_comment
comment|// CHECK: vadd.i16 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint16x4_t
name|test_vadd_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|)
block|{
return|return
name|vadd_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vadd_u32
end_comment

begin_comment
comment|// CHECK: vadd.i32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint32x2_t
name|test_vadd_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|)
block|{
return|return
name|vadd_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vadd_u64
end_comment

begin_comment
comment|// CHECK: vadd.i64 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint64x1_t
name|test_vadd_u64
parameter_list|(
name|uint64x1_t
name|a
parameter_list|,
name|uint64x1_t
name|b
parameter_list|)
block|{
return|return
name|vadd_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vaddq_s8
end_comment

begin_comment
comment|// CHECK: vadd.i8 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int8x16_t
name|test_vaddq_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|)
block|{
return|return
name|vaddq_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vaddq_s16
end_comment

begin_comment
comment|// CHECK: vadd.i16 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int16x8_t
name|test_vaddq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
return|return
name|vaddq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vaddq_s32
end_comment

begin_comment
comment|// CHECK: vadd.i32 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int32x4_t
name|test_vaddq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
return|return
name|vaddq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vaddq_s64
end_comment

begin_comment
comment|// CHECK: vadd.i64 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int64x2_t
name|test_vaddq_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int64x2_t
name|b
parameter_list|)
block|{
return|return
name|vaddq_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vaddq_f32
end_comment

begin_comment
comment|// CHECK: vadd.f32 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|float32x4_t
name|test_vaddq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|,
name|float32x4_t
name|b
parameter_list|)
block|{
return|return
name|vaddq_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vaddq_u8
end_comment

begin_comment
comment|// CHECK: vadd.i8 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint8x16_t
name|test_vaddq_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|,
name|uint8x16_t
name|b
parameter_list|)
block|{
return|return
name|vaddq_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vaddq_u16
end_comment

begin_comment
comment|// CHECK: vadd.i16 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint16x8_t
name|test_vaddq_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|)
block|{
return|return
name|vaddq_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vaddq_u32
end_comment

begin_comment
comment|// CHECK: vadd.i32 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint32x4_t
name|test_vaddq_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|)
block|{
return|return
name|vaddq_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vaddq_u64
end_comment

begin_comment
comment|// CHECK: vadd.i64 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint64x2_t
name|test_vaddq_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|,
name|uint64x2_t
name|b
parameter_list|)
block|{
return|return
name|vaddq_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vaddhn_s16
end_comment

begin_comment
comment|// CHECK: vaddhn.i16 d{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int8x8_t
name|test_vaddhn_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
return|return
name|vaddhn_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vaddhn_s32
end_comment

begin_comment
comment|// CHECK: vaddhn.i32 d{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int16x4_t
name|test_vaddhn_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
return|return
name|vaddhn_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vaddhn_s64
end_comment

begin_comment
comment|// CHECK: vaddhn.i64 d{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int32x2_t
name|test_vaddhn_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int64x2_t
name|b
parameter_list|)
block|{
return|return
name|vaddhn_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vaddhn_u16
end_comment

begin_comment
comment|// CHECK: vaddhn.i16 d{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint8x8_t
name|test_vaddhn_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|)
block|{
return|return
name|vaddhn_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vaddhn_u32
end_comment

begin_comment
comment|// CHECK: vaddhn.i32 d{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint16x4_t
name|test_vaddhn_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|)
block|{
return|return
name|vaddhn_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vaddhn_u64
end_comment

begin_comment
comment|// CHECK: vaddhn.i64 d{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint32x2_t
name|test_vaddhn_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|,
name|uint64x2_t
name|b
parameter_list|)
block|{
return|return
name|vaddhn_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vaddl_s8
end_comment

begin_comment
comment|// CHECK: vaddl.s8 q{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int16x8_t
name|test_vaddl_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
return|return
name|vaddl_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vaddl_s16
end_comment

begin_comment
comment|// CHECK: vaddl.s16 q{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int32x4_t
name|test_vaddl_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
return|return
name|vaddl_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vaddl_s32
end_comment

begin_comment
comment|// CHECK: vaddl.s32 q{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int64x2_t
name|test_vaddl_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
return|return
name|vaddl_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vaddl_u8
end_comment

begin_comment
comment|// CHECK: vaddl.u8 q{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint16x8_t
name|test_vaddl_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|)
block|{
return|return
name|vaddl_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vaddl_u16
end_comment

begin_comment
comment|// CHECK: vaddl.u16 q{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint32x4_t
name|test_vaddl_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|)
block|{
return|return
name|vaddl_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vaddl_u32
end_comment

begin_comment
comment|// CHECK: vaddl.u32 q{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint64x2_t
name|test_vaddl_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|)
block|{
return|return
name|vaddl_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vaddw_s8
end_comment

begin_comment
comment|// CHECK: vaddw.s8 q{{[0-9]+}}, q{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int16x8_t
name|test_vaddw_s8
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
return|return
name|vaddw_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vaddw_s16
end_comment

begin_comment
comment|// CHECK: vaddw.s16 q{{[0-9]+}}, q{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int32x4_t
name|test_vaddw_s16
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
return|return
name|vaddw_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vaddw_s32
end_comment

begin_comment
comment|// CHECK: vaddw.s32 q{{[0-9]+}}, q{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int64x2_t
name|test_vaddw_s32
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
return|return
name|vaddw_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vaddw_u8
end_comment

begin_comment
comment|// CHECK: vaddw.u8 q{{[0-9]+}}, q{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint16x8_t
name|test_vaddw_u8
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|)
block|{
return|return
name|vaddw_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vaddw_u16
end_comment

begin_comment
comment|// CHECK: vaddw.u16 q{{[0-9]+}}, q{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint32x4_t
name|test_vaddw_u16
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|)
block|{
return|return
name|vaddw_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vaddw_u32
end_comment

begin_comment
comment|// CHECK: vaddw.u32 q{{[0-9]+}}, q{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint64x2_t
name|test_vaddw_u32
parameter_list|(
name|uint64x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|)
block|{
return|return
name|vaddw_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vand_s8
end_comment

begin_comment
comment|// CHECK: vand d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int8x8_t
name|test_vand_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
return|return
name|vand_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vand_s16
end_comment

begin_comment
comment|// CHECK: vand d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int16x4_t
name|test_vand_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
return|return
name|vand_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vand_s32
end_comment

begin_comment
comment|// CHECK: vand d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int32x2_t
name|test_vand_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
return|return
name|vand_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vand_s64
end_comment

begin_comment
comment|// CHECK: vand d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int64x1_t
name|test_vand_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|,
name|int64x1_t
name|b
parameter_list|)
block|{
return|return
name|vand_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vand_u8
end_comment

begin_comment
comment|// CHECK: vand d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint8x8_t
name|test_vand_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|)
block|{
return|return
name|vand_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vand_u16
end_comment

begin_comment
comment|// CHECK: vand d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint16x4_t
name|test_vand_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|)
block|{
return|return
name|vand_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vand_u32
end_comment

begin_comment
comment|// CHECK: vand d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint32x2_t
name|test_vand_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|)
block|{
return|return
name|vand_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vand_u64
end_comment

begin_comment
comment|// CHECK: vand d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint64x1_t
name|test_vand_u64
parameter_list|(
name|uint64x1_t
name|a
parameter_list|,
name|uint64x1_t
name|b
parameter_list|)
block|{
return|return
name|vand_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vandq_s8
end_comment

begin_comment
comment|// CHECK: vand q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int8x16_t
name|test_vandq_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|)
block|{
return|return
name|vandq_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vandq_s16
end_comment

begin_comment
comment|// CHECK: vand q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int16x8_t
name|test_vandq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
return|return
name|vandq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vandq_s32
end_comment

begin_comment
comment|// CHECK: vand q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int32x4_t
name|test_vandq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
return|return
name|vandq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vandq_s64
end_comment

begin_comment
comment|// CHECK: vand q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int64x2_t
name|test_vandq_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int64x2_t
name|b
parameter_list|)
block|{
return|return
name|vandq_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vandq_u8
end_comment

begin_comment
comment|// CHECK: vand q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint8x16_t
name|test_vandq_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|,
name|uint8x16_t
name|b
parameter_list|)
block|{
return|return
name|vandq_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vandq_u16
end_comment

begin_comment
comment|// CHECK: vand q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint16x8_t
name|test_vandq_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|)
block|{
return|return
name|vandq_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vandq_u32
end_comment

begin_comment
comment|// CHECK: vand q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint32x4_t
name|test_vandq_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|)
block|{
return|return
name|vandq_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vandq_u64
end_comment

begin_comment
comment|// CHECK: vand q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint64x2_t
name|test_vandq_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|,
name|uint64x2_t
name|b
parameter_list|)
block|{
return|return
name|vandq_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vbic_s8
end_comment

begin_comment
comment|// CHECK: vbic d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int8x8_t
name|test_vbic_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
return|return
name|vbic_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vbic_s16
end_comment

begin_comment
comment|// CHECK: vbic d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int16x4_t
name|test_vbic_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
return|return
name|vbic_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vbic_s32
end_comment

begin_comment
comment|// CHECK: vbic d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int32x2_t
name|test_vbic_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
return|return
name|vbic_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vbic_s64
end_comment

begin_comment
comment|// CHECK: vbic d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int64x1_t
name|test_vbic_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|,
name|int64x1_t
name|b
parameter_list|)
block|{
return|return
name|vbic_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vbic_u8
end_comment

begin_comment
comment|// CHECK: vbic d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint8x8_t
name|test_vbic_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|)
block|{
return|return
name|vbic_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vbic_u16
end_comment

begin_comment
comment|// CHECK: vbic d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint16x4_t
name|test_vbic_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|)
block|{
return|return
name|vbic_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vbic_u32
end_comment

begin_comment
comment|// CHECK: vbic d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint32x2_t
name|test_vbic_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|)
block|{
return|return
name|vbic_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vbic_u64
end_comment

begin_comment
comment|// CHECK: vbic d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint64x1_t
name|test_vbic_u64
parameter_list|(
name|uint64x1_t
name|a
parameter_list|,
name|uint64x1_t
name|b
parameter_list|)
block|{
return|return
name|vbic_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vbicq_s8
end_comment

begin_comment
comment|// CHECK: vbic q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int8x16_t
name|test_vbicq_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|)
block|{
return|return
name|vbicq_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vbicq_s16
end_comment

begin_comment
comment|// CHECK: vbic q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int16x8_t
name|test_vbicq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
return|return
name|vbicq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vbicq_s32
end_comment

begin_comment
comment|// CHECK: vbic q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int32x4_t
name|test_vbicq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
return|return
name|vbicq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vbicq_s64
end_comment

begin_comment
comment|// CHECK: vbic q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int64x2_t
name|test_vbicq_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int64x2_t
name|b
parameter_list|)
block|{
return|return
name|vbicq_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vbicq_u8
end_comment

begin_comment
comment|// CHECK: vbic q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint8x16_t
name|test_vbicq_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|,
name|uint8x16_t
name|b
parameter_list|)
block|{
return|return
name|vbicq_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vbicq_u16
end_comment

begin_comment
comment|// CHECK: vbic q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint16x8_t
name|test_vbicq_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|)
block|{
return|return
name|vbicq_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vbicq_u32
end_comment

begin_comment
comment|// CHECK: vbic q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint32x4_t
name|test_vbicq_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|)
block|{
return|return
name|vbicq_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vbicq_u64
end_comment

begin_comment
comment|// CHECK: vbic q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint64x2_t
name|test_vbicq_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|,
name|uint64x2_t
name|b
parameter_list|)
block|{
return|return
name|vbicq_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vbsl_s8
end_comment

begin_comment
comment|// CHECK: vbsl d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int8x8_t
name|test_vbsl_s8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|,
name|int8x8_t
name|c
parameter_list|)
block|{
return|return
name|vbsl_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vbsl_s16
end_comment

begin_comment
comment|// CHECK: vbsl d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int16x4_t
name|test_vbsl_s16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|,
name|int16x4_t
name|c
parameter_list|)
block|{
return|return
name|vbsl_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vbsl_s32
end_comment

begin_comment
comment|// CHECK: vbsl d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int32x2_t
name|test_vbsl_s32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|,
name|int32x2_t
name|c
parameter_list|)
block|{
return|return
name|vbsl_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vbsl_s64
end_comment

begin_comment
comment|// CHECK: vbsl d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int64x1_t
name|test_vbsl_s64
parameter_list|(
name|uint64x1_t
name|a
parameter_list|,
name|int64x1_t
name|b
parameter_list|,
name|int64x1_t
name|c
parameter_list|)
block|{
return|return
name|vbsl_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vbsl_u8
end_comment

begin_comment
comment|// CHECK: vbsl d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint8x8_t
name|test_vbsl_u8
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
return|return
name|vbsl_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vbsl_u16
end_comment

begin_comment
comment|// CHECK: vbsl d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint16x4_t
name|test_vbsl_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|,
name|uint16x4_t
name|c
parameter_list|)
block|{
return|return
name|vbsl_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vbsl_u32
end_comment

begin_comment
comment|// CHECK: vbsl d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint32x2_t
name|test_vbsl_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|,
name|uint32x2_t
name|c
parameter_list|)
block|{
return|return
name|vbsl_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vbsl_u64
end_comment

begin_comment
comment|// CHECK: vbsl d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint64x1_t
name|test_vbsl_u64
parameter_list|(
name|uint64x1_t
name|a
parameter_list|,
name|uint64x1_t
name|b
parameter_list|,
name|uint64x1_t
name|c
parameter_list|)
block|{
return|return
name|vbsl_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vbsl_f32
end_comment

begin_comment
comment|// CHECK: vbsl d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|float32x2_t
name|test_vbsl_f32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|float32x2_t
name|b
parameter_list|,
name|float32x2_t
name|c
parameter_list|)
block|{
return|return
name|vbsl_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vbsl_p8
end_comment

begin_comment
comment|// CHECK: vbsl d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|poly8x8_t
name|test_vbsl_p8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|,
name|poly8x8_t
name|b
parameter_list|,
name|poly8x8_t
name|c
parameter_list|)
block|{
return|return
name|vbsl_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vbsl_p16
end_comment

begin_comment
comment|// CHECK: vbsl d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|poly16x4_t
name|test_vbsl_p16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|poly16x4_t
name|b
parameter_list|,
name|poly16x4_t
name|c
parameter_list|)
block|{
return|return
name|vbsl_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vbslq_s8
end_comment

begin_comment
comment|// CHECK: vbsl q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int8x16_t
name|test_vbslq_s8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|,
name|int8x16_t
name|c
parameter_list|)
block|{
return|return
name|vbslq_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vbslq_s16
end_comment

begin_comment
comment|// CHECK: vbsl q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int16x8_t
name|test_vbslq_s16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|,
name|int16x8_t
name|c
parameter_list|)
block|{
return|return
name|vbslq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vbslq_s32
end_comment

begin_comment
comment|// CHECK: vbsl q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int32x4_t
name|test_vbslq_s32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|,
name|int32x4_t
name|c
parameter_list|)
block|{
return|return
name|vbslq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vbslq_s64
end_comment

begin_comment
comment|// CHECK: vbsl q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int64x2_t
name|test_vbslq_s64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|,
name|int64x2_t
name|b
parameter_list|,
name|int64x2_t
name|c
parameter_list|)
block|{
return|return
name|vbslq_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vbslq_u8
end_comment

begin_comment
comment|// CHECK: vbsl q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint8x16_t
name|test_vbslq_u8
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
return|return
name|vbslq_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vbslq_u16
end_comment

begin_comment
comment|// CHECK: vbsl q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint16x8_t
name|test_vbslq_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|,
name|uint16x8_t
name|c
parameter_list|)
block|{
return|return
name|vbslq_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vbslq_u32
end_comment

begin_comment
comment|// CHECK: vbsl q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint32x4_t
name|test_vbslq_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|,
name|uint32x4_t
name|c
parameter_list|)
block|{
return|return
name|vbslq_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vbslq_u64
end_comment

begin_comment
comment|// CHECK: vbsl q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint64x2_t
name|test_vbslq_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|,
name|uint64x2_t
name|b
parameter_list|,
name|uint64x2_t
name|c
parameter_list|)
block|{
return|return
name|vbslq_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vbslq_f32
end_comment

begin_comment
comment|// CHECK: vbsl q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|float32x4_t
name|test_vbslq_f32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|float32x4_t
name|b
parameter_list|,
name|float32x4_t
name|c
parameter_list|)
block|{
return|return
name|vbslq_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vbslq_p8
end_comment

begin_comment
comment|// CHECK: vbsl q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|poly8x16_t
name|test_vbslq_p8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|,
name|poly8x16_t
name|b
parameter_list|,
name|poly8x16_t
name|c
parameter_list|)
block|{
return|return
name|vbslq_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vbslq_p16
end_comment

begin_comment
comment|// CHECK: vbsl q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|poly16x8_t
name|test_vbslq_p16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|poly16x8_t
name|b
parameter_list|,
name|poly16x8_t
name|c
parameter_list|)
block|{
return|return
name|vbslq_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcage_f32
end_comment

begin_comment
comment|// CHECK: vacge.f32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint32x2_t
name|test_vcage_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32x2_t
name|b
parameter_list|)
block|{
return|return
name|vcage_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcageq_f32
end_comment

begin_comment
comment|// CHECK: vacge.f32 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint32x4_t
name|test_vcageq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|,
name|float32x4_t
name|b
parameter_list|)
block|{
return|return
name|vcageq_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcagt_f32
end_comment

begin_comment
comment|// CHECK: vacgt.f32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint32x2_t
name|test_vcagt_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32x2_t
name|b
parameter_list|)
block|{
return|return
name|vcagt_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcagtq_f32
end_comment

begin_comment
comment|// CHECK: vacgt.f32 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint32x4_t
name|test_vcagtq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|,
name|float32x4_t
name|b
parameter_list|)
block|{
return|return
name|vcagtq_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcale_f32
end_comment

begin_comment
comment|// CHECK: vacge.f32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint32x2_t
name|test_vcale_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32x2_t
name|b
parameter_list|)
block|{
return|return
name|vcale_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcaleq_f32
end_comment

begin_comment
comment|// CHECK: vacge.f32 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint32x4_t
name|test_vcaleq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|,
name|float32x4_t
name|b
parameter_list|)
block|{
return|return
name|vcaleq_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcalt_f32
end_comment

begin_comment
comment|// CHECK: vacgt.f32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint32x2_t
name|test_vcalt_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32x2_t
name|b
parameter_list|)
block|{
return|return
name|vcalt_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcaltq_f32
end_comment

begin_comment
comment|// CHECK: vacgt.f32 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint32x4_t
name|test_vcaltq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|,
name|float32x4_t
name|b
parameter_list|)
block|{
return|return
name|vcaltq_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vceq_s8
end_comment

begin_comment
comment|// CHECK: vceq.i8 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint8x8_t
name|test_vceq_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
return|return
name|vceq_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vceq_s16
end_comment

begin_comment
comment|// CHECK: vceq.i16 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint16x4_t
name|test_vceq_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
return|return
name|vceq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vceq_s32
end_comment

begin_comment
comment|// CHECK: vceq.i32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint32x2_t
name|test_vceq_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
return|return
name|vceq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vceq_f32
end_comment

begin_comment
comment|// CHECK: vceq.f32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint32x2_t
name|test_vceq_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32x2_t
name|b
parameter_list|)
block|{
return|return
name|vceq_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vceq_u8
end_comment

begin_comment
comment|// CHECK: vceq.i8 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint8x8_t
name|test_vceq_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|)
block|{
return|return
name|vceq_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vceq_u16
end_comment

begin_comment
comment|// CHECK: vceq.i16 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint16x4_t
name|test_vceq_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|)
block|{
return|return
name|vceq_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vceq_u32
end_comment

begin_comment
comment|// CHECK: vceq.i32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint32x2_t
name|test_vceq_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|)
block|{
return|return
name|vceq_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vceq_p8
end_comment

begin_comment
comment|// CHECK: vceq.i8 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint8x8_t
name|test_vceq_p8
parameter_list|(
name|poly8x8_t
name|a
parameter_list|,
name|poly8x8_t
name|b
parameter_list|)
block|{
return|return
name|vceq_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vceqq_s8
end_comment

begin_comment
comment|// CHECK: vceq.i8 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint8x16_t
name|test_vceqq_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|)
block|{
return|return
name|vceqq_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vceqq_s16
end_comment

begin_comment
comment|// CHECK: vceq.i16 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint16x8_t
name|test_vceqq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
return|return
name|vceqq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vceqq_s32
end_comment

begin_comment
comment|// CHECK: vceq.i32 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint32x4_t
name|test_vceqq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
return|return
name|vceqq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vceqq_f32
end_comment

begin_comment
comment|// CHECK: vceq.f32 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint32x4_t
name|test_vceqq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|,
name|float32x4_t
name|b
parameter_list|)
block|{
return|return
name|vceqq_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vceqq_u8
end_comment

begin_comment
comment|// CHECK: vceq.i8 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint8x16_t
name|test_vceqq_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|,
name|uint8x16_t
name|b
parameter_list|)
block|{
return|return
name|vceqq_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vceqq_u16
end_comment

begin_comment
comment|// CHECK: vceq.i16 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint16x8_t
name|test_vceqq_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|)
block|{
return|return
name|vceqq_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vceqq_u32
end_comment

begin_comment
comment|// CHECK: vceq.i32 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint32x4_t
name|test_vceqq_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|)
block|{
return|return
name|vceqq_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vceqq_p8
end_comment

begin_comment
comment|// CHECK: vceq.i8 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint8x16_t
name|test_vceqq_p8
parameter_list|(
name|poly8x16_t
name|a
parameter_list|,
name|poly8x16_t
name|b
parameter_list|)
block|{
return|return
name|vceqq_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcge_s8
end_comment

begin_comment
comment|// CHECK: vcge.s8 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint8x8_t
name|test_vcge_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
return|return
name|vcge_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcge_s16
end_comment

begin_comment
comment|// CHECK: vcge.s16 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint16x4_t
name|test_vcge_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
return|return
name|vcge_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcge_s32
end_comment

begin_comment
comment|// CHECK: vcge.s32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint32x2_t
name|test_vcge_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
return|return
name|vcge_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcge_f32
end_comment

begin_comment
comment|// CHECK: vcge.f32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint32x2_t
name|test_vcge_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32x2_t
name|b
parameter_list|)
block|{
return|return
name|vcge_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcge_u8
end_comment

begin_comment
comment|// CHECK: vcge.u8 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint8x8_t
name|test_vcge_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|)
block|{
return|return
name|vcge_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcge_u16
end_comment

begin_comment
comment|// CHECK: vcge.u16 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint16x4_t
name|test_vcge_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|)
block|{
return|return
name|vcge_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcge_u32
end_comment

begin_comment
comment|// CHECK: vcge.u32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint32x2_t
name|test_vcge_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|)
block|{
return|return
name|vcge_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcgeq_s8
end_comment

begin_comment
comment|// CHECK: vcge.s8 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint8x16_t
name|test_vcgeq_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|)
block|{
return|return
name|vcgeq_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcgeq_s16
end_comment

begin_comment
comment|// CHECK: vcge.s16 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint16x8_t
name|test_vcgeq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
return|return
name|vcgeq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcgeq_s32
end_comment

begin_comment
comment|// CHECK: vcge.s32 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint32x4_t
name|test_vcgeq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
return|return
name|vcgeq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcgeq_f32
end_comment

begin_comment
comment|// CHECK: vcge.f32 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint32x4_t
name|test_vcgeq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|,
name|float32x4_t
name|b
parameter_list|)
block|{
return|return
name|vcgeq_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcgeq_u8
end_comment

begin_comment
comment|// CHECK: vcge.u8 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint8x16_t
name|test_vcgeq_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|,
name|uint8x16_t
name|b
parameter_list|)
block|{
return|return
name|vcgeq_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcgeq_u16
end_comment

begin_comment
comment|// CHECK: vcge.u16 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint16x8_t
name|test_vcgeq_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|)
block|{
return|return
name|vcgeq_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcgeq_u32
end_comment

begin_comment
comment|// CHECK: vcge.u32 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint32x4_t
name|test_vcgeq_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|)
block|{
return|return
name|vcgeq_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcgt_s8
end_comment

begin_comment
comment|// CHECK: vcgt.s8 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint8x8_t
name|test_vcgt_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
return|return
name|vcgt_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcgt_s16
end_comment

begin_comment
comment|// CHECK: vcgt.s16 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint16x4_t
name|test_vcgt_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
return|return
name|vcgt_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcgt_s32
end_comment

begin_comment
comment|// CHECK: vcgt.s32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint32x2_t
name|test_vcgt_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
return|return
name|vcgt_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcgt_f32
end_comment

begin_comment
comment|// CHECK: vcgt.f32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint32x2_t
name|test_vcgt_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32x2_t
name|b
parameter_list|)
block|{
return|return
name|vcgt_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcgt_u8
end_comment

begin_comment
comment|// CHECK: vcgt.u8 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint8x8_t
name|test_vcgt_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|)
block|{
return|return
name|vcgt_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcgt_u16
end_comment

begin_comment
comment|// CHECK: vcgt.u16 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint16x4_t
name|test_vcgt_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|)
block|{
return|return
name|vcgt_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcgt_u32
end_comment

begin_comment
comment|// CHECK: vcgt.u32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint32x2_t
name|test_vcgt_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|)
block|{
return|return
name|vcgt_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcgtq_s8
end_comment

begin_comment
comment|// CHECK: vcgt.s8 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint8x16_t
name|test_vcgtq_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|)
block|{
return|return
name|vcgtq_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcgtq_s16
end_comment

begin_comment
comment|// CHECK: vcgt.s16 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint16x8_t
name|test_vcgtq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
return|return
name|vcgtq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcgtq_s32
end_comment

begin_comment
comment|// CHECK: vcgt.s32 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint32x4_t
name|test_vcgtq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
return|return
name|vcgtq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcgtq_f32
end_comment

begin_comment
comment|// CHECK: vcgt.f32 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint32x4_t
name|test_vcgtq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|,
name|float32x4_t
name|b
parameter_list|)
block|{
return|return
name|vcgtq_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcgtq_u8
end_comment

begin_comment
comment|// CHECK: vcgt.u8 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint8x16_t
name|test_vcgtq_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|,
name|uint8x16_t
name|b
parameter_list|)
block|{
return|return
name|vcgtq_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcgtq_u16
end_comment

begin_comment
comment|// CHECK: vcgt.u16 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint16x8_t
name|test_vcgtq_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|)
block|{
return|return
name|vcgtq_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcgtq_u32
end_comment

begin_comment
comment|// CHECK: vcgt.u32 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint32x4_t
name|test_vcgtq_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|)
block|{
return|return
name|vcgtq_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcle_s8
end_comment

begin_comment
comment|// CHECK: vcge.s8 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint8x8_t
name|test_vcle_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
return|return
name|vcle_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcle_s16
end_comment

begin_comment
comment|// CHECK: vcge.s16 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint16x4_t
name|test_vcle_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
return|return
name|vcle_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcle_s32
end_comment

begin_comment
comment|// CHECK: vcge.s32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint32x2_t
name|test_vcle_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
return|return
name|vcle_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcle_f32
end_comment

begin_comment
comment|// CHECK: vcge.f32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint32x2_t
name|test_vcle_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32x2_t
name|b
parameter_list|)
block|{
return|return
name|vcle_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcle_u8
end_comment

begin_comment
comment|// CHECK: vcge.u8 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint8x8_t
name|test_vcle_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|)
block|{
return|return
name|vcle_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcle_u16
end_comment

begin_comment
comment|// CHECK: vcge.u16 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint16x4_t
name|test_vcle_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|)
block|{
return|return
name|vcle_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcle_u32
end_comment

begin_comment
comment|// CHECK: vcge.u32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint32x2_t
name|test_vcle_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|)
block|{
return|return
name|vcle_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcleq_s8
end_comment

begin_comment
comment|// CHECK: vcge.s8 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint8x16_t
name|test_vcleq_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|)
block|{
return|return
name|vcleq_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcleq_s16
end_comment

begin_comment
comment|// CHECK: vcge.s16 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint16x8_t
name|test_vcleq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
return|return
name|vcleq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcleq_s32
end_comment

begin_comment
comment|// CHECK: vcge.s32 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint32x4_t
name|test_vcleq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
return|return
name|vcleq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcleq_f32
end_comment

begin_comment
comment|// CHECK: vcge.f32 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint32x4_t
name|test_vcleq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|,
name|float32x4_t
name|b
parameter_list|)
block|{
return|return
name|vcleq_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcleq_u8
end_comment

begin_comment
comment|// CHECK: vcge.u8 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint8x16_t
name|test_vcleq_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|,
name|uint8x16_t
name|b
parameter_list|)
block|{
return|return
name|vcleq_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcleq_u16
end_comment

begin_comment
comment|// CHECK: vcge.u16 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint16x8_t
name|test_vcleq_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|)
block|{
return|return
name|vcleq_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcleq_u32
end_comment

begin_comment
comment|// CHECK: vcge.u32 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint32x4_t
name|test_vcleq_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|)
block|{
return|return
name|vcleq_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcls_s8
end_comment

begin_comment
comment|// CHECK: vcls.s8 d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int8x8_t
name|test_vcls_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
return|return
name|vcls_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcls_s16
end_comment

begin_comment
comment|// CHECK: vcls.s16 d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int16x4_t
name|test_vcls_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|)
block|{
return|return
name|vcls_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcls_s32
end_comment

begin_comment
comment|// CHECK: vcls.s32 d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int32x2_t
name|test_vcls_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|)
block|{
return|return
name|vcls_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vclsq_s8
end_comment

begin_comment
comment|// CHECK: vcls.s8 q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int8x16_t
name|test_vclsq_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
return|return
name|vclsq_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vclsq_s16
end_comment

begin_comment
comment|// CHECK: vcls.s16 q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int16x8_t
name|test_vclsq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
return|return
name|vclsq_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vclsq_s32
end_comment

begin_comment
comment|// CHECK: vcls.s32 q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int32x4_t
name|test_vclsq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
return|return
name|vclsq_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vclt_s8
end_comment

begin_comment
comment|// CHECK: vcgt.s8 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint8x8_t
name|test_vclt_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
return|return
name|vclt_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vclt_s16
end_comment

begin_comment
comment|// CHECK: vcgt.s16 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint16x4_t
name|test_vclt_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
return|return
name|vclt_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vclt_s32
end_comment

begin_comment
comment|// CHECK: vcgt.s32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint32x2_t
name|test_vclt_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
return|return
name|vclt_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vclt_f32
end_comment

begin_comment
comment|// CHECK: vcgt.f32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint32x2_t
name|test_vclt_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32x2_t
name|b
parameter_list|)
block|{
return|return
name|vclt_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vclt_u8
end_comment

begin_comment
comment|// CHECK: vcgt.u8 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint8x8_t
name|test_vclt_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|)
block|{
return|return
name|vclt_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vclt_u16
end_comment

begin_comment
comment|// CHECK: vcgt.u16 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint16x4_t
name|test_vclt_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|)
block|{
return|return
name|vclt_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vclt_u32
end_comment

begin_comment
comment|// CHECK: vcgt.u32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint32x2_t
name|test_vclt_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|)
block|{
return|return
name|vclt_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcltq_s8
end_comment

begin_comment
comment|// CHECK: vcgt.s8 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint8x16_t
name|test_vcltq_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|)
block|{
return|return
name|vcltq_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcltq_s16
end_comment

begin_comment
comment|// CHECK: vcgt.s16 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint16x8_t
name|test_vcltq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
return|return
name|vcltq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcltq_s32
end_comment

begin_comment
comment|// CHECK: vcgt.s32 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint32x4_t
name|test_vcltq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
return|return
name|vcltq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcltq_f32
end_comment

begin_comment
comment|// CHECK: vcgt.f32 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint32x4_t
name|test_vcltq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|,
name|float32x4_t
name|b
parameter_list|)
block|{
return|return
name|vcltq_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcltq_u8
end_comment

begin_comment
comment|// CHECK: vcgt.u8 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint8x16_t
name|test_vcltq_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|,
name|uint8x16_t
name|b
parameter_list|)
block|{
return|return
name|vcltq_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcltq_u16
end_comment

begin_comment
comment|// CHECK: vcgt.u16 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint16x8_t
name|test_vcltq_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|)
block|{
return|return
name|vcltq_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcltq_u32
end_comment

begin_comment
comment|// CHECK: vcgt.u32 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint32x4_t
name|test_vcltq_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|)
block|{
return|return
name|vcltq_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vclz_s8
end_comment

begin_comment
comment|// CHECK: vclz.i8 d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int8x8_t
name|test_vclz_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
return|return
name|vclz_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vclz_s16
end_comment

begin_comment
comment|// CHECK: vclz.i16 d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int16x4_t
name|test_vclz_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|)
block|{
return|return
name|vclz_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vclz_s32
end_comment

begin_comment
comment|// CHECK: vclz.i32 d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int32x2_t
name|test_vclz_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|)
block|{
return|return
name|vclz_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vclz_u8
end_comment

begin_comment
comment|// CHECK: vclz.i8 d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint8x8_t
name|test_vclz_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|)
block|{
return|return
name|vclz_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vclz_u16
end_comment

begin_comment
comment|// CHECK: vclz.i16 d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint16x4_t
name|test_vclz_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|)
block|{
return|return
name|vclz_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vclz_u32
end_comment

begin_comment
comment|// CHECK: vclz.i32 d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint32x2_t
name|test_vclz_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|)
block|{
return|return
name|vclz_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vclzq_s8
end_comment

begin_comment
comment|// CHECK: vclz.i8 q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int8x16_t
name|test_vclzq_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
return|return
name|vclzq_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vclzq_s16
end_comment

begin_comment
comment|// CHECK: vclz.i16 q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int16x8_t
name|test_vclzq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
return|return
name|vclzq_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vclzq_s32
end_comment

begin_comment
comment|// CHECK: vclz.i32 q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int32x4_t
name|test_vclzq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
return|return
name|vclzq_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vclzq_u8
end_comment

begin_comment
comment|// CHECK: vclz.i8 q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint8x16_t
name|test_vclzq_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|)
block|{
return|return
name|vclzq_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vclzq_u16
end_comment

begin_comment
comment|// CHECK: vclz.i16 q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint16x8_t
name|test_vclzq_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|)
block|{
return|return
name|vclzq_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vclzq_u32
end_comment

begin_comment
comment|// CHECK: vclz.i32 q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint32x4_t
name|test_vclzq_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|)
block|{
return|return
name|vclzq_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcnt_u8
end_comment

begin_comment
comment|// CHECK: vcnt.8 d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint8x8_t
name|test_vcnt_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|)
block|{
return|return
name|vcnt_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcnt_s8
end_comment

begin_comment
comment|// CHECK: vcnt.8 d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int8x8_t
name|test_vcnt_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
return|return
name|vcnt_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcnt_p8
end_comment

begin_comment
comment|// CHECK: vcnt.8 d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|poly8x8_t
name|test_vcnt_p8
parameter_list|(
name|poly8x8_t
name|a
parameter_list|)
block|{
return|return
name|vcnt_p8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcntq_u8
end_comment

begin_comment
comment|// CHECK: vcnt.8 q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint8x16_t
name|test_vcntq_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|)
block|{
return|return
name|vcntq_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcntq_s8
end_comment

begin_comment
comment|// CHECK: vcnt.8 q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int8x16_t
name|test_vcntq_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
return|return
name|vcntq_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcntq_p8
end_comment

begin_comment
comment|// CHECK: vcnt.8 q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|poly8x16_t
name|test_vcntq_p8
parameter_list|(
name|poly8x16_t
name|a
parameter_list|)
block|{
return|return
name|vcntq_p8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcombine_s8
end_comment

begin_comment
comment|// CHECK: vmov d{{[0-9]+}}, r{{[0-9]+}}, r{{[0-9]+}}
end_comment

begin_comment
comment|// CHECK: vmov d{{[0-9]+}}, r{{[0-9]+}}, r{{[0-9]+}}
end_comment

begin_function
name|int8x16_t
name|test_vcombine_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
return|return
name|vcombine_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcombine_s16
end_comment

begin_comment
comment|// CHECK: vmov d{{[0-9]+}}, r{{[0-9]+}}, r{{[0-9]+}}
end_comment

begin_comment
comment|// CHECK: vmov d{{[0-9]+}}, r{{[0-9]+}}, r{{[0-9]+}}
end_comment

begin_function
name|int16x8_t
name|test_vcombine_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
return|return
name|vcombine_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcombine_s32
end_comment

begin_comment
comment|// CHECK: vmov d{{[0-9]+}}, r{{[0-9]+}}, r{{[0-9]+}}
end_comment

begin_comment
comment|// CHECK: vmov d{{[0-9]+}}, r{{[0-9]+}}, r{{[0-9]+}}
end_comment

begin_function
name|int32x4_t
name|test_vcombine_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
return|return
name|vcombine_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcombine_s64
end_comment

begin_comment
comment|// CHECK: vmov d{{[0-9]+}}, r{{[0-9]+}}, r{{[0-9]+}}
end_comment

begin_comment
comment|// CHECK: vmov d{{[0-9]+}}, r{{[0-9]+}}, r{{[0-9]+}}
end_comment

begin_function
name|int64x2_t
name|test_vcombine_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|,
name|int64x1_t
name|b
parameter_list|)
block|{
return|return
name|vcombine_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcombine_f16
end_comment

begin_comment
comment|// CHECK: vmov d{{[0-9]+}}, r{{[0-9]+}}, r{{[0-9]+}}
end_comment

begin_comment
comment|// CHECK: vmov d{{[0-9]+}}, r{{[0-9]+}}, r{{[0-9]+}}
end_comment

begin_function
name|float16x8_t
name|test_vcombine_f16
parameter_list|(
name|float16x4_t
name|a
parameter_list|,
name|float16x4_t
name|b
parameter_list|)
block|{
return|return
name|vcombine_f16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcombine_f32
end_comment

begin_comment
comment|// CHECK: vmov d{{[0-9]+}}, r{{[0-9]+}}, r{{[0-9]+}}
end_comment

begin_comment
comment|// CHECK: vmov d{{[0-9]+}}, r{{[0-9]+}}, r{{[0-9]+}}
end_comment

begin_function
name|float32x4_t
name|test_vcombine_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32x2_t
name|b
parameter_list|)
block|{
return|return
name|vcombine_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcombine_u8
end_comment

begin_comment
comment|// CHECK: vmov d{{[0-9]+}}, r{{[0-9]+}}, r{{[0-9]+}}
end_comment

begin_comment
comment|// CHECK: vmov d{{[0-9]+}}, r{{[0-9]+}}, r{{[0-9]+}}
end_comment

begin_function
name|uint8x16_t
name|test_vcombine_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|)
block|{
return|return
name|vcombine_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcombine_u16
end_comment

begin_comment
comment|// CHECK: vmov d{{[0-9]+}}, r{{[0-9]+}}, r{{[0-9]+}}
end_comment

begin_comment
comment|// CHECK: vmov d{{[0-9]+}}, r{{[0-9]+}}, r{{[0-9]+}}
end_comment

begin_function
name|uint16x8_t
name|test_vcombine_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|)
block|{
return|return
name|vcombine_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcombine_u32
end_comment

begin_comment
comment|// CHECK: vmov d{{[0-9]+}}, r{{[0-9]+}}, r{{[0-9]+}}
end_comment

begin_comment
comment|// CHECK: vmov d{{[0-9]+}}, r{{[0-9]+}}, r{{[0-9]+}}
end_comment

begin_function
name|uint32x4_t
name|test_vcombine_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|)
block|{
return|return
name|vcombine_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcombine_u64
end_comment

begin_comment
comment|// CHECK: vmov d{{[0-9]+}}, r{{[0-9]+}}, r{{[0-9]+}}
end_comment

begin_comment
comment|// CHECK: vmov d{{[0-9]+}}, r{{[0-9]+}}, r{{[0-9]+}}
end_comment

begin_function
name|uint64x2_t
name|test_vcombine_u64
parameter_list|(
name|uint64x1_t
name|a
parameter_list|,
name|uint64x1_t
name|b
parameter_list|)
block|{
return|return
name|vcombine_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcombine_p8
end_comment

begin_comment
comment|// CHECK: vmov d{{[0-9]+}}, r{{[0-9]+}}, r{{[0-9]+}}
end_comment

begin_comment
comment|// CHECK: vmov d{{[0-9]+}}, r{{[0-9]+}}, r{{[0-9]+}}
end_comment

begin_function
name|poly8x16_t
name|test_vcombine_p8
parameter_list|(
name|poly8x8_t
name|a
parameter_list|,
name|poly8x8_t
name|b
parameter_list|)
block|{
return|return
name|vcombine_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcombine_p16
end_comment

begin_comment
comment|// CHECK: vmov d{{[0-9]+}}, r{{[0-9]+}}, r{{[0-9]+}}
end_comment

begin_comment
comment|// CHECK: vmov d{{[0-9]+}}, r{{[0-9]+}}, r{{[0-9]+}}
end_comment

begin_function
name|poly16x8_t
name|test_vcombine_p16
parameter_list|(
name|poly16x4_t
name|a
parameter_list|,
name|poly16x4_t
name|b
parameter_list|)
block|{
return|return
name|vcombine_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcreate_s8
end_comment

begin_comment
comment|// CHECK: vmov [[REG:d[0-9]+]], r0, r1
end_comment

begin_comment
comment|// CHECK: vclz.i8 d{{[0-9]+}}, [[REG]]
end_comment

begin_function
name|int8x8_t
name|test_vcreate_s8
parameter_list|(
name|uint64_t
name|a
parameter_list|)
block|{
return|return
name|vclz_s8
argument_list|(
name|vcreate_s8
argument_list|(
name|a
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcreate_s16
end_comment

begin_comment
comment|// CHECK: vmov [[REG:d[0-9]+]], r0, r1
end_comment

begin_comment
comment|// CHECK: vclz.i16 d{{[0-9]+}}, [[REG]]
end_comment

begin_function
name|int16x4_t
name|test_vcreate_s16
parameter_list|(
name|uint64_t
name|a
parameter_list|)
block|{
return|return
name|vclz_s16
argument_list|(
name|vcreate_s16
argument_list|(
name|a
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcreate_s32
end_comment

begin_comment
comment|// CHECK: vmov [[REG:d[0-9]+]], r0, r1
end_comment

begin_comment
comment|// CHECK: vclz.i32 d{{[0-9]+}}, [[REG]]
end_comment

begin_function
name|int32x2_t
name|test_vcreate_s32
parameter_list|(
name|uint64_t
name|a
parameter_list|)
block|{
return|return
name|vclz_s32
argument_list|(
name|vcreate_s32
argument_list|(
name|a
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcreate_f16
end_comment

begin_function
name|float16x4_t
name|test_vcreate_f16
parameter_list|(
name|uint64_t
name|a
parameter_list|)
block|{
return|return
name|vcreate_f16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcreate_f32
end_comment

begin_function
name|float32x2_t
name|test_vcreate_f32
parameter_list|(
name|uint64_t
name|a
parameter_list|)
block|{
return|return
name|vcreate_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcreate_u8
end_comment

begin_comment
comment|// CHECK: vmov [[REG:d[0-9]+]], r0, r1
end_comment

begin_comment
comment|// CHECK: vclz.i8 d{{[0-9]+}}, [[REG]]
end_comment

begin_function
name|uint8x8_t
name|test_vcreate_u8
parameter_list|(
name|uint64_t
name|a
parameter_list|)
block|{
return|return
name|vclz_s8
argument_list|(
name|vcreate_u8
argument_list|(
name|a
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcreate_u16
end_comment

begin_comment
comment|// CHECK: vmov [[REG:d[0-9]+]], r0, r1
end_comment

begin_comment
comment|// CHECK: vclz.i16 d{{[0-9]+}}, [[REG]]
end_comment

begin_function
name|uint16x4_t
name|test_vcreate_u16
parameter_list|(
name|uint64_t
name|a
parameter_list|)
block|{
return|return
name|vclz_s16
argument_list|(
name|vcreate_u16
argument_list|(
name|a
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcreate_u32
end_comment

begin_comment
comment|// CHECK: vmov [[REG:d[0-9]+]], r0, r1
end_comment

begin_comment
comment|// CHECK: vclz.i32 d{{[0-9]+}}, [[REG]]
end_comment

begin_function
name|uint32x2_t
name|test_vcreate_u32
parameter_list|(
name|uint64_t
name|a
parameter_list|)
block|{
return|return
name|vclz_s32
argument_list|(
name|vcreate_u32
argument_list|(
name|a
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// We have two ways of lowering that.  Either with one 'vmov d, r, r' or
end_comment

begin_comment
comment|// with two 'vmov d[],r'.  LLVM does the latter. We may want to be less
end_comment

begin_comment
comment|// strict about the matching pattern if it starts causing problem.
end_comment

begin_comment
comment|// CHECK-LABEL: test_vcreate_u64
end_comment

begin_comment
comment|// CHECK: vmov.32 [[REG:d[0-9]+]][0], r0
end_comment

begin_comment
comment|// CHECK: vmov.32 [[REG]][1], r1
end_comment

begin_function
name|uint64x1_t
name|test_vcreate_u64
parameter_list|(
name|uint64_t
name|a
parameter_list|)
block|{
name|uint64x1_t
name|tmp
init|=
name|vcreate_u64
argument_list|(
name|a
argument_list|)
decl_stmt|;
return|return
name|vadd_u64
argument_list|(
name|tmp
argument_list|,
name|tmp
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcreate_p8
end_comment

begin_comment
comment|// CHECK: vmov [[REG:d[0-9]+]], r0, r1
end_comment

begin_comment
comment|// CHECK: vcnt.8 d{{[0-9]+}}, [[REG]]
end_comment

begin_function
name|poly8x8_t
name|test_vcreate_p8
parameter_list|(
name|uint64_t
name|a
parameter_list|)
block|{
return|return
name|vcnt_p8
argument_list|(
name|vcreate_p8
argument_list|(
name|a
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcreate_p16
end_comment

begin_comment
comment|// CHECK: vmov [[REG:d[0-9]+]], r0, r1
end_comment

begin_function
name|poly16x4_t
name|test_vcreate_p16
parameter_list|(
name|uint64_t
name|a
parameter_list|)
block|{
name|poly16x4_t
name|tmp
init|=
name|vcreate_p16
argument_list|(
name|a
argument_list|)
decl_stmt|;
return|return
name|vbsl_p16
argument_list|(
name|tmp
argument_list|,
name|tmp
argument_list|,
name|tmp
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcreate_s64
end_comment

begin_comment
comment|// CHECK: vmov.32 [[REG:d[0-9]+]][0], r0
end_comment

begin_comment
comment|// CHECK: vmov.32 [[REG]][1], r1
end_comment

begin_function
name|int64x1_t
name|test_vcreate_s64
parameter_list|(
name|uint64_t
name|a
parameter_list|)
block|{
name|int64x1_t
name|tmp
init|=
name|vcreate_s64
argument_list|(
name|a
argument_list|)
decl_stmt|;
return|return
name|vadd_s64
argument_list|(
name|tmp
argument_list|,
name|tmp
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcvt_f16_f32
end_comment

begin_comment
comment|// CHECK: vcvt.f16.f32 d{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|float16x4_t
name|test_vcvt_f16_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
return|return
name|vcvt_f16_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcvt_f32_s32
end_comment

begin_comment
comment|// CHECK: vcvt.f32.s32 d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|float32x2_t
name|test_vcvt_f32_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|)
block|{
return|return
name|vcvt_f32_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcvt_f32_u32
end_comment

begin_comment
comment|// CHECK: vcvt.f32.u32 d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|float32x2_t
name|test_vcvt_f32_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|)
block|{
return|return
name|vcvt_f32_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcvtq_f32_s32
end_comment

begin_comment
comment|// CHECK: vcvt.f32.s32 q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|float32x4_t
name|test_vcvtq_f32_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
return|return
name|vcvtq_f32_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcvtq_f32_u32
end_comment

begin_comment
comment|// CHECK: vcvt.f32.u32 q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|float32x4_t
name|test_vcvtq_f32_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|)
block|{
return|return
name|vcvtq_f32_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcvt_f32_f16
end_comment

begin_comment
comment|// CHECK: vcvt.f32.f16
end_comment

begin_function
name|float32x4_t
name|test_vcvt_f32_f16
parameter_list|(
name|float16x4_t
name|a
parameter_list|)
block|{
return|return
name|vcvt_f32_f16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcvt_n_f32_s32
end_comment

begin_comment
comment|// CHECK: vcvt.f32.s32 d{{[0-9]+}}, d{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|float32x2_t
name|test_vcvt_n_f32_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|)
block|{
return|return
name|vcvt_n_f32_s32
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcvt_n_f32_u32
end_comment

begin_comment
comment|// CHECK: vcvt.f32.u32 d{{[0-9]+}}, d{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|float32x2_t
name|test_vcvt_n_f32_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|)
block|{
return|return
name|vcvt_n_f32_u32
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcvtq_n_f32_s32
end_comment

begin_comment
comment|// CHECK: vcvt.f32.s32 q{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|float32x4_t
name|test_vcvtq_n_f32_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
return|return
name|vcvtq_n_f32_s32
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcvtq_n_f32_u32
end_comment

begin_comment
comment|// CHECK: vcvt.f32.u32 q{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|float32x4_t
name|test_vcvtq_n_f32_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|)
block|{
return|return
name|vcvtq_n_f32_u32
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcvt_n_s32_f32
end_comment

begin_comment
comment|// CHECK: vcvt.s32.f32 d{{[0-9]+}}, d{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|int32x2_t
name|test_vcvt_n_s32_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
return|return
name|vcvt_n_s32_f32
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcvtq_n_s32_f32
end_comment

begin_comment
comment|// CHECK: vcvt.s32.f32 q{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|int32x4_t
name|test_vcvtq_n_s32_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
return|return
name|vcvtq_n_s32_f32
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcvt_n_u32_f32
end_comment

begin_comment
comment|// CHECK: vcvt.u32.f32 d{{[0-9]+}}, d{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|uint32x2_t
name|test_vcvt_n_u32_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
return|return
name|vcvt_n_u32_f32
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcvtq_n_u32_f32
end_comment

begin_comment
comment|// CHECK: vcvt.u32.f32 q{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|uint32x4_t
name|test_vcvtq_n_u32_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
return|return
name|vcvtq_n_u32_f32
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcvt_s32_f32
end_comment

begin_comment
comment|// CHECK: vcvt.s32.f32 d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int32x2_t
name|test_vcvt_s32_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
return|return
name|vcvt_s32_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcvtq_s32_f32
end_comment

begin_comment
comment|// CHECK: vcvt.s32.f32 q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int32x4_t
name|test_vcvtq_s32_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
return|return
name|vcvtq_s32_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcvt_u32_f32
end_comment

begin_comment
comment|// CHECK: vcvt.u32.f32 d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint32x2_t
name|test_vcvt_u32_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
return|return
name|vcvt_u32_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vcvtq_u32_f32
end_comment

begin_comment
comment|// CHECK: vcvt.u32.f32 q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint32x4_t
name|test_vcvtq_u32_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
return|return
name|vcvtq_u32_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vdup_lane_u8
end_comment

begin_comment
comment|// CHECK: vdup.8 d{{[0-9]+}}, d{{[0-9]+}}[{{[0-9]}}]
end_comment

begin_function
name|uint8x8_t
name|test_vdup_lane_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|)
block|{
return|return
name|vdup_lane_u8
argument_list|(
name|a
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vdup_lane_u16
end_comment

begin_comment
comment|// CHECK: vdup.16 d{{[0-9]+}}, d{{[0-9]+}}[{{[0-9]}}]
end_comment

begin_function
name|uint16x4_t
name|test_vdup_lane_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|)
block|{
return|return
name|vdup_lane_u16
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vdup_lane_u32
end_comment

begin_comment
comment|// CHECK: vdup.32 d{{[0-9]+}}, d{{[0-9]+}}[{{[0-9]}}]
end_comment

begin_function
name|uint32x2_t
name|test_vdup_lane_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|)
block|{
return|return
name|vdup_lane_u32
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vdup_lane_s8
end_comment

begin_comment
comment|// CHECK: vdup.8 d{{[0-9]+}}, d{{[0-9]+}}[{{[0-9]}}]
end_comment

begin_function
name|int8x8_t
name|test_vdup_lane_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
return|return
name|vdup_lane_s8
argument_list|(
name|a
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vdup_lane_s16
end_comment

begin_comment
comment|// CHECK: vdup.16 d{{[0-9]+}}, d{{[0-9]+}}[{{[0-9]}}]
end_comment

begin_function
name|int16x4_t
name|test_vdup_lane_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|)
block|{
return|return
name|vdup_lane_s16
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vdup_lane_s32
end_comment

begin_comment
comment|// CHECK: vdup.32 d{{[0-9]+}}, d{{[0-9]+}}[{{[0-9]}}]
end_comment

begin_function
name|int32x2_t
name|test_vdup_lane_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|)
block|{
return|return
name|vdup_lane_s32
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vdup_lane_p8
end_comment

begin_comment
comment|// CHECK: vdup.8 d{{[0-9]+}}, d{{[0-9]+}}[{{[0-9]}}]
end_comment

begin_function
name|poly8x8_t
name|test_vdup_lane_p8
parameter_list|(
name|poly8x8_t
name|a
parameter_list|)
block|{
return|return
name|vdup_lane_p8
argument_list|(
name|a
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vdup_lane_p16
end_comment

begin_comment
comment|// CHECK: vdup.16 d{{[0-9]+}}, d{{[0-9]+}}[{{[0-9]}}]
end_comment

begin_function
name|poly16x4_t
name|test_vdup_lane_p16
parameter_list|(
name|poly16x4_t
name|a
parameter_list|)
block|{
return|return
name|vdup_lane_p16
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vdup_lane_f32
end_comment

begin_comment
comment|// CHECK: vdup.32 d{{[0-9]+}}, d{{[0-9]+}}[{{[0-9]}}]
end_comment

begin_function
name|float32x2_t
name|test_vdup_lane_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
return|return
name|vdup_lane_f32
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vdupq_lane_u8
end_comment

begin_comment
comment|// CHECK: vdup.8 q{{[0-9]+}}, d{{[0-9]+}}[{{[0-9]}}]
end_comment

begin_function
name|uint8x16_t
name|test_vdupq_lane_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|)
block|{
return|return
name|vdupq_lane_u8
argument_list|(
name|a
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vdupq_lane_u16
end_comment

begin_comment
comment|// CHECK: vdup.16 q{{[0-9]+}}, d{{[0-9]+}}[{{[0-9]}}]
end_comment

begin_function
name|uint16x8_t
name|test_vdupq_lane_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|)
block|{
return|return
name|vdupq_lane_u16
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vdupq_lane_u32
end_comment

begin_comment
comment|// CHECK: vdup.32 q{{[0-9]+}}, d{{[0-9]+}}[{{[0-9]}}]
end_comment

begin_function
name|uint32x4_t
name|test_vdupq_lane_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|)
block|{
return|return
name|vdupq_lane_u32
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vdupq_lane_s8
end_comment

begin_comment
comment|// CHECK: vdup.8 q{{[0-9]+}}, d{{[0-9]+}}[{{[0-9]}}]
end_comment

begin_function
name|int8x16_t
name|test_vdupq_lane_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
return|return
name|vdupq_lane_s8
argument_list|(
name|a
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vdupq_lane_s16
end_comment

begin_comment
comment|// CHECK: vdup.16 q{{[0-9]+}}, d{{[0-9]+}}[{{[0-9]}}]
end_comment

begin_function
name|int16x8_t
name|test_vdupq_lane_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|)
block|{
return|return
name|vdupq_lane_s16
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vdupq_lane_s32
end_comment

begin_comment
comment|// CHECK: vdup.32 q{{[0-9]+}}, d{{[0-9]+}}[{{[0-9]}}]
end_comment

begin_function
name|int32x4_t
name|test_vdupq_lane_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|)
block|{
return|return
name|vdupq_lane_s32
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vdupq_lane_p8
end_comment

begin_comment
comment|// CHECK: vdup.8 q{{[0-9]+}}, d{{[0-9]+}}[{{[0-9]}}]
end_comment

begin_function
name|poly8x16_t
name|test_vdupq_lane_p8
parameter_list|(
name|poly8x8_t
name|a
parameter_list|)
block|{
return|return
name|vdupq_lane_p8
argument_list|(
name|a
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vdupq_lane_p16
end_comment

begin_comment
comment|// CHECK: vdup.16 q{{[0-9]+}}, d{{[0-9]+}}[{{[0-9]}}]
end_comment

begin_function
name|poly16x8_t
name|test_vdupq_lane_p16
parameter_list|(
name|poly16x4_t
name|a
parameter_list|)
block|{
return|return
name|vdupq_lane_p16
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vdupq_lane_f32
end_comment

begin_comment
comment|// CHECK: vdup.32 q{{[0-9]+}}, d{{[0-9]+}}[{{[0-9]}}]
end_comment

begin_function
name|float32x4_t
name|test_vdupq_lane_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
return|return
name|vdupq_lane_f32
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vdup_lane_s64
end_comment

begin_function
name|int64x1_t
name|test_vdup_lane_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|)
block|{
return|return
name|vdup_lane_s64
argument_list|(
name|a
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vdup_lane_u64
end_comment

begin_function
name|uint64x1_t
name|test_vdup_lane_u64
parameter_list|(
name|uint64x1_t
name|a
parameter_list|)
block|{
return|return
name|vdup_lane_u64
argument_list|(
name|a
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vdupq_lane_s64
end_comment

begin_comment
comment|// CHECK: {{vmov|vdup}}
end_comment

begin_function
name|int64x2_t
name|test_vdupq_lane_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|)
block|{
return|return
name|vdupq_lane_s64
argument_list|(
name|a
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vdupq_lane_u64
end_comment

begin_comment
comment|// CHECK: {{vmov|vdup}}
end_comment

begin_function
name|uint64x2_t
name|test_vdupq_lane_u64
parameter_list|(
name|uint64x1_t
name|a
parameter_list|)
block|{
return|return
name|vdupq_lane_u64
argument_list|(
name|a
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vdup_n_u8
end_comment

begin_comment
comment|// CHECK: vmov
end_comment

begin_function
name|uint8x8_t
name|test_vdup_n_u8
parameter_list|(
name|uint8_t
name|a
parameter_list|)
block|{
return|return
name|vdup_n_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vdup_n_u16
end_comment

begin_comment
comment|// CHECK: vmov
end_comment

begin_function
name|uint16x4_t
name|test_vdup_n_u16
parameter_list|(
name|uint16_t
name|a
parameter_list|)
block|{
return|return
name|vdup_n_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vdup_n_u32
end_comment

begin_comment
comment|// CHECK: mov
end_comment

begin_function
name|uint32x2_t
name|test_vdup_n_u32
parameter_list|(
name|uint32_t
name|a
parameter_list|)
block|{
return|return
name|vdup_n_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vdup_n_s8
end_comment

begin_comment
comment|// CHECK: vmov
end_comment

begin_function
name|int8x8_t
name|test_vdup_n_s8
parameter_list|(
name|int8_t
name|a
parameter_list|)
block|{
return|return
name|vdup_n_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vdup_n_s16
end_comment

begin_comment
comment|// CHECK: vmov
end_comment

begin_function
name|int16x4_t
name|test_vdup_n_s16
parameter_list|(
name|int16_t
name|a
parameter_list|)
block|{
return|return
name|vdup_n_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vdup_n_s32
end_comment

begin_comment
comment|// CHECK: mov
end_comment

begin_function
name|int32x2_t
name|test_vdup_n_s32
parameter_list|(
name|int32_t
name|a
parameter_list|)
block|{
return|return
name|vdup_n_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vdup_n_p8
end_comment

begin_comment
comment|// CHECK: vmov
end_comment

begin_function
name|poly8x8_t
name|test_vdup_n_p8
parameter_list|(
name|poly8_t
name|a
parameter_list|)
block|{
return|return
name|vdup_n_p8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vdup_n_p16
end_comment

begin_comment
comment|// CHECK: vmov
end_comment

begin_function
name|poly16x4_t
name|test_vdup_n_p16
parameter_list|(
name|poly16_t
name|a
parameter_list|)
block|{
return|return
name|vdup_n_p16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vdup_n_f16
end_comment

begin_comment
comment|// CHECK: vld1.16 {{{d[0-9]+\[\]}}}
end_comment

begin_function
name|float16x4_t
name|test_vdup_n_f16
parameter_list|(
name|float16_t
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vdup_n_f16
argument_list|(
operator|*
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vdup_n_f32
end_comment

begin_comment
comment|// CHECK: mov
end_comment

begin_function
name|float32x2_t
name|test_vdup_n_f32
parameter_list|(
name|float32_t
name|a
parameter_list|)
block|{
return|return
name|vdup_n_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vdupq_n_u8
end_comment

begin_comment
comment|// CHECK: vmov
end_comment

begin_function
name|uint8x16_t
name|test_vdupq_n_u8
parameter_list|(
name|uint8_t
name|a
parameter_list|)
block|{
return|return
name|vdupq_n_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vdupq_n_u16
end_comment

begin_comment
comment|// CHECK: vmov
end_comment

begin_function
name|uint16x8_t
name|test_vdupq_n_u16
parameter_list|(
name|uint16_t
name|a
parameter_list|)
block|{
return|return
name|vdupq_n_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vdupq_n_u32
end_comment

begin_comment
comment|// CHECK: vmov
end_comment

begin_function
name|uint32x4_t
name|test_vdupq_n_u32
parameter_list|(
name|uint32_t
name|a
parameter_list|)
block|{
return|return
name|vdupq_n_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vdupq_n_s8
end_comment

begin_comment
comment|// CHECK: vmov
end_comment

begin_function
name|int8x16_t
name|test_vdupq_n_s8
parameter_list|(
name|int8_t
name|a
parameter_list|)
block|{
return|return
name|vdupq_n_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vdupq_n_s16
end_comment

begin_comment
comment|// CHECK: vmov
end_comment

begin_function
name|int16x8_t
name|test_vdupq_n_s16
parameter_list|(
name|int16_t
name|a
parameter_list|)
block|{
return|return
name|vdupq_n_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vdupq_n_s32
end_comment

begin_comment
comment|// CHECK: vmov
end_comment

begin_function
name|int32x4_t
name|test_vdupq_n_s32
parameter_list|(
name|int32_t
name|a
parameter_list|)
block|{
return|return
name|vdupq_n_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vdupq_n_p8
end_comment

begin_comment
comment|// CHECK: vmov
end_comment

begin_function
name|poly8x16_t
name|test_vdupq_n_p8
parameter_list|(
name|poly8_t
name|a
parameter_list|)
block|{
return|return
name|vdupq_n_p8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vdupq_n_p16
end_comment

begin_comment
comment|// CHECK: vmov
end_comment

begin_function
name|poly16x8_t
name|test_vdupq_n_p16
parameter_list|(
name|poly16_t
name|a
parameter_list|)
block|{
return|return
name|vdupq_n_p16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vdupq_n_f16
end_comment

begin_comment
comment|// CHECK: vld1.16 {{{d[0-9]+\[\], d[0-9]+\[\]}}}
end_comment

begin_function
name|float16x8_t
name|test_vdupq_n_f16
parameter_list|(
name|float16_t
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vdupq_n_f16
argument_list|(
operator|*
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vdupq_n_f32
end_comment

begin_comment
comment|// CHECK: vmov
end_comment

begin_function
name|float32x4_t
name|test_vdupq_n_f32
parameter_list|(
name|float32_t
name|a
parameter_list|)
block|{
return|return
name|vdupq_n_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vdup_n_s64
end_comment

begin_comment
comment|// CHECK: vmov
end_comment

begin_function
name|int64x1_t
name|test_vdup_n_s64
parameter_list|(
name|int64_t
name|a
parameter_list|)
block|{
name|int64x1_t
name|tmp
init|=
name|vdup_n_s64
argument_list|(
name|a
argument_list|)
decl_stmt|;
return|return
name|vadd_s64
argument_list|(
name|tmp
argument_list|,
name|tmp
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vdup_n_u64
end_comment

begin_comment
comment|// CHECK: vmov
end_comment

begin_function
name|uint64x1_t
name|test_vdup_n_u64
parameter_list|(
name|uint64_t
name|a
parameter_list|)
block|{
name|int64x1_t
name|tmp
init|=
name|vdup_n_u64
argument_list|(
name|a
argument_list|)
decl_stmt|;
return|return
name|vadd_s64
argument_list|(
name|tmp
argument_list|,
name|tmp
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vdupq_n_s64
end_comment

begin_comment
comment|// CHECK: vmov
end_comment

begin_function
name|int64x2_t
name|test_vdupq_n_s64
parameter_list|(
name|int64_t
name|a
parameter_list|)
block|{
name|int64x2_t
name|tmp
init|=
name|vdupq_n_s64
argument_list|(
name|a
argument_list|)
decl_stmt|;
return|return
name|vaddq_s64
argument_list|(
name|tmp
argument_list|,
name|tmp
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vdupq_n_u64
end_comment

begin_comment
comment|// CHECK: vmov
end_comment

begin_function
name|uint64x2_t
name|test_vdupq_n_u64
parameter_list|(
name|uint64_t
name|a
parameter_list|)
block|{
name|int64x2_t
name|tmp
init|=
name|vdupq_n_u64
argument_list|(
name|a
argument_list|)
decl_stmt|;
return|return
name|vaddq_u64
argument_list|(
name|tmp
argument_list|,
name|tmp
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_veor_s8
end_comment

begin_comment
comment|// CHECK: veor d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int8x8_t
name|test_veor_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
return|return
name|veor_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_veor_s16
end_comment

begin_comment
comment|// CHECK: veor d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int16x4_t
name|test_veor_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
return|return
name|veor_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_veor_s32
end_comment

begin_comment
comment|// CHECK: veor d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int32x2_t
name|test_veor_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
return|return
name|veor_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_veor_s64
end_comment

begin_comment
comment|// CHECK: veor d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int64x1_t
name|test_veor_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|,
name|int64x1_t
name|b
parameter_list|)
block|{
return|return
name|veor_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_veor_u8
end_comment

begin_comment
comment|// CHECK: veor d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint8x8_t
name|test_veor_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|)
block|{
return|return
name|veor_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_veor_u16
end_comment

begin_comment
comment|// CHECK: veor d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint16x4_t
name|test_veor_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|)
block|{
return|return
name|veor_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_veor_u32
end_comment

begin_comment
comment|// CHECK: veor d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint32x2_t
name|test_veor_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|)
block|{
return|return
name|veor_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_veor_u64
end_comment

begin_comment
comment|// CHECK: veor d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint64x1_t
name|test_veor_u64
parameter_list|(
name|uint64x1_t
name|a
parameter_list|,
name|uint64x1_t
name|b
parameter_list|)
block|{
return|return
name|veor_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_veorq_s8
end_comment

begin_comment
comment|// CHECK: veor q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int8x16_t
name|test_veorq_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|)
block|{
return|return
name|veorq_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_veorq_s16
end_comment

begin_comment
comment|// CHECK: veor q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int16x8_t
name|test_veorq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
return|return
name|veorq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_veorq_s32
end_comment

begin_comment
comment|// CHECK: veor q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int32x4_t
name|test_veorq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
return|return
name|veorq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_veorq_s64
end_comment

begin_comment
comment|// CHECK: veor q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int64x2_t
name|test_veorq_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int64x2_t
name|b
parameter_list|)
block|{
return|return
name|veorq_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_veorq_u8
end_comment

begin_comment
comment|// CHECK: veor q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint8x16_t
name|test_veorq_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|,
name|uint8x16_t
name|b
parameter_list|)
block|{
return|return
name|veorq_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_veorq_u16
end_comment

begin_comment
comment|// CHECK: veor q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint16x8_t
name|test_veorq_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|)
block|{
return|return
name|veorq_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_veorq_u32
end_comment

begin_comment
comment|// CHECK: veor q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint32x4_t
name|test_veorq_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|)
block|{
return|return
name|veorq_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_veorq_u64
end_comment

begin_comment
comment|// CHECK: veor q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint64x2_t
name|test_veorq_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|,
name|uint64x2_t
name|b
parameter_list|)
block|{
return|return
name|veorq_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vext_s8
end_comment

begin_comment
comment|// CHECK: vext.8 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}, #{{[0-9]+}}
end_comment

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
return|return
name|vext_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vext_u8
end_comment

begin_comment
comment|// CHECK: vext.8 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}, #{{[0-9]+}}
end_comment

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
return|return
name|vext_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vext_p8
end_comment

begin_comment
comment|// CHECK: vext.8 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}, #{{[0-9]+}}
end_comment

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
return|return
name|vext_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vext_s16
end_comment

begin_comment
comment|// CHECK: vext.16 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}, #{{[0-9]+}}
end_comment

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
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vext_u16
end_comment

begin_comment
comment|// CHECK: vext.16 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}, #{{[0-9]+}}
end_comment

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
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vext_p16
end_comment

begin_comment
comment|// CHECK: vext.16 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}, #{{[0-9]+}}
end_comment

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
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vext_s32
end_comment

begin_comment
comment|// CHECK: vext.32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}, #{{[0-9]+}}
end_comment

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
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vext_u32
end_comment

begin_comment
comment|// CHECK: vext.32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}, #{{[0-9]+}}
end_comment

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
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vext_s64
end_comment

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

begin_comment
comment|// CHECK-LABEL: test_vext_u64
end_comment

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

begin_comment
comment|// CHECK-LABEL: test_vext_f32
end_comment

begin_comment
comment|// CHECK: vext.32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}, #{{[0-9]+}}
end_comment

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
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vextq_s8
end_comment

begin_comment
comment|// CHECK: vext.8 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

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
return|return
name|vextq_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|15
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vextq_u8
end_comment

begin_comment
comment|// CHECK: vext.8 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

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
return|return
name|vextq_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|15
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vextq_p8
end_comment

begin_comment
comment|// CHECK: vext.8 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

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
return|return
name|vextq_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|15
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vextq_s16
end_comment

begin_comment
comment|// CHECK: vext.16 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

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
return|return
name|vextq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vextq_u16
end_comment

begin_comment
comment|// CHECK: vext.16 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

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
return|return
name|vextq_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vextq_p16
end_comment

begin_comment
comment|// CHECK: vext.16 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

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
return|return
name|vextq_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vextq_s32
end_comment

begin_comment
comment|// CHECK: vext.32 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

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
return|return
name|vextq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vextq_u32
end_comment

begin_comment
comment|// CHECK: vext.32 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

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
return|return
name|vextq_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vextq_s64
end_comment

begin_comment
comment|// CHECK: {{vmov|vdup}}
end_comment

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
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vextq_u64
end_comment

begin_comment
comment|// CHECK: {{vmov|vdup}}
end_comment

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
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vextq_f32
end_comment

begin_comment
comment|// CHECK: vext.32 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

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
return|return
name|vextq_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vfma_f32
end_comment

begin_comment
comment|// CHECK: vfma.f32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|float32x2_t
name|test_vfma_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32x2_t
name|b
parameter_list|,
name|float32x2_t
name|c
parameter_list|)
block|{
return|return
name|vfma_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vfmaq_f32
end_comment

begin_comment
comment|// CHECK: vfma.f32 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|float32x4_t
name|test_vfmaq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|,
name|float32x4_t
name|b
parameter_list|,
name|float32x4_t
name|c
parameter_list|)
block|{
return|return
name|vfmaq_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vget_high_s8
end_comment

begin_function
name|int8x8_t
name|test_vget_high_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
return|return
name|vget_high_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vget_high_s16
end_comment

begin_function
name|int16x4_t
name|test_vget_high_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
return|return
name|vget_high_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vget_high_s32
end_comment

begin_function
name|int32x2_t
name|test_vget_high_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
return|return
name|vget_high_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vget_high_s64
end_comment

begin_function
name|int64x1_t
name|test_vget_high_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|)
block|{
return|return
name|vget_high_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vget_high_f16
end_comment

begin_function
name|float16x4_t
name|test_vget_high_f16
parameter_list|(
name|float16x8_t
name|a
parameter_list|)
block|{
return|return
name|vget_high_f16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vget_high_f32
end_comment

begin_function
name|float32x2_t
name|test_vget_high_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
return|return
name|vget_high_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vget_high_u8
end_comment

begin_function
name|uint8x8_t
name|test_vget_high_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|)
block|{
return|return
name|vget_high_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vget_high_u16
end_comment

begin_function
name|uint16x4_t
name|test_vget_high_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|)
block|{
return|return
name|vget_high_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vget_high_u32
end_comment

begin_function
name|uint32x2_t
name|test_vget_high_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|)
block|{
return|return
name|vget_high_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vget_high_u64
end_comment

begin_function
name|uint64x1_t
name|test_vget_high_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|)
block|{
return|return
name|vget_high_u64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vget_high_p8
end_comment

begin_function
name|poly8x8_t
name|test_vget_high_p8
parameter_list|(
name|poly8x16_t
name|a
parameter_list|)
block|{
return|return
name|vget_high_p8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vget_high_p16
end_comment

begin_function
name|poly16x4_t
name|test_vget_high_p16
parameter_list|(
name|poly16x8_t
name|a
parameter_list|)
block|{
return|return
name|vget_high_p16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vget_lane_u8
end_comment

begin_comment
comment|// CHECK: vmov
end_comment

begin_function
name|uint8_t
name|test_vget_lane_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|)
block|{
return|return
name|vget_lane_u8
argument_list|(
name|a
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vget_lane_u16
end_comment

begin_comment
comment|// CHECK: vmov
end_comment

begin_function
name|uint16_t
name|test_vget_lane_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|)
block|{
return|return
name|vget_lane_u16
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vget_lane_u32
end_comment

begin_comment
comment|// CHECK: mov
end_comment

begin_function
name|uint32_t
name|test_vget_lane_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|)
block|{
return|return
name|vget_lane_u32
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vget_lane_s8
end_comment

begin_comment
comment|// CHECK: vmov
end_comment

begin_function
name|int8_t
name|test_vget_lane_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
return|return
name|vget_lane_s8
argument_list|(
name|a
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vget_lane_s16
end_comment

begin_comment
comment|// CHECK: vmov
end_comment

begin_function
name|int16_t
name|test_vget_lane_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|)
block|{
return|return
name|vget_lane_s16
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vget_lane_s32
end_comment

begin_comment
comment|// CHECK: mov
end_comment

begin_function
name|int32_t
name|test_vget_lane_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|)
block|{
return|return
name|vget_lane_s32
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vget_lane_p8
end_comment

begin_comment
comment|// CHECK: vmov
end_comment

begin_function
name|poly8_t
name|test_vget_lane_p8
parameter_list|(
name|poly8x8_t
name|a
parameter_list|)
block|{
return|return
name|vget_lane_p8
argument_list|(
name|a
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vget_lane_p16
end_comment

begin_comment
comment|// CHECK: vmov
end_comment

begin_function
name|poly16_t
name|test_vget_lane_p16
parameter_list|(
name|poly16x4_t
name|a
parameter_list|)
block|{
return|return
name|vget_lane_p16
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vget_lane_f32
end_comment

begin_comment
comment|// CHECK: vmov
end_comment

begin_function
name|float32_t
name|test_vget_lane_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
return|return
name|vget_lane_f32
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vgetq_lane_u8
end_comment

begin_comment
comment|// CHECK: vmov
end_comment

begin_function
name|uint8_t
name|test_vgetq_lane_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|)
block|{
return|return
name|vgetq_lane_u8
argument_list|(
name|a
argument_list|,
literal|15
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vgetq_lane_u16
end_comment

begin_comment
comment|// CHECK: vmov
end_comment

begin_function
name|uint16_t
name|test_vgetq_lane_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|)
block|{
return|return
name|vgetq_lane_u16
argument_list|(
name|a
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vgetq_lane_u32
end_comment

begin_comment
comment|// CHECK: vmov
end_comment

begin_function
name|uint32_t
name|test_vgetq_lane_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|)
block|{
return|return
name|vgetq_lane_u32
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vgetq_lane_s8
end_comment

begin_comment
comment|// CHECK: vmov
end_comment

begin_function
name|int8_t
name|test_vgetq_lane_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
return|return
name|vgetq_lane_s8
argument_list|(
name|a
argument_list|,
literal|15
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vgetq_lane_s16
end_comment

begin_comment
comment|// CHECK: vmov
end_comment

begin_function
name|int16_t
name|test_vgetq_lane_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
return|return
name|vgetq_lane_s16
argument_list|(
name|a
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vgetq_lane_s32
end_comment

begin_comment
comment|// CHECK: vmov
end_comment

begin_function
name|int32_t
name|test_vgetq_lane_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
return|return
name|vgetq_lane_s32
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vgetq_lane_p8
end_comment

begin_comment
comment|// CHECK: vmov
end_comment

begin_function
name|poly8_t
name|test_vgetq_lane_p8
parameter_list|(
name|poly8x16_t
name|a
parameter_list|)
block|{
return|return
name|vgetq_lane_p8
argument_list|(
name|a
argument_list|,
literal|15
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vgetq_lane_p16
end_comment

begin_comment
comment|// CHECK: vmov
end_comment

begin_function
name|poly16_t
name|test_vgetq_lane_p16
parameter_list|(
name|poly16x8_t
name|a
parameter_list|)
block|{
return|return
name|vgetq_lane_p16
argument_list|(
name|a
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vgetq_lane_f32
end_comment

begin_comment
comment|// CHECK: vmov
end_comment

begin_function
name|float32_t
name|test_vgetq_lane_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
return|return
name|vgetq_lane_f32
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vget_lane_s64
end_comment

begin_comment
comment|// The optimizer is able to remove all moves now.
end_comment

begin_function
name|int64_t
name|test_vget_lane_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|)
block|{
return|return
name|vget_lane_s64
argument_list|(
name|a
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vget_lane_u64
end_comment

begin_comment
comment|// The optimizer is able to remove all moves now.
end_comment

begin_function
name|uint64_t
name|test_vget_lane_u64
parameter_list|(
name|uint64x1_t
name|a
parameter_list|)
block|{
return|return
name|vget_lane_u64
argument_list|(
name|a
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vgetq_lane_s64
end_comment

begin_comment
comment|// CHECK: vmov
end_comment

begin_function
name|int64_t
name|test_vgetq_lane_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|)
block|{
return|return
name|vgetq_lane_s64
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vgetq_lane_u64
end_comment

begin_comment
comment|// CHECK: vmov
end_comment

begin_function
name|uint64_t
name|test_vgetq_lane_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|)
block|{
return|return
name|vgetq_lane_u64
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vget_low_s8
end_comment

begin_function
name|int8x8_t
name|test_vget_low_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
return|return
name|vget_low_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vget_low_s16
end_comment

begin_function
name|int16x4_t
name|test_vget_low_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
return|return
name|vget_low_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vget_low_s32
end_comment

begin_function
name|int32x2_t
name|test_vget_low_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
return|return
name|vget_low_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vget_low_s64
end_comment

begin_function
name|int64x1_t
name|test_vget_low_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|)
block|{
return|return
name|vget_low_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vget_low_f16
end_comment

begin_function
name|float16x4_t
name|test_vget_low_f16
parameter_list|(
name|float16x8_t
name|a
parameter_list|)
block|{
return|return
name|vget_low_f16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vget_low_f32
end_comment

begin_function
name|float32x2_t
name|test_vget_low_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
return|return
name|vget_low_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vget_low_u8
end_comment

begin_function
name|uint8x8_t
name|test_vget_low_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|)
block|{
return|return
name|vget_low_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vget_low_u16
end_comment

begin_function
name|uint16x4_t
name|test_vget_low_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|)
block|{
return|return
name|vget_low_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vget_low_u32
end_comment

begin_function
name|uint32x2_t
name|test_vget_low_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|)
block|{
return|return
name|vget_low_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vget_low_u64
end_comment

begin_function
name|uint64x1_t
name|test_vget_low_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|)
block|{
return|return
name|vget_low_u64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vget_low_p8
end_comment

begin_function
name|poly8x8_t
name|test_vget_low_p8
parameter_list|(
name|poly8x16_t
name|a
parameter_list|)
block|{
return|return
name|vget_low_p8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vget_low_p16
end_comment

begin_function
name|poly16x4_t
name|test_vget_low_p16
parameter_list|(
name|poly16x8_t
name|a
parameter_list|)
block|{
return|return
name|vget_low_p16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vhadd_s8
end_comment

begin_comment
comment|// CHECK: vhadd.s8 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int8x8_t
name|test_vhadd_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
return|return
name|vhadd_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vhadd_s16
end_comment

begin_comment
comment|// CHECK: vhadd.s16 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int16x4_t
name|test_vhadd_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
return|return
name|vhadd_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vhadd_s32
end_comment

begin_comment
comment|// CHECK: vhadd.s32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int32x2_t
name|test_vhadd_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
return|return
name|vhadd_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vhadd_u8
end_comment

begin_comment
comment|// CHECK: vhadd.u8 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint8x8_t
name|test_vhadd_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|)
block|{
return|return
name|vhadd_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vhadd_u16
end_comment

begin_comment
comment|// CHECK: vhadd.u16 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint16x4_t
name|test_vhadd_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|)
block|{
return|return
name|vhadd_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vhadd_u32
end_comment

begin_comment
comment|// CHECK: vhadd.u32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint32x2_t
name|test_vhadd_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|)
block|{
return|return
name|vhadd_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vhaddq_s8
end_comment

begin_comment
comment|// CHECK: vhadd.s8 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int8x16_t
name|test_vhaddq_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|)
block|{
return|return
name|vhaddq_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vhaddq_s16
end_comment

begin_comment
comment|// CHECK: vhadd.s16 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int16x8_t
name|test_vhaddq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
return|return
name|vhaddq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vhaddq_s32
end_comment

begin_comment
comment|// CHECK: vhadd.s32 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int32x4_t
name|test_vhaddq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
return|return
name|vhaddq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vhaddq_u8
end_comment

begin_comment
comment|// CHECK: vhadd.u8 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint8x16_t
name|test_vhaddq_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|,
name|uint8x16_t
name|b
parameter_list|)
block|{
return|return
name|vhaddq_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vhaddq_u16
end_comment

begin_comment
comment|// CHECK: vhadd.u16 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint16x8_t
name|test_vhaddq_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|)
block|{
return|return
name|vhaddq_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vhaddq_u32
end_comment

begin_comment
comment|// CHECK: vhadd.u32 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint32x4_t
name|test_vhaddq_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|)
block|{
return|return
name|vhaddq_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vhsub_s8
end_comment

begin_comment
comment|// CHECK: vhsub.s8 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int8x8_t
name|test_vhsub_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
return|return
name|vhsub_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vhsub_s16
end_comment

begin_comment
comment|// CHECK: vhsub.s16 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int16x4_t
name|test_vhsub_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
return|return
name|vhsub_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vhsub_s32
end_comment

begin_comment
comment|// CHECK: vhsub.s32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int32x2_t
name|test_vhsub_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
return|return
name|vhsub_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vhsub_u8
end_comment

begin_comment
comment|// CHECK: vhsub.u8 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint8x8_t
name|test_vhsub_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|)
block|{
return|return
name|vhsub_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vhsub_u16
end_comment

begin_comment
comment|// CHECK: vhsub.u16 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint16x4_t
name|test_vhsub_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|)
block|{
return|return
name|vhsub_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vhsub_u32
end_comment

begin_comment
comment|// CHECK: vhsub.u32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint32x2_t
name|test_vhsub_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|)
block|{
return|return
name|vhsub_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vhsubq_s8
end_comment

begin_comment
comment|// CHECK: vhsub.s8 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int8x16_t
name|test_vhsubq_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|)
block|{
return|return
name|vhsubq_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vhsubq_s16
end_comment

begin_comment
comment|// CHECK: vhsub.s16 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int16x8_t
name|test_vhsubq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
return|return
name|vhsubq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vhsubq_s32
end_comment

begin_comment
comment|// CHECK: vhsub.s32 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int32x4_t
name|test_vhsubq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
return|return
name|vhsubq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vhsubq_u8
end_comment

begin_comment
comment|// CHECK: vhsub.u8 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint8x16_t
name|test_vhsubq_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|,
name|uint8x16_t
name|b
parameter_list|)
block|{
return|return
name|vhsubq_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vhsubq_u16
end_comment

begin_comment
comment|// CHECK: vhsub.u16 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint16x8_t
name|test_vhsubq_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|)
block|{
return|return
name|vhsubq_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vhsubq_u32
end_comment

begin_comment
comment|// CHECK: vhsub.u32 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint32x4_t
name|test_vhsubq_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|)
block|{
return|return
name|vhsubq_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld1q_u8
end_comment

begin_comment
comment|// CHECK: vld1.8 {d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|uint8x16_t
name|test_vld1q_u8
parameter_list|(
name|uint8_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld1q_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld1q_u16
end_comment

begin_comment
comment|// CHECK: vld1.16 {d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|uint16x8_t
name|test_vld1q_u16
parameter_list|(
name|uint16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld1q_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld1q_u32
end_comment

begin_comment
comment|// CHECK: vld1.32 {d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|uint32x4_t
name|test_vld1q_u32
parameter_list|(
name|uint32_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld1q_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld1q_u64
end_comment

begin_comment
comment|// CHECK: vld1.64 {d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}{{(:64)?}}]
end_comment

begin_function
name|uint64x2_t
name|test_vld1q_u64
parameter_list|(
name|uint64_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld1q_u64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld1q_s8
end_comment

begin_comment
comment|// CHECK: vld1.8 {d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|int8x16_t
name|test_vld1q_s8
parameter_list|(
name|int8_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld1q_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld1q_s16
end_comment

begin_comment
comment|// CHECK: vld1.16 {d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|int16x8_t
name|test_vld1q_s16
parameter_list|(
name|int16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld1q_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld1q_s32
end_comment

begin_comment
comment|// CHECK: vld1.32 {d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|int32x4_t
name|test_vld1q_s32
parameter_list|(
name|int32_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld1q_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld1q_s64
end_comment

begin_comment
comment|// CHECK: vld1.64 {d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}{{(:64)?}}]
end_comment

begin_function
name|int64x2_t
name|test_vld1q_s64
parameter_list|(
name|int64_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld1q_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld1q_f16
end_comment

begin_comment
comment|// CHECK: vld1.16 {d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|float16x8_t
name|test_vld1q_f16
parameter_list|(
name|float16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld1q_f16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld1q_f32
end_comment

begin_comment
comment|// CHECK: vld1.32 {d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|float32x4_t
name|test_vld1q_f32
parameter_list|(
name|float32_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld1q_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld1q_p8
end_comment

begin_comment
comment|// CHECK: vld1.8 {d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|poly8x16_t
name|test_vld1q_p8
parameter_list|(
name|poly8_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld1q_p8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld1q_p16
end_comment

begin_comment
comment|// CHECK: vld1.16 {d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|poly16x8_t
name|test_vld1q_p16
parameter_list|(
name|poly16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld1q_p16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld1_u8
end_comment

begin_comment
comment|// CHECK: vld1.8 {d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|uint8x8_t
name|test_vld1_u8
parameter_list|(
name|uint8_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld1_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld1_u16
end_comment

begin_comment
comment|// CHECK: vld1.16 {d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|uint16x4_t
name|test_vld1_u16
parameter_list|(
name|uint16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld1_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld1_u32
end_comment

begin_comment
comment|// CHECK: vld1.32 {d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|uint32x2_t
name|test_vld1_u32
parameter_list|(
name|uint32_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld1_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld1_u64
end_comment

begin_comment
comment|// CHECK: vld1.64 {d{{[0-9]+}}}, [r{{[0-9]+}}{{(:64)?}}]
end_comment

begin_function
name|uint64x1_t
name|test_vld1_u64
parameter_list|(
name|uint64_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld1_u64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld1_s8
end_comment

begin_comment
comment|// CHECK: vld1.8 {d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|int8x8_t
name|test_vld1_s8
parameter_list|(
name|int8_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld1_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld1_s16
end_comment

begin_comment
comment|// CHECK: vld1.16 {d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|int16x4_t
name|test_vld1_s16
parameter_list|(
name|int16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld1_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld1_s32
end_comment

begin_comment
comment|// CHECK: vld1.32 {d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|int32x2_t
name|test_vld1_s32
parameter_list|(
name|int32_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld1_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld1_s64
end_comment

begin_comment
comment|// CHECK: vld1.64 {d{{[0-9]+}}}, [r{{[0-9]+}}{{(:64)?}}]
end_comment

begin_function
name|int64x1_t
name|test_vld1_s64
parameter_list|(
name|int64_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld1_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld1_f16
end_comment

begin_comment
comment|// CHECK: vld1.16 {d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|float16x4_t
name|test_vld1_f16
parameter_list|(
name|float16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld1_f16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld1_f32
end_comment

begin_comment
comment|// CHECK: vld1.32 {d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|float32x2_t
name|test_vld1_f32
parameter_list|(
name|float32_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld1_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld1_p8
end_comment

begin_comment
comment|// CHECK: vld1.8 {d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|poly8x8_t
name|test_vld1_p8
parameter_list|(
name|poly8_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld1_p8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld1_p16
end_comment

begin_comment
comment|// CHECK: vld1.16 {d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|poly16x4_t
name|test_vld1_p16
parameter_list|(
name|poly16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld1_p16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld1q_dup_u8
end_comment

begin_comment
comment|// CHECK: vld1.8 {d{{[0-9]+}}[], d{{[0-9]+}}[]}, [r{{[0-9]+}}]
end_comment

begin_function
name|uint8x16_t
name|test_vld1q_dup_u8
parameter_list|(
name|uint8_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld1q_dup_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld1q_dup_u16
end_comment

begin_comment
comment|// CHECK: vld1.16 {d{{[0-9]+}}[], d{{[0-9]+}}[]}, [r{{[0-9]+}}:16]
end_comment

begin_function
name|uint16x8_t
name|test_vld1q_dup_u16
parameter_list|(
name|uint16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld1q_dup_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld1q_dup_u32
end_comment

begin_comment
comment|// CHECK: vld1.32 {d{{[0-9]+}}[], d{{[0-9]+}}[]}, [r{{[0-9]+}}:32]
end_comment

begin_function
name|uint32x4_t
name|test_vld1q_dup_u32
parameter_list|(
name|uint32_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld1q_dup_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld1q_dup_u64
end_comment

begin_comment
comment|// CHECK: {{ldr|vldr|vmov}}
end_comment

begin_function
name|uint64x2_t
name|test_vld1q_dup_u64
parameter_list|(
name|uint64_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld1q_dup_u64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld1q_dup_s8
end_comment

begin_comment
comment|// CHECK: vld1.8 {d{{[0-9]+}}[], d{{[0-9]+}}[]}, [r{{[0-9]+}}]
end_comment

begin_function
name|int8x16_t
name|test_vld1q_dup_s8
parameter_list|(
name|int8_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld1q_dup_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld1q_dup_s16
end_comment

begin_comment
comment|// CHECK: vld1.16 {d{{[0-9]+}}[], d{{[0-9]+}}[]}, [r{{[0-9]+}}:16]
end_comment

begin_function
name|int16x8_t
name|test_vld1q_dup_s16
parameter_list|(
name|int16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld1q_dup_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld1q_dup_s32
end_comment

begin_comment
comment|// CHECK: vld1.32 {d{{[0-9]+}}[], d{{[0-9]+}}[]}, [r{{[0-9]+}}:32]
end_comment

begin_function
name|int32x4_t
name|test_vld1q_dup_s32
parameter_list|(
name|int32_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld1q_dup_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld1q_dup_s64
end_comment

begin_comment
comment|// CHECK: {{ldr|vldr|vmov}}
end_comment

begin_function
name|int64x2_t
name|test_vld1q_dup_s64
parameter_list|(
name|int64_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld1q_dup_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld1q_dup_f16
end_comment

begin_comment
comment|// CHECK: vld1.16 {d{{[0-9]+}}[], d{{[0-9]+}}[]}, [r{{[0-9]+}}:16]
end_comment

begin_function
name|float16x8_t
name|test_vld1q_dup_f16
parameter_list|(
name|float16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld1q_dup_f16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld1q_dup_f32
end_comment

begin_comment
comment|// CHECK: vld1.32 {d{{[0-9]+}}[], d{{[0-9]+}}[]}, [r{{[0-9]+}}:32]
end_comment

begin_function
name|float32x4_t
name|test_vld1q_dup_f32
parameter_list|(
name|float32_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld1q_dup_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld1q_dup_p8
end_comment

begin_comment
comment|// CHECK: vld1.8 {d{{[0-9]+}}[], d{{[0-9]+}}[]}, [r{{[0-9]+}}]
end_comment

begin_function
name|poly8x16_t
name|test_vld1q_dup_p8
parameter_list|(
name|poly8_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld1q_dup_p8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld1q_dup_p16
end_comment

begin_comment
comment|// CHECK: vld1.16 {d{{[0-9]+}}[], d{{[0-9]+}}[]}, [r{{[0-9]+}}:16]
end_comment

begin_function
name|poly16x8_t
name|test_vld1q_dup_p16
parameter_list|(
name|poly16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld1q_dup_p16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld1_dup_u8
end_comment

begin_comment
comment|// CHECK: vld1.8 {d{{[0-9]+}}[]}, [r{{[0-9]+}}]
end_comment

begin_function
name|uint8x8_t
name|test_vld1_dup_u8
parameter_list|(
name|uint8_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld1_dup_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld1_dup_u16
end_comment

begin_comment
comment|// CHECK: vld1.16 {d{{[0-9]+}}[]}, [r{{[0-9]+}}:16]
end_comment

begin_function
name|uint16x4_t
name|test_vld1_dup_u16
parameter_list|(
name|uint16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld1_dup_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld1_dup_u32
end_comment

begin_comment
comment|// CHECK: vld1.32 {d{{[0-9]+}}[]}, [r{{[0-9]+}}:32]
end_comment

begin_function
name|uint32x2_t
name|test_vld1_dup_u32
parameter_list|(
name|uint32_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld1_dup_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld1_dup_u64
end_comment

begin_comment
comment|// CHECK: {{ldr|vldr|vmov}}
end_comment

begin_function
name|uint64x1_t
name|test_vld1_dup_u64
parameter_list|(
name|uint64_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld1_dup_u64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld1_dup_s8
end_comment

begin_comment
comment|// CHECK: vld1.8 {d{{[0-9]+}}[]}, [r{{[0-9]+}}]
end_comment

begin_function
name|int8x8_t
name|test_vld1_dup_s8
parameter_list|(
name|int8_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld1_dup_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld1_dup_s16
end_comment

begin_comment
comment|// CHECK: vld1.16 {d{{[0-9]+}}[]}, [r{{[0-9]+}}:16]
end_comment

begin_function
name|int16x4_t
name|test_vld1_dup_s16
parameter_list|(
name|int16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld1_dup_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld1_dup_s32
end_comment

begin_comment
comment|// CHECK: vld1.32 {d{{[0-9]+}}[]}, [r{{[0-9]+}}:32]
end_comment

begin_function
name|int32x2_t
name|test_vld1_dup_s32
parameter_list|(
name|int32_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld1_dup_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld1_dup_s64
end_comment

begin_comment
comment|// CHECK: {{ldr|vldr|vmov}}
end_comment

begin_function
name|int64x1_t
name|test_vld1_dup_s64
parameter_list|(
name|int64_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld1_dup_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld1_dup_f16
end_comment

begin_comment
comment|// CHECK: vld1.16 {d{{[0-9]+}}[]}, [r{{[0-9]+}}:16]
end_comment

begin_function
name|float16x4_t
name|test_vld1_dup_f16
parameter_list|(
name|float16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld1_dup_f16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld1_dup_f32
end_comment

begin_comment
comment|// CHECK: vld1.32 {d{{[0-9]+}}[]}, [r{{[0-9]+}}:32]
end_comment

begin_function
name|float32x2_t
name|test_vld1_dup_f32
parameter_list|(
name|float32_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld1_dup_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld1_dup_p8
end_comment

begin_comment
comment|// CHECK: vld1.8 {d{{[0-9]+}}[]}, [r{{[0-9]+}}]
end_comment

begin_function
name|poly8x8_t
name|test_vld1_dup_p8
parameter_list|(
name|poly8_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld1_dup_p8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld1_dup_p16
end_comment

begin_comment
comment|// CHECK: vld1.16 {d{{[0-9]+}}[]}, [r{{[0-9]+}}:16]
end_comment

begin_function
name|poly16x4_t
name|test_vld1_dup_p16
parameter_list|(
name|poly16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld1_dup_p16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld1q_lane_u8
end_comment

begin_comment
comment|// CHECK: vld1.8 {d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}]
end_comment

begin_function
name|uint8x16_t
name|test_vld1q_lane_u8
parameter_list|(
name|uint8_t
specifier|const
modifier|*
name|a
parameter_list|,
name|uint8x16_t
name|b
parameter_list|)
block|{
return|return
name|vld1q_lane_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|15
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld1q_lane_u16
end_comment

begin_comment
comment|// CHECK: vld1.16 {d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}:16]
end_comment

begin_function
name|uint16x8_t
name|test_vld1q_lane_u16
parameter_list|(
name|uint16_t
specifier|const
modifier|*
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|)
block|{
return|return
name|vld1q_lane_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld1q_lane_u32
end_comment

begin_comment
comment|// CHECK: vld1.32 {d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}:32]
end_comment

begin_function
name|uint32x4_t
name|test_vld1q_lane_u32
parameter_list|(
name|uint32_t
specifier|const
modifier|*
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|)
block|{
return|return
name|vld1q_lane_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld1q_lane_u64
end_comment

begin_comment
comment|// CHECK: {{ldr|vldr|vmov}}
end_comment

begin_function
name|uint64x2_t
name|test_vld1q_lane_u64
parameter_list|(
name|uint64_t
specifier|const
modifier|*
name|a
parameter_list|,
name|uint64x2_t
name|b
parameter_list|)
block|{
return|return
name|vld1q_lane_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld1q_lane_s8
end_comment

begin_comment
comment|// CHECK: vld1.8 {d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}]
end_comment

begin_function
name|int8x16_t
name|test_vld1q_lane_s8
parameter_list|(
name|int8_t
specifier|const
modifier|*
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|)
block|{
return|return
name|vld1q_lane_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|15
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld1q_lane_s16
end_comment

begin_comment
comment|// CHECK: vld1.16 {d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}:16]
end_comment

begin_function
name|int16x8_t
name|test_vld1q_lane_s16
parameter_list|(
name|int16_t
specifier|const
modifier|*
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
return|return
name|vld1q_lane_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld1q_lane_s32
end_comment

begin_comment
comment|// CHECK: vld1.32 {d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}:32]
end_comment

begin_function
name|int32x4_t
name|test_vld1q_lane_s32
parameter_list|(
name|int32_t
specifier|const
modifier|*
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
return|return
name|vld1q_lane_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld1q_lane_s64
end_comment

begin_comment
comment|// CHECK: {{ldr|vldr|vmov}}
end_comment

begin_function
name|int64x2_t
name|test_vld1q_lane_s64
parameter_list|(
name|int64_t
specifier|const
modifier|*
name|a
parameter_list|,
name|int64x2_t
name|b
parameter_list|)
block|{
return|return
name|vld1q_lane_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld1q_lane_f16
end_comment

begin_comment
comment|// CHECK: vld1.16 {d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}:16]
end_comment

begin_function
name|float16x8_t
name|test_vld1q_lane_f16
parameter_list|(
name|float16_t
specifier|const
modifier|*
name|a
parameter_list|,
name|float16x8_t
name|b
parameter_list|)
block|{
return|return
name|vld1q_lane_f16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld1q_lane_f32
end_comment

begin_comment
comment|// CHECK: vld1.32 {d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}:32]
end_comment

begin_function
name|float32x4_t
name|test_vld1q_lane_f32
parameter_list|(
name|float32_t
specifier|const
modifier|*
name|a
parameter_list|,
name|float32x4_t
name|b
parameter_list|)
block|{
return|return
name|vld1q_lane_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld1q_lane_p8
end_comment

begin_comment
comment|// CHECK: vld1.8 {d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}]
end_comment

begin_function
name|poly8x16_t
name|test_vld1q_lane_p8
parameter_list|(
name|poly8_t
specifier|const
modifier|*
name|a
parameter_list|,
name|poly8x16_t
name|b
parameter_list|)
block|{
return|return
name|vld1q_lane_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|15
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld1q_lane_p16
end_comment

begin_comment
comment|// CHECK: vld1.16 {d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}:16]
end_comment

begin_function
name|poly16x8_t
name|test_vld1q_lane_p16
parameter_list|(
name|poly16_t
specifier|const
modifier|*
name|a
parameter_list|,
name|poly16x8_t
name|b
parameter_list|)
block|{
return|return
name|vld1q_lane_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld1_lane_u8
end_comment

begin_comment
comment|// CHECK: vld1.8 {d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}]
end_comment

begin_function
name|uint8x8_t
name|test_vld1_lane_u8
parameter_list|(
name|uint8_t
specifier|const
modifier|*
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|)
block|{
return|return
name|vld1_lane_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld1_lane_u16
end_comment

begin_comment
comment|// CHECK: vld1.16 {d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}:16]
end_comment

begin_function
name|uint16x4_t
name|test_vld1_lane_u16
parameter_list|(
name|uint16_t
specifier|const
modifier|*
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|)
block|{
return|return
name|vld1_lane_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld1_lane_u32
end_comment

begin_comment
comment|// CHECK: vld1.32 {d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}:32]
end_comment

begin_function
name|uint32x2_t
name|test_vld1_lane_u32
parameter_list|(
name|uint32_t
specifier|const
modifier|*
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|)
block|{
return|return
name|vld1_lane_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld1_lane_u64
end_comment

begin_comment
comment|// CHECK: {{ldr|vldr|vmov}}
end_comment

begin_function
name|uint64x1_t
name|test_vld1_lane_u64
parameter_list|(
name|uint64_t
specifier|const
modifier|*
name|a
parameter_list|,
name|uint64x1_t
name|b
parameter_list|)
block|{
return|return
name|vld1_lane_u64
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

begin_comment
comment|// CHECK-LABEL: test_vld1_lane_s8
end_comment

begin_comment
comment|// CHECK: vld1.8 {d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}]
end_comment

begin_function
name|int8x8_t
name|test_vld1_lane_s8
parameter_list|(
name|int8_t
specifier|const
modifier|*
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
return|return
name|vld1_lane_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld1_lane_s16
end_comment

begin_comment
comment|// CHECK: vld1.16 {d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}:16]
end_comment

begin_function
name|int16x4_t
name|test_vld1_lane_s16
parameter_list|(
name|int16_t
specifier|const
modifier|*
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
return|return
name|vld1_lane_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld1_lane_s32
end_comment

begin_comment
comment|// CHECK: vld1.32 {d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}:32]
end_comment

begin_function
name|int32x2_t
name|test_vld1_lane_s32
parameter_list|(
name|int32_t
specifier|const
modifier|*
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
return|return
name|vld1_lane_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld1_lane_s64
end_comment

begin_comment
comment|// CHECK: {{ldr|vldr|vmov}}
end_comment

begin_function
name|int64x1_t
name|test_vld1_lane_s64
parameter_list|(
name|int64_t
specifier|const
modifier|*
name|a
parameter_list|,
name|int64x1_t
name|b
parameter_list|)
block|{
return|return
name|vld1_lane_s64
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

begin_comment
comment|// CHECK-LABEL: test_vld1_lane_f16
end_comment

begin_comment
comment|// CHECK: vld1.16 {d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}:16]
end_comment

begin_function
name|float16x4_t
name|test_vld1_lane_f16
parameter_list|(
name|float16_t
specifier|const
modifier|*
name|a
parameter_list|,
name|float16x4_t
name|b
parameter_list|)
block|{
return|return
name|vld1_lane_f16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld1_lane_f32
end_comment

begin_comment
comment|// CHECK: vld1.32 {d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}:32]
end_comment

begin_function
name|float32x2_t
name|test_vld1_lane_f32
parameter_list|(
name|float32_t
specifier|const
modifier|*
name|a
parameter_list|,
name|float32x2_t
name|b
parameter_list|)
block|{
return|return
name|vld1_lane_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld1_lane_p8
end_comment

begin_comment
comment|// CHECK: vld1.8 {d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}]
end_comment

begin_function
name|poly8x8_t
name|test_vld1_lane_p8
parameter_list|(
name|poly8_t
specifier|const
modifier|*
name|a
parameter_list|,
name|poly8x8_t
name|b
parameter_list|)
block|{
return|return
name|vld1_lane_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld1_lane_p16
end_comment

begin_comment
comment|// CHECK: vld1.16 {d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}:16]
end_comment

begin_function
name|poly16x4_t
name|test_vld1_lane_p16
parameter_list|(
name|poly16_t
specifier|const
modifier|*
name|a
parameter_list|,
name|poly16x4_t
name|b
parameter_list|)
block|{
return|return
name|vld1_lane_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld2q_u8
end_comment

begin_comment
comment|// CHECK: vld2.8 {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|uint8x16x2_t
name|test_vld2q_u8
parameter_list|(
name|uint8_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld2q_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld2q_u16
end_comment

begin_comment
comment|// CHECK: vld2.16 {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|uint16x8x2_t
name|test_vld2q_u16
parameter_list|(
name|uint16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld2q_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld2q_u32
end_comment

begin_comment
comment|// CHECK: vld2.32 {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|uint32x4x2_t
name|test_vld2q_u32
parameter_list|(
name|uint32_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld2q_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld2q_s8
end_comment

begin_comment
comment|// CHECK: vld2.8 {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|int8x16x2_t
name|test_vld2q_s8
parameter_list|(
name|int8_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld2q_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld2q_s16
end_comment

begin_comment
comment|// CHECK: vld2.16 {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|int16x8x2_t
name|test_vld2q_s16
parameter_list|(
name|int16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld2q_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld2q_s32
end_comment

begin_comment
comment|// CHECK: vld2.32 {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|int32x4x2_t
name|test_vld2q_s32
parameter_list|(
name|int32_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld2q_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld2q_f16
end_comment

begin_comment
comment|// CHECK: vld2.16 {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|float16x8x2_t
name|test_vld2q_f16
parameter_list|(
name|float16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld2q_f16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld2q_f32
end_comment

begin_comment
comment|// CHECK: vld2.32 {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|float32x4x2_t
name|test_vld2q_f32
parameter_list|(
name|float32_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld2q_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld2q_p8
end_comment

begin_comment
comment|// CHECK: vld2.8 {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|poly8x16x2_t
name|test_vld2q_p8
parameter_list|(
name|poly8_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld2q_p8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld2q_p16
end_comment

begin_comment
comment|// CHECK: vld2.16 {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|poly16x8x2_t
name|test_vld2q_p16
parameter_list|(
name|poly16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld2q_p16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld2_u8
end_comment

begin_comment
comment|// CHECK: vld2.8 {d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|uint8x8x2_t
name|test_vld2_u8
parameter_list|(
name|uint8_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld2_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld2_u16
end_comment

begin_comment
comment|// CHECK: vld2.16 {d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|uint16x4x2_t
name|test_vld2_u16
parameter_list|(
name|uint16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld2_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld2_u32
end_comment

begin_comment
comment|// CHECK: vld2.32 {d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|uint32x2x2_t
name|test_vld2_u32
parameter_list|(
name|uint32_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld2_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld2_u64
end_comment

begin_comment
comment|// CHECK: vld1.64
end_comment

begin_function
name|uint64x1x2_t
name|test_vld2_u64
parameter_list|(
name|uint64_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld2_u64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld2_s8
end_comment

begin_comment
comment|// CHECK: vld2.8 {d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|int8x8x2_t
name|test_vld2_s8
parameter_list|(
name|int8_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld2_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld2_s16
end_comment

begin_comment
comment|// CHECK: vld2.16 {d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|int16x4x2_t
name|test_vld2_s16
parameter_list|(
name|int16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld2_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld2_s32
end_comment

begin_comment
comment|// CHECK: vld2.32 {d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|int32x2x2_t
name|test_vld2_s32
parameter_list|(
name|int32_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld2_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld2_s64
end_comment

begin_comment
comment|// CHECK: vld1.64
end_comment

begin_function
name|int64x1x2_t
name|test_vld2_s64
parameter_list|(
name|int64_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld2_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld2_f16
end_comment

begin_comment
comment|// CHECK: vld2.16 {d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|float16x4x2_t
name|test_vld2_f16
parameter_list|(
name|float16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld2_f16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld2_f32
end_comment

begin_comment
comment|// CHECK: vld2.32 {d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|float32x2x2_t
name|test_vld2_f32
parameter_list|(
name|float32_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld2_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld2_p8
end_comment

begin_comment
comment|// CHECK: vld2.8 {d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|poly8x8x2_t
name|test_vld2_p8
parameter_list|(
name|poly8_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld2_p8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld2_p16
end_comment

begin_comment
comment|// CHECK: vld2.16 {d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|poly16x4x2_t
name|test_vld2_p16
parameter_list|(
name|poly16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld2_p16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld2_dup_u8
end_comment

begin_comment
comment|// CHECK: vld2.8 {d{{[0-9]+}}[], d{{[0-9]+}}[]}, [r{{[0-9]+}}]
end_comment

begin_function
name|uint8x8x2_t
name|test_vld2_dup_u8
parameter_list|(
name|uint8_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld2_dup_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld2_dup_u16
end_comment

begin_comment
comment|// CHECK: vld2.16 {d{{[0-9]+}}[], d{{[0-9]+}}[]}, [r{{[0-9]+}}]
end_comment

begin_function
name|uint16x4x2_t
name|test_vld2_dup_u16
parameter_list|(
name|uint16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld2_dup_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld2_dup_u32
end_comment

begin_comment
comment|// CHECK: vld2.32 {d{{[0-9]+}}[], d{{[0-9]+}}[]}, [r{{[0-9]+}}]
end_comment

begin_function
name|uint32x2x2_t
name|test_vld2_dup_u32
parameter_list|(
name|uint32_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld2_dup_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld2_dup_u64
end_comment

begin_comment
comment|// CHECK: vld1.64
end_comment

begin_function
name|uint64x1x2_t
name|test_vld2_dup_u64
parameter_list|(
name|uint64_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld2_dup_u64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld2_dup_s8
end_comment

begin_comment
comment|// CHECK: vld2.8 {d{{[0-9]+}}[], d{{[0-9]+}}[]}, [r{{[0-9]+}}]
end_comment

begin_function
name|int8x8x2_t
name|test_vld2_dup_s8
parameter_list|(
name|int8_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld2_dup_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld2_dup_s16
end_comment

begin_comment
comment|// CHECK: vld2.16 {d{{[0-9]+}}[], d{{[0-9]+}}[]}, [r{{[0-9]+}}]
end_comment

begin_function
name|int16x4x2_t
name|test_vld2_dup_s16
parameter_list|(
name|int16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld2_dup_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld2_dup_s32
end_comment

begin_comment
comment|// CHECK: vld2.32 {d{{[0-9]+}}[], d{{[0-9]+}}[]}, [r{{[0-9]+}}]
end_comment

begin_function
name|int32x2x2_t
name|test_vld2_dup_s32
parameter_list|(
name|int32_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld2_dup_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld2_dup_s64
end_comment

begin_comment
comment|// CHECK: vld1.64
end_comment

begin_function
name|int64x1x2_t
name|test_vld2_dup_s64
parameter_list|(
name|int64_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld2_dup_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld2_dup_f16
end_comment

begin_comment
comment|// CHECK: vld2.16 {d{{[0-9]+}}[], d{{[0-9]+}}[]}, [r{{[0-9]+}}]
end_comment

begin_function
name|float16x4x2_t
name|test_vld2_dup_f16
parameter_list|(
name|float16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld2_dup_f16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld2_dup_f32
end_comment

begin_comment
comment|// CHECK: vld2.32 {d{{[0-9]+}}[], d{{[0-9]+}}[]}, [r{{[0-9]+}}]
end_comment

begin_function
name|float32x2x2_t
name|test_vld2_dup_f32
parameter_list|(
name|float32_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld2_dup_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld2_dup_p8
end_comment

begin_comment
comment|// CHECK: vld2.8 {d{{[0-9]+}}[], d{{[0-9]+}}[]}, [r{{[0-9]+}}]
end_comment

begin_function
name|poly8x8x2_t
name|test_vld2_dup_p8
parameter_list|(
name|poly8_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld2_dup_p8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld2_dup_p16
end_comment

begin_comment
comment|// CHECK: vld2.16 {d{{[0-9]+}}[], d{{[0-9]+}}[]}, [r{{[0-9]+}}]
end_comment

begin_function
name|poly16x4x2_t
name|test_vld2_dup_p16
parameter_list|(
name|poly16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld2_dup_p16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld2q_lane_u16
end_comment

begin_comment
comment|// CHECK: vld2.16 {d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}]
end_comment

begin_function
name|uint16x8x2_t
name|test_vld2q_lane_u16
parameter_list|(
name|uint16_t
specifier|const
modifier|*
name|a
parameter_list|,
name|uint16x8x2_t
name|b
parameter_list|)
block|{
return|return
name|vld2q_lane_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld2q_lane_u32
end_comment

begin_comment
comment|// CHECK: vld2.32 {d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}]
end_comment

begin_function
name|uint32x4x2_t
name|test_vld2q_lane_u32
parameter_list|(
name|uint32_t
specifier|const
modifier|*
name|a
parameter_list|,
name|uint32x4x2_t
name|b
parameter_list|)
block|{
return|return
name|vld2q_lane_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld2q_lane_s16
end_comment

begin_comment
comment|// CHECK: vld2.16 {d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}]
end_comment

begin_function
name|int16x8x2_t
name|test_vld2q_lane_s16
parameter_list|(
name|int16_t
specifier|const
modifier|*
name|a
parameter_list|,
name|int16x8x2_t
name|b
parameter_list|)
block|{
return|return
name|vld2q_lane_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld2q_lane_s32
end_comment

begin_comment
comment|// CHECK: vld2.32 {d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}]
end_comment

begin_function
name|int32x4x2_t
name|test_vld2q_lane_s32
parameter_list|(
name|int32_t
specifier|const
modifier|*
name|a
parameter_list|,
name|int32x4x2_t
name|b
parameter_list|)
block|{
return|return
name|vld2q_lane_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld2q_lane_f16
end_comment

begin_comment
comment|// CHECK: vld2.16 {d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}]
end_comment

begin_function
name|float16x8x2_t
name|test_vld2q_lane_f16
parameter_list|(
name|float16_t
specifier|const
modifier|*
name|a
parameter_list|,
name|float16x8x2_t
name|b
parameter_list|)
block|{
return|return
name|vld2q_lane_f16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld2q_lane_f32
end_comment

begin_comment
comment|// CHECK: vld2.32 {d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}]
end_comment

begin_function
name|float32x4x2_t
name|test_vld2q_lane_f32
parameter_list|(
name|float32_t
specifier|const
modifier|*
name|a
parameter_list|,
name|float32x4x2_t
name|b
parameter_list|)
block|{
return|return
name|vld2q_lane_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld2q_lane_p16
end_comment

begin_comment
comment|// CHECK: vld2.16 {d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}]
end_comment

begin_function
name|poly16x8x2_t
name|test_vld2q_lane_p16
parameter_list|(
name|poly16_t
specifier|const
modifier|*
name|a
parameter_list|,
name|poly16x8x2_t
name|b
parameter_list|)
block|{
return|return
name|vld2q_lane_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld2_lane_u8
end_comment

begin_comment
comment|// CHECK: vld2.8 {d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}]
end_comment

begin_function
name|uint8x8x2_t
name|test_vld2_lane_u8
parameter_list|(
name|uint8_t
specifier|const
modifier|*
name|a
parameter_list|,
name|uint8x8x2_t
name|b
parameter_list|)
block|{
return|return
name|vld2_lane_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld2_lane_u16
end_comment

begin_comment
comment|// CHECK: vld2.16 {d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}]
end_comment

begin_function
name|uint16x4x2_t
name|test_vld2_lane_u16
parameter_list|(
name|uint16_t
specifier|const
modifier|*
name|a
parameter_list|,
name|uint16x4x2_t
name|b
parameter_list|)
block|{
return|return
name|vld2_lane_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld2_lane_u32
end_comment

begin_comment
comment|// CHECK: vld2.32 {d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}]
end_comment

begin_function
name|uint32x2x2_t
name|test_vld2_lane_u32
parameter_list|(
name|uint32_t
specifier|const
modifier|*
name|a
parameter_list|,
name|uint32x2x2_t
name|b
parameter_list|)
block|{
return|return
name|vld2_lane_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld2_lane_s8
end_comment

begin_comment
comment|// CHECK: vld2.8 {d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}]
end_comment

begin_function
name|int8x8x2_t
name|test_vld2_lane_s8
parameter_list|(
name|int8_t
specifier|const
modifier|*
name|a
parameter_list|,
name|int8x8x2_t
name|b
parameter_list|)
block|{
return|return
name|vld2_lane_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld2_lane_s16
end_comment

begin_comment
comment|// CHECK: vld2.16 {d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}]
end_comment

begin_function
name|int16x4x2_t
name|test_vld2_lane_s16
parameter_list|(
name|int16_t
specifier|const
modifier|*
name|a
parameter_list|,
name|int16x4x2_t
name|b
parameter_list|)
block|{
return|return
name|vld2_lane_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld2_lane_s32
end_comment

begin_comment
comment|// CHECK: vld2.32 {d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}]
end_comment

begin_function
name|int32x2x2_t
name|test_vld2_lane_s32
parameter_list|(
name|int32_t
specifier|const
modifier|*
name|a
parameter_list|,
name|int32x2x2_t
name|b
parameter_list|)
block|{
return|return
name|vld2_lane_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld2_lane_f16
end_comment

begin_comment
comment|// CHECK: vld2.16 {d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}]
end_comment

begin_function
name|float16x4x2_t
name|test_vld2_lane_f16
parameter_list|(
name|float16_t
specifier|const
modifier|*
name|a
parameter_list|,
name|float16x4x2_t
name|b
parameter_list|)
block|{
return|return
name|vld2_lane_f16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld2_lane_f32
end_comment

begin_comment
comment|// CHECK: vld2.32 {d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}]
end_comment

begin_function
name|float32x2x2_t
name|test_vld2_lane_f32
parameter_list|(
name|float32_t
specifier|const
modifier|*
name|a
parameter_list|,
name|float32x2x2_t
name|b
parameter_list|)
block|{
return|return
name|vld2_lane_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld2_lane_p8
end_comment

begin_comment
comment|// CHECK: vld2.8 {d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}]
end_comment

begin_function
name|poly8x8x2_t
name|test_vld2_lane_p8
parameter_list|(
name|poly8_t
specifier|const
modifier|*
name|a
parameter_list|,
name|poly8x8x2_t
name|b
parameter_list|)
block|{
return|return
name|vld2_lane_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld2_lane_p16
end_comment

begin_comment
comment|// CHECK: vld2.16 {d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}]
end_comment

begin_function
name|poly16x4x2_t
name|test_vld2_lane_p16
parameter_list|(
name|poly16_t
specifier|const
modifier|*
name|a
parameter_list|,
name|poly16x4x2_t
name|b
parameter_list|)
block|{
return|return
name|vld2_lane_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld3q_u8
end_comment

begin_comment
comment|// CHECK: vld3.8 {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}
end_comment

begin_function
name|uint8x16x3_t
name|test_vld3q_u8
parameter_list|(
name|uint8_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld3q_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld3q_u16
end_comment

begin_comment
comment|// CHECK: vld3.16 {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}
end_comment

begin_function
name|uint16x8x3_t
name|test_vld3q_u16
parameter_list|(
name|uint16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld3q_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld3q_u32
end_comment

begin_comment
comment|// CHECK: vld3.32 {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}
end_comment

begin_function
name|uint32x4x3_t
name|test_vld3q_u32
parameter_list|(
name|uint32_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld3q_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld3q_s8
end_comment

begin_comment
comment|// CHECK: vld3.8 {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}
end_comment

begin_function
name|int8x16x3_t
name|test_vld3q_s8
parameter_list|(
name|int8_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld3q_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld3q_s16
end_comment

begin_comment
comment|// CHECK: vld3.16 {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}
end_comment

begin_function
name|int16x8x3_t
name|test_vld3q_s16
parameter_list|(
name|int16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld3q_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld3q_s32
end_comment

begin_comment
comment|// CHECK: vld3.32 {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}
end_comment

begin_function
name|int32x4x3_t
name|test_vld3q_s32
parameter_list|(
name|int32_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld3q_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld3q_f16
end_comment

begin_comment
comment|// CHECK: vld3.16 {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}
end_comment

begin_function
name|float16x8x3_t
name|test_vld3q_f16
parameter_list|(
name|float16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld3q_f16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld3q_f32
end_comment

begin_comment
comment|// CHECK: vld3.32 {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}
end_comment

begin_function
name|float32x4x3_t
name|test_vld3q_f32
parameter_list|(
name|float32_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld3q_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld3q_p8
end_comment

begin_comment
comment|// CHECK: vld3.8 {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}
end_comment

begin_function
name|poly8x16x3_t
name|test_vld3q_p8
parameter_list|(
name|poly8_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld3q_p8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld3q_p16
end_comment

begin_comment
comment|// CHECK: vld3.16 {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}
end_comment

begin_function
name|poly16x8x3_t
name|test_vld3q_p16
parameter_list|(
name|poly16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld3q_p16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld3_u8
end_comment

begin_comment
comment|// CHECK: vld3.8 {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|uint8x8x3_t
name|test_vld3_u8
parameter_list|(
name|uint8_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld3_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld3_u16
end_comment

begin_comment
comment|// CHECK: vld3.16 {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|uint16x4x3_t
name|test_vld3_u16
parameter_list|(
name|uint16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld3_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld3_u32
end_comment

begin_comment
comment|// CHECK: vld3.32 {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|uint32x2x3_t
name|test_vld3_u32
parameter_list|(
name|uint32_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld3_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld3_u64
end_comment

begin_comment
comment|// CHECK: vld1.64
end_comment

begin_function
name|uint64x1x3_t
name|test_vld3_u64
parameter_list|(
name|uint64_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld3_u64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld3_s8
end_comment

begin_comment
comment|// CHECK: vld3.8 {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|int8x8x3_t
name|test_vld3_s8
parameter_list|(
name|int8_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld3_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld3_s16
end_comment

begin_comment
comment|// CHECK: vld3.16 {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|int16x4x3_t
name|test_vld3_s16
parameter_list|(
name|int16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld3_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld3_s32
end_comment

begin_comment
comment|// CHECK: vld3.32 {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|int32x2x3_t
name|test_vld3_s32
parameter_list|(
name|int32_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld3_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld3_s64
end_comment

begin_comment
comment|// CHECK: vld1.64
end_comment

begin_function
name|int64x1x3_t
name|test_vld3_s64
parameter_list|(
name|int64_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld3_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld3_f16
end_comment

begin_comment
comment|// CHECK: vld3.16 {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|float16x4x3_t
name|test_vld3_f16
parameter_list|(
name|float16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld3_f16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld3_f32
end_comment

begin_comment
comment|// CHECK: vld3.32 {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|float32x2x3_t
name|test_vld3_f32
parameter_list|(
name|float32_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld3_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld3_p8
end_comment

begin_comment
comment|// CHECK: vld3.8 {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|poly8x8x3_t
name|test_vld3_p8
parameter_list|(
name|poly8_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld3_p8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld3_p16
end_comment

begin_comment
comment|// CHECK: vld3.16 {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|poly16x4x3_t
name|test_vld3_p16
parameter_list|(
name|poly16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld3_p16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld3_dup_u8
end_comment

begin_comment
comment|// CHECK: vld3.8 {d{{[0-9]+}}[], d{{[0-9]+}}[], d{{[0-9]+}}[]}, [r{{[0-9]+}}]
end_comment

begin_function
name|uint8x8x3_t
name|test_vld3_dup_u8
parameter_list|(
name|uint8_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld3_dup_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld3_dup_u16
end_comment

begin_comment
comment|// CHECK: vld3.16 {d{{[0-9]+}}[], d{{[0-9]+}}[], d{{[0-9]+}}[]}, [r{{[0-9]+}}]
end_comment

begin_function
name|uint16x4x3_t
name|test_vld3_dup_u16
parameter_list|(
name|uint16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld3_dup_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld3_dup_u32
end_comment

begin_comment
comment|// CHECK: vld3.32 {d{{[0-9]+}}[], d{{[0-9]+}}[], d{{[0-9]+}}[]}, [r{{[0-9]+}}]
end_comment

begin_function
name|uint32x2x3_t
name|test_vld3_dup_u32
parameter_list|(
name|uint32_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld3_dup_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld3_dup_u64
end_comment

begin_comment
comment|// CHECK: vld1.64
end_comment

begin_function
name|uint64x1x3_t
name|test_vld3_dup_u64
parameter_list|(
name|uint64_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld3_dup_u64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld3_dup_s8
end_comment

begin_comment
comment|// CHECK: vld3.8 {d{{[0-9]+}}[], d{{[0-9]+}}[], d{{[0-9]+}}[]}, [r{{[0-9]+}}]
end_comment

begin_function
name|int8x8x3_t
name|test_vld3_dup_s8
parameter_list|(
name|int8_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld3_dup_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld3_dup_s16
end_comment

begin_comment
comment|// CHECK: vld3.16 {d{{[0-9]+}}[], d{{[0-9]+}}[], d{{[0-9]+}}[]}, [r{{[0-9]+}}]
end_comment

begin_function
name|int16x4x3_t
name|test_vld3_dup_s16
parameter_list|(
name|int16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld3_dup_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld3_dup_s32
end_comment

begin_comment
comment|// CHECK: vld3.32 {d{{[0-9]+}}[], d{{[0-9]+}}[], d{{[0-9]+}}[]}, [r{{[0-9]+}}]
end_comment

begin_function
name|int32x2x3_t
name|test_vld3_dup_s32
parameter_list|(
name|int32_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld3_dup_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld3_dup_s64
end_comment

begin_comment
comment|// CHECK: vld1.64
end_comment

begin_function
name|int64x1x3_t
name|test_vld3_dup_s64
parameter_list|(
name|int64_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld3_dup_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld3_dup_f16
end_comment

begin_comment
comment|// CHECK: vld3.16 {d{{[0-9]+}}[], d{{[0-9]+}}[], d{{[0-9]+}}[]}, [r{{[0-9]+}}]
end_comment

begin_function
name|float16x4x3_t
name|test_vld3_dup_f16
parameter_list|(
name|float16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld3_dup_f16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld3_dup_f32
end_comment

begin_comment
comment|// CHECK: vld3.32 {d{{[0-9]+}}[], d{{[0-9]+}}[], d{{[0-9]+}}[]}, [r{{[0-9]+}}]
end_comment

begin_function
name|float32x2x3_t
name|test_vld3_dup_f32
parameter_list|(
name|float32_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld3_dup_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld3_dup_p8
end_comment

begin_comment
comment|// CHECK: vld3.8 {d{{[0-9]+}}[], d{{[0-9]+}}[], d{{[0-9]+}}[]}, [r{{[0-9]+}}]
end_comment

begin_function
name|poly8x8x3_t
name|test_vld3_dup_p8
parameter_list|(
name|poly8_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld3_dup_p8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld3_dup_p16
end_comment

begin_comment
comment|// CHECK: vld3.16 {d{{[0-9]+}}[], d{{[0-9]+}}[], d{{[0-9]+}}[]}, [r{{[0-9]+}}]
end_comment

begin_function
name|poly16x4x3_t
name|test_vld3_dup_p16
parameter_list|(
name|poly16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld3_dup_p16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld3q_lane_u16
end_comment

begin_comment
comment|// CHECK: vld3.16 {d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}]}
end_comment

begin_function
name|uint16x8x3_t
name|test_vld3q_lane_u16
parameter_list|(
name|uint16_t
specifier|const
modifier|*
name|a
parameter_list|,
name|uint16x8x3_t
name|b
parameter_list|)
block|{
return|return
name|vld3q_lane_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld3q_lane_u32
end_comment

begin_comment
comment|// CHECK: vld3.32 {d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}]}
end_comment

begin_function
name|uint32x4x3_t
name|test_vld3q_lane_u32
parameter_list|(
name|uint32_t
specifier|const
modifier|*
name|a
parameter_list|,
name|uint32x4x3_t
name|b
parameter_list|)
block|{
return|return
name|vld3q_lane_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld3q_lane_s16
end_comment

begin_comment
comment|// CHECK: vld3.16 {d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}]}
end_comment

begin_function
name|int16x8x3_t
name|test_vld3q_lane_s16
parameter_list|(
name|int16_t
specifier|const
modifier|*
name|a
parameter_list|,
name|int16x8x3_t
name|b
parameter_list|)
block|{
return|return
name|vld3q_lane_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld3q_lane_s32
end_comment

begin_comment
comment|// CHECK: vld3.32 {d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}]}
end_comment

begin_function
name|int32x4x3_t
name|test_vld3q_lane_s32
parameter_list|(
name|int32_t
specifier|const
modifier|*
name|a
parameter_list|,
name|int32x4x3_t
name|b
parameter_list|)
block|{
return|return
name|vld3q_lane_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld3q_lane_f16
end_comment

begin_comment
comment|// CHECK: vld3.16 {d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}]}
end_comment

begin_function
name|float16x8x3_t
name|test_vld3q_lane_f16
parameter_list|(
name|float16_t
specifier|const
modifier|*
name|a
parameter_list|,
name|float16x8x3_t
name|b
parameter_list|)
block|{
return|return
name|vld3q_lane_f16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld3q_lane_f32
end_comment

begin_comment
comment|// CHECK: vld3.32 {d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}]}
end_comment

begin_function
name|float32x4x3_t
name|test_vld3q_lane_f32
parameter_list|(
name|float32_t
specifier|const
modifier|*
name|a
parameter_list|,
name|float32x4x3_t
name|b
parameter_list|)
block|{
return|return
name|vld3q_lane_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld3q_lane_p16
end_comment

begin_comment
comment|// CHECK: vld3.16 {d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}]}
end_comment

begin_function
name|poly16x8x3_t
name|test_vld3q_lane_p16
parameter_list|(
name|poly16_t
specifier|const
modifier|*
name|a
parameter_list|,
name|poly16x8x3_t
name|b
parameter_list|)
block|{
return|return
name|vld3q_lane_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld3_lane_u8
end_comment

begin_comment
comment|// CHECK: vld3.8 {d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}]
end_comment

begin_function
name|uint8x8x3_t
name|test_vld3_lane_u8
parameter_list|(
name|uint8_t
specifier|const
modifier|*
name|a
parameter_list|,
name|uint8x8x3_t
name|b
parameter_list|)
block|{
return|return
name|vld3_lane_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld3_lane_u16
end_comment

begin_comment
comment|// CHECK: vld3.16 {d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}]
end_comment

begin_function
name|uint16x4x3_t
name|test_vld3_lane_u16
parameter_list|(
name|uint16_t
specifier|const
modifier|*
name|a
parameter_list|,
name|uint16x4x3_t
name|b
parameter_list|)
block|{
return|return
name|vld3_lane_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld3_lane_u32
end_comment

begin_comment
comment|// CHECK: vld3.32 {d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}]
end_comment

begin_function
name|uint32x2x3_t
name|test_vld3_lane_u32
parameter_list|(
name|uint32_t
specifier|const
modifier|*
name|a
parameter_list|,
name|uint32x2x3_t
name|b
parameter_list|)
block|{
return|return
name|vld3_lane_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld3_lane_s8
end_comment

begin_comment
comment|// CHECK: vld3.8 {d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}]
end_comment

begin_function
name|int8x8x3_t
name|test_vld3_lane_s8
parameter_list|(
name|int8_t
specifier|const
modifier|*
name|a
parameter_list|,
name|int8x8x3_t
name|b
parameter_list|)
block|{
return|return
name|vld3_lane_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld3_lane_s16
end_comment

begin_comment
comment|// CHECK: vld3.16 {d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}]
end_comment

begin_function
name|int16x4x3_t
name|test_vld3_lane_s16
parameter_list|(
name|int16_t
specifier|const
modifier|*
name|a
parameter_list|,
name|int16x4x3_t
name|b
parameter_list|)
block|{
return|return
name|vld3_lane_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld3_lane_s32
end_comment

begin_comment
comment|// CHECK: vld3.32 {d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}]
end_comment

begin_function
name|int32x2x3_t
name|test_vld3_lane_s32
parameter_list|(
name|int32_t
specifier|const
modifier|*
name|a
parameter_list|,
name|int32x2x3_t
name|b
parameter_list|)
block|{
return|return
name|vld3_lane_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld3_lane_f16
end_comment

begin_comment
comment|// CHECK: vld3.16 {d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}]
end_comment

begin_function
name|float16x4x3_t
name|test_vld3_lane_f16
parameter_list|(
name|float16_t
specifier|const
modifier|*
name|a
parameter_list|,
name|float16x4x3_t
name|b
parameter_list|)
block|{
return|return
name|vld3_lane_f16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld3_lane_f32
end_comment

begin_comment
comment|// CHECK: vld3.32 {d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}]
end_comment

begin_function
name|float32x2x3_t
name|test_vld3_lane_f32
parameter_list|(
name|float32_t
specifier|const
modifier|*
name|a
parameter_list|,
name|float32x2x3_t
name|b
parameter_list|)
block|{
return|return
name|vld3_lane_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld3_lane_p8
end_comment

begin_comment
comment|// CHECK: vld3.8 {d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}]
end_comment

begin_function
name|poly8x8x3_t
name|test_vld3_lane_p8
parameter_list|(
name|poly8_t
specifier|const
modifier|*
name|a
parameter_list|,
name|poly8x8x3_t
name|b
parameter_list|)
block|{
return|return
name|vld3_lane_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld3_lane_p16
end_comment

begin_comment
comment|// CHECK: vld3.16 {d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}]
end_comment

begin_function
name|poly16x4x3_t
name|test_vld3_lane_p16
parameter_list|(
name|poly16_t
specifier|const
modifier|*
name|a
parameter_list|,
name|poly16x4x3_t
name|b
parameter_list|)
block|{
return|return
name|vld3_lane_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld4q_u8
end_comment

begin_comment
comment|// CHECK: vld4.8 {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}
end_comment

begin_function
name|uint8x16x4_t
name|test_vld4q_u8
parameter_list|(
name|uint8_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld4q_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld4q_u16
end_comment

begin_comment
comment|// CHECK: vld4.16 {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}
end_comment

begin_function
name|uint16x8x4_t
name|test_vld4q_u16
parameter_list|(
name|uint16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld4q_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld4q_u32
end_comment

begin_comment
comment|// CHECK: vld4.32 {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}
end_comment

begin_function
name|uint32x4x4_t
name|test_vld4q_u32
parameter_list|(
name|uint32_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld4q_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld4q_s8
end_comment

begin_comment
comment|// CHECK: vld4.8 {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}
end_comment

begin_function
name|int8x16x4_t
name|test_vld4q_s8
parameter_list|(
name|int8_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld4q_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld4q_s16
end_comment

begin_comment
comment|// CHECK: vld4.16 {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}
end_comment

begin_function
name|int16x8x4_t
name|test_vld4q_s16
parameter_list|(
name|int16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld4q_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld4q_s32
end_comment

begin_comment
comment|// CHECK: vld4.32 {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}
end_comment

begin_function
name|int32x4x4_t
name|test_vld4q_s32
parameter_list|(
name|int32_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld4q_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld4q_f16
end_comment

begin_comment
comment|// CHECK: vld4.16 {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}
end_comment

begin_function
name|float16x8x4_t
name|test_vld4q_f16
parameter_list|(
name|float16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld4q_f16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld4q_f32
end_comment

begin_comment
comment|// CHECK: vld4.32 {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}
end_comment

begin_function
name|float32x4x4_t
name|test_vld4q_f32
parameter_list|(
name|float32_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld4q_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld4q_p8
end_comment

begin_comment
comment|// CHECK: vld4.8 {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}
end_comment

begin_function
name|poly8x16x4_t
name|test_vld4q_p8
parameter_list|(
name|poly8_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld4q_p8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld4q_p16
end_comment

begin_comment
comment|// CHECK: vld4.16 {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}
end_comment

begin_function
name|poly16x8x4_t
name|test_vld4q_p16
parameter_list|(
name|poly16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld4q_p16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld4_u8
end_comment

begin_comment
comment|// CHECK: vld4.8 {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|uint8x8x4_t
name|test_vld4_u8
parameter_list|(
name|uint8_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld4_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld4_u16
end_comment

begin_comment
comment|// CHECK: vld4.16 {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|uint16x4x4_t
name|test_vld4_u16
parameter_list|(
name|uint16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld4_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld4_u32
end_comment

begin_comment
comment|// CHECK: vld4.32 {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|uint32x2x4_t
name|test_vld4_u32
parameter_list|(
name|uint32_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld4_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld4_u64
end_comment

begin_comment
comment|// CHECK: vld1.64
end_comment

begin_function
name|uint64x1x4_t
name|test_vld4_u64
parameter_list|(
name|uint64_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld4_u64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld4_s8
end_comment

begin_comment
comment|// CHECK: vld4.8 {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|int8x8x4_t
name|test_vld4_s8
parameter_list|(
name|int8_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld4_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld4_s16
end_comment

begin_comment
comment|// CHECK: vld4.16 {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|int16x4x4_t
name|test_vld4_s16
parameter_list|(
name|int16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld4_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld4_s32
end_comment

begin_comment
comment|// CHECK: vld4.32 {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|int32x2x4_t
name|test_vld4_s32
parameter_list|(
name|int32_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld4_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld4_s64
end_comment

begin_comment
comment|// CHECK: vld1.64
end_comment

begin_function
name|int64x1x4_t
name|test_vld4_s64
parameter_list|(
name|int64_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld4_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld4_f16
end_comment

begin_comment
comment|// CHECK: vld4.16 {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|float16x4x4_t
name|test_vld4_f16
parameter_list|(
name|float16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld4_f16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld4_f32
end_comment

begin_comment
comment|// CHECK: vld4.32 {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|float32x2x4_t
name|test_vld4_f32
parameter_list|(
name|float32_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld4_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld4_p8
end_comment

begin_comment
comment|// CHECK: vld4.8 {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|poly8x8x4_t
name|test_vld4_p8
parameter_list|(
name|poly8_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld4_p8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld4_p16
end_comment

begin_comment
comment|// CHECK: vld4.16 {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|poly16x4x4_t
name|test_vld4_p16
parameter_list|(
name|poly16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld4_p16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld4_dup_u8
end_comment

begin_comment
comment|// CHECK: vld4.8 {d{{[0-9]+}}[], d{{[0-9]+}}[], d{{[0-9]+}}[], d{{[0-9]+}}[]}, [r{{[0-9]+}}]
end_comment

begin_function
name|uint8x8x4_t
name|test_vld4_dup_u8
parameter_list|(
name|uint8_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld4_dup_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld4_dup_u16
end_comment

begin_comment
comment|// CHECK: vld4.16 {d{{[0-9]+}}[], d{{[0-9]+}}[], d{{[0-9]+}}[], d{{[0-9]+}}[]}, [r{{[0-9]+}}]
end_comment

begin_function
name|uint16x4x4_t
name|test_vld4_dup_u16
parameter_list|(
name|uint16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld4_dup_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld4_dup_u32
end_comment

begin_comment
comment|// CHECK: vld4.32 {d{{[0-9]+}}[], d{{[0-9]+}}[], d{{[0-9]+}}[], d{{[0-9]+}}[]}, [r{{[0-9]+}}]
end_comment

begin_function
name|uint32x2x4_t
name|test_vld4_dup_u32
parameter_list|(
name|uint32_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld4_dup_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld4_dup_u64
end_comment

begin_comment
comment|// CHECK: vld1.64
end_comment

begin_function
name|uint64x1x4_t
name|test_vld4_dup_u64
parameter_list|(
name|uint64_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld4_dup_u64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld4_dup_s8
end_comment

begin_comment
comment|// CHECK: vld4.8 {d{{[0-9]+}}[], d{{[0-9]+}}[], d{{[0-9]+}}[], d{{[0-9]+}}[]}, [r{{[0-9]+}}]
end_comment

begin_function
name|int8x8x4_t
name|test_vld4_dup_s8
parameter_list|(
name|int8_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld4_dup_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld4_dup_s16
end_comment

begin_comment
comment|// CHECK: vld4.16 {d{{[0-9]+}}[], d{{[0-9]+}}[], d{{[0-9]+}}[], d{{[0-9]+}}[]}, [r{{[0-9]+}}]
end_comment

begin_function
name|int16x4x4_t
name|test_vld4_dup_s16
parameter_list|(
name|int16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld4_dup_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld4_dup_s32
end_comment

begin_comment
comment|// CHECK: vld4.32 {d{{[0-9]+}}[], d{{[0-9]+}}[], d{{[0-9]+}}[], d{{[0-9]+}}[]}, [r{{[0-9]+}}]
end_comment

begin_function
name|int32x2x4_t
name|test_vld4_dup_s32
parameter_list|(
name|int32_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld4_dup_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld4_dup_s64
end_comment

begin_comment
comment|// CHECK: vld1.64
end_comment

begin_function
name|int64x1x4_t
name|test_vld4_dup_s64
parameter_list|(
name|int64_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld4_dup_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld4_dup_f16
end_comment

begin_comment
comment|// CHECK: vld4.16 {d{{[0-9]+}}[], d{{[0-9]+}}[], d{{[0-9]+}}[], d{{[0-9]+}}[]}, [r{{[0-9]+}}]
end_comment

begin_function
name|float16x4x4_t
name|test_vld4_dup_f16
parameter_list|(
name|float16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld4_dup_f16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld4_dup_f32
end_comment

begin_comment
comment|// CHECK: vld4.32 {d{{[0-9]+}}[], d{{[0-9]+}}[], d{{[0-9]+}}[], d{{[0-9]+}}[]}, [r{{[0-9]+}}]
end_comment

begin_function
name|float32x2x4_t
name|test_vld4_dup_f32
parameter_list|(
name|float32_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld4_dup_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld4_dup_p8
end_comment

begin_comment
comment|// CHECK: vld4.8 {d{{[0-9]+}}[], d{{[0-9]+}}[], d{{[0-9]+}}[], d{{[0-9]+}}[]}, [r{{[0-9]+}}]
end_comment

begin_function
name|poly8x8x4_t
name|test_vld4_dup_p8
parameter_list|(
name|poly8_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld4_dup_p8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld4_dup_p16
end_comment

begin_comment
comment|// CHECK: vld4.16 {d{{[0-9]+}}[], d{{[0-9]+}}[], d{{[0-9]+}}[], d{{[0-9]+}}[]}, [r{{[0-9]+}}]
end_comment

begin_function
name|poly16x4x4_t
name|test_vld4_dup_p16
parameter_list|(
name|poly16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vld4_dup_p16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld4q_lane_u16
end_comment

begin_comment
comment|// CHECK: vld4.16 {d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}]}
end_comment

begin_function
name|uint16x8x4_t
name|test_vld4q_lane_u16
parameter_list|(
name|uint16_t
specifier|const
modifier|*
name|a
parameter_list|,
name|uint16x8x4_t
name|b
parameter_list|)
block|{
return|return
name|vld4q_lane_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld4q_lane_u32
end_comment

begin_comment
comment|// CHECK: vld4.32 {d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}]}
end_comment

begin_function
name|uint32x4x4_t
name|test_vld4q_lane_u32
parameter_list|(
name|uint32_t
specifier|const
modifier|*
name|a
parameter_list|,
name|uint32x4x4_t
name|b
parameter_list|)
block|{
return|return
name|vld4q_lane_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld4q_lane_s16
end_comment

begin_comment
comment|// CHECK: vld4.16 {d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}]}
end_comment

begin_function
name|int16x8x4_t
name|test_vld4q_lane_s16
parameter_list|(
name|int16_t
specifier|const
modifier|*
name|a
parameter_list|,
name|int16x8x4_t
name|b
parameter_list|)
block|{
return|return
name|vld4q_lane_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld4q_lane_s32
end_comment

begin_comment
comment|// CHECK: vld4.32 {d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}]}
end_comment

begin_function
name|int32x4x4_t
name|test_vld4q_lane_s32
parameter_list|(
name|int32_t
specifier|const
modifier|*
name|a
parameter_list|,
name|int32x4x4_t
name|b
parameter_list|)
block|{
return|return
name|vld4q_lane_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld4q_lane_f16
end_comment

begin_comment
comment|// CHECK: vld4.16 {d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}]}
end_comment

begin_function
name|float16x8x4_t
name|test_vld4q_lane_f16
parameter_list|(
name|float16_t
specifier|const
modifier|*
name|a
parameter_list|,
name|float16x8x4_t
name|b
parameter_list|)
block|{
return|return
name|vld4q_lane_f16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld4q_lane_f32
end_comment

begin_comment
comment|// CHECK: vld4.32 {d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}]}
end_comment

begin_function
name|float32x4x4_t
name|test_vld4q_lane_f32
parameter_list|(
name|float32_t
specifier|const
modifier|*
name|a
parameter_list|,
name|float32x4x4_t
name|b
parameter_list|)
block|{
return|return
name|vld4q_lane_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld4q_lane_p16
end_comment

begin_comment
comment|// CHECK: vld4.16 {d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}]}
end_comment

begin_function
name|poly16x8x4_t
name|test_vld4q_lane_p16
parameter_list|(
name|poly16_t
specifier|const
modifier|*
name|a
parameter_list|,
name|poly16x8x4_t
name|b
parameter_list|)
block|{
return|return
name|vld4q_lane_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld4_lane_u8
end_comment

begin_comment
comment|// CHECK: vld4.8 {d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}]
end_comment

begin_function
name|uint8x8x4_t
name|test_vld4_lane_u8
parameter_list|(
name|uint8_t
specifier|const
modifier|*
name|a
parameter_list|,
name|uint8x8x4_t
name|b
parameter_list|)
block|{
return|return
name|vld4_lane_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld4_lane_u16
end_comment

begin_comment
comment|// CHECK: vld4.16 {d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}]
end_comment

begin_function
name|uint16x4x4_t
name|test_vld4_lane_u16
parameter_list|(
name|uint16_t
specifier|const
modifier|*
name|a
parameter_list|,
name|uint16x4x4_t
name|b
parameter_list|)
block|{
return|return
name|vld4_lane_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld4_lane_u32
end_comment

begin_comment
comment|// CHECK: vld4.32 {d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}]
end_comment

begin_function
name|uint32x2x4_t
name|test_vld4_lane_u32
parameter_list|(
name|uint32_t
specifier|const
modifier|*
name|a
parameter_list|,
name|uint32x2x4_t
name|b
parameter_list|)
block|{
return|return
name|vld4_lane_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld4_lane_s8
end_comment

begin_comment
comment|// CHECK: vld4.8 {d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}]
end_comment

begin_function
name|int8x8x4_t
name|test_vld4_lane_s8
parameter_list|(
name|int8_t
specifier|const
modifier|*
name|a
parameter_list|,
name|int8x8x4_t
name|b
parameter_list|)
block|{
return|return
name|vld4_lane_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld4_lane_s16
end_comment

begin_comment
comment|// CHECK: vld4.16 {d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}]
end_comment

begin_function
name|int16x4x4_t
name|test_vld4_lane_s16
parameter_list|(
name|int16_t
specifier|const
modifier|*
name|a
parameter_list|,
name|int16x4x4_t
name|b
parameter_list|)
block|{
return|return
name|vld4_lane_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld4_lane_s32
end_comment

begin_comment
comment|// CHECK: vld4.32 {d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}]
end_comment

begin_function
name|int32x2x4_t
name|test_vld4_lane_s32
parameter_list|(
name|int32_t
specifier|const
modifier|*
name|a
parameter_list|,
name|int32x2x4_t
name|b
parameter_list|)
block|{
return|return
name|vld4_lane_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld4_lane_f16
end_comment

begin_comment
comment|// CHECK: vld4.16 {d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}]
end_comment

begin_function
name|float16x4x4_t
name|test_vld4_lane_f16
parameter_list|(
name|float16_t
specifier|const
modifier|*
name|a
parameter_list|,
name|float16x4x4_t
name|b
parameter_list|)
block|{
return|return
name|vld4_lane_f16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld4_lane_f32
end_comment

begin_comment
comment|// CHECK: vld4.32 {d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}]
end_comment

begin_function
name|float32x2x4_t
name|test_vld4_lane_f32
parameter_list|(
name|float32_t
specifier|const
modifier|*
name|a
parameter_list|,
name|float32x2x4_t
name|b
parameter_list|)
block|{
return|return
name|vld4_lane_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld4_lane_p8
end_comment

begin_comment
comment|// CHECK: vld4.8 {d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}]
end_comment

begin_function
name|poly8x8x4_t
name|test_vld4_lane_p8
parameter_list|(
name|poly8_t
specifier|const
modifier|*
name|a
parameter_list|,
name|poly8x8x4_t
name|b
parameter_list|)
block|{
return|return
name|vld4_lane_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vld4_lane_p16
end_comment

begin_comment
comment|// CHECK: vld4.16 {d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}]
end_comment

begin_function
name|poly16x4x4_t
name|test_vld4_lane_p16
parameter_list|(
name|poly16_t
specifier|const
modifier|*
name|a
parameter_list|,
name|poly16x4x4_t
name|b
parameter_list|)
block|{
return|return
name|vld4_lane_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmax_s8
end_comment

begin_comment
comment|// CHECK: vmax.s8 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int8x8_t
name|test_vmax_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
return|return
name|vmax_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmax_s16
end_comment

begin_comment
comment|// CHECK: vmax.s16 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int16x4_t
name|test_vmax_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
return|return
name|vmax_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmax_s32
end_comment

begin_comment
comment|// CHECK: vmax.s32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int32x2_t
name|test_vmax_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
return|return
name|vmax_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmax_u8
end_comment

begin_comment
comment|// CHECK: vmax.u8 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint8x8_t
name|test_vmax_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|)
block|{
return|return
name|vmax_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmax_u16
end_comment

begin_comment
comment|// CHECK: vmax.u16 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint16x4_t
name|test_vmax_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|)
block|{
return|return
name|vmax_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmax_u32
end_comment

begin_comment
comment|// CHECK: vmax.u32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint32x2_t
name|test_vmax_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|)
block|{
return|return
name|vmax_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmax_f32
end_comment

begin_comment
comment|// CHECK: vmax.f32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|float32x2_t
name|test_vmax_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32x2_t
name|b
parameter_list|)
block|{
return|return
name|vmax_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmaxq_s8
end_comment

begin_comment
comment|// CHECK: vmax.s8 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int8x16_t
name|test_vmaxq_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|)
block|{
return|return
name|vmaxq_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmaxq_s16
end_comment

begin_comment
comment|// CHECK: vmax.s16 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int16x8_t
name|test_vmaxq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
return|return
name|vmaxq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmaxq_s32
end_comment

begin_comment
comment|// CHECK: vmax.s32 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int32x4_t
name|test_vmaxq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
return|return
name|vmaxq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmaxq_u8
end_comment

begin_comment
comment|// CHECK: vmax.u8 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint8x16_t
name|test_vmaxq_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|,
name|uint8x16_t
name|b
parameter_list|)
block|{
return|return
name|vmaxq_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmaxq_u16
end_comment

begin_comment
comment|// CHECK: vmax.u16 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint16x8_t
name|test_vmaxq_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|)
block|{
return|return
name|vmaxq_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmaxq_u32
end_comment

begin_comment
comment|// CHECK: vmax.u32 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint32x4_t
name|test_vmaxq_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|)
block|{
return|return
name|vmaxq_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmaxq_f32
end_comment

begin_comment
comment|// CHECK: vmax.f32 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|float32x4_t
name|test_vmaxq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|,
name|float32x4_t
name|b
parameter_list|)
block|{
return|return
name|vmaxq_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmin_s8
end_comment

begin_comment
comment|// CHECK: vmin.s8 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int8x8_t
name|test_vmin_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
return|return
name|vmin_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmin_s16
end_comment

begin_comment
comment|// CHECK: vmin.s16 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int16x4_t
name|test_vmin_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
return|return
name|vmin_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmin_s32
end_comment

begin_comment
comment|// CHECK: vmin.s32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int32x2_t
name|test_vmin_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
return|return
name|vmin_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmin_u8
end_comment

begin_comment
comment|// CHECK: vmin.u8 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint8x8_t
name|test_vmin_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|)
block|{
return|return
name|vmin_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmin_u16
end_comment

begin_comment
comment|// CHECK: vmin.u16 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint16x4_t
name|test_vmin_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|)
block|{
return|return
name|vmin_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmin_u32
end_comment

begin_comment
comment|// CHECK: vmin.u32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint32x2_t
name|test_vmin_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|)
block|{
return|return
name|vmin_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmin_f32
end_comment

begin_comment
comment|// CHECK: vmin.f32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|float32x2_t
name|test_vmin_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32x2_t
name|b
parameter_list|)
block|{
return|return
name|vmin_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vminq_s8
end_comment

begin_comment
comment|// CHECK: vmin.s8 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int8x16_t
name|test_vminq_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|)
block|{
return|return
name|vminq_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vminq_s16
end_comment

begin_comment
comment|// CHECK: vmin.s16 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int16x8_t
name|test_vminq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
return|return
name|vminq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vminq_s32
end_comment

begin_comment
comment|// CHECK: vmin.s32 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int32x4_t
name|test_vminq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
return|return
name|vminq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vminq_u8
end_comment

begin_comment
comment|// CHECK: vmin.u8 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint8x16_t
name|test_vminq_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|,
name|uint8x16_t
name|b
parameter_list|)
block|{
return|return
name|vminq_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vminq_u16
end_comment

begin_comment
comment|// CHECK: vmin.u16 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint16x8_t
name|test_vminq_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|)
block|{
return|return
name|vminq_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vminq_u32
end_comment

begin_comment
comment|// CHECK: vmin.u32 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint32x4_t
name|test_vminq_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|)
block|{
return|return
name|vminq_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vminq_f32
end_comment

begin_comment
comment|// CHECK: vmin.f32 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|float32x4_t
name|test_vminq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|,
name|float32x4_t
name|b
parameter_list|)
block|{
return|return
name|vminq_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmla_s8
end_comment

begin_comment
comment|// CHECK: vmla.i8 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int8x8_t
name|test_vmla_s8
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
return|return
name|vmla_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmla_s16
end_comment

begin_comment
comment|// CHECK: vmla.i16 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int16x4_t
name|test_vmla_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|,
name|int16x4_t
name|c
parameter_list|)
block|{
return|return
name|vmla_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmla_s32
end_comment

begin_comment
comment|// CHECK: vmla.i32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int32x2_t
name|test_vmla_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|,
name|int32x2_t
name|c
parameter_list|)
block|{
return|return
name|vmla_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmla_f32
end_comment

begin_comment
comment|// CHECK-SWIFT: vmul.f32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_comment
comment|// CHECK-SWIFT: vadd.f32
end_comment

begin_comment
comment|// CHECK-A57: vmla.f32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|float32x2_t
name|test_vmla_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32x2_t
name|b
parameter_list|,
name|float32x2_t
name|c
parameter_list|)
block|{
return|return
name|vmla_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmla_u8
end_comment

begin_comment
comment|// CHECK: vmla.i8 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint8x8_t
name|test_vmla_u8
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
return|return
name|vmla_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmla_u16
end_comment

begin_comment
comment|// CHECK: vmla.i16 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint16x4_t
name|test_vmla_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|,
name|uint16x4_t
name|c
parameter_list|)
block|{
return|return
name|vmla_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmla_u32
end_comment

begin_comment
comment|// CHECK: vmla.i32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint32x2_t
name|test_vmla_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|,
name|uint32x2_t
name|c
parameter_list|)
block|{
return|return
name|vmla_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmlaq_s8
end_comment

begin_comment
comment|// CHECK: vmla.i8 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int8x16_t
name|test_vmlaq_s8
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
return|return
name|vmlaq_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmlaq_s16
end_comment

begin_comment
comment|// CHECK: vmla.i16 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int16x8_t
name|test_vmlaq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|,
name|int16x8_t
name|c
parameter_list|)
block|{
return|return
name|vmlaq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmlaq_s32
end_comment

begin_comment
comment|// CHECK: vmla.i32 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int32x4_t
name|test_vmlaq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|,
name|int32x4_t
name|c
parameter_list|)
block|{
return|return
name|vmlaq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmlaq_f32
end_comment

begin_comment
comment|// CHECK-SWIFT: vmul.f32 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_comment
comment|// CHECK-SWIFT: vadd.f32
end_comment

begin_comment
comment|// CHECK-A57: vmla.f32 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|float32x4_t
name|test_vmlaq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|,
name|float32x4_t
name|b
parameter_list|,
name|float32x4_t
name|c
parameter_list|)
block|{
return|return
name|vmlaq_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmlaq_u8
end_comment

begin_comment
comment|// CHECK: vmla.i8 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint8x16_t
name|test_vmlaq_u8
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
return|return
name|vmlaq_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmlaq_u16
end_comment

begin_comment
comment|// CHECK: vmla.i16 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint16x8_t
name|test_vmlaq_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|,
name|uint16x8_t
name|c
parameter_list|)
block|{
return|return
name|vmlaq_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmlaq_u32
end_comment

begin_comment
comment|// CHECK: vmla.i32 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint32x4_t
name|test_vmlaq_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|,
name|uint32x4_t
name|c
parameter_list|)
block|{
return|return
name|vmlaq_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmlal_s8
end_comment

begin_comment
comment|// CHECK: vmlal.s8 q{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int16x8_t
name|test_vmlal_s8
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|,
name|int8x8_t
name|c
parameter_list|)
block|{
return|return
name|vmlal_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmlal_s16
end_comment

begin_comment
comment|// CHECK: vmlal.s16 q{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int32x4_t
name|test_vmlal_s16
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|,
name|int16x4_t
name|c
parameter_list|)
block|{
return|return
name|vmlal_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmlal_s32
end_comment

begin_comment
comment|// CHECK: vmlal.s32 q{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int64x2_t
name|test_vmlal_s32
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|,
name|int32x2_t
name|c
parameter_list|)
block|{
return|return
name|vmlal_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmlal_u8
end_comment

begin_comment
comment|// CHECK: vmlal.u8 q{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint16x8_t
name|test_vmlal_u8
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|,
name|uint8x8_t
name|c
parameter_list|)
block|{
return|return
name|vmlal_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmlal_u16
end_comment

begin_comment
comment|// CHECK: vmlal.u16 q{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint32x4_t
name|test_vmlal_u16
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|,
name|uint16x4_t
name|c
parameter_list|)
block|{
return|return
name|vmlal_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmlal_u32
end_comment

begin_comment
comment|// CHECK: vmlal.u32 q{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint64x2_t
name|test_vmlal_u32
parameter_list|(
name|uint64x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|,
name|uint32x2_t
name|c
parameter_list|)
block|{
return|return
name|vmlal_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmlal_lane_s16
end_comment

begin_comment
comment|// CHECK: vmlal.s16 q{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}[{{[0-9]}}]
end_comment

begin_function
name|int32x4_t
name|test_vmlal_lane_s16
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|,
name|int16x4_t
name|c
parameter_list|)
block|{
return|return
name|vmlal_lane_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmlal_lane_s32
end_comment

begin_comment
comment|// CHECK: vmlal.s32 q{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}[{{[0-9]}}]
end_comment

begin_function
name|int64x2_t
name|test_vmlal_lane_s32
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|,
name|int32x2_t
name|c
parameter_list|)
block|{
return|return
name|vmlal_lane_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmlal_lane_u16
end_comment

begin_comment
comment|// CHECK: vmlal.u16 q{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}[{{[0-9]}}]
end_comment

begin_function
name|uint32x4_t
name|test_vmlal_lane_u16
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|,
name|uint16x4_t
name|c
parameter_list|)
block|{
return|return
name|vmlal_lane_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmlal_lane_u32
end_comment

begin_comment
comment|// CHECK: vmlal.u32 q{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}[{{[0-9]}}]
end_comment

begin_function
name|uint64x2_t
name|test_vmlal_lane_u32
parameter_list|(
name|uint64x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|,
name|uint32x2_t
name|c
parameter_list|)
block|{
return|return
name|vmlal_lane_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmlal_n_s16
end_comment

begin_comment
comment|// CHECK: vmlal.s16 q{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int32x4_t
name|test_vmlal_n_s16
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|,
name|int16_t
name|c
parameter_list|)
block|{
return|return
name|vmlal_n_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmlal_n_s32
end_comment

begin_comment
comment|// CHECK: vmlal.s32 q{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int64x2_t
name|test_vmlal_n_s32
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|,
name|int32_t
name|c
parameter_list|)
block|{
return|return
name|vmlal_n_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmlal_n_u16
end_comment

begin_comment
comment|// CHECK: vmlal.u16 q{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint32x4_t
name|test_vmlal_n_u16
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|,
name|uint16_t
name|c
parameter_list|)
block|{
return|return
name|vmlal_n_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmlal_n_u32
end_comment

begin_comment
comment|// CHECK: vmlal.u32 q{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint64x2_t
name|test_vmlal_n_u32
parameter_list|(
name|uint64x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|,
name|uint32_t
name|c
parameter_list|)
block|{
return|return
name|vmlal_n_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmla_lane_s16
end_comment

begin_comment
comment|// CHECK: vmla.i16 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}[{{[0-9]}}]
end_comment

begin_function
name|int16x4_t
name|test_vmla_lane_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|,
name|int16x4_t
name|c
parameter_list|)
block|{
return|return
name|vmla_lane_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmla_lane_s32
end_comment

begin_comment
comment|// CHECK: vmla.i32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}[{{[0-9]}}]
end_comment

begin_function
name|int32x2_t
name|test_vmla_lane_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|,
name|int32x2_t
name|c
parameter_list|)
block|{
return|return
name|vmla_lane_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmla_lane_u16
end_comment

begin_comment
comment|// CHECK: vmla.i16 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}[{{[0-9]}}]
end_comment

begin_function
name|uint16x4_t
name|test_vmla_lane_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|,
name|uint16x4_t
name|c
parameter_list|)
block|{
return|return
name|vmla_lane_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmla_lane_u32
end_comment

begin_comment
comment|// CHECK: vmla.i32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}[{{[0-9]}}]
end_comment

begin_function
name|uint32x2_t
name|test_vmla_lane_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|,
name|uint32x2_t
name|c
parameter_list|)
block|{
return|return
name|vmla_lane_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmla_lane_f32
end_comment

begin_comment
comment|// CHECK-SWIFT: vmul.f32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}[{{[0-9]}}]
end_comment

begin_comment
comment|// CHECK-SWIFT: vadd.f32
end_comment

begin_comment
comment|// CHECK-A57: vmla.f32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}[{{[0-9]}}]
end_comment

begin_function
name|float32x2_t
name|test_vmla_lane_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32x2_t
name|b
parameter_list|,
name|float32x2_t
name|c
parameter_list|)
block|{
return|return
name|vmla_lane_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmlaq_lane_s16
end_comment

begin_comment
comment|// CHECK: vmla.i16 q{{[0-9]+}}, q{{[0-9]+}}, d{{[0-9]+}}[{{[0-9]}}]
end_comment

begin_function
name|int16x8_t
name|test_vmlaq_lane_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|,
name|int16x4_t
name|c
parameter_list|)
block|{
return|return
name|vmlaq_lane_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmlaq_lane_s32
end_comment

begin_comment
comment|// CHECK: vmla.i32 q{{[0-9]+}}, q{{[0-9]+}}, d{{[0-9]+}}[{{[0-9]}}]
end_comment

begin_function
name|int32x4_t
name|test_vmlaq_lane_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|,
name|int32x2_t
name|c
parameter_list|)
block|{
return|return
name|vmlaq_lane_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmlaq_lane_u16
end_comment

begin_comment
comment|// CHECK: vmla.i16 q{{[0-9]+}}, q{{[0-9]+}}, d{{[0-9]+}}[{{[0-9]}}]
end_comment

begin_function
name|uint16x8_t
name|test_vmlaq_lane_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|,
name|uint16x4_t
name|c
parameter_list|)
block|{
return|return
name|vmlaq_lane_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmlaq_lane_u32
end_comment

begin_comment
comment|// CHECK: vmla.i32 q{{[0-9]+}}, q{{[0-9]+}}, d{{[0-9]+}}[{{[0-9]}}]
end_comment

begin_function
name|uint32x4_t
name|test_vmlaq_lane_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|,
name|uint32x2_t
name|c
parameter_list|)
block|{
return|return
name|vmlaq_lane_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmlaq_lane_f32
end_comment

begin_comment
comment|// CHECK-SWIFT: vmul.f32 q{{[0-9]+}}, q{{[0-9]+}}, d{{[0-9]+}}[{{[0-9]}}]
end_comment

begin_comment
comment|// CHECK-SWIFT: vadd.f32
end_comment

begin_comment
comment|// CHECK-A57: vmla.f32 q{{[0-9]+}}, q{{[0-9]+}}, d{{[0-9]+}}[{{[0-9]}}]
end_comment

begin_function
name|float32x4_t
name|test_vmlaq_lane_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|,
name|float32x4_t
name|b
parameter_list|,
name|float32x2_t
name|c
parameter_list|)
block|{
return|return
name|vmlaq_lane_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmla_n_s16
end_comment

begin_comment
comment|// CHECK: vmla.i16 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int16x4_t
name|test_vmla_n_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|,
name|int16_t
name|c
parameter_list|)
block|{
return|return
name|vmla_n_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmla_n_s32
end_comment

begin_comment
comment|// CHECK: vmla.i32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int32x2_t
name|test_vmla_n_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|,
name|int32_t
name|c
parameter_list|)
block|{
return|return
name|vmla_n_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmla_n_u16
end_comment

begin_comment
comment|// CHECK: vmla.i16 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint16x4_t
name|test_vmla_n_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|,
name|uint16_t
name|c
parameter_list|)
block|{
return|return
name|vmla_n_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmla_n_u32
end_comment

begin_comment
comment|// CHECK: vmla.i32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint32x2_t
name|test_vmla_n_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|,
name|uint32_t
name|c
parameter_list|)
block|{
return|return
name|vmla_n_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmla_n_f32
end_comment

begin_comment
comment|// CHECK-SWIFT: vmul.f32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_comment
comment|// CHECK-SWIFT: vadd.f32
end_comment

begin_comment
comment|// CHECK-A57: vmla.f32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|float32x2_t
name|test_vmla_n_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32x2_t
name|b
parameter_list|,
name|float32_t
name|c
parameter_list|)
block|{
return|return
name|vmla_n_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmlaq_n_s16
end_comment

begin_comment
comment|// CHECK: vmla.i16 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int16x8_t
name|test_vmlaq_n_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|,
name|int16_t
name|c
parameter_list|)
block|{
return|return
name|vmlaq_n_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmlaq_n_s32
end_comment

begin_comment
comment|// CHECK: vmla.i32 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int32x4_t
name|test_vmlaq_n_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|,
name|int32_t
name|c
parameter_list|)
block|{
return|return
name|vmlaq_n_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmlaq_n_u16
end_comment

begin_comment
comment|// CHECK: vmla.i16 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint16x8_t
name|test_vmlaq_n_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|,
name|uint16_t
name|c
parameter_list|)
block|{
return|return
name|vmlaq_n_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmlaq_n_u32
end_comment

begin_comment
comment|// CHECK: vmla.i32 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint32x4_t
name|test_vmlaq_n_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|,
name|uint32_t
name|c
parameter_list|)
block|{
return|return
name|vmlaq_n_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmlaq_n_f32
end_comment

begin_comment
comment|// CHECK-SWIFT: vmul.f32 q{{[0-9]+}}, q{{[0-9]+}}, d{{[0-9]+}}[0]
end_comment

begin_comment
comment|// CHECK-SWIFT: vadd.f32
end_comment

begin_comment
comment|// CHECK-A57: vld1.32 {d{{[0-9]+}}[], d{{[0-9]+}}[]},
end_comment

begin_comment
comment|// CHECK-A57: vmla.f32 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|float32x4_t
name|test_vmlaq_n_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|,
name|float32x4_t
name|b
parameter_list|,
name|float32_t
name|c
parameter_list|)
block|{
return|return
name|vmlaq_n_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmls_s8
end_comment

begin_comment
comment|// CHECK: vmls.i8 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int8x8_t
name|test_vmls_s8
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
return|return
name|vmls_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmls_s16
end_comment

begin_comment
comment|// CHECK: vmls.i16 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int16x4_t
name|test_vmls_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|,
name|int16x4_t
name|c
parameter_list|)
block|{
return|return
name|vmls_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmls_s32
end_comment

begin_comment
comment|// CHECK: vmls.i32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int32x2_t
name|test_vmls_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|,
name|int32x2_t
name|c
parameter_list|)
block|{
return|return
name|vmls_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmls_f32
end_comment

begin_comment
comment|// CHECK-SWIFT: vmul.f32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_comment
comment|// CHECK-SWIFT: vsub.f32
end_comment

begin_comment
comment|// CHECK-A57: vmls.f32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|float32x2_t
name|test_vmls_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32x2_t
name|b
parameter_list|,
name|float32x2_t
name|c
parameter_list|)
block|{
return|return
name|vmls_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmls_u8
end_comment

begin_comment
comment|// CHECK: vmls.i8 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint8x8_t
name|test_vmls_u8
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
return|return
name|vmls_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmls_u16
end_comment

begin_comment
comment|// CHECK: vmls.i16 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint16x4_t
name|test_vmls_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|,
name|uint16x4_t
name|c
parameter_list|)
block|{
return|return
name|vmls_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmls_u32
end_comment

begin_comment
comment|// CHECK: vmls.i32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint32x2_t
name|test_vmls_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|,
name|uint32x2_t
name|c
parameter_list|)
block|{
return|return
name|vmls_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmlsq_s8
end_comment

begin_comment
comment|// CHECK: vmls.i8 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int8x16_t
name|test_vmlsq_s8
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
return|return
name|vmlsq_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmlsq_s16
end_comment

begin_comment
comment|// CHECK: vmls.i16 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int16x8_t
name|test_vmlsq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|,
name|int16x8_t
name|c
parameter_list|)
block|{
return|return
name|vmlsq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmlsq_s32
end_comment

begin_comment
comment|// CHECK: vmls.i32 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int32x4_t
name|test_vmlsq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|,
name|int32x4_t
name|c
parameter_list|)
block|{
return|return
name|vmlsq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmlsq_f32
end_comment

begin_comment
comment|// CHECK-SWIFT: vmul.f32 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_comment
comment|// CHECK-SWIFT: vsub.f32
end_comment

begin_comment
comment|// CHECK-A57: vmls.f32 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|float32x4_t
name|test_vmlsq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|,
name|float32x4_t
name|b
parameter_list|,
name|float32x4_t
name|c
parameter_list|)
block|{
return|return
name|vmlsq_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmlsq_u8
end_comment

begin_comment
comment|// CHECK: vmls.i8 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint8x16_t
name|test_vmlsq_u8
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
return|return
name|vmlsq_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmlsq_u16
end_comment

begin_comment
comment|// CHECK: vmls.i16 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint16x8_t
name|test_vmlsq_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|,
name|uint16x8_t
name|c
parameter_list|)
block|{
return|return
name|vmlsq_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmlsq_u32
end_comment

begin_comment
comment|// CHECK: vmls.i32 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint32x4_t
name|test_vmlsq_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|,
name|uint32x4_t
name|c
parameter_list|)
block|{
return|return
name|vmlsq_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmlsl_s8
end_comment

begin_comment
comment|// CHECK: vmlsl.s8 q{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int16x8_t
name|test_vmlsl_s8
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|,
name|int8x8_t
name|c
parameter_list|)
block|{
return|return
name|vmlsl_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmlsl_s16
end_comment

begin_comment
comment|// CHECK: vmlsl.s16 q{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int32x4_t
name|test_vmlsl_s16
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|,
name|int16x4_t
name|c
parameter_list|)
block|{
return|return
name|vmlsl_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmlsl_s32
end_comment

begin_comment
comment|// CHECK: vmlsl.s32 q{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int64x2_t
name|test_vmlsl_s32
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|,
name|int32x2_t
name|c
parameter_list|)
block|{
return|return
name|vmlsl_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmlsl_u8
end_comment

begin_comment
comment|// CHECK: vmlsl.u8 q{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint16x8_t
name|test_vmlsl_u8
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|,
name|uint8x8_t
name|c
parameter_list|)
block|{
return|return
name|vmlsl_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmlsl_u16
end_comment

begin_comment
comment|// CHECK: vmlsl.u16 q{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint32x4_t
name|test_vmlsl_u16
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|,
name|uint16x4_t
name|c
parameter_list|)
block|{
return|return
name|vmlsl_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmlsl_u32
end_comment

begin_comment
comment|// CHECK: vmlsl.u32 q{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint64x2_t
name|test_vmlsl_u32
parameter_list|(
name|uint64x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|,
name|uint32x2_t
name|c
parameter_list|)
block|{
return|return
name|vmlsl_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmlsl_lane_s16
end_comment

begin_comment
comment|// CHECK: vmlsl.s16 q{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}[{{[0-9]}}]
end_comment

begin_function
name|int32x4_t
name|test_vmlsl_lane_s16
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|,
name|int16x4_t
name|c
parameter_list|)
block|{
return|return
name|vmlsl_lane_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmlsl_lane_s32
end_comment

begin_comment
comment|// CHECK: vmlsl.s32 q{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}[{{[0-9]}}]
end_comment

begin_function
name|int64x2_t
name|test_vmlsl_lane_s32
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|,
name|int32x2_t
name|c
parameter_list|)
block|{
return|return
name|vmlsl_lane_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmlsl_lane_u16
end_comment

begin_comment
comment|// CHECK: vmlsl.u16 q{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}[{{[0-9]}}]
end_comment

begin_function
name|uint32x4_t
name|test_vmlsl_lane_u16
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|,
name|uint16x4_t
name|c
parameter_list|)
block|{
return|return
name|vmlsl_lane_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmlsl_lane_u32
end_comment

begin_comment
comment|// CHECK: vmlsl.u32 q{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}[{{[0-9]}}]
end_comment

begin_function
name|uint64x2_t
name|test_vmlsl_lane_u32
parameter_list|(
name|uint64x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|,
name|uint32x2_t
name|c
parameter_list|)
block|{
return|return
name|vmlsl_lane_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmlsl_n_s16
end_comment

begin_comment
comment|// CHECK: vmlsl.s16 q{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int32x4_t
name|test_vmlsl_n_s16
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|,
name|int16_t
name|c
parameter_list|)
block|{
return|return
name|vmlsl_n_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmlsl_n_s32
end_comment

begin_comment
comment|// CHECK: vmlsl.s32 q{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int64x2_t
name|test_vmlsl_n_s32
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|,
name|int32_t
name|c
parameter_list|)
block|{
return|return
name|vmlsl_n_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmlsl_n_u16
end_comment

begin_comment
comment|// CHECK: vmlsl.u16 q{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint32x4_t
name|test_vmlsl_n_u16
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|,
name|uint16_t
name|c
parameter_list|)
block|{
return|return
name|vmlsl_n_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmlsl_n_u32
end_comment

begin_comment
comment|// CHECK: vmlsl.u32 q{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint64x2_t
name|test_vmlsl_n_u32
parameter_list|(
name|uint64x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|,
name|uint32_t
name|c
parameter_list|)
block|{
return|return
name|vmlsl_n_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmls_lane_s16
end_comment

begin_comment
comment|// CHECK: vmls.i16 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}[{{[0-9]}}]
end_comment

begin_function
name|int16x4_t
name|test_vmls_lane_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|,
name|int16x4_t
name|c
parameter_list|)
block|{
return|return
name|vmls_lane_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmls_lane_s32
end_comment

begin_comment
comment|// CHECK: vmls.i32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}[{{[0-9]}}]
end_comment

begin_function
name|int32x2_t
name|test_vmls_lane_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|,
name|int32x2_t
name|c
parameter_list|)
block|{
return|return
name|vmls_lane_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmls_lane_u16
end_comment

begin_comment
comment|// CHECK: vmls.i16 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}[{{[0-9]}}]
end_comment

begin_function
name|uint16x4_t
name|test_vmls_lane_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|,
name|uint16x4_t
name|c
parameter_list|)
block|{
return|return
name|vmls_lane_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmls_lane_u32
end_comment

begin_comment
comment|// CHECK: vmls.i32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}[{{[0-9]}}]
end_comment

begin_function
name|uint32x2_t
name|test_vmls_lane_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|,
name|uint32x2_t
name|c
parameter_list|)
block|{
return|return
name|vmls_lane_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmls_lane_f32
end_comment

begin_comment
comment|// CHECK-SWIFT: vmul.f32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}[{{[0-9]}}]
end_comment

begin_comment
comment|// CHECK-SWIFT: vsub.f32
end_comment

begin_comment
comment|// CHECK-A57: vmls.f32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}[{{[0-9]}}]
end_comment

begin_function
name|float32x2_t
name|test_vmls_lane_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32x2_t
name|b
parameter_list|,
name|float32x2_t
name|c
parameter_list|)
block|{
return|return
name|vmls_lane_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmlsq_lane_s16
end_comment

begin_comment
comment|// CHECK: vmls.i16 q{{[0-9]+}}, q{{[0-9]+}}, d{{[0-9]+}}[{{[0-9]}}]
end_comment

begin_function
name|int16x8_t
name|test_vmlsq_lane_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|,
name|int16x4_t
name|c
parameter_list|)
block|{
return|return
name|vmlsq_lane_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmlsq_lane_s32
end_comment

begin_comment
comment|// CHECK: vmls.i32 q{{[0-9]+}}, q{{[0-9]+}}, d{{[0-9]+}}[{{[0-9]}}]
end_comment

begin_function
name|int32x4_t
name|test_vmlsq_lane_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|,
name|int32x2_t
name|c
parameter_list|)
block|{
return|return
name|vmlsq_lane_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmlsq_lane_u16
end_comment

begin_comment
comment|// CHECK: vmls.i16 q{{[0-9]+}}, q{{[0-9]+}}, d{{[0-9]+}}[{{[0-9]}}]
end_comment

begin_function
name|uint16x8_t
name|test_vmlsq_lane_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|,
name|uint16x4_t
name|c
parameter_list|)
block|{
return|return
name|vmlsq_lane_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmlsq_lane_u32
end_comment

begin_comment
comment|// CHECK: vmls.i32 q{{[0-9]+}}, q{{[0-9]+}}, d{{[0-9]+}}[{{[0-9]}}]
end_comment

begin_function
name|uint32x4_t
name|test_vmlsq_lane_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|,
name|uint32x2_t
name|c
parameter_list|)
block|{
return|return
name|vmlsq_lane_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmlsq_lane_f32
end_comment

begin_comment
comment|// CHECK-SWIFT: vmul.f32 q{{[0-9]+}}, q{{[0-9]+}}, d{{[0-9]+}}[{{[0-9]}}]
end_comment

begin_comment
comment|// CHECK-SWIFT: vsub.f32
end_comment

begin_comment
comment|// CHECK-A57: vmls.f32 q{{[0-9]+}}, q{{[0-9]+}}, d{{[0-9]+}}[{{[0-9]}}]
end_comment

begin_function
name|float32x4_t
name|test_vmlsq_lane_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|,
name|float32x4_t
name|b
parameter_list|,
name|float32x2_t
name|c
parameter_list|)
block|{
return|return
name|vmlsq_lane_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmls_n_s16
end_comment

begin_comment
comment|// CHECK: vmls.i16 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int16x4_t
name|test_vmls_n_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|,
name|int16_t
name|c
parameter_list|)
block|{
return|return
name|vmls_n_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmls_n_s32
end_comment

begin_comment
comment|// CHECK: vmls.i32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int32x2_t
name|test_vmls_n_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|,
name|int32_t
name|c
parameter_list|)
block|{
return|return
name|vmls_n_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmls_n_u16
end_comment

begin_comment
comment|// CHECK: vmls.i16 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint16x4_t
name|test_vmls_n_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|,
name|uint16_t
name|c
parameter_list|)
block|{
return|return
name|vmls_n_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmls_n_u32
end_comment

begin_comment
comment|// CHECK: vmls.i32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint32x2_t
name|test_vmls_n_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|,
name|uint32_t
name|c
parameter_list|)
block|{
return|return
name|vmls_n_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmls_n_f32
end_comment

begin_comment
comment|// CHECK-SWIFT: vmul.f32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_comment
comment|// CHECK-SWIFT: vsub.f32
end_comment

begin_comment
comment|// CHECK-A57: vmls.f32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|float32x2_t
name|test_vmls_n_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32x2_t
name|b
parameter_list|,
name|float32_t
name|c
parameter_list|)
block|{
return|return
name|vmls_n_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmlsq_n_s16
end_comment

begin_comment
comment|// CHECK: vmls.i16 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int16x8_t
name|test_vmlsq_n_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|,
name|int16_t
name|c
parameter_list|)
block|{
return|return
name|vmlsq_n_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmlsq_n_s32
end_comment

begin_comment
comment|// CHECK: vmls.i32 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int32x4_t
name|test_vmlsq_n_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|,
name|int32_t
name|c
parameter_list|)
block|{
return|return
name|vmlsq_n_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmlsq_n_u16
end_comment

begin_comment
comment|// CHECK: vmls.i16 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint16x8_t
name|test_vmlsq_n_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|,
name|uint16_t
name|c
parameter_list|)
block|{
return|return
name|vmlsq_n_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmlsq_n_u32
end_comment

begin_comment
comment|// CHECK: vmls.i32 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint32x4_t
name|test_vmlsq_n_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|,
name|uint32_t
name|c
parameter_list|)
block|{
return|return
name|vmlsq_n_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmlsq_n_f32
end_comment

begin_comment
comment|// CHECK-SWIFT: vmul.f32 q{{[0-9]+}}, q{{[0-9]+}}, d{{[0-9]+}}[0]
end_comment

begin_comment
comment|// CHECK-SWIFT: vsub.f32
end_comment

begin_comment
comment|// CHECK-A57: vmls.f32 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|float32x4_t
name|test_vmlsq_n_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|,
name|float32x4_t
name|b
parameter_list|,
name|float32_t
name|c
parameter_list|)
block|{
return|return
name|vmlsq_n_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmovl_s8
end_comment

begin_comment
comment|// CHECK: vmovl.s8 q{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int16x8_t
name|test_vmovl_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
return|return
name|vmovl_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmovl_s16
end_comment

begin_comment
comment|// CHECK: vmovl.s16 q{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int32x4_t
name|test_vmovl_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|)
block|{
return|return
name|vmovl_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmovl_s32
end_comment

begin_comment
comment|// CHECK: vmovl.s32 q{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int64x2_t
name|test_vmovl_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|)
block|{
return|return
name|vmovl_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmovl_u8
end_comment

begin_comment
comment|// CHECK: vmovl.u8 q{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint16x8_t
name|test_vmovl_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|)
block|{
return|return
name|vmovl_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmovl_u16
end_comment

begin_comment
comment|// CHECK: vmovl.u16 q{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint32x4_t
name|test_vmovl_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|)
block|{
return|return
name|vmovl_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmovl_u32
end_comment

begin_comment
comment|// CHECK: vmovl.u32 q{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint64x2_t
name|test_vmovl_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|)
block|{
return|return
name|vmovl_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmovn_s16
end_comment

begin_comment
comment|// CHECK: vmovn.i16 d{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int8x8_t
name|test_vmovn_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
return|return
name|vmovn_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmovn_s32
end_comment

begin_comment
comment|// CHECK: vmovn.i32 d{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int16x4_t
name|test_vmovn_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
return|return
name|vmovn_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmovn_s64
end_comment

begin_comment
comment|// CHECK: vmovn.i64 d{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int32x2_t
name|test_vmovn_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|)
block|{
return|return
name|vmovn_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmovn_u16
end_comment

begin_comment
comment|// CHECK: vmovn.i16 d{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint8x8_t
name|test_vmovn_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|)
block|{
return|return
name|vmovn_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmovn_u32
end_comment

begin_comment
comment|// CHECK: vmovn.i32 d{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint16x4_t
name|test_vmovn_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|)
block|{
return|return
name|vmovn_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmovn_u64
end_comment

begin_comment
comment|// CHECK: vmovn.i64 d{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint32x2_t
name|test_vmovn_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|)
block|{
return|return
name|vmovn_u64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmov_n_u8
end_comment

begin_comment
comment|// CHECK: vmov {{r[0-9]+}}
end_comment

begin_function
name|uint8x8_t
name|test_vmov_n_u8
parameter_list|(
name|uint8_t
name|a
parameter_list|)
block|{
return|return
name|vmov_n_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmov_n_u16
end_comment

begin_comment
comment|// CHECK: vmov {{r[0-9]+}}
end_comment

begin_function
name|uint16x4_t
name|test_vmov_n_u16
parameter_list|(
name|uint16_t
name|a
parameter_list|)
block|{
return|return
name|vmov_n_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmov_n_u32
end_comment

begin_comment
comment|// CHECK: mov {{r[0-9]+}}
end_comment

begin_function
name|uint32x2_t
name|test_vmov_n_u32
parameter_list|(
name|uint32_t
name|a
parameter_list|)
block|{
return|return
name|vmov_n_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmov_n_s8
end_comment

begin_comment
comment|// CHECK: vmov {{r[0-9]+}}
end_comment

begin_function
name|int8x8_t
name|test_vmov_n_s8
parameter_list|(
name|int8_t
name|a
parameter_list|)
block|{
return|return
name|vmov_n_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmov_n_s16
end_comment

begin_comment
comment|// CHECK: vmov {{r[0-9]+}}
end_comment

begin_function
name|int16x4_t
name|test_vmov_n_s16
parameter_list|(
name|int16_t
name|a
parameter_list|)
block|{
return|return
name|vmov_n_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmov_n_s32
end_comment

begin_comment
comment|// CHECK: mov {{r[0-9]+}}
end_comment

begin_function
name|int32x2_t
name|test_vmov_n_s32
parameter_list|(
name|int32_t
name|a
parameter_list|)
block|{
return|return
name|vmov_n_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmov_n_p8
end_comment

begin_comment
comment|// CHECK: vmov {{r[0-9]+}}
end_comment

begin_function
name|poly8x8_t
name|test_vmov_n_p8
parameter_list|(
name|poly8_t
name|a
parameter_list|)
block|{
return|return
name|vmov_n_p8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmov_n_p16
end_comment

begin_comment
comment|// CHECK: vmov {{r[0-9]+}}
end_comment

begin_function
name|poly16x4_t
name|test_vmov_n_p16
parameter_list|(
name|poly16_t
name|a
parameter_list|)
block|{
return|return
name|vmov_n_p16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmov_n_f16
end_comment

begin_comment
comment|// CHECK: vld1.16 {{{d[0-9]+\[\]}}}
end_comment

begin_function
name|float16x4_t
name|test_vmov_n_f16
parameter_list|(
name|float16_t
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vmov_n_f16
argument_list|(
operator|*
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmov_n_f32
end_comment

begin_comment
comment|// CHECK: mov {{r[0-9]+}}
end_comment

begin_function
name|float32x2_t
name|test_vmov_n_f32
parameter_list|(
name|float32_t
name|a
parameter_list|)
block|{
return|return
name|vmov_n_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmovq_n_u8
end_comment

begin_comment
comment|// CHECK: vmov {{r[0-9]+}}
end_comment

begin_function
name|uint8x16_t
name|test_vmovq_n_u8
parameter_list|(
name|uint8_t
name|a
parameter_list|)
block|{
return|return
name|vmovq_n_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmovq_n_u16
end_comment

begin_comment
comment|// CHECK: vmov {{r[0-9]+}}
end_comment

begin_function
name|uint16x8_t
name|test_vmovq_n_u16
parameter_list|(
name|uint16_t
name|a
parameter_list|)
block|{
return|return
name|vmovq_n_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmovq_n_u32
end_comment

begin_comment
comment|// CHECK: vmov {{r[0-9]+}}
end_comment

begin_function
name|uint32x4_t
name|test_vmovq_n_u32
parameter_list|(
name|uint32_t
name|a
parameter_list|)
block|{
return|return
name|vmovq_n_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmovq_n_s8
end_comment

begin_comment
comment|// CHECK: vmov {{r[0-9]+}}
end_comment

begin_function
name|int8x16_t
name|test_vmovq_n_s8
parameter_list|(
name|int8_t
name|a
parameter_list|)
block|{
return|return
name|vmovq_n_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmovq_n_s16
end_comment

begin_comment
comment|// CHECK: vmov {{r[0-9]+}}
end_comment

begin_function
name|int16x8_t
name|test_vmovq_n_s16
parameter_list|(
name|int16_t
name|a
parameter_list|)
block|{
return|return
name|vmovq_n_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmovq_n_s32
end_comment

begin_comment
comment|// CHECK: vmov {{r[0-9]+}}
end_comment

begin_function
name|int32x4_t
name|test_vmovq_n_s32
parameter_list|(
name|int32_t
name|a
parameter_list|)
block|{
return|return
name|vmovq_n_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmovq_n_p8
end_comment

begin_comment
comment|// CHECK: vmov {{r[0-9]+}}
end_comment

begin_function
name|poly8x16_t
name|test_vmovq_n_p8
parameter_list|(
name|poly8_t
name|a
parameter_list|)
block|{
return|return
name|vmovq_n_p8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmovq_n_p16
end_comment

begin_comment
comment|// CHECK: vmov {{r[0-9]+}}
end_comment

begin_function
name|poly16x8_t
name|test_vmovq_n_p16
parameter_list|(
name|poly16_t
name|a
parameter_list|)
block|{
return|return
name|vmovq_n_p16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmovq_n_f16
end_comment

begin_comment
comment|// CHECK: vld1.16 {{{d[0-9]+\[\], d[0-9]+\[\]}}}
end_comment

begin_function
name|float16x8_t
name|test_vmovq_n_f16
parameter_list|(
name|float16_t
modifier|*
name|a
parameter_list|)
block|{
return|return
name|vmovq_n_f16
argument_list|(
operator|*
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmovq_n_f32
end_comment

begin_comment
comment|// CHECK: vmov {{r[0-9]+}}
end_comment

begin_function
name|float32x4_t
name|test_vmovq_n_f32
parameter_list|(
name|float32_t
name|a
parameter_list|)
block|{
return|return
name|vmovq_n_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmov_n_s64
end_comment

begin_comment
comment|// CHECK: vmov.32 [[REG:d[0-9]+]][0], r0
end_comment

begin_comment
comment|// CHECK: vmov.32 [[REG]][1], r1
end_comment

begin_function
name|int64x1_t
name|test_vmov_n_s64
parameter_list|(
name|int64_t
name|a
parameter_list|)
block|{
name|int64x1_t
name|tmp
init|=
name|vmov_n_s64
argument_list|(
name|a
argument_list|)
decl_stmt|;
return|return
name|vadd_s64
argument_list|(
name|tmp
argument_list|,
name|tmp
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmov_n_u64
end_comment

begin_comment
comment|// CHECK: vmov.32 [[REG:d[0-9]+]][0], r0
end_comment

begin_comment
comment|// CHECK: vmov.32 [[REG]][1], r1
end_comment

begin_function
name|uint64x1_t
name|test_vmov_n_u64
parameter_list|(
name|uint64_t
name|a
parameter_list|)
block|{
name|uint64x1_t
name|tmp
init|=
name|vmov_n_u64
argument_list|(
name|a
argument_list|)
decl_stmt|;
return|return
name|vadd_u64
argument_list|(
name|tmp
argument_list|,
name|tmp
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmovq_n_s64
end_comment

begin_comment
comment|// CHECK: vmov {{r[0-9]+}}
end_comment

begin_function
name|int64x2_t
name|test_vmovq_n_s64
parameter_list|(
name|int64_t
name|a
parameter_list|)
block|{
return|return
name|vmovq_n_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmovq_n_u64
end_comment

begin_comment
comment|// CHECK: vmov {{r[0-9]+}}
end_comment

begin_function
name|uint64x2_t
name|test_vmovq_n_u64
parameter_list|(
name|uint64_t
name|a
parameter_list|)
block|{
return|return
name|vmovq_n_u64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmul_s8
end_comment

begin_comment
comment|// CHECK: vmul.i8 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int8x8_t
name|test_vmul_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
return|return
name|vmul_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmul_s16
end_comment

begin_comment
comment|// CHECK: vmul.i16 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int16x4_t
name|test_vmul_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
return|return
name|vmul_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmul_s32
end_comment

begin_comment
comment|// CHECK: vmul.i32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int32x2_t
name|test_vmul_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
return|return
name|vmul_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmul_f32
end_comment

begin_comment
comment|// CHECK: vmul.f32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|float32x2_t
name|test_vmul_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32x2_t
name|b
parameter_list|)
block|{
return|return
name|vmul_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmul_u8
end_comment

begin_comment
comment|// CHECK: vmul.i8 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint8x8_t
name|test_vmul_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|)
block|{
return|return
name|vmul_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmul_u16
end_comment

begin_comment
comment|// CHECK: vmul.i16 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint16x4_t
name|test_vmul_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|)
block|{
return|return
name|vmul_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmul_u32
end_comment

begin_comment
comment|// CHECK: vmul.i32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint32x2_t
name|test_vmul_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|)
block|{
return|return
name|vmul_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmulq_s8
end_comment

begin_comment
comment|// CHECK: vmul.i8 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int8x16_t
name|test_vmulq_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|)
block|{
return|return
name|vmulq_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmulq_s16
end_comment

begin_comment
comment|// CHECK: vmul.i16 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int16x8_t
name|test_vmulq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
return|return
name|vmulq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmulq_s32
end_comment

begin_comment
comment|// CHECK: vmul.i32 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int32x4_t
name|test_vmulq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
return|return
name|vmulq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmulq_f32
end_comment

begin_comment
comment|// CHECK: vmul.f32 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|float32x4_t
name|test_vmulq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|,
name|float32x4_t
name|b
parameter_list|)
block|{
return|return
name|vmulq_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmulq_u8
end_comment

begin_comment
comment|// CHECK: vmul.i8 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint8x16_t
name|test_vmulq_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|,
name|uint8x16_t
name|b
parameter_list|)
block|{
return|return
name|vmulq_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmulq_u16
end_comment

begin_comment
comment|// CHECK: vmul.i16 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint16x8_t
name|test_vmulq_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|)
block|{
return|return
name|vmulq_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmulq_u32
end_comment

begin_comment
comment|// CHECK: vmul.i32 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint32x4_t
name|test_vmulq_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|)
block|{
return|return
name|vmulq_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmull_s8
end_comment

begin_comment
comment|// CHECK: vmull.s8 q{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int16x8_t
name|test_vmull_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
return|return
name|vmull_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmull_s16
end_comment

begin_comment
comment|// CHECK: vmull.s16 q{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int32x4_t
name|test_vmull_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
return|return
name|vmull_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmull_s32
end_comment

begin_comment
comment|// CHECK: vmull.s32 q{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int64x2_t
name|test_vmull_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
return|return
name|vmull_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmull_u8
end_comment

begin_comment
comment|// CHECK: vmull.u8 q{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint16x8_t
name|test_vmull_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|)
block|{
return|return
name|vmull_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmull_u16
end_comment

begin_comment
comment|// CHECK: vmull.u16 q{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint32x4_t
name|test_vmull_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|)
block|{
return|return
name|vmull_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmull_u32
end_comment

begin_comment
comment|// CHECK: vmull.u32 q{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint64x2_t
name|test_vmull_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|)
block|{
return|return
name|vmull_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmull_p8
end_comment

begin_comment
comment|// CHECK: vmull.p8 q{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|poly16x8_t
name|test_vmull_p8
parameter_list|(
name|poly8x8_t
name|a
parameter_list|,
name|poly8x8_t
name|b
parameter_list|)
block|{
return|return
name|vmull_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmull_lane_s16
end_comment

begin_comment
comment|// CHECK: vmull.s16 q{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}[{{[0-9]}}]
end_comment

begin_function
name|int32x4_t
name|test_vmull_lane_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
return|return
name|vmull_lane_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmull_lane_s32
end_comment

begin_comment
comment|// CHECK: vmull.s32 q{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}[{{[0-9]}}]
end_comment

begin_function
name|int64x2_t
name|test_vmull_lane_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
return|return
name|vmull_lane_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmull_lane_u16
end_comment

begin_comment
comment|// CHECK: vmull.u16 q{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}[{{[0-9]}}]
end_comment

begin_function
name|uint32x4_t
name|test_vmull_lane_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|)
block|{
return|return
name|vmull_lane_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmull_lane_u32
end_comment

begin_comment
comment|// CHECK: vmull.u32 q{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}[{{[0-9]}}]
end_comment

begin_function
name|uint64x2_t
name|test_vmull_lane_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|)
block|{
return|return
name|vmull_lane_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmull_n_s16
end_comment

begin_comment
comment|// CHECK: vmull.s16 q{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int32x4_t
name|test_vmull_n_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16_t
name|b
parameter_list|)
block|{
return|return
name|vmull_n_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmull_n_s32
end_comment

begin_comment
comment|// CHECK: vmull.s32 q{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int64x2_t
name|test_vmull_n_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32_t
name|b
parameter_list|)
block|{
return|return
name|vmull_n_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmull_n_u16
end_comment

begin_comment
comment|// CHECK: vmull.u16 q{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint32x4_t
name|test_vmull_n_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16_t
name|b
parameter_list|)
block|{
return|return
name|vmull_n_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmull_n_u32
end_comment

begin_comment
comment|// CHECK: vmull.u32 q{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint64x2_t
name|test_vmull_n_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32_t
name|b
parameter_list|)
block|{
return|return
name|vmull_n_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmul_p8
end_comment

begin_comment
comment|// CHECK: vmul.p8 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|poly8x8_t
name|test_vmul_p8
parameter_list|(
name|poly8x8_t
name|a
parameter_list|,
name|poly8x8_t
name|b
parameter_list|)
block|{
return|return
name|vmul_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmulq_p8
end_comment

begin_comment
comment|// CHECK: vmul.p8 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|poly8x16_t
name|test_vmulq_p8
parameter_list|(
name|poly8x16_t
name|a
parameter_list|,
name|poly8x16_t
name|b
parameter_list|)
block|{
return|return
name|vmulq_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmul_lane_s16
end_comment

begin_comment
comment|// CHECK: vmul.i16 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}[{{[0-9]}}]
end_comment

begin_function
name|int16x4_t
name|test_vmul_lane_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
return|return
name|vmul_lane_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmul_lane_s32
end_comment

begin_comment
comment|// CHECK: vmul.i32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}[{{[0-9]}}]
end_comment

begin_function
name|int32x2_t
name|test_vmul_lane_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
return|return
name|vmul_lane_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmul_lane_f32
end_comment

begin_comment
comment|// CHECK: vmul.f32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}[{{[0-9]}}]
end_comment

begin_function
name|float32x2_t
name|test_vmul_lane_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32x2_t
name|b
parameter_list|)
block|{
return|return
name|vmul_lane_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmul_lane_u16
end_comment

begin_comment
comment|// CHECK: vmul.i16 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}[{{[0-9]}}]
end_comment

begin_function
name|uint16x4_t
name|test_vmul_lane_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|)
block|{
return|return
name|vmul_lane_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmul_lane_u32
end_comment

begin_comment
comment|// CHECK: vmul.i32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}[{{[0-9]}}]
end_comment

begin_function
name|uint32x2_t
name|test_vmul_lane_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|)
block|{
return|return
name|vmul_lane_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmulq_lane_s16
end_comment

begin_comment
comment|// CHECK: vmul.i16 q{{[0-9]+}}, q{{[0-9]+}}, d{{[0-9]+}}[{{[0-9]}}]
end_comment

begin_function
name|int16x8_t
name|test_vmulq_lane_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
return|return
name|vmulq_lane_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmulq_lane_s32
end_comment

begin_comment
comment|// CHECK: vmul.i32 q{{[0-9]+}}, q{{[0-9]+}}, d{{[0-9]+}}[{{[0-9]}}]
end_comment

begin_function
name|int32x4_t
name|test_vmulq_lane_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
return|return
name|vmulq_lane_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmulq_lane_f32
end_comment

begin_comment
comment|// CHECK: vmul.f32 q{{[0-9]+}}, q{{[0-9]+}}, d{{[0-9]+}}[{{[0-9]}}]
end_comment

begin_function
name|float32x4_t
name|test_vmulq_lane_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|,
name|float32x2_t
name|b
parameter_list|)
block|{
return|return
name|vmulq_lane_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmulq_lane_u16
end_comment

begin_comment
comment|// CHECK: vmul.i16 q{{[0-9]+}}, q{{[0-9]+}}, d{{[0-9]+}}[{{[0-9]}}]
end_comment

begin_function
name|uint16x8_t
name|test_vmulq_lane_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|)
block|{
return|return
name|vmulq_lane_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmulq_lane_u32
end_comment

begin_comment
comment|// CHECK: vmul.i32 q{{[0-9]+}}, q{{[0-9]+}}, d{{[0-9]+}}[{{[0-9]}}]
end_comment

begin_function
name|uint32x4_t
name|test_vmulq_lane_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|)
block|{
return|return
name|vmulq_lane_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmul_n_s16
end_comment

begin_comment
comment|// CHECK: vmul.i16 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int16x4_t
name|test_vmul_n_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16_t
name|b
parameter_list|)
block|{
return|return
name|vmul_n_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmul_n_s32
end_comment

begin_comment
comment|// CHECK: vmul.i32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int32x2_t
name|test_vmul_n_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32_t
name|b
parameter_list|)
block|{
return|return
name|vmul_n_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmul_n_f32
end_comment

begin_comment
comment|// CHECK: vmul.f32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|float32x2_t
name|test_vmul_n_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32_t
name|b
parameter_list|)
block|{
return|return
name|vmul_n_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmul_n_u16
end_comment

begin_comment
comment|// CHECK: vmul.i16 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint16x4_t
name|test_vmul_n_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16_t
name|b
parameter_list|)
block|{
return|return
name|vmul_n_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmul_n_u32
end_comment

begin_comment
comment|// CHECK: vmul.i32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint32x2_t
name|test_vmul_n_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32_t
name|b
parameter_list|)
block|{
return|return
name|vmul_n_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmulq_n_s16
end_comment

begin_comment
comment|// CHECK: vmul.i16 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int16x8_t
name|test_vmulq_n_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16_t
name|b
parameter_list|)
block|{
return|return
name|vmulq_n_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmulq_n_s32
end_comment

begin_comment
comment|// CHECK: vmul.i32 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int32x4_t
name|test_vmulq_n_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32_t
name|b
parameter_list|)
block|{
return|return
name|vmulq_n_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmulq_n_f32
end_comment

begin_comment
comment|// CHECK: vmul.f32 q{{[0-9]+}}, q{{[0-9]+}}, d{{[0-9]+}}[0]
end_comment

begin_function
name|float32x4_t
name|test_vmulq_n_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|,
name|float32_t
name|b
parameter_list|)
block|{
return|return
name|vmulq_n_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmulq_n_u16
end_comment

begin_comment
comment|// CHECK: vmul.i16 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint16x8_t
name|test_vmulq_n_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16_t
name|b
parameter_list|)
block|{
return|return
name|vmulq_n_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmulq_n_u32
end_comment

begin_comment
comment|// CHECK: vmul.i32 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint32x4_t
name|test_vmulq_n_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32_t
name|b
parameter_list|)
block|{
return|return
name|vmulq_n_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmvn_s8
end_comment

begin_comment
comment|// CHECK: vmvn d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int8x8_t
name|test_vmvn_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
return|return
name|vmvn_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmvn_s16
end_comment

begin_comment
comment|// CHECK: vmvn d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int16x4_t
name|test_vmvn_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|)
block|{
return|return
name|vmvn_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmvn_s32
end_comment

begin_comment
comment|// CHECK: vmvn d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int32x2_t
name|test_vmvn_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|)
block|{
return|return
name|vmvn_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmvn_u8
end_comment

begin_comment
comment|// CHECK: vmvn d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint8x8_t
name|test_vmvn_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|)
block|{
return|return
name|vmvn_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmvn_u16
end_comment

begin_comment
comment|// CHECK: vmvn d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint16x4_t
name|test_vmvn_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|)
block|{
return|return
name|vmvn_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmvn_u32
end_comment

begin_comment
comment|// CHECK: vmvn d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint32x2_t
name|test_vmvn_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|)
block|{
return|return
name|vmvn_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmvn_p8
end_comment

begin_comment
comment|// CHECK: vmvn d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|poly8x8_t
name|test_vmvn_p8
parameter_list|(
name|poly8x8_t
name|a
parameter_list|)
block|{
return|return
name|vmvn_p8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmvnq_s8
end_comment

begin_comment
comment|// CHECK: vmvn q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int8x16_t
name|test_vmvnq_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
return|return
name|vmvnq_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmvnq_s16
end_comment

begin_comment
comment|// CHECK: vmvn q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int16x8_t
name|test_vmvnq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
return|return
name|vmvnq_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmvnq_s32
end_comment

begin_comment
comment|// CHECK: vmvn q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int32x4_t
name|test_vmvnq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
return|return
name|vmvnq_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmvnq_u8
end_comment

begin_comment
comment|// CHECK: vmvn q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint8x16_t
name|test_vmvnq_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|)
block|{
return|return
name|vmvnq_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmvnq_u16
end_comment

begin_comment
comment|// CHECK: vmvn q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint16x8_t
name|test_vmvnq_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|)
block|{
return|return
name|vmvnq_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmvnq_u32
end_comment

begin_comment
comment|// CHECK: vmvn q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint32x4_t
name|test_vmvnq_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|)
block|{
return|return
name|vmvnq_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmvnq_p8
end_comment

begin_comment
comment|// CHECK: vmvn q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|poly8x16_t
name|test_vmvnq_p8
parameter_list|(
name|poly8x16_t
name|a
parameter_list|)
block|{
return|return
name|vmvnq_p8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vneg_s8
end_comment

begin_comment
comment|// CHECK: vneg.s8 d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int8x8_t
name|test_vneg_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
return|return
name|vneg_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vneg_s16
end_comment

begin_comment
comment|// CHECK: vneg.s16 d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int16x4_t
name|test_vneg_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|)
block|{
return|return
name|vneg_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vneg_s32
end_comment

begin_comment
comment|// CHECK: vneg.s32 d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int32x2_t
name|test_vneg_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|)
block|{
return|return
name|vneg_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vneg_f32
end_comment

begin_comment
comment|// CHECK: vneg.f32 d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|float32x2_t
name|test_vneg_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
return|return
name|vneg_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vnegq_s8
end_comment

begin_comment
comment|// CHECK: vneg.s8 q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int8x16_t
name|test_vnegq_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
return|return
name|vnegq_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vnegq_s16
end_comment

begin_comment
comment|// CHECK: vneg.s16 q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int16x8_t
name|test_vnegq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
return|return
name|vnegq_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vnegq_s32
end_comment

begin_comment
comment|// CHECK: vneg.s32 q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int32x4_t
name|test_vnegq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
return|return
name|vnegq_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vnegq_f32
end_comment

begin_comment
comment|// CHECK: vneg.f32 q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|float32x4_t
name|test_vnegq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
return|return
name|vnegq_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vorn_s8
end_comment

begin_comment
comment|// CHECK: vorn d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int8x8_t
name|test_vorn_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
return|return
name|vorn_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vorn_s16
end_comment

begin_comment
comment|// CHECK: vorn d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int16x4_t
name|test_vorn_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
return|return
name|vorn_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vorn_s32
end_comment

begin_comment
comment|// CHECK: vorn d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int32x2_t
name|test_vorn_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
return|return
name|vorn_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vorn_s64
end_comment

begin_comment
comment|// CHECK: vorn d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int64x1_t
name|test_vorn_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|,
name|int64x1_t
name|b
parameter_list|)
block|{
return|return
name|vorn_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vorn_u8
end_comment

begin_comment
comment|// CHECK: vorn d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint8x8_t
name|test_vorn_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|)
block|{
return|return
name|vorn_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vorn_u16
end_comment

begin_comment
comment|// CHECK: vorn d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint16x4_t
name|test_vorn_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|)
block|{
return|return
name|vorn_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vorn_u32
end_comment

begin_comment
comment|// CHECK: vorn d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint32x2_t
name|test_vorn_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|)
block|{
return|return
name|vorn_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vorn_u64
end_comment

begin_comment
comment|// CHECK: vorn d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint64x1_t
name|test_vorn_u64
parameter_list|(
name|uint64x1_t
name|a
parameter_list|,
name|uint64x1_t
name|b
parameter_list|)
block|{
return|return
name|vorn_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vornq_s8
end_comment

begin_comment
comment|// CHECK: vorn q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int8x16_t
name|test_vornq_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|)
block|{
return|return
name|vornq_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vornq_s16
end_comment

begin_comment
comment|// CHECK: vorn q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int16x8_t
name|test_vornq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
return|return
name|vornq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vornq_s32
end_comment

begin_comment
comment|// CHECK: vorn q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int32x4_t
name|test_vornq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
return|return
name|vornq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vornq_s64
end_comment

begin_comment
comment|// CHECK: vorn q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int64x2_t
name|test_vornq_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int64x2_t
name|b
parameter_list|)
block|{
return|return
name|vornq_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vornq_u8
end_comment

begin_comment
comment|// CHECK: vorn q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint8x16_t
name|test_vornq_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|,
name|uint8x16_t
name|b
parameter_list|)
block|{
return|return
name|vornq_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vornq_u16
end_comment

begin_comment
comment|// CHECK: vorn q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint16x8_t
name|test_vornq_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|)
block|{
return|return
name|vornq_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vornq_u32
end_comment

begin_comment
comment|// CHECK: vorn q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint32x4_t
name|test_vornq_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|)
block|{
return|return
name|vornq_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vornq_u64
end_comment

begin_comment
comment|// CHECK: vorn q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint64x2_t
name|test_vornq_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|,
name|uint64x2_t
name|b
parameter_list|)
block|{
return|return
name|vornq_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vorr_s8
end_comment

begin_comment
comment|// CHECK: vorr d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int8x8_t
name|test_vorr_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
return|return
name|vorr_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vorr_s16
end_comment

begin_comment
comment|// CHECK: vorr d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int16x4_t
name|test_vorr_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
return|return
name|vorr_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vorr_s32
end_comment

begin_comment
comment|// CHECK: vorr d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int32x2_t
name|test_vorr_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
return|return
name|vorr_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vorr_s64
end_comment

begin_comment
comment|// CHECK: vorr d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int64x1_t
name|test_vorr_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|,
name|int64x1_t
name|b
parameter_list|)
block|{
return|return
name|vorr_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vorr_u8
end_comment

begin_comment
comment|// CHECK: vorr d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint8x8_t
name|test_vorr_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|)
block|{
return|return
name|vorr_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vorr_u16
end_comment

begin_comment
comment|// CHECK: vorr d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint16x4_t
name|test_vorr_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|)
block|{
return|return
name|vorr_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vorr_u32
end_comment

begin_comment
comment|// CHECK: vorr d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint32x2_t
name|test_vorr_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|)
block|{
return|return
name|vorr_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vorr_u64
end_comment

begin_comment
comment|// CHECK: vorr d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint64x1_t
name|test_vorr_u64
parameter_list|(
name|uint64x1_t
name|a
parameter_list|,
name|uint64x1_t
name|b
parameter_list|)
block|{
return|return
name|vorr_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vorrq_s8
end_comment

begin_comment
comment|// CHECK: vorr q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int8x16_t
name|test_vorrq_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|)
block|{
return|return
name|vorrq_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vorrq_s16
end_comment

begin_comment
comment|// CHECK: vorr q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int16x8_t
name|test_vorrq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
return|return
name|vorrq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vorrq_s32
end_comment

begin_comment
comment|// CHECK: vorr q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int32x4_t
name|test_vorrq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
return|return
name|vorrq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vorrq_s64
end_comment

begin_comment
comment|// CHECK: vorr q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int64x2_t
name|test_vorrq_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int64x2_t
name|b
parameter_list|)
block|{
return|return
name|vorrq_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vorrq_u8
end_comment

begin_comment
comment|// CHECK: vorr q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint8x16_t
name|test_vorrq_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|,
name|uint8x16_t
name|b
parameter_list|)
block|{
return|return
name|vorrq_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vorrq_u16
end_comment

begin_comment
comment|// CHECK: vorr q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint16x8_t
name|test_vorrq_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|)
block|{
return|return
name|vorrq_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vorrq_u32
end_comment

begin_comment
comment|// CHECK: vorr q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint32x4_t
name|test_vorrq_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|)
block|{
return|return
name|vorrq_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vorrq_u64
end_comment

begin_comment
comment|// CHECK: vorr q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint64x2_t
name|test_vorrq_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|,
name|uint64x2_t
name|b
parameter_list|)
block|{
return|return
name|vorrq_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vpadal_s8
end_comment

begin_comment
comment|// CHECK: vpadal.s8 d{{[0-9]+}}, d{{[0-9]+}}
end_comment

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
return|return
name|vpadal_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vpadal_s16
end_comment

begin_comment
comment|// CHECK: vpadal.s16 d{{[0-9]+}}, d{{[0-9]+}}
end_comment

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
return|return
name|vpadal_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vpadal_s32
end_comment

begin_comment
comment|// CHECK: vpadal.s32 d{{[0-9]+}}, d{{[0-9]+}}
end_comment

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
return|return
name|vpadal_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vpadal_u8
end_comment

begin_comment
comment|// CHECK: vpadal.u8 d{{[0-9]+}}, d{{[0-9]+}}
end_comment

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
return|return
name|vpadal_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vpadal_u16
end_comment

begin_comment
comment|// CHECK: vpadal.u16 d{{[0-9]+}}, d{{[0-9]+}}
end_comment

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
return|return
name|vpadal_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vpadal_u32
end_comment

begin_comment
comment|// CHECK: vpadal.u32 d{{[0-9]+}}, d{{[0-9]+}}
end_comment

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
return|return
name|vpadal_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vpadalq_s8
end_comment

begin_comment
comment|// CHECK: vpadal.s8 q{{[0-9]+}}, q{{[0-9]+}}
end_comment

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
return|return
name|vpadalq_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vpadalq_s16
end_comment

begin_comment
comment|// CHECK: vpadal.s16 q{{[0-9]+}}, q{{[0-9]+}}
end_comment

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
return|return
name|vpadalq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vpadalq_s32
end_comment

begin_comment
comment|// CHECK: vpadal.s32 q{{[0-9]+}}, q{{[0-9]+}}
end_comment

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
return|return
name|vpadalq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vpadalq_u8
end_comment

begin_comment
comment|// CHECK: vpadal.u8 q{{[0-9]+}}, q{{[0-9]+}}
end_comment

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
return|return
name|vpadalq_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vpadalq_u16
end_comment

begin_comment
comment|// CHECK: vpadal.u16 q{{[0-9]+}}, q{{[0-9]+}}
end_comment

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
return|return
name|vpadalq_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vpadalq_u32
end_comment

begin_comment
comment|// CHECK: vpadal.u32 q{{[0-9]+}}, q{{[0-9]+}}
end_comment

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
return|return
name|vpadalq_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vpadd_s8
end_comment

begin_comment
comment|// CHECK: vpadd.i8 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int8x8_t
name|test_vpadd_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
return|return
name|vpadd_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vpadd_s16
end_comment

begin_comment
comment|// CHECK: vpadd.i16 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int16x4_t
name|test_vpadd_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
return|return
name|vpadd_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vpadd_s32
end_comment

begin_comment
comment|// CHECK: vpadd.i32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int32x2_t
name|test_vpadd_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
return|return
name|vpadd_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vpadd_u8
end_comment

begin_comment
comment|// CHECK: vpadd.i8 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint8x8_t
name|test_vpadd_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|)
block|{
return|return
name|vpadd_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vpadd_u16
end_comment

begin_comment
comment|// CHECK: vpadd.i16 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint16x4_t
name|test_vpadd_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|)
block|{
return|return
name|vpadd_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vpadd_u32
end_comment

begin_comment
comment|// CHECK: vpadd.i32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint32x2_t
name|test_vpadd_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|)
block|{
return|return
name|vpadd_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vpadd_f32
end_comment

begin_comment
comment|// CHECK: vpadd.f32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|float32x2_t
name|test_vpadd_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32x2_t
name|b
parameter_list|)
block|{
return|return
name|vpadd_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vpaddl_s8
end_comment

begin_comment
comment|// CHECK: vpaddl.s8 d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int16x4_t
name|test_vpaddl_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
return|return
name|vpaddl_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vpaddl_s16
end_comment

begin_comment
comment|// CHECK: vpaddl.s16 d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int32x2_t
name|test_vpaddl_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|)
block|{
return|return
name|vpaddl_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vpaddl_s32
end_comment

begin_comment
comment|// CHECK: vpaddl.s32 d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int64x1_t
name|test_vpaddl_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|)
block|{
return|return
name|vpaddl_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vpaddl_u8
end_comment

begin_comment
comment|// CHECK: vpaddl.u8 d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint16x4_t
name|test_vpaddl_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|)
block|{
return|return
name|vpaddl_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vpaddl_u16
end_comment

begin_comment
comment|// CHECK: vpaddl.u16 d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint32x2_t
name|test_vpaddl_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|)
block|{
return|return
name|vpaddl_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vpaddl_u32
end_comment

begin_comment
comment|// CHECK: vpaddl.u32 d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint64x1_t
name|test_vpaddl_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|)
block|{
return|return
name|vpaddl_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vpaddlq_s8
end_comment

begin_comment
comment|// CHECK: vpaddl.s8 q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int16x8_t
name|test_vpaddlq_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
return|return
name|vpaddlq_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vpaddlq_s16
end_comment

begin_comment
comment|// CHECK: vpaddl.s16 q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int32x4_t
name|test_vpaddlq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
return|return
name|vpaddlq_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vpaddlq_s32
end_comment

begin_comment
comment|// CHECK: vpaddl.s32 q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int64x2_t
name|test_vpaddlq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
return|return
name|vpaddlq_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vpaddlq_u8
end_comment

begin_comment
comment|// CHECK: vpaddl.u8 q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint16x8_t
name|test_vpaddlq_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|)
block|{
return|return
name|vpaddlq_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vpaddlq_u16
end_comment

begin_comment
comment|// CHECK: vpaddl.u16 q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint32x4_t
name|test_vpaddlq_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|)
block|{
return|return
name|vpaddlq_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vpaddlq_u32
end_comment

begin_comment
comment|// CHECK: vpaddl.u32 q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint64x2_t
name|test_vpaddlq_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|)
block|{
return|return
name|vpaddlq_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vpmax_s8
end_comment

begin_comment
comment|// CHECK: vpmax.s8 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int8x8_t
name|test_vpmax_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
return|return
name|vpmax_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vpmax_s16
end_comment

begin_comment
comment|// CHECK: vpmax.s16 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int16x4_t
name|test_vpmax_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
return|return
name|vpmax_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vpmax_s32
end_comment

begin_comment
comment|// CHECK: vpmax.s32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int32x2_t
name|test_vpmax_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
return|return
name|vpmax_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vpmax_u8
end_comment

begin_comment
comment|// CHECK: vpmax.u8 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint8x8_t
name|test_vpmax_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|)
block|{
return|return
name|vpmax_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vpmax_u16
end_comment

begin_comment
comment|// CHECK: vpmax.u16 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint16x4_t
name|test_vpmax_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|)
block|{
return|return
name|vpmax_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vpmax_u32
end_comment

begin_comment
comment|// CHECK: vpmax.u32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint32x2_t
name|test_vpmax_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|)
block|{
return|return
name|vpmax_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vpmax_f32
end_comment

begin_comment
comment|// CHECK: vpmax.f32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|float32x2_t
name|test_vpmax_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32x2_t
name|b
parameter_list|)
block|{
return|return
name|vpmax_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vpmin_s8
end_comment

begin_comment
comment|// CHECK: vpmin.s8 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int8x8_t
name|test_vpmin_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
return|return
name|vpmin_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vpmin_s16
end_comment

begin_comment
comment|// CHECK: vpmin.s16 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int16x4_t
name|test_vpmin_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
return|return
name|vpmin_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vpmin_s32
end_comment

begin_comment
comment|// CHECK: vpmin.s32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int32x2_t
name|test_vpmin_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
return|return
name|vpmin_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vpmin_u8
end_comment

begin_comment
comment|// CHECK: vpmin.u8 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint8x8_t
name|test_vpmin_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|)
block|{
return|return
name|vpmin_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vpmin_u16
end_comment

begin_comment
comment|// CHECK: vpmin.u16 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint16x4_t
name|test_vpmin_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|)
block|{
return|return
name|vpmin_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vpmin_u32
end_comment

begin_comment
comment|// CHECK: vpmin.u32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint32x2_t
name|test_vpmin_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|)
block|{
return|return
name|vpmin_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vpmin_f32
end_comment

begin_comment
comment|// CHECK: vpmin.f32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|float32x2_t
name|test_vpmin_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32x2_t
name|b
parameter_list|)
block|{
return|return
name|vpmin_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqabs_s8
end_comment

begin_comment
comment|// CHECK: vqabs.s8 d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int8x8_t
name|test_vqabs_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
return|return
name|vqabs_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqabs_s16
end_comment

begin_comment
comment|// CHECK: vqabs.s16 d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int16x4_t
name|test_vqabs_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|)
block|{
return|return
name|vqabs_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqabs_s32
end_comment

begin_comment
comment|// CHECK: vqabs.s32 d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int32x2_t
name|test_vqabs_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|)
block|{
return|return
name|vqabs_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqabsq_s8
end_comment

begin_comment
comment|// CHECK: vqabs.s8 q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int8x16_t
name|test_vqabsq_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
return|return
name|vqabsq_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqabsq_s16
end_comment

begin_comment
comment|// CHECK: vqabs.s16 q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int16x8_t
name|test_vqabsq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
return|return
name|vqabsq_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqabsq_s32
end_comment

begin_comment
comment|// CHECK: vqabs.s32 q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int32x4_t
name|test_vqabsq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
return|return
name|vqabsq_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqadd_s8
end_comment

begin_comment
comment|// CHECK: vqadd.s8 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int8x8_t
name|test_vqadd_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
return|return
name|vqadd_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqadd_s16
end_comment

begin_comment
comment|// CHECK: vqadd.s16 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int16x4_t
name|test_vqadd_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
return|return
name|vqadd_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqadd_s32
end_comment

begin_comment
comment|// CHECK: vqadd.s32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int32x2_t
name|test_vqadd_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
return|return
name|vqadd_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqadd_s64
end_comment

begin_comment
comment|// CHECK: vqadd.s64 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int64x1_t
name|test_vqadd_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|,
name|int64x1_t
name|b
parameter_list|)
block|{
return|return
name|vqadd_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqadd_u8
end_comment

begin_comment
comment|// CHECK: vqadd.u8 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint8x8_t
name|test_vqadd_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|)
block|{
return|return
name|vqadd_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqadd_u16
end_comment

begin_comment
comment|// CHECK: vqadd.u16 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint16x4_t
name|test_vqadd_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|)
block|{
return|return
name|vqadd_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqadd_u32
end_comment

begin_comment
comment|// CHECK: vqadd.u32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint32x2_t
name|test_vqadd_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|)
block|{
return|return
name|vqadd_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqadd_u64
end_comment

begin_comment
comment|// CHECK: vqadd.u64 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint64x1_t
name|test_vqadd_u64
parameter_list|(
name|uint64x1_t
name|a
parameter_list|,
name|uint64x1_t
name|b
parameter_list|)
block|{
return|return
name|vqadd_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqaddq_s8
end_comment

begin_comment
comment|// CHECK: vqadd.s8 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int8x16_t
name|test_vqaddq_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|)
block|{
return|return
name|vqaddq_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqaddq_s16
end_comment

begin_comment
comment|// CHECK: vqadd.s16 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int16x8_t
name|test_vqaddq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
return|return
name|vqaddq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqaddq_s32
end_comment

begin_comment
comment|// CHECK: vqadd.s32 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int32x4_t
name|test_vqaddq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
return|return
name|vqaddq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqaddq_s64
end_comment

begin_comment
comment|// CHECK: vqadd.s64 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int64x2_t
name|test_vqaddq_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int64x2_t
name|b
parameter_list|)
block|{
return|return
name|vqaddq_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqaddq_u8
end_comment

begin_comment
comment|// CHECK: vqadd.u8 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint8x16_t
name|test_vqaddq_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|,
name|uint8x16_t
name|b
parameter_list|)
block|{
return|return
name|vqaddq_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqaddq_u16
end_comment

begin_comment
comment|// CHECK: vqadd.u16 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint16x8_t
name|test_vqaddq_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|)
block|{
return|return
name|vqaddq_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqaddq_u32
end_comment

begin_comment
comment|// CHECK: vqadd.u32 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint32x4_t
name|test_vqaddq_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|)
block|{
return|return
name|vqaddq_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqaddq_u64
end_comment

begin_comment
comment|// CHECK: vqadd.u64 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint64x2_t
name|test_vqaddq_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|,
name|uint64x2_t
name|b
parameter_list|)
block|{
return|return
name|vqaddq_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqdmlal_s16
end_comment

begin_comment
comment|// CHECK: vqdmlal.s16 q{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int32x4_t
name|test_vqdmlal_s16
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|,
name|int16x4_t
name|c
parameter_list|)
block|{
return|return
name|vqdmlal_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqdmlal_s32
end_comment

begin_comment
comment|// CHECK: vqdmlal.s32 q{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int64x2_t
name|test_vqdmlal_s32
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|,
name|int32x2_t
name|c
parameter_list|)
block|{
return|return
name|vqdmlal_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqdmlal_lane_s16
end_comment

begin_comment
comment|// CHECK: vqdmlal.s16 q{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}[{{[0-9]}}]
end_comment

begin_function
name|int32x4_t
name|test_vqdmlal_lane_s16
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|,
name|int16x4_t
name|c
parameter_list|)
block|{
return|return
name|vqdmlal_lane_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqdmlal_lane_s32
end_comment

begin_comment
comment|// CHECK: vqdmlal.s32 q{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}[{{[0-9]}}]
end_comment

begin_function
name|int64x2_t
name|test_vqdmlal_lane_s32
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|,
name|int32x2_t
name|c
parameter_list|)
block|{
return|return
name|vqdmlal_lane_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqdmlal_n_s16
end_comment

begin_comment
comment|// CHECK: vqdmlal.s16 q{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int32x4_t
name|test_vqdmlal_n_s16
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|,
name|int16_t
name|c
parameter_list|)
block|{
return|return
name|vqdmlal_n_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqdmlal_n_s32
end_comment

begin_comment
comment|// CHECK: vqdmlal.s32 q{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int64x2_t
name|test_vqdmlal_n_s32
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|,
name|int32_t
name|c
parameter_list|)
block|{
return|return
name|vqdmlal_n_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqdmlsl_s16
end_comment

begin_comment
comment|// CHECK: vqdmlsl.s16 q{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int32x4_t
name|test_vqdmlsl_s16
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|,
name|int16x4_t
name|c
parameter_list|)
block|{
return|return
name|vqdmlsl_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqdmlsl_s32
end_comment

begin_comment
comment|// CHECK: vqdmlsl.s32 q{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int64x2_t
name|test_vqdmlsl_s32
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|,
name|int32x2_t
name|c
parameter_list|)
block|{
return|return
name|vqdmlsl_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqdmlsl_lane_s16
end_comment

begin_comment
comment|// CHECK: vqdmlsl.s16 q{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}[{{[0-9]}}]
end_comment

begin_function
name|int32x4_t
name|test_vqdmlsl_lane_s16
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|,
name|int16x4_t
name|c
parameter_list|)
block|{
return|return
name|vqdmlsl_lane_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqdmlsl_lane_s32
end_comment

begin_comment
comment|// CHECK: vqdmlsl.s32 q{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}[{{[0-9]}}]
end_comment

begin_function
name|int64x2_t
name|test_vqdmlsl_lane_s32
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|,
name|int32x2_t
name|c
parameter_list|)
block|{
return|return
name|vqdmlsl_lane_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqdmlsl_n_s16
end_comment

begin_comment
comment|// CHECK: vqdmlsl.s16 q{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int32x4_t
name|test_vqdmlsl_n_s16
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|,
name|int16_t
name|c
parameter_list|)
block|{
return|return
name|vqdmlsl_n_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqdmlsl_n_s32
end_comment

begin_comment
comment|// CHECK: vqdmlsl.s32 q{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int64x2_t
name|test_vqdmlsl_n_s32
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|,
name|int32_t
name|c
parameter_list|)
block|{
return|return
name|vqdmlsl_n_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqdmulh_s16
end_comment

begin_comment
comment|// CHECK: vqdmulh.s16 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int16x4_t
name|test_vqdmulh_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
return|return
name|vqdmulh_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqdmulh_s32
end_comment

begin_comment
comment|// CHECK: vqdmulh.s32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int32x2_t
name|test_vqdmulh_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
return|return
name|vqdmulh_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqdmulhq_s16
end_comment

begin_comment
comment|// CHECK: vqdmulh.s16 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int16x8_t
name|test_vqdmulhq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
return|return
name|vqdmulhq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqdmulhq_s32
end_comment

begin_comment
comment|// CHECK: vqdmulh.s32 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int32x4_t
name|test_vqdmulhq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
return|return
name|vqdmulhq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqdmulh_lane_s16
end_comment

begin_comment
comment|// CHECK: vqdmulh.s16 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}[{{[0-9]}}]
end_comment

begin_function
name|int16x4_t
name|test_vqdmulh_lane_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
return|return
name|vqdmulh_lane_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqdmulh_lane_s32
end_comment

begin_comment
comment|// CHECK: vqdmulh.s32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}[{{[0-9]}}]
end_comment

begin_function
name|int32x2_t
name|test_vqdmulh_lane_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
return|return
name|vqdmulh_lane_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqdmulhq_lane_s16
end_comment

begin_comment
comment|// CHECK: vqdmulh.s16 q{{[0-9]+}}, q{{[0-9]+}}, d{{[0-9]+}}[{{[0-9]}}]
end_comment

begin_function
name|int16x8_t
name|test_vqdmulhq_lane_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
return|return
name|vqdmulhq_lane_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqdmulhq_lane_s32
end_comment

begin_comment
comment|// CHECK: vqdmulh.s32 q{{[0-9]+}}, q{{[0-9]+}}, d{{[0-9]+}}[{{[0-9]}}]
end_comment

begin_function
name|int32x4_t
name|test_vqdmulhq_lane_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
return|return
name|vqdmulhq_lane_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqdmulh_n_s16
end_comment

begin_comment
comment|// CHECK: vqdmulh.s16 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int16x4_t
name|test_vqdmulh_n_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16_t
name|b
parameter_list|)
block|{
return|return
name|vqdmulh_n_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqdmulh_n_s32
end_comment

begin_comment
comment|// CHECK: vqdmulh.s32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int32x2_t
name|test_vqdmulh_n_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32_t
name|b
parameter_list|)
block|{
return|return
name|vqdmulh_n_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqdmulhq_n_s16
end_comment

begin_comment
comment|// CHECK: vqdmulh.s16 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int16x8_t
name|test_vqdmulhq_n_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16_t
name|b
parameter_list|)
block|{
return|return
name|vqdmulhq_n_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqdmulhq_n_s32
end_comment

begin_comment
comment|// CHECK: vqdmulh.s32 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int32x4_t
name|test_vqdmulhq_n_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32_t
name|b
parameter_list|)
block|{
return|return
name|vqdmulhq_n_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqdmull_s16
end_comment

begin_comment
comment|// CHECK: vqdmull.s16 q{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int32x4_t
name|test_vqdmull_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
return|return
name|vqdmull_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqdmull_s32
end_comment

begin_comment
comment|// CHECK: vqdmull.s32 q{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int64x2_t
name|test_vqdmull_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
return|return
name|vqdmull_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqdmull_lane_s16
end_comment

begin_comment
comment|// CHECK: vqdmull.s16 q{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}[{{[0-9]}}]
end_comment

begin_function
name|int32x4_t
name|test_vqdmull_lane_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
return|return
name|vqdmull_lane_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqdmull_lane_s32
end_comment

begin_comment
comment|// CHECK: vqdmull.s32 q{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}[{{[0-9]}}]
end_comment

begin_function
name|int64x2_t
name|test_vqdmull_lane_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
return|return
name|vqdmull_lane_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqdmull_n_s16
end_comment

begin_comment
comment|// CHECK: vqdmull.s16 q{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int32x4_t
name|test_vqdmull_n_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16_t
name|b
parameter_list|)
block|{
return|return
name|vqdmull_n_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqdmull_n_s32
end_comment

begin_comment
comment|// CHECK: vqdmull.s32 q{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int64x2_t
name|test_vqdmull_n_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32_t
name|b
parameter_list|)
block|{
return|return
name|vqdmull_n_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqmovn_s16
end_comment

begin_comment
comment|// CHECK: vqmovn.s16 d{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int8x8_t
name|test_vqmovn_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
return|return
name|vqmovn_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqmovn_s32
end_comment

begin_comment
comment|// CHECK: vqmovn.s32 d{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int16x4_t
name|test_vqmovn_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
return|return
name|vqmovn_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqmovn_s64
end_comment

begin_comment
comment|// CHECK: vqmovn.s64 d{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int32x2_t
name|test_vqmovn_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|)
block|{
return|return
name|vqmovn_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqmovn_u16
end_comment

begin_comment
comment|// CHECK: vqmovn.u16 d{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint8x8_t
name|test_vqmovn_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|)
block|{
return|return
name|vqmovn_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqmovn_u32
end_comment

begin_comment
comment|// CHECK: vqmovn.u32 d{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint16x4_t
name|test_vqmovn_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|)
block|{
return|return
name|vqmovn_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqmovn_u64
end_comment

begin_comment
comment|// CHECK: vqmovn.u64 d{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint32x2_t
name|test_vqmovn_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|)
block|{
return|return
name|vqmovn_u64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqmovun_s16
end_comment

begin_comment
comment|// CHECK: vqmovun.s16 d{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint8x8_t
name|test_vqmovun_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
return|return
name|vqmovun_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqmovun_s32
end_comment

begin_comment
comment|// CHECK: vqmovun.s32 d{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint16x4_t
name|test_vqmovun_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
return|return
name|vqmovun_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqmovun_s64
end_comment

begin_comment
comment|// CHECK: vqmovun.s64 d{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint32x2_t
name|test_vqmovun_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|)
block|{
return|return
name|vqmovun_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqneg_s8
end_comment

begin_comment
comment|// CHECK: vqneg.s8 d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int8x8_t
name|test_vqneg_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
return|return
name|vqneg_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqneg_s16
end_comment

begin_comment
comment|// CHECK: vqneg.s16 d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int16x4_t
name|test_vqneg_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|)
block|{
return|return
name|vqneg_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqneg_s32
end_comment

begin_comment
comment|// CHECK: vqneg.s32 d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int32x2_t
name|test_vqneg_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|)
block|{
return|return
name|vqneg_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqnegq_s8
end_comment

begin_comment
comment|// CHECK: vqneg.s8 q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int8x16_t
name|test_vqnegq_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
return|return
name|vqnegq_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqnegq_s16
end_comment

begin_comment
comment|// CHECK: vqneg.s16 q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int16x8_t
name|test_vqnegq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
return|return
name|vqnegq_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqnegq_s32
end_comment

begin_comment
comment|// CHECK: vqneg.s32 q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int32x4_t
name|test_vqnegq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
return|return
name|vqnegq_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqrdmulh_s16
end_comment

begin_comment
comment|// CHECK: vqrdmulh.s16 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int16x4_t
name|test_vqrdmulh_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
return|return
name|vqrdmulh_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqrdmulh_s32
end_comment

begin_comment
comment|// CHECK: vqrdmulh.s32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int32x2_t
name|test_vqrdmulh_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
return|return
name|vqrdmulh_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqrdmulhq_s16
end_comment

begin_comment
comment|// CHECK: vqrdmulh.s16 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int16x8_t
name|test_vqrdmulhq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
return|return
name|vqrdmulhq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqrdmulhq_s32
end_comment

begin_comment
comment|// CHECK: vqrdmulh.s32 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int32x4_t
name|test_vqrdmulhq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
return|return
name|vqrdmulhq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqrdmulh_lane_s16
end_comment

begin_comment
comment|// CHECK: vqrdmulh.s16 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}[{{[0-9]}}]
end_comment

begin_function
name|int16x4_t
name|test_vqrdmulh_lane_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
return|return
name|vqrdmulh_lane_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqrdmulh_lane_s32
end_comment

begin_comment
comment|// CHECK: vqrdmulh.s32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}[{{[0-9]}}]
end_comment

begin_function
name|int32x2_t
name|test_vqrdmulh_lane_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
return|return
name|vqrdmulh_lane_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqrdmulhq_lane_s16
end_comment

begin_comment
comment|// CHECK: vqrdmulh.s16 q{{[0-9]+}}, q{{[0-9]+}}, d{{[0-9]+}}[{{[0-9]}}]
end_comment

begin_function
name|int16x8_t
name|test_vqrdmulhq_lane_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
return|return
name|vqrdmulhq_lane_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqrdmulhq_lane_s32
end_comment

begin_comment
comment|// CHECK: vqrdmulh.s32 q{{[0-9]+}}, q{{[0-9]+}}, d{{[0-9]+}}[{{[0-9]}}]
end_comment

begin_function
name|int32x4_t
name|test_vqrdmulhq_lane_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
return|return
name|vqrdmulhq_lane_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqrdmulh_n_s16
end_comment

begin_comment
comment|// CHECK: vqrdmulh.s16 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int16x4_t
name|test_vqrdmulh_n_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16_t
name|b
parameter_list|)
block|{
return|return
name|vqrdmulh_n_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqrdmulh_n_s32
end_comment

begin_comment
comment|// CHECK: vqrdmulh.s32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int32x2_t
name|test_vqrdmulh_n_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32_t
name|b
parameter_list|)
block|{
return|return
name|vqrdmulh_n_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqrdmulhq_n_s16
end_comment

begin_comment
comment|// CHECK: vqrdmulh.s16 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int16x8_t
name|test_vqrdmulhq_n_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16_t
name|b
parameter_list|)
block|{
return|return
name|vqrdmulhq_n_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqrdmulhq_n_s32
end_comment

begin_comment
comment|// CHECK: vqrdmulh.s32 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int32x4_t
name|test_vqrdmulhq_n_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32_t
name|b
parameter_list|)
block|{
return|return
name|vqrdmulhq_n_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqrshl_s8
end_comment

begin_comment
comment|// CHECK: vqrshl.s8 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int8x8_t
name|test_vqrshl_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
return|return
name|vqrshl_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqrshl_s16
end_comment

begin_comment
comment|// CHECK: vqrshl.s16 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int16x4_t
name|test_vqrshl_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
return|return
name|vqrshl_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqrshl_s32
end_comment

begin_comment
comment|// CHECK: vqrshl.s32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int32x2_t
name|test_vqrshl_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
return|return
name|vqrshl_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqrshl_s64
end_comment

begin_comment
comment|// CHECK: vqrshl.s64 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int64x1_t
name|test_vqrshl_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|,
name|int64x1_t
name|b
parameter_list|)
block|{
return|return
name|vqrshl_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqrshl_u8
end_comment

begin_comment
comment|// CHECK: vqrshl.u8 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint8x8_t
name|test_vqrshl_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
return|return
name|vqrshl_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqrshl_u16
end_comment

begin_comment
comment|// CHECK: vqrshl.u16 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint16x4_t
name|test_vqrshl_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
return|return
name|vqrshl_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqrshl_u32
end_comment

begin_comment
comment|// CHECK: vqrshl.u32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint32x2_t
name|test_vqrshl_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
return|return
name|vqrshl_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqrshl_u64
end_comment

begin_comment
comment|// CHECK: vqrshl.u64 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint64x1_t
name|test_vqrshl_u64
parameter_list|(
name|uint64x1_t
name|a
parameter_list|,
name|int64x1_t
name|b
parameter_list|)
block|{
return|return
name|vqrshl_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqrshlq_s8
end_comment

begin_comment
comment|// CHECK: vqrshl.s8 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int8x16_t
name|test_vqrshlq_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|)
block|{
return|return
name|vqrshlq_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqrshlq_s16
end_comment

begin_comment
comment|// CHECK: vqrshl.s16 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int16x8_t
name|test_vqrshlq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
return|return
name|vqrshlq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqrshlq_s32
end_comment

begin_comment
comment|// CHECK: vqrshl.s32 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int32x4_t
name|test_vqrshlq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
return|return
name|vqrshlq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqrshlq_s64
end_comment

begin_comment
comment|// CHECK: vqrshl.s64 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int64x2_t
name|test_vqrshlq_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int64x2_t
name|b
parameter_list|)
block|{
return|return
name|vqrshlq_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqrshlq_u8
end_comment

begin_comment
comment|// CHECK: vqrshl.u8 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint8x16_t
name|test_vqrshlq_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|)
block|{
return|return
name|vqrshlq_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqrshlq_u16
end_comment

begin_comment
comment|// CHECK: vqrshl.u16 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint16x8_t
name|test_vqrshlq_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
return|return
name|vqrshlq_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqrshlq_u32
end_comment

begin_comment
comment|// CHECK: vqrshl.u32 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint32x4_t
name|test_vqrshlq_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
return|return
name|vqrshlq_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqrshlq_u64
end_comment

begin_comment
comment|// CHECK: vqrshl.u64 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint64x2_t
name|test_vqrshlq_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|,
name|int64x2_t
name|b
parameter_list|)
block|{
return|return
name|vqrshlq_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqrshrn_n_s16
end_comment

begin_comment
comment|// CHECK: vqrshrn.s16 d{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|int8x8_t
name|test_vqrshrn_n_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
return|return
name|vqrshrn_n_s16
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqrshrn_n_s32
end_comment

begin_comment
comment|// CHECK: vqrshrn.s32 d{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|int16x4_t
name|test_vqrshrn_n_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
return|return
name|vqrshrn_n_s32
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqrshrn_n_s64
end_comment

begin_comment
comment|// CHECK: vqrshrn.s64 d{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|int32x2_t
name|test_vqrshrn_n_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|)
block|{
return|return
name|vqrshrn_n_s64
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqrshrn_n_u16
end_comment

begin_comment
comment|// CHECK: vqrshrn.u16 d{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|uint8x8_t
name|test_vqrshrn_n_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|)
block|{
return|return
name|vqrshrn_n_u16
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqrshrn_n_u32
end_comment

begin_comment
comment|// CHECK: vqrshrn.u32 d{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|uint16x4_t
name|test_vqrshrn_n_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|)
block|{
return|return
name|vqrshrn_n_u32
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqrshrn_n_u64
end_comment

begin_comment
comment|// CHECK: vqrshrn.u64 d{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|uint32x2_t
name|test_vqrshrn_n_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|)
block|{
return|return
name|vqrshrn_n_u64
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqrshrun_n_s16
end_comment

begin_comment
comment|// CHECK: vqrshrun.s16 d{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|uint8x8_t
name|test_vqrshrun_n_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
return|return
name|vqrshrun_n_s16
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqrshrun_n_s32
end_comment

begin_comment
comment|// CHECK: vqrshrun.s32 d{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|uint16x4_t
name|test_vqrshrun_n_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
return|return
name|vqrshrun_n_s32
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqrshrun_n_s64
end_comment

begin_comment
comment|// CHECK: vqrshrun.s64 d{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|uint32x2_t
name|test_vqrshrun_n_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|)
block|{
return|return
name|vqrshrun_n_s64
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqshl_s8
end_comment

begin_comment
comment|// CHECK: vqshl.s8 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int8x8_t
name|test_vqshl_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
return|return
name|vqshl_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqshl_s16
end_comment

begin_comment
comment|// CHECK: vqshl.s16 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int16x4_t
name|test_vqshl_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
return|return
name|vqshl_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqshl_s32
end_comment

begin_comment
comment|// CHECK: vqshl.s32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int32x2_t
name|test_vqshl_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
return|return
name|vqshl_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqshl_s64
end_comment

begin_comment
comment|// CHECK: vqshl.s64 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int64x1_t
name|test_vqshl_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|,
name|int64x1_t
name|b
parameter_list|)
block|{
return|return
name|vqshl_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqshl_u8
end_comment

begin_comment
comment|// CHECK: vqshl.u8 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint8x8_t
name|test_vqshl_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
return|return
name|vqshl_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqshl_u16
end_comment

begin_comment
comment|// CHECK: vqshl.u16 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint16x4_t
name|test_vqshl_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
return|return
name|vqshl_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqshl_u32
end_comment

begin_comment
comment|// CHECK: vqshl.u32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint32x2_t
name|test_vqshl_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
return|return
name|vqshl_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqshl_u64
end_comment

begin_comment
comment|// CHECK: vqshl.u64 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint64x1_t
name|test_vqshl_u64
parameter_list|(
name|uint64x1_t
name|a
parameter_list|,
name|int64x1_t
name|b
parameter_list|)
block|{
return|return
name|vqshl_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqshlq_s8
end_comment

begin_comment
comment|// CHECK: vqshl.s8 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int8x16_t
name|test_vqshlq_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|)
block|{
return|return
name|vqshlq_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqshlq_s16
end_comment

begin_comment
comment|// CHECK: vqshl.s16 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int16x8_t
name|test_vqshlq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
return|return
name|vqshlq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqshlq_s32
end_comment

begin_comment
comment|// CHECK: vqshl.s32 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int32x4_t
name|test_vqshlq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
return|return
name|vqshlq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqshlq_s64
end_comment

begin_comment
comment|// CHECK: vqshl.s64 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int64x2_t
name|test_vqshlq_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int64x2_t
name|b
parameter_list|)
block|{
return|return
name|vqshlq_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqshlq_u8
end_comment

begin_comment
comment|// CHECK: vqshl.u8 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint8x16_t
name|test_vqshlq_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|)
block|{
return|return
name|vqshlq_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqshlq_u16
end_comment

begin_comment
comment|// CHECK: vqshl.u16 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint16x8_t
name|test_vqshlq_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
return|return
name|vqshlq_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqshlq_u32
end_comment

begin_comment
comment|// CHECK: vqshl.u32 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint32x4_t
name|test_vqshlq_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
return|return
name|vqshlq_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqshlq_u64
end_comment

begin_comment
comment|// CHECK: vqshl.u64 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint64x2_t
name|test_vqshlq_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|,
name|int64x2_t
name|b
parameter_list|)
block|{
return|return
name|vqshlq_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqshlu_n_s8
end_comment

begin_comment
comment|// CHECK: vqshlu.s8 d{{[0-9]+}}, d{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|uint8x8_t
name|test_vqshlu_n_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
return|return
name|vqshlu_n_s8
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqshlu_n_s16
end_comment

begin_comment
comment|// CHECK: vqshlu.s16 d{{[0-9]+}}, d{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|uint16x4_t
name|test_vqshlu_n_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|)
block|{
return|return
name|vqshlu_n_s16
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqshlu_n_s32
end_comment

begin_comment
comment|// CHECK: vqshlu.s32 d{{[0-9]+}}, d{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|uint32x2_t
name|test_vqshlu_n_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|)
block|{
return|return
name|vqshlu_n_s32
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqshlu_n_s64
end_comment

begin_comment
comment|// CHECK: vqshlu.s64 d{{[0-9]+}}, d{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|uint64x1_t
name|test_vqshlu_n_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|)
block|{
return|return
name|vqshlu_n_s64
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqshluq_n_s8
end_comment

begin_comment
comment|// CHECK: vqshlu.s8 q{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|uint8x16_t
name|test_vqshluq_n_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
return|return
name|vqshluq_n_s8
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqshluq_n_s16
end_comment

begin_comment
comment|// CHECK: vqshlu.s16 q{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|uint16x8_t
name|test_vqshluq_n_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
return|return
name|vqshluq_n_s16
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqshluq_n_s32
end_comment

begin_comment
comment|// CHECK: vqshlu.s32 q{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|uint32x4_t
name|test_vqshluq_n_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
return|return
name|vqshluq_n_s32
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqshluq_n_s64
end_comment

begin_comment
comment|// CHECK: vqshlu.s64 q{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|uint64x2_t
name|test_vqshluq_n_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|)
block|{
return|return
name|vqshluq_n_s64
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqshl_n_s8
end_comment

begin_comment
comment|// CHECK: vqshl.s8 d{{[0-9]+}}, d{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|int8x8_t
name|test_vqshl_n_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
return|return
name|vqshl_n_s8
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqshl_n_s16
end_comment

begin_comment
comment|// CHECK: vqshl.s16 d{{[0-9]+}}, d{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|int16x4_t
name|test_vqshl_n_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|)
block|{
return|return
name|vqshl_n_s16
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqshl_n_s32
end_comment

begin_comment
comment|// CHECK: vqshl.s32 d{{[0-9]+}}, d{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|int32x2_t
name|test_vqshl_n_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|)
block|{
return|return
name|vqshl_n_s32
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqshl_n_s64
end_comment

begin_comment
comment|// CHECK: vqshl.s64 d{{[0-9]+}}, d{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|int64x1_t
name|test_vqshl_n_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|)
block|{
return|return
name|vqshl_n_s64
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqshl_n_u8
end_comment

begin_comment
comment|// CHECK: vqshl.u8 d{{[0-9]+}}, d{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|uint8x8_t
name|test_vqshl_n_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|)
block|{
return|return
name|vqshl_n_u8
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqshl_n_u16
end_comment

begin_comment
comment|// CHECK: vqshl.u16 d{{[0-9]+}}, d{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|uint16x4_t
name|test_vqshl_n_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|)
block|{
return|return
name|vqshl_n_u16
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqshl_n_u32
end_comment

begin_comment
comment|// CHECK: vqshl.u32 d{{[0-9]+}}, d{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|uint32x2_t
name|test_vqshl_n_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|)
block|{
return|return
name|vqshl_n_u32
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqshl_n_u64
end_comment

begin_comment
comment|// CHECK: vqshl.u64 d{{[0-9]+}}, d{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|uint64x1_t
name|test_vqshl_n_u64
parameter_list|(
name|uint64x1_t
name|a
parameter_list|)
block|{
return|return
name|vqshl_n_u64
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqshlq_n_s8
end_comment

begin_comment
comment|// CHECK: vqshl.s8 q{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|int8x16_t
name|test_vqshlq_n_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
return|return
name|vqshlq_n_s8
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqshlq_n_s16
end_comment

begin_comment
comment|// CHECK: vqshl.s16 q{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|int16x8_t
name|test_vqshlq_n_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
return|return
name|vqshlq_n_s16
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqshlq_n_s32
end_comment

begin_comment
comment|// CHECK: vqshl.s32 q{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|int32x4_t
name|test_vqshlq_n_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
return|return
name|vqshlq_n_s32
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqshlq_n_s64
end_comment

begin_comment
comment|// CHECK: vqshl.s64 q{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|int64x2_t
name|test_vqshlq_n_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|)
block|{
return|return
name|vqshlq_n_s64
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqshlq_n_u8
end_comment

begin_comment
comment|// CHECK: vqshl.u8 q{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|uint8x16_t
name|test_vqshlq_n_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|)
block|{
return|return
name|vqshlq_n_u8
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqshlq_n_u16
end_comment

begin_comment
comment|// CHECK: vqshl.u16 q{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|uint16x8_t
name|test_vqshlq_n_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|)
block|{
return|return
name|vqshlq_n_u16
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqshlq_n_u32
end_comment

begin_comment
comment|// CHECK: vqshl.u32 q{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|uint32x4_t
name|test_vqshlq_n_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|)
block|{
return|return
name|vqshlq_n_u32
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqshlq_n_u64
end_comment

begin_comment
comment|// CHECK: vqshl.u64 q{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|uint64x2_t
name|test_vqshlq_n_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|)
block|{
return|return
name|vqshlq_n_u64
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqshrn_n_s16
end_comment

begin_comment
comment|// CHECK: vqshrn.s16 d{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|int8x8_t
name|test_vqshrn_n_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
return|return
name|vqshrn_n_s16
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqshrn_n_s32
end_comment

begin_comment
comment|// CHECK: vqshrn.s32 d{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|int16x4_t
name|test_vqshrn_n_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
return|return
name|vqshrn_n_s32
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqshrn_n_s64
end_comment

begin_comment
comment|// CHECK: vqshrn.s64 d{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|int32x2_t
name|test_vqshrn_n_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|)
block|{
return|return
name|vqshrn_n_s64
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqshrn_n_u16
end_comment

begin_comment
comment|// CHECK: vqshrn.u16 d{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|uint8x8_t
name|test_vqshrn_n_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|)
block|{
return|return
name|vqshrn_n_u16
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqshrn_n_u32
end_comment

begin_comment
comment|// CHECK: vqshrn.u32 d{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|uint16x4_t
name|test_vqshrn_n_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|)
block|{
return|return
name|vqshrn_n_u32
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqshrn_n_u64
end_comment

begin_comment
comment|// CHECK: vqshrn.u64 d{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|uint32x2_t
name|test_vqshrn_n_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|)
block|{
return|return
name|vqshrn_n_u64
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqshrun_n_s16
end_comment

begin_comment
comment|// CHECK: vqshrun.s16 d{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|uint8x8_t
name|test_vqshrun_n_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
return|return
name|vqshrun_n_s16
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqshrun_n_s32
end_comment

begin_comment
comment|// CHECK: vqshrun.s32 d{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|uint16x4_t
name|test_vqshrun_n_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
return|return
name|vqshrun_n_s32
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqshrun_n_s64
end_comment

begin_comment
comment|// CHECK: vqshrun.s64 d{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|uint32x2_t
name|test_vqshrun_n_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|)
block|{
return|return
name|vqshrun_n_s64
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqsub_s8
end_comment

begin_comment
comment|// CHECK: vqsub.s8 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int8x8_t
name|test_vqsub_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
return|return
name|vqsub_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqsub_s16
end_comment

begin_comment
comment|// CHECK: vqsub.s16 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int16x4_t
name|test_vqsub_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
return|return
name|vqsub_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqsub_s32
end_comment

begin_comment
comment|// CHECK: vqsub.s32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int32x2_t
name|test_vqsub_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
return|return
name|vqsub_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqsub_s64
end_comment

begin_comment
comment|// CHECK: vqsub.s64 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int64x1_t
name|test_vqsub_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|,
name|int64x1_t
name|b
parameter_list|)
block|{
return|return
name|vqsub_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqsub_u8
end_comment

begin_comment
comment|// CHECK: vqsub.u8 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint8x8_t
name|test_vqsub_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|)
block|{
return|return
name|vqsub_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqsub_u16
end_comment

begin_comment
comment|// CHECK: vqsub.u16 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint16x4_t
name|test_vqsub_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|)
block|{
return|return
name|vqsub_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqsub_u32
end_comment

begin_comment
comment|// CHECK: vqsub.u32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint32x2_t
name|test_vqsub_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|)
block|{
return|return
name|vqsub_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqsub_u64
end_comment

begin_comment
comment|// CHECK: vqsub.u64 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint64x1_t
name|test_vqsub_u64
parameter_list|(
name|uint64x1_t
name|a
parameter_list|,
name|uint64x1_t
name|b
parameter_list|)
block|{
return|return
name|vqsub_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqsubq_s8
end_comment

begin_comment
comment|// CHECK: vqsub.s8 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int8x16_t
name|test_vqsubq_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|)
block|{
return|return
name|vqsubq_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqsubq_s16
end_comment

begin_comment
comment|// CHECK: vqsub.s16 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int16x8_t
name|test_vqsubq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
return|return
name|vqsubq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqsubq_s32
end_comment

begin_comment
comment|// CHECK: vqsub.s32 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int32x4_t
name|test_vqsubq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
return|return
name|vqsubq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqsubq_s64
end_comment

begin_comment
comment|// CHECK: vqsub.s64 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int64x2_t
name|test_vqsubq_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int64x2_t
name|b
parameter_list|)
block|{
return|return
name|vqsubq_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqsubq_u8
end_comment

begin_comment
comment|// CHECK: vqsub.u8 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint8x16_t
name|test_vqsubq_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|,
name|uint8x16_t
name|b
parameter_list|)
block|{
return|return
name|vqsubq_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqsubq_u16
end_comment

begin_comment
comment|// CHECK: vqsub.u16 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint16x8_t
name|test_vqsubq_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|)
block|{
return|return
name|vqsubq_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqsubq_u32
end_comment

begin_comment
comment|// CHECK: vqsub.u32 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint32x4_t
name|test_vqsubq_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|)
block|{
return|return
name|vqsubq_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqsubq_u64
end_comment

begin_comment
comment|// CHECK: vqsub.u64 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint64x2_t
name|test_vqsubq_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|,
name|uint64x2_t
name|b
parameter_list|)
block|{
return|return
name|vqsubq_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vraddhn_s16
end_comment

begin_comment
comment|// CHECK: vraddhn.i16 d{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int8x8_t
name|test_vraddhn_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
return|return
name|vraddhn_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vraddhn_s32
end_comment

begin_comment
comment|// CHECK: vraddhn.i32 d{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int16x4_t
name|test_vraddhn_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
return|return
name|vraddhn_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vraddhn_s64
end_comment

begin_comment
comment|// CHECK: vraddhn.i64 d{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int32x2_t
name|test_vraddhn_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int64x2_t
name|b
parameter_list|)
block|{
return|return
name|vraddhn_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vraddhn_u16
end_comment

begin_comment
comment|// CHECK: vraddhn.i16 d{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint8x8_t
name|test_vraddhn_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|)
block|{
return|return
name|vraddhn_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vraddhn_u32
end_comment

begin_comment
comment|// CHECK: vraddhn.i32 d{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint16x4_t
name|test_vraddhn_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|)
block|{
return|return
name|vraddhn_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vraddhn_u64
end_comment

begin_comment
comment|// CHECK: vraddhn.i64 d{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint32x2_t
name|test_vraddhn_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|,
name|uint64x2_t
name|b
parameter_list|)
block|{
return|return
name|vraddhn_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrecpe_f32
end_comment

begin_comment
comment|// CHECK: vrecpe.f32 d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|float32x2_t
name|test_vrecpe_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
return|return
name|vrecpe_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrecpe_u32
end_comment

begin_comment
comment|// CHECK: vrecpe.u32 d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint32x2_t
name|test_vrecpe_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|)
block|{
return|return
name|vrecpe_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrecpeq_f32
end_comment

begin_comment
comment|// CHECK: vrecpe.f32 q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|float32x4_t
name|test_vrecpeq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
return|return
name|vrecpeq_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrecpeq_u32
end_comment

begin_comment
comment|// CHECK: vrecpe.u32 q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint32x4_t
name|test_vrecpeq_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|)
block|{
return|return
name|vrecpeq_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrecps_f32
end_comment

begin_comment
comment|// CHECK: vrecps.f32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|float32x2_t
name|test_vrecps_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32x2_t
name|b
parameter_list|)
block|{
return|return
name|vrecps_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrecpsq_f32
end_comment

begin_comment
comment|// CHECK: vrecps.f32 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|float32x4_t
name|test_vrecpsq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|,
name|float32x4_t
name|b
parameter_list|)
block|{
return|return
name|vrecpsq_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_s8_s16
end_comment

begin_function
name|int8x8_t
name|test_vreinterpret_s8_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_s8_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_s8_s32
end_comment

begin_function
name|int8x8_t
name|test_vreinterpret_s8_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_s8_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_s8_s64
end_comment

begin_function
name|int8x8_t
name|test_vreinterpret_s8_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_s8_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_s8_u8
end_comment

begin_function
name|int8x8_t
name|test_vreinterpret_s8_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_s8_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_s8_u16
end_comment

begin_function
name|int8x8_t
name|test_vreinterpret_s8_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_s8_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_s8_u32
end_comment

begin_function
name|int8x8_t
name|test_vreinterpret_s8_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_s8_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_s8_u64
end_comment

begin_function
name|int8x8_t
name|test_vreinterpret_s8_u64
parameter_list|(
name|uint64x1_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_s8_u64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_s8_f16
end_comment

begin_function
name|int8x8_t
name|test_vreinterpret_s8_f16
parameter_list|(
name|float16x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_s8_f16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_s8_f32
end_comment

begin_function
name|int8x8_t
name|test_vreinterpret_s8_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_s8_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_s8_p8
end_comment

begin_function
name|int8x8_t
name|test_vreinterpret_s8_p8
parameter_list|(
name|poly8x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_s8_p8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_s8_p16
end_comment

begin_function
name|int8x8_t
name|test_vreinterpret_s8_p16
parameter_list|(
name|poly16x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_s8_p16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_s16_s8
end_comment

begin_function
name|int16x4_t
name|test_vreinterpret_s16_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_s16_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_s16_s32
end_comment

begin_function
name|int16x4_t
name|test_vreinterpret_s16_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_s16_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_s16_s64
end_comment

begin_function
name|int16x4_t
name|test_vreinterpret_s16_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_s16_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_s16_u8
end_comment

begin_function
name|int16x4_t
name|test_vreinterpret_s16_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_s16_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_s16_u16
end_comment

begin_function
name|int16x4_t
name|test_vreinterpret_s16_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_s16_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_s16_u32
end_comment

begin_function
name|int16x4_t
name|test_vreinterpret_s16_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_s16_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_s16_u64
end_comment

begin_function
name|int16x4_t
name|test_vreinterpret_s16_u64
parameter_list|(
name|uint64x1_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_s16_u64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_s16_f16
end_comment

begin_function
name|int16x4_t
name|test_vreinterpret_s16_f16
parameter_list|(
name|float16x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_s16_f16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_s16_f32
end_comment

begin_function
name|int16x4_t
name|test_vreinterpret_s16_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_s16_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_s16_p8
end_comment

begin_function
name|int16x4_t
name|test_vreinterpret_s16_p8
parameter_list|(
name|poly8x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_s16_p8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_s16_p16
end_comment

begin_function
name|int16x4_t
name|test_vreinterpret_s16_p16
parameter_list|(
name|poly16x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_s16_p16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_s32_s8
end_comment

begin_function
name|int32x2_t
name|test_vreinterpret_s32_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_s32_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_s32_s16
end_comment

begin_function
name|int32x2_t
name|test_vreinterpret_s32_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_s32_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_s32_s64
end_comment

begin_function
name|int32x2_t
name|test_vreinterpret_s32_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_s32_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_s32_u8
end_comment

begin_function
name|int32x2_t
name|test_vreinterpret_s32_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_s32_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_s32_u16
end_comment

begin_function
name|int32x2_t
name|test_vreinterpret_s32_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_s32_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_s32_u32
end_comment

begin_function
name|int32x2_t
name|test_vreinterpret_s32_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_s32_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_s32_u64
end_comment

begin_function
name|int32x2_t
name|test_vreinterpret_s32_u64
parameter_list|(
name|uint64x1_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_s32_u64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_s32_f16
end_comment

begin_function
name|int32x2_t
name|test_vreinterpret_s32_f16
parameter_list|(
name|float16x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_s32_f16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_s32_f32
end_comment

begin_function
name|int32x2_t
name|test_vreinterpret_s32_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_s32_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_s32_p8
end_comment

begin_function
name|int32x2_t
name|test_vreinterpret_s32_p8
parameter_list|(
name|poly8x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_s32_p8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_s32_p16
end_comment

begin_function
name|int32x2_t
name|test_vreinterpret_s32_p16
parameter_list|(
name|poly16x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_s32_p16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_s64_s8
end_comment

begin_function
name|int64x1_t
name|test_vreinterpret_s64_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_s64_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_s64_s16
end_comment

begin_function
name|int64x1_t
name|test_vreinterpret_s64_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_s64_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_s64_s32
end_comment

begin_function
name|int64x1_t
name|test_vreinterpret_s64_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_s64_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_s64_u8
end_comment

begin_function
name|int64x1_t
name|test_vreinterpret_s64_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_s64_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_s64_u16
end_comment

begin_function
name|int64x1_t
name|test_vreinterpret_s64_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_s64_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_s64_u32
end_comment

begin_function
name|int64x1_t
name|test_vreinterpret_s64_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_s64_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_s64_u64
end_comment

begin_function
name|int64x1_t
name|test_vreinterpret_s64_u64
parameter_list|(
name|uint64x1_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_s64_u64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_s64_f16
end_comment

begin_function
name|int64x1_t
name|test_vreinterpret_s64_f16
parameter_list|(
name|float16x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_s64_f16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_s64_f32
end_comment

begin_function
name|int64x1_t
name|test_vreinterpret_s64_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_s64_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_s64_p8
end_comment

begin_function
name|int64x1_t
name|test_vreinterpret_s64_p8
parameter_list|(
name|poly8x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_s64_p8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_s64_p16
end_comment

begin_function
name|int64x1_t
name|test_vreinterpret_s64_p16
parameter_list|(
name|poly16x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_s64_p16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_u8_s8
end_comment

begin_function
name|uint8x8_t
name|test_vreinterpret_u8_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_u8_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_u8_s16
end_comment

begin_function
name|uint8x8_t
name|test_vreinterpret_u8_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_u8_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_u8_s32
end_comment

begin_function
name|uint8x8_t
name|test_vreinterpret_u8_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_u8_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_u8_s64
end_comment

begin_function
name|uint8x8_t
name|test_vreinterpret_u8_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_u8_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_u8_u16
end_comment

begin_function
name|uint8x8_t
name|test_vreinterpret_u8_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_u8_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_u8_u32
end_comment

begin_function
name|uint8x8_t
name|test_vreinterpret_u8_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_u8_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_u8_u64
end_comment

begin_function
name|uint8x8_t
name|test_vreinterpret_u8_u64
parameter_list|(
name|uint64x1_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_u8_u64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_u8_f16
end_comment

begin_function
name|uint8x8_t
name|test_vreinterpret_u8_f16
parameter_list|(
name|float16x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_u8_f16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_u8_f32
end_comment

begin_function
name|uint8x8_t
name|test_vreinterpret_u8_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_u8_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_u8_p8
end_comment

begin_function
name|uint8x8_t
name|test_vreinterpret_u8_p8
parameter_list|(
name|poly8x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_u8_p8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_u8_p16
end_comment

begin_function
name|uint8x8_t
name|test_vreinterpret_u8_p16
parameter_list|(
name|poly16x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_u8_p16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_u16_s8
end_comment

begin_function
name|uint16x4_t
name|test_vreinterpret_u16_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_u16_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_u16_s16
end_comment

begin_function
name|uint16x4_t
name|test_vreinterpret_u16_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_u16_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_u16_s32
end_comment

begin_function
name|uint16x4_t
name|test_vreinterpret_u16_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_u16_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_u16_s64
end_comment

begin_function
name|uint16x4_t
name|test_vreinterpret_u16_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_u16_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_u16_u8
end_comment

begin_function
name|uint16x4_t
name|test_vreinterpret_u16_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_u16_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_u16_u32
end_comment

begin_function
name|uint16x4_t
name|test_vreinterpret_u16_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_u16_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_u16_u64
end_comment

begin_function
name|uint16x4_t
name|test_vreinterpret_u16_u64
parameter_list|(
name|uint64x1_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_u16_u64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_u16_f16
end_comment

begin_function
name|uint16x4_t
name|test_vreinterpret_u16_f16
parameter_list|(
name|float16x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_u16_f16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_u16_f32
end_comment

begin_function
name|uint16x4_t
name|test_vreinterpret_u16_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_u16_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_u16_p8
end_comment

begin_function
name|uint16x4_t
name|test_vreinterpret_u16_p8
parameter_list|(
name|poly8x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_u16_p8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_u16_p16
end_comment

begin_function
name|uint16x4_t
name|test_vreinterpret_u16_p16
parameter_list|(
name|poly16x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_u16_p16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_u32_s8
end_comment

begin_function
name|uint32x2_t
name|test_vreinterpret_u32_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_u32_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_u32_s16
end_comment

begin_function
name|uint32x2_t
name|test_vreinterpret_u32_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_u32_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_u32_s32
end_comment

begin_function
name|uint32x2_t
name|test_vreinterpret_u32_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_u32_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_u32_s64
end_comment

begin_function
name|uint32x2_t
name|test_vreinterpret_u32_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_u32_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_u32_u8
end_comment

begin_function
name|uint32x2_t
name|test_vreinterpret_u32_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_u32_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_u32_u16
end_comment

begin_function
name|uint32x2_t
name|test_vreinterpret_u32_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_u32_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_u32_u64
end_comment

begin_function
name|uint32x2_t
name|test_vreinterpret_u32_u64
parameter_list|(
name|uint64x1_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_u32_u64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_u32_f16
end_comment

begin_function
name|uint32x2_t
name|test_vreinterpret_u32_f16
parameter_list|(
name|float16x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_u32_f16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_u32_f32
end_comment

begin_function
name|uint32x2_t
name|test_vreinterpret_u32_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_u32_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_u32_p8
end_comment

begin_function
name|uint32x2_t
name|test_vreinterpret_u32_p8
parameter_list|(
name|poly8x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_u32_p8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_u32_p16
end_comment

begin_function
name|uint32x2_t
name|test_vreinterpret_u32_p16
parameter_list|(
name|poly16x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_u32_p16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_u64_s8
end_comment

begin_function
name|uint64x1_t
name|test_vreinterpret_u64_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_u64_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_u64_s16
end_comment

begin_function
name|uint64x1_t
name|test_vreinterpret_u64_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_u64_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_u64_s32
end_comment

begin_function
name|uint64x1_t
name|test_vreinterpret_u64_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_u64_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_u64_s64
end_comment

begin_function
name|uint64x1_t
name|test_vreinterpret_u64_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_u64_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_u64_u8
end_comment

begin_function
name|uint64x1_t
name|test_vreinterpret_u64_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_u64_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_u64_u16
end_comment

begin_function
name|uint64x1_t
name|test_vreinterpret_u64_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_u64_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_u64_u32
end_comment

begin_function
name|uint64x1_t
name|test_vreinterpret_u64_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_u64_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_u64_f16
end_comment

begin_function
name|uint64x1_t
name|test_vreinterpret_u64_f16
parameter_list|(
name|float16x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_u64_f16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_u64_f32
end_comment

begin_function
name|uint64x1_t
name|test_vreinterpret_u64_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_u64_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_u64_p8
end_comment

begin_function
name|uint64x1_t
name|test_vreinterpret_u64_p8
parameter_list|(
name|poly8x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_u64_p8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_u64_p16
end_comment

begin_function
name|uint64x1_t
name|test_vreinterpret_u64_p16
parameter_list|(
name|poly16x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_u64_p16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_f16_s8
end_comment

begin_function
name|float16x4_t
name|test_vreinterpret_f16_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_f16_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_f16_s16
end_comment

begin_function
name|float16x4_t
name|test_vreinterpret_f16_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_f16_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_f16_s32
end_comment

begin_function
name|float16x4_t
name|test_vreinterpret_f16_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_f16_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_f16_s64
end_comment

begin_function
name|float16x4_t
name|test_vreinterpret_f16_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_f16_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_f16_u8
end_comment

begin_function
name|float16x4_t
name|test_vreinterpret_f16_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_f16_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_f16_u16
end_comment

begin_function
name|float16x4_t
name|test_vreinterpret_f16_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_f16_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_f16_u32
end_comment

begin_function
name|float16x4_t
name|test_vreinterpret_f16_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_f16_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_f16_u64
end_comment

begin_function
name|float16x4_t
name|test_vreinterpret_f16_u64
parameter_list|(
name|uint64x1_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_f16_u64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_f16_f32
end_comment

begin_function
name|float16x4_t
name|test_vreinterpret_f16_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_f16_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_f16_p8
end_comment

begin_function
name|float16x4_t
name|test_vreinterpret_f16_p8
parameter_list|(
name|poly8x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_f16_p8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_f16_p16
end_comment

begin_function
name|float16x4_t
name|test_vreinterpret_f16_p16
parameter_list|(
name|poly16x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_f16_p16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_f32_s8
end_comment

begin_function
name|float32x2_t
name|test_vreinterpret_f32_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_f32_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_f32_s16
end_comment

begin_function
name|float32x2_t
name|test_vreinterpret_f32_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_f32_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_f32_s32
end_comment

begin_function
name|float32x2_t
name|test_vreinterpret_f32_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_f32_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_f32_s64
end_comment

begin_function
name|float32x2_t
name|test_vreinterpret_f32_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_f32_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_f32_u8
end_comment

begin_function
name|float32x2_t
name|test_vreinterpret_f32_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_f32_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_f32_u16
end_comment

begin_function
name|float32x2_t
name|test_vreinterpret_f32_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_f32_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_f32_u32
end_comment

begin_function
name|float32x2_t
name|test_vreinterpret_f32_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_f32_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_f32_u64
end_comment

begin_function
name|float32x2_t
name|test_vreinterpret_f32_u64
parameter_list|(
name|uint64x1_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_f32_u64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_f32_f16
end_comment

begin_function
name|float32x2_t
name|test_vreinterpret_f32_f16
parameter_list|(
name|float16x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_f32_f16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_f32_p8
end_comment

begin_function
name|float32x2_t
name|test_vreinterpret_f32_p8
parameter_list|(
name|poly8x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_f32_p8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_f32_p16
end_comment

begin_function
name|float32x2_t
name|test_vreinterpret_f32_p16
parameter_list|(
name|poly16x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_f32_p16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_p8_s8
end_comment

begin_function
name|poly8x8_t
name|test_vreinterpret_p8_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_p8_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_p8_s16
end_comment

begin_function
name|poly8x8_t
name|test_vreinterpret_p8_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_p8_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_p8_s32
end_comment

begin_function
name|poly8x8_t
name|test_vreinterpret_p8_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_p8_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_p8_s64
end_comment

begin_function
name|poly8x8_t
name|test_vreinterpret_p8_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_p8_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_p8_u8
end_comment

begin_function
name|poly8x8_t
name|test_vreinterpret_p8_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_p8_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_p8_u16
end_comment

begin_function
name|poly8x8_t
name|test_vreinterpret_p8_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_p8_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_p8_u32
end_comment

begin_function
name|poly8x8_t
name|test_vreinterpret_p8_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_p8_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_p8_u64
end_comment

begin_function
name|poly8x8_t
name|test_vreinterpret_p8_u64
parameter_list|(
name|uint64x1_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_p8_u64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_p8_f16
end_comment

begin_function
name|poly8x8_t
name|test_vreinterpret_p8_f16
parameter_list|(
name|float16x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_p8_f16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_p8_f32
end_comment

begin_function
name|poly8x8_t
name|test_vreinterpret_p8_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_p8_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_p8_p16
end_comment

begin_function
name|poly8x8_t
name|test_vreinterpret_p8_p16
parameter_list|(
name|poly16x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_p8_p16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_p16_s8
end_comment

begin_function
name|poly16x4_t
name|test_vreinterpret_p16_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_p16_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_p16_s16
end_comment

begin_function
name|poly16x4_t
name|test_vreinterpret_p16_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_p16_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_p16_s32
end_comment

begin_function
name|poly16x4_t
name|test_vreinterpret_p16_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_p16_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_p16_s64
end_comment

begin_function
name|poly16x4_t
name|test_vreinterpret_p16_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_p16_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_p16_u8
end_comment

begin_function
name|poly16x4_t
name|test_vreinterpret_p16_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_p16_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_p16_u16
end_comment

begin_function
name|poly16x4_t
name|test_vreinterpret_p16_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_p16_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_p16_u32
end_comment

begin_function
name|poly16x4_t
name|test_vreinterpret_p16_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_p16_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_p16_u64
end_comment

begin_function
name|poly16x4_t
name|test_vreinterpret_p16_u64
parameter_list|(
name|uint64x1_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_p16_u64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_p16_f16
end_comment

begin_function
name|poly16x4_t
name|test_vreinterpret_p16_f16
parameter_list|(
name|float16x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_p16_f16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_p16_f32
end_comment

begin_function
name|poly16x4_t
name|test_vreinterpret_p16_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_p16_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_p16_p8
end_comment

begin_function
name|poly16x4_t
name|test_vreinterpret_p16_p8
parameter_list|(
name|poly8x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_p16_p8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_s8_s16
end_comment

begin_function
name|int8x16_t
name|test_vreinterpretq_s8_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s8_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_s8_s32
end_comment

begin_function
name|int8x16_t
name|test_vreinterpretq_s8_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s8_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_s8_s64
end_comment

begin_function
name|int8x16_t
name|test_vreinterpretq_s8_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s8_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_s8_u8
end_comment

begin_function
name|int8x16_t
name|test_vreinterpretq_s8_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s8_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_s8_u16
end_comment

begin_function
name|int8x16_t
name|test_vreinterpretq_s8_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s8_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_s8_u32
end_comment

begin_function
name|int8x16_t
name|test_vreinterpretq_s8_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s8_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_s8_u64
end_comment

begin_function
name|int8x16_t
name|test_vreinterpretq_s8_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s8_u64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_s8_f16
end_comment

begin_function
name|int8x16_t
name|test_vreinterpretq_s8_f16
parameter_list|(
name|float16x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s8_f16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_s8_f32
end_comment

begin_function
name|int8x16_t
name|test_vreinterpretq_s8_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s8_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_s8_p8
end_comment

begin_function
name|int8x16_t
name|test_vreinterpretq_s8_p8
parameter_list|(
name|poly8x16_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s8_p8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_s8_p16
end_comment

begin_function
name|int8x16_t
name|test_vreinterpretq_s8_p16
parameter_list|(
name|poly16x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s8_p16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_s16_s8
end_comment

begin_function
name|int16x8_t
name|test_vreinterpretq_s16_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s16_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_s16_s32
end_comment

begin_function
name|int16x8_t
name|test_vreinterpretq_s16_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s16_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_s16_s64
end_comment

begin_function
name|int16x8_t
name|test_vreinterpretq_s16_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s16_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_s16_u8
end_comment

begin_function
name|int16x8_t
name|test_vreinterpretq_s16_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s16_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_s16_u16
end_comment

begin_function
name|int16x8_t
name|test_vreinterpretq_s16_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s16_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_s16_u32
end_comment

begin_function
name|int16x8_t
name|test_vreinterpretq_s16_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s16_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_s16_u64
end_comment

begin_function
name|int16x8_t
name|test_vreinterpretq_s16_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s16_u64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_s16_f16
end_comment

begin_function
name|int16x8_t
name|test_vreinterpretq_s16_f16
parameter_list|(
name|float16x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s16_f16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_s16_f32
end_comment

begin_function
name|int16x8_t
name|test_vreinterpretq_s16_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s16_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_s16_p8
end_comment

begin_function
name|int16x8_t
name|test_vreinterpretq_s16_p8
parameter_list|(
name|poly8x16_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s16_p8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_s16_p16
end_comment

begin_function
name|int16x8_t
name|test_vreinterpretq_s16_p16
parameter_list|(
name|poly16x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s16_p16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_s32_s8
end_comment

begin_function
name|int32x4_t
name|test_vreinterpretq_s32_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s32_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_s32_s16
end_comment

begin_function
name|int32x4_t
name|test_vreinterpretq_s32_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s32_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_s32_s64
end_comment

begin_function
name|int32x4_t
name|test_vreinterpretq_s32_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s32_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_s32_u8
end_comment

begin_function
name|int32x4_t
name|test_vreinterpretq_s32_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s32_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_s32_u16
end_comment

begin_function
name|int32x4_t
name|test_vreinterpretq_s32_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s32_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_s32_u32
end_comment

begin_function
name|int32x4_t
name|test_vreinterpretq_s32_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s32_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_s32_u64
end_comment

begin_function
name|int32x4_t
name|test_vreinterpretq_s32_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s32_u64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_s32_f16
end_comment

begin_function
name|int32x4_t
name|test_vreinterpretq_s32_f16
parameter_list|(
name|float16x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s32_f16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_s32_f32
end_comment

begin_function
name|int32x4_t
name|test_vreinterpretq_s32_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s32_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_s32_p8
end_comment

begin_function
name|int32x4_t
name|test_vreinterpretq_s32_p8
parameter_list|(
name|poly8x16_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s32_p8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_s32_p16
end_comment

begin_function
name|int32x4_t
name|test_vreinterpretq_s32_p16
parameter_list|(
name|poly16x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s32_p16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_s64_s8
end_comment

begin_function
name|int64x2_t
name|test_vreinterpretq_s64_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s64_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_s64_s16
end_comment

begin_function
name|int64x2_t
name|test_vreinterpretq_s64_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s64_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_s64_s32
end_comment

begin_function
name|int64x2_t
name|test_vreinterpretq_s64_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s64_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_s64_u8
end_comment

begin_function
name|int64x2_t
name|test_vreinterpretq_s64_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s64_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_s64_u16
end_comment

begin_function
name|int64x2_t
name|test_vreinterpretq_s64_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s64_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_s64_u32
end_comment

begin_function
name|int64x2_t
name|test_vreinterpretq_s64_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s64_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_s64_u64
end_comment

begin_function
name|int64x2_t
name|test_vreinterpretq_s64_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s64_u64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_s64_f16
end_comment

begin_function
name|int64x2_t
name|test_vreinterpretq_s64_f16
parameter_list|(
name|float16x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s64_f16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_s64_f32
end_comment

begin_function
name|int64x2_t
name|test_vreinterpretq_s64_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s64_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_s64_p8
end_comment

begin_function
name|int64x2_t
name|test_vreinterpretq_s64_p8
parameter_list|(
name|poly8x16_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s64_p8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_s64_p16
end_comment

begin_function
name|int64x2_t
name|test_vreinterpretq_s64_p16
parameter_list|(
name|poly16x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s64_p16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_u8_s8
end_comment

begin_function
name|uint8x16_t
name|test_vreinterpretq_u8_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u8_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_u8_s16
end_comment

begin_function
name|uint8x16_t
name|test_vreinterpretq_u8_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u8_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_u8_s32
end_comment

begin_function
name|uint8x16_t
name|test_vreinterpretq_u8_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u8_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_u8_s64
end_comment

begin_function
name|uint8x16_t
name|test_vreinterpretq_u8_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u8_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_u8_u16
end_comment

begin_function
name|uint8x16_t
name|test_vreinterpretq_u8_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u8_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_u8_u32
end_comment

begin_function
name|uint8x16_t
name|test_vreinterpretq_u8_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u8_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_u8_u64
end_comment

begin_function
name|uint8x16_t
name|test_vreinterpretq_u8_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u8_u64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_u8_f16
end_comment

begin_function
name|uint8x16_t
name|test_vreinterpretq_u8_f16
parameter_list|(
name|float16x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u8_f16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_u8_f32
end_comment

begin_function
name|uint8x16_t
name|test_vreinterpretq_u8_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u8_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_u8_p8
end_comment

begin_function
name|uint8x16_t
name|test_vreinterpretq_u8_p8
parameter_list|(
name|poly8x16_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u8_p8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_u8_p16
end_comment

begin_function
name|uint8x16_t
name|test_vreinterpretq_u8_p16
parameter_list|(
name|poly16x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u8_p16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_u16_s8
end_comment

begin_function
name|uint16x8_t
name|test_vreinterpretq_u16_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u16_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_u16_s16
end_comment

begin_function
name|uint16x8_t
name|test_vreinterpretq_u16_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u16_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_u16_s32
end_comment

begin_function
name|uint16x8_t
name|test_vreinterpretq_u16_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u16_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_u16_s64
end_comment

begin_function
name|uint16x8_t
name|test_vreinterpretq_u16_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u16_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_u16_u8
end_comment

begin_function
name|uint16x8_t
name|test_vreinterpretq_u16_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u16_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_u16_u32
end_comment

begin_function
name|uint16x8_t
name|test_vreinterpretq_u16_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u16_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_u16_u64
end_comment

begin_function
name|uint16x8_t
name|test_vreinterpretq_u16_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u16_u64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_u16_f16
end_comment

begin_function
name|uint16x8_t
name|test_vreinterpretq_u16_f16
parameter_list|(
name|float16x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u16_f16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_u16_f32
end_comment

begin_function
name|uint16x8_t
name|test_vreinterpretq_u16_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u16_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_u16_p8
end_comment

begin_function
name|uint16x8_t
name|test_vreinterpretq_u16_p8
parameter_list|(
name|poly8x16_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u16_p8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_u16_p16
end_comment

begin_function
name|uint16x8_t
name|test_vreinterpretq_u16_p16
parameter_list|(
name|poly16x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u16_p16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_u32_s8
end_comment

begin_function
name|uint32x4_t
name|test_vreinterpretq_u32_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u32_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_u32_s16
end_comment

begin_function
name|uint32x4_t
name|test_vreinterpretq_u32_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u32_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_u32_s32
end_comment

begin_function
name|uint32x4_t
name|test_vreinterpretq_u32_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u32_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_u32_s64
end_comment

begin_function
name|uint32x4_t
name|test_vreinterpretq_u32_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u32_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_u32_u8
end_comment

begin_function
name|uint32x4_t
name|test_vreinterpretq_u32_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u32_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_u32_u16
end_comment

begin_function
name|uint32x4_t
name|test_vreinterpretq_u32_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u32_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_u32_u64
end_comment

begin_function
name|uint32x4_t
name|test_vreinterpretq_u32_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u32_u64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_u32_f16
end_comment

begin_function
name|uint32x4_t
name|test_vreinterpretq_u32_f16
parameter_list|(
name|float16x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u32_f16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_u32_f32
end_comment

begin_function
name|uint32x4_t
name|test_vreinterpretq_u32_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u32_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_u32_p8
end_comment

begin_function
name|uint32x4_t
name|test_vreinterpretq_u32_p8
parameter_list|(
name|poly8x16_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u32_p8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_u32_p16
end_comment

begin_function
name|uint32x4_t
name|test_vreinterpretq_u32_p16
parameter_list|(
name|poly16x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u32_p16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_u64_s8
end_comment

begin_function
name|uint64x2_t
name|test_vreinterpretq_u64_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u64_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_u64_s16
end_comment

begin_function
name|uint64x2_t
name|test_vreinterpretq_u64_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u64_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_u64_s32
end_comment

begin_function
name|uint64x2_t
name|test_vreinterpretq_u64_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u64_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_u64_s64
end_comment

begin_function
name|uint64x2_t
name|test_vreinterpretq_u64_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u64_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_u64_u8
end_comment

begin_function
name|uint64x2_t
name|test_vreinterpretq_u64_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u64_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_u64_u16
end_comment

begin_function
name|uint64x2_t
name|test_vreinterpretq_u64_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u64_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_u64_u32
end_comment

begin_function
name|uint64x2_t
name|test_vreinterpretq_u64_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u64_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_u64_f16
end_comment

begin_function
name|uint64x2_t
name|test_vreinterpretq_u64_f16
parameter_list|(
name|float16x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u64_f16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_u64_f32
end_comment

begin_function
name|uint64x2_t
name|test_vreinterpretq_u64_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u64_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_u64_p8
end_comment

begin_function
name|uint64x2_t
name|test_vreinterpretq_u64_p8
parameter_list|(
name|poly8x16_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u64_p8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_u64_p16
end_comment

begin_function
name|uint64x2_t
name|test_vreinterpretq_u64_p16
parameter_list|(
name|poly16x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u64_p16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_f16_s8
end_comment

begin_function
name|float16x8_t
name|test_vreinterpretq_f16_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_f16_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_f16_s16
end_comment

begin_function
name|float16x8_t
name|test_vreinterpretq_f16_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_f16_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_f16_s32
end_comment

begin_function
name|float16x8_t
name|test_vreinterpretq_f16_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_f16_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_f16_s64
end_comment

begin_function
name|float16x8_t
name|test_vreinterpretq_f16_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_f16_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_f16_u8
end_comment

begin_function
name|float16x8_t
name|test_vreinterpretq_f16_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_f16_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_f16_u16
end_comment

begin_function
name|float16x8_t
name|test_vreinterpretq_f16_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_f16_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_f16_u32
end_comment

begin_function
name|float16x8_t
name|test_vreinterpretq_f16_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_f16_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_f16_u64
end_comment

begin_function
name|float16x8_t
name|test_vreinterpretq_f16_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_f16_u64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_f16_f32
end_comment

begin_function
name|float16x8_t
name|test_vreinterpretq_f16_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_f16_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_f16_p8
end_comment

begin_function
name|float16x8_t
name|test_vreinterpretq_f16_p8
parameter_list|(
name|poly8x16_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_f16_p8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_f16_p16
end_comment

begin_function
name|float16x8_t
name|test_vreinterpretq_f16_p16
parameter_list|(
name|poly16x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_f16_p16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_f32_s8
end_comment

begin_function
name|float32x4_t
name|test_vreinterpretq_f32_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_f32_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_f32_s16
end_comment

begin_function
name|float32x4_t
name|test_vreinterpretq_f32_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_f32_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_f32_s32
end_comment

begin_function
name|float32x4_t
name|test_vreinterpretq_f32_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_f32_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_f32_s64
end_comment

begin_function
name|float32x4_t
name|test_vreinterpretq_f32_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_f32_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_f32_u8
end_comment

begin_function
name|float32x4_t
name|test_vreinterpretq_f32_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_f32_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_f32_u16
end_comment

begin_function
name|float32x4_t
name|test_vreinterpretq_f32_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_f32_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_f32_u32
end_comment

begin_function
name|float32x4_t
name|test_vreinterpretq_f32_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_f32_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_f32_u64
end_comment

begin_function
name|float32x4_t
name|test_vreinterpretq_f32_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_f32_u64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_f32_f16
end_comment

begin_function
name|float32x4_t
name|test_vreinterpretq_f32_f16
parameter_list|(
name|float16x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_f32_f16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_f32_p8
end_comment

begin_function
name|float32x4_t
name|test_vreinterpretq_f32_p8
parameter_list|(
name|poly8x16_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_f32_p8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_f32_p16
end_comment

begin_function
name|float32x4_t
name|test_vreinterpretq_f32_p16
parameter_list|(
name|poly16x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_f32_p16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_p8_s8
end_comment

begin_function
name|poly8x16_t
name|test_vreinterpretq_p8_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_p8_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_p8_s16
end_comment

begin_function
name|poly8x16_t
name|test_vreinterpretq_p8_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_p8_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_p8_s32
end_comment

begin_function
name|poly8x16_t
name|test_vreinterpretq_p8_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_p8_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_p8_s64
end_comment

begin_function
name|poly8x16_t
name|test_vreinterpretq_p8_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_p8_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_p8_u8
end_comment

begin_function
name|poly8x16_t
name|test_vreinterpretq_p8_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_p8_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_p8_u16
end_comment

begin_function
name|poly8x16_t
name|test_vreinterpretq_p8_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_p8_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_p8_u32
end_comment

begin_function
name|poly8x16_t
name|test_vreinterpretq_p8_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_p8_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_p8_u64
end_comment

begin_function
name|poly8x16_t
name|test_vreinterpretq_p8_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_p8_u64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_p8_f16
end_comment

begin_function
name|poly8x16_t
name|test_vreinterpretq_p8_f16
parameter_list|(
name|float16x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_p8_f16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_p8_f32
end_comment

begin_function
name|poly8x16_t
name|test_vreinterpretq_p8_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_p8_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_p8_p16
end_comment

begin_function
name|poly8x16_t
name|test_vreinterpretq_p8_p16
parameter_list|(
name|poly16x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_p8_p16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_p16_s8
end_comment

begin_function
name|poly16x8_t
name|test_vreinterpretq_p16_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_p16_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_p16_s16
end_comment

begin_function
name|poly16x8_t
name|test_vreinterpretq_p16_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_p16_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_p16_s32
end_comment

begin_function
name|poly16x8_t
name|test_vreinterpretq_p16_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_p16_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_p16_s64
end_comment

begin_function
name|poly16x8_t
name|test_vreinterpretq_p16_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_p16_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_p16_u8
end_comment

begin_function
name|poly16x8_t
name|test_vreinterpretq_p16_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_p16_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_p16_u16
end_comment

begin_function
name|poly16x8_t
name|test_vreinterpretq_p16_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_p16_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_p16_u32
end_comment

begin_function
name|poly16x8_t
name|test_vreinterpretq_p16_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_p16_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_p16_u64
end_comment

begin_function
name|poly16x8_t
name|test_vreinterpretq_p16_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_p16_u64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_p16_f16
end_comment

begin_function
name|poly16x8_t
name|test_vreinterpretq_p16_f16
parameter_list|(
name|float16x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_p16_f16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_p16_f32
end_comment

begin_function
name|poly16x8_t
name|test_vreinterpretq_p16_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_p16_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_p16_p8
end_comment

begin_function
name|poly16x8_t
name|test_vreinterpretq_p16_p8
parameter_list|(
name|poly8x16_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_p16_p8
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
comment|// CHECK: vrev16.8 d{{[0-9]+}}, d{{[0-9]+}}
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
comment|// CHECK: vrev16.8 d{{[0-9]+}}, d{{[0-9]+}}
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
comment|// CHECK: vrev16.8 d{{[0-9]+}}, d{{[0-9]+}}
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
comment|// CHECK: vrev16.8 q{{[0-9]+}}, q{{[0-9]+}}
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
comment|// CHECK: vrev16.8 q{{[0-9]+}}, q{{[0-9]+}}
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
comment|// CHECK: vrev16.8 q{{[0-9]+}}, q{{[0-9]+}}
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
comment|// CHECK: vrev32.8 d{{[0-9]+}}, d{{[0-9]+}}
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
comment|// CHECK: vrev32.16 d{{[0-9]+}}, d{{[0-9]+}}
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
comment|// CHECK: vrev32.8 d{{[0-9]+}}, d{{[0-9]+}}
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
comment|// CHECK: vrev32.16 d{{[0-9]+}}, d{{[0-9]+}}
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
comment|// CHECK: vrev32.8 d{{[0-9]+}}, d{{[0-9]+}}
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
comment|// CHECK: vrev32.16 d{{[0-9]+}}, d{{[0-9]+}}
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
comment|// CHECK: vrev32.8 q{{[0-9]+}}, q{{[0-9]+}}
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
comment|// CHECK: vrev32.16 q{{[0-9]+}}, q{{[0-9]+}}
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
comment|// CHECK: vrev32.8 q{{[0-9]+}}, q{{[0-9]+}}
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
comment|// CHECK: vrev32.16 q{{[0-9]+}}, q{{[0-9]+}}
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
comment|// CHECK: vrev32.8 q{{[0-9]+}}, q{{[0-9]+}}
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
comment|// CHECK: vrev32.16 q{{[0-9]+}}, q{{[0-9]+}}
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
comment|// CHECK: vrev64.8 d{{[0-9]+}}, d{{[0-9]+}}
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
comment|// CHECK: vrev64.16 d{{[0-9]+}}, d{{[0-9]+}}
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
comment|// CHECK: vrev64.32 d{{[0-9]+}}, d{{[0-9]+}}
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
comment|// CHECK: vrev64.8 d{{[0-9]+}}, d{{[0-9]+}}
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
comment|// CHECK: vrev64.16 d{{[0-9]+}}, d{{[0-9]+}}
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
comment|// CHECK: vrev64.32 d{{[0-9]+}}, d{{[0-9]+}}
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
comment|// CHECK: vrev64.8 d{{[0-9]+}}, d{{[0-9]+}}
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
comment|// CHECK: vrev64.16 d{{[0-9]+}}, d{{[0-9]+}}
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
comment|// CHECK: vrev64.32 d{{[0-9]+}}, d{{[0-9]+}}
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
comment|// CHECK: vrev64.8 q{{[0-9]+}}, q{{[0-9]+}}
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
comment|// CHECK: vrev64.16 q{{[0-9]+}}, q{{[0-9]+}}
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
comment|// CHECK: vrev64.32 q{{[0-9]+}}, q{{[0-9]+}}
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
comment|// CHECK: vrev64.8 q{{[0-9]+}}, q{{[0-9]+}}
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
comment|// CHECK: vrev64.16 q{{[0-9]+}}, q{{[0-9]+}}
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
comment|// CHECK: vrev64.32 q{{[0-9]+}}, q{{[0-9]+}}
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
comment|// CHECK: vrev64.8 q{{[0-9]+}}, q{{[0-9]+}}
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
comment|// CHECK: vrev64.16 q{{[0-9]+}}, q{{[0-9]+}}
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
comment|// CHECK: vrev64.32 q{{[0-9]+}}, q{{[0-9]+}}
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

begin_comment
comment|// CHECK-LABEL: test_vrhadd_s8
end_comment

begin_comment
comment|// CHECK: vrhadd.s8 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int8x8_t
name|test_vrhadd_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
return|return
name|vrhadd_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrhadd_s16
end_comment

begin_comment
comment|// CHECK: vrhadd.s16 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int16x4_t
name|test_vrhadd_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
return|return
name|vrhadd_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrhadd_s32
end_comment

begin_comment
comment|// CHECK: vrhadd.s32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int32x2_t
name|test_vrhadd_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
return|return
name|vrhadd_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrhadd_u8
end_comment

begin_comment
comment|// CHECK: vrhadd.u8 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint8x8_t
name|test_vrhadd_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|)
block|{
return|return
name|vrhadd_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrhadd_u16
end_comment

begin_comment
comment|// CHECK: vrhadd.u16 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint16x4_t
name|test_vrhadd_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|)
block|{
return|return
name|vrhadd_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrhadd_u32
end_comment

begin_comment
comment|// CHECK: vrhadd.u32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint32x2_t
name|test_vrhadd_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|)
block|{
return|return
name|vrhadd_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrhaddq_s8
end_comment

begin_comment
comment|// CHECK: vrhadd.s8 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int8x16_t
name|test_vrhaddq_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|)
block|{
return|return
name|vrhaddq_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrhaddq_s16
end_comment

begin_comment
comment|// CHECK: vrhadd.s16 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int16x8_t
name|test_vrhaddq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
return|return
name|vrhaddq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrhaddq_s32
end_comment

begin_comment
comment|// CHECK: vrhadd.s32 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int32x4_t
name|test_vrhaddq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
return|return
name|vrhaddq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrhaddq_u8
end_comment

begin_comment
comment|// CHECK: vrhadd.u8 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint8x16_t
name|test_vrhaddq_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|,
name|uint8x16_t
name|b
parameter_list|)
block|{
return|return
name|vrhaddq_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrhaddq_u16
end_comment

begin_comment
comment|// CHECK: vrhadd.u16 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint16x8_t
name|test_vrhaddq_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|)
block|{
return|return
name|vrhaddq_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrhaddq_u32
end_comment

begin_comment
comment|// CHECK: vrhadd.u32 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint32x4_t
name|test_vrhaddq_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|)
block|{
return|return
name|vrhaddq_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrshl_s8
end_comment

begin_comment
comment|// CHECK: vrshl.s8 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int8x8_t
name|test_vrshl_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
return|return
name|vrshl_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrshl_s16
end_comment

begin_comment
comment|// CHECK: vrshl.s16 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int16x4_t
name|test_vrshl_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
return|return
name|vrshl_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrshl_s32
end_comment

begin_comment
comment|// CHECK: vrshl.s32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int32x2_t
name|test_vrshl_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
return|return
name|vrshl_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrshl_s64
end_comment

begin_comment
comment|// CHECK: vrshl.s64 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int64x1_t
name|test_vrshl_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|,
name|int64x1_t
name|b
parameter_list|)
block|{
return|return
name|vrshl_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrshl_u8
end_comment

begin_comment
comment|// CHECK: vrshl.u8 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint8x8_t
name|test_vrshl_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
return|return
name|vrshl_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrshl_u16
end_comment

begin_comment
comment|// CHECK: vrshl.u16 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint16x4_t
name|test_vrshl_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
return|return
name|vrshl_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrshl_u32
end_comment

begin_comment
comment|// CHECK: vrshl.u32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint32x2_t
name|test_vrshl_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
return|return
name|vrshl_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrshl_u64
end_comment

begin_comment
comment|// CHECK: vrshl.u64 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint64x1_t
name|test_vrshl_u64
parameter_list|(
name|uint64x1_t
name|a
parameter_list|,
name|int64x1_t
name|b
parameter_list|)
block|{
return|return
name|vrshl_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrshlq_s8
end_comment

begin_comment
comment|// CHECK: vrshl.s8 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int8x16_t
name|test_vrshlq_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|)
block|{
return|return
name|vrshlq_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrshlq_s16
end_comment

begin_comment
comment|// CHECK: vrshl.s16 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int16x8_t
name|test_vrshlq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
return|return
name|vrshlq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrshlq_s32
end_comment

begin_comment
comment|// CHECK: vrshl.s32 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int32x4_t
name|test_vrshlq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
return|return
name|vrshlq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrshlq_s64
end_comment

begin_comment
comment|// CHECK: vrshl.s64 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int64x2_t
name|test_vrshlq_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int64x2_t
name|b
parameter_list|)
block|{
return|return
name|vrshlq_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrshlq_u8
end_comment

begin_comment
comment|// CHECK: vrshl.u8 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint8x16_t
name|test_vrshlq_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|)
block|{
return|return
name|vrshlq_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrshlq_u16
end_comment

begin_comment
comment|// CHECK: vrshl.u16 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint16x8_t
name|test_vrshlq_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
return|return
name|vrshlq_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrshlq_u32
end_comment

begin_comment
comment|// CHECK: vrshl.u32 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint32x4_t
name|test_vrshlq_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
return|return
name|vrshlq_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrshlq_u64
end_comment

begin_comment
comment|// CHECK: vrshl.u64 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint64x2_t
name|test_vrshlq_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|,
name|int64x2_t
name|b
parameter_list|)
block|{
return|return
name|vrshlq_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrshrn_n_s16
end_comment

begin_comment
comment|// CHECK: vrshrn.i16 d{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|int8x8_t
name|test_vrshrn_n_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
return|return
name|vrshrn_n_s16
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrshrn_n_s32
end_comment

begin_comment
comment|// CHECK: vrshrn.i32 d{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|int16x4_t
name|test_vrshrn_n_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
return|return
name|vrshrn_n_s32
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrshrn_n_s64
end_comment

begin_comment
comment|// CHECK: vrshrn.i64 d{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|int32x2_t
name|test_vrshrn_n_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|)
block|{
return|return
name|vrshrn_n_s64
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrshrn_n_u16
end_comment

begin_comment
comment|// CHECK: vrshrn.i16 d{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|uint8x8_t
name|test_vrshrn_n_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|)
block|{
return|return
name|vrshrn_n_u16
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrshrn_n_u32
end_comment

begin_comment
comment|// CHECK: vrshrn.i32 d{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|uint16x4_t
name|test_vrshrn_n_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|)
block|{
return|return
name|vrshrn_n_u32
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrshrn_n_u64
end_comment

begin_comment
comment|// CHECK: vrshrn.i64 d{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|uint32x2_t
name|test_vrshrn_n_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|)
block|{
return|return
name|vrshrn_n_u64
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrshr_n_s8
end_comment

begin_comment
comment|// CHECK: vrshr.s8 d{{[0-9]+}}, d{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|int8x8_t
name|test_vrshr_n_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
return|return
name|vrshr_n_s8
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrshr_n_s16
end_comment

begin_comment
comment|// CHECK: vrshr.s16 d{{[0-9]+}}, d{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|int16x4_t
name|test_vrshr_n_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|)
block|{
return|return
name|vrshr_n_s16
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrshr_n_s32
end_comment

begin_comment
comment|// CHECK: vrshr.s32 d{{[0-9]+}}, d{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|int32x2_t
name|test_vrshr_n_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|)
block|{
return|return
name|vrshr_n_s32
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrshr_n_s64
end_comment

begin_comment
comment|// CHECK: vrshr.s64 d{{[0-9]+}}, d{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|int64x1_t
name|test_vrshr_n_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|)
block|{
return|return
name|vrshr_n_s64
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrshr_n_u8
end_comment

begin_comment
comment|// CHECK: vrshr.u8 d{{[0-9]+}}, d{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|uint8x8_t
name|test_vrshr_n_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|)
block|{
return|return
name|vrshr_n_u8
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrshr_n_u16
end_comment

begin_comment
comment|// CHECK: vrshr.u16 d{{[0-9]+}}, d{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|uint16x4_t
name|test_vrshr_n_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|)
block|{
return|return
name|vrshr_n_u16
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrshr_n_u32
end_comment

begin_comment
comment|// CHECK: vrshr.u32 d{{[0-9]+}}, d{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|uint32x2_t
name|test_vrshr_n_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|)
block|{
return|return
name|vrshr_n_u32
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrshr_n_u64
end_comment

begin_comment
comment|// CHECK: vrshr.u64 d{{[0-9]+}}, d{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|uint64x1_t
name|test_vrshr_n_u64
parameter_list|(
name|uint64x1_t
name|a
parameter_list|)
block|{
return|return
name|vrshr_n_u64
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrshrq_n_s8
end_comment

begin_comment
comment|// CHECK: vrshr.s8 q{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|int8x16_t
name|test_vrshrq_n_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
return|return
name|vrshrq_n_s8
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrshrq_n_s16
end_comment

begin_comment
comment|// CHECK: vrshr.s16 q{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|int16x8_t
name|test_vrshrq_n_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
return|return
name|vrshrq_n_s16
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrshrq_n_s32
end_comment

begin_comment
comment|// CHECK: vrshr.s32 q{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|int32x4_t
name|test_vrshrq_n_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
return|return
name|vrshrq_n_s32
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrshrq_n_s64
end_comment

begin_comment
comment|// CHECK: vrshr.s64 q{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|int64x2_t
name|test_vrshrq_n_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|)
block|{
return|return
name|vrshrq_n_s64
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrshrq_n_u8
end_comment

begin_comment
comment|// CHECK: vrshr.u8 q{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|uint8x16_t
name|test_vrshrq_n_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|)
block|{
return|return
name|vrshrq_n_u8
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrshrq_n_u16
end_comment

begin_comment
comment|// CHECK: vrshr.u16 q{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|uint16x8_t
name|test_vrshrq_n_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|)
block|{
return|return
name|vrshrq_n_u16
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrshrq_n_u32
end_comment

begin_comment
comment|// CHECK: vrshr.u32 q{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|uint32x4_t
name|test_vrshrq_n_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|)
block|{
return|return
name|vrshrq_n_u32
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrshrq_n_u64
end_comment

begin_comment
comment|// CHECK: vrshr.u64 q{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|uint64x2_t
name|test_vrshrq_n_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|)
block|{
return|return
name|vrshrq_n_u64
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrsqrte_f32
end_comment

begin_comment
comment|// CHECK: vrsqrte.f32 d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|float32x2_t
name|test_vrsqrte_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
return|return
name|vrsqrte_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrsqrte_u32
end_comment

begin_comment
comment|// CHECK: vrsqrte.u32 d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint32x2_t
name|test_vrsqrte_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|)
block|{
return|return
name|vrsqrte_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrsqrteq_f32
end_comment

begin_comment
comment|// CHECK: vrsqrte.f32 q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|float32x4_t
name|test_vrsqrteq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
return|return
name|vrsqrteq_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrsqrteq_u32
end_comment

begin_comment
comment|// CHECK: vrsqrte.u32 q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint32x4_t
name|test_vrsqrteq_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|)
block|{
return|return
name|vrsqrteq_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrsqrts_f32
end_comment

begin_comment
comment|// CHECK: vrsqrts.f32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|float32x2_t
name|test_vrsqrts_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32x2_t
name|b
parameter_list|)
block|{
return|return
name|vrsqrts_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrsqrtsq_f32
end_comment

begin_comment
comment|// CHECK: vrsqrts.f32 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|float32x4_t
name|test_vrsqrtsq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|,
name|float32x4_t
name|b
parameter_list|)
block|{
return|return
name|vrsqrtsq_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrsra_n_s8
end_comment

begin_comment
comment|// CHECK: vrsra.s8 d{{[0-9]+}}, d{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|int8x8_t
name|test_vrsra_n_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
return|return
name|vrsra_n_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrsra_n_s16
end_comment

begin_comment
comment|// CHECK: vrsra.s16 d{{[0-9]+}}, d{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|int16x4_t
name|test_vrsra_n_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
return|return
name|vrsra_n_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrsra_n_s32
end_comment

begin_comment
comment|// CHECK: vrsra.s32 d{{[0-9]+}}, d{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|int32x2_t
name|test_vrsra_n_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
return|return
name|vrsra_n_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrsra_n_s64
end_comment

begin_comment
comment|// CHECK: vrsra.s64 d{{[0-9]+}}, d{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|int64x1_t
name|test_vrsra_n_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|,
name|int64x1_t
name|b
parameter_list|)
block|{
return|return
name|vrsra_n_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrsra_n_u8
end_comment

begin_comment
comment|// CHECK: vrsra.u8 d{{[0-9]+}}, d{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|uint8x8_t
name|test_vrsra_n_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|)
block|{
return|return
name|vrsra_n_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrsra_n_u16
end_comment

begin_comment
comment|// CHECK: vrsra.u16 d{{[0-9]+}}, d{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|uint16x4_t
name|test_vrsra_n_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|)
block|{
return|return
name|vrsra_n_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrsra_n_u32
end_comment

begin_comment
comment|// CHECK: vrsra.u32 d{{[0-9]+}}, d{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|uint32x2_t
name|test_vrsra_n_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|)
block|{
return|return
name|vrsra_n_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrsra_n_u64
end_comment

begin_comment
comment|// CHECK: vrsra.u64 d{{[0-9]+}}, d{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|uint64x1_t
name|test_vrsra_n_u64
parameter_list|(
name|uint64x1_t
name|a
parameter_list|,
name|uint64x1_t
name|b
parameter_list|)
block|{
return|return
name|vrsra_n_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrsraq_n_s8
end_comment

begin_comment
comment|// CHECK: vrsra.s8 q{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|int8x16_t
name|test_vrsraq_n_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|)
block|{
return|return
name|vrsraq_n_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrsraq_n_s16
end_comment

begin_comment
comment|// CHECK: vrsra.s16 q{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|int16x8_t
name|test_vrsraq_n_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
return|return
name|vrsraq_n_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrsraq_n_s32
end_comment

begin_comment
comment|// CHECK: vrsra.s32 q{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|int32x4_t
name|test_vrsraq_n_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
return|return
name|vrsraq_n_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrsraq_n_s64
end_comment

begin_comment
comment|// CHECK: vrsra.s64 q{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|int64x2_t
name|test_vrsraq_n_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int64x2_t
name|b
parameter_list|)
block|{
return|return
name|vrsraq_n_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrsraq_n_u8
end_comment

begin_comment
comment|// CHECK: vrsra.u8 q{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|uint8x16_t
name|test_vrsraq_n_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|,
name|uint8x16_t
name|b
parameter_list|)
block|{
return|return
name|vrsraq_n_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrsraq_n_u16
end_comment

begin_comment
comment|// CHECK: vrsra.u16 q{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|uint16x8_t
name|test_vrsraq_n_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|)
block|{
return|return
name|vrsraq_n_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrsraq_n_u32
end_comment

begin_comment
comment|// CHECK: vrsra.u32 q{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|uint32x4_t
name|test_vrsraq_n_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|)
block|{
return|return
name|vrsraq_n_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrsraq_n_u64
end_comment

begin_comment
comment|// CHECK: vrsra.u64 q{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|uint64x2_t
name|test_vrsraq_n_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|,
name|uint64x2_t
name|b
parameter_list|)
block|{
return|return
name|vrsraq_n_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrsubhn_s16
end_comment

begin_comment
comment|// CHECK: vrsubhn.i16 d{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int8x8_t
name|test_vrsubhn_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
return|return
name|vrsubhn_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrsubhn_s32
end_comment

begin_comment
comment|// CHECK: vrsubhn.i32 d{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int16x4_t
name|test_vrsubhn_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
return|return
name|vrsubhn_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrsubhn_s64
end_comment

begin_comment
comment|// CHECK: vrsubhn.i64 d{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int32x2_t
name|test_vrsubhn_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int64x2_t
name|b
parameter_list|)
block|{
return|return
name|vrsubhn_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrsubhn_u16
end_comment

begin_comment
comment|// CHECK: vrsubhn.i16 d{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint8x8_t
name|test_vrsubhn_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|)
block|{
return|return
name|vrsubhn_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrsubhn_u32
end_comment

begin_comment
comment|// CHECK: vrsubhn.i32 d{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint16x4_t
name|test_vrsubhn_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|)
block|{
return|return
name|vrsubhn_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrsubhn_u64
end_comment

begin_comment
comment|// CHECK: vrsubhn.i64 d{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint32x2_t
name|test_vrsubhn_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|,
name|uint64x2_t
name|b
parameter_list|)
block|{
return|return
name|vrsubhn_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vset_lane_u8
end_comment

begin_comment
comment|// CHECK: vmov
end_comment

begin_function
name|uint8x8_t
name|test_vset_lane_u8
parameter_list|(
name|uint8_t
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|)
block|{
return|return
name|vset_lane_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vset_lane_u16
end_comment

begin_comment
comment|// CHECK: vmov
end_comment

begin_function
name|uint16x4_t
name|test_vset_lane_u16
parameter_list|(
name|uint16_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|)
block|{
return|return
name|vset_lane_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vset_lane_u32
end_comment

begin_comment
comment|// CHECK: mov
end_comment

begin_function
name|uint32x2_t
name|test_vset_lane_u32
parameter_list|(
name|uint32_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|)
block|{
return|return
name|vset_lane_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vset_lane_s8
end_comment

begin_comment
comment|// CHECK: vmov
end_comment

begin_function
name|int8x8_t
name|test_vset_lane_s8
parameter_list|(
name|int8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
return|return
name|vset_lane_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vset_lane_s16
end_comment

begin_comment
comment|// CHECK: vmov
end_comment

begin_function
name|int16x4_t
name|test_vset_lane_s16
parameter_list|(
name|int16_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
return|return
name|vset_lane_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vset_lane_s32
end_comment

begin_comment
comment|// CHECK: mov
end_comment

begin_function
name|int32x2_t
name|test_vset_lane_s32
parameter_list|(
name|int32_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
return|return
name|vset_lane_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vset_lane_p8
end_comment

begin_comment
comment|// CHECK: vmov
end_comment

begin_function
name|poly8x8_t
name|test_vset_lane_p8
parameter_list|(
name|poly8_t
name|a
parameter_list|,
name|poly8x8_t
name|b
parameter_list|)
block|{
return|return
name|vset_lane_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vset_lane_p16
end_comment

begin_comment
comment|// CHECK: vmov
end_comment

begin_function
name|poly16x4_t
name|test_vset_lane_p16
parameter_list|(
name|poly16_t
name|a
parameter_list|,
name|poly16x4_t
name|b
parameter_list|)
block|{
return|return
name|vset_lane_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vset_lane_f32
end_comment

begin_comment
comment|// CHECK: mov
end_comment

begin_function
name|float32x2_t
name|test_vset_lane_f32
parameter_list|(
name|float32_t
name|a
parameter_list|,
name|float32x2_t
name|b
parameter_list|)
block|{
return|return
name|vset_lane_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vsetq_lane_u8
end_comment

begin_comment
comment|// CHECK: vmov
end_comment

begin_function
name|uint8x16_t
name|test_vsetq_lane_u8
parameter_list|(
name|uint8_t
name|a
parameter_list|,
name|uint8x16_t
name|b
parameter_list|)
block|{
return|return
name|vsetq_lane_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|15
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vsetq_lane_u16
end_comment

begin_comment
comment|// CHECK: vmov
end_comment

begin_function
name|uint16x8_t
name|test_vsetq_lane_u16
parameter_list|(
name|uint16_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|)
block|{
return|return
name|vsetq_lane_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vsetq_lane_u32
end_comment

begin_comment
comment|// CHECK: vmov
end_comment

begin_function
name|uint32x4_t
name|test_vsetq_lane_u32
parameter_list|(
name|uint32_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|)
block|{
return|return
name|vsetq_lane_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vsetq_lane_s8
end_comment

begin_comment
comment|// CHECK: vmov
end_comment

begin_function
name|int8x16_t
name|test_vsetq_lane_s8
parameter_list|(
name|int8_t
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|)
block|{
return|return
name|vsetq_lane_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|15
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vsetq_lane_s16
end_comment

begin_comment
comment|// CHECK: vmov
end_comment

begin_function
name|int16x8_t
name|test_vsetq_lane_s16
parameter_list|(
name|int16_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
return|return
name|vsetq_lane_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vsetq_lane_s32
end_comment

begin_comment
comment|// CHECK: vmov
end_comment

begin_function
name|int32x4_t
name|test_vsetq_lane_s32
parameter_list|(
name|int32_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
return|return
name|vsetq_lane_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vsetq_lane_p8
end_comment

begin_comment
comment|// CHECK: vmov
end_comment

begin_function
name|poly8x16_t
name|test_vsetq_lane_p8
parameter_list|(
name|poly8_t
name|a
parameter_list|,
name|poly8x16_t
name|b
parameter_list|)
block|{
return|return
name|vsetq_lane_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|15
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vsetq_lane_p16
end_comment

begin_comment
comment|// CHECK: vmov
end_comment

begin_function
name|poly16x8_t
name|test_vsetq_lane_p16
parameter_list|(
name|poly16_t
name|a
parameter_list|,
name|poly16x8_t
name|b
parameter_list|)
block|{
return|return
name|vsetq_lane_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vsetq_lane_f32
end_comment

begin_comment
comment|// CHECK: vmov
end_comment

begin_function
name|float32x4_t
name|test_vsetq_lane_f32
parameter_list|(
name|float32_t
name|a
parameter_list|,
name|float32x4_t
name|b
parameter_list|)
block|{
return|return
name|vsetq_lane_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vset_lane_s64
end_comment

begin_comment
comment|// The optimizer is able to get rid of all moves now.
end_comment

begin_function
name|int64x1_t
name|test_vset_lane_s64
parameter_list|(
name|int64_t
name|a
parameter_list|,
name|int64x1_t
name|b
parameter_list|)
block|{
return|return
name|vset_lane_s64
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

begin_comment
comment|// CHECK-LABEL: test_vset_lane_u64
end_comment

begin_comment
comment|// The optimizer is able to get rid of all moves now.
end_comment

begin_function
name|uint64x1_t
name|test_vset_lane_u64
parameter_list|(
name|uint64_t
name|a
parameter_list|,
name|uint64x1_t
name|b
parameter_list|)
block|{
return|return
name|vset_lane_u64
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

begin_comment
comment|// CHECK-LABEL: test_vsetq_lane_s64
end_comment

begin_comment
comment|// CHECK: vmov
end_comment

begin_function
name|int64x2_t
name|test_vsetq_lane_s64
parameter_list|(
name|int64_t
name|a
parameter_list|,
name|int64x2_t
name|b
parameter_list|)
block|{
return|return
name|vsetq_lane_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vsetq_lane_u64
end_comment

begin_comment
comment|// CHECK: vmov
end_comment

begin_function
name|uint64x2_t
name|test_vsetq_lane_u64
parameter_list|(
name|uint64_t
name|a
parameter_list|,
name|uint64x2_t
name|b
parameter_list|)
block|{
return|return
name|vsetq_lane_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vshl_s8
end_comment

begin_comment
comment|// CHECK: vshl.s8 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int8x8_t
name|test_vshl_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
return|return
name|vshl_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vshl_s16
end_comment

begin_comment
comment|// CHECK: vshl.s16 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int16x4_t
name|test_vshl_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
return|return
name|vshl_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vshl_s32
end_comment

begin_comment
comment|// CHECK: vshl.s32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int32x2_t
name|test_vshl_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
return|return
name|vshl_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vshl_s64
end_comment

begin_comment
comment|// CHECK: vshl.s64 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int64x1_t
name|test_vshl_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|,
name|int64x1_t
name|b
parameter_list|)
block|{
return|return
name|vshl_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vshl_u8
end_comment

begin_comment
comment|// CHECK: vshl.u8 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint8x8_t
name|test_vshl_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
return|return
name|vshl_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vshl_u16
end_comment

begin_comment
comment|// CHECK: vshl.u16 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint16x4_t
name|test_vshl_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
return|return
name|vshl_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vshl_u32
end_comment

begin_comment
comment|// CHECK: vshl.u32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint32x2_t
name|test_vshl_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
return|return
name|vshl_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vshl_u64
end_comment

begin_comment
comment|// CHECK: vshl.u64 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint64x1_t
name|test_vshl_u64
parameter_list|(
name|uint64x1_t
name|a
parameter_list|,
name|int64x1_t
name|b
parameter_list|)
block|{
return|return
name|vshl_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vshlq_s8
end_comment

begin_comment
comment|// CHECK: vshl.s8 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int8x16_t
name|test_vshlq_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|)
block|{
return|return
name|vshlq_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vshlq_s16
end_comment

begin_comment
comment|// CHECK: vshl.s16 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int16x8_t
name|test_vshlq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
return|return
name|vshlq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vshlq_s32
end_comment

begin_comment
comment|// CHECK: vshl.s32 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int32x4_t
name|test_vshlq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
return|return
name|vshlq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vshlq_s64
end_comment

begin_comment
comment|// CHECK: vshl.s64 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int64x2_t
name|test_vshlq_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int64x2_t
name|b
parameter_list|)
block|{
return|return
name|vshlq_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vshlq_u8
end_comment

begin_comment
comment|// CHECK: vshl.u8 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint8x16_t
name|test_vshlq_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|)
block|{
return|return
name|vshlq_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vshlq_u16
end_comment

begin_comment
comment|// CHECK: vshl.u16 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint16x8_t
name|test_vshlq_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
return|return
name|vshlq_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vshlq_u32
end_comment

begin_comment
comment|// CHECK: vshl.u32 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint32x4_t
name|test_vshlq_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
return|return
name|vshlq_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vshlq_u64
end_comment

begin_comment
comment|// CHECK: vshl.u64 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint64x2_t
name|test_vshlq_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|,
name|int64x2_t
name|b
parameter_list|)
block|{
return|return
name|vshlq_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vshll_n_s8
end_comment

begin_comment
comment|// CHECK: vshll.s8 q{{[0-9]+}}, d{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|int16x8_t
name|test_vshll_n_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
return|return
name|vshll_n_s8
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vshll_n_s16
end_comment

begin_comment
comment|// CHECK: vshll.s16 q{{[0-9]+}}, d{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|int32x4_t
name|test_vshll_n_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|)
block|{
return|return
name|vshll_n_s16
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vshll_n_s32
end_comment

begin_comment
comment|// CHECK: vshll.s32 q{{[0-9]+}}, d{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|int64x2_t
name|test_vshll_n_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|)
block|{
return|return
name|vshll_n_s32
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vshll_n_u8
end_comment

begin_comment
comment|// CHECK: vshll.u8 q{{[0-9]+}}, d{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|uint16x8_t
name|test_vshll_n_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|)
block|{
return|return
name|vshll_n_u8
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vshll_n_u16
end_comment

begin_comment
comment|// CHECK: vshll.u16 q{{[0-9]+}}, d{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|uint32x4_t
name|test_vshll_n_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|)
block|{
return|return
name|vshll_n_u16
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vshll_n_u32
end_comment

begin_comment
comment|// CHECK: vshll.u32 q{{[0-9]+}}, d{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|uint64x2_t
name|test_vshll_n_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|)
block|{
return|return
name|vshll_n_u32
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vshl_n_s8
end_comment

begin_comment
comment|// CHECK: vshl.i8 d{{[0-9]+}}, d{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|int8x8_t
name|test_vshl_n_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
return|return
name|vshl_n_s8
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vshl_n_s16
end_comment

begin_comment
comment|// CHECK: vshl.i16 d{{[0-9]+}}, d{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|int16x4_t
name|test_vshl_n_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|)
block|{
return|return
name|vshl_n_s16
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vshl_n_s32
end_comment

begin_comment
comment|// CHECK: vshl.i32 d{{[0-9]+}}, d{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|int32x2_t
name|test_vshl_n_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|)
block|{
return|return
name|vshl_n_s32
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vshl_n_s64
end_comment

begin_comment
comment|// CHECK: vshl.i64 d{{[0-9]+}}, d{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|int64x1_t
name|test_vshl_n_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|)
block|{
return|return
name|vshl_n_s64
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vshl_n_u8
end_comment

begin_comment
comment|// CHECK: vshl.i8 d{{[0-9]+}}, d{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|uint8x8_t
name|test_vshl_n_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|)
block|{
return|return
name|vshl_n_u8
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vshl_n_u16
end_comment

begin_comment
comment|// CHECK: vshl.i16 d{{[0-9]+}}, d{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|uint16x4_t
name|test_vshl_n_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|)
block|{
return|return
name|vshl_n_u16
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vshl_n_u32
end_comment

begin_comment
comment|// CHECK: vshl.i32 d{{[0-9]+}}, d{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|uint32x2_t
name|test_vshl_n_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|)
block|{
return|return
name|vshl_n_u32
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vshl_n_u64
end_comment

begin_comment
comment|// CHECK: vshl.i64 d{{[0-9]+}}, d{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|uint64x1_t
name|test_vshl_n_u64
parameter_list|(
name|uint64x1_t
name|a
parameter_list|)
block|{
return|return
name|vshl_n_u64
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vshlq_n_s8
end_comment

begin_comment
comment|// CHECK: vshl.i8 q{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|int8x16_t
name|test_vshlq_n_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
return|return
name|vshlq_n_s8
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vshlq_n_s16
end_comment

begin_comment
comment|// CHECK: vshl.i16 q{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|int16x8_t
name|test_vshlq_n_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
return|return
name|vshlq_n_s16
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vshlq_n_s32
end_comment

begin_comment
comment|// CHECK: vshl.i32 q{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|int32x4_t
name|test_vshlq_n_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
return|return
name|vshlq_n_s32
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vshlq_n_s64
end_comment

begin_comment
comment|// CHECK: vshl.i64 q{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|int64x2_t
name|test_vshlq_n_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|)
block|{
return|return
name|vshlq_n_s64
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vshlq_n_u8
end_comment

begin_comment
comment|// CHECK: vshl.i8 q{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|uint8x16_t
name|test_vshlq_n_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|)
block|{
return|return
name|vshlq_n_u8
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vshlq_n_u16
end_comment

begin_comment
comment|// CHECK: vshl.i16 q{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|uint16x8_t
name|test_vshlq_n_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|)
block|{
return|return
name|vshlq_n_u16
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vshlq_n_u32
end_comment

begin_comment
comment|// CHECK: vshl.i32 q{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|uint32x4_t
name|test_vshlq_n_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|)
block|{
return|return
name|vshlq_n_u32
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vshlq_n_u64
end_comment

begin_comment
comment|// CHECK: vshl.i64 q{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|uint64x2_t
name|test_vshlq_n_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|)
block|{
return|return
name|vshlq_n_u64
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vshrn_n_s16
end_comment

begin_comment
comment|// CHECK: vshrn.i16 d{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|int8x8_t
name|test_vshrn_n_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
return|return
name|vshrn_n_s16
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vshrn_n_s32
end_comment

begin_comment
comment|// CHECK: vshrn.i32 d{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|int16x4_t
name|test_vshrn_n_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
return|return
name|vshrn_n_s32
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vshrn_n_s64
end_comment

begin_comment
comment|// CHECK: vshrn.i64 d{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|int32x2_t
name|test_vshrn_n_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|)
block|{
return|return
name|vshrn_n_s64
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vshrn_n_u16
end_comment

begin_comment
comment|// CHECK: vshrn.i16 d{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|uint8x8_t
name|test_vshrn_n_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|)
block|{
return|return
name|vshrn_n_u16
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vshrn_n_u32
end_comment

begin_comment
comment|// CHECK: vshrn.i32 d{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|uint16x4_t
name|test_vshrn_n_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|)
block|{
return|return
name|vshrn_n_u32
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vshrn_n_u64
end_comment

begin_comment
comment|// CHECK: vshrn.i64 d{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|uint32x2_t
name|test_vshrn_n_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|)
block|{
return|return
name|vshrn_n_u64
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vshr_n_s8
end_comment

begin_comment
comment|// CHECK: vshr.s8 d{{[0-9]+}}, d{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|int8x8_t
name|test_vshr_n_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
return|return
name|vshr_n_s8
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vshr_n_s16
end_comment

begin_comment
comment|// CHECK: vshr.s16 d{{[0-9]+}}, d{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|int16x4_t
name|test_vshr_n_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|)
block|{
return|return
name|vshr_n_s16
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vshr_n_s32
end_comment

begin_comment
comment|// CHECK: vshr.s32 d{{[0-9]+}}, d{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|int32x2_t
name|test_vshr_n_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|)
block|{
return|return
name|vshr_n_s32
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vshr_n_s64
end_comment

begin_comment
comment|// CHECK: vshr.s64 d{{[0-9]+}}, d{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|int64x1_t
name|test_vshr_n_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|)
block|{
return|return
name|vshr_n_s64
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vshr_n_u8
end_comment

begin_comment
comment|// CHECK: vshr.u8 d{{[0-9]+}}, d{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|uint8x8_t
name|test_vshr_n_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|)
block|{
return|return
name|vshr_n_u8
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vshr_n_u16
end_comment

begin_comment
comment|// CHECK: vshr.u16 d{{[0-9]+}}, d{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|uint16x4_t
name|test_vshr_n_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|)
block|{
return|return
name|vshr_n_u16
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vshr_n_u32
end_comment

begin_comment
comment|// CHECK: vshr.u32 d{{[0-9]+}}, d{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|uint32x2_t
name|test_vshr_n_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|)
block|{
return|return
name|vshr_n_u32
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vshr_n_u64
end_comment

begin_comment
comment|// CHECK: vshr.u64 d{{[0-9]+}}, d{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|uint64x1_t
name|test_vshr_n_u64
parameter_list|(
name|uint64x1_t
name|a
parameter_list|)
block|{
return|return
name|vshr_n_u64
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vshrq_n_s8
end_comment

begin_comment
comment|// CHECK: vshr.s8 q{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|int8x16_t
name|test_vshrq_n_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
return|return
name|vshrq_n_s8
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vshrq_n_s16
end_comment

begin_comment
comment|// CHECK: vshr.s16 q{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|int16x8_t
name|test_vshrq_n_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
return|return
name|vshrq_n_s16
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vshrq_n_s32
end_comment

begin_comment
comment|// CHECK: vshr.s32 q{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|int32x4_t
name|test_vshrq_n_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
return|return
name|vshrq_n_s32
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vshrq_n_s64
end_comment

begin_comment
comment|// CHECK: vshr.s64 q{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|int64x2_t
name|test_vshrq_n_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|)
block|{
return|return
name|vshrq_n_s64
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vshrq_n_u8
end_comment

begin_comment
comment|// CHECK: vshr.u8 q{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|uint8x16_t
name|test_vshrq_n_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|)
block|{
return|return
name|vshrq_n_u8
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vshrq_n_u16
end_comment

begin_comment
comment|// CHECK: vshr.u16 q{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|uint16x8_t
name|test_vshrq_n_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|)
block|{
return|return
name|vshrq_n_u16
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vshrq_n_u32
end_comment

begin_comment
comment|// CHECK: vshr.u32 q{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|uint32x4_t
name|test_vshrq_n_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|)
block|{
return|return
name|vshrq_n_u32
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vshrq_n_u64
end_comment

begin_comment
comment|// CHECK: vshr.u64 q{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|uint64x2_t
name|test_vshrq_n_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|)
block|{
return|return
name|vshrq_n_u64
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vsli_n_s8
end_comment

begin_comment
comment|// CHECK: vsli.8 d{{[0-9]+}}, d{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|int8x8_t
name|test_vsli_n_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
return|return
name|vsli_n_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vsli_n_s16
end_comment

begin_comment
comment|// CHECK: vsli.16 d{{[0-9]+}}, d{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|int16x4_t
name|test_vsli_n_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
return|return
name|vsli_n_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vsli_n_s32
end_comment

begin_comment
comment|// CHECK: vsli.32 d{{[0-9]+}}, d{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|int32x2_t
name|test_vsli_n_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
return|return
name|vsli_n_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vsli_n_s64
end_comment

begin_comment
comment|// CHECK: vsli.64 d{{[0-9]+}}, d{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|int64x1_t
name|test_vsli_n_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|,
name|int64x1_t
name|b
parameter_list|)
block|{
return|return
name|vsli_n_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vsli_n_u8
end_comment

begin_comment
comment|// CHECK: vsli.8 d{{[0-9]+}}, d{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|uint8x8_t
name|test_vsli_n_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|)
block|{
return|return
name|vsli_n_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vsli_n_u16
end_comment

begin_comment
comment|// CHECK: vsli.16 d{{[0-9]+}}, d{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|uint16x4_t
name|test_vsli_n_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|)
block|{
return|return
name|vsli_n_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vsli_n_u32
end_comment

begin_comment
comment|// CHECK: vsli.32 d{{[0-9]+}}, d{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|uint32x2_t
name|test_vsli_n_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|)
block|{
return|return
name|vsli_n_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vsli_n_u64
end_comment

begin_comment
comment|// CHECK: vsli.64 d{{[0-9]+}}, d{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|uint64x1_t
name|test_vsli_n_u64
parameter_list|(
name|uint64x1_t
name|a
parameter_list|,
name|uint64x1_t
name|b
parameter_list|)
block|{
return|return
name|vsli_n_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vsli_n_p8
end_comment

begin_comment
comment|// CHECK: vsli.8 d{{[0-9]+}}, d{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|poly8x8_t
name|test_vsli_n_p8
parameter_list|(
name|poly8x8_t
name|a
parameter_list|,
name|poly8x8_t
name|b
parameter_list|)
block|{
return|return
name|vsli_n_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vsli_n_p16
end_comment

begin_comment
comment|// CHECK: vsli.16 d{{[0-9]+}}, d{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|poly16x4_t
name|test_vsli_n_p16
parameter_list|(
name|poly16x4_t
name|a
parameter_list|,
name|poly16x4_t
name|b
parameter_list|)
block|{
return|return
name|vsli_n_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vsliq_n_s8
end_comment

begin_comment
comment|// CHECK: vsli.8 q{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|int8x16_t
name|test_vsliq_n_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|)
block|{
return|return
name|vsliq_n_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vsliq_n_s16
end_comment

begin_comment
comment|// CHECK: vsli.16 q{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|int16x8_t
name|test_vsliq_n_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
return|return
name|vsliq_n_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vsliq_n_s32
end_comment

begin_comment
comment|// CHECK: vsli.32 q{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|int32x4_t
name|test_vsliq_n_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
return|return
name|vsliq_n_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vsliq_n_s64
end_comment

begin_comment
comment|// CHECK: vsli.64 q{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|int64x2_t
name|test_vsliq_n_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int64x2_t
name|b
parameter_list|)
block|{
return|return
name|vsliq_n_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vsliq_n_u8
end_comment

begin_comment
comment|// CHECK: vsli.8 q{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|uint8x16_t
name|test_vsliq_n_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|,
name|uint8x16_t
name|b
parameter_list|)
block|{
return|return
name|vsliq_n_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vsliq_n_u16
end_comment

begin_comment
comment|// CHECK: vsli.16 q{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|uint16x8_t
name|test_vsliq_n_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|)
block|{
return|return
name|vsliq_n_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vsliq_n_u32
end_comment

begin_comment
comment|// CHECK: vsli.32 q{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|uint32x4_t
name|test_vsliq_n_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|)
block|{
return|return
name|vsliq_n_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vsliq_n_u64
end_comment

begin_comment
comment|// CHECK: vsli.64 q{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|uint64x2_t
name|test_vsliq_n_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|,
name|uint64x2_t
name|b
parameter_list|)
block|{
return|return
name|vsliq_n_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vsliq_n_p8
end_comment

begin_comment
comment|// CHECK: vsli.8 q{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|poly8x16_t
name|test_vsliq_n_p8
parameter_list|(
name|poly8x16_t
name|a
parameter_list|,
name|poly8x16_t
name|b
parameter_list|)
block|{
return|return
name|vsliq_n_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vsliq_n_p16
end_comment

begin_comment
comment|// CHECK: vsli.16 q{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|poly16x8_t
name|test_vsliq_n_p16
parameter_list|(
name|poly16x8_t
name|a
parameter_list|,
name|poly16x8_t
name|b
parameter_list|)
block|{
return|return
name|vsliq_n_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vsra_n_s8
end_comment

begin_comment
comment|// CHECK: vsra.s8 d{{[0-9]+}}, d{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|int8x8_t
name|test_vsra_n_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
return|return
name|vsra_n_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vsra_n_s16
end_comment

begin_comment
comment|// CHECK: vsra.s16 d{{[0-9]+}}, d{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|int16x4_t
name|test_vsra_n_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
return|return
name|vsra_n_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vsra_n_s32
end_comment

begin_comment
comment|// CHECK: vsra.s32 d{{[0-9]+}}, d{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|int32x2_t
name|test_vsra_n_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
return|return
name|vsra_n_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vsra_n_s64
end_comment

begin_comment
comment|// CHECK: vsra.s64 d{{[0-9]+}}, d{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|int64x1_t
name|test_vsra_n_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|,
name|int64x1_t
name|b
parameter_list|)
block|{
return|return
name|vsra_n_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vsra_n_u8
end_comment

begin_comment
comment|// CHECK: vsra.u8 d{{[0-9]+}}, d{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|uint8x8_t
name|test_vsra_n_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|)
block|{
return|return
name|vsra_n_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vsra_n_u16
end_comment

begin_comment
comment|// CHECK: vsra.u16 d{{[0-9]+}}, d{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|uint16x4_t
name|test_vsra_n_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|)
block|{
return|return
name|vsra_n_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vsra_n_u32
end_comment

begin_comment
comment|// CHECK: vsra.u32 d{{[0-9]+}}, d{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|uint32x2_t
name|test_vsra_n_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|)
block|{
return|return
name|vsra_n_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vsra_n_u64
end_comment

begin_comment
comment|// CHECK: vsra.u64 d{{[0-9]+}}, d{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|uint64x1_t
name|test_vsra_n_u64
parameter_list|(
name|uint64x1_t
name|a
parameter_list|,
name|uint64x1_t
name|b
parameter_list|)
block|{
return|return
name|vsra_n_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vsraq_n_s8
end_comment

begin_comment
comment|// CHECK: vsra.s8 q{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|int8x16_t
name|test_vsraq_n_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|)
block|{
return|return
name|vsraq_n_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vsraq_n_s16
end_comment

begin_comment
comment|// CHECK: vsra.s16 q{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|int16x8_t
name|test_vsraq_n_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
return|return
name|vsraq_n_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vsraq_n_s32
end_comment

begin_comment
comment|// CHECK: vsra.s32 q{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|int32x4_t
name|test_vsraq_n_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
return|return
name|vsraq_n_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vsraq_n_s64
end_comment

begin_comment
comment|// CHECK: vsra.s64 q{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|int64x2_t
name|test_vsraq_n_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int64x2_t
name|b
parameter_list|)
block|{
return|return
name|vsraq_n_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vsraq_n_u8
end_comment

begin_comment
comment|// CHECK: vsra.u8 q{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|uint8x16_t
name|test_vsraq_n_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|,
name|uint8x16_t
name|b
parameter_list|)
block|{
return|return
name|vsraq_n_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vsraq_n_u16
end_comment

begin_comment
comment|// CHECK: vsra.u16 q{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|uint16x8_t
name|test_vsraq_n_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|)
block|{
return|return
name|vsraq_n_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vsraq_n_u32
end_comment

begin_comment
comment|// CHECK: vsra.u32 q{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|uint32x4_t
name|test_vsraq_n_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|)
block|{
return|return
name|vsraq_n_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vsraq_n_u64
end_comment

begin_comment
comment|// CHECK: vsra.u64 q{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|uint64x2_t
name|test_vsraq_n_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|,
name|uint64x2_t
name|b
parameter_list|)
block|{
return|return
name|vsraq_n_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vsri_n_s8
end_comment

begin_comment
comment|// CHECK: vsri.8 d{{[0-9]+}}, d{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|int8x8_t
name|test_vsri_n_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
return|return
name|vsri_n_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vsri_n_s16
end_comment

begin_comment
comment|// CHECK: vsri.16 d{{[0-9]+}}, d{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|int16x4_t
name|test_vsri_n_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
return|return
name|vsri_n_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vsri_n_s32
end_comment

begin_comment
comment|// CHECK: vsri.32 d{{[0-9]+}}, d{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|int32x2_t
name|test_vsri_n_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
return|return
name|vsri_n_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vsri_n_s64
end_comment

begin_comment
comment|// CHECK: vsri.64 d{{[0-9]+}}, d{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|int64x1_t
name|test_vsri_n_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|,
name|int64x1_t
name|b
parameter_list|)
block|{
return|return
name|vsri_n_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vsri_n_u8
end_comment

begin_comment
comment|// CHECK: vsri.8 d{{[0-9]+}}, d{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|uint8x8_t
name|test_vsri_n_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|)
block|{
return|return
name|vsri_n_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vsri_n_u16
end_comment

begin_comment
comment|// CHECK: vsri.16 d{{[0-9]+}}, d{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|uint16x4_t
name|test_vsri_n_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|)
block|{
return|return
name|vsri_n_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vsri_n_u32
end_comment

begin_comment
comment|// CHECK: vsri.32 d{{[0-9]+}}, d{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|uint32x2_t
name|test_vsri_n_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|)
block|{
return|return
name|vsri_n_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vsri_n_u64
end_comment

begin_comment
comment|// CHECK: vsri.64 d{{[0-9]+}}, d{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|uint64x1_t
name|test_vsri_n_u64
parameter_list|(
name|uint64x1_t
name|a
parameter_list|,
name|uint64x1_t
name|b
parameter_list|)
block|{
return|return
name|vsri_n_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vsri_n_p8
end_comment

begin_comment
comment|// CHECK: vsri.8 d{{[0-9]+}}, d{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|poly8x8_t
name|test_vsri_n_p8
parameter_list|(
name|poly8x8_t
name|a
parameter_list|,
name|poly8x8_t
name|b
parameter_list|)
block|{
return|return
name|vsri_n_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vsri_n_p16
end_comment

begin_comment
comment|// CHECK: vsri.16 d{{[0-9]+}}, d{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|poly16x4_t
name|test_vsri_n_p16
parameter_list|(
name|poly16x4_t
name|a
parameter_list|,
name|poly16x4_t
name|b
parameter_list|)
block|{
return|return
name|vsri_n_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vsriq_n_s8
end_comment

begin_comment
comment|// CHECK: vsri.8 q{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|int8x16_t
name|test_vsriq_n_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|)
block|{
return|return
name|vsriq_n_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vsriq_n_s16
end_comment

begin_comment
comment|// CHECK: vsri.16 q{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|int16x8_t
name|test_vsriq_n_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
return|return
name|vsriq_n_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vsriq_n_s32
end_comment

begin_comment
comment|// CHECK: vsri.32 q{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|int32x4_t
name|test_vsriq_n_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
return|return
name|vsriq_n_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vsriq_n_s64
end_comment

begin_comment
comment|// CHECK: vsri.64 q{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|int64x2_t
name|test_vsriq_n_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int64x2_t
name|b
parameter_list|)
block|{
return|return
name|vsriq_n_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vsriq_n_u8
end_comment

begin_comment
comment|// CHECK: vsri.8 q{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|uint8x16_t
name|test_vsriq_n_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|,
name|uint8x16_t
name|b
parameter_list|)
block|{
return|return
name|vsriq_n_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vsriq_n_u16
end_comment

begin_comment
comment|// CHECK: vsri.16 q{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|uint16x8_t
name|test_vsriq_n_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|)
block|{
return|return
name|vsriq_n_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vsriq_n_u32
end_comment

begin_comment
comment|// CHECK: vsri.32 q{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|uint32x4_t
name|test_vsriq_n_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|)
block|{
return|return
name|vsriq_n_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vsriq_n_u64
end_comment

begin_comment
comment|// CHECK: vsri.64 q{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|uint64x2_t
name|test_vsriq_n_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|,
name|uint64x2_t
name|b
parameter_list|)
block|{
return|return
name|vsriq_n_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vsriq_n_p8
end_comment

begin_comment
comment|// CHECK: vsri.8 q{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|poly8x16_t
name|test_vsriq_n_p8
parameter_list|(
name|poly8x16_t
name|a
parameter_list|,
name|poly8x16_t
name|b
parameter_list|)
block|{
return|return
name|vsriq_n_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vsriq_n_p16
end_comment

begin_comment
comment|// CHECK: vsri.16 q{{[0-9]+}}, q{{[0-9]+}}, #{{[0-9]+}}
end_comment

begin_function
name|poly16x8_t
name|test_vsriq_n_p16
parameter_list|(
name|poly16x8_t
name|a
parameter_list|,
name|poly16x8_t
name|b
parameter_list|)
block|{
return|return
name|vsriq_n_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst1q_u8
end_comment

begin_comment
comment|// CHECK: vst1.8 {d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst1q_u8
parameter_list|(
name|uint8_t
modifier|*
name|a
parameter_list|,
name|uint8x16_t
name|b
parameter_list|)
block|{
name|vst1q_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst1q_u16
end_comment

begin_comment
comment|// CHECK: vst1.16 {d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst1q_u16
parameter_list|(
name|uint16_t
modifier|*
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|)
block|{
name|vst1q_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst1q_u32
end_comment

begin_comment
comment|// CHECK: vst1.32 {d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst1q_u32
parameter_list|(
name|uint32_t
modifier|*
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|)
block|{
name|vst1q_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst1q_u64
end_comment

begin_comment
comment|// CHECK: vst1.64 {d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}{{(:64)?}}]
end_comment

begin_function
name|void
name|test_vst1q_u64
parameter_list|(
name|uint64_t
modifier|*
name|a
parameter_list|,
name|uint64x2_t
name|b
parameter_list|)
block|{
name|vst1q_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst1q_s8
end_comment

begin_comment
comment|// CHECK: vst1.8 {d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst1q_s8
parameter_list|(
name|int8_t
modifier|*
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|)
block|{
name|vst1q_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst1q_s16
end_comment

begin_comment
comment|// CHECK: vst1.16 {d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst1q_s16
parameter_list|(
name|int16_t
modifier|*
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
name|vst1q_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst1q_s32
end_comment

begin_comment
comment|// CHECK: vst1.32 {d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst1q_s32
parameter_list|(
name|int32_t
modifier|*
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
name|vst1q_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst1q_s64
end_comment

begin_comment
comment|// CHECK: vst1.64 {d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}{{(:64)?}}]
end_comment

begin_function
name|void
name|test_vst1q_s64
parameter_list|(
name|int64_t
modifier|*
name|a
parameter_list|,
name|int64x2_t
name|b
parameter_list|)
block|{
name|vst1q_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst1q_f16
end_comment

begin_comment
comment|// CHECK: vst1.16 {d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst1q_f16
parameter_list|(
name|float16_t
modifier|*
name|a
parameter_list|,
name|float16x8_t
name|b
parameter_list|)
block|{
name|vst1q_f16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst1q_f32
end_comment

begin_comment
comment|// CHECK: vst1.32 {d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst1q_f32
parameter_list|(
name|float32_t
modifier|*
name|a
parameter_list|,
name|float32x4_t
name|b
parameter_list|)
block|{
name|vst1q_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst1q_p8
end_comment

begin_comment
comment|// CHECK: vst1.8 {d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst1q_p8
parameter_list|(
name|poly8_t
modifier|*
name|a
parameter_list|,
name|poly8x16_t
name|b
parameter_list|)
block|{
name|vst1q_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst1q_p16
end_comment

begin_comment
comment|// CHECK: vst1.16 {d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst1q_p16
parameter_list|(
name|poly16_t
modifier|*
name|a
parameter_list|,
name|poly16x8_t
name|b
parameter_list|)
block|{
name|vst1q_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst1_u8
end_comment

begin_comment
comment|// CHECK: vst1.8 {d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst1_u8
parameter_list|(
name|uint8_t
modifier|*
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|)
block|{
name|vst1_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst1_u16
end_comment

begin_comment
comment|// CHECK: vst1.16 {d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst1_u16
parameter_list|(
name|uint16_t
modifier|*
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|)
block|{
name|vst1_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst1_u32
end_comment

begin_comment
comment|// CHECK: vst1.32 {d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst1_u32
parameter_list|(
name|uint32_t
modifier|*
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|)
block|{
name|vst1_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst1_u64
end_comment

begin_comment
comment|// CHECK: vst1.64 {d{{[0-9]+}}}, [r{{[0-9]+}}{{(:64)?}}]
end_comment

begin_function
name|void
name|test_vst1_u64
parameter_list|(
name|uint64_t
modifier|*
name|a
parameter_list|,
name|uint64x1_t
name|b
parameter_list|)
block|{
name|vst1_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst1_s8
end_comment

begin_comment
comment|// CHECK: vst1.8 {d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst1_s8
parameter_list|(
name|int8_t
modifier|*
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
name|vst1_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst1_s16
end_comment

begin_comment
comment|// CHECK: vst1.16 {d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst1_s16
parameter_list|(
name|int16_t
modifier|*
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
name|vst1_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst1_s32
end_comment

begin_comment
comment|// CHECK: vst1.32 {d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst1_s32
parameter_list|(
name|int32_t
modifier|*
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
name|vst1_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst1_s64
end_comment

begin_comment
comment|// CHECK: vst1.64 {d{{[0-9]+}}}, [r{{[0-9]+}}{{(:64)?}}]
end_comment

begin_function
name|void
name|test_vst1_s64
parameter_list|(
name|int64_t
modifier|*
name|a
parameter_list|,
name|int64x1_t
name|b
parameter_list|)
block|{
name|vst1_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst1_f16
end_comment

begin_comment
comment|// CHECK: vst1.16 {d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst1_f16
parameter_list|(
name|float16_t
modifier|*
name|a
parameter_list|,
name|float16x4_t
name|b
parameter_list|)
block|{
name|vst1_f16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst1_f32
end_comment

begin_comment
comment|// CHECK: vst1.32 {d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst1_f32
parameter_list|(
name|float32_t
modifier|*
name|a
parameter_list|,
name|float32x2_t
name|b
parameter_list|)
block|{
name|vst1_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst1_p8
end_comment

begin_comment
comment|// CHECK: vst1.8 {d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst1_p8
parameter_list|(
name|poly8_t
modifier|*
name|a
parameter_list|,
name|poly8x8_t
name|b
parameter_list|)
block|{
name|vst1_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst1_p16
end_comment

begin_comment
comment|// CHECK: vst1.16 {d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst1_p16
parameter_list|(
name|poly16_t
modifier|*
name|a
parameter_list|,
name|poly16x4_t
name|b
parameter_list|)
block|{
name|vst1_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst1q_lane_u8
end_comment

begin_comment
comment|// CHECK: vst1.8 {d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst1q_lane_u8
parameter_list|(
name|uint8_t
modifier|*
name|a
parameter_list|,
name|uint8x16_t
name|b
parameter_list|)
block|{
name|vst1q_lane_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|15
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst1q_lane_u16
end_comment

begin_comment
comment|// CHECK: vst1.16 {d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}:16]
end_comment

begin_function
name|void
name|test_vst1q_lane_u16
parameter_list|(
name|uint16_t
modifier|*
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|)
block|{
name|vst1q_lane_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst1q_lane_u32
end_comment

begin_comment
comment|// CHECK: vst1.32 {d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}:32]
end_comment

begin_function
name|void
name|test_vst1q_lane_u32
parameter_list|(
name|uint32_t
modifier|*
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|)
block|{
name|vst1q_lane_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst1q_lane_u64
end_comment

begin_comment
comment|// CHECK: {{str|vstr|vmov}}
end_comment

begin_function
name|void
name|test_vst1q_lane_u64
parameter_list|(
name|uint64_t
modifier|*
name|a
parameter_list|,
name|uint64x2_t
name|b
parameter_list|)
block|{
name|vst1q_lane_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst1q_lane_s8
end_comment

begin_comment
comment|// CHECK: vst1.8 {d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst1q_lane_s8
parameter_list|(
name|int8_t
modifier|*
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|)
block|{
name|vst1q_lane_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|15
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst1q_lane_s16
end_comment

begin_comment
comment|// CHECK: vst1.16 {d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}:16]
end_comment

begin_function
name|void
name|test_vst1q_lane_s16
parameter_list|(
name|int16_t
modifier|*
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
name|vst1q_lane_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst1q_lane_s32
end_comment

begin_comment
comment|// CHECK: vst1.32 {d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}:32]
end_comment

begin_function
name|void
name|test_vst1q_lane_s32
parameter_list|(
name|int32_t
modifier|*
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
name|vst1q_lane_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst1q_lane_s64
end_comment

begin_comment
comment|// CHECK: {{str|vstr|vmov}}
end_comment

begin_function
name|void
name|test_vst1q_lane_s64
parameter_list|(
name|int64_t
modifier|*
name|a
parameter_list|,
name|int64x2_t
name|b
parameter_list|)
block|{
name|vst1q_lane_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst1q_lane_f16
end_comment

begin_comment
comment|// CHECK: vst1.16 {d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}:16]
end_comment

begin_function
name|void
name|test_vst1q_lane_f16
parameter_list|(
name|float16_t
modifier|*
name|a
parameter_list|,
name|float16x8_t
name|b
parameter_list|)
block|{
name|vst1q_lane_f16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst1q_lane_f32
end_comment

begin_comment
comment|// CHECK: vst1.32 {d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}:32]
end_comment

begin_function
name|void
name|test_vst1q_lane_f32
parameter_list|(
name|float32_t
modifier|*
name|a
parameter_list|,
name|float32x4_t
name|b
parameter_list|)
block|{
name|vst1q_lane_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst1q_lane_p8
end_comment

begin_comment
comment|// CHECK: vst1.8 {d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst1q_lane_p8
parameter_list|(
name|poly8_t
modifier|*
name|a
parameter_list|,
name|poly8x16_t
name|b
parameter_list|)
block|{
name|vst1q_lane_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|15
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst1q_lane_p16
end_comment

begin_comment
comment|// CHECK: vst1.16 {d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}:16]
end_comment

begin_function
name|void
name|test_vst1q_lane_p16
parameter_list|(
name|poly16_t
modifier|*
name|a
parameter_list|,
name|poly16x8_t
name|b
parameter_list|)
block|{
name|vst1q_lane_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst1_lane_u8
end_comment

begin_comment
comment|// CHECK: vst1.8 {d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst1_lane_u8
parameter_list|(
name|uint8_t
modifier|*
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|)
block|{
name|vst1_lane_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst1_lane_u16
end_comment

begin_comment
comment|// CHECK: vst1.16 {d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}:16]
end_comment

begin_function
name|void
name|test_vst1_lane_u16
parameter_list|(
name|uint16_t
modifier|*
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|)
block|{
name|vst1_lane_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst1_lane_u32
end_comment

begin_comment
comment|// CHECK: vst1.32 {d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}:32]
end_comment

begin_function
name|void
name|test_vst1_lane_u32
parameter_list|(
name|uint32_t
modifier|*
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|)
block|{
name|vst1_lane_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst1_lane_u64
end_comment

begin_comment
comment|// CHECK: {{str|vstr|vmov}}
end_comment

begin_function
name|void
name|test_vst1_lane_u64
parameter_list|(
name|uint64_t
modifier|*
name|a
parameter_list|,
name|uint64x1_t
name|b
parameter_list|)
block|{
name|vst1_lane_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst1_lane_s8
end_comment

begin_comment
comment|// CHECK: vst1.8 {d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst1_lane_s8
parameter_list|(
name|int8_t
modifier|*
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
name|vst1_lane_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst1_lane_s16
end_comment

begin_comment
comment|// CHECK: vst1.16 {d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}:16]
end_comment

begin_function
name|void
name|test_vst1_lane_s16
parameter_list|(
name|int16_t
modifier|*
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
name|vst1_lane_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst1_lane_s32
end_comment

begin_comment
comment|// CHECK: vst1.32 {d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}:32]
end_comment

begin_function
name|void
name|test_vst1_lane_s32
parameter_list|(
name|int32_t
modifier|*
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
name|vst1_lane_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst1_lane_s64
end_comment

begin_comment
comment|// CHECK: {{str|vstr|vmov}}
end_comment

begin_function
name|void
name|test_vst1_lane_s64
parameter_list|(
name|int64_t
modifier|*
name|a
parameter_list|,
name|int64x1_t
name|b
parameter_list|)
block|{
name|vst1_lane_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst1_lane_f16
end_comment

begin_comment
comment|// CHECK: vst1.16 {d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}:16]
end_comment

begin_function
name|void
name|test_vst1_lane_f16
parameter_list|(
name|float16_t
modifier|*
name|a
parameter_list|,
name|float16x4_t
name|b
parameter_list|)
block|{
name|vst1_lane_f16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst1_lane_f32
end_comment

begin_comment
comment|// CHECK: vst1.32 {d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}:32]
end_comment

begin_function
name|void
name|test_vst1_lane_f32
parameter_list|(
name|float32_t
modifier|*
name|a
parameter_list|,
name|float32x2_t
name|b
parameter_list|)
block|{
name|vst1_lane_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst1_lane_p8
end_comment

begin_comment
comment|// CHECK: vst1.8 {d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst1_lane_p8
parameter_list|(
name|poly8_t
modifier|*
name|a
parameter_list|,
name|poly8x8_t
name|b
parameter_list|)
block|{
name|vst1_lane_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst1_lane_p16
end_comment

begin_comment
comment|// CHECK: vst1.16 {d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}:16]
end_comment

begin_function
name|void
name|test_vst1_lane_p16
parameter_list|(
name|poly16_t
modifier|*
name|a
parameter_list|,
name|poly16x4_t
name|b
parameter_list|)
block|{
name|vst1_lane_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst2q_u8
end_comment

begin_comment
comment|// CHECK: vst2.8 {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst2q_u8
parameter_list|(
name|uint8_t
modifier|*
name|a
parameter_list|,
name|uint8x16x2_t
name|b
parameter_list|)
block|{
name|vst2q_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst2q_u16
end_comment

begin_comment
comment|// CHECK: vst2.16 {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst2q_u16
parameter_list|(
name|uint16_t
modifier|*
name|a
parameter_list|,
name|uint16x8x2_t
name|b
parameter_list|)
block|{
name|vst2q_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst2q_u32
end_comment

begin_comment
comment|// CHECK: vst2.32 {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst2q_u32
parameter_list|(
name|uint32_t
modifier|*
name|a
parameter_list|,
name|uint32x4x2_t
name|b
parameter_list|)
block|{
name|vst2q_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst2q_s8
end_comment

begin_comment
comment|// CHECK: vst2.8 {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst2q_s8
parameter_list|(
name|int8_t
modifier|*
name|a
parameter_list|,
name|int8x16x2_t
name|b
parameter_list|)
block|{
name|vst2q_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst2q_s16
end_comment

begin_comment
comment|// CHECK: vst2.16 {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst2q_s16
parameter_list|(
name|int16_t
modifier|*
name|a
parameter_list|,
name|int16x8x2_t
name|b
parameter_list|)
block|{
name|vst2q_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst2q_s32
end_comment

begin_comment
comment|// CHECK: vst2.32 {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst2q_s32
parameter_list|(
name|int32_t
modifier|*
name|a
parameter_list|,
name|int32x4x2_t
name|b
parameter_list|)
block|{
name|vst2q_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst2q_f16
end_comment

begin_comment
comment|// CHECK: vst2.16 {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst2q_f16
parameter_list|(
name|float16_t
modifier|*
name|a
parameter_list|,
name|float16x8x2_t
name|b
parameter_list|)
block|{
name|vst2q_f16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst2q_f32
end_comment

begin_comment
comment|// CHECK: vst2.32 {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst2q_f32
parameter_list|(
name|float32_t
modifier|*
name|a
parameter_list|,
name|float32x4x2_t
name|b
parameter_list|)
block|{
name|vst2q_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst2q_p8
end_comment

begin_comment
comment|// CHECK: vst2.8 {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst2q_p8
parameter_list|(
name|poly8_t
modifier|*
name|a
parameter_list|,
name|poly8x16x2_t
name|b
parameter_list|)
block|{
name|vst2q_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst2q_p16
end_comment

begin_comment
comment|// CHECK: vst2.16 {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst2q_p16
parameter_list|(
name|poly16_t
modifier|*
name|a
parameter_list|,
name|poly16x8x2_t
name|b
parameter_list|)
block|{
name|vst2q_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst2_u8
end_comment

begin_comment
comment|// CHECK: vst2.8 {d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst2_u8
parameter_list|(
name|uint8_t
modifier|*
name|a
parameter_list|,
name|uint8x8x2_t
name|b
parameter_list|)
block|{
name|vst2_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst2_u16
end_comment

begin_comment
comment|// CHECK: vst2.16 {d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst2_u16
parameter_list|(
name|uint16_t
modifier|*
name|a
parameter_list|,
name|uint16x4x2_t
name|b
parameter_list|)
block|{
name|vst2_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst2_u32
end_comment

begin_comment
comment|// CHECK: vst2.32 {d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst2_u32
parameter_list|(
name|uint32_t
modifier|*
name|a
parameter_list|,
name|uint32x2x2_t
name|b
parameter_list|)
block|{
name|vst2_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst2_u64
end_comment

begin_comment
comment|// CHECK: vst1.64
end_comment

begin_function
name|void
name|test_vst2_u64
parameter_list|(
name|uint64_t
modifier|*
name|a
parameter_list|,
name|uint64x1x2_t
name|b
parameter_list|)
block|{
name|vst2_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst2_s8
end_comment

begin_comment
comment|// CHECK: vst2.8 {d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst2_s8
parameter_list|(
name|int8_t
modifier|*
name|a
parameter_list|,
name|int8x8x2_t
name|b
parameter_list|)
block|{
name|vst2_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst2_s16
end_comment

begin_comment
comment|// CHECK: vst2.16 {d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst2_s16
parameter_list|(
name|int16_t
modifier|*
name|a
parameter_list|,
name|int16x4x2_t
name|b
parameter_list|)
block|{
name|vst2_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst2_s32
end_comment

begin_comment
comment|// CHECK: vst2.32 {d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst2_s32
parameter_list|(
name|int32_t
modifier|*
name|a
parameter_list|,
name|int32x2x2_t
name|b
parameter_list|)
block|{
name|vst2_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst2_s64
end_comment

begin_comment
comment|// CHECK: vst1.64
end_comment

begin_function
name|void
name|test_vst2_s64
parameter_list|(
name|int64_t
modifier|*
name|a
parameter_list|,
name|int64x1x2_t
name|b
parameter_list|)
block|{
name|vst2_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst2_f16
end_comment

begin_comment
comment|// CHECK: vst2.16 {d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst2_f16
parameter_list|(
name|float16_t
modifier|*
name|a
parameter_list|,
name|float16x4x2_t
name|b
parameter_list|)
block|{
name|vst2_f16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst2_f32
end_comment

begin_comment
comment|// CHECK: vst2.32 {d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst2_f32
parameter_list|(
name|float32_t
modifier|*
name|a
parameter_list|,
name|float32x2x2_t
name|b
parameter_list|)
block|{
name|vst2_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst2_p8
end_comment

begin_comment
comment|// CHECK: vst2.8 {d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst2_p8
parameter_list|(
name|poly8_t
modifier|*
name|a
parameter_list|,
name|poly8x8x2_t
name|b
parameter_list|)
block|{
name|vst2_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst2_p16
end_comment

begin_comment
comment|// CHECK: vst2.16 {d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst2_p16
parameter_list|(
name|poly16_t
modifier|*
name|a
parameter_list|,
name|poly16x4x2_t
name|b
parameter_list|)
block|{
name|vst2_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst2q_lane_u16
end_comment

begin_comment
comment|// CHECK: vst2.16 {d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst2q_lane_u16
parameter_list|(
name|uint16_t
modifier|*
name|a
parameter_list|,
name|uint16x8x2_t
name|b
parameter_list|)
block|{
name|vst2q_lane_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst2q_lane_u32
end_comment

begin_comment
comment|// CHECK: vst2.32 {d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst2q_lane_u32
parameter_list|(
name|uint32_t
modifier|*
name|a
parameter_list|,
name|uint32x4x2_t
name|b
parameter_list|)
block|{
name|vst2q_lane_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst2q_lane_s16
end_comment

begin_comment
comment|// CHECK: vst2.16 {d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst2q_lane_s16
parameter_list|(
name|int16_t
modifier|*
name|a
parameter_list|,
name|int16x8x2_t
name|b
parameter_list|)
block|{
name|vst2q_lane_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst2q_lane_s32
end_comment

begin_comment
comment|// CHECK: vst2.32 {d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst2q_lane_s32
parameter_list|(
name|int32_t
modifier|*
name|a
parameter_list|,
name|int32x4x2_t
name|b
parameter_list|)
block|{
name|vst2q_lane_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst2q_lane_f16
end_comment

begin_comment
comment|// CHECK: vst2.16 {d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst2q_lane_f16
parameter_list|(
name|float16_t
modifier|*
name|a
parameter_list|,
name|float16x8x2_t
name|b
parameter_list|)
block|{
name|vst2q_lane_f16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst2q_lane_f32
end_comment

begin_comment
comment|// CHECK: vst2.32 {d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst2q_lane_f32
parameter_list|(
name|float32_t
modifier|*
name|a
parameter_list|,
name|float32x4x2_t
name|b
parameter_list|)
block|{
name|vst2q_lane_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst2q_lane_p16
end_comment

begin_comment
comment|// CHECK: vst2.16 {d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst2q_lane_p16
parameter_list|(
name|poly16_t
modifier|*
name|a
parameter_list|,
name|poly16x8x2_t
name|b
parameter_list|)
block|{
name|vst2q_lane_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst2_lane_u8
end_comment

begin_comment
comment|// CHECK: vst2.8 {d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst2_lane_u8
parameter_list|(
name|uint8_t
modifier|*
name|a
parameter_list|,
name|uint8x8x2_t
name|b
parameter_list|)
block|{
name|vst2_lane_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst2_lane_u16
end_comment

begin_comment
comment|// CHECK: vst2.16 {d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst2_lane_u16
parameter_list|(
name|uint16_t
modifier|*
name|a
parameter_list|,
name|uint16x4x2_t
name|b
parameter_list|)
block|{
name|vst2_lane_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst2_lane_u32
end_comment

begin_comment
comment|// CHECK: vst2.32 {d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst2_lane_u32
parameter_list|(
name|uint32_t
modifier|*
name|a
parameter_list|,
name|uint32x2x2_t
name|b
parameter_list|)
block|{
name|vst2_lane_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst2_lane_s8
end_comment

begin_comment
comment|// CHECK: vst2.8 {d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst2_lane_s8
parameter_list|(
name|int8_t
modifier|*
name|a
parameter_list|,
name|int8x8x2_t
name|b
parameter_list|)
block|{
name|vst2_lane_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst2_lane_s16
end_comment

begin_comment
comment|// CHECK: vst2.16 {d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst2_lane_s16
parameter_list|(
name|int16_t
modifier|*
name|a
parameter_list|,
name|int16x4x2_t
name|b
parameter_list|)
block|{
name|vst2_lane_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst2_lane_s32
end_comment

begin_comment
comment|// CHECK: vst2.32 {d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst2_lane_s32
parameter_list|(
name|int32_t
modifier|*
name|a
parameter_list|,
name|int32x2x2_t
name|b
parameter_list|)
block|{
name|vst2_lane_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst2_lane_f16
end_comment

begin_comment
comment|// CHECK: vst2.16 {d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst2_lane_f16
parameter_list|(
name|float16_t
modifier|*
name|a
parameter_list|,
name|float16x4x2_t
name|b
parameter_list|)
block|{
name|vst2_lane_f16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst2_lane_f32
end_comment

begin_comment
comment|// CHECK: vst2.32 {d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst2_lane_f32
parameter_list|(
name|float32_t
modifier|*
name|a
parameter_list|,
name|float32x2x2_t
name|b
parameter_list|)
block|{
name|vst2_lane_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst2_lane_p8
end_comment

begin_comment
comment|// CHECK: vst2.8 {d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst2_lane_p8
parameter_list|(
name|poly8_t
modifier|*
name|a
parameter_list|,
name|poly8x8x2_t
name|b
parameter_list|)
block|{
name|vst2_lane_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst2_lane_p16
end_comment

begin_comment
comment|// CHECK: vst2.16 {d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst2_lane_p16
parameter_list|(
name|poly16_t
modifier|*
name|a
parameter_list|,
name|poly16x4x2_t
name|b
parameter_list|)
block|{
name|vst2_lane_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst3q_u8
end_comment

begin_comment
comment|// CHECK: vst3.8 {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}
end_comment

begin_function
name|void
name|test_vst3q_u8
parameter_list|(
name|uint8_t
modifier|*
name|a
parameter_list|,
name|uint8x16x3_t
name|b
parameter_list|)
block|{
name|vst3q_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst3q_u16
end_comment

begin_comment
comment|// CHECK: vst3.16 {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}
end_comment

begin_function
name|void
name|test_vst3q_u16
parameter_list|(
name|uint16_t
modifier|*
name|a
parameter_list|,
name|uint16x8x3_t
name|b
parameter_list|)
block|{
name|vst3q_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst3q_u32
end_comment

begin_comment
comment|// CHECK: vst3.32 {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}
end_comment

begin_function
name|void
name|test_vst3q_u32
parameter_list|(
name|uint32_t
modifier|*
name|a
parameter_list|,
name|uint32x4x3_t
name|b
parameter_list|)
block|{
name|vst3q_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst3q_s8
end_comment

begin_comment
comment|// CHECK: vst3.8 {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}
end_comment

begin_function
name|void
name|test_vst3q_s8
parameter_list|(
name|int8_t
modifier|*
name|a
parameter_list|,
name|int8x16x3_t
name|b
parameter_list|)
block|{
name|vst3q_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst3q_s16
end_comment

begin_comment
comment|// CHECK: vst3.16 {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}
end_comment

begin_function
name|void
name|test_vst3q_s16
parameter_list|(
name|int16_t
modifier|*
name|a
parameter_list|,
name|int16x8x3_t
name|b
parameter_list|)
block|{
name|vst3q_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst3q_s32
end_comment

begin_comment
comment|// CHECK: vst3.32 {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}
end_comment

begin_function
name|void
name|test_vst3q_s32
parameter_list|(
name|int32_t
modifier|*
name|a
parameter_list|,
name|int32x4x3_t
name|b
parameter_list|)
block|{
name|vst3q_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst3q_f16
end_comment

begin_comment
comment|// CHECK: vst3.16 {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}
end_comment

begin_function
name|void
name|test_vst3q_f16
parameter_list|(
name|float16_t
modifier|*
name|a
parameter_list|,
name|float16x8x3_t
name|b
parameter_list|)
block|{
name|vst3q_f16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst3q_f32
end_comment

begin_comment
comment|// CHECK: vst3.32 {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}
end_comment

begin_function
name|void
name|test_vst3q_f32
parameter_list|(
name|float32_t
modifier|*
name|a
parameter_list|,
name|float32x4x3_t
name|b
parameter_list|)
block|{
name|vst3q_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst3q_p8
end_comment

begin_comment
comment|// CHECK: vst3.8 {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}
end_comment

begin_function
name|void
name|test_vst3q_p8
parameter_list|(
name|poly8_t
modifier|*
name|a
parameter_list|,
name|poly8x16x3_t
name|b
parameter_list|)
block|{
name|vst3q_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst3q_p16
end_comment

begin_comment
comment|// CHECK: vst3.16 {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}
end_comment

begin_function
name|void
name|test_vst3q_p16
parameter_list|(
name|poly16_t
modifier|*
name|a
parameter_list|,
name|poly16x8x3_t
name|b
parameter_list|)
block|{
name|vst3q_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst3_u8
end_comment

begin_comment
comment|// CHECK: vst3.8 {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst3_u8
parameter_list|(
name|uint8_t
modifier|*
name|a
parameter_list|,
name|uint8x8x3_t
name|b
parameter_list|)
block|{
name|vst3_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst3_u16
end_comment

begin_comment
comment|// CHECK: vst3.16 {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst3_u16
parameter_list|(
name|uint16_t
modifier|*
name|a
parameter_list|,
name|uint16x4x3_t
name|b
parameter_list|)
block|{
name|vst3_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst3_u32
end_comment

begin_comment
comment|// CHECK: vst3.32 {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst3_u32
parameter_list|(
name|uint32_t
modifier|*
name|a
parameter_list|,
name|uint32x2x3_t
name|b
parameter_list|)
block|{
name|vst3_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst3_u64
end_comment

begin_comment
comment|// CHECK: vst1.64
end_comment

begin_function
name|void
name|test_vst3_u64
parameter_list|(
name|uint64_t
modifier|*
name|a
parameter_list|,
name|uint64x1x3_t
name|b
parameter_list|)
block|{
name|vst3_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst3_s8
end_comment

begin_comment
comment|// CHECK: vst3.8 {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst3_s8
parameter_list|(
name|int8_t
modifier|*
name|a
parameter_list|,
name|int8x8x3_t
name|b
parameter_list|)
block|{
name|vst3_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst3_s16
end_comment

begin_comment
comment|// CHECK: vst3.16 {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst3_s16
parameter_list|(
name|int16_t
modifier|*
name|a
parameter_list|,
name|int16x4x3_t
name|b
parameter_list|)
block|{
name|vst3_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst3_s32
end_comment

begin_comment
comment|// CHECK: vst3.32 {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst3_s32
parameter_list|(
name|int32_t
modifier|*
name|a
parameter_list|,
name|int32x2x3_t
name|b
parameter_list|)
block|{
name|vst3_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst3_s64
end_comment

begin_comment
comment|// CHECK: vst1.64
end_comment

begin_function
name|void
name|test_vst3_s64
parameter_list|(
name|int64_t
modifier|*
name|a
parameter_list|,
name|int64x1x3_t
name|b
parameter_list|)
block|{
name|vst3_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst3_f16
end_comment

begin_comment
comment|// CHECK: vst3.16 {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst3_f16
parameter_list|(
name|float16_t
modifier|*
name|a
parameter_list|,
name|float16x4x3_t
name|b
parameter_list|)
block|{
name|vst3_f16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst3_f32
end_comment

begin_comment
comment|// CHECK: vst3.32 {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst3_f32
parameter_list|(
name|float32_t
modifier|*
name|a
parameter_list|,
name|float32x2x3_t
name|b
parameter_list|)
block|{
name|vst3_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst3_p8
end_comment

begin_comment
comment|// CHECK: vst3.8 {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst3_p8
parameter_list|(
name|poly8_t
modifier|*
name|a
parameter_list|,
name|poly8x8x3_t
name|b
parameter_list|)
block|{
name|vst3_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst3_p16
end_comment

begin_comment
comment|// CHECK: vst3.16 {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst3_p16
parameter_list|(
name|poly16_t
modifier|*
name|a
parameter_list|,
name|poly16x4x3_t
name|b
parameter_list|)
block|{
name|vst3_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst3q_lane_u16
end_comment

begin_comment
comment|// CHECK: vst3.16 {d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}]}
end_comment

begin_function
name|void
name|test_vst3q_lane_u16
parameter_list|(
name|uint16_t
modifier|*
name|a
parameter_list|,
name|uint16x8x3_t
name|b
parameter_list|)
block|{
name|vst3q_lane_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst3q_lane_u32
end_comment

begin_comment
comment|// CHECK: vst3.32 {d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}]}
end_comment

begin_function
name|void
name|test_vst3q_lane_u32
parameter_list|(
name|uint32_t
modifier|*
name|a
parameter_list|,
name|uint32x4x3_t
name|b
parameter_list|)
block|{
name|vst3q_lane_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst3q_lane_s16
end_comment

begin_comment
comment|// CHECK: vst3.16 {d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}]}
end_comment

begin_function
name|void
name|test_vst3q_lane_s16
parameter_list|(
name|int16_t
modifier|*
name|a
parameter_list|,
name|int16x8x3_t
name|b
parameter_list|)
block|{
name|vst3q_lane_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst3q_lane_s32
end_comment

begin_comment
comment|// CHECK: vst3.32 {d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}]}
end_comment

begin_function
name|void
name|test_vst3q_lane_s32
parameter_list|(
name|int32_t
modifier|*
name|a
parameter_list|,
name|int32x4x3_t
name|b
parameter_list|)
block|{
name|vst3q_lane_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst3q_lane_f16
end_comment

begin_comment
comment|// CHECK: vst3.16 {d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}]}
end_comment

begin_function
name|void
name|test_vst3q_lane_f16
parameter_list|(
name|float16_t
modifier|*
name|a
parameter_list|,
name|float16x8x3_t
name|b
parameter_list|)
block|{
name|vst3q_lane_f16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst3q_lane_f32
end_comment

begin_comment
comment|// CHECK: vst3.32 {d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}]}
end_comment

begin_function
name|void
name|test_vst3q_lane_f32
parameter_list|(
name|float32_t
modifier|*
name|a
parameter_list|,
name|float32x4x3_t
name|b
parameter_list|)
block|{
name|vst3q_lane_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst3q_lane_p16
end_comment

begin_comment
comment|// CHECK: vst3.16 {d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}]}
end_comment

begin_function
name|void
name|test_vst3q_lane_p16
parameter_list|(
name|poly16_t
modifier|*
name|a
parameter_list|,
name|poly16x8x3_t
name|b
parameter_list|)
block|{
name|vst3q_lane_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst3_lane_u8
end_comment

begin_comment
comment|// CHECK: vst3.8 {d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst3_lane_u8
parameter_list|(
name|uint8_t
modifier|*
name|a
parameter_list|,
name|uint8x8x3_t
name|b
parameter_list|)
block|{
name|vst3_lane_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst3_lane_u16
end_comment

begin_comment
comment|// CHECK: vst3.16 {d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst3_lane_u16
parameter_list|(
name|uint16_t
modifier|*
name|a
parameter_list|,
name|uint16x4x3_t
name|b
parameter_list|)
block|{
name|vst3_lane_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst3_lane_u32
end_comment

begin_comment
comment|// CHECK: vst3.32 {d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst3_lane_u32
parameter_list|(
name|uint32_t
modifier|*
name|a
parameter_list|,
name|uint32x2x3_t
name|b
parameter_list|)
block|{
name|vst3_lane_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst3_lane_s8
end_comment

begin_comment
comment|// CHECK: vst3.8 {d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst3_lane_s8
parameter_list|(
name|int8_t
modifier|*
name|a
parameter_list|,
name|int8x8x3_t
name|b
parameter_list|)
block|{
name|vst3_lane_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst3_lane_s16
end_comment

begin_comment
comment|// CHECK: vst3.16 {d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst3_lane_s16
parameter_list|(
name|int16_t
modifier|*
name|a
parameter_list|,
name|int16x4x3_t
name|b
parameter_list|)
block|{
name|vst3_lane_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst3_lane_s32
end_comment

begin_comment
comment|// CHECK: vst3.32 {d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst3_lane_s32
parameter_list|(
name|int32_t
modifier|*
name|a
parameter_list|,
name|int32x2x3_t
name|b
parameter_list|)
block|{
name|vst3_lane_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst3_lane_f16
end_comment

begin_comment
comment|// CHECK: vst3.16 {d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst3_lane_f16
parameter_list|(
name|float16_t
modifier|*
name|a
parameter_list|,
name|float16x4x3_t
name|b
parameter_list|)
block|{
name|vst3_lane_f16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst3_lane_f32
end_comment

begin_comment
comment|// CHECK: vst3.32 {d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst3_lane_f32
parameter_list|(
name|float32_t
modifier|*
name|a
parameter_list|,
name|float32x2x3_t
name|b
parameter_list|)
block|{
name|vst3_lane_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst3_lane_p8
end_comment

begin_comment
comment|// CHECK: vst3.8 {d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst3_lane_p8
parameter_list|(
name|poly8_t
modifier|*
name|a
parameter_list|,
name|poly8x8x3_t
name|b
parameter_list|)
block|{
name|vst3_lane_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst3_lane_p16
end_comment

begin_comment
comment|// CHECK: vst3.16 {d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst3_lane_p16
parameter_list|(
name|poly16_t
modifier|*
name|a
parameter_list|,
name|poly16x4x3_t
name|b
parameter_list|)
block|{
name|vst3_lane_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst4q_u8
end_comment

begin_comment
comment|// CHECK: vst4.8 {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}
end_comment

begin_function
name|void
name|test_vst4q_u8
parameter_list|(
name|uint8_t
modifier|*
name|a
parameter_list|,
name|uint8x16x4_t
name|b
parameter_list|)
block|{
name|vst4q_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst4q_u16
end_comment

begin_comment
comment|// CHECK: vst4.16 {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}
end_comment

begin_function
name|void
name|test_vst4q_u16
parameter_list|(
name|uint16_t
modifier|*
name|a
parameter_list|,
name|uint16x8x4_t
name|b
parameter_list|)
block|{
name|vst4q_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst4q_u32
end_comment

begin_comment
comment|// CHECK: vst4.32 {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}
end_comment

begin_function
name|void
name|test_vst4q_u32
parameter_list|(
name|uint32_t
modifier|*
name|a
parameter_list|,
name|uint32x4x4_t
name|b
parameter_list|)
block|{
name|vst4q_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst4q_s8
end_comment

begin_comment
comment|// CHECK: vst4.8 {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}
end_comment

begin_function
name|void
name|test_vst4q_s8
parameter_list|(
name|int8_t
modifier|*
name|a
parameter_list|,
name|int8x16x4_t
name|b
parameter_list|)
block|{
name|vst4q_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst4q_s16
end_comment

begin_comment
comment|// CHECK: vst4.16 {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}
end_comment

begin_function
name|void
name|test_vst4q_s16
parameter_list|(
name|int16_t
modifier|*
name|a
parameter_list|,
name|int16x8x4_t
name|b
parameter_list|)
block|{
name|vst4q_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst4q_s32
end_comment

begin_comment
comment|// CHECK: vst4.32 {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}
end_comment

begin_function
name|void
name|test_vst4q_s32
parameter_list|(
name|int32_t
modifier|*
name|a
parameter_list|,
name|int32x4x4_t
name|b
parameter_list|)
block|{
name|vst4q_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst4q_f16
end_comment

begin_comment
comment|// CHECK: vst4.16 {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}
end_comment

begin_function
name|void
name|test_vst4q_f16
parameter_list|(
name|float16_t
modifier|*
name|a
parameter_list|,
name|float16x8x4_t
name|b
parameter_list|)
block|{
name|vst4q_f16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst4q_f32
end_comment

begin_comment
comment|// CHECK: vst4.32 {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}
end_comment

begin_function
name|void
name|test_vst4q_f32
parameter_list|(
name|float32_t
modifier|*
name|a
parameter_list|,
name|float32x4x4_t
name|b
parameter_list|)
block|{
name|vst4q_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst4q_p8
end_comment

begin_comment
comment|// CHECK: vst4.8 {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}
end_comment

begin_function
name|void
name|test_vst4q_p8
parameter_list|(
name|poly8_t
modifier|*
name|a
parameter_list|,
name|poly8x16x4_t
name|b
parameter_list|)
block|{
name|vst4q_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst4q_p16
end_comment

begin_comment
comment|// CHECK: vst4.16 {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}
end_comment

begin_function
name|void
name|test_vst4q_p16
parameter_list|(
name|poly16_t
modifier|*
name|a
parameter_list|,
name|poly16x8x4_t
name|b
parameter_list|)
block|{
name|vst4q_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst4_u8
end_comment

begin_comment
comment|// CHECK: vst4.8 {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst4_u8
parameter_list|(
name|uint8_t
modifier|*
name|a
parameter_list|,
name|uint8x8x4_t
name|b
parameter_list|)
block|{
name|vst4_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst4_u16
end_comment

begin_comment
comment|// CHECK: vst4.16 {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst4_u16
parameter_list|(
name|uint16_t
modifier|*
name|a
parameter_list|,
name|uint16x4x4_t
name|b
parameter_list|)
block|{
name|vst4_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst4_u32
end_comment

begin_comment
comment|// CHECK: vst4.32 {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst4_u32
parameter_list|(
name|uint32_t
modifier|*
name|a
parameter_list|,
name|uint32x2x4_t
name|b
parameter_list|)
block|{
name|vst4_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst4_u64
end_comment

begin_comment
comment|// CHECK: vst1.64
end_comment

begin_function
name|void
name|test_vst4_u64
parameter_list|(
name|uint64_t
modifier|*
name|a
parameter_list|,
name|uint64x1x4_t
name|b
parameter_list|)
block|{
name|vst4_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst4_s8
end_comment

begin_comment
comment|// CHECK: vst4.8 {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst4_s8
parameter_list|(
name|int8_t
modifier|*
name|a
parameter_list|,
name|int8x8x4_t
name|b
parameter_list|)
block|{
name|vst4_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst4_s16
end_comment

begin_comment
comment|// CHECK: vst4.16 {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst4_s16
parameter_list|(
name|int16_t
modifier|*
name|a
parameter_list|,
name|int16x4x4_t
name|b
parameter_list|)
block|{
name|vst4_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst4_s32
end_comment

begin_comment
comment|// CHECK: vst4.32 {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst4_s32
parameter_list|(
name|int32_t
modifier|*
name|a
parameter_list|,
name|int32x2x4_t
name|b
parameter_list|)
block|{
name|vst4_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst4_s64
end_comment

begin_comment
comment|// CHECK: vst1.64
end_comment

begin_function
name|void
name|test_vst4_s64
parameter_list|(
name|int64_t
modifier|*
name|a
parameter_list|,
name|int64x1x4_t
name|b
parameter_list|)
block|{
name|vst4_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst4_f16
end_comment

begin_comment
comment|// CHECK: vst4.16 {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst4_f16
parameter_list|(
name|float16_t
modifier|*
name|a
parameter_list|,
name|float16x4x4_t
name|b
parameter_list|)
block|{
name|vst4_f16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst4_f32
end_comment

begin_comment
comment|// CHECK: vst4.32 {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst4_f32
parameter_list|(
name|float32_t
modifier|*
name|a
parameter_list|,
name|float32x2x4_t
name|b
parameter_list|)
block|{
name|vst4_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst4_p8
end_comment

begin_comment
comment|// CHECK: vst4.8 {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst4_p8
parameter_list|(
name|poly8_t
modifier|*
name|a
parameter_list|,
name|poly8x8x4_t
name|b
parameter_list|)
block|{
name|vst4_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst4_p16
end_comment

begin_comment
comment|// CHECK: vst4.16 {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst4_p16
parameter_list|(
name|poly16_t
modifier|*
name|a
parameter_list|,
name|poly16x4x4_t
name|b
parameter_list|)
block|{
name|vst4_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst4q_lane_u16
end_comment

begin_comment
comment|// CHECK: vst4.16 {d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}]}
end_comment

begin_function
name|void
name|test_vst4q_lane_u16
parameter_list|(
name|uint16_t
modifier|*
name|a
parameter_list|,
name|uint16x8x4_t
name|b
parameter_list|)
block|{
name|vst4q_lane_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst4q_lane_u32
end_comment

begin_comment
comment|// CHECK: vst4.32 {d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}]}
end_comment

begin_function
name|void
name|test_vst4q_lane_u32
parameter_list|(
name|uint32_t
modifier|*
name|a
parameter_list|,
name|uint32x4x4_t
name|b
parameter_list|)
block|{
name|vst4q_lane_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst4q_lane_s16
end_comment

begin_comment
comment|// CHECK: vst4.16 {d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}]}
end_comment

begin_function
name|void
name|test_vst4q_lane_s16
parameter_list|(
name|int16_t
modifier|*
name|a
parameter_list|,
name|int16x8x4_t
name|b
parameter_list|)
block|{
name|vst4q_lane_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst4q_lane_s32
end_comment

begin_comment
comment|// CHECK: vst4.32 {d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}]}
end_comment

begin_function
name|void
name|test_vst4q_lane_s32
parameter_list|(
name|int32_t
modifier|*
name|a
parameter_list|,
name|int32x4x4_t
name|b
parameter_list|)
block|{
name|vst4q_lane_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst4q_lane_f16
end_comment

begin_comment
comment|// CHECK: vst4.16 {d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}]}
end_comment

begin_function
name|void
name|test_vst4q_lane_f16
parameter_list|(
name|float16_t
modifier|*
name|a
parameter_list|,
name|float16x8x4_t
name|b
parameter_list|)
block|{
name|vst4q_lane_f16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst4q_lane_f32
end_comment

begin_comment
comment|// CHECK: vst4.32 {d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}]}
end_comment

begin_function
name|void
name|test_vst4q_lane_f32
parameter_list|(
name|float32_t
modifier|*
name|a
parameter_list|,
name|float32x4x4_t
name|b
parameter_list|)
block|{
name|vst4q_lane_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst4q_lane_p16
end_comment

begin_comment
comment|// CHECK: vst4.16 {d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}]}
end_comment

begin_function
name|void
name|test_vst4q_lane_p16
parameter_list|(
name|poly16_t
modifier|*
name|a
parameter_list|,
name|poly16x8x4_t
name|b
parameter_list|)
block|{
name|vst4q_lane_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst4_lane_u8
end_comment

begin_comment
comment|// CHECK: vst4.8 {d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst4_lane_u8
parameter_list|(
name|uint8_t
modifier|*
name|a
parameter_list|,
name|uint8x8x4_t
name|b
parameter_list|)
block|{
name|vst4_lane_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst4_lane_u16
end_comment

begin_comment
comment|// CHECK: vst4.16 {d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst4_lane_u16
parameter_list|(
name|uint16_t
modifier|*
name|a
parameter_list|,
name|uint16x4x4_t
name|b
parameter_list|)
block|{
name|vst4_lane_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst4_lane_u32
end_comment

begin_comment
comment|// CHECK: vst4.32 {d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst4_lane_u32
parameter_list|(
name|uint32_t
modifier|*
name|a
parameter_list|,
name|uint32x2x4_t
name|b
parameter_list|)
block|{
name|vst4_lane_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst4_lane_s8
end_comment

begin_comment
comment|// CHECK: vst4.8 {d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst4_lane_s8
parameter_list|(
name|int8_t
modifier|*
name|a
parameter_list|,
name|int8x8x4_t
name|b
parameter_list|)
block|{
name|vst4_lane_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst4_lane_s16
end_comment

begin_comment
comment|// CHECK: vst4.16 {d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst4_lane_s16
parameter_list|(
name|int16_t
modifier|*
name|a
parameter_list|,
name|int16x4x4_t
name|b
parameter_list|)
block|{
name|vst4_lane_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst4_lane_s32
end_comment

begin_comment
comment|// CHECK: vst4.32 {d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst4_lane_s32
parameter_list|(
name|int32_t
modifier|*
name|a
parameter_list|,
name|int32x2x4_t
name|b
parameter_list|)
block|{
name|vst4_lane_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst4_lane_f16
end_comment

begin_comment
comment|// CHECK: vst4.16 {d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst4_lane_f16
parameter_list|(
name|float16_t
modifier|*
name|a
parameter_list|,
name|float16x4x4_t
name|b
parameter_list|)
block|{
name|vst4_lane_f16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst4_lane_f32
end_comment

begin_comment
comment|// CHECK: vst4.32 {d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst4_lane_f32
parameter_list|(
name|float32_t
modifier|*
name|a
parameter_list|,
name|float32x2x4_t
name|b
parameter_list|)
block|{
name|vst4_lane_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst4_lane_p8
end_comment

begin_comment
comment|// CHECK: vst4.8 {d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst4_lane_p8
parameter_list|(
name|poly8_t
modifier|*
name|a
parameter_list|,
name|poly8x8x4_t
name|b
parameter_list|)
block|{
name|vst4_lane_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vst4_lane_p16
end_comment

begin_comment
comment|// CHECK: vst4.16 {d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}], d{{[0-9]+}}[{{[0-9]+}}]}, [r{{[0-9]+}}]
end_comment

begin_function
name|void
name|test_vst4_lane_p16
parameter_list|(
name|poly16_t
modifier|*
name|a
parameter_list|,
name|poly16x4x4_t
name|b
parameter_list|)
block|{
name|vst4_lane_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vsub_s8
end_comment

begin_comment
comment|// CHECK: vsub.i8 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int8x8_t
name|test_vsub_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
return|return
name|vsub_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vsub_s16
end_comment

begin_comment
comment|// CHECK: vsub.i16 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int16x4_t
name|test_vsub_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
return|return
name|vsub_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vsub_s32
end_comment

begin_comment
comment|// CHECK: vsub.i32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int32x2_t
name|test_vsub_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
return|return
name|vsub_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vsub_s64
end_comment

begin_comment
comment|// CHECK: vsub.i64 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int64x1_t
name|test_vsub_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|,
name|int64x1_t
name|b
parameter_list|)
block|{
return|return
name|vsub_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vsub_f32
end_comment

begin_comment
comment|// CHECK: vsub.f32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|float32x2_t
name|test_vsub_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32x2_t
name|b
parameter_list|)
block|{
return|return
name|vsub_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vsub_u8
end_comment

begin_comment
comment|// CHECK: vsub.i8 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint8x8_t
name|test_vsub_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|)
block|{
return|return
name|vsub_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vsub_u16
end_comment

begin_comment
comment|// CHECK: vsub.i16 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint16x4_t
name|test_vsub_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|)
block|{
return|return
name|vsub_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vsub_u32
end_comment

begin_comment
comment|// CHECK: vsub.i32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint32x2_t
name|test_vsub_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|)
block|{
return|return
name|vsub_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vsub_u64
end_comment

begin_comment
comment|// CHECK: vsub.i64 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint64x1_t
name|test_vsub_u64
parameter_list|(
name|uint64x1_t
name|a
parameter_list|,
name|uint64x1_t
name|b
parameter_list|)
block|{
return|return
name|vsub_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vsubq_s8
end_comment

begin_comment
comment|// CHECK: vsub.i8 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int8x16_t
name|test_vsubq_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|)
block|{
return|return
name|vsubq_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vsubq_s16
end_comment

begin_comment
comment|// CHECK: vsub.i16 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int16x8_t
name|test_vsubq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
return|return
name|vsubq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vsubq_s32
end_comment

begin_comment
comment|// CHECK: vsub.i32 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int32x4_t
name|test_vsubq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
return|return
name|vsubq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vsubq_s64
end_comment

begin_comment
comment|// CHECK: vsub.i64 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int64x2_t
name|test_vsubq_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int64x2_t
name|b
parameter_list|)
block|{
return|return
name|vsubq_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vsubq_f32
end_comment

begin_comment
comment|// CHECK: vsub.f32 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|float32x4_t
name|test_vsubq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|,
name|float32x4_t
name|b
parameter_list|)
block|{
return|return
name|vsubq_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vsubq_u8
end_comment

begin_comment
comment|// CHECK: vsub.i8 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint8x16_t
name|test_vsubq_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|,
name|uint8x16_t
name|b
parameter_list|)
block|{
return|return
name|vsubq_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vsubq_u16
end_comment

begin_comment
comment|// CHECK: vsub.i16 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint16x8_t
name|test_vsubq_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|)
block|{
return|return
name|vsubq_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vsubq_u32
end_comment

begin_comment
comment|// CHECK: vsub.i32 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint32x4_t
name|test_vsubq_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|)
block|{
return|return
name|vsubq_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vsubq_u64
end_comment

begin_comment
comment|// CHECK: vsub.i64 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint64x2_t
name|test_vsubq_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|,
name|uint64x2_t
name|b
parameter_list|)
block|{
return|return
name|vsubq_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vsubhn_s16
end_comment

begin_comment
comment|// CHECK: vsubhn.i16 d{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int8x8_t
name|test_vsubhn_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
return|return
name|vsubhn_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vsubhn_s32
end_comment

begin_comment
comment|// CHECK: vsubhn.i32 d{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int16x4_t
name|test_vsubhn_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
return|return
name|vsubhn_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vsubhn_s64
end_comment

begin_comment
comment|// CHECK: vsubhn.i64 d{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int32x2_t
name|test_vsubhn_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int64x2_t
name|b
parameter_list|)
block|{
return|return
name|vsubhn_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vsubhn_u16
end_comment

begin_comment
comment|// CHECK: vsubhn.i16 d{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint8x8_t
name|test_vsubhn_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|)
block|{
return|return
name|vsubhn_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vsubhn_u32
end_comment

begin_comment
comment|// CHECK: vsubhn.i32 d{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint16x4_t
name|test_vsubhn_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|)
block|{
return|return
name|vsubhn_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vsubhn_u64
end_comment

begin_comment
comment|// CHECK: vsubhn.i64 d{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint32x2_t
name|test_vsubhn_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|,
name|uint64x2_t
name|b
parameter_list|)
block|{
return|return
name|vsubhn_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vsubl_s8
end_comment

begin_comment
comment|// CHECK: vsubl.s8 q{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int16x8_t
name|test_vsubl_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
return|return
name|vsubl_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vsubl_s16
end_comment

begin_comment
comment|// CHECK: vsubl.s16 q{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int32x4_t
name|test_vsubl_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
return|return
name|vsubl_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vsubl_s32
end_comment

begin_comment
comment|// CHECK: vsubl.s32 q{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int64x2_t
name|test_vsubl_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
return|return
name|vsubl_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vsubl_u8
end_comment

begin_comment
comment|// CHECK: vsubl.u8 q{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint16x8_t
name|test_vsubl_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|)
block|{
return|return
name|vsubl_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vsubl_u16
end_comment

begin_comment
comment|// CHECK: vsubl.u16 q{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint32x4_t
name|test_vsubl_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|)
block|{
return|return
name|vsubl_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vsubl_u32
end_comment

begin_comment
comment|// CHECK: vsubl.u32 q{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint64x2_t
name|test_vsubl_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|)
block|{
return|return
name|vsubl_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vsubw_s8
end_comment

begin_comment
comment|// CHECK: vsubw.s8 q{{[0-9]+}}, q{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int16x8_t
name|test_vsubw_s8
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
return|return
name|vsubw_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vsubw_s16
end_comment

begin_comment
comment|// CHECK: vsubw.s16 q{{[0-9]+}}, q{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int32x4_t
name|test_vsubw_s16
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
return|return
name|vsubw_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vsubw_s32
end_comment

begin_comment
comment|// CHECK: vsubw.s32 q{{[0-9]+}}, q{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int64x2_t
name|test_vsubw_s32
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
return|return
name|vsubw_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vsubw_u8
end_comment

begin_comment
comment|// CHECK: vsubw.u8 q{{[0-9]+}}, q{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint16x8_t
name|test_vsubw_u8
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|)
block|{
return|return
name|vsubw_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vsubw_u16
end_comment

begin_comment
comment|// CHECK: vsubw.u16 q{{[0-9]+}}, q{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint32x4_t
name|test_vsubw_u16
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|)
block|{
return|return
name|vsubw_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vsubw_u32
end_comment

begin_comment
comment|// CHECK: vsubw.u32 q{{[0-9]+}}, q{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint64x2_t
name|test_vsubw_u32
parameter_list|(
name|uint64x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|)
block|{
return|return
name|vsubw_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vtbl1_u8
end_comment

begin_comment
comment|// CHECK: vtbl.8 d{{[0-9]+}}, {d{{[0-9]+}}}, d{{[0-9]+}}
end_comment

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
return|return
name|vtbl1_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vtbl1_s8
end_comment

begin_comment
comment|// CHECK: vtbl.8 d{{[0-9]+}}, {d{{[0-9]+}}}, d{{[0-9]+}}
end_comment

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
return|return
name|vtbl1_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vtbl1_p8
end_comment

begin_comment
comment|// CHECK: vtbl.8 d{{[0-9]+}}, {d{{[0-9]+}}}, d{{[0-9]+}}
end_comment

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
return|return
name|vtbl1_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vtbl2_u8
end_comment

begin_comment
comment|// CHECK: vtbl.8 d{{[0-9]+}}, {d{{[0-9]+}}, d{{[0-9]+}}}, d{{[0-9]+}}
end_comment

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
return|return
name|vtbl2_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vtbl2_s8
end_comment

begin_comment
comment|// CHECK: vtbl.8 d{{[0-9]+}}, {d{{[0-9]+}}, d{{[0-9]+}}}, d{{[0-9]+}}
end_comment

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
return|return
name|vtbl2_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vtbl2_p8
end_comment

begin_comment
comment|// CHECK: vtbl.8 d{{[0-9]+}}, {d{{[0-9]+}}, d{{[0-9]+}}}, d{{[0-9]+}}
end_comment

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
return|return
name|vtbl2_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vtbl3_u8
end_comment

begin_comment
comment|// CHECK: vtbl.8 d{{[0-9]+}}, {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}, d{{[0-9]+}}
end_comment

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
return|return
name|vtbl3_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vtbl3_s8
end_comment

begin_comment
comment|// CHECK: vtbl.8 d{{[0-9]+}}, {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}, d{{[0-9]+}}
end_comment

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
return|return
name|vtbl3_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vtbl3_p8
end_comment

begin_comment
comment|// CHECK: vtbl.8 d{{[0-9]+}}, {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}, d{{[0-9]+}}
end_comment

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
return|return
name|vtbl3_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vtbl4_u8
end_comment

begin_comment
comment|// CHECK: vtbl.8 d{{[0-9]+}}, {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}, d{{[0-9]+}}
end_comment

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
return|return
name|vtbl4_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vtbl4_s8
end_comment

begin_comment
comment|// CHECK: vtbl.8 d{{[0-9]+}}, {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}, d{{[0-9]+}}
end_comment

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
return|return
name|vtbl4_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vtbl4_p8
end_comment

begin_comment
comment|// CHECK: vtbl.8 d{{[0-9]+}}, {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}, d{{[0-9]+}}
end_comment

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
return|return
name|vtbl4_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vtbx1_u8
end_comment

begin_comment
comment|// CHECK: vtbx.8 d{{[0-9]+}}, {d{{[0-9]+}}}, d{{[0-9]+}}
end_comment

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
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vtbx1_s8
end_comment

begin_comment
comment|// CHECK: vtbx.8 d{{[0-9]+}}, {d{{[0-9]+}}}, d{{[0-9]+}}
end_comment

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
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vtbx1_p8
end_comment

begin_comment
comment|// CHECK: vtbx.8 d{{[0-9]+}}, {d{{[0-9]+}}}, d{{[0-9]+}}
end_comment

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
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vtbx2_u8
end_comment

begin_comment
comment|// CHECK: vtbx.8 d{{[0-9]+}}, {d{{[0-9]+}}, d{{[0-9]+}}}, d{{[0-9]+}}
end_comment

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
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vtbx2_s8
end_comment

begin_comment
comment|// CHECK: vtbx.8 d{{[0-9]+}}, {d{{[0-9]+}}, d{{[0-9]+}}}, d{{[0-9]+}}
end_comment

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
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vtbx2_p8
end_comment

begin_comment
comment|// CHECK: vtbx.8 d{{[0-9]+}}, {d{{[0-9]+}}, d{{[0-9]+}}}, d{{[0-9]+}}
end_comment

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
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vtbx3_u8
end_comment

begin_comment
comment|// CHECK: vtbx.8 d{{[0-9]+}}, {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}, d{{[0-9]+}}
end_comment

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
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vtbx3_s8
end_comment

begin_comment
comment|// CHECK: vtbx.8 d{{[0-9]+}}, {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}, d{{[0-9]+}}
end_comment

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
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vtbx3_p8
end_comment

begin_comment
comment|// CHECK: vtbx.8 d{{[0-9]+}}, {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}, d{{[0-9]+}}
end_comment

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
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vtbx4_u8
end_comment

begin_comment
comment|// CHECK: vtbx.8 d{{[0-9]+}}, {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}, d{{[0-9]+}}
end_comment

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
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vtbx4_s8
end_comment

begin_comment
comment|// CHECK: vtbx.8 d{{[0-9]+}}, {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}, d{{[0-9]+}}
end_comment

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
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vtbx4_p8
end_comment

begin_comment
comment|// CHECK: vtbx.8 d{{[0-9]+}}, {d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}}, d{{[0-9]+}}
end_comment

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
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vtrn_s8
end_comment

begin_comment
comment|// CHECK: vtrn.8 d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int8x8x2_t
name|test_vtrn_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
return|return
name|vtrn_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vtrn_s16
end_comment

begin_comment
comment|// CHECK: vtrn.16 d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int16x4x2_t
name|test_vtrn_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
return|return
name|vtrn_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vtrn_s32
end_comment

begin_comment
comment|// CHECK: vtrn.32 d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int32x2x2_t
name|test_vtrn_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
return|return
name|vtrn_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vtrn_u8
end_comment

begin_comment
comment|// CHECK: vtrn.8 d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint8x8x2_t
name|test_vtrn_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|)
block|{
return|return
name|vtrn_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vtrn_u16
end_comment

begin_comment
comment|// CHECK: vtrn.16 d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint16x4x2_t
name|test_vtrn_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|)
block|{
return|return
name|vtrn_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vtrn_u32
end_comment

begin_comment
comment|// CHECK: vtrn.32 d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint32x2x2_t
name|test_vtrn_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|)
block|{
return|return
name|vtrn_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vtrn_f32
end_comment

begin_comment
comment|// CHECK: vtrn.32 d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|float32x2x2_t
name|test_vtrn_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32x2_t
name|b
parameter_list|)
block|{
return|return
name|vtrn_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vtrn_p8
end_comment

begin_comment
comment|// CHECK: vtrn.8 d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|poly8x8x2_t
name|test_vtrn_p8
parameter_list|(
name|poly8x8_t
name|a
parameter_list|,
name|poly8x8_t
name|b
parameter_list|)
block|{
return|return
name|vtrn_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vtrn_p16
end_comment

begin_comment
comment|// CHECK: vtrn.16 d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|poly16x4x2_t
name|test_vtrn_p16
parameter_list|(
name|poly16x4_t
name|a
parameter_list|,
name|poly16x4_t
name|b
parameter_list|)
block|{
return|return
name|vtrn_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vtrnq_s8
end_comment

begin_comment
comment|// CHECK: vtrn.8 q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int8x16x2_t
name|test_vtrnq_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|)
block|{
return|return
name|vtrnq_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vtrnq_s16
end_comment

begin_comment
comment|// CHECK: vtrn.16 q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int16x8x2_t
name|test_vtrnq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
return|return
name|vtrnq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vtrnq_s32
end_comment

begin_comment
comment|// CHECK: vtrn.32 q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int32x4x2_t
name|test_vtrnq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
return|return
name|vtrnq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vtrnq_u8
end_comment

begin_comment
comment|// CHECK: vtrn.8 q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint8x16x2_t
name|test_vtrnq_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|,
name|uint8x16_t
name|b
parameter_list|)
block|{
return|return
name|vtrnq_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vtrnq_u16
end_comment

begin_comment
comment|// CHECK: vtrn.16 q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint16x8x2_t
name|test_vtrnq_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|)
block|{
return|return
name|vtrnq_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vtrnq_u32
end_comment

begin_comment
comment|// CHECK: vtrn.32 q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint32x4x2_t
name|test_vtrnq_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|)
block|{
return|return
name|vtrnq_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vtrnq_f32
end_comment

begin_comment
comment|// CHECK: vtrn.32 q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|float32x4x2_t
name|test_vtrnq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|,
name|float32x4_t
name|b
parameter_list|)
block|{
return|return
name|vtrnq_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vtrnq_p8
end_comment

begin_comment
comment|// CHECK: vtrn.8 q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|poly8x16x2_t
name|test_vtrnq_p8
parameter_list|(
name|poly8x16_t
name|a
parameter_list|,
name|poly8x16_t
name|b
parameter_list|)
block|{
return|return
name|vtrnq_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vtrnq_p16
end_comment

begin_comment
comment|// CHECK: vtrn.16 q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|poly16x8x2_t
name|test_vtrnq_p16
parameter_list|(
name|poly16x8_t
name|a
parameter_list|,
name|poly16x8_t
name|b
parameter_list|)
block|{
return|return
name|vtrnq_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vtst_s8
end_comment

begin_comment
comment|// CHECK: vtst.8 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint8x8_t
name|test_vtst_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
return|return
name|vtst_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vtst_s16
end_comment

begin_comment
comment|// CHECK: vtst.16 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint16x4_t
name|test_vtst_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
return|return
name|vtst_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vtst_s32
end_comment

begin_comment
comment|// CHECK: vtst.32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint32x2_t
name|test_vtst_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
return|return
name|vtst_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vtst_u8
end_comment

begin_comment
comment|// CHECK: vtst.8 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint8x8_t
name|test_vtst_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|)
block|{
return|return
name|vtst_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vtst_u16
end_comment

begin_comment
comment|// CHECK: vtst.16 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint16x4_t
name|test_vtst_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|)
block|{
return|return
name|vtst_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vtst_u32
end_comment

begin_comment
comment|// CHECK: vtst.32 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint32x2_t
name|test_vtst_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|)
block|{
return|return
name|vtst_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vtst_p8
end_comment

begin_comment
comment|// CHECK: vtst.8 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint8x8_t
name|test_vtst_p8
parameter_list|(
name|poly8x8_t
name|a
parameter_list|,
name|poly8x8_t
name|b
parameter_list|)
block|{
return|return
name|vtst_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vtst_p16
end_comment

begin_comment
comment|// CHECK: vtst.16 d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint16x4_t
name|test_vtst_p16
parameter_list|(
name|poly16x4_t
name|a
parameter_list|,
name|poly16x4_t
name|b
parameter_list|)
block|{
return|return
name|vtst_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vtstq_s8
end_comment

begin_comment
comment|// CHECK: vtst.8 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint8x16_t
name|test_vtstq_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|)
block|{
return|return
name|vtstq_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vtstq_s16
end_comment

begin_comment
comment|// CHECK: vtst.16 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint16x8_t
name|test_vtstq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
return|return
name|vtstq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vtstq_s32
end_comment

begin_comment
comment|// CHECK: vtst.32 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint32x4_t
name|test_vtstq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
return|return
name|vtstq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vtstq_u8
end_comment

begin_comment
comment|// CHECK: vtst.8 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint8x16_t
name|test_vtstq_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|,
name|uint8x16_t
name|b
parameter_list|)
block|{
return|return
name|vtstq_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vtstq_u16
end_comment

begin_comment
comment|// CHECK: vtst.16 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint16x8_t
name|test_vtstq_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|)
block|{
return|return
name|vtstq_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vtstq_u32
end_comment

begin_comment
comment|// CHECK: vtst.32 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint32x4_t
name|test_vtstq_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|)
block|{
return|return
name|vtstq_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vtstq_p8
end_comment

begin_comment
comment|// CHECK: vtst.8 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint8x16_t
name|test_vtstq_p8
parameter_list|(
name|poly8x16_t
name|a
parameter_list|,
name|poly8x16_t
name|b
parameter_list|)
block|{
return|return
name|vtstq_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vtstq_p16
end_comment

begin_comment
comment|// CHECK: vtst.16 q{{[0-9]+}}, q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint16x8_t
name|test_vtstq_p16
parameter_list|(
name|poly16x8_t
name|a
parameter_list|,
name|poly16x8_t
name|b
parameter_list|)
block|{
return|return
name|vtstq_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vuzp_s8
end_comment

begin_comment
comment|// CHECK: vuzp.8 d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int8x8x2_t
name|test_vuzp_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
return|return
name|vuzp_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vuzp_s16
end_comment

begin_comment
comment|// CHECK: vuzp.16 d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int16x4x2_t
name|test_vuzp_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
return|return
name|vuzp_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vuzp_s32
end_comment

begin_comment
comment|// CHECK: {{vtrn|vuzp}}.32 d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int32x2x2_t
name|test_vuzp_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
return|return
name|vuzp_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vuzp_u8
end_comment

begin_comment
comment|// CHECK: vuzp.8 d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint8x8x2_t
name|test_vuzp_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|)
block|{
return|return
name|vuzp_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vuzp_u16
end_comment

begin_comment
comment|// CHECK: vuzp.16 d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint16x4x2_t
name|test_vuzp_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|)
block|{
return|return
name|vuzp_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vuzp_u32
end_comment

begin_comment
comment|// CHECK: {{vtrn|vuzp}}.32 d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint32x2x2_t
name|test_vuzp_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|)
block|{
return|return
name|vuzp_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vuzp_f32
end_comment

begin_comment
comment|// CHECK: {{vtrn|vuzp}}.32 d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|float32x2x2_t
name|test_vuzp_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32x2_t
name|b
parameter_list|)
block|{
return|return
name|vuzp_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vuzp_p8
end_comment

begin_comment
comment|// CHECK: vuzp.8 d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|poly8x8x2_t
name|test_vuzp_p8
parameter_list|(
name|poly8x8_t
name|a
parameter_list|,
name|poly8x8_t
name|b
parameter_list|)
block|{
return|return
name|vuzp_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vuzp_p16
end_comment

begin_comment
comment|// CHECK: vuzp.16 d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|poly16x4x2_t
name|test_vuzp_p16
parameter_list|(
name|poly16x4_t
name|a
parameter_list|,
name|poly16x4_t
name|b
parameter_list|)
block|{
return|return
name|vuzp_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vuzpq_s8
end_comment

begin_comment
comment|// CHECK: vuzp.8 q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int8x16x2_t
name|test_vuzpq_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|)
block|{
return|return
name|vuzpq_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vuzpq_s16
end_comment

begin_comment
comment|// CHECK: vuzp.16 q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int16x8x2_t
name|test_vuzpq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
return|return
name|vuzpq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vuzpq_s32
end_comment

begin_comment
comment|// CHECK: {{vtrn|vuzp}}.32 q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int32x4x2_t
name|test_vuzpq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
return|return
name|vuzpq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vuzpq_u8
end_comment

begin_comment
comment|// CHECK: vuzp.8 q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint8x16x2_t
name|test_vuzpq_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|,
name|uint8x16_t
name|b
parameter_list|)
block|{
return|return
name|vuzpq_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vuzpq_u16
end_comment

begin_comment
comment|// CHECK: vuzp.16 q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint16x8x2_t
name|test_vuzpq_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|)
block|{
return|return
name|vuzpq_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vuzpq_u32
end_comment

begin_comment
comment|// CHECK: {{vtrn|vuzp}}.32 q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint32x4x2_t
name|test_vuzpq_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|)
block|{
return|return
name|vuzpq_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vuzpq_f32
end_comment

begin_comment
comment|// CHECK: {{vtrn|vuzp}}.32 q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|float32x4x2_t
name|test_vuzpq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|,
name|float32x4_t
name|b
parameter_list|)
block|{
return|return
name|vuzpq_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vuzpq_p8
end_comment

begin_comment
comment|// CHECK: vuzp.8 q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|poly8x16x2_t
name|test_vuzpq_p8
parameter_list|(
name|poly8x16_t
name|a
parameter_list|,
name|poly8x16_t
name|b
parameter_list|)
block|{
return|return
name|vuzpq_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vuzpq_p16
end_comment

begin_comment
comment|// CHECK: vuzp.16 q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|poly16x8x2_t
name|test_vuzpq_p16
parameter_list|(
name|poly16x8_t
name|a
parameter_list|,
name|poly16x8_t
name|b
parameter_list|)
block|{
return|return
name|vuzpq_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vzip_s8
end_comment

begin_comment
comment|// CHECK: vzip.8 d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int8x8x2_t
name|test_vzip_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
return|return
name|vzip_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vzip_s16
end_comment

begin_comment
comment|// CHECK: vzip.16 d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int16x4x2_t
name|test_vzip_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
return|return
name|vzip_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vzip_s32
end_comment

begin_comment
comment|// CHECK: {{vtrn|vzip}}.32 d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|int32x2x2_t
name|test_vzip_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
return|return
name|vzip_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vzip_u8
end_comment

begin_comment
comment|// CHECK: vzip.8 d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint8x8x2_t
name|test_vzip_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|)
block|{
return|return
name|vzip_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vzip_u16
end_comment

begin_comment
comment|// CHECK: vzip.16 d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint16x4x2_t
name|test_vzip_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|)
block|{
return|return
name|vzip_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vzip_u32
end_comment

begin_comment
comment|// CHECK: {{vtrn|vzip}}.32 d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|uint32x2x2_t
name|test_vzip_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|)
block|{
return|return
name|vzip_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vzip_f32
end_comment

begin_comment
comment|// CHECK: {{vtrn|vzip}}.32 d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|float32x2x2_t
name|test_vzip_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32x2_t
name|b
parameter_list|)
block|{
return|return
name|vzip_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vzip_p8
end_comment

begin_comment
comment|// CHECK: vzip.8 d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|poly8x8x2_t
name|test_vzip_p8
parameter_list|(
name|poly8x8_t
name|a
parameter_list|,
name|poly8x8_t
name|b
parameter_list|)
block|{
return|return
name|vzip_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vzip_p16
end_comment

begin_comment
comment|// CHECK: vzip.16 d{{[0-9]+}}, d{{[0-9]+}}
end_comment

begin_function
name|poly16x4x2_t
name|test_vzip_p16
parameter_list|(
name|poly16x4_t
name|a
parameter_list|,
name|poly16x4_t
name|b
parameter_list|)
block|{
return|return
name|vzip_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vzipq_s8
end_comment

begin_comment
comment|// CHECK: vzip.8 q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int8x16x2_t
name|test_vzipq_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|)
block|{
return|return
name|vzipq_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vzipq_s16
end_comment

begin_comment
comment|// CHECK: vzip.16 q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int16x8x2_t
name|test_vzipq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
return|return
name|vzipq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vzipq_s32
end_comment

begin_comment
comment|// CHECK: {{vtrn|vzip}}.32 q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|int32x4x2_t
name|test_vzipq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
return|return
name|vzipq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vzipq_u8
end_comment

begin_comment
comment|// CHECK: vzip.8 q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint8x16x2_t
name|test_vzipq_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|,
name|uint8x16_t
name|b
parameter_list|)
block|{
return|return
name|vzipq_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vzipq_u16
end_comment

begin_comment
comment|// CHECK: vzip.16 q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint16x8x2_t
name|test_vzipq_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|)
block|{
return|return
name|vzipq_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vzipq_u32
end_comment

begin_comment
comment|// CHECK: {{vtrn|vzip}}.32 q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|uint32x4x2_t
name|test_vzipq_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|)
block|{
return|return
name|vzipq_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vzipq_f32
end_comment

begin_comment
comment|// CHECK: {{vtrn|vzip}}.32 q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|float32x4x2_t
name|test_vzipq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|,
name|float32x4_t
name|b
parameter_list|)
block|{
return|return
name|vzipq_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vzipq_p8
end_comment

begin_comment
comment|// CHECK: vzip.8 q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|poly8x16x2_t
name|test_vzipq_p8
parameter_list|(
name|poly8x16_t
name|a
parameter_list|,
name|poly8x16_t
name|b
parameter_list|)
block|{
return|return
name|vzipq_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vzipq_p16
end_comment

begin_comment
comment|// CHECK: vzip.16 q{{[0-9]+}}, q{{[0-9]+}}
end_comment

begin_function
name|poly16x8x2_t
name|test_vzipq_p16
parameter_list|(
name|poly16x8_t
name|a
parameter_list|,
name|poly16x8_t
name|b
parameter_list|)
block|{
return|return
name|vzipq_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

end_unit

