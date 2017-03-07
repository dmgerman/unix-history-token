begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Guid& data structure used for Delivering Capsules Containing Updates to Firmware   Management Protocol    Copyright (c) 2013 - 2015, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.    @par Revision Reference:   GUIDs defined in UEFI 2.4 spec.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_FMP_CAPSULE_GUID_H__
end_ifndef

begin_define
define|#
directive|define
name|_FMP_CAPSULE_GUID_H__
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// This is the GUID of the capsule for Firmware Management Protocol.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_FIRMWARE_MANAGEMENT_CAPSULE_ID_GUID
define|\
value|{ \     0x6dcbd5ed, 0xe82d, 0x4c44, {0xbd, 0xa1, 0x71, 0x94, 0x19, 0x9a, 0xd9, 0x2a } \   }
end_define

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|1
name|)
end_pragma

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|Version
decl_stmt|;
comment|///
comment|/// The number of drivers included in the capsule and the number of corresponding
comment|/// offsets stored in ItemOffsetList array.
comment|///
name|UINT16
name|EmbeddedDriverCount
decl_stmt|;
comment|///
comment|/// The number of payload items included in the capsule and the number of
comment|/// corresponding offsets stored in the ItemOffsetList array.
comment|///
name|UINT16
name|PayloadItemCount
decl_stmt|;
comment|///
comment|/// Variable length array of dimension [EmbeddedDriverCount + PayloadItemCount]
comment|/// containing offsets of each of the drivers and payload items contained within the capsule
comment|///
comment|// UINT64 ItemOffsetList[];
block|}
name|EFI_FIRMWARE_MANAGEMENT_CAPSULE_HEADER
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|Version
decl_stmt|;
comment|///
comment|/// Used to identify device firmware targeted by this update. This guid is matched by
comment|/// system firmware against ImageTypeId field within a EFI_FIRMWARE_IMAGE_DESCRIPTOR
comment|///
name|EFI_GUID
name|UpdateImageTypeId
decl_stmt|;
comment|///
comment|/// Passed as ImageIndex in call to EFI_FIRMWARE_MANAGEMENT_PROTOCOL.SetImage()
comment|///
name|UINT8
name|UpdateImageIndex
decl_stmt|;
name|UINT8
name|reserved_bytes
index|[
literal|3
index|]
decl_stmt|;
comment|///
comment|/// Size of the binary update image which immediately follows this structure
comment|///
name|UINT32
name|UpdateImageSize
decl_stmt|;
comment|///
comment|/// Size of the VendorCode bytes which optionally immediately follow binary update image in the capsule
comment|///
name|UINT32
name|UpdateVendorCodeSize
decl_stmt|;
comment|///
comment|/// The HardwareInstance to target with this update. If value is zero it means match all
comment|/// HardwareInstances. This field allows update software to target only a single device in
comment|/// cases where there are more than one device with the same ImageTypeId GUID.
comment|/// This header is outside the signed data of the Authentication Info structure and
comment|/// therefore can be modified without changing the Auth data.
comment|///
name|UINT64
name|UpdateHardwareInstance
decl_stmt|;
block|}
name|EFI_FIRMWARE_MANAGEMENT_CAPSULE_IMAGE_HEADER
typedef|;
end_typedef

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_define
define|#
directive|define
name|EFI_FIRMWARE_MANAGEMENT_CAPSULE_HEADER_INIT_VERSION
value|0x00000001
end_define

begin_define
define|#
directive|define
name|EFI_FIRMWARE_MANAGEMENT_CAPSULE_IMAGE_HEADER_INIT_VERSION
value|0x00000002
end_define

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiFmpCapsuleGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

