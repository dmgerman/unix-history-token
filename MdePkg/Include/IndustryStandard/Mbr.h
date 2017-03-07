begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Legacy Master Boot Record Format Definition.  Copyright (c) 2006 - 2008, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials                           are licensed and made available under the terms and conditions of the BSD License          which accompanies this distribution.  The full text of the license may be found at         http://opensource.org/licenses/bsd-license.php                                                                                            THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                      WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.               **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MBR_H_
end_ifndef

begin_define
define|#
directive|define
name|_MBR_H_
end_define

begin_define
define|#
directive|define
name|MBR_SIGNATURE
value|0xaa55
end_define

begin_define
define|#
directive|define
name|EXTENDED_DOS_PARTITION
value|0x05
end_define

begin_define
define|#
directive|define
name|EXTENDED_WINDOWS_PARTITION
value|0x0F
end_define

begin_define
define|#
directive|define
name|MAX_MBR_PARTITIONS
value|4
end_define

begin_define
define|#
directive|define
name|PMBR_GPT_PARTITION
value|0xEE
end_define

begin_define
define|#
directive|define
name|EFI_PARTITION
value|0xEF
end_define

begin_define
define|#
directive|define
name|MBR_SIZE
value|512
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
comment|/// MBR Partition Entry
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|BootIndicator
decl_stmt|;
name|UINT8
name|StartHead
decl_stmt|;
name|UINT8
name|StartSector
decl_stmt|;
name|UINT8
name|StartTrack
decl_stmt|;
name|UINT8
name|OSIndicator
decl_stmt|;
name|UINT8
name|EndHead
decl_stmt|;
name|UINT8
name|EndSector
decl_stmt|;
name|UINT8
name|EndTrack
decl_stmt|;
name|UINT8
name|StartingLBA
index|[
literal|4
index|]
decl_stmt|;
name|UINT8
name|SizeInLBA
index|[
literal|4
index|]
decl_stmt|;
block|}
name|MBR_PARTITION_RECORD
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// MBR Partition Table
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|BootStrapCode
index|[
literal|440
index|]
decl_stmt|;
name|UINT8
name|UniqueMbrSignature
index|[
literal|4
index|]
decl_stmt|;
name|UINT8
name|Unknown
index|[
literal|2
index|]
decl_stmt|;
name|MBR_PARTITION_RECORD
name|Partition
index|[
name|MAX_MBR_PARTITIONS
index|]
decl_stmt|;
name|UINT16
name|Signature
decl_stmt|;
block|}
name|MASTER_BOOT_RECORD
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

