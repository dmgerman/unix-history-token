begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * Copyright (c) 1991 Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * The Mach Operating System project at Carnegie-Mellon University.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)queue.h	7.3 (Berkeley) 4/21/91  *	$Id: queue.h,v 1.2 1993/10/16 16:20:18 rgrimes Exp $  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1987, 1990 Carnegie-Mellon University.  * All rights reserved.  *  * Author: Avadis Tevanian, Jr.  *   * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *   * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"   * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND   * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *   * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_comment
comment|/*  *	Type definitions for generic queues.  */
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
name|queue_enter_head
parameter_list|(
name|head
parameter_list|,
name|elt
parameter_list|,
name|type
parameter_list|,
name|field
parameter_list|)
value|{		\ 	if (queue_empty((head))) {				\ 		(head)->next = (queue_entry_t) elt;		\ 		(head)->prev = (queue_entry_t) elt;		\ 		(elt)->field.next = head;			\ 		(elt)->field.prev = head;			\ 	} else {						\ 		register queue_entry_t next = (head)->next;	\ 		(elt)->field.prev = head;			\ 		(elt)->field.next = next;			\ 		(head)->next = (queue_entry_t)(elt);		\ 		((type)next)->field.prev = (queue_entry_t)(elt);\ 	}							\ }
end_define

begin_comment
comment|/* insert 'item' after 'position' using field 'field' */
end_comment

begin_comment
comment|/* XXX might be broken - BEWARE */
end_comment

begin_define
define|#
directive|define
name|queue_insert
parameter_list|(
name|position
parameter_list|,
name|item
parameter_list|,
name|type
parameter_list|,
name|field
parameter_list|)
value|{			\ 	((type) position->field.next)->field.prev = (queue_entry_t)(item);		\ 	(item)->field.next = (position)->field.next;		\ 	(position)->field.next = (queue_entry_t)(item);		\ 	(item)->field.prev = (queue_entry_t) position;		\ }
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
comment|/* !_QUEUE_H_ */
end_comment

end_unit

