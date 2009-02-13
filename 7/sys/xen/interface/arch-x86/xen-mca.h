begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  * arch-x86/mca.h  *   * Contributed by Advanced Micro Devices, Inc.  * Author: Christoph Egger<Christoph.Egger@amd.com>  *  * Guest OS machine check interface to x86 Xen.  *   * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to  * deal in the Software without restriction, including without limitation the  * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or  * sell copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER  * DEALINGS IN THE SOFTWARE.  */
end_comment

begin_comment
comment|/* Full MCA functionality has the following Usecases from the guest side:  *  * Must have's:  * 1. Dom0 and DomU register machine check trap callback handlers  *    (already done via "set_trap_table" hypercall)  * 2. Dom0 registers machine check event callback handler  *    (doable via EVTCHNOP_bind_virq)  * 3. Dom0 and DomU fetches machine check data  * 4. Dom0 wants Xen to notify a DomU  * 5. Dom0 gets DomU ID from physical address  * 6. Dom0 wants Xen to kill DomU (already done for "xm destroy")  *  * Nice to have's:  * 7. Dom0 wants Xen to deactivate a physical CPU  *    This is better done as separate task, physical CPU hotplugging,  *    and hypercall(s) should be sysctl's  * 8. Page migration proposed from Xen NUMA work, where Dom0 can tell Xen to  *    move a DomU (or Dom0 itself) away from a malicious page  *    producing correctable errors.  * 9. offlining physical page:  *    Xen free's and never re-uses a certain physical page.  * 10. Testfacility: Allow Dom0 to write values into machine check MSR's  *     and tell Xen to trigger a machine check  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XEN_PUBLIC_ARCH_X86_MCA_H__
end_ifndef

begin_define
define|#
directive|define
name|__XEN_PUBLIC_ARCH_X86_MCA_H__
end_define

begin_comment
comment|/* Hypercall */
end_comment

begin_define
define|#
directive|define
name|__HYPERVISOR_mca
value|__HYPERVISOR_arch_0
end_define

begin_define
define|#
directive|define
name|XEN_MCA_INTERFACE_VERSION
value|0x03000001
end_define

begin_comment
comment|/* IN: Dom0 calls hypercall from MC event handler. */
end_comment

begin_define
define|#
directive|define
name|XEN_MC_CORRECTABLE
value|0x0
end_define

begin_comment
comment|/* IN: Dom0/DomU calls hypercall from MC trap handler. */
end_comment

begin_define
define|#
directive|define
name|XEN_MC_TRAP
value|0x1
end_define

begin_comment
comment|/* XEN_MC_CORRECTABLE and XEN_MC_TRAP are mutually exclusive. */
end_comment

begin_comment
comment|/* OUT: All is ok */
end_comment

begin_define
define|#
directive|define
name|XEN_MC_OK
value|0x0
end_define

begin_comment
comment|/* OUT: Domain could not fetch data. */
end_comment

begin_define
define|#
directive|define
name|XEN_MC_FETCHFAILED
value|0x1
end_define

begin_comment
comment|/* OUT: There was no machine check data to fetch. */
end_comment

begin_define
define|#
directive|define
name|XEN_MC_NODATA
value|0x2
end_define

begin_comment
comment|/* OUT: Between notification time and this hypercall an other  *  (most likely) correctable error happened. The fetched data,  *  does not match the original machine check data. */
end_comment

begin_define
define|#
directive|define
name|XEN_MC_NOMATCH
value|0x4
end_define

begin_comment
comment|/* OUT: DomU did not register MC NMI handler. Try something else. */
end_comment

begin_define
define|#
directive|define
name|XEN_MC_CANNOTHANDLE
value|0x8
end_define

begin_comment
comment|/* OUT: Notifying DomU failed. Retry later or try something else. */
end_comment

begin_define
define|#
directive|define
name|XEN_MC_NOTDELIVERED
value|0x10
end_define

begin_comment
comment|/* Note, XEN_MC_CANNOTHANDLE and XEN_MC_NOTDELIVERED are mutually exclusive. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ASSEMBLY__
end_ifndef

begin_define
define|#
directive|define
name|VIRQ_MCA
value|VIRQ_ARCH_0
end_define

begin_comment
comment|/* G. (DOM0) Machine Check Architecture */
end_comment

begin_comment
comment|/*  * Machine Check Architecure:  * structs are read-only and used to report all kinds of  * correctable and uncorrectable errors detected by the HW.  * Dom0 and DomU: register a handler to get notified.  * Dom0 only: Correctable errors are reported via VIRQ_MCA  * Dom0 and DomU: Uncorrectable errors are reported via nmi handlers  */
end_comment

