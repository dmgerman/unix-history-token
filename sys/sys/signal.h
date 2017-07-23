begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1986, 1989, 1991, 1993  *	The Regents of the University of California.  All rights reserved.  * (c) UNIX System Laboratories, Inc.  * All or some portions of this file are derived from material licensed  * to the University of California by American Telephone and Telegraph  * Co. or Unix System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)signal.h	8.4 (Berkeley) 5/4/95  * $FreeBSD$  */
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
file|<machine/_limits.h>
end_include

begin_comment
comment|/* __MINSIGSTKSZ */
end_comment

begin_include
include|#
directive|include
file|<machine/signal.h>
end_include

begin_comment
comment|/* sig_atomic_t; trap codes; sigcontext */
end_comment

begin_if
if|#
directive|if
name|__POSIX_VISIBLE
operator|>=
literal|200809
end_if

begin_include
include|#
directive|include
file|<sys/_pthreadtypes.h>
end_include

begin_include
include|#
directive|include
file|<sys/_timespec.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|_SIZE_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__size_t
name|size_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_SIZE_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_UID_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__uid_t
name|uid_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_UID_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __POSIX_VISIBLE>= 200809 */
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
name|__POSIX_VISIBLE
operator|>=
literal|200112
operator|||
name|__XSI_VISIBLE
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

begin_define
define|#
directive|define
name|SIGLIBRT
value|33
end_define

begin_comment
comment|/* reserved by real-time library. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SIGRTMIN
value|65
end_define

begin_define
define|#
directive|define
name|SIGRTMAX
value|126
end_define

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
comment|/* #define	SIG_CATCH	((__sighandler_t *)2) See signalvar.h */
end_comment

begin_define
define|#
directive|define
name|SIG_HOLD
value|((__sighandler_t *)3)
end_define

begin_comment
comment|/*  * Type of a signal handling function.  *  * Language spec sez signal handlers take exactly one arg, even though we  * actually supply three.  Ugh!  *  * We don't try to hide the difference by leaving out the args because  * that would cause warnings about conformant programs.  Nonconformant  * programs can avoid the warnings by casting to (__sighandler_t *) or  * sig_t before calling signal() or assigning to sa_handler or sv_handler.  *  * The kernel should reverse the cast before calling the function.  It  * has no way to do this, but on most machines 1-arg and 3-arg functions  * have the same calling protocol so there is no problem in practice.  * A bit in sa_flags could be used to specify the number of args.  */
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
name|sival_int
decl_stmt|;
name|void
modifier|*
name|sival_ptr
decl_stmt|;
comment|/* 6.0 compatibility */
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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_WANT_LWPINFO32
argument_list|)
operator|||
operator|(
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|&&
name|defined
argument_list|(
name|__LP64__
argument_list|)
operator|)
end_if

begin_union
union|union
name|sigval32
block|{
name|int
name|sival_int
decl_stmt|;
name|uint32_t
name|sival_ptr
decl_stmt|;
comment|/* 6.0 compatibility */
name|int
name|sigval_int
decl_stmt|;
name|uint32_t
name|sigval_ptr
decl_stmt|;
block|}
union|;
end_union

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
end_if

begin_struct_decl
struct_decl|struct
name|pthread_attr
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|sigevent
block|{
name|int
name|sigev_notify
decl_stmt|;
comment|/* Notification type */
name|int
name|sigev_signo
decl_stmt|;
comment|/* Signal number */
name|union
name|sigval
name|sigev_value
decl_stmt|;
comment|/* Signal value */
union|union
block|{
name|__lwpid_t
name|_threadid
decl_stmt|;
struct|struct
block|{
name|void
function_decl|(
modifier|*
name|_function
function_decl|)
parameter_list|(
name|union
name|sigval
parameter_list|)
function_decl|;
name|struct
name|pthread_attr
modifier|*
modifier|*
name|_attribute
decl_stmt|;
block|}
name|_sigev_thread
struct|;
name|unsigned
name|short
name|_kevent_flags
decl_stmt|;
name|long
name|__spare__
index|[
literal|8
index|]
decl_stmt|;
block|}
name|_sigev_un
union|;
block|}
struct|;
end_struct

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_define
define|#
directive|define
name|sigev_notify_kqueue
value|sigev_signo
end_define

begin_define
define|#
directive|define
name|sigev_notify_kevent_flags
value|_sigev_un._kevent_flags
end_define

begin_define
define|#
directive|define
name|sigev_notify_thread_id
value|_sigev_un._threadid
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|sigev_notify_function
value|_sigev_un._sigev_thread._function
end_define

