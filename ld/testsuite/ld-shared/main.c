begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
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

begin_comment
comment|/* This function is called by the shared library.  */
end_comment

begin_function
name|int
name|main_called
parameter_list|()
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
parameter_list|()
block|{
return|return
literal|8
return|;
block|}
end_function

begin_function
name|int
name|main
parameter_list|()
block|{
name|int
function_decl|(
modifier|*
name|p
function_decl|)
parameter_list|()
function_decl|;
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
ifndef|#
directive|ifndef
name|SYMBOLIC_TEST
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
return|return
literal|0
return|;
block|}
end_function

end_unit

