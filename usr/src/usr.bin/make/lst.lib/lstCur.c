begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * LstCur.c --  *	Return the current node in the list.  *	The sequential functions access the list in a slightly different way.  *	CurPtr points to their idea of the current node in the list and they  *	access the list based on it. Because the list is circular, Lst_Next  *	and Lst_Prev will go around the list forever. Lst_IsAtEnd must be  *	used to determine when to stop.  *  * Copyright (c) 1988 by University of California Regents  *  * Permission to use, copy, modify, and distribute this  * software and its documentation for any purpose and without  * fee is hereby granted, provided that the above copyright  * notice appears in all copies.  Neither the University of California nor  * Adam de Boor makes any representations about the suitability of this  * software for any purpose.  It is provided "as is" without  * express or implied warranty.  */
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
literal|"$Id: lstCur.c,v 1.4 88/11/17 20:52:03 adam Exp $ SPRITE (Berkeley)"
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
comment|/*-  *-----------------------------------------------------------------------  * Lst_Cur --  *	Return the current node if the list is open for sequential  *	access.  *  * Results:  *	The current node or NILLNODE if the list isn't open..  *  * Side Effects:  *	None.  *  *-----------------------------------------------------------------------  */
end_comment

begin_function
name|LstNode
name|Lst_Cur
parameter_list|(
name|l
parameter_list|)
name|Lst
name|l
decl_stmt|;
block|{
specifier|register
name|List
name|list
init|=
operator|(
name|List
operator|)
name|l
decl_stmt|;
if|if
condition|(
operator|(
name|LstValid
argument_list|(
name|l
argument_list|)
operator|==
name|FALSE
operator|)
operator|||
operator|(
name|list
operator|->
name|isOpen
operator|==
name|FALSE
operator|)
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
operator|(
name|LstNode
operator|)
name|list
operator|->
name|curPtr
operator|)
return|;
block|}
block|}
end_function

end_unit

