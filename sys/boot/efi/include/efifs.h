begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_EFI_FS_H
end_ifndef

begin_define
define|#
directive|define
name|_EFI_FS_H
end_define

begin_comment
comment|/*++  Copyright (c) 1998  Intel Corporation  Module Name:      efifs.h  Abstract:      EFI File System structures    Revision History  --*/
end_comment

begin_comment
comment|/*  * EFI Partition header (normaly starts in LBA 1)  */
end_comment

begin_define
define|#
directive|define
name|EFI_PARTITION_SIGNATURE
value|0x5053595320494249
end_define

begin_define
define|#
directive|define
name|EFI_PARTITION_REVISION
value|0x00010001
end_define

begin_define
define|#
directive|define
name|MIN_EFI_PARTITION_BLOCK_SIZE
value|512
end_define

begin_define
define|#
directive|define
name|EFI_PARTITION_LBA
value|1
end_define

begin_typedef
typedef|typedef
struct|struct
name|_EFI_PARTITION_HEADER
block|{
name|EFI_TABLE_HEADER
name|Hdr
decl_stmt|;
name|UINT32
name|DirectoryAllocationNumber
decl_stmt|;
name|UINT32
name|BlockSize
decl_stmt|;
name|EFI_LBA
name|FirstUsableLba
decl_stmt|;
name|EFI_LBA
name|LastUsableLba
decl_stmt|;
name|EFI_LBA
name|UnusableSpace
decl_stmt|;
name|EFI_LBA
name|FreeSpace
decl_stmt|;
name|EFI_LBA
name|RootFile
decl_stmt|;
name|EFI_LBA
name|SecutiryFile
decl_stmt|;
block|}
name|EFI_PARTITION_HEADER
typedef|;
end_typedef

begin_comment
comment|/*  * File header  */
end_comment

begin_define
define|#
directive|define
name|EFI_FILE_HEADER_SIGNATURE
value|0x454c494620494249
end_define

begin_define
define|#
directive|define
name|EFI_FILE_HEADER_REVISION
value|0x00010000
end_define

begin_define
define|#
directive|define
name|EFI_FILE_STRING_SIZE
value|260
end_define

begin_typedef
typedef|typedef
struct|struct
name|_EFI_FILE_HEADER
block|{
name|EFI_TABLE_HEADER
name|Hdr
decl_stmt|;
name|UINT32
name|Class
decl_stmt|;
name|UINT32
name|LBALOffset
decl_stmt|;
name|EFI_LBA
name|Parent
decl_stmt|;
name|UINT64
name|FileSize
decl_stmt|;
name|UINT64
name|FileAttributes
decl_stmt|;
name|EFI_TIME
name|FileCreateTime
decl_stmt|;
name|EFI_TIME
name|FileModificationTime
decl_stmt|;
name|EFI_GUID
name|VendorGuid
decl_stmt|;
name|CHAR16
name|FileString
index|[
name|EFI_FILE_STRING_SIZE
index|]
decl_stmt|;
block|}
name|EFI_FILE_HEADER
typedef|;
end_typedef

begin_comment
comment|/*  * Return the file's first LBAL which is in the same  * logical block as the file header  */
end_comment

begin_define
define|#
directive|define
name|EFI_FILE_LBAL
parameter_list|(
name|a
parameter_list|)
value|((EFI_LBAL *) (((CHAR8 *) (a)) + (a)->LBALOffset))
end_define

begin_define
define|#
directive|define
name|EFI_FILE_CLASS_FREE_SPACE
value|1
end_define

begin_define
define|#
directive|define
name|EFI_FILE_CLASS_EMPTY
value|2
end_define

begin_define
define|#
directive|define
name|EFI_FILE_CLASS_NORMAL
value|3
end_define

begin_comment
comment|/*  * Logical Block Address List - the fundemental block  * description structure  */
end_comment

begin_define
define|#
directive|define
name|EFI_LBAL_SIGNATURE
value|0x4c41424c20494249
end_define

begin_define
define|#
directive|define
name|EFI_LBAL_REVISION
value|0x00010000
end_define

begin_typedef
typedef|typedef
struct|struct
name|_EFI_LBAL
block|{
name|EFI_TABLE_HEADER
name|Hdr
decl_stmt|;
name|UINT32
name|Class
decl_stmt|;
name|EFI_LBA
name|Parent
decl_stmt|;
name|EFI_LBA
name|Next
decl_stmt|;
name|UINT32
name|ArraySize
decl_stmt|;
name|UINT32
name|ArrayCount
decl_stmt|;
block|}
name|EFI_LBAL
typedef|;
end_typedef

begin_comment
comment|/* Array size */
end_comment

begin_define
define|#
directive|define
name|EFI_LBAL_ARRAY_SIZE
parameter_list|(
name|lbal
parameter_list|,
name|offs
parameter_list|,
name|blks
parameter_list|)
define|\
value|(((blks) - (offs) - (lbal)->Hdr.HeaderSize) / sizeof(EFI_RL))
end_define

begin_comment
comment|/*  * Logical Block run-length  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_LBA
name|Start
decl_stmt|;
name|UINT64
name|Length
decl_stmt|;
block|}
name|EFI_RL
typedef|;
end_typedef

begin_comment
comment|/*  * Return the run-length structure from an LBAL header  */
end_comment

begin_define
define|#
directive|define
name|EFI_LBAL_RL
parameter_list|(
name|a
parameter_list|)
value|((EFI_RL*) (((CHAR8 *) (a)) + (a)->Hdr.HeaderSize))
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

