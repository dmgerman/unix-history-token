begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 1995, 1996 Wolfgang Solfrank.  * Copyright (C) 1995, 1996 TooLs GmbH.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by TooLs GmbH.  * 4. The name of TooLs GmbH may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY TOOLS GMBH ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL TOOLS GMBH BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;  * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF  * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  *	$NetBSD: vmparam.h,v 1.11 2000/02/11 19:25:16 thorpej Exp $  * $FreeBSD$  */
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

begin_define
define|#
directive|define
name|USRSTACK
value|SHAREDPAGE
end_define

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
comment|/* default data size */
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
value|(8*1024*1024)
end_define

begin_comment
comment|/* default stack size */
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
value|(64*1024*1024)
end_define

begin_comment
comment|/* max stack size */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|AIM
end_ifdef

begin_define
define|#
directive|define
name|VM_MAXUSER_ADDRESS32
value|((vm_offset_t)0xfffff000)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|VM_MAXUSER_ADDRESS32
value|((vm_offset_t)0x7ffff000)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Would like to have MAX addresses = 0, but this doesn't (currently) work  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|LOCORE
argument_list|)
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|__powerpc64__
end_ifdef

begin_define
define|#
directive|define
name|VM_MIN_ADDRESS
value|(0x0000000000000000UL)
end_define

begin_define
define|#
directive|define
name|VM_MAXUSER_ADDRESS
value|(0xfffffffffffff000UL)
end_define

begin_define
define|#
directive|define
name|VM_MAX_ADDRESS
value|(0xffffffffffffffffUL)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|VM_MIN_ADDRESS
value|((vm_offset_t)0)
end_define

begin_define
define|#
directive|define
name|VM_MAXUSER_ADDRESS
value|VM_MAXUSER_ADDRESS32
end_define

begin_define
define|#
directive|define
name|VM_MAX_ADDRESS
value|((vm_offset_t)0xffffffff)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SHAREDPAGE
value|(VM_MAXUSER_ADDRESS - PAGE_SIZE)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* LOCORE */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__powerpc64__
argument_list|)
operator|&&
name|defined
argument_list|(
name|BOOKE
argument_list|)
end_if

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
value|0x7ffff000
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
comment|/* LOCORE */
end_comment

begin_define
define|#
directive|define
name|FREEBSD32_SHAREDPAGE
value|(VM_MAXUSER_ADDRESS32 - PAGE_SIZE)
end_define

begin_define
define|#
directive|define
name|FREEBSD32_USRSTACK
value|FREEBSD32_SHAREDPAGE
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|AIM
end_ifdef

begin_define
define|#
directive|define
name|KERNBASE
value|0x00100000UL
end_define

begin_comment
comment|/* start of kernel virtual */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__powerpc64__
end_ifdef

begin_define
define|#
directive|define
name|VM_MIN_KERNEL_ADDRESS
value|0xc000000000000000UL
end_define

begin_define
define|#
directive|define
name|VM_MAX_KERNEL_ADDRESS
value|0xc0000001c7ffffffUL
end_define

begin_define
define|#
directive|define
name|VM_MAX_SAFE_KERNEL_ADDRESS
value|VM_MAX_KERNEL_ADDRESS
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|VM_MIN_KERNEL_ADDRESS
value|((vm_offset_t)KERNEL_SR<< ADDR_SR_SHFT)
end_define

begin_define
define|#
directive|define
name|VM_MAX_SAFE_KERNEL_ADDRESS
value|(VM_MIN_KERNEL_ADDRESS + 2*SEGMENT_LENGTH -1)
end_define

begin_define
define|#
directive|define
name|VM_MAX_KERNEL_ADDRESS
value|(VM_MIN_KERNEL_ADDRESS + 3*SEGMENT_LENGTH - 1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Use the direct-mapped BAT registers for UMA small allocs. This  * takes pressure off the small amount of available KVA.  */
end_comment

begin_define
define|#
directive|define
name|UMA_MD_SMALL_ALLOC
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Book-E */
end_comment

begin_define
define|#
directive|define
name|KERNBASE
value|0xc0000000
end_define

begin_comment
comment|/* start of kernel virtual */
end_comment

begin_define
define|#
directive|define
name|VM_MIN_KERNEL_ADDRESS
value|KERNBASE
end_define

begin_define
define|#
directive|define
name|VM_MAX_KERNEL_ADDRESS
value|0xf8000000
end_define

begin_define
define|#
directive|define
name|VM_MAX_SAFE_KERNEL_ADDRESS
value|VM_MAX_KERNEL_ADDRESS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AIM/E500 */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|LOCORE
argument_list|)
end_if

begin_struct
struct|struct
name|pmap_physseg
block|{
name|struct
name|pv_entry
modifier|*
name|pvent
decl_stmt|;
name|char
modifier|*
name|attrs
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|VM_PHYSSEG_MAX
value|16
end_define

begin_comment
comment|/* 1? */
end_comment

begin_comment
comment|/*  * The physical address space is densely populated on 32-bit systems,  * but may not be on 64-bit ones.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__powerpc64__
end_ifdef

begin_define
define|#
directive|define
name|VM_PHYSSEG_SPARSE
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|VM_PHYSSEG_DENSE
end_define

begin_endif
endif|#
directive|endif
end_endif

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
comment|/*  * The largest allocation size is 4MB.  */
end_comment

begin_define
define|#
directive|define
name|VM_NFREEORDER
value|11
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
comment|/*  * Optional ceiling (in bytes) on the size of the kmem arena: 40% of the  * usable KVA space.  */
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
value|((VM_MAX_SAFE_KERNEL_ADDRESS - \     VM_MIN_KERNEL_ADDRESS + 1) * 2 / 5)
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

begin_comment
comment|/*  * On 32-bit OEA, the only purpose for which sf_buf is used is to implement  * an opaque pointer required by the machine-independent parts of the kernel.  * That pointer references the vm_page that is "mapped" by the sf_buf.  The  * actual mapping is provided by the direct virtual-to-physical mapping.  *  * On OEA64 and Book-E, we need to do something a little more complicated. Use  * the runtime-detected hw_direct_map to pick between the two cases. Our  * friends in vm_machdep.c will do the same to ensure nothing gets confused.  */
end_comment

begin_define
define|#
directive|define
name|SFBUF
end_define

begin_define
define|#
directive|define
name|SFBUF_NOMD
end_define

begin_define
define|#
directive|define
name|SFBUF_OPTIONAL_DIRECT_MAP
value|hw_direct_map
end_define

begin_define
define|#
directive|define
name|SFBUF_PHYS_DMAP
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_VMPARAM_H_ */
end_comment

end_unit

