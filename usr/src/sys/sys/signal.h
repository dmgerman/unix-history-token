begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1989 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)signal.h	7.10 (Berkeley) %G%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NSIG
end_ifndef

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

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_include
include|#
directive|include
file|"machine/trap.h"
end_include

begin_comment
comment|/* codes for SIGILL, SIGFPE */
end_comment

begin_else
else|#
directive|else
end_else

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _POSIX_SOURCE */
end_comment

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

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|sig_t
function_decl|)
parameter_list|()
function_decl|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|KERNEL
end_ifndef

begin_expr_stmt
name|void
argument_list|(
operator|*
name|signal
argument_list|()
argument_list|)
argument_list|()
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|unsigned
name|int
name|sigset_t
typedef|;
end_typedef

begin_if
if|#
directive|if
name|__STDC__
operator|||
name|c_plusplus
end_if

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

begin_else
else|#
directive|else
end_else

begin_function_decl
name|int
name|sigemptyset
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sigfillset
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sigaddset
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sigdelset
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sigismember
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

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
value|( *(set) = ~(sigset_t)0 )
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
comment|/* do not restart system on signal return */
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
value|(void (*)())-1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _POSIX_SOURCE */
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

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_define
define|#
directive|define
name|SIG_CATCH
value|(void (*)())2
end_define

begin_define
define|#
directive|define
name|SIG_HOLD
value|(void (*)())3
end_define

begin_define
define|#
directive|define
name|sigcantmask
value|(sigmask(SIGKILL)|sigmask(SIGSTOP))
end_define

begin_comment
comment|/*  * get signal action for process and signal; currently only for current process  */
end_comment

begin_define
define|#
directive|define
name|SIGACTION
parameter_list|(
name|p
parameter_list|,
name|sig
parameter_list|)
value|(u.u_signal[(sig)])
end_define

begin_comment
comment|/*  * Determine signal that should be delivered to process p, the current process,  * 0 if none.  If there is a pending stop signal with default action,  * the process stops in issig().  */
end_comment

begin_define
define|#
directive|define
name|CURSIG
parameter_list|(
name|p
parameter_list|)
define|\
value|(((p)->p_sig == 0 || \ 	    ((p)->p_flag&STRC) == 0&& ((p)->p_sig&~ (p)->p_sigmask) == 0) ? \ 	    0 : issig())
end_define

begin_comment
comment|/*  * Clear a pending signal from a process.  */
end_comment

begin_define
define|#
directive|define
name|CLRSIG
parameter_list|(
name|p
parameter_list|,
name|sig
parameter_list|)
value|{ (p)->p_sig&= ~sigmask(sig); }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

begin_if
if|#
directive|if
name|__STDC__
operator|||
name|c_plusplus
end_if

begin_function_decl
name|int
name|kill
parameter_list|(
name|pid_t
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
name|sigpending
parameter_list|(
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

begin_else
else|#
directive|else
end_else

begin_function_decl
name|int
name|kill
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sigaction
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sigprocmask
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sigpending
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sigsuspend
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NSIG */
end_comment

end_unit

