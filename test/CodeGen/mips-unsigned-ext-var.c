begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple mips64-unknown-linux -O2 -target-abi n64 -S -emit-llvm %s -o - | FileCheck %s -check-prefix=N64
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple mips64-unknown-linux -O2 -target-abi n32 -S -emit-llvm %s -o - | FileCheck %s -check-prefix=N32
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple mips-unknown-linux -O2 -target-abi o32 -S -emit-llvm %s -o - | FileCheck %s -check-prefix=O32
end_comment

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_function
name|unsigned
name|foo
parameter_list|(
name|int
name|x
parameter_list|,
modifier|...
parameter_list|)
block|{
name|va_list
name|valist
decl_stmt|;
name|va_start
argument_list|(
name|valist
argument_list|,
name|x
argument_list|)
expr_stmt|;
name|unsigned
name|a
decl_stmt|;
name|a
operator|=
name|va_arg
argument_list|(
name|valist
argument_list|,
name|unsigned
argument_list|)
expr_stmt|;
return|return
name|a
return|;
block|}
end_function

begin_function
name|void
name|foo1
parameter_list|()
block|{
name|unsigned
name|f
init|=
literal|0xffffffe0
decl_stmt|;
name|foo
argument_list|(
literal|1
argument_list|,
name|f
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|//N64: call i32 (i32, ...) @foo(i32 signext undef, i32 signext -32)
end_comment

begin_comment
comment|//N32: call i32 (i32, ...) @foo(i32 signext undef, i32 signext -32)
end_comment

begin_comment
comment|//O32: call i32 (i32, ...) @foo(i32 signext undef, i32 signext -32)
end_comment

end_unit

