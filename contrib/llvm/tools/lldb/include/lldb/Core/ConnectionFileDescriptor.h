begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ConnectionFileDescriptor.h ------------------------------*- C++ -*-===//
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
name|liblldb_ConnectionFileDescriptor_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ConnectionFileDescriptor_h_
end_define

begin_comment
comment|// C Includes
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_WIN32
end_ifndef

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// C++ Includes
end_comment

begin_include
include|#
directive|include
file|<memory>
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
file|"lldb/Core/Connection.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Host/Mutex.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Host/Predicate.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
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
name|ConnectionFileDescriptor
argument_list|()
block|;
name|ConnectionFileDescriptor
argument_list|(
argument|int fd
argument_list|,
argument|bool owns_fd
argument_list|)
block|;
name|virtual
operator|~
name|ConnectionFileDescriptor
argument_list|()
block|;
name|virtual
name|bool
name|IsConnected
argument_list|()
specifier|const
block|;
name|virtual
name|lldb
operator|::
name|ConnectionStatus
name|Connect
argument_list|(
specifier|const
name|char
operator|*
name|s
argument_list|,
name|Error
operator|*
name|error_ptr
argument_list|)
block|;
name|virtual
name|lldb
operator|::
name|ConnectionStatus
name|Disconnect
argument_list|(
name|Error
operator|*
name|error_ptr
argument_list|)
block|;
name|virtual
name|size_t
name|Read
argument_list|(
argument|void *dst
argument_list|,
argument|size_t dst_len
argument_list|,
argument|uint32_t timeout_usec
argument_list|,
argument|lldb::ConnectionStatus&status
argument_list|,
argument|Error *error_ptr
argument_list|)
block|;
name|virtual
name|size_t
name|Write
argument_list|(
argument|const void *src
argument_list|,
argument|size_t src_len
argument_list|,
argument|lldb::ConnectionStatus&status
argument_list|,
argument|Error *error_ptr
argument_list|)
block|;
comment|// If the read file descriptor is a socket, then return
comment|// the port number that is being used by the socket.
name|uint16_t
name|GetReadPort
argument_list|()
specifier|const
block|;
comment|// If the write file descriptor is a socket, then return
comment|// the port number that is being used by the socket.
name|uint16_t
name|GetWritePort
argument_list|()
specifier|const
block|;
name|uint16_t
name|GetBoundPort
argument_list|(
argument|uint32_t timeout_sec
argument_list|)
block|;
name|protected
operator|:
typedef|typedef
enum|enum
block|{
name|eFDTypeFile
block|,
comment|// Other FD requireing read/write
name|eFDTypeSocket
block|,
comment|// Socket requiring send/recv
name|eFDTypeSocketUDP
comment|// Unconnected UDP socket requiring sendto/recvfrom
decl|}
name|FDType
empty_stmt|;
name|void
name|OpenCommandPipe
parameter_list|()
function_decl|;
name|void
name|CloseCommandPipe
parameter_list|()
function_decl|;
name|lldb
decl|::
name|ConnectionStatus
name|BytesAvailable
argument_list|(
name|uint32_t
name|timeout_usec
argument_list|,
name|Error
operator|*
name|error_ptr
argument_list|)
empty_stmt|;
name|lldb
decl|::
name|ConnectionStatus
name|SocketListen
argument_list|(
specifier|const
name|char
operator|*
name|host_and_port
argument_list|,
name|Error
operator|*
name|error_ptr
argument_list|)
empty_stmt|;
name|lldb
decl|::
name|ConnectionStatus
name|ConnectTCP
argument_list|(
specifier|const
name|char
operator|*
name|host_and_port
argument_list|,
name|Error
operator|*
name|error_ptr
argument_list|)
empty_stmt|;
name|lldb
decl|::
name|ConnectionStatus
name|ConnectUDP
argument_list|(
specifier|const
name|char
operator|*
name|args
argument_list|,
name|Error
operator|*
name|error_ptr
argument_list|)
empty_stmt|;
name|lldb
decl|::
name|ConnectionStatus
name|NamedSocketAccept
argument_list|(
specifier|const
name|char
operator|*
name|socket_name
argument_list|,
name|Error
operator|*
name|error_ptr
argument_list|)
empty_stmt|;
name|lldb
decl|::
name|ConnectionStatus
name|NamedSocketConnect
argument_list|(
specifier|const
name|char
operator|*
name|socket_name
argument_list|,
name|Error
operator|*
name|error_ptr
argument_list|)
empty_stmt|;
name|lldb
decl|::
name|ConnectionStatus
name|Close
argument_list|(
name|int
operator|&
name|fd
argument_list|,
name|FDType
name|type
argument_list|,
name|Error
operator|*
name|error
argument_list|)
empty_stmt|;
name|int
name|m_fd_send
block|;
name|int
name|m_fd_recv
block|;
name|FDType
name|m_fd_send_type
block|;
name|FDType
name|m_fd_recv_type
block|;
name|std
decl|::
name|unique_ptr
decl|<
name|SocketAddress
decl|>
name|m_udp_send_sockaddr
empty_stmt|;
name|uint32_t
name|m_socket_timeout_usec
block|;
name|int
name|m_pipe_read
block|;
comment|// A pipe that we select on the reading end of along with
name|int
name|m_pipe_write
block|;
comment|// m_fd_recv so we can force ourselves out of the select.
name|Mutex
name|m_mutex
block|;
name|Predicate
decl|<
name|uint16_t
decl|>
name|m_port_predicate
empty_stmt|;
comment|// Used when binding to port zero to wait for the thread that creates the socket, binds and listens to resolve the port number
name|bool
name|m_should_close_fd
block|;
comment|// True if this class should close the file descriptor when it goes away.
name|bool
name|m_shutting_down
block|;
comment|// This marks that we are shutting down so if we get woken up from BytesAvailable
comment|// to disconnect, we won't try to read again.
specifier|static
name|uint16_t
name|GetSocketPort
parameter_list|(
name|int
name|fd
parameter_list|)
function_decl|;
specifier|static
name|int
name|GetSocketOption
parameter_list|(
name|int
name|fd
parameter_list|,
name|int
name|level
parameter_list|,
name|int
name|option_name
parameter_list|,
name|int
modifier|&
name|option_value
parameter_list|)
function_decl|;
specifier|static
name|int
name|SetSocketOption
parameter_list|(
name|int
name|fd
parameter_list|,
name|int
name|level
parameter_list|,
name|int
name|option_name
parameter_list|,
name|int
name|option_value
parameter_list|)
function_decl|;
name|bool
name|SetSocketReceiveTimeout
parameter_list|(
name|uint32_t
name|timeout_usec
parameter_list|)
function_decl|;
name|private
label|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|ConnectionFileDescriptor
argument_list|)
empty_stmt|;
block|}
enum|;
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

