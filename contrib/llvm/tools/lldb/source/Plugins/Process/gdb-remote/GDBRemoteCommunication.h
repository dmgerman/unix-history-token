begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- GDBRemoteCommunication.h --------------------------------*- C++ -*-===//
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
name|liblldb_GDBRemoteCommunication_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_GDBRemoteCommunication_h_
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
file|<list>
end_include

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
file|"lldb/lldb-public.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/Communication.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/Listener.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Host/Mutex.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Host/Predicate.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Host/TimeValue.h"
end_include

begin_include
include|#
directive|include
file|"Utility/StringExtractorGDBRemote.h"
end_include

begin_decl_stmt
name|class
name|ProcessGDBRemote
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|GDBRemoteCommunication
range|:
name|public
name|lldb_private
operator|::
name|Communication
block|{
name|public
operator|:
expr|enum
block|{
name|eBroadcastBitRunPacketSent
operator|=
name|kLoUserBroadcastBit
block|}
block|;          enum
name|class
name|PacketResult
block|{
name|Success
operator|=
literal|0
block|,
comment|// Success
name|ErrorSendFailed
block|,
comment|// Error sending the packet
name|ErrorSendAck
block|,
comment|// Didn't get an ack back after sending a packet
name|ErrorReplyFailed
block|,
comment|// Error getting the reply
name|ErrorReplyTimeout
block|,
comment|// Timed out waiting for reply
name|ErrorReplyInvalid
block|,
comment|// Got a reply but it wasn't valid for the packet that was sent
name|ErrorReplyAck
block|,
comment|// Sending reply ack failed
name|ErrorDisconnected
block|,
comment|// We were disconnected
name|ErrorNoSequenceLock
comment|// We couldn't get the sequence lock for a multi-packet request
block|}
block|;
comment|//------------------------------------------------------------------
comment|// Constructors and Destructors
comment|//------------------------------------------------------------------
name|GDBRemoteCommunication
argument_list|(
argument|const char *comm_name
argument_list|,
argument|const char *listener_name
argument_list|,
argument|bool is_platform
argument_list|)
block|;
name|virtual
operator|~
name|GDBRemoteCommunication
argument_list|()
block|;
name|PacketResult
name|GetAck
argument_list|()
block|;
name|size_t
name|SendAck
argument_list|()
block|;
name|size_t
name|SendNack
argument_list|()
block|;
name|char
name|CalculcateChecksum
argument_list|(
argument|const char *payload
argument_list|,
argument|size_t payload_length
argument_list|)
block|;
name|bool
name|GetSequenceMutex
argument_list|(
name|lldb_private
operator|::
name|Mutex
operator|::
name|Locker
operator|&
name|locker
argument_list|,
specifier|const
name|char
operator|*
name|failure_message
operator|=
name|NULL
argument_list|)
block|;
name|bool
name|CheckForPacket
argument_list|(
argument|const uint8_t *src
argument_list|,
argument|size_t src_len
argument_list|,
argument|StringExtractorGDBRemote&packet
argument_list|)
block|;
name|bool
name|IsRunning
argument_list|()
specifier|const
block|{
return|return
name|m_public_is_running
operator|.
name|GetValue
argument_list|()
return|;
block|}
name|bool
name|GetSendAcks
argument_list|()
block|{
return|return
name|m_send_acks
return|;
block|}
comment|//------------------------------------------------------------------
comment|// Client and server must implement these pure virtual functions
comment|//------------------------------------------------------------------
name|virtual
name|bool
name|GetThreadSuffixSupported
argument_list|()
operator|=
literal|0
block|;
comment|//------------------------------------------------------------------
comment|// Set the global packet timeout.
comment|//
comment|// For clients, this is the timeout that gets used when sending
comment|// packets and waiting for responses. For servers, this might not
comment|// get used, and if it doesn't this should be moved to the
comment|// GDBRemoteCommunicationClient.
comment|//------------------------------------------------------------------
name|uint32_t
name|SetPacketTimeout
argument_list|(
argument|uint32_t packet_timeout
argument_list|)
block|{
specifier|const
name|uint32_t
name|old_packet_timeout
operator|=
name|m_packet_timeout
block|;
name|m_packet_timeout
operator|=
name|packet_timeout
block|;
return|return
name|old_packet_timeout
return|;
block|}
name|uint32_t
name|GetPacketTimeoutInMicroSeconds
argument_list|()
specifier|const
block|{
return|return
name|m_packet_timeout
operator|*
name|lldb_private
operator|::
name|TimeValue
operator|::
name|MicroSecPerSec
return|;
block|}
comment|//------------------------------------------------------------------
comment|// Start a debugserver instance on the current host using the
comment|// supplied connection URL.
comment|//------------------------------------------------------------------
name|lldb_private
operator|::
name|Error
name|StartDebugserverProcess
argument_list|(
argument|const char *hostname
argument_list|,
argument|uint16_t in_port
argument_list|,
comment|// If set to zero, then out_port will contain the bound port on exit
argument|lldb_private::ProcessLaunchInfo&launch_info
argument_list|,
argument|uint16_t&out_port
argument_list|)
block|;
name|void
name|DumpHistory
argument_list|(
name|lldb_private
operator|::
name|Stream
operator|&
name|strm
argument_list|)
block|;
name|protected
operator|:
name|class
name|History
block|{
name|public
operator|:
expr|enum
name|PacketType
block|{
name|ePacketTypeInvalid
operator|=
literal|0
block|,
name|ePacketTypeSend
block|,
name|ePacketTypeRecv
block|}
block|;          struct
name|Entry
block|{
name|Entry
argument_list|()
operator|:
name|packet
argument_list|()
block|,
name|type
argument_list|(
name|ePacketTypeInvalid
argument_list|)
block|,
name|bytes_transmitted
argument_list|(
literal|0
argument_list|)
block|,
name|packet_idx
argument_list|(
literal|0
argument_list|)
block|,
name|tid
argument_list|(
argument|LLDB_INVALID_THREAD_ID
argument_list|)
block|{             }
name|void
name|Clear
argument_list|()
block|{
name|packet
operator|.
name|clear
argument_list|()
block|;
name|type
operator|=
name|ePacketTypeInvalid
block|;
name|bytes_transmitted
operator|=
literal|0
block|;
name|packet_idx
operator|=
literal|0
block|;
name|tid
operator|=
name|LLDB_INVALID_THREAD_ID
block|;             }
name|std
operator|::
name|string
name|packet
block|;
name|PacketType
name|type
block|;
name|uint32_t
name|bytes_transmitted
block|;
name|uint32_t
name|packet_idx
block|;
name|lldb
operator|::
name|tid_t
name|tid
block|;         }
block|;
name|History
argument_list|(
argument|uint32_t size
argument_list|)
block|;
operator|~
name|History
argument_list|()
block|;
comment|// For single char packets for ack, nack and /x03
name|void
name|AddPacket
argument_list|(
argument|char packet_char
argument_list|,
argument|PacketType type
argument_list|,
argument|uint32_t bytes_transmitted
argument_list|)
block|;
name|void
name|AddPacket
argument_list|(
argument|const std::string&src
argument_list|,
argument|uint32_t src_len
argument_list|,
argument|PacketType type
argument_list|,
argument|uint32_t bytes_transmitted
argument_list|)
block|;
name|void
name|Dump
argument_list|(
argument|lldb_private::Stream&strm
argument_list|)
specifier|const
block|;
name|void
name|Dump
argument_list|(
argument|lldb_private::Log *log
argument_list|)
specifier|const
block|;
name|bool
name|DidDumpToLog
argument_list|()
specifier|const
block|{
return|return
name|m_dumped_to_log
return|;
block|}
name|protected
operator|:
name|uint32_t
name|GetFirstSavedPacketIndex
argument_list|()
specifier|const
block|{
if|if
condition|(
name|m_total_packet_count
operator|<
name|m_packets
operator|.
name|size
argument_list|()
condition|)
return|return
literal|0
return|;
else|else
return|return
name|m_curr_idx
operator|+
literal|1
return|;
block|}
name|uint32_t
name|GetNumPacketsInHistory
argument_list|()
specifier|const
block|{
if|if
condition|(
name|m_total_packet_count
operator|<
name|m_packets
operator|.
name|size
argument_list|()
condition|)
return|return
name|m_total_packet_count
return|;
else|else
return|return
operator|(
name|uint32_t
operator|)
name|m_packets
operator|.
name|size
argument_list|()
return|;
block|}
name|uint32_t
name|GetNextIndex
argument_list|()
block|{
operator|++
name|m_total_packet_count
block|;
specifier|const
name|uint32_t
name|idx
operator|=
name|m_curr_idx
block|;
name|m_curr_idx
operator|=
name|NormalizeIndex
argument_list|(
name|idx
operator|+
literal|1
argument_list|)
block|;
return|return
name|idx
return|;
block|}
name|uint32_t
name|NormalizeIndex
argument_list|(
argument|uint32_t i
argument_list|)
specifier|const
block|{
return|return
name|i
operator|%
name|m_packets
operator|.
name|size
argument_list|()
return|;
block|}
name|std
operator|::
name|vector
operator|<
name|Entry
operator|>
name|m_packets
block|;
name|uint32_t
name|m_curr_idx
block|;
name|uint32_t
name|m_total_packet_count
block|;
name|mutable
name|bool
name|m_dumped_to_log
block|;     }
block|;
name|PacketResult
name|SendPacket
argument_list|(
argument|const char *payload
argument_list|,
argument|size_t payload_length
argument_list|)
block|;
name|PacketResult
name|SendPacketNoLock
argument_list|(
argument|const char *payload
argument_list|,
argument|size_t payload_length
argument_list|)
block|;
name|PacketResult
name|WaitForPacketWithTimeoutMicroSecondsNoLock
argument_list|(
argument|StringExtractorGDBRemote&response
argument_list|,
argument|uint32_t timeout_usec
argument_list|)
block|;
name|bool
name|WaitForNotRunningPrivate
argument_list|(
specifier|const
name|lldb_private
operator|::
name|TimeValue
operator|*
name|timeout_ptr
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|// Classes that inherit from GDBRemoteCommunication can see and modify these
comment|//------------------------------------------------------------------
name|uint32_t
name|m_packet_timeout
block|;
ifdef|#
directive|ifdef
name|ENABLE_MUTEX_ERROR_CHECKING
name|lldb_private
operator|::
name|TrackingMutex
name|m_sequence_mutex
block|;
else|#
directive|else
name|lldb_private
operator|::
name|Mutex
name|m_sequence_mutex
block|;
comment|// Restrict access to sending/receiving packets to a single thread at a time
endif|#
directive|endif
name|lldb_private
operator|::
name|Predicate
operator|<
name|bool
operator|>
name|m_public_is_running
block|;
name|lldb_private
operator|::
name|Predicate
operator|<
name|bool
operator|>
name|m_private_is_running
block|;
name|History
name|m_history
block|;
name|bool
name|m_send_acks
block|;
name|bool
name|m_is_platform
block|;
comment|// Set to true if this class represents a platform,
comment|// false if this class represents a debug session for
comment|// a single process
name|lldb_private
operator|::
name|Error
name|StartListenThread
argument_list|(
argument|const char *hostname =
literal|"localhost"
argument_list|,
argument|uint16_t port =
literal|0
argument_list|)
block|;
name|bool
name|JoinListenThread
argument_list|()
block|;
specifier|static
name|lldb
operator|::
name|thread_result_t
name|ListenThread
argument_list|(
argument|lldb::thread_arg_t arg
argument_list|)
block|;
name|private
operator|:
name|lldb
operator|::
name|thread_t
name|m_listen_thread
block|;
name|std
operator|::
name|string
name|m_listen_url
block|;
comment|//------------------------------------------------------------------
comment|// For GDBRemoteCommunication only
comment|//------------------------------------------------------------------
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|GDBRemoteCommunication
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_GDBRemoteCommunication_h_
end_comment

end_unit

