begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*	$NetBSD: bpb.h,v 1.3 1994/06/29 06:35:29 cgd Exp $	*/
end_comment

begin_comment
comment|/*  * Written by Paul Popelka (paulp@uts.amdahl.com)  *  * You can do anything you want with this software, just don't say you wrote  * it, and don't remove this notice.  *  * This software is provided "as is".  *  * The author supplies this software to be publicly redistributed on the  * understanding that the author is not responsible for the correct  * functioning of this software in any circumstances and is not liable for  * any damages caused by this software.  *  * October 1992  */
end_comment

begin_comment
comment|/*  * BIOS Parameter Block (BPB) for DOS 3.3  */
end_comment

begin_struct
struct|struct
name|bpb33
block|{
name|u_short
name|bpbBytesPerSec
decl_stmt|;
comment|/* bytes per sector */
name|u_char
name|bpbSecPerClust
decl_stmt|;
comment|/* sectors per cluster */
name|u_short
name|bpbResSectors
decl_stmt|;
comment|/* number of reserved sectors */
name|u_char
name|bpbFATs
decl_stmt|;
comment|/* number of FATs */
name|u_short
name|bpbRootDirEnts
decl_stmt|;
comment|/* number of root directory entries */
name|u_short
name|bpbSectors
decl_stmt|;
comment|/* total number of sectors */
name|u_char
name|bpbMedia
decl_stmt|;
comment|/* media descriptor */
name|u_short
name|bpbFATsecs
decl_stmt|;
comment|/* number of sectors per FAT */
name|u_short
name|bpbSecPerTrack
decl_stmt|;
comment|/* sectors per track */
name|u_short
name|bpbHeads
decl_stmt|;
comment|/* number of heads */
name|u_short
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
name|u_short
name|bpbBytesPerSec
decl_stmt|;
comment|/* bytes per sector */
name|u_char
name|bpbSecPerClust
decl_stmt|;
comment|/* sectors per cluster */
name|u_short
name|bpbResSectors
decl_stmt|;
comment|/* number of reserved sectors */
name|u_char
name|bpbFATs
decl_stmt|;
comment|/* number of FATs */
name|u_short
name|bpbRootDirEnts
decl_stmt|;
comment|/* number of root directory entries */
name|u_short
name|bpbSectors
decl_stmt|;
comment|/* total number of sectors */
name|u_char
name|bpbMedia
decl_stmt|;
comment|/* media descriptor */
name|u_short
name|bpbFATsecs
decl_stmt|;
comment|/* number of sectors per FAT */
name|u_short
name|bpbSecPerTrack
decl_stmt|;
comment|/* sectors per track */
name|u_short
name|bpbHeads
decl_stmt|;
comment|/* number of heads */
name|u_long
name|bpbHiddenSecs
decl_stmt|;
comment|/* number of hidden sectors */
name|u_long
name|bpbHugeSectors
decl_stmt|;
comment|/* number of sectrs if bpbSectors == 0 */
block|}
struct|;
end_struct

begin_comment
comment|/*  * The following structures represent how the bpb's look on disk.  shorts  * and longs are just character arrays of the appropriate length.  This is  * because the compiler forces shorts and longs to align on word or  * halfword boundaries.  *  * XXX The little-endian code here assumes that the processor can access  * 16-bit and 32-bit quantities on byte boundaries.  If this is not true,  * use the macros for the big-endian case.  */
end_comment

begin_include
include|#
directive|include
file|<machine/endian.h>
end_include

begin_if
if|#
directive|if
name|BYTE_ORDER
operator|==
name|LITTLE_ENDIAN
end_if

begin_comment
comment|/*&& can do unaligned accesses */
end_comment

begin_define
define|#
directive|define
name|getushort
parameter_list|(
name|x
parameter_list|)
value|*((u_short *)(x))
end_define

