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

begin_ifndef
ifndef|#
directive|ifndef
name|_LOCORE
end_ifndef

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

begin_if
if|#
directive|if
name|_BYTE_ORDER
operator|==
name|_BIG_ENDIAN
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|__mips_n64
end_ifdef

begin_define
define|#
directive|define
name|MACHINE_ARCH
value|"mips64"
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|MACHINE_ARCH32
end_ifndef

begin_define
define|#
directive|define
name|MACHINE_ARCH32
value|"mips"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__mips_n32
argument_list|)
end_elif

begin_define
define|#
directive|define
name|MACHINE_ARCH
value|"mipsn32"
end_define

begin_else
else|#
directive|else
end_else

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

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|__mips_n64
end_ifdef

begin_define
define|#
directive|define
name|MACHINE_ARCH
value|"mips64el"
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|MACHINE_ARCH32
end_ifndef

begin_define
define|#
directive|define
name|MACHINE_ARCH32
value|"mipsel"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__mips_n32
argument_list|)
end_elif

begin_define
define|#
directive|define
name|MACHINE_ARCH
value|"mipsn32el"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MACHINE_ARCH
value|"mipsel"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

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
value|32
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|MAXCPU
end_ifndef

begin_define
define|#
directive|define
name|MAXCPU
value|MAXSMPCPU
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

begin_ifndef
ifndef|#
directive|ifndef
name|MAXMEMDOM
end_ifndef

begin_define
define|#
directive|define
name|MAXMEMDOM
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
name|NPDEPG
value|(PAGE_SIZE/(sizeof (pd_entry_t)))
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__mips_n32
argument_list|)
operator|||
name|defined
argument_list|(
name|__mips_n64
argument_list|)
end_if

begin_comment
comment|/*  PHYSADDR_64_BIT */
end_comment

begin_define
define|#
directive|define
name|NPTEPGSHIFT
value|9
end_define

begin_comment
comment|/* LOG2(NPTEPG) */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NPTEPGSHIFT
value|10
end_define

begin_comment
comment|/* LOG2(NPTEPG) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__mips_n64
end_ifdef

begin_define
define|#
directive|define
name|NPDEPGSHIFT
value|9
end_define

begin_comment
comment|/* LOG2(NPTEPG) */
end_comment

begin_define
define|#
directive|define
name|SEGSHIFT
value|(PAGE_SHIFT + NPTEPGSHIFT + NPDEPGSHIFT)
end_define

begin_define
define|#
directive|define
name|NBSEG
value|(1ul<< SEGSHIFT)
end_define

begin_define
define|#
directive|define
name|PDRSHIFT
value|(PAGE_SHIFT + NPTEPGSHIFT)
end_define

begin_define
define|#
directive|define
name|PDRMASK
value|((1<< PDRSHIFT) - 1)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NPDEPGSHIFT
value|10
end_define

begin_comment
comment|/* LOG2(NPTEPG) */
end_comment

begin_define
define|#
directive|define
name|SEGSHIFT
value|(PAGE_SHIFT + NPTEPGSHIFT)
end_define

begin_define
define|#
directive|define
name|NBSEG
value|(1<< SEGSHIFT)
end_define

begin_comment
comment|/* bytes/segment */
end_comment

begin_define
define|#
directive|define
name|PDRSHIFT
value|SEGSHIFT
end_define

begin_comment
comment|/* alias for SEG in 32 bit */
end_comment

begin_define
define|#
directive|define
name|PDRMASK
value|((1<< PDRSHIFT) - 1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|NBPDR
value|(1<< PDRSHIFT)
end_define

begin_comment
comment|/* bytes/pagedir */
end_comment

begin_define
define|#
directive|define
name|SEGMASK
value|(NBSEG - 1)
end_define

begin_comment
comment|/* byte offset into segment */
end_comment

begin_define
define|#
directive|define
name|MAXPAGESIZES
value|1
end_define

begin_comment
comment|/* max supported pagesizes */
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
comment|/*  * The kernel stack needs to be aligned on a (PAGE_SIZE * 2) boundary.  */
end_comment

begin_define
define|#
directive|define
name|KSTACK_PAGES
value|2
end_define

begin_comment
comment|/* kernel stack */
end_comment

begin_define
define|#
directive|define
name|KSTACK_GUARD_PAGES
value|2
end_define

begin_comment
comment|/* pages of kstack guard; 0 disables */
end_comment

begin_comment
comment|/*  * Mach derived conversion macros  */
end_comment

begin_define
define|#
directive|define
name|round_page
parameter_list|(
name|x
parameter_list|)
value|(((x) + PAGE_MASK)& ~PAGE_MASK)
end_define

begin_define
define|#
directive|define
name|trunc_page
parameter_list|(
name|x
parameter_list|)
value|((x)& ~PAGE_MASK)
end_define

begin_define
define|#
directive|define
name|atop
parameter_list|(
name|x
parameter_list|)
value|((x)>> PAGE_SHIFT)
end_define

begin_define
define|#
directive|define
name|ptoa
parameter_list|(
name|x
parameter_list|)
value|((x)<< PAGE_SHIFT)
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

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|NO_FUEWORD
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MIPS_INCLUDE_PARAM_H_ */
end_comment

end_unit

