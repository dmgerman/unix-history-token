begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)param.h	7.5 (Berkeley) 6/5/87  */
end_comment

begin_define
define|#
directive|define
name|BSD
value|43
end_define

begin_comment
comment|/* 4.3 * 10, as cpp doesn't do floats */
end_comment

begin_define
define|#
directive|define
name|BSD4_3
value|1
end_define

begin_comment
comment|/*  * Machine-independent constants  */
end_comment

begin_define
define|#
directive|define
name|NMOUNT
value|20
end_define

begin_comment
comment|/* number of mountable file systems */
end_comment

begin_comment
comment|/* NMOUNT must be<= 255 unless c_mdev (cmap.h) is expanded */
end_comment

begin_define
define|#
directive|define
name|MSWAPX
value|NMOUNT
end_define

begin_comment
comment|/* pseudo mount table index for swapdev */
end_comment

begin_define
define|#
directive|define
name|MAXUPRC
value|40
end_define

begin_comment
comment|/* max processes per user */
end_comment

begin_define
define|#
directive|define
name|NOFILE
value|64
end_define

begin_comment
comment|/* max open files per process */
end_comment

begin_define
define|#
directive|define
name|CANBSIZ
value|256
end_define

begin_comment
comment|/* max size of typewriter line */
end_comment

begin_define
define|#
directive|define
name|NCARGS
value|20480
end_define

begin_comment
comment|/* # characters in exec arglist */
end_comment

begin_define
define|#
directive|define
name|MAXINTERP
value|32
end_define

begin_comment
comment|/* maximum interpreter file name length */
end_comment

begin_define
define|#
directive|define
name|NGROUPS
value|16
end_define

begin_comment
comment|/* max number groups */
end_comment

begin_define
define|#
directive|define
name|MAXHOSTNAMELEN
value|64
end_define

begin_comment
comment|/* maximum hostname size */
end_comment

begin_define
define|#
directive|define
name|NOGROUP
value|65535
end_define

begin_comment
comment|/* marker for empty group set member */
end_comment

begin_comment
comment|/*  * Priorities  */
end_comment

begin_define
define|#
directive|define
name|PSWP
value|0
end_define

begin_define
define|#
directive|define
name|PINOD
value|10
end_define

begin_define
define|#
directive|define
name|PRIBIO
value|20
end_define

begin_define
define|#
directive|define
name|PRIUBA
value|24
end_define

begin_define
define|#
directive|define
name|PZERO
value|25
end_define

begin_define
define|#
directive|define
name|PPIPE
value|26
end_define

begin_define
define|#
directive|define
name|PWAIT
value|30
end_define

begin_define
define|#
directive|define
name|PLOCK
value|35
end_define

begin_define
define|#
directive|define
name|PSLEP
value|40
end_define

begin_define
define|#
directive|define
name|PUSER
value|50
end_define

begin_define
define|#
directive|define
name|NZERO
value|0
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|KERNEL
end_ifndef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_include
include|#
directive|include
file|"types.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Signals  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_include
include|#
directive|include
file|"signal.h"
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ISSIG
parameter_list|(
name|p
parameter_list|)
define|\
value|((p)->p_sig&& ((p)->p_flag&STRC || \ 	 ((p)->p_sig&~ ((p)->p_sigignore | (p)->p_sigmask)))&& issig())
end_define

begin_comment
comment|/*  * Machine type dependent parameters.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_include
include|#
directive|include
file|"../machine/machparam.h"
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<machine/machparam.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|NBPW
value|sizeof(int)
end_define

begin_comment
comment|/* number of bytes in an integer */
end_comment

begin_define
define|#
directive|define
name|NULL
value|0
end_define

begin_define
define|#
directive|define
name|CMASK
value|022
end_define

begin_comment
comment|/* default mask for file creation */
end_comment

begin_define
define|#
directive|define
name|NODEV
value|(dev_t)(-1)
end_define

begin_comment
comment|/*  * Clustering of hardware pages on machines with ridiculously small  * page sizes is done here.  The paging subsystem deals with units of  * CLSIZE pte's describing NBPG (from machine/machparam.h) pages each.  *  * NOTE: SSIZE, SINCR and UPAGES must be multiples of CLSIZE  */
end_comment

begin_define
define|#
directive|define
name|CLBYTES
value|(CLSIZE*NBPG)
end_define

begin_define
define|#
directive|define
name|CLOFSET
value|(CLSIZE*NBPG-1)
end_define

begin_comment
comment|/* for clusters, like PGOFSET */
end_comment

begin_define
define|#
directive|define
name|claligned
parameter_list|(
name|x
parameter_list|)
value|((((int)(x))&CLOFSET)==0)
end_define

begin_define
define|#
directive|define
name|CLOFF
value|CLOFSET
end_define

begin_define
define|#
directive|define
name|CLSHIFT
value|(PGSHIFT+CLSIZELOG2)
end_define

begin_if
if|#
directive|if
name|CLSIZE
operator|==
literal|1
end_if

begin_define
define|#
directive|define
name|clbase
parameter_list|(
name|i
parameter_list|)
value|(i)
end_define

begin_define
define|#
directive|define
name|clrnd
parameter_list|(
name|i
parameter_list|)
value|(i)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* give the base virtual address (first of CLSIZE) */
end_comment

