begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1993, 1994  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
literal|"@(#)sex_util.c	9.2 (Berkeley) 11/13/94"
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
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<bitstring.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
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
file|"compat.h"
end_include

begin_include
include|#
directive|include
file|<db.h>
end_include

begin_include
include|#
directive|include
file|<regex.h>
end_include

begin_include
include|#
directive|include
file|"vi.h"
end_include

begin_include
include|#
directive|include
file|"excmd.h"
end_include

begin_include
include|#
directive|include
file|"sex_screen.h"
end_include

begin_comment
comment|/*  * sex_bell --  *	Ring the bell.  */
end_comment

begin_function
name|void
name|sex_bell
parameter_list|(
name|sp
parameter_list|)
name|SCR
modifier|*
name|sp
decl_stmt|;
block|{
operator|(
name|void
operator|)
name|write
argument_list|(
name|STDOUT_FILENO
argument_list|,
literal|"\07"
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|/* \a */
block|}
end_function

begin_function
name|void
name|sex_busy
parameter_list|(
name|sp
parameter_list|,
name|msg
parameter_list|)
name|SCR
modifier|*
name|sp
decl_stmt|;
name|char
specifier|const
modifier|*
name|msg
decl_stmt|;
block|{
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|sp
operator|->
name|stdfp
argument_list|,
literal|"%s\n"
argument_list|,
name|msg
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|fflush
argument_list|(
name|sp
operator|->
name|stdfp
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * sex_optchange --  *	Screen specific "option changed" routine.  */
end_comment

begin_function
name|int
name|sex_optchange
parameter_list|(
name|sp
parameter_list|,
name|opt
parameter_list|)
name|SCR
modifier|*
name|sp
decl_stmt|;
name|int
name|opt
decl_stmt|;
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * sex_suspend --  *	Suspend an ex screen.  */
end_comment

begin_function
name|int
name|sex_suspend
parameter_list|(
name|sp
parameter_list|)
name|SCR
modifier|*
name|sp
decl_stmt|;
block|{
name|struct
name|termios
name|t
decl_stmt|;
name|GS
modifier|*
name|gp
decl_stmt|;
name|int
name|rval
decl_stmt|;
name|rval
operator|=
literal|0
expr_stmt|;
comment|/* Save current terminal settings, and restore the original ones. */
name|gp
operator|=
name|sp
operator|->
name|gp
expr_stmt|;
if|if
condition|(
name|F_ISSET
argument_list|(
name|gp
argument_list|,
name|G_STDIN_TTY
argument_list|)
condition|)
block|{
if|if
condition|(
name|tcgetattr
argument_list|(
name|STDIN_FILENO
argument_list|,
operator|&
name|t
argument_list|)
condition|)
block|{
name|msgq
argument_list|(
name|sp
argument_list|,
name|M_SYSERR
argument_list|,
literal|"suspend: tcgetattr"
argument_list|)
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
block|}
if|if
condition|(
name|F_ISSET
argument_list|(
name|gp
argument_list|,
name|G_TERMIOS_SET
argument_list|)
operator|&&
name|tcsetattr
argument_list|(
name|STDIN_FILENO
argument_list|,
name|TCSASOFT
operator||
name|TCSADRAIN
argument_list|,
operator|&
name|gp
operator|->
name|original_termios
argument_list|)
condition|)
block|{
name|msgq
argument_list|(
name|sp
argument_list|,
name|M_SYSERR
argument_list|,
literal|"suspend: tcsetattr original"
argument_list|)
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
block|}
block|}
comment|/* Push out any waiting messages. */
operator|(
name|void
operator|)
name|sex_refresh
argument_list|(
name|sp
argument_list|)
expr_stmt|;
comment|/* Stop the process group. */
if|if
condition|(
name|kill
argument_list|(
literal|0
argument_list|,
name|SIGTSTP
argument_list|)
condition|)
block|{
name|msgq
argument_list|(
name|sp
argument_list|,
name|M_SYSERR
argument_list|,
literal|"suspend: kill"
argument_list|)
expr_stmt|;
name|rval
operator|=
literal|1
expr_stmt|;
block|}
comment|/* Time passes ... */
comment|/* Restore current terminal settings. */
if|if
condition|(
name|F_ISSET
argument_list|(
name|gp
argument_list|,
name|G_STDIN_TTY
argument_list|)
operator|&&
name|tcsetattr
argument_list|(
name|STDIN_FILENO
argument_list|,
name|TCSASOFT
operator||
name|TCSADRAIN
argument_list|,
operator|&
name|t
argument_list|)
condition|)
block|{
name|msgq
argument_list|(
name|sp
argument_list|,
name|M_SYSERR
argument_list|,
literal|"suspend: tcsetattr current"
argument_list|)
expr_stmt|;
name|rval
operator|=
literal|1
expr_stmt|;
block|}
return|return
operator|(
name|rval
operator|)
return|;
block|}
end_function

end_unit

