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
literal|"@(#)c.c	8.1 (Berkeley) %G%"
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
comment|/*  * This deletes the range of lines specified and then sets up things  * for the central input routine.  */
end_comment

begin_function
name|void
name|c
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
name|int
name|l_flag
init|=
literal|1
decl_stmt|;
if|if
condition|(
name|Start_default
operator|&&
name|End_default
condition|)
name|Start
operator|=
name|End
operator|=
name|current
expr_stmt|;
elseif|else
if|if
condition|(
name|Start_default
condition|)
name|Start
operator|=
name|End
expr_stmt|;
if|if
condition|(
name|Start
operator|==
name|NULL
condition|)
block|{
operator|*
name|errnum
operator|=
operator|-
literal|1
expr_stmt|;
return|return;
block|}
name|Start_default
operator|=
name|End_default
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|End
operator|==
name|bottom
condition|)
name|l_flag
operator|=
literal|0
expr_stmt|;
comment|/* first delete the lines */
name|d
argument_list|(
name|inputt
argument_list|,
name|errnum
argument_list|)
expr_stmt|;
if|if
condition|(
operator|*
name|errnum
operator|<
literal|0
condition|)
return|return;
operator|*
name|errnum
operator|=
literal|0
expr_stmt|;
comment|/*if ((current != NULL)&& (current != bottom)) RMSR */
if|if
condition|(
operator|(
name|current
operator|!=
name|NULL
operator|)
operator|&&
name|l_flag
condition|)
name|current
operator|=
name|current
operator|->
name|above
expr_stmt|;
name|add_flag
operator|=
literal|1
expr_stmt|;
name|Start_default
operator|=
name|End_default
operator|=
literal|1
expr_stmt|;
comment|/* now get the "change" lines */
name|input_lines
argument_list|(
name|inputt
argument_list|,
name|errnum
argument_list|)
expr_stmt|;
name|add_flag
operator|=
literal|0
expr_stmt|;
block|}
end_function

end_unit

