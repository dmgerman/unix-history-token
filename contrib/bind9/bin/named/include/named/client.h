begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004-2006  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1999-2003  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: client.h,v 1.60.2.2.10.12 2006/06/06 00:11:40 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NAMED_CLIENT_H
end_ifndef

begin_define
define|#
directive|define
name|NAMED_CLIENT_H
value|1
end_define

begin_comment
comment|/*****  ***** Module Info  *****/
end_comment

begin_comment
comment|/*  * Client  *  * This module defines two objects, ns_client_t and ns_clientmgr_t.  *  * An ns_client_t object handles incoming DNS requests from clients  * on a given network interface.  *  * Each ns_client_t object can handle only one TCP connection or UDP  * request at a time.  Therefore, several ns_client_t objects are  * typically created to serve each network interface, e.g., one  * for handling TCP requests and a few (one per CPU) for handling  * UDP requests.  *  * Incoming requests are classified as queries, zone transfer  * requests, update requests, notify requests, etc, and handed off  * to the appropriate request handler.  When the request has been  * fully handled (which can be much later), the ns_client_t must be  * notified of this by calling one of the following functions  * exactly once in the context of its task:  *  *   ns_client_send()	(sending a non-error response)  *   ns_client_sendraw() (sending a raw response)  *   ns_client_error()	(sending an error response)  *   ns_client_next()	(sending no response)  *  * This will release any resources used by the request and  * and allow the ns_client_t to listen for the next request.  *  * A ns_clientmgr_t manages a number of ns_client_t objects.  * New ns_client_t objects are created by calling  * ns_clientmgr_createclients(). They are destroyed by  * destroying their manager.  */
end_comment

begin_comment
comment|/***  *** Imports  ***/
end_comment

begin_include
include|#
directive|include
file|<isc/buffer.h>
end_include

begin_include
include|#
directive|include
file|<isc/magic.h>
end_include

begin_include
include|#
directive|include
file|<isc/stdtime.h>
end_include

begin_include
include|#
directive|include
file|<isc/quota.h>
end_include

begin_include
include|#
directive|include
file|<dns/fixedname.h>
end_include

begin_include
include|#
directive|include
file|<dns/name.h>
end_include

begin_include
include|#
directive|include
file|<dns/rdataclass.h>
end_include

begin_include
include|#
directive|include
file|<dns/rdatatype.h>
end_include

begin_include
include|#
directive|include
file|<dns/tcpmsg.h>
end_include

begin_include
include|#
directive|include
file|<dns/types.h>
end_include

begin_include
include|#
directive|include
file|<named/types.h>
end_include

begin_include
include|#
directive|include
file|<named/query.h>
end_include

begin_comment
comment|/***  *** Types  ***/
end_comment

begin_typedef
typedef|typedef
name|ISC_LIST
argument_list|(
argument|ns_client_t
argument_list|)
name|client_list_t
expr_stmt|;
end_typedef

