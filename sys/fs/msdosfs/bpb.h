begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*	$NetBSD: bpb.h,v 1.7 1997/11/17 15:36:24 ws Exp $	*/
end_comment

begin_comment
comment|/*-  * Written by Paul Popelka (paulp@uts.amdahl.com)  *  * You can do anything you want with this software, just don't say you wrote  * it, and don't remove this notice.  *  * This software is provided "as is".  *  * The author supplies this software to be publicly redistributed on the  * understanding that the author is not responsible for the correct  * functioning of this software in any circumstances and is not liable for  * any damages caused by this software.  *  * October 1992  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_FS_MSDOSFS_BPB_H_
end_ifndef

begin_define
define|#
directive|define
name|_FS_MSDOSFS_BPB_H_
end_define

begin_comment
comment|/*  * BIOS Parameter Block (BPB) for DOS 3.3  */
end_comment

begin_struct
struct|struct
name|bpb33
block|{
name|uint16_t
name|bpbBytesPerSec
decl_stmt|;
comment|/* bytes per sector */
name|uint8_t
name|bpbSecPerClust
decl_stmt|;
comment|/* sectors per cluster */
name|uint16_t
name|bpbResSectors
decl_stmt|;
comment|/* number of reserved sectors */
name|uint8_t
name|bpbFATs
decl_stmt|;
comment|/* number of FATs */
name|uint16_t
name|bpbRootDirEnts
decl_stmt|;
comment|/* number of root directory entries */
name|uint16_t
name|bpbSectors
decl_stmt|;
comment|/* total number of sectors */
name|uint8_t
name|bpbMedia
decl_stmt|;
comment|/* media descriptor */
name|uint16_t
name|bpbFATsecs
decl_stmt|;
comment|/* number of sectors per FAT */
name|uint16_t
name|bpbSecPerTrack
decl_stmt|;
comment|/* sectors per track */
name|uint16_t
name|bpbHeads
decl_stmt|;
comment|/* number of heads */
name|uint16_t
name|bpbHiddenSecs
decl_stmt|;
comment|/* number of hidden sectors */
block|}
struct|;
end_struct

begin_comment
comment|/*  * BPB for DOS 5.0 The difference is bpbHiddenSecs is a short for DOS 3.3,  * and bpbHugeSectors is not in the 3.3 bpb.  */
end_comment

begin_struct
struct|struct
name|bpb50
block|{
name|uint16_t
name|bpbBytesPerSec
decl_stmt|;
comment|/* bytes per sector */
name|uint8_t
name|bpbSecPerClust
decl_stmt|;
comment|/* sectors per cluster */
name|uint16_t
name|bpbResSectors
decl_stmt|;
comment|/* number of reserved sectors */
name|uint8_t
name|bpbFATs
decl_stmt|;
comment|/* number of FATs */
name|uint16_t
name|bpbRootDirEnts
decl_stmt|;
comment|/* number of root directory entries */
name|uint16_t
name|bpbSectors
decl_stmt|;
comment|/* total number of sectors */
name|uint8_t
name|bpbMedia
decl_stmt|;
comment|/* media descriptor */
name|uint16_t
name|bpbFATsecs
decl_stmt|;
comment|/* number of sectors per FAT */
name|uint16_t
name|bpbSecPerTrack
decl_stmt|;
comment|/* sectors per track */
name|uint16_t
name|bpbHeads
decl_stmt|;
comment|/* number of heads */
name|uint32_t
name|bpbHiddenSecs
decl_stmt|;
comment|/* # of hidden sectors */
name|uint32_t
name|bpbHugeSectors
decl_stmt|;
comment|/* # of sectors if bpbSectors == 0 */
block|}
struct|;
end_struct

begin_comment
comment|/*  * BPB for DOS 7.10 (FAT32).  This one has a few extensions to bpb50.  */
end_comment

