begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1981, 1993, 1994  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)tstp.c	8.3 (Berkeley) %G%"
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

begin_include
include|#
directive|include
file|"curses.h"
end_include

begin_comment
comment|/*  * stop_signal_handler --  *	Handle stop signals.  */
end_comment

begin_function
name|void
name|__stop_signal_handler
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
name|oset
decl_stmt|,
name|set
decl_stmt|;
comment|/* Get the current terminal state (which the user may have changed). */
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
comment|/* 	 * Block window change and timer signals.  The latter is because 	 * applications use timers to decide when to repaint the screen. 	 */
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
name|SIGALRM
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
name|SIGWINCH
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|sigprocmask
argument_list|(
name|SIG_BLOCK
argument_list|,
operator|&
name|set
argument_list|,
operator|&
name|oset
argument_list|)
expr_stmt|;
comment|/* 	 * End the window, which also resets the terminal state to the 	 * original modes. 	 */
name|endwin
argument_list|()
expr_stmt|;
comment|/* Unblock SIGTSTP. */
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
comment|/* Stop ourselves. */
name|__restore_stophandler
argument_list|()
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
comment|/* Reset the curses SIGTSTP signal handler. */
name|__set_stophandler
argument_list|()
expr_stmt|;
comment|/* save the new "default" terminal state */
operator|(
name|void
operator|)
name|tcgetattr
argument_list|(
name|STDIN_FILENO
argument_list|,
operator|&
name|__orig_termios
argument_list|)
expr_stmt|;
comment|/* Reset the terminal state to the mode just before we stopped. */
operator|(
name|void
operator|)
name|tcsetattr
argument_list|(
name|STDIN_FILENO
argument_list|,
name|__tcaction
condition|?
name|TCSASOFT
operator||
name|TCSADRAIN
else|:
name|TCSADRAIN
argument_list|,
operator|&
name|save
argument_list|)
expr_stmt|;
comment|/* Restart the screen. */
name|__startwin
argument_list|()
expr_stmt|;
comment|/* Repaint the screen. */
name|wrefresh
argument_list|(
name|curscr
argument_list|)
expr_stmt|;
comment|/* Reset the signals. */
operator|(
name|void
operator|)
name|sigprocmask
argument_list|(
name|SIG_SETMASK
argument_list|,
operator|&
name|oset
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
block|}
end_function

begin_function_decl
specifier|static
name|void
function_decl|(
modifier|*
name|otstpfn
function_decl|)
parameter_list|()
init|=
name|SIG_DFL
function_decl|;
end_function_decl

begin_comment
comment|/*  * Set the TSTP handler.  */
end_comment

begin_function
name|void
name|__set_stophandler
parameter_list|()
block|{
name|otstpfn
operator|=
name|signal
argument_list|(
name|SIGTSTP
argument_list|,
name|__stop_signal_handler
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Restore the TSTP handler.  */
end_comment

begin_function
name|void
name|__restore_stophandler
parameter_list|()
block|{
operator|(
name|void
operator|)
name|signal
argument_list|(
name|SIGTSTP
argument_list|,
name|otstpfn
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

