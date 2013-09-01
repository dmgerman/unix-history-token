begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2011-2013  Internet Systems Consortium, Inc. ("ISC")  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id$ */
end_comment

begin_comment
comment|/*  * This is a generic implementation of a two-lock concurrent queue.  * There are built-in mutex locks for the head and tail of the queue,  * allowing elements to be safely added and removed at the same time.  *  * NULL is "end of list"  * -1 is "not linked"  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_QUEUE_H
end_ifndef

begin_define
define|#
directive|define
name|ISC_QUEUE_H
value|1
end_define

begin_include
include|#
directive|include
file|<isc/assertions.h>
end_include

begin_include
include|#
directive|include
file|<isc/boolean.h>
end_include

begin_include
include|#
directive|include
file|<isc/mutex.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|ISC_QUEUE_CHECKINIT
end_ifdef

begin_define
define|#
directive|define
name|ISC_QLINK_INSIST
parameter_list|(
name|x
parameter_list|)
value|ISC_INSIST(x)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ISC_QLINK_INSIST
parameter_list|(
name|x
parameter_list|)
value|(void)0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ISC_QLINK
parameter_list|(
name|type
parameter_list|)
value|struct { type *prev, *next; }
end_define

begin_define
define|#
directive|define
name|ISC_QLINK_INIT
parameter_list|(
name|elt
parameter_list|,
name|link
parameter_list|)
define|\
value|do { \ 		(elt)->link.next = (elt)->link.prev = (void *)(-1); \ 	} while(0)
end_define

begin_define
define|#
directive|define
name|ISC_QLINK_LINKED
parameter_list|(
name|elt
parameter_list|,
name|link
parameter_list|)
value|((void*)(elt)->link.next != (void*)(-1))
end_define

begin_define
define|#
directive|define
name|ISC_QUEUE
parameter_list|(
name|type
parameter_list|)
value|struct { \ 	type *head, *tail; \ 	isc_mutex_t headlock, taillock; \ }
end_define

begin_define
define|#
directive|define
name|ISC_QUEUE_INIT
parameter_list|(
name|queue
parameter_list|,
name|link
parameter_list|)
define|\
value|do { \ 		(void) isc_mutex_init(&(queue).taillock); \ 		(void) isc_mutex_init(&(queue).headlock); \ 		(queue).tail = (queue).head = NULL; \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|ISC_QUEUE_EMPTY
parameter_list|(
name|queue
parameter_list|)
value|ISC_TF((queue).head == NULL)
end_define

begin_define
define|#
directive|define
name|ISC_QUEUE_DESTROY
parameter_list|(
name|queue
parameter_list|)
define|\
value|do { \ 		ISC_QLINK_INSIST(ISC_QUEUE_EMPTY(queue)); \ 		(void) isc_mutex_destroy(&(queue).taillock); \ 		(void) isc_mutex_destroy(&(queue).headlock); \ 	} while (0)
end_define

begin_comment
comment|/*  * queues are meant to separate the locks at either end.  For best effect, that  * means keeping the ends separate - i.e. non-empty queues work best.  *  * a push to an empty queue has to take the pop lock to update  * the pop side of the queue.  * Popping the last entry has to take the push lock to update  * the push side of the queue.  *  * The order is (pop, push), because a pop is presumably in the  * latency path and a push is when we're done.  *  * We do an MT hot test in push to see if we need both locks, so we can  * acquire them in order.  Hopefully that makes the case where we get  * the push lock and find we need the pop lock (and have to release it) rare.  *  *> 1 entry - no collision, push works on one end, pop on the other  *   0 entry - headlock race  *     pop wins - return(NULL), push adds new as both head/tail  *     push wins - updates head/tail, becomes 1 entry case.  *   1 entry - taillock race  *     pop wins - return(pop) sets head/tail NULL, becomes 0 entry case  *     push wins - updates {head,tail}->link.next, pop updates head  *                 with new ->link.next and doesn't update tail  *  */
end_comment

begin_define
define|#
directive|define
name|ISC_QUEUE_PUSH
parameter_list|(
name|queue
parameter_list|,
name|elt
parameter_list|,
name|link
parameter_list|)
define|\
value|do { \ 		isc_boolean_t headlocked = ISC_FALSE; \ 		ISC_QLINK_INSIST(!ISC_QLINK_LINKED(elt, link)); \ 		if ((queue).head == NULL) { \ 			LOCK(&(queue).headlock); \ 			headlocked = ISC_TRUE; \ 		} \ 		LOCK(&(queue).taillock); \ 		if ((queue).tail == NULL&& !headlocked) { \ 			UNLOCK(&(queue).taillock); \ 			LOCK(&(queue).headlock); \ 			LOCK(&(queue).taillock); \ 			headlocked = ISC_TRUE; \ 		} \ 		(elt)->link.prev = (queue).tail; \ 		(elt)->link.next = NULL; \ 		if ((queue).tail != NULL) \ 			(queue).tail->link.next = (elt); \ 		(queue).tail = (elt); \ 		UNLOCK(&(queue).taillock); \ 		if (headlocked) { \ 			if ((queue).head == NULL) \ 				(queue).head = (elt); \ 			UNLOCK(&(queue).headlock); \ 		} \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|ISC_QUEUE_POP
parameter_list|(
name|queue
parameter_list|,
name|link
parameter_list|,
name|ret
parameter_list|)
define|\
value|do { \ 		LOCK(&(queue).headlock); \ 		ret = (queue).head; \ 		while (ret != NULL) { \ 			if (ret->link.next == NULL) { \ 				LOCK(&(queue).taillock); \ 				if (ret->link.next == NULL) { \ 					(queue).head = (queue).tail = NULL; \ 					UNLOCK(&(queue).taillock); \ 					break; \ 				}\ 				UNLOCK(&(queue).taillock); \ 			} \ 			(queue).head = ret->link.next; \ 			(queue).head->link.prev = NULL; \ 			break; \ 		} \ 		UNLOCK(&(queue).headlock); \ 		if (ret != NULL) \ 			(ret)->link.next = (ret)->link.prev = (void *)(-1); \ 	} while(0)
end_define

begin_define
define|#
directive|define
name|ISC_QUEUE_UNLINK
parameter_list|(
name|queue
parameter_list|,
name|elt
parameter_list|,
name|link
parameter_list|)
define|\
value|do { \ 		ISC_QLINK_INSIST(ISC_QLINK_LINKED(elt, link)); \ 		LOCK(&(queue).headlock); \ 		LOCK(&(queue).taillock); \ 		if ((elt)->link.prev == NULL) \ 			(queue).head = (elt)->link.next; \ 		else \ 			(elt)->link.prev->link.next = (elt)->link.next; \ 		if ((elt)->link.next == NULL) \ 			(queue).tail = (elt)->link.prev; \ 		else \ 			(elt)->link.next->link.prev = (elt)->link.prev; \ 		UNLOCK(&(queue).taillock); \ 		UNLOCK(&(queue).headlock); \ 		(elt)->link.next = (elt)->link.prev = (void *)(-1); \ 	} while(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISC_QUEUE_H */
end_comment

end_unit

