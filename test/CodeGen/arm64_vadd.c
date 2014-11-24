begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -O1 -triple arm64-apple-ios7 -target-feature +neon -ffreestanding -S -o - -emit-llvm %s | FileCheck %s
end_comment

begin_comment
comment|// Test ARM64 SIMD add intrinsics
end_comment

begin_include
include|#
directive|include
file|<arm_neon.h>
end_include

begin_function
name|int64_t
name|test_vaddlv_s32
parameter_list|(
name|int32x2_t
name|a1
parameter_list|)
block|{
comment|// CHECK: test_vaddlv_s32
return|return
name|vaddlv_s32
argument_list|(
name|a1
argument_list|)
return|;
comment|// CHECK: llvm.aarch64.neon.saddlv.i64.v2i32
comment|// CHECK-NEXT: ret
block|}
end_function

begin_function
name|uint64_t
name|test_vaddlv_u32
parameter_list|(
name|uint32x2_t
name|a1
parameter_list|)
block|{
comment|// CHECK: test_vaddlv_u32
return|return
name|vaddlv_u32
argument_list|(
name|a1
argument_list|)
return|;
comment|// CHECK: llvm.aarch64.neon.uaddlv.i64.v2i32
comment|// CHECK-NEXT: ret
block|}
end_function

begin_function
name|int8_t
name|test_vaddv_s8
parameter_list|(
name|int8x8_t
name|a1
parameter_list|)
block|{
comment|// CHECK: test_vaddv_s8
return|return
name|vaddv_s8
argument_list|(
name|a1
argument_list|)
return|;
comment|// CHECK: llvm.aarch64.neon.saddv.i32.v8i8
comment|// don't check for return here (there's a trunc?)
block|}
end_function

begin_function
name|int16_t
name|test_vaddv_s16
parameter_list|(
name|int16x4_t
name|a1
parameter_list|)
block|{
comment|// CHECK: test_vaddv_s16
return|return
name|vaddv_s16
argument_list|(
name|a1
argument_list|)
return|;
comment|// CHECK: llvm.aarch64.neon.saddv.i32.v4i16
comment|// don't check for return here (there's a trunc?)
block|}
end_function

begin_function
name|int32_t
name|test_vaddv_s32
parameter_list|(
name|int32x2_t
name|a1
parameter_list|)
block|{
comment|// CHECK: test_vaddv_s32
return|return
name|vaddv_s32
argument_list|(
name|a1
argument_list|)
return|;
comment|// CHECK: llvm.aarch64.neon.saddv.i32.v2i32
comment|// CHECK-NEXT: ret
block|}
end_function

begin_function
name|uint8_t
name|test_vaddv_u8
parameter_list|(
name|int8x8_t
name|a1
parameter_list|)
block|{
comment|// CHECK: test_vaddv_u8
return|return
name|vaddv_u8
argument_list|(
name|a1
argument_list|)
return|;
comment|// CHECK: llvm.aarch64.neon.uaddv.i32.v8i8
comment|// don't check for return here (there's a trunc?)
block|}
end_function

begin_function
name|uint16_t
name|test_vaddv_u16
parameter_list|(
name|int16x4_t
name|a1
parameter_list|)
block|{
comment|// CHECK: test_vaddv_u16
return|return
name|vaddv_u16
argument_list|(
name|a1
argument_list|)
return|;
comment|// CHECK: llvm.aarch64.neon.uaddv.i32.v4i16
comment|// don't check for return here (there's a trunc?)
block|}
end_function

begin_function
name|uint32_t
name|test_vaddv_u32
parameter_list|(
name|int32x2_t
name|a1
parameter_list|)
block|{
comment|// CHECK: test_vaddv_u32
return|return
name|vaddv_u32
argument_list|(
name|a1
argument_list|)
return|;
comment|// CHECK: llvm.aarch64.neon.uaddv.i32.v2i32
comment|// CHECK-NEXT: ret
block|}
end_function

begin_function
name|int8_t
name|test_vaddvq_s8
parameter_list|(
name|int8x16_t
name|a1
parameter_list|)
block|{
comment|// CHECK: test_vaddvq_s8
return|return
name|vaddvq_s8
argument_list|(
name|a1
argument_list|)
return|;
comment|// CHECK: llvm.aarch64.neon.saddv.i32.v16i8
comment|// don't check for return here (there's a trunc?)
block|}
end_function

begin_function
name|int16_t
name|test_vaddvq_s16
parameter_list|(
name|int16x8_t
name|a1
parameter_list|)
block|{
comment|// CHECK: test_vaddvq_s16
return|return
name|vaddvq_s16
argument_list|(
name|a1
argument_list|)
return|;
comment|// CHECK: llvm.aarch64.neon.saddv.i32.v8i16
comment|// don't check for return here (there's a trunc?)
block|}
end_function

begin_function
name|int32_t
name|test_vaddvq_s32
parameter_list|(
name|int32x4_t
name|a1
parameter_list|)
block|{
comment|// CHECK: test_vaddvq_s32
return|return
name|vaddvq_s32
argument_list|(
name|a1
argument_list|)
return|;
comment|// CHECK: llvm.aarch64.neon.saddv.i32.v4i32
comment|// CHECK-NEXT: ret
block|}
end_function

begin_function
name|uint8_t
name|test_vaddvq_u8
parameter_list|(
name|int8x16_t
name|a1
parameter_list|)
block|{
comment|// CHECK: test_vaddvq_u8
return|return
name|vaddvq_u8
argument_list|(
name|a1
argument_list|)
return|;
comment|// CHECK: llvm.aarch64.neon.uaddv.i32.v16i8
comment|// don't check for return here (there's a trunc?)
block|}
end_function

begin_function
name|uint16_t
name|test_vaddvq_u16
parameter_list|(
name|int16x8_t
name|a1
parameter_list|)
block|{
comment|// CHECK: test_vaddvq_u16
return|return
name|vaddvq_u16
argument_list|(
name|a1
argument_list|)
return|;
comment|// CHECK: llvm.aarch64.neon.uaddv.i32.v8i16
comment|// don't check for return here (there's a trunc?)
block|}
end_function

begin_function
name|uint32_t
name|test_vaddvq_u32
parameter_list|(
name|int32x4_t
name|a1
parameter_list|)
block|{
comment|// CHECK: test_vaddvq_u32
return|return
name|vaddvq_u32
argument_list|(
name|a1
argument_list|)
return|;
comment|// CHECK: llvm.aarch64.neon.uaddv.i32.v4i32
comment|// CHECK-NEXT: ret
block|}
end_function

end_unit

