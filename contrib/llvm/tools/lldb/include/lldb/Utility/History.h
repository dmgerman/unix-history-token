begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- History.h -----------------------------------------------*- C++ -*-===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|lldb_History_h_
end_ifndef

begin_define
define|#
directive|define
name|lldb_History_h_
end_define

begin_include
include|#
directive|include
file|"lldb/lldb-defines.h"
end_include

begin_comment
comment|// for DISALLOW_COPY_AND_ASSIGN
end_comment

begin_comment
comment|// C++ Includes
end_comment

begin_include
include|#
directive|include
file|<mutex>
end_include

begin_include
include|#
directive|include
file|<stack>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_comment
comment|// for size_t
end_comment

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|Stream
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//----------------------------------------------------------------------
comment|/// @class HistorySource History.h "lldb/Core/History.h"
comment|/// @brief A class that defines history events.
comment|//----------------------------------------------------------------------
name|class
name|HistorySource
block|{
name|public
label|:
typedef|typedef
specifier|const
name|void
modifier|*
name|HistoryEvent
typedef|;
name|HistorySource
argument_list|()
operator|:
name|m_mutex
argument_list|()
operator|,
name|m_events
argument_list|()
block|{}
name|virtual
operator|~
name|HistorySource
argument_list|()
block|{}
comment|// Create a new history event. Subclasses should use any data or members
comment|// in the subclass of this class to produce a history event and push it
comment|// onto the end of the history stack.
name|virtual
name|HistoryEvent
name|CreateHistoryEvent
argument_list|()
operator|=
literal|0
expr_stmt|;
name|virtual
name|void
name|DeleteHistoryEvent
parameter_list|(
name|HistoryEvent
name|event
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|void
name|DumpHistoryEvent
parameter_list|(
name|Stream
modifier|&
name|strm
parameter_list|,
name|HistoryEvent
name|event
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|size_t
name|GetHistoryEventCount
parameter_list|()
init|=
literal|0
function_decl|;
name|virtual
name|HistoryEvent
name|GetHistoryEventAtIndex
parameter_list|(
name|uint32_t
name|idx
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|HistoryEvent
name|GetCurrentHistoryEvent
parameter_list|()
init|=
literal|0
function_decl|;
comment|// Return 0 when lhs == rhs, 1 if lhs> rhs, or -1 if lhs< rhs.
name|virtual
name|int
name|CompareHistoryEvents
parameter_list|(
specifier|const
name|HistoryEvent
name|lhs
parameter_list|,
specifier|const
name|HistoryEvent
name|rhs
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|bool
name|IsCurrentHistoryEvent
parameter_list|(
specifier|const
name|HistoryEvent
name|event
parameter_list|)
init|=
literal|0
function_decl|;
name|private
label|:
typedef|typedef
name|std
operator|::
name|stack
operator|<
name|HistoryEvent
operator|>
name|collection
expr_stmt|;
name|std
operator|::
name|recursive_mutex
name|m_mutex
expr_stmt|;
name|collection
name|m_events
decl_stmt|;
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|HistorySource
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
comment|//----------------------------------------------------------------------
comment|/// @class HistorySourceUInt History.h "lldb/Core/History.h"
comment|/// @brief A class that defines history events that are represented by
comment|/// unsigned integers.
comment|///
comment|/// Any history event that is defined by a unique monotonically
comment|/// increasing unsigned integer
comment|//----------------------------------------------------------------------
name|class
name|HistorySourceUInt
range|:
name|public
name|HistorySource
block|{
name|HistorySourceUInt
argument_list|(
argument|const char *id_name
argument_list|,
argument|uintptr_t start_value =
literal|0u
argument_list|)
operator|:
name|HistorySource
argument_list|()
block|,
name|m_name
argument_list|(
name|id_name
argument_list|)
block|,
name|m_curr_id
argument_list|(
argument|start_value
argument_list|)
block|{}
operator|~
name|HistorySourceUInt
argument_list|()
name|override
block|{}
comment|// Create a new history event. Subclasses should use any data or members
comment|// in the subclass of this class to produce a history event and push it
comment|// onto the end of the history stack.
name|HistoryEvent
name|CreateHistoryEvent
argument_list|()
name|override
block|{
operator|++
name|m_curr_id
block|;
return|return
operator|(
name|HistoryEvent
operator|)
name|m_curr_id
return|;
block|}
name|void
name|DeleteHistoryEvent
argument_list|(
argument|HistoryEvent event
argument_list|)
name|override
block|{
comment|// Nothing to delete, the event contains the integer
block|}
name|void
name|DumpHistoryEvent
argument_list|(
argument|Stream&strm
argument_list|,
argument|HistoryEvent event
argument_list|)
name|override
block|;
name|size_t
name|GetHistoryEventCount
argument_list|()
name|override
block|{
return|return
name|m_curr_id
return|;
block|}
name|HistoryEvent
name|GetHistoryEventAtIndex
argument_list|(
argument|uint32_t idx
argument_list|)
name|override
block|{
return|return
call|(
name|HistoryEvent
call|)
argument_list|(
operator|(
name|uintptr_t
operator|)
name|idx
argument_list|)
return|;
block|}
name|HistoryEvent
name|GetCurrentHistoryEvent
argument_list|()
name|override
block|{
return|return
operator|(
name|HistoryEvent
operator|)
name|m_curr_id
return|;
block|}
comment|// Return 0 when lhs == rhs, 1 if lhs> rhs, or -1 if lhs< rhs.
name|int
name|CompareHistoryEvents
argument_list|(
argument|const HistoryEvent lhs
argument_list|,
argument|const HistoryEvent rhs
argument_list|)
name|override
block|{
name|uintptr_t
name|lhs_uint
operator|=
operator|(
name|uintptr_t
operator|)
name|lhs
block|;
name|uintptr_t
name|rhs_uint
operator|=
operator|(
name|uintptr_t
operator|)
name|rhs
block|;
if|if
condition|(
name|lhs_uint
operator|<
name|rhs_uint
condition|)
return|return
operator|-
literal|1
return|;
if|if
condition|(
name|lhs_uint
operator|>
name|rhs_uint
condition|)
return|return
operator|+
literal|1
return|;
return|return
literal|0
return|;
block|}
end_decl_stmt

begin_function
name|bool
name|IsCurrentHistoryEvent
parameter_list|(
specifier|const
name|HistoryEvent
name|event
parameter_list|)
function|override
block|{
return|return
operator|(
name|uintptr_t
operator|)
name|event
operator|==
name|m_curr_id
return|;
block|}
end_function

begin_label
name|protected
label|:
end_label

begin_expr_stmt
name|std
operator|::
name|string
name|m_name
expr_stmt|;
end_expr_stmt

begin_comment
comment|// The name of the history unsigned integer
end_comment

begin_decl_stmt
name|uintptr_t
name|m_curr_id
decl_stmt|;
end_decl_stmt

begin_comment
comment|// The current value of the history unsigned unteger
end_comment

begin_comment
unit|};  }
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// lldb_History_h_
end_comment

end_unit

