begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2001 Silicon Graphics, Inc.  All Rights Reserved.  *  * This program is free software; you can redistribute it and/or modify it  * under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it would be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  *  * Further, this software is distributed without any warranty that it is  * free of the rightful claim of any third person regarding infringement  * or the like.  Any license provided herein, whether implied or  * otherwise, applies only to this software file.  Patent licenses, if  * any, provided herein do not apply to combinations of this program with  * other software, or any other product whatsoever.  *  * You should have received a copy of the GNU General Public License along  * with this program; if not, write the Free Software Foundation, Inc., 59  * Temple Place - Suite 330, Boston MA 02111-1307, USA.  *  * Contact information: Silicon Graphics, Inc., 1600 Amphitheatre Pkwy,  * Mountain View, CA  94043, or:  *  * http://www.sgi.com  *  * For further information regarding this notice, see:  *  * http://oss.sgi.com/projects/GenInfo/SGIGPLNoticeExplan/  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XFS_ITABLE_H__
end_ifndef

begin_define
define|#
directive|define
name|__XFS_ITABLE_H__
end_define

begin_comment
comment|/*  * xfs_bulkstat() is used to fill in xfs_bstat structures as well as dm_stat  * structures (by the dmi library). This is a pointer to a formatter function  * that will iget the inode and fill in the appropriate structure.  * see xfs_bulkstat_one() and xfs_dm_bulkstat_one() in dmapi_xfs.c  */
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|bulkstat_one_pf
function_decl|)
parameter_list|(
name|struct
name|xfs_mount
modifier|*
name|mp
parameter_list|,
name|struct
name|xfs_trans
modifier|*
name|tp
parameter_list|,
name|xfs_ino_t
name|ino
parameter_list|,
name|void
modifier|*
name|buffer
parameter_list|,
name|int
name|ubsize
parameter_list|,
name|void
modifier|*
name|private_data
parameter_list|,
name|xfs_daddr_t
name|bno
parameter_list|,
name|int
modifier|*
name|ubused
parameter_list|,
name|void
modifier|*
name|dip
parameter_list|,
name|int
modifier|*
name|stat
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * Values for stat return value.  */
end_comment

begin_define
define|#
directive|define
name|BULKSTAT_RV_NOTHING
value|0
end_define

begin_define
define|#
directive|define
name|BULKSTAT_RV_DIDONE
value|1
end_define

begin_define
define|#
directive|define
name|BULKSTAT_RV_GIVEUP
value|2
end_define

begin_comment
comment|/*  * Values for bulkstat flag argument.  */
end_comment

begin_define
define|#
directive|define
name|BULKSTAT_FG_IGET
value|0x1
end_define

begin_comment
comment|/* Go through the buffer cache */
end_comment

begin_define
define|#
directive|define
name|BULKSTAT_FG_QUICK
value|0x2
end_define

begin_comment
comment|/* No iget, walk the dinode cluster */
end_comment

begin_define
define|#
directive|define
name|BULKSTAT_FG_VFSLOCKED
value|0x4
end_define

begin_comment
comment|/* Already have vfs lock */
end_comment

begin_comment
comment|/*  * Return stat information in bulk (by-inode) for the filesystem.  */
end_comment

begin_function_decl
name|int
comment|/* error status */
name|xfs_bulkstat
parameter_list|(
name|xfs_mount_t
modifier|*
name|mp
parameter_list|,
comment|/* mount point for filesystem */
name|xfs_trans_t
modifier|*
name|tp
parameter_list|,
comment|/* transaction pointer */
name|xfs_ino_t
modifier|*
name|lastino
parameter_list|,
comment|/* last inode returned */
name|int
modifier|*
name|count
parameter_list|,
comment|/* size of buffer/count returned */
name|bulkstat_one_pf
name|formatter
parameter_list|,
comment|/* func that'd fill a single buf */
name|void
modifier|*
name|private_data
parameter_list|,
comment|/* private data for formatter */
name|size_t
name|statstruct_size
parameter_list|,
comment|/* sizeof struct that we're filling */
name|xfs_caddr_t
name|ubuffer
parameter_list|,
comment|/* buffer with inode stats */
name|int
name|flags
parameter_list|,
comment|/* flag to control access method */
name|int
modifier|*
name|done
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* 1 if there're more stats to get */
end_comment

begin_function_decl
name|int
name|xfs_bulkstat_single
parameter_list|(
name|xfs_mount_t
modifier|*
name|mp
parameter_list|,
name|xfs_ino_t
modifier|*
name|lastinop
parameter_list|,
name|xfs_caddr_t
name|buffer
parameter_list|,
name|int
modifier|*
name|done
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_bulkstat_one
parameter_list|(
name|xfs_mount_t
modifier|*
name|mp
parameter_list|,
name|xfs_trans_t
modifier|*
name|tp
parameter_list|,
name|xfs_ino_t
name|ino
parameter_list|,
name|void
modifier|*
name|buffer
parameter_list|,
name|int
name|ubsize
parameter_list|,
name|void
modifier|*
name|private_data
parameter_list|,
name|xfs_daddr_t
name|bno
parameter_list|,
name|int
modifier|*
name|ubused
parameter_list|,
name|void
modifier|*
name|dibuff
parameter_list|,
name|int
modifier|*
name|stat
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
comment|/* error status */
name|xfs_inumbers
parameter_list|(
name|xfs_mount_t
modifier|*
name|mp
parameter_list|,
comment|/* mount point for filesystem */
name|xfs_trans_t
modifier|*
name|tp
parameter_list|,
comment|/* transaction pointer */
name|xfs_ino_t
modifier|*
name|last
parameter_list|,
comment|/* last inode returned */
name|int
modifier|*
name|count
parameter_list|,
comment|/* size of buffer/count returned */
name|xfs_caddr_t
name|buffer
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* buffer with inode descriptions */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XFS_ITABLE_H__ */
end_comment

end_unit

