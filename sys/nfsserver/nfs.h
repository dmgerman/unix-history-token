begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1989, 1993, 1995  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Rick Macklem at The University of Guelph.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)nfs.h	8.4 (Berkeley) 5/1/95  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NFSSERVER_NFS_H_
end_ifndef

begin_define
define|#
directive|define
name|_NFSSERVER_NFS_H_
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
name|NFS_MAXUIDHASH
value|64
end_define

begin_comment
comment|/* Max. # of hashed uid entries/mp */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NFS_GATHERDELAY
end_ifndef

begin_define
define|#
directive|define
name|NFS_GATHERDELAY
value|10
end_define

begin_comment
comment|/* Default write gather delay (msec) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

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

begin_comment
comment|/*  * Oddballs  */
end_comment

begin_define
define|#
directive|define
name|NFS_SRVMAXDATA
parameter_list|(
name|n
parameter_list|)
define|\
value|(((n)->nd_flag& ND_NFSV3) ? (((n)->nd_nam2) ? \ 		 NFS_MAXDGRAMDATA : NFS_MAXDATA) : NFS_V2MAXDATA)
end_define

begin_comment
comment|/*  * XXX  * The B_INVAFTERWRITE flag should be set to whatever is required by the  * buffer cache code to say "Invalidate the block after it is written back".  */
end_comment

begin_define
define|#
directive|define
name|B_INVAFTERWRITE
value|B_NOCACHE
end_define

begin_comment
comment|/*  * The IO_METASYNC flag should be implemented for local filesystems.  * (Until then, it is nothin at all.)  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IO_METASYNC
end_ifndef

begin_define
define|#
directive|define
name|IO_METASYNC
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NFS state flags XXX -Wunused */
end_comment

begin_define
define|#
directive|define
name|NFSRV_SNDLOCK
value|0x01000000
end_define

begin_comment
comment|/* Send socket lock */
end_comment

begin_define
define|#
directive|define
name|NFSRV_WANTSND
value|0x02000000
end_define

begin_comment
comment|/* Want above */
end_comment

begin_comment
comment|/*  * Structures for the nfssvc(2) syscall. Not that anyone but nfsd and mount_nfs  * should ever try and use it.  */
end_comment

begin_struct
struct|struct
name|nfsd_args
block|{
name|int
name|sock
decl_stmt|;
comment|/* Socket to serve */
name|caddr_t
name|name
decl_stmt|;
comment|/* Client addr for connection based sockets */
name|int
name|namelen
decl_stmt|;
comment|/* Length of name */
block|}
struct|;
end_struct

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
file|<nfsserver/nfsrvstats.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Flags for nfssvc() system call.  */
end_comment

begin_define
define|#
directive|define
name|NFSSVC_NFSD
value|0x004
end_define

begin_define
define|#
directive|define
name|NFSSVC_ADDSOCK
value|0x008
end_define

begin_comment
comment|/*  * vfs.nfsrv sysctl(3) identifiers  */
end_comment

begin_define
define|#
directive|define
name|NFS_NFSRVSTATS
value|1
end_define

begin_comment
comment|/* struct: struct nfsrvstats */
end_comment

begin_define
define|#
directive|define
name|NFS_NFSPRIVPORT
value|2
end_define

begin_comment
comment|/* int: prohibit nfs to resvports */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|mtx
name|nfsd_mtx
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|NFSD_LOCK_ASSERT
parameter_list|()
value|mtx_assert(&nfsd_mtx, MA_OWNED)
end_define

begin_define
define|#
directive|define
name|NFSD_UNLOCK_ASSERT
parameter_list|()
value|mtx_assert(&nfsd_mtx, MA_NOTOWNED)
end_define

begin_define
define|#
directive|define
name|NFSD_LOCK_DONTCARE
parameter_list|()
end_define

begin_define
define|#
directive|define
name|NFSD_LOCK
parameter_list|()
value|mtx_lock(&nfsd_mtx)
end_define