begin_struct
struct|struct
name|bpb710
block|{
name|uint16_t
name|bpbBytesPerSec
decl_stmt|;
comment|/* bytes per sector */
name|uint8_t
name|bpbSecPerClust
decl_stmt|;
comment|/* sectors per cluster */
name|uint16_t
name|bpbResSectors
decl_stmt|;
comment|/* number of reserved sectors */
name|uint8_t
name|bpbFATs
decl_stmt|;
comment|/* number of FATs */
name|uint16_t
name|bpbRootDirEnts
decl_stmt|;
comment|/* number of root directory entries */
name|uint16_t
name|bpbSectors
decl_stmt|;
comment|/* total number of sectors */
name|uint8_t
name|bpbMedia
decl_stmt|;
comment|/* media descriptor */
name|uint16_t
name|bpbFATsecs
decl_stmt|;
comment|/* number of sectors per FAT */
name|uint16_t
name|bpbSecPerTrack
decl_stmt|;
comment|/* sectors per track */
name|uint16_t
name|bpbHeads
decl_stmt|;
comment|/* number of heads */
name|uint32_t
name|bpbHiddenSecs
decl_stmt|;
comment|/* # of hidden sectors */
name|uint32_t
name|bpbHugeSectors
decl_stmt|;
comment|/* # of sectors if bpbSectors == 0 */
name|uint32_t
name|bpbBigFATsecs
decl_stmt|;
comment|/* like bpbFATsecs for FAT32 */
name|uint16_t
name|bpbExtFlags
decl_stmt|;
comment|/* extended flags: */
define|#
directive|define
name|FATNUM
value|0xf
comment|/* mask for numbering active FAT */
define|#
directive|define
name|FATMIRROR
value|0x80
comment|/* FAT is mirrored (like it always was) */
name|uint16_t
name|bpbFSVers
decl_stmt|;
comment|/* filesystem version */
define|#
directive|define
name|FSVERS
value|0
comment|/* currently only 0 is understood */
name|uint32_t
name|bpbRootClust
decl_stmt|;
comment|/* start cluster for root directory */
name|uint16_t
name|bpbFSInfo
decl_stmt|;
comment|/* filesystem info structure sector */
name|uint16_t
name|bpbBackup
decl_stmt|;
comment|/* backup boot sector */
name|uint8_t
name|bpbReserved
index|[
literal|12
index|]
decl_stmt|;
comment|/* reserved for future expansion */
block|}
struct|;
end_struct

begin_comment
comment|/*  * The following structures represent how the bpb's look on disk.  shorts  * and longs are just character arrays of the appropriate length.  This is  * because the compiler forces shorts and longs to align on word or  * halfword boundaries.  */
end_comment

begin_include
include|#
directive|include
file|<sys/endian.h>
end_include

begin_define
define|#
directive|define
name|getushort
parameter_list|(
name|x
parameter_list|)
value|le16dec(x)
end_define

begin_define
define|#
directive|define
name|getulong
parameter_list|(
name|x
parameter_list|)
value|le32dec(x)
end_define

begin_define
define|#
directive|define
name|putushort
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|le16enc(p, v)
end_define

begin_define
define|#
directive|define
name|putulong
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|le32enc(p, v)
end_define

begin_comment
comment|/*  * BIOS Parameter Block (BPB) for DOS 3.3  */
end_comment

begin_struct
struct|struct
name|byte_bpb33
block|{
name|int8_t
name|bpbBytesPerSec
index|[
literal|2
index|]
decl_stmt|;
comment|/* bytes per sector */
name|int8_t
name|bpbSecPerClust
decl_stmt|;
comment|/* sectors per cluster */
name|int8_t
name|bpbResSectors
index|[
literal|2
index|]
decl_stmt|;
comment|/* number of reserved sectors */
name|int8_t
name|bpbFATs
decl_stmt|;
comment|/* number of FATs */
name|int8_t
name|bpbRootDirEnts
index|[
literal|2
index|]
decl_stmt|;
comment|/* number of root directory entries */
name|int8_t
name|bpbSectors
index|[
literal|2
index|]
decl_stmt|;
comment|/* total number of sectors */
name|int8_t
name|bpbMedia
decl_stmt|;
comment|/* media descriptor */
name|int8_t
name|bpbFATsecs
index|[
literal|2
index|]
decl_stmt|;
comment|/* number of sectors per FAT */
name|int8_t
name|bpbSecPerTrack
index|[
literal|2
index|]
decl_stmt|;
comment|/* sectors per track */
name|int8_t
name|bpbHeads
index|[
literal|2
index|]
decl_stmt|;
comment|/* number of heads */
name|int8_t
name|bpbHiddenSecs
index|[
literal|2
index|]
decl_stmt|;
comment|/* number of hidden sectors */
block|}
struct|;
end_struct

begin_comment
comment|/*  * BPB for DOS 5.0 The difference is bpbHiddenSecs is a short for DOS 3.3,  * and bpbHugeSectors is not in the 3.3 bpb.  */
end_comment

