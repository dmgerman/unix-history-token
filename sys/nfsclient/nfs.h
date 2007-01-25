begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1989, 1993, 1995  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Rick Macklem at The University of Guelph.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)nfs.h	8.4 (Berkeley) 5/1/95  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NFSCLIENT_NFS_H_
end_ifndef

begin_define
define|#
directive|define
name|_NFSCLIENT_NFS_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|"opt_nfs.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<nfsclient/nfsargs.h>
end_include

begin_comment
comment|/*  * Tunable constants for nfs  */
end_comment

begin_define
define|#
directive|define
name|NFS_TICKINTVL
value|10
end_define

begin_comment
comment|/* Desired time for a tick (msec) */
end_comment

begin_define
define|#
directive|define
name|NFS_HZ
value|(hz / nfs_ticks)
end_define

begin_comment
comment|/* Ticks/sec */
end_comment

begin_define
define|#
directive|define
name|NFS_TIMEO
value|(1 * NFS_HZ)
end_define

begin_comment
comment|/* Default timeout = 1 second */
end_comment

begin_define
define|#
directive|define
name|NFS_MINTIMEO
value|(1 * NFS_HZ)
end_define

begin_comment
comment|/* Min timeout to use */
end_comment

begin_define
define|#
directive|define
name|NFS_MAXTIMEO
value|(60 * NFS_HZ)
end_define

begin_comment
comment|/* Max timeout to backoff to */
end_comment

begin_define
define|#
directive|define
name|NFS_MINIDEMTIMEO
value|(5 * NFS_HZ)
end_define

begin_comment
comment|/* Min timeout for non-idempotent ops*/
end_comment

begin_define
define|#
directive|define
name|NFS_MAXREXMIT
value|100
end_define

begin_comment
comment|/* Stop counting after this many */
end_comment

begin_define
define|#
directive|define
name|NFS_RETRANS
value|10
end_define

begin_comment
comment|/* Num of retrans for UDP soft mounts */
end_comment

begin_define
define|#
directive|define
name|NFS_RETRANS_TCP
value|2
end_define

begin_comment
comment|/* Num of retrans for TCP soft mounts */
end_comment

begin_define
define|#
directive|define
name|NFS_MAXGRPS
value|16
end_define

begin_comment
comment|/* Max. size of groups list */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NFS_MINATTRTIMO
end_ifndef

begin_define
define|#
directive|define
name|NFS_MINATTRTIMO
value|3
end_define

begin_comment
comment|/* VREG attrib cache timeout in sec */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NFS_MAXATTRTIMO
end_ifndef

begin_define
define|#
directive|define
name|NFS_MAXATTRTIMO
value|60
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NFS_MINDIRATTRTIMO
end_ifndef

begin_define
define|#
directive|define
name|NFS_MINDIRATTRTIMO
value|30
end_define

begin_comment
comment|/* VDIR attrib cache timeout in sec */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NFS_MAXDIRATTRTIMO
end_ifndef

begin_define
define|#
directive|define
name|NFS_MAXDIRATTRTIMO
value|60
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|NFS_WSIZE
value|8192
end_define

begin_comment
comment|/* Def. write data size<= 8192 */
end_comment

begin_define
define|#
directive|define
name|NFS_RSIZE
value|8192
end_define

begin_comment
comment|/* Def. read data size<= 8192 */
end_comment

begin_define
define|#
directive|define
name|NFS_READDIRSIZE
value|8192
end_define

begin_comment
comment|/* Def. readdir size */
end_comment

begin_define
define|#
directive|define
name|NFS_DEFRAHEAD
value|1
end_define

begin_comment
comment|/* Def. read ahead # blocks */
end_comment

begin_define
define|#
directive|define
name|NFS_MAXRAHEAD
value|4
end_define

begin_comment
comment|/* Max. read ahead # blocks */
end_comment

begin_define
define|#
directive|define
name|NFS_MAXASYNCDAEMON
value|64
end_define

begin_comment
comment|/* Max. number async_daemons runnable */
end_comment

begin_define
define|#
directive|define
name|NFS_DIRBLKSIZ
value|4096
end_define

begin_comment
comment|/* Must be a multiple of DIRBLKSIZ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|DIRBLKSIZ
value|512
end_define

begin_comment
comment|/* XXX we used to use ufs's DIRBLKSIZ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|NFS_MAXDEADTHRESH
value|9
end_define

begin_comment
comment|/* How long till we say 'server not responding' */
end_comment

