begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * LstOpen.c --  *	Open a list for sequential access. The sequential functions access the  *	list in a slightly different way. CurPtr points to their idea of the  *	current node in the list and they access the list based on it.  *	If the list is circular, Lst_Next and Lst_Prev will go around  *	the list forever. Lst_IsAtEnd must be used to determine when to stop.  *  * Copyright (c) 1988 by University of California Regents  *  * Permission to use, copy, modify, and distribute this  * software and its documentation for any purpose and without  * fee is hereby granted, provided that the above copyright  * notice appears in all copies.  Neither the University of California nor  * Adam de Boor makes any representations about the suitability of this  * software for any purpose.  It is provided "as is" without  * express or implied warranty.  */
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
literal|"$Id: lstOpen.c,v 1.6 88/11/17 20:53:43 adam Exp $ SPRITE (Berkeley)"
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
comment|/*-  *-----------------------------------------------------------------------  * Lst_Open --  *	Open a list for sequential access. A list can still be searched,  *	etc., without confusing these functions.  *  * Results:  *	SUCCESS or FAILURE.  *  * Side Effects:  *	isOpen is set TRUE and curPtr is set to NilListNode so the  *	other sequential functions no it was just opened and can choose  *	the first element accessed based on this.  *  *-----------------------------------------------------------------------  */
end_comment

begin_function
name|ReturnStatus
name|Lst_Open
parameter_list|(
name|l
parameter_list|)
specifier|register
name|Lst
name|l
decl_stmt|;
block|{
if|if
condition|(
name|LstValid
argument_list|(
name|l
argument_list|)
operator|==
name|FALSE
condition|)
block|{
return|return
operator|(
name|FAILURE
operator|)
return|;
block|}
operator|(
operator|(
name|List
operator|)
name|l
operator|)
operator|->
name|isOpen
operator|=
name|TRUE
expr_stmt|;
operator|(
operator|(
name|List
operator|)
name|l
operator|)
operator|->
name|atEnd
operator|=
name|LstIsEmpty
argument_list|(
name|l
argument_list|)
condition|?
name|Head
else|:
name|Unknown
expr_stmt|;
operator|(
operator|(
name|List
operator|)
name|l
operator|)
operator|->
name|curPtr
operator|=
name|NilListNode
expr_stmt|;
return|return
operator|(
name|SUCCESS
operator|)
return|;
block|}
end_function

end_unit

