begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1993 Paul Kranenburg  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Paul Kranenburg.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software withough specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  *	$Id: pfsnode.h,v 1.6 1993/09/07 15:41:24 ws Exp $  */
end_comment

begin_comment
comment|/*  * This structure defines the control data for the proc file system.  */
end_comment

begin_struct
struct|struct
name|pfsnode
block|{
name|struct
name|pfsnode
modifier|*
name|pfs_next
decl_stmt|;
comment|/* next on list */
name|struct
name|vnode
modifier|*
name|pfs_vnode
decl_stmt|;
comment|/* vnode associated with this pfsnode */
name|pid_t
name|pfs_pid
decl_stmt|;
comment|/* associated process */
name|u_short
name|pfs_mode
decl_stmt|;
comment|/* mode bits for stat() */
name|uid_t
name|pfs_uid
decl_stmt|;
comment|/* process' owner */
name|gid_t
name|pfs_gid
decl_stmt|;
comment|/* process' group */
name|u_long
name|pfs_vflags
decl_stmt|;
comment|/* chflags() flags */
name|u_long
name|pfs_flags
decl_stmt|;
comment|/* open flags */
name|struct
name|vmspace
modifier|*
name|pfs_vs
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|pfsnode
modifier|*
name|pfshead
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Format of a directory entry in /proc  */
end_comment

begin_struct
struct|struct
name|pfsdent
block|{
name|unsigned
name|long
name|d_fileno
decl_stmt|;
name|unsigned
name|short
name|d_reclen
decl_stmt|;
name|unsigned
name|short
name|d_namlen
decl_stmt|;
name|char
name|d_nam
index|[
literal|8
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PFSDENTSIZE
value|(sizeof(struct direct) - MAXNAMELEN + 8)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|DIRBLKSIZ
end_ifndef

begin_define
define|#
directive|define
name|DIRBLKSIZ
value|DEV_BSIZE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_decl_stmt
name|int
name|pfs_debug
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Convert between pfsnode pointers and vnode pointers  */
end_comment

begin_define
define|#
directive|define
name|VTOPFS
parameter_list|(
name|vp
parameter_list|)
value|((struct pfsnode *)(vp)->v_data)
end_define

begin_define
define|#
directive|define
name|PFSTOV
parameter_list|(
name|pfsp
parameter_list|)
value|((pfsp)->pfs_vnode)
end_define

begin_comment
comment|/*  * Prototypes for PFS operations on vnodes.  */
end_comment

begin_function_decl
name|int
name|pfs_badop
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pfs_doio
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|int
name|pfs_lookup
name|__P
argument_list|(
operator|(
expr|\ 		struct
name|vnode
operator|*
name|vp
operator|,
expr|\ 		struct
name|nameidata
operator|*
name|ndp
operator|,
expr|\ 		struct
name|proc
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|pfs_create
value|((int (*) __P(( \ 		struct nameidata *ndp, \ 		struct vattr *vap, \ 		struct proc *p))) pfs_badop)
end_define

begin_define
define|#
directive|define
name|pfs_mknod
value|((int (*) __P(( \ 		struct nameidata *ndp, \ 		struct vattr *vap, \ 		struct ucred *cred, \ 		struct proc *p))) pfs_badop)
end_define

begin_decl_stmt
name|int
name|pfs_open
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|,
name|int
name|mode
operator|,
expr|struct
name|ucred
operator|*
name|cred
operator|,
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pfs_close
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|,
name|int
name|fflag
operator|,
expr|struct
name|ucred
operator|*
name|cred
operator|,
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pfs_access
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|,
name|int
name|mode
operator|,
expr|struct
name|ucred
operator|*
name|cred
operator|,
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pfs_getattr
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|,
expr|struct
name|vattr
operator|*
name|vap
operator|,
expr|struct
name|ucred
operator|*
name|cred
operator|,
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pfs_setattr
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|,
expr|struct
name|vattr
operator|*
name|vap
operator|,
expr|struct
name|ucred
operator|*
name|cred
operator|,
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|pfs_read
value|((int (*)  __P(( \ 		struct vnode *vp, \ 		struct uio *uio, \ 		int ioflag, \ 		struct ucred *cred))) pfs_doio)
end_define

begin_define
define|#
directive|define
name|pfs_write
value|((int (*) __P(( \ 		struct vnode *vp, \ 		struct uio *uio, \ 		int ioflag, \ 		struct ucred *cred))) pfs_doio)
end_define

begin_decl_stmt
name|int
name|pfs_ioctl
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|,
name|int
name|command
operator|,
name|caddr_t
name|data
operator|,
name|int
name|fflag
operator|,
expr|struct
name|ucred
operator|*
name|cred
operator|,
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|pfs_select
value|((int (*) __P(( \ 		struct vnode *vp, \ 		int which, \ 		int fflags, \ 		struct ucred *cred, \ 		struct proc *p))) pfs_badop)
end_define

begin_define
define|#
directive|define
name|pfs_mmap
value|((int (*) __P(( \ 		struct vnode *vp, \ 		int fflags, \ 		struct ucred *cred, \ 		struct proc *p))) pfs_badop)
end_define

begin_define
define|#
directive|define
name|pfs_fsync
value|((int (*) __P(( \ 		struct vnode *vp, \ 		int fflags, \ 		struct ucred *cred, \ 		int waitfor, \ 		struct proc *p))) pfs_badop)
end_define

begin_define
define|#
directive|define
name|pfs_seek
value|((int (*) __P(( \ 		struct vnode *vp, \ 		off_t oldoff, \ 		off_t newoff, \ 		struct ucred *cred))) pfs_badop)
end_define

begin_define
define|#
directive|define
name|pfs_remove
value|((int (*) __P(( \ 		struct nameidata *ndp, \ 		struct proc *p))) pfs_badop)
end_define

begin_define
define|#
directive|define
name|pfs_link
value|((int (*) __P(( \ 		struct vnode *vp, \ 		struct nameidata *ndp, \ 		struct proc *p))) pfs_badop)
end_define

begin_define
define|#
directive|define
name|pfs_rename
value|((int (*) __P(( \ 		struct nameidata *fndp, \ 		struct nameidata *tdnp, \ 		struct proc *p))) pfs_badop)
end_define

begin_define
define|#
directive|define
name|pfs_mkdir
value|((int (*) __P(( \ 		struct nameidata *ndp, \ 		struct vattr *vap, \ 		struct proc *p))) pfs_badop)
end_define

begin_define
define|#
directive|define
name|pfs_rmdir
value|((int (*) __P(( \ 		struct nameidata *ndp, \ 		struct proc *p))) pfs_badop)
end_define

begin_define
define|#
directive|define
name|pfs_symlink
value|((int (*) __P(( \ 		struct nameidata *ndp, \ 		struct vattr *vap, \ 		char *target, \ 		struct proc *p))) pfs_badop)
end_define

begin_decl_stmt
name|int
name|pfs_readdir
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|,
expr|struct
name|uio
operator|*
name|uio
operator|,
expr|struct
name|ucred
operator|*
name|cred
operator|,
name|int
operator|*
name|eofflagp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|pfs_readlink
value|((int (*) __P(( \ 		struct vnode *vp, \ 		struct uio *uio, \ 		struct ucred *cred))) pfs_badop)
end_define

begin_define
define|#
directive|define
name|pfs_abortop
value|((int (*) __P(( \ 		struct nameidata *ndp))) pfs_badop)
end_define

begin_decl_stmt
name|int
name|pfs_inactive
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|,
expr|struct
name|proc
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pfs_reclaim
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|pfs_lock
value|((int (*) __P(( \ 		struct vnode *vp))) nullop)
end_define

begin_define
define|#
directive|define
name|pfs_unlock
value|((int (*) __P(( \ 		struct vnode *vp))) nullop)
end_define

begin_decl_stmt
name|int
name|pfs_bmap
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|,
name|daddr_t
name|bn
operator|,
expr|struct
name|vnode
operator|*
operator|*
name|vpp
operator|,
name|daddr_t
operator|*
name|bnp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pfs_strategy
name|__P
argument_list|(
operator|(
expr|struct
name|buf
operator|*
name|bp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|pfs_print
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|pfs_islocked
value|((int (*) __P(( \ 		struct vnode *vp))) nullop)
end_define

begin_define
define|#
directive|define
name|pfs_advlock
value|((int (*) __P(( \ 		struct vnode *vp, \ 		caddr_t id, \ 		int op, \ 		struct flock *fl, \ 		int flags))) pfs_badop)
end_define

end_unit

