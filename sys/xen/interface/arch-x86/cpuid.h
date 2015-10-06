begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  * arch-x86/cpuid.h  *   * CPUID interface to Xen.  *   * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to  * deal in the Software without restriction, including without limitation the  * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or  * sell copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER  * DEALINGS IN THE SOFTWARE.  *   * Copyright (c) 2007 Citrix Systems, Inc.  *   * Authors:  *    Keir Fraser<keir@xen.org>  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XEN_PUBLIC_ARCH_X86_CPUID_H__
end_ifndef

begin_define
define|#
directive|define
name|__XEN_PUBLIC_ARCH_X86_CPUID_H__
end_define

begin_comment
comment|/*  * For compatibility with other hypervisor interfaces, the Xen cpuid leaves  * can be found at the first otherwise unused 0x100 aligned boundary starting  * from 0x40000000.  *  * e.g If viridian extensions are enabled for an HVM domain, the Xen cpuid  * leaves will start at 0x40000100  */
end_comment

begin_define
define|#
directive|define
name|XEN_CPUID_FIRST_LEAF
value|0x40000000
end_define

begin_define
define|#
directive|define
name|XEN_CPUID_LEAF
parameter_list|(
name|i
parameter_list|)
value|(XEN_CPUID_FIRST_LEAF + (i))
end_define

begin_comment
comment|/*  * Leaf 1 (0x40000x00)  * EAX: Largest Xen-information leaf. All leaves up to an including @EAX  *      are supported by the Xen host.  * EBX-EDX: "XenVMMXenVMM" signature, allowing positive identification  *      of a Xen host.  */
end_comment

begin_define
define|#
directive|define
name|XEN_CPUID_SIGNATURE_EBX
value|0x566e6558
end_define

begin_comment
comment|/* "XenV" */
end_comment

begin_define
define|#
directive|define
name|XEN_CPUID_SIGNATURE_ECX
value|0x65584d4d
end_define

begin_comment
comment|/* "MMXe" */
end_comment

begin_define
define|#
directive|define
name|XEN_CPUID_SIGNATURE_EDX
value|0x4d4d566e
end_define

begin_comment
comment|/* "nVMM" */
end_comment

begin_comment
comment|/*  * Leaf 2 (0x40000x01)  * EAX[31:16]: Xen major version.  * EAX[15: 0]: Xen minor version.  * EBX-EDX: Reserved (currently all zeroes).  */
end_comment

begin_comment
comment|/*  * Leaf 3 (0x40000x02)  * EAX: Number of hypercall transfer pages. This register is always guaranteed  *      to specify one hypercall page.  * EBX: Base address of Xen-specific MSRs.  * ECX: Features 1. Unused bits are set to zero.  * EDX: Features 2. Unused bits are set to zero.  */
end_comment

begin_comment
comment|/* Does the host support MMU_PT_UPDATE_PRESERVE_AD for this guest? */
end_comment

begin_define
define|#
directive|define
name|_XEN_CPUID_FEAT1_MMU_PT_UPDATE_PRESERVE_AD
value|0
end_define

begin_define
define|#
directive|define
name|XEN_CPUID_FEAT1_MMU_PT_UPDATE_PRESERVE_AD
value|(1u<<0)
end_define

begin_comment
comment|/*  * Leaf 5 (0x40000x04)  * HVM-specific features  * EAX: Features  * EBX: vcpu id (iff EAX has XEN_HVM_CPUID_VCPU_ID_PRESENT flag)  */
end_comment

begin_define
define|#
directive|define
name|XEN_HVM_CPUID_APIC_ACCESS_VIRT
value|(1u<< 0)
end_define

begin_comment
comment|/* Virtualized APIC registers */
end_comment

begin_define
define|#
directive|define
name|XEN_HVM_CPUID_X2APIC_VIRT
value|(1u<< 1)
end_define

begin_comment
comment|/* Virtualized x2APIC accesses */
end_comment

begin_comment
comment|/* Memory mapped from other domains has valid IOMMU entries */
end_comment

begin_define
define|#
directive|define
name|XEN_HVM_CPUID_IOMMU_MAPPINGS
value|(1u<< 2)
end_define

begin_define
define|#
directive|define
name|XEN_HVM_CPUID_VCPU_ID_PRESENT
value|(1u<< 3)
end_define

begin_comment
comment|/* vcpu id is present in EBX */
end_comment

begin_define
define|#
directive|define
name|XEN_CPUID_MAX_NUM_LEAVES
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XEN_PUBLIC_ARCH_X86_CPUID_H__ */
end_comment

end_unit

