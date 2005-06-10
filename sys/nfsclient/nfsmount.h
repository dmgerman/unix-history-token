begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Rick Macklem at The University of Guelph.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)nfsmount.h	8.3 (Berkeley) 3/30/95  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NFSCLIENT_NFSMOUNT_H_
end_ifndef

begin_define
define|#
directive|define
name|_NFSCLIENT_NFSMOUNT_H_
end_define

begin_struct
struct|struct
name|nfs_tcp_mountstate
block|{
name|int
name|rpcresid
decl_stmt|;
define|#
directive|define
name|NFS_TCP_EXPECT_RPCMARKER
value|0x0001
comment|/* Expect to see a RPC/TCP marker next */
define|#
directive|define
name|NFS_TCP_FORCE_RECONNECT
value|0x0002
comment|/* Force a TCP reconnect */
name|int
name|flags
decl_stmt|;
name|struct
name|mtx
name|mtx
decl_stmt|;
block|}
struct|;
end_struct

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
name|int
name|nm_state
decl_stmt|;
comment|/* Internal state flags */
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
name|u_char
name|nm_fh
index|[
name|NFSX_V4FH
index|]
decl_stmt|;
comment|/* File handle of root dir */
name|int
name|nm_fhsize
decl_stmt|;
comment|/* Size of root file handle */
name|struct
name|rpcclnt
name|nm_rpcclnt
decl_stmt|;
comment|/* rpc state */
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
name|sockaddr
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
name|nm_readdirsize
decl_stmt|;
comment|/* Size of a readdir rpc */
name|int
name|nm_readahead
decl_stmt|;
comment|/* Num. of blocks to readahead */
name|int
name|nm_wcommitsize
decl_stmt|;
comment|/* Max size of commit for write */
name|int
name|nm_acdirmin
decl_stmt|;
comment|/* Directory attr cache min lifetime */
name|int
name|nm_acdirmax
decl_stmt|;
comment|/* Directory attr cache max lifetime */
name|int
name|nm_acregmin
decl_stmt|;
comment|/* Reg file attr cache min lifetime */
name|int
name|nm_acregmax
decl_stmt|;
comment|/* Reg file attr cache max lifetime */
name|u_char
name|nm_verf
index|[
name|NFSX_V3WRITEVERF
index|]
decl_stmt|;
comment|/* V3 write verifier */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|buf
argument_list|)
name|nm_bufq
expr_stmt|;
comment|/* async io buffer queue */
name|short
name|nm_bufqlen
decl_stmt|;
comment|/* number of buffers in queue */
name|short
name|nm_bufqwant
decl_stmt|;
comment|/* process wants to add to the queue */
name|int
name|nm_bufqiods
decl_stmt|;
comment|/* number of iods processing queue */
name|u_int64_t
name|nm_maxfilesize
decl_stmt|;
comment|/* maximum file size */
name|struct
name|nfs_rpcops
modifier|*
name|nm_rpcops
decl_stmt|;
name|int
name|nm_tprintf_initial_delay
decl_stmt|;
comment|/* initial delay */
name|int
name|nm_tprintf_delay
decl_stmt|;
comment|/* interval for messages */
name|struct
name|nfs_tcp_mountstate
name|nm_nfstcpstate
decl_stmt|;
comment|/* NFSv4 */
name|uint64_t
name|nm_clientid
decl_stmt|;
name|fsid_t
name|nm_fsid
decl_stmt|;
name|u_int
name|nm_lease_time
decl_stmt|;
name|time_t
name|nm_last_renewal
decl_stmt|;
block|}
struct|;
end_struct

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_KERNEL
argument_list|)
end_if

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

begin_ifndef
ifndef|#
directive|ifndef
name|NFS_TPRINTF_INITIAL_DELAY
end_ifndef

begin_define
define|#
directive|define
name|NFS_TPRINTF_INITIAL_DELAY
value|12
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NFS_TPRINTF_DELAY
end_ifndef

begin_define
define|#
directive|define
name|NFS_TPRINTF_DELAY
value|30
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

