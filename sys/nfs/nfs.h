begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Rick Macklem at The University of Guelph.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)nfs.h	8.1 (Berkeley) 6/10/93  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NFS_NFS_H_
end_ifndef

begin_define
define|#
directive|define
name|_NFS_NFS_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|NFS
end_ifdef

begin_define
define|#
directive|define
name|NFS_SERVER
value|1
end_define

begin_define
define|#
directive|define
name|NFS_CLIENT
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NFS
value|1
end_define

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
name|NFS_MAXIOVEC
value|34
end_define

begin_define
define|#
directive|define
name|NFS_HZ
value|25
end_define

begin_comment
comment|/* Ticks per second for NFS timeouts */
end_comment

begin_define
define|#
directive|define
name|NFS_TIMEO
value|(1*NFS_HZ)
end_define

begin_comment
comment|/* Default timeout = 1 second */
end_comment

begin_define
define|#
directive|define
name|NFS_MINTIMEO
value|(1*NFS_HZ)
end_define

begin_comment
comment|/* Min timeout to use */
end_comment

begin_define
define|#
directive|define
name|NFS_MAXTIMEO
value|(60*NFS_HZ)
end_define

begin_comment
comment|/* Max timeout to backoff to */
end_comment

begin_define
define|#
directive|define
name|NFS_MINIDEMTIMEO
value|(5*NFS_HZ)
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
name|NFS_MAXWINDOW
value|1024
end_define

begin_comment
comment|/* Max number of outstanding requests */
end_comment

begin_define
define|#
directive|define
name|NFS_RETRANS
value|10
end_define

begin_comment
comment|/* Num of retrans for soft mounts */
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
value|5
end_define

begin_comment
comment|/* Attribute cache timeout in sec */
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
name|NFS_MAXREADDIR
value|NFS_MAXDATA
end_define

begin_comment
comment|/* Max. size of directory read */
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

begin_define
define|#
directive|define
name|NFS_MAXASYNCDAEMON
value|20
end_define

begin_comment
comment|/* Max. number async_daemons runable */
end_comment

begin_define
define|#
directive|define
name|NFS_DIRBLKSIZ
value|1024
end_define

begin_comment
comment|/* Size of an NFS directory block */
end_comment

begin_define
define|#
directive|define
name|NMOD
parameter_list|(
name|a
parameter_list|)
value|((a) % nfs_asyncdaemons)
end_define

begin_comment
comment|/*  * Set the attribute timeout based on how recently the file has been modified.  */
end_comment

