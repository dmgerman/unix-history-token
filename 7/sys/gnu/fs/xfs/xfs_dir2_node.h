begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000,2005 Silicon Graphics, Inc.  * All Rights Reserved.  *  * This program is free software; you can redistribute it and/or  * modify it under the terms of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it would be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write the Free Software Foundation,  * Inc.,  51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XFS_DIR2_NODE_H__
end_ifndef

begin_define
define|#
directive|define
name|__XFS_DIR2_NODE_H__
end_define

begin_comment
comment|/*  * Directory version 2, btree node format structures  */
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
name|xfs_da_state
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_da_state_blk
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
comment|/*  * Offset of the freespace index.  */
end_comment

begin_define
define|#
directive|define
name|XFS_DIR2_FREE_SPACE
value|2
end_define

begin_define
define|#
directive|define
name|XFS_DIR2_FREE_OFFSET
value|(XFS_DIR2_FREE_SPACE * XFS_DIR2_SPACE_SIZE)
end_define

begin_define
define|#
directive|define
name|XFS_DIR2_FREE_FIRSTDB
parameter_list|(
name|mp
parameter_list|)
define|\
value|XFS_DIR2_BYTE_TO_DB(mp, XFS_DIR2_FREE_OFFSET)
end_define

begin_define
define|#
directive|define
name|XFS_DIR2_FREE_MAGIC
value|0x58443246
end_define

begin_comment
comment|/* XD2F */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xfs_dir2_free_hdr
block|{
name|__be32
name|magic
decl_stmt|;
comment|/* XFS_DIR2_FREE_MAGIC */
name|__be32
name|firstdb
decl_stmt|;
comment|/* db of first entry */
name|__be32
name|nvalid
decl_stmt|;
comment|/* count of valid entries */
name|__be32
name|nused
decl_stmt|;
comment|/* count of used entries */
block|}
name|xfs_dir2_free_hdr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|xfs_dir2_free
block|{
name|xfs_dir2_free_hdr_t
name|hdr
decl_stmt|;
comment|/* block header */
name|__be16
name|bests
index|[
literal|1
index|]
decl_stmt|;
comment|/* best free counts */
comment|/* unused entries are -1 */
block|}
name|xfs_dir2_free_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|XFS_DIR2_MAX_FREE_BESTS
parameter_list|(
name|mp
parameter_list|)
define|\
value|(((mp)->m_dirblksize - (uint)sizeof(xfs_dir2_free_hdr_t)) / \ 	 (uint)sizeof(xfs_dir2_data_off_t))
end_define

begin_comment
comment|/*  * Convert data space db to the corresponding free db.  */
end_comment

begin_define
define|#
directive|define
name|XFS_DIR2_DB_TO_FDB
parameter_list|(
name|mp
parameter_list|,
name|db
parameter_list|)
value|xfs_dir2_db_to_fdb(mp, db)
end_define

begin_function
specifier|static
specifier|inline
name|xfs_dir2_db_t
name|xfs_dir2_db_to_fdb
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
operator|(
name|XFS_DIR2_FREE_FIRSTDB
argument_list|(
name|mp
argument_list|)
operator|+
operator|(
name|db
operator|)
operator|/
name|XFS_DIR2_MAX_FREE_BESTS
argument_list|(
name|mp
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Convert data space db to the corresponding index in a free db.  */
end_comment

begin_define
define|#
directive|define
name|XFS_DIR2_DB_TO_FDINDEX
parameter_list|(
name|mp
parameter_list|,
name|db
parameter_list|)
value|xfs_dir2_db_to_fdindex(mp, db)
end_define

begin_function
specifier|static
specifier|inline
name|int
name|xfs_dir2_db_to_fdindex
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
operator|(
operator|(
name|db
operator|)
operator|%
name|XFS_DIR2_MAX_FREE_BESTS
argument_list|(
name|mp
argument_list|)
operator|)
return|;
block|}
end_function

begin_function_decl
specifier|extern
name|void
name|xfs_dir2_free_log_bests
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
name|int
name|xfs_dir2_leaf_to_node
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
name|xfs_dahash_t
name|xfs_dir2_leafn_lasthash
parameter_list|(
name|struct
name|xfs_dabuf
modifier|*
name|bp
parameter_list|,
name|int
modifier|*
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|xfs_dir2_leafn_lookup_int
parameter_list|(
name|struct
name|xfs_dabuf
modifier|*
name|bp
parameter_list|,
name|struct
name|xfs_da_args
modifier|*
name|args
parameter_list|,
name|int
modifier|*
name|indexp
parameter_list|,
name|struct
name|xfs_da_state
modifier|*
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|xfs_dir2_leafn_order
parameter_list|(
name|struct
name|xfs_dabuf
modifier|*
name|leaf1_bp
parameter_list|,
name|struct
name|xfs_dabuf
modifier|*
name|leaf2_bp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|xfs_dir2_leafn_split
parameter_list|(
name|struct
name|xfs_da_state
modifier|*
name|state
parameter_list|,
name|struct
name|xfs_da_state_blk
modifier|*
name|oldblk
parameter_list|,
name|struct
name|xfs_da_state_blk
modifier|*
name|newblk
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|xfs_dir2_leafn_toosmall
parameter_list|(
name|struct
name|xfs_da_state
modifier|*
name|state
parameter_list|,
name|int
modifier|*
name|action
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|xfs_dir2_leafn_unbalance
parameter_list|(
name|struct
name|xfs_da_state
modifier|*
name|state
parameter_list|,
name|struct
name|xfs_da_state_blk
modifier|*
name|drop_blk
parameter_list|,
name|struct
name|xfs_da_state_blk
modifier|*
name|save_blk
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|xfs_dir2_node_addname
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
name|xfs_dir2_node_lookup
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
name|xfs_dir2_node_removename
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
name|xfs_dir2_node_replace
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
name|xfs_dir2_node_trim_free
parameter_list|(
name|struct
name|xfs_da_args
modifier|*
name|args
parameter_list|,
name|xfs_fileoff_t
name|fo
parameter_list|,
name|int
modifier|*
name|rvalp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XFS_DIR2_NODE_H__ */
end_comment

end_unit

