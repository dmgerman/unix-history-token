begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- FileSpec.h ----------------------------------------------*- C++ -*-===//
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
name|liblldb_FileSpec_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_FileSpec_h_
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
file|"lldb/lldb-private.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/ConstString.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/STLUtils.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Host/TimeValue.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//----------------------------------------------------------------------
comment|/// @class FileSpec FileSpec.h "lldb/Host/FileSpec.h"
comment|/// @brief A file utility class.
comment|///
comment|/// A file specification class that divides paths up into a directory
comment|/// and basename. These string values of the paths are put into uniqued
comment|/// string pools for fast comparisons and efficient memory usage.
comment|///
comment|/// Another reason the paths are split into the directory and basename
comment|/// is to allow efficient debugger searching. Often in a debugger the
comment|/// user types in the basename of the file, for example setting a
comment|/// breakpoint by file and line, or specifying a module (shared library)
comment|/// to limit the scope in which to execute a command. The user rarely
comment|/// types in a full path. When the paths are already split up, it makes
comment|/// it easy for us to compare only the basenames of a lot of file
comment|/// specifications without having to split up the file path each time
comment|/// to get to the basename.
comment|//----------------------------------------------------------------------
name|class
name|FileSpec
block|{
name|public
label|:
typedef|typedef
enum|enum
name|FileType
block|{
name|eFileTypeInvalid
init|=
operator|-
literal|1
block|,
name|eFileTypeUnknown
init|=
literal|0
block|,
name|eFileTypeDirectory
block|,
name|eFileTypePipe
block|,
name|eFileTypeRegular
block|,
name|eFileTypeSocket
block|,
name|eFileTypeSymbolicLink
block|,
name|eFileTypeOther
block|}
name|FileType
typedef|;
name|FileSpec
argument_list|()
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Constructor with path.
comment|///
comment|/// Takes a path to a file which can be just a filename, or a full
comment|/// path. If \a path is not NULL or empty, this function will call
comment|/// FileSpec::SetFile (const char *path, bool resolve).
comment|///
comment|/// @param[in] path
comment|///     The full or partial path to a file.
comment|///
comment|/// @param[in] resolve_path
comment|///     If \b true, then we resolve the path with realpath,
comment|///     if \b false we trust the path is in canonical form already.
comment|///
comment|/// @see FileSpec::SetFile (const char *path, bool resolve)
comment|//------------------------------------------------------------------
name|explicit
name|FileSpec
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|,
name|bool
name|resolve_path
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Copy constructor
comment|///
comment|/// Makes a copy of the uniqued directory and filename strings from
comment|/// \a rhs.
comment|///
comment|/// @param[in] rhs
comment|///     A const FileSpec object reference to copy.
comment|//------------------------------------------------------------------
name|FileSpec
argument_list|(
specifier|const
name|FileSpec
operator|&
name|rhs
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Copy constructor
comment|///
comment|/// Makes a copy of the uniqued directory and filename strings from
comment|/// \a rhs if it is not NULL.
comment|///
comment|/// @param[in] rhs
comment|///     A const FileSpec object pointer to copy if non-NULL.
comment|//------------------------------------------------------------------
name|FileSpec
argument_list|(
specifier|const
name|FileSpec
operator|*
name|rhs
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Destructor.
comment|//------------------------------------------------------------------
operator|~
name|FileSpec
argument_list|()
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Assignment operator.
comment|///
comment|/// Makes a copy of the uniqued directory and filename strings from
comment|/// \a rhs.
comment|///
comment|/// @param[in] rhs
comment|///     A const FileSpec object reference to assign to this object.
comment|///
comment|/// @return
comment|///     A const reference to this object.
comment|//------------------------------------------------------------------
specifier|const
name|FileSpec
modifier|&
name|operator
init|=
operator|(
specifier|const
name|FileSpec
operator|&
name|rhs
operator|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Equal to operator
comment|///
comment|/// Tests if this object is equal to \a rhs.
comment|///
comment|/// @param[in] rhs
comment|///     A const FileSpec object reference to compare this object
comment|///     to.
comment|///
comment|/// @return
comment|///     \b true if this object is equal to \a rhs, \b false
comment|///     otherwise.
comment|//------------------------------------------------------------------
name|bool
name|operator
operator|==
operator|(
specifier|const
name|FileSpec
operator|&
name|rhs
operator|)
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Not equal to operator
comment|///
comment|/// Tests if this object is not equal to \a rhs.
comment|///
comment|/// @param[in] rhs
comment|///     A const FileSpec object reference to compare this object
comment|///     to.
comment|///
comment|/// @return
comment|///     \b true if this object is equal to \a rhs, \b false
comment|///     otherwise.
comment|//------------------------------------------------------------------
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|FileSpec
operator|&
name|rhs
operator|)
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Less than to operator
comment|///
comment|/// Tests if this object is less than \a rhs.
comment|///
comment|/// @param[in] rhs
comment|///     A const FileSpec object reference to compare this object
comment|///     to.
comment|///
comment|/// @return
comment|///     \b true if this object is less than \a rhs, \b false
comment|///     otherwise.
comment|//------------------------------------------------------------------
name|bool
name|operator
operator|<
operator|(
specifier|const
name|FileSpec
operator|&
name|rhs
operator|)
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Convert to pointer operator.
comment|///
comment|/// This allows code to check a FileSpec object to see if it
comment|/// contains anything valid using code such as:
comment|///
comment|/// @code
comment|/// FileSpec file_spec(...);
comment|/// if (file_spec)
comment|/// { ...
comment|/// @endcode
comment|///
comment|/// @return
comment|///     A pointer to this object if either the directory or filename
comment|///     is valid, NULL otherwise.
comment|//------------------------------------------------------------------
name|explicit
name|operator
name|bool
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Logical NOT operator.
comment|///
comment|/// This allows code to check a FileSpec object to see if it is
comment|/// invalid using code such as:
comment|///
comment|/// @code
comment|/// FileSpec file_spec(...);
comment|/// if (!file_spec)
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
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Clears the object state.
comment|///
comment|/// Clear this object by releasing both the directory and filename
comment|/// string values and reverting them to empty strings.
comment|//------------------------------------------------------------------
name|void
name|Clear
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Compare two FileSpec objects.
comment|///
comment|/// If \a full is true, then both the directory and the filename
comment|/// must match. If \a full is false, then the directory names for
comment|/// \a lhs and \a rhs are only compared if they are both not empty.
comment|/// This allows a FileSpec object to only contain a filename
comment|/// and it can match FileSpec objects that have matching
comment|/// filenames with different paths.
comment|///
comment|/// @param[in] lhs
comment|///     A const reference to the Left Hand Side object to compare.
comment|///
comment|/// @param[in] rhs
comment|///     A const reference to the Right Hand Side object to compare.
comment|///
comment|/// @param[in] full
comment|///     If true, then both the directory and filenames will have to
comment|///     match for a compare to return zero (equal to). If false
comment|///     and either directory from \a lhs or \a rhs is empty, then
comment|///     only the filename will be compared, else a full comparison
comment|///     is done.
comment|///
comment|/// @return
comment|///     @li -1 if \a lhs is less than \a rhs
comment|///     @li 0 if \a lhs is equal to \a rhs
comment|///     @li 1 if \a lhs is greater than \a rhs
comment|//------------------------------------------------------------------
specifier|static
name|int
name|Compare
parameter_list|(
specifier|const
name|FileSpec
modifier|&
name|lhs
parameter_list|,
specifier|const
name|FileSpec
modifier|&
name|rhs
parameter_list|,
name|bool
name|full
parameter_list|)
function_decl|;
specifier|static
name|bool
name|Equal
parameter_list|(
specifier|const
name|FileSpec
modifier|&
name|a
parameter_list|,
specifier|const
name|FileSpec
modifier|&
name|b
parameter_list|,
name|bool
name|full
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Dump this object to a Stream.
comment|///
comment|/// Dump the object to the supplied stream \a s. If the object
comment|/// contains a valid directory name, it will be displayed followed
comment|/// by a directory delimiter, and the filename.
comment|///
comment|/// @param[in] s
comment|///     The stream to which to dump the object descripton.
comment|//------------------------------------------------------------------
name|void
name|Dump
argument_list|(
name|Stream
operator|*
name|s
argument_list|)
decl|const
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Existence test.
comment|///
comment|/// @return
comment|///     \b true if the file exists on disk, \b false otherwise.
comment|//------------------------------------------------------------------
name|bool
name|Exists
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Expanded existence test.
comment|///
comment|/// Call into the Host to see if it can help find the file (e.g. by
comment|/// searching paths set in the environment, etc.).
comment|///
comment|/// If found, sets the value of m_directory to the directory where
comment|/// the file was found.
comment|///
comment|/// @return
comment|///     \b true if was able to find the file using expanded search
comment|///     methods, \b false otherwise.
comment|//------------------------------------------------------------------
name|bool
name|ResolveExecutableLocation
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Canonicalize this file path (basically running the static
comment|/// FileSpec::Resolve method on it). Useful if you asked us not to
comment|/// resolve the file path when you set the file.
comment|//------------------------------------------------------------------
name|bool
name|ResolvePath
parameter_list|()
function_decl|;
name|uint64_t
name|GetByteSize
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Directory string get accessor.
comment|///
comment|/// @return
comment|///     A reference to the directory string object.
comment|//------------------------------------------------------------------
name|ConstString
modifier|&
name|GetDirectory
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Directory string const get accessor.
comment|///
comment|/// @return
comment|///     A const reference to the directory string object.
comment|//------------------------------------------------------------------
specifier|const
name|ConstString
operator|&
name|GetDirectory
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Filename string get accessor.
comment|///
comment|/// @return
comment|///     A reference to the filename string object.
comment|//------------------------------------------------------------------
name|ConstString
modifier|&
name|GetFilename
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Filename string const get accessor.
comment|///
comment|/// @return
comment|///     A const reference to the filename string object.
comment|//------------------------------------------------------------------
specifier|const
name|ConstString
operator|&
name|GetFilename
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Returns true if the filespec represents an implementation source
comment|/// file (files with a ".c", ".cpp", ".m", ".mm" (many more)
comment|/// extension).
comment|///
comment|/// @return
comment|///     \b true if the filespec represents an implementation source
comment|///     file, \b false otherwise.
comment|//------------------------------------------------------------------
name|bool
name|IsSourceImplementationFile
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Returns true if the filespec represents path that is relative
comment|/// path to the current working directory.
comment|///
comment|/// @return
comment|///     \b true if the filespec represents a current working
comment|///     directory relative path, \b false otherwise.
comment|//------------------------------------------------------------------
name|bool
name|IsRelativeToCurrentWorkingDirectory
argument_list|()
specifier|const
expr_stmt|;
name|TimeValue
name|GetModificationTime
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Extract the full path to the file.
comment|///
comment|/// Extract the directory and path into a fixed buffer. This is
comment|/// needed as the directory and path are stored in separate string
comment|/// values.
comment|///
comment|/// @param[out] path
comment|///     The buffer in which to place the extracted full path.
comment|///
comment|/// @param[in] max_path_length
comment|///     The maximum length of \a path.
comment|///
comment|/// @return
comment|///     Returns the number of characters that would be needed to
comment|///     properly copy the full path into \a path. If the returned
comment|///     number is less than \a max_path_length, then the path is
comment|///     properly copied and terminated. If the return value is
comment|///>= \a max_path_length, then the path was truncated (but is
comment|///     still NULL terminated).
comment|//------------------------------------------------------------------
name|size_t
name|GetPath
argument_list|(
name|char
operator|*
name|path
argument_list|,
name|size_t
name|max_path_length
argument_list|)
decl|const
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Extract the full path to the file.
comment|///
comment|/// Extract the directory and path into a std::string, which is returned.
comment|///
comment|/// @return
comment|///     Returns a std::string with the directory and filename
comment|///     concatenated.
comment|//------------------------------------------------------------------
name|std
operator|::
name|string
name|GetPath
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Extract the extension of the file.
comment|///
comment|/// Returns a ConstString that represents the extension of the filename
comment|/// for this FileSpec object. If this object does not represent a file,
comment|/// or the filename has no extension, ConstString(NULL) is returned.
comment|/// The dot ('.') character is not returned as part of the extension
comment|///
comment|/// @return
comment|///     Returns the extension of the file as a ConstString object.
comment|//------------------------------------------------------------------
name|ConstString
name|GetFileNameExtension
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Return the filename without the extension part
comment|///
comment|/// Returns a ConstString that represents the filename of this object
comment|/// without the extension part (e.g. for a file named "foo.bar", "foo"
comment|/// is returned)
comment|///
comment|/// @return
comment|///     Returns the filename without extension
comment|///     as a ConstString object.
comment|//------------------------------------------------------------------
name|ConstString
name|GetFileNameStrippingExtension
argument_list|()
specifier|const
expr_stmt|;
name|FileType
name|GetFileType
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Return the current permissions of the path.
comment|///
comment|/// Returns a bitmask for the current permissions of the file
comment|/// ( zero or more of the permission bits defined in
comment|/// File::Permissions).
comment|///
comment|/// @return
comment|///     Zero if the file doesn't exist or we are unable to get
comment|///     information for the file, otherwise one or more permission
comment|///     bits from the File::Permissions enumeration.
comment|//------------------------------------------------------------------
name|uint32_t
name|GetPermissions
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|IsDirectory
argument_list|()
specifier|const
block|{
return|return
name|GetFileType
argument_list|()
operator|==
name|FileSpec
operator|::
name|eFileTypeDirectory
return|;
block|}
name|bool
name|IsPipe
argument_list|()
specifier|const
block|{
return|return
name|GetFileType
argument_list|()
operator|==
name|FileSpec
operator|::
name|eFileTypePipe
return|;
block|}
name|bool
name|IsRegularFile
argument_list|()
specifier|const
block|{
return|return
name|GetFileType
argument_list|()
operator|==
name|FileSpec
operator|::
name|eFileTypeRegular
return|;
block|}
name|bool
name|IsSocket
argument_list|()
specifier|const
block|{
return|return
name|GetFileType
argument_list|()
operator|==
name|FileSpec
operator|::
name|eFileTypeSocket
return|;
block|}
name|bool
name|IsSymbolicLink
argument_list|()
specifier|const
block|{
return|return
name|GetFileType
argument_list|()
operator|==
name|FileSpec
operator|::
name|eFileTypeSymbolicLink
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Get the memory cost of this object.
comment|///
comment|/// Return the size in bytes that this object takes in memory. This
comment|/// returns the size in bytes of this object, not any shared string
comment|/// values it may refer to.
comment|///
comment|/// @return
comment|///     The number of bytes that this object occupies in memory.
comment|///
comment|/// @see ConstString::StaticMemorySize ()
comment|//------------------------------------------------------------------
name|size_t
name|MemorySize
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Memory map part of, or the entire contents of, a file.
comment|///
comment|/// Returns a shared pointer to a data buffer that contains all or
comment|/// part of the contents of a file. The data is memory mapped and
comment|/// will lazily page in data from the file as memory is accessed.
comment|/// The data that is mappped will start \a offset bytes into the
comment|/// file, and \a length bytes will be mapped. If \a length is
comment|/// greater than the number of bytes available in the file starting
comment|/// at \a offset, the number of bytes will be appropriately
comment|/// truncated. The final number of bytes that get mapped can be
comment|/// verified using the DataBuffer::GetByteSize() function on the return
comment|/// shared data pointer object contents.
comment|///
comment|/// @param[in] offset
comment|///     The offset in bytes from the beginning of the file where
comment|///     memory mapping should begin.
comment|///
comment|/// @param[in] length
comment|///     The size in bytes that should be mapped starting \a offset
comment|///     bytes into the file. If \a length is \c SIZE_MAX, map
comment|///     as many bytes as possible.
comment|///
comment|/// @return
comment|///     A shared pointer to the memeory mapped data. This shared
comment|///     pointer can contain a NULL DataBuffer pointer, so the contained
comment|///     pointer must be checked prior to using it.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|DataBufferSP
name|MemoryMapFileContents
argument_list|(
argument|off_t offset =
literal|0
argument_list|,
argument|size_t length = SIZE_MAX
argument_list|)
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Read part of, or the entire contents of, a file into a heap based data buffer.
comment|///
comment|/// Returns a shared pointer to a data buffer that contains all or
comment|/// part of the contents of a file. The data copies into a heap based
comment|/// buffer that lives in the DataBuffer shared pointer object returned.
comment|/// The data that is cached will start \a offset bytes into the
comment|/// file, and \a length bytes will be mapped. If \a length is
comment|/// greater than the number of bytes available in the file starting
comment|/// at \a offset, the number of bytes will be appropriately
comment|/// truncated. The final number of bytes that get mapped can be
comment|/// verified using the DataBuffer::GetByteSize() function.
comment|///
comment|/// @param[in] offset
comment|///     The offset in bytes from the beginning of the file where
comment|///     memory mapping should begin.
comment|///
comment|/// @param[in] length
comment|///     The size in bytes that should be mapped starting \a offset
comment|///     bytes into the file. If \a length is \c SIZE_MAX, map
comment|///     as many bytes as possible.
comment|///
comment|/// @return
comment|///     A shared pointer to the memory mapped data. This shared
comment|///     pointer can contain a NULL DataBuffer pointer, so the contained
comment|///     pointer must be checked prior to using it.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|DataBufferSP
name|ReadFileContents
argument_list|(
argument|off_t offset =
literal|0
argument_list|,
argument|size_t length = SIZE_MAX
argument_list|,
argument|Error *error_ptr = NULL
argument_list|)
specifier|const
expr_stmt|;
name|size_t
name|ReadFileContents
argument_list|(
name|off_t
name|file_offset
argument_list|,
name|void
operator|*
name|dst
argument_list|,
name|size_t
name|dst_len
argument_list|,
name|Error
operator|*
name|error_ptr
argument_list|)
decl|const
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Read the entire contents of a file as data that can be used
comment|/// as a C string.
comment|///
comment|/// Read the entire contents of a file and ensure that the data
comment|/// is NULL terminated so it can be used as a C string.
comment|///
comment|/// @return
comment|///     A shared pointer to the data. This shared pointer can
comment|///     contain a NULL DataBuffer pointer, so the contained pointer
comment|///     must be checked prior to using it.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|DataBufferSP
name|ReadFileContentsAsCString
argument_list|(
name|Error
operator|*
name|error_ptr
operator|=
name|NULL
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Change the file specificed with a new path.
comment|///
comment|/// Update the contents of this object with a new path. The path will
comment|/// be split up into a directory and filename and stored as uniqued
comment|/// string values for quick comparison and efficient memory usage.
comment|///
comment|/// @param[in] path
comment|///     A full, partial, or relative path to a file.
comment|///
comment|/// @param[in] resolve_path
comment|///     If \b true, then we will try to resolve links the path using
comment|///     the static FileSpec::Resolve.
comment|//------------------------------------------------------------------
name|void
name|SetFile
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|,
name|bool
name|resolve_path
parameter_list|)
function_decl|;
name|bool
name|IsResolved
argument_list|()
specifier|const
block|{
return|return
name|m_is_resolved
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Set if the file path has been resolved or not.
comment|///
comment|/// If you know a file path is already resolved and avoided passing
comment|/// a \b true parameter for any functions that take a "bool
comment|/// resolve_path" parameter, you can set the value manually using
comment|/// this call to make sure we don't try and resolve it later, or try
comment|/// and resolve a path that has already been resolved.
comment|///
comment|/// @param[in] is_resolved
comment|///     A boolean value that will replace the current value that
comment|///     indicates if the paths in this object have been resolved.
comment|//------------------------------------------------------------------
name|void
name|SetIsResolved
parameter_list|(
name|bool
name|is_resolved
parameter_list|)
block|{
name|m_is_resolved
operator|=
name|is_resolved
expr_stmt|;
block|}
comment|//------------------------------------------------------------------
comment|/// Read the file into an array of strings, one per line.
comment|///
comment|/// Opens and reads the file in this object into an array of strings,
comment|/// one string per line of the file. Returns a boolean indicating
comment|/// success or failure.
comment|///
comment|/// @param[out] lines
comment|///     The string array into which to read the file.
comment|///
comment|/// @result
comment|///     Returns the number of lines that were read from the file.
comment|//------------------------------------------------------------------
name|size_t
name|ReadFileLines
parameter_list|(
name|STLStringArray
modifier|&
name|lines
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Resolves user name and links in \a src_path, and writes the output
comment|/// to \a dst_path.  Note if the path pointed to by \a src_path does not
comment|/// exist, the contents of \a src_path will be copied to \a dst_path
comment|/// unchanged.
comment|///
comment|/// @param[in] src_path
comment|///     Input path to be resolved.
comment|///
comment|/// @param[in] dst_path
comment|///     Buffer to store the resolved path.
comment|///
comment|/// @param[in] dst_len
comment|///     Size of the buffer pointed to by dst_path.
comment|///
comment|/// @result
comment|///     The number of characters required to write the resolved path.  If the
comment|///     resolved path doesn't fit in dst_len, dst_len-1 characters will
comment|///     be written to \a dst_path, but the actual required length will still be returned.
comment|//------------------------------------------------------------------
specifier|static
name|size_t
name|Resolve
parameter_list|(
specifier|const
name|char
modifier|*
name|src_path
parameter_list|,
name|char
modifier|*
name|dst_path
parameter_list|,
name|size_t
name|dst_len
parameter_list|)
function_decl|;
name|FileSpec
name|CopyByAppendingPathComponent
argument_list|(
specifier|const
name|char
operator|*
name|new_path
argument_list|)
decl|const
decl_stmt|;
name|FileSpec
name|CopyByRemovingLastPathComponent
argument_list|()
specifier|const
expr_stmt|;
name|void
name|AppendPathComponent
parameter_list|(
specifier|const
name|char
modifier|*
name|new_path
parameter_list|)
function_decl|;
name|void
name|RemoveLastPathComponent
parameter_list|()
function_decl|;
name|ConstString
name|GetLastPathComponent
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Resolves the user name at the beginning of \a src_path, and writes the output
comment|/// to \a dst_path.  Note, \a src_path can contain other path components after the
comment|/// user name, they will be copied over, and if the path doesn't start with "~" it
comment|/// will also be copied over to \a dst_path.
comment|///
comment|/// @param[in] src_path
comment|///     Input path to be resolved.
comment|///
comment|/// @param[in] dst_path
comment|///     Buffer to store the resolved path.
comment|///
comment|/// @param[in] dst_len
comment|///     Size of the buffer pointed to by dst_path.
comment|///
comment|/// @result
comment|///     The number of characters required to write the resolved path, or 0 if
comment|///     the user name could not be found.  If the
comment|///     resolved path doesn't fit in dst_len, dst_len-1 characters will
comment|///     be written to \a dst_path, but the actual required length will still be returned.
comment|//------------------------------------------------------------------
specifier|static
name|size_t
name|ResolveUsername
parameter_list|(
specifier|const
name|char
modifier|*
name|src_path
parameter_list|,
name|char
modifier|*
name|dst_path
parameter_list|,
name|size_t
name|dst_len
parameter_list|)
function_decl|;
specifier|static
name|size_t
name|ResolvePartialUsername
parameter_list|(
specifier|const
name|char
modifier|*
name|partial_name
parameter_list|,
name|StringList
modifier|&
name|matches
parameter_list|)
function_decl|;
enum|enum
name|EnumerateDirectoryResult
block|{
name|eEnumerateDirectoryResultNext
block|,
comment|// Enumerate next entry in the current directory
name|eEnumerateDirectoryResultEnter
block|,
comment|// Recurse into the current entry if it is a directory or symlink, or next if not
name|eEnumerateDirectoryResultExit
block|,
comment|// Exit from the current directory at the current level.
name|eEnumerateDirectoryResultQuit
comment|// Stop directory enumerations at any level
block|}
enum|;
typedef|typedef
name|EnumerateDirectoryResult
function_decl|(
modifier|*
name|EnumerateDirectoryCallbackType
function_decl|)
parameter_list|(
name|void
modifier|*
name|baton
parameter_list|,
name|FileType
name|file_type
parameter_list|,
specifier|const
name|FileSpec
modifier|&
name|spec
parameter_list|)
function_decl|;
specifier|static
name|EnumerateDirectoryResult
name|EnumerateDirectory
parameter_list|(
specifier|const
name|char
modifier|*
name|dir_path
parameter_list|,
name|bool
name|find_directories
parameter_list|,
name|bool
name|find_files
parameter_list|,
name|bool
name|find_other
parameter_list|,
name|EnumerateDirectoryCallbackType
name|callback
parameter_list|,
name|void
modifier|*
name|callback_baton
parameter_list|)
function_decl|;
name|protected
label|:
comment|//------------------------------------------------------------------
comment|// Member variables
comment|//------------------------------------------------------------------
name|ConstString
name|m_directory
decl_stmt|;
comment|///< The uniqued directory path
name|ConstString
name|m_filename
decl_stmt|;
comment|///< The uniqued filename path
name|mutable
name|bool
name|m_is_resolved
decl_stmt|;
comment|///< True if this path has been resolved.
block|}
empty_stmt|;
comment|//----------------------------------------------------------------------
comment|/// Dump a FileSpec object to a stream
comment|//----------------------------------------------------------------------
name|Stream
operator|&
name|operator
operator|<<
operator|(
name|Stream
operator|&
name|s
operator|,
specifier|const
name|FileSpec
operator|&
name|f
operator|)
expr_stmt|;
block|}
end_decl_stmt

begin_comment
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
comment|// liblldb_FileSpec_h_
end_comment

end_unit

