begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* From: NetBSD: param.h,v 1.20 1997/09/19 13:52:53 leo Exp */
end_comment

begin_comment
comment|/*  * Copyright (c) 1988 University of Utah.  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department and Ralph Campbell.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * from: Utah $Hdr: machparam.h 1.11 89/08/14$  *  *	@(#)param.h	8.1 (Berkeley) 6/10/93  */
end_comment

begin_comment
comment|/*  * Machine dependent constants for the Alpha.  */
end_comment

begin_comment
comment|/*  * Round p (pointer or byte index) up to a correctly-aligned value for all  * data types (int, long, ...).   The result is u_long and must be cast to  * any desired pointer type.  *  * ALIGNED_POINTER is a boolean macro that checks whether an address  * is valid to fetch data elements of type t from on this architecture.  * This does not reflect the optimal alignment, just the possibility  * (within reasonable limits).   *  */
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
value|7
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
value|(((u_long)(p) + _ALIGNBYTES)&~ _ALIGNBYTES)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_ALIGNED_POINTER
end_ifndef

begin_define
define|#
directive|define
name|_ALIGNED_POINTER
parameter_list|(
name|p
parameter_list|,
name|t
parameter_list|)
value|((((u_long)(p))& (sizeof(t)-1)) == 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE
value|alpha
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_ARCH
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_ARCH
value|alpha
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
value|"alpha"
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
value|"alpha"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MID_MACHINE
value|MID_ALPHA
end_define

begin_include
include|#
directive|include
file|<machine/alpha_cpu.h>
end_include

begin_include
include|#
directive|include
file|<machine/cpu.h>
end_include

begin_define
define|#
directive|define
name|MAXSMPCPU
value|8
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
value|MAXSMPCPU
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
name|ALIGNED_POINTER
parameter_list|(
name|p
parameter_list|,
name|t
parameter_list|)
value|_ALIGNED_POINTER(p,t)
end_define

begin_define
define|#
directive|define
name|PAGE_SIZE
value|(1<< ALPHA_PGSHIFT)
end_define

begin_comment
comment|/* bytes/page */
end_comment

begin_define
define|#
directive|define
name|PAGE_SHIFT
value|ALPHA_PGSHIFT
end_define

begin_define
define|#
directive|define
name|PAGE_MASK
value|(PAGE_SIZE-1)
end_define

begin_define
define|#
directive|define
name|NPTEPG
value|(PAGE_SIZE/(sizeof (pt_entry_t)))
end_define

begin_define
define|#
directive|define
name|KERNBASE
value|0xfffffc0000300000LL
end_define

begin_comment
comment|/* start of kernel virtual */
end_comment

begin_define
define|#
directive|define
name|BTOPKERNBASE
value|((u_long)KERNBASE>> PGSHIFT)
end_define

begin_define
define|#
directive|define
name|CLSIZE
value|1
end_define

begin_define
define|#
directive|define
name|CLSIZELOG2
value|0
end_define

begin_comment
comment|/* NOTE: SSIZE, SINCR and UPAGES must be multiples of CLSIZE */
end_comment

begin_define
define|#
directive|define
name|SSIZE
value|1
end_define

begin_comment
comment|/* initial stack size/NBPG */
end_comment

begin_define
define|#
directive|define
name|SINCR
value|1
end_define

begin_comment
comment|/* increment of stack/NBPG */
end_comment

begin_define
define|#
directive|define
name|PREEMPTION
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
value|2
end_define

begin_comment
comment|/* pages of kstack (with pcb) */
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
name|UAREA_PAGES
value|1
end_define

begin_comment
comment|/* pages of u-area */
end_comment

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
value|((((unsigned long)(x)) + PAGE_MASK)& ~(PAGE_MASK))
end_define

begin_define
define|#
directive|define
name|trunc_page
parameter_list|(
name|x
parameter_list|)
value|((unsigned long)(x)& ~(PAGE_MASK))
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
name|alpha_btop
parameter_list|(
name|x
parameter_list|)
value|((unsigned long)(x)>> PAGE_SHIFT)
end_define

begin_define
define|#
directive|define
name|alpha_ptob
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
value|((x) * (PAGE_SIZE / 1024))
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

