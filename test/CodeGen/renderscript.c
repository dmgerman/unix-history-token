begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -triple=renderscript32-none-linux-gnueabi -emit-llvm -o - -Werror | FileCheck %s -check-prefix=CHECK-RS32
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -triple=renderscript64-none-linux-android -emit-llvm -o - -Werror | FileCheck %s -check-prefix=CHECK-RS64
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -triple=armv7-none-linux-gnueabi -emit-llvm -o - -Werror | FileCheck %s -check-prefix=CHECK-ARM
end_comment

begin_comment
comment|// Ensure that the bitcode has the correct triple
end_comment

begin_comment
comment|// CHECK-RS32: target triple = "armv7-none-linux-gnueabi"
end_comment

begin_comment
comment|// CHECK-RS64: target triple = "aarch64-none-linux-android"
end_comment

begin_comment
comment|// CHECK-ARM: target triple = "armv7-none-linux-gnueabi"
end_comment

begin_comment
comment|// Ensure that long data type has 8-byte size and alignment in RenderScript
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__RENDERSCRIPT__
end_ifdef

begin_define
define|#
directive|define
name|LONG_WIDTH_AND_ALIGN
value|8
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LONG_WIDTH_AND_ALIGN
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_assert
assert|_Static_assert
argument_list|(
sizeof|sizeof
argument_list|(
name|long
argument_list|)
operator|==
name|LONG_WIDTH_AND_ALIGN
argument_list|,
literal|"sizeof long is wrong"
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
alignof|_Alignof
argument_list|(
name|long
argument_list|)
operator|==
name|LONG_WIDTH_AND_ALIGN
argument_list|,
literal|"sizeof long is wrong"
argument_list|)
assert|;
end_assert

begin_comment
comment|// CHECK-RS32: i64 @test_long(i64 %v)
end_comment

begin_comment
comment|// CHECK-RS64: i64 @test_long(i64 %v)
end_comment

begin_comment
comment|// CHECK-ARM: i32 @test_long(i32 %v)
end_comment

begin_function
name|long
name|test_long
parameter_list|(
name|long
name|v
parameter_list|)
block|{
return|return
name|v
operator|+
literal|1
return|;
block|}
end_function

end_unit

