begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Rick Macklem at The University of Guelph.  *  * %sccs.include.redist.c%  *  *	@(#)nfsmount.h	8.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Mount structure.  * One allocated on every NFS mount.  * Holds NFS specific information for mount.  */
end_comment

begin_struct
struct|struct
name|nfsmount
block|{
name|int
name|nm_flag
decl_stmt|;
comment|/* Flags for soft/hard... */
name|struct
name|mount
modifier|*
name|nm_mountp
decl_stmt|;
comment|/* Vfs structure for this filesystem */
name|int
name|nm_numgrps
decl_stmt|;
comment|/* Max. size of groupslist */
name|nfsv2fh_t
name|nm_fh
decl_stmt|;
comment|/* File handle of root dir */
name|struct
name|socket
modifier|*
name|nm_so
decl_stmt|;
comment|/* Rpc socket */
name|int
name|nm_sotype
decl_stmt|;
comment|/* Type of socket */
name|int
name|nm_soproto
decl_stmt|;
comment|/* and protocol */
name|int
name|nm_soflags
decl_stmt|;
comment|/* pr_flags for socket protocol */
name|struct
name|mbuf
modifier|*
name|nm_nam
decl_stmt|;
comment|/* Addr of server */
name|int
name|nm_timeo
decl_stmt|;
comment|/* Init timer for NFSMNT_DUMBTIMR */
name|int
name|nm_retry
decl_stmt|;
comment|/* Max retries */
name|int
name|nm_srtt
index|[
literal|4
index|]
decl_stmt|;
comment|/* Timers for rpcs */
name|int
name|nm_sdrtt
index|[
literal|4
index|]
decl_stmt|;
name|int
name|nm_sent
decl_stmt|;
comment|/* Request send count */
name|int
name|nm_cwnd
decl_stmt|;
comment|/* Request send window */
name|int
name|nm_timeouts
decl_stmt|;
comment|/* Request timeouts */
name|int
name|nm_deadthresh
decl_stmt|;
comment|/* Threshold of timeouts-->dead server*/
name|int
name|nm_rsize
decl_stmt|;
comment|/* Max size of read rpc */
name|int
name|nm_wsize
decl_stmt|;
comment|/* Max size of write rpc */
name|int
name|nm_readahead
decl_stmt|;
comment|/* Num. of blocks to readahead */
name|int
name|nm_leaseterm
decl_stmt|;
comment|/* Term (sec) for NQNFS lease */
name|struct
name|nfsnode
modifier|*
name|nm_tnext
decl_stmt|;
comment|/* Head of lease timer queue */
name|struct
name|nfsnode
modifier|*
name|nm_tprev
decl_stmt|;
name|struct
name|vnode
modifier|*
name|nm_inprog
decl_stmt|;
comment|/* Vnode in prog by nqnfs_clientd() */
name|uid_t
name|nm_authuid
decl_stmt|;
comment|/* Uid for authenticator */
name|int
name|nm_authtype
decl_stmt|;
comment|/* Authenticator type */
name|int
name|nm_authlen
decl_stmt|;
comment|/* and length */
name|char
modifier|*
name|nm_authstr
decl_stmt|;
comment|/* Authenticator string */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_comment
comment|/*  * Convert mount ptr to nfsmount ptr.  */
end_comment

begin_define
define|#
directive|define
name|VFSTONFS
parameter_list|(
name|mp
parameter_list|)
value|((struct nfsmount *)((mp)->mnt_data))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

begin_comment
comment|/*  * Prototypes for NFS mount operations  */
end_comment

begin_decl_stmt
name|int
name|nfs_mount
name|__P
argument_list|(
operator|(
expr|struct
name|mount
operator|*
name|mp
operator|,
name|char
operator|*
name|path
operator|,
name|caddr_t
name|data
operator|,
expr|struct
name|nameidata
operator|*
name|ndp
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
name|nfs_start
name|__P
argument_list|(
operator|(
expr|struct
name|mount
operator|*
name|mp
operator|,
name|int
name|flags
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
name|nfs_unmount
name|__P
argument_list|(
operator|(
expr|struct
name|mount
operator|*
name|mp
operator|,
name|int
name|mntflags
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
name|nfs_root
name|__P
argument_list|(
operator|(
expr|struct
name|mount
operator|*
name|mp
operator|,
expr|struct
name|vnode
operator|*
operator|*
name|vpp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nfs_quotactl
name|__P
argument_list|(
operator|(
expr|struct
name|mount
operator|*
name|mp
operator|,
name|int
name|cmds
operator|,
name|uid_t
name|uid
operator|,
name|caddr_t
name|arg
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
name|nfs_statfs
name|__P
argument_list|(
operator|(
expr|struct
name|mount
operator|*
name|mp
operator|,
expr|struct
name|statfs
operator|*
name|sbp
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
name|nfs_sync
name|__P
argument_list|(
operator|(
expr|struct
name|mount
operator|*
name|mp
operator|,
name|int
name|waitfor
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
name|nfs_fhtovp
name|__P
argument_list|(
operator|(
expr|struct
name|mount
operator|*
name|mp
operator|,
expr|struct
name|fid
operator|*
name|fhp
operator|,
expr|struct
name|mbuf
operator|*
name|nam
operator|,
expr|struct
name|vnode
operator|*
operator|*
name|vpp
operator|,
name|int
operator|*
name|exflagsp
operator|,
expr|struct
name|ucred
operator|*
operator|*
name|credanonp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nfs_vptofh
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
name|vp
operator|,
expr|struct
name|fid
operator|*
name|fhp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nfs_init
name|__P
argument_list|(
operator|(
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

