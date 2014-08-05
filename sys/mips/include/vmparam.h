begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: vmparam.h,v 1.2 1998/09/15 10:50:12 pefo Exp $	*/
end_comment

begin_comment
comment|/*	$NetBSD: vmparam.h,v 1.5 1994/10/26 21:10:10 cgd Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1988 University of Utah.  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department and Ralph Campbell.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: Utah Hdr: vmparam.h 1.16 91/01/18  *	@(#)vmparam.h	8.2 (Berkeley) 4/22/94  *	JNPR: vmparam.h,v 1.3.2.1 2007/09/10 06:01:28 girish  * $FreeBSD$  */
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
comment|/*  * Machine dependent constants mips processors.  */
end_comment

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
value|(128UL*1024*1024)
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
value|(1*1024UL*1024*1024)
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
comment|/*  * Mach derived constants  */
end_comment

begin_comment
comment|/* user/kernel map constants */
end_comment

begin_define
define|#
directive|define
name|VM_MIN_ADDRESS
value|((vm_offset_t)0x00000000)
end_define

begin_define
define|#
directive|define
name|VM_MAX_ADDRESS
value|((vm_offset_t)(intptr_t)(int32_t)0xffffffff)
end_define

begin_define
define|#
directive|define
name|VM_MINUSER_ADDRESS
value|((vm_offset_t)0x00000000)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__mips_n64
end_ifdef

begin_define
define|#
directive|define
name|VM_MAXUSER_ADDRESS
value|(VM_MINUSER_ADDRESS + (NPDEPG * NBSEG))
end_define

begin_define
define|#
directive|define
name|VM_MIN_KERNEL_ADDRESS
value|((vm_offset_t)0xc000000000000000)
end_define

begin_define
define|#
directive|define
name|VM_MAX_KERNEL_ADDRESS
value|(VM_MIN_KERNEL_ADDRESS + (NPDEPG * NBSEG))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|VM_MAXUSER_ADDRESS
value|((vm_offset_t)0x80000000)
end_define

begin_define
define|#
directive|define
name|VM_MIN_KERNEL_ADDRESS
value|((vm_offset_t)0xC0000000)
end_define

begin_define
define|#
directive|define
name|VM_MAX_KERNEL_ADDRESS
value|((vm_offset_t)0xFFFFC000)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|KERNBASE
value|((vm_offset_t)(intptr_t)(int32_t)0x80000000)
end_define

begin_comment
comment|/*  * USRSTACK needs to start a little below 0x8000000 because the R8000  * and some QED CPUs perform some virtual address checks before the  * offset is calculated.  */
end_comment

begin_define
define|#
directive|define
name|USRSTACK
value|(VM_MAXUSER_ADDRESS - PAGE_SIZE)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__mips_n64
end_ifdef

begin_define
define|#
directive|define
name|FREEBSD32_USRSTACK
value|(((vm_offset_t)0x80000000) - PAGE_SIZE)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Disable superpage reservations. (not sure if this is right  * I copied it from ARM)  */
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
comment|/*  * Optional ceiling (in bytes) on the size of the kmem arena: 40% of the  * kernel map.  */
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
value|((VM_MAX_KERNEL_ADDRESS - \     VM_MIN_KERNEL_ADDRESS + 1) * 2 / 5)
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
name|UMA_MD_SMALL_ALLOC
end_define

begin_comment
comment|/*  * max number of non-contig chunks of physical RAM you can have  */
end_comment

begin_define
define|#
directive|define
name|VM_PHYSSEG_MAX
value|32
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
comment|/*  * we support 2 free lists:  *  *	- DEFAULT for direct mapped (KSEG0) pages.  *	  Note: This usage of DEFAULT may be misleading because we use  *	  DEFAULT for allocating direct mapped pages. The normal page  *	  allocations use HIGHMEM if available, and then DEFAULT.   *	- HIGHMEM for other pages   */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__mips_n64
end_ifdef

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

begin_define
define|#
directive|define
name|VM_FREELIST_DIRECT
value|VM_FREELIST_DEFAULT
end_define

begin_else
else|#
directive|else
end_else

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
value|1
end_define

begin_define
define|#
directive|define
name|VM_FREELIST_HIGHMEM
value|0
end_define

begin_define
define|#
directive|define
name|VM_FREELIST_DIRECT
value|VM_FREELIST_DEFAULT
end_define

begin_define
define|#
directive|define
name|VM_HIGHMEM_ADDRESS
value|((vm_paddr_t)0x20000000)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * The largest allocation size is 1MB.  */
end_comment

begin_define
define|#
directive|define
name|VM_NFREEORDER
value|9
end_define

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
name|__mips_n64
end_ifndef

begin_define
define|#
directive|define
name|SFBUF
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
comment|/* !_MACHINE_VMPARAM_H_ */
end_comment

end_unit

