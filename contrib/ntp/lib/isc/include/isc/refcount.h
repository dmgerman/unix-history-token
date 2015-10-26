begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004-2007, 2009  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 2001, 2003  Internet Software Consortium.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: refcount.h,v 1.17 2009/09/29 23:48:04 tbox Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_REFCOUNT_H
end_ifndef

begin_define
define|#
directive|define
name|ISC_REFCOUNT_H
value|1
end_define

begin_include
include|#
directive|include
file|<isc/atomic.h>
end_include

begin_include
include|#
directive|include
file|<isc/lang.h>
end_include

begin_include
include|#
directive|include
file|<isc/mutex.h>
end_include

begin_include
include|#
directive|include
file|<isc/platform.h>
end_include

begin_include
include|#
directive|include
file|<isc/types.h>
end_include

begin_include
include|#
directive|include
file|<isc/util.h>
end_include

begin_comment
comment|/*! \file isc/refcount.h  * \brief Implements a locked reference counter.  *  * These functions may actually be  * implemented using macros, and implementations of these macros are below.  * The isc_refcount_t type should not be accessed directly, as its contents  * depend on the implementation.  */
end_comment

begin_macro
name|ISC_LANG_BEGINDECLS
end_macro

begin_comment
comment|/*  * Function prototypes  */
end_comment

begin_comment
comment|/*  * isc_result_t  * isc_refcount_init(isc_refcount_t *ref, unsigned int n);  *  * Initialize the reference counter.  There will be 'n' initial references.  *  * Requires:  *	ref != NULL  */
end_comment

begin_comment
comment|/*  * void  * isc_refcount_destroy(isc_refcount_t *ref);  *  * Destroys a reference counter.  *  * Requires:  *	ref != NULL  *	The number of references is 0.  */
end_comment

begin_comment
comment|/*  * void  * isc_refcount_increment(isc_refcount_t *ref, unsigned int *targetp);  * isc_refcount_increment0(isc_refcount_t *ref, unsigned int *targetp);  *  * Increments the reference count, returning the new value in targetp if it's  * not NULL.  The reference counter typically begins with the initial counter  * of 1, and will be destroyed once the counter reaches 0.  Thus,  * isc_refcount_increment() additionally requires the previous counter be  * larger than 0 so that an error which violates the usage can be easily  * caught.  isc_refcount_increment0() does not have this restriction.  *  * Requires:  *	ref != NULL.  */
end_comment

begin_comment
comment|/*  * void  * isc_refcount_decrement(isc_refcount_t *ref, unsigned int *targetp);  *  * Decrements the reference count,  returning the new value in targetp if it's  * not NULL.  *  * Requires:  *	ref != NULL.  */
end_comment

begin_comment
comment|/*  * Sample implementations  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ISC_PLATFORM_USETHREADS
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|ISC_PLATFORM_HAVEXADD
end_ifdef

begin_define
define|#
directive|define
name|ISC_REFCOUNT_HAVEATOMIC
value|1
end_define

begin_typedef
typedef|typedef
struct|struct
name|isc_refcount
block|{
name|isc_int32_t
name|refs
decl_stmt|;
block|}
name|isc_refcount_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|isc_refcount_destroy
parameter_list|(
name|rp
parameter_list|)
value|REQUIRE((rp)->refs == 0)
end_define

begin_define
define|#
directive|define
name|isc_refcount_current
parameter_list|(
name|rp
parameter_list|)
value|((unsigned int)((rp)->refs))
end_define

begin_define
define|#
directive|define
name|isc_refcount_increment0
parameter_list|(
name|rp
parameter_list|,
name|tp
parameter_list|)
define|\
value|do {							\ 		unsigned int *_tmp = (unsigned int *)(tp);	\ 		isc_int32_t prev;				\ 		prev = isc_atomic_xadd(&(rp)->refs, 1);		\ 		if (_tmp != NULL)				\ 			*_tmp = prev + 1;			\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|isc_refcount_increment
parameter_list|(
name|rp
parameter_list|,
name|tp
parameter_list|)
define|\
value|do {							\ 		unsigned int *_tmp = (unsigned int *)(tp);	\ 		isc_int32_t prev;				\ 		prev = isc_atomic_xadd(&(rp)->refs, 1);		\ 		REQUIRE(prev> 0);				\ 		if (_tmp != NULL)				\ 			*_tmp = prev + 1;			\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|isc_refcount_decrement
parameter_list|(
name|rp
parameter_list|,
name|tp
parameter_list|)
define|\
value|do {							\ 		unsigned int *_tmp = (unsigned int *)(tp);	\ 		isc_int32_t prev;				\ 		prev = isc_atomic_xadd(&(rp)->refs, -1);	\ 		REQUIRE(prev> 0);				\ 		if (_tmp != NULL)				\ 			*_tmp = prev - 1;			\ 	} while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ISC_PLATFORM_HAVEXADD */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|isc_refcount
block|{
name|int
name|refs
decl_stmt|;
name|isc_mutex_t
name|lock
decl_stmt|;
block|}
name|isc_refcount_t
typedef|;
end_typedef

