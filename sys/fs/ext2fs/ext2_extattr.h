begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2017, Fedor Uporov  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_FS_EXT2FS_EXT2_EXTARTTR_H_
end_ifndef

begin_define
define|#
directive|define
name|_FS_EXT2FS_EXT2_EXTARTTR_H_
end_define

begin_comment
comment|/* Linux xattr name indexes */
end_comment

begin_define
define|#
directive|define
name|EXT4_XATTR_INDEX_USER
value|1
end_define

begin_define
define|#
directive|define
name|EXT4_XATTR_INDEX_POSIX_ACL_ACCESS
value|2
end_define

begin_define
define|#
directive|define
name|EXT4_XATTR_INDEX_POSIX_ACL_DEFAULT
value|3
end_define

begin_define
define|#
directive|define
name|EXT4_XATTR_INDEX_TRUSTED
value|4
end_define

begin_define
define|#
directive|define
name|EXT4_XATTR_INDEX_LUSTRE
value|5
end_define

begin_define
define|#
directive|define
name|EXT4_XATTR_INDEX_SECURITY
value|6
end_define

begin_define
define|#
directive|define
name|EXT4_XATTR_INDEX_SYSTEM
value|7
end_define

begin_define
define|#
directive|define
name|EXT4_XATTR_INDEX_RICHACL
value|8
end_define

begin_define
define|#
directive|define
name|EXT4_XATTR_INDEX_ENCRYPTION
value|9
end_define

begin_comment
comment|/* Magic value in attribute blocks */
end_comment

begin_define
define|#
directive|define
name|EXTATTR_MAGIC
value|0xEA020000
end_define

begin_comment
comment|/* Max EA name length */
end_comment

begin_define
define|#
directive|define
name|EXT2_EXTATTR_NAMELEN_MAX
value|255
end_define

begin_comment
comment|/* EA hash constants */
end_comment

begin_define
define|#
directive|define
name|EXT2_EXTATTR_NAME_HASH_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|EXT2_EXTATTR_VALUE_HASH_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|EXT2_EXTATTR_BLOCK_HASH_SHIFT
value|16
end_define

