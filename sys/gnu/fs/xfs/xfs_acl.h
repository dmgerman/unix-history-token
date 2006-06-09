begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2001-2005 Silicon Graphics, Inc.  * All Rights Reserved.  *  * This program is free software; you can redistribute it and/or  * modify it under the terms of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it would be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write the Free Software Foundation,  * Inc.,  51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XFS_ACL_H__
end_ifndef

begin_define
define|#
directive|define
name|__XFS_ACL_H__
end_define

begin_comment
comment|/*  * Access Control Lists  */
end_comment

begin_typedef
typedef|typedef
name|__uint16_t
name|xfs_acl_perm_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__int32_t
name|xfs_acl_type_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__int32_t
name|xfs_acl_tag_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__int32_t
name|xfs_acl_id_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|XFS_ACL_MAX_ENTRIES
value|25
end_define

begin_define
define|#
directive|define
name|XFS_ACL_NOT_PRESENT
value|(-1)
end_define

begin_typedef
typedef|typedef
struct|struct
name|xfs_acl_entry
block|{
name|xfs_acl_tag_t
name|ae_tag
decl_stmt|;
name|xfs_acl_id_t
name|ae_id
decl_stmt|;
name|xfs_acl_perm_t
name|ae_perm
decl_stmt|;
block|}
name|xfs_acl_entry_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|xfs_acl
block|{
name|__int32_t
name|acl_cnt
decl_stmt|;
name|xfs_acl_entry_t
name|acl_entry
index|[
name|XFS_ACL_MAX_ENTRIES
index|]
decl_stmt|;
block|}
name|xfs_acl_t
typedef|;
end_typedef

begin_comment
comment|/* On-disk XFS extended attribute names */
end_comment

begin_define
define|#
directive|define
name|SGI_ACL_FILE
value|"SGI_ACL_FILE"
end_define

begin_define
define|#
directive|define
name|SGI_ACL_DEFAULT
value|"SGI_ACL_DEFAULT"
end_define

begin_define
define|#
directive|define
name|SGI_ACL_FILE_SIZE
value|(sizeof(SGI_ACL_FILE)-1)
end_define

begin_define
define|#
directive|define
name|SGI_ACL_DEFAULT_SIZE
value|(sizeof(SGI_ACL_DEFAULT)-1)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_XFS_POSIX_ACL
end_ifdef

begin_struct_decl
struct_decl|struct
name|vattr
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|vnode
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_inode
struct_decl|;
end_struct_decl

begin_decl_stmt
specifier|extern
name|struct
name|kmem_zone
modifier|*
name|xfs_acl_zone
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|xfs_acl_zone_init
parameter_list|(
name|zone
parameter_list|,
name|name
parameter_list|)
define|\
value|(zone) = kmem_zone_init(sizeof(xfs_acl_t), (name))
end_define

begin_define
define|#
directive|define
name|xfs_acl_zone_destroy
parameter_list|(
name|zone
parameter_list|)
value|kmem_zone_destroy(zone)
end_define

