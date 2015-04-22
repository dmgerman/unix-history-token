begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004, 2007-2009  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1998-2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: mutex.h,v 1.22 2009/01/18 23:48:14 tbox Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_MUTEX_H
end_ifndef

begin_define
define|#
directive|define
name|ISC_MUTEX_H
value|1
end_define

begin_include
include|#
directive|include
file|<isc/net.h>
end_include

begin_include
include|#
directive|include
file|<windows.h>
end_include

begin_include
include|#
directive|include
file|<isc/result.h>
end_include

begin_typedef
typedef|typedef
name|CRITICAL_SECTION
name|isc_mutex_t
typedef|;
end_typedef

begin_comment
comment|/*  * This definition is here since some versions of WINBASE.H  * omits it for some reason.  */
end_comment

begin_if
if|#
directive|if
operator|(
name|_WIN32_WINNT
operator|<
literal|0x0400
operator|)
end_if

begin_function_decl
name|WINBASEAPI
name|BOOL
name|WINAPI
name|TryEnterCriticalSection
parameter_list|(
name|LPCRITICAL_SECTION
name|lpCriticalSection
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _WIN32_WINNT< 0x0400 */
end_comment

begin_define
define|#
directive|define
name|isc_mutex_init
parameter_list|(
name|mp
parameter_list|)
define|\
value|(InitializeCriticalSection((mp)), ISC_R_SUCCESS)
end_define

begin_define
define|#
directive|define
name|isc_mutex_lock
parameter_list|(
name|mp
parameter_list|)
define|\
value|(EnterCriticalSection((mp)), ISC_R_SUCCESS)
end_define

begin_define
define|#
directive|define
name|isc_mutex_unlock
parameter_list|(
name|mp
parameter_list|)
define|\
value|(LeaveCriticalSection((mp)), ISC_R_SUCCESS)
end_define

begin_define
define|#
directive|define
name|isc_mutex_trylock
parameter_list|(
name|mp
parameter_list|)
define|\
value|(TryEnterCriticalSection((mp)) ? ISC_R_SUCCESS : ISC_R_LOCKBUSY)
end_define

begin_define
define|#
directive|define
name|isc_mutex_destroy
parameter_list|(
name|mp
parameter_list|)
define|\
value|(DeleteCriticalSection((mp)), ISC_R_SUCCESS)
end_define

begin_comment
comment|/*  * This is a placeholder for now since we are not keeping any mutex stats  */
end_comment

begin_define
define|#
directive|define
name|isc_mutex_stats
parameter_list|(
name|fp
parameter_list|)
value|do {} while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISC_MUTEX_H */
end_comment

end_unit

