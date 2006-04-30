begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1996, 1998 Robert Nordier  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR(S) ``AS IS'' AND ANY EXPRESS  * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR(S) BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE  * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN  * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DOSIO_H
end_ifndef

begin_define
define|#
directive|define
name|DOSIO_H
end_define

begin_comment
comment|/*  * DOS file attributes  */
end_comment

begin_define
define|#
directive|define
name|FA_RDONLY
value|001
end_define

begin_comment
comment|/* read-only */
end_comment

begin_define
define|#
directive|define
name|FA_HIDDEN
value|002
end_define

begin_comment
comment|/* hidden file */
end_comment

begin_define
define|#
directive|define
name|FA_SYSTEM
value|004
end_define

begin_comment
comment|/* system file */
end_comment

begin_define
define|#
directive|define
name|FA_LABEL
value|010
end_define

begin_comment
comment|/* volume label */
end_comment

begin_define
define|#
directive|define
name|FA_DIR
value|020
end_define

begin_comment
comment|/* directory */
end_comment

begin_define
define|#
directive|define
name|FA_ARCH
value|040
end_define

begin_comment
comment|/* archive (file modified) */
end_comment

begin_define
define|#
directive|define
name|FA_XDE
value|017
end_define

begin_comment
comment|/* extended directory entry */
end_comment

begin_define
define|#
directive|define
name|FA_MASK
value|077
end_define

begin_comment
comment|/* all attributes */
end_comment

begin_comment
comment|/*  * Macros to convert DOS-format 16-bit and 32-bit quantities  */
end_comment

begin_define
define|#
directive|define
name|cv2
parameter_list|(
name|p
parameter_list|)
value|((u_int16_t)(p)[0] |         \                 ((u_int16_t)(p)[1]<< 010))
end_define

begin_define
define|#
directive|define
name|cv4
parameter_list|(
name|p
parameter_list|)
value|((u_int32_t)(p)[0] |          \                 ((u_int32_t)(p)[1]<< 010) |  \                 ((u_int32_t)(p)[2]<< 020) |  \                 ((u_int32_t)(p)[3]<< 030))
end_define

begin_comment
comment|/*  * Directory, filesystem, and file structures.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_char
name|x_case
decl_stmt|;
comment|/* case */
name|u_char
name|c_hsec
decl_stmt|;
comment|/* created: secs/100 */
name|u_char
name|c_time
index|[
literal|2
index|]
decl_stmt|;
comment|/* created: time */
name|u_char
name|c_date
index|[
literal|2
index|]
decl_stmt|;
comment|/* created: date */
name|u_char
name|a_date
index|[
literal|2
index|]
decl_stmt|;
comment|/* accessed: date */
name|u_char
name|h_clus
index|[
literal|2
index|]
decl_stmt|;
comment|/* clus[hi] */
block|}
name|DOS_DEX
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_char
name|name
index|[
literal|8
index|]
decl_stmt|;
comment|/* name */
name|u_char
name|ext
index|[
literal|3
index|]
decl_stmt|;
comment|/* extension */
name|u_char
name|attr
decl_stmt|;
comment|/* attributes */
name|DOS_DEX
name|dex
decl_stmt|;
comment|/* VFAT/FAT32 only */
name|u_char
name|time
index|[
literal|2
index|]
decl_stmt|;
comment|/* modified: time */
name|u_char
name|date
index|[
literal|2
index|]
decl_stmt|;
comment|/* modified: date */
name|u_char
name|clus
index|[
literal|2
index|]
decl_stmt|;
comment|/* starting cluster */
name|u_char
name|size
index|[
literal|4
index|]
decl_stmt|;
comment|/* size */
block|}
name|DOS_DE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_char
name|seq
decl_stmt|;
comment|/* flags */
name|u_char
name|name1
index|[
literal|5
index|]
index|[
literal|2
index|]
decl_stmt|;
comment|/* 1st name area */
name|u_char
name|attr
decl_stmt|;
comment|/* (see fat_de) */
name|u_char
name|res
decl_stmt|;
comment|/* reserved */
name|u_char
name|chk
decl_stmt|;
comment|/* checksum */
name|u_char
name|name2
index|[
literal|6
index|]
index|[
literal|2
index|]
decl_stmt|;
comment|/* 2nd name area */
name|u_char
name|clus
index|[
literal|2
index|]
decl_stmt|;
comment|/* (see fat_de) */
name|u_char
name|name3
index|[
literal|2
index|]
index|[
literal|2
index|]
decl_stmt|;
comment|/* 3rd name area */
block|}
name|DOS_XDE
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
name|DOS_DE
name|de
decl_stmt|;
comment|/* standard directory entry */
name|DOS_XDE
name|xde
decl_stmt|;
comment|/* extended directory entry */
block|}
name|DOS_DIR
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|struct
name|open_file
modifier|*
name|fd
decl_stmt|;
comment|/* file descriptor */
name|u_char
modifier|*
name|buf
decl_stmt|;
comment|/* buffer */
name|u_int
name|bufsec
decl_stmt|;
comment|/* buffered sector */
name|u_int
name|links
decl_stmt|;
comment|/* active links to structure */
name|u_int
name|spc
decl_stmt|;
comment|/* sectors per cluster */
name|u_int
name|bsize
decl_stmt|;
comment|/* cluster size in bytes */
name|u_int
name|bshift
decl_stmt|;
comment|/* cluster conversion shift */
name|u_int
name|dirents
decl_stmt|;
comment|/* root directory entries */
name|u_int
name|spf
decl_stmt|;
comment|/* sectors per fat */
name|u_int
name|rdcl
decl_stmt|;
comment|/* root directory start cluster */
name|u_int
name|lsnfat
decl_stmt|;
comment|/* start of fat */
name|u_int
name|lsndir
decl_stmt|;
comment|/* start of root dir */
name|u_int
name|lsndta
decl_stmt|;
comment|/* start of data area */
name|u_int
name|fatsz
decl_stmt|;
comment|/* FAT entry size */
name|u_int
name|xclus
decl_stmt|;
comment|/* maximum cluster number */
block|}
name|DOS_FS
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|DOS_FS
modifier|*
name|fs
decl_stmt|;
comment|/* associated filesystem */
name|DOS_DE
name|de
decl_stmt|;
comment|/* directory entry */
name|u_int
name|offset
decl_stmt|;
comment|/* current offset */
name|u_int
name|c
decl_stmt|;
comment|/* last cluster read */
block|}
name|DOS_FILE
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !DOSIO_H */
end_comment

end_unit

