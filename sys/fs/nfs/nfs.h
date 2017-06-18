begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Rick Macklem at The University of Guelph.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
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
name|NFS_TICKINTVL
value|500
end_define

begin_comment
comment|/* Desired time for a tick (msec) */
end_comment

begin_define
define|#
directive|define
name|NFS_HZ
value|(hz / nfscl_ticks)
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
name|NFS_TCPTIMEO
value|300
end_define

begin_comment
comment|/* TCP timeout */
end_comment

begin_define
define|#
directive|define
name|NFS_MAXRCVTIMEO
value|60
end_define

begin_comment
comment|/* 1 minute in seconds */
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
name|NFSV4_CALLBACKTIMEO
value|(2 * NFS_HZ)
end_define

begin_comment
comment|/* Timeout in ticks */
end_comment

begin_define
define|#
directive|define
name|NFSV4_CALLBACKRETRY
value|5
end_define

begin_comment
comment|/* Number of retries before failure */
end_comment

begin_define
define|#
directive|define
name|NFSV4_SLOTS
value|64
end_define

begin_comment
comment|/* Number of slots, fore channel */
end_comment

begin_define
define|#
directive|define
name|NFSV4_CBSLOTS
value|8
end_define

begin_comment
comment|/* Number of slots, back channel */
end_comment

begin_define
define|#
directive|define
name|NFSV4_CBRETRYCNT
value|4
end_define

begin_comment
comment|/* # of CBRecall retries upon err */
end_comment

begin_define
define|#
directive|define
name|NFSV4_UPCALLTIMEO
value|(15 * NFS_HZ)
end_define

begin_comment
comment|/* Timeout in ticks for upcalls */
end_comment

begin_comment
comment|/* to gssd or nfsuserd */
end_comment

begin_define
define|#
directive|define
name|NFSV4_UPCALLRETRY
value|4
end_define

begin_comment
comment|/* Number of retries before failure */
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

begin_define
define|#
directive|define
name|NFS_TRYLATERDEL
value|15
end_define

begin_comment
comment|/* Maximum delay timeout (sec) */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NFS_REMOVETIMEO
end_ifndef

begin_define
define|#
directive|define
name|NFS_REMOVETIMEO
value|15
end_define

begin_comment
comment|/* # sec to wait for delegret in local syscall */
end_comment

begin_endif
endif|#
directive|endif
end_endif

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
value|16
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
name|NFS_MAXUIDHASH
value|64
end_define

begin_comment
comment|/* Max. # of hashed uid entries/mp */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NFSRV_LEASE
end_ifndef

begin_define
define|#
directive|define
name|NFSRV_LEASE
value|120
end_define

begin_comment
comment|/* Lease time in seconds for V4 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* assigned to nfsrv_lease */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NFSRV_STALELEASE
end_ifndef

begin_define
define|#
directive|define
name|NFSRV_STALELEASE
value|(5 * nfsrv_lease)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NFSRV_MOULDYLEASE
end_ifndef

begin_define
define|#
directive|define
name|NFSRV_MOULDYLEASE
value|604800
end_define

begin_comment
comment|/* One week (in sec) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NFSCLIENTHASHSIZE
end_ifndef

begin_define
define|#
directive|define
name|NFSCLIENTHASHSIZE
value|20
end_define

begin_comment
comment|/* Size of server client hash table */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NFSLOCKHASHSIZE
end_ifndef

begin_define
define|#
directive|define
name|NFSLOCKHASHSIZE
value|20
end_define

begin_comment
comment|/* Size of server nfslock hash table */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NFSSESSIONHASHSIZE
end_ifndef

begin_define
define|#
directive|define
name|NFSSESSIONHASHSIZE
value|20
end_define

begin_comment
comment|/* Size of server session hash table */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|NFSSTATEHASHSIZE
value|10
end_define

begin_comment
comment|/* Size of server stateid hash table */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NFSCLDELEGHIGHWATER
end_ifndef

begin_define
define|#
directive|define
name|NFSCLDELEGHIGHWATER
value|10000
end_define

begin_comment
comment|/* limit for client delegations */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NFSCLLAYOUTHIGHWATER
end_ifndef

begin_define
define|#
directive|define
name|NFSCLLAYOUTHIGHWATER
value|10000
end_define

begin_comment
comment|/* limit for client pNFS layouts */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NFSNOOPEN
end_ifndef

begin_comment
comment|/* Inactive open owner (sec) */
end_comment

begin_define
define|#
directive|define
name|NFSNOOPEN
value|120
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|NFSRV_LEASEDELTA
value|15
end_define

begin_comment
comment|/* # of seconds to delay beyond lease */
end_comment

begin_define
define|#
directive|define
name|NFS_IDMAXSIZE
value|4
end_define

begin_comment
comment|/* max sizeof (in_addr_t) */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NFSRVCACHE_UDPTIMEOUT
end_ifndef

begin_define
define|#
directive|define
name|NFSRVCACHE_UDPTIMEOUT
value|30
end_define

begin_comment
comment|/* # of sec to hold cached rpcs(udp) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NFSRVCACHE_UDPHIGHWATER
end_ifndef

begin_define
define|#
directive|define
name|NFSRVCACHE_UDPHIGHWATER
value|500
end_define

begin_comment
comment|/* Max # of udp cache entries */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NFSRVCACHE_TCPTIMEOUT
end_ifndef

begin_define
define|#
directive|define
name|NFSRVCACHE_TCPTIMEOUT
value|(3600*12)
end_define

begin_comment
comment|/*#of sec to hold cached rpcs(tcp) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NFSRVCACHE_FLOODLEVEL
end_ifndef

begin_define
define|#
directive|define
name|NFSRVCACHE_FLOODLEVEL
value|16384
end_define

begin_comment
comment|/* Very high water mark for cache */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NFSRV_CLIENTHIGHWATER
end_ifndef

