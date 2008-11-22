begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1999-2003  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: types.h,v 1.32.2.3.2.1 2004/03/06 08:14:50 marka Exp $ */
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

begin_comment
comment|/*  * OS-specific types, from the OS-specific include directories.  */
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
comment|/***  *** Core Types.  Alphabetized by defined type.  ***/
end_comment

begin_typedef
typedef|typedef
name|struct
name|isc_bitstring
name|isc_bitstring_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|isc_buffer
name|isc_buffer_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ISC_LIST
argument_list|(
argument|isc_buffer_t
argument_list|)
name|isc_bufferlist_t
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|isc_constregion
name|isc_constregion_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|isc_consttextregion
name|isc_consttextregion_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|isc_entropy
name|isc_entropy_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|isc_entropysource
name|isc_entropysource_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|isc_event
name|isc_event_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ISC_LIST
argument_list|(
argument|isc_event_t
argument_list|)
name|isc_eventlist_t
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|isc_eventtype_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|isc_uint32_t
name|isc_fsaccess_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|isc_hash
name|isc_hash_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|isc_interface
name|isc_interface_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|isc_interfaceiter
name|isc_interfaceiter_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|isc_interval
name|isc_interval_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|isc_lex
name|isc_lex_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|isc_log
name|isc_log_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|isc_logcategory
name|isc_logcategory_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|isc_logconfig
name|isc_logconfig_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|isc_logmodule
name|isc_logmodule_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|isc_mem
name|isc_mem_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|isc_mempool
name|isc_mempool_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|isc_msgcat
name|isc_msgcat_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|isc_ondestroy
name|isc_ondestroy_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|isc_netaddr
name|isc_netaddr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|isc_quota
name|isc_quota_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|isc_random
name|isc_random_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|isc_ratelimiter
name|isc_ratelimiter_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|isc_region
name|isc_region_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|isc_uint64_t
name|isc_resourcevalue_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|isc_result_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|isc_rwlock
name|isc_rwlock_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|isc_sockaddr
name|isc_sockaddr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|isc_socket
name|isc_socket_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|isc_socketevent
name|isc_socketevent_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|isc_socketmgr
name|isc_socketmgr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|isc_symtab
name|isc_symtab_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|isc_task
name|isc_task_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ISC_LIST
argument_list|(
argument|isc_task_t
argument_list|)
name|isc_tasklist_t
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|isc_taskmgr
name|isc_taskmgr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|isc_textregion
name|isc_textregion_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|isc_time
name|isc_time_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|isc_timer
name|isc_timer_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|isc_timermgr
name|isc_timermgr_t
typedef|;
end_typedef

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

