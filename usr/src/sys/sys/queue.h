begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * Copyright (c) 1991 Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * The Mach Operating System project at Carnegie-Mellon University.  *  * %sccs.include.redist.c%  *  *	@(#)queue.h	7.4 (Berkeley) %G%  *  *  * Copyright (c) 1987, 1990 Carnegie-Mellon University.  * All rights reserved.  *  * Author: Avadis Tevanian, Jr.  *   * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *   * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"   * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND   * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *   * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
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
name|next
decl_stmt|;
comment|/* next element */
name|void
modifier|*
modifier|*
name|prev
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
name|next
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
value|((head)->next = 0, (head)->prev =&(head)->next)
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
value|{ \ 	(elm)->field.next = 0; \ 	(elm)->field.prev = (head)->prev; \ 	*(head)->prev = (elm); \ 	(head)->prev =&(elm)->field.next; \ }
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
value|{ \ 	type queue_ptr; \ 	if (queue_ptr = (head)->next) \ 		queue_ptr->field.prev =&(elm)->field.next; \ 	else \ 		(head)->prev =&(elm)->field.next; \ 	(head)->next = (elm); \ 	(elm)->field.next = queue_ptr; \ 	(elm)->field.prev =&(head)->next; \ }
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
value|{ \ 	type queue_ptr; \ 	if (queue_ptr = (listelm)->next) \ 		queue_ptr->field.prev =&(elm)->field.next; \ 	else \ 		(head)->prev =&(elm)->field.next; \ 	(listelm)->next = (elm); \ 	(elm)->field.next = queue_ptr; \ 	(elm)->field.prev =&(listelm)->next; \ }
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
value|{ \ 	type queue_ptr; \ 	if (queue_ptr = (elm)->field.next) \ 		queue_ptr->field.prev = (elm)->field.prev; \ 	else \ 		(head)->prev = (elm)->field.prev; \ 	*(elm)->field.prev = queue_ptr; \ 	(elm)->field.next = NOLIST; \ 	(elm)->field.prev = NOLIST; \ }
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
value|{ \ 	type queue_ptr; \ 	if (queue_ptr = (head)->next) \ 		queue_ptr->field.prev =&(elm)->field.next; \ 	(head)->next = (elm); \ 	(elm)->field.next = queue_ptr; \ 	(elm)->field.prev =&(head)->next; \ }
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
value|{ \ 	type queue_ptr; \ 	if (queue_ptr = (listelm)->next) \ 		queue_ptr->field.prev =&(elm)->field.next; \ 	(listelm)->next = (elm); \ 	(elm)->field.next = queue_ptr; \ 	(elm)->field.prev =&(listelm)->next; \ }
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
value|{ \ 	type queue_ptr; \ 	if (queue_ptr = (elm)->field.next) \ 		queue_ptr->field.prev = (elm)->field.prev; \ 	*(elm)->field.prev = queue_ptr; \ 	(elm)->field.next = NOLIST; \ 	(elm)->field.prev = NOLIST; \ }
end_define

begin_comment
comment|/*  * Compatibility with old MACH VM code.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|queue_entry
modifier|*
name|queue_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|queue_entry
name|queue_head_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|queue_entry
name|queue_chain_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|queue_entry
modifier|*
name|queue_entry_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|queue_first
parameter_list|(
name|head
parameter_list|)
value|((head)->next)
end_define

begin_define
define|#
directive|define
name|queue_next
parameter_list|(
name|elm
parameter_list|)
value|((elm)->next)
end_define

begin_define
define|#
directive|define
name|queue_empty
parameter_list|(
name|head
parameter_list|)
value|((head)->next == 0)
end_define

begin_define
define|#
directive|define
name|queue_end
parameter_list|(
name|elm
parameter_list|,
name|head
parameter_list|)
value|((elm) == 0)
end_define

begin_define
define|#
directive|define
name|queue_enter
parameter_list|(
name|head
parameter_list|,
name|elt
parameter_list|,
name|type
parameter_list|,
name|field
parameter_list|)
define|\
value|queue_enter_tail(head, elt, type, field)
end_define

begin_define
define|#
directive|define
name|queue_remove_first
parameter_list|(
name|head
parameter_list|,
name|elt
parameter_list|,
name|type
parameter_list|,
name|field
parameter_list|)
value|{ \ 	elt = queue_first(head); \ 	queue_remove(head, elt, type, field) \ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_QUEUE_H_ */
end_comment

end_unit

