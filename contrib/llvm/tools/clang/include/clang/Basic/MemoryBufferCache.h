begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- MemoryBufferCache.h - Cache for loaded memory buffers ----*- C++ -*-===//
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
name|LLVM_CLANG_BASIC_MEMORYBUFFERCACHE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_BASIC_MEMORYBUFFERCACHE_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/IntrusiveRefCntPtr.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringMap.h"
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MemoryBuffer
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_decl_stmt
name|namespace
name|clang
block|{
comment|/// Manage memory buffers across multiple users.
comment|///
comment|/// Ensures that multiple users have a consistent view of each buffer.  This is
comment|/// used by \a CompilerInstance when building PCMs to ensure that each \a
comment|/// ModuleManager sees the same files.
comment|///
comment|/// \a finalizeCurrentBuffers() should be called before creating a new user.
comment|/// This locks in the current buffers, ensuring that no buffer that has already
comment|/// been accessed can be purged, preventing use-after-frees.
name|class
name|MemoryBufferCache
range|:
name|public
name|llvm
operator|::
name|RefCountedBase
operator|<
name|MemoryBufferCache
operator|>
block|{   struct
name|BufferEntry
block|{
name|std
operator|::
name|unique_ptr
operator|<
name|llvm
operator|::
name|MemoryBuffer
operator|>
name|Buffer
block|;
comment|/// Track the timeline of when this was added to the cache.
name|unsigned
name|Index
block|;   }
block|;
comment|/// Cache of buffers.
name|llvm
operator|::
name|StringMap
operator|<
name|BufferEntry
operator|>
name|Buffers
block|;
comment|/// Monotonically increasing index.
name|unsigned
name|NextIndex
operator|=
literal|0
block|;
comment|/// Bumped to prevent "older" buffers from being removed.
name|unsigned
name|FirstRemovableIndex
operator|=
literal|0
block|;
name|public
operator|:
comment|/// Store the Buffer under the Filename.
comment|///
comment|/// \pre There is not already buffer is not already in the cache.
comment|/// \return a reference to the buffer as a convenience.
name|llvm
operator|::
name|MemoryBuffer
operator|&
name|addBuffer
argument_list|(
argument|llvm::StringRef Filename
argument_list|,
argument|std::unique_ptr<llvm::MemoryBuffer> Buffer
argument_list|)
block|;
comment|/// Try to remove a buffer from the cache.
comment|///
comment|/// \return false on success, iff \c !isBufferFinal().
name|bool
name|tryToRemoveBuffer
argument_list|(
argument|llvm::StringRef Filename
argument_list|)
block|;
comment|/// Get a pointer to the buffer if it exists; else nullptr.
name|llvm
operator|::
name|MemoryBuffer
operator|*
name|lookupBuffer
argument_list|(
argument|llvm::StringRef Filename
argument_list|)
block|;
comment|/// Check whether the buffer is final.
comment|///
comment|/// \return true iff \a finalizeCurrentBuffers() has been called since the
comment|/// buffer was added.  This prevents buffers from being removed.
name|bool
name|isBufferFinal
argument_list|(
argument|llvm::StringRef Filename
argument_list|)
block|;
comment|/// Finalize the current buffers in the cache.
comment|///
comment|/// Should be called when creating a new user to ensure previous uses aren't
comment|/// invalidated.
name|void
name|finalizeCurrentBuffers
argument_list|()
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CLANG_BASIC_MEMORYBUFFERCACHE_H
end_comment

end_unit

