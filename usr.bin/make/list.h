begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988, 1989, 1990, 1993  *	The Regents of the University of California.  All rights reserved.  * Copyright (c) 1988, 1989 by Adam de Boor  * Copyright (c) 1989 by Berkeley Softworks  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Adam de Boor.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)list.h	8.2 (Berkeley) 4/28/95  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * list.h --  *  * Structures, macros, and routines exported by the List module.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LIST
end_ifndef

begin_define
define|#
directive|define
name|_LIST
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_SPRITE
end_ifndef

begin_include
include|#
directive|include
file|"sprite.h"
end_include

begin_endif
endif|#
directive|endif
endif|_SPRITE
end_endif

begin_comment
comment|/*  * This module defines the list abstraction, which enables one to link  * together arbitrary data structures.  Lists are doubly-linked and  * circular.  A list contains a header followed by its real members, if  * any.  (An empty list therefore consists of a single element, the  * header,  whose nextPtr and prevPtr fields point to itself).  To refer  * to a list as a whole, the user keeps a pointer to the header; that  * header is initialized by a call to List_Init(), which creates an empty  * list given a pointer to a List_Links structure (described below).  *  * The links are contained in a two-element structure called List_Links.  * A list joins List_Links records (that is, each List_Links structure  * points to other List_Links structures), but if the List_Links is the  * first field within a larger structure, then the larger structures are  * effectively linked together as follows:  *  *	      header  *	  (List_Links)		   first elt.		    second elt.  *	-----------------	-----------------	-----------------  * ..->	|    nextPtr	| ---->	|  List_Links	| ---->	|  List_Links	|----..  *	| - - - - - - -	|	|		|	|		|  * ..--	|    prevPtr	|<----	|		|<----	|		|<---..  *	-----------------	- ---  ---  ---	-	- ---  ---  ---	-  *				|    rest of	|	|    rest of	|  *				|   structure	|	|   structure	|  *				|		|	|		|  *				|      ...	|	|      ...	|  *				-----------------	-----------------  *  * It is possible to link structures through List_Links fields that are  * not at the beginning of the larger structure, but it is then necessary  * to perform pointer arithmetic to find the beginning of the larger  * structure, given a pointer to some point within it.  *  * A typical structure might be something like:  *  *      typedef struct {  *                  List_Links links;  *                  char ch;  *                  integer flags;  *      } EditChar;  *  * Before an element is inserted in a list for the first time, it must  * be initialized by calling the macro List_InitElement().  */
end_comment

begin_escape
end_escape

begin_comment
comment|/*  * data structure for lists  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|List_Links
block|{
name|struct
name|List_Links
modifier|*
name|prevPtr
decl_stmt|;
name|struct
name|List_Links
modifier|*
name|nextPtr
decl_stmt|;
block|}
name|List_Links
typedef|;
end_typedef

begin_comment
comment|/*  * procedures  */
end_comment

begin_function_decl
name|void
name|List_Init
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* initialize a header to a list */
end_comment

begin_function_decl
name|void
name|List_Insert
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* insert an element into a list */
end_comment

begin_function_decl
name|void
name|List_Remove
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* remove an element from a list */
end_comment

begin_function_decl
name|void
name|List_Move
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* move an element elsewhere in a list */
end_comment

begin_escape
end_escape

begin_comment
comment|/*  * ----------------------------------------------------------------------------  *  * List_InitElement --  *  *      Initialize a list element.  Must be called before an element is first  *	inserted into a list.  *  * ----------------------------------------------------------------------------  */
end_comment

begin_define
define|#
directive|define
name|List_InitElement
parameter_list|(
name|elementPtr
parameter_list|)
define|\
value|(elementPtr)->prevPtr = (List_Links *) NULL; \     (elementPtr)->nextPtr = (List_Links *) NULL;
end_define

begin_comment
comment|/*  * Macros for stepping through or selecting parts of lists  */
end_comment

begin_comment
comment|/*  * ----------------------------------------------------------------------------  *  * LIST_FORALL --  *  *      Macro to loop through a list and perform an operation on each member.  *  *      Usage: LIST_FORALL(headerPtr, itemPtr) {  *                 / *  *                   * operation on itemPtr, which points to successive members  *                   * of the list  *                   *  *                   * It may be appropriate to first assign  *                   *          foobarPtr = (Foobar *) itemPtr;  *                   * to refer to the entire Foobar structure.  *                   * /  *             }  *  *      Note: itemPtr must be a List_Links pointer variable, and headerPtr  *      must evaluate to a pointer to a List_Links structure.  *  * ----------------------------------------------------------------------------  */
end_comment

begin_define
define|#
directive|define
name|LIST_FORALL
parameter_list|(
name|headerPtr
parameter_list|,
name|itemPtr
parameter_list|)
define|\
value|for (itemPtr = List_First(headerPtr); \              !List_IsAtEnd((headerPtr),itemPtr); \              itemPtr = List_Next(itemPtr))
end_define

