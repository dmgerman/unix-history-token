begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2012-2015 Samy Al Bahra.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)queue.h	8.5 (Berkeley) 8/20/94  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CK_QUEUE_H
end_ifndef

begin_define
define|#
directive|define
name|CK_QUEUE_H
end_define

begin_include
include|#
directive|include
file|<ck_pr.h>
end_include

begin_comment
comment|/*  * This file defines three types of data structures: singly-linked lists,  * singly-linked tail queues and lists.  *  * A singly-linked list is headed by a single forward pointer. The elements  * are singly linked for minimum space and pointer manipulation overhead at  * the expense of O(n) removal for arbitrary elements. New elements can be  * added to the list after an existing element or at the head of the list.  * Elements being removed from the head of the list should use the explicit  * macro for this purpose for optimum efficiency. A singly-linked list may  * only be traversed in the forward direction.  Singly-linked lists are ideal  * for applications with large datasets and few or no removals or for  * implementing a LIFO queue.  *  * A singly-linked tail queue is headed by a pair of pointers, one to the  * head of the list and the other to the tail of the list. The elements are  * singly linked for minimum space and pointer manipulation overhead at the  * expense of O(n) removal for arbitrary elements. New elements can be added  * to the list after an existing element, at the head of the list, or at the  * end of the list. Elements being removed from the head of the tail queue  * should use the explicit macro for this purpose for optimum efficiency.  * A singly-linked tail queue may only be traversed in the forward direction.  * Singly-linked tail queues are ideal for applications with large datasets  * and few or no removals or for implementing a FIFO queue.  *  * A list is headed by a single forward pointer (or an array of forward  * pointers for a hash table header). The elements are doubly linked  * so that an arbitrary element can be removed without a need to  * traverse the list. New elements can be added to the list before  * or after an existing element or at the head of the list. A list  * may only be traversed in the forward direction.  *  * It is safe to use _FOREACH/_FOREACH_SAFE in the presence of concurrent  * modifications to the list. Writers to these lists must, on the other hand,  * implement writer-side synchronization. The _SWAP operations are not atomic.  * This facility is currently unsupported on architectures such as the Alpha  * which require load-depend memory fences.  *  *				CK_SLIST	CK_LIST	CK_STAILQ  * _HEAD			+		+	+  * _HEAD_INITIALIZER		+		+	+  * _ENTRY			+		+	+  * _INIT			+		+	+  * _EMPTY			+		+	+  * _FIRST			+		+	+  * _NEXT			+		+	+  * _FOREACH			+		+	+  * _FOREACH_SAFE		+		+	+  * _INSERT_HEAD			+		+	+  * _INSERT_BEFORE		-		+	-  * _INSERT_AFTER		+		+	+  * _INSERT_TAIL			-		-	+  * _REMOVE_AFTER		+		-	+  * _REMOVE_HEAD			+		-	+  * _REMOVE			+		+	+  * _SWAP			+		+	+  * _MOVE			+		+	+  */
end_comment

begin_comment
comment|/*  * Singly-linked List declarations.  */
end_comment

begin_define
define|#
directive|define
name|CK_SLIST_HEAD
parameter_list|(
name|name
parameter_list|,
name|type
parameter_list|)
define|\
value|struct name {									\ 	struct type *slh_first;
comment|/* first element */
value|\ }
end_define

begin_define
define|#
directive|define
name|CK_SLIST_HEAD_INITIALIZER
parameter_list|(
name|head
parameter_list|)
define|\
value|{ NULL }
end_define

begin_define
define|#
directive|define
name|CK_SLIST_ENTRY
parameter_list|(
name|type
parameter_list|)
define|\
value|struct {									\ 	struct type *sle_next;
comment|/* next element */
value|\ }
end_define

begin_comment
comment|/*  * Singly-linked List functions.  */
end_comment

