begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2002 David E. O'Brien.  All rights reserved.  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department and Ralph Campbell.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)param.h	8.1 (Berkeley) 6/10/93  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Machine dependent constants for AMD64.  */
end_comment

begin_comment
comment|/*  * Round p (pointer or byte index) up to a correctly-aligned value  * for all data types (int, long, ...).   The result is u_long and  * must be cast to any desired pointer type.  *  * ALIGNED_POINTER is a boolean macro that checks whether an address  * is valid to fetch data elements of type t from on this architecture.  * This does not reflect the optimal alignment, just the possibility  * (within reasonable limits).   *  */
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
value|(sizeof(long) - 1)
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
value|(((u_long)(p) + _ALIGNBYTES)&~ _ALIGNBYTES)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_ALIGNED_POINTER
end_ifndef

begin_define
define|#
directive|define
name|_ALIGNED_POINTER
parameter_list|(
name|p
parameter_list|,
name|t
parameter_list|)
value|((((u_long)(p))& (sizeof(t)-1)) == 0)
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
value|amd64
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
value|amd64
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
value|"amd64"
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
value|"amd64"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MAXCPU
value|1
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
name|ALIGNED_POINTER
parameter_list|(
name|p
parameter_list|,
name|t
parameter_list|)
value|_ALIGNED_POINTER((p),(t))
end_define

begin_comment
comment|/* Size of the level 1 page table units */
end_comment

begin_define
define|#
directive|define
name|NPTEPG
value|(PAGE_SIZE/(sizeof (pt_entry_t)))
end_define

begin_define
define|#
directive|define
name|NPTEPGSHIFT
value|9
end_define

begin_comment
comment|/* LOG2(NPTEPG) */
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

begin_comment
comment|/* Size of the level 2 page directory units */
end_comment

begin_define
define|#
directive|define
name|NPDEPG
value|(PAGE_SIZE/(sizeof (pd_entry_t)))
end_define

begin_define
define|#
directive|define
name|NPDEPGSHIFT
value|9
end_define

begin_comment
comment|/* LOG2(NPDEPG) */
end_comment

begin_define
define|#
directive|define
name|PDRSHIFT
value|21
end_define

begin_comment
comment|/* LOG2(NBPDR) */
end_comment

begin_define
define|#
directive|define
name|NBPDR
value|(1<<PDRSHIFT)
end_define

begin_comment
comment|/* bytes/page dir */
end_comment

begin_define
define|#
directive|define
name|PDRMASK
value|(NBPDR-1)
end_define

begin_comment
comment|/* Size of the level 3 page directory pointer table units */
end_comment

begin_define
define|#
directive|define
name|NPDPEPG
value|(PAGE_SIZE/(sizeof (pdp_entry_t)))
end_define

begin_define
define|#
directive|define
name|NPDPEPGSHIFT
value|9
end_define

begin_comment
comment|/* LOG2(NPDPEPG) */
end_comment

begin_define
define|#
directive|define
name|PDPSHIFT
value|30
end_define

begin_comment
comment|/* LOG2(NBPDP) */
end_comment

begin_define
define|#
directive|define
name|NBPDP
value|(1<<PDPSHIFT)
end_define

begin_comment
comment|/* bytes/page dir ptr table */
end_comment

begin_define
define|#
directive|define
name|PDPMASK
value|(NBPDP-1)
end_define

begin_comment
comment|/* Size of the level 4 page-map level-4 table units */
end_comment

begin_define
define|#
directive|define
name|NPML4EPG
value|(PAGE_SIZE/(sizeof (pml4_entry_t)))
end_define

begin_define
define|#
directive|define
name|NPML4EPGSHIFT
value|9
end_define

begin_comment
comment|/* LOG2(NPML4EPG) */
end_comment

begin_define
define|#
directive|define
name|PML4SHIFT
value|39
end_define

begin_comment
comment|/* LOG2(NBPML4T) */
end_comment

begin_define
define|#
directive|define
name|NBPML4T
value|(1ul<<PML4SHIFT)
end_define

begin_comment
comment|/* bytes/page map lev4 table */
end_comment

begin_define
define|#
directive|define
name|PML4MASK
value|(NBPML4T-1)
end_define

begin_define
define|#
directive|define
name|IOPAGES
value|2
end_define

begin_comment
comment|/* pages of i/o permission bitmap */
end_comment

begin_define
define|#
directive|define
name|KSTACK_PAGES
value|4
end_define

begin_comment
comment|/* pages of kstack (with pcb) */
end_comment

begin_define
define|#
directive|define
name|UAREA_PAGES
value|1
end_define

begin_comment
comment|/* holds struct user WITHOUT PCB (see def.) */
end_comment

begin_define
define|#
directive|define
name|KSTACK_GUARD
value|1
end_define

begin_comment
comment|/* compile in the kstack guard page */
end_comment

begin_comment
comment|/*  * Ceiling on amount of swblock kva space, can be changed via  * the kern.maxswzone /boot/loader.conf variable.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VM_SWZONE_SIZE_MAX
end_ifndef

begin_define
define|#
directive|define
name|VM_SWZONE_SIZE_MAX
value|(32 * 1024 * 1024)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Ceiling on size of buffer cache (really only effects write queueing,  * the VM page cache is not effected), can be changed via  * the kern.maxbcache /boot/loader.conf variable.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VM_BCACHE_SIZE_MAX
end_ifndef

begin_define
define|#
directive|define
name|VM_BCACHE_SIZE_MAX
value|(200 * 1024 * 1024)
end_define

begin_endif
endif|#
directive|endif
end_endif

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
value|((((unsigned long)(x)) + PAGE_MASK)& ~(PAGE_MASK))
end_define

begin_define
define|#
directive|define
name|trunc_page
parameter_list|(
name|x
parameter_list|)
value|((unsigned long)(x)& ~(PAGE_MASK))
end_define

begin_define
define|#
directive|define
name|trunc_2mpage
parameter_list|(
name|x
parameter_list|)
value|((unsigned long)(x)& ~PDRMASK)
end_define

begin_define
define|#
directive|define
name|round_2mpage
parameter_list|(
name|x
parameter_list|)
value|((((unsigned long)(x)) + PDRMASK)& ~PDRMASK)
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
name|amd64_btop
parameter_list|(
name|x
parameter_list|)
value|((unsigned long)(x)>> PAGE_SHIFT)
end_define

begin_define
define|#
directive|define
name|amd64_ptob
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

