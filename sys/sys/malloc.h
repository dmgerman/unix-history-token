begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1987, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)malloc.h	8.5 (Berkeley) 5/3/95  * $Id: malloc.h,v 1.24 1997/09/16 13:52:04 bde Exp $  */
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

begin_comment
comment|/*  * Types of memory to be allocated  */
end_comment

begin_define
define|#
directive|define
name|M_FREE
value|0
end_define

begin_comment
comment|/* should be on free list */
end_comment

begin_define
define|#
directive|define
name|M_MBUF
value|1
end_define

begin_comment
comment|/* mbuf */
end_comment

begin_define
define|#
directive|define
name|M_DEVBUF
value|2
end_define

begin_comment
comment|/* device driver memory */
end_comment

begin_define
define|#
directive|define
name|M_SOCKET
value|3
end_define

begin_comment
comment|/* socket structure */
end_comment

begin_define
define|#
directive|define
name|M_PCB
value|4
end_define

begin_comment
comment|/* protocol control block */
end_comment

begin_define
define|#
directive|define
name|M_RTABLE
value|5
end_define

begin_comment
comment|/* routing tables */
end_comment

begin_define
define|#
directive|define
name|M_HTABLE
value|6
end_define

begin_comment
comment|/* IMP host tables */
end_comment

begin_define
define|#
directive|define
name|M_FTABLE
value|7
end_define

begin_comment
comment|/* fragment reassembly header */
end_comment

begin_define
define|#
directive|define
name|M_ZOMBIE
value|8
end_define

begin_comment
comment|/* zombie proc status */
end_comment

begin_define
define|#
directive|define
name|M_IFADDR
value|9
end_define

begin_comment
comment|/* interface address */
end_comment

begin_define
define|#
directive|define
name|M_SOOPTS
value|10
end_define

begin_comment
comment|/* socket options */
end_comment

begin_define
define|#
directive|define
name|M_SONAME
value|11
end_define

begin_comment
comment|/* socket name */
end_comment

begin_define
define|#
directive|define
name|M_NAMEI
value|12
end_define

begin_comment
comment|/* namei path name buffer */
end_comment

begin_define
define|#
directive|define
name|M_GPROF
value|13
end_define

begin_comment
comment|/* kernel profiling buffer */
end_comment

begin_define
define|#
directive|define
name|M_IOCTLOPS
value|14
end_define

begin_comment
comment|/* ioctl data buffer */
end_comment

begin_define
define|#
directive|define
name|M_MAPMEM
value|15
end_define

begin_comment
comment|/* mapped memory descriptors */
end_comment

begin_define
define|#
directive|define
name|M_CRED
value|16
end_define

begin_comment
comment|/* credentials */
end_comment

begin_define
define|#
directive|define
name|M_PGRP
value|17
end_define

begin_comment
comment|/* process group header */
end_comment

begin_define
define|#
directive|define
name|M_SESSION
value|18
end_define

begin_comment
comment|/* session header */
end_comment

begin_define
define|#
directive|define
name|M_IOV
value|19
end_define

begin_comment
comment|/* large iov's */
end_comment

begin_define
define|#
directive|define
name|M_MOUNT
value|20
end_define

begin_comment
comment|/* vfs mount struct */
end_comment

begin_define
define|#
directive|define
name|M_FHANDLE
value|21
end_define

begin_comment
comment|/* network file handle */
end_comment

begin_define
define|#
directive|define
name|M_NFSREQ
value|22
end_define

begin_comment
comment|/* NFS request header */
end_comment

begin_define
define|#
directive|define
name|M_NFSMNT
value|23
end_define

begin_comment
comment|/* NFS mount structure */
end_comment

begin_define
define|#
directive|define
name|M_NFSNODE
value|24
end_define

begin_comment
comment|/* NFS vnode private part */
end_comment

begin_define
define|#
directive|define
name|M_VNODE
value|25
end_define

begin_comment
comment|/* Dynamically allocated vnodes */
end_comment

begin_define
define|#
directive|define
name|M_CACHE
value|26
end_define

begin_comment
comment|/* Dynamically allocated cache entries */
end_comment

