begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000 Silicon Graphics, Inc.  All Rights Reserved.  *  * This program is free software; you can redistribute it and/or modify it  * under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it would be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  *  * Further, this software is distributed without any warranty that it is  * free of the rightful claim of any third person regarding infringement  * or the like.  Any license provided herein, whether implied or  * otherwise, applies only to this software file.  Patent licenses, if  * any, provided herein do not apply to combinations of this program with  * other software, or any other product whatsoever.  *  * You should have received a copy of the GNU General Public License along  * with this program; if not, write the Free Software Foundation, Inc., 59  * Temple Place - Suite 330, Boston MA 02111-1307, USA.  *  * Contact information: Silicon Graphics, Inc., 1600 Amphitheatre Pkwy,  * Mountain View, CA  94043, or:  *  * http://www.sgi.com  *  * For further information regarding this notice, see:  *  * http://oss.sgi.com/projects/GenInfo/SGIGPLNoticeExplan/  */
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
comment|/*  * Constants.  */
end_comment

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

begin_comment
comment|/*  * Structures.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xfs_dir2_free_hdr
block|{
name|__uint32_t
name|magic
decl_stmt|;
comment|/* XFS_DIR2_FREE_MAGIC */
name|__int32_t
name|firstdb
decl_stmt|;
comment|/* db of first entry */
name|__int32_t
name|nvalid
decl_stmt|;
comment|/* count of valid entries */
name|__int32_t
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
name|xfs_dir2_data_off_t
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
comment|/*  * Macros.  */
end_comment

begin_comment
comment|/*  * Convert data space db to the corresponding free db.  */
end_comment

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
name|XFS_WANT_FUNCS_C
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_DIR2_DB_TO_FDB
operator|)
end_if

begin_function_decl
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
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_DIR2_DB_TO_FDB
operator|)
end_if

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

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_DIR2_DB_TO_FDB
parameter_list|(
name|mp
parameter_list|,
name|db
parameter_list|)
define|\
value|(XFS_DIR2_FREE_FIRSTDB(mp) + (db) / XFS_DIR2_MAX_FREE_BESTS(mp))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Convert data space db to the corresponding index in a free db.  */
end_comment

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
name|XFS_WANT_FUNCS_C
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_DIR2_DB_TO_FDINDEX
operator|)
end_if

begin_function_decl
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
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_WANT_FUNCS
operator|||
operator|(
name|XFS_WANT_SPACE
operator|&&
name|XFSSO_XFS_DIR2_DB_TO_FDINDEX
operator|)
end_if

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

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_DIR2_DB_TO_FDINDEX
parameter_list|(
name|mp
parameter_list|,
name|db
parameter_list|)
value|((db) % XFS_DIR2_MAX_FREE_BESTS(mp))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Functions.  */
end_comment

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

