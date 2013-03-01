begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: vmparam.h,v 1.26 2003/08/07 16:27:47 agc Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 1988 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
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
comment|/*#include<arm/arm32/vmparam.h> */
end_comment

begin_comment
comment|/*  * Address space constants  */
end_comment

begin_comment
comment|/*  * The line between user space and kernel space  * Mappings>= KERNEL_BASE are constant across all processes  */
end_comment

begin_define
define|#
directive|define
name|KERNBASE
value|0xc0000000
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
comment|/*  * The physical address space is densely populated.  */
end_comment

begin_define
define|#
directive|define
name|VM_PHYSSEG_DENSE
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
comment|/*  * we support 2 free lists:  *  *	- DEFAULT for all systems  *	- ISADMA for the ISA DMA range on Sharks only  */
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
comment|/*  * The largest allocation size is 1MB.  */
end_comment

begin_define
define|#
directive|define
name|VM_NFREEORDER
value|9
end_define

begin_comment
comment|/*  * Only one memory domain.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VM_NDOMAIN
end_ifndef

begin_define
define|#
directive|define
name|VM_NDOMAIN
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

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
name|UPT_MAX_ADDRESS
value|VADDR(UPTPTDI + 3, 0)
end_define

begin_define
define|#
directive|define
name|UPT_MIN_ADDRESS
value|VADDR(UPTPTDI, 0)
end_define

begin_define
define|#
directive|define
name|VM_MIN_ADDRESS
value|(0x00001000)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|ARM_USE_SMALL_ALLOC
end_ifdef

begin_comment
comment|/*  * ARM_KERN_DIRECTMAP is used to make sure there's enough space between  * VM_MAXUSER_ADDRESS and KERNBASE to map the whole memory.  * It has to be a compile-time constant, even if arm_init_smallalloc(),  * which will do the mapping, gets the real amount of memory at runtime,  * because VM_MAXUSER_ADDRESS is a constant.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ARM_KERN_DIRECTMAP
end_ifndef

begin_define
define|#
directive|define
name|ARM_KERN_DIRECTMAP
value|512 * 1024 * 1024
end_define

begin_comment
comment|/* 512 MB */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|VM_MAXUSER_ADDRESS
value|KERNBASE - ARM_KERN_DIRECTMAP
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ARM_USE_SMALL_ALLOC */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VM_MAXUSER_ADDRESS
end_ifndef

begin_define
define|#
directive|define
name|VM_MAXUSER_ADDRESS
value|KERNBASE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VM_MAXUSER_ADDRESS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ARM_USE_SMALL_ALLOC */
end_comment

begin_define
define|#
directive|define
name|VM_MAX_ADDRESS
value|VM_MAXUSER_ADDRESS
end_define

begin_define
define|#
directive|define
name|USRSTACK
value|VM_MAXUSER_ADDRESS
end_define

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

begin_ifndef
ifndef|#
directive|ifndef
name|VM_MIN_KERNEL_ADDRESS
end_ifndef

begin_define
define|#
directive|define
name|VM_MIN_KERNEL_ADDRESS
value|KERNBASE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|VM_MAX_KERNEL_ADDRESS
value|(vm_max_kernel_address)
end_define

begin_comment
comment|/*  * Virtual size (bytes) for various kernel submaps.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VM_KMEM_SIZE
end_ifndef

begin_define
define|#
directive|define
name|VM_KMEM_SIZE
value|(12*1024*1024)
end_define

begin_endif
endif|#
directive|endif
end_endif

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
comment|/*  * Ceiling on the size of the kmem submap: 40% of the kernel map.  */
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
value|((vm_max_kernel_address - \     VM_MIN_KERNEL_ADDRESS + 1) * 2 / 5)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MAXTSIZ
end_ifndef

begin_define
define|#
directive|define
name|MAXTSIZ
value|(64*1024*1024)
end_define

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
value|(512*1024*1024)
end_define

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
value|(2*1024*1024)
end_define

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
value|(8*1024*1024)
end_define

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

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|ARM_USE_SMALL_ALLOC
end_ifdef

begin_define
define|#
directive|define
name|UMA_MD_SMALL_ALLOC
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ARM_USE_SMALL_ALLOC */
end_comment

begin_decl_stmt
specifier|extern
name|vm_offset_t
name|vm_max_kernel_address
decl_stmt|;
end_decl_stmt

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_VMPARAM_H_ */
end_comment

end_unit

