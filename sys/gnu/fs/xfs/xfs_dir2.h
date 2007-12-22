begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2001,2005 Silicon Graphics, Inc.  * All Rights Reserved.  *  * This program is free software; you can redistribute it and/or  * modify it under the terms of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it would be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write the Free Software Foundation,  * Inc.,  51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XFS_DIR2_H__
end_ifndef

begin_define
define|#
directive|define
name|__XFS_DIR2_H__
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
name|xfs_dir2_put_args
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
comment|/*  * Directory version 2.  * There are 4 possible formats:  *	shortform  *	single block - data with embedded leaf at the end  *	multiple data blocks, single leaf+freeindex block  *	data blocks, node&leaf blocks (btree), freeindex blocks  *  *	The shortform format is in xfs_dir2_sf.h.  *	The single block format is in xfs_dir2_block.h.  *	The data block format is in xfs_dir2_data.h.  *	The leaf and freeindex block formats are in xfs_dir2_leaf.h.  *	Node blocks are the same as the other version, in xfs_da_btree.h.  */
end_comment

begin_comment
comment|/*  * Byte offset in data block and shortform entry.  */
end_comment

begin_typedef
typedef|typedef
name|__uint16_t
name|xfs_dir2_data_off_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NULLDATAOFF
value|0xffffU
end_define

begin_typedef
typedef|typedef
name|uint
name|xfs_dir2_data_aoff_t
typedef|;
end_typedef

begin_comment
comment|/* argument form */
end_comment

begin_comment
comment|/*  * Directory block number (logical dirblk in file)  */
end_comment

begin_typedef
typedef|typedef
name|__uint32_t
name|xfs_dir2_db_t
typedef|;
end_typedef

begin_comment
comment|/*  * Byte offset in a directory.  */
end_comment

begin_typedef
typedef|typedef
name|xfs_off_t
name|xfs_dir2_off_t
typedef|;
end_typedef

begin_comment
comment|/*  * For getdents, argument struct for put routines.  */
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|xfs_dir2_put_t
function_decl|)
parameter_list|(
name|struct
name|xfs_dir2_put_args
modifier|*
name|pa
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|xfs_dir2_put_args
block|{
name|xfs_off_t
name|cook
decl_stmt|;
comment|/* cookie of (next) entry */
name|xfs_intino_t
name|ino
decl_stmt|;
comment|/* inode number */
name|xfs_dirent_t
modifier|*
name|dbp
decl_stmt|;
comment|/* buffer pointer */
name|char
modifier|*
name|name
decl_stmt|;
comment|/* directory entry name */
name|int
name|namelen
decl_stmt|;
comment|/* length of name */
name|int
name|done
decl_stmt|;
comment|/* output: set if value was stored */
name|xfs_dir2_put_t
name|put
decl_stmt|;
comment|/* put function ptr (i/o) */
name|struct
name|uio
modifier|*
name|uio
decl_stmt|;
comment|/* uio control structure */
block|}
name|xfs_dir2_put_args_t
typedef|;
end_typedef

begin_comment
comment|/*  * Other interfaces used by the rest of the dir v2 code.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|xfs_dir2_grow_inode
parameter_list|(
name|struct
name|xfs_da_args
modifier|*
name|args
parameter_list|,
name|int
name|space
parameter_list|,
name|xfs_dir2_db_t
modifier|*
name|dbp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|xfs_dir2_isblock
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
name|int
modifier|*
name|vp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|xfs_dir2_isleaf
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
name|int
modifier|*
name|vp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|xfs_dir2_shrink_inode
parameter_list|(
name|struct
name|xfs_da_args
modifier|*
name|args
parameter_list|,
name|xfs_dir2_db_t
name|db
parameter_list|,
name|struct
name|xfs_dabuf
modifier|*
name|bp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XFS_DIR2_H__ */
end_comment

end_unit