begin_define
define|#
directive|define
name|MC_TYPE_GLOBAL
value|0
end_define

begin_define
define|#
directive|define
name|MC_TYPE_BANK
value|1
end_define

begin_define
define|#
directive|define
name|MC_TYPE_EXTENDED
value|2
end_define

begin_struct
struct|struct
name|mcinfo_common
block|{
name|uint16_t
name|type
decl_stmt|;
comment|/* structure type */
name|uint16_t
name|size
decl_stmt|;
comment|/* size of this struct in bytes */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MC_FLAG_CORRECTABLE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|MC_FLAG_UNCORRECTABLE
value|(1<< 1)
end_define

begin_comment
comment|/* contains global x86 mc information */
end_comment

begin_struct
struct|struct
name|mcinfo_global
block|{
name|struct
name|mcinfo_common
name|common
decl_stmt|;
comment|/* running domain at the time in error (most likely the impacted one) */
name|uint16_t
name|mc_domid
decl_stmt|;
name|uint32_t
name|mc_socketid
decl_stmt|;
comment|/* physical socket of the physical core */
name|uint16_t
name|mc_coreid
decl_stmt|;
comment|/* physical impacted core */
name|uint16_t
name|mc_core_threadid
decl_stmt|;
comment|/* core thread of physical core */
name|uint16_t
name|mc_vcpuid
decl_stmt|;
comment|/* virtual cpu scheduled for mc_domid */
name|uint64_t
name|mc_gstatus
decl_stmt|;
comment|/* global status */
name|uint32_t
name|mc_flags
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* contains bank local x86 mc information */
end_comment

begin_struct
struct|struct
name|mcinfo_bank
block|{
name|struct
name|mcinfo_common
name|common
decl_stmt|;
name|uint16_t
name|mc_bank
decl_stmt|;
comment|/* bank nr */
name|uint16_t
name|mc_domid
decl_stmt|;
comment|/* Usecase 5: domain referenced by mc_addr on dom0                         * and if mc_addr is valid. Never valid on DomU. */
name|uint64_t
name|mc_status
decl_stmt|;
comment|/* bank status */
name|uint64_t
name|mc_addr
decl_stmt|;
comment|/* bank address, only valid                          * if addr bit is set in mc_status */
name|uint64_t
name|mc_misc
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mcinfo_msr
block|{
name|uint64_t
name|reg
decl_stmt|;
comment|/* MSR */
name|uint64_t
name|value
decl_stmt|;
comment|/* MSR value */
block|}
struct|;
end_struct

begin_comment
comment|/* contains mc information from other  * or additional mc MSRs */
end_comment

begin_struct
struct|struct
name|mcinfo_extended
block|{
name|struct
name|mcinfo_common
name|common
decl_stmt|;
comment|/* You can fill up to five registers.      * If you need more, then use this structure      * multiple times. */
name|uint32_t
name|mc_msrs
decl_stmt|;
comment|/* Number of msr with valid values. */
name|struct
name|mcinfo_msr
name|mc_msr
index|[
literal|5
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MCINFO_HYPERCALLSIZE
value|1024
end_define

begin_define
define|#
directive|define
name|MCINFO_MAXSIZE
value|768
end_define

begin_struct
struct|struct
name|mc_info
block|{
comment|/* Number of mcinfo_* entries in mi_data */
name|uint32_t
name|mi_nentries
decl_stmt|;
name|uint8_t
name|mi_data
index|[
name|MCINFO_MAXSIZE
operator|-
sizeof|sizeof
argument_list|(
name|uint32_t
argument_list|)
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|mc_info
name|mc_info_t
typedef|;
end_typedef

begin_comment
comment|/*   * OS's should use these instead of writing their own lookup function  * each with its own bugs and drawbacks.  * We use macros instead of static inline functions to allow guests  * to include this header in assembly files (*.S).  */
end_comment

begin_comment
comment|/* Prototype:  *    uint32_t x86_mcinfo_nentries(struct mc_info *mi);  */
end_comment

begin_define
define|#
directive|define
name|x86_mcinfo_nentries
parameter_list|(
name|_mi
parameter_list|)
define|\
value|(_mi)->mi_nentries
end_define

begin_comment
comment|/* Prototype:  *    struct mcinfo_common *x86_mcinfo_first(struct mc_info *mi);  */
end_comment

begin_define
define|#
directive|define
name|x86_mcinfo_first
parameter_list|(
name|_mi
parameter_list|)
define|\
value|(struct mcinfo_common *)((_mi)->mi_data)
end_define

begin_comment
comment|/* Prototype:  *    struct mcinfo_common *x86_mcinfo_next(struct mcinfo_common *mic);  */
end_comment

begin_define
define|#
directive|define
name|x86_mcinfo_next
parameter_list|(
name|_mic
parameter_list|)
define|\
value|(struct mcinfo_common *)((uint8_t *)(_mic) + (_mic)->size)
end_define

begin_comment
comment|/* Prototype:  *    void x86_mcinfo_lookup(void *ret, struct mc_info *mi, uint16_t type);  */
end_comment

begin_define
define|#
directive|define
name|x86_mcinfo_lookup
parameter_list|(
name|_ret
parameter_list|,
name|_mi
parameter_list|,
name|_type
parameter_list|)
define|\
value|do {                                                        \         uint32_t found, i;                                      \         struct mcinfo_common *_mic;                             \                                                                 \         found = 0;                                              \ 	(_ret) = NULL;						\ 	if (_mi == NULL) break;					\         _mic = x86_mcinfo_first(_mi);                           \         for (i = 0; i< x86_mcinfo_nentries(_mi); i++) {        \             if (_mic->type == (_type)) {                        \                 found = 1;                                      \                 break;                                          \             }                                                   \             _mic = x86_mcinfo_next(_mic);                       \         }                                                       \         (_ret) = found ? _mic : NULL;                           \     } while (0)
end_define

begin_comment
comment|/* Usecase 1  * Register machine check trap callback handler  *    (already done via "set_trap_table" hypercall)  */
end_comment

begin_comment
comment|/* Usecase 2  * Dom0 registers machine check event callback handler  * done by EVTCHNOP_bind_virq  */
end_comment

begin_comment
comment|/* Usecase 3  * Fetch machine check data from hypervisor.  * Note, this hypercall is special, because both Dom0 and DomU must use this.  */
end_comment

begin_define
define|#
directive|define
name|XEN_MC_fetch
value|1
end_define

begin_struct
struct|struct
name|xen_mc_fetch
block|{
comment|/* IN/OUT variables. */
name|uint32_t
name|flags
decl_stmt|;
comment|/* IN: XEN_MC_CORRECTABLE, XEN_MC_TRAP */
comment|/* OUT: XEN_MC_OK, XEN_MC_FETCHFAILED, XEN_MC_NODATA, XEN_MC_NOMATCH */
comment|/* OUT variables. */
name|uint32_t
name|fetch_idx
decl_stmt|;
comment|/* only useful for Dom0 for the notify hypercall */
name|struct
name|mc_info
name|mc_info
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_mc_fetch
name|xen_mc_fetch_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_mc_fetch_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Usecase 4  * This tells the hypervisor to notify a DomU about the machine check error  */
end_comment

begin_define
define|#
directive|define
name|XEN_MC_notifydomain
value|2
end_define

begin_struct
struct|struct
name|xen_mc_notifydomain
block|{
comment|/* IN variables. */
name|uint16_t
name|mc_domid
decl_stmt|;
comment|/* The unprivileged domain to notify. */
name|uint16_t
name|mc_vcpuid
decl_stmt|;
comment|/* The vcpu in mc_domid to notify.                            * Usually echo'd value from the fetch hypercall. */
name|uint32_t
name|fetch_idx
decl_stmt|;
comment|/* echo'd value from the fetch hypercall. */
comment|/* IN/OUT variables. */
name|uint32_t
name|flags
decl_stmt|;
comment|/* IN: XEN_MC_CORRECTABLE, XEN_MC_TRAP */
comment|/* OUT: XEN_MC_OK, XEN_MC_CANNOTHANDLE, XEN_MC_NOTDELIVERED, XEN_MC_NOMATCH */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_mc_notifydomain
name|xen_mc_notifydomain_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_mc_notifydomain_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|xen_mc
block|{
name|uint32_t
name|cmd
decl_stmt|;
name|uint32_t
name|interface_version
decl_stmt|;
comment|/* XEN_MCA_INTERFACE_VERSION */
union|union
block|{
name|struct
name|xen_mc_fetch
name|mc_fetch
decl_stmt|;
name|struct
name|xen_mc_notifydomain
name|mc_notifydomain
decl_stmt|;
name|uint8_t
name|pad
index|[
name|MCINFO_HYPERCALLSIZE
index|]
decl_stmt|;
block|}
name|u
union|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_mc
name|xen_mc_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_mc_t
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
comment|/* __XEN_PUBLIC_ARCH_X86_MCA_H__ */
end_comment

end_unit

