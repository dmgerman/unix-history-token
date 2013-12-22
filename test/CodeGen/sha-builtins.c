begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -O3 -triple=x86_64-unknown-unknown -target-feature +sha -emit-llvm -o - | FileCheck %s
end_comment

begin_comment
comment|// Don't include mm_malloc.h, it's system specific.
end_comment

begin_define
define|#
directive|define
name|__MM_MALLOC_H
end_define

begin_include
include|#
directive|include
file|<immintrin.h>
end_include

begin_function
name|__m128i
name|test_sha1rnds4
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK: call<4 x i32> @llvm.x86.sha1rnds4
return|return
name|_mm_sha1rnds4_epu32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|8
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_sha1nexte
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK: call<4 x i32> @llvm.x86.sha1nexte
return|return
name|_mm_sha1nexte_epu32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_sha1msg1
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK: call<4 x i32> @llvm.x86.sha1msg1
return|return
name|_mm_sha1msg1_epu32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_sha1msg2
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK: call<4 x i32> @llvm.x86.sha1msg2
return|return
name|_mm_sha1msg2_epu32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_sha256rnds2
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|,
name|__m128i
name|c
parameter_list|)
block|{
comment|// CHECK: call<4 x i32> @llvm.x86.sha256rnds2
return|return
name|_mm_sha256rnds2_epu32
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

begin_function
name|__m128i
name|test_sha256msg1
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK: call<4 x i32> @llvm.x86.sha256msg1
return|return
name|_mm_sha256msg1_epu32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_sha256msg2
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK: call<4 x i32> @llvm.x86.sha256msg2
return|return
name|_mm_sha256msg2_epu32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

end_unit

