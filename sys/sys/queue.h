begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)queue.h	8.5 (Berkeley) 8/20/94  * $FreeBSD$  */
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

begin_include
include|#
directive|include
file|<struct.h>
end_include

begin_comment
comment|/*  * This file defines five types of data structures: singly-linked lists,  * singly-linked tail queues, lists, tail queues, and circular queues.  *  * A singly-linked list is headed by a single forward pointer. The elements  * are singly linked for minimum space and pointer manipulation overhead at  * the expense of O(n) removal for arbitrary elements. New elements can be  * added to the list after an existing element or at the head of the list.  * Elements being removed from the head of the list should use the explicit  * macro for this purpose for optimum efficiency. A singly-linked list may  * only be traversed in the forward direction.  Singly-linked lists are ideal  * for applications with large datasets and few or no removals or for  * implementing a LIFO queue.  *  * A singly-linked tail queue is headed by a pair of pointers, one to the  * head of the list and the other to the tail of the list. The elements are  * singly linked for minimum space and pointer manipulation overhead at the  * expense of O(n) removal for arbitrary elements. New elements can be added  * to the list after an existing element, at the head of the list, or at the  * end of the list. Elements being removed from the head of the tail queue  * should use the explicit macro for this purpose for optimum efficiency.  * A singly-linked tail queue may only be traversed in the forward direction.  * Singly-linked tail queues are ideal for applications with large datasets  * and few or no removals or for implementing a FIFO queue.  *  * A list is headed by a single forward pointer (or an array of forward  * pointers for a hash table header). The elements are doubly linked  * so that an arbitrary element can be removed without a need to  * traverse the list. New elements can be added to the list before  * or after an existing element or at the head of the list. A list  * may only be traversed in the forward direction.  *  * A tail queue is headed by a pair of pointers, one to the head of the  * list and the other to the tail of the list. The elements are doubly  * linked so that an arbitrary element can be removed without a need to  * traverse the list. New elements can be added to the list before or  * after an existing element, at the head of the list, or at the end of  * the list. A tail queue may be traversed in either direction.  *  * A circle queue is headed by a pair of pointers, one to the head of the  * list and the other to the tail of the list. The elements are doubly  * linked so that an arbitrary element can be removed without a need to  * traverse the list. New elements can be added to the list before or after  * an existing element, at the head of the list, or at the end of the list.  * A circle queue may be traversed in either direction, but has a more  * complex end of list detection.  *  * For details on the use of these macros, see the queue(3) manual page.  *  *  *			SLIST	LIST	STAILQ	TAILQ	CIRCLEQ  * _HEAD		+	+	+	+	+  * _HEAD_INITIALIZER	+	+	+	+	+  * _ENTRY		+	+	+	+	+  * _INIT		+	+	+	+	+  * _EMPTY		+	+	+	+	+  * _FIRST		+	+	+	+	+  * _NEXT		+	+	+	+	+  * _PREV		-	-	-	+	+  * _LAST		-	-	+	+	+  * _FOREACH		+	+	+	+	+  * _FOREACH_REVERSE	-	-	-	+	+  * _INSERT_HEAD		+	+	+	+	+  * _INSERT_BEFORE	-	+	-	+	+  * _INSERT_AFTER	+	+	+	+	+  * _INSERT_TAIL		-	-	+	+	+  * _REMOVE_HEAD		+	-	+	-	-  * _REMOVE		+	+	+	+	+  *  */
end_comment

begin_comment
comment|/*  * Singly-linked List declarations.  */
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
name|SLIST_FOREACH
parameter_list|(
name|var
parameter_list|,
name|head
parameter_list|,
name|field
parameter_list|)
define|\
value|for ((var) = SLIST_FIRST((head));				\ 	    (var);							\ 	    (var) = SLIST_NEXT((var), field))
end_define

