begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * init.c --  *	Initialize a new linked list.  *  * Copyright (c) 1988 by University of California Regents  *  * Permission to use, copy, modify, and distribute this  * software and its documentation for any purpose and without  * fee is hereby granted, provided that the above copyright  * notice appears in all copies.  Neither the University of California nor  * Adam de Boor makes any representations about the suitability of this  * software for any purpose.  It is provided "as is" without  * express or implied warranty.  */
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
literal|"$Id: lstInit.c,v 1.7 88/11/17 20:52:57 adam Exp $ SPRITE (Berkeley)"
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

begin_macro
name|Malloc
argument_list|(
argument|nbytes
argument_list|)
end_macro

begin_block
block|{
ifdef|#
directive|ifdef
name|DEBUG
name|printf
argument_list|(
literal|"malloc: %d\n"
argument_list|,
name|nbytes
argument_list|)
expr_stmt|;
endif|#
directive|endif
endif|DEBUG
return|return
operator|(
name|malloc
argument_list|(
name|nbytes
argument_list|)
operator|)
return|;
block|}
end_block

end_unit

