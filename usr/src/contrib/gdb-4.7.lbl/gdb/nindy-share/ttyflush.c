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
literal|"Id: ttyflush.c,v 1.1.1.1 1991/03/28 16:21:03 rich Exp $"
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_comment
comment|/* Needed on Sys V */
end_comment

begin_include
include|#
directive|include
file|"ttycntl.h"
end_include

begin_comment
comment|/******************************************************************************  * tty_flush:  *  *	This routine puts the specified tty into a quiescent state by flushing  *	all pending input and output.  *  *	The tty is assumed to be connected to an i960 board containing a  *	a NINDY ROM;  since the 960 may be generating output, we wait until  *	at least one second goes by without anything new arriving.  ******************************************************************************/
end_comment

begin_macro
name|tty_flush
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
comment|/* File descriptor of tty line */
end_comment

begin_block
block|{
name|int
name|n
decl_stmt|;
comment|/* Number of characters of pending input */
name|char
name|c
decl_stmt|;
comment|/* Next character of input (discarded) */
do|do
block|{
name|TTY_FLUSH
argument_list|(
name|fd
argument_list|)
expr_stmt|;
name|sleep
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|n
operator|=
literal|1
expr_stmt|;
name|TTY_NBREAD
argument_list|(
name|fd
argument_list|,
name|n
argument_list|,
operator|&
name|c
argument_list|)
expr_stmt|;
comment|/* Non-blocking read */
block|}
do|while
condition|(
name|n
operator|>
literal|0
condition|)
do|;
block|}
end_block

end_unit

