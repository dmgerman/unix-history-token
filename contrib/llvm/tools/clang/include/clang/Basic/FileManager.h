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
comment|///
end_comment

begin_comment
comment|/// \file
end_comment

begin_comment
comment|/// \brief Defines the clang::FileManager interface and associated types.
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
file|"clang/Basic/FileSystemOptions.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/LLVM.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/IntrusiveRefCntPtr.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/OwningPtr.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

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
file|"llvm/Support/Allocator.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/FileSystem.h"
end_include

begin_comment
comment|// FIXME: Enhance libsystem to support inode and other fields in stat.
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_MSC_VER
end_ifdef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|mode_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_struct_decl
struct_decl|struct
name|stat
struct_decl|;
end_struct_decl

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MemoryBuffer
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|FileManager
decl_stmt|;
name|class
name|FileSystemStatCache
decl_stmt|;
comment|/// \brief Cached information about one directory (either on disk or in
comment|/// the virtual file system).
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
comment|/// \brief Cached information about one file (either on disk
comment|/// or in the virtual file system).
comment|///
comment|/// If the 'FD' member is valid, then this FileEntry has an open file
comment|/// descriptor for the file.
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
name|IsNamedPipe
decl_stmt|;
name|bool
name|InPCH
decl_stmt|;
comment|/// FD - The file descriptor for the file entry if it is opened and owned
comment|/// by the FileEntry.  If not, this is set to -1.
name|mutable
name|int
name|FD
decl_stmt|;
name|friend
name|class
name|FileManager
decl_stmt|;
name|public
label|:
name|FileEntry
argument_list|(
argument|llvm::sys::fs::UniqueID UniqueID
argument_list|,
argument|bool IsNamedPipe
argument_list|,
argument|bool InPCH
argument_list|)
block|:
name|Name
argument_list|(
literal|0
argument_list|)
operator|,
name|UniqueID
argument_list|(
name|UniqueID
argument_list|)
operator|,
name|IsNamedPipe
argument_list|(
name|IsNamedPipe
argument_list|)
operator|,
name|InPCH
argument_list|(
name|InPCH
argument_list|)
operator|,
name|FD
argument_list|(
argument|-
literal|1
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
name|UniqueID
argument_list|(
literal|0
argument_list|,
literal|0
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
name|FD
argument_list|(
argument|-
literal|1
argument_list|)
block|{}
name|FileEntry
argument_list|(
argument|const FileEntry&FE
argument_list|)
block|{
name|memcpy
argument_list|(
name|this
argument_list|,
operator|&
name|FE
argument_list|,
sizeof|sizeof
argument_list|(
name|FE
argument_list|)
argument_list|)
block|;
name|assert
argument_list|(
name|FD
operator|==
operator|-
literal|1
operator|&&
literal|"Cannot copy a file-owning FileEntry"
argument_list|)
block|;   }
name|void
name|operator
operator|=
operator|(
specifier|const
name|FileEntry
operator|&
name|FE
operator|)
block|{
name|memcpy
argument_list|(
name|this
argument_list|,
operator|&
name|FE
argument_list|,
sizeof|sizeof
argument_list|(
name|FE
argument_list|)
argument_list|)
block|;
name|assert
argument_list|(
name|FD
operator|==
operator|-
literal|1
operator|&&
literal|"Cannot assign a file-owning FileEntry"
argument_list|)
block|;   }
operator|~
name|FileEntry
argument_list|()
expr_stmt|;
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
specifier|const
name|llvm
operator|::
name|sys
operator|::
name|fs
operator|::
name|UniqueID
operator|&
name|getUniqueID
argument_list|()
specifier|const
block|{
return|return
name|UniqueID
return|;
block|}
name|bool
name|isInPCH
argument_list|()
specifier|const
block|{
return|return
name|InPCH
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
comment|/// \brief Return the directory the file lives in.
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
name|UniqueID
operator|<
name|RHS
operator|.
name|UniqueID
return|;
block|}
comment|/// \brief Check whether the file is a named pipe (and thus can't be opened by
comment|/// the native FileManager methods).
name|bool
name|isNamedPipe
argument_list|()
specifier|const
block|{
return|return
name|IsNamedPipe
return|;
block|}
block|}
empty_stmt|;
struct_decl|struct
name|FileData
struct_decl|;
comment|/// \brief Implements support for file system lookup, file system caching,
comment|/// and directory search management.
comment|///
comment|/// This also handles more advanced properties, such as uniquing files based
comment|/// on "inode", so that a file with two names (e.g. symlinked) will be treated
comment|/// as a single file.
comment|///
name|class
name|FileManager
range|:
name|public
name|RefCountedBase
operator|<
name|FileManager
operator|>
block|{
name|FileSystemOptions
name|FileSystemOpts
block|;
name|class
name|UniqueDirContainer
block|;
name|class
name|UniqueFileContainer
block|;
comment|/// \brief Cache for existing real directories.
name|UniqueDirContainer
operator|&
name|UniqueRealDirs
block|;
comment|/// \brief Cache for existing real files.
name|UniqueFileContainer
operator|&
name|UniqueRealFiles
block|;
comment|/// \brief The virtual directories that we have allocated.
comment|///
comment|/// For each virtual file (e.g. foo/bar/baz.cpp), we add all of its parent
comment|/// directories (foo/ and foo/bar/) here.
name|SmallVector
operator|<
name|DirectoryEntry
operator|*
block|,
literal|4
operator|>
name|VirtualDirectoryEntries
block|;
comment|/// \brief The virtual files that we have allocated.
name|SmallVector
operator|<
name|FileEntry
operator|*
block|,
literal|4
operator|>
name|VirtualFileEntries
block|;
comment|/// \brief A cache that maps paths to directory entries (either real or
comment|/// virtual) we have looked up
comment|///
comment|/// The actual Entries for real directories/files are
comment|/// owned by UniqueRealDirs/UniqueRealFiles above, while the Entries
comment|/// for virtual directories/files are owned by
comment|/// VirtualDirectoryEntries/VirtualFileEntries above.
comment|///
name|llvm
operator|::
name|StringMap
operator|<
name|DirectoryEntry
operator|*
block|,
name|llvm
operator|::
name|BumpPtrAllocator
operator|>
name|SeenDirEntries
block|;
comment|/// \brief A cache that maps paths to file entries (either real or
comment|/// virtual) we have looked up.
comment|///
comment|/// \see SeenDirEntries
name|llvm
operator|::
name|StringMap
operator|<
name|FileEntry
operator|*
block|,
name|llvm
operator|::
name|BumpPtrAllocator
operator|>
name|SeenFileEntries
block|;
comment|/// \brief The canonical names of directories.
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|DirectoryEntry
operator|*
block|,
name|llvm
operator|::
name|StringRef
operator|>
name|CanonicalDirNames
block|;
comment|/// \brief Storage for canonical names that we have computed.
name|llvm
operator|::
name|BumpPtrAllocator
name|CanonicalNameStorage
block|;
comment|/// \brief Each FileEntry we create is assigned a unique ID #.
comment|///
name|unsigned
name|NextFileUID
block|;
comment|// Statistics.
name|unsigned
name|NumDirLookups
block|,
name|NumFileLookups
block|;
name|unsigned
name|NumDirCacheMisses
block|,
name|NumFileCacheMisses
block|;
comment|// Caching.
name|OwningPtr
operator|<
name|FileSystemStatCache
operator|>
name|StatCache
block|;
name|bool
name|getStatValue
argument_list|(
argument|const char *Path
argument_list|,
argument|FileData&Data
argument_list|,
argument|bool isFile
argument_list|,
argument|int *FileDescriptor
argument_list|)
block|;
comment|/// Add all ancestors of the given path (pointing to either a file
comment|/// or a directory) as virtual directories.
name|void
name|addAncestorsAsVirtualDirs
argument_list|(
argument|StringRef Path
argument_list|)
block|;
name|public
operator|:
name|FileManager
argument_list|(
specifier|const
name|FileSystemOptions
operator|&
name|FileSystemOpts
argument_list|)
block|;
operator|~
name|FileManager
argument_list|()
block|;
comment|/// \brief Installs the provided FileSystemStatCache object within
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
argument_list|(
argument|FileSystemStatCache *statCache
argument_list|,
argument|bool AtBeginning = false
argument_list|)
block|;
comment|/// \brief Removes the specified FileSystemStatCache object from the manager.
name|void
name|removeStatCache
argument_list|(
name|FileSystemStatCache
operator|*
name|statCache
argument_list|)
block|;
comment|/// \brief Removes all FileSystemStatCache objects from the manager.
name|void
name|clearStatCaches
argument_list|()
block|;
comment|/// \brief Lookup, cache, and verify the specified directory (real or
comment|/// virtual).
comment|///
comment|/// This returns NULL if the directory doesn't exist.
comment|///
comment|/// \param CacheFailure If true and the file does not exist, we'll cache
comment|/// the failure to find this file.
specifier|const
name|DirectoryEntry
operator|*
name|getDirectory
argument_list|(
argument|StringRef DirName
argument_list|,
argument|bool CacheFailure = true
argument_list|)
block|;
comment|/// \brief Lookup, cache, and verify the specified file (real or
comment|/// virtual).
comment|///
comment|/// This returns NULL if the file doesn't exist.
comment|///
comment|/// \param OpenFile if true and the file exists, it will be opened.
comment|///
comment|/// \param CacheFailure If true and the file does not exist, we'll cache
comment|/// the failure to find this file.
specifier|const
name|FileEntry
operator|*
name|getFile
argument_list|(
argument|StringRef Filename
argument_list|,
argument|bool OpenFile = false
argument_list|,
argument|bool CacheFailure = true
argument_list|)
block|;
comment|/// \brief Returns the current file system options
specifier|const
name|FileSystemOptions
operator|&
name|getFileSystemOptions
argument_list|()
block|{
return|return
name|FileSystemOpts
return|;
block|}
comment|/// \brief Retrieve a file entry for a "virtual" file that acts as
comment|/// if there were a file with the given name on disk.
comment|///
comment|/// The file itself is not accessed.
specifier|const
name|FileEntry
operator|*
name|getVirtualFile
argument_list|(
argument|StringRef Filename
argument_list|,
argument|off_t Size
argument_list|,
argument|time_t ModificationTime
argument_list|)
block|;
comment|/// \brief Open the specified file as a MemoryBuffer, returning a new
comment|/// MemoryBuffer if successful, otherwise returning null.
name|llvm
operator|::
name|MemoryBuffer
operator|*
name|getBufferForFile
argument_list|(
argument|const FileEntry *Entry
argument_list|,
argument|std::string *ErrorStr =
literal|0
argument_list|,
argument|bool isVolatile = false
argument_list|)
block|;
name|llvm
operator|::
name|MemoryBuffer
operator|*
name|getBufferForFile
argument_list|(
argument|StringRef Filename
argument_list|,
argument|std::string *ErrorStr =
literal|0
argument_list|)
block|;
comment|/// \brief Get the 'stat' information for the given \p Path.
comment|///
comment|/// If the path is relative, it will be resolved against the WorkingDir of the
comment|/// FileManager's FileSystemOptions.
name|bool
name|getNoncachedStatValue
argument_list|(
argument|StringRef Path
argument_list|,
argument|llvm::sys::fs::file_status&Result
argument_list|)
block|;
comment|/// \brief Remove the real file \p Entry from the cache.
name|void
name|invalidateCache
argument_list|(
specifier|const
name|FileEntry
operator|*
name|Entry
argument_list|)
block|;
comment|/// \brief If path is not absolute and FileSystemOptions set the working
comment|/// directory, the path is modified to be relative to the given
comment|/// working directory.
name|void
name|FixupRelativePath
argument_list|(
argument|SmallVectorImpl<char>&path
argument_list|)
specifier|const
block|;
comment|/// \brief Produce an array mapping from the unique IDs assigned to each
comment|/// file to the corresponding FileEntry pointer.
name|void
name|GetUniqueIDMapping
argument_list|(
argument|SmallVectorImpl<const FileEntry *>&UIDToFiles
argument_list|)
specifier|const
block|;
comment|/// \brief Modifies the size and modification time of a previously created
comment|/// FileEntry. Use with caution.
specifier|static
name|void
name|modifyFileEntry
argument_list|(
argument|FileEntry *File
argument_list|,
argument|off_t Size
argument_list|,
argument|time_t ModificationTime
argument_list|)
block|;
comment|/// \brief Retrieve the canonical name for a given directory.
comment|///
comment|/// This is a very expensive operation, despite its results being cached,
comment|/// and should only be used when the physical layout of the file system is
comment|/// required, which is (almost) never.
name|StringRef
name|getCanonicalName
argument_list|(
specifier|const
name|DirectoryEntry
operator|*
name|Dir
argument_list|)
block|;
name|void
name|PrintStats
argument_list|()
specifier|const
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

end_unit

