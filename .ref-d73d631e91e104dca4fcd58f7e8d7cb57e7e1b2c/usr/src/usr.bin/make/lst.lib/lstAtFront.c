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
literal|"@(#)lstAtFront.c	5.3 (Berkeley) %G%"
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
comment|/*-  * LstAtFront.c --  *	Add a node at the front of the list  */
end_comment

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

