begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*****************************************************************************  * Copyright 1990, 1992 Free Software Foundation, Inc.  *  * This code was donated by Intel Corp.  *  * Intel hereby grants you permission to copy, modify, and   * distribute this software and its documentation.  Intel grants  * this permission provided that the above copyright notice   * appears in all copies and that both the copyright notice and  * this permission notice appear in supporting documentation.  In  * addition, Intel grants this permission provided that you  * prominently mark as not part of the original any modifications  * made to this software or documentation, and that the name of   * Intel Corporation not be used in advertising or publicity   * pertaining to distribution of the software or the documentation   * without specific, written prior permission.    *  * Intel Corporation does not warrant, guarantee or make any   * representations regarding the use of, or the results of the use  * of, the software and documentation in terms of correctness,   * accuracy, reliability, currentness, or otherwise; and you rely  * on the software, documentation and results solely at your own risk.  *****************************************************************************/
end_comment

begin_decl_stmt
specifier|static
name|char
name|rcsid
index|[]
init|=
literal|"$Id"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/******************************************************************************  * send_break:  *  *	This function sends a a "break" to the specified tty.  This is useful  *	if the tty is attached to an i960 board equipped with a break-detector  *	circuit that causes a hard reset of the board.  ******************************************************************************/
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"ttycntl.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|USG
end_ifdef

begin_macro
name|send_break
argument_list|(
argument|fd
argument_list|)
end_macro

begin_decl_stmt
name|int
name|fd
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* File descriptor of i960 tty */
end_comment

begin_block
block|{
name|TTY_FLUSH
argument_list|(
name|fd
argument_list|)
expr_stmt|;
name|ioctl
argument_list|(
name|fd
argument_list|,
name|TCSBRK
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_block

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* BSD Unix */
end_comment

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_function
specifier|static
name|void
name|alarm_handler
parameter_list|()
block|{
return|return;
block|}
end_function

begin_macro
name|send_break
argument_list|(
argument|fd
argument_list|)
end_macro

begin_decl_stmt
name|int
name|fd
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* File descriptor of i960 tty */
end_comment

begin_block
block|{
name|struct
name|itimerval
name|t
decl_stmt|;
name|void
function_decl|(
modifier|*
name|old_alarm
function_decl|)
parameter_list|()
function_decl|;
comment|/* Alarm signal handler on entry */
name|old_alarm
operator|=
name|signal
argument_list|(
name|SIGALRM
argument_list|,
name|alarm_handler
argument_list|)
expr_stmt|;
comment|/* Set timer for 1/4 second break */
name|t
operator|.
name|it_value
operator|.
name|tv_sec
operator|=
literal|0
expr_stmt|;
name|t
operator|.
name|it_value
operator|.
name|tv_usec
operator|=
literal|250000
expr_stmt|;
name|t
operator|.
name|it_interval
operator|.
name|tv_sec
operator|=
name|t
operator|.
name|it_interval
operator|.
name|tv_usec
operator|=
literal|0
expr_stmt|;
comment|/* Assert break for the duration of the timer */
name|ioctl
argument_list|(
name|fd
argument_list|,
name|TIOCSBRK
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|setitimer
argument_list|(
name|ITIMER_REAL
argument_list|,
operator|&
name|t
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|sigpause
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|ioctl
argument_list|(
name|fd
argument_list|,
name|TIOCCBRK
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|signal
argument_list|(
name|SIGALRM
argument_list|,
name|old_alarm
argument_list|)
expr_stmt|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

end_unit

