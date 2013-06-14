begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  * arch-x86/xen.h  *   * Guest OS interface to x86 Xen.  *   * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to  * deal in the Software without restriction, including without limitation the  * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or  * sell copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER  * DEALINGS IN THE SOFTWARE.  *  * Copyright (c) 2004-2006, K A Fraser  */
end_comment

begin_include
include|#
directive|include
file|"../xen.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|__XEN_PUBLIC_ARCH_X86_XEN_H__
end_ifndef

begin_define
define|#
directive|define
name|__XEN_PUBLIC_ARCH_X86_XEN_H__
end_define

begin_comment
comment|/* Structural guest handles introduced in 0x00030201. */
end_comment

begin_if
if|#
directive|if
name|__XEN_INTERFACE_VERSION__
operator|>=
literal|0x00030201
end_if

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
value|typedef struct { type *p; } __guest_handle_ ## name
end_define

begin_else
else|#
directive|else
end_else

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
value|typedef type * __guest_handle_ ## name
end_define

begin_endif
endif|#
directive|endif
end_endif

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
name|__XEN_GUEST_HANDLE
parameter_list|(
name|name
parameter_list|)
value|__guest_handle_ ## name
end_define

begin_define
define|#
directive|define
name|XEN_GUEST_HANDLE
parameter_list|(
name|name
parameter_list|)
value|__XEN_GUEST_HANDLE(name)
end_define

begin_define
define|#
directive|define
name|set_xen_guest_handle_raw
parameter_list|(
name|hnd
parameter_list|,
name|val
parameter_list|)
value|do { (hnd).p = val; } while (0)
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

begin_define
define|#
directive|define
name|set_xen_guest_handle
parameter_list|(
name|hnd
parameter_list|,
name|val
parameter_list|)
value|set_xen_guest_handle_raw(hnd, val)
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__i386__
argument_list|)
end_if

begin_include
include|#
directive|include
file|"xen-x86_32.h"
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__x86_64__
argument_list|)
end_elif

begin_include
include|#
directive|include
file|"xen-x86_64.h"
end_include

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
name|xen_pfn_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PRI_xen_pfn
value|"lx"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * SEGMENT DESCRIPTOR TABLES  */
end_comment

begin_comment
comment|/*  * ` enum neg_errnoval  * ` HYPERVISOR_set_gdt(const xen_pfn_t frames[], unsigned int entries);  * `  */
end_comment

begin_comment
comment|/*  * A number of GDT entries are reserved by Xen. These are not situated at the  * start of the GDT because some stupid OSes export hard-coded selector values  * in their ABI. These hard-coded values are always near the start of the GDT,  * so Xen places itself out of the way, at the far end of the GDT.  */
end_comment

begin_define
define|#
directive|define
name|FIRST_RESERVED_GDT_PAGE
value|14
end_define

begin_define
define|#
directive|define
name|FIRST_RESERVED_GDT_BYTE
value|(FIRST_RESERVED_GDT_PAGE * 4096)
end_define

begin_define
define|#
directive|define
name|FIRST_RESERVED_GDT_ENTRY
value|(FIRST_RESERVED_GDT_BYTE / 8)
end_define

begin_comment
comment|/* Maximum number of virtual CPUs in legacy multi-processor guests. */
end_comment

begin_define
define|#
directive|define
name|XEN_LEGACY_MAX_VCPUS
value|32
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|__ASSEMBLY__
end_ifndef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|xen_ulong_t
typedef|;
end_typedef

begin_comment
comment|/*  * ` enum neg_errnoval  * ` HYPERVISOR_stack_switch(unsigned long ss, unsigned long esp);  * `  * Sets the stack segment and pointer for the current vcpu.  */
end_comment

begin_comment
comment|/*  * ` enum neg_errnoval  * ` HYPERVISOR_set_trap_table(const struct trap_info traps[]);  * `  */
end_comment

begin_comment
comment|/*  * Send an array of these to HYPERVISOR_set_trap_table().  * Terminate the array with a sentinel entry, with traps[].address==0.  * The privilege level specifies which modes may enter a trap via a software  * interrupt. On x86/64, since rings 1 and 2 are unavailable, we allocate  * privilege levels as follows:  *  Level == 0: Noone may enter  *  Level == 1: Kernel may enter  *  Level == 2: Kernel may enter  *  Level == 3: Everyone may enter  */
end_comment

