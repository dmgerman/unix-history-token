begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * LstIsEmpty.c --  *	A single function to decide if a list is empty  *  * Copyright (c) 1988 by University of California Regents  *  * Permission to use, copy, modify, and distribute this  * software and its documentation for any purpose and without  * fee is hereby granted, provided that the above copyright  * notice appears in all copies.  Neither the University of California nor  * Adam de Boor makes any representations about the suitability of this  * software for any purpose.  It is provided "as is" without  * express or implied warranty.  */
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
literal|"$Id: lstIsEmpty.c,v 1.5 88/11/17 20:53:19 adam Exp $ SPRITE (Berkeley)"
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
comment|/*-  *-----------------------------------------------------------------------  * Lst_IsEmpty --  *	Return TRUE if the given list is empty.  *  * Results:  *	TRUE if the list is empty, FALSE otherwise.  *  * Side Effects:  *	None.  *  *	A list is considered empty if its firstPtr == NilListNode (or if  *	the list itself is NILLIST).  *-----------------------------------------------------------------------  */
end_comment

begin_function
name|Boolean
name|Lst_IsEmpty
parameter_list|(
name|l
parameter_list|)
name|Lst
name|l
decl_stmt|;
block|{
return|return
operator|(
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
operator|)
return|;
block|}
end_function

end_unit

