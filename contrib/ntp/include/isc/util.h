begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 1998-2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND INTERNET SOFTWARE CONSORTIUM  * DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL  * INTERNET SOFTWARE CONSORTIUM BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING  * FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT,  * NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION  * WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: util.h,v 1.23 2001/11/30 01:59:38 gson Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_UTIL_H
end_ifndef

begin_define
define|#
directive|define
name|ISC_UTIL_H
value|1
end_define

begin_comment
comment|/*  * NOTE:  *  * This file is not to be included from any<isc/???.h> (or other) library  * files.  *  * Including this file puts several macros in your name space that are  * not protected (as all the other ISC functions/macros do) by prepending  * ISC_ or isc_ to the name.  */
end_comment

begin_comment
comment|/***  *** General Macros.  ***/
end_comment

begin_comment
comment|/*  * Use this to hide unused function arguments.  *  * int  * foo(char *bar)  * {  *	UNUSED(bar);  * }  */
end_comment

begin_define
define|#
directive|define
name|UNUSED
parameter_list|(
name|x
parameter_list|)
value|(void)(x)
end_define

begin_define
define|#
directive|define
name|ISC_MAX
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)> (b) ? (a) : (b))
end_define

begin_define
define|#
directive|define
name|ISC_MIN
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)< (b) ? (a) : (b))
end_define

begin_comment
comment|/*  * Use this to remove the const qualifier of a variable to assign it to  * a non-const variable or pass it as a non-const function argument ...  * but only when you are sure it won't then be changed!  * This is necessary to sometimes shut up some compilers  * (as with gcc -Wcast-qual) when there is just no other good way to avoid the  * situation.  */
end_comment

begin_define
define|#
directive|define
name|DE_CONST
parameter_list|(
name|konst
parameter_list|,
name|var
parameter_list|)
define|\
value|do { \ 		union { const void *k; void *v; } _u; \ 		_u.k = konst; \ 		var = _u.v; \ 	} while (0)
end_define

begin_comment
comment|/*  * Use this in translation units that would otherwise be empty, to  * suppress compiler warnings.  */
end_comment

begin_define
define|#
directive|define
name|EMPTY_TRANSLATION_UNIT
value|static void isc__empty(void) { isc__empty(); }
end_define

begin_comment
comment|/*  * We use macros instead of calling the routines directly because  * the capital letters make the locking stand out.  *  * We RUNTIME_CHECK for success since in general there's no way  * for us to continue if they fail.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ISC_UTIL_TRACEON
end_ifdef

begin_define
define|#
directive|define
name|ISC_UTIL_TRACE
parameter_list|(
name|a
parameter_list|)
value|a
end_define

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_comment
comment|/* Required for fprintf/stderr when tracing. */
end_comment

begin_include
include|#
directive|include
file|<isc/msgs.h>
end_include

