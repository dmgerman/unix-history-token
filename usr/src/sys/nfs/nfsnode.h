begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Rick Macklem at The University of Guelph.  *  * %sccs.include.redist.c%  *  *	@(#)nfsnode.h	8.4 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Silly rename structure that hangs off the nfsnode until the name  * can be removed by nfs_inactive()  */
end_comment

begin_struct
struct|struct
name|sillyrename
block|{
name|struct
name|ucred
modifier|*
name|s_cred
decl_stmt|;
name|struct
name|vnode
modifier|*
name|s_dvp
decl_stmt|;
name|long
name|s_namlen
decl_stmt|;
name|char
name|s_name
index|[
literal|20
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The nfsnode is the nfs equivalent to ufs's inode. Any similarity  * is purely coincidental.  * There is a unique nfsnode allocated for each active file,  * each current directory, each mounted-on file, text file, and the root.  * An nfsnode is 'named' by its file handle. (nget/nfs_node.c)  */
end_comment

begin_struct
struct|struct
name|nfsnode
block|{
name|struct
name|nfsnode
modifier|*
name|n_forw
decl_stmt|;
comment|/* hash, forward */
name|struct
name|nfsnode
modifier|*
modifier|*
name|n_back
decl_stmt|;
comment|/* hash, backward */
name|nfsv2fh_t
name|n_fh
decl_stmt|;
comment|/* NFS File Handle */
name|long
name|n_flag
decl_stmt|;
comment|/* Flag for locking.. */
name|struct
name|vnode
modifier|*
name|n_vnode
decl_stmt|;
comment|/* vnode associated with this node */
name|struct
name|vattr
name|n_vattr
decl_stmt|;
comment|/* Vnode attribute cache */
name|time_t
name|n_attrstamp
decl_stmt|;
comment|/* Time stamp for cached attributes */
name|struct
name|sillyrename
modifier|*
name|n_sillyrename
decl_stmt|;
comment|/* Ptr to silly rename struct */
name|u_quad_t
name|n_size
decl_stmt|;
comment|/* Current size of file */
name|int
name|n_error
decl_stmt|;
comment|/* Save write error value */
name|u_long
name|n_direofoffset
decl_stmt|;
comment|/* Dir. EOF offset cache */
name|time_t
name|n_mtime
decl_stmt|;
comment|/* Prev modify time. */
name|time_t
name|n_ctime
decl_stmt|;
comment|/* Prev create time. */
name|u_quad_t
name|n_brev
decl_stmt|;
comment|/* Modify rev when cached */
name|u_quad_t
name|n_lrev
decl_stmt|;
comment|/* Modify rev for lease */
name|time_t
name|n_expiry
decl_stmt|;
comment|/* Lease expiry time */
name|struct
name|nfsnode
modifier|*
name|n_tnext
decl_stmt|;
comment|/* Nqnfs timer chain */
name|struct
name|nfsnode
modifier|*
name|n_tprev
decl_stmt|;
name|long
name|spare1
decl_stmt|;
comment|/* To 8 byte boundary */
name|struct
name|sillyrename
name|n_silly
decl_stmt|;
comment|/* Silly rename struct */
name|struct
name|timeval
name|n_atim
decl_stmt|;
comment|/* Special file times */
name|struct
name|timeval
name|n_mtim
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Flags for n_flag  */
end_comment

begin_define
define|#
directive|define
name|NFLUSHWANT
value|0x0001
end_define

begin_comment
comment|/* Want wakeup from a flush in prog. */
end_comment

begin_define
define|#
directive|define
name|NFLUSHINPROG
value|0x0002
end_define

begin_comment
comment|/* Avoid multiple calls to vinvalbuf() */
end_comment

begin_define
define|#
directive|define
name|NMODIFIED
value|0x0004
end_define

begin_comment
comment|/* Might have a modified buffer in bio */
end_comment

begin_define
define|#
directive|define
name|NWRITEERR
value|0x0008
end_define

begin_comment
comment|/* Flag write errors so close will know */
end_comment

begin_define
define|#
directive|define
name|NQNFSNONCACHE
value|0x0020
end_define

begin_comment
comment|/* Non-cachable lease */
end_comment

begin_define
define|#
directive|define
name|NQNFSWRITE
value|0x0040
end_define

begin_comment
comment|/* Write lease */
end_comment

begin_define
define|#
directive|define
name|NQNFSEVICTED
value|0x0080
end_define

begin_comment
comment|/* Has been evicted */
end_comment

begin_define
define|#
directive|define
name|NACC
value|0x0100
end_define

begin_comment
comment|/* Special file accessed */
end_comment

begin_define
define|#
directive|define
name|NUPD
value|0x0200
end_define

begin_comment
comment|/* Special file updated */
end_comment

begin_define
define|#
directive|define
name|NCHG
value|0x0400
end_define

begin_comment
comment|/* Special file times changed */
end_comment

begin_comment
comment|/*  * Convert between nfsnode pointers and vnode pointers  */
end_comment

begin_define
define|#
directive|define
name|VTONFS
parameter_list|(
name|vp
parameter_list|)
value|((struct nfsnode *)(vp)->v_data)
end_define

begin_define
define|#
directive|define
name|NFSTOV
parameter_list|(
name|np
parameter_list|)
value|((struct vnode *)(np)->n_vnode)
end_define

begin_comment
comment|/*  * Queue head for nfsiod's  */
end_comment

begin_macro
name|TAILQ_HEAD
argument_list|(
argument|nfsbufs
argument_list|,
argument|buf
argument_list|)
end_macro

begin_expr_stmt
name|nfs_bufq
expr_stmt|;
end_expr_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_comment
comment|/*  * Prototypes for NFS vnode operations  */
end_comment

begin_decl_stmt
name|int
name|nfs_lookup
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

begin_decl_stmt
name|int
name|nfs_create
name|__P
argument_list|(
operator|(
expr|struct
name|vop_create_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nfs_mknod
name|__P
argument_list|(
operator|(
expr|struct
name|vop_mknod_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nfs_open
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
name|nfs_close
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
name|nfsspec_close
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

begin_ifdef
ifdef|#
directive|ifdef
name|FIFO
end_ifdef

begin_decl_stmt
name|int
name|nfsfifo_close
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

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|int
name|nfs_access
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
name|nfsspec_access
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
name|nfs_getattr
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
name|nfs_setattr
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

begin_decl_stmt
name|int
name|nfs_read
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
name|nfs_write
name|__P
argument_list|(
operator|(
expr|struct
name|vop_write_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nfsspec_read
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
name|nfsspec_write
name|__P
argument_list|(
operator|(
expr|struct
name|vop_write_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|FIFO
end_ifdef

begin_decl_stmt
name|int
name|nfsfifo_read
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
name|nfsfifo_write
name|__P
argument_list|(
operator|(
expr|struct
name|vop_write_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|nfs_ioctl
value|((int (*) __P((struct  vop_ioctl_args *)))enoioctl)
end_define

begin_define
define|#
directive|define
name|nfs_select
value|((int (*) __P((struct  vop_select_args *)))seltrue)
end_define

begin_decl_stmt
name|int
name|nfs_mmap
name|__P
argument_list|(
operator|(
expr|struct
name|vop_mmap_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nfs_fsync
name|__P
argument_list|(
operator|(
expr|struct
name|vop_fsync_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|nfs_seek
value|((int (*) __P((struct  vop_seek_args *)))nullop)
end_define

begin_decl_stmt
name|int
name|nfs_remove
name|__P
argument_list|(
operator|(
expr|struct
name|vop_remove_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nfs_link
name|__P
argument_list|(
operator|(
expr|struct
name|vop_link_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nfs_rename
name|__P
argument_list|(
operator|(
expr|struct
name|vop_rename_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nfs_mkdir
name|__P
argument_list|(
operator|(
expr|struct
name|vop_mkdir_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nfs_rmdir
name|__P
argument_list|(
operator|(
expr|struct
name|vop_rmdir_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nfs_symlink
name|__P
argument_list|(
operator|(
expr|struct
name|vop_symlink_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nfs_readdir
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
name|nfs_readlink
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
name|nfs_abortop
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
name|nfs_inactive
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
name|nfs_reclaim
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

begin_decl_stmt
name|int
name|nfs_lock
name|__P
argument_list|(
operator|(
expr|struct
name|vop_lock_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nfs_unlock
name|__P
argument_list|(
operator|(
expr|struct
name|vop_unlock_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nfs_bmap
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

begin_decl_stmt
name|int
name|nfs_strategy
name|__P
argument_list|(
operator|(
expr|struct
name|vop_strategy_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nfs_print
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

begin_decl_stmt
name|int
name|nfs_islocked
name|__P
argument_list|(
operator|(
expr|struct
name|vop_islocked_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nfs_pathconf
name|__P
argument_list|(
operator|(
expr|struct
name|vop_pathconf_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nfs_advlock
name|__P
argument_list|(
operator|(
expr|struct
name|vop_advlock_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nfs_blkatoff
name|__P
argument_list|(
operator|(
expr|struct
name|vop_blkatoff_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nfs_vget
name|__P
argument_list|(
operator|(
expr|struct
name|mount
operator|*
operator|,
name|ino_t
operator|,
expr|struct
name|vnode
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nfs_valloc
name|__P
argument_list|(
operator|(
expr|struct
name|vop_valloc_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|nfs_reallocblks
define|\
value|((int (*) __P((struct  vop_reallocblks_args *)))eopnotsupp)
end_define

begin_decl_stmt
name|int
name|nfs_vfree
name|__P
argument_list|(
operator|(
expr|struct
name|vop_vfree_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nfs_truncate
name|__P
argument_list|(
operator|(
expr|struct
name|vop_truncate_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nfs_update
name|__P
argument_list|(
operator|(
expr|struct
name|vop_update_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nfs_bwrite
name|__P
argument_list|(
operator|(
expr|struct
name|vop_bwrite_args
operator|*
operator|)
argument_list|)
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

