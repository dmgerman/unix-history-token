begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	@(#)siglist.c	4.2 (Berkeley) %G%	*/
end_comment

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_decl_stmt
name|char
modifier|*
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
literal|"IOT trap"
block|,
comment|/* SIGIOT */
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
literal|"Stopped (signal)"
block|,
comment|/* SIGSTOP */
literal|"Stopped"
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
literal|"Signal 28"
block|,
literal|"Signal 29"
block|,
literal|"Signal 30"
block|,
literal|"Signal 31"
block|}
decl_stmt|;
end_decl_stmt

end_unit