begin_define
define|#
directive|define
name|sigev_notify_attributes
value|_sigev_un._sigev_thread._attribute
end_define

begin_define
define|#
directive|define
name|SIGEV_NONE
value|0
end_define

begin_comment
comment|/* No async notification. */
end_comment

begin_define
define|#
directive|define
name|SIGEV_SIGNAL
value|1
end_define

begin_comment
comment|/* Generate a queued signal. */
end_comment

begin_define
define|#
directive|define
name|SIGEV_THREAD
value|2
end_define

begin_comment
comment|/* Call back from another pthread. */
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
comment|/* Generate a kevent. */
end_comment

begin_define
define|#
directive|define
name|SIGEV_THREAD_ID
value|4
end_define

begin_comment
comment|/* Send signal to a kernel thread. */
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
union|union
block|{
struct|struct
block|{
name|int
name|_trapno
decl_stmt|;
comment|/* machine specific trap code */
block|}
name|_fault
struct|;
struct|struct
block|{
name|int
name|_timerid
decl_stmt|;
name|int
name|_overrun
decl_stmt|;
block|}
name|_timer
struct|;
struct|struct
block|{
name|int
name|_mqd
decl_stmt|;
block|}
name|_mesgq
struct|;
struct|struct
block|{
name|long
name|_band
decl_stmt|;
comment|/* band event for SIGPOLL */
block|}
name|_poll
struct|;
comment|/* was this ever used ? */
struct|struct
block|{
name|long
name|__spare1__
decl_stmt|;
name|int
name|__spare2__
index|[
literal|7
index|]
decl_stmt|;
block|}
name|__spare__
struct|;
block|}
name|_reason
union|;
block|}
name|siginfo_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|si_trapno
value|_reason._fault._trapno
end_define

begin_define
define|#
directive|define
name|si_timerid
value|_reason._timer._timerid
end_define

begin_define
define|#
directive|define
name|si_overrun
value|_reason._timer._overrun
end_define

begin_define
define|#
directive|define
name|si_mqd
value|_reason._mesgq._mqd
end_define

begin_define
define|#
directive|define
name|si_band
value|_reason._poll._band
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_WANT_LWPINFO32
argument_list|)
operator|||
operator|(
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|&&
name|defined
argument_list|(
name|__LP64__
argument_list|)
operator|)
end_if

