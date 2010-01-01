begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -ast-dump %s 2>&1 | grep ImplicitCastExpr | count 2
end_comment

begin_function
name|int
name|foo
parameter_list|(
name|double
name|x
parameter_list|,
name|long
name|double
name|y
parameter_list|)
block|{
comment|// There needs to be an implicit cast on x here.
return|return
name|__builtin_isgreater
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
return|;
block|}
end_function

end_unit