begin_struct
struct|struct
name|byte_bpb50
block|{
name|int8_t
name|bpbBytesPerSec
index|[
literal|2
index|]
decl_stmt|;
comment|/* bytes per sector */
name|int8_t
name|bpbSecPerClust
decl_stmt|;
comment|/* sectors per cluster */
name|int8_t
name|bpbResSectors
index|[
literal|2
index|]
decl_stmt|;
comment|/* number of reserved sectors */
name|int8_t
name|bpbFATs
decl_stmt|;
comment|/* number of FATs */
name|int8_t
name|bpbRootDirEnts
index|[
literal|2
index|]
decl_stmt|;
comment|/* number of root directory entries */
name|int8_t
name|bpbSectors
index|[
literal|2
index|]
decl_stmt|;
comment|/* total number of sectors */
name|int8_t
name|bpbMedia
decl_stmt|;
comment|/* media descriptor */
name|int8_t
name|bpbFATsecs
index|[
literal|2
index|]
decl_stmt|;
comment|/* number of sectors per FAT */
name|int8_t
name|bpbSecPerTrack
index|[
literal|2
index|]
decl_stmt|;
comment|/* sectors per track */
name|int8_t
name|bpbHeads
index|[
literal|2
index|]
decl_stmt|;
comment|/* number of heads */
name|int8_t
name|bpbHiddenSecs
index|[
literal|4
index|]
decl_stmt|;
comment|/* number of hidden sectors */
name|int8_t
name|bpbHugeSectors
index|[
literal|4
index|]
decl_stmt|;
comment|/* # of sectors if bpbSectors == 0 */
block|}
struct|;
end_struct

begin_comment
comment|/*  * BPB for DOS 7.10 (FAT32).  This one has a few extensions to bpb50.  */
end_comment

begin_struct
struct|struct
name|byte_bpb710
block|{
name|uint8_t
name|bpbBytesPerSec
index|[
literal|2
index|]
decl_stmt|;
comment|/* bytes per sector */
name|uint8_t
name|bpbSecPerClust
decl_stmt|;
comment|/* sectors per cluster */
name|uint8_t
name|bpbResSectors
index|[
literal|2
index|]
decl_stmt|;
comment|/* number of reserved sectors */
name|uint8_t
name|bpbFATs
decl_stmt|;
comment|/* number of FATs */
name|uint8_t
name|bpbRootDirEnts
index|[
literal|2
index|]
decl_stmt|;
comment|/* number of root directory entries */
name|uint8_t
name|bpbSectors
index|[
literal|2
index|]
decl_stmt|;
comment|/* total number of sectors */
name|uint8_t
name|bpbMedia
decl_stmt|;
comment|/* media descriptor */
name|uint8_t
name|bpbFATsecs
index|[
literal|2
index|]
decl_stmt|;
comment|/* number of sectors per FAT */
name|uint8_t
name|bpbSecPerTrack
index|[
literal|2
index|]
decl_stmt|;
comment|/* sectors per track */
name|uint8_t
name|bpbHeads
index|[
literal|2
index|]
decl_stmt|;
comment|/* number of heads */
name|uint8_t
name|bpbHiddenSecs
index|[
literal|4
index|]
decl_stmt|;
comment|/* # of hidden sectors */
name|uint8_t
name|bpbHugeSectors
index|[
literal|4
index|]
decl_stmt|;
comment|/* # of sectors if bpbSectors == 0 */
name|uint8_t
name|bpbBigFATsecs
index|[
literal|4
index|]
decl_stmt|;
comment|/* like bpbFATsecs for FAT32 */
name|uint8_t
name|bpbExtFlags
index|[
literal|2
index|]
decl_stmt|;
comment|/* extended flags: */
name|uint8_t
name|bpbFSVers
index|[
literal|2
index|]
decl_stmt|;
comment|/* filesystem version */
name|uint8_t
name|bpbRootClust
index|[
literal|4
index|]
decl_stmt|;
comment|/* start cluster for root directory */
name|uint8_t
name|bpbFSInfo
index|[
literal|2
index|]
decl_stmt|;
comment|/* filesystem info structure sector */
name|uint8_t
name|bpbBackup
index|[
literal|2
index|]
decl_stmt|;
comment|/* backup boot sector */
name|uint8_t
name|bpbReserved
index|[
literal|12
index|]
decl_stmt|;
comment|/* reserved for future expansion */
block|}
struct|;
end_struct

begin_comment
comment|/*  * FAT32 FSInfo block.  */
end_comment

begin_struct
struct|struct
name|fsinfo
block|{
name|uint8_t
name|fsisig1
index|[
literal|4
index|]
decl_stmt|;
name|uint8_t
name|fsifill1
index|[
literal|480
index|]
decl_stmt|;
name|uint8_t
name|fsisig2
index|[
literal|4
index|]
decl_stmt|;
name|uint8_t
name|fsinfree
index|[
literal|4
index|]
decl_stmt|;
name|uint8_t
name|fsinxtfree
index|[
literal|4
index|]
decl_stmt|;
name|uint8_t
name|fsifill2
index|[
literal|12
index|]
decl_stmt|;
name|uint8_t
name|fsisig3
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_FS_MSDOSFS_BPB_H_ */
end_comment

end_unit

