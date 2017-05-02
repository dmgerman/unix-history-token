begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- TCPSocket.h ---------------------------------------------*- C++ -*-===//
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
name|liblldb_TCPSocket_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_TCPSocket_h_
end_define

begin_include
include|#
directive|include
file|"lldb/Host/Socket.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Host/SocketAddress.h"
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|TCPSocket
range|:
name|public
name|Socket
block|{
name|public
operator|:
name|TCPSocket
argument_list|(
argument|bool should_close
argument_list|,
argument|bool child_processes_inherit
argument_list|)
block|;
name|TCPSocket
argument_list|(
argument|NativeSocket socket
argument_list|,
argument|bool should_close
argument_list|,
argument|bool child_processes_inherit
argument_list|)
block|;
operator|~
name|TCPSocket
argument_list|()
name|override
block|;
comment|// returns port number or 0 if error
name|uint16_t
name|GetLocalPortNumber
argument_list|()
specifier|const
block|;
comment|// returns ip address string or empty string if error
name|std
operator|::
name|string
name|GetLocalIPAddress
argument_list|()
specifier|const
block|;
comment|// must be connected
comment|// returns port number or 0 if error
name|uint16_t
name|GetRemotePortNumber
argument_list|()
specifier|const
block|;
comment|// must be connected
comment|// returns ip address string or empty string if error
name|std
operator|::
name|string
name|GetRemoteIPAddress
argument_list|()
specifier|const
block|;
name|int
name|SetOptionNoDelay
argument_list|()
block|;
name|int
name|SetOptionReuseAddress
argument_list|()
block|;
name|Error
name|Connect
argument_list|(
argument|llvm::StringRef name
argument_list|)
name|override
block|;
name|Error
name|Listen
argument_list|(
argument|llvm::StringRef name
argument_list|,
argument|int backlog
argument_list|)
name|override
block|;
name|Error
name|Accept
argument_list|(
argument|Socket *&conn_socket
argument_list|)
name|override
block|;
name|Error
name|CreateSocket
argument_list|(
argument|int domain
argument_list|)
block|;
name|bool
name|IsValid
argument_list|()
specifier|const
name|override
block|;
name|private
operator|:
name|TCPSocket
argument_list|(
argument|NativeSocket socket
argument_list|,
argument|const TCPSocket&listen_socket
argument_list|)
block|;
name|void
name|CloseListenSockets
argument_list|()
block|;
name|std
operator|::
name|map
operator|<
name|int
block|,
name|SocketAddress
operator|>
name|m_listen_sockets
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// ifndef liblldb_TCPSocket_h_
end_comment

end_unit

