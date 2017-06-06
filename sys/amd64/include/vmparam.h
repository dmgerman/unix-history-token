begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  * Copyright (c) 1994 John S. Dyson  * All rights reserved.  * Copyright (c) 2003 Peter Wemm  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * William Jolitz.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)vmparam.h	5.9 (Berkeley) 5/12/91  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_VMPARAM_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_VMPARAM_H_
value|1
end_define

begin_comment
comment|/*  * Machine dependent constants for AMD64.  */
end_comment

begin_comment
comment|/*  * Virtual memory related constants, all in bytes  */
end_comment

begin_define
define|#
directive|define
name|MAXTSIZ
value|(32768UL*1024*1024)
end_define

begin_comment
comment|/* max text size */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DFLDSIZ
end_ifndef

begin_define
define|#
directive|define
name|DFLDSIZ
value|(32768UL*1024*1024)
end_define

begin_comment
comment|/* initial data size limit */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MAXDSIZ
end_ifndef

begin_define
define|#
directive|define
name|MAXDSIZ
value|(32768UL*1024*1024)
end_define

begin_comment
comment|/* max data size */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DFLSSIZ
end_ifndef

begin_define
define|#
directive|define
name|DFLSSIZ
value|(8UL*1024*1024)
end_define

begin_comment
comment|/* initial stack size limit */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MAXSSIZ
end_ifndef

begin_define
define|#
directive|define
name|MAXSSIZ
value|(512UL*1024*1024)
end_define

begin_comment
comment|/* max stack size */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SGROWSIZ
end_ifndef

begin_define
define|#
directive|define
name|SGROWSIZ
value|(128UL*1024)
end_define

begin_comment
comment|/* amount to grow stack */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * We provide a machine specific single page allocator through the use  * of the direct mapped segment.  This uses 2MB pages for reduced  * TLB pressure.  */
end_comment

begin_define
define|#
directive|define
name|UMA_MD_SMALL_ALLOC
end_define

begin_comment
comment|/*  * The physical address space is densely populated.  */
end_comment

begin_define
define|#
directive|define
name|VM_PHYSSEG_DENSE
end_define

begin_comment
comment|/*  * The number of PHYSSEG entries must be one greater than the number  * of phys_avail entries because the phys_avail entry that spans the  * largest physical address that is accessible by ISA DMA is split  * into two PHYSSEG entries.   */
end_comment

begin_define
define|#
directive|define
name|VM_PHYSSEG_MAX
value|63
end_define

begin_comment
comment|/*  * Create two free page pools: VM_FREEPOOL_DEFAULT is the default pool  * from which physical pages are allocated and VM_FREEPOOL_DIRECT is  * the pool from which physical pages for page tables and small UMA  * objects are allocated.  */
end_comment

begin_define
define|#
directive|define
name|VM_NFREEPOOL
value|2
end_define

begin_define
define|#
directive|define
name|VM_FREEPOOL_DEFAULT
value|0
end_define

begin_define
define|#
directive|define
name|VM_FREEPOOL_DIRECT
value|1
end_define

begin_comment
comment|/*  * Create up to three free page lists: VM_FREELIST_DMA32 is for physical pages  * that have physical addresses below 4G but are not accessible by ISA DMA,  * and VM_FREELIST_ISADMA is for physical pages that are accessible by ISA  * DMA.  */
end_comment

begin_define
define|#
directive|define
name|VM_NFREELIST
value|3
end_define

begin_define
define|#
directive|define
name|VM_FREELIST_DEFAULT
value|0
end_define

begin_define
define|#
directive|define
name|VM_FREELIST_DMA32
value|1
end_define

begin_define
define|#
directive|define
name|VM_FREELIST_ISADMA
value|2
end_define

begin_comment
comment|/*  * Create the DMA32 free list only if the number of physical pages above  * physical address 4G is at least 16M, which amounts to 64GB of physical  * memory.  */
end_comment

begin_define
define|#
directive|define
name|VM_DMA32_NPAGES_THRESHOLD
value|16777216
end_define

begin_comment
comment|/*  * An allocation size of 16MB is supported in order to optimize the  * use of the direct map by UMA.  Specifically, a cache line contains  * at most 8 PDEs, collectively mapping 16MB of physical memory.  By  * reducing the number of distinct 16MB "pages" that are used by UMA,  * the physical memory allocator reduces the likelihood of both 2MB  * page TLB misses and cache misses caused by 2MB page TLB misses.  */
end_comment

begin_define
define|#
directive|define
name|VM_NFREEORDER
value|13
end_define

