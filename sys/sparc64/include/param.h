begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * William Jolitz.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)param.h	5.8 (Berkeley) 6/28/91  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Machine dependent constants for sparc64.  */
end_comment

begin_comment
comment|/*  * Round p (pointer or byte index) up to a correctly-aligned value  * for all data types (int, long, ...).   The result is unsigned int  * and must be cast to any desired pointer type.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ALIGNBYTES
end_ifndef

begin_define
define|#
directive|define
name|_ALIGNBYTES
value|0xf
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_ALIGN
end_ifndef

begin_define
define|#
directive|define
name|_ALIGN
parameter_list|(
name|p
parameter_list|)
value|(((u_long)(p) + _ALIGNBYTES)& ~_ALIGNBYTES)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_NO_NAMESPACE_POLLUTION
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_PARAM_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_PARAM_H_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|MACHINE
end_ifndef

begin_define
define|#
directive|define
name|MACHINE
value|"sparc64"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MACHINE_ARCH
end_ifndef

begin_define
define|#
directive|define
name|MACHINE_ARCH
value|"sparc64"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MID_MACHINE
value|MID_SPARC64
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|SMP
end_ifdef

begin_define
define|#
directive|define
name|MAXCPU
value|16
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MAXCPU
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SMP */
end_comment

begin_define
define|#
directive|define
name|INT_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|PTR_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|ALIGNBYTES
value|_ALIGNBYTES
end_define

begin_define
define|#
directive|define
name|ALIGN
parameter_list|(
name|p
parameter_list|)
value|_ALIGN(p)
end_define

begin_define
define|#
directive|define
name|PAGE_SHIFT_8K
value|13
end_define

begin_define
define|#
directive|define
name|PAGE_SIZE_8K
value|(1L<<PAGE_SHIFT_8K)
end_define

begin_define
define|#
directive|define
name|PAGE_MASK_8K
value|(PAGE_SIZE_8K-1)
end_define

begin_define
define|#
directive|define
name|PAGE_SHIFT_64K
value|16
end_define

begin_define
define|#
directive|define
name|PAGE_SIZE_64K
value|(1L<<PAGE_SHIFT_64K)
end_define

begin_define
define|#
directive|define
name|PAGE_MASK_64K
value|(PAGE_SIZE_64K-1)
end_define

begin_define
define|#
directive|define
name|PAGE_SHIFT_512K
value|19
end_define

begin_define
define|#
directive|define
name|PAGE_SIZE_512K
value|(1L<<PAGE_SHIFT_512K)
end_define

begin_define
define|#
directive|define
name|PAGE_MASK_512K
value|(PAGE_SIZE_512K-1)
end_define

begin_define
define|#
directive|define
name|PAGE_SHIFT_4M
value|22
end_define

begin_define
define|#
directive|define
name|PAGE_SIZE_4M
value|(1L<<PAGE_SHIFT_4M)
end_define

begin_define
define|#
directive|define
name|PAGE_MASK_4M
value|(PAGE_SIZE_4M-1)
end_define

begin_define
define|#
directive|define
name|PAGE_SHIFT_32M
value|25
end_define

begin_define
define|#
directive|define
name|PAGE_SIZE_32M
value|(1L<<PAGE_SHIFT_32M)
end_define

begin_define
define|#
directive|define
name|PAGE_MASK_32M
value|(PAGE_SIZE_32M-1)
end_define

begin_define
define|#
directive|define
name|PAGE_SHIFT_256M
value|28
end_define

begin_define
define|#
directive|define
name|PAGE_SIZE_256M
value|(1L<<PAGE_SHIFT_256M)
end_define

begin_define
define|#
directive|define
name|PAGE_MASK_256M
value|(PAGE_SIZE_256M-1)
end_define

begin_define
define|#
directive|define
name|PAGE_SHIFT_MIN
value|PAGE_SHIFT_8K
end_define

begin_define
define|#
directive|define
name|PAGE_SIZE_MIN
value|PAGE_SIZE_8K
end_define

begin_define
define|#
directive|define
name|PAGE_MASK_MIN
value|PAGE_MASK_8K
end_define

begin_define
define|#
directive|define
name|PAGE_SHIFT
value|PAGE_SHIFT_8K
end_define

begin_comment
comment|/* LOG2(PAGE_SIZE) */
end_comment

begin_define
define|#
directive|define
name|PAGE_SIZE
value|PAGE_SIZE_8K
end_define

begin_comment
comment|/* bytes/page */
end_comment

begin_define
define|#
directive|define
name|PAGE_MASK
value|PAGE_MASK_8K
end_define

begin_define
define|#
directive|define
name|PAGE_SHIFT_MAX
value|PAGE_SHIFT_4M
end_define

begin_define
define|#
directive|define
name|PAGE_SIZE_MAX
value|PAGE_SIZE_4M
end_define

begin_define
define|#
directive|define
name|PAGE_MASK_MAX
value|PAGE_MASK_4M
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|KSTACK_PAGES
end_ifndef

begin_define
define|#
directive|define
name|KSTACK_PAGES
value|4
end_define

begin_comment
comment|/* pages of kernel stack (with pcb) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|KSTACK_GUARD_PAGES
value|1
end_define

begin_comment
comment|/* pages of kstack guard; 0 disables */
end_comment

begin_define
define|#
directive|define
name|PCPU_PAGES
value|1
end_define

begin_comment
comment|/*  * Ceiling on size of buffer cache (really only effects write queueing,  * the VM page cache is not effected), can be changed via  * the kern.maxbcache /boot/loader.conf variable.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VM_BCACHE_SIZE_MAX
end_ifndef

begin_define
define|#
directive|define
name|VM_BCACHE_SIZE_MAX
value|(400 * 1024 * 1024)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Mach derived conversion macros  */
end_comment

begin_define
define|#
directive|define
name|round_page
parameter_list|(
name|x
parameter_list|)
value|(((unsigned long)(x) + PAGE_MASK)& ~PAGE_MASK)
end_define

begin_define
define|#
directive|define
name|trunc_page
parameter_list|(
name|x
parameter_list|)
value|((unsigned long)(x)& ~PAGE_MASK)
end_define

begin_define
define|#
directive|define
name|atop
parameter_list|(
name|x
parameter_list|)
value|((unsigned long)(x)>> PAGE_SHIFT)
end_define

begin_define
define|#
directive|define
name|ptoa
parameter_list|(
name|x
parameter_list|)
value|((unsigned long)(x)<< PAGE_SHIFT)
end_define

begin_define
define|#
directive|define
name|sparc64_btop
parameter_list|(
name|x
parameter_list|)
value|((unsigned long)(x)>> PAGE_SHIFT)
end_define

begin_define
define|#
directive|define
name|sparc64_ptob
parameter_list|(
name|x
parameter_list|)
value|((unsigned long)(x)<< PAGE_SHIFT)
end_define

begin_define
define|#
directive|define
name|pgtok
parameter_list|(
name|x
parameter_list|)
value|((unsigned long)(x) * (PAGE_SIZE / 1024))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_PARAM_H_ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_NO_NAMESPACE_POLLUTION */
end_comment

end_unit