begin_comment
comment|/*  * Oddballs  */
end_comment

begin_define
define|#
directive|define
name|NFS_CMPFH
parameter_list|(
name|n
parameter_list|,
name|f
parameter_list|,
name|s
parameter_list|)
define|\
value|((n)->n_fhsize == (s)&& !bcmp((caddr_t)(n)->n_fhp, (caddr_t)(f), (s)))
end_define

begin_define
define|#
directive|define
name|NFS_ISV3
parameter_list|(
name|v
parameter_list|)
value|(VFSTONFS((v)->v_mount)->nm_flag& NFSMNT_NFSV3)
end_define

begin_define
define|#
directive|define
name|NFS_ISV4
parameter_list|(
name|v
parameter_list|)
value|(VFSTONFS((v)->v_mount)->nm_flag& NFSMNT_NFSV4)
end_define

begin_define
define|#
directive|define
name|NFSSTA_HASWRITEVERF
value|0x00040000
end_define

begin_comment
comment|/* Has write verifier for V3 */
end_comment

begin_define
define|#
directive|define
name|NFSSTA_GOTFSINFO
value|0x00100000
end_define

begin_comment
comment|/* Got the V3 fsinfo */
end_comment

begin_define
define|#
directive|define
name|NFSSTA_SNDLOCK
value|0x01000000
end_define

begin_comment
comment|/* Send socket lock */
end_comment

begin_define
define|#
directive|define
name|NFSSTA_WANTSND
value|0x02000000
end_define

begin_comment
comment|/* Want above */
end_comment

begin_define
define|#
directive|define
name|NFSSTA_TIMEO
value|0x10000000
end_define

begin_comment
comment|/* Experiencing a timeout */
end_comment

begin_comment
comment|/*  * XXX to allow amd to include nfs.h without nfsproto.h  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NFS_NPROCS
end_ifdef

begin_include
include|#
directive|include
file|<nfsclient/nfsstats.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * vfs.nfs sysctl(3) identifiers  */
end_comment

begin_define
define|#
directive|define
name|NFS_NFSSTATS
value|1
end_define

begin_comment
comment|/* struct: struct nfsstats */
end_comment

begin_comment
comment|/*  * File context information for nfsv4.	Currently, there is only one  * lockowner for the whole machine "0."  */
end_comment

