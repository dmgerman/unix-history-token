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
file|"llvm/Support/PathV1.h"
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
file|<string>
end_include

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
comment|/// file_status - Represents the result of a call to stat and friends. It has
comment|///               a platform specific member to store the result.
name|class
name|file_status
block|{
comment|// implementation defined status field.
name|file_type
name|Type
decl_stmt|;
name|public
label|:
name|explicit
name|file_status
argument_list|(
argument|file_type v=file_type::status_error
argument_list|)
block|:
name|Type
argument_list|(
argument|v
argument_list|)
block|{}
name|file_type
name|type
argument_list|()
specifier|const
block|{
return|return
name|Type
return|;
block|}
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
block|}
empty_stmt|;
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
comment|/// @results errc::success if the current path has been stored in result,
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
comment|/// @results errc::success if path has been removed and existed has been
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
comment|/// @results errc::success if path has been removed and num_removed has been
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
comment|/// @brief Make file readable.
comment|///
comment|/// @param path Input path.
comment|/// @param value If true, make readable, else, make unreadable.
comment|/// @results errc::success if readability has been successfully set, otherwise a
comment|///          platform specific error_code.
name|error_code
name|set_read
parameter_list|(
specifier|const
name|Twine
modifier|&
name|path
parameter_list|,
name|bool
name|value
parameter_list|)
function_decl|;
comment|/// @brief Make file writeable.
comment|///
comment|/// @param path Input path.
comment|/// @param value If true, make writeable, else, make unwriteable.
comment|/// @results errc::success if writeability has been successfully set, otherwise
comment|///          a platform specific error_code.
name|error_code
name|set_write
parameter_list|(
specifier|const
name|Twine
modifier|&
name|path
parameter_list|,
name|bool
name|value
parameter_list|)
function_decl|;
comment|/// @brief Make file executable.
comment|///
comment|/// @param path Input path.
comment|/// @param value If true, make executable, else, make unexecutable.
comment|/// @results errc::success if executability has been successfully set, otherwise
comment|///          a platform specific error_code.
name|error_code
name|set_execute
parameter_list|(
specifier|const
name|Twine
modifier|&
name|path
parameter_list|,
name|bool
name|value
parameter_list|)
function_decl|;
comment|/// @}
comment|/// @name Physical Observers
comment|/// @{
comment|/// @brief Does file exist?
comment|///
comment|/// @param status A file_status previously returned from stat.
comment|/// @results True if the file represented by status exists, false if it does
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
comment|/// @results errc::success if result has been successfully set, otherwise a
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
comment|/// @brief Do file_status's represent the same thing?
comment|///
comment|/// @param A Input file_status.
comment|/// @param B Input file_status.
comment|///
comment|/// assert(status_known(A) || status_known(B));
comment|///
comment|/// @results True if A and B both represent the same file system entity, false
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
comment|/// @param A Input path A.
comment|/// @param B Input path B.
comment|/// @param result Set to true if stat(A) and stat(B) have the same device and
comment|///               inode (or equivalent).
comment|/// @results errc::success if result has been successfully set, otherwise a
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
comment|/// @results status.type() == file_type::directory_file.
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
comment|/// @results errc::success if result has been successfully set, otherwise a
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
comment|/// @brief Is path an empty file?
comment|///
comment|/// @param path Input path.
comment|/// @param result Set to true if \a path is a an empty file, false if it is not.
comment|///               Undefined otherwise.
comment|/// @results errc::success if result has been successfully set, otherwise a
comment|///          platform specific error_code.
name|error_code
name|is_empty
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
comment|/// @results status_known(status)&& status.type() == file_type::regular_file.
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
comment|/// @results errc::success if result has been successfully set, otherwise a
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
comment|/// @results exists(s)&& !is_regular_file(s)&& !is_directory(s)&&
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
comment|/// @results errc::success if result has been successfully set, otherwise a
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
comment|/// @param result status.type() == symlink_file.
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
comment|/// @results errc::success if result has been successfully set, otherwise a
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
comment|/// @brief Get last write time without changing it.
comment|///
comment|/// @param path Input path.
comment|/// @param result Set to the last write time (UNIX time) of \a path if it
comment|///               exists.
comment|/// @results errc::success if result has been successfully set, otherwise a
comment|///          platform specific error_code.
name|error_code
name|last_write_time
argument_list|(
specifier|const
name|Twine
operator|&
name|path
argument_list|,
name|std
operator|::
name|time_t
operator|&
name|result
argument_list|)
decl_stmt|;
comment|/// @brief Set last write time.
comment|///
comment|/// @param path Input path.
comment|/// @param value Time to set (UNIX time) \a path's last write time to.
comment|/// @results errc::success if result has been successfully set, otherwise a
comment|///          platform specific error_code.
name|error_code
name|set_last_write_time
argument_list|(
specifier|const
name|Twine
operator|&
name|path
argument_list|,
name|std
operator|::
name|time_t
name|value
argument_list|)
decl_stmt|;
comment|/// @brief Read a symlink's value.
comment|///
comment|/// @param path Input path.
comment|/// @param result Set to the value of the symbolic link \a path.
comment|/// @results errc::success if result has been successfully set, otherwise a
comment|///          platform specific error_code.
name|error_code
name|read_symlink
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
comment|/// @brief Get disk space usage information.
comment|///
comment|/// @param path Input path.
comment|/// @param result Set to the capacity, free, and available space on the device
comment|///               \a path is on.
comment|/// @results errc::success if result has been successfully set, otherwise a
comment|///          platform specific error_code.
name|error_code
name|disk_space
parameter_list|(
specifier|const
name|Twine
modifier|&
name|path
parameter_list|,
name|space_info
modifier|&
name|result
parameter_list|)
function_decl|;
comment|/// @brief Get file status as if by POSIX stat().
comment|///
comment|/// @param path Input path.
comment|/// @param result Set to the file status.
comment|/// @results errc::success if result has been successfully set, otherwise a
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
comment|/// @brief Is status available?
comment|///
comment|/// @param path Input path.
comment|/// @results True if status() != status_error.
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
comment|/// @results errc::success if result has been successfully set, otherwise a
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
comment|/// @brief Get file status as if by POSIX lstat().
comment|///
comment|/// Does not resolve symlinks.
comment|///
comment|/// @param path Input path.
comment|/// @param result Set to the file status.
comment|/// @results errc::success if result has been successfully set, otherwise a
comment|///          platform specific error_code.
name|error_code
name|symlink_status
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
comment|/// @param result_fs Set to the opened file's file descriptor.
comment|/// @param result_path Set to the opened file's absolute path.
comment|/// @results errc::success if result_{fd,path} have been successfully set,
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
argument_list|)
decl_stmt|;
comment|/// @brief Canonicalize path.
comment|///
comment|/// Sets result to the file system's idea of what path is. The result is always
comment|/// absolute and has the same capitalization as the file system.
comment|///
comment|/// @param path Input path.
comment|/// @param result Set to the canonicalized version of \a path.
comment|/// @results errc::success if result has been successfully set, otherwise a
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
comment|/// @results errc::success if result has been successfully set, otherwise a
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
comment|/// @results errc::success if result has been successfully set,
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
comment|/// @brief Get and identify \a path's type based on its content.
comment|///
comment|/// @param path Input path.
comment|/// @param result Set to the type of file, or LLVMFileType::Unknown_FileType.
comment|/// @results errc::success if result has been successfully set, otherwise a
comment|///          platform specific error_code.
name|error_code
name|identify_magic
parameter_list|(
specifier|const
name|Twine
modifier|&
name|path
parameter_list|,
name|LLVMFileType
modifier|&
name|result
parameter_list|)
function_decl|;
comment|/// @brief Is file bitcode?
comment|///
comment|/// @param path Input path.
comment|/// @param result Set to true if \a path is a bitcode file, false if it is not,
comment|///               undefined otherwise.
comment|/// @results errc::success if result has been successfully set, otherwise a
comment|///          platform specific error_code.
name|error_code
name|is_bitcode
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
comment|/// @brief Is file a dynamic library?
comment|///
comment|/// @param path Input path.
comment|/// @param result Set to true if \a path is a dynamic library, false if it is
comment|///               not, undefined otherwise.
comment|/// @results errc::success if result has been successfully set, otherwise a
comment|///          platform specific error_code.
name|error_code
name|is_dynamic_library
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
comment|/// @brief Is an object file?
comment|///
comment|/// @param path Input path.
comment|/// @param result Set to true if \a path is an object file, false if it is not,
comment|///               undefined otherwise.
comment|/// @results errc::success if result has been successfully set, otherwise a
comment|///          platform specific error_code.
name|error_code
name|is_object_file
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
comment|/// @brief Can file be read?
comment|///
comment|/// @param path Input path.
comment|/// @param result Set to true if \a path is readable, false it it is not,
comment|///               undefined otherwise.
comment|/// @results errc::success if result has been successfully set, otherwise a
comment|///          platform specific error_code.
name|error_code
name|can_read
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
comment|/// @brief Can file be written?
comment|///
comment|/// @param path Input path.
comment|/// @param result Set to true if \a path is writeable, false it it is not,
comment|///               undefined otherwise.
comment|/// @results errc::success if result has been successfully set, otherwise a
comment|///          platform specific error_code.
name|error_code
name|can_write
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
comment|/// @brief Can file be executed?
comment|///
comment|/// @param path Input path.
comment|/// @param result Set to true if \a path is executable, false it it is not,
comment|///               undefined otherwise.
comment|/// @results errc::success if result has been successfully set, otherwise a
comment|///          platform specific error_code.
name|error_code
name|can_execute
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
comment|/// @brief Get library paths the system linker uses.
comment|///
comment|/// @param result Set to the list of system library paths.
comment|/// @results errc::success if result has been successfully set, otherwise a
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
comment|/// @results errc::success if result has been successfully set, otherwise a
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
comment|/// @results errc::success if result has been successfully set, otherwise a
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
comment|/// @results errc::success if result has been successfully set, otherwise a
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
comment|/// @}
comment|/// @name Iterators
comment|/// @{
comment|/// directory_entry - A single entry in a directory. Caches the status either
comment|/// from the result of the iteration syscall, or the first time status or
comment|/// symlink_status is called.
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
name|mutable
name|file_status
name|SymlinkStatus
decl_stmt|;
name|public
label|:
name|explicit
name|directory_entry
argument_list|(
argument|const Twine&path
argument_list|,
argument|file_status st = file_status()
argument_list|,
argument|file_status symlink_st = file_status()
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
name|st
argument_list|)
operator|,
name|SymlinkStatus
argument_list|(
argument|symlink_st
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
argument_list|,
argument|file_status symlink_st = file_status()
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
block|;
name|SymlinkStatus
operator|=
name|symlink_st
block|;   }
name|void
name|replace_filename
argument_list|(
argument|const Twine&filename
argument_list|,
argument|file_status st = file_status()
argument_list|,
argument|file_status symlink_st = file_status()
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
name|error_code
name|symlink_status
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
comment|/// directory_iterator - Iterates through the entries in path. There is no
comment|/// operator++ because we need an error_code. If it's really needed we can make
comment|/// it call report_fatal_error on error.
name|class
name|directory_iterator
block|{
name|intptr_t
name|IterationHandle
decl_stmt|;
name|directory_entry
name|CurrentEntry
decl_stmt|;
comment|// Platform implementations implement these functions to handle iteration.
name|friend
name|error_code
name|directory_iterator_construct
parameter_list|(
name|directory_iterator
modifier|&
name|it
parameter_list|,
name|StringRef
name|path
parameter_list|)
function_decl|;
name|friend
name|error_code
name|directory_iterator_increment
parameter_list|(
name|directory_iterator
modifier|&
name|it
parameter_list|)
function_decl|;
name|friend
name|error_code
name|directory_iterator_destruct
parameter_list|(
name|directory_iterator
modifier|&
name|it
parameter_list|)
function_decl|;
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
name|error_code
operator|&
name|ec
argument_list|)
operator|:
name|IterationHandle
argument_list|(
literal|0
argument_list|)
block|{
name|SmallString
operator|<
literal|128
operator|>
name|path_storage
block|;
name|ec
operator|=
name|directory_iterator_construct
argument_list|(
operator|*
name|this
argument_list|,
name|path
operator|.
name|toStringRef
argument_list|(
name|path_storage
argument_list|)
argument_list|)
block|;   }
comment|/// Construct end iterator.
name|directory_iterator
argument_list|()
operator|:
name|IterationHandle
argument_list|(
literal|0
argument_list|)
block|{}
operator|~
name|directory_iterator
argument_list|()
block|{
name|directory_iterator_destruct
argument_list|(
operator|*
name|this
argument_list|)
block|;   }
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
name|this
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
name|CurrentEntry
operator|!=
name|RHS
operator|.
name|CurrentEntry
return|;
block|}
comment|// Other members as required by
comment|// C++ Std, 24.1.1 Input iterators [input.iterators]
block|}
empty_stmt|;
comment|/// recursive_directory_iterator - Same as directory_iterator except for it
comment|/// recurses down into child directories.
name|class
name|recursive_directory_iterator
block|{
name|uint16_t
name|Level
decl_stmt|;
name|bool
name|HasNoPushRequest
decl_stmt|;
comment|// implementation directory iterator status
name|public
label|:
name|explicit
name|recursive_directory_iterator
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
function_decl|;
comment|// No operator++ because we need error_code.
name|directory_iterator
modifier|&
name|increment
parameter_list|(
name|error_code
modifier|&
name|ec
parameter_list|)
function_decl|;
specifier|const
name|directory_entry
operator|&
name|operator
operator|*
operator|(
operator|)
specifier|const
expr_stmt|;
specifier|const
name|directory_entry
operator|*
name|operator
operator|->
expr|(
block|)
decl|const
decl_stmt|;
comment|// observers
comment|/// Gets the current level. path is at level 0.
name|int
name|level
argument_list|()
specifier|const
expr_stmt|;
comment|/// Returns true if no_push has been called for this directory_entry.
name|bool
name|no_push_request
argument_list|()
specifier|const
expr_stmt|;
comment|// modifiers
comment|/// Goes up one level if Level> 0.
name|void
name|pop
parameter_list|()
function_decl|;
comment|/// Does not go down into the current directory_entry.
name|void
name|no_push
parameter_list|()
function_decl|;
comment|// Other members as required by
comment|// C++ Std, 24.1.1 Input iterators [input.iterators]
block|}
empty_stmt|;
comment|/// @}
block|}
end_decl_stmt

begin_comment
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

