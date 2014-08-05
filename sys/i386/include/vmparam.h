begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  * Copyright (c) 1994 John S. Dyson  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * William Jolitz.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)vmparam.h	5.9 (Berkeley) 5/12/91  * $FreeBSD$  */
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
comment|/*  * Machine dependent constants for 386.  */
end_comment

begin_comment
comment|/*  * Virtual memory related constants, all in bytes  */
end_comment

begin_define
define|#
directive|define
name|MAXTSIZ
value|(128UL*1024*1024)
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
value|(128UL*1024*1024)
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
value|(512UL*1024*1024)
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
value|(64UL*1024*1024)
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
value|17
end_define

begin_comment
comment|/*  * Create two free page pools.  Since the i386 kernel virtual address  * space does not include a mapping onto the machine's entire physical  * memory, VM_FREEPOOL_DIRECT is defined as an alias for the default  * pool, VM_FREEPOOL_DEFAULT.  */
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
name|VM_FREEPOOL_CACHE
value|1
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
value|0
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
comment|/*  * The largest allocation size is 2MB under PAE and 4MB otherwise.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PAE
end_ifdef

begin_define
define|#
directive|define
name|VM_NFREEORDER
value|10
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|VM_NFREEORDER
value|11
end_define

begin_endif
endif|#
directive|endif
end_endif

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
comment|/*  * Level 0 reservations consist of 512 pages under PAE and 1024 pages  * otherwise.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VM_LEVEL_0_ORDER
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|PAE
end_ifdef

begin_define
define|#
directive|define
name|VM_LEVEL_0_ORDER
value|9
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|VM_LEVEL_0_ORDER
value|10
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
comment|/*  * Kernel physical load address.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|KERNLOAD
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|XEN
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|XEN_PRIVILEGED_GUEST
argument_list|)
end_if

begin_define
define|#
directive|define
name|KERNLOAD
value|0
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|KERNLOAD
value|(1<< PDRSHIFT)
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
comment|/* !defined(KERNLOAD) */
end_comment

begin_comment
comment|/*  * Virtual addresses of things.  Derived from the page directory and  * page table indexes from pmap.h for precision.  * Because of the page that is both a PD and PT, it looks a little  * messy at times, but hey, we'll do anything to save a page :-)  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|XEN
end_ifdef

begin_define
define|#
directive|define
name|VM_MAX_KERNEL_ADDRESS
value|HYPERVISOR_VIRT_START
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|VM_MAX_KERNEL_ADDRESS
value|VADDR(KPTDI+NKPDE-1, NPTEPG-1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|VM_MIN_KERNEL_ADDRESS
value|VADDR(PTDPTDI, PTDPTDI)
end_define

begin_define
define|#
directive|define
name|KERNBASE
value|VADDR(KPTDI, 0)
end_define

begin_define
define|#
directive|define
name|UPT_MAX_ADDRESS
value|VADDR(PTDPTDI, PTDPTDI)
end_define

begin_define
define|#
directive|define
name|UPT_MIN_ADDRESS
value|VADDR(PTDPTDI, 0)
end_define

begin_define
define|#
directive|define
name|VM_MAXUSER_ADDRESS
value|VADDR(PTDPTDI, 0)
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
value|VADDR(PTDPTDI, PTDPTDI)
end_define

begin_define
define|#
directive|define
name|VM_MIN_ADDRESS
value|((vm_offset_t)0)
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
value|(12 * 1024 * 1024)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Optional ceiling (in bytes) on the size of the kmem arena: 40% of the  * kernel map rounded to the nearest multiple of the superpage size.  */
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
value|(((((VM_MAX_KERNEL_ADDRESS - \     VM_MIN_KERNEL_ADDRESS)>> (PDRSHIFT - 2)) + 5) / 10)<< PDRSHIFT)
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
value|(64 * 1024)
end_define

begin_comment
comment|/* 64KB */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VM_MAX_AUTOTUNE_MAXUSERS
end_ifndef

begin_define
define|#
directive|define
name|VM_MAX_AUTOTUNE_MAXUSERS
value|384
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SFBUF
end_define

begin_define
define|#
directive|define
name|SFBUF_MAP
end_define

begin_define
define|#
directive|define
name|SFBUF_CPUSET
end_define

begin_define
define|#
directive|define
name|SFBUF_PROCESS_PAGE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_VMPARAM_H_ */
end_comment

end_unit

