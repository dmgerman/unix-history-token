begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)vfs_conf.c	7.2 (Berkeley) %G%  */
end_comment

begin_include
include|#
directive|include
file|"param.h"
end_include

begin_include
include|#
directive|include
file|"mount.h"
end_include

begin_comment
comment|/*  * This specifies the filesystem used to mount the root.  * This specification should be done by /etc/config.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|ufs_mountroot
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
function_decl|(
modifier|*
name|mountroot
function_decl|)
parameter_list|()
init|=
name|ufs_mountroot
function_decl|;
end_function_decl

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

begin_decl_stmt
specifier|extern
name|struct
name|vfsops
name|ufs_vfsops
decl_stmt|;
end_decl_stmt

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
operator|(
expr|struct
name|vfsops
operator|*
operator|)
literal|0
block|,
comment|/* 0 = MOUNT_NONE */
operator|&
name|ufs_vfsops
block|,
comment|/* 1 = MOUNT_UFS */
ifdef|#
directive|ifdef
name|NFS
operator|&
name|nfs_vfsops
block|,
comment|/* 2 = MOUNT_NFS */
else|#
directive|else
operator|(
expr|struct
name|vfsops
operator|*
operator|)
literal|0
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|MFS
operator|&
name|mfs_vfsops
block|,
comment|/* 3 = MOUNT_MFS */
else|#
directive|else
operator|(
expr|struct
name|vfsops
operator|*
operator|)
literal|0
block|,
endif|#
directive|endif
operator|(
expr|struct
name|vfsops
operator|*
operator|)
literal|0
block|,
comment|/* 4 = MOUNT_PC */
block|}
decl_stmt|;
end_decl_stmt

end_unit