begin_struct
struct|struct
name|siginfo32
block|{
name|int
name|si_signo
decl_stmt|;
comment|/* signal number */
name|int
name|si_errno
decl_stmt|;
comment|/* errno association */
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
name|uint32_t
name|si_addr
decl_stmt|;
comment|/* faulting instruction */
name|union
name|sigval32
name|si_value
decl_stmt|;
comment|/* signal value */
union|union
block|{
struct|struct
block|{
name|int
name|_trapno
decl_stmt|;
comment|/* machine specific trap code */
block|}
name|_fault
struct|;
struct|struct
block|{
name|int
name|_timerid
decl_stmt|;
name|int
name|_overrun
decl_stmt|;
block|}
name|_timer
struct|;
struct|struct
block|{
name|int
name|_mqd
decl_stmt|;
block|}
name|_mesgq
struct|;
struct|struct
block|{
name|int32_t
name|_band
decl_stmt|;
comment|/* band event for SIGPOLL */
block|}
name|_poll
struct|;
comment|/* was this ever used ? */
struct|struct
block|{
name|int32_t
name|__spare1__
decl_stmt|;
name|int
name|__spare2__
index|[
literal|7
index|]
decl_stmt|;
block|}
name|__spare__
struct|;
block|}
name|_reason
union|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/** si_code **/
end_comment

begin_comment
comment|/* codes for SIGILL */
end_comment

begin_define
define|#
directive|define
name|ILL_ILLOPC
value|1
end_define

begin_comment
comment|/* Illegal opcode.			*/
end_comment

begin_define
define|#
directive|define
name|ILL_ILLOPN
value|2
end_define

begin_comment
comment|/* Illegal operand.			*/
end_comment

begin_define
define|#
directive|define
name|ILL_ILLADR
value|3
end_define

begin_comment
comment|/* Illegal addressing mode.		*/
end_comment

begin_define
define|#
directive|define
name|ILL_ILLTRP
value|4
end_define

begin_comment
comment|/* Illegal trap.			*/
end_comment

begin_define
define|#
directive|define
name|ILL_PRVOPC
value|5
end_define

begin_comment
comment|/* Privileged opcode.			*/
end_comment

begin_define
define|#
directive|define
name|ILL_PRVREG
value|6
end_define

begin_comment
comment|/* Privileged register.			*/
end_comment

begin_define
define|#
directive|define
name|ILL_COPROC
value|7
end_define

begin_comment
comment|/* Coprocessor error.			*/
end_comment

begin_define
define|#
directive|define
name|ILL_BADSTK
value|8
end_define

begin_comment
comment|/* Internal stack error.		*/
end_comment

begin_comment
comment|/* codes for SIGBUS */
end_comment

begin_define
define|#
directive|define
name|BUS_ADRALN
value|1
end_define

begin_comment
comment|/* Invalid address alignment.		*/
end_comment

begin_define
define|#
directive|define
name|BUS_ADRERR
value|2
end_define

begin_comment
comment|/* Nonexistent physical address.	*/
end_comment

begin_define
define|#
directive|define
name|BUS_OBJERR
value|3
end_define

begin_comment
comment|/* Object-specific hardware error.	*/
end_comment

begin_comment
comment|/* codes for SIGSEGV */
end_comment

begin_define
define|#
directive|define
name|SEGV_MAPERR
value|1
end_define

begin_comment
comment|/* Address not mapped to object.	*/
end_comment

begin_define
define|#
directive|define
name|SEGV_ACCERR
value|2
end_define

begin_comment
comment|/* Invalid permissions for mapped	*/
end_comment

begin_comment
comment|/* object.				*/
end_comment

begin_comment
comment|/* codes for SIGFPE */
end_comment

begin_define
define|#
directive|define
name|FPE_INTOVF
value|1
end_define

begin_comment
comment|/* Integer overflow.			*/
end_comment

begin_define
define|#
directive|define
name|FPE_INTDIV
value|2
end_define

begin_comment
comment|/* Integer divide by zero.		*/
end_comment

begin_define
define|#
directive|define
name|FPE_FLTDIV
value|3
end_define

begin_comment
comment|/* Floating point divide by zero.	*/
end_comment

begin_define
define|#
directive|define
name|FPE_FLTOVF
value|4
end_define

begin_comment
comment|/* Floating point overflow.		*/
end_comment

begin_define
define|#
directive|define
name|FPE_FLTUND
value|5
end_define

begin_comment
comment|/* Floating point underflow.		*/
end_comment

begin_define
define|#
directive|define
name|FPE_FLTRES
value|6
end_define

begin_comment
comment|/* Floating point inexact result.	*/
end_comment

begin_define
define|#
directive|define
name|FPE_FLTINV
value|7
end_define

begin_comment
comment|/* Invalid floating point operation.	*/
end_comment

begin_define
define|#
directive|define
name|FPE_FLTSUB
value|8
end_define

begin_comment
comment|/* Subscript out of range.		*/
end_comment

begin_comment
comment|/* codes for SIGTRAP */
end_comment

begin_define
define|#
directive|define
name|TRAP_BRKPT
value|1
end_define

begin_comment
comment|/* Process breakpoint.			*/
end_comment

begin_define
define|#
directive|define
name|TRAP_TRACE
value|2
end_define

begin_comment
comment|/* Process trace trap.			*/
end_comment

begin_define
define|#
directive|define
name|TRAP_DTRACE
value|3
end_define

begin_comment
comment|/* DTrace induced trap.			*/
end_comment

begin_define
define|#
directive|define
name|TRAP_CAP
value|4
end_define

begin_comment
comment|/* Capabilities protective trap.	*/
end_comment

begin_comment
comment|/* codes for SIGCHLD */
end_comment

begin_define
define|#
directive|define
name|CLD_EXITED
value|1
end_define

begin_comment
comment|/* Child has exited			*/
end_comment

begin_define
define|#
directive|define
name|CLD_KILLED
value|2
end_define

begin_comment
comment|/* Child has terminated abnormally but	*/
end_comment

begin_comment
comment|/* did not create a core file		*/
end_comment

begin_define
define|#
directive|define
name|CLD_DUMPED
value|3
end_define

begin_comment
comment|/* Child has terminated abnormally and	*/
end_comment

begin_comment
comment|/* created a core file			*/
end_comment

begin_define
define|#
directive|define
name|CLD_TRAPPED
value|4
end_define

begin_comment
comment|/* Traced child has trapped		*/
end_comment

begin_define
define|#
directive|define
name|CLD_STOPPED
value|5
end_define

begin_comment
comment|/* Child has stopped			*/
end_comment

begin_define
define|#
directive|define
name|CLD_CONTINUED
value|6
end_define

begin_comment
comment|/* Stopped child has continued		*/
end_comment

begin_comment
comment|/* codes for SIGPOLL */
end_comment

begin_define
define|#
directive|define
name|POLL_IN
value|1
end_define

begin_comment
comment|/* Data input available			*/
end_comment

begin_define
define|#
directive|define
name|POLL_OUT
value|2
end_define

begin_comment
comment|/* Output buffers available		*/
end_comment

begin_define
define|#
directive|define
name|POLL_MSG
value|3
end_define

begin_comment
comment|/* Input message available		*/
end_comment

begin_define
define|#
directive|define
name|POLL_ERR
value|4
end_define

begin_comment
comment|/* I/O Error				*/
end_comment

begin_define
define|#
directive|define
name|POLL_PRI
value|5
end_define

begin_comment
comment|/* High priority input available	*/
end_comment

begin_define
define|#
directive|define
name|POLL_HUP
value|6
end_define

begin_comment
comment|/* Device disconnected			*/
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
name|SI_NOINFO
value|0
end_define

begin_comment
comment|/* No signal info besides si_signo. */
end_comment

begin_define
define|#
directive|define
name|SI_USER
value|0x10001
end_define

begin_comment
comment|/* Signal sent by kill(). */
end_comment

begin_define
define|#
directive|define
name|SI_QUEUE
value|0x10002
end_define

begin_comment
comment|/* Signal sent by the sigqueue(). */
end_comment

begin_define
define|#
directive|define
name|SI_TIMER
value|0x10003
end_define

begin_comment
comment|/* Signal generated by expiration of */
end_comment

begin_comment
comment|/* a timer set by timer_settime(). */
end_comment

begin_define
define|#
directive|define
name|SI_ASYNCIO
value|0x10004
end_define

begin_comment
comment|/* Signal generated by completion of */
end_comment

begin_comment
comment|/* an asynchronous I/O request.*/
end_comment

begin_define
define|#
directive|define
name|SI_MESGQ
value|0x10005
end_define

begin_comment
comment|/* Signal generated by arrival of a */
end_comment

begin_comment
comment|/* message on an empty message queue. */
end_comment

begin_define
define|#
directive|define
name|SI_KERNEL
value|0x10006
end_define

begin_define
define|#
directive|define
name|SI_LWP
value|0x10007
end_define

begin_comment
comment|/* Signal sent by thr_kill */
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

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_define
define|#
directive|define
name|__stack_t
value|sigaltstack
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|struct
name|__stack_t
name|stack_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SS_ONSTACK
value|0x0001
end_define

begin_comment
comment|/* take signal on alternate stack */
end_comment

begin_define
define|#
directive|define
name|SS_DISABLE
value|0x0004
end_define

begin_comment
comment|/* disable taking signals on alternate stack */
end_comment

begin_define
define|#
directive|define
name|MINSIGSTKSZ
value|__MINSIGSTKSZ
end_define

begin_comment
comment|/* minimum stack size */
end_comment

begin_define
define|#
directive|define
name|SIGSTKSZ
value|(MINSIGSTKSZ + 32768)
end_define

begin_comment
comment|/* recommended stack size */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Structure used in sigaltstack call.  Its definition is always  * needed for __ucontext.  If __BSD_VISIBLE is defined, the structure  * tag is actually sigaltstack.  */
end_comment

begin_struct
struct|struct
name|__stack_t
block|{
name|void
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
struct|;
end_struct

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_comment
comment|/*  * 4.3 compatibility:  * Signal vector "template" used in sigvec call.  */
end_comment

begin_struct
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
name|SV_RESETHAND
value|SA_RESETHAND
end_define

begin_define
define|#
directive|define
name|SV_NODEFER
value|SA_NODEFER
end_define

begin_define
define|#
directive|define
name|SV_NOCLDSTOP
value|SA_NOCLDSTOP
end_define

begin_define
define|#
directive|define
name|SV_SIGINFO
value|SA_SIGINFO
end_define

begin_define
define|#
directive|define
name|sv_onstack
value|sv_flags
end_define

begin_comment
comment|/* isn't compatibility wonderful! */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Keep this in one place only */
end_comment

begin_if
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
end_if

begin_struct
struct|struct
name|osigcontext
block|{
name|int
name|_not_used
decl_stmt|;
block|}
struct|;
end_struct

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
comment|/*  * Structure used in sigstack call.  */
end_comment

begin_struct
struct|struct
name|sigstack
block|{
name|void
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

begin_endif
endif|#
directive|endif
end_endif

begin_if
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
end_if

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
name|BADSIG
value|SIG_ERR
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * For historical reasons; programs expect signal's return value to be  * defined by<sys/signal.h>.  */
end_comment

begin_function_decl
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
end_function_decl

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_SIGNAL_H_ */
end_comment

end_unit

