begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988, 1989, 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Adam de Boor.  *  * Redistribution and use in source and binary forms are permitted  * provided that: (1) source distributions retain this entire copyright  * notice and comment, and (2) distributions including binaries display  * the following acknowledgement:  ``This product includes software  * developed by the University of California, Berkeley and its contributors''  * in the documentation or other materials provided with the distribution  * and in all advertising materials mentioning features or use of this  * software. Neither the name of the University nor the names of its  * contributors may be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
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
literal|"@(#)lstMember.c	5.3 (Berkeley) 6/1/90"
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
name|l
parameter_list|,
name|d
parameter_list|)
name|Lst
name|l
decl_stmt|;
name|ClientData
name|d
decl_stmt|;
block|{
name|List
name|list
init|=
operator|(
name|List
operator|)
name|l
decl_stmt|;
specifier|register
name|ListNode
name|lNode
decl_stmt|;
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
name|NilListNode
condition|)
block|{
return|return
name|NILLNODE
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
operator|(
name|LstNode
operator|)
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
name|NilListNode
operator|&&
name|lNode
operator|!=
name|list
operator|->
name|firstPtr
condition|)
do|;
return|return
name|NILLNODE
return|;
block|}
end_function

end_unit

