begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1993 Jan-Simon Pendry  * Copyright (c) 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Jan-Simon Pendry.  *  * %sccs.include.redist.c%  *  *	@(#)procfs.h	8.9 (Berkeley) %G%  *  * From:  *	$Id: procfs.h,v 3.2 1993/12/15 09:40:17 jsp Exp $  */
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
name|Pcurproc
block|,
comment|/* symbolic link for curproc */
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
value|(((type)< Pproc) ? \ 			((type) + 2) : \ 			((((pid)+1)<< 4) + ((int) (type))))
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
name|int
name|procfs_sstep
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
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

begin_comment
comment|/* functions to check whether or not files should be displayed */
end_comment

begin_decl_stmt
name|int
name|procfs_validfile
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
name|int
name|procfs_validfpregs
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
name|int
name|procfs_validregs
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
name|procfs_revoke
value|vop_revoke
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

begin_decl_stmt
name|int
name|procfs_readlink
name|__P
argument_list|(
operator|(
expr|struct
name|vop_readlink_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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
value|((int (*) __P((struct  vop_lock_args *)))vop_nolock)
end_define

begin_define
define|#
directive|define
name|procfs_unlock
value|((int (*) __P((struct  vop_unlock_args *)))vop_nounlock)
end_define

begin_decl_stmt
name|int
name|procfs_bmap
name|__P
argument_list|(
operator|(
expr|struct
name|vop_bmap_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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
define|\
value|((int (*) __P((struct vop_islocked_args *)))vop_noislocked)
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

