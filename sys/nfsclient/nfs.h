begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989, 1993, 1995  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Rick Macklem at The University of Guelph.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)nfs.h	8.4 (Berkeley) 5/1/95  * $Id: nfs.h,v 1.31 1997/09/10 19:52:24 phk Exp $  */
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
value|5
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
comment|/* Max. number async_daemons runnable */
end_comment

begin_define
define|#
directive|define
name|NFS_MAXGATHERDELAY
value|100
end_define

begin_comment
comment|/* Max. write gather delay (msec) */
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
name|KERNEL
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
name|NMOD
parameter_list|(
name|a
parameter_list|)
value|((a) % nfs_asyncdaemons)
end_define

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
comment|/*  * The IO_METASYNC flag should be implemented for local file systems.  * (Until then, it is nothin at all.)  */
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
comment|/*  * Expected allocation sizes for major data structures. If the actual size  * of the structure exceeds these sizes, then malloc() will be allocating  * almost twice the memory required. This is used in nfs_init() to warn  * the sysadmin that the size of a structure should be reduced.  * (These sizes are always a power of 2. If the kernel malloc() changes  *  to one that does not allocate space in powers of 2 size, then this all  *  becomes bunk!)  */
end_comment

begin_define
define|#
directive|define
name|NFS_NODEALLOC
value|256
end_define

begin_define
define|#
directive|define
name|NFS_MNTALLOC
value|512
end_define

begin_define
define|#
directive|define
name|NFS_SVCALLOC
value|256
end_define

begin_define
define|#
directive|define
name|NFS_UIDALLOC
value|128
end_define

begin_comment
comment|/*  * Arguments to mount NFS  */
end_comment

begin_define
define|#
directive|define
name|NFS_ARGSVERSION
value|3
end_define

begin_comment
comment|/* change when nfs_args changes */
end_comment

begin_struct
struct|struct
name|nfs_args
block|{
name|int
name|version
decl_stmt|;
comment|/* args structure version number */
name|struct
name|sockaddr
modifier|*
name|addr
decl_stmt|;
comment|/* file server address */
name|int
name|addrlen
decl_stmt|;
comment|/* length of address */
name|int
name|sotype
decl_stmt|;
comment|/* Socket type */
name|int
name|proto
decl_stmt|;
comment|/* and Protocol */
name|u_char
modifier|*
name|fh
decl_stmt|;
comment|/* File handle to be mounted */
name|int
name|fhsize
decl_stmt|;
comment|/* Size, in bytes, of fh */
name|int
name|flags
decl_stmt|;
comment|/* flags */
name|int
name|wsize
decl_stmt|;
comment|/* write size in bytes */
name|int
name|rsize
decl_stmt|;
comment|/* read size in bytes */
name|int
name|readdirsize
decl_stmt|;
comment|/* readdir size in bytes */
name|int
name|timeo
decl_stmt|;
comment|/* initial timeout in .1 secs */
name|int
name|retrans
decl_stmt|;
comment|/* times to retry send */
name|int
name|maxgrouplist
decl_stmt|;
comment|/* Max. size of group list */
name|int
name|readahead
decl_stmt|;
comment|/* # of blocks to readahead */
name|int
name|leaseterm
decl_stmt|;
comment|/* Term (sec) of lease */
name|int
name|deadthresh
decl_stmt|;
comment|/* Retrans threshold */
name|char
modifier|*
name|hostname
decl_stmt|;
comment|/* server's name */
block|}
struct|;
end_struct

begin_comment
comment|/*  * NFS mount option flags  */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_SOFT
value|0x00000001
end_define

begin_comment
comment|/* soft mount (hard is default) */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_WSIZE
value|0x00000002
end_define

begin_comment
comment|/* set write size */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_RSIZE
value|0x00000004
end_define

begin_comment
comment|/* set read size */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_TIMEO
value|0x00000008
end_define

begin_comment
comment|/* set initial timeout */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_RETRANS
value|0x00000010
end_define

begin_comment
comment|/* set number of request retries */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_MAXGRPS
value|0x00000020
end_define

begin_comment
comment|/* set maximum grouplist size */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_INT
value|0x00000040
end_define

begin_comment
comment|/* allow interrupts on hard mount */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_NOCONN
value|0x00000080
end_define

begin_comment
comment|/* Don't Connect the socket */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_NQNFS
value|0x00000100
end_define

