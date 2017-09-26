begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- QueueList.h --------------------------------------------*- C++ -*-===//
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
name|liblldb_QueueList_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_QueueList_h_
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
comment|//------------------------------------------------------------------
comment|// QueueList:
comment|// This is the container for libdispatch aka Grand Central Dispatch
comment|// Queue objects.
comment|//
comment|// Each Process will have a QueueList.  When the process execution is
comment|// paused, the QueueList may be populated with Queues by the
comment|// SystemRuntime.
comment|//------------------------------------------------------------------
name|class
name|QueueList
block|{
name|friend
name|class
name|Process
decl_stmt|;
name|public
label|:
name|QueueList
argument_list|(
name|Process
operator|*
name|process
argument_list|)
expr_stmt|;
operator|~
name|QueueList
argument_list|()
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Get the number of libdispatch queues that are available
comment|///
comment|/// @return
comment|///     The number of queues that are stored in the QueueList.
comment|//------------------------------------------------------------------
name|uint32_t
name|GetSize
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Get the Queue at a given index number
comment|///
comment|/// @param [in] idx
comment|///     The index number (0-based) of the queue.
comment|/// @return
comment|///     The Queue at that index number.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|QueueSP
name|GetQueueAtIndex
argument_list|(
argument|uint32_t idx
argument_list|)
expr_stmt|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|lldb
operator|::
name|QueueSP
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
name|QueueSP
operator|,
name|vector_adapter
operator|,
name|std
operator|::
name|mutex
operator|>
name|QueueIterable
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Iterate over the list of queues
comment|///
comment|/// @return
comment|///     An Iterable object which can be used to loop over the queues
comment|///     that exist.
comment|//------------------------------------------------------------------
name|QueueIterable
name|Queues
parameter_list|()
block|{
return|return
name|QueueIterable
argument_list|(
name|m_queues
argument_list|,
name|m_mutex
argument_list|)
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Clear out the list of queues from the QueueList
comment|//------------------------------------------------------------------
name|void
name|Clear
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Add a Queue to the QueueList
comment|///
comment|/// @param [in] queue
comment|///     Used by the SystemRuntime to populate the QueueList
comment|//------------------------------------------------------------------
name|void
name|AddQueue
argument_list|(
name|lldb
operator|::
name|QueueSP
name|queue
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Find a queue in the QueueList by QueueID
comment|///
comment|/// @param [in] qid
comment|///     The QueueID (same as returned by Thread::GetQueueID()) to find.
comment|///
comment|/// @return
comment|///     A QueueSP to the queue requested, if it is present in the QueueList.
comment|///     An empty QueueSP will be returned if this queue was not found.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|QueueSP
name|FindQueueByID
argument_list|(
argument|lldb::queue_id_t qid
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Find a queue in the QueueList by IndexID
comment|///
comment|/// @param [in] index_id
comment|///     Find a queue by IndexID.  This is an integer associated with each
comment|///     unique queue seen during a debug session and will not be reused
comment|///     for a different queue.  Unlike the QueueID, a 64-bit value, this
comment|///     will tend to be an integral value like 1 or 7.
comment|///
comment|/// @return
comment|///     A QueueSP to the queue requested, if it is present in the QueueList.
comment|///     An empty QueueSP will be returned if this queue was not found.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|QueueSP
name|FindQueueByIndexID
argument_list|(
argument|uint32_t index_id
argument_list|)
expr_stmt|;
name|std
operator|::
name|mutex
operator|&
name|GetMutex
argument_list|()
expr_stmt|;
name|protected
label|:
comment|//------------------------------------------------------------------
comment|// Classes that inherit from Process can see and modify these
comment|//------------------------------------------------------------------
name|Process
modifier|*
name|m_process
decl_stmt|;
comment|///< The process that manages this queue list.
name|uint32_t
name|m_stop_id
decl_stmt|;
comment|///< The process stop ID that this queue list is valid for.
name|collection
name|m_queues
decl_stmt|;
comment|///< The queues for this process.
name|std
operator|::
name|mutex
name|m_mutex
expr_stmt|;
name|private
label|:
name|QueueList
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
comment|// liblldb_QueueList_h_
end_comment

end_unit

