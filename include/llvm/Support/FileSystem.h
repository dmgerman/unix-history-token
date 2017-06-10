begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/Support/FileSystem.h - File System OS Concept -------*- C++ -*-===//
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
comment|// This file declares the llvm::sys::fs namespace. It is designed after
end_comment

begin_comment
comment|// TR2/boost filesystem (v3), but modified to remove exception handling and the
end_comment

begin_comment
comment|// path class.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// All functions return an error_code and their actual work via the last out
end_comment

begin_comment
comment|// argument. The out argument is defined if and only if errc::success is
end_comment

begin_comment
comment|// returned. A function may return any error code in the generic or system
end_comment

begin_comment
comment|// category. However, they shall be equivalent to any error conditions listed
end_comment

begin_comment
comment|// in each functions respective documentation if the condition applies. [ note:
end_comment

begin_comment
comment|// this does not guarantee that error_code will be in the set of explicitly
end_comment

begin_comment
comment|// listed codes, but it does guarantee that if any of the explicitly listed
end_comment

begin_comment
comment|// errors occur, the correct error_code will be used ]. All functions may
end_comment

begin_comment
comment|// return errc::not_enough_memory if there is not enough memory to complete the
end_comment

begin_comment
comment|// operation.
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
name|LLVM_SUPPORT_FILESYSTEM_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_FILESYSTEM_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/SmallString.h"
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
file|"llvm/Support/ErrorHandling.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ErrorOr.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/MD5.h"
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
file|<tuple>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_STAT_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|sys
block|{
name|namespace
name|fs
block|{
comment|/// An enumeration for the file system's view of the type.
name|enum
name|class
name|file_type
block|{
name|status_error
operator|,
name|file_not_found
operator|,
name|regular_file
operator|,
name|directory_file
operator|,
name|symlink_file
operator|,
name|block_file
operator|,
name|character_file
operator|,
name|fifo_file
operator|,
name|socket_file
operator|,
name|type_unknown
block|}
empty_stmt|;
comment|/// space_info - Self explanatory.
struct|struct
name|space_info
block|{
name|uint64_t
name|capacity
decl_stmt|;
name|uint64_t
name|free
decl_stmt|;
name|uint64_t
name|available
decl_stmt|;
block|}
struct|;
enum|enum
name|perms
block|{
name|no_perms
init|=
literal|0
block|,
name|owner_read
init|=
literal|0400
block|,
name|owner_write
init|=
literal|0200
block|,
name|owner_exe
init|=
literal|0100
block|,
name|owner_all
init|=
name|owner_read
operator||
name|owner_write
operator||
name|owner_exe
block|,
name|group_read
init|=
literal|040
block|,
name|group_write
init|=
literal|020
block|,
name|group_exe
init|=
literal|010
block|,
name|group_all
init|=
name|group_read
operator||
name|group_write
operator||
name|group_exe
block|,
name|others_read
init|=
literal|04
block|,
name|others_write
init|=
literal|02
block|,
name|others_exe
init|=
literal|01
block|,
name|others_all
init|=
name|others_read
operator||
name|others_write
operator||
name|others_exe
block|,
name|all_read
init|=
name|owner_read
operator||
name|group_read
operator||
name|others_read
block|,
name|all_write
init|=
name|owner_write
operator||
name|group_write
operator||
name|others_write
block|,
name|all_exe
init|=
name|owner_exe
operator||
name|group_exe
operator||
name|others_exe
block|,
name|all_all
init|=
name|owner_all
operator||
name|group_all
operator||
name|others_all
block|,
name|set_uid_on_exe
init|=
literal|04000
block|,
name|set_gid_on_exe
init|=
literal|02000
block|,
name|sticky_bit
init|=
literal|01000
block|,
name|all_perms
init|=
name|all_all
operator||
name|set_uid_on_exe
operator||
name|set_gid_on_exe
operator||
name|sticky_bit
block|,
name|perms_not_known
init|=
literal|0xFFFF
block|}
enum|;
comment|// Helper functions so that you can use& and | to manipulate perms bits:
specifier|inline
name|perms
name|operator
operator||
operator|(
name|perms
name|l
operator|,
name|perms
name|r
operator|)
block|{
return|return
name|static_cast
operator|<
name|perms
operator|>
operator|(
name|static_cast
operator|<
name|unsigned
name|short
operator|>
operator|(
name|l
operator|)
operator||
name|static_cast
operator|<
name|unsigned
name|short
operator|>
operator|(
name|r
operator|)
operator|)
return|;
block|}
specifier|inline
name|perms
name|operator
function|&(
name|perms
name|l
function|,
name|perms
function|r
block|)
block|{
return|return
name|static_cast
operator|<
name|perms
operator|>
operator|(
name|static_cast
operator|<
name|unsigned
name|short
operator|>
operator|(
name|l
operator|)
operator|&
name|static_cast
operator|<
name|unsigned
name|short
operator|>
operator|(
name|r
operator|)
operator|)
return|;
block|}
specifier|inline
name|perms
operator|&
name|operator
operator||=
operator|(
name|perms
operator|&
name|l
operator|,
name|perms
name|r
operator|)
block|{
name|l
operator|=
name|l
operator||
name|r
block|;
return|return
name|l
return|;
block|}
specifier|inline
name|perms
operator|&
name|operator
operator|&=
operator|(
name|perms
operator|&
name|l
operator|,
name|perms
name|r
operator|)
block|{
name|l
operator|=
name|l
operator|&
name|r
block|;
return|return
name|l
return|;
block|}
specifier|inline
name|perms
name|operator
operator|~
operator|(
name|perms
name|x
operator|)
block|{
comment|// Avoid UB by explicitly truncating the (unsigned) ~ result.
return|return
name|static_cast
operator|<
name|perms
operator|>
operator|(
name|static_cast
operator|<
name|unsigned
name|short
operator|>
operator|(
operator|~
name|static_cast
operator|<
name|unsigned
name|short
operator|>
operator|(
name|x
operator|)
operator|)
operator|)
return|;
block|}
name|class
name|UniqueID
block|{
name|uint64_t
name|Device
decl_stmt|;
name|uint64_t
name|File
decl_stmt|;
name|public
label|:
name|UniqueID
argument_list|()
operator|=
expr|default
expr_stmt|;
name|UniqueID
argument_list|(
argument|uint64_t Device
argument_list|,
argument|uint64_t File
argument_list|)
block|:
name|Device
argument_list|(
name|Device
argument_list|)
operator|,
name|File
argument_list|(
argument|File
argument_list|)
block|{}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|UniqueID
operator|&
name|Other
operator|)
specifier|const
block|{
return|return
name|Device
operator|==
name|Other
operator|.
name|Device
operator|&&
name|File
operator|==
name|Other
operator|.
name|File
return|;
block|}
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|UniqueID
operator|&
name|Other
operator|)
specifier|const
block|{
return|return
operator|!
operator|(
operator|*
name|this
operator|==
name|Other
operator|)
return|;
block|}
name|bool
name|operator
operator|<
operator|(
specifier|const
name|UniqueID
operator|&
name|Other
operator|)
specifier|const
block|{
return|return
name|std
operator|::
name|tie
argument_list|(
name|Device
argument_list|,
name|File
argument_list|)
operator|<
name|std
operator|::
name|tie
argument_list|(
name|Other
operator|.
name|Device
argument_list|,
name|Other
operator|.
name|File
argument_list|)
return|;
block|}
name|uint64_t
name|getDevice
argument_list|()
specifier|const
block|{
return|return
name|Device
return|;
block|}
name|uint64_t
name|getFile
argument_list|()
specifier|const
block|{
return|return
name|File
return|;
block|}
block|}
empty_stmt|;
comment|/// file_status - Represents the result of a call to stat and friends. It has
comment|///               a platform-specific member to store the result.
name|class
name|file_status
block|{
name|friend
name|bool
name|equivalent
parameter_list|(
name|file_status
name|A
parameter_list|,
name|file_status
name|B
parameter_list|)
function_decl|;
if|#
directive|if
name|defined
argument_list|(
name|LLVM_ON_UNIX
argument_list|)
name|dev_t
name|fs_st_dev
init|=
literal|0
decl_stmt|;
name|nlink_t
name|fs_st_nlinks
init|=
literal|0
decl_stmt|;
name|ino_t
name|fs_st_ino
init|=
literal|0
decl_stmt|;
name|time_t
name|fs_st_atime
init|=
literal|0
decl_stmt|;
name|time_t
name|fs_st_mtime
init|=
literal|0
decl_stmt|;
name|uid_t
name|fs_st_uid
init|=
literal|0
decl_stmt|;
name|gid_t
name|fs_st_gid
init|=
literal|0
decl_stmt|;
name|off_t
name|fs_st_size
init|=
literal|0
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|LLVM_ON_WIN32
argument_list|)
name|uint32_t
name|NumLinks
init|=
literal|0
decl_stmt|;
name|uint32_t
name|LastAccessedTimeHigh
init|=
literal|0
decl_stmt|;
name|uint32_t
name|LastAccessedTimeLow
init|=
literal|0
decl_stmt|;
name|uint32_t
name|LastWriteTimeHigh
init|=
literal|0
decl_stmt|;
name|uint32_t
name|LastWriteTimeLow
init|=
literal|0
decl_stmt|;
name|uint32_t
name|VolumeSerialNumber
init|=
literal|0
decl_stmt|;
name|uint32_t
name|FileSizeHigh
init|=
literal|0
decl_stmt|;
name|uint32_t
name|FileSizeLow
init|=
literal|0
decl_stmt|;
name|uint32_t
name|FileIndexHigh
init|=
literal|0
decl_stmt|;
name|uint32_t
name|FileIndexLow
init|=
literal|0
decl_stmt|;
endif|#
directive|endif
name|file_type
name|Type
init|=
name|file_type
operator|::
name|status_error
decl_stmt|;
name|perms
name|Perms
init|=
name|perms_not_known
decl_stmt|;
name|public
label|:
if|#
directive|if
name|defined
argument_list|(
name|LLVM_ON_UNIX
argument_list|)
name|file_status
argument_list|()
operator|=
expr|default
expr_stmt|;
name|file_status
argument_list|(
argument|file_type Type
argument_list|)
block|:
name|Type
argument_list|(
argument|Type
argument_list|)
block|{}
name|file_status
argument_list|(
argument|file_type Type
argument_list|,
argument|perms Perms
argument_list|,
argument|dev_t Dev
argument_list|,
argument|nlink_t Links
argument_list|,
argument|ino_t Ino
argument_list|,
argument|time_t ATime
argument_list|,
argument|time_t MTime
argument_list|,
argument|uid_t UID
argument_list|,
argument|gid_t GID
argument_list|,
argument|off_t Size
argument_list|)
block|:
name|fs_st_dev
argument_list|(
name|Dev
argument_list|)
operator|,
name|fs_st_nlinks
argument_list|(
name|Links
argument_list|)
operator|,
name|fs_st_ino
argument_list|(
name|Ino
argument_list|)
operator|,
name|fs_st_atime
argument_list|(
name|ATime
argument_list|)
operator|,
name|fs_st_mtime
argument_list|(
name|MTime
argument_list|)
operator|,
name|fs_st_uid
argument_list|(
name|UID
argument_list|)
operator|,
name|fs_st_gid
argument_list|(
name|GID
argument_list|)
operator|,
name|fs_st_size
argument_list|(
name|Size
argument_list|)
operator|,
name|Type
argument_list|(
name|Type
argument_list|)
operator|,
name|Perms
argument_list|(
argument|Perms
argument_list|)
block|{}
elif|#
directive|elif
name|defined
argument_list|(
name|LLVM_ON_WIN32
argument_list|)
name|file_status
argument_list|()
operator|=
expr|default
expr_stmt|;
name|file_status
argument_list|(
argument|file_type Type
argument_list|)
block|:
name|Type
argument_list|(
argument|Type
argument_list|)
block|{}
name|file_status
argument_list|(
argument|file_type Type
argument_list|,
argument|perms Perms
argument_list|,
argument|uint32_t LinkCount
argument_list|,
argument|uint32_t LastAccessTimeHigh
argument_list|,
argument|uint32_t LastAccessTimeLow
argument_list|,
argument|uint32_t LastWriteTimeHigh
argument_list|,
argument|uint32_t LastWriteTimeLow
argument_list|,
argument|uint32_t VolumeSerialNumber
argument_list|,
argument|uint32_t FileSizeHigh
argument_list|,
argument|uint32_t FileSizeLow
argument_list|,
argument|uint32_t FileIndexHigh
argument_list|,
argument|uint32_t FileIndexLow
argument_list|)
block|:
name|NumLinks
argument_list|(
name|LinkCount
argument_list|)
operator|,
name|LastAccessedTimeHigh
argument_list|(
name|LastAccessTimeHigh
argument_list|)
operator|,
name|LastAccessedTimeLow
argument_list|(
name|LastAccessTimeLow
argument_list|)
operator|,
name|LastWriteTimeHigh
argument_list|(
name|LastWriteTimeHigh
argument_list|)
operator|,
name|LastWriteTimeLow
argument_list|(
name|LastWriteTimeLow
argument_list|)
operator|,
name|VolumeSerialNumber
argument_list|(
name|VolumeSerialNumber
argument_list|)
operator|,
name|FileSizeHigh
argument_list|(
name|FileSizeHigh
argument_list|)
operator|,
name|FileSizeLow
argument_list|(
name|FileSizeLow
argument_list|)
operator|,
name|FileIndexHigh
argument_list|(
name|FileIndexHigh
argument_list|)
operator|,
name|FileIndexLow
argument_list|(
name|FileIndexLow
argument_list|)
operator|,
name|Type
argument_list|(
name|Type
argument_list|)
operator|,
name|Perms
argument_list|(
argument|Perms
argument_list|)
block|{}
endif|#
directive|endif
comment|// getters
name|file_type
name|type
argument_list|()
specifier|const
block|{
return|return
name|Type
return|;
block|}
name|perms
name|permissions
argument_list|()
specifier|const
block|{
return|return
name|Perms
return|;
block|}
name|TimePoint
operator|<
operator|>
name|getLastAccessedTime
argument_list|()
specifier|const
expr_stmt|;
name|TimePoint
operator|<
operator|>
name|getLastModificationTime
argument_list|()
specifier|const
expr_stmt|;
name|UniqueID
name|getUniqueID
argument_list|()
specifier|const
expr_stmt|;
name|uint32_t
name|getLinkCount
argument_list|()
specifier|const
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|LLVM_ON_UNIX
argument_list|)
name|uint32_t
name|getUser
argument_list|()
specifier|const
block|{
return|return
name|fs_st_uid
return|;
block|}
name|uint32_t
name|getGroup
argument_list|()
specifier|const
block|{
return|return
name|fs_st_gid
return|;
block|}
name|uint64_t
name|getSize
argument_list|()
specifier|const
block|{
return|return
name|fs_st_size
return|;
block|}
elif|#
directive|elif
name|defined
argument_list|(
name|LLVM_ON_WIN32
argument_list|)
name|uint32_t
name|getUser
argument_list|()
specifier|const
block|{
return|return
literal|9999
return|;
comment|// Not applicable to Windows, so...
block|}
name|uint32_t
name|getGroup
argument_list|()
specifier|const
block|{
return|return
literal|9999
return|;
comment|// Not applicable to Windows, so...
block|}
name|uint64_t
name|getSize
argument_list|()
specifier|const
block|{
return|return
operator|(
name|uint64_t
argument_list|(
name|FileSizeHigh
argument_list|)
operator|<<
literal|32
operator|)
operator|+
name|FileSizeLow
return|;
block|}
endif|#
directive|endif
comment|// setters
name|void
name|type
parameter_list|(
name|file_type
name|v
parameter_list|)
block|{
name|Type
operator|=
name|v
expr_stmt|;
block|}
name|void
name|permissions
parameter_list|(
name|perms
name|p
parameter_list|)
block|{
name|Perms
operator|=
name|p
expr_stmt|;
block|}
block|}
empty_stmt|;
comment|/// @}
comment|/// @name Physical Operators
comment|/// @{
comment|/// @brief Make \a path an absolute path.
comment|///
comment|/// Makes \a path absolute using the \a current_directory if it is not already.
comment|/// An empty \a path will result in the \a current_directory.
comment|///
comment|/// /absolute/path   => /absolute/path
comment|/// relative/../path =><current-directory>/relative/../path
comment|///
comment|/// @param path A path that is modified to be an absolute path.
comment|/// @returns errc::success if \a path has been made absolute, otherwise a
comment|///          platform-specific error_code.
name|std
operator|::
name|error_code
name|make_absolute
argument_list|(
specifier|const
name|Twine
operator|&
name|current_directory
argument_list|,
name|SmallVectorImpl
operator|<
name|char
operator|>
operator|&
name|path
argument_list|)
expr_stmt|;
comment|/// @brief Make \a path an absolute path.
comment|///
comment|/// Makes \a path absolute using the current directory if it is not already. An
comment|/// empty \a path will result in the current directory.
comment|///
comment|/// /absolute/path   => /absolute/path
comment|/// relative/../path =><current-directory>/relative/../path
comment|///
comment|/// @param path A path that is modified to be an absolute path.
comment|/// @returns errc::success if \a path has been made absolute, otherwise a
comment|///          platform-specific error_code.
name|std
operator|::
name|error_code
name|make_absolute
argument_list|(
name|SmallVectorImpl
operator|<
name|char
operator|>
operator|&
name|path
argument_list|)
expr_stmt|;
comment|/// @brief Create all the non-existent directories in path.
comment|///
comment|/// @param path Directories to create.
comment|/// @returns errc::success if is_directory(path), otherwise a platform
comment|///          specific error_code. If IgnoreExisting is false, also returns
comment|///          error if the directory already existed.
name|std
operator|::
name|error_code
name|create_directories
argument_list|(
argument|const Twine&path
argument_list|,
argument|bool IgnoreExisting = true
argument_list|,
argument|perms Perms = owner_all | group_all
argument_list|)
expr_stmt|;
comment|/// @brief Create the directory in path.
comment|///
comment|/// @param path Directory to create.
comment|/// @returns errc::success if is_directory(path), otherwise a platform
comment|///          specific error_code. If IgnoreExisting is false, also returns
comment|///          error if the directory already existed.
name|std
operator|::
name|error_code
name|create_directory
argument_list|(
argument|const Twine&path
argument_list|,
argument|bool IgnoreExisting = true
argument_list|,
argument|perms Perms = owner_all | group_all
argument_list|)
expr_stmt|;
comment|/// @brief Create a link from \a from to \a to.
comment|///
comment|/// The link may be a soft or a hard link, depending on the platform. The caller
comment|/// may not assume which one. Currently on windows it creates a hard link since
comment|/// soft links require extra privileges. On unix, it creates a soft link since
comment|/// hard links don't work on SMB file systems.
comment|///
comment|/// @param to The path to hard link to.
comment|/// @param from The path to hard link from. This is created.
comment|/// @returns errc::success if the link was created, otherwise a platform
comment|/// specific error_code.
name|std
operator|::
name|error_code
name|create_link
argument_list|(
specifier|const
name|Twine
operator|&
name|to
argument_list|,
specifier|const
name|Twine
operator|&
name|from
argument_list|)
expr_stmt|;
comment|/// Create a hard link from \a from to \a to, or return an error.
comment|///
comment|/// @param to The path to hard link to.
comment|/// @param from The path to hard link from. This is created.
comment|/// @returns errc::success if the link was created, otherwise a platform
comment|/// specific error_code.
name|std
operator|::
name|error_code
name|create_hard_link
argument_list|(
specifier|const
name|Twine
operator|&
name|to
argument_list|,
specifier|const
name|Twine
operator|&
name|from
argument_list|)
expr_stmt|;
comment|/// @brief Collapse all . and .. patterns, resolve all symlinks, and optionally
comment|///        expand ~ expressions to the user's home directory.
comment|///
comment|/// @param path The path to resolve.
comment|/// @param output The location to store the resolved path.
comment|/// @param expand_tilde If true, resolves ~ expressions to the user's home
comment|///                     directory.
name|std
operator|::
name|error_code
name|real_path
argument_list|(
argument|const Twine&path
argument_list|,
argument|SmallVectorImpl<char>&output
argument_list|,
argument|bool expand_tilde = false
argument_list|)
expr_stmt|;
comment|/// @brief Get the current path.
comment|///
comment|/// @param result Holds the current path on return.
comment|/// @returns errc::success if the current path has been stored in result,
comment|///          otherwise a platform-specific error_code.
name|std
operator|::
name|error_code
name|current_path
argument_list|(
name|SmallVectorImpl
operator|<
name|char
operator|>
operator|&
name|result
argument_list|)
expr_stmt|;
comment|/// @brief Set the current path.
comment|///
comment|/// @param path The path to set.
comment|/// @returns errc::success if the current path was successfully set,
comment|///          otherwise a platform-specific error_code.
name|std
operator|::
name|error_code
name|set_current_path
argument_list|(
specifier|const
name|Twine
operator|&
name|path
argument_list|)
expr_stmt|;
comment|/// @brief Remove path. Equivalent to POSIX remove().
comment|///
comment|/// @param path Input path.
comment|/// @returns errc::success if path has been removed or didn't exist, otherwise a
comment|///          platform-specific error code. If IgnoreNonExisting is false, also
comment|///          returns error if the file didn't exist.
name|std
operator|::
name|error_code
name|remove
argument_list|(
argument|const Twine&path
argument_list|,
argument|bool IgnoreNonExisting = true
argument_list|)
expr_stmt|;
comment|/// @brief Recursively delete a directory.
comment|///
comment|/// @param path Input path.
comment|/// @returns errc::success if path has been removed or didn't exist, otherwise a
comment|///          platform-specific error code.
name|std
operator|::
name|error_code
name|remove_directories
argument_list|(
argument|const Twine&path
argument_list|,
argument|bool IgnoreErrors = true
argument_list|)
expr_stmt|;
comment|/// @brief Rename \a from to \a to. Files are renamed as if by POSIX rename().
comment|///
comment|/// @param from The path to rename from.
comment|/// @param to The path to rename to. This is created.
name|std
operator|::
name|error_code
name|rename
argument_list|(
specifier|const
name|Twine
operator|&
name|from
argument_list|,
specifier|const
name|Twine
operator|&
name|to
argument_list|)
expr_stmt|;
comment|/// @brief Copy the contents of \a From to \a To.
comment|///
comment|/// @param From The path to copy from.
comment|/// @param To The path to copy to. This is created.
name|std
operator|::
name|error_code
name|copy_file
argument_list|(
specifier|const
name|Twine
operator|&
name|From
argument_list|,
specifier|const
name|Twine
operator|&
name|To
argument_list|)
expr_stmt|;
comment|/// @brief Resize path to size. File is resized as if by POSIX truncate().
comment|///
comment|/// @param FD Input file descriptor.
comment|/// @param Size Size to resize to.
comment|/// @returns errc::success if \a path has been resized to \a size, otherwise a
comment|///          platform-specific error_code.
name|std
operator|::
name|error_code
name|resize_file
argument_list|(
argument|int FD
argument_list|,
argument|uint64_t Size
argument_list|)
expr_stmt|;
comment|/// @brief Compute an MD5 hash of a file's contents.
comment|///
comment|/// @param FD Input file descriptor.
comment|/// @returns An MD5Result with the hash computed, if successful, otherwise a
comment|///          std::error_code.
name|ErrorOr
operator|<
name|MD5
operator|::
name|MD5Result
operator|>
name|md5_contents
argument_list|(
argument|int FD
argument_list|)
expr_stmt|;
comment|/// @brief Version of compute_md5 that doesn't require an open file descriptor.
name|ErrorOr
operator|<
name|MD5
operator|::
name|MD5Result
operator|>
name|md5_contents
argument_list|(
specifier|const
name|Twine
operator|&
name|Path
argument_list|)
expr_stmt|;
comment|/// @}
comment|/// @name Physical Observers
comment|/// @{
comment|/// @brief Does file exist?
comment|///
comment|/// @param status A file_status previously returned from stat.
comment|/// @returns True if the file represented by status exists, false if it does
comment|///          not.
name|bool
name|exists
parameter_list|(
name|file_status
name|status
parameter_list|)
function_decl|;
name|enum
name|class
name|AccessMode
block|{
name|Exist
operator|,
name|Write
operator|,
name|Execute
block|}
empty_stmt|;
comment|/// @brief Can the file be accessed?
comment|///
comment|/// @param Path Input path.
comment|/// @returns errc::success if the path can be accessed, otherwise a
comment|///          platform-specific error_code.
name|std
operator|::
name|error_code
name|access
argument_list|(
argument|const Twine&Path
argument_list|,
argument|AccessMode Mode
argument_list|)
expr_stmt|;
comment|/// @brief Does file exist?
comment|///
comment|/// @param Path Input path.
comment|/// @returns True if it exists, false otherwise.
specifier|inline
name|bool
name|exists
parameter_list|(
specifier|const
name|Twine
modifier|&
name|Path
parameter_list|)
block|{
return|return
operator|!
name|access
argument_list|(
name|Path
argument_list|,
name|AccessMode
operator|::
name|Exist
argument_list|)
return|;
block|}
comment|/// @brief Can we execute this file?
comment|///
comment|/// @param Path Input path.
comment|/// @returns True if we can execute it, false otherwise.
name|bool
name|can_execute
parameter_list|(
specifier|const
name|Twine
modifier|&
name|Path
parameter_list|)
function_decl|;
comment|/// @brief Can we write this file?
comment|///
comment|/// @param Path Input path.
comment|/// @returns True if we can write to it, false otherwise.
specifier|inline
name|bool
name|can_write
parameter_list|(
specifier|const
name|Twine
modifier|&
name|Path
parameter_list|)
block|{
return|return
operator|!
name|access
argument_list|(
name|Path
argument_list|,
name|AccessMode
operator|::
name|Write
argument_list|)
return|;
block|}
comment|/// @brief Do file_status's represent the same thing?
comment|///
comment|/// @param A Input file_status.
comment|/// @param B Input file_status.
comment|///
comment|/// assert(status_known(A) || status_known(B));
comment|///
comment|/// @returns True if A and B both represent the same file system entity, false
comment|///          otherwise.
name|bool
name|equivalent
parameter_list|(
name|file_status
name|A
parameter_list|,
name|file_status
name|B
parameter_list|)
function_decl|;
comment|/// @brief Do paths represent the same thing?
comment|///
comment|/// assert(status_known(A) || status_known(B));
comment|///
comment|/// @param A Input path A.
comment|/// @param B Input path B.
comment|/// @param result Set to true if stat(A) and stat(B) have the same device and
comment|///               inode (or equivalent).
comment|/// @returns errc::success if result has been successfully set, otherwise a
comment|///          platform-specific error_code.
name|std
operator|::
name|error_code
name|equivalent
argument_list|(
specifier|const
name|Twine
operator|&
name|A
argument_list|,
specifier|const
name|Twine
operator|&
name|B
argument_list|,
name|bool
operator|&
name|result
argument_list|)
expr_stmt|;
comment|/// @brief Simpler version of equivalent for clients that don't need to
comment|///        differentiate between an error and false.
specifier|inline
name|bool
name|equivalent
parameter_list|(
specifier|const
name|Twine
modifier|&
name|A
parameter_list|,
specifier|const
name|Twine
modifier|&
name|B
parameter_list|)
block|{
name|bool
name|result
decl_stmt|;
return|return
operator|!
name|equivalent
argument_list|(
name|A
argument_list|,
name|B
argument_list|,
name|result
argument_list|)
operator|&&
name|result
return|;
block|}
comment|/// @brief Is the file mounted on a local filesystem?
comment|///
comment|/// @param path Input path.
comment|/// @param result Set to true if \a path is on fixed media such as a hard disk,
comment|///               false if it is not.
comment|/// @returns errc::success if result has been successfully set, otherwise a
comment|///          platform specific error_code.
name|std
operator|::
name|error_code
name|is_local
argument_list|(
specifier|const
name|Twine
operator|&
name|path
argument_list|,
name|bool
operator|&
name|result
argument_list|)
expr_stmt|;
comment|/// @brief Version of is_local accepting an open file descriptor.
name|std
operator|::
name|error_code
name|is_local
argument_list|(
argument|int FD
argument_list|,
argument|bool&result
argument_list|)
expr_stmt|;
comment|/// @brief Simpler version of is_local for clients that don't need to
comment|///        differentiate between an error and false.
specifier|inline
name|bool
name|is_local
parameter_list|(
specifier|const
name|Twine
modifier|&
name|Path
parameter_list|)
block|{
name|bool
name|Result
decl_stmt|;
return|return
operator|!
name|is_local
argument_list|(
name|Path
argument_list|,
name|Result
argument_list|)
operator|&&
name|Result
return|;
block|}
comment|/// @brief Simpler version of is_local accepting an open file descriptor for
comment|///        clients that don't need to differentiate between an error and false.
specifier|inline
name|bool
name|is_local
parameter_list|(
name|int
name|FD
parameter_list|)
block|{
name|bool
name|Result
decl_stmt|;
return|return
operator|!
name|is_local
argument_list|(
name|FD
argument_list|,
name|Result
argument_list|)
operator|&&
name|Result
return|;
block|}
comment|/// @brief Does status represent a directory?
comment|///
comment|/// @param Path The path to get the type of.
comment|/// @param Follow For symbolic links, indicates whether to return the file type
comment|///               of the link itself, or of the target.
comment|/// @returns A value from the file_type enumeration indicating the type of file.
name|file_type
name|get_file_type
parameter_list|(
specifier|const
name|Twine
modifier|&
name|Path
parameter_list|,
name|bool
name|Follow
init|=
name|true
parameter_list|)
function_decl|;
comment|/// @brief Does status represent a directory?
comment|///
comment|/// @param status A file_status previously returned from status.
comment|/// @returns status.type() == file_type::directory_file.
name|bool
name|is_directory
parameter_list|(
name|file_status
name|status
parameter_list|)
function_decl|;
comment|/// @brief Is path a directory?
comment|///
comment|/// @param path Input path.
comment|/// @param result Set to true if \a path is a directory (after following
comment|///               symlinks, false if it is not. Undefined otherwise.
comment|/// @returns errc::success if result has been successfully set, otherwise a
comment|///          platform-specific error_code.
name|std
operator|::
name|error_code
name|is_directory
argument_list|(
specifier|const
name|Twine
operator|&
name|path
argument_list|,
name|bool
operator|&
name|result
argument_list|)
expr_stmt|;
comment|/// @brief Simpler version of is_directory for clients that don't need to
comment|///        differentiate between an error and false.
specifier|inline
name|bool
name|is_directory
parameter_list|(
specifier|const
name|Twine
modifier|&
name|Path
parameter_list|)
block|{
name|bool
name|Result
decl_stmt|;
return|return
operator|!
name|is_directory
argument_list|(
name|Path
argument_list|,
name|Result
argument_list|)
operator|&&
name|Result
return|;
block|}
comment|/// @brief Does status represent a regular file?
comment|///
comment|/// @param status A file_status previously returned from status.
comment|/// @returns status_known(status)&& status.type() == file_type::regular_file.
name|bool
name|is_regular_file
parameter_list|(
name|file_status
name|status
parameter_list|)
function_decl|;
comment|/// @brief Is path a regular file?
comment|///
comment|/// @param path Input path.
comment|/// @param result Set to true if \a path is a regular file (after following
comment|///               symlinks), false if it is not. Undefined otherwise.
comment|/// @returns errc::success if result has been successfully set, otherwise a
comment|///          platform-specific error_code.
name|std
operator|::
name|error_code
name|is_regular_file
argument_list|(
specifier|const
name|Twine
operator|&
name|path
argument_list|,
name|bool
operator|&
name|result
argument_list|)
expr_stmt|;
comment|/// @brief Simpler version of is_regular_file for clients that don't need to
comment|///        differentiate between an error and false.
specifier|inline
name|bool
name|is_regular_file
parameter_list|(
specifier|const
name|Twine
modifier|&
name|Path
parameter_list|)
block|{
name|bool
name|Result
decl_stmt|;
if|if
condition|(
name|is_regular_file
argument_list|(
name|Path
argument_list|,
name|Result
argument_list|)
condition|)
return|return
name|false
return|;
return|return
name|Result
return|;
block|}
comment|/// @brief Does status represent a symlink file?
comment|///
comment|/// @param status A file_status previously returned from status.
comment|/// @returns status_known(status)&& status.type() == file_type::symlink_file.
name|bool
name|is_symlink_file
parameter_list|(
name|file_status
name|status
parameter_list|)
function_decl|;
comment|/// @brief Is path a symlink file?
comment|///
comment|/// @param path Input path.
comment|/// @param result Set to true if \a path is a symlink file, false if it is not.
comment|///               Undefined otherwise.
comment|/// @returns errc::success if result has been successfully set, otherwise a
comment|///          platform-specific error_code.
name|std
operator|::
name|error_code
name|is_symlink_file
argument_list|(
specifier|const
name|Twine
operator|&
name|path
argument_list|,
name|bool
operator|&
name|result
argument_list|)
expr_stmt|;
comment|/// @brief Simpler version of is_symlink_file for clients that don't need to
comment|///        differentiate between an error and false.
specifier|inline
name|bool
name|is_symlink_file
parameter_list|(
specifier|const
name|Twine
modifier|&
name|Path
parameter_list|)
block|{
name|bool
name|Result
decl_stmt|;
if|if
condition|(
name|is_symlink_file
argument_list|(
name|Path
argument_list|,
name|Result
argument_list|)
condition|)
return|return
name|false
return|;
return|return
name|Result
return|;
block|}
comment|/// @brief Does this status represent something that exists but is not a
comment|///        directory or regular file?
comment|///
comment|/// @param status A file_status previously returned from status.
comment|/// @returns exists(s)&& !is_regular_file(s)&& !is_directory(s)
name|bool
name|is_other
parameter_list|(
name|file_status
name|status
parameter_list|)
function_decl|;
comment|/// @brief Is path something that exists but is not a directory,
comment|///        regular file, or symlink?
comment|///
comment|/// @param path Input path.
comment|/// @param result Set to true if \a path exists, but is not a directory, regular
comment|///               file, or a symlink, false if it does not. Undefined otherwise.
comment|/// @returns errc::success if result has been successfully set, otherwise a
comment|///          platform-specific error_code.
name|std
operator|::
name|error_code
name|is_other
argument_list|(
specifier|const
name|Twine
operator|&
name|path
argument_list|,
name|bool
operator|&
name|result
argument_list|)
expr_stmt|;
comment|/// @brief Get file status as if by POSIX stat().
comment|///
comment|/// @param path Input path.
comment|/// @param result Set to the file status.
comment|/// @param follow When true, follows symlinks.  Otherwise, the symlink itself is
comment|///               statted.
comment|/// @returns errc::success if result has been successfully set, otherwise a
comment|///          platform-specific error_code.
name|std
operator|::
name|error_code
name|status
argument_list|(
argument|const Twine&path
argument_list|,
argument|file_status&result
argument_list|,
argument|bool follow = true
argument_list|)
expr_stmt|;
comment|/// @brief A version for when a file descriptor is already available.
name|std
operator|::
name|error_code
name|status
argument_list|(
argument|int FD
argument_list|,
argument|file_status&Result
argument_list|)
expr_stmt|;
comment|/// @brief Set file permissions.
comment|///
comment|/// @param Path File to set permissions on.
comment|/// @param Permissions New file permissions.
comment|/// @returns errc::success if the permissions were successfully set, otherwise
comment|///          a platform-specific error_code.
comment|/// @note On Windows, all permissions except *_write are ignored. Using any of
comment|///       owner_write, group_write, or all_write will make the file writable.
comment|///       Otherwise, the file will be marked as read-only.
name|std
operator|::
name|error_code
name|setPermissions
argument_list|(
argument|const Twine&Path
argument_list|,
argument|perms Permissions
argument_list|)
expr_stmt|;
comment|/// @brief Get file permissions.
comment|///
comment|/// @param Path File to get permissions from.
comment|/// @returns the permissions if they were successfully retrieved, otherwise a
comment|///          platform-specific error_code.
comment|/// @note On Windows, if the file does not have the FILE_ATTRIBUTE_READONLY
comment|///       attribute, all_all will be returned. Otherwise, all_read | all_exe
comment|///       will be returned.
name|ErrorOr
operator|<
name|perms
operator|>
name|getPermissions
argument_list|(
specifier|const
name|Twine
operator|&
name|Path
argument_list|)
expr_stmt|;
comment|/// @brief Get file size.
comment|///
comment|/// @param Path Input path.
comment|/// @param Result Set to the size of the file in \a Path.
comment|/// @returns errc::success if result has been successfully set, otherwise a
comment|///          platform-specific error_code.
specifier|inline
name|std
operator|::
name|error_code
name|file_size
argument_list|(
argument|const Twine&Path
argument_list|,
argument|uint64_t&Result
argument_list|)
block|{
name|file_status
name|Status
block|;
name|std
operator|::
name|error_code
name|EC
operator|=
name|status
argument_list|(
name|Path
argument_list|,
name|Status
argument_list|)
block|;
if|if
condition|(
name|EC
condition|)
return|return
name|EC
return|;
name|Result
operator|=
name|Status
operator|.
name|getSize
argument_list|()
expr_stmt|;
return|return
name|std
operator|::
name|error_code
argument_list|()
return|;
block|}
comment|/// @brief Set the file modification and access time.
comment|///
comment|/// @returns errc::success if the file times were successfully set, otherwise a
comment|///          platform-specific error_code or errc::function_not_supported on
comment|///          platforms where the functionality isn't available.
name|std
operator|::
name|error_code
name|setLastModificationAndAccessTime
argument_list|(
argument|int FD
argument_list|,
argument|TimePoint<> Time
argument_list|)
expr_stmt|;
comment|/// @brief Is status available?
comment|///
comment|/// @param s Input file status.
comment|/// @returns True if status() != status_error.
name|bool
name|status_known
parameter_list|(
name|file_status
name|s
parameter_list|)
function_decl|;
comment|/// @brief Is status available?
comment|///
comment|/// @param path Input path.
comment|/// @param result Set to true if status() != status_error.
comment|/// @returns errc::success if result has been successfully set, otherwise a
comment|///          platform-specific error_code.
name|std
operator|::
name|error_code
name|status_known
argument_list|(
specifier|const
name|Twine
operator|&
name|path
argument_list|,
name|bool
operator|&
name|result
argument_list|)
expr_stmt|;
comment|/// @brief Create a uniquely named file.
comment|///
comment|/// Generates a unique path suitable for a temporary file and then opens it as a
comment|/// file. The name is based on \a model with '%' replaced by a random char in
comment|/// [0-9a-f]. If \a model is not an absolute path, the temporary file will be
comment|/// created in the current directory.
comment|///
comment|/// Example: clang-%%-%%-%%-%%-%%.s => clang-a0-b1-c2-d3-e4.s
comment|///
comment|/// This is an atomic operation. Either the file is created and opened, or the
comment|/// file system is left untouched.
comment|///
comment|/// The intended use is for files that are to be kept, possibly after
comment|/// renaming them. For example, when running 'clang -c foo.o', the file can
comment|/// be first created as foo-abc123.o and then renamed.
comment|///
comment|/// @param Model Name to base unique path off of.
comment|/// @param ResultFD Set to the opened file's file descriptor.
comment|/// @param ResultPath Set to the opened file's absolute path.
comment|/// @returns errc::success if Result{FD,Path} have been successfully set,
comment|///          otherwise a platform-specific error_code.
name|std
operator|::
name|error_code
name|createUniqueFile
argument_list|(
argument|const Twine&Model
argument_list|,
argument|int&ResultFD
argument_list|,
argument|SmallVectorImpl<char>&ResultPath
argument_list|,
argument|unsigned Mode = all_read | all_write
argument_list|)
expr_stmt|;
comment|/// @brief Simpler version for clients that don't want an open file.
name|std
operator|::
name|error_code
name|createUniqueFile
argument_list|(
specifier|const
name|Twine
operator|&
name|Model
argument_list|,
name|SmallVectorImpl
operator|<
name|char
operator|>
operator|&
name|ResultPath
argument_list|)
expr_stmt|;
comment|/// @brief Create a file in the system temporary directory.
comment|///
comment|/// The filename is of the form prefix-random_chars.suffix. Since the directory
comment|/// is not know to the caller, Prefix and Suffix cannot have path separators.
comment|/// The files are created with mode 0600.
comment|///
comment|/// This should be used for things like a temporary .s that is removed after
comment|/// running the assembler.
name|std
operator|::
name|error_code
name|createTemporaryFile
argument_list|(
argument|const Twine&Prefix
argument_list|,
argument|StringRef Suffix
argument_list|,
argument|int&ResultFD
argument_list|,
argument|SmallVectorImpl<char>&ResultPath
argument_list|)
expr_stmt|;
comment|/// @brief Simpler version for clients that don't want an open file.
name|std
operator|::
name|error_code
name|createTemporaryFile
argument_list|(
argument|const Twine&Prefix
argument_list|,
argument|StringRef Suffix
argument_list|,
argument|SmallVectorImpl<char>&ResultPath
argument_list|)
expr_stmt|;
name|std
operator|::
name|error_code
name|createUniqueDirectory
argument_list|(
specifier|const
name|Twine
operator|&
name|Prefix
argument_list|,
name|SmallVectorImpl
operator|<
name|char
operator|>
operator|&
name|ResultPath
argument_list|)
expr_stmt|;
comment|/// @brief Fetch a path to an open file, as specified by a file descriptor
comment|///
comment|/// @param FD File descriptor to a currently open file
comment|/// @param ResultPath The buffer into which to write the path
name|std
operator|::
name|error_code
name|getPathFromOpenFD
argument_list|(
argument|int FD
argument_list|,
argument|SmallVectorImpl<char>&ResultPath
argument_list|)
expr_stmt|;
enum|enum
name|OpenFlags
enum|:
name|unsigned
block|{
name|F_None
init|=
literal|0
block|,
comment|/// F_Excl - When opening a file, this flag makes raw_fd_ostream
comment|/// report an error if the file already exists.
name|F_Excl
init|=
literal|1
block|,
comment|/// F_Append - When opening a file, if it already exists append to the
comment|/// existing file instead of returning an error.  This may not be specified
comment|/// with F_Excl.
name|F_Append
init|=
literal|2
block|,
comment|/// The file should be opened in text mode on platforms that make this
comment|/// distinction.
name|F_Text
init|=
literal|4
block|,
comment|/// Open the file for read and write.
name|F_RW
init|=
literal|8
block|}
enum|;
specifier|inline
name|OpenFlags
name|operator
operator||
operator|(
name|OpenFlags
name|A
operator|,
name|OpenFlags
name|B
operator|)
block|{
return|return
name|OpenFlags
argument_list|(
name|unsigned
argument_list|(
name|A
argument_list|)
operator||
name|unsigned
argument_list|(
name|B
argument_list|)
argument_list|)
return|;
block|}
specifier|inline
name|OpenFlags
operator|&
name|operator
operator||=
operator|(
name|OpenFlags
operator|&
name|A
operator|,
name|OpenFlags
name|B
operator|)
block|{
name|A
operator|=
name|A
operator||
name|B
block|;
return|return
name|A
return|;
block|}
name|std
operator|::
name|error_code
name|openFileForWrite
argument_list|(
argument|const Twine&Name
argument_list|,
argument|int&ResultFD
argument_list|,
argument|OpenFlags Flags
argument_list|,
argument|unsigned Mode =
literal|0666
argument_list|)
expr_stmt|;
name|std
operator|::
name|error_code
name|openFileForRead
argument_list|(
specifier|const
name|Twine
operator|&
name|Name
argument_list|,
name|int
operator|&
name|ResultFD
argument_list|,
name|SmallVectorImpl
operator|<
name|char
operator|>
operator|*
name|RealPath
operator|=
name|nullptr
argument_list|)
expr_stmt|;
name|std
operator|::
name|error_code
name|getUniqueID
argument_list|(
argument|const Twine Path
argument_list|,
argument|UniqueID&Result
argument_list|)
expr_stmt|;
comment|/// @brief Get disk space usage information.
comment|///
comment|/// Note: Users must be careful about "Time Of Check, Time Of Use" kind of bug.
comment|/// Note: Windows reports results according to the quota allocated to the user.
comment|///
comment|/// @param Path Input path.
comment|/// @returns a space_info structure filled with the capacity, free, and
comment|/// available space on the device \a Path is on. A platform specific error_code
comment|/// is returned on error.
name|ErrorOr
operator|<
name|space_info
operator|>
name|disk_space
argument_list|(
specifier|const
name|Twine
operator|&
name|Path
argument_list|)
expr_stmt|;
comment|/// This class represents a memory mapped file. It is based on
comment|/// boost::iostreams::mapped_file.
name|class
name|mapped_file_region
block|{
name|public
label|:
enum|enum
name|mapmode
block|{
name|readonly
block|,
comment|///< May only access map via const_data as read only.
name|readwrite
block|,
comment|///< May access map via data and modify it. Written to path.
name|priv
comment|///< May modify via data, but changes are lost on destruction.
block|}
enum|;
name|private
label|:
comment|/// Platform-specific mapping state.
name|uint64_t
name|Size
decl_stmt|;
name|void
modifier|*
name|Mapping
decl_stmt|;
name|std
operator|::
name|error_code
name|init
argument_list|(
argument|int FD
argument_list|,
argument|uint64_t Offset
argument_list|,
argument|mapmode Mode
argument_list|)
expr_stmt|;
name|public
label|:
name|mapped_file_region
argument_list|()
operator|=
name|delete
expr_stmt|;
name|mapped_file_region
argument_list|(
name|mapped_file_region
operator|&
argument_list|)
operator|=
name|delete
expr_stmt|;
name|mapped_file_region
modifier|&
name|operator
init|=
operator|(
name|mapped_file_region
operator|&
operator|)
operator|=
name|delete
decl_stmt|;
comment|/// \param fd An open file descriptor to map. mapped_file_region takes
comment|///   ownership if closefd is true. It must have been opended in the correct
comment|///   mode.
name|mapped_file_region
argument_list|(
argument|int fd
argument_list|,
argument|mapmode mode
argument_list|,
argument|uint64_t length
argument_list|,
argument|uint64_t offset
argument_list|,
argument|std::error_code&ec
argument_list|)
empty_stmt|;
operator|~
name|mapped_file_region
argument_list|()
expr_stmt|;
name|uint64_t
name|size
argument_list|()
specifier|const
expr_stmt|;
name|char
operator|*
name|data
argument_list|()
specifier|const
expr_stmt|;
comment|/// Get a const view of the data. Modifying this memory has undefined
comment|/// behavior.
specifier|const
name|char
operator|*
name|const_data
argument_list|()
specifier|const
expr_stmt|;
comment|/// \returns The minimum alignment offset must be.
specifier|static
name|int
name|alignment
parameter_list|()
function_decl|;
block|}
empty_stmt|;
comment|/// Return the path to the main executable, given the value of argv[0] from
comment|/// program startup and the address of main itself. In extremis, this function
comment|/// may fail and return an empty path.
name|std
operator|::
name|string
name|getMainExecutable
argument_list|(
specifier|const
name|char
operator|*
name|argv0
argument_list|,
name|void
operator|*
name|MainExecAddr
argument_list|)
expr_stmt|;
comment|/// @}
comment|/// @name Iterators
comment|/// @{
comment|/// directory_entry - A single entry in a directory. Caches the status either
comment|/// from the result of the iteration syscall, or the first time status is
comment|/// called.
name|class
name|directory_entry
block|{
name|std
operator|::
name|string
name|Path
expr_stmt|;
name|bool
name|FollowSymlinks
decl_stmt|;
name|mutable
name|file_status
name|Status
decl_stmt|;
name|public
label|:
name|explicit
name|directory_entry
argument_list|(
argument|const Twine&path
argument_list|,
argument|bool follow_symlinks = true
argument_list|,
argument|file_status st = file_status()
argument_list|)
block|:
name|Path
argument_list|(
name|path
operator|.
name|str
argument_list|()
argument_list|)
operator|,
name|FollowSymlinks
argument_list|(
name|follow_symlinks
argument_list|)
operator|,
name|Status
argument_list|(
argument|st
argument_list|)
block|{}
name|directory_entry
argument_list|()
operator|=
expr|default
expr_stmt|;
name|void
name|assign
parameter_list|(
specifier|const
name|Twine
modifier|&
name|path
parameter_list|,
name|file_status
name|st
init|=
name|file_status
argument_list|()
parameter_list|)
block|{
name|Path
operator|=
name|path
operator|.
name|str
argument_list|()
expr_stmt|;
name|Status
operator|=
name|st
expr_stmt|;
block|}
name|void
name|replace_filename
parameter_list|(
specifier|const
name|Twine
modifier|&
name|filename
parameter_list|,
name|file_status
name|st
init|=
name|file_status
argument_list|()
parameter_list|)
function_decl|;
specifier|const
name|std
operator|::
name|string
operator|&
name|path
argument_list|()
specifier|const
block|{
return|return
name|Path
return|;
block|}
name|std
operator|::
name|error_code
name|status
argument_list|(
argument|file_status&result
argument_list|)
specifier|const
expr_stmt|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|directory_entry
operator|&
name|rhs
operator|)
specifier|const
block|{
return|return
name|Path
operator|==
name|rhs
operator|.
name|Path
return|;
block|}
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|directory_entry
operator|&
name|rhs
operator|)
specifier|const
block|{
return|return
operator|!
operator|(
operator|*
name|this
operator|==
name|rhs
operator|)
return|;
block|}
name|bool
name|operator
operator|<
operator|(
specifier|const
name|directory_entry
operator|&
name|rhs
operator|)
specifier|const
expr_stmt|;
name|bool
name|operator
operator|<=
operator|(
specifier|const
name|directory_entry
operator|&
name|rhs
operator|)
specifier|const
expr_stmt|;
name|bool
name|operator
operator|>
operator|(
specifier|const
name|directory_entry
operator|&
name|rhs
operator|)
specifier|const
expr_stmt|;
name|bool
name|operator
operator|>=
operator|(
specifier|const
name|directory_entry
operator|&
name|rhs
operator|)
specifier|const
expr_stmt|;
block|}
empty_stmt|;
name|namespace
name|detail
block|{
struct_decl|struct
name|DirIterState
struct_decl|;
name|std
operator|::
name|error_code
name|directory_iterator_construct
argument_list|(
name|DirIterState
operator|&
argument_list|,
name|StringRef
argument_list|,
name|bool
argument_list|)
expr_stmt|;
name|std
operator|::
name|error_code
name|directory_iterator_increment
argument_list|(
name|DirIterState
operator|&
argument_list|)
expr_stmt|;
name|std
operator|::
name|error_code
name|directory_iterator_destruct
argument_list|(
name|DirIterState
operator|&
argument_list|)
expr_stmt|;
comment|/// Keeps state for the directory_iterator.
struct|struct
name|DirIterState
block|{
operator|~
name|DirIterState
argument_list|()
block|{
name|directory_iterator_destruct
argument_list|(
operator|*
name|this
argument_list|)
block|;     }
name|intptr_t
name|IterationHandle
operator|=
literal|0
expr_stmt|;
name|directory_entry
name|CurrentEntry
decl_stmt|;
block|}
struct|;
block|}
comment|// end namespace detail
comment|/// directory_iterator - Iterates through the entries in path. There is no
comment|/// operator++ because we need an error_code. If it's really needed we can make
comment|/// it call report_fatal_error on error.
name|class
name|directory_iterator
block|{
name|std
operator|::
name|shared_ptr
operator|<
name|detail
operator|::
name|DirIterState
operator|>
name|State
expr_stmt|;
name|bool
name|FollowSymlinks
init|=
name|true
decl_stmt|;
name|public
label|:
name|explicit
name|directory_iterator
argument_list|(
specifier|const
name|Twine
operator|&
name|path
argument_list|,
name|std
operator|::
name|error_code
operator|&
name|ec
argument_list|,
name|bool
name|follow_symlinks
operator|=
name|true
argument_list|)
range|:
name|FollowSymlinks
argument_list|(
argument|follow_symlinks
argument_list|)
block|{
name|State
operator|=
name|std
operator|::
name|make_shared
operator|<
name|detail
operator|::
name|DirIterState
operator|>
operator|(
operator|)
block|;
name|SmallString
operator|<
literal|128
operator|>
name|path_storage
block|;
name|ec
operator|=
name|detail
operator|::
name|directory_iterator_construct
argument_list|(
operator|*
name|State
argument_list|,
name|path
operator|.
name|toStringRef
argument_list|(
name|path_storage
argument_list|)
argument_list|,
name|FollowSymlinks
argument_list|)
block|;   }
name|explicit
name|directory_iterator
argument_list|(
argument|const directory_entry&de
argument_list|,
argument|std::error_code&ec
argument_list|,
argument|bool follow_symlinks = true
argument_list|)
operator|:
name|FollowSymlinks
argument_list|(
argument|follow_symlinks
argument_list|)
block|{
name|State
operator|=
name|std
operator|::
name|make_shared
operator|<
name|detail
operator|::
name|DirIterState
operator|>
operator|(
operator|)
block|;
name|ec
operator|=
name|detail
operator|::
name|directory_iterator_construct
argument_list|(
operator|*
name|State
argument_list|,
name|de
operator|.
name|path
argument_list|()
argument_list|,
name|FollowSymlinks
argument_list|)
block|;   }
comment|/// Construct end iterator.
name|directory_iterator
argument_list|()
operator|=
expr|default
decl_stmt|;
comment|// No operator++ because we need error_code.
name|directory_iterator
modifier|&
name|increment
argument_list|(
name|std
operator|::
name|error_code
operator|&
name|ec
argument_list|)
block|{
name|ec
operator|=
name|directory_iterator_increment
argument_list|(
operator|*
name|State
argument_list|)
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
specifier|const
name|directory_entry
operator|&
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
name|State
operator|->
name|CurrentEntry
return|;
block|}
specifier|const
name|directory_entry
operator|*
name|operator
operator|->
expr|(
block|)
decl|const
block|{
return|return
operator|&
name|State
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
name|State
operator|==
name|RHS
operator|.
name|State
condition|)
return|return
name|true
return|;
if|if
condition|(
operator|!
name|RHS
operator|.
name|State
condition|)
return|return
name|State
operator|->
name|CurrentEntry
operator|==
name|directory_entry
argument_list|()
return|;
if|if
condition|(
operator|!
name|State
condition|)
return|return
name|RHS
operator|.
name|State
operator|->
name|CurrentEntry
operator|==
name|directory_entry
argument_list|()
return|;
return|return
name|State
operator|->
name|CurrentEntry
operator|==
name|RHS
operator|.
name|State
operator|->
name|CurrentEntry
return|;
block|}
end_decl_stmt

