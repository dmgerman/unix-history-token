begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- DomainSocket.h ------------------------------------------*- C++ -*-===//
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
name|liblldb_DomainSocket_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_DomainSocket_h_
end_define

begin_include
include|#
directive|include
file|"lldb/Host/Socket.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|DomainSocket
range|:
name|public
name|Socket
block|{
name|public
operator|:
name|DomainSocket
argument_list|(
argument|bool should_close
argument_list|,
argument|bool child_processes_inherit
argument_list|)
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
argument|Socket *&socket
argument_list|)
name|override
block|;
name|protected
operator|:
name|DomainSocket
argument_list|(
argument|SocketProtocol protocol
argument_list|,
argument|bool child_processes_inherit
argument_list|)
block|;
name|virtual
name|size_t
name|GetNameOffset
argument_list|()
specifier|const
block|;
name|virtual
name|void
name|DeleteSocketFile
argument_list|(
argument|llvm::StringRef name
argument_list|)
block|;
name|private
operator|:
name|DomainSocket
argument_list|(
argument|NativeSocket socket
argument_list|,
argument|const DomainSocket&listen_socket
argument_list|)
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// ifndef liblldb_DomainSocket_h_
end_comment

end_unit

