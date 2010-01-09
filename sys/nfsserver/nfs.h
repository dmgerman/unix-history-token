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

begin_include
include|#
directive|include
file|<nfs/nfssvc.h>
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
comment|/*  * Structures for the nfssvc(2) syscall.  Not that anyone but nfsd and  * mount_nfs should ever try and use it.  */
end_comment

begin_comment
comment|/*  * Add a socket to monitor for NFS requests.  */
end_comment

begin_struct
struct|struct
name|nfsd_addsock_args
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
comment|/*  * Start processing requests.  */
end_comment

begin_struct
struct|struct
name|nfsd_nfsd_args
block|{
specifier|const
name|char
modifier|*
name|principal
decl_stmt|;
comment|/* GSS-API service principal name */
name|int
name|minthreads
decl_stmt|;
comment|/* minimum service thread count */
name|int
name|maxthreads
decl_stmt|;
comment|/* maximum service thread count */
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
comment|/*  * This structure is used by the server for describing each request.  */
end_comment

begin_struct
struct|struct
name|nfsrv_descript
block|{
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
name|nd_repstat
decl_stmt|;
comment|/* Reply status */
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
name|int
name|nd_credflavor
decl_stmt|;
comment|/* Security flavor */
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
name|void
name|nfs_realign
parameter_list|(
name|struct
name|mbuf
modifier|*
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
name|nfs_namei
parameter_list|(
name|struct
name|nameidata
modifier|*
parameter_list|,
name|struct
name|nfsrv_descript
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
name|int
modifier|*
parameter_list|,
name|struct
name|nfsrv_descript
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
name|mbuf
modifier|*
modifier|*
name|mrq
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * #ifdef _SYS_SYSPROTO_H_ so that it is only defined when sysproto.h  * has been included, so that "struct nfssvc_args" is defined.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_SYS_SYSPROTO_H_
end_ifdef

begin_function_decl
name|int
name|nfssvc_nfsserver
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|struct
name|nfssvc_args
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

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

