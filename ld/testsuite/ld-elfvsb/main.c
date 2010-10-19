begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifdef
ifdef|#
directive|ifdef
name|PROTECTED_CHECK
end_ifdef

begin_include
include|#
directive|include
file|<features.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_function
name|int
name|main
parameter_list|(
name|void
parameter_list|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|__GLIBC__
argument_list|)
operator|&&
operator|(
name|__GLIBC__
operator|>
literal|2
expr|\
operator|||
operator|(
name|__GLIBC__
operator|==
literal|2
expr|\
operator|&&
name|__GLIBC_MINOR__
operator|>=
literal|2
operator|)
operator|)
name|puts
argument_list|(
literal|"yes"
argument_list|)
expr_stmt|;
else|#
directive|else
name|puts
argument_list|(
literal|"no"
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
literal|0
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* This is the main program for the shared library test.  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_decl_stmt
name|int
name|mainvar
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|overriddenvar
init|=
literal|2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|shlibvar1
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|shlib_mainvar
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|shlib_overriddenvar
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|shlib_shlibvar1
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|shlib_shlibvar2
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|shlib_shlibcall
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|shlib_maincall
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|shlib_checkfunptr1
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|shlib_checkfunptr2
parameter_list|()
function_decl|;
end_function_decl

begin_extern
extern|extern int (*shlib_getfunptr1 (
end_extern

begin_expr_stmt
unit|))
operator|(
operator|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern int (*shlib_getfunptr2 (
end_extern

begin_expr_stmt
unit|))
operator|(
operator|)
expr_stmt|;
end_expr_stmt

begin_function_decl
specifier|extern
name|int
name|shlib_check
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|shlib_shlibcall2
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|visibility_check
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|visibility_checkfunptr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
modifier|*
name|visibility_funptr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|visibility_checkvar
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|visibility_checkvarptr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|visibility_varval
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
modifier|*
name|visibility_varptr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|shlib_visibility_checkcom
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|shlib_visibility_checkweak
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|int
name|shlib_visibility_com
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|shlib_visibility_var_weak
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|shlib_visibility_func_weak
parameter_list|()
block|{
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
name|WEAK_TEST
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|PROTECTED_UNDEF_TEST
end_ifdef

begin_define
define|#
directive|define
name|PROTECTED_TEST
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|WEAK_TEST
end_ifndef

begin_function_decl
specifier|extern
name|int
name|visibility
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|visibility_var
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HIDDEN_TEST
argument_list|)
operator|&&
name|defined
argument_list|(
name|PROTECTED_TEST
argument_list|)
end_if

begin_function
name|int
name|visibility
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|1
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|main_visibility_check
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
operator|(
name|int
argument_list|(
operator|*
argument_list|)
argument_list|(
name|void
argument_list|)
operator|)
name|visibility_funptr
argument_list|()
operator|)
operator|!=
name|visibility
return|;
block|}
end_function

begin_decl_stmt
name|int
name|visibility_var
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|int
name|main_visibility_checkvar
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|visibility_varval
argument_list|()
operator|!=
name|visibility_var
operator|&&
name|visibility_varptr
argument_list|()
operator|!=
operator|&
name|visibility_var
return|;
block|}
end_function

begin_ifndef
ifndef|#
directive|ifndef
name|PROTECTED_UNDEF_TEST
end_ifndef

begin_decl_stmt
name|int
name|shared_data
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_asm
asm|asm (".protected shared_data");
end_asm

begin_function
name|int
name|shared_func
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|1
return|;
block|}
end_function

begin_asm
asm|asm (".protected shared_func");
end_asm

begin_function_decl
specifier|extern
name|int
modifier|*
name|shared_data_p
parameter_list|()
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|func
function_decl|)
parameter_list|()
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|func
name|shared_func_p
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_function
specifier|static
name|int
name|main_visibility_check
parameter_list|(
name|void
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|WEAK_TEST
return|return
name|visibility_funptr
argument_list|()
operator|==
name|NULL
return|;
else|#
directive|else
return|return
operator|(
operator|(
name|int
argument_list|(
operator|*
argument_list|)
argument_list|(
name|void
argument_list|)
operator|)
name|visibility_funptr
argument_list|()
operator|)
operator|==
name|visibility
return|;
endif|#
directive|endif
block|}
end_function

begin_function
specifier|static
name|int
name|main_visibility_checkvar
parameter_list|(
name|void
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|WEAK_TEST
return|return
name|visibility_varval
argument_list|()
operator|==
literal|0
operator|&&
name|visibility_varptr
argument_list|()
operator|==
name|NULL
return|;
else|#
directive|else
return|return
name|visibility_varval
argument_list|()
operator|==
name|visibility_var
operator|&&
name|visibility_varptr
argument_list|()
operator|==
operator|&
name|visibility_var
return|;
endif|#
directive|endif
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This function is called by the shared library.  */
end_comment

begin_function
name|int
name|main_called
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|6
return|;
block|}
end_function