begin_struct
struct|struct
name|ext2fs_extattr_header
block|{
name|int32_t
name|h_magic
decl_stmt|;
comment|/* magic number for identification */
name|int32_t
name|h_refcount
decl_stmt|;
comment|/* reference count */
name|int32_t
name|h_blocks
decl_stmt|;
comment|/* number of disk blocks used */
name|int32_t
name|h_hash
decl_stmt|;
comment|/* hash value of all attributes */
name|uint32_t
name|h_reserved
index|[
literal|4
index|]
decl_stmt|;
comment|/* zero right now */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ext2fs_extattr_dinode_header
block|{
name|int32_t
name|h_magic
decl_stmt|;
comment|/* magic number for identification */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ext2fs_extattr_entry
block|{
name|uint8_t
name|e_name_len
decl_stmt|;
comment|/* length of name */
name|uint8_t
name|e_name_index
decl_stmt|;
comment|/* attribute name index */
name|uint16_t
name|e_value_offs
decl_stmt|;
comment|/* offset in disk block of value */
name|uint32_t
name|e_value_block
decl_stmt|;
comment|/* disk block attribute is stored on (n/i) */
name|uint32_t
name|e_value_size
decl_stmt|;
comment|/* size of attribute value */
name|uint32_t
name|e_hash
decl_stmt|;
comment|/* hash value of name and value */
name|char
name|e_name
index|[
literal|0
index|]
decl_stmt|;
comment|/* attribute name */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|EXT2_IFIRST
parameter_list|(
name|hdr
parameter_list|)
value|((struct ext2fs_extattr_entry *)((hdr)+1))
end_define

begin_define
define|#
directive|define
name|EXT2_HDR
parameter_list|(
name|bh
parameter_list|)
value|((struct ext2fs_extattr_header *)((bh)->b_data))
end_define

begin_define
define|#
directive|define
name|EXT2_ENTRY
parameter_list|(
name|ptr
parameter_list|)
value|((struct ext2fs_extattr_entry *)(ptr))
end_define

begin_define
define|#
directive|define
name|EXT2_FIRST_ENTRY
parameter_list|(
name|bh
parameter_list|)
value|EXT2_ENTRY(EXT2_HDR(bh)+1)
end_define

begin_define
define|#
directive|define
name|EXT2_IS_LAST_ENTRY
parameter_list|(
name|entry
parameter_list|)
value|(*(uint32_t *)(entry) == 0)
end_define

begin_define
define|#
directive|define
name|EXT2_EXTATTR_PAD_BITS
value|2
end_define

begin_define
define|#
directive|define
name|EXT2_EXTATTR_PAD
value|(1<<EXT2_EXTATTR_PAD_BITS)
end_define

begin_define
define|#
directive|define
name|EXT2_EXTATTR_ROUND
value|(EXT2_EXTATTR_PAD-1)
end_define

begin_define
define|#
directive|define
name|EXT2_EXTATTR_LEN
parameter_list|(
name|name_len
parameter_list|)
define|\
value|(((name_len) + EXT2_EXTATTR_ROUND + \ 	    sizeof(struct ext2fs_extattr_entry))& ~EXT2_EXTATTR_ROUND)
end_define

begin_define
define|#
directive|define
name|EXT2_EXTATTR_SIZE
parameter_list|(
name|size
parameter_list|)
define|\
value|(((size) + EXT2_EXTATTR_ROUND)& ~EXT2_EXTATTR_ROUND)
end_define

begin_define
define|#
directive|define
name|EXT2_EXTATTR_NEXT
parameter_list|(
name|entry
parameter_list|)
define|\
value|( (struct ext2fs_extattr_entry *)( \ 	    (char *)(entry) + EXT2_EXTATTR_LEN((entry)->e_name_len)) )
end_define

begin_function_decl
name|int
name|ext2_extattr_inode_delete
parameter_list|(
name|struct
name|inode
modifier|*
name|ip
parameter_list|,
name|int
name|attrnamespace
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ext2_extattr_block_delete
parameter_list|(
name|struct
name|inode
modifier|*
name|ip
parameter_list|,
name|int
name|attrnamespace
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ext2_extattr_free
parameter_list|(
name|struct
name|inode
modifier|*
name|ip
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ext2_extattr_inode_list
parameter_list|(
name|struct
name|inode
modifier|*
name|ip
parameter_list|,
name|int
name|attrnamespace
parameter_list|,
name|struct
name|uio
modifier|*
name|uio
parameter_list|,
name|size_t
modifier|*
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ext2_extattr_block_list
parameter_list|(
name|struct
name|inode
modifier|*
name|ip
parameter_list|,
name|int
name|attrnamespace
parameter_list|,
name|struct
name|uio
modifier|*
name|uio
parameter_list|,
name|size_t
modifier|*
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ext2_extattr_inode_get
parameter_list|(
name|struct
name|inode
modifier|*
name|ip
parameter_list|,
name|int
name|attrnamespace
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|struct
name|uio
modifier|*
name|uio
parameter_list|,
name|size_t
modifier|*
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ext2_extattr_block_get
parameter_list|(
name|struct
name|inode
modifier|*
name|ip
parameter_list|,
name|int
name|attrnamespace
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|struct
name|uio
modifier|*
name|uio
parameter_list|,
name|size_t
modifier|*
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ext2_extattr_inode_set
parameter_list|(
name|struct
name|inode
modifier|*
name|ip
parameter_list|,
name|int
name|attrnamespace
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|struct
name|uio
modifier|*
name|uio
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ext2_extattr_block_set
parameter_list|(
name|struct
name|inode
modifier|*
name|ip
parameter_list|,
name|int
name|attrnamespace
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|struct
name|uio
modifier|*
name|uio
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ext2_extattr_valid_attrname
parameter_list|(
name|int
name|attrnamespace
parameter_list|,
specifier|const
name|char
modifier|*
name|attrname
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_FS_EXT2FS_EXT2_EXTARTTR_H_ */
end_comment

end_unit

