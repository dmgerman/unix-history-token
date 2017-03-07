begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   SimpleFileSystem protocol as defined in the UEFI 2.0 specification.    The SimpleFileSystem protocol is the programmatic access to the FAT (12,16,32)    file system specified in UEFI 2.0. It can also be used to abstract a file     system other than FAT.    UEFI 2.0 can boot from any valid EFI image contained in a SimpleFileSystem.  Copyright (c) 2006 - 2014, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under  the terms and conditions of the BSD License that accompanies this distribution.   The full text of the license may be found at http://opensource.org/licenses/bsd-license.php.                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                      WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.               **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__SIMPLE_FILE_SYSTEM_H__
end_ifndef

begin_define
define|#
directive|define
name|__SIMPLE_FILE_SYSTEM_H__
end_define

begin_define
define|#
directive|define
name|EFI_SIMPLE_FILE_SYSTEM_PROTOCOL_GUID
define|\
value|{ \     0x964e5b22, 0x6459, 0x11d2, {0x8e, 0x39, 0x0, 0xa0, 0xc9, 0x69, 0x72, 0x3b } \   }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_SIMPLE_FILE_SYSTEM_PROTOCOL
name|EFI_SIMPLE_FILE_SYSTEM_PROTOCOL
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_EFI_FILE_PROTOCOL
name|EFI_FILE_PROTOCOL
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_EFI_FILE_PROTOCOL
modifier|*
name|EFI_FILE_HANDLE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Protocol GUID name defined in EFI1.1.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|SIMPLE_FILE_SYSTEM_PROTOCOL
value|EFI_SIMPLE_FILE_SYSTEM_PROTOCOL_GUID
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Protocol name defined in EFI1.1.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|EFI_SIMPLE_FILE_SYSTEM_PROTOCOL
name|EFI_FILE_IO_INTERFACE
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|EFI_FILE_PROTOCOL
name|EFI_FILE
typedef|;
end_typedef

