begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * LstFirst.c --  *	Return the first node of a list  *  * Copyright (c) 1988 by University of California Regents  *  * Permission to use, copy, modify, and distribute this  * software and its documentation for any purpose and without  * fee is hereby granted, provided that the above copyright  * notice appears in all copies.  Neither the University of California nor  * Adam de Boor makes any representations about the suitability of this  * software for any purpose.  It is provided "as is" without  * express or implied warranty.  */
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
literal|"$Id: lstFirst.c,v 1.5 88/11/17 20:52:44 adam Exp $ SPRITE (Berkeley)"
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
comment|/*-  *-----------------------------------------------------------------------  * Lst_First --  *	Return the first node on the given list.  *  * Results:  *	The first node or NILLNODE if the list is empty.  *  * Side Effects:  *	None.  *  *-----------------------------------------------------------------------  */
end_comment

begin_function
name|LstNode
name|Lst_First
parameter_list|(
name|l
parameter_list|)
name|Lst
name|l
decl_stmt|;
block|{
if|if
condition|(
operator|!
name|LstValid
argument_list|(
name|l
argument_list|)
operator|||
name|LstIsEmpty
argument_list|(
name|l
argument_list|)
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
name|List
operator|)
name|l
argument_list|)
operator|->
name|firstPtr
operator|)
return|;
block|}
block|}
end_function

end_unit

