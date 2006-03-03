begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)queue.h	8.5 (Berkeley) 8/20/94  * $FreeBSD$  *  * $FreeBSD$  */
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

begin_undef
undef|#
directive|undef
name|__ofsetof
end_undef

begin_define
define|#
directive|define
name|__offsetof
parameter_list|(
name|type
parameter_list|,
name|field
parameter_list|)
value|((size_t)(&((type *)0)->field))
end_define

begin_comment
comment|/*  * Singly-linked Tail queue declarations.  */
end_comment

begin_undef
undef|#
directive|undef
name|STAILQ_HEAD
end_undef

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

begin_undef
undef|#
directive|undef
name|STAILQ_HEAD_INITIALIZER
end_undef

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

begin_undef
undef|#
directive|undef
name|STAILQ_ENTRY
end_undef

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

begin_undef
undef|#
directive|undef
name|STAILQ_EMPTY
end_undef

begin_define
define|#
directive|define
name|STAILQ_EMPTY
parameter_list|(
name|head
parameter_list|)
value|((head)->stqh_first == NULL)
end_define

begin_undef
undef|#
directive|undef
name|STAILQ_FIRST
end_undef

begin_define
define|#
directive|define
name|STAILQ_FIRST
parameter_list|(
name|head
parameter_list|)
value|((head)->stqh_first)
end_define

begin_undef
undef|#
directive|undef
name|STAILQ_FOREACH
end_undef

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

begin_undef
undef|#
directive|undef
name|STAILQ_FOREACH_SAFE
end_undef

begin_define
define|#
directive|define
name|STAILQ_FOREACH_SAFE
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
value|for ((var) = STAILQ_FIRST((head));				\ 	    (var)&& ((tvar) = STAILQ_NEXT((var), field), 1);		\ 	    (var) = (tvar))
end_define

begin_undef
undef|#
directive|undef
name|STAILQ_INIT
end_undef

begin_define
define|#
directive|define
name|STAILQ_INIT
parameter_list|(
name|head
parameter_list|)
value|do {						\ 	STAILQ_FIRST((head)) = NULL;					\ 	(head)->stqh_last =&STAILQ_FIRST((head));			\ } while (0)
end_define

begin_undef
undef|#
directive|undef
name|STAILQ_INSERT_AFTER
end_undef

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

begin_undef
undef|#
directive|undef
name|STAILQ_INSERT_HEAD
end_undef

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

begin_undef
undef|#
directive|undef
name|STAILQ_INSERT_TAIL
end_undef

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

begin_undef
undef|#
directive|undef
name|STAILQ_LAST
end_undef

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
value|(STAILQ_EMPTY((head)) ?						\ 		NULL :							\ 	        ((struct type *)					\ 		((char *)((head)->stqh_last) - __offsetof(struct type, field))))
end_define

begin_undef
undef|#
directive|undef
name|STAILQ_NEXT
end_undef

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

begin_undef
undef|#
directive|undef
name|STAILQ_REMOVE
end_undef

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
value|do {			\ 	if (STAILQ_FIRST((head)) == (elm)) {				\ 		STAILQ_REMOVE_HEAD((head), field);			\ 	}								\ 	else {								\ 		struct type *curelm = STAILQ_FIRST((head));		\ 		while (STAILQ_NEXT(curelm, field) != (elm))		\ 			curelm = STAILQ_NEXT(curelm, field);		\ 		if ((STAILQ_NEXT(curelm, field) =			\ 		     STAILQ_NEXT(STAILQ_NEXT(curelm, field), field)) == NULL)\ 			(head)->stqh_last =&STAILQ_NEXT((curelm), field);\ 	}								\ } while (0)
end_define

begin_undef
undef|#
directive|undef
name|STAILQ_REMOVE_HEAD
end_undef

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

begin_undef
undef|#
directive|undef
name|STAILQ_REMOVE_HEAD_UNTIL
end_undef

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

begin_undef
undef|#
directive|undef
name|LIST_HEAD
end_undef

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

begin_undef
undef|#
directive|undef
name|LIST_HEAD_INITIALIZER
end_undef

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

begin_undef
undef|#
directive|undef
name|LIST_ENTRY
end_undef

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

begin_undef
undef|#
directive|undef
name|LIST_EMPTY
end_undef

begin_define
define|#
directive|define
name|LIST_EMPTY
parameter_list|(
name|head
parameter_list|)
value|((head)->lh_first == NULL)
end_define

begin_undef
undef|#
directive|undef
name|LIST_FIRST
end_undef

begin_define
define|#
directive|define
name|LIST_FIRST
parameter_list|(
name|head
parameter_list|)
value|((head)->lh_first)
end_define

begin_undef
undef|#
directive|undef
name|LIST_FOREACH
end_undef

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

begin_undef
undef|#
directive|undef
name|LIST_FOREACH_SAFE
end_undef

begin_define
define|#
directive|define
name|LIST_FOREACH_SAFE
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
value|for ((var) = LIST_FIRST((head));				\ 	    (var)&& ((tvar) = LIST_NEXT((var), field), 1);		\ 	    (var) = (tvar))
end_define

begin_undef
undef|#
directive|undef
name|LIST_INIT
end_undef

begin_define
define|#
directive|define
name|LIST_INIT
parameter_list|(
name|head
parameter_list|)
value|do {						\ 	LIST_FIRST((head)) = NULL;					\ } while (0)
end_define

begin_undef
undef|#
directive|undef
name|LIST_INSERT_AFTER
end_undef

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

begin_undef
undef|#
directive|undef
name|LIST_INSERT_BEFORE
end_undef

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

begin_undef
undef|#
directive|undef
name|LIST_INSERT_HEAD
end_undef

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

begin_undef
undef|#
directive|undef
name|LIST_NEXT
end_undef

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

begin_undef
undef|#
directive|undef
name|LIST_REMOVE
end_undef

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_QUEUE_H_ */
end_comment

end_unit

