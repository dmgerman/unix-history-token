begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- VirtualFileSystem.h - Virtual File System Layer ----------*- C++ -*-===//
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
comment|/// \file
end_comment

begin_comment
comment|/// \brief Defines the virtual file system interface vfs::FileSystem.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_CLANG_BASIC_VIRTUALFILESYSTEM_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_BASIC_VIRTUALFILESYSTEM_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/LLVM.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/IntrusiveRefCntPtr.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Optional.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Twine.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Chrono.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ErrorOr.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/FileSystem.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/SourceMgr.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/raw_ostream.h"
end_include

begin_include
include|#
directive|include
file|<algorithm>
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_include
include|#
directive|include
file|<ctime>
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_include
include|#
directive|include
file|<stack>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<system_error>
end_include

begin_include
include|#
directive|include
file|<utility>
end_include

begin_include
include|#
directive|include
file|<vector>
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
name|namespace
name|vfs
block|{
comment|/// \brief The result of a \p status operation.
name|class
name|Status
block|{
name|std
operator|::
name|string
name|Name
expr_stmt|;
name|llvm
operator|::
name|sys
operator|::
name|fs
operator|::
name|UniqueID
name|UID
expr_stmt|;
name|llvm
operator|::
name|sys
operator|::
name|TimePoint
operator|<
operator|>
name|MTime
expr_stmt|;
name|uint32_t
name|User
decl_stmt|;
name|uint32_t
name|Group
decl_stmt|;
name|uint64_t
name|Size
decl_stmt|;
name|llvm
operator|::
name|sys
operator|::
name|fs
operator|::
name|file_type
name|Type
expr_stmt|;
name|llvm
operator|::
name|sys
operator|::
name|fs
operator|::
name|perms
name|Perms
expr_stmt|;
name|public
label|:
name|bool
name|IsVFSMapped
decl_stmt|;
comment|// FIXME: remove when files support multiple names
name|public
label|:
name|Status
argument_list|()
operator|:
name|Type
argument_list|(
argument|llvm::sys::fs::file_type::status_error
argument_list|)
block|{}
name|Status
argument_list|(
specifier|const
name|llvm
operator|::
name|sys
operator|::
name|fs
operator|::
name|file_status
operator|&
name|Status
argument_list|)
expr_stmt|;
name|Status
argument_list|(
argument|StringRef Name
argument_list|,
argument|llvm::sys::fs::UniqueID UID
argument_list|,
argument|llvm::sys::TimePoint<> MTime
argument_list|,
argument|uint32_t User
argument_list|,
argument|uint32_t Group
argument_list|,
argument|uint64_t Size
argument_list|,
argument|llvm::sys::fs::file_type Type
argument_list|,
argument|llvm::sys::fs::perms Perms
argument_list|)
empty_stmt|;
comment|/// Get a copy of a Status with a different name.
specifier|static
name|Status
name|copyWithNewName
parameter_list|(
specifier|const
name|Status
modifier|&
name|In
parameter_list|,
name|StringRef
name|NewName
parameter_list|)
function_decl|;
specifier|static
name|Status
name|copyWithNewName
argument_list|(
specifier|const
name|llvm
operator|::
name|sys
operator|::
name|fs
operator|::
name|file_status
operator|&
name|In
argument_list|,
name|StringRef
name|NewName
argument_list|)
decl_stmt|;
comment|/// \brief Returns the name that should be used for this file or directory.
name|StringRef
name|getName
argument_list|()
specifier|const
block|{
return|return
name|Name
return|;
block|}
comment|/// @name Status interface from llvm::sys::fs
comment|/// @{
name|llvm
operator|::
name|sys
operator|::
name|fs
operator|::
name|file_type
name|getType
argument_list|()
specifier|const
block|{
return|return
name|Type
return|;
block|}
name|llvm
operator|::
name|sys
operator|::
name|fs
operator|::
name|perms
name|getPermissions
argument_list|()
specifier|const
block|{
return|return
name|Perms
return|;
block|}
name|llvm
operator|::
name|sys
operator|::
name|TimePoint
operator|<
operator|>
name|getLastModificationTime
argument_list|()
specifier|const
block|{
return|return
name|MTime
return|;
block|}
name|llvm
operator|::
name|sys
operator|::
name|fs
operator|::
name|UniqueID
name|getUniqueID
argument_list|()
specifier|const
block|{
return|return
name|UID
return|;
block|}
name|uint32_t
name|getUser
argument_list|()
specifier|const
block|{
return|return
name|User
return|;
block|}
name|uint32_t
name|getGroup
argument_list|()
specifier|const
block|{
return|return
name|Group
return|;
block|}
name|uint64_t
name|getSize
argument_list|()
specifier|const
block|{
return|return
name|Size
return|;
block|}
comment|/// @}
comment|/// @name Status queries
comment|/// These are static queries in llvm::sys::fs.
comment|/// @{
name|bool
name|equivalent
argument_list|(
specifier|const
name|Status
operator|&
name|Other
argument_list|)
decl|const
decl_stmt|;
name|bool
name|isDirectory
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isRegularFile
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isOther
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isSymlink
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isStatusKnown
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|exists
argument_list|()
specifier|const
expr_stmt|;
comment|/// @}
block|}
empty_stmt|;
comment|/// \brief Represents an open file.
name|class
name|File
block|{
name|public
label|:
comment|/// \brief Destroy the file after closing it (if open).
comment|/// Sub-classes should generally call close() inside their destructors.  We
comment|/// cannot do that from the base class, since close is virtual.
name|virtual
operator|~
name|File
argument_list|()
expr_stmt|;
comment|/// \brief Get the status of the file.
name|virtual
name|llvm
operator|::
name|ErrorOr
operator|<
name|Status
operator|>
name|status
argument_list|()
operator|=
literal|0
expr_stmt|;
comment|/// \brief Get the name of the file
name|virtual
name|llvm
operator|::
name|ErrorOr
operator|<
name|std
operator|::
name|string
operator|>
name|getName
argument_list|()
block|{
if|if
condition|(
name|auto
name|Status
init|=
name|status
argument_list|()
condition|)
return|return
name|Status
operator|->
name|getName
argument_list|()
operator|.
name|str
argument_list|()
return|;
else|else
return|return
name|Status
operator|.
name|getError
argument_list|()
return|;
block|}
comment|/// \brief Get the contents of the file as a \p MemoryBuffer.
name|virtual
name|llvm
operator|::
name|ErrorOr
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|llvm
operator|::
name|MemoryBuffer
operator|>>
name|getBuffer
argument_list|(
argument|const Twine&Name
argument_list|,
argument|int64_t FileSize = -
literal|1
argument_list|,
argument|bool RequiresNullTerminator = true
argument_list|,
argument|bool IsVolatile = false
argument_list|)
operator|=
literal|0
expr_stmt|;
comment|/// \brief Closes the file.
name|virtual
name|std
operator|::
name|error_code
name|close
argument_list|()
operator|=
literal|0
expr_stmt|;
block|}
empty_stmt|;
name|namespace
name|detail
block|{
comment|/// \brief An interface for virtual file systems to provide an iterator over the
comment|/// (non-recursive) contents of a directory.
struct|struct
name|DirIterImpl
block|{
name|virtual
operator|~
name|DirIterImpl
argument_list|()
expr_stmt|;
comment|/// \brief Sets \c CurrentEntry to the next entry in the directory on success,
comment|/// or returns a system-defined \c error_code.
name|virtual
name|std
operator|::
name|error_code
name|increment
argument_list|()
operator|=
literal|0
expr_stmt|;
name|Status
name|CurrentEntry
decl_stmt|;
block|}
struct|;
block|}
comment|// end namespace detail
comment|/// \brief An input iterator over the entries in a virtual path, similar to
comment|/// llvm::sys::fs::directory_iterator.
name|class
name|directory_iterator
block|{
name|std
operator|::
name|shared_ptr
operator|<
name|detail
operator|::
name|DirIterImpl
operator|>
name|Impl
expr_stmt|;
comment|// Input iterator semantics on copy
name|public
label|:
name|directory_iterator
argument_list|(
name|std
operator|::
name|shared_ptr
operator|<
name|detail
operator|::
name|DirIterImpl
operator|>
name|I
argument_list|)
operator|:
name|Impl
argument_list|(
argument|std::move(I)
argument_list|)
block|{
name|assert
argument_list|(
name|Impl
operator|.
name|get
argument_list|()
operator|!=
name|nullptr
operator|&&
literal|"requires non-null implementation"
argument_list|)
block|;
if|if
condition|(
operator|!
name|Impl
operator|->
name|CurrentEntry
operator|.
name|isStatusKnown
argument_list|()
condition|)
name|Impl
operator|.
name|reset
argument_list|()
expr_stmt|;
comment|// Normalize the end iterator to Impl == nullptr.
block|}
comment|/// \brief Construct an 'end' iterator.
name|directory_iterator
argument_list|()
operator|=
expr|default
expr_stmt|;
comment|/// \brief Equivalent to operator++, with an error code.
name|directory_iterator
modifier|&
name|increment
argument_list|(
name|std
operator|::
name|error_code
operator|&
name|EC
argument_list|)
block|{
name|assert
argument_list|(
name|Impl
operator|&&
literal|"attempting to increment past end"
argument_list|)
expr_stmt|;
name|EC
operator|=
name|Impl
operator|->
name|increment
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|Impl
operator|->
name|CurrentEntry
operator|.
name|isStatusKnown
argument_list|()
condition|)
name|Impl
operator|.
name|reset
argument_list|()
expr_stmt|;
comment|// Normalize the end iterator to Impl == nullptr.
return|return
operator|*
name|this
return|;
block|}
specifier|const
name|Status
operator|&
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
name|Impl
operator|->
name|CurrentEntry
return|;
block|}
specifier|const
name|Status
operator|*
name|operator
operator|->
expr|(
block|)
decl|const
block|{
return|return
operator|&
name|Impl
operator|->
name|CurrentEntry
return|;
block|}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|directory_iterator
operator|&
name|RHS
operator|)
specifier|const
block|{
if|if
condition|(
name|Impl
operator|&&
name|RHS
operator|.
name|Impl
condition|)
return|return
name|Impl
operator|->
name|CurrentEntry
operator|.
name|equivalent
argument_list|(
name|RHS
operator|.
name|Impl
operator|->
name|CurrentEntry
argument_list|)
return|;
return|return
operator|!
name|Impl
operator|&&
operator|!
name|RHS
operator|.
name|Impl
return|;
block|}
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|directory_iterator
operator|&
name|RHS
operator|)
specifier|const
block|{
return|return
operator|!
operator|(
operator|*
name|this
operator|==
name|RHS
operator|)
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|class
name|FileSystem
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief An input iterator over the recursive contents of a virtual path,
end_comment

begin_comment
comment|/// similar to llvm::sys::fs::recursive_directory_iterator.
end_comment

begin_decl_stmt
name|class
name|recursive_directory_iterator
block|{
typedef|typedef
name|std
operator|::
name|stack
operator|<
name|directory_iterator
operator|,
name|std
operator|::
name|vector
operator|<
name|directory_iterator
operator|>>
name|IterState
expr_stmt|;
name|FileSystem
modifier|*
name|FS
decl_stmt|;
name|std
operator|::
name|shared_ptr
operator|<
name|IterState
operator|>
name|State
expr_stmt|;
comment|// Input iterator semantics on copy.
name|public
label|:
name|recursive_directory_iterator
argument_list|(
name|FileSystem
operator|&
name|FS
argument_list|,
specifier|const
name|Twine
operator|&
name|Path
argument_list|,
name|std
operator|::
name|error_code
operator|&
name|EC
argument_list|)
expr_stmt|;
comment|/// \brief Construct an 'end' iterator.
name|recursive_directory_iterator
argument_list|()
operator|=
expr|default
expr_stmt|;
comment|/// \brief Equivalent to operator++, with an error code.
name|recursive_directory_iterator
modifier|&
name|increment
argument_list|(
name|std
operator|::
name|error_code
operator|&
name|EC
argument_list|)
decl_stmt|;
specifier|const
name|Status
operator|&
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
operator|*
name|State
operator|->
name|top
argument_list|()
return|;
block|}
specifier|const
name|Status
operator|*
name|operator
operator|->
expr|(
block|)
decl|const
block|{
return|return
operator|&
operator|*
name|State
operator|->
name|top
argument_list|()
return|;
block|}
end_decl_stmt

begin_expr_stmt
name|bool
name|operator
operator|==
operator|(
specifier|const
name|recursive_directory_iterator
operator|&
name|Other
operator|)
specifier|const
block|{
return|return
name|State
operator|==
name|Other
operator|.
name|State
return|;
comment|// identity
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|recursive_directory_iterator
operator|&
name|RHS
operator|)
specifier|const
block|{
return|return
operator|!
operator|(
operator|*
name|this
operator|==
name|RHS
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Gets the current level. Starting path is at level 0.
end_comment

begin_expr_stmt
name|int
name|level
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|State
operator|->
name|size
argument_list|()
operator|&&
literal|"Cannot get level without any iteration state"
argument_list|)
block|;
return|return
name|State
operator|->
name|size
argument_list|()
operator|-
literal|1
return|;
block|}
end_expr_stmt

begin_comment
unit|};
comment|/// \brief The virtual file system interface.
end_comment

