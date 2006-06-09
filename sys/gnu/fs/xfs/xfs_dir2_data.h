begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000,2005 Silicon Graphics, Inc.  * All Rights Reserved.  *  * This program is free software; you can redistribute it and/or  * modify it under the terms of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it would be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write the Free Software Foundation,  * Inc.,  51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XFS_DIR2_DATA_H__
end_ifndef

begin_define
define|#
directive|define
name|__XFS_DIR2_DATA_H__
end_define

begin_comment
comment|/*  * Directory format 2, data block structures.  */
end_comment

begin_struct_decl
struct_decl|struct
name|xfs_dabuf
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_da_args
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_inode
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_trans
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * Constants.  */
end_comment

begin_define
define|#
directive|define
name|XFS_DIR2_DATA_MAGIC
value|0x58443244
end_define

begin_comment
comment|/* XD2D: for multiblock dirs */
end_comment

begin_define
define|#
directive|define
name|XFS_DIR2_DATA_ALIGN_LOG
value|3
end_define

begin_comment
comment|/* i.e., 8 bytes */
end_comment

begin_define
define|#
directive|define
name|XFS_DIR2_DATA_ALIGN
value|(1<< XFS_DIR2_DATA_ALIGN_LOG)
end_define

begin_define
define|#
directive|define
name|XFS_DIR2_DATA_FREE_TAG
value|0xffff
end_define

begin_define
define|#
directive|define
name|XFS_DIR2_DATA_FD_COUNT
value|3
end_define

begin_comment
comment|/*  * Directory address space divided into sections,  * spaces separated by 32gb.  */
end_comment

begin_define
define|#
directive|define
name|XFS_DIR2_SPACE_SIZE
value|(1ULL<< (32 + XFS_DIR2_DATA_ALIGN_LOG))
end_define

begin_define
define|#
directive|define
name|XFS_DIR2_DATA_SPACE
value|0
end_define

begin_define
define|#
directive|define
name|XFS_DIR2_DATA_OFFSET
value|(XFS_DIR2_DATA_SPACE * XFS_DIR2_SPACE_SIZE)
end_define

begin_define
define|#
directive|define
name|XFS_DIR2_DATA_FIRSTDB
parameter_list|(
name|mp
parameter_list|)
define|\
value|XFS_DIR2_BYTE_TO_DB(mp, XFS_DIR2_DATA_OFFSET)
end_define

begin_comment
comment|/*  * Offsets of . and .. in data space (always block 0)  */
end_comment

begin_define
define|#
directive|define
name|XFS_DIR2_DATA_DOT_OFFSET
define|\
value|((xfs_dir2_data_aoff_t)sizeof(xfs_dir2_data_hdr_t))
end_define

begin_define
define|#
directive|define
name|XFS_DIR2_DATA_DOTDOT_OFFSET
define|\
value|(XFS_DIR2_DATA_DOT_OFFSET + XFS_DIR2_DATA_ENTSIZE(1))
end_define

begin_define
define|#
directive|define
name|XFS_DIR2_DATA_FIRST_OFFSET
define|\
value|(XFS_DIR2_DATA_DOTDOT_OFFSET + XFS_DIR2_DATA_ENTSIZE(2))
end_define

begin_comment
comment|/*  * Structures.  */
end_comment

begin_comment
comment|/*  * Describe a free area in the data block.  * The freespace will be formatted as a xfs_dir2_data_unused_t.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xfs_dir2_data_free
block|{
name|__be16
name|offset
decl_stmt|;
comment|/* start of freespace */
name|__be16
name|length
decl_stmt|;
comment|/* length of freespace */
block|}
name|xfs_dir2_data_free_t
typedef|;
end_typedef

begin_comment
comment|/*  * Header for the data blocks.  * Always at the beginning of a directory-sized block.  * The code knows that XFS_DIR2_DATA_FD_COUNT is 3.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xfs_dir2_data_hdr
block|{
name|__be32
name|magic
decl_stmt|;
comment|/* XFS_DIR2_DATA_MAGIC */
comment|/* or XFS_DIR2_BLOCK_MAGIC */
name|xfs_dir2_data_free_t
name|bestfree
index|[
name|XFS_DIR2_DATA_FD_COUNT
index|]
decl_stmt|;
block|}
name|xfs_dir2_data_hdr_t
typedef|;
end_typedef

