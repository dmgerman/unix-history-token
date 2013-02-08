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
name|LLVM_SUPPORT_FILE_SYSTEM_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_FILE_SYSTEM_H
end_define

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
file|"llvm/ADT/SmallString.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Twine.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ErrorHandling.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/system_error.h"
end_include

begin_include
include|#
directive|include
file|<ctime>
end_include

begin_include
include|#
directive|include
file|<iterator>
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
comment|/// file_type - An "enum class" enumeration for the file system's view of the
comment|///             type.
struct|struct
name|file_type
block|{
enum|enum
name|_
block|{
name|status_error
block|,
name|file_not_found
block|,
name|regular_file
block|,
name|directory_file
block|,
name|symlink_file
block|,
name|block_file
block|,
name|character_file
block|,
name|fifo_file
block|,
name|socket_file
block|,
name|type_unknown
block|}
enum|;
name|file_type
argument_list|(
argument|_ v
argument_list|)
block|:
name|v_
argument_list|(
argument|v
argument_list|)
block|{}
name|explicit
name|file_type
argument_list|(
argument|int v
argument_list|)
block|:
name|v_
argument_list|(
argument|_(v)
argument_list|)
block|{}
name|operator
name|int
argument_list|()
specifier|const
block|{
return|return
name|v_
return|;
block|}
name|private
label|:
name|int
name|v_
decl_stmt|;
block|}
struct|;
comment|/// copy_option - An "enum class" enumeration of copy semantics for copy
comment|///               operations.
struct|struct
name|copy_option
block|{
enum|enum
name|_
block|{
name|fail_if_exists
block|,
name|overwrite_if_exists
block|}
enum|;
name|copy_option
argument_list|(
argument|_ v
argument_list|)
block|:
name|v_
argument_list|(
argument|v
argument_list|)
block|{}
name|explicit
name|copy_option
argument_list|(
argument|int v
argument_list|)
block|:
name|v_
argument_list|(
argument|_(v)
argument_list|)
block|{}
name|operator
name|int
argument_list|()
specifier|const
block|{
return|return
name|v_
return|;
block|}
name|private
label|:
name|int
name|v_
decl_stmt|;
block|}
struct|;
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
name|perms_mask
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
block|,
name|add_perms
init|=
literal|0x1000
block|,
name|remove_perms
init|=
literal|0x2000
block|,
name|symlink_perms
init|=
literal|0x4000
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
return|return
name|static_cast
operator|<
name|perms
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
return|;
block|}
comment|/// file_status - Represents the result of a call to stat and friends. It has
comment|///               a platform specific member to store the result.
name|class
name|file_status
block|{
if|#
directive|if
name|defined
argument_list|(
name|LLVM_ON_UNIX
argument_list|)
name|dev_t
name|fs_st_dev
decl_stmt|;
name|ino_t
name|fs_st_ino
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|LLVM_ON_WIN32
argument_list|)
name|uint32_t
name|LastWriteTimeHigh
decl_stmt|;
name|uint32_t
name|LastWriteTimeLow
decl_stmt|;
name|uint32_t
name|VolumeSerialNumber
decl_stmt|;
name|uint32_t
name|FileSizeHigh
decl_stmt|;
name|uint32_t
name|FileSizeLow
decl_stmt|;
name|uint32_t
name|FileIndexHigh
decl_stmt|;
name|uint32_t
name|FileIndexLow
decl_stmt|;
endif|#
directive|endif
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
name|friend
name|error_code
name|status
parameter_list|(
specifier|const
name|Twine
modifier|&
name|path
parameter_list|,
name|file_status
modifier|&
name|result
parameter_list|)
function_decl|;
name|file_type
name|Type
decl_stmt|;
name|perms
name|Perms
decl_stmt|;
name|public
label|:
name|explicit
name|file_status
argument_list|(
argument|file_type v=file_type::status_error
argument_list|,
argument|perms prms=perms_not_known
argument_list|)
block|:
name|Type
argument_list|(
name|v
argument_list|)
operator|,
name|Perms
argument_list|(
argument|prms
argument_list|)
block|{}
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
comment|/// file_magic - An "enum class" enumeration of file types based on magic (the first
comment|///         N bytes of the file).
struct|struct
name|file_magic
block|{
enum|enum
name|_
block|{
name|unknown
init|=
literal|0
block|,
comment|///< Unrecognized file
name|bitcode
block|,
comment|///< Bitcode file
name|archive
block|,
comment|///< ar style archive file
name|elf_relocatable
block|,
comment|///< ELF Relocatable object file
name|elf_executable
block|,
comment|///< ELF Executable image
name|elf_shared_object
block|,
comment|///< ELF dynamically linked shared lib
name|elf_core
block|,
comment|///< ELF core image
name|macho_object
block|,
comment|///< Mach-O Object file
name|macho_executable
block|,
comment|///< Mach-O Executable
name|macho_fixed_virtual_memory_shared_lib
block|,
comment|///< Mach-O Shared Lib, FVM
name|macho_core
block|,
comment|///< Mach-O Core File
name|macho_preload_executabl
block|,
comment|///< Mach-O Preloaded Executable
name|macho_dynamically_linked_shared_lib
block|,
comment|///< Mach-O dynlinked shared lib
name|macho_dynamic_linker
block|,
comment|///< The Mach-O dynamic linker
name|macho_bundle
block|,
comment|///< Mach-O Bundle file
name|macho_dynamically_linked_shared_lib_stub
block|,
comment|///< Mach-O Shared lib stub
name|macho_dsym_companion
block|,
comment|///< Mach-O dSYM companion file
name|coff_object
block|,
comment|///< COFF object file
name|pecoff_executable
comment|///< PECOFF executable file
block|}
enum|;
name|bool
name|is_object
argument_list|()
specifier|const
block|{
return|return
name|v_
operator|==
name|unknown
operator|?
name|false
operator|:
name|true
return|;
block|}
name|file_magic
argument_list|()
operator|:
name|v_
argument_list|(
argument|unknown
argument_list|)
block|{}
name|file_magic
argument_list|(
argument|_ v
argument_list|)
operator|:
name|v_
argument_list|(
argument|v
argument_list|)
block|{}
name|explicit
name|file_magic
argument_list|(
argument|int v
argument_list|)
operator|:
name|v_
argument_list|(
argument|_(v)
argument_list|)
block|{}
name|operator
name|int
argument_list|()
specifier|const
block|{
return|return
name|v_
return|;
block|}
name|private
label|:
name|int
name|v_
decl_stmt|;
block|}
struct|;
comment|/// @}
comment|/// @name Physical Operators
comment|/// @{
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
comment|///          platform specific error_code.
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
decl_stmt|;
comment|/// @brief Copy the file at \a from to the path \a to.
comment|///
comment|/// @param from The path to copy the file from.
comment|/// @param to The path to copy the file to.
comment|/// @param copt Behavior if \a to already exists.
comment|/// @returns errc::success if the file has been successfully copied.
comment|///          errc::file_exists if \a to already exists and \a copt ==
comment|///          copy_option::fail_if_exists. Otherwise a platform specific
comment|///          error_code.
name|error_code
name|copy_file
parameter_list|(
specifier|const
name|Twine
modifier|&
name|from
parameter_list|,
specifier|const
name|Twine
modifier|&
name|to
parameter_list|,
name|copy_option
name|copt
init|=
name|copy_option
operator|::
name|fail_if_exists
parameter_list|)
function_decl|;
comment|/// @brief Create all the non-existent directories in path.
comment|///
comment|/// @param path Directories to create.
comment|/// @param existed Set to true if \a path already existed, false otherwise.
comment|/// @returns errc::success if is_directory(path) and existed have been set,
comment|///          otherwise a platform specific error_code.
name|error_code
name|create_directories
parameter_list|(
specifier|const
name|Twine
modifier|&
name|path
parameter_list|,
name|bool
modifier|&
name|existed
parameter_list|)
function_decl|;
comment|/// @brief Create the directory in path.
comment|///
comment|/// @param path Directory to create.
comment|/// @param existed Set to true if \a path already existed, false otherwise.
comment|/// @returns errc::success if is_directory(path) and existed have been set,
comment|///          otherwise a platform specific error_code.
name|error_code
name|create_directory
parameter_list|(
specifier|const
name|Twine
modifier|&
name|path
parameter_list|,
name|bool
modifier|&
name|existed
parameter_list|)
function_decl|;
comment|/// @brief Create a hard link from \a from to \a to.
comment|///
comment|/// @param to The path to hard link to.
comment|/// @param from The path to hard link from. This is created.
comment|/// @returns errc::success if exists(to)&& exists(from)&& equivalent(to, from)
comment|///          , otherwise a platform specific error_code.
name|error_code
name|create_hard_link
parameter_list|(
specifier|const
name|Twine
modifier|&
name|to
parameter_list|,
specifier|const
name|Twine
modifier|&
name|from
parameter_list|)
function_decl|;
comment|/// @brief Create a symbolic link from \a from to \a to.
comment|///
comment|/// @param to The path to symbolically link to.
comment|/// @param from The path to symbolically link from. This is created.
comment|/// @returns errc::success if exists(to)&& exists(from)&& is_symlink(from),
comment|///          otherwise a platform specific error_code.
name|error_code
name|create_symlink
parameter_list|(
specifier|const
name|Twine
modifier|&
name|to
parameter_list|,
specifier|const
name|Twine
modifier|&
name|from
parameter_list|)
function_decl|;
comment|/// @brief Get the current path.
comment|///
comment|/// @param result Holds the current path on return.
comment|/// @returns errc::success if the current path has been stored in result,
comment|///          otherwise a platform specific error_code.
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
decl_stmt|;
comment|/// @brief Remove path. Equivalent to POSIX remove().
comment|///
comment|/// @param path Input path.
comment|/// @param existed Set to true if \a path existed, false if it did not.
comment|///                undefined otherwise.
comment|/// @returns errc::success if path has been removed and existed has been
comment|///          successfully set, otherwise a platform specific error_code.
name|error_code
name|remove
parameter_list|(
specifier|const
name|Twine
modifier|&
name|path
parameter_list|,
name|bool
modifier|&
name|existed
parameter_list|)
function_decl|;
comment|/// @brief Recursively remove all files below \a path, then \a path. Files are
comment|///        removed as if by POSIX remove().
comment|///
comment|/// @param path Input path.
comment|/// @param num_removed Number of files removed.
comment|/// @returns errc::success if path has been removed and num_removed has been
comment|///          successfully set, otherwise a platform specific error_code.
name|error_code
name|remove_all
parameter_list|(
specifier|const
name|Twine
modifier|&
name|path
parameter_list|,
name|uint32_t
modifier|&
name|num_removed
parameter_list|)
function_decl|;
comment|/// @brief Rename \a from to \a to. Files are renamed as if by POSIX rename().
comment|///
comment|/// @param from The path to rename from.
comment|/// @param to The path to rename to. This is created.
name|error_code
name|rename
parameter_list|(
specifier|const
name|Twine
modifier|&
name|from
parameter_list|,
specifier|const
name|Twine
modifier|&
name|to
parameter_list|)
function_decl|;
comment|/// @brief Resize path to size. File is resized as if by POSIX truncate().
comment|///
comment|/// @param path Input path.
comment|/// @param size Size to resize to.
comment|/// @returns errc::success if \a path has been resized to \a size, otherwise a
comment|///          platform specific error_code.
name|error_code
name|resize_file
parameter_list|(
specifier|const
name|Twine
modifier|&
name|path
parameter_list|,
name|uint64_t
name|size
parameter_list|)
function_decl|;
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
comment|/// @brief Does file exist?
comment|///
comment|/// @param path Input path.
comment|/// @param result Set to true if the file represented by status exists, false if
comment|///               it does not. Undefined otherwise.
comment|/// @returns errc::success if result has been successfully set, otherwise a
comment|///          platform specific error_code.
name|error_code
name|exists
parameter_list|(
specifier|const
name|Twine
modifier|&
name|path
parameter_list|,
name|bool
modifier|&
name|result
parameter_list|)
function_decl|;
comment|/// @brief Simpler version of exists for clients that don't need to
comment|///        differentiate between an error and false.
specifier|inline
name|bool
name|exists
parameter_list|(
specifier|const
name|Twine
modifier|&
name|path
parameter_list|)
block|{
name|bool
name|result
decl_stmt|;
return|return
operator|!
name|exists
argument_list|(
name|path
argument_list|,
name|result
argument_list|)
operator|&&
name|result
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
comment|///          platform specific error_code.
name|error_code
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
parameter_list|,
name|bool
modifier|&
name|result
parameter_list|)
function_decl|;
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
comment|/// @brief Get file size.
comment|///
comment|/// @param path Input path.
comment|/// @param result Set to the size of the file in \a path.
comment|/// @returns errc::success if result has been successfully set, otherwise a
comment|///          platform specific error_code.
name|error_code
name|file_size
parameter_list|(
specifier|const
name|Twine
modifier|&
name|path
parameter_list|,
name|uint64_t
modifier|&
name|result
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
comment|/// @param result Set to true if \a path is a directory, false if it is not.
comment|///               Undefined otherwise.
comment|/// @returns errc::success if result has been successfully set, otherwise a
comment|///          platform specific error_code.
name|error_code
name|is_directory
parameter_list|(
specifier|const
name|Twine
modifier|&
name|path
parameter_list|,
name|bool
modifier|&
name|result
parameter_list|)
function_decl|;
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
comment|/// @param result Set to true if \a path is a regular file, false if it is not.
comment|///               Undefined otherwise.
comment|/// @returns errc::success if result has been successfully set, otherwise a
comment|///          platform specific error_code.
name|error_code
name|is_regular_file
parameter_list|(
specifier|const
name|Twine
modifier|&
name|path
parameter_list|,
name|bool
modifier|&
name|result
parameter_list|)
function_decl|;
comment|/// @brief Does this status represent something that exists but is not a
comment|///        directory, regular file, or symlink?
comment|///
comment|/// @param status A file_status previously returned from status.
comment|/// @returns exists(s)&& !is_regular_file(s)&& !is_directory(s)&&
comment|///          !is_symlink(s)
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
comment|///          platform specific error_code.
name|error_code
name|is_other
parameter_list|(
specifier|const
name|Twine
modifier|&
name|path
parameter_list|,
name|bool
modifier|&
name|result
parameter_list|)
function_decl|;
comment|/// @brief Does status represent a symlink?
comment|///
comment|/// @param status A file_status previously returned from stat.
comment|/// @returns status.type() == symlink_file.
name|bool
name|is_symlink
parameter_list|(
name|file_status
name|status
parameter_list|)
function_decl|;
comment|/// @brief Is path a symlink?
comment|///
comment|/// @param path Input path.
comment|/// @param result Set to true if \a path is a symlink, false if it is not.
comment|///               Undefined otherwise.
comment|/// @returns errc::success if result has been successfully set, otherwise a
comment|///          platform specific error_code.
name|error_code
name|is_symlink
parameter_list|(
specifier|const
name|Twine
modifier|&
name|path
parameter_list|,
name|bool
modifier|&
name|result
parameter_list|)
function_decl|;
comment|/// @brief Get file status as if by POSIX stat().
comment|///
comment|/// @param path Input path.
comment|/// @param result Set to the file status.
comment|/// @returns errc::success if result has been successfully set, otherwise a
comment|///          platform specific error_code.
name|error_code
name|status
parameter_list|(
specifier|const
name|Twine
modifier|&
name|path
parameter_list|,
name|file_status
modifier|&
name|result
parameter_list|)
function_decl|;
comment|/// @brief Modifies permission bits on a file
comment|///
comment|/// @param path Input path.
comment|/// @returns errc::success if permissions have been changed, otherwise a
comment|///          platform specific error_code.
name|error_code
name|permissions
parameter_list|(
specifier|const
name|Twine
modifier|&
name|path
parameter_list|,
name|perms
name|prms
parameter_list|)
function_decl|;
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
comment|///          platform specific error_code.
name|error_code
name|status_known
parameter_list|(
specifier|const
name|Twine
modifier|&
name|path
parameter_list|,
name|bool
modifier|&
name|result
parameter_list|)
function_decl|;
comment|/// @brief Generate a unique path and open it as a file.
comment|///
comment|/// Generates a unique path suitable for a temporary file and then opens it as a
comment|/// file. The name is based on \a model with '%' replaced by a random char in
comment|/// [0-9a-f]. If \a model is not an absolute path, a suitable temporary
comment|/// directory will be prepended.
comment|///
comment|/// This is an atomic operation. Either the file is created and opened, or the
comment|/// file system is left untouched.
comment|///
comment|/// clang-%%-%%-%%-%%-%%.s => /tmp/clang-a0-b1-c2-d3-e4.s
comment|///
comment|/// @param model Name to base unique path off of.
comment|/// @param result_fd Set to the opened file's file descriptor.
comment|/// @param result_path Set to the opened file's absolute path.
comment|/// @param makeAbsolute If true and \a model is not an absolute path, a temp
comment|///        directory will be prepended.
comment|/// @returns errc::success if result_{fd,path} have been successfully set,
comment|///          otherwise a platform specific error_code.
name|error_code
name|unique_file
argument_list|(
specifier|const
name|Twine
operator|&
name|model
argument_list|,
name|int
operator|&
name|result_fd
argument_list|,
name|SmallVectorImpl
operator|<
name|char
operator|>
operator|&
name|result_path
argument_list|,
name|bool
name|makeAbsolute
operator|=
name|true
argument_list|,
name|unsigned
name|mode
operator|=
literal|0600
argument_list|)
decl_stmt|;
comment|/// @brief Canonicalize path.
comment|///
comment|/// Sets result to the file system's idea of what path is. The result is always
comment|/// absolute and has the same capitalization as the file system.
comment|///
comment|/// @param path Input path.
comment|/// @param result Set to the canonicalized version of \a path.
comment|/// @returns errc::success if result has been successfully set, otherwise a
comment|///          platform specific error_code.
name|error_code
name|canonicalize
argument_list|(
specifier|const
name|Twine
operator|&
name|path
argument_list|,
name|SmallVectorImpl
operator|<
name|char
operator|>
operator|&
name|result
argument_list|)
decl_stmt|;
comment|/// @brief Are \a path's first bytes \a magic?
comment|///
comment|/// @param path Input path.
comment|/// @param magic Byte sequence to compare \a path's first len(magic) bytes to.
comment|/// @returns errc::success if result has been successfully set, otherwise a
comment|///          platform specific error_code.
name|error_code
name|has_magic
parameter_list|(
specifier|const
name|Twine
modifier|&
name|path
parameter_list|,
specifier|const
name|Twine
modifier|&
name|magic
parameter_list|,
name|bool
modifier|&
name|result
parameter_list|)
function_decl|;
comment|/// @brief Get \a path's first \a len bytes.
comment|///
comment|/// @param path Input path.
comment|/// @param len Number of magic bytes to get.
comment|/// @param result Set to the first \a len bytes in the file pointed to by
comment|///               \a path. Or the entire file if file_size(path)< len, in which
comment|///               case result.size() returns the size of the file.
comment|/// @returns errc::success if result has been successfully set,
comment|///          errc::value_too_large if len is larger then the file pointed to by
comment|///          \a path, otherwise a platform specific error_code.
name|error_code
name|get_magic
argument_list|(
specifier|const
name|Twine
operator|&
name|path
argument_list|,
name|uint32_t
name|len
argument_list|,
name|SmallVectorImpl
operator|<
name|char
operator|>
operator|&
name|result
argument_list|)
decl_stmt|;
comment|/// @brief Identify the type of a binary file based on how magical it is.
name|file_magic
name|identify_magic
parameter_list|(
name|StringRef
name|magic
parameter_list|)
function_decl|;
comment|/// @brief Get and identify \a path's type based on its content.
comment|///
comment|/// @param path Input path.
comment|/// @param result Set to the type of file, or LLVMFileType::Unknown_FileType.
comment|/// @returns errc::success if result has been successfully set, otherwise a
comment|///          platform specific error_code.
name|error_code
name|identify_magic
parameter_list|(
specifier|const
name|Twine
modifier|&
name|path
parameter_list|,
name|file_magic
modifier|&
name|result
parameter_list|)
function_decl|;
comment|/// @brief Get library paths the system linker uses.
comment|///
comment|/// @param result Set to the list of system library paths.
comment|/// @returns errc::success if result has been successfully set, otherwise a
comment|///          platform specific error_code.
name|error_code
name|GetSystemLibraryPaths
argument_list|(
name|SmallVectorImpl
operator|<
name|std
operator|::
name|string
operator|>
operator|&
name|result
argument_list|)
decl_stmt|;
comment|/// @brief Get bitcode library paths the system linker uses
comment|///        + LLVM_LIB_SEARCH_PATH + LLVM_LIBDIR.
comment|///
comment|/// @param result Set to the list of bitcode library paths.
comment|/// @returns errc::success if result has been successfully set, otherwise a
comment|///          platform specific error_code.
name|error_code
name|GetBitcodeLibraryPaths
argument_list|(
name|SmallVectorImpl
operator|<
name|std
operator|::
name|string
operator|>
operator|&
name|result
argument_list|)
decl_stmt|;
comment|/// @brief Find a library.
comment|///
comment|/// Find the path to a library using its short name. Use the system
comment|/// dependent library paths to locate the library.
comment|///
comment|/// c => /usr/lib/libc.so
comment|///
comment|/// @param short_name Library name one would give to the system linker.
comment|/// @param result Set to the absolute path \a short_name represents.
comment|/// @returns errc::success if result has been successfully set, otherwise a
comment|///          platform specific error_code.
name|error_code
name|FindLibrary
argument_list|(
specifier|const
name|Twine
operator|&
name|short_name
argument_list|,
name|SmallVectorImpl
operator|<
name|char
operator|>
operator|&
name|result
argument_list|)
decl_stmt|;
comment|/// @brief Get absolute path of main executable.
comment|///
comment|/// @param argv0 The program name as it was spelled on the command line.
comment|/// @param MainAddr Address of some symbol in the executable (not in a library).
comment|/// @param result Set to the absolute path of the current executable.
comment|/// @returns errc::success if result has been successfully set, otherwise a
comment|///          platform specific error_code.
name|error_code
name|GetMainExecutable
argument_list|(
specifier|const
name|char
operator|*
name|argv0
argument_list|,
name|void
operator|*
name|MainAddr
argument_list|,
name|SmallVectorImpl
operator|<
name|char
operator|>
operator|&
name|result
argument_list|)
decl_stmt|;
comment|/// This class represents a memory mapped file. It is based on
comment|/// boost::iostreams::mapped_file.
name|class
name|mapped_file_region
block|{
name|mapped_file_region
argument_list|()
name|LLVM_DELETED_FUNCTION
expr_stmt|;
name|mapped_file_region
argument_list|(
argument|mapped_file_region&
argument_list|)
name|LLVM_DELETED_FUNCTION
expr_stmt|;
name|mapped_file_region
modifier|&
name|operator
init|=
operator|(
name|mapped_file_region
operator|&
operator|)
name|LLVM_DELETED_FUNCTION
decl_stmt|;
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
comment|/// Platform specific mapping state.
name|mapmode
name|Mode
decl_stmt|;
name|uint64_t
name|Size
decl_stmt|;
name|void
modifier|*
name|Mapping
decl_stmt|;
ifdef|#
directive|ifdef
name|LLVM_ON_WIN32
name|int
name|FileDescriptor
decl_stmt|;
name|void
modifier|*
name|FileHandle
decl_stmt|;
name|void
modifier|*
name|FileMappingHandle
decl_stmt|;
endif|#
directive|endif
name|error_code
name|init
parameter_list|(
name|int
name|FD
parameter_list|,
name|uint64_t
name|Offset
parameter_list|)
function_decl|;
name|public
label|:
typedef|typedef
name|char
name|char_type
typedef|;
if|#
directive|if
name|LLVM_USE_RVALUE_REFERENCES
name|mapped_file_region
argument_list|(
name|mapped_file_region
operator|&&
argument_list|)
expr_stmt|;
name|mapped_file_region
modifier|&
name|operator
init|=
operator|(
name|mapped_file_region
operator|&&
operator|)
decl_stmt|;
endif|#
directive|endif
comment|/// Construct a mapped_file_region at \a path starting at \a offset of length
comment|/// \a length and with access \a mode.
comment|///
comment|/// \param path Path to the file to map. If it does not exist it will be
comment|///             created.
comment|/// \param mode How to map the memory.
comment|/// \param length Number of bytes to map in starting at \a offset. If the file
comment|///               is shorter than this, it will be extended. If \a length is
comment|///               0, the entire file will be mapped.
comment|/// \param offset Byte offset from the beginning of the file where the map
comment|///               should begin. Must be a multiple of
comment|///               mapped_file_region::alignment().
comment|/// \param ec This is set to errc::success if the map was constructed
comment|///           sucessfully. Otherwise it is set to a platform dependent error.
name|mapped_file_region
argument_list|(
argument|const Twine&path
argument_list|,
argument|mapmode mode
argument_list|,
argument|uint64_t length
argument_list|,
argument|uint64_t offset
argument_list|,
argument|error_code&ec
argument_list|)
empty_stmt|;
comment|/// \param fd An open file descriptor to map. mapped_file_region takes
comment|///           ownership. It must have been opended in the correct mode.
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
argument|error_code&ec
argument_list|)
empty_stmt|;
operator|~
name|mapped_file_region
argument_list|()
expr_stmt|;
name|mapmode
name|flags
argument_list|()
specifier|const
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
comment|/// behaivor.
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
comment|/// @brief Memory maps the contents of a file
comment|///
comment|/// @param path Path to file to map.
comment|/// @param file_offset Byte offset in file where mapping should begin.
comment|/// @param size Byte length of range of the file to map.
comment|/// @param map_writable If true, the file will be mapped in r/w such
comment|///        that changes to the mapped buffer will be flushed back
comment|///        to the file.  If false, the file will be mapped read-only
comment|///        and the buffer will be read-only.
comment|/// @param result Set to the start address of the mapped buffer.
comment|/// @returns errc::success if result has been successfully set, otherwise a
comment|///          platform specific error_code.
name|error_code
name|map_file_pages
parameter_list|(
specifier|const
name|Twine
modifier|&
name|path
parameter_list|,
name|off_t
name|file_offset
parameter_list|,
name|size_t
name|size
parameter_list|,
name|bool
name|map_writable
parameter_list|,
name|void
modifier|*
modifier|&
name|result
parameter_list|)
function_decl|;
comment|/// @brief Memory unmaps the contents of a file
comment|///
comment|/// @param base Pointer to the start of the buffer.
comment|/// @param size Byte length of the range to unmmap.
comment|/// @returns errc::success if result has been successfully set, otherwise a
comment|///          platform specific error_code.
name|error_code
name|unmap_file_pages
parameter_list|(
name|void
modifier|*
name|base
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
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
name|Status
argument_list|(
argument|st
argument_list|)
block|{}
name|directory_entry
argument_list|()
block|{}
name|void
name|assign
argument_list|(
argument|const Twine&path
argument_list|,
argument|file_status st = file_status()
argument_list|)
block|{
name|Path
operator|=
name|path
operator|.
name|str
argument_list|()
block|;
name|Status
operator|=
name|st
block|;   }
name|void
name|replace_filename
argument_list|(
argument|const Twine&filename
argument_list|,
argument|file_status st = file_status()
argument_list|)
expr_stmt|;
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
name|error_code
name|status
argument_list|(
name|file_status
operator|&
name|result
argument_list|)
decl|const
decl_stmt|;
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
name|error_code
name|directory_iterator_construct
parameter_list|(
name|DirIterState
modifier|&
parameter_list|,
name|StringRef
parameter_list|)
function_decl|;
name|error_code
name|directory_iterator_increment
parameter_list|(
name|DirIterState
modifier|&
parameter_list|)
function_decl|;
name|error_code
name|directory_iterator_destruct
parameter_list|(
name|DirIterState
modifier|&
parameter_list|)
function_decl|;
comment|/// DirIterState - Keeps state for the directory_iterator. It is reference
comment|/// counted in order to preserve InputIterator semantics on copy.
name|struct
name|DirIterState
range|:
name|public
name|RefCountedBase
operator|<
name|DirIterState
operator|>
block|{
name|DirIterState
argument_list|()
operator|:
name|IterationHandle
argument_list|(
literal|0
argument_list|)
block|{}
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
block|;
name|directory_entry
name|CurrentEntry
block|;   }
decl_stmt|;
block|}
comment|/// directory_iterator - Iterates through the entries in path. There is no
comment|/// operator++ because we need an error_code. If it's really needed we can make
comment|/// it call report_fatal_error on error.
name|class
name|directory_iterator
block|{
name|IntrusiveRefCntPtr
operator|<
name|detail
operator|::
name|DirIterState
operator|>
name|State
expr_stmt|;
name|public
label|:
name|explicit
name|directory_iterator
parameter_list|(
specifier|const
name|Twine
modifier|&
name|path
parameter_list|,
name|error_code
modifier|&
name|ec
parameter_list|)
block|{
name|State
operator|=
name|new
name|detail
operator|::
name|DirIterState
expr_stmt|;
name|SmallString
operator|<
literal|128
operator|>
name|path_storage
expr_stmt|;
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
argument_list|)
expr_stmt|;
block|}
name|explicit
name|directory_iterator
parameter_list|(
specifier|const
name|directory_entry
modifier|&
name|de
parameter_list|,
name|error_code
modifier|&
name|ec
parameter_list|)
block|{
name|State
operator|=
name|new
name|detail
operator|::
name|DirIterState
expr_stmt|;
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
argument_list|)
expr_stmt|;
block|}
comment|/// Construct end iterator.
name|directory_iterator
argument_list|()
operator|:
name|State
argument_list|(
argument|new detail::DirIterState
argument_list|)
block|{}
comment|// No operator++ because we need error_code.
name|directory_iterator
operator|&
name|increment
argument_list|(
argument|error_code&ec
argument_list|)
block|{
name|ec
operator|=
name|directory_iterator_increment
argument_list|(
operator|*
name|State
argument_list|)
block|;
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
comment|// Other members as required by
comment|// C++ Std, 24.1.1 Input iterators [input.iterators]
block|}
empty_stmt|;
name|namespace
name|detail
block|{
comment|/// RecDirIterState - Keeps state for the recursive_directory_iterator. It is
comment|/// reference counted in order to preserve InputIterator semantics on copy.
name|struct
name|RecDirIterState
range|:
name|public
name|RefCountedBase
operator|<
name|RecDirIterState
operator|>
block|{
name|RecDirIterState
argument_list|()
operator|:
name|Level
argument_list|(
literal|0
argument_list|)
block|,
name|HasNoPushRequest
argument_list|(
argument|false
argument_list|)
block|{}
name|std
operator|::
name|stack
operator|<
name|directory_iterator
block|,
name|std
operator|::
name|vector
operator|<
name|directory_iterator
operator|>
expr|>
name|Stack
block|;
name|uint16_t
name|Level
block|;
name|bool
name|HasNoPushRequest
block|;   }
decl_stmt|;
block|}
comment|/// recursive_directory_iterator - Same as directory_iterator except for it
comment|/// recurses down into child directories.
name|class
name|recursive_directory_iterator
block|{
name|IntrusiveRefCntPtr
operator|<
name|detail
operator|::
name|RecDirIterState
operator|>
name|State
expr_stmt|;
name|public
label|:
name|recursive_directory_iterator
argument_list|()
block|{}
name|explicit
name|recursive_directory_iterator
argument_list|(
specifier|const
name|Twine
operator|&
name|path
argument_list|,
name|error_code
operator|&
name|ec
argument_list|)
operator|:
name|State
argument_list|(
argument|new detail::RecDirIterState
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
argument_list|)
argument_list|)
block|;
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
parameter_list|(
name|error_code
modifier|&
name|ec
parameter_list|)
block|{
specifier|static
specifier|const
name|directory_iterator
name|end_itr
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
comment|// observers
comment|/// Gets the current level. Starting path is at level 0.
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
comment|/// Returns true if no_push has been called for this directory_entry.
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
comment|// modifiers
comment|/// Goes up one level if Level> 0.
name|void
name|pop
parameter_list|()
block|{
name|assert
argument_list|(
name|State
operator|&&
literal|"Cannot pop and end itertor!"
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
specifier|static
specifier|const
name|directory_iterator
name|end_itr
decl_stmt|;
name|error_code
name|ec
decl_stmt|;
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
comment|/// Does not go down into the current directory_entry.
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
comment|// Other members as required by
comment|// C++ Std, 24.1.1 Input iterators [input.iterators]
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
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

end_unit

