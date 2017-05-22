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
comment|/*  * Machine dependent constants for ARM.  */
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
value|(256UL*1024*1024)
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
value|(2UL*1024*1024)
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
value|(8UL*1024*1024)
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
comment|/*  * Address space constants  */
end_comment

begin_comment
comment|/*  * The line between user space and kernel space  * Mappings>= KERNEL_BASE are constant across all processes  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|KERNBASE
end_ifndef

begin_define
define|#
directive|define
name|KERNBASE
value|0xc0000000
end_define

begin_endif
endif|#
directive|endif
end_endif

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
comment|/*  * The physical address space may be sparsely populated on some ARM systems.  */
end_comment

begin_define
define|#
directive|define
name|VM_PHYSSEG_SPARSE
end_define

begin_comment
comment|/*  * Create one free page pool.  Since the ARM kernel virtual address  * space does not include a mapping onto the machine's entire physical  * memory, VM_FREEPOOL_DIRECT is defined as an alias for the default  * pool, VM_FREEPOOL_DEFAULT.  */
end_comment

begin_define
define|#
directive|define
name|VM_NFREEPOOL
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
comment|/*  * We need just one free list:  DEFAULT.  */
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
comment|/*  * The largest allocation size is 1MB.  */
end_comment

begin_define
define|#
directive|define
name|VM_NFREEORDER
value|9
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
comment|/*  * Level 0 reservations consist of 256 pages.  */
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
value|8
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|VM_MIN_ADDRESS
value|(0x00001000)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|VM_MAXUSER_ADDRESS
end_ifndef

begin_define
define|#
directive|define
name|VM_MAXUSER_ADDRESS
value|(KERNBASE - 0x00400000)
end_define

begin_comment
comment|/* !!! PT2MAP_SIZE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|VM_MAX_ADDRESS
value|VM_MAXUSER_ADDRESS
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
value|((vm_max_kernel_address - \     VM_MIN_KERNEL_ADDRESS + 1) * 2 / 5)
end_define

begin_endif
endif|#
directive|endif
end_endif

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
name|DEVMAP_MAX_VADDR
value|ARM_VECTORS_HIGH
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_VMPARAM_H_ */
end_comment

end_unit

