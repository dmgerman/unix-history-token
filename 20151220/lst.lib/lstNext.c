begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: lstNext.c,v 1.12 2008/12/13 15:19:29 dsl Exp $	*/
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
literal|"$NetBSD: lstNext.c,v 1.12 2008/12/13 15:19:29 dsl Exp $"
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
unit|static char sccsid[] = "@(#)lstNext.c	8.1 (Berkeley) 6/6/93";
else|#
directive|else
end_else

begin_expr_stmt
name|__RCSID
argument_list|(
literal|"$NetBSD: lstNext.c,v 1.12 2008/12/13 15:19:29 dsl Exp $"
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
comment|/*-  * LstNext.c --  *	Return the next node for a list.  *	The sequential functions access the list in a slightly different way.  *	CurPtr points to their idea of the current node in the list and they  *	access the list based on it. Because the list is circular, Lst_Next  *	and Lst_Prev will go around the list forever. Lst_IsAtEnd must be  *	used to determine when to stop.  */
end_comment

begin_include
include|#
directive|include
file|"lstInt.h"
end_include

begin_comment
comment|/*-  *-----------------------------------------------------------------------  * Lst_Next --  *	Return the next node for the given list.  *  * Results:  *	The next node or NULL if the list has yet to be opened. Also  *	if the list is non-circular and the end has been reached, NULL  *	is returned.  *  * Side Effects:  *	the curPtr field is updated.  *  *-----------------------------------------------------------------------  */
end_comment

begin_function
name|LstNode
name|Lst_Next
parameter_list|(
name|Lst
name|l
parameter_list|)
block|{
name|ListNode
name|tln
decl_stmt|;
name|List
name|list
init|=
name|l
decl_stmt|;
if|if
condition|(
operator|(
name|LstValid
argument_list|(
name|l
argument_list|)
operator|==
name|FALSE
operator|)
operator|||
operator|(
name|list
operator|->
name|isOpen
operator|==
name|FALSE
operator|)
condition|)
block|{
return|return
name|NULL
return|;
block|}
name|list
operator|->
name|prevPtr
operator|=
name|list
operator|->
name|curPtr
expr_stmt|;
if|if
condition|(
name|list
operator|->
name|curPtr
operator|==
name|NULL
condition|)
block|{
if|if
condition|(
name|list
operator|->
name|atEnd
operator|==
name|Unknown
condition|)
block|{
comment|/* 	     * If we're just starting out, atEnd will be Unknown. 	     * Then we want to start this thing off in the right 	     * direction -- at the start with atEnd being Middle. 	     */
name|list
operator|->
name|curPtr
operator|=
name|tln
operator|=
name|list
operator|->
name|firstPtr
expr_stmt|;
name|list
operator|->
name|atEnd
operator|=
name|Middle
expr_stmt|;
block|}
else|else
block|{
name|tln
operator|=
name|NULL
expr_stmt|;
name|list
operator|->
name|atEnd
operator|=
name|Tail
expr_stmt|;
block|}
block|}
else|else
block|{
name|tln
operator|=
name|list
operator|->
name|curPtr
operator|->
name|nextPtr
expr_stmt|;
name|list
operator|->
name|curPtr
operator|=
name|tln
expr_stmt|;
if|if
condition|(
name|tln
operator|==
name|list
operator|->
name|firstPtr
operator|||
name|tln
operator|==
name|NULL
condition|)
block|{
comment|/* 	     * If back at the front, then we've hit the end... 	     */
name|list
operator|->
name|atEnd
operator|=
name|Tail
expr_stmt|;
block|}
else|else
block|{
comment|/* 	     * Reset to Middle if gone past first. 	     */
name|list
operator|->
name|atEnd
operator|=
name|Middle
expr_stmt|;
block|}
block|}
return|return
operator|(
name|tln
operator|)
return|;
block|}
end_function

end_unit

