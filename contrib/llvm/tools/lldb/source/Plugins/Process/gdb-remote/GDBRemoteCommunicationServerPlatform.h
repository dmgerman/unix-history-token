begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- GDBRemoteCommunicationServerPlatform.h ------------------*- C++ -*-===//
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
name|liblldb_GDBRemoteCommunicationServerPlatform_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_GDBRemoteCommunicationServerPlatform_h_
end_define

begin_include
include|#
directive|include
file|"GDBRemoteCommunicationServerCommon.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|namespace
name|process_gdb_remote
block|{
name|class
name|GDBRemoteCommunicationServerPlatform
range|:
name|public
name|GDBRemoteCommunicationServerCommon
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
name|GDBRemoteCommunicationServerPlatform
argument_list|()
decl_stmt|;
name|virtual
operator|~
name|GDBRemoteCommunicationServerPlatform
argument_list|()
expr_stmt|;
name|Error
name|LaunchProcess
argument_list|()
name|override
expr_stmt|;
comment|// Set both ports to zero to let the platform automatically bind to
comment|// a port chosen by the OS.
name|void
name|SetPortMap
argument_list|(
name|PortMap
operator|&&
name|port_map
argument_list|)
decl_stmt|;
comment|//----------------------------------------------------------------------
comment|// If we are using a port map where we can only use certain ports,
comment|// get the next available port.
comment|//
comment|// If we are using a port map and we are out of ports, return UINT16_MAX
comment|//
comment|// If we aren't using a port map, return 0 to indicate we should bind to
comment|// port 0 and then figure out which port we used.
comment|//----------------------------------------------------------------------
name|uint16_t
name|GetNextAvailablePort
parameter_list|()
function_decl|;
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
decl_stmt|;
name|bool
name|FreePort
parameter_list|(
name|uint16_t
name|port
parameter_list|)
function_decl|;
name|bool
name|FreePortForProcess
argument_list|(
name|lldb
operator|::
name|pid_t
name|pid
argument_list|)
decl_stmt|;
name|void
name|SetPortOffset
parameter_list|(
name|uint16_t
name|port_offset
parameter_list|)
function_decl|;
name|protected
label|:
name|lldb
operator|::
name|PlatformSP
name|m_platform_sp
expr_stmt|;
name|PortMap
name|m_port_map
decl_stmt|;
name|uint16_t
name|m_port_offset
decl_stmt|;
name|PacketResult
name|Handle_qLaunchGDBServer
parameter_list|(
name|StringExtractorGDBRemote
modifier|&
name|packet
parameter_list|)
function_decl|;
name|PacketResult
name|Handle_qProcessInfo
parameter_list|(
name|StringExtractorGDBRemote
modifier|&
name|packet
parameter_list|)
function_decl|;
name|PacketResult
name|Handle_qGetWorkingDir
parameter_list|(
name|StringExtractorGDBRemote
modifier|&
name|packet
parameter_list|)
function_decl|;
name|PacketResult
name|Handle_QSetWorkingDir
parameter_list|(
name|StringExtractorGDBRemote
modifier|&
name|packet
parameter_list|)
function_decl|;
name|PacketResult
name|Handle_qC
parameter_list|(
name|StringExtractorGDBRemote
modifier|&
name|packet
parameter_list|)
function_decl|;
name|PacketResult
name|Handle_jSignalsInfo
parameter_list|(
name|StringExtractorGDBRemote
modifier|&
name|packet
parameter_list|)
function_decl|;
name|private
label|:
name|bool
name|DebugserverProcessReaped
argument_list|(
name|lldb
operator|::
name|pid_t
name|pid
argument_list|)
decl_stmt|;
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
comment|//------------------------------------------------------------------
comment|// For GDBRemoteCommunicationServerPlatform only
comment|//------------------------------------------------------------------
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|GDBRemoteCommunicationServerPlatform
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace process_gdb_remote
end_comment

begin_comment
unit|}
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_GDBRemoteCommunicationServerPlatform_h_
end_comment

end_unit

