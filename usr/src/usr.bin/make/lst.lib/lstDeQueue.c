begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988, 1989, 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Adam de Boor.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
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
literal|"@(#)lstDeQueue.c	5.2 (Berkeley) %G%"
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
comment|/*-  * LstDeQueue.c --  *	Remove the node and return its datum from the head of the list  */
end_comment

begin_include
include|#
directive|include
file|"lstInt.h"
end_include

begin_comment
comment|/*-  *-----------------------------------------------------------------------  * Lst_DeQueue --  *	Remove and return the datum at the head of the given list.  *  * Results:  *	The datum in the node at the head or (ick) NIL if the list  *	is empty.  *  * Side Effects:  *	The head node is removed from the list.  *  *-----------------------------------------------------------------------  */
end_comment

begin_function
name|ClientData
name|Lst_DeQueue
parameter_list|(
name|l
parameter_list|)
name|Lst
name|l
decl_stmt|;
block|{
name|ClientData
name|rd
decl_stmt|;
specifier|register
name|ListNode
name|tln
decl_stmt|;
name|tln
operator|=
operator|(
name|ListNode
operator|)
name|Lst_First
argument_list|(
name|l
argument_list|)
expr_stmt|;
if|if
condition|(
name|tln
operator|==
name|NilListNode
condition|)
block|{
return|return
operator|(
operator|(
name|ClientData
operator|)
name|NIL
operator|)
return|;
block|}
name|rd
operator|=
name|tln
operator|->
name|datum
expr_stmt|;
if|if
condition|(
name|Lst_Remove
argument_list|(
name|l
argument_list|,
operator|(
name|LstNode
operator|)
name|tln
argument_list|)
operator|==
name|FAILURE
condition|)
block|{
return|return
operator|(
operator|(
name|ClientData
operator|)
name|NIL
operator|)
return|;
block|}
else|else
block|{
return|return
operator|(
name|rd
operator|)
return|;
block|}
block|}
end_function

end_unit

