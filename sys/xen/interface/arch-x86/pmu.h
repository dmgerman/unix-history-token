begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to  * deal in the Software without restriction, including without limitation the  * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or  * sell copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER  * DEALINGS IN THE SOFTWARE.  *  * Copyright (c) 2015 Oracle and/or its affiliates. All rights reserved.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XEN_PUBLIC_ARCH_X86_PMU_H__
end_ifndef

begin_define
define|#
directive|define
name|__XEN_PUBLIC_ARCH_X86_PMU_H__
end_define

begin_comment
comment|/* x86-specific PMU definitions */
end_comment

begin_comment
comment|/* AMD PMU registers and structures */
end_comment

begin_struct
struct|struct
name|xen_pmu_amd_ctxt
block|{
comment|/*      * Offsets to counter and control MSRs (relative to xen_pmu_arch.c.amd).      * For PV(H) guests these fields are RO.      */
name|uint32_t
name|counters
decl_stmt|;
name|uint32_t
name|ctrls
decl_stmt|;
comment|/* Counter MSRs */
if|#
directive|if
name|defined
argument_list|(
name|__STDC_VERSION__
argument_list|)
operator|&&
name|__STDC_VERSION__
operator|>=
literal|199901L
name|uint64_t
name|regs
index|[]
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__GNUC__
argument_list|)
name|uint64_t
name|regs
index|[
literal|0
index|]
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_pmu_amd_ctxt
name|xen_pmu_amd_ctxt_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_pmu_amd_ctxt_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Intel PMU registers and structures */
end_comment

begin_struct
struct|struct
name|xen_pmu_cntr_pair
block|{
name|uint64_t
name|counter
decl_stmt|;
name|uint64_t
name|control
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_pmu_cntr_pair
name|xen_pmu_cntr_pair_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_pmu_cntr_pair_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|xen_pmu_intel_ctxt
block|{
comment|/*     * Offsets to fixed and architectural counter MSRs (relative to     * xen_pmu_arch.c.intel).     * For PV(H) guests these fields are RO.     */
name|uint32_t
name|fixed_counters
decl_stmt|;
name|uint32_t
name|arch_counters
decl_stmt|;
comment|/* PMU registers */
name|uint64_t
name|global_ctrl
decl_stmt|;
name|uint64_t
name|global_ovf_ctrl
decl_stmt|;
name|uint64_t
name|global_status
decl_stmt|;
name|uint64_t
name|fixed_ctrl
decl_stmt|;
name|uint64_t
name|ds_area
decl_stmt|;
name|uint64_t
name|pebs_enable
decl_stmt|;
name|uint64_t
name|debugctl
decl_stmt|;
comment|/* Fixed and architectural counter MSRs */
if|#
directive|if
name|defined
argument_list|(
name|__STDC_VERSION__
argument_list|)
operator|&&
name|__STDC_VERSION__
operator|>=
literal|199901L
name|uint64_t
name|regs
index|[]
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__GNUC__
argument_list|)
name|uint64_t
name|regs
index|[
literal|0
index|]
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_pmu_intel_ctxt
name|xen_pmu_intel_ctxt_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_pmu_intel_ctxt_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Sampled domain's registers */
end_comment

begin_struct
struct|struct
name|xen_pmu_regs
block|{
name|uint64_t
name|ip
decl_stmt|;
name|uint64_t
name|sp
decl_stmt|;
name|uint64_t
name|flags
decl_stmt|;
name|uint16_t
name|cs
decl_stmt|;
name|uint16_t
name|ss
decl_stmt|;
name|uint8_t
name|cpl
decl_stmt|;
name|uint8_t
name|pad
index|[
literal|3
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_pmu_regs
name|xen_pmu_regs_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_pmu_regs_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* PMU flags */
end_comment

begin_define
define|#
directive|define
name|PMU_CACHED
value|(1<<0)
end_define

begin_comment
comment|/* PMU MSRs are cached in the context */
end_comment

begin_define
define|#
directive|define
name|PMU_SAMPLE_USER
value|(1<<1)
end_define

begin_comment
comment|/* Sample is from user or kernel mode */
end_comment

begin_define
define|#
directive|define
name|PMU_SAMPLE_REAL
value|(1<<2)
end_define

begin_comment
comment|/* Sample is from realmode */
end_comment

begin_define
define|#
directive|define
name|PMU_SAMPLE_PV
value|(1<<3)
end_define

begin_comment
comment|/* Sample from a PV guest */
end_comment

begin_comment
comment|/*  * Architecture-specific information describing state of the processor at  * the time of PMU interrupt.  * Fields of this structure marked as RW for guest should only be written by  * the guest when PMU_CACHED bit in pmu_flags is set (which is done by the  * hypervisor during PMU interrupt). Hypervisor will read updated data in  * XENPMU_flush hypercall and clear PMU_CACHED bit.  */
end_comment

begin_struct
struct|struct
name|xen_pmu_arch
block|{
union|union
block|{
comment|/*          * Processor's registers at the time of interrupt.          * WO for hypervisor, RO for guests.          */
name|struct
name|xen_pmu_regs
name|regs
decl_stmt|;
comment|/* Padding for adding new registers to xen_pmu_regs in the future */
define|#
directive|define
name|XENPMU_REGS_PAD_SZ
value|64
name|uint8_t
name|pad
index|[
name|XENPMU_REGS_PAD_SZ
index|]
decl_stmt|;
block|}
name|r
union|;
comment|/* WO for hypervisor, RO for guest */
name|uint64_t
name|pmu_flags
decl_stmt|;
comment|/*      * APIC LVTPC register.      * RW for both hypervisor and guest.      * Only APIC_LVT_MASKED bit is loaded by the hypervisor into hardware      * during XENPMU_flush or XENPMU_lvtpc_set.      */
union|union
block|{
name|uint32_t
name|lapic_lvtpc
decl_stmt|;
name|uint64_t
name|pad
decl_stmt|;
block|}
name|l
union|;
comment|/*      * Vendor-specific PMU registers.      * RW for both hypervisor and guest (see exceptions above).      * Guest's updates to this field are verified and then loaded by the      * hypervisor into hardware during XENPMU_flush      */
union|union
block|{
name|struct
name|xen_pmu_amd_ctxt
name|amd
decl_stmt|;
name|struct
name|xen_pmu_intel_ctxt
name|intel
decl_stmt|;
comment|/*          * Padding for contexts (fixed parts only, does not include MSR banks          * that are specified by offsets)          */
define|#
directive|define
name|XENPMU_CTXT_PAD_SZ
value|128
name|uint8_t
name|pad
index|[
name|XENPMU_CTXT_PAD_SZ
index|]
decl_stmt|;
block|}
name|c
union|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_pmu_arch
name|xen_pmu_arch_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_pmu_arch_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XEN_PUBLIC_ARCH_X86_PMU_H__ */
end_comment

begin_comment
comment|/*  * Local variables:  * mode: C  * c-file-style: "BSD"  * c-basic-offset: 4  * tab-width: 4  * indent-tabs-mode: nil  * End:  */
end_comment

end_unit

