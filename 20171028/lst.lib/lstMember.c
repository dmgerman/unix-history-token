begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: lstMember.c,v 1.14 2013/11/14 00:01:28 sjg Exp $	*/
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
literal|"$NetBSD: lstMember.c,v 1.14 2013/11/14 00:01:28 sjg Exp $"
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
unit|static char sccsid[] = "@(#)lstMember.c	8.1 (Berkeley) 6/6/93";
else|#
directive|else
end_else

begin_expr_stmt
name|__RCSID
argument_list|(
literal|"$NetBSD: lstMember.c,v 1.14 2013/11/14 00:01:28 sjg Exp $"
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
comment|/*-  * lstMember.c --  *	See if a given datum is on a given list.  */
end_comment

begin_include
include|#
directive|include
file|"lstInt.h"
end_include

begin_function
name|LstNode
name|Lst_Member
parameter_list|(
name|Lst
name|l
parameter_list|,
name|void
modifier|*
name|d
parameter_list|)
block|{
name|List
name|list
init|=
name|l
decl_stmt|;
name|ListNode
name|lNode
decl_stmt|;
if|if
condition|(
name|list
operator|==
name|NULL
condition|)
block|{
return|return
name|NULL
return|;
block|}
name|lNode
operator|=
name|list
operator|->
name|firstPtr
expr_stmt|;
if|if
condition|(
name|lNode
operator|==
name|NULL
condition|)
block|{
return|return
name|NULL
return|;
block|}
do|do
block|{
if|if
condition|(
name|lNode
operator|->
name|datum
operator|==
name|d
condition|)
block|{
return|return
name|lNode
return|;
block|}
name|lNode
operator|=
name|lNode
operator|->
name|nextPtr
expr_stmt|;
block|}
do|while
condition|(
name|lNode
operator|!=
name|NULL
operator|&&
name|lNode
operator|!=
name|list
operator|->
name|firstPtr
condition|)
do|;
return|return
name|NULL
return|;
block|}
end_function

end_unit

