begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1988 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)param.h	7.3 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Machine dependent constants for TAHOE.  */
end_comment

begin_define
define|#
directive|define
name|MACHINE
value|"tahoe"
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|BYTE_ORDER
end_ifndef

begin_include
include|#
directive|include
file|<machine/endian.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<machine/machlimits.h>
end_include

begin_define
define|#
directive|define
name|NBPG
value|1024
end_define

begin_comment
comment|/* bytes/page */
end_comment

begin_define
define|#
directive|define
name|PGOFSET
value|(NBPG-1)
end_define

begin_comment
comment|/* byte offset into page */
end_comment

begin_define
define|#
directive|define
name|PGSHIFT
value|10
end_define

begin_comment
comment|/* LOG2(NBPG) */
end_comment

begin_define
define|#
directive|define
name|NPTEPG
value|(NBPG/(sizeof (struct pte)))
end_define

begin_define
define|#
directive|define
name|KERNBASE
value|0xc0000000
end_define

begin_comment
comment|/* start of kernel virtual */
end_comment

begin_define
define|#
directive|define
name|BTOPKERNBASE
value|((u_long)KERNBASE>> PGSHIFT)
end_define

begin_define
define|#
directive|define
name|KERNBASE
value|0xc0000000
end_define

begin_comment
comment|/* start of kernel virtual */
end_comment

begin_define
define|#
directive|define
name|BTOPKERNBASE
value|((u_long)KERNBASE>> PGSHIFT)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|SECSIZE
end_ifndef

begin_define
define|#
directive|define
name|DEV_BSIZE
value|1024
end_define

begin_define
define|#
directive|define
name|DEV_BSHIFT
value|10
end_define

begin_comment
comment|/* log2(DEV_BSIZE) */
end_comment

begin_define
define|#
directive|define
name|BLKDEV_IOSIZE
value|1024
end_define

begin_comment
comment|/* NBPG for physical controllers */
end_comment

begin_define
define|#
directive|define
name|MAXPHYS
value|(64 * 1024)
end_define

begin_comment
comment|/* max raw I/O transfer size */
end_comment

begin_else
else|#
directive|else
else|SECSIZE
end_else

begin_comment
comment|/*  * Devices without disk labels and the swap virtual device  * use "blocks" of exactly pagesize.  Devices with disk labels  * use device-dependent sector sizes for block and character interfaces.  */
end_comment

begin_define
define|#
directive|define
name|DEV_BSIZE
value|NBPG
end_define

begin_define
define|#
directive|define
name|DEV_BSHIFT
value|PGSHIFT
end_define

begin_comment
comment|/* log2(DEV_BSIZE) */
end_comment

begin_define
define|#
directive|define
name|BLKDEV_IOSIZE
value|NBPG
end_define

begin_comment
comment|/* NBPG for unlabeled block devices */
end_comment

begin_endif
endif|#
directive|endif
endif|SECSIZE
end_endif

begin_define
define|#
directive|define
name|MAXPHYS
value|(64 * 1024)
end_define

begin_comment
comment|/* max raw I/O transfer size */
end_comment

begin_define
define|#
directive|define
name|CLSIZE
value|1
end_define

begin_define
define|#
directive|define
name|CLSIZELOG2
value|0
end_define

begin_define
define|#
directive|define
name|SSIZE
value|2
end_define

begin_comment
comment|/* initial stack size/NBPG */
end_comment

begin_define
define|#
directive|define
name|SINCR
value|2
end_define

begin_comment
comment|/* increment of stack/NBPG */
end_comment

begin_define
define|#
directive|define
name|UPAGES
value|8
end_define

begin_comment
comment|/* pages of u-area (2 stack pages) */
end_comment

begin_comment
comment|/*  * Constants related to network buffer management.  * MCLBYTES must be no larger than CLBYTES (the software page size), and,  * on machines that exchange pages of input or output buffers with mbuf  * clusters (MAPPED_MBUFS), MCLBYTES must also be an integral multiple  * of the hardware page size.  */
end_comment

begin_define
define|#
directive|define
name|MSIZE
value|128
end_define

begin_comment
comment|/* size of an mbuf */
end_comment

begin_define
define|#
directive|define
name|MAPPED_MBUFS
end_define

begin_comment
comment|/* can do scatter-gather I/O */
end_comment

begin_if
if|#
directive|if
name|CLBYTES
operator|>
literal|1024
end_if

begin_define
define|#
directive|define
name|MCLBYTES
value|1024
end_define

begin_define
define|#
directive|define
name|MCLSHIFT
value|10
end_define

