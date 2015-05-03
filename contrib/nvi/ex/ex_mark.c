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
literal|"$Id: ex_mark.c,v 10.9 2001/06/25 15:19:17 skimo Exp $"
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
file|<sys/time.h>
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
comment|/*  * ex_mark -- :mark char  *	      :k char  *	Mark lines.  *  *  * PUBLIC: int ex_mark(SCR *, EXCMD *);  */
end_comment

begin_function
name|int
name|ex_mark
parameter_list|(
name|SCR
modifier|*
name|sp
parameter_list|,
name|EXCMD
modifier|*
name|cmdp
parameter_list|)
block|{
name|NEEDFILE
argument_list|(
name|sp
argument_list|,
name|cmdp
argument_list|)
expr_stmt|;
if|if
condition|(
name|cmdp
operator|->
name|argv
index|[
literal|0
index|]
operator|->
name|len
operator|!=
literal|1
condition|)
block|{
name|msgq
argument_list|(
name|sp
argument_list|,
name|M_ERR
argument_list|,
literal|"136|Mark names must be a single character"
argument_list|)
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
block|}
return|return
operator|(
name|mark_set
argument_list|(
name|sp
argument_list|,
name|cmdp
operator|->
name|argv
index|[
literal|0
index|]
operator|->
name|bp
index|[
literal|0
index|]
argument_list|,
operator|&
name|cmdp
operator|->
name|addr1
argument_list|,
literal|1
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

