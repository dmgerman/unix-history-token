begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- Caching.h - LLVM Link Time Optimizer Configuration -----------------===//
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

begin_comment
comment|//
end_comment

begin_comment
comment|// This file defines the localCache function, which allows clients to add a
end_comment

begin_comment
comment|// filesystem cache to ThinLTO.
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
name|LLVM_LTO_CACHING_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LTO_CACHING_H
end_define

begin_include
include|#
directive|include
file|"llvm/LTO/LTO.h"
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
name|namespace
name|lto
block|{
comment|/// This type defines the callback to add a pre-existing native object file
comment|/// (e.g. in a cache).
comment|///
comment|/// MB->getBufferIdentifier() is a valid path for the file at the time that it
comment|/// was opened, but clients should prefer to access MB directly in order to
comment|/// avoid a potential race condition.
comment|///
comment|/// Buffer callbacks must be thread safe.
typedef|typedef
name|std
operator|::
name|function
operator|<
name|void
argument_list|(
argument|unsigned Task
argument_list|,
argument|std::unique_ptr<MemoryBuffer> MB
argument_list|)
operator|>
name|AddBufferFn
expr_stmt|;
comment|/// Create a local file system cache which uses the given cache directory and
comment|/// file callback. This function also creates the cache directory if it does not
comment|/// already exist.
name|Expected
operator|<
name|NativeObjectCache
operator|>
name|localCache
argument_list|(
argument|StringRef CacheDirectoryPath
argument_list|,
argument|AddBufferFn AddBuffer
argument_list|)
expr_stmt|;
block|}
comment|// namespace lto
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