begin_comment
comment|/* Use Nqnfs protocol */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_NFSV3
value|0x00000200
end_define

begin_comment
comment|/* Use NFS Version 3 protocol */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_KERB
value|0x00000400
end_define

begin_comment
comment|/* Use Kerberos authentication */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_DUMBTIMR
value|0x00000800
end_define

begin_comment
comment|/* Don't estimate rtt dynamically */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_LEASETERM
value|0x00001000
end_define

begin_comment
comment|/* set lease term (nqnfs) */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_READAHEAD
value|0x00002000
end_define

begin_comment
comment|/* set read ahead */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_DEADTHRESH
value|0x00004000
end_define

begin_comment
comment|/* set dead server retry thresh */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_RESVPORT
value|0x00008000
end_define

begin_comment
comment|/* Allocate a reserved port */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_RDIRPLUS
value|0x00010000
end_define

begin_comment
comment|/* Use Readdirplus for V3 */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_READDIRSIZE
value|0x00020000
end_define

begin_comment
comment|/* Set readdir size */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_INTERNAL
value|0xfffc0000
end_define

begin_comment
comment|/* Bits set internally */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_HASWRITEVERF
value|0x00040000
end_define

begin_comment
comment|/* Has write verifier for V3 */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_GOTPATHCONF
value|0x00080000
end_define

begin_comment
comment|/* Got the V3 pathconf info */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_GOTFSINFO
value|0x00100000
end_define

begin_comment
comment|/* Got the V3 fsinfo */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_MNTD
value|0x00200000
end_define

begin_comment
comment|/* Mnt server for mnt point */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_DISMINPROG
value|0x00400000
end_define

begin_comment
comment|/* Dismount in progress */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_DISMNT
value|0x00800000
end_define

begin_comment
comment|/* Dismounted */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_SNDLOCK
value|0x01000000
end_define

begin_comment
comment|/* Send socket lock */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_WANTSND
value|0x02000000
end_define

begin_comment
comment|/* Want above */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_RCVLOCK
value|0x04000000
end_define

begin_comment
comment|/* Rcv socket lock */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_WANTRCV
value|0x08000000
end_define

begin_comment
comment|/* Want above */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_WAITAUTH
value|0x10000000
end_define

begin_comment
comment|/* Wait for authentication */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_HASAUTH
value|0x20000000
end_define

begin_comment
comment|/* Has authenticator */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_WANTAUTH
value|0x40000000
end_define

begin_comment
comment|/* Wants an authenticator */
end_comment

begin_define
define|#
directive|define
name|NFSMNT_AUTHERR
value|0x80000000
end_define

begin_comment
comment|/* Authentication error */
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
name|u_char
modifier|*
name|nsd_authstr
decl_stmt|;
comment|/* Auth string (ret) */
name|int
name|nsd_verflen
decl_stmt|;
comment|/* and the verfier */
name|u_char
modifier|*
name|nsd_verfstr
decl_stmt|;
name|struct
name|timeval
name|nsd_timestamp
decl_stmt|;
comment|/* timestamp from verifier */
name|u_long
name|nsd_ttl
decl_stmt|;
comment|/* credential ttl (sec) */
name|NFSKERBKEY_T
name|nsd_key
decl_stmt|;
comment|/* Session key */
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
name|u_char
modifier|*
name|ncd_authstr
decl_stmt|;
comment|/* Authenticator string */
name|int
name|ncd_verflen
decl_stmt|;
comment|/* and the verifier */
name|u_char
modifier|*
name|ncd_verfstr
decl_stmt|;
name|NFSKERBKEY_T
name|ncd_key
decl_stmt|;
comment|/* Session key */
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
name|int
name|srvvop_writes
decl_stmt|;
block|}
struct|;
end_struct

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
name|NFS_NFSPRIVPORT
value|2
end_define

begin_comment
comment|/* int: prohibit nfs to resvports */
end_comment

begin_define
define|#
directive|define
name|FS_NFS_NAMES
value|{ \ 		       { 0, 0 }, \ 		       { "nfsstats", CTLTYPE_STRUCT }, \ 		       { "nfsprivport", CTLTYPE_INT }, \ }
end_define

