begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 1997, 1999  Internet Software Consortium.  *   * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *   * THE SOFTWARE IS PROVIDED "AS IS" AND INTERNET SOFTWARE CONSORTIUM DISCLAIMS  * ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL INTERNET SOFTWARE  * CONSORTIUM BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL  * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR  * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS  * ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS  * SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_LIST_H
end_ifndef

begin_define
define|#
directive|define
name|ISC_LIST_H
value|1
end_define

begin_define
define|#
directive|define
name|ISC_LIST
parameter_list|(
name|type
parameter_list|)
value|struct { type *head, *tail; }
end_define

begin_define
define|#
directive|define
name|ISC_LIST_INIT
parameter_list|(
name|list
parameter_list|)
define|\
value|do { (list).head = NULL; (list).tail = NULL; } while (0)
end_define

begin_define
define|#
directive|define
name|ISC_LINK
parameter_list|(
name|type
parameter_list|)
value|struct { type *prev, *next; }
end_define

begin_define
define|#
directive|define
name|ISC_LINK_INIT
parameter_list|(
name|elt
parameter_list|,
name|link
parameter_list|)
define|\
value|do { \ 		(elt)->link.prev = (void *)(-1); \ 		(elt)->link.next = (void *)(-1); \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|ISC_LINK_LINKED
parameter_list|(
name|elt
parameter_list|,
name|link
parameter_list|)
value|((elt)->link.prev != (void *)(-1))
end_define

begin_define
define|#
directive|define
name|ISC_LIST_HEAD
parameter_list|(
name|list
parameter_list|)
value|((list).head)
end_define

begin_define
define|#
directive|define
name|ISC_LIST_TAIL
parameter_list|(
name|list
parameter_list|)
value|((list).tail)
end_define

begin_define
define|#
directive|define
name|ISC_LIST_EMPTY
parameter_list|(
name|list
parameter_list|)
value|((list).head == NULL)
end_define

begin_define
define|#
directive|define
name|ISC_LIST_PREPEND
parameter_list|(
name|list
parameter_list|,
name|elt
parameter_list|,
name|link
parameter_list|)
define|\
value|do { \ 		if ((list).head != NULL) \ 			(list).head->link.prev = (elt); \ 		else \ 			(list).tail = (elt); \ 		(elt)->link.prev = NULL; \ 		(elt)->link.next = (list).head; \ 		(list).head = (elt); \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|ISC_LIST_APPEND
parameter_list|(
name|list
parameter_list|,
name|elt
parameter_list|,
name|link
parameter_list|)
define|\
value|do { \ 		if ((list).tail != NULL) \ 			(list).tail->link.next = (elt); \ 		else \ 			(list).head = (elt); \ 		(elt)->link.prev = (list).tail; \ 		(elt)->link.next = NULL; \ 		(list).tail = (elt); \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|ISC_LIST_UNLINK
parameter_list|(
name|list
parameter_list|,
name|elt
parameter_list|,
name|link
parameter_list|)
define|\
value|do { \ 		if ((elt)->link.next != NULL) \ 			(elt)->link.next->link.prev = (elt)->link.prev; \ 		else \ 			(list).tail = (elt)->link.prev; \ 		if ((elt)->link.prev != NULL) \ 			(elt)->link.prev->link.next = (elt)->link.next; \ 		else \ 			(list).head = (elt)->link.next; \ 		(elt)->link.prev = (void *)(-1); \ 		(elt)->link.next = (void *)(-1); \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|ISC_LIST_PREV
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
name|ISC_LIST_NEXT
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
name|ISC_LIST_INSERTBEFORE
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
value|do { \ 		if ((before)->link.prev == NULL) \ 			ISC_LIST_PREPEND(list, elt, link); \ 		else { \ 			(elt)->link.prev = (before)->link.prev; \ 			(before)->link.prev = (elt); \ 			(elt)->link.prev->link.next = (elt); \ 			(elt)->link.next = (before); \ 		} \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|ISC_LIST_INSERTAFTER
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
value|do { \ 		if ((after)->link.next == NULL) \ 			ISC_LIST_APPEND(list, elt, link); \ 		else { \ 			(elt)->link.next = (after)->link.next; \ 			(after)->link.next = (elt); \ 			(elt)->link.next->link.prev = (elt); \ 			(elt)->link.prev = (after); \ 		} \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|ISC_LIST_APPENDLIST
parameter_list|(
name|list1
parameter_list|,
name|list2
parameter_list|,
name|link
parameter_list|)
define|\
value|do { \ 		if (ISC_LIST_EMPTY(list1)) \ 			(list1) = (list2); \ 		else if (!ISC_LIST_EMPTY(list2)) { \ 			(list1).tail->link.next = (list2).head; \ 			(list2).head->link.prev = (list1).tail; \ 			(list1).tail = (list2).tail; \ 			(list2).head = NULL; \ 			(list2).tail = NULL; \ 		} \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|ISC_LIST_ENQUEUE
parameter_list|(
name|list
parameter_list|,
name|elt
parameter_list|,
name|link
parameter_list|)
value|ISC_LIST_APPEND(list, elt, link)
end_define

begin_define
define|#
directive|define
name|ISC_LIST_DEQUEUE
parameter_list|(
name|list
parameter_list|,
name|elt
parameter_list|,
name|link
parameter_list|)
value|ISC_LIST_UNLINK(list, elt, link)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISC_LIST_H */
end_comment

end_unit

