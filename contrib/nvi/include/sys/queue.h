begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)queue.h	8.5 (Berkeley) 8/20/94  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_QUEUE_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_QUEUE_H_
end_define

begin_comment
comment|/*  * This file defines three types of data structures: lists, tail queues,  * and circular queues.  *  * A list is headed by a single forward pointer (or an array of forward  * pointers for a hash table header). The elements are doubly linked  * so that an arbitrary element can be removed without a need to  * traverse the list. New elements can be added to the list before  * or after an existing element or at the head of the list. A list  * may only be traversed in the forward direction.  *  * A tail queue is headed by a pair of pointers, one to the head of the  * list and the other to the tail of the list. The elements are doubly  * linked so that an arbitrary element can be removed without a need to  * traverse the list. New elements can be added to the list before or  * after an existing element, at the head of the list, or at the end of  * the list. A tail queue may only be traversed in the forward direction.  *  * A circle queue is headed by a pair of pointers, one to the head of the  * list and the other to the tail of the list. The elements are doubly  * linked so that an arbitrary element can be removed without a need to  * traverse the list. New elements can be added to the list before or after  * an existing element, at the head of the list, or at the end of the list.  * A circle queue may be traversed in either direction, but has a more  * complex end of list detection.  *  * For details on the use of these macros, see the queue(3) manual page.  */
end_comment

begin_comment
comment|/*  * List definitions.  */
end_comment

begin_define
define|#
directive|define
name|LIST_HEAD
parameter_list|(
name|name
parameter_list|,
name|type
parameter_list|)
define|\
value|struct name {								\ 	struct type *lh_first;
comment|/* first element */
value|\ }
end_define

begin_define
define|#
directive|define
name|LIST_ENTRY
parameter_list|(
name|type
parameter_list|)
define|\
value|struct {								\ 	struct type *le_next;
comment|/* next element */
value|\ 	struct type **le_prev;
comment|/* address of previous next element */
value|\ }
end_define

begin_comment
comment|/*  * List functions.  */
end_comment

begin_define
define|#
directive|define
name|LIST_INIT
parameter_list|(
name|head
parameter_list|)
value|{						\ 	(head)->lh_first = NULL;					\ }
end_define

begin_define
define|#
directive|define
name|LIST_INSERT_AFTER
parameter_list|(
name|listelm
parameter_list|,
name|elm
parameter_list|,
name|field
parameter_list|)
value|{			\ 	if (((elm)->field.le_next = (listelm)->field.le_next) != NULL)	\ 		(listelm)->field.le_next->field.le_prev =		\&(elm)->field.le_next;				\ 	(listelm)->field.le_next = (elm);				\ 	(elm)->field.le_prev =&(listelm)->field.le_next;		\ }
end_define

begin_define
define|#
directive|define
name|LIST_INSERT_BEFORE
parameter_list|(
name|listelm
parameter_list|,
name|elm
parameter_list|,
name|field
parameter_list|)
value|{			\ 	(elm)->field.le_prev = (listelm)->field.le_prev;		\ 	(elm)->field.le_next = (listelm);				\ 	*(listelm)->field.le_prev = (elm);				\ 	(listelm)->field.le_prev =&(elm)->field.le_next;		\ }
end_define

begin_define
define|#
directive|define
name|LIST_INSERT_HEAD
parameter_list|(
name|head
parameter_list|,
name|elm
parameter_list|,
name|field
parameter_list|)
value|{				\ 	if (((elm)->field.le_next = (head)->lh_first) != NULL)		\ 		(head)->lh_first->field.le_prev =&(elm)->field.le_next;\ 	(head)->lh_first = (elm);					\ 	(elm)->field.le_prev =&(head)->lh_first;			\ }
end_define

begin_define
define|#
directive|define
name|LIST_REMOVE
parameter_list|(
name|elm
parameter_list|,
name|field
parameter_list|)
value|{					\ 	if ((elm)->field.le_next != NULL)				\ 		(elm)->field.le_next->field.le_prev = 			\ 		    (elm)->field.le_prev;				\ 	*(elm)->field.le_prev = (elm)->field.le_next;			\ }
end_define

begin_comment
comment|/*  * Tail queue definitions.  */
end_comment

