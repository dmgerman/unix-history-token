begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1989, 1991 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)signal.h	7.19 (Berkeley) %G%  */
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

begin_define
define|#
directive|define
name|NSIG
value|32
end_define

begin_comment
comment|/* counting 0; could be 33 (mask is 1-32) */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

begin_include
include|#
directive|include
file|<machine/trap.h>
end_include

begin_comment
comment|/* codes for SIGILL, SIGFPE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SIGHUP
value|1
end_define

begin_comment
comment|/* hangup */
end_comment

begin_define
define|#
directive|define
name|SIGINT
value|2
end_define

begin_comment
comment|/* interrupt */
end_comment

begin_define
define|#
directive|define
name|SIGQUIT
value|3
end_define

begin_comment
comment|/* quit */
end_comment

begin_define
define|#
directive|define
name|SIGILL
value|4
end_define

begin_comment
comment|/* illegal instruction (not reset when caught) */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

begin_define
define|#
directive|define
name|SIGTRAP
value|5
end_define

begin_comment
comment|/* trace trap (not reset when caught) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SIGABRT
value|6
end_define

begin_comment
comment|/* abort() */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

begin_define
define|#
directive|define
name|SIGIOT
value|SIGABRT
end_define

begin_comment
comment|/* compatibility */
end_comment

begin_define
define|#
directive|define
name|SIGEMT
value|7
end_define

begin_comment
comment|/* EMT instruction */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SIGFPE
value|8
end_define

begin_comment
comment|/* floating point exception */
end_comment

begin_define
define|#
directive|define
name|SIGKILL
value|9
end_define

begin_comment
comment|/* kill (cannot be caught or ignored) */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

begin_define
define|#
directive|define
name|SIGBUS
value|10
end_define

begin_comment
comment|/* bus error */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SIGSEGV
value|11
end_define

begin_comment
comment|/* segmentation violation */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

begin_define
define|#
directive|define
name|SIGSYS
value|12
end_define

begin_comment
comment|/* bad argument to system call */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SIGPIPE
value|13
end_define

begin_comment
comment|/* write on a pipe with no one to read it */
end_comment

begin_define
define|#
directive|define
name|SIGALRM
value|14
end_define

begin_comment
comment|/* alarm clock */
end_comment

begin_define
define|#
directive|define
name|SIGTERM
value|15
end_define

begin_comment
comment|/* software termination signal from kill */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

begin_define
define|#
directive|define
name|SIGURG
value|16
end_define

begin_comment
comment|/* urgent condition on IO channel */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SIGSTOP
value|17
end_define

begin_comment
comment|/* sendable stop signal not from tty */
end_comment

begin_define
define|#
directive|define
name|SIGTSTP
value|18
end_define

begin_comment
comment|/* stop signal from tty */
end_comment

begin_define
define|#
directive|define
name|SIGCONT
value|19
end_define

begin_comment
comment|/* continue a stopped process */
end_comment

begin_define
define|#
directive|define
name|SIGCHLD
value|20
end_define

begin_comment
comment|/* to parent on child stop or exit */
end_comment

begin_define
define|#
directive|define
name|SIGTTIN
value|21
end_define

begin_comment
comment|/* to readers pgrp upon background tty read */
end_comment

begin_define
define|#
directive|define
name|SIGTTOU
value|22
end_define

begin_comment
comment|/* like TTIN for output if (tp->t_local&LTOSTOP) */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

begin_define
define|#
directive|define
name|SIGIO
value|23
end_define

begin_comment
comment|/* input/output possible signal */
end_comment

begin_define
define|#
directive|define
name|SIGXCPU
value|24
end_define

begin_comment
comment|/* exceeded CPU time limit */
end_comment

begin_define
define|#
directive|define
name|SIGXFSZ
value|25
end_define

begin_comment
comment|/* exceeded file size limit */
end_comment

begin_define
define|#
directive|define
name|SIGVTALRM
value|26
end_define

begin_comment
comment|/* virtual time alarm */
end_comment

