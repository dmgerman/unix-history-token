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
file|<functional>
end_include

begin_include
include|#
directive|include
file|<map>
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
file|"GDBRemoteCommunication.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-private-forward.h"
end_include

begin_decl_stmt
name|class
name|StringExtractorGDBRemote
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|namespace
name|process_gdb_remote
block|{
name|class
name|ProcessGDBRemote
decl_stmt|;
name|class
name|GDBRemoteCommunicationServer
range|:
name|public
name|GDBRemoteCommunication
block|{
name|public
operator|:
name|using
name|PortMap
operator|=
name|std
operator|::
name|map
operator|<
name|uint16_t
block|,
name|lldb
operator|::
name|pid_t
operator|>
block|;
name|using
name|PacketHandler
operator|=
name|std
operator|::
name|function
operator|<
name|PacketResult
argument_list|(
name|StringExtractorGDBRemote
operator|&
name|packet
argument_list|,
name|Status
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
operator|>
block|;
name|GDBRemoteCommunicationServer
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
name|GDBRemoteCommunicationServer
argument_list|()
name|override
block|;
name|void
name|RegisterPacketHandler
argument_list|(
argument|StringExtractorGDBRemote::ServerPacketType packet_type
argument_list|,
argument|PacketHandler handler
argument_list|)
block|;
name|PacketResult
name|GetPacketAndSendResponse
argument_list|(
name|Timeout
operator|<
name|std
operator|::
name|micro
operator|>
name|timeout
argument_list|,
name|Status
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
block|;
comment|// After connecting, do a little handshake with the client to make sure
comment|// we are at least communicating
name|bool
name|HandshakeWithClient
argument_list|()
block|;
name|protected
operator|:
name|std
operator|::
name|map
operator|<
name|StringExtractorGDBRemote
operator|::
name|ServerPacketType
block|,
name|PacketHandler
operator|>
name|m_packet_handlers
block|;
name|bool
name|m_exit_now
block|;
comment|// use in asynchronous handling to indicate process should
comment|// exit.
name|PacketResult
name|SendUnimplementedResponse
argument_list|(
specifier|const
name|char
operator|*
name|packet
argument_list|)
block|;
name|PacketResult
name|SendErrorResponse
argument_list|(
argument|uint8_t error
argument_list|)
block|;
name|PacketResult
name|SendIllFormedResponse
argument_list|(
specifier|const
name|StringExtractorGDBRemote
operator|&
name|packet
argument_list|,
specifier|const
name|char
operator|*
name|error_message
argument_list|)
block|;
name|PacketResult
name|SendOKResponse
argument_list|()
block|;
name|private
operator|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|GDBRemoteCommunicationServer
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
comment|// liblldb_GDBRemoteCommunicationServer_h_
end_comment

end_unit

