begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 1999  Internet Software Consortium.  *   * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *   * THE SOFTWARE IS PROVIDED "AS IS" AND INTERNET SOFTWARE CONSORTIUM DISCLAIMS  * ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL INTERNET SOFTWARE  * CONSORTIUM BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL  * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR  * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS  * ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS  * SOFTWARE.  */
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
file|<isc-dhcp/int.h>
end_include

begin_include
include|#
directive|include
file|<isc-dhcp/boolean.h>
end_include

begin_include
include|#
directive|include
file|<isc-dhcp/list.h>
end_include

begin_comment
comment|/***  *** Core Types.  ***/
end_comment

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
name|unsigned
name|int
name|isc_eventtype_t
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
name|struct
name|isc_task
name|isc_task_t
typedef|;
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
name|isc_rwlock
name|isc_rwlock_t
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISC_TYPES_H */
end_comment

end_unit

