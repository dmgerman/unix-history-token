begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1981 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)tstp.c	5.7 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_include
include|#
directive|include
file|<curses.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<termios.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_comment
comment|/*  * tstp --  *	Handle stop and start signals.  */
end_comment

begin_function
name|void
name|tstp
parameter_list|(
name|signo
parameter_list|)
name|int
name|signo
decl_stmt|;
block|{
name|struct
name|termios
name|save
decl_stmt|;
name|sigset_t
name|set
decl_stmt|;
comment|/* Get the current terminal state. */
if|if
condition|(
name|tcgetattr
argument_list|(
name|STDIN_FILENO
argument_list|,
operator|&
name|save
argument_list|)
condition|)
return|return;
comment|/* Move the cursor to the end of the screen. */
name|mvcur
argument_list|(
literal|0
argument_list|,
name|COLS
operator|-
literal|1
argument_list|,
name|LINES
operator|-
literal|1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* End the window. */
name|endwin
argument_list|()
expr_stmt|;
comment|/* Stop ourselves. */
operator|(
name|void
operator|)
name|sigemptyset
argument_list|(
operator|&
name|set
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|sigaddset
argument_list|(
operator|&
name|set
argument_list|,
name|SIGTSTP
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|sigprocmask
argument_list|(
name|SIG_UNBLOCK
argument_list|,
operator|&
name|set
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|signal
argument_list|(
name|SIGTSTP
argument_list|,
name|SIG_DFL
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|kill
argument_list|(
literal|0
argument_list|,
name|SIGTSTP
argument_list|)
expr_stmt|;
comment|/* Time passes ... */
comment|/* Reset the signal handler. */
operator|(
name|void
operator|)
name|signal
argument_list|(
name|SIGTSTP
argument_list|,
name|tstp
argument_list|)
expr_stmt|;
comment|/* Reset the terminal state. */
operator|(
name|void
operator|)
name|tcsetattr
argument_list|(
name|STDIN_FILENO
argument_list|,
name|TCSADRAIN
argument_list|,
operator|&
name|save
argument_list|)
expr_stmt|;
comment|/* Restart the screen. */
name|wrefresh
argument_list|(
name|curscr
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