begin_define
define|#
directive|define
name|getulong
parameter_list|(
name|x
parameter_list|)
value|*((u_long *)(x))
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
value|(*((u_short *)(p)) = (v))
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
value|(*((u_long *)(p)) = (v))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|getushort
parameter_list|(
name|x
parameter_list|)
value|(((u_char *)(x))[0] + (((u_char *)(x))[1]<< 8))
end_define

begin_define
define|#
directive|define
name|getulong
parameter_list|(
name|x
parameter_list|)
value|(((u_char *)(x))[0] + (((u_char *)(x))[1]<< 8) \ 			 + (((u_char *)(x))[2]<< 16)	\ 			 + (((u_char *)(x))[3]<< 24))
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
value|(((u_char *)(p))[0] = (v),	\ 			 ((u_char *)(p))[1] = (v)>> 8)
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
value|(((u_char *)(p))[0] = (v),	\ 			 ((u_char *)(p))[1] = (v)>> 8, \ 			 ((u_char *)(p))[2] = (v)>> 16,\ 			 ((u_char *)(p))[3] = (v)>> 24)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * BIOS Parameter Block (BPB) for DOS 3.3  */
end_comment

begin_struct
struct|struct
name|byte_bpb33
block|{
name|char
name|bpbBytesPerSec
index|[
literal|2
index|]
decl_stmt|;
comment|/* bytes per sector */
name|char
name|bpbSecPerClust
decl_stmt|;
comment|/* sectors per cluster */
name|char
name|bpbResSectors
index|[
literal|2
index|]
decl_stmt|;
comment|/* number of reserved sectors */
name|char
name|bpbFATs
decl_stmt|;
comment|/* number of FATs */
name|char
name|bpbRootDirEnts
index|[
literal|2
index|]
decl_stmt|;
comment|/* number of root directory entries */
name|char
name|bpbSectors
index|[
literal|2
index|]
decl_stmt|;
comment|/* total number of sectors */
name|char
name|bpbMedia
decl_stmt|;
comment|/* media descriptor */
name|char
name|bpbFATsecs
index|[
literal|2
index|]
decl_stmt|;
comment|/* number of sectors per FAT */
name|char
name|bpbSecPerTrack
index|[
literal|2
index|]
decl_stmt|;
comment|/* sectors per track */
name|char
name|bpbHeads
index|[
literal|2
index|]
decl_stmt|;
comment|/* number of heads */
name|char
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
name|char
name|bpbBytesPerSec
index|[
literal|2
index|]
decl_stmt|;
comment|/* bytes per sector */
name|char
name|bpbSecPerClust
decl_stmt|;
comment|/* sectors per cluster */
name|char
name|bpbResSectors
index|[
literal|2
index|]
decl_stmt|;
comment|/* number of reserved sectors */
name|char
name|bpbFATs
decl_stmt|;
comment|/* number of FATs */
name|char
name|bpbRootDirEnts
index|[
literal|2
index|]
decl_stmt|;
comment|/* number of root directory entries */
name|char
name|bpbSectors
index|[
literal|2
index|]
decl_stmt|;
comment|/* total number of sectors */
name|char
name|bpbMedia
decl_stmt|;
comment|/* media descriptor */
name|char
name|bpbFATsecs
index|[
literal|2
index|]
decl_stmt|;
comment|/* number of sectors per FAT */
name|char
name|bpbSecPerTrack
index|[
literal|2
index|]
decl_stmt|;
comment|/* sectors per track */
name|char
name|bpbHeads
index|[
literal|2
index|]
decl_stmt|;
comment|/* number of heads */
name|char
name|bpbHiddenSecs
index|[
literal|4
index|]
decl_stmt|;
comment|/* number of hidden sectors */
name|char
name|bpbHugeSectors
index|[
literal|4
index|]
decl_stmt|;
comment|/* number of sectrs if bpbSectors == 0 */
block|}
struct|;
end_struct

end_unit