begin_comment
comment|/*  * Active entry in a data block.  Aligned to 8 bytes.  * Tag appears as the last 2 bytes.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xfs_dir2_data_entry
block|{
name|xfs_ino_t
name|inumber
decl_stmt|;
comment|/* inode number */
name|__uint8_t
name|namelen
decl_stmt|;
comment|/* name length */
name|__uint8_t
name|name
index|[
literal|1
index|]
decl_stmt|;
comment|/* name bytes, no null */
comment|/* variable offset */
name|xfs_dir2_data_off_t
name|tag
decl_stmt|;
comment|/* starting offset of us */
block|}
name|xfs_dir2_data_entry_t
typedef|;
end_typedef

begin_comment
comment|/*  * Unused entry in a data block.  Aligned to 8 bytes.  * Tag appears as the last 2 bytes.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xfs_dir2_data_unused
block|{
name|__be16
name|freetag
decl_stmt|;
comment|/* XFS_DIR2_DATA_FREE_TAG */
name|__be16
name|length
decl_stmt|;
comment|/* total free length */
comment|/* variable offset */
name|__be16
name|tag
decl_stmt|;
comment|/* starting offset of us */
block|}
name|xfs_dir2_data_unused_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
name|xfs_dir2_data_entry_t
name|entry
decl_stmt|;
name|xfs_dir2_data_unused_t
name|unused
decl_stmt|;
block|}
name|xfs_dir2_data_union_t
typedef|;
end_typedef

begin_comment
comment|/*  * Generic data block structure, for xfs_db.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xfs_dir2_data
block|{
name|xfs_dir2_data_hdr_t
name|hdr
decl_stmt|;
comment|/* magic XFS_DIR2_DATA_MAGIC */
name|xfs_dir2_data_union_t
name|u
index|[
literal|1
index|]
decl_stmt|;
block|}
name|xfs_dir2_data_t
typedef|;
end_typedef

begin_comment
comment|/*  * Macros.  */
end_comment

begin_comment
comment|/*  * Size of a data entry.  */
end_comment

begin_define
define|#
directive|define
name|XFS_DIR2_DATA_ENTSIZE
parameter_list|(
name|n
parameter_list|)
value|xfs_dir2_data_entsize(n)
end_define

