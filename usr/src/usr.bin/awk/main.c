begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************** main.c copyright 1991, Michael D. Brennan  This is a source file for mawk, an implementation of the AWK programming language.  Mawk is distributed without warranty under the terms of the GNU General Public License, version 2, 1991. ********************************************/
end_comment

begin_comment
comment|/* $Log:	main.c,v $  * Revision 5.1  91/12/05  07:56:14  brennan  * 1.1 pre-release  *  */
end_comment

begin_comment
comment|/*  main.c  */
end_comment

begin_include
include|#
directive|include
file|"mawk.h"
end_include

begin_include
include|#
directive|include
file|"code.h"
end_include

begin_include
include|#
directive|include
file|"init.h"
end_include

begin_include
include|#
directive|include
file|"fin.h"
end_include

begin_include
include|#
directive|include
file|"bi_vars.h"
end_include

begin_include
include|#
directive|include
file|"field.h"
end_include

begin_include
include|#
directive|include
file|"files.h"
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_if
if|#
directive|if
name|MSDOS
end_if

begin_function_decl
name|void
name|reargv
parameter_list|(
name|int
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LM_DOS
operator|&&
name|__TURBOC__
end_if

begin_decl_stmt
specifier|extern
name|unsigned
name|_stklen
init|=
literal|16
operator|*
literal|1024U
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  4K of stack is enough for a user function call         nesting depth of 75 so this is enough for 300 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|program_fd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|progname
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|short
name|mawk_state
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 0 is compiling */
end_comment

begin_decl_stmt
name|int
name|exit_code
decl_stmt|;
end_decl_stmt

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
if|#
directive|if
name|MSDOS
name|progname
operator|=
literal|"mawk"
expr_stmt|;
if|#
directive|if
name|HAVE_REARGV
name|reargv
argument_list|(
operator|&
name|argc
argument_list|,
operator|&
name|argv
argument_list|)
expr_stmt|;
endif|#
directive|endif
else|#
directive|else
comment|/* MSDOS */
ifdef|#
directive|ifdef
name|THINK_C
name|progname
operator|=
literal|"MacMAWK"
expr_stmt|;
else|#
directive|else
comment|/* THINK_C */
block|{
name|char
modifier|*
name|strrchr
parameter_list|()
function_decl|;
name|char
modifier|*
name|p
init|=
name|strrchr
argument_list|(
name|argv
index|[
literal|0
index|]
argument_list|,
literal|'/'
argument_list|)
decl_stmt|;
name|progname
operator|=
name|p
condition|?
name|p
operator|+
literal|1
else|:
name|argv
index|[
literal|0
index|]
expr_stmt|;
block|}
endif|#
directive|endif
endif|#
directive|endif
name|initialize
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
expr_stmt|;
if|if
condition|(
name|parse
argument_list|()
operator|||
name|compile_error_count
condition|)
name|mawk_exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|compile_cleanup
argument_list|()
expr_stmt|;
name|mawk_state
operator|=
name|EXECUTION
expr_stmt|;
name|execute
argument_list|(
name|code_ptr
argument_list|,
name|eval_stack
operator|-
literal|1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* never returns */
return|return
literal|0
return|;
block|}
end_function

begin_function
name|void
name|mawk_exit
parameter_list|(
name|x
parameter_list|)
name|int
name|x
decl_stmt|;
block|{
if|#
directive|if
name|HAVE_REAL_PIPES
name|close_out_pipes
argument_list|()
expr_stmt|;
comment|/* no effect, if no out pipes */
else|#
directive|else
if|#
directive|if
name|HAVE_FAKE_PIPES
name|close_fake_pipes
argument_list|()
expr_stmt|;
endif|#
directive|endif
endif|#
directive|endif
name|exit
argument_list|(
name|x
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

