begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988, 1989, 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Adam de Boor.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)lstInt.h	5.2 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*-  * lstInt.h --  *	Internals for the list library  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LSTINT_H_
end_ifndef

begin_define
define|#
directive|define
name|_LSTINT_H_
end_define

begin_include
include|#
directive|include
file|"lst.h"
end_include

begin_typedef
typedef|typedef
struct|struct
name|ListNode
block|{
name|struct
name|ListNode
modifier|*
name|prevPtr
decl_stmt|;
comment|/* previous element in list */
name|struct
name|ListNode
modifier|*
name|nextPtr
decl_stmt|;
comment|/* next in list */
name|short
name|useCount
range|:
literal|8
decl_stmt|,
comment|/* Count of functions using the node. 				     * node may not be deleted until count 				     * goes to 0 */
name|flags
range|:
literal|8
decl_stmt|;
comment|/* Node status flags */
name|ClientData
name|datum
decl_stmt|;
comment|/* datum associated with this element */
block|}
typedef|*
name|ListNode
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

begin_define
define|#
directive|define
name|NilListNode
value|((ListNode)-1)
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|Head
block|,
name|Middle
block|,
name|Tail
block|,
name|Unknown
block|}
name|Where
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|ListNode
name|firstPtr
decl_stmt|;
comment|/* first node in list */
name|ListNode
name|lastPtr
decl_stmt|;
comment|/* last node in list */
name|Boolean
name|isCirc
decl_stmt|;
comment|/* true if the list should be considered 				   * circular */
comment|/*  * fields for sequential access  */
name|Where
name|atEnd
decl_stmt|;
comment|/* Where in the list the last access was */
name|Boolean
name|isOpen
decl_stmt|;
comment|/* true if list has been Lst_Open'ed */
name|ListNode
name|curPtr
decl_stmt|;
comment|/* current node, if open. NilListNode if 				   * *just* opened */
name|ListNode
name|prevPtr
decl_stmt|;
comment|/* Previous node, if open. Used by 				   * Lst_Remove */
block|}
typedef|*
name|List
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NilList
value|((List)-1)
end_define

begin_comment
comment|/*  * PAlloc (var, ptype) --  *	Allocate a pointer-typedef structure 'ptype' into the variable 'var'  */
end_comment

begin_define
define|#
directive|define
name|PAlloc
parameter_list|(
name|var
parameter_list|,
name|ptype
parameter_list|)
value|var = (ptype) Malloc (sizeof (*var))
end_define

begin_comment
comment|/*  * LstValid (l) --  *	Return TRUE if the list l is valid  */
end_comment

begin_define
define|#
directive|define
name|LstValid
parameter_list|(
name|l
parameter_list|)
value|(((Lst)l == NILLST) ? FALSE : TRUE)
end_define

begin_comment
comment|/*  * LstNodeValid (ln, l) --  *	Return TRUE if the LstNode ln is valid with respect to l  */
end_comment

begin_define
define|#
directive|define
name|LstNodeValid
parameter_list|(
name|ln
parameter_list|,
name|l
parameter_list|)
value|((((LstNode)ln) == NILLNODE) ? FALSE : TRUE)
end_define

begin_comment
comment|/*  * LstIsEmpty (l) --  *	TRUE if the list l is empty.  */
end_comment

begin_define
define|#
directive|define
name|LstIsEmpty
parameter_list|(
name|l
parameter_list|)
value|(((List)l)->firstPtr == NilListNode)
end_define

begin_endif
endif|#
directive|endif
endif|_LSTINT_H_
end_endif

end_unit

