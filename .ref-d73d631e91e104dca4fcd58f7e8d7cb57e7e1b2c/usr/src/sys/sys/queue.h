begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * Copyright (c) 1985, Avadis Tevanian, Jr.  * Copyright (c) 1987 Carnegie-Mellon University  * Copyright (c) 1991 Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * The Mach Operating System project at Carnegie-Mellon University.  *  * The CMU software License Agreement specifies the terms and conditions  * for use and redistribution.  *  *	@(#)queue.h	7.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  *	Type definitions for generic queues.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_QUEUE_
end_ifndef

begin_define
define|#
directive|define
name|_QUEUE_
end_define

begin_struct
struct|struct
name|queue_entry
block|{
name|struct
name|queue_entry
modifier|*
name|next
decl_stmt|;
comment|/* next element */
name|struct
name|queue_entry
modifier|*
name|prev
decl_stmt|;
comment|/* previous element */
block|}
struct|;
end_struct

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
name|round_queue
parameter_list|(
name|size
parameter_list|)
value|(((size)+7)& (~7))
end_define

begin_define
define|#
directive|define
name|enqueue
parameter_list|(
name|queue
parameter_list|,
name|elt
parameter_list|)
value|enqueue_tail(queue, elt)
end_define

begin_define
define|#
directive|define
name|dequeue
parameter_list|(
name|queue
parameter_list|)
value|dequeue_head(queue)
end_define

begin_define
define|#
directive|define
name|enqueue_head
parameter_list|(
name|queue
parameter_list|,
name|elt
parameter_list|)
value|insque(elt,queue)
end_define

begin_define
define|#
directive|define
name|enqueue_tail
parameter_list|(
name|queue
parameter_list|,
name|elt
parameter_list|)
value|insque(elt,(queue)->prev)
end_define

begin_define
define|#
directive|define
name|remqueue
parameter_list|(
name|queue
parameter_list|,
name|elt
parameter_list|)
value|remque(elt)
end_define

begin_define
define|#
directive|define
name|queue_init
parameter_list|(
name|q
parameter_list|)
value|((q)->next = (q)->prev = q)
end_define

begin_define
define|#
directive|define
name|queue_first
parameter_list|(
name|q
parameter_list|)
value|((q)->next)
end_define

begin_define
define|#
directive|define
name|queue_next
parameter_list|(
name|qc
parameter_list|)
value|((qc)->next)
end_define

begin_define
define|#
directive|define
name|queue_end
parameter_list|(
name|q
parameter_list|,
name|qe
parameter_list|)
value|((q) == (qe))
end_define

begin_define
define|#
directive|define
name|queue_empty
parameter_list|(
name|q
parameter_list|)
value|queue_end((q), queue_first(q))
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
value|{			\ 	if (queue_empty((head))) {				\ 		(head)->next = (queue_entry_t) elt;		\ 		(head)->prev = (queue_entry_t) elt;		\ 		(elt)->field.next = head;			\ 		(elt)->field.prev = head;			\ 	} else {						\ 		register queue_entry_t prev = (head)->prev;	\ 		(elt)->field.prev = prev;			\ 		(elt)->field.next = head;			\ 		(head)->prev = (queue_entry_t)(elt);		\ 		((type)prev)->field.next = (queue_entry_t)(elt);\ 	}							\ }
end_define

begin_define
define|#
directive|define
name|queue_field
parameter_list|(
name|head
parameter_list|,
name|thing
parameter_list|,
name|type
parameter_list|,
name|field
parameter_list|)
define|\
value|(((head) == (thing)) ? (head) :&((type)(thing))->field)
end_define

begin_define
define|#
directive|define
name|queue_remove
parameter_list|(
name|head
parameter_list|,
name|elt
parameter_list|,
name|type
parameter_list|,
name|field
parameter_list|)
value|{			\ 	register queue_entry_t next = (elt)->field.next;	\ 	register queue_entry_t prev = (elt)->field.prev;	\ 	queue_field((head), next, type, field)->prev = prev;	\ 	queue_field((head), prev, type, field)->next = next;	\ }
end_define

begin_define
define|#
directive|define
name|queue_assign
parameter_list|(
name|to
parameter_list|,
name|from
parameter_list|,
name|type
parameter_list|,
name|field
parameter_list|)
value|{			\ 	((type)((from)->prev))->field.next = (to);		\ 	((type)((from)->next))->field.prev = (to);		\ 	*to = *from;						\ }
end_define

begin_define
define|#
directive|define
name|queue_remove_first
parameter_list|(
name|h
parameter_list|,
name|e
parameter_list|,
name|t
parameter_list|,
name|f
parameter_list|)
value|{			\ 	e = (t) queue_first((h));				\ 	queue_remove((h), (e), t, f);				\ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _QUEUE_ */
end_comment

end_unit

