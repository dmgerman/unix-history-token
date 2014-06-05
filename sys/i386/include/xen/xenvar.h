begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2008 Kip Macy  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|XENVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|XENVAR_H_
end_define

begin_include
include|#
directive|include
file|<machine/xen/features.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|XEN
argument_list|)
end_if

begin_define
define|#
directive|define
name|XBOOTUP
value|0x1
end_define

begin_define
define|#
directive|define
name|XPMAP
value|0x2
end_define

begin_decl_stmt
specifier|extern
name|int
name|xendebug_flags
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|NOXENDEBUG
end_ifndef

begin_define
define|#
directive|define
name|XENPRINTF
value|printk
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XENPRINTF
value|printf
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|xen_pfn_t
modifier|*
name|xen_phys_machine
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|xen_pfn_t
modifier|*
name|xen_pfn_to_mfn_frame_list
index|[
literal|16
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|xen_pfn_t
modifier|*
name|xen_pfn_to_mfn_frame_list_list
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|TRACE_ENTER
value|XENPRINTF("(file=%s, line=%d) entered %s\n", __FILE__, __LINE__, __FUNCTION__)
end_define

begin_define
define|#
directive|define
name|TRACE_EXIT
value|XENPRINTF("(file=%s, line=%d) exiting %s\n", __FILE__, __LINE__, __FUNCTION__)
end_define

begin_define
define|#
directive|define
name|TRACE_DEBUG
parameter_list|(
name|argflags
parameter_list|,
name|_f
parameter_list|,
name|_a
modifier|...
parameter_list|)
define|\
value|if (xendebug_flags& argflags) XENPRINTF("(file=%s, line=%d) " _f "\n", __FILE__, __LINE__, ## _a);
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TRACE_ENTER
end_define

begin_define
define|#
directive|define
name|TRACE_EXIT
end_define

begin_define
define|#
directive|define
name|TRACE_DEBUG
parameter_list|(
name|argflags
parameter_list|,
name|_f
parameter_list|,
name|_a
modifier|...
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|xen_pfn_t
modifier|*
name|xen_machine_phys
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Xen starts physical pages after the 4MB ISA hole -  * FreeBSD doesn't  */
end_comment

begin_undef
undef|#
directive|undef
name|ADD_ISA_HOLE
end_undef

begin_comment
comment|/* XXX */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ADD_ISA_HOLE
end_ifdef

begin_define
define|#
directive|define
name|ISA_INDEX_OFFSET
value|1024
end_define

begin_define
define|#
directive|define
name|ISA_PDR_OFFSET
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ISA_INDEX_OFFSET
value|0
end_define

begin_define
define|#
directive|define
name|ISA_PDR_OFFSET
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PFNTOMFN
parameter_list|(
name|i
parameter_list|)
value|(xen_phys_machine[(i)])
end_define

begin_define
define|#
directive|define
name|MFNTOPFN
parameter_list|(
name|i
parameter_list|)
value|((vm_paddr_t)xen_machine_phys[(i)])
end_define

begin_define
define|#
directive|define
name|VTOP
parameter_list|(
name|x
parameter_list|)
value|((((uintptr_t)(x))) - KERNBASE)
end_define

begin_define
define|#
directive|define
name|PTOV
parameter_list|(
name|x
parameter_list|)
value|(((uintptr_t)(x)) + KERNBASE)
end_define

begin_define
define|#
directive|define
name|VTOPFN
parameter_list|(
name|x
parameter_list|)
value|(VTOP(x)>> PAGE_SHIFT)
end_define

begin_define
define|#
directive|define
name|PFNTOV
parameter_list|(
name|x
parameter_list|)
value|PTOV((vm_paddr_t)(x)<< PAGE_SHIFT)
end_define

begin_define
define|#
directive|define
name|VTOMFN
parameter_list|(
name|va
parameter_list|)
value|(vtomach(va)>> PAGE_SHIFT)
end_define

begin_define
define|#
directive|define
name|PFN_UP
parameter_list|(
name|x
parameter_list|)
value|(((x) + PAGE_SIZE-1)>> PAGE_SHIFT)
end_define

begin_define
define|#
directive|define
name|phystomach
parameter_list|(
name|pa
parameter_list|)
value|(((vm_paddr_t)(PFNTOMFN((pa)>> PAGE_SHIFT)))<< PAGE_SHIFT)
end_define

begin_define
define|#
directive|define
name|machtophys
parameter_list|(
name|ma
parameter_list|)
value|(((vm_paddr_t)(MFNTOPFN((ma)>> PAGE_SHIFT)))<< PAGE_SHIFT)
end_define

begin_function_decl
name|void
name|xpq_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|BITS_PER_LONG
value|32
end_define

begin_define
define|#
directive|define
name|NR_CPUS
value|MAX_VIRT_CPUS
end_define

begin_define
define|#
directive|define
name|BITS_TO_LONGS
parameter_list|(
name|bits
parameter_list|)
define|\
value|(((bits)+BITS_PER_LONG-1)/BITS_PER_LONG)
end_define

begin_define
define|#
directive|define
name|DECLARE_BITMAP
parameter_list|(
name|name
parameter_list|,
name|bits
parameter_list|)
define|\
value|unsigned long name[BITS_TO_LONGS(bits)]
end_define

begin_function_decl
name|int
name|xen_create_contiguous_region
parameter_list|(
name|vm_page_t
name|pages
parameter_list|,
name|int
name|npages
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xen_destroy_contiguous_region
parameter_list|(
name|void
modifier|*
name|addr
parameter_list|,
name|int
name|npages
parameter_list|)
function_decl|;
end_function_decl

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|XENHVM
argument_list|)
end_elif

begin_define
define|#
directive|define
name|vtomach
parameter_list|(
name|va
parameter_list|)
value|pmap_kextract((vm_offset_t) (va))
end_define

begin_define
define|#
directive|define
name|PFNTOMFN
parameter_list|(
name|pa
parameter_list|)
value|(pa)
end_define

begin_define
define|#
directive|define
name|MFNTOPFN
parameter_list|(
name|ma
parameter_list|)
value|(ma)
end_define

begin_define
define|#
directive|define
name|set_phys_to_machine
parameter_list|(
name|pfn
parameter_list|,
name|mfn
parameter_list|)
value|((void)0)
end_define

begin_define
define|#
directive|define
name|phys_to_machine_mapping_valid
parameter_list|(
name|pfn
parameter_list|)
value|(TRUE)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !XEN&& !XENHVM */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

