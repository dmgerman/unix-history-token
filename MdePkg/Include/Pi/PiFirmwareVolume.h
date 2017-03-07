begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   The firmware volume related definitions in PI.    Copyright (c) 2006 - 2013, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.    @par Revision Reference:   PI Version 1.3  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PI_FIRMWAREVOLUME_H__
end_ifndef

begin_define
define|#
directive|define
name|__PI_FIRMWAREVOLUME_H__
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_FV_FILE_ATTRIBUTES
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|UINT32
name|EFI_FV_FILE_ATTRIBUTES
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Value of EFI_FV_FILE_ATTRIBUTES.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_FV_FILE_ATTRIB_ALIGNMENT
value|0x0000001F
end_define

begin_define
define|#
directive|define
name|EFI_FV_FILE_ATTRIB_FIXED
value|0x00000100
end_define

begin_define
define|#
directive|define
name|EFI_FV_FILE_ATTRIB_MEMORY_MAPPED
value|0x00000200
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// type of EFI FVB attribute
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|UINT32
name|EFI_FVB_ATTRIBUTES_2
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Attributes bit definitions
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_FVB2_READ_DISABLED_CAP
value|0x00000001
end_define

begin_define
define|#
directive|define
name|EFI_FVB2_READ_ENABLED_CAP
value|0x00000002
end_define

begin_define
define|#
directive|define
name|EFI_FVB2_READ_STATUS
value|0x00000004
end_define

begin_define
define|#
directive|define
name|EFI_FVB2_WRITE_DISABLED_CAP
value|0x00000008
end_define

begin_define
define|#
directive|define
name|EFI_FVB2_WRITE_ENABLED_CAP
value|0x00000010
end_define

begin_define
define|#
directive|define
name|EFI_FVB2_WRITE_STATUS
value|0x00000020
end_define

begin_define
define|#
directive|define
name|EFI_FVB2_LOCK_CAP
value|0x00000040
end_define

begin_define
define|#
directive|define
name|EFI_FVB2_LOCK_STATUS
value|0x00000080
end_define

begin_define
define|#
directive|define
name|EFI_FVB2_STICKY_WRITE
value|0x00000200
end_define

begin_define
define|#
directive|define
name|EFI_FVB2_MEMORY_MAPPED
value|0x00000400
end_define

begin_define
define|#
directive|define
name|EFI_FVB2_ERASE_POLARITY
value|0x00000800
end_define

begin_define
define|#
directive|define
name|EFI_FVB2_READ_LOCK_CAP
value|0x00001000
end_define

begin_define
define|#
directive|define
name|EFI_FVB2_READ_LOCK_STATUS
value|0x00002000
end_define

begin_define
define|#
directive|define
name|EFI_FVB2_WRITE_LOCK_CAP
value|0x00004000
end_define

begin_define
define|#
directive|define
name|EFI_FVB2_WRITE_LOCK_STATUS
value|0x00008000
end_define

begin_define
define|#
directive|define
name|EFI_FVB2_ALIGNMENT
value|0x001F0000
end_define

begin_define
define|#
directive|define
name|EFI_FVB2_ALIGNMENT_1
value|0x00000000
end_define

begin_define
define|#
directive|define
name|EFI_FVB2_ALIGNMENT_2
value|0x00010000
end_define

begin_define
define|#
directive|define
name|EFI_FVB2_ALIGNMENT_4
value|0x00020000
end_define

begin_define
define|#
directive|define
name|EFI_FVB2_ALIGNMENT_8
value|0x00030000
end_define

begin_define
define|#
directive|define
name|EFI_FVB2_ALIGNMENT_16
value|0x00040000
end_define

begin_define
define|#
directive|define
name|EFI_FVB2_ALIGNMENT_32
value|0x00050000
end_define

begin_define
define|#
directive|define
name|EFI_FVB2_ALIGNMENT_64
value|0x00060000
end_define

begin_define
define|#
directive|define
name|EFI_FVB2_ALIGNMENT_128
value|0x00070000
end_define

begin_define
define|#
directive|define
name|EFI_FVB2_ALIGNMENT_256
value|0x00080000
end_define

begin_define
define|#
directive|define
name|EFI_FVB2_ALIGNMENT_512
value|0x00090000
end_define

