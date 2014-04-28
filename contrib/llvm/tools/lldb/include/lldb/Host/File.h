begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- File.h --------------------------------------------------*- C++ -*-===//
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
name|liblldb_File_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_File_h_
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__cplusplus
argument_list|)
end_if

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-private.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//----------------------------------------------------------------------
comment|/// @class File File.h "lldb/Host/File.h"
comment|/// @brief A file class.
comment|///
comment|/// A file class that divides abstracts the LLDB core from host file
comment|/// functionality.
comment|//----------------------------------------------------------------------
name|class
name|File
block|{
name|public
label|:
specifier|static
name|int
name|kInvalidDescriptor
decl_stmt|;
specifier|static
name|FILE
modifier|*
name|kInvalidStream
decl_stmt|;
enum|enum
name|OpenOptions
block|{
name|eOpenOptionRead
init|=
operator|(
literal|1u
operator|<<
literal|0
operator|)
block|,
comment|// Open file for reading
name|eOpenOptionWrite
init|=
operator|(
literal|1u
operator|<<
literal|1
operator|)
block|,
comment|// Open file for writing
name|eOpenOptionAppend
init|=
operator|(
literal|1u
operator|<<
literal|2
operator|)
block|,
comment|// Don't truncate file when opening, append to end of file
name|eOpenOptionTruncate
init|=
operator|(
literal|1u
operator|<<
literal|3
operator|)
block|,
comment|// Truncate file when opening
name|eOpenOptionNonBlocking
init|=
operator|(
literal|1u
operator|<<
literal|4
operator|)
block|,
comment|// File reads
name|eOpenOptionCanCreate
init|=
operator|(
literal|1u
operator|<<
literal|5
operator|)
block|,
comment|// Create file if doesn't already exist
name|eOpenOptionCanCreateNewOnly
init|=
operator|(
literal|1u
operator|<<
literal|6
operator|)
block|,
comment|// Can create file only if it doesn't already exist
name|eOpenoptionDontFollowSymlinks
init|=
operator|(
literal|1u
operator|<<
literal|7
operator|)
block|}
enum|;
specifier|static
name|mode_t
name|ConvertOpenOptionsForPOSIXOpen
parameter_list|(
name|uint32_t
name|open_options
parameter_list|)
function_decl|;
name|File
argument_list|()
operator|:
name|m_descriptor
argument_list|(
name|kInvalidDescriptor
argument_list|)
operator|,
name|m_stream
argument_list|(
name|kInvalidStream
argument_list|)
operator|,
name|m_options
argument_list|(
literal|0
argument_list|)
operator|,
name|m_own_stream
argument_list|(
name|false
argument_list|)
operator|,
name|m_own_descriptor
argument_list|(
name|false
argument_list|)
operator|,
name|m_is_interactive
argument_list|(
name|eLazyBoolCalculate
argument_list|)
operator|,
name|m_is_real_terminal
argument_list|(
argument|eLazyBoolCalculate
argument_list|)
block|{     }
name|File
argument_list|(
argument|FILE *fh
argument_list|,
argument|bool transfer_ownership
argument_list|)
operator|:
name|m_descriptor
argument_list|(
name|kInvalidDescriptor
argument_list|)
operator|,
name|m_stream
argument_list|(
name|fh
argument_list|)
operator|,
name|m_options
argument_list|(
literal|0
argument_list|)
operator|,
name|m_own_stream
argument_list|(
name|transfer_ownership
argument_list|)
operator|,
name|m_own_descriptor
argument_list|(
name|false
argument_list|)
operator|,
name|m_is_interactive
argument_list|(
name|eLazyBoolCalculate
argument_list|)
operator|,
name|m_is_real_terminal
argument_list|(
argument|eLazyBoolCalculate
argument_list|)
block|{     }
name|File
argument_list|(
specifier|const
name|File
operator|&
name|rhs
argument_list|)
expr_stmt|;
name|File
modifier|&
name|operator
init|=
operator|(
specifier|const
name|File
operator|&
name|rhs
operator|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Constructor with path.
comment|///
comment|/// Takes a path to a file which can be just a filename, or a full
comment|/// path. If \a path is not NULL or empty, this function will call
comment|/// File::Open (const char *path, uint32_t options, uint32_t permissions).
comment|///
comment|/// @param[in] path
comment|///     The full or partial path to a file.
comment|///
comment|/// @param[in] options
comment|///     Options to use when opening (see File::OpenOptions)
comment|///
comment|/// @param[in] permissions
comment|///     Options to use when opening (see File::Permissions)
comment|///
comment|/// @see File::Open (const char *path, uint32_t options, uint32_t permissions)
comment|//------------------------------------------------------------------
name|File
argument_list|(
argument|const char *path
argument_list|,
argument|uint32_t options
argument_list|,
argument|uint32_t permissions = lldb::eFilePermissionsFileDefault
argument_list|)
empty_stmt|;
comment|//------------------------------------------------------------------
comment|/// Constructor with FileSpec.
comment|///
comment|/// Takes a FileSpec pointing to a file which can be just a filename, or a full
comment|/// path. If \a path is not NULL or empty, this function will call
comment|/// File::Open (const char *path, uint32_t options, uint32_t permissions).
comment|///
comment|/// @param[in] path
comment|///     The FileSpec for this file.
comment|///
comment|/// @param[in] options
comment|///     Options to use when opening (see File::OpenOptions)
comment|///
comment|/// @param[in] permissions
comment|///     Options to use when opening (see File::Permissions)
comment|///
comment|/// @see File::Open (const char *path, uint32_t options, uint32_t permissions)
comment|//------------------------------------------------------------------
name|File
argument_list|(
argument|const FileSpec& filespec
argument_list|,
argument|uint32_t options
argument_list|,
argument|uint32_t permissions = lldb::eFilePermissionsFileDefault
argument_list|)
empty_stmt|;
name|File
argument_list|(
argument|int fd
argument_list|,
argument|bool transfer_ownership
argument_list|)
block|:
name|m_descriptor
argument_list|(
name|fd
argument_list|)
operator|,
name|m_stream
argument_list|(
name|kInvalidStream
argument_list|)
operator|,
name|m_options
argument_list|(
literal|0
argument_list|)
operator|,
name|m_own_stream
argument_list|(
name|false
argument_list|)
operator|,
name|m_own_descriptor
argument_list|(
argument|transfer_ownership
argument_list|)
block|{     }
comment|//------------------------------------------------------------------
comment|/// Destructor.
comment|///
comment|/// The destructor is virtual in case this class is subclassed.
comment|//------------------------------------------------------------------
name|virtual
operator|~
name|File
argument_list|()
expr_stmt|;
name|bool
name|IsValid
argument_list|()
specifier|const
block|{
return|return
name|DescriptorIsValid
argument_list|()
operator|||
name|StreamIsValid
argument_list|()
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Convert to pointer operator.
comment|///
comment|/// This allows code to check a File object to see if it
comment|/// contains anything valid using code such as:
comment|///
comment|/// @code
comment|/// File file(...);
comment|/// if (file)
comment|/// { ...
comment|/// @endcode
comment|///
comment|/// @return
comment|///     A pointer to this object if either the directory or filename
comment|///     is valid, NULL otherwise.
comment|//------------------------------------------------------------------
name|operator
name|bool
argument_list|()
specifier|const
block|{
return|return
name|DescriptorIsValid
argument_list|()
operator|||
name|StreamIsValid
argument_list|()
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Logical NOT operator.
comment|///
comment|/// This allows code to check a File object to see if it is
comment|/// invalid using code such as:
comment|///
comment|/// @code
comment|/// File file(...);
comment|/// if (!file)
comment|/// { ...
comment|/// @endcode
comment|///
comment|/// @return
comment|///     Returns \b true if the object has an empty directory and
comment|///     filename, \b false otherwise.
comment|//------------------------------------------------------------------
name|bool
name|operator
operator|!
operator|(
operator|)
specifier|const
block|{
return|return
operator|!
name|DescriptorIsValid
argument_list|()
operator|&&
operator|!
name|StreamIsValid
argument_list|()
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Get the file spec for this file.
comment|///
comment|/// @return
comment|///     A reference to the file specification object.
comment|//------------------------------------------------------------------
name|Error
name|GetFileSpec
argument_list|(
name|FileSpec
operator|&
name|file_spec
argument_list|)
decl|const
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Open a file for read/writing with the specified options.
comment|///
comment|/// Takes a path to a file which can be just a filename, or a full
comment|/// path.
comment|///
comment|/// @param[in] path
comment|///     The full or partial path to a file.
comment|///
comment|/// @param[in] options
comment|///     Options to use when opening (see File::OpenOptions)
comment|///
comment|/// @param[in] permissions
comment|///     Options to use when opening (see File::Permissions)
comment|//------------------------------------------------------------------
name|Error
name|Open
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|,
name|uint32_t
name|options
parameter_list|,
name|uint32_t
name|permissions
init|=
name|lldb
operator|::
name|eFilePermissionsFileDefault
parameter_list|)
function_decl|;
name|Error
name|Close
parameter_list|()
function_decl|;
name|Error
name|Duplicate
parameter_list|(
specifier|const
name|File
modifier|&
name|rhs
parameter_list|)
function_decl|;
name|int
name|GetDescriptor
argument_list|()
specifier|const
expr_stmt|;
name|void
name|SetDescriptor
parameter_list|(
name|int
name|fd
parameter_list|,
name|bool
name|transfer_ownership
parameter_list|)
function_decl|;
name|FILE
modifier|*
name|GetStream
parameter_list|()
function_decl|;
name|void
name|SetStream
parameter_list|(
name|FILE
modifier|*
name|fh
parameter_list|,
name|bool
name|transfer_ownership
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Read bytes from a file from the current file position.
comment|///
comment|/// NOTE: This function is NOT thread safe. Use the read function
comment|/// that takes an "off_t&offset" to ensure correct operation in
comment|/// multi-threaded environments.
comment|///
comment|/// @param[in] buf
comment|///     A buffer where to put the bytes that are read.
comment|///
comment|/// @param[in/out] num_bytes
comment|///     The number of bytes to read form the current file position
comment|///     which gets modified with the number of bytes that were read.
comment|///
comment|/// @return
comment|///     An error object that indicates success or the reason for
comment|///     failure.
comment|//------------------------------------------------------------------
name|Error
name|Read
parameter_list|(
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
modifier|&
name|num_bytes
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Write bytes to a file at the current file position.
comment|///
comment|/// NOTE: This function is NOT thread safe. Use the write function
comment|/// that takes an "off_t&offset" to ensure correct operation in
comment|/// multi-threaded environments.
comment|///
comment|/// @param[in] buf
comment|///     A buffer where to put the bytes that are read.
comment|///
comment|/// @param[in/out] num_bytes
comment|///     The number of bytes to write to the current file position
comment|///     which gets modified with the number of bytes that were
comment|///     written.
comment|///
comment|/// @return
comment|///     An error object that indicates success or the reason for
comment|///     failure.
comment|//------------------------------------------------------------------
name|Error
name|Write
parameter_list|(
specifier|const
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
modifier|&
name|num_bytes
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Seek to an offset relative to the beginning of the file.
comment|///
comment|/// NOTE: This function is NOT thread safe, other threads that
comment|/// access this object might also change the current file position.
comment|/// For thread safe reads and writes see the following functions:
comment|/// @see File::Read (void *, size_t, off_t&)
comment|/// @see File::Write (const void *, size_t, off_t&)
comment|///
comment|/// @param[in] offset
comment|///     The offset to seek to within the file relative to the
comment|///     beginning of the file.
comment|///
comment|/// @param[in] error_ptr
comment|///     A pointer to a lldb_private::Error object that will be
comment|///     filled in if non-NULL.
comment|///
comment|/// @return
comment|///     The resulting seek offset, or -1 on error.
comment|//------------------------------------------------------------------
name|off_t
name|SeekFromStart
parameter_list|(
name|off_t
name|offset
parameter_list|,
name|Error
modifier|*
name|error_ptr
init|=
name|NULL
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Seek to an offset relative to the current file position.
comment|///
comment|/// NOTE: This function is NOT thread safe, other threads that
comment|/// access this object might also change the current file position.
comment|/// For thread safe reads and writes see the following functions:
comment|/// @see File::Read (void *, size_t, off_t&)
comment|/// @see File::Write (const void *, size_t, off_t&)
comment|///
comment|/// @param[in] offset
comment|///     The offset to seek to within the file relative to the
comment|///     current file position.
comment|///
comment|/// @param[in] error_ptr
comment|///     A pointer to a lldb_private::Error object that will be
comment|///     filled in if non-NULL.
comment|///
comment|/// @return
comment|///     The resulting seek offset, or -1 on error.
comment|//------------------------------------------------------------------
name|off_t
name|SeekFromCurrent
parameter_list|(
name|off_t
name|offset
parameter_list|,
name|Error
modifier|*
name|error_ptr
init|=
name|NULL
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Seek to an offset relative to the end of the file.
comment|///
comment|/// NOTE: This function is NOT thread safe, other threads that
comment|/// access this object might also change the current file position.
comment|/// For thread safe reads and writes see the following functions:
comment|/// @see File::Read (void *, size_t, off_t&)
comment|/// @see File::Write (const void *, size_t, off_t&)
comment|///
comment|/// @param[in/out] offset
comment|///     The offset to seek to within the file relative to the
comment|///     end of the file which gets filled in the the resulting
comment|///     absolute file offset.
comment|///
comment|/// @param[in] error_ptr
comment|///     A pointer to a lldb_private::Error object that will be
comment|///     filled in if non-NULL.
comment|///
comment|/// @return
comment|///     The resulting seek offset, or -1 on error.
comment|//------------------------------------------------------------------
name|off_t
name|SeekFromEnd
parameter_list|(
name|off_t
name|offset
parameter_list|,
name|Error
modifier|*
name|error_ptr
init|=
name|NULL
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Read bytes from a file from the specified file offset.
comment|///
comment|/// NOTE: This function is thread safe in that clients manager their
comment|/// own file position markers and reads on other threads won't mess
comment|/// up the current read.
comment|///
comment|/// @param[in] buf
comment|///     A buffer where to put the bytes that are read.
comment|///
comment|/// @param[in/out] num_bytes
comment|///     The number of bytes to read form the current file position
comment|///     which gets modified with the number of bytes that were read.
comment|///
comment|/// @param[in/out] offset
comment|///     The offset within the file from which to read \a num_bytes
comment|///     bytes. This offset gets incremented by the number of bytes
comment|///     that were read.
comment|///
comment|/// @return
comment|///     An error object that indicates success or the reason for
comment|///     failure.
comment|//------------------------------------------------------------------
name|Error
name|Read
parameter_list|(
name|void
modifier|*
name|dst
parameter_list|,
name|size_t
modifier|&
name|num_bytes
parameter_list|,
name|off_t
modifier|&
name|offset
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Read bytes from a file from the specified file offset.
comment|///
comment|/// NOTE: This function is thread safe in that clients manager their
comment|/// own file position markers and reads on other threads won't mess
comment|/// up the current read.
comment|///
comment|/// @param[in/out] num_bytes
comment|///     The number of bytes to read form the current file position
comment|///     which gets modified with the number of bytes that were read.
comment|///
comment|/// @param[in/out] offset
comment|///     The offset within the file from which to read \a num_bytes
comment|///     bytes. This offset gets incremented by the number of bytes
comment|///     that were read.
comment|///
comment|/// @param[in] null_terminate
comment|///     Ensure that the data that is read is terminated with a NULL
comment|///     character so that the data can be used as a C string.
comment|///
comment|/// @param[out] data_buffer_sp
comment|///     A data buffer to create and fill in that will contain any
comment|///     data that is read from the file. This buffer will be reset
comment|///     if an error occurs.
comment|///
comment|/// @return
comment|///     An error object that indicates success or the reason for
comment|///     failure.
comment|//------------------------------------------------------------------
name|Error
name|Read
argument_list|(
name|size_t
operator|&
name|num_bytes
argument_list|,
name|off_t
operator|&
name|offset
argument_list|,
name|bool
name|null_terminate
argument_list|,
name|lldb
operator|::
name|DataBufferSP
operator|&
name|data_buffer_sp
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Write bytes to a file at the specified file offset.
comment|///
comment|/// NOTE: This function is thread safe in that clients manager their
comment|/// own file position markers, though clients will need to implement
comment|/// their own locking externally to avoid multiple people writing
comment|/// to the file at the same time.
comment|///
comment|/// @param[in] buf
comment|///     A buffer containing the bytes to write.
comment|///
comment|/// @param[in/out] num_bytes
comment|///     The number of bytes to write to the file at offset \a offset.
comment|///     \a num_bytes gets modified with the number of bytes that
comment|///     were read.
comment|///
comment|/// @param[in/out] offset
comment|///     The offset within the file at which to write \a num_bytes
comment|///     bytes. This offset gets incremented by the number of bytes
comment|///     that were written.
comment|///
comment|/// @return
comment|///     An error object that indicates success or the reason for
comment|///     failure.
comment|//------------------------------------------------------------------
name|Error
name|Write
parameter_list|(
specifier|const
name|void
modifier|*
name|src
parameter_list|,
name|size_t
modifier|&
name|num_bytes
parameter_list|,
name|off_t
modifier|&
name|offset
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Flush the current stream
comment|///
comment|/// @return
comment|///     An error object that indicates success or the reason for
comment|///     failure.
comment|//------------------------------------------------------------------
name|Error
name|Flush
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Sync to disk.
comment|///
comment|/// @return
comment|///     An error object that indicates success or the reason for
comment|///     failure.
comment|//------------------------------------------------------------------
name|Error
name|Sync
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Get the permissions for a this file.
comment|///
comment|/// @return
comment|///     Bits logical OR'ed together from the permission bits defined
comment|///     in lldb_private::File::Permissions.
comment|//------------------------------------------------------------------
name|uint32_t
name|GetPermissions
argument_list|(
name|Error
operator|&
name|error
argument_list|)
decl|const
decl_stmt|;
specifier|static
name|uint32_t
name|GetPermissions
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|,
name|Error
modifier|&
name|error
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Return true if this file is interactive.
comment|///
comment|/// @return
comment|///     True if this file is a terminal (tty or pty), false
comment|///     otherwise.
comment|//------------------------------------------------------------------
name|bool
name|GetIsInteractive
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Return true if this file from a real terminal.
comment|///
comment|/// Just knowing a file is a interactive isn't enough, we also need
comment|/// to know if the terminal has a width and height so we can do
comment|/// cursor movement and other terminal maninpulations by sending
comment|/// escape sequences.
comment|///
comment|/// @return
comment|///     True if this file is a terminal (tty, not a pty) that has
comment|///     a non-zero width and height, false otherwise.
comment|//------------------------------------------------------------------
name|bool
name|GetIsRealTerminal
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Output printf formatted output to the stream.
comment|///
comment|/// Print some formatted output to the stream.
comment|///
comment|/// @param[in] format
comment|///     A printf style format string.
comment|///
comment|/// @param[in] ...
comment|///     Variable arguments that are needed for the printf style
comment|///     format string \a format.
comment|//------------------------------------------------------------------
name|size_t
name|Printf
parameter_list|(
specifier|const
name|char
modifier|*
name|format
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|2
operator|,
function_decl|3
block|)
decl_stmt|)
block|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|size_t
name|PrintfVarArg
parameter_list|(
specifier|const
name|char
modifier|*
name|format
parameter_list|,
name|va_list
name|args
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|SetOptions
parameter_list|(
name|uint32_t
name|options
parameter_list|)
block|{
name|m_options
operator|=
name|options
expr_stmt|;
block|}
end_function

begin_label
name|protected
label|:
end_label

begin_expr_stmt
name|bool
name|DescriptorIsValid
argument_list|()
specifier|const
block|{
return|return
name|m_descriptor
operator|>=
literal|0
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|StreamIsValid
argument_list|()
specifier|const
block|{
return|return
name|m_stream
operator|!=
name|kInvalidStream
return|;
block|}
end_expr_stmt

begin_function_decl
name|void
name|CalculateInteractiveAndTerminal
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|// Member variables
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_decl_stmt
name|int
name|m_descriptor
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|FILE
modifier|*
name|m_stream
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|uint32_t
name|m_options
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|m_own_stream
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|m_own_descriptor
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|LazyBool
name|m_is_interactive
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|LazyBool
name|m_is_real_terminal
decl_stmt|;
end_decl_stmt

begin_comment
unit|};  }
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// #if defined(__cplusplus)
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_File_h_
end_comment

end_unit

