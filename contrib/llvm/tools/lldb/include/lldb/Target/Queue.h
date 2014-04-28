begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Queue.h ------------------------------------------------*- C++ -*-===//
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
name|liblldb_Queue_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_Queue_h_
end_define

begin_include
include|#
directive|include
file|<vector>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-forward.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-enumerations.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-private.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/QueueItem.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//------------------------------------------------------------------
comment|// Queue:
comment|// This class represents a libdispatch aka Grand Central Dispatch
comment|// queue in the process.
comment|//
comment|// A program using libdispatch will create queues, put work items
comment|// (functions, blocks) on the queues.  The system will create /
comment|// reassign pthreads to execute the work items for the queues.  A
comment|// serial queue will be associated with a single thread (or possibly
comment|// no thread, if it is not doing any work).  A concurrent queue may
comment|// be associated with multiple threads.
comment|//------------------------------------------------------------------
name|class
name|Queue
range|:
name|public
name|std
operator|::
name|enable_shared_from_this
operator|<
name|Queue
operator|>
block|{
name|public
operator|:
name|Queue
argument_list|(
argument|lldb::ProcessSP process_sp
argument_list|,
argument|lldb::queue_id_t queue_id
argument_list|,
argument|const char *queue_name
argument_list|)
block|;
operator|~
name|Queue
argument_list|()
block|;
comment|//------------------------------------------------------------------
comment|/// Get the QueueID for this Queue
comment|///
comment|/// A 64-bit ID number that uniquely identifies a queue at this particular
comment|/// stop_id.  Currently the libdispatch serialnum is used for the QueueID;
comment|/// it is a number that starts at 1 for each process and increments with
comment|/// each queue.  A serialnum is not reused for a different queue in the
comment|/// lifetime of that process execution.
comment|///
comment|/// @return
comment|///     The QueueID for this Queue.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|queue_id_t
name|GetID
argument_list|()
block|;
comment|//------------------------------------------------------------------
comment|/// Get the name of this Queue
comment|///
comment|/// @return
comment|///     The name of the queue, if one is available.
comment|///     A NULL pointer is returned if none is available.
comment|//------------------------------------------------------------------
specifier|const
name|char
operator|*
name|GetName
argument_list|()
block|;
comment|//------------------------------------------------------------------
comment|/// Get the IndexID for this Queue
comment|///
comment|/// This is currently the same as GetID().  If it changes in the future,
comment|/// it will be  a small integer value (starting with 1) assigned to
comment|/// each queue that is seen during a Process lifetime.
comment|///
comment|/// Both the GetID and GetIndexID are being retained for Queues to
comment|/// maintain similar API to the Thread class, and allow for the
comment|/// possibility of GetID changing to a different source in the future.
comment|///
comment|/// @return
comment|///     The IndexID for this queue.
comment|//------------------------------------------------------------------
name|uint32_t
name|GetIndexID
argument_list|()
block|;
comment|//------------------------------------------------------------------
comment|/// Return the threads currently associated with this queue
comment|///
comment|/// Zero, one, or many threads may be executing code for a queue at
comment|/// a given point in time.  This call returns the list of threads
comment|/// that are currently executing work for this queue.
comment|///
comment|/// @return
comment|///     The threads currently performing work for this queue
comment|//------------------------------------------------------------------
name|std
operator|::
name|vector
operator|<
name|lldb
operator|::
name|ThreadSP
operator|>
name|GetThreads
argument_list|()
block|;
comment|//------------------------------------------------------------------
comment|/// Return the items that are currently enqueued
comment|///
comment|/// "Enqueued" means that the item has been added to the queue to
comment|/// be done, but has not yet been done.  When the item is going to
comment|/// be processed it is "dequeued".
comment|///
comment|/// @return
comment|///     The vector of enqueued items for this queue
comment|//------------------------------------------------------------------
specifier|const
name|std
operator|::
name|vector
operator|<
name|lldb
operator|::
name|QueueItemSP
operator|>
operator|&
name|GetPendingItems
argument_list|()
block|;
name|lldb
operator|::
name|ProcessSP
name|GetProcess
argument_list|()
specifier|const
block|{
return|return
name|m_process_wp
operator|.
name|lock
argument_list|()
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Get the number of work items that this queue is currently running
comment|///
comment|/// @return
comment|///     The number of work items currently executing.  For a serial
comment|///     queue, this will be 0 or 1.  For a concurrent queue, this
comment|///     may be any number.
comment|//------------------------------------------------------------------
name|uint32_t
name|GetNumRunningWorkItems
argument_list|()
specifier|const
block|;
comment|//------------------------------------------------------------------
comment|/// Get the number of work items enqueued on this queue
comment|///
comment|/// @return
comment|///     The number of work items currently enqueued, waiting to
comment|///     execute.
comment|//------------------------------------------------------------------
name|uint32_t
name|GetNumPendingWorkItems
argument_list|()
specifier|const
block|;
comment|//------------------------------------------------------------------
comment|/// Get the dispatch_queue_t structure address for this Queue
comment|///
comment|/// Get the address in the inferior process' memory of this Queue's
comment|/// dispatch_queue_t structure.
comment|///
comment|/// @return
comment|///     The address of the dispatch_queue_t structure, if known.
comment|///     LLDB_INVALID_ADDRESS will be returned if it is unavailable.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|addr_t
name|GetLibdispatchQueueAddress
argument_list|()
specifier|const
block|;
name|void
name|SetNumRunningWorkItems
argument_list|(
argument|uint32_t count
argument_list|)
block|;
name|void
name|SetNumPendingWorkItems
argument_list|(
argument|uint32_t count
argument_list|)
block|;
name|void
name|SetLibdispatchQueueAddress
argument_list|(
argument|lldb::addr_t dispatch_queue_t_addr
argument_list|)
block|;
name|void
name|PushPendingQueueItem
argument_list|(
argument|lldb::QueueItemSP item
argument_list|)
block|{
name|m_pending_items
operator|.
name|push_back
argument_list|(
name|item
argument_list|)
block|;     }
name|private
operator|:
comment|//------------------------------------------------------------------
comment|// For Queue only
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|ProcessWP
name|m_process_wp
block|;
name|lldb
operator|::
name|queue_id_t
name|m_queue_id
block|;
name|std
operator|::
name|string
name|m_queue_name
block|;
name|uint32_t
name|m_running_work_items_count
block|;
name|uint32_t
name|m_pending_work_items_count
block|;
name|std
operator|::
name|vector
operator|<
name|lldb
operator|::
name|QueueItemSP
operator|>
name|m_pending_items
block|;
name|lldb
operator|::
name|addr_t
name|m_dispatch_queue_t_addr
block|;
comment|// address of libdispatch dispatch_queue_t for this Queue
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|Queue
argument_list|)
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
comment|// liblldb_Queue_h_
end_comment

end_unit

