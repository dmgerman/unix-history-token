begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)signalvar.h	8.6 (Berkeley) 2/19/95  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_SIGNALVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_SIGNALVAR_H_
end_define

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<sys/_lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/_mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/signal.h>
end_include

begin_comment
comment|/*  * Kernel signal definitions and data structures,  * not exported to user programs.  */
end_comment

begin_comment
comment|/*  * Logical process signal actions and state, needed only within the process  * The mapping between sigacts and proc structures is 1:1 except for rfork()  * processes masquerading as threads which use one structure for the whole  * group.  All members are locked by the included mutex.  The reference count  * and mutex must be last for the bcopy in sigacts_copy() to work.  */
end_comment

begin_struct
struct|struct
name|sigacts
block|{
name|sig_t
name|ps_sigact
index|[
name|_SIG_MAXSIG
index|]
decl_stmt|;
comment|/* Disposition of signals. */
name|sigset_t
name|ps_catchmask
index|[
name|_SIG_MAXSIG
index|]
decl_stmt|;
comment|/* Signals to be blocked. */
name|sigset_t
name|ps_sigonstack
decl_stmt|;
comment|/* Signals to take on sigstack. */
name|sigset_t
name|ps_sigintr
decl_stmt|;
comment|/* Signals that interrupt syscalls. */
name|sigset_t
name|ps_sigreset
decl_stmt|;
comment|/* Signals that reset when caught. */
name|sigset_t
name|ps_signodefer
decl_stmt|;
comment|/* Signals not masked while handled. */
name|sigset_t
name|ps_siginfo
decl_stmt|;
comment|/* Signals that want SA_SIGINFO args. */
name|sigset_t
name|ps_sigignore
decl_stmt|;
comment|/* Signals being ignored. */
name|sigset_t
name|ps_sigcatch
decl_stmt|;
comment|/* Signals being caught by user. */
name|sigset_t
name|ps_freebsd4
decl_stmt|;
comment|/* signals using freebsd4 ucontext. */
name|sigset_t
name|ps_osigset
decl_stmt|;
comment|/* Signals using<= 3.x osigset_t. */
name|sigset_t
name|ps_usertramp
decl_stmt|;
comment|/* SunOS compat; libc sigtramp. XXX */
name|int
name|ps_flag
decl_stmt|;
name|int
name|ps_refcnt
decl_stmt|;
name|struct
name|mtx
name|ps_mtx
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PS_NOCLDWAIT
value|0x0001
end_define

begin_comment
comment|/* No zombies if child dies */
end_comment

begin_define
define|#
directive|define
name|PS_NOCLDSTOP
value|0x0002
end_define

begin_comment
comment|/* No SIGCHLD when children stop. */
end_comment

begin_define
define|#
directive|define
name|PS_CLDSIGIGN
value|0x0004
end_define

begin_comment
comment|/* The SIGCHLD handler is SIG_IGN. */
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
end_if

begin_comment
comment|/*  * Compatibility.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|struct
name|osigcontext
name|si_sc
decl_stmt|;
name|int
name|si_signo
decl_stmt|;
name|int
name|si_code
decl_stmt|;
name|union
name|sigval
name|si_value
decl_stmt|;
block|}
name|osiginfo_t
typedef|;
end_typedef

begin_struct
struct|struct
name|osigaction
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
name|osiginfo_t
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
name|osigset_t
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

begin_typedef
typedef|typedef
name|void
name|__osiginfohandler_t
parameter_list|(
name|int
parameter_list|,
name|osiginfo_t
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

begin_comment
comment|/* _KERNEL&& COMPAT_43 */
end_comment

begin_comment
comment|/* additional signal action values, used only temporarily/internally */
end_comment

begin_define
define|#
directive|define
name|SIG_CATCH
value|((__sighandler_t *)2)
end_define

begin_define
define|#
directive|define
name|SIG_HOLD
value|((__sighandler_t *)3)
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
value|(p->p_sigacts->ps_sigact[_SIG_IDX(sig)])
end_define

begin_comment
comment|/*  * sigset_t manipulation macros  */
end_comment

begin_define
define|#
directive|define
name|SIGADDSET
parameter_list|(
name|set
parameter_list|,
name|signo
parameter_list|)
define|\
value|((set).__bits[_SIG_WORD(signo)] |= _SIG_BIT(signo))
end_define

begin_define
define|#
directive|define
name|SIGDELSET
parameter_list|(
name|set
parameter_list|,
name|signo
parameter_list|)
define|\
value|((set).__bits[_SIG_WORD(signo)]&= ~_SIG_BIT(signo))
end_define

begin_define
define|#
directive|define
name|SIGEMPTYSET
parameter_list|(
name|set
parameter_list|)
define|\
value|do {								\ 		int __i;						\ 		for (__i = 0; __i< _SIG_WORDS; __i++)			\ 			(set).__bits[__i] = 0;				\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|SIGFILLSET
parameter_list|(
name|set
parameter_list|)
define|\
value|do {								\ 		int __i;						\ 		for (__i = 0; __i< _SIG_WORDS; __i++)			\ 			(set).__bits[__i] = ~0U;			\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|SIGISMEMBER
parameter_list|(
name|set
parameter_list|,
name|signo
parameter_list|)
define|\
value|((set).__bits[_SIG_WORD(signo)]& _SIG_BIT(signo))
end_define

begin_define
define|#
directive|define
name|SIGISEMPTY
parameter_list|(
name|set
parameter_list|)
value|(__sigisempty(&(set)))
end_define

begin_define
define|#
directive|define
name|SIGNOTEMPTY
parameter_list|(
name|set
parameter_list|)
value|(!__sigisempty(&(set)))
end_define

begin_define
define|#
directive|define
name|SIGSETEQ
parameter_list|(
name|set1
parameter_list|,
name|set2
parameter_list|)
value|(__sigseteq(&(set1),&(set2)))
end_define

begin_define
define|#
directive|define
name|SIGSETNEQ
parameter_list|(
name|set1
parameter_list|,
name|set2
parameter_list|)
value|(!__sigseteq(&(set1),&(set2)))
end_define

begin_define
define|#
directive|define
name|SIGSETOR
parameter_list|(
name|set1
parameter_list|,
name|set2
parameter_list|)
define|\
value|do {								\ 		int __i;						\ 		for (__i = 0; __i< _SIG_WORDS; __i++)			\ 			(set1).__bits[__i] |= (set2).__bits[__i];	\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|SIGSETAND
parameter_list|(
name|set1
parameter_list|,
name|set2
parameter_list|)
define|\
value|do {								\ 		int __i;						\ 		for (__i = 0; __i< _SIG_WORDS; __i++)			\ 			(set1).__bits[__i]&= (set2).__bits[__i];	\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|SIGSETNAND
parameter_list|(
name|set1
parameter_list|,
name|set2
parameter_list|)
define|\
value|do {								\ 		int __i;						\ 		for (__i = 0; __i< _SIG_WORDS; __i++)			\ 			(set1).__bits[__i]&= ~(set2).__bits[__i];	\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|SIGSETLO
parameter_list|(
name|set1
parameter_list|,
name|set2
parameter_list|)
value|((set1).__bits[0] = (set2).__bits[0])
end_define

begin_define
define|#
directive|define
name|SIGSETOLD
parameter_list|(
name|set
parameter_list|,
name|oset
parameter_list|)
value|((set).__bits[0] = (oset))
end_define

begin_define
define|#
directive|define
name|SIG_CANTMASK
parameter_list|(
name|set
parameter_list|)
define|\
value|SIGDELSET(set, SIGKILL), SIGDELSET(set, SIGSTOP)
end_define

begin_define
define|#
directive|define
name|SIG_STOPSIGMASK
parameter_list|(
name|set
parameter_list|)
define|\
value|SIGDELSET(set, SIGSTOP), SIGDELSET(set, SIGTSTP),		\ 	SIGDELSET(set, SIGTTIN), SIGDELSET(set, SIGTTOU)
end_define

begin_define
define|#
directive|define
name|SIG_CONTSIGMASK
parameter_list|(
name|set
parameter_list|)
define|\
value|SIGDELSET(set, SIGCONT)
end_define

begin_define
define|#
directive|define
name|sigcantmask
value|(sigmask(SIGKILL) | sigmask(SIGSTOP))
end_define

begin_define
define|#
directive|define
name|SIG2OSIG
parameter_list|(
name|sig
parameter_list|,
name|osig
parameter_list|)
value|(osig = (sig).__bits[0])
end_define

begin_define
define|#
directive|define
name|OSIG2SIG
parameter_list|(
name|osig
parameter_list|,
name|sig
parameter_list|)
value|SIGEMPTYSET(sig); (sig).__bits[0] = osig
end_define

begin_function
specifier|static
name|__inline
name|int
name|__sigisempty
parameter_list|(
name|sigset_t
modifier|*
name|set
parameter_list|)
block|{
name|int
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|_SIG_WORDS
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|set
operator|->
name|__bits
index|[
name|i
index|]
condition|)
return|return
operator|(
literal|0
operator|)
return|;
block|}
return|return
operator|(
literal|1
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|__sigseteq
parameter_list|(
name|sigset_t
modifier|*
name|set1
parameter_list|,
name|sigset_t
modifier|*
name|set2
parameter_list|)
block|{
name|int
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|_SIG_WORDS
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|set1
operator|->
name|__bits
index|[
name|i
index|]
operator|!=
name|set2
operator|->
name|__bits
index|[
name|i
index|]
condition|)
return|return
operator|(
literal|0
operator|)
return|;
block|}
return|return
operator|(
literal|1
operator|)
return|;
block|}
end_function

begin_struct
struct|struct
name|osigevent
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
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
struct|struct
name|ksiginfo
block|{
name|TAILQ_ENTRY
argument_list|(
argument|ksiginfo
argument_list|)
name|ksi_link
expr_stmt|;
name|siginfo_t
name|ksi_info
decl_stmt|;
name|int
name|ksi_flags
decl_stmt|;
name|struct
name|sigqueue
modifier|*
name|ksi_sigq
decl_stmt|;
block|}
name|ksiginfo_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ksi_signo
value|ksi_info.si_signo
end_define

begin_define
define|#
directive|define
name|ksi_errno
value|ksi_info.si_errno
end_define

begin_define
define|#
directive|define
name|ksi_code
value|ksi_info.si_code
end_define

begin_define
define|#
directive|define
name|ksi_pid
value|ksi_info.si_pid
end_define

begin_define
define|#
directive|define
name|ksi_uid
value|ksi_info.si_uid
end_define

begin_define
define|#
directive|define
name|ksi_status
value|ksi_info.si_status
end_define

begin_define
define|#
directive|define
name|ksi_addr
value|ksi_info.si_addr
end_define

begin_define
define|#
directive|define
name|ksi_value
value|ksi_info.si_value
end_define

begin_define
define|#
directive|define
name|ksi_band
value|ksi_info.si_band
end_define

begin_define
define|#
directive|define
name|ksi_trapno
value|ksi_info.si_trapno
end_define

begin_define
define|#
directive|define
name|ksi_overrun
value|ksi_info.si_overrun
end_define

begin_define
define|#
directive|define
name|ksi_timerid
value|ksi_info.si_timerid
end_define

begin_define
define|#
directive|define
name|ksi_mqd
value|ksi_info.si_mqd
end_define

begin_comment
comment|/* bits for ksi_flags */
end_comment

begin_define
define|#
directive|define
name|KSI_TRAP
value|0x01
end_define

begin_comment
comment|/* Generated by trap. */
end_comment

begin_define
define|#
directive|define
name|KSI_EXT
value|0x02
end_define

begin_comment
comment|/* Externally managed ksi. */
end_comment

begin_define
define|#
directive|define
name|KSI_INS
value|0x04
end_define

begin_comment
comment|/* Directly insert ksi, not the copy */
end_comment

begin_define
define|#
directive|define
name|KSI_COPYMASK
value|KSI_TRAP
end_define

begin_define
define|#
directive|define
name|KSI_ONQ
parameter_list|(
name|ksi
parameter_list|)
value|((ksi)->ksi_sigq != NULL)
end_define

begin_typedef
typedef|typedef
struct|struct
name|sigqueue
block|{
name|sigset_t
name|sq_signals
decl_stmt|;
comment|/* All pending signals. */
name|sigset_t
name|sq_kill
decl_stmt|;
comment|/* Legacy depth 1 queue. */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|ksiginfo
argument_list|)
name|sq_list
expr_stmt|;
comment|/* Queued signal info. */
name|struct
name|proc
modifier|*
name|sq_proc
decl_stmt|;
name|int
name|sq_flags
decl_stmt|;
block|}
name|sigqueue_t
typedef|;
end_typedef

begin_comment
comment|/* Flags for ksi_flags */
end_comment

begin_define
define|#
directive|define
name|SQ_INIT
value|0x01
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/* Return nonzero if process p has an unmasked pending signal. */
end_comment

begin_define
define|#
directive|define
name|SIGPENDING
parameter_list|(
name|td
parameter_list|)
define|\
value|((!SIGISEMPTY((td)->td_siglist)&&				\ 	    !sigsetmasked(&(td)->td_siglist,&(td)->td_sigmask)) ||	\ 	 (!SIGISEMPTY((td)->td_proc->p_siglist)&&			\ 	    !sigsetmasked(&(td)->td_proc->p_siglist,&(td)->td_sigmask)))
end_define

begin_comment
comment|/*  * Return the value of the pseudo-expression ((*set& ~*mask) != 0).  This  * is an optimized version of SIGISEMPTY() on a temporary variable  * containing SIGSETNAND(*set, *mask).  */
end_comment

begin_function
specifier|static
name|__inline
name|int
name|sigsetmasked
parameter_list|(
name|sigset_t
modifier|*
name|set
parameter_list|,
name|sigset_t
modifier|*
name|mask
parameter_list|)
block|{
name|int
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|_SIG_WORDS
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|set
operator|->
name|__bits
index|[
name|i
index|]
operator|&
operator|~
name|mask
operator|->
name|__bits
index|[
name|i
index|]
condition|)
return|return
operator|(
literal|0
operator|)
return|;
block|}
return|return
operator|(
literal|1
operator|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|ksiginfo_init
parameter_list|(
name|ksi
parameter_list|)
define|\
value|do {						\ 	bzero(ksi, sizeof(ksiginfo_t));		\ } while(0)
end_define

begin_define
define|#
directive|define
name|ksiginfo_init_trap
parameter_list|(
name|ksi
parameter_list|)
define|\
value|do {						\ 	ksiginfo_t *kp = ksi;			\ 	bzero(kp, sizeof(ksiginfo_t));		\ 	kp->ksi_flags |= KSI_TRAP;		\ } while(0)
end_define

begin_function
specifier|static
name|__inline
name|void
name|ksiginfo_copy
parameter_list|(
name|ksiginfo_t
modifier|*
name|src
parameter_list|,
name|ksiginfo_t
modifier|*
name|dst
parameter_list|)
block|{
operator|(
name|dst
operator|)
operator|->
name|ksi_info
operator|=
name|src
operator|->
name|ksi_info
expr_stmt|;
operator|(
name|dst
operator|)
operator|->
name|ksi_flags
operator|=
operator|(
name|src
operator|->
name|ksi_flags
operator|&
name|KSI_COPYMASK
operator|)
expr_stmt|;
block|}
end_function

begin_struct_decl
struct_decl|struct
name|pgrp
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|thread
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|proc
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|sigio
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|mtx
struct_decl|;
end_struct_decl

begin_decl_stmt
specifier|extern
name|int
name|sugid_coredump
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Sysctl variable kern.sugid_coredump */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|mtx
name|sigio_lock
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|kern_logsigexit
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Sysctl variable kern.logsigexit */
end_comment

begin_comment
comment|/*  * Lock the pointers for a sigio object in the underlying objects of  * a file descriptor.  */
end_comment

begin_define
define|#
directive|define
name|SIGIO_LOCK
parameter_list|()
value|mtx_lock(&sigio_lock)
end_define

begin_define
define|#
directive|define
name|SIGIO_TRYLOCK
parameter_list|()
value|mtx_trylock(&sigio_lock)
end_define

begin_define
define|#
directive|define
name|SIGIO_UNLOCK
parameter_list|()
value|mtx_unlock(&sigio_lock)
end_define

begin_define
define|#
directive|define
name|SIGIO_LOCKED
parameter_list|()
value|mtx_owned(&sigio_lock)
end_define

begin_define
define|#
directive|define
name|SIGIO_ASSERT
parameter_list|(
name|type
parameter_list|)
value|mtx_assert(&sigio_lock, type)
end_define

begin_comment
comment|/* stop_allowed parameter for cursig */
end_comment

begin_define
define|#
directive|define
name|SIG_STOP_ALLOWED
value|100
end_define

begin_define
define|#
directive|define
name|SIG_STOP_NOT_ALLOWED
value|101
end_define

begin_comment
comment|/* flags for kern_sigprocmask */
end_comment

begin_define
define|#
directive|define
name|SIGPROCMASK_OLD
value|0x0001
end_define

begin_define
define|#
directive|define
name|SIGPROCMASK_PROC_LOCKED
value|0x0002
end_define

begin_comment
comment|/*  * Machine-independent functions:  */
end_comment

begin_function_decl
name|int
name|cursig
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|int
name|stop_allowed
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|execsigs
parameter_list|(
name|struct
name|proc
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|gsignal
parameter_list|(
name|int
name|pgid
parameter_list|,
name|int
name|sig
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|killproc
parameter_list|(
name|struct
name|proc
modifier|*
name|p
parameter_list|,
name|char
modifier|*
name|why
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pgsigio
parameter_list|(
name|struct
name|sigio
modifier|*
modifier|*
parameter_list|,
name|int
name|signum
parameter_list|,
name|int
name|checkctty
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pgsignal
parameter_list|(
name|struct
name|pgrp
modifier|*
name|pgrp
parameter_list|,
name|int
name|sig
parameter_list|,
name|int
name|checkctty
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|postsig
parameter_list|(
name|int
name|sig
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|psignal
parameter_list|(
name|struct
name|proc
modifier|*
name|p
parameter_list|,
name|int
name|sig
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|psignal_event
parameter_list|(
name|struct
name|proc
modifier|*
name|p
parameter_list|,
name|struct
name|sigevent
modifier|*
parameter_list|,
name|ksiginfo_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|sigacts
modifier|*
name|sigacts_alloc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sigacts_copy
parameter_list|(
name|struct
name|sigacts
modifier|*
name|dest
parameter_list|,
name|struct
name|sigacts
modifier|*
name|src
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sigacts_free
parameter_list|(
name|struct
name|sigacts
modifier|*
name|ps
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|sigacts
modifier|*
name|sigacts_hold
parameter_list|(
name|struct
name|sigacts
modifier|*
name|ps
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sigacts_shared
parameter_list|(
name|struct
name|sigacts
modifier|*
name|ps
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|sigexit
argument_list|(
expr|struct
name|thread
operator|*
name|td
argument_list|,
name|int
name|signum
argument_list|)
name|__dead2
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|sig_ffs
parameter_list|(
name|sigset_t
modifier|*
name|set
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|siginit
parameter_list|(
name|struct
name|proc
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|signotify
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tdsigcleanup
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tdsignal
parameter_list|(
name|struct
name|proc
modifier|*
name|p
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|int
name|sig
parameter_list|,
name|ksiginfo_t
modifier|*
name|ksi
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|trapsignal
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|ksiginfo_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ptracestop
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|int
name|sig
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ksiginfo_t
modifier|*
name|ksiginfo_alloc
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ksiginfo_free
parameter_list|(
name|ksiginfo_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sigqueue_init
parameter_list|(
name|struct
name|sigqueue
modifier|*
name|queue
parameter_list|,
name|struct
name|proc
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sigqueue_flush
parameter_list|(
name|struct
name|sigqueue
modifier|*
name|queue
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sigqueue_delete_proc
parameter_list|(
name|struct
name|proc
modifier|*
name|p
parameter_list|,
name|int
name|sig
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sigqueue_delete_set
parameter_list|(
name|struct
name|sigqueue
modifier|*
name|queue
parameter_list|,
name|sigset_t
modifier|*
name|set
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sigqueue_delete
parameter_list|(
name|struct
name|sigqueue
modifier|*
name|queue
parameter_list|,
name|int
name|sig
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sigqueue_move_set
parameter_list|(
name|struct
name|sigqueue
modifier|*
name|src
parameter_list|,
name|sigqueue_t
modifier|*
name|dst
parameter_list|,
name|sigset_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sigqueue_get
parameter_list|(
name|struct
name|sigqueue
modifier|*
name|queue
parameter_list|,
name|int
name|sig
parameter_list|,
name|ksiginfo_t
modifier|*
name|info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sigqueue_add
parameter_list|(
name|struct
name|sigqueue
modifier|*
name|queue
parameter_list|,
name|int
name|sig
parameter_list|,
name|ksiginfo_t
modifier|*
name|info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sigqueue_collect_set
parameter_list|(
name|struct
name|sigqueue
modifier|*
name|queue
parameter_list|,
name|sigset_t
modifier|*
name|set
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sigqueue_move
parameter_list|(
name|struct
name|sigqueue
modifier|*
parameter_list|,
name|struct
name|sigqueue
modifier|*
parameter_list|,
name|int
name|sig
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sigqueue_delete_set_proc
parameter_list|(
name|struct
name|proc
modifier|*
parameter_list|,
name|sigset_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sigqueue_delete_stopmask_proc
parameter_list|(
name|struct
name|proc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sigqueue_take
parameter_list|(
name|ksiginfo_t
modifier|*
name|ksi
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|kern_sigtimedwait
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|sigset_t
parameter_list|,
name|ksiginfo_t
modifier|*
parameter_list|,
name|struct
name|timespec
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|kern_sigprocmask
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|int
name|how
parameter_list|,
name|sigset_t
modifier|*
name|set
parameter_list|,
name|sigset_t
modifier|*
name|oset
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Machine-dependent functions:  */
end_comment

begin_function_decl
name|void
name|sendsig
parameter_list|(
name|sig_t
parameter_list|,
name|ksiginfo_t
modifier|*
parameter_list|,
name|sigset_t
modifier|*
name|retmask
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_SIGNALVAR_H_ */
end_comment

end_unit

