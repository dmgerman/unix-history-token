begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_function_decl
name|double
name|cabs
parameter_list|(
name|double
specifier|_Complex
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|double
name|cabs
parameter_list|(
name|double
specifier|_Complex
name|foo
parameter_list|)
block|{
name|double
name|d
init|=
name|__real__
name|foo
decl_stmt|;
return|return
name|d
operator|+
literal|0.1fi
return|;
block|}
end_function

end_unit

