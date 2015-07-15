begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004, 2005, 2007-2009  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 2000, 2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: socket_p.h,v 1.15 2009/09/02 23:48:03 tbox Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_SOCKET_P_H
end_ifndef

begin_define
define|#
directive|define
name|ISC_SOCKET_P_H
end_define

begin_comment
comment|/*! \file */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ISC_PLATFORM_NEEDSYSSELECTH
end_ifdef

begin_include
include|#
directive|include
file|<sys/select.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|struct
name|isc_socketwait
name|isc_socketwait_t
typedef|;
end_typedef

begin_function_decl
name|int
name|isc__socketmgr_waitevents
parameter_list|(
name|isc_socketmgr_t
modifier|*
parameter_list|,
name|struct
name|timeval
modifier|*
parameter_list|,
name|isc_socketwait_t
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|isc__socketmgr_dispatch
parameter_list|(
name|isc_socketmgr_t
modifier|*
parameter_list|,
name|isc_socketwait_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISC_SOCKET_P_H */
end_comment

end_unit

