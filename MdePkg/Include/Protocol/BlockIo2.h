begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Block IO2 protocol as defined in the UEFI 2.3.1 specification.    The Block IO2 protocol defines an extension to the Block IO protocol which   enables the ability to read and write data at a block level in a non-blocking   manner.    Copyright (c) 2011, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.               **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__BLOCK_IO2_H__
end_ifndef

begin_define
define|#
directive|define
name|__BLOCK_IO2_H__
end_define

begin_include
include|#
directive|include
file|<Protocol/BlockIo.h>
end_include

begin_define
define|#
directive|define
name|EFI_BLOCK_IO2_PROTOCOL_GUID
define|\
value|{ \     0xa77b2472, 0xe282, 0x4e9f, {0xa2, 0x45, 0xc2, 0xc0, 0xe2, 0x7b, 0xbc, 0xc1} \   }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_BLOCK_IO2_PROTOCOL
name|EFI_BLOCK_IO2_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|/**   The struct of Block IO2 Token. **/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// If Event is NULL, then blocking I/O is performed.If Event is not NULL and
comment|/// non-blocking I/O is supported, then non-blocking I/O is performed, and
comment|/// Event will be signaled when the read request is completed.
comment|///
name|EFI_EVENT
name|Event
decl_stmt|;
comment|///
comment|/// Defines whether or not the signaled event encountered an error.
comment|///
name|EFI_STATUS
name|TransactionStatus
decl_stmt|;
block|}
name|EFI_BLOCK_IO2_TOKEN
typedef|;
end_typedef

