begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This is part of the shared library ld test.  This file becomes part    of a shared library.  */
end_comment

begin_comment
comment|/* This variable is defined here, and referenced by another file in    the shared library.  */
end_comment

begin_decl_stmt
name|int
name|shlibvar2
init|=
literal|4
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* This function is called by another file in the shared library.  */
end_comment

begin_function
name|int
name|shlib_shlibcalled
parameter_list|()
block|{
return|return
literal|5
return|;
block|}
end_function

end_unit

