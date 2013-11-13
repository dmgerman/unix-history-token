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
expr|enum
block|{
name|eBroadcastBitRunPacketSent
operator|=
name|kLoUserBroadcastBit
block|}
block|;
comment|//------------------------------------------------------------------
comment|// Constructors and Destructors
comment|//------------------------------------------------------------------
name|GDBRemoteCommunicationServer
argument_list|(
argument|bool is_platform
argument_list|)
block|;
name|virtual
operator|~
name|GDBRemoteCommunicationServer
argument_list|()
block|;
name|bool
name|GetPacketAndSendResponse
argument_list|(
argument|uint32_t timeout_usec
argument_list|,
argument|lldb_private::Error&error
argument_list|,
argument|bool&interrupt
argument_list|,
argument|bool&quit
argument_list|)
block|;
name|virtual
name|bool
name|GetThreadSuffixSupported
argument_list|()
block|{
return|return
name|true
return|;
block|}
comment|// After connecting, do a little handshake with the client to make sure
comment|// we are at least communicating
name|bool
name|HandshakeWithClient
argument_list|(
name|lldb_private
operator|::
name|Error
operator|*
name|error_ptr
argument_list|)
block|;
comment|// Set both ports to zero to let the platform automatically bind to
comment|// a port chosen by the OS.
name|void
name|SetPortRange
argument_list|(
argument|uint16_t lo_port_num
argument_list|,
argument|uint16_t hi_port_num
argument_list|)
block|{
name|m_lo_port_num
operator|=
name|lo_port_num
block|;
name|m_hi_port_num
operator|=
name|hi_port_num
block|;
name|m_next_port
operator|=
name|m_lo_port_num
block|;
name|m_use_port_range
operator|=
name|true
block|;     }
comment|// If we are using a port range, get and update the next port to be used variable.
comment|// Otherwise, just return 0.
name|uint16_t
name|GetAndUpdateNextPort
argument_list|()
block|{
if|if
condition|(
operator|!
name|m_use_port_range
condition|)
return|return
literal|0
return|;
name|uint16_t
name|val
operator|=
name|m_next_port
block|;
if|if
condition|(
operator|++
name|m_next_port
operator|>
name|m_hi_port_num
condition|)
name|m_next_port
operator|=
name|m_lo_port_num
expr_stmt|;
end_decl_stmt

begin_return
return|return
name|val
return|;
end_return

begin_comment
unit|}  protected:
comment|//typedef std::map<uint16_t, lldb::pid_t> PortToPIDMap;
end_comment

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
name|uint16_t
name|m_lo_port_num
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|uint16_t
name|m_hi_port_num
decl_stmt|;
end_decl_stmt

begin_comment
comment|//PortToPIDMap m_port_to_pid_map;
end_comment

begin_decl_stmt
name|uint16_t
name|m_next_port
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|m_use_port_range
decl_stmt|;
end_decl_stmt

begin_function_decl
name|size_t
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
name|size_t
name|SendErrorResponse
parameter_list|(
name|uint8_t
name|error
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|SendOKResponse
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|Handle_A
parameter_list|(
name|StringExtractorGDBRemote
modifier|&
name|packet
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|Handle_qLaunchSuccess
parameter_list|(
name|StringExtractorGDBRemote
modifier|&
name|packet
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|Handle_qHostInfo
parameter_list|(
name|StringExtractorGDBRemote
modifier|&
name|packet
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|Handle_qLaunchGDBServer
parameter_list|(
name|StringExtractorGDBRemote
modifier|&
name|packet
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|Handle_qKillSpawnedProcess
parameter_list|(
name|StringExtractorGDBRemote
modifier|&
name|packet
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|Handle_qPlatform_IO_MkDir
parameter_list|(
name|StringExtractorGDBRemote
modifier|&
name|packet
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|Handle_qProcessInfoPID
parameter_list|(
name|StringExtractorGDBRemote
modifier|&
name|packet
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|Handle_qfProcessInfo
parameter_list|(
name|StringExtractorGDBRemote
modifier|&
name|packet
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|Handle_qsProcessInfo
parameter_list|(
name|StringExtractorGDBRemote
modifier|&
name|packet
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|Handle_qC
parameter_list|(
name|StringExtractorGDBRemote
modifier|&
name|packet
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|Handle_qUserName
parameter_list|(
name|StringExtractorGDBRemote
modifier|&
name|packet
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|Handle_qGroupName
parameter_list|(
name|StringExtractorGDBRemote
modifier|&
name|packet
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|Handle_qSpeedTest
parameter_list|(
name|StringExtractorGDBRemote
modifier|&
name|packet
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|Handle_QEnvironment
parameter_list|(
name|StringExtractorGDBRemote
modifier|&
name|packet
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|Handle_QLaunchArch
parameter_list|(
name|StringExtractorGDBRemote
modifier|&
name|packet
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|Handle_QSetDisableASLR
parameter_list|(
name|StringExtractorGDBRemote
modifier|&
name|packet
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|Handle_QSetWorkingDir
parameter_list|(
name|StringExtractorGDBRemote
modifier|&
name|packet
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|Handle_QStartNoAckMode
parameter_list|(
name|StringExtractorGDBRemote
modifier|&
name|packet
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|Handle_QSetSTDIN
parameter_list|(
name|StringExtractorGDBRemote
modifier|&
name|packet
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|Handle_QSetSTDOUT
parameter_list|(
name|StringExtractorGDBRemote
modifier|&
name|packet
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|Handle_QSetSTDERR
parameter_list|(
name|StringExtractorGDBRemote
modifier|&
name|packet
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|Handle_vFile_Open
parameter_list|(
name|StringExtractorGDBRemote
modifier|&
name|packet
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|Handle_vFile_Close
parameter_list|(
name|StringExtractorGDBRemote
modifier|&
name|packet
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|Handle_vFile_pRead
parameter_list|(
name|StringExtractorGDBRemote
modifier|&
name|packet
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|Handle_vFile_pWrite
parameter_list|(
name|StringExtractorGDBRemote
modifier|&
name|packet
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|Handle_vFile_Size
parameter_list|(
name|StringExtractorGDBRemote
modifier|&
name|packet
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|Handle_vFile_Mode
parameter_list|(
name|StringExtractorGDBRemote
modifier|&
name|packet
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|Handle_vFile_Exists
parameter_list|(
name|StringExtractorGDBRemote
modifier|&
name|packet
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|Handle_vFile_Stat
parameter_list|(
name|StringExtractorGDBRemote
modifier|&
name|packet
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|Handle_vFile_MD5
parameter_list|(
name|StringExtractorGDBRemote
modifier|&
name|packet
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|Handle_qPlatform_RunCommand
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

