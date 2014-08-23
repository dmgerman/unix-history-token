begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 David E. O'Brien  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * William Jolitz.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)param.h	5.8 (Berkeley) 6/28/91  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ARM_INCLUDE_PARAM_H_
end_ifndef

begin_define
define|#
directive|define
name|_ARM_INCLUDE_PARAM_H_
end_define

begin_comment
comment|/*  * Machine dependent constants for StrongARM  */
end_comment

begin_include
include|#
directive|include
file|<machine/_align.h>
end_include

begin_include
include|#
directive|include
file|<machine/acle-compat.h>
end_include

begin_define
define|#
directive|define
name|STACKALIGNBYTES
value|(8 - 1)
end_define

begin_define
define|#
directive|define
name|STACKALIGN
parameter_list|(
name|p
parameter_list|)
value|((u_int)(p)& ~STACKALIGNBYTES)
end_define

begin_define
define|#
directive|define
name|__PCI_REROUTE_INTERRUPT
end_define

begin_if
if|#
directive|if
name|__ARM_ARCH
operator|>=
literal|6
end_if

begin_define
define|#
directive|define
name|_V6_SUFFIX
value|"v6"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_V6_SUFFIX
value|""
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__ARM_PCS_VFP
end_ifdef

begin_define
define|#
directive|define
name|_HF_SUFFIX
value|"hf"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_HF_SUFFIX
value|""
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__ARM_BIG_ENDIAN
end_ifdef

begin_define
define|#
directive|define
name|_EB_SUFFIX
value|"eb"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_EB_SUFFIX
value|""
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MACHINE
end_ifndef

begin_define
define|#
directive|define
name|MACHINE
value|"arm"
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
value|"arm" _V6_SUFFIX _HF_SUFFIX _EB_SUFFIX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SMP
argument_list|)
operator|||
name|defined
argument_list|(
name|KLD_MODULE
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|MAXCPU
end_ifndef

begin_define
define|#
directive|define
name|MAXCPU
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

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
comment|/* SMP || KLD_MODULE */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MAXMEMDOM
end_ifndef

begin_define
define|#
directive|define
name|MAXMEMDOM
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

begin_comment
comment|/*  * ALIGNED_POINTER is a boolean macro that checks whether an address  * is valid to fetch data elements of type t from on this architecture.  * This does not reflect the optimal alignment, just the possibility  * (within reasonable limits).  */
end_comment

begin_define
define|#
directive|define
name|ALIGNED_POINTER
parameter_list|(
name|p
parameter_list|,
name|t
parameter_list|)
value|((((unsigned)(p))& (sizeof(t)-1)) == 0)
end_define

begin_comment
comment|/*  * CACHE_LINE_SIZE is the compile-time maximum cache line size for an  * architecture.  It should be used with appropriate caution.  */
end_comment

begin_define
define|#
directive|define
name|CACHE_LINE_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|CACHE_LINE_SIZE
value|(1<< CACHE_LINE_SHIFT)
end_define

begin_define
define|#
directive|define
name|PAGE_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|PAGE_SIZE
value|(1<< PAGE_SHIFT)
end_define

begin_comment
comment|/* Page size */
end_comment

begin_define
define|#
directive|define
name|PAGE_MASK
value|(PAGE_SIZE - 1)
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
name|PDR_SHIFT
value|20
end_define

begin_comment
comment|/* log2(NBPDR) */
end_comment

begin_define
define|#
directive|define
name|NBPDR
value|(1<< PDR_SHIFT)
end_define

begin_define
define|#
directive|define
name|PDRMASK
value|(NBPDR - 1)
end_define

begin_define
define|#
directive|define
name|NPDEPG
value|(1<< (32 - PDR_SHIFT))
end_define

begin_define
define|#
directive|define
name|MAXPAGESIZES
value|2
end_define

begin_comment
comment|/* maximum number of supported page sizes */
end_comment

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !KSTACK_PAGES */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FPCONTEXTSIZE
end_ifndef

begin_define
define|#
directive|define
name|FPCONTEXTSIZE
value|(0x100)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|KSTACK_GUARD_PAGES
end_ifndef

begin_define
define|#
directive|define
name|KSTACK_GUARD_PAGES
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !KSTACK_GUARD_PAGES */
end_comment

begin_define
define|#
directive|define
name|USPACE_SVC_STACK_TOP
value|(KSTACK_PAGES * PAGE_SIZE)
end_define

begin_comment
comment|/*  * Mach derived conversion macros  */
end_comment

begin_define
define|#
directive|define
name|trunc_page
parameter_list|(
name|x
parameter_list|)
value|((x)& ~PAGE_MASK)
end_define

begin_define
define|#
directive|define
name|round_page
parameter_list|(
name|x
parameter_list|)
value|(((x) + PAGE_MASK)& ~PAGE_MASK)
end_define

begin_define
define|#
directive|define
name|trunc_1mpage
parameter_list|(
name|x
parameter_list|)
value|((unsigned)(x)& ~PDRMASK)
end_define

begin_define
define|#
directive|define
name|round_1mpage
parameter_list|(
name|x
parameter_list|)
value|((((unsigned)(x)) + PDRMASK)& ~PDRMASK)
end_define

begin_define
define|#
directive|define
name|atop
parameter_list|(
name|x
parameter_list|)
value|((unsigned)(x)>> PAGE_SHIFT)
end_define

begin_define
define|#
directive|define
name|ptoa
parameter_list|(
name|x
parameter_list|)
value|((unsigned)(x)<< PAGE_SHIFT)
end_define

begin_define
define|#
directive|define
name|arm32_btop
parameter_list|(
name|x
parameter_list|)
value|((unsigned)(x)>> PAGE_SHIFT)
end_define

begin_define
define|#
directive|define
name|arm32_ptob
parameter_list|(
name|x
parameter_list|)
value|((unsigned)(x)<< PAGE_SHIFT)
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
comment|/* !_ARM_INCLUDE_PARAM_H_ */
end_comment

end_unit

