begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: queue.h,v 1.38 2004/04/18 14:12:05 lukem Exp $	*/
end_comment

begin_comment
comment|/*	$Id$ */
end_comment

begin_comment
comment|/*  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)queue.h	8.5 (Berkeley) 8/20/94  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ASN1_QUEUE_H_
end_ifndef

begin_define
define|#
directive|define
name|_ASN1_QUEUE_H_
end_define

begin_comment
comment|/*  * Tail queue definitions.  */
end_comment

begin_define
define|#
directive|define
name|ASN1_TAILQ_HEAD
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
name|ASN1_TAILQ_HEAD_INITIALIZER
parameter_list|(
name|head
parameter_list|)
define|\
value|{ NULL,&(head).tqh_first }
end_define

begin_define
define|#
directive|define
name|ASN1_TAILQ_ENTRY
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
name|QUEUEDEBUG_ASN1_TAILQ_INSERT_HEAD
parameter_list|(
name|head
parameter_list|,
name|elm
parameter_list|,
name|field
parameter_list|)
define|\
value|if ((head)->tqh_first&&					\ 	    (head)->tqh_first->field.tqe_prev !=&(head)->tqh_first)	\ 		panic("ASN1_TAILQ_INSERT_HEAD %p %s:%d", (head), __FILE__, __LINE__);
end_define

begin_define
define|#
directive|define
name|QUEUEDEBUG_ASN1_TAILQ_INSERT_TAIL
parameter_list|(
name|head
parameter_list|,
name|elm
parameter_list|,
name|field
parameter_list|)
define|\
value|if (*(head)->tqh_last != NULL)					\ 		panic("ASN1_TAILQ_INSERT_TAIL %p %s:%d", (head), __FILE__, __LINE__);
end_define

begin_define
define|#
directive|define
name|QUEUEDEBUG_ASN1_TAILQ_OP
parameter_list|(
name|elm
parameter_list|,
name|field
parameter_list|)
define|\
value|if ((elm)->field.tqe_next&&					\ 	    (elm)->field.tqe_next->field.tqe_prev !=			\&(elm)->field.tqe_next)					\ 		panic("ASN1_TAILQ_* forw %p %s:%d", (elm), __FILE__, __LINE__);\ 	if (*(elm)->field.tqe_prev != (elm))				\ 		panic("ASN1_TAILQ_* back %p %s:%d", (elm), __FILE__, __LINE__);
end_define

begin_define
define|#
directive|define
name|QUEUEDEBUG_ASN1_TAILQ_PREREMOVE
parameter_list|(
name|head
parameter_list|,
name|elm
parameter_list|,
name|field
parameter_list|)
define|\
value|if ((elm)->field.tqe_next == NULL&&				\ 	    (head)->tqh_last !=&(elm)->field.tqe_next)			\ 		panic("ASN1_TAILQ_PREREMOVE head %p elm %p %s:%d",	\ 		      (head), (elm), __FILE__, __LINE__);
end_define

begin_define
define|#
directive|define
name|QUEUEDEBUG_ASN1_TAILQ_POSTREMOVE
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
name|QUEUEDEBUG_ASN1_TAILQ_INSERT_HEAD
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
name|QUEUEDEBUG_ASN1_TAILQ_INSERT_TAIL
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
name|QUEUEDEBUG_ASN1_TAILQ_OP
parameter_list|(
name|elm
parameter_list|,
name|field
parameter_list|)
end_define

begin_define
define|#
directive|define
name|QUEUEDEBUG_ASN1_TAILQ_PREREMOVE
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
name|QUEUEDEBUG_ASN1_TAILQ_POSTREMOVE
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
name|ASN1_TAILQ_INIT
parameter_list|(
name|head
parameter_list|)
value|do {					\ 	(head)->tqh_first = NULL;					\ 	(head)->tqh_last =&(head)->tqh_first;				\ } while (
comment|/*CONSTCOND*/
value|0)
end_define

begin_define
define|#
directive|define
name|ASN1_TAILQ_INSERT_HEAD
parameter_list|(
name|head
parameter_list|,
name|elm
parameter_list|,
name|field
parameter_list|)
value|do {			\ 	QUEUEDEBUG_ASN1_TAILQ_INSERT_HEAD((head), (elm), field)		\ 	if (((elm)->field.tqe_next = (head)->tqh_first) != NULL)	\ 		(head)->tqh_first->field.tqe_prev =			\&(elm)->field.tqe_next;				\ 	else								\ 		(head)->tqh_last =&(elm)->field.tqe_next;		\ 	(head)->tqh_first = (elm);					\ 	(elm)->field.tqe_prev =&(head)->tqh_first;			\ } while (
comment|/*CONSTCOND*/
value|0)
end_define

