begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* default / lib implementation of 'setUp()'  *  * SOLARIS does not support weak symbols -- need a real lib  * implemetation here.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|setUp
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|setUp
parameter_list|(
name|void
parameter_list|)
block|{
comment|/* empty on purpose */
block|}
end_function

begin_comment
comment|/* -*- that's all folks! -*- */
end_comment

end_unit