begin_define
define|#
directive|define
name|M_DQUOT
value|27
end_define

begin_comment
comment|/* UFS quota entries */
end_comment

begin_define
define|#
directive|define
name|M_UFSMNT
value|28
end_define

begin_comment
comment|/* UFS mount structure */
end_comment

begin_define
define|#
directive|define
name|M_SHM
value|29
end_define

begin_comment
comment|/* SVID compatible shared memory segments */
end_comment

begin_define
define|#
directive|define
name|M_VMMAP
value|30
end_define

begin_comment
comment|/* VM map structures */
end_comment

begin_define
define|#
directive|define
name|M_VMMAPENT
value|31
end_define

begin_comment
comment|/* VM map entry structures */
end_comment

begin_define
define|#
directive|define
name|M_VMOBJ
value|32
end_define

begin_comment
comment|/* VM object structure */
end_comment

begin_define
define|#
directive|define
name|M_VMOBJHASH
value|33
end_define

begin_comment
comment|/* VM object hash structure */
end_comment

begin_define
define|#
directive|define
name|M_VMPMAP
value|34
end_define

begin_comment
comment|/* VM pmap */
end_comment

begin_define
define|#
directive|define
name|M_VMPVENT
value|35
end_define

begin_comment
comment|/* VM phys-virt mapping entry */
end_comment

begin_define
define|#
directive|define
name|M_VMPAGER
value|36
end_define

begin_comment
comment|/* XXX: VM pager struct */
end_comment

begin_define
define|#
directive|define
name|M_VMPGDATA
value|37
end_define

begin_comment
comment|/* XXX: VM pager private data */
end_comment

begin_define
define|#
directive|define
name|M_FILE
value|38
end_define

begin_comment
comment|/* Open file structure */
end_comment

begin_define
define|#
directive|define
name|M_FILEDESC
value|39
end_define

begin_comment
comment|/* Open file descriptor table */
end_comment

begin_define
define|#
directive|define
name|M_LOCKF
value|40
end_define

begin_comment
comment|/* Byte-range locking structures */
end_comment

begin_define
define|#
directive|define
name|M_PROC
value|41
end_define

begin_comment
comment|/* Proc structures */
end_comment

begin_define
define|#
directive|define
name|M_SUBPROC
value|42
end_define

begin_comment
comment|/* Proc sub-structures */
end_comment

begin_define
define|#
directive|define
name|M_SEGMENT
value|43
end_define

begin_comment
comment|/* Segment for LFS */
end_comment

begin_define
define|#
directive|define
name|M_LFSNODE
value|44
end_define

begin_comment
comment|/* LFS vnode private part */
end_comment

begin_define
define|#
directive|define
name|M_FFSNODE
value|45
end_define

begin_comment
comment|/* FFS vnode private part */
end_comment

begin_define
define|#
directive|define
name|M_MFSNODE
value|46
end_define

begin_comment
comment|/* MFS vnode private part */
end_comment

begin_define
define|#
directive|define
name|M_NQLEASE
value|47
end_define

begin_comment
comment|/* Nqnfs lease */
end_comment

begin_define
define|#
directive|define
name|M_NQMHOST
value|48
end_define

begin_comment
comment|/* Nqnfs host address table */
end_comment

begin_define
define|#
directive|define
name|M_NETADDR
value|49
end_define

begin_comment
comment|/* Export host address structure */
end_comment

begin_define
define|#
directive|define
name|M_NFSSVC
value|50
end_define

begin_comment
comment|/* Nfs server structure */
end_comment

begin_define
define|#
directive|define
name|M_NFSUID
value|51
end_define

begin_comment
comment|/* Nfs uid mapping structure */
end_comment

begin_define
define|#
directive|define
name|M_NFSD
value|52
end_define

begin_comment
comment|/* Nfs server daemon structure */
end_comment

begin_define
define|#
directive|define
name|M_IPMOPTS
value|53
end_define

begin_comment
comment|/* internet multicast options */
end_comment

begin_define
define|#
directive|define
name|M_IPMADDR
value|54
end_define

begin_comment
comment|/* internet multicast address */
end_comment

