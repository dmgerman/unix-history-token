begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  * arch-ia64/hypervisor-if.h  *   * Guest OS interface to IA64 Xen.  *  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to  * deal in the Software without restriction, including without limitation the  * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or  * sell copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER  * DEALINGS IN THE SOFTWARE.  *  */
end_comment

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
name|__DEFINE_XEN_GUEST_HANDLE
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
name|__DEFINE_XEN_GUEST_HANDLE
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

begin_comment
comment|/* Guest handles for primitive C types. */
end_comment

begin_macro
name|__DEFINE_XEN_GUEST_HANDLE
argument_list|(
argument|uchar
argument_list|,
argument|unsigned char
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|__DEFINE_XEN_GUEST_HANDLE
argument_list|(
argument|uint
argument_list|,
argument|unsigned int
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|__DEFINE_XEN_GUEST_HANDLE
argument_list|(
argument|ulong
argument_list|,
argument|unsigned long
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|__DEFINE_XEN_GUEST_HANDLE
argument_list|(
argument|u64
argument_list|,
argument|unsigned long
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|char
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|int
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|long
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|void
argument_list|)
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|unsigned
name|long
name|xen_pfn_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_pfn_t
argument_list|)
expr_stmt|;
end_expr_stmt

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

begin_define
define|#
directive|define
name|INVALID_MFN
value|(~0UL)
end_define

begin_define
define|#
directive|define
name|MEM_G
value|(1UL<< 30)
end_define

begin_define
define|#
directive|define
name|MEM_M
value|(1UL<< 20)
end_define

begin_define
define|#
directive|define
name|MEM_K
value|(1UL<< 10)
end_define

begin_define
define|#
directive|define
name|MMIO_START
value|(3 * MEM_G)
end_define

begin_define
define|#
directive|define
name|MMIO_SIZE
value|(512 * MEM_M)
end_define

begin_define
define|#
directive|define
name|VGA_IO_START
value|0xA0000UL
end_define

begin_define
define|#
directive|define
name|VGA_IO_SIZE
value|0x20000
end_define

begin_define
define|#
directive|define
name|LEGACY_IO_START
value|(MMIO_START + MMIO_SIZE)
end_define

begin_define
define|#
directive|define
name|LEGACY_IO_SIZE
value|(64*MEM_M)
end_define

begin_define
define|#
directive|define
name|IO_PAGE_START
value|(LEGACY_IO_START + LEGACY_IO_SIZE)
end_define

begin_define
define|#
directive|define
name|IO_PAGE_SIZE
value|PAGE_SIZE
end_define

begin_define
define|#
directive|define
name|STORE_PAGE_START
value|(IO_PAGE_START + IO_PAGE_SIZE)
end_define

begin_define
define|#
directive|define
name|STORE_PAGE_SIZE
value|PAGE_SIZE
end_define

begin_define
define|#
directive|define
name|BUFFER_IO_PAGE_START
value|(STORE_PAGE_START+STORE_PAGE_SIZE)
end_define

begin_define
define|#
directive|define
name|BUFFER_IO_PAGE_SIZE
value|PAGE_SIZE
end_define

begin_define
define|#
directive|define
name|BUFFER_PIO_PAGE_START
value|(BUFFER_IO_PAGE_START+BUFFER_IO_PAGE_SIZE)
end_define

begin_define
define|#
directive|define
name|BUFFER_PIO_PAGE_SIZE
value|PAGE_SIZE
end_define

begin_define
define|#
directive|define
name|IO_SAPIC_START
value|0xfec00000UL
end_define

begin_define
define|#
directive|define
name|IO_SAPIC_SIZE
value|0x100000
end_define

begin_define
define|#
directive|define
name|PIB_START
value|0xfee00000UL
end_define

begin_define
define|#
directive|define
name|PIB_SIZE
value|0x200000
end_define

begin_define
define|#
directive|define
name|GFW_START
value|(4*MEM_G -16*MEM_M)
end_define

begin_define
define|#
directive|define
name|GFW_SIZE
value|(16*MEM_M)
end_define

begin_comment
comment|/* Nvram belongs to GFW memory space  */
end_comment

begin_define
define|#
directive|define
name|NVRAM_SIZE
value|(MEM_K * 64)
end_define

begin_define
define|#
directive|define
name|NVRAM_START
value|(GFW_START + 10 * MEM_M)
end_define

begin_define
define|#
directive|define
name|NVRAM_VALID_SIG
value|0x4650494e45584948
end_define

begin_comment
comment|// "HIXENIPF"
end_comment

begin_struct
struct|struct
name|nvram_save_addr
block|{
name|unsigned
name|long
name|addr
decl_stmt|;
name|unsigned
name|long
name|signature
decl_stmt|;
block|}
struct|;
end_struct

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

begin_struct
struct|struct
name|cpu_user_regs
block|{
comment|/* The following registers are saved by SAVE_MIN: */
name|unsigned
name|long
name|b6
decl_stmt|;
comment|/* scratch */
name|unsigned
name|long
name|b7
decl_stmt|;
comment|/* scratch */
name|unsigned
name|long
name|ar_csd
decl_stmt|;
comment|/* used by cmp8xchg16 (scratch) */
name|unsigned
name|long
name|ar_ssd
decl_stmt|;
comment|/* reserved for future use (scratch) */
name|unsigned
name|long
name|r8
decl_stmt|;
comment|/* scratch (return value register 0) */
name|unsigned
name|long
name|r9
decl_stmt|;
comment|/* scratch (return value register 1) */
name|unsigned
name|long
name|r10
decl_stmt|;
comment|/* scratch (return value register 2) */
name|unsigned
name|long
name|r11
decl_stmt|;
comment|/* scratch (return value register 3) */
name|unsigned
name|long
name|cr_ipsr
decl_stmt|;
comment|/* interrupted task's psr */
name|unsigned
name|long
name|cr_iip
decl_stmt|;
comment|/* interrupted task's instruction pointer */
name|unsigned
name|long
name|cr_ifs
decl_stmt|;
comment|/* interrupted task's function state */
name|unsigned
name|long
name|ar_unat
decl_stmt|;
comment|/* interrupted task's NaT register (preserved) */
name|unsigned
name|long
name|ar_pfs
decl_stmt|;
comment|/* prev function state  */
name|unsigned
name|long
name|ar_rsc
decl_stmt|;
comment|/* RSE configuration */
comment|/* The following two are valid only if cr_ipsr.cpl> 0: */
name|unsigned
name|long
name|ar_rnat
decl_stmt|;
comment|/* RSE NaT */
name|unsigned
name|long
name|ar_bspstore
decl_stmt|;
comment|/* RSE bspstore */
name|unsigned
name|long
name|pr
decl_stmt|;
comment|/* 64 predicate registers (1 bit each) */
name|unsigned
name|long
name|b0
decl_stmt|;
comment|/* return pointer (bp) */
name|unsigned
name|long
name|loadrs
decl_stmt|;
comment|/* size of dirty partition<< 16 */
name|unsigned
name|long
name|r1
decl_stmt|;
comment|/* the gp pointer */
name|unsigned
name|long
name|r12
decl_stmt|;
comment|/* interrupted task's memory stack pointer */
name|unsigned
name|long
name|r13
decl_stmt|;
comment|/* thread pointer */
name|unsigned
name|long
name|ar_fpsr
decl_stmt|;
comment|/* floating point status (preserved) */
name|unsigned
name|long
name|r15
decl_stmt|;
comment|/* scratch */
comment|/* The remaining registers are NOT saved for system calls.  */
name|unsigned
name|long
name|r14
decl_stmt|;
comment|/* scratch */
name|unsigned
name|long
name|r2
decl_stmt|;
comment|/* scratch */
name|unsigned
name|long
name|r3
decl_stmt|;
comment|/* scratch */
name|unsigned
name|long
name|r16
decl_stmt|;
comment|/* scratch */
name|unsigned
name|long
name|r17
decl_stmt|;
comment|/* scratch */
name|unsigned
name|long
name|r18
decl_stmt|;
comment|/* scratch */
name|unsigned
name|long
name|r19
decl_stmt|;
comment|/* scratch */
name|unsigned
name|long
name|r20
decl_stmt|;
comment|/* scratch */
name|unsigned
name|long
name|r21
decl_stmt|;
comment|/* scratch */
name|unsigned
name|long
name|r22
decl_stmt|;
comment|/* scratch */
name|unsigned
name|long
name|r23
decl_stmt|;
comment|/* scratch */
name|unsigned
name|long
name|r24
decl_stmt|;
comment|/* scratch */
name|unsigned
name|long
name|r25
decl_stmt|;
comment|/* scratch */
name|unsigned
name|long
name|r26
decl_stmt|;
comment|/* scratch */
name|unsigned
name|long
name|r27
decl_stmt|;
comment|/* scratch */
name|unsigned
name|long
name|r28
decl_stmt|;
comment|/* scratch */
name|unsigned
name|long
name|r29
decl_stmt|;
comment|/* scratch */
name|unsigned
name|long
name|r30
decl_stmt|;
comment|/* scratch */
name|unsigned
name|long
name|r31
decl_stmt|;
comment|/* scratch */
name|unsigned
name|long
name|ar_ccv
decl_stmt|;
comment|/* compare/exchange value (scratch) */
comment|/*      * Floating point registers that the kernel considers scratch:      */
name|struct
name|pt_fpreg
name|f6
decl_stmt|;
comment|/* scratch */
name|struct
name|pt_fpreg
name|f7
decl_stmt|;
comment|/* scratch */
name|struct
name|pt_fpreg
name|f8
decl_stmt|;
comment|/* scratch */
name|struct
name|pt_fpreg
name|f9
decl_stmt|;
comment|/* scratch */
name|struct
name|pt_fpreg
name|f10
decl_stmt|;
comment|/* scratch */
name|struct
name|pt_fpreg
name|f11
decl_stmt|;
comment|/* scratch */
name|unsigned
name|long
name|r4
decl_stmt|;
comment|/* preserved */
name|unsigned
name|long
name|r5
decl_stmt|;
comment|/* preserved */
name|unsigned
name|long
name|r6
decl_stmt|;
comment|/* preserved */
name|unsigned
name|long
name|r7
decl_stmt|;
comment|/* preserved */
name|unsigned
name|long
name|eml_unat
decl_stmt|;
comment|/* used for emulating instruction */
name|unsigned
name|long
name|pad0
decl_stmt|;
comment|/* alignment pad */
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
name|pkrs
index|[
literal|8
index|]
decl_stmt|;
comment|// protection key registers
name|unsigned
name|long
name|tmp
index|[
literal|8
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

begin_struct
struct|struct
name|vcpu_extra_regs
block|{
name|struct
name|ia64_tr_entry
name|itrs
index|[
literal|8
index|]
decl_stmt|;
name|struct
name|ia64_tr_entry
name|dtrs
index|[
literal|8
index|]
decl_stmt|;
name|unsigned
name|long
name|iva
decl_stmt|;
name|unsigned
name|long
name|dcr
decl_stmt|;
name|unsigned
name|long
name|event_callback_ip
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
value|(1<<1)
comment|/* Get/Set extra regs.  */
name|unsigned
name|long
name|flags
decl_stmt|;
comment|/* VGCF_* flags */
name|struct
name|cpu_user_regs
name|user_regs
decl_stmt|;
name|struct
name|vcpu_extra_regs
name|extra_regs
decl_stmt|;
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
comment|/* Add an I/O port space range */
end_comment

begin_define
define|#
directive|define
name|IA64_DOM0VP_add_io_space
value|11
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
name|HYPERPRIVOP_MAX
value|(0x19)
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

begin_define
define|#
directive|define
name|XENCOMM_IS_INLINE
parameter_list|(
name|addr
parameter_list|)
define|\
value|(((unsigned long)(addr)& XENCOMM_INLINE_MASK) == XENCOMM_INLINE_FLAG)
end_define

begin_define
define|#
directive|define
name|XENCOMM_INLINE_ADDR
parameter_list|(
name|addr
parameter_list|)
define|\
value|((unsigned long)(addr)& ~XENCOMM_INLINE_MASK)
end_define

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

