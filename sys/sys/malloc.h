begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1987, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)malloc.h	8.5 (Berkeley) 5/3/95  * $Id: malloc.h,v 1.26 1997/10/10 14:05:34 phk Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_MALLOC_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_MALLOC_H_
end_define

begin_define
define|#
directive|define
name|KMEMSTATS
end_define

begin_comment
comment|/*  * flags to malloc  */
end_comment

begin_define
define|#
directive|define
name|M_WAITOK
value|0x0000
end_define

begin_define
define|#
directive|define
name|M_NOWAIT
value|0x0001
end_define

begin_define
define|#
directive|define
name|M_KERNEL
value|0x0002
end_define

begin_struct
struct|struct
name|malloc_type
block|{
name|char
modifier|*
name|ks_shortdesc
decl_stmt|;
comment|/* Short description */
name|char
modifier|*
name|ks_longdesc
decl_stmt|;
comment|/* Long description */
name|struct
name|malloc_type
modifier|*
name|ks_next
decl_stmt|;
comment|/* Next pointer */
name|long
name|ks_inuse
decl_stmt|;
comment|/* # of packets of this type currently in use */
name|long
name|ks_calls
decl_stmt|;
comment|/* total packets of this type ever allocated */
name|long
name|ks_memuse
decl_stmt|;
comment|/* total memory held in bytes */
name|u_short
name|ks_limblocks
decl_stmt|;
comment|/* number of times blocked for hitting limit */
name|u_short
name|ks_mapblocks
decl_stmt|;
comment|/* number of times blocked for kernel map */
name|long
name|ks_maxused
decl_stmt|;
comment|/* maximum number ever used */
name|long
name|ks_limit
decl_stmt|;
comment|/* most that are allowed to exist */
name|long
name|ks_size
decl_stmt|;
comment|/* sizes of this thing that are allocated */
name|long
name|ks_spare
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|malloc_type
name|malloc_type_t
index|[
literal|1
index|]
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|MALLOC_INSTANTIATE
end_ifdef

begin_define
define|#
directive|define
name|MALLOC_MAKE_TYPE
parameter_list|(
name|type
parameter_list|,
name|short
parameter_list|,
name|long
parameter_list|)
define|\
value|malloc_type_t type = {{short, long}}
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MALLOC_MAKE_TYPE
parameter_list|(
name|type
parameter_list|,
name|short
parameter_list|,
name|long
parameter_list|)
value|extern malloc_type_t type;
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
name|MALLOC_MAKE_TYPE
argument_list|(
name|M_FREE
argument_list|,
literal|"free"
argument_list|,
literal|"should be on free list"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_MAKE_TYPE
argument_list|(
name|M_MBUF
argument_list|,
literal|"mbuf"
argument_list|,
literal|"mbuf"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_MAKE_TYPE
argument_list|(
name|M_DEVBUF
argument_list|,
literal|"devbuf"
argument_list|,
literal|"device driver memory"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_MAKE_TYPE
argument_list|(
name|M_SOCKET
argument_list|,
literal|"socket"
argument_list|,
literal|"socket structure"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_MAKE_TYPE
argument_list|(
name|M_PCB
argument_list|,
literal|"pcb"
argument_list|,
literal|"protocol control block"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_MAKE_TYPE
argument_list|(
name|M_RTABLE
argument_list|,
literal|"routetbl"
argument_list|,
literal|"routing tables"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_MAKE_TYPE
argument_list|(
name|M_FTABLE
argument_list|,
literal|"fragtbl"
argument_list|,
literal|"fragment reassembly header"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_MAKE_TYPE
argument_list|(
name|M_ZOMBIE
argument_list|,
literal|"zombie"
argument_list|,
literal|"zombie proc status"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_MAKE_TYPE
argument_list|(
name|M_IFADDR
argument_list|,
literal|"ifaddr"
argument_list|,
literal|"interface address"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_MAKE_TYPE
argument_list|(
name|M_SOOPTS
argument_list|,
literal|"soopts"
argument_list|,
literal|"socket options"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_MAKE_TYPE
argument_list|(
name|M_SONAME
argument_list|,
literal|"soname"
argument_list|,
literal|"socket name"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_MAKE_TYPE
argument_list|(
name|M_GPROF
argument_list|,
literal|"gprof"
argument_list|,
literal|"kernel profiling buffer"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_MAKE_TYPE
argument_list|(
name|M_IOCTLOPS
argument_list|,
literal|"ioctlops"
argument_list|,
literal|"ioctl data buffer"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_MAKE_TYPE
argument_list|(
name|M_CRED
argument_list|,
literal|"cred"
argument_list|,
literal|"credentials"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_MAKE_TYPE
argument_list|(
name|M_PGRP
argument_list|,
literal|"pgrp"
argument_list|,
literal|"process group header"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_MAKE_TYPE
argument_list|(
name|M_SESSION
argument_list|,
literal|"session"
argument_list|,
literal|"session header"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_MAKE_TYPE
argument_list|(
name|M_IOV
argument_list|,
literal|"iov"
argument_list|,
literal|"large iov's"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_MAKE_TYPE
argument_list|(
name|M_MOUNT
argument_list|,
literal|"mount"
argument_list|,
literal|"vfs mount struct"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_MAKE_TYPE
argument_list|(
name|M_NFSREQ
argument_list|,
literal|"NFS req"
argument_list|,
literal|"NFS request header"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_MAKE_TYPE
argument_list|(
name|M_NFSMNT
argument_list|,
literal|"NFS mount"
argument_list|,
literal|"NFS mount structure"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_MAKE_TYPE
argument_list|(
name|M_NFSNODE
argument_list|,
literal|"NFS node"
argument_list|,
literal|"NFS vnode private part"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_MAKE_TYPE
argument_list|(
name|M_VNODE
argument_list|,
literal|"vnodes"
argument_list|,
literal|"Dynamically allocated vnodes"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_MAKE_TYPE
argument_list|(
name|M_CACHE
argument_list|,
literal|"namecache"
argument_list|,
literal|"Dynamically allocated cache entries"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_MAKE_TYPE
argument_list|(
name|M_DQUOT
argument_list|,
literal|"UFS quota"
argument_list|,
literal|"UFS quota entries"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_MAKE_TYPE
argument_list|(
name|M_UFSMNT
argument_list|,
literal|"UFS mount"
argument_list|,
literal|"UFS mount structure"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_MAKE_TYPE
argument_list|(
name|M_SHM
argument_list|,
literal|"shm"
argument_list|,
literal|"SVID compatible shared memory segments"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_MAKE_TYPE
argument_list|(
name|M_VMMAP
argument_list|,
literal|"VM map"
argument_list|,
literal|"VM map structures"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_MAKE_TYPE
argument_list|(
name|M_VMPMAP
argument_list|,
literal|"VM pmap"
argument_list|,
literal|"VM pmap"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* XXX only free() ??? */
end_comment

begin_expr_stmt
name|MALLOC_MAKE_TYPE
argument_list|(
name|M_VMPGDATA
argument_list|,
literal|"VM pgdata"
argument_list|,
literal|"XXX: VM pager private data"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_MAKE_TYPE
argument_list|(
name|M_FILE
argument_list|,
literal|"file"
argument_list|,
literal|"Open file structure"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_MAKE_TYPE
argument_list|(
name|M_FILEDESC
argument_list|,
literal|"file desc"
argument_list|,
literal|"Open file descriptor table"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_MAKE_TYPE
argument_list|(
name|M_LOCKF
argument_list|,
literal|"lockf"
argument_list|,
literal|"Byte-range locking structures"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_MAKE_TYPE
argument_list|(
name|M_PROC
argument_list|,
literal|"proc"
argument_list|,
literal|"Proc structures"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_MAKE_TYPE
argument_list|(
name|M_SUBPROC
argument_list|,
literal|"subproc"
argument_list|,
literal|"Proc sub-structures"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_MAKE_TYPE
argument_list|(
name|M_SEGMENT
argument_list|,
literal|"LFS segment"
argument_list|,
literal|"Segment for LFS"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_MAKE_TYPE
argument_list|(
name|M_LFSNODE
argument_list|,
literal|"LFS node"
argument_list|,
literal|"LFS vnode private part"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_MAKE_TYPE
argument_list|(
name|M_FFSNODE
argument_list|,
literal|"FFS node"
argument_list|,
literal|"FFS vnode private part"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_MAKE_TYPE
argument_list|(
name|M_MFSNODE
argument_list|,
literal|"MFS node"
argument_list|,
literal|"MFS vnode private part"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_MAKE_TYPE
argument_list|(
name|M_NQLEASE
argument_list|,
literal|"NQNFS Lease"
argument_list|,
literal|"Nqnfs lease"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_MAKE_TYPE
argument_list|(
name|M_NQMHOST
argument_list|,
literal|"NQNFS Host"
argument_list|,
literal|"Nqnfs host address table"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_MAKE_TYPE
argument_list|(
name|M_NETADDR
argument_list|,
literal|"Export Host"
argument_list|,
literal|"Export host address structure"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_MAKE_TYPE
argument_list|(
name|M_NFSSVC
argument_list|,
literal|"NFS srvsock"
argument_list|,
literal|"Nfs server structure"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_MAKE_TYPE
argument_list|(
name|M_NFSUID
argument_list|,
literal|"NFS uid"
argument_list|,
literal|"Nfs uid mapping structure"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_MAKE_TYPE
argument_list|(
name|M_NFSD
argument_list|,
literal|"NFS daemon"
argument_list|,
literal|"Nfs server daemon structure"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_MAKE_TYPE
argument_list|(
name|M_IPMOPTS
argument_list|,
literal|"ip_moptions"
argument_list|,
literal|"internet multicast options"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_MAKE_TYPE
argument_list|(
name|M_IPMADDR
argument_list|,
literal|"in_multi"
argument_list|,
literal|"internet multicast address"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_MAKE_TYPE
argument_list|(
name|M_IFMADDR
argument_list|,
literal|"ether_multi"
argument_list|,
literal|"link-level multicast address"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_MAKE_TYPE
argument_list|(
name|M_MRTABLE
argument_list|,
literal|"mrt"
argument_list|,
literal|"multicast routing tables"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_MAKE_TYPE
argument_list|(
name|M_ISOFSMNT
argument_list|,
literal|"ISOFS mount"
argument_list|,
literal|"ISOFS mount structure"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_MAKE_TYPE
argument_list|(
name|M_ISOFSNODE
argument_list|,
literal|"ISOFS node"
argument_list|,
literal|"ISOFS vnode private part"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_MAKE_TYPE
argument_list|(
name|M_NFSRVDESC
argument_list|,
literal|"NFSV3 srvdesc"
argument_list|,
literal|"NFS server socket descriptor"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_MAKE_TYPE
argument_list|(
name|M_NFSDIROFF
argument_list|,
literal|"NFSV3 diroff"
argument_list|,
literal|"NFS directory offset data"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_MAKE_TYPE
argument_list|(
name|M_NFSBIGFH
argument_list|,
literal|"NFSV3 bigfh"
argument_list|,
literal|"NFS version 3 file handle"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_MAKE_TYPE
argument_list|(
name|M_MSDOSFSMNT
argument_list|,
literal|"MSDOSFS mount"
argument_list|,
literal|"MSDOSFS mount structure"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_MAKE_TYPE
argument_list|(
name|M_MSDOSFSNODE
argument_list|,
literal|"MSDOSFS node"
argument_list|,
literal|"MSDOSFS vnode private part"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_MAKE_TYPE
argument_list|(
name|M_MSDOSFSFAT
argument_list|,
literal|"MSDOSFS FAT"
argument_list|,
literal|"MSDOSFS file allocation table"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_MAKE_TYPE
argument_list|(
name|M_DEVFSMNT
argument_list|,
literal|"DEVFS mount"
argument_list|,
literal|"DEVFS mount structure"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_MAKE_TYPE
argument_list|(
name|M_DEVFSBACK
argument_list|,
literal|"DEVFS back"
argument_list|,
literal|"DEVFS Back node"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_MAKE_TYPE
argument_list|(
name|M_DEVFSNODE
argument_list|,
literal|"DEVFS node"
argument_list|,
literal|"DEVFS node"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_MAKE_TYPE
argument_list|(
name|M_TEMP
argument_list|,
literal|"temp"
argument_list|,
literal|"misc temporary data buffers"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_MAKE_TYPE
argument_list|(
name|M_TTYS
argument_list|,
literal|"ttys"
argument_list|,
literal|"tty data structures"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_MAKE_TYPE
argument_list|(
name|M_GZIP
argument_list|,
literal|"Gzip trees"
argument_list|,
literal|"Gzip trees"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_MAKE_TYPE
argument_list|(
name|M_IPFW
argument_list|,
literal|"IpFw/IpAcct"
argument_list|,
literal|"IpFw/IpAcct chain's"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_MAKE_TYPE
argument_list|(
name|M_DEVL
argument_list|,
literal|"isa_devlist"
argument_list|,
literal|"isa_device lists in userconfig()"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_MAKE_TYPE
argument_list|(
name|M_SYSCTL
argument_list|,
literal|"sysctl"
argument_list|,
literal|"sysctl internal magic"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_MAKE_TYPE
argument_list|(
name|M_SECA
argument_list|,
literal|"key mgmt"
argument_list|,
literal|"security associations, key management"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_MAKE_TYPE
argument_list|(
name|M_BIOBUF
argument_list|,
literal|"BIO buffer"
argument_list|,
literal|"BIO buffer"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_MAKE_TYPE
argument_list|(
name|M_KTRACE
argument_list|,
literal|"KTRACE"
argument_list|,
literal|"KTRACE"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_MAKE_TYPE
argument_list|(
name|M_SELECT
argument_list|,
literal|"select"
argument_list|,
literal|"select() buffer"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_MAKE_TYPE
argument_list|(
name|M_VFSCONF
argument_list|,
literal|"VFS conf"
argument_list|,
literal|"vfsconf structure"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* XXX only free() ??? */
end_comment

begin_expr_stmt
name|MALLOC_MAKE_TYPE
argument_list|(
name|M_AIO
argument_list|,
literal|"AIO"
argument_list|,
literal|"AIO structure(s)"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_MAKE_TYPE
argument_list|(
name|M_ZONE
argument_list|,
literal|"ZONE"
argument_list|,
literal|"Zone header"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_MAKE_TYPE
argument_list|(
name|M_HOSTCACHE
argument_list|,
literal|"hostcache"
argument_list|,
literal|"per-host information cache structure"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Array of descriptors that describe the contents of each page  */
end_comment

begin_struct
struct|struct
name|kmemusage
block|{
name|short
name|ku_indx
decl_stmt|;
comment|/* bucket index */
union|union
block|{
name|u_short
name|freecnt
decl_stmt|;
comment|/* for small allocations, free pieces in page */
name|u_short
name|pagecnt
decl_stmt|;
comment|/* for large allocations, pages alloced */
block|}
name|ku_un
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ku_freecnt
value|ku_un.freecnt
end_define

begin_define
define|#
directive|define
name|ku_pagecnt
value|ku_un.pagecnt
end_define

begin_comment
comment|/*  * Set of buckets for each size of memory block that is retained  */
end_comment

begin_struct
struct|struct
name|kmembuckets
block|{
name|caddr_t
name|kb_next
decl_stmt|;
comment|/* list of free blocks */
name|caddr_t
name|kb_last
decl_stmt|;
comment|/* last free block */
name|long
name|kb_calls
decl_stmt|;
comment|/* total calls to allocate this size */
name|long
name|kb_total
decl_stmt|;
comment|/* total number of blocks allocated */
name|long
name|kb_totalfree
decl_stmt|;
comment|/* # of free elements in this bucket */
name|long
name|kb_elmpercl
decl_stmt|;
comment|/* # of elements in this sized allocation */
name|long
name|kb_highwat
decl_stmt|;
comment|/* high water mark */
name|long
name|kb_couldfree
decl_stmt|;
comment|/* over high water mark and could free */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<vm/vm_zone.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_zone.h>
end_include

begin_define
define|#
directive|define
name|MINALLOCSIZE
value|(1<< MINBUCKET)
end_define

begin_define
define|#
directive|define
name|BUCKETINDX
parameter_list|(
name|size
parameter_list|)
define|\
value|((size)<= (MINALLOCSIZE * 128) \ 		? (size)<= (MINALLOCSIZE * 8) \ 			? (size)<= (MINALLOCSIZE * 2) \ 				? (size)<= (MINALLOCSIZE * 1) \ 					? (MINBUCKET + 0) \ 					: (MINBUCKET + 1) \ 				: (size)<= (MINALLOCSIZE * 4) \ 					? (MINBUCKET + 2) \ 					: (MINBUCKET + 3) \ 			: (size)<= (MINALLOCSIZE* 32) \ 				? (size)<= (MINALLOCSIZE * 16) \ 					? (MINBUCKET + 4) \ 					: (MINBUCKET + 5) \ 				: (size)<= (MINALLOCSIZE * 64) \ 					? (MINBUCKET + 6) \ 					: (MINBUCKET + 7) \ 		: (size)<= (MINALLOCSIZE * 2048) \ 			? (size)<= (MINALLOCSIZE * 512) \ 				? (size)<= (MINALLOCSIZE * 256) \ 					? (MINBUCKET + 8) \ 					: (MINBUCKET + 9) \ 				: (size)<= (MINALLOCSIZE * 1024) \ 					? (MINBUCKET + 10) \ 					: (MINBUCKET + 11) \ 			: (size)<= (MINALLOCSIZE * 8192) \ 				? (size)<= (MINALLOCSIZE * 4096) \ 					? (MINBUCKET + 12) \ 					: (MINBUCKET + 13) \ 				: (size)<= (MINALLOCSIZE * 16384) \ 					? (MINBUCKET + 14) \ 					: (MINBUCKET + 15))
end_define

begin_comment
comment|/*  * Turn virtual addresses into kmem map indices  */
end_comment

begin_define
define|#
directive|define
name|kmemxtob
parameter_list|(
name|alloc
parameter_list|)
value|(kmembase + (alloc) * PAGE_SIZE)
end_define

begin_define
define|#
directive|define
name|btokmemx
parameter_list|(
name|addr
parameter_list|)
value|(((caddr_t)(addr) - kmembase) / PAGE_SIZE)
end_define

begin_define
define|#
directive|define
name|btokup
parameter_list|(
name|addr
parameter_list|)
value|(&kmemusage[(caddr_t)(addr) - kmembase>> PAGE_SHIFT])
end_define

begin_comment
comment|/*  * Macro versions for the usual cases of malloc/free  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|KMEMSTATS
argument_list|)
operator|||
name|defined
argument_list|(
name|DIAGNOSTIC
argument_list|)
end_if

begin_define
define|#
directive|define
name|MALLOC
parameter_list|(
name|space
parameter_list|,
name|cast
parameter_list|,
name|size
parameter_list|,
name|type
parameter_list|,
name|flags
parameter_list|)
define|\
value|(space) = (cast)malloc((u_long)(size), type, flags)
end_define

begin_define
define|#
directive|define
name|FREE
parameter_list|(
name|addr
parameter_list|,
name|type
parameter_list|)
value|free((addr), type)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* do not collect statistics */
end_comment

begin_define
define|#
directive|define
name|MALLOC
parameter_list|(
name|space
parameter_list|,
name|cast
parameter_list|,
name|size
parameter_list|,
name|type
parameter_list|,
name|flags
parameter_list|)
value|do { \ 	register struct kmembuckets *kbp =&bucket[BUCKETINDX(size)]; \ 	long s = splimp(); \ 	if (kbp->kb_next == NULL) { \ 		(space) = (cast)malloc((u_long)(size), type, flags); \ 	} else { \ 		(space) = (cast)kbp->kb_next; \ 		kbp->kb_next = *(caddr_t *)(space); \ 	} \ 	splx(s); \ } while (0)
end_define

begin_define
define|#
directive|define
name|FREE
parameter_list|(
name|addr
parameter_list|,
name|type
parameter_list|)
value|do { \ 	register struct kmembuckets *kbp; \ 	register struct kmemusage *kup = btokup(addr); \ 	long s = splimp(); \ 	if (1<< kup->ku_indx> MAXALLOCSAVE) { \ 		free((addr), type); \ 	} else { \ 		kbp =&bucket[kup->ku_indx]; \ 		if (kbp->kb_next == NULL) \ 			kbp->kb_next = (caddr_t)(addr); \ 		else \ 			*(caddr_t *)(kbp->kb_last) = (caddr_t)(addr); \ 		*(caddr_t *)(addr) = NULL; \ 		kbp->kb_last = (caddr_t)(addr); \ 	} \ 	splx(s); \ } while (0)
end_define

begin_decl_stmt
specifier|extern
name|struct
name|kmemusage
modifier|*
name|kmemusage
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|kmembase
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|kmembuckets
name|bucket
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* do not collect statistics */
end_comment

begin_decl_stmt
name|void
modifier|*
name|contigmalloc
name|__P
argument_list|(
operator|(
name|unsigned
name|long
name|size
operator|,
expr|struct
name|malloc_type
operator|*
name|type
operator|,
name|int
name|flags
operator|,
name|unsigned
name|long
name|low
operator|,
name|unsigned
name|long
name|high
operator|,
name|unsigned
name|long
name|alignment
operator|,
name|unsigned
name|long
name|boundary
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|free
name|__P
argument_list|(
operator|(
name|void
operator|*
name|addr
operator|,
expr|struct
name|malloc_type
operator|*
name|type
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
modifier|*
name|malloc
name|__P
argument_list|(
operator|(
name|unsigned
name|long
name|size
operator|,
expr|struct
name|malloc_type
operator|*
name|type
operator|,
name|int
name|flags
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

begin_comment
comment|/* !_SYS_MALLOC_H_ */
end_comment

end_unit

