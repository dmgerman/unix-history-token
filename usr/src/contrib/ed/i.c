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
literal|"@(#)i.c	8.1 (Berkeley) %G%"
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
comment|/*  * Set things up for the central input routine to correctly place  * the text as per the insert command.  */
end_comment

begin_function
name|void
name|i
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
ifdef|#
directive|ifdef
name|POSIX
name|LINE
modifier|*
name|l_address
decl_stmt|;
endif|#
directive|endif
if|if
condition|(
operator|(
name|End_default
operator|==
literal|1
operator|)
operator|&&
operator|(
name|current
operator|!=
name|NULL
operator|)
condition|)
name|Start
operator|=
name|End
operator|=
name|current
operator|->
name|above
expr_stmt|;
else|else
block|{
if|if
condition|(
name|End
operator|==
name|NULL
condition|)
block|{
name|strcpy
argument_list|(
name|help_msg
argument_list|,
literal|"illegal address for command i"
argument_list|)
expr_stmt|;
operator|*
name|errnum
operator|=
operator|-
literal|1
expr_stmt|;
return|return;
block|}
else|else
name|End
operator|=
name|End
operator|->
name|above
expr_stmt|;
block|}
name|Start_default
operator|=
name|End_default
operator|=
literal|0
expr_stmt|;
ifdef|#
directive|ifdef
name|POSIX
name|l_address
operator|=
name|End
expr_stmt|;
endif|#
directive|endif
comment|/* 	 * 'i' is just a variation on 'a': completely true with BSD; with 	 * POSIX we have to fake the location of "current" in a special case. 	 */
name|a
argument_list|(
name|inputt
argument_list|,
name|errnum
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|POSIX
if|if
condition|(
name|l_address
operator|->
name|above
condition|)
name|current
operator|=
name|l_address
operator|->
name|below
expr_stmt|;
endif|#
directive|endif
block|}
end_function

end_unit

