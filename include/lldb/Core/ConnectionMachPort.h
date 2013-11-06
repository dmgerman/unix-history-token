begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ConnectionMachPort.h --------------------------------*- C++ -*-===//
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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__APPLE__
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|liblldb_ConnectionMachPort_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ConnectionMachPort_h_
end_define

begin_comment
comment|// C Includes
end_comment

begin_include
include|#
directive|include
file|<mach/port.h>
end_include

begin_include
include|#
directive|include
file|<mach/kern_return.h>
end_include

begin_comment
comment|// C++ Includes
end_comment

begin_include
include|#
directive|include
file|<string>
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

begin_decl_stmt
name|class
name|ConnectionMachPort
range|:
name|public
name|lldb_private
operator|::
name|Connection
block|{
name|public
operator|:
name|ConnectionMachPort
argument_list|()
block|;
name|virtual
operator|~
name|ConnectionMachPort
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
name|BytesAvailable
argument_list|(
argument|uint32_t timeout_usec
argument_list|,
argument|lldb_private::Error *error_ptr
argument_list|)
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
name|lldb_private
operator|::
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
name|lldb_private
operator|::
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
argument|lldb_private::Error *error_ptr
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
argument|lldb_private::Error *error_ptr
argument_list|)
block|;
name|lldb
operator|::
name|ConnectionStatus
name|BootstrapCheckIn
argument_list|(
specifier|const
name|char
operator|*
name|port_name
argument_list|,
name|lldb_private
operator|::
name|Error
operator|*
name|error_ptr
argument_list|)
block|;
name|lldb
operator|::
name|ConnectionStatus
name|BootstrapLookup
argument_list|(
specifier|const
name|char
operator|*
name|port_name
argument_list|,
name|lldb_private
operator|::
name|Error
operator|*
name|error_ptr
argument_list|)
block|;      struct
name|PayloadType
block|{
name|uint32_t
name|command
block|;
name|uint32_t
name|data_length
block|;
name|uint8_t
name|data
index|[
literal|32
index|]
block|;     }
block|;
name|kern_return_t
name|Send
argument_list|(
specifier|const
name|PayloadType
operator|&
name|payload
argument_list|)
block|;
name|kern_return_t
name|Receive
argument_list|(
name|PayloadType
operator|&
name|payload
argument_list|)
block|;
name|protected
operator|:
name|mach_port_t
name|m_task
block|;
name|mach_port_t
name|m_port
block|;
name|private
operator|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|ConnectionMachPort
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_ConnectionMachPort_h_
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// #if defined(__APPLE__)
end_comment

end_unit

