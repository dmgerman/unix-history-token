begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SystemRuntimeMacOSX.h -----------------------------------*- C++ -*-===//
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
name|liblldb_SystemRuntimeMacOSX_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_SystemRuntimeMacOSX_h_
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
comment|// Other libraries and framework include
end_comment

begin_comment
comment|// Project includes
end_comment

begin_include
include|#
directive|include
file|"lldb/Core/ModuleList.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/Process.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/QueueItem.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/SystemRuntime.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/ConstString.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/FileSpec.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/StructuredData.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/UUID.h"
end_include

begin_include
include|#
directive|include
file|"AppleGetItemInfoHandler.h"
end_include

begin_include
include|#
directive|include
file|"AppleGetPendingItemsHandler.h"
end_include

begin_include
include|#
directive|include
file|"AppleGetQueuesHandler.h"
end_include

begin_include
include|#
directive|include
file|"AppleGetThreadItemInfoHandler.h"
end_include

begin_decl_stmt
name|class
name|SystemRuntimeMacOSX
range|:
name|public
name|lldb_private
operator|::
name|SystemRuntime
block|{
name|public
operator|:
name|SystemRuntimeMacOSX
argument_list|(
name|lldb_private
operator|::
name|Process
operator|*
name|process
argument_list|)
block|;
operator|~
name|SystemRuntimeMacOSX
argument_list|()
name|override
block|;
comment|//------------------------------------------------------------------
comment|// Static Functions
comment|//------------------------------------------------------------------
specifier|static
name|void
name|Initialize
argument_list|()
block|;
specifier|static
name|void
name|Terminate
argument_list|()
block|;
specifier|static
name|lldb_private
operator|::
name|ConstString
name|GetPluginNameStatic
argument_list|()
block|;
specifier|static
specifier|const
name|char
operator|*
name|GetPluginDescriptionStatic
argument_list|()
block|;
specifier|static
name|lldb_private
operator|::
name|SystemRuntime
operator|*
name|CreateInstance
argument_list|(
name|lldb_private
operator|::
name|Process
operator|*
name|process
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|// instance methods
comment|//------------------------------------------------------------------
name|void
name|Clear
argument_list|(
argument|bool clear_process
argument_list|)
block|;
name|void
name|Detach
argument_list|()
name|override
block|;
specifier|const
name|std
operator|::
name|vector
operator|<
name|lldb_private
operator|::
name|ConstString
operator|>
operator|&
name|GetExtendedBacktraceTypes
argument_list|()
name|override
block|;
name|lldb
operator|::
name|ThreadSP
name|GetExtendedBacktraceThread
argument_list|(
argument|lldb::ThreadSP thread
argument_list|,
argument|lldb_private::ConstString type
argument_list|)
name|override
block|;
name|lldb
operator|::
name|ThreadSP
name|GetExtendedBacktraceForQueueItem
argument_list|(
argument|lldb::QueueItemSP queue_item_sp
argument_list|,
argument|lldb_private::ConstString type
argument_list|)
name|override
block|;
name|lldb
operator|::
name|ThreadSP
name|GetExtendedBacktraceFromItemRef
argument_list|(
argument|lldb::addr_t item_ref
argument_list|)
block|;
name|void
name|PopulateQueueList
argument_list|(
argument|lldb_private::QueueList&queue_list
argument_list|)
name|override
block|;
name|void
name|PopulateQueuesUsingLibBTR
argument_list|(
argument|lldb::addr_t queues_buffer
argument_list|,
argument|uint64_t queues_buffer_size
argument_list|,
argument|uint64_t count
argument_list|,
argument|lldb_private::QueueList&queue_list
argument_list|)
block|;
name|void
name|PopulatePendingQueuesUsingLibBTR
argument_list|(
argument|lldb::addr_t items_buffer
argument_list|,
argument|uint64_t items_buffer_size
argument_list|,
argument|uint64_t count
argument_list|,
argument|lldb_private::Queue *queue
argument_list|)
block|;
name|std
operator|::
name|string
name|GetQueueNameFromThreadQAddress
argument_list|(
argument|lldb::addr_t dispatch_qaddr
argument_list|)
name|override
block|;
name|lldb
operator|::
name|queue_id_t
name|GetQueueIDFromThreadQAddress
argument_list|(
argument|lldb::addr_t dispatch_qaddr
argument_list|)
name|override
block|;
name|lldb
operator|::
name|addr_t
name|GetLibdispatchQueueAddressFromThreadQAddress
argument_list|(
argument|lldb::addr_t dispatch_qaddr
argument_list|)
name|override
block|;
name|void
name|PopulatePendingItemsForQueue
argument_list|(
argument|lldb_private::Queue *queue
argument_list|)
name|override
block|;
name|void
name|CompleteQueueItem
argument_list|(
argument|lldb_private::QueueItem *queue_item
argument_list|,
argument|lldb::addr_t item_ref
argument_list|)
name|override
block|;
name|lldb
operator|::
name|QueueKind
name|GetQueueKind
argument_list|(
argument|lldb::addr_t dispatch_queue_addr
argument_list|)
name|override
block|;
name|void
name|AddThreadExtendedInfoPacketHints
argument_list|(
argument|lldb_private::StructuredData::ObjectSP dict
argument_list|)
name|override
block|;
name|bool
name|SafeToCallFunctionsOnThisThread
argument_list|(
argument|lldb::ThreadSP thread_sp
argument_list|)
name|override
block|;
comment|//------------------------------------------------------------------
comment|// PluginInterface protocol
comment|//------------------------------------------------------------------
name|lldb_private
operator|::
name|ConstString
name|GetPluginName
argument_list|()
name|override
block|;
name|uint32_t
name|GetPluginVersion
argument_list|()
name|override
block|;
name|protected
operator|:
name|lldb
operator|::
name|user_id_t
name|m_break_id
block|;
name|mutable
name|std
operator|::
name|recursive_mutex
name|m_mutex
block|;
name|private
operator|:
expr|struct
name|libBacktraceRecording_info
block|{
name|uint16_t
name|queue_info_version
block|;
name|uint16_t
name|queue_info_data_offset
block|;
name|uint16_t
name|item_info_version
block|;
name|uint16_t
name|item_info_data_offset
block|;
name|libBacktraceRecording_info
argument_list|()
operator|:
name|queue_info_version
argument_list|(
literal|0
argument_list|)
block|,
name|queue_info_data_offset
argument_list|(
literal|0
argument_list|)
block|,
name|item_info_version
argument_list|(
literal|0
argument_list|)
block|,
name|item_info_data_offset
argument_list|(
literal|0
argument_list|)
block|{}
block|}
block|;
comment|// A structure which reflects the data recorded in the
comment|// libBacktraceRecording introspection_dispatch_item_info_s.
block|struct
name|ItemInfo
block|{
name|lldb
operator|::
name|addr_t
name|item_that_enqueued_this
block|;
name|lldb
operator|::
name|addr_t
name|function_or_block
block|;
name|uint64_t
name|enqueuing_thread_id
block|;
name|uint64_t
name|enqueuing_queue_serialnum
block|;
name|uint64_t
name|target_queue_serialnum
block|;
name|uint32_t
name|enqueuing_callstack_frame_count
block|;
name|uint32_t
name|stop_id
block|;
name|std
operator|::
name|vector
operator|<
name|lldb
operator|::
name|addr_t
operator|>
name|enqueuing_callstack
block|;
name|std
operator|::
name|string
name|enqueuing_thread_label
block|;
name|std
operator|::
name|string
name|enqueuing_queue_label
block|;
name|std
operator|::
name|string
name|target_queue_label
block|;   }
block|;
comment|// The offsets of different fields of the dispatch_queue_t structure in
comment|// a thread/queue process.
comment|// Based on libdispatch src/queue_private.h, struct dispatch_queue_offsets_s
comment|// With dqo_version 1-3, the dqo_label field is a per-queue value and cannot
comment|// be cached.
comment|// With dqo_version 4 (Mac OS X 10.9 / iOS 7), dqo_label is a constant value
comment|// that can be cached.
block|struct
name|LibdispatchOffsets
block|{
name|uint16_t
name|dqo_version
block|;
name|uint16_t
name|dqo_label
block|;
name|uint16_t
name|dqo_label_size
block|;
name|uint16_t
name|dqo_flags
block|;
name|uint16_t
name|dqo_flags_size
block|;
name|uint16_t
name|dqo_serialnum
block|;
name|uint16_t
name|dqo_serialnum_size
block|;
name|uint16_t
name|dqo_width
block|;
name|uint16_t
name|dqo_width_size
block|;
name|uint16_t
name|dqo_running
block|;
name|uint16_t
name|dqo_running_size
block|;
name|uint16_t
name|dqo_suspend_cnt
block|;
comment|// version 5 and later, starting with Mac OS X
comment|// 10.10/iOS 8
name|uint16_t
name|dqo_suspend_cnt_size
block|;
comment|// version 5 and later, starting with Mac OS
comment|// X 10.10/iOS 8
name|uint16_t
name|dqo_target_queue
block|;
comment|// version 5 and later, starting with Mac OS X
comment|// 10.10/iOS 8
name|uint16_t
name|dqo_target_queue_size
block|;
comment|// version 5 and later, starting with Mac OS
comment|// X 10.10/iOS 8
name|uint16_t
name|dqo_priority
block|;
comment|// version 5 and later, starting with Mac OS X 10.10/iOS 8
name|uint16_t
name|dqo_priority_size
block|;
comment|// version 5 and later, starting with Mac OS X
comment|// 10.10/iOS 8
name|LibdispatchOffsets
argument_list|()
block|{
name|dqo_version
operator|=
name|UINT16_MAX
block|;
name|dqo_flags
operator|=
name|UINT16_MAX
block|;
name|dqo_serialnum
operator|=
name|UINT16_MAX
block|;
name|dqo_label
operator|=
name|UINT16_MAX
block|;
name|dqo_width
operator|=
name|UINT16_MAX
block|;
name|dqo_running
operator|=
name|UINT16_MAX
block|;
name|dqo_suspend_cnt
operator|=
name|UINT16_MAX
block|;
name|dqo_target_queue
operator|=
name|UINT16_MAX
block|;
name|dqo_target_queue
operator|=
name|UINT16_MAX
block|;
name|dqo_priority
operator|=
name|UINT16_MAX
block|;     }
name|bool
name|IsValid
argument_list|()
block|{
return|return
name|dqo_version
operator|!=
name|UINT16_MAX
return|;
block|}
name|bool
name|LabelIsValid
argument_list|()
block|{
return|return
name|dqo_label
operator|!=
name|UINT16_MAX
return|;
block|}
expr|}
block|;    struct
name|LibdispatchVoucherOffsets
block|{
name|uint16_t
name|vo_version
block|;
name|uint16_t
name|vo_activity_ids_count
block|;
name|uint16_t
name|vo_activity_ids_count_size
block|;
name|uint16_t
name|vo_activity_ids_array
block|;
name|uint16_t
name|vo_activity_ids_array_entry_size
block|;
name|LibdispatchVoucherOffsets
argument_list|()
operator|:
name|vo_version
argument_list|(
name|UINT16_MAX
argument_list|)
block|,
name|vo_activity_ids_count
argument_list|(
name|UINT16_MAX
argument_list|)
block|,
name|vo_activity_ids_count_size
argument_list|(
name|UINT16_MAX
argument_list|)
block|,
name|vo_activity_ids_array
argument_list|(
name|UINT16_MAX
argument_list|)
block|,
name|vo_activity_ids_array_entry_size
argument_list|(
argument|UINT16_MAX
argument_list|)
block|{}
name|bool
name|IsValid
argument_list|()
block|{
return|return
name|vo_version
operator|!=
name|UINT16_MAX
return|;
block|}
expr|}
block|;    struct
name|LibdispatchTSDIndexes
block|{
name|uint16_t
name|dti_version
block|;
name|uint64_t
name|dti_queue_index
block|;
name|uint64_t
name|dti_voucher_index
block|;
name|uint64_t
name|dti_qos_class_index
block|;
name|LibdispatchTSDIndexes
argument_list|()
operator|:
name|dti_version
argument_list|(
name|UINT16_MAX
argument_list|)
block|,
name|dti_queue_index
argument_list|(
name|UINT64_MAX
argument_list|)
block|,
name|dti_voucher_index
argument_list|(
name|UINT64_MAX
argument_list|)
block|,
name|dti_qos_class_index
argument_list|(
argument|UINT64_MAX
argument_list|)
block|{}
name|bool
name|IsValid
argument_list|()
block|{
return|return
name|dti_version
operator|!=
name|UINT16_MAX
return|;
block|}
expr|}
block|;    struct
name|LibpthreadOffsets
block|{
name|uint16_t
name|plo_version
block|;
name|uint16_t
name|plo_pthread_tsd_base_offset
block|;
name|uint16_t
name|plo_pthread_tsd_base_address_offset
block|;
name|uint16_t
name|plo_pthread_tsd_entry_size
block|;
name|LibpthreadOffsets
argument_list|()
operator|:
name|plo_version
argument_list|(
name|UINT16_MAX
argument_list|)
block|,
name|plo_pthread_tsd_base_offset
argument_list|(
name|UINT16_MAX
argument_list|)
block|,
name|plo_pthread_tsd_base_address_offset
argument_list|(
name|UINT16_MAX
argument_list|)
block|,
name|plo_pthread_tsd_entry_size
argument_list|(
argument|UINT16_MAX
argument_list|)
block|{}
name|bool
name|IsValid
argument_list|()
block|{
return|return
name|plo_version
operator|!=
name|UINT16_MAX
return|;
block|}
expr|}
block|;
comment|// The libBacktraceRecording function
comment|// __introspection_dispatch_queue_get_pending_items has
comment|// two forms.  It can either return a simple array of item_refs (void *) size
comment|// or it can return
comment|// a header with uint32_t version, a uint32_t size of item, and then an array
comment|// of item_refs (void*)
comment|// and code addresses (void*) for all the pending blocks.
block|struct
name|ItemRefAndCodeAddress
block|{
name|lldb
operator|::
name|addr_t
name|item_ref
block|;
name|lldb
operator|::
name|addr_t
name|code_address
block|;   }
block|;    struct
name|PendingItemsForQueue
block|{
name|bool
name|new_style
block|;
comment|// new-style means both item_refs and code_addresses avail
comment|// old-style means only item_refs is filled in
name|std
operator|::
name|vector
operator|<
name|ItemRefAndCodeAddress
operator|>
name|item_refs_and_code_addresses
block|;   }
block|;
name|bool
name|BacktraceRecordingHeadersInitialized
argument_list|()
block|;
name|void
name|ReadLibdispatchOffsetsAddress
argument_list|()
block|;
name|void
name|ReadLibdispatchOffsets
argument_list|()
block|;
name|void
name|ReadLibpthreadOffsetsAddress
argument_list|()
block|;
name|void
name|ReadLibpthreadOffsets
argument_list|()
block|;
name|void
name|ReadLibdispatchTSDIndexesAddress
argument_list|()
block|;
name|void
name|ReadLibdispatchTSDIndexes
argument_list|()
block|;
name|PendingItemsForQueue
name|GetPendingItemRefsForQueue
argument_list|(
argument|lldb::addr_t queue
argument_list|)
block|;
name|ItemInfo
name|ExtractItemInfoFromBuffer
argument_list|(
name|lldb_private
operator|::
name|DataExtractor
operator|&
name|extractor
argument_list|)
block|;
name|lldb_private
operator|::
name|AppleGetQueuesHandler
name|m_get_queues_handler
block|;
name|lldb_private
operator|::
name|AppleGetPendingItemsHandler
name|m_get_pending_items_handler
block|;
name|lldb_private
operator|::
name|AppleGetItemInfoHandler
name|m_get_item_info_handler
block|;
name|lldb_private
operator|::
name|AppleGetThreadItemInfoHandler
name|m_get_thread_item_info_handler
block|;
name|lldb
operator|::
name|addr_t
name|m_page_to_free
block|;
name|uint64_t
name|m_page_to_free_size
block|;
name|libBacktraceRecording_info
name|m_lib_backtrace_recording_info
block|;
name|lldb
operator|::
name|addr_t
name|m_dispatch_queue_offsets_addr
block|;   struct
name|LibdispatchOffsets
name|m_libdispatch_offsets
block|;
name|lldb
operator|::
name|addr_t
name|m_libpthread_layout_offsets_addr
block|;   struct
name|LibpthreadOffsets
name|m_libpthread_offsets
block|;
name|lldb
operator|::
name|addr_t
name|m_dispatch_tsd_indexes_addr
block|;   struct
name|LibdispatchTSDIndexes
name|m_libdispatch_tsd_indexes
block|;
name|lldb
operator|::
name|addr_t
name|m_dispatch_voucher_offsets_addr
block|;   struct
name|LibdispatchVoucherOffsets
name|m_libdispatch_voucher_offsets
block|;
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|SystemRuntimeMacOSX
argument_list|)
block|; }
block|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_SystemRuntimeMacOSX_h_
end_comment

end_unit

