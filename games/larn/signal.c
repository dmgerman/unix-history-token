begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|"header.h"
end_include

begin_comment
comment|/* "Larn is copyrighted 1986 by Noah Morgan.\n" */
end_comment

begin_define
define|#
directive|define
name|BIT
parameter_list|(
name|a
parameter_list|)
value|(1<<((a)-1))
end_define

begin_decl_stmt
specifier|extern
name|char
name|savefilename
index|[]
decl_stmt|,
name|wizard
decl_stmt|,
name|predostuff
decl_stmt|,
name|nosignal
decl_stmt|;
end_decl_stmt

begin_expr_stmt
specifier|static
name|s2choose
argument_list|()
comment|/* text to be displayed if ^C during intro screen */
block|{
name|cursor
argument_list|(
literal|1
argument_list|,
literal|24
argument_list|)
block|;
name|lprcat
argument_list|(
literal|"Press "
argument_list|)
block|;
name|setbold
argument_list|()
block|;
name|lprcat
argument_list|(
literal|"return"
argument_list|)
block|;
name|resetbold
argument_list|()
block|;
name|lprcat
argument_list|(
literal|" to continue: "
argument_list|)
block|;
name|lflush
argument_list|()
block|; 	}
specifier|static
name|void
name|cntlc
argument_list|()
comment|/* what to do for a ^C */
block|{
if|if
condition|(
name|nosignal
condition|)
return|return;
comment|/* don't do anything if inhibited */
name|signal
argument_list|(
name|SIGQUIT
argument_list|,
name|SIG_IGN
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|signal
argument_list|(
name|SIGINT
argument_list|,
name|SIG_IGN
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|quit
argument_list|()
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|predostuff
operator|==
literal|1
condition|)
name|s2choose
argument_list|()
expr_stmt|;
else|else
name|showplayer
argument_list|()
expr_stmt|;
end_if

begin_expr_stmt
name|lflush
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|signal
argument_list|(
name|SIGQUIT
argument_list|,
name|cntlc
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|signal
argument_list|(
name|SIGINT
argument_list|,
name|cntlc
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|/*  *	subroutine to save the game if a hangup signal  */
end_comment

begin_function
unit|static
name|void
name|sgam
parameter_list|()
block|{
name|savegame
argument_list|(
name|savefilename
argument_list|)
expr_stmt|;
name|wizard
operator|=
literal|1
expr_stmt|;
name|died
argument_list|(
operator|-
literal|257
argument_list|)
expr_stmt|;
comment|/* hangup signal */
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|SIGTSTP
end_ifdef

begin_function
specifier|static
name|void
name|tstop
parameter_list|()
comment|/* control Y	*/
block|{
if|if
condition|(
name|nosignal
condition|)
return|return;
comment|/* nothing if inhibited */
name|lcreat
argument_list|(
operator|(
name|char
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
name|clearvt100
argument_list|()
expr_stmt|;
name|lflush
argument_list|()
expr_stmt|;
name|signal
argument_list|(
name|SIGTSTP
argument_list|,
name|SIG_DFL
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|SIGVTALRM
comment|/* looks like BSD4.2 or higher - must clr mask for signal to take effect*/
name|sigsetmask
argument_list|(
name|sigblock
argument_list|(
literal|0
argument_list|)
operator|&
operator|~
name|BIT
argument_list|(
name|SIGTSTP
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|kill
argument_list|(
name|getpid
argument_list|()
argument_list|,
name|SIGTSTP
argument_list|)
expr_stmt|;
name|setupvt100
argument_list|()
expr_stmt|;
name|signal
argument_list|(
name|SIGTSTP
argument_list|,
name|tstop
argument_list|)
expr_stmt|;
if|if
condition|(
name|predostuff
operator|==
literal|1
condition|)
name|s2choose
argument_list|()
expr_stmt|;
else|else
name|drawscreen
argument_list|()
expr_stmt|;
name|showplayer
argument_list|()
expr_stmt|;
name|lflush
argument_list|()
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
endif|SIGTSTP
end_endif

begin_comment
comment|/*  *	subroutine to issue the needed signal traps  called from main()  */
end_comment

begin_function_decl
specifier|static
name|void
name|sigpanic
parameter_list|()
function_decl|;
end_function_decl

begin_function
specifier|static
name|void
name|sigill
parameter_list|()
block|{
name|sigpanic
argument_list|(
name|SIGILL
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|sigtrap
parameter_list|()
block|{
name|sigpanic
argument_list|(
name|SIGTRAP
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|sigiot
parameter_list|()
block|{
name|sigpanic
argument_list|(
name|SIGIOT
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|sigemt
parameter_list|()
block|{
name|sigpanic
argument_list|(
name|SIGEMT
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|sigfpe
parameter_list|()
block|{
name|sigpanic
argument_list|(
name|SIGFPE
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|sigbus
parameter_list|()
block|{
name|sigpanic
argument_list|(
name|SIGBUS
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|sigsegv
parameter_list|()
block|{
name|sigpanic
argument_list|(
name|SIGSEGV
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|sigsys
parameter_list|()
block|{
name|sigpanic
argument_list|(
name|SIGSYS
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|sigpipe
parameter_list|()
block|{
name|sigpanic
argument_list|(
name|SIGPIPE
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|sigterm
parameter_list|()
block|{
name|sigpanic
argument_list|(
name|SIGTERM
argument_list|)
expr_stmt|;
block|}
end_function

begin_macro
name|sigsetup
argument_list|()
end_macro

begin_block
block|{
name|signal
argument_list|(
name|SIGQUIT
argument_list|,
name|cntlc
argument_list|)
expr_stmt|;
name|signal
argument_list|(
name|SIGINT
argument_list|,
name|cntlc
argument_list|)
expr_stmt|;
name|signal
argument_list|(
name|SIGKILL
argument_list|,
name|SIG_IGN
argument_list|)
expr_stmt|;
name|signal
argument_list|(
name|SIGHUP
argument_list|,
name|sgam
argument_list|)
expr_stmt|;
name|signal
argument_list|(
name|SIGILL
argument_list|,
name|sigill
argument_list|)
expr_stmt|;
name|signal
argument_list|(
name|SIGTRAP
argument_list|,
name|sigtrap
argument_list|)
expr_stmt|;
name|signal
argument_list|(
name|SIGIOT
argument_list|,
name|sigiot
argument_list|)
expr_stmt|;
name|signal
argument_list|(
name|SIGEMT
argument_list|,
name|sigemt
argument_list|)
expr_stmt|;
name|signal
argument_list|(
name|SIGFPE
argument_list|,
name|sigfpe
argument_list|)
expr_stmt|;
name|signal
argument_list|(
name|SIGBUS
argument_list|,
name|sigbus
argument_list|)
expr_stmt|;
name|signal
argument_list|(
name|SIGSEGV
argument_list|,
name|sigsegv
argument_list|)
expr_stmt|;
name|signal
argument_list|(
name|SIGSYS
argument_list|,
name|sigsys
argument_list|)
expr_stmt|;
name|signal
argument_list|(
name|SIGPIPE
argument_list|,
name|sigpipe
argument_list|)
expr_stmt|;
name|signal
argument_list|(
name|SIGTERM
argument_list|,
name|sigterm
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|SIGTSTP
name|signal
argument_list|(
name|SIGTSTP
argument_list|,
name|tstop
argument_list|)
expr_stmt|;
name|signal
argument_list|(
name|SIGSTOP
argument_list|,
name|tstop
argument_list|)
expr_stmt|;
endif|#
directive|endif
endif|SIGTSTP
block|}
end_block

begin_ifdef
ifdef|#
directive|ifdef
name|BSD
end_ifdef

begin_comment
comment|/* for BSD UNIX? */
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|signame
index|[
name|NSIG
index|]
init|=
block|{
literal|""
block|,
literal|"SIGHUP"
block|,
comment|/*	1	 hangup */
literal|"SIGINT"
block|,
comment|/*	2	 interrupt */
literal|"SIGQUIT"
block|,
comment|/*	3	 quit */
literal|"SIGILL"
block|,
comment|/*	4	 illegal instruction (not reset when caught) */
literal|"SIGTRAP"
block|,
comment|/*	5	 trace trap (not reset when caught) */
literal|"SIGIOT"
block|,
comment|/*	6	 IOT instruction */
literal|"SIGEMT"
block|,
comment|/*	7	 EMT instruction */
literal|"SIGFPE"
block|,
comment|/*	8	 floating point exception */
literal|"SIGKILL"
block|,
comment|/*	9	 kill (cannot be caught or ignored) */
literal|"SIGBUS"
block|,
comment|/*	10	 bus error */
literal|"SIGSEGV"
block|,
comment|/*	11	 segmentation violation */
literal|"SIGSYS"
block|,
comment|/*	12	 bad argument to system call */
literal|"SIGPIPE"
block|,
comment|/*	13	 write on a pipe with no one to read it */
literal|"SIGALRM"
block|,
comment|/*	14	 alarm clock */
literal|"SIGTERM"
block|,
comment|/*	15	 software termination signal from kill */
literal|"SIGURG"
block|,
comment|/*	16	 urgent condition on IO channel */
literal|"SIGSTOP"
block|,
comment|/*	17	 sendable stop signal not from tty */
literal|"SIGTSTP"
block|,
comment|/*	18	 stop signal from tty */
literal|"SIGCONT"
block|,
comment|/*	19	 continue a stopped process */
literal|"SIGCHLD"
block|,
comment|/*	20	 to parent on child stop or exit */
literal|"SIGTTIN"
block|,
comment|/*	21	 to readers pgrp upon background tty read */
literal|"SIGTTOU"
block|,
comment|/*	22	 like TTIN for output if (tp->t_local&LTOSTOP) */
literal|"SIGIO"
block|,
comment|/*	23	 input/output possible signal */
literal|"SIGXCPU"
block|,
comment|/*	24	 exceeded CPU time limit */
literal|"SIGXFSZ"
block|,
comment|/*	25	 exceeded file size limit */
literal|"SIGVTALRM"
block|,
comment|/*  26	 virtual time alarm */
literal|"SIGPROF"
block|,
comment|/*	27	 profiling time alarm */
literal|""
block|,
literal|""
block|,
literal|""
block|,
literal|""
block|}
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
else|BSD
end_else

begin_comment
comment|/* for system V? */
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|signame
index|[
name|NSIG
index|]
init|=
block|{
literal|""
block|,
literal|"SIGHUP"
block|,
comment|/*	1	 hangup */
literal|"SIGINT"
block|,
comment|/*	2	 interrupt */
literal|"SIGQUIT"
block|,
comment|/*	3	 quit */
literal|"SIGILL"
block|,
comment|/*	4	 illegal instruction (not reset when caught) */
literal|"SIGTRAP"
block|,
comment|/*	5	 trace trap (not reset when caught) */
literal|"SIGIOT"
block|,
comment|/*	6	 IOT instruction */
literal|"SIGEMT"
block|,
comment|/*	7	 EMT instruction */
literal|"SIGFPE"
block|,
comment|/*	8	 floating point exception */
literal|"SIGKILL"
block|,
comment|/*	9	 kill (cannot be caught or ignored) */
literal|"SIGBUS"
block|,
comment|/*	10	 bus error */
literal|"SIGSEGV"
block|,
comment|/*	11	 segmentation violation */
literal|"SIGSYS"
block|,
comment|/*	12	 bad argument to system call */
literal|"SIGPIPE"
block|,
comment|/*	13	 write on a pipe with no one to read it */
literal|"SIGALRM"
block|,
comment|/*	14	 alarm clock */
literal|"SIGTERM"
block|,
comment|/*	15	 software termination signal from kill */
literal|"SIGUSR1"
block|,
comment|/*	16	 user defines signal 1 */
literal|"SIGUSR2"
block|,
comment|/*	17	 user defines signal 2 */
literal|"SIGCLD"
block|,
comment|/*	18	 child death */
literal|"SIGPWR"
block|,
comment|/*	19	 power fail */
literal|""
block|,
literal|""
block|,
literal|""
block|,
literal|""
block|,
literal|""
block|,
literal|""
block|,
literal|""
block|,
literal|""
block|,
literal|""
block|,
literal|""
block|,
literal|""
block|,
literal|""
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|BSD
end_endif

begin_comment
comment|/*  *	routine to process a fatal error signal  */
end_comment

begin_function
specifier|static
name|void
name|sigpanic
parameter_list|(
name|sig
parameter_list|)
name|int
name|sig
decl_stmt|;
block|{
name|char
name|buf
index|[
literal|128
index|]
decl_stmt|;
name|signal
argument_list|(
name|sig
argument_list|,
name|SIG_DFL
argument_list|)
expr_stmt|;
name|sprintf
argument_list|(
name|buf
argument_list|,
literal|"\nLarn - Panic! Signal %d received [%s]"
argument_list|,
name|sig
argument_list|,
name|signame
index|[
name|sig
index|]
argument_list|)
expr_stmt|;
name|write
argument_list|(
literal|2
argument_list|,
name|buf
argument_list|,
name|strlen
argument_list|(
name|buf
argument_list|)
argument_list|)
expr_stmt|;
name|sleep
argument_list|(
literal|2
argument_list|)
expr_stmt|;
name|sncbr
argument_list|()
expr_stmt|;
name|savegame
argument_list|(
name|savefilename
argument_list|)
expr_stmt|;
name|kill
argument_list|(
name|getpid
argument_list|()
argument_list|,
name|sig
argument_list|)
expr_stmt|;
comment|/* this will terminate us */
block|}
end_function

end_unit

