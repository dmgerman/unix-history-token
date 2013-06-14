begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  * arch-arm.h  *  * Guest OS interface to ARM Xen.  *  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to  * deal in the Software without restriction, including without limitation the  * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or  * sell copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER  * DEALINGS IN THE SOFTWARE.  *  * Copyright 2011 (C) Citrix Systems  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XEN_PUBLIC_ARCH_ARM_H__
end_ifndef

begin_define
define|#
directive|define
name|__XEN_PUBLIC_ARCH_ARM_H__
end_define

begin_comment
comment|/* hypercall calling convention  * ----------------------------  *  * A hypercall is issued using the ARM HVC instruction.  *  * A hypercall can take up to 5 arguments. These are passed in  * registers, the first argument in r0, the second argument in r1, the  * third in r2, the forth in r3 and the fifth in r4.  *  * The hypercall number is passed in r12.  *  * The HVC ISS must contain a Xen specific TAG: XEN_HYPERCALL_TAG.  *  * The return value is in r0.  *  * The hypercall will clobber r12 and the argument registers used by  * that hypercall (except r0 which is the return value) i.e. a 2  * argument hypercall will clobber r1 and a 4 argument hypercall will  * clobber r1, r2 and r3.  *  */
end_comment

begin_define
define|#
directive|define
name|XEN_HYPERCALL_TAG
value|0XEA1
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|__ASSEMBLY__
end_ifndef

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

