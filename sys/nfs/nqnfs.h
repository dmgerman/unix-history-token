begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Rick Macklem at The University of Guelph.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)nqnfs.h	8.3 (Berkeley) 3/30/95  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NFS_NQNFS_H_
end_ifndef

begin_define
define|#
directive|define
name|_NFS_NQNFS_H_
end_define

begin_comment
comment|/*  * Definitions for NQNFS (Not Quite NFS) cache consistency protocol.  */
end_comment

begin_comment
comment|/* Tunable constants */
end_comment

begin_define
define|#
directive|define
name|NQ_CLOCKSKEW
value|3
end_define

begin_comment
comment|/* Clock skew factor (sec) */
end_comment

begin_define
define|#
directive|define
name|NQ_WRITESLACK
value|5
end_define

begin_comment
comment|/* Delay for write cache flushing */
end_comment

begin_define
define|#
directive|define
name|NQ_MAXLEASE
value|60
end_define

begin_comment
comment|/* Max lease duration (sec) */
end_comment

begin_define
define|#
directive|define
name|NQ_MINLEASE
value|5
end_define

begin_comment
comment|/* Min lease duration (sec) */
end_comment

begin_define
define|#
directive|define
name|NQ_DEFLEASE
value|30
end_define

begin_comment
comment|/* Default lease duration (sec) */
end_comment

begin_define
define|#
directive|define
name|NQ_RENEWAL
value|3
end_define

begin_comment
comment|/* Time before expiry (sec) to renew */
end_comment

begin_define
define|#
directive|define
name|NQ_TRYLATERDEL
value|15
end_define

begin_comment
comment|/* Initial try later delay (sec) */
end_comment

begin_define
define|#
directive|define
name|NQ_MAXNUMLEASE
value|2048
end_define

begin_comment
comment|/* Upper bound on number of server leases */
end_comment

begin_define
define|#
directive|define
name|NQ_DEADTHRESH
value|NQ_NEVERDEAD
end_define

begin_comment
comment|/* Default nm_deadthresh */
end_comment

begin_define
define|#
directive|define
name|NQ_NEVERDEAD
value|9
end_define

begin_comment
comment|/* Greater than max. nm_timeouts */
end_comment

begin_define
define|#
directive|define
name|NQLCHSZ
value|256
end_define

begin_comment
comment|/* Server hash table size */
end_comment

begin_define
define|#
directive|define
name|NQNFS_PROG
value|300105
end_define

begin_comment
comment|/* As assigned by Sun */
end_comment

begin_define
define|#
directive|define
name|NQNFS_VER3
value|3
end_define

begin_define
define|#
directive|define
name|NQNFS_EVICTSIZ
value|156
end_define

begin_comment
comment|/* Size of eviction request in bytes */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_KERNEL
argument_list|)
end_if

begin_comment
comment|/*  * Definitions used for saving the "last lease expires" time in Non-volatile  * RAM on the server. The default definitions below assume that NOVRAM is not  * available.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HASNVRAM
end_ifdef

begin_undef
undef|#
directive|undef
name|HASNVRAM
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|NQSTORENOVRAM
parameter_list|(
name|t
parameter_list|)
end_define

begin_define
define|#
directive|define
name|NQLOADNOVRAM
parameter_list|(
name|t
parameter_list|)
end_define

begin_comment
comment|/*  * Defn and structs used on the server to maintain state for current leases.  * The list of host(s) that hold the lease are kept as nqhost structures.  * The first one lives in nqlease and any others are held in a linked  * list of nqm structures hanging off of nqlease.  *  * Each nqlease structure is chained into two lists. The first is a list  * ordered by increasing expiry time for nqsrv_timer() and the second is a chain  * hashed on lc_fh.  */
end_comment

begin_define
define|#
directive|define
name|LC_MOREHOSTSIZ
value|10
end_define

