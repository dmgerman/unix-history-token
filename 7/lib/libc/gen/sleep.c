begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LIBC_SCCS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
end_if

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)sleep.c	8.1 (Berkeley) 6/4/93"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LIBC_SCCS and not lint */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|"namespace.h"
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
file|<time.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|"un-namespace.h"
end_include

begin_function
name|unsigned
name|int
name|__sleep
parameter_list|(
name|seconds
parameter_list|)
name|unsigned
name|int
name|seconds
decl_stmt|;
block|{
name|struct
name|timespec
name|time_to_sleep
decl_stmt|;
name|struct
name|timespec
name|time_remaining
decl_stmt|;
comment|/* 	 * Avoid overflow when `seconds' is huge.  This assumes that 	 * the maximum value for a time_t is>= INT_MAX. 	 */
if|if
condition|(
name|seconds
operator|>
name|INT_MAX
condition|)
return|return
operator|(
name|seconds
operator|-
name|INT_MAX
operator|+
name|__sleep
argument_list|(
name|INT_MAX
argument_list|)
operator|)
return|;
name|time_to_sleep
operator|.
name|tv_sec
operator|=
name|seconds
expr_stmt|;
name|time_to_sleep
operator|.
name|tv_nsec
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|_nanosleep
argument_list|(
operator|&
name|time_to_sleep
argument_list|,
operator|&
name|time_remaining
argument_list|)
operator|!=
operator|-
literal|1
condition|)
return|return
operator|(
literal|0
operator|)
return|;
if|if
condition|(
name|errno
operator|!=
name|EINTR
condition|)
return|return
operator|(
name|seconds
operator|)
return|;
comment|/* best guess */
return|return
operator|(
name|time_remaining
operator|.
name|tv_sec
operator|+
operator|(
name|time_remaining
operator|.
name|tv_nsec
operator|!=
literal|0
operator|)
operator|)
return|;
comment|/* round up */
block|}
end_function

begin_expr_stmt
name|__weak_reference
argument_list|(
name|__sleep
argument_list|,
name|sleep
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__weak_reference
argument_list|(
name|__sleep
argument_list|,
name|_sleep
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

