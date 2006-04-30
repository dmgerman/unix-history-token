begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1986, 1989, 1991, 1993  *	The Regents of the University of California.  All rights reserved.  * (c) UNIX System Laboratories, Inc.  * All or some portions of this file are derived from material licensed  * to the University of California by American Telephone and Telegraph  * Co. or Unix System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)signal.h	8.4 (Berkeley) 5/4/95  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_SIGNAL_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_SIGNAL_H_
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<sys/_types.h>
end_include

begin_include
include|#
directive|include
file|<sys/_sigset.h>
end_include

begin_include
include|#
directive|include
file|<machine/signal.h>
end_include

begin_comment
comment|/* sig_atomic_t; trap codes; sigcontext */
end_comment

begin_comment
comment|/*  * System defined signals.  */
end_comment

begin_if
if|#
directive|if
name|__POSIX_VISIBLE
operator|||
name|__XSI_VISIBLE
end_if

begin_define
define|#
directive|define
name|SIGHUP
value|1
end_define

begin_comment
comment|/* hangup */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SIGINT
value|2
end_define

begin_comment
comment|/* interrupt */
end_comment

begin_if
if|#
directive|if
name|__POSIX_VISIBLE
operator|||
name|__XSI_VISIBLE
end_if

begin_define
define|#
directive|define
name|SIGQUIT
value|3
end_define

begin_comment
comment|/* quit */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SIGILL
value|4
end_define

begin_comment
comment|/* illegal instr. (not reset when caught) */
end_comment

begin_if
if|#
directive|if
name|__XSI_VISIBLE
end_if

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

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

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

begin_if
if|#
directive|if
name|__POSIX_VISIBLE
operator|||
name|__XSI_VISIBLE
end_if

begin_define
define|#
directive|define
name|SIGKILL
value|9
end_define

begin_comment
comment|/* kill (cannot be caught or ignored) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__POSIX_VISIBLE
operator|>=
literal|200112
operator|||
name|__XSI_VISIBLE
end_if

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

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_define
define|#
directive|define
name|SIGSYS
value|12
end_define

begin_comment
comment|/* non-existent system call invoked */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__POSIX_VISIBLE
operator|||
name|__XSI_VISIBLE
end_if

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

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SIGTERM
value|15
end_define

begin_comment
comment|/* software termination signal from kill */
end_comment

begin_if
if|#
directive|if
name|__POSIX_VISIBLE
operator|>=
literal|200112
operator|||
name|__XSI_VISIBLE
end_if

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

begin_if
if|#
directive|if
name|__POSIX_VISIBLE
operator|||
name|__XSI_VISIBLE
end_if

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
comment|/* like TTIN if (tp->t_local&LTOSTOP) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_define
define|#
directive|define
name|SIGIO
value|23
end_define

begin_comment
comment|/* input/output possible signal */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__XSI_VISIBLE
end_if

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

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

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

begin_if
if|#
directive|if
name|__POSIX_VISIBLE
operator|||
name|__XSI_VISIBLE
end_if

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

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_define
define|#
directive|define
name|SIGTHR
value|32
end_define

begin_comment
comment|/* reserved by thread library. */
end_comment

begin_define
define|#
directive|define
name|SIGLWP
value|SIGTHR
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * XXX missing SIGRTMIN, SIGRTMAX.  */
end_comment

begin_define
define|#
directive|define
name|SIG_DFL
value|((__sighandler_t *)0)
end_define

begin_define
define|#
directive|define
name|SIG_IGN
value|((__sighandler_t *)1)
end_define

begin_define
define|#
directive|define
name|SIG_ERR
value|((__sighandler_t *)-1)
end_define

begin_comment
comment|/*  * XXX missing SIG_HOLD.  */
end_comment

begin_comment
comment|/*-  * Type of a signal handling function.  *  * Language spec sez signal handlers take exactly one arg, even though we  * actually supply three.  Ugh!  *  * We don't try to hide the difference by leaving out the args because  * that would cause warnings about conformant programs.  Nonconformant  * programs can avoid the warnings by casting to (__sighandler_t *) or  * sig_t before calling signal() or assigning to sa_handler or sv_handler.  *  * The kernel should reverse the cast before calling the function.  It  * has no way to do this, but on most machines 1-arg and 3-arg functions  * have the same calling protocol so there is no problem in practice.  * A bit in sa_flags could be used to specify the number of args.  */
end_comment

begin_typedef
typedef|typedef
name|void
name|__sighandler_t
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_typedef

begin_if
if|#
directive|if
name|__POSIX_VISIBLE
operator|||
name|__XSI_VISIBLE
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|_SIGSET_T_DECLARED
end_ifndef

begin_define
define|#
directive|define
name|_SIGSET_T_DECLARED
end_define

begin_typedef
typedef|typedef
name|__sigset_t
name|sigset_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__POSIX_VISIBLE
operator|>=
literal|199309
operator|||
name|__XSI_VISIBLE
operator|>=
literal|500
end_if