begin_comment
comment|/*% Destroys a reference counter. */
end_comment

begin_define
define|#
directive|define
name|isc_refcount_destroy
parameter_list|(
name|rp
parameter_list|)
define|\
value|do {						\ 		REQUIRE((rp)->refs == 0);		\ 		DESTROYLOCK(&(rp)->lock);		\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|isc_refcount_current
parameter_list|(
name|rp
parameter_list|)
value|((unsigned int)((rp)->refs))
end_define

begin_comment
comment|/*% Increments the reference count, returning the new value in targetp if it's not NULL. */
end_comment

begin_define
define|#
directive|define
name|isc_refcount_increment0
parameter_list|(
name|rp
parameter_list|,
name|tp
parameter_list|)
define|\
value|do {							\ 		unsigned int *_tmp = (unsigned int *)(tp);	\ 		LOCK(&(rp)->lock);				\ 		++((rp)->refs);					\ 		if (_tmp != NULL)				\ 			*_tmp = ((rp)->refs);			\ 		UNLOCK(&(rp)->lock);				\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|isc_refcount_increment
parameter_list|(
name|rp
parameter_list|,
name|tp
parameter_list|)
define|\
value|do {							\ 		unsigned int *_tmp = (unsigned int *)(tp);	\ 		LOCK(&(rp)->lock);				\ 		REQUIRE((rp)->refs> 0);			\ 		++((rp)->refs);					\ 		if (_tmp != NULL)				\ 			*_tmp = ((rp)->refs);			\ 		UNLOCK(&(rp)->lock);				\ 	} while (0)
end_define

begin_comment
comment|/*% Decrements the reference count,  returning the new value in targetp if it's not NULL. */
end_comment

begin_define
define|#
directive|define
name|isc_refcount_decrement
parameter_list|(
name|rp
parameter_list|,
name|tp
parameter_list|)
define|\
value|do {							\ 		unsigned int *_tmp = (unsigned int *)(tp);	\ 		LOCK(&(rp)->lock);				\ 		REQUIRE((rp)->refs> 0);			\ 		--((rp)->refs);					\ 		if (_tmp != NULL)				\ 			*_tmp = ((rp)->refs);			\ 		UNLOCK(&(rp)->lock);				\ 	} while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISC_PLATFORM_HAVEXADD */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ISC_PLATFORM_USETHREADS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|isc_refcount
block|{
name|int
name|refs
decl_stmt|;
block|}
name|isc_refcount_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|isc_refcount_destroy
parameter_list|(
name|rp
parameter_list|)
value|REQUIRE((rp)->refs == 0)
end_define

begin_define
define|#
directive|define
name|isc_refcount_current
parameter_list|(
name|rp
parameter_list|)
value|((unsigned int)((rp)->refs))
end_define

begin_define
define|#
directive|define
name|isc_refcount_increment0
parameter_list|(
name|rp
parameter_list|,
name|tp
parameter_list|)
define|\
value|do {								\ 		unsigned int *_tmp = (unsigned int *)(tp);		\ 		int _n = ++(rp)->refs;					\ 		if (_tmp != NULL)					\ 			*_tmp = _n;					\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|isc_refcount_increment
parameter_list|(
name|rp
parameter_list|,
name|tp
parameter_list|)
define|\
value|do {								\ 		unsigned int *_tmp = (unsigned int *)(tp);		\ 		int _n;							\ 		REQUIRE((rp)->refs> 0);				\ 		_n = ++(rp)->refs;					\ 		if (_tmp != NULL)					\ 			*_tmp = _n;					\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|isc_refcount_decrement
parameter_list|(
name|rp
parameter_list|,
name|tp
parameter_list|)
define|\
value|do {								\ 		unsigned int *_tmp = (unsigned int *)(tp);		\ 		int _n;							\ 		REQUIRE((rp)->refs> 0);				\ 		_n = --(rp)->refs;					\ 		if (_tmp != NULL)					\ 			*_tmp = _n;					\ 	} while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISC_PLATFORM_USETHREADS */
end_comment

begin_function_decl
name|isc_result_t
name|isc_refcount_init
parameter_list|(
name|isc_refcount_t
modifier|*
name|ref
parameter_list|,
name|unsigned
name|int
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISC_REFCOUNT_H */
end_comment

end_unit

