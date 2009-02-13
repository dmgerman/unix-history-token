begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995-1998 John Birrell<jb@cimlogic.com.au>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY JOHN BIRRELL AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  *  */
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

begin_include
include|#
directive|include
file|<pthread.h>
end_include

begin_include
include|#
directive|include
file|"thr_private.h"
end_include

begin_expr_stmt
name|LT10_COMPAT_PRIVATE
argument_list|(
name|__open
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|LT10_COMPAT_DEFAULT
argument_list|(
name|open
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__weak_reference
argument_list|(
name|__open
argument_list|,
name|open
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
name|int
name|__open
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
name|struct
name|pthread
modifier|*
name|curthread
init|=
name|_get_curthread
argument_list|()
decl_stmt|;
name|int
name|ret
decl_stmt|;
name|int
name|mode
init|=
literal|0
decl_stmt|;
name|va_list
name|ap
decl_stmt|;
name|_thr_cancel_enter
argument_list|(
name|curthread
argument_list|)
expr_stmt|;
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
name|ret
operator|=
name|__sys_open
argument_list|(
name|path
argument_list|,
name|flags
argument_list|,
name|mode
argument_list|)
expr_stmt|;
comment|/* 	 * To avoid possible file handle leak,  	 * only check cancellation point if it is failure 	 */
name|_thr_cancel_leave
argument_list|(
name|curthread
argument_list|,
operator|(
name|ret
operator|==
operator|-
literal|1
operator|)
argument_list|)
expr_stmt|;
return|return
name|ret
return|;
block|}
end_function

end_unit

