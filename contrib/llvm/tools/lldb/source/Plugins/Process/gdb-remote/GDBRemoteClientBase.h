begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- GDBRemoteClientBase.h -----------------------------------*- C++ -*-===//
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
name|liblldb_GDBRemoteClientBase_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_GDBRemoteClientBase_h_
end_define

begin_include
include|#
directive|include
file|"GDBRemoteCommunication.h"
end_include

begin_include
include|#
directive|include
file|<condition_variable>
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|namespace
name|process_gdb_remote
block|{
name|class
name|GDBRemoteClientBase
range|:
name|public
name|GDBRemoteCommunication
block|{
name|public
operator|:
expr|struct
name|ContinueDelegate
block|{
name|virtual
operator|~
name|ContinueDelegate
argument_list|()
block|;
name|virtual
name|void
name|HandleAsyncStdout
argument_list|(
argument|llvm::StringRef out
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|HandleAsyncMisc
argument_list|(
argument|llvm::StringRef data
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|HandleStopReply
argument_list|()
operator|=
literal|0
block|;
comment|// =========================================================================
comment|/// Process asynchronously-received structured data.
comment|///
comment|/// @param[in] data
comment|///   The complete data packet, expected to start with JSON-async.
comment|// =========================================================================
name|virtual
name|void
name|HandleAsyncStructuredDataPacket
argument_list|(
argument|llvm::StringRef data
argument_list|)
operator|=
literal|0
block|;   }
block|;
name|GDBRemoteClientBase
argument_list|(
specifier|const
name|char
operator|*
name|comm_name
argument_list|,
specifier|const
name|char
operator|*
name|listener_name
argument_list|)
block|;
name|bool
name|SendAsyncSignal
argument_list|(
argument|int signo
argument_list|)
block|;
name|bool
name|Interrupt
argument_list|()
block|;
name|lldb
operator|::
name|StateType
name|SendContinuePacketAndWaitForResponse
argument_list|(
argument|ContinueDelegate&delegate
argument_list|,
argument|const UnixSignals&signals
argument_list|,
argument|llvm::StringRef payload
argument_list|,
argument|StringExtractorGDBRemote&response
argument_list|)
block|;
name|PacketResult
name|SendPacketAndWaitForResponse
argument_list|(
argument|llvm::StringRef payload
argument_list|,
argument|StringExtractorGDBRemote&response
argument_list|,
argument|bool send_async
argument_list|)
block|;
name|bool
name|SendvContPacket
argument_list|(
argument|llvm::StringRef payload
argument_list|,
argument|StringExtractorGDBRemote&response
argument_list|)
block|;
name|class
name|Lock
block|{
name|public
operator|:
name|Lock
argument_list|(
argument|GDBRemoteClientBase&comm
argument_list|,
argument|bool interrupt
argument_list|)
block|;
operator|~
name|Lock
argument_list|()
block|;
name|explicit
name|operator
name|bool
argument_list|()
block|{
return|return
name|m_acquired
return|;
block|}
comment|// Whether we had to interrupt the continue thread to acquire the
comment|// connection.
name|bool
name|DidInterrupt
argument_list|()
specifier|const
block|{
return|return
name|m_did_interrupt
return|;
block|}
name|private
operator|:
name|std
operator|::
name|unique_lock
operator|<
name|std
operator|::
name|recursive_mutex
operator|>
name|m_async_lock
block|;
name|GDBRemoteClientBase
operator|&
name|m_comm
block|;
name|bool
name|m_acquired
block|;
name|bool
name|m_did_interrupt
block|;
name|void
name|SyncWithContinueThread
argument_list|(
argument|bool interrupt
argument_list|)
block|;   }
block|;
name|protected
operator|:
name|PacketResult
name|SendPacketAndWaitForResponseNoLock
argument_list|(
argument|llvm::StringRef payload
argument_list|,
argument|StringExtractorGDBRemote&response
argument_list|)
block|;
name|virtual
name|void
name|OnRunPacketSent
argument_list|(
argument|bool first
argument_list|)
block|;
name|private
operator|:
comment|// Variables handling synchronization between the Continue thread and any
comment|// other threads
comment|// wishing to send packets over the connection. Either the continue thread has
comment|// control over
comment|// the connection (m_is_running == true) or the connection is free for an
comment|// arbitrary number of
comment|// other senders to take which indicate their interest by incrementing
comment|// m_async_count.
comment|// Semantics of individual states:
comment|// - m_continue_packet == false, m_async_count == 0: connection is free
comment|// - m_continue_packet == true, m_async_count == 0: only continue thread is
comment|// present
comment|// - m_continue_packet == true, m_async_count> 0: continue thread has
comment|// control, async threads
comment|//   should interrupt it and wait for it to set m_continue_packet to false
comment|// - m_continue_packet == false, m_async_count> 0: async threads have
comment|// control, continue
comment|//   thread needs to wait for them to finish (m_async_count goes down to 0).
name|std
operator|::
name|mutex
name|m_mutex
block|;
name|std
operator|::
name|condition_variable
name|m_cv
block|;
comment|// Packet with which to resume after an async interrupt. Can be changed by an
comment|// async thread
comment|// e.g. to inject a signal.
name|std
operator|::
name|string
name|m_continue_packet
block|;
comment|// When was the interrupt packet sent. Used to make sure we time out if the
comment|// stub does not
comment|// respond to interrupt requests.
name|std
operator|::
name|chrono
operator|::
name|time_point
operator|<
name|std
operator|::
name|chrono
operator|::
name|steady_clock
operator|>
name|m_interrupt_time
block|;
name|uint32_t
name|m_async_count
block|;
name|bool
name|m_is_running
block|;
name|bool
name|m_should_stop
block|;
comment|// Whether we should resume after a stop.
comment|// end of continue thread synchronization block
comment|// This handles the synchronization between individual async threads. For now
comment|// they just use a
comment|// simple mutex.
name|std
operator|::
name|recursive_mutex
name|m_async_mutex
block|;
name|bool
name|ShouldStop
argument_list|(
specifier|const
name|UnixSignals
operator|&
name|signals
argument_list|,
name|StringExtractorGDBRemote
operator|&
name|response
argument_list|)
block|;
name|class
name|ContinueLock
block|{
name|public
operator|:
expr|enum
name|class
name|LockResult
block|{
name|Success
block|,
name|Cancelled
block|,
name|Failed
block|}
block|;
name|explicit
name|ContinueLock
argument_list|(
name|GDBRemoteClientBase
operator|&
name|comm
argument_list|)
block|;
operator|~
name|ContinueLock
argument_list|()
block|;
name|explicit
name|operator
name|bool
argument_list|()
block|{
return|return
name|m_acquired
return|;
block|}
name|LockResult
name|lock
argument_list|()
block|;
name|void
name|unlock
argument_list|()
block|;
name|private
operator|:
name|GDBRemoteClientBase
operator|&
name|m_comm
block|;
name|bool
name|m_acquired
block|;   }
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
comment|// liblldb_GDBRemoteCommunicationClient_h_
end_comment

end_unit

