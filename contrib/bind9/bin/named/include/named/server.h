begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004-2014  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1999-2003  Internet Software Consortium.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NAMED_SERVER_H
end_ifndef

begin_define
define|#
directive|define
name|NAMED_SERVER_H
value|1
end_define

begin_comment
comment|/*! \file */
end_comment

begin_include
include|#
directive|include
file|<isc/log.h>
end_include

begin_include
include|#
directive|include
file|<isc/magic.h>
end_include

begin_include
include|#
directive|include
file|<isc/quota.h>
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
file|<isc/xml.h>
end_include

begin_include
include|#
directive|include
file|<dns/acl.h>
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

begin_define
define|#
directive|define
name|NS_EVENTCLASS
value|ISC_EVENTCLASS(0x4E43)
end_define

begin_define
define|#
directive|define
name|NS_EVENT_RELOAD
value|(NS_EVENTCLASS + 0)
end_define

begin_define
define|#
directive|define
name|NS_EVENT_CLIENTCONTROL
value|(NS_EVENTCLASS + 1)
end_define

begin_comment
comment|/*%  * Name server state.  Better here than in lots of separate global variables.  */
end_comment

begin_struct
struct|struct
name|ns_server
block|{
name|unsigned
name|int
name|magic
decl_stmt|;
name|isc_mem_t
modifier|*
name|mctx
decl_stmt|;
name|isc_task_t
modifier|*
name|task
decl_stmt|;
comment|/* Configurable data. */
name|isc_quota_t
name|xfroutquota
decl_stmt|;
name|isc_quota_t
name|tcpquota
decl_stmt|;
name|isc_quota_t
name|recursionquota
decl_stmt|;
name|dns_acl_t
modifier|*
name|blackholeacl
decl_stmt|;
name|char
modifier|*
name|statsfile
decl_stmt|;
comment|/*%< Statistics file name */
name|char
modifier|*
name|dumpfile
decl_stmt|;
comment|/*%< Dump file name */
name|char
modifier|*
name|secrootsfile
decl_stmt|;
comment|/*%< Secroots file name */
name|char
modifier|*
name|bindkeysfile
decl_stmt|;
comment|/*%< bind.keys file name */
name|char
modifier|*
name|recfile
decl_stmt|;
comment|/*%< Recursive file name */
name|isc_boolean_t
name|version_set
decl_stmt|;
comment|/*%< User has set version */
name|char
modifier|*
name|version
decl_stmt|;
comment|/*%< User-specified version */
name|isc_boolean_t
name|hostname_set
decl_stmt|;
comment|/*%< User has set hostname */
name|char
modifier|*
name|hostname
decl_stmt|;
comment|/*%< User-specified hostname */
comment|/*% Use hostname for server id */
name|isc_boolean_t
name|server_usehostname
decl_stmt|;
name|char
modifier|*
name|server_id
decl_stmt|;
comment|/*%< User-specified server id */
comment|/*% 	 * Current ACL environment.  This defines the 	 * current values of the localhost and localnets 	 * ACLs. 	 */
name|dns_aclenv_t
name|aclenv
decl_stmt|;
comment|/* Server data structures. */
name|dns_loadmgr_t
modifier|*
name|loadmgr
decl_stmt|;
name|dns_zonemgr_t
modifier|*
name|zonemgr
decl_stmt|;
name|dns_viewlist_t
name|viewlist
decl_stmt|;
name|ns_interfacemgr_t
modifier|*
name|interfacemgr
decl_stmt|;
name|dns_db_t
modifier|*
name|in_roothints
decl_stmt|;
name|dns_tkeyctx_t
modifier|*
name|tkeyctx
decl_stmt|;
name|isc_timer_t
modifier|*
name|interface_timer
decl_stmt|;
name|isc_timer_t
modifier|*
name|heartbeat_timer
decl_stmt|;
name|isc_timer_t
modifier|*
name|pps_timer
decl_stmt|;
name|isc_uint32_t
name|interface_interval
decl_stmt|;
name|isc_uint32_t
name|heartbeat_interval
decl_stmt|;
name|isc_mutex_t
name|reload_event_lock
decl_stmt|;
name|isc_event_t
modifier|*
name|reload_event
decl_stmt|;
name|isc_boolean_t
name|flushonshutdown
decl_stmt|;
name|isc_boolean_t
name|log_queries
decl_stmt|;
comment|/*%< For BIND 8 compatibility */
name|ns_cachelist_t
name|cachelist
decl_stmt|;
comment|/*%< Possibly shared caches */
name|isc_stats_t
modifier|*
name|nsstats
decl_stmt|;
comment|/*%< Server stats */
name|dns_stats_t
modifier|*
name|rcvquerystats
decl_stmt|;
comment|/*% Incoming query stats */
name|dns_stats_t
modifier|*
name|opcodestats
decl_stmt|;
comment|/*%< Incoming message stats */
name|isc_stats_t
modifier|*
name|zonestats
decl_stmt|;
comment|/*% Zone management stats */
name|isc_stats_t
modifier|*
name|resolverstats
decl_stmt|;
comment|/*% Resolver stats */
name|isc_stats_t
modifier|*
name|sockstats
decl_stmt|;
comment|/*%< Socket stats */
name|ns_controls_t
modifier|*
name|controls
decl_stmt|;
comment|/*%< Control channels */
name|unsigned
name|int
name|dispatchgen
decl_stmt|;
name|ns_dispatchlist_t
name|dispatches
decl_stmt|;
name|dns_acache_t
modifier|*
name|acache
decl_stmt|;
name|ns_statschannellist_t
name|statschannels
decl_stmt|;
name|dns_tsigkey_t
modifier|*
name|sessionkey
decl_stmt|;
name|char
modifier|*
name|session_keyfile
decl_stmt|;
name|dns_name_t
modifier|*
name|session_keyname
decl_stmt|;
name|unsigned
name|int
name|session_keyalg
decl_stmt|;
name|isc_uint16_t
name|session_keybits
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NS_SERVER_MAGIC
value|ISC_MAGIC('S','V','E','R')
end_define

begin_define
define|#
directive|define
name|NS_SERVER_VALID
parameter_list|(
name|s
parameter_list|)
value|ISC_MAGIC_VALID(s, NS_SERVER_MAGIC)
end_define

begin_comment
comment|/*%  * Server statistics counters.  Used as isc_statscounter_t values.  */
end_comment

begin_enum
enum|enum
block|{
name|dns_nsstatscounter_requestv4
init|=
literal|0
block|,
name|dns_nsstatscounter_requestv6
init|=
literal|1
block|,
name|dns_nsstatscounter_edns0in
init|=
literal|2
block|,
name|dns_nsstatscounter_badednsver
init|=
literal|3
block|,
name|dns_nsstatscounter_tsigin
init|=
literal|4
block|,
name|dns_nsstatscounter_sig0in
init|=
literal|5
block|,
name|dns_nsstatscounter_invalidsig
init|=
literal|6
block|,
name|dns_nsstatscounter_tcp
init|=
literal|7
block|,
name|dns_nsstatscounter_authrej
init|=
literal|8
block|,
name|dns_nsstatscounter_recurserej
init|=
literal|9
block|,
name|dns_nsstatscounter_xfrrej
init|=
literal|10
block|,
name|dns_nsstatscounter_updaterej
init|=
literal|11
block|,
name|dns_nsstatscounter_response
init|=
literal|12
block|,
name|dns_nsstatscounter_truncatedresp
init|=
literal|13
block|,
name|dns_nsstatscounter_edns0out
init|=
literal|14
block|,
name|dns_nsstatscounter_tsigout
init|=
literal|15
block|,
name|dns_nsstatscounter_sig0out
init|=
literal|16
block|,
name|dns_nsstatscounter_success
init|=
literal|17
block|,
name|dns_nsstatscounter_authans
init|=
literal|18
block|,
name|dns_nsstatscounter_nonauthans
init|=
literal|19
block|,
name|dns_nsstatscounter_referral
init|=
literal|20
block|,
name|dns_nsstatscounter_nxrrset
init|=
literal|21
block|,
name|dns_nsstatscounter_servfail
init|=
literal|22
block|,
name|dns_nsstatscounter_formerr
init|=
literal|23
block|,
name|dns_nsstatscounter_nxdomain
init|=
literal|24
block|,
name|dns_nsstatscounter_recursion
init|=
literal|25
block|,
name|dns_nsstatscounter_duplicate
init|=
literal|26
block|,
name|dns_nsstatscounter_dropped
init|=
literal|27
block|,
name|dns_nsstatscounter_failure
init|=
literal|28
block|,
name|dns_nsstatscounter_xfrdone
init|=
literal|29
block|,
name|dns_nsstatscounter_updatereqfwd
init|=
literal|30
block|,
name|dns_nsstatscounter_updaterespfwd
init|=
literal|31
block|,
name|dns_nsstatscounter_updatefwdfail
init|=
literal|32
block|,
name|dns_nsstatscounter_updatedone
init|=
literal|33
block|,
name|dns_nsstatscounter_updatefail
init|=
literal|34
block|,
name|dns_nsstatscounter_updatebadprereq
init|=
literal|35
block|,
name|dns_nsstatscounter_rpz_rewrites
init|=
literal|36
block|,
ifdef|#
directive|ifdef
name|USE_RRL
name|dns_nsstatscounter_ratedropped
init|=
literal|37
block|,
name|dns_nsstatscounter_rateslipped
init|=
literal|38
block|,
name|dns_nsstatscounter_max
init|=
literal|39
else|#
directive|else
comment|/* USE_RRL */
name|dns_nsstatscounter_max
operator|=
literal|37
endif|#
directive|endif
comment|/* USE_RRL */
block|}
enum|;
end_enum

begin_function_decl
name|void
name|ns_server_create
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|ns_server_t
modifier|*
modifier|*
name|serverp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Create a server object with default settings.  * This function either succeeds or causes the program to exit  * with a fatal error.  */
end_comment

begin_function_decl
name|void
name|ns_server_destroy
parameter_list|(
name|ns_server_t
modifier|*
modifier|*
name|serverp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Destroy a server object, freeing its memory.  */
end_comment

begin_function_decl
name|void
name|ns_server_reloadwanted
parameter_list|(
name|ns_server_t
modifier|*
name|server
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Inform a server that a reload is wanted.  This function  * may be called asynchronously, from outside the server's task.  * If a reload is already scheduled or in progress, the call  * is ignored.  */
end_comment

begin_function_decl
name|void
name|ns_server_flushonshutdown
parameter_list|(
name|ns_server_t
modifier|*
name|server
parameter_list|,
name|isc_boolean_t
name|flush
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Inform the server that the zones should be flushed to disk on shutdown.  */
end_comment

begin_function_decl
name|isc_result_t
name|ns_server_reloadcommand
parameter_list|(
name|ns_server_t
modifier|*
name|server
parameter_list|,
name|char
modifier|*
name|args
parameter_list|,
name|isc_buffer_t
modifier|*
name|text
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Act on a "reload" command from the command channel.  */
end_comment

begin_function_decl
name|isc_result_t
name|ns_server_reconfigcommand
parameter_list|(
name|ns_server_t
modifier|*
name|server
parameter_list|,
name|char
modifier|*
name|args
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Act on a "reconfig" command from the command channel.  */
end_comment

begin_function_decl
name|isc_result_t
name|ns_server_notifycommand
parameter_list|(
name|ns_server_t
modifier|*
name|server
parameter_list|,
name|char
modifier|*
name|args
parameter_list|,
name|isc_buffer_t
modifier|*
name|text
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Act on a "notify" command from the command channel.  */
end_comment

begin_function_decl
name|isc_result_t
name|ns_server_refreshcommand
parameter_list|(
name|ns_server_t
modifier|*
name|server
parameter_list|,
name|char
modifier|*
name|args
parameter_list|,
name|isc_buffer_t
modifier|*
name|text
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Act on a "refresh" command from the command channel.  */
end_comment

begin_function_decl
name|isc_result_t
name|ns_server_retransfercommand
parameter_list|(
name|ns_server_t
modifier|*
name|server
parameter_list|,
name|char
modifier|*
name|args
parameter_list|,
name|isc_buffer_t
modifier|*
name|text
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Act on a "retransfer" command from the command channel.  */
end_comment

begin_function_decl
name|isc_result_t
name|ns_server_togglequerylog
parameter_list|(
name|ns_server_t
modifier|*
name|server
parameter_list|,
name|char
modifier|*
name|args
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Enable/disable logging of queries.  (Takes "yes" or "no" argument,  * but can also be used as a toggle for backward comptibility.)  */
end_comment

begin_comment
comment|/*%  * Dump the current statistics to the statistics file.  */
end_comment

begin_function_decl
name|isc_result_t
name|ns_server_dumpstats
parameter_list|(
name|ns_server_t
modifier|*
name|server
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%  * Dump the current cache to the dump file.  */
end_comment

begin_function_decl
name|isc_result_t
name|ns_server_dumpdb
parameter_list|(
name|ns_server_t
modifier|*
name|server
parameter_list|,
name|char
modifier|*
name|args
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%  * Dump the current security roots to the secroots file.  */
end_comment

begin_function_decl
name|isc_result_t
name|ns_server_dumpsecroots
parameter_list|(
name|ns_server_t
modifier|*
name|server
parameter_list|,
name|char
modifier|*
name|args
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%  * Change or increment the server debug level.  */
end_comment

begin_function_decl
name|isc_result_t
name|ns_server_setdebuglevel
parameter_list|(
name|ns_server_t
modifier|*
name|server
parameter_list|,
name|char
modifier|*
name|args
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%  * Flush the server's cache(s)  */
end_comment

begin_function_decl
name|isc_result_t
name|ns_server_flushcache
parameter_list|(
name|ns_server_t
modifier|*
name|server
parameter_list|,
name|char
modifier|*
name|args
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%  * Flush a particular name from the server's cache.  If 'tree' is false,  * also flush the name from the ADB and badcache.  If 'tree' is true, also  * flush all the names under the specified name.  */
end_comment

begin_function_decl
name|isc_result_t
name|ns_server_flushnode
parameter_list|(
name|ns_server_t
modifier|*
name|server
parameter_list|,
name|char
modifier|*
name|args
parameter_list|,
name|isc_boolean_t
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%  * Report the server's status.  */
end_comment

begin_function_decl
name|isc_result_t
name|ns_server_status
parameter_list|(
name|ns_server_t
modifier|*
name|server
parameter_list|,
name|isc_buffer_t
modifier|*
name|text
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%  * Report a list of dynamic and static tsig keys, per view.  */
end_comment

begin_function_decl
name|isc_result_t
name|ns_server_tsiglist
parameter_list|(
name|ns_server_t
modifier|*
name|server
parameter_list|,
name|isc_buffer_t
modifier|*
name|text
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%  * Delete a specific key (with optional view).  */
end_comment

begin_function_decl
name|isc_result_t
name|ns_server_tsigdelete
parameter_list|(
name|ns_server_t
modifier|*
name|server
parameter_list|,
name|char
modifier|*
name|command
parameter_list|,
name|isc_buffer_t
modifier|*
name|text
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%  * Enable or disable updates for a zone.  */
end_comment

begin_function_decl
name|isc_result_t
name|ns_server_freeze
parameter_list|(
name|ns_server_t
modifier|*
name|server
parameter_list|,
name|isc_boolean_t
name|freeze
parameter_list|,
name|char
modifier|*
name|args
parameter_list|,
name|isc_buffer_t
modifier|*
name|text
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%  * Dump zone updates to disk, optionally removing the journal file  */
end_comment

begin_function_decl
name|isc_result_t
name|ns_server_sync
parameter_list|(
name|ns_server_t
modifier|*
name|server
parameter_list|,
name|char
modifier|*
name|args
parameter_list|,
name|isc_buffer_t
modifier|*
name|text
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%  * Update a zone's DNSKEY set from the key repository.  If  * the command that triggered the call to this function was "sign",  * then force a full signing of the zone.  If it was "loadkeys",  * then don't sign the zone; any needed changes to signatures can  * take place incrementally.  */
end_comment

begin_function_decl
name|isc_result_t
name|ns_server_rekey
parameter_list|(
name|ns_server_t
modifier|*
name|server
parameter_list|,
name|char
modifier|*
name|args
parameter_list|,
name|isc_buffer_t
modifier|*
name|text
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%  * Dump the current recursive queries.  */
end_comment

begin_function_decl
name|isc_result_t
name|ns_server_dumprecursing
parameter_list|(
name|ns_server_t
modifier|*
name|server
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%  * Maintain a list of dispatches that require reserved ports.  */
end_comment

begin_function_decl
name|void
name|ns_add_reserved_dispatch
parameter_list|(
name|ns_server_t
modifier|*
name|server
parameter_list|,
specifier|const
name|isc_sockaddr_t
modifier|*
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%  * Enable or disable dnssec validation.  */
end_comment

begin_function_decl
name|isc_result_t
name|ns_server_validation
parameter_list|(
name|ns_server_t
modifier|*
name|server
parameter_list|,
name|char
modifier|*
name|args
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%  * Add a zone to a running process  */
end_comment

begin_function_decl
name|isc_result_t
name|ns_server_add_zone
parameter_list|(
name|ns_server_t
modifier|*
name|server
parameter_list|,
name|char
modifier|*
name|args
parameter_list|,
name|isc_buffer_t
modifier|*
name|text
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%  * Deletes a zone from a running process  */
end_comment

begin_function_decl
name|isc_result_t
name|ns_server_del_zone
parameter_list|(
name|ns_server_t
modifier|*
name|server
parameter_list|,
name|char
modifier|*
name|args
parameter_list|,
name|isc_buffer_t
modifier|*
name|text
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%  * Lists the status of the signing records for a given zone.  */
end_comment

begin_function_decl
name|isc_result_t
name|ns_server_signing
parameter_list|(
name|ns_server_t
modifier|*
name|server
parameter_list|,
name|char
modifier|*
name|args
parameter_list|,
name|isc_buffer_t
modifier|*
name|text
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NAMED_SERVER_H */
end_comment

end_unit

