begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- CommunicationKDP.h --------------------------------------*- C++ -*-===//
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
name|liblldb_CommunicationKDP_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_CommunicationKDP_h_
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
file|<mutex>
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
file|"lldb/Core/StreamBuffer.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Host/Predicate.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-private.h"
end_include

begin_decl_stmt
name|class
name|CommunicationKDP
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
block|;
specifier|const
specifier|static
name|uint32_t
name|kMaxPacketSize
operator|=
literal|1200
block|;
specifier|const
specifier|static
name|uint32_t
name|kMaxDataSize
operator|=
literal|1024
block|;
typedef|typedef
name|lldb_private
operator|::
name|StreamBuffer
operator|<
literal|1024
operator|>
name|PacketStreamType
expr_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
enum|enum
block|{
name|KDP_CONNECT
init|=
literal|0u
block|,
name|KDP_DISCONNECT
block|,
name|KDP_HOSTINFO
block|,
name|KDP_VERSION
block|,
name|KDP_MAXBYTES
block|,
name|KDP_READMEM
block|,
name|KDP_WRITEMEM
block|,
name|KDP_READREGS
block|,
name|KDP_WRITEREGS
block|,
name|KDP_LOAD
block|,
name|KDP_IMAGEPATH
block|,
name|KDP_SUSPEND
block|,
name|KDP_RESUMECPUS
block|,
name|KDP_EXCEPTION
block|,
name|KDP_TERMINATION
block|,
name|KDP_BREAKPOINT_SET
block|,
name|KDP_BREAKPOINT_REMOVE
block|,
name|KDP_REGIONS
block|,
name|KDP_REATTACH
block|,
name|KDP_HOSTREBOOT
block|,
name|KDP_READMEM64
block|,
name|KDP_WRITEMEM64
block|,
name|KDP_BREAKPOINT_SET64
block|,
name|KDP_BREAKPOINT_REMOVE64
block|,
name|KDP_KERNELVERSION
block|,
name|KDP_READPHYSMEM64
block|,
name|KDP_WRITEPHYSMEM64
block|,
name|KDP_READIOPORT
block|,
name|KDP_WRITEIOPORT
block|,
name|KDP_READMSR64
block|,
name|KDP_WRITEMSR64
block|,
name|KDP_DUMPINFO
block|}
name|CommandType
typedef|;
end_typedef

