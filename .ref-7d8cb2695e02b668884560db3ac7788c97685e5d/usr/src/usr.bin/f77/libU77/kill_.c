begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1980 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.proprietary.c%  */
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
literal|"@(#)kill_.c	5.2 (Berkeley) %G%"
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
comment|/*  * send a signal to a process  *  * calling sequence:  *	ierror = kill(pid, signum)  * where:  *	pid must be the process id of one of the user's processes  *	signum must be a valid signal number (see signal(2))  *	ierror will be 0 if successful; an error code otherwise.  */
end_comment

begin_include
include|#
directive|include
file|"../libI77/f_errno.h"
end_include

begin_function
name|long
name|kill_
parameter_list|(
name|pid
parameter_list|,
name|signum
parameter_list|)
name|long
modifier|*
name|pid
decl_stmt|,
decl|*
name|signum
decl_stmt|;
end_function

begin_block
block|{
if|if
condition|(
operator|*
name|pid
operator|<
literal|0
operator|||
operator|*
name|pid
operator|>
literal|32767L
operator|||
operator|*
name|signum
operator|<
literal|1
operator|||
operator|*
name|signum
operator|>
literal|16
condition|)
return|return
operator|(
call|(
name|long
call|)
argument_list|(
name|errno
operator|=
name|F_ERARG
argument_list|)
operator|)
return|;
if|if
condition|(
name|kill
argument_list|(
operator|(
name|int
operator|)
operator|*
name|pid
argument_list|,
operator|(
name|int
operator|)
operator|*
name|signum
argument_list|)
operator|!=
literal|0
condition|)
return|return
operator|(
operator|(
name|long
operator|)
name|errno
operator|)
return|;
return|return
operator|(
literal|0L
operator|)
return|;
block|}
end_block

end_unit

