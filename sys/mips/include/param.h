begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: param.h,v 1.11 1998/08/30 22:05:35 millert Exp $ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 1988 University of Utah.  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department and Ralph Campbell.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: Utah Hdr: machparam.h 1.11 89/08/14  *	from: @(#)param.h	8.1 (Berkeley) 6/10/93  *	JNPR: param.h,v 1.6.2.1 2007/09/10 07:49:36 girish  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MIPS_INCLUDE_PARAM_H_
end_ifndef

begin_define
define|#
directive|define
name|_MIPS_INCLUDE_PARAM_H_
end_define

begin_include
include|#
directive|include
file|<machine/_align.h>
end_include

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|_LOCORE
end_ifdef

begin_include
include|#
directive|include
file|<machine/psl.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<machine/cpu.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|__PCI_REROUTE_INTERRUPT
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|MACHINE
end_ifndef

begin_define
define|#
directive|define
name|MACHINE
value|"mips"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MACHINE_ARCH
end_ifndef

begin_define
define|#
directive|define
name|MACHINE_ARCH
value|"mips"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * OBJFORMAT_NAMES is a comma-separated list of the object formats  * that are supported on the architecture.  */
end_comment

begin_define
define|#
directive|define
name|OBJFORMAT_NAMES
value|"elf"
end_define

begin_define
define|#
directive|define
name|OBJFORMAT_DEFAULT
value|"elf"
end_define

begin_define
define|#
directive|define
name|MID_MACHINE
value|0
end_define

begin_comment
comment|/* None but has to be defined */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SMP
end_ifdef

begin_define
define|#
directive|define
name|MAXSMPCPU
value|16
end_define

begin_define
define|#
directive|define
name|MAXCPU
value|MAXSMPCPU
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MAXSMPCPU
value|1
end_define

begin_define
define|#
directive|define
name|MAXCPU
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Round p (pointer or byte index) up to a correctly-aligned value for all  * data types (int, long, ...).	  The result is u_int and must be cast to  * any desired pointer type.  */
end_comment

begin_define
define|#
directive|define
name|ALIGNBYTES
value|_ALIGNBYTES
end_define

begin_define
define|#
directive|define
name|ALIGN
parameter_list|(
name|p
parameter_list|)
value|_ALIGN(p)
end_define

begin_comment
comment|/*  * ALIGNED_POINTER is a boolean macro that checks whether an address  * is valid to fetch data elements of type t from on this architecture.  * This does not reflect the optimal alignment, just the possibility  * (within reasonable limits).   */
end_comment

begin_define
define|#
directive|define
name|ALIGNED_POINTER
parameter_list|(
name|p
parameter_list|,
name|t
parameter_list|)
value|((((unsigned long)(p))& (sizeof (t) - 1)) == 0)
end_define

begin_comment
comment|/*  * CACHE_LINE_SIZE is the compile-time maximum cache line size for an  * architecture.  It should be used with appropriate caution.  */
end_comment

begin_define
define|#
directive|define
name|CACHE_LINE_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|CACHE_LINE_SIZE
value|(1<< CACHE_LINE_SHIFT)
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
name|PAGE_SHIFT
value|12
end_define

begin_comment
comment|/* LOG2(PAGE_SIZE) */
end_comment

begin_define
define|#
directive|define
name|PAGE_SIZE
value|(1<<PAGE_SHIFT)
end_define

begin_comment
comment|/* bytes/page */
end_comment

begin_define
define|#
directive|define
name|PAGE_MASK
value|(PAGE_SIZE-1)
end_define

begin_define
define|#
directive|define
name|NPTEPG
value|(PAGE_SIZE/(sizeof (pt_entry_t)))
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
name|MAXPAGESIZES
value|1
end_define

begin_comment
comment|/* maximum number of supported page sizes */
end_comment

begin_comment
comment|/* XXXimp: This has moved to vmparam.h */
end_comment

begin_comment
comment|/* Also, this differs from the mips2 definition, but likely is better */
end_comment

begin_comment
comment|/* since this means the kernel won't chew up TLBs when it is executing */
end_comment

begin_comment
comment|/* code */
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
name|BLKDEV_IOSIZE
value|2048
end_define

begin_comment
comment|/* xxx: Why is this 1/2 page? */
end_comment

begin_define
define|#
directive|define
name|MAXDUMPPGS
value|1
end_define

begin_comment
comment|/* xxx: why is this only one? */
end_comment

begin_comment
comment|/*  * NOTE: In FreeBSD, Uarea's don't have a fixed address.  *	 Therefore, any code imported from OpenBSD which depends on  *	 UADDR, UVPN and KERNELSTACK requires porting.  * XXX: 3 stack pages?  Not 4 which would be more efficient from a tlb  * XXX: point of view.  */
end_comment

begin_define
define|#
directive|define
name|KSTACK_PAGES
value|3
end_define

begin_comment
comment|/* kernel stack*/
end_comment

begin_define
define|#
directive|define
name|KSTACK_GUARD_PAGES
value|0
end_define

begin_comment
comment|/* pages of kstack guard; 0 disables */
end_comment

begin_define
define|#
directive|define
name|UPAGES
value|2
end_define

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
comment|/*  * Conversion macros  */
end_comment

begin_define
define|#
directive|define
name|mips_round_page
parameter_list|(
name|x
parameter_list|)
value|((((unsigned long)(x)) + NBPG - 1)& ~(NBPG-1))
end_define

begin_define
define|#
directive|define
name|mips_trunc_page
parameter_list|(
name|x
parameter_list|)
value|((unsigned long)(x)& ~(NBPG-1))
end_define

begin_define
define|#
directive|define
name|mips_btop
parameter_list|(
name|x
parameter_list|)
value|((unsigned long)(x)>> PGSHIFT)
end_define

begin_define
define|#
directive|define
name|mips_ptob
parameter_list|(
name|x
parameter_list|)
value|((unsigned long)(x)<< PGSHIFT)
end_define

begin_define
define|#
directive|define
name|round_page
value|mips_round_page
end_define

begin_define
define|#
directive|define
name|trunc_page
value|mips_trunc_page
end_define

begin_define
define|#
directive|define
name|atop
parameter_list|(
name|x
parameter_list|)
value|((unsigned long)(x)>> PAGE_SHIFT)
end_define

begin_define
define|#
directive|define
name|ptoa
parameter_list|(
name|x
parameter_list|)
value|((unsigned long)(x)<< PAGE_SHIFT)
end_define

begin_define
define|#
directive|define
name|pgtok
parameter_list|(
name|x
parameter_list|)
value|((x) * (PAGE_SIZE / 1024))
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

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
comment|/* !_KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MIPS_INCLUDE_PARAM_H_ */
end_comment

end_unit

