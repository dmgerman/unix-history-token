begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * LstReplace.c --  *	Replace the datum in a node with a new datum  *  * Copyright (c) 1988 by University of California Regents  *  * Permission to use, copy, modify, and distribute this  * software and its documentation for any purpose and without  * fee is hereby granted, provided that the above copyright  * notice appears in all copies.  Neither the University of California nor  * Adam de Boor makes any representations about the suitability of this  * software for any purpose.  It is provided "as is" without  * express or implied warranty.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|rcsid
init|=
literal|"$Id: lstReplace.c,v 1.4 88/11/17 20:54:01 adam Exp $ SPRITE (Berkeley)"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|lint
end_endif

begin_include
include|#
directive|include
file|"lstInt.h"
end_include

begin_comment
comment|/*-  *-----------------------------------------------------------------------  * Lst_Replace --  *	Replace the datum in the given node with the new datum  *  * Results:  *	SUCCESS or FAILURE.  *  * Side Effects:  *	The datum field fo the node is altered.  *  *-----------------------------------------------------------------------  */
end_comment

begin_function
name|ReturnStatus
name|Lst_Replace
parameter_list|(
name|ln
parameter_list|,
name|d
parameter_list|)
specifier|register
name|LstNode
name|ln
decl_stmt|;
name|ClientData
name|d
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
name|FAILURE
operator|)
return|;
block|}
else|else
block|{
operator|(
operator|(
name|ListNode
operator|)
name|ln
operator|)
operator|->
name|datum
operator|=
name|d
expr_stmt|;
return|return
operator|(
name|SUCCESS
operator|)
return|;
block|}
block|}
end_function

end_unit

