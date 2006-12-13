begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004 by Internet Systems Consortium, Inc. ("ISC")  * Copyright (c) 1997,1999 by Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT  * OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LIST_H
end_ifndef

begin_define
define|#
directive|define
name|LIST_H
value|1
end_define

begin_include
include|#
directive|include
file|<isc/assertions.h>
end_include

begin_define
define|#
directive|define
name|LIST
parameter_list|(
name|type
parameter_list|)
value|struct { type *head, *tail; }
end_define

begin_define
define|#
directive|define
name|INIT_LIST
parameter_list|(
name|list
parameter_list|)
define|\
value|do { (list).head = NULL; (list).tail = NULL; } while (0)
end_define

begin_define
define|#
directive|define
name|LINK
parameter_list|(
name|type
parameter_list|)
value|struct { type *prev, *next; }
end_define

begin_define
define|#
directive|define
name|INIT_LINK_TYPE
parameter_list|(
name|elt
parameter_list|,
name|link
parameter_list|,
name|type
parameter_list|)
define|\
value|do { \ 		(elt)->link.prev = (type *)(-1); \ 		(elt)->link.next = (type *)(-1); \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|INIT_LINK
parameter_list|(
name|elt
parameter_list|,
name|link
parameter_list|)
define|\
value|INIT_LINK_TYPE(elt, link, void)
end_define

begin_define
define|#
directive|define
name|LINKED
parameter_list|(
name|elt
parameter_list|,
name|link
parameter_list|)
value|((void *)((elt)->link.prev) != (void *)(-1))
end_define

begin_define
define|#
directive|define
name|HEAD
parameter_list|(
name|list
parameter_list|)
value|((list).head)
end_define

begin_define
define|#
directive|define
name|TAIL
parameter_list|(
name|list
parameter_list|)
value|((list).tail)
end_define

begin_define
define|#
directive|define
name|EMPTY
parameter_list|(
name|list
parameter_list|)
value|((list).head == NULL)
end_define

begin_define
define|#
directive|define
name|PREPEND
parameter_list|(
name|list
parameter_list|,
name|elt
parameter_list|,
name|link
parameter_list|)
define|\
value|do { \ 		INSIST(!LINKED(elt, link));\ 		if ((list).head != NULL) \ 			(list).head->link.prev = (elt); \ 		else \ 			(list).tail = (elt); \ 		(elt)->link.prev = NULL; \ 		(elt)->link.next = (list).head; \ 		(list).head = (elt); \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|APPEND
parameter_list|(
name|list
parameter_list|,
name|elt
parameter_list|,
name|link
parameter_list|)
define|\
value|do { \ 		INSIST(!LINKED(elt, link));\ 		if ((list).tail != NULL) \ 			(list).tail->link.next = (elt); \ 		else \ 			(list).head = (elt); \ 		(elt)->link.prev = (list).tail; \ 		(elt)->link.next = NULL; \ 		(list).tail = (elt); \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|UNLINK_TYPE
parameter_list|(
name|list
parameter_list|,
name|elt
parameter_list|,
name|link
parameter_list|,
name|type
parameter_list|)
define|\
value|do { \ 		INSIST(LINKED(elt, link));\ 		if ((elt)->link.next != NULL) \ 			(elt)->link.next->link.prev = (elt)->link.prev; \ 		else { \ 			INSIST((list).tail == (elt)); \ 			(list).tail = (elt)->link.prev; \ 		} \ 		if ((elt)->link.prev != NULL) \ 			(elt)->link.prev->link.next = (elt)->link.next; \ 		else { \ 			INSIST((list).head == (elt)); \ 			(list).head = (elt)->link.next; \ 		} \ 		INIT_LINK_TYPE(elt, link, type); \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|UNLINK
parameter_list|(
name|list
parameter_list|,
name|elt
parameter_list|,
name|link
parameter_list|)
define|\
value|UNLINK_TYPE(list, elt, link, void)
end_define

begin_define
define|#
directive|define
name|PREV
parameter_list|(
name|elt
parameter_list|,
name|link
parameter_list|)
value|((elt)->link.prev)
end_define

begin_define
define|#
directive|define
name|NEXT
parameter_list|(
name|elt
parameter_list|,
name|link
parameter_list|)
value|((elt)->link.next)
end_define

begin_define
define|#
directive|define
name|INSERT_BEFORE
parameter_list|(
name|list
parameter_list|,
name|before
parameter_list|,
name|elt
parameter_list|,
name|link
parameter_list|)
define|\
value|do { \ 		INSIST(!LINKED(elt, link));\ 		if ((before)->link.prev == NULL) \ 			PREPEND(list, elt, link); \ 		else { \ 			(elt)->link.prev = (before)->link.prev; \ 			(before)->link.prev = (elt); \ 			(elt)->link.prev->link.next = (elt); \ 			(elt)->link.next = (before); \ 		} \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|INSERT_AFTER
parameter_list|(
name|list
parameter_list|,
name|after
parameter_list|,
name|elt
parameter_list|,
name|link
parameter_list|)
define|\
value|do { \ 		INSIST(!LINKED(elt, link));\ 		if ((after)->link.next == NULL) \ 			APPEND(list, elt, link); \ 		else { \ 			(elt)->link.next = (after)->link.next; \ 			(after)->link.next = (elt); \ 			(elt)->link.next->link.prev = (elt); \ 			(elt)->link.prev = (after); \ 		} \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|ENQUEUE
parameter_list|(
name|list
parameter_list|,
name|elt
parameter_list|,
name|link
parameter_list|)
value|APPEND(list, elt, link)
end_define

begin_define
define|#
directive|define
name|DEQUEUE
parameter_list|(
name|list
parameter_list|,
name|elt
parameter_list|,
name|link
parameter_list|)
value|UNLINK(list, elt, link)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LIST_H */
end_comment

end_unit

