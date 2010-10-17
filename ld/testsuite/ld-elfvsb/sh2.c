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
comment|/* This variable is defined here, and shouldn't be used to resolve a    reference with non-default visibility in another shared library.  */
end_comment

begin_decl_stmt
name|int
name|visibility_com
init|=
literal|2
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

begin_ifdef
ifdef|#
directive|ifdef
name|DSO_DEFINE_TEST
end_ifdef

begin_function
name|int
name|visibility
parameter_list|()
block|{
return|return
literal|2
return|;
block|}
end_function

begin_decl_stmt
name|int
name|visibility_var
init|=
literal|2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|visibility_def
init|=
literal|2
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|visibility_func
parameter_list|()
block|{
return|return
literal|2
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HIDDEN_WEAK_TEST
end_ifdef

begin_decl_stmt
name|int
name|visibility_var_weak
init|=
literal|2
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|visibility_func_weak
parameter_list|()
block|{
return|return
literal|2
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

