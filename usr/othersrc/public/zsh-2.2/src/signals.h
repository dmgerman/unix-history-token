begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* this file is created automatically by buildzsh */
end_comment

begin_comment
comment|/* if all this is wrong, blame csh ;-) */
end_comment

begin_define
define|#
directive|define
name|SIGCOUNT
value|31
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|GLOBALS
end_ifdef

begin_decl_stmt
name|char
modifier|*
name|sigmsg
index|[
name|SIGCOUNT
operator|+
literal|2
index|]
init|=
block|{
literal|"done"
block|,
literal|"hangup"
block|,
literal|"interrupt"
block|,
literal|"quit"
block|,
literal|"illegal instruction"
block|,
literal|"trace trap"
block|,
literal|"abort"
block|,
literal|"EMT instruction"
block|,
literal|"floating point exception"
block|,
literal|"killed"
block|,
literal|"bus error"
block|,
literal|"segmentation fault"
block|,
literal|"bad system call"
block|,
literal|"broken pipe"
block|,
literal|"SIGALRM"
block|,
literal|"terminated"
block|,
literal|"SIGURG"
block|,
ifdef|#
directive|ifdef
name|USE_SUSPENDED
literal|"suspended (signal)"
block|,
else|#
directive|else
literal|"stopped (signal)"
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|USE_SUSPENDED
literal|"suspended"
block|,
else|#
directive|else
literal|"stopped"
block|,
endif|#
directive|endif
literal|"continued"
block|,
literal|"SIGCHLD"
block|,
ifdef|#
directive|ifdef
name|USE_SUSPENDED
literal|"suspended (tty input)"
block|,
else|#
directive|else
literal|"stopped (tty input)"
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|USE_SUSPENDED
literal|"suspended (tty output)"
block|,
else|#
directive|else
literal|"stopped (tty output)"
block|,
endif|#
directive|endif
literal|"SIGIO"
block|,
literal|"cpu limit exceeded"
block|,
literal|"filesize limit exceeded"
block|,
literal|"virtual time alarm"
block|,
literal|"SIGPROF"
block|,
literal|"SIGWINCH"
block|,
literal|"SIGINFO"
block|,
literal|"SIGUSR1"
block|,
literal|"SIGUSR2"
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|sigs
index|[
name|SIGCOUNT
operator|+
literal|4
index|]
init|=
block|{
literal|"EXIT"
block|,
literal|"HUP"
block|,
literal|"INT"
block|,
literal|"QUIT"
block|,
literal|"ILL"
block|,
literal|"TRAP"
block|,
literal|"ABRT"
block|,
literal|"EMT"
block|,
literal|"FPE"
block|,
literal|"KILL"
block|,
literal|"BUS"
block|,
literal|"SEGV"
block|,
literal|"SYS"
block|,
literal|"PIPE"
block|,
literal|"ALRM"
block|,
literal|"TERM"
block|,
literal|"URG"
block|,
literal|"STOP"
block|,
literal|"TSTP"
block|,
literal|"CONT"
block|,
literal|"CHLD"
block|,
literal|"TTIN"
block|,
literal|"TTOU"
block|,
literal|"IO"
block|,
literal|"XCPU"
block|,
literal|"XFSZ"
block|,
literal|"VTALRM"
block|,
literal|"PROF"
block|,
literal|"WINCH"
block|,
literal|"INFO"
block|,
literal|"USR1"
block|,
literal|"USR2"
block|,
literal|"ERR"
block|,
literal|"DEBUG"
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|sigs
index|[
name|SIGCOUNT
operator|+
literal|4
index|]
decl_stmt|,
modifier|*
name|sigmsg
index|[
name|SIGCOUNT
operator|+
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

