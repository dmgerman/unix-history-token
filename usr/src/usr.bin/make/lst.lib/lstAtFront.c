begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * LstAtFront.c --  *	Add a node at the front of the list  *  * Copyright (c) 1988 by the Regents of the University of California  *  * Permission to use, copy, modify, and distribute this  * software and its documentation for any purpose and without  * fee is hereby granted, provided that the above copyright  * notice appears in all copies.  Neither the University of California nor  * Adam de Boor makes any representations about the suitability of this  * software for any purpose.  It is provided "as is" without  * express or implied warranty.  *  */
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
literal|"$Id: lstAtFront.c,v 1.3 88/11/17 20:51:51 adam Exp $ SPRITE (Berkeley)"
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
comment|/*-  *-----------------------------------------------------------------------  * Lst_AtFront --  *	Place a piece of data at the front of a list  *  * Results:  *	SUCCESS or FAILURE  *  * Side Effects:  *	A new ListNode is created and stuck at the front of the list.  *	hence, firstPtr (and possible lastPtr) in the list are altered.  *  *-----------------------------------------------------------------------  */
end_comment

begin_function
name|ReturnStatus
name|Lst_AtFront
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
specifier|register
name|LstNode
name|front
decl_stmt|;
name|front
operator|=
name|Lst_First
argument_list|(
name|l
argument_list|)
expr_stmt|;
return|return
operator|(
name|Lst_Insert
argument_list|(
name|l
argument_list|,
name|front
argument_list|,
name|d
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

