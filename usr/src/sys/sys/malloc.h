begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1987 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)malloc.h	7.13 (Berkeley) %G%  */
end_comment

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
name|M_SUPERBLK
value|15
end_define

begin_comment
comment|/* super block data */
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
name|M_VNODE
value|24
end_define

begin_comment
comment|/* Dynamically allocated vnodes */
end_comment

begin_define
define|#
directive|define
name|M_CACHE
value|25
end_define

begin_comment
comment|/* Dynamically allocated cahe entries */
end_comment

begin_define
define|#
directive|define
name|M_TEMP
value|49
end_define

begin_comment
comment|/* misc temporary data buffers */
end_comment

begin_define
define|#
directive|define
name|M_LAST
value|50
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
value|(size)<= (MINALLOCSIZE * 128) \ 		? (size)<= (MINALLOCSIZE * 8) \ 			? (size)<= (MINALLOCSIZE * 2) \ 				? (size)<= (MINALLOCSIZE * 1) \ 					? (MINBUCKET + 0) \ 					: (MINBUCKET + 1) \ 				: (size)<= (MINALLOCSIZE * 4) \ 					? (MINBUCKET + 2) \ 					: (MINBUCKET + 3) \ 			: (size)<= (MINALLOCSIZE* 32) \ 				? (size)<= (MINALLOCSIZE * 16) \ 					? (MINBUCKET + 4) \ 					: (MINBUCKET + 5) \ 				: (size)<= (MINALLOCSIZE * 64) \ 					? (MINBUCKET + 6) \ 					: (MINBUCKET + 7) \ 		: (size)<= (MINALLOCSIZE * 2048) \ 			? (size)<= (MINALLOCSIZE * 512) \ 				? (size)<= (MINALLOCSIZE * 256) \ 					? (MINBUCKET + 8) \ 					: (MINBUCKET + 9) \ 				: (size)<= (MINALLOCSIZE * 1024) \ 					? (MINBUCKET + 10) \ 					: (MINBUCKET + 11) \ 			: (size)<= (MINALLOCSIZE * 8192) \ 				? (size)<= (MINALLOCSIZE * 4096) \ 					? (MINBUCKET + 12) \ 					: (MINBUCKET + 13) \ 				: (size)<= (MINALLOCSIZE * 16384) \ 					? (MINBUCKET + 14) \ 					: (MINBUCKET + 15)
end_define

begin_comment
comment|/*  * Turn virtual addresses into kmem map indicies  */
end_comment

begin_define
define|#
directive|define
name|kmemxtob
parameter_list|(
name|alloc
parameter_list|)
value|(kmembase + (alloc) * NBPG)
end_define

begin_define
define|#
directive|define
name|btokmemx
parameter_list|(
name|addr
parameter_list|)
value|(((caddr_t)(addr) - kmembase) / NBPG)
end_define

begin_define
define|#
directive|define
name|btokup
parameter_list|(
name|addr
parameter_list|)
value|(&kmemusage[((caddr_t)(addr) - kmembase)>> CLSHIFT])
end_define

begin_comment
comment|/*  * Macro versions for the usual cases of malloc/free  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KMEMSTATS
end_ifdef

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
value|free((caddr_t)(addr), type)
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
value|{ \ 	register struct kmembuckets *kbp =&bucket[BUCKETINDX(size)]; \ 	long s = splimp(); \ 	if (kbp->kb_next == NULL) { \ 		(space) = (cast)malloc((u_long)(size), type, flags); \ 	} else { \ 		(space) = (cast)kbp->kb_next; \ 		kbp->kb_next = *(caddr_t *)(space); \ 	} \ 	splx(s); \ }
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
value|{ \ 	register struct kmembuckets *kbp; \ 	register struct kmemusage *kup = btokup(addr); \ 	long s = splimp(); \ 	if (1<< kup->ku_indx> MAXALLOCSAVE) { \ 		free((caddr_t)(addr), type); \ 	} else { \ 		kbp =&bucket[kup->ku_indx]; \ 		*(caddr_t *)(addr) = kbp->kb_next; \ 		kbp->kb_next = (caddr_t)(addr); \ 	} \ 	splx(s); \ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* do not collect statistics */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|kmemstats
name|kmemstats
index|[]
decl_stmt|;
end_decl_stmt

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
name|kmembase
index|[]
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

begin_function_decl
specifier|extern
name|qaddr_t
name|malloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|free
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
endif|KERNEL
end_endif

end_unit

