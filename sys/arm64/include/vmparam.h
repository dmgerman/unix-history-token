begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  * Copyright (c) 1994 John S. Dyson  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * William Jolitz.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)vmparam.h     5.9 (Berkeley) 5/12/91  *	from: FreeBSD: src/sys/i386/include/vmparam.h,v 1.33 2000/03/30  * $FreeBSD$  */
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
value|(1*1024*1024*1024)
end_define

begin_comment
comment|/* max text size */
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
value|(128*1024*1024)
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
value|(1*1024*1024*1024)
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
value|(128*1024*1024)
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
value|(1*1024*1024*1024)
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
value|(128*1024)
end_define

begin_comment
comment|/* amount to grow stack */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * The physical address space is sparsely populated.  */
end_comment

begin_define
define|#
directive|define
name|VM_PHYSSEG_SPARSE
end_define

begin_comment
comment|/*  * The number of PHYSSEG entries must be one greater than the number  * of phys_avail entries because the phys_avail entry that spans the  * largest physical address that is accessible by ISA DMA is split  * into two PHYSSEG entries.  */
end_comment

begin_define
define|#
directive|define
name|VM_PHYSSEG_MAX
value|64
end_define

begin_comment
comment|/*  * Create two free page pools: VM_FREEPOOL_DEFAULT is the default pool  * from which physical pages are allocated and VM_FREEPOOL_DIRECT is  * the pool from which physical pages for small UMA objects are  * allocated.  */
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
comment|/*  * Create two free page lists: VM_FREELIST_DEFAULT is for physical  * pages that are above the largest physical address that is  * accessible by ISA DMA and VM_FREELIST_ISADMA is for physical pages  * that are below that address.  */
end_comment

begin_define
define|#
directive|define
name|VM_NFREELIST
value|2
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
name|VM_FREELIST_ISADMA
value|1
end_define

begin_comment
comment|/*  * An allocation size of 16MB is supported in order to optimize the  * use of the direct map by UMA.  Specifically, a cache line contains  * at most four TTEs, collectively mapping 16MB of physical memory.  * By reducing the number of distinct 16MB "pages" that are used by UMA,  * the physical memory allocator reduces the likelihood of both 4MB  * page TLB misses and cache misses caused by 4MB page TLB misses.  */
end_comment

begin_define
define|#
directive|define
name|VM_NFREEORDER
value|12
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

begin_comment
comment|/**  * Address space layout.  *  * ARMv8 implements up to a 48 bit virtual address space. The address space is  * split into 2 regions at each end of the 64 bit address space, with an  * out of range "hole" in the middle.  *  * We use the full 48 bits for each region, however the kernel may only use  * a limited range within this space.  *  * Upper region:    0xffffffffffffffff  Top of virtual memory  *  *                  0xfffffeffffffffff  End of DMAP  *                  0xfffffd0000000000  Start of DMAP  *  *                  0xffff007fffffffff  End of KVA  *                  0xffff000000000000  Kernel base address& start of KVA  *  * Hole:            0xfffeffffffffffff  *                  0x0001000000000000  *  * Lower region:    0x0000ffffffffffff End of user address space  *                  0x0000000000000000 Start of user address space  *  * We use the upper region for the kernel, and the lower region for userland.  *  * We define some interesting address constants:  *  * VM_MIN_ADDRESS and VM_MAX_ADDRESS define the start and end of the entire  * 64 bit address space, mostly just for convenience.  *  * VM_MIN_KERNEL_ADDRESS and VM_MAX_KERNEL_ADDRESS define the start and end of  * mappable kernel virtual address space.  *  * VM_MIN_USER_ADDRESS and VM_MAX_USER_ADDRESS define the start and end of the  * user address space.  */
end_comment

begin_define
define|#
directive|define
name|VM_MIN_ADDRESS
value|(0x0000000000000000UL)
end_define

begin_define
define|#
directive|define
name|VM_MAX_ADDRESS
value|(0xffffffffffffffffUL)
end_define

begin_comment
comment|/* 512 GiB of kernel addresses */
end_comment

