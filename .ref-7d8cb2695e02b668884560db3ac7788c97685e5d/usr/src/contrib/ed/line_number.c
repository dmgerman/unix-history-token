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
literal|"@(#)line_number.c	8.1 (Berkeley) %G%"
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
comment|/*  * Converts a LINE to a line number (int) that can be printed to  * the device the user is at. Used by n and =.  */
end_comment

begin_function
name|int
name|line_number
parameter_list|(
name|line_addr
parameter_list|)
name|LINE
modifier|*
name|line_addr
decl_stmt|;
block|{
name|LINE
modifier|*
name|l_temp1
decl_stmt|;
name|int
name|l_cnt
init|=
literal|1
decl_stmt|;
comment|/* yes! =1 */
name|l_temp1
operator|=
name|top
expr_stmt|;
if|if
condition|(
operator|(
name|line_addr
operator|==
name|NULL
operator|)
operator|&&
operator|(
name|top
operator|==
name|NULL
operator|)
condition|)
return|return
operator|(
literal|0
operator|)
return|;
for|for
control|(
init|;
condition|;
control|)
block|{
if|if
condition|(
name|line_addr
operator|==
name|l_temp1
condition|)
break|break;
name|l_temp1
operator|=
name|l_temp1
operator|->
name|below
expr_stmt|;
name|l_cnt
operator|++
expr_stmt|;
block|}
return|return
operator|(
name|l_cnt
operator|)
return|;
block|}
end_function

end_unit

