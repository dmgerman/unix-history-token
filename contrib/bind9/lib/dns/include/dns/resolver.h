begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004, 2006  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1999-2001, 2003  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: resolver.h,v 1.34.12.9 2006/02/01 23:48:51 marka Exp $ */
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
comment|/*  * DNS Resolver  *  * This is the BIND 9 resolver, the module responsible for resolving DNS  * requests by iteratively querying authoritative servers and following  * referrals.  This is a "full resolver", not to be confused with  * the stub resolvers most people associate with the word "resolver".  * The full resolver is part of the caching name server or resolver  * daemon the stub resolver talks to.  *  * MP:  *	The module ensures appropriate synchronization of data structures it  *	creates and manipulates.  *  * Reliability:  *	No anticipated impact.  *  * Resources:  *<TBS>  *  * Security:  *	No anticipated impact.  *  * Standards:  *	RFCs:	1034, 1035, 2181,<TBS>  *	Drafts:<TBS>  */
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
comment|/*  * A dns_fetchevent_t is sent when a 'fetch' completes.  Any of 'db',  * 'node', 'rdataset', and 'sigrdataset' may be bound.  It is the  * receiver's responsibility to detach before freeing the event.  *  * 'rdataset' and 'sigrdataset' are the values that were supplied when  * dns_resolver_createfetch() was called.  They are returned to the  * caller so that they may be freed.  */
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
comment|/* Use TCP. */
end_comment

begin_define
define|#
directive|define
name|DNS_FETCHOPT_UNSHARED
value|0x02
end_define

begin_comment
comment|/* See below. */
end_comment

begin_define
define|#
directive|define
name|DNS_FETCHOPT_RECURSIVE
value|0x04
end_define

begin_comment
comment|/* Set RD? */
end_comment

begin_define
define|#
directive|define
name|DNS_FETCHOPT_NOEDNS0
value|0x08
end_define

begin_comment
comment|/* Do not use EDNS. */
end_comment

begin_define
define|#
directive|define
name|DNS_FETCHOPT_FORWARDONLY
value|0x10
end_define

begin_comment
comment|/* Only use forwarders. */
end_comment

begin_define
define|#
directive|define
name|DNS_FETCHOPT_NOVALIDATE
value|0x20
end_define

begin_comment
comment|/* Disable validation. */
end_comment

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
comment|/*  * Create a resolver.  *  * Notes:  *  *	Generally, applications should not create a resolver directly, but  *	should instead call dns_view_createresolver().  *  *	No options are currently defined.  *  * Requires:  *  *	'view' is a valid view.  *  *	'taskmgr' is a valid task manager.  *  *	'ntasks'> 0.  *  *	'socketmgr' is a valid socket manager.  *  *	'timermgr' is a valid timer manager.  *  *	'dispatchv4' is a valid dispatcher with an IPv4 UDP socket, or is NULL.  *  *	'dispatchv6' is a valid dispatcher with an IPv6 UDP socket, or is NULL.  *  *	resp != NULL&& *resp == NULL.  *  * Returns:  *  *	ISC_R_SUCCESS				On success.  *  *	Anything else				Failure.  */
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
comment|/*  * Freeze resolver.  *  * Notes:  *  *	Certain configuration changes cannot be made after the resolver  *	is frozen.  Fetches cannot be created until the resolver is frozen.  *  * Requires:  *  *	'res' is a valid, unfrozen resolver.  *  * Ensures:  *  *	'res' is frozen.  */
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
comment|/*  * Prime resolver.  *  * Notes:  *  *	Resolvers which have a forwarding policy other than dns_fwdpolicy_only  *	need to be primed with the root nameservers, otherwise the root  *	nameserver hints data may be used indefinitely.  This function requests  *	that the resolver start a priming fetch, if it isn't already priming.  *  * Requires:  *  *	'res' is a valid, frozen resolver.  */
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
comment|/*  * Send '*eventp' to 'task' when 'res' has completed shutdown.  *  * Notes:  *  *	It is not safe to detach the last reference to 'res' until  *	shutdown is complete.  *  * Requires:  *  *	'res' is a valid resolver.  *  *	'task' is a valid task.  *  *	*eventp is a valid event.  *  * Ensures:  *  *	*eventp == NULL.  */
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
comment|/*  * Start the shutdown process for 'res'.  *  * Notes:  *  *	This call has no effect if the resolver is already shutting down.  *  * Requires:  *  *	'res' is a valid resolver.  */
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

