begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1998-2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: condition.h,v 1.21.206.1 2004/03/06 08:14:56 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_CONDITION_H
end_ifndef

begin_define
define|#
directive|define
name|ISC_CONDITION_H
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
file|<isc/result.h>
end_include

begin_include
include|#
directive|include
file|<isc/types.h>
end_include

begin_typedef
typedef|typedef
name|pthread_cond_t
name|isc_condition_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|isc_condition_init
parameter_list|(
name|cp
parameter_list|)
define|\
value|((pthread_cond_init((cp), NULL) == 0) ? \ 	 ISC_R_SUCCESS : ISC_R_UNEXPECTED)
end_define

begin_if
if|#
directive|if
name|ISC_MUTEX_PROFILE
end_if

begin_define
define|#
directive|define
name|isc_condition_wait
parameter_list|(
name|cp
parameter_list|,
name|mp
parameter_list|)
define|\
value|((pthread_cond_wait((cp),&((mp)->mutex)) == 0) ? \ 	 ISC_R_SUCCESS : ISC_R_UNEXPECTED)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|isc_condition_wait
parameter_list|(
name|cp
parameter_list|,
name|mp
parameter_list|)
define|\
value|((pthread_cond_wait((cp), (mp)) == 0) ? \ 	 ISC_R_SUCCESS : ISC_R_UNEXPECTED)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|isc_condition_signal
parameter_list|(
name|cp
parameter_list|)
define|\
value|((pthread_cond_signal((cp)) == 0) ? \ 	 ISC_R_SUCCESS : ISC_R_UNEXPECTED)
end_define

begin_define
define|#
directive|define
name|isc_condition_broadcast
parameter_list|(
name|cp
parameter_list|)
define|\
value|((pthread_cond_broadcast((cp)) == 0) ? \ 	 ISC_R_SUCCESS : ISC_R_UNEXPECTED)
end_define

begin_define
define|#
directive|define
name|isc_condition_destroy
parameter_list|(
name|cp
parameter_list|)
define|\
value|((pthread_cond_destroy((cp)) == 0) ? \ 	 ISC_R_SUCCESS : ISC_R_UNEXPECTED)
end_define

begin_function_decl
name|ISC_LANG_BEGINDECLS
name|isc_result_t
name|isc_condition_waituntil
parameter_list|(
name|isc_condition_t
modifier|*
parameter_list|,
name|isc_mutex_t
modifier|*
parameter_list|,
name|isc_time_t
modifier|*
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
comment|/* ISC_CONDITION_H */
end_comment

end_unit

