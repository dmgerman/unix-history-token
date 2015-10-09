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
comment|/*  * `incontents 50 arm_abi Hypercall Calling Convention  *  * A hypercall is issued using the ARM HVC instruction.  *  * A hypercall can take up to 5 arguments. These are passed in  * registers, the first argument in x0/r0 (for arm64/arm32 guests  * respectively irrespective of whether the underlying hypervisor is  * 32- or 64-bit), the second argument in x1/r1, the third in x2/r2,  * the forth in x3/r3 and the fifth in x4/r4.  *  * The hypercall number is passed in r12 (arm) or x16 (arm64). In both  * cases the relevant ARM procedure calling convention specifies this  * is an inter-procedure-call scratch register (e.g. for use in linker  * stubs). This use does not conflict with use during a hypercall.  *  * The HVC ISS must contain a Xen specific TAG: XEN_HYPERCALL_TAG.  *  * The return value is in x0/r0.  *  * The hypercall will clobber x16/r12 and the argument registers used  * by that hypercall (except r0 which is the return value) i.e. in  * addition to x16/r12 a 2 argument hypercall will clobber x1/r1 and a  * 4 argument hypercall will clobber x1/r1, x2/r2 and x3/r3.  *  * Parameter structs passed to hypercalls are laid out according to  * the Procedure Call Standard for the ARM Architecture (AAPCS, AKA  * EABI) and Procedure Call Standard for the ARM 64-bit Architecture  * (AAPCS64). Where there is a conflict the 64-bit standard should be  * used regardless of guest type. Structures which are passed as  * hypercall arguments are always little endian.  *  * All memory which is shared with other entities in the system  * (including the hypervisor and other guests) must reside in memory  * which is mapped as Normal Inner-cacheable. This applies to:  *  - hypercall arguments passed via a pointer to guest memory.  *  - memory shared via the grant table mechanism (including PV I/O  *    rings etc).  *  - memory shared with the hypervisor (struct shared_info, struct  *    vcpu_info, the grant table, etc).  *  * Any Inner cache allocation strategy (Write-Back, Write-Through etc)  * is acceptable. There is no restriction on the Outer-cacheability.  */
end_comment

begin_comment
comment|/*  * `incontents 55 arm_hcall Supported Hypercalls  *  * Xen on ARM makes extensive use of hardware facilities and therefore  * only a subset of the potential hypercalls are required.  *  * Since ARM uses second stage paging any machine/physical addresses  * passed to hypercalls are Guest Physical Addresses (Intermediate  * Physical Addresses) unless otherwise noted.  *  * The following hypercalls (and sub operations) are supported on the  * ARM platform. Other hypercalls should be considered  * unavailable/unsupported.  *  *  HYPERVISOR_memory_op  *   All generic sub-operations  *  *  HYPERVISOR_domctl  *   All generic sub-operations, with the exception of:  *    * XEN_DOMCTL_irq_permission (not yet implemented)  *  *  HYPERVISOR_sched_op  *   All generic sub-operations, with the exception of:  *    * SCHEDOP_block -- prefer wfi hardware instruction  *  *  HYPERVISOR_console_io  *   All generic sub-operations  *  *  HYPERVISOR_xen_version  *   All generic sub-operations  *  *  HYPERVISOR_event_channel_op  *   All generic sub-operations  *  *  HYPERVISOR_physdev_op  *   No sub-operations are currenty supported  *  *  HYPERVISOR_sysctl  *   All generic sub-operations, with the exception of:  *    * XEN_SYSCTL_page_offline_op  *    * XEN_SYSCTL_get_pmstat  *    * XEN_SYSCTL_pm_op  *  *  HYPERVISOR_hvm_op  *   Exactly these sub-operations are supported:  *    * HVMOP_set_param  *    * HVMOP_get_param  *  *  HYPERVISOR_grant_table_op  *   All generic sub-operations  *  *  HYPERVISOR_vcpu_op  *   Exactly these sub-operations are supported:  *    * VCPUOP_register_vcpu_info  *    * VCPUOP_register_runstate_memory_area  *  *  * Other notes on the ARM ABI:  *  * - struct start_info is not exported to ARM guests.  *  * - struct shared_info is mapped by ARM guests using the  *   HYPERVISOR_memory_op sub-op XENMEM_add_to_physmap, passing  *   XENMAPSPACE_shared_info as space parameter.  *  * - All the per-cpu struct vcpu_info are mapped by ARM guests using the  *   HYPERVISOR_vcpu_op sub-op VCPUOP_register_vcpu_info, including cpu0  *   struct vcpu_info.  *  * - The grant table is mapped using the HYPERVISOR_memory_op sub-op  *   XENMEM_add_to_physmap, passing XENMAPSPACE_grant_table as space  *   parameter. The memory range specified under the Xen compatible  *   hypervisor node on device tree can be used as target gpfn for the  *   mapping.  *  * - Xenstore is initialized by using the two hvm_params  *   HVM_PARAM_STORE_PFN and HVM_PARAM_STORE_EVTCHN. They can be read  *   with the HYPERVISOR_hvm_op sub-op HVMOP_get_param.  *  * - The paravirtualized console is initialized by using the two  *   hvm_params HVM_PARAM_CONSOLE_PFN and HVM_PARAM_CONSOLE_EVTCHN. They  *   can be read with the HYPERVISOR_hvm_op sub-op HVMOP_get_param.  *  * - Event channel notifications are delivered using the percpu GIC  *   interrupt specified under the Xen compatible hypervisor node on  *   device tree.  *  * - The device tree Xen compatible node is fully described under Linux  *   at Documentation/devicetree/bindings/arm/xen.txt.  */
end_comment

