begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004, 2006  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1997-2002  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: list.h,v 1.18.2.2.8.3 2006/06/06 00:11:40 marka Exp $ */
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

begin_include
include|#
directive|include
file|<isc/boolean.h>
end_include

begin_include
include|#
directive|include
file|<isc/assertions.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|ISC_LIST_CHECKINIT
end_ifdef

begin_define
define|#
directive|define
name|ISC_LINK_INSIST
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
name|ISC_LINK_INSIST
parameter_list|(
name|x
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

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
name|ISC_LINK_INIT_TYPE
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
name|ISC_LINK_INIT
parameter_list|(
name|elt
parameter_list|,
name|link
parameter_list|)
define|\
value|ISC_LINK_INIT_TYPE(elt, link, void)
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
value|((void *)((elt)->link.prev) != (void *)(-1))
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
value|ISC_TF((list).head == NULL)
end_define

begin_define
define|#
directive|define
name|__ISC_LIST_PREPENDUNSAFE
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
name|ISC_LIST_PREPEND
parameter_list|(
name|list
parameter_list|,
name|elt
parameter_list|,
name|link
parameter_list|)
define|\
value|do { \ 		ISC_LINK_INSIST(!ISC_LINK_LINKED(elt, link)); \ 		__ISC_LIST_PREPENDUNSAFE(list, elt, link); \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|ISC_LIST_INITANDPREPEND
parameter_list|(
name|list
parameter_list|,
name|elt
parameter_list|,
name|link
parameter_list|)
define|\
value|__ISC_LIST_PREPENDUNSAFE(list, elt, link)
end_define

begin_define
define|#
directive|define
name|__ISC_LIST_APPENDUNSAFE
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
name|ISC_LIST_APPEND
parameter_list|(
name|list
parameter_list|,
name|elt
parameter_list|,
name|link
parameter_list|)
define|\
value|do { \ 		ISC_LINK_INSIST(!ISC_LINK_LINKED(elt, link)); \ 		__ISC_LIST_APPENDUNSAFE(list, elt, link); \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|ISC_LIST_INITANDAPPEND
parameter_list|(
name|list
parameter_list|,
name|elt
parameter_list|,
name|link
parameter_list|)
define|\
value|__ISC_LIST_APPENDUNSAFE(list, elt, link)
end_define

begin_define
define|#
directive|define
name|__ISC_LIST_UNLINKUNSAFE_TYPE
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
value|do { \ 		if ((elt)->link.next != NULL) \ 			(elt)->link.next->link.prev = (elt)->link.prev; \ 		else { \ 			ISC_INSIST((list).tail == (elt)); \ 			(list).tail = (elt)->link.prev; \ 		} \ 		if ((elt)->link.prev != NULL) \ 			(elt)->link.prev->link.next = (elt)->link.next; \ 		else { \ 			ISC_INSIST((list).head == (elt)); \ 			(list).head = (elt)->link.next; \ 		} \ 		(elt)->link.prev = (type *)(-1); \ 		(elt)->link.next = (type *)(-1); \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|__ISC_LIST_UNLINKUNSAFE
parameter_list|(
name|list
parameter_list|,
name|elt
parameter_list|,
name|link
parameter_list|)
define|\
value|__ISC_LIST_UNLINKUNSAFE_TYPE(list, elt, link, void)
end_define

begin_define
define|#
directive|define
name|ISC_LIST_UNLINK_TYPE
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
value|do { \ 		ISC_LINK_INSIST(ISC_LINK_LINKED(elt, link)); \ 		__ISC_LIST_UNLINKUNSAFE_TYPE(list, elt, link, type); \ 	} while (0)
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
value|ISC_LIST_UNLINK_TYPE(list, elt, link, void)
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
name|__ISC_LIST_INSERTBEFOREUNSAFE
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
value|do { \ 		ISC_LINK_INSIST(ISC_LINK_LINKED(before, link)); \ 		ISC_LINK_INSIST(!ISC_LINK_LINKED(elt, link)); \ 		__ISC_LIST_INSERTBEFOREUNSAFE(list, before, elt, link); \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|__ISC_LIST_INSERTAFTERUNSAFE
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
value|do { \ 		ISC_LINK_INSIST(ISC_LINK_LINKED(after, link)); \ 		ISC_LINK_INSIST(!ISC_LINK_LINKED(elt, link)); \ 		__ISC_LIST_INSERTAFTERUNSAFE(list, after, elt, link); \ 	} while (0)
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
value|do { \ 		if (ISC_LIST_EMPTY(list1)) \ 			(list1) = (list2); \ 		else if (!ISC_LIST_EMPTY(list2)) { \ 			(list1).tail->link.next = (list2).head; \ 			(list2).head->link.prev = (list1).tail; \ 			(list1).tail = (list2).tail; \ 		} \ 		(list2).head = NULL; \ 		(list2).tail = NULL; \ 	} while (0)
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
name|__ISC_LIST_ENQUEUEUNSAFE
parameter_list|(
name|list
parameter_list|,
name|elt
parameter_list|,
name|link
parameter_list|)
define|\
value|__ISC_LIST_APPENDUNSAFE(list, elt, link)
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
define|\
value|ISC_LIST_UNLINK_TYPE(list, elt, link, void)
end_define

begin_define
define|#
directive|define
name|ISC_LIST_DEQUEUE_TYPE
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
value|ISC_LIST_UNLINK_TYPE(list, elt, link, type)
end_define

begin_define
define|#
directive|define
name|__ISC_LIST_DEQUEUEUNSAFE
parameter_list|(
name|list
parameter_list|,
name|elt
parameter_list|,
name|link
parameter_list|)
define|\
value|__ISC_LIST_UNLINKUNSAFE_TYPE(list, elt, link, void)
end_define

begin_define
define|#
directive|define
name|__ISC_LIST_DEQUEUEUNSAFE_TYPE
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
value|__ISC_LIST_UNLINKUNSAFE_TYPE(list, elt, link, type)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISC_LIST_H */
end_comment

end_unit

