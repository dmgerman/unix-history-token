begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988, 1989, 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Adam de Boor.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
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
literal|"@(#)lstFind.c	8.1 (Berkeley) 6/6/93"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_comment
comment|/*-  * LstFind.c --  *	Find a node on a list.  */
end_comment

begin_include
include|#
directive|include
file|"lstInt.h"
end_include

begin_comment
comment|/*-  *-----------------------------------------------------------------------  * Lst_Find --  *	Find a node on the given list using the given comparison function  *	and the given datum.  *  * Results:  *	The found node or NILLNODE if none matches.  *  * Side Effects:  *	None.  *  *-----------------------------------------------------------------------  */
end_comment

begin_function_decl
name|LstNode
name|Lst_Find
parameter_list|(
name|l
parameter_list|,
name|d
parameter_list|,
name|cProc
parameter_list|)
name|Lst
name|l
decl_stmt|;
name|ClientData
name|d
decl_stmt|;
function_decl|int
parameter_list|(
function_decl|*cProc
end_function_decl

begin_expr_stmt
unit|)
name|__P
argument_list|(
operator|(
name|ClientData
operator|,
name|ClientData
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_block
block|{
return|return
operator|(
name|Lst_FindFrom
argument_list|(
name|l
argument_list|,
name|Lst_First
argument_list|(
name|l
argument_list|)
argument_list|,
name|d
argument_list|,
name|cProc
argument_list|)
operator|)
return|;
block|}
end_block

end_unit

