begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: lstDupl.c,v 1.16 2009/01/23 21:26:30 dsl Exp $	*/
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
literal|"$NetBSD: lstDupl.c,v 1.16 2009/01/23 21:26:30 dsl Exp $"
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
unit|static char sccsid[] = "@(#)lstDupl.c	8.1 (Berkeley) 6/6/93";
else|#
directive|else
end_else

begin_expr_stmt
name|__RCSID
argument_list|(
literal|"$NetBSD: lstDupl.c,v 1.16 2009/01/23 21:26:30 dsl Exp $"
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
comment|/*-  * listDupl.c --  *	Duplicate a list. This includes duplicating the individual  *	elements.  */
end_comment

begin_include
include|#
directive|include
file|"lstInt.h"
end_include

begin_comment
comment|/*-  *-----------------------------------------------------------------------  * Lst_Duplicate --  *	Duplicate an entire list. If a function to copy a void *is  *	given, the individual client elements will be duplicated as well.  *  * Input:  *	l		the list to duplicate  *	copyProc	A function to duplicate each void *  *  * Results:  *	The new Lst structure or NULL if failure.  *  * Side Effects:  *	A new list is created.  *-----------------------------------------------------------------------  */
end_comment

begin_function
name|Lst
name|Lst_Duplicate
parameter_list|(
name|Lst
name|l
parameter_list|,
name|DuplicateProc
modifier|*
name|copyProc
parameter_list|)
block|{
name|Lst
name|nl
decl_stmt|;
name|ListNode
name|ln
decl_stmt|;
name|List
name|list
init|=
name|l
decl_stmt|;
if|if
condition|(
operator|!
name|LstValid
argument_list|(
name|l
argument_list|)
condition|)
block|{
return|return
name|NULL
return|;
block|}
name|nl
operator|=
name|Lst_Init
argument_list|(
name|list
operator|->
name|isCirc
argument_list|)
expr_stmt|;
if|if
condition|(
name|nl
operator|==
name|NULL
condition|)
block|{
return|return
name|NULL
return|;
block|}
name|ln
operator|=
name|list
operator|->
name|firstPtr
expr_stmt|;
while|while
condition|(
name|ln
operator|!=
name|NULL
condition|)
block|{
if|if
condition|(
name|copyProc
operator|!=
name|NULL
condition|)
block|{
if|if
condition|(
name|Lst_AtEnd
argument_list|(
name|nl
argument_list|,
name|copyProc
argument_list|(
name|ln
operator|->
name|datum
argument_list|)
argument_list|)
operator|==
name|FAILURE
condition|)
block|{
return|return
name|NULL
return|;
block|}
block|}
elseif|else
if|if
condition|(
name|Lst_AtEnd
argument_list|(
name|nl
argument_list|,
name|ln
operator|->
name|datum
argument_list|)
operator|==
name|FAILURE
condition|)
block|{
return|return
name|NULL
return|;
block|}
if|if
condition|(
name|list
operator|->
name|isCirc
operator|&&
name|ln
operator|==
name|list
operator|->
name|lastPtr
condition|)
block|{
name|ln
operator|=
name|NULL
expr_stmt|;
block|}
else|else
block|{
name|ln
operator|=
name|ln
operator|->
name|nextPtr
expr_stmt|;
block|}
block|}
return|return
operator|(
name|nl
operator|)
return|;
block|}
end_function

end_unit

