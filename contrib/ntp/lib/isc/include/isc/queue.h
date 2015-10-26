begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2011, 2012  Internet Systems Consortium, Inc. ("ISC")  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id$ */
end_comment

begin_comment
comment|/*  * This is a generic implementation of a two-lock concurrent queue.  * There are built-in mutex locks for the head and tail of the queue,  * allowing elements to be safely added and removed at the same time.  */
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
value|struct { void *next; isc_boolean_t linked; }
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
value|do { \ 		(elt)->link.next = (void *)(-1); \ 		(elt)->link.linked = ISC_FALSE; \ 	} while (0)
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
value|((elt)->link.linked)
end_define

begin_define
define|#
directive|define
name|ISC_QUEUE
parameter_list|(
name|type
parameter_list|)
value|struct { \ 	type headnode; \ 	type *head, *tail; \ 	isc_mutex_t headlock, taillock; \ }
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
value|do { \ 		isc_mutex_init(&(queue).headlock); \ 		isc_mutex_init(&(queue).taillock); \ 		(queue).head = (void *)&((queue).headnode); \ 		(queue).tail = (void *)&((queue).headnode); \ 		ISC_QLINK_INIT((queue).head, link); \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|ISC_QUEUE_EMPTY
parameter_list|(
name|queue
parameter_list|)
value|ISC_TF((queue).head == (queue).tail)
end_define

begin_define
define|#
directive|define
name|ISC_QUEUE_DESTROY
parameter_list|(
name|queue
parameter_list|)
define|\
value|do { \ 		ISC_QLINK_INSIST(ISC_QUEUE_EMPTY(queue)); \ 		isc_mutex_destroy(&(queue).headlock); \ 		isc_mutex_destroy(&(queue).taillock); \ 	} while (0)
end_define

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
value|do { \ 		ISC_QLINK_INSIST(!ISC_QLINK_LINKED(elt, link)); \ 		(elt)->link.next = (void *)(-1); \ 		LOCK(&(queue).taillock); \ 		(queue).tail->link.next = elt; \ 		(queue).tail = elt; \ 		UNLOCK(&(queue).taillock); \ 		(elt)->link.linked = ISC_TRUE; \ 	} while (0)
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
value|do { \ 		LOCK(&(queue).headlock); \ 		ret = (queue).head->link.next; \ 		if (ret == (void *)(-1)) { \ 			UNLOCK(&(queue).headlock); \ 			ret = NULL; \ 		} else { \ 			(queue).head->link.next = ret->link.next; \ 			if (ret->link.next == (void *)(-1)) { \ 				LOCK(&(queue).taillock); \ 				(queue).tail = (queue).head; \ 				UNLOCK(&(queue).taillock); \ 			} \ 			UNLOCK(&(queue).headlock); \ 			ret->link.next = (void *)(-1); \ 			ret->link.linked = ISC_FALSE; \ 		} \ 	} while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISC_QUEUE_H */
end_comment

end_unit