begin_comment
comment|/*  * The set of signals the interrupt an I/O in progress for NFSMNT_INT mounts.  * What should be in this set is open to debate, but I believe that since  * I/O system calls on ufs are never interrupted by signals the set should  * be minimal. My reasoning is that many current programs that use signals  * such as SIGALRM will not expect file I/O system calls to be interrupted  * by them and break.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
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
name|M_NFSMNT
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
name|M_NFSRVDESC
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_NFSUID
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_NQLEASE
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

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_NFSBIGFH
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

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
name|u_int32_t
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

begin_comment
comment|/*  * A list of nfssvc_sock structures is maintained with all the sockets  * that require service by the nfsd.  * The nfsuid structs hang off of the nfssvc_sock structs in both lru  * and uid hash lists.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NFS_UIDHASHSIZ
end_ifndef

begin_define
define|#
directive|define
name|NFS_UIDHASHSIZ
value|29
end_define

begin_comment
comment|/* Tune the size of nfssvc_sock with this */
end_comment

begin_endif
endif|#
directive|endif
end_endif

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
value|(&(sock)->ns_uidhashtbl[(uid) % NFS_UIDHASHSIZ])
end_define

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
value|(&(sock)->ns_wdelayhashtbl[(*((u_long *)(f))) % NFS_WDELAYHASHSIZ])
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|NFS_MUIDHASHSIZ
end_ifndef

begin_define
define|#
directive|define
name|NFS_MUIDHASHSIZ
value|63
end_define

begin_comment
comment|/* Tune the size of nfsmount with this */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|NMUIDHASH
parameter_list|(
name|nmp
parameter_list|,
name|uid
parameter_list|)
define|\
value|(&(nmp)->nm_uidhashtbl[(uid) % NFS_MUIDHASHSIZ])
end_define

begin_define
define|#
directive|define
name|NFSNOHASH
parameter_list|(
name|fhsum
parameter_list|)
define|\
value|(&nfsnodehashtbl[(fhsum)& nfsnodehash])
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
name|sockaddr
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
name|int
name|nu_expire
decl_stmt|;
comment|/* Expiry time (sec) */
name|struct
name|timeval
name|nu_timestamp
decl_stmt|;
comment|/* Kerb. timestamp */
name|u_long
name|nu_nickname
decl_stmt|;
comment|/* Nickname on server */
name|NFSKERBKEY_T
name|nu_key
decl_stmt|;
comment|/* and session key */
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

begin_define
define|#
directive|define
name|NU_NAM
value|0x2
end_define

begin_define
define|#
directive|define
name|NU_NETFAM
parameter_list|(
name|u
parameter_list|)
value|(((u)->nu_flag& NU_INETADDR) ? AF_INET : AF_ISO)
end_define

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
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|nfsuid
argument_list|)
name|ns_uidlruhead
expr_stmt|;
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
name|int
name|ns_numuids
decl_stmt|;
name|u_long
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
argument_list|,
argument|nfsuid
argument_list|)
name|ns_uidhashtbl
index|[
name|NFS_UIDHASHSIZ
index|]
expr_stmt|;
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
name|SLP_LASTFRAG
value|0x20
end_define

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
name|proc
modifier|*
name|nfsd_procp
decl_stmt|;
comment|/* Proc ptr */
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
name|u_long
name|nd_retxid
decl_stmt|;
comment|/* Reply xid */
name|u_long
name|nd_duration
decl_stmt|;
comment|/* Lease duration */
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
name|ND_READ
value|LEASE_READ
end_define

begin_define
define|#
directive|define
name|ND_WRITE
value|LEASE_WRITE
end_define

begin_define
define|#
directive|define
name|ND_CHECK
value|0x04
end_define

begin_define
define|#
directive|define
name|ND_LEASE
value|(ND_READ | ND_WRITE | ND_CHECK)
end_define

begin_define
define|#
directive|define
name|ND_NFSV3
value|0x08
end_define

begin_define
define|#
directive|define
name|ND_NQNFS
value|0x10
end_define

begin_define
define|#
directive|define
name|ND_KERBNICK
value|0x20
end_define

begin_define
define|#
directive|define
name|ND_KERBFULL
value|0x40
end_define

begin_define
define|#
directive|define
name|ND_KERBAUTH
value|(ND_KERBNICK | ND_KERBFULL)
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

begin_define
define|#
directive|define
name|NFSW_SAMECRED
parameter_list|(
name|o
parameter_list|,
name|n
parameter_list|)
define|\
value|(((o)->nd_flag& ND_KERBAUTH) == ((n)->nd_flag& ND_KERBAUTH)&& \  	 !bcmp((caddr_t)&(o)->nd_cr, (caddr_t)&(n)->nd_cr, \ 		sizeof (struct ucred)))
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

