begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- PlatformAndroidRemoteGDBServer.h ------------------------*- C++ -*-===//
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
name|liblldb_PlatformAndroidRemoteGDBServer_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_PlatformAndroidRemoteGDBServer_h_
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
file|<map>
end_include

begin_include
include|#
directive|include
file|<utility>
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
file|"Plugins/Platform/gdb-server/PlatformRemoteGDBServer.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Optional.h"
end_include

begin_include
include|#
directive|include
file|"AdbClient.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|namespace
name|platform_android
block|{
name|class
name|PlatformAndroidRemoteGDBServer
range|:
name|public
name|platform_gdb_server
operator|::
name|PlatformRemoteGDBServer
block|{
name|public
operator|:
name|PlatformAndroidRemoteGDBServer
argument_list|()
block|;
operator|~
name|PlatformAndroidRemoteGDBServer
argument_list|()
name|override
block|;
name|Status
name|ConnectRemote
argument_list|(
argument|Args&args
argument_list|)
name|override
block|;
name|Status
name|DisconnectRemote
argument_list|()
name|override
block|;
name|lldb
operator|::
name|ProcessSP
name|ConnectProcess
argument_list|(
argument|llvm::StringRef connect_url
argument_list|,
argument|llvm::StringRef plugin_name
argument_list|,
argument|lldb_private::Debugger&debugger
argument_list|,
argument|lldb_private::Target *target
argument_list|,
argument|lldb_private::Status&error
argument_list|)
name|override
block|;
name|protected
operator|:
name|std
operator|::
name|string
name|m_device_id
block|;
name|std
operator|::
name|map
operator|<
name|lldb
operator|::
name|pid_t
block|,
name|uint16_t
operator|>
name|m_port_forwards
block|;
name|llvm
operator|::
name|Optional
operator|<
name|AdbClient
operator|::
name|UnixSocketNamespace
operator|>
name|m_socket_namespace
block|;
name|bool
name|LaunchGDBServer
argument_list|(
argument|lldb::pid_t&pid
argument_list|,
argument|std::string&connect_url
argument_list|)
name|override
block|;
name|bool
name|KillSpawnedProcess
argument_list|(
argument|lldb::pid_t pid
argument_list|)
name|override
block|;
name|void
name|DeleteForwardPort
argument_list|(
argument|lldb::pid_t pid
argument_list|)
block|;
name|Status
name|MakeConnectURL
argument_list|(
argument|const lldb::pid_t pid
argument_list|,
argument|const uint16_t remote_port
argument_list|,
argument|llvm::StringRef remote_socket_name
argument_list|,
argument|std::string&connect_url
argument_list|)
block|;
name|private
operator|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|PlatformAndroidRemoteGDBServer
argument_list|)
block|; }
decl_stmt|;
block|}
comment|// namespace platform_android
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
comment|// liblldb_PlatformAndroidRemoteGDBServer_h_
end_comment

end_unit

