begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_EFI_PART_H
end_ifndef

begin_define
define|#
directive|define
name|_EFI_PART_H
end_define

begin_comment
comment|/*++  Copyright (c) 1998  Intel Corporation  Module Name:      efipart.h      Abstract:        Info about disk partitions and Master Boot Records     Revision History  --*/
end_comment

begin_define
define|#
directive|define
name|EFI_PARTITION
value|0xef
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

begin_define
define|#
directive|define
name|EXTRACT_UINT32
parameter_list|(
name|D
parameter_list|)
value|(UINT32)(D[0] | (D[1]<< 8) | (D[2]<< 16) | (D[3]<< 24))
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
name|MIN_MBR_DEVICE_SIZE
value|0x80000
end_define

begin_define
define|#
directive|define
name|MBR_ERRATA_PAD
value|0x40000
end_define

begin_comment
comment|/* 128 MB */
end_comment

begin_define
define|#
directive|define
name|MAX_MBR_PARTITIONS
value|4
end_define

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

