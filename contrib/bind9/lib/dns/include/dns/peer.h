begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004, 2006  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 2000, 2001, 2003  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: peer.h,v 1.16.2.1.10.5 2006/03/02 00:37:20 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DNS_PEER_H
end_ifndef

begin_define
define|#
directive|define
name|DNS_PEER_H
value|1
end_define

begin_comment
comment|/*****  ***** Module Info  *****/
end_comment

begin_comment
comment|/*  * Data structures for peers (e.g. a 'server' config file statement)  */
end_comment

begin_comment
comment|/***  *** Imports  ***/
end_comment

begin_include
include|#
directive|include
file|<isc/lang.h>
end_include

begin_include
include|#
directive|include
file|<isc/magic.h>
end_include

begin_include
include|#
directive|include
file|<isc/netaddr.h>
end_include

begin_include
include|#
directive|include
file|<dns/types.h>
end_include

begin_define
define|#
directive|define
name|DNS_PEERLIST_MAGIC
value|ISC_MAGIC('s','e','R','L')
end_define

begin_define
define|#
directive|define
name|DNS_PEER_MAGIC
value|ISC_MAGIC('S','E','r','v')
end_define

begin_define
define|#
directive|define
name|DNS_PEERLIST_VALID
parameter_list|(
name|ptr
parameter_list|)
value|ISC_MAGIC_VALID(ptr, DNS_PEERLIST_MAGIC)
end_define

begin_define
define|#
directive|define
name|DNS_PEER_VALID
parameter_list|(
name|ptr
parameter_list|)
value|ISC_MAGIC_VALID(ptr, DNS_PEER_MAGIC)
end_define

begin_comment
comment|/***  *** Types  ***/
end_comment