begin_comment
comment|/* Required for isc_msgcat when tracing. */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ISC_UTIL_TRACE
parameter_list|(
name|a
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<isc/result.h>
end_include

begin_comment
comment|/* Contractual promise. */
end_comment

begin_define
define|#
directive|define
name|LOCK
parameter_list|(
name|lp
parameter_list|)
value|do { \ 	ISC_UTIL_TRACE(fprintf(stderr, "%s %p %s %d\n", \ 			       isc_msgcat_get(isc_msgcat, ISC_MSGSET_UTIL, \ 					      ISC_MSG_LOCKING, "LOCKING"), \ 			       (lp), __FILE__, __LINE__)); \ 	RUNTIME_CHECK(isc_mutex_lock((lp)) == ISC_R_SUCCESS); \ 	ISC_UTIL_TRACE(fprintf(stderr, "%s %p %s %d\n", \ 			       isc_msgcat_get(isc_msgcat, ISC_MSGSET_UTIL, \ 					      ISC_MSG_LOCKED, "LOCKED"), \ 			       (lp), __FILE__, __LINE__)); \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|UNLOCK
parameter_list|(
name|lp
parameter_list|)
value|do { \ 	RUNTIME_CHECK(isc_mutex_unlock((lp)) == ISC_R_SUCCESS); \ 	ISC_UTIL_TRACE(fprintf(stderr, "%s %p %s %d\n", \ 			       isc_msgcat_get(isc_msgcat, ISC_MSGSET_UTIL, \ 					      ISC_MSG_UNLOCKED, "UNLOCKED"), \ 			       (lp), __FILE__, __LINE__)); \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|ISLOCKED
parameter_list|(
name|lp
parameter_list|)
value|(1)
end_define

begin_define
define|#
directive|define
name|DESTROYLOCK
parameter_list|(
name|lp
parameter_list|)
define|\
value|RUNTIME_CHECK(isc_mutex_destroy((lp)) == ISC_R_SUCCESS)
end_define

begin_define
define|#
directive|define
name|BROADCAST
parameter_list|(
name|cvp
parameter_list|)
value|do { \ 	ISC_UTIL_TRACE(fprintf(stderr, "%s %p %s %d\n", \ 			       isc_msgcat_get(isc_msgcat, ISC_MSGSET_UTIL, \ 					      ISC_MSG_BROADCAST, "BROADCAST"),\ 			       (cvp), __FILE__, __LINE__)); \ 	RUNTIME_CHECK(isc_condition_broadcast((cvp)) == ISC_R_SUCCESS); \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|SIGNAL
parameter_list|(
name|cvp
parameter_list|)
value|do { \ 	ISC_UTIL_TRACE(fprintf(stderr, "%s %p %s %d\n", \ 			       isc_msgcat_get(isc_msgcat, ISC_MSGSET_UTIL, \ 					      ISC_MSG_SIGNAL, "SIGNAL"), \ 			       (cvp), __FILE__, __LINE__)); \ 	RUNTIME_CHECK(isc_condition_signal((cvp)) == ISC_R_SUCCESS); \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|WAIT
parameter_list|(
name|cvp
parameter_list|,
name|lp
parameter_list|)
value|do { \ 	ISC_UTIL_TRACE(fprintf(stderr, "%s %p %s %p %s %d\n", \ 			       isc_msgcat_get(isc_msgcat, ISC_MSGSET_UTIL, \ 					      ISC_MSG_UTILWAIT, "WAIT"), \ 			       (cvp), \ 			       isc_msgcat_get(isc_msgcat, ISC_MSGSET_UTIL, \ 					      ISC_MSG_LOCK, "LOCK"), \ 			       (lp), __FILE__, __LINE__)); \ 	RUNTIME_CHECK(isc_condition_wait((cvp), (lp)) == ISC_R_SUCCESS); \ 	ISC_UTIL_TRACE(fprintf(stderr, "%s %p %s %p %s %d\n", \ 			       isc_msgcat_get(isc_msgcat, ISC_MSGSET_UTIL, \ 					      ISC_MSG_WAITED, "WAITED"), \ 			       (cvp), \ 			       isc_msgcat_get(isc_msgcat, ISC_MSGSET_UTIL, \ 					      ISC_MSG_LOCKED, "LOCKED"), \ 			       (lp), __FILE__, __LINE__)); \ 	} while (0)
end_define

begin_comment
comment|/*  * isc_condition_waituntil can return ISC_R_TIMEDOUT, so we  * don't RUNTIME_CHECK the result.  *  *  XXX Also, can't really debug this then...  */
end_comment

begin_define
define|#
directive|define
name|WAITUNTIL
parameter_list|(
name|cvp
parameter_list|,
name|lp
parameter_list|,
name|tp
parameter_list|)
define|\
value|isc_condition_waituntil((cvp), (lp), (tp))
end_define

begin_define
define|#
directive|define
name|RWLOCK
parameter_list|(
name|lp
parameter_list|,
name|t
parameter_list|)
value|do { \ 	ISC_UTIL_TRACE(fprintf(stderr, "%s %p, %d %s %d\n", \ 			       isc_msgcat_get(isc_msgcat, ISC_MSGSET_UTIL, \ 					      ISC_MSG_RWLOCK, "RWLOCK"), \ 			       (lp), (t), __FILE__, __LINE__)); \ 	RUNTIME_CHECK(isc_rwlock_lock((lp), (t)) == ISC_R_SUCCESS); \ 	ISC_UTIL_TRACE(fprintf(stderr, "%s %p, %d %s %d\n", \ 			       isc_msgcat_get(isc_msgcat, ISC_MSGSET_UTIL, \ 					      ISC_MSG_RWLOCKED, "RWLOCKED"), \ 			       (lp), (t), __FILE__, __LINE__)); \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|RWUNLOCK
parameter_list|(
name|lp
parameter_list|,
name|t
parameter_list|)
value|do { \ 	ISC_UTIL_TRACE(fprintf(stderr, "%s %p, %d %s %d\n", \ 			       isc_msgcat_get(isc_msgcat, ISC_MSGSET_UTIL, \ 					      ISC_MSG_RWUNLOCK, "RWUNLOCK"), \ 			       (lp), (t), __FILE__, __LINE__)); \ 	RUNTIME_CHECK(isc_rwlock_unlock((lp), (t)) == ISC_R_SUCCESS); \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|DESTROYMUTEXBLOCK
parameter_list|(
name|bp
parameter_list|,
name|n
parameter_list|)
define|\
value|RUNTIME_CHECK(isc_mutexblock_destroy((bp), (n)) == ISC_R_SUCCESS)
end_define

begin_comment
comment|/*  * List Macros.  */
end_comment

begin_include
include|#
directive|include
file|<isc/list.h>
end_include

begin_comment
comment|/* Contractual promise. */
end_comment

begin_define
define|#
directive|define
name|LIST
parameter_list|(
name|type
parameter_list|)
value|ISC_LIST(type)
end_define

begin_define
define|#
directive|define
name|INIT_LIST
parameter_list|(
name|type
parameter_list|)
value|ISC_LIST_INIT(type)
end_define

begin_define
define|#
directive|define
name|LINK
parameter_list|(
name|type
parameter_list|)
value|ISC_LINK(type)
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
value|ISC_LINK_INIT(elt, link)
end_define

begin_define
define|#
directive|define
name|HEAD
parameter_list|(
name|list
parameter_list|)
value|ISC_LIST_HEAD(list)
end_define

begin_define
define|#
directive|define
name|TAIL
parameter_list|(
name|list
parameter_list|)
value|ISC_LIST_TAIL(list)
end_define

begin_define
define|#
directive|define
name|EMPTY
parameter_list|(
name|list
parameter_list|)
value|ISC_LIST_EMPTY(list)
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
value|ISC_LIST_PREV(elt, link)
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
value|ISC_LIST_NEXT(elt, link)
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
value|ISC_LIST_APPEND(list, elt, link)
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
value|ISC_LIST_PREPEND(list, elt, link)
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
value|ISC_LIST_UNLINK(list, elt, link)
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
value|ISC_LIST_APPEND(list, elt, link)
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
value|ISC_LIST_UNLINK(list, elt, link)
end_define

begin_define
define|#
directive|define
name|INSERTBEFORE
parameter_list|(
name|li
parameter_list|,
name|b
parameter_list|,
name|e
parameter_list|,
name|ln
parameter_list|)
value|ISC_LIST_INSERTBEFORE(li, b, e, ln)
end_define

begin_define
define|#
directive|define
name|INSERTAFTER
parameter_list|(
name|li
parameter_list|,
name|a
parameter_list|,
name|e
parameter_list|,
name|ln
parameter_list|)
value|ISC_LIST_INSERTAFTER(li, a, e, ln)
end_define

begin_define
define|#
directive|define
name|APPENDLIST
parameter_list|(
name|list1
parameter_list|,
name|list2
parameter_list|,
name|link
parameter_list|)
value|ISC_LIST_APPENDLIST(list1, list2, link)
end_define

begin_comment
comment|/*  * Assertions  */
end_comment

begin_include
include|#
directive|include
file|<isc/assertions.h>
end_include

begin_comment
comment|/* Contractual promise. */
end_comment

begin_define
define|#
directive|define
name|REQUIRE
parameter_list|(
name|e
parameter_list|)
value|ISC_REQUIRE(e)
end_define

begin_define
define|#
directive|define
name|ENSURE
parameter_list|(
name|e
parameter_list|)
value|ISC_ENSURE(e)
end_define

begin_define
define|#
directive|define
name|INSIST
parameter_list|(
name|e
parameter_list|)
value|ISC_INSIST(e)
end_define

begin_define
define|#
directive|define
name|INVARIANT
parameter_list|(
name|e
parameter_list|)
value|ISC_INVARIANT(e)
end_define

begin_comment
comment|/*  * Errors  */
end_comment

begin_include
include|#
directive|include
file|<isc/error.h>
end_include

begin_comment
comment|/* Contractual promise. */
end_comment

begin_define
define|#
directive|define
name|UNEXPECTED_ERROR
value|isc_error_unexpected
end_define

begin_define
define|#
directive|define
name|FATAL_ERROR
value|isc_error_fatal
end_define

begin_define
define|#
directive|define
name|RUNTIME_CHECK
parameter_list|(
name|cond
parameter_list|)
value|ISC_ERROR_RUNTIMECHECK(cond)
end_define

begin_comment
comment|/*  * Time  */
end_comment

begin_define
define|#
directive|define
name|TIME_NOW
parameter_list|(
name|tp
parameter_list|)
value|RUNTIME_CHECK(isc_time_now((tp)) == ISC_R_SUCCESS)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISC_UTIL_H */
end_comment

end_unit