begin_define
define|#
directive|define
name|XEN_HYPERCALL_TAG
value|0XEA1
end_define

begin_define
define|#
directive|define
name|int64_aligned_t
value|int64_t __attribute__((aligned(8)))
end_define

begin_define
define|#
directive|define
name|uint64_aligned_t
value|uint64_t __attribute__((aligned(8)))
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
value|typedef union { type *p; unsigned long q; }                 \         __guest_handle_ ## name;                                \     typedef union { type *p; uint64_aligned_t q; }              \         __guest_handle_64_ ## name;
end_define

begin_comment
comment|/*  * XEN_GUEST_HANDLE represents a guest pointer, when passed as a field  * in a struct in memory. On ARM is always 8 bytes sizes and 8 bytes  * aligned.  * XEN_GUEST_HANDLE_PARAM represents a guest pointer, when passed as an  * hypercall argument. It is 4 bytes on aarch32 and 8 bytes on aarch64.  */
end_comment

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
value|__guest_handle_64_ ## name
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
name|XEN_GUEST_HANDLE_PARAM
parameter_list|(
name|name
parameter_list|)
value|__guest_handle_ ## name
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
define|\
value|do {                                                    \         typeof(&(hnd)) _sxghr_tmp =&(hnd);                 \         _sxghr_tmp->q = 0;                                  \         _sxghr_tmp->p = val;                                \     } while ( 0 )
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
comment|/* Anonymous union includes both 32- and 64-bit names (e.g., r0/x0). */
end_comment

begin_define
define|#
directive|define
name|__DECL_REG
parameter_list|(
name|n64
parameter_list|,
name|n32
parameter_list|)
value|union {          \         uint64_t n64;                          \         uint32_t n32;                          \     }
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Non-gcc sources must always use the proper 64-bit name (e.g., x0). */
end_comment

