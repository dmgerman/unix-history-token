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
literal|"@(#)lstIndex.c	5.2 (Berkeley) %G%"
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
comment|/*-  * lstIndex.c --  *	Function to return the index of a datum in a Lst.  */
end_comment

begin_include
include|#
directive|include
file|"lstInt.h"
end_include

begin_comment
comment|/*-  *-----------------------------------------------------------------------  * Lst_Index --  *	Return the index of a datum in a Lst. Indices start at 0.  *  * Results:  *	Returns -1 if the datum isn't in the Lst, or the index of  *	the datum if it is.  *  * Side Effects:  *	None.  *  *-----------------------------------------------------------------------  */
end_comment

begin_function
name|int
name|Lst_Index
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
specifier|register
name|int
name|index
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
operator|(
operator|-
literal|1
operator|)
return|;
block|}
name|index
operator|=
literal|0
expr_stmt|;
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
name|index
operator|)
return|;
block|}
else|else
block|{
name|lNode
operator|=
name|lNode
operator|->
name|nextPtr
expr_stmt|;
name|index
operator|+=
literal|1
expr_stmt|;
block|}
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
operator|(
operator|-
literal|1
operator|)
return|;
block|}
end_function

end_unit

