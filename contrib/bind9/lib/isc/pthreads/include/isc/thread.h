begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1998-2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: thread.h,v 1.19.206.1 2004/03/06 08:14:57 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_THREAD_H
end_ifndef

begin_define
define|#
directive|define
name|ISC_THREAD_H
value|1
end_define

begin_include
include|#
directive|include
file|<pthread.h>
end_include

begin_include
include|#
directive|include
file|<isc/lang.h>
end_include

begin_include
include|#
directive|include
file|<isc/result.h>
end_include

begin_macro
name|ISC_LANG_BEGINDECLS
end_macro

begin_typedef
typedef|typedef
name|pthread_t
name|isc_thread_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
modifier|*
name|isc_threadresult_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
modifier|*
name|isc_threadarg_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|isc_threadresult_t
function_decl|(
modifier|*
name|isc_threadfunc_t
function_decl|)
parameter_list|(
name|isc_threadarg_t
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|isc_result_t
name|isc_thread_create
parameter_list|(
name|isc_threadfunc_t
parameter_list|,
name|isc_threadarg_t
parameter_list|,
name|isc_thread_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|isc_thread_setconcurrency
parameter_list|(
name|unsigned
name|int
name|level
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* XXX We could do fancier error handling... */
end_comment

begin_define
define|#
directive|define
name|isc_thread_join
parameter_list|(
name|t
parameter_list|,
name|rp
parameter_list|)
define|\
value|((pthread_join((t), (rp)) == 0) ? \ 	 ISC_R_SUCCESS : ISC_R_UNEXPECTED)
end_define

begin_define
define|#
directive|define
name|isc_thread_self
define|\
value|(unsigned long)pthread_self
end_define

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISC_THREAD_H */
end_comment

end_unit