begin_enum
enum|enum
block|{
name|KDP_FEATURE_BP
init|=
operator|(
literal|1u
operator|<<
literal|0
operator|)
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
enum|enum
block|{
name|KDP_PROTERR_SUCCESS
init|=
literal|0
block|,
name|KDP_PROTERR_ALREADY_CONNECTED
block|,
name|KDP_PROTERR_BAD_NBYTES
block|,
name|KDP_PROTERR_BADFLAVOR
block|}
name|KDPError
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|ePacketTypeRequest
init|=
literal|0x00u
block|,
name|ePacketTypeReply
init|=
literal|0x80u
block|,
name|ePacketTypeMask
init|=
literal|0x80u
block|,
name|eCommandTypeMask
init|=
literal|0x7fu
block|}
name|PacketType
typedef|;
end_typedef

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|// Constructors and Destructors
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_expr_stmt
name|CommunicationKDP
argument_list|(
specifier|const
name|char
operator|*
name|comm_name
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|virtual
operator|~
name|CommunicationKDP
argument_list|()
expr_stmt|;
end_expr_stmt

begin_function_decl
name|bool
name|SendRequestPacket
parameter_list|(
specifier|const
name|PacketStreamType
modifier|&
name|request_packet
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Wait for a packet within 'nsec' seconds
end_comment

begin_decl_stmt
name|size_t
name|WaitForPacketWithTimeoutMicroSeconds
argument_list|(
name|lldb_private
operator|::
name|DataExtractor
operator|&
name|response
argument_list|,
name|uint32_t
name|usec
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|GetSequenceMutex
argument_list|(
name|std
operator|::
name|unique_lock
operator|<
name|std
operator|::
name|recursive_mutex
operator|>
operator|&
name|lock
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|CheckForPacket
argument_list|(
specifier|const
name|uint8_t
operator|*
name|src
argument_list|,
name|size_t
name|src_len
argument_list|,
name|lldb_private
operator|::
name|DataExtractor
operator|&
name|packet
argument_list|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|bool
name|IsRunning
argument_list|()
specifier|const
block|{
return|return
name|m_is_running
operator|.
name|GetValue
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|// Set the global packet timeout.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// For clients, this is the timeout that gets used when sending
end_comment

begin_comment
comment|// packets and waiting for responses. For servers, this might not
end_comment

begin_comment
comment|// get used, and if it doesn't this should be moved to the
end_comment

begin_comment
comment|// CommunicationKDPClient.
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_expr_stmt
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
end_expr_stmt

begin_expr_stmt
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
end_expr_stmt

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|// Public Request Packets
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_function_decl
name|bool
name|SendRequestConnect
parameter_list|(
name|uint16_t
name|reply_port
parameter_list|,
name|uint16_t
name|exc_port
parameter_list|,
specifier|const
name|char
modifier|*
name|greeting
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|SendRequestReattach
parameter_list|(
name|uint16_t
name|reply_port
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|SendRequestDisconnect
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|uint32_t
name|SendRequestReadMemory
argument_list|(
name|lldb
operator|::
name|addr_t
name|addr
argument_list|,
name|void
operator|*
name|dst
argument_list|,
name|uint32_t
name|dst_size
argument_list|,
name|lldb_private
operator|::
name|Status
operator|&
name|error
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|uint32_t
name|SendRequestWriteMemory
argument_list|(
name|lldb
operator|::
name|addr_t
name|addr
argument_list|,
specifier|const
name|void
operator|*
name|src
argument_list|,
name|uint32_t
name|src_len
argument_list|,
name|lldb_private
operator|::
name|Status
operator|&
name|error
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|SendRawRequest
argument_list|(
name|uint8_t
name|command_byte
argument_list|,
specifier|const
name|void
operator|*
name|src
argument_list|,
name|uint32_t
name|src_len
argument_list|,
name|lldb_private
operator|::
name|DataExtractor
operator|&
name|reply
argument_list|,
name|lldb_private
operator|::
name|Status
operator|&
name|error
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|uint32_t
name|SendRequestReadRegisters
argument_list|(
name|uint32_t
name|cpu
argument_list|,
name|uint32_t
name|flavor
argument_list|,
name|void
operator|*
name|dst
argument_list|,
name|uint32_t
name|dst_size
argument_list|,
name|lldb_private
operator|::
name|Status
operator|&
name|error
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|uint32_t
name|SendRequestWriteRegisters
argument_list|(
name|uint32_t
name|cpu
argument_list|,
name|uint32_t
name|flavor
argument_list|,
specifier|const
name|void
operator|*
name|src
argument_list|,
name|uint32_t
name|src_size
argument_list|,
name|lldb_private
operator|::
name|Status
operator|&
name|error
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|const
name|char
modifier|*
name|GetKernelVersion
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// Disable KDP_IMAGEPATH for now, it seems to hang the KDP connection...
end_comment

begin_comment
comment|// const char *
end_comment

begin_comment
comment|// GetImagePath ();
end_comment

begin_function_decl
name|uint32_t
name|GetVersion
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|GetFeatureFlags
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|bool
name|LocalBreakpointsAreSupported
parameter_list|()
block|{
return|return
operator|(
name|GetFeatureFlags
argument_list|()
operator|&
name|KDP_FEATURE_BP
operator|)
operator|!=
literal|0
return|;
block|}
end_function

begin_function_decl
name|uint32_t
name|GetCPUMask
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|GetCPUType
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|GetCPUSubtype
parameter_list|()
function_decl|;
end_function_decl

begin_expr_stmt
name|lldb_private
operator|::
name|UUID
name|GetUUID
argument_list|()
expr_stmt|;
end_expr_stmt

begin_function_decl
name|bool
name|RemoteIsEFI
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|RemoteIsDarwinKernel
parameter_list|()
function_decl|;
end_function_decl

begin_expr_stmt
name|lldb
operator|::
name|addr_t
name|GetLoadAddress
argument_list|()
expr_stmt|;
end_expr_stmt

begin_function_decl
name|bool
name|SendRequestResume
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|SendRequestSuspend
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|bool
name|SendRequestBreakpoint
argument_list|(
name|bool
name|set
argument_list|,
name|lldb
operator|::
name|addr_t
name|addr
argument_list|)
decl_stmt|;
end_decl_stmt

begin_label
name|protected
label|:
end_label

begin_function_decl
name|bool
name|SendRequestPacketNoLock
parameter_list|(
specifier|const
name|PacketStreamType
modifier|&
name|request_packet
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|size_t
name|WaitForPacketWithTimeoutMicroSecondsNoLock
argument_list|(
name|lldb_private
operator|::
name|DataExtractor
operator|&
name|response
argument_list|,
name|uint32_t
name|timeout_usec
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|WaitForNotRunningPrivate
argument_list|(
specifier|const
name|std
operator|::
name|chrono
operator|::
name|microseconds
operator|&
name|timeout
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|MakeRequestPacketHeader
parameter_list|(
name|CommandType
name|request_type
parameter_list|,
name|PacketStreamType
modifier|&
name|request_packet
parameter_list|,
name|uint16_t
name|request_length
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|// Protected Request Packets (use public accessors which will cache
end_comment

begin_comment
comment|// results.
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_function_decl
name|bool
name|SendRequestVersion
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|SendRequestHostInfo
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|SendRequestKernelVersion
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// Disable KDP_IMAGEPATH for now, it seems to hang the KDP connection...
end_comment

begin_comment
comment|// bool
end_comment

begin_comment
comment|// SendRequestImagePath ();
end_comment

begin_decl_stmt
name|void
name|DumpPacket
argument_list|(
name|lldb_private
operator|::
name|Stream
operator|&
name|s
argument_list|,
specifier|const
name|void
operator|*
name|data
argument_list|,
name|uint32_t
name|data_len
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|DumpPacket
argument_list|(
name|lldb_private
operator|::
name|Stream
operator|&
name|s
argument_list|,
specifier|const
name|lldb_private
operator|::
name|DataExtractor
operator|&
name|extractor
argument_list|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|bool
name|VersionIsValid
argument_list|()
specifier|const
block|{
return|return
name|m_kdp_version_version
operator|!=
literal|0
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|HostInfoIsValid
argument_list|()
specifier|const
block|{
return|return
name|m_kdp_hostinfo_cpu_type
operator|!=
literal|0
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|bool
name|ExtractIsReply
argument_list|(
name|uint8_t
name|first_packet_byte
argument_list|)
decl|const
block|{
comment|// TODO: handle big endian...
return|return
operator|(
name|first_packet_byte
operator|&
name|ePacketTypeMask
operator|)
operator|!=
literal|0
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|CommandType
name|ExtractCommand
argument_list|(
name|uint8_t
name|first_packet_byte
argument_list|)
decl|const
block|{
comment|// TODO: handle big endian...
return|return
call|(
name|CommandType
call|)
argument_list|(
name|first_packet_byte
operator|&
name|eCommandTypeMask
argument_list|)
return|;
block|}
end_decl_stmt

begin_function_decl
specifier|static
specifier|const
name|char
modifier|*
name|GetCommandAsCString
parameter_list|(
name|uint8_t
name|command
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ClearKDPSettings
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|bool
name|SendRequestAndGetReply
argument_list|(
specifier|const
name|CommandType
name|command
argument_list|,
specifier|const
name|PacketStreamType
operator|&
name|request_packet
argument_list|,
name|lldb_private
operator|::
name|DataExtractor
operator|&
name|reply_packet
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|// Classes that inherit from CommunicationKDP can see and modify these
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_decl_stmt
name|uint32_t
name|m_addr_byte_size
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|lldb
operator|::
name|ByteOrder
name|m_byte_order
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|chrono
operator|::
name|seconds
name|m_packet_timeout
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|recursive_mutex
name|m_sequence_mutex
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Restrict access to sending/receiving
end_comment

begin_comment
comment|// packets to a single thread at a time
end_comment

begin_expr_stmt
name|lldb_private
operator|::
name|Predicate
operator|<
name|bool
operator|>
name|m_is_running
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|uint32_t
name|m_session_key
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|uint8_t
name|m_request_sequence_id
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|uint8_t
name|m_exception_sequence_id
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|uint32_t
name|m_kdp_version_version
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|uint32_t
name|m_kdp_version_feature
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|uint32_t
name|m_kdp_hostinfo_cpu_mask
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|uint32_t
name|m_kdp_hostinfo_cpu_type
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|uint32_t
name|m_kdp_hostinfo_cpu_subtype
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|std
operator|::
name|string
name|m_kernel_version
expr_stmt|;
end_expr_stmt

begin_comment
comment|// std::string m_image_path; // Disable KDP_IMAGEPATH for now, it seems to
end_comment

begin_comment
comment|// hang the KDP connection...
end_comment

begin_expr_stmt
name|lldb
operator|::
name|addr_t
name|m_last_read_memory_addr
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Last memory read address for logging
end_comment

begin_label
name|private
label|:
end_label

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|// For CommunicationKDP only
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_expr_stmt
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|CommunicationKDP
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
unit|};
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_CommunicationKDP_h_
end_comment

end_unit

