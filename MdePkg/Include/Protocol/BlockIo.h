begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Block IO protocol as defined in the UEFI 2.0 specification.    The Block IO protocol is used to abstract block devices like hard drives,   DVD-ROMs and floppy drives.    Copyright (c) 2006 - 2011, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.               **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__BLOCK_IO_H__
end_ifndef

begin_define
define|#
directive|define
name|__BLOCK_IO_H__
end_define

begin_define
define|#
directive|define
name|EFI_BLOCK_IO_PROTOCOL_GUID
define|\
value|{ \     0x964e5b21, 0x6459, 0x11d2, {0x8e, 0x39, 0x0, 0xa0, 0xc9, 0x69, 0x72, 0x3b } \   }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_BLOCK_IO_PROTOCOL
name|EFI_BLOCK_IO_PROTOCOL
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
name|BLOCK_IO_PROTOCOL
value|EFI_BLOCK_IO_PROTOCOL_GUID
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Protocol defined in EFI1.1.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|EFI_BLOCK_IO_PROTOCOL
name|EFI_BLOCK_IO
typedef|;
end_typedef

begin_comment
comment|/**   Reset the Block Device.    @param  This                 Indicates a pointer to the calling context.   @param  ExtendedVerification Driver may perform diagnostics on reset.    @retval EFI_SUCCESS          The device was reset.   @retval EFI_DEVICE_ERROR     The device is not functioning properly and could                                not be reset.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_BLOCK_RESET
function_decl|)
parameter_list|(
name|IN
name|EFI_BLOCK_IO_PROTOCOL
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
comment|/**   Read BufferSize bytes from Lba into Buffer.    @param  This       Indicates a pointer to the calling context.   @param  MediaId    Id of the media, changes every time the media is replaced.   @param  Lba        The starting Logical Block Address to read from   @param  BufferSize Size of Buffer, must be a multiple of device block size.   @param  Buffer     A pointer to the destination buffer for the data. The caller is                      responsible for either having implicit or explicit ownership of the buffer.    @retval EFI_SUCCESS           The data was read correctly from the device.   @retval EFI_DEVICE_ERROR      The device reported an error while performing the read.   @retval EFI_NO_MEDIA          There is no media in the device.   @retval EFI_MEDIA_CHANGED     The MediaId does not matched the current device.   @retval EFI_BAD_BUFFER_SIZE   The Buffer was not a multiple of the block size of the device.   @retval EFI_INVALID_PARAMETER The read request contains LBAs that are not valid,                                  or the buffer is not on proper alignment.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_BLOCK_READ
function_decl|)
parameter_list|(
name|IN
name|EFI_BLOCK_IO_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINT32
name|MediaId
parameter_list|,
name|IN
name|EFI_LBA
name|Lba
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
comment|/**   Write BufferSize bytes from Lba into Buffer.    @param  This       Indicates a pointer to the calling context.   @param  MediaId    The media ID that the write request is for.   @param  Lba        The starting logical block address to be written. The caller is                      responsible for writing to only legitimate locations.   @param  BufferSize Size of Buffer, must be a multiple of device block size.   @param  Buffer     A pointer to the source buffer for the data.    @retval EFI_SUCCESS           The data was written correctly to the device.   @retval EFI_WRITE_PROTECTED   The device can not be written to.   @retval EFI_DEVICE_ERROR      The device reported an error while performing the write.   @retval EFI_NO_MEDIA          There is no media in the device.   @retval EFI_MEDIA_CHNAGED     The MediaId does not matched the current device.   @retval EFI_BAD_BUFFER_SIZE   The Buffer was not a multiple of the block size of the device.   @retval EFI_INVALID_PARAMETER The write request contains LBAs that are not valid,                                  or the buffer is not on proper alignment.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_BLOCK_WRITE
function_decl|)
parameter_list|(
name|IN
name|EFI_BLOCK_IO_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINT32
name|MediaId
parameter_list|,
name|IN
name|EFI_LBA
name|Lba
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
comment|/**   Flush the Block Device.    @param  This              Indicates a pointer to the calling context.    @retval EFI_SUCCESS       All outstanding data was written to the device   @retval EFI_DEVICE_ERROR  The device reported an error while writting back the data   @retval EFI_NO_MEDIA      There is no media in the device.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_BLOCK_FLUSH
function_decl|)
parameter_list|(
name|IN
name|EFI_BLOCK_IO_PROTOCOL
modifier|*
name|This
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Block IO read only mode data and updated only via members of BlockIO **/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The curent media Id. If the media changes, this value is changed.
comment|///
name|UINT32
name|MediaId
decl_stmt|;
comment|///
comment|/// TRUE if the media is removable; otherwise, FALSE.
comment|///
name|BOOLEAN
name|RemovableMedia
decl_stmt|;
comment|///
comment|/// TRUE if there is a media currently present in the device;
comment|/// othersise, FALSE. THis field shows the media present status
comment|/// as of the most recent ReadBlocks() or WriteBlocks() call.
comment|///
name|BOOLEAN
name|MediaPresent
decl_stmt|;
comment|///
comment|/// TRUE if LBA 0 is the first block of a partition; otherwise
comment|/// FALSE. For media with only one partition this would be TRUE.
comment|///
name|BOOLEAN
name|LogicalPartition
decl_stmt|;
comment|///
comment|/// TRUE if the media is marked read-only otherwise, FALSE.
comment|/// This field shows the read-only status as of the most recent WriteBlocks () call.
comment|///
name|BOOLEAN
name|ReadOnly
decl_stmt|;
comment|///
comment|/// TRUE if the WriteBlock () function caches write data.
comment|///
name|BOOLEAN
name|WriteCaching
decl_stmt|;
comment|///
comment|/// The intrinsic block size of the device. If the media changes, then
comment|/// this field is updated.
comment|///
name|UINT32
name|BlockSize
decl_stmt|;
comment|///
comment|/// Supplies the alignment requirement for any buffer to read or write block(s).
comment|///
name|UINT32
name|IoAlign
decl_stmt|;
comment|///
comment|/// The last logical block address on the device.
comment|/// If the media changes, then this field is updated.
comment|///
name|EFI_LBA
name|LastBlock
decl_stmt|;
comment|///
comment|/// Only present if EFI_BLOCK_IO_PROTOCOL.Revision is greater than or equal to
comment|/// EFI_BLOCK_IO_PROTOCOL_REVISION2. Returns the first LBA is aligned to
comment|/// a physical block boundary.
comment|///
name|EFI_LBA
name|LowestAlignedLba
decl_stmt|;
comment|///
comment|/// Only present if EFI_BLOCK_IO_PROTOCOL.Revision is greater than or equal to
comment|/// EFI_BLOCK_IO_PROTOCOL_REVISION2. Returns the number of logical blocks
comment|/// per physical block.
comment|///
name|UINT32
name|LogicalBlocksPerPhysicalBlock
decl_stmt|;
comment|///
comment|/// Only present if EFI_BLOCK_IO_PROTOCOL.Revision is greater than or equal to
comment|/// EFI_BLOCK_IO_PROTOCOL_REVISION3. Returns the optimal transfer length
comment|/// granularity as a number of logical blocks.
comment|///
name|UINT32
name|OptimalTransferLengthGranularity
decl_stmt|;
block|}
name|EFI_BLOCK_IO_MEDIA
typedef|;
end_typedef

