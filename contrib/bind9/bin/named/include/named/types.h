begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1999-2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: types.h,v 1.19.208.2 2004/03/06 10:21:26 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NAMED_TYPES_H
end_ifndef

begin_define
define|#
directive|define
name|NAMED_TYPES_H
value|1
end_define

begin_include
include|#
directive|include
file|<dns/types.h>
end_include

begin_typedef
typedef|typedef
name|struct
name|ns_client
name|ns_client_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|ns_clientmgr
name|ns_clientmgr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|ns_query
name|ns_query_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|ns_server
name|ns_server_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|ns_interface
name|ns_interface_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|ns_interfacemgr
name|ns_interfacemgr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|ns_lwresd
name|ns_lwresd_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|ns_lwreslistener
name|ns_lwreslistener_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|ns_lwdclient
name|ns_lwdclient_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|ns_lwdclientmgr
name|ns_lwdclientmgr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|ns_lwsearchlist
name|ns_lwsearchlist_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|ns_lwsearchctx
name|ns_lwsearchctx_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|ns_controls
name|ns_controls_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|ns_dispatch
name|ns_dispatch_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ISC_LIST
argument_list|(
argument|ns_dispatch_t
argument_list|)
name|ns_dispatchlist_t
expr_stmt|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NAMED_TYPES_H */
end_comment

end_unit

