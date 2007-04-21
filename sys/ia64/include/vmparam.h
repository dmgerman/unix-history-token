begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* From: NetBSD: vmparam.h,v 1.6 1997/09/23 23:23:23 mjacob Exp */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_VMPARAM_H
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_VMPARAM_H
end_define

begin_comment
comment|/*-  * Copyright (c) 1988 University of Utah.  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department and Ralph Campbell.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * from: Utah $Hdr: vmparam.h 1.16 91/01/18$  *  *	@(#)vmparam.h	8.2 (Berkeley) 4/22/94  */
end_comment

begin_comment
comment|/*  * Machine dependent constants for ia64.  */
end_comment

begin_comment
comment|/*  * USRTEXT is the start of the user text/data space, while USRSTACK  * is the top (end) of the user stack.  Immediately above the user stack  * resides the syscall gateway page.  */
end_comment

begin_define
define|#
directive|define
name|USRTEXT
value|CLBYTES
end_define

begin_define
define|#
directive|define
name|USRSTACK
value|VM_MAX_ADDRESS
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
value|(1<<30)
end_define

begin_comment
comment|/* max text size (1G) */
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
value|(1<<27)
end_define

begin_comment
comment|/* initial data size (128M) */
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
value|(1<<30)
end_define

begin_comment
comment|/* max data size (1G) */
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
value|(1<<21)
end_define

begin_comment
comment|/* initial stack size (2M) */
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
value|(1<<28)
end_define

begin_comment
comment|/* max stack size (256M) */
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
comment|/*  * Boundary at which to place first MAPMEM segment if not explicitly  * specified.  Should be a power of two.  This allows some slop for  * the data segment to grow underneath the first mapped segment.  */
end_comment

begin_define
define|#
directive|define
name|MMSEG
value|0x200000
end_define

begin_comment
comment|/*  * The size of the clock loop.  */
end_comment

begin_define
define|#
directive|define
name|LOOPPAGES
value|(maxfree - firstfree)
end_define

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
comment|/*  * A swapped in process is given a small amount of core without being bothered  * by the page replacement algorithm.  Basically this says that if you are  * swapped in you deserve some resources.  We protect the last SAFERSS  * pages against paging and will just swap you out rather than paging you.  * Note that each process has at least UPAGES pages which are not  * paged anyways, in addition to SAFERSS.  */
end_comment

begin_define
define|#
directive|define
name|SAFERSS
value|10
end_define

begin_comment
comment|/* nominal ``small'' resident set size 					   protected against replacement */
end_comment

begin_comment
comment|/*  * We need region 7 virtual addresses for pagetables.  */
end_comment

begin_define
define|#
directive|define
name|UMA_MD_SMALL_ALLOC
end_define

begin_comment
comment|/*  * Manipulating region bits of an address.  */
end_comment

begin_define
define|#
directive|define
name|IA64_RR_BASE
parameter_list|(
name|n
parameter_list|)
value|(((u_int64_t) (n))<< 61)
end_define

begin_define
define|#
directive|define
name|IA64_RR_MASK
parameter_list|(
name|x
parameter_list|)
value|((x)& ((1L<< 61) - 1))
end_define

begin_define
define|#
directive|define
name|IA64_PHYS_TO_RR6
parameter_list|(
name|x
parameter_list|)
value|((x) | IA64_RR_BASE(6))
end_define

begin_define
define|#
directive|define
name|IA64_PHYS_TO_RR7
parameter_list|(
name|x
parameter_list|)
value|((x) | IA64_RR_BASE(7))
end_define

begin_comment
comment|/*  * Page size of the identity mappings in region 7.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LOG2_ID_PAGE_SIZE
end_ifndef

begin_define
define|#
directive|define
name|LOG2_ID_PAGE_SIZE
value|28
end_define

begin_comment
comment|/* 256M */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|IA64_ID_PAGE_SHIFT
value|(LOG2_ID_PAGE_SIZE)
end_define

begin_define
define|#
directive|define
name|IA64_ID_PAGE_SIZE
value|(1<<(LOG2_ID_PAGE_SIZE))
end_define

begin_define
define|#
directive|define
name|IA64_ID_PAGE_MASK
value|(IA64_ID_PAGE_SIZE-1)
end_define

begin_define
define|#
directive|define
name|IA64_BACKINGSTORE
value|IA64_RR_BASE(4)
end_define

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
value|0
end_define

begin_define
define|#
directive|define
name|VM_MAX_ADDRESS
value|IA64_RR_BASE(5)
end_define

begin_define
define|#
directive|define
name|VM_GATEWAY_SIZE
value|PAGE_SIZE
end_define

begin_define
define|#
directive|define
name|VM_MAXUSER_ADDRESS
value|(VM_MAX_ADDRESS + VM_GATEWAY_SIZE)
end_define

begin_define
define|#
directive|define
name|VM_MIN_KERNEL_ADDRESS
value|VM_MAXUSER_ADDRESS
end_define

begin_define
define|#
directive|define
name|VM_MAX_KERNEL_ADDRESS
value|(IA64_RR_BASE(6) - 1)
end_define

begin_define
define|#
directive|define
name|KERNBASE
value|VM_MAX_ADDRESS
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
value|(4)
end_define

begin_comment
comment|/* XXX 8192 byte pages */
end_comment

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
comment|/* !_MACHINE_VMPARAM_H */
end_comment

end_unit