begin_decl_stmt
name|class
name|FileSystem
range|:
name|public
name|llvm
operator|::
name|ThreadSafeRefCountedBase
operator|<
name|FileSystem
operator|>
block|{
name|public
operator|:
name|virtual
operator|~
name|FileSystem
argument_list|()
block|;
comment|/// \brief Get the status of the entry at \p Path, if one exists.
name|virtual
name|llvm
operator|::
name|ErrorOr
operator|<
name|Status
operator|>
name|status
argument_list|(
specifier|const
name|Twine
operator|&
name|Path
argument_list|)
operator|=
literal|0
block|;
comment|/// \brief Get a \p File object for the file at \p Path, if one exists.
name|virtual
name|llvm
operator|::
name|ErrorOr
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|File
operator|>>
name|openFileForRead
argument_list|(
specifier|const
name|Twine
operator|&
name|Path
argument_list|)
operator|=
literal|0
block|;
comment|/// This is a convenience method that opens a file, gets its content and then
comment|/// closes the file.
name|llvm
operator|::
name|ErrorOr
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|llvm
operator|::
name|MemoryBuffer
operator|>>
name|getBufferForFile
argument_list|(
argument|const Twine&Name
argument_list|,
argument|int64_t FileSize = -
literal|1
argument_list|,
argument|bool RequiresNullTerminator = true
argument_list|,
argument|bool IsVolatile = false
argument_list|)
block|;
comment|/// \brief Get a directory_iterator for \p Dir.
comment|/// \note The 'end' iterator is directory_iterator().
name|virtual
name|directory_iterator
name|dir_begin
argument_list|(
specifier|const
name|Twine
operator|&
name|Dir
argument_list|,
name|std
operator|::
name|error_code
operator|&
name|EC
argument_list|)
operator|=
literal|0
block|;
comment|/// Set the working directory. This will affect all following operations on
comment|/// this file system and may propagate down for nested file systems.
name|virtual
name|std
operator|::
name|error_code
name|setCurrentWorkingDirectory
argument_list|(
specifier|const
name|Twine
operator|&
name|Path
argument_list|)
operator|=
literal|0
block|;
comment|/// Get the working directory of this file system.
name|virtual
name|llvm
operator|::
name|ErrorOr
operator|<
name|std
operator|::
name|string
operator|>
name|getCurrentWorkingDirectory
argument_list|()
specifier|const
operator|=
literal|0
block|;
comment|/// Check whether a file exists. Provided for convenience.
name|bool
name|exists
argument_list|(
specifier|const
name|Twine
operator|&
name|Path
argument_list|)
block|;
comment|/// Make \a Path an absolute path.
comment|///
comment|/// Makes \a Path absolute using the current directory if it is not already.
comment|/// An empty \a Path will result in the current directory.
comment|///
comment|/// /absolute/path   => /absolute/path
comment|/// relative/../path =><current-directory>/relative/../path
comment|///
comment|/// \param Path A path that is modified to be an absolute path.
comment|/// \returns success if \a path has been made absolute, otherwise a
comment|///          platform-specific error_code.
name|std
operator|::
name|error_code
name|makeAbsolute
argument_list|(
argument|SmallVectorImpl<char>&Path
argument_list|)
specifier|const
block|; }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Gets an \p vfs::FileSystem for the 'real' file system, as seen by
end_comment

