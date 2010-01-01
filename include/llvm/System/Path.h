begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/System/Path.h - Path Operating System Concept -------*- C++ -*-===//
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
comment|// This file declares the llvm::sys::Path class.
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
name|LLVM_SYSTEM_PATH_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SYSTEM_PATH_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/System/TimeValue.h"
end_include

begin_include
include|#
directive|include
file|<set>
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

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|sys
block|{
comment|/// This structure provides basic file system information about a file. It
comment|/// is patterned after the stat(2) Unix operating system call but made
comment|/// platform independent and eliminates many of the unix-specific fields.
comment|/// However, to support llvm-ar, the mode, user, and group fields are
comment|/// retained. These pertain to unix security and may not have a meaningful
comment|/// value on non-Unix platforms. However, the other fields fields should
comment|/// always be applicable on all platforms.  The structure is filled in by
comment|/// the PathWithStatus class.
comment|/// @brief File status structure
name|class
name|FileStatus
block|{
name|public
label|:
name|uint64_t
name|fileSize
decl_stmt|;
comment|///< Size of the file in bytes
name|TimeValue
name|modTime
decl_stmt|;
comment|///< Time of file's modification
name|uint32_t
name|mode
decl_stmt|;
comment|///< Mode of the file, if applicable
name|uint32_t
name|user
decl_stmt|;
comment|///< User ID of owner, if applicable
name|uint32_t
name|group
decl_stmt|;
comment|///< Group ID of owner, if applicable
name|uint64_t
name|uniqueID
decl_stmt|;
comment|///< A number to uniquely ID this file
name|bool
name|isDir
range|:
literal|1
decl_stmt|;
comment|///< True if this is a directory.
name|bool
name|isFile
range|:
literal|1
decl_stmt|;
comment|///< True if this is a file.
name|FileStatus
argument_list|()
operator|:
name|fileSize
argument_list|(
literal|0
argument_list|)
operator|,
name|modTime
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
operator|,
name|mode
argument_list|(
literal|0777
argument_list|)
operator|,
name|user
argument_list|(
literal|999
argument_list|)
operator|,
name|group
argument_list|(
literal|999
argument_list|)
operator|,
name|uniqueID
argument_list|(
literal|0
argument_list|)
operator|,
name|isDir
argument_list|(
name|false
argument_list|)
operator|,
name|isFile
argument_list|(
argument|false
argument_list|)
block|{ }
name|TimeValue
name|getTimestamp
argument_list|()
specifier|const
block|{
return|return
name|modTime
return|;
block|}
name|uint64_t
name|getSize
argument_list|()
specifier|const
block|{
return|return
name|fileSize
return|;
block|}
name|uint32_t
name|getMode
argument_list|()
specifier|const
block|{
return|return
name|mode
return|;
block|}
name|uint32_t
name|getUser
argument_list|()
specifier|const
block|{
return|return
name|user
return|;
block|}
name|uint32_t
name|getGroup
argument_list|()
specifier|const
block|{
return|return
name|group
return|;
block|}
name|uint64_t
name|getUniqueID
argument_list|()
specifier|const
block|{
return|return
name|uniqueID
return|;
block|}
block|}
empty_stmt|;
comment|/// This class provides an abstraction for the path to a file or directory
comment|/// in the operating system's filesystem and provides various basic operations
comment|/// on it.  Note that this class only represents the name of a path to a file
comment|/// or directory which may or may not be valid for a given machine's file
comment|/// system. The class is patterned after the java.io.File class with various
comment|/// extensions and several omissions (not relevant to LLVM).  A Path object
comment|/// ensures that the path it encapsulates is syntactically valid for the
comment|/// operating system it is running on but does not ensure correctness for
comment|/// any particular file system. That is, a syntactically valid path might
comment|/// specify path components that do not exist in the file system and using
comment|/// such a Path to act on the file system could produce errors. There is one
comment|/// invalid Path value which is permitted: the empty path.  The class should
comment|/// never allow a syntactically invalid non-empty path name to be assigned.
comment|/// Empty paths are required in order to indicate an error result in some
comment|/// situations. If the path is empty, the isValid operation will return
comment|/// false. All operations will fail if isValid is false. Operations that
comment|/// change the path will either return false if it would cause a syntactically
comment|/// invalid path name (in which case the Path object is left unchanged) or
comment|/// throw an std::string exception indicating the error. The methods are
comment|/// grouped into four basic categories: Path Accessors (provide information
comment|/// about the path without accessing disk), Disk Accessors (provide
comment|/// information about the underlying file or directory), Path Mutators
comment|/// (change the path information, not the disk), and Disk Mutators (change
comment|/// the disk file/directory referenced by the path). The Disk Mutator methods
comment|/// all have the word "disk" embedded in their method name to reinforce the
comment|/// notion that the operation modifies the file system.
comment|/// @since 1.4
comment|/// @brief An abstraction for operating system paths.
name|class
name|Path
block|{
comment|/// @name Constructors
comment|/// @{
name|public
label|:
comment|/// Construct a path to the root directory of the file system. The root
comment|/// directory is a top level directory above which there are no more
comment|/// directories. For example, on UNIX, the root directory is /. On Windows
comment|/// it is C:\. Other operating systems may have different notions of
comment|/// what the root directory is or none at all. In that case, a consistent
comment|/// default root directory will be used.
specifier|static
name|Path
name|GetRootDirectory
parameter_list|()
function_decl|;
comment|/// Construct a path to a unique temporary directory that is created in
comment|/// a "standard" place for the operating system. The directory is
comment|/// guaranteed to be created on exit from this function. If the directory
comment|/// cannot be created, the function will throw an exception.
comment|/// @returns an invalid path (empty) on error
comment|/// @param ErrMsg Optional place for an error message if an error occurs
comment|/// @brief Constrct a path to an new, unique, existing temporary
comment|/// directory.
specifier|static
name|Path
name|GetTemporaryDirectory
argument_list|(
name|std
operator|::
name|string
operator|*
name|ErrMsg
operator|=
literal|0
argument_list|)
decl_stmt|;
comment|/// Construct a vector of sys::Path that contains the "standard" system
comment|/// library paths suitable for linking into programs. This function *must*
comment|/// return the value of LLVM_LIB_SEARCH_PATH as the first item in \p Paths
comment|/// if that environment variable is set and it references a directory.
comment|/// @brief Construct a path to the system library directory
specifier|static
name|void
name|GetSystemLibraryPaths
argument_list|(
name|std
operator|::
name|vector
operator|<
name|sys
operator|::
name|Path
operator|>
operator|&
name|Paths
argument_list|)
decl_stmt|;
comment|/// Construct a vector of sys::Path that contains the "standard" bitcode
comment|/// library paths suitable for linking into an llvm program. This function
comment|/// *must* return the value of LLVM_LIB_SEARCH_PATH as well as the value
comment|/// of LLVM_LIBDIR. It also must provide the System library paths as
comment|/// returned by GetSystemLibraryPaths.
comment|/// @see GetSystemLibraryPaths
comment|/// @brief Construct a list of directories in which bitcode could be
comment|/// found.
specifier|static
name|void
name|GetBitcodeLibraryPaths
argument_list|(
name|std
operator|::
name|vector
operator|<
name|sys
operator|::
name|Path
operator|>
operator|&
name|Paths
argument_list|)
decl_stmt|;
comment|/// Find the path to a library using its short name. Use the system
comment|/// dependent library paths to locate the library.
comment|/// @brief Find a library.
specifier|static
name|Path
name|FindLibrary
argument_list|(
name|std
operator|::
name|string
operator|&
name|short_name
argument_list|)
decl_stmt|;
comment|/// Construct a path to the default LLVM configuration directory. The
comment|/// implementation must ensure that this is a well-known (same on many
comment|/// systems) directory in which llvm configuration files exist. For
comment|/// example, on Unix, the /etc/llvm directory has been selected.
comment|/// @brief Construct a path to the default LLVM configuration directory
specifier|static
name|Path
name|GetLLVMDefaultConfigDir
parameter_list|()
function_decl|;
comment|/// Construct a path to the LLVM installed configuration directory. The
comment|/// implementation must ensure that this refers to the "etc" directory of
comment|/// the LLVM installation. This is the location where configuration files
comment|/// will be located for a particular installation of LLVM on a machine.
comment|/// @brief Construct a path to the LLVM installed configuration directory
specifier|static
name|Path
name|GetLLVMConfigDir
parameter_list|()
function_decl|;
comment|/// Construct a path to the current user's home directory. The
comment|/// implementation must use an operating system specific mechanism for
comment|/// determining the user's home directory. For example, the environment
comment|/// variable "HOME" could be used on Unix. If a given operating system
comment|/// does not have the concept of a user's home directory, this static
comment|/// constructor must provide the same result as GetRootDirectory.
comment|/// @brief Construct a path to the current user's "home" directory
specifier|static
name|Path
name|GetUserHomeDirectory
parameter_list|()
function_decl|;
comment|/// Construct a path to the current directory for the current process.
comment|/// @returns The current working directory.
comment|/// @brief Returns the current working directory.
specifier|static
name|Path
name|GetCurrentDirectory
parameter_list|()
function_decl|;
comment|/// Return the suffix commonly used on file names that contain a shared
comment|/// object, shared archive, or dynamic link library. Such files are
comment|/// linked at runtime into a process and their code images are shared
comment|/// between processes.
comment|/// @returns The dynamic link library suffix for the current platform.
comment|/// @brief Return the dynamic link library suffix.
specifier|static
name|StringRef
name|GetDLLSuffix
parameter_list|()
function_decl|;
comment|/// GetMainExecutable - Return the path to the main executable, given the
comment|/// value of argv[0] from program startup and the address of main itself.
specifier|static
name|Path
name|GetMainExecutable
parameter_list|(
specifier|const
name|char
modifier|*
name|argv0
parameter_list|,
name|void
modifier|*
name|MainAddr
parameter_list|)
function_decl|;
comment|/// This is one of the very few ways in which a path can be constructed
comment|/// with a syntactically invalid name. The only *legal* invalid name is an
comment|/// empty one. Other invalid names are not permitted. Empty paths are
comment|/// provided so that they can be used to indicate null or error results in
comment|/// other lib/System functionality.
comment|/// @brief Construct an empty (and invalid) path.
name|Path
argument_list|()
operator|:
name|path
argument_list|()
block|{}
name|Path
argument_list|(
specifier|const
name|Path
operator|&
name|that
argument_list|)
operator|:
name|path
argument_list|(
argument|that.path
argument_list|)
block|{}
comment|/// This constructor will accept a char* or std::string as a path. No
comment|/// checking is done on this path to determine if it is valid. To
comment|/// determine validity of the path, use the isValid method.
comment|/// @param p The path to assign.
comment|/// @brief Construct a Path from a string.
name|explicit
name|Path
argument_list|(
argument|StringRef p
argument_list|)
expr_stmt|;
comment|/// This constructor will accept a character range as a path.  No checking
comment|/// is done on this path to determine if it is valid.  To determine
comment|/// validity of the path, use the isValid method.
comment|/// @param StrStart A pointer to the first character of the path name
comment|/// @param StrLen The length of the path name at StrStart
comment|/// @brief Construct a Path from a string.
name|Path
argument_list|(
argument|const char *StrStart
argument_list|,
argument|unsigned StrLen
argument_list|)
empty_stmt|;
comment|/// @}
comment|/// @name Operators
comment|/// @{
name|public
label|:
comment|/// Makes a copy of \p that to \p this.
comment|/// @returns \p this
comment|/// @brief Assignment Operator
name|Path
modifier|&
name|operator
init|=
operator|(
specifier|const
name|Path
operator|&
name|that
operator|)
block|{
name|path
operator|=
name|that
operator|.
name|path
block|;
return|return
operator|*
name|this
return|;
block|}
comment|/// Makes a copy of \p that to \p this.
comment|/// @param \p that A StringRef denoting the path
comment|/// @returns \p this
comment|/// @brief Assignment Operator
name|Path
modifier|&
name|operator
init|=
operator|(
name|StringRef
name|that
operator|)
decl_stmt|;
comment|/// Compares \p this Path with \p that Path for equality.
comment|/// @returns true if \p this and \p that refer to the same thing.
comment|/// @brief Equality Operator
name|bool
name|operator
operator|==
operator|(
specifier|const
name|Path
operator|&
name|that
operator|)
specifier|const
expr_stmt|;
comment|/// Compares \p this Path with \p that Path for inequality.
comment|/// @returns true if \p this and \p that refer to different things.
comment|/// @brief Inequality Operator
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|Path
operator|&
name|that
operator|)
specifier|const
block|{
return|return
operator|!
operator|(
operator|*
name|this
operator|==
name|that
operator|)
return|;
block|}
comment|/// Determines if \p this Path is less than \p that Path. This is required
comment|/// so that Path objects can be placed into ordered collections (e.g.
comment|/// std::map). The comparison is done lexicographically as defined by
comment|/// the std::string::compare method.
comment|/// @returns true if \p this path is lexicographically less than \p that.
comment|/// @brief Less Than Operator
name|bool
name|operator
operator|<
operator|(
specifier|const
name|Path
operator|&
name|that
operator|)
specifier|const
expr_stmt|;
comment|/// @}
comment|/// @name Path Accessors
comment|/// @{
name|public
label|:
comment|/// This function will use an operating system specific algorithm to
comment|/// determine if the current value of \p this is a syntactically valid
comment|/// path name for the operating system. The path name does not need to
comment|/// exist, validity is simply syntactical. Empty paths are always invalid.
comment|/// @returns true iff the path name is syntactically legal for the
comment|/// host operating system.
comment|/// @brief Determine if a path is syntactically valid or not.
name|bool
name|isValid
argument_list|()
specifier|const
expr_stmt|;
comment|/// This function determines if the contents of the path name are empty.
comment|/// That is, the path name has a zero length. This does NOT determine if
comment|/// if the file is empty. To get the length of the file itself, Use the
comment|/// PathWithStatus::getFileStatus() method and then the getSize() method
comment|/// on the returned FileStatus object.
comment|/// @returns true iff the path is empty.
comment|/// @brief Determines if the path name is empty (invalid).
name|bool
name|isEmpty
argument_list|()
specifier|const
block|{
return|return
name|path
operator|.
name|empty
argument_list|()
return|;
block|}
comment|/// This function returns the last component of the path name. The last
comment|/// component is the file or directory name occuring after the last
comment|/// directory separator. If no directory separator is present, the entire
comment|/// path name is returned (i.e. same as toString).
comment|/// @returns StringRef containing the last component of the path name.
comment|/// @brief Returns the last component of the path name.
name|StringRef
name|getLast
argument_list|()
specifier|const
expr_stmt|;
comment|/// This function strips off the path and suffix of the file or directory
comment|/// name and returns just the basename. For example /a/foo.bar would cause
comment|/// this function to return "foo".
comment|/// @returns StringRef containing the basename of the path
comment|/// @brief Get the base name of the path
name|StringRef
name|getBasename
argument_list|()
specifier|const
expr_stmt|;
comment|/// This function strips off the suffix of the path beginning with the
comment|/// path separator ('/' on Unix, '\' on Windows) and returns the result.
name|StringRef
name|getDirname
argument_list|()
specifier|const
expr_stmt|;
comment|/// This function strips off the path and basename(up to and
comment|/// including the last dot) of the file or directory name and
comment|/// returns just the suffix. For example /a/foo.bar would cause
comment|/// this function to return "bar".
comment|/// @returns StringRef containing the suffix of the path
comment|/// @brief Get the suffix of the path
name|StringRef
name|getSuffix
argument_list|()
specifier|const
expr_stmt|;
comment|/// Obtain a 'C' string for the path name.
comment|/// @returns a 'C' string containing the path name.
comment|/// @brief Returns the path as a C string.
specifier|const
name|char
operator|*
name|c_str
argument_list|()
specifier|const
block|{
return|return
name|path
operator|.
name|c_str
argument_list|()
return|;
block|}
specifier|const
name|std
operator|::
name|string
operator|&
name|str
argument_list|()
specifier|const
block|{
return|return
name|path
return|;
block|}
comment|/// size - Return the length in bytes of this path name.
name|size_t
name|size
argument_list|()
specifier|const
block|{
return|return
name|path
operator|.
name|size
argument_list|()
return|;
block|}
comment|/// empty - Returns true if the path is empty.
name|unsigned
name|empty
argument_list|()
specifier|const
block|{
return|return
name|path
operator|.
name|empty
argument_list|()
return|;
block|}
comment|/// @}
comment|/// @name Disk Accessors
comment|/// @{
name|public
label|:
comment|/// This function determines if the path name in this object references
comment|/// the root (top level directory) of the file system. The details of what
comment|/// is considered the "root" may vary from system to system so this method
comment|/// will do the necessary checking.
comment|/// @returns true iff the path name references the root directory.
comment|/// @brief Determines if the path references the root directory.
name|bool
name|isRootDirectory
argument_list|()
specifier|const
expr_stmt|;
comment|/// This function determines if the path name is absolute, as opposed to
comment|/// relative.
comment|/// @brief Determine if the path is absolute.
name|bool
name|isAbsolute
argument_list|()
specifier|const
expr_stmt|;
comment|/// This function determines if the path name is absolute, as opposed to
comment|/// relative.
comment|/// @brief Determine if the path is absolute.
specifier|static
name|bool
name|isAbsolute
parameter_list|(
specifier|const
name|char
modifier|*
name|NameStart
parameter_list|,
name|unsigned
name|NameLen
parameter_list|)
function_decl|;
comment|/// This function opens the file associated with the path name provided by
comment|/// the Path object and reads its magic number. If the magic number at the
comment|/// start of the file matches \p magic, true is returned. In all other
comment|/// cases (file not found, file not accessible, etc.) it returns false.
comment|/// @returns true if the magic number of the file matches \p magic.
comment|/// @brief Determine if file has a specific magic number
name|bool
name|hasMagicNumber
argument_list|(
name|StringRef
name|magic
argument_list|)
decl|const
decl_stmt|;
comment|/// This function retrieves the first \p len bytes of the file associated
comment|/// with \p this. These bytes are returned as the "magic number" in the
comment|/// \p Magic parameter.
comment|/// @returns true if the Path is a file and the magic number is retrieved,
comment|/// false otherwise.
comment|/// @brief Get the file's magic number.
name|bool
name|getMagicNumber
argument_list|(
name|std
operator|::
name|string
operator|&
name|Magic
argument_list|,
name|unsigned
name|len
argument_list|)
decl|const
decl_stmt|;
comment|/// This function determines if the path name in the object references an
comment|/// archive file by looking at its magic number.
comment|/// @returns true if the file starts with the magic number for an archive
comment|/// file.
comment|/// @brief Determine if the path references an archive file.
name|bool
name|isArchive
argument_list|()
specifier|const
expr_stmt|;
comment|/// This function determines if the path name in the object references an
comment|/// LLVM Bitcode file by looking at its magic number.
comment|/// @returns true if the file starts with the magic number for LLVM
comment|/// bitcode files.
comment|/// @brief Determine if the path references a bitcode file.
name|bool
name|isBitcodeFile
argument_list|()
specifier|const
expr_stmt|;
comment|/// This function determines if the path name in the object references a
comment|/// native Dynamic Library (shared library, shared object) by looking at
comment|/// the file's magic number. The Path object must reference a file, not a
comment|/// directory.
comment|/// @return strue if the file starts with the magid number for a native
comment|/// shared library.
comment|/// @brief Determine if the path reference a dynamic library.
name|bool
name|isDynamicLibrary
argument_list|()
specifier|const
expr_stmt|;
comment|/// This function determines if the path name references an existing file
comment|/// or directory in the file system.
comment|/// @returns true if the pathname references an existing file or
comment|/// directory.
comment|/// @brief Determines if the path is a file or directory in
comment|/// the file system.
name|bool
name|exists
argument_list|()
specifier|const
expr_stmt|;
comment|/// This function determines if the path name refences an
comment|/// existing directory.
comment|/// @returns true if the pathname references an existing directory.
comment|/// @brief Determins if the path is a directory in the file system.
name|bool
name|isDirectory
argument_list|()
specifier|const
expr_stmt|;
comment|/// This function determines if the path name references a readable file
comment|/// or directory in the file system. This function checks for
comment|/// the existence and readability (by the current program) of the file
comment|/// or directory.
comment|/// @returns true if the pathname references a readable file.
comment|/// @brief Determines if the path is a readable file or directory
comment|/// in the file system.
name|bool
name|canRead
argument_list|()
specifier|const
expr_stmt|;
comment|/// This function determines if the path name references a writable file
comment|/// or directory in the file system. This function checks for the
comment|/// existence and writability (by the current program) of the file or
comment|/// directory.
comment|/// @returns true if the pathname references a writable file.
comment|/// @brief Determines if the path is a writable file or directory
comment|/// in the file system.
name|bool
name|canWrite
argument_list|()
specifier|const
expr_stmt|;
comment|/// This function checks that what we're trying to work only on a regular file.
comment|/// Check for things like /dev/null, any block special file,
comment|/// or other things that aren't "regular" regular files.
comment|/// @returns true if the file is S_ISREG.
comment|/// @brief Determines if the file is a regular file
name|bool
name|isRegularFile
argument_list|()
specifier|const
expr_stmt|;
comment|/// This function determines if the path name references an executable
comment|/// file in the file system. This function checks for the existence and
comment|/// executability (by the current program) of the file.
comment|/// @returns true if the pathname references an executable file.
comment|/// @brief Determines if the path is an executable file in the file
comment|/// system.
name|bool
name|canExecute
argument_list|()
specifier|const
expr_stmt|;
comment|/// This function builds a list of paths that are the names of the
comment|/// files and directories in a directory.
comment|/// @returns true if an error occurs, true otherwise
comment|/// @brief Build a list of directory's contents.
name|bool
name|getDirectoryContents
argument_list|(
name|std
operator|::
name|set
operator|<
name|Path
operator|>
operator|&
name|paths
argument_list|,
comment|///< The resulting list of file& directory names
name|std
operator|::
name|string
operator|*
name|ErrMsg
comment|///< Optional place to return an error message.
argument_list|)
decl|const
decl_stmt|;
comment|/// @}
comment|/// @name Path Mutators
comment|/// @{
name|public
label|:
comment|/// The path name is cleared and becomes empty. This is an invalid
comment|/// path name but is the *only* invalid path name. This is provided
comment|/// so that path objects can be used to indicate the lack of a
comment|/// valid path being found.
comment|/// @brief Make the path empty.
name|void
name|clear
parameter_list|()
block|{
name|path
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
comment|/// This method sets the Path object to \p unverified_path. This can fail
comment|/// if the \p unverified_path does not pass the syntactic checks of the
comment|/// isValid() method. If verification fails, the Path object remains
comment|/// unchanged and false is returned. Otherwise true is returned and the
comment|/// Path object takes on the path value of \p unverified_path
comment|/// @returns true if the path was set, false otherwise.
comment|/// @param unverified_path The path to be set in Path object.
comment|/// @brief Set a full path from a StringRef
name|bool
name|set
parameter_list|(
name|StringRef
name|unverified_path
parameter_list|)
function_decl|;
comment|/// One path component is removed from the Path. If only one component is
comment|/// present in the path, the Path object becomes empty. If the Path object
comment|/// is empty, no change is made.
comment|/// @returns false if the path component could not be removed.
comment|/// @brief Removes the last directory component of the Path.
name|bool
name|eraseComponent
parameter_list|()
function_decl|;
comment|/// The \p component is added to the end of the Path if it is a legal
comment|/// name for the operating system. A directory separator will be added if
comment|/// needed.
comment|/// @returns false if the path component could not be added.
comment|/// @brief Appends one path component to the Path.
name|bool
name|appendComponent
parameter_list|(
name|StringRef
name|component
parameter_list|)
function_decl|;
comment|/// A period and the \p suffix are appended to the end of the pathname.
comment|/// The precondition for this function is that the Path reference a file
comment|/// name (i.e. isFile() returns true). If the Path is not a file, no
comment|/// action is taken and the function returns false. If the path would
comment|/// become invalid for the host operating system, false is returned.
comment|/// @returns false if the suffix could not be added, true if it was.
comment|/// @brief Adds a period and the \p suffix to the end of the pathname.
name|bool
name|appendSuffix
parameter_list|(
name|StringRef
name|suffix
parameter_list|)
function_decl|;
comment|/// The suffix of the filename is erased. The suffix begins with and
comment|/// includes the last . character in the filename after the last directory
comment|/// separator and extends until the end of the name. If no . character is
comment|/// after the last directory separator, then the file name is left
comment|/// unchanged (i.e. it was already without a suffix) but the function
comment|/// returns false.
comment|/// @returns false if there was no suffix to remove, true otherwise.
comment|/// @brief Remove the suffix from a path name.
name|bool
name|eraseSuffix
parameter_list|()
function_decl|;
comment|/// The current Path name is made unique in the file system. Upon return,
comment|/// the Path will have been changed to make a unique file in the file
comment|/// system or it will not have been changed if the current path name is
comment|/// already unique.
comment|/// @throws std::string if an unrecoverable error occurs.
comment|/// @brief Make the current path name unique in the file system.
name|bool
name|makeUnique
argument_list|(
name|bool
name|reuse_current
comment|/*= true*/
argument_list|,
name|std
operator|::
name|string
operator|*
name|ErrMsg
argument_list|)
decl_stmt|;
comment|/// The current Path name is made absolute by prepending the
comment|/// current working directory if necessary.
name|void
name|makeAbsolute
parameter_list|()
function_decl|;
comment|/// @}
comment|/// @name Disk Mutators
comment|/// @{
name|public
label|:
comment|/// This method attempts to make the file referenced by the Path object
comment|/// available for reading so that the canRead() method will return true.
comment|/// @brief Make the file readable;
name|bool
name|makeReadableOnDisk
argument_list|(
name|std
operator|::
name|string
operator|*
name|ErrMsg
operator|=
literal|0
argument_list|)
decl_stmt|;
comment|/// This method attempts to make the file referenced by the Path object
comment|/// available for writing so that the canWrite() method will return true.
comment|/// @brief Make the file writable;
name|bool
name|makeWriteableOnDisk
argument_list|(
name|std
operator|::
name|string
operator|*
name|ErrMsg
operator|=
literal|0
argument_list|)
decl_stmt|;
comment|/// This method attempts to make the file referenced by the Path object
comment|/// available for execution so that the canExecute() method will return
comment|/// true.
comment|/// @brief Make the file readable;
name|bool
name|makeExecutableOnDisk
argument_list|(
name|std
operator|::
name|string
operator|*
name|ErrMsg
operator|=
literal|0
argument_list|)
decl_stmt|;
comment|/// This method allows the last modified time stamp and permission bits
comment|/// to be set on the disk object referenced by the Path.
comment|/// @throws std::string if an error occurs.
comment|/// @returns true on error.
comment|/// @brief Set the status information.
name|bool
name|setStatusInfoOnDisk
argument_list|(
specifier|const
name|FileStatus
operator|&
name|SI
argument_list|,
name|std
operator|::
name|string
operator|*
name|ErrStr
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
comment|/// This method attempts to create a directory in the file system with the
comment|/// same name as the Path object. The \p create_parents parameter controls
comment|/// whether intermediate directories are created or not. if \p
comment|/// create_parents is true, then an attempt will be made to create all
comment|/// intermediate directories, as needed. If \p create_parents is false,
comment|/// then only the final directory component of the Path name will be
comment|/// created. The created directory will have no entries.
comment|/// @returns true if the directory could not be created, false otherwise
comment|/// @brief Create the directory this Path refers to.
name|bool
name|createDirectoryOnDisk
argument_list|(
name|bool
name|create_parents
operator|=
name|false
argument_list|,
comment|///<  Determines whether non-existent
comment|///< directory components other than the last one (the "parents")
comment|///< are created or not.
name|std
operator|::
name|string
operator|*
name|ErrMsg
operator|=
literal|0
comment|///< Optional place to put error messages.
argument_list|)
decl_stmt|;
comment|/// This method attempts to create a file in the file system with the same
comment|/// name as the Path object. The intermediate directories must all exist
comment|/// at the time this method is called. Use createDirectoriesOnDisk to
comment|/// accomplish that. The created file will be empty upon return from this
comment|/// function.
comment|/// @returns true if the file could not be created, false otherwise.
comment|/// @brief Create the file this Path refers to.
name|bool
name|createFileOnDisk
argument_list|(
name|std
operator|::
name|string
operator|*
name|ErrMsg
operator|=
literal|0
comment|///< Optional place to put error messages.
argument_list|)
decl_stmt|;
comment|/// This is like createFile except that it creates a temporary file. A
comment|/// unique temporary file name is generated based on the contents of
comment|/// \p this before the call. The new name is assigned to \p this and the
comment|/// file is created.  Note that this will both change the Path object
comment|/// *and* create the corresponding file. This function will ensure that
comment|/// the newly generated temporary file name is unique in the file system.
comment|/// @returns true if the file couldn't be created, false otherwise.
comment|/// @brief Create a unique temporary file
name|bool
name|createTemporaryFileOnDisk
argument_list|(
name|bool
name|reuse_current
operator|=
name|false
argument_list|,
comment|///< When set to true, this parameter
comment|///< indicates that if the current file name does not exist then
comment|///< it will be used without modification.
name|std
operator|::
name|string
operator|*
name|ErrMsg
operator|=
literal|0
comment|///< Optional place to put error messages
argument_list|)
decl_stmt|;
comment|/// This method renames the file referenced by \p this as \p newName. The
comment|/// file referenced by \p this must exist. The file referenced by
comment|/// \p newName does not need to exist.
comment|/// @returns true on error, false otherwise
comment|/// @brief Rename one file as another.
name|bool
name|renamePathOnDisk
argument_list|(
specifier|const
name|Path
operator|&
name|newName
argument_list|,
name|std
operator|::
name|string
operator|*
name|ErrMsg
argument_list|)
decl_stmt|;
comment|/// This method attempts to destroy the file or directory named by the
comment|/// last component of the Path. If the Path refers to a directory and the
comment|/// \p destroy_contents is false, an attempt will be made to remove just
comment|/// the directory (the final Path component). If \p destroy_contents is
comment|/// true, an attempt will be made to remove the entire contents of the
comment|/// directory, recursively. If the Path refers to a file, the
comment|/// \p destroy_contents parameter is ignored.
comment|/// @param destroy_contents Indicates whether the contents of a destroyed
comment|/// @param Err An optional string to receive an error message.
comment|/// directory should also be destroyed (recursively).
comment|/// @returns false if the file/directory was destroyed, true on error.
comment|/// @brief Removes the file or directory from the filesystem.
name|bool
name|eraseFromDisk
argument_list|(
name|bool
name|destroy_contents
operator|=
name|false
argument_list|,
name|std
operator|::
name|string
operator|*
name|Err
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
comment|/// MapInFilePages - This is a low level system API to map in the file
comment|/// that is currently opened as FD into the current processes' address
comment|/// space for read only access.  This function may return null on failure
comment|/// or if the system cannot provide the following constraints:
comment|///  1) The pages must be valid after the FD is closed, until
comment|///     UnMapFilePages is called.
comment|///  2) Any padding after the end of the file must be zero filled, if
comment|///     present.
comment|///  3) The pages must be contiguous.
comment|///
comment|/// This API is not intended for general use, clients should use
comment|/// MemoryBuffer::getFile instead.
specifier|static
specifier|const
name|char
modifier|*
name|MapInFilePages
parameter_list|(
name|int
name|FD
parameter_list|,
name|uint64_t
name|FileSize
parameter_list|)
function_decl|;
comment|/// UnMapFilePages - Free pages mapped into the current process by
comment|/// MapInFilePages.
comment|///
comment|/// This API is not intended for general use, clients should use
comment|/// MemoryBuffer::getFile instead.
specifier|static
name|void
name|UnMapFilePages
parameter_list|(
specifier|const
name|char
modifier|*
name|Base
parameter_list|,
name|uint64_t
name|FileSize
parameter_list|)
function_decl|;
comment|/// @}
comment|/// @name Data
comment|/// @{
name|protected
label|:
comment|// Our win32 implementation relies on this string being mutable.
name|mutable
name|std
operator|::
name|string
name|path
expr_stmt|;
comment|///< Storage for the path name.
comment|/// @}
block|}
empty_stmt|;
comment|/// This class is identical to Path class except it allows you to obtain the
comment|/// file status of the Path as well. The reason for the distinction is one of
comment|/// efficiency. First, the file status requires additional space and the space
comment|/// is incorporated directly into PathWithStatus without an additional malloc.
comment|/// Second, obtaining status information is an expensive operation on most
comment|/// operating systems so we want to be careful and explicity about where we
comment|/// allow this operation in LLVM.
comment|/// @brief Path with file status class.
name|class
name|PathWithStatus
range|:
name|public
name|Path
block|{
comment|/// @name Constructors
comment|/// @{
name|public
operator|:
comment|/// @brief Default constructor
name|PathWithStatus
argument_list|()
operator|:
name|Path
argument_list|()
block|,
name|status
argument_list|()
block|,
name|fsIsValid
argument_list|(
argument|false
argument_list|)
block|{}
comment|/// @brief Copy constructor
name|PathWithStatus
argument_list|(
specifier|const
name|PathWithStatus
operator|&
name|that
argument_list|)
operator|:
name|Path
argument_list|(
name|static_cast
operator|<
specifier|const
name|Path
operator|&
operator|>
operator|(
name|that
operator|)
argument_list|)
block|,
name|status
argument_list|(
name|that
operator|.
name|status
argument_list|)
block|,
name|fsIsValid
argument_list|(
argument|that.fsIsValid
argument_list|)
block|{}
comment|/// This constructor allows construction from a Path object
comment|/// @brief Path constructor
name|PathWithStatus
argument_list|(
specifier|const
name|Path
operator|&
name|other
argument_list|)
operator|:
name|Path
argument_list|(
name|other
argument_list|)
block|,
name|status
argument_list|()
block|,
name|fsIsValid
argument_list|(
argument|false
argument_list|)
block|{}
comment|/// This constructor will accept a char* or std::string as a path. No
comment|/// checking is done on this path to determine if it is valid. To
comment|/// determine validity of the path, use the isValid method.
comment|/// @brief Construct a Path from a string.
name|explicit
name|PathWithStatus
argument_list|(
argument|StringRef p
comment|///< The path to assign.
argument_list|)
operator|:
name|Path
argument_list|(
name|p
argument_list|)
block|,
name|status
argument_list|()
block|,
name|fsIsValid
argument_list|(
argument|false
argument_list|)
block|{}
comment|/// This constructor will accept a character range as a path.  No checking
comment|/// is done on this path to determine if it is valid.  To determine
comment|/// validity of the path, use the isValid method.
comment|/// @brief Construct a Path from a string.
name|explicit
name|PathWithStatus
argument_list|(
argument|const char *StrStart
argument_list|,
comment|///< Pointer to the first character of the path
argument|unsigned StrLen
comment|///< Length of the path.
argument_list|)
operator|:
name|Path
argument_list|(
name|StrStart
argument_list|,
name|StrLen
argument_list|)
block|,
name|status
argument_list|()
block|,
name|fsIsValid
argument_list|(
argument|false
argument_list|)
block|{}
comment|/// Makes a copy of \p that to \p this.
comment|/// @returns \p this
comment|/// @brief Assignment Operator
name|PathWithStatus
operator|&
name|operator
operator|=
operator|(
specifier|const
name|PathWithStatus
operator|&
name|that
operator|)
block|{
name|static_cast
operator|<
name|Path
operator|&
operator|>
operator|(
operator|*
name|this
operator|)
operator|=
name|static_cast
operator|<
specifier|const
name|Path
operator|&
operator|>
operator|(
name|that
operator|)
block|;
name|status
operator|=
name|that
operator|.
name|status
block|;
name|fsIsValid
operator|=
name|that
operator|.
name|fsIsValid
block|;
return|return
operator|*
name|this
return|;
block|}
comment|/// Makes a copy of \p that to \p this.
comment|/// @returns \p this
comment|/// @brief Assignment Operator
name|PathWithStatus
operator|&
name|operator
operator|=
operator|(
specifier|const
name|Path
operator|&
name|that
operator|)
block|{
name|static_cast
operator|<
name|Path
operator|&
operator|>
operator|(
operator|*
name|this
operator|)
operator|=
name|static_cast
operator|<
specifier|const
name|Path
operator|&
operator|>
operator|(
name|that
operator|)
block|;
name|fsIsValid
operator|=
name|false
block|;
return|return
operator|*
name|this
return|;
block|}
comment|/// @}
comment|/// @name Methods
comment|/// @{
name|public
operator|:
comment|/// This function returns status information about the file. The type of
comment|/// path (file or directory) is updated to reflect the actual contents
comment|/// of the file system.
comment|/// @returns 0 on failure, with Error explaining why (if non-zero)
comment|/// @returns a pointer to a FileStatus structure on success.
comment|/// @brief Get file status.
specifier|const
name|FileStatus
operator|*
name|getFileStatus
argument_list|(
argument|bool forceUpdate = false
argument_list|,
comment|///< Force an update from the file system
argument|std::string *Error =
literal|0
comment|///< Optional place to return an error msg.
argument_list|)
specifier|const
block|;
comment|/// @}
comment|/// @name Data
comment|/// @{
name|private
operator|:
name|mutable
name|FileStatus
name|status
block|;
comment|///< Status information.
name|mutable
name|bool
name|fsIsValid
block|;
comment|///< Whether we've obtained it or not
comment|/// @}
block|}
decl_stmt|;
comment|/// This enumeration delineates the kinds of files that LLVM knows about.
enum|enum
name|LLVMFileType
block|{
name|Unknown_FileType
init|=
literal|0
block|,
comment|///< Unrecognized file
name|Bitcode_FileType
block|,
comment|///< Bitcode file
name|Archive_FileType
block|,
comment|///< ar style archive file
name|ELF_Relocatable_FileType
block|,
comment|///< ELF Relocatable object file
name|ELF_Executable_FileType
block|,
comment|///< ELF Executable image
name|ELF_SharedObject_FileType
block|,
comment|///< ELF dynamically linked shared lib
name|ELF_Core_FileType
block|,
comment|///< ELF core image
name|Mach_O_Object_FileType
block|,
comment|///< Mach-O Object file
name|Mach_O_Executable_FileType
block|,
comment|///< Mach-O Executable
name|Mach_O_FixedVirtualMemorySharedLib_FileType
block|,
comment|///< Mach-O Shared Lib, FVM
name|Mach_O_Core_FileType
block|,
comment|///< Mach-O Core File
name|Mach_O_PreloadExectuable_FileType
block|,
comment|///< Mach-O Preloaded Executable
name|Mach_O_DynamicallyLinkedSharedLib_FileType
block|,
comment|///< Mach-O dynlinked shared lib
name|Mach_O_DynamicLinker_FileType
block|,
comment|///< The Mach-O dynamic linker
name|Mach_O_Bundle_FileType
block|,
comment|///< Mach-O Bundle file
name|Mach_O_DynamicallyLinkedSharedLibStub_FileType
block|,
comment|///< Mach-O Shared lib stub
name|COFF_FileType
comment|///< COFF object file or lib
block|}
enum|;
comment|/// This utility function allows any memory block to be examined in order
comment|/// to determine its file type.
name|LLVMFileType
name|IdentifyFileType
parameter_list|(
specifier|const
name|char
modifier|*
name|magic
parameter_list|,
name|unsigned
name|length
parameter_list|)
function_decl|;
comment|/// This function can be used to copy the file specified by Src to the
comment|/// file specified by Dest. If an error occurs, Dest is removed.
comment|/// @returns true if an error occurs, false otherwise
comment|/// @brief Copy one file to another.
name|bool
name|CopyFile
argument_list|(
specifier|const
name|Path
operator|&
name|Dest
argument_list|,
specifier|const
name|Path
operator|&
name|Src
argument_list|,
name|std
operator|::
name|string
operator|*
name|ErrMsg
argument_list|)
decl_stmt|;
comment|/// This is the OS-specific path separator: a colon on Unix or a semicolon
comment|/// on Windows.
specifier|extern
specifier|const
name|char
name|PathSeparator
decl_stmt|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

