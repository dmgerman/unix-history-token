begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995 Joerg Wunsch  *  * All rights reserved.  *  * This program is free software.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE DEVELOPERS ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE DEVELOPERS BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * MS-DOS (FAT) file system structure definitions.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DOSFS_H
end_ifndef

begin_define
define|#
directive|define
name|DOSFS_H
value|1
end_define

begin_typedef
typedef|typedef
name|u_char
name|Long
index|[
literal|4
index|]
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_char
name|Short
index|[
literal|2
index|]
typedef|;
end_typedef

begin_union
union|union
name|bootsector
block|{
name|unsigned
name|char
name|raw
index|[
literal|512
index|]
decl_stmt|;
struct|struct
name|bsec
block|{
name|u_char
name|jump_boot
index|[
literal|3
index|]
decl_stmt|;
comment|/* jump code to boot-up partition */
name|char
name|oem_name
index|[
literal|8
index|]
decl_stmt|;
comment|/* OEM company name& version */
name|Short
name|sectsiz
decl_stmt|;
comment|/* bytes per sector */
name|u_char
name|clustsiz
decl_stmt|;
comment|/* sectors per cluster */
name|Short
name|ressecs
decl_stmt|;
comment|/* reserved sectors [before 1st FAT] */
name|u_char
name|fatcnt
decl_stmt|;
comment|/* # of FAT's */
name|Short
name|rootsiz
decl_stmt|;
comment|/* number of root dir entries */
name|Short
name|totsecs
decl_stmt|;
comment|/* total # of sectors */
name|u_char
name|media
decl_stmt|;
comment|/* media descriptor */
name|Short
name|fatsize
decl_stmt|;
comment|/* # of sectors per FAT */
name|Short
name|trksecs
decl_stmt|;
comment|/* sectors per track (cylinder) */
name|Short
name|headcnt
decl_stmt|;
comment|/* # of r/w heads */
name|Short
name|hidnsec
decl_stmt|;
comment|/* hidden sectors */
union|union
block|{
comment|/* case totsecs != 0: */
comment|/* This is a partition of MS-DOS 3.3 format (< 32 MB) */
name|u_char
name|bootprogram
index|[
literal|480
index|]
decl_stmt|;
comment|/* case totsecs == 0: */
comment|/* partition of MS-DOS 4.0+ format, or> 32 MB */
struct|struct
block|{
name|Short
name|unused
decl_stmt|;
name|Long
name|totsecs
decl_stmt|;
comment|/* total # of sectors, as a 32-bit */
name|Short
name|physdrv
decl_stmt|;
comment|/* physical drive # [0x80...] */
name|u_char
name|extboot
decl_stmt|;
comment|/* extended boot signature??? */
name|Long
name|serial
decl_stmt|;
comment|/* volume serial number */
name|char
name|label
index|[
literal|11
index|]
decl_stmt|;
comment|/* same as volume label in root dir */
name|char
name|fsysid
index|[
literal|8
index|]
decl_stmt|;
comment|/* some like `FAT16' */
name|u_char
name|bootprogram
index|[
literal|448
index|]
decl_stmt|;
block|}
name|extended
struct|;
block|}
name|variable_part
union|;
name|u_char
name|signature
index|[
literal|2
index|]
decl_stmt|;
comment|/* always {0x55, 0xaa} */
block|}
name|bsec
struct|;
block|}
union|;
end_union

begin_struct
struct|struct
name|fat
block|{
name|u_char
name|media
decl_stmt|;
comment|/* the media descriptor again */
name|u_char
name|padded
decl_stmt|;
comment|/* alway 0xff */
name|u_char
name|contents
index|[
literal|1
index|]
decl_stmt|;
comment|/* the `1' is a placeholder only */
block|}
struct|;
end_struct

begin_comment
comment|/* DOS file attributes */
end_comment

begin_define
define|#
directive|define
name|FA_RONLY
value|1
end_define

begin_comment
comment|/* read/only */
end_comment

begin_define
define|#
directive|define
name|FA_HIDDEN
value|2
end_define

begin_comment
comment|/* hidden */
end_comment

begin_define
define|#
directive|define
name|FA_SYSTEM
value|4
end_define

begin_comment
comment|/* system */
end_comment

begin_define
define|#
directive|define
name|FA_VOLLABEL
value|8
end_define

begin_comment
comment|/* this is the volume label */
end_comment

begin_define
define|#
directive|define
name|FA_SUBDIR
value|0x10
end_define

begin_comment
comment|/* sub-directory */
end_comment

begin_define
define|#
directive|define
name|FA_ARCH
value|0x20
end_define

begin_comment
comment|/* archive - file hasn't been backed up */
end_comment

begin_struct
struct|struct
name|dosftime
block|{
name|u_char
name|time
index|[
literal|2
index|]
decl_stmt|;
comment|/* [0]& 0x1f - seconds div 2 			 * ([1]& 7) * 8 + ([0]>> 5) - minutes 			 * [1]>> 3   - hours 			 */
name|u_char
name|date
index|[
literal|2
index|]
decl_stmt|;
comment|/* [0]& 0x1f - day 			 * ([1]& 1) * 8 + ([0]>> 5) - month 			 * [1]>> 1   - year - 1980 			 */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|dosft_hour
parameter_list|(
name|dft
parameter_list|)
value|((dft).time[1]>> 3)
end_define

begin_define
define|#
directive|define
name|dosft_minute
parameter_list|(
name|dft
parameter_list|)
value|(((dft).time[1]& 7) * 8 + ((dft).time[0]>> 5))
end_define

begin_define
define|#
directive|define
name|dosft_second
parameter_list|(
name|dft
parameter_list|)
value|(((dft).time[0]& 0x1f) * 2)
end_define

begin_define
define|#
directive|define
name|dosft_year
parameter_list|(
name|dft
parameter_list|)
value|(((dft).date[1]>> 1) + 1980)
end_define

begin_define
define|#
directive|define
name|dosft_month
parameter_list|(
name|dft
parameter_list|)
value|(((dft).date[1]& 1) * 8 + ((dft).date[0]>> 5))
end_define

begin_define
define|#
directive|define
name|dosft_day
parameter_list|(
name|dft
parameter_list|)
value|((dft).date[0]& 0x1f)
end_define

begin_struct
struct|struct
name|direntry
block|{
name|char
name|name
index|[
literal|8
index|]
decl_stmt|;
comment|/* file name portion */
name|char
name|ext
index|[
literal|3
index|]
decl_stmt|;
comment|/* file extension */
name|u_char
name|attr
decl_stmt|;
comment|/* file attribute as above */
name|char
name|reserved
index|[
literal|10
index|]
decl_stmt|;
name|struct
name|dosftime
name|fdate
decl_stmt|;
comment|/* time created/last modified */
name|Short
name|startclstr
decl_stmt|;
comment|/* starting cluster number */
name|Long
name|filesiz
decl_stmt|;
comment|/* file size in bytes */
block|}
struct|;
end_struct

begin_comment
comment|/* handle endiannes: */
end_comment

begin_define
define|#
directive|define
name|s_to_little_s
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
value|dst[0]=(src)&0xff; dst[1]=((src)&0xff00)>>8
end_define

begin_define
define|#
directive|define
name|l_to_little_l
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|dst[0]=(src)&0xff; dst[1]=((src)&0xff00)>>8; \ dst[2]=((src)&0xff0000)>>16; dst[3]=((src)&0xff000000)>>24
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DOSFS_H */
end_comment

end_unit