begin_define
define|#
directive|define
name|NFSRV_CLIENTHIGHWATER
value|1000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NFSRV_MAXDUMPLIST
end_ifndef

begin_define
define|#
directive|define
name|NFSRV_MAXDUMPLIST
value|10000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NFS_ACCESSCACHESIZE
end_ifndef

begin_define
define|#
directive|define
name|NFS_ACCESSCACHESIZE
value|8
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|NFSV4_CBPORT
value|7745
end_define

begin_comment
comment|/* Callback port for testing */
end_comment

begin_comment
comment|/*  * This macro defines the high water mark for issuing V4 delegations.  * (It is currently set at a conservative 20% of nfsrv_v4statelimit. This  *  may want to increase when clients can make more effective use of  *  delegations.)  */
end_comment

begin_define
define|#
directive|define
name|NFSRV_V4DELEGLIMIT
parameter_list|(
name|c
parameter_list|)
value|(((c) * 5)> nfsrv_v4statelimit)
end_define

begin_define
define|#
directive|define
name|NFS_READDIRBLKSIZ
value|DIRBLKSIZ
end_define

begin_comment
comment|/* Minimal nm_readdirsize */
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
value|((n)->n_fhp->nfh_len == (s)&& !NFSBCMP((n)->n_fhp->nfh_fh, (caddr_t)(f), (s)))
end_define

begin_define
define|#
directive|define
name|NFSRV_CMPFH
parameter_list|(
name|nf
parameter_list|,
name|ns
parameter_list|,
name|f
parameter_list|,
name|s
parameter_list|)
define|\
value|((ns) == (s)&& !NFSBCMP((caddr_t)(nf), (caddr_t)(f), (s)))
end_define

begin_define
define|#
directive|define
name|NFS_CMPTIME
parameter_list|(
name|t1
parameter_list|,
name|t2
parameter_list|)
define|\
value|((t1).tv_sec == (t2).tv_sec&& (t1).tv_nsec == (t2).tv_nsec)
end_define

begin_define
define|#
directive|define
name|NFS_SETTIME
parameter_list|(
name|t
parameter_list|)
value|do { 						\ 	(t).tv_sec = time.tv_sec; (t).tv_nsec = 1000 * time.tv_usec; } while (0)
end_define

begin_define
define|#
directive|define
name|NFS_SRVMAXDATA
parameter_list|(
name|n
parameter_list|)
define|\
value|(((n)->nd_flag& (ND_NFSV3 | ND_NFSV4)) ? 		\ 		 NFS_SRVMAXIO : NFS_V2MAXDATA)
end_define

begin_define
define|#
directive|define
name|NFS64BITSSET
value|0xffffffffffffffffull
end_define

begin_define
define|#
directive|define
name|NFS64BITSMINUS1
value|0xfffffffffffffffeull
end_define

begin_comment
comment|/*  * Structures for the nfssvc(2) syscall. Not that anyone but nfsd, mount_nfs  * and nfsloaduser should ever try and use it.  */
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
comment|/*  * nfsd argument for new krpc.  */
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
comment|/*  * Arguments for use by the callback daemon.  */
end_comment

