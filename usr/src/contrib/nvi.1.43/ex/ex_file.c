begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993, 1994  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
literal|"@(#)ex_file.c	9.2 (Berkeley) 12/1/94"
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
file|<stdlib.h>
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

begin_comment
comment|/*  * ex_file -- :f[ile] [name]  *	Change the file's name and display the status line.  */
end_comment

begin_function
name|int
name|ex_file
parameter_list|(
name|sp
parameter_list|,
name|cmdp
parameter_list|)
name|SCR
modifier|*
name|sp
decl_stmt|;
name|EXCMDARG
modifier|*
name|cmdp
decl_stmt|;
block|{
name|CHAR_T
modifier|*
name|p
decl_stmt|;
name|FREF
modifier|*
name|frp
decl_stmt|;
name|NEEDFILE
argument_list|(
name|sp
argument_list|,
name|cmdp
operator|->
name|cmd
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|cmdp
operator|->
name|argc
condition|)
block|{
case|case
literal|0
case|:
break|break;
case|case
literal|1
case|:
name|frp
operator|=
name|sp
operator|->
name|frp
expr_stmt|;
comment|/* Make sure can allocate enough space. */
if|if
condition|(
operator|(
name|p
operator|=
name|v_strdup
argument_list|(
name|sp
argument_list|,
name|cmdp
operator|->
name|argv
index|[
literal|0
index|]
operator|->
name|bp
argument_list|,
name|cmdp
operator|->
name|argv
index|[
literal|0
index|]
operator|->
name|len
argument_list|)
operator|)
operator|==
name|NULL
condition|)
return|return
operator|(
literal|1
operator|)
return|;
comment|/* If already have a file name, it becomes the alternate. */
if|if
condition|(
operator|!
name|F_ISSET
argument_list|(
name|frp
argument_list|,
name|FR_TMPFILE
argument_list|)
condition|)
name|set_alt_name
argument_list|(
name|sp
argument_list|,
name|frp
operator|->
name|name
argument_list|)
expr_stmt|;
comment|/* Free the previous name. */
name|free
argument_list|(
name|frp
operator|->
name|name
argument_list|)
expr_stmt|;
name|frp
operator|->
name|name
operator|=
name|p
expr_stmt|;
comment|/* 		 * The file has a real name, it's no longer a temporary, 		 * clear the temporary file flags.  The read-only flag 		 * follows the file name, clear it as well. 		 */
name|F_CLR
argument_list|(
name|frp
argument_list|,
name|FR_RDONLY
operator||
name|FR_TMPEXIT
operator||
name|FR_TMPFILE
argument_list|)
expr_stmt|;
comment|/* Have to force a write if the file exists, next time. */
name|F_SET
argument_list|(
name|frp
argument_list|,
name|FR_NAMECHANGE
argument_list|)
expr_stmt|;
break|break;
default|default:
name|abort
argument_list|()
expr_stmt|;
block|}
return|return
operator|(
name|msg_status
argument_list|(
name|sp
argument_list|,
name|sp
operator|->
name|lno
argument_list|,
literal|1
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

