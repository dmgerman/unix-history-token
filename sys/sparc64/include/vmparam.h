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
comment|/*  * Address space layout.  *  * UltraSPARC I and II implement a 44 bit virtual address space.  The address  * space is split into 2 regions at each end of the 64 bit address space, with  * an out of range "hole" in the middle.  UltraSPARC III implements the full  * 64 bit virtual address space, but we don't really have any use for it and  * 43 bits of user address space is considered to be "enough", so we ignore it.  *  * Upper region:	0xffffffffffffffff  * 			0xfffff80000000000  *   * Hole:		0xfffff7ffffffffff  * 			0x0000080000000000  *  * Lower region:	0x000007ffffffffff  * 			0x0000000000000000  *  * In general we ignore the upper region, and use the lower region as mappable  * space.  *  * We define some interesting address constants:  *  * VM_MIN_ADDRESS and VM_MAX_ADDRESS define the start and of the entire 64 bit  * address space, mostly just for convenience.  *  * VM_MIN_DIRECT_ADDRESS and VM_MAX_DIRECT_ADDRESS define the start and end  * of the direct mapped region.  This maps virtual addresses to physical  * addresses directly using 4mb tlb entries, with the physical address encoded  * in the lower 43 bits of virtual address.  These mappings are convenient  * because they do not require page tables, and because they never change they  * do not require tlb flushes.  However, since these mappings are cacheable,  * we must ensure that all pages accessed this way are either not double  * mapped, or that all other mappings have virtual color equal to physical  * color, in order to avoid creating illegal aliases in the data cache.  *  * VM_MIN_KERNEL_ADDRESS and VM_MAX_KERNEL_ADDRESS define the start and end of  * mappable kernel virtual address space.  VM_MIN_KERNEL_ADDRESS is basically  * arbitrary, a convenient address is chosen which allows both the kernel text  * and data and the prom's address space to be mapped with 1 4mb tsb page.  * VM_MAX_KERNEL_ADDRESS is variable, computed at startup time based on the  * amount of physical memory available.  Each 4mb tsb page provides 1g of  * virtual address space, with the only practical limit being available  * phsyical memory.  *  * VM_MIN_PROM_ADDRESS and VM_MAX_PROM_ADDRESS define the start and end of the  * prom address space.  On startup the prom's mappings are duplicated in the  * kernel tsb, to allow prom memory to be accessed normally by the kernel.  *  * VM_MIN_USER_ADDRESS and VM_MAX_USER_ADDRESS define the start and end of the  * user address space.  There are some hardware errata about using addresses  * at the boundary of the va hole, so we allow just under 43 bits of user  * address space.  Note that the kernel and user address spaces overlap, but  * this doesn't matter because they use different tlb contexts, and because  * the kernel address space is not mapped into each process' address space.  */
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

begin_define
define|#
directive|define
name|VM_MIN_DIRECT_ADDRESS
value|(0xfffff80000000000UL)
end_define

begin_define
define|#
directive|define
name|VM_MAX_DIRECT_ADDRESS
value|(VM_MAX_ADDRESS)
end_define

begin_define
define|#
directive|define
name|VM_MIN_KERNEL_ADDRESS
value|(0x00000000c0000000UL)
end_define

begin_define
define|#
directive|define
name|VM_MAX_KERNEL_ADDRESS
value|(vm_max_kernel_address)
end_define

begin_define
define|#
directive|define
name|VM_MIN_PROM_ADDRESS
value|(0x00000000f0000000UL)
end_define

begin_define
define|#
directive|define
name|VM_MAX_PROM_ADDRESS
value|(0x00000000ffffe000UL)
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
value|(0x000007fe00000000UL)
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
name|USRSTACK
value|(VM_MAX_USER_ADDRESS)
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
comment|/*  * How many physical pages per KVA page allocated.  * min(max(max(VM_KMEM_SIZE, Physical memory/VM_KMEM_SIZE_SCALE),  *     VM_KMEM_SIZE_MIN), VM_KMEM_SIZE_MAX)  * is the total KVA space allocated for kmem_map.  */
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

begin_decl_stmt
specifier|extern
name|vm_offset_t
name|vm_max_kernel_address
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_VMPARAM_H_ */
end_comment

end_unit

