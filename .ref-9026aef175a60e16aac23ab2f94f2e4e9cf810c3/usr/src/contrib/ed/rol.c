begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Rodney Ruddock of the University of Guelph.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)rol.c	8.1 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<regex.h>
end_include

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|DBI
end_ifdef

begin_include
include|#
directive|include
file|<db.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"ed.h"
end_include

begin_include
include|#
directive|include
file|"extern.h"
end_include

begin_comment
comment|/*  * After the command check the rest of the line to see nothing illegal  * is following. Any single instance of a printsfx suffix is the only  * legal thing to follow ( that is, a 'l', 'n', or 'p'). If a suffix  * occurs the execution of that suffix occurs back in the cmd_loop  * function after the command that called this function finishes  * successfully.  */
end_comment

begin_function
name|int
name|rol
parameter_list|(
name|inputt
parameter_list|,
name|errnum
parameter_list|)
name|FILE
modifier|*
name|inputt
decl_stmt|;
name|int
modifier|*
name|errnum
decl_stmt|;
block|{
name|ss
operator|=
name|getc
argument_list|(
name|inputt
argument_list|)
expr_stmt|;
name|printsfx
operator|=
literal|0
expr_stmt|;
comment|/* Only one of the suffix is allowed. */
if|if
condition|(
name|ss
operator|==
literal|'p'
condition|)
name|printsfx
operator|=
literal|1
expr_stmt|;
elseif|else
if|if
condition|(
name|ss
operator|==
literal|'n'
condition|)
name|printsfx
operator|=
literal|2
expr_stmt|;
elseif|else
if|if
condition|(
name|ss
operator|==
literal|'l'
condition|)
name|printsfx
operator|=
literal|4
expr_stmt|;
else|else
name|ungetc
argument_list|(
name|ss
argument_list|,
name|inputt
argument_list|)
expr_stmt|;
for|for
control|(
init|;
condition|;
control|)
block|{
name|ss
operator|=
name|getc
argument_list|(
name|inputt
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|ss
operator|!=
literal|' '
operator|)
operator|&&
operator|(
name|ss
operator|!=
literal|'\n'
operator|)
operator|&&
operator|(
name|ss
operator|!=
name|EOF
operator|)
condition|)
block|{
operator|*
name|errnum
operator|=
operator|-
literal|1
expr_stmt|;
name|strcpy
argument_list|(
name|help_msg
argument_list|,
literal|"illegal command option"
argument_list|)
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
block|}
if|if
condition|(
operator|(
name|ss
operator|==
literal|'\n'
operator|)
operator|||
operator|(
name|ss
operator|==
name|EOF
operator|)
condition|)
break|break;
block|}
comment|/* Rest-of-line was okay. */
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

end_unit

