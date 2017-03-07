begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Provides the services required to access a block I/O device during PEI recovery    boot mode.    The Recovery Module PPI and the Device Recovery Module PPI are device neutral.    This PPI is device specific and addresses the most common form of recovery    media-block I/O devices such as legacy floppy, CD-ROM, or IDE devices.    The Recovery Block I/O PPI is used to access block devices. Because the Recovery    Block I/O PPIs that are provided by the PEI ATAPI driver and PEI legacy floppy    driver are the same, here we define a set of general PPIs for both drivers to use.    Copyright (c) 2007 - 2015, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under  the terms and conditions of the BSD License that accompanies this distribution.   The full text of the license may be found at http://opensource.org/licenses/bsd-license.php.                                              THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                      WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.    @par Revision Reference:   This PPI is defined in UEFI Platform Initialization Specification 1.2 Volume 1:    Pre-EFI Initalization Core Interface.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PEI_BLOCK_IO_H_
end_ifndef

begin_define
define|#
directive|define
name|_PEI_BLOCK_IO_H_
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Global ID for EFI_PEI_RECOVERY_BLOCK_IO_PPI
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_PEI_RECOVERY_BLOCK_IO_PPI_GUID
define|\
value|{ \     0x695d8aa1, 0x42ee, 0x4c46, { 0x80, 0x5c, 0x6e, 0xa6, 0xbc, 0xe7, 0x99, 0xe3 } \   }
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// The forward declaration for EFI_PEI_RECOVERY_BLOCK_IO_PPI.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|struct
name|_EFI_PEI_RECOVERY_BLOCK_IO_PPI
name|EFI_PEI_RECOVERY_BLOCK_IO_PPI
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// All blocks on the recovery device are addressed with a 64-bit Logical Block Address (LBA).
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|UINT64
name|EFI_PEI_LBA
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_PEI_BLOCK_DEVICE_TYPE
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|LegacyFloppy
init|=
literal|0
block|,
comment|///< The recovery device is a floppy.
name|IdeCDROM
init|=
literal|1
block|,
comment|///< The recovery device is an IDE CD-ROM
name|IdeLS120
init|=
literal|2
block|,
comment|///< The recovery device is an IDE LS-120
name|UsbMassStorage
init|=
literal|3
block|,
comment|///< The recovery device is a USB Mass Storage device
name|SD
init|=
literal|4
block|,
comment|///< The recovery device is a Secure Digital device
name|EMMC
init|=
literal|5
block|,
comment|///< The recovery device is a eMMC device
name|UfsDevice
init|=
literal|6
block|,
comment|///< The recovery device is a Universal Flash Storage device
name|MaxDeviceType
block|}
name|EFI_PEI_BLOCK_DEVICE_TYPE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Specification inconsistency here:
end_comment

begin_comment
comment|/// PEI_BLOCK_IO_MEDIA has been changed to EFI_PEI_BLOCK_IO_MEDIA.
end_comment

begin_comment
comment|/// Inconsistency exists in UEFI Platform Initialization Specification 1.2
end_comment

begin_comment
comment|/// Volume 1: Pre-EFI Initalization Core Interface, where all referrences to
end_comment

begin_comment
comment|/// this structure name are with the "EFI_" prefix, except for the definition
end_comment

begin_comment
comment|/// which is without "EFI_".  So the name of PEI_BLOCK_IO_MEDIA is taken as the
end_comment

begin_comment
comment|/// exception, and EFI_PEI_BLOCK_IO_MEDIA is used to comply with most of
end_comment

begin_comment
comment|/// the specification.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The type of media device being referenced by DeviceIndex.
comment|///
name|EFI_PEI_BLOCK_DEVICE_TYPE
name|DeviceType
decl_stmt|;
comment|///
comment|/// A flag that indicates if media is present. This flag is always set for
comment|/// nonremovable media devices.
comment|///
name|BOOLEAN
name|MediaPresent
decl_stmt|;
comment|///
comment|/// The last logical block that the device supports.
comment|///
name|UINTN
name|LastBlock
decl_stmt|;
comment|///
comment|/// The size of a logical block in bytes.
comment|///
name|UINTN
name|BlockSize
decl_stmt|;
block|}
name|EFI_PEI_BLOCK_IO_MEDIA
typedef|;
end_typedef

