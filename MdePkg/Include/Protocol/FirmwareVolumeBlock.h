begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   This file provides control over block-oriented firmware devices.  Copyright (c) 2006 - 2011, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under  the terms and conditions of the BSD License that accompanies this distribution.   The full text of the license may be found at http://opensource.org/licenses/bsd-license.php.                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                      WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.                 @par Revision Reference: PI   Version 1.0 and 1.2.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__FIRMWARE_VOLUME_BLOCK_H__
end_ifndef

begin_define
define|#
directive|define
name|__FIRMWARE_VOLUME_BLOCK_H__
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// EFI_FIRMWARE_VOLUME_BLOCK_PROTOCOL is defined in PI 1.0 spec and its GUID value
end_comment

begin_comment
comment|// is later updated to be the same as that of EFI_FIRMWARE_VOLUME_BLOCK2_PROTOCOL
end_comment

begin_comment
comment|// defined in PI 1.2 spec.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_FIRMWARE_VOLUME_BLOCK_PROTOCOL_GUID
define|\
value|{ 0x8f644fa9, 0xe850, 0x4db1, {0x9c, 0xe2, 0xb, 0x44, 0x69, 0x8e, 0x8d, 0xa4 } }
end_define

begin_define
define|#
directive|define
name|EFI_FIRMWARE_VOLUME_BLOCK2_PROTOCOL_GUID
define|\
value|{ 0x8f644fa9, 0xe850, 0x4db1, {0x9c, 0xe2, 0xb, 0x44, 0x69, 0x8e, 0x8d, 0xa4 } }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_FIRMWARE_VOLUME_BLOCK_PROTOCOL
name|EFI_FIRMWARE_VOLUME_BLOCK_PROTOCOL
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|EFI_FIRMWARE_VOLUME_BLOCK_PROTOCOL
name|EFI_FIRMWARE_VOLUME_BLOCK2_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|/**   The GetAttributes() function retrieves the attributes and   current settings of the block.    @param This       Indicates the EFI_FIRMWARE_VOLUME_BLOCK2_PROTOCOL instance.    @param Attributes Pointer to EFI_FVB_ATTRIBUTES_2 in which the                     attributes and current settings are                     returned. Type EFI_FVB_ATTRIBUTES_2 is defined                     in EFI_FIRMWARE_VOLUME_HEADER.    @retval EFI_SUCCESS The firmware volume attributes were                       returned.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_FVB_GET_ATTRIBUTES
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_FIRMWARE_VOLUME_BLOCK2_PROTOCOL
modifier|*
name|This
parameter_list|,
name|OUT
name|EFI_FVB_ATTRIBUTES_2
modifier|*
name|Attributes
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   The SetAttributes() function sets configurable firmware volume   attributes and returns the new settings of the firmware volume.    @param This         Indicates the EFI_FIRMWARE_VOLUME_BLOCK2_PROTOCOL instance.    @param Attributes   On input, Attributes is a pointer to                       EFI_FVB_ATTRIBUTES_2 that contains the                       desired firmware volume settings. On                       successful return, it contains the new                       settings of the firmware volume. Type                       EFI_FVB_ATTRIBUTES_2 is defined in                       EFI_FIRMWARE_VOLUME_HEADER.      @retval EFI_SUCCESS           The firmware volume attributes were returned.    @retval EFI_INVALID_PARAMETER The attributes requested are in                                 conflict with the capabilities                                 as declared in the firmware                                 volume header.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_FVB_SET_ATTRIBUTES
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_FIRMWARE_VOLUME_BLOCK2_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|OUT
name|EFI_FVB_ATTRIBUTES_2
modifier|*
name|Attributes
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   The GetPhysicalAddress() function retrieves the base address of   a memory-mapped firmware volume. This function should be called   only for memory-mapped firmware volumes.    @param This     Indicates the EFI_FIRMWARE_VOLUME_BLOCK2_PROTOCOL instance.      @param Address  Pointer to a caller-allocated                   EFI_PHYSICAL_ADDRESS that, on successful                   return from GetPhysicalAddress(), contains the                   base address of the firmware volume.      @retval EFI_SUCCESS       The firmware volume base address was returned.      @retval EFI_UNSUPPORTED   The firmware volume is not memory mapped.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_FVB_GET_PHYSICAL_ADDRESS
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_FIRMWARE_VOLUME_BLOCK2_PROTOCOL
modifier|*
name|This
parameter_list|,
name|OUT
name|EFI_PHYSICAL_ADDRESS
modifier|*
name|Address
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   The GetBlockSize() function retrieves the size of the requested   block. It also returns the number of additional blocks with   the identical size. The GetBlockSize() function is used to   retrieve the block map (see EFI_FIRMWARE_VOLUME_HEADER).     @param This           Indicates the EFI_FIRMWARE_VOLUME_BLOCK2_PROTOCOL instance.    @param Lba            Indicates the block for which to return the size.    @param BlockSize      Pointer to a caller-allocated UINTN in which                         the size of the block is returned.    @param NumberOfBlocks Pointer to a caller-allocated UINTN in                         which the number of consecutive blocks,                         starting with Lba, is returned. All                         blocks in this range have a size of                         BlockSize.       @retval EFI_SUCCESS             The firmware volume base address was returned.      @retval EFI_INVALID_PARAMETER   The requested LBA is out of range.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_FVB_GET_BLOCK_SIZE
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_FIRMWARE_VOLUME_BLOCK2_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_LBA
name|Lba
parameter_list|,
name|OUT
name|UINTN
modifier|*
name|BlockSize
parameter_list|,
name|OUT
name|UINTN
modifier|*
name|NumberOfBlocks
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Reads the specified number of bytes into a buffer from the specified block.    The Read() function reads the requested number of bytes from the   requested block and stores them in the provided buffer.   Implementations should be mindful that the firmware volume   might be in the ReadDisabled state. If it is in this state,   the Read() function must return the status code   EFI_ACCESS_DENIED without modifying the contents of the   buffer. The Read() function must also prevent spanning block   boundaries. If a read is requested that would span a block   boundary, the read must read up to the boundary but not   beyond. The output parameter NumBytes must be set to correctly   indicate the number of bytes actually read. The caller must be   aware that a read may be partially completed.    @param This     Indicates the EFI_FIRMWARE_VOLUME_BLOCK2_PROTOCOL instance.      @param Lba      The starting logical block index                   from which to read.    @param Offset   Offset into the block at which to begin reading.    @param NumBytes Pointer to a UINTN. At entry, *NumBytes                   contains the total size of the buffer. At                   exit, *NumBytes contains the total number of                   bytes read.    @param Buffer   Pointer to a caller-allocated buffer that will                   be used to hold the data that is read.    @retval EFI_SUCCESS         The firmware volume was read successfully,                               and contents are in Buffer.      @retval EFI_BAD_BUFFER_SIZE Read attempted across an LBA                               boundary. On output, NumBytes                               contains the total number of bytes                               returned in Buffer.      @retval EFI_ACCESS_DENIED   The firmware volume is in the                               ReadDisabled state.      @retval EFI_DEVICE_ERROR    The block device is not                               functioning correctly and could                               not be read.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_FVB_READ
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_FIRMWARE_VOLUME_BLOCK2_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_LBA
name|Lba
parameter_list|,
name|IN
name|UINTN
name|Offset
parameter_list|,
name|IN
name|OUT
name|UINTN
modifier|*
name|NumBytes
parameter_list|,
name|IN
name|OUT
name|UINT8
modifier|*
name|Buffer
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Writes the specified number of bytes from the input buffer to the block.    The Write() function writes the specified number of bytes from   the provided buffer to the specified block and offset. If the   firmware volume is sticky write, the caller must ensure that   all the bits of the specified range to write are in the   EFI_FVB_ERASE_POLARITY state before calling the Write()   function, or else the result will be unpredictable. This   unpredictability arises because, for a sticky-write firmware   volume, a write may negate a bit in the EFI_FVB_ERASE_POLARITY   state but cannot flip it back again.  Before calling the   Write() function,  it is recommended for the caller to first call    the EraseBlocks() function to erase the specified block to   write. A block erase cycle will transition bits from the   (NOT)EFI_FVB_ERASE_POLARITY state back to the   EFI_FVB_ERASE_POLARITY state. Implementations should be   mindful that the firmware volume might be in the WriteDisabled   state. If it is in this state, the Write() function must   return the status code EFI_ACCESS_DENIED without modifying the   contents of the firmware volume. The Write() function must   also prevent spanning block boundaries. If a write is   requested that spans a block boundary, the write must store up   to the boundary but not beyond. The output parameter NumBytes   must be set to correctly indicate the number of bytes actually   written. The caller must be aware that a write may be   partially completed. All writes, partial or otherwise, must be   fully flushed to the hardware before the Write() service   returns.    @param This     Indicates the EFI_FIRMWARE_VOLUME_BLOCK2_PROTOCOL instance.      @param Lba      The starting logical block index to write to.      @param Offset   Offset into the block at which to begin writing.      @param NumBytes The pointer to a UINTN. At entry, *NumBytes                   contains the total size of the buffer. At                   exit, *NumBytes contains the total number of                   bytes actually written.      @param Buffer   The pointer to a caller-allocated buffer that                   contains the source for the write.      @retval EFI_SUCCESS         The firmware volume was written successfully.      @retval EFI_BAD_BUFFER_SIZE The write was attempted across an                               LBA boundary. On output, NumBytes                               contains the total number of bytes                               actually written.      @retval EFI_ACCESS_DENIED   The firmware volume is in the                               WriteDisabled state.      @retval EFI_DEVICE_ERROR    The block device is malfunctioning                               and could not be written.   **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_FVB_WRITE
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_FIRMWARE_VOLUME_BLOCK2_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_LBA
name|Lba
parameter_list|,
name|IN
name|UINTN
name|Offset
parameter_list|,
name|IN
name|OUT
name|UINTN
modifier|*
name|NumBytes
parameter_list|,
name|IN
name|UINT8
modifier|*
name|Buffer
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_LBA_LIST_TERMINATOR
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_LBA_LIST_TERMINATOR
value|0xFFFFFFFFFFFFFFFFULL
end_define

begin_comment
comment|/**   Erases and initializes a firmware volume block.    The EraseBlocks() function erases one or more blocks as denoted   by the variable argument list. The entire parameter list of   blocks must be verified before erasing any blocks. If a block is   requested that does not exist within the associated firmware   volume (it has a larger index than the last block of the   firmware volume), the EraseBlocks() function must return the   status code EFI_INVALID_PARAMETER without modifying the contents   of the firmware volume. Implementations should be mindful that   the firmware volume might be in the WriteDisabled state. If it   is in this state, the EraseBlocks() function must return the   status code EFI_ACCESS_DENIED without modifying the contents of   the firmware volume. All calls to EraseBlocks() must be fully   flushed to the hardware before the EraseBlocks() service   returns.    @param This   Indicates the EFI_FIRMWARE_VOLUME_BLOCK2_PROTOCOL                 instance.    @param ...    The variable argument list is a list of tuples.                 Each tuple describes a range of LBAs to erase                 and consists of the following:                 - An EFI_LBA that indicates the starting LBA                 - A UINTN that indicates the number of blocks to                   erase.                  The list is terminated with an                 EFI_LBA_LIST_TERMINATOR. For example, the                 following indicates that two ranges of blocks                 (5-7 and 10-11) are to be erased: EraseBlocks                 (This, 5, 3, 10, 2, EFI_LBA_LIST_TERMINATOR);    @retval EFI_SUCCESS The erase request successfully                       completed.      @retval EFI_ACCESS_DENIED   The firmware volume is in the                               WriteDisabled state.   @retval EFI_DEVICE_ERROR  The block device is not functioning                             correctly and could not be written.                             The firmware device may have been                             partially erased.   @retval EFI_INVALID_PARAMETER One or more of the LBAs listed                                 in the variable argument list do                                 not exist in the firmware volume.    **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_FVB_ERASE_BLOCKS
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_FIRMWARE_VOLUME_BLOCK2_PROTOCOL
modifier|*
name|This
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The Firmware Volume Block Protocol is the low-level interface
end_comment

begin_comment
comment|/// to a firmware volume. File-level access to a firmware volume
end_comment

begin_comment
comment|/// should not be done using the Firmware Volume Block Protocol.
end_comment

begin_comment
comment|/// Normal access to a firmware volume must use the Firmware
end_comment

begin_comment
comment|/// Volume Protocol. Typically, only the file system driver that
end_comment

begin_comment
comment|/// produces the Firmware Volume Protocol will bind to the
end_comment

begin_comment
comment|/// Firmware Volume Block Protocol.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_FIRMWARE_VOLUME_BLOCK_PROTOCOL
block|{
name|EFI_FVB_GET_ATTRIBUTES
name|GetAttributes
decl_stmt|;
name|EFI_FVB_SET_ATTRIBUTES
name|SetAttributes
decl_stmt|;
name|EFI_FVB_GET_PHYSICAL_ADDRESS
name|GetPhysicalAddress
decl_stmt|;
name|EFI_FVB_GET_BLOCK_SIZE
name|GetBlockSize
decl_stmt|;
name|EFI_FVB_READ
name|Read
decl_stmt|;
name|EFI_FVB_WRITE
name|Write
decl_stmt|;
name|EFI_FVB_ERASE_BLOCKS
name|EraseBlocks
decl_stmt|;
comment|///
comment|/// The handle of the parent firmware volume.
comment|///
name|EFI_HANDLE
name|ParentHandle
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiFirmwareVolumeBlockProtocolGuid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiFirmwareVolumeBlock2ProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