begin_define
define|#
directive|define
name|EFI_FVB2_ALIGNMENT_1K
value|0x000A0000
end_define

begin_define
define|#
directive|define
name|EFI_FVB2_ALIGNMENT_2K
value|0x000B0000
end_define

begin_define
define|#
directive|define
name|EFI_FVB2_ALIGNMENT_4K
value|0x000C0000
end_define

begin_define
define|#
directive|define
name|EFI_FVB2_ALIGNMENT_8K
value|0x000D0000
end_define

begin_define
define|#
directive|define
name|EFI_FVB2_ALIGNMENT_16K
value|0x000E0000
end_define

begin_define
define|#
directive|define
name|EFI_FVB2_ALIGNMENT_32K
value|0x000F0000
end_define

begin_define
define|#
directive|define
name|EFI_FVB2_ALIGNMENT_64K
value|0x00100000
end_define

begin_define
define|#
directive|define
name|EFI_FVB2_ALIGNMENT_128K
value|0x00110000
end_define

begin_define
define|#
directive|define
name|EFI_FVB2_ALIGNMENT_256K
value|0x00120000
end_define

begin_define
define|#
directive|define
name|EFI_FVB2_ALIGNMENT_512K
value|0x00130000
end_define

begin_define
define|#
directive|define
name|EFI_FVB2_ALIGNMENT_1M
value|0x00140000
end_define

begin_define
define|#
directive|define
name|EFI_FVB2_ALIGNMENT_2M
value|0x00150000
end_define

begin_define
define|#
directive|define
name|EFI_FVB2_ALIGNMENT_4M
value|0x00160000
end_define

begin_define
define|#
directive|define
name|EFI_FVB2_ALIGNMENT_8M
value|0x00170000
end_define

begin_define
define|#
directive|define
name|EFI_FVB2_ALIGNMENT_16M
value|0x00180000
end_define

begin_define
define|#
directive|define
name|EFI_FVB2_ALIGNMENT_32M
value|0x00190000
end_define

begin_define
define|#
directive|define
name|EFI_FVB2_ALIGNMENT_64M
value|0x001A0000
end_define

begin_define
define|#
directive|define
name|EFI_FVB2_ALIGNMENT_128M
value|0x001B0000
end_define

begin_define
define|#
directive|define
name|EFI_FVB2_ALIGNMENT_256M
value|0x001C0000
end_define

begin_define
define|#
directive|define
name|EFI_FVB2_ALIGNMENT_512M
value|0x001D0000
end_define

begin_define
define|#
directive|define
name|EFI_FVB2_ALIGNMENT_1G
value|0x001E0000
end_define

begin_define
define|#
directive|define
name|EFI_FVB2_ALIGNMENT_2G
value|0x001F0000
end_define

begin_define
define|#
directive|define
name|EFI_FVB2_WEAK_ALIGNMENT
value|0x80000000
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The number of sequential blocks which are of the same size.
comment|///
name|UINT32
name|NumBlocks
decl_stmt|;
comment|///
comment|/// The size of the blocks.
comment|///
name|UINT32
name|Length
decl_stmt|;
block|}
name|EFI_FV_BLOCK_MAP_ENTRY
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Describes the features and layout of the firmware volume.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The first 16 bytes are reserved to allow for the reset vector of
comment|/// processors whose reset vector is at address 0.
comment|///
name|UINT8
name|ZeroVector
index|[
literal|16
index|]
decl_stmt|;
comment|///
comment|/// Declares the file system with which the firmware volume is formatted.
comment|///
name|EFI_GUID
name|FileSystemGuid
decl_stmt|;
comment|///
comment|/// Length in bytes of the complete firmware volume, including the header.
comment|///
name|UINT64
name|FvLength
decl_stmt|;
comment|///
comment|/// Set to EFI_FVH_SIGNATURE
comment|///
name|UINT32
name|Signature
decl_stmt|;
comment|///
comment|/// Declares capabilities and power-on defaults for the firmware volume.
comment|///
name|EFI_FVB_ATTRIBUTES_2
name|Attributes
decl_stmt|;
comment|///
comment|/// Length in bytes of the complete firmware volume header.
comment|///
name|UINT16
name|HeaderLength
decl_stmt|;
comment|///
comment|/// A 16-bit checksum of the firmware volume header. A valid header sums to zero.
comment|///
name|UINT16
name|Checksum
decl_stmt|;
comment|///
comment|/// Offset, relative to the start of the header, of the extended header
comment|/// (EFI_FIRMWARE_VOLUME_EXT_HEADER) or zero if there is no extended header.
comment|///
name|UINT16
name|ExtHeaderOffset
decl_stmt|;
comment|///
comment|/// This field must always be set to zero.
comment|///
name|UINT8
name|Reserved
index|[
literal|1
index|]
decl_stmt|;
comment|///
comment|/// Set to 2. Future versions of this specification may define new header fields and will
comment|/// increment the Revision field accordingly.
comment|///
name|UINT8
name|Revision
decl_stmt|;
comment|///
comment|/// An array of run-length encoded FvBlockMapEntry structures. The array is
comment|/// terminated with an entry of {0,0}.
comment|///
name|EFI_FV_BLOCK_MAP_ENTRY
name|BlockMap
index|[
literal|1
index|]
decl_stmt|;
block|}
name|EFI_FIRMWARE_VOLUME_HEADER
typedef|;
end_typedef