begin_struct
struct|struct
name|nqhost
block|{
name|u_int16_t
name|lph_flag
decl_stmt|;
name|u_int16_t
name|lph_port
decl_stmt|;
name|struct
name|nfssvc_sock
modifier|*
name|lph_slp
decl_stmt|;
union|union
block|{
struct|struct
block|{
name|union
name|nethostaddr
name|udp_haddr
decl_stmt|;
block|}
name|un_udp
struct|;
struct|struct
block|{
name|int
name|dummy
decl_stmt|;
block|}
name|un_conn
struct|;
block|}
name|lph_un
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|lph_haddr
value|lph_un.un_udp.udp_haddr
end_define

begin_define
define|#
directive|define
name|lph_inetaddr
value|lph_un.un_udp.udp_haddr.had_inetaddr
end_define

begin_struct
struct|struct
name|nqlease
block|{
name|LIST_ENTRY
argument_list|(
argument|nqlease
argument_list|)
name|lc_hash
expr_stmt|;
comment|/* Fhandle hash list */
name|CIRCLEQ_ENTRY
argument_list|(
argument|nqlease
argument_list|)
name|lc_timer
expr_stmt|;
comment|/* Timer queue list */
name|time_t
name|lc_expiry
decl_stmt|;
comment|/* Expiry time (sec) */
name|struct
name|nqhost
name|lc_host
decl_stmt|;
comment|/* Host that got lease */
name|struct
name|nqm
modifier|*
name|lc_morehosts
decl_stmt|;
comment|/* Other hosts that share read lease */
name|fsid_t
name|lc_fsid
decl_stmt|;
comment|/* Fhandle */
name|char
name|lc_fiddata
index|[
name|MAXFIDSZ
index|]
decl_stmt|;
name|struct
name|vnode
modifier|*
name|lc_vp
decl_stmt|;
comment|/* Soft reference to associated vnode */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|lc_flag
value|lc_host.lph_flag
end_define

begin_comment
comment|/* lc_flag bits */
end_comment

begin_define
define|#
directive|define
name|LC_VALID
value|0x0001
end_define

begin_comment
comment|/* Host address valid */
end_comment

begin_define
define|#
directive|define
name|LC_WRITE
value|0x0002
end_define

begin_comment
comment|/* Write cache */
end_comment

begin_define
define|#
directive|define
name|LC_NONCACHABLE
value|0x0004
end_define

begin_comment
comment|/* Non-cachable lease */
end_comment

begin_define
define|#
directive|define
name|LC_LOCKED
value|0x0008
end_define

begin_comment
comment|/* Locked */
end_comment

begin_define
define|#
directive|define
name|LC_WANTED
value|0x0010
end_define

begin_comment
comment|/* Lock wanted */
end_comment

begin_define
define|#
directive|define
name|LC_EXPIREDWANTED
value|0x0020
end_define

begin_comment
comment|/* Want lease when expired */
end_comment

begin_define
define|#
directive|define
name|LC_UDP
value|0x0040
end_define

begin_comment
comment|/* Host address for udp socket */
end_comment

begin_comment
comment|/* 0x0080 free */
end_comment

begin_define
define|#
directive|define
name|LC_LOCAL
value|0x0100
end_define

begin_comment
comment|/* Host is server */
end_comment

begin_define
define|#
directive|define
name|LC_VACATED
value|0x0200
end_define

begin_comment
comment|/* Host has vacated lease */
end_comment

begin_define
define|#
directive|define
name|LC_WRITTEN
value|0x0400
end_define

begin_comment
comment|/* Recently wrote to the leased file */
end_comment

begin_define
define|#
directive|define
name|LC_SREF
value|0x0800
end_define

begin_comment
comment|/* Holds a nfssvc_sock reference */
end_comment

begin_struct
struct|struct
name|nqm
block|{
name|struct
name|nqm
modifier|*
name|lpm_next
decl_stmt|;
name|struct
name|nqhost
name|lpm_hosts
index|[
name|LC_MOREHOSTSIZ
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Special value for slp for local server calls.  */
end_comment

begin_define
define|#
directive|define
name|NQLOCALSLP
value|((struct nfssvc_sock *) -1)
end_define

begin_comment
comment|/*  * Server side macros.  */
end_comment

begin_define
define|#
directive|define
name|nqsrv_getl
parameter_list|(
name|v
parameter_list|,
name|l
parameter_list|)
define|\
value|(void) nqsrv_getlease((v),&nfsd->nd_duration, \ 		 ((nfsd->nd_flag& ND_LEASE) ? (nfsd->nd_flag& ND_LEASE) : \ 		 ((l) | ND_CHECK)), \ 		 slp, procp, nfsd->nd_nam,&cache,&frev, cred)
end_define

begin_comment
comment|/*  * Client side macros that check for a valid lease.  */
end_comment

begin_define
define|#
directive|define
name|NQNFS_CKINVALID
parameter_list|(
name|v
parameter_list|,
name|n
parameter_list|,
name|f
parameter_list|)
define|\
value|((time_second> (n)->n_expiry&& \  VFSTONFS((v)->v_mount)->nm_timeouts< VFSTONFS((v)->v_mount)->nm_deadthresh) \   || ((f) == ND_WRITE&& ((n)->n_flag& NQNFSWRITE) == 0))
end_define

begin_define
define|#
directive|define
name|NQNFS_CKCACHABLE
parameter_list|(
name|v
parameter_list|,
name|f
parameter_list|)
define|\
value|((time_second<= VTONFS(v)->n_expiry || \   VFSTONFS((v)->v_mount)->nm_timeouts>= VFSTONFS((v)->v_mount)->nm_deadthresh) \&& (VTONFS(v)->n_flag& NQNFSNONCACHE) == 0&& \    ((f) == ND_READ || (VTONFS(v)->n_flag& NQNFSWRITE)))
end_define

begin_define
define|#
directive|define
name|NQNFS_NEEDLEASE
parameter_list|(
name|v
parameter_list|,
name|p
parameter_list|)
define|\
value|(time_second> VTONFS(v)->n_expiry ? \ 		 ((VTONFS(v)->n_flag& NQNFSEVICTED) ? 0 : nqnfs_piggy[p]) : \ 		 (((time_second + NQ_RENEWAL)> VTONFS(v)->n_expiry&& \ 		   nqnfs_piggy[p]) ? \ 		   ((VTONFS(v)->n_flag& NQNFSWRITE) ? \ 		    ND_WRITE : nqnfs_piggy[p]) : 0))
end_define

begin_comment
comment|/*  * List head for timer queue.  */
end_comment

begin_extern
extern|extern CIRCLEQ_HEAD(nqtimerhead
operator|,
extern|nqlease
end_extern

begin_expr_stmt
unit|)
name|nqtimerhead
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * List head for the file handle hash table.  */
end_comment

begin_define
define|#
directive|define
name|NQFHHASH
parameter_list|(
name|f
parameter_list|)
define|\
value|(&nqfhhashtbl[(*((u_int32_t *)(f)))& nqfhhash])
end_define

begin_extern
extern|extern LIST_HEAD(nqfhhashhead
operator|,
extern|nqlease
end_extern

begin_expr_stmt
unit|)
operator|*
name|nqfhhashtbl
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|extern
name|u_long
name|nqfhhash
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Nqnfs return status numbers.  */
end_comment

begin_define
define|#
directive|define
name|NQNFS_EXPIRED
value|500
end_define

begin_define
define|#
directive|define
name|NQNFS_TRYLATER
value|501
end_define

begin_decl_stmt
name|void
name|nqnfs_lease_check
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
operator|,
expr|struct
name|proc
operator|*
operator|,
expr|struct
name|ucred
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|nqnfs_lease_updatetime
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nqsrv_getlease
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
operator|,
name|u_int32_t
operator|*
operator|,
name|int
operator|,
expr|struct
name|nfssvc_sock
operator|*
operator|,
expr|struct
name|proc
operator|*
operator|,
expr|struct
name|sockaddr
operator|*
operator|,
name|int
operator|*
operator|,
name|u_quad_t
operator|*
operator|,
expr|struct
name|ucred
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nqnfs_getlease
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
operator|,
name|int
operator|,
expr|struct
name|ucred
operator|*
operator|,
expr|struct
name|proc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nqnfs_callback
name|__P
argument_list|(
operator|(
expr|struct
name|nfsmount
operator|*
operator|,
expr|struct
name|mbuf
operator|*
operator|,
expr|struct
name|mbuf
operator|*
operator|,
name|caddr_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nqnfs_clientd
name|__P
argument_list|(
operator|(
expr|struct
name|nfsmount
operator|*
operator|,
expr|struct
name|ucred
operator|*
operator|,
expr|struct
name|nfsd_cargs
operator|*
operator|,
name|int
operator|,
name|caddr_t
operator|,
expr|struct
name|proc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_struct_decl
struct_decl|struct
name|nfsnode
struct_decl|;
end_struct_decl

begin_decl_stmt
name|void
name|nqnfs_clientlease
name|__P
argument_list|(
operator|(
expr|struct
name|nfsmount
operator|*
operator|,
expr|struct
name|nfsnode
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|time_t
operator|,
name|u_quad_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|nqnfs_serverd
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nqnfsrv_getlease
name|__P
argument_list|(
operator|(
expr|struct
name|nfsrv_descript
operator|*
operator|,
expr|struct
name|nfssvc_sock
operator|*
operator|,
expr|struct
name|proc
operator|*
operator|,
expr|struct
name|mbuf
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nqnfsrv_vacated
name|__P
argument_list|(
operator|(
expr|struct
name|nfsrv_descript
operator|*
operator|,
expr|struct
name|nfssvc_sock
operator|*
operator|,
expr|struct
name|proc
operator|*
operator|,
expr|struct
name|mbuf
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

