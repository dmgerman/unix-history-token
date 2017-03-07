begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   EFI Shell protocol as defined in the UEFI Shell 2.0 specification including errata.    (C) Copyright 2014 Hewlett-Packard Development Company, L.P.<BR>   Copyright (c) 2006 - 2016, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__EFI_SHELL_PROTOCOL_H__
end_ifndef

begin_define
define|#
directive|define
name|__EFI_SHELL_PROTOCOL_H__
end_define

begin_include
include|#
directive|include
file|<Guid/FileInfo.h>
end_include

begin_define
define|#
directive|define
name|EFI_SHELL_PROTOCOL_GUID
define|\
value|{ \   0x6302d008, 0x7f9b, 0x4f30, { 0x87, 0xac, 0x60, 0xc9, 0xfe, 0xf5, 0xda, 0x4e } \   }
end_define

begin_typedef
typedef|typedef
name|VOID
modifier|*
name|SHELL_FILE_HANDLE
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
comment|///
comment|/// The operation completed successfully.
comment|///
name|SHELL_SUCCESS
init|=
literal|0
block|,
comment|///
comment|/// The image failed to load.
comment|///
name|SHELL_LOAD_ERROR
init|=
literal|1
block|,
comment|///
comment|/// The parameter was incorrect.
comment|///
name|SHELL_INVALID_PARAMETER
init|=
literal|2
block|,
comment|///
comment|/// The operation is not supported.
comment|///
name|SHELL_UNSUPPORTED
init|=
literal|3
block|,
comment|///
comment|/// The buffer was not the proper size for the request.
comment|///
name|SHELL_BAD_BUFFER_SIZE
init|=
literal|4
block|,
comment|///
comment|/// The buffer was not large enough to hold the requested data.
comment|/// The required buffer size is returned in the appropriate
comment|/// parameter when this error occurs.
comment|///
name|SHELL_BUFFER_TOO_SMALL
init|=
literal|5
block|,
comment|///
comment|/// There is no data pending upon return.
comment|///
name|SHELL_NOT_READY
init|=
literal|6
block|,
comment|///
comment|/// The physical device reported an error while attempting the
comment|/// operation.
comment|///
name|SHELL_DEVICE_ERROR
init|=
literal|7
block|,
comment|///
comment|/// The device cannot be written to.
comment|///
name|SHELL_WRITE_PROTECTED
init|=
literal|8
block|,
comment|///
comment|/// The resource has run out.
comment|///
name|SHELL_OUT_OF_RESOURCES
init|=
literal|9
block|,
comment|///
comment|/// An inconsistency was detected on the file system causing the
comment|/// operation to fail.
comment|///
name|SHELL_VOLUME_CORRUPTED
init|=
literal|10
block|,
comment|///
comment|/// There is no more space on the file system.
comment|///
name|SHELL_VOLUME_FULL
init|=
literal|11
block|,
comment|///
comment|/// The device does not contain any medium to perform the
comment|/// operation.
comment|///
name|SHELL_NO_MEDIA
init|=
literal|12
block|,
comment|///
comment|/// The medium in the device has changed since the last
comment|/// access.
comment|///
name|SHELL_MEDIA_CHANGED
init|=
literal|13
block|,
comment|///
comment|/// The item was not found.
comment|///
name|SHELL_NOT_FOUND
init|=
literal|14
block|,
comment|///
comment|/// Access was denied.
comment|///
name|SHELL_ACCESS_DENIED
init|=
literal|15
block|,
comment|// note the skipping of 16 and 17
comment|///
comment|/// A timeout time expired.
comment|///
name|SHELL_TIMEOUT
init|=
literal|18
block|,
comment|///
comment|/// The protocol has not been started.
comment|///
name|SHELL_NOT_STARTED
init|=
literal|19
block|,
comment|///
comment|/// The protocol has already been started.
comment|///
name|SHELL_ALREADY_STARTED
init|=
literal|20
block|,
comment|///
comment|/// The operation was aborted.
comment|///
name|SHELL_ABORTED
init|=
literal|21
block|,
comment|// note the skipping of 22, 23, and 24
comment|///
comment|/// A function encountered an internal version that was
comment|/// incompatible with a version requested by the caller.
comment|///
name|SHELL_INCOMPATIBLE_VERSION
init|=
literal|25
block|,
comment|///
comment|/// The function was not performed due to a security violation.
comment|///
name|SHELL_SECURITY_VIOLATION
init|=
literal|26
block|,
comment|///
comment|/// The function was performed and resulted in an unequal
comment|/// comparison..
comment|///
name|SHELL_NOT_EQUAL
init|=
literal|27
block|}
name|SHELL_STATUS
typedef|;
end_typedef

begin_comment
comment|// replaced EFI_LIST_ENTRY with LIST_ENTRY for simplicity.
end_comment

begin_comment
comment|// they are identical outside of the name.
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|LIST_ENTRY
name|Link
decl_stmt|;
comment|///< Linked list members.
name|EFI_STATUS
name|Status
decl_stmt|;
comment|///< Status of opening the file.  Valid only if Handle != NULL.
name|CONST
name|CHAR16
modifier|*
name|FullName
decl_stmt|;
comment|///< Fully qualified filename.
name|CONST
name|CHAR16
modifier|*
name|FileName
decl_stmt|;
comment|///< name of this file.
name|SHELL_FILE_HANDLE
name|Handle
decl_stmt|;
comment|///< Handle for interacting with the opened file or NULL if closed.
name|EFI_FILE_INFO
modifier|*
name|Info
decl_stmt|;
comment|///< Pointer to the FileInfo struct for this file or NULL.
block|}
name|EFI_SHELL_FILE_INFO
typedef|;
end_typedef

begin_comment
comment|/**   Returns whether any script files are currently being processed.    @retval TRUE                 There is at least one script file active.   @retval FALSE                No script files are active now.  **/
end_comment

