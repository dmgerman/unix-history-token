begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_dfsan -m64 %s -o %t
end_comment

begin_comment
comment|// RUN: not %run %t 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// RUN: %run %t foo
end_comment

begin_comment
comment|// RUN: %clang_dfsan -mllvm -dfsan-args-abi -m64 %s -o %t
end_comment

begin_comment
comment|// RUN: not %run %t 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// RUN: %run %t foo
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_function
name|int
name|do_nothing
parameter_list|(
specifier|const
name|char
modifier|*
name|format
parameter_list|,
modifier|...
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
name|int
function_decl|(
modifier|*
name|fp
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
if|if
condition|(
name|argc
operator|>
literal|1
condition|)
name|fp
operator|=
name|do_nothing
expr_stmt|;
else|else
name|fp
operator|=
name|printf
expr_stmt|;
comment|// CHECK: FATAL: DataFlowSanitizer: unsupported indirect call to vararg function printf
name|fp
argument_list|(
literal|"hello %s\n"
argument_list|,
literal|"world"
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