begin_define
define|#
directive|define
name|CK_SLIST_EMPTY
parameter_list|(
name|head
parameter_list|)
define|\
value|(ck_pr_load_ptr(&(head)->slh_first) == NULL)
end_define

begin_define
define|#
directive|define
name|CK_SLIST_FIRST
parameter_list|(
name|head
parameter_list|)
define|\
value|(ck_pr_load_ptr(&(head)->slh_first))
end_define

begin_define
define|#
directive|define
name|CK_SLIST_NEXT
parameter_list|(
name|elm
parameter_list|,
name|field
parameter_list|)
define|\
value|ck_pr_load_ptr(&((elm)->field.sle_next))
end_define

begin_define
define|#
directive|define
name|CK_SLIST_FOREACH
parameter_list|(
name|var
parameter_list|,
name|head
parameter_list|,
name|field
parameter_list|)
define|\
value|for ((var) = CK_SLIST_FIRST((head));					\ 	    (var)&& (ck_pr_fence_load(), 1);					\ 	    (var) = CK_SLIST_NEXT((var), field))
end_define

begin_define
define|#
directive|define
name|CK_SLIST_FOREACH_SAFE
parameter_list|(
name|var
parameter_list|,
name|head
parameter_list|,
name|field
parameter_list|,
name|tvar
parameter_list|)
define|\
value|for ((var) = CK_SLIST_FIRST(head);					 \ 	    (var)&& (ck_pr_fence_load(), (tvar) = CK_SLIST_NEXT(var, field), 1);\ 	    (var) = (tvar))
end_define

begin_define
define|#
directive|define
name|CK_SLIST_FOREACH_PREVPTR
parameter_list|(
name|var
parameter_list|,
name|varp
parameter_list|,
name|head
parameter_list|,
name|field
parameter_list|)
define|\
value|for ((varp) =&(head)->slh_first;					\ 	    ((var) = ck_pr_load_ptr(varp)) != NULL&& (ck_pr_fence_load(), 1);	\ 	    (varp) =&(var)->field.sle_next)
end_define

begin_define
define|#
directive|define
name|CK_SLIST_INIT
parameter_list|(
name|head
parameter_list|)
value|do {						\ 	ck_pr_store_ptr(&(head)->slh_first, NULL);				\ 	ck_pr_fence_store();							\ } while (0)
end_define

begin_define
define|#
directive|define
name|CK_SLIST_INSERT_AFTER
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|field
parameter_list|)
value|do {					\ 	(b)->field.sle_next = (a)->field.sle_next;				\ 	ck_pr_fence_store();							\ 	ck_pr_store_ptr(&(a)->field.sle_next, b);				\ } while (0)
end_define

begin_define
define|#
directive|define
name|CK_SLIST_INSERT_HEAD
parameter_list|(
name|head
parameter_list|,
name|elm
parameter_list|,
name|field
parameter_list|)
value|do {				\ 	(elm)->field.sle_next = (head)->slh_first;				\ 	ck_pr_fence_store();							\ 	ck_pr_store_ptr(&(head)->slh_first, elm);				\ } while (0)
end_define

begin_define
define|#
directive|define
name|CK_SLIST_REMOVE_AFTER
parameter_list|(
name|elm
parameter_list|,
name|field
parameter_list|)
value|do {					\ 	ck_pr_store_ptr(&(elm)->field.sle_next,					\ 	    (elm)->field.sle_next->field.sle_next);				\ } while (0)
end_define

begin_define
define|#
directive|define
name|CK_SLIST_REMOVE
parameter_list|(
name|head
parameter_list|,
name|elm
parameter_list|,
name|type
parameter_list|,
name|field
parameter_list|)
value|do {				\ 	if ((head)->slh_first == (elm)) {					\ 		CK_SLIST_REMOVE_HEAD((head), field);				\ 	} else {								\ 		struct type *curelm = (head)->slh_first;			\ 		while (curelm->field.sle_next != (elm))				\ 			curelm = curelm->field.sle_next;			\ 		CK_SLIST_REMOVE_AFTER(curelm, field);				\ 	}									\ } while (0)
end_define

