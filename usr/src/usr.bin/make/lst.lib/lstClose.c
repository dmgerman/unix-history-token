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
literal|"@(#)lstClose.c	8.2 (Berkeley) %G%"
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
comment|/*-  * LstClose.c --  *	Close a list for sequential access.  *	The sequential functions access the list in a slightly different way.  *	CurPtr points to their idea of the current node in the list and they  *	access the list based on it. Because the list is circular, Lst_Next  *	and Lst_Prev will go around the list forever. Lst_IsAtEnd must be  *	used to determine when to stop.  */
end_comment

begin_include
include|#
directive|include
file|"lstInt.h"
end_include

begin_comment
comment|/*-  *-----------------------------------------------------------------------  * Lst_Close --  *	Close a list which was opened for sequential access.  *  * Results:  *	None.  *  * Side Effects:  *	The list is closed.  *  *-----------------------------------------------------------------------  */
end_comment

begin_function
name|void
name|Lst_Close
parameter_list|(
name|l
parameter_list|)
name|Lst
name|l
decl_stmt|;
comment|/* The list to close */
block|{
specifier|register
name|List
name|list
init|=
operator|(
name|List
operator|)
name|l
decl_stmt|;
if|if
condition|(
name|LstValid
argument_list|(
name|l
argument_list|)
operator|==
name|TRUE
condition|)
block|{
name|list
operator|->
name|isOpen
operator|=
name|FALSE
expr_stmt|;
name|list
operator|->
name|atEnd
operator|=
name|Unknown
expr_stmt|;
block|}
block|}
end_function

end_unit

