begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1993 Jan-Simon Pendry  * Copyright (c) 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Jan-Simon Pendry.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)procfs.h	8.6 (Berkeley) 2/3/94  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * The different types of node in a procfs filesystem  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|Proot
block|,
comment|/* the filesystem root */
name|Pproc
block|,
comment|/* a process-specific sub-directory */
name|Pfile
block|,
comment|/* the executable file */
name|Pmem
block|,
comment|/* the process's memory image */
name|Pregs
block|,
comment|/* the process's register set */
name|Pfpregs
block|,
comment|/* the process's FP register set */
name|Pctl
block|,
comment|/* process control */
name|Pstatus
block|,
comment|/* process status */
name|Pnote
block|,
comment|/* process notifier */
name|Pnotepg
comment|/* process group notifier */
block|}
name|pfstype
typedef|;
end_typedef

begin_comment
comment|/*  * control data for the proc file system.  */
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
name|pfstype
name|pfs_type
decl_stmt|;
comment|/* type of procfs node */
name|pid_t
name|pfs_pid
decl_stmt|;
comment|/* associated process */
name|u_short
name|pfs_mode
decl_stmt|;
comment|/* mode bits for stat() */
name|u_long
name|pfs_flags
decl_stmt|;
comment|/* open flags */
name|u_long
name|pfs_fileno
decl_stmt|;
comment|/* unique file id */
name|pid_t
name|pfs_lockowner
decl_stmt|;
comment|/* pfs lock owner */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PROCFS_NOTELEN
value|64
end_define

begin_comment
comment|/* max length of a note (/proc/$pid/note) */
end_comment

begin_define
define|#
directive|define
name|PROCFS_CTLLEN
value|8
end_define

begin_comment
comment|/* max length of a ctl msg (/proc/$pid/ctl */
end_comment

begin_comment
comment|/*  * Kernel stuff follows  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_define
define|#
directive|define
name|CNEQ
parameter_list|(
name|cnp
parameter_list|,
name|s
parameter_list|,
name|len
parameter_list|)
define|\
value|((cnp)->cn_namelen == (len)&& \ 	  (bcmp((s), (cnp)->cn_nameptr, (len)) == 0))
end_define

begin_define
define|#
directive|define
name|KMEM_GROUP
value|2
end_define

begin_comment
comment|/*  * Check to see whether access to target process is allowed  * Evaluates to 1 if access is allowed.  */
end_comment

begin_define
define|#
directive|define
name|CHECKIO
parameter_list|(
name|p1
parameter_list|,
name|p2
parameter_list|)
define|\
value|((((p1)->p_cred->pc_ucred->cr_uid == (p2)->p_cred->p_ruid)&& \        ((p1)->p_cred->p_ruid == (p2)->p_cred->p_ruid)&& \        ((p1)->p_cred->p_svuid == (p2)->p_cred->p_ruid)&& \        ((p2)->p_flag& P_SUGID) == 0) || \       (suser((p1)->p_cred->pc_ucred,&(p1)->p_acflag) == 0))
end_define

begin_comment
comment|/*  * Format of a directory entry in /proc, ...  * This must map onto struct dirent (see<dirent.h>)  */
end_comment

begin_define
define|#
directive|define
name|PROCFS_NAMELEN
value|8
end_define

