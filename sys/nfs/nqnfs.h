begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Rick Macklem at The University of Guelph.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)nqnfs.h	8.1 (Berkeley) 6/10/93  * $Id: nqnfs.h,v 1.3 1994/08/21 06:50:14 paul Exp $  */
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
name|NQNFS_VER1
value|1
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

begin_comment
comment|/*  * Definitions used for saving the "last lease expires" time in Non-volatile  * RAM on the server. The default definitions below assume that NOVRAM is not  * available.  */
end_comment

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
union|union
block|{
struct|struct
block|{
name|u_short
name|udp_flag
decl_stmt|;
name|u_short
name|udp_port
decl_stmt|;
name|union
name|nethostaddr
name|udp_haddr
decl_stmt|;
block|}
name|un_udp
struct|;
struct|struct
block|{
name|u_short
name|connless_flag
decl_stmt|;
name|u_short
name|connless_spare
decl_stmt|;
name|union
name|nethostaddr
name|connless_haddr
decl_stmt|;
block|}
name|un_connless
struct|;
struct|struct
block|{
name|u_short
name|conn_flag
decl_stmt|;
name|u_short
name|conn_spare
decl_stmt|;
name|struct
name|nfssvc_sock
modifier|*
name|conn_slp
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
name|lph_flag
value|lph_un.un_udp.udp_flag
end_define

begin_define
define|#
directive|define
name|lph_port
value|lph_un.un_udp.udp_port
end_define

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

begin_define
define|#
directive|define
name|lph_claddr
value|lph_un.un_connless.connless_haddr
end_define

begin_define
define|#
directive|define
name|lph_nam
value|lph_un.un_connless.connless_haddr.had_nam
end_define

begin_define
define|#
directive|define
name|lph_slp
value|lph_un.un_conn.conn_slp
end_define

begin_struct
struct|struct
name|nqlease
block|{
name|struct
name|nqlease
modifier|*
name|lc_chain1
index|[
literal|2
index|]
decl_stmt|;
comment|/* Timer queue list (must be first) */
name|struct
name|nqlease
modifier|*
name|lc_fhnext
decl_stmt|;
comment|/* Fhandle hash list */
name|struct
name|nqlease
modifier|*
modifier|*
name|lc_fhprev
decl_stmt|;
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
value|lc_host.lph_un.un_udp.udp_flag
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

begin_define
define|#
directive|define
name|LC_CLTP
value|0x0080
end_define

begin_comment
comment|/* Host address for other connectionless */
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
comment|/*  * Flag bits for flags argument to nqsrv_getlease.  */
end_comment

begin_define
define|#
directive|define
name|NQL_READ
value|LEASE_READ
end_define

begin_comment
comment|/* Read Request */
end_comment

begin_define
define|#
directive|define
name|NQL_WRITE
value|LEASE_WRITE
end_define

begin_comment
comment|/* Write Request */
end_comment

begin_define
define|#
directive|define
name|NQL_CHECK
value|0x4
end_define

begin_comment
comment|/* Check for lease */
end_comment

begin_define
define|#
directive|define
name|NQL_NOVAL
value|0xffffffff
end_define

begin_comment
comment|/* Invalid */
end_comment

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
value|(void) nqsrv_getlease((v),&nfsd->nd_duration, \ 		 ((nfsd->nd_nqlflag != 0&& nfsd->nd_nqlflag != NQL_NOVAL) ? nfsd->nd_nqlflag : \ 		 ((l) | NQL_CHECK)), \ 		 nfsd, nam,&cache,&frev, cred)
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
value|((time.tv_sec> (n)->n_expiry&& \  VFSTONFS((v)->v_mount)->nm_timeouts< VFSTONFS((v)->v_mount)->nm_deadthresh) \   || ((f) == NQL_WRITE&& ((n)->n_flag& NQNFSWRITE) == 0))
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
value|((time.tv_sec<= VTONFS(v)->n_expiry || \   VFSTONFS((v)->v_mount)->nm_timeouts>= VFSTONFS((v)->v_mount)->nm_deadthresh) \&& (VTONFS(v)->n_flag& NQNFSNONCACHE) == 0&& \    ((f) == NQL_READ || (VTONFS(v)->n_flag& NQNFSWRITE)))
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
value|(time.tv_sec> VTONFS(v)->n_expiry ? \ 		 ((VTONFS(v)->n_flag& NQNFSEVICTED) ? 0 : nqnfs_piggy[p]) : \ 		 (((time.tv_sec + NQ_RENEWAL)> VTONFS(v)->n_expiry&& \ 		   nqnfs_piggy[p]) ? \ 		   ((VTONFS(v)->n_flag& NQNFSWRITE) ? \ 		    NQL_WRITE : nqnfs_piggy[p]) : 0))
end_define

begin_comment
comment|/*  * List head for timer queue.  */
end_comment

begin_union
specifier|extern
union|union
name|nqsrvthead
block|{
name|union
name|nqsrvthead
modifier|*
name|th_head
index|[
literal|2
index|]
decl_stmt|;
name|struct
name|nqlease
modifier|*
name|th_chain
index|[
literal|2
index|]
decl_stmt|;
block|}
name|nqthead
union|;
end_union

begin_decl_stmt
specifier|extern
name|struct
name|nqlease
modifier|*
modifier|*
name|nqfhead
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_long
name|nqfheadhash
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

begin_define
define|#
directive|define
name|NQNFS_AUTHERR
value|502
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
name|void
name|nfs_lease_check
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
name|nfs_lease_updatetime
name|__P
argument_list|(
operator|(
name|int
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

