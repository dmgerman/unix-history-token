begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000,2005 Silicon Graphics, Inc.  * All Rights Reserved.  *  * This program is free software; you can redistribute it and/or  * modify it under the terms of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it would be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write the Free Software Foundation,  * Inc.,  51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XFS_IMAP_H__
end_ifndef

begin_define
define|#
directive|define
name|__XFS_IMAP_H__
end_define

begin_comment
comment|/*  * This is the structure passed to xfs_imap() to map  * an inode number to its on disk location.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xfs_imap
block|{
name|xfs_daddr_t
name|im_blkno
decl_stmt|;
comment|/* starting BB of inode chunk */
name|uint
name|im_len
decl_stmt|;
comment|/* length in BBs of inode chunk */
name|xfs_agblock_t
name|im_agblkno
decl_stmt|;
comment|/* logical block of inode chunk in ag */
name|ushort
name|im_ioffset
decl_stmt|;
comment|/* inode offset in block in "inodes" */
name|ushort
name|im_boffset
decl_stmt|;
comment|/* inode offset in block in bytes */
block|}
name|xfs_imap_t
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|__KERNEL__
end_ifdef

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

begin_function_decl
name|int
name|xfs_imap
parameter_list|(
name|struct
name|xfs_mount
modifier|*
parameter_list|,
name|struct
name|xfs_trans
modifier|*
parameter_list|,
name|xfs_ino_t
parameter_list|,
name|xfs_imap_t
modifier|*
parameter_list|,
name|uint
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XFS_IMAP_H__ */
end_comment

end_unit

