begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ConnectionFileDescriptorPosix.h -------------------------*- C++ -*-===//
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
name|liblldb_Host_posix_ConnectionFileDescriptorPosix_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_Host_posix_ConnectionFileDescriptorPosix_h_
end_define

begin_comment
comment|// C++ Includes
end_comment

begin_include
include|#
directive|include
file|<atomic>
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_include
include|#
directive|include
file|<mutex>
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-forward.h"
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
file|"lldb/Host/Pipe.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Host/Predicate.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/Connection.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/IOObject.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|Status
decl_stmt|;
name|class
name|Socket
decl_stmt|;
name|class
name|SocketAddress
decl_stmt|;
name|class
name|ConnectionFileDescriptor
range|:
name|public
name|Connection
block|{
name|public
operator|:
specifier|static
specifier|const
name|char
operator|*
name|LISTEN_SCHEME
block|;
specifier|static
specifier|const
name|char
operator|*
name|ACCEPT_SCHEME
block|;
specifier|static
specifier|const
name|char
operator|*
name|UNIX_ACCEPT_SCHEME
block|;
specifier|static
specifier|const
name|char
operator|*
name|CONNECT_SCHEME
block|;
specifier|static
specifier|const
name|char
operator|*
name|TCP_CONNECT_SCHEME
block|;
specifier|static
specifier|const
name|char
operator|*
name|UDP_SCHEME
block|;
specifier|static
specifier|const
name|char
operator|*
name|UNIX_CONNECT_SCHEME
block|;
specifier|static
specifier|const
name|char
operator|*
name|UNIX_ABSTRACT_CONNECT_SCHEME
block|;
specifier|static
specifier|const
name|char
operator|*
name|FD_SCHEME
block|;
specifier|static
specifier|const
name|char
operator|*
name|FILE_SCHEME
block|;
name|ConnectionFileDescriptor
argument_list|(
argument|bool child_processes_inherit = false
argument_list|)
block|;
name|ConnectionFileDescriptor
argument_list|(
argument|int fd
argument_list|,
argument|bool owns_fd
argument_list|)
block|;
name|ConnectionFileDescriptor
argument_list|(
name|Socket
operator|*
name|socket
argument_list|)
block|;
operator|~
name|ConnectionFileDescriptor
argument_list|()
name|override
block|;
name|bool
name|IsConnected
argument_list|()
specifier|const
name|override
block|;
name|lldb
operator|::
name|ConnectionStatus
name|Connect
argument_list|(
argument|llvm::StringRef s
argument_list|,
argument|Status *error_ptr
argument_list|)
name|override
block|;
name|lldb
operator|::
name|ConnectionStatus
name|Disconnect
argument_list|(
argument|Status *error_ptr
argument_list|)
name|override
block|;
name|size_t
name|Read
argument_list|(
argument|void *dst
argument_list|,
argument|size_t dst_len
argument_list|,
argument|const Timeout<std::micro>&timeout
argument_list|,
argument|lldb::ConnectionStatus&status
argument_list|,
argument|Status *error_ptr
argument_list|)
name|override
block|;
name|size_t
name|Write
argument_list|(
argument|const void *src
argument_list|,
argument|size_t src_len
argument_list|,
argument|lldb::ConnectionStatus&status
argument_list|,
argument|Status *error_ptr
argument_list|)
name|override
block|;
name|std
operator|::
name|string
name|GetURI
argument_list|()
name|override
block|;
name|lldb
operator|::
name|ConnectionStatus
name|BytesAvailable
argument_list|(
specifier|const
name|Timeout
operator|<
name|std
operator|::
name|micro
operator|>
operator|&
name|timeout
argument_list|,
name|Status
operator|*
name|error_ptr
argument_list|)
block|;
name|bool
name|InterruptRead
argument_list|()
name|override
block|;
name|lldb
operator|::
name|IOObjectSP
name|GetReadObject
argument_list|()
name|override
block|{
return|return
name|m_read_sp
return|;
block|}
name|uint16_t
name|GetListeningPort
argument_list|(
argument|uint32_t timeout_sec
argument_list|)
block|;
name|bool
name|GetChildProcessesInherit
argument_list|()
specifier|const
block|;
name|void
name|SetChildProcessesInherit
argument_list|(
argument|bool child_processes_inherit
argument_list|)
block|;
name|protected
operator|:
name|void
name|OpenCommandPipe
argument_list|()
block|;
name|void
name|CloseCommandPipe
argument_list|()
block|;
name|lldb
operator|::
name|ConnectionStatus
name|SocketListenAndAccept
argument_list|(
argument|llvm::StringRef host_and_port
argument_list|,
argument|Status *error_ptr
argument_list|)
block|;
name|lldb
operator|::
name|ConnectionStatus
name|ConnectTCP
argument_list|(
argument|llvm::StringRef host_and_port
argument_list|,
argument|Status *error_ptr
argument_list|)
block|;
name|lldb
operator|::
name|ConnectionStatus
name|ConnectUDP
argument_list|(
argument|llvm::StringRef args
argument_list|,
argument|Status *error_ptr
argument_list|)
block|;
name|lldb
operator|::
name|ConnectionStatus
name|NamedSocketConnect
argument_list|(
argument|llvm::StringRef socket_name
argument_list|,
argument|Status *error_ptr
argument_list|)
block|;
name|lldb
operator|::
name|ConnectionStatus
name|NamedSocketAccept
argument_list|(
argument|llvm::StringRef socket_name
argument_list|,
argument|Status *error_ptr
argument_list|)
block|;
name|lldb
operator|::
name|ConnectionStatus
name|UnixAbstractSocketConnect
argument_list|(
argument|llvm::StringRef socket_name
argument_list|,
argument|Status *error_ptr
argument_list|)
block|;
name|lldb
operator|::
name|IOObjectSP
name|m_read_sp
block|;
name|lldb
operator|::
name|IOObjectSP
name|m_write_sp
block|;
name|Predicate
operator|<
name|uint16_t
operator|>
name|m_port_predicate
block|;
comment|// Used when binding to port zero to wait for the thread
comment|// that creates the socket, binds and listens to resolve
comment|// the port number.
name|Pipe
name|m_pipe
block|;
name|std
operator|::
name|recursive_mutex
name|m_mutex
block|;
name|std
operator|::
name|atomic
operator|<
name|bool
operator|>
name|m_shutting_down
block|;
comment|// This marks that we are shutting down so
comment|// if we get woken up from
comment|// BytesAvailable to disconnect, we won't try to read again.
name|bool
name|m_waiting_for_accept
block|;
name|bool
name|m_child_processes_inherit
block|;
name|std
operator|::
name|string
name|m_uri
block|;
name|private
operator|:
name|void
name|InitializeSocket
argument_list|(
name|Socket
operator|*
name|socket
argument_list|)
block|;
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|ConnectionFileDescriptor
argument_list|)
block|; }
decl_stmt|;
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
comment|// liblldb_ConnectionFileDescriptor_h_
end_comment

end_unit

