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
file|<condition_variable>
end_include

begin_include
include|#
directive|include
file|<mutex>
end_include

begin_include
include|#
directive|include
file|<queue>
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
file|"lldb/Host/HostThread.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Host/Predicate.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Interpreter/Args.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-public.h"
end_include

begin_include
include|#
directive|include
file|"Utility/StringExtractorGDBRemote.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|namespace
name|process_gdb_remote
block|{
typedef|typedef
enum|enum
block|{
name|eStoppointInvalid
init|=
operator|-
literal|1
block|,
name|eBreakpointSoftware
init|=
literal|0
block|,
name|eBreakpointHardware
block|,
name|eWatchpointWrite
block|,
name|eWatchpointRead
block|,
name|eWatchpointReadWrite
block|}
name|GDBStoppointType
typedef|;
name|enum
name|class
name|CompressionType
block|{
name|None
operator|=
literal|0
operator|,
comment|// no compression
name|ZlibDeflate
operator|,
comment|// zlib's deflate compression scheme, requires zlib or Apple's
comment|// libcompression
name|LZFSE
operator|,
comment|// an Apple compression scheme, requires Apple's libcompression
name|LZ4
operator|,
comment|// lz compression - called "lz4 raw" in libcompression terms, compat with
comment|// https://code.google.com/p/lz4/
name|LZMA
operator|,
comment|// LempelâZivâMarkov chain algorithm
block|}
empty_stmt|;
name|class
name|ProcessGDBRemote
decl_stmt|;
name|class
name|GDBRemoteCommunication
range|:
name|public
name|Communication
block|{
name|public
operator|:
expr|enum
block|{
name|eBroadcastBitRunPacketSent
operator|=
name|kLoUserBroadcastBit
block|,
name|eBroadcastBitGdbReadThreadGotNotify
operator|=
name|kLoUserBroadcastBit
operator|<<
literal|1
comment|// Sent when we received a notify packet.
block|}
block|;    enum
name|class
name|PacketType
block|{
name|Invalid
operator|=
literal|0
block|,
name|Standard
block|,
name|Notify
block|}
block|;    enum
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
comment|// Got a reply but it wasn't valid for the packet that
comment|// was sent
name|ErrorReplyAck
block|,
comment|// Sending reply ack failed
name|ErrorDisconnected
block|,
comment|// We were disconnected
name|ErrorNoSequenceLock
comment|// We couldn't get the sequence lock for a multi-packet
comment|// request
block|}
block|;
comment|// Class to change the timeout for a given scope and restore it to the
comment|// original value when the
comment|// created ScopedTimeout object got out of scope
name|class
name|ScopedTimeout
block|{
name|public
operator|:
name|ScopedTimeout
argument_list|(
argument|GDBRemoteCommunication&gdb_comm
argument_list|,
argument|std::chrono::seconds timeout
argument_list|)
block|;
operator|~
name|ScopedTimeout
argument_list|()
block|;
name|private
operator|:
name|GDBRemoteCommunication
operator|&
name|m_gdb_comm
block|;
name|std
operator|::
name|chrono
operator|::
name|seconds
name|m_saved_timeout
block|;
comment|// Don't ever reduce the timeout for a packet, only increase it. If the
comment|// requested timeout if less than the current timeout, we don't set it
comment|// and won't need to restore it.
name|bool
name|m_timeout_modified
block|;   }
block|;
name|GDBRemoteCommunication
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
operator|~
name|GDBRemoteCommunication
argument_list|()
name|override
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
argument|llvm::StringRef payload
argument_list|)
block|;
name|PacketType
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
name|GetSendAcks
argument_list|()
block|{
return|return
name|m_send_acks
return|;
block|}
comment|//------------------------------------------------------------------
comment|// Set the global packet timeout.
comment|//
comment|// For clients, this is the timeout that gets used when sending
comment|// packets and waiting for responses. For servers, this is used when waiting
comment|// for ACKs.
comment|//------------------------------------------------------------------
name|std
operator|::
name|chrono
operator|::
name|seconds
name|SetPacketTimeout
argument_list|(
argument|std::chrono::seconds packet_timeout
argument_list|)
block|{
specifier|const
name|auto
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
name|std
operator|::
name|chrono
operator|::
name|seconds
name|GetPacketTimeout
argument_list|()
specifier|const
block|{
return|return
name|m_packet_timeout
return|;
block|}
comment|//------------------------------------------------------------------
comment|// Start a debugserver instance on the current host using the
comment|// supplied connection URL.
comment|//------------------------------------------------------------------
name|Error
name|StartDebugserverProcess
argument_list|(
argument|const char *url
argument_list|,
argument|Platform *platform
argument_list|,
comment|// If non nullptr, then check with the platform for
comment|// the GDB server binary if it can't be located
argument|ProcessLaunchInfo&launch_info
argument_list|,
argument|uint16_t *port
argument_list|,
argument|const Args *inferior_args
argument_list|,
argument|int pass_comm_fd
argument_list|)
block|;
comment|// Communication file descriptor to pass during
comment|// fork/exec to avoid having to connect/accept
name|void
name|DumpHistory
argument_list|(
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
block|;      struct
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
block|{}
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
block|;       }
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
block|;     }
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
argument|Stream&strm
argument_list|)
specifier|const
block|;
name|void
name|Dump
argument_list|(
argument|Log *log
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
block|;   }
block|;
name|std
operator|::
name|chrono
operator|::
name|seconds
name|m_packet_timeout
block|;
name|uint32_t
name|m_echo_number
block|;
name|LazyBool
name|m_supports_qEcho
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
name|CompressionType
name|m_compression_type
block|;
name|PacketResult
name|SendPacketNoLock
argument_list|(
argument|llvm::StringRef payload
argument_list|)
block|;
name|PacketResult
name|ReadPacket
argument_list|(
argument|StringExtractorGDBRemote&response
argument_list|,
argument|Timeout<std::micro> timeout
argument_list|,
argument|bool sync_on_timeout
argument_list|)
block|;
comment|// Pop a packet from the queue in a thread safe manner
name|PacketResult
name|PopPacketFromQueue
argument_list|(
name|StringExtractorGDBRemote
operator|&
name|response
argument_list|,
name|Timeout
operator|<
name|std
operator|::
name|micro
operator|>
name|timeout
argument_list|)
block|;
name|PacketResult
name|WaitForPacketNoLock
argument_list|(
argument|StringExtractorGDBRemote&response
argument_list|,
argument|Timeout<std::micro> timeout
argument_list|,
argument|bool sync_on_timeout
argument_list|)
block|;
name|bool
name|CompressionIsEnabled
argument_list|()
block|{
return|return
name|m_compression_type
operator|!=
name|CompressionType
operator|::
name|None
return|;
block|}
comment|// If compression is enabled, decompress the packet in m_bytes and update
comment|// m_bytes with the uncompressed version.
comment|// Returns 'true' packet was decompressed and m_bytes is the now-decompressed
comment|// text.
comment|// Returns 'false' if unable to decompress or if the checksum was invalid.
comment|//
comment|// NB: Once the packet has been decompressed, checksum cannot be computed
comment|// based
comment|// on m_bytes.  The checksum was for the compressed packet.
name|bool
name|DecompressPacket
argument_list|()
block|;
name|Error
name|StartListenThread
argument_list|(
argument|const char *hostname =
literal|"127.0.0.1"
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
comment|// GDB-Remote read thread
comment|//  . this thread constantly tries to read from the communication
comment|//    class and stores all packets received in a queue.  The usual
comment|//    threads read requests simply pop packets off the queue in the
comment|//    usual order.
comment|//    This setup allows us to intercept and handle async packets, such
comment|//    as the notify packet.
comment|// This method is defined as part of communication.h
comment|// when the read thread gets any bytes it will pass them on to this function
name|void
name|AppendBytesToCache
argument_list|(
argument|const uint8_t *bytes
argument_list|,
argument|size_t len
argument_list|,
argument|bool broadcast
argument_list|,
argument|lldb::ConnectionStatus status
argument_list|)
name|override
block|;
name|private
operator|:
name|std
operator|::
name|queue
operator|<
name|StringExtractorGDBRemote
operator|>
name|m_packet_queue
block|;
comment|// The packet queue
name|std
operator|::
name|mutex
name|m_packet_queue_mutex
block|;
comment|// Mutex for accessing queue
name|std
operator|::
name|condition_variable
name|m_condition_queue_not_empty
block|;
comment|// Condition variable to wait for packets
name|HostThread
name|m_listen_thread
block|;
name|std
operator|::
name|string
name|m_listen_url
block|;
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|GDBRemoteCommunication
argument_list|)
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
comment|// liblldb_GDBRemoteCommunication_h_
end_comment

end_unit