begin_define
define|#
directive|define
name|SLIST_INIT
parameter_list|(
name|head
parameter_list|)
value|do {						\ 	SLIST_FIRST((head)) = NULL;					\ } while (0)
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
value|do {			\ 	SLIST_NEXT((elm), field) = SLIST_NEXT((slistelm), field);	\ 	SLIST_NEXT((slistelm), field) = (elm);				\ } while (0)
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
value|do {			\ 	SLIST_NEXT((elm), field) = SLIST_FIRST((head));			\ 	SLIST_FIRST((head)) = (elm);					\ } while (0)
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
value|do {			\ 	if (SLIST_FIRST((head)) == (elm)) {				\ 		SLIST_REMOVE_HEAD((head), field);			\ 	}								\ 	else {								\ 		struct type *curelm = SLIST_FIRST((head));		\ 		while (SLIST_NEXT(curelm, field) != (elm))		\ 			curelm = SLIST_NEXT(curelm, field);		\ 		SLIST_NEXT(curelm, field) =				\ 		    SLIST_NEXT(SLIST_NEXT(curelm, field), field);	\ 	}								\ } while (0)
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
value|do {				\ 	SLIST_FIRST((head)) = SLIST_NEXT(SLIST_FIRST((head)), field);	\ } while (0)
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
name|STAILQ_FOREACH
parameter_list|(
name|var
parameter_list|,
name|head
parameter_list|,
name|field
parameter_list|)
define|\
value|for((var) = STAILQ_FIRST((head));				\ 	   (var);							\ 	   (var) = STAILQ_NEXT((var), field))
end_define

begin_define
define|#
directive|define
name|STAILQ_INIT
parameter_list|(
name|head
parameter_list|)
value|do {						\ 	STAILQ_FIRST((head)) = NULL;					\ 	(head)->stqh_last =&STAILQ_FIRST((head));			\ } while (0)
end_define

begin_define
define|#
directive|define
name|STAILQ_INSERT_AFTER
parameter_list|(
name|head
parameter_list|,
name|tqelm
parameter_list|,
name|elm
parameter_list|,
name|field
parameter_list|)
value|do {		\ 	if ((STAILQ_NEXT((elm), field) = STAILQ_NEXT((tqelm), field)) == NULL)\ 		(head)->stqh_last =&STAILQ_NEXT((elm), field);		\ 	STAILQ_NEXT((tqelm), field) = (elm);				\ } while (0)
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
value|do {			\ 	if ((STAILQ_NEXT((elm), field) = STAILQ_FIRST((head))) == NULL)	\ 		(head)->stqh_last =&STAILQ_NEXT((elm), field);		\ 	STAILQ_FIRST((head)) = (elm);					\ } while (0)
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
value|do {			\ 	STAILQ_NEXT((elm), field) = NULL;				\ 	*(head)->stqh_last = (elm);					\ 	(head)->stqh_last =&STAILQ_NEXT((elm), field);			\ } while (0)
end_define

begin_define
define|#
directive|define
name|STAILQ_LAST
parameter_list|(
name|head
parameter_list|,
name|type
parameter_list|,
name|field
parameter_list|)
define|\
value|(STAILQ_EMPTY(head) ?						\ 		NULL :							\ 		strbase(type, (head)->stqh_last, field))
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
value|do {			\ 	if (STAILQ_FIRST((head)) == (elm)) {				\ 		STAILQ_REMOVE_HEAD(head, field);			\ 	}								\ 	else {								\ 		struct type *curelm = STAILQ_FIRST((head));		\ 		while (STAILQ_NEXT(curelm, field) != (elm))		\ 			curelm = STAILQ_NEXT(curelm, field);		\ 		if ((STAILQ_NEXT(curelm, field) =			\ 		     STAILQ_NEXT(STAILQ_NEXT(curelm, field), field)) == NULL)\ 			(head)->stqh_last =&STAILQ_NEXT((curelm), field);\ 	}								\ } while (0)
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
value|do {				\ 	if ((STAILQ_FIRST((head)) =					\ 	     STAILQ_NEXT(STAILQ_FIRST((head)), field)) == NULL)		\ 		(head)->stqh_last =&STAILQ_FIRST((head));		\ } while (0)
end_define

