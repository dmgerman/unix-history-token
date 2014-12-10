begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004-2012  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1999-2001, 2003  Internet Software Consortium.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DNS_RESOLVER_H
end_ifndef

begin_define
define|#
directive|define
name|DNS_RESOLVER_H
value|1
end_define

begin_comment
comment|/*****  ***** Module Info  *****/
end_comment

begin_comment
comment|/*! \file dns/resolver.h  *  * \brief  * This is the BIND 9 resolver, the module responsible for resolving DNS  * requests by iteratively querying authoritative servers and following  * referrals.  This is a "full resolver", not to be confused with  * the stub resolvers most people associate with the word "resolver".  * The full resolver is part of the caching name server or resolver  * daemon the stub resolver talks to.  *  * MP:  *\li	The module ensures appropriate synchronization of data structures it  *	creates and manipulates.  *  * Reliability:  *\li	No anticipated impact.  *  * Resources:  *\li	TBS  *  * Security:  *\li	No anticipated impact.  *  * Standards:  *\li	RFCs:	1034, 1035, 2181, TBS  *\li	Drafts:	TBS  */
end_comment

begin_include
include|#
directive|include
file|<isc/lang.h>
end_include

begin_include
include|#
directive|include
file|<isc/socket.h>
end_include

begin_include
include|#
directive|include
file|<dns/types.h>
end_include

begin_include
include|#
directive|include
file|<dns/fixedname.h>
end_include

begin_macro
name|ISC_LANG_BEGINDECLS
end_macro

begin_comment
comment|/*%  * A dns_fetchevent_t is sent when a 'fetch' completes.  Any of 'db',  * 'node', 'rdataset', and 'sigrdataset' may be bound.  It is the  * receiver's responsibility to detach before freeing the event.  * \brief  * 'rdataset', 'sigrdataset', 'client' and 'id' are the values that were  * supplied when dns_resolver_createfetch() was called.  They are returned  *  to the caller so that they may be freed.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|dns_fetchevent
block|{
name|ISC_EVENT_COMMON
argument_list|(
expr|struct
name|dns_fetchevent
argument_list|)
expr_stmt|;
name|dns_fetch_t
modifier|*
name|fetch
decl_stmt|;
name|isc_result_t
name|result
decl_stmt|;
name|dns_rdatatype_t
name|qtype
decl_stmt|;
name|dns_db_t
modifier|*
name|db
decl_stmt|;
name|dns_dbnode_t
modifier|*
name|node
decl_stmt|;
name|dns_rdataset_t
modifier|*
name|rdataset
decl_stmt|;
name|dns_rdataset_t
modifier|*
name|sigrdataset
decl_stmt|;
name|dns_fixedname_t
name|foundname
decl_stmt|;
name|isc_sockaddr_t
modifier|*
name|client
decl_stmt|;
name|dns_messageid_t
name|id
decl_stmt|;
name|isc_result_t
name|vresult
decl_stmt|;
block|}
name|dns_fetchevent_t
typedef|;
end_typedef

begin_comment
comment|/*  * Options that modify how a 'fetch' is done.  */
end_comment

begin_define
define|#
directive|define
name|DNS_FETCHOPT_TCP
value|0x01
end_define

begin_comment
comment|/*%< Use TCP. */
end_comment

begin_define
define|#
directive|define
name|DNS_FETCHOPT_UNSHARED
value|0x02
end_define

begin_comment
comment|/*%< See below. */
end_comment

begin_define
define|#
directive|define
name|DNS_FETCHOPT_RECURSIVE
value|0x04
end_define

begin_comment
comment|/*%< Set RD? */
end_comment

begin_define
define|#
directive|define
name|DNS_FETCHOPT_NOEDNS0
value|0x08
end_define

begin_comment
comment|/*%< Do not use EDNS. */
end_comment

begin_define
define|#
directive|define
name|DNS_FETCHOPT_FORWARDONLY
value|0x10
end_define

begin_comment
comment|/*%< Only use forwarders. */
end_comment

begin_define
define|#
directive|define
name|DNS_FETCHOPT_NOVALIDATE
value|0x20
end_define

begin_comment
comment|/*%< Disable validation. */
end_comment

begin_define
define|#
directive|define
name|DNS_FETCHOPT_EDNS512
value|0x40
end_define

begin_comment
comment|/*%< Advertise a 512 byte 							  UDP buffer. */
end_comment

begin_define
define|#
directive|define
name|DNS_FETCHOPT_WANTNSID
value|0x80
end_define