begin_comment
comment|/*  * ----------------------------------------------------------------------------  *  * List_IsEmpty --  *  *      Macro: Boolean value, TRUE if the given list does not contain any  *      members.  *  *      Usage: if (List_IsEmpty(headerPtr)) ...  *  * ----------------------------------------------------------------------------  */
end_comment

begin_define
define|#
directive|define
name|List_IsEmpty
parameter_list|(
name|headerPtr
parameter_list|)
define|\
value|((headerPtr) == (headerPtr)->nextPtr)
end_define

begin_comment
comment|/*  * ----------------------------------------------------------------------------  *  * List_IsAtEnd --  *  *      Macro: Boolean value, TRUE if itemPtr is after the end of headerPtr  *      (i.e., itemPtr is the header of the list).  *  *      Usage: if (List_IsAtEnd(headerPtr, itemPtr)) ...  *  * ----------------------------------------------------------------------------  */
end_comment

begin_define
define|#
directive|define
name|List_IsAtEnd
parameter_list|(
name|headerPtr
parameter_list|,
name|itemPtr
parameter_list|)
define|\
value|((itemPtr) == (headerPtr))
end_define

begin_escape
end_escape

begin_comment
comment|/*  * ----------------------------------------------------------------------------  *  * List_First --  *  *      Macro to return the first member in a list, which is the header if  *      the list is empty.  *  *      Usage: firstPtr = List_First(headerPtr);  *  * ----------------------------------------------------------------------------  */
end_comment

begin_define
define|#
directive|define
name|List_First
parameter_list|(
name|headerPtr
parameter_list|)
value|((headerPtr)->nextPtr)
end_define

begin_comment
comment|/*  * ----------------------------------------------------------------------------  *  * List_Last --  *  *      Macro to return the last member in a list, which is the header if  *      the list is empty.  *  *      Usage: lastPtr = List_Last(headerPtr);  *  * ----------------------------------------------------------------------------  */
end_comment

begin_define
define|#
directive|define
name|List_Last
parameter_list|(
name|headerPtr
parameter_list|)
value|((headerPtr)->prevPtr)
end_define

begin_comment
comment|/*  * ----------------------------------------------------------------------------  *  * List_Prev --  *  *      Macro to return the member preceding the given member in its list.  *      If the given list member is the first element in the list, List_Prev  *      returns the list header.  *  *      Usage: prevPtr = List_Prev(itemPtr);  *  * ----------------------------------------------------------------------------  */
end_comment

begin_define
define|#
directive|define
name|List_Prev
parameter_list|(
name|itemPtr
parameter_list|)
value|((itemPtr)->prevPtr)
end_define

begin_comment
comment|/*  * ----------------------------------------------------------------------------  *  * List_Next --  *  *      Macro to return the member following the given member in its list.  *      If the given list member is the last element in the list, List_Next  *      returns the list header.  *  *      Usage: nextPtr = List_Next(itemPtr);  *  * ----------------------------------------------------------------------------  */
end_comment

begin_define
define|#
directive|define
name|List_Next
parameter_list|(
name|itemPtr
parameter_list|)
value|((itemPtr)->nextPtr)
end_define

begin_escape
end_escape

begin_comment
comment|/*  * ----------------------------------------------------------------------------  *      The List_Insert procedure takes two arguments.  The first argument  *      is a pointer to the structure to be inserted into a list, and  *      the second argument is a pointer to the list member after which  *      the new element is to be inserted.  Macros are used to determine  *      which existing member will precede the new one.  *  *      The List_Move procedure takes a destination argument with the same  *      semantics as List_Insert.  *  *      The following macros define where to insert the new element  *      in the list:  *  *      LIST_AFTER(itemPtr)     --      insert after itemPtr  *      LIST_BEFORE(itemPtr)    --      insert before itemPtr  *      LIST_ATFRONT(headerPtr) --      insert at front of list  *      LIST_ATREAR(headerPtr)  --      insert at end of list  *  *      For example,  *  *              List_Insert(itemPtr, LIST_AFTER(otherPtr));  *  *      will insert itemPtr following otherPtr in the list containing otherPtr.  * ----------------------------------------------------------------------------  */
end_comment

begin_define
define|#
directive|define
name|LIST_AFTER
parameter_list|(
name|itemPtr
parameter_list|)
value|((List_Links *) itemPtr)
end_define

begin_define
define|#
directive|define
name|LIST_BEFORE
parameter_list|(
name|itemPtr
parameter_list|)
value|(((List_Links *) itemPtr)->prevPtr)
end_define

begin_define
define|#
directive|define
name|LIST_ATFRONT
parameter_list|(
name|headerPtr
parameter_list|)
value|((List_Links *) headerPtr)
end_define

begin_define
define|#
directive|define
name|LIST_ATREAR
parameter_list|(
name|headerPtr
parameter_list|)
value|(((List_Links *) headerPtr)->prevPtr)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LIST */
end_comment

end_unit

