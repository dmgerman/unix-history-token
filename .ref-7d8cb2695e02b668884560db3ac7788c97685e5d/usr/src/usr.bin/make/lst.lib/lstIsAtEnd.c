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
literal|"@(#)lstIsAtEnd.c	5.3 (Berkeley) %G%"
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
comment|/*-  * LstIsAtEnd.c --  *	Tell if the current node is at the end of the list.  *	The sequential functions access the list in a slightly different way.  *	CurPtr points to their idea of the current node in the list and they  *	access the list based on it. Because the list is circular, Lst_Next  *	and Lst_Prev will go around the list forever. Lst_IsAtEnd must be  *	used to determine when to stop.  */
end_comment

begin_include
include|#
directive|include
file|"lstInt.h"
end_include

begin_comment
comment|/*-  *-----------------------------------------------------------------------  * Lst_IsAtEnd --  *	Return true if have reached the end of the given list.  *  * Results:  *	TRUE if at the end of the list (this includes the list not being  *	open or being invalid) or FALSE if not. We return TRUE if the list  *	is invalid or unopend so as to cause the caller to exit its loop  *	asap, the assumption being that the loop is of the form  *	    while (!Lst_IsAtEnd (l)) {  *	    	  ...  *	    }  *  * Side Effects:  *	None.  *  *-----------------------------------------------------------------------  */
end_comment

begin_function
name|Boolean
name|Lst_IsAtEnd
parameter_list|(
name|l
parameter_list|)
name|Lst
name|l
decl_stmt|;
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
return|return
operator|(
operator|!
name|LstValid
argument_list|(
name|l
argument_list|)
operator|||
operator|!
name|list
operator|->
name|isOpen
operator|||
operator|(
name|list
operator|->
name|atEnd
operator|==
name|Head
operator|)
operator|||
operator|(
name|list
operator|->
name|atEnd
operator|==
name|Tail
operator|)
operator|)
return|;
block|}
end_function

end_unit