begin_define
define|#
directive|define
name|M_IFMADDR
value|55
end_define

begin_comment
comment|/* link-level multicast address */
end_comment

begin_define
define|#
directive|define
name|M_MRTABLE
value|56
end_define

begin_comment
comment|/* multicast routing tables */
end_comment

begin_define
define|#
directive|define
name|M_ISOFSMNT
value|57
end_define

begin_comment
comment|/* ISOFS mount structure */
end_comment

begin_define
define|#
directive|define
name|M_ISOFSNODE
value|58
end_define

begin_comment
comment|/* ISOFS vnode private part */
end_comment

begin_define
define|#
directive|define
name|M_NFSRVDESC
value|59
end_define

begin_comment
comment|/* NFS server socket descriptor */
end_comment

begin_define
define|#
directive|define
name|M_NFSDIROFF
value|60
end_define

begin_comment
comment|/* NFS directory offset data */
end_comment

begin_define
define|#
directive|define
name|M_NFSBIGFH
value|61
end_define

begin_comment
comment|/* NFS version 3 file handle */
end_comment

begin_define
define|#
directive|define
name|M_MSDOSFSMNT
value|67
end_define

begin_comment
comment|/* MSDOSFS mount structure */
end_comment

begin_define
define|#
directive|define
name|M_MSDOSFSNODE
value|68
end_define

begin_comment
comment|/* MSDOSFS vnode private part */
end_comment

begin_define
define|#
directive|define
name|M_MSDOSFSFAT
value|69
end_define

begin_comment
comment|/* MSDOSFS file allocation table */
end_comment

begin_define
define|#
directive|define
name|M_DEVFSMNT
value|70
end_define

begin_comment
comment|/* DEVFS mount structure */
end_comment

begin_define
define|#
directive|define
name|M_DEVFSBACK
value|71
end_define

begin_comment
comment|/* DEVFS Back node */
end_comment

begin_define
define|#
directive|define
name|M_DEVFSFRONT
value|72
end_define

begin_comment
comment|/* DEVFS Front node */
end_comment

begin_define
define|#
directive|define
name|M_DEVFSNODE
value|73
end_define

begin_comment
comment|/* DEVFS node */
end_comment

begin_define
define|#
directive|define
name|M_TEMP
value|74
end_define

begin_comment
comment|/* misc temporary data buffers */
end_comment

begin_define
define|#
directive|define
name|M_TTYS
value|75
end_define

begin_comment
comment|/* tty data structures */
end_comment

begin_define
define|#
directive|define
name|M_GZIP
value|76
end_define

begin_comment
comment|/* Gzip trees */
end_comment

begin_define
define|#
directive|define
name|M_IPFW
value|77
end_define

begin_comment
comment|/* IpFw/IpAcct chain's */
end_comment

begin_define
define|#
directive|define
name|M_DEVL
value|78
end_define

begin_comment
comment|/* isa_device lists in userconfig() */
end_comment

begin_define
define|#
directive|define
name|M_PKTCLASS
value|79
end_define

begin_comment
comment|/* structures used in packet classifier */
end_comment

begin_define
define|#
directive|define
name|M_SYSCTL
value|80
end_define

begin_comment
comment|/* sysctl internal magic */
end_comment

begin_define
define|#
directive|define
name|M_SECA
value|81
end_define

begin_comment
comment|/* security associations, key management */
end_comment

begin_define
define|#
directive|define
name|M_BIOBUF
value|82
end_define

begin_comment
comment|/* BIO buffer */
end_comment

begin_define
define|#
directive|define
name|M_KTRACE
value|83
end_define

begin_comment
comment|/* KTRACE */
end_comment

begin_define
define|#
directive|define
name|M_SELECT
value|84
end_define

begin_comment
comment|/* select() buffer */
end_comment

begin_define
define|#
directive|define
name|M_GEOM_DEV
value|85
end_define

begin_comment
comment|/* geometry device */
end_comment

begin_define
define|#
directive|define
name|M_GEOM_MOD
value|86
end_define

begin_comment
comment|/* geometry module */
end_comment

