begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997 John Birrell<jb@cimlogic.com.au>.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by John Birrell.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY JOHN BIRRELL AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_include
include|#
directive|include
file|<stdlib.h>
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
file|<sched.h>
end_include

begin_include
include|#
directive|include
file|<pthread.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<libc_private.h>
end_include

begin_include
include|#
directive|include
file|"spinlock.h"
end_include

begin_include
include|#
directive|include
file|"thr_private.h"
end_include

begin_comment
comment|/*  * These are for compatability only.  Spinlocks of this type  * are deprecated.  */
end_comment

begin_function
name|void
name|_spinunlock
parameter_list|(
name|spinlock_t
modifier|*
name|lck
parameter_list|)
block|{
name|lck
operator|->
name|access_lock
operator|=
literal|0
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Lock a location for the running thread. Yield to allow other  * threads to run if this thread is blocked because the lock is  * not available. Note that this function does not sleep. It  * assumes that the lock will be available very soon.  */
end_comment

begin_function
name|void
name|_spinlock
parameter_list|(
name|spinlock_t
modifier|*
name|lck
parameter_list|)
block|{
comment|/* 	 * Try to grab the lock and loop if another thread grabs 	 * it before we do. 	 */
while|while
condition|(
name|_atomic_lock
argument_list|(
operator|&
name|lck
operator|->
name|access_lock
argument_list|)
condition|)
block|{
while|while
condition|(
name|lck
operator|->
name|access_lock
condition|)
empty_stmt|;
block|}
block|}
end_function

begin_comment
comment|/*  * Lock a location for the running thread. Yield to allow other  * threads to run if this thread is blocked because the lock is  * not available. Note that this function does not sleep. It  * assumes that the lock will be available very soon.  *  * This function checks if the running thread has already locked the  * location, warns if this occurs and creates a thread dump before  * returning.  */
end_comment

begin_function
name|void
name|_spinlock_debug
parameter_list|(
name|spinlock_t
modifier|*
name|lck
parameter_list|,
name|char
modifier|*
name|fname
parameter_list|,
name|int
name|lineno
parameter_list|)
block|{
comment|/* 	 * Try to grab the lock and loop if another thread grabs 	 * it before we do. 	 */
while|while
condition|(
name|_atomic_lock
argument_list|(
operator|&
name|lck
operator|->
name|access_lock
argument_list|)
condition|)
block|{
while|while
condition|(
name|lck
operator|->
name|access_lock
condition|)
empty_stmt|;
block|}
block|}
end_function

end_unit

