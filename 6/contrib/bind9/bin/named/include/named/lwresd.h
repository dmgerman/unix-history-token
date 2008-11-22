begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004, 2006  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 2000, 2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: lwresd.h,v 1.12.208.3 2006/03/02 00:37:20 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NAMED_LWRESD_H
end_ifndef

begin_define
define|#
directive|define
name|NAMED_LWRESD_H
value|1
end_define

begin_include
include|#
directive|include
file|<isc/types.h>
end_include

begin_include
include|#
directive|include
file|<isc/sockaddr.h>
end_include

begin_include
include|#
directive|include
file|<isccfg/cfg.h>
end_include

begin_include
include|#
directive|include
file|<dns/types.h>
end_include

begin_struct
struct|struct
name|ns_lwresd
block|{
name|unsigned
name|int
name|magic
decl_stmt|;
name|isc_mutex_t
name|lock
decl_stmt|;
name|dns_view_t
modifier|*
name|view
decl_stmt|;
name|ns_lwsearchlist_t
modifier|*
name|search
decl_stmt|;
name|unsigned
name|int
name|ndots
decl_stmt|;
name|isc_mem_t
modifier|*
name|mctx
decl_stmt|;
name|isc_boolean_t
name|shutting_down
decl_stmt|;
name|unsigned
name|int
name|refs
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ns_lwreslistener
block|{
name|unsigned
name|int
name|magic
decl_stmt|;
name|isc_mutex_t
name|lock
decl_stmt|;
name|isc_mem_t
modifier|*
name|mctx
decl_stmt|;
name|isc_sockaddr_t
name|address
decl_stmt|;
name|ns_lwresd_t
modifier|*
name|manager
decl_stmt|;
name|isc_socket_t
modifier|*
name|sock
decl_stmt|;
name|unsigned
name|int
name|refs
decl_stmt|;
name|ISC_LIST
argument_list|(
argument|ns_lwdclientmgr_t
argument_list|)
name|cmgrs
expr_stmt|;
name|ISC_LINK
argument_list|(
argument|ns_lwreslistener_t
argument_list|)
name|link
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Configure lwresd.  */
end_comment

begin_function_decl
name|isc_result_t
name|ns_lwresd_configure
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
specifier|const
name|cfg_obj_t
modifier|*
name|config
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|ns_lwresd_parseeresolvconf
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|cfg_parser_t
modifier|*
name|pctx
parameter_list|,
name|cfg_obj_t
modifier|*
modifier|*
name|configp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Trigger shutdown.  */
end_comment

begin_function_decl
name|void
name|ns_lwresd_shutdown
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Manager functions  */
end_comment

begin_function_decl
name|isc_result_t
name|ns_lwdmanager_create
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
specifier|const
name|cfg_obj_t
modifier|*
name|lwres
parameter_list|,
name|ns_lwresd_t
modifier|*
modifier|*
name|lwresdp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ns_lwdmanager_attach
parameter_list|(
name|ns_lwresd_t
modifier|*
name|source
parameter_list|,
name|ns_lwresd_t
modifier|*
modifier|*
name|targetp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ns_lwdmanager_detach
parameter_list|(
name|ns_lwresd_t
modifier|*
modifier|*
name|lwresdp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Listener functions  */
end_comment

begin_function_decl
name|void
name|ns_lwreslistener_attach
parameter_list|(
name|ns_lwreslistener_t
modifier|*
name|source
parameter_list|,
name|ns_lwreslistener_t
modifier|*
modifier|*
name|targetp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ns_lwreslistener_detach
parameter_list|(
name|ns_lwreslistener_t
modifier|*
modifier|*
name|listenerp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ns_lwreslistener_unlinkcm
parameter_list|(
name|ns_lwreslistener_t
modifier|*
name|listener
parameter_list|,
name|ns_lwdclientmgr_t
modifier|*
name|cm
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ns_lwreslistener_linkcm
parameter_list|(
name|ns_lwreslistener_t
modifier|*
name|listener
parameter_list|,
name|ns_lwdclientmgr_t
modifier|*
name|cm
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * INTERNAL FUNCTIONS.  */
end_comment

begin_function_decl
name|void
modifier|*
name|ns__lwresd_memalloc
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ns__lwresd_memfree
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|,
name|void
modifier|*
name|mem
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NAMED_LWRESD_H */
end_comment

end_unit

