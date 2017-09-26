begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MachException.h -----------------------------------------*- C++ -*-===//
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
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Created by Greg Clayton on 6/18/07.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__MachException_h__
end_ifndef

begin_define
define|#
directive|define
name|__MachException_h__
end_define

begin_include
include|#
directive|include
file|<mach/mach.h>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_include
include|#
directive|include
file|"lldb/Host/Debug.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-private-forward.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-types.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|namespace
name|process_darwin
block|{
typedef|typedef
union|union
name|MachMessageTag
block|{
name|mach_msg_header_t
name|hdr
decl_stmt|;
name|char
name|data
index|[
literal|1024
index|]
decl_stmt|;
block|}
name|MachMessage
typedef|;
name|class
name|MachException
block|{
name|public
label|:
struct|struct
name|PortInfo
block|{
name|exception_mask_t
name|mask
decl_stmt|;
comment|// the exception mask for this device which may be a
comment|// subset of EXC_MASK_ALL...
name|exception_mask_t
name|masks
index|[
name|EXC_TYPES_COUNT
index|]
decl_stmt|;
name|mach_port_t
name|ports
index|[
name|EXC_TYPES_COUNT
index|]
decl_stmt|;
name|exception_behavior_t
name|behaviors
index|[
name|EXC_TYPES_COUNT
index|]
decl_stmt|;
name|thread_state_flavor_t
name|flavors
index|[
name|EXC_TYPES_COUNT
index|]
decl_stmt|;
name|mach_msg_type_number_t
name|count
decl_stmt|;
name|Status
name|Save
parameter_list|(
name|task_t
name|task
parameter_list|)
function_decl|;
name|Status
name|Restore
parameter_list|(
name|task_t
name|task
parameter_list|)
function_decl|;
block|}
struct|;
struct|struct
name|Data
block|{
name|task_t
name|task_port
decl_stmt|;
name|thread_t
name|thread_port
decl_stmt|;
name|exception_type_t
name|exc_type
decl_stmt|;
name|std
operator|::
name|vector
operator|<
name|mach_exception_data_type_t
operator|>
name|exc_data
expr_stmt|;
name|Data
argument_list|()
operator|:
name|task_port
argument_list|(
name|TASK_NULL
argument_list|)
operator|,
name|thread_port
argument_list|(
name|THREAD_NULL
argument_list|)
operator|,
name|exc_type
argument_list|(
literal|0
argument_list|)
operator|,
name|exc_data
argument_list|()
block|{}
name|void
name|Clear
argument_list|()
block|{
name|task_port
operator|=
name|TASK_NULL
block|;
name|thread_port
operator|=
name|THREAD_NULL
block|;
name|exc_type
operator|=
literal|0
block|;
name|exc_data
operator|.
name|clear
argument_list|()
block|;     }
name|bool
name|IsValid
argument_list|()
specifier|const
block|{
return|return
name|task_port
operator|!=
name|TASK_NULL
operator|&&
name|thread_port
operator|!=
name|THREAD_NULL
operator|&&
name|exc_type
operator|!=
literal|0
return|;
block|}
comment|// Return the SoftSignal for this MachException data, or zero if there is
comment|// none
name|int
name|SoftSignal
argument_list|()
specifier|const
block|{
if|if
condition|(
name|exc_type
operator|==
name|EXC_SOFTWARE
operator|&&
name|exc_data
operator|.
name|size
argument_list|()
operator|==
literal|2
operator|&&
name|exc_data
index|[
literal|0
index|]
operator|==
name|EXC_SOFT_SIGNAL
condition|)
return|return
name|static_cast
operator|<
name|int
operator|>
operator|(
name|exc_data
index|[
literal|1
index|]
operator|)
return|;
return|return
literal|0
return|;
block|}
name|bool
name|IsBreakpoint
argument_list|()
decl|const
block|{
return|return
operator|(
name|exc_type
operator|==
name|EXC_BREAKPOINT
operator|||
operator|(
operator|(
name|exc_type
operator|==
name|EXC_SOFTWARE
operator|)
operator|&&
name|exc_data
index|[
literal|0
index|]
operator|==
literal|1
operator|)
operator|)
return|;
block|}
name|bool
name|GetStopInfo
argument_list|(
name|ThreadStopInfo
operator|*
name|stop_info
argument_list|,
specifier|const
name|UnixSignals
operator|&
name|signals
argument_list|,
name|Stream
operator|&
name|stream
argument_list|)
decl|const
struct|;
block|}
empty_stmt|;
struct|struct
name|Message
block|{
name|MachMessage
name|exc_msg
decl_stmt|;
name|MachMessage
name|reply_msg
decl_stmt|;
name|Data
name|state
decl_stmt|;
name|Message
argument_list|()
operator|:
name|state
argument_list|()
block|{
name|memset
argument_list|(
operator|&
name|exc_msg
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|exc_msg
argument_list|)
argument_list|)
block|;
name|memset
argument_list|(
operator|&
name|reply_msg
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|reply_msg
argument_list|)
argument_list|)
block|;     }
name|bool
name|CatchExceptionRaise
argument_list|(
argument|task_t task
argument_list|)
expr_stmt|;
name|Status
name|Reply
argument_list|(
operator|::
name|pid_t
name|inferior_pid
argument_list|,
name|task_t
name|inferior_task
argument_list|,
name|int
name|signal
argument_list|)
decl_stmt|;
name|Status
name|Receive
parameter_list|(
name|mach_port_t
name|receive_port
parameter_list|,
name|mach_msg_option_t
name|options
parameter_list|,
name|mach_msg_timeout_t
name|timeout
parameter_list|,
name|mach_port_t
name|notify_port
init|=
name|MACH_PORT_NULL
parameter_list|)
function_decl|;
name|void
name|Dump
argument_list|(
name|Stream
operator|&
name|stream
argument_list|)
decl|const
decl_stmt|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|Message
operator|>
name|collection
expr_stmt|;
typedef|typedef
name|collection
operator|::
name|iterator
name|iterator
expr_stmt|;
typedef|typedef
name|collection
operator|::
name|const_iterator
name|const_iterator
expr_stmt|;
block|}
struct|;
enum|enum
block|{
name|e_actionForward
block|,
comment|// Forward signal to inferior process
name|e_actionStop
block|,
comment|// Stop when this signal is received
block|}
enum|;
struct|struct
name|Action
block|{
name|task_t
name|task_port
decl_stmt|;
comment|// Set to TASK_NULL for any TASK
name|thread_t
name|thread_port
decl_stmt|;
comment|// Set to THREAD_NULL for any thread
name|exception_type_t
name|exc_mask
decl_stmt|;
comment|// Mach exception mask to watch for
name|std
operator|::
name|vector
operator|<
name|mach_exception_data_type_t
operator|>
name|exc_data_mask
expr_stmt|;
comment|// Mask to apply to
comment|// exception data, or
comment|// empty to ignore
comment|// exc_data value for
comment|// exception
name|std
operator|::
name|vector
operator|<
name|mach_exception_data_type_t
operator|>
name|exc_data_value
expr_stmt|;
comment|// Value to compare
comment|// to exception data
comment|// after masking, or
comment|// empty to ignore
comment|// exc_data value
comment|// for exception
name|uint8_t
name|flags
decl_stmt|;
comment|// Action flags describing what to do with the exception
block|}
struct|;
specifier|static
specifier|const
name|char
modifier|*
name|Name
parameter_list|(
name|exception_type_t
name|exc_type
parameter_list|)
function_decl|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace process_darwin
end_comment

begin_comment
unit|}
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