begin_define
define|#
directive|define
name|EFI_BLOCK_IO_PROTOCOL_REVISION
value|0x00010000
end_define

begin_define
define|#
directive|define
name|EFI_BLOCK_IO_PROTOCOL_REVISION2
value|0x00020001
end_define

begin_define
define|#
directive|define
name|EFI_BLOCK_IO_PROTOCOL_REVISION3
value|0x00020031
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Revision defined in EFI1.1.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_BLOCK_IO_INTERFACE_REVISION
value|EFI_BLOCK_IO_PROTOCOL_REVISION
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|///  This protocol provides control over block devices.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_BLOCK_IO_PROTOCOL
block|{
comment|///
comment|/// The revision to which the block IO interface adheres. All future
comment|/// revisions must be backwards compatible. If a future version is not
comment|/// back wards compatible, it is not the same GUID.
comment|///
name|UINT64
name|Revision
decl_stmt|;
comment|///
comment|/// Pointer to the EFI_BLOCK_IO_MEDIA data for this device.
comment|///
name|EFI_BLOCK_IO_MEDIA
modifier|*
name|Media
decl_stmt|;
name|EFI_BLOCK_RESET
name|Reset
decl_stmt|;
name|EFI_BLOCK_READ
name|ReadBlocks
decl_stmt|;
name|EFI_BLOCK_WRITE
name|WriteBlocks
decl_stmt|;
name|EFI_BLOCK_FLUSH
name|FlushBlocks
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiBlockIoProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

