begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 2000, 2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: condition.h,v 1.3.206.1 2004/03/06 08:14:52 marka Exp $ */
end_comment

begin_comment
comment|/*  * This provides a limited subset of the isc_condition_t  * functionality for use by single-threaded programs that  * need to block waiting for events.   Only a single  * call to isc_condition_wait() may be blocked at any given  * time, and the _waituntil and _broadcast functions are not  * supported.  This is intended primarily for use by the omapi  * library, and may go away once omapi goes away.  Use for  * other purposes is strongly discouraged.  */
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
file|<isc/mutex.h>
end_include

begin_typedef
typedef|typedef
name|int
name|isc_condition_t
typedef|;
end_typedef

begin_function_decl
name|isc_result_t
name|isc__nothread_wait_hack
parameter_list|(
name|isc_condition_t
modifier|*
name|cp
parameter_list|,
name|isc_mutex_t
modifier|*
name|mp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|isc__nothread_signal_hack
parameter_list|(
name|isc_condition_t
modifier|*
name|cp
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|isc_condition_init
parameter_list|(
name|cp
parameter_list|)
define|\
value|(*(cp) = 0, ISC_R_SUCCESS)
end_define

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
value|isc__nothread_wait_hack(cp, mp)
end_define

begin_define
define|#
directive|define
name|isc_condition_waituntil
parameter_list|(
name|cp
parameter_list|,
name|mp
parameter_list|,
name|tp
parameter_list|)
define|\
value|((void)(cp), (void)(mp), (void)(tp), ISC_R_NOTIMPLEMENTED)
end_define

begin_define
define|#
directive|define
name|isc_condition_signal
parameter_list|(
name|cp
parameter_list|)
define|\
value|isc__nothread_signal_hack(cp)
end_define

begin_define
define|#
directive|define
name|isc_condition_broadcast
parameter_list|(
name|cp
parameter_list|)
define|\
value|((void)(cp), ISC_R_NOTIMPLEMENTED)
end_define

begin_define
define|#
directive|define
name|isc_condition_destroy
parameter_list|(
name|cp
parameter_list|)
define|\
value|(*(cp) == 0 ? (*(cp) = -1, ISC_R_SUCCESS) : ISC_R_UNEXPECTED)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISC_CONDITION_H */
end_comment

end_unit

