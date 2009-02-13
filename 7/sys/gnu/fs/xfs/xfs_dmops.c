begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2003,2005 Silicon Graphics, Inc.  * All Rights Reserved.  *  * This program is free software; you can redistribute it and/or  * modify it under the terms of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it would be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write the Free Software Foundation,  * Inc.,  51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA  */
end_comment

begin_include
include|#
directive|include
file|"xfs.h"
end_include

begin_include
include|#
directive|include
file|"xfs_fs.h"
end_include

begin_include
include|#
directive|include
file|"xfs_types.h"
end_include

begin_include
include|#
directive|include
file|"xfs_log.h"
end_include

begin_include
include|#
directive|include
file|"xfs_inum.h"
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

