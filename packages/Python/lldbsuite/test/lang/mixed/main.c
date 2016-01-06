begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_function_decl
name|int
name|foo
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|static
name|int
name|static_value
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|bar
parameter_list|()
block|{
name|static_value
operator|++
expr_stmt|;
return|return
name|static_value
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
specifier|const
modifier|*
name|argv
index|[]
parameter_list|)
block|{
name|bar
argument_list|()
expr_stmt|;
comment|// breakpoint_in_main
return|return
name|foo
argument_list|()
return|;
block|}
end_function

end_unit

