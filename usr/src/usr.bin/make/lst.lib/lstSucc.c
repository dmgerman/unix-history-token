begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988, 1989, 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Adam de Boor.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)lstSucc.c	8.1 (Berkeley) %G%"
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
comment|/*-  * LstSucc.c --  *	return the successor to a given node  */
end_comment

begin_include
include|#
directive|include
file|"lstInt.h"
end_include

begin_comment
comment|/*-  *-----------------------------------------------------------------------  * Lst_Succ --  *	Return the sucessor to the given node on its list.  *  * Results:  *	The successor of the node, if it exists (note that on a circular  *	list, if the node is the only one in the list, it is its own  *	successor).  *  * Side Effects:  *	None.  *  *-----------------------------------------------------------------------  */
end_comment

begin_function
name|LstNode
name|Lst_Succ
parameter_list|(
name|ln
parameter_list|)
name|LstNode
name|ln
decl_stmt|;
block|{
if|if
condition|(
name|ln
operator|==
name|NILLNODE
condition|)
block|{
return|return
operator|(
name|NILLNODE
operator|)
return|;
block|}
else|else
block|{
return|return
operator|(
call|(
name|LstNode
call|)
argument_list|(
operator|(
name|ListNode
operator|)
name|ln
argument_list|)
operator|->
name|nextPtr
operator|)
return|;
block|}
block|}
end_function

end_unit