begin_comment
comment|/*  * Enable superpage reservations: 1 level.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VM_NRESERVLEVEL
end_ifndef

begin_define
define|#
directive|define
name|VM_NRESERVLEVEL
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Level 0 reservations consist of 512 pages.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VM_LEVEL_0_ORDER
end_ifndef

begin_define
define|#
directive|define
name|VM_LEVEL_0_ORDER
value|9
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SMP
end_ifdef

begin_define
define|#
directive|define
name|PA_LOCK_COUNT
value|256
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Virtual addresses of things.  Derived from the page directory and  * page table indexes from pmap.h for precision.  *  * 0x0000000000000000 - 0x00007fffffffffff   user map  * 0x0000800000000000 - 0xffff7fffffffffff   does not exist (hole)  * 0xffff800000000000 - 0xffff804020100fff   recursive page table (512GB slot)  * 0xffff804020101000 - 0xfffff7ffffffffff   unused  * 0xfffff80000000000 - 0xfffffbffffffffff   4TB direct map  * 0xfffffc0000000000 - 0xfffffdffffffffff   unused  * 0xfffffe0000000000 - 0xffffffffffffffff   2TB kernel map  *  * Within the kernel map:  *  * 0xffffffff80000000                        KERNBASE  */
end_comment

begin_define
define|#
directive|define
name|VM_MIN_KERNEL_ADDRESS
value|KVADDR(KPML4BASE, 0, 0, 0)
end_define

begin_define
define|#
directive|define
name|VM_MAX_KERNEL_ADDRESS
value|KVADDR(KPML4BASE + NKPML4E - 1, \ 					NPDPEPG-1, NPDEPG-1, NPTEPG-1)
end_define

begin_define
define|#
directive|define
name|DMAP_MIN_ADDRESS
value|KVADDR(DMPML4I, 0, 0, 0)
end_define

begin_define
define|#
directive|define
name|DMAP_MAX_ADDRESS
value|KVADDR(DMPML4I + NDMPML4E, 0, 0, 0)
end_define

begin_define
define|#
directive|define
name|KERNBASE
value|KVADDR(KPML4I, KPDPI, 0, 0)
end_define

begin_define
define|#
directive|define
name|UPT_MAX_ADDRESS
value|KVADDR(PML4PML4I, PML4PML4I, PML4PML4I, PML4PML4I)
end_define

begin_define
define|#
directive|define
name|UPT_MIN_ADDRESS
value|KVADDR(PML4PML4I, 0, 0, 0)
end_define

begin_define
define|#
directive|define
name|VM_MAXUSER_ADDRESS
value|UVADDR(NUPML4E, 0, 0, 0)
end_define

begin_define
define|#
directive|define
name|SHAREDPAGE
value|(VM_MAXUSER_ADDRESS - PAGE_SIZE)
end_define

begin_define
define|#
directive|define
name|USRSTACK
value|SHAREDPAGE
end_define

begin_define
define|#
directive|define
name|VM_MAX_ADDRESS
value|UPT_MAX_ADDRESS
end_define

begin_define
define|#
directive|define
name|VM_MIN_ADDRESS
value|(0)
end_define

begin_comment
comment|/*  * XXX Allowing dmaplimit == 0 is a temporary workaround for vt(4) efifb's  * early use of PHYS_TO_DMAP before the mapping is actually setup. This works  * because the result is not actually accessed until later, but the early  * vt fb startup needs to be reworked.  */
end_comment

begin_define
define|#
directive|define
name|PHYS_TO_DMAP
parameter_list|(
name|x
parameter_list|)
value|({						\ 	KASSERT(dmaplimit == 0 || (x)< dmaplimit,			\ 	    ("physical address %#jx not covered by the DMAP",		\ 	    (uintmax_t)x));						\ 	(x) | DMAP_MIN_ADDRESS; })
end_define

begin_define
define|#
directive|define
name|DMAP_TO_PHYS
parameter_list|(
name|x
parameter_list|)
value|({						\ 	KASSERT((x)< (DMAP_MIN_ADDRESS + dmaplimit)&&			\ 	    (x)>= DMAP_MIN_ADDRESS,					\ 	    ("virtual address %#jx not covered by the DMAP",		\ 	    (uintmax_t)x));						\ 	(x)& ~DMAP_MIN_ADDRESS; })
end_define

begin_comment
comment|/*  * How many physical pages per kmem arena virtual page.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VM_KMEM_SIZE_SCALE
end_ifndef

begin_define
define|#
directive|define
name|VM_KMEM_SIZE_SCALE
value|(1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Optional ceiling (in bytes) on the size of the kmem arena: 60% of the  * kernel map.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VM_KMEM_SIZE_MAX
end_ifndef

begin_define
define|#
directive|define
name|VM_KMEM_SIZE_MAX
value|((VM_MAX_KERNEL_ADDRESS - \     VM_MIN_KERNEL_ADDRESS + 1) * 3 / 5)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* initial pagein size of beginning of executable file */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VM_INITIAL_PAGEIN
end_ifndef

begin_define
define|#
directive|define
name|VM_INITIAL_PAGEIN
value|16
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ZERO_REGION_SIZE
value|(2 * 1024 * 1024)
end_define

begin_comment
comment|/* 2MB */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_VMPARAM_H_ */
end_comment

end_unit

