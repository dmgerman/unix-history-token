begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)vfs_conf.c	7.6 (Berkeley) %G%  */
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
block|}
decl_stmt|;
end_decl_stmt

end_unit