begin_comment
comment|/**   Gets the count of block I/O devices that one specific block driver detects.    This function is used for getting the count of block I/O devices that one    specific block driver detects.  To the PEI ATAPI driver, it returns the number   of all the detected ATAPI devices it detects during the enumeration process.    To the PEI legacy floppy driver, it returns the number of all the legacy    devices it finds during its enumeration process. If no device is detected,    then the function will return zero.        @param[in]  PeiServices          General-purpose services that are available                                     to every PEIM.   @param[in]  This                 Indicates the EFI_PEI_RECOVERY_BLOCK_IO_PPI                                     instance.   @param[out] NumberBlockDevices   The number of block I/O devices discovered.    @retval     EFI_SUCCESS          The operation performed successfully.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PEI_GET_NUMBER_BLOCK_DEVICES
function_decl|)
parameter_list|(
name|IN
name|EFI_PEI_SERVICES
modifier|*
modifier|*
name|PeiServices
parameter_list|,
name|IN
name|EFI_PEI_RECOVERY_BLOCK_IO_PPI
modifier|*
name|This
parameter_list|,
name|OUT
name|UINTN
modifier|*
name|NumberBlockDevices
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Gets a block device's media information.    This function will provide the caller with the specified block device's media    information. If the media changes, calling this function will update the media    information accordingly.    @param[in]  PeiServices   General-purpose services that are available to every                             PEIM   @param[in]  This          Indicates the EFI_PEI_RECOVERY_BLOCK_IO_PPI instance.   @param[in]  DeviceIndex   Specifies the block device to which the function wants                              to talk. Because the driver that implements Block I/O                              PPIs will manage multiple block devices, the PPIs that                              want to talk to a single device must specify the                              device index that was assigned during the enumeration                             process. This index is a number from one to                              NumberBlockDevices.   @param[out] MediaInfo     The media information of the specified block media.                               The caller is responsible for the ownership of this                              data structure.    @par Note:        The MediaInfo structure describes an enumeration of possible block device        types.  This enumeration exists because no device paths are actually passed        across interfaces that describe the type or class of hardware that is publishing        the block I/O interface. This enumeration will allow for policy decisions       in the Recovery PEIM, such as "Try to recover from legacy floppy first,        LS-120 second, CD-ROM third." If there are multiple partitions abstracted        by a given device type, they should be reported in ascending order; this        order also applies to nested partitions, such as legacy MBR, where the        outermost partitions would have precedence in the reporting order. The        same logic applies to systems such as IDE that have precedence relationships        like "Master/Slave" or "Primary/Secondary". The master device should be        reported first, the slave second.      @retval EFI_SUCCESS        Media information about the specified block device                               was obtained successfully.   @retval EFI_DEVICE_ERROR   Cannot get the media information due to a hardware                               error.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PEI_GET_DEVICE_MEDIA_INFORMATION
function_decl|)
parameter_list|(
name|IN
name|EFI_PEI_SERVICES
modifier|*
modifier|*
name|PeiServices
parameter_list|,
name|IN
name|EFI_PEI_RECOVERY_BLOCK_IO_PPI
modifier|*
name|This
parameter_list|,
name|IN
name|UINTN
name|DeviceIndex
parameter_list|,
name|OUT
name|EFI_PEI_BLOCK_IO_MEDIA
modifier|*
name|MediaInfo
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Reads the requested number of blocks from the specified block device.    The function reads the requested number of blocks from the device. All the    blocks are read, or an error is returned. If there is no media in the device,   the function returns EFI_NO_MEDIA.    @param[in]  PeiServices   General-purpose services that are available to                              every PEIM.   @param[in]  This          Indicates the EFI_PEI_RECOVERY_BLOCK_IO_PPI instance.   @param[in]  DeviceIndex   Specifies the block device to which the function wants                              to talk. Because the driver that implements Block I/O                              PPIs will manage multiple block devices, PPIs that                              want to talk to a single device must specify the device                              index that was assigned during the enumeration process.                              This index is a number from one to NumberBlockDevices.   @param[in]  StartLBA      The starting logical block address (LBA) to read from                             on the device   @param[in]  BufferSize    The size of the Buffer in bytes. This number must be                             a multiple of the intrinsic block size of the device.   @param[out] Buffer        A pointer to the destination buffer for the data.                             The caller is responsible for the ownership of the                              buffer.                             @retval EFI_SUCCESS             The data was read correctly from the device.   @retval EFI_DEVICE_ERROR        The device reported an error while attempting                                    to perform the read operation.   @retval EFI_INVALID_PARAMETER   The read request contains LBAs that are not                                    valid, or the buffer is not properly aligned.   @retval EFI_NO_MEDIA            There is no media in the device.   @retval EFI_BAD_BUFFER_SIZE     The BufferSize parameter is not a multiple of                                   the intrinsic block size of the device.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PEI_READ_BLOCKS
function_decl|)
parameter_list|(
name|IN
name|EFI_PEI_SERVICES
modifier|*
modifier|*
name|PeiServices
parameter_list|,
name|IN
name|EFI_PEI_RECOVERY_BLOCK_IO_PPI
modifier|*
name|This
parameter_list|,
name|IN
name|UINTN
name|DeviceIndex
parameter_list|,
name|IN
name|EFI_PEI_LBA
name|StartLBA
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
comment|///
end_comment

begin_comment
comment|///  EFI_PEI_RECOVERY_BLOCK_IO_PPI provides the services that are required
end_comment

begin_comment
comment|///  to access a block I/O device during PEI recovery boot mode.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_PEI_RECOVERY_BLOCK_IO_PPI
block|{
comment|///
comment|/// Gets the number of block I/O devices that the specific block driver manages.
comment|///
name|EFI_PEI_GET_NUMBER_BLOCK_DEVICES
name|GetNumberOfBlockDevices
decl_stmt|;
comment|///
comment|/// Gets the specified media information.
comment|///
name|EFI_PEI_GET_DEVICE_MEDIA_INFORMATION
name|GetBlockDeviceMediaInfo
decl_stmt|;
comment|///
comment|/// Reads the requested number of blocks from the specified block device.
comment|///
name|EFI_PEI_READ_BLOCKS
name|ReadBlocks
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiPeiVirtualBlockIoPpiGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

