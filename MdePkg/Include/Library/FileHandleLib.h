begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Provides interface to EFI_FILE_HANDLE functionality.    Copyright (c) 2009 - 2017, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_FILE_HANDLE_LIBRARY_HEADER_
end_ifndef

begin_define
define|#
directive|define
name|_FILE_HANDLE_LIBRARY_HEADER_
end_define

begin_include
include|#
directive|include
file|<Protocol/SimpleFileSystem.h>
end_include

begin_include
include|#
directive|include
file|<Guid/FileInfo.h>
end_include

begin_comment
comment|/// The tag for use in identifying UNICODE files.
end_comment

begin_comment
comment|/// If the file is UNICODE, the first 16 bits of the file will equal this value.
end_comment

begin_decl_stmt
specifier|extern
name|CONST
name|UINT16
name|gUnicodeFileTag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**   This function retrieves information about the file for the handle   specified and stores it in the allocated pool memory.    This function allocates a buffer to store the file's information. It is the   caller's responsibility to free the buffer.    @param[in] FileHandle         The file handle of the file for which information is                                 being requested.    @retval NULL                  Information could not be retrieved.   @retval !NULL                 The information about the file. **/
end_comment

begin_function_decl
name|EFI_FILE_INFO
modifier|*
name|EFIAPI
name|FileHandleGetInfo
parameter_list|(
name|IN
name|EFI_FILE_HANDLE
name|FileHandle
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   This function sets the information about the file for the opened handle   specified.    @param[in]  FileHandle        The file handle of the file for which information                                 is being set.    @param[in]  FileInfo          The information to set.    @retval EFI_SUCCESS           The information was set.   @retval EFI_INVALID_PARAMETER A parameter was out of range or invalid.   @retval EFI_UNSUPPORTED       The FileHandle does not support FileInfo.   @retval EFI_NO_MEDIA          The device has no medium.   @retval EFI_DEVICE_ERROR      The device reported an error.   @retval EFI_VOLUME_CORRUPTED  The file system structures are corrupted.   @retval EFI_WRITE_PROTECTED   The file or medium is write protected.   @retval EFI_ACCESS_DENIED     The file was opened read only.   @retval EFI_VOLUME_FULL       The volume is full. **/
end_comment

begin_function_decl
name|EFI_STATUS
name|EFIAPI
name|FileHandleSetInfo
parameter_list|(
name|IN
name|EFI_FILE_HANDLE
name|FileHandle
parameter_list|,
name|IN
name|CONST
name|EFI_FILE_INFO
modifier|*
name|FileInfo
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   This function reads information from an opened file.    If FileHandle is not a directory, the function reads the requested number of   bytes from the file at the file's current position and returns them in Buffer.   If the read goes beyond the end of the file, the read length is truncated to the   end of the file. The file's current position is increased by the number of bytes   returned.  If FileHandle is a directory, the function reads the directory entry   at the file's current position and returns the entry in Buffer. If the Buffer   is not large enough to hold the current directory entry, then   EFI_BUFFER_TOO_SMALL is returned and the current file position is not updated.   BufferSize is set to be the size of the buffer needed to read the entry. On   success, the current position is updated to the next directory entry. If there   are no more directory entries, the read returns a zero-length buffer.   EFI_FILE_INFO is the structure returned as the directory entry.    @param[in] FileHandle          The opened file handle.   @param[in, out] BufferSize     On input, the size of buffer in bytes.  On return,                                  the number of bytes written.   @param[out] Buffer             The buffer to put read data into.    @retval EFI_SUCCESS         Data was read.   @retval EFI_NO_MEDIA          The device has no media.   @retval EFI_DEVICE_ERROR  The device reported an error.   @retval EFI_VOLUME_CORRUPTED  The file system structures are corrupted.   @retval EFI_BUFFER_TO_SMALL Buffer is too small. ReadSize contains required                                 size.  **/
end_comment

begin_function_decl
name|EFI_STATUS
name|EFIAPI
name|FileHandleRead
parameter_list|(
name|IN
name|EFI_FILE_HANDLE
name|FileHandle
parameter_list|,
name|IN
name|OUT
name|UINTN
modifier|*
name|BufferSize
parameter_list|,
name|OUT
name|VOID
modifier|*
name|Buffer
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Write data to a file.    This function writes the specified number of bytes to the file at the current   file position. The current file position is advanced the actual number of bytes   written, which is returned in BufferSize. Partial writes only occur when there   has been a data error during the write attempt (such as "volume space full").   The file is automatically grown to hold the data if required. Direct writes to   opened directories are not supported.    @param[in] FileHandle          The opened file for writing.   @param[in, out] BufferSize     On input, the number of bytes in Buffer.  On output,                                  the number of bytes written.   @param[in] Buffer              The buffer containing data to write is stored.    @retval EFI_SUCCESS         Data was written.   @retval EFI_UNSUPPORTED       Writes to an open directory are not supported.   @retval EFI_NO_MEDIA          The device has no media.   @retval EFI_DEVICE_ERROR  The device reported an error.   @retval EFI_VOLUME_CORRUPTED  The file system structures are corrupted.   @retval EFI_WRITE_PROTECTED The device is write-protected.   @retval EFI_ACCESS_DENIED The file was opened for read only.   @retval EFI_VOLUME_FULL The volume is full. **/
end_comment

begin_function_decl
name|EFI_STATUS
name|EFIAPI
name|FileHandleWrite
parameter_list|(
name|IN
name|EFI_FILE_HANDLE
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
end_function_decl

begin_comment
comment|/**   Close an open file handle.    This function closes a specified file handle. All "dirty" cached file data is   flushed to the device, and the file is closed. In all cases the handle is   closed.    @param[in] FileHandle           The file handle to close.    @retval EFI_SUCCESS             The file handle was closed successfully. **/
end_comment

begin_function_decl
name|EFI_STATUS
name|EFIAPI
name|FileHandleClose
parameter_list|(
name|IN
name|EFI_FILE_HANDLE
name|FileHandle
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Delete a file and close the handle.    This function closes and deletes a file. In all cases the file handle is closed.   If the file cannot be deleted, the warning code EFI_WARN_DELETE_FAILURE is   returned, but the handle is still closed.    @param[in] FileHandle             The file handle to delete.    @retval EFI_SUCCESS               The file was closed successfully.   @retval EFI_WARN_DELETE_FAILURE   The handle was closed, but the file was not                                     deleted.   @retval INVALID_PARAMETER         One of the parameters has an invalid value. **/
end_comment

begin_function_decl
name|EFI_STATUS
name|EFIAPI
name|FileHandleDelete
parameter_list|(
name|IN
name|EFI_FILE_HANDLE
name|FileHandle
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Set the current position in a file.    This function sets the current file position for the handle to the position   supplied. With the exception of moving to position 0xFFFFFFFFFFFFFFFF, only   absolute positioning is supported, and moving past the end of the file is   allowed (a subsequent write would grow the file). Moving to position   0xFFFFFFFFFFFFFFFF causes the current position to be set to the end of the file.   If FileHandle is a directory, the only position that may be set is zero. This   has the effect of starting the read process of the directory entries over again.    @param[in] FileHandle         The file handle on which the position is being set.   @param[in] Position           The byte position from the beginning of the file.    @retval EFI_SUCCESS           The operation completed successfully.   @retval EFI_UNSUPPORTED       The request for non-zero is not valid on                                 directories.   @retval INVALID_PARAMETER     One of the parameters has an invalid value. **/
end_comment

begin_function_decl
name|EFI_STATUS
name|EFIAPI
name|FileHandleSetPosition
parameter_list|(
name|IN
name|EFI_FILE_HANDLE
name|FileHandle
parameter_list|,
name|IN
name|UINT64
name|Position
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Gets a file's current position.    This function retrieves the current file position for the file handle. For   directories, the current file position has no meaning outside of the file   system driver. As such, the operation is not supported. An error is returned   if FileHandle is a directory.    @param[in] FileHandle         The open file handle on which to get the position.   @param[out] Position          The byte position from beginning of file.    @retval EFI_SUCCESS           The operation completed successfully.   @retval INVALID_PARAMETER     One of the parameters has an invalid value.   @retval EFI_UNSUPPORTED       The request is not valid on directories. **/
end_comment

begin_function_decl
name|EFI_STATUS
name|EFIAPI
name|FileHandleGetPosition
parameter_list|(
name|IN
name|EFI_FILE_HANDLE
name|FileHandle
parameter_list|,
name|OUT
name|UINT64
modifier|*
name|Position
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Flushes data on a file.    This function flushes all modified data associated with a file to a device.    @param[in] FileHandle         The file handle on which to flush data.    @retval EFI_SUCCESS           The data was flushed.   @retval EFI_NO_MEDIA          The device has no media.   @retval EFI_DEVICE_ERROR      The device reported an error.   @retval EFI_VOLUME_CORRUPTED  The file system structures are corrupted.   @retval EFI_WRITE_PROTECTED   The file or medium is write protected.   @retval EFI_ACCESS_DENIED     The file was opened for read only. **/
end_comment

begin_function_decl
name|EFI_STATUS
name|EFIAPI
name|FileHandleFlush
parameter_list|(
name|IN
name|EFI_FILE_HANDLE
name|FileHandle
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Function to determine if a given handle is a directory handle.    Open the file information on the DirHandle and verify that the Attribute   includes EFI_FILE_DIRECTORY bit set.    @param[in] DirHandle          Handle to open file.    @retval EFI_SUCCESS           DirHandle is a directory.   @retval EFI_INVALID_PARAMETER DirHandle is NULL.                                  The file information returns from FileHandleGetInfo is NULL.    @retval EFI_NOT_FOUND         DirHandle is not a directory. **/
end_comment

begin_function_decl
name|EFI_STATUS
name|EFIAPI
name|FileHandleIsDirectory
parameter_list|(
name|IN
name|EFI_FILE_HANDLE
name|DirHandle
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Retrieve first entry from a directory.    This function takes an open directory handle and gets information from the   first entry in the directory.  A buffer is allocated to contain   the information and a pointer to the buffer is returned in *Buffer.  The   caller can use FileHandleFindNextFile() to get subsequent directory entries.    The buffer will be freed by FileHandleFindNextFile() when the last directory   entry is read.  Otherwise, the caller must free the buffer, using FreePool,   when finished with it.    @param[in]  DirHandle         The file handle of the directory to search.   @param[out] Buffer            The pointer to pointer to buffer for file's information.    @retval EFI_SUCCESS           Found the first file.   @retval EFI_NOT_FOUND         Cannot find the directory.   @retval EFI_NO_MEDIA          The device has no media.   @retval EFI_DEVICE_ERROR      The device reported an error.   @retval EFI_VOLUME_CORRUPTED  The file system structures are corrupted.   @return Others                The status of FileHandleGetInfo, FileHandleSetPosition,                                 or FileHandleRead. **/
end_comment

begin_function_decl
name|EFI_STATUS
name|EFIAPI
name|FileHandleFindFirstFile
parameter_list|(
name|IN
name|EFI_FILE_HANDLE
name|DirHandle
parameter_list|,
name|OUT
name|EFI_FILE_INFO
modifier|*
modifier|*
name|Buffer
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Retrieve next entries from a directory.    To use this function, the caller must first call the FileHandleFindFirstFile()   function to get the first directory entry.  Subsequent directory entries are   retrieved by using the FileHandleFindNextFile() function.  This function can   be called several times to get each entry from the directory.  If the call of   FileHandleFindNextFile() retrieved the last directory entry, the next call of   this function will set *NoFile to TRUE and free the buffer.    @param[in]  DirHandle         The file handle of the directory.   @param[out] Buffer            The pointer to buffer for file's information.   @param[out] NoFile            The pointer to boolean when last file is found.    @retval EFI_SUCCESS           Found the next file, or reached last file.   @retval EFI_NO_MEDIA          The device has no media.   @retval EFI_DEVICE_ERROR      The device reported an error.   @retval EFI_VOLUME_CORRUPTED  The file system structures are corrupted. **/
end_comment

begin_function_decl
name|EFI_STATUS
name|EFIAPI
name|FileHandleFindNextFile
parameter_list|(
name|IN
name|EFI_FILE_HANDLE
name|DirHandle
parameter_list|,
name|OUT
name|EFI_FILE_INFO
modifier|*
name|Buffer
parameter_list|,
name|OUT
name|BOOLEAN
modifier|*
name|NoFile
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Retrieve the size of a file.    This function extracts the file size info from the FileHandle's EFI_FILE_INFO   data.    @param[in] FileHandle         The file handle from which size is retrieved.   @param[out] Size              The pointer to size.    @retval EFI_SUCCESS           Operation was completed successfully.   @retval EFI_DEVICE_ERROR      Cannot access the file.   @retval EFI_INVALID_PARAMETER FileHandle is NULL.                                 Size is NULL. **/
end_comment

begin_function_decl
name|EFI_STATUS
name|EFIAPI
name|FileHandleGetSize
parameter_list|(
name|IN
name|EFI_FILE_HANDLE
name|FileHandle
parameter_list|,
name|OUT
name|UINT64
modifier|*
name|Size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Set the size of a file.    This function changes the file size info from the FileHandle's EFI_FILE_INFO   data.    @param[in] FileHandle         The file handle whose size is to be changed.   @param[in] Size               The new size.    @retval EFI_SUCCESS           The operation completed successfully.   @retval EFI_DEVICE_ERROR      Cannot access the file.   @retval EFI_INVALID_PARAMETER FileHandle is NULL. **/
end_comment

begin_function_decl
name|EFI_STATUS
name|EFIAPI
name|FileHandleSetSize
parameter_list|(
name|IN
name|EFI_FILE_HANDLE
name|FileHandle
parameter_list|,
name|IN
name|UINT64
name|Size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Function to get a full filename given a EFI_FILE_HANDLE somewhere lower on the   directory 'stack'. If the file is a directory, then append the '\' char at the    end of name string. If it's not a directory, then the last '\' should not be    added.    @param[in] Handle             Handle to the Directory or File to create path to.   @param[out] FullFileName      Pointer to pointer to generated full file name.  It                                 is the responsibility of the caller to free this memory                                 with a call to FreePool().   @retval EFI_SUCCESS           The operation was successful and FullFileName is valid.   @retval EFI_INVALID_PARAMETER Handle was NULL.   @retval EFI_INVALID_PARAMETER FullFileName was NULL.   @retval EFI_OUT_OF_MEMORY     A memory allocation failed. **/
end_comment

begin_function_decl
name|EFI_STATUS
name|EFIAPI
name|FileHandleGetFileName
parameter_list|(
name|IN
name|CONST
name|EFI_FILE_HANDLE
name|Handle
parameter_list|,
name|OUT
name|CHAR16
modifier|*
modifier|*
name|FullFileName
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Function to read a single line (up to but not including the \n) from a file.    If the position upon start is 0, then the Ascii Boolean will be set.  This should be   maintained and not changed for all operations with the same file.   The function will not return the \r and \n character in buffer. When an empty line is   read a CHAR_NULL character will be returned in buffer.    @param[in]       Handle        FileHandle to read from.   @param[in, out]  Buffer        The pointer to buffer to read into.   @param[in, out]  Size          The pointer to number of bytes in Buffer.   @param[in]       Truncate      If the buffer is large enough, this has no effect.                                  If the buffer is is too small and Truncate is TRUE,                                  the line will be truncated.                                  If the buffer is is too small and Truncate is FALSE,                                  then no read will occur.    @param[in, out]  Ascii         Boolean value for indicating whether the file is                                  Ascii (TRUE) or UCS2 (FALSE).    @retval EFI_SUCCESS           The operation was successful.  The line is stored in                                 Buffer.   @retval EFI_INVALID_PARAMETER Handle was NULL.   @retval EFI_INVALID_PARAMETER Size was NULL.   @retval EFI_BUFFER_TOO_SMALL  Size was not large enough to store the line.                                 Size was updated to the minimum space required.   @sa FileHandleRead **/
end_comment

begin_function_decl
name|EFI_STATUS
name|EFIAPI
name|FileHandleReadLine
parameter_list|(
name|IN
name|EFI_FILE_HANDLE
name|Handle
parameter_list|,
name|IN
name|OUT
name|CHAR16
modifier|*
name|Buffer
parameter_list|,
name|IN
name|OUT
name|UINTN
modifier|*
name|Size
parameter_list|,
name|IN
name|BOOLEAN
name|Truncate
parameter_list|,
name|IN
name|OUT
name|BOOLEAN
modifier|*
name|Ascii
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Function to read a single line from a file. The \n is not included in the returned   buffer.  The returned buffer must be callee freed.    If the position upon start is 0, then the Ascii Boolean will be set.  This should be   maintained and not changed for all operations with the same file.    @param[in]       Handle        FileHandle to read from.   @param[in, out]  Ascii         Boolean value for indicating whether the file is                                  Ascii (TRUE) or UCS2 (FALSE).    @return                       The line of text from the file.    @sa FileHandleReadLine **/
end_comment

begin_function_decl
name|CHAR16
modifier|*
name|EFIAPI
name|FileHandleReturnLine
parameter_list|(
name|IN
name|EFI_FILE_HANDLE
name|Handle
parameter_list|,
name|IN
name|OUT
name|BOOLEAN
modifier|*
name|Ascii
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Function to write a line of text to a file.      If the file is a Unicode file (with UNICODE file tag) then write the unicode    text.   If the file is an ASCII file then write the ASCII text.   If the size of file is zero (without file tag at the beginning) then write    ASCII text as default.    @param[in]     Handle         FileHandle to write to.   @param[in]     Buffer         Buffer to write, if NULL the function will                                 take no action and return EFI_SUCCESS.    @retval  EFI_SUCCESS            The data was written.                                   Buffer is NULL.   @retval  EFI_INVALID_PARAMETER  Handle is NULL.   @retval  EFI_OUT_OF_RESOURCES   Unable to allocate temporary space for ASCII                                    string due to out of resources.    @sa FileHandleWrite **/
end_comment

begin_function_decl
name|EFI_STATUS
name|EFIAPI
name|FileHandleWriteLine
parameter_list|(
name|IN
name|EFI_FILE_HANDLE
name|Handle
parameter_list|,
name|IN
name|CHAR16
modifier|*
name|Buffer
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Function to take a formatted argument and print it to a file.    @param[in] Handle   The file handle for the file to write to.   @param[in] Format   The format argument (see printlib for the format specifier).   @param[in] ...      The variable arguments for the format.    @retval EFI_SUCCESS The operation was successful.   @retval other       A return value from FileHandleWriteLine.    @sa FileHandleWriteLine **/
end_comment

begin_function_decl
name|EFI_STATUS
name|EFIAPI
name|FileHandlePrintLine
parameter_list|(
name|IN
name|EFI_FILE_HANDLE
name|Handle
parameter_list|,
name|IN
name|CONST
name|CHAR16
modifier|*
name|Format
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Function to determine if a FILE_HANDLE is at the end of the file.    This will NOT work on directories.    If Handle is NULL, then ASSERT().    @param[in] Handle     The file handle.    @retval TRUE          The position is at the end of the file.   @retval FALSE         The position is not at the end of the file. **/
end_comment

begin_function_decl
name|BOOLEAN
name|EFIAPI
name|FileHandleEof
parameter_list|(
name|IN
name|EFI_FILE_HANDLE
name|Handle
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|//_FILE_HANDLE_LIBRARY_HEADER_
end_comment

end_unit

