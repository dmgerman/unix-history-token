begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995 John Birrell<jb@cimlogic.com.au>.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by John Birrell.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY JOHN BIRRELL AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  */
end_comment

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_THREAD_SAFE
end_ifdef

begin_include
include|#
directive|include
file|<pthread.h>
end_include

begin_include
include|#
directive|include
file|"pthread_private.h"
end_include

begin_function
name|pid_t
name|fork
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|flags
decl_stmt|;
name|pid_t
name|ret
decl_stmt|;
comment|/* Fork a new process: */
if|if
condition|(
operator|(
name|ret
operator|=
name|_thread_sys_fork
argument_list|()
operator|)
operator|<=
literal|0
condition|)
block|{
comment|/* Parent process or error. Nothing to do here. */
block|}
else|else
block|{
comment|/* Close the pthread kernel pipe: */
name|_thread_sys_close
argument_list|(
name|_thread_kern_pipe
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
name|_thread_sys_close
argument_list|(
name|_thread_kern_pipe
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
comment|/* Reset signals pending for the running thread: */
name|memset
argument_list|(
name|_thread_run
operator|->
name|sigpend
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|_thread_run
operator|->
name|sigpend
argument_list|)
argument_list|)
expr_stmt|;
comment|/* 		 * Create a pipe that is written to by the signal handler to 		 * prevent signals being missed in calls to 		 * _thread_sys_select:  		 */
if|if
condition|(
name|_thread_sys_pipe
argument_list|(
name|_thread_kern_pipe
argument_list|)
operator|!=
literal|0
condition|)
block|{
comment|/* Cannot create pipe, so abort: */
name|PANIC
argument_list|(
literal|"Cannot create pthread kernel pipe for forked process"
argument_list|)
expr_stmt|;
block|}
comment|/* Get the flags for the read pipe: */
elseif|else
if|if
condition|(
operator|(
name|flags
operator|=
name|_thread_sys_fcntl
argument_list|(
name|_thread_kern_pipe
index|[
literal|0
index|]
argument_list|,
name|F_GETFL
argument_list|,
name|NULL
argument_list|)
operator|)
operator|==
operator|-
literal|1
condition|)
block|{
comment|/* Abort this application: */
name|abort
argument_list|()
expr_stmt|;
block|}
comment|/* Make the read pipe non-blocking: */
elseif|else
if|if
condition|(
name|_thread_sys_fcntl
argument_list|(
name|_thread_kern_pipe
index|[
literal|0
index|]
argument_list|,
name|F_SETFL
argument_list|,
name|flags
operator||
name|O_NONBLOCK
argument_list|)
operator|==
operator|-
literal|1
condition|)
block|{
comment|/* Abort this application: */
name|abort
argument_list|()
expr_stmt|;
block|}
comment|/* Get the flags for the write pipe: */
elseif|else
if|if
condition|(
operator|(
name|flags
operator|=
name|_thread_sys_fcntl
argument_list|(
name|_thread_kern_pipe
index|[
literal|1
index|]
argument_list|,
name|F_GETFL
argument_list|,
name|NULL
argument_list|)
operator|)
operator|==
operator|-
literal|1
condition|)
block|{
comment|/* Abort this application: */
name|abort
argument_list|()
expr_stmt|;
block|}
comment|/* Make the write pipe non-blocking: */
elseif|else
if|if
condition|(
name|_thread_sys_fcntl
argument_list|(
name|_thread_kern_pipe
index|[
literal|1
index|]
argument_list|,
name|F_SETFL
argument_list|,
name|flags
operator||
name|O_NONBLOCK
argument_list|)
operator|==
operator|-
literal|1
condition|)
block|{
comment|/* Abort this application: */
name|abort
argument_list|()
expr_stmt|;
block|}
block|}
comment|/* Return the process ID: */
return|return
operator|(
name|ret
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