begin_struct
struct|struct
name|dns_peerlist
block|{
name|unsigned
name|int
name|magic
decl_stmt|;
name|isc_uint32_t
name|refs
decl_stmt|;
name|isc_mem_t
modifier|*
name|mem
decl_stmt|;
name|ISC_LIST
argument_list|(
argument|dns_peer_t
argument_list|)
name|elements
expr_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|dns_peer
block|{
name|unsigned
name|int
name|magic
decl_stmt|;
name|isc_uint32_t
name|refs
decl_stmt|;
name|isc_mem_t
modifier|*
name|mem
decl_stmt|;
name|isc_netaddr_t
name|address
decl_stmt|;
name|isc_boolean_t
name|bogus
decl_stmt|;
name|dns_transfer_format_t
name|transfer_format
decl_stmt|;
name|isc_uint32_t
name|transfers
decl_stmt|;
name|isc_boolean_t
name|support_ixfr
decl_stmt|;
name|isc_boolean_t
name|provide_ixfr
decl_stmt|;
name|isc_boolean_t
name|request_ixfr
decl_stmt|;
name|isc_boolean_t
name|support_edns
decl_stmt|;
name|dns_name_t
modifier|*
name|key
decl_stmt|;
name|isc_sockaddr_t
modifier|*
name|transfer_source
decl_stmt|;
name|isc_uint32_t
name|bitflags
decl_stmt|;
name|ISC_LINK
argument_list|(
argument|dns_peer_t
argument_list|)
name|next
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/***  *** Functions  ***/
end_comment

begin_function_decl
name|ISC_LANG_BEGINDECLS
name|isc_result_t
name|dns_peerlist_new
parameter_list|(
name|isc_mem_t
modifier|*
name|mem
parameter_list|,
name|dns_peerlist_t
modifier|*
modifier|*
name|list
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dns_peerlist_attach
parameter_list|(
name|dns_peerlist_t
modifier|*
name|source
parameter_list|,
name|dns_peerlist_t
modifier|*
modifier|*
name|target
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dns_peerlist_detach
parameter_list|(
name|dns_peerlist_t
modifier|*
modifier|*
name|list
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * After return caller still holds a reference to peer.  */
end_comment

begin_function_decl
name|void
name|dns_peerlist_addpeer
parameter_list|(
name|dns_peerlist_t
modifier|*
name|peers
parameter_list|,
name|dns_peer_t
modifier|*
name|peer
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Ditto. */
end_comment

begin_function_decl
name|isc_result_t
name|dns_peerlist_peerbyaddr
parameter_list|(
name|dns_peerlist_t
modifier|*
name|peers
parameter_list|,
name|isc_netaddr_t
modifier|*
name|addr
parameter_list|,
name|dns_peer_t
modifier|*
modifier|*
name|retval
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * What he said.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_peerlist_currpeer
parameter_list|(
name|dns_peerlist_t
modifier|*
name|peers
parameter_list|,
name|dns_peer_t
modifier|*
modifier|*
name|retval
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|dns_peer_new
parameter_list|(
name|isc_mem_t
modifier|*
name|mem
parameter_list|,
name|isc_netaddr_t
modifier|*
name|ipaddr
parameter_list|,
name|dns_peer_t
modifier|*
modifier|*
name|peer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dns_peer_attach
parameter_list|(
name|dns_peer_t
modifier|*
name|source
parameter_list|,
name|dns_peer_t
modifier|*
modifier|*
name|target
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dns_peer_detach
parameter_list|(
name|dns_peer_t
modifier|*
modifier|*
name|list
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|dns_peer_setbogus
parameter_list|(
name|dns_peer_t
modifier|*
name|peer
parameter_list|,
name|isc_boolean_t
name|newval
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|dns_peer_getbogus
parameter_list|(
name|dns_peer_t
modifier|*
name|peer
parameter_list|,
name|isc_boolean_t
modifier|*
name|retval
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|dns_peer_setrequestixfr
parameter_list|(
name|dns_peer_t
modifier|*
name|peer
parameter_list|,
name|isc_boolean_t
name|newval
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|dns_peer_getrequestixfr
parameter_list|(
name|dns_peer_t
modifier|*
name|peer
parameter_list|,
name|isc_boolean_t
modifier|*
name|retval
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|dns_peer_setprovideixfr
parameter_list|(
name|dns_peer_t
modifier|*
name|peer
parameter_list|,
name|isc_boolean_t
name|newval
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|dns_peer_getprovideixfr
parameter_list|(
name|dns_peer_t
modifier|*
name|peer
parameter_list|,
name|isc_boolean_t
modifier|*
name|retval
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|dns_peer_setsupportedns
parameter_list|(
name|dns_peer_t
modifier|*
name|peer
parameter_list|,
name|isc_boolean_t
name|newval
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|dns_peer_getsupportedns
parameter_list|(
name|dns_peer_t
modifier|*
name|peer
parameter_list|,
name|isc_boolean_t
modifier|*
name|retval
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|dns_peer_settransfers
parameter_list|(
name|dns_peer_t
modifier|*
name|peer
parameter_list|,
name|isc_uint32_t
name|newval
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|dns_peer_gettransfers
parameter_list|(
name|dns_peer_t
modifier|*
name|peer
parameter_list|,
name|isc_uint32_t
modifier|*
name|retval
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|dns_peer_settransferformat
parameter_list|(
name|dns_peer_t
modifier|*
name|peer
parameter_list|,
name|dns_transfer_format_t
name|newval
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|dns_peer_gettransferformat
parameter_list|(
name|dns_peer_t
modifier|*
name|peer
parameter_list|,
name|dns_transfer_format_t
modifier|*
name|retval
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|dns_peer_setkeybycharp
parameter_list|(
name|dns_peer_t
modifier|*
name|peer
parameter_list|,
specifier|const
name|char
modifier|*
name|keyval
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|dns_peer_getkey
parameter_list|(
name|dns_peer_t
modifier|*
name|peer
parameter_list|,
name|dns_name_t
modifier|*
modifier|*
name|retval
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|dns_peer_setkey
parameter_list|(
name|dns_peer_t
modifier|*
name|peer
parameter_list|,
name|dns_name_t
modifier|*
modifier|*
name|keyval
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|dns_peer_settransfersource
parameter_list|(
name|dns_peer_t
modifier|*
name|peer
parameter_list|,
specifier|const
name|isc_sockaddr_t
modifier|*
name|transfer_source
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|dns_peer_gettransfersource
parameter_list|(
name|dns_peer_t
modifier|*
name|peer
parameter_list|,
name|isc_sockaddr_t
modifier|*
name|transfer_source
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
comment|/* DNS_PEER_H */
end_comment

end_unit