begin_define
define|#
directive|define
name|STAILQ_REMOVE_HEAD_UNTIL
parameter_list|(
name|head
parameter_list|,
name|elm
parameter_list|,
name|field
parameter_list|)
value|do {			\ 	if ((STAILQ_FIRST((head)) = STAILQ_NEXT((elm), field)) == NULL)	\ 		(head)->stqh_last =&STAILQ_FIRST((head));		\ } while (0)
end_define

begin_comment
comment|/*  * List declarations.  */
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
name|LIST_FOREACH
parameter_list|(
name|var
parameter_list|,
name|head
parameter_list|,
name|field
parameter_list|)
define|\
value|for ((var) = LIST_FIRST((head));				\ 	    (var);							\ 	    (var) = LIST_NEXT((var), field))
end_define

begin_define
define|#
directive|define
name|LIST_INIT
parameter_list|(
name|head
parameter_list|)
value|do {						\ 	LIST_FIRST((head)) = NULL;					\ } while (0)
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
value|do {			\ 	if ((LIST_NEXT((elm), field) = LIST_NEXT((listelm), field)) != NULL)\ 		LIST_NEXT((listelm), field)->field.le_prev =		\&LIST_NEXT((elm), field);				\ 	LIST_NEXT((listelm), field) = (elm);				\ 	(elm)->field.le_prev =&LIST_NEXT((listelm), field);		\ } while (0)
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
value|do {			\ 	(elm)->field.le_prev = (listelm)->field.le_prev;		\ 	LIST_NEXT((elm), field) = (listelm);				\ 	*(listelm)->field.le_prev = (elm);				\ 	(listelm)->field.le_prev =&LIST_NEXT((elm), field);		\ } while (0)
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
value|do {				\ 	if ((LIST_NEXT((elm), field) = LIST_FIRST((head))) != NULL)	\ 		LIST_FIRST((head))->field.le_prev =&LIST_NEXT((elm), field);\ 	LIST_FIRST((head)) = (elm);					\ 	(elm)->field.le_prev =&LIST_FIRST((head));			\ } while (0)
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

begin_define
define|#
directive|define
name|LIST_REMOVE
parameter_list|(
name|elm
parameter_list|,
name|field
parameter_list|)
value|do {					\ 	if (LIST_NEXT((elm), field) != NULL)				\ 		LIST_NEXT((elm), field)->field.le_prev = 		\ 		    (elm)->field.le_prev;				\ 	*(elm)->field.le_prev = LIST_NEXT((elm), field);		\ } while (0)
end_define

begin_comment
comment|/*  * Tail queue declarations.  */
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
name|TAILQ_FOREACH
parameter_list|(
name|var
parameter_list|,
name|head
parameter_list|,
name|field
parameter_list|)
define|\
value|for ((var) = TAILQ_FIRST((head));				\ 	    (var);							\ 	    (var) = TAILQ_NEXT((var), field))
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
value|for ((var) = TAILQ_LAST((head), headname);			\ 	    (var);							\ 	    (var) = TAILQ_PREV((var), headname, field))
end_define

