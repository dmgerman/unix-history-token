begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- QueueItem.h ---------------------------------------------*- C++ -*-===//
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
name|liblldb_QueueItem_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_QueueItem_h_
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
file|<memory>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<vector>
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
file|"lldb/lldb-enumerations.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-forward.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-private.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/Address.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/ConstString.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//------------------------------------------------------------------
comment|// QueueItem:
comment|// This class represents a work item enqueued on a libdispatch aka
comment|// Grand Central Dispatch (GCD) queue.  Most often, this will be a
comment|// function or block.
comment|// "enqueued" here means that the work item has been added to a queue
comment|// but it has not yet started executing.  When it is "dequeued",
comment|// execution of the item begins.
comment|//------------------------------------------------------------------
name|class
name|QueueItem
range|:
name|public
name|std
operator|::
name|enable_shared_from_this
operator|<
name|QueueItem
operator|>
block|{
name|public
operator|:
name|QueueItem
argument_list|(
argument|lldb::QueueSP queue_sp
argument_list|,
argument|lldb::ProcessSP process_sp
argument_list|,
argument|lldb::addr_t item_ref
argument_list|,
argument|lldb_private::Address address
argument_list|)
block|;
operator|~
name|QueueItem
argument_list|()
block|;
comment|//------------------------------------------------------------------
comment|/// Get the kind of work item this is
comment|///
comment|/// @return
comment|///     The type of work item that this QueueItem object
comment|///     represents.  eQueueItemKindUnknown may be returned.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|QueueItemKind
name|GetKind
argument_list|()
block|;
comment|//------------------------------------------------------------------
comment|/// Set the type of work item this is
comment|///
comment|/// @param [in] item_kind
comment|///     Set the kind of this work item object.
comment|//------------------------------------------------------------------
name|void
name|SetKind
argument_list|(
argument|lldb::QueueItemKind item_kind
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Get the code address that will be executed when this work item
comment|/// is executed.
comment|///
comment|/// @return
comment|///     The address that will be invoked when this work item is
comment|///     executed.  Not all types of QueueItems will have an
comment|///     address associated with them; check that the returned
comment|///     Address is valid, or check that the WorkItemKind is a
comment|///     kind that involves an address, such as eQueueItemKindFunction
comment|///     or eQueueItemKindBlock.
comment|//------------------------------------------------------------------
name|lldb_private
operator|::
name|Address
operator|&
name|GetAddress
argument_list|()
block|;
comment|//------------------------------------------------------------------
comment|/// Set the work item address for this object
comment|///
comment|/// @param [in] addr
comment|///     The address that will be invoked when this work item
comment|///     is executed.
comment|//------------------------------------------------------------------
name|void
name|SetAddress
argument_list|(
argument|lldb_private::Address addr
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Check if this QueueItem object is valid
comment|///
comment|/// If the weak pointer to the parent Queue cannot be revivified,
comment|/// it is invalid.
comment|///
comment|/// @return
comment|///     True if this object is valid.
comment|//------------------------------------------------------------------
name|bool
name|IsValid
argument_list|()
block|{
return|return
name|m_queue_wp
operator|.
name|lock
argument_list|()
operator|!=
name|nullptr
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Get an extended backtrace thread for this queue item, if available
comment|///
comment|/// If the backtrace/thread information was collected when this item
comment|/// was enqueued, this call will provide it.
comment|///
comment|/// @param [in] type
comment|///     The type of extended backtrace being requested, e.g. "libdispatch"
comment|///     or "pthread".
comment|///
comment|/// @return
comment|///     A thread shared pointer which will have a reference to an extended
comment|///     thread if one was available.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|ThreadSP
name|GetExtendedBacktraceThread
argument_list|(
argument|ConstString type
argument_list|)
block|;
name|void
name|SetItemThatEnqueuedThis
argument_list|(
argument|lldb::addr_t address_of_item
argument_list|)
block|{
name|m_item_that_enqueued_this_ref
operator|=
name|address_of_item
block|;   }
name|lldb
operator|::
name|addr_t
name|GetItemThatEnqueuedThis
argument_list|()
block|;
name|void
name|SetEnqueueingThreadID
argument_list|(
argument|lldb::tid_t tid
argument_list|)
block|{
name|m_enqueueing_thread_id
operator|=
name|tid
block|; }
name|lldb
operator|::
name|tid_t
name|GetEnqueueingThreadID
argument_list|()
block|;
name|void
name|SetEnqueueingQueueID
argument_list|(
argument|lldb::queue_id_t qid
argument_list|)
block|{
name|m_enqueueing_queue_id
operator|=
name|qid
block|;   }
name|lldb
operator|::
name|queue_id_t
name|GetEnqueueingQueueID
argument_list|()
block|;
name|void
name|SetTargetQueueID
argument_list|(
argument|lldb::queue_id_t qid
argument_list|)
block|{
name|m_target_queue_id
operator|=
name|qid
block|; }
name|void
name|SetStopID
argument_list|(
argument|uint32_t stop_id
argument_list|)
block|{
name|m_stop_id
operator|=
name|stop_id
block|; }
name|uint32_t
name|GetStopID
argument_list|()
block|;
name|void
name|SetEnqueueingBacktrace
argument_list|(
argument|std::vector<lldb::addr_t> backtrace
argument_list|)
block|{
name|m_backtrace
operator|=
name|backtrace
block|;   }
name|std
operator|::
name|vector
operator|<
name|lldb
operator|::
name|addr_t
operator|>
operator|&
name|GetEnqueueingBacktrace
argument_list|()
block|;
name|void
name|SetThreadLabel
argument_list|(
argument|std::string thread_name
argument_list|)
block|{
name|m_thread_label
operator|=
name|thread_name
block|; }
name|std
operator|::
name|string
name|GetThreadLabel
argument_list|()
block|;
name|void
name|SetQueueLabel
argument_list|(
argument|std::string queue_name
argument_list|)
block|{
name|m_queue_label
operator|=
name|queue_name
block|; }
name|std
operator|::
name|string
name|GetQueueLabel
argument_list|()
block|;
name|void
name|SetTargetQueueLabel
argument_list|(
argument|std::string queue_name
argument_list|)
block|{
name|m_target_queue_label
operator|=
name|queue_name
block|;   }
name|lldb
operator|::
name|ProcessSP
name|GetProcessSP
argument_list|()
block|;
name|protected
operator|:
name|void
name|FetchEntireItem
argument_list|()
block|;
name|lldb
operator|::
name|QueueWP
name|m_queue_wp
block|;
name|lldb
operator|::
name|ProcessWP
name|m_process_wp
block|;
name|lldb
operator|::
name|addr_t
name|m_item_ref
block|;
comment|// the token we can be used to fetch more information
comment|// about this queue item
name|lldb_private
operator|::
name|Address
name|m_address
block|;
name|bool
name|m_have_fetched_entire_item
block|;
name|lldb
operator|::
name|QueueItemKind
name|m_kind
block|;
name|lldb
operator|::
name|addr_t
name|m_item_that_enqueued_this_ref
block|;
comment|// a handle that we can pass into
comment|// libBacktraceRecording
comment|// to get the QueueItem that enqueued this item
name|lldb
operator|::
name|tid_t
name|m_enqueueing_thread_id
block|;
comment|// thread that enqueued this item
name|lldb
operator|::
name|queue_id_t
name|m_enqueueing_queue_id
block|;
comment|// Queue that enqueued this item, if it was a queue
name|lldb
operator|::
name|queue_id_t
name|m_target_queue_id
block|;
name|uint32_t
name|m_stop_id
block|;
comment|// indicates when this backtrace was recorded in time
name|std
operator|::
name|vector
operator|<
name|lldb
operator|::
name|addr_t
operator|>
name|m_backtrace
block|;
name|std
operator|::
name|string
name|m_thread_label
block|;
name|std
operator|::
name|string
name|m_queue_label
block|;
name|std
operator|::
name|string
name|m_target_queue_label
block|;
name|private
operator|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|QueueItem
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
comment|// liblldb_QueueItem_h_
end_comment

end_unit