begin_define
define|#
directive|define
name|VM_MIN_KERNEL_ADDRESS
value|(0xffff000000000000UL)
end_define

begin_define
define|#
directive|define
name|VM_MAX_KERNEL_ADDRESS
value|(0xffff008000000000UL)
end_define

begin_comment
comment|/* 2 TiB maximum for the direct map region */
end_comment

begin_define
define|#
directive|define
name|DMAP_MIN_ADDRESS
value|(0xfffffd0000000000UL)
end_define

begin_define
define|#
directive|define
name|DMAP_MAX_ADDRESS
value|(0xffffff0000000000UL)
end_define

begin_define
define|#
directive|define
name|DMAP_MIN_PHYSADDR
value|(dmap_phys_base)
end_define

begin_define
define|#
directive|define
name|DMAP_MAX_PHYSADDR
value|(dmap_phys_max)
end_define

begin_comment
comment|/* True if pa is in the dmap range */
end_comment

begin_define
define|#
directive|define
name|PHYS_IN_DMAP
parameter_list|(
name|pa
parameter_list|)
value|((pa)>= DMAP_MIN_PHYSADDR&& \     (pa)< DMAP_MAX_PHYSADDR)
end_define

begin_comment
comment|/* True if va is in the dmap range */
end_comment

begin_define
define|#
directive|define
name|VIRT_IN_DMAP
parameter_list|(
name|va
parameter_list|)
value|((va)>= DMAP_MIN_ADDRESS&& \     (va)< (dmap_max_addr))
end_define

begin_define
define|#
directive|define
name|PHYS_TO_DMAP
parameter_list|(
name|pa
parameter_list|)
define|\
value|({									\ 	KASSERT(PHYS_IN_DMAP(pa),					\ 	    ("%s: PA out of range, PA: 0x%lx", __func__,		\ 	    (vm_paddr_t)(pa)));						\ 	((pa) - dmap_phys_base) | DMAP_MIN_ADDRESS;			\ })
end_define

begin_define
define|#
directive|define
name|DMAP_TO_PHYS
parameter_list|(
name|va
parameter_list|)
define|\
value|({									\ 	KASSERT(VIRT_IN_DMAP(va),					\ 	    ("%s: VA out of range, VA: 0x%lx", __func__,		\ 	    (vm_offset_t)(va)));					\ 	((va)& ~DMAP_MIN_ADDRESS) + dmap_phys_base;			\ })
end_define

begin_define
define|#
directive|define
name|VM_MIN_USER_ADDRESS
value|(0x0000000000000000UL)
end_define

begin_define
define|#
directive|define
name|VM_MAX_USER_ADDRESS
value|(0x0001000000000000UL)
end_define

begin_define
define|#
directive|define
name|VM_MINUSER_ADDRESS
value|(VM_MIN_USER_ADDRESS)
end_define

begin_define
define|#
directive|define
name|VM_MAXUSER_ADDRESS
value|(VM_MAX_USER_ADDRESS)
end_define

begin_define
define|#
directive|define
name|KERNBASE
value|(VM_MIN_KERNEL_ADDRESS)
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
value|(3)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Optional floor (in bytes) on the size of the kmem arena.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VM_KMEM_SIZE_MIN
end_ifndef

begin_define
define|#
directive|define
name|VM_KMEM_SIZE_MIN
value|(16 * 1024 * 1024)
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
comment|/*  * Initial pagein size of beginning of executable file.  */
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
name|UMA_MD_SMALL_ALLOC
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_decl_stmt
specifier|extern
name|vm_paddr_t
name|dmap_phys_base
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|vm_paddr_t
name|dmap_phys_max
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|vm_offset_t
name|dmap_max_addr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int
name|tsb_kernel_ldd_phys
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|vm_offset_t
name|vm_max_kernel_address
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|vm_offset_t
name|init_pt_va
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ZERO_REGION_SIZE
value|(64 * 1024)
end_define

begin_comment
comment|/* 64KB */
end_comment

begin_define
define|#
directive|define
name|DEVMAP_MAX_VADDR
value|VM_MAX_KERNEL_ADDRESS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_VMPARAM_H_ */
end_comment

end_unit

