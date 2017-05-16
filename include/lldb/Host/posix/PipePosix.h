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
name|liblldb_Host_posix_PipePosix_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_Host_posix_PipePosix_h_
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__cplusplus
argument_list|)
end_if

begin_include
include|#
directive|include
file|"lldb/Host/PipeBase.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//----------------------------------------------------------------------
comment|/// @class PipePosix PipePosix.h "lldb/Host/posix/PipePosix.h"
comment|/// @brief A posix-based implementation of Pipe, a class that abtracts
comment|///        unix style pipes.
comment|///
comment|/// A class that abstracts the LLDB core from host pipe functionality.
comment|//----------------------------------------------------------------------
name|class
name|PipePosix
range|:
name|public
name|PipeBase
block|{
name|public
operator|:
specifier|static
name|int
name|kInvalidDescriptor
block|;
name|PipePosix
argument_list|()
block|;
name|PipePosix
argument_list|(
argument|int read_fd
argument_list|,
argument|int write_fd
argument_list|)
block|;
name|PipePosix
argument_list|(
specifier|const
name|PipePosix
operator|&
argument_list|)
operator|=
name|delete
block|;
name|PipePosix
argument_list|(
name|PipePosix
operator|&&
name|pipe_posix
argument_list|)
block|;
name|PipePosix
operator|&
name|operator
operator|=
operator|(
specifier|const
name|PipePosix
operator|&
operator|)
operator|=
name|delete
block|;
name|PipePosix
operator|&
name|operator
operator|=
operator|(
name|PipePosix
operator|&&
name|pipe_posix
operator|)
block|;
operator|~
name|PipePosix
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
comment|// Close both descriptors
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
name|private
operator|:
name|int
name|m_fds
index|[
literal|2
index|]
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
comment|// #if defined(__cplusplus)
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_Host_posix_PipePosix_h_
end_comment

end_unit