begin_comment
comment|/*  * Recurse to answer a question.  *  * Notes:  *  *	This call starts a query for 'name', type 'type'.  *  *	The 'domain' is a parent domain of 'name' for which  *	a set of name servers 'nameservers' is known.  If no  *	such name server information is available, set  * 	'domain' and 'nameservers' to NULL.  *  *	'forwarders' is unimplemented, and subject to change when  *	we figure out how selective forwarding will work.  *  *	When the fetch completes (successfully or otherwise), a  *	DNS_EVENT_FETCHDONE event with action 'action' and arg 'arg' will be  *	posted to 'task'.  *  *	The values of 'rdataset' and 'sigrdataset' will be returned in  *	the FETCHDONE event.  *  * Requires:  *  *	'res' is a valid resolver that has been frozen.  *  *	'name' is a valid name.  *  *	'type' is not a meta type other than ANY.  *  *	'domain' is a valid name or NULL.  *  *	'nameservers' is a valid NS rdataset (whose owner name is 'domain')  *	iff. 'domain' is not NULL.  *  *	'forwarders' is NULL.  *  *	'options' contains valid options.  *  *	'rdataset' is a valid, disassociated rdataset.  *  *	'sigrdataset' is NULL, or is a valid, disassociated rdataset.  *  *	fetchp != NULL&& *fetchp == NULL.  *  * Returns:  *  *	ISC_R_SUCCESS					Success  *  *	Many other values are possible, all of which indicate failure.  */
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
comment|/*  * Cancel 'fetch'.  *  * Notes:  *  *	If 'fetch' has not completed, post its FETCHDONE event with a  *	result code of ISC_R_CANCELED.  *  * Requires:  *  *	'fetch' is a valid fetch.  */
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
comment|/*  * Destroy 'fetch'.  *  * Requires:  *  *	'*fetchp' is a valid fetch.  *  *	The caller has received the FETCHDONE event (either because the  *	fetch completed or because dns_resolver_cancelfetch() was called).  *  * Ensures:  *  *	*fetchp == NULL.  */
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
comment|/*  * Get the resolver's lame-ttl.  zero => no lame processing.  *  * Requires:  *	'resolver' to be valid.  */
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
comment|/*  * Set the resolver's lame-ttl.  zero => no lame processing.  *  * Requires:  *	'resolver' to be valid.  */
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
comment|/*  * Return the number of currently running resolutions in this  * resolver.  This is may be less than the number of outstanding  * fetches due to multiple identical fetches, or more than the  * number of of outstanding fetches due to the fact that resolution  * can continue even though a fetch has been canceled.  */
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
comment|/*  * Add alternate addresses to be tried in the event that the nameservers  * for a zone are not available in the address families supported by the  * operating system.  *  * Require:  * 	only one of 'name' or 'alt' to be valid.  */
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
comment|/*  * Set the EDNS UDP buffer size advertised by the server.  */
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
comment|/*  * Get the current EDNS UDP buffer size.  */
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
comment|/*  * Clear the disabled DNSSEC algorithms.  */
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
comment|/*  * Mark the give DNSSEC algorithm as disabled and below 'name'.  * Valid algorithms are less than 256.  *  * Returns:  *	ISC_R_SUCCESS  *	ISC_R_RANGE  *	ISC_R_NOMEMORY  */
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
comment|/*  * Check if the given algorithm is supported by this resolver.  * This checks if the algorithm has been disabled via  * dns_resolver_disable_algorithm() then the underlying  * crypto libraries if not specifically disabled.  */
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