begin_comment
comment|/// the operating system.
end_comment

begin_expr_stmt
name|IntrusiveRefCntPtr
operator|<
name|FileSystem
operator|>
name|getRealFileSystem
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief A file system that allows overlaying one \p AbstractFileSystem on top
end_comment

begin_comment
comment|/// of another.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Consists of a stack of>=1 \p FileSystem objects, which are treated as being
end_comment

begin_comment
comment|/// one merged file system. When there is a directory that exists in more than
end_comment

begin_comment
comment|/// one file system, the \p OverlayFileSystem contains a directory containing
end_comment

begin_comment
comment|/// the union of their contents.  The attributes (permissions, etc.) of the
end_comment

begin_comment
comment|/// top-most (most recently added) directory are used.  When there is a file
end_comment

begin_comment
comment|/// that exists in more than one file system, the file in the top-most file
end_comment

begin_comment
comment|/// system overrides the other(s).
end_comment

begin_decl_stmt
name|class
name|OverlayFileSystem
range|:
name|public
name|FileSystem
block|{
typedef|typedef
name|SmallVector
operator|<
name|IntrusiveRefCntPtr
operator|<
name|FileSystem
operator|>
operator|,
literal|1
operator|>
name|FileSystemList
expr_stmt|;
comment|/// \brief The stack of file systems, implemented as a list in order of
comment|/// their addition.
name|FileSystemList
name|FSList
decl_stmt|;
end_decl_stmt

begin_label
name|public
label|:
end_label

begin_expr_stmt
name|OverlayFileSystem
argument_list|(
name|IntrusiveRefCntPtr
operator|<
name|FileSystem
operator|>
name|Base
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Pushes a file system on top of the stack.
end_comment

begin_decl_stmt
name|void
name|pushOverlay
argument_list|(
name|IntrusiveRefCntPtr
operator|<
name|FileSystem
operator|>
name|FS
argument_list|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|llvm
operator|::
name|ErrorOr
operator|<
name|Status
operator|>
name|status
argument_list|(
argument|const Twine&Path
argument_list|)
name|override
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|ErrorOr
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|File
operator|>>
name|openFileForRead
argument_list|(
argument|const Twine&Path
argument_list|)
name|override
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|directory_iterator
name|dir_begin
argument_list|(
specifier|const
name|Twine
operator|&
name|Dir
argument_list|,
name|std
operator|::
name|error_code
operator|&
name|EC
argument_list|)
name|override
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|llvm
operator|::
name|ErrorOr
operator|<
name|std
operator|::
name|string
operator|>
name|getCurrentWorkingDirectory
argument_list|()
specifier|const
name|override
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|error_code
name|setCurrentWorkingDirectory
argument_list|(
argument|const Twine&Path
argument_list|)
name|override
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|FileSystemList
operator|::
name|reverse_iterator
name|iterator
expr_stmt|;
end_typedef

begin_comment
comment|/// \brief Get an iterator pointing to the most recently added file system.
end_comment

begin_function
name|iterator
name|overlays_begin
parameter_list|()
block|{
return|return
name|FSList
operator|.
name|rbegin
argument_list|()
return|;
block|}
end_function

begin_comment
comment|/// \brief Get an iterator pointing one-past the least recently added file
end_comment

begin_comment
comment|/// system.
end_comment

begin_function
name|iterator
name|overlays_end
parameter_list|()
block|{
return|return
name|FSList
operator|.
name|rend
argument_list|()
return|;
block|}
end_function

begin_decl_stmt
unit|};
name|namespace
name|detail
block|{
name|class
name|InMemoryDirectory
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace detail
end_comment

begin_comment
comment|/// An in-memory file system.
end_comment

begin_decl_stmt
name|class
name|InMemoryFileSystem
range|:
name|public
name|FileSystem
block|{
name|std
operator|::
name|unique_ptr
operator|<
name|detail
operator|::
name|InMemoryDirectory
operator|>
name|Root
block|;
name|std
operator|::
name|string
name|WorkingDirectory
block|;
name|bool
name|UseNormalizedPaths
operator|=
name|true
block|;
name|public
operator|:
name|explicit
name|InMemoryFileSystem
argument_list|(
argument|bool UseNormalizedPaths = true
argument_list|)
block|;
operator|~
name|InMemoryFileSystem
argument_list|()
name|override
block|;
comment|/// Add a buffer to the VFS with a path. The VFS owns the buffer.
comment|/// \return true if the file was successfully added, false if the file already
comment|/// exists in the file system with different contents.
name|bool
name|addFile
argument_list|(
argument|const Twine&Path
argument_list|,
argument|time_t ModificationTime
argument_list|,
argument|std::unique_ptr<llvm::MemoryBuffer> Buffer
argument_list|)
block|;
comment|/// Add a buffer to the VFS with a path. The VFS does not own the buffer.
comment|/// \return true if the file was successfully added, false if the file already
comment|/// exists in the file system with different contents.
name|bool
name|addFileNoOwn
argument_list|(
argument|const Twine&Path
argument_list|,
argument|time_t ModificationTime
argument_list|,
argument|llvm::MemoryBuffer *Buffer
argument_list|)
block|;
name|std
operator|::
name|string
name|toString
argument_list|()
specifier|const
block|;
comment|/// Return true if this file system normalizes . and .. in paths.
name|bool
name|useNormalizedPaths
argument_list|()
specifier|const
block|{
return|return
name|UseNormalizedPaths
return|;
block|}
name|llvm
operator|::
name|ErrorOr
operator|<
name|Status
operator|>
name|status
argument_list|(
argument|const Twine&Path
argument_list|)
name|override
block|;
name|llvm
operator|::
name|ErrorOr
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|File
operator|>>
name|openFileForRead
argument_list|(
argument|const Twine&Path
argument_list|)
name|override
block|;
name|directory_iterator
name|dir_begin
argument_list|(
argument|const Twine&Dir
argument_list|,
argument|std::error_code&EC
argument_list|)
name|override
block|;
name|llvm
operator|::
name|ErrorOr
operator|<
name|std
operator|::
name|string
operator|>
name|getCurrentWorkingDirectory
argument_list|()
specifier|const
name|override
block|{
return|return
name|WorkingDirectory
return|;
block|}
name|std
operator|::
name|error_code
name|setCurrentWorkingDirectory
argument_list|(
argument|const Twine&Path
argument_list|)
name|override
block|; }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Get a globally unique ID for a virtual file or directory.
end_comment

begin_expr_stmt
name|llvm
operator|::
name|sys
operator|::
name|fs
operator|::
name|UniqueID
name|getNextVirtualUniqueID
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Gets a \p FileSystem for a virtual file system described in YAML
end_comment

begin_comment
comment|/// format.
end_comment

begin_expr_stmt
name|IntrusiveRefCntPtr
operator|<
name|FileSystem
operator|>
name|getVFSFromYAML
argument_list|(
argument|std::unique_ptr<llvm::MemoryBuffer> Buffer
argument_list|,
argument|llvm::SourceMgr::DiagHandlerTy DiagHandler
argument_list|,
argument|StringRef YAMLFilePath
argument_list|,
argument|void *DiagContext = nullptr
argument_list|,
argument|IntrusiveRefCntPtr<FileSystem> ExternalFS = getRealFileSystem()
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|YAMLVFSEntry
block|{
name|template
operator|<
name|typename
name|T1
operator|,
name|typename
name|T2
operator|>
name|YAMLVFSEntry
argument_list|(
name|T1
operator|&&
name|VPath
argument_list|,
name|T2
operator|&&
name|RPath
argument_list|)
operator|:
name|VPath
argument_list|(
name|std
operator|::
name|forward
operator|<
name|T1
operator|>
operator|(
name|VPath
operator|)
argument_list|)
operator|,
name|RPath
argument_list|(
argument|std::forward<T2>(RPath)
argument_list|)
block|{}
name|std
operator|::
name|string
name|VPath
expr_stmt|;
name|std
operator|::
name|string
name|RPath
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/// \brief Collect all pairs of<virtual path, real path> entries from the
end_comment

begin_comment
comment|/// \p YAMLFilePath. This is used by the module dependency collector to forward
end_comment

begin_comment
comment|/// the entries into the reproducer output VFS YAML file.
end_comment

begin_decl_stmt
name|void
name|collectVFSFromYAML
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|llvm
operator|::
name|MemoryBuffer
operator|>
name|Buffer
argument_list|,
name|llvm
operator|::
name|SourceMgr
operator|::
name|DiagHandlerTy
name|DiagHandler
argument_list|,
name|StringRef
name|YAMLFilePath
argument_list|,
name|SmallVectorImpl
operator|<
name|YAMLVFSEntry
operator|>
operator|&
name|CollectedEntries
argument_list|,
name|void
operator|*
name|DiagContext
operator|=
name|nullptr
argument_list|,
name|IntrusiveRefCntPtr
operator|<
name|FileSystem
operator|>
name|ExternalFS
operator|=
name|getRealFileSystem
argument_list|()
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|YAMLVFSWriter
block|{
name|std
operator|::
name|vector
operator|<
name|YAMLVFSEntry
operator|>
name|Mappings
expr_stmt|;
name|Optional
operator|<
name|bool
operator|>
name|IsCaseSensitive
expr_stmt|;
name|Optional
operator|<
name|bool
operator|>
name|IsOverlayRelative
expr_stmt|;
name|Optional
operator|<
name|bool
operator|>
name|UseExternalNames
expr_stmt|;
name|Optional
operator|<
name|bool
operator|>
name|IgnoreNonExistentContents
expr_stmt|;
name|std
operator|::
name|string
name|OverlayDir
expr_stmt|;
name|public
label|:
name|YAMLVFSWriter
argument_list|()
operator|=
expr|default
expr_stmt|;
name|void
name|addFileMapping
parameter_list|(
name|StringRef
name|VirtualPath
parameter_list|,
name|StringRef
name|RealPath
parameter_list|)
function_decl|;
name|void
name|setCaseSensitivity
parameter_list|(
name|bool
name|CaseSensitive
parameter_list|)
block|{
name|IsCaseSensitive
operator|=
name|CaseSensitive
expr_stmt|;
block|}
name|void
name|setUseExternalNames
parameter_list|(
name|bool
name|UseExtNames
parameter_list|)
block|{
name|UseExternalNames
operator|=
name|UseExtNames
expr_stmt|;
block|}
name|void
name|setIgnoreNonExistentContents
parameter_list|(
name|bool
name|IgnoreContents
parameter_list|)
block|{
name|IgnoreNonExistentContents
operator|=
name|IgnoreContents
expr_stmt|;
block|}
name|void
name|setOverlayDir
parameter_list|(
name|StringRef
name|OverlayDirectory
parameter_list|)
block|{
name|IsOverlayRelative
operator|=
name|true
expr_stmt|;
name|OverlayDir
operator|.
name|assign
argument_list|(
name|OverlayDirectory
operator|.
name|str
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|void
name|write
argument_list|(
name|llvm
operator|::
name|raw_ostream
operator|&
name|OS
argument_list|)
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// end namespace vfs
end_comment

begin_comment
unit|}
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CLANG_BASIC_VIRTUALFILESYSTEM_H
end_comment

end_unit

