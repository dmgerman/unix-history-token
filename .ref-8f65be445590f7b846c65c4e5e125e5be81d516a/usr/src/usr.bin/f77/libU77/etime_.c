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
literal|"@(#)etime_.c	5.2 (Berkeley) %G%"
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
comment|/*  * Return the elapsed execution time for this process.  *  * calling sequence:  * 	real time(2)  * 	call etime (time)  * where:  * 	the 2 element array, time, will receive the user and system  * 	elapsed time since the start of execution.  *  *	This routine can be called as function, and returns the sum of  *	user and system times. The time array argument must always be given.  *  *	The resolution for all timing is 1/60 second.  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/times.h>
end_include

begin_struct
struct|struct
name|tb
block|{
name|float
name|usrtime
decl_stmt|;
name|float
name|systime
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|float
name|etime_
parameter_list|(
name|et
parameter_list|)
name|struct
name|tb
modifier|*
name|et
decl_stmt|;
block|{
name|struct
name|tms
name|clock
decl_stmt|;
name|times
argument_list|(
operator|&
name|clock
argument_list|)
expr_stmt|;
name|et
operator|->
name|usrtime
operator|=
operator|(
name|float
operator|)
name|clock
operator|.
name|tms_utime
operator|/
literal|60.0
expr_stmt|;
name|et
operator|->
name|systime
operator|=
operator|(
name|float
operator|)
name|clock
operator|.
name|tms_stime
operator|/
literal|60.0
expr_stmt|;
return|return
operator|(
name|et
operator|->
name|usrtime
operator|+
name|et
operator|->
name|systime
operator|)
return|;
block|}
end_function

end_unit

