begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   ElTorito Partitions Format Definition.    This file includes some defintions from    1. "El Torito" Bootable CD-ROM Format Specification, Version 1.0.   2. Volume and File Structure of CDROM for Information Interchange,       Standard ECMA-119. (IS0 9660)  Copyright (c) 2006 - 2008, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials                           are licensed and made available under the terms and conditions of the BSD License          which accompanies this distribution.  The full text of the license may be found at         http://opensource.org/licenses/bsd-license.php                                                                                                                                        THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                      WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.               **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ELTORITO_H_
end_ifndef

begin_define
define|#
directive|define
name|_ELTORITO_H_
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// CDROM_VOLUME_DESCRIPTOR.Types, defined in ISO 9660
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|CDVOL_TYPE_STANDARD
value|0x0
end_define

begin_define
define|#
directive|define
name|CDVOL_TYPE_CODED
value|0x1
end_define

begin_define
define|#
directive|define
name|CDVOL_TYPE_END
value|0xFF
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// CDROM_VOLUME_DESCRIPTOR.Id
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|CDVOL_ID
value|"CD001"
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// CDROM_VOLUME_DESCRIPTOR.SystemId
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|CDVOL_ELTORITO_ID
value|"EL TORITO SPECIFICATION"
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Indicator types
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|ELTORITO_ID_CATALOG
value|0x01
end_define

begin_define
define|#
directive|define
name|ELTORITO_ID_SECTION_BOOTABLE
value|0x88
end_define

begin_define
define|#
directive|define
name|ELTORITO_ID_SECTION_NOT_BOOTABLE
value|0x00
end_define

begin_define
define|#
directive|define
name|ELTORITO_ID_SECTION_HEADER
value|0x90
end_define

begin_define
define|#
directive|define
name|ELTORITO_ID_SECTION_HEADER_FINAL
value|0x91
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// ELTORITO_CATALOG.Boot.MediaTypes
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|ELTORITO_NO_EMULATION
value|0x00
end_define

begin_define
define|#
directive|define
name|ELTORITO_12_DISKETTE
value|0x01
end_define

begin_define
define|#
directive|define
name|ELTORITO_14_DISKETTE
value|0x02
end_define

begin_define
define|#
directive|define
name|ELTORITO_28_DISKETTE
value|0x03
end_define

begin_define
define|#
directive|define
name|ELTORITO_HARD_DISK
value|0x04
end_define

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|1
name|)
end_pragma

begin_comment
comment|///
end_comment

begin_comment
comment|/// CD-ROM Volume Descriptor
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT8
name|Type
decl_stmt|;
name|CHAR8
name|Id
index|[
literal|5
index|]
decl_stmt|;
comment|///< "CD001"
name|CHAR8
name|Reserved
index|[
literal|82
index|]
decl_stmt|;
block|}
name|Unknown
struct|;
comment|///
comment|/// Boot Record Volume Descriptor, defined in "El Torito" Specification.
comment|///
struct|struct
block|{
name|UINT8
name|Type
decl_stmt|;
comment|///< Must be 0
name|CHAR8
name|Id
index|[
literal|5
index|]
decl_stmt|;
comment|///< "CD001"
name|UINT8
name|Version
decl_stmt|;
comment|///< Must be 1
name|CHAR8
name|SystemId
index|[
literal|32
index|]
decl_stmt|;
comment|///< "EL TORITO SPECIFICATION"
name|CHAR8
name|Unused
index|[
literal|32
index|]
decl_stmt|;
comment|///< Must be 0
name|UINT8
name|EltCatalog
index|[
literal|4
index|]
decl_stmt|;
comment|///< Absolute pointer to first sector of Boot Catalog
name|CHAR8
name|Unused2
index|[
literal|13
index|]
decl_stmt|;
comment|///< Must be 0
block|}
name|BootRecordVolume
struct|;
comment|///
comment|/// Primary Volumn Descriptor, defined in ISO 9660.
comment|///
struct|struct
block|{
name|UINT8
name|Type
decl_stmt|;
name|CHAR8
name|Id
index|[
literal|5
index|]
decl_stmt|;
comment|///< "CD001"
name|UINT8
name|Version
decl_stmt|;
name|UINT8
name|Unused
decl_stmt|;
comment|///< Must be 0
name|CHAR8
name|SystemId
index|[
literal|32
index|]
decl_stmt|;
name|CHAR8
name|VolumeId
index|[
literal|32
index|]
decl_stmt|;
name|UINT8
name|Unused2
index|[
literal|8
index|]
decl_stmt|;
comment|///< Must be 0
name|UINT32
name|VolSpaceSize
index|[
literal|2
index|]
decl_stmt|;
comment|///< the number of Logical Blocks
block|}
name|PrimaryVolume
struct|;
block|}
name|CDROM_VOLUME_DESCRIPTOR
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Catalog Entry
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|CHAR8
name|Reserved
index|[
literal|0x20
index|]
decl_stmt|;
block|}
name|Unknown
struct|;
comment|///
comment|/// Catalog validation entry (Catalog header)
comment|///
struct|struct
block|{
name|UINT8
name|Indicator
decl_stmt|;
comment|///< Must be 01
name|UINT8
name|PlatformId
decl_stmt|;
name|UINT16
name|Reserved
decl_stmt|;
name|CHAR8
name|ManufacId
index|[
literal|24
index|]
decl_stmt|;
name|UINT16
name|Checksum
decl_stmt|;
name|UINT16
name|Id55AA
decl_stmt|;
block|}
name|Catalog
struct|;
comment|///
comment|/// Initial/Default Entry or Section Entry
comment|///
struct|struct
block|{
name|UINT8
name|Indicator
decl_stmt|;
comment|///< 88 = Bootable, 00 = Not Bootable
name|UINT8
name|MediaType
range|:
literal|4
decl_stmt|;
name|UINT8
name|Reserved1
range|:
literal|4
decl_stmt|;
comment|///< Must be 0
name|UINT16
name|LoadSegment
decl_stmt|;
name|UINT8
name|SystemType
decl_stmt|;
name|UINT8
name|Reserved2
decl_stmt|;
comment|///< Must be 0
name|UINT16
name|SectorCount
decl_stmt|;
name|UINT32
name|Lba
decl_stmt|;
block|}
name|Boot
struct|;
comment|///
comment|/// Section Header Entry
comment|///
struct|struct
block|{
name|UINT8
name|Indicator
decl_stmt|;
comment|///< 90 - Header, more header follw, 91 - Final Header
name|UINT8
name|PlatformId
decl_stmt|;
name|UINT16
name|SectionEntries
decl_stmt|;
comment|///< Number of section entries following this header
name|CHAR8
name|Id
index|[
literal|28
index|]
decl_stmt|;
block|}
name|Section
struct|;
block|}
name|ELTORITO_CATALOG
typedef|;
end_typedef

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

end_unit

