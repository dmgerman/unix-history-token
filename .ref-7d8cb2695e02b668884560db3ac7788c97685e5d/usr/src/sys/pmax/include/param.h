begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 University of Utah.  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department and Ralph Campbell.  *  * %sccs.include.redist.c%  *  * from: Utah $Hdr: machparam.h 1.11 89/08/14$  *  *	@(#)param.h	7.10 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Machine dependent constants for DEC Station 3100.  */
end_comment

begin_define
define|#
directive|define
name|MACHINE
value|"mips"
end_define

begin_comment
comment|/*  * Round p (pointer or byte index) up to a correctly-aligned value for all  * data types (int, long, ...).   The result is u_int and must be cast to  * any desired pointer type.  */
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
value|(((u_int)(p) + ALIGNBYTES)&~ ALIGNBYTES)
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
comment|/* LOG2(NBPG) */
end_comment

begin_define
define|#
directive|define
name|NPTEPG
value|(NBPG/4)
end_define

begin_define
define|#
directive|define
name|NBSEG
value|0x400000
end_define

begin_comment
comment|/* bytes/segment */
end_comment

begin_define
define|#
directive|define
name|SEGOFSET
value|(NBSEG-1)
end_define

begin_comment
comment|/* byte offset into segment */
end_comment

begin_define
define|#
directive|define
name|SEGSHIFT
value|22
end_define

begin_comment
comment|/* LOG2(NBSEG) */
end_comment

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

begin_comment
comment|/* NOTE: SSIZE, SINCR and UPAGES must be multiples of CLSIZE */
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
name|SINCR
value|1
end_define

begin_comment
comment|/* increment of stack/NBPG */
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

begin_define
define|#
directive|define
name|UADDR
value|0xffffd000
end_define

begin_comment
comment|/* address of u */
end_comment

begin_define
define|#
directive|define
name|UVPN
value|(UADDR>>PGSHIFT)
end_define

begin_comment
comment|/* virtual page number of u */
end_comment

begin_define
define|#
directive|define
name|KERNELSTACK
value|(UADDR+UPAGES*NBPG)
end_define

begin_comment
comment|/* top of kernel stack */
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
comment|/*  * Size of kernel malloc arena in CLBYTES-sized logical pages  */
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
value|(512*1024/CLBYTES)
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
value|((x)<<(PGSHIFT-DEV_BSHIFT))
end_define

begin_define
define|#
directive|define
name|dtoc
parameter_list|(
name|x
parameter_list|)
value|((x)>>(PGSHIFT-DEV_BSHIFT))
end_define

begin_define
define|#
directive|define
name|dtob
parameter_list|(
name|x
parameter_list|)
value|((x)<<DEV_BSHIFT)
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
value|((x)<<PGSHIFT)
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
value|(((unsigned)(x)+(NBPG-1))>>PGSHIFT)
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
comment|/*  * Map a ``block device block'' to a file system block.  * This should be device dependent, and should use the bsize  * field from the disk label.  * For now though just use DEV_BSIZE.  */
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
comment|/*  * Mach derived conversion macros  */
end_comment

begin_define
define|#
directive|define
name|pmax_round_page
parameter_list|(
name|x
parameter_list|)
value|((((unsigned)(x)) + NBPG - 1)& ~(NBPG-1))
end_define

begin_define
define|#
directive|define
name|pmax_trunc_page
parameter_list|(
name|x
parameter_list|)
value|((unsigned)(x)& ~(NBPG-1))
end_define

begin_define
define|#
directive|define
name|pmax_btop
parameter_list|(
name|x
parameter_list|)
value|((unsigned)(x)>> PGSHIFT)
end_define

begin_define
define|#
directive|define
name|pmax_ptob
parameter_list|(
name|x
parameter_list|)
value|((unsigned)(x)<< PGSHIFT)
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
specifier|extern
name|int
argument_list|(
operator|*
name|Mach_splnet
argument_list|)
argument_list|()
decl_stmt|,
argument_list|(
operator|*
name|Mach_splbio
argument_list|)
argument_list|()
decl_stmt|,
argument_list|(
operator|*
name|Mach_splimp
argument_list|)
argument_list|()
decl_stmt|,
argument_list|(
operator|*
name|Mach_spltty
argument_list|)
argument_list|()
decl_stmt|,
argument_list|(
operator|*
name|Mach_splclock
argument_list|)
argument_list|()
decl_stmt|,
argument_list|(
operator|*
name|Mach_splstatclock
argument_list|)
argument_list|()
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|splnet
parameter_list|()
value|((*Mach_splnet)())
end_define

begin_define
define|#
directive|define
name|splbio
parameter_list|()
value|((*Mach_splbio)())
end_define

begin_define
define|#
directive|define
name|splimp
parameter_list|()
value|((*Mach_splimp)())
end_define

begin_define
define|#
directive|define
name|spltty
parameter_list|()
value|((*Mach_spltty)())
end_define

begin_define
define|#
directive|define
name|splclock
parameter_list|()
value|((*Mach_splclock)())
end_define

begin_define
define|#
directive|define
name|splstatclock
parameter_list|()
value|((*Mach_splstatclock)())
end_define

begin_decl_stmt
specifier|extern
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
end_else

begin_comment
comment|/* !KERNEL */
end_comment

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
end_endif

begin_comment
comment|/* !KERNEL */
end_comment

end_unit

