begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|NULL
end_ifndef

begin_define
define|#
directive|define
name|NULL
value|((void *) 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

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

begin_ifdef
ifdef|#
directive|ifdef
name|SHARED
end_ifdef

begin_comment
comment|/* SHARED is defined if we are compiling with -fpic/-fPIC.  */
end_comment

begin_decl_stmt
name|int
name|overriddenvar
init|=
operator|-
literal|1
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Without -fpic, newer versions of gcc assume that we are not    compiling for a shared library, and thus that overriddenvar is    local.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|overriddenvar
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

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

begin_ifdef
ifdef|#
directive|ifdef
name|SHARED
end_ifdef

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

begin_ifdef
ifdef|#
directive|ifdef
name|HIDDEN_WEAK_TEST
end_ifdef

begin_define
define|#
directive|define
name|HIDDEN_UNDEF_TEST
end_define

begin_define
define|#
directive|define
name|WEAK_TEST
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|PROTECTED_WEAK_TEST
end_ifdef

begin_define
define|#
directive|define
name|PROTECTED_UNDEF_TEST
end_define

begin_define
define|#
directive|define
name|WEAK_TEST
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HIDDEN_UNDEF_TEST
argument_list|)
operator|||
name|defined
argument_list|(
name|PROTECTED_UNDEF_TEST
argument_list|)
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|WEAK_TEST
end_ifdef

begin_pragma
pragma|#
directive|pragma
name|weak
name|visibility
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|int
name|visibility
parameter_list|()
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

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

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HIDDEN_NORMAL_TEST
end_ifdef

begin_asm
asm|asm (".hidden visibility_normal");
end_asm

begin_function
name|int
name|visibility_normal
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

begin_function
name|int
name|visibility_checkfunptr
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|WEAK_TEST
return|return
literal|1
return|;
else|#
directive|else
ifdef|#
directive|ifdef
name|HIDDEN_NORMAL_TEST
name|int
function_decl|(
modifier|*
name|v
function_decl|)
parameter_list|()
init|=
name|visibility_normal
function_decl|;
else|#
directive|else
name|int
function_decl|(
modifier|*
name|v
function_decl|)
parameter_list|()
init|=
name|visibility
function_decl|;
endif|#
directive|endif
return|return
call|(
modifier|*
name|v
call|)
argument_list|()
operator|==
literal|2
return|;
endif|#
directive|endif
block|}
end_function

begin_function
name|int
name|visibility_check
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|WEAK_TEST
if|if
condition|(
operator|&
name|visibility
condition|)
return|return
name|visibility
argument_list|()
operator|==
literal|1
return|;
else|else
return|return
literal|1
return|;
else|#
directive|else
ifdef|#
directive|ifdef
name|HIDDEN_NORMAL_TEST
return|return
name|visibility_normal
argument_list|()
operator|==
literal|2
return|;
else|#
directive|else
return|return
name|visibility
argument_list|()
operator|==
literal|2
return|;
endif|#
directive|endif
endif|#
directive|endif
block|}
end_function

begin_function
name|void
modifier|*
name|visibility_funptr
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|WEAK_TEST
if|if
condition|(
operator|&
name|visibility
operator|==
name|NULL
condition|)
return|return
name|NULL
return|;
else|else
endif|#
directive|endif
return|return
name|visibility
return|;
block|}
end_function

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HIDDEN_UNDEF_TEST
argument_list|)
operator|||
name|defined
argument_list|(
name|PROTECTED_UNDEF_TEST
argument_list|)
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|WEAK_TEST
end_ifdef

begin_pragma
pragma|#
directive|pragma
name|weak
name|visibility_var
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|visibility_var
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|int
name|visibility_var
init|=
literal|2
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HIDDEN_NORMAL_TEST
end_ifdef

begin_asm
asm|asm (".hidden visibility_var_normal");
end_asm

begin_decl_stmt
name|int
name|visibility_var_normal
init|=
literal|2
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|int
name|visibility_checkvarptr
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|WEAK_TEST
if|if
condition|(
operator|&
name|visibility_var
condition|)
return|return
name|visibility_var
operator|==
literal|1
return|;
else|else
return|return
literal|1
return|;
else|#
directive|else
ifdef|#
directive|ifdef
name|HIDDEN_NORMAL_TEST
name|int
modifier|*
name|v
init|=
operator|&
name|visibility_var_normal
decl_stmt|;
else|#
directive|else
name|int
modifier|*
name|v
init|=
operator|&
name|visibility_var
decl_stmt|;
endif|#
directive|endif
return|return
operator|*
name|v
operator|==
literal|2
return|;
endif|#
directive|endif
block|}
end_function

begin_function
name|int
name|visibility_checkvar
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|WEAK_TEST
return|return
literal|1
return|;
else|#
directive|else
ifdef|#
directive|ifdef
name|HIDDEN_NORMAL_TEST
return|return
name|visibility_var_normal
operator|==
literal|2
return|;
else|#
directive|else
return|return
name|visibility_var
operator|==
literal|2
return|;
endif|#
directive|endif
endif|#
directive|endif
block|}
end_function

