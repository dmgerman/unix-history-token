begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Disk I/O 2 protocol as defined in the UEFI 2.4 specification.    The Disk I/O 2 protocol defines an extension to the Disk I/O protocol to enable   non-blocking / asynchronous byte-oriented disk operation.    Copyright (c) 2013, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.               **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DISK_IO2_H__
end_ifndef

begin_define
define|#
directive|define
name|__DISK_IO2_H__
end_define

begin_define
define|#
directive|define
name|EFI_DISK_IO2_PROTOCOL_GUID
define|\
value|{ \     0x151c8eae, 0x7f2c, 0x472c, 0x9e, 0x54, 0x98, 0x28, 0x19, 0x4f, 0x6a, 0x88 \   }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_DISK_IO2_PROTOCOL
name|EFI_DISK_IO2_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|/**   The struct of Disk IO2 Token. **/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|//
comment|// If Event is NULL, then blocking I/O is performed.
comment|// If Event is not NULL and non-blocking I/O is supported, then non-blocking I/O is performed,
comment|// and Event will be signaled when the I/O request is completed.
comment|// The caller must be prepared to handle the case where the callback associated with Event occurs
comment|// before the original asynchronous I/O request call returns.
comment|//
name|EFI_EVENT
name|Event
decl_stmt|;
comment|//
comment|// Defines whether or not the signaled event encountered an error.
comment|//
name|EFI_STATUS
name|TransactionStatus
decl_stmt|;
block|}
name|EFI_DISK_IO2_TOKEN
typedef|;
end_typedef

begin_comment
comment|/**   Terminate outstanding asynchronous requests to a device.    @param This                   Indicates a pointer to the calling context.    @retval EFI_SUCCESS           All outstanding requests were successfully terminated.   @retval EFI_DEVICE_ERROR      The device reported an error while performing the cancel                                 operation. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_DISK_CANCEL_EX
function_decl|)
parameter_list|(
name|IN
name|EFI_DISK_IO2_PROTOCOL
modifier|*
name|This
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Reads a specified number of bytes from a device.    @param This                   Indicates a pointer to the calling context.   @param MediaId                ID of the medium to be read.   @param Offset                 The starting byte offset on the logical block I/O device to read from.   @param Token                  A pointer to the token associated with the transaction.                                 If this field is NULL, synchronous/blocking IO is performed.   @param  BufferSize            The size in bytes of Buffer. The number of bytes to read from the device.   @param  Buffer                A pointer to the destination buffer for the data.                                 The caller is responsible either having implicit or explicit ownership of the buffer.    @retval EFI_SUCCESS           If Event is NULL (blocking I/O): The data was read correctly from the device.                                 If Event is not NULL (asynchronous I/O): The request was successfully queued for processing.                                                                          Event will be signaled upon completion.   @retval EFI_DEVICE_ERROR      The device reported an error while performing the write.   @retval EFI_NO_MEDIA          There is no medium in the device.   @retval EFI_MEDIA_CHNAGED     The MediaId is not for the current medium.   @retval EFI_INVALID_PARAMETER The read request contains device addresses that are not valid for the device.   @retval EFI_OUT_OF_RESOURCES  The request could not be completed due to a lack of resources.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_DISK_READ_EX
function_decl|)
parameter_list|(
name|IN
name|EFI_DISK_IO2_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINT32
name|MediaId
parameter_list|,
name|IN
name|UINT64
name|Offset
parameter_list|,
name|IN
name|OUT
name|EFI_DISK_IO2_TOKEN
modifier|*
name|Token
parameter_list|,
name|IN
name|UINTN
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
comment|/**   Writes a specified number of bytes to a device.    @param This        Indicates a pointer to the calling context.   @param MediaId     ID of the medium to be written.   @param Offset      The starting byte offset on the logical block I/O device to write to.   @param Token       A pointer to the token associated with the transaction.                      If this field is NULL, synchronous/blocking IO is performed.   @param BufferSize  The size in bytes of Buffer. The number of bytes to write to the device.   @param Buffer      A pointer to the buffer containing the data to be written.    @retval EFI_SUCCESS           If Event is NULL (blocking I/O): The data was written correctly to the device.                                 If Event is not NULL (asynchronous I/O): The request was successfully queued for processing.                                                                          Event will be signaled upon completion.   @retval EFI_WRITE_PROTECTED   The device cannot be written to.   @retval EFI_DEVICE_ERROR      The device reported an error while performing the write operation.   @retval EFI_NO_MEDIA          There is no medium in the device.   @retval EFI_MEDIA_CHNAGED     The MediaId is not for the current medium.   @retval EFI_INVALID_PARAMETER The write request contains device addresses that are not valid for the device.   @retval EFI_OUT_OF_RESOURCES  The request could not be completed due to a lack of resources.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_DISK_WRITE_EX
function_decl|)
parameter_list|(
name|IN
name|EFI_DISK_IO2_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINT32
name|MediaId
parameter_list|,
name|IN
name|UINT64
name|Offset
parameter_list|,
name|IN
name|OUT
name|EFI_DISK_IO2_TOKEN
modifier|*
name|Token
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
comment|/**   Flushes all modified data to the physical device.    @param This        Indicates a pointer to the calling context.   @param MediaId     ID of the medium to be written.   @param Token       A pointer to the token associated with the transaction.                      If this field is NULL, synchronous/blocking IO is performed.    @retval EFI_SUCCESS           If Event is NULL (blocking I/O): The data was flushed successfully to the device.                                 If Event is not NULL (asynchronous I/O): The request was successfully queued for processing.                                                                          Event will be signaled upon completion.   @retval EFI_WRITE_PROTECTED   The device cannot be written to.   @retval EFI_DEVICE_ERROR      The device reported an error while performing the write operation.   @retval EFI_NO_MEDIA          There is no medium in the device.   @retval EFI_MEDIA_CHNAGED     The MediaId is not for the current medium.   @retval EFI_OUT_OF_RESOURCES  The request could not be completed due to a lack of resources. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_DISK_FLUSH_EX
function_decl|)
parameter_list|(
name|IN
name|EFI_DISK_IO2_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|OUT
name|EFI_DISK_IO2_TOKEN
modifier|*
name|Token
parameter_list|)
function_decl|;
end_typedef

begin_define
define|#
directive|define
name|EFI_DISK_IO2_PROTOCOL_REVISION
value|0x00020000
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// This protocol is used to abstract Block I/O interfaces.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_DISK_IO2_PROTOCOL
block|{
comment|///
comment|/// The revision to which the disk I/O interface adheres. All future
comment|/// revisions must be backwards compatible. If a future version is not
comment|/// backwards compatible, it is not the same GUID.
comment|///
name|UINT64
name|Revision
decl_stmt|;
name|EFI_DISK_CANCEL_EX
name|Cancel
decl_stmt|;
name|EFI_DISK_READ_EX
name|ReadDiskEx
decl_stmt|;
name|EFI_DISK_WRITE_EX
name|WriteDiskEx
decl_stmt|;
name|EFI_DISK_FLUSH_EX
name|FlushDiskEx
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiDiskIo2ProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

