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
literal|"@(#)lstMove.c	5.2 (Berkeley) %G%"
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
comment|/*-  * LstMove.c --  *	Move an existing node after or before one in the same or different  *	list.  */
end_comment

begin_include
include|#
directive|include
file|"lstInt.h"
end_include

begin_comment
comment|/*-  *-----------------------------------------------------------------------  * Lst_Move --  *	Move a node after or before a destination node. The nodes do not  *	need to be in the same list, of course.  *  * Results:  *	SUCCESS or FAILURE.  *  * Side Effects:  *	The firstPtr and lastPtr fields of either or both of the involved  *	lists may be altered to reflect reality.  *  *-----------------------------------------------------------------------  */
end_comment

begin_function
name|ReturnStatus
name|Lst_Move
parameter_list|(
name|ls
parameter_list|,
name|lns
parameter_list|,
name|ld
parameter_list|,
name|lnd
parameter_list|,
name|before
parameter_list|)
name|Lst
name|ls
decl_stmt|;
comment|/* Source list */
specifier|register
name|LstNode
name|lns
decl_stmt|;
comment|/* source list node */
name|Lst
name|ld
decl_stmt|;
comment|/* Destination list */
specifier|register
name|LstNode
name|lnd
decl_stmt|;
comment|/* destination list node */
name|Boolean
name|before
decl_stmt|;
comment|/* true if should use Lst_Insert */
block|{
name|ClientData
name|d
decl_stmt|;
name|ReturnStatus
name|rval
decl_stmt|;
if|if
condition|(
name|lns
operator|==
name|NILLNODE
operator|||
name|lnd
operator|==
name|NILLNODE
condition|)
block|{
return|return
operator|(
name|FAILURE
operator|)
return|;
block|}
name|d
operator|=
operator|(
operator|(
name|ListNode
operator|)
name|lns
operator|)
operator|->
name|datum
expr_stmt|;
if|if
condition|(
name|Lst_Remove
argument_list|(
name|ls
argument_list|,
name|lns
argument_list|)
operator|==
name|FAILURE
condition|)
block|{
return|return
operator|(
name|FAILURE
operator|)
return|;
block|}
if|if
condition|(
name|before
operator|==
name|TRUE
condition|)
block|{
name|rval
operator|=
name|Lst_Insert
argument_list|(
name|ld
argument_list|,
name|lnd
argument_list|,
name|d
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|rval
operator|=
name|Lst_Append
argument_list|(
name|ld
argument_list|,
name|lnd
argument_list|,
name|d
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
name|rval
operator|)
return|;
block|}
end_function

end_unit