begin_define
define|#
directive|define
name|TI_GET_DPL
parameter_list|(
name|_ti
parameter_list|)
value|((_ti)->flags& 3)
end_define

begin_define
define|#
directive|define
name|TI_GET_IF
parameter_list|(
name|_ti
parameter_list|)
value|((_ti)->flags& 4)
end_define

begin_define
define|#
directive|define
name|TI_SET_DPL
parameter_list|(
name|_ti
parameter_list|,
name|_dpl
parameter_list|)
value|((_ti)->flags |= (_dpl))
end_define

begin_define
define|#
directive|define
name|TI_SET_IF
parameter_list|(
name|_ti
parameter_list|,
name|_if
parameter_list|)
value|((_ti)->flags |= ((!!(_if))<<2))
end_define

begin_struct
struct|struct
name|trap_info
block|{
name|uint8_t
name|vector
decl_stmt|;
comment|/* exception vector                              */
name|uint8_t
name|flags
decl_stmt|;
comment|/* 0-3: privilege level; 4: clear event enable?  */
name|uint16_t
name|cs
decl_stmt|;
comment|/* code selector                                 */
name|unsigned
name|long
name|address
decl_stmt|;
comment|/* code offset                                   */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|trap_info
name|trap_info_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|trap_info_t
argument_list|)
expr_stmt|;
end_expr_stmt

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
comment|/*  * The following is all CPU context. Note that the fpu_ctxt block is filled   * in by FXSAVE if the CPU has feature FXSR; otherwise FSAVE is used.  */
end_comment