begin_define
define|#
directive|define
name|NFS_ATTRTIMEO
parameter_list|(
name|np
parameter_list|)
define|\
value|((((np)->n_flag& NMODIFIED) || \ 	 (time.tv_sec - (np)->n_mtime) / 10< NFS_MINATTRTIMO) ? NFS_MINATTRTIMO : \ 	 ((time.tv_sec - (np)->n_mtime) / 10> NFS_MAXATTRTIMO ? NFS_MAXATTRTIMO : \ 	  (time.tv_sec - (np)->n_mtime) / 10))
end_define

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
comment|/* Client address for connection based sockets */
name|int
name|namelen
decl_stmt|;
comment|/* Length of name */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|nfsd_srvargs
block|{
name|struct
name|nfsd
modifier|*
name|nsd_nfsd
decl_stmt|;
comment|/* Pointer to in kernel nfsd struct */
name|uid_t
name|nsd_uid
decl_stmt|;
comment|/* Effective uid mapped to cred */
name|u_long
name|nsd_haddr
decl_stmt|;
comment|/* Ip address of client */
name|struct
name|ucred
name|nsd_cr
decl_stmt|;
comment|/* Cred. uid maps to */
name|int
name|nsd_authlen
decl_stmt|;
comment|/* Length of auth string (ret) */
name|char
modifier|*
name|nsd_authstr
decl_stmt|;
comment|/* Auth string (ret) */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|nfsd_cargs
block|{
name|char
modifier|*
name|ncd_dirp
decl_stmt|;
comment|/* Mount dir path */
name|uid_t
name|ncd_authuid
decl_stmt|;
comment|/* Effective uid */
name|int
name|ncd_authtype
decl_stmt|;
comment|/* Type of authenticator */
name|int
name|ncd_authlen
decl_stmt|;
comment|/* Length of authenticator string */
name|char
modifier|*
name|ncd_authstr
decl_stmt|;
comment|/* Authenticator string */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Stats structure  */
end_comment

begin_struct
struct|struct
name|nfsstats
block|{
name|int
name|attrcache_hits
decl_stmt|;
name|int
name|attrcache_misses
decl_stmt|;
name|int
name|lookupcache_hits
decl_stmt|;
name|int
name|lookupcache_misses
decl_stmt|;
name|int
name|direofcache_hits
decl_stmt|;
name|int
name|direofcache_misses
decl_stmt|;
name|int
name|biocache_reads
decl_stmt|;
name|int
name|read_bios
decl_stmt|;
name|int
name|read_physios
decl_stmt|;
name|int
name|biocache_writes
decl_stmt|;
name|int
name|write_bios
decl_stmt|;
name|int
name|write_physios
decl_stmt|;
name|int
name|biocache_readlinks
decl_stmt|;
name|int
name|readlink_bios
decl_stmt|;
name|int
name|biocache_readdirs
decl_stmt|;
name|int
name|readdir_bios
decl_stmt|;
name|int
name|rpccnt
index|[
name|NFS_NPROCS
index|]
decl_stmt|;
name|int
name|rpcretries
decl_stmt|;
name|int
name|srvrpccnt
index|[
name|NFS_NPROCS
index|]
decl_stmt|;
name|int
name|srvrpc_errs
decl_stmt|;
name|int
name|srv_errs
decl_stmt|;
name|int
name|rpcrequests
decl_stmt|;
name|int
name|rpctimeouts
decl_stmt|;
name|int
name|rpcunexpected
decl_stmt|;
name|int
name|rpcinvalid
decl_stmt|;
name|int
name|srvcache_inproghits
decl_stmt|;
name|int
name|srvcache_idemdonehits
decl_stmt|;
name|int
name|srvcache_nonidemdonehits
decl_stmt|;
name|int
name|srvcache_misses
decl_stmt|;
name|int
name|srvnqnfs_leases
decl_stmt|;
name|int
name|srvnqnfs_maxleases
decl_stmt|;
name|int
name|srvnqnfs_getleases
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Flags for nfssvc() system call.  */
end_comment

begin_define
define|#
directive|define
name|NFSSVC_BIOD
value|0x002
end_define

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

begin_define
define|#
directive|define
name|NFSSVC_AUTHIN
value|0x010
end_define

begin_define
define|#
directive|define
name|NFSSVC_GOTAUTH
value|0x040
end_define

begin_define
define|#
directive|define
name|NFSSVC_AUTHINFAIL
value|0x080
end_define

begin_define
define|#
directive|define
name|NFSSVC_MNTD
value|0x100
end_define

begin_comment
comment|/*  * fs.nfs sysctl(3) identifiers  */
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

begin_define
define|#
directive|define
name|FS_NFS_NAMES
value|{ \ 		       { 0, 0 }, \ 		       { "nfsstats", CTLTYPE_STRUCT }, \ }
end_define

begin_comment
comment|/*  * The set of signals the interrupt an I/O in progress for NFSMNT_INT mounts.  * What should be in this set is open to debate, but I believe that since  * I/O system calls on ufs are never interrupted by signals the set should  * be minimal. My reasoning is that many current programs that use signals  * such as SIGALRM will not expect file I/O system calls to be interrupted  * by them and break.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_struct_decl
struct_decl|struct
name|uio
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|buf
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

begin_comment
comment|/* XXX */
end_comment

begin_define
define|#
directive|define
name|NFSINT_SIGMASK
value|(sigmask(SIGINT)|sigmask(SIGTERM)|sigmask(SIGKILL)| \ 			 sigmask(SIGHUP)|sigmask(SIGQUIT))
end_define

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
value|((e) != EINTR&& (e) != ERESTART&& (e) != EWOULDBLOCK&& \ 		((s)& PR_CONNREQUIRED) == 0)
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
name|u_long
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
name|int
name|r_procnum
decl_stmt|;
comment|/* NFS procedure number */
name|int
name|r_rtt
decl_stmt|;
comment|/* RTT for rpc */
name|struct
name|proc
modifier|*
name|r_procp
decl_stmt|;
comment|/* Proc that did I/O system call */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Queue head for nfsreq's  */
end_comment

begin_macro
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|nfsreq
argument_list|)
end_macro

begin_expr_stmt
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
name|R_INTR
value|0x08
end_define

begin_comment
comment|/* intr mnt, signal pending */
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

begin_decl_stmt
specifier|extern
name|struct
name|nfsstats
name|nfsstats
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * A list of nfssvc_sock structures is maintained with all the sockets  * that require service by the nfsd.  * The nfsuid structs hang off of the nfssvc_sock structs in both lru  * and uid hash lists.  */
end_comment

begin_define
define|#
directive|define
name|NUIDHASHSIZ
value|32
end_define

begin_define
define|#
directive|define
name|NUIDHASH
parameter_list|(
name|sock
parameter_list|,
name|uid
parameter_list|)
define|\
value|(&(sock)->ns_uidhashtbl[(uid)& (sock)->ns_uidhash])
end_define

begin_comment
comment|/*  * Network address hash list element  */
end_comment

begin_union
union|union
name|nethostaddr
block|{
name|u_long
name|had_inetaddr
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|had_nam
decl_stmt|;
block|}
union|;
end_union

begin_struct
struct|struct
name|nfsuid
block|{
name|TAILQ_ENTRY
argument_list|(
argument|nfsuid
argument_list|)
name|nu_lru
expr_stmt|;
comment|/* LRU chain */
name|LIST_ENTRY
argument_list|(
argument|nfsuid
argument_list|)
name|nu_hash
expr_stmt|;
comment|/* Hash list */
name|int
name|nu_flag
decl_stmt|;
comment|/* Flags */
name|uid_t
name|nu_uid
decl_stmt|;
comment|/* Uid mapped by this entry */
name|union
name|nethostaddr
name|nu_haddr
decl_stmt|;
comment|/* Host addr. for dgram sockets */
name|struct
name|ucred
name|nu_cr
decl_stmt|;
comment|/* Cred uid mapped to */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|nu_inetaddr
value|nu_haddr.had_inetaddr
end_define

begin_define
define|#
directive|define
name|nu_nam
value|nu_haddr.had_nam
end_define

begin_comment
comment|/* Bits for nu_flag */
end_comment

begin_define
define|#
directive|define
name|NU_INETADDR
value|0x1
end_define

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
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|nfsuid
argument_list|)
name|ns_uidlruhead
expr_stmt|;
name|LIST_HEAD
argument_list|(,
name|nfsuid
argument_list|)
operator|*
name|ns_uidhashtbl
expr_stmt|;
name|u_long
name|ns_uidhash
decl_stmt|;
name|int
name|ns_flag
decl_stmt|;
name|u_long
name|ns_sref
decl_stmt|;
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
name|int
name|ns_solock
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|ns_nam
decl_stmt|;
name|int
name|ns_cc
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
name|int
name|ns_reclen
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|ns_rec
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|ns_recend
decl_stmt|;
name|int
name|ns_numuids
decl_stmt|;
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

begin_define
define|#
directive|define
name|SLP_DOREC
value|0x02
end_define

begin_define
define|#
directive|define
name|SLP_NEEDQ
value|0x04
end_define

begin_define
define|#
directive|define
name|SLP_DISCONN
value|0x08
end_define

begin_define
define|#
directive|define
name|SLP_GETSTREAM
value|0x10
end_define

begin_define
define|#
directive|define
name|SLP_ALLFLAGS
value|0xff
end_define

begin_macro
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|nfssvc_sock
argument_list|)
end_macro

begin_expr_stmt
name|nfssvc_sockhead
expr_stmt|;
end_expr_stmt

begin_decl_stmt
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
name|nd_chain
expr_stmt|;
comment|/* List of all nfsd's */
name|int
name|nd_flag
decl_stmt|;
comment|/* NFSD_ flags */
name|struct
name|nfssvc_sock
modifier|*
name|nd_slp
decl_stmt|;
comment|/* Current socket */
name|struct
name|mbuf
modifier|*
name|nd_nam
decl_stmt|;
comment|/* Client addr for datagram req. */
name|struct
name|mbuf
modifier|*
name|nd_mrep
decl_stmt|;
comment|/* Req. mbuf list */
name|struct
name|mbuf
modifier|*
name|nd_md
decl_stmt|;
name|caddr_t
name|nd_dpos
decl_stmt|;
comment|/* Position in list */
name|int
name|nd_procnum
decl_stmt|;
comment|/* RPC procedure number */
name|u_long
name|nd_retxid
decl_stmt|;
comment|/* RPC xid */
name|int
name|nd_repstat
decl_stmt|;
comment|/* Reply status value */
name|struct
name|ucred
name|nd_cr
decl_stmt|;
comment|/* Credentials for req. */
name|int
name|nd_nqlflag
decl_stmt|;
comment|/* Leasing flag */
name|u_long
name|nd_duration
decl_stmt|;
comment|/* Lease duration */
name|int
name|nd_authlen
decl_stmt|;
comment|/* Authenticator len */
name|u_char
name|nd_authstr
index|[
name|RPCAUTH_MAXSIZ
index|]
decl_stmt|;
comment|/* Authenticator data */
name|struct
name|proc
modifier|*
name|nd_procp
decl_stmt|;
comment|/* Proc ptr */
block|}
struct|;
end_struct

