begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)specdev.h	7.7 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * This structure defines the information maintained about  * special devices. It is allocated in checkalias and freed  * in vgone.  */
end_comment

begin_struct
struct|struct
name|specinfo
block|{
name|struct
name|vnode
modifier|*
modifier|*
name|si_hashchain
decl_stmt|;
name|struct
name|vnode
modifier|*
name|si_specnext
decl_stmt|;
name|long
name|si_flags
decl_stmt|;
name|dev_t
name|si_rdev
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Exported shorthand  */
end_comment

begin_define
define|#
directive|define
name|v_rdev
value|v_specinfo->si_rdev
end_define

begin_define
define|#
directive|define
name|v_hashchain
value|v_specinfo->si_hashchain
end_define

begin_define
define|#
directive|define
name|v_specnext
value|v_specinfo->si_specnext
end_define

begin_define
define|#
directive|define
name|v_specflags
value|v_specinfo->si_flags
end_define

begin_comment
comment|/*  * Flags for specinfo  */
end_comment

begin_define
define|#
directive|define
name|SI_MOUNTEDON
value|0x0001
end_define

begin_comment
comment|/* block special device is mounted on */
end_comment

begin_comment
comment|/*  * Special device management  */
end_comment

begin_define
define|#
directive|define
name|SPECHSZ
value|64
end_define

begin_if
if|#
directive|if
operator|(
operator|(
name|SPECHSZ
operator|&
operator|(
name|SPECHSZ
operator|-
literal|1
operator|)
operator|)
operator|==
literal|0
operator|)
end_if

begin_define
define|#
directive|define
name|SPECHASH
parameter_list|(
name|rdev
parameter_list|)
value|(((rdev>>5)+(rdev))&(SPECHSZ-1))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SPECHASH
parameter_list|(
name|rdev
parameter_list|)
value|(((unsigned)((rdev>>5)+(rdev)))%SPECHSZ)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|struct
name|vnode
modifier|*
name|speclisth
index|[
name|SPECHSZ
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Prototypes for special file operations on vnodes.  */
end_comment

begin_struct_decl
struct_decl|struct
name|nameidata
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|componentname
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ucred
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|flock
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|buf
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|uio
struct_decl|;
end_struct_decl

begin_decl_stmt
name|int
name|spec_badop
argument_list|()
decl_stmt|,
name|spec_ebadf
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|spec_lookup
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|dvp
operator|,
expr|struct
name|vnode
operator|*
operator|*
name|vpp
operator|,
expr|struct
name|componentname
operator|*
name|cnp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|spec_create
value|((int (*) __P(( \ 		struct vnode *dvp, \  		struct vnode **vpp, \ 		struct componentname *cnp, \ 		struct vattr *vap))) spec_badop)
end_define

begin_define
define|#
directive|define
name|spec_mknod
value|((int (*) __P(( \ 		struct vnode *dvp, \ 		struct vnode **vpp, \ 		struct componentname *cnp, \ 		struct vattr *vap))) spec_badop)
end_define

begin_decl_stmt
name|int
name|spec_open
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
name|spec_close
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

begin_define
define|#
directive|define
name|spec_access
value|((int (*) __P(( \ 		struct vnode *vp, \ 		int mode, \ 		struct ucred *cred, \ 		struct proc *p))) spec_ebadf)
end_define

begin_define
define|#
directive|define
name|spec_getattr
value|((int (*) __P(( \ 		struct vnode *vp, \ 		struct vattr *vap, \ 		struct ucred *cred, \ 		struct proc *p))) spec_ebadf)
end_define

begin_define
define|#
directive|define
name|spec_setattr
value|((int (*) __P(( \ 		struct vnode *vp, \ 		struct vattr *vap, \ 		struct ucred *cred, \ 		struct proc *p))) spec_ebadf)
end_define

begin_decl_stmt
name|int
name|spec_read
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
name|int
name|ioflag
operator|,
expr|struct
name|ucred
operator|*
name|cred
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|spec_write
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
name|int
name|ioflag
operator|,
expr|struct
name|ucred
operator|*
name|cred
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|spec_ioctl
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

begin_decl_stmt
name|int
name|spec_select
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|,
name|int
name|which
operator|,
name|int
name|fflags
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
name|spec_mmap
value|((int (*) __P(( \ 		struct vnode *vp, \ 		int fflags, \ 		struct ucred *cred, \ 		struct proc *p))) spec_badop)
end_define

begin_define
define|#
directive|define
name|spec_fsync
value|((int (*) __P(( \ 		struct vnode *vp, \ 		int fflags, \ 		struct ucred *cred, \ 		int waitfor, \ 		struct proc *p))) nullop)
end_define

begin_define
define|#
directive|define
name|spec_seek
value|((int (*) __P(( \ 		struct vnode *vp, \ 		off_t oldoff, \ 		off_t newoff, \ 		struct ucred *cred))) spec_badop)
end_define

begin_define
define|#
directive|define
name|spec_remove
value|((int (*) __P(( \ 		struct vnode *dvp, \ 	        struct vnode *vp, \ 		struct componentname *cnp))) spec_badop)
end_define

begin_define
define|#
directive|define
name|spec_link
value|((int (*) __P(( \ 		register struct vnode *vp, \ 		struct vnode *tdvp, \ 		struct componentname *cnp))) spec_badop)
end_define

begin_define
define|#
directive|define
name|spec_rename
value|((int (*) __P(( \ 		struct vnode *fdvp, \ 	        struct vnode *fvp, \ 		struct componentname *fcnp, \ 		struct vnode *tdvp, \ 		struct vnode *tvp, \ 		struct componentname *tcnp))) spec_badop)
end_define

begin_define
define|#
directive|define
name|spec_mkdir
value|((int (*) __P(( \ 		struct vnode *dvp, \ 		struct vnode **vpp, \ 		struct componentname *cnp, \ 		struct vattr *vap))) spec_badop)
end_define

begin_define
define|#
directive|define
name|spec_rmdir
value|((int (*) __P(( \ 		struct vnode *dvp, \ 		struct vnode *vp, \ 		struct componentname *cnp))) spec_badop)
end_define

begin_define
define|#
directive|define
name|spec_symlink
value|((int (*) __P(( \ 		struct vnode *dvp, \ 		struct vnode **vpp, \ 		struct componentname *cnp, \ 		struct vattr *vap, \ 		char *target))) spec_badop)
end_define

begin_define
define|#
directive|define
name|spec_readdir
value|((int (*) __P(( \ 		struct vnode *vp, \ 		struct uio *uio, \ 		struct ucred *cred, \ 		int *eofflagp))) spec_badop)
end_define

begin_define
define|#
directive|define
name|spec_readlink
value|((int (*) __P(( \ 		struct vnode *vp, \ 		struct uio *uio, \ 		struct ucred *cred))) spec_badop)
end_define

begin_define
define|#
directive|define
name|spec_abortop
value|((int (*) __P(( \ 		struct vnode *dvp, \ 		struct componentname *cnp))) spec_badop)
end_define

begin_define
define|#
directive|define
name|spec_inactive
value|((int (*) __P(( \ 		struct vnode *vp, \ 		struct proc *p))) nullop)
end_define

begin_define
define|#
directive|define
name|spec_reclaim
value|((int (*) __P(( \ 		struct vnode *vp))) nullop)
end_define

begin_decl_stmt
name|int
name|spec_lock
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

begin_decl_stmt
name|int
name|spec_unlock
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

begin_decl_stmt
name|int
name|spec_bmap
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
name|spec_strategy
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
name|int
name|spec_print
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
name|spec_islocked
value|((int (*) __P(( \ 		struct vnode *vp))) nullop)
end_define

begin_decl_stmt
name|int
name|spec_advlock
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|,
name|caddr_t
name|id
operator|,
name|int
name|op
operator|,
expr|struct
name|flock
operator|*
name|fl
operator|,
name|int
name|flags
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|spec_blkatoff
value|((int (*) __P(( \ 		struct vnode *vp, \ 		off_t offset, \ 		char **res, \ 		struct buf **bpp))) spec_badop)
end_define

begin_define
define|#
directive|define
name|spec_vget
value|((int (*) __P(( \ 		struct mount *mp, \ 		ino_t ino, \ 		struct vnode **vpp))) spec_badop)
end_define

begin_define
define|#
directive|define
name|spec_valloc
value|((int (*) __P(( \ 		struct vnode *pvp, \ 		int mode, \ 		struct ucred *cred, \ 		struct vnode **vpp))) spec_badop)
end_define

begin_define
define|#
directive|define
name|spec_vfree
value|((void (*) __P(( \ 		struct vnode *pvp, \ 		ino_t ino, \ 		int mode))) spec_badop)
end_define

begin_define
define|#
directive|define
name|spec_truncate
value|((int (*) __P(( \ 		struct vnode *vp, \ 		off_t length, \ 		int flags))) nullop)
end_define

begin_define
define|#
directive|define
name|spec_update
value|((int (*) __P(( \ 		struct vnode *vp, \ 		struct timeval *ta, \ 		struct timeval *tm, \ 		int waitfor))) nullop)
end_define

begin_define
define|#
directive|define
name|spec_bwrite
value|((int (*) __P(( \ 		struct buf *bp))) nullop)
end_define

end_unit

