begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- FileSystemStatCache.h - Caching for 'stat' calls -------*- C++ -*-===//
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
comment|///
end_comment

begin_comment
comment|/// \file
end_comment

begin_comment
comment|/// \brief Defines the FileSystemStatCache interface.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_CLANG_FILESYSTEMSTATCACHE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_FILESYSTEMSTATCACHE_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/LLVM.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/FileSystem.h"
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|vfs
block|{
name|class
name|File
decl_stmt|;
name|class
name|FileSystem
decl_stmt|;
block|}
comment|// FIXME: should probably replace this with vfs::Status
struct|struct
name|FileData
block|{
name|std
operator|::
name|string
name|Name
expr_stmt|;
name|uint64_t
name|Size
decl_stmt|;
name|time_t
name|ModTime
decl_stmt|;
name|llvm
operator|::
name|sys
operator|::
name|fs
operator|::
name|UniqueID
name|UniqueID
expr_stmt|;
name|bool
name|IsDirectory
decl_stmt|;
name|bool
name|IsNamedPipe
decl_stmt|;
name|bool
name|InPCH
decl_stmt|;
name|bool
name|IsVFSMapped
decl_stmt|;
comment|// FIXME: remove this when files support multiple names
name|FileData
argument_list|()
operator|:
name|Size
argument_list|(
literal|0
argument_list|)
operator|,
name|ModTime
argument_list|(
literal|0
argument_list|)
operator|,
name|IsDirectory
argument_list|(
name|false
argument_list|)
operator|,
name|IsNamedPipe
argument_list|(
name|false
argument_list|)
operator|,
name|InPCH
argument_list|(
name|false
argument_list|)
operator|,
name|IsVFSMapped
argument_list|(
argument|false
argument_list|)
block|{}
block|}
struct|;
comment|/// \brief Abstract interface for introducing a FileManager cache for 'stat'
comment|/// system calls, which is used by precompiled and pretokenized headers to
comment|/// improve performance.
name|class
name|FileSystemStatCache
block|{
name|virtual
name|void
name|anchor
parameter_list|()
function_decl|;
name|protected
label|:
name|std
operator|::
name|unique_ptr
operator|<
name|FileSystemStatCache
operator|>
name|NextStatCache
expr_stmt|;
name|public
label|:
name|virtual
operator|~
name|FileSystemStatCache
argument_list|()
block|{}
expr|enum
name|LookupResult
block|{
name|CacheExists
block|,
comment|///< We know the file exists and its cached stat data.
name|CacheMissing
comment|///< We know that the file doesn't exist.
block|}
expr_stmt|;
comment|/// \brief Get the 'stat' information for the specified path, using the cache
comment|/// to accelerate it if possible.
comment|///
comment|/// \returns \c true if the path does not exist or \c false if it exists.
comment|///
comment|/// If isFile is true, then this lookup should only return success for files
comment|/// (not directories).  If it is false this lookup should only return
comment|/// success for directories (not files).  On a successful file lookup, the
comment|/// implementation can optionally fill in \p F with a valid \p File object and
comment|/// the client guarantees that it will close it.
specifier|static
name|bool
name|get
argument_list|(
specifier|const
name|char
operator|*
name|Path
argument_list|,
name|FileData
operator|&
name|Data
argument_list|,
name|bool
name|isFile
argument_list|,
name|std
operator|::
name|unique_ptr
operator|<
name|vfs
operator|::
name|File
operator|>
operator|*
name|F
argument_list|,
name|FileSystemStatCache
operator|*
name|Cache
argument_list|,
name|vfs
operator|::
name|FileSystem
operator|&
name|FS
argument_list|)
decl_stmt|;
comment|/// \brief Sets the next stat call cache in the chain of stat caches.
comment|/// Takes ownership of the given stat cache.
name|void
name|setNextStatCache
parameter_list|(
name|FileSystemStatCache
modifier|*
name|Cache
parameter_list|)
block|{
name|NextStatCache
operator|.
name|reset
argument_list|(
name|Cache
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Retrieve the next stat call cache in the chain.
name|FileSystemStatCache
modifier|*
name|getNextStatCache
parameter_list|()
block|{
return|return
name|NextStatCache
operator|.
name|get
argument_list|()
return|;
block|}
comment|/// \brief Retrieve the next stat call cache in the chain, transferring
comment|/// ownership of this cache (and, transitively, all of the remaining caches)
comment|/// to the caller.
name|FileSystemStatCache
modifier|*
name|takeNextStatCache
parameter_list|()
block|{
return|return
name|NextStatCache
operator|.
name|release
argument_list|()
return|;
block|}
name|protected
label|:
comment|// FIXME: The pointer here is a non-owning/optional reference to the
comment|// unique_ptr. Optional<unique_ptr<vfs::File>&> might be nicer, but
comment|// Optional needs some work to support references so this isn't possible yet.
name|virtual
name|LookupResult
name|getStat
argument_list|(
specifier|const
name|char
operator|*
name|Path
argument_list|,
name|FileData
operator|&
name|Data
argument_list|,
name|bool
name|isFile
argument_list|,
name|std
operator|::
name|unique_ptr
operator|<
name|vfs
operator|::
name|File
operator|>
operator|*
name|F
argument_list|,
name|vfs
operator|::
name|FileSystem
operator|&
name|FS
argument_list|)
init|=
literal|0
decl_stmt|;
name|LookupResult
name|statChained
argument_list|(
specifier|const
name|char
operator|*
name|Path
argument_list|,
name|FileData
operator|&
name|Data
argument_list|,
name|bool
name|isFile
argument_list|,
name|std
operator|::
name|unique_ptr
operator|<
name|vfs
operator|::
name|File
operator|>
operator|*
name|F
argument_list|,
name|vfs
operator|::
name|FileSystem
operator|&
name|FS
argument_list|)
block|{
if|if
condition|(
name|FileSystemStatCache
modifier|*
name|Next
init|=
name|getNextStatCache
argument_list|()
condition|)
return|return
name|Next
operator|->
name|getStat
argument_list|(
name|Path
argument_list|,
name|Data
argument_list|,
name|isFile
argument_list|,
name|F
argument_list|,
name|FS
argument_list|)
return|;
comment|// If we hit the end of the list of stat caches to try, just compute and
comment|// return it without a cache.
return|return
name|get
argument_list|(
name|Path
argument_list|,
name|Data
argument_list|,
name|isFile
argument_list|,
name|F
argument_list|,
name|nullptr
argument_list|,
name|FS
argument_list|)
condition|?
name|CacheMissing
else|:
name|CacheExists
return|;
block|}
block|}
empty_stmt|;
comment|/// \brief A stat "cache" that can be used by FileManager to keep
comment|/// track of the results of stat() calls that occur throughout the
comment|/// execution of the front end.
name|class
name|MemorizeStatCalls
range|:
name|public
name|FileSystemStatCache
block|{
name|public
operator|:
comment|/// \brief The set of stat() calls that have been seen.
name|llvm
operator|::
name|StringMap
operator|<
name|FileData
block|,
name|llvm
operator|::
name|BumpPtrAllocator
operator|>
name|StatCalls
block|;
typedef|typedef
name|llvm
operator|::
name|StringMap
operator|<
name|FileData
operator|,
name|llvm
operator|::
name|BumpPtrAllocator
operator|>
operator|::
name|const_iterator
name|iterator
expr_stmt|;
name|iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|StatCalls
operator|.
name|begin
argument_list|()
return|;
block|}
name|iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|StatCalls
operator|.
name|end
argument_list|()
return|;
block|}
name|LookupResult
name|getStat
argument_list|(
argument|const char *Path
argument_list|,
argument|FileData&Data
argument_list|,
argument|bool isFile
argument_list|,
argument|std::unique_ptr<vfs::File> *F
argument_list|,
argument|vfs::FileSystem&FS
argument_list|)
name|override
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

