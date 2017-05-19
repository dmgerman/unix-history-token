begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*	$NetBSD: bootsect.h,v 1.9 1997/11/17 15:36:17 ws Exp $	*/
end_comment

begin_comment
comment|/*-  * Written by Paul Popelka (paulp@uts.amdahl.com)  *  * You can do anything you want with this software, just don't say you wrote  * it, and don't remove this notice.  *  * This software is provided "as is".  *  * The author supplies this software to be publicly redistributed on the  * understanding that the author is not responsible for the correct  * functioning of this software in any circumstances and is not liable for  * any damages caused by this software.  *  * October 1992  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_FS_MSDOSFS_BOOTSECT_H_
end_ifndef

begin_define
define|#
directive|define
name|_FS_MSDOSFS_BOOTSECT_H_
end_define

begin_comment
comment|/*  * Format of a boot sector.  This is the first sector on a DOS floppy disk  * or the fist sector of a partition on a hard disk.  But, it is not the  * first sector of a partitioned hard disk.  */
end_comment

begin_struct
struct|struct
name|bootsector33
block|{
name|uint8_t
name|bsJump
index|[
literal|3
index|]
decl_stmt|;
comment|/* jump inst E9xxxx or EBxx90 */
name|int8_t
name|bsOemName
index|[
literal|8
index|]
decl_stmt|;
comment|/* OEM name and version */
name|int8_t
name|bsBPB
index|[
literal|19
index|]
decl_stmt|;
comment|/* BIOS parameter block */
name|int8_t
name|bsDriveNumber
decl_stmt|;
comment|/* drive number (0x80) */
name|int8_t
name|bsBootCode
index|[
literal|479
index|]
decl_stmt|;
comment|/* pad so struct is 512b */
name|uint8_t
name|bsBootSectSig0
decl_stmt|;
name|uint8_t
name|bsBootSectSig1
decl_stmt|;
define|#
directive|define
name|BOOTSIG0
value|0x55
define|#
directive|define
name|BOOTSIG1
value|0xaa
block|}
struct|;
end_struct

begin_struct
struct|struct
name|extboot
block|{
name|int8_t
name|exDriveNumber
decl_stmt|;
comment|/* drive number (0x80) */
name|int8_t
name|exReserved1
decl_stmt|;
comment|/* reserved */
name|int8_t
name|exBootSignature
decl_stmt|;
comment|/* ext. boot signature (0x29) */
define|#
directive|define
name|EXBOOTSIG
value|0x29
name|int8_t
name|exVolumeID
index|[
literal|4
index|]
decl_stmt|;
comment|/* volume ID number */
name|int8_t
name|exVolumeLabel
index|[
literal|11
index|]
decl_stmt|;
comment|/* volume label */
name|int8_t
name|exFileSysType
index|[
literal|8
index|]
decl_stmt|;
comment|/* fs type (FAT12 or FAT16) */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|bootsector50
block|{
name|uint8_t
name|bsJump
index|[
literal|3
index|]
decl_stmt|;
comment|/* jump inst E9xxxx or EBxx90 */
name|int8_t
name|bsOemName
index|[
literal|8
index|]
decl_stmt|;
comment|/* OEM name and version */
name|int8_t
name|bsBPB
index|[
literal|25
index|]
decl_stmt|;
comment|/* BIOS parameter block */
name|int8_t
name|bsExt
index|[
literal|26
index|]
decl_stmt|;
comment|/* Bootsector Extension */
name|int8_t
name|bsBootCode
index|[
literal|448
index|]
decl_stmt|;
comment|/* pad so structure is 512b */
name|uint8_t
name|bsBootSectSig0
decl_stmt|;
name|uint8_t
name|bsBootSectSig1
decl_stmt|;
define|#
directive|define
name|BOOTSIG0
value|0x55
define|#
directive|define
name|BOOTSIG1
value|0xaa
block|}
struct|;
end_struct

begin_struct
struct|struct
name|bootsector710
block|{
name|uint8_t
name|bsJump
index|[
literal|3
index|]
decl_stmt|;
comment|/* jump inst E9xxxx or EBxx90 */
name|int8_t
name|bsOEMName
index|[
literal|8
index|]
decl_stmt|;
comment|/* OEM name and version */
name|int8_t
name|bsBPB
index|[
literal|53
index|]
decl_stmt|;
comment|/* BIOS parameter block */
name|int8_t
name|bsExt
index|[
literal|26
index|]
decl_stmt|;
comment|/* Bootsector Extension */
name|int8_t
name|bsBootCode
index|[
literal|420
index|]
decl_stmt|;
comment|/* pad so structure is 512b */
name|uint8_t
name|bsBootSectSig0
decl_stmt|;
name|uint8_t
name|bsBootSectSig1
decl_stmt|;
define|#
directive|define
name|BOOTSIG0
value|0x55
define|#
directive|define
name|BOOTSIG1
value|0xaa
block|}
struct|;
end_struct

begin_union
union|union
name|bootsector
block|{
name|struct
name|bootsector33
name|bs33
decl_stmt|;
name|struct
name|bootsector50
name|bs50
decl_stmt|;
name|struct
name|bootsector710
name|bs710
decl_stmt|;
block|}
union|;
end_union

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/*  * Shorthand for fields in the bpb.  */
end_comment

begin_define
define|#
directive|define
name|bsBytesPerSec
value|bsBPB.bpbBytesPerSec
end_define

begin_define
define|#
directive|define
name|bsSectPerClust
value|bsBPB.bpbSectPerClust
end_define

begin_define
define|#
directive|define
name|bsResSectors
value|bsBPB.bpbResSectors
end_define

begin_define
define|#
directive|define
name|bsFATS
value|bsBPB.bpbFATS
end_define

begin_define
define|#
directive|define
name|bsRootDirEnts
value|bsBPB.bpbRootDirEnts
end_define

begin_define
define|#
directive|define
name|bsSectors
value|bsBPB.bpbSectors
end_define

begin_define
define|#
directive|define
name|bsMedia
value|bsBPB.bpbMedia
end_define

begin_define
define|#
directive|define
name|bsFATsecs
value|bsBPB.bpbFATsecs
end_define

begin_define
define|#
directive|define
name|bsSectPerTrack
value|bsBPB.bpbSectPerTrack
end_define

begin_define
define|#
directive|define
name|bsHeads
value|bsBPB.bpbHeads
end_define

begin_define
define|#
directive|define
name|bsHiddenSecs
value|bsBPB.bpbHiddenSecs
end_define

begin_define
define|#
directive|define
name|bsHugeSectors
value|bsBPB.bpbHugeSectors
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_FS_MSDOSFS_BOOTSECT_H_ */
end_comment

end_unit