begin_union
union|union
name|sigval
block|{
comment|/* Members as suggested by Annex C of POSIX 1003.1b. */
name|int
name|sigval_int
decl_stmt|;
name|void
modifier|*
name|sigval_ptr
decl_stmt|;
block|}
union|;
end_union

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__POSIX_VISIBLE
operator|>=
literal|199309
end_if

begin_struct
struct|struct
name|sigevent
block|{
name|int
name|sigev_notify
decl_stmt|;
comment|/* Notification type */
union|union
block|{
name|int
name|__sigev_signo
decl_stmt|;
comment|/* Signal number */
name|int
name|__sigev_notify_kqueue
decl_stmt|;
block|}
name|__sigev_u
union|;
name|union
name|sigval
name|sigev_value
decl_stmt|;
comment|/* Signal value */
comment|/*  * XXX missing sigev_notify_function, sigev_notify_attributes.  */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|sigev_signo
value|__sigev_u.__sigev_signo
end_define

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_define
define|#
directive|define
name|sigev_notify_kqueue
value|__sigev_u.__sigev_notify_kqueue
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SIGEV_NONE
value|0
end_define

begin_comment
comment|/* No async notification */
end_comment

begin_define
define|#
directive|define
name|SIGEV_SIGNAL
value|1
end_define

begin_comment
comment|/* Generate a queued signal */
end_comment

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_define
define|#
directive|define
name|SIGEV_KEVENT
value|3
end_define

begin_comment
comment|/* Generate a kevent */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * XXX missing SIGEV_THREAD.  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __POSIX_VISIBLE>= 199309 */
end_comment

begin_if
if|#
directive|if
name|__POSIX_VISIBLE
operator|>=
literal|199309
operator|||
name|__XSI_VISIBLE
end_if

begin_typedef
typedef|typedef
struct|struct
name|__siginfo
block|{
name|int
name|si_signo
decl_stmt|;
comment|/* signal number */
name|int
name|si_errno
decl_stmt|;
comment|/* errno association */
comment|/* 	 * Cause of signal, one of the SI_ macros or signal-specific 	 * values, i.e. one of the FPE_... values for SIGFPE.  This 	 * value is equivalent to the second argument to an old-style 	 * FreeBSD signal handler. 	 */
name|int
name|si_code
decl_stmt|;
comment|/* signal code */
name|__pid_t
name|si_pid
decl_stmt|;
comment|/* sending process */
name|__uid_t
name|si_uid
decl_stmt|;
comment|/* sender's ruid */
name|int
name|si_status
decl_stmt|;
comment|/* exit value */
name|void
modifier|*
name|si_addr
decl_stmt|;
comment|/* faulting instruction */
name|union
name|sigval
name|si_value
decl_stmt|;
comment|/* signal value */
name|long
name|si_band
decl_stmt|;
comment|/* band event for SIGPOLL */
name|int
name|__spare__
index|[
literal|7
index|]
decl_stmt|;
comment|/* gimme some slack */
block|}
name|siginfo_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__POSIX_VISIBLE
operator|||
name|__XSI_VISIBLE
end_if

begin_struct_decl
struct_decl|struct
name|__siginfo
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * Signal vector "template" used in sigaction call.  */
end_comment

begin_struct
struct|struct
name|sigaction
block|{
union|union
block|{
name|void
function_decl|(
modifier|*
name|__sa_handler
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|__sa_sigaction
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|struct
name|__siginfo
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
block|}
name|__sigaction_u
union|;
comment|/* signal handler */
name|int
name|sa_flags
decl_stmt|;
comment|/* see signal options below */
name|sigset_t
name|sa_mask
decl_stmt|;
comment|/* signal mask to apply */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|sa_handler
value|__sigaction_u.__sa_handler
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__XSI_VISIBLE
end_if

begin_comment
comment|/* If SA_SIGINFO is set, sa_sigaction must be used instead of sa_handler. */
end_comment

begin_define
define|#
directive|define
name|sa_sigaction
value|__sigaction_u.__sa_sigaction
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__POSIX_VISIBLE
operator|||
name|__XSI_VISIBLE
end_if

begin_define
define|#
directive|define
name|SA_NOCLDSTOP
value|0x0008
end_define

begin_comment
comment|/* do not generate SIGCHLD on child stop */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __POSIX_VISIBLE || __XSI_VISIBLE */
end_comment

begin_if
if|#
directive|if
name|__XSI_VISIBLE
end_if

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
comment|/* restart system call on signal return */
end_comment

begin_define
define|#
directive|define
name|SA_RESETHAND
value|0x0004
end_define

begin_comment
comment|/* reset to SIG_DFL when taking signal */
end_comment

begin_define
define|#
directive|define
name|SA_NODEFER
value|0x0010
end_define

begin_comment
comment|/* don't mask the signal we're delivering */
end_comment

begin_define
define|#
directive|define
name|SA_NOCLDWAIT
value|0x0020
end_define

begin_comment
comment|/* don't keep zombies around */
end_comment

begin_define
define|#
directive|define
name|SA_SIGINFO
value|0x0040
end_define

begin_comment
comment|/* signal handler with SA_SIGINFO args */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_define
define|#
directive|define
name|NSIG
value|32
end_define

begin_comment
comment|/* number of old signals (counting 0) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__POSIX_VISIBLE
operator|||
name|__XSI_VISIBLE
end_if

begin_define
define|#
directive|define
name|SI_USER
value|0x10001
end_define

begin_define
define|#
directive|define
name|SI_QUEUE
value|0x10002
end_define

begin_define
define|#
directive|define
name|SI_TIMER
value|0x10003
end_define

begin_define
define|#
directive|define
name|SI_ASYNCIO
value|0x10004
end_define

begin_define
define|#
directive|define
name|SI_MESGQ
value|0x10005
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_define
define|#
directive|define
name|SI_UNDEFINED
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_typedef
typedef|typedef
name|__sighandler_t
modifier|*
name|sig_t
typedef|;
end_typedef

begin_comment
comment|/* type of pointer to a signal function */
end_comment

begin_typedef
typedef|typedef
name|void
name|__siginfohandler_t
parameter_list|(
name|int
parameter_list|,
name|struct
name|__siginfo
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__XSI_VISIBLE
end_if

begin_comment
comment|/*  * Structure used in sigaltstack call.  */
end_comment

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_typedef
typedef|typedef
struct|struct
name|sigaltstack
block|{
else|#
directive|else
typedef|typedef
struct|struct
block|{
endif|#
directive|endif
name|char
modifier|*
name|ss_sp
decl_stmt|;
comment|/* signal stack base */
name|__size_t
name|ss_size
decl_stmt|;
comment|/* signal stack length */
name|int
name|ss_flags
decl_stmt|;
comment|/* SS_DISABLE and/or SS_ONSTACK */
block|}
name|stack_t
typedef|;
define|#
directive|define
name|SS_ONSTACK
value|0x0001
comment|/* take signal on alternate stack */
define|#
directive|define
name|SS_DISABLE
value|0x0004
comment|/* disable taking signals on alternate stack */
define|#
directive|define
name|SIGSTKSZ
value|(MINSIGSTKSZ + 32768)
comment|/* recommended stack size */
endif|#
directive|endif
if|#
directive|if
name|__BSD_VISIBLE
comment|/*  * 4.3 compatibility:  * Signal vector "template" used in sigvec call.  */
struct|struct
name|sigvec
block|{
name|__sighandler_t
modifier|*
name|sv_handler
decl_stmt|;
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
define|#
directive|define
name|SV_ONSTACK
value|SA_ONSTACK
define|#
directive|define
name|SV_INTERRUPT
value|SA_RESTART
comment|/* same bit, opposite sense */
define|#
directive|define
name|SV_RESETHAND
value|SA_RESETHAND
define|#
directive|define
name|SV_NODEFER
value|SA_NODEFER
define|#
directive|define
name|SV_NOCLDSTOP
value|SA_NOCLDSTOP
define|#
directive|define
name|SV_SIGINFO
value|SA_SIGINFO
define|#
directive|define
name|sv_onstack
value|sv_flags
comment|/* isn't compatibility wonderful! */
endif|#
directive|endif
comment|/* Keep this in one place only */
if|#
directive|if
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|&&
name|defined
argument_list|(
name|COMPAT_43
argument_list|)
operator|&&
expr|\
operator|!
name|defined
argument_list|(
name|__i386__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__alpha__
argument_list|)
struct|struct
name|osigcontext
block|{
name|int
name|_not_used
decl_stmt|;
block|}
struct|;
endif|#
directive|endif
if|#
directive|if
name|__XSI_VISIBLE
comment|/*  * Structure used in sigstack call.  */
struct|struct
name|sigstack
block|{
comment|/* XXX ss_sp's type should be `void *'. */
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
endif|#
directive|endif
if|#
directive|if
name|__BSD_VISIBLE
operator|||
name|__POSIX_VISIBLE
operator|>
literal|0
operator|&&
name|__POSIX_VISIBLE
operator|<=
literal|200112
comment|/*  * Macro for converting signal number to a mask suitable for  * sigblock().  */
define|#
directive|define
name|sigmask
parameter_list|(
name|m
parameter_list|)
value|(1<< ((m)-1))
endif|#
directive|endif
if|#
directive|if
name|__BSD_VISIBLE
define|#
directive|define
name|BADSIG
value|SIG_ERR
endif|#
directive|endif
if|#
directive|if
name|__POSIX_VISIBLE
operator|||
name|__XSI_VISIBLE
comment|/*  * Flags for sigprocmask:  */
define|#
directive|define
name|SIG_BLOCK
value|1
comment|/* block specified signal set */
define|#
directive|define
name|SIG_UNBLOCK
value|2
comment|/* unblock specified signal set */
define|#
directive|define
name|SIG_SETMASK
value|3
comment|/* set specified signal set */
endif|#
directive|endif
comment|/*  * For historical reasons; programs expect signal's return value to be  * defined by<sys/signal.h>.  */
name|__BEGIN_DECLS
name|__sighandler_t
modifier|*
name|signal
parameter_list|(
name|int
parameter_list|,
name|__sighandler_t
modifier|*
parameter_list|)
function_decl|;
name|__END_DECLS
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_SIGNAL_H_ */
end_comment

end_unit

