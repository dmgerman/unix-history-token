begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 2000, 2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: lwdclient.h,v 1.13.208.1 2004/03/06 10:21:24 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NAMED_LWDCLIENT_H
end_ifndef

begin_define
define|#
directive|define
name|NAMED_LWDCLIENT_H
value|1
end_define

begin_include
include|#
directive|include
file|<isc/event.h>
end_include

begin_include
include|#
directive|include
file|<isc/eventclass.h>
end_include

begin_include
include|#
directive|include
file|<isc/netaddr.h>
end_include

begin_include
include|#
directive|include
file|<isc/sockaddr.h>
end_include

begin_include
include|#
directive|include
file|<isc/types.h>
end_include

begin_include
include|#
directive|include
file|<dns/fixedname.h>
end_include

begin_include
include|#
directive|include
file|<dns/types.h>
end_include

begin_include
include|#
directive|include
file|<lwres/lwres.h>
end_include

begin_include
include|#
directive|include
file|<named/lwsearch.h>
end_include

begin_define
define|#
directive|define
name|LWRD_EVENTCLASS
value|ISC_EVENTCLASS(4242)
end_define

begin_define
define|#
directive|define
name|LWRD_SHUTDOWN
value|(LWRD_EVENTCLASS + 0x0001)
end_define