begin_struct
struct|struct
name|cpu_user_regs
block|{
name|uint32_t
name|r0
decl_stmt|;
name|uint32_t
name|r1
decl_stmt|;
name|uint32_t
name|r2
decl_stmt|;
name|uint32_t
name|r3
decl_stmt|;
name|uint32_t
name|r4
decl_stmt|;
name|uint32_t
name|r5
decl_stmt|;
name|uint32_t
name|r6
decl_stmt|;
name|uint32_t
name|r7
decl_stmt|;
name|uint32_t
name|r8
decl_stmt|;
name|uint32_t
name|r9
decl_stmt|;
name|uint32_t
name|r10
decl_stmt|;
union|union
block|{
name|uint32_t
name|r11
decl_stmt|;
name|uint32_t
name|fp
decl_stmt|;
block|}
union|;
name|uint32_t
name|r12
decl_stmt|;
name|uint32_t
name|sp
decl_stmt|;
comment|/* r13 - SP: Valid for Hyp. frames only, o/w banked (see below) */
comment|/* r14 - LR: is the same physical register as LR_usr */
union|union
block|{
name|uint32_t
name|lr
decl_stmt|;
comment|/* r14 - LR: Valid for Hyp. Same physical register as lr_usr. */
name|uint32_t
name|lr_usr
decl_stmt|;
block|}
union|;
name|uint32_t
name|pc
decl_stmt|;
comment|/* Return IP */
name|uint32_t
name|cpsr
decl_stmt|;
comment|/* Return mode */
name|uint32_t
name|pad0
decl_stmt|;
comment|/* Doubleword-align the kernel half of the frame */
comment|/* Outer guest frame only from here on... */
name|uint32_t
name|r8_fiq
decl_stmt|,
name|r9_fiq
decl_stmt|,
name|r10_fiq
decl_stmt|,
name|r11_fiq
decl_stmt|,
name|r12_fiq
decl_stmt|;
name|uint32_t
name|sp_usr
decl_stmt|;
comment|/* LR_usr is the same register as LR, see above */
name|uint32_t
name|sp_svc
decl_stmt|,
name|sp_abt
decl_stmt|,
name|sp_und
decl_stmt|,
name|sp_irq
decl_stmt|,
name|sp_fiq
decl_stmt|;
name|uint32_t
name|lr_svc
decl_stmt|,
name|lr_abt
decl_stmt|,
name|lr_und
decl_stmt|,
name|lr_irq
decl_stmt|,
name|lr_fiq
decl_stmt|;
name|uint32_t
name|spsr_svc
decl_stmt|,
name|spsr_abt
decl_stmt|,
name|spsr_und
decl_stmt|,
name|spsr_irq
decl_stmt|,
name|spsr_fiq
decl_stmt|;
name|uint32_t
name|pad1
decl_stmt|;
comment|/* Doubleword-align the user half of the frame */
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

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|cpu_user_regs_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|uint64_t
name|xen_pfn_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PRI_xen_pfn
value|PRIx64
end_define

begin_comment
comment|/* Maximum number of virtual CPUs in legacy multi-processor guests. */
end_comment

begin_comment
comment|/* Only one. All other VCPUS must use VCPUOP_register_vcpu_info */
end_comment

begin_define
define|#
directive|define
name|XEN_LEGACY_MAX_VCPUS
value|1
end_define

begin_typedef
typedef|typedef
name|uint32_t
name|xen_ulong_t
typedef|;
end_typedef

begin_struct
struct|struct
name|vcpu_guest_context
block|{
name|struct
name|cpu_user_regs
name|user_regs
decl_stmt|;
comment|/* User-level CPU registers     */
name|uint32_t
name|sctlr
decl_stmt|;
name|uint32_t
name|ttbr0
decl_stmt|,
name|ttbr1
decl_stmt|,
name|ttbcr
decl_stmt|;
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
name|arch_vcpu_info
block|{ }
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|arch_vcpu_info
name|arch_vcpu_info_t
typedef|;
end_typedef

begin_struct
struct|struct
name|arch_shared_info
block|{ }
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|arch_shared_info
name|arch_shared_info_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint64_t
name|xen_callback_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ifndef __ASSEMBLY __ */
end_comment

begin_comment
comment|/* PSR bits (CPSR, SPSR)*/
end_comment

begin_comment
comment|/* 0-4: Mode */
end_comment

begin_define
define|#
directive|define
name|PSR_MODE_MASK
value|0x1f
end_define

begin_define
define|#
directive|define
name|PSR_MODE_USR
value|0x10
end_define

begin_define
define|#
directive|define
name|PSR_MODE_FIQ
value|0x11
end_define

begin_define
define|#
directive|define
name|PSR_MODE_IRQ
value|0x12
end_define

begin_define
define|#
directive|define
name|PSR_MODE_SVC
value|0x13
end_define

begin_define
define|#
directive|define
name|PSR_MODE_MON
value|0x16
end_define

begin_define
define|#
directive|define
name|PSR_MODE_ABT
value|0x17
end_define

begin_define
define|#
directive|define
name|PSR_MODE_HYP
value|0x1a
end_define

begin_define
define|#
directive|define
name|PSR_MODE_UND
value|0x1b
end_define

begin_define
define|#
directive|define
name|PSR_MODE_SYS
value|0x1f
end_define

begin_define
define|#
directive|define
name|PSR_THUMB
value|(1<<5)
end_define

begin_comment
comment|/* Thumb Mode enable */
end_comment

begin_define
define|#
directive|define
name|PSR_FIQ_MASK
value|(1<<6)
end_define

begin_comment
comment|/* Fast Interrupt mask */
end_comment

begin_define
define|#
directive|define
name|PSR_IRQ_MASK
value|(1<<7)
end_define

begin_comment
comment|/* Interrupt mask */
end_comment

begin_define
define|#
directive|define
name|PSR_ABT_MASK
value|(1<<8)
end_define

begin_comment
comment|/* Asynchronous Abort mask */
end_comment

begin_define
define|#
directive|define
name|PSR_BIG_ENDIAN
value|(1<<9)
end_define

begin_comment
comment|/* Big Endian Mode */
end_comment

begin_define
define|#
directive|define
name|PSR_JAZELLE
value|(1<<24)
end_define

begin_comment
comment|/* Jazelle Mode */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  __XEN_PUBLIC_ARCH_ARM_H__ */
end_comment

begin_comment
comment|/*  * Local variables:  * mode: C  * c-set-style: "BSD"  * c-basic-offset: 4  * tab-width: 4  * indent-tabs-mode: nil  * End:  */
end_comment

end_unit

