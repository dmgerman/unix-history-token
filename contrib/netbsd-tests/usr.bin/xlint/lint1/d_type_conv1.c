begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Flag information-losing type conversion in argument lists */
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
name|long
name|long
name|x
init|=
literal|20
decl_stmt|;
name|f
argument_list|(
name|x
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

