begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 2001, 2003  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: refcount.h,v 1.3.2.2.2.2 2004/04/14 05:12:25 marka Exp $ */
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
comment|/*  * Implements a locked reference counter.  These functions may actually be  * implemented using macros, and implementations of these macros are below.  * The isc_refcount_t type should not be accessed directly, as its contents  * depend on the implementation.  */
end_comment

begin_macro
name|ISC_LANG_BEGINDECLS
end_macro

begin_comment
comment|/*  * Function prototypes  */
end_comment

begin_comment
comment|/*  * void  * isc_refcount_init(isc_refcount_t *ref, unsigned int n);  *  * Initialize the reference counter.  There will be 'n' initial references.  *  * Requires:  *	ref != NULL  */
end_comment

begin_comment
comment|/*  * void  * isc_refcount_destroy(isc_refcount_t *ref);  *  * Destroys a reference counter.  *  * Requires:  *	ref != NULL  *	The number of references is 0.  */
end_comment

begin_comment
comment|/*  * void  * isc_refcount_increment(isc_refcount_t *ref, unsigned int *targetp);  *  * Increments the reference count, returning the new value in targetp if it's  * not NULL.  *  * Requires:  *	ref != NULL.  */
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

begin_define
define|#
directive|define
name|isc_refcount_init
parameter_list|(
name|rp
parameter_list|,
name|n
parameter_list|)
define|\
value|do {						\ 		isc_result_t _r;			\ 		(rp)->refs = (n);			\ 		_r = isc_mutex_init(&(rp)->lock);	\ 		RUNTIME_CHECK(_r == ISC_R_SUCCESS);	\ 	} while (0)
end_define

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

begin_else
else|#
directive|else
end_else

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
name|isc_refcount_init
parameter_list|(
name|rp
parameter_list|,
name|n
parameter_list|)
value|((rp)->refs = (n))
end_define

begin_define
define|#
directive|define
name|isc_refcount_destroy
parameter_list|(
name|rp
parameter_list|)
value|(REQUIRE((rp)->refs == 0))
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
name|isc_refcount_increment
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
name|isc_refcount_decrement
parameter_list|(
name|rp
parameter_list|,
name|tp
parameter_list|)
define|\
value|do {								\ 		unsigned int *_tmp = (unsigned int *)(tp);		\ 		int _n = --(rp)->refs;					\ 		if (_tmp != NULL)					\ 			*_tmp = _n;					\ 	} while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

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

