begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)signalvar.h	8.6 (Berkeley) 2/19/95  * $Id: signalvar.h,v 1.16 1997/08/30 11:24:05 peter Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_SIGNALVAR_H_
end_ifndef

begin_comment
comment|/* tmp for user.h */
end_comment

begin_define
define|#
directive|define
name|_SYS_SIGNALVAR_H_
end_define

begin_comment
comment|/*  * Kernel signal definitions and data structures,  * not exported to user programs.  */
end_comment

begin_comment
comment|/*  * Process signal actions and state, needed only within the process  * (not necessarily resident).  */
end_comment

begin_struct
struct|struct
name|sigacts
block|{
name|sig_t
name|ps_sigact
index|[
name|NSIG
index|]
decl_stmt|;
comment|/* disposition of signals */
name|sigset_t
name|ps_catchmask
index|[
name|NSIG
index|]
decl_stmt|;
comment|/* signals to be blocked */
name|sigset_t
name|ps_sigonstack
decl_stmt|;
comment|/* signals to take on sigstack */
name|sigset_t
name|ps_sigintr
decl_stmt|;
comment|/* signals that interrupt syscalls */
name|sigset_t
name|ps_sigreset
decl_stmt|;
comment|/* signals that reset when caught */
name|sigset_t
name|ps_signodefer
decl_stmt|;
comment|/* signals not masked while handled */
name|sigset_t
name|ps_oldmask
decl_stmt|;
comment|/* saved mask from before sigpause */
name|int
name|ps_flags
decl_stmt|;
comment|/* signal flags, below */
name|struct
name|sigaltstack
name|ps_sigstk
decl_stmt|;
comment|/* sp& on stack state variable */
name|int
name|ps_sig
decl_stmt|;
comment|/* for core dump/debugger XXX */
name|u_long
name|ps_code
decl_stmt|;
comment|/* for core dump/debugger XXX */
name|sigset_t
name|ps_usertramp
decl_stmt|;
comment|/* SunOS compat; libc sigtramp XXX */
block|}
struct|;
end_struct

begin_comment
comment|/* signal flags */
end_comment

begin_define
define|#
directive|define
name|SAS_OLDMASK
value|0x01
end_define

begin_comment
comment|/* need to restore mask before pause */
end_comment

begin_define
define|#
directive|define
name|SAS_ALTSTACK
value|0x02
end_define

begin_comment
comment|/* have alternate signal stack */
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
value|(p->p_sigacts->ps_sigact[(sig)])
end_define

begin_comment
comment|/*  * Determine signal that should be delivered to process p, the current  * process, 0 if none.  If there is a pending stop signal with default  * action, the process stops in issignal().  */
end_comment

begin_define
define|#
directive|define
name|CURSIG
parameter_list|(
name|p
parameter_list|)
define|\
value|(((p)->p_siglist == 0 ||					\ 	    (((p)->p_flag& P_TRACED) == 0&&				\ 	     ((p)->p_siglist& ~(p)->p_sigmask) == 0)) ?		\ 	    0 : issignal(p))
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
value|{ (p)->p_siglist&= ~sigmask(sig); }
end_define

begin_comment
comment|/*  * Signal properties and actions.  * The array below categorizes the signals and their default actions  * according to the following properties:  */
end_comment

begin_define
define|#
directive|define
name|SA_KILL
value|0x01
end_define

begin_comment
comment|/* terminates process by default */
end_comment

begin_define
define|#
directive|define
name|SA_CORE
value|0x02
end_define

begin_comment
comment|/* ditto and coredumps */
end_comment

begin_define
define|#
directive|define
name|SA_STOP
value|0x04
end_define

begin_comment
comment|/* suspend process */
end_comment

begin_define
define|#
directive|define
name|SA_TTYSTOP
value|0x08
end_define

begin_comment
comment|/* ditto, from tty */
end_comment

begin_define
define|#
directive|define
name|SA_IGNORE
value|0x10
end_define

begin_comment
comment|/* ignore by default */
end_comment

begin_define
define|#
directive|define
name|SA_CONT
value|0x20
end_define

begin_comment
comment|/* continue if suspended */
end_comment

begin_define
define|#
directive|define
name|SA_CANTMASK
value|0x40
end_define

begin_comment
comment|/* non-maskable, catchable */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SIGPROP
end_ifdef

