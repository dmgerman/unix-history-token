begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988, 1989, 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Adam de Boor.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * @(#)lstRemove.c	8.1 (Berkeley) 6/6/93  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_comment
comment|/*-  * LstRemove.c --  *	Remove an element from a list  */
end_comment

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
file|"make.h"
end_include

begin_include
include|#
directive|include
file|"util.h"
end_include

begin_include
include|#
directive|include
file|"lst.h"
end_include

begin_comment
comment|/*-  *-----------------------------------------------------------------------  * Lst_Remove --  *	Remove the given node from the given list.  *  * Results:  *	SUCCESS or FAILURE.  *  * Side Effects:  *	The list's firstPtr will be set to NULL if ln is the last  *	node on the list. firsPtr and lastPtr will be altered if ln is  *	either the first or last node, respectively, on the list.  *  *-----------------------------------------------------------------------  */
end_comment

begin_function
name|void
name|Lst_Remove
parameter_list|(
name|Lst
modifier|*
name|list
parameter_list|,
name|LstNode
modifier|*
name|ln
parameter_list|)
block|{
comment|/*      * unlink it from the list      */
if|if
condition|(
name|ln
operator|->
name|nextPtr
operator|!=
name|NULL
condition|)
comment|/* unlink from the backward chain */
name|ln
operator|->
name|nextPtr
operator|->
name|prevPtr
operator|=
name|ln
operator|->
name|prevPtr
expr_stmt|;
else|else
comment|/* this was the last element */
name|list
operator|->
name|lastPtr
operator|=
name|ln
operator|->
name|prevPtr
expr_stmt|;
if|if
condition|(
name|ln
operator|->
name|prevPtr
operator|!=
name|NULL
condition|)
comment|/* unlink from the forward chain */
name|ln
operator|->
name|prevPtr
operator|->
name|nextPtr
operator|=
name|ln
operator|->
name|nextPtr
expr_stmt|;
else|else
comment|/* this was the first element */
name|list
operator|->
name|firstPtr
operator|=
name|ln
operator|->
name|nextPtr
expr_stmt|;
comment|/*      * note that the datum is unmolested. The caller must free it as      * necessary and as expected.      */
if|if
condition|(
name|ln
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
name|ln
operator|->
name|flags
operator||=
name|LN_DELETED
expr_stmt|;
block|}
block|}
end_function

end_unit

