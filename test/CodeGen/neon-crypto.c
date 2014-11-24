begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple arm-none-linux-gnueabi -target-feature +neon \
end_comment

begin_comment
comment|// RUN:  -target-feature +crypto -target-cpu cortex-a57 -emit-llvm -O1 -o - %s | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple arm64-none-linux-gnu -target-feature +neon \
end_comment

begin_comment
comment|// RUN:   -target-feature +crypto -emit-llvm -O1 -o - %s | FileCheck %s
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -triple arm64-none-linux-gnu -target-feature +neon \
end_comment

begin_comment
comment|// RUN:   -S -O3 -o - %s 2>&1 | FileCheck --check-prefix=CHECK-NO-CRYPTO %s
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
name|uint8x16_t
name|test_vaeseq_u8
parameter_list|(
name|uint8x16_t
name|data
parameter_list|,
name|uint8x16_t
name|key
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_vaeseq_u8
comment|// CHECK-NO-CRYPTO: warning: implicit declaration of function 'vaeseq_u8' is invalid in C99
return|return
name|vaeseq_u8
argument_list|(
name|data
argument_list|,
name|key
argument_list|)
return|;
comment|// CHECK: call<16 x i8> @llvm.{{arm.neon|aarch64.crypto}}.aese(<16 x i8> %data,<16 x i8> %key)
block|}
end_function

begin_function
name|uint8x16_t
name|test_vaesdq_u8
parameter_list|(
name|uint8x16_t
name|data
parameter_list|,
name|uint8x16_t
name|key
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_vaesdq_u8
return|return
name|vaesdq_u8
argument_list|(
name|data
argument_list|,
name|key
argument_list|)
return|;
comment|// CHECK: call<16 x i8> @llvm.{{arm.neon|aarch64.crypto}}.aesd(<16 x i8> %data,<16 x i8> %key)
block|}
end_function

begin_function
name|uint8x16_t
name|test_vaesmcq_u8
parameter_list|(
name|uint8x16_t
name|data
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_vaesmcq_u8
return|return
name|vaesmcq_u8
argument_list|(
name|data
argument_list|)
return|;
comment|// CHECK: call<16 x i8> @llvm.{{arm.neon|aarch64.crypto}}.aesmc(<16 x i8> %data)
block|}
end_function

begin_function
name|uint8x16_t
name|test_vaesimcq_u8
parameter_list|(
name|uint8x16_t
name|data
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_vaesimcq_u8
return|return
name|vaesimcq_u8
argument_list|(
name|data
argument_list|)
return|;
comment|// CHECK: call<16 x i8> @llvm.{{arm.neon|aarch64.crypto}}.aesimc(<16 x i8> %data)
block|}
end_function

begin_function
name|uint32_t
name|test_vsha1h_u32
parameter_list|(
name|uint32_t
name|hash_e
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_vsha1h_u32
return|return
name|vsha1h_u32
argument_list|(
name|hash_e
argument_list|)
return|;
comment|// CHECK: call i32 @llvm.{{arm.neon|aarch64.crypto}}.sha1h(i32 %hash_e)
block|}
end_function

begin_function
name|uint32x4_t
name|test_vsha1su1q_u32
parameter_list|(
name|uint32x4_t
name|w0_3
parameter_list|,
name|uint32x4_t
name|w12_15
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_vsha1su1q_u32
return|return
name|vsha1su1q_u32
argument_list|(
name|w0_3
argument_list|,
name|w12_15
argument_list|)
return|;
comment|// CHECK: call<4 x i32> @llvm.{{arm.neon|aarch64.crypto}}.sha1su1(<4 x i32> %w0_3,<4 x i32> %w12_15)
block|}
end_function

begin_function
name|uint32x4_t
name|test_vsha256su0q_u32
parameter_list|(
name|uint32x4_t
name|w0_3
parameter_list|,
name|uint32x4_t
name|w4_7
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_vsha256su0q_u32
return|return
name|vsha256su0q_u32
argument_list|(
name|w0_3
argument_list|,
name|w4_7
argument_list|)
return|;
comment|// CHECK: call<4 x i32> @llvm.{{arm.neon|aarch64.crypto}}.sha256su0(<4 x i32> %w0_3,<4 x i32> %w4_7)
block|}
end_function