begin_struct
struct|struct
name|pfsdent
block|{
name|u_long
name|d_fileno
decl_stmt|;
name|u_short
name|d_reclen
decl_stmt|;
name|u_char
name|d_type
decl_stmt|;
name|u_char
name|d_namlen
decl_stmt|;
name|char
name|d_name
index|[
name|PROCFS_NAMELEN
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|UIO_MX
value|sizeof(struct pfsdent)
end_define

begin_define
define|#
directive|define
name|PROCFS_FILENO
parameter_list|(
name|pid
parameter_list|,
name|type
parameter_list|)
define|\
value|(((type) == Proot) ? \ 			2 : \ 			((((pid)+1)<< 3) + ((int) (type))))
end_define

begin_comment
comment|/*  * Convert between pfsnode vnode  */
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
name|pfs
parameter_list|)
value|((pfs)->pfs_vnode)
end_define

begin_typedef
typedef|typedef
name|struct
name|vfs_namemap
name|vfs_namemap_t
typedef|;
end_typedef

begin_struct
struct|struct
name|vfs_namemap
block|{
specifier|const
name|char
modifier|*
name|nm_name
decl_stmt|;
name|int
name|nm_val
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|int
name|vfs_getuserstr
name|__P
argument_list|(
operator|(
expr|struct
name|uio
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|vfs_namemap_t
modifier|*
name|vfs_findname
name|__P
argument_list|(
operator|(
name|vfs_namemap_t
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*<machine/reg.h> */
end_comment

begin_struct_decl
struct_decl|struct
name|reg
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|fpreg
struct_decl|;
end_struct_decl

begin_define
define|#
directive|define
name|PFIND
parameter_list|(
name|pid
parameter_list|)
value|((pid) ? pfind(pid) :&proc0)
end_define

begin_decl_stmt
specifier|extern
name|int
name|procfs_freevp
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|procfs_allocvp
name|__P
argument_list|(
operator|(
expr|struct
name|mount
operator|*
operator|,
expr|struct
name|vnode
operator|*
operator|*
operator|,
name|long
operator|,
name|pfstype
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|vnode
modifier|*
name|procfs_findtextvp
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|procfs_sstep
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|procfs_fix_sstep
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|procfs_read_regs
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
operator|,
expr|struct
name|reg
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|procfs_write_regs
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
operator|,
expr|struct
name|reg
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|procfs_read_fpregs
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
operator|,
expr|struct
name|fpreg
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|procfs_write_fpregs
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
operator|,
expr|struct
name|fpreg
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|procfs_donote
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
operator|,
expr|struct
name|proc
operator|*
operator|,
expr|struct
name|pfsnode
operator|*
name|pfsp
operator|,
expr|struct
name|uio
operator|*
name|uio
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|procfs_doregs
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
operator|,
expr|struct
name|proc
operator|*
operator|,
expr|struct
name|pfsnode
operator|*
name|pfsp
operator|,
expr|struct
name|uio
operator|*
name|uio
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|procfs_dofpregs
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
operator|,
expr|struct
name|proc
operator|*
operator|,
expr|struct
name|pfsnode
operator|*
name|pfsp
operator|,
expr|struct
name|uio
operator|*
name|uio
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|procfs_domem
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
operator|,
expr|struct
name|proc
operator|*
operator|,
expr|struct
name|pfsnode
operator|*
name|pfsp
operator|,
expr|struct
name|uio
operator|*
name|uio
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|procfs_doctl
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
operator|,
expr|struct
name|proc
operator|*
operator|,
expr|struct
name|pfsnode
operator|*
name|pfsp
operator|,
expr|struct
name|uio
operator|*
name|uio
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|procfs_dostatus
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
operator|,
expr|struct
name|proc
operator|*
operator|,
expr|struct
name|pfsnode
operator|*
name|pfsp
operator|,
expr|struct
name|uio
operator|*
name|uio
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|PROCFS_LOCKED
value|0x01
end_define

begin_define
define|#
directive|define
name|PROCFS_WANT
value|0x02
end_define

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
modifier|*
name|procfs_vnodeop_p
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|struct
name|vfsops
name|procfs_vfsops
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|procfs_root
name|__P
argument_list|(
operator|(
expr|struct
name|mount
operator|*
operator|,
expr|struct
name|vnode
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Prototypes for procfs vnode ops  */
end_comment

begin_function_decl
name|int
name|procfs_badop
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* varargs */
end_comment

begin_decl_stmt
name|int
name|procfs_rw
name|__P
argument_list|(
operator|(
expr|struct
name|vop_read_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|procfs_lookup
name|__P
argument_list|(
operator|(
expr|struct
name|vop_lookup_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|procfs_create
value|((int (*) __P((struct vop_create_args *))) procfs_badop)
end_define

begin_define
define|#
directive|define
name|procfs_mknod
value|((int (*) __P((struct vop_mknod_args *))) procfs_badop)
end_define

begin_decl_stmt
name|int
name|procfs_open
name|__P
argument_list|(
operator|(
expr|struct
name|vop_open_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|procfs_close
name|__P
argument_list|(
operator|(
expr|struct
name|vop_close_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|procfs_access
name|__P
argument_list|(
operator|(
expr|struct
name|vop_access_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|procfs_getattr
name|__P
argument_list|(
operator|(
expr|struct
name|vop_getattr_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|procfs_setattr
name|__P
argument_list|(
operator|(
expr|struct
name|vop_setattr_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|procfs_read
value|procfs_rw
end_define

begin_define
define|#
directive|define
name|procfs_write
value|procfs_rw
end_define

begin_decl_stmt
name|int
name|procfs_ioctl
name|__P
argument_list|(
operator|(
expr|struct
name|vop_ioctl_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|procfs_select
value|((int (*) __P((struct vop_select_args *))) procfs_badop)
end_define

begin_define
define|#
directive|define
name|procfs_mmap
value|((int (*) __P((struct vop_mmap_args *))) procfs_badop)
end_define

begin_define
define|#
directive|define
name|procfs_fsync
value|((int (*) __P((struct vop_fsync_args *))) procfs_badop)
end_define

begin_define
define|#
directive|define
name|procfs_seek
value|((int (*) __P((struct vop_seek_args *))) procfs_badop)
end_define

begin_define
define|#
directive|define
name|procfs_remove
value|((int (*) __P((struct vop_remove_args *))) procfs_badop)
end_define

begin_define
define|#
directive|define
name|procfs_link
value|((int (*) __P((struct vop_link_args *))) procfs_badop)
end_define

begin_define
define|#
directive|define
name|procfs_rename
value|((int (*) __P((struct vop_rename_args *))) procfs_badop)
end_define

begin_define
define|#
directive|define
name|procfs_mkdir
value|((int (*) __P((struct vop_mkdir_args *))) procfs_badop)
end_define

begin_define
define|#
directive|define
name|procfs_rmdir
value|((int (*) __P((struct vop_rmdir_args *))) procfs_badop)
end_define

begin_define
define|#
directive|define
name|procfs_symlink
value|((int (*) __P((struct vop_symlink_args *))) procfs_badop)
end_define

begin_decl_stmt
name|int
name|procfs_readdir
name|__P
argument_list|(
operator|(
expr|struct
name|vop_readdir_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|procfs_readlink
value|((int (*) __P((struct vop_readlink_args *))) procfs_badop)
end_define

begin_decl_stmt
name|int
name|procfs_abortop
name|__P
argument_list|(
operator|(
expr|struct
name|vop_abortop_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|procfs_inactive
name|__P
argument_list|(
operator|(
expr|struct
name|vop_inactive_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|procfs_reclaim
name|__P
argument_list|(
operator|(
expr|struct
name|vop_reclaim_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|procfs_lock
value|((int (*) __P((struct vop_lock_args *))) nullop)
end_define

begin_define
define|#
directive|define
name|procfs_unlock
value|((int (*) __P((struct vop_unlock_args *))) nullop)
end_define

begin_define
define|#
directive|define
name|procfs_bmap
value|((int (*) __P((struct vop_bmap_args *))) procfs_badop)
end_define

begin_define
define|#
directive|define
name|procfs_strategy
value|((int (*) __P((struct vop_strategy_args *))) procfs_badop)
end_define

begin_decl_stmt
name|int
name|procfs_print
name|__P
argument_list|(
operator|(
expr|struct
name|vop_print_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|procfs_islocked
value|((int (*) __P((struct vop_islocked_args *))) nullop)
end_define

begin_define
define|#
directive|define
name|procfs_advlock
value|((int (*) __P((struct vop_advlock_args *))) procfs_badop)
end_define

begin_define
define|#
directive|define
name|procfs_blkatoff
value|((int (*) __P((struct vop_blkatoff_args *))) procfs_badop)
end_define

begin_define
define|#
directive|define
name|procfs_valloc
value|((int (*) __P((struct vop_valloc_args *))) procfs_badop)
end_define

begin_define
define|#
directive|define
name|procfs_vfree
value|((int (*) __P((struct vop_vfree_args *))) nullop)
end_define

begin_define
define|#
directive|define
name|procfs_truncate
value|((int (*) __P((struct vop_truncate_args *))) procfs_badop)
end_define

begin_define
define|#
directive|define
name|procfs_update
value|((int (*) __P((struct vop_update_args *))) nullop)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

end_unit

