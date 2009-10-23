begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- FileManager.h - File System Probing and Caching --------*- C++ -*-===//
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
comment|//  This file defines the FileManager interface.
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
name|LLVM_CLANG_FILEMANAGER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_FILEMANAGER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/OwningPtr.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Allocator.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Config/config.h"
end_include

begin_comment
comment|// for mode_t
end_comment

begin_comment
comment|// FIXME: Enhance libsystem to support inode and other fields in stat.
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|FileManager
decl_stmt|;
comment|/// DirectoryEntry - Cached information about one directory on the disk.
comment|///
name|class
name|DirectoryEntry
block|{
specifier|const
name|char
modifier|*
name|Name
decl_stmt|;
comment|// Name of the directory.
name|friend
name|class
name|FileManager
decl_stmt|;
name|public
label|:
name|DirectoryEntry
argument_list|()
operator|:
name|Name
argument_list|(
literal|0
argument_list|)
block|{}
specifier|const
name|char
operator|*
name|getName
argument_list|()
specifier|const
block|{
return|return
name|Name
return|;
block|}
block|}
empty_stmt|;
comment|/// FileEntry - Cached information about one file on the disk.
comment|///
name|class
name|FileEntry
block|{
specifier|const
name|char
modifier|*
name|Name
decl_stmt|;
comment|// Name of the file.
name|off_t
name|Size
decl_stmt|;
comment|// File size in bytes.
name|time_t
name|ModTime
decl_stmt|;
comment|// Modification time of file.
specifier|const
name|DirectoryEntry
modifier|*
name|Dir
decl_stmt|;
comment|// Directory file lives in.
name|unsigned
name|UID
decl_stmt|;
comment|// A unique (small) ID for the file.
name|dev_t
name|Device
decl_stmt|;
comment|// ID for the device containing the file.
name|ino_t
name|Inode
decl_stmt|;
comment|// Inode number for the file.
name|mode_t
name|FileMode
decl_stmt|;
comment|// The file mode as returned by 'stat'.
name|friend
name|class
name|FileManager
decl_stmt|;
name|public
label|:
name|FileEntry
argument_list|(
argument|dev_t device
argument_list|,
argument|ino_t inode
argument_list|,
argument|mode_t m
argument_list|)
block|:
name|Name
argument_list|(
literal|0
argument_list|)
operator|,
name|Device
argument_list|(
name|device
argument_list|)
operator|,
name|Inode
argument_list|(
name|inode
argument_list|)
operator|,
name|FileMode
argument_list|(
argument|m
argument_list|)
block|{}
comment|// Add a default constructor for use with llvm::StringMap
name|FileEntry
argument_list|()
operator|:
name|Name
argument_list|(
literal|0
argument_list|)
operator|,
name|Device
argument_list|(
literal|0
argument_list|)
operator|,
name|Inode
argument_list|(
literal|0
argument_list|)
operator|,
name|FileMode
argument_list|(
literal|0
argument_list|)
block|{}
specifier|const
name|char
operator|*
name|getName
argument_list|()
specifier|const
block|{
return|return
name|Name
return|;
block|}
name|off_t
name|getSize
argument_list|()
specifier|const
block|{
return|return
name|Size
return|;
block|}
name|unsigned
name|getUID
argument_list|()
specifier|const
block|{
return|return
name|UID
return|;
block|}
name|ino_t
name|getInode
argument_list|()
specifier|const
block|{
return|return
name|Inode
return|;
block|}
name|dev_t
name|getDevice
argument_list|()
specifier|const
block|{
return|return
name|Device
return|;
block|}
name|time_t
name|getModificationTime
argument_list|()
specifier|const
block|{
return|return
name|ModTime
return|;
block|}
name|mode_t
name|getFileMode
argument_list|()
specifier|const
block|{
return|return
name|FileMode
return|;
block|}
comment|/// getDir - Return the directory the file lives in.
comment|///
specifier|const
name|DirectoryEntry
operator|*
name|getDir
argument_list|()
specifier|const
block|{
return|return
name|Dir
return|;
block|}
name|bool
name|operator
operator|<
operator|(
specifier|const
name|FileEntry
operator|&
name|RHS
operator|)
specifier|const
block|{
return|return
name|Device
operator|<
name|RHS
operator|.
name|Device
operator|||
operator|(
name|Device
operator|==
name|RHS
operator|.
name|Device
operator|&&
name|Inode
operator|<
name|RHS
operator|.
name|Inode
operator|)
return|;
block|}
block|}
empty_stmt|;
comment|/// \brief Abstract interface for introducing a FileManager cache for 'stat'
comment|/// system calls, which is used by precompiled and pretokenized headers to
comment|/// improve performance.
name|class
name|StatSysCallCache
block|{
name|protected
label|:
name|llvm
operator|::
name|OwningPtr
operator|<
name|StatSysCallCache
operator|>
name|NextStatCache
expr_stmt|;
name|public
label|:
name|virtual
operator|~
name|StatSysCallCache
argument_list|()
block|{}
name|virtual
name|int
name|stat
argument_list|(
argument|const char *path
argument_list|,
argument|struct stat *buf
argument_list|)
block|{
if|if
condition|(
name|getNextStatCache
argument_list|()
condition|)
return|return
name|getNextStatCache
argument_list|()
operator|->
name|stat
argument_list|(
name|path
argument_list|,
name|buf
argument_list|)
return|;
return|return
operator|::
name|stat
argument_list|(
name|path
argument_list|,
name|buf
argument_list|)
return|;
block|}
comment|/// \brief Sets the next stat call cache in the chain of stat caches.
comment|/// Takes ownership of the given stat cache.
name|void
name|setNextStatCache
parameter_list|(
name|StatSysCallCache
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
name|StatSysCallCache
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
name|StatSysCallCache
modifier|*
name|takeNextStatCache
parameter_list|()
block|{
return|return
name|NextStatCache
operator|.
name|take
argument_list|()
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// \brief A stat "cache" that can be used by FileManager to keep
end_comment

begin_comment
comment|/// track of the results of stat() calls that occur throughout the
end_comment

begin_comment
comment|/// execution of the front end.
end_comment

begin_decl_stmt
name|class
name|MemorizeStatCalls
range|:
name|public
name|StatSysCallCache
block|{
name|public
operator|:
comment|/// \brief The result of a stat() call.
comment|///
comment|/// The first member is the result of calling stat(). If stat()
comment|/// found something, the second member is a copy of the stat
comment|/// structure.
typedef|typedef
name|std
operator|::
name|pair
operator|<
name|int
operator|,
expr_stmt|struct
name|stat
operator|>
name|StatResult
expr_stmt|;
comment|/// \brief The set of stat() calls that have been
name|llvm
operator|::
name|StringMap
operator|<
name|StatResult
block|,
name|llvm
operator|::
name|BumpPtrAllocator
operator|>
name|StatCalls
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|llvm
operator|::
name|StringMap
operator|<
name|StatResult
operator|,
name|llvm
operator|::
name|BumpPtrAllocator
operator|>
operator|::
name|const_iterator
name|iterator
expr_stmt|;
end_typedef

begin_expr_stmt
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
end_expr_stmt

begin_expr_stmt
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
end_expr_stmt

begin_function_decl
name|virtual
name|int
name|stat
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|,
name|struct
name|stat
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_comment
unit|};
comment|/// FileManager - Implements support for file system lookup, file system
end_comment

begin_comment
comment|/// caching, and directory search management.  This also handles more advanced
end_comment

begin_comment
comment|/// properties, such as uniquing files based on "inode", so that a file with two
end_comment

begin_comment
comment|/// names (e.g. symlinked) will be treated as a single file.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|class
name|FileManager
block|{
name|class
name|UniqueDirContainer
decl_stmt|;
name|class
name|UniqueFileContainer
decl_stmt|;
comment|/// UniqueDirs/UniqueFiles - Cache for existing directories/files.
comment|///
name|UniqueDirContainer
modifier|&
name|UniqueDirs
decl_stmt|;
name|UniqueFileContainer
modifier|&
name|UniqueFiles
decl_stmt|;
comment|/// DirEntries/FileEntries - This is a cache of directory/file entries we have
comment|/// looked up.  The actual Entry is owned by UniqueFiles/UniqueDirs above.
comment|///
name|llvm
operator|::
name|StringMap
operator|<
name|DirectoryEntry
operator|*
operator|,
name|llvm
operator|::
name|BumpPtrAllocator
operator|>
name|DirEntries
expr_stmt|;
name|llvm
operator|::
name|StringMap
operator|<
name|FileEntry
operator|*
operator|,
name|llvm
operator|::
name|BumpPtrAllocator
operator|>
name|FileEntries
expr_stmt|;
comment|/// NextFileUID - Each FileEntry we create is assigned a unique ID #.
comment|///
name|unsigned
name|NextFileUID
decl_stmt|;
comment|// Statistics.
name|unsigned
name|NumDirLookups
decl_stmt|,
name|NumFileLookups
decl_stmt|;
name|unsigned
name|NumDirCacheMisses
decl_stmt|,
name|NumFileCacheMisses
decl_stmt|;
comment|// Caching.
name|llvm
operator|::
name|OwningPtr
operator|<
name|StatSysCallCache
operator|>
name|StatCache
expr_stmt|;
name|int
name|stat_cached
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|,
name|struct
name|stat
modifier|*
name|buf
parameter_list|)
block|{
return|return
name|StatCache
operator|.
name|get
argument_list|()
condition|?
name|StatCache
operator|->
name|stat
argument_list|(
name|path
argument_list|,
name|buf
argument_list|)
else|:
name|stat
argument_list|(
name|path
argument_list|,
name|buf
argument_list|)
return|;
block|}
name|public
label|:
name|FileManager
argument_list|()
expr_stmt|;
operator|~
name|FileManager
argument_list|()
expr_stmt|;
comment|/// \brief Installs the provided StatSysCallCache object within
comment|/// the FileManager.
comment|///
comment|/// Ownership of this object is transferred to the FileManager.
comment|///
comment|/// \param statCache the new stat cache to install. Ownership of this
comment|/// object is transferred to the FileManager.
comment|///
comment|/// \param AtBeginning whether this new stat cache must be installed at the
comment|/// beginning of the chain of stat caches. Otherwise, it will be added to
comment|/// the end of the chain.
name|void
name|addStatCache
parameter_list|(
name|StatSysCallCache
modifier|*
name|statCache
parameter_list|,
name|bool
name|AtBeginning
init|=
name|false
parameter_list|)
function_decl|;
comment|/// \brief Removes the provided StatSysCallCache object from the file manager.
name|void
name|removeStatCache
parameter_list|(
name|StatSysCallCache
modifier|*
name|statCache
parameter_list|)
function_decl|;
comment|/// getDirectory - Lookup, cache, and verify the specified directory.  This
comment|/// returns null if the directory doesn't exist.
comment|///
specifier|const
name|DirectoryEntry
modifier|*
name|getDirectory
argument_list|(
specifier|const
name|llvm
operator|::
name|StringRef
operator|&
name|Filename
argument_list|)
block|{
return|return
name|getDirectory
argument_list|(
name|Filename
operator|.
name|begin
argument_list|()
argument_list|,
name|Filename
operator|.
name|end
argument_list|()
argument_list|)
return|;
block|}
specifier|const
name|DirectoryEntry
modifier|*
name|getDirectory
parameter_list|(
specifier|const
name|char
modifier|*
name|FileStart
parameter_list|,
specifier|const
name|char
modifier|*
name|FileEnd
parameter_list|)
function_decl|;
comment|/// getFile - Lookup, cache, and verify the specified file.  This returns null
comment|/// if the file doesn't exist.
comment|///
specifier|const
name|FileEntry
modifier|*
name|getFile
argument_list|(
specifier|const
name|llvm
operator|::
name|StringRef
operator|&
name|Filename
argument_list|)
block|{
return|return
name|getFile
argument_list|(
name|Filename
operator|.
name|begin
argument_list|()
argument_list|,
name|Filename
operator|.
name|end
argument_list|()
argument_list|)
return|;
block|}
specifier|const
name|FileEntry
modifier|*
name|getFile
parameter_list|(
specifier|const
name|char
modifier|*
name|FilenameStart
parameter_list|,
specifier|const
name|char
modifier|*
name|FilenameEnd
parameter_list|)
function_decl|;
name|void
name|PrintStats
argument_list|()
specifier|const
expr_stmt|;
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

