begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ThreadList.h --------------------------------------------*- C++ -*-===//
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
name|liblldb_ThreadList_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ThreadList_h_
end_define

begin_include
include|#
directive|include
file|<mutex>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_include
include|#
directive|include
file|"lldb/Target/Thread.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/ThreadCollection.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/Iterable.h"
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
comment|// This is a thread list with lots of functionality for use only by the process
comment|// for which this is the thread list.  A generic container class with iterator
comment|// functionality is ThreadCollection.
name|class
name|ThreadList
range|:
name|public
name|ThreadCollection
block|{
name|friend
name|class
name|Process
block|;
name|public
operator|:
name|ThreadList
argument_list|(
name|Process
operator|*
name|process
argument_list|)
block|;
name|ThreadList
argument_list|(
specifier|const
name|ThreadList
operator|&
name|rhs
argument_list|)
block|;
operator|~
name|ThreadList
argument_list|()
name|override
block|;
specifier|const
name|ThreadList
operator|&
name|operator
operator|=
operator|(
specifier|const
name|ThreadList
operator|&
name|rhs
operator|)
block|;
name|uint32_t
name|GetSize
argument_list|(
argument|bool can_update = true
argument_list|)
block|;
comment|// Return the selected thread if there is one.  Otherwise, return the thread
comment|// selected at index 0.
name|lldb
operator|::
name|ThreadSP
name|GetSelectedThread
argument_list|()
block|;
comment|// Manage the thread to use for running expressions.  This is usually the
comment|// Selected thread,
comment|// but sometimes (e.g. when evaluating breakpoint conditions& stop hooks) it
comment|// isn't.
name|class
name|ExpressionExecutionThreadPusher
block|{
name|public
operator|:
name|ExpressionExecutionThreadPusher
argument_list|(
argument|ThreadList&thread_list
argument_list|,
argument|lldb::tid_t tid
argument_list|)
operator|:
name|m_thread_list
argument_list|(
operator|&
name|thread_list
argument_list|)
block|,
name|m_tid
argument_list|(
argument|tid
argument_list|)
block|{
name|m_thread_list
operator|->
name|PushExpressionExecutionThread
argument_list|(
name|m_tid
argument_list|)
block|;     }
name|ExpressionExecutionThreadPusher
argument_list|(
argument|lldb::ThreadSP thread_sp
argument_list|)
block|;
operator|~
name|ExpressionExecutionThreadPusher
argument_list|()
block|{
if|if
condition|(
name|m_thread_list
operator|&&
name|m_tid
operator|!=
name|LLDB_INVALID_THREAD_ID
condition|)
name|m_thread_list
operator|->
name|PopExpressionExecutionThread
argument_list|(
name|m_tid
argument_list|)
expr_stmt|;
block|}
name|private
operator|:
name|ThreadList
operator|*
name|m_thread_list
block|;
name|lldb
operator|::
name|tid_t
name|m_tid
block|;   }
block|;
name|lldb
operator|::
name|ThreadSP
name|GetExpressionExecutionThread
argument_list|()
block|;
name|protected
operator|:
name|void
name|PushExpressionExecutionThread
argument_list|(
argument|lldb::tid_t tid
argument_list|)
block|;
name|void
name|PopExpressionExecutionThread
argument_list|(
argument|lldb::tid_t tid
argument_list|)
block|;
name|public
operator|:
name|bool
name|SetSelectedThreadByID
argument_list|(
argument|lldb::tid_t tid
argument_list|,
argument|bool notify = false
argument_list|)
block|;
name|bool
name|SetSelectedThreadByIndexID
argument_list|(
argument|uint32_t index_id
argument_list|,
argument|bool notify = false
argument_list|)
block|;
name|void
name|Clear
argument_list|()
block|;
name|void
name|Flush
argument_list|()
block|;
name|void
name|Destroy
argument_list|()
block|;
comment|// Note that "idx" is not the same as the "thread_index". It is a zero
comment|// based index to accessing the current threads, whereas "thread_index"
comment|// is a unique index assigned
name|lldb
operator|::
name|ThreadSP
name|GetThreadAtIndex
argument_list|(
argument|uint32_t idx
argument_list|,
argument|bool can_update = true
argument_list|)
block|;
name|lldb
operator|::
name|ThreadSP
name|FindThreadByID
argument_list|(
argument|lldb::tid_t tid
argument_list|,
argument|bool can_update = true
argument_list|)
block|;
name|lldb
operator|::
name|ThreadSP
name|FindThreadByProtocolID
argument_list|(
argument|lldb::tid_t tid
argument_list|,
argument|bool can_update = true
argument_list|)
block|;
name|lldb
operator|::
name|ThreadSP
name|RemoveThreadByID
argument_list|(
argument|lldb::tid_t tid
argument_list|,
argument|bool can_update = true
argument_list|)
block|;
name|lldb
operator|::
name|ThreadSP
name|RemoveThreadByProtocolID
argument_list|(
argument|lldb::tid_t tid
argument_list|,
argument|bool can_update = true
argument_list|)
block|;
name|lldb
operator|::
name|ThreadSP
name|FindThreadByIndexID
argument_list|(
argument|uint32_t index_id
argument_list|,
argument|bool can_update = true
argument_list|)
block|;
name|lldb
operator|::
name|ThreadSP
name|GetThreadSPForThreadPtr
argument_list|(
name|Thread
operator|*
name|thread_ptr
argument_list|)
block|;
name|bool
name|ShouldStop
argument_list|(
name|Event
operator|*
name|event_ptr
argument_list|)
block|;
name|Vote
name|ShouldReportStop
argument_list|(
name|Event
operator|*
name|event_ptr
argument_list|)
block|;
name|Vote
name|ShouldReportRun
argument_list|(
name|Event
operator|*
name|event_ptr
argument_list|)
block|;
name|void
name|RefreshStateAfterStop
argument_list|()
block|;
comment|//------------------------------------------------------------------
comment|/// The thread list asks tells all the threads it is about to resume.
comment|/// If a thread can "resume" without having to resume the target, it
comment|/// will return false for WillResume, and then the process will not be
comment|/// restarted.
comment|///
comment|/// @return
comment|///    \b true instructs the process to resume normally,
comment|///    \b false means start& stopped events will be generated, but
comment|///    the process will not actually run.  The thread must then return
comment|///    the correct StopInfo when asked.
comment|///
comment|//------------------------------------------------------------------
name|bool
name|WillResume
argument_list|()
block|;
name|void
name|DidResume
argument_list|()
block|;
name|void
name|DidStop
argument_list|()
block|;
name|void
name|DiscardThreadPlans
argument_list|()
block|;
name|uint32_t
name|GetStopID
argument_list|()
specifier|const
block|;
name|void
name|SetStopID
argument_list|(
argument|uint32_t stop_id
argument_list|)
block|;
name|std
operator|::
name|recursive_mutex
operator|&
name|GetMutex
argument_list|()
specifier|const
name|override
block|;
name|void
name|Update
argument_list|(
name|ThreadList
operator|&
name|rhs
argument_list|)
block|;
name|protected
operator|:
name|void
name|SetShouldReportStop
argument_list|(
argument|Vote vote
argument_list|)
block|;
name|void
name|NotifySelectedThreadChanged
argument_list|(
argument|lldb::tid_t tid
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|// Classes that inherit from Process can see and modify these
comment|//------------------------------------------------------------------
name|Process
operator|*
name|m_process
block|;
comment|///< The process that manages this thread list.
name|uint32_t
name|m_stop_id
block|;
comment|///< The process stop ID that this thread list is valid for.
name|lldb
operator|::
name|tid_t
name|m_selected_tid
block|;
comment|///< For targets that need the notion of a current thread.
name|std
operator|::
name|vector
operator|<
name|lldb
operator|::
name|tid_t
operator|>
name|m_expression_tid_stack
block|;
name|private
operator|:
name|ThreadList
argument_list|()
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
comment|// liblldb_ThreadList_h_
end_comment

end_unit