begin_define
define|#
directive|define
name|TAILQ_HEAD
parameter_list|(
name|name
parameter_list|,
name|type
parameter_list|)
define|\
value|struct name {								\ 	struct type *tqh_first;
comment|/* first element */
value|\ 	struct type **tqh_last;
comment|/* addr of last next element */
value|\ }
end_define

begin_define
define|#
directive|define
name|TAILQ_ENTRY
parameter_list|(
name|type
parameter_list|)
define|\
value|struct {								\ 	struct type *tqe_next;
comment|/* next element */
value|\ 	struct type **tqe_prev;
comment|/* address of previous next element */
value|\ }
end_define

begin_comment
comment|/*  * Tail queue functions.  */
end_comment

begin_define
define|#
directive|define
name|TAILQ_INIT
parameter_list|(
name|head
parameter_list|)
value|{						\ 	(head)->tqh_first = NULL;					\ 	(head)->tqh_last =&(head)->tqh_first;				\ }
end_define

begin_define
define|#
directive|define
name|TAILQ_INSERT_HEAD
parameter_list|(
name|head
parameter_list|,
name|elm
parameter_list|,
name|field
parameter_list|)
value|{				\ 	if (((elm)->field.tqe_next = (head)->tqh_first) != NULL)	\ 		(head)->tqh_first->field.tqe_prev =			\&(elm)->field.tqe_next;				\ 	else								\ 		(head)->tqh_last =&(elm)->field.tqe_next;		\ 	(head)->tqh_first = (elm);					\ 	(elm)->field.tqe_prev =&(head)->tqh_first;			\ }
end_define

begin_define
define|#
directive|define
name|TAILQ_INSERT_TAIL
parameter_list|(
name|head
parameter_list|,
name|elm
parameter_list|,
name|field
parameter_list|)
value|{				\ 	(elm)->field.tqe_next = NULL;					\ 	(elm)->field.tqe_prev = (head)->tqh_last;			\ 	*(head)->tqh_last = (elm);					\ 	(head)->tqh_last =&(elm)->field.tqe_next;			\ }
end_define

begin_define
define|#
directive|define
name|TAILQ_INSERT_AFTER
parameter_list|(
name|head
parameter_list|,
name|listelm
parameter_list|,
name|elm
parameter_list|,
name|field
parameter_list|)
value|{			\ 	if (((elm)->field.tqe_next = (listelm)->field.tqe_next) != NULL)\ 		(elm)->field.tqe_next->field.tqe_prev = 		\&(elm)->field.tqe_next;				\ 	else								\ 		(head)->tqh_last =&(elm)->field.tqe_next;		\ 	(listelm)->field.tqe_next = (elm);				\ 	(elm)->field.tqe_prev =&(listelm)->field.tqe_next;		\ }
end_define

begin_define
define|#
directive|define
name|TAILQ_INSERT_BEFORE
parameter_list|(
name|listelm
parameter_list|,
name|elm
parameter_list|,
name|field
parameter_list|)
value|{			\ 	(elm)->field.tqe_prev = (listelm)->field.tqe_prev;		\ 	(elm)->field.tqe_next = (listelm);				\ 	*(listelm)->field.tqe_prev = (elm);				\ 	(listelm)->field.tqe_prev =&(elm)->field.tqe_next;		\ }
end_define

begin_define
define|#
directive|define
name|TAILQ_REMOVE
parameter_list|(
name|head
parameter_list|,
name|elm
parameter_list|,
name|field
parameter_list|)
value|{				\ 	if (((elm)->field.tqe_next) != NULL)				\ 		(elm)->field.tqe_next->field.tqe_prev = 		\ 		    (elm)->field.tqe_prev;				\ 	else								\ 		(head)->tqh_last = (elm)->field.tqe_prev;		\ 	*(elm)->field.tqe_prev = (elm)->field.tqe_next;			\ }
end_define

begin_comment
comment|/*  * Circular queue definitions.  */
end_comment

begin_define
define|#
directive|define
name|CIRCLEQ_HEAD
parameter_list|(
name|name
parameter_list|,
name|type
parameter_list|)
define|\
value|struct name {								\ 	struct type *cqh_first;
comment|/* first element */
value|\ 	struct type *cqh_last;
comment|/* last element */
value|\ }
end_define

