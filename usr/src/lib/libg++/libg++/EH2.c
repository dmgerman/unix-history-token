begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Unhandled exceptions cause the program to abort. Argument FILENAME is the name of the file that caught the exception. Argument LINENO is the line number at which the exception was caught. */
end_comment

begin_function_decl
specifier|extern
specifier|volatile
name|void
name|abort
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|void
name|__unhandled_exception
parameter_list|(
name|char
modifier|*
name|filename
parameter_list|,
name|int
name|lineno
parameter_list|)
block|{
name|abort
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
name|void
name|__raise_exception
parameter_list|(
name|void
modifier|*
modifier|*
name|addr
parameter_list|,
name|void
modifier|*
name|id
parameter_list|)
block|{
operator|*
name|addr
operator|=
name|id
expr_stmt|;
block|}
end_function

end_unit

