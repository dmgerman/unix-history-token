begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// This file is erroneous, but should not cause the compiler to ICE.
end_comment

begin_comment
comment|// PR481
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -o /dev/null
end_comment

begin_function
name|int
name|flags
parameter_list|(
name|int
name|a
parameter_list|,
name|int
name|b
parameter_list|,
modifier|...
parameter_list|)
block|{
name|__builtin_va_list
name|args
decl_stmt|;
name|__builtin_va_start
argument_list|(
name|args
argument_list|,
name|a
argument_list|)
expr_stmt|;
comment|// not the last named arg
name|foo
argument_list|(
name|args
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

