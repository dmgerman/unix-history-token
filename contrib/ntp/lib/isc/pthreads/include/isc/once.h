begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004, 2005, 2007  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1999-2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: once.h,v 1.13 2007/06/19 23:47:18 tbox Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_ONCE_H
end_ifndef

begin_define
define|#
directive|define
name|ISC_ONCE_H
value|1
end_define

begin_comment
comment|/*! \file */
end_comment

begin_include
include|#
directive|include
file|<pthread.h>
end_include

begin_include
include|#
directive|include
file|<isc/platform.h>
end_include

begin_include
include|#
directive|include
file|<isc/result.h>
end_include

begin_typedef
typedef|typedef
name|pthread_once_t
name|isc_once_t
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|ISC_PLATFORM_BRACEPTHREADONCEINIT
end_ifdef

begin_comment
comment|/*!  * This accomodates systems that define PTHRAD_ONCE_INIT improperly.  */
end_comment

begin_define
define|#
directive|define
name|ISC_ONCE_INIT
value|{ PTHREAD_ONCE_INIT }
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*!  * This is the usual case.  */
end_comment

begin_define
define|#
directive|define
name|ISC_ONCE_INIT
value|PTHREAD_ONCE_INIT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* XXX We could do fancier error handling... */
end_comment

begin_define
define|#
directive|define
name|isc_once_do
parameter_list|(
name|op
parameter_list|,
name|f
parameter_list|)
define|\
value|((pthread_once((op), (f)) == 0) ? \ 	 ISC_R_SUCCESS : ISC_R_UNEXPECTED)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISC_ONCE_H */
end_comment

end_unit

