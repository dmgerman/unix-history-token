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
file|"clang/Basic/FileSystemOptions.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/IntrusiveRefCntPtr.h"
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
name|namespace
name|sys
block|{
name|class
name|Path
decl_stmt|;
block|}
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
comment|/// DirectoryEntry - Cached information about one directory (either on
comment|/// the disk or in the virtual file system).
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
comment|/// FileEntry - Cached information about one file (either on the disk
comment|/// or in the virtual file system).  If the 'FD' member is valid, then
comment|/// this FileEntry has an open file descriptor for the file.
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
name|m
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
comment|/// FileManager - Implements support for file system lookup, file system
comment|/// caching, and directory search management.  This also handles more advanced
comment|/// properties, such as uniquing files based on "inode", so that a file with two
comment|/// names (e.g. symlinked) will be treated as a single file.
comment|///
name|class
name|FileManager
range|:
name|public
name|llvm
operator|::
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
comment|/// UniqueRealDirs/UniqueRealFiles - Cache for existing real directories/files.
comment|///
name|UniqueDirContainer
operator|&
name|UniqueRealDirs
block|;
name|UniqueFileContainer
operator|&
name|UniqueRealFiles
block|;
comment|/// \brief The virtual directories that we have allocated.  For each
comment|/// virtual file (e.g. foo/bar/baz.cpp), we add all of its parent
comment|/// directories (foo/ and foo/bar/) here.
name|llvm
operator|::
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
name|llvm
operator|::
name|SmallVector
operator|<
name|FileEntry
operator|*
block|,
literal|4
operator|>
name|VirtualFileEntries
block|;
comment|/// SeenDirEntries/SeenFileEntries - This is a cache that maps paths
comment|/// to directory/file entries (either real or virtual) we have
comment|/// looked up.  The actual Entries for real directories/files are
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
comment|/// NextFileUID - Each FileEntry we create is assigned a unique ID #.
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
name|llvm
operator|::
name|OwningPtr
operator|<
name|FileSystemStatCache
operator|>
name|StatCache
block|;
name|bool
name|getStatValue
argument_list|(
specifier|const
name|char
operator|*
name|Path
argument_list|,
expr|struct
name|stat
operator|&
name|StatBuf
argument_list|,
name|int
operator|*
name|FileDescriptor
argument_list|)
block|;
comment|/// Add all ancestors of the given path (pointing to either a file
comment|/// or a directory) as virtual directories.
name|void
name|addAncestorsAsVirtualDirs
argument_list|(
argument|llvm::StringRef Path
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
comment|/// getDirectory - Lookup, cache, and verify the specified directory
comment|/// (real or virtual).  This returns NULL if the directory doesn't exist.
comment|///
specifier|const
name|DirectoryEntry
operator|*
name|getDirectory
argument_list|(
argument|llvm::StringRef DirName
argument_list|)
block|;
comment|/// \brief Lookup, cache, and verify the specified file (real or
comment|/// virtual).  This returns NULL if the file doesn't exist.
comment|///
comment|/// \param openFile if true and the file exists, it will be opened.
specifier|const
name|FileEntry
operator|*
name|getFile
argument_list|(
argument|llvm::StringRef Filename
argument_list|,
argument|bool openFile = false
argument_list|)
block|;
comment|/// \brief Retrieve a file entry for a "virtual" file that acts as
comment|/// if there were a file with the given name on disk. The file
comment|/// itself is not accessed.
specifier|const
name|FileEntry
operator|*
name|getVirtualFile
argument_list|(
argument|llvm::StringRef Filename
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
specifier|const
name|FileEntry
operator|*
name|Entry
argument_list|,
name|std
operator|::
name|string
operator|*
name|ErrorStr
operator|=
literal|0
argument_list|)
block|;
name|llvm
operator|::
name|MemoryBuffer
operator|*
name|getBufferForFile
argument_list|(
argument|llvm::StringRef Filename
argument_list|,
argument|std::string *ErrorStr =
literal|0
argument_list|)
block|;
comment|// getNoncachedStatValue - Will get the 'stat' information for the given path.
comment|// If the path is relative, it will be resolved against the WorkingDir of the
comment|// FileManager's FileSystemOptions.
name|bool
name|getNoncachedStatValue
argument_list|(
argument|llvm::StringRef Path
argument_list|,
argument|struct stat&StatBuf
argument_list|)
block|;
comment|/// \brief If path is not absolute and FileSystemOptions set the working
comment|/// directory, the path is modified to be relative to the given
comment|/// working directory.
name|void
name|FixupRelativePath
argument_list|(
argument|llvm::SmallVectorImpl<char>&path
argument_list|)
specifier|const
block|;
comment|/// \brief Produce an array mapping from the unique IDs assigned to each
comment|/// file to the corresponding FileEntry pointer.
name|void
name|GetUniqueIDMapping
argument_list|(
argument|llvm::SmallVectorImpl<const FileEntry *>&UIDToFiles
argument_list|)
specifier|const
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

