begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- GDBRemoteTestUtils.h ------------------------------------*- C++ -*-===//
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
name|lldb_unittests_Process_gdb_remote_GDBRemoteTestUtils_h
end_ifndef

begin_define
define|#
directive|define
name|lldb_unittests_Process_gdb_remote_GDBRemoteTestUtils_h
end_define

begin_include
include|#
directive|include
file|"gtest/gtest.h"
end_include

begin_include
include|#
directive|include
file|"Plugins/Process/gdb-remote/GDBRemoteCommunicationServer.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|namespace
name|process_gdb_remote
block|{
name|class
name|GDBRemoteTest
range|:
name|public
name|testing
operator|::
name|Test
block|{
name|public
operator|:
specifier|static
name|void
name|SetUpTestCase
argument_list|()
block|;
specifier|static
name|void
name|TearDownTestCase
argument_list|()
block|;
name|protected
operator|:
name|llvm
operator|::
name|Error
name|Connect
argument_list|(
name|GDBRemoteCommunication
operator|&
name|client
argument_list|,
name|GDBRemoteCommunication
operator|&
name|server
argument_list|)
block|; }
decl_stmt|;
name|struct
name|MockServer
range|:
name|public
name|GDBRemoteCommunicationServer
block|{
name|MockServer
argument_list|()
operator|:
name|GDBRemoteCommunicationServer
argument_list|(
literal|"mock-server"
argument_list|,
literal|"mock-server.listener"
argument_list|)
block|{
name|m_send_acks
operator|=
name|false
block|;   }
name|PacketResult
name|SendPacket
argument_list|(
argument|llvm::StringRef payload
argument_list|)
block|{
return|return
name|GDBRemoteCommunicationServer
operator|::
name|SendPacketNoLock
argument_list|(
name|payload
argument_list|)
return|;
block|}
name|PacketResult
name|GetPacket
argument_list|(
argument|StringExtractorGDBRemote&response
argument_list|)
block|{
specifier|const
name|bool
name|sync_on_timeout
operator|=
name|false
block|;
return|return
name|WaitForPacketNoLock
argument_list|(
name|response
argument_list|,
name|std
operator|::
name|chrono
operator|::
name|seconds
argument_list|(
literal|1
argument_list|)
argument_list|,
name|sync_on_timeout
argument_list|)
return|;
block|}
name|using
name|GDBRemoteCommunicationServer
operator|::
name|SendOKResponse
block|;
name|using
name|GDBRemoteCommunicationServer
operator|::
name|SendUnimplementedResponse
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
comment|// lldb_unittests_Process_gdb_remote_GDBRemoteTestUtils_h
end_comment

end_unit