begin_define
define|#
directive|define
name|NFSD_UNLOCK
parameter_list|()
value|mtx_unlock(&nfsd_mtx)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|MALLOC_DECLARE
end_ifdef

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_NFSRVDESC
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_NFSD
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Forward declarations */
end_comment

begin_struct_decl
struct_decl|struct
name|nfssvc_sock
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|nfsrv_descript
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

begin_struct_decl
struct_decl|struct
name|nameidata
struct_decl|;
end_struct_decl

begin_decl_stmt
specifier|extern
name|struct
name|callout
name|nfsrv_callout
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|nfsrvstats
name|nfsrvstats
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nfsrv_ticks
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nfsrvw_procrastinate
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nfsrvw_procrastinate_v3
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nfsrv_numnfsd
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Various values converted to XDR form. */
end_comment

begin_decl_stmt
specifier|extern
name|u_int32_t
name|nfsrv_nfs_false
decl_stmt|,
name|nfsrv_nfs_true
decl_stmt|,
name|nfsrv_nfs_xdrneg1
decl_stmt|,
name|nfsrv_nfs_prog
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int32_t
name|nfsrv_rpc_reply
decl_stmt|,
name|nfsrv_rpc_msgdenied
decl_stmt|,
name|nfsrv_rpc_mismatch
decl_stmt|,
name|nfsrv_rpc_vers
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int32_t
name|nfsrv_rpc_auth_unix
decl_stmt|,
name|nfsrv_rpc_msgaccepted
decl_stmt|,
name|nfsrv_rpc_call
decl_stmt|,
name|nfsrv_rpc_autherr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Procedure table data */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|nfsrvv2_procid
index|[
name|NFS_NPROCS
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|nfsrv_nfsv3_procid
index|[
name|NFS_NPROCS
index|]
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int32_t
function_decl|(
modifier|*
name|nfsrv3_procs
index|[
name|NFS_NPROCS
index|]
function_decl|)
parameter_list|(
name|struct
name|nfsrv_descript
modifier|*
name|nd
parameter_list|,
name|struct
name|nfssvc_sock
modifier|*
name|slp
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
name|mreqp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * A list of nfssvc_sock structures is maintained with all the sockets  * that require service by the nfsd.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NFS_WDELAYHASHSIZ
end_ifndef

begin_define
define|#
directive|define
name|NFS_WDELAYHASHSIZ
value|16
end_define

begin_comment
comment|/* and with this */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|NWDELAYHASH
parameter_list|(
name|sock
parameter_list|,
name|f
parameter_list|)
define|\
value|(&(sock)->ns_wdelayhashtbl[(*((u_int32_t *)(f))) % NFS_WDELAYHASHSIZ])
end_define

begin_comment
comment|/*  * Network address hash list element  */
end_comment

begin_union
union|union
name|nethostaddr
block|{
name|u_int32_t
name|had_inetaddr
decl_stmt|;
name|struct
name|sockaddr
modifier|*
name|had_nam
decl_stmt|;
block|}
union|;
end_union

begin_struct
struct|struct
name|nfsrv_rec
block|{
name|STAILQ_ENTRY
argument_list|(
argument|nfsrv_rec
argument_list|)
name|nr_link
expr_stmt|;
name|struct
name|sockaddr
modifier|*
name|nr_address
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|nr_packet
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|nfssvc_sock
block|{
name|TAILQ_ENTRY
argument_list|(
argument|nfssvc_sock
argument_list|)
name|ns_chain
expr_stmt|;
comment|/* List of all nfssvc_sock's */
name|struct
name|file
modifier|*
name|ns_fp
decl_stmt|;
name|struct
name|socket
modifier|*
name|ns_so
decl_stmt|;
name|struct
name|sockaddr
modifier|*
name|ns_nam
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|ns_raw
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|ns_rawend
decl_stmt|;
name|STAILQ_HEAD
argument_list|(
argument_list|,
argument|nfsrv_rec
argument_list|)
name|ns_rec
expr_stmt|;
name|struct
name|mbuf
modifier|*
name|ns_frag
decl_stmt|;
name|int
name|ns_flag
decl_stmt|;
name|int
name|ns_solock
decl_stmt|;
name|int
name|ns_cc
decl_stmt|;
name|int
name|ns_reclen
decl_stmt|;
name|u_int32_t
name|ns_sref
decl_stmt|;
name|LIST_HEAD
argument_list|(
argument_list|,
argument|nfsrv_descript
argument_list|)
name|ns_tq
expr_stmt|;
comment|/* Write gather lists */
name|LIST_HEAD
argument_list|(
argument|nfsrvw_delayhash
argument_list|,
argument|nfsrv_descript
argument_list|)
name|ns_wdelayhashtbl
index|[
name|NFS_WDELAYHASHSIZ
index|]
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Bits for "ns_flag" */
end_comment

begin_define
define|#
directive|define
name|SLP_VALID
value|0x01
end_define

begin_comment
comment|/* Socket valid for use (XXX) */
end_comment

begin_define
define|#
directive|define
name|SLP_DOREC
value|0x02
end_define

begin_comment
comment|/* Socket ready for processing */
end_comment

begin_define
define|#
directive|define
name|SLP_NEEDQ
value|0x04
end_define

begin_comment
comment|/* Socket has request queued */
end_comment

begin_define
define|#
directive|define
name|SLP_DISCONN
value|0x08
end_define

begin_comment
comment|/* Error received from stream socket */
end_comment

begin_define
define|#
directive|define
name|SLP_GETSTREAM
value|0x10
end_define

begin_comment
comment|/* nfsrv_getstream in prog on sock */
end_comment

begin_define
define|#
directive|define
name|SLP_LASTFRAG
value|0x20
end_define

begin_comment
comment|/* Socket received end-of-record */
end_comment

begin_define
define|#
directive|define
name|SLP_ALLFLAGS
value|0xff
end_define

begin_extern
extern|extern TAILQ_HEAD(nfssvc_sockhead
operator|,
extern|nfssvc_sock
end_extern

begin_expr_stmt
unit|)
name|nfssvc_sockhead
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|extern
name|int
name|nfssvc_sockhead_flag
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|SLP_INIT
value|0x01
end_define

begin_define
define|#
directive|define
name|SLP_WANTINIT
value|0x02
end_define

begin_comment
comment|/*  * One of these structures is allocated for each nfsd.  */
end_comment

begin_struct
struct|struct
name|nfsd
block|{
name|TAILQ_ENTRY
argument_list|(
argument|nfsd
argument_list|)
name|nfsd_chain
expr_stmt|;
comment|/* List of all nfsd's */
name|int
name|nfsd_flag
decl_stmt|;
comment|/* NFSD_ flags */
name|struct
name|nfssvc_sock
modifier|*
name|nfsd_slp
decl_stmt|;
comment|/* Current socket */
name|int
name|nfsd_authlen
decl_stmt|;
comment|/* Authenticator len */
name|u_char
name|nfsd_authstr
index|[
name|RPCAUTH_MAXSIZ
index|]
decl_stmt|;
comment|/* Authenticator data */
name|int
name|nfsd_verflen
decl_stmt|;
comment|/* and the Verifier */
name|u_char
name|nfsd_verfstr
index|[
name|RPCVERF_MAXSIZ
index|]
decl_stmt|;
name|struct
name|thread
modifier|*
name|nfsd_td
decl_stmt|;
comment|/* daemon thread ptr */
name|struct
name|nfsrv_descript
modifier|*
name|nfsd_nd
decl_stmt|;
comment|/* Associated nfsrv_descript */
block|}
struct|;
end_struct

begin_comment
comment|/* Bits for "nfsd_flag" */
end_comment

begin_define
define|#
directive|define
name|NFSD_WAITING
value|0x01
end_define

begin_define
define|#
directive|define
name|NFSD_REQINPROG
value|0x02
end_define

begin_comment
comment|/*  * This structure is used by the server for describing each request.  * Some fields are used only when write request gathering is performed.  */
end_comment

begin_struct
struct|struct
name|nfsrv_descript
block|{
name|u_quad_t
name|nd_time
decl_stmt|;
comment|/* Write deadline (usec) */
name|off_t
name|nd_off
decl_stmt|;
comment|/* Start byte offset */
name|off_t
name|nd_eoff
decl_stmt|;
comment|/* and end byte offset */
name|LIST_ENTRY
argument_list|(
argument|nfsrv_descript
argument_list|)
name|nd_hash
expr_stmt|;
comment|/* Hash list */
name|LIST_ENTRY
argument_list|(
argument|nfsrv_descript
argument_list|)
name|nd_tq
expr_stmt|;
comment|/* and timer list */
name|LIST_HEAD
argument_list|(
argument_list|,
argument|nfsrv_descript
argument_list|)
name|nd_coalesce
expr_stmt|;
comment|/* coalesced writes */
name|struct
name|mbuf
modifier|*
name|nd_mrep
decl_stmt|;
comment|/* Request mbuf list */
name|struct
name|mbuf
modifier|*
name|nd_md
decl_stmt|;
comment|/* Current dissect mbuf */
name|struct
name|mbuf
modifier|*
name|nd_mreq
decl_stmt|;
comment|/* Reply mbuf list */
name|struct
name|sockaddr
modifier|*
name|nd_nam
decl_stmt|;
comment|/* and socket addr */
name|struct
name|sockaddr
modifier|*
name|nd_nam2
decl_stmt|;
comment|/* return socket addr */
name|caddr_t
name|nd_dpos
decl_stmt|;
comment|/* Current dissect pos */
name|u_int32_t
name|nd_procnum
decl_stmt|;
comment|/* RPC # */
name|int
name|nd_stable
decl_stmt|;
comment|/* storage type */
name|int
name|nd_flag
decl_stmt|;
comment|/* nd_flag */
name|int
name|nd_len
decl_stmt|;
comment|/* Length of this write */
name|int
name|nd_repstat
decl_stmt|;
comment|/* Reply status */
name|u_int32_t
name|nd_retxid
decl_stmt|;
comment|/* Reply xid */
name|struct
name|timeval
name|nd_starttime
decl_stmt|;
comment|/* Time RPC initiated */
name|fhandle_t
name|nd_fh
decl_stmt|;
comment|/* File handle */
name|struct
name|ucred
modifier|*
name|nd_cr
decl_stmt|;
comment|/* Credentials */
block|}
struct|;
end_struct

begin_comment
comment|/* Bits for "nd_flag" */
end_comment

begin_define
define|#
directive|define
name|ND_NFSV3
value|0x08
end_define

begin_extern
extern|extern TAILQ_HEAD(nfsd_head
operator|,
extern|nfsd
end_extern

begin_expr_stmt
unit|)
name|nfsd_head
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|extern
name|int
name|nfsd_head_flag
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|NFSD_CHECKSLP
value|0x01
end_define

begin_comment
comment|/*  * These macros compare nfsrv_descript structures.  */
end_comment

begin_define
define|#
directive|define
name|NFSW_CONTIG
parameter_list|(
name|o
parameter_list|,
name|n
parameter_list|)
define|\
value|((o)->nd_eoff>= (n)->nd_off&& \ 		 !bcmp((caddr_t)&(o)->nd_fh, (caddr_t)&(n)->nd_fh, NFSX_V3FH))
end_define

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

begin_function_decl
name|int
name|nfs_getreq
parameter_list|(
name|struct
name|nfsrv_descript
modifier|*
parameter_list|,
name|struct
name|nfsd
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfsrv_send
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
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|mbuf
modifier|*
name|nfs_rephead
parameter_list|(
name|int
parameter_list|,
name|struct
name|nfsrv_descript
modifier|*
parameter_list|,
name|int
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
name|nfs_slplock
parameter_list|(
name|struct
name|nfssvc_sock
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nfs_slpunlock
parameter_list|(
name|struct
name|nfssvc_sock
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nfsm_srvfattr
parameter_list|(
name|struct
name|nfsrv_descript
modifier|*
parameter_list|,
name|struct
name|vattr
modifier|*
parameter_list|,
name|struct
name|nfs_fattr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nfsm_srvwcc
parameter_list|(
name|struct
name|nfsrv_descript
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|vattr
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|vattr
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nfsm_srvpostopattr
parameter_list|(
name|struct
name|nfsrv_descript
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|vattr
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|netaddr_match
parameter_list|(
name|int
parameter_list|,
name|union
name|nethostaddr
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfs_namei
parameter_list|(
name|struct
name|nameidata
modifier|*
parameter_list|,
name|fhandle_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|nfssvc_sock
modifier|*
parameter_list|,
name|struct
name|sockaddr
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
name|vnode
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|vattr
modifier|*
parameter_list|,
name|int
modifier|*
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
name|void
name|nfsm_adj
parameter_list|(
name|struct
name|mbuf
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
name|nfsrv_initcache
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nfsrv_destroycache
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nfsrv_timer
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfsrv_dorec
parameter_list|(
name|struct
name|nfssvc_sock
modifier|*
parameter_list|,
name|struct
name|nfsd
modifier|*
parameter_list|,
name|struct
name|nfsrv_descript
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfsrv_getcache
parameter_list|(
name|struct
name|nfsrv_descript
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nfsrv_updatecache
parameter_list|(
name|struct
name|nfsrv_descript
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nfsrv_cleancache
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nfsrv_init
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfsrv_errmap
parameter_list|(
name|struct
name|nfsrv_descript
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nfsrvw_sort
parameter_list|(
name|gid_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nfsrv_setcred
parameter_list|(
name|struct
name|ucred
modifier|*
parameter_list|,
name|struct
name|ucred
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nfsrv_wakenfsd
parameter_list|(
name|struct
name|nfssvc_sock
modifier|*
name|slp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfsrv_writegather
parameter_list|(
name|struct
name|nfsrv_descript
modifier|*
modifier|*
parameter_list|,
name|struct
name|nfssvc_sock
modifier|*
parameter_list|,
name|struct
name|thread
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfsrv3_access
parameter_list|(
name|struct
name|nfsrv_descript
modifier|*
name|nfsd
parameter_list|,
name|struct
name|nfssvc_sock
modifier|*
name|slp
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
name|mrq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfsrv_commit
parameter_list|(
name|struct
name|nfsrv_descript
modifier|*
name|nfsd
parameter_list|,
name|struct
name|nfssvc_sock
modifier|*
name|slp
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
name|mrq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfsrv_create
parameter_list|(
name|struct
name|nfsrv_descript
modifier|*
name|nfsd
parameter_list|,
name|struct
name|nfssvc_sock
modifier|*
name|slp
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
name|mrq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfsrv_fhtovp
parameter_list|(
name|fhandle_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|vnode
modifier|*
modifier|*
parameter_list|,
name|struct
name|ucred
modifier|*
parameter_list|,
name|struct
name|nfssvc_sock
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfsrv_fhtovp_locked
parameter_list|(
name|fhandle_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|vnode
modifier|*
modifier|*
parameter_list|,
name|struct
name|ucred
modifier|*
parameter_list|,
name|struct
name|nfssvc_sock
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfsrv_setpublicfs
parameter_list|(
name|struct
name|mount
modifier|*
parameter_list|,
name|struct
name|netexport
modifier|*
parameter_list|,
name|struct
name|export_args
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfs_ispublicfh
parameter_list|(
name|fhandle_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfsrv_fsinfo
parameter_list|(
name|struct
name|nfsrv_descript
modifier|*
name|nfsd
parameter_list|,
name|struct
name|nfssvc_sock
modifier|*
name|slp
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
name|mrq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfsrv_getattr
parameter_list|(
name|struct
name|nfsrv_descript
modifier|*
name|nfsd
parameter_list|,
name|struct
name|nfssvc_sock
modifier|*
name|slp
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
name|mrq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfsrv_link
parameter_list|(
name|struct
name|nfsrv_descript
modifier|*
name|nfsd
parameter_list|,
name|struct
name|nfssvc_sock
modifier|*
name|slp
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
name|mrq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfsrv_lookup
parameter_list|(
name|struct
name|nfsrv_descript
modifier|*
name|nfsd
parameter_list|,
name|struct
name|nfssvc_sock
modifier|*
name|slp
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
name|mrq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfsrv_mkdir
parameter_list|(
name|struct
name|nfsrv_descript
modifier|*
name|nfsd
parameter_list|,
name|struct
name|nfssvc_sock
modifier|*
name|slp
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
name|mrq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfsrv_mknod
parameter_list|(
name|struct
name|nfsrv_descript
modifier|*
name|nfsd
parameter_list|,
name|struct
name|nfssvc_sock
modifier|*
name|slp
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
name|mrq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfsrv_noop
parameter_list|(
name|struct
name|nfsrv_descript
modifier|*
name|nfsd
parameter_list|,
name|struct
name|nfssvc_sock
modifier|*
name|slp
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
name|mrq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfsrv_null
parameter_list|(
name|struct
name|nfsrv_descript
modifier|*
name|nfsd
parameter_list|,
name|struct
name|nfssvc_sock
modifier|*
name|slp
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
name|mrq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfsrv_pathconf
parameter_list|(
name|struct
name|nfsrv_descript
modifier|*
name|nfsd
parameter_list|,
name|struct
name|nfssvc_sock
modifier|*
name|slp
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
name|mrq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfsrv_read
parameter_list|(
name|struct
name|nfsrv_descript
modifier|*
name|nfsd
parameter_list|,
name|struct
name|nfssvc_sock
modifier|*
name|slp
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
name|mrq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfsrv_readdir
parameter_list|(
name|struct
name|nfsrv_descript
modifier|*
name|nfsd
parameter_list|,
name|struct
name|nfssvc_sock
modifier|*
name|slp
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
name|mrq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfsrv_readdirplus
parameter_list|(
name|struct
name|nfsrv_descript
modifier|*
name|nfsd
parameter_list|,
name|struct
name|nfssvc_sock
modifier|*
name|slp
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
name|mrq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfsrv_readlink
parameter_list|(
name|struct
name|nfsrv_descript
modifier|*
name|nfsd
parameter_list|,
name|struct
name|nfssvc_sock
modifier|*
name|slp
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
name|mrq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfsrv_remove
parameter_list|(
name|struct
name|nfsrv_descript
modifier|*
name|nfsd
parameter_list|,
name|struct
name|nfssvc_sock
modifier|*
name|slp
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
name|mrq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfsrv_rename
parameter_list|(
name|struct
name|nfsrv_descript
modifier|*
name|nfsd
parameter_list|,
name|struct
name|nfssvc_sock
modifier|*
name|slp
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
name|mrq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfsrv_rmdir
parameter_list|(
name|struct
name|nfsrv_descript
modifier|*
name|nfsd
parameter_list|,
name|struct
name|nfssvc_sock
modifier|*
name|slp
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
name|mrq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfsrv_setattr
parameter_list|(
name|struct
name|nfsrv_descript
modifier|*
name|nfsd
parameter_list|,
name|struct
name|nfssvc_sock
modifier|*
name|slp
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
name|mrq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfsrv_statfs
parameter_list|(
name|struct
name|nfsrv_descript
modifier|*
name|nfsd
parameter_list|,
name|struct
name|nfssvc_sock
modifier|*
name|slp
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
name|mrq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfsrv_symlink
parameter_list|(
name|struct
name|nfsrv_descript
modifier|*
name|nfsd
parameter_list|,
name|struct
name|nfssvc_sock
modifier|*
name|slp
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
name|mrq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nfsrv_write
parameter_list|(
name|struct
name|nfsrv_descript
modifier|*
name|nfsd
parameter_list|,
name|struct
name|nfssvc_sock
modifier|*
name|slp
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
name|mrq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nfsrv_rcv
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|,
name|int
name|waitflag
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nfsrv_slpderef
parameter_list|(
name|struct
name|nfssvc_sock
modifier|*
name|slp
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