begin_typedef
typedef|typedef
name|BOOLEAN
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SHELL_BATCH_IS_ACTIVE
function_decl|)
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Closes the file handle.    This function closes a specified file handle. All 'dirty' cached file data is   flushed to the device, and the file is closed. In all cases, the handle is   closed.    @param[in] FileHandle         The file handle to be closed.    @retval EFI_SUCCESS           The file closed sucessfully. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SHELL_CLOSE_FILE
function_decl|)
parameter_list|(
name|IN
name|SHELL_FILE_HANDLE
name|FileHandle
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Creates a file or directory by name.    This function creates an empty new file or directory with the specified attributes and   returns the new file's handle. If the file already exists and is read-only, then   EFI_INVALID_PARAMETER will be returned.    If the file already existed, it is truncated and its attributes updated. If the file is   created successfully, the FileHandle is the file's handle, else, the FileHandle is NULL.    If the file name begins with>v, then the file handle which is returned refers to the   shell environment variable with the specified name. If the shell environment variable   already exists and is non-volatile then EFI_INVALID_PARAMETER is returned.    @param[in] FileName           Pointer to NULL-terminated file path.   @param[in] FileAttribs        The new file's attrbiutes.  The different attributes are                                 described in EFI_FILE_PROTOCOL.Open().   @param[out] FileHandle        On return, points to the created file handle or directory's handle.    @retval EFI_SUCCESS           The file was opened.  FileHandle points to the new file's handle.   @retval EFI_INVALID_PARAMETER One of the parameters has an invalid value.   @retval EFI_UNSUPPORTED       The file path could not be opened.   @retval EFI_NOT_FOUND         The specified file could not be found on the device, or could not                                 file the file system on the device.   @retval EFI_NO_MEDIA          The device has no medium.   @retval EFI_MEDIA_CHANGED     The device has a different medium in it or the medium is no                                 longer supported.   @retval EFI_DEVICE_ERROR      The device reported an error or can't get the file path according                                 the DirName.   @retval EFI_VOLUME_CORRUPTED  The file system structures are corrupted.   @retval EFI_WRITE_PROTECTED   An attempt was made to create a file, or open a file for write                                 when the media is write-protected.   @retval EFI_ACCESS_DENIED     The service denied access to the file.   @retval EFI_OUT_OF_RESOURCES  Not enough resources were available to open the file.   @retval EFI_VOLUME_FULL       The volume is full. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SHELL_CREATE_FILE
function_decl|)
parameter_list|(
name|IN
name|CONST
name|CHAR16
modifier|*
name|FileName
parameter_list|,
name|IN
name|UINT64
name|FileAttribs
parameter_list|,
name|OUT
name|SHELL_FILE_HANDLE
modifier|*
name|FileHandle
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Deletes the file specified by the file handle.    This function closes and deletes a file. In all cases, the file handle is closed. If the file   cannot be deleted, the warning code EFI_WARN_DELETE_FAILURE is returned, but the   handle is still closed.    @param[in] FileHandle           The file handle to delete.    @retval EFI_SUCCESS             The file was closed and deleted and the handle was closed.   @retval EFI_WARN_DELETE_FAILURE The handle was closed but the file was not deleted. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SHELL_DELETE_FILE
function_decl|)
parameter_list|(
name|IN
name|SHELL_FILE_HANDLE
name|FileHandle
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Deletes the file specified by the file name.    This function deletes a file.    @param[in] FileName             Points to the NULL-terminated file name.    @retval EFI_SUCCESS             The file was deleted.   @retval EFI_WARN_DELETE_FAILURE The handle was closed but the file was not deleted. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SHELL_DELETE_FILE_BY_NAME
function_decl|)
parameter_list|(
name|IN
name|CONST
name|CHAR16
modifier|*
name|FileName
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Disables the page break output mode. **/
end_comment

begin_typedef
typedef|typedef
name|VOID
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SHELL_DISABLE_PAGE_BREAK
function_decl|)
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Enables the page break output mode. **/
end_comment

