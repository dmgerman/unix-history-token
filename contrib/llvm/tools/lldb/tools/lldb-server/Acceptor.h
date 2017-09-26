begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Acceptor.h ----------------------------------------------*- C++ -*-===//
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
name|lldb_server_Acceptor_h_
end_ifndef

begin_define
define|#
directive|define
name|lldb_server_Acceptor_h_
end_define

begin_include
include|#
directive|include
file|"lldb/Host/Socket.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/Connection.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/Status.h"
end_include

begin_include
include|#
directive|include
file|<functional>
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|StringRef
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|namespace
name|lldb_server
block|{
name|class
name|Acceptor
block|{
name|public
label|:
name|virtual
operator|~
name|Acceptor
argument_list|()
operator|=
expr|default
expr_stmt|;
name|Status
name|Listen
parameter_list|(
name|int
name|backlog
parameter_list|)
function_decl|;
name|Status
name|Accept
parameter_list|(
specifier|const
name|bool
name|child_processes_inherit
parameter_list|,
name|Connection
modifier|*
modifier|&
name|conn
parameter_list|)
function_decl|;
specifier|static
name|std
operator|::
name|unique_ptr
operator|<
name|Acceptor
operator|>
name|Create
argument_list|(
argument|llvm::StringRef name
argument_list|,
argument|const bool child_processes_inherit
argument_list|,
argument|Status&error
argument_list|)
expr_stmt|;
name|Socket
operator|::
name|SocketProtocol
name|GetSocketProtocol
argument_list|()
specifier|const
expr_stmt|;
specifier|const
name|char
operator|*
name|GetSocketScheme
argument_list|()
specifier|const
expr_stmt|;
comment|// Returns either TCP port number as string or domain socket path.
comment|// Empty string is returned in case of error.
name|std
operator|::
name|string
name|GetLocalSocketId
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
typedef|typedef
name|std
operator|::
name|function
operator|<
name|std
operator|::
name|string
argument_list|()
operator|>
name|LocalSocketIdFunc
expr_stmt|;
name|Acceptor
argument_list|(
argument|std::unique_ptr<Socket>&&listener_socket
argument_list|,
argument|llvm::StringRef name
argument_list|,
argument|const LocalSocketIdFunc&local_socket_id
argument_list|)
empty_stmt|;
specifier|const
name|std
operator|::
name|unique_ptr
operator|<
name|Socket
operator|>
name|m_listener_socket_up
expr_stmt|;
specifier|const
name|std
operator|::
name|string
name|m_name
expr_stmt|;
specifier|const
name|LocalSocketIdFunc
name|m_local_socket_id
decl_stmt|;
block|}
empty_stmt|;
block|}
comment|// namespace lldb_server
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
comment|// lldb_server_Acceptor_h_
end_comment

end_unit

