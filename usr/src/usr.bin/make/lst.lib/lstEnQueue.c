begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * LstEnQueue.c--  *	Treat the list as a queue and place a datum at its end  *  * Copyright (c) 1988 by University of California Regents  *  * Permission to use, copy, modify, and distribute this  * software and its documentation for any purpose and without  * fee is hereby granted, provided that the above copyright  * notice appears in all copies.  Neither the University of California nor  * Adam de Boor makes any representations about the suitability of this  * software for any purpose.  It is provided "as is" without  * express or implied warranty.  */
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
literal|"$Id: lstEnQueue.c,v 1.4 88/11/17 20:52:26 adam Exp $ SPRITE (Berkeley)"
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
comment|/*-  *-----------------------------------------------------------------------  * Lst_EnQueue --  *	Add the datum to the tail of the given list.  *  * Results:  *	SUCCESS or FAILURE as returned by Lst_Append.  *  * Side Effects:  *	the lastPtr field is altered all the time and the firstPtr field  *	will be altered if the list used to be empty.  *  *-----------------------------------------------------------------------  */
end_comment

begin_function
name|ReturnStatus
name|Lst_EnQueue
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
return|return
operator|(
name|Lst_Append
argument_list|(
name|l
argument_list|,
name|Lst_Last
argument_list|(
name|l
argument_list|)
argument_list|,
name|d
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