begin_comment
comment|/*%< Request NSID */
end_comment

begin_define
define|#
directive|define
name|DNS_FETCHOPT_EDNSVERSIONSET
value|0x00800000
end_define

begin_define
define|#
directive|define
name|DNS_FETCHOPT_EDNSVERSIONMASK
value|0xff000000
end_define

begin_define
define|#
directive|define
name|DNS_FETCHOPT_EDNSVERSIONSHIFT
value|24
end_define

begin_comment
comment|/*  * Upper bounds of class of query RTT (ms).  Corresponds to  * dns_resstatscounter_queryrttX statistics counters.  */
end_comment

begin_define
define|#
directive|define
name|DNS_RESOLVER_QRYRTTCLASS0
value|10
end_define

begin_define
define|#
directive|define
name|DNS_RESOLVER_QRYRTTCLASS0STR
value|"10"
end_define

begin_define
define|#
directive|define
name|DNS_RESOLVER_QRYRTTCLASS1
value|100
end_define

begin_define
define|#
directive|define
name|DNS_RESOLVER_QRYRTTCLASS1STR
value|"100"
end_define

begin_define
define|#
directive|define
name|DNS_RESOLVER_QRYRTTCLASS2
value|500
end_define

begin_define
define|#
directive|define
name|DNS_RESOLVER_QRYRTTCLASS2STR
value|"500"
end_define

begin_define
define|#
directive|define
name|DNS_RESOLVER_QRYRTTCLASS3
value|800
end_define

begin_define
define|#
directive|define
name|DNS_RESOLVER_QRYRTTCLASS3STR
value|"800"
end_define

begin_define
define|#
directive|define
name|DNS_RESOLVER_QRYRTTCLASS4
value|1600
end_define

begin_define
define|#
directive|define
name|DNS_RESOLVER_QRYRTTCLASS4STR
value|"1600"
end_define

begin_comment
comment|/*  * XXXRTH  Should this API be made semi-private?  (I.e.  * _dns_resolver_create()).  */
end_comment

begin_define
define|#
directive|define
name|DNS_RESOLVER_CHECKNAMES
value|0x01
end_define

begin_define
define|#
directive|define
name|DNS_RESOLVER_CHECKNAMESFAIL
value|0x02
end_define

