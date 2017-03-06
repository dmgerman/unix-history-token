begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: lstRemove.c,v 1.16 2014/09/07 20:55:34 joerg Exp $	*/
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
literal|"$NetBSD: lstRemove.c,v 1.16 2014/09/07 20:55:34 joerg Exp $"
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
unit|static char sccsid[] = "@(#)lstRemove.c	8.1 (Berkeley) 6/6/93";
else|#
directive|else
end_else

begin_expr_stmt
name|__RCSID
argument_list|(
literal|"$NetBSD: lstRemove.c,v 1.16 2014/09/07 20:55:34 joerg Exp $"
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
comment|/*-  * LstRemove.c --  *	Remove an element from a list  */
end_comment

begin_include
include|#
directive|include
file|"lstInt.h"
end_include

begin_comment
comment|/*-  *-----------------------------------------------------------------------  * Lst_Remove --  *	Remove the given node from the given list.  *  * Results:  *	SUCCESS or FAILURE.  *  * Side Effects:  *	The list's firstPtr will be set to NULL if ln is the last  *	node on the list. firsPtr and lastPtr will be altered if ln is  *	either the first or last node, respectively, on the list.  *  *-----------------------------------------------------------------------  */
end_comment

begin_function
name|ReturnStatus
name|Lst_Remove
parameter_list|(
name|Lst
name|l
parameter_list|,
name|LstNode
name|ln
parameter_list|)
block|{
name|List
name|list
init|=
name|l
decl_stmt|;
name|ListNode
name|lNode
init|=
name|ln
decl_stmt|;
if|if
condition|(
operator|!
name|LstValid
argument_list|(
name|l
argument_list|)
operator|||
operator|!
name|LstNodeValid
argument_list|(
name|ln
argument_list|,
name|l
argument_list|)
condition|)
block|{
return|return
operator|(
name|FAILURE
operator|)
return|;
block|}
comment|/*      * unlink it from the list      */
if|if
condition|(
name|lNode
operator|->
name|nextPtr
operator|!=
name|NULL
condition|)
block|{
name|lNode
operator|->
name|nextPtr
operator|->
name|prevPtr
operator|=
name|lNode
operator|->
name|prevPtr
expr_stmt|;
block|}
if|if
condition|(
name|lNode
operator|->
name|prevPtr
operator|!=
name|NULL
condition|)
block|{
name|lNode
operator|->
name|prevPtr
operator|->
name|nextPtr
operator|=
name|lNode
operator|->
name|nextPtr
expr_stmt|;
block|}
comment|/*      * if either the firstPtr or lastPtr of the list point to this node,      * adjust them accordingly      */
if|if
condition|(
name|list
operator|->
name|firstPtr
operator|==
name|lNode
condition|)
block|{
name|list
operator|->
name|firstPtr
operator|=
name|lNode
operator|->
name|nextPtr
expr_stmt|;
block|}
if|if
condition|(
name|list
operator|->
name|lastPtr
operator|==
name|lNode
condition|)
block|{
name|list
operator|->
name|lastPtr
operator|=
name|lNode
operator|->
name|prevPtr
expr_stmt|;
block|}
comment|/*      * Sequential access stuff. If the node we're removing is the current      * node in the list, reset the current node to the previous one. If the      * previous one was non-existent (prevPtr == NULL), we set the      * end to be Unknown, since it is.      */
if|if
condition|(
name|list
operator|->
name|isOpen
operator|&&
operator|(
name|list
operator|->
name|curPtr
operator|==
name|lNode
operator|)
condition|)
block|{
name|list
operator|->
name|curPtr
operator|=
name|list
operator|->
name|prevPtr
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
name|list
operator|->
name|atEnd
operator|=
name|Unknown
expr_stmt|;
block|}
block|}
comment|/*      * the only way firstPtr can still point to ln is if ln is the last      * node on the list (the list is circular, so lNode->nextptr == lNode in      * this case). The list is, therefore, empty and is marked as such      */
if|if
condition|(
name|list
operator|->
name|firstPtr
operator|==
name|lNode
condition|)
block|{
name|list
operator|->
name|firstPtr
operator|=
name|NULL
expr_stmt|;
block|}
comment|/*      * note that the datum is unmolested. The caller must free it as      * necessary and as expected.      */
if|if
condition|(
name|lNode
operator|->
name|useCount
operator|==
literal|0
condition|)
block|{
name|free
argument_list|(
name|ln
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|lNode
operator|->
name|flags
operator||=
name|LN_DELETED
expr_stmt|;
block|}
return|return
operator|(
name|SUCCESS
operator|)
return|;
block|}
end_function

end_unit

