begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995-1998 John Birrell<jb@cimlogic.com.au>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by John Birrell.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY JOHN BIRRELL AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
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
name|int
name|_dup2
parameter_list|(
name|int
name|fd
parameter_list|,
name|int
name|newfd
parameter_list|)
block|{
name|int
name|ret
decl_stmt|;
name|int
name|newfd_opened
decl_stmt|;
comment|/* Check if the file descriptor is out of range: */
if|if
condition|(
name|newfd
operator|<
literal|0
operator|||
name|newfd
operator|>=
name|_thread_dtablesize
condition|)
block|{
comment|/* Return a bad file descriptor error: */
name|errno
operator|=
name|EBADF
expr_stmt|;
name|ret
operator|=
operator|-
literal|1
expr_stmt|;
block|}
comment|/* Lock the file descriptor: */
elseif|else
if|if
condition|(
operator|(
name|ret
operator|=
name|_FD_LOCK
argument_list|(
name|fd
argument_list|,
name|FD_RDWR
argument_list|,
name|NULL
argument_list|)
operator|)
operator|==
literal|0
condition|)
block|{
comment|/* Lock the file descriptor: */
if|if
condition|(
operator|!
operator|(
name|newfd_opened
operator|=
operator|(
name|_thread_fd_table
index|[
name|newfd
index|]
operator|!=
name|NULL
operator|)
operator|)
operator|||
operator|(
name|ret
operator|=
name|_FD_LOCK
argument_list|(
name|newfd
argument_list|,
name|FD_RDWR
argument_list|,
name|NULL
argument_list|)
operator|)
operator|==
literal|0
condition|)
block|{
comment|/* Perform the 'dup2' syscall: */
if|if
condition|(
operator|(
name|ret
operator|=
name|_thread_sys_dup2
argument_list|(
name|fd
argument_list|,
name|newfd
argument_list|)
operator|)
operator|<
literal|0
condition|)
block|{ 			}
comment|/* Initialise the file descriptor table entry: */
elseif|else
if|if
condition|(
name|_thread_fd_table_init
argument_list|(
name|ret
argument_list|)
operator|!=
literal|0
condition|)
block|{
comment|/* Quietly close the file: */
name|_thread_sys_close
argument_list|(
name|ret
argument_list|)
expr_stmt|;
comment|/* Reset the file descriptor: */
name|ret
operator|=
operator|-
literal|1
expr_stmt|;
block|}
else|else
block|{
comment|/* 				 * Save the file open flags so that they can 				 * be checked     later:  				 */
name|_thread_fd_table
index|[
name|ret
index|]
operator|->
name|flags
operator|=
name|_thread_fd_table
index|[
name|fd
index|]
operator|->
name|flags
expr_stmt|;
block|}
comment|/* Unlock the file descriptor: */
if|if
condition|(
name|newfd_opened
condition|)
name|_FD_UNLOCK
argument_list|(
name|newfd
argument_list|,
name|FD_RDWR
argument_list|)
expr_stmt|;
block|}
comment|/* Unlock the file descriptor: */
name|_FD_UNLOCK
argument_list|(
name|fd
argument_list|,
name|FD_RDWR
argument_list|)
expr_stmt|;
block|}
comment|/* Return the completion status: */
return|return
operator|(
name|ret
operator|)
return|;
block|}
end_function

begin_expr_stmt
name|__strong_reference
argument_list|(
name|_dup2
argument_list|,
name|dup2
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

