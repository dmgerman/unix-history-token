begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2005 Silicon Graphics, Inc.  * All Rights Reserved.  *  * This program is free software; you can redistribute it and/or  * modify it under the terms of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it would be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write the Free Software Foundation,  * Inc.,  51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XFS_SUPER_H__
end_ifndef

begin_define
define|#
directive|define
name|__XFS_SUPER_H__
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_XFS_DMAPI
end_ifdef

begin_define
define|#
directive|define
name|vfs_insertdmapi
parameter_list|(
name|vfs
parameter_list|)
value|vfs_insertops(vfsp,&xfs_dmops)
end_define

begin_define
define|#
directive|define
name|vfs_initdmapi
parameter_list|()
value|dmapi_init()
end_define

begin_define
define|#
directive|define
name|vfs_exitdmapi
parameter_list|()
value|dmapi_uninit()
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|vfs_insertdmapi
parameter_list|(
name|vfs
parameter_list|)
value|do { } while (0)
end_define

begin_define
define|#
directive|define
name|vfs_initdmapi
parameter_list|()
value|do { } while (0)
end_define

begin_define
define|#
directive|define
name|vfs_exitdmapi
parameter_list|()
value|do { } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_XFS_QUOTA
end_ifdef

begin_define
define|#
directive|define
name|vfs_insertquota
parameter_list|(
name|vfs
parameter_list|)
value|vfs_insertops(vfsp,&xfs_qmops)
end_define

begin_define
define|#
directive|define
name|vfs_initquota
parameter_list|()
value|xfs_qm_init()
end_define

begin_define
define|#
directive|define
name|vfs_exitquota
parameter_list|()
value|xfs_qm_exit()
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|vfs_insertquota
parameter_list|(
name|vfs
parameter_list|)
value|do { } while (0)
end_define

begin_define
define|#
directive|define
name|vfs_initquota
parameter_list|()
value|do { } while (0)
end_define

begin_define
define|#
directive|define
name|vfs_exitquota
parameter_list|()
value|do { } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_XFS_POSIX_ACL
end_ifdef

begin_define
define|#
directive|define
name|XFS_ACL_STRING
value|"ACLs, "
end_define

begin_define
define|#
directive|define
name|set_posix_acl_flag
parameter_list|(
name|sb
parameter_list|)
value|((sb)->s_flags |= MS_POSIXACL)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_ACL_STRING
end_define

begin_define
define|#
directive|define
name|set_posix_acl_flag
parameter_list|(
name|sb
parameter_list|)
value|do { } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_XFS_SECURITY
end_ifdef

begin_define
define|#
directive|define
name|XFS_SECURITY_STRING
value|"security attributes, "
end_define

begin_define
define|#
directive|define
name|ENOSECURITY
value|0
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_SECURITY_STRING
end_define

begin_define
define|#
directive|define
name|ENOSECURITY
value|EOPNOTSUPP
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_XFS_RT
end_ifdef

begin_define
define|#
directive|define
name|XFS_REALTIME_STRING
value|"realtime, "
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_REALTIME_STRING
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|XFS_BIG_BLKNOS
end_if

begin_if
if|#
directive|if
name|XFS_BIG_INUMS
end_if

begin_define
define|#
directive|define
name|XFS_BIGFS_STRING
value|"large block/inode numbers, "
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_BIGFS_STRING
value|"large block numbers, "
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_BIGFS_STRING
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_XFS_TRACE
end_ifdef

begin_define
define|#
directive|define
name|XFS_TRACE_STRING
value|"tracing, "
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_TRACE_STRING
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|XFSDEBUG
end_ifdef

begin_define
define|#
directive|define
name|XFS_DBG_STRING
value|"debug"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XFS_DBG_STRING
value|"no debug"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|XFS_BUILD_OPTIONS
value|XFS_ACL_STRING \ 				XFS_SECURITY_STRING \ 				XFS_REALTIME_STRING \ 				XFS_BIGFS_STRING \ 				XFS_TRACE_STRING \ 				XFS_DBG_STRING
end_define

begin_comment
comment|/* DBG must be last */
end_comment

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

begin_struct_decl
struct_decl|struct
name|xfs_buftarg
struct_decl|;
end_struct_decl

begin_function_decl
specifier|extern
name|__uint64_t
name|xfs_max_file_offset
parameter_list|(
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|xfs_initialize_vnode
parameter_list|(
name|bhv_desc_t
modifier|*
parameter_list|,
name|xfs_vnode_t
modifier|*
parameter_list|,
name|bhv_desc_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|xfs_flush_inode
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
name|xfs_flush_device
parameter_list|(
name|struct
name|xfs_inode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|xfs_blkdev_get
parameter_list|(
name|struct
name|xfs_mount
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|block_device
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|xfs_blkdev_put
parameter_list|(
name|struct
name|block_device
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|xfs_blkdev_issue_flush
parameter_list|(
name|struct
name|xfs_buftarg
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|struct
name|export_operations
name|xfs_export_operations
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|init_xfs_fs
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|exit_xfs_fs
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XFS_SUPER_H__ */
end_comment

end_unit