begin_decl_stmt
specifier|static
name|int
name|sigprop
index|[
name|NSIG
operator|+
literal|1
index|]
init|=
block|{
literal|0
block|,
comment|/* unused */
name|SA_KILL
block|,
comment|/* SIGHUP */
name|SA_KILL
block|,
comment|/* SIGINT */
name|SA_KILL
operator||
name|SA_CORE
block|,
comment|/* SIGQUIT */
name|SA_KILL
operator||
name|SA_CORE
block|,
comment|/* SIGILL */
name|SA_KILL
operator||
name|SA_CORE
block|,
comment|/* SIGTRAP */
name|SA_KILL
operator||
name|SA_CORE
block|,
comment|/* SIGABRT */
name|SA_KILL
operator||
name|SA_CORE
block|,
comment|/* SIGEMT */
name|SA_KILL
operator||
name|SA_CORE
block|,
comment|/* SIGFPE */
name|SA_KILL
block|,
comment|/* SIGKILL */
name|SA_KILL
operator||
name|SA_CORE
block|,
comment|/* SIGBUS */
name|SA_KILL
operator||
name|SA_CORE
block|,
comment|/* SIGSEGV */
name|SA_KILL
operator||
name|SA_CORE
block|,
comment|/* SIGSYS */
name|SA_KILL
block|,
comment|/* SIGPIPE */
name|SA_KILL
block|,
comment|/* SIGALRM */
name|SA_KILL
block|,
comment|/* SIGTERM */
name|SA_IGNORE
block|,
comment|/* SIGURG */
name|SA_STOP
block|,
comment|/* SIGSTOP */
name|SA_STOP
operator||
name|SA_TTYSTOP
block|,
comment|/* SIGTSTP */
name|SA_IGNORE
operator||
name|SA_CONT
block|,
comment|/* SIGCONT */
name|SA_IGNORE
block|,
comment|/* SIGCHLD */
name|SA_STOP
operator||
name|SA_TTYSTOP
block|,
comment|/* SIGTTIN */
name|SA_STOP
operator||
name|SA_TTYSTOP
block|,
comment|/* SIGTTOU */
name|SA_IGNORE
block|,
comment|/* SIGIO */
name|SA_KILL
block|,
comment|/* SIGXCPU */
name|SA_KILL
block|,
comment|/* SIGXFSZ */
name|SA_KILL
block|,
comment|/* SIGVTALRM */
name|SA_KILL
block|,
comment|/* SIGPROF */
name|SA_IGNORE
block|,
comment|/* SIGWINCH  */
name|SA_IGNORE
block|,
comment|/* SIGINFO */
name|SA_KILL
block|,
comment|/* SIGUSR1 */
name|SA_KILL
block|,
comment|/* SIGUSR2 */
block|}
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|contsigmask
value|(sigmask(SIGCONT))
end_define

begin_define
define|#
directive|define
name|stopsigmask
value|(sigmask(SIGSTOP) | sigmask(SIGTSTP) | \ 			    sigmask(SIGTTIN) | sigmask(SIGTTOU))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SIGPROP */
end_comment

begin_define
define|#
directive|define
name|sigcantmask
value|(sigmask(SIGKILL) | sigmask(SIGSTOP))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_struct_decl
struct_decl|struct
name|pgrp
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * Machine-independent functions:  */
end_comment

begin_decl_stmt
name|void
name|execsigs
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|gsignal
name|__P
argument_list|(
operator|(
name|int
name|pgid
operator|,
name|int
name|sig
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|issignal
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|killproc
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
name|p
operator|,
name|char
operator|*
name|why
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|pgsignal
name|__P
argument_list|(
operator|(
expr|struct
name|pgrp
operator|*
name|pgrp
operator|,
name|int
name|sig
operator|,
name|int
name|checkctty
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|postsig
name|__P
argument_list|(
operator|(
name|int
name|sig
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
expr|struct
name|proc
operator|*
name|p
operator|,
name|int
name|sig
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|sigexit
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
name|p
operator|,
name|int
name|signum
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|siginit
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|trapsignal
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
name|p
operator|,
name|int
name|sig
operator|,
name|u_long
name|code
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Machine-dependent functions:  */
end_comment

begin_decl_stmt
name|void
name|sendsig
name|__P
argument_list|(
operator|(
name|sig_t
name|action
operator|,
name|int
name|sig
operator|,
name|int
name|returnmask
operator|,
name|u_long
name|code
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_SIGNALVAR_H_ */
end_comment

end_unit

