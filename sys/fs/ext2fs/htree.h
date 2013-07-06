begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010, 2012 Zheng Liu<lz@freebsd.org>  * Copyright (c) 2012, Vyacheslav Matyushin  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_FS_EXT2FS_HTREE_H_
end_ifndef

begin_define
define|#
directive|define
name|_FS_EXT2FS_HTREE_H_
end_define

begin_comment
comment|/* EXT3 HTree directory indexing */
end_comment

begin_define
define|#
directive|define
name|EXT2_HTREE_LEGACY
value|0
end_define

begin_define
define|#
directive|define
name|EXT2_HTREE_HALF_MD4
value|1
end_define

begin_define
define|#
directive|define
name|EXT2_HTREE_TEA
value|2
end_define

begin_define
define|#
directive|define
name|EXT2_HTREE_LEGACY_UNSIGNED
value|3
end_define

begin_define
define|#
directive|define
name|EXT2_HTREE_HALF_MD4_UNSIGNED
value|4
end_define

begin_define
define|#
directive|define
name|EXT2_HTREE_TEA_UNSIGNED
value|5
end_define

begin_define
define|#
directive|define
name|EXT2_HTREE_EOF
value|0x7FFFFFFF
end_define

begin_struct
struct|struct
name|ext2fs_fake_direct
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
comment|/* length of string in d_name */
name|uint8_t
name|e2d_type
decl_stmt|;
comment|/* file type */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ext2fs_htree_count
block|{
name|uint16_t
name|h_entries_max
decl_stmt|;
name|uint16_t
name|h_entries_num
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ext2fs_htree_entry
block|{
name|uint32_t
name|h_hash
decl_stmt|;
name|uint32_t
name|h_blk
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ext2fs_htree_root_info
block|{
name|uint32_t
name|h_reserved1
decl_stmt|;
name|uint8_t
name|h_hash_version
decl_stmt|;
name|uint8_t
name|h_info_len
decl_stmt|;
name|uint8_t
name|h_ind_levels
decl_stmt|;
name|uint8_t
name|h_reserved2
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ext2fs_htree_root
block|{
name|struct
name|ext2fs_fake_direct
name|h_dot
decl_stmt|;
name|char
name|h_dot_name
index|[
literal|4
index|]
decl_stmt|;
name|struct
name|ext2fs_fake_direct
name|h_dotdot
decl_stmt|;
name|char
name|h_dotdot_name
index|[
literal|4
index|]
decl_stmt|;
name|struct
name|ext2fs_htree_root_info
name|h_info
decl_stmt|;
name|struct
name|ext2fs_htree_entry
name|h_entries
index|[
literal|0
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ext2fs_htree_node
block|{
name|struct
name|ext2fs_fake_direct
name|h_fake_dirent
decl_stmt|;
name|struct
name|ext2fs_htree_entry
name|h_entries
index|[
literal|0
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ext2fs_htree_lookup_level
block|{
name|struct
name|buf
modifier|*
name|h_bp
decl_stmt|;
name|struct
name|ext2fs_htree_entry
modifier|*
name|h_entries
decl_stmt|;
name|struct
name|ext2fs_htree_entry
modifier|*
name|h_entry
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ext2fs_htree_lookup_info
block|{
name|struct
name|ext2fs_htree_lookup_level
name|h_levels
index|[
literal|2
index|]
decl_stmt|;
name|uint32_t
name|h_levels_num
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ext2fs_htree_sort_entry
block|{
name|uint16_t
name|h_offset
decl_stmt|;
name|uint16_t
name|h_size
decl_stmt|;
name|uint32_t
name|h_hash
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_FS_EXT2FS_HTREE_H_ */
end_comment

end_unit

