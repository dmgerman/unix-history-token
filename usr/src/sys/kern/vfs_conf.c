begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)vfs_conf.c	8.8 (Berkeley) 3/31/94  */
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
name|rootvnode
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

begin_ifdef
ifdef|#
directive|ifdef
name|NULLFS
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|vfsops
name|null_vfsops
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|NULL_VFSOPS
value|&null_vfsops
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NULL_VFSOPS
value|NULL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|UMAPFS
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|vfsops
name|umap_vfsops
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|UMAP_VFSOPS
value|&umap_vfsops
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|UMAP_VFSOPS
value|NULL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|KERNFS
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|vfsops
name|kernfs_vfsops
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|KERNFS_VFSOPS
value|&kernfs_vfsops
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|KERNFS_VFSOPS
value|NULL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|PROCFS
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|vfsops
name|procfs_vfsops
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|PROCFS_VFSOPS
value|&procfs_vfsops
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PROCFS_VFSOPS
value|NULL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|AFS
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|vfsops
name|afs_vfsops
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|AFS_VFSOPS
value|&afs_vfsops
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|AFS_VFSOPS
value|NULL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CD9660
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|vfsops
name|cd9660_vfsops
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|CD9660_VFSOPS
value|&cd9660_vfsops
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CD9660_VFSOPS
value|NULL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|UNION
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|vfsops
name|union_vfsops
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|UNION_VFSOPS
value|&union_vfsops
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|UNION_VFSOPS
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
name|NULL
block|,
comment|/* 6 = MOUNT_LOFS */
name|FDESC_VFSOPS
block|,
comment|/* 7 = MOUNT_FDESC */
name|PORTAL_VFSOPS
block|,
comment|/* 8 = MOUNT_PORTAL */
name|NULL_VFSOPS
block|,
comment|/* 9 = MOUNT_NULL */
name|UMAP_VFSOPS
block|,
comment|/* 10 = MOUNT_UMAP */
name|KERNFS_VFSOPS
block|,
comment|/* 11 = MOUNT_KERNFS */
name|PROCFS_VFSOPS
block|,
comment|/* 12 = MOUNT_PROCFS */
name|AFS_VFSOPS
block|,
comment|/* 13 = MOUNT_AFS */
name|CD9660_VFSOPS
block|,
comment|/* 14 = MOUNT_CD9660 */
name|UNION_VFSOPS
block|,
comment|/* 15 = MOUNT_UNION */
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  *  * vfs_opv_descs enumerates the list of vnode classes, each with it's own  * vnode operation vector.  It is consulted at system boot to build operation  * vectors.  It is NULL terminated.  *  */
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
specifier|extern
name|struct
name|vnodeopv_desc
name|fdesc_vnodeop_opv_desc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|vnodeopv_desc
name|portal_vnodeop_opv_desc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|vnodeopv_desc
name|null_vnodeop_opv_desc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|vnodeopv_desc
name|umap_vnodeop_opv_desc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|vnodeopv_desc
name|kernfs_vnodeop_opv_desc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|vnodeopv_desc
name|procfs_vnodeop_opv_desc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|vnodeopv_desc
name|cd9660_vnodeop_opv_desc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|vnodeopv_desc
name|cd9660_specop_opv_desc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|vnodeopv_desc
name|cd9660_fifoop_opv_desc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|vnodeopv_desc
name|union_vnodeop_opv_desc
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
ifdef|#
directive|ifdef
name|FIFO
operator|&
name|ffs_fifoop_opv_desc
block|,
endif|#
directive|endif
operator|&
name|dead_vnodeop_opv_desc
block|,
ifdef|#
directive|ifdef
name|FIFO
operator|&
name|fifo_vnodeop_opv_desc
block|,
endif|#
directive|endif
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
ifdef|#
directive|ifdef
name|FIFO
operator|&
name|lfs_fifoop_opv_desc
block|,
endif|#
directive|endif
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
ifdef|#
directive|ifdef
name|FIFO
operator|&
name|fifo_nfsv2nodeop_opv_desc
block|,
endif|#
directive|endif
endif|#
directive|endif
ifdef|#
directive|ifdef
name|FDESC
operator|&
name|fdesc_vnodeop_opv_desc
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|PORTAL
operator|&
name|portal_vnodeop_opv_desc
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|NULLFS
operator|&
name|null_vnodeop_opv_desc
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|UMAPFS
operator|&
name|umap_vnodeop_opv_desc
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|KERNFS
operator|&
name|kernfs_vnodeop_opv_desc
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|PROCFS
operator|&
name|procfs_vnodeop_opv_desc
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|CD9660
operator|&
name|cd9660_vnodeop_opv_desc
block|,
operator|&
name|cd9660_specop_opv_desc
block|,
ifdef|#
directive|ifdef
name|FIFO
operator|&
name|cd9660_fifoop_opv_desc
block|,
endif|#
directive|endif
endif|#
directive|endif
ifdef|#
directive|ifdef
name|UNION
operator|&
name|union_vnodeop_opv_desc
block|,
endif|#
directive|endif
name|NULL
block|}
decl_stmt|;
end_decl_stmt

end_unit