begin_define
define|#
directive|define
name|SIGPROF
value|27
end_define

begin_comment
comment|/* profiling time alarm */
end_comment

begin_define
define|#
directive|define
name|SIGWINCH
value|28
end_define

begin_comment
comment|/* window size changes */
end_comment

begin_define
define|#
directive|define
name|SIGINFO
value|29
end_define

begin_comment
comment|/* information request */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SIGUSR1
value|30
end_define

begin_comment
comment|/* user defined signal 1 */
end_comment

begin_define
define|#
directive|define
name|SIGUSR2
value|31
end_define

begin_comment
comment|/* user defined signal 2 */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

begin_typedef
typedef|typedef
name|void
argument_list|(
argument|*sig_t
argument_list|)
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|int
name|sig_atomic_t
typedef|;
end_typedef

begin_comment
comment|/* XXX should be machine dependent. */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|int
name|sigset_t
typedef|;
end_typedef

begin_decl_stmt
name|__BEGIN_DECLS
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

begin_macro
name|__END_DECLS
end_macro

begin_define
define|#
directive|define
name|sigemptyset
parameter_list|(
name|set
parameter_list|)
value|( *(set) = 0 )
end_define

begin_define
define|#
directive|define
name|sigfillset
parameter_list|(
name|set
parameter_list|)
value|( *(set) = ~(sigset_t)0, 0 )
end_define

begin_define
define|#
directive|define
name|sigaddset
parameter_list|(
name|set
parameter_list|,
name|signo
parameter_list|)
value|( *(set) |= 1<< ((signo) - 1), 0)
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
value|( *(set)&= ~(1<< ((signo) - 1)), 0)
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
value|( (*(set)& (1<< ((signo) - 1))) != 0)
end_define

begin_comment
comment|/*  * Signal vector "template" used in sigaction call.  */
end_comment

begin_struct
struct|struct
name|sigaction
block|{
name|void
function_decl|(
modifier|*
name|sa_handler
function_decl|)
parameter_list|()
function_decl|;
comment|/* signal handler */
name|sigset_t
name|sa_mask
decl_stmt|;
comment|/* signal mask to apply */
name|int
name|sa_flags
decl_stmt|;
comment|/* see signal options below */
block|}
struct|;
end_struct

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

begin_define
define|#
directive|define
name|SA_ONSTACK
value|0x0001
end_define

begin_comment
comment|/* take signal on signal stack */
end_comment

begin_define
define|#
directive|define
name|SA_RESTART
value|0x0002
end_define

begin_comment
comment|/* restart system on signal return */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SA_NOCLDSTOP
value|0x0004
end_define

begin_comment
comment|/* do not generate SIGCHLD on child stop */
end_comment

begin_comment
comment|/*  * Flags for sigprocmask:  */
end_comment

begin_define
define|#
directive|define
name|SIG_BLOCK
value|1
end_define

begin_comment
comment|/* block specified signal set */
end_comment

begin_define
define|#
directive|define
name|SIG_UNBLOCK
value|2
end_define

begin_comment
comment|/* unblock specified signal set */
end_comment

begin_define
define|#
directive|define
name|SIG_SETMASK
value|3
end_define

begin_comment
comment|/* set specified signal set */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

begin_comment
comment|/*  * 4.3 compatibility:  * Signal vector "template" used in sigvec call.  */
end_comment

