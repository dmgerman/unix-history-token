begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	param.h	6.1	83/07/29	*/
end_comment

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
file|"../machine/param.h"
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<machine/param.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|NPTEPG
value|(NBPG/(sizeof (struct pte)))
end_define

begin_comment
comment|/*  * Machine-independent constants  */
end_comment

begin_define
define|#
directive|define
name|NMOUNT
value|15
end_define

begin_comment
comment|/* number of mountable file systems */
end_comment

begin_define
define|#
directive|define
name|MSWAPX
value|15
end_define

begin_comment
comment|/* pseudo mount table index for swapdev */
end_comment

begin_define
define|#
directive|define
name|MAXUPRC
value|25
end_define

begin_comment
comment|/* max processes per user */
end_comment

begin_define
define|#
directive|define
name|NOFILE
value|20
end_define

begin_comment
comment|/* max open files per process */
end_comment

begin_comment
comment|/* NOFILE MUST NOT BE>= 31; SEE pte.h */
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
value|10240
end_define

begin_comment
comment|/* # characters in exec arglist */
end_comment

begin_define
define|#
directive|define
name|NGROUPS
value|8
end_define

begin_comment
comment|/* max number groups */
end_comment

begin_define
define|#
directive|define
name|NOGROUP
value|-1
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
value|20
end_define

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
file|"../h/signal.h"
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
comment|/*  * Fundamental constants of the implementation.  */
end_comment

begin_define
define|#
directive|define
name|NBBY
value|8
end_define

begin_comment
comment|/* number of bits in a byte */
end_comment

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
value|0
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
comment|/*  * Clustering of hardware pages on machines with ridiculously small  * page sizes is done here.  The paging subsystem deals with units of  * CLSIZE pte's describing NBPG (from vm.h) pages each... BSIZE must  * be CLSIZE*NBPG in the current implementation, that is the paging subsystem  * deals with the same size blocks that the file system uses.  *  * NOTE: SSIZE, SINCR and UPAGES must be multiples of CLSIZE  */
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

begin_ifndef
ifndef|#
directive|ifndef
name|INTRLVE
end_ifndef

begin_comment
comment|/* macros replacing interleaving functions */
end_comment

begin_define
define|#
directive|define
name|dkblock
parameter_list|(
name|bp
parameter_list|)
value|((bp)->b_blkno)
end_define

begin_define
define|#
directive|define
name|dkunit
parameter_list|(
name|bp
parameter_list|)
value|(minor((bp)->b_dev)>> 3)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|CBSIZE
value|28
end_define

begin_comment
comment|/* number of chars in a clist block */
end_comment

begin_define
define|#
directive|define
name|CROUND
value|0x1F
end_define

begin_comment
comment|/* clist rounding; sizeof(int *) + CBSIZE -1*/
end_comment

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
file|"../h/types.h"
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
name|DEV_BSIZE
value|512
end_define

begin_define
define|#
directive|define
name|DEV_BSHIFT
value|9
end_define

begin_comment
comment|/* log2(DEV_BSIZE) */
end_comment

begin_define
define|#
directive|define
name|BLKDEV_IOSIZE
value|2048
end_define

begin_define
define|#
directive|define
name|MAXFRAG
value|8
end_define

begin_define
define|#
directive|define
name|btodb
parameter_list|(
name|bytes
parameter_list|)
comment|/* calculates (bytes / DEV_BSIZE) */
define|\
value|((unsigned)(bytes)>> DEV_BSHIFT)
end_define

begin_define
define|#
directive|define
name|dbtob
parameter_list|(
name|db
parameter_list|)
comment|/* calculates (db * DEV_BSIZE) */
define|\
value|((unsigned)(db)<< DEV_BSHIFT)
end_define

begin_comment
comment|/*  * Map a ``block device block'' to a file system block.  * This should be device dependent, and will be after we  * add an entry to cdevsw for that purpose.  For now though  * just use DEV_BSIZE.  */
end_comment

begin_define
define|#
directive|define
name|bdbtofsb
parameter_list|(
name|bn
parameter_list|)
value|((bn) / (BLKDEV_IOSIZE/DEV_BSIZE))
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

end_unit

