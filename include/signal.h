begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)signal.h	8.3 (Berkeley) 3/30/94  */
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
file|<sys/signal.h>
end_include

begin_include
include|#
directive|include
file|<machine/ansi.h>
end_include

begin_include
include|#
directive|include
file|<sys/_posix.h>
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

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|__BEGIN_DECLS
name|int
name|raise
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|_ANSI_SOURCE
end_ifndef

begin_decl_stmt
name|int
name|kill
name|__P
argument_list|(
operator|(
name|_BSD_PID_T_
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sigaction
name|__P
argument_list|(
operator|(
name|int
operator|,
specifier|const
expr|struct
name|sigaction
operator|*
operator|,
expr|struct
name|sigaction
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sigaddset
name|__P
argument_list|(
operator|(
name|sigset_t
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sigdelset
name|__P
argument_list|(
operator|(
name|sigset_t
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sigemptyset
name|__P
argument_list|(
operator|(
name|sigset_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sigfillset
name|__P
argument_list|(
operator|(
name|sigset_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sigismember
name|__P
argument_list|(
operator|(
specifier|const
name|sigset_t
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

begin_struct_decl
struct_decl|struct
name|timespec
struct_decl|;
end_struct_decl

begin_decl_stmt
name|int
name|signanosleep
name|__P
argument_list|(
operator|(
specifier|const
expr|struct
name|timespec
operator|*
operator|,
expr|struct
name|timespec
operator|*
operator|,
name|sigset_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|int
name|sigpending
name|__P
argument_list|(
operator|(
name|sigset_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sigprocmask
name|__P
argument_list|(
operator|(
name|int
operator|,
specifier|const
name|sigset_t
operator|*
operator|,
name|sigset_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sigsuspend
name|__P
argument_list|(
operator|(
specifier|const
name|sigset_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|_POSIX4_VISIBLE
end_ifdef

begin_typedef
typedef|typedef
struct|struct
name|siginfo
block|{
name|int
name|si_signo
decl_stmt|;
comment|/* Signal number */
name|int
name|si_code
decl_stmt|;
comment|/* Cause of the signal */
name|union
name|sigval
name|si_value
decl_stmt|;
comment|/* Signal value */
block|}
name|siginfo_t
typedef|;
end_typedef

begin_decl_stmt
name|__BEGIN_DECLS
name|int
name|sigqueue
name|__P
argument_list|(
operator|(
name|_BSD_PID_T_
operator|,
name|int
operator|,
specifier|const
expr|union
name|sigval
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sigtimedwait
name|__P
argument_list|(
operator|(
specifier|const
name|sigset_t
operator|*
operator|,
name|siginfo_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sigwaitinfo
name|__P
argument_list|(
operator|(
specifier|const
name|sigset_t
operator|*
operator|,
name|siginfo_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__END_DECLS
endif|#
directive|endif
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
name|int
name|killpg
name|__P
argument_list|(
operator|(
name|_BSD_PID_T_
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sigaltstack
name|__P
argument_list|(
operator|(
specifier|const
expr|struct
name|sigaltstack
operator|*
operator|,
expr|struct
name|sigaltstack
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sigblock
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|siginterrupt
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sigpause
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sigreturn
name|__P
argument_list|(
operator|(
expr|struct
name|sigcontext
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sigsetmask
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sigstack
name|__P
argument_list|(
operator|(
specifier|const
expr|struct
name|sigstack
operator|*
operator|,
expr|struct
name|sigstack
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sigvec
name|__P
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|sigvec
operator|*
operator|,
expr|struct
name|sigvec
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|psignal
name|__P
argument_list|(
operator|(
name|unsigned
name|int
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

begin_ifndef
ifndef|#
directive|ifndef
name|_ANSI_SOURCE
end_ifndef

begin_comment
comment|/* List definitions after function declarations, or Reiser cpp gets upset. */
end_comment

begin_define
define|#
directive|define
name|sigaddset
parameter_list|(
name|set
parameter_list|,
name|signo
parameter_list|)
value|(*(set) |= 1<< ((signo) - 1), 0)
end_define

begin_define
define|#
directive|define
name|sigdelset
parameter_list|(
name|set
parameter_list|,
name|signo
parameter_list|)
value|(*(set)&= ~(1<< ((signo) - 1)), 0)
end_define

begin_define
define|#
directive|define
name|sigemptyset
parameter_list|(
name|set
parameter_list|)
value|(*(set) = 0, 0)
end_define

begin_define
define|#
directive|define
name|sigfillset
parameter_list|(
name|set
parameter_list|)
value|(*(set) = ~(sigset_t)0, 0)
end_define

begin_define
define|#
directive|define
name|sigismember
parameter_list|(
name|set
parameter_list|,
name|signo
parameter_list|)
value|((*(set)& (1<< ((signo) - 1))) != 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_ANSI_SOURCE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SIGNAL_H_ */
end_comment

end_unit