begin_expr_stmt
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
end_expr_stmt

begin_comment
comment|// Other members as required by
end_comment

begin_comment
comment|// C++ Std, 24.1.1 Input iterators [input.iterators]
end_comment

begin_decl_stmt
unit|};
name|namespace
name|detail
block|{
comment|/// Keeps state for the recursive_directory_iterator.
struct|struct
name|RecDirIterState
block|{
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
name|Stack
expr_stmt|;
name|uint16_t
name|Level
init|=
literal|0
decl_stmt|;
name|bool
name|HasNoPushRequest
init|=
name|false
decl_stmt|;
block|}
struct|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace detail
end_comment

begin_comment
comment|/// recursive_directory_iterator - Same as directory_iterator except for it
end_comment

begin_comment
comment|/// recurses down into child directories.
end_comment

begin_decl_stmt
name|class
name|recursive_directory_iterator
block|{
name|std
operator|::
name|shared_ptr
operator|<
name|detail
operator|::
name|RecDirIterState
operator|>
name|State
expr_stmt|;
name|bool
name|Follow
decl_stmt|;
name|public
label|:
name|recursive_directory_iterator
argument_list|()
operator|=
expr|default
expr_stmt|;
name|explicit
name|recursive_directory_iterator
argument_list|(
specifier|const
name|Twine
operator|&
name|path
argument_list|,
name|std
operator|::
name|error_code
operator|&
name|ec
argument_list|,
name|bool
name|follow_symlinks
operator|=
name|true
argument_list|)
range|:
name|State
argument_list|(
name|std
operator|::
name|make_shared
operator|<
name|detail
operator|::
name|RecDirIterState
operator|>
operator|(
operator|)
argument_list|)
decl_stmt|,
name|Follow
argument_list|(
name|follow_symlinks
argument_list|)
block|{
name|State
operator|->
name|Stack
operator|.
name|push
argument_list|(
name|directory_iterator
argument_list|(
name|path
argument_list|,
name|ec
argument_list|,
name|Follow
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|State
operator|->
name|Stack
operator|.
name|top
argument_list|()
operator|==
name|directory_iterator
argument_list|()
condition|)
name|State
operator|.
name|reset
argument_list|()
expr_stmt|;
block|}
comment|// No operator++ because we need error_code.
name|recursive_directory_iterator
modifier|&
name|increment
argument_list|(
name|std
operator|::
name|error_code
operator|&
name|ec
argument_list|)
block|{
specifier|const
name|directory_iterator
name|end_itr
init|=
block|{}
decl_stmt|;
if|if
condition|(
name|State
operator|->
name|HasNoPushRequest
condition|)
name|State
operator|->
name|HasNoPushRequest
operator|=
name|false
expr_stmt|;
else|else
block|{
name|file_status
name|st
decl_stmt|;
if|if
condition|(
operator|(
name|ec
operator|=
name|State
operator|->
name|Stack
operator|.
name|top
argument_list|()
operator|->
name|status
argument_list|(
name|st
argument_list|)
operator|)
condition|)
return|return
operator|*
name|this
return|;
if|if
condition|(
name|is_directory
argument_list|(
name|st
argument_list|)
condition|)
block|{
name|State
operator|->
name|Stack
operator|.
name|push
argument_list|(
name|directory_iterator
argument_list|(
operator|*
name|State
operator|->
name|Stack
operator|.
name|top
argument_list|()
argument_list|,
name|ec
argument_list|,
name|Follow
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|ec
condition|)
return|return
operator|*
name|this
return|;
if|if
condition|(
name|State
operator|->
name|Stack
operator|.
name|top
argument_list|()
operator|!=
name|end_itr
condition|)
block|{
operator|++
name|State
operator|->
name|Level
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
name|State
operator|->
name|Stack
operator|.
name|pop
argument_list|()
expr_stmt|;
block|}
block|}
while|while
condition|(
operator|!
name|State
operator|->
name|Stack
operator|.
name|empty
argument_list|()
operator|&&
name|State
operator|->
name|Stack
operator|.
name|top
argument_list|()
operator|.
name|increment
argument_list|(
name|ec
argument_list|)
operator|==
name|end_itr
condition|)
block|{
name|State
operator|->
name|Stack
operator|.
name|pop
argument_list|()
expr_stmt|;
operator|--
name|State
operator|->
name|Level
expr_stmt|;
block|}
comment|// Check if we are done. If so, create an end iterator.
if|if
condition|(
name|State
operator|->
name|Stack
operator|.
name|empty
argument_list|()
condition|)
name|State
operator|.
name|reset
argument_list|()
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
specifier|const
name|directory_entry
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
name|Stack
operator|.
name|top
argument_list|()
return|;
block|}
specifier|const
name|directory_entry
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
name|Stack
operator|.
name|top
argument_list|()
return|;
block|}
end_decl_stmt

begin_comment
comment|// observers
end_comment

begin_comment
comment|/// Gets the current level. Starting path is at level 0.
end_comment

begin_expr_stmt
name|int
name|level
argument_list|()
specifier|const
block|{
return|return
name|State
operator|->
name|Level
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Returns true if no_push has been called for this directory_entry.
end_comment

begin_expr_stmt
name|bool
name|no_push_request
argument_list|()
specifier|const
block|{
return|return
name|State
operator|->
name|HasNoPushRequest
return|;
block|}
end_expr_stmt

begin_comment
comment|// modifiers
end_comment

begin_comment
comment|/// Goes up one level if Level> 0.
end_comment

begin_function
name|void
name|pop
parameter_list|()
block|{
name|assert
argument_list|(
name|State
operator|&&
literal|"Cannot pop an end iterator!"
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|State
operator|->
name|Level
operator|>
literal|0
operator|&&
literal|"Cannot pop an iterator with level< 1"
argument_list|)
expr_stmt|;
specifier|const
name|directory_iterator
name|end_itr
init|=
block|{}
decl_stmt|;
name|std
operator|::
name|error_code
name|ec
expr_stmt|;
do|do
block|{
if|if
condition|(
name|ec
condition|)
name|report_fatal_error
argument_list|(
literal|"Error incrementing directory iterator."
argument_list|)
expr_stmt|;
name|State
operator|->
name|Stack
operator|.
name|pop
argument_list|()
expr_stmt|;
operator|--
name|State
operator|->
name|Level
expr_stmt|;
block|}
do|while
condition|(
operator|!
name|State
operator|->
name|Stack
operator|.
name|empty
argument_list|()
operator|&&
name|State
operator|->
name|Stack
operator|.
name|top
argument_list|()
operator|.
name|increment
argument_list|(
name|ec
argument_list|)
operator|==
name|end_itr
condition|)
do|;
comment|// Check if we are done. If so, create an end iterator.
if|if
condition|(
name|State
operator|->
name|Stack
operator|.
name|empty
argument_list|()
condition|)
name|State
operator|.
name|reset
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/// Does not go down into the current directory_entry.
end_comment

begin_function
name|void
name|no_push
parameter_list|()
block|{
name|State
operator|->
name|HasNoPushRequest
operator|=
name|true
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|bool
name|operator
operator|==
operator|(
specifier|const
name|recursive_directory_iterator
operator|&
name|RHS
operator|)
specifier|const
block|{
return|return
name|State
operator|==
name|RHS
operator|.
name|State
return|;
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
comment|// Other members as required by
end_comment

begin_comment
comment|// C++ Std, 24.1.1 Input iterators [input.iterators]
end_comment

begin_comment
unit|};
comment|/// @}
end_comment

begin_comment
unit|}
comment|// end namespace fs
end_comment

begin_comment
unit|}
comment|// end namespace sys
end_comment

begin_comment
unit|}
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_SUPPORT_FILESYSTEM_H
end_comment

end_unit

