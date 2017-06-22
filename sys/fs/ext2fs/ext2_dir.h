begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2009 Aditya Sarawgi  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_FS_EXT2FS_EXT2_DIR_H_
end_ifndef

begin_define
define|#
directive|define
name|_FS_EXT2FS_EXT2_DIR_H_
end_define

begin_comment
comment|/*  * Structure of a directory entry  */
end_comment

begin_define
define|#
directive|define
name|EXT2FS_MAXNAMLEN
value|255
end_define

begin_struct
struct|struct
name|ext2fs_direct
block|{
name|uint32_t
name|e2d_ino
decl_stmt|;
comment|/* inode number of entry */
name|uint16_t
name|e2d_reclen
decl_stmt|;
comment|/* length of this record */
name|uint16_t
name|e2d_namlen
decl_stmt|;
comment|/* length of string in e2d_name */
name|char
name|e2d_name
index|[
name|EXT2FS_MAXNAMLEN
index|]
decl_stmt|;
comment|/* name with length<=EXT2FS_MAXNAMLEN */
block|}
struct|;
end_struct

begin_enum
enum|enum
name|slotstatus
block|{
name|NONE
block|,
name|COMPACT
block|,
name|FOUND
block|}
enum|;
end_enum

begin_struct
struct|struct
name|ext2fs_searchslot
block|{
name|enum
name|slotstatus
name|slotstatus
decl_stmt|;
name|doff_t
name|slotoffset
decl_stmt|;
comment|/* offset of area with free space */
name|int
name|slotsize
decl_stmt|;
comment|/* size of area at slotoffset */
name|int
name|slotfreespace
decl_stmt|;
comment|/* amount of space free in slot */
name|int
name|slotneeded
decl_stmt|;
comment|/* sizeof the entry we are seeking */
block|}
struct|;
end_struct

begin_comment
comment|/*  * The new version of the directory entry.  Since EXT2 structures are  * stored in intel byte order, and the name_len field could never be  * bigger than 255 chars, it's safe to reclaim the extra byte for the  * file_type field.  */
end_comment

begin_struct
struct|struct
name|ext2fs_direct_2
block|{
name|uint32_t
name|e2d_ino
decl_stmt|;
comment|/* inode number of entry */
name|uint16_t
name|e2d_reclen
decl_stmt|;
comment|/* length of this record */
name|uint8_t
name|e2d_namlen
decl_stmt|;
comment|/* length of string in e2d_name */
name|uint8_t
name|e2d_type
decl_stmt|;
comment|/* file type */
name|char
name|e2d_name
index|[
name|EXT2FS_MAXNAMLEN
index|]
decl_stmt|;
comment|/* name with 						 * length<=EXT2FS_MAXNAMLEN */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Maximal count of links to a file  */
end_comment

begin_define
define|#
directive|define
name|EXT2_LINK_MAX
value|32000
end_define

begin_define
define|#
directive|define
name|EXT4_LINK_MAX
value|65000
end_define

begin_comment
comment|/*  * Ext2 directory file types.  Only the low 3 bits are used.  The  * other bits are reserved for now.  */
end_comment

begin_define
define|#
directive|define
name|EXT2_FT_UNKNOWN
value|0
end_define

begin_define
define|#
directive|define
name|EXT2_FT_REG_FILE
value|1
end_define

begin_define
define|#
directive|define
name|EXT2_FT_DIR
value|2
end_define

begin_define
define|#
directive|define
name|EXT2_FT_CHRDEV
value|3
end_define

begin_define
define|#
directive|define
name|EXT2_FT_BLKDEV
value|4
end_define

begin_define
define|#
directive|define
name|EXT2_FT_FIFO
value|5
end_define

begin_define
define|#
directive|define
name|EXT2_FT_SOCK
value|6
end_define

begin_define
define|#
directive|define
name|EXT2_FT_SYMLINK
value|7
end_define

begin_define
define|#
directive|define
name|EXT2_FT_MAX
value|8
end_define

begin_comment
comment|/*  * EXT2_DIR_PAD defines the directory entries boundaries  *  * NOTE: It must be a multiple of 4  */
end_comment

begin_define
define|#
directive|define
name|EXT2_DIR_PAD
value|4
end_define

begin_define
define|#
directive|define
name|EXT2_DIR_ROUND
value|(EXT2_DIR_PAD - 1)
end_define

begin_define
define|#
directive|define
name|EXT2_DIR_REC_LEN
parameter_list|(
name|name_len
parameter_list|)
value|(((name_len) + 8 + EXT2_DIR_ROUND)& \ 					 ~EXT2_DIR_ROUND)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_FS_EXT2FS_EXT2_DIR_H_ */
end_comment

end_unit

