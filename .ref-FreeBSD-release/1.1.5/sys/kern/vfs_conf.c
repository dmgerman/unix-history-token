begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)vfs_conf.c	7.3 (Berkeley) 6/28/90  *	$Id: vfs_conf.c,v 1.4 1993/12/19 00:51:49 wollman Exp $  */
end_comment

begin_include
include|#
directive|include
file|"param.h"
end_include

begin_include
include|#
directive|include
file|"systm.h"
end_include

begin_include
include|#
directive|include
file|"mount.h"
end_include

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

begin_ifdef
ifdef|#
directive|ifdef
name|PCFS
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|vfsops
name|pcfs_vfsops
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|ISOFS
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|vfsops
name|isofs_vfsops
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|struct
name|vfsops
name|procfs_vfsops
decl_stmt|;
end_decl_stmt

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
ifdef|#
directive|ifdef
name|PCFS
operator|&
name|pcfs_vfsops
block|,
comment|/* 4 = MOUNT_MSDOS */
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
name|ISOFS
operator|&
name|isofs_vfsops
block|,
comment|/* 5 = MOUNT_ISOFS */
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
operator|&
name|procfs_vfsops
block|,
comment|/* 6 = MOUNT_PROCFS */
block|}
decl_stmt|;
end_decl_stmt

end_unit

