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
value|VM_MAXUSER_ADDRESS
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

begin_comment
comment|/*  * Size of shared memory map  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SHMMAXPGS
end_ifndef

begin_define
define|#
directive|define
name|SHMMAXPGS
value|1024
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * The time for a process to be blocked before being very swappable.  * This is a number of seconds which the system takes as being a non-trivial  * amount of real time.  You probably shouldn't change this;  * it is used in subtle ways (fractions and multiples of it are, that is, like  * half of a ``long time'', almost a long time, etc.)  * It is related to human patience and other factors which don't really  * change over time.  */
end_comment

begin_define
define|#
directive|define
name|MAXSLP
value|20
end_define

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
value|((vm_offset_t)0x7ffff000)
end_define

begin_else
else|#
directive|else
end_else

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

begin_comment
comment|/* LOCORE */
end_comment

begin_define
define|#
directive|define
name|VM_MAX_ADDRESS
value|VM_MAXUSER_ADDRESS
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|AIM
argument_list|)
end_if

begin_comment
comment|/* AIM */
end_comment

begin_define
define|#
directive|define
name|KERNBASE
value|0x00100000
end_define

begin_comment
comment|/* start of kernel virtual */
end_comment

begin_define
define|#
directive|define
name|VM_MIN_KERNEL_ADDRESS
value|((vm_offset_t)(KERNEL_SR<< ADDR_SR_SHFT))
end_define

begin_define
define|#
directive|define
name|VM_MAX_KERNEL_ADDRESS
value|(VM_MIN_KERNEL_ADDRESS + 2*SEGMENT_LENGTH - 1)
end_define

begin_comment
comment|/*  * Use the direct-mapped BAT registers for UMA small allocs. This  * takes pressure off the small amount of available KVA.  */
end_comment

begin_define
define|#
directive|define
name|UMA_MD_SMALL_ALLOC
end_define

begin_comment
comment|/*  * On 64-bit systems in bridge mode, we have no direct map, so we fake  * the small_alloc() calls. But we need the VM to be in a reasonable  * state first.  */
end_comment

begin_define
define|#
directive|define
name|UMA_MD_SMALL_ALLOC_NEEDS_VM
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*  * Kernel CCSRBAR location. We make this the reset location.  */
end_comment

begin_define
define|#
directive|define
name|CCSRBAR_VA
value|0xfef00000
end_define

begin_define
define|#
directive|define
name|CCSRBAR_SIZE
value|0x00100000
end_define

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AIM/E500 */
end_comment

begin_comment
comment|/* XXX max. amount of KVM to be used by buffers. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VM_MAX_KERNEL_BUF
end_ifndef

begin_define
define|#
directive|define
name|VM_MAX_KERNEL_BUF
value|(SEGMENT_LENGTH * 7 / 10)
end_define

begin_endif
endif|#
directive|endif
end_endif

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

begin_ifndef
ifndef|#
directive|ifndef
name|VM_KMEM_SIZE
end_ifndef

begin_define
define|#
directive|define
name|VM_KMEM_SIZE
value|(12 * 1024 * 1024)
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