begin_define
define|#
directive|define
name|TAILQ_INIT
parameter_list|(
name|head
parameter_list|)
value|do {						\ 	TAILQ_FIRST((head)) = NULL;					\ 	(head)->tqh_last =&TAILQ_FIRST((head));			\ } while (0)
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
value|do {		\ 	if ((TAILQ_NEXT((elm), field) = TAILQ_NEXT((listelm), field)) != NULL)\ 		TAILQ_NEXT((elm), field)->field.tqe_prev = 		\&TAILQ_NEXT((elm), field);				\ 	else								\ 		(head)->tqh_last =&TAILQ_NEXT((elm), field);		\ 	TAILQ_NEXT((listelm), field) = (elm);				\ 	(elm)->field.tqe_prev =&TAILQ_NEXT((listelm), field);		\ } while (0)
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
value|do {			\ 	(elm)->field.tqe_prev = (listelm)->field.tqe_prev;		\ 	TAILQ_NEXT((elm), field) = (listelm);				\ 	*(listelm)->field.tqe_prev = (elm);				\ 	(listelm)->field.tqe_prev =&TAILQ_NEXT((elm), field);		\ } while (0)
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
value|do {			\ 	if ((TAILQ_NEXT((elm), field) = TAILQ_FIRST((head))) != NULL)	\ 		TAILQ_FIRST((head))->field.tqe_prev =			\&TAILQ_NEXT((elm), field);				\ 	else								\ 		(head)->tqh_last =&TAILQ_NEXT((elm), field);		\ 	TAILQ_FIRST((head)) = (elm);					\ 	(elm)->field.tqe_prev =&TAILQ_FIRST((head));			\ } while (0)
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
value|do {			\ 	TAILQ_NEXT((elm), field) = NULL;				\ 	(elm)->field.tqe_prev = (head)->tqh_last;			\ 	*(head)->tqh_last = (elm);					\ 	(head)->tqh_last =&TAILQ_NEXT((elm), field);			\ } while (0)
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
value|do {				\ 	if ((TAILQ_NEXT((elm), field)) != NULL)				\ 		TAILQ_NEXT((elm), field)->field.tqe_prev = 		\ 		    (elm)->field.tqe_prev;				\ 	else								\ 		(head)->tqh_last = (elm)->field.tqe_prev;		\ 	*(elm)->field.tqe_prev = TAILQ_NEXT((elm), field);		\ } while (0)
end_define

begin_comment
comment|/*  * Circular queue declarations.  */
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
value|{ (void *)&(head), (void *)&(head) }
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
name|CIRCLEQ_FOREACH
parameter_list|(
name|var
parameter_list|,
name|head
parameter_list|,
name|field
parameter_list|)
define|\
value|for ((var) = CIRCLEQ_FIRST((head));				\ 	    (var) != (void *)(head);					\ 	    (var) = CIRCLEQ_NEXT((var), field))
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
value|for ((var) = CIRCLEQ_LAST((head));				\ 	    (var) != (void *)(head);					\ 	    (var) = CIRCLEQ_PREV((var), field))
end_define

