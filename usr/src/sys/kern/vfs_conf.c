begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)vfs_conf.c	7.10 (Berkeley) %G%  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/mount.h>
end_include

begin_include
include|#
directive|include
file|<sys/vnode.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|FFS
end_ifdef

begin_include
include|#
directive|include
file|<ufs/ffs/ffs_extern.h>
end_include

begin_comment
comment|/*  * This specifies the filesystem used to mount the root.  * This specification should be done by /etc/config.  */
end_comment

begin_function_decl
name|int
function_decl|(
modifier|*
name|mountroot
function_decl|)
parameter_list|()
init|=
name|ffs_mountroot
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * These define the root filesystem and device.  */
end_comment

begin_decl_stmt
name|struct
name|mount
modifier|*
name|rootfs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|vnode
modifier|*
name|rootdir
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Set up the filesystem operations for vnodes.  * The types are defined in mount.h.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|FFS
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|vfsops
name|ufs_vfsops
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|UFS_VFSOPS
value|&ufs_vfsops
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|UFS_VFSOPS
value|NULL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|LFS
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|vfsops
name|lfs_vfsops
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|LFS_VFSOPS
value|&lfs_vfsops
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LFS_VFSOPS
value|NULL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|MFS
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|vfsops
name|mfs_vfsops
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|MFS_VFSOPS
value|&mfs_vfsops
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MFS_VFSOPS
value|NULL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|NFS
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|vfsops
name|nfs_vfsops
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|NFS_VFSOPS
value|&nfs_vfsops
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NFS_VFSOPS
value|NULL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|LOFS
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|vfsops
name|lofs_vfsops
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|LOFS_VFSOPS
value|&lofs_vfsops
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LOFS_VFSOPS
value|NULL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|FDESC
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|vfsops
name|fdesc_vfsops
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|FDESC_VFSOPS
value|&fdesc_vfsops
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|FDESC_VFSOPS
value|NULL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|PORTAL
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|vfsops
name|portal_vfsops
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|PORTAL_VFSOPS
value|&portal_vfsops
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PORTAL_VFSOPS
value|NULL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|struct
name|vfsops
modifier|*
name|vfssw
index|[]
init|=
block|{
name|NULL
block|,
comment|/* 0 = MOUNT_NONE */
name|UFS_VFSOPS
block|,
comment|/* 1 = MOUNT_UFS */
name|NFS_VFSOPS
block|,
comment|/* 2 = MOUNT_NFS */
name|MFS_VFSOPS
block|,
comment|/* 3 = MOUNT_MFS */
name|NULL
block|,
comment|/* 4 = MOUNT_PC */
name|LFS_VFSOPS
block|,
comment|/* 5 = MOUNT_LFS */
name|LOFS_VFSOPS
block|,
comment|/* 6 = MOUNT_LOFS */
name|FDESC_VFSOPS
block|,
comment|/* 7 = MOUNT_FDESC */
name|PORTAL_VFSOPS
block|,
comment|/* 8 = MOUNT_PORTAL */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Vnode_op_descs lists all vnode operations supported.  * At boot time vfs_op_init examines this list  * to configure vnode operations vectors.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|vnodeop_desc
name|vop_lookup_desc
decl_stmt|,
name|vop_create_desc
decl_stmt|,
name|vop_mknod_desc
decl_stmt|,
name|vop_open_desc
decl_stmt|,
name|vop_close_desc
decl_stmt|,
name|vop_access_desc
decl_stmt|,
name|vop_getattr_desc
decl_stmt|,
name|vop_setattr_desc
decl_stmt|,
name|vop_read_desc
decl_stmt|,
name|vop_write_desc
decl_stmt|,
name|vop_ioctl_desc
decl_stmt|,
name|vop_select_desc
decl_stmt|,
name|vop_mmap_desc
decl_stmt|,
name|vop_fsync_desc
decl_stmt|,
name|vop_seek_desc
decl_stmt|,
name|vop_remove_desc
decl_stmt|,
name|vop_link_desc
decl_stmt|,
name|vop_rename_desc
decl_stmt|,
name|vop_mkdir_desc
decl_stmt|,
name|vop_rmdir_desc
decl_stmt|,
name|vop_symlink_desc
decl_stmt|,
name|vop_readdir_desc
decl_stmt|,
name|vop_readlink_desc
decl_stmt|,
name|vop_abortop_desc
decl_stmt|,
name|vop_inactive_desc
decl_stmt|,
name|vop_reclaim_desc
decl_stmt|,
name|vop_lock_desc
decl_stmt|,
name|vop_unlock_desc
decl_stmt|,
name|vop_bmap_desc
decl_stmt|,
name|vop_strategy_desc
decl_stmt|,
name|vop_print_desc
decl_stmt|,
name|vop_islocked_desc
decl_stmt|,
name|vop_advlock_desc
decl_stmt|,
name|vop_blkatoff_desc
decl_stmt|,
name|vop_vget_desc
decl_stmt|,
name|vop_valloc_desc
decl_stmt|,
name|vop_vfree_desc
decl_stmt|,
name|vop_truncate_desc
decl_stmt|,
name|vop_update_desc
decl_stmt|,
name|vop_bwrite_desc
decl_stmt|,
comment|/* and the default */
name|vop_default_desc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|vnodeop_desc
modifier|*
name|vfs_op_descs
index|[]
init|=
block|{
operator|&
name|vop_default_desc
block|,
comment|/* must be first */
operator|&
name|vop_lookup_desc
block|,
operator|&
name|vop_create_desc
block|,
operator|&
name|vop_mknod_desc
block|,
operator|&
name|vop_open_desc
block|,
operator|&
name|vop_close_desc
block|,
operator|&
name|vop_access_desc
block|,
operator|&
name|vop_getattr_desc
block|,
operator|&
name|vop_setattr_desc
block|,
operator|&
name|vop_read_desc
block|,
operator|&
name|vop_write_desc
block|,
operator|&
name|vop_ioctl_desc
block|,
operator|&
name|vop_select_desc
block|,
operator|&
name|vop_mmap_desc
block|,
operator|&
name|vop_fsync_desc
block|,
operator|&
name|vop_seek_desc
block|,
operator|&
name|vop_remove_desc
block|,
operator|&
name|vop_link_desc
block|,
operator|&
name|vop_rename_desc
block|,
operator|&
name|vop_mkdir_desc
block|,
operator|&
name|vop_rmdir_desc
block|,
operator|&
name|vop_symlink_desc
block|,
operator|&
name|vop_readdir_desc
block|,
operator|&
name|vop_readlink_desc
block|,
operator|&
name|vop_abortop_desc
block|,
operator|&
name|vop_inactive_desc
block|,
operator|&
name|vop_reclaim_desc
block|,
operator|&
name|vop_lock_desc
block|,
operator|&
name|vop_unlock_desc
block|,
operator|&
name|vop_bmap_desc
block|,
operator|&
name|vop_strategy_desc
block|,
operator|&
name|vop_print_desc
block|,
operator|&
name|vop_islocked_desc
block|,
operator|&
name|vop_advlock_desc
block|,
operator|&
name|vop_blkatoff_desc
block|,
operator|&
name|vop_vget_desc
block|,
operator|&
name|vop_valloc_desc
block|,
operator|&
name|vop_vfree_desc
block|,
operator|&
name|vop_truncate_desc
block|,
operator|&
name|vop_update_desc
block|,
operator|&
name|vop_bwrite_desc
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  *  * vfs_opv_descs enumerates the list of vnode classes,  * each with it's own vnode operation vector.  * It is consulted at system  * boot to build operation vectors.  * It's also null terminated.  *  * Out-of-kernel, someone else (more knowlegable about what file  * systems live in this address space) must specify this table.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|vnodeopv_desc
name|ffs_vnodeop_opv_desc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|vnodeopv_desc
name|ffs_specop_opv_desc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|vnodeopv_desc
name|ffs_fifoop_opv_desc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|vnodeopv_desc
name|lfs_vnodeop_opv_desc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|vnodeopv_desc
name|lfs_specop_opv_desc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|vnodeopv_desc
name|lfs_fifoop_opv_desc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|vnodeopv_desc
name|mfs_vnodeop_opv_desc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|vnodeopv_desc
name|dead_vnodeop_opv_desc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|vnodeopv_desc
name|fifo_vnodeop_opv_desc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|vnodeopv_desc
name|spec_vnodeop_opv_desc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|vnodeopv_desc
name|nfsv2_vnodeop_opv_desc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|vnodeopv_desc
name|spec_nfsv2nodeop_opv_desc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|vnodeopv_desc
name|fifo_nfsv2nodeop_opv_desc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|vnodeopv_desc
modifier|*
name|vfs_opv_descs
index|[]
init|=
block|{
operator|&
name|ffs_vnodeop_opv_desc
block|,
operator|&
name|ffs_specop_opv_desc
block|,
operator|&
name|ffs_fifoop_opv_desc
block|,
operator|&
name|dead_vnodeop_opv_desc
block|,
operator|&
name|fifo_vnodeop_opv_desc
block|,
operator|&
name|spec_vnodeop_opv_desc
block|,
ifdef|#
directive|ifdef
name|LFS
operator|&
name|lfs_vnodeop_opv_desc
block|,
operator|&
name|lfs_specop_opv_desc
block|,
operator|&
name|lfs_fifoop_opv_desc
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|MFS
operator|&
name|mfs_vnodeop_opv_desc
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|NFS
operator|&
name|nfsv2_vnodeop_opv_desc
block|,
operator|&
name|spec_nfsv2nodeop_opv_desc
block|,
operator|&
name|fifo_nfsv2nodeop_opv_desc
block|,
endif|#
directive|endif
name|NULL
block|}
decl_stmt|;
end_decl_stmt

end_unit

