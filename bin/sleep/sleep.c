begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1988, 1993, 1994  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_endif
unit|static char const copyright[] = "@(#) Copyright (c) 1988, 1993, 1994\n\ 	The Regents of the University of California.  All rights reserved.\n";
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_endif
unit|static char sccsid[] = "@(#)sleep.c	8.3 (Berkeley) 4/2/94";
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_endif
endif|#
directive|endif
end_endif

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
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<err.h>
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
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_function_decl
specifier|static
name|void
name|usage
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|static
specifier|volatile
name|sig_atomic_t
name|report_requested
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|void
name|report_request
parameter_list|(
name|int
name|signo
name|__unused
parameter_list|)
block|{
name|report_requested
operator|=
literal|1
expr_stmt|;
block|}
end_function

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{
name|struct
name|timespec
name|time_to_sleep
decl_stmt|;
name|double
name|d
decl_stmt|;
name|time_t
name|original
decl_stmt|;
name|char
name|buf
index|[
literal|2
index|]
decl_stmt|;
if|if
condition|(
name|argc
operator|!=
literal|2
condition|)
name|usage
argument_list|()
expr_stmt|;
if|if
condition|(
name|sscanf
argument_list|(
name|argv
index|[
literal|1
index|]
argument_list|,
literal|"%lf%1s"
argument_list|,
operator|&
name|d
argument_list|,
name|buf
argument_list|)
operator|!=
literal|1
condition|)
name|usage
argument_list|()
expr_stmt|;
if|if
condition|(
name|d
operator|>
name|INT_MAX
condition|)
name|usage
argument_list|()
expr_stmt|;
if|if
condition|(
name|d
operator|<=
literal|0
condition|)
return|return
operator|(
literal|0
operator|)
return|;
name|original
operator|=
name|time_to_sleep
operator|.
name|tv_sec
operator|=
operator|(
name|time_t
operator|)
name|d
expr_stmt|;
name|time_to_sleep
operator|.
name|tv_nsec
operator|=
literal|1e9
operator|*
operator|(
name|d
operator|-
name|time_to_sleep
operator|.
name|tv_sec
operator|)
expr_stmt|;
name|signal
argument_list|(
name|SIGINFO
argument_list|,
name|report_request
argument_list|)
expr_stmt|;
comment|/* 	 * Note: [EINTR] is supposed to happen only when a signal was handled 	 * but the kernel also returns it when a ptrace-based debugger 	 * attaches. This is a bug but it is hard to fix. 	 */
while|while
condition|(
name|nanosleep
argument_list|(
operator|&
name|time_to_sleep
argument_list|,
operator|&
name|time_to_sleep
argument_list|)
operator|!=
literal|0
condition|)
block|{
if|if
condition|(
name|report_requested
condition|)
block|{
comment|/* Reporting does not bother with nanoseconds. */
name|warnx
argument_list|(
literal|"about %d second(s) left out of the original %d"
argument_list|,
operator|(
name|int
operator|)
name|time_to_sleep
operator|.
name|tv_sec
argument_list|,
operator|(
name|int
operator|)
name|original
argument_list|)
expr_stmt|;
name|report_requested
operator|=
literal|0
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|errno
operator|!=
name|EINTR
condition|)
name|err
argument_list|(
literal|1
argument_list|,
literal|"nanosleep"
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|void
name|usage
parameter_list|(
name|void
parameter_list|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"usage: sleep seconds\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