begin_define
define|#
directive|define
name|CIRCLEQ_ENTRY
parameter_list|(
name|type
parameter_list|)
define|\
value|struct {								\ 	struct type *cqe_next;
comment|/* next element */
value|\ 	struct type *cqe_prev;
comment|/* previous element */
value|\ }
end_define

begin_comment
comment|/*  * Circular queue functions.  */
end_comment

begin_define
define|#
directive|define
name|CIRCLEQ_INIT
parameter_list|(
name|head
parameter_list|)
value|{						\ 	(head)->cqh_first = (void *)(head);				\ 	(head)->cqh_last = (void *)(head);				\ }
end_define

begin_define
define|#
directive|define
name|CIRCLEQ_INSERT_AFTER
parameter_list|(
name|head
parameter_list|,
name|listelm
parameter_list|,
name|elm
parameter_list|,
name|field
parameter_list|)
value|{		\ 	(elm)->field.cqe_next = (listelm)->field.cqe_next;		\ 	(elm)->field.cqe_prev = (listelm);				\ 	if ((listelm)->field.cqe_next == (void *)(head))		\ 		(head)->cqh_last = (elm);				\ 	else								\ 		(listelm)->field.cqe_next->field.cqe_prev = (elm);	\ 	(listelm)->field.cqe_next = (elm);				\ }
end_define

begin_define
define|#
directive|define
name|CIRCLEQ_INSERT_BEFORE
parameter_list|(
name|head
parameter_list|,
name|listelm
parameter_list|,
name|elm
parameter_list|,
name|field
parameter_list|)
value|{		\ 	(elm)->field.cqe_next = (listelm);				\ 	(elm)->field.cqe_prev = (listelm)->field.cqe_prev;		\ 	if ((listelm)->field.cqe_prev == (void *)(head))		\ 		(head)->cqh_first = (elm);				\ 	else								\ 		(listelm)->field.cqe_prev->field.cqe_next = (elm);	\ 	(listelm)->field.cqe_prev = (elm);				\ }
end_define

begin_define
define|#
directive|define
name|CIRCLEQ_INSERT_HEAD
parameter_list|(
name|head
parameter_list|,
name|elm
parameter_list|,
name|field
parameter_list|)
value|{				\ 	(elm)->field.cqe_next = (head)->cqh_first;			\ 	(elm)->field.cqe_prev = (void *)(head);				\ 	if ((head)->cqh_last == (void *)(head))				\ 		(head)->cqh_last = (elm);				\ 	else								\ 		(head)->cqh_first->field.cqe_prev = (elm);		\ 	(head)->cqh_first = (elm);					\ }
end_define

begin_define
define|#
directive|define
name|CIRCLEQ_INSERT_TAIL
parameter_list|(
name|head
parameter_list|,
name|elm
parameter_list|,
name|field
parameter_list|)
value|{				\ 	(elm)->field.cqe_next = (void *)(head);				\ 	(elm)->field.cqe_prev = (head)->cqh_last;			\ 	if ((head)->cqh_first == (void *)(head))			\ 		(head)->cqh_first = (elm);				\ 	else								\ 		(head)->cqh_last->field.cqe_next = (elm);		\ 	(head)->cqh_last = (elm);					\ }
end_define

begin_define
define|#
directive|define
name|CIRCLEQ_REMOVE
parameter_list|(
name|head
parameter_list|,
name|elm
parameter_list|,
name|field
parameter_list|)
value|{				\ 	if ((elm)->field.cqe_next == (void *)(head))			\ 		(head)->cqh_last = (elm)->field.cqe_prev;		\ 	else								\ 		(elm)->field.cqe_next->field.cqe_prev =			\ 		    (elm)->field.cqe_prev;				\ 	if ((elm)->field.cqe_prev == (void *)(head))			\ 		(head)->cqh_first = (elm)->field.cqe_next;		\ 	else								\ 		(elm)->field.cqe_prev->field.cqe_next =			\ 		    (elm)->field.cqe_next;				\ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_QUEUE_H_ */
end_comment

end_unit

