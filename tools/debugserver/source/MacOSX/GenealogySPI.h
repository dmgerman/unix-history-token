begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ActivitySPI.h -------------------------------------------*- C++ -*-===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                     The LLVM Compiler Infrastructure
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is distributed under the University of Illinois Open Source
end_comment

begin_comment
comment|// License. See LICENSE.TXT for details.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__GenealogySPI_h__
end_ifndef

begin_define
define|#
directive|define
name|__GenealogySPI_h__
end_define

begin_include
include|#
directive|include
file|<xpc/xpc.h>
end_include

begin_typedef
typedef|typedef
name|void
modifier|*
name|os_activity_process_list_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
modifier|*
name|os_activity_list_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
modifier|*
name|os_trace_message_list_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|os_activity_watch_s
modifier|*
name|os_activity_watch_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint64_t
name|os_activity_t
typedef|;
end_typedef

begin_struct
struct|struct
name|os_activity_breadcrumb_s
block|{
name|uint32_t
name|breadcrumb_id
decl_stmt|;
name|uint64_t
name|activity_id
decl_stmt|;
name|uint64_t
name|timestamp
decl_stmt|;
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|os_activity_breadcrumb_s
modifier|*
name|os_activity_breadcrumb_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|os_trace_message_s
block|{
name|uint64_t
name|trace_id
decl_stmt|;
name|uint64_t
name|thread
decl_stmt|;
name|uint64_t
name|timestamp
decl_stmt|;
name|uint32_t
name|offset
decl_stmt|;
name|xpc_object_t
name|__unsafe_unretained
name|payload
decl_stmt|;
specifier|const
name|uint8_t
modifier|*
name|image_uuid
decl_stmt|;
specifier|const
name|char
modifier|*
name|image_path
decl_stmt|;
specifier|const
name|char
modifier|*
name|format
decl_stmt|;
specifier|const
name|void
modifier|*
name|buffer
decl_stmt|;
name|size_t
name|bufferLen
decl_stmt|;
block|}
typedef|*
name|os_trace_message_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|os_activity_process_s
block|{
name|os_activity_process_list_t
name|child_procs
decl_stmt|;
name|os_trace_message_list_t
name|messages
decl_stmt|;
name|os_activity_list_t
name|activities
decl_stmt|;
name|void
modifier|*
name|breadcrumbs
decl_stmt|;
name|uint64_t
name|proc_id
decl_stmt|;
specifier|const
name|uint8_t
modifier|*
name|image_uuid
decl_stmt|;
specifier|const
name|char
modifier|*
name|image_path
decl_stmt|;
name|pid_t
name|pid
decl_stmt|;
block|}
typedef|*
name|os_activity_process_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|os_activity_entry_s
block|{
name|uint64_t
name|activity_start
decl_stmt|;
name|os_activity_t
name|activity_id
decl_stmt|;
name|os_activity_t
name|parent_id
decl_stmt|;
specifier|const
name|char
modifier|*
name|activity_name
decl_stmt|;
specifier|const
name|char
modifier|*
name|reason
decl_stmt|;
name|os_trace_message_list_t
name|messages
decl_stmt|;
block|}
typedef|*
name|os_activity_entry_t
typedef|;
end_typedef

begin_enum
enum|enum
block|{
name|OS_ACTIVITY_DIAGNOSTIC_DEFAULT
init|=
literal|0x00000000
block|,
name|OS_ACTIVITY_DIAGNOSTIC_PROCESS_ONLY
init|=
literal|0x00000001
block|,
name|OS_ACTIVITY_DIAGNOSTIC_SKIP_DECODE
init|=
literal|0x00000002
block|,
name|OS_ACTIVITY_DIAGNOSTIC_FLATTENED
init|=
literal|0x00000004
block|,
name|OS_ACTIVITY_DIAGNOSTIC_ALL_ACTIVITIES
init|=
literal|0x00000008
block|,
name|OS_ACTIVITY_DIAGNOSTIC_MAX
init|=
literal|0x0000000f
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|uint32_t
name|os_activity_diagnostic_flag_t
typedef|;
end_typedef

begin_enum
enum|enum
block|{
name|OS_ACTIVITY_WATCH_DEFAULT
init|=
literal|0x00000000
block|,
name|OS_ACTIVITY_WATCH_PROCESS_ONLY
init|=
literal|0x00000001
block|,
name|OS_ACTIVITY_WATCH_SKIP_DECODE
init|=
literal|0x00000002
block|,
name|OS_ACTIVITY_WATCH_PAYLOAD
init|=
literal|0x00000004
block|,
name|OS_ACTIVITY_WATCH_ERRORS
init|=
literal|0x00000008
block|,
name|OS_ACTIVITY_WATCH_FAULTS
init|=
literal|0x00000010
block|,
name|OS_ACTIVITY_WATCH_MAX
init|=
literal|0x0000001f
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|uint32_t
name|os_activity_watch_flag_t
typedef|;
end_typedef

begin_comment
comment|// Return values from os_trace_get_type()
end_comment

begin_define
define|#
directive|define
name|OS_TRACE_TYPE_RELEASE
value|(1u<< 0)
end_define

begin_define
define|#
directive|define
name|OS_TRACE_TYPE_DEBUG
value|(1u<< 1)
end_define

begin_define
define|#
directive|define
name|OS_TRACE_TYPE_ERROR
value|((1u<< 6) | (1u<< 0))
end_define

begin_define
define|#
directive|define
name|OS_TRACE_TYPE_FAULT
value|((1u<< 7) | (1u<< 6) | (1u<< 0))
end_define

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|^
name|os_activity_watch_block_t
function_decl|)
parameter_list|(
name|os_activity_watch_t
name|watch
parameter_list|,
name|os_activity_process_t
name|process_info
parameter_list|,
name|bool
name|canceled
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|^
name|os_diagnostic_block_t
function_decl|)
parameter_list|(
name|os_activity_process_list_t
name|processes
parameter_list|,
name|int
name|error
parameter_list|)
function_decl|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

end_unit

