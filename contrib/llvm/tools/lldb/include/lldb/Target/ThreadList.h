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
file|<vector>
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-private.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/UserID.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/Iterable.h"
end_include

begin_comment
comment|// FIXME: Currently this is a thread list with lots of functionality for use only by
end_comment

begin_comment
comment|// the process for which this is the thread list.  If we ever want a container class
end_comment

begin_comment
comment|// to hand out that is just a random subset of threads, with iterator functionality,
end_comment

begin_comment
comment|// then we should make that part a base class, and make a ProcessThreadList for the
end_comment

begin_comment
comment|// process.
end_comment

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|ThreadList
block|{
name|friend
name|class
name|Process
decl_stmt|;
name|public
label|:
name|ThreadList
argument_list|(
name|Process
operator|*
name|process
argument_list|)
expr_stmt|;
name|ThreadList
argument_list|(
specifier|const
name|ThreadList
operator|&
name|rhs
argument_list|)
expr_stmt|;
operator|~
name|ThreadList
argument_list|()
expr_stmt|;
specifier|const
name|ThreadList
modifier|&
name|operator
init|=
operator|(
specifier|const
name|ThreadList
operator|&
name|rhs
operator|)
decl_stmt|;
name|uint32_t
name|GetSize
parameter_list|(
name|bool
name|can_update
init|=
name|true
parameter_list|)
function_decl|;
name|void
name|AddThread
argument_list|(
specifier|const
name|lldb
operator|::
name|ThreadSP
operator|&
name|thread_sp
argument_list|)
decl_stmt|;
name|void
name|InsertThread
argument_list|(
specifier|const
name|lldb
operator|::
name|ThreadSP
operator|&
name|thread_sp
argument_list|,
name|uint32_t
name|idx
argument_list|)
decl_stmt|;
comment|// Return the selected thread if there is one.  Otherwise, return the thread
comment|// selected at index 0.
name|lldb
operator|::
name|ThreadSP
name|GetSelectedThread
argument_list|()
expr_stmt|;
name|bool
name|SetSelectedThreadByID
argument_list|(
name|lldb
operator|::
name|tid_t
name|tid
argument_list|,
name|bool
name|notify
operator|=
name|false
argument_list|)
decl_stmt|;
name|bool
name|SetSelectedThreadByIndexID
parameter_list|(
name|uint32_t
name|index_id
parameter_list|,
name|bool
name|notify
init|=
name|false
parameter_list|)
function_decl|;
name|void
name|Clear
parameter_list|()
function_decl|;
name|void
name|Flush
parameter_list|()
function_decl|;
name|void
name|Destroy
parameter_list|()
function_decl|;
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
expr_stmt|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|lldb
operator|::
name|ThreadSP
operator|>
name|collection
expr_stmt|;
typedef|typedef
name|LockingAdaptedIterable
operator|<
name|collection
operator|,
name|lldb
operator|::
name|ThreadSP
operator|,
name|vector_adapter
operator|>
name|ThreadIterable
expr_stmt|;
name|ThreadIterable
name|Threads
parameter_list|()
block|{
return|return
name|ThreadIterable
argument_list|(
name|m_threads
argument_list|,
name|GetMutex
argument_list|()
argument_list|)
return|;
block|}
name|lldb
operator|::
name|ThreadSP
name|FindThreadByID
argument_list|(
argument|lldb::tid_t tid
argument_list|,
argument|bool can_update = true
argument_list|)
expr_stmt|;
name|lldb
operator|::
name|ThreadSP
name|FindThreadByProtocolID
argument_list|(
argument|lldb::tid_t tid
argument_list|,
argument|bool can_update = true
argument_list|)
expr_stmt|;
name|lldb
operator|::
name|ThreadSP
name|RemoveThreadByID
argument_list|(
argument|lldb::tid_t tid
argument_list|,
argument|bool can_update = true
argument_list|)
expr_stmt|;
name|lldb
operator|::
name|ThreadSP
name|RemoveThreadByProtocolID
argument_list|(
argument|lldb::tid_t tid
argument_list|,
argument|bool can_update = true
argument_list|)
expr_stmt|;
name|lldb
operator|::
name|ThreadSP
name|FindThreadByIndexID
argument_list|(
argument|uint32_t index_id
argument_list|,
argument|bool can_update = true
argument_list|)
expr_stmt|;
name|lldb
operator|::
name|ThreadSP
name|GetThreadSPForThreadPtr
argument_list|(
name|Thread
operator|*
name|thread_ptr
argument_list|)
expr_stmt|;
name|bool
name|ShouldStop
parameter_list|(
name|Event
modifier|*
name|event_ptr
parameter_list|)
function_decl|;
name|Vote
name|ShouldReportStop
parameter_list|(
name|Event
modifier|*
name|event_ptr
parameter_list|)
function_decl|;
name|Vote
name|ShouldReportRun
parameter_list|(
name|Event
modifier|*
name|event_ptr
parameter_list|)
function_decl|;
name|void
name|RefreshStateAfterStop
parameter_list|()
function_decl|;
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
parameter_list|()
function_decl|;
name|void
name|DidResume
parameter_list|()
function_decl|;
name|void
name|DidStop
parameter_list|()
function_decl|;
name|void
name|DiscardThreadPlans
parameter_list|()
function_decl|;
name|uint32_t
name|GetStopID
argument_list|()
specifier|const
expr_stmt|;
name|void
name|SetStopID
parameter_list|(
name|uint32_t
name|stop_id
parameter_list|)
function_decl|;
name|Mutex
modifier|&
name|GetMutex
parameter_list|()
function_decl|;
name|void
name|Update
parameter_list|(
name|ThreadList
modifier|&
name|rhs
parameter_list|)
function_decl|;
name|protected
label|:
name|void
name|SetShouldReportStop
parameter_list|(
name|Vote
name|vote
parameter_list|)
function_decl|;
name|void
name|NotifySelectedThreadChanged
argument_list|(
name|lldb
operator|::
name|tid_t
name|tid
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|// Classes that inherit from Process can see and modify these
comment|//------------------------------------------------------------------
name|Process
modifier|*
name|m_process
decl_stmt|;
comment|///< The process that manages this thread list.
name|uint32_t
name|m_stop_id
decl_stmt|;
comment|///< The process stop ID that this thread list is valid for.
name|collection
name|m_threads
decl_stmt|;
comment|///< The threads for this process.
name|lldb
operator|::
name|tid_t
name|m_selected_tid
expr_stmt|;
comment|///< For targets that need the notion of a current thread.
name|private
label|:
name|ThreadList
argument_list|()
expr_stmt|;
block|}
empty_stmt|;
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

