begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * William Jolitz.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)param.h	5.8 (Berkeley) 6/28/91  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Machine dependent constants for Intel 386.  */
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
value|(sizeof(int) - 1)
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
value|(((unsigned)(p) + _ALIGNBYTES)& ~_ALIGNBYTES)
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

begin_define
define|#
directive|define
name|__HAVE_ACPI
end_define

begin_define
define|#
directive|define
name|__PCI_REROUTE_INTERRUPT
end_define

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
value|"i386"
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
value|"i386"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MID_MACHINE
value|MID_I386
end_define

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
comment|/*  * ALIGNED_POINTER is a boolean macro that checks whether an address  * is valid to fetch data elements of type t from on this architecture.  * This does not reflect the optimal alignment, just the possibility  * (within reasonable limits).   */
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
value|1
end_define

begin_define
define|#
directive|define
name|PAGE_SHIFT
value|12
end_define

begin_comment
comment|/* LOG2(PAGE_SIZE) */
end_comment

begin_define
define|#
directive|define
name|PAGE_SIZE
value|(1<<PAGE_SHIFT)
end_define

begin_comment
comment|/* bytes/page */
end_comment

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

begin_ifdef
ifdef|#
directive|ifdef
name|PAE
end_ifdef

begin_define
define|#
directive|define
name|NPGPTD
value|4
end_define

begin_define
define|#
directive|define
name|PDRSHIFT
value|21
end_define

begin_comment
comment|/* LOG2(NBPDR) */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NPGPTD
value|1
end_define

begin_define
define|#
directive|define
name|PDRSHIFT
value|22
end_define

begin_comment
comment|/* LOG2(NBPDR) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|NBPTD
value|(NPGPTD<<PAGE_SHIFT)
end_define

begin_define
define|#
directive|define
name|NPDEPTD
value|(NBPTD/(sizeof (pd_entry_t)))
end_define

begin_define
define|#
directive|define
name|NPDEPG
value|(PAGE_SIZE/(sizeof (pd_entry_t)))
end_define

begin_define
define|#
directive|define
name|NBPDR
value|(1<<PDRSHIFT)
end_define

begin_comment
comment|/* bytes/page dir */
end_comment

begin_define
define|#
directive|define
name|PDRMASK
value|(NBPDR-1)
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

begin_define
define|#
directive|define
name|IOPAGES
value|2
end_define

begin_comment
comment|/* pages of i/o permission bitmap */
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

begin_comment
comment|/* Includes pcb! */
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

begin_comment
comment|/*  * Ceiling on amount of swblock kva space, can be changed via  * the kern.maxswzone /boot/loader.conf variable.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VM_SWZONE_SIZE_MAX
end_ifndef

begin_define
define|#
directive|define
name|VM_SWZONE_SIZE_MAX
value|(32 * 1024 * 1024)
end_define

begin_endif
endif|#
directive|endif
end_endif

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
value|(200 * 1024 * 1024)
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
name|trunc_4mpage
parameter_list|(
name|x
parameter_list|)
value|((x)& ~PDRMASK)
end_define

begin_define
define|#
directive|define
name|round_4mpage
parameter_list|(
name|x
parameter_list|)
value|((((x)) + PDRMASK)& ~PDRMASK)
end_define

begin_define
define|#
directive|define
name|atop
parameter_list|(
name|x
parameter_list|)
value|((x)>> PAGE_SHIFT)
end_define

begin_define
define|#
directive|define
name|ptoa
parameter_list|(
name|x
parameter_list|)
value|((x)<< PAGE_SHIFT)
end_define

begin_define
define|#
directive|define
name|i386_btop
parameter_list|(
name|x
parameter_list|)
value|((x)>> PAGE_SHIFT)
end_define

begin_define
define|#
directive|define
name|i386_ptob
parameter_list|(
name|x
parameter_list|)
value|((x)<< PAGE_SHIFT)
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

