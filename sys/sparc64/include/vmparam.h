begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  * Copyright (c) 1994 John S. Dyson  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * William Jolitz.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by the University of  *      California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)vmparam.h     5.9 (Berkeley) 5/12/91  *	from: FreeBSD: src/sys/i386/include/vmparam.h,v 1.33 2000/03/30  * $FreeBSD$  */
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
comment|/*  * The time for a process to be blocked before being very swappable.  * This is a number of seconds which the system takes as being a non-trivial  * amount of real time.  You probably shouldn't change this;  * it is used in subtle ways (fractions and multiples of it are, that is, like  * half of a ``long time'', almost a long time, etc.)  * It is related to human patience and other factors which don't really  * change over time.  */
end_comment

begin_define
define|#
directive|define
name|MAXSLP
value|20
end_define

begin_comment
comment|/*  * Highest user address.  Also address of initial user stack.  This is  * arbitrary, neither the structure or size of the user page table (tsb)  * nor the location or size of the kernel virtual address space have any  * bearing on what we use for user addresses.  We want something relatively  * high to give a large address space, but we also have to take the out of  * range va hole into account.  So we pick an address just before the start  * of the hole, which gives a user address space of just under 8TB.  Note  * that if this moves above the va hole, we will have to deal with sign  * extension of virtual addresses.  */
end_comment

begin_define
define|#
directive|define
name|VM_MAXUSER_ADDRESS
value|((vm_offset_t)0x7fe00000000)
end_define

begin_define
define|#
directive|define
name|VM_MIN_ADDRESS
value|((vm_offset_t)0)
end_define

begin_define
define|#
directive|define
name|VM_MAX_ADDRESS
value|(VM_MAXUSER_ADDRESS)
end_define

begin_comment
comment|/*  * Initial user stack address for 64 bit processes.  Should be highest user  * virtual address.  */
end_comment

begin_define
define|#
directive|define
name|USRSTACK
value|VM_MAXUSER_ADDRESS
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
value|(16*1024*1024)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * How many physical pages per KVA page allocated.  * min(max(VM_KMEM_SIZE, Physical memory/VM_KMEM_SIZE_SCALE), VM_KMEM_SIZE_MAX)  * is the total KVA space allocated for kmem_map.  */
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
comment|/*  * Number of 4 meg pages to use for the kernel tsb.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|KVA_PAGES
end_ifndef

begin_define
define|#
directive|define
name|KVA_PAGES
value|(1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Range of kernel virtual addresses.  max = min + range.  */
end_comment

begin_define
define|#
directive|define
name|KVA_RANGE
define|\
value|((KVA_PAGES * PAGE_SIZE_4M)<< (PAGE_SHIFT - TTE_SHIFT))
end_define

begin_comment
comment|/*  * Lowest kernel virtual address, where the kernel is loaded.  *  * If we are using less than 4 super pages for the kernel tsb, the address  * space is less than 4 gigabytes, so put it at the end of the first 4  * gigbytes.  This allows the kernel and the firmware mappings to be mapped  * with a single contiguous tsb.  Otherwise start at 0, we'll cover them  * anyway.  *  * ie:  * kva_pages = 1  *	vm_max_kernel_address	0xffffe000  *	openfirmware		0xf0000000  *	kernbase		0xc0000000  * kva_pages = 8  *	vm_max_kernel_address	0x1ffffe000  *	openfirmware		0xf0000000  *	kernbase		0x0  *  * There are at least 4 pages of dynamic linker junk before kernel text begins,  * so starting at zero is fairly safe (if the firmware will let us).  */
end_comment

begin_if
if|#
directive|if
name|KVA_PAGES
operator|<
literal|4
end_if

begin_define
define|#
directive|define
name|VM_MIN_KERNEL_ADDRESS
value|((1UL<< 32) - KVA_RANGE)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|VM_MIN_KERNEL_ADDRESS
value|(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|VM_MAX_KERNEL_ADDRESS
value|(VM_MIN_KERNEL_ADDRESS + KVA_RANGE - PAGE_SIZE)
end_define

begin_define
define|#
directive|define
name|KERNBASE
value|(VM_MIN_KERNEL_ADDRESS)
end_define

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_VMPARAM_H_ */
end_comment

end_unit