begin_function_decl
name|isc_result_t
name|dns_resolver_create
parameter_list|(
name|dns_view_t
modifier|*
name|view
parameter_list|,
name|isc_taskmgr_t
modifier|*
name|taskmgr
parameter_list|,
name|unsigned
name|int
name|ntasks
parameter_list|,
name|isc_socketmgr_t
modifier|*
name|socketmgr
parameter_list|,
name|isc_timermgr_t
modifier|*
name|timermgr
parameter_list|,
name|unsigned
name|int
name|options
parameter_list|,
name|dns_dispatchmgr_t
modifier|*
name|dispatchmgr
parameter_list|,
name|dns_dispatch_t
modifier|*
name|dispatchv4
parameter_list|,
name|dns_dispatch_t
modifier|*
name|dispatchv6
parameter_list|,
name|dns_resolver_t
modifier|*
modifier|*
name|resp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Create a resolver.  *  * Notes:  *  *\li	Generally, applications should not create a resolver directly, but  *	should instead call dns_view_createresolver().  *  * Requires:  *  *\li	'view' is a valid view.  *  *\li	'taskmgr' is a valid task manager.  *  *\li	'ntasks'> 0.  *  *\li	'socketmgr' is a valid socket manager.  *  *\li	'timermgr' is a valid timer manager.  *  *\li	'dispatchv4' is a valid dispatcher with an IPv4 UDP socket, or is NULL.  *  *\li	'dispatchv6' is a valid dispatcher with an IPv6 UDP socket, or is NULL.  *  *\li	resp != NULL&& *resp == NULL.  *  * Returns:  *  *\li	#ISC_R_SUCCESS				On success.  *  *\li	Anything else				Failure.  */
end_comment

begin_function_decl
name|void
name|dns_resolver_freeze
parameter_list|(
name|dns_resolver_t
modifier|*
name|res
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Freeze resolver.  *  * Notes:  *  *\li	Certain configuration changes cannot be made after the resolver  *	is frozen.  Fetches cannot be created until the resolver is frozen.  *  * Requires:  *  *\li	'res' is a valid resolver.  *  * Ensures:  *  *\li	'res' is frozen.  */
end_comment

begin_function_decl
name|void
name|dns_resolver_prime
parameter_list|(
name|dns_resolver_t
modifier|*
name|res
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Prime resolver.  *  * Notes:  *  *\li	Resolvers which have a forwarding policy other than dns_fwdpolicy_only  *	need to be primed with the root nameservers, otherwise the root  *	nameserver hints data may be used indefinitely.  This function requests  *	that the resolver start a priming fetch, if it isn't already priming.  *  * Requires:  *  *\li	'res' is a valid, frozen resolver.  */
end_comment

begin_function_decl
name|void
name|dns_resolver_whenshutdown
parameter_list|(
name|dns_resolver_t
modifier|*
name|res
parameter_list|,
name|isc_task_t
modifier|*
name|task
parameter_list|,
name|isc_event_t
modifier|*
modifier|*
name|eventp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Send '*eventp' to 'task' when 'res' has completed shutdown.  *  * Notes:  *  *\li	It is not safe to detach the last reference to 'res' until  *	shutdown is complete.  *  * Requires:  *  *\li	'res' is a valid resolver.  *  *\li	'task' is a valid task.  *  *\li	*eventp is a valid event.  *  * Ensures:  *  *\li	*eventp == NULL.  */
end_comment

begin_function_decl
name|void
name|dns_resolver_shutdown
parameter_list|(
name|dns_resolver_t
modifier|*
name|res
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Start the shutdown process for 'res'.  *  * Notes:  *  *\li	This call has no effect if the resolver is already shutting down.  *  * Requires:  *  *\li	'res' is a valid resolver.  */
end_comment

begin_function_decl
name|void
name|dns_resolver_attach
parameter_list|(
name|dns_resolver_t
modifier|*
name|source
parameter_list|,
name|dns_resolver_t
modifier|*
modifier|*
name|targetp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dns_resolver_detach
parameter_list|(
name|dns_resolver_t
modifier|*
modifier|*
name|resp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|dns_resolver_createfetch
parameter_list|(
name|dns_resolver_t
modifier|*
name|res
parameter_list|,
name|dns_name_t
modifier|*
name|name
parameter_list|,
name|dns_rdatatype_t
name|type
parameter_list|,
name|dns_name_t
modifier|*
name|domain
parameter_list|,
name|dns_rdataset_t
modifier|*
name|nameservers
parameter_list|,
name|dns_forwarders_t
modifier|*
name|forwarders
parameter_list|,
name|unsigned
name|int
name|options
parameter_list|,
name|isc_task_t
modifier|*
name|task
parameter_list|,
name|isc_taskaction_t
name|action
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|,
name|dns_rdataset_t
modifier|*
name|rdataset
parameter_list|,
name|dns_rdataset_t
modifier|*
name|sigrdataset
parameter_list|,
name|dns_fetch_t
modifier|*
modifier|*
name|fetchp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|dns_resolver_createfetch2
parameter_list|(
name|dns_resolver_t
modifier|*
name|res
parameter_list|,
name|dns_name_t
modifier|*
name|name
parameter_list|,
name|dns_rdatatype_t
name|type
parameter_list|,
name|dns_name_t
modifier|*
name|domain
parameter_list|,
name|dns_rdataset_t
modifier|*
name|nameservers
parameter_list|,
name|dns_forwarders_t
modifier|*
name|forwarders
parameter_list|,
name|isc_sockaddr_t
modifier|*
name|client
parameter_list|,
name|isc_uint16_t
name|id
parameter_list|,
name|unsigned
name|int
name|options
parameter_list|,
name|isc_task_t
modifier|*
name|task
parameter_list|,
name|isc_taskaction_t
name|action
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|,
name|dns_rdataset_t
modifier|*
name|rdataset
parameter_list|,
name|dns_rdataset_t
modifier|*
name|sigrdataset
parameter_list|,
name|dns_fetch_t
modifier|*
modifier|*
name|fetchp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|dns_resolver_createfetch3
parameter_list|(
name|dns_resolver_t
modifier|*
name|res
parameter_list|,
name|dns_name_t
modifier|*
name|name
parameter_list|,
name|dns_rdatatype_t
name|type
parameter_list|,
name|dns_name_t
modifier|*
name|domain
parameter_list|,
name|dns_rdataset_t
modifier|*
name|nameservers
parameter_list|,
name|dns_forwarders_t
modifier|*
name|forwarders
parameter_list|,
name|isc_sockaddr_t
modifier|*
name|client
parameter_list|,
name|isc_uint16_t
name|id
parameter_list|,
name|unsigned
name|int
name|options
parameter_list|,
name|unsigned
name|int
name|depth
parameter_list|,
name|isc_counter_t
modifier|*
name|qc
parameter_list|,
name|isc_task_t
modifier|*
name|task
parameter_list|,
name|isc_taskaction_t
name|action
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|,
name|dns_rdataset_t
modifier|*
name|rdataset
parameter_list|,
name|dns_rdataset_t
modifier|*
name|sigrdataset
parameter_list|,
name|dns_fetch_t
modifier|*
modifier|*
name|fetchp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Recurse to answer a question.  *  * Notes:  *  *\li	This call starts a query for 'name', type 'type'.  *  *\li	The 'domain' is a parent domain of 'name' for which  *	a set of name servers 'nameservers' is known.  If no  *	such name server information is available, set  * 	'domain' and 'nameservers' to NULL.  *  *\li	'forwarders' is unimplemented, and subject to change when  *	we figure out how selective forwarding will work.  *  *\li	When the fetch completes (successfully or otherwise), a  *	#DNS_EVENT_FETCHDONE event with action 'action' and arg 'arg' will be  *	posted to 'task'.  *  *\li	The values of 'rdataset' and 'sigrdataset' will be returned in  *	the FETCHDONE event.  *  *\li	'client' and 'id' are used for duplicate query detection.  '*client'  *	must remain stable until after 'action' has been called or  *	dns_resolver_cancelfetch() is called.  *  * Requires:  *  *\li	'res' is a valid resolver that has been frozen.  *  *\li	'name' is a valid name.  *  *\li	'type' is not a meta type other than ANY.  *  *\li	'domain' is a valid name or NULL.  *  *\li	'nameservers' is a valid NS rdataset (whose owner name is 'domain')  *	iff. 'domain' is not NULL.  *  *\li	'forwarders' is NULL.  *  *\li	'client' is a valid sockaddr or NULL.  *  *\li	'options' contains valid options.  *  *\li	'rdataset' is a valid, disassociated rdataset.  *  *\li	'sigrdataset' is NULL, or is a valid, disassociated rdataset.  *  *\li	fetchp != NULL&& *fetchp == NULL.  *  * Returns:  *  *\li	#ISC_R_SUCCESS					Success  *\li	#DNS_R_DUPLICATE  *\li	#DNS_R_DROP  *  *\li	Many other values are possible, all of which indicate failure.  */
end_comment

begin_function_decl
name|void
name|dns_resolver_cancelfetch
parameter_list|(
name|dns_fetch_t
modifier|*
name|fetch
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Cancel 'fetch'.  *  * Notes:  *  *\li	If 'fetch' has not completed, post its FETCHDONE event with a  *	result code of #ISC_R_CANCELED.  *  * Requires:  *  *\li	'fetch' is a valid fetch.  */
end_comment

begin_function_decl
name|void
name|dns_resolver_destroyfetch
parameter_list|(
name|dns_fetch_t
modifier|*
modifier|*
name|fetchp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Destroy 'fetch'.  *  * Requires:  *  *\li	'*fetchp' is a valid fetch.  *  *\li	The caller has received the FETCHDONE event (either because the  *	fetch completed or because dns_resolver_cancelfetch() was called).  *  * Ensures:  *  *\li	*fetchp == NULL.  */
end_comment

begin_function_decl
name|void
name|dns_resolver_logfetch
parameter_list|(
name|dns_fetch_t
modifier|*
name|fetch
parameter_list|,
name|isc_log_t
modifier|*
name|lctx
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
name|isc_boolean_t
name|duplicateok
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Dump a log message on internal state at the completion of given 'fetch'.  * 'lctx', 'category', 'module', and 'level' are used to write the log message.  * By default, only one log message is written even if the corresponding fetch  * context serves multiple clients; if 'duplicateok' is true the suppression  * is disabled and the message can be written every time this function is  * called.  *  * Requires:  *  *\li	'fetch' is a valid fetch, and has completed.  */
end_comment

begin_function_decl
name|dns_dispatchmgr_t
modifier|*
name|dns_resolver_dispatchmgr
parameter_list|(
name|dns_resolver_t
modifier|*
name|resolver
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|dns_dispatch_t
modifier|*
name|dns_resolver_dispatchv4
parameter_list|(
name|dns_resolver_t
modifier|*
name|resolver
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|dns_dispatch_t
modifier|*
name|dns_resolver_dispatchv6
parameter_list|(
name|dns_resolver_t
modifier|*
name|resolver
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_socketmgr_t
modifier|*
name|dns_resolver_socketmgr
parameter_list|(
name|dns_resolver_t
modifier|*
name|resolver
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_taskmgr_t
modifier|*
name|dns_resolver_taskmgr
parameter_list|(
name|dns_resolver_t
modifier|*
name|resolver
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_uint32_t
name|dns_resolver_getlamettl
parameter_list|(
name|dns_resolver_t
modifier|*
name|resolver
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Get the resolver's lame-ttl.  zero => no lame processing.  *  * Requires:  *\li	'resolver' to be valid.  */
end_comment

begin_function_decl
name|void
name|dns_resolver_setlamettl
parameter_list|(
name|dns_resolver_t
modifier|*
name|resolver
parameter_list|,
name|isc_uint32_t
name|lame_ttl
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Set the resolver's lame-ttl.  zero => no lame processing.  *  * Requires:  *\li	'resolver' to be valid.  */
end_comment

begin_function_decl
name|unsigned
name|int
name|dns_resolver_nrunning
parameter_list|(
name|dns_resolver_t
modifier|*
name|resolver
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Return the number of currently running resolutions in this  * resolver.  This is may be less than the number of outstanding  * fetches due to multiple identical fetches, or more than the  * number of of outstanding fetches due to the fact that resolution  * can continue even though a fetch has been canceled.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_resolver_addalternate
parameter_list|(
name|dns_resolver_t
modifier|*
name|resolver
parameter_list|,
name|isc_sockaddr_t
modifier|*
name|alt
parameter_list|,
name|dns_name_t
modifier|*
name|name
parameter_list|,
name|in_port_t
name|port
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Add alternate addresses to be tried in the event that the nameservers  * for a zone are not available in the address families supported by the  * operating system.  *  * Require:  * \li	only one of 'name' or 'alt' to be valid.  */
end_comment

begin_function_decl
name|void
name|dns_resolver_setudpsize
parameter_list|(
name|dns_resolver_t
modifier|*
name|resolver
parameter_list|,
name|isc_uint16_t
name|udpsize
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Set the EDNS UDP buffer size advertised by the server.  */
end_comment

begin_function_decl
name|isc_uint16_t
name|dns_resolver_getudpsize
parameter_list|(
name|dns_resolver_t
modifier|*
name|resolver
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Get the current EDNS UDP buffer size.  */
end_comment

begin_function_decl
name|void
name|dns_resolver_reset_algorithms
parameter_list|(
name|dns_resolver_t
modifier|*
name|resolver
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Clear the disabled DNSSEC algorithms.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_resolver_disable_algorithm
parameter_list|(
name|dns_resolver_t
modifier|*
name|resolver
parameter_list|,
name|dns_name_t
modifier|*
name|name
parameter_list|,
name|unsigned
name|int
name|alg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Mark the give DNSSEC algorithm as disabled and below 'name'.  * Valid algorithms are less than 256.  *  * Returns:  *\li	#ISC_R_SUCCESS  *\li	#ISC_R_RANGE  *\li	#ISC_R_NOMEMORY  */
end_comment

begin_function_decl
name|isc_boolean_t
name|dns_resolver_algorithm_supported
parameter_list|(
name|dns_resolver_t
modifier|*
name|resolver
parameter_list|,
name|dns_name_t
modifier|*
name|name
parameter_list|,
name|unsigned
name|int
name|alg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Check if the given algorithm is supported by this resolver.  * This checks if the algorithm has been disabled via  * dns_resolver_disable_algorithm() then the underlying  * crypto libraries if not specifically disabled.  */
end_comment

begin_function_decl
name|isc_boolean_t
name|dns_resolver_digest_supported
parameter_list|(
name|dns_resolver_t
modifier|*
name|resolver
parameter_list|,
name|unsigned
name|int
name|digest_type
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Is this digest type supported.  */
end_comment

begin_function_decl
name|void
name|dns_resolver_resetmustbesecure
parameter_list|(
name|dns_resolver_t
modifier|*
name|resolver
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|dns_resolver_setmustbesecure
parameter_list|(
name|dns_resolver_t
modifier|*
name|resolver
parameter_list|,
name|dns_name_t
modifier|*
name|name
parameter_list|,
name|isc_boolean_t
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_boolean_t
name|dns_resolver_getmustbesecure
parameter_list|(
name|dns_resolver_t
modifier|*
name|resolver
parameter_list|,
name|dns_name_t
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dns_resolver_settimeout
parameter_list|(
name|dns_resolver_t
modifier|*
name|resolver
parameter_list|,
name|unsigned
name|int
name|seconds
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Set the length of time the resolver will work on a query, in seconds.  *  * If timeout is 0, the default timeout will be applied.  *  * Requires:  * \li  resolver to be valid.  */
end_comment

begin_function_decl
name|unsigned
name|int
name|dns_resolver_gettimeout
parameter_list|(
name|dns_resolver_t
modifier|*
name|resolver
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Get the current length of time the resolver will work on a query, in seconds.  *  * Requires:  * \li  resolver to be valid.  */
end_comment

begin_function_decl
name|void
name|dns_resolver_setclientsperquery
parameter_list|(
name|dns_resolver_t
modifier|*
name|resolver
parameter_list|,
name|isc_uint32_t
name|min
parameter_list|,
name|isc_uint32_t
name|max
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dns_resolver_getclientsperquery
parameter_list|(
name|dns_resolver_t
modifier|*
name|resolver
parameter_list|,
name|isc_uint32_t
modifier|*
name|cur
parameter_list|,
name|isc_uint32_t
modifier|*
name|min
parameter_list|,
name|isc_uint32_t
modifier|*
name|max
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_boolean_t
name|dns_resolver_getzeronosoattl
parameter_list|(
name|dns_resolver_t
modifier|*
name|resolver
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dns_resolver_setzeronosoattl
parameter_list|(
name|dns_resolver_t
modifier|*
name|resolver
parameter_list|,
name|isc_boolean_t
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|int
name|dns_resolver_getoptions
parameter_list|(
name|dns_resolver_t
modifier|*
name|resolver
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dns_resolver_addbadcache
parameter_list|(
name|dns_resolver_t
modifier|*
name|resolver
parameter_list|,
name|dns_name_t
modifier|*
name|name
parameter_list|,
name|dns_rdatatype_t
name|type
parameter_list|,
name|isc_time_t
modifier|*
name|expire
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Add a entry to the bad cache for<name,type> that will expire at 'expire'.  *  * Requires:  * \li	resolver to be valid.  * \li	name to be valid.  */
end_comment

begin_function_decl
name|isc_boolean_t
name|dns_resolver_getbadcache
parameter_list|(
name|dns_resolver_t
modifier|*
name|resolver
parameter_list|,
name|dns_name_t
modifier|*
name|name
parameter_list|,
name|dns_rdatatype_t
name|type
parameter_list|,
name|isc_time_t
modifier|*
name|now
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Check to see if there is a unexpired entry in the bad cache for  *<name,type>.  *  * Requires:  * \li	resolver to be valid.  * \li	name to be valid.  */
end_comment

begin_function_decl
name|void
name|dns_resolver_flushbadcache
parameter_list|(
name|dns_resolver_t
modifier|*
name|resolver
parameter_list|,
name|dns_name_t
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Flush the bad cache of all entries at 'name' if 'name' is non NULL.  * Flush the entire bad cache if 'name' is NULL.  *  * Requires:  * \li	resolver to be valid.  */
end_comment

begin_function_decl
name|void
name|dns_resolver_printbadcache
parameter_list|(
name|dns_resolver_t
modifier|*
name|resolver
parameter_list|,
name|FILE
modifier|*
name|fp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%  * Print out the contents of the bad cache to 'fp'.  *  * Requires:  * \li	resolver to be valid.  */
end_comment

begin_function_decl
name|void
name|dns_resolver_setmaxdepth
parameter_list|(
name|dns_resolver_t
modifier|*
name|resolver
parameter_list|,
name|unsigned
name|int
name|maxdepth
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|int
name|dns_resolver_getmaxdepth
parameter_list|(
name|dns_resolver_t
modifier|*
name|resolver
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%  * Get and set how many NS indirections will be followed when looking for  * nameserver addresses.  *  * Requires:  * \li	resolver to be valid.  */
end_comment

begin_function_decl
name|void
name|dns_resolver_setmaxqueries
parameter_list|(
name|dns_resolver_t
modifier|*
name|resolver
parameter_list|,
name|unsigned
name|int
name|queries
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|int
name|dns_resolver_getmaxqueries
parameter_list|(
name|dns_resolver_t
modifier|*
name|resolver
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%  * Get and set how many iterative queries will be allowed before  * terminating a recursive query.  *  * Requires:  * \li	resolver to be valid.  */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DNS_RESOLVER_H */
end_comment

end_unit

