begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  * features.h  *   * Feature flags, reported by XENVER_get_features.  *   * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to  * deal in the Software without restriction, including without limitation the  * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or  * sell copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER  * DEALINGS IN THE SOFTWARE.  *  * Copyright (c) 2006, Keir Fraser<keir@xensource.com>  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XEN_PUBLIC_FEATURES_H__
end_ifndef

begin_define
define|#
directive|define
name|__XEN_PUBLIC_FEATURES_H__
end_define

begin_comment
comment|/*  * If set, the guest does not need to write-protect its pagetables, and can  * update them via direct writes.  */
end_comment

begin_define
define|#
directive|define
name|XENFEAT_writable_page_tables
value|0
end_define

begin_comment
comment|/*  * If set, the guest does not need to write-protect its segment descriptor  * tables, and can update them via direct writes.  */
end_comment

begin_define
define|#
directive|define
name|XENFEAT_writable_descriptor_tables
value|1
end_define

begin_comment
comment|/*  * If set, translation between the guest's 'pseudo-physical' address space  * and the host's machine address space are handled by the hypervisor. In this  * mode the guest does not need to perform phys-to/from-machine translations  * when performing page table operations.  */
end_comment

begin_define
define|#
directive|define
name|XENFEAT_auto_translated_physmap
value|2
end_define

begin_comment
comment|/* If set, the guest is running in supervisor mode (e.g., x86 ring 0). */
end_comment

begin_define
define|#
directive|define
name|XENFEAT_supervisor_mode_kernel
value|3
end_define

begin_comment
comment|/*  * If set, the guest does not need to allocate x86 PAE page directories  * below 4GB. This flag is usually implied by auto_translated_physmap.  */
end_comment

begin_define
define|#
directive|define
name|XENFEAT_pae_pgdir_above_4gb
value|4
end_define

begin_comment
comment|/* x86: Does this Xen host support the MMU_PT_UPDATE_PRESERVE_AD hypercall? */
end_comment

begin_define
define|#
directive|define
name|XENFEAT_mmu_pt_update_preserve_ad
value|5
end_define

begin_define
define|#
directive|define
name|XENFEAT_NR_SUBMAPS
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XEN_PUBLIC_FEATURES_H__ */
end_comment

begin_comment
comment|/*  * Local variables:  * mode: C  * c-set-style: "BSD"  * c-basic-offset: 4  * tab-width: 4  * indent-tabs-mode: nil  * End:  */
end_comment

end_unit