begin_define
define|#
directive|define
name|EFI_FVH_SIGNATURE
value|SIGNATURE_32 ('_', 'F', 'V', 'H')
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Firmware Volume Header Revision definition
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_FVH_REVISION
value|0x02
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Extension header pointed by ExtHeaderOffset of volume header.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// Firmware volume name.
comment|///
name|EFI_GUID
name|FvName
decl_stmt|;
comment|///
comment|/// Size of the rest of the extension header, including this structure.
comment|///
name|UINT32
name|ExtHeaderSize
decl_stmt|;
block|}
name|EFI_FIRMWARE_VOLUME_EXT_HEADER
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Entry struture for describing FV extension header
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// Size of this header extension.
comment|///
name|UINT16
name|ExtEntrySize
decl_stmt|;
comment|///
comment|/// Type of the header.
comment|///
name|UINT16
name|ExtEntryType
decl_stmt|;
block|}
name|EFI_FIRMWARE_VOLUME_EXT_ENTRY
typedef|;
end_typedef

begin_define
define|#
directive|define
name|EFI_FV_EXT_TYPE_OEM_TYPE
value|0x01
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// This extension header provides a mapping between a GUID and an OEM file type.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// Standard extension entry, with the type EFI_FV_EXT_TYPE_OEM_TYPE.
comment|///
name|EFI_FIRMWARE_VOLUME_EXT_ENTRY
name|Hdr
decl_stmt|;
comment|///
comment|/// A bit mask, one bit for each file type between 0xC0 (bit 0) and 0xDF (bit 31). If a bit
comment|/// is '1', then the GUID entry exists in Types. If a bit is '0' then no GUID entry exists in Types.
comment|///
name|UINT32
name|TypeMask
decl_stmt|;
comment|///
comment|/// An array of GUIDs, each GUID representing an OEM file type.
comment|///
comment|/// EFI_GUID  Types[1];
comment|///
block|}
name|EFI_FIRMWARE_VOLUME_EXT_ENTRY_OEM_TYPE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|EFI_FV_EXT_TYPE_GUID_TYPE
value|0x0002
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// This extension header EFI_FIRMWARE_VOLUME_EXT_ENTRY_GUID_TYPE provides a vendor specific
end_comment

begin_comment
comment|/// GUID FormatType type which includes a length and a successive series of data bytes.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// Standard extension entry, with the type EFI_FV_EXT_TYPE_OEM_TYPE.
comment|///
name|EFI_FIRMWARE_VOLUME_EXT_ENTRY
name|Hdr
decl_stmt|;
comment|///
comment|/// Vendor-specific GUID.
comment|///
name|EFI_GUID
name|FormatType
decl_stmt|;
comment|///
comment|/// An arry of bytes of length Length.
comment|///
comment|/// UINT8                             Data[1];
comment|///
block|}
name|EFI_FIRMWARE_VOLUME_EXT_ENTRY_GUID_TYPE
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

end_unit

