begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  * xen-x86_64.h  *   * Guest OS interface to x86 64-bit Xen.  *   * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to  * deal in the Software without restriction, including without limitation the  * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or  * sell copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER  * DEALINGS IN THE SOFTWARE.  *  * Copyright (c) 2004-2006, K A Fraser  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XEN_PUBLIC_ARCH_X86_XEN_X86_64_H__
end_ifndef

begin_define
define|#
directive|define
name|__XEN_PUBLIC_ARCH_X86_XEN_X86_64_H__
end_define

begin_comment
comment|/*  * Hypercall interface:  *  Input:  %rdi, %rsi, %rdx, %r10, %r8 (arguments 1-5)  *  Output: %rax  * Access is via hypercall page (set up by guest loader or via a Xen MSR):  *  call hypercall_page + hypercall-number * 32  * Clobbered: argument registers (e.g., 2-arg hypercall clobbers %rdi,%rsi)  */
end_comment

begin_if
if|#
directive|if
name|__XEN_INTERFACE_VERSION__
operator|<
literal|0x00030203
end_if

begin_comment
comment|/*  * Legacy hypercall interface:  * As above, except the entry sequence to the hypervisor is:  *  mov $hypercall-number*32,%eax ; syscall  * Clobbered: %rcx, %r11, argument registers (as above)  */
end_comment

begin_define
define|#
directive|define
name|TRAP_INSTR
value|"syscall"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * 64-bit segment selectors  * These flat segments are in the Xen-private section of every GDT. Since these  * are also present in the initial GDT, many OSes will be able to avoid  * installing their own GDT.  */
end_comment

begin_define
define|#
directive|define
name|FLAT_RING3_CS32
value|0xe023
end_define

begin_comment
comment|/* GDT index 260 */
end_comment

begin_define
define|#
directive|define
name|FLAT_RING3_CS64
value|0xe033
end_define

begin_comment
comment|/* GDT index 261 */
end_comment

begin_define
define|#
directive|define
name|FLAT_RING3_DS32
value|0xe02b
end_define

begin_comment
comment|/* GDT index 262 */
end_comment

begin_define
define|#
directive|define
name|FLAT_RING3_DS64
value|0x0000
end_define

begin_comment
comment|/* NULL selector */
end_comment

begin_define
define|#
directive|define
name|FLAT_RING3_SS32
value|0xe02b
end_define

begin_comment
comment|/* GDT index 262 */
end_comment

begin_define
define|#
directive|define
name|FLAT_RING3_SS64
value|0xe02b
end_define

begin_comment
comment|/* GDT index 262 */
end_comment

begin_define
define|#
directive|define
name|FLAT_KERNEL_DS64
value|FLAT_RING3_DS64
end_define

begin_define
define|#
directive|define
name|FLAT_KERNEL_DS32
value|FLAT_RING3_DS32
end_define

begin_define
define|#
directive|define
name|FLAT_KERNEL_DS
value|FLAT_KERNEL_DS64
end_define

begin_define
define|#
directive|define
name|FLAT_KERNEL_CS64
value|FLAT_RING3_CS64
end_define

begin_define
define|#
directive|define
name|FLAT_KERNEL_CS32
value|FLAT_RING3_CS32
end_define

begin_define
define|#
directive|define
name|FLAT_KERNEL_CS
value|FLAT_KERNEL_CS64
end_define

begin_define
define|#
directive|define
name|FLAT_KERNEL_SS64
value|FLAT_RING3_SS64
end_define

begin_define
define|#
directive|define
name|FLAT_KERNEL_SS32
value|FLAT_RING3_SS32
end_define

begin_define
define|#
directive|define
name|FLAT_KERNEL_SS
value|FLAT_KERNEL_SS64
end_define

begin_define
define|#
directive|define
name|FLAT_USER_DS64
value|FLAT_RING3_DS64
end_define

begin_define
define|#
directive|define
name|FLAT_USER_DS32
value|FLAT_RING3_DS32
end_define

begin_define
define|#
directive|define
name|FLAT_USER_DS
value|FLAT_USER_DS64
end_define

begin_define
define|#
directive|define
name|FLAT_USER_CS64
value|FLAT_RING3_CS64
end_define

begin_define
define|#
directive|define
name|FLAT_USER_CS32
value|FLAT_RING3_CS32
end_define

begin_define
define|#
directive|define
name|FLAT_USER_CS
value|FLAT_USER_CS64
end_define

