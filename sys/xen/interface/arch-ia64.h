begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  * arch-ia64/hypervisor-if.h  *   * Guest OS interface to IA64 Xen.  *  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to  * deal in the Software without restriction, including without limitation the  * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or  * sell copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER  * DEALINGS IN THE SOFTWARE.  *  */
end_comment

begin_include
include|#
directive|include
file|"xen.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|__HYPERVISOR_IF_IA64_H__
end_ifndef

begin_define
define|#
directive|define
name|__HYPERVISOR_IF_IA64_H__
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|||
name|defined
argument_list|(
name|__STRICT_ANSI__
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Anonymous structs/unions are a GNU extension."
end_error

begin_endif
endif|#
directive|endif
end_endif

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
name|XEN_GUEST_HANDLE
parameter_list|(
name|name
parameter_list|)
value|__guest_handle_ ## name
end_define

begin_define
define|#
directive|define
name|XEN_GUEST_HANDLE_64
parameter_list|(
name|name
parameter_list|)
value|XEN_GUEST_HANDLE(name)
end_define

begin_define
define|#
directive|define
name|uint64_aligned_t
value|uint64_t
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
comment|/* Arch specific VIRQs definition */
end_comment

begin_define
define|#
directive|define
name|VIRQ_ITC
value|VIRQ_ARCH_0
end_define

begin_comment
comment|/* V. Virtual itc timer */
end_comment

begin_define
define|#
directive|define
name|VIRQ_MCA_CMC
value|VIRQ_ARCH_1
end_define

begin_comment
comment|/* MCA cmc interrupt */
end_comment

begin_define
define|#
directive|define
name|VIRQ_MCA_CPE
value|VIRQ_ARCH_2
end_define

begin_comment
comment|/* MCA cpe interrupt */
end_comment

begin_comment
comment|/* Maximum number of virtual CPUs in multi-processor guests. */
end_comment

begin_comment
comment|/* WARNING: before changing this, check that shared_info fits on a page */
end_comment

begin_define
define|#
directive|define
name|MAX_VIRT_CPUS
value|64
end_define

begin_comment
comment|/* IO ports location for PV.  */
end_comment

begin_define
define|#
directive|define
name|IO_PORTS_PADDR
value|0x00000ffffc000000UL
end_define

begin_define
define|#
directive|define
name|IO_PORTS_SIZE
value|0x0000000004000000UL
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

begin_ifdef
ifdef|#
directive|ifdef
name|__XEN_TOOLS__
end_ifdef

begin_define
define|#
directive|define
name|XEN_PAGE_SIZE
value|XC_PAGE_SIZE
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XEN_PAGE_SIZE
value|PAGE_SIZE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|INVALID_MFN
value|(~0UL)
end_define

begin_struct
struct|struct
name|pt_fpreg
block|{
union|union
block|{
name|unsigned
name|long
name|bits
index|[
literal|2
index|]
decl_stmt|;
name|long
name|double
name|__dummy
decl_stmt|;
comment|/* force 16-byte alignment */
block|}
name|u
union|;
block|}
struct|;
end_struct

begin_union
union|union
name|vac
block|{
name|unsigned
name|long
name|value
decl_stmt|;
struct|struct
block|{
name|int
name|a_int
range|:
literal|1
decl_stmt|;
name|int
name|a_from_int_cr
range|:
literal|1
decl_stmt|;
name|int
name|a_to_int_cr
range|:
literal|1
decl_stmt|;
name|int
name|a_from_psr
range|:
literal|1
decl_stmt|;
name|int
name|a_from_cpuid
range|:
literal|1
decl_stmt|;
name|int
name|a_cover
range|:
literal|1
decl_stmt|;
name|int
name|a_bsw
range|:
literal|1
decl_stmt|;
name|long
name|reserved
range|:
literal|57
decl_stmt|;
block|}
struct|;
block|}
union|;
end_union

begin_typedef
typedef|typedef
name|union
name|vac
name|vac_t
typedef|;
end_typedef

begin_union
union|union
name|vdc
block|{
name|unsigned
name|long
name|value
decl_stmt|;
struct|struct
block|{
name|int
name|d_vmsw
range|:
literal|1
decl_stmt|;
name|int
name|d_extint
range|:
literal|1
decl_stmt|;
name|int
name|d_ibr_dbr
range|:
literal|1
decl_stmt|;
name|int
name|d_pmc
range|:
literal|1
decl_stmt|;
name|int
name|d_to_pmd
range|:
literal|1
decl_stmt|;
name|int
name|d_itm
range|:
literal|1
decl_stmt|;
name|long
name|reserved
range|:
literal|58
decl_stmt|;
block|}
struct|;
block|}
union|;
end_union

begin_typedef
typedef|typedef
name|union
name|vdc
name|vdc_t
typedef|;
end_typedef

begin_struct
struct|struct
name|mapped_regs
block|{
name|union
name|vac
name|vac
decl_stmt|;
name|union
name|vdc
name|vdc
decl_stmt|;
name|unsigned
name|long
name|virt_env_vaddr
decl_stmt|;
name|unsigned
name|long
name|reserved1
index|[
literal|29
index|]
decl_stmt|;
name|unsigned
name|long
name|vhpi
decl_stmt|;
name|unsigned
name|long
name|reserved2
index|[
literal|95
index|]
decl_stmt|;
union|union
block|{
name|unsigned
name|long
name|vgr
index|[
literal|16
index|]
decl_stmt|;
name|unsigned
name|long
name|bank1_regs
index|[
literal|16
index|]
decl_stmt|;
comment|// bank1 regs (r16-r31) when bank0 active
block|}
union|;
union|union
block|{
name|unsigned
name|long
name|vbgr
index|[
literal|16
index|]
decl_stmt|;
name|unsigned
name|long
name|bank0_regs
index|[
literal|16
index|]
decl_stmt|;
comment|// bank0 regs (r16-r31) when bank1 active
block|}
union|;
name|unsigned
name|long
name|vnat
decl_stmt|;
name|unsigned
name|long
name|vbnat
decl_stmt|;
name|unsigned
name|long
name|vcpuid
index|[
literal|5
index|]
decl_stmt|;
name|unsigned
name|long
name|reserved3
index|[
literal|11
index|]
decl_stmt|;
name|unsigned
name|long
name|vpsr
decl_stmt|;
name|unsigned
name|long
name|vpr
decl_stmt|;
name|unsigned
name|long
name|reserved4
index|[
literal|76
index|]
decl_stmt|;
union|union
block|{
name|unsigned
name|long
name|vcr
index|[
literal|128
index|]
decl_stmt|;
struct|struct
block|{
name|unsigned
name|long
name|dcr
decl_stmt|;
comment|// CR0
name|unsigned
name|long
name|itm
decl_stmt|;
name|unsigned
name|long
name|iva
decl_stmt|;
name|unsigned
name|long
name|rsv1
index|[
literal|5
index|]
decl_stmt|;
name|unsigned
name|long
name|pta
decl_stmt|;
comment|// CR8
name|unsigned
name|long
name|rsv2
index|[
literal|7
index|]
decl_stmt|;
name|unsigned
name|long
name|ipsr
decl_stmt|;
comment|// CR16
name|unsigned
name|long
name|isr
decl_stmt|;
name|unsigned
name|long
name|rsv3
decl_stmt|;
name|unsigned
name|long
name|iip
decl_stmt|;
name|unsigned
name|long
name|ifa
decl_stmt|;
name|unsigned
name|long
name|itir
decl_stmt|;
name|unsigned
name|long
name|iipa
decl_stmt|;
name|unsigned
name|long
name|ifs
decl_stmt|;
name|unsigned
name|long
name|iim
decl_stmt|;
comment|// CR24
name|unsigned
name|long
name|iha
decl_stmt|;
name|unsigned
name|long
name|rsv4
index|[
literal|38
index|]
decl_stmt|;
name|unsigned
name|long
name|lid
decl_stmt|;
comment|// CR64
name|unsigned
name|long
name|ivr
decl_stmt|;
name|unsigned
name|long
name|tpr
decl_stmt|;
name|unsigned
name|long
name|eoi
decl_stmt|;
name|unsigned
name|long
name|irr
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|long
name|itv
decl_stmt|;
comment|// CR72
name|unsigned
name|long
name|pmv
decl_stmt|;
name|unsigned
name|long
name|cmcv
decl_stmt|;
name|unsigned
name|long
name|rsv5
index|[
literal|5
index|]
decl_stmt|;
name|unsigned
name|long
name|lrr0
decl_stmt|;
comment|// CR80
name|unsigned
name|long
name|lrr1
decl_stmt|;
name|unsigned
name|long
name|rsv6
index|[
literal|46
index|]
decl_stmt|;
block|}
struct|;
block|}
union|;
union|union
block|{
name|unsigned
name|long
name|reserved5
index|[
literal|128
index|]
decl_stmt|;
struct|struct
block|{
name|unsigned
name|long
name|precover_ifs
decl_stmt|;
name|unsigned
name|long
name|unat
decl_stmt|;
comment|// not sure if this is needed until NaT arch is done
name|int
name|interrupt_collection_enabled
decl_stmt|;
comment|// virtual psr.ic
comment|/* virtual interrupt deliverable flag is evtchn_upcall_mask in              * shared info area now. interrupt_mask_addr is the address              * of evtchn_upcall_mask for current vcpu              */
name|unsigned
name|char
modifier|*
name|interrupt_mask_addr
decl_stmt|;
name|int
name|pending_interruption
decl_stmt|;
name|unsigned
name|char
name|vpsr_pp
decl_stmt|;
name|unsigned
name|char
name|vpsr_dfh
decl_stmt|;
name|unsigned
name|char
name|hpsr_dfh
decl_stmt|;
name|unsigned
name|char
name|hpsr_mfh
decl_stmt|;
name|unsigned
name|long
name|reserved5_1
index|[
literal|4
index|]
decl_stmt|;
name|int
name|metaphysical_mode
decl_stmt|;
comment|// 1 = use metaphys mapping, 0 = use virtual
name|int
name|banknum
decl_stmt|;
comment|// 0 or 1, which virtual register bank is active
name|unsigned
name|long
name|rrs
index|[
literal|8
index|]
decl_stmt|;
comment|// region registers
name|unsigned
name|long
name|krs
index|[
literal|8
index|]
decl_stmt|;
comment|// kernel registers
name|unsigned
name|long
name|tmp
index|[
literal|16
index|]
decl_stmt|;
comment|// temp registers (e.g. for hyperprivops)
block|}
struct|;
block|}
union|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|mapped_regs
name|mapped_regs_t
typedef|;
end_typedef

begin_struct
struct|struct
name|vpd
block|{
name|struct
name|mapped_regs
name|vpd_low
decl_stmt|;
name|unsigned
name|long
name|reserved6
index|[
literal|3456
index|]
decl_stmt|;
name|unsigned
name|long
name|vmm_avail
index|[
literal|128
index|]
decl_stmt|;
name|unsigned
name|long
name|reserved7
index|[
literal|4096
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|vpd
name|vpd_t
typedef|;
end_typedef

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

begin_comment
comment|/*  * This structure is used for magic page in domain pseudo physical address  * space and the result of XENMEM_machine_memory_map.  * As the XENMEM_machine_memory_map result,  * xen_memory_map::nr_entries indicates the size in bytes   * including struct xen_ia64_memmap_info. Not the number of entries.  */
end_comment

begin_struct
struct|struct
name|xen_ia64_memmap_info
block|{
name|uint64_t
name|efi_memmap_size
decl_stmt|;
comment|/* size of EFI memory map */
name|uint64_t
name|efi_memdesc_size
decl_stmt|;
comment|/* size of an EFI memory map descriptor */
name|uint32_t
name|efi_memdesc_version
decl_stmt|;
comment|/* memory descriptor version */
name|void
modifier|*
name|memdesc
index|[
literal|0
index|]
decl_stmt|;
comment|/* array of efi_memory_desc_t */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_ia64_memmap_info
name|xen_ia64_memmap_info_t
typedef|;
end_typedef

begin_struct
struct|struct
name|arch_shared_info
block|{
comment|/* PFN of the start_info page.  */
name|unsigned
name|long
name|start_info_pfn
decl_stmt|;
comment|/* Interrupt vector for event channel.  */
name|int
name|evtchn_vector
decl_stmt|;
comment|/* PFN of memmap_info page */
name|unsigned
name|int
name|memmap_info_num_pages
decl_stmt|;
comment|/* currently only = 1 case is                                           supported. */
name|unsigned
name|long
name|memmap_info_pfn
decl_stmt|;
name|uint64_t
name|pad
index|[
literal|31
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

begin_typedef
typedef|typedef
name|unsigned
name|long
name|xen_callback_t
typedef|;
end_typedef

begin_struct
struct|struct
name|ia64_tr_entry
block|{
name|unsigned
name|long
name|pte
decl_stmt|;
name|unsigned
name|long
name|itir
decl_stmt|;
name|unsigned
name|long
name|vadr
decl_stmt|;
name|unsigned
name|long
name|rid
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ia64_tr_entry
name|ia64_tr_entry_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|ia64_tr_entry_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|vcpu_tr_regs
block|{
name|struct
name|ia64_tr_entry
name|itrs
index|[
literal|12
index|]
decl_stmt|;
name|struct
name|ia64_tr_entry
name|dtrs
index|[
literal|12
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_union
union|union
name|vcpu_ar_regs
block|{
name|unsigned
name|long
name|ar
index|[
literal|128
index|]
decl_stmt|;
struct|struct
block|{
name|unsigned
name|long
name|kr
index|[
literal|8
index|]
decl_stmt|;
name|unsigned
name|long
name|rsv1
index|[
literal|8
index|]
decl_stmt|;
name|unsigned
name|long
name|rsc
decl_stmt|;
name|unsigned
name|long
name|bsp
decl_stmt|;
name|unsigned
name|long
name|bspstore
decl_stmt|;
name|unsigned
name|long
name|rnat
decl_stmt|;
name|unsigned
name|long
name|rsv2
decl_stmt|;
name|unsigned
name|long
name|fcr
decl_stmt|;
name|unsigned
name|long
name|rsv3
index|[
literal|2
index|]
decl_stmt|;
name|unsigned
name|long
name|eflag
decl_stmt|;
name|unsigned
name|long
name|csd
decl_stmt|;
name|unsigned
name|long
name|ssd
decl_stmt|;
name|unsigned
name|long
name|cflg
decl_stmt|;
name|unsigned
name|long
name|fsr
decl_stmt|;
name|unsigned
name|long
name|fir
decl_stmt|;
name|unsigned
name|long
name|fdr
decl_stmt|;
name|unsigned
name|long
name|rsv4
decl_stmt|;
name|unsigned
name|long
name|ccv
decl_stmt|;
comment|/* 32 */
name|unsigned
name|long
name|rsv5
index|[
literal|3
index|]
decl_stmt|;
name|unsigned
name|long
name|unat
decl_stmt|;
name|unsigned
name|long
name|rsv6
index|[
literal|3
index|]
decl_stmt|;
name|unsigned
name|long
name|fpsr
decl_stmt|;
name|unsigned
name|long
name|rsv7
index|[
literal|3
index|]
decl_stmt|;
name|unsigned
name|long
name|itc
decl_stmt|;
name|unsigned
name|long
name|rsv8
index|[
literal|3
index|]
decl_stmt|;
name|unsigned
name|long
name|ign1
index|[
literal|16
index|]
decl_stmt|;
name|unsigned
name|long
name|pfs
decl_stmt|;
comment|/* 64 */
name|unsigned
name|long
name|lc
decl_stmt|;
name|unsigned
name|long
name|ec
decl_stmt|;
name|unsigned
name|long
name|rsv9
index|[
literal|45
index|]
decl_stmt|;
name|unsigned
name|long
name|ign2
index|[
literal|16
index|]
decl_stmt|;
block|}
struct|;
block|}
union|;
end_union

begin_union
union|union
name|vcpu_cr_regs
block|{
name|unsigned
name|long
name|cr
index|[
literal|128
index|]
decl_stmt|;
struct|struct
block|{
name|unsigned
name|long
name|dcr
decl_stmt|;
comment|// CR0
name|unsigned
name|long
name|itm
decl_stmt|;
name|unsigned
name|long
name|iva
decl_stmt|;
name|unsigned
name|long
name|rsv1
index|[
literal|5
index|]
decl_stmt|;
name|unsigned
name|long
name|pta
decl_stmt|;
comment|// CR8
name|unsigned
name|long
name|rsv2
index|[
literal|7
index|]
decl_stmt|;
name|unsigned
name|long
name|ipsr
decl_stmt|;
comment|// CR16
name|unsigned
name|long
name|isr
decl_stmt|;
name|unsigned
name|long
name|rsv3
decl_stmt|;
name|unsigned
name|long
name|iip
decl_stmt|;
name|unsigned
name|long
name|ifa
decl_stmt|;
name|unsigned
name|long
name|itir
decl_stmt|;
name|unsigned
name|long
name|iipa
decl_stmt|;
name|unsigned
name|long
name|ifs
decl_stmt|;
name|unsigned
name|long
name|iim
decl_stmt|;
comment|// CR24
name|unsigned
name|long
name|iha
decl_stmt|;
name|unsigned
name|long
name|rsv4
index|[
literal|38
index|]
decl_stmt|;
name|unsigned
name|long
name|lid
decl_stmt|;
comment|// CR64
name|unsigned
name|long
name|ivr
decl_stmt|;
name|unsigned
name|long
name|tpr
decl_stmt|;
name|unsigned
name|long
name|eoi
decl_stmt|;
name|unsigned
name|long
name|irr
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|long
name|itv
decl_stmt|;
comment|// CR72
name|unsigned
name|long
name|pmv
decl_stmt|;
name|unsigned
name|long
name|cmcv
decl_stmt|;
name|unsigned
name|long
name|rsv5
index|[
literal|5
index|]
decl_stmt|;
name|unsigned
name|long
name|lrr0
decl_stmt|;
comment|// CR80
name|unsigned
name|long
name|lrr1
decl_stmt|;
name|unsigned
name|long
name|rsv6
index|[
literal|46
index|]
decl_stmt|;
block|}
struct|;
block|}
union|;
end_union

begin_struct
struct|struct
name|vcpu_guest_context_regs
block|{
name|unsigned
name|long
name|r
index|[
literal|32
index|]
decl_stmt|;
name|unsigned
name|long
name|b
index|[
literal|8
index|]
decl_stmt|;
name|unsigned
name|long
name|bank
index|[
literal|16
index|]
decl_stmt|;
name|unsigned
name|long
name|ip
decl_stmt|;
name|unsigned
name|long
name|psr
decl_stmt|;
name|unsigned
name|long
name|cfm
decl_stmt|;
name|unsigned
name|long
name|pr
decl_stmt|;
name|unsigned
name|int
name|nats
decl_stmt|;
comment|/* NaT bits for r1-r31.  */
name|unsigned
name|int
name|bnats
decl_stmt|;
comment|/* Nat bits for banked registers.  */
name|union
name|vcpu_ar_regs
name|ar
decl_stmt|;
name|union
name|vcpu_cr_regs
name|cr
decl_stmt|;
name|struct
name|pt_fpreg
name|f
index|[
literal|128
index|]
decl_stmt|;
name|unsigned
name|long
name|dbr
index|[
literal|8
index|]
decl_stmt|;
name|unsigned
name|long
name|ibr
index|[
literal|8
index|]
decl_stmt|;
name|unsigned
name|long
name|rr
index|[
literal|8
index|]
decl_stmt|;
name|unsigned
name|long
name|pkr
index|[
literal|16
index|]
decl_stmt|;
comment|/* FIXME: cpuid,pmd,pmc */
name|unsigned
name|long
name|xip
decl_stmt|;
name|unsigned
name|long
name|xpsr
decl_stmt|;
name|unsigned
name|long
name|xfs
decl_stmt|;
name|unsigned
name|long
name|xr
index|[
literal|4
index|]
decl_stmt|;
name|struct
name|vcpu_tr_regs
name|tr
decl_stmt|;
comment|/* Physical registers in case of debug event.  */
name|unsigned
name|long
name|excp_iipa
decl_stmt|;
name|unsigned
name|long
name|excp_ifa
decl_stmt|;
name|unsigned
name|long
name|excp_isr
decl_stmt|;
name|unsigned
name|int
name|excp_vector
decl_stmt|;
comment|/*          * The rbs is intended to be the image of the stacked registers still          * in the cpu (not yet stored in memory).  It is laid out as if it          * were written in memory at a 512 (64*8) aligned address + offset.          * rbs_voff is (offset / 8).  rbs_nat contains NaT bits for the          * remaining rbs registers.  rbs_rnat contains NaT bits for in memory          * rbs registers.          * Note: loadrs is 2**14 bytes == 2**11 slots.          */
name|unsigned
name|int
name|rbs_voff
decl_stmt|;
name|unsigned
name|long
name|rbs
index|[
literal|2048
index|]
decl_stmt|;
name|unsigned
name|long
name|rbs_rnat
decl_stmt|;
comment|/*          * RSE.N_STACKED_PHYS via PAL_RSE_INFO          * Strictly this isn't cpu context, but this value is necessary          * for domain save/restore. So is here.          */
name|unsigned
name|long
name|num_phys_stacked
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|vcpu_guest_context
block|{
define|#
directive|define
name|VGCF_EXTRA_REGS
value|(1UL<< 1)
comment|/* Set extra regs.  */
define|#
directive|define
name|VGCF_SET_CR_IRR
value|(1UL<< 2)
comment|/* Set cr_irr[0:3]. */
define|#
directive|define
name|VGCF_online
value|(1UL<< 3)
comment|/* make this vcpu online */
name|unsigned
name|long
name|flags
decl_stmt|;
comment|/* VGCF_* flags */
name|struct
name|vcpu_guest_context_regs
name|regs
decl_stmt|;
name|unsigned
name|long
name|event_callback_ip
decl_stmt|;
comment|/* xen doesn't share privregs pages with hvm domain so that this member      * doesn't make sense for hvm domain.      * ~0UL is already used for INVALID_P2M_ENTRY. */
define|#
directive|define
name|VGC_PRIVREGS_HVM
value|(~(-2UL))
name|unsigned
name|long
name|privregs_pfn
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
comment|/* dom0 vp op */
end_comment

begin_define
define|#
directive|define
name|__HYPERVISOR_ia64_dom0vp_op
value|__HYPERVISOR_arch_0
end_define

begin_comment
comment|/*  Map io space in machine address to dom0 physical address space.     Currently physical assigned address equals to machine address.  */
end_comment

begin_define
define|#
directive|define
name|IA64_DOM0VP_ioremap
value|0
end_define

begin_comment
comment|/* Convert a pseudo physical page frame number to the corresponding    machine page frame number. If no page is assigned, INVALID_MFN or    GPFN_INV_MASK is returned depending on domain's non-vti/vti mode.  */
end_comment

begin_define
define|#
directive|define
name|IA64_DOM0VP_phystomach
value|1
end_define

begin_comment
comment|/* Convert a machine page frame number to the corresponding pseudo physical    page frame number of the caller domain.  */
end_comment

begin_define
define|#
directive|define
name|IA64_DOM0VP_machtophys
value|3
end_define

begin_comment
comment|/* Reserved for future use.  */
end_comment

begin_define
define|#
directive|define
name|IA64_DOM0VP_iounmap
value|4
end_define

begin_comment
comment|/* Unmap and free pages contained in the specified pseudo physical region.  */
end_comment

begin_define
define|#
directive|define
name|IA64_DOM0VP_zap_physmap
value|5
end_define

begin_comment
comment|/* Assign machine page frame to dom0's pseudo physical address space.  */
end_comment

begin_define
define|#
directive|define
name|IA64_DOM0VP_add_physmap
value|6
end_define

begin_comment
comment|/* expose the p2m table into domain */
end_comment

begin_define
define|#
directive|define
name|IA64_DOM0VP_expose_p2m
value|7
end_define

begin_comment
comment|/* xen perfmon */
end_comment

begin_define
define|#
directive|define
name|IA64_DOM0VP_perfmon
value|8
end_define

begin_comment
comment|/* gmfn version of IA64_DOM0VP_add_physmap */
end_comment

begin_define
define|#
directive|define
name|IA64_DOM0VP_add_physmap_with_gmfn
value|9
end_define

begin_comment
comment|/* get fpswa revision */
end_comment

begin_define
define|#
directive|define
name|IA64_DOM0VP_fpswa_revision
value|10
end_define

begin_comment
comment|/* Add an I/O port space range */
end_comment

begin_define
define|#
directive|define
name|IA64_DOM0VP_add_io_space
value|11
end_define

begin_comment
comment|/* expose the foreign domain's p2m table into privileged domain */
end_comment

begin_define
define|#
directive|define
name|IA64_DOM0VP_expose_foreign_p2m
value|12
end_define

begin_define
define|#
directive|define
name|IA64_DOM0VP_EFP_ALLOC_PTE
value|0x1
end_define

begin_comment
comment|/* allocate p2m table */
end_comment

begin_comment
comment|/* unexpose the foreign domain's p2m table into privileged domain */
end_comment

begin_define
define|#
directive|define
name|IA64_DOM0VP_unexpose_foreign_p2m
value|13
end_define

begin_comment
comment|// flags for page assignement to pseudo physical address space
end_comment

begin_define
define|#
directive|define
name|_ASSIGN_readonly
value|0
end_define

begin_define
define|#
directive|define
name|ASSIGN_readonly
value|(1UL<< _ASSIGN_readonly)
end_define

begin_define
define|#
directive|define
name|ASSIGN_writable
value|(0UL<< _ASSIGN_readonly)
end_define

begin_comment
comment|// dummy flag
end_comment

begin_comment
comment|/* Internal only: memory attribute must be WC/UC/UCE.  */
end_comment

begin_define
define|#
directive|define
name|_ASSIGN_nocache
value|1
end_define

begin_define
define|#
directive|define
name|ASSIGN_nocache
value|(1UL<< _ASSIGN_nocache)
end_define

begin_comment
comment|// tlb tracking
end_comment

begin_define
define|#
directive|define
name|_ASSIGN_tlb_track
value|2
end_define

begin_define
define|#
directive|define
name|ASSIGN_tlb_track
value|(1UL<< _ASSIGN_tlb_track)
end_define

begin_comment
comment|/* Internal only: associated with PGC_allocated bit */
end_comment

begin_define
define|#
directive|define
name|_ASSIGN_pgc_allocated
value|3
end_define

begin_define
define|#
directive|define
name|ASSIGN_pgc_allocated
value|(1UL<< _ASSIGN_pgc_allocated)
end_define

begin_comment
comment|/* Page is an IO page.  */
end_comment

begin_define
define|#
directive|define
name|_ASSIGN_io
value|4
end_define

begin_define
define|#
directive|define
name|ASSIGN_io
value|(1UL<< _ASSIGN_io)
end_define

begin_comment
comment|/* This structure has the same layout of struct ia64_boot_param, defined in<asm/system.h>.  It is redefined here to ease use.  */
end_comment

begin_struct
struct|struct
name|xen_ia64_boot_param
block|{
name|unsigned
name|long
name|command_line
decl_stmt|;
comment|/* physical address of cmd line args */
name|unsigned
name|long
name|efi_systab
decl_stmt|;
comment|/* physical address of EFI system table */
name|unsigned
name|long
name|efi_memmap
decl_stmt|;
comment|/* physical address of EFI memory map */
name|unsigned
name|long
name|efi_memmap_size
decl_stmt|;
comment|/* size of EFI memory map */
name|unsigned
name|long
name|efi_memdesc_size
decl_stmt|;
comment|/* size of an EFI memory map descriptor */
name|unsigned
name|int
name|efi_memdesc_version
decl_stmt|;
comment|/* memory descriptor version */
struct|struct
block|{
name|unsigned
name|short
name|num_cols
decl_stmt|;
comment|/* number of columns on console.  */
name|unsigned
name|short
name|num_rows
decl_stmt|;
comment|/* number of rows on console.  */
name|unsigned
name|short
name|orig_x
decl_stmt|;
comment|/* cursor's x position */
name|unsigned
name|short
name|orig_y
decl_stmt|;
comment|/* cursor's y position */
block|}
name|console_info
struct|;
name|unsigned
name|long
name|fpswa
decl_stmt|;
comment|/* physical address of the fpswa interface */
name|unsigned
name|long
name|initrd_start
decl_stmt|;
name|unsigned
name|long
name|initrd_size
decl_stmt|;
name|unsigned
name|long
name|domain_start
decl_stmt|;
comment|/* va where the boot time domain begins */
name|unsigned
name|long
name|domain_size
decl_stmt|;
comment|/* how big is the boot domain */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !__ASSEMBLY__ */
end_comment

begin_comment
comment|/* Size of the shared_info area (this is not related to page size).  */
end_comment

begin_define
define|#
directive|define
name|XSI_SHIFT
value|14
end_define

begin_define
define|#
directive|define
name|XSI_SIZE
value|(1<< XSI_SHIFT)
end_define

begin_comment
comment|/* Log size of mapped_regs area (64 KB - only 4KB is used).  */
end_comment

begin_define
define|#
directive|define
name|XMAPPEDREGS_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|XMAPPEDREGS_SIZE
value|(1<< XMAPPEDREGS_SHIFT)
end_define

begin_comment
comment|/* Offset of XASI (Xen arch shared info) wrt XSI_BASE.  */
end_comment

begin_define
define|#
directive|define
name|XMAPPEDREGS_OFS
value|XSI_SIZE
end_define

begin_comment
comment|/* Hyperprivops.  */
end_comment

begin_define
define|#
directive|define
name|HYPERPRIVOP_START
value|0x1
end_define

begin_define
define|#
directive|define
name|HYPERPRIVOP_RFI
value|(HYPERPRIVOP_START + 0x0)
end_define

begin_define
define|#
directive|define
name|HYPERPRIVOP_RSM_DT
value|(HYPERPRIVOP_START + 0x1)
end_define

begin_define
define|#
directive|define
name|HYPERPRIVOP_SSM_DT
value|(HYPERPRIVOP_START + 0x2)
end_define

begin_define
define|#
directive|define
name|HYPERPRIVOP_COVER
value|(HYPERPRIVOP_START + 0x3)
end_define

begin_define
define|#
directive|define
name|HYPERPRIVOP_ITC_D
value|(HYPERPRIVOP_START + 0x4)
end_define

begin_define
define|#
directive|define
name|HYPERPRIVOP_ITC_I
value|(HYPERPRIVOP_START + 0x5)
end_define

begin_define
define|#
directive|define
name|HYPERPRIVOP_SSM_I
value|(HYPERPRIVOP_START + 0x6)
end_define

begin_define
define|#
directive|define
name|HYPERPRIVOP_GET_IVR
value|(HYPERPRIVOP_START + 0x7)
end_define

begin_define
define|#
directive|define
name|HYPERPRIVOP_GET_TPR
value|(HYPERPRIVOP_START + 0x8)
end_define

begin_define
define|#
directive|define
name|HYPERPRIVOP_SET_TPR
value|(HYPERPRIVOP_START + 0x9)
end_define

begin_define
define|#
directive|define
name|HYPERPRIVOP_EOI
value|(HYPERPRIVOP_START + 0xa)
end_define

begin_define
define|#
directive|define
name|HYPERPRIVOP_SET_ITM
value|(HYPERPRIVOP_START + 0xb)
end_define

begin_define
define|#
directive|define
name|HYPERPRIVOP_THASH
value|(HYPERPRIVOP_START + 0xc)
end_define

begin_define
define|#
directive|define
name|HYPERPRIVOP_PTC_GA
value|(HYPERPRIVOP_START + 0xd)
end_define

begin_define
define|#
directive|define
name|HYPERPRIVOP_ITR_D
value|(HYPERPRIVOP_START + 0xe)
end_define

begin_define
define|#
directive|define
name|HYPERPRIVOP_GET_RR
value|(HYPERPRIVOP_START + 0xf)
end_define

begin_define
define|#
directive|define
name|HYPERPRIVOP_SET_RR
value|(HYPERPRIVOP_START + 0x10)
end_define

begin_define
define|#
directive|define
name|HYPERPRIVOP_SET_KR
value|(HYPERPRIVOP_START + 0x11)
end_define

begin_define
define|#
directive|define
name|HYPERPRIVOP_FC
value|(HYPERPRIVOP_START + 0x12)
end_define

begin_define
define|#
directive|define
name|HYPERPRIVOP_GET_CPUID
value|(HYPERPRIVOP_START + 0x13)
end_define

begin_define
define|#
directive|define
name|HYPERPRIVOP_GET_PMD
value|(HYPERPRIVOP_START + 0x14)
end_define

begin_define
define|#
directive|define
name|HYPERPRIVOP_GET_EFLAG
value|(HYPERPRIVOP_START + 0x15)
end_define

begin_define
define|#
directive|define
name|HYPERPRIVOP_SET_EFLAG
value|(HYPERPRIVOP_START + 0x16)
end_define

begin_define
define|#
directive|define
name|HYPERPRIVOP_RSM_BE
value|(HYPERPRIVOP_START + 0x17)
end_define

begin_define
define|#
directive|define
name|HYPERPRIVOP_GET_PSR
value|(HYPERPRIVOP_START + 0x18)
end_define

begin_define
define|#
directive|define
name|HYPERPRIVOP_SET_RR0_TO_RR4
value|(HYPERPRIVOP_START + 0x19)
end_define

begin_define
define|#
directive|define
name|HYPERPRIVOP_MAX
value|(0x1a)
end_define

begin_comment
comment|/* Fast and light hypercalls.  */
end_comment

begin_define
define|#
directive|define
name|__HYPERVISOR_ia64_fast_eoi
value|__HYPERVISOR_arch_1
end_define

begin_comment
comment|/* Extra debug features.  */
end_comment

begin_define
define|#
directive|define
name|__HYPERVISOR_ia64_debug_op
value|__HYPERVISOR_arch_2
end_define

begin_comment
comment|/* Xencomm macros.  */
end_comment

begin_define
define|#
directive|define
name|XENCOMM_INLINE_MASK
value|0xf800000000000000UL
end_define

begin_define
define|#
directive|define
name|XENCOMM_INLINE_FLAG
value|0x8000000000000000UL
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|__ASSEMBLY__
end_ifndef

begin_comment
comment|/*  * Optimization features.  * The hypervisor may do some special optimizations for guests. This hypercall  * can be used to switch on/of these special optimizations.  */
end_comment

begin_define
define|#
directive|define
name|__HYPERVISOR_opt_feature
value|0x700UL
end_define

begin_define
define|#
directive|define
name|XEN_IA64_OPTF_OFF
value|0x0
end_define

begin_define
define|#
directive|define
name|XEN_IA64_OPTF_ON
value|0x1
end_define

begin_comment
comment|/*  * If this feature is switched on, the hypervisor inserts the  * tlb entries without calling the guests traphandler.  * This is useful in guests using region 7 for identity mapping  * like the linux kernel does.  */
end_comment

begin_define
define|#
directive|define
name|XEN_IA64_OPTF_IDENT_MAP_REG7
value|1
end_define

begin_comment
comment|/* Identity mapping of region 4 addresses in HVM. */
end_comment

begin_define
define|#
directive|define
name|XEN_IA64_OPTF_IDENT_MAP_REG4
value|2
end_define

begin_comment
comment|/* Identity mapping of region 5 addresses in HVM. */
end_comment

begin_define
define|#
directive|define
name|XEN_IA64_OPTF_IDENT_MAP_REG5
value|3
end_define

begin_define
define|#
directive|define
name|XEN_IA64_OPTF_IDENT_MAP_NOT_SET
value|(0)
end_define

begin_struct
struct|struct
name|xen_ia64_opt_feature
block|{
name|unsigned
name|long
name|cmd
decl_stmt|;
comment|/* Which feature */
name|unsigned
name|char
name|on
decl_stmt|;
comment|/* Switch feature on/off */
union|union
block|{
struct|struct
block|{
comment|/* The page protection bit mask of the pte. 			 	 * This will be or'ed with the pte. */
name|unsigned
name|long
name|pgprot
decl_stmt|;
name|unsigned
name|long
name|key
decl_stmt|;
comment|/* A protection key for itir. */
block|}
struct|;
block|}
union|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ASSEMBLY__ */
end_comment

begin_comment
comment|/* xen perfmon */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|XEN
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|__ASSEMBLY__
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|_ASM_IA64_PERFMON_H
end_ifndef

begin_include
include|#
directive|include
file|<xen/list.h>
end_include

begin_comment
comment|// asm/perfmon.h requires struct list_head
end_comment

begin_include
include|#
directive|include
file|<asm/perfmon.h>
end_include

begin_comment
comment|// for PFM_xxx and pfarg_features_t, pfarg_context_t, pfarg_reg_t, pfarg_load_t
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ASM_IA64_PERFMON_H */
end_comment

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|pfarg_features_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|pfarg_context_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|pfarg_reg_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|pfarg_load_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ASSEMBLY__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* XEN */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ASSEMBLY__
end_ifndef

begin_include
include|#
directive|include
file|"arch-ia64/hvm/memmap.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __HYPERVISOR_IF_IA64_H__ */
end_comment

begin_comment
comment|/*  * Local variables:  * mode: C  * c-set-style: "BSD"  * c-basic-offset: 4  * tab-width: 4  * indent-tabs-mode: nil  * End:  */
end_comment

end_unit

