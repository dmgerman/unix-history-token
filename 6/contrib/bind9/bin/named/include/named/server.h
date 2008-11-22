begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004, 2006  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1999-2003  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: server.h,v 1.58.2.1.10.13 2006/03/02 00:37:20 marka Exp $ */
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

begin_include
include|#
directive|include
file|<isc/log.h>
end_include

begin_include
include|#
directive|include
file|<isc/sockaddr.h>
end_include

begin_include
include|#
directive|include
file|<isc/magic.h>
end_include

begin_include
include|#
directive|include
file|<isc/types.h>
end_include

begin_include
include|#
directive|include
file|<isc/quota.h>
end_include

begin_include
include|#
directive|include
file|<dns/types.h>
end_include

begin_include
include|#
directive|include
file|<dns/acl.h>
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
comment|/*  * Name server state.  Better here than in lots of separate global variables.  */
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
comment|/* Statistics file name */
name|char
modifier|*
name|dumpfile
decl_stmt|;
comment|/* Dump file name */
name|char
modifier|*
name|recfile
decl_stmt|;
comment|/* Recursive file name */
name|isc_boolean_t
name|version_set
decl_stmt|;
comment|/* User has set version */
name|char
modifier|*
name|version
decl_stmt|;
comment|/* User-specified version */
name|isc_boolean_t
name|hostname_set
decl_stmt|;
comment|/* User has set hostname */
name|char
modifier|*
name|hostname
decl_stmt|;
comment|/* User-specified hostname */
comment|/* Use hostname for server id */
name|isc_boolean_t
name|server_usehostname
decl_stmt|;
name|char
modifier|*
name|server_id
decl_stmt|;
comment|/* User-specified server id */
comment|/* 	 * Current ACL environment.  This defines the 	 * current values of the localhost and localnets 	 * ACLs. 	 */
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
comment|/* For BIND 8 compatibility */
name|isc_uint64_t
modifier|*
name|querystats
decl_stmt|;
comment|/* Query statistics counters */
name|ns_controls_t
modifier|*
name|controls
decl_stmt|;
comment|/* Control channels */
name|unsigned
name|int
name|dispatchgen
decl_stmt|;
name|ns_dispatchlist_t
name|dispatches
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
comment|/*  * Create a server object with default settings.  * This function either succeeds or causes the program to exit  * with a fatal error.  */
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
comment|/*  * Destroy a server object, freeing its memory.  */
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
comment|/*  * Inform a server that a reload is wanted.  This function  * may be called asynchronously, from outside the server's task.  * If a reload is already scheduled or in progress, the call  * is ignored.  */
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
comment|/*  * Inform the server that the zones should be flushed to disk on shutdown.  */
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
comment|/*  * Act on a "reload" command from the command channel.  */
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
comment|/*  * Act on a "reconfig" command from the command channel.  */
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
comment|/*  * Act on a "refresh" command from the command channel.  */
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
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Act on a "retransfer" command from the command channel.  */
end_comment

begin_function_decl
name|isc_result_t
name|ns_server_togglequerylog
parameter_list|(
name|ns_server_t
modifier|*
name|server
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Toggle logging of queries, as in BIND 8.  */
end_comment

begin_comment
comment|/*  * Dump the current statistics to the statistics file.  */
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
comment|/*  * Dump the current cache to the dump file.  */
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
comment|/*  * Change or increment the server debug level.  */
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
comment|/*  * Flush the server's cache(s)  */
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
comment|/*  * Flush a particular name from the server's cache(s)  */
end_comment

begin_function_decl
name|isc_result_t
name|ns_server_flushname
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
comment|/*  * Report the server's status.  */
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
comment|/*  * Enable or disable updates for a zone.  */
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
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Dump the current recursive queries.  */
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
comment|/*  * Maintain a list of dispatches that require reserved ports.  */
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NAMED_SERVER_H */
end_comment

end_unit