begin_define
define|#
directive|define
name|FLAT_USER_SS64
value|FLAT_RING3_SS64
end_define

begin_define
define|#
directive|define
name|FLAT_USER_SS32
value|FLAT_RING3_SS32
end_define

begin_define
define|#
directive|define
name|FLAT_USER_SS
value|FLAT_USER_SS64
end_define

begin_define
define|#
directive|define
name|__HYPERVISOR_VIRT_START
value|0xFFFF800000000000
end_define

begin_define
define|#
directive|define
name|__HYPERVISOR_VIRT_END
value|0xFFFF880000000000
end_define

begin_define
define|#
directive|define
name|__MACH2PHYS_VIRT_START
value|0xFFFF800000000000
end_define

begin_define
define|#
directive|define
name|__MACH2PHYS_VIRT_END
value|0xFFFF804000000000
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|HYPERVISOR_VIRT_START
end_ifndef

begin_define
define|#
directive|define
name|HYPERVISOR_VIRT_START
value|mk_unsigned_long(__HYPERVISOR_VIRT_START)
end_define

begin_define
define|#
directive|define
name|HYPERVISOR_VIRT_END
value|mk_unsigned_long(__HYPERVISOR_VIRT_END)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MACH2PHYS_VIRT_START
value|mk_unsigned_long(__MACH2PHYS_VIRT_START)
end_define

begin_define
define|#
directive|define
name|MACH2PHYS_VIRT_END
value|mk_unsigned_long(__MACH2PHYS_VIRT_END)
end_define

begin_define
define|#
directive|define
name|MACH2PHYS_NR_ENTRIES
value|((MACH2PHYS_VIRT_END-MACH2PHYS_VIRT_START)>>3)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|machine_to_phys_mapping
end_ifndef

begin_define
define|#
directive|define
name|machine_to_phys_mapping
value|((unsigned long *)HYPERVISOR_VIRT_START)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * int HYPERVISOR_set_segment_base(unsigned int which, unsigned long base)  *  @which == SEGBASE_*  ;  @base == 64-bit base address  * Returns 0 on success.  */
end_comment

begin_define
define|#
directive|define
name|SEGBASE_FS
value|0
end_define

begin_define
define|#
directive|define
name|SEGBASE_GS_USER
value|1
end_define

begin_define
define|#
directive|define
name|SEGBASE_GS_KERNEL
value|2
end_define

begin_define
define|#
directive|define
name|SEGBASE_GS_USER_SEL
value|3
end_define

begin_comment
comment|/* Set user %gs specified in base[15:0] */
end_comment

begin_comment
comment|/*  * int HYPERVISOR_iret(void)  * All arguments are on the kernel stack, in the following format.  * Never returns if successful. Current kernel context is lost.  * The saved CS is mapped as follows:  *   RING0 -> RING3 kernel mode.  *   RING1 -> RING3 kernel mode.  *   RING2 -> RING3 kernel mode.  *   RING3 -> RING3 user mode.  * However RING0 indicates that the guest kernel should return to iteself  * directly with  *      orb   $3,1*8(%rsp)  *      iretq  * If flags contains VGCF_in_syscall:  *   Restore RAX, RIP, RFLAGS, RSP.  *   Discard R11, RCX, CS, SS.  * Otherwise:  *   Restore RAX, R11, RCX, CS:RIP, RFLAGS, SS:RSP.  * All other registers are saved on hypercall entry and restored to user.  */
end_comment

begin_comment
comment|/* Guest exited in SYSCALL context? Return to guest with SYSRET? */
end_comment

begin_define
define|#
directive|define
name|_VGCF_in_syscall
value|8
end_define

begin_define
define|#
directive|define
name|VGCF_in_syscall
value|(1<<_VGCF_in_syscall)
end_define

begin_define
define|#
directive|define
name|VGCF_IN_SYSCALL
value|VGCF_in_syscall
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|__ASSEMBLY__
end_ifndef

begin_struct
struct|struct
name|iret_context
block|{
comment|/* Top of stack (%rsp at point of hypercall). */
name|uint64_t
name|rax
decl_stmt|,
name|r11
decl_stmt|,
name|rcx
decl_stmt|,
name|flags
decl_stmt|,
name|rip
decl_stmt|,
name|cs
decl_stmt|,
name|rflags
decl_stmt|,
name|rsp
decl_stmt|,
name|ss
decl_stmt|;
comment|/* Bottom of iret stack frame. */
block|}
struct|;
end_struct

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__STRICT_ANSI__
argument_list|)
end_if

