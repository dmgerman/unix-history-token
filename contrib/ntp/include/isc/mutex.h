begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2000, 2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND INTERNET SOFTWARE CONSORTIUM  * DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL  * INTERNET SOFTWARE CONSORTIUM BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING  * FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT,  * NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION  * WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: mutex.h,v 1.3 2001/01/09 21:57:55 bwelling Exp $ */
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
file|<isc/result.h>
end_include

begin_comment
comment|/* for ISC_R_ codes */
end_comment

begin_typedef
typedef|typedef
name|int
name|isc_mutex_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|isc_mutex_init
parameter_list|(
name|mp
parameter_list|)
define|\
value|(*(mp) = 0, ISC_R_SUCCESS)
end_define

begin_define
define|#
directive|define
name|isc_mutex_lock
parameter_list|(
name|mp
parameter_list|)
define|\
value|((*(mp))++ == 0 ? ISC_R_SUCCESS : ISC_R_UNEXPECTED)
end_define

begin_define
define|#
directive|define
name|isc_mutex_unlock
parameter_list|(
name|mp
parameter_list|)
define|\
value|(--(*(mp)) == 0 ? ISC_R_SUCCESS : ISC_R_UNEXPECTED)
end_define

begin_define
define|#
directive|define
name|isc_mutex_trylock
parameter_list|(
name|mp
parameter_list|)
define|\
value|(*(mp) == 0 ? ((*(mp))++, ISC_R_SUCCESS) : ISC_R_LOCKBUSY)
end_define

begin_define
define|#
directive|define
name|isc_mutex_destroy
parameter_list|(
name|mp
parameter_list|)
define|\
value|(*(mp) == 0 ? (*(mp) = -1, ISC_R_SUCCESS) : ISC_R_UNEXPECTED)
end_define

begin_define
define|#
directive|define
name|isc_mutex_stats
parameter_list|(
name|fp
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISC_MUTEX_H */
end_comment

end_unit

