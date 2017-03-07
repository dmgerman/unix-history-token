begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   This file declares the SMBus definitions defined in SmBus Specifciation V2.0   and defined in PI1.0 specification volume 5.    Copyright (c) 2007 - 2008, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.               **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SMBUS_H_
end_ifndef

begin_define
define|#
directive|define
name|_SMBUS_H_
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// UDID of SMBUS device.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|VendorSpecificId
decl_stmt|;
name|UINT16
name|SubsystemDeviceId
decl_stmt|;
name|UINT16
name|SubsystemVendorId
decl_stmt|;
name|UINT16
name|Interface
decl_stmt|;
name|UINT16
name|DeviceId
decl_stmt|;
name|UINT16
name|VendorId
decl_stmt|;
name|UINT8
name|VendorRevision
decl_stmt|;
name|UINT8
name|DeviceCapabilities
decl_stmt|;
block|}
name|EFI_SMBUS_UDID
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Smbus Device Address
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The SMBUS hardware address to which the SMBUS device is preassigned or allocated.
comment|///
name|UINTN
name|SmbusDeviceAddress
range|:
literal|7
decl_stmt|;
block|}
name|EFI_SMBUS_DEVICE_ADDRESS
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The SMBUS hardware address to which the SMBUS device is preassigned or
comment|/// allocated. Type EFI_SMBUS_DEVICE_ADDRESS is defined in EFI_PEI_SMBUS2_PPI.Execute().
comment|///
name|EFI_SMBUS_DEVICE_ADDRESS
name|SmbusDeviceAddress
decl_stmt|;
comment|///
comment|/// The SMBUS Unique Device Identifier (UDID) as defined in EFI_SMBUS_UDID.
comment|/// Type EFI_SMBUS_UDID is defined in EFI_PEI_SMBUS2_PPI.ArpDevice().
comment|///
name|EFI_SMBUS_UDID
name|SmbusDeviceUdid
decl_stmt|;
block|}
name|EFI_SMBUS_DEVICE_MAP
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Smbus Operations
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
name|_EFI_SMBUS_OPERATION
block|{
name|EfiSmbusQuickRead
block|,
name|EfiSmbusQuickWrite
block|,
name|EfiSmbusReceiveByte
block|,
name|EfiSmbusSendByte
block|,
name|EfiSmbusReadByte
block|,
name|EfiSmbusWriteByte
block|,
name|EfiSmbusReadWord
block|,
name|EfiSmbusWriteWord
block|,
name|EfiSmbusReadBlock
block|,
name|EfiSmbusWriteBlock
block|,
name|EfiSmbusProcessCall
block|,
name|EfiSmbusBWBRProcessCall
block|}
name|EFI_SMBUS_OPERATION
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_SMBUS_DEVICE_COMMAND
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|UINTN
name|EFI_SMBUS_DEVICE_COMMAND
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

end_unit

