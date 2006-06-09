begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2001,2005 Silicon Graphics, Inc.  * All Rights Reserved.  *  * This program is free software; you can redistribute it and/or  * modify it under the terms of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it would be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write the Free Software Foundation,  * Inc.,  51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XFS_DIR2_LEAF_H__
end_ifndef

begin_define
define|#
directive|define
name|__XFS_DIR2_LEAF_H__
end_define

begin_struct_decl
struct_decl|struct
name|uio
struct_decl|;
end_struct_decl

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
name|xfs_mount
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_trans
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * Offset of the leaf/node space.  First block in this space  * is the btree root.  */
end_comment

begin_define
define|#
directive|define
name|XFS_DIR2_LEAF_SPACE
value|1
end_define

begin_define
define|#
directive|define
name|XFS_DIR2_LEAF_OFFSET
value|(XFS_DIR2_LEAF_SPACE * XFS_DIR2_SPACE_SIZE)
end_define

begin_define
define|#
directive|define
name|XFS_DIR2_LEAF_FIRSTDB
parameter_list|(
name|mp
parameter_list|)
define|\
value|XFS_DIR2_BYTE_TO_DB(mp, XFS_DIR2_LEAF_OFFSET)
end_define

begin_comment
comment|/*  * Offset in data space of a data entry.  */
end_comment

begin_typedef
typedef|typedef
name|__uint32_t
name|xfs_dir2_dataptr_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|XFS_DIR2_MAX_DATAPTR
value|((xfs_dir2_dataptr_t)0xffffffff)
end_define

begin_define
define|#
directive|define
name|XFS_DIR2_NULL_DATAPTR
value|((xfs_dir2_dataptr_t)0)
end_define

begin_comment
comment|/*  * Leaf block header.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xfs_dir2_leaf_hdr
block|{
name|xfs_da_blkinfo_t
name|info
decl_stmt|;
comment|/* header for da routines */
name|__be16
name|count
decl_stmt|;
comment|/* count of entries */
name|__be16
name|stale
decl_stmt|;
comment|/* count of stale entries */
block|}
name|xfs_dir2_leaf_hdr_t
typedef|;
end_typedef

begin_comment
comment|/*  * Leaf block entry.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xfs_dir2_leaf_entry
block|{
name|__be32
name|hashval
decl_stmt|;
comment|/* hash value of name */
name|__be32
name|address
decl_stmt|;
comment|/* address of data entry */
block|}
name|xfs_dir2_leaf_entry_t
typedef|;
end_typedef

begin_comment
comment|/*  * Leaf block tail.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xfs_dir2_leaf_tail
block|{
name|__be32
name|bestcount
decl_stmt|;
block|}
name|xfs_dir2_leaf_tail_t
typedef|;
end_typedef

begin_comment
comment|/*  * Leaf block.  * bests and tail are at the end of the block for single-leaf only  * (magic = XFS_DIR2_LEAF1_MAGIC not XFS_DIR2_LEAFN_MAGIC).  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xfs_dir2_leaf
block|{
name|xfs_dir2_leaf_hdr_t
name|hdr
decl_stmt|;
comment|/* leaf header */
name|xfs_dir2_leaf_entry_t
name|ents
index|[
literal|1
index|]
decl_stmt|;
comment|/* entries */
comment|/* ... */
name|xfs_dir2_data_off_t
name|bests
index|[
literal|1
index|]
decl_stmt|;
comment|/* best free counts */
name|xfs_dir2_leaf_tail_t
name|tail
decl_stmt|;
comment|/* leaf tail */
block|}
name|xfs_dir2_leaf_t
typedef|;
end_typedef

begin_comment
comment|/*  * DB blocks here are logical directory block numbers, not filesystem blocks.  */
end_comment

begin_define
define|#
directive|define
name|XFS_DIR2_MAX_LEAF_ENTS
parameter_list|(
name|mp
parameter_list|)
value|xfs_dir2_max_leaf_ents(mp)
end_define