begin_define
define|#
directive|define
name|ASN1_TAILQ_INSERT_TAIL
parameter_list|(
name|head
parameter_list|,
name|elm
parameter_list|,
name|field
parameter_list|)
value|do {			\ 	QUEUEDEBUG_ASN1_TAILQ_INSERT_TAIL((head), (elm), field)		\ 	(elm)->field.tqe_next = NULL;					\ 	(elm)->field.tqe_prev = (head)->tqh_last;			\ 	*(head)->tqh_last = (elm);					\ 	(head)->tqh_last =&(elm)->field.tqe_next;			\ } while (
comment|/*CONSTCOND*/
value|0)
end_define

begin_define
define|#
directive|define
name|ASN1_TAILQ_INSERT_AFTER
parameter_list|(
name|head
parameter_list|,
name|listelm
parameter_list|,
name|elm
parameter_list|,
name|field
parameter_list|)
value|do {		\ 	QUEUEDEBUG_ASN1_TAILQ_OP((listelm), field)			\ 	if (((elm)->field.tqe_next = (listelm)->field.tqe_next) != NULL)\ 		(elm)->field.tqe_next->field.tqe_prev = 		\&(elm)->field.tqe_next;				\ 	else								\ 		(head)->tqh_last =&(elm)->field.tqe_next;		\ 	(listelm)->field.tqe_next = (elm);				\ 	(elm)->field.tqe_prev =&(listelm)->field.tqe_next;		\ } while (
comment|/*CONSTCOND*/
value|0)
end_define

begin_define
define|#
directive|define
name|ASN1_TAILQ_INSERT_BEFORE
parameter_list|(
name|listelm
parameter_list|,
name|elm
parameter_list|,
name|field
parameter_list|)
value|do {		\ 	QUEUEDEBUG_ASN1_TAILQ_OP((listelm), field)			\ 	(elm)->field.tqe_prev = (listelm)->field.tqe_prev;		\ 	(elm)->field.tqe_next = (listelm);				\ 	*(listelm)->field.tqe_prev = (elm);				\ 	(listelm)->field.tqe_prev =&(elm)->field.tqe_next;		\ } while (
comment|/*CONSTCOND*/
value|0)
end_define

begin_define
define|#
directive|define
name|ASN1_TAILQ_REMOVE
parameter_list|(
name|head
parameter_list|,
name|elm
parameter_list|,
name|field
parameter_list|)
value|do {			\ 	QUEUEDEBUG_ASN1_TAILQ_PREREMOVE((head), (elm), field)		\ 	QUEUEDEBUG_ASN1_TAILQ_OP((elm), field)				\ 	if (((elm)->field.tqe_next) != NULL)				\ 		(elm)->field.tqe_next->field.tqe_prev = 		\ 		    (elm)->field.tqe_prev;				\ 	else								\ 		(head)->tqh_last = (elm)->field.tqe_prev;		\ 	*(elm)->field.tqe_prev = (elm)->field.tqe_next;			\ 	QUEUEDEBUG_ASN1_TAILQ_POSTREMOVE((elm), field);			\ } while (
comment|/*CONSTCOND*/
value|0)
end_define

begin_define
define|#
directive|define
name|ASN1_TAILQ_FOREACH
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
name|ASN1_TAILQ_FOREACH_REVERSE
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
value|for ((var) = (*(((struct headname *)((head)->tqh_last))->tqh_last)); \ 		(var);							\ 		(var) = (*(((struct headname *)((var)->field.tqe_prev))->tqh_last)))
end_define

begin_comment
comment|/*  * Tail queue access methods.  */
end_comment

begin_define
define|#
directive|define
name|ASN1_TAILQ_EMPTY
parameter_list|(
name|head
parameter_list|)
value|((head)->tqh_first == NULL)
end_define

begin_define
define|#
directive|define
name|ASN1_TAILQ_FIRST
parameter_list|(
name|head
parameter_list|)
value|((head)->tqh_first)
end_define

begin_define
define|#
directive|define
name|ASN1_TAILQ_NEXT
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
name|ASN1_TAILQ_LAST
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
name|ASN1_TAILQ_PREV
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_ASN1_QUEUE_H_ */
end_comment

end_unit

