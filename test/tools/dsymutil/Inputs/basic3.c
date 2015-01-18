begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* For compilation instructions see basic1.c. */
end_comment

begin_decl_stmt
specifier|volatile
name|int
name|val
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|foo
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|unused2
parameter_list|()
block|{
return|return
name|foo
argument_list|(
name|val
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|inc
parameter_list|()
block|{
return|return
operator|++
name|val
return|;
block|}
end_function

begin_macro
name|__attribute__
argument_list|(
argument|(noinline)
argument_list|)
end_macro

begin_function
name|int
name|bar
parameter_list|(
name|int
name|arg
parameter_list|)
block|{
if|if
condition|(
name|arg
operator|>
literal|42
condition|)
return|return
name|inc
argument_list|()
return|;
return|return
name|foo
argument_list|(
name|val
operator|+
name|arg
argument_list|)
return|;
block|}
end_function

end_unit