begin_function
name|void
modifier|*
name|visibility_varptr
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|WEAK_TEST
if|if
condition|(
operator|&
name|visibility_var
operator|==
name|NULL
condition|)
return|return
name|NULL
return|;
else|else
endif|#
directive|endif
return|return
operator|&
name|visibility_var
return|;
block|}
end_function

begin_function
name|int
name|visibility_varval
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|WEAK_TEST
if|if
condition|(
operator|&
name|visibility_var
operator|==
name|NULL
condition|)
return|return
literal|0
return|;
else|else
endif|#
directive|endif
return|return
name|visibility_var
return|;
block|}
end_function

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HIDDEN_TEST
argument_list|)
operator|||
name|defined
argument_list|(
name|HIDDEN_UNDEF_TEST
argument_list|)
end_if

begin_asm
asm|asm (".hidden visibility");
end_asm

begin_asm
asm|asm (".hidden visibility_var");
end_asm

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|defined
argument_list|(
name|PROTECTED_TEST
argument_list|)
operator|||
name|defined
argument_list|(
name|PROTECTED_UNDEF_TEST
argument_list|)
operator|||
name|defined
argument_list|(
name|PROTECTED_WEAK_TEST
argument_list|)
end_if

begin_asm
asm|asm (".protected visibility");
end_asm

begin_asm
asm|asm (".protected visibility_var");
end_asm

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HIDDEN_NORMAL_TEST
end_ifdef

begin_decl_stmt
name|int
name|shlib_visibility_com
decl_stmt|;
end_decl_stmt

begin_asm
asm|asm (".hidden shlib_visibility_com");
end_asm

begin_function
name|int
name|shlib_visibility_checkcom
parameter_list|()
block|{
return|return
name|shlib_visibility_com
operator|==
literal|0
return|;
block|}
end_function

begin_function
name|int
name|shlib_visibility_checkweak
parameter_list|()
block|{
return|return
literal|1
return|;
block|}
end_function

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|HIDDEN_WEAK_TEST
argument_list|)
end_elif

begin_pragma
pragma|#
directive|pragma
name|weak
name|shlib_visibility_undef_var_weak
end_pragma

begin_decl_stmt
specifier|extern
name|int
name|shlib_visibility_undef_var_weak
decl_stmt|;
end_decl_stmt

begin_asm
asm|asm (".hidden shlib_visibility_undef_var_weak");
end_asm

begin_pragma
pragma|#
directive|pragma
name|weak
name|shlib_visibility_undef_func_weak
end_pragma

begin_function_decl
specifier|extern
name|int
name|shlib_visibility_undef_func_weak
parameter_list|()
function_decl|;
end_function_decl

begin_asm
asm|asm (".hidden shlib_visibility_undef_func_weak");
end_asm

begin_pragma
pragma|#
directive|pragma
name|weak
name|shlib_visibility_var_weak
end_pragma

begin_decl_stmt
specifier|extern
name|int
name|shlib_visibility_var_weak
decl_stmt|;
end_decl_stmt

begin_asm
asm|asm (".hidden shlib_visibility_var_weak");
end_asm

begin_pragma
pragma|#
directive|pragma
name|weak
name|shlib_visibility_func_weak
end_pragma

begin_function_decl
specifier|extern
name|int
name|shlib_visibility_func_weak
parameter_list|()
function_decl|;
end_function_decl

begin_asm
asm|asm (".hidden shlib_visibility_func_weak");
end_asm

begin_function
name|int
name|shlib_visibility_checkcom
parameter_list|()
block|{
return|return
literal|1
return|;
block|}
end_function

begin_function
name|int
name|shlib_visibility_checkweak
parameter_list|()
block|{
return|return
operator|&
name|shlib_visibility_undef_var_weak
operator|==
name|NULL
operator|&&
operator|&
name|shlib_visibility_undef_func_weak
operator|==
name|NULL
operator|&&
operator|&
name|shlib_visibility_func_weak
operator|==
name|NULL
operator|&&
operator|&
name|shlib_visibility_var_weak
operator|==
name|NULL
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_function
name|int
name|shlib_visibility_checkcom
parameter_list|()
block|{
return|return
literal|1
return|;
block|}
end_function

begin_function
name|int
name|shlib_visibility_checkweak
parameter_list|()
block|{
return|return
literal|1
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
name|PROTECTED_TEST
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|SHARED
end_ifdef

begin_decl_stmt
name|int
name|shared_data
init|=
literal|100
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|extern
name|int
name|shared_data
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|int
modifier|*
name|shared_data_p
parameter_list|()
block|{
return|return
operator|&
name|shared_data
return|;
block|}
end_function

begin_function
name|int
name|shared_func
parameter_list|()
block|{
return|return
literal|100
return|;
block|}
end_function

begin_function
name|void
modifier|*
name|shared_func_p
parameter_list|()
block|{
return|return
name|shared_func
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

