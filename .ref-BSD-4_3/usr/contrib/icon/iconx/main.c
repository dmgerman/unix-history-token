begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * C startup program for Icon.  Just pass argv to mstart and let it  *  do the work.  */
end_comment

begin_function
name|main
parameter_list|(
name|argc
parameter_list|,
name|argv
parameter_list|)
name|int
name|argc
decl_stmt|;
name|char
modifier|*
modifier|*
name|argv
decl_stmt|;
block|{
name|mstart
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

