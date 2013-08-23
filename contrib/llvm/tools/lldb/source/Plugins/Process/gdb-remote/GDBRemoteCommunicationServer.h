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
block|;     }
name|protected
operator|:
comment|//typedef std::map<uint16_t, lldb::pid_t> PortToPIDMap;
name|lldb
operator|::
name|thread_t
name|m_async_thread
block|;
name|lldb_private
operator|::
name|ProcessLaunchInfo
name|m_process_launch_info
block|;
name|lldb_private
operator|::
name|Error
name|m_process_launch_error
block|;
name|lldb_private
operator|::
name|ProcessInstanceInfoList
name|m_proc_infos
block|;
name|uint32_t
name|m_proc_infos_index
block|;
name|uint16_t
name|m_lo_port_num
block|;
name|uint16_t
name|m_hi_port_num
block|;
comment|//PortToPIDMap m_port_to_pid_map;
name|size_t
name|SendUnimplementedResponse
argument_list|(
specifier|const
name|char
operator|*
name|packet
argument_list|)
block|;
name|size_t
name|SendErrorResponse
argument_list|(
argument|uint8_t error
argument_list|)
block|;
name|size_t
name|SendOKResponse
argument_list|()
block|;
name|bool
name|Handle_A
argument_list|(
name|StringExtractorGDBRemote
operator|&
name|packet
argument_list|)
block|;
name|bool
name|Handle_qLaunchSuccess
argument_list|(
name|StringExtractorGDBRemote
operator|&
name|packet
argument_list|)
block|;
name|bool
name|Handle_qHostInfo
argument_list|(
name|StringExtractorGDBRemote
operator|&
name|packet
argument_list|)
block|;
name|bool
name|Handle_qLaunchGDBServer
argument_list|(
name|StringExtractorGDBRemote
operator|&
name|packet
argument_list|)
block|;
name|bool
name|Handle_qProcessInfoPID
argument_list|(
name|StringExtractorGDBRemote
operator|&
name|packet
argument_list|)
block|;
name|bool
name|Handle_qfProcessInfo
argument_list|(
name|StringExtractorGDBRemote
operator|&
name|packet
argument_list|)
block|;
name|bool
name|Handle_qsProcessInfo
argument_list|(
name|StringExtractorGDBRemote
operator|&
name|packet
argument_list|)
block|;
name|bool
name|Handle_qC
argument_list|(
name|StringExtractorGDBRemote
operator|&
name|packet
argument_list|)
block|;
name|bool
name|Handle_qUserName
argument_list|(
name|StringExtractorGDBRemote
operator|&
name|packet
argument_list|)
block|;
name|bool
name|Handle_qGroupName
argument_list|(
name|StringExtractorGDBRemote
operator|&
name|packet
argument_list|)
block|;
name|bool
name|Handle_qSpeedTest
argument_list|(
name|StringExtractorGDBRemote
operator|&
name|packet
argument_list|)
block|;
name|bool
name|Handle_QEnvironment
argument_list|(
name|StringExtractorGDBRemote
operator|&
name|packet
argument_list|)
block|;
name|bool
name|Handle_QSetDisableASLR
argument_list|(
name|StringExtractorGDBRemote
operator|&
name|packet
argument_list|)
block|;
name|bool
name|Handle_QSetWorkingDir
argument_list|(
name|StringExtractorGDBRemote
operator|&
name|packet
argument_list|)
block|;
name|bool
name|Handle_QStartNoAckMode
argument_list|(
name|StringExtractorGDBRemote
operator|&
name|packet
argument_list|)
block|;
name|bool
name|Handle_QSetSTDIN
argument_list|(
name|StringExtractorGDBRemote
operator|&
name|packet
argument_list|)
block|;
name|bool
name|Handle_QSetSTDOUT
argument_list|(
name|StringExtractorGDBRemote
operator|&
name|packet
argument_list|)
block|;
name|bool
name|Handle_QSetSTDERR
argument_list|(
name|StringExtractorGDBRemote
operator|&
name|packet
argument_list|)
block|;
name|private
operator|:
comment|//------------------------------------------------------------------
comment|// For GDBRemoteCommunicationServer only
comment|//------------------------------------------------------------------
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|GDBRemoteCommunicationServer
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_GDBRemoteCommunicationServer_h_
end_comment

end_unit