begin_typedef
typedef|typedef
name|VOID
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SHELL_ENABLE_PAGE_BREAK
function_decl|)
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Execute the command line.    This function creates a nested instance of the shell and executes the specified   command (CommandLine) with the specified environment (Environment). Upon return,   the status code returned by the specified command is placed in StatusCode.    If Environment is NULL, then the current environment is used and all changes made   by the commands executed will be reflected in the current environment. If the   Environment is non-NULL, then the changes made will be discarded.    The CommandLine is executed from the current working directory on the current   device.    @param[in] ParentImageHandle  A handle of the image that is executing the specified                                 command line.   @param[in] CommandLine        Points to the NULL-terminated UCS-2 encoded string                                 containing the command line. If NULL then the command-                                 line will be empty.   @param[in] Environment        Points to a NULL-terminated array of environment                                 variables with the format 'x=y', where x is the                                 environment variable name and y is the value. If this                                 is NULL, then the current shell environment is used.   @param[out] ErrorCode         Points to the status code returned by the command.    @retval EFI_SUCCESS           The command executed successfully. The  status code                                 returned by the command is pointed to by StatusCode.   @retval EFI_INVALID_PARAMETER The parameters are invalid.   @retval EFI_OUT_OF_RESOURCES  Out of resources.   @retval EFI_UNSUPPORTED       Nested shell invocations are not allowed. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SHELL_EXECUTE
function_decl|)
parameter_list|(
name|IN
name|EFI_HANDLE
modifier|*
name|ParentImageHandle
parameter_list|,
name|IN
name|CHAR16
modifier|*
name|CommandLine
name|OPTIONAL
parameter_list|,
name|IN
name|CHAR16
modifier|*
modifier|*
name|Environment
name|OPTIONAL
parameter_list|,
name|OUT
name|EFI_STATUS
modifier|*
name|StatusCode
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Find files that match a specified pattern.    This function searches for all files and directories that match the specified   FilePattern. The FilePattern can contain wild-card characters. The resulting file   information is placed in the file list FileList.    The files in the file list are not opened. The OpenMode field is set to 0 and the FileInfo   field is set to NULL.    @param[in] FilePattern        Points to a NULL-terminated shell file path, including wildcards.   @param[out] FileList          On return, points to the start of a file list containing the names                                 of all matching files or else points to NULL if no matching files                                 were found.    @retval EFI_SUCCESS           Files found.   @retval EFI_NOT_FOUND         No files found.   @retval EFI_NO_MEDIA          The device has no media.   @retval EFI_DEVICE_ERROR      The device reported an error.   @retval EFI_VOLUME_CORRUPTED  The file system structures are corrupted. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SHELL_FIND_FILES
function_decl|)
parameter_list|(
name|IN
name|CONST
name|CHAR16
modifier|*
name|FilePattern
parameter_list|,
name|OUT
name|EFI_SHELL_FILE_INFO
modifier|*
modifier|*
name|FileList
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Find all files in a specified directory.    @param[in] FileDirHandle      Handle of the directory to search.   @param[out] FileList          On return, points to the list of files in the directory                                 or NULL if there are no files in the directory.    @retval EFI_SUCCESS           File information was returned successfully.   @retval EFI_VOLUME_CORRUPTED  The file system structures have been corrupted.   @retval EFI_DEVICE_ERROR      The device reported an error.   @retval EFI_NO_MEDIA          The device media is not present. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SHELL_FIND_FILES_IN_DIR
function_decl|)
parameter_list|(
name|IN
name|SHELL_FILE_HANDLE
name|FileDirHandle
parameter_list|,
name|OUT
name|EFI_SHELL_FILE_INFO
modifier|*
modifier|*
name|FileList
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Flushes data back to a device.    This function flushes all modified data associated with a file to a device.    @param[in] FileHandle         The handle of the file to flush.    @retval EFI_SUCCESS           The data was flushed.   @retval EFI_NO_MEDIA          The device has no medium.   @retval EFI_DEVICE_ERROR      The device reported an error.   @retval EFI_VOLUME_CORRUPTED  The file system structures are corrupted.   @retval EFI_WRITE_PROTECTED   The file or medium is write-protected.   @retval EFI_ACCESS_DENIED     The file was opened read-only.   @retval EFI_VOLUME_FULL       The volume is full. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SHELL_FLUSH_FILE
function_decl|)
parameter_list|(
name|IN
name|SHELL_FILE_HANDLE
name|FileHandle
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Frees the file list.    This function cleans up the file list and any related data structures. It has no   impact on the files themselves.    @param[in] FileList           The file list to free. Type EFI_SHELL_FILE_INFO is                                 defined in OpenFileList().    @retval EFI_SUCCESS           Free the file list successfully. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SHELL_FREE_FILE_LIST
function_decl|)
parameter_list|(
name|IN
name|EFI_SHELL_FILE_INFO
modifier|*
modifier|*
name|FileList
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Returns the current directory on the specified device.    If FileSystemMapping is NULL, it returns the current working directory. If the   FileSystemMapping is not NULL, it returns the current directory associated with the   FileSystemMapping. In both cases, the returned name includes the file system   mapping (i.e. fs0:\current-dir).    Note that the current directory string should exclude the tailing backslash character.    @param[in] FileSystemMapping  A pointer to the file system mapping. If NULL,                                 then the current working directory is returned.    @retval !=NULL                The current directory.   @retval NULL                  Current directory does not exist. **/
end_comment

begin_typedef
typedef|typedef
name|CONST
name|CHAR16
modifier|*
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SHELL_GET_CUR_DIR
function_decl|)
parameter_list|(
name|IN
name|CONST
name|CHAR16
modifier|*
name|FileSystemMapping
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|UINT32
name|EFI_SHELL_DEVICE_NAME_FLAGS
typedef|;
end_typedef

begin_define
define|#
directive|define
name|EFI_DEVICE_NAME_USE_COMPONENT_NAME
value|0x00000001
end_define

begin_define
define|#
directive|define
name|EFI_DEVICE_NAME_USE_DEVICE_PATH
value|0x00000002
end_define

begin_comment
comment|/**   Gets the name of the device specified by the device handle.    This function gets the user-readable name of the device specified by the device   handle. If no user-readable name could be generated, then *BestDeviceName will be   NULL and EFI_NOT_FOUND will be returned.    If EFI_DEVICE_NAME_USE_COMPONENT_NAME is set, then the function will return the   device's name using the EFI_COMPONENT_NAME2_PROTOCOL, if present on   DeviceHandle.    If EFI_DEVICE_NAME_USE_DEVICE_PATH is set, then the function will return the   device's name using the EFI_DEVICE_PATH_PROTOCOL, if present on DeviceHandle.   If both EFI_DEVICE_NAME_USE_COMPONENT_NAME and   EFI_DEVICE_NAME_USE_DEVICE_PATH are set, then   EFI_DEVICE_NAME_USE_COMPONENT_NAME will have higher priority.    @param[in] DeviceHandle       The handle of the device.   @param[in] Flags              Determines the possible sources of component names.   @param[in] Language           A pointer to the language specified for the device                                 name, in the same format as described in the UEFI                                 specification, Appendix M.   @param[out] BestDeviceName    On return, points to the callee-allocated NULL-                                 terminated name of the device. If no device name                                 could be found, points to NULL. The name must be                                 freed by the caller...    @retval EFI_SUCCESS           Get the name successfully.   @retval EFI_NOT_FOUND         Fail to get the device name. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SHELL_GET_DEVICE_NAME
function_decl|)
parameter_list|(
name|IN
name|EFI_HANDLE
name|DeviceHandle
parameter_list|,
name|IN
name|EFI_SHELL_DEVICE_NAME_FLAGS
name|Flags
parameter_list|,
name|IN
name|CHAR8
modifier|*
name|Language
parameter_list|,
name|OUT
name|CHAR16
modifier|*
modifier|*
name|BestDeviceName
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Gets the device path from the mapping.    This function gets the device path associated with a mapping.    @param[in] Mapping                A pointer to the mapping    @retval !=NULL                Pointer to the device path that corresponds to the                                 device mapping. The returned pointer does not need                                 to be freed.   @retval NULL                  There is no device path associated with the                                 specified mapping. **/
end_comment

begin_typedef
typedef|typedef
name|CONST
name|EFI_DEVICE_PATH_PROTOCOL
modifier|*
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SHELL_GET_DEVICE_PATH_FROM_MAP
function_decl|)
parameter_list|(
name|IN
name|CONST
name|CHAR16
modifier|*
name|Mapping
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Converts a file system style name to a device path.    This function converts a file system style name to a device path, by replacing any   mapping references to the associated device path.    @param[in] Path               The pointer to the path.    @return                       The pointer of the file path. The file path is callee                                 allocated and should be freed by the caller. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_DEVICE_PATH_PROTOCOL
modifier|*
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SHELL_GET_DEVICE_PATH_FROM_FILE_PATH
function_decl|)
parameter_list|(
name|IN
name|CONST
name|CHAR16
modifier|*
name|Path
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Gets either a single or list of environment variables.    If name is not NULL then this function returns the current value of the specified   environment variable.    If Name is NULL than a list of all environment variable names is returned.  Each a   NULL terminated string with a double NULL terminating the list.    @param[in] Name               A pointer to the environment variable name.  If                                 Name is NULL, then the function will return all                                 of the defined shell environment variables.  In                                 the case where multiple environment variables are                                 being returned, each variable will be terminated by                                 a NULL, and the list will be terminated by a double                                 NULL.    @return                       A pointer to the returned string.                                 The returned pointer does not need to be freed by the caller.    @retval NULL                  The environment variable doesn't exist or there are                                 no environment variables. **/
end_comment

begin_typedef
typedef|typedef
name|CONST
name|CHAR16
modifier|*
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SHELL_GET_ENV
function_decl|)
parameter_list|(
name|IN
name|CONST
name|CHAR16
modifier|*
name|Name
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Gets the environment variable and Attributes, or list of environment variables.  Can be    used instead of GetEnv().    This function returns the current value of the specified environment variable and   the Attributes. If no variable name was specified, then all of the known   variables will be returned.    @param[in] Name               A pointer to the environment variable name. If Name is NULL,                                 then the function will return all of the defined shell                                  environment variables. In the case where multiple environment                                 variables are being returned, each variable will be terminated                                  by a NULL, and the list will be terminated by a double NULL.   @param[out] Attributes        If not NULL, a pointer to the returned attributes bitmask for                                 the environment variable. In the case where Name is NULL, and                                 multiple environment variables are being returned, Attributes                                 is undefined.    @retval NULL                  The environment variable doesn't exist.     @return                       The environment variable's value. The returned pointer does not                                  need to be freed by the caller.   **/
end_comment

begin_typedef
typedef|typedef
name|CONST
name|CHAR16
modifier|*
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SHELL_GET_ENV_EX
function_decl|)
parameter_list|(
name|IN
name|CONST
name|CHAR16
modifier|*
name|Name
parameter_list|,
name|OUT
name|UINT32
modifier|*
name|Attributes
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Gets the file information from an open file handle.    This function allocates a buffer to store the file's information. It's the caller's   responsibility to free the buffer.    @param[in] FileHandle         A File Handle.    @retval NULL                  Cannot get the file info.   @return                       A pointer to a buffer with file information. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_FILE_INFO
modifier|*
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SHELL_GET_FILE_INFO
function_decl|)
parameter_list|(
name|IN
name|SHELL_FILE_HANDLE
name|FileHandle
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Converts a device path to a file system-style path.    This function converts a device path to a file system path by replacing part, or all, of   the device path with the file-system mapping. If there are more than one application   file system mappings, the one that most closely matches Path will be used.    @param[in] Path               The pointer to the device path.    @return                       The pointer of the NULL-terminated file path. The path                                 is callee-allocated and should be freed by the caller. **/
end_comment

begin_typedef
typedef|typedef
name|CHAR16
modifier|*
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SHELL_GET_FILE_PATH_FROM_DEVICE_PATH
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_DEVICE_PATH_PROTOCOL
modifier|*
name|Path
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Gets a file's current position.    This function returns the current file position for the file handle. For directories, the   current file position has no meaning outside of the file system driver and as such, the   operation is not supported.    @param[in] FileHandle         The file handle on which to get the current position.   @param[out] Position          Byte position from the start of the file.    @retval EFI_SUCCESS           Data was accessed.   @retval EFI_UNSUPPORTED       The request is not valid on open directories. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SHELL_GET_FILE_POSITION
function_decl|)
parameter_list|(
name|IN
name|SHELL_FILE_HANDLE
name|FileHandle
parameter_list|,
name|OUT
name|UINT64
modifier|*
name|Position
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Gets the size of a file.    This function returns the size of the file specified by FileHandle.    @param[in] FileHandle         The handle of the file.   @param[out] Size              The size of this file.    @retval EFI_SUCCESS           Get the file's size.   @retval EFI_DEVICE_ERROR      Can't access the file. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SHELL_GET_FILE_SIZE
function_decl|)
parameter_list|(
name|IN
name|SHELL_FILE_HANDLE
name|FileHandle
parameter_list|,
name|OUT
name|UINT64
modifier|*
name|Size
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Get the GUID value from a human readable name.    If GuidName is a known GUID name, then update Guid to have the correct value for   that GUID.    This function is only available when the major and minor versions in the   EfiShellProtocol are greater than or equal to 2 and 1, respectively.    @param[in]  GuidName   A pointer to the localized name for the GUID being queried.   @param[out] Guid       A pointer to the GUID structure to be filled in.    @retval EFI_SUCCESS             The operation was successful.   @retval EFI_INVALID_PARAMETER   Guid was NULL.   @retval EFI_INVALID_PARAMETER   GuidName was NULL.   @retval EFI_NOT_FOUND           GuidName is not a known GUID Name. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SHELL_GET_GUID_FROM_NAME
function_decl|)
parameter_list|(
name|IN
name|CONST
name|CHAR16
modifier|*
name|GuidName
parameter_list|,
name|OUT
name|EFI_GUID
modifier|*
name|Guid
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Get the human readable name for a GUID from the value.    If Guid is assigned a name, then update *GuidName to point to the name. The callee   should not modify the value.    This function is only available when the major and minor versions in the   EfiShellProtocol are greater than or equal to 2 and 1, respectively.    @param[in]  Guid       A pointer to the GUID being queried.   @param[out] GuidName   A pointer to a pointer the localized to name for the GUID being requested    @retval EFI_SUCCESS             The operation was successful.   @retval EFI_INVALID_PARAMETER   Guid was NULL.   @retval EFI_INVALID_PARAMETER   GuidName was NULL.   @retval EFI_NOT_FOUND           Guid is not assigned a name. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SHELL_GET_GUID_NAME
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_GUID
modifier|*
name|Guid
parameter_list|,
name|OUT
name|CONST
name|CHAR16
modifier|*
modifier|*
name|GuidName
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Return help information about a specific command.    This function returns the help information for the specified command. The help text   can be internal to the shell or can be from a UEFI Shell manual page.    If Sections is specified, then each section name listed will be compared in a casesensitive   manner, to the section names described in Appendix B. If the section exists,   it will be appended to the returned help text. If the section does not exist, no   information will be returned. If Sections is NULL, then all help text information   available will be returned.    @param[in] Command            Points to the NULL-terminated UEFI Shell command name.   @param[in] Sections           Points to the NULL-terminated comma-delimited                                 section names to return. If NULL, then all                                 sections will be returned.   @param[out] HelpText          On return, points to a callee-allocated buffer                                 containing all specified help text.    @retval EFI_SUCCESS           The help text was returned.   @retval EFI_OUT_OF_RESOURCES  The necessary buffer could not be allocated to hold the                                 returned help text.   @retval EFI_INVALID_PARAMETER HelpText is NULL.   @retval EFI_NOT_FOUND         There is no help text available for Command. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SHELL_GET_HELP_TEXT
function_decl|)
parameter_list|(
name|IN
name|CONST
name|CHAR16
modifier|*
name|Command
parameter_list|,
name|IN
name|CONST
name|CHAR16
modifier|*
name|Sections
name|OPTIONAL
parameter_list|,
name|OUT
name|CHAR16
modifier|*
modifier|*
name|HelpText
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Gets the mapping(s) that most closely matches the device path.    This function gets the mapping which corresponds to the device path *DevicePath. If   there is no exact match, then the mapping which most closely matches *DevicePath   is returned, and *DevicePath is updated to point to the remaining portion of the   device path. If there is an exact match, the mapping is returned and *DevicePath   points to the end-of-device-path node.    If there are multiple map names they will be semi-colon seperated in the   NULL-terminated string.    @param[in, out] DevicePath     On entry, points to a device path pointer. On                                  exit, updates the pointer to point to the                                  portion of the device path after the mapping.    @retval NULL                  No mapping was found.   @retval !=NULL                Pointer to NULL-terminated mapping. The buffer                                 is callee allocated and should be freed by the caller. **/
end_comment

begin_typedef
typedef|typedef
name|CONST
name|CHAR16
modifier|*
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SHELL_GET_MAP_FROM_DEVICE_PATH
function_decl|)
parameter_list|(
name|IN
name|OUT
name|EFI_DEVICE_PATH_PROTOCOL
modifier|*
modifier|*
name|DevicePath
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Gets the enable status of the page break output mode.    User can use this function to determine current page break mode.    @retval TRUE                  The page break output mode is enabled.   @retval FALSE                 The page break output mode is disabled. **/
end_comment

begin_typedef
typedef|typedef
name|BOOLEAN
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SHELL_GET_PAGE_BREAK
function_decl|)
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Judges whether the active shell is the root shell.    This function makes the user to know that whether the active Shell is the root shell.    @retval TRUE                  The active Shell is the root Shell.   @retval FALSE                 The active Shell is NOT the root Shell. **/
end_comment