begin_function
specifier|static
specifier|inline
name|int
name|xfs_dir2_data_entsize
parameter_list|(
name|int
name|n
parameter_list|)
block|{
return|return
operator|(
name|int
operator|)
name|roundup
argument_list|(
name|offsetof
argument_list|(
name|xfs_dir2_data_entry_t
argument_list|,
name|name
index|[
literal|0
index|]
argument_list|)
operator|+
operator|(
name|n
operator|)
operator|+
expr|\
operator|(
name|uint
operator|)
sizeof|sizeof
argument_list|(
name|xfs_dir2_data_off_t
argument_list|)
argument_list|,
name|XFS_DIR2_DATA_ALIGN
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/*  * Pointer to an entry's tag word.  */
end_comment

begin_define
define|#
directive|define
name|XFS_DIR2_DATA_ENTRY_TAG_P
parameter_list|(
name|dep
parameter_list|)
value|xfs_dir2_data_entry_tag_p(dep)
end_define

begin_function
specifier|static
specifier|inline
name|__be16
modifier|*
name|xfs_dir2_data_entry_tag_p
parameter_list|(
name|xfs_dir2_data_entry_t
modifier|*
name|dep
parameter_list|)
block|{
return|return
operator|(
name|__be16
operator|*
operator|)
operator|(
operator|(
name|char
operator|*
operator|)
name|dep
operator|+
name|XFS_DIR2_DATA_ENTSIZE
argument_list|(
name|dep
operator|->
name|namelen
argument_list|)
operator|-
sizeof|sizeof
argument_list|(
name|__be16
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Pointer to a freespace's tag word.  */
end_comment

begin_define
define|#
directive|define
name|XFS_DIR2_DATA_UNUSED_TAG_P
parameter_list|(
name|dup
parameter_list|)
define|\
value|xfs_dir2_data_unused_tag_p(dup)
end_define

begin_function
specifier|static
specifier|inline
name|__be16
modifier|*
name|xfs_dir2_data_unused_tag_p
parameter_list|(
name|xfs_dir2_data_unused_t
modifier|*
name|dup
parameter_list|)
block|{
return|return
operator|(
name|__be16
operator|*
operator|)
operator|(
operator|(
name|char
operator|*
operator|)
name|dup
operator|+
name|be16_to_cpu
argument_list|(
name|dup
operator|->
name|length
argument_list|)
operator|-
sizeof|sizeof
argument_list|(
name|__be16
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Function declarations.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_function_decl
specifier|extern
name|void
name|xfs_dir2_data_check
parameter_list|(
name|struct
name|xfs_inode
modifier|*
name|dp
parameter_list|,
name|struct
name|xfs_dabuf
modifier|*
name|bp
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|xfs_dir2_data_check
parameter_list|(
name|dp
parameter_list|,
name|bp
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|xfs_dir2_data_free_t
modifier|*
name|xfs_dir2_data_freefind
parameter_list|(
name|xfs_dir2_data_t
modifier|*
name|d
parameter_list|,
name|xfs_dir2_data_unused_t
modifier|*
name|dup
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|xfs_dir2_data_free_t
modifier|*
name|xfs_dir2_data_freeinsert
parameter_list|(
name|xfs_dir2_data_t
modifier|*
name|d
parameter_list|,
name|xfs_dir2_data_unused_t
modifier|*
name|dup
parameter_list|,
name|int
modifier|*
name|loghead
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|xfs_dir2_data_freescan
parameter_list|(
name|struct
name|xfs_mount
modifier|*
name|mp
parameter_list|,
name|xfs_dir2_data_t
modifier|*
name|d
parameter_list|,
name|int
modifier|*
name|loghead
parameter_list|,
name|char
modifier|*
name|aendp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|xfs_dir2_data_init
parameter_list|(
name|struct
name|xfs_da_args
modifier|*
name|args
parameter_list|,
name|xfs_dir2_db_t
name|blkno
parameter_list|,
name|struct
name|xfs_dabuf
modifier|*
modifier|*
name|bpp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|xfs_dir2_data_log_entry
parameter_list|(
name|struct
name|xfs_trans
modifier|*
name|tp
parameter_list|,
name|struct
name|xfs_dabuf
modifier|*
name|bp
parameter_list|,
name|xfs_dir2_data_entry_t
modifier|*
name|dep
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|xfs_dir2_data_log_header
parameter_list|(
name|struct
name|xfs_trans
modifier|*
name|tp
parameter_list|,
name|struct
name|xfs_dabuf
modifier|*
name|bp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|xfs_dir2_data_log_unused
parameter_list|(
name|struct
name|xfs_trans
modifier|*
name|tp
parameter_list|,
name|struct
name|xfs_dabuf
modifier|*
name|bp
parameter_list|,
name|xfs_dir2_data_unused_t
modifier|*
name|dup
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|xfs_dir2_data_make_free
parameter_list|(
name|struct
name|xfs_trans
modifier|*
name|tp
parameter_list|,
name|struct
name|xfs_dabuf
modifier|*
name|bp
parameter_list|,
name|xfs_dir2_data_aoff_t
name|offset
parameter_list|,
name|xfs_dir2_data_aoff_t
name|len
parameter_list|,
name|int
modifier|*
name|needlogp
parameter_list|,
name|int
modifier|*
name|needscanp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|xfs_dir2_data_use_free
parameter_list|(
name|struct
name|xfs_trans
modifier|*
name|tp
parameter_list|,
name|struct
name|xfs_dabuf
modifier|*
name|bp
parameter_list|,
name|xfs_dir2_data_unused_t
modifier|*
name|dup
parameter_list|,
name|xfs_dir2_data_aoff_t
name|offset
parameter_list|,
name|xfs_dir2_data_aoff_t
name|len
parameter_list|,
name|int
modifier|*
name|needlogp
parameter_list|,
name|int
modifier|*
name|needscanp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XFS_DIR2_DATA_H__ */
end_comment

end_unit