begin_function_decl
specifier|extern
name|int
name|xfs_acl_inherit
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|,
name|struct
name|vattr
modifier|*
parameter_list|,
name|xfs_acl_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|xfs_acl_iaccess
parameter_list|(
name|struct
name|xfs_inode
modifier|*
parameter_list|,
name|mode_t
parameter_list|,
name|cred_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|xfs_acl_vtoacl
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|,
name|xfs_acl_t
modifier|*
parameter_list|,
name|xfs_acl_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|xfs_acl_vhasacl_access
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|xfs_acl_vhasacl_default
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|xfs_acl_vset
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|xfs_acl_vget
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|xfs_acl_vremove
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|_ACL_TYPE_ACCESS
value|1
end_define

begin_define
define|#
directive|define
name|_ACL_TYPE_DEFAULT
value|2
end_define

begin_define
define|#
directive|define
name|_ACL_PERM_INVALID
parameter_list|(
name|perm
parameter_list|)
value|((perm)& ~(ACL_READ|ACL_WRITE|ACL_EXECUTE))
end_define

begin_define
define|#
directive|define
name|_ACL_INHERIT
parameter_list|(
name|c
parameter_list|,
name|v
parameter_list|,
name|d
parameter_list|)
value|(xfs_acl_inherit(c,v,d))
end_define

begin_define
define|#
directive|define
name|_ACL_GET_ACCESS
parameter_list|(
name|pv
parameter_list|,
name|pa
parameter_list|)
value|(xfs_acl_vtoacl(pv,pa,NULL) == 0)
end_define

begin_define
define|#
directive|define
name|_ACL_GET_DEFAULT
parameter_list|(
name|pv
parameter_list|,
name|pd
parameter_list|)
value|(xfs_acl_vtoacl(pv,NULL,pd) == 0)
end_define

begin_define
define|#
directive|define
name|_ACL_ACCESS_EXISTS
value|xfs_acl_vhasacl_access
end_define

begin_define
define|#
directive|define
name|_ACL_DEFAULT_EXISTS
value|xfs_acl_vhasacl_default
end_define

begin_define
define|#
directive|define
name|_ACL_XFS_IACCESS
parameter_list|(
name|i
parameter_list|,
name|m
parameter_list|,
name|c
parameter_list|)
value|(XFS_IFORK_Q(i) ? xfs_acl_iaccess(i,m,c) : -1)
end_define

begin_define
define|#
directive|define
name|_ACL_ALLOC
parameter_list|(
name|a
parameter_list|)
value|((a) = kmem_zone_alloc(xfs_acl_zone, KM_SLEEP))
end_define

begin_define
define|#
directive|define
name|_ACL_FREE
parameter_list|(
name|a
parameter_list|)
value|((a)? kmem_zone_free(xfs_acl_zone, (a)):(void)0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|xfs_acl_zone_init
parameter_list|(
name|zone
parameter_list|,
name|name
parameter_list|)
end_define

begin_define
define|#
directive|define
name|xfs_acl_zone_destroy
parameter_list|(
name|zone
parameter_list|)
end_define

begin_define
define|#
directive|define
name|xfs_acl_vset
parameter_list|(
name|v
parameter_list|,
name|p
parameter_list|,
name|sz
parameter_list|,
name|t
parameter_list|)
value|(-EOPNOTSUPP)
end_define

begin_define
define|#
directive|define
name|xfs_acl_vget
parameter_list|(
name|v
parameter_list|,
name|p
parameter_list|,
name|sz
parameter_list|,
name|t
parameter_list|)
value|(-EOPNOTSUPP)
end_define

begin_define
define|#
directive|define
name|xfs_acl_vremove
parameter_list|(
name|v
parameter_list|,
name|t
parameter_list|)
value|(-EOPNOTSUPP)
end_define

begin_define
define|#
directive|define
name|xfs_acl_vhasacl_access
parameter_list|(
name|v
parameter_list|)
value|(0)
end_define

begin_define
define|#
directive|define
name|xfs_acl_vhasacl_default
parameter_list|(
name|v
parameter_list|)
value|(0)
end_define

begin_define
define|#
directive|define
name|_ACL_ALLOC
parameter_list|(
name|a
parameter_list|)
value|(1)
end_define

begin_comment
comment|/* successfully allocate nothing */
end_comment

begin_define
define|#
directive|define
name|_ACL_FREE
parameter_list|(
name|a
parameter_list|)
value|((void)0)
end_define

begin_define
define|#
directive|define
name|_ACL_INHERIT
parameter_list|(
name|c
parameter_list|,
name|v
parameter_list|,
name|d
parameter_list|)
value|(0)
end_define

begin_define
define|#
directive|define
name|_ACL_GET_ACCESS
parameter_list|(
name|pv
parameter_list|,
name|pa
parameter_list|)
value|(0)
end_define

begin_define
define|#
directive|define
name|_ACL_GET_DEFAULT
parameter_list|(
name|pv
parameter_list|,
name|pd
parameter_list|)
value|(0)
end_define

begin_define
define|#
directive|define
name|_ACL_ACCESS_EXISTS
value|(NULL)
end_define

begin_define
define|#
directive|define
name|_ACL_DEFAULT_EXISTS
value|(NULL)
end_define

begin_define
define|#
directive|define
name|_ACL_XFS_IACCESS
parameter_list|(
name|i
parameter_list|,
name|m
parameter_list|,
name|c
parameter_list|)
value|(-1)
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
comment|/* __XFS_ACL_H__ */
end_comment

end_unit

