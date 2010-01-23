begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// PR: 6058
end_comment

begin_comment
comment|// RUN: %llvmgcc -g -S %s -o - | llc -O0 -o /dev/null
end_comment

begin_function_decl
specifier|static
specifier|inline
name|int
name|foo
parameter_list|(
name|double
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(always_inline
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function
specifier|static
specifier|inline
name|int
name|foo
parameter_list|(
name|double
name|__x
parameter_list|)
block|{
return|return
name|__x
return|;
block|}
end_function

begin_function
name|void
name|bar
parameter_list|(
name|double
name|x
parameter_list|)
block|{
name|foo
argument_list|(
name|x
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

