begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988, 1989, 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Adam de Boor.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)lstInit.c	8.1 (Berkeley) %G%"
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
comment|/*-  * init.c --  *	Initialize a new linked list.  */
end_comment

begin_include
include|#
directive|include
file|"lstInt.h"
end_include

begin_comment
comment|/*-  *-----------------------------------------------------------------------  * Lst_Init --  *	Create and initialize a new list.  *  * Results:  *	The created list.  *  * Side Effects:  *	A list is created, what else?  *  *-----------------------------------------------------------------------  */
end_comment

begin_function
name|Lst
name|Lst_Init
parameter_list|(
name|circ
parameter_list|)
name|Boolean
name|circ
decl_stmt|;
comment|/* TRUE if the list should be made circular */
block|{
specifier|register
name|List
name|nList
decl_stmt|;
name|PAlloc
argument_list|(
name|nList
argument_list|,
name|List
argument_list|)
expr_stmt|;
name|nList
operator|->
name|firstPtr
operator|=
name|NilListNode
expr_stmt|;
name|nList
operator|->
name|lastPtr
operator|=
name|NilListNode
expr_stmt|;
name|nList
operator|->
name|isOpen
operator|=
name|FALSE
expr_stmt|;
name|nList
operator|->
name|isCirc
operator|=
name|circ
expr_stmt|;
name|nList
operator|->
name|atEnd
operator|=
name|Unknown
expr_stmt|;
return|return
operator|(
operator|(
name|Lst
operator|)
name|nList
operator|)
return|;
block|}
end_function

end_unit

