begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988, 1989, 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Adam de Boor.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)lstOpen.c	5.3 (Berkeley) %G%"
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
comment|/*-  * LstOpen.c --  *	Open a list for sequential access. The sequential functions access the  *	list in a slightly different way. CurPtr points to their idea of the  *	current node in the list and they access the list based on it.  *	If the list is circular, Lst_Next and Lst_Prev will go around  *	the list forever. Lst_IsAtEnd must be used to determine when to stop.  */
end_comment

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

