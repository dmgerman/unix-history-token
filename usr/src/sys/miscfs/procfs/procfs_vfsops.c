begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1993 Jan-Simon Pendry  * Copyright (c) 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Jan-Simon Pendry.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)procfs_vfsops.c	8.7 (Berkeley) 5/10/95  *  * From:  *	$Id: procfs_vfsops.c,v 3.1 1993/12/15 09:40:17 jsp Exp $  */
end_comment

begin_comment
comment|/*  * procfs VFS interface  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/buf.h>
end_include

begin_include
include|#
directive|include
file|<sys/syslog.h>
end_include

begin_include
include|#
directive|include
file|<sys/mount.h>
end_include

begin_include
include|#
directive|include
file|<sys/signalvar.h>
end_include

begin_include
include|#
directive|include
file|<sys/vnode.h>
end_include

begin_include
include|#
directive|include
file|<miscfs/procfs/procfs.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_comment
comment|/* for PAGE_SIZE */
end_comment

begin_comment
comment|/*  * VFS Operations.  *  * mount system call  */
end_comment

begin_comment
comment|/* ARGSUSED */
end_comment

begin_macro
name|procfs_mount
argument_list|(
argument|mp
argument_list|,
argument|path
argument_list|,
argument|data
argument_list|,
argument|ndp
argument_list|,
argument|p
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|mount
modifier|*
name|mp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|path
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|caddr_t
name|data
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|nameidata
modifier|*
name|ndp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|proc
modifier|*
name|p
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|u_int
name|size
decl_stmt|;
if|if
condition|(
name|UIO_MX
operator|&
operator|(
name|UIO_MX
operator|-
literal|1
operator|)
condition|)
block|{
name|log
argument_list|(
name|LOG_ERR
argument_list|,
literal|"procfs: invalid directory entry size"
argument_list|)
expr_stmt|;
return|return
operator|(
name|EINVAL
operator|)
return|;
block|}
if|if
condition|(
name|mp
operator|->
name|mnt_flag
operator|&
name|MNT_UPDATE
condition|)
return|return
operator|(
name|EOPNOTSUPP
operator|)
return|;
name|mp
operator|->
name|mnt_flag
operator||=
name|MNT_LOCAL
expr_stmt|;
name|mp
operator|->
name|mnt_data
operator|=
literal|0
expr_stmt|;
name|vfs_getnewfsid
argument_list|(
name|mp
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|copyinstr
argument_list|(
name|path
argument_list|,
operator|(
name|caddr_t
operator|)
name|mp
operator|->
name|mnt_stat
operator|.
name|f_mntonname
argument_list|,
name|MNAMELEN
argument_list|,
operator|&
name|size
argument_list|)
expr_stmt|;
name|bzero
argument_list|(
name|mp
operator|->
name|mnt_stat
operator|.
name|f_mntonname
operator|+
name|size
argument_list|,
name|MNAMELEN
operator|-
name|size
argument_list|)
expr_stmt|;
name|size
operator|=
sizeof|sizeof
argument_list|(
literal|"procfs"
argument_list|)
operator|-
literal|1
expr_stmt|;
name|bcopy
argument_list|(
literal|"procfs"
argument_list|,
name|mp
operator|->
name|mnt_stat
operator|.
name|f_mntfromname
argument_list|,
name|size
argument_list|)
expr_stmt|;
name|bzero
argument_list|(
name|mp
operator|->
name|mnt_stat
operator|.
name|f_mntfromname
operator|+
name|size
argument_list|,
name|MNAMELEN
operator|-
name|size
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * unmount system call  */
end_comment

begin_macro
name|procfs_unmount
argument_list|(
argument|mp
argument_list|,
argument|mntflags
argument_list|,
argument|p
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|mount
modifier|*
name|mp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|mntflags
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|proc
modifier|*
name|p
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|error
decl_stmt|;
name|int
name|flags
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|mntflags
operator|&
name|MNT_FORCE
condition|)
name|flags
operator||=
name|FORCECLOSE
expr_stmt|;
if|if
condition|(
name|error
operator|=
name|vflush
argument_list|(
name|mp
argument_list|,
literal|0
argument_list|,
name|flags
argument_list|)
condition|)
return|return
operator|(
name|error
operator|)
return|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_macro
name|procfs_root
argument_list|(
argument|mp
argument_list|,
argument|vpp
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|mount
modifier|*
name|mp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|vnode
modifier|*
modifier|*
name|vpp
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
name|procfs_allocvp
argument_list|(
name|mp
argument_list|,
name|vpp
argument_list|,
literal|0
argument_list|,
name|Proot
argument_list|)
operator|)
return|;
block|}
end_block

begin_comment
comment|/* ARGSUSED */
end_comment

begin_macro
name|procfs_start
argument_list|(
argument|mp
argument_list|,
argument|flags
argument_list|,
argument|p
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|mount
modifier|*
name|mp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|flags
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|proc
modifier|*
name|p
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * Get file system statistics.  */
end_comment

begin_macro
name|procfs_statfs
argument_list|(
argument|mp
argument_list|,
argument|sbp
argument_list|,
argument|p
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|mount
modifier|*
name|mp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|statfs
modifier|*
name|sbp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|proc
modifier|*
name|p
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|sbp
operator|->
name|f_bsize
operator|=
name|PAGE_SIZE
expr_stmt|;
name|sbp
operator|->
name|f_iosize
operator|=
name|PAGE_SIZE
expr_stmt|;
name|sbp
operator|->
name|f_blocks
operator|=
literal|1
expr_stmt|;
comment|/* avoid divide by zero in some df's */
name|sbp
operator|->
name|f_bfree
operator|=
literal|0
expr_stmt|;
name|sbp
operator|->
name|f_bavail
operator|=
literal|0
expr_stmt|;
name|sbp
operator|->
name|f_files
operator|=
name|maxproc
expr_stmt|;
comment|/* approx */
name|sbp
operator|->
name|f_ffree
operator|=
name|maxproc
operator|-
name|nprocs
expr_stmt|;
comment|/* approx */
if|if
condition|(
name|sbp
operator|!=
operator|&
name|mp
operator|->
name|mnt_stat
condition|)
block|{
name|sbp
operator|->
name|f_type
operator|=
name|mp
operator|->
name|mnt_vfc
operator|->
name|vfc_typenum
expr_stmt|;
name|bcopy
argument_list|(
operator|&
name|mp
operator|->
name|mnt_stat
operator|.
name|f_fsid
argument_list|,
operator|&
name|sbp
operator|->
name|f_fsid
argument_list|,
sizeof|sizeof
argument_list|(
name|sbp
operator|->
name|f_fsid
argument_list|)
argument_list|)
expr_stmt|;
name|bcopy
argument_list|(
name|mp
operator|->
name|mnt_stat
operator|.
name|f_mntonname
argument_list|,
name|sbp
operator|->
name|f_mntonname
argument_list|,
name|MNAMELEN
argument_list|)
expr_stmt|;
name|bcopy
argument_list|(
name|mp
operator|->
name|mnt_stat
operator|.
name|f_mntfromname
argument_list|,
name|sbp
operator|->
name|f_mntfromname
argument_list|,
name|MNAMELEN
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_macro
name|procfs_init
argument_list|(
argument|vfsp
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|vfsconf
modifier|*
name|vfsp
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_define
define|#
directive|define
name|procfs_fhtovp
value|((int (*) __P((struct mount *, struct fid *, \ 	    struct mbuf *, struct vnode **, int *, struct ucred **)))einval)
end_define

begin_define
define|#
directive|define
name|procfs_quotactl
value|((int (*) __P((struct mount *, int, uid_t, caddr_t, \ 	    struct proc *)))eopnotsupp)
end_define

begin_define
define|#
directive|define
name|procfs_sync
value|((int (*) __P((struct mount *, int, struct ucred *, \ 	    struct proc *)))nullop)
end_define

begin_define
define|#
directive|define
name|procfs_sysctl
value|((int (*) __P((int *, u_int, void *, size_t *, void *, \ 	    size_t, struct proc *)))eopnotsupp)
end_define

begin_define
define|#
directive|define
name|procfs_vget
value|((int (*) __P((struct mount *, ino_t, struct vnode **))) \ 	    eopnotsupp)
end_define

begin_define
define|#
directive|define
name|procfs_vptofh
value|((int (*) __P((struct vnode *, struct fid *)))einval)
end_define

begin_decl_stmt
name|struct
name|vfsops
name|procfs_vfsops
init|=
block|{
name|procfs_mount
block|,
name|procfs_start
block|,
name|procfs_unmount
block|,
name|procfs_root
block|,
name|procfs_quotactl
block|,
name|procfs_statfs
block|,
name|procfs_sync
block|,
name|procfs_vget
block|,
name|procfs_fhtovp
block|,
name|procfs_vptofh
block|,
name|procfs_init
block|,
name|procfs_sysctl
block|, }
decl_stmt|;
end_decl_stmt

end_unit

