begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000,2005 Silicon Graphics, Inc.  * All Rights Reserved.  *  * This program is free software; you can redistribute it and/or  * modify it under the terms of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it would be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write the Free Software Foundation,  * Inc.,  51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XFS_DFRAG_H__
end_ifndef

begin_define
define|#
directive|define
name|__XFS_DFRAG_H__
end_define

begin_comment
comment|/*  * Structure passed to xfs_swapext  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xfs_swapext
block|{
name|__int64_t
name|sx_version
decl_stmt|;
comment|/* version */
name|__int64_t
name|sx_fdtarget
decl_stmt|;
comment|/* fd of target file */
name|__int64_t
name|sx_fdtmp
decl_stmt|;
comment|/* fd of tmp file */
name|xfs_off_t
name|sx_offset
decl_stmt|;
comment|/* offset into file */
name|xfs_off_t
name|sx_length
decl_stmt|;
comment|/* leng from offset */
name|char
name|sx_pad
index|[
literal|16
index|]
decl_stmt|;
comment|/* pad space, unused */
name|xfs_bstat_t
name|sx_stat
decl_stmt|;
comment|/* stat of target b4 copy */
block|}
name|xfs_swapext_t
typedef|;
end_typedef

begin_comment
comment|/*  * Version flag  */
end_comment

begin_define
define|#
directive|define
name|XFS_SX_VERSION
value|0
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__KERNEL__
end_ifdef

begin_comment
comment|/*  * Prototypes for visible xfs_dfrag.c routines.  */
end_comment

begin_comment
comment|/*  * Syscall interface for xfs_swapext  */
end_comment

begin_function_decl
name|int
name|xfs_swapext
parameter_list|(
name|struct
name|xfs_swapext
name|__user
modifier|*
name|sx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_swap_extents
parameter_list|(
name|struct
name|xfs_inode
modifier|*
name|ip
parameter_list|,
name|struct
name|xfs_inode
modifier|*
name|tip
parameter_list|,
name|struct
name|xfs_swapext
modifier|*
name|sxp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __KERNEL__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XFS_DFRAG_H__ */
end_comment

end_unit

