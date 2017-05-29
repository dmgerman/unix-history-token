begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- GDBRemoteCommunicationClient.h --------------------------*- C++ -*-===//
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
name|liblldb_GDBRemoteCommunicationClient_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_GDBRemoteCommunicationClient_h_
end_define

begin_include
include|#
directive|include
file|"GDBRemoteClientBase.h"
end_include

begin_comment
comment|// C Includes
end_comment

begin_comment
comment|// C++ Includes
end_comment

begin_include
include|#
directive|include
file|<chrono>
end_include

begin_include
include|#
directive|include
file|<map>
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
file|"lldb/Core/ArchSpec.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/StructuredData.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/Process.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/StreamGDBRemote.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Optional.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|namespace
name|process_gdb_remote
block|{
name|class
name|GDBRemoteCommunicationClient
range|:
name|public
name|GDBRemoteClientBase
block|{
name|public
operator|:
name|GDBRemoteCommunicationClient
argument_list|()
block|;
operator|~
name|GDBRemoteCommunicationClient
argument_list|()
name|override
block|;
comment|//------------------------------------------------------------------
comment|// After connecting, send the handshake to the server to make sure
comment|// we are communicating with it.
comment|//------------------------------------------------------------------
name|bool
name|HandshakeWithServer
argument_list|(
name|Status
operator|*
name|error_ptr
argument_list|)
block|;
comment|// For packets which specify a range of output to be returned,
comment|// return all of the output via a series of request packets of the form
comment|//<prefix>0,<size>
comment|//<prefix><size>,<size>
comment|//<prefix><size>*2,<size>
comment|//<prefix><size>*3,<size>
comment|// ...
comment|// until a "$l..." packet is received, indicating the end.
comment|// (size is in hex; this format is used by a standard gdbserver to
comment|// return the given portion of the output specified by<prefix>;
comment|// for example, "qXfer:libraries-svr4:read::fff,1000" means
comment|// "return a chunk of the xml description file for shared
comment|// library load addresses, where the chunk starts at offset 0xfff
comment|// and continues for 0x1000 bytes").
comment|// Concatenate the resulting server response packets together and
comment|// return in response_string.  If any packet fails, the return value
comment|// indicates that failure and the returned string value is undefined.
name|PacketResult
name|SendPacketsAndConcatenateResponses
argument_list|(
specifier|const
name|char
operator|*
name|send_payload_prefix
argument_list|,
name|std
operator|::
name|string
operator|&
name|response_string
argument_list|)
block|;
name|bool
name|GetThreadSuffixSupported
argument_list|()
block|;
comment|// This packet is usually sent first and the boolean return value
comment|// indicates if the packet was send and any response was received
comment|// even in the response is UNIMPLEMENTED. If the packet failed to
comment|// get a response, then false is returned. This quickly tells us
comment|// if we were able to connect and communicate with the remote GDB
comment|// server
name|bool
name|QueryNoAckModeSupported
argument_list|()
block|;
name|void
name|GetListThreadsInStopReplySupported
argument_list|()
block|;
name|lldb
operator|::
name|pid_t
name|GetCurrentProcessID
argument_list|(
argument|bool allow_lazy = true
argument_list|)
block|;
name|bool
name|GetLaunchSuccess
argument_list|(
name|std
operator|::
name|string
operator|&
name|error_str
argument_list|)
block|;
name|bool
name|LaunchGDBServer
argument_list|(
specifier|const
name|char
operator|*
name|remote_accept_hostname
argument_list|,
name|lldb
operator|::
name|pid_t
operator|&
name|pid
argument_list|,
name|uint16_t
operator|&
name|port
argument_list|,
name|std
operator|::
name|string
operator|&
name|socket_name
argument_list|)
block|;
name|size_t
name|QueryGDBServer
argument_list|(
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|pair
operator|<
name|uint16_t
argument_list|,
name|std
operator|::
name|string
operator|>>
operator|&
name|connection_urls
argument_list|)
block|;
name|bool
name|KillSpawnedProcess
argument_list|(
argument|lldb::pid_t pid
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Sends a GDB remote protocol 'A' packet that delivers program
comment|/// arguments to the remote server.
comment|///
comment|/// @param[in] argv
comment|///     A NULL terminated array of const C strings to use as the
comment|///     arguments.
comment|///
comment|/// @return
comment|///     Zero if the response was "OK", a positive value if the
comment|///     the response was "Exx" where xx are two hex digits, or
comment|///     -1 if the call is unsupported or any other unexpected
comment|///     response was received.
comment|//------------------------------------------------------------------
name|int
name|SendArgumentsPacket
argument_list|(
specifier|const
name|ProcessLaunchInfo
operator|&
name|launch_info
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Sends a "QEnvironment:NAME=VALUE" packet that will build up the
comment|/// environment that will get used when launching an application
comment|/// in conjunction with the 'A' packet. This function can be called
comment|/// multiple times in a row in order to pass on the desired
comment|/// environment that the inferior should be launched with.
comment|///
comment|/// @param[in] name_equal_value
comment|///     A NULL terminated C string that contains a single environment
comment|///     in the format "NAME=VALUE".
comment|///
comment|/// @return
comment|///     Zero if the response was "OK", a positive value if the
comment|///     the response was "Exx" where xx are two hex digits, or
comment|///     -1 if the call is unsupported or any other unexpected
comment|///     response was received.
comment|//------------------------------------------------------------------
name|int
name|SendEnvironmentPacket
argument_list|(
name|char
specifier|const
operator|*
name|name_equal_value
argument_list|)
block|;
name|int
name|SendLaunchArchPacket
argument_list|(
specifier|const
name|char
operator|*
name|arch
argument_list|)
block|;
name|int
name|SendLaunchEventDataPacket
argument_list|(
specifier|const
name|char
operator|*
name|data
argument_list|,
name|bool
operator|*
name|was_supported
operator|=
name|nullptr
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Sends a "vAttach:PID" where PID is in hex.
comment|///
comment|/// @param[in] pid
comment|///     A process ID for the remote gdb server to attach to.
comment|///
comment|/// @param[out] response
comment|///     The response received from the gdb server. If the return
comment|///     value is zero, \a response will contain a stop reply
comment|///     packet.
comment|///
comment|/// @return
comment|///     Zero if the attach was successful, or an error indicating
comment|///     an error code.
comment|//------------------------------------------------------------------
name|int
name|SendAttach
argument_list|(
argument|lldb::pid_t pid
argument_list|,
argument|StringExtractorGDBRemote&response
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Sends a GDB remote protocol 'I' packet that delivers stdin
comment|/// data to the remote process.
comment|///
comment|/// @param[in] data
comment|///     A pointer to stdin data.
comment|///
comment|/// @param[in] data_len
comment|///     The number of bytes available at \a data.
comment|///
comment|/// @return
comment|///     Zero if the attach was successful, or an error indicating
comment|///     an error code.
comment|//------------------------------------------------------------------
name|int
name|SendStdinNotification
argument_list|(
argument|const char *data
argument_list|,
argument|size_t data_len
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Sets the path to use for stdin/out/err for a process
comment|/// that will be launched with the 'A' packet.
comment|///
comment|/// @param[in] path
comment|///     The path to use for stdin/out/err
comment|///
comment|/// @return
comment|///     Zero if the for success, or an error code for failure.
comment|//------------------------------------------------------------------
name|int
name|SetSTDIN
argument_list|(
specifier|const
name|FileSpec
operator|&
name|file_spec
argument_list|)
block|;
name|int
name|SetSTDOUT
argument_list|(
specifier|const
name|FileSpec
operator|&
name|file_spec
argument_list|)
block|;
name|int
name|SetSTDERR
argument_list|(
specifier|const
name|FileSpec
operator|&
name|file_spec
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Sets the disable ASLR flag to \a enable for a process that will
comment|/// be launched with the 'A' packet.
comment|///
comment|/// @param[in] enable
comment|///     A boolean value indicating whether to disable ASLR or not.
comment|///
comment|/// @return
comment|///     Zero if the for success, or an error code for failure.
comment|//------------------------------------------------------------------
name|int
name|SetDisableASLR
argument_list|(
argument|bool enable
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Sets the DetachOnError flag to \a enable for the process controlled by the
comment|/// stub.
comment|///
comment|/// @param[in] enable
comment|///     A boolean value indicating whether to detach on error or not.
comment|///
comment|/// @return
comment|///     Zero if the for success, or an error code for failure.
comment|//------------------------------------------------------------------
name|int
name|SetDetachOnError
argument_list|(
argument|bool enable
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Sets the working directory to \a path for a process that will
comment|/// be launched with the 'A' packet for non platform based
comment|/// connections. If this packet is sent to a GDB server that
comment|/// implements the platform, it will change the current working
comment|/// directory for the platform process.
comment|///
comment|/// @param[in] working_dir
comment|///     The path to a directory to use when launching our process
comment|///
comment|/// @return
comment|///     Zero if the for success, or an error code for failure.
comment|//------------------------------------------------------------------
name|int
name|SetWorkingDir
argument_list|(
specifier|const
name|FileSpec
operator|&
name|working_dir
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Gets the current working directory of a remote platform GDB
comment|/// server.
comment|///
comment|/// @param[out] working_dir
comment|///     The current working directory on the remote platform.
comment|///
comment|/// @return
comment|///     Boolean for success
comment|//------------------------------------------------------------------
name|bool
name|GetWorkingDir
argument_list|(
name|FileSpec
operator|&
name|working_dir
argument_list|)
block|;
name|lldb
operator|::
name|addr_t
name|AllocateMemory
argument_list|(
argument|size_t size
argument_list|,
argument|uint32_t permissions
argument_list|)
block|;
name|bool
name|DeallocateMemory
argument_list|(
argument|lldb::addr_t addr
argument_list|)
block|;
name|Status
name|Detach
argument_list|(
argument|bool keep_stopped
argument_list|)
block|;
name|Status
name|GetMemoryRegionInfo
argument_list|(
argument|lldb::addr_t addr
argument_list|,
argument|MemoryRegionInfo&range_info
argument_list|)
block|;
name|Status
name|GetWatchpointSupportInfo
argument_list|(
name|uint32_t
operator|&
name|num
argument_list|)
block|;
name|Status
name|GetWatchpointSupportInfo
argument_list|(
name|uint32_t
operator|&
name|num
argument_list|,
name|bool
operator|&
name|after
argument_list|,
specifier|const
name|ArchSpec
operator|&
name|arch
argument_list|)
block|;
name|Status
name|GetWatchpointsTriggerAfterInstruction
argument_list|(
name|bool
operator|&
name|after
argument_list|,
specifier|const
name|ArchSpec
operator|&
name|arch
argument_list|)
block|;
specifier|const
name|ArchSpec
operator|&
name|GetHostArchitecture
argument_list|()
block|;
name|std
operator|::
name|chrono
operator|::
name|seconds
name|GetHostDefaultPacketTimeout
argument_list|()
block|;
specifier|const
name|ArchSpec
operator|&
name|GetProcessArchitecture
argument_list|()
block|;
name|void
name|GetRemoteQSupported
argument_list|()
block|;
name|bool
name|GetVContSupported
argument_list|(
argument|char flavor
argument_list|)
block|;
name|bool
name|GetpPacketSupported
argument_list|(
argument|lldb::tid_t tid
argument_list|)
block|;
name|bool
name|GetxPacketSupported
argument_list|()
block|;
name|bool
name|GetVAttachOrWaitSupported
argument_list|()
block|;
name|bool
name|GetSyncThreadStateSupported
argument_list|()
block|;
name|void
name|ResetDiscoverableSettings
argument_list|(
argument|bool did_exec
argument_list|)
block|;
name|bool
name|GetHostInfo
argument_list|(
argument|bool force = false
argument_list|)
block|;
name|bool
name|GetDefaultThreadId
argument_list|(
name|lldb
operator|::
name|tid_t
operator|&
name|tid
argument_list|)
block|;
name|bool
name|GetOSVersion
argument_list|(
name|uint32_t
operator|&
name|major
argument_list|,
name|uint32_t
operator|&
name|minor
argument_list|,
name|uint32_t
operator|&
name|update
argument_list|)
block|;
name|bool
name|GetOSBuildString
argument_list|(
name|std
operator|::
name|string
operator|&
name|s
argument_list|)
block|;
name|bool
name|GetOSKernelDescription
argument_list|(
name|std
operator|::
name|string
operator|&
name|s
argument_list|)
block|;
name|ArchSpec
name|GetSystemArchitecture
argument_list|()
block|;
name|bool
name|GetHostname
argument_list|(
name|std
operator|::
name|string
operator|&
name|s
argument_list|)
block|;
name|lldb
operator|::
name|addr_t
name|GetShlibInfoAddr
argument_list|()
block|;
name|bool
name|GetSupportsThreadSuffix
argument_list|()
block|;
name|bool
name|GetProcessInfo
argument_list|(
argument|lldb::pid_t pid
argument_list|,
argument|ProcessInstanceInfo&process_info
argument_list|)
block|;
name|uint32_t
name|FindProcesses
argument_list|(
specifier|const
name|ProcessInstanceInfoMatch
operator|&
name|process_match_info
argument_list|,
name|ProcessInstanceInfoList
operator|&
name|process_infos
argument_list|)
block|;
name|bool
name|GetUserName
argument_list|(
argument|uint32_t uid
argument_list|,
argument|std::string&name
argument_list|)
block|;
name|bool
name|GetGroupName
argument_list|(
argument|uint32_t gid
argument_list|,
argument|std::string&name
argument_list|)
block|;
name|bool
name|HasFullVContSupport
argument_list|()
block|{
return|return
name|GetVContSupported
argument_list|(
literal|'A'
argument_list|)
return|;
block|}
name|bool
name|HasAnyVContSupport
argument_list|()
block|{
return|return
name|GetVContSupported
argument_list|(
literal|'a'
argument_list|)
return|;
block|}
name|bool
name|GetStopReply
argument_list|(
name|StringExtractorGDBRemote
operator|&
name|response
argument_list|)
block|;
name|bool
name|GetThreadStopInfo
argument_list|(
argument|lldb::tid_t tid
argument_list|,
argument|StringExtractorGDBRemote&response
argument_list|)
block|;
name|bool
name|SupportsGDBStoppointPacket
argument_list|(
argument|GDBStoppointType type
argument_list|)
block|{
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|eBreakpointSoftware
case|:
return|return
name|m_supports_z0
return|;
case|case
name|eBreakpointHardware
case|:
return|return
name|m_supports_z1
return|;
case|case
name|eWatchpointWrite
case|:
return|return
name|m_supports_z2
return|;
case|case
name|eWatchpointRead
case|:
return|return
name|m_supports_z3
return|;
case|case
name|eWatchpointReadWrite
case|:
return|return
name|m_supports_z4
return|;
default|default:
return|return
name|false
return|;
block|}
block|}
name|uint8_t
name|SendGDBStoppointTypePacket
argument_list|(
argument|GDBStoppointType type
argument_list|,
comment|// Type of breakpoint or watchpoint
argument|bool insert
argument_list|,
comment|// Insert or remove?
argument|lldb::addr_t addr
argument_list|,
comment|// Address of breakpoint or watchpoint
argument|uint32_t length
argument_list|)
block|;
comment|// Byte Size of breakpoint or watchpoint
name|bool
name|SetNonStopMode
argument_list|(
argument|const bool enable
argument_list|)
block|;
name|void
name|TestPacketSpeed
argument_list|(
argument|const uint32_t num_packets
argument_list|,
argument|uint32_t max_send
argument_list|,
argument|uint32_t max_recv
argument_list|,
argument|uint64_t recv_amount
argument_list|,
argument|bool json
argument_list|,
argument|Stream&strm
argument_list|)
block|;
comment|// This packet is for testing the speed of the interface only. Both
comment|// the client and server need to support it, but this allows us to
comment|// measure the packet speed without any other work being done on the
comment|// other end and avoids any of that work affecting the packet send
comment|// and response times.
name|bool
name|SendSpeedTestPacket
argument_list|(
argument|uint32_t send_size
argument_list|,
argument|uint32_t recv_size
argument_list|)
block|;
name|bool
name|SetCurrentThread
argument_list|(
argument|uint64_t tid
argument_list|)
block|;
name|bool
name|SetCurrentThreadForRun
argument_list|(
argument|uint64_t tid
argument_list|)
block|;
name|bool
name|GetQXferAuxvReadSupported
argument_list|()
block|;
name|bool
name|GetQXferLibrariesReadSupported
argument_list|()
block|;
name|bool
name|GetQXferLibrariesSVR4ReadSupported
argument_list|()
block|;
name|uint64_t
name|GetRemoteMaxPacketSize
argument_list|()
block|;
name|bool
name|GetEchoSupported
argument_list|()
block|;
name|bool
name|GetQPassSignalsSupported
argument_list|()
block|;
name|bool
name|GetAugmentedLibrariesSVR4ReadSupported
argument_list|()
block|;
name|bool
name|GetQXferFeaturesReadSupported
argument_list|()
block|;
name|LazyBool
name|SupportsAllocDeallocMemory
argument_list|()
comment|// const
block|{
comment|// Uncomment this to have lldb pretend the debug server doesn't respond to
comment|// alloc/dealloc memory packets.
comment|// m_supports_alloc_dealloc_memory = lldb_private::eLazyBoolNo;
return|return
name|m_supports_alloc_dealloc_memory
return|;
block|}
name|size_t
name|GetCurrentThreadIDs
argument_list|(
name|std
operator|::
name|vector
operator|<
name|lldb
operator|::
name|tid_t
operator|>
operator|&
name|thread_ids
argument_list|,
name|bool
operator|&
name|sequence_mutex_unavailable
argument_list|)
block|;
name|lldb
operator|::
name|user_id_t
name|OpenFile
argument_list|(
argument|const FileSpec&file_spec
argument_list|,
argument|uint32_t flags
argument_list|,
argument|mode_t mode
argument_list|,
argument|Status&error
argument_list|)
block|;
name|bool
name|CloseFile
argument_list|(
argument|lldb::user_id_t fd
argument_list|,
argument|Status&error
argument_list|)
block|;
name|lldb
operator|::
name|user_id_t
name|GetFileSize
argument_list|(
specifier|const
name|FileSpec
operator|&
name|file_spec
argument_list|)
block|;
name|Status
name|GetFilePermissions
argument_list|(
specifier|const
name|FileSpec
operator|&
name|file_spec
argument_list|,
name|uint32_t
operator|&
name|file_permissions
argument_list|)
block|;
name|Status
name|SetFilePermissions
argument_list|(
argument|const FileSpec&file_spec
argument_list|,
argument|uint32_t file_permissions
argument_list|)
block|;
name|uint64_t
name|ReadFile
argument_list|(
argument|lldb::user_id_t fd
argument_list|,
argument|uint64_t offset
argument_list|,
argument|void *dst
argument_list|,
argument|uint64_t dst_len
argument_list|,
argument|Status&error
argument_list|)
block|;
name|uint64_t
name|WriteFile
argument_list|(
argument|lldb::user_id_t fd
argument_list|,
argument|uint64_t offset
argument_list|,
argument|const void *src
argument_list|,
argument|uint64_t src_len
argument_list|,
argument|Status&error
argument_list|)
block|;
name|Status
name|CreateSymlink
argument_list|(
specifier|const
name|FileSpec
operator|&
name|src
argument_list|,
specifier|const
name|FileSpec
operator|&
name|dst
argument_list|)
block|;
name|Status
name|Unlink
argument_list|(
specifier|const
name|FileSpec
operator|&
name|file_spec
argument_list|)
block|;
name|Status
name|MakeDirectory
argument_list|(
argument|const FileSpec&file_spec
argument_list|,
argument|uint32_t mode
argument_list|)
block|;
name|bool
name|GetFileExists
argument_list|(
specifier|const
name|FileSpec
operator|&
name|file_spec
argument_list|)
block|;
name|Status
name|RunShellCommand
argument_list|(
argument|const char *command
argument_list|,
comment|// Shouldn't be nullptr
argument|const FileSpec&working_dir
argument_list|,
comment|// Pass empty FileSpec to use the current
comment|// working directory
argument|int *status_ptr
argument_list|,
comment|// Pass nullptr if you don't want the process exit status
argument|int *signo_ptr
argument_list|,
comment|// Pass nullptr if you don't want the signal that caused
comment|// the process to exit
argument|std::string           *command_output
argument_list|,
comment|// Pass nullptr if you don't want the command output
argument|uint32_t timeout_sec
argument_list|)
block|;
comment|// Timeout in seconds to wait for shell program to
comment|// finish
name|bool
name|CalculateMD5
argument_list|(
specifier|const
name|FileSpec
operator|&
name|file_spec
argument_list|,
name|uint64_t
operator|&
name|high
argument_list|,
name|uint64_t
operator|&
name|low
argument_list|)
block|;
name|lldb
operator|::
name|DataBufferSP
name|ReadRegister
argument_list|(
argument|lldb::tid_t tid
argument_list|,
argument|uint32_t           reg_num
argument_list|)
block|;
comment|// Must be the eRegisterKindProcessPlugin register number
name|lldb
operator|::
name|DataBufferSP
name|ReadAllRegisters
argument_list|(
argument|lldb::tid_t tid
argument_list|)
block|;
name|bool
name|WriteRegister
argument_list|(
argument|lldb::tid_t tid
argument_list|,
argument|uint32_t reg_num
argument_list|,
comment|// eRegisterKindProcessPlugin register number
argument|llvm::ArrayRef<uint8_t> data
argument_list|)
block|;
name|bool
name|WriteAllRegisters
argument_list|(
argument|lldb::tid_t tid
argument_list|,
argument|llvm::ArrayRef<uint8_t> data
argument_list|)
block|;
name|bool
name|SaveRegisterState
argument_list|(
argument|lldb::tid_t tid
argument_list|,
argument|uint32_t&save_id
argument_list|)
block|;
name|bool
name|RestoreRegisterState
argument_list|(
argument|lldb::tid_t tid
argument_list|,
argument|uint32_t save_id
argument_list|)
block|;
name|bool
name|SyncThreadState
argument_list|(
argument|lldb::tid_t tid
argument_list|)
block|;
specifier|const
name|char
operator|*
name|GetGDBServerProgramName
argument_list|()
block|;
name|uint32_t
name|GetGDBServerProgramVersion
argument_list|()
block|;
name|bool
name|AvoidGPackets
argument_list|(
name|ProcessGDBRemote
operator|*
name|process
argument_list|)
block|;
name|StructuredData
operator|::
name|ObjectSP
name|GetThreadsInfo
argument_list|()
block|;
name|bool
name|GetThreadExtendedInfoSupported
argument_list|()
block|;
name|bool
name|GetLoadedDynamicLibrariesInfosSupported
argument_list|()
block|;
name|bool
name|GetSharedCacheInfoSupported
argument_list|()
block|;
name|bool
name|GetModuleInfo
argument_list|(
specifier|const
name|FileSpec
operator|&
name|module_file_spec
argument_list|,
specifier|const
name|ArchSpec
operator|&
name|arch_spec
argument_list|,
name|ModuleSpec
operator|&
name|module_spec
argument_list|)
block|;
name|llvm
operator|::
name|Optional
operator|<
name|std
operator|::
name|vector
operator|<
name|ModuleSpec
operator|>>
name|GetModulesInfo
argument_list|(
name|llvm
operator|::
name|ArrayRef
operator|<
name|FileSpec
operator|>
name|module_file_specs
argument_list|,
specifier|const
name|llvm
operator|::
name|Triple
operator|&
name|triple
argument_list|)
block|;
name|bool
name|ReadExtFeature
argument_list|(
argument|const lldb_private::ConstString object
argument_list|,
argument|const lldb_private::ConstString annex
argument_list|,
argument|std::string&out
argument_list|,
argument|lldb_private::Status&err
argument_list|)
block|;
name|void
name|ServeSymbolLookups
argument_list|(
name|lldb_private
operator|::
name|Process
operator|*
name|process
argument_list|)
block|;
comment|// Sends QPassSignals packet to the server with given signals to ignore.
name|Status
name|SendSignalsToIgnore
argument_list|(
name|llvm
operator|::
name|ArrayRef
operator|<
name|int32_t
operator|>
name|signals
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Return the feature set supported by the gdb-remote server.
comment|///
comment|/// This method returns the remote side's response to the qSupported
comment|/// packet.  The response is the complete string payload returned
comment|/// to the client.
comment|///
comment|/// @return
comment|///     The string returned by the server to the qSupported query.
comment|//------------------------------------------------------------------
specifier|const
name|std
operator|::
name|string
operator|&
name|GetServerSupportedFeatures
argument_list|()
specifier|const
block|{
return|return
name|m_qSupported_response
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Return the array of async JSON packet types supported by the remote.
comment|///
comment|/// This method returns the remote side's array of supported JSON
comment|/// packet types as a list of type names.  Each of the results are
comment|/// expected to have an Enable{type_name} command to enable and configure
comment|/// the related feature.  Each type_name for an enabled feature will
comment|/// possibly send async-style packets that contain a payload of a
comment|/// binhex-encoded JSON dictionary.  The dictionary will have a
comment|/// string field named 'type', that contains the type_name of the
comment|/// supported packet type.
comment|///
comment|/// There is a Plugin category called structured-data plugins.
comment|/// A plugin indicates whether it knows how to handle a type_name.
comment|/// If so, it can be used to process the async JSON packet.
comment|///
comment|/// @return
comment|///     The string returned by the server to the qSupported query.
comment|//------------------------------------------------------------------
name|lldb_private
operator|::
name|StructuredData
operator|::
name|Array
operator|*
name|GetSupportedStructuredDataPlugins
argument_list|()
block|;
comment|//------------------------------------------------------------------
comment|/// Configure a StructuredData feature on the remote end.
comment|///
comment|/// @see \b Process::ConfigureStructuredData(...) for details.
comment|//------------------------------------------------------------------
name|Status
name|ConfigureRemoteStructuredData
argument_list|(
specifier|const
name|ConstString
operator|&
name|type_name
argument_list|,
specifier|const
name|StructuredData
operator|::
name|ObjectSP
operator|&
name|config_sp
argument_list|)
block|;
name|lldb
operator|::
name|user_id_t
name|SendStartTracePacket
argument_list|(
specifier|const
name|TraceOptions
operator|&
name|options
argument_list|,
name|Status
operator|&
name|error
argument_list|)
block|;
name|Status
name|SendStopTracePacket
argument_list|(
argument|lldb::user_id_t uid
argument_list|,
argument|lldb::tid_t thread_id
argument_list|)
block|;
name|Status
name|SendGetDataPacket
argument_list|(
argument|lldb::user_id_t uid
argument_list|,
argument|lldb::tid_t thread_id
argument_list|,
argument|llvm::MutableArrayRef<uint8_t>&buffer
argument_list|,
argument|size_t offset =
literal|0
argument_list|)
block|;
name|Status
name|SendGetMetaDataPacket
argument_list|(
argument|lldb::user_id_t uid
argument_list|,
argument|lldb::tid_t thread_id
argument_list|,
argument|llvm::MutableArrayRef<uint8_t>&buffer
argument_list|,
argument|size_t offset =
literal|0
argument_list|)
block|;
name|Status
name|SendGetTraceConfigPacket
argument_list|(
argument|lldb::user_id_t uid
argument_list|,
argument|TraceOptions&options
argument_list|)
block|;
name|protected
operator|:
name|LazyBool
name|m_supports_not_sending_acks
block|;
name|LazyBool
name|m_supports_thread_suffix
block|;
name|LazyBool
name|m_supports_threads_in_stop_reply
block|;
name|LazyBool
name|m_supports_vCont_all
block|;
name|LazyBool
name|m_supports_vCont_any
block|;
name|LazyBool
name|m_supports_vCont_c
block|;
name|LazyBool
name|m_supports_vCont_C
block|;
name|LazyBool
name|m_supports_vCont_s
block|;
name|LazyBool
name|m_supports_vCont_S
block|;
name|LazyBool
name|m_qHostInfo_is_valid
block|;
name|LazyBool
name|m_curr_pid_is_valid
block|;
name|LazyBool
name|m_qProcessInfo_is_valid
block|;
name|LazyBool
name|m_qGDBServerVersion_is_valid
block|;
name|LazyBool
name|m_supports_alloc_dealloc_memory
block|;
name|LazyBool
name|m_supports_memory_region_info
block|;
name|LazyBool
name|m_supports_watchpoint_support_info
block|;
name|LazyBool
name|m_supports_detach_stay_stopped
block|;
name|LazyBool
name|m_watchpoints_trigger_after_instruction
block|;
name|LazyBool
name|m_attach_or_wait_reply
block|;
name|LazyBool
name|m_prepare_for_reg_writing_reply
block|;
name|LazyBool
name|m_supports_p
block|;
name|LazyBool
name|m_supports_x
block|;
name|LazyBool
name|m_avoid_g_packets
block|;
name|LazyBool
name|m_supports_QSaveRegisterState
block|;
name|LazyBool
name|m_supports_qXfer_auxv_read
block|;
name|LazyBool
name|m_supports_qXfer_libraries_read
block|;
name|LazyBool
name|m_supports_qXfer_libraries_svr4_read
block|;
name|LazyBool
name|m_supports_qXfer_features_read
block|;
name|LazyBool
name|m_supports_augmented_libraries_svr4_read
block|;
name|LazyBool
name|m_supports_jThreadExtendedInfo
block|;
name|LazyBool
name|m_supports_jLoadedDynamicLibrariesInfos
block|;
name|LazyBool
name|m_supports_jGetSharedCacheInfo
block|;
name|LazyBool
name|m_supports_QPassSignals
block|;
name|bool
name|m_supports_qProcessInfoPID
operator|:
literal|1
block|,
name|m_supports_qfProcessInfo
operator|:
literal|1
block|,
name|m_supports_qUserName
operator|:
literal|1
block|,
name|m_supports_qGroupName
operator|:
literal|1
block|,
name|m_supports_qThreadStopInfo
operator|:
literal|1
block|,
name|m_supports_z0
operator|:
literal|1
block|,
name|m_supports_z1
operator|:
literal|1
block|,
name|m_supports_z2
operator|:
literal|1
block|,
name|m_supports_z3
operator|:
literal|1
block|,
name|m_supports_z4
operator|:
literal|1
block|,
name|m_supports_QEnvironment
operator|:
literal|1
block|,
name|m_supports_QEnvironmentHexEncoded
operator|:
literal|1
block|,
name|m_supports_qSymbol
operator|:
literal|1
block|,
name|m_qSymbol_requests_done
operator|:
literal|1
block|,
name|m_supports_qModuleInfo
operator|:
literal|1
block|,
name|m_supports_jThreadsInfo
operator|:
literal|1
block|,
name|m_supports_jModulesInfo
operator|:
literal|1
block|;
name|lldb
operator|::
name|pid_t
name|m_curr_pid
block|;
name|lldb
operator|::
name|tid_t
name|m_curr_tid
block|;
comment|// Current gdb remote protocol thread index for all
comment|// other operations
name|lldb
operator|::
name|tid_t
name|m_curr_tid_run
block|;
comment|// Current gdb remote protocol thread index for
comment|// continue, step, etc
name|uint32_t
name|m_num_supported_hardware_watchpoints
block|;
name|ArchSpec
name|m_host_arch
block|;
name|ArchSpec
name|m_process_arch
block|;
name|uint32_t
name|m_os_version_major
block|;
name|uint32_t
name|m_os_version_minor
block|;
name|uint32_t
name|m_os_version_update
block|;
name|std
operator|::
name|string
name|m_os_build
block|;
name|std
operator|::
name|string
name|m_os_kernel
block|;
name|std
operator|::
name|string
name|m_hostname
block|;
name|std
operator|::
name|string
name|m_gdb_server_name
block|;
comment|// from reply to qGDBServerVersion, empty if
comment|// qGDBServerVersion is not supported
name|uint32_t
name|m_gdb_server_version
block|;
comment|// from reply to qGDBServerVersion, zero if
comment|// qGDBServerVersion is not supported
name|std
operator|::
name|chrono
operator|::
name|seconds
name|m_default_packet_timeout
block|;
name|uint64_t
name|m_max_packet_size
block|;
comment|// as returned by qSupported
name|std
operator|::
name|string
name|m_qSupported_response
block|;
comment|// the complete response to qSupported
name|bool
name|m_supported_async_json_packets_is_valid
block|;
name|lldb_private
operator|::
name|StructuredData
operator|::
name|ObjectSP
name|m_supported_async_json_packets_sp
block|;
name|bool
name|GetCurrentProcessInfo
argument_list|(
argument|bool allow_lazy_pid = true
argument_list|)
block|;
name|bool
name|GetGDBServerVersion
argument_list|()
block|;
comment|// Given the list of compression types that the remote debug stub can support,
comment|// possibly enable compression if we find an encoding we can handle.
name|void
name|MaybeEnableCompression
argument_list|(
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|supported_compressions
argument_list|)
block|;
name|bool
name|DecodeProcessInfoResponse
argument_list|(
name|StringExtractorGDBRemote
operator|&
name|response
argument_list|,
name|ProcessInstanceInfo
operator|&
name|process_info
argument_list|)
block|;
name|void
name|OnRunPacketSent
argument_list|(
argument|bool first
argument_list|)
name|override
block|;
name|PacketResult
name|SendThreadSpecificPacketAndWaitForResponse
argument_list|(
argument|lldb::tid_t tid
argument_list|,
argument|StreamString&&payload
argument_list|,
argument|StringExtractorGDBRemote&response
argument_list|,
argument|bool send_async
argument_list|)
block|;
name|Status
name|SendGetTraceDataPacket
argument_list|(
argument|StreamGDBRemote&packet
argument_list|,
argument|lldb::user_id_t uid
argument_list|,
argument|lldb::tid_t thread_id
argument_list|,
argument|llvm::MutableArrayRef<uint8_t>&buffer
argument_list|,
argument|size_t offset
argument_list|)
block|;
name|private
operator|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|GDBRemoteCommunicationClient
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
comment|// liblldb_GDBRemoteCommunicationClient_h_
end_comment

end_unit

