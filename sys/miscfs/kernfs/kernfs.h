begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software donated to Berkeley by  * Jan-Simon Pendry.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)kernfs.h	8.6 (Berkeley) 3/29/95  * $Id: kernfs.h,v 1.8 1997/09/07 05:25:58 bde Exp $  */
end_comment

begin_define
define|#
directive|define
name|_PATH_KERNFS
value|"/kern"
end_define

begin_comment
comment|/* Default mountpoint */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_struct
struct|struct
name|kernfs_mount
block|{
name|struct
name|vnode
modifier|*
name|kf_root
decl_stmt|;
comment|/* Root node */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|kernfs_node
block|{
name|struct
name|kern_target
modifier|*
name|kf_kt
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|VFSTOKERNFS
parameter_list|(
name|mp
parameter_list|)
value|((struct kernfs_mount *)((mp)->mnt_data))
end_define

begin_define
define|#
directive|define
name|VTOKERN
parameter_list|(
name|vp
parameter_list|)
value|((struct kernfs_node *)(vp)->v_data)
end_define

begin_define
define|#
directive|define
name|kernfs_fhtovp
value|((int (*) __P((struct mount *, struct fid *, \ 	    struct sockaddr *, struct vnode **, int *, struct ucred **)))eopnotsupp)
end_define

begin_define
define|#
directive|define
name|kernfs_quotactl
value|((int (*) __P((struct mount *, int, uid_t, caddr_t, \ 	    struct proc *)))eopnotsupp)
end_define

begin_define
define|#
directive|define
name|kernfs_sync
value|((int (*) __P((struct mount *, int, struct ucred *, \ 	    struct proc *)))nullop)
end_define

begin_define
define|#
directive|define
name|kernfs_sysctl
value|((int (*) __P((int *, u_int, void *, size_t *, void *, \ 	    size_t, struct proc *)))eopnotsupp)
end_define

begin_define
define|#
directive|define
name|kernfs_vget
value|((int (*) __P((struct mount *, ino_t, struct vnode **))) \ 	    eopnotsupp)
end_define

begin_define
define|#
directive|define
name|kernfs_vrele
value|((int (*) __P((struct mount *, struct vnode *))) \ 	    eopnotsupp)
end_define

begin_define
define|#
directive|define
name|kernfs_vptofh
value|((int (*) __P((struct vnode *, struct fid *)))eopnotsupp)
end_define

begin_decl_stmt
specifier|extern
name|vop_t
modifier|*
modifier|*
name|kernfs_vnodeop_p
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|dev_t
name|rrootdev
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

end_unit

