begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)alarm_.c	5.1	6/7/85  */
end_comment

begin_comment
comment|/*  * set an alarm time, arrange for user specified action, and return.  *  * calling sequence:  *	integer	flag  *	external alfunc  *	lastiv = alarm (intval, alfunc)  * where:  *	intval	= the alarm interval in seconds; 0 turns off the alarm.  *	alfunc	= the function to be called after the alarm interval,  *  *	The returned value will be the time remaining on the last alarm.  */
end_comment

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_decl_stmt
name|long
name|alarm_
argument_list|(
name|sec
argument_list|,
name|proc
argument_list|)
name|long
modifier|*
name|sec
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
function_decl|(
modifier|*
name|proc
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_block
block|{
specifier|register
name|long
name|lt
decl_stmt|;
name|lt
operator|=
name|alarm
argument_list|(
literal|1000
argument_list|)
expr_stmt|;
comment|/* time to maneuver */
if|if
condition|(
operator|*
name|sec
condition|)
name|signal
argument_list|(
name|SIGALRM
argument_list|,
name|proc
argument_list|)
expr_stmt|;
name|alarm
argument_list|(
operator|*
name|sec
argument_list|)
expr_stmt|;
return|return
operator|(
name|lt
operator|)
return|;
block|}
end_block

end_unit