begin_struct
struct|struct
name|sigvec
block|{
name|void
function_decl|(
modifier|*
name|sv_handler
function_decl|)
parameter_list|()
function_decl|;
comment|/* signal handler */
name|int
name|sv_mask
decl_stmt|;
comment|/* signal mask to apply */
name|int
name|sv_flags
decl_stmt|;
comment|/* see signal options below */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SV_ONSTACK
value|SA_ONSTACK
end_define

begin_define
define|#
directive|define
name|SV_INTERRUPT
value|SA_RESTART
end_define

begin_comment
comment|/* same bit, opposite sense */
end_comment

begin_define
define|#
directive|define
name|sv_onstack
value|sv_flags
end_define

begin_comment
comment|/* isn't compatibility wonderful! */
end_comment

begin_comment
comment|/*  * Structure used in sigaltstack call.  */
end_comment

begin_struct
struct|struct
name|sigaltstack
block|{
name|char
modifier|*
name|ss_base
decl_stmt|;
comment|/* signal stack base */
name|int
name|ss_len
decl_stmt|;
comment|/* signal stack length */
name|int
name|ss_onstack
decl_stmt|;
comment|/* current status */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Structure used in sigstack call.  */
end_comment

begin_struct
struct|struct
name|sigstack
block|{
name|char
modifier|*
name|ss_sp
decl_stmt|;
comment|/* signal stack pointer */
name|int
name|ss_onstack
decl_stmt|;
comment|/* current status */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Information pushed on stack when a signal is delivered.  * This is used by the kernel to restore state following  * execution of the signal handler.  It is also made available  * to the handler to allow it to restore state properly if  * a non-standard exit is performed.  */
end_comment

begin_struct
struct|struct
name|sigcontext
block|{
if|#
directive|if
name|defined
argument_list|(
name|vax
argument_list|)
operator|||
name|defined
argument_list|(
name|tahoe
argument_list|)
operator|||
name|defined
argument_list|(
name|hp300
argument_list|)
operator|||
name|defined
argument_list|(
name|i386
argument_list|)
name|int
name|sc_onstack
decl_stmt|;
comment|/* sigstack state to restore */
name|int
name|sc_mask
decl_stmt|;
comment|/* signal mask to restore */
name|int
name|sc_sp
decl_stmt|;
comment|/* sp to restore */
name|int
name|sc_fp
decl_stmt|;
comment|/* fp to restore */
name|int
name|sc_ap
decl_stmt|;
comment|/* ap to restore */
name|int
name|sc_pc
decl_stmt|;
comment|/* pc to restore */
name|int
name|sc_ps
decl_stmt|;
comment|/* psl to restore */
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|mips
argument_list|)
name|int
name|sc_onstack
decl_stmt|;
comment|/* sigstack state to restore */
name|int
name|sc_mask
decl_stmt|;
comment|/* signal mask to restore */
name|int
name|sc_pc
decl_stmt|;
comment|/* pc at time of signal */
name|int
name|sc_regs
index|[
literal|34
index|]
decl_stmt|;
comment|/* processor regs 0 to 31, mullo, mullhi */
name|int
name|sc_fpused
decl_stmt|;
comment|/* fp has been used */
name|int
name|sc_fpregs
index|[
literal|33
index|]
decl_stmt|;
comment|/* fp regs 0 to 31 and csr */
name|int
name|sc_fpc_eir
decl_stmt|;
comment|/* floating point exception instruction reg */
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/*  * Macro for converting signal number to a mask suitable for  * sigblock().  */
end_comment

begin_define
define|#
directive|define
name|sigmask
parameter_list|(
name|m
parameter_list|)
value|(1<< ((m)-1))
end_define

begin_define
define|#
directive|define
name|BADSIG
value|SIG_ERR
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_POSIX_SOURCE */
end_comment

begin_define
define|#
directive|define
name|SIG_DFL
value|(void (*)())0
end_define

begin_define
define|#
directive|define
name|SIG_IGN
value|(void (*)())1
end_define

begin_define
define|#
directive|define
name|SIG_ERR
value|(void (*)())-1
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|KERNEL
end_ifndef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_decl_stmt
name|__BEGIN_DECLS
name|void
argument_list|(
operator|*
name|signal
name|__P
argument_list|(
operator|(
name|int
operator|,
name|void
argument_list|(
argument|*
argument_list|)
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
operator|)
argument_list|)
argument_list|)
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_ANSI_SOURCE */
end_comment

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_ANSI_SOURCE&& !_POSIX_SOURCE */
end_comment

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SIGNAL_H_ */
end_comment

end_unit