begin_define
define|#
directive|define
name|CK_SLIST_REMOVE_HEAD
parameter_list|(
name|head
parameter_list|,
name|field
parameter_list|)
value|do {					\ 	ck_pr_store_ptr(&(head)->slh_first,					\ 		(head)->slh_first->field.sle_next);				\ } while (0)
end_define

begin_define
define|#
directive|define
name|CK_SLIST_MOVE
parameter_list|(
name|head1
parameter_list|,
name|head2
parameter_list|,
name|field
parameter_list|)
value|do {					\ 	ck_pr_store_ptr(&(head1)->slh_first, (head2)->slh_first);		\ } while (0)
end_define

begin_comment
comment|/*  * This operation is not applied atomically.  */
end_comment

begin_define
define|#
directive|define
name|CK_SLIST_SWAP
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|type
parameter_list|)
value|do {						\ 	struct type *swap_first = (a)->slh_first;				\ 	(a)->slh_first = (b)->slh_first;					\ 	(b)->slh_first = swap_first;						\ } while (0)
end_define

begin_comment
comment|/*  * Singly-linked Tail queue declarations.  */
end_comment

begin_define
define|#
directive|define
name|CK_STAILQ_HEAD
parameter_list|(
name|name
parameter_list|,
name|type
parameter_list|)
define|\
value|struct name {								\ 	struct type *stqh_first;
comment|/* first element */
value|\ 	struct type **stqh_last;
comment|/* addr of last next element */
value|\ }
end_define

begin_define
define|#
directive|define
name|CK_STAILQ_HEAD_INITIALIZER
parameter_list|(
name|head
parameter_list|)
define|\
value|{ NULL,&(head).stqh_first }
end_define

begin_define
define|#
directive|define
name|CK_STAILQ_ENTRY
parameter_list|(
name|type
parameter_list|)
define|\
value|struct {								\ 	struct type *stqe_next;
comment|/* next element */
value|\ }
end_define

begin_comment
comment|/*  * Singly-linked Tail queue functions.  */
end_comment

begin_define
define|#
directive|define
name|CK_STAILQ_CONCAT
parameter_list|(
name|head1
parameter_list|,
name|head2
parameter_list|)
value|do {					\ 	if ((head2)->stqh_first == NULL) {					\ 		ck_pr_store_ptr((head1)->stqh_last, (head2)->stqh_first);	\ 		ck_pr_fence_store();						\ 		(head1)->stqh_last = (head2)->stqh_last;			\ 		CK_STAILQ_INIT((head2));					\ 	}									\ } while (0)
end_define

begin_define
define|#
directive|define
name|CK_STAILQ_EMPTY
parameter_list|(
name|head
parameter_list|)
value|(ck_pr_load_ptr(&(head)->stqh_first) == NULL)
end_define

begin_define
define|#
directive|define
name|CK_STAILQ_FIRST
parameter_list|(
name|head
parameter_list|)
value|(ck_pr_load_ptr(&(head)->stqh_first))
end_define

begin_define
define|#
directive|define
name|CK_STAILQ_FOREACH
parameter_list|(
name|var
parameter_list|,
name|head
parameter_list|,
name|field
parameter_list|)
define|\
value|for((var) = CK_STAILQ_FIRST((head));				\ 	   (var)&& (ck_pr_fence_load(), 1);				\ 	   (var) = CK_STAILQ_NEXT((var), field))
end_define

begin_define
define|#
directive|define
name|CK_STAILQ_FOREACH_SAFE
parameter_list|(
name|var
parameter_list|,
name|head
parameter_list|,
name|field
parameter_list|,
name|tvar
parameter_list|)
define|\
value|for ((var) = CK_STAILQ_FIRST((head));				\ 	    (var)&& (ck_pr_fence_load(), (tvar) =			\ 		CK_STAILQ_NEXT((var), field), 1);			\ 	    (var) = (tvar))
end_define

