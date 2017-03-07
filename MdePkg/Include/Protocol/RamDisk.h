begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   This file defines the EFI RAM Disk Protocol.    Copyright (c) 2016, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.    @par Revision Reference:   This Protocol is introduced in UEFI Specification 2.6  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__RAM_DISK_PROTOCOL_H__
end_ifndef

begin_define
define|#
directive|define
name|__RAM_DISK_PROTOCOL_H__
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// EFI RAM Disk Protocol GUID value
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_RAM_DISK_PROTOCOL_GUID
define|\
value|{ 0xab38a0df, 0x6873, 0x44a9, { 0x87, 0xe6, 0xd4, 0xeb, 0x56, 0x14, 0x84, 0x49 }};
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Forward reference for pure ANSI compatability
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
name|struct
name|_EFI_RAM_DISK_PROTOCOL
name|EFI_RAM_DISK_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|/**   Register a RAM disk with specified address, size and type.    @param[in]  RamDiskBase    The base address of registered RAM disk.   @param[in]  RamDiskSize    The size of registered RAM disk.   @param[in]  RamDiskType    The type of registered RAM disk. The GUID can be                              any of the values defined in section 9.3.6.9, or a                              vendor defined GUID.   @param[in]  ParentDevicePath                              Pointer to the parent device path. If there is no                              parent device path then ParentDevicePath is NULL.   @param[out] DevicePath     On return, points to a pointer to the device path                              of the RAM disk device.                              If ParentDevicePath is not NULL, the returned                              DevicePath is created by appending a RAM disk node                              to the parent device path. If ParentDevicePath is                              NULL, the returned DevicePath is a RAM disk device                              path without appending. This function is                              responsible for allocating the buffer DevicePath                              with the boot service AllocatePool().    @retval EFI_SUCCESS             The RAM disk is registered successfully.   @retval EFI_INVALID_PARAMETER   DevicePath or RamDiskType is NULL.                                   RamDiskSize is 0.   @retval EFI_ALREADY_STARTED     A Device Path Protocol instance to be created                                   is already present in the handle database.   @retval EFI_OUT_OF_RESOURCES    The RAM disk register operation fails due to                                   resource limitation.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_RAM_DISK_REGISTER_RAMDISK
function_decl|)
parameter_list|(
name|IN
name|UINT64
name|RamDiskBase
parameter_list|,
name|IN
name|UINT64
name|RamDiskSize
parameter_list|,
name|IN
name|EFI_GUID
modifier|*
name|RamDiskType
parameter_list|,
name|IN
name|EFI_DEVICE_PATH
modifier|*
name|ParentDevicePath
name|OPTIONAL
parameter_list|,
name|OUT
name|EFI_DEVICE_PATH_PROTOCOL
modifier|*
modifier|*
name|DevicePath
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Unregister a RAM disk specified by DevicePath.    @param[in] DevicePath      A pointer to the device path that describes a RAM                              Disk device.    @retval EFI_SUCCESS             The RAM disk is unregistered successfully.   @retval EFI_INVALID_PARAMETER   DevicePath is NULL.   @retval EFI_UNSUPPORTED         The device specified by DevicePath is not a                                   valid ramdisk device path and not supported                                   by the driver.   @retval EFI_NOT_FOUND           The RAM disk pointed by DevicePath doesn't                                   exist.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_RAM_DISK_UNREGISTER_RAMDISK
function_decl|)
parameter_list|(
name|IN
name|EFI_DEVICE_PATH_PROTOCOL
modifier|*
name|DevicePath
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// RAM Disk Protocol structure.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_RAM_DISK_PROTOCOL
block|{
name|EFI_RAM_DISK_REGISTER_RAMDISK
name|Register
decl_stmt|;
name|EFI_RAM_DISK_UNREGISTER_RAMDISK
name|Unregister
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|///
end_comment

begin_comment
comment|/// RAM Disk Protocol GUID variable.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiRamDiskProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

