begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)signal.h	5.6 (Berkeley) %G%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_USER_SIGNAL_H
end_ifndef

begin_define
define|#
directive|define
name|_USER_SIGNAL_H
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

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
specifier|const
name|char
modifier|*
specifier|const
name|sys_signame
index|[
name|NSIG
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
specifier|const
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
name|pid_t
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

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

begin_decl_stmt
name|int
name|killpg
name|__P
argument_list|(
operator|(
name|pid_t
operator|,
name|int
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
value|(*(set) = 0)
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
comment|/* !_USER_SIGNAL_H */
end_comment

end_unit