begin_define
define|#
directive|define
name|MCLOFSET
value|(MCLBYTES - 1)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MCLBYTES
value|CLBYTES
end_define

begin_define
define|#
directive|define
name|MCLSHIFT
value|CLSHIFT
end_define

begin_define
define|#
directive|define
name|MCLOFSET
value|CLOFSET
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|GATEWAY
end_ifdef

begin_define
define|#
directive|define
name|NMBCLUSTERS
value|512
end_define

begin_comment
comment|/* map size, max cluster allocation */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NMBCLUSTERS
value|256
end_define

begin_comment
comment|/* map size, max cluster allocation */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MAXCKEY
value|255
end_define

begin_comment
comment|/* maximal allowed code key */
end_comment

begin_define
define|#
directive|define
name|MAXDKEY
value|255
end_define

begin_comment
comment|/* maximal allowed data key */
end_comment

begin_define
define|#
directive|define
name|NCKEY
value|(MAXCKEY+1)
end_define

begin_comment
comment|/* # code keys, including 0 (reserved) */
end_comment

begin_define
define|#
directive|define
name|NDKEY
value|(MAXDKEY+1)
end_define

begin_comment
comment|/* # data keys, including 0 (reserved) */
end_comment

begin_comment
comment|/*  * Some macros for units conversion  */
end_comment

begin_comment
comment|/* Core clicks (1024 bytes) to segments and vice versa */
end_comment

begin_define
define|#
directive|define
name|ctos
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_define
define|#
directive|define
name|stoc
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|SECSIZE
end_ifndef

begin_comment
comment|/* Core clicks (1024 bytes) to disk blocks */
end_comment

begin_define
define|#
directive|define
name|ctod
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_define
define|#
directive|define
name|dtoc
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_define
define|#
directive|define
name|dtob
parameter_list|(
name|x
parameter_list|)
value|((x)<<PGSHIFT)
end_define

begin_else
else|#
directive|else
else|SECSIZE
end_else

begin_comment
comment|/* Core clicks (1024 bytes) to disk blocks; deprecated */
end_comment

begin_define
define|#
directive|define
name|ctod
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_comment
comment|/* XXX */
end_comment

begin_define
define|#
directive|define
name|dtoc
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_comment
comment|/* XXX */
end_comment

begin_define
define|#
directive|define
name|dtob
parameter_list|(
name|x
parameter_list|)
value|((x)<<PGSHIFT)
end_define

begin_comment
comment|/* XXX */
end_comment

begin_endif
endif|#
directive|endif
endif|SECSIZE
end_endif

begin_comment
comment|/* clicks to bytes */
end_comment

begin_define
define|#
directive|define
name|ctob
parameter_list|(
name|x
parameter_list|)
value|((x)<<PGSHIFT)
end_define

begin_comment
comment|/* bytes to clicks */
end_comment

begin_define
define|#
directive|define
name|btoc
parameter_list|(
name|x
parameter_list|)
value|((((unsigned)(x)+NBPG-1)>> PGSHIFT))
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|SECSIZE
end_ifndef

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
comment|/*  * Map a ``block device block'' to a file system block.  * This should be device dependent, and will be if we  * add an entry to cdevsw/bdevsw for that purpose.  * For now though just use DEV_BSIZE.  */
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

begin_else
else|#
directive|else
else|SECSIZE
end_else

begin_comment
comment|/* bytes to "disk blocks" and back; deprecated */
end_comment

begin_define
define|#
directive|define
name|btodb
parameter_list|(
name|bytes
parameter_list|)
value|((unsigned)(bytes)>> DEV_BSHIFT)
end_define

begin_comment
comment|/* XXX */
end_comment

begin_define
define|#
directive|define
name|dbtob
parameter_list|(
name|db
parameter_list|)
value|((unsigned)(db)<< DEV_BSHIFT)
end_define

begin_comment
comment|/* XXX */
end_comment

begin_endif
endif|#
directive|endif
endif|SECSIZE
end_endif

begin_comment
comment|/*  * Macros to decode processor status word.  */
end_comment

begin_define
define|#
directive|define
name|USERMODE
parameter_list|(
name|ps
parameter_list|)
value|(((ps)& PSL_CURMOD) == PSL_CURMOD)
end_define

begin_define
define|#
directive|define
name|BASEPRI
parameter_list|(
name|ps
parameter_list|)
value|(((ps)& PSL_IPL) == 0)
end_define

begin_define
define|#
directive|define
name|DELAY
parameter_list|(
name|n
parameter_list|)
value|{ register int N = 3*(n); while (--N> 0); }
end_define

end_unit

