begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Flag information-losing constant conversion in argument lists */
end_comment

begin_function_decl
name|int
name|f
parameter_list|(
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|should_fail
parameter_list|()
block|{
name|f
argument_list|(
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

