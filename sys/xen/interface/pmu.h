begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to  * deal in the Software without restriction, including without limitation the  * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or  * sell copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER  * DEALINGS IN THE SOFTWARE.  *  * Copyright (c) 2015 Oracle and/or its affiliates. All rights reserved.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XEN_PUBLIC_PMU_H__
end_ifndef

begin_define
define|#
directive|define
name|__XEN_PUBLIC_PMU_H__
end_define

begin_include
include|#
directive|include
file|"xen.h"
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__i386__
argument_list|)
operator|||
name|defined
argument_list|(
name|__x86_64__
argument_list|)
end_if

begin_include
include|#
directive|include
file|"arch-x86/pmu.h"
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__arm__
argument_list|)
operator|||
name|defined
argument_list|(
name|__aarch64__
argument_list|)
end_elif

begin_include
include|#
directive|include
file|"arch-arm.h"
end_include

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
literal|"Unsupported architecture"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|XENPMU_VER_MAJ
value|0
end_define

begin_define
define|#
directive|define
name|XENPMU_VER_MIN
value|1
end_define

begin_comment
comment|/*  * ` enum neg_errnoval  * ` HYPERVISOR_xenpmu_op(enum xenpmu_op cmd, struct xenpmu_params *args);  *  * @cmd  == XENPMU_* (PMU operation)  * @args == struct xenpmu_params  */
end_comment

begin_comment
comment|/* ` enum xenpmu_op { */
end_comment

begin_define
define|#
directive|define
name|XENPMU_mode_get
value|0
end_define

begin_comment
comment|/* Also used for getting PMU version */
end_comment

begin_define
define|#
directive|define
name|XENPMU_mode_set
value|1
end_define

begin_define
define|#
directive|define
name|XENPMU_feature_get
value|2
end_define

begin_define
define|#
directive|define
name|XENPMU_feature_set
value|3
end_define

begin_define
define|#
directive|define
name|XENPMU_init
value|4
end_define

begin_define
define|#
directive|define
name|XENPMU_finish
value|5
end_define

begin_define
define|#
directive|define
name|XENPMU_lvtpc_set
value|6
end_define

begin_define
define|#
directive|define
name|XENPMU_flush
value|7
end_define

begin_comment
comment|/* Write cached MSR values to HW     */
end_comment

begin_comment
comment|/* ` } */
end_comment

begin_comment
comment|/* Parameters structure for HYPERVISOR_xenpmu_op call */
end_comment

begin_struct
struct|struct
name|xen_pmu_params
block|{
comment|/* IN/OUT parameters */
struct|struct
block|{
name|uint32_t
name|maj
decl_stmt|;
name|uint32_t
name|min
decl_stmt|;
block|}
name|version
struct|;
name|uint64_t
name|val
decl_stmt|;
comment|/* IN parameters */
name|uint32_t
name|vcpu
decl_stmt|;
name|uint32_t
name|pad
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_pmu_params
name|xen_pmu_params_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_pmu_params_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* PMU modes:  * - XENPMU_MODE_OFF:   No PMU virtualization  * - XENPMU_MODE_SELF:  Guests can profile themselves  * - XENPMU_MODE_HV:    Guests can profile themselves, dom0 profiles  *                      itself and Xen  * - XENPMU_MODE_ALL:   Only dom0 has access to VPMU and it profiles  *                      everyone: itself, the hypervisor and the guests.  */
end_comment

begin_define
define|#
directive|define
name|XENPMU_MODE_OFF
value|0
end_define

begin_define
define|#
directive|define
name|XENPMU_MODE_SELF
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|XENPMU_MODE_HV
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|XENPMU_MODE_ALL
value|(1<<2)
end_define

begin_comment
comment|/*  * PMU features:  * - XENPMU_FEATURE_INTEL_BTS: Intel BTS support (ignored on AMD)  */
end_comment

begin_define
define|#
directive|define
name|XENPMU_FEATURE_INTEL_BTS
value|1
end_define

begin_comment
comment|/*  * Shared PMU data between hypervisor and PV(H) domains.  *  * The hypervisor fills out this structure during PMU interrupt and sends an  * interrupt to appropriate VCPU.  * Architecture-independent fields of xen_pmu_data are WO for the hypervisor  * and RO for the guest but some fields in xen_pmu_arch can be writable  * by both the hypervisor and the guest (see arch-$arch/pmu.h).  */
end_comment

begin_struct
struct|struct
name|xen_pmu_data
block|{
comment|/* Interrupted VCPU */
name|uint32_t
name|vcpu_id
decl_stmt|;
comment|/*      * Physical processor on which the interrupt occurred. On non-privileged      * guests set to vcpu_id;      */
name|uint32_t
name|pcpu_id
decl_stmt|;
comment|/*      * Domain that was interrupted. On non-privileged guests set to DOMID_SELF.      * On privileged guests can be DOMID_SELF, DOMID_XEN, or, when in      * XENPMU_MODE_ALL mode, domain ID of another domain.      */
name|domid_t
name|domain_id
decl_stmt|;
name|uint8_t
name|pad
index|[
literal|6
index|]
decl_stmt|;
comment|/* Architecture-specific information */
name|struct
name|xen_pmu_arch
name|pmu
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XEN_PUBLIC_PMU_H__ */
end_comment

begin_comment
comment|/*  * Local variables:  * mode: C  * c-file-style: "BSD"  * c-basic-offset: 4  * tab-width: 4  * indent-tabs-mode: nil  * End:  */
end_comment

end_unit

