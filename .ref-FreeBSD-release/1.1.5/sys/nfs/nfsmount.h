begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Rick Macklem at The University of Guelph.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	From:	@(#)nfsmount.h	7.7 (Berkeley) 4/16/91  *	$Id: nfsmount.h,v 1.2 1993/09/09 22:06:23 rgrimes Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__h_nfsmount
end_ifndef

begin_define
define|#
directive|define
name|__h_nfsmount
value|1
end_define

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
name|short
name|nm_retry
decl_stmt|;
comment|/* Max retry count */
name|short
name|nm_rexmit
decl_stmt|;
comment|/* Rexmit on previous request */
name|short
name|nm_rtt
decl_stmt|;
comment|/* Round trip timer ticks @ NFS_HZ */
name|short
name|nm_rto
decl_stmt|;
comment|/* Current timeout */
name|short
name|nm_srtt
decl_stmt|;
comment|/* Smoothed round trip time */
name|short
name|nm_rttvar
decl_stmt|;
comment|/* RTT variance */
name|short
name|nm_currto
decl_stmt|;
comment|/* Current rto of any nfsmount */
name|short
name|nm_currexmit
decl_stmt|;
comment|/* Max rexmit count of nfsmounts */
name|short
name|nm_sent
decl_stmt|;
comment|/* Request send count */
name|short
name|nm_window
decl_stmt|;
comment|/* Request send window (max) */
name|short
name|nm_winext
decl_stmt|;
comment|/* Window incremental value */
name|short
name|nm_ssthresh
decl_stmt|;
comment|/* Slowstart threshold */
name|short
name|nm_salen
decl_stmt|;
comment|/* Actual length of nm_sockaddr */
name|int
name|nm_rsize
decl_stmt|;
comment|/* Max size of read rpc */
name|int
name|nm_wsize
decl_stmt|;
comment|/* Max size of write rpc */
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
name|int
name|uid
operator|,
comment|/* should be uid_t */
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
name|void
name|nfs_init
name|__P
argument_list|(
operator|(
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __h_nfsmount */
end_comment

end_unit

