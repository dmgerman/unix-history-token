begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: lstAtFront.c,v 1.13 2009/01/23 21:26:30 dsl Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1988, 1989, 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Adam de Boor.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MAKE_NATIVE
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|rcsid
index|[]
init|=
literal|"$NetBSD: lstAtFront.c,v 1.13 2009/01/23 21:26:30 dsl Exp $"
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_if
if|#
directive|if
literal|0
end_if

begin_else
unit|static char sccsid[] = "@(#)lstAtFront.c	8.1 (Berkeley) 6/6/93";
else|#
directive|else
end_else

begin_expr_stmt
name|__RCSID
argument_list|(
literal|"$NetBSD: lstAtFront.c,v 1.13 2009/01/23 21:26:30 dsl Exp $"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*-  * LstAtFront.c --  *	Add a node at the front of the list  */
end_comment

begin_include
include|#
directive|include
file|"lstInt.h"
end_include

begin_comment
comment|/*-  *-----------------------------------------------------------------------  * Lst_AtFront --  *	Place a piece of data at the front of a list  *  * Results:  *	SUCCESS or FAILURE  *  * Side Effects:  *	A new ListNode is created and stuck at the front of the list.  *	hence, firstPtr (and possible lastPtr) in the list are altered.  *  *-----------------------------------------------------------------------  */
end_comment

begin_function
name|ReturnStatus
name|Lst_AtFront
parameter_list|(
name|Lst
name|l
parameter_list|,
name|void
modifier|*
name|d
parameter_list|)
block|{
name|LstNode
name|front
decl_stmt|;
name|front
operator|=
name|Lst_First
argument_list|(
name|l
argument_list|)
expr_stmt|;
return|return
operator|(
name|Lst_InsertBefore
argument_list|(
name|l
argument_list|,
name|front
argument_list|,
name|d
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

