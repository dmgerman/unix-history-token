begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * LstAtEnd.c --  *	Add a node at the end of the list  *  * Copyright (c) 1988 by the Regents of the University of California  *  * Permission to use, copy, modify, and distribute this  * software and its documentation for any purpose and without  * fee is hereby granted, provided that the above copyright  * notice appears in all copies.  Neither the University of California nor  * Adam de Boor makes any representations about the suitability of this  * software for any purpose.  It is provided "as is" without  * express or implied warranty.  *  */
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
literal|"$Id: lstAtEnd.c,v 1.3 88/11/17 20:51:48 adam Exp $ SPRITE (Berkeley)"
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
comment|/*-  *-----------------------------------------------------------------------  * Lst_AtEnd --  *	Add a node to the end of the given list  *  * Results:  *	SUCCESS if life is good.  *  * Side Effects:  *	A new ListNode is created and added to the list.  *  *-----------------------------------------------------------------------  */
end_comment

begin_function
name|ReturnStatus
name|Lst_AtEnd
parameter_list|(
name|l
parameter_list|,
name|d
parameter_list|)
name|Lst
name|l
decl_stmt|;
comment|/* List to which to add the datum */
name|ClientData
name|d
decl_stmt|;
comment|/* Datum to add */
block|{
specifier|register
name|LstNode
name|end
decl_stmt|;
name|end
operator|=
name|Lst_Last
argument_list|(
name|l
argument_list|)
expr_stmt|;
return|return
operator|(
name|Lst_Append
argument_list|(
name|l
argument_list|,
name|end
argument_list|,
name|d
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