begin_define
define|#
directive|define
name|M_GEOM_REQ
value|87
end_define

begin_comment
comment|/* geometry request */
end_comment

begin_define
define|#
directive|define
name|M_GEOM_MISC
value|88
end_define

begin_comment
comment|/* geometry misc */
end_comment

begin_define
define|#
directive|define
name|M_VFSCONF
value|89
end_define

begin_comment
comment|/* vfsconf structure */
end_comment

begin_define
define|#
directive|define
name|M_AIO
value|90
end_define

begin_comment
comment|/* AIO structure(s) */
end_comment

begin_define
define|#
directive|define
name|M_ZONE
value|91
end_define

begin_comment
comment|/* Zone header */
end_comment

begin_define
define|#
directive|define
name|M_HOSTCACHE
value|92
end_define

begin_comment
comment|/* per-host information cache structure */
end_comment

begin_define
define|#
directive|define
name|M_LAST
value|93
end_define

begin_comment
comment|/* Must be last type + 1 */
end_comment

begin_define
define|#
directive|define
name|INITKMEMNAMES
value|{ \ 	"free",
comment|/* 0 M_FREE */
value|\ 	"mbuf",
comment|/* 1 M_MBUF */
value|\ 	"devbuf",
comment|/* 2 M_DEVBUF */
value|\ 	"socket",
comment|/* 3 M_SOCKET */
value|\ 	"pcb",
comment|/* 4 M_PCB */
value|\ 	"routetbl",
comment|/* 5 M_RTABLE */
value|\ 	"hosttbl",
comment|/* 6 M_HTABLE */
value|\ 	"fragtbl",
comment|/* 7 M_FTABLE */
value|\ 	"zombie",
comment|/* 8 M_ZOMBIE */
value|\ 	"ifaddr",
comment|/* 9 M_IFADDR */
value|\ 	"soopts",
comment|/* 10 M_SOOPTS */
value|\ 	"soname",
comment|/* 11 M_SONAME */
value|\ 	"namei",
comment|/* 12 M_NAMEI */
value|\ 	"gprof",
comment|/* 13 M_GPROF */
value|\ 	"ioctlops",
comment|/* 14 M_IOCTLOPS */
value|\ 	"mapmem",
comment|/* 15 M_MAPMEM */
value|\ 	"cred",
comment|/* 16 M_CRED */
value|\ 	"pgrp",
comment|/* 17 M_PGRP */
value|\ 	"session",
comment|/* 18 M_SESSION */
value|\ 	"iov",
comment|/* 19 M_IOV */
value|\ 	"mount",
comment|/* 20 M_MOUNT */
value|\ 	"fhandle",
comment|/* 21 M_FHANDLE */
value|\ 	"NFS req",
comment|/* 22 M_NFSREQ */
value|\ 	"NFS mount",
comment|/* 23 M_NFSMNT */
value|\ 	"NFS node",
comment|/* 24 M_NFSNODE */
value|\ 	"vnodes",
comment|/* 25 M_VNODE */
value|\ 	"namecache",
comment|/* 26 M_CACHE */
value|\ 	"UFS quota",
comment|/* 27 M_DQUOT */
value|\ 	"UFS mount",
comment|/* 28 M_UFSMNT */
value|\ 	"shm",
comment|/* 29 M_SHM */
value|\ 	"VM map",
comment|/* 30 M_VMMAP */
value|\ 	"VM mapent",
comment|/* 31 M_VMMAPENT */
value|\ 	"VM object",
comment|/* 32 M_VMOBJ */
value|\ 	"VM objhash",
comment|/* 33 M_VMOBJHASH */
value|\ 	"VM pmap",
comment|/* 34 M_VMPMAP */
value|\ 	"VM pvmap",
comment|/* 35 M_VMPVENT */
value|\ 	"VM pager",
comment|/* 36 M_VMPAGER */
value|\ 	"VM pgdata",
comment|/* 37 M_VMPGDATA */
value|\ 	"file",
comment|/* 38 M_FILE */
value|\ 	"file desc",
comment|/* 39 M_FILEDESC */
value|\ 	"lockf",
comment|/* 40 M_LOCKF */
value|\ 	"proc",
comment|/* 41 M_PROC */
value|\ 	"subproc",
comment|/* 42 M_SUBPROC */
value|\ 	"LFS segment",
comment|/* 43 M_SEGMENT */
value|\ 	"LFS node",
comment|/* 44 M_LFSNODE */
value|\ 	"FFS node",
comment|/* 45 M_FFSNODE */
value|\ 	"MFS node",
comment|/* 46 M_MFSNODE */
value|\ 	"NQNFS Lease",
comment|/* 47 M_NQLEASE */
value|\ 	"NQNFS Host",
comment|/* 48 M_NQMHOST */
value|\ 	"Export Host",
comment|/* 49 M_NETADDR */
value|\ 	"NFS srvsock",
comment|/* 50 M_NFSSVC */
value|\ 	"NFS uid",
comment|/* 51 M_NFSUID */
value|\ 	"NFS daemon",
comment|/* 52 M_NFSD */
value|\ 	"ip_moptions",
comment|/* 53 M_IPMOPTS */
value|\ 	"in_multi",
comment|/* 54 M_IPMADDR */
value|\ 	"ether_multi",
comment|/* 55 M_IFMADDR */
value|\ 	"mrt",
comment|/* 56 M_MRTABLE */
value|\ 	"ISOFS mount",
comment|/* 57 M_ISOFSMNT */
value|\ 	"ISOFS node",
comment|/* 58 M_ISOFSNODE */
value|\ 	"NFSV3 srvdesc",
comment|/* 59 M_NFSRVDESC */
value|\ 	"NFSV3 diroff",
comment|/* 60 M_NFSDIROFF */
value|\ 	"NFSV3 bigfh",
comment|/* 61 M_NFSBIGFH */
value|\ 	NULL, \ 	NULL, NULL, NULL, NULL, \ 	"MSDOSFS mount",
comment|/* 67 M_MSDOSFSMNT */
value|\ 	"MSDOSFS node",
comment|/* 68 M_MSDOSFSNODE */
value|\ 	"MSDOSFS FAT",
comment|/* 69 M_MSDOSFSFAR */
value|\ 	"DEVFS mount",
comment|/* 70 M_DEVFSMNT */
value|\ 	"DEVFS back",
comment|/* 71 M_DEVFSBACK */
value|\ 	"DEVFS front",
comment|/* 72 M_DEVFSFRONT */
value|\ 	"DEVFS node",
comment|/* 73 M_DEVFSNODE */
value|\ 	"temp",
comment|/* 74 M_TEMP */
value|\ 	"ttys",
comment|/* 75 M_TTYS */
value|\ 	"Gzip trees",
comment|/* 76 M_GZIP */
value|\ 	"IpFw/IpAcct",
comment|/* 77 M_IPFW */
value|\ 	"isa_devlist",
comment|/* 78 M_DEVL */
value|\ 	"PktClass",
comment|/* 79 M_PKTCLASS */
value|\ 	"sysctl",
comment|/* 80 M_SYSCTL */
value|\ 	"key mgmt",
comment|/* 81 M_SECA */
value|\ 	"BIO buffer",
comment|/* 82 M_BIOBUF */
value|\ 	"KTRACE",
comment|/* 83 M_KTRACE */
value|\ 	"select",
comment|/* 84 M_SELECT */
value|\ 	"GEOM dev",
comment|/* 85 M_GEOM_DEV */
value|\ 	"GEOM mod",
comment|/* 86 M_GEOM_MOD */
value|\ 	"GEOM req",
comment|/* 87 M_GEOM_REQ */
value|\ 	"GEOM misc",
comment|/* 88 M_GEOM_MISC */
value|\ 	"VFS conf",
comment|/* 89 M_VFSCONF */
value|\ 	"AIO",
comment|/* 90 M_AIO */
value|\ 	"ZONE",
comment|/* 91 M_ZONE */
value|\ 	"hostcache",
comment|/* 92 M_HOSTCACHE */
value|\ }
end_define

begin_struct
struct|struct
name|kmemstats
block|{
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
name|int
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
name|int
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
name|int
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

