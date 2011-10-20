begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1  %s -w -emit-llvm -o -
end_comment

begin_function
name|float
name|test
parameter_list|(
name|int
name|X
parameter_list|,
modifier|...
parameter_list|)
block|{
name|__builtin_va_list
name|ap
decl_stmt|;
name|float
name|F
decl_stmt|;
name|__builtin_va_start
argument_list|(
name|ap
argument_list|,
name|X
argument_list|)
expr_stmt|;
name|F
operator|=
name|__builtin_va_arg
argument_list|(
name|ap
argument_list|,
name|float
argument_list|)
expr_stmt|;
return|return
name|F
return|;
block|}
end_function

end_unit

