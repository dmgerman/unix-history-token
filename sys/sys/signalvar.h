begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)signalvar.h	8.6 (Berkeley) 2/19/95  * $FreeBSD$  */
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
file|<sys/signal.h>
end_include

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
name|_SIG_MAXSIG
index|]
decl_stmt|;
comment|/* disposition of signals */
name|sigset_t
name|ps_catchmask
index|[
name|_SIG_MAXSIG
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
name|ps_siginfo
decl_stmt|;
comment|/* signals that want SA_SIGINFO args */
name|sigset_t
name|ps_osigset
decl_stmt|;
comment|/* signals that use osigset_t */
name|sigset_t
name|ps_usertramp
decl_stmt|;
comment|/* SunOS compat; libc sigtramp XXX */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

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
comment|/* _KERNEL */
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
value|(set).__bits[_SIG_WORD(signo)] |= _SIG_BIT(signo)
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
value|(set).__bits[_SIG_WORD(signo)]&= ~_SIG_BIT(signo)
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
value|__sigisempty(&(set))
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
value|__sigseteq(&(set1),&(set2))
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
value|osig = (sig).__bits[0]
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
name|p
parameter_list|)
define|\
value|(!SIGISEMPTY((p)->p_siglist)&&					\ 	    (!sigsetmasked(&(p)->p_siglist,&(p)->p_sigmask) ||		\ 	    (p)->p_flag& P_TRACED))
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

begin_decl_stmt
specifier|extern
name|int
name|sugid_coredump
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Sysctl variable kern.sugid_coredump */
end_comment

begin_comment
comment|/*  * Machine-independent functions:  */
end_comment

begin_function_decl
name|int
name|CURSIG
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
name|int
name|issignal
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
name|proc
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|trapsignal
parameter_list|(
name|struct
name|proc
modifier|*
name|p
parameter_list|,
name|int
name|sig
parameter_list|,
name|u_long
name|code
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
name|action
parameter_list|,
name|int
name|sig
parameter_list|,
name|sigset_t
modifier|*
name|retmask
parameter_list|,
name|u_long
name|code
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