begin_function
specifier|static
specifier|inline
name|int
name|xfs_dir2_max_leaf_ents
parameter_list|(
name|struct
name|xfs_mount
modifier|*
name|mp
parameter_list|)
block|{
return|return
call|(
name|int
call|)
argument_list|(
operator|(
operator|(
name|mp
operator|)
operator|->
name|m_dirblksize
operator|-
operator|(
name|uint
operator|)
sizeof|sizeof
argument_list|(
name|xfs_dir2_leaf_hdr_t
argument_list|)
operator|)
operator|/
operator|(
name|uint
operator|)
sizeof|sizeof
argument_list|(
name|xfs_dir2_leaf_entry_t
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/*  * Get address of the bestcount field in the single-leaf block.  */
end_comment

begin_define
define|#
directive|define
name|XFS_DIR2_LEAF_TAIL_P
parameter_list|(
name|mp
parameter_list|,
name|lp
parameter_list|)
value|xfs_dir2_leaf_tail_p(mp, lp)
end_define

begin_function
specifier|static
specifier|inline
name|xfs_dir2_leaf_tail_t
modifier|*
name|xfs_dir2_leaf_tail_p
parameter_list|(
name|struct
name|xfs_mount
modifier|*
name|mp
parameter_list|,
name|xfs_dir2_leaf_t
modifier|*
name|lp
parameter_list|)
block|{
return|return
operator|(
name|xfs_dir2_leaf_tail_t
operator|*
operator|)
operator|(
operator|(
name|char
operator|*
operator|)
operator|(
name|lp
operator|)
operator|+
operator|(
name|mp
operator|)
operator|->
name|m_dirblksize
operator|-
operator|(
name|uint
operator|)
sizeof|sizeof
argument_list|(
name|xfs_dir2_leaf_tail_t
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Get address of the bests array in the single-leaf block.  */
end_comment

begin_define
define|#
directive|define
name|XFS_DIR2_LEAF_BESTS_P
parameter_list|(
name|ltp
parameter_list|)
value|xfs_dir2_leaf_bests_p(ltp)
end_define

begin_function
specifier|static
specifier|inline
name|__be16
modifier|*
name|xfs_dir2_leaf_bests_p
parameter_list|(
name|xfs_dir2_leaf_tail_t
modifier|*
name|ltp
parameter_list|)
block|{
return|return
operator|(
name|__be16
operator|*
operator|)
name|ltp
operator|-
name|be32_to_cpu
argument_list|(
name|ltp
operator|->
name|bestcount
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/*  * Convert dataptr to byte in file space  */
end_comment

begin_define
define|#
directive|define
name|XFS_DIR2_DATAPTR_TO_BYTE
parameter_list|(
name|mp
parameter_list|,
name|dp
parameter_list|)
value|xfs_dir2_dataptr_to_byte(mp, dp)
end_define

begin_function
specifier|static
specifier|inline
name|xfs_dir2_off_t
name|xfs_dir2_dataptr_to_byte
parameter_list|(
name|struct
name|xfs_mount
modifier|*
name|mp
parameter_list|,
name|xfs_dir2_dataptr_t
name|dp
parameter_list|)
block|{
return|return
call|(
name|xfs_dir2_off_t
call|)
argument_list|(
name|dp
argument_list|)
operator|<<
name|XFS_DIR2_DATA_ALIGN_LOG
return|;
block|}
end_function

begin_comment
comment|/*  * Convert byte in file space to dataptr.  It had better be aligned.  */
end_comment

begin_define
define|#
directive|define
name|XFS_DIR2_BYTE_TO_DATAPTR
parameter_list|(
name|mp
parameter_list|,
name|by
parameter_list|)
value|xfs_dir2_byte_to_dataptr(mp,by)
end_define

begin_function
specifier|static
specifier|inline
name|xfs_dir2_dataptr_t
name|xfs_dir2_byte_to_dataptr
parameter_list|(
name|struct
name|xfs_mount
modifier|*
name|mp
parameter_list|,
name|xfs_dir2_off_t
name|by
parameter_list|)
block|{
return|return
call|(
name|xfs_dir2_dataptr_t
call|)
argument_list|(
operator|(
name|by
operator|)
operator|>>
name|XFS_DIR2_DATA_ALIGN_LOG
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/*  * Convert byte in space to (DB) block  */
end_comment

begin_define
define|#
directive|define
name|XFS_DIR2_BYTE_TO_DB
parameter_list|(
name|mp
parameter_list|,
name|by
parameter_list|)
value|xfs_dir2_byte_to_db(mp, by)
end_define

begin_function
specifier|static
specifier|inline
name|xfs_dir2_db_t
name|xfs_dir2_byte_to_db
parameter_list|(
name|struct
name|xfs_mount
modifier|*
name|mp
parameter_list|,
name|xfs_dir2_off_t
name|by
parameter_list|)
block|{
return|return
call|(
name|xfs_dir2_db_t
call|)
argument_list|(
operator|(
name|by
operator|)
operator|>>
expr|\
operator|(
operator|(
name|mp
operator|)
operator|->
name|m_sb
operator|.
name|sb_blocklog
operator|+
operator|(
name|mp
operator|)
operator|->
name|m_sb
operator|.
name|sb_dirblklog
operator|)
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/*  * Convert dataptr to a block number  */
end_comment

begin_define
define|#
directive|define
name|XFS_DIR2_DATAPTR_TO_DB
parameter_list|(
name|mp
parameter_list|,
name|dp
parameter_list|)
value|xfs_dir2_dataptr_to_db(mp, dp)
end_define

begin_function
specifier|static
specifier|inline
name|xfs_dir2_db_t
name|xfs_dir2_dataptr_to_db
parameter_list|(
name|struct
name|xfs_mount
modifier|*
name|mp
parameter_list|,
name|xfs_dir2_dataptr_t
name|dp
parameter_list|)
block|{
return|return
name|XFS_DIR2_BYTE_TO_DB
argument_list|(
name|mp
argument_list|,
name|XFS_DIR2_DATAPTR_TO_BYTE
argument_list|(
name|mp
argument_list|,
name|dp
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/*  * Convert byte in space to offset in a block  */
end_comment

begin_define
define|#
directive|define
name|XFS_DIR2_BYTE_TO_OFF
parameter_list|(
name|mp
parameter_list|,
name|by
parameter_list|)
value|xfs_dir2_byte_to_off(mp, by)
end_define

begin_function
specifier|static
specifier|inline
name|xfs_dir2_data_aoff_t
name|xfs_dir2_byte_to_off
parameter_list|(
name|struct
name|xfs_mount
modifier|*
name|mp
parameter_list|,
name|xfs_dir2_off_t
name|by
parameter_list|)
block|{
return|return
call|(
name|xfs_dir2_data_aoff_t
call|)
argument_list|(
operator|(
name|by
operator|)
operator|&
expr|\
operator|(
operator|(
literal|1
operator|<<
operator|(
operator|(
name|mp
operator|)
operator|->
name|m_sb
operator|.
name|sb_blocklog
operator|+
operator|(
name|mp
operator|)
operator|->
name|m_sb
operator|.
name|sb_dirblklog
operator|)
operator|)
operator|-
literal|1
operator|)
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/*  * Convert dataptr to a byte offset in a block  */
end_comment

begin_define
define|#
directive|define
name|XFS_DIR2_DATAPTR_TO_OFF
parameter_list|(
name|mp
parameter_list|,
name|dp
parameter_list|)
value|xfs_dir2_dataptr_to_off(mp, dp)
end_define

begin_function
specifier|static
specifier|inline
name|xfs_dir2_data_aoff_t
name|xfs_dir2_dataptr_to_off
parameter_list|(
name|struct
name|xfs_mount
modifier|*
name|mp
parameter_list|,
name|xfs_dir2_dataptr_t
name|dp
parameter_list|)
block|{
return|return
name|XFS_DIR2_BYTE_TO_OFF
argument_list|(
name|mp
argument_list|,
name|XFS_DIR2_DATAPTR_TO_BYTE
argument_list|(
name|mp
argument_list|,
name|dp
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/*  * Convert block and offset to byte in space  */
end_comment

begin_define
define|#
directive|define
name|XFS_DIR2_DB_OFF_TO_BYTE
parameter_list|(
name|mp
parameter_list|,
name|db
parameter_list|,
name|o
parameter_list|)
define|\
value|xfs_dir2_db_off_to_byte(mp, db, o)
end_define

begin_function
specifier|static
specifier|inline
name|xfs_dir2_off_t
name|xfs_dir2_db_off_to_byte
parameter_list|(
name|struct
name|xfs_mount
modifier|*
name|mp
parameter_list|,
name|xfs_dir2_db_t
name|db
parameter_list|,
name|xfs_dir2_data_aoff_t
name|o
parameter_list|)
block|{
return|return
operator|(
call|(
name|xfs_dir2_off_t
call|)
argument_list|(
name|db
argument_list|)
operator|<<
expr|\
operator|(
operator|(
name|mp
operator|)
operator|->
name|m_sb
operator|.
name|sb_blocklog
operator|+
operator|(
name|mp
operator|)
operator|->
name|m_sb
operator|.
name|sb_dirblklog
operator|)
operator|)
operator|+
operator|(
name|o
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Convert block (DB) to block (dablk)  */
end_comment

begin_define
define|#
directive|define
name|XFS_DIR2_DB_TO_DA
parameter_list|(
name|mp
parameter_list|,
name|db
parameter_list|)
value|xfs_dir2_db_to_da(mp, db)
end_define

begin_function
specifier|static
specifier|inline
name|xfs_dablk_t
name|xfs_dir2_db_to_da
parameter_list|(
name|struct
name|xfs_mount
modifier|*
name|mp
parameter_list|,
name|xfs_dir2_db_t
name|db
parameter_list|)
block|{
return|return
call|(
name|xfs_dablk_t
call|)
argument_list|(
operator|(
name|db
operator|)
operator|<<
operator|(
name|mp
operator|)
operator|->
name|m_sb
operator|.
name|sb_dirblklog
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/*  * Convert byte in space to (DA) block  */
end_comment

begin_define
define|#
directive|define
name|XFS_DIR2_BYTE_TO_DA
parameter_list|(
name|mp
parameter_list|,
name|by
parameter_list|)
value|xfs_dir2_byte_to_da(mp, by)
end_define

begin_function
specifier|static
specifier|inline
name|xfs_dablk_t
name|xfs_dir2_byte_to_da
parameter_list|(
name|struct
name|xfs_mount
modifier|*
name|mp
parameter_list|,
name|xfs_dir2_off_t
name|by
parameter_list|)
block|{
return|return
name|XFS_DIR2_DB_TO_DA
argument_list|(
name|mp
argument_list|,
name|XFS_DIR2_BYTE_TO_DB
argument_list|(
name|mp
argument_list|,
name|by
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/*  * Convert block and offset to dataptr  */
end_comment

begin_define
define|#
directive|define
name|XFS_DIR2_DB_OFF_TO_DATAPTR
parameter_list|(
name|mp
parameter_list|,
name|db
parameter_list|,
name|o
parameter_list|)
define|\
value|xfs_dir2_db_off_to_dataptr(mp, db, o)
end_define

begin_function
specifier|static
specifier|inline
name|xfs_dir2_dataptr_t
name|xfs_dir2_db_off_to_dataptr
parameter_list|(
name|struct
name|xfs_mount
modifier|*
name|mp
parameter_list|,
name|xfs_dir2_db_t
name|db
parameter_list|,
name|xfs_dir2_data_aoff_t
name|o
parameter_list|)
block|{
return|return
name|XFS_DIR2_BYTE_TO_DATAPTR
argument_list|(
name|mp
argument_list|,
name|XFS_DIR2_DB_OFF_TO_BYTE
argument_list|(
name|mp
argument_list|,
name|db
argument_list|,
name|o
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/*  * Convert block (dablk) to block (DB)  */
end_comment

begin_define
define|#
directive|define
name|XFS_DIR2_DA_TO_DB
parameter_list|(
name|mp
parameter_list|,
name|da
parameter_list|)
value|xfs_dir2_da_to_db(mp, da)
end_define

begin_function
specifier|static
specifier|inline
name|xfs_dir2_db_t
name|xfs_dir2_da_to_db
parameter_list|(
name|struct
name|xfs_mount
modifier|*
name|mp
parameter_list|,
name|xfs_dablk_t
name|da
parameter_list|)
block|{
return|return
call|(
name|xfs_dir2_db_t
call|)
argument_list|(
operator|(
name|da
operator|)
operator|>>
operator|(
name|mp
operator|)
operator|->
name|m_sb
operator|.
name|sb_dirblklog
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/*  * Convert block (dablk) to byte offset in space  */
end_comment

begin_define
define|#
directive|define
name|XFS_DIR2_DA_TO_BYTE
parameter_list|(
name|mp
parameter_list|,
name|da
parameter_list|)
value|xfs_dir2_da_to_byte(mp, da)
end_define

begin_function
specifier|static
specifier|inline
name|xfs_dir2_off_t
name|xfs_dir2_da_to_byte
parameter_list|(
name|struct
name|xfs_mount
modifier|*
name|mp
parameter_list|,
name|xfs_dablk_t
name|da
parameter_list|)
block|{
return|return
name|XFS_DIR2_DB_OFF_TO_BYTE
argument_list|(
name|mp
argument_list|,
name|XFS_DIR2_DA_TO_DB
argument_list|(
name|mp
argument_list|,
name|da
argument_list|)
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/*  * Function declarations.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|xfs_dir2_block_to_leaf
parameter_list|(
name|struct
name|xfs_da_args
modifier|*
name|args
parameter_list|,
name|struct
name|xfs_dabuf
modifier|*
name|dbp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|xfs_dir2_leaf_addname
parameter_list|(
name|struct
name|xfs_da_args
modifier|*
name|args
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|xfs_dir2_leaf_compact
parameter_list|(
name|struct
name|xfs_da_args
modifier|*
name|args
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
name|xfs_dir2_leaf_compact_x1
parameter_list|(
name|struct
name|xfs_dabuf
modifier|*
name|bp
parameter_list|,
name|int
modifier|*
name|indexp
parameter_list|,
name|int
modifier|*
name|lowstalep
parameter_list|,
name|int
modifier|*
name|highstalep
parameter_list|,
name|int
modifier|*
name|lowlogp
parameter_list|,
name|int
modifier|*
name|highlogp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|xfs_dir2_leaf_getdents
parameter_list|(
name|struct
name|xfs_trans
modifier|*
name|tp
parameter_list|,
name|struct
name|xfs_inode
modifier|*
name|dp
parameter_list|,
name|struct
name|uio
modifier|*
name|uio
parameter_list|,
name|int
modifier|*
name|eofp
parameter_list|,
name|struct
name|xfs_dirent
modifier|*
name|dbp
parameter_list|,
name|xfs_dir2_put_t
name|put
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|xfs_dir2_leaf_init
parameter_list|(
name|struct
name|xfs_da_args
modifier|*
name|args
parameter_list|,
name|xfs_dir2_db_t
name|bno
parameter_list|,
name|struct
name|xfs_dabuf
modifier|*
modifier|*
name|bpp
parameter_list|,
name|int
name|magic
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|xfs_dir2_leaf_log_ents
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
name|int
name|first
parameter_list|,
name|int
name|last
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|xfs_dir2_leaf_log_header
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
name|int
name|xfs_dir2_leaf_lookup
parameter_list|(
name|struct
name|xfs_da_args
modifier|*
name|args
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|xfs_dir2_leaf_removename
parameter_list|(
name|struct
name|xfs_da_args
modifier|*
name|args
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|xfs_dir2_leaf_replace
parameter_list|(
name|struct
name|xfs_da_args
modifier|*
name|args
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|xfs_dir2_leaf_search_hash
parameter_list|(
name|struct
name|xfs_da_args
modifier|*
name|args
parameter_list|,
name|struct
name|xfs_dabuf
modifier|*
name|lbp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|xfs_dir2_leaf_trim_data
parameter_list|(
name|struct
name|xfs_da_args
modifier|*
name|args
parameter_list|,
name|struct
name|xfs_dabuf
modifier|*
name|lbp
parameter_list|,
name|xfs_dir2_db_t
name|db
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|xfs_dir2_node_to_leaf
parameter_list|(
name|struct
name|xfs_da_state
modifier|*
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XFS_DIR2_LEAF_H__ */
end_comment

end_unit