begin_function
name|uint32x4_t
name|test_vsha1cq_u32
parameter_list|(
name|uint32x4_t
name|hash_abcd
parameter_list|,
name|uint32_t
name|hash_e
parameter_list|,
name|uint32x4_t
name|wk
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_vsha1cq_u32
return|return
name|vsha1cq_u32
argument_list|(
name|hash_abcd
argument_list|,
name|hash_e
argument_list|,
name|wk
argument_list|)
return|;
comment|// CHECK: call<4 x i32> @llvm.{{arm.neon|aarch64.crypto}}.sha1c(<4 x i32> %hash_abcd, i32 %hash_e,<4 x i32> %wk)
block|}
end_function

begin_function
name|uint32x4_t
name|test_vsha1pq_u32
parameter_list|(
name|uint32x4_t
name|hash_abcd
parameter_list|,
name|uint32_t
name|hash_e
parameter_list|,
name|uint32x4_t
name|wk
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_vsha1pq_u32
return|return
name|vsha1pq_u32
argument_list|(
name|hash_abcd
argument_list|,
name|hash_e
argument_list|,
name|wk
argument_list|)
return|;
comment|// CHECK: call<4 x i32> @llvm.{{arm.neon|aarch64.crypto}}.sha1p(<4 x i32> %hash_abcd, i32 %hash_e,<4 x i32> %wk)
block|}
end_function

begin_function
name|uint32x4_t
name|test_vsha1mq_u32
parameter_list|(
name|uint32x4_t
name|hash_abcd
parameter_list|,
name|uint32_t
name|hash_e
parameter_list|,
name|uint32x4_t
name|wk
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_vsha1mq_u32
return|return
name|vsha1mq_u32
argument_list|(
name|hash_abcd
argument_list|,
name|hash_e
argument_list|,
name|wk
argument_list|)
return|;
comment|// CHECK: call<4 x i32> @llvm.{{arm.neon|aarch64.crypto}}.sha1m(<4 x i32> %hash_abcd, i32 %hash_e,<4 x i32> %wk)
block|}
end_function

begin_function
name|uint32x4_t
name|test_vsha1su0q_u32
parameter_list|(
name|uint32x4_t
name|w0_3
parameter_list|,
name|uint32x4_t
name|w4_7
parameter_list|,
name|uint32x4_t
name|w8_11
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_vsha1su0q_u32
return|return
name|vsha1su0q_u32
argument_list|(
name|w0_3
argument_list|,
name|w4_7
argument_list|,
name|w8_11
argument_list|)
return|;
comment|// CHECK: call<4 x i32> @llvm.{{arm.neon|aarch64.crypto}}.sha1su0(<4 x i32> %w0_3,<4 x i32> %w4_7,<4 x i32> %w8_11)
block|}
end_function

begin_function
name|uint32x4_t
name|test_vsha256hq_u32
parameter_list|(
name|uint32x4_t
name|hash_abcd
parameter_list|,
name|uint32x4_t
name|hash_efgh
parameter_list|,
name|uint32x4_t
name|wk
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_vsha256hq_u32
return|return
name|vsha256hq_u32
argument_list|(
name|hash_abcd
argument_list|,
name|hash_efgh
argument_list|,
name|wk
argument_list|)
return|;
comment|// CHECK: call<4 x i32> @llvm.{{arm.neon|aarch64.crypto}}.sha256h(<4 x i32> %hash_abcd,<4 x i32> %hash_efgh,<4 x i32> %wk)
block|}
end_function

begin_function
name|uint32x4_t
name|test_vsha256h2q_u32
parameter_list|(
name|uint32x4_t
name|hash_efgh
parameter_list|,
name|uint32x4_t
name|hash_abcd
parameter_list|,
name|uint32x4_t
name|wk
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_vsha256h2q_u32
return|return
name|vsha256h2q_u32
argument_list|(
name|hash_efgh
argument_list|,
name|hash_abcd
argument_list|,
name|wk
argument_list|)
return|;
comment|// CHECK: call<4 x i32> @llvm.{{arm.neon|aarch64.crypto}}.sha256h2(<4 x i32> %hash_efgh,<4 x i32> %hash_abcd,<4 x i32> %wk)
block|}
end_function

begin_function
name|uint32x4_t
name|test_vsha256su1q_u32
parameter_list|(
name|uint32x4_t
name|w0_3
parameter_list|,
name|uint32x4_t
name|w8_11
parameter_list|,
name|uint32x4_t
name|w12_15
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_vsha256su1q_u32
return|return
name|vsha256su1q_u32
argument_list|(
name|w0_3
argument_list|,
name|w8_11
argument_list|,
name|w12_15
argument_list|)
return|;
comment|// CHECK: call<4 x i32> @llvm.{{arm.neon|aarch64.crypto}}.sha256su1(<4 x i32> %w0_3,<4 x i32> %w8_11,<4 x i32> %w12_15)
block|}
end_function

end_unit

