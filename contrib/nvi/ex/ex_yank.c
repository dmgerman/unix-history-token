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
literal|"@(#)ex_yank.c	10.7 (Berkeley) 3/6/96"
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
comment|/*  * ex_yank -- :[line [,line]] ya[nk] [buffer] [count]  *	Yank the lines into a buffer.  *  * PUBLIC: int ex_yank __P((SCR *, EXCMD *));  */
end_comment

begin_function
name|int
name|ex_yank
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
name|NEEDFILE
argument_list|(
name|sp
argument_list|,
name|cmdp
argument_list|)
expr_stmt|;
comment|/* 	 * !!! 	 * Historically, yanking lines in ex didn't count toward the 	 * number-of-lines-yanked report. 	 */
return|return
operator|(
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
operator|)
return|;
block|}
end_function

end_unit

