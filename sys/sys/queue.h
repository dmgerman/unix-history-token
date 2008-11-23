begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: queue.h,v 1.39 2004/04/18 14:25:34 lukem Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)queue.h	8.5 (Berkeley) 8/20/94  */
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
comment|/*  * This file defines five types of data structures: singly-linked lists,  * lists, simple queues, tail queues, and circular queues.  *  * A singly-linked list is headed by a single forward pointer. The  * elements are singly linked for minimum space and pointer manipulation  * overhead at the expense of O(n) removal for arbitrary elements. New  * elements can be added to the list after an existing element or at the  * head of the list.  Elements being removed from the head of the list  * should use the explicit macro for this purpose for optimum  * efficiency. A singly-linked list may only be traversed in the forward  * direction.  Singly-linked lists are ideal for applications with large  * datasets and few or no removals or for implementing a LIFO queue.  *  * A list is headed by a single forward pointer (or an array of forward  * pointers for a hash table header). The elements are doubly linked  * so that an arbitrary element can be removed without a need to  * traverse the list. New elements can be added to the list before  * or after an existing element or at the head of the list. A list  * may only be traversed in the forward direction.  *  * A simple queue is headed by a pair of pointers, one the head of the  * list and the other to the tail of the list. The elements are singly  * linked to save space, so only elements can only be removed from the  * head of the list. New elements can be added to the list after  * an existing element, at the head of the list, or at the end of the  * list. A simple queue may only be traversed in the forward direction.  *  * A tail queue is headed by a pair of pointers, one to the head of the  * list and the other to the tail of the list. The elements are doubly  * linked so that an arbitrary element can be removed without a need to  * traverse the list. New elements can be added to the list before or  * after an existing element, at the head of the list, or at the end of  * the list. A tail queue may be traversed in either direction.  *  * A circle queue is headed by a pair of pointers, one to the head of the  * list and the other to the tail of the list. The elements are doubly  * linked so that an arbitrary element can be removed without a need to  * traverse the list. New elements can be added to the list before or after  * an existing element, at the head of the list, or at the end of the list.  * A circle queue may be traversed in either direction, but has a more  * complex end of list detection.  *  * For details on the use of these macros, see the queue(3) manual page.  */
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
name|LIST_HEAD_INITIALIZER
parameter_list|(
name|head
parameter_list|)
define|\
value|{ NULL }
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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|&&
name|defined
argument_list|(
name|QUEUEDEBUG
argument_list|)
end_if

begin_define
define|#
directive|define
name|QUEUEDEBUG_LIST_INSERT_HEAD
parameter_list|(
name|head
parameter_list|,
name|elm
parameter_list|,
name|field
parameter_list|)
define|\
value|if ((head)->lh_first&&						\ 	    (head)->lh_first->field.le_prev !=&(head)->lh_first)	\ 		panic("LIST_INSERT_HEAD %p %s:%d", (head), __FILE__, __LINE__);
end_define

begin_define
define|#
directive|define
name|QUEUEDEBUG_LIST_OP
parameter_list|(
name|elm
parameter_list|,
name|field
parameter_list|)
define|\
value|if ((elm)->field.le_next&&					\ 	    (elm)->field.le_next->field.le_prev !=			\&(elm)->field.le_next)					\ 		panic("LIST_* forw %p %s:%d", (elm), __FILE__, __LINE__);\ 	if (*(elm)->field.le_prev != (elm))				\ 		panic("LIST_* back %p %s:%d", (elm), __FILE__, __LINE__);
end_define

begin_define
define|#
directive|define
name|QUEUEDEBUG_LIST_POSTREMOVE
parameter_list|(
name|elm
parameter_list|,
name|field
parameter_list|)
define|\
value|(elm)->field.le_next = (void *)1L;				\ 	(elm)->field.le_prev = (void *)1L;
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|QUEUEDEBUG_LIST_INSERT_HEAD
parameter_list|(
name|head
parameter_list|,
name|elm
parameter_list|,
name|field
parameter_list|)
end_define

begin_define
define|#
directive|define
name|QUEUEDEBUG_LIST_OP
parameter_list|(
name|elm
parameter_list|,
name|field
parameter_list|)
end_define

