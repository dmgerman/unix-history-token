begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*	$NetBSD: bootsect.h,v 1.4 1994/06/29 06:35:28 cgd Exp $	*/
end_comment

begin_comment
comment|/*  * Written by Paul Popelka (paulp@uts.amdahl.com)  *  * You can do anything you want with this software, just don't say you wrote  * it, and don't remove this notice.  *  * This software is provided "as is".  *  * The author supplies this software to be publicly redistributed on the  * understanding that the author is not responsible for the correct  * functioning of this software in any circumstances and is not liable for  * any damages caused by this software.  *  * October 1992  */
end_comment

begin_comment
comment|/*  * Format of a boot sector.  This is the first sector on a DOS floppy disk  * or the fist sector of a partition on a hard disk.  But, it is not the  * first sector of a partitioned hard disk.  */
end_comment

begin_struct
struct|struct
name|bootsector33
block|{
name|u_char
name|bsJump
index|[
literal|3
index|]
decl_stmt|;
comment|/* jump instruction E9xxxx or EBxx90 */
name|char
name|bsOemName
index|[
literal|8
index|]
decl_stmt|;
comment|/* OEM name and version */
name|char
name|bsBPB
index|[
literal|19
index|]
decl_stmt|;
comment|/* BIOS parameter block */
name|char
name|bsDriveNumber
decl_stmt|;
comment|/* drive number (0x80) */
name|char
name|bsBootCode
index|[
literal|474
index|]
decl_stmt|;
comment|/* pad so structure is 512 bytes long */
name|u_short
name|bsBootSectSig
decl_stmt|;
define|#
directive|define
name|BOOTSIG
value|0xaa55
block|}
struct|;
end_struct

begin_struct
struct|struct
name|bootsector50
block|{
name|u_char
name|bsJump
index|[
literal|3
index|]
decl_stmt|;
comment|/* jump instruction E9xxxx or EBxx90 */
name|char
name|bsOemName
index|[
literal|8
index|]
decl_stmt|;
comment|/* OEM name and version */
name|char
name|bsBPB
index|[
literal|25
index|]
decl_stmt|;
comment|/* BIOS parameter block */
name|char
name|bsDriveNumber
decl_stmt|;
comment|/* drive number (0x80) */
name|char
name|bsReserved1
decl_stmt|;
comment|/* reserved */
name|char
name|bsBootSignature
decl_stmt|;
comment|/* extended boot signature (0x29) */
define|#
directive|define
name|EXBOOTSIG
value|0x29
name|char
name|bsVolumeID
index|[
literal|4
index|]
decl_stmt|;
comment|/* volume ID number */
name|char
name|bsVolumeLabel
index|[
literal|11
index|]
decl_stmt|;
comment|/* volume label */
name|char
name|bsFileSysType
index|[
literal|8
index|]
decl_stmt|;
comment|/* file system type (FAT12 or FAT16) */
name|char
name|bsBootCode
index|[
literal|448
index|]
decl_stmt|;
comment|/* pad so structure is 512 bytes long */
name|u_short
name|bsBootSectSig
decl_stmt|;
define|#
directive|define
name|BOOTSIG
value|0xaa55
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
block|}
union|;
end_union

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

end_unit

