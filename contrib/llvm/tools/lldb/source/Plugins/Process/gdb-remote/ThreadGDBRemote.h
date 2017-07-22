begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ThreadGDBRemote.h ---------------------------------------*- C++ -*-===//
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
name|liblldb_ThreadGDBRemote_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ThreadGDBRemote_h_
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
file|<string>
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
file|"lldb/Target/Process.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/Thread.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/StructuredData.h"
end_include

begin_decl_stmt
name|class
name|StringExtractor
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|namespace
name|process_gdb_remote
block|{
name|class
name|ProcessGDBRemote
decl_stmt|;
name|class
name|ThreadGDBRemote
range|:
name|public
name|Thread
block|{
name|public
operator|:
name|ThreadGDBRemote
argument_list|(
argument|Process&process
argument_list|,
argument|lldb::tid_t tid
argument_list|)
block|;
operator|~
name|ThreadGDBRemote
argument_list|()
name|override
block|;
name|void
name|WillResume
argument_list|(
argument|lldb::StateType resume_state
argument_list|)
name|override
block|;
name|void
name|RefreshStateAfterStop
argument_list|()
name|override
block|;
specifier|const
name|char
operator|*
name|GetName
argument_list|()
name|override
block|;
specifier|const
name|char
operator|*
name|GetQueueName
argument_list|()
name|override
block|;
name|lldb
operator|::
name|QueueKind
name|GetQueueKind
argument_list|()
name|override
block|;
name|lldb
operator|::
name|queue_id_t
name|GetQueueID
argument_list|()
name|override
block|;
name|lldb
operator|::
name|QueueSP
name|GetQueue
argument_list|()
name|override
block|;
name|lldb
operator|::
name|addr_t
name|GetQueueLibdispatchQueueAddress
argument_list|()
name|override
block|;
name|void
name|SetQueueLibdispatchQueueAddress
argument_list|(
argument|lldb::addr_t dispatch_queue_t
argument_list|)
name|override
block|;
name|bool
name|ThreadHasQueueInformation
argument_list|()
specifier|const
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
name|Dump
argument_list|(
argument|Log *log
argument_list|,
argument|uint32_t index
argument_list|)
block|;
specifier|static
name|bool
name|ThreadIDIsValid
argument_list|(
argument|lldb::tid_t thread
argument_list|)
block|;
name|bool
name|ShouldStop
argument_list|(
name|bool
operator|&
name|step_more
argument_list|)
block|;
specifier|const
name|char
operator|*
name|GetBasicInfoAsString
argument_list|()
block|;
name|void
name|SetName
argument_list|(
argument|const char *name
argument_list|)
name|override
block|{
if|if
condition|(
name|name
operator|&&
name|name
index|[
literal|0
index|]
condition|)
name|m_thread_name
operator|.
name|assign
argument_list|(
name|name
argument_list|)
expr_stmt|;
else|else
name|m_thread_name
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
name|lldb
operator|::
name|addr_t
name|GetThreadDispatchQAddr
argument_list|()
block|{
return|return
name|m_thread_dispatch_qaddr
return|;
block|}
name|void
name|SetThreadDispatchQAddr
argument_list|(
argument|lldb::addr_t thread_dispatch_qaddr
argument_list|)
block|{
name|m_thread_dispatch_qaddr
operator|=
name|thread_dispatch_qaddr
block|;   }
name|void
name|ClearQueueInfo
argument_list|()
block|;
name|void
name|SetQueueInfo
argument_list|(
argument|std::string&&queue_name
argument_list|,
argument|lldb::QueueKind queue_kind
argument_list|,
argument|uint64_t queue_serial
argument_list|,
argument|lldb::addr_t dispatch_queue_t
argument_list|,
argument|lldb_private::LazyBool associated_with_libdispatch_queue
argument_list|)
block|;
name|lldb_private
operator|::
name|LazyBool
name|GetAssociatedWithLibdispatchQueue
argument_list|()
name|override
block|;
name|void
name|SetAssociatedWithLibdispatchQueue
argument_list|(
argument|lldb_private::LazyBool associated_with_libdispatch_queue
argument_list|)
name|override
block|;
name|StructuredData
operator|::
name|ObjectSP
name|FetchThreadExtendedInfo
argument_list|()
name|override
block|;
name|protected
operator|:
name|friend
name|class
name|ProcessGDBRemote
block|;
name|std
operator|::
name|string
name|m_thread_name
block|;
name|std
operator|::
name|string
name|m_dispatch_queue_name
block|;
name|lldb
operator|::
name|addr_t
name|m_thread_dispatch_qaddr
block|;
name|lldb
operator|::
name|addr_t
name|m_dispatch_queue_t
block|;
name|lldb
operator|::
name|QueueKind
name|m_queue_kind
block|;
comment|// Queue info from stop reply/stop info for thread
name|uint64_t
name|m_queue_serial_number
block|;
comment|// Queue info from stop reply/stop info for thread
name|lldb_private
operator|::
name|LazyBool
name|m_associated_with_libdispatch_queue
block|;
name|bool
name|PrivateSetRegisterValue
argument_list|(
argument|uint32_t reg
argument_list|,
argument|llvm::ArrayRef<uint8_t> data
argument_list|)
block|;
name|bool
name|PrivateSetRegisterValue
argument_list|(
argument|uint32_t reg
argument_list|,
argument|uint64_t regval
argument_list|)
block|;
name|bool
name|CachedQueueInfoIsValid
argument_list|()
specifier|const
block|{
return|return
name|m_queue_kind
operator|!=
name|lldb
operator|::
name|eQueueKindUnknown
return|;
block|}
name|void
name|SetStopInfoFromPacket
argument_list|(
argument|StringExtractor&stop_packet
argument_list|,
argument|uint32_t stop_id
argument_list|)
block|;
name|bool
name|CalculateStopInfo
argument_list|()
name|override
block|; }
decl_stmt|;
block|}
comment|// namespace process_gdb_remote
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
comment|// liblldb_ThreadGDBRemote_h_
end_comment

end_unit

