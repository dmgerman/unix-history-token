begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * William Jolitz.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)param.h	5.8 (Berkeley) 6/28/91  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Machine dependent constants for sparc64.  */
end_comment

begin_define
define|#
directive|define
name|TODO
define|\
value|panic("implement %s", __func__)
end_define

begin_comment
comment|/*  * Round p (pointer or byte index) up to a correctly-aligned value  * for all data types (int, long, ...).   The result is unsigned int  * and must be cast to any desired pointer type.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ALIGNBYTES
end_ifndef

begin_define
define|#
directive|define
name|_ALIGNBYTES
value|0xf
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_ALIGN
end_ifndef

begin_define
define|#
directive|define
name|_ALIGN
parameter_list|(
name|p
parameter_list|)
value|(((u_long)(p) + _ALIGNBYTES)& ~_ALIGNBYTES)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE
value|sparc64
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_ARCH
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_ARCH
value|sparc64
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_NO_NAMESPACE_POLLUTION
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_PARAM_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_PARAM_H_
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
value|"sparc64"
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
value|"sparc64"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MID_MACHINE
value|MID_SPARC64
end_define

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

begin_ifdef
ifdef|#
directive|ifdef
name|SMP
end_ifdef

begin_define
define|#
directive|define
name|MAXCPU
value|16
end_define

begin_else
else|#
directive|else
end_else

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
comment|/* SMP */
end_comment

begin_define
define|#
directive|define
name|INT_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|PTR_SHIFT
value|3
end_define

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

begin_define
define|#
directive|define
name|PAGE_SHIFT_8K
value|13
end_define

begin_define
define|#
directive|define
name|PAGE_SIZE_8K
value|(1UL<<PAGE_SHIFT_8K)
end_define

begin_define
define|#
directive|define
name|PAGE_MASK_8K
value|(PAGE_SIZE_8K-1)
end_define

begin_define
define|#
directive|define
name|PAGE_SHIFT_64K
value|16
end_define

begin_define
define|#
directive|define
name|PAGE_SIZE_64K
value|(1UL<<PAGE_SHIFT_64K)
end_define

begin_define
define|#
directive|define
name|PAGE_MASK_64K
value|(PAGE_SIZE_64K-1)
end_define

begin_define
define|#
directive|define
name|PAGE_SHIFT_512K
value|19
end_define

begin_define
define|#
directive|define
name|PAGE_SIZE_512K
value|(1UL<<PAGE_SHIFT_512K)
end_define

begin_define
define|#
directive|define
name|PAGE_MASK_512K
value|(PAGE_SIZE_512K-1)
end_define

begin_define
define|#
directive|define
name|PAGE_SHIFT_4M
value|22
end_define

begin_define
define|#
directive|define
name|PAGE_SIZE_4M
value|(1UL<<PAGE_SHIFT_4M)
end_define

begin_define
define|#
directive|define
name|PAGE_MASK_4M
value|(PAGE_SIZE_4M-1)
end_define

begin_define
define|#
directive|define
name|PAGE_SHIFT_MIN
value|PAGE_SHIFT_8K
end_define

begin_define
define|#
directive|define
name|PAGE_SIZE_MIN
value|PAGE_SIZE_8K
end_define

begin_define
define|#
directive|define
name|PAGE_MASK_MIN
value|PAGE_MASK_8K
end_define

begin_define
define|#
directive|define
name|PAGE_SHIFT
value|PAGE_SHIFT_8K
end_define

begin_comment
comment|/* LOG2(PAGE_SIZE) */
end_comment

begin_define
define|#
directive|define
name|PAGE_SIZE
value|PAGE_SIZE_8K
end_define

begin_comment
comment|/* bytes/page */
end_comment

begin_define
define|#
directive|define
name|PAGE_MASK
value|PAGE_MASK_8K
end_define

begin_define
define|#
directive|define
name|PAGE_SHIFT_MAX
value|PAGE_SHIFT_4M
end_define

begin_define
define|#
directive|define
name|PAGE_SIZE_MAX
value|PAGE_SIZE_4M
end_define

