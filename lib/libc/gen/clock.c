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
literal|"@(#)clock.c	8.1 (Berkeley) 6/4/93"
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
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<sys/resource.h>
end_include

begin_comment
comment|/*  * Convert usec to clock ticks; could do (usec * CLOCKS_PER_SEC) / 1000000,  * but this would overflow if we switch to nanosec.  */
end_comment

begin_define
define|#
directive|define
name|CONVTCK
parameter_list|(
name|r
parameter_list|)
value|((r).tv_sec * CLOCKS_PER_SEC \ 			 + (r).tv_usec / (1000000 / CLOCKS_PER_SEC))
end_define

begin_function
name|clock_t
name|clock
parameter_list|()
block|{
name|struct
name|rusage
name|ru
decl_stmt|;
if|if
condition|(
name|getrusage
argument_list|(
name|RUSAGE_SELF
argument_list|,
operator|&
name|ru
argument_list|)
condition|)
return|return
operator|(
operator|(
name|clock_t
operator|)
operator|-
literal|1
operator|)
return|;
return|return
operator|(
call|(
name|clock_t
call|)
argument_list|(
operator|(
name|CONVTCK
argument_list|(
name|ru
operator|.
name|ru_utime
argument_list|)
operator|+
name|CONVTCK
argument_list|(
name|ru
operator|.
name|ru_stime
argument_list|)
operator|)
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

