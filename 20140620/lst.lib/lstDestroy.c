begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: lstDestroy.c,v 1.16 2008/12/13 15:19:29 dsl Exp $	*/
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
literal|"$NetBSD: lstDestroy.c,v 1.16 2008/12/13 15:19:29 dsl Exp $"
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
unit|static char sccsid[] = "@(#)lstDestroy.c	8.1 (Berkeley) 6/6/93";
else|#
directive|else
end_else

begin_expr_stmt
name|__RCSID
argument_list|(
literal|"$NetBSD: lstDestroy.c,v 1.16 2008/12/13 15:19:29 dsl Exp $"
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
comment|/*-  * LstDestroy.c --  *	Nuke a list and all its resources  */
end_comment

begin_include
include|#
directive|include
file|"lstInt.h"
end_include

begin_comment
comment|/*-  *-----------------------------------------------------------------------  * Lst_Destroy --  *	Destroy a list and free all its resources. If the freeProc is  *	given, it is called with the datum from each node in turn before  *	the node is freed.  *  * Results:  *	None.  *  * Side Effects:  *	The given list is freed in its entirety.  *  *-----------------------------------------------------------------------  */
end_comment

begin_function
name|void
name|Lst_Destroy
parameter_list|(
name|Lst
name|list
parameter_list|,
name|FreeProc
modifier|*
name|freeProc
parameter_list|)
block|{
name|ListNode
name|ln
decl_stmt|;
name|ListNode
name|tln
init|=
name|NULL
decl_stmt|;
if|if
condition|(
name|list
operator|==
name|NULL
condition|)
return|return;
comment|/* To ease scanning */
if|if
condition|(
name|list
operator|->
name|lastPtr
operator|!=
name|NULL
condition|)
name|list
operator|->
name|lastPtr
operator|->
name|nextPtr
operator|=
name|NULL
expr_stmt|;
else|else
block|{
name|free
argument_list|(
name|list
argument_list|)
expr_stmt|;
return|return;
block|}
if|if
condition|(
name|freeProc
condition|)
block|{
for|for
control|(
name|ln
operator|=
name|list
operator|->
name|firstPtr
init|;
name|ln
operator|!=
name|NULL
condition|;
name|ln
operator|=
name|tln
control|)
block|{
name|tln
operator|=
name|ln
operator|->
name|nextPtr
expr_stmt|;
name|freeProc
argument_list|(
name|ln
operator|->
name|datum
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|ln
argument_list|)
expr_stmt|;
block|}
block|}
else|else
block|{
for|for
control|(
name|ln
operator|=
name|list
operator|->
name|firstPtr
init|;
name|ln
operator|!=
name|NULL
condition|;
name|ln
operator|=
name|tln
control|)
block|{
name|tln
operator|=
name|ln
operator|->
name|nextPtr
expr_stmt|;
name|free
argument_list|(
name|ln
argument_list|)
expr_stmt|;
block|}
block|}
name|free
argument_list|(
name|list
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

