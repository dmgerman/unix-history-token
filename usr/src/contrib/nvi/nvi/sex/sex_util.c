begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
literal|"@(#)sex_util.c	8.1 (Berkeley) 6/9/93"
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
file|"vi.h"
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
name|fprintf
argument_list|(
name|sp
operator|->
name|stdfp
argument_list|,
literal|"\07"
argument_list|)
expr_stmt|;
comment|/* \a */
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
comment|/* Save ex/vi terminal settings, and restore the original ones. */
operator|(
name|void
operator|)
name|tcgetattr
argument_list|(
name|STDIN_FILENO
argument_list|,
operator|&
name|t
argument_list|)
expr_stmt|;
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
name|sp
operator|->
name|gp
operator|->
name|original_termios
argument_list|)
expr_stmt|;
comment|/* Kill the process group. */
if|if
condition|(
name|kill
argument_list|(
literal|0
argument_list|,
name|SIGTSTP
argument_list|)
condition|)
name|msgq
argument_list|(
name|sp
argument_list|,
name|M_ERR
argument_list|,
literal|"Error: SIGTSTP: %s"
argument_list|,
name|strerror
argument_list|(
name|errno
argument_list|)
argument_list|)
expr_stmt|;
comment|/* Restore ex/vi terminal settings. */
operator|(
name|void
operator|)
name|tcsetattr
argument_list|(
name|STDIN_FILENO
argument_list|,
name|TCSAFLUSH
argument_list|,
operator|&
name|t
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

end_unit

