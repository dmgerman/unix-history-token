begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004-2009, 2012  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1999-2003  Internet Software Consortium.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_TYPES_H
end_ifndef

begin_define
define|#
directive|define
name|ISC_TYPES_H
value|1
end_define

begin_include
include|#
directive|include
file|<isc/bind9.h>
end_include

begin_include
include|#
directive|include
file|<isc/namespace.h>
end_include

begin_comment
comment|/*! \file isc/types.h  * \brief  * OS-specific types, from the OS-specific include directories.  */
end_comment

begin_include
include|#
directive|include
file|<isc/int.h>
end_include

begin_include
include|#
directive|include
file|<isc/offset.h>
end_include

begin_comment
comment|/*  * XXXDCL should isc_boolean_t be moved here, requiring an explicit include  * of<isc/boolean.h> when ISC_TRUE/ISC_FALSE/ISC_TF() are desired?  */
end_comment

begin_include
include|#
directive|include
file|<isc/boolean.h>
end_include

begin_comment
comment|/*  * XXXDCL This is just for ISC_LIST and ISC_LINK, but gets all of the other  * list macros too.  */
end_comment

begin_include
include|#
directive|include
file|<isc/list.h>
end_include

begin_comment
comment|/* Core Types.  Alphabetized by defined type. */
end_comment

begin_typedef
typedef|typedef
name|struct
name|isc_appctx
name|isc_appctx_t
typedef|;
end_typedef

begin_comment
comment|/*%< Application context */
end_comment

begin_typedef
typedef|typedef
name|struct
name|isc_backtrace_symmap
name|isc_backtrace_symmap_t
typedef|;
end_typedef

begin_comment
comment|/*%< Symbol Table Entry */
end_comment

begin_typedef
typedef|typedef
name|struct
name|isc_bitstring
name|isc_bitstring_t
typedef|;
end_typedef

begin_comment
comment|/*%< Bitstring */
end_comment

begin_typedef
typedef|typedef
name|struct
name|isc_buffer
name|isc_buffer_t
typedef|;
end_typedef

begin_comment
comment|/*%< Buffer */
end_comment

begin_typedef
typedef|typedef
name|ISC_LIST
argument_list|(
argument|isc_buffer_t
argument_list|)
name|isc_bufferlist_t
expr_stmt|;
end_typedef

begin_comment
comment|/*%< Buffer List */
end_comment

begin_typedef
typedef|typedef
name|struct
name|isc_constregion
name|isc_constregion_t
typedef|;
end_typedef

begin_comment
comment|/*%< Const region */
end_comment

begin_typedef
typedef|typedef
name|struct
name|isc_consttextregion
name|isc_consttextregion_t
typedef|;
end_typedef

begin_comment
comment|/*%< Const Text Region */
end_comment

begin_typedef
typedef|typedef
name|struct
name|isc_entropy
name|isc_entropy_t
typedef|;
end_typedef

begin_comment
comment|/*%< Entropy */
end_comment

begin_typedef
typedef|typedef
name|struct
name|isc_entropysource
name|isc_entropysource_t
typedef|;
end_typedef

begin_comment
comment|/*%< Entropy Source */
end_comment

begin_typedef
typedef|typedef
name|struct
name|isc_event
name|isc_event_t
typedef|;
end_typedef

begin_comment
comment|/*%< Event */
end_comment

begin_typedef
typedef|typedef
name|ISC_LIST
argument_list|(
argument|isc_event_t
argument_list|)
name|isc_eventlist_t
expr_stmt|;
end_typedef

begin_comment
comment|/*%< Event List */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|int
name|isc_eventtype_t
typedef|;
end_typedef

begin_comment
comment|/*%< Event Type */
end_comment

begin_typedef
typedef|typedef
name|isc_uint32_t
name|isc_fsaccess_t
typedef|;
end_typedef

begin_comment
comment|/*%< FS Access */
end_comment

begin_typedef
typedef|typedef
name|struct
name|isc_hash
name|isc_hash_t
typedef|;
end_typedef

begin_comment
comment|/*%< Hash */
end_comment

begin_typedef
typedef|typedef
name|struct
name|isc_httpd
name|isc_httpd_t
typedef|;
end_typedef

