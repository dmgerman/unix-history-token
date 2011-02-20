begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -O2 -S %s -o - | grep call
end_comment

begin_function_decl
specifier|static
name|int
name|bar
parameter_list|(
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(noinline
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function
specifier|static
name|int
name|bar
parameter_list|(
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|)
block|{
return|return
name|x
operator|+
name|y
return|;
block|}
end_function

begin_function
name|int
name|foo
parameter_list|(
name|int
name|a
parameter_list|,
name|int
name|b
parameter_list|)
block|{
return|return
name|bar
argument_list|(
name|b
argument_list|,
name|a
argument_list|)
return|;
block|}
end_function

end_unit

