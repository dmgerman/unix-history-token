begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993, 1994  *	The Regents of the University of California.  All rights reserved.  * Copyright (c) 1992, 1993, 1994, 1995, 1996  *	Keith Bostic.  All rights reserved.  *  * See the LICENSE file for redistribution information.  */
end_comment

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
specifier|const
name|char
name|sccsid
index|[]
init|=
literal|"@(#)ex_delete.c	10.9 (Berkeley) 10/23/96"
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
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<bitstring.h>
end_include

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"../common/common.h"
end_include

begin_comment
comment|/*  * ex_delete: [line [,line]] d[elete] [buffer] [count] [flags]  *  *	Delete lines from the file.  *  * PUBLIC: int ex_delete __P((SCR *, EXCMD *));  */
end_comment

begin_function
name|int
name|ex_delete
parameter_list|(
name|sp
parameter_list|,
name|cmdp
parameter_list|)
name|SCR
modifier|*
name|sp
decl_stmt|;
name|EXCMD
modifier|*
name|cmdp
decl_stmt|;
block|{
name|recno_t
name|lno
decl_stmt|;
name|NEEDFILE
argument_list|(
name|sp
argument_list|,
name|cmdp
argument_list|)
expr_stmt|;
comment|/* 	 * !!! 	 * Historically, lines deleted in ex were not placed in the numeric 	 * buffers.  We follow historic practice so that we don't overwrite 	 * vi buffers accidentally. 	 */
if|if
condition|(
name|cut
argument_list|(
name|sp
argument_list|,
name|FL_ISSET
argument_list|(
name|cmdp
operator|->
name|iflags
argument_list|,
name|E_C_BUFFER
argument_list|)
condition|?
operator|&
name|cmdp
operator|->
name|buffer
else|:
name|NULL
argument_list|,
operator|&
name|cmdp
operator|->
name|addr1
argument_list|,
operator|&
name|cmdp
operator|->
name|addr2
argument_list|,
name|CUT_LINEMODE
argument_list|)
condition|)
return|return
operator|(
literal|1
operator|)
return|;
comment|/* Delete the lines. */
if|if
condition|(
name|del
argument_list|(
name|sp
argument_list|,
operator|&
name|cmdp
operator|->
name|addr1
argument_list|,
operator|&
name|cmdp
operator|->
name|addr2
argument_list|,
literal|1
argument_list|)
condition|)
return|return
operator|(
literal|1
operator|)
return|;
comment|/* Set the cursor to the line after the last line deleted. */
name|sp
operator|->
name|lno
operator|=
name|cmdp
operator|->
name|addr1
operator|.
name|lno
expr_stmt|;
comment|/* Or the last line in the file if deleted to the end of the file. */
if|if
condition|(
name|db_last
argument_list|(
name|sp
argument_list|,
operator|&
name|lno
argument_list|)
condition|)
return|return
operator|(
literal|1
operator|)
return|;
if|if
condition|(
name|sp
operator|->
name|lno
operator|>
name|lno
condition|)
name|sp
operator|->
name|lno
operator|=
name|lno
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

end_unit