begin_define
define|#
directive|define
name|QUEUEDEBUG_LIST_POSTREMOVE
parameter_list|(
name|elm
parameter_list|,
name|field
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|LIST_INIT
parameter_list|(
name|head
parameter_list|)
value|do {						\ 	(head)->lh_first = NULL;					\ } while (
comment|/*CONSTCOND*/
value|0)
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
value|do {			\ 	QUEUEDEBUG_LIST_OP((listelm), field)				\ 	if (((elm)->field.le_next = (listelm)->field.le_next) != NULL)	\ 		(listelm)->field.le_next->field.le_prev =		\&(elm)->field.le_next;				\ 	(listelm)->field.le_next = (elm);				\ 	(elm)->field.le_prev =&(listelm)->field.le_next;		\ } while (
comment|/*CONSTCOND*/
value|0)
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
value|do {			\ 	QUEUEDEBUG_LIST_OP((listelm), field)				\ 	(elm)->field.le_prev = (listelm)->field.le_prev;		\ 	(elm)->field.le_next = (listelm);				\ 	*(listelm)->field.le_prev = (elm);				\ 	(listelm)->field.le_prev =&(elm)->field.le_next;		\ } while (
comment|/*CONSTCOND*/
value|0)
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
value|do {				\ 	QUEUEDEBUG_LIST_INSERT_HEAD((head), (elm), field)		\ 	if (((elm)->field.le_next = (head)->lh_first) != NULL)		\ 		(head)->lh_first->field.le_prev =&(elm)->field.le_next;\ 	(head)->lh_first = (elm);					\ 	(elm)->field.le_prev =&(head)->lh_first;			\ } while (
comment|/*CONSTCOND*/
value|0)
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
value|do {					\ 	QUEUEDEBUG_LIST_OP((elm), field)				\ 	if ((elm)->field.le_next != NULL)				\ 		(elm)->field.le_next->field.le_prev = 			\ 		    (elm)->field.le_prev;				\ 	*(elm)->field.le_prev = (elm)->field.le_next;			\ 	QUEUEDEBUG_LIST_POSTREMOVE((elm), field)			\ } while (
comment|/*CONSTCOND*/
value|0)
end_define

begin_define
define|#
directive|define
name|LIST_FOREACH
parameter_list|(
name|var
parameter_list|,
name|head
parameter_list|,
name|field
parameter_list|)
define|\
value|for ((var) = ((head)->lh_first);				\ 		(var);							\ 		(var) = ((var)->field.le_next))
end_define

begin_comment
comment|/*  * List access methods.  */
end_comment

begin_define
define|#
directive|define
name|LIST_EMPTY
parameter_list|(
name|head
parameter_list|)
value|((head)->lh_first == NULL)
end_define

begin_define
define|#
directive|define
name|LIST_FIRST
parameter_list|(
name|head
parameter_list|)
value|((head)->lh_first)
end_define

begin_define
define|#
directive|define
name|LIST_NEXT
parameter_list|(
name|elm
parameter_list|,
name|field
parameter_list|)
value|((elm)->field.le_next)
end_define

begin_comment
comment|/*  * Singly-linked List definitions.  */
end_comment

begin_define
define|#
directive|define
name|SLIST_HEAD
parameter_list|(
name|name
parameter_list|,
name|type
parameter_list|)
define|\
value|struct name {								\ 	struct type *slh_first;
comment|/* first element */
value|\ }
end_define

begin_define
define|#
directive|define
name|SLIST_HEAD_INITIALIZER
parameter_list|(
name|head
parameter_list|)
define|\
value|{ NULL }
end_define

begin_define
define|#
directive|define
name|SLIST_ENTRY
parameter_list|(
name|type
parameter_list|)
define|\
value|struct {								\ 	struct type *sle_next;
comment|/* next element */
value|\ }
end_define

begin_comment
comment|/*  * Singly-linked List functions.  */
end_comment

begin_define
define|#
directive|define
name|SLIST_INIT
parameter_list|(
name|head
parameter_list|)
value|do {						\ 	(head)->slh_first = NULL;					\ } while (
comment|/*CONSTCOND*/
value|0)
end_define

begin_define
define|#
directive|define
name|SLIST_INSERT_AFTER
parameter_list|(
name|slistelm
parameter_list|,
name|elm
parameter_list|,
name|field
parameter_list|)
value|do {			\ 	(elm)->field.sle_next = (slistelm)->field.sle_next;		\ 	(slistelm)->field.sle_next = (elm);				\ } while (
comment|/*CONSTCOND*/
value|0)
end_define

begin_define
define|#
directive|define
name|SLIST_INSERT_HEAD
parameter_list|(
name|head
parameter_list|,
name|elm
parameter_list|,
name|field
parameter_list|)
value|do {			\ 	(elm)->field.sle_next = (head)->slh_first;			\ 	(head)->slh_first = (elm);					\ } while (
comment|/*CONSTCOND*/
value|0)
end_define

begin_define
define|#
directive|define
name|SLIST_REMOVE_HEAD
parameter_list|(
name|head
parameter_list|,
name|field
parameter_list|)
value|do {				\ 	(head)->slh_first = (head)->slh_first->field.sle_next;		\ } while (
comment|/*CONSTCOND*/
value|0)
end_define

begin_define
define|#
directive|define
name|SLIST_REMOVE
parameter_list|(
name|head
parameter_list|,
name|elm
parameter_list|,
name|type
parameter_list|,
name|field
parameter_list|)
value|do {			\ 	if ((head)->slh_first == (elm)) {				\ 		SLIST_REMOVE_HEAD((head), field);			\ 	}								\ 	else {								\ 		struct type *curelm = (head)->slh_first;		\ 		while(curelm->field.sle_next != (elm))			\ 			curelm = curelm->field.sle_next;		\ 		curelm->field.sle_next =				\ 		    curelm->field.sle_next->field.sle_next;		\ 	}								\ } while (
comment|/*CONSTCOND*/
value|0)
end_define

begin_define
define|#
directive|define
name|SLIST_FOREACH
parameter_list|(
name|var
parameter_list|,
name|head
parameter_list|,
name|field
parameter_list|)
define|\
value|for((var) = (head)->slh_first; (var); (var) = (var)->field.sle_next)
end_define

begin_comment
comment|/*  * Singly-linked List access methods.  */
end_comment

begin_define
define|#
directive|define
name|SLIST_EMPTY
parameter_list|(
name|head
parameter_list|)
value|((head)->slh_first == NULL)
end_define

begin_define
define|#
directive|define
name|SLIST_FIRST
parameter_list|(
name|head
parameter_list|)
value|((head)->slh_first)
end_define

begin_define
define|#
directive|define
name|SLIST_NEXT
parameter_list|(
name|elm
parameter_list|,
name|field
parameter_list|)
value|((elm)->field.sle_next)
end_define

begin_comment
comment|/*  * Singly-linked Tail queue declarations.  */
end_comment

begin_define
define|#
directive|define
name|STAILQ_HEAD
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
name|STAILQ_HEAD_INITIALIZER
parameter_list|(
name|head
parameter_list|)
define|\
value|{ NULL,&(head).stqh_first }
end_define

begin_define
define|#
directive|define
name|STAILQ_ENTRY
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
name|STAILQ_INIT
parameter_list|(
name|head
parameter_list|)
value|do {						\ 	(head)->stqh_first = NULL;					\ 	(head)->stqh_last =&(head)->stqh_first;				\ } while (
comment|/*CONSTCOND*/
value|0)
end_define

begin_define
define|#
directive|define
name|STAILQ_INSERT_HEAD
parameter_list|(
name|head
parameter_list|,
name|elm
parameter_list|,
name|field
parameter_list|)
value|do {			\ 	if (((elm)->field.stqe_next = (head)->stqh_first) == NULL)	\ 		(head)->stqh_last =&(elm)->field.stqe_next;		\ 	(head)->stqh_first = (elm);					\ } while (
comment|/*CONSTCOND*/
value|0)
end_define

begin_define
define|#
directive|define
name|STAILQ_INSERT_TAIL
parameter_list|(
name|head
parameter_list|,
name|elm
parameter_list|,
name|field
parameter_list|)
value|do {			\ 	(elm)->field.stqe_next = NULL;					\ 	*(head)->stqh_last = (elm);					\ 	(head)->stqh_last =&(elm)->field.stqe_next;			\ } while (
comment|/*CONSTCOND*/
value|0)
end_define

begin_define
define|#
directive|define
name|STAILQ_INSERT_AFTER
parameter_list|(
name|head
parameter_list|,
name|listelm
parameter_list|,
name|elm
parameter_list|,
name|field
parameter_list|)
value|do {		\ 	if (((elm)->field.stqe_next = (listelm)->field.stqe_next) == NULL)\ 		(head)->stqh_last =&(elm)->field.stqe_next;		\ 	(listelm)->field.stqe_next = (elm);				\ } while (
comment|/*CONSTCOND*/
value|0)
end_define

begin_define
define|#
directive|define
name|STAILQ_REMOVE_HEAD
parameter_list|(
name|head
parameter_list|,
name|field
parameter_list|)
value|do {				\ 	if (((head)->stqh_first = (head)->stqh_first->field.stqe_next) == NULL) \ 		(head)->stqh_last =&(head)->stqh_first;			\ } while (
comment|/*CONSTCOND*/
value|0)
end_define

begin_define
define|#
directive|define
name|STAILQ_REMOVE
parameter_list|(
name|head
parameter_list|,
name|elm
parameter_list|,
name|type
parameter_list|,
name|field
parameter_list|)
value|do {			\ 	if ((head)->stqh_first == (elm)) {				\ 		STAILQ_REMOVE_HEAD((head), field);			\ 	} else {							\ 		struct type *curelm = (head)->stqh_first;		\ 		while (curelm->field.stqe_next != (elm))			\ 			curelm = curelm->field.stqe_next;		\ 		if ((curelm->field.stqe_next =				\ 			curelm->field.stqe_next->field.stqe_next) == NULL) \ 			    (head)->stqh_last =&(curelm)->field.stqe_next; \ 	}								\ } while (
comment|/*CONSTCOND*/
value|0)
end_define

begin_define
define|#
directive|define
name|STAILQ_FOREACH
parameter_list|(
name|var
parameter_list|,
name|head
parameter_list|,
name|field
parameter_list|)
define|\
value|for ((var) = ((head)->stqh_first);				\ 		(var);							\ 		(var) = ((var)->field.stqe_next))
end_define

begin_comment
comment|/*  * Singly-linked Tail queue access methods.  */
end_comment

begin_define
define|#
directive|define
name|STAILQ_EMPTY
parameter_list|(
name|head
parameter_list|)
value|((head)->stqh_first == NULL)
end_define

begin_define
define|#
directive|define
name|STAILQ_FIRST
parameter_list|(
name|head
parameter_list|)
value|((head)->stqh_first)
end_define

begin_define
define|#
directive|define
name|STAILQ_NEXT
parameter_list|(
name|elm
parameter_list|,
name|field
parameter_list|)
value|((elm)->field.stqe_next)
end_define

begin_comment
comment|/*  * Simple queue definitions.  */
end_comment

begin_define
define|#
directive|define
name|SIMPLEQ_HEAD
parameter_list|(
name|name
parameter_list|,
name|type
parameter_list|)
define|\
value|struct name {								\ 	struct type *sqh_first;
comment|/* first element */
value|\ 	struct type **sqh_last;
comment|/* addr of last next element */
value|\ }
end_define

begin_define
define|#
directive|define
name|SIMPLEQ_HEAD_INITIALIZER
parameter_list|(
name|head
parameter_list|)
define|\
value|{ NULL,&(head).sqh_first }
end_define

begin_define
define|#
directive|define
name|SIMPLEQ_ENTRY
parameter_list|(
name|type
parameter_list|)
define|\
value|struct {								\ 	struct type *sqe_next;
comment|/* next element */
value|\ }
end_define

begin_comment
comment|/*  * Simple queue functions.  */
end_comment

begin_define
define|#
directive|define
name|SIMPLEQ_INIT
parameter_list|(
name|head
parameter_list|)
value|do {						\ 	(head)->sqh_first = NULL;					\ 	(head)->sqh_last =&(head)->sqh_first;				\ } while (
comment|/*CONSTCOND*/
value|0)
end_define

begin_define
define|#
directive|define
name|SIMPLEQ_INSERT_HEAD
parameter_list|(
name|head
parameter_list|,
name|elm
parameter_list|,
name|field
parameter_list|)
value|do {			\ 	if (((elm)->field.sqe_next = (head)->sqh_first) == NULL)	\ 		(head)->sqh_last =&(elm)->field.sqe_next;		\ 	(head)->sqh_first = (elm);					\ } while (
comment|/*CONSTCOND*/
value|0)
end_define

begin_define
define|#
directive|define
name|SIMPLEQ_INSERT_TAIL
parameter_list|(
name|head
parameter_list|,
name|elm
parameter_list|,
name|field
parameter_list|)
value|do {			\ 	(elm)->field.sqe_next = NULL;					\ 	*(head)->sqh_last = (elm);					\ 	(head)->sqh_last =&(elm)->field.sqe_next;			\ } while (
comment|/*CONSTCOND*/
value|0)
end_define

begin_define
define|#
directive|define
name|SIMPLEQ_INSERT_AFTER
parameter_list|(
name|head
parameter_list|,
name|listelm
parameter_list|,
name|elm
parameter_list|,
name|field
parameter_list|)
value|do {		\ 	if (((elm)->field.sqe_next = (listelm)->field.sqe_next) == NULL)\ 		(head)->sqh_last =&(elm)->field.sqe_next;		\ 	(listelm)->field.sqe_next = (elm);				\ } while (
comment|/*CONSTCOND*/
value|0)
end_define

begin_define
define|#
directive|define
name|SIMPLEQ_REMOVE_HEAD
parameter_list|(
name|head
parameter_list|,
name|field
parameter_list|)
value|do {				\ 	if (((head)->sqh_first = (head)->sqh_first->field.sqe_next) == NULL) \ 		(head)->sqh_last =&(head)->sqh_first;			\ } while (
comment|/*CONSTCOND*/
value|0)
end_define

begin_define
define|#
directive|define
name|SIMPLEQ_REMOVE
parameter_list|(
name|head
parameter_list|,
name|elm
parameter_list|,
name|type
parameter_list|,
name|field
parameter_list|)
value|do {			\ 	if ((head)->sqh_first == (elm)) {				\ 		SIMPLEQ_REMOVE_HEAD((head), field);			\ 	} else {							\ 		struct type *curelm = (head)->sqh_first;		\ 		while (curelm->field.sqe_next != (elm))			\ 			curelm = curelm->field.sqe_next;		\ 		if ((curelm->field.sqe_next =				\ 			curelm->field.sqe_next->field.sqe_next) == NULL) \ 			    (head)->sqh_last =&(curelm)->field.sqe_next; \ 	}								\ } while (
comment|/*CONSTCOND*/
value|0)
end_define

begin_define
define|#
directive|define
name|SIMPLEQ_FOREACH
parameter_list|(
name|var
parameter_list|,
name|head
parameter_list|,
name|field
parameter_list|)
define|\
value|for ((var) = ((head)->sqh_first);				\ 		(var);							\ 		(var) = ((var)->field.sqe_next))
end_define

begin_comment
comment|/*  * Simple queue access methods.  */
end_comment

begin_define
define|#
directive|define
name|SIMPLEQ_EMPTY
parameter_list|(
name|head
parameter_list|)
value|((head)->sqh_first == NULL)
end_define

begin_define
define|#
directive|define
name|SIMPLEQ_FIRST
parameter_list|(
name|head
parameter_list|)
value|((head)->sqh_first)
end_define

begin_define
define|#
directive|define
name|SIMPLEQ_NEXT
parameter_list|(
name|elm
parameter_list|,
name|field
parameter_list|)
value|((elm)->field.sqe_next)
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
name|TAILQ_HEAD_INITIALIZER
parameter_list|(
name|head
parameter_list|)
define|\
value|{ NULL,&(head).tqh_first }
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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|&&
name|defined
argument_list|(
name|QUEUEDEBUG
argument_list|)
end_if

begin_define
define|#
directive|define
name|QUEUEDEBUG_TAILQ_INSERT_HEAD
parameter_list|(
name|head
parameter_list|,
name|elm
parameter_list|,
name|field
parameter_list|)
define|\
value|if ((head)->tqh_first&&					\ 	    (head)->tqh_first->field.tqe_prev !=&(head)->tqh_first)	\ 		panic("TAILQ_INSERT_HEAD %p %s:%d", (head), __FILE__, __LINE__);
end_define

begin_define
define|#
directive|define
name|QUEUEDEBUG_TAILQ_INSERT_TAIL
parameter_list|(
name|head
parameter_list|,
name|elm
parameter_list|,
name|field
parameter_list|)
define|\
value|if (*(head)->tqh_last != NULL)					\ 		panic("TAILQ_INSERT_TAIL %p %s:%d", (head), __FILE__, __LINE__);
end_define

begin_define
define|#
directive|define
name|QUEUEDEBUG_TAILQ_OP
parameter_list|(
name|elm
parameter_list|,
name|field
parameter_list|)
define|\
value|if ((elm)->field.tqe_next&&					\ 	    (elm)->field.tqe_next->field.tqe_prev !=			\&(elm)->field.tqe_next)					\ 		panic("TAILQ_* forw %p %s:%d", (elm), __FILE__, __LINE__);\ 	if (*(elm)->field.tqe_prev != (elm))				\ 		panic("TAILQ_* back %p %s:%d", (elm), __FILE__, __LINE__);
end_define

begin_define
define|#
directive|define
name|QUEUEDEBUG_TAILQ_PREREMOVE
parameter_list|(
name|head
parameter_list|,
name|elm
parameter_list|,
name|field
parameter_list|)
define|\
value|if ((elm)->field.tqe_next == NULL&&				\ 	    (head)->tqh_last !=&(elm)->field.tqe_next)			\ 		panic("TAILQ_PREREMOVE head %p elm %p %s:%d",		\ 		      (head), (elm), __FILE__, __LINE__);
end_define

begin_define
define|#
directive|define
name|QUEUEDEBUG_TAILQ_POSTREMOVE
parameter_list|(
name|elm
parameter_list|,
name|field
parameter_list|)
define|\
value|(elm)->field.tqe_next = (void *)1L;				\ 	(elm)->field.tqe_prev = (void *)1L;
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|QUEUEDEBUG_TAILQ_INSERT_HEAD
parameter_list|(
name|head
parameter_list|,
name|elm
parameter_list|,
name|field
parameter_list|)
end_define

begin_define
define|#
directive|define
name|QUEUEDEBUG_TAILQ_INSERT_TAIL
parameter_list|(
name|head
parameter_list|,
name|elm
parameter_list|,
name|field
parameter_list|)
end_define

begin_define
define|#
directive|define
name|QUEUEDEBUG_TAILQ_OP
parameter_list|(
name|elm
parameter_list|,
name|field
parameter_list|)
end_define

begin_define
define|#
directive|define
name|QUEUEDEBUG_TAILQ_PREREMOVE
parameter_list|(
name|head
parameter_list|,
name|elm
parameter_list|,
name|field
parameter_list|)
end_define

begin_define
define|#
directive|define
name|QUEUEDEBUG_TAILQ_POSTREMOVE
parameter_list|(
name|elm
parameter_list|,
name|field
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TAILQ_INIT
parameter_list|(
name|head
parameter_list|)
value|do {						\ 	(head)->tqh_first = NULL;					\ 	(head)->tqh_last =&(head)->tqh_first;				\ } while (
comment|/*CONSTCOND*/
value|0)
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
value|do {			\ 	QUEUEDEBUG_TAILQ_INSERT_HEAD((head), (elm), field)		\ 	if (((elm)->field.tqe_next = (head)->tqh_first) != NULL)	\ 		(head)->tqh_first->field.tqe_prev =			\&(elm)->field.tqe_next;				\ 	else								\ 		(head)->tqh_last =&(elm)->field.tqe_next;		\ 	(head)->tqh_first = (elm);					\ 	(elm)->field.tqe_prev =&(head)->tqh_first;			\ } while (
comment|/*CONSTCOND*/
value|0)
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
value|do {			\ 	QUEUEDEBUG_TAILQ_INSERT_TAIL((head), (elm), field)		\ 	(elm)->field.tqe_next = NULL;					\ 	(elm)->field.tqe_prev = (head)->tqh_last;			\ 	*(head)->tqh_last = (elm);					\ 	(head)->tqh_last =&(elm)->field.tqe_next;			\ } while (
comment|/*CONSTCOND*/
value|0)
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
value|do {		\ 	QUEUEDEBUG_TAILQ_OP((listelm), field)				\ 	if (((elm)->field.tqe_next = (listelm)->field.tqe_next) != NULL)\ 		(elm)->field.tqe_next->field.tqe_prev = 		\&(elm)->field.tqe_next;				\ 	else								\ 		(head)->tqh_last =&(elm)->field.tqe_next;		\ 	(listelm)->field.tqe_next = (elm);				\ 	(elm)->field.tqe_prev =&(listelm)->field.tqe_next;		\ } while (
comment|/*CONSTCOND*/
value|0)
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
value|do {			\ 	QUEUEDEBUG_TAILQ_OP((listelm), field)				\ 	(elm)->field.tqe_prev = (listelm)->field.tqe_prev;		\ 	(elm)->field.tqe_next = (listelm);				\ 	*(listelm)->field.tqe_prev = (elm);				\ 	(listelm)->field.tqe_prev =&(elm)->field.tqe_next;		\ } while (
comment|/*CONSTCOND*/
value|0)
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
value|do {				\ 	QUEUEDEBUG_TAILQ_PREREMOVE((head), (elm), field)		\ 	QUEUEDEBUG_TAILQ_OP((elm), field)				\ 	if (((elm)->field.tqe_next) != NULL)				\ 		(elm)->field.tqe_next->field.tqe_prev = 		\ 		    (elm)->field.tqe_prev;				\ 	else								\ 		(head)->tqh_last = (elm)->field.tqe_prev;		\ 	*(elm)->field.tqe_prev = (elm)->field.tqe_next;			\ 	QUEUEDEBUG_TAILQ_POSTREMOVE((elm), field);			\ } while (
comment|/*CONSTCOND*/
value|0)
end_define

begin_define
define|#
directive|define
name|TAILQ_FOREACH
parameter_list|(
name|var
parameter_list|,
name|head
parameter_list|,
name|field
parameter_list|)
define|\
value|for ((var) = ((head)->tqh_first);				\ 		(var);							\ 		(var) = ((var)->field.tqe_next))
end_define

begin_define
define|#
directive|define
name|TAILQ_FOREACH_REVERSE
parameter_list|(
name|var
parameter_list|,
name|head
parameter_list|,
name|headname
parameter_list|,
name|field
parameter_list|)
define|\
value|for ((var) = (*(((struct headname *)((head)->tqh_last))->tqh_last));	\ 		(var);							\ 		(var) = (*(((struct headname *)((var)->field.tqe_prev))->tqh_last)))
end_define

begin_comment
comment|/*  * Tail queue access methods.  */
end_comment

begin_define
define|#
directive|define
name|TAILQ_EMPTY
parameter_list|(
name|head
parameter_list|)
value|((head)->tqh_first == NULL)
end_define

begin_define
define|#
directive|define
name|TAILQ_FIRST
parameter_list|(
name|head
parameter_list|)
value|((head)->tqh_first)
end_define

begin_define
define|#
directive|define
name|TAILQ_NEXT
parameter_list|(
name|elm
parameter_list|,
name|field
parameter_list|)
value|((elm)->field.tqe_next)
end_define

begin_define
define|#
directive|define
name|TAILQ_LAST
parameter_list|(
name|head
parameter_list|,
name|headname
parameter_list|)
define|\
value|(*(((struct headname *)((head)->tqh_last))->tqh_last))
end_define

begin_define
define|#
directive|define
name|TAILQ_PREV
parameter_list|(
name|elm
parameter_list|,
name|headname
parameter_list|,
name|field
parameter_list|)
define|\
value|(*(((struct headname *)((elm)->field.tqe_prev))->tqh_last))
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
name|CIRCLEQ_HEAD_INITIALIZER
parameter_list|(
name|head
parameter_list|)
define|\
value|{ (void *)&head, (void *)&head }
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
value|do {						\ 	(head)->cqh_first = (void *)(head);				\ 	(head)->cqh_last = (void *)(head);				\ } while (
comment|/*CONSTCOND*/
value|0)
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
value|do {		\ 	(elm)->field.cqe_next = (listelm)->field.cqe_next;		\ 	(elm)->field.cqe_prev = (listelm);				\ 	if ((listelm)->field.cqe_next == (void *)(head))		\ 		(head)->cqh_last = (elm);				\ 	else								\ 		(listelm)->field.cqe_next->field.cqe_prev = (elm);	\ 	(listelm)->field.cqe_next = (elm);				\ } while (
comment|/*CONSTCOND*/
value|0)
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
value|do {		\ 	(elm)->field.cqe_next = (listelm);				\ 	(elm)->field.cqe_prev = (listelm)->field.cqe_prev;		\ 	if ((listelm)->field.cqe_prev == (void *)(head))		\ 		(head)->cqh_first = (elm);				\ 	else								\ 		(listelm)->field.cqe_prev->field.cqe_next = (elm);	\ 	(listelm)->field.cqe_prev = (elm);				\ } while (
comment|/*CONSTCOND*/
value|0)
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
value|do {			\ 	(elm)->field.cqe_next = (head)->cqh_first;			\ 	(elm)->field.cqe_prev = (void *)(head);				\ 	if ((head)->cqh_last == (void *)(head))				\ 		(head)->cqh_last = (elm);				\ 	else								\ 		(head)->cqh_first->field.cqe_prev = (elm);		\ 	(head)->cqh_first = (elm);					\ } while (
comment|/*CONSTCOND*/
value|0)
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
value|do {			\ 	(elm)->field.cqe_next = (void *)(head);				\ 	(elm)->field.cqe_prev = (head)->cqh_last;			\ 	if ((head)->cqh_first == (void *)(head))			\ 		(head)->cqh_first = (elm);				\ 	else								\ 		(head)->cqh_last->field.cqe_next = (elm);		\ 	(head)->cqh_last = (elm);					\ } while (
comment|/*CONSTCOND*/
value|0)
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
value|do {				\ 	if ((elm)->field.cqe_next == (void *)(head))			\ 		(head)->cqh_last = (elm)->field.cqe_prev;		\ 	else								\ 		(elm)->field.cqe_next->field.cqe_prev =			\ 		    (elm)->field.cqe_prev;				\ 	if ((elm)->field.cqe_prev == (void *)(head))			\ 		(head)->cqh_first = (elm)->field.cqe_next;		\ 	else								\ 		(elm)->field.cqe_prev->field.cqe_next =			\ 		    (elm)->field.cqe_next;				\ } while (
comment|/*CONSTCOND*/
value|0)
end_define

begin_define
define|#
directive|define
name|CIRCLEQ_FOREACH
parameter_list|(
name|var
parameter_list|,
name|head
parameter_list|,
name|field
parameter_list|)
define|\
value|for ((var) = ((head)->cqh_first);				\ 		(var) != (void *)(head);				\ 		(var) = ((var)->field.cqe_next))
end_define

begin_define
define|#
directive|define
name|CIRCLEQ_FOREACH_REVERSE
parameter_list|(
name|var
parameter_list|,
name|head
parameter_list|,
name|field
parameter_list|)
define|\
value|for ((var) = ((head)->cqh_last);				\ 		(var) != (void *)(head);				\ 		(var) = ((var)->field.cqe_prev))
end_define

begin_comment
comment|/*  * Circular queue access methods.  */
end_comment

begin_define
define|#
directive|define
name|CIRCLEQ_EMPTY
parameter_list|(
name|head
parameter_list|)
value|((head)->cqh_first == (void *)(head))
end_define

begin_define
define|#
directive|define
name|CIRCLEQ_FIRST
parameter_list|(
name|head
parameter_list|)
value|((head)->cqh_first)
end_define

begin_define
define|#
directive|define
name|CIRCLEQ_LAST
parameter_list|(
name|head
parameter_list|)
value|((head)->cqh_last)
end_define

begin_define
define|#
directive|define
name|CIRCLEQ_NEXT
parameter_list|(
name|elm
parameter_list|,
name|field
parameter_list|)
value|((elm)->field.cqe_next)
end_define

begin_define
define|#
directive|define
name|CIRCLEQ_PREV
parameter_list|(
name|elm
parameter_list|,
name|field
parameter_list|)
value|((elm)->field.cqe_prev)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_QUEUE_H_ */
end_comment

end_unit

