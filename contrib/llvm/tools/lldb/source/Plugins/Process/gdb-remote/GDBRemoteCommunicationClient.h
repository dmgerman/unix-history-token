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

begin_comment
comment|// C Includes
end_comment

begin_comment
comment|// C++ Includes
end_comment

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
file|"lldb/Target/Process.h"
end_include

begin_include
include|#
directive|include
file|"GDBRemoteCommunication.h"
end_include

begin_typedef
typedef|typedef
enum|enum
block|{
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
end_typedef

begin_decl_stmt
name|class
name|GDBRemoteCommunicationClient
range|:
name|public
name|GDBRemoteCommunication
block|{
name|public
operator|:
comment|//------------------------------------------------------------------
comment|// Constructors and Destructors
comment|//------------------------------------------------------------------
name|GDBRemoteCommunicationClient
argument_list|(
argument|bool is_platform
argument_list|)
block|;
operator|~
name|GDBRemoteCommunicationClient
argument_list|()
block|;
comment|//------------------------------------------------------------------
comment|// After connecting, send the handshake to the server to make sure
comment|// we are communicating with it.
comment|//------------------------------------------------------------------
name|bool
name|HandshakeWithServer
argument_list|(
name|lldb_private
operator|::
name|Error
operator|*
name|error_ptr
argument_list|)
block|;
name|PacketResult
name|SendPacketAndWaitForResponse
argument_list|(
argument|const char *send_payload
argument_list|,
argument|StringExtractorGDBRemote&response
argument_list|,
argument|bool send_async
argument_list|)
block|;
name|PacketResult
name|SendPacketAndWaitForResponse
argument_list|(
argument|const char *send_payload
argument_list|,
argument|size_t send_length
argument_list|,
argument|StringExtractorGDBRemote&response
argument_list|,
argument|bool send_async
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
name|lldb
operator|::
name|StateType
name|SendContinuePacketAndWaitForResponse
argument_list|(
argument|ProcessGDBRemote *process
argument_list|,
argument|const char *packet_payload
argument_list|,
argument|size_t packet_length
argument_list|,
argument|StringExtractorGDBRemote&response
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
comment|// if we were able to connect and communicte with the remote GDB
comment|// server
name|bool
name|QueryNoAckModeSupported
argument_list|()
block|;
name|void
name|GetListThreadsInStopReplySupported
argument_list|()
block|;
name|bool
name|SendAsyncSignal
argument_list|(
argument|int signo
argument_list|)
block|;
name|bool
name|SendInterrupt
argument_list|(
argument|lldb_private::Mutex::Locker&locker
argument_list|,
argument|uint32_t seconds_to_wait_for_stop
argument_list|,
argument|bool&timed_out
argument_list|)
block|;
name|lldb
operator|::
name|pid_t
name|GetCurrentProcessID
argument_list|()
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
name|uint16_t
name|LaunchGDBserverAndGetPort
argument_list|(
name|lldb
operator|::
name|pid_t
operator|&
name|pid
argument_list|,
specifier|const
name|char
operator|*
name|remote_accept_hostname
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
name|lldb_private
operator|::
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
argument|StringExtractorGDBRemote& response
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
name|char
specifier|const
operator|*
name|path
argument_list|)
block|;
name|int
name|SetSTDOUT
argument_list|(
name|char
specifier|const
operator|*
name|path
argument_list|)
block|;
name|int
name|SetSTDERR
argument_list|(
name|char
specifier|const
operator|*
name|path
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Sets the disable ASLR flag to \a enable for a process that will
comment|/// be launched with the 'A' packet.
comment|///
comment|/// @param[in] enable
comment|///     A boolean value indicating wether to disable ASLR or not.
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
comment|/// Sets the working directory to \a path for a process that will
comment|/// be launched with the 'A' packet for non platform based
comment|/// connections. If this packet is sent to a GDB server that
comment|/// implements the platform, it will change the current working
comment|/// directory for the platform process.
comment|///
comment|/// @param[in] path
comment|///     The path to a directory to use when launching our processs
comment|///
comment|/// @return
comment|///     Zero if the for success, or an error code for failure.
comment|//------------------------------------------------------------------
name|int
name|SetWorkingDir
argument_list|(
name|char
specifier|const
operator|*
name|path
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Gets the current working directory of a remote platform GDB
comment|/// server.
comment|///
comment|/// @param[out] cwd
comment|///     The current working directory on the remote platform.
comment|///
comment|/// @return
comment|///     Boolean for success
comment|//------------------------------------------------------------------
name|bool
name|GetWorkingDir
argument_list|(
name|std
operator|::
name|string
operator|&
name|cwd
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
name|lldb_private
operator|::
name|Error
name|Detach
argument_list|(
argument|bool keep_stopped
argument_list|)
block|;
name|lldb_private
operator|::
name|Error
name|GetMemoryRegionInfo
argument_list|(
argument|lldb::addr_t addr
argument_list|,
argument|lldb_private::MemoryRegionInfo&range_info
argument_list|)
block|;
name|lldb_private
operator|::
name|Error
name|GetWatchpointSupportInfo
argument_list|(
name|uint32_t
operator|&
name|num
argument_list|)
block|;
name|lldb_private
operator|::
name|Error
name|GetWatchpointSupportInfo
argument_list|(
name|uint32_t
operator|&
name|num
argument_list|,
name|bool
operator|&
name|after
argument_list|)
block|;
name|lldb_private
operator|::
name|Error
name|GetWatchpointsTriggerAfterInstruction
argument_list|(
name|bool
operator|&
name|after
argument_list|)
block|;
specifier|const
name|lldb_private
operator|::
name|ArchSpec
operator|&
name|GetHostArchitecture
argument_list|()
block|;
name|uint32_t
name|GetHostDefaultPacketTimeout
argument_list|()
block|;
specifier|const
name|lldb_private
operator|::
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
name|GetVAttachOrWaitSupported
argument_list|()
block|;
name|bool
name|GetSyncThreadStateSupported
argument_list|()
block|;
name|void
name|ResetDiscoverableSettings
argument_list|()
block|;
name|bool
name|GetHostInfo
argument_list|(
argument|bool force = false
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
name|lldb_private
operator|::
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
argument|lldb_private::ProcessInstanceInfo&process_info
argument_list|)
block|;
name|uint32_t
name|FindProcesses
argument_list|(
specifier|const
name|lldb_private
operator|::
name|ProcessInstanceInfoMatch
operator|&
name|process_match_info
argument_list|,
name|lldb_private
operator|::
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
block|}
return|return
name|false
return|;
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
name|void
name|TestPacketSpeed
argument_list|(
argument|const uint32_t num_packets
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
name|GetAugmentedLibrariesSVR4ReadSupported
argument_list|()
block|;
name|lldb_private
operator|::
name|LazyBool
name|SupportsAllocDeallocMemory
argument_list|()
comment|// const
block|{
comment|// Uncomment this to have lldb pretend the debug server doesn't respond to alloc/dealloc memory packets.
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
name|bool
name|GetInterruptWasSent
argument_list|()
specifier|const
block|{
return|return
name|m_interrupt_sent
return|;
block|}
name|lldb
operator|::
name|user_id_t
name|OpenFile
argument_list|(
argument|const lldb_private::FileSpec& file_spec
argument_list|,
argument|uint32_t flags
argument_list|,
argument|mode_t mode
argument_list|,
argument|lldb_private::Error&error
argument_list|)
block|;
name|bool
name|CloseFile
argument_list|(
argument|lldb::user_id_t fd
argument_list|,
argument|lldb_private::Error&error
argument_list|)
block|;
name|lldb
operator|::
name|user_id_t
name|GetFileSize
argument_list|(
specifier|const
name|lldb_private
operator|::
name|FileSpec
operator|&
name|file_spec
argument_list|)
block|;
name|lldb_private
operator|::
name|Error
name|GetFilePermissions
argument_list|(
specifier|const
name|char
operator|*
name|path
argument_list|,
name|uint32_t
operator|&
name|file_permissions
argument_list|)
block|;
name|lldb_private
operator|::
name|Error
name|SetFilePermissions
argument_list|(
argument|const char *path
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
argument|lldb_private::Error&error
argument_list|)
block|;
name|uint64_t
name|WriteFile
argument_list|(
argument|lldb::user_id_t fd
argument_list|,
argument|uint64_t offset
argument_list|,
argument|const void* src
argument_list|,
argument|uint64_t src_len
argument_list|,
argument|lldb_private::Error&error
argument_list|)
block|;
name|lldb_private
operator|::
name|Error
name|CreateSymlink
argument_list|(
specifier|const
name|char
operator|*
name|src
argument_list|,
specifier|const
name|char
operator|*
name|dst
argument_list|)
block|;
name|lldb_private
operator|::
name|Error
name|Unlink
argument_list|(
specifier|const
name|char
operator|*
name|path
argument_list|)
block|;
name|lldb_private
operator|::
name|Error
name|MakeDirectory
argument_list|(
argument|const char *path
argument_list|,
argument|uint32_t mode
argument_list|)
block|;
name|bool
name|GetFileExists
argument_list|(
specifier|const
name|lldb_private
operator|::
name|FileSpec
operator|&
name|file_spec
argument_list|)
block|;
name|lldb_private
operator|::
name|Error
name|RunShellCommand
argument_list|(
argument|const char *command
argument_list|,
comment|// Shouldn't be NULL
argument|const char *working_dir
argument_list|,
comment|// Pass NULL to use the current working directory
argument|int *status_ptr
argument_list|,
comment|// Pass NULL if you don't want the process exit status
argument|int *signo_ptr
argument_list|,
comment|// Pass NULL if you don't want the signal that caused the process to exit
argument|std::string *command_output
argument_list|,
comment|// Pass NULL if you don't want the command output
argument|uint32_t timeout_sec
argument_list|)
block|;
comment|// Timeout in seconds to wait for shell program to finish
name|bool
name|CalculateMD5
argument_list|(
specifier|const
name|lldb_private
operator|::
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
name|std
operator|::
name|string
name|HarmonizeThreadIdsForProfileData
argument_list|(
name|ProcessGDBRemote
operator|*
name|process
argument_list|,
name|StringExtractorGDBRemote
operator|&
name|inputStringExtractor
argument_list|)
block|;
name|bool
name|ReadRegister
argument_list|(
argument|lldb::tid_t tid
argument_list|,
argument|uint32_t reg_num
argument_list|,
argument|StringExtractorGDBRemote&response
argument_list|)
block|;
name|bool
name|ReadAllRegisters
argument_list|(
argument|lldb::tid_t tid
argument_list|,
argument|StringExtractorGDBRemote&response
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
name|protected
operator|:
name|PacketResult
name|SendPacketAndWaitForResponseNoLock
argument_list|(
argument|const char *payload
argument_list|,
argument|size_t payload_length
argument_list|,
argument|StringExtractorGDBRemote&response
argument_list|)
block|;
name|bool
name|GetCurrentProcessInfo
argument_list|()
block|;
comment|//------------------------------------------------------------------
comment|// Classes that inherit from GDBRemoteCommunicationClient can see and modify these
comment|//------------------------------------------------------------------
name|lldb_private
operator|::
name|LazyBool
name|m_supports_not_sending_acks
block|;
name|lldb_private
operator|::
name|LazyBool
name|m_supports_thread_suffix
block|;
name|lldb_private
operator|::
name|LazyBool
name|m_supports_threads_in_stop_reply
block|;
name|lldb_private
operator|::
name|LazyBool
name|m_supports_vCont_all
block|;
name|lldb_private
operator|::
name|LazyBool
name|m_supports_vCont_any
block|;
name|lldb_private
operator|::
name|LazyBool
name|m_supports_vCont_c
block|;
name|lldb_private
operator|::
name|LazyBool
name|m_supports_vCont_C
block|;
name|lldb_private
operator|::
name|LazyBool
name|m_supports_vCont_s
block|;
name|lldb_private
operator|::
name|LazyBool
name|m_supports_vCont_S
block|;
name|lldb_private
operator|::
name|LazyBool
name|m_qHostInfo_is_valid
block|;
name|lldb_private
operator|::
name|LazyBool
name|m_qProcessInfo_is_valid
block|;
name|lldb_private
operator|::
name|LazyBool
name|m_supports_alloc_dealloc_memory
block|;
name|lldb_private
operator|::
name|LazyBool
name|m_supports_memory_region_info
block|;
name|lldb_private
operator|::
name|LazyBool
name|m_supports_watchpoint_support_info
block|;
name|lldb_private
operator|::
name|LazyBool
name|m_supports_detach_stay_stopped
block|;
name|lldb_private
operator|::
name|LazyBool
name|m_watchpoints_trigger_after_instruction
block|;
name|lldb_private
operator|::
name|LazyBool
name|m_attach_or_wait_reply
block|;
name|lldb_private
operator|::
name|LazyBool
name|m_prepare_for_reg_writing_reply
block|;
name|lldb_private
operator|::
name|LazyBool
name|m_supports_p
block|;
name|lldb_private
operator|::
name|LazyBool
name|m_supports_QSaveRegisterState
block|;
name|lldb_private
operator|::
name|LazyBool
name|m_supports_qXfer_libraries_read
block|;
name|lldb_private
operator|::
name|LazyBool
name|m_supports_qXfer_libraries_svr4_read
block|;
name|lldb_private
operator|::
name|LazyBool
name|m_supports_augmented_libraries_svr4_read
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
block|;
name|lldb
operator|::
name|tid_t
name|m_curr_tid
block|;
comment|// Current gdb remote protocol thread index for all other operations
name|lldb
operator|::
name|tid_t
name|m_curr_tid_run
block|;
comment|// Current gdb remote protocol thread index for continue, step, etc
name|uint32_t
name|m_num_supported_hardware_watchpoints
block|;
comment|// If we need to send a packet while the target is running, the m_async_XXX
comment|// member variables take care of making this happen.
name|lldb_private
operator|::
name|Mutex
name|m_async_mutex
block|;
name|lldb_private
operator|::
name|Predicate
operator|<
name|bool
operator|>
name|m_async_packet_predicate
block|;
name|std
operator|::
name|string
name|m_async_packet
block|;
name|PacketResult
name|m_async_result
block|;
name|StringExtractorGDBRemote
name|m_async_response
block|;
name|int
name|m_async_signal
block|;
comment|// We were asked to deliver a signal to the inferior process.
name|bool
name|m_interrupt_sent
block|;
name|std
operator|::
name|string
name|m_partial_profile_data
block|;
name|std
operator|::
name|map
operator|<
name|uint64_t
block|,
name|uint32_t
operator|>
name|m_thread_id_to_used_usec_map
block|;
name|lldb_private
operator|::
name|ArchSpec
name|m_host_arch
block|;
name|lldb_private
operator|::
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
name|uint32_t
name|m_default_packet_timeout
block|;
name|uint64_t
name|m_max_packet_size
block|;
comment|// as returned by qSupported
name|bool
name|DecodeProcessInfoResponse
argument_list|(
name|StringExtractorGDBRemote
operator|&
name|response
argument_list|,
name|lldb_private
operator|::
name|ProcessInstanceInfo
operator|&
name|process_info
argument_list|)
block|;
name|private
operator|:
comment|//------------------------------------------------------------------
comment|// For GDBRemoteCommunicationClient only
comment|//------------------------------------------------------------------
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|GDBRemoteCommunicationClient
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_GDBRemoteCommunicationClient_h_
end_comment

end_unit

