begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988, 1989, 1990 The Regents of the University of California.  * Copyright (c) 1988, 1989 by Adam de Boor  * Copyright (c) 1989 by Berkeley Softworks  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Adam de Boor.  *  * Redistribution and use in source and binary forms are permitted  * provided that: (1) source distributions retain this entire copyright  * notice and comment, and (2) distributions including binaries display  * the following acknowledgement:  ``This product includes software  * developed by the University of California, Berkeley and its contributors''  * in the documentation or other materials provided with the distribution  * and in all advertising materials mentioning features or use of this  * software. Neither the name of the University nor the names of its  * contributors may be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
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
literal|"@(#)list.c	5.4 (Berkeley) 6/1/90"
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
comment|/* list.c -  *  * This file contains procedures for manipulating lists.  * Structures may be inserted into or deleted from lists, and  * they may be moved from one place in a list to another.  *  * The header file contains macros to help in determining the destination  * locations for List_Insert and List_Move.  See list.h for details.  */
end_comment

begin_include
include|#
directive|include
file|"sprite.h"
end_include

begin_include
include|#
directive|include
file|"list.h"
end_include

begin_escape
end_escape

begin_comment
comment|/*  * ----------------------------------------------------------------------------  *  * List_Insert --  *  *	Insert the list element pointed to by itemPtr into a List after   *	destPtr.  Perform a primitive test for self-looping by returning  *	failure if the list element is being inserted next to itself.  *  * Results:  *	None.  *  * Side effects:  *	The list containing destPtr is modified to contain itemPtr.  *  * ----------------------------------------------------------------------------  */
end_comment

begin_function
name|void
name|List_Insert
parameter_list|(
name|itemPtr
parameter_list|,
name|destPtr
parameter_list|)
specifier|register
name|List_Links
modifier|*
name|itemPtr
decl_stmt|;
comment|/* structure to insert */
specifier|register
name|List_Links
modifier|*
name|destPtr
decl_stmt|;
comment|/* structure after which to insert it */
block|{
if|if
condition|(
name|itemPtr
operator|==
operator|(
name|List_Links
operator|*
operator|)
name|NIL
operator|||
name|destPtr
operator|==
operator|(
name|List_Links
operator|*
operator|)
name|NIL
operator|||
operator|!
name|itemPtr
operator|||
operator|!
name|destPtr
operator|||
operator|(
name|itemPtr
operator|==
name|destPtr
operator|)
condition|)
block|{
name|Punt
argument_list|(
literal|"List_Insert: inserting this item would create a loop.\n"
argument_list|)
expr_stmt|;
return|return;
block|}
name|itemPtr
operator|->
name|nextPtr
operator|=
name|destPtr
operator|->
name|nextPtr
expr_stmt|;
name|itemPtr
operator|->
name|prevPtr
operator|=
name|destPtr
expr_stmt|;
name|destPtr
operator|->
name|nextPtr
operator|->
name|prevPtr
operator|=
name|itemPtr
expr_stmt|;
name|destPtr
operator|->
name|nextPtr
operator|=
name|itemPtr
expr_stmt|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/*  * ----------------------------------------------------------------------------  *  * List_Remove --  *  *	Remove a list element from the list in which it is contained.  *  * Results:  *	None.  *  * Side effects:  *	The given structure is removed from its containing list.  *  * ----------------------------------------------------------------------------  */
end_comment

begin_function
name|void
name|List_Remove
parameter_list|(
name|itemPtr
parameter_list|)
specifier|register
name|List_Links
modifier|*
name|itemPtr
decl_stmt|;
comment|/* list element to remove */
block|{
if|if
condition|(
name|itemPtr
operator|==
operator|(
name|List_Links
operator|*
operator|)
name|NIL
operator|||
name|itemPtr
operator|==
name|itemPtr
operator|->
name|nextPtr
operator|||
operator|!
name|itemPtr
condition|)
block|{
name|Punt
argument_list|(
literal|"List_Remove: invalid item to remove.\n"
argument_list|)
expr_stmt|;
block|}
name|itemPtr
operator|->
name|prevPtr
operator|->
name|nextPtr
operator|=
name|itemPtr
operator|->
name|nextPtr
expr_stmt|;
name|itemPtr
operator|->
name|nextPtr
operator|->
name|prevPtr
operator|=
name|itemPtr
operator|->
name|prevPtr
expr_stmt|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/*  * ----------------------------------------------------------------------------  *  * List_Move --  *  *	Move the list element referenced by itemPtr to follow destPtr.  *  * Results:  *	None.  *  * Side effects:  *	List ordering is modified.  *  * ----------------------------------------------------------------------------  */
end_comment

begin_function
name|void
name|List_Move
parameter_list|(
name|itemPtr
parameter_list|,
name|destPtr
parameter_list|)
specifier|register
name|List_Links
modifier|*
name|itemPtr
decl_stmt|;
comment|/* list element to be moved */
specifier|register
name|List_Links
modifier|*
name|destPtr
decl_stmt|;
comment|/* element after which it is to be placed */
block|{
if|if
condition|(
name|itemPtr
operator|==
operator|(
name|List_Links
operator|*
operator|)
name|NIL
operator|||
name|destPtr
operator|==
operator|(
name|List_Links
operator|*
operator|)
name|NIL
operator|||
operator|!
name|itemPtr
operator|||
operator|!
name|destPtr
condition|)
block|{
name|Punt
argument_list|(
literal|"List_Move: One of the list items is NIL.\n"
argument_list|)
expr_stmt|;
block|}
comment|/*      * It is conceivable that someone will try to move a list element to      * be after itself.      */
if|if
condition|(
name|itemPtr
operator|!=
name|destPtr
condition|)
block|{
name|List_Remove
argument_list|(
name|itemPtr
argument_list|)
expr_stmt|;
name|List_Insert
argument_list|(
name|itemPtr
argument_list|,
name|destPtr
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/*  * ----------------------------------------------------------------------------  *  * List_Init --  *  *	Initialize a header pointer to point to an empty list.  The List_Links  *	structure must already be allocated.  *  * Results:  *	None.  *  * Side effects:  *	The header's pointers are modified to point to itself.  *  * ----------------------------------------------------------------------------  */
end_comment

begin_function
name|void
name|List_Init
parameter_list|(
name|headerPtr
parameter_list|)
specifier|register
name|List_Links
modifier|*
name|headerPtr
decl_stmt|;
comment|/* Pointer to a List_Links structure  					to be header */
block|{
if|if
condition|(
name|headerPtr
operator|==
operator|(
name|List_Links
operator|*
operator|)
name|NIL
operator|||
operator|!
name|headerPtr
condition|)
block|{
name|Punt
argument_list|(
literal|"List_Init: invalid header pointer.\n"
argument_list|)
expr_stmt|;
block|}
name|headerPtr
operator|->
name|nextPtr
operator|=
name|headerPtr
expr_stmt|;
name|headerPtr
operator|->
name|prevPtr
operator|=
name|headerPtr
expr_stmt|;
block|}
end_function

end_unit

