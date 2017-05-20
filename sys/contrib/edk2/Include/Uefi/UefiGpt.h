begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   EFI Guid Partition Table Format Definition.  Copyright (c) 2006 - 2011, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under  the terms and conditions of the BSD License that accompanies this distribution.   The full text of the license may be found at http://opensource.org/licenses/bsd-license.php.                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                      WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__UEFI_GPT_H__
end_ifndef

begin_define
define|#
directive|define
name|__UEFI_GPT_H__
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// The primary GUID Partition Table Header must be
end_comment

begin_comment
comment|/// located in LBA 1 (i.e., the second logical block).
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PRIMARY_PART_HEADER_LBA
value|1
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI Partition Table Signature: "EFI PART".
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_PTAB_HEADER_ID
value|SIGNATURE_64 ('E','F','I',' ','P','A','R','T')
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
comment|/// GPT Partition Table Header.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The table header for the GPT partition Table.
comment|/// This header contains EFI_PTAB_HEADER_ID.
comment|///
name|EFI_TABLE_HEADER
name|Header
decl_stmt|;
comment|///
comment|/// The LBA that contains this data structure.
comment|///
name|EFI_LBA
name|MyLBA
decl_stmt|;
comment|///
comment|/// LBA address of the alternate GUID Partition Table Header.
comment|///
name|EFI_LBA
name|AlternateLBA
decl_stmt|;
comment|///
comment|/// The first usable logical block that may be used
comment|/// by a partition described by a GUID Partition Entry.
comment|///
name|EFI_LBA
name|FirstUsableLBA
decl_stmt|;
comment|///
comment|/// The last usable logical block that may be used
comment|/// by a partition described by a GUID Partition Entry.
comment|///
name|EFI_LBA
name|LastUsableLBA
decl_stmt|;
comment|///
comment|/// GUID that can be used to uniquely identify the disk.
comment|///
name|EFI_GUID
name|DiskGUID
decl_stmt|;
comment|///
comment|/// The starting LBA of the GUID Partition Entry array.
comment|///
name|EFI_LBA
name|PartitionEntryLBA
decl_stmt|;
comment|///
comment|/// The number of Partition Entries in the GUID Partition Entry array.
comment|///
name|UINT32
name|NumberOfPartitionEntries
decl_stmt|;
comment|///
comment|/// The size, in bytes, of each the GUID Partition
comment|/// Entry structures in the GUID Partition Entry
comment|/// array. This field shall be set to a value of 128 x 2^n where n is
comment|/// an integer greater than or equal to zero (e.g., 128, 256, 512, etc.).
comment|///
name|UINT32
name|SizeOfPartitionEntry
decl_stmt|;
comment|///
comment|/// The CRC32 of the GUID Partition Entry array.
comment|/// Starts at PartitionEntryLBA and is
comment|/// computed over a byte length of
comment|/// NumberOfPartitionEntries * SizeOfPartitionEntry.
comment|///
name|UINT32
name|PartitionEntryArrayCRC32
decl_stmt|;
block|}
name|EFI_PARTITION_TABLE_HEADER
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// GPT Partition Entry.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// Unique ID that defines the purpose and type of this Partition. A value of
comment|/// zero defines that this partition entry is not being used.
comment|///
name|EFI_GUID
name|PartitionTypeGUID
decl_stmt|;
comment|///
comment|/// GUID that is unique for every partition entry. Every partition ever
comment|/// created will have a unique GUID.
comment|/// This GUID must be assigned when the GUID Partition Entry is created.
comment|///
name|EFI_GUID
name|UniquePartitionGUID
decl_stmt|;
comment|///
comment|/// Starting LBA of the partition defined by this entry
comment|///
name|EFI_LBA
name|StartingLBA
decl_stmt|;
comment|///
comment|/// Ending LBA of the partition defined by this entry.
comment|///
name|EFI_LBA
name|EndingLBA
decl_stmt|;
comment|///
comment|/// Attribute bits, all bits reserved by UEFI
comment|/// Bit 0:      If this bit is set, the partition is required for the platform to function. The owner/creator of the
comment|///             partition indicates that deletion or modification of the contents can result in loss of platform
comment|///             features or failure for the platform to boot or operate. The system cannot function normally if
comment|///             this partition is removed, and it should be considered part of the hardware of the system.
comment|///             Actions such as running diagnostics, system recovery, or even OS install or boot, could
comment|///             potentially stop working if this partition is removed. Unless OS software or firmware
comment|///             recognizes this partition, it should never be removed or modified as the UEFI firmware or
comment|///             platform hardware may become non-functional.
comment|/// Bit 1:      If this bit is set, then firmware must not produce an EFI_BLOCK_IO_PROTOCOL device for
comment|///             this partition. By not producing an EFI_BLOCK_IO_PROTOCOL partition, file system
comment|///             mappings will not be created for this partition in UEFI.
comment|/// Bit 2:      This bit is set aside to let systems with traditional PC-AT BIOS firmware implementations
comment|///             inform certain limited, special-purpose software running on these systems that a GPT
comment|///             partition may be bootable. The UEFI boot manager must ignore this bit when selecting
comment|///             a UEFI-compliant application, e.g., an OS loader.
comment|/// Bits 3-47:  Undefined and must be zero. Reserved for expansion by future versions of the UEFI
comment|///             specification.
comment|/// Bits 48-63: Reserved for GUID specific use. The use of these bits will vary depending on the
comment|///             PartitionTypeGUID. Only the owner of the PartitionTypeGUID is allowed
comment|///             to modify these bits. They must be preserved if Bits 0-47 are modified..
comment|///
name|UINT64
name|Attributes
decl_stmt|;
comment|///
comment|/// Null-terminated name of the partition.
comment|///
name|CHAR16
name|PartitionName
index|[
literal|36
index|]
decl_stmt|;
block|}
name|EFI_PARTITION_ENTRY
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

