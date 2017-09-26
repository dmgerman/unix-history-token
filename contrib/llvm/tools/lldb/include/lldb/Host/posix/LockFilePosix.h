begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- LockFilePosix.h -----------------------------------------*- C++ -*-===//
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
name|liblldb_Host_posix_LockFilePosix_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_Host_posix_LockFilePosix_h_
end_define

begin_include
include|#
directive|include
file|"lldb/Host/LockFileBase.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|LockFilePosix
range|:
name|public
name|LockFileBase
block|{
name|public
operator|:
name|explicit
name|LockFilePosix
argument_list|(
argument|int fd
argument_list|)
block|;
operator|~
name|LockFilePosix
argument_list|()
name|override
block|;
name|protected
operator|:
name|Status
name|DoWriteLock
argument_list|(
argument|const uint64_t start
argument_list|,
argument|const uint64_t len
argument_list|)
name|override
block|;
name|Status
name|DoTryWriteLock
argument_list|(
argument|const uint64_t start
argument_list|,
argument|const uint64_t len
argument_list|)
name|override
block|;
name|Status
name|DoReadLock
argument_list|(
argument|const uint64_t start
argument_list|,
argument|const uint64_t len
argument_list|)
name|override
block|;
name|Status
name|DoTryReadLock
argument_list|(
argument|const uint64_t start
argument_list|,
argument|const uint64_t len
argument_list|)
name|override
block|;
name|Status
name|DoUnlock
argument_list|()
name|override
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
comment|// liblldb_Host_posix_LockFilePosix_h_
end_comment

end_unit

