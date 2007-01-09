begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1985, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
literal|"@(#)ualarm.c	8.1 (Berkeley) 6/4/93"
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
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_define
define|#
directive|define
name|USPS
value|1000000
end_define

begin_comment
comment|/* # of microseconds in a second */
end_comment

begin_comment
comment|/*  * Generate a SIGALRM signal in ``usecs'' microseconds.  * If ``reload'' is non-zero, keep generating SIGALRM  * every ``reload'' microseconds after the first signal.  */
end_comment

begin_function
name|useconds_t
name|ualarm
parameter_list|(
name|usecs
parameter_list|,
name|reload
parameter_list|)
name|useconds_t
name|usecs
decl_stmt|;
name|useconds_t
name|reload
decl_stmt|;
block|{
name|struct
name|itimerval
name|new
decl_stmt|,
name|old
decl_stmt|;
name|new
operator|.
name|it_interval
operator|.
name|tv_usec
operator|=
name|reload
operator|%
name|USPS
expr_stmt|;
name|new
operator|.
name|it_interval
operator|.
name|tv_sec
operator|=
name|reload
operator|/
name|USPS
expr_stmt|;
name|new
operator|.
name|it_value
operator|.
name|tv_usec
operator|=
name|usecs
operator|%
name|USPS
expr_stmt|;
name|new
operator|.
name|it_value
operator|.
name|tv_sec
operator|=
name|usecs
operator|/
name|USPS
expr_stmt|;
if|if
condition|(
name|setitimer
argument_list|(
name|ITIMER_REAL
argument_list|,
operator|&
name|new
argument_list|,
operator|&
name|old
argument_list|)
operator|==
literal|0
condition|)
return|return
operator|(
name|old
operator|.
name|it_value
operator|.
name|tv_sec
operator|*
name|USPS
operator|+
name|old
operator|.
name|it_value
operator|.
name|tv_usec
operator|)
return|;
comment|/* else */
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
end_function

end_unit