begin_struct
struct|struct
name|vcpu_guest_context
block|{
comment|/* FPU registers come first so they can be aligned for FXSAVE/FXRSTOR. */
struct|struct
block|{
name|char
name|x
index|[
literal|512
index|]
decl_stmt|;
block|}
name|fpu_ctxt
struct|;
comment|/* User-level FPU registers     */
define|#
directive|define
name|VGCF_I387_VALID
value|(1<<0)
define|#
directive|define
name|VGCF_IN_KERNEL
value|(1<<2)
define|#
directive|define
name|_VGCF_i387_valid
value|0
define|#
directive|define
name|VGCF_i387_valid
value|(1<<_VGCF_i387_valid)
define|#
directive|define
name|_VGCF_in_kernel
value|2
define|#
directive|define
name|VGCF_in_kernel
value|(1<<_VGCF_in_kernel)
define|#
directive|define
name|_VGCF_failsafe_disables_events
value|3
define|#
directive|define
name|VGCF_failsafe_disables_events
value|(1<<_VGCF_failsafe_disables_events)
define|#
directive|define
name|_VGCF_syscall_disables_events
value|4
define|#
directive|define
name|VGCF_syscall_disables_events
value|(1<<_VGCF_syscall_disables_events)
define|#
directive|define
name|_VGCF_online
value|5
define|#
directive|define
name|VGCF_online
value|(1<<_VGCF_online)
name|unsigned
name|long
name|flags
decl_stmt|;
comment|/* VGCF_* flags                 */
name|struct
name|cpu_user_regs
name|user_regs
decl_stmt|;
comment|/* User-level CPU registers     */
name|struct
name|trap_info
name|trap_ctxt
index|[
literal|256
index|]
decl_stmt|;
comment|/* Virtual IDT                  */
name|unsigned
name|long
name|ldt_base
decl_stmt|,
name|ldt_ents
decl_stmt|;
comment|/* LDT (linear address, # ents) */
name|unsigned
name|long
name|gdt_frames
index|[
literal|16
index|]
decl_stmt|,
name|gdt_ents
decl_stmt|;
comment|/* GDT (machine frames, # ents) */
name|unsigned
name|long
name|kernel_ss
decl_stmt|,
name|kernel_sp
decl_stmt|;
comment|/* Virtual TSS (only SS1/SP1)   */
comment|/* NB. User pagetable on x86/64 is placed in ctrlreg[1]. */
name|unsigned
name|long
name|ctrlreg
index|[
literal|8
index|]
decl_stmt|;
comment|/* CR0-CR7 (control registers)  */
name|unsigned
name|long
name|debugreg
index|[
literal|8
index|]
decl_stmt|;
comment|/* DB0-DB7 (debug registers)    */
ifdef|#
directive|ifdef
name|__i386__
name|unsigned
name|long
name|event_callback_cs
decl_stmt|;
comment|/* CS:EIP of event callback     */
name|unsigned
name|long
name|event_callback_eip
decl_stmt|;
name|unsigned
name|long
name|failsafe_callback_cs
decl_stmt|;
comment|/* CS:EIP of failsafe callback  */
name|unsigned
name|long
name|failsafe_callback_eip
decl_stmt|;
else|#
directive|else
name|unsigned
name|long
name|event_callback_eip
decl_stmt|;
name|unsigned
name|long
name|failsafe_callback_eip
decl_stmt|;
ifdef|#
directive|ifdef
name|__XEN__
union|union
block|{
name|unsigned
name|long
name|syscall_callback_eip
decl_stmt|;
struct|struct
block|{
name|unsigned
name|int
name|event_callback_cs
decl_stmt|;
comment|/* compat CS of event cb     */
name|unsigned
name|int
name|failsafe_callback_cs
decl_stmt|;
comment|/* compat CS of failsafe cb  */
block|}
struct|;
block|}
union|;
else|#
directive|else
name|unsigned
name|long
name|syscall_callback_eip
decl_stmt|;
endif|#
directive|endif
endif|#
directive|endif
name|unsigned
name|long
name|vm_assist
decl_stmt|;
comment|/* VMASST_TYPE_* bitmap */
ifdef|#
directive|ifdef
name|__x86_64__
comment|/* Segment base addresses. */
name|uint64_t
name|fs_base
decl_stmt|;
name|uint64_t
name|gs_base_kernel
decl_stmt|;
name|uint64_t
name|gs_base_user
decl_stmt|;
endif|#
directive|endif
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
name|unsigned
name|long
name|max_pfn
decl_stmt|;
comment|/* max pfn that appears in table */
comment|/* Frame containing list of mfns containing list of mfns containing p2m. */
name|xen_pfn_t
name|pfn_to_mfn_frame_list_list
decl_stmt|;
name|unsigned
name|long
name|nmi_reason
decl_stmt|;
name|uint64_t
name|pad
index|[
literal|32
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|arch_shared_info
name|arch_shared_info_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !__ASSEMBLY__ */
end_comment

begin_comment
comment|/*  * ` enum neg_errnoval  * ` HYPERVISOR_fpu_taskswitch(int set);  * `  * Sets (if set!=0) or clears (if set==0) CR0.TS.  */
end_comment

begin_comment
comment|/*  * ` enum neg_errnoval  * ` HYPERVISOR_set_debugreg(int regno, unsigned long value);  *  * ` unsigned long  * ` HYPERVISOR_get_debugreg(int regno);  * For 0<=reg<=7, returns the debug register value.  * For other values of reg, returns ((unsigned long)-EINVAL).  * (Unfortunately, this interface is defective.)  */
end_comment

begin_comment
comment|/*  * Prefix forces emulation of some non-trapping instructions.  * Currently only CPUID.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__ASSEMBLY__
end_ifdef

begin_define
define|#
directive|define
name|XEN_EMULATE_PREFIX
value|.byte 0x0f,0x0b,0x78,0x65,0x6e ;
end_define

begin_define
define|#
directive|define
name|XEN_CPUID
value|XEN_EMULATE_PREFIX cpuid
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XEN_EMULATE_PREFIX
value|".byte 0x0f,0x0b,0x78,0x65,0x6e ; "
end_define

begin_define
define|#
directive|define
name|XEN_CPUID
value|XEN_EMULATE_PREFIX "cpuid"
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
comment|/* __XEN_PUBLIC_ARCH_X86_XEN_H__ */
end_comment

begin_comment
comment|/*  * Local variables:  * mode: C  * c-set-style: "BSD"  * c-basic-offset: 4  * tab-width: 4  * indent-tabs-mode: nil  * End:  */
end_comment

end_unit

