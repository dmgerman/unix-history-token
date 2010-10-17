begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Test program that goes with test7.so  */
end_comment

begin_function_decl
specifier|extern
name|int
name|hide_a
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|show_b
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|int
name|main
parameter_list|()
block|{
return|return
name|hide_a
argument_list|(
literal|1
argument_list|)
operator|+
name|show_b
argument_list|(
literal|1
argument_list|)
return|;
return|return
literal|0
return|;
block|}
end_function

end_unit

