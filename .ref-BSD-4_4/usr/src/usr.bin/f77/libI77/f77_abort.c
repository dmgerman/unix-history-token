begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1980 The Regents of the University of California.  * All rights reserved.  *  * This module is believed to contain source code proprietary to AT&T.  * Use and redistribution is subject to the Berkeley Software License  * Agreement and your Software Agreement with AT&T (Western Electric).  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)f77_abort.c	5.3 (Berkeley) 4/12/91"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_comment
comment|/*  *	all f77 aborts eventually call f77_abort.  *	f77_abort cleans up open files and terminates with a dump if needed,  *	with a message otherwise.	  *  */
end_comment

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|"fio.h"
end_include

begin_function_decl
name|char
modifier|*
name|getenv
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|_lg_flag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* _lg_flag is non-zero if -lg was specified to ld */
end_comment

begin_macro
name|f77_abort
argument_list|(
argument|err_val
argument_list|,
argument|act_core
argument_list|)
end_macro

begin_block
block|{
name|char
name|first_char
decl_stmt|,
modifier|*
name|env_var
decl_stmt|;
name|int
name|core_dump
decl_stmt|;
name|env_var
operator|=
name|getenv
argument_list|(
literal|"f77_dump_flag"
argument_list|)
expr_stmt|;
name|first_char
operator|=
operator|(
name|env_var
operator|==
name|NULL
operator|)
condition|?
literal|0
else|:
operator|*
name|env_var
expr_stmt|;
name|signal
argument_list|(
name|SIGILL
argument_list|,
name|SIG_DFL
argument_list|)
expr_stmt|;
name|sigsetmask
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|/* don't block */
comment|/* see if we want a core dump: 		first line checks for signals like hangup - don't dump then. 		second line checks if -lg specified to ld (e.g. by saying 			-g to f77) and checks the f77_dump_flag var. */
name|core_dump
operator|=
operator|(
operator|(
name|nargs
argument_list|()
operator|!=
literal|2
operator|)
operator|||
name|act_core
operator|)
operator|&&
operator|(
operator|(
name|_lg_flag
operator|&&
operator|(
name|first_char
operator|!=
literal|'n'
operator|)
operator|)
operator|||
name|first_char
operator|==
literal|'y'
operator|)
expr_stmt|;
if|if
condition|(
operator|!
name|core_dump
condition|)
name|fprintf
argument_list|(
name|units
index|[
name|STDERR
index|]
operator|.
name|ufd
argument_list|,
literal|"*** Execution terminated\n"
argument_list|)
expr_stmt|;
name|f_exit
argument_list|()
expr_stmt|;
name|_cleanup
argument_list|()
expr_stmt|;
if|if
condition|(
name|nargs
argument_list|()
condition|)
name|errno
operator|=
name|err_val
expr_stmt|;
else|else
name|errno
operator|=
operator|-
literal|2
expr_stmt|;
comment|/* prior value will be meaningless, 				so set it to undefined value */
if|if
condition|(
name|core_dump
condition|)
name|abort
argument_list|()
expr_stmt|;
else|else
name|exit
argument_list|(
name|errno
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

