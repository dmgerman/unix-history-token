begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
literal|"@(#)v_exmode.c	8.3 (Berkeley) 11/13/93"
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
file|"vi.h"
end_include

begin_include
include|#
directive|include
file|"vcmd.h"
end_include

begin_comment
comment|/*  * v_exmode --  *	Put the editor in EX mode.  */
end_comment

begin_function
name|int
name|v_exmode
parameter_list|(
name|sp
parameter_list|,
name|ep
parameter_list|,
name|vp
parameter_list|,
name|fm
parameter_list|,
name|tm
parameter_list|,
name|rp
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
name|MARK
modifier|*
name|fm
decl_stmt|,
decl|*
name|tm
decl_stmt|,
modifier|*
name|rp
decl_stmt|;
end_function

begin_block
block|{
name|sp
operator|->
name|saved_vi_mode
operator|=
name|F_ISSET
argument_list|(
name|sp
argument_list|,
name|S_VI_CURSES
operator||
name|S_VI_XAW
argument_list|)
expr_stmt|;
name|F_CLR
argument_list|(
name|sp
argument_list|,
name|S_SCREENS
argument_list|)
expr_stmt|;
name|F_SET
argument_list|(
name|sp
argument_list|,
name|S_EX
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

end_unit