begin_comment
comment|/*%< HTTP client */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
name|isc_httpdfree_t
function_decl|)
parameter_list|(
name|isc_buffer_t
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*%< HTTP free function */
end_comment

begin_typedef
typedef|typedef
name|struct
name|isc_httpdmgr
name|isc_httpdmgr_t
typedef|;
end_typedef

begin_comment
comment|/*%< HTTP manager */
end_comment

begin_typedef
typedef|typedef
name|struct
name|isc_httpdurl
name|isc_httpdurl_t
typedef|;
end_typedef

begin_comment
comment|/*%< HTTP URL */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
name|isc_httpdondestroy_t
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*%< Callback on destroying httpd */
end_comment

begin_typedef
typedef|typedef
name|struct
name|isc_interface
name|isc_interface_t
typedef|;
end_typedef

begin_comment
comment|/*%< Interface */
end_comment

begin_typedef
typedef|typedef
name|struct
name|isc_interfaceiter
name|isc_interfaceiter_t
typedef|;
end_typedef

begin_comment
comment|/*%< Interface Iterator */
end_comment

begin_typedef
typedef|typedef
name|struct
name|isc_interval
name|isc_interval_t
typedef|;
end_typedef

begin_comment
comment|/*%< Interval */
end_comment

begin_typedef
typedef|typedef
name|struct
name|isc_lex
name|isc_lex_t
typedef|;
end_typedef

begin_comment
comment|/*%< Lex */
end_comment

begin_typedef
typedef|typedef
name|struct
name|isc_log
name|isc_log_t
typedef|;
end_typedef

begin_comment
comment|/*%< Log */
end_comment

begin_typedef
typedef|typedef
name|struct
name|isc_logcategory
name|isc_logcategory_t
typedef|;
end_typedef

begin_comment
comment|/*%< Log Category */
end_comment

begin_typedef
typedef|typedef
name|struct
name|isc_logconfig
name|isc_logconfig_t
typedef|;
end_typedef

begin_comment
comment|/*%< Log Configuration */
end_comment

begin_typedef
typedef|typedef
name|struct
name|isc_logmodule
name|isc_logmodule_t
typedef|;
end_typedef

begin_comment
comment|/*%< Log Module */
end_comment

begin_typedef
typedef|typedef
name|struct
name|isc_mem
name|isc_mem_t
typedef|;
end_typedef

begin_comment
comment|/*%< Memory */
end_comment

begin_typedef
typedef|typedef
name|struct
name|isc_mempool
name|isc_mempool_t
typedef|;
end_typedef

begin_comment
comment|/*%< Memory Pool */
end_comment

begin_typedef
typedef|typedef
name|struct
name|isc_msgcat
name|isc_msgcat_t
typedef|;
end_typedef

begin_comment
comment|/*%< Message Catalog */
end_comment

begin_typedef
typedef|typedef
name|struct
name|isc_ondestroy
name|isc_ondestroy_t
typedef|;
end_typedef

begin_comment
comment|/*%< On Destroy */
end_comment

begin_typedef
typedef|typedef
name|struct
name|isc_netaddr
name|isc_netaddr_t
typedef|;
end_typedef

begin_comment
comment|/*%< Net Address */
end_comment

begin_typedef
typedef|typedef
name|struct
name|isc_portset
name|isc_portset_t
typedef|;
end_typedef

begin_comment
comment|/*%< Port Set */
end_comment

begin_typedef
typedef|typedef
name|struct
name|isc_quota
name|isc_quota_t
typedef|;
end_typedef

begin_comment
comment|/*%< Quota */
end_comment

begin_typedef
typedef|typedef
name|struct
name|isc_random
name|isc_random_t
typedef|;
end_typedef

begin_comment
comment|/*%< Random */
end_comment

begin_typedef
typedef|typedef
name|struct
name|isc_ratelimiter
name|isc_ratelimiter_t
typedef|;
end_typedef

begin_comment
comment|/*%< Rate Limiter */
end_comment

begin_typedef
typedef|typedef
name|struct
name|isc_region
name|isc_region_t
typedef|;
end_typedef

begin_comment
comment|/*%< Region */
end_comment

begin_typedef
typedef|typedef
name|isc_uint64_t
name|isc_resourcevalue_t
typedef|;
end_typedef

begin_comment
comment|/*%< Resource Value */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|int
name|isc_result_t
typedef|;
end_typedef

begin_comment
comment|/*%< Result */
end_comment

begin_typedef
typedef|typedef
name|struct
name|isc_rwlock
name|isc_rwlock_t
typedef|;
end_typedef

begin_comment
comment|/*%< Read Write Lock */
end_comment

begin_typedef
typedef|typedef
name|struct
name|isc_sockaddr
name|isc_sockaddr_t
typedef|;
end_typedef

begin_comment
comment|/*%< Socket Address */
end_comment

begin_typedef
typedef|typedef
name|struct
name|isc_socket
name|isc_socket_t
typedef|;
end_typedef

begin_comment
comment|/*%< Socket */
end_comment

begin_typedef
typedef|typedef
name|struct
name|isc_socketevent
name|isc_socketevent_t
typedef|;
end_typedef

begin_comment
comment|/*%< Socket Event */
end_comment

begin_typedef
typedef|typedef
name|struct
name|isc_socketmgr
name|isc_socketmgr_t
typedef|;
end_typedef

begin_comment
comment|/*%< Socket Manager */
end_comment

begin_typedef
typedef|typedef
name|struct
name|isc_stats
name|isc_stats_t
typedef|;
end_typedef

begin_comment
comment|/*%< Statistics */
end_comment

begin_typedef
typedef|typedef
name|int
name|isc_statscounter_t
typedef|;
end_typedef

begin_comment
comment|/*%< Statistics Counter */
end_comment

begin_typedef
typedef|typedef
name|struct
name|isc_symtab
name|isc_symtab_t
typedef|;
end_typedef

begin_comment
comment|/*%< Symbol Table */
end_comment

begin_typedef
typedef|typedef
name|struct
name|isc_task
name|isc_task_t
typedef|;
end_typedef

begin_comment
comment|/*%< Task */
end_comment

begin_typedef
typedef|typedef
name|ISC_LIST
argument_list|(
argument|isc_task_t
argument_list|)
name|isc_tasklist_t
expr_stmt|;
end_typedef

begin_comment
comment|/*%< Task List */
end_comment

begin_typedef
typedef|typedef
name|struct
name|isc_taskmgr
name|isc_taskmgr_t
typedef|;
end_typedef

begin_comment
comment|/*%< Task Manager */
end_comment

begin_typedef
typedef|typedef
name|struct
name|isc_textregion
name|isc_textregion_t
typedef|;
end_typedef

begin_comment
comment|/*%< Text Region */
end_comment

begin_typedef
typedef|typedef
name|struct
name|isc_time
name|isc_time_t
typedef|;
end_typedef

begin_comment
comment|/*%< Time */
end_comment

begin_typedef
typedef|typedef
name|struct
name|isc_timer
name|isc_timer_t
typedef|;
end_typedef

begin_comment
comment|/*%< Timer */
end_comment

begin_typedef
typedef|typedef
name|struct
name|isc_timermgr
name|isc_timermgr_t
typedef|;
end_typedef

begin_comment
comment|/*%< Timer Manager */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|isc_taskaction_t
function_decl|)
parameter_list|(
name|isc_task_t
modifier|*
parameter_list|,
name|isc_event_t
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|isc_sockfdwatch_t
function_decl|)
parameter_list|(
name|isc_task_t
modifier|*
parameter_list|,
name|isc_socket_t
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* The following cannot be listed alphabetically due to forward reference */
end_comment

begin_typedef
typedef|typedef
name|isc_result_t
function_decl|(
name|isc_httpdaction_t
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
name|url
parameter_list|,
specifier|const
name|char
modifier|*
name|querystring
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|,
name|unsigned
name|int
modifier|*
name|retcode
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|retmsg
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|mimetype
parameter_list|,
name|isc_buffer_t
modifier|*
name|body
parameter_list|,
name|isc_httpdfree_t
modifier|*
modifier|*
name|freecb
parameter_list|,
name|void
modifier|*
modifier|*
name|freecb_args
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|isc_boolean_t
function_decl|(
name|isc_httpdclientok_t
function_decl|)
parameter_list|(
specifier|const
name|isc_sockaddr_t
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*% Resource */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|isc_resource_coresize
init|=
literal|1
block|,
name|isc_resource_cputime
block|,
name|isc_resource_datasize
block|,
name|isc_resource_filesize
block|,
name|isc_resource_lockedmemory
block|,
name|isc_resource_openfiles
block|,
name|isc_resource_processes
block|,
name|isc_resource_residentsize
block|,
name|isc_resource_stacksize
block|}
name|isc_resource_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISC_TYPES_H */
end_comment

end_unit

