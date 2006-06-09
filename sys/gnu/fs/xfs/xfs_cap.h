begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2002,2005 Silicon Graphics, Inc.  * All Rights Reserved.  *  * This program is free software; you can redistribute it and/or  * modify it under the terms of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it would be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write the Free Software Foundation,  * Inc.,  51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XFS_CAP_H__
end_ifndef

begin_define
define|#
directive|define
name|__XFS_CAP_H__
end_define

begin_comment
comment|/*  * Capabilities  */
end_comment

begin_typedef
typedef|typedef
name|__uint64_t
name|xfs_cap_value_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|xfs_cap_set
block|{
name|xfs_cap_value_t
name|cap_effective
decl_stmt|;
comment|/* use in capability checks */
name|xfs_cap_value_t
name|cap_permitted
decl_stmt|;
comment|/* combined with file attrs */
name|xfs_cap_value_t
name|cap_inheritable
decl_stmt|;
comment|/* pass through exec */
block|}
name|xfs_cap_set_t
typedef|;
end_typedef

begin_comment
comment|/* On-disk XFS extended attribute names */
end_comment

begin_define
define|#
directive|define
name|SGI_CAP_FILE
value|"SGI_CAP_FILE"
end_define

begin_define
define|#
directive|define
name|SGI_CAP_FILE_SIZE
value|(sizeof(SGI_CAP_FILE)-1)
end_define

begin_define
define|#
directive|define
name|SGI_CAP_LINUX
value|"SGI_CAP_LINUX"
end_define

begin_define
define|#
directive|define
name|SGI_CAP_LINUX_SIZE
value|(sizeof(SGI_CAP_LINUX)-1)
end_define

begin_comment
comment|/*  * For Linux, we take the bitfields directly from capability.h  * and no longer attempt to keep this attribute ondisk compatible  * with IRIX.  Since this attribute is only set on executables,  * it just doesn't make much sense to try.  We do use a different  * named attribute though, to avoid confusion.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__KERNEL__
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_FS_POSIX_CAP
end_ifdef

begin_include
include|#
directive|include
file|<linux/posix_cap_xattr.h>
end_include

begin_struct_decl
struct_decl|struct
name|xfs_vnode
struct_decl|;
end_struct_decl

begin_function_decl
specifier|extern
name|int
name|xfs_cap_vhascap
parameter_list|(
name|struct
name|xfs_vnode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|xfs_cap_vset
parameter_list|(
name|struct
name|xfs_vnode
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|xfs_cap_vget
parameter_list|(
name|struct
name|xfs_vnode
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|xfs_cap_vremove
parameter_list|(
name|struct
name|xfs_vnode
modifier|*
name|vp
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|_CAP_EXISTS
value|xfs_cap_vhascap
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|xfs_cap_vset
parameter_list|(
name|v
parameter_list|,
name|p
parameter_list|,
name|sz
parameter_list|)
value|(-EOPNOTSUPP)
end_define

begin_define
define|#
directive|define
name|xfs_cap_vget
parameter_list|(
name|v
parameter_list|,
name|p
parameter_list|,
name|sz
parameter_list|)
value|(-EOPNOTSUPP)
end_define

begin_define
define|#
directive|define
name|xfs_cap_vremove
parameter_list|(
name|v
parameter_list|)
value|(-EOPNOTSUPP)
end_define

begin_define
define|#
directive|define
name|_CAP_EXISTS
value|(NULL)
end_define

begin_endif
endif|#
directive|endif
end_endif

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
comment|/* __XFS_CAP_H__ */
end_comment

end_unit