begin_struct
struct|struct
name|ns_client
block|{
name|unsigned
name|int
name|magic
decl_stmt|;
name|isc_mem_t
modifier|*
name|mctx
decl_stmt|;
name|ns_clientmgr_t
modifier|*
name|manager
decl_stmt|;
name|int
name|state
decl_stmt|;
name|int
name|newstate
decl_stmt|;
name|int
name|naccepts
decl_stmt|;
name|int
name|nreads
decl_stmt|;
name|int
name|nsends
decl_stmt|;
name|int
name|nrecvs
decl_stmt|;
name|int
name|nupdates
decl_stmt|;
name|int
name|nctls
decl_stmt|;
name|int
name|references
decl_stmt|;
name|unsigned
name|int
name|attributes
decl_stmt|;
name|isc_task_t
modifier|*
name|task
decl_stmt|;
name|dns_view_t
modifier|*
name|view
decl_stmt|;
name|dns_dispatch_t
modifier|*
name|dispatch
decl_stmt|;
name|isc_socket_t
modifier|*
name|udpsocket
decl_stmt|;
name|isc_socket_t
modifier|*
name|tcplistener
decl_stmt|;
name|isc_socket_t
modifier|*
name|tcpsocket
decl_stmt|;
name|unsigned
name|char
modifier|*
name|tcpbuf
decl_stmt|;
name|dns_tcpmsg_t
name|tcpmsg
decl_stmt|;
name|isc_boolean_t
name|tcpmsg_valid
decl_stmt|;
name|isc_timer_t
modifier|*
name|timer
decl_stmt|;
name|isc_boolean_t
name|timerset
decl_stmt|;
name|dns_message_t
modifier|*
name|message
decl_stmt|;
name|isc_socketevent_t
modifier|*
name|sendevent
decl_stmt|;
name|isc_socketevent_t
modifier|*
name|recvevent
decl_stmt|;
name|unsigned
name|char
modifier|*
name|recvbuf
decl_stmt|;
name|dns_rdataset_t
modifier|*
name|opt
decl_stmt|;
name|isc_uint16_t
name|udpsize
decl_stmt|;
name|isc_uint16_t
name|extflags
decl_stmt|;
name|void
function_decl|(
modifier|*
name|next
function_decl|)
parameter_list|(
name|ns_client_t
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|shutdown
function_decl|)
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|,
name|isc_result_t
name|result
parameter_list|)
function_decl|;
name|void
modifier|*
name|shutdown_arg
decl_stmt|;
name|ns_query_t
name|query
decl_stmt|;
name|isc_stdtime_t
name|requesttime
decl_stmt|;
name|isc_stdtime_t
name|now
decl_stmt|;
name|dns_name_t
name|signername
decl_stmt|;
comment|/* [T]SIG key name */
name|dns_name_t
modifier|*
name|signer
decl_stmt|;
comment|/* NULL if not valid sig */
name|isc_boolean_t
name|mortal
decl_stmt|;
comment|/* Die after handling request */
name|isc_quota_t
modifier|*
name|tcpquota
decl_stmt|;
name|isc_quota_t
modifier|*
name|recursionquota
decl_stmt|;
name|ns_interface_t
modifier|*
name|interface
decl_stmt|;
name|isc_sockaddr_t
name|peeraddr
decl_stmt|;
name|isc_boolean_t
name|peeraddr_valid
decl_stmt|;
name|struct
name|in6_pktinfo
name|pktinfo
decl_stmt|;
name|isc_event_t
name|ctlevent
decl_stmt|;
comment|/* 	 * Information about recent FORMERR response(s), for 	 * FORMERR loop avoidance.  This is separate for each 	 * client object rather than global only to avoid 	 * the need for locking. 	 */
struct|struct
block|{
name|isc_sockaddr_t
name|addr
decl_stmt|;
name|isc_stdtime_t
name|time
decl_stmt|;
name|dns_messageid_t
name|id
decl_stmt|;
block|}
name|formerrcache
struct|;
name|ISC_LINK
argument_list|(
argument|ns_client_t
argument_list|)
name|link
expr_stmt|;
comment|/* 	 * The list 'link' is part of, or NULL if not on any list. 	 */
name|client_list_t
modifier|*
name|list
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NS_CLIENT_MAGIC
value|ISC_MAGIC('N','S','C','c')
end_define

begin_define
define|#
directive|define
name|NS_CLIENT_VALID
parameter_list|(
name|c
parameter_list|)
value|ISC_MAGIC_VALID(c, NS_CLIENT_MAGIC)
end_define

begin_define
define|#
directive|define
name|NS_CLIENTATTR_TCP
value|0x01
end_define

begin_define
define|#
directive|define
name|NS_CLIENTATTR_RA
value|0x02
end_define

begin_comment
comment|/* Client gets recusive service */
end_comment

begin_define
define|#
directive|define
name|NS_CLIENTATTR_PKTINFO
value|0x04
end_define

begin_comment
comment|/* pktinfo is valid */
end_comment

begin_define
define|#
directive|define
name|NS_CLIENTATTR_MULTICAST
value|0x08
end_define

begin_comment
comment|/* recv'd from multicast */
end_comment

begin_define
define|#
directive|define
name|NS_CLIENTATTR_WANTDNSSEC
value|0x10
end_define