begin_comment
comment|/* This function overrides a function in the shared library.  */
end_comment

begin_function
name|int
name|shlib_overriddencall2
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|8
return|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|HIDDEN_NORMAL_TEST
end_ifdef

begin_decl_stmt
name|int
name|visibility_com
decl_stmt|;
end_decl_stmt

begin_asm
asm|asm (".hidden visibility_com");
end_asm

begin_function
name|int
name|main_visibility_checkcom
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|visibility_com
operator|==
literal|0
return|;
block|}
end_function

begin_function
name|int
name|main_visibility_checkweak
parameter_list|(
name|void
parameter_list|)
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

begin_function
name|int
name|main_visibility_checkcom
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|1
return|;
block|}
end_function

begin_pragma
pragma|#
directive|pragma
name|weak
name|visibility_undef_var_weak
end_pragma

begin_decl_stmt
specifier|extern
name|int
name|visibility_undef_var_weak
decl_stmt|;
end_decl_stmt

begin_asm
asm|asm (".hidden visibility_undef_var_weak");
end_asm

begin_pragma
pragma|#
directive|pragma
name|weak
name|visibility_undef_func_weak
end_pragma

begin_function_decl
specifier|extern
name|int
name|visibility_undef_func_weak
parameter_list|()
function_decl|;
end_function_decl

begin_asm
asm|asm (".hidden visibility_undef_func_weak");
end_asm

begin_pragma
pragma|#
directive|pragma
name|weak
name|visibility_var_weak
end_pragma

begin_decl_stmt
specifier|extern
name|int
name|visibility_var_weak
decl_stmt|;
end_decl_stmt

begin_asm
asm|asm (".hidden visibility_var_weak");
end_asm

begin_pragma
pragma|#
directive|pragma
name|weak
name|visibility_func_weak
end_pragma

begin_function_decl
specifier|extern
name|int
name|visibility_func_weak
parameter_list|()
function_decl|;
end_function_decl

begin_asm
asm|asm (".hidden visibility_func_weak");
end_asm

begin_function
name|int
name|main_visibility_checkweak
parameter_list|()
block|{
return|return
operator|&
name|visibility_undef_var_weak
operator|==
name|NULL
operator|&&
operator|&
name|visibility_undef_func_weak
operator|==
name|NULL
operator|&&
operator|&
name|visibility_func_weak
operator|==
name|NULL
operator|&&
operator|&
name|visibility_var_weak
operator|==
name|NULL
return|;
block|}
end_function

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|HIDDEN_UNDEF_TEST
argument_list|)
end_elif

begin_decl_stmt
specifier|extern
name|int
name|visibility_def
decl_stmt|;
end_decl_stmt

begin_asm
asm|asm (".hidden visibility_def");
end_asm

begin_function_decl
specifier|extern
name|int
name|visibility_func
parameter_list|()
function_decl|;
end_function_decl

begin_asm
asm|asm (".hidden visibility_func");
end_asm

begin_function
name|int
name|main_visibility_checkcom
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|&
name|visibility_def
operator|!=
name|NULL
operator|&&
name|visibility_def
operator|==
literal|2
return|;
block|}
end_function

begin_function
name|int
name|main_visibility_checkweak
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|&
name|visibility_func
operator|!=
name|NULL
operator|&&
name|visibility_func
argument_list|()
operator|==
literal|2
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_function
name|int
name|main_visibility_checkcom
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|1
return|;
block|}
end_function

begin_function
name|int
name|main_visibility_checkweak
parameter_list|(
name|void
parameter_list|)
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

