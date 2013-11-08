begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1988 University of Utah.  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department and Ralph Campbell.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * from: Utah $Hdr: vmparam.h 1.16 91/01/18$  *  *	@(#)vmparam.h	8.2 (Berkeley) 4/22/94  *  * $FreeBSD$  */
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
end_define

begin_comment
comment|/*  * Virtual memory related constants, all in bytes  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MAXTSIZ
end_ifndef

begin_define
define|#
directive|define
name|MAXTSIZ
value|(1<<30)
end_define

begin_comment
comment|/* max text size (1G) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DFLDSIZ
end_ifndef

begin_define
define|#
directive|define
name|DFLDSIZ
value|(1<<27)
end_define

begin_comment
comment|/* initial data size (128M) */
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
value|(1<<30)
end_define

begin_comment
comment|/* max data size (1G) */
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
value|(1<<21)
end_define

begin_comment
comment|/* initial stack size (2M) */
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
value|(1<<28)
end_define

begin_comment
comment|/* max stack size (256M) */
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
comment|/*  * We need region 7 virtual addresses for pagetables.  */
end_comment

begin_define
define|#
directive|define
name|UMA_MD_SMALL_ALLOC
end_define

begin_comment
comment|/*  * The physical address space is sparsely populated.  */
end_comment

begin_define
define|#
directive|define
name|VM_PHYSSEG_SPARSE
end_define

begin_comment
comment|/*  * The number of PHYSSEG entries is equal to the number of phys_avail  * entries.  */
end_comment

begin_define
define|#
directive|define
name|VM_PHYSSEG_MAX
value|49
end_define

begin_comment
comment|/*  * Create three free page pools: VM_FREEPOOL_DEFAULT is the default pool  * from which physical pages are allocated and VM_FREEPOOL_DIRECT is  * the pool from which physical pages for small UMA objects are  * allocated.  */
end_comment

begin_define
define|#
directive|define
name|VM_NFREEPOOL
value|3
end_define

begin_define
define|#
directive|define
name|VM_FREEPOOL_CACHE
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
comment|/*  * Create one free page list.  */
end_comment

begin_define
define|#
directive|define
name|VM_NFREELIST
value|1
end_define

begin_define
define|#
directive|define
name|VM_FREELIST_DEFAULT
value|0
end_define

begin_comment
comment|/*  * An allocation size of 256MB is supported in order to optimize the  * use of the identity mappings in region 7 by UMA.  */
end_comment

begin_define
define|#
directive|define
name|VM_NFREEORDER
value|16
end_define

begin_comment
comment|/*  * Disable superpage reservations.  */
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
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|IA64_VM_MINKERN_REGION
value|4
end_define

begin_comment
comment|/*  * Manipulating region bits of an address.  */
end_comment

begin_define
define|#
directive|define
name|IA64_RR_BASE
parameter_list|(
name|n
parameter_list|)
value|(((uint64_t) (n))<< 61)
end_define

begin_define
define|#
directive|define
name|IA64_RR_MASK
parameter_list|(
name|x
parameter_list|)
value|((x)& ((1L<< 61) - 1))
end_define

begin_define
define|#
directive|define
name|IA64_PHYS_TO_RR6
parameter_list|(
name|x
parameter_list|)
value|((x) | IA64_RR_BASE(6))
end_define

begin_define
define|#
directive|define
name|IA64_PHYS_TO_RR7
parameter_list|(
name|x
parameter_list|)
value|((x) | IA64_RR_BASE(7))
end_define

begin_comment
comment|/*  * The Itanium architecture defines that all implementations support at  * least 51 virtual address bits (i.e. IMPL_VA_MSB=50). The unimplemented  * bits are sign-extended from VA{IMPL_VA_MSB}. As such, there's a gap in  * the virtual address range, which extends at most from 0x0004000000000000  * to 0x1ffbffffffffffff. We define the top half of a region in terms of  * this worst-case gap.  */
end_comment

begin_define
define|#
directive|define
name|IA64_REGION_GAP_START
value|0x0004000000000000
end_define

begin_define
define|#
directive|define
name|IA64_REGION_GAP_EXTEND
value|0x1ffc000000000000
end_define

begin_comment
comment|/*  * Parameters for Pre-Boot Virtual Memory (PBVM).  * The kernel, its modules and metadata are loaded in the PBVM by the loader.  * The PBVM consists of pages for which the mapping is maintained in a page  * table. The page table is at least 1 EFI page large (i.e. 4KB), but can be  * larger to accommodate more PBVM. The maximum page table size is 1MB. With  * 8 bytes per page table entry, this means that the PBVM has at least 512  * pages and at most 128K pages.  * The GNU toolchain (in particular GNU ld) does not support an alignment  * larger than 64K. This means that we cannot guarantee page alignment for  * a page size that's larger than 64K. We do want to have text and data in  * different pages, which means that the maximum usable page size is 64KB.  * Consequently:  * The maximum total PBVM size is 8GB -- enough for a DVD image. A page table  * of a single EFI page (4KB) allows for 32MB of PBVM.  *  * The kernel is given the PA and size of the page table that provides the  * mapping of the PBVM. The page table itself is assumed to be mapped at a  * known virtual address and using a single translation wired into the CPU.  * As such, the page table is assumed to be a power of 2 and naturally aligned.  * The kernel also assumes that a good portion of the kernel text is mapped  * and wired into the CPU, but does not assume that the mapping covers the  * whole of PBVM.  */
end_comment

begin_define
define|#
directive|define
name|IA64_PBVM_RR
value|IA64_VM_MINKERN_REGION
end_define

begin_define
define|#
directive|define
name|IA64_PBVM_BASE
define|\
value|(IA64_RR_BASE(IA64_PBVM_RR) + IA64_REGION_GAP_EXTEND)
end_define

begin_define
define|#
directive|define
name|IA64_PBVM_PGTBL_MAXSZ
value|1048576
end_define

begin_define
define|#
directive|define
name|IA64_PBVM_PGTBL
define|\
value|(IA64_RR_BASE(IA64_PBVM_RR + 1) - IA64_PBVM_PGTBL_MAXSZ)
end_define

begin_define
define|#
directive|define
name|IA64_PBVM_PAGE_SHIFT
value|16
end_define

begin_comment
comment|/* 64KB */
end_comment

begin_define
define|#
directive|define
name|IA64_PBVM_PAGE_SIZE
value|(1<< IA64_PBVM_PAGE_SHIFT)
end_define

begin_define
define|#
directive|define
name|IA64_PBVM_PAGE_MASK
value|(IA64_PBVM_PAGE_SIZE - 1)
end_define

begin_comment
comment|/*  * Mach derived constants  */
end_comment

begin_comment
comment|/* user/kernel map constants */
end_comment

begin_define
define|#
directive|define
name|VM_MIN_ADDRESS
value|0
end_define

begin_define
define|#
directive|define
name|VM_MAXUSER_ADDRESS
value|IA64_RR_BASE(IA64_VM_MINKERN_REGION)
end_define

begin_define
define|#
directive|define
name|VM_MIN_KERNEL_ADDRESS
value|VM_MAXUSER_ADDRESS
end_define

begin_define
define|#
directive|define
name|VM_INIT_KERNEL_ADDRESS
value|IA64_RR_BASE(IA64_VM_MINKERN_REGION + 1)
end_define

begin_define
define|#
directive|define
name|VM_MAX_KERNEL_ADDRESS
value|(IA64_RR_BASE(IA64_VM_MINKERN_REGION + 2) - 1)
end_define

begin_define
define|#
directive|define
name|VM_MAX_ADDRESS
value|~0UL
end_define

begin_comment
comment|/* We link the kernel at IA64_PBVM_BASE. */
end_comment

begin_define
define|#
directive|define
name|KERNBASE
value|IA64_PBVM_BASE
end_define

begin_comment
comment|/*  * USRSTACK is the top (end) of the user stack.  Immediately above the user  * stack resides the syscall gateway page.  */
end_comment

begin_define
define|#
directive|define
name|USRSTACK
value|VM_MAXUSER_ADDRESS
end_define

begin_define
define|#
directive|define
name|IA64_BACKINGSTORE
value|(USRSTACK - (2 * MAXSSIZ) - PAGE_SIZE)
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
value|(4)
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
comment|/* !_MACHINE_VMPARAM_H_ */
end_comment

end_unit

