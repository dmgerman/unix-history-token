begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995-1998 John Birrell<jb@cimlogic.com.au>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by John Birrell.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY JOHN BIRRELL AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<dirent.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
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
name|open
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|,
name|int
name|flags
parameter_list|,
modifier|...
parameter_list|)
block|{
name|int
name|fd
decl_stmt|;
name|int
name|mode
init|=
literal|0
decl_stmt|;
name|int
name|status
decl_stmt|;
name|va_list
name|ap
decl_stmt|;
comment|/* Check if the file is being created: */
if|if
condition|(
name|flags
operator|&
name|O_CREAT
condition|)
block|{
comment|/* Get the creation mode: */
name|va_start
argument_list|(
name|ap
argument_list|,
name|flags
argument_list|)
expr_stmt|;
name|mode
operator|=
name|va_arg
argument_list|(
name|ap
argument_list|,
name|int
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|ap
argument_list|)
expr_stmt|;
block|}
comment|/* Open the file: */
if|if
condition|(
operator|(
name|fd
operator|=
name|_thread_sys_open
argument_list|(
name|path
argument_list|,
name|flags
argument_list|,
name|mode
argument_list|)
operator|)
operator|<
literal|0
condition|)
block|{ 	}
comment|/* Initialise the file descriptor table entry: */
elseif|else
if|if
condition|(
name|_thread_fd_table_init
argument_list|(
name|fd
argument_list|)
operator|!=
literal|0
condition|)
block|{
comment|/* Quietly close the file: */
name|_thread_sys_close
argument_list|(
name|fd
argument_list|)
expr_stmt|;
comment|/* Reset the file descriptor: */
name|fd
operator|=
operator|-
literal|1
expr_stmt|;
block|}
comment|/* Return the file descriptor or -1 on error: */
return|return
operator|(
name|fd
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