begin_function
name|int
name|main
parameter_list|(
name|void
parameter_list|)
block|{
name|int
function_decl|(
modifier|*
name|p
function_decl|)
parameter_list|()
function_decl|;
name|int
name|ret
init|=
literal|0
decl_stmt|;
name|printf
argument_list|(
literal|"mainvar == %d\n"
argument_list|,
name|mainvar
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"overriddenvar == %d\n"
argument_list|,
name|overriddenvar
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"shlibvar1 == %d\n"
argument_list|,
name|shlibvar1
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|XCOFF_TEST
name|printf
argument_list|(
literal|"shlib_mainvar () == %d\n"
argument_list|,
name|shlib_mainvar
argument_list|()
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"shlib_overriddenvar () == %d\n"
argument_list|,
name|shlib_overriddenvar
argument_list|()
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|printf
argument_list|(
literal|"shlib_shlibvar1 () == %d\n"
argument_list|,
name|shlib_shlibvar1
argument_list|()
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"shlib_shlibvar2 () == %d\n"
argument_list|,
name|shlib_shlibvar2
argument_list|()
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"shlib_shlibcall () == %d\n"
argument_list|,
name|shlib_shlibcall
argument_list|()
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|XCOFF_TEST
name|printf
argument_list|(
literal|"shlib_shlibcall2 () == %d\n"
argument_list|,
name|shlib_shlibcall2
argument_list|()
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"shlib_maincall () == %d\n"
argument_list|,
name|shlib_maincall
argument_list|()
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|printf
argument_list|(
literal|"main_called () == %d\n"
argument_list|,
name|main_called
argument_list|()
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"shlib_checkfunptr1 (shlib_shlibvar1) == %d\n"
argument_list|,
name|shlib_checkfunptr1
argument_list|(
name|shlib_shlibvar1
argument_list|)
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|XCOFF_TEST
name|printf
argument_list|(
literal|"shlib_checkfunptr2 (main_called) == %d\n"
argument_list|,
name|shlib_checkfunptr2
argument_list|(
name|main_called
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|p
operator|=
name|shlib_getfunptr1
argument_list|()
expr_stmt|;
name|printf
argument_list|(
literal|"shlib_getfunptr1 () "
argument_list|)
expr_stmt|;
if|if
condition|(
name|p
operator|==
name|shlib_shlibvar1
condition|)
name|printf
argument_list|(
literal|"=="
argument_list|)
expr_stmt|;
else|else
name|printf
argument_list|(
literal|"!="
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" shlib_shlibvar1\n"
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|XCOFF_TEST
name|p
operator|=
name|shlib_getfunptr2
argument_list|()
expr_stmt|;
name|printf
argument_list|(
literal|"shlib_getfunptr2 () "
argument_list|)
expr_stmt|;
if|if
condition|(
name|p
operator|==
name|main_called
condition|)
name|printf
argument_list|(
literal|"=="
argument_list|)
expr_stmt|;
else|else
name|printf
argument_list|(
literal|"!="
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" main_called\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|printf
argument_list|(
literal|"shlib_check () == %d\n"
argument_list|,
name|shlib_check
argument_list|()
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"visibility_check () == %d\n"
argument_list|,
name|visibility_check
argument_list|()
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"visibility_checkfunptr () == %d\n"
argument_list|,
name|visibility_checkfunptr
argument_list|()
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"main_visibility_check () == %d\n"
argument_list|,
name|main_visibility_check
argument_list|()
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"visibility_checkvar () == %d\n"
argument_list|,
name|visibility_checkvar
argument_list|()
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"visibility_checkvarptr () == %d\n"
argument_list|,
name|visibility_checkvarptr
argument_list|()
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"main_visibility_checkvar () == %d\n"
argument_list|,
name|main_visibility_checkvar
argument_list|()
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"main_visibility_checkcom () == %d\n"
argument_list|,
name|main_visibility_checkcom
argument_list|()
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"shlib_visibility_checkcom () == %d\n"
argument_list|,
name|shlib_visibility_checkcom
argument_list|()
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"main_visibility_checkweak () == %d\n"
argument_list|,
name|main_visibility_checkweak
argument_list|()
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"shlib_visibility_checkweak () == %d\n"
argument_list|,
name|shlib_visibility_checkweak
argument_list|()
argument_list|)
expr_stmt|;
if|#
directive|if
operator|!
name|defined
argument_list|(
name|PROTECTED_UNDEF_TEST
argument_list|)
operator|&&
name|defined
argument_list|(
name|PROTECTED_TEST
argument_list|)
if|if
condition|(
operator|&
name|shared_data
operator|!=
name|shared_data_p
argument_list|()
condition|)
name|ret
operator|=
literal|1
expr_stmt|;
name|p
operator|=
name|shared_func_p
argument_list|()
expr_stmt|;
if|if
condition|(
name|shared_func
operator|!=
name|p
condition|)
name|ret
operator|=
literal|1
expr_stmt|;
if|if
condition|(
name|shared_data
operator|!=
operator|*
name|shared_data_p
argument_list|()
condition|)
name|ret
operator|=
literal|1
expr_stmt|;
if|if
condition|(
name|shared_func
argument_list|()
operator|!=
call|(
modifier|*
name|p
call|)
argument_list|()
condition|)
name|ret
operator|=
literal|1
expr_stmt|;
endif|#
directive|endif
return|return
name|ret
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

