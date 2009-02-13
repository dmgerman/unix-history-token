begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to  * deal in the Software without restriction, including without limitation the  * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or  * sell copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER  * DEALINGS IN THE SOFTWARE.  *  * Copyright (C) IBM Corp. 2005, 2006  *  * Authors: Hollis Blanchard<hollisb@us.ibm.com>  */
end_comment

begin_include
include|#
directive|include
file|"xen.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|__XEN_PUBLIC_ARCH_PPC_64_H__
end_ifndef

begin_define
define|#
directive|define
name|__XEN_PUBLIC_ARCH_PPC_64_H__
end_define

begin_define
define|#
directive|define
name|___DEFINE_XEN_GUEST_HANDLE
parameter_list|(
name|name
parameter_list|,
name|type
parameter_list|)
define|\
value|typedef struct { \         int __pad[(sizeof (long long) - sizeof (void *)) / sizeof (int)]; \         type *p; \     } __attribute__((__aligned__(8))) __guest_handle_ ## name
end_define

begin_define
define|#
directive|define
name|__DEFINE_XEN_GUEST_HANDLE
parameter_list|(
name|name
parameter_list|,
name|type
parameter_list|)
define|\
value|___DEFINE_XEN_GUEST_HANDLE(name, type);   \     ___DEFINE_XEN_GUEST_HANDLE(const_##name, const type)
end_define

begin_define
define|#
directive|define
name|DEFINE_XEN_GUEST_HANDLE
parameter_list|(
name|name
parameter_list|)
value|__DEFINE_XEN_GUEST_HANDLE(name, name)
end_define

begin_define
define|#
directive|define
name|XEN_GUEST_HANDLE
parameter_list|(
name|name
parameter_list|)
value|__guest_handle_ ## name
end_define

begin_define
define|#
directive|define
name|set_xen_guest_handle
parameter_list|(
name|hnd
parameter_list|,
name|val
parameter_list|)
define|\
value|do { \         if (sizeof ((hnd).__pad)) \             (hnd).__pad[0] = 0; \         (hnd).p = val; \     } while (0)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__XEN_TOOLS__
end_ifdef

begin_define
define|#
directive|define
name|get_xen_guest_handle
parameter_list|(
name|val
parameter_list|,
name|hnd
parameter_list|)
value|do { val = (hnd).p; } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__ASSEMBLY__
end_ifndef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|long
name|xen_pfn_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PRI_xen_pfn
value|"llx"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Pointers and other address fields inside interface structures are padded to  * 64 bits. This means that field alignments aren't different between 32- and  * 64-bit architectures.   */
end_comment

begin_comment
comment|/* NB. Multi-level macro ensures __LINE__ is expanded before concatenation. */
end_comment

begin_define
define|#
directive|define
name|__MEMORY_PADDING
parameter_list|(
name|_X
parameter_list|)
end_define

begin_define
define|#
directive|define
name|_MEMORY_PADDING
parameter_list|(
name|_X
parameter_list|)
value|__MEMORY_PADDING(_X)
end_define

begin_define
define|#
directive|define
name|MEMORY_PADDING
value|_MEMORY_PADDING(__LINE__)
end_define

begin_comment
comment|/* And the trap vector is... */
end_comment

begin_define
define|#
directive|define
name|TRAP_INSTR
value|"li 0,-1; sc"
end_define

begin_comment
comment|/* XXX just "sc"? */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ASSEMBLY__
end_ifndef

begin_define
define|#
directive|define
name|XENCOMM_INLINE_FLAG
value|(1UL<< 63)
end_define

begin_typedef
typedef|typedef
name|uint64_t
name|xen_ulong_t
typedef|;
end_typedef

begin_comment
comment|/* User-accessible registers: nost of these need to be saved/restored  * for every nested Xen invocation. */
end_comment

begin_struct
struct|struct
name|cpu_user_regs
block|{
name|uint64_t
name|gprs
index|[
literal|32
index|]
decl_stmt|;
name|uint64_t
name|lr
decl_stmt|;
name|uint64_t
name|ctr
decl_stmt|;
name|uint64_t
name|srr0
decl_stmt|;
name|uint64_t
name|srr1
decl_stmt|;
name|uint64_t
name|pc
decl_stmt|;
name|uint64_t
name|msr
decl_stmt|;
name|uint64_t
name|fpscr
decl_stmt|;
comment|/* XXX Is this necessary */
name|uint64_t
name|xer
decl_stmt|;
name|uint64_t
name|hid4
decl_stmt|;
comment|/* debug only */
name|uint64_t
name|dar
decl_stmt|;
comment|/* debug only */
name|uint32_t
name|dsisr
decl_stmt|;
comment|/* debug only */
name|uint32_t
name|cr
decl_stmt|;
name|uint32_t
name|__pad
decl_stmt|;
comment|/* good spot for another 32bit reg */
name|uint32_t
name|entry_vector
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|cpu_user_regs
name|cpu_user_regs_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint64_t
name|tsc_timestamp_t
typedef|;
end_typedef

begin_comment
comment|/* RDTSC timestamp */
end_comment

begin_comment
comment|/* XXX timebase */
end_comment

begin_comment
comment|/* ONLY used to communicate with dom0! See also struct exec_domain. */
end_comment

begin_struct
struct|struct
name|vcpu_guest_context
block|{
name|cpu_user_regs_t
name|user_regs
decl_stmt|;
comment|/* User-level CPU registers     */
name|uint64_t
name|sdr1
decl_stmt|;
comment|/* Pagetable base               */
comment|/* XXX etc */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|vcpu_guest_context
name|vcpu_guest_context_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|vcpu_guest_context_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|arch_shared_info
block|{
name|uint64_t
name|boot_timebase
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|arch_vcpu_info
block|{ }
struct|;
end_struct

begin_comment
comment|/* Support for multi-processor guests. */
end_comment

begin_define
define|#
directive|define
name|MAX_VIRT_CPUS
value|32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

