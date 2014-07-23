begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- GDBRemoteCommunicationServer.h --------------------------*- C++ -*-===//
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
name|liblldb_GDBRemoteCommunicationServer_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_GDBRemoteCommunicationServer_h_
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

begin_include
include|#
directive|include
file|<set>
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
file|"lldb/Host/Mutex.h"
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

begin_decl_stmt
name|class
name|ProcessGDBRemote
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|StringExtractorGDBRemote
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|GDBRemoteCommunicationServer
range|:
name|public
name|GDBRemoteCommunication
block|{
name|public
operator|:
typedef|typedef
name|std
operator|::
name|map
operator|<
name|uint16_t
operator|,
name|lldb
operator|::
name|pid_t
operator|>
name|PortMap
expr_stmt|;
block|enum
block|{
name|eBroadcastBitRunPacketSent
operator|=
name|kLoUserBroadcastBit
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|// Constructors and Destructors
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_macro
name|GDBRemoteCommunicationServer
argument_list|(
argument|bool is_platform
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|GDBRemoteCommunicationServer
argument_list|(
argument|bool is_platform
argument_list|,
argument|const lldb::PlatformSP& platform_sp
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|virtual
operator|~
name|GDBRemoteCommunicationServer
argument_list|()
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|bool
name|GetPacketAndSendResponse
argument_list|(
name|uint32_t
name|timeout_usec
argument_list|,
name|lldb_private
operator|::
name|Error
operator|&
name|error
argument_list|,
name|bool
operator|&
name|interrupt
argument_list|,
name|bool
operator|&
name|quit
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
name|virtual
name|bool
name|GetThreadSuffixSupported
parameter_list|()
block|{
return|return
name|true
return|;
block|}
end_function

begin_comment
comment|// After connecting, do a little handshake with the client to make sure
end_comment

begin_comment
comment|// we are at least communicating
end_comment

begin_decl_stmt
name|bool
name|HandshakeWithClient
argument_list|(
name|lldb_private
operator|::
name|Error
operator|*
name|error_ptr
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Set both ports to zero to let the platform automatically bind to
end_comment

begin_comment
comment|// a port chosen by the OS.
end_comment

begin_decl_stmt
name|void
name|SetPortMap
argument_list|(
name|PortMap
operator|&&
name|port_map
argument_list|)
block|{
name|m_port_map
operator|=
name|port_map
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_comment
comment|// If we are using a port map where we can only use certain ports,
end_comment

begin_comment
comment|// get the next available port.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// If we are using a port map and we are out of ports, return UINT16_MAX
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// If we aren't using a port map, return 0 to indicate we should bind to
end_comment

begin_comment
comment|// port 0 and then figure out which port we used.
end_comment

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_function
name|uint16_t
name|GetNextAvailablePort
parameter_list|()
block|{
if|if
condition|(
name|m_port_map
operator|.
name|empty
argument_list|()
condition|)
return|return
literal|0
return|;
comment|// Bind to port zero and get a port, we didn't have any limitations
for|for
control|(
name|auto
operator|&
name|pair
operator|:
name|m_port_map
control|)
block|{
if|if
condition|(
name|pair
operator|.
name|second
operator|==
name|LLDB_INVALID_PROCESS_ID
condition|)
block|{
name|pair
operator|.
name|second
operator|=
operator|~
operator|(
name|lldb
operator|::
name|pid_t
operator|)
name|LLDB_INVALID_PROCESS_ID
expr_stmt|;
return|return
name|pair
operator|.
name|first
return|;
block|}
block|}
return|return
name|UINT16_MAX
return|;
block|}
end_function

begin_decl_stmt
name|bool
name|AssociatePortWithProcess
argument_list|(
name|uint16_t
name|port
argument_list|,
name|lldb
operator|::
name|pid_t
name|pid
argument_list|)
block|{
name|PortMap
operator|::
name|iterator
name|pos
operator|=
name|m_port_map
operator|.
name|find
argument_list|(
name|port
argument_list|)
expr_stmt|;
if|if
condition|(
name|pos
operator|!=
name|m_port_map
operator|.
name|end
argument_list|()
condition|)
block|{
name|pos
operator|->
name|second
operator|=
name|pid
expr_stmt|;
return|return
name|true
return|;
block|}
return|return
name|false
return|;
block|}
end_decl_stmt

begin_function
name|bool
name|FreePort
parameter_list|(
name|uint16_t
name|port
parameter_list|)
block|{
name|PortMap
operator|::
name|iterator
name|pos
operator|=
name|m_port_map
operator|.
name|find
argument_list|(
name|port
argument_list|)
expr_stmt|;
if|if
condition|(
name|pos
operator|!=
name|m_port_map
operator|.
name|end
argument_list|()
condition|)
block|{
name|pos
operator|->
name|second
operator|=
name|LLDB_INVALID_PROCESS_ID
expr_stmt|;
return|return
name|true
return|;
block|}
return|return
name|false
return|;
block|}
end_function

begin_decl_stmt
name|bool
name|FreePortForProcess
argument_list|(
name|lldb
operator|::
name|pid_t
name|pid
argument_list|)
block|{
if|if
condition|(
operator|!
name|m_port_map
operator|.
name|empty
argument_list|()
condition|)
block|{
for|for
control|(
name|auto
operator|&
name|pair
operator|:
name|m_port_map
control|)
block|{
if|if
condition|(
name|pair
operator|.
name|second
operator|==
name|pid
condition|)
block|{
name|pair
operator|.
name|second
operator|=
name|LLDB_INVALID_PROCESS_ID
expr_stmt|;
return|return
name|true
return|;
block|}
block|}
block|}
return|return
name|false
return|;
block|}
end_decl_stmt

begin_function
name|void
name|SetPortOffset
parameter_list|(
name|uint16_t
name|port_offset
parameter_list|)
block|{
name|m_port_offset
operator|=
name|port_offset
expr_stmt|;
block|}
end_function

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|/// Specify the program to launch and its arguments.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The LaunchProcess () command can be executed to do the lauching.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param[in] args
end_comment

begin_comment
comment|///     The command line to launch.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param[in] argc
end_comment

begin_comment
comment|///     The number of elements in the args array of cstring pointers.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @return
end_comment

begin_comment
comment|///     An Error object indicating the success or failure of making
end_comment

begin_comment
comment|///     the setting.
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_expr_stmt
name|lldb_private
operator|::
name|Error
name|SetLaunchArguments
argument_list|(
argument|const char *const args[]
argument_list|,
argument|int argc
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|/// Specify the launch flags for the process.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The LaunchProcess () command can be executed to do the lauching.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param[in] launch_flags
end_comment

begin_comment
comment|///     The launch flags to use when launching this process.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @return
end_comment

begin_comment
comment|///     An Error object indicating the success or failure of making
end_comment

begin_comment
comment|///     the setting.
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_expr_stmt
name|lldb_private
operator|::
name|Error
name|SetLaunchFlags
argument_list|(
argument|unsigned int launch_flags
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|/// Launch a process with the current launch settings.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This method supports running an lldb-gdbserver or similar
end_comment

begin_comment
comment|/// server in a situation where the startup code has been provided
end_comment

begin_comment
comment|/// with all the information for a child process to be launched.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @return
end_comment

begin_comment
comment|///     An Error object indicating the success or failure of the
end_comment

begin_comment
comment|///     launch.
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_expr_stmt
name|lldb_private
operator|::
name|Error
name|LaunchProcess
argument_list|()
expr_stmt|;
end_expr_stmt

begin_label
name|protected
label|:
end_label

begin_expr_stmt
name|lldb
operator|::
name|PlatformSP
name|m_platform_sp
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|lldb
operator|::
name|thread_t
name|m_async_thread
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|lldb_private
operator|::
name|ProcessLaunchInfo
name|m_process_launch_info
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|lldb_private
operator|::
name|Error
name|m_process_launch_error
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|set
operator|<
name|lldb
operator|::
name|pid_t
operator|>
name|m_spawned_pids
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|lldb_private
operator|::
name|Mutex
name|m_spawned_pids_mutex
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|lldb_private
operator|::
name|ProcessInstanceInfoList
name|m_proc_infos
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|uint32_t
name|m_proc_infos_index
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|PortMap
name|m_port_map
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|uint16_t
name|m_port_offset
decl_stmt|;
end_decl_stmt

begin_function_decl
name|PacketResult
name|SendUnimplementedResponse
parameter_list|(
specifier|const
name|char
modifier|*
name|packet
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|PacketResult
name|SendErrorResponse
parameter_list|(
name|uint8_t
name|error
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|PacketResult
name|SendOKResponse
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|PacketResult
name|Handle_A
parameter_list|(
name|StringExtractorGDBRemote
modifier|&
name|packet
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|PacketResult
name|Handle_qLaunchSuccess
parameter_list|(
name|StringExtractorGDBRemote
modifier|&
name|packet
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|PacketResult
name|Handle_qHostInfo
parameter_list|(
name|StringExtractorGDBRemote
modifier|&
name|packet
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|PacketResult
name|Handle_qLaunchGDBServer
parameter_list|(
name|StringExtractorGDBRemote
modifier|&
name|packet
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|PacketResult
name|Handle_qKillSpawnedProcess
parameter_list|(
name|StringExtractorGDBRemote
modifier|&
name|packet
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|PacketResult
name|Handle_k
parameter_list|(
name|StringExtractorGDBRemote
modifier|&
name|packet
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|PacketResult
name|Handle_qPlatform_mkdir
parameter_list|(
name|StringExtractorGDBRemote
modifier|&
name|packet
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|PacketResult
name|Handle_qPlatform_chmod
parameter_list|(
name|StringExtractorGDBRemote
modifier|&
name|packet
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|PacketResult
name|Handle_qProcessInfoPID
parameter_list|(
name|StringExtractorGDBRemote
modifier|&
name|packet
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|PacketResult
name|Handle_qfProcessInfo
parameter_list|(
name|StringExtractorGDBRemote
modifier|&
name|packet
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|PacketResult
name|Handle_qsProcessInfo
parameter_list|(
name|StringExtractorGDBRemote
modifier|&
name|packet
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|PacketResult
name|Handle_qC
parameter_list|(
name|StringExtractorGDBRemote
modifier|&
name|packet
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|PacketResult
name|Handle_qUserName
parameter_list|(
name|StringExtractorGDBRemote
modifier|&
name|packet
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|PacketResult
name|Handle_qGroupName
parameter_list|(
name|StringExtractorGDBRemote
modifier|&
name|packet
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|PacketResult
name|Handle_qSpeedTest
parameter_list|(
name|StringExtractorGDBRemote
modifier|&
name|packet
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|PacketResult
name|Handle_QEnvironment
parameter_list|(
name|StringExtractorGDBRemote
modifier|&
name|packet
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|PacketResult
name|Handle_QLaunchArch
parameter_list|(
name|StringExtractorGDBRemote
modifier|&
name|packet
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|PacketResult
name|Handle_QSetDisableASLR
parameter_list|(
name|StringExtractorGDBRemote
modifier|&
name|packet
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|PacketResult
name|Handle_QSetWorkingDir
parameter_list|(
name|StringExtractorGDBRemote
modifier|&
name|packet
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|PacketResult
name|Handle_qGetWorkingDir
parameter_list|(
name|StringExtractorGDBRemote
modifier|&
name|packet
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|PacketResult
name|Handle_QStartNoAckMode
parameter_list|(
name|StringExtractorGDBRemote
modifier|&
name|packet
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|PacketResult
name|Handle_QSetSTDIN
parameter_list|(
name|StringExtractorGDBRemote
modifier|&
name|packet
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|PacketResult
name|Handle_QSetSTDOUT
parameter_list|(
name|StringExtractorGDBRemote
modifier|&
name|packet
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|PacketResult
name|Handle_QSetSTDERR
parameter_list|(
name|StringExtractorGDBRemote
modifier|&
name|packet
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|PacketResult
name|Handle_vFile_Open
parameter_list|(
name|StringExtractorGDBRemote
modifier|&
name|packet
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|PacketResult
name|Handle_vFile_Close
parameter_list|(
name|StringExtractorGDBRemote
modifier|&
name|packet
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|PacketResult
name|Handle_vFile_pRead
parameter_list|(
name|StringExtractorGDBRemote
modifier|&
name|packet
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|PacketResult
name|Handle_vFile_pWrite
parameter_list|(
name|StringExtractorGDBRemote
modifier|&
name|packet
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|PacketResult
name|Handle_vFile_Size
parameter_list|(
name|StringExtractorGDBRemote
modifier|&
name|packet
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|PacketResult
name|Handle_vFile_Mode
parameter_list|(
name|StringExtractorGDBRemote
modifier|&
name|packet
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|PacketResult
name|Handle_vFile_Exists
parameter_list|(
name|StringExtractorGDBRemote
modifier|&
name|packet
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|PacketResult
name|Handle_vFile_symlink
parameter_list|(
name|StringExtractorGDBRemote
modifier|&
name|packet
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|PacketResult
name|Handle_vFile_unlink
parameter_list|(
name|StringExtractorGDBRemote
modifier|&
name|packet
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|PacketResult
name|Handle_vFile_Stat
parameter_list|(
name|StringExtractorGDBRemote
modifier|&
name|packet
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|PacketResult
name|Handle_vFile_MD5
parameter_list|(
name|StringExtractorGDBRemote
modifier|&
name|packet
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|PacketResult
name|Handle_qPlatform_shell
parameter_list|(
name|StringExtractorGDBRemote
modifier|&
name|packet
parameter_list|)
function_decl|;
end_function_decl

begin_label
name|private
label|:
end_label

begin_decl_stmt
name|bool
name|DebugserverProcessReaped
argument_list|(
name|lldb
operator|::
name|pid_t
name|pid
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|bool
name|ReapDebugserverProcess
argument_list|(
name|void
operator|*
name|callback_baton
argument_list|,
name|lldb
operator|::
name|pid_t
name|pid
argument_list|,
name|bool
name|exited
argument_list|,
name|int
name|signal
argument_list|,
name|int
name|status
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|DebuggedProcessReaped
argument_list|(
name|lldb
operator|::
name|pid_t
name|pid
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|bool
name|ReapDebuggedProcess
argument_list|(
name|void
operator|*
name|callback_baton
argument_list|,
name|lldb
operator|::
name|pid_t
name|pid
argument_list|,
name|bool
name|exited
argument_list|,
name|int
name|signal
argument_list|,
name|int
name|status
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|KillSpawnedProcess
argument_list|(
name|lldb
operator|::
name|pid_t
name|pid
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|// For GDBRemoteCommunicationServer only
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_expr_stmt
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|GDBRemoteCommunicationServer
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
unit|};
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_GDBRemoteCommunicationServer_h_
end_comment

end_unit

