begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * All advertising materials mentioning features or use of this software  * must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Lawrence Berkeley Laboratory.  *  * %sccs.include.redist.c%  *  *	@(#)param.h	8.3 (Berkeley) %G%  *  * from: $Header: param.h,v 1.13 92/11/26 02:04:38 torek Exp $ (LBL)  */
end_comment

begin_comment
comment|/*  * Machine dependent constants for Sun-4c (SPARCstation)  */
end_comment

begin_define
define|#
directive|define
name|MACHINE
value|"sparc"
end_define

begin_define
define|#
directive|define
name|NCPUS
value|1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_comment
comment|/* XXX */
end_comment

begin_include
include|#
directive|include
file|<machine/cpu.h>
end_include

begin_comment
comment|/* XXX */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* XXX */
end_comment

begin_comment
comment|/*  * Round p (pointer or byte index) up to a correctly-aligned value for  * the machine's strictest data type.  The result is u_int and must be  * cast to any desired pointer type.  */
end_comment

begin_define
define|#
directive|define
name|ALIGNBYTES
value|7
end_define

begin_define
define|#
directive|define
name|ALIGN
parameter_list|(
name|p
parameter_list|)
value|(((u_int)(p) + ALIGNBYTES)& ~ALIGNBYTES)
end_define

begin_define
define|#
directive|define
name|NBPG
value|4096
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
value|12
end_define

begin_comment
comment|/* log2(NBPG) */
end_comment

begin_define
define|#
directive|define
name|KERNBASE
value|0xf8000000
end_define

begin_comment
comment|/* start of kernel virtual space */
end_comment

begin_define
define|#
directive|define
name|KERNTEXTOFF
value|0xf8004000
end_define

begin_comment
comment|/* start of kernel text */
end_comment

begin_define
define|#
directive|define
name|BTOPKERNBASE
value|((u_long)KERNBASE>> PG_SHIFT)
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
value|(64 * 1024)
end_define

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

begin_comment
comment|/* NOTE: SSIZE and UPAGES must be multiples of CLSIZE */
end_comment

begin_define
define|#
directive|define
name|SSIZE
value|1
end_define

begin_comment
comment|/* initial stack size/NBPG */
end_comment

begin_define
define|#
directive|define
name|UPAGES
value|2
end_define

begin_comment
comment|/* pages of u-area */
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
name|MCLBYTES
value|2048
end_define

begin_comment
comment|/* enough for whole Ethernet packet */
end_comment

begin_define
define|#
directive|define
name|MCLSHIFT
value|11
end_define

begin_comment
comment|/* log2(MCLBYTES) */
end_comment

begin_define
define|#
directive|define
name|MCLOFSET
value|(MCLBYTES - 1)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|NMBCLUSTERS
end_ifndef

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Size of kernel malloc arena in CLBYTES-sized logical pages.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NKMEMCLUSTERS
end_ifndef

begin_define
define|#
directive|define
name|NKMEMCLUSTERS
value|(6 * 1024 * 1024 / CLBYTES)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* pages ("clicks") (4096 bytes) to disk blocks */
end_comment

begin_define
define|#
directive|define
name|ctod
parameter_list|(
name|x
parameter_list|)
value|((x)<< (PGSHIFT - DEV_BSHIFT))
end_define

begin_define
define|#
directive|define
name|dtoc
parameter_list|(
name|x
parameter_list|)
value|((x)>> (PGSHIFT - DEV_BSHIFT))
end_define

begin_define
define|#
directive|define
name|dtob
parameter_list|(
name|x
parameter_list|)
value|((x)<< DEV_BSHIFT)
end_define

begin_comment
comment|/* pages to bytes */
end_comment

begin_define
define|#
directive|define
name|ctob
parameter_list|(
name|x
parameter_list|)
value|((x)<< PGSHIFT)
end_define

begin_comment
comment|/* bytes to pages */
end_comment

begin_define
define|#
directive|define
name|btoc
parameter_list|(
name|x
parameter_list|)
value|(((unsigned)(x) + PGOFSET)>> PGSHIFT)
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
value|((bytes)>> DEV_BSHIFT)
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
value|((db)<< DEV_BSHIFT)
end_define

begin_comment
comment|/*  * Map a ``block device block'' to a file system block.  * This should be device dependent, and should use the bsize  * field from the disk label.  * For now though just use DEV_BSIZE.  */
end_comment

begin_define
define|#
directive|define
name|bdbtofsb
parameter_list|(
name|bn
parameter_list|)
value|((bn) / (BLKDEV_IOSIZE / DEV_BSIZE))
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

begin_define
define|#
directive|define
name|DELAY
parameter_list|(
name|n
parameter_list|)
value|delay(n)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DELAY
parameter_list|(
name|n
parameter_list|)
value|{ register volatile int N = (n); while (--N> 0); }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_SIMPLELOCK_H_
end_ifndef

begin_define
define|#
directive|define
name|_SIMPLELOCK_H_
end_define

begin_comment
comment|/*  * A simple spin lock.  *  * This structure only sets one bit of data, but is sized based on the  * minimum word size that can be operated on by the hardware test-and-set  * instruction. It is only needed for multiprocessors, as uniprocessors  * will always run to completion or a sleep. It is an error to hold one  * of these locks while a process is sleeping.  */
end_comment

begin_struct
struct|struct
name|simplelock
block|{
name|int
name|lock_data
decl_stmt|;
block|}
struct|;
end_struct

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DEBUG
argument_list|)
operator|&&
name|NCPUS
operator|>
literal|1
end_if

begin_comment
comment|/*  * The simple-lock routines are the primitives out of which the lock  * package is built. The machine-dependent code must implement an  * atomic test_and_set operation that indivisibly sets the simple lock  * to non-zero and returns its old value. It also assumes that the  * setting of the lock to zero below is indivisible. Simple locks may  * only be used for exclusive locks.  */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|simple_lock_init
parameter_list|(
name|lkp
parameter_list|)
name|struct
name|simplelock
modifier|*
name|lkp
decl_stmt|;
block|{
name|lkp
operator|->
name|lock_data
operator|=
literal|0
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|simple_lock
parameter_list|(
name|lkp
parameter_list|)
name|__volatile
name|struct
name|simplelock
modifier|*
name|lkp
decl_stmt|;
block|{
while|while
condition|(
name|test_and_set
argument_list|(
operator|&
name|lkp
operator|->
name|lock_data
argument_list|)
condition|)
continue|continue;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|simple_lock_try
parameter_list|(
name|lkp
parameter_list|)
name|__volatile
name|struct
name|simplelock
modifier|*
name|lkp
decl_stmt|;
block|{
return|return
operator|(
operator|!
name|test_and_set
argument_list|(
operator|&
name|lkp
operator|->
name|lock_data
argument_list|)
operator|)
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|simple_unlock
parameter_list|(
name|lkp
parameter_list|)
name|__volatile
name|struct
name|simplelock
modifier|*
name|lkp
decl_stmt|;
block|{
name|lkp
operator|->
name|lock_data
operator|=
literal|0
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NCPUS> 1 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SIMPLELOCK_H_ */
end_comment

end_unit