begin_define
define|#
directive|define
name|PAGE_MASK_MAX
value|PAGE_MASK_4M
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
name|DEV_BSIZE
value|(1<<DEV_BSHIFT)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|BLKDEV_IOSIZE
end_ifndef

begin_define
define|#
directive|define
name|BLKDEV_IOSIZE
value|PAGE_SIZE
end_define

begin_comment
comment|/* default block device I/O size */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|DFLTPHYS
value|(64 * 1024)
end_define

begin_comment
comment|/* default max raw I/O transfer size */
end_comment

begin_define
define|#
directive|define
name|MAXPHYS
value|(128 * 1024)
end_define

begin_comment
comment|/* max raw I/O transfer size */
end_comment

begin_define
define|#
directive|define
name|MAXDUMPPGS
value|(DFLTPHYS/PAGE_SIZE)
end_define

begin_define
define|#
directive|define
name|KSTACK_PAGES
value|4
end_define

begin_comment
comment|/* pages of kernel stack (with pcb) */
end_comment

begin_define
define|#
directive|define
name|UAREA_PAGES
value|1
end_define

begin_comment
comment|/* pages of user area */
end_comment

begin_define
define|#
directive|define
name|PCPU_PAGES
value|1
end_define

begin_define
define|#
directive|define
name|KSTACK_GUARD
end_define

begin_comment
comment|/* compile in kstack guard page */
end_comment

begin_define
define|#
directive|define
name|KSTACK_GUARD_PAGES
value|1
end_define

begin_comment
comment|/*  * Constants related to network buffer management.  * MCLBYTES must be no larger than PAGE_SIZE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MSIZE
end_ifndef

begin_define
define|#
directive|define
name|MSIZE
value|256
end_define

begin_comment
comment|/* size of an mbuf */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MSIZE */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MCLSHIFT
end_ifndef

begin_define
define|#
directive|define
name|MCLSHIFT
value|11
end_define

begin_comment
comment|/* convert bytes to mbuf clusters */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MCLSHIFT */
end_comment

begin_define
define|#
directive|define
name|MCLBYTES
value|(1<< MCLSHIFT)
end_define

begin_comment
comment|/* size of an mbuf cluster */
end_comment

begin_comment
comment|/*  * Some macros for units conversion  */
end_comment

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
value|((unsigned long)(x)<<PAGE_SHIFT)
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
value|(((unsigned long)(x)+PAGE_MASK)>>PAGE_SHIFT)
end_define

begin_comment
comment|/* bytes to disk blocks */
end_comment

begin_define
define|#
directive|define
name|btodb
parameter_list|(
name|bytes
parameter_list|)
comment|/* calculates (bytes / DEV_BSIZE) */
define|\
value|(daddr_t)((unsigned long)(bytes)>> DEV_BSHIFT)
end_define

begin_comment
comment|/* disk blocks to bytes */
end_comment

begin_define
define|#
directive|define
name|dbtob
parameter_list|(
name|db
parameter_list|)
comment|/* calculates (db * DEV_BSIZE) */
define|\
value|(off_t)((unsigned long)(db)<< DEV_BSHIFT)
end_define

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
value|(((unsigned long)(x) + PAGE_MASK)& ~PAGE_MASK)
end_define

begin_define
define|#
directive|define
name|trunc_page
parameter_list|(
name|x
parameter_list|)
value|((unsigned long)(x)& ~PAGE_MASK)
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
name|sparc64_btop
parameter_list|(
name|x
parameter_list|)
value|((unsigned long)(x)>> PAGE_SHIFT)
end_define

begin_define
define|#
directive|define
name|sparc64_ptob
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
value|((unsigned long)(x) * (PAGE_SIZE / 1024))
end_define

begin_define
define|#
directive|define
name|CTASSERT
parameter_list|(
name|x
parameter_list|)
value|_CTASSERT(x, __LINE__)
end_define

begin_define
define|#
directive|define
name|_CTASSERT
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|__CTASSERT(x, y)
end_define

begin_define
define|#
directive|define
name|__CTASSERT
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|typedef char __assert ## y[(x) ? 1 : -1]
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_PARAM_H_ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_NO_NAMESPACE_POLLUTION */
end_comment

end_unit

