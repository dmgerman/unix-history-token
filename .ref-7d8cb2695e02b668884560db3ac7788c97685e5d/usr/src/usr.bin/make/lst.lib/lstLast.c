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
literal|"@(#)lstLast.c	5.3 (Berkeley) %G%"
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
comment|/*-  * LstLast.c --  *	Return the last element of a list  */
end_comment

begin_include
include|#
directive|include
file|"lstInt.h"
end_include

begin_comment
comment|/*-  *-----------------------------------------------------------------------  * Lst_Last --  *	Return the last node on the list l.  *  * Results:  *	The requested node or NILLNODE if the list is empty.  *  * Side Effects:  *	None.  *  *-----------------------------------------------------------------------  */
end_comment

begin_function
name|LstNode
name|Lst_Last
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
name|lastPtr
operator|)
return|;
block|}
block|}
end_function

end_unit

