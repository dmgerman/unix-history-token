begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2003 Silicon Graphics, Inc.  All Rights Reserved.  *  * This program is free software; you can redistribute it and/or modify it  * under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it would be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  *  * Further, this software is distributed without any warranty that it is  * free of the rightful claim of any third person regarding infringement  * or the like.	 Any license provided herein, whether implied or  * otherwise, applies only to this software file.  Patent licenses, if  * any, provided herein do not apply to combinations of this program with  * other software, or any other product whatsoever.  *  * You should have received a copy of the GNU General Public License along  * with this program; if not, write the Free Software Foundation, Inc., 59  * Temple Place - Suite 330, Boston MA 02111-1307, USA.  *  * Contact information: Silicon Graphics, Inc., 1600 Amphitheatre Pkwy,  * Mountain View, CA  94043, or:  *  * http://www.sgi.com  *  * For further information regarding this notice, see:  *  * http://oss.sgi.com/projects/GenInfo/SGIGPLNoticeExplan/  */
end_comment

begin_include
include|#
directive|include
file|"xfs.h"
end_include

begin_include
include|#
directive|include
file|"xfs_macros.h"
end_include

begin_include
include|#
directive|include
file|"xfs_types.h"
end_include

begin_include
include|#
directive|include
file|"xfs_inum.h"
end_include

begin_include
include|#
directive|include
file|"xfs_log.h"
end_include

begin_include
include|#
directive|include
file|"xfs_trans.h"
end_include

begin_include
include|#
directive|include
file|"xfs_sb.h"
end_include

begin_include
include|#
directive|include
file|"xfs_ag.h"
end_include

begin_include
include|#
directive|include
file|"xfs_dir.h"
end_include

begin_include
include|#
directive|include
file|"xfs_dir2.h"
end_include

begin_include
include|#
directive|include
file|"xfs_dmapi.h"
end_include

begin_include
include|#
directive|include
file|"xfs_mount.h"
end_include

begin_decl_stmt
name|xfs_dmops_t
name|xfs_dmcore_stub
init|=
block|{
operator|.
name|xfs_send_data
operator|=
operator|(
name|xfs_send_data_t
operator|)
name|fs_nosys
block|,
operator|.
name|xfs_send_mmap
operator|=
operator|(
name|xfs_send_mmap_t
operator|)
name|fs_noerr
block|,
operator|.
name|xfs_send_destroy
operator|=
operator|(
name|xfs_send_destroy_t
operator|)
name|fs_nosys
block|,
operator|.
name|xfs_send_namesp
operator|=
operator|(
name|xfs_send_namesp_t
operator|)
name|fs_nosys
block|,
operator|.
name|xfs_send_unmount
operator|=
operator|(
name|xfs_send_unmount_t
operator|)
name|fs_noval
block|, }
decl_stmt|;
end_decl_stmt

end_unit