begin_define
define|#
directive|define
name|CK_STAILQ_INIT
parameter_list|(
name|head
parameter_list|)
value|do {					\ 	ck_pr_store_ptr(&(head)->stqh_first, NULL);			\ 	ck_pr_fence_store();						\ 	(head)->stqh_last =&(head)->stqh_first;			\ } while (0)
end_define

begin_define
define|#
directive|define
name|CK_STAILQ_INSERT_AFTER
parameter_list|(
name|head
parameter_list|,
name|tqelm
parameter_list|,
name|elm
parameter_list|,
name|field
parameter_list|)
value|do {			\ 	(elm)->field.stqe_next = (tqelm)->field.stqe_next;			\ 	ck_pr_fence_store();							\ 	ck_pr_store_ptr(&(tqelm)->field.stqe_next, elm);			\ 	if ((elm)->field.stqe_next == NULL)					\ 		(head)->stqh_last =&(elm)->field.stqe_next;			\ } while (0)
end_define

begin_define
define|#
directive|define
name|CK_STAILQ_INSERT_HEAD
parameter_list|(
name|head
parameter_list|,
name|elm
parameter_list|,
name|field
parameter_list|)
value|do {				\ 	(elm)->field.stqe_next = (head)->stqh_first;				\ 	ck_pr_fence_store();							\ 	ck_pr_store_ptr(&(head)->stqh_first, elm);				\ 	if ((elm)->field.stqe_next == NULL)					\ 		(head)->stqh_last =&(elm)->field.stqe_next;			\ } while (0)
end_define

begin_define
define|#
directive|define
name|CK_STAILQ_INSERT_TAIL
parameter_list|(
name|head
parameter_list|,
name|elm
parameter_list|,
name|field
parameter_list|)
value|do {				\ 	(elm)->field.stqe_next = NULL;						\ 	ck_pr_fence_store();							\ 	ck_pr_store_ptr((head)->stqh_last, (elm));				\ 	(head)->stqh_last =&(elm)->field.stqe_next;				\ } while (0)
end_define

begin_define
define|#
directive|define
name|CK_STAILQ_NEXT
parameter_list|(
name|elm
parameter_list|,
name|field
parameter_list|)
define|\
value|(ck_pr_load_ptr(&(elm)->field.stqe_next))
end_define

begin_define
define|#
directive|define
name|CK_STAILQ_REMOVE
parameter_list|(
name|head
parameter_list|,
name|elm
parameter_list|,
name|type
parameter_list|,
name|field
parameter_list|)
value|do {				\ 	if ((head)->stqh_first == (elm)) {					\ 		CK_STAILQ_REMOVE_HEAD((head), field);				\ 	} else {								\ 		struct type *curelm = (head)->stqh_first;			\ 		while (curelm->field.stqe_next != (elm))			\ 			curelm = curelm->field.stqe_next;			\ 		CK_STAILQ_REMOVE_AFTER(head, curelm, field);			\ 	}									\ } while (0)
end_define

begin_define
define|#
directive|define
name|CK_STAILQ_REMOVE_AFTER
parameter_list|(
name|head
parameter_list|,
name|elm
parameter_list|,
name|field
parameter_list|)
value|do {				\ 	ck_pr_store_ptr(&(elm)->field.stqe_next,				\ 	    (elm)->field.stqe_next->field.stqe_next);				\ 	if ((elm)->field.stqe_next == NULL)					\ 		(head)->stqh_last =&(elm)->field.stqe_next;			\ } while (0)
end_define

begin_define
define|#
directive|define
name|CK_STAILQ_REMOVE_HEAD
parameter_list|(
name|head
parameter_list|,
name|field
parameter_list|)
value|do {					\ 	ck_pr_store_ptr(&(head)->stqh_first,					\ 	    (head)->stqh_first->field.stqe_next);				\ 	if ((head)->stqh_first == NULL)						\ 		(head)->stqh_last =&(head)->stqh_first;			\ } while (0)
end_define

