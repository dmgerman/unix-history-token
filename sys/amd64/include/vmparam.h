begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  * Copyright (c) 1994 John S. Dyson  * All rights reserved.  * Copyright (c) 2003 Peter Wemm  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * William Jolitz.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)vmparam.h	5.9 (Berkeley) 5/12/91  * $FreeBSD$  */
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
comment|/*  * Machine dependent constants for AMD64.  */
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
value|(32768UL*1024*1024)
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
value|(512UL*1024*1024)
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
comment|/*  * The time for a process to be blocked before being very swappable.  * This is a number of seconds which the system takes as being a non-trivial  * amount of real time.  You probably shouldn't change this;  * it is used in subtle ways (fractions and multiples of it are, that is, like  * half of a ``long time'', almost a long time, etc.)  * It is related to human patience and other factors which don't really  * change over time.  */
end_comment

begin_define
define|#
directive|define
name|MAXSLP
value|20
end_define

begin_comment
comment|/*  * We provide a machine specific single page allocator through the use  * of the direct mapped segment.  This uses 2MB pages for reduced  * TLB pressure.  */
end_comment

begin_define
define|#
directive|define
name|UMA_MD_SMALL_ALLOC
end_define

begin_comment
comment|/*  * Virtual addresses of things.  Derived from the page directory and  * page table indexes from pmap.h for precision.  *  * 0x0000000000000000 - 0x00007fffffffffff   user map  * 0x0000800000000000 - 0xffff7fffffffffff   does not exist (hole)  * 0xffff800000000000 - 0xffff804020100fff   recursive page table (512GB slot)  * 0xffff804020101000 - 0xfffffeffffffffff   unused  * 0xffffff0000000000 - 0xffffff7fffffffff   512GB direct map mappings  * 0xffffff8000000000 - 0xffffffff7fffffff   unused (510GB)  * 0xffffffff80000000 - 0xffffffffffffffff   2GB kernel map  *  * Within the kernel map:  * 0xffffffff80000000                        KERNBASE  */
end_comment

begin_define
define|#
directive|define
name|VM_MAX_KERNEL_ADDRESS
value|KVADDR(KPML4I, NPDPEPG-1, NKPDE-1, NPTEPG-1)
end_define

begin_define
define|#
directive|define
name|VM_MIN_KERNEL_ADDRESS
value|KVADDR(KPML4I, KPDPI, 0, 0)
end_define

begin_define
define|#
directive|define
name|DMAP_MIN_ADDRESS
value|KVADDR(DMPML4I, 0, 0, 0)
end_define

begin_define
define|#
directive|define
name|DMAP_MAX_ADDRESS
value|KVADDR(DMPML4I+1, 0, 0, 0)
end_define

begin_define
define|#
directive|define
name|KERNBASE
value|KVADDR(KPML4I, KPDPI, 0, 0)
end_define

begin_define
define|#
directive|define
name|UPT_MAX_ADDRESS
value|KVADDR(PML4PML4I, PML4PML4I, PML4PML4I, PML4PML4I)
end_define

begin_define
define|#
directive|define
name|UPT_MIN_ADDRESS
value|KVADDR(PML4PML4I, 0, 0, 0)
end_define

begin_define
define|#
directive|define
name|VM_MAXUSER_ADDRESS
value|UVADDR(NUPML4E, 0, 0, 0)
end_define

begin_define
define|#
directive|define
name|USRSTACK
value|VM_MAXUSER_ADDRESS
end_define

begin_define
define|#
directive|define
name|VM_MAX_ADDRESS
value|UPT_MAX_ADDRESS
end_define

begin_define
define|#
directive|define
name|VM_MIN_ADDRESS
value|(0)
end_define

begin_define
define|#
directive|define
name|PHYS_TO_DMAP
parameter_list|(
name|x
parameter_list|)
value|((x) | DMAP_MIN_ADDRESS)
end_define

begin_define
define|#
directive|define
name|DMAP_TO_PHYS
parameter_list|(
name|x
parameter_list|)
value|((x)& ~DMAP_MIN_ADDRESS)
end_define

begin_comment
comment|/* virtual sizes (bytes) for various kernel submaps */
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
value|(12 * 1024 * 1024)
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
comment|/*  * Ceiling on amount of kmem_map kva space.  */
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
value|(400 * 1024 * 1024)
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_VMPARAM_H_ */
end_comment

end_unit

