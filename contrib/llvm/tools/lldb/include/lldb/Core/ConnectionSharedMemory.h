begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ConnectionSharedMemory.h --------------------------------*- C++ -*-===//
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
name|liblldb_ConnectionSharedMemory_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ConnectionSharedMemory_h_
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

begin_include
include|#
directive|include
file|"lldb/Core/DataBufferMemoryMap.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|ConnectionSharedMemory
range|:
name|public
name|Connection
block|{
name|public
operator|:
name|ConnectionSharedMemory
argument_list|()
block|;
name|virtual
operator|~
name|ConnectionSharedMemory
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
argument|Error *error_ptr
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
name|virtual
name|std
operator|::
name|string
name|GetURI
argument_list|()
block|;
name|lldb
operator|::
name|ConnectionStatus
name|Open
argument_list|(
argument|bool create
argument_list|,
argument|const char *name
argument_list|,
argument|size_t size
argument_list|,
argument|Error *error_ptr
argument_list|)
block|;
name|protected
operator|:
name|std
operator|::
name|string
name|m_name
block|;
name|int
name|m_fd
block|;
comment|// One buffer that contains all we need
name|DataBufferMemoryMap
name|m_mmap
block|;
name|private
operator|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|ConnectionSharedMemory
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
comment|// liblldb_ConnectionSharedMemory_h_
end_comment

end_unit