begin_struct
struct|struct
name|ns_lwdclient
block|{
name|isc_sockaddr_t
name|address
decl_stmt|;
comment|/* where to reply */
name|struct
name|in6_pktinfo
name|pktinfo
decl_stmt|;
name|isc_boolean_t
name|pktinfo_valid
decl_stmt|;
name|ns_lwdclientmgr_t
modifier|*
name|clientmgr
decl_stmt|;
comment|/* our parent */
name|ISC_LINK
argument_list|(
argument|ns_lwdclient_t
argument_list|)
name|link
expr_stmt|;
name|unsigned
name|int
name|state
decl_stmt|;
name|void
modifier|*
name|arg
decl_stmt|;
comment|/* packet processing state */
comment|/* 	 * Received data info. 	 */
name|unsigned
name|char
name|buffer
index|[
name|LWRES_RECVLENGTH
index|]
decl_stmt|;
comment|/* receive buffer */
name|isc_uint32_t
name|recvlength
decl_stmt|;
comment|/* length recv'd */
name|lwres_lwpacket_t
name|pkt
decl_stmt|;
comment|/* 	 * Send data state.  If sendbuf != buffer (that is, the send buffer 	 * isn't our receive buffer) it will be freed to the lwres_context_t. 	 */
name|unsigned
name|char
modifier|*
name|sendbuf
decl_stmt|;
name|isc_uint32_t
name|sendlength
decl_stmt|;
name|isc_buffer_t
name|recv_buffer
decl_stmt|;
comment|/* 	 * gabn (get address by name) state info. 	 */
name|dns_adbfind_t
modifier|*
name|find
decl_stmt|;
name|dns_adbfind_t
modifier|*
name|v4find
decl_stmt|;
name|dns_adbfind_t
modifier|*
name|v6find
decl_stmt|;
name|unsigned
name|int
name|find_wanted
decl_stmt|;
comment|/* Addresses we want */
name|dns_fixedname_t
name|query_name
decl_stmt|;
name|dns_fixedname_t
name|target_name
decl_stmt|;
name|ns_lwsearchctx_t
name|searchctx
decl_stmt|;
name|lwres_gabnresponse_t
name|gabn
decl_stmt|;
comment|/* 	 * gnba (get name by address) state info. 	 */
name|lwres_gnbaresponse_t
name|gnba
decl_stmt|;
name|dns_byaddr_t
modifier|*
name|byaddr
decl_stmt|;
name|unsigned
name|int
name|options
decl_stmt|;
name|isc_netaddr_t
name|na
decl_stmt|;
comment|/* 	 * grbn (get rrset by name) state info. 	 * 	 * Note: this also uses target_name and searchctx. 	 */
name|lwres_grbnresponse_t
name|grbn
decl_stmt|;
name|dns_lookup_t
modifier|*
name|lookup
decl_stmt|;
name|dns_rdatatype_t
name|rdtype
decl_stmt|;
comment|/* 	 * Alias and address info.  This is copied up to the gabn/gnba 	 * structures eventually. 	 * 	 * XXXMLG We can keep all of this in a client since we only service 	 * three packet types right now.  If we started handling more, 	 * we'd need to use "arg" above and allocate/destroy things. 	 */
name|char
modifier|*
name|aliases
index|[
name|LWRES_MAX_ALIASES
index|]
decl_stmt|;
name|isc_uint16_t
name|aliaslen
index|[
name|LWRES_MAX_ALIASES
index|]
decl_stmt|;
name|lwres_addr_t
name|addrs
index|[
name|LWRES_MAX_ADDRS
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Client states.  *  * _IDLE	The client is not doing anything at all.  *  * _RECV	The client is waiting for data after issuing a socket recv().  *  * _RECVDONE	Data has been received, and is being processed.  *  * _FINDWAIT	An adb (or other) request was made that cannot be satisfied  *		immediately.  An event will wake the client up.  *  * _SEND	All data for a response has completed, and a reply was  *		sent via a socket send() call.  *  * Badly formatted state table:  *  *	IDLE -> RECV when client has a recv() queued.  *  *	RECV -> RECVDONE when recvdone event received.  *  *	RECVDONE -> SEND if the data for a reply is at hand.  *	RECVDONE -> FINDWAIT if more searching is needed, and events will  *		eventually wake us up again.  *  *	FINDWAIT -> SEND when enough data was received to reply.  *  *	SEND -> IDLE when a senddone event was received.  *  *	At any time -> IDLE on error.  Sometimes this will be -> SEND  *	instead, if enough data is on hand to reply with a meaningful  *	error.  *  *	Packets which are badly formatted may or may not get error returns.  */
end_comment

begin_define
define|#
directive|define
name|NS_LWDCLIENT_STATEIDLE
value|1
end_define

begin_define
define|#
directive|define
name|NS_LWDCLIENT_STATERECV
value|2
end_define

begin_define
define|#
directive|define
name|NS_LWDCLIENT_STATERECVDONE
value|3
end_define

begin_define
define|#
directive|define
name|NS_LWDCLIENT_STATEFINDWAIT
value|4
end_define

begin_define
define|#
directive|define
name|NS_LWDCLIENT_STATESEND
value|5
end_define

begin_define
define|#
directive|define
name|NS_LWDCLIENT_STATESENDDONE
value|6
end_define

begin_define
define|#
directive|define
name|NS_LWDCLIENT_ISIDLE
parameter_list|(
name|c
parameter_list|)
define|\
value|((c)->state == NS_LWDCLIENT_STATEIDLE)
end_define

begin_define
define|#
directive|define
name|NS_LWDCLIENT_ISRECV
parameter_list|(
name|c
parameter_list|)
define|\
value|((c)->state == NS_LWDCLIENT_STATERECV)
end_define

begin_define
define|#
directive|define
name|NS_LWDCLIENT_ISRECVDONE
parameter_list|(
name|c
parameter_list|)
define|\
value|((c)->state == NS_LWDCLIENT_STATERECVDONE)
end_define

begin_define
define|#
directive|define
name|NS_LWDCLIENT_ISFINDWAIT
parameter_list|(
name|c
parameter_list|)
define|\
value|((c)->state == NS_LWDCLIENT_STATEFINDWAIT)
end_define

begin_define
define|#
directive|define
name|NS_LWDCLIENT_ISSEND
parameter_list|(
name|c
parameter_list|)
define|\
value|((c)->state == NS_LWDCLIENT_STATESEND)
end_define

begin_comment
comment|/*  * Overall magic test that means we're not idle.  */
end_comment

begin_define
define|#
directive|define
name|NS_LWDCLIENT_ISRUNNING
parameter_list|(
name|c
parameter_list|)
value|(!NS_LWDCLIENT_ISIDLE(c))
end_define

begin_define
define|#
directive|define
name|NS_LWDCLIENT_SETIDLE
parameter_list|(
name|c
parameter_list|)
define|\
value|((c)->state = NS_LWDCLIENT_STATEIDLE)
end_define

begin_define
define|#
directive|define
name|NS_LWDCLIENT_SETRECV
parameter_list|(
name|c
parameter_list|)
define|\
value|((c)->state = NS_LWDCLIENT_STATERECV)
end_define

begin_define
define|#
directive|define
name|NS_LWDCLIENT_SETRECVDONE
parameter_list|(
name|c
parameter_list|)
define|\
value|((c)->state = NS_LWDCLIENT_STATERECVDONE)
end_define

begin_define
define|#
directive|define
name|NS_LWDCLIENT_SETFINDWAIT
parameter_list|(
name|c
parameter_list|)
define|\
value|((c)->state = NS_LWDCLIENT_STATEFINDWAIT)
end_define

begin_define
define|#
directive|define
name|NS_LWDCLIENT_SETSEND
parameter_list|(
name|c
parameter_list|)
define|\
value|((c)->state = NS_LWDCLIENT_STATESEND)
end_define

begin_define
define|#
directive|define
name|NS_LWDCLIENT_SETSENDDONE
parameter_list|(
name|c
parameter_list|)
define|\
value|((c)->state = NS_LWDCLIENT_STATESENDDONE)
end_define

begin_struct
struct|struct
name|ns_lwdclientmgr
block|{
name|ns_lwreslistener_t
modifier|*
name|listener
decl_stmt|;
name|isc_mem_t
modifier|*
name|mctx
decl_stmt|;
name|isc_socket_t
modifier|*
name|sock
decl_stmt|;
comment|/* socket to use */
name|dns_view_t
modifier|*
name|view
decl_stmt|;
name|lwres_context_t
modifier|*
name|lwctx
decl_stmt|;
comment|/* lightweight proto context */
name|isc_task_t
modifier|*
name|task
decl_stmt|;
comment|/* owning task */
name|unsigned
name|int
name|flags
decl_stmt|;
name|ISC_LINK
argument_list|(
argument|ns_lwdclientmgr_t
argument_list|)
name|link
expr_stmt|;
name|ISC_LIST
argument_list|(
argument|ns_lwdclient_t
argument_list|)
name|idle
expr_stmt|;
comment|/* idle client slots */
name|ISC_LIST
argument_list|(
argument|ns_lwdclient_t
argument_list|)
name|running
expr_stmt|;
comment|/* running clients */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NS_LWDCLIENTMGR_FLAGRECVPENDING
value|0x00000001
end_define

begin_define
define|#
directive|define
name|NS_LWDCLIENTMGR_FLAGSHUTTINGDOWN
value|0x00000002
end_define

begin_function_decl
name|isc_result_t
name|ns_lwdclientmgr_create
parameter_list|(
name|ns_lwreslistener_t
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|isc_taskmgr_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ns_lwdclient_initialize
parameter_list|(
name|ns_lwdclient_t
modifier|*
parameter_list|,
name|ns_lwdclientmgr_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|ns_lwdclient_startrecv
parameter_list|(
name|ns_lwdclientmgr_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ns_lwdclient_stateidle
parameter_list|(
name|ns_lwdclient_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ns_lwdclient_recv
parameter_list|(
name|isc_task_t
modifier|*
parameter_list|,
name|isc_event_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ns_lwdclient_shutdown
parameter_list|(
name|isc_task_t
modifier|*
parameter_list|,
name|isc_event_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ns_lwdclient_send
parameter_list|(
name|isc_task_t
modifier|*
parameter_list|,
name|isc_event_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|ns_lwdclient_sendreply
parameter_list|(
name|ns_lwdclient_t
modifier|*
name|client
parameter_list|,
name|isc_region_t
modifier|*
name|r
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Processing functions of various types.  */
end_comment

begin_function_decl
name|void
name|ns_lwdclient_processgabn
parameter_list|(
name|ns_lwdclient_t
modifier|*
parameter_list|,
name|lwres_buffer_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ns_lwdclient_processgnba
parameter_list|(
name|ns_lwdclient_t
modifier|*
parameter_list|,
name|lwres_buffer_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ns_lwdclient_processgrbn
parameter_list|(
name|ns_lwdclient_t
modifier|*
parameter_list|,
name|lwres_buffer_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ns_lwdclient_processnoop
parameter_list|(
name|ns_lwdclient_t
modifier|*
parameter_list|,
name|lwres_buffer_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ns_lwdclient_errorpktsend
parameter_list|(
name|ns_lwdclient_t
modifier|*
parameter_list|,
name|isc_uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ns_lwdclient_log
parameter_list|(
name|int
name|level
parameter_list|,
specifier|const
name|char
modifier|*
name|format
parameter_list|,
modifier|...
parameter_list|)
function_decl|ISC_FORMAT_PRINTF
parameter_list|(
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NAMED_LWDCLIENT_H */
end_comment

end_unit