begin_struct
struct|struct
name|nfs4_fctx
block|{
name|TAILQ_ENTRY
argument_list|(
argument|nfs4_fstate
argument_list|)
name|next
expr_stmt|;
name|uint32_t
name|refcnt
decl_stmt|;
name|struct
name|nfs4_lowner
modifier|*
name|lop
decl_stmt|;
name|struct
name|nfsnode
modifier|*
name|np
decl_stmt|;
name|char
name|stateid
index|[
name|NFSX_V4STATEID
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|MALLOC_DECLARE
end_ifdef

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_NFSREQ
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_NFSDIROFF
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_NFSBIGFH
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_NFSHASH
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_NFSDIRECTIO
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|struct
name|uma_zone
modifier|*
name|nfsmount_zone
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|callout
name|nfs_callout
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|nfsstats
name|nfsstats
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|mtx
name|nfs_iod_mtx
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nfs_numasync
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|nfs_iodmax
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nfs_pbuf_freecnt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nfs_ticks
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Data constants in XDR form */
end_comment

begin_decl_stmt
specifier|extern
name|u_int32_t
name|nfs_true
decl_stmt|,
name|nfs_false
decl_stmt|,
name|nfs_xdrneg1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int32_t
name|rpc_reply
decl_stmt|,
name|rpc_msgdenied
decl_stmt|,
name|rpc_mismatch
decl_stmt|,
name|rpc_vers
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int32_t
name|rpc_auth_unix
decl_stmt|,
name|rpc_msgaccepted
decl_stmt|,
name|rpc_call
decl_stmt|,
name|rpc_autherr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nfsv3_procid
index|[
name|NFS_NPROCS
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Socket errors ignored for connectionless sockets??  * For now, ignore them all  */
end_comment

begin_define
define|#
directive|define
name|NFSIGNORE_SOERROR
parameter_list|(
name|s
parameter_list|,
name|e
parameter_list|)
define|\
value|((e) != EINTR&& (e) != EIO&& \ 		(e) != ERESTART&& (e) != EWOULDBLOCK&& \ 		((s)& PR_CONNREQUIRED) == 0)
end_define

begin_comment
comment|/*  * Nfs outstanding request list element  */
end_comment

begin_struct
struct|struct
name|nfsreq
block|{
name|TAILQ_ENTRY
argument_list|(
argument|nfsreq
argument_list|)
name|r_chain
expr_stmt|;
name|struct
name|mbuf
modifier|*
name|r_mreq
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|r_mrep
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|r_md
decl_stmt|;
name|caddr_t
name|r_dpos
decl_stmt|;
name|struct
name|nfsmount
modifier|*
name|r_nmp
decl_stmt|;
name|struct
name|vnode
modifier|*
name|r_vp
decl_stmt|;
name|u_int32_t
name|r_xid
decl_stmt|;
name|int
name|r_flags
decl_stmt|;
comment|/* flags on request, see below */
name|int
name|r_retry
decl_stmt|;
comment|/* max retransmission count */
name|int
name|r_rexmit
decl_stmt|;
comment|/* current retrans count */
name|int
name|r_timer
decl_stmt|;
comment|/* tick counter on reply */
name|u_int32_t
name|r_procnum
decl_stmt|;
comment|/* NFS procedure number */
name|int
name|r_rtt
decl_stmt|;
comment|/* RTT for rpc */
name|int
name|r_lastmsg
decl_stmt|;
comment|/* last tprintf */
name|struct
name|thread
modifier|*
name|r_td
decl_stmt|;
comment|/* Proc that did I/O system call */
name|struct
name|mtx
name|r_mtx
decl_stmt|;
comment|/* Protects nfsreq fields */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Queue head for nfsreq's  */
end_comment

begin_extern
extern|extern TAILQ_HEAD(nfs_reqq
operator|,
extern|nfsreq
end_extern

begin_expr_stmt
unit|)
name|nfs_reqq
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Flag values for r_flags */
end_comment

begin_define
define|#
directive|define
name|R_TIMING
value|0x01
end_define

begin_comment
comment|/* timing request (in mntp) */
end_comment

begin_define
define|#
directive|define
name|R_SENT
value|0x02
end_define

begin_comment
comment|/* request has been sent */
end_comment

begin_define
define|#
directive|define
name|R_SOFTTERM
value|0x04
end_define

begin_comment
comment|/* soft mnt, too many retries */
end_comment

begin_define
define|#
directive|define
name|R_RESENDERR
value|0x08
end_define

begin_comment
comment|/* Resend failed */
end_comment

begin_define
define|#
directive|define
name|R_SOCKERR
value|0x10
end_define

begin_comment
comment|/* Fatal error on socket */
end_comment

begin_define
define|#
directive|define
name|R_TPRINTFMSG
value|0x20
end_define

begin_comment
comment|/* Did a tprintf msg. */
end_comment

begin_define
define|#
directive|define
name|R_MUSTRESEND
value|0x40
end_define

begin_comment
comment|/* Must resend request */
end_comment

begin_define
define|#
directive|define
name|R_GETONEREP
value|0x80
end_define

begin_comment
comment|/* Probe for one reply only */
end_comment

begin_define
define|#
directive|define
name|R_PIN_REQ
value|0x100
end_define

begin_comment
comment|/* Pin request down (rexmit in prog or other) */
end_comment

begin_struct_decl
struct_decl|struct
name|buf
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|socket
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|uio
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|vattr
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * Pointers to ops that differ from v3 to v4  */
end_comment

begin_struct
struct|struct
name|nfs_rpcops
block|{
name|int
function_decl|(
modifier|*
name|nr_readrpc
function_decl|)
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|,
name|struct
name|uio
modifier|*
name|uiop
parameter_list|,
name|struct
name|ucred
modifier|*
name|cred
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|nr_writerpc
function_decl|)
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|,
name|struct
name|uio
modifier|*
name|uiop
parameter_list|,
name|struct
name|ucred
modifier|*
name|cred
parameter_list|,
name|int
modifier|*
name|iomode
parameter_list|,
name|int
modifier|*
name|must_commit
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|nr_writebp
function_decl|)
parameter_list|(
name|struct
name|buf
modifier|*
name|bp
parameter_list|,
name|int
name|force
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|nr_readlinkrpc
function_decl|)
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|,
name|struct
name|uio
modifier|*
name|uiop
parameter_list|,
name|struct
name|ucred
modifier|*
name|cred
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|nr_invaldir
function_decl|)
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|nr_commit
function_decl|)
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|,
name|u_quad_t
name|offset
parameter_list|,
name|int
name|cnt
parameter_list|,
name|struct
name|ucred
modifier|*
name|cred
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Defines for WebNFS  */
end_comment

begin_define
define|#
directive|define
name|WEBNFS_ESC_CHAR
value|'%'
end_define

begin_define
define|#
directive|define
name|WEBNFS_SPECCHAR_START
value|0x80
end_define

begin_define
define|#
directive|define
name|WEBNFS_NATIVE_CHAR
value|0x80
end_define

begin_comment
comment|/*  * ..  * Possibly more here in the future.  */
end_comment

begin_comment
comment|/*  * Macro for converting escape characters in WebNFS pathnames.  * Should really be in libkern.  */
end_comment

begin_define
define|#
directive|define
name|HEXTOC
parameter_list|(
name|c
parameter_list|)
define|\
value|((c)>= 'a' ? ((c) - ('a' - 10)) : \ 	    ((c)>= 'A' ? ((c) - ('A' - 10)) : ((c) - '0')))
end_define

begin_define
define|#
directive|define
name|HEXSTRTOI
parameter_list|(
name|p
parameter_list|)
define|\
value|((HEXTOC(p[0])<< 4) + HEXTOC(p[1]))
end_define

begin_comment
comment|/* nfs_sigintr() helper, when 'rep' has all we need */
end_comment

begin_define
define|#
directive|define
name|NFS_SIGREP
parameter_list|(
name|rep
parameter_list|)
value|nfs_sigintr((rep)->r_nmp, (rep), (rep)->r_td)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|NFS_DEBUG
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|nfs_debug
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|NFS_DEBUG_ASYNCIO
value|1
end_define

begin_comment
comment|/* asynchronous i/o */
end_comment

begin_define
define|#
directive|define
name|NFS_DEBUG_WG
value|2
end_define

begin_comment
comment|/* server write gathering */
end_comment

begin_define
define|#
directive|define
name|NFS_DEBUG_RC
value|4
end_define

begin_comment
comment|/* server request caching */
end_comment

begin_define
define|#
directive|define
name|NFS_DPF
parameter_list|(
name|cat
parameter_list|,
name|args
parameter_list|)
define|\
value|do {							\ 		if (nfs_debug& NFS_DEBUG_##cat) printf args;	\ 	} while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NFS_DPF
parameter_list|(
name|cat
parameter_list|,
name|args
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * On fast networks, the estimator will try to reduce the  * timeout lower than the latency of the server's disks,  * which results in too many timeouts, so cap the lower  * bound.  */
end_comment

begin_define
define|#
directive|define
name|NFS_MINRTO
value|(NFS_HZ>> 2)
end_define

begin_comment
comment|/*  * Keep the RTO from increasing to unreasonably large values  * when a server is not responding.  */
end_comment

begin_define
define|#
directive|define
name|NFS_MAXRTO
value|(20 * NFS_HZ)
end_define

begin_enum
enum|enum
name|nfs_rto_timer_t
block|{
name|NFS_DEFAULT_TIMER
block|,
name|NFS_GETATTR_TIMER
block|,
name|NFS_LOOKUP_TIMER
block|,
name|NFS_READ_TIMER
block|,
name|NFS_WRITE_TIMER
block|, }
enum|;
end_enum

begin_define
define|#
directive|define
name|NFS_MAX_TIMER
value|(NFS_WRITE_TIMER)
end_define

begin_define
define|#
directive|define
name|NFS_INITRTT
value|(NFS_HZ<< 3)
end_define

begin_decl_stmt
name|vfs_init_t
name|nfs_init
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vfs_uninit_t
name|nfs_uninit
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|nfs_mountroot
parameter_list|(
name|struct
name|mount
modifier|*
name|mp
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|NFS4_USE_RPCCLNT
end_ifndef

begin_function_decl
name|int
name|nfs_send
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|struct
name|nfsreq
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfs_sndlock
parameter_list|(
name|struct
name|nfsreq
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nfs_sndunlock
parameter_list|(
name|struct
name|nfsreq
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! NFS4_USE_RPCCLNT */
end_comment

begin_function_decl
name|int
name|nfs_vinvalbuf
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|thread
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfs_readrpc
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|,
name|struct
name|uio
modifier|*
parameter_list|,
name|struct
name|ucred
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfs_writerpc
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|,
name|struct
name|uio
modifier|*
parameter_list|,
name|struct
name|ucred
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfs_commit
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|,
name|u_quad_t
name|offset
parameter_list|,
name|int
name|cnt
parameter_list|,
name|struct
name|ucred
modifier|*
name|cred
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfs_readdirrpc
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|,
name|struct
name|uio
modifier|*
parameter_list|,
name|struct
name|ucred
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfs_nfsiodnew
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfs_asyncio
parameter_list|(
name|struct
name|nfsmount
modifier|*
parameter_list|,
name|struct
name|buf
modifier|*
parameter_list|,
name|struct
name|ucred
modifier|*
parameter_list|,
name|struct
name|thread
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfs_doio
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|,
name|struct
name|buf
modifier|*
parameter_list|,
name|struct
name|ucred
modifier|*
parameter_list|,
name|struct
name|thread
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nfs_doio_directwrite
parameter_list|(
name|struct
name|buf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nfs_up
parameter_list|(
name|struct
name|nfsreq
modifier|*
parameter_list|,
name|struct
name|nfsmount
modifier|*
parameter_list|,
name|struct
name|thread
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nfs_down
parameter_list|(
name|struct
name|nfsreq
modifier|*
parameter_list|,
name|struct
name|nfsmount
modifier|*
parameter_list|,
name|struct
name|thread
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfs_readlinkrpc
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|,
name|struct
name|uio
modifier|*
parameter_list|,
name|struct
name|ucred
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfs_sigintr
parameter_list|(
name|struct
name|nfsmount
modifier|*
parameter_list|,
name|struct
name|nfsreq
modifier|*
parameter_list|,
name|struct
name|thread
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfs_readdirplusrpc
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|,
name|struct
name|uio
modifier|*
parameter_list|,
name|struct
name|ucred
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfs_request
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|thread
modifier|*
parameter_list|,
name|struct
name|ucred
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
parameter_list|,
name|caddr_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfs_loadattrcache
parameter_list|(
name|struct
name|vnode
modifier|*
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
parameter_list|,
name|caddr_t
modifier|*
parameter_list|,
name|struct
name|vattr
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfsm_mbuftouio
parameter_list|(
name|struct
name|mbuf
modifier|*
modifier|*
parameter_list|,
name|struct
name|uio
modifier|*
parameter_list|,
name|int
parameter_list|,
name|caddr_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nfs_nhinit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nfs_nhuninit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfs_nmcancelreqs
parameter_list|(
name|struct
name|nfsmount
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nfs_timer
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfs_connect
parameter_list|(
name|struct
name|nfsmount
modifier|*
parameter_list|,
name|struct
name|nfsreq
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nfs_disconnect
parameter_list|(
name|struct
name|nfsmount
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nfs_safedisconnect
parameter_list|(
name|struct
name|nfsmount
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfs_getattrcache
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|,
name|struct
name|vattr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfs_iosize
parameter_list|(
name|struct
name|nfsmount
modifier|*
name|nmp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfsm_strtmbuf
parameter_list|(
name|struct
name|mbuf
modifier|*
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfs_bioread
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|,
name|struct
name|uio
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|ucred
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfsm_uiotombuf
parameter_list|(
name|struct
name|uio
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|,
name|caddr_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nfs_clearcommit
parameter_list|(
name|struct
name|mount
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfs_writebp
parameter_list|(
name|struct
name|buf
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|thread
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfs_fsinfo
parameter_list|(
name|struct
name|nfsmount
modifier|*
parameter_list|,
name|struct
name|vnode
modifier|*
parameter_list|,
name|struct
name|ucred
modifier|*
parameter_list|,
name|struct
name|thread
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfs_meta_setsize
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|,
name|struct
name|ucred
modifier|*
parameter_list|,
name|struct
name|thread
modifier|*
parameter_list|,
name|u_quad_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nfs_set_sigmask
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|sigset_t
modifier|*
name|oldset
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nfs_restore_sigmask
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|sigset_t
modifier|*
name|set
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfs_msleep
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|void
modifier|*
name|ident
parameter_list|,
name|struct
name|mtx
modifier|*
name|mtx
parameter_list|,
name|int
name|priority
parameter_list|,
name|char
modifier|*
name|wmesg
parameter_list|,
name|int
name|timo
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

