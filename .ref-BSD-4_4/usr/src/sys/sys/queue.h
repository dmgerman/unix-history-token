begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)queue.h	8.1 (Berkeley) 6/2/93  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_QUEUE_H_
end_ifndef

begin_define
define|#
directive|define
name|_QUEUE_H_
end_define

begin_comment
comment|/*  * This file defines two types of data structures, lists and queues.  *  * A list is headed by a single forward pointer (or an array of forward  * pointers for a hash table header). The elements are doubly linked  * so that an arbitrary element can be removed without a need to  * traverse the list. New elements can be added to the list after  * an existing element or at the head of the list.  *  * A queue is headed by a pair of pointers, one to the head of the list  * and the other to the tail of the list. The elements are doubly linked  * so that an arbitrary element can be removed without a need to  * traverse the list. New elements can be added to the list after  * an existing element, at the head of the list, or at the end of  * the list.  *  * Note that the implementation used here avoids the need to special  * case inserting into an empty list, deleting the last element from  * a list, or inserting at the beginning or end of a list. The drawback  * to this method is that it is not possible to traverse a list or  * queue backwards.  */
end_comment

begin_struct
struct|struct
name|queue_entry
block|{
name|void
modifier|*
name|qe_next
decl_stmt|;
comment|/* next element */
name|void
modifier|*
modifier|*
name|qe_prev
decl_stmt|;
comment|/* address of previous next element */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|list_entry
block|{
name|void
modifier|*
name|le_next
decl_stmt|;
comment|/* next element */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Value for pointers on removed entries.  */
end_comment

begin_define
define|#
directive|define
name|NOLIST
value|(void *)0xdead
end_define

begin_comment
comment|/*  * Queue functions.  */
end_comment

begin_define
define|#
directive|define
name|queue_init
parameter_list|(
name|head
parameter_list|)
value|{ \ 	(head)->qe_next = 0; \ 	(head)->qe_prev =&(head)->qe_next; \ }
end_define

begin_define
define|#
directive|define
name|queue_enter_tail
parameter_list|(
name|head
parameter_list|,
name|elm
parameter_list|,
name|type
parameter_list|,
name|field
parameter_list|)
value|{ \ 	(elm)->field.qe_next = 0; \ 	(elm)->field.qe_prev = (head)->qe_prev; \ 	*(head)->qe_prev = (elm); \ 	(head)->qe_prev =&(elm)->field.qe_next; \ }
end_define

begin_define
define|#
directive|define
name|queue_enter_head
parameter_list|(
name|head
parameter_list|,
name|elm
parameter_list|,
name|type
parameter_list|,
name|field
parameter_list|)
value|{ \ 	type queue_ptr; \ 	if (queue_ptr = (head)->qe_next) \ 		queue_ptr->field.qe_prev =&(elm)->field.qe_next; \ 	else \ 		(head)->qe_prev =&(elm)->field.qe_next; \ 	(head)->qe_next = (elm); \ 	(elm)->field.qe_next = queue_ptr; \ 	(elm)->field.qe_prev =&(head)->qe_next; \ }
end_define

begin_define
define|#
directive|define
name|queue_insert_after
parameter_list|(
name|head
parameter_list|,
name|listelm
parameter_list|,
name|elm
parameter_list|,
name|type
parameter_list|,
name|field
parameter_list|)
value|{ \ 	type queue_ptr; \ 	if (queue_ptr = (listelm)->qe_next) \ 		queue_ptr->field.qe_prev =&(elm)->field.qe_next; \ 	else \ 		(head)->qe_prev =&(elm)->field.qe_next; \ 	(listelm)->qe_next = (elm); \ 	(elm)->field.qe_next = queue_ptr; \ 	(elm)->field.qe_prev =&(listelm)->qe_next; \ }
end_define

begin_define
define|#
directive|define
name|queue_remove
parameter_list|(
name|head
parameter_list|,
name|elm
parameter_list|,
name|type
parameter_list|,
name|field
parameter_list|)
value|{ \ 	type queue_ptr; \ 	if (queue_ptr = (elm)->field.qe_next) \ 		queue_ptr->field.qe_prev = (elm)->field.qe_prev; \ 	else \ 		(head)->qe_prev = (elm)->field.qe_prev; \ 	*(elm)->field.qe_prev = queue_ptr; \ 	(elm)->field.qe_next = NOLIST; \ 	(elm)->field.qe_prev = NOLIST; \ }
end_define

begin_comment
comment|/*  * List functions.  */
end_comment

begin_define
define|#
directive|define
name|list_enter_head
parameter_list|(
name|head
parameter_list|,
name|elm
parameter_list|,
name|type
parameter_list|,
name|field
parameter_list|)
value|{ \ 	type queue_ptr; \ 	if (queue_ptr = (head)->le_next) \ 		queue_ptr->field.qe_prev =&(elm)->field.qe_next; \ 	(head)->le_next = (elm); \ 	(elm)->field.qe_next = queue_ptr; \ 	(elm)->field.qe_prev =&(head)->le_next; \ }
end_define

begin_define
define|#
directive|define
name|list_insert_after
parameter_list|(
name|listelm
parameter_list|,
name|elm
parameter_list|,
name|type
parameter_list|,
name|field
parameter_list|)
value|{ \ 	type queue_ptr; \ 	if (queue_ptr = (listelm)->qe_next) \ 		queue_ptr->field.qe_prev =&(elm)->field.qe_next; \ 	(listelm)->qe_next = (elm); \ 	(elm)->field.qe_next = queue_ptr; \ 	(elm)->field.qe_prev =&(listelm)->qe_next; \ }
end_define

begin_define
define|#
directive|define
name|list_remove
parameter_list|(
name|elm
parameter_list|,
name|type
parameter_list|,
name|field
parameter_list|)
value|{ \ 	type queue_ptr; \ 	if (queue_ptr = (elm)->field.qe_next) \ 		queue_ptr->field.qe_prev = (elm)->field.qe_prev; \ 	*(elm)->field.qe_prev = queue_ptr; \ 	(elm)->field.qe_next = NOLIST; \ 	(elm)->field.qe_prev = NOLIST; \ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_QUEUE_H_ */
end_comment

end_unit