begin_comment
comment|/* Anonymous union includes both 32- and 64-bit names (e.g., eax/rax). */
end_comment

begin_define
define|#
directive|define
name|__DECL_REG
parameter_list|(
name|name
parameter_list|)
value|union { \     uint64_t r ## name, e ## name; \     uint32_t _e ## name; \ }
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Non-gcc sources must always use the proper 64-bit name (e.g., rax). */
end_comment

begin_define
define|#
directive|define
name|__DECL_REG
parameter_list|(
name|name
parameter_list|)
value|uint64_t r ## name
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|cpu_user_regs
block|{
name|uint64_t
name|r15
decl_stmt|;
name|uint64_t
name|r14
decl_stmt|;
name|uint64_t
name|r13
decl_stmt|;
name|uint64_t
name|r12
decl_stmt|;
name|__DECL_REG
argument_list|(
name|bp
argument_list|)
expr_stmt|;
name|__DECL_REG
argument_list|(
name|bx
argument_list|)
expr_stmt|;
name|uint64_t
name|r11
decl_stmt|;
name|uint64_t
name|r10
decl_stmt|;
name|uint64_t
name|r9
decl_stmt|;
name|uint64_t
name|r8
decl_stmt|;
name|__DECL_REG
argument_list|(
name|ax
argument_list|)
expr_stmt|;
name|__DECL_REG
argument_list|(
name|cx
argument_list|)
expr_stmt|;
name|__DECL_REG
argument_list|(
name|dx
argument_list|)
expr_stmt|;
name|__DECL_REG
argument_list|(
name|si
argument_list|)
expr_stmt|;
name|__DECL_REG
argument_list|(
name|di
argument_list|)
expr_stmt|;
name|uint32_t
name|error_code
decl_stmt|;
comment|/* private */
name|uint32_t
name|entry_vector
decl_stmt|;
comment|/* private */
name|__DECL_REG
argument_list|(
name|ip
argument_list|)
expr_stmt|;
name|uint16_t
name|cs
decl_stmt|,
name|_pad0
index|[
literal|1
index|]
decl_stmt|;
name|uint8_t
name|saved_upcall_mask
decl_stmt|;
name|uint8_t
name|_pad1
index|[
literal|3
index|]
decl_stmt|;
name|__DECL_REG
argument_list|(
name|flags
argument_list|)
expr_stmt|;
comment|/* rflags.IF == !saved_upcall_mask */
name|__DECL_REG
argument_list|(
name|sp
argument_list|)
expr_stmt|;
name|uint16_t
name|ss
decl_stmt|,
name|_pad2
index|[
literal|3
index|]
decl_stmt|;
name|uint16_t
name|es
decl_stmt|,
name|_pad3
index|[
literal|3
index|]
decl_stmt|;
name|uint16_t
name|ds
decl_stmt|,
name|_pad4
index|[
literal|3
index|]
decl_stmt|;
name|uint16_t
name|fs
decl_stmt|,
name|_pad5
index|[
literal|3
index|]
decl_stmt|;
comment|/* Non-zero => takes precedence over fs_base.     */
name|uint16_t
name|gs
decl_stmt|,
name|_pad6
index|[
literal|3
index|]
decl_stmt|;
comment|/* Non-zero => takes precedence over gs_base_usr. */
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

begin_undef
undef|#
directive|undef
name|__DECL_REG
end_undef

begin_define
define|#
directive|define
name|xen_pfn_to_cr3
parameter_list|(
name|pfn
parameter_list|)
value|((unsigned long)(pfn)<< 12)
end_define

begin_define
define|#
directive|define
name|xen_cr3_to_pfn
parameter_list|(
name|cr3
parameter_list|)
value|((unsigned long)(cr3)>> 12)
end_define

begin_struct
struct|struct
name|arch_vcpu_info
block|{
name|unsigned
name|long
name|cr2
decl_stmt|;
name|unsigned
name|long
name|pad
decl_stmt|;
comment|/* sizeof(vcpu_info_t) == 64 */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|arch_vcpu_info
name|arch_vcpu_info_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|xen_callback_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !__ASSEMBLY__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XEN_PUBLIC_ARCH_X86_XEN_X86_64_H__ */
end_comment

begin_comment
comment|/*  * Local variables:  * mode: C  * c-set-style: "BSD"  * c-basic-offset: 4  * tab-width: 4  * indent-tabs-mode: nil  * End:  */
end_comment

end_unit