begin_comment
comment|/**   Reset the block device hardware.    @param[in]  This                 Indicates a pointer to the calling context.   @param[in]  ExtendedVerification Indicates that the driver may perform a more                                    exhausive verification operation of the device                                    during reset.    @retval EFI_SUCCESS          The device was reset.   @retval EFI_DEVICE_ERROR     The device is not functioning properly and could                                not be reset.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_BLOCK_RESET_EX
function_decl|)
parameter_list|(
name|IN
name|EFI_BLOCK_IO2_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|BOOLEAN
name|ExtendedVerification
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Read BufferSize bytes from Lba into Buffer.      This function reads the requested number of blocks from the device. All the   blocks are read, or an error is returned.   If EFI_DEVICE_ERROR, EFI_NO_MEDIA,_or EFI_MEDIA_CHANGED is returned and   non-blocking I/O is being used, the Event associated with this request will   not be signaled.    @param[in]       This       Indicates a pointer to the calling context.   @param[in]       MediaId    Id of the media, changes every time the media is                                replaced.   @param[in]       Lba        The starting Logical Block Address to read from.   @param[in, out]  Token	    A pointer to the token associated with the transaction.   @param[in]       BufferSize Size of Buffer, must be a multiple of device block size.     @param[out]      Buffer     A pointer to the destination buffer for the data. The                                caller is responsible for either having implicit or                                explicit ownership of the buffer.    @retval EFI_SUCCESS           The read request was queued if Token->Event is                                 not NULL.The data was read correctly from the                                 device if the Token->Event is NULL.   @retval EFI_DEVICE_ERROR      The device reported an error while performing                                 the read.   @retval EFI_NO_MEDIA          There is no media in the device.   @retval EFI_MEDIA_CHANGED     The MediaId is not for the current media.   @retval EFI_BAD_BUFFER_SIZE   The BufferSize parameter is not a multiple of the                                 intrinsic block size of the device.   @retval EFI_INVALID_PARAMETER The read request contains LBAs that are not valid,                                  or the buffer is not on proper alignment.   @retval EFI_OUT_OF_RESOURCES  The request could not be completed due to a lack                                 of resources. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_BLOCK_READ_EX
function_decl|)
parameter_list|(
name|IN
name|EFI_BLOCK_IO2_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINT32
name|MediaId
parameter_list|,
name|IN
name|EFI_LBA
name|LBA
parameter_list|,
name|IN
name|OUT
name|EFI_BLOCK_IO2_TOKEN
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
comment|/**   Write BufferSize bytes from Lba into Buffer.    This function writes the requested number of blocks to the device. All blocks   are written, or an error is returned.If EFI_DEVICE_ERROR, EFI_NO_MEDIA,   EFI_WRITE_PROTECTED or EFI_MEDIA_CHANGED is returned and non-blocking I/O is   being used, the Event associated with this request will not be signaled.    @param[in]       This       Indicates a pointer to the calling context.   @param[in]       MediaId    The media ID that the write request is for.   @param[in]       Lba        The starting logical block address to be written. The                               caller is responsible for writing to only legitimate                               locations.   @param[in, out]  Token      A pointer to the token associated with the transaction.   @param[in]       BufferSize Size of Buffer, must be a multiple of device block size.   @param[in]       Buffer     A pointer to the source buffer for the data.    @retval EFI_SUCCESS           The write request was queued if Event is not NULL.                                 The data was written correctly to the device if                                 the Event is NULL.   @retval EFI_WRITE_PROTECTED   The device can not be written to.   @retval EFI_NO_MEDIA          There is no media in the device.   @retval EFI_MEDIA_CHNAGED     The MediaId does not matched the current device.   @retval EFI_DEVICE_ERROR      The device reported an error while performing the write.   @retval EFI_BAD_BUFFER_SIZE   The Buffer was not a multiple of the block size of the device.   @retval EFI_INVALID_PARAMETER The write request contains LBAs that are not valid,                                  or the buffer is not on proper alignment.   @retval EFI_OUT_OF_RESOURCES  The request could not be completed due to a lack                                 of resources.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_BLOCK_WRITE_EX
function_decl|)
parameter_list|(
name|IN
name|EFI_BLOCK_IO2_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINT32
name|MediaId
parameter_list|,
name|IN
name|EFI_LBA
name|LBA
parameter_list|,
name|IN
name|OUT
name|EFI_BLOCK_IO2_TOKEN
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
comment|/**   Flush the Block Device.     If EFI_DEVICE_ERROR, EFI_NO_MEDIA,_EFI_WRITE_PROTECTED or EFI_MEDIA_CHANGED   is returned and non-blocking I/O is being used, the Event associated with   this request will not be signaled.      @param[in]      This     Indicates a pointer to the calling context.   @param[in,out]  Token    A pointer to the token associated with the transaction    @retval EFI_SUCCESS          The flush request was queued if Event is not NULL.                                All outstanding data was written correctly to the                                device if the Event is NULL.   @retval EFI_DEVICE_ERROR     The device reported an error while writting back                                the data.   @retval EFI_WRITE_PROTECTED  The device cannot be written to.   @retval EFI_NO_MEDIA         There is no media in the device.   @retval EFI_MEDIA_CHANGED    The MediaId is not for the current media.   @retval EFI_OUT_OF_RESOURCES The request could not be completed due to a lack                                of resources.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_BLOCK_FLUSH_EX
function_decl|)
parameter_list|(
name|IN
name|EFI_BLOCK_IO2_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|OUT
name|EFI_BLOCK_IO2_TOKEN
modifier|*
name|Token
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|///  The Block I/O2 protocol defines an extension to the Block I/O protocol which
end_comment

begin_comment
comment|///  enables the ability to read and write data at a block level in a non-blocking
end_comment

begin_comment
comment|//   manner.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_BLOCK_IO2_PROTOCOL
block|{
comment|///
comment|/// A pointer to the EFI_BLOCK_IO_MEDIA data for this device.
comment|/// Type EFI_BLOCK_IO_MEDIA is defined in BlockIo.h.
comment|///
name|EFI_BLOCK_IO_MEDIA
modifier|*
name|Media
decl_stmt|;
name|EFI_BLOCK_RESET_EX
name|Reset
decl_stmt|;
name|EFI_BLOCK_READ_EX
name|ReadBlocksEx
decl_stmt|;
name|EFI_BLOCK_WRITE_EX
name|WriteBlocksEx
decl_stmt|;
name|EFI_BLOCK_FLUSH_EX
name|FlushBlocksEx
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiBlockIo2ProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

