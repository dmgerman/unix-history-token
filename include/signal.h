begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)signal.h	8.3 (Berkeley) 3/30/94  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SIGNAL_H_
end_ifndef

begin_define
define|#
directive|define
name|_SIGNAL_H_
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<sys/_posix.h>
end_include

begin_include
include|#
directive|include
file|<machine/ansi.h>
end_include

begin_include
include|#
directive|include
file|<sys/signal.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_ANSI_SOURCE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_POSIX_SOURCE
argument_list|)
end_if

begin_decl_stmt
specifier|extern
name|__const
name|char
modifier|*
name|__const
name|sys_signame
index|[
name|NSIG
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|__const
name|char
modifier|*
name|__const
name|sys_siglist
index|[
name|NSIG
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|__const
name|int
name|sys_nsig
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|__BEGIN_DECLS
name|int
name|raise
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|_ANSI_SOURCE
end_ifndef

begin_function_decl
name|int
name|kill
parameter_list|(
name|_BSD_PID_T_
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sigaction
parameter_list|(
name|int
parameter_list|,
specifier|const
name|struct
name|sigaction
modifier|*
parameter_list|,
name|struct
name|sigaction
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sigaddset
parameter_list|(
name|sigset_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sigdelset
parameter_list|(
name|sigset_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sigemptyset
parameter_list|(
name|sigset_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sigfillset
parameter_list|(
name|sigset_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sigismember
parameter_list|(
specifier|const
name|sigset_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sigpending
parameter_list|(
name|sigset_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sigprocmask
parameter_list|(
name|int
parameter_list|,
specifier|const
name|sigset_t
modifier|*
parameter_list|,
name|sigset_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sigsuspend
parameter_list|(
specifier|const
name|sigset_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sigwait
parameter_list|(
specifier|const
name|sigset_t
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|_P1003_1B_VISIBLE
end_ifdef

begin_function_decl
name|__BEGIN_DECLS
name|int
name|sigqueue
parameter_list|(
name|_BSD_PID_T_
parameter_list|,
name|int
parameter_list|,
specifier|const
name|union
name|sigval
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sigtimedwait
parameter_list|(
specifier|const
name|sigset_t
modifier|*
parameter_list|,
name|siginfo_t
modifier|*
parameter_list|,
specifier|const
name|struct
name|timespec
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sigwaitinfo
parameter_list|(
specifier|const
name|sigset_t
modifier|*
parameter_list|,
name|siginfo_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|__END_DECLS
endif|#
directive|endif
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
name|int
name|killpg
parameter_list|(
name|_BSD_PID_T_
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sigaltstack
parameter_list|(
specifier|const
name|stack_t
modifier|*
parameter_list|,
name|stack_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sigblock
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|siginterrupt
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sigpause
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sigreturn
parameter_list|(
specifier|const
name|struct
name|__ucontext
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sigsetmask
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sigstack
parameter_list|(
specifier|const
name|struct
name|sigstack
modifier|*
parameter_list|,
name|struct
name|sigstack
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sigvec
parameter_list|(
name|int
parameter_list|,
name|struct
name|sigvec
modifier|*
parameter_list|,
name|struct
name|sigvec
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|psignal
parameter_list|(
name|unsigned
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_POSIX_SOURCE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_ANSI_SOURCE */
end_comment

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SIGNAL_H_ */
end_comment

end_unit

