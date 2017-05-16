begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- PipePosix.h ---------------------------------------------*- C++ -*-===//
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
name|liblldb_Host_windows_PipeWindows_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_Host_windows_PipeWindows_h_
end_define

begin_include
include|#
directive|include
file|"lldb/Host/PipeBase.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Host/windows/windows.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//----------------------------------------------------------------------
comment|/// @class Pipe PipeWindows.h "lldb/Host/windows/PipeWindows.h"
comment|/// @brief A windows-based implementation of Pipe, a class that abtracts
comment|///        unix style pipes.
comment|///
comment|/// A class that abstracts the LLDB core from host pipe functionality.
comment|//----------------------------------------------------------------------
name|class
name|PipeWindows
range|:
name|public
name|PipeBase
block|{
name|public
operator|:
name|PipeWindows
argument_list|()
block|;
operator|~
name|PipeWindows
argument_list|()
name|override
block|;
name|Status
name|CreateNew
argument_list|(
argument|bool child_process_inherit
argument_list|)
name|override
block|;
name|Status
name|CreateNew
argument_list|(
argument|llvm::StringRef name
argument_list|,
argument|bool child_process_inherit
argument_list|)
name|override
block|;
name|Status
name|CreateWithUniqueName
argument_list|(
argument|llvm::StringRef prefix
argument_list|,
argument|bool child_process_inherit
argument_list|,
argument|llvm::SmallVectorImpl<char>&name
argument_list|)
name|override
block|;
name|Status
name|OpenAsReader
argument_list|(
argument|llvm::StringRef name
argument_list|,
argument|bool child_process_inherit
argument_list|)
name|override
block|;
name|Status
name|OpenAsWriterWithTimeout
argument_list|(
argument|llvm::StringRef name
argument_list|,
argument|bool child_process_inherit
argument_list|,
argument|const std::chrono::microseconds&timeout
argument_list|)
name|override
block|;
name|bool
name|CanRead
argument_list|()
specifier|const
name|override
block|;
name|bool
name|CanWrite
argument_list|()
specifier|const
name|override
block|;
name|int
name|GetReadFileDescriptor
argument_list|()
specifier|const
name|override
block|;
name|int
name|GetWriteFileDescriptor
argument_list|()
specifier|const
name|override
block|;
name|int
name|ReleaseReadFileDescriptor
argument_list|()
name|override
block|;
name|int
name|ReleaseWriteFileDescriptor
argument_list|()
name|override
block|;
name|void
name|CloseReadFileDescriptor
argument_list|()
name|override
block|;
name|void
name|CloseWriteFileDescriptor
argument_list|()
name|override
block|;
name|void
name|Close
argument_list|()
name|override
block|;
name|Status
name|Delete
argument_list|(
argument|llvm::StringRef name
argument_list|)
name|override
block|;
name|Status
name|Write
argument_list|(
argument|const void *buf
argument_list|,
argument|size_t size
argument_list|,
argument|size_t&bytes_written
argument_list|)
name|override
block|;
name|Status
name|ReadWithTimeout
argument_list|(
argument|void *buf
argument_list|,
argument|size_t size
argument_list|,
argument|const std::chrono::microseconds&timeout
argument_list|,
argument|size_t&bytes_read
argument_list|)
name|override
block|;
comment|// PipeWindows specific methods.  These allow access to the underlying OS
comment|// handle.
name|HANDLE
name|GetReadNativeHandle
argument_list|()
block|;
name|HANDLE
name|GetWriteNativeHandle
argument_list|()
block|;
name|private
operator|:
name|Status
name|OpenNamedPipe
argument_list|(
argument|llvm::StringRef name
argument_list|,
argument|bool child_process_inherit
argument_list|,
argument|bool is_read
argument_list|)
block|;
name|HANDLE
name|m_read
block|;
name|HANDLE
name|m_write
block|;
name|int
name|m_read_fd
block|;
name|int
name|m_write_fd
block|;
name|OVERLAPPED
name|m_read_overlapped
block|;
name|OVERLAPPED
name|m_write_overlapped
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
comment|// liblldb_Host_posix_PipePosix_h_
end_comment

end_unit