begin_struct
struct|struct
name|nfsd_nfscbd_args
block|{
specifier|const
name|char
modifier|*
name|principal
decl_stmt|;
comment|/* GSS-API service principal name */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|nfscbd_args
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
name|u_short
name|port
decl_stmt|;
comment|/* Port# for callbacks */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|nfsd_idargs
block|{
name|int
name|nid_flag
decl_stmt|;
comment|/* Flags (see below) */
name|uid_t
name|nid_uid
decl_stmt|;
comment|/* user/group id */
name|gid_t
name|nid_gid
decl_stmt|;
name|int
name|nid_usermax
decl_stmt|;
comment|/* Upper bound on user name cache */
name|int
name|nid_usertimeout
decl_stmt|;
comment|/* User name timeout (minutes) */
name|u_char
modifier|*
name|nid_name
decl_stmt|;
comment|/* Name */
name|int
name|nid_namelen
decl_stmt|;
comment|/* and its length */
name|gid_t
modifier|*
name|nid_grps
decl_stmt|;
comment|/* and the list */
name|int
name|nid_ngroup
decl_stmt|;
comment|/* Size of groups list */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|nfsd_oidargs
block|{
name|int
name|nid_flag
decl_stmt|;
comment|/* Flags (see below) */
name|uid_t
name|nid_uid
decl_stmt|;
comment|/* user/group id */
name|gid_t
name|nid_gid
decl_stmt|;
name|int
name|nid_usermax
decl_stmt|;
comment|/* Upper bound on user name cache */
name|int
name|nid_usertimeout
decl_stmt|;
comment|/* User name timeout (minutes) */
name|u_char
modifier|*
name|nid_name
decl_stmt|;
comment|/* Name */
name|int
name|nid_namelen
decl_stmt|;
comment|/* and its length */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|nfsd_clid
block|{
name|int
name|nclid_idlen
decl_stmt|;
comment|/* Length of client id */
name|u_char
name|nclid_id
index|[
name|NFSV4_OPAQUELIMIT
index|]
decl_stmt|;
comment|/* and name */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|nfsd_dumplist
block|{
name|int
name|ndl_size
decl_stmt|;
comment|/* Number of elements */
name|void
modifier|*
name|ndl_list
decl_stmt|;
comment|/* and the list of elements */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|nfsd_dumpclients
block|{
name|u_int32_t
name|ndcl_flags
decl_stmt|;
comment|/* LCL_xxx flags */
name|u_int32_t
name|ndcl_nopenowners
decl_stmt|;
comment|/* Number of openowners */
name|u_int32_t
name|ndcl_nopens
decl_stmt|;
comment|/* and opens */
name|u_int32_t
name|ndcl_nlockowners
decl_stmt|;
comment|/* and of lockowners */
name|u_int32_t
name|ndcl_nlocks
decl_stmt|;
comment|/* and of locks */
name|u_int32_t
name|ndcl_ndelegs
decl_stmt|;
comment|/* and of delegations */
name|u_int32_t
name|ndcl_nolddelegs
decl_stmt|;
comment|/* and old delegations */
name|sa_family_t
name|ndcl_addrfam
decl_stmt|;
comment|/* Callback address */
union|union
block|{
name|struct
name|in_addr
name|sin_addr
decl_stmt|;
name|struct
name|in6_addr
name|sin6_addr
decl_stmt|;
block|}
name|ndcl_cbaddr
union|;
name|struct
name|nfsd_clid
name|ndcl_clid
decl_stmt|;
comment|/* and client id */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|nfsd_dumplocklist
block|{
name|char
modifier|*
name|ndllck_fname
decl_stmt|;
comment|/* File Name */
name|int
name|ndllck_size
decl_stmt|;
comment|/* Number of elements */
name|void
modifier|*
name|ndllck_list
decl_stmt|;
comment|/* and the list of elements */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|nfsd_dumplocks
block|{
name|u_int32_t
name|ndlck_flags
decl_stmt|;
comment|/* state flags NFSLCK_xxx */
name|nfsv4stateid_t
name|ndlck_stateid
decl_stmt|;
comment|/* stateid */
name|u_int64_t
name|ndlck_first
decl_stmt|;
comment|/* lock byte range */
name|u_int64_t
name|ndlck_end
decl_stmt|;
name|struct
name|nfsd_clid
name|ndlck_owner
decl_stmt|;
comment|/* Owner of open/lock */
name|sa_family_t
name|ndlck_addrfam
decl_stmt|;
comment|/* Callback address */
union|union
block|{
name|struct
name|in_addr
name|sin_addr
decl_stmt|;
name|struct
name|in6_addr
name|sin6_addr
decl_stmt|;
block|}
name|ndlck_cbaddr
union|;
name|struct
name|nfsd_clid
name|ndlck_clid
decl_stmt|;
comment|/* and client id */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Structure for referral information.  */
end_comment

begin_struct
struct|struct
name|nfsreferral
block|{
name|u_char
modifier|*
name|nfr_srvlist
decl_stmt|;
comment|/* List of servers */
name|int
name|nfr_srvcnt
decl_stmt|;
comment|/* number of servers */
name|vnode_t
name|nfr_vp
decl_stmt|;
comment|/* vnode for referral */
name|uint64_t
name|nfr_dfileno
decl_stmt|;
comment|/* assigned dir inode# */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Flags for lc_flags and opsflags for nfsrv_getclient().  */
end_comment

begin_define
define|#
directive|define
name|LCL_NEEDSCONFIRM
value|0x00000001
end_define

begin_define
define|#
directive|define
name|LCL_DONTCLEAN
value|0x00000002
end_define

begin_define
define|#
directive|define
name|LCL_WAKEUPWANTED
value|0x00000004
end_define

begin_define
define|#
directive|define
name|LCL_TCPCALLBACK
value|0x00000008
end_define

begin_define
define|#
directive|define
name|LCL_CALLBACKSON
value|0x00000010
end_define

begin_define
define|#
directive|define
name|LCL_INDEXNOTOK
value|0x00000020
end_define

begin_define
define|#
directive|define
name|LCL_STAMPEDSTABLE
value|0x00000040
end_define

begin_define
define|#
directive|define
name|LCL_EXPIREIT
value|0x00000080
end_define

begin_define
define|#
directive|define
name|LCL_CBDOWN
value|0x00000100
end_define

begin_define
define|#
directive|define
name|LCL_KERBV
value|0x00000400
end_define

begin_define
define|#
directive|define
name|LCL_NAME
value|0x00000800
end_define

begin_define
define|#
directive|define
name|LCL_NEEDSCBNULL
value|0x00001000
end_define

begin_define
define|#
directive|define
name|LCL_GSSINTEGRITY
value|0x00002000
end_define

begin_define
define|#
directive|define
name|LCL_GSSPRIVACY
value|0x00004000
end_define

begin_define
define|#
directive|define
name|LCL_ADMINREVOKED
value|0x00008000
end_define

begin_define
define|#
directive|define
name|LCL_RECLAIMCOMPLETE
value|0x00010000
end_define

begin_define
define|#
directive|define
name|LCL_NFSV41
value|0x00020000
end_define

begin_define
define|#
directive|define
name|LCL_GSS
value|LCL_KERBV
end_define

begin_comment
comment|/* Or of all mechs */
end_comment

begin_comment
comment|/*  * Bits for flags in nfslock and nfsstate.  * The access, deny, NFSLCK_READ and NFSLCK_WRITE bits must be defined as  * below, in the correct order, so the shifts work for tests.  */
end_comment

begin_define
define|#
directive|define
name|NFSLCK_READACCESS
value|0x00000001
end_define

begin_define
define|#
directive|define
name|NFSLCK_WRITEACCESS
value|0x00000002
end_define

begin_define
define|#
directive|define
name|NFSLCK_ACCESSBITS
value|(NFSLCK_READACCESS | NFSLCK_WRITEACCESS)
end_define

begin_define
define|#
directive|define
name|NFSLCK_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|NFSLCK_READDENY
value|0x00000004
end_define

begin_define
define|#
directive|define
name|NFSLCK_WRITEDENY
value|0x00000008
end_define

begin_define
define|#
directive|define
name|NFSLCK_DENYBITS
value|(NFSLCK_READDENY | NFSLCK_WRITEDENY)
end_define

begin_define
define|#
directive|define
name|NFSLCK_SHAREBITS
define|\
value|(NFSLCK_READACCESS|NFSLCK_WRITEACCESS|NFSLCK_READDENY|NFSLCK_WRITEDENY)
end_define

begin_define
define|#
directive|define
name|NFSLCK_LOCKSHIFT
value|4
end_define

begin_define
define|#
directive|define
name|NFSLCK_READ
value|0x00000010
end_define

begin_define
define|#
directive|define
name|NFSLCK_WRITE
value|0x00000020
end_define

begin_define
define|#
directive|define
name|NFSLCK_BLOCKING
value|0x00000040
end_define

begin_define
define|#
directive|define
name|NFSLCK_RECLAIM
value|0x00000080
end_define

begin_define
define|#
directive|define
name|NFSLCK_OPENTOLOCK
value|0x00000100
end_define

begin_define
define|#
directive|define
name|NFSLCK_TEST
value|0x00000200
end_define

begin_define
define|#
directive|define
name|NFSLCK_LOCK
value|0x00000400
end_define

begin_define
define|#
directive|define
name|NFSLCK_UNLOCK
value|0x00000800
end_define

begin_define
define|#
directive|define
name|NFSLCK_OPEN
value|0x00001000
end_define

begin_define
define|#
directive|define
name|NFSLCK_CLOSE
value|0x00002000
end_define

begin_define
define|#
directive|define
name|NFSLCK_CHECK
value|0x00004000
end_define

begin_define
define|#
directive|define
name|NFSLCK_RELEASE
value|0x00008000
end_define

begin_define
define|#
directive|define
name|NFSLCK_NEEDSCONFIRM
value|0x00010000
end_define

begin_define
define|#
directive|define
name|NFSLCK_CONFIRM
value|0x00020000
end_define

begin_define
define|#
directive|define
name|NFSLCK_DOWNGRADE
value|0x00040000
end_define

begin_define
define|#
directive|define
name|NFSLCK_DELEGREAD
value|0x00080000
end_define

begin_define
define|#
directive|define
name|NFSLCK_DELEGWRITE
value|0x00100000
end_define

begin_define
define|#
directive|define
name|NFSLCK_DELEGCUR
value|0x00200000
end_define

begin_define
define|#
directive|define
name|NFSLCK_DELEGPREV
value|0x00400000
end_define

begin_define
define|#
directive|define
name|NFSLCK_OLDDELEG
value|0x00800000
end_define

begin_define
define|#
directive|define
name|NFSLCK_DELEGRECALL
value|0x01000000
end_define

begin_define
define|#
directive|define
name|NFSLCK_SETATTR
value|0x02000000
end_define

begin_define
define|#
directive|define
name|NFSLCK_DELEGPURGE
value|0x04000000
end_define

begin_define
define|#
directive|define
name|NFSLCK_DELEGRETURN
value|0x08000000
end_define

begin_define
define|#
directive|define
name|NFSLCK_WANTWDELEG
value|0x10000000
end_define

begin_define
define|#
directive|define
name|NFSLCK_WANTRDELEG
value|0x20000000
end_define

begin_define
define|#
directive|define
name|NFSLCK_WANTNODELEG
value|0x40000000
end_define

begin_define
define|#
directive|define
name|NFSLCK_WANTBITS
define|\
value|(NFSLCK_WANTWDELEG | NFSLCK_WANTRDELEG | NFSLCK_WANTNODELEG)
end_define

begin_comment
comment|/* And bits for nid_flag */
end_comment

begin_define
define|#
directive|define
name|NFSID_INITIALIZE
value|0x0001
end_define

begin_define
define|#
directive|define
name|NFSID_ADDUID
value|0x0002
end_define

begin_define
define|#
directive|define
name|NFSID_DELUID
value|0x0004
end_define

begin_define
define|#
directive|define
name|NFSID_ADDUSERNAME
value|0x0008
end_define

begin_define
define|#
directive|define
name|NFSID_DELUSERNAME
value|0x0010
end_define

begin_define
define|#
directive|define
name|NFSID_ADDGID
value|0x0020
end_define

begin_define
define|#
directive|define
name|NFSID_DELGID
value|0x0040
end_define

begin_define
define|#
directive|define
name|NFSID_ADDGROUPNAME
value|0x0080
end_define

begin_define
define|#
directive|define
name|NFSID_DELGROUPNAME
value|0x0100
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

begin_comment
comment|/*  * Here is the definition of the attribute bits array and macros that  * manipulate it.  * THE MACROS MUST BE MANUALLY MODIFIED IF NFSATTRBIT_MAXWORDS CHANGES!!  * It is (NFSATTRBIT_MAX + 31) / 32.  */
end_comment

begin_define
define|#
directive|define
name|NFSATTRBIT_MAXWORDS
value|3
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int32_t
name|bits
index|[
name|NFSATTRBIT_MAXWORDS
index|]
decl_stmt|;
block|}
name|nfsattrbit_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NFSZERO_ATTRBIT
parameter_list|(
name|b
parameter_list|)
value|do {						\ 	(b)->bits[0] = 0;						\ 	(b)->bits[1] = 0;						\ 	(b)->bits[2] = 0;						\ } while (0)
end_define

begin_define
define|#
directive|define
name|NFSSET_ATTRBIT
parameter_list|(
name|t
parameter_list|,
name|f
parameter_list|)
value|do {					\ 	(t)->bits[0] = (f)->bits[0];			 		\ 	(t)->bits[1] = (f)->bits[1];					\ 	(t)->bits[2] = (f)->bits[2];					\ } while (0)
end_define

begin_define
define|#
directive|define
name|NFSSETSUPP_ATTRBIT
parameter_list|(
name|b
parameter_list|)
value|do { 					\ 	(b)->bits[0] = NFSATTRBIT_SUPP0; 				\ 	(b)->bits[1] = (NFSATTRBIT_SUPP1 | NFSATTRBIT_SUPPSETONLY);	\ 	(b)->bits[2] = NFSATTRBIT_SUPP2;				\ } while (0)
end_define

begin_define
define|#
directive|define
name|NFSISSET_ATTRBIT
parameter_list|(
name|b
parameter_list|,
name|p
parameter_list|)
value|((b)->bits[(p) / 32]& (1<< ((p) % 32)))
end_define

begin_define
define|#
directive|define
name|NFSSETBIT_ATTRBIT
parameter_list|(
name|b
parameter_list|,
name|p
parameter_list|)
value|((b)->bits[(p) / 32] |= (1<< ((p) % 32)))
end_define

begin_define
define|#
directive|define
name|NFSCLRBIT_ATTRBIT
parameter_list|(
name|b
parameter_list|,
name|p
parameter_list|)
value|((b)->bits[(p) / 32]&= ~(1<< ((p) % 32)))
end_define

begin_define
define|#
directive|define
name|NFSCLRALL_ATTRBIT
parameter_list|(
name|b
parameter_list|,
name|a
parameter_list|)
value|do { 					\ 	(b)->bits[0]&= ~((a)->bits[0]);	 			\ 	(b)->bits[1]&= ~((a)->bits[1]);	 			\ 	(b)->bits[2]&= ~((a)->bits[2]);				\ } while (0)
end_define

begin_define
define|#
directive|define
name|NFSCLRNOT_ATTRBIT
parameter_list|(
name|b
parameter_list|,
name|a
parameter_list|)
value|do { 					\ 	(b)->bits[0]&= ((a)->bits[0]);		 			\ 	(b)->bits[1]&= ((a)->bits[1]);		 			\ 	(b)->bits[2]&= ((a)->bits[2]);		 			\ } while (0)
end_define

begin_define
define|#
directive|define
name|NFSCLRNOTFILLABLE_ATTRBIT
parameter_list|(
name|b
parameter_list|)
value|do { 				\ 	(b)->bits[0]&= NFSATTRBIT_SUPP0;	 			\ 	(b)->bits[1]&= NFSATTRBIT_SUPP1;				\ 	(b)->bits[2]&= NFSATTRBIT_SUPP2;				\ } while (0)
end_define

begin_define
define|#
directive|define
name|NFSCLRNOTSETABLE_ATTRBIT
parameter_list|(
name|b
parameter_list|)
value|do { 				\ 	(b)->bits[0]&= NFSATTRBIT_SETABLE0;	 			\ 	(b)->bits[1]&= NFSATTRBIT_SETABLE1;				\ 	(b)->bits[2]&= NFSATTRBIT_SETABLE2;				\ } while (0)
end_define

begin_define
define|#
directive|define
name|NFSNONZERO_ATTRBIT
parameter_list|(
name|b
parameter_list|)
value|((b)->bits[0] || (b)->bits[1] || (b)->bits[2])
end_define

begin_define
define|#
directive|define
name|NFSEQUAL_ATTRBIT
parameter_list|(
name|b
parameter_list|,
name|p
parameter_list|)
value|((b)->bits[0] == (p)->bits[0]&&	\ 	(b)->bits[1] == (p)->bits[1]&& (b)->bits[2] == (p)->bits[2])
end_define

begin_define
define|#
directive|define
name|NFSGETATTR_ATTRBIT
parameter_list|(
name|b
parameter_list|)
value|do { 					\ 	(b)->bits[0] = NFSATTRBIT_GETATTR0;	 			\ 	(b)->bits[1] = NFSATTRBIT_GETATTR1;				\ 	(b)->bits[2] = NFSATTRBIT_GETATTR2;				\ } while (0)
end_define

begin_define
define|#
directive|define
name|NFSWCCATTR_ATTRBIT
parameter_list|(
name|b
parameter_list|)
value|do { 					\ 	(b)->bits[0] = NFSATTRBIT_WCCATTR0;	 			\ 	(b)->bits[1] = NFSATTRBIT_WCCATTR1;				\ 	(b)->bits[2] = NFSATTRBIT_WCCATTR2;				\ } while (0)
end_define

begin_define
define|#
directive|define
name|NFSWRITEGETATTR_ATTRBIT
parameter_list|(
name|b
parameter_list|)
value|do { 				\ 	(b)->bits[0] = NFSATTRBIT_WRITEGETATTR0;			\ 	(b)->bits[1] = NFSATTRBIT_WRITEGETATTR1;			\ 	(b)->bits[2] = NFSATTRBIT_WRITEGETATTR2;			\ } while (0)
end_define

begin_define
define|#
directive|define
name|NFSCBGETATTR_ATTRBIT
parameter_list|(
name|b
parameter_list|,
name|c
parameter_list|)
value|do { 				\ 	(c)->bits[0] = ((b)->bits[0]& NFSATTRBIT_CBGETATTR0);		\ 	(c)->bits[1] = ((b)->bits[1]& NFSATTRBIT_CBGETATTR1);		\ 	(c)->bits[2] = ((b)->bits[2]& NFSATTRBIT_CBGETATTR2);		\ } while (0)
end_define

begin_define
define|#
directive|define
name|NFSPATHCONF_GETATTRBIT
parameter_list|(
name|b
parameter_list|)
value|do { 					\ 	(b)->bits[0] = NFSGETATTRBIT_PATHCONF0;		 		\ 	(b)->bits[1] = NFSGETATTRBIT_PATHCONF1;				\ 	(b)->bits[2] = NFSGETATTRBIT_PATHCONF2;				\ } while (0)
end_define

begin_define
define|#
directive|define
name|NFSSTATFS_GETATTRBIT
parameter_list|(
name|b
parameter_list|)
value|do { 					\ 	(b)->bits[0] = NFSGETATTRBIT_STATFS0;	 			\ 	(b)->bits[1] = NFSGETATTRBIT_STATFS1;				\ 	(b)->bits[2] = NFSGETATTRBIT_STATFS2;				\ } while (0)
end_define

begin_define
define|#
directive|define
name|NFSISSETSTATFS_ATTRBIT
parameter_list|(
name|b
parameter_list|)
define|\
value|(((b)->bits[0]& NFSATTRBIT_STATFS0) || 		\ 		 ((b)->bits[1]& NFSATTRBIT_STATFS1) ||			\ 		 ((b)->bits[2]& NFSATTRBIT_STATFS2))
end_define

begin_define
define|#
directive|define
name|NFSCLRSTATFS_ATTRBIT
parameter_list|(
name|b
parameter_list|)
value|do { 					\ 	(b)->bits[0]&= ~NFSATTRBIT_STATFS0;	 			\ 	(b)->bits[1]&= ~NFSATTRBIT_STATFS1;				\ 	(b)->bits[2]&= ~NFSATTRBIT_STATFS2;				\ } while (0)
end_define

begin_define
define|#
directive|define
name|NFSREADDIRPLUS_ATTRBIT
parameter_list|(
name|b
parameter_list|)
value|do { 					\ 	(b)->bits[0] = NFSATTRBIT_READDIRPLUS0;		 		\ 	(b)->bits[1] = NFSATTRBIT_READDIRPLUS1;				\ 	(b)->bits[2] = NFSATTRBIT_READDIRPLUS2;				\ } while (0)
end_define

begin_define
define|#
directive|define
name|NFSREFERRAL_ATTRBIT
parameter_list|(
name|b
parameter_list|)
value|do { 					\ 	(b)->bits[0] = NFSATTRBIT_REFERRAL0;		 		\ 	(b)->bits[1] = NFSATTRBIT_REFERRAL1;				\ 	(b)->bits[2] = NFSATTRBIT_REFERRAL2;				\ } while (0)
end_define

begin_comment
comment|/*  * Store uid, gid creds that were used when the stateid was acquired.  * The RPC layer allows NFS_MAXGRPS + 1 groups to go out on the wire,  * so that's how many gets stored here.  */
end_comment

begin_struct
struct|struct
name|nfscred
block|{
name|uid_t
name|nfsc_uid
decl_stmt|;
name|gid_t
name|nfsc_groups
index|[
name|NFS_MAXGRPS
operator|+
literal|1
index|]
decl_stmt|;
name|int
name|nfsc_ngroups
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Constants that define the file handle for the V4 root directory.  * (The FSID must never be used by other file systems that are exported.)  */
end_comment

begin_define
define|#
directive|define
name|NFSV4ROOT_FSID0
value|((int32_t) -1)
end_define

begin_define
define|#
directive|define
name|NFSV4ROOT_FSID1
value|((int32_t) -1)
end_define

begin_define
define|#
directive|define
name|NFSV4ROOT_REFERRAL
value|((int32_t) -2)
end_define

begin_define
define|#
directive|define
name|NFSV4ROOT_INO
value|2
end_define

begin_comment
comment|/* It's traditional */
end_comment

begin_define
define|#
directive|define
name|NFSV4ROOT_GEN
value|1
end_define

begin_comment
comment|/*  * The set of signals the interrupt an I/O in progress for NFSMNT_INT mounts.  * What should be in this set is open to debate, but I believe that since  * I/O system calls on ufs are never interrupted by signals the set should  * be minimal. My reasoning is that many current programs that use signals  * such as SIGALRM will not expect file I/O system calls to be interrupted  * by them and break.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|||
name|defined
argument_list|(
name|KERNEL
argument_list|)
end_if

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

begin_comment
comment|/*  * Socket errors ignored for connectionless sockets?  * For now, ignore them all  */
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
comment|/*  * This structure holds socket information for a connection. Used by the  * client and the server for callbacks.  */
end_comment

begin_struct
struct|struct
name|nfssockreq
block|{
name|NFSSOCKADDR_T
name|nr_nam
decl_stmt|;
name|int
name|nr_sotype
decl_stmt|;
name|int
name|nr_soproto
decl_stmt|;
name|int
name|nr_soflags
decl_stmt|;
name|struct
name|ucred
modifier|*
name|nr_cred
decl_stmt|;
name|int
name|nr_lock
decl_stmt|;
name|NFSMUTEX_T
name|nr_mtx
decl_stmt|;
name|u_int32_t
name|nr_prog
decl_stmt|;
name|u_int32_t
name|nr_vers
decl_stmt|;
name|struct
name|__rpc_client
modifier|*
name|nr_client
decl_stmt|;
name|AUTH
modifier|*
name|nr_auth
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * And associated nr_lock bits.  */
end_comment

begin_define
define|#
directive|define
name|NFSR_SNDLOCK
value|0x01
end_define

begin_define
define|#
directive|define
name|NFSR_WANTSND
value|0x02
end_define

begin_define
define|#
directive|define
name|NFSR_RCVLOCK
value|0x04
end_define

begin_define
define|#
directive|define
name|NFSR_WANTRCV
value|0x08
end_define

begin_define
define|#
directive|define
name|NFSR_RESERVEDPORT
value|0x10
end_define

begin_define
define|#
directive|define
name|NFSR_LOCALHOST
value|0x20
end_define

begin_comment
comment|/*  * Queue head for nfsreq's  */
end_comment

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|nfsreqhead
argument_list|,
name|nfsreq
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* This is the only nfsreq R_xxx flag still used. */
end_comment

begin_define
define|#
directive|define
name|R_DONTRECOVER
value|0x00000100
end_define

begin_comment
comment|/* don't initiate recovery when this 					   rpc gets a stale state reply */
end_comment

begin_comment
comment|/*  * Network address hash list element  */
end_comment

begin_union
union|union
name|nethostaddr
block|{
name|struct
name|in_addr
name|had_inet
decl_stmt|;
name|struct
name|in6_addr
name|had_inet6
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/*  * Structure of list of mechanisms.  */
end_comment

begin_struct
struct|struct
name|nfsgss_mechlist
block|{
name|int
name|len
decl_stmt|;
specifier|const
name|u_char
modifier|*
name|str
decl_stmt|;
name|int
name|totlen
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|KERBV_MECH
value|0
end_define

begin_comment
comment|/* position in list */
end_comment

begin_comment
comment|/*  * This structure is used by the server for describing each request.  */
end_comment

begin_struct
struct|struct
name|nfsrv_descript
block|{
name|mbuf_t
name|nd_mrep
decl_stmt|;
comment|/* Request mbuf list */
name|mbuf_t
name|nd_md
decl_stmt|;
comment|/* Current dissect mbuf */
name|mbuf_t
name|nd_mreq
decl_stmt|;
comment|/* Reply mbuf list */
name|mbuf_t
name|nd_mb
decl_stmt|;
comment|/* Current build mbuf */
name|NFSSOCKADDR_T
name|nd_nam
decl_stmt|;
comment|/* and socket addr */
name|NFSSOCKADDR_T
name|nd_nam2
decl_stmt|;
comment|/* return socket addr */
name|caddr_t
name|nd_dpos
decl_stmt|;
comment|/* Current dissect pos */
name|caddr_t
name|nd_bpos
decl_stmt|;
comment|/* Current build pos */
name|u_int16_t
name|nd_procnum
decl_stmt|;
comment|/* RPC # */
name|u_int32_t
name|nd_flag
decl_stmt|;
comment|/* nd_flag */
name|u_int32_t
name|nd_repstat
decl_stmt|;
comment|/* Reply status */
name|int
modifier|*
name|nd_errp
decl_stmt|;
comment|/* Pointer to ret status */
name|u_int32_t
name|nd_retxid
decl_stmt|;
comment|/* Reply xid */
name|struct
name|nfsrvcache
modifier|*
name|nd_rp
decl_stmt|;
comment|/* Assoc. cache entry */
name|fhandle_t
name|nd_fh
decl_stmt|;
comment|/* File handle */
name|struct
name|ucred
modifier|*
name|nd_cred
decl_stmt|;
comment|/* Credentials */
name|uid_t
name|nd_saveduid
decl_stmt|;
comment|/* Saved uid */
name|u_int64_t
name|nd_sockref
decl_stmt|;
comment|/* Rcv socket ref# */
name|u_int64_t
name|nd_compref
decl_stmt|;
comment|/* Compound RPC ref# */
name|time_t
name|nd_tcpconntime
decl_stmt|;
comment|/* Time TCP connection est. */
name|nfsquad_t
name|nd_clientid
decl_stmt|;
comment|/* Implied clientid */
name|int
name|nd_gssnamelen
decl_stmt|;
comment|/* principal name length */
name|char
modifier|*
name|nd_gssname
decl_stmt|;
comment|/* principal name */
name|uint32_t
modifier|*
name|nd_slotseq
decl_stmt|;
comment|/* ptr to slot seq# in req */
name|uint8_t
name|nd_sessionid
index|[
name|NFSX_V4SESSIONID
index|]
decl_stmt|;
comment|/* Session id */
name|uint32_t
name|nd_slotid
decl_stmt|;
comment|/* Slotid for this RPC */
name|SVCXPRT
modifier|*
name|nd_xprt
decl_stmt|;
comment|/* Server RPC handle */
name|uint32_t
modifier|*
name|nd_sequence
decl_stmt|;
comment|/* Sequence Op. ptr */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|nd_princlen
value|nd_gssnamelen
end_define

begin_define
define|#
directive|define
name|nd_principal
value|nd_gssname
end_define

begin_comment
comment|/* Bits for "nd_flag" */
end_comment

begin_define
define|#
directive|define
name|ND_DONTSAVEREPLY
value|0x00000001
end_define

begin_define
define|#
directive|define
name|ND_SAVEREPLY
value|0x00000002
end_define

begin_define
define|#
directive|define
name|ND_NFSV2
value|0x00000004
end_define

begin_define
define|#
directive|define
name|ND_NFSV3
value|0x00000008
end_define

begin_define
define|#
directive|define
name|ND_NFSV4
value|0x00000010
end_define

begin_define
define|#
directive|define
name|ND_KERBV
value|0x00000020
end_define

begin_define
define|#
directive|define
name|ND_GSSINTEGRITY
value|0x00000040
end_define

begin_define
define|#
directive|define
name|ND_GSSPRIVACY
value|0x00000080
end_define

begin_define
define|#
directive|define
name|ND_WINDOWVERF
value|0x00000100
end_define

begin_define
define|#
directive|define
name|ND_GSSINITREPLY
value|0x00000200
end_define

begin_define
define|#
directive|define
name|ND_STREAMSOCK
value|0x00000400
end_define

begin_define
define|#
directive|define
name|ND_PUBLOOKUP
value|0x00000800
end_define

begin_define
define|#
directive|define
name|ND_USEGSSNAME
value|0x00001000
end_define

begin_define
define|#
directive|define
name|ND_SAMETCPCONN
value|0x00002000
end_define

begin_define
define|#
directive|define
name|ND_IMPLIEDCLID
value|0x00004000
end_define

begin_define
define|#
directive|define
name|ND_NOMOREDATA
value|0x00008000
end_define

begin_define
define|#
directive|define
name|ND_V4WCCATTR
value|0x00010000
end_define

begin_define
define|#
directive|define
name|ND_NFSCB
value|0x00020000
end_define

begin_define
define|#
directive|define
name|ND_AUTHNONE
value|0x00040000
end_define

begin_define
define|#
directive|define
name|ND_EXAUTHSYS
value|0x00080000
end_define

begin_define
define|#
directive|define
name|ND_EXGSS
value|0x00100000
end_define

begin_define
define|#
directive|define
name|ND_EXGSSINTEGRITY
value|0x00200000
end_define

begin_define
define|#
directive|define
name|ND_EXGSSPRIVACY
value|0x00400000
end_define

begin_define
define|#
directive|define
name|ND_INCRSEQID
value|0x00800000
end_define

begin_define
define|#
directive|define
name|ND_NFSCL
value|0x01000000
end_define

begin_define
define|#
directive|define
name|ND_NFSV41
value|0x02000000
end_define

begin_define
define|#
directive|define
name|ND_HASSEQUENCE
value|0x04000000
end_define

begin_define
define|#
directive|define
name|ND_CACHETHIS
value|0x08000000
end_define

begin_define
define|#
directive|define
name|ND_LASTOP
value|0x10000000
end_define

begin_define
define|#
directive|define
name|ND_LOOPBADSESS
value|0x20000000
end_define

begin_comment
comment|/*  * ND_GSS should be the "or" of all GSS type authentications.  */
end_comment

begin_define
define|#
directive|define
name|ND_GSS
value|(ND_KERBV)
end_define

begin_struct
struct|struct
name|nfsv4_opflag
block|{
name|int
name|retfh
decl_stmt|;
name|int
name|needscfh
decl_stmt|;
name|int
name|savereply
decl_stmt|;
name|int
name|modifyfs
decl_stmt|;
name|int
name|lktype
decl_stmt|;
name|int
name|needsseq
decl_stmt|;
name|int
name|loopbadsess
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Flags used to indicate what to do w.r.t. seqid checking.  */
end_comment

begin_define
define|#
directive|define
name|NFSRVSEQID_FIRST
value|0x01
end_define

begin_define
define|#
directive|define
name|NFSRVSEQID_LAST
value|0x02
end_define

begin_define
define|#
directive|define
name|NFSRVSEQID_OPEN
value|0x04
end_define

begin_comment
comment|/*  * assign a doubly linked list to a new head  * and prepend one list into another.  */
end_comment

begin_define
define|#
directive|define
name|LIST_NEWHEAD
parameter_list|(
name|nhead
parameter_list|,
name|ohead
parameter_list|,
name|field
parameter_list|)
value|do { 				\ 	if (((nhead)->lh_first = (ohead)->lh_first) != NULL) 		\ 		(ohead)->lh_first->field.le_prev =&(nhead)->lh_first; 	\ 	(ohead)->lh_first = NULL; 					\     } while (0)
end_define

begin_define
define|#
directive|define
name|LIST_PREPEND
parameter_list|(
name|head
parameter_list|,
name|phead
parameter_list|,
name|lelm
parameter_list|,
name|field
parameter_list|)
value|do {			\ 	if ((head)->lh_first != NULL) {					\ 		(lelm)->field.le_next = (head)->lh_first;		\ 		(lelm)->field.le_next->field.le_prev =			\&(lelm)->field.le_next;				\ 	}								\ 	(head)->lh_first = (phead)->lh_first;				\ 	(head)->lh_first->field.le_prev =&(head)->lh_first;		\     } while (0)
end_define

begin_comment
comment|/*  * File handle structure for client. Malloc'd to the correct length with  * malloc type M_NFSFH.  */
end_comment

begin_struct
struct|struct
name|nfsfh
block|{
name|u_int16_t
name|nfh_len
decl_stmt|;
comment|/* Length of file handle */
name|u_int8_t
name|nfh_fh
index|[
literal|1
index|]
decl_stmt|;
comment|/* and the file handle */
block|}
struct|;
end_struct

begin_comment
comment|/*  * File handle structure for server. The NFSRV_MAXFH constant is  * set in nfsdport.h. I use a 32bit length, so that alignment is  * preserved.  */
end_comment

begin_struct
struct|struct
name|nfsrvfh
block|{
name|u_int32_t
name|nfsrvfh_len
decl_stmt|;
name|u_int8_t
name|nfsrvfh_data
index|[
name|NFSRV_MAXFH
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * This structure is used for sleep locks on the NFSv4 nfsd threads and  * NFSv4 client data structures.  */
end_comment

begin_struct
struct|struct
name|nfsv4lock
block|{
name|u_int32_t
name|nfslock_usecnt
decl_stmt|;
name|u_int8_t
name|nfslock_lock
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NFSV4LOCK_LOCK
value|0x01
end_define

begin_define
define|#
directive|define
name|NFSV4LOCK_LOCKWANTED
value|0x02
end_define

begin_define
define|#
directive|define
name|NFSV4LOCK_WANTED
value|0x04
end_define

begin_comment
comment|/*  * Values for the override argument for nfsvno_accchk().  */
end_comment

begin_define
define|#
directive|define
name|NFSACCCHK_NOOVERRIDE
value|0
end_define

begin_define
define|#
directive|define
name|NFSACCCHK_ALLOWROOT
value|1
end_define

begin_define
define|#
directive|define
name|NFSACCCHK_ALLOWOWNER
value|2
end_define

begin_comment
comment|/*  * and values for the vpislocked argument for nfsvno_accchk().  */
end_comment

begin_define
define|#
directive|define
name|NFSACCCHK_VPNOTLOCKED
value|0
end_define

begin_define
define|#
directive|define
name|NFSACCCHK_VPISLOCKED
value|1
end_define

begin_comment
comment|/*  * Slot for the NFSv4.1 Sequence Op.  */
end_comment

begin_struct
struct|struct
name|nfsslot
block|{
name|int
name|nfssl_inprog
decl_stmt|;
name|uint32_t
name|nfssl_seq
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|nfssl_reply
decl_stmt|;
block|}
struct|;
end_struct

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

begin_comment
comment|/* _NFS_NFS_H */
end_comment

end_unit

