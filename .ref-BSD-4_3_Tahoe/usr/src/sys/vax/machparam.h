begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)machparam.h	7.10 (Berkeley) 1/21/88  */
end_comment

begin_comment
comment|/*  * Machine dependent constants for VAX.  */
end_comment

begin_define
define|#
directive|define
name|MACHINE
value|"vax"
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

begin_define
define|#
directive|define
name|CHAR_BIT
value|NBBY
end_define

begin_define
define|#
directive|define
name|CHAR_MAX
value|0x7f
end_define

begin_define
define|#
directive|define
name|CHAR_MIN
value|0x80
end_define

begin_define
define|#
directive|define
name|CLK_TCK
value|60
end_define

begin_comment
comment|/* for times() */
end_comment

begin_define
define|#
directive|define
name|INT_MAX
value|0x7fffffff
end_define

begin_define
define|#
directive|define
name|INT_MIN
value|0x80000000
end_define

begin_define
define|#
directive|define
name|LONG_MAX
value|0x7fffffff
end_define

begin_define
define|#
directive|define
name|LONG_MIN
value|0x80000000
end_define

begin_define
define|#
directive|define
name|SCHAR_MAX
value|0x7f
end_define

begin_define
define|#
directive|define
name|SCHAR_MIN
value|0x80
end_define

begin_define
define|#
directive|define
name|SHRT_MAX
value|0x7fff
end_define

begin_define
define|#
directive|define
name|SHRT_MIN
value|0x8000
end_define

begin_define
define|#
directive|define
name|UCHAR_MAX
value|0xff
end_define

begin_define
define|#
directive|define
name|UINT_MAX
value|0xffffffff
end_define

begin_define
define|#
directive|define
name|ULONG_MAX
value|0xffffffff
end_define

begin_define
define|#
directive|define
name|USHRT_MAX
value|0xffff
end_define

begin_define
define|#
directive|define
name|NBPG
value|512
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
value|9
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
value|0x80000000
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
name|MAXPHYS
value|(63 * 1024)
end_define

begin_comment
comment|/* max raw I/O transfer size */
end_comment

begin_define
define|#
directive|define
name|CLSIZE
value|2
end_define

begin_define
define|#
directive|define
name|CLSIZELOG2
value|1
end_define

begin_define
define|#
directive|define
name|SSIZE
value|4
end_define

begin_comment
comment|/* initial stack size/NBPG */
end_comment

begin_define
define|#
directive|define
name|SINCR
value|4
end_define

begin_comment
comment|/* increment of stack/NBPG */
end_comment

begin_define
define|#
directive|define
name|UPAGES
value|10
end_define

begin_comment
comment|/* pages of u-area */
end_comment

begin_comment
comment|/*  * Some macros for units conversion  */
end_comment

begin_comment
comment|/* Core clicks (512 bytes) to segments and vice versa */
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

begin_comment
comment|/* Core clicks (512 bytes) to disk blocks */
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
value|((x)<<9)
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
value|((((unsigned)(x)+511)>>9))
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

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_decl_stmt
name|int
name|cpuspeed
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|DELAY
parameter_list|(
name|n
parameter_list|)
value|{ register int N = cpuspeed * (n); while (--N> 0); }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
else|KERNEL
end_else

begin_define
define|#
directive|define
name|DELAY
parameter_list|(
name|n
parameter_list|)
value|{ register int N = (n); while (--N> 0); }
end_define

begin_endif
endif|#
directive|endif
endif|KERNEL
end_endif

end_unit

