begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988, 1989, 1990, 1993  *	The Regents of the University of California.  All rights reserved.  * Copyright (c) 1988, 1989 by Adam de Boor  * Copyright (c) 1989 by Berkeley Softworks  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Adam de Boor.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)lst.h	8.2 (Berkeley) 4/28/95  * $FreeBSD$  */
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
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|"sprite.h"
end_include

begin_comment
comment|/*  * Structure of a list node.  */
end_comment

begin_struct
struct|struct
name|LstNode
block|{
name|struct
name|LstNode
modifier|*
name|prevPtr
decl_stmt|;
comment|/* previous element in list */
name|struct
name|LstNode
modifier|*
name|nextPtr
decl_stmt|;
comment|/* next in list */
name|int
name|useCount
range|:
literal|8
decl_stmt|;
comment|/* Count of functions using the node. Node may not 			     * be deleted until count goes to 0 */
name|int
name|flags
range|:
literal|8
decl_stmt|;
comment|/* Node status flags */
name|void
modifier|*
name|datum
decl_stmt|;
comment|/* datum associated with this element */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|LstNode
name|LstNode
typedef|;
end_typedef

begin_comment
comment|/*  * Flags required for synchronization  */
end_comment

begin_define
define|#
directive|define
name|LN_DELETED
value|0x0001
end_define

begin_comment
comment|/* List node should be removed when done */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|LstHead
block|,
name|LstMiddle
block|,
name|LstTail
block|,
name|LstUnknown
block|}
name|LstWhere
typedef|;
end_typedef

begin_comment
comment|/*  * The list itself  */
end_comment

