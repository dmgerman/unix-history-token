begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015 Dmitry Chagin  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/signalvar.h>
end_include

begin_include
include|#
directive|include
file|<compat/linux/linux.h>
end_include

begin_decl_stmt
specifier|static
name|int
name|bsd_to_linux_sigtbl
index|[
name|LINUX_SIGTBLSZ
index|]
init|=
block|{
name|LINUX_SIGHUP
block|,
comment|/* SIGHUP */
name|LINUX_SIGINT
block|,
comment|/* SIGINT */
name|LINUX_SIGQUIT
block|,
comment|/* SIGQUIT */
name|LINUX_SIGILL
block|,
comment|/* SIGILL */
name|LINUX_SIGTRAP
block|,
comment|/* SIGTRAP */
name|LINUX_SIGABRT
block|,
comment|/* SIGABRT */
literal|0
block|,
comment|/* SIGEMT */
name|LINUX_SIGFPE
block|,
comment|/* SIGFPE */
name|LINUX_SIGKILL
block|,
comment|/* SIGKILL */
name|LINUX_SIGBUS
block|,
comment|/* SIGBUS */
name|LINUX_SIGSEGV
block|,
comment|/* SIGSEGV */
name|LINUX_SIGSYS
block|,
comment|/* SIGSYS */
name|LINUX_SIGPIPE
block|,
comment|/* SIGPIPE */
name|LINUX_SIGALRM
block|,
comment|/* SIGALRM */
name|LINUX_SIGTERM
block|,
comment|/* SIGTERM */
name|LINUX_SIGURG
block|,
comment|/* SIGURG */
name|LINUX_SIGSTOP
block|,
comment|/* SIGSTOP */
name|LINUX_SIGTSTP
block|,
comment|/* SIGTSTP */
name|LINUX_SIGCONT
block|,
comment|/* SIGCONT */
name|LINUX_SIGCHLD
block|,
comment|/* SIGCHLD */
name|LINUX_SIGTTIN
block|,
comment|/* SIGTTIN */
name|LINUX_SIGTTOU
block|,
comment|/* SIGTTOU */
name|LINUX_SIGIO
block|,
comment|/* SIGIO */
name|LINUX_SIGXCPU
block|,
comment|/* SIGXCPU */
name|LINUX_SIGXFSZ
block|,
comment|/* SIGXFSZ */
name|LINUX_SIGVTALRM
block|,
comment|/* SIGVTALRM */
name|LINUX_SIGPROF
block|,
comment|/* SIGPROF */
name|LINUX_SIGWINCH
block|,
comment|/* SIGWINCH */
literal|0
block|,
comment|/* SIGINFO */
name|LINUX_SIGUSR1
block|,
comment|/* SIGUSR1 */
name|LINUX_SIGUSR2
comment|/* SIGUSR2 */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|linux_to_bsd_sigtbl
index|[
name|LINUX_SIGTBLSZ
index|]
init|=
block|{
name|SIGHUP
block|,
comment|/* LINUX_SIGHUP */
name|SIGINT
block|,
comment|/* LINUX_SIGINT */
name|SIGQUIT
block|,
comment|/* LINUX_SIGQUIT */
name|SIGILL
block|,
comment|/* LINUX_SIGILL */
name|SIGTRAP
block|,
comment|/* LINUX_SIGTRAP */
name|SIGABRT
block|,
comment|/* LINUX_SIGABRT */
name|SIGBUS
block|,
comment|/* LINUX_SIGBUS */
name|SIGFPE
block|,
comment|/* LINUX_SIGFPE */
name|SIGKILL
block|,
comment|/* LINUX_SIGKILL */
name|SIGUSR1
block|,
comment|/* LINUX_SIGUSR1 */
name|SIGSEGV
block|,
comment|/* LINUX_SIGSEGV */
name|SIGUSR2
block|,
comment|/* LINUX_SIGUSR2 */
name|SIGPIPE
block|,
comment|/* LINUX_SIGPIPE */
name|SIGALRM
block|,
comment|/* LINUX_SIGALRM */
name|SIGTERM
block|,
comment|/* LINUX_SIGTERM */
name|SIGBUS
block|,
comment|/* LINUX_SIGSTKFLT */
name|SIGCHLD
block|,
comment|/* LINUX_SIGCHLD */
name|SIGCONT
block|,
comment|/* LINUX_SIGCONT */
name|SIGSTOP
block|,
comment|/* LINUX_SIGSTOP */
name|SIGTSTP
block|,
comment|/* LINUX_SIGTSTP */
name|SIGTTIN
block|,
comment|/* LINUX_SIGTTIN */
name|SIGTTOU
block|,
comment|/* LINUX_SIGTTOU */
name|SIGURG
block|,
comment|/* LINUX_SIGURG */
name|SIGXCPU
block|,
comment|/* LINUX_SIGXCPU */
name|SIGXFSZ
block|,
comment|/* LINUX_SIGXFSZ */
name|SIGVTALRM
block|,
comment|/* LINUX_SIGVTALARM */
name|SIGPROF
block|,
comment|/* LINUX_SIGPROF */
name|SIGWINCH
block|,
comment|/* LINUX_SIGWINCH */
name|SIGIO
block|,
comment|/* LINUX_SIGIO */
comment|/* 	 * FreeBSD does not have SIGPWR signal, map Linux SIGPWR signal 	 * to the first unused FreeBSD signal number. Since Linux supports 	 * signals from 1 to 64 we are ok here as our SIGRTMIN = 65. 	 */
name|SIGRTMIN
block|,
comment|/* LINUX_SIGPWR */
name|SIGSYS
comment|/* LINUX_SIGSYS */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Map Linux RT signals to the FreeBSD RT signals.  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|linux_to_bsd_rt_signal
parameter_list|(
name|int
name|sig
parameter_list|)
block|{
return|return
operator|(
name|SIGRTMIN
operator|+
literal|1
operator|+
name|sig
operator|-
name|LINUX_SIGRTMIN
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|bsd_to_linux_rt_signal
parameter_list|(
name|int
name|sig
parameter_list|)
block|{
return|return
operator|(
name|sig
operator|-
name|SIGRTMIN
operator|-
literal|1
operator|+
name|LINUX_SIGRTMIN
operator|)
return|;
block|}
end_function

begin_function
name|int
name|linux_to_bsd_signal
parameter_list|(
name|int
name|sig
parameter_list|)
block|{
name|KASSERT
argument_list|(
name|sig
operator|>
literal|0
operator|&&
name|sig
operator|<=
name|LINUX_SIGRTMAX
argument_list|,
operator|(
literal|"invalid Linux signal %d\n"
operator|,
name|sig
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|sig
operator|<
name|LINUX_SIGRTMIN
condition|)
return|return
operator|(
name|linux_to_bsd_sigtbl
index|[
name|_SIG_IDX
argument_list|(
name|sig
argument_list|)
index|]
operator|)
return|;
return|return
operator|(
name|linux_to_bsd_rt_signal
argument_list|(
name|sig
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
name|int
name|bsd_to_linux_signal
parameter_list|(
name|int
name|sig
parameter_list|)
block|{
if|if
condition|(
name|sig
operator|<=
name|LINUX_SIGTBLSZ
condition|)
return|return
operator|(
name|bsd_to_linux_sigtbl
index|[
name|_SIG_IDX
argument_list|(
name|sig
argument_list|)
index|]
operator|)
return|;
if|if
condition|(
name|sig
operator|==
name|SIGRTMIN
condition|)
return|return
operator|(
name|LINUX_SIGPWR
operator|)
return|;
return|return
operator|(
name|bsd_to_linux_rt_signal
argument_list|(
name|sig
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
name|int
name|linux_to_bsd_sigaltstack
parameter_list|(
name|int
name|lsa
parameter_list|)
block|{
name|int
name|bsa
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|lsa
operator|&
name|LINUX_SS_DISABLE
condition|)
name|bsa
operator||=
name|SS_DISABLE
expr_stmt|;
comment|/* 	 * Linux ignores SS_ONSTACK flag for ss 	 * parameter while FreeBSD prohibits it. 	 */
return|return
operator|(
name|bsa
operator|)
return|;
block|}
end_function

begin_function
name|int
name|bsd_to_linux_sigaltstack
parameter_list|(
name|int
name|bsa
parameter_list|)
block|{
name|int
name|lsa
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|bsa
operator|&
name|SS_DISABLE
condition|)
name|lsa
operator||=
name|LINUX_SS_DISABLE
expr_stmt|;
if|if
condition|(
name|bsa
operator|&
name|SS_ONSTACK
condition|)
name|lsa
operator||=
name|LINUX_SS_ONSTACK
expr_stmt|;
return|return
operator|(
name|lsa
operator|)
return|;
block|}
end_function

begin_function
name|void
name|linux_to_bsd_sigset
parameter_list|(
name|l_sigset_t
modifier|*
name|lss
parameter_list|,
name|sigset_t
modifier|*
name|bss
parameter_list|)
block|{
name|int
name|b
decl_stmt|,
name|l
decl_stmt|;
name|SIGEMPTYSET
argument_list|(
operator|*
name|bss
argument_list|)
expr_stmt|;
for|for
control|(
name|l
operator|=
literal|1
init|;
name|l
operator|<=
name|LINUX_SIGRTMAX
condition|;
name|l
operator|++
control|)
block|{
if|if
condition|(
name|LINUX_SIGISMEMBER
argument_list|(
operator|*
name|lss
argument_list|,
name|l
argument_list|)
condition|)
block|{
name|b
operator|=
name|linux_to_bsd_signal
argument_list|(
name|l
argument_list|)
expr_stmt|;
if|if
condition|(
name|b
condition|)
name|SIGADDSET
argument_list|(
operator|*
name|bss
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function

begin_function
name|void
name|bsd_to_linux_sigset
parameter_list|(
name|sigset_t
modifier|*
name|bss
parameter_list|,
name|l_sigset_t
modifier|*
name|lss
parameter_list|)
block|{
name|int
name|b
decl_stmt|,
name|l
decl_stmt|;
name|LINUX_SIGEMPTYSET
argument_list|(
operator|*
name|lss
argument_list|)
expr_stmt|;
for|for
control|(
name|b
operator|=
literal|1
init|;
name|b
operator|<=
name|SIGRTMAX
condition|;
name|b
operator|++
control|)
block|{
if|if
condition|(
name|SIGISMEMBER
argument_list|(
operator|*
name|bss
argument_list|,
name|b
argument_list|)
condition|)
block|{
name|l
operator|=
name|bsd_to_linux_signal
argument_list|(
name|b
argument_list|)
expr_stmt|;
if|if
condition|(
name|l
condition|)
name|LINUX_SIGADDSET
argument_list|(
operator|*
name|lss
argument_list|,
name|l
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function

end_unit

