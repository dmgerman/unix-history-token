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
literal|"@(#)v_switch.c	8.7 (Berkeley) 3/8/94"
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
file|<queue.h>
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
file|"vcmd.h"
end_include

begin_include
include|#
directive|include
file|"excmd.h"
end_include

begin_comment
comment|/*  * v_switch -- ^^  *	Switch to the previous file.  */
end_comment

begin_function
name|int
name|v_switch
parameter_list|(
name|sp
parameter_list|,
name|ep
parameter_list|,
name|vp
parameter_list|)
name|SCR
modifier|*
name|sp
decl_stmt|;
name|EXF
modifier|*
name|ep
decl_stmt|;
name|VICMDARG
modifier|*
name|vp
decl_stmt|;
block|{
name|EXCMDARG
name|cmd
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
comment|/* 	 * Try the alternate file name, then the previous file 	 * name.  Use the real name, not the user's current name. 	 */
if|if
condition|(
name|sp
operator|->
name|alt_name
operator|!=
name|NULL
condition|)
name|name
operator|=
name|sp
operator|->
name|alt_name
expr_stmt|;
elseif|else
if|if
condition|(
name|sp
operator|->
name|p_frp
operator|!=
name|NULL
condition|)
name|name
operator|=
name|sp
operator|->
name|p_frp
operator|->
name|name
expr_stmt|;
else|else
block|{
name|msgq
argument_list|(
name|sp
argument_list|,
name|M_ERR
argument_list|,
literal|"No previous file to edit."
argument_list|)
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
block|}
comment|/* If autowrite is set, write out the file. */
if|if
condition|(
name|F_ISSET
argument_list|(
name|ep
argument_list|,
name|F_MODIFIED
argument_list|)
condition|)
if|if
condition|(
name|O_ISSET
argument_list|(
name|sp
argument_list|,
name|O_AUTOWRITE
argument_list|)
condition|)
block|{
if|if
condition|(
name|file_write
argument_list|(
name|sp
argument_list|,
name|ep
argument_list|,
name|NULL
argument_list|,
name|NULL
argument_list|,
name|NULL
argument_list|,
name|FS_ALL
argument_list|)
condition|)
return|return
operator|(
literal|1
operator|)
return|;
block|}
else|else
block|{
name|msgq
argument_list|(
name|sp
argument_list|,
name|M_ERR
argument_list|,
literal|"Modified since last write; write or use :edit! to override."
argument_list|)
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
block|}
name|SETCMDARG
argument_list|(
name|cmd
argument_list|,
name|C_EDIT
argument_list|,
literal|0
argument_list|,
name|OOBLNO
argument_list|,
name|OOBLNO
argument_list|,
literal|0
argument_list|,
name|name
argument_list|)
expr_stmt|;
return|return
operator|(
name|sp
operator|->
name|s_ex_cmd
argument_list|(
name|sp
argument_list|,
name|ep
argument_list|,
operator|&
name|cmd
argument_list|,
operator|&
name|vp
operator|->
name|m_final
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

