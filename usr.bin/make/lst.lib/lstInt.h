begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988, 1989, 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Adam de Boor.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)lstInt.h	8.1 (Berkeley) 6/6/93  * $FreeBSD$  */
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
file|"make.h"
end_include

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
value|var = (ptype) emalloc (sizeof (*var))
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
end_endif

begin_comment
comment|/* _LSTINT_H_ */
end_comment

end_unit

