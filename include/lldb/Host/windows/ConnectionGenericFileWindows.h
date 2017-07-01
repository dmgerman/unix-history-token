begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ConnectionGenericFileWindows.h --------------------------*- C++ -*-===//
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
name|liblldb_Host_windows_ConnectionGenericFileWindows_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_Host_windows_ConnectionGenericFileWindows_h_
end_define

begin_include
include|#
directive|include
file|"lldb/Host/windows/windows.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/Connection.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-types.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|Status
decl_stmt|;
name|class
name|ConnectionGenericFile
range|:
name|public
name|lldb_private
operator|::
name|Connection
block|{
name|public
operator|:
name|ConnectionGenericFile
argument_list|()
block|;
name|ConnectionGenericFile
argument_list|(
argument|lldb::file_t file
argument_list|,
argument|bool owns_file
argument_list|)
block|;
operator|~
name|ConnectionGenericFile
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
name|bool
name|InterruptRead
argument_list|()
name|override
block|;
name|protected
operator|:
name|OVERLAPPED
name|m_overlapped
block|;
name|HANDLE
name|m_file
block|;
name|HANDLE
name|m_event_handles
index|[
literal|2
index|]
block|;
name|bool
name|m_owns_file
block|;
name|LARGE_INTEGER
name|m_file_position
block|;    enum
block|{
name|kBytesAvailableEvent
block|,
name|kInterruptEvent
block|}
block|;
name|private
operator|:
name|void
name|InitializeEventHandles
argument_list|()
block|;
name|void
name|IncrementFilePointer
argument_list|(
argument|DWORD amount
argument_list|)
block|;
name|std
operator|::
name|string
name|m_uri
block|;
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|ConnectionGenericFile
argument_list|)
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