begin_define
define|#
directive|define
name|clbase
parameter_list|(
name|i
parameter_list|)
value|((i)&~ (CLSIZE-1))
end_define

begin_comment
comment|/* round a number of clicks up to a whole cluster */
end_comment

begin_define
define|#
directive|define
name|clrnd
parameter_list|(
name|i
parameter_list|)
value|(((i) + (CLSIZE-1))&~ (CLSIZE-1))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CBLOCK is the size of a clist block, must be power of 2 */
end_comment

begin_define
define|#
directive|define
name|CBLOCK
value|64
end_define

begin_define
define|#
directive|define
name|CBSIZE
value|(CBLOCK - sizeof(struct cblock *))
end_define

begin_comment
comment|/* data chars/clist */
end_comment

begin_define
define|#
directive|define
name|CROUND
value|(CBLOCK - 1)
end_define

begin_comment
comment|/* clist rounding */
end_comment

begin_comment
comment|/*  * File system parameters and macros.  *  * The file system is made out of blocks of at most MAXBSIZE units,  * with smaller units (fragments) only in the last direct block.  * MAXBSIZE primarily determines the size of buffers in the buffer  * pool. It may be made larger without any effect on existing  * file systems; however making it smaller make make some file  * systems unmountable.  *  * Note that the blocked devices are assumed to have DEV_BSIZE  * "sectors" and that fragments must be some multiple of this size.  * Block devices are read in BLKDEV_IOSIZE units. This number must  * be a power of two and in the range of  *	DEV_BSIZE<= BLKDEV_IOSIZE<= MAXBSIZE  * This size has no effect upon the file system, but is usually set  * to the block size of the root file system, so as to maximize the  * speed of ``fsck''.  */
end_comment

begin_define
define|#
directive|define
name|MAXBSIZE
value|8192
end_define

begin_define
define|#
directive|define
name|MAXFRAG
value|8
end_define

begin_comment
comment|/*  * MAXPATHLEN defines the longest permissable path length  * after expanding symbolic links. It is used to allocate  * a temporary buffer from the buffer pool in which to do the  * name expansion, hence should be a power of two, and must  * be less than or equal to MAXBSIZE.  * MAXSYMLINKS defines the maximum number of symbolic links  * that may be expanded in a path name. It should be set high  * enough to allow all legitimate uses, but halt infinite loops  * reasonably quickly.  */
end_comment

begin_define
define|#
directive|define
name|MAXPATHLEN
value|1024
end_define

begin_define
define|#
directive|define
name|MAXSYMLINKS
value|8
end_define

begin_comment
comment|/*  * Constants for setting the parameters of the kernel memory allocator.  *  * 2 ** MINBUCKET is the smallest unit of memory that will be  * allocated. It must be at least large enough to hold a pointer.  *  * Units of memory less or equal to MAXALLOCSAVE will permanently  * allocate physical memory; requests for these size pieces of  * memory are quite fast. Allocations greater than MAXALLOCSAVE must  * always allocate and free physical memory; requests for these  * size allocations should be done infrequently as they will be slow.  * Constraints: CLBYTES<= MAXALLOCSAVE<= 2 ** (MINBUCKET + 14)  * and MAXALLOCSIZE must be a power of two.  */
end_comment

begin_define
define|#
directive|define
name|MINBUCKET
value|4
end_define

begin_comment
comment|/* 4 => min allocation of 16 bytes */
end_comment

begin_define
define|#
directive|define
name|MAXALLOCSAVE
value|(2 * CLBYTES)
end_define

begin_comment
comment|/*  * bit map related macros  */
end_comment

begin_define
define|#
directive|define
name|setbit
parameter_list|(
name|a
parameter_list|,
name|i
parameter_list|)
value|((a)[(i)/NBBY] |= 1<<((i)%NBBY))
end_define

begin_define
define|#
directive|define
name|clrbit
parameter_list|(
name|a
parameter_list|,
name|i
parameter_list|)
value|((a)[(i)/NBBY]&= ~(1<<((i)%NBBY)))
end_define

begin_define
define|#
directive|define
name|isset
parameter_list|(
name|a
parameter_list|,
name|i
parameter_list|)
value|((a)[(i)/NBBY]& (1<<((i)%NBBY)))
end_define

begin_define
define|#
directive|define
name|isclr
parameter_list|(
name|a
parameter_list|,
name|i
parameter_list|)
value|(((a)[(i)/NBBY]& (1<<((i)%NBBY))) == 0)
end_define

begin_comment
comment|/*  * Macros for fast min/max.  */
end_comment

begin_define
define|#
directive|define
name|MIN
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(((a)<(b))?(a):(b))
end_define

begin_define
define|#
directive|define
name|MAX
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(((a)>(b))?(a):(b))
end_define

begin_comment
comment|/*  * Macros for counting and rounding.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|howmany
end_ifndef

begin_define
define|#
directive|define
name|howmany
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(((x)+((y)-1))/(y))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|roundup
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((((x)+((y)-1))/(y))*(y))
end_define

begin_define
define|#
directive|define
name|powerof2
parameter_list|(
name|x
parameter_list|)
value|((((x)-1)&(x))==0)
end_define

end_unit