begin_comment
comment|/**   Open the root directory on a volume.    @param  This A pointer to the volume to open the root directory.   @param  Root A pointer to the location to return the opened file handle for the                root directory.    @retval EFI_SUCCESS          The device was opened.   @retval EFI_UNSUPPORTED      This volume does not support the requested file system type.   @retval EFI_NO_MEDIA         The device has no medium.   @retval EFI_DEVICE_ERROR     The device reported an error.   @retval EFI_VOLUME_CORRUPTED The file system structures are corrupted.   @retval EFI_ACCESS_DENIED    The service denied access to the file.   @retval EFI_OUT_OF_RESOURCES The volume was not opened due to lack of resources.   @retval EFI_MEDIA_CHANGED    The device has a different medium in it or the medium is no                                longer supported. Any existing file handles for this volume are                                no longer valid. To access the files on the new medium, the                                volume must be reopened with OpenVolume().  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SIMPLE_FILE_SYSTEM_PROTOCOL_OPEN_VOLUME
function_decl|)
parameter_list|(
name|IN
name|EFI_SIMPLE_FILE_SYSTEM_PROTOCOL
modifier|*
name|This
parameter_list|,
name|OUT
name|EFI_FILE_PROTOCOL
modifier|*
modifier|*
name|Root
parameter_list|)
function_decl|;
end_typedef

begin_define
define|#
directive|define
name|EFI_SIMPLE_FILE_SYSTEM_PROTOCOL_REVISION
value|0x00010000
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Revision defined in EFI1.1
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_FILE_IO_INTERFACE_REVISION
value|EFI_SIMPLE_FILE_SYSTEM_PROTOCOL_REVISION
end_define

begin_struct
struct|struct
name|_EFI_SIMPLE_FILE_SYSTEM_PROTOCOL
block|{
comment|///
comment|/// The version of the EFI_SIMPLE_FILE_SYSTEM_PROTOCOL. The version
comment|/// specified by this specification is 0x00010000. All future revisions
comment|/// must be backwards compatible.
comment|///
name|UINT64
name|Revision
decl_stmt|;
name|EFI_SIMPLE_FILE_SYSTEM_PROTOCOL_OPEN_VOLUME
name|OpenVolume
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**   Opens a new file relative to the source file's location.    @param  This       A pointer to the EFI_FILE_PROTOCOL instance that is the file                      handle to the source location. This would typically be an open                      handle to a directory.   @param  NewHandle  A pointer to the location to return the opened handle for the new                      file.   @param  FileName   The Null-terminated string of the name of the file to be opened.                      The file name may contain the following path modifiers: "\", ".",                      and "..".   @param  OpenMode   The mode to open the file. The only valid combinations that the                      file may be opened with are: Read, Read/Write, or Create/Read/Write.   @param  Attributes Only valid for EFI_FILE_MODE_CREATE, in which case these are the                       attribute bits for the newly created file.    @retval EFI_SUCCESS          The file was opened.   @retval EFI_NOT_FOUND        The specified file could not be found on the device.   @retval EFI_NO_MEDIA         The device has no medium.   @retval EFI_MEDIA_CHANGED    The device has a different medium in it or the medium is no                                longer supported.   @retval EFI_DEVICE_ERROR     The device reported an error.   @retval EFI_VOLUME_CORRUPTED The file system structures are corrupted.   @retval EFI_WRITE_PROTECTED  An attempt was made to create a file, or open a file for write                                when the media is write-protected.   @retval EFI_ACCESS_DENIED    The service denied access to the file.   @retval EFI_OUT_OF_RESOURCES Not enough resources were available to open the file.   @retval EFI_VOLUME_FULL      The volume is full.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_FILE_OPEN
function_decl|)
parameter_list|(
name|IN
name|EFI_FILE_PROTOCOL
modifier|*
name|This
parameter_list|,
name|OUT
name|EFI_FILE_PROTOCOL
modifier|*
modifier|*
name|NewHandle
parameter_list|,
name|IN
name|CHAR16
modifier|*
name|FileName
parameter_list|,
name|IN
name|UINT64
name|OpenMode
parameter_list|,
name|IN
name|UINT64
name|Attributes
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Open modes
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_FILE_MODE_READ
value|0x0000000000000001ULL
end_define

begin_define
define|#
directive|define
name|EFI_FILE_MODE_WRITE
value|0x0000000000000002ULL
end_define

begin_define
define|#
directive|define
name|EFI_FILE_MODE_CREATE
value|0x8000000000000000ULL
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// File attributes
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_FILE_READ_ONLY
value|0x0000000000000001ULL
end_define

begin_define
define|#
directive|define
name|EFI_FILE_HIDDEN
value|0x0000000000000002ULL
end_define

begin_define
define|#
directive|define
name|EFI_FILE_SYSTEM
value|0x0000000000000004ULL
end_define

begin_define
define|#
directive|define
name|EFI_FILE_RESERVED
value|0x0000000000000008ULL
end_define

begin_define
define|#
directive|define
name|EFI_FILE_DIRECTORY
value|0x0000000000000010ULL
end_define

begin_define
define|#
directive|define
name|EFI_FILE_ARCHIVE
value|0x0000000000000020ULL
end_define

begin_define
define|#
directive|define
name|EFI_FILE_VALID_ATTR
value|0x0000000000000037ULL
end_define

begin_comment
comment|/**   Closes a specified file handle.    @param  This          A pointer to the EFI_FILE_PROTOCOL instance that is the file                          handle to close.    @retval EFI_SUCCESS   The file was closed.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_FILE_CLOSE
function_decl|)
parameter_list|(
name|IN
name|EFI_FILE_PROTOCOL
modifier|*
name|This
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Close and delete the file handle.    @param  This                     A pointer to the EFI_FILE_PROTOCOL instance that is the                                    handle to the file to delete.    @retval EFI_SUCCESS              The file was closed and deleted, and the handle was closed.   @retval EFI_WARN_DELETE_FAILURE  The handle was closed, but the file was not deleted.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_FILE_DELETE
function_decl|)
parameter_list|(
name|IN
name|EFI_FILE_PROTOCOL
modifier|*
name|This
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Reads data from a file.    @param  This       A pointer to the EFI_FILE_PROTOCOL instance that is the file                      handle to read data from.   @param  BufferSize On input, the size of the Buffer. On output, the amount of data                      returned in Buffer. In both cases, the size is measured in bytes.   @param  Buffer     The buffer into which the data is read.    @retval EFI_SUCCESS          Data was read.   @retval EFI_NO_MEDIA         The device has no medium.   @retval EFI_DEVICE_ERROR     The device reported an error.   @retval EFI_DEVICE_ERROR     An attempt was made to read from a deleted file.   @retval EFI_DEVICE_ERROR     On entry, the current file position is beyond the end of the file.   @retval EFI_VOLUME_CORRUPTED The file system structures are corrupted.   @retval EFI_BUFFER_TOO_SMALL The BufferSize is too small to read the current directory                                entry. BufferSize has been updated with the size                                needed to complete the request.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_FILE_READ
function_decl|)
parameter_list|(
name|IN
name|EFI_FILE_PROTOCOL
modifier|*
name|This
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
end_typedef

begin_comment
comment|/**   Writes data to a file.    @param  This       A pointer to the EFI_FILE_PROTOCOL instance that is the file                      handle to write data to.   @param  BufferSize On input, the size of the Buffer. On output, the amount of data                      actually written. In both cases, the size is measured in bytes.   @param  Buffer     The buffer of data to write.    @retval EFI_SUCCESS          Data was written.   @retval EFI_UNSUPPORTED      Writes to open directory files are not supported.   @retval EFI_NO_MEDIA         The device has no medium.   @retval EFI_DEVICE_ERROR     The device reported an error.   @retval EFI_DEVICE_ERROR     An attempt was made to write to a deleted file.   @retval EFI_VOLUME_CORRUPTED The file system structures are corrupted.   @retval EFI_WRITE_PROTECTED  The file or medium is write-protected.   @retval EFI_ACCESS_DENIED    The file was opened read only.   @retval EFI_VOLUME_FULL      The volume is full.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_FILE_WRITE
function_decl|)
parameter_list|(
name|IN
name|EFI_FILE_PROTOCOL
modifier|*
name|This
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
comment|/**   Sets a file's current position.    @param  This            A pointer to the EFI_FILE_PROTOCOL instance that is the                           file handle to set the requested position on.   @param  Position        The byte position from the start of the file to set.    @retval EFI_SUCCESS      The position was set.   @retval EFI_UNSUPPORTED  The seek request for nonzero is not valid on open                            directories.   @retval EFI_DEVICE_ERROR An attempt was made to set the position of a deleted file.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_FILE_SET_POSITION
function_decl|)
parameter_list|(
name|IN
name|EFI_FILE_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINT64
name|Position
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Returns a file's current position.    @param  This            A pointer to the EFI_FILE_PROTOCOL instance that is the file                           handle to get the current position on.   @param  Position        The address to return the file's current position value.    @retval EFI_SUCCESS      The position was returned.   @retval EFI_UNSUPPORTED  The request is not valid on open directories.   @retval EFI_DEVICE_ERROR An attempt was made to get the position from a deleted file.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_FILE_GET_POSITION
function_decl|)
parameter_list|(
name|IN
name|EFI_FILE_PROTOCOL
modifier|*
name|This
parameter_list|,
name|OUT
name|UINT64
modifier|*
name|Position
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Returns information about a file.    @param  This            A pointer to the EFI_FILE_PROTOCOL instance that is the file                           handle the requested information is for.   @param  InformationType The type identifier for the information being requested.   @param  BufferSize      On input, the size of Buffer. On output, the amount of data                           returned in Buffer. In both cases, the size is measured in bytes.   @param  Buffer          A pointer to the data buffer to return. The buffer's type is                           indicated by InformationType.    @retval EFI_SUCCESS          The information was returned.   @retval EFI_UNSUPPORTED      The InformationType is not known.   @retval EFI_NO_MEDIA         The device has no medium.   @retval EFI_DEVICE_ERROR     The device reported an error.   @retval EFI_VOLUME_CORRUPTED The file system structures are corrupted.   @retval EFI_BUFFER_TOO_SMALL The BufferSize is too small to read the current directory entry.                                BufferSize has been updated with the size needed to complete                                the request. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_FILE_GET_INFO
function_decl|)
parameter_list|(
name|IN
name|EFI_FILE_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_GUID
modifier|*
name|InformationType
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
end_typedef

begin_comment
comment|/**   Sets information about a file.    @param  File            A pointer to the EFI_FILE_PROTOCOL instance that is the file                           handle the information is for.   @param  InformationType The type identifier for the information being set.   @param  BufferSize      The size, in bytes, of Buffer.   @param  Buffer          A pointer to the data buffer to write. The buffer's type is                           indicated by InformationType.    @retval EFI_SUCCESS          The information was set.   @retval EFI_UNSUPPORTED      The InformationType is not known.   @retval EFI_NO_MEDIA         The device has no medium.   @retval EFI_DEVICE_ERROR     The device reported an error.   @retval EFI_VOLUME_CORRUPTED The file system structures are corrupted.   @retval EFI_WRITE_PROTECTED  InformationType is EFI_FILE_INFO_ID and the media is                                read-only.   @retval EFI_WRITE_PROTECTED  InformationType is EFI_FILE_PROTOCOL_SYSTEM_INFO_ID                                and the media is read only.   @retval EFI_WRITE_PROTECTED  InformationType is EFI_FILE_SYSTEM_VOLUME_LABEL_ID                                and the media is read-only.   @retval EFI_ACCESS_DENIED    An attempt is made to change the name of a file to a                                file that is already present.   @retval EFI_ACCESS_DENIED    An attempt is being made to change the EFI_FILE_DIRECTORY                                Attribute.   @retval EFI_ACCESS_DENIED    An attempt is being made to change the size of a directory.   @retval EFI_ACCESS_DENIED    InformationType is EFI_FILE_INFO_ID and the file was opened                                read-only and an attempt is being made to modify a field                                other than Attribute.   @retval EFI_VOLUME_FULL      The volume is full.   @retval EFI_BAD_BUFFER_SIZE  BufferSize is smaller than the size of the type indicated                                by InformationType.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_FILE_SET_INFO
function_decl|)
parameter_list|(
name|IN
name|EFI_FILE_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_GUID
modifier|*
name|InformationType
parameter_list|,
name|IN
name|UINTN
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
comment|/**   Flushes all modified data associated with a file to a device.    @param  This A pointer to the EFI_FILE_PROTOCOL instance that is the file                 handle to flush.    @retval EFI_SUCCESS          The data was flushed.   @retval EFI_NO_MEDIA         The device has no medium.   @retval EFI_DEVICE_ERROR     The device reported an error.   @retval EFI_VOLUME_CORRUPTED The file system structures are corrupted.   @retval EFI_WRITE_PROTECTED  The file or medium is write-protected.   @retval EFI_ACCESS_DENIED    The file was opened read-only.   @retval EFI_VOLUME_FULL      The volume is full.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_FILE_FLUSH
function_decl|)
parameter_list|(
name|IN
name|EFI_FILE_PROTOCOL
modifier|*
name|This
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|//
comment|// If Event is NULL, then blocking I/O is performed.
comment|// If Event is not NULL and non-blocking I/O is supported, then non-blocking I/O is performed,
comment|// and Event will be signaled when the read request is completed.
comment|// The caller must be prepared to handle the case where the callback associated with Event
comment|// occurs before the original asynchronous I/O request call returns.
comment|//
name|EFI_EVENT
name|Event
decl_stmt|;
comment|//
comment|// Defines whether or not the signaled event encountered an error.
comment|//
name|EFI_STATUS
name|Status
decl_stmt|;
comment|//
comment|// For OpenEx():  Not Used, ignored.
comment|// For ReadEx():  On input, the size of the Buffer. On output, the amount of data returned in Buffer.
comment|//                In both cases, the size is measured in bytes.
comment|// For WriteEx(): On input, the size of the Buffer. On output, the amount of data actually written.
comment|//                In both cases, the size is measured in bytes.
comment|// For FlushEx(): Not used, ignored.
comment|//
name|UINTN
name|BufferSize
decl_stmt|;
comment|//
comment|// For OpenEx():  Not Used, ignored.
comment|// For ReadEx():  The buffer into which the data is read.
comment|// For WriteEx(): The buffer of data to write.
comment|// For FlushEx(): Not Used, ignored.
comment|//
name|VOID
modifier|*
name|Buffer
decl_stmt|;
block|}
name|EFI_FILE_IO_TOKEN
typedef|;
end_typedef

begin_comment
comment|/**   Opens a new file relative to the source directory's location.    @param  This       A pointer to the EFI_FILE_PROTOCOL instance that is the file                      handle to the source location.   @param  NewHandle  A pointer to the location to return the opened handle for the new                      file.   @param  FileName   The Null-terminated string of the name of the file to be opened.                      The file name may contain the following path modifiers: "\", ".",                      and "..".   @param  OpenMode   The mode to open the file. The only valid combinations that the                      file may be opened with are: Read, Read/Write, or Create/Read/Write.   @param  Attributes Only valid for EFI_FILE_MODE_CREATE, in which case these are the                       attribute bits for the newly created file.   @param  Token      A pointer to the token associated with the transaction.    @retval EFI_SUCCESS          If Event is NULL (blocking I/O): The data was read successfully.                                If Event is not NULL (asynchronous I/O): The request was successfully                                                                         queued for processing.   @retval EFI_NOT_FOUND        The specified file could not be found on the device.   @retval EFI_NO_MEDIA         The device has no medium.   @retval EFI_MEDIA_CHANGED    The device has a different medium in it or the medium is no                                longer supported.   @retval EFI_DEVICE_ERROR     The device reported an error.   @retval EFI_VOLUME_CORRUPTED The file system structures are corrupted.   @retval EFI_WRITE_PROTECTED  An attempt was made to create a file, or open a file for write                                when the media is write-protected.   @retval EFI_ACCESS_DENIED    The service denied access to the file.   @retval EFI_OUT_OF_RESOURCES Not enough resources were available to open the file.   @retval EFI_VOLUME_FULL      The volume is full.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_FILE_OPEN_EX
function_decl|)
parameter_list|(
name|IN
name|EFI_FILE_PROTOCOL
modifier|*
name|This
parameter_list|,
name|OUT
name|EFI_FILE_PROTOCOL
modifier|*
modifier|*
name|NewHandle
parameter_list|,
name|IN
name|CHAR16
modifier|*
name|FileName
parameter_list|,
name|IN
name|UINT64
name|OpenMode
parameter_list|,
name|IN
name|UINT64
name|Attributes
parameter_list|,
name|IN
name|OUT
name|EFI_FILE_IO_TOKEN
modifier|*
name|Token
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Reads data from a file.    @param  This       A pointer to the EFI_FILE_PROTOCOL instance that is the file handle to read data from.   @param  Token      A pointer to the token associated with the transaction.    @retval EFI_SUCCESS          If Event is NULL (blocking I/O): The data was read successfully.                                If Event is not NULL (asynchronous I/O): The request was successfully                                                                         queued for processing.   @retval EFI_NO_MEDIA         The device has no medium.   @retval EFI_DEVICE_ERROR     The device reported an error.   @retval EFI_DEVICE_ERROR     An attempt was made to read from a deleted file.   @retval EFI_DEVICE_ERROR     On entry, the current file position is beyond the end of the file.   @retval EFI_VOLUME_CORRUPTED The file system structures are corrupted.   @retval EFI_OUT_OF_RESOURCES Unable to queue the request due to lack of resources. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_FILE_READ_EX
function_decl|)
parameter_list|(
name|IN
name|EFI_FILE_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|OUT
name|EFI_FILE_IO_TOKEN
modifier|*
name|Token
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Writes data to a file.    @param  This       A pointer to the EFI_FILE_PROTOCOL instance that is the file handle to write data to.   @param  Token      A pointer to the token associated with the transaction.    @retval EFI_SUCCESS          If Event is NULL (blocking I/O): The data was read successfully.                                If Event is not NULL (asynchronous I/O): The request was successfully                                                                         queued for processing.   @retval EFI_UNSUPPORTED      Writes to open directory files are not supported.   @retval EFI_NO_MEDIA         The device has no medium.   @retval EFI_DEVICE_ERROR     The device reported an error.   @retval EFI_DEVICE_ERROR     An attempt was made to write to a deleted file.   @retval EFI_VOLUME_CORRUPTED The file system structures are corrupted.   @retval EFI_WRITE_PROTECTED  The file or medium is write-protected.   @retval EFI_ACCESS_DENIED    The file was opened read only.   @retval EFI_VOLUME_FULL      The volume is full.   @retval EFI_OUT_OF_RESOURCES Unable to queue the request due to lack of resources. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_FILE_WRITE_EX
function_decl|)
parameter_list|(
name|IN
name|EFI_FILE_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|OUT
name|EFI_FILE_IO_TOKEN
modifier|*
name|Token
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Flushes all modified data associated with a file to a device.    @param  This  A pointer to the EFI_FILE_PROTOCOL instance that is the file                  handle to flush.   @param  Token A pointer to the token associated with the transaction.    @retval EFI_SUCCESS          If Event is NULL (blocking I/O): The data was read successfully.                                If Event is not NULL (asynchronous I/O): The request was successfully                                                                         queued for processing.   @retval EFI_NO_MEDIA         The device has no medium.   @retval EFI_DEVICE_ERROR     The device reported an error.   @retval EFI_VOLUME_CORRUPTED The file system structures are corrupted.   @retval EFI_WRITE_PROTECTED  The file or medium is write-protected.   @retval EFI_ACCESS_DENIED    The file was opened read-only.   @retval EFI_VOLUME_FULL      The volume is full.   @retval EFI_OUT_OF_RESOURCES Unable to queue the request due to lack of resources.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_FILE_FLUSH_EX
function_decl|)
parameter_list|(
name|IN
name|EFI_FILE_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|OUT
name|EFI_FILE_IO_TOKEN
modifier|*
name|Token
parameter_list|)
function_decl|;
end_typedef

begin_define
define|#
directive|define
name|EFI_FILE_PROTOCOL_REVISION
value|0x00010000
end_define

begin_define
define|#
directive|define
name|EFI_FILE_PROTOCOL_REVISION2
value|0x00020000
end_define

begin_define
define|#
directive|define
name|EFI_FILE_PROTOCOL_LATEST_REVISION
value|EFI_FILE_PROTOCOL_REVISION2
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Revision defined in EFI1.1.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_FILE_REVISION
value|EFI_FILE_PROTOCOL_REVISION
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// The EFI_FILE_PROTOCOL provides file IO access to supported file systems.
end_comment

begin_comment
comment|/// An EFI_FILE_PROTOCOL provides access to a file's or directory's contents,
end_comment

begin_comment
comment|/// and is also a reference to a location in the directory tree of the file system
end_comment

begin_comment
comment|/// in which the file resides. With any given file handle, other files may be opened
end_comment

begin_comment
comment|/// relative to this file's location, yielding new file handles.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_FILE_PROTOCOL
block|{
comment|///
comment|/// The version of the EFI_FILE_PROTOCOL interface. The version specified
comment|/// by this specification is EFI_FILE_PROTOCOL_LATEST_REVISION.
comment|/// Future versions are required to be backward compatible to version 1.0.
comment|///
name|UINT64
name|Revision
decl_stmt|;
name|EFI_FILE_OPEN
name|Open
decl_stmt|;
name|EFI_FILE_CLOSE
name|Close
decl_stmt|;
name|EFI_FILE_DELETE
name|Delete
decl_stmt|;
name|EFI_FILE_READ
name|Read
decl_stmt|;
name|EFI_FILE_WRITE
name|Write
decl_stmt|;
name|EFI_FILE_GET_POSITION
name|GetPosition
decl_stmt|;
name|EFI_FILE_SET_POSITION
name|SetPosition
decl_stmt|;
name|EFI_FILE_GET_INFO
name|GetInfo
decl_stmt|;
name|EFI_FILE_SET_INFO
name|SetInfo
decl_stmt|;
name|EFI_FILE_FLUSH
name|Flush
decl_stmt|;
name|EFI_FILE_OPEN_EX
name|OpenEx
decl_stmt|;
name|EFI_FILE_READ_EX
name|ReadEx
decl_stmt|;
name|EFI_FILE_WRITE_EX
name|WriteEx
decl_stmt|;
name|EFI_FILE_FLUSH_EX
name|FlushEx
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiSimpleFileSystemProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