begin_define
define|#
directive|define
name|CK_STAILQ_MOVE
parameter_list|(
name|head1
parameter_list|,
name|head2
parameter_list|,
name|field
parameter_list|)
value|do {				\ 	ck_pr_store_ptr(&(head1)->stqh_first, (head2)->stqh_first);		\ 	(head1)->stqh_last = (head2)->stqh_last;				\ 	if ((head2)->stqh_last ==&(head2)->stqh_first)				\ 		(head1)->stqh_last =&(head1)->stqh_first;			\ } while (0)
end_define

begin_comment
comment|/*  * This operation is not applied atomically.  */
end_comment

begin_define
define|#
directive|define
name|CK_STAILQ_SWAP
parameter_list|(
name|head1
parameter_list|,
name|head2
parameter_list|,
name|type
parameter_list|)
value|do {				\ 	struct type *swap_first = CK_STAILQ_FIRST(head1);		\ 	struct type **swap_last = (head1)->stqh_last;			\ 	CK_STAILQ_FIRST(head1) = CK_STAILQ_FIRST(head2);		\ 	(head1)->stqh_last = (head2)->stqh_last;			\ 	CK_STAILQ_FIRST(head2) = swap_first;				\ 	(head2)->stqh_last = swap_last;					\ 	if (CK_STAILQ_EMPTY(head1))					\ 		(head1)->stqh_last =&(head1)->stqh_first;		\ 	if (CK_STAILQ_EMPTY(head2))					\ 		(head2)->stqh_last =&(head2)->stqh_first;		\ } while (0)
end_define

begin_comment
comment|/*  * List declarations.  */
end_comment

begin_define
define|#
directive|define
name|CK_LIST_HEAD
parameter_list|(
name|name
parameter_list|,
name|type
parameter_list|)
define|\
value|struct name {									\ 	struct type *lh_first;
comment|/* first element */
value|\ }
end_define

begin_define
define|#
directive|define
name|CK_LIST_HEAD_INITIALIZER
parameter_list|(
name|head
parameter_list|)
define|\
value|{ NULL }
end_define

begin_define
define|#
directive|define
name|CK_LIST_ENTRY
parameter_list|(
name|type
parameter_list|)
define|\
value|struct {									\ 	struct type *le_next;
comment|/* next element */
value|\ 	struct type **le_prev;
comment|/* address of previous next element */
value|\ }
end_define

begin_define
define|#
directive|define
name|CK_LIST_FIRST
parameter_list|(
name|head
parameter_list|)
value|ck_pr_load_ptr(&(head)->lh_first)
end_define

begin_define
define|#
directive|define
name|CK_LIST_EMPTY
parameter_list|(
name|head
parameter_list|)
value|(CK_LIST_FIRST(head) == NULL)
end_define

begin_define
define|#
directive|define
name|CK_LIST_NEXT
parameter_list|(
name|elm
parameter_list|,
name|field
parameter_list|)
value|ck_pr_load_ptr(&(elm)->field.le_next)
end_define

begin_define
define|#
directive|define
name|CK_LIST_FOREACH
parameter_list|(
name|var
parameter_list|,
name|head
parameter_list|,
name|field
parameter_list|)
define|\
value|for ((var) = CK_LIST_FIRST((head));					\ 	    (var)&& (ck_pr_fence_load(), 1);					\ 	    (var) = CK_LIST_NEXT((var), field))
end_define

begin_define
define|#
directive|define
name|CK_LIST_FOREACH_SAFE
parameter_list|(
name|var
parameter_list|,
name|head
parameter_list|,
name|field
parameter_list|,
name|tvar
parameter_list|)
define|\
value|for ((var) = CK_LIST_FIRST((head));					  \ 	    (var)&& (ck_pr_fence_load(), (tvar) = CK_LIST_NEXT((var), field), 1);\ 	    (var) = (tvar))
end_define