begin_comment
comment|/* Bits for "nd_flag" */
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

begin_define
define|#
directive|define
name|NFSD_NEEDAUTH
value|0x04
end_define

begin_define
define|#
directive|define
name|NFSD_AUTHFAIL
value|0x08
end_define

begin_macro
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|nfsd
argument_list|)
end_macro

begin_expr_stmt
name|nfsd_head
expr_stmt|;
end_expr_stmt

begin_decl_stmt
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

begin_decl_stmt
name|int
name|nfs_reply
name|__P
argument_list|(
operator|(
expr|struct
name|nfsreq
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nfs_getreq
name|__P
argument_list|(
operator|(
expr|struct
name|nfsd
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nfs_send
name|__P
argument_list|(
operator|(
expr|struct
name|socket
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
expr|struct
name|nfsreq
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nfs_rephead
name|__P
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|nfsd
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|u_quad_t
operator|*
operator|,
expr|struct
name|mbuf
operator|*
operator|*
operator|,
expr|struct
name|mbuf
operator|*
operator|*
operator|,
name|caddr_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nfs_sndlock
name|__P
argument_list|(
operator|(
name|int
operator|*
operator|,
expr|struct
name|nfsreq
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nfs_disct
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
operator|*
operator|,
name|caddr_t
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|caddr_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nfs_vinvalbuf
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
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nfs_readrpc
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
operator|,
expr|struct
name|uio
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
name|nfs_writerpc
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
operator|,
expr|struct
name|uio
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
name|int
name|nfs_readdirrpc
name|__P
argument_list|(
operator|(
specifier|register
expr|struct
name|vnode
operator|*
operator|,
expr|struct
name|uio
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
name|nfs_asyncio
name|__P
argument_list|(
operator|(
expr|struct
name|buf
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
name|nfs_doio
name|__P
argument_list|(
operator|(
expr|struct
name|buf
operator|*
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
name|nfs_readlinkrpc
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
operator|,
expr|struct
name|uio
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
name|nfs_sigintr
name|__P
argument_list|(
operator|(
expr|struct
name|nfsmount
operator|*
operator|,
expr|struct
name|nfsreq
operator|*
name|r
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
name|nfs_readdirlookrpc
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
operator|,
specifier|register
expr|struct
name|uio
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
name|nfsm_disct
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
operator|*
operator|,
name|caddr_t
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|caddr_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nfsrv_fhtovp
name|__P
argument_list|(
operator|(
name|fhandle_t
operator|*
operator|,
name|int
operator|,
expr|struct
name|vnode
operator|*
operator|*
operator|,
expr|struct
name|ucred
operator|*
operator|,
expr|struct
name|nfssvc_sock
operator|*
operator|,
expr|struct
name|mbuf
operator|*
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nfsrv_access
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
name|int
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
name|netaddr_match
name|__P
argument_list|(
operator|(
name|int
operator|,
expr|union
name|nethostaddr
operator|*
operator|,
expr|struct
name|mbuf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nfs_request
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
operator|,
expr|struct
name|mbuf
operator|*
operator|,
name|int
operator|,
expr|struct
name|proc
operator|*
operator|,
expr|struct
name|ucred
operator|*
operator|,
expr|struct
name|mbuf
operator|*
operator|*
operator|,
expr|struct
name|mbuf
operator|*
operator|*
operator|,
name|caddr_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nfs_loadattrcache
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
operator|*
operator|,
expr|struct
name|mbuf
operator|*
operator|*
operator|,
name|caddr_t
operator|*
operator|,
expr|struct
name|vattr
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nfs_namei
name|__P
argument_list|(
operator|(
expr|struct
name|nameidata
operator|*
operator|,
name|fhandle_t
operator|*
operator|,
name|int
operator|,
expr|struct
name|nfssvc_sock
operator|*
operator|,
expr|struct
name|mbuf
operator|*
operator|,
expr|struct
name|mbuf
operator|*
operator|*
operator|,
name|caddr_t
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
name|void
name|nfsm_adj
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nfsm_mbuftouio
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
operator|*
operator|,
expr|struct
name|uio
operator|*
operator|,
name|int
operator|,
name|caddr_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|nfsrv_initcache
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
name|nfs_rcvlock
name|__P
argument_list|(
operator|(
expr|struct
name|nfsreq
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nfs_getauth
name|__P
argument_list|(
operator|(
expr|struct
name|nfsmount
operator|*
operator|,
expr|struct
name|nfsreq
operator|*
operator|,
expr|struct
name|ucred
operator|*
operator|,
name|int
operator|*
operator|,
name|char
operator|*
operator|*
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nfs_msg
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nfs_adv
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
operator|*
operator|,
name|caddr_t
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nfsrv_getstream
name|__P
argument_list|(
operator|(
expr|struct
name|nfssvc_sock
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|nfs_nhinit
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|nfs_timer
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|nfsnodehashhead
modifier|*
name|nfs_hash
name|__P
argument_list|(
operator|(
name|nfsv2fh_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nfssvc_iod
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
name|nfssvc_nfsd
name|__P
argument_list|(
operator|(
expr|struct
name|nfsd_srvargs
operator|*
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

begin_decl_stmt
name|int
name|nfssvc_addsock
name|__P
argument_list|(
operator|(
expr|struct
name|file
operator|*
operator|,
expr|struct
name|mbuf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nfsrv_dorec
name|__P
argument_list|(
operator|(
expr|struct
name|nfssvc_sock
operator|*
operator|,
expr|struct
name|nfsd
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nfsrv_getcache
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
operator|,
expr|struct
name|nfsd
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
name|void
name|nfsrv_updatecache
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
operator|,
expr|struct
name|nfsd
operator|*
operator|,
name|int
operator|,
expr|struct
name|mbuf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|mountnfs
name|__P
argument_list|(
operator|(
expr|struct
name|nfs_args
operator|*
operator|,
expr|struct
name|mount
operator|*
operator|,
expr|struct
name|mbuf
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
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
name|nfs_connect
name|__P
argument_list|(
operator|(
expr|struct
name|nfsmount
operator|*
operator|,
expr|struct
name|nfsreq
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nfs_getattrcache
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
operator|,
expr|struct
name|vattr
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nfsm_strtmbuf
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
operator|*
operator|,
name|char
operator|*
operator|*
operator|,
name|char
operator|*
operator|,
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nfs_bioread
name|__P
argument_list|(
operator|(
expr|struct
name|vnode
operator|*
operator|,
expr|struct
name|uio
operator|*
operator|,
name|int
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
name|nfsm_uiotombuf
name|__P
argument_list|(
operator|(
expr|struct
name|uio
operator|*
operator|,
expr|struct
name|mbuf
operator|*
operator|*
operator|,
name|int
operator|,
name|caddr_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|nfsrv_init
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
name|nfsrv_vput
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
name|nfsrv_vrele
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
name|nfsrv_vmio
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

