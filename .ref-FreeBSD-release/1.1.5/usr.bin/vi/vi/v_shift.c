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
literal|"@(#)v_shift.c	8.5 (Berkeley) 3/8/94"
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
file|"excmd.h"
end_include

begin_include
include|#
directive|include
file|"vcmd.h"
end_include

begin_comment
comment|/*  * v_shiftl -- [count]<motion  *	Shift lines left.  */
end_comment

begin_function
name|int
name|v_shiftl
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
name|SETCMDARG
argument_list|(
name|cmd
argument_list|,
name|C_SHIFTL
argument_list|,
literal|2
argument_list|,
name|vp
operator|->
name|m_start
operator|.
name|lno
argument_list|,
name|vp
operator|->
name|m_stop
operator|.
name|lno
argument_list|,
literal|0
argument_list|,
literal|"<"
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

begin_comment
comment|/*  * v_shiftr -- [count]>motion  *	Shift lines right.  */
end_comment

begin_function
name|int
name|v_shiftr
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
name|SETCMDARG
argument_list|(
name|cmd
argument_list|,
name|C_SHIFTR
argument_list|,
literal|2
argument_list|,
name|vp
operator|->
name|m_start
operator|.
name|lno
argument_list|,
name|vp
operator|->
name|m_stop
operator|.
name|lno
argument_list|,
literal|0
argument_list|,
literal|">"
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