begin_define
define|#
directive|define
name|CK_LIST_INIT
parameter_list|(
name|head
parameter_list|)
value|do {							\ 	ck_pr_store_ptr(&(head)->lh_first, NULL);				\ 	ck_pr_fence_store();							\ } while (0)
end_define

begin_define
define|#
directive|define
name|CK_LIST_INSERT_AFTER
parameter_list|(
name|listelm
parameter_list|,
name|elm
parameter_list|,
name|field
parameter_list|)
value|do {				\ 	(elm)->field.le_next = (listelm)->field.le_next;			\ 	(elm)->field.le_prev =&(listelm)->field.le_next;			\ 	ck_pr_fence_store();							\ 	if ((listelm)->field.le_next != NULL)					\ 		(listelm)->field.le_next->field.le_prev =&(elm)->field.le_next;\ 	ck_pr_store_ptr(&(listelm)->field.le_next, elm);			\ } while (0)
end_define

begin_define
define|#
directive|define
name|CK_LIST_INSERT_BEFORE
parameter_list|(
name|listelm
parameter_list|,
name|elm
parameter_list|,
name|field
parameter_list|)
value|do {				\ 	(elm)->field.le_prev = (listelm)->field.le_prev;			\ 	(elm)->field.le_next = (listelm);					\ 	ck_pr_fence_store();							\ 	ck_pr_store_ptr((listelm)->field.le_prev, (elm));			\ 	(listelm)->field.le_prev =&(elm)->field.le_next;			\ } while (0)
end_define

begin_define
define|#
directive|define
name|CK_LIST_INSERT_HEAD
parameter_list|(
name|head
parameter_list|,
name|elm
parameter_list|,
name|field
parameter_list|)
value|do {				\ 	(elm)->field.le_next = (head)->lh_first;				\ 	ck_pr_fence_store();							\ 	if ((elm)->field.le_next != NULL)					\ 		(head)->lh_first->field.le_prev =&(elm)->field.le_next;	\ 	ck_pr_store_ptr(&(head)->lh_first, elm);				\ 	(elm)->field.le_prev =&(head)->lh_first;				\ } while (0)
end_define

begin_define
define|#
directive|define
name|CK_LIST_REMOVE
parameter_list|(
name|elm
parameter_list|,
name|field
parameter_list|)
value|do {						\ 	ck_pr_store_ptr((elm)->field.le_prev, (elm)->field.le_next);		\ 	if ((elm)->field.le_next != NULL)					\ 		(elm)->field.le_next->field.le_prev = (elm)->field.le_prev;	\ } while (0)
end_define

begin_define
define|#
directive|define
name|CK_LIST_MOVE
parameter_list|(
name|head1
parameter_list|,
name|head2
parameter_list|,
name|field
parameter_list|)
value|do {				\ 	ck_pr_store_ptr(&(head1)->lh_first, (head2)->lh_first);		\ 	if ((head1)->lh_first != NULL)					\ 		(head1)->lh_first->field.le_prev =&(head1)->lh_first;	\ } while (0)
end_define

begin_comment
comment|/*  * This operation is not applied atomically.  */
end_comment

begin_define
define|#
directive|define
name|CK_LIST_SWAP
parameter_list|(
name|head1
parameter_list|,
name|head2
parameter_list|,
name|type
parameter_list|,
name|field
parameter_list|)
value|do {			\ 	struct type *swap_tmp = (head1)->lh_first;			\ 	(head1)->lh_first = (head2)->lh_first;				\ 	(head2)->lh_first = swap_tmp;					\ 	if ((swap_tmp = (head1)->lh_first) != NULL)			\ 		swap_tmp->field.le_prev =&(head1)->lh_first;		\ 	if ((swap_tmp = (head2)->lh_first) != NULL)			\ 		swap_tmp->field.le_prev =&(head2)->lh_first;		\ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_QUEUE_H */
end_comment

end_unit