begin_define
define|#
directive|define
name|__DECL_REG
parameter_list|(
name|n64
parameter_list|,
name|n32
parameter_list|)
value|uint64_t n64
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|vcpu_guest_core_regs
block|{
comment|/*         Aarch64       Aarch32 */
name|__DECL_REG
argument_list|(
name|x0
argument_list|,
name|r0_usr
argument_list|)
expr_stmt|;
name|__DECL_REG
argument_list|(
name|x1
argument_list|,
name|r1_usr
argument_list|)
expr_stmt|;
name|__DECL_REG
argument_list|(
name|x2
argument_list|,
name|r2_usr
argument_list|)
expr_stmt|;
name|__DECL_REG
argument_list|(
name|x3
argument_list|,
name|r3_usr
argument_list|)
expr_stmt|;
name|__DECL_REG
argument_list|(
name|x4
argument_list|,
name|r4_usr
argument_list|)
expr_stmt|;
name|__DECL_REG
argument_list|(
name|x5
argument_list|,
name|r5_usr
argument_list|)
expr_stmt|;
name|__DECL_REG
argument_list|(
name|x6
argument_list|,
name|r6_usr
argument_list|)
expr_stmt|;
name|__DECL_REG
argument_list|(
name|x7
argument_list|,
name|r7_usr
argument_list|)
expr_stmt|;
name|__DECL_REG
argument_list|(
name|x8
argument_list|,
name|r8_usr
argument_list|)
expr_stmt|;
name|__DECL_REG
argument_list|(
name|x9
argument_list|,
name|r9_usr
argument_list|)
expr_stmt|;
name|__DECL_REG
argument_list|(
name|x10
argument_list|,
name|r10_usr
argument_list|)
expr_stmt|;
name|__DECL_REG
argument_list|(
name|x11
argument_list|,
name|r11_usr
argument_list|)
expr_stmt|;
name|__DECL_REG
argument_list|(
name|x12
argument_list|,
name|r12_usr
argument_list|)
expr_stmt|;
name|__DECL_REG
argument_list|(
name|x13
argument_list|,
name|sp_usr
argument_list|)
expr_stmt|;
name|__DECL_REG
argument_list|(
name|x14
argument_list|,
name|lr_usr
argument_list|)
expr_stmt|;
name|__DECL_REG
argument_list|(
name|x15
argument_list|,
name|__unused_sp_hyp
argument_list|)
expr_stmt|;
name|__DECL_REG
argument_list|(
name|x16
argument_list|,
name|lr_irq
argument_list|)
expr_stmt|;
name|__DECL_REG
argument_list|(
name|x17
argument_list|,
name|sp_irq
argument_list|)
expr_stmt|;
name|__DECL_REG
argument_list|(
name|x18
argument_list|,
name|lr_svc
argument_list|)
expr_stmt|;
name|__DECL_REG
argument_list|(
name|x19
argument_list|,
name|sp_svc
argument_list|)
expr_stmt|;
name|__DECL_REG
argument_list|(
name|x20
argument_list|,
name|lr_abt
argument_list|)
expr_stmt|;
name|__DECL_REG
argument_list|(
name|x21
argument_list|,
name|sp_abt
argument_list|)
expr_stmt|;
name|__DECL_REG
argument_list|(
name|x22
argument_list|,
name|lr_und
argument_list|)
expr_stmt|;
name|__DECL_REG
argument_list|(
name|x23
argument_list|,
name|sp_und
argument_list|)
expr_stmt|;
name|__DECL_REG
argument_list|(
name|x24
argument_list|,
name|r8_fiq
argument_list|)
expr_stmt|;
name|__DECL_REG
argument_list|(
name|x25
argument_list|,
name|r9_fiq
argument_list|)
expr_stmt|;
name|__DECL_REG
argument_list|(
name|x26
argument_list|,
name|r10_fiq
argument_list|)
expr_stmt|;
name|__DECL_REG
argument_list|(
name|x27
argument_list|,
name|r11_fiq
argument_list|)
expr_stmt|;
name|__DECL_REG
argument_list|(
name|x28
argument_list|,
name|r12_fiq
argument_list|)
expr_stmt|;
name|__DECL_REG
argument_list|(
name|x29
argument_list|,
name|sp_fiq
argument_list|)
expr_stmt|;
name|__DECL_REG
argument_list|(
name|x30
argument_list|,
name|lr_fiq
argument_list|)
expr_stmt|;
comment|/* Return address and mode */
name|__DECL_REG
argument_list|(
name|pc64
argument_list|,
name|pc32
argument_list|)
expr_stmt|;
comment|/* ELR_EL2 */
name|uint32_t
name|cpsr
decl_stmt|;
comment|/* SPSR_EL2 */
union|union
block|{
name|uint32_t
name|spsr_el1
decl_stmt|;
comment|/* AArch64 */
name|uint32_t
name|spsr_svc
decl_stmt|;
comment|/* AArch32 */
block|}
union|;
comment|/* AArch32 guests only */
name|uint32_t
name|spsr_fiq
decl_stmt|,
name|spsr_irq
decl_stmt|,
name|spsr_und
decl_stmt|,
name|spsr_abt
decl_stmt|;
comment|/* AArch64 guests only */
name|uint64_t
name|sp_el0
decl_stmt|;
name|uint64_t
name|sp_el1
decl_stmt|,
name|elr_el1
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|vcpu_guest_core_regs
name|vcpu_guest_core_regs_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|vcpu_guest_core_regs_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_undef
undef|#
directive|undef
name|__DECL_REG
end_undef

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
name|uint64_t
name|xen_ulong_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PRI_xen_ulong
value|PRIx64
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__XEN__
argument_list|)
operator|||
name|defined
argument_list|(
name|__XEN_TOOLS__
argument_list|)
end_if