begin_typedef
typedef|typedef
name|BOOLEAN
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SHELL_IS_ROOT_SHELL
function_decl|)
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Opens a file or a directory by file name.    This function opens the specified file in the specified OpenMode and returns a file   handle.   If the file name begins with '>v', then the file handle which is returned refers to the   shell environment variable with the specified name. If the shell environment variable   exists, is non-volatile and the OpenMode indicates EFI_FILE_MODE_WRITE, then   EFI_INVALID_PARAMETER is returned.    If the file name is '>i', then the file handle which is returned refers to the standard   input. If the OpenMode indicates EFI_FILE_MODE_WRITE, then EFI_INVALID_PARAMETER   is returned.    If the file name is '>o', then the file handle which is returned refers to the standard   output. If the OpenMode indicates EFI_FILE_MODE_READ, then EFI_INVALID_PARAMETER   is returned.    If the file name is '>e', then the file handle which is returned refers to the standard   error. If the OpenMode indicates EFI_FILE_MODE_READ, then EFI_INVALID_PARAMETER   is returned.    If the file name is 'NUL', then the file handle that is returned refers to the standard NUL   file. If the OpenMode indicates EFI_FILE_MODE_READ, then EFI_INVALID_PARAMETER is   returned.    If return EFI_SUCCESS, the FileHandle is the opened file's handle, else, the   FileHandle is NULL.    @param[in] FileName           Points to the NULL-terminated UCS-2 encoded file name.   @param[out] FileHandle        On return, points to the file handle.   @param[in] OpenMode           File open mode. Either EFI_FILE_MODE_READ or                                 EFI_FILE_MODE_WRITE from section 12.4 of the UEFI                                 Specification.   @retval EFI_SUCCESS           The file was opened. FileHandle has the opened file's handle.   @retval EFI_INVALID_PARAMETER One of the parameters has an invalid value. FileHandle is NULL.   @retval EFI_UNSUPPORTED       Could not open the file path. FileHandle is NULL.   @retval EFI_NOT_FOUND         The specified file could not be found on the device or the file                                 system could not be found on the device. FileHandle is NULL.   @retval EFI_NO_MEDIA          The device has no medium. FileHandle is NULL.   @retval EFI_MEDIA_CHANGED     The device has a different medium in it or the medium is no                                 longer supported. FileHandle is NULL.   @retval EFI_DEVICE_ERROR      The device reported an error or can't get the file path according                                 the FileName. FileHandle is NULL.   @retval EFI_VOLUME_CORRUPTED  The file system structures are corrupted. FileHandle is NULL.   @retval EFI_WRITE_PROTECTED   An attempt was made to create a file, or open a file for write                                 when the media is write-protected. FileHandle is NULL.   @retval EFI_ACCESS_DENIED     The service denied access to the file. FileHandle is NULL.   @retval EFI_OUT_OF_RESOURCES  Not enough resources were available to open the file. FileHandle                                 is NULL.   @retval EFI_VOLUME_FULL       The volume is full. FileHandle is NULL. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SHELL_OPEN_FILE_BY_NAME
function_decl|)
parameter_list|(
name|IN
name|CONST
name|CHAR16
modifier|*
name|FileName
parameter_list|,
name|OUT
name|SHELL_FILE_HANDLE
modifier|*
name|FileHandle
parameter_list|,
name|IN
name|UINT64
name|OpenMode
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Opens the files that match the path specified.    This function opens all of the files specified by Path. Wildcards are processed   according to the rules specified in UEFI Shell 2.0 spec section 3.7.1. Each   matching file has an EFI_SHELL_FILE_INFO structure created in a linked list.    @param[in] Path                A pointer to the path string.   @param[in] OpenMode            Specifies the mode used to open each file, EFI_FILE_MODE_READ or                                  EFI_FILE_MODE_WRITE.   @param[in, out] FileList       Points to the start of a list of files opened.    @retval EFI_SUCCESS           Create the file list successfully.   @return                       Can't create the file list. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SHELL_OPEN_FILE_LIST
function_decl|)
parameter_list|(
name|IN
name|CHAR16
modifier|*
name|Path
parameter_list|,
name|IN
name|UINT64
name|OpenMode
parameter_list|,
name|IN
name|OUT
name|EFI_SHELL_FILE_INFO
modifier|*
modifier|*
name|FileList
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Opens the root directory of a device.    This function opens the root directory of a device and returns a file handle to it.    @param[in] DevicePath         Points to the device path corresponding to the device where the                                 EFI_SIMPLE_FILE_SYSTEM_PROTOCOL is installed.   @param[out] FileHandle        On exit, points to the file handle corresponding to the root directory on the                                 device.    @retval EFI_SUCCESS           Root opened successfully.   @retval EFI_NOT_FOUND         EFI_SIMPLE_FILE_SYSTEM could not be found or the root directory                                 could not be opened.   @retval EFI_VOLUME_CORRUPTED  The data structures in the volume were corrupted.   @retval EFI_DEVICE_ERROR      The device had an error. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SHELL_OPEN_ROOT
function_decl|)
parameter_list|(
name|IN
name|EFI_DEVICE_PATH_PROTOCOL
modifier|*
name|DevicePath
parameter_list|,
name|OUT
name|SHELL_FILE_HANDLE
modifier|*
name|FileHandle
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Opens the root directory of a device on a handle.    This function opens the root directory of a device and returns a file handle to it.    @param[in] DeviceHandle       The handle of the device that contains the volume.   @param[out] FileHandle        On exit, points to the file handle corresponding to the root directory on the                                 device.    @retval EFI_SUCCESS           Root opened successfully.   @retval EFI_NOT_FOUND         EFI_SIMPLE_FILE_SYSTEM could not be found or the root directory                                 could not be opened.   @retval EFI_VOLUME_CORRUPTED  The data structures in the volume were corrupted.   @retval EFI_DEVICE_ERROR      The device had an error. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SHELL_OPEN_ROOT_BY_HANDLE
function_decl|)
parameter_list|(
name|IN
name|EFI_HANDLE
name|DeviceHandle
parameter_list|,
name|OUT
name|SHELL_FILE_HANDLE
modifier|*
name|FileHandle
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Reads data from the file.    If FileHandle is not a directory, the function reads the requested number of bytes   from the file at the file's current position and returns them in Buffer. If the read goes   beyond the end of the file, the read length is truncated to the end of the file. The file's   current position is increased by the number of bytes returned.   If FileHandle is a directory, then an error is returned.    @param[in] FileHandle          The opened file handle for read.   @param[in] ReadSize            On input, the size of Buffer, in bytes. On output, the amount of data read.   @param[in, out] Buffer         The buffer in which data is read.    @retval EFI_SUCCESS           Data was read.   @retval EFI_NO_MEDIA          The device has no media.   @retval EFI_DEVICE_ERROR      The device reported an error.   @retval EFI_VOLUME_CORRUPTED  The file system structures are corrupted.   @retval EFI_BUFFER_TO_SMALL   Buffer is too small. ReadSize contains required size. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SHELL_READ_FILE
function_decl|)
parameter_list|(
name|IN
name|SHELL_FILE_HANDLE
name|FileHandle
parameter_list|,
name|IN
name|OUT
name|UINTN
modifier|*
name|ReadSize
parameter_list|,
name|IN
name|OUT
name|VOID
modifier|*
name|Buffer
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Register a GUID and a localized human readable name for it.    If Guid is not assigned a name, then assign GuidName to Guid.  This list of GUID   names must be used whenever a shell command outputs GUID information.    This function is only available when the major and minor versions in the   EfiShellProtocol are greater than or equal to 2 and 1, respectively.    @param[in] Guid       A pointer to the GUID being registered.   @param[in] GuidName   A pointer to the localized name for the GUID being registered.    @retval EFI_SUCCESS             The operation was successful.   @retval EFI_INVALID_PARAMETER   Guid was NULL.   @retval EFI_INVALID_PARAMETER   GuidName was NULL.   @retval EFI_ACCESS_DENIED       Guid already is assigned a name. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SHELL_REGISTER_GUID_NAME
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_GUID
modifier|*
name|Guid
parameter_list|,
name|IN
name|CONST
name|CHAR16
modifier|*
name|GuidName
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Deletes the duplicate file names files in the given file list.    @param[in] FileList           A pointer to the first entry in the file list.    @retval EFI_SUCCESS           Always success. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SHELL_REMOVE_DUP_IN_FILE_LIST
function_decl|)
parameter_list|(
name|IN
name|EFI_SHELL_FILE_INFO
modifier|*
modifier|*
name|FileList
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Changes a shell command alias.    This function creates an alias for a shell command.    @param[in] Command            Points to the NULL-terminated shell command or existing alias.   @param[in] Alias              Points to the NULL-terminated alias for the shell command. If this is NULL, and                                 Command refers to an alias, that alias will be deleted.   @param[in] Replace            If TRUE and the alias already exists, then the existing alias will be replaced. If                                 FALSE and the alias already exists, then the existing alias is unchanged and                                 EFI_ACCESS_DENIED is returned.   @param[in] Volatile           if TRUE the Alias being set will be stored in a volatile fashion.  if FALSE the                                 Alias being set will be stored in a non-volatile fashion.    @retval EFI_SUCCESS           Alias created or deleted successfully.   @retval EFI_ACCESS_DENIED     The alias is a built-in alias or already existed and Replace was set to                                 FALSE. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SHELL_SET_ALIAS
function_decl|)
parameter_list|(
name|IN
name|CONST
name|CHAR16
modifier|*
name|Command
parameter_list|,
name|IN
name|CONST
name|CHAR16
modifier|*
name|Alias
parameter_list|,
name|IN
name|BOOLEAN
name|Replace
parameter_list|,
name|IN
name|BOOLEAN
name|Volatile
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   This function returns the command associated with a alias or a list of all   alias'.    @param[in] Alias              Points to the NULL-terminated shell alias.                                 If this parameter is NULL, then all                                 aliases will be returned in ReturnedData.   @param[out] Volatile          Upon return of a single command if TRUE indicates                                 this is stored in a volatile fashion.  FALSE otherwise.   @return                      	If Alias is not NULL, it will return a pointer to                                 the NULL-terminated command for that alias.                                 If Alias is NULL, ReturnedData points to a ';'                                 delimited list of alias (e.g.                                 ReturnedData = "dir;del;copy;mfp") that is NULL-terminated.   @retval NULL                  An error ocurred.   @retval NULL                  Alias was not a valid Alias. **/
end_comment

begin_typedef
typedef|typedef
name|CONST
name|CHAR16
modifier|*
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SHELL_GET_ALIAS
function_decl|)
parameter_list|(
name|IN
name|CONST
name|CHAR16
modifier|*
name|Alias
parameter_list|,
name|OUT
name|BOOLEAN
modifier|*
name|Volatile
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Changes the current directory on the specified device.    If the FileSystem is NULL, and the directory Dir does not contain a file system's   mapped name, this function changes the current working directory. If FileSystem is   NULL and the directory Dir contains a mapped name, then the current file system and   the current directory on that file system are changed.    If FileSystem is not NULL, and Dir is NULL, then this changes the current working file   system.    If FileSystem is not NULL and Dir is not NULL, then this function changes the current   directory on the specified file system.    If the current working directory or the current working file system is changed then the   %cwd% environment variable will be updated.    @param[in] FileSystem         A pointer to the file system's mapped name. If NULL, then the current working                                 directory is changed.   @param[in] Dir                Points to the NULL-terminated directory on the device specified by FileSystem.    @retval NULL                  Current directory does not exist.   @return                       The current directory. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SHELL_SET_CUR_DIR
function_decl|)
parameter_list|(
name|IN
name|CONST
name|CHAR16
modifier|*
name|FileSystem
name|OPTIONAL
parameter_list|,
name|IN
name|CONST
name|CHAR16
modifier|*
name|Dir
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Sets the environment variable.    This function changes the current value of the specified environment variable. If the   environment variable exists and the Value is an empty string, then the environment   variable is deleted. If the environment variable exists and the Value is not an empty   string, then the value of the environment variable is changed. If the environment   variable does not exist and the Value is an empty string, there is no action. If the   environment variable does not exist and the Value is a non-empty string, then the   environment variable is created and assigned the specified value.    For a description of volatile and non-volatile environment variables, see UEFI Shell   2.0 specification section 3.6.1.    @param[in] Name               Points to the NULL-terminated environment variable name.   @param[in] Value              Points to the NULL-terminated environment variable value. If the value is an                                 empty string then the environment variable is deleted.   @param[in] Volatile           Indicates whether the variable is non-volatile (FALSE) or volatile (TRUE).    @retval EFI_SUCCESS           The environment variable was successfully updated. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SHELL_SET_ENV
function_decl|)
parameter_list|(
name|IN
name|CONST
name|CHAR16
modifier|*
name|Name
parameter_list|,
name|IN
name|CONST
name|CHAR16
modifier|*
name|Value
parameter_list|,
name|IN
name|BOOLEAN
name|Volatile
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Sets the file information to an opened file handle.    This function changes file information.  All file information in the EFI_FILE_INFO   struct will be updated to the passed in data.    @param[in] FileHandle         A file handle.   @param[in] FileInfo           Points to new file information.    @retval EFI_SUCCESS           The information was set.   @retval EFI_NO_MEDIA          The device has no medium.   @retval EFI_DEVICE_ERROR      The device reported an error.   @retval EFI_VOLUME_CORRUPTED  The file system structures are corrupted.   @retval EFI_WRITE_PROTECTED   The file or medium is write-protected.   @retval EFI_ACCESS_DENIED     The file was opened read-only.   @retval EFI_VOLUME_FULL       The volume is full.   @retval EFI_BAD_BUFFER_SIZE   BufferSize is smaller than the size of EFI_FILE_INFO. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SHELL_SET_FILE_INFO
function_decl|)
parameter_list|(
name|IN
name|SHELL_FILE_HANDLE
name|FileHandle
parameter_list|,
name|IN
name|CONST
name|EFI_FILE_INFO
modifier|*
name|FileInfo
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Sets a file's current position.    This function sets the current file position for the handle to the position supplied. With   the exception of seeking to position 0xFFFFFFFFFFFFFFFF, only absolute positioning is   supported, and seeking past the end of the file is allowed (a subsequent write would   grow the file). Seeking to position 0xFFFFFFFFFFFFFFFF causes the current position   to be set to the end of the file.    @param[in] FileHandle         The file handle on which requested position will be set.   @param[in] Position           Byte position from the start of the file.    @retval EFI_SUCCESS           Data was written.   @retval EFI_UNSUPPORTED       The seek request for nonzero is not valid on open directories. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SHELL_SET_FILE_POSITION
function_decl|)
parameter_list|(
name|IN
name|SHELL_FILE_HANDLE
name|FileHandle
parameter_list|,
name|IN
name|UINT64
name|Position
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   This function creates a mapping for a device path.    @param[in] DevicePath         Points to the device path. If this is NULL and Mapping points to a valid mapping,                                 then the mapping will be deleted.   @param[in] Mapping            Points to the NULL-terminated mapping for the device path.    @retval EFI_SUCCESS           Mapping created or deleted successfully.   @retval EFI_NO_MAPPING        There is no handle that corresponds exactly to DevicePath. See the                                 boot service function LocateDevicePath().   @retval EFI_ACCESS_DENIED     The mapping is a built-in alias. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SHELL_SET_MAP
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_DEVICE_PATH_PROTOCOL
modifier|*
name|DevicePath
parameter_list|,
name|IN
name|CONST
name|CHAR16
modifier|*
name|Mapping
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Writes data to the file.    This function writes the specified number of bytes to the file at the current file position.   The current file position is advanced the actual number of bytes written, which is   returned in BufferSize. Partial writes only occur when there has been a data error   during the write attempt (such as "volume space full"). The file automatically grows to   hold the data, if required.    Direct writes to opened directories are not supported.    @param[in] FileHandle              The opened file handle for writing.   @param[in, out] BufferSize         On input, size of Buffer.   @param[in] Buffer                  The buffer in which data to write.    @retval EFI_SUCCESS               Data was written.   @retval EFI_UNSUPPORTED           Writes to open directory are not supported.   @retval EFI_NO_MEDIA              The device has no media.   @retval EFI_DEVICE_ERROR          The device reported an error.   @retval EFI_VOLUME_CORRUPTED      The file system structures are corrupted.   @retval EFI_WRITE_PROTECTED       The device is write-protected.   @retval EFI_ACCESS_DENIED         The file was open for read only.   @retval EFI_VOLUME_FULL           The volume is full. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SHELL_WRITE_FILE
function_decl|)
parameter_list|(
name|IN
name|SHELL_FILE_HANDLE
name|FileHandle
parameter_list|,
name|IN
name|OUT
name|UINTN
modifier|*
name|BufferSize
parameter_list|,
name|IN
name|VOID
modifier|*
name|Buffer
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// EFI_SHELL_PROTOCOL has been updated since UEFI Shell Spec 2.0
end_comment

begin_comment
comment|// Usage of this protocol will require version checking before attempting
end_comment

begin_comment
comment|// to use any new members.  There is no need to check the version for
end_comment

begin_comment
comment|// members that existed in UEFI Shell Spec 2.0.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Update below for any future UEFI Shell spec changes to this protocol.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Check EFI_SHELL_PROTOCOL MajorVersion and MinorVersion:
end_comment

begin_comment
comment|// if ((2 == gEfiShellProtocol->MajorVersion)&&
end_comment

begin_comment
comment|//     (0 == gEfiShellProtocol->MinorVersion)) {
end_comment

begin_comment
comment|//   //
end_comment

begin_comment
comment|//   // Cannot call:
end_comment

begin_comment
comment|//   // RegisterGuidName - UEFI Shell 2.1
end_comment

begin_comment
comment|//   // GetGuidName      - UEFI Shell 2.1
end_comment

begin_comment
comment|//   // GetGuidFromName  - UEFI Shell 2.1
end_comment

begin_comment
comment|//   // GetEnvEx         - UEFI Shell 2.1
end_comment

begin_comment
comment|//   //
end_comment

begin_comment
comment|// } else {
end_comment

begin_comment
comment|//   //
end_comment

begin_comment
comment|//   // Can use all members
end_comment

begin_comment
comment|//   //
end_comment

begin_comment
comment|// }
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_EFI_SHELL_PROTOCOL
block|{
name|EFI_SHELL_EXECUTE
name|Execute
decl_stmt|;
name|EFI_SHELL_GET_ENV
name|GetEnv
decl_stmt|;
name|EFI_SHELL_SET_ENV
name|SetEnv
decl_stmt|;
name|EFI_SHELL_GET_ALIAS
name|GetAlias
decl_stmt|;
name|EFI_SHELL_SET_ALIAS
name|SetAlias
decl_stmt|;
name|EFI_SHELL_GET_HELP_TEXT
name|GetHelpText
decl_stmt|;
name|EFI_SHELL_GET_DEVICE_PATH_FROM_MAP
name|GetDevicePathFromMap
decl_stmt|;
name|EFI_SHELL_GET_MAP_FROM_DEVICE_PATH
name|GetMapFromDevicePath
decl_stmt|;
name|EFI_SHELL_GET_DEVICE_PATH_FROM_FILE_PATH
name|GetDevicePathFromFilePath
decl_stmt|;
name|EFI_SHELL_GET_FILE_PATH_FROM_DEVICE_PATH
name|GetFilePathFromDevicePath
decl_stmt|;
name|EFI_SHELL_SET_MAP
name|SetMap
decl_stmt|;
name|EFI_SHELL_GET_CUR_DIR
name|GetCurDir
decl_stmt|;
name|EFI_SHELL_SET_CUR_DIR
name|SetCurDir
decl_stmt|;
name|EFI_SHELL_OPEN_FILE_LIST
name|OpenFileList
decl_stmt|;
name|EFI_SHELL_FREE_FILE_LIST
name|FreeFileList
decl_stmt|;
name|EFI_SHELL_REMOVE_DUP_IN_FILE_LIST
name|RemoveDupInFileList
decl_stmt|;
name|EFI_SHELL_BATCH_IS_ACTIVE
name|BatchIsActive
decl_stmt|;
name|EFI_SHELL_IS_ROOT_SHELL
name|IsRootShell
decl_stmt|;
name|EFI_SHELL_ENABLE_PAGE_BREAK
name|EnablePageBreak
decl_stmt|;
name|EFI_SHELL_DISABLE_PAGE_BREAK
name|DisablePageBreak
decl_stmt|;
name|EFI_SHELL_GET_PAGE_BREAK
name|GetPageBreak
decl_stmt|;
name|EFI_SHELL_GET_DEVICE_NAME
name|GetDeviceName
decl_stmt|;
name|EFI_SHELL_GET_FILE_INFO
name|GetFileInfo
decl_stmt|;
name|EFI_SHELL_SET_FILE_INFO
name|SetFileInfo
decl_stmt|;
name|EFI_SHELL_OPEN_FILE_BY_NAME
name|OpenFileByName
decl_stmt|;
name|EFI_SHELL_CLOSE_FILE
name|CloseFile
decl_stmt|;
name|EFI_SHELL_CREATE_FILE
name|CreateFile
decl_stmt|;
name|EFI_SHELL_READ_FILE
name|ReadFile
decl_stmt|;
name|EFI_SHELL_WRITE_FILE
name|WriteFile
decl_stmt|;
name|EFI_SHELL_DELETE_FILE
name|DeleteFile
decl_stmt|;
name|EFI_SHELL_DELETE_FILE_BY_NAME
name|DeleteFileByName
decl_stmt|;
name|EFI_SHELL_GET_FILE_POSITION
name|GetFilePosition
decl_stmt|;
name|EFI_SHELL_SET_FILE_POSITION
name|SetFilePosition
decl_stmt|;
name|EFI_SHELL_FLUSH_FILE
name|FlushFile
decl_stmt|;
name|EFI_SHELL_FIND_FILES
name|FindFiles
decl_stmt|;
name|EFI_SHELL_FIND_FILES_IN_DIR
name|FindFilesInDir
decl_stmt|;
name|EFI_SHELL_GET_FILE_SIZE
name|GetFileSize
decl_stmt|;
name|EFI_SHELL_OPEN_ROOT
name|OpenRoot
decl_stmt|;
name|EFI_SHELL_OPEN_ROOT_BY_HANDLE
name|OpenRootByHandle
decl_stmt|;
name|EFI_EVENT
name|ExecutionBreak
decl_stmt|;
name|UINT32
name|MajorVersion
decl_stmt|;
name|UINT32
name|MinorVersion
decl_stmt|;
comment|// Added for Shell 2.1
name|EFI_SHELL_REGISTER_GUID_NAME
name|RegisterGuidName
decl_stmt|;
name|EFI_SHELL_GET_GUID_NAME
name|GetGuidName
decl_stmt|;
name|EFI_SHELL_GET_GUID_FROM_NAME
name|GetGuidFromName
decl_stmt|;
name|EFI_SHELL_GET_ENV_EX
name|GetEnvEx
decl_stmt|;
block|}
name|EFI_SHELL_PROTOCOL
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiShellProtocolGuid
decl_stmt|;
end_decl_stmt

begin_enum
enum|enum
name|ShellVersion
block|{
name|SHELL_MAJOR_VERSION
init|=
literal|2
block|,
name|SHELL_MINOR_VERSION
init|=
literal|1
block|}
enum|;
end_enum

begin_endif
endif|#
directive|endif
end_endif

end_unit

