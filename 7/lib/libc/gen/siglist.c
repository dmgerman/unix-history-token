begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LIBC_SCCS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
end_if

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)siglist.c	8.1 (Berkeley) 6/4/93"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LIBC_SCCS and not lint */
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
file|<signal.h>
end_include

begin_decl_stmt
specifier|const
name|char
modifier|*
specifier|const
name|sys_signame
index|[
name|NSIG
index|]
init|=
block|{
literal|"Signal 0"
block|,
literal|"hup"
block|,
comment|/* SIGHUP */
literal|"int"
block|,
comment|/* SIGINT */
literal|"quit"
block|,
comment|/* SIGQUIT */
literal|"ill"
block|,
comment|/* SIGILL */
literal|"trap"
block|,
comment|/* SIGTRAP */
literal|"abrt"
block|,
comment|/* SIGABRT */
literal|"emt"
block|,
comment|/* SIGEMT */
literal|"fpe"
block|,
comment|/* SIGFPE */
literal|"kill"
block|,
comment|/* SIGKILL */
literal|"bus"
block|,
comment|/* SIGBUS */
literal|"segv"
block|,
comment|/* SIGSEGV */
literal|"sys"
block|,
comment|/* SIGSYS */
literal|"pipe"
block|,
comment|/* SIGPIPE */
literal|"alrm"
block|,
comment|/* SIGALRM */
literal|"term"
block|,
comment|/* SIGTERM */
literal|"urg"
block|,
comment|/* SIGURG */
literal|"stop"
block|,
comment|/* SIGSTOP */
literal|"tstp"
block|,
comment|/* SIGTSTP */
literal|"cont"
block|,
comment|/* SIGCONT */
literal|"chld"
block|,
comment|/* SIGCHLD */
literal|"ttin"
block|,
comment|/* SIGTTIN */
literal|"ttou"
block|,
comment|/* SIGTTOU */
literal|"io"
block|,
comment|/* SIGIO */
literal|"xcpu"
block|,
comment|/* SIGXCPU */
literal|"xfsz"
block|,
comment|/* SIGXFSZ */
literal|"vtalrm"
block|,
comment|/* SIGVTALRM */
literal|"prof"
block|,
comment|/* SIGPROF */
literal|"winch"
block|,
comment|/* SIGWINCH */
literal|"info"
block|,
comment|/* SIGINFO */
literal|"usr1"
block|,
comment|/* SIGUSR1 */
literal|"usr2"
comment|/* SIGUSR2 */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
specifier|const
name|sys_siglist
index|[
name|NSIG
index|]
init|=
block|{
literal|"Signal 0"
block|,
literal|"Hangup"
block|,
comment|/* SIGHUP */
literal|"Interrupt"
block|,
comment|/* SIGINT */
literal|"Quit"
block|,
comment|/* SIGQUIT */
literal|"Illegal instruction"
block|,
comment|/* SIGILL */
literal|"Trace/BPT trap"
block|,
comment|/* SIGTRAP */
literal|"Abort trap"
block|,
comment|/* SIGABRT */
literal|"EMT trap"
block|,
comment|/* SIGEMT */
literal|"Floating point exception"
block|,
comment|/* SIGFPE */
literal|"Killed"
block|,
comment|/* SIGKILL */
literal|"Bus error"
block|,
comment|/* SIGBUS */
literal|"Segmentation fault"
block|,
comment|/* SIGSEGV */
literal|"Bad system call"
block|,
comment|/* SIGSYS */
literal|"Broken pipe"
block|,
comment|/* SIGPIPE */
literal|"Alarm clock"
block|,
comment|/* SIGALRM */
literal|"Terminated"
block|,
comment|/* SIGTERM */
literal|"Urgent I/O condition"
block|,
comment|/* SIGURG */
literal|"Suspended (signal)"
block|,
comment|/* SIGSTOP */
literal|"Suspended"
block|,
comment|/* SIGTSTP */
literal|"Continued"
block|,
comment|/* SIGCONT */
literal|"Child exited"
block|,
comment|/* SIGCHLD */
literal|"Stopped (tty input)"
block|,
comment|/* SIGTTIN */
literal|"Stopped (tty output)"
block|,
comment|/* SIGTTOU */
literal|"I/O possible"
block|,
comment|/* SIGIO */
literal|"Cputime limit exceeded"
block|,
comment|/* SIGXCPU */
literal|"Filesize limit exceeded"
block|,
comment|/* SIGXFSZ */
literal|"Virtual timer expired"
block|,
comment|/* SIGVTALRM */
literal|"Profiling timer expired"
block|,
comment|/* SIGPROF */
literal|"Window size changes"
block|,
comment|/* SIGWINCH */
literal|"Information request"
block|,
comment|/* SIGINFO */
literal|"User defined signal 1"
block|,
comment|/* SIGUSR1 */
literal|"User defined signal 2"
comment|/* SIGUSR2 */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|sys_nsig
init|=
sizeof|sizeof
argument_list|(
name|sys_siglist
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|sys_siglist
index|[
literal|0
index|]
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