begin_struct
struct|struct
name|Lst
block|{
name|LstNode
modifier|*
name|firstPtr
decl_stmt|;
comment|/* first node in list */
name|LstNode
modifier|*
name|lastPtr
decl_stmt|;
comment|/* last node in list */
comment|/* 	 * fields for sequential access 	 */
name|LstWhere
name|atEnd
decl_stmt|;
comment|/* Where in the list the last access was */
name|Boolean
name|isOpen
decl_stmt|;
comment|/* true if list has been Lst_Open'ed */
name|LstNode
modifier|*
name|curPtr
decl_stmt|;
comment|/* current node, if open. NULL if 				   * *just* opened */
name|LstNode
modifier|*
name|prevPtr
decl_stmt|;
comment|/* Previous node, if open. Used by 				   * Lst_Remove */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|Lst
name|Lst
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|CompareProc
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|DoProc
parameter_list|(
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
modifier|*
name|DuplicateProc
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|FreeProc
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * NOFREE can be used as the freeProc to Lst_Destroy when the elements are  *	not to be freed.  * NOCOPY performs similarly when given as the copyProc to Lst_Duplicate.  */
end_comment

begin_define
define|#
directive|define
name|NOFREE
value|((FreeProc *)NULL)
end_define

begin_define
define|#
directive|define
name|NOCOPY
value|((DuplicateProc *)NULL)
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

begin_comment
comment|/* Create a new list */
end_comment

begin_function_decl
name|Lst
modifier|*
name|Lst_Init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Duplicate an existing list */
end_comment

begin_function_decl
name|Lst
modifier|*
name|Lst_Duplicate
parameter_list|(
name|Lst
modifier|*
parameter_list|,
name|DuplicateProc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Destroy an old one */
end_comment

begin_function_decl
name|void
name|Lst_Destroy
parameter_list|(
name|Lst
modifier|*
parameter_list|,
name|FreeProc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Functions to modify a list  */
end_comment

begin_comment
comment|/* Insert an element before another */
end_comment

begin_function_decl
name|ReturnStatus
name|Lst_Insert
parameter_list|(
name|Lst
modifier|*
parameter_list|,
name|LstNode
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Insert an element after another */
end_comment

begin_function_decl
name|ReturnStatus
name|Lst_Append
parameter_list|(
name|Lst
modifier|*
parameter_list|,
name|LstNode
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Place an element at the front of a lst. */
end_comment

begin_define
define|#
directive|define
name|Lst_AtFront
parameter_list|(
name|LST
parameter_list|,
name|D
parameter_list|)
value|(Lst_Insert((LST), Lst_First(LST), (D)))
end_define

begin_comment
comment|/* Place an element at the end of a lst. */
end_comment

begin_define
define|#
directive|define
name|Lst_AtEnd
parameter_list|(
name|LST
parameter_list|,
name|D
parameter_list|)
value|(Lst_Append((LST), Lst_Last(LST), (D)))
end_define

begin_comment
comment|/* Remove an element */
end_comment

begin_function_decl
name|ReturnStatus
name|Lst_Remove
parameter_list|(
name|Lst
modifier|*
parameter_list|,
name|LstNode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Replace a node with a new value */
end_comment

begin_define
define|#
directive|define
name|Lst_Replace
parameter_list|(
name|NODE
parameter_list|,
name|D
parameter_list|)
value|(((NODE) == NULL) ? FAILURE : \ 				    (((NODE)->datum = (D)), SUCCESS))
end_define

begin_comment
comment|/* Concatenate two lists */
end_comment

begin_function_decl
name|ReturnStatus
name|Lst_Concat
parameter_list|(
name|Lst
modifier|*
parameter_list|,
name|Lst
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Node-specific functions  */
end_comment

begin_comment
comment|/* Return first element in list */
end_comment

begin_define
define|#
directive|define
name|Lst_First
parameter_list|(
name|LST
parameter_list|)
value|((Lst_Valid(LST)&& !Lst_IsEmpty(LST)) \ 			    ? (LST)->firstPtr : NULL)
end_define

begin_comment
comment|/* Return last element in list */
end_comment

begin_define
define|#
directive|define
name|Lst_Last
parameter_list|(
name|LST
parameter_list|)
value|((Lst_Valid(LST)&& !Lst_IsEmpty(LST)) \ 			    ? (LST)->lastPtr : NULL)
end_define

begin_comment
comment|/* Return successor to given element */
end_comment

begin_define
define|#
directive|define
name|Lst_Succ
parameter_list|(
name|NODE
parameter_list|)
value|(((NODE) == NULL) ? NULL : (NODE)->nextPtr)
end_define

begin_comment
comment|/* Get datum from LstNode */
end_comment

begin_define
define|#
directive|define
name|Lst_Datum
parameter_list|(
name|NODE
parameter_list|)
value|((NODE)->datum)
end_define

begin_comment
comment|/*  * Functions for entire lists  */
end_comment

begin_comment
comment|/* Find an element in a list */
end_comment

begin_define
define|#
directive|define
name|Lst_Find
parameter_list|(
name|LST
parameter_list|,
name|D
parameter_list|,
name|FN
parameter_list|)
value|(Lst_FindFrom((LST), Lst_First(LST), (D), (FN)))
end_define

begin_comment
comment|/* Find an element starting from somewhere */
end_comment

begin_function_decl
name|LstNode
modifier|*
name|Lst_FindFrom
parameter_list|(
name|Lst
modifier|*
parameter_list|,
name|LstNode
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|CompareProc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * See if the given datum is on the list. Returns the LstNode containing  * the datum  */
end_comment

begin_function_decl
name|LstNode
modifier|*
name|Lst_Member
parameter_list|(
name|Lst
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Apply a function to all elements of a lst */
end_comment

begin_function_decl
name|void
name|Lst_ForEach
parameter_list|(
name|Lst
modifier|*
parameter_list|,
name|DoProc
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|Lst_ForEach
parameter_list|(
name|LST
parameter_list|,
name|FN
parameter_list|,
name|D
parameter_list|)
value|(Lst_ForEachFrom((LST), Lst_First(LST), \ 				    (FN), (D)))
end_define

begin_comment
comment|/*  * Apply a function to all elements of a lst starting from a certain point.  * If the list is circular, the application will wrap around to the  * beginning of the list again.  */
end_comment

begin_function_decl
name|void
name|Lst_ForEachFrom
parameter_list|(
name|Lst
modifier|*
parameter_list|,
name|LstNode
modifier|*
parameter_list|,
name|DoProc
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * these functions are for dealing with a list as a table, of sorts.  * An idea of the "current element" is kept and used by all the functions  * between Lst_Open() and Lst_Close().  */
end_comment

begin_comment
comment|/* Open the list */
end_comment

begin_function_decl
name|ReturnStatus
name|Lst_Open
parameter_list|(
name|Lst
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Next element please */
end_comment

begin_function_decl
name|LstNode
modifier|*
name|Lst_Next
parameter_list|(
name|Lst
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Done yet? */
end_comment

begin_function_decl
name|Boolean
name|Lst_IsAtEnd
parameter_list|(
name|Lst
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Finish table access */
end_comment

begin_function_decl
name|void
name|Lst_Close
parameter_list|(
name|Lst
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * for using the list as a queue  */
end_comment

begin_comment
comment|/* Place an element at tail of queue */
end_comment

begin_define
define|#
directive|define
name|Lst_EnQueue
parameter_list|(
name|LST
parameter_list|,
name|D
parameter_list|)
value|(Lst_Valid(LST) \ 				    ? Lst_Append((LST), Lst_Last(LST), (D)) \ 				    : FAILURE)
end_define

begin_comment
comment|/* Remove an element from head of queue */
end_comment

begin_function_decl
name|void
modifier|*
name|Lst_DeQueue
parameter_list|(
name|Lst
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * LstValid (L) --  *	Return TRUE if the list L is valid  */
end_comment

begin_define
define|#
directive|define
name|Lst_Valid
parameter_list|(
name|L
parameter_list|)
value|(((L) == NULL) ? FALSE : TRUE)
end_define

begin_comment
comment|/*  * LstNodeValid (LN, L) --  *	Return TRUE if the LstNode LN is valid with respect to L  */
end_comment

begin_define
define|#
directive|define
name|Lst_NodeValid
parameter_list|(
name|LN
parameter_list|,
name|L
parameter_list|)
value|(((LN) == NULL) ? FALSE : TRUE)
end_define

begin_comment
comment|/*  * Lst_IsEmpty(L) --  *	TRUE if the list L is empty.  */
end_comment

begin_define
define|#
directive|define
name|Lst_IsEmpty
parameter_list|(
name|L
parameter_list|)
value|(!Lst_Valid(L) || (L)->firstPtr == NULL)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LST_H_ */
end_comment

end_unit

