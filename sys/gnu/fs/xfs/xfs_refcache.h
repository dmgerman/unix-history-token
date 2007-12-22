begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2003,2005 Silicon Graphics, Inc.  * All Rights Reserved.  *  * This program is free software; you can redistribute it and/or  * modify it under the terms of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it would be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write the Free Software Foundation,  * Inc.,  51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XFS_REFCACHE_H__
end_ifndef

begin_define
define|#
directive|define
name|__XFS_REFCACHE_H__
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_REFCACHE
end_ifdef

begin_comment
comment|/*  * Maximum size (in inodes) for the NFS reference cache  */
end_comment

begin_define
define|#
directive|define
name|XFS_REFCACHE_SIZE_MAX
value|512
end_define

begin_struct_decl
struct_decl|struct
name|xfs_inode
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_mount
struct_decl|;
end_struct_decl

begin_function_decl
specifier|extern
name|void
name|xfs_refcache_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|xfs_refcache_insert
parameter_list|(
name|struct
name|xfs_inode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|xfs_refcache_purge_ip
parameter_list|(
name|struct
name|xfs_inode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|xfs_refcache_purge_mp
parameter_list|(
name|struct
name|xfs_mount
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|xfs_refcache_purge_some
parameter_list|(
name|struct
name|xfs_mount
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|xfs_refcache_resize
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|xfs_refcache_destroy
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|xfs_refcache_iunlock
parameter_list|(
name|struct
name|xfs_inode
modifier|*
parameter_list|,
name|uint
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|xfs_refcache_init
parameter_list|()
value|do { } while (0)
end_define

begin_define
define|#
directive|define
name|xfs_refcache_insert
parameter_list|(
name|ip
parameter_list|)
value|do { } while (0)
end_define

begin_define
define|#
directive|define
name|xfs_refcache_purge_ip
parameter_list|(
name|ip
parameter_list|)
value|do { } while (0)
end_define

begin_define
define|#
directive|define
name|xfs_refcache_purge_mp
parameter_list|(
name|mp
parameter_list|)
value|do { } while (0)
end_define

begin_define
define|#
directive|define
name|xfs_refcache_purge_some
parameter_list|(
name|mp
parameter_list|)
value|do { } while (0)
end_define

begin_define
define|#
directive|define
name|xfs_refcache_resize
parameter_list|(
name|size
parameter_list|)
value|do { } while (0)
end_define

begin_define
define|#
directive|define
name|xfs_refcache_destroy
parameter_list|()
value|do { } while (0)
end_define

begin_define
define|#
directive|define
name|xfs_refcache_iunlock
parameter_list|(
name|ip
parameter_list|,
name|flags
parameter_list|)
value|xfs_iunlock(ip, flags)
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
comment|/* __XFS_REFCACHE_H__ */
end_comment

end_unit