begin_define
define|#
directive|define
name|CIRCLEQ_INIT
parameter_list|(
name|head
parameter_list|)
value|do {						\ 	CIRCLEQ_FIRST((head)) = (void *)(head);				\ 	CIRCLEQ_LAST((head)) = (void *)(head);				\ } while (0)
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
value|do {		\ 	CIRCLEQ_NEXT((elm), field) = CIRCLEQ_NEXT((listelm), field);	\ 	CIRCLEQ_PREV((elm), field) = (listelm);				\ 	if (CIRCLEQ_NEXT((listelm), field) == (void *)(head))		\ 		CIRCLEQ_LAST((head)) = (elm);				\ 	else								\ 		CIRCLEQ_PREV(CIRCLEQ_NEXT((listelm), field), field) = (elm);\ 	CIRCLEQ_NEXT((listelm), field) = (elm);				\ } while (0)
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
value|do {		\ 	CIRCLEQ_NEXT((elm), field) = (listelm);				\ 	CIRCLEQ_PREV((elm), field) = CIRCLEQ_PREV((listelm), field);	\ 	if (CIRCLEQ_PREV((listelm), field) == (void *)(head))		\ 		CIRCLEQ_FIRST((head)) = (elm);				\ 	else								\ 		CIRCLEQ_NEXT(CIRCLEQ_PREV((listelm), field), field) = (elm);\ 	CIRCLEQ_PREV((listelm), field) = (elm);				\ } while (0)
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
value|do {			\ 	CIRCLEQ_NEXT((elm), field) = CIRCLEQ_FIRST((head));		\ 	CIRCLEQ_PREV((elm), field) = (void *)(head);			\ 	if (CIRCLEQ_LAST((head)) == (void *)(head))			\ 		CIRCLEQ_LAST((head)) = (elm);				\ 	else								\ 		CIRCLEQ_PREV(CIRCLEQ_FIRST((head)), field) = (elm);	\ 	CIRCLEQ_FIRST((head)) = (elm);					\ } while (0)
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
value|do {			\ 	CIRCLEQ_NEXT((elm), field) = (void *)(head);			\ 	CIRCLEQ_PREV((elm), field) = CIRCLEQ_LAST((head));		\ 	if (CIRCLEQ_FIRST((head)) == (void *)(head))			\ 		CIRCLEQ_FIRST((head)) = (elm);				\ 	else								\ 		CIRCLEQ_NEXT(CIRCLEQ_LAST((head)), field) = (elm);	\ 	CIRCLEQ_LAST((head)) = (elm);					\ } while (0)
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
value|do {				\ 	if (CIRCLEQ_NEXT((elm), field) == (void *)(head))		\ 		CIRCLEQ_LAST((head)) = CIRCLEQ_PREV((elm), field);	\ 	else								\ 		CIRCLEQ_PREV(CIRCLEQ_NEXT((elm), field), field) =	\ 		    CIRCLEQ_PREV((elm), field);				\ 	if (CIRCLEQ_PREV((elm), field) == (void *)(head))		\ 		CIRCLEQ_FIRST((head)) = CIRCLEQ_NEXT((elm), field);	\ 	else								\ 		CIRCLEQ_NEXT(CIRCLEQ_PREV((elm), field), field) =	\ 		    CIRCLEQ_NEXT((elm), field);				\ } while (0)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * XXX insque() and remque() are an old way of handling certain queues.  * They bogusly assumes that all queue heads look alike.  */
end_comment

begin_struct
struct|struct
name|quehead
block|{
name|struct
name|quehead
modifier|*
name|qh_link
decl_stmt|;
name|struct
name|quehead
modifier|*
name|qh_rlink
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_function
specifier|static
name|__inline
name|void
name|insque
parameter_list|(
name|void
modifier|*
name|a
parameter_list|,
name|void
modifier|*
name|b
parameter_list|)
block|{
name|struct
name|quehead
modifier|*
name|element
init|=
name|a
decl_stmt|,
modifier|*
name|head
init|=
name|b
decl_stmt|;
name|element
operator|->
name|qh_link
operator|=
name|head
operator|->
name|qh_link
expr_stmt|;
name|element
operator|->
name|qh_rlink
operator|=
name|head
expr_stmt|;
name|head
operator|->
name|qh_link
operator|=
name|element
expr_stmt|;
name|element
operator|->
name|qh_link
operator|->
name|qh_rlink
operator|=
name|element
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|remque
parameter_list|(
name|void
modifier|*
name|a
parameter_list|)
block|{
name|struct
name|quehead
modifier|*
name|element
init|=
name|a
decl_stmt|;
name|element
operator|->
name|qh_link
operator|->
name|qh_rlink
operator|=
name|element
operator|->
name|qh_rlink
expr_stmt|;
name|element
operator|->
name|qh_rlink
operator|->
name|qh_link
operator|=
name|element
operator|->
name|qh_link
expr_stmt|;
name|element
operator|->
name|qh_rlink
operator|=
literal|0
expr_stmt|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !__GNUC__ */
end_comment

begin_decl_stmt
name|void
name|insque
name|__P
argument_list|(
operator|(
name|void
operator|*
name|a
operator|,
name|void
operator|*
name|b
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|remque
name|__P
argument_list|(
operator|(
name|void
operator|*
name|a
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GNUC__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_QUEUE_H_ */
end_comment

end_unit

