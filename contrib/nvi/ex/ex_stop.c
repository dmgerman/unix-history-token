begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1993, 1994  *	The Regents of the University of California.  All rights reserved.  * Copyright (c) 1992, 1993, 1994, 1995, 1996  *	Keith Bostic.  All rights reserved.  *  * See the LICENSE file for redistribution information.  */
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
literal|"@(#)ex_stop.c	10.10 (Berkeley) 3/6/96"
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
file|<errno.h>
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
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|"../common/common.h"
end_include

begin_comment
comment|/*  * ex_stop -- :stop[!]  *	      :suspend[!]  *	Suspend execution.  *  * PUBLIC: int ex_stop __P((SCR *, EXCMD *));  */
end_comment

begin_function
name|int
name|ex_stop
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
name|int
name|allowed
decl_stmt|;
comment|/* For some strange reason, the force flag turns off autowrite. */
if|if
condition|(
operator|!
name|FL_ISSET
argument_list|(
name|cmdp
operator|->
name|iflags
argument_list|,
name|E_C_FORCE
argument_list|)
operator|&&
name|file_aw
argument_list|(
name|sp
argument_list|,
name|FS_ALL
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
name|gp
operator|->
name|scr_suspend
argument_list|(
name|sp
argument_list|,
operator|&
name|allowed
argument_list|)
condition|)
return|return
operator|(
literal|1
operator|)
return|;
if|if
condition|(
operator|!
name|allowed
condition|)
name|ex_emsg
argument_list|(
name|sp
argument_list|,
name|NULL
argument_list|,
name|EXM_NOSUSPEND
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

end_unit

