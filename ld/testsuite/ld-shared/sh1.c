begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This is part of the shared library ld test.  This file becomes part    of a shared library.  */
end_comment

begin_comment
comment|/* This variable is supplied by the main program.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|XCOFF_TEST
end_ifndef

begin_decl_stmt
specifier|extern
name|int
name|mainvar
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This variable is defined in the shared library, and overridden by    the main program.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|XCOFF_TEST
end_ifndef

begin_decl_stmt
name|int
name|overriddenvar
init|=
operator|-
literal|1
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This variable is defined in the shared library.  */
end_comment

begin_decl_stmt
name|int
name|shlibvar1
init|=
literal|3
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* This variable is defined by another object in the shared library.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|shlibvar2
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* These functions return the values of the above variables as seen in    the shared library.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|XCOFF_TEST
end_ifndef

begin_function
name|int
name|shlib_mainvar
parameter_list|()
block|{
return|return
name|mainvar
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|XCOFF_TEST
end_ifndef

begin_function
name|int
name|shlib_overriddenvar
parameter_list|()
block|{
return|return
name|overriddenvar
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|int
name|shlib_shlibvar1
parameter_list|()
block|{
return|return
name|shlibvar1
return|;
block|}
end_function

begin_function
name|int
name|shlib_shlibvar2
parameter_list|()
block|{
return|return
name|shlibvar2
return|;
block|}
end_function

begin_comment
comment|/* This function calls a function defined by another object in the    shared library.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|shlib_shlibcalled
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|int
name|shlib_shlibcall
parameter_list|()
block|{
return|return
name|shlib_shlibcalled
argument_list|()
return|;
block|}
end_function

begin_ifndef
ifndef|#
directive|ifndef
name|XCOFF_TEST
end_ifndef

begin_comment
comment|/* This function calls a function defined in this object in the shared    library.  The main program will override the called function.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|shlib_overriddencall2
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|int
name|shlib_shlibcall2
parameter_list|()
block|{
return|return
name|shlib_overriddencall2
argument_list|()
return|;
block|}
end_function

begin_function
name|int
name|shlib_overriddencall2
parameter_list|()
block|{
return|return
literal|7
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This function calls a function defined by the main program.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|XCOFF_TEST
end_ifndef

begin_function_decl
specifier|extern
name|int
name|main_called
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|int
name|shlib_maincall
parameter_list|()
block|{
return|return
name|main_called
argument_list|()
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This function is passed a function pointer to shlib_mainvar.  It    confirms that the pointer compares equally.  */
end_comment

begin_function_decl
name|int
name|shlib_checkfunptr1
function_decl|(
name|p
function_decl|)
name|int
argument_list|(
argument|*p
argument_list|)
parameter_list|()
function_decl|;
end_function_decl

begin_block
block|{
return|return
name|p
operator|==
name|shlib_shlibvar1
return|;
block|}
end_block

begin_comment
comment|/* This function is passed a function pointer to main_called.  It    confirms that the pointer compares equally.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|XCOFF_TEST
end_ifndef

begin_function_decl
name|int
name|shlib_checkfunptr2
function_decl|(
name|p
function_decl|)
name|int
argument_list|(
argument|*p
argument_list|)
parameter_list|()
function_decl|;
end_function_decl

begin_block
block|{
return|return
name|p
operator|==
name|main_called
return|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This function returns a pointer to shlib_mainvar.  */
end_comment

begin_macro
name|int
argument_list|(
argument|*shlib_getfunptr1 ()
argument_list|)
end_macro

begin_expr_stmt
operator|(
operator|)
block|{
return|return
name|shlib_shlibvar1
return|;
block|}
end_expr_stmt

begin_comment
comment|/* This function returns a pointer to main_called.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|XCOFF_TEST
end_ifndef

begin_macro
name|int
argument_list|(
argument|*shlib_getfunptr2 ()
argument_list|)
end_macro

begin_expr_stmt
operator|(
operator|)
block|{
return|return
name|main_called
return|;
block|}
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This function makes sure that constant data and local functions    work.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__STDC__
end_ifndef

begin_define
define|#
directive|define
name|const
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|static
name|int
name|i
init|=
literal|6
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|str
init|=
literal|"Hello, world\n"
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|shlib_check
parameter_list|()
block|{
specifier|const
name|char
modifier|*
name|s1
decl_stmt|,
modifier|*
name|s2
decl_stmt|;
if|if
condition|(
name|i
operator|!=
literal|6
condition|)
return|return
literal|0
return|;
comment|/* To isolate the test, don't rely on any external functions, such      as strcmp.  */
name|s1
operator|=
literal|"Hello, world\n"
expr_stmt|;
name|s2
operator|=
name|str
expr_stmt|;
while|while
condition|(
operator|*
name|s1
operator|!=
literal|'\0'
condition|)
if|if
condition|(
operator|*
name|s1
operator|++
operator|!=
operator|*
name|s2
operator|++
condition|)
return|return
literal|0
return|;
if|if
condition|(
operator|*
name|s2
operator|!=
literal|'\0'
condition|)
return|return
literal|0
return|;
if|if
condition|(
name|shlib_shlibvar1
argument_list|()
operator|!=
literal|3
condition|)
return|return
literal|0
return|;
return|return
literal|1
return|;
block|}
end_function

end_unit

