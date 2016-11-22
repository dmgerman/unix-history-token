begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* default / lib implementation of 'tearDown()'  *  * SOLARIS does not support weak symbols -- need a real lib  * implemetation here.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|tearDown
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|tearDown
parameter_list|(
name|void
parameter_list|)
block|{
comment|/* empty on purpose */
block|}
end_function

end_unit