begin_comment
comment|/* include dnssec records */
end_comment

begin_comment
comment|/***  *** Functions  ***/
end_comment

begin_comment
comment|/*  * Note!  These ns_client_ routines MUST be called ONLY from the client's  * task in order to ensure synchronization.  */
end_comment

begin_function_decl
name|void
name|ns_client_send
parameter_list|(
name|ns_client_t
modifier|*
name|client
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Finish processing the current client request and  * send client->message as a response.  */
end_comment

begin_function_decl
name|void
name|ns_client_sendraw
parameter_list|(
name|ns_client_t
modifier|*
name|client
parameter_list|,
name|dns_message_t
modifier|*
name|msg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Finish processing the current client request and  * send msg as a response using client->message->id for the id.  */
end_comment

begin_function_decl
name|void
name|ns_client_error
parameter_list|(
name|ns_client_t
modifier|*
name|client
parameter_list|,
name|isc_result_t
name|result
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Finish processing the current client request and return  * an error response to the client.  The error response  * will have an RCODE determined by 'result'.  */
end_comment

begin_function_decl
name|void
name|ns_client_next
parameter_list|(
name|ns_client_t
modifier|*
name|client
parameter_list|,
name|isc_result_t
name|result
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Finish processing the current client request,  * return no response to the client.  */
end_comment

begin_function_decl
name|void
name|ns_client_qnamereplace
parameter_list|(
name|ns_client_t
modifier|*
name|client
parameter_list|,
name|dns_name_t
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%  * Replace the qname.  */
end_comment

begin_function_decl
name|isc_boolean_t
name|ns_client_shuttingdown
parameter_list|(
name|ns_client_t
modifier|*
name|client
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Return ISC_TRUE iff the client is currently shutting down.  */
end_comment

begin_function_decl
name|void
name|ns_client_attach
parameter_list|(
name|ns_client_t
modifier|*
name|source
parameter_list|,
name|ns_client_t
modifier|*
modifier|*
name|target
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Attach '*targetp' to 'source'.  */
end_comment

begin_function_decl
name|void
name|ns_client_detach
parameter_list|(
name|ns_client_t
modifier|*
modifier|*
name|clientp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Detach '*clientp' from its client.  */
end_comment

begin_function_decl
name|isc_result_t
name|ns_client_replace
parameter_list|(
name|ns_client_t
modifier|*
name|client
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Try to replace the current client with a new one, so that the  * current one can go off and do some lengthy work without  * leaving the dispatch/socket without service.  */
end_comment

begin_function_decl
name|void
name|ns_client_settimeout
parameter_list|(
name|ns_client_t
modifier|*
name|client
parameter_list|,
name|unsigned
name|int
name|seconds
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Set a timer in the client to go off in the specified amount of time.  */
end_comment

begin_function_decl
name|isc_result_t
name|ns_clientmgr_create
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|isc_taskmgr_t
modifier|*
name|taskmgr
parameter_list|,
name|isc_timermgr_t
modifier|*
name|timermgr
parameter_list|,
name|ns_clientmgr_t
modifier|*
modifier|*
name|managerp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Create a client manager.  */
end_comment

begin_function_decl
name|void
name|ns_clientmgr_destroy
parameter_list|(
name|ns_clientmgr_t
modifier|*
modifier|*
name|managerp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Destroy a client manager and all ns_client_t objects  * managed by it.  */
end_comment

begin_function_decl
name|isc_result_t
name|ns_clientmgr_createclients
parameter_list|(
name|ns_clientmgr_t
modifier|*
name|manager
parameter_list|,
name|unsigned
name|int
name|n
parameter_list|,
name|ns_interface_t
modifier|*
name|ifp
parameter_list|,
name|isc_boolean_t
name|tcp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Create up to 'n' clients listening on interface 'ifp'.  * If 'tcp' is ISC_TRUE, the clients will listen for TCP connections,  * otherwise for UDP requests.  */
end_comment

begin_function_decl
name|isc_sockaddr_t
modifier|*
name|ns_client_getsockaddr
parameter_list|(
name|ns_client_t
modifier|*
name|client
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Get the socket address of the client whose request is  * currently being processed.  */
end_comment

begin_function_decl
name|isc_result_t
name|ns_client_checkaclsilent
parameter_list|(
name|ns_client_t
modifier|*
name|client
parameter_list|,
name|dns_acl_t
modifier|*
name|acl
parameter_list|,
name|isc_boolean_t
name|default_allow
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Convenience function for client request ACL checking.  *  * Check the current client request against 'acl'.  If 'acl'  * is NULL, allow the request iff 'default_allow' is ISC_TRUE.  *  * Notes:  *	This is appropriate for checking allow-update,  * 	allow-query, allow-transfer, etc.  It is not appropriate  * 	for checking the blackhole list because we treat positive  * 	matches as "allow" and negative matches as "deny"; in  *	the case of the blackhole list this would be backwards.  *  * Requires:  *	'client' points to a valid client.  *	'acl' points to a valid ACL, or is NULL.  *  * Returns:  *	ISC_R_SUCCESS	if the request should be allowed  * 	ISC_R_REFUSED	if the request should be denied  *	No other return values are possible.  */
end_comment

begin_function_decl
name|isc_result_t
name|ns_client_checkacl
parameter_list|(
name|ns_client_t
modifier|*
name|client
parameter_list|,
specifier|const
name|char
modifier|*
name|opname
parameter_list|,
name|dns_acl_t
modifier|*
name|acl
parameter_list|,
name|isc_boolean_t
name|default_allow
parameter_list|,
name|int
name|log_level
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Like ns_client_checkacl, but also logs the outcome of the  * check at log level 'log_level' if denied, and at debug 3  * if approved.  Log messages will refer to the request as  * an 'opname' request.  *  * Requires:  *	Those of ns_client_checkaclsilent(), and:  *  *	'opname' points to a null-terminated string.  */
end_comment

begin_function_decl
name|void
name|ns_client_log
parameter_list|(
name|ns_client_t
modifier|*
name|client
parameter_list|,
name|isc_logcategory_t
modifier|*
name|category
parameter_list|,
name|isc_logmodule_t
modifier|*
name|module
parameter_list|,
name|int
name|level
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|ISC_FORMAT_PRINTF
parameter_list|(
function_decl|5
operator|,
function_decl|6
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|ns_client_logv
parameter_list|(
name|ns_client_t
modifier|*
name|client
parameter_list|,
name|isc_logcategory_t
modifier|*
name|category
parameter_list|,
name|isc_logmodule_t
modifier|*
name|module
parameter_list|,
name|int
name|level
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
name|va_list
name|ap
parameter_list|)
function_decl|ISC_FORMAT_PRINTF
parameter_list|(
function_decl|5
operator|,
function_decl|0
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|ns_client_aclmsg
parameter_list|(
specifier|const
name|char
modifier|*
name|msg
parameter_list|,
name|dns_name_t
modifier|*
name|name
parameter_list|,
name|dns_rdatatype_t
name|type
parameter_list|,
name|dns_rdataclass_t
name|rdclass
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|NS_CLIENT_ACLMSGSIZE
parameter_list|(
name|x
parameter_list|)
define|\
value|(DNS_NAME_FORMATSIZE + DNS_RDATATYPE_FORMATSIZE + \ 	 DNS_RDATACLASS_FORMATSIZE + sizeof(x) + sizeof("'/'"))
end_define

begin_function_decl
name|void
name|ns_client_recursing
parameter_list|(
name|ns_client_t
modifier|*
name|client
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%  * Add client to end of recursing list.  If 'killoldest' is true  * kill the oldest recursive client (list head).   */
end_comment

begin_function_decl
name|void
name|ns_client_killoldestquery
parameter_list|(
name|ns_client_t
modifier|*
name|client
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%  * Kill the oldest recursive query (recursing list head).  */
end_comment

begin_function_decl
name|void
name|ns_client_dumprecursing
parameter_list|(
name|FILE
modifier|*
name|f
parameter_list|,
name|ns_clientmgr_t
modifier|*
name|manager
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Dump the outstanding recursive queries to 'f'.  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NAMED_CLIENT_H */
end_comment

end_unit

