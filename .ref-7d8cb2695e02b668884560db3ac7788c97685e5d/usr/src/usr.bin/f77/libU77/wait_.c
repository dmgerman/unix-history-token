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
literal|"@(#)wait_.c	5.2 (Berkeley) %G%"
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
comment|/*  * wait for a child to die  *  * calling sequence:  *	integer wait, status, chilid  *	chilid = wait(status)  * where:  *	chilid will be	->0 if child process id  *			-<0 if (negative of) system error code  *	status will contain the exit status of the child  *		(see wait(2))  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_function
name|long
name|wait_
parameter_list|(
name|status
parameter_list|)
name|long
modifier|*
name|status
decl_stmt|;
block|{
name|int
name|stat
decl_stmt|;
name|int
name|chid
init|=
name|wait
argument_list|(
operator|&
name|stat
argument_list|)
decl_stmt|;
if|if
condition|(
name|chid
operator|<
literal|0
condition|)
return|return
operator|(
call|(
name|long
call|)
argument_list|(
operator|-
name|errno
argument_list|)
operator|)
return|;
operator|*
name|status
operator|=
operator|(
name|long
operator|)
name|stat
expr_stmt|;
return|return
operator|(
operator|(
name|long
operator|)
name|chid
operator|)
return|;
block|}
end_function

end_unit

