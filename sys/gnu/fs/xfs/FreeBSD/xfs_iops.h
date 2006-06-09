begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2002 Silicon Graphics, Inc.  All Rights Reserved.  *  * This program is free software; you can redistribute it and/or modify it  * under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it would be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  *  * Further, this software is distributed without any warranty that it is  * free of the rightful claim of any third person regarding infringement  * or the like.  Any license provided herein, whether implied or  * otherwise, applies only to this software file.  Patent licenses, if  * any, provided herein do not apply to combinations of this program with  * other software, or any other product whatsoever.  *  * You should have received a copy of the GNU General Public License along  * with this program; if not, write the Free Software Foundation, Inc., 59  * Temple Place - Suite 330, Boston MA 02111-1307, USA.  *  * Contact information: Silicon Graphics, Inc., 1600 Amphitheatre Pkwy,  * Mountain View, CA  94043, or:  *  * http://www.sgi.com  *  * For further information regarding this notice, see:  *  * http://oss.sgi.com/projects/GenInfo/SGIGPLNoticeExplan/  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XFS_IOPS_H__
end_ifndef

begin_define
define|#
directive|define
name|__XFS_IOPS_H__
end_define

begin_comment
comment|/*  * Extended system attributes.  * So far only POSIX ACLs are supported, but this will need to  * grow in time (capabilities, mandatory access control, etc).  */
end_comment

begin_define
define|#
directive|define
name|XFS_SYSTEM_NAMESPACE
value|SYSTEM_POSIXACL
end_define

begin_comment
comment|/*  * Define a table of the namespaces XFS supports  */
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|xattr_exists_t
function_decl|)
parameter_list|(
name|xfs_vnode_t
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|xattr_namespace
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|unsigned
name|int
name|namelen
decl_stmt|;
name|xattr_exists_t
name|exists
decl_stmt|;
block|}
name|xattr_namespace_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SYSTEM_NAMES
value|0
end_define

begin_define
define|#
directive|define
name|ROOT_NAMES
value|1
end_define

begin_define
define|#
directive|define
name|USER_NAMES
value|2
end_define

begin_decl_stmt
specifier|extern
name|struct
name|xattr_namespace
modifier|*
name|xfs_namespaces
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|xfs_ioctl
parameter_list|(
name|struct
name|bhv_desc
modifier|*
parameter_list|,
name|struct
name|inode
modifier|*
parameter_list|,
name|struct
name|file
modifier|*
parameter_list|,
name|int
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XFS_IOPS_H__ */
end_comment

end_unit

