begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2012, 2010 Zheng Liu<lz@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_FS_EXT2FS_EXT2_EXTENTS_H_
end_ifndef

begin_define
define|#
directive|define
name|_FS_EXT2FS_EXT2_EXTENTS_H_
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_define
define|#
directive|define
name|EXT4_EXT_MAGIC
value|0xf30a
end_define

begin_define
define|#
directive|define
name|EXT4_EXT_CACHE_NO
value|0
end_define

begin_define
define|#
directive|define
name|EXT4_EXT_CACHE_GAP
value|1
end_define

begin_define
define|#
directive|define
name|EXT4_EXT_CACHE_IN
value|2
end_define

begin_comment
comment|/*  * Ext4 file system extent on disk.  */
end_comment

begin_struct
struct|struct
name|ext4_extent
block|{
name|uint32_t
name|e_blk
decl_stmt|;
comment|/* first logical block */
name|uint16_t
name|e_len
decl_stmt|;
comment|/* number of blocks */
name|uint16_t
name|e_start_hi
decl_stmt|;
comment|/* high 16 bits of physical block */
name|uint32_t
name|e_start_lo
decl_stmt|;
comment|/* low 32 bits of physical block */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Extent index on disk.  */
end_comment

begin_struct
struct|struct
name|ext4_extent_index
block|{
name|uint32_t
name|ei_blk
decl_stmt|;
comment|/* indexes logical blocks */
name|uint32_t
name|ei_leaf_lo
decl_stmt|;
comment|/* points to physical block of the 				 * next level */
name|uint16_t
name|ei_leaf_hi
decl_stmt|;
comment|/* high 16 bits of physical block */
name|uint16_t
name|ei_unused
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Extent tree header.  */
end_comment

begin_struct
struct|struct
name|ext4_extent_header
block|{
name|uint16_t
name|eh_magic
decl_stmt|;
comment|/* magic number: 0xf30a */
name|uint16_t
name|eh_ecount
decl_stmt|;
comment|/* number of valid entries */
name|uint16_t
name|eh_max
decl_stmt|;
comment|/* capacity of store in entries */
name|uint16_t
name|eh_depth
decl_stmt|;
comment|/* the depth of extent tree */
name|uint32_t
name|eh_gen
decl_stmt|;
comment|/* generation of extent tree */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Save cached extent.  */
end_comment

begin_struct
struct|struct
name|ext4_extent_cache
block|{
name|daddr_t
name|ec_start
decl_stmt|;
comment|/* extent start */
name|uint32_t
name|ec_blk
decl_stmt|;
comment|/* logical block */
name|uint32_t
name|ec_len
decl_stmt|;
name|uint32_t
name|ec_type
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Save path to some extent.  */
end_comment

begin_struct
struct|struct
name|ext4_extent_path
block|{
name|uint16_t
name|ep_depth
decl_stmt|;
name|struct
name|buf
modifier|*
name|ep_bp
decl_stmt|;
name|struct
name|ext4_extent
modifier|*
name|ep_ext
decl_stmt|;
name|struct
name|ext4_extent_index
modifier|*
name|ep_index
decl_stmt|;
name|struct
name|ext4_extent_header
modifier|*
name|ep_header
decl_stmt|;
block|}
struct|;
end_struct

begin_struct_decl
struct_decl|struct
name|inode
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|m_ext2fs
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|ext4_ext_in_cache
parameter_list|(
name|struct
name|inode
modifier|*
parameter_list|,
name|daddr_t
parameter_list|,
name|struct
name|ext4_extent
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ext4_ext_put_cache
parameter_list|(
name|struct
name|inode
modifier|*
parameter_list|,
name|struct
name|ext4_extent
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ext4_extent_path
modifier|*
name|ext4_ext_find_extent
parameter_list|(
name|struct
name|m_ext2fs
modifier|*
name|fs
parameter_list|,
name|struct
name|inode
modifier|*
parameter_list|,
name|daddr_t
parameter_list|,
name|struct
name|ext4_extent_path
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_FS_EXT2FS_EXT2_EXTENTS_H_ */
end_comment

end_unit

