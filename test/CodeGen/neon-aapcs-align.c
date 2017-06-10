begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple armv7a-none-eabi -target-feature +neon -emit-llvm -o - %s | FileCheck %s -check-prefix=CHECK -check-prefix=AAPCS
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple armv7a-none-gnueabi -target-feature +neon -emit-llvm -o - %s | FileCheck %s -check-prefix=CHECK -check-prefix=AAPCS
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple armv7a-none-freebsd -target-feature +neon -emit-llvm -o - %s | FileCheck %s -check-prefix=CHECK -check-prefix=AAPCS
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple armv7a-apple-ios -target-feature +neon -emit-llvm -o - %s | FileCheck %s -check-prefix=CHECK -check-prefix=DEFAULT
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple armv7a-none-android -target-feature +neon -emit-llvm -o - %s | FileCheck %s -check-prefix=CHECK -check-prefix=DEFAULT
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple armv7a-none-androideabi -target-feature +neon -emit-llvm -o - %s | FileCheck %s -check-prefix=CHECK -check-prefix=DEFAULT
end_comment

begin_include
include|#
directive|include
file|<arm_neon.h>
end_include

begin_comment
comment|// Neon types have 64-bit alignment
end_comment

begin_decl_stmt
name|int32x4_t
name|gl_b
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|t3
parameter_list|(
name|int32x4_t
modifier|*
name|src
parameter_list|)
block|{
comment|// CHECK: @t3
name|gl_b
operator|=
operator|*
name|src
expr_stmt|;
comment|// AAPCS: store<4 x i32> {{%.*}},<4 x i32>* @gl_b, align 8
comment|// DEFAULT: store<4 x i32> {{%.*}},<4 x i32>* @gl_b, align 16
block|}
end_function

end_unit

