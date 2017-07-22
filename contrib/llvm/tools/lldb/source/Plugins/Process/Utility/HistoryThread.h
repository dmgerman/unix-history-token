begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- HistoryThread.h -----------------------------------------*- C++ -*-===//
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
name|liblldb_HistoryThread_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_HistoryThread_h_
end_define

begin_comment
comment|// C Includes
end_comment

begin_comment
comment|// C++ Includes
end_comment

begin_include
include|#
directive|include
file|<mutex>
end_include

begin_comment
comment|// Other libraries and framework includes
end_comment

begin_comment
comment|// Project includes
end_comment

begin_include
include|#
directive|include
file|"lldb/Core/Broadcaster.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/Event.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/UserSettingsController.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/ExecutionContextScope.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/StackFrameList.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/Thread.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/UserID.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-private.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//----------------------------------------------------------------------
comment|/// @class HistoryThread HistoryThread.h "HistoryThread.h"
comment|/// @brief A thread object representing a backtrace from a previous point in the
comment|/// process execution
comment|///
comment|/// This subclass of Thread is used to provide a backtrace from earlier in
comment|/// process execution.  It is given a backtrace list of pc addresses and
comment|/// optionally a stop_id of when those pc addresses were collected, and it will
comment|/// create stack frames for them.
comment|//----------------------------------------------------------------------
name|class
name|HistoryThread
range|:
name|public
name|lldb_private
operator|::
name|Thread
block|{
name|public
operator|:
name|HistoryThread
argument_list|(
argument|lldb_private::Process&process
argument_list|,
argument|lldb::tid_t tid
argument_list|,
argument|std::vector<lldb::addr_t> pcs
argument_list|,
argument|uint32_t stop_id
argument_list|,
argument|bool stop_id_is_valid
argument_list|)
block|;
operator|~
name|HistoryThread
argument_list|()
name|override
block|;
name|lldb
operator|::
name|RegisterContextSP
name|GetRegisterContext
argument_list|()
name|override
block|;
name|lldb
operator|::
name|RegisterContextSP
name|CreateRegisterContextForFrame
argument_list|(
argument|StackFrame *frame
argument_list|)
name|override
block|;
name|void
name|RefreshStateAfterStop
argument_list|()
name|override
block|{}
name|bool
name|CalculateStopInfo
argument_list|()
name|override
block|{
return|return
name|false
return|;
block|}
name|void
name|SetExtendedBacktraceToken
argument_list|(
argument|uint64_t token
argument_list|)
name|override
block|{
name|m_extended_unwind_token
operator|=
name|token
block|;   }
name|uint64_t
name|GetExtendedBacktraceToken
argument_list|()
name|override
block|{
return|return
name|m_extended_unwind_token
return|;
block|}
specifier|const
name|char
operator|*
name|GetQueueName
argument_list|()
name|override
block|{
return|return
name|m_queue_name
operator|.
name|c_str
argument_list|()
return|;
block|}
name|void
name|SetQueueName
argument_list|(
argument|const char *name
argument_list|)
name|override
block|{
name|m_queue_name
operator|=
name|name
block|; }
name|lldb
operator|::
name|queue_id_t
name|GetQueueID
argument_list|()
name|override
block|{
return|return
name|m_queue_id
return|;
block|}
name|void
name|SetQueueID
argument_list|(
argument|lldb::queue_id_t queue
argument_list|)
name|override
block|{
name|m_queue_id
operator|=
name|queue
block|; }
specifier|const
name|char
operator|*
name|GetThreadName
argument_list|()
block|{
return|return
name|m_thread_name
operator|.
name|c_str
argument_list|()
return|;
block|}
name|uint32_t
name|GetExtendedBacktraceOriginatingIndexID
argument_list|()
name|override
block|;
name|void
name|SetThreadName
argument_list|(
argument|const char *name
argument_list|)
block|{
name|m_thread_name
operator|=
name|name
block|; }
specifier|const
name|char
operator|*
name|GetName
argument_list|()
name|override
block|{
return|return
name|m_thread_name
operator|.
name|c_str
argument_list|()
return|;
block|}
name|void
name|SetName
argument_list|(
argument|const char *name
argument_list|)
name|override
block|{
name|m_thread_name
operator|=
name|name
block|; }
name|protected
operator|:
name|virtual
name|lldb
operator|::
name|StackFrameListSP
name|GetStackFrameList
argument_list|()
block|;
name|mutable
name|std
operator|::
name|mutex
name|m_framelist_mutex
block|;
name|lldb
operator|::
name|StackFrameListSP
name|m_framelist
block|;
name|std
operator|::
name|vector
operator|<
name|lldb
operator|::
name|addr_t
operator|>
name|m_pcs
block|;
name|uint32_t
name|m_stop_id
block|;
name|bool
name|m_stop_id_is_valid
block|;
name|uint64_t
name|m_extended_unwind_token
block|;
name|std
operator|::
name|string
name|m_queue_name
block|;
name|std
operator|::
name|string
name|m_thread_name
block|;
name|lldb
operator|::
name|tid_t
name|m_originating_unique_thread_id
block|;
name|lldb
operator|::
name|queue_id_t
name|m_queue_id
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_HistoryThread_h_
end_comment

end_unit

