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
literal|"@(#)usleep.c	8.1 (Berkeley) 6/4/93"
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

begin_include
include|#
directive|include
file|"libc_private.h"
end_include

begin_function
name|int
name|__usleep
parameter_list|(
name|useconds_t
name|useconds
parameter_list|)
block|{
name|struct
name|timespec
name|time_to_sleep
decl_stmt|;
name|time_to_sleep
operator|.
name|tv_nsec
operator|=
operator|(
name|useconds
operator|%
literal|1000000
operator|)
operator|*
literal|1000
expr_stmt|;
name|time_to_sleep
operator|.
name|tv_sec
operator|=
name|useconds
operator|/
literal|1000000
expr_stmt|;
return|return
operator|(
operator|(
operator|(
name|int
argument_list|(
operator|*
argument_list|)
argument_list|(
specifier|const
expr|struct
name|timespec
operator|*
argument_list|,
expr|struct
name|timespec
operator|*
argument_list|)
operator|)
name|__libc_interposing
index|[
name|INTERPOS_nanosleep
index|]
operator|)
operator|(
operator|&
name|time_to_sleep
operator|,
name|NULL
operator|)
operator|)
return|;
block|}
end_function

begin_expr_stmt
name|__weak_reference
argument_list|(
name|__usleep
argument_list|,
name|usleep
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__weak_reference
argument_list|(
name|__usleep
argument_list|,
name|_usleep
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