begin_decl_stmt
name|int
name|nfs_init
name|__P
argument_list|(
operator|(
expr|struct
name|vfsconf
operator|*
name|vfsp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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
name|nfsrv_descript
operator|*
operator|,
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
name|sockaddr
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
name|nfsrv_descript
operator|*
operator|,
expr|struct
name|nfssvc_sock
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
name|void
name|nfs_sndunlock
name|__P
argument_list|(
operator|(
name|int
operator|*
name|flagp
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
name|nfs_readdirrpc
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
name|nfs_readdirplusrpc
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
name|void
name|nfsm_srvfattr
name|__P
argument_list|(
operator|(
expr|struct
name|nfsrv_descript
operator|*
operator|,
expr|struct
name|vattr
operator|*
operator|,
expr|struct
name|nfs_fattr
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|nfsm_srvwcc
name|__P
argument_list|(
operator|(
expr|struct
name|nfsrv_descript
operator|*
operator|,
name|int
operator|,
expr|struct
name|vattr
operator|*
operator|,
name|int
operator|,
expr|struct
name|vattr
operator|*
operator|,
expr|struct
name|mbuf
operator|*
operator|*
operator|,
name|char
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|nfsm_srvpostopattr
name|__P
argument_list|(
operator|(
expr|struct
name|nfsrv_descript
operator|*
operator|,
name|int
operator|,
expr|struct
name|vattr
operator|*
operator|,
expr|struct
name|mbuf
operator|*
operator|*
operator|,
name|char
operator|*
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
name|sockaddr
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
name|sockaddr
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
name|vnode
operator|*
operator|*
operator|,
expr|struct
name|proc
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
name|char
operator|*
operator|*
operator|,
name|int
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|*
operator|,
name|NFSKERBKEY_T
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nfs_getnickauth
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
name|char
operator|*
operator|*
operator|,
name|int
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nfs_savenickauth
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
name|int
operator|,
name|NFSKERBKEY_T
operator|,
expr|struct
name|mbuf
operator|*
operator|*
operator|,
name|char
operator|*
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
name|u_long
name|nfs_hash
name|__P
argument_list|(
operator|(
name|nfsfh_t
operator|*
operator|,
name|int
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
operator|,
expr|struct
name|nfsrv_descript
operator|*
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
name|nfsrv_descript
operator|*
operator|,
expr|struct
name|nfssvc_sock
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
name|nfsrv_descript
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
name|void
name|nfsrv_cleancache
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
name|void
name|nfs_disconnect
name|__P
argument_list|(
operator|(
expr|struct
name|nfsmount
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
operator|,
name|int
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
name|void
name|nfs_clearcommit
name|__P
argument_list|(
operator|(
expr|struct
name|mount
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nfsrv_errmap
name|__P
argument_list|(
operator|(
expr|struct
name|nfsrv_descript
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|nfsrvw_sort
name|__P
argument_list|(
operator|(
name|gid_t
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|nfsrv_setcred
name|__P
argument_list|(
operator|(
expr|struct
name|ucred
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
name|nfs_writebp
name|__P
argument_list|(
operator|(
expr|struct
name|buf
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nfsrv_object_create
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
name|void
name|nfsrv_wakenfsd
name|__P
argument_list|(
operator|(
expr|struct
name|nfssvc_sock
operator|*
name|slp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nfsrv_writegather
name|__P
argument_list|(
operator|(
expr|struct
name|nfsrv_descript
operator|*
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
name|nfs_fsinfo
name|__P
argument_list|(
operator|(
expr|struct
name|nfsmount
operator|*
operator|,
expr|struct
name|vnode
operator|*
operator|,
expr|struct
name|ucred
operator|*
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
name|nfsrv3_access
name|__P
argument_list|(
operator|(
expr|struct
name|nfsrv_descript
operator|*
name|nfsd
operator|,
expr|struct
name|nfssvc_sock
operator|*
name|slp
operator|,
expr|struct
name|proc
operator|*
name|procp
operator|,
expr|struct
name|mbuf
operator|*
operator|*
name|mrq
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nfsrv_commit
name|__P
argument_list|(
operator|(
expr|struct
name|nfsrv_descript
operator|*
name|nfsd
operator|,
expr|struct
name|nfssvc_sock
operator|*
name|slp
operator|,
expr|struct
name|proc
operator|*
name|procp
operator|,
expr|struct
name|mbuf
operator|*
operator|*
name|mrq
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nfsrv_create
name|__P
argument_list|(
operator|(
expr|struct
name|nfsrv_descript
operator|*
name|nfsd
operator|,
expr|struct
name|nfssvc_sock
operator|*
name|slp
operator|,
expr|struct
name|proc
operator|*
name|procp
operator|,
expr|struct
name|mbuf
operator|*
operator|*
name|mrq
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
name|sockaddr
operator|*
operator|,
name|int
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
name|nfsrv_setpublicfs
name|__P
argument_list|(
operator|(
expr|struct
name|mount
operator|*
operator|,
expr|struct
name|netexport
operator|*
operator|,
expr|struct
name|export_args
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nfs_ispublicfh
name|__P
argument_list|(
operator|(
name|fhandle_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nfsrv_fsinfo
name|__P
argument_list|(
operator|(
expr|struct
name|nfsrv_descript
operator|*
name|nfsd
operator|,
expr|struct
name|nfssvc_sock
operator|*
name|slp
operator|,
expr|struct
name|proc
operator|*
name|procp
operator|,
expr|struct
name|mbuf
operator|*
operator|*
name|mrq
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nfsrv_getattr
name|__P
argument_list|(
operator|(
expr|struct
name|nfsrv_descript
operator|*
name|nfsd
operator|,
expr|struct
name|nfssvc_sock
operator|*
name|slp
operator|,
expr|struct
name|proc
operator|*
name|procp
operator|,
expr|struct
name|mbuf
operator|*
operator|*
name|mrq
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nfsrv_link
name|__P
argument_list|(
operator|(
expr|struct
name|nfsrv_descript
operator|*
name|nfsd
operator|,
expr|struct
name|nfssvc_sock
operator|*
name|slp
operator|,
expr|struct
name|proc
operator|*
name|procp
operator|,
expr|struct
name|mbuf
operator|*
operator|*
name|mrq
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nfsrv_lookup
name|__P
argument_list|(
operator|(
expr|struct
name|nfsrv_descript
operator|*
name|nfsd
operator|,
expr|struct
name|nfssvc_sock
operator|*
name|slp
operator|,
expr|struct
name|proc
operator|*
name|procp
operator|,
expr|struct
name|mbuf
operator|*
operator|*
name|mrq
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nfsrv_mkdir
name|__P
argument_list|(
operator|(
expr|struct
name|nfsrv_descript
operator|*
name|nfsd
operator|,
expr|struct
name|nfssvc_sock
operator|*
name|slp
operator|,
expr|struct
name|proc
operator|*
name|procp
operator|,
expr|struct
name|mbuf
operator|*
operator|*
name|mrq
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nfsrv_mknod
name|__P
argument_list|(
operator|(
expr|struct
name|nfsrv_descript
operator|*
name|nfsd
operator|,
expr|struct
name|nfssvc_sock
operator|*
name|slp
operator|,
expr|struct
name|proc
operator|*
name|procp
operator|,
expr|struct
name|mbuf
operator|*
operator|*
name|mrq
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nfsrv_noop
name|__P
argument_list|(
operator|(
expr|struct
name|nfsrv_descript
operator|*
name|nfsd
operator|,
expr|struct
name|nfssvc_sock
operator|*
name|slp
operator|,
expr|struct
name|proc
operator|*
name|procp
operator|,
expr|struct
name|mbuf
operator|*
operator|*
name|mrq
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nfsrv_null
name|__P
argument_list|(
operator|(
expr|struct
name|nfsrv_descript
operator|*
name|nfsd
operator|,
expr|struct
name|nfssvc_sock
operator|*
name|slp
operator|,
expr|struct
name|proc
operator|*
name|procp
operator|,
expr|struct
name|mbuf
operator|*
operator|*
name|mrq
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nfsrv_pathconf
name|__P
argument_list|(
operator|(
expr|struct
name|nfsrv_descript
operator|*
name|nfsd
operator|,
expr|struct
name|nfssvc_sock
operator|*
name|slp
operator|,
expr|struct
name|proc
operator|*
name|procp
operator|,
expr|struct
name|mbuf
operator|*
operator|*
name|mrq
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nfsrv_read
name|__P
argument_list|(
operator|(
expr|struct
name|nfsrv_descript
operator|*
name|nfsd
operator|,
expr|struct
name|nfssvc_sock
operator|*
name|slp
operator|,
expr|struct
name|proc
operator|*
name|procp
operator|,
expr|struct
name|mbuf
operator|*
operator|*
name|mrq
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nfsrv_readdir
name|__P
argument_list|(
operator|(
expr|struct
name|nfsrv_descript
operator|*
name|nfsd
operator|,
expr|struct
name|nfssvc_sock
operator|*
name|slp
operator|,
expr|struct
name|proc
operator|*
name|procp
operator|,
expr|struct
name|mbuf
operator|*
operator|*
name|mrq
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nfsrv_readdirplus
name|__P
argument_list|(
operator|(
expr|struct
name|nfsrv_descript
operator|*
name|nfsd
operator|,
expr|struct
name|nfssvc_sock
operator|*
name|slp
operator|,
expr|struct
name|proc
operator|*
name|procp
operator|,
expr|struct
name|mbuf
operator|*
operator|*
name|mrq
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nfsrv_readlink
name|__P
argument_list|(
operator|(
expr|struct
name|nfsrv_descript
operator|*
name|nfsd
operator|,
expr|struct
name|nfssvc_sock
operator|*
name|slp
operator|,
expr|struct
name|proc
operator|*
name|procp
operator|,
expr|struct
name|mbuf
operator|*
operator|*
name|mrq
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nfsrv_remove
name|__P
argument_list|(
operator|(
expr|struct
name|nfsrv_descript
operator|*
name|nfsd
operator|,
expr|struct
name|nfssvc_sock
operator|*
name|slp
operator|,
expr|struct
name|proc
operator|*
name|procp
operator|,
expr|struct
name|mbuf
operator|*
operator|*
name|mrq
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nfsrv_rename
name|__P
argument_list|(
operator|(
expr|struct
name|nfsrv_descript
operator|*
name|nfsd
operator|,
expr|struct
name|nfssvc_sock
operator|*
name|slp
operator|,
expr|struct
name|proc
operator|*
name|procp
operator|,
expr|struct
name|mbuf
operator|*
operator|*
name|mrq
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nfsrv_rmdir
name|__P
argument_list|(
operator|(
expr|struct
name|nfsrv_descript
operator|*
name|nfsd
operator|,
expr|struct
name|nfssvc_sock
operator|*
name|slp
operator|,
expr|struct
name|proc
operator|*
name|procp
operator|,
expr|struct
name|mbuf
operator|*
operator|*
name|mrq
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nfsrv_setattr
name|__P
argument_list|(
operator|(
expr|struct
name|nfsrv_descript
operator|*
name|nfsd
operator|,
expr|struct
name|nfssvc_sock
operator|*
name|slp
operator|,
expr|struct
name|proc
operator|*
name|procp
operator|,
expr|struct
name|mbuf
operator|*
operator|*
name|mrq
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nfsrv_statfs
name|__P
argument_list|(
operator|(
expr|struct
name|nfsrv_descript
operator|*
name|nfsd
operator|,
expr|struct
name|nfssvc_sock
operator|*
name|slp
operator|,
expr|struct
name|proc
operator|*
name|procp
operator|,
expr|struct
name|mbuf
operator|*
operator|*
name|mrq
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nfsrv_symlink
name|__P
argument_list|(
operator|(
expr|struct
name|nfsrv_descript
operator|*
name|nfsd
operator|,
expr|struct
name|nfssvc_sock
operator|*
name|slp
operator|,
expr|struct
name|proc
operator|*
name|procp
operator|,
expr|struct
name|mbuf
operator|*
operator|*
name|mrq
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nfsrv_write
name|__P
argument_list|(
operator|(
expr|struct
name|nfsrv_descript
operator|*
name|nfsd
operator|,
expr|struct
name|nfssvc_sock
operator|*
name|slp
operator|,
expr|struct
name|proc
operator|*
name|procp
operator|,
expr|struct
name|mbuf
operator|*
operator|*
name|mrq
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|nfsrv_rcv
name|__P
argument_list|(
operator|(
expr|struct
name|socket
operator|*
name|so
operator|,
name|caddr_t
name|arg
operator|,
name|int
name|waitflag
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|nfsrv_slpderef
name|__P
argument_list|(
operator|(
expr|struct
name|nfssvc_sock
operator|*
name|slp
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