begin_struct
struct|struct
name|vcpu_guest_context
block|{
define|#
directive|define
name|_VGCF_online
value|0
define|#
directive|define
name|VGCF_online
value|(1<<_VGCF_online)
name|uint32_t
name|flags
decl_stmt|;
comment|/* VGCF_* */
name|struct
name|vcpu_guest_core_regs
name|user_regs
decl_stmt|;
comment|/* Core CPU registers */
name|uint32_t
name|sctlr
decl_stmt|;
name|uint64_t
name|ttbcr
decl_stmt|,
name|ttbr0
decl_stmt|,
name|ttbr1
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

begin_comment
comment|/*  * struct xen_arch_domainconfig's ABI is covered by  * XEN_DOMCTL_INTERFACE_VERSION.  */
end_comment

begin_define
define|#
directive|define
name|XEN_DOMCTL_CONFIG_GIC_NATIVE
value|0
end_define

begin_define
define|#
directive|define
name|XEN_DOMCTL_CONFIG_GIC_V2
value|1
end_define

begin_define
define|#
directive|define
name|XEN_DOMCTL_CONFIG_GIC_V3
value|2
end_define

begin_struct
struct|struct
name|xen_arch_domainconfig
block|{
comment|/* IN/OUT */
name|uint8_t
name|gic_version
decl_stmt|;
comment|/* IN */
name|uint32_t
name|nr_spis
decl_stmt|;
comment|/*      * OUT      * Based on the property clock-frequency in the DT timer node.      * The property may be present when the bootloader/firmware doesn't      * set correctly CNTFRQ which hold the timer frequency.      *      * As it's not possible to trap this register, we have to replicate      * the value in the guest DT.      *      * = 0 => property not present      *> 0 => Value of the property      *      */
name|uint32_t
name|clock_frequency
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XEN__ || __XEN_TOOLS__ */
end_comment

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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__XEN__
argument_list|)
operator|||
name|defined
argument_list|(
name|__XEN_TOOLS__
argument_list|)
end_if

begin_comment
comment|/* PSR bits (CPSR, SPSR) */
end_comment

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
comment|/* arm32: Big Endian Mode */
end_comment

begin_define
define|#
directive|define
name|PSR_DBG_MASK
value|(1<<9)
end_define

begin_comment
comment|/* arm64: Debug Exception mask */
end_comment

begin_define
define|#
directive|define
name|PSR_IT_MASK
value|(0x0600fc00)
end_define

begin_comment
comment|/* Thumb If-Then Mask */
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

begin_comment
comment|/* 32 bit modes */
end_comment

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

begin_comment
comment|/* 64 bit modes */
end_comment

begin_define
define|#
directive|define
name|PSR_MODE_BIT
value|0x10
end_define

begin_comment
comment|/* Set iff AArch32 */
end_comment

begin_define
define|#
directive|define
name|PSR_MODE_EL3h
value|0x0d
end_define

begin_define
define|#
directive|define
name|PSR_MODE_EL3t
value|0x0c
end_define

begin_define
define|#
directive|define
name|PSR_MODE_EL2h
value|0x09
end_define

begin_define
define|#
directive|define
name|PSR_MODE_EL2t
value|0x08
end_define

begin_define
define|#
directive|define
name|PSR_MODE_EL1h
value|0x05
end_define

begin_define
define|#
directive|define
name|PSR_MODE_EL1t
value|0x04
end_define

begin_define
define|#
directive|define
name|PSR_MODE_EL0t
value|0x00
end_define

begin_define
define|#
directive|define
name|PSR_GUEST32_INIT
value|(PSR_ABT_MASK|PSR_FIQ_MASK|PSR_IRQ_MASK|PSR_MODE_SVC)
end_define

begin_define
define|#
directive|define
name|PSR_GUEST64_INIT
value|(PSR_ABT_MASK|PSR_FIQ_MASK|PSR_IRQ_MASK|PSR_MODE_EL1h)
end_define

begin_define
define|#
directive|define
name|SCTLR_GUEST_INIT
value|0x00c50078
end_define

begin_comment
comment|/*  * Virtual machine platform (memory layout, interrupts)  *  * These are defined for consistency between the tools and the  * hypervisor. Guests must not rely on these hardcoded values but  * should instead use the FDT.  */
end_comment

begin_comment
comment|/* Physical Address Space */
end_comment

begin_comment
comment|/*  * vGIC mappings: Only one set of mapping is used by the guest.  * Therefore they can overlap.  */
end_comment

begin_comment
comment|/* vGIC v2 mappings */
end_comment

begin_define
define|#
directive|define
name|GUEST_GICD_BASE
value|0x03001000ULL
end_define

begin_define
define|#
directive|define
name|GUEST_GICD_SIZE
value|0x00001000ULL
end_define

begin_define
define|#
directive|define
name|GUEST_GICC_BASE
value|0x03002000ULL
end_define

begin_define
define|#
directive|define
name|GUEST_GICC_SIZE
value|0x00000100ULL
end_define

begin_comment
comment|/* vGIC v3 mappings */
end_comment

begin_define
define|#
directive|define
name|GUEST_GICV3_GICD_BASE
value|0x03001000ULL
end_define

begin_define
define|#
directive|define
name|GUEST_GICV3_GICD_SIZE
value|0x00010000ULL
end_define

begin_define
define|#
directive|define
name|GUEST_GICV3_RDIST_STRIDE
value|0x20000ULL
end_define

begin_define
define|#
directive|define
name|GUEST_GICV3_RDIST_REGIONS
value|1
end_define

begin_define
define|#
directive|define
name|GUEST_GICV3_GICR0_BASE
value|0x03020000ULL
end_define

begin_comment
comment|/* vCPU0 - vCPU127 */
end_comment

begin_define
define|#
directive|define
name|GUEST_GICV3_GICR0_SIZE
value|0x01000000ULL
end_define

begin_comment
comment|/*  * 16MB == 4096 pages reserved for guest to use as a region to map its  * grant table in.  */
end_comment

begin_define
define|#
directive|define
name|GUEST_GNTTAB_BASE
value|0x38000000ULL
end_define

begin_define
define|#
directive|define
name|GUEST_GNTTAB_SIZE
value|0x01000000ULL
end_define

begin_define
define|#
directive|define
name|GUEST_MAGIC_BASE
value|0x39000000ULL
end_define

begin_define
define|#
directive|define
name|GUEST_MAGIC_SIZE
value|0x01000000ULL
end_define

begin_define
define|#
directive|define
name|GUEST_RAM_BANKS
value|2
end_define

begin_define
define|#
directive|define
name|GUEST_RAM0_BASE
value|0x40000000ULL
end_define

begin_comment
comment|/* 3GB of low RAM @ 1GB */
end_comment

begin_define
define|#
directive|define
name|GUEST_RAM0_SIZE
value|0xc0000000ULL
end_define

begin_define
define|#
directive|define
name|GUEST_RAM1_BASE
value|0x0200000000ULL
end_define

begin_comment
comment|/* 1016GB of RAM @ 8GB */
end_comment

begin_define
define|#
directive|define
name|GUEST_RAM1_SIZE
value|0xfe00000000ULL
end_define

begin_define
define|#
directive|define
name|GUEST_RAM_BASE
value|GUEST_RAM0_BASE
end_define

begin_comment
comment|/* Lowest RAM address */
end_comment

begin_comment
comment|/* Largest amount of actual RAM, not including holes */
end_comment

begin_define
define|#
directive|define
name|GUEST_RAM_MAX
value|(GUEST_RAM0_SIZE + GUEST_RAM1_SIZE)
end_define

begin_comment
comment|/* Suitable for e.g. const uint64_t ramfoo[] = GUEST_RAM_BANK_FOOS; */
end_comment

begin_define
define|#
directive|define
name|GUEST_RAM_BANK_BASES
value|{ GUEST_RAM0_BASE, GUEST_RAM1_BASE }
end_define

begin_define
define|#
directive|define
name|GUEST_RAM_BANK_SIZES
value|{ GUEST_RAM0_SIZE, GUEST_RAM1_SIZE }
end_define

begin_comment
comment|/* Interrupts */
end_comment

begin_define
define|#
directive|define
name|GUEST_TIMER_VIRT_PPI
value|27
end_define

begin_define
define|#
directive|define
name|GUEST_TIMER_PHYS_S_PPI
value|29
end_define

begin_define
define|#
directive|define
name|GUEST_TIMER_PHYS_NS_PPI
value|30
end_define

begin_define
define|#
directive|define
name|GUEST_EVTCHN_PPI
value|31
end_define

begin_comment
comment|/* PSCI functions */
end_comment

begin_define
define|#
directive|define
name|PSCI_cpu_suspend
value|0
end_define

begin_define
define|#
directive|define
name|PSCI_cpu_off
value|1
end_define

begin_define
define|#
directive|define
name|PSCI_cpu_on
value|2
end_define

begin_define
define|#
directive|define
name|PSCI_migrate
value|3
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

begin_comment
comment|/* Stub definition of PMU structure */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xen_pmu_arch
block|{
name|uint8_t
name|dummy
decl_stmt|;
block|}
name|xen_pmu_arch_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  __XEN_PUBLIC_ARCH_ARM_H__ */
end_comment

begin_comment
comment|/*  * Local variables:  * mode: C  * c-file-style: "BSD"  * c-basic-offset: 4  * tab-width: 4  * indent-tabs-mode: nil  * End:  */
end_comment

end_unit

