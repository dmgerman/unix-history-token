begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988, 1989, 1990 The Regents of the University of California.  * Copyright (c) 1988, 1989 by Adam de Boor  * Copyright (c) 1989 by Berkeley Softworks  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Adam de Boor.  *  * %sccs.include.redist.c%  *  *	@(#)lst.h	5.3 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*-  * lst.h --  *	Header for using the list library  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LST_H_
end_ifndef

begin_define
define|#
directive|define
name|_LST_H_
end_define

begin_include
include|#
directive|include
file|<sprite.h>
end_include

begin_comment
comment|/*  * basic typedef. This is what the Lst_ functions handle  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|Lst
modifier|*
name|Lst
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|LstNode
modifier|*
name|LstNode
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NILLST
value|((Lst) NIL)
end_define

begin_define
define|#
directive|define
name|NILLNODE
value|((LstNode) NIL)
end_define

begin_comment
comment|/*  * NOFREE can be used as the freeProc to Lst_Destroy when the elements are  *	not to be freed.  * NOCOPY performs similarly when given as the copyProc to Lst_Duplicate.  */
end_comment

begin_define
define|#
directive|define
name|NOFREE
value|((void (*)()) 0)
end_define

begin_define
define|#
directive|define
name|NOCOPY
value|((ClientData (*)()) 0)
end_define

begin_define
define|#
directive|define
name|LST_CONCNEW
value|0
end_define

begin_comment
comment|/* create new LstNode's when using Lst_Concat */
end_comment

begin_define
define|#
directive|define
name|LST_CONCLINK
value|1
end_define

begin_comment
comment|/* relink LstNode's when using Lst_Concat */
end_comment

begin_comment
comment|/*  * Creation/destruction functions  */
end_comment

begin_function_decl
name|Lst
name|Lst_Init
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Create a new list */
end_comment

begin_function_decl
name|Lst
name|Lst_Duplicate
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Duplicate an existing list */
end_comment

begin_function_decl
name|void
name|Lst_Destroy
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Destroy an old one */
end_comment

begin_function_decl
name|int
name|Lst_Length
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Find the length of a list */
end_comment

begin_function_decl
name|Boolean
name|Lst_IsEmpty
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* True if list is empty */
end_comment

begin_comment
comment|/*  * Functions to modify a list  */
end_comment

begin_function_decl
name|ReturnStatus
name|Lst_Insert
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Insert an element before another */
end_comment

begin_function_decl
name|ReturnStatus
name|Lst_Append
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Insert an element after another */
end_comment

begin_function_decl
name|ReturnStatus
name|Lst_AtFront
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Place an element at the front of 					 * a lst. */
end_comment

begin_function_decl
name|ReturnStatus
name|Lst_AtEnd
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Place an element at the end of a 					 * lst. */
end_comment

begin_function_decl
name|ReturnStatus
name|Lst_Remove
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Remove an element */
end_comment

begin_function_decl
name|ReturnStatus
name|Lst_Replace
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Replace a node with a new value */
end_comment

begin_function_decl
name|ReturnStatus
name|Lst_Move
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Move an element to another place */
end_comment

begin_function_decl
name|ReturnStatus
name|Lst_Concat
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Concatenate two lists */
end_comment

begin_comment
comment|/*  * Node-specific functions  */
end_comment

begin_function_decl
name|LstNode
name|Lst_First
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Return first element in list */
end_comment

begin_function_decl
name|LstNode
name|Lst_Last
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Return last element in list */
end_comment

begin_function_decl
name|LstNode
name|Lst_Succ
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Return successor to given element */
end_comment

begin_function_decl
name|LstNode
name|Lst_Pred
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Return predecessor to given 					 * element */
end_comment

begin_function_decl
name|ClientData
name|Lst_Datum
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Get datum from LstNode */
end_comment

begin_comment
comment|/*  * Functions for entire lists  */
end_comment

begin_function_decl
name|LstNode
name|Lst_Find
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Find an element in a list */
end_comment

begin_function_decl
name|LstNode
name|Lst_FindFrom
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Find an element starting from 					 * somewhere */
end_comment

begin_function_decl
name|LstNode
name|Lst_Member
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* See if the given datum is on the 					 * list. Returns the LstNode containing 					 * the datum */
end_comment

begin_function_decl
name|int
name|Lst_Index
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Returns the index of a datum in the 					 * list, starting from 0 */
end_comment

begin_function_decl
name|void
name|Lst_ForEach
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Apply a function to all elements of 					 * a lst */
end_comment

begin_function_decl
name|void
name|Lst_ForEachFrom
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Apply a function to all elements of 					 * a lst starting from a certain point. 					 * If the list is circular, the 					 * application will wrap around to the 					 * beginning of the list again. */
end_comment

begin_comment
comment|/*  * these functions are for dealing with a list as a table, of sorts.  * An idea of the "current element" is kept and used by all the functions  * between Lst_Open() and Lst_Close().  */
end_comment

begin_function_decl
name|ReturnStatus
name|Lst_Open
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Open the list */
end_comment

begin_function_decl
name|LstNode
name|Lst_Prev
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Previous element */
end_comment

begin_function_decl
name|LstNode
name|Lst_Cur
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* The current element, please */
end_comment

begin_function_decl
name|LstNode
name|Lst_Next
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Next element please */
end_comment

begin_function_decl
name|Boolean
name|Lst_IsAtEnd
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Done yet? */
end_comment

begin_function_decl
name|void
name|Lst_Close
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Finish table access */
end_comment

begin_comment
comment|/*  * for using the list as a queue  */
end_comment

begin_function_decl
name|ReturnStatus
name|Lst_EnQueue
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Place an element at tail of queue */
end_comment

begin_function_decl
name|ClientData
name|Lst_DeQueue
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Remove an element from head of 					 * queue */
end_comment

begin_endif
endif|#
directive|endif
endif|_LST_H_
end_endif

end_unit

