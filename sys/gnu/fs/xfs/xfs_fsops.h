begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2001 Silicon Graphics, Inc.  All Rights Reserved.  *  * This program is free software; you can redistribute it and/or modify it  * under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it would be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  *  * Further, this software is distributed without any warranty that it is  * free of the rightful claim of any third person regarding infringement  * or the like.  Any license provided herein, whether implied or  * otherwise, applies only to this software file.  Patent licenses, if  * any, provided herein do not apply to combinations of this program with  * other software, or any other product whatsoever.  *  * You should have received a copy of the GNU General Public License along  * with this program; if not, write the Free Software Foundation, Inc., 59  * Temple Place - Suite 330, Boston MA 02111-1307, USA.  *  * Contact information: Silicon Graphics, Inc., 1600 Amphitheatre Pkwy,  * Mountain View, CA  94043, or:  *  * http://www.sgi.com  *  * For further information regarding this notice, see:  *  * http://oss.sgi.com/projects/GenInfo/SGIGPLNoticeExplan/  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XFS_FSOPS_H__
end_ifndef

begin_define
define|#
directive|define
name|__XFS_FSOPS_H__
end_define

begin_function_decl
name|int
name|xfs_fs_geometry
parameter_list|(
name|xfs_mount_t
modifier|*
name|mp
parameter_list|,
name|xfs_fsop_geom_t
modifier|*
name|geo
parameter_list|,
name|int
name|new_version
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_growfs_data
parameter_list|(
name|xfs_mount_t
modifier|*
name|mp
parameter_list|,
name|xfs_growfs_data_t
modifier|*
name|in
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_growfs_log
parameter_list|(
name|xfs_mount_t
modifier|*
name|mp
parameter_list|,
name|xfs_growfs_log_t
modifier|*
name|in
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_fs_counts
parameter_list|(
name|xfs_mount_t
modifier|*
name|mp
parameter_list|,
name|xfs_fsop_counts_t
modifier|*
name|cnt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_reserve_blocks
parameter_list|(
name|xfs_mount_t
modifier|*
name|mp
parameter_list|,
name|__uint64_t
modifier|*
name|inval
parameter_list|,
name|xfs_fsop_resblks_t
modifier|*
name|outval
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_fs_freeze
parameter_list|(
name|xfs_mount_t
modifier|*
name|mp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_fs_thaw
parameter_list|(
name|xfs_mount_t
modifier|*
name|mp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_fs_goingdown
parameter_list|(
name|xfs_mount_t
modifier|*
name|mp
parameter_list|,
name|__uint32_t
name|inflags
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XFS_FSOPS_H__ */
end_comment

end_unit

