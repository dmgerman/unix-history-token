begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988, 1989, 1990 The Regents of the University of California.  * Copyright (c) 1988, 1989 by Adam de Boor  * Copyright (c) 1989 by Berkeley Softworks  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Adam de Boor.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)lst.h	8.1 (Berkeley) 6/6/93  * $FreeBSD$  */
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

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"sprite.h"
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
value|((void (*) __P((ClientData))) 0)
end_define

begin_define
define|#
directive|define
name|NOCOPY
value|((ClientData (*) __P((ClientData))) 0)
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

begin_decl_stmt
name|Lst
name|Lst_Init
name|__P
argument_list|(
operator|(
name|Boolean
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Duplicate an existing list */
end_comment

begin_decl_stmt
name|Lst
name|Lst_Duplicate
name|__P
argument_list|(
operator|(
name|Lst
operator|,
name|ClientData
argument_list|(
operator|*
argument_list|)
argument_list|(
name|ClientData
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Destroy an old one */
end_comment

begin_decl_stmt
name|void
name|Lst_Destroy
name|__P
argument_list|(
operator|(
name|Lst
operator|,
name|void
argument_list|(
operator|*
argument_list|)
argument_list|(
name|ClientData
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* True if list is empty */
end_comment

begin_decl_stmt
name|Boolean
name|Lst_IsEmpty
name|__P
argument_list|(
operator|(
name|Lst
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Functions to modify a list  */
end_comment

begin_comment
comment|/* Insert an element before another */
end_comment

begin_decl_stmt
name|ReturnStatus
name|Lst_Insert
name|__P
argument_list|(
operator|(
name|Lst
operator|,
name|LstNode
operator|,
name|ClientData
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Insert an element after another */
end_comment

begin_decl_stmt
name|ReturnStatus
name|Lst_Append
name|__P
argument_list|(
operator|(
name|Lst
operator|,
name|LstNode
operator|,
name|ClientData
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Place an element at the front of a lst. */
end_comment

begin_decl_stmt
name|ReturnStatus
name|Lst_AtFront
name|__P
argument_list|(
operator|(
name|Lst
operator|,
name|ClientData
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Place an element at the end of a lst. */
end_comment

begin_decl_stmt
name|ReturnStatus
name|Lst_AtEnd
name|__P
argument_list|(
operator|(
name|Lst
operator|,
name|ClientData
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Remove an element */
end_comment

begin_decl_stmt
name|ReturnStatus
name|Lst_Remove
name|__P
argument_list|(
operator|(
name|Lst
operator|,
name|LstNode
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Replace a node with a new value */
end_comment

begin_decl_stmt
name|ReturnStatus
name|Lst_Replace
name|__P
argument_list|(
operator|(
name|LstNode
operator|,
name|ClientData
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Concatenate two lists */
end_comment

begin_decl_stmt
name|ReturnStatus
name|Lst_Concat
name|__P
argument_list|(
operator|(
name|Lst
operator|,
name|Lst
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Node-specific functions  */
end_comment

begin_comment
comment|/* Return first element in list */
end_comment

begin_decl_stmt
name|LstNode
name|Lst_First
name|__P
argument_list|(
operator|(
name|Lst
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Return last element in list */
end_comment

begin_decl_stmt
name|LstNode
name|Lst_Last
name|__P
argument_list|(
operator|(
name|Lst
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Return successor to given element */
end_comment

begin_decl_stmt
name|LstNode
name|Lst_Succ
name|__P
argument_list|(
operator|(
name|LstNode
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Get datum from LstNode */
end_comment

begin_decl_stmt
name|ClientData
name|Lst_Datum
name|__P
argument_list|(
operator|(
name|LstNode
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Functions for entire lists  */
end_comment

begin_comment
comment|/* Find an element in a list */
end_comment

begin_decl_stmt
name|LstNode
name|Lst_Find
name|__P
argument_list|(
operator|(
name|Lst
operator|,
name|ClientData
operator|,
name|int
argument_list|(
operator|*
argument_list|)
argument_list|(
name|ClientData
argument_list|,
name|ClientData
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Find an element starting from somewhere */
end_comment

begin_decl_stmt
name|LstNode
name|Lst_FindFrom
name|__P
argument_list|(
operator|(
name|Lst
operator|,
name|LstNode
operator|,
name|ClientData
operator|,
name|int
argument_list|(
operator|*
name|cProc
argument_list|)
argument_list|(
name|ClientData
argument_list|,
name|ClientData
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * See if the given datum is on the list. Returns the LstNode containing  * the datum  */
end_comment

begin_decl_stmt
name|LstNode
name|Lst_Member
name|__P
argument_list|(
operator|(
name|Lst
operator|,
name|ClientData
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Apply a function to all elements of a lst */
end_comment

begin_decl_stmt
name|void
name|Lst_ForEach
name|__P
argument_list|(
operator|(
name|Lst
operator|,
name|int
argument_list|(
operator|*
argument_list|)
argument_list|(
name|ClientData
argument_list|,
name|ClientData
argument_list|)
operator|,
name|ClientData
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Apply a function to all elements of a lst starting from a certain point.  * If the list is circular, the application will wrap around to the  * beginning of the list again.  */
end_comment

begin_decl_stmt
name|void
name|Lst_ForEachFrom
name|__P
argument_list|(
operator|(
name|Lst
operator|,
name|LstNode
operator|,
name|int
argument_list|(
operator|*
argument_list|)
argument_list|(
name|ClientData
argument_list|,
name|ClientData
argument_list|)
operator|,
name|ClientData
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * these functions are for dealing with a list as a table, of sorts.  * An idea of the "current element" is kept and used by all the functions  * between Lst_Open() and Lst_Close().  */
end_comment

begin_comment
comment|/* Open the list */
end_comment

begin_decl_stmt
name|ReturnStatus
name|Lst_Open
name|__P
argument_list|(
operator|(
name|Lst
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Next element please */
end_comment

begin_decl_stmt
name|LstNode
name|Lst_Next
name|__P
argument_list|(
operator|(
name|Lst
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Done yet? */
end_comment

begin_decl_stmt
name|Boolean
name|Lst_IsAtEnd
name|__P
argument_list|(
operator|(
name|Lst
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Finish table access */
end_comment

begin_decl_stmt
name|void
name|Lst_Close
name|__P
argument_list|(
operator|(
name|Lst
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * for using the list as a queue  */
end_comment

begin_comment
comment|/* Place an element at tail of queue */
end_comment

begin_decl_stmt
name|ReturnStatus
name|Lst_EnQueue
name|__P
argument_list|(
operator|(
name|Lst
operator|,
name|ClientData
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Remove an element from head of queue */
end_comment

begin_decl_stmt
name|ClientData
name|Lst_DeQueue
name|__P
argument_list|(
operator|(
name|Lst
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LST_H_ */
end_comment

end_unit

