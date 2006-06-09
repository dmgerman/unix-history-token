begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2001,2005 Silicon Graphics, Inc.  * All Rights Reserved.  *  * This program is free software; you can redistribute it and/or  * modify it under the terms of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it would be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write the Free Software Foundation,  * Inc.,  51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XFS_DIR2_BLOCK_H__
end_ifndef

begin_define
define|#
directive|define
name|__XFS_DIR2_BLOCK_H__
end_define

begin_comment
comment|/*  * xfs_dir2_block.h  * Directory version 2, single block format structures  */
end_comment

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
name|xfs_dir2_data_hdr
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_dir2_leaf_entry
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
comment|/*  * The single block format is as follows:  * xfs_dir2_data_hdr_t structure  * xfs_dir2_data_entry_t and xfs_dir2_data_unused_t structures  * xfs_dir2_leaf_entry_t structures  * xfs_dir2_block_tail_t structure  */
end_comment

begin_define
define|#
directive|define
name|XFS_DIR2_BLOCK_MAGIC
value|0x58443242
end_define

begin_comment
comment|/* XD2B: for one block dirs */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xfs_dir2_block_tail
block|{
name|__be32
name|count
decl_stmt|;
comment|/* count of leaf entries */
name|__be32
name|stale
decl_stmt|;
comment|/* count of stale lf entries */
block|}
name|xfs_dir2_block_tail_t
typedef|;
end_typedef

begin_comment
comment|/*  * Generic single-block structure, for xfs_db.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xfs_dir2_block
block|{
name|xfs_dir2_data_hdr_t
name|hdr
decl_stmt|;
comment|/* magic XFS_DIR2_BLOCK_MAGIC */
name|xfs_dir2_data_union_t
name|u
index|[
literal|1
index|]
decl_stmt|;
name|xfs_dir2_leaf_entry_t
name|leaf
index|[
literal|1
index|]
decl_stmt|;
name|xfs_dir2_block_tail_t
name|tail
decl_stmt|;
block|}
name|xfs_dir2_block_t
typedef|;
end_typedef

begin_comment
comment|/*  * Pointer to the leaf header embedded in a data block (1-block format)  */
end_comment

begin_define
define|#
directive|define
name|XFS_DIR2_BLOCK_TAIL_P
parameter_list|(
name|mp
parameter_list|,
name|block
parameter_list|)
value|xfs_dir2_block_tail_p(mp,block)
end_define

begin_function
specifier|static
specifier|inline
name|xfs_dir2_block_tail_t
modifier|*
name|xfs_dir2_block_tail_p
parameter_list|(
name|struct
name|xfs_mount
modifier|*
name|mp
parameter_list|,
name|xfs_dir2_block_t
modifier|*
name|block
parameter_list|)
block|{
return|return
operator|(
operator|(
operator|(
name|xfs_dir2_block_tail_t
operator|*
operator|)
operator|(
operator|(
name|char
operator|*
operator|)
operator|(
name|block
operator|)
operator|+
operator|(
name|mp
operator|)
operator|->
name|m_dirblksize
operator|)
operator|)
operator|-
literal|1
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Pointer to the leaf entries embedded in a data block (1-block format)  */
end_comment

begin_define
define|#
directive|define
name|XFS_DIR2_BLOCK_LEAF_P
parameter_list|(
name|btp
parameter_list|)
value|xfs_dir2_block_leaf_p(btp)
end_define

begin_function
specifier|static
specifier|inline
name|struct
name|xfs_dir2_leaf_entry
modifier|*
name|xfs_dir2_block_leaf_p
parameter_list|(
name|xfs_dir2_block_tail_t
modifier|*
name|btp
parameter_list|)
block|{
return|return
operator|(
operator|(
expr|struct
name|xfs_dir2_leaf_entry
operator|*
operator|)
name|btp
operator|)
operator|-
name|be32_to_cpu
argument_list|(
name|btp
operator|->
name|count
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
name|xfs_dir2_block_addname
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
name|xfs_dir2_block_getdents
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
name|xfs_dir2_block_lookup
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
name|xfs_dir2_block_removename
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
name|xfs_dir2_block_replace
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
name|xfs_dir2_leaf_to_block
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
name|xfs_dir2_sf_to_block
parameter_list|(
name|struct
name|xfs_da_args
modifier|*
name|args
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XFS_DIR2_BLOCK_H__ */
end_comment

end_unit

