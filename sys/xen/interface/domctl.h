begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  * domctl.h  *   * Domain management operations. For use by node control stack.  *   * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to  * deal in the Software without restriction, including without limitation the  * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or  * sell copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER  * DEALINGS IN THE SOFTWARE.  *  * Copyright (c) 2002-2003, B Dragovic  * Copyright (c) 2002-2006, K Fraser  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XEN_PUBLIC_DOMCTL_H__
end_ifndef

begin_define
define|#
directive|define
name|__XEN_PUBLIC_DOMCTL_H__
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__XEN__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__XEN_TOOLS__
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"domctl operations are intended for use by node control tools only"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"xen.h"
end_include

begin_include
include|#
directive|include
file|"grant_table.h"
end_include

begin_define
define|#
directive|define
name|XEN_DOMCTL_INTERFACE_VERSION
value|0x00000008
end_define

begin_comment
comment|/*  * NB. xen_domctl.domain is an IN/OUT parameter for this operation.  * If it is specified as zero, an id is auto-allocated and returned.  */
end_comment

begin_comment
comment|/* XEN_DOMCTL_createdomain */
end_comment

begin_struct
struct|struct
name|xen_domctl_createdomain
block|{
comment|/* IN parameters */
name|uint32_t
name|ssidref
decl_stmt|;
name|xen_domain_handle_t
name|handle
decl_stmt|;
comment|/* Is this an HVM guest (as opposed to a PV guest)? */
define|#
directive|define
name|_XEN_DOMCTL_CDF_hvm_guest
value|0
define|#
directive|define
name|XEN_DOMCTL_CDF_hvm_guest
value|(1U<<_XEN_DOMCTL_CDF_hvm_guest)
comment|/* Use hardware-assisted paging if available? */
define|#
directive|define
name|_XEN_DOMCTL_CDF_hap
value|1
define|#
directive|define
name|XEN_DOMCTL_CDF_hap
value|(1U<<_XEN_DOMCTL_CDF_hap)
comment|/* Should domain memory integrity be verifed by tboot during Sx? */
define|#
directive|define
name|_XEN_DOMCTL_CDF_s3_integrity
value|2
define|#
directive|define
name|XEN_DOMCTL_CDF_s3_integrity
value|(1U<<_XEN_DOMCTL_CDF_s3_integrity)
comment|/* Disable out-of-sync shadow page tables? */
define|#
directive|define
name|_XEN_DOMCTL_CDF_oos_off
value|3
define|#
directive|define
name|XEN_DOMCTL_CDF_oos_off
value|(1U<<_XEN_DOMCTL_CDF_oos_off)
name|uint32_t
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_domctl_createdomain
name|xen_domctl_createdomain_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_domctl_createdomain_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* XEN_DOMCTL_getdomaininfo */
end_comment

begin_struct
struct|struct
name|xen_domctl_getdomaininfo
block|{
comment|/* OUT variables. */
name|domid_t
name|domain
decl_stmt|;
comment|/* Also echoed in domctl.domain */
comment|/* Domain is scheduled to die. */
define|#
directive|define
name|_XEN_DOMINF_dying
value|0
define|#
directive|define
name|XEN_DOMINF_dying
value|(1U<<_XEN_DOMINF_dying)
comment|/* Domain is an HVM guest (as opposed to a PV guest). */
define|#
directive|define
name|_XEN_DOMINF_hvm_guest
value|1
define|#
directive|define
name|XEN_DOMINF_hvm_guest
value|(1U<<_XEN_DOMINF_hvm_guest)
comment|/* The guest OS has shut down. */
define|#
directive|define
name|_XEN_DOMINF_shutdown
value|2
define|#
directive|define
name|XEN_DOMINF_shutdown
value|(1U<<_XEN_DOMINF_shutdown)
comment|/* Currently paused by control software. */
define|#
directive|define
name|_XEN_DOMINF_paused
value|3
define|#
directive|define
name|XEN_DOMINF_paused
value|(1U<<_XEN_DOMINF_paused)
comment|/* Currently blocked pending an event.     */
define|#
directive|define
name|_XEN_DOMINF_blocked
value|4
define|#
directive|define
name|XEN_DOMINF_blocked
value|(1U<<_XEN_DOMINF_blocked)
comment|/* Domain is currently running.            */
define|#
directive|define
name|_XEN_DOMINF_running
value|5
define|#
directive|define
name|XEN_DOMINF_running
value|(1U<<_XEN_DOMINF_running)
comment|/* Being debugged.  */
define|#
directive|define
name|_XEN_DOMINF_debugged
value|6
define|#
directive|define
name|XEN_DOMINF_debugged
value|(1U<<_XEN_DOMINF_debugged)
comment|/* XEN_DOMINF_shutdown guest-supplied code.  */
define|#
directive|define
name|XEN_DOMINF_shutdownmask
value|255
define|#
directive|define
name|XEN_DOMINF_shutdownshift
value|16
name|uint32_t
name|flags
decl_stmt|;
comment|/* XEN_DOMINF_* */
name|uint64_aligned_t
name|tot_pages
decl_stmt|;
name|uint64_aligned_t
name|max_pages
decl_stmt|;
name|uint64_aligned_t
name|shr_pages
decl_stmt|;
name|uint64_aligned_t
name|paged_pages
decl_stmt|;
name|uint64_aligned_t
name|shared_info_frame
decl_stmt|;
comment|/* GMFN of shared_info struct */
name|uint64_aligned_t
name|cpu_time
decl_stmt|;
name|uint32_t
name|nr_online_vcpus
decl_stmt|;
comment|/* Number of VCPUs currently online. */
name|uint32_t
name|max_vcpu_id
decl_stmt|;
comment|/* Maximum VCPUID in use by this domain. */
name|uint32_t
name|ssidref
decl_stmt|;
name|xen_domain_handle_t
name|handle
decl_stmt|;
name|uint32_t
name|cpupool
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_domctl_getdomaininfo
name|xen_domctl_getdomaininfo_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_domctl_getdomaininfo_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* XEN_DOMCTL_getmemlist */
end_comment

begin_struct
struct|struct
name|xen_domctl_getmemlist
block|{
comment|/* IN variables. */
comment|/* Max entries to write to output buffer. */
name|uint64_aligned_t
name|max_pfns
decl_stmt|;
comment|/* Start index in guest's page list. */
name|uint64_aligned_t
name|start_pfn
decl_stmt|;
name|XEN_GUEST_HANDLE_64
argument_list|(
argument|uint64
argument_list|)
name|buffer
expr_stmt|;
comment|/* OUT variables. */
name|uint64_aligned_t
name|num_pfns
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_domctl_getmemlist
name|xen_domctl_getmemlist_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_domctl_getmemlist_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* XEN_DOMCTL_getpageframeinfo */
end_comment

begin_define
define|#
directive|define
name|XEN_DOMCTL_PFINFO_LTAB_SHIFT
value|28
end_define

begin_define
define|#
directive|define
name|XEN_DOMCTL_PFINFO_NOTAB
value|(0x0U<<28)
end_define

begin_define
define|#
directive|define
name|XEN_DOMCTL_PFINFO_L1TAB
value|(0x1U<<28)
end_define

begin_define
define|#
directive|define
name|XEN_DOMCTL_PFINFO_L2TAB
value|(0x2U<<28)
end_define

begin_define
define|#
directive|define
name|XEN_DOMCTL_PFINFO_L3TAB
value|(0x3U<<28)
end_define

begin_define
define|#
directive|define
name|XEN_DOMCTL_PFINFO_L4TAB
value|(0x4U<<28)
end_define

begin_define
define|#
directive|define
name|XEN_DOMCTL_PFINFO_LTABTYPE_MASK
value|(0x7U<<28)
end_define

begin_define
define|#
directive|define
name|XEN_DOMCTL_PFINFO_LPINTAB
value|(0x1U<<31)
end_define

begin_define
define|#
directive|define
name|XEN_DOMCTL_PFINFO_XTAB
value|(0xfU<<28)
end_define

begin_comment
comment|/* invalid page */
end_comment

begin_define
define|#
directive|define
name|XEN_DOMCTL_PFINFO_XALLOC
value|(0xeU<<28)
end_define

begin_comment
comment|/* allocate-only page */
end_comment

begin_define
define|#
directive|define
name|XEN_DOMCTL_PFINFO_PAGEDTAB
value|(0x8U<<28)
end_define

begin_define
define|#
directive|define
name|XEN_DOMCTL_PFINFO_LTAB_MASK
value|(0xfU<<28)
end_define

begin_struct
struct|struct
name|xen_domctl_getpageframeinfo
block|{
comment|/* IN variables. */
name|uint64_aligned_t
name|gmfn
decl_stmt|;
comment|/* GMFN to query */
comment|/* OUT variables. */
comment|/* Is the page PINNED to a type? */
name|uint32_t
name|type
decl_stmt|;
comment|/* see above type defs */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_domctl_getpageframeinfo
name|xen_domctl_getpageframeinfo_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_domctl_getpageframeinfo_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* XEN_DOMCTL_getpageframeinfo2 */
end_comment

begin_struct
struct|struct
name|xen_domctl_getpageframeinfo2
block|{
comment|/* IN variables. */
name|uint64_aligned_t
name|num
decl_stmt|;
comment|/* IN/OUT variables. */
name|XEN_GUEST_HANDLE_64
argument_list|(
argument|uint32
argument_list|)
name|array
expr_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_domctl_getpageframeinfo2
name|xen_domctl_getpageframeinfo2_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_domctl_getpageframeinfo2_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* XEN_DOMCTL_getpageframeinfo3 */
end_comment

begin_struct
struct|struct
name|xen_domctl_getpageframeinfo3
block|{
comment|/* IN variables. */
name|uint64_aligned_t
name|num
decl_stmt|;
comment|/* IN/OUT variables. */
name|XEN_GUEST_HANDLE_64
argument_list|(
argument|xen_pfn_t
argument_list|)
name|array
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Control shadow pagetables operation  */
end_comment

begin_comment
comment|/* XEN_DOMCTL_shadow_op */
end_comment

begin_comment
comment|/* Disable shadow mode. */
end_comment

begin_define
define|#
directive|define
name|XEN_DOMCTL_SHADOW_OP_OFF
value|0
end_define

begin_comment
comment|/* Enable shadow mode (mode contains ORed XEN_DOMCTL_SHADOW_ENABLE_* flags). */
end_comment

begin_define
define|#
directive|define
name|XEN_DOMCTL_SHADOW_OP_ENABLE
value|32
end_define

begin_comment
comment|/* Log-dirty bitmap operations. */
end_comment

begin_comment
comment|/* Return the bitmap and clean internal copy for next round. */
end_comment

begin_define
define|#
directive|define
name|XEN_DOMCTL_SHADOW_OP_CLEAN
value|11
end_define

begin_comment
comment|/* Return the bitmap but do not modify internal copy. */
end_comment

begin_define
define|#
directive|define
name|XEN_DOMCTL_SHADOW_OP_PEEK
value|12
end_define

begin_comment
comment|/* Memory allocation accessors. */
end_comment

begin_define
define|#
directive|define
name|XEN_DOMCTL_SHADOW_OP_GET_ALLOCATION
value|30
end_define

begin_define
define|#
directive|define
name|XEN_DOMCTL_SHADOW_OP_SET_ALLOCATION
value|31
end_define

begin_comment
comment|/* Legacy enable operations. */
end_comment

begin_comment
comment|/* Equiv. to ENABLE with no mode flags. */
end_comment

begin_define
define|#
directive|define
name|XEN_DOMCTL_SHADOW_OP_ENABLE_TEST
value|1
end_define

begin_comment
comment|/* Equiv. to ENABLE with mode flag ENABLE_LOG_DIRTY. */
end_comment

begin_define
define|#
directive|define
name|XEN_DOMCTL_SHADOW_OP_ENABLE_LOGDIRTY
value|2
end_define

begin_comment
comment|/* Equiv. to ENABLE with mode flags ENABLE_REFCOUNT and ENABLE_TRANSLATE. */
end_comment

begin_define
define|#
directive|define
name|XEN_DOMCTL_SHADOW_OP_ENABLE_TRANSLATE
value|3
end_define

begin_comment
comment|/* Mode flags for XEN_DOMCTL_SHADOW_OP_ENABLE. */
end_comment

begin_comment
comment|/*   * Shadow pagetables are refcounted: guest does not use explicit mmu   * operations nor write-protect its pagetables.   */
end_comment

begin_define
define|#
directive|define
name|XEN_DOMCTL_SHADOW_ENABLE_REFCOUNT
value|(1<< 1)
end_define

begin_comment
comment|/*   * Log pages in a bitmap as they are dirtied.   * Used for live relocation to determine which pages must be re-sent.   */
end_comment

begin_define
define|#
directive|define
name|XEN_DOMCTL_SHADOW_ENABLE_LOG_DIRTY
value|(1<< 2)
end_define

begin_comment
comment|/*   * Automatically translate GPFNs into MFNs.   */
end_comment

begin_define
define|#
directive|define
name|XEN_DOMCTL_SHADOW_ENABLE_TRANSLATE
value|(1<< 3)
end_define

begin_comment
comment|/*   * Xen does not steal virtual address space from the guest.   * Requires HVM support.   */
end_comment

begin_define
define|#
directive|define
name|XEN_DOMCTL_SHADOW_ENABLE_EXTERNAL
value|(1<< 4)
end_define

begin_struct
struct|struct
name|xen_domctl_shadow_op_stats
block|{
name|uint32_t
name|fault_count
decl_stmt|;
name|uint32_t
name|dirty_count
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_domctl_shadow_op_stats
name|xen_domctl_shadow_op_stats_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_domctl_shadow_op_stats_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|xen_domctl_shadow_op
block|{
comment|/* IN variables. */
name|uint32_t
name|op
decl_stmt|;
comment|/* XEN_DOMCTL_SHADOW_OP_* */
comment|/* OP_ENABLE */
name|uint32_t
name|mode
decl_stmt|;
comment|/* XEN_DOMCTL_SHADOW_ENABLE_* */
comment|/* OP_GET_ALLOCATION / OP_SET_ALLOCATION */
name|uint32_t
name|mb
decl_stmt|;
comment|/* Shadow memory allocation in MB */
comment|/* OP_PEEK / OP_CLEAN */
name|XEN_GUEST_HANDLE_64
argument_list|(
argument|uint8
argument_list|)
name|dirty_bitmap
expr_stmt|;
name|uint64_aligned_t
name|pages
decl_stmt|;
comment|/* Size of buffer. Updated with actual size. */
name|struct
name|xen_domctl_shadow_op_stats
name|stats
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_domctl_shadow_op
name|xen_domctl_shadow_op_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_domctl_shadow_op_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* XEN_DOMCTL_max_mem */
end_comment

begin_struct
struct|struct
name|xen_domctl_max_mem
block|{
comment|/* IN variables. */
name|uint64_aligned_t
name|max_memkb
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_domctl_max_mem
name|xen_domctl_max_mem_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_domctl_max_mem_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* XEN_DOMCTL_setvcpucontext */
end_comment

begin_comment
comment|/* XEN_DOMCTL_getvcpucontext */
end_comment

begin_struct
struct|struct
name|xen_domctl_vcpucontext
block|{
name|uint32_t
name|vcpu
decl_stmt|;
comment|/* IN */
name|XEN_GUEST_HANDLE_64
argument_list|(
argument|vcpu_guest_context_t
argument_list|)
name|ctxt
expr_stmt|;
comment|/* IN/OUT */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_domctl_vcpucontext
name|xen_domctl_vcpucontext_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_domctl_vcpucontext_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* XEN_DOMCTL_getvcpuinfo */
end_comment

begin_struct
struct|struct
name|xen_domctl_getvcpuinfo
block|{
comment|/* IN variables. */
name|uint32_t
name|vcpu
decl_stmt|;
comment|/* OUT variables. */
name|uint8_t
name|online
decl_stmt|;
comment|/* currently online (not hotplugged)? */
name|uint8_t
name|blocked
decl_stmt|;
comment|/* blocked waiting for an event? */
name|uint8_t
name|running
decl_stmt|;
comment|/* currently scheduled on its CPU? */
name|uint64_aligned_t
name|cpu_time
decl_stmt|;
comment|/* total cpu time consumed (ns) */
name|uint32_t
name|cpu
decl_stmt|;
comment|/* current mapping   */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_domctl_getvcpuinfo
name|xen_domctl_getvcpuinfo_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_domctl_getvcpuinfo_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Get/set which physical cpus a vcpu can execute on. */
end_comment

begin_comment
comment|/* XEN_DOMCTL_setvcpuaffinity */
end_comment

begin_comment
comment|/* XEN_DOMCTL_getvcpuaffinity */
end_comment

begin_struct
struct|struct
name|xen_domctl_vcpuaffinity
block|{
name|uint32_t
name|vcpu
decl_stmt|;
comment|/* IN */
name|struct
name|xenctl_cpumap
name|cpumap
decl_stmt|;
comment|/* IN/OUT */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_domctl_vcpuaffinity
name|xen_domctl_vcpuaffinity_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_domctl_vcpuaffinity_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* XEN_DOMCTL_max_vcpus */
end_comment

begin_struct
struct|struct
name|xen_domctl_max_vcpus
block|{
name|uint32_t
name|max
decl_stmt|;
comment|/* maximum number of vcpus */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_domctl_max_vcpus
name|xen_domctl_max_vcpus_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_domctl_max_vcpus_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* XEN_DOMCTL_scheduler_op */
end_comment

begin_comment
comment|/* Scheduler types. */
end_comment

begin_define
define|#
directive|define
name|XEN_SCHEDULER_SEDF
value|4
end_define

begin_define
define|#
directive|define
name|XEN_SCHEDULER_CREDIT
value|5
end_define

begin_define
define|#
directive|define
name|XEN_SCHEDULER_CREDIT2
value|6
end_define

begin_define
define|#
directive|define
name|XEN_SCHEDULER_ARINC653
value|7
end_define

begin_comment
comment|/* Set or get info? */
end_comment

begin_define
define|#
directive|define
name|XEN_DOMCTL_SCHEDOP_putinfo
value|0
end_define

begin_define
define|#
directive|define
name|XEN_DOMCTL_SCHEDOP_getinfo
value|1
end_define

begin_struct
struct|struct
name|xen_domctl_scheduler_op
block|{
name|uint32_t
name|sched_id
decl_stmt|;
comment|/* XEN_SCHEDULER_* */
name|uint32_t
name|cmd
decl_stmt|;
comment|/* XEN_DOMCTL_SCHEDOP_* */
union|union
block|{
struct|struct
name|xen_domctl_sched_sedf
block|{
name|uint64_aligned_t
name|period
decl_stmt|;
name|uint64_aligned_t
name|slice
decl_stmt|;
name|uint64_aligned_t
name|latency
decl_stmt|;
name|uint32_t
name|extratime
decl_stmt|;
name|uint32_t
name|weight
decl_stmt|;
block|}
name|sedf
struct|;
struct|struct
name|xen_domctl_sched_credit
block|{
name|uint16_t
name|weight
decl_stmt|;
name|uint16_t
name|cap
decl_stmt|;
block|}
name|credit
struct|;
struct|struct
name|xen_domctl_sched_credit2
block|{
name|uint16_t
name|weight
decl_stmt|;
block|}
name|credit2
struct|;
block|}
name|u
union|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_domctl_scheduler_op
name|xen_domctl_scheduler_op_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_domctl_scheduler_op_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* XEN_DOMCTL_setdomainhandle */
end_comment

begin_struct
struct|struct
name|xen_domctl_setdomainhandle
block|{
name|xen_domain_handle_t
name|handle
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_domctl_setdomainhandle
name|xen_domctl_setdomainhandle_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_domctl_setdomainhandle_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* XEN_DOMCTL_setdebugging */
end_comment

begin_struct
struct|struct
name|xen_domctl_setdebugging
block|{
name|uint8_t
name|enable
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_domctl_setdebugging
name|xen_domctl_setdebugging_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_domctl_setdebugging_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* XEN_DOMCTL_irq_permission */
end_comment

begin_struct
struct|struct
name|xen_domctl_irq_permission
block|{
name|uint8_t
name|pirq
decl_stmt|;
name|uint8_t
name|allow_access
decl_stmt|;
comment|/* flag to specify enable/disable of IRQ access */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_domctl_irq_permission
name|xen_domctl_irq_permission_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_domctl_irq_permission_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* XEN_DOMCTL_iomem_permission */
end_comment

begin_struct
struct|struct
name|xen_domctl_iomem_permission
block|{
name|uint64_aligned_t
name|first_mfn
decl_stmt|;
comment|/* first page (physical page number) in range */
name|uint64_aligned_t
name|nr_mfns
decl_stmt|;
comment|/* number of pages in range (>0) */
name|uint8_t
name|allow_access
decl_stmt|;
comment|/* allow (!0) or deny (0) access to range? */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_domctl_iomem_permission
name|xen_domctl_iomem_permission_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_domctl_iomem_permission_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* XEN_DOMCTL_ioport_permission */
end_comment

begin_struct
struct|struct
name|xen_domctl_ioport_permission
block|{
name|uint32_t
name|first_port
decl_stmt|;
comment|/* first port int range */
name|uint32_t
name|nr_ports
decl_stmt|;
comment|/* size of port range */
name|uint8_t
name|allow_access
decl_stmt|;
comment|/* allow or deny access to range? */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_domctl_ioport_permission
name|xen_domctl_ioport_permission_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_domctl_ioport_permission_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* XEN_DOMCTL_hypercall_init */
end_comment

begin_struct
struct|struct
name|xen_domctl_hypercall_init
block|{
name|uint64_aligned_t
name|gmfn
decl_stmt|;
comment|/* GMFN to be initialised */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_domctl_hypercall_init
name|xen_domctl_hypercall_init_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_domctl_hypercall_init_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* XEN_DOMCTL_arch_setup */
end_comment

begin_define
define|#
directive|define
name|_XEN_DOMAINSETUP_hvm_guest
value|0
end_define

begin_define
define|#
directive|define
name|XEN_DOMAINSETUP_hvm_guest
value|(1UL<<_XEN_DOMAINSETUP_hvm_guest)
end_define

begin_define
define|#
directive|define
name|_XEN_DOMAINSETUP_query
value|1
end_define

begin_comment
comment|/* Get parameters (for save)  */
end_comment

begin_define
define|#
directive|define
name|XEN_DOMAINSETUP_query
value|(1UL<<_XEN_DOMAINSETUP_query)
end_define

begin_define
define|#
directive|define
name|_XEN_DOMAINSETUP_sioemu_guest
value|2
end_define

begin_define
define|#
directive|define
name|XEN_DOMAINSETUP_sioemu_guest
value|(1UL<<_XEN_DOMAINSETUP_sioemu_guest)
end_define

begin_typedef
typedef|typedef
struct|struct
name|xen_domctl_arch_setup
block|{
name|uint64_aligned_t
name|flags
decl_stmt|;
comment|/* XEN_DOMAINSETUP_* */
ifdef|#
directive|ifdef
name|__ia64__
name|uint64_aligned_t
name|bp
decl_stmt|;
comment|/* mpaddr of boot param area */
name|uint64_aligned_t
name|maxmem
decl_stmt|;
comment|/* Highest memory address for MDT.  */
name|uint64_aligned_t
name|xsi_va
decl_stmt|;
comment|/* Xen shared_info area virtual address.  */
name|uint32_t
name|hypercall_imm
decl_stmt|;
comment|/* Break imm for Xen hypercalls.  */
name|int8_t
name|vhpt_size_log2
decl_stmt|;
comment|/* Log2 of VHPT size. */
endif|#
directive|endif
block|}
name|xen_domctl_arch_setup_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_domctl_arch_setup_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* XEN_DOMCTL_settimeoffset */
end_comment

begin_struct
struct|struct
name|xen_domctl_settimeoffset
block|{
name|int32_t
name|time_offset_seconds
decl_stmt|;
comment|/* applied to domain wallclock time */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_domctl_settimeoffset
name|xen_domctl_settimeoffset_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_domctl_settimeoffset_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* XEN_DOMCTL_gethvmcontext */
end_comment

begin_comment
comment|/* XEN_DOMCTL_sethvmcontext */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xen_domctl_hvmcontext
block|{
name|uint32_t
name|size
decl_stmt|;
comment|/* IN/OUT: size of buffer / bytes filled */
name|XEN_GUEST_HANDLE_64
argument_list|(
argument|uint8
argument_list|)
name|buffer
expr_stmt|;
comment|/* IN/OUT: data, or call                                         * gethvmcontext with NULL                                         * buffer to get size req'd */
block|}
name|xen_domctl_hvmcontext_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_domctl_hvmcontext_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* XEN_DOMCTL_set_address_size */
end_comment

begin_comment
comment|/* XEN_DOMCTL_get_address_size */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xen_domctl_address_size
block|{
name|uint32_t
name|size
decl_stmt|;
block|}
name|xen_domctl_address_size_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_domctl_address_size_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* XEN_DOMCTL_real_mode_area */
end_comment

begin_struct
struct|struct
name|xen_domctl_real_mode_area
block|{
name|uint32_t
name|log
decl_stmt|;
comment|/* log2 of Real Mode Area size */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_domctl_real_mode_area
name|xen_domctl_real_mode_area_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_domctl_real_mode_area_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* XEN_DOMCTL_sendtrigger */
end_comment

begin_define
define|#
directive|define
name|XEN_DOMCTL_SENDTRIGGER_NMI
value|0
end_define

begin_define
define|#
directive|define
name|XEN_DOMCTL_SENDTRIGGER_RESET
value|1
end_define

begin_define
define|#
directive|define
name|XEN_DOMCTL_SENDTRIGGER_INIT
value|2
end_define

begin_define
define|#
directive|define
name|XEN_DOMCTL_SENDTRIGGER_POWER
value|3
end_define

begin_define
define|#
directive|define
name|XEN_DOMCTL_SENDTRIGGER_SLEEP
value|4
end_define

begin_struct
struct|struct
name|xen_domctl_sendtrigger
block|{
name|uint32_t
name|trigger
decl_stmt|;
comment|/* IN */
name|uint32_t
name|vcpu
decl_stmt|;
comment|/* IN */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_domctl_sendtrigger
name|xen_domctl_sendtrigger_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_domctl_sendtrigger_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Assign PCI device to HVM guest. Sets up IOMMU structures. */
end_comment

begin_comment
comment|/* XEN_DOMCTL_assign_device */
end_comment

begin_comment
comment|/* XEN_DOMCTL_test_assign_device */
end_comment

begin_comment
comment|/* XEN_DOMCTL_deassign_device */
end_comment

begin_struct
struct|struct
name|xen_domctl_assign_device
block|{
name|uint32_t
name|machine_sbdf
decl_stmt|;
comment|/* machine PCI ID of assigned device */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_domctl_assign_device
name|xen_domctl_assign_device_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_domctl_assign_device_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Retrieve sibling devices infomation of machine_sbdf */
end_comment

begin_comment
comment|/* XEN_DOMCTL_get_device_group */
end_comment

begin_struct
struct|struct
name|xen_domctl_get_device_group
block|{
name|uint32_t
name|machine_sbdf
decl_stmt|;
comment|/* IN */
name|uint32_t
name|max_sdevs
decl_stmt|;
comment|/* IN */
name|uint32_t
name|num_sdevs
decl_stmt|;
comment|/* OUT */
name|XEN_GUEST_HANDLE_64
argument_list|(
argument|uint32
argument_list|)
name|sdev_array
expr_stmt|;
comment|/* OUT */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_domctl_get_device_group
name|xen_domctl_get_device_group_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_domctl_get_device_group_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Pass-through interrupts: bind real irq -> hvm devfn. */
end_comment

begin_comment
comment|/* XEN_DOMCTL_bind_pt_irq */
end_comment

begin_comment
comment|/* XEN_DOMCTL_unbind_pt_irq */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|pt_irq_type_e
block|{
name|PT_IRQ_TYPE_PCI
block|,
name|PT_IRQ_TYPE_ISA
block|,
name|PT_IRQ_TYPE_MSI
block|,
name|PT_IRQ_TYPE_MSI_TRANSLATE
block|, }
name|pt_irq_type_t
typedef|;
end_typedef

begin_struct
struct|struct
name|xen_domctl_bind_pt_irq
block|{
name|uint32_t
name|machine_irq
decl_stmt|;
name|pt_irq_type_t
name|irq_type
decl_stmt|;
name|uint32_t
name|hvm_domid
decl_stmt|;
union|union
block|{
struct|struct
block|{
name|uint8_t
name|isa_irq
decl_stmt|;
block|}
name|isa
struct|;
struct|struct
block|{
name|uint8_t
name|bus
decl_stmt|;
name|uint8_t
name|device
decl_stmt|;
name|uint8_t
name|intx
decl_stmt|;
block|}
name|pci
struct|;
struct|struct
block|{
name|uint8_t
name|gvec
decl_stmt|;
name|uint32_t
name|gflags
decl_stmt|;
name|uint64_aligned_t
name|gtable
decl_stmt|;
block|}
name|msi
struct|;
block|}
name|u
union|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_domctl_bind_pt_irq
name|xen_domctl_bind_pt_irq_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_domctl_bind_pt_irq_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Bind machine I/O address range -> HVM address range. */
end_comment

begin_comment
comment|/* XEN_DOMCTL_memory_mapping */
end_comment

begin_define
define|#
directive|define
name|DPCI_ADD_MAPPING
value|1
end_define

begin_define
define|#
directive|define
name|DPCI_REMOVE_MAPPING
value|0
end_define

begin_struct
struct|struct
name|xen_domctl_memory_mapping
block|{
name|uint64_aligned_t
name|first_gfn
decl_stmt|;
comment|/* first page (hvm guest phys page) in range */
name|uint64_aligned_t
name|first_mfn
decl_stmt|;
comment|/* first page (machine page) in range */
name|uint64_aligned_t
name|nr_mfns
decl_stmt|;
comment|/* number of pages in range (>0) */
name|uint32_t
name|add_mapping
decl_stmt|;
comment|/* add or remove mapping */
name|uint32_t
name|padding
decl_stmt|;
comment|/* padding for 64-bit aligned structure */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_domctl_memory_mapping
name|xen_domctl_memory_mapping_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_domctl_memory_mapping_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Bind machine I/O port range -> HVM I/O port range. */
end_comment

begin_comment
comment|/* XEN_DOMCTL_ioport_mapping */
end_comment

begin_struct
struct|struct
name|xen_domctl_ioport_mapping
block|{
name|uint32_t
name|first_gport
decl_stmt|;
comment|/* first guest IO port*/
name|uint32_t
name|first_mport
decl_stmt|;
comment|/* first machine IO port */
name|uint32_t
name|nr_ports
decl_stmt|;
comment|/* size of port range */
name|uint32_t
name|add_mapping
decl_stmt|;
comment|/* add or remove mapping */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_domctl_ioport_mapping
name|xen_domctl_ioport_mapping_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_domctl_ioport_mapping_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Pin caching type of RAM space for x86 HVM domU.  */
end_comment

begin_comment
comment|/* XEN_DOMCTL_pin_mem_cacheattr */
end_comment

begin_comment
comment|/* Caching types: these happen to be the same as x86 MTRR/PAT type codes. */
end_comment

begin_define
define|#
directive|define
name|XEN_DOMCTL_MEM_CACHEATTR_UC
value|0
end_define

begin_define
define|#
directive|define
name|XEN_DOMCTL_MEM_CACHEATTR_WC
value|1
end_define

begin_define
define|#
directive|define
name|XEN_DOMCTL_MEM_CACHEATTR_WT
value|4
end_define

begin_define
define|#
directive|define
name|XEN_DOMCTL_MEM_CACHEATTR_WP
value|5
end_define

begin_define
define|#
directive|define
name|XEN_DOMCTL_MEM_CACHEATTR_WB
value|6
end_define

begin_define
define|#
directive|define
name|XEN_DOMCTL_MEM_CACHEATTR_UCM
value|7
end_define

begin_struct
struct|struct
name|xen_domctl_pin_mem_cacheattr
block|{
name|uint64_aligned_t
name|start
decl_stmt|,
name|end
decl_stmt|;
name|uint32_t
name|type
decl_stmt|;
comment|/* XEN_DOMCTL_MEM_CACHEATTR_* */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_domctl_pin_mem_cacheattr
name|xen_domctl_pin_mem_cacheattr_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_domctl_pin_mem_cacheattr_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* XEN_DOMCTL_set_ext_vcpucontext */
end_comment

begin_comment
comment|/* XEN_DOMCTL_get_ext_vcpucontext */
end_comment

begin_struct
struct|struct
name|xen_domctl_ext_vcpucontext
block|{
comment|/* IN: VCPU that this call applies to. */
name|uint32_t
name|vcpu
decl_stmt|;
comment|/*      * SET: Size of struct (IN)      * GET: Size of struct (OUT, up to 128 bytes)      */
name|uint32_t
name|size
decl_stmt|;
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
comment|/* SYSCALL from 32-bit mode and SYSENTER callback information. */
comment|/* NB. SYSCALL from 64-bit mode is contained in vcpu_guest_context_t */
name|uint64_aligned_t
name|syscall32_callback_eip
decl_stmt|;
name|uint64_aligned_t
name|sysenter_callback_eip
decl_stmt|;
name|uint16_t
name|syscall32_callback_cs
decl_stmt|;
name|uint16_t
name|sysenter_callback_cs
decl_stmt|;
name|uint8_t
name|syscall32_disables_events
decl_stmt|;
name|uint8_t
name|sysenter_disables_events
decl_stmt|;
name|uint64_aligned_t
name|mcg_cap
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_domctl_ext_vcpucontext
name|xen_domctl_ext_vcpucontext_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_domctl_ext_vcpucontext_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Set optimizaton features for a domain  */
end_comment

begin_comment
comment|/* XEN_DOMCTL_set_opt_feature */
end_comment

begin_struct
struct|struct
name|xen_domctl_set_opt_feature
block|{
if|#
directive|if
name|defined
argument_list|(
name|__ia64__
argument_list|)
name|struct
name|xen_ia64_opt_feature
name|optf
decl_stmt|;
else|#
directive|else
comment|/* Make struct non-empty: do not depend on this field name! */
name|uint64_t
name|dummy
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_domctl_set_opt_feature
name|xen_domctl_set_opt_feature_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_domctl_set_opt_feature_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Set the target domain for a domain  */
end_comment

begin_comment
comment|/* XEN_DOMCTL_set_target */
end_comment

begin_struct
struct|struct
name|xen_domctl_set_target
block|{
name|domid_t
name|target
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_domctl_set_target
name|xen_domctl_set_target_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_domctl_set_target_t
argument_list|)
expr_stmt|;
end_expr_stmt

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

begin_define
define|#
directive|define
name|XEN_CPUID_INPUT_UNUSED
value|0xFFFFFFFF
end_define

begin_comment
comment|/* XEN_DOMCTL_set_cpuid */
end_comment

begin_struct
struct|struct
name|xen_domctl_cpuid
block|{
name|uint32_t
name|input
index|[
literal|2
index|]
decl_stmt|;
name|uint32_t
name|eax
decl_stmt|;
name|uint32_t
name|ebx
decl_stmt|;
name|uint32_t
name|ecx
decl_stmt|;
name|uint32_t
name|edx
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_domctl_cpuid
name|xen_domctl_cpuid_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_domctl_cpuid_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* XEN_DOMCTL_subscribe */
end_comment

begin_struct
struct|struct
name|xen_domctl_subscribe
block|{
name|uint32_t
name|port
decl_stmt|;
comment|/* IN */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_domctl_subscribe
name|xen_domctl_subscribe_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_domctl_subscribe_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Define the maximum machine address size which should be allocated  * to a guest.  */
end_comment

begin_comment
comment|/* XEN_DOMCTL_set_machine_address_size */
end_comment

begin_comment
comment|/* XEN_DOMCTL_get_machine_address_size */
end_comment

begin_comment
comment|/*  * Do not inject spurious page faults into this domain.  */
end_comment

begin_comment
comment|/* XEN_DOMCTL_suppress_spurious_page_faults */
end_comment

begin_comment
comment|/* XEN_DOMCTL_debug_op */
end_comment

begin_define
define|#
directive|define
name|XEN_DOMCTL_DEBUG_OP_SINGLE_STEP_OFF
value|0
end_define

begin_define
define|#
directive|define
name|XEN_DOMCTL_DEBUG_OP_SINGLE_STEP_ON
value|1
end_define

begin_struct
struct|struct
name|xen_domctl_debug_op
block|{
name|uint32_t
name|op
decl_stmt|;
comment|/* IN */
name|uint32_t
name|vcpu
decl_stmt|;
comment|/* IN */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_domctl_debug_op
name|xen_domctl_debug_op_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_domctl_debug_op_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Request a particular record from the HVM context  */
end_comment

begin_comment
comment|/* XEN_DOMCTL_gethvmcontext_partial */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xen_domctl_hvmcontext_partial
block|{
name|uint32_t
name|type
decl_stmt|;
comment|/* IN: Type of record required */
name|uint32_t
name|instance
decl_stmt|;
comment|/* IN: Instance of that type */
name|XEN_GUEST_HANDLE_64
argument_list|(
argument|uint8
argument_list|)
name|buffer
expr_stmt|;
comment|/* OUT: buffer to write record into */
block|}
name|xen_domctl_hvmcontext_partial_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_domctl_hvmcontext_partial_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* XEN_DOMCTL_disable_migrate */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xen_domctl_disable_migrate
block|{
name|uint32_t
name|disable
decl_stmt|;
comment|/* IN: 1: disable migration and restore */
block|}
name|xen_domctl_disable_migrate_t
typedef|;
end_typedef

begin_comment
comment|/* XEN_DOMCTL_gettscinfo */
end_comment

begin_comment
comment|/* XEN_DOMCTL_settscinfo */
end_comment

begin_struct
struct|struct
name|xen_guest_tsc_info
block|{
name|uint32_t
name|tsc_mode
decl_stmt|;
name|uint32_t
name|gtsc_khz
decl_stmt|;
name|uint32_t
name|incarnation
decl_stmt|;
name|uint32_t
name|pad
decl_stmt|;
name|uint64_aligned_t
name|elapsed_nsec
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_guest_tsc_info
name|xen_guest_tsc_info_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_guest_tsc_info_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
struct|struct
name|xen_domctl_tsc_info
block|{
name|XEN_GUEST_HANDLE_64
argument_list|(
argument|xen_guest_tsc_info_t
argument_list|)
name|out_info
expr_stmt|;
comment|/* OUT */
name|xen_guest_tsc_info_t
name|info
decl_stmt|;
comment|/* IN */
block|}
name|xen_domctl_tsc_info_t
typedef|;
end_typedef

begin_comment
comment|/* XEN_DOMCTL_gdbsx_guestmemio      guest mem io */
end_comment

begin_struct
struct|struct
name|xen_domctl_gdbsx_memio
block|{
comment|/* IN */
name|uint64_aligned_t
name|pgd3val
decl_stmt|;
comment|/* optional: init_mm.pgd[3] value */
name|uint64_aligned_t
name|gva
decl_stmt|;
comment|/* guest virtual address */
name|uint64_aligned_t
name|uva
decl_stmt|;
comment|/* user buffer virtual address */
name|uint32_t
name|len
decl_stmt|;
comment|/* number of bytes to read/write */
name|uint8_t
name|gwr
decl_stmt|;
comment|/* 0 = read from guest. 1 = write to guest */
comment|/* OUT */
name|uint32_t
name|remain
decl_stmt|;
comment|/* bytes remaining to be copied */
block|}
struct|;
end_struct

begin_comment
comment|/* XEN_DOMCTL_gdbsx_pausevcpu */
end_comment

begin_comment
comment|/* XEN_DOMCTL_gdbsx_unpausevcpu */
end_comment

begin_struct
struct|struct
name|xen_domctl_gdbsx_pauseunp_vcpu
block|{
comment|/* pause/unpause a vcpu */
name|uint32_t
name|vcpu
decl_stmt|;
comment|/* which vcpu */
block|}
struct|;
end_struct

begin_comment
comment|/* XEN_DOMCTL_gdbsx_domstatus */
end_comment

begin_struct
struct|struct
name|xen_domctl_gdbsx_domstatus
block|{
comment|/* OUT */
name|uint8_t
name|paused
decl_stmt|;
comment|/* is the domain paused */
name|uint32_t
name|vcpu_id
decl_stmt|;
comment|/* any vcpu in an event? */
name|uint32_t
name|vcpu_ev
decl_stmt|;
comment|/* if yes, what event? */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Memory event operations  */
end_comment

begin_comment
comment|/* XEN_DOMCTL_mem_event_op */
end_comment

begin_comment
comment|/*  * Domain memory paging  * Page memory in and out.  * Domctl interface to set up and tear down the   * pager<->hypervisor interface. Use XENMEM_paging_op*  * to perform per-page operations.  *  * The XEN_DOMCTL_MEM_EVENT_OP_PAGING_ENABLE domctl returns several  * non-standard error codes to indicate why paging could not be enabled:  * ENODEV - host lacks HAP support (EPT/NPT) or HAP is disabled in guest  * EMLINK - guest has iommu passthrough enabled  * EXDEV  - guest has PoD enabled  * EBUSY  - guest has or had paging enabled, ring buffer still active  */
end_comment

begin_define
define|#
directive|define
name|XEN_DOMCTL_MEM_EVENT_OP_PAGING
value|1
end_define

begin_define
define|#
directive|define
name|XEN_DOMCTL_MEM_EVENT_OP_PAGING_ENABLE
value|0
end_define

begin_define
define|#
directive|define
name|XEN_DOMCTL_MEM_EVENT_OP_PAGING_DISABLE
value|1
end_define

begin_comment
comment|/*  * Access permissions.  *  * As with paging, use the domctl for teardown/setup of the  * helper<->hypervisor interface.  *  * There are HVM hypercalls to set the per-page access permissions of every  * page in a domain.  When one of these permissions--independent, read,   * write, and execute--is violated, the VCPU is paused and a memory event   * is sent with what happened.  (See public/mem_event.h) .  *  * The memory event handler can then resume the VCPU and redo the access   * with a XENMEM_access_op_resume hypercall.  *  * The XEN_DOMCTL_MEM_EVENT_OP_ACCESS_ENABLE domctl returns several  * non-standard error codes to indicate why access could not be enabled:  * ENODEV - host lacks HAP support (EPT/NPT) or HAP is disabled in guest  * EBUSY  - guest has or had access enabled, ring buffer still active  */
end_comment

begin_define
define|#
directive|define
name|XEN_DOMCTL_MEM_EVENT_OP_ACCESS
value|2
end_define

begin_define
define|#
directive|define
name|XEN_DOMCTL_MEM_EVENT_OP_ACCESS_ENABLE
value|0
end_define

begin_define
define|#
directive|define
name|XEN_DOMCTL_MEM_EVENT_OP_ACCESS_DISABLE
value|1
end_define

begin_comment
comment|/*  * Sharing ENOMEM helper.  *  * As with paging, use the domctl for teardown/setup of the  * helper<->hypervisor interface.  *  * If setup, this ring is used to communicate failed allocations  * in the unshare path. XENMEM_sharing_op_resume is used to wake up  * vcpus that could not unshare.  *  * Note that shring can be turned on (as per the domctl below)  * *without* this ring being setup.  */
end_comment

begin_define
define|#
directive|define
name|XEN_DOMCTL_MEM_EVENT_OP_SHARING
value|3
end_define

begin_define
define|#
directive|define
name|XEN_DOMCTL_MEM_EVENT_OP_SHARING_ENABLE
value|0
end_define

begin_define
define|#
directive|define
name|XEN_DOMCTL_MEM_EVENT_OP_SHARING_DISABLE
value|1
end_define

begin_comment
comment|/* Use for teardown/setup of helper<->hypervisor interface for paging,   * access and sharing.*/
end_comment

begin_struct
struct|struct
name|xen_domctl_mem_event_op
block|{
name|uint32_t
name|op
decl_stmt|;
comment|/* XEN_DOMCTL_MEM_EVENT_OP_*_* */
name|uint32_t
name|mode
decl_stmt|;
comment|/* XEN_DOMCTL_MEM_EVENT_OP_* */
name|uint32_t
name|port
decl_stmt|;
comment|/* OUT: event channel for ring */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_domctl_mem_event_op
name|xen_domctl_mem_event_op_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_domctl_mem_event_op_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Memory sharing operations  */
end_comment

begin_comment
comment|/* XEN_DOMCTL_mem_sharing_op.  * The CONTROL sub-domctl is used for bringup/teardown. */
end_comment

begin_define
define|#
directive|define
name|XEN_DOMCTL_MEM_SHARING_CONTROL
value|0
end_define

begin_struct
struct|struct
name|xen_domctl_mem_sharing_op
block|{
name|uint8_t
name|op
decl_stmt|;
comment|/* XEN_DOMCTL_MEM_SHARING_* */
union|union
block|{
name|uint8_t
name|enable
decl_stmt|;
comment|/* CONTROL */
block|}
name|u
union|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_domctl_mem_sharing_op
name|xen_domctl_mem_sharing_op_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_domctl_mem_sharing_op_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|xen_domctl_audit_p2m
block|{
comment|/* OUT error counts */
name|uint64_t
name|orphans
decl_stmt|;
name|uint64_t
name|m2p_bad
decl_stmt|;
name|uint64_t
name|p2m_bad
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_domctl_audit_p2m
name|xen_domctl_audit_p2m_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_domctl_audit_p2m_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|xen_domctl_set_virq_handler
block|{
name|uint32_t
name|virq
decl_stmt|;
comment|/* IN */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_domctl_set_virq_handler
name|xen_domctl_set_virq_handler_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_domctl_set_virq_handler_t
argument_list|)
expr_stmt|;
end_expr_stmt

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

begin_comment
comment|/* XEN_DOMCTL_setvcpuextstate */
end_comment

begin_comment
comment|/* XEN_DOMCTL_getvcpuextstate */
end_comment

begin_struct
struct|struct
name|xen_domctl_vcpuextstate
block|{
comment|/* IN: VCPU that this call applies to. */
name|uint32_t
name|vcpu
decl_stmt|;
comment|/*      * SET: xfeature support mask of struct (IN)      * GET: xfeature support mask of struct (IN/OUT)      * xfeature mask is served as identifications of the saving format      * so that compatible CPUs can have a check on format to decide      * whether it can restore.      */
name|uint64_aligned_t
name|xfeature_mask
decl_stmt|;
comment|/*      * SET: Size of struct (IN)      * GET: Size of struct (IN/OUT)      */
name|uint64_aligned_t
name|size
decl_stmt|;
name|XEN_GUEST_HANDLE_64
argument_list|(
argument|uint64
argument_list|)
name|buffer
expr_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_domctl_vcpuextstate
name|xen_domctl_vcpuextstate_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_domctl_vcpuextstate_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* XEN_DOMCTL_set_access_required: sets whether a memory event listener  * must be present to handle page access events: if false, the page  * access will revert to full permissions if no one is listening;  *  */
end_comment

begin_struct
struct|struct
name|xen_domctl_set_access_required
block|{
name|uint8_t
name|access_required
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_domctl_set_access_required
name|xen_domctl_set_access_required_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_domctl_set_access_required_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|xen_domctl
block|{
name|uint32_t
name|cmd
decl_stmt|;
define|#
directive|define
name|XEN_DOMCTL_createdomain
value|1
define|#
directive|define
name|XEN_DOMCTL_destroydomain
value|2
define|#
directive|define
name|XEN_DOMCTL_pausedomain
value|3
define|#
directive|define
name|XEN_DOMCTL_unpausedomain
value|4
define|#
directive|define
name|XEN_DOMCTL_getdomaininfo
value|5
define|#
directive|define
name|XEN_DOMCTL_getmemlist
value|6
define|#
directive|define
name|XEN_DOMCTL_getpageframeinfo
value|7
define|#
directive|define
name|XEN_DOMCTL_getpageframeinfo2
value|8
define|#
directive|define
name|XEN_DOMCTL_setvcpuaffinity
value|9
define|#
directive|define
name|XEN_DOMCTL_shadow_op
value|10
define|#
directive|define
name|XEN_DOMCTL_max_mem
value|11
define|#
directive|define
name|XEN_DOMCTL_setvcpucontext
value|12
define|#
directive|define
name|XEN_DOMCTL_getvcpucontext
value|13
define|#
directive|define
name|XEN_DOMCTL_getvcpuinfo
value|14
define|#
directive|define
name|XEN_DOMCTL_max_vcpus
value|15
define|#
directive|define
name|XEN_DOMCTL_scheduler_op
value|16
define|#
directive|define
name|XEN_DOMCTL_setdomainhandle
value|17
define|#
directive|define
name|XEN_DOMCTL_setdebugging
value|18
define|#
directive|define
name|XEN_DOMCTL_irq_permission
value|19
define|#
directive|define
name|XEN_DOMCTL_iomem_permission
value|20
define|#
directive|define
name|XEN_DOMCTL_ioport_permission
value|21
define|#
directive|define
name|XEN_DOMCTL_hypercall_init
value|22
define|#
directive|define
name|XEN_DOMCTL_arch_setup
value|23
define|#
directive|define
name|XEN_DOMCTL_settimeoffset
value|24
define|#
directive|define
name|XEN_DOMCTL_getvcpuaffinity
value|25
define|#
directive|define
name|XEN_DOMCTL_real_mode_area
value|26
define|#
directive|define
name|XEN_DOMCTL_resumedomain
value|27
define|#
directive|define
name|XEN_DOMCTL_sendtrigger
value|28
define|#
directive|define
name|XEN_DOMCTL_subscribe
value|29
define|#
directive|define
name|XEN_DOMCTL_gethvmcontext
value|33
define|#
directive|define
name|XEN_DOMCTL_sethvmcontext
value|34
define|#
directive|define
name|XEN_DOMCTL_set_address_size
value|35
define|#
directive|define
name|XEN_DOMCTL_get_address_size
value|36
define|#
directive|define
name|XEN_DOMCTL_assign_device
value|37
define|#
directive|define
name|XEN_DOMCTL_bind_pt_irq
value|38
define|#
directive|define
name|XEN_DOMCTL_memory_mapping
value|39
define|#
directive|define
name|XEN_DOMCTL_ioport_mapping
value|40
define|#
directive|define
name|XEN_DOMCTL_pin_mem_cacheattr
value|41
define|#
directive|define
name|XEN_DOMCTL_set_ext_vcpucontext
value|42
define|#
directive|define
name|XEN_DOMCTL_get_ext_vcpucontext
value|43
define|#
directive|define
name|XEN_DOMCTL_set_opt_feature
value|44
define|#
directive|define
name|XEN_DOMCTL_test_assign_device
value|45
define|#
directive|define
name|XEN_DOMCTL_set_target
value|46
define|#
directive|define
name|XEN_DOMCTL_deassign_device
value|47
define|#
directive|define
name|XEN_DOMCTL_unbind_pt_irq
value|48
define|#
directive|define
name|XEN_DOMCTL_set_cpuid
value|49
define|#
directive|define
name|XEN_DOMCTL_get_device_group
value|50
define|#
directive|define
name|XEN_DOMCTL_set_machine_address_size
value|51
define|#
directive|define
name|XEN_DOMCTL_get_machine_address_size
value|52
define|#
directive|define
name|XEN_DOMCTL_suppress_spurious_page_faults
value|53
define|#
directive|define
name|XEN_DOMCTL_debug_op
value|54
define|#
directive|define
name|XEN_DOMCTL_gethvmcontext_partial
value|55
define|#
directive|define
name|XEN_DOMCTL_mem_event_op
value|56
define|#
directive|define
name|XEN_DOMCTL_mem_sharing_op
value|57
define|#
directive|define
name|XEN_DOMCTL_disable_migrate
value|58
define|#
directive|define
name|XEN_DOMCTL_gettscinfo
value|59
define|#
directive|define
name|XEN_DOMCTL_settscinfo
value|60
define|#
directive|define
name|XEN_DOMCTL_getpageframeinfo3
value|61
define|#
directive|define
name|XEN_DOMCTL_setvcpuextstate
value|62
define|#
directive|define
name|XEN_DOMCTL_getvcpuextstate
value|63
define|#
directive|define
name|XEN_DOMCTL_set_access_required
value|64
define|#
directive|define
name|XEN_DOMCTL_audit_p2m
value|65
define|#
directive|define
name|XEN_DOMCTL_set_virq_handler
value|66
define|#
directive|define
name|XEN_DOMCTL_gdbsx_guestmemio
value|1000
define|#
directive|define
name|XEN_DOMCTL_gdbsx_pausevcpu
value|1001
define|#
directive|define
name|XEN_DOMCTL_gdbsx_unpausevcpu
value|1002
define|#
directive|define
name|XEN_DOMCTL_gdbsx_domstatus
value|1003
name|uint32_t
name|interface_version
decl_stmt|;
comment|/* XEN_DOMCTL_INTERFACE_VERSION */
name|domid_t
name|domain
decl_stmt|;
union|union
block|{
name|struct
name|xen_domctl_createdomain
name|createdomain
decl_stmt|;
name|struct
name|xen_domctl_getdomaininfo
name|getdomaininfo
decl_stmt|;
name|struct
name|xen_domctl_getmemlist
name|getmemlist
decl_stmt|;
name|struct
name|xen_domctl_getpageframeinfo
name|getpageframeinfo
decl_stmt|;
name|struct
name|xen_domctl_getpageframeinfo2
name|getpageframeinfo2
decl_stmt|;
name|struct
name|xen_domctl_getpageframeinfo3
name|getpageframeinfo3
decl_stmt|;
name|struct
name|xen_domctl_vcpuaffinity
name|vcpuaffinity
decl_stmt|;
name|struct
name|xen_domctl_shadow_op
name|shadow_op
decl_stmt|;
name|struct
name|xen_domctl_max_mem
name|max_mem
decl_stmt|;
name|struct
name|xen_domctl_vcpucontext
name|vcpucontext
decl_stmt|;
name|struct
name|xen_domctl_getvcpuinfo
name|getvcpuinfo
decl_stmt|;
name|struct
name|xen_domctl_max_vcpus
name|max_vcpus
decl_stmt|;
name|struct
name|xen_domctl_scheduler_op
name|scheduler_op
decl_stmt|;
name|struct
name|xen_domctl_setdomainhandle
name|setdomainhandle
decl_stmt|;
name|struct
name|xen_domctl_setdebugging
name|setdebugging
decl_stmt|;
name|struct
name|xen_domctl_irq_permission
name|irq_permission
decl_stmt|;
name|struct
name|xen_domctl_iomem_permission
name|iomem_permission
decl_stmt|;
name|struct
name|xen_domctl_ioport_permission
name|ioport_permission
decl_stmt|;
name|struct
name|xen_domctl_hypercall_init
name|hypercall_init
decl_stmt|;
name|struct
name|xen_domctl_arch_setup
name|arch_setup
decl_stmt|;
name|struct
name|xen_domctl_settimeoffset
name|settimeoffset
decl_stmt|;
name|struct
name|xen_domctl_disable_migrate
name|disable_migrate
decl_stmt|;
name|struct
name|xen_domctl_tsc_info
name|tsc_info
decl_stmt|;
name|struct
name|xen_domctl_real_mode_area
name|real_mode_area
decl_stmt|;
name|struct
name|xen_domctl_hvmcontext
name|hvmcontext
decl_stmt|;
name|struct
name|xen_domctl_hvmcontext_partial
name|hvmcontext_partial
decl_stmt|;
name|struct
name|xen_domctl_address_size
name|address_size
decl_stmt|;
name|struct
name|xen_domctl_sendtrigger
name|sendtrigger
decl_stmt|;
name|struct
name|xen_domctl_get_device_group
name|get_device_group
decl_stmt|;
name|struct
name|xen_domctl_assign_device
name|assign_device
decl_stmt|;
name|struct
name|xen_domctl_bind_pt_irq
name|bind_pt_irq
decl_stmt|;
name|struct
name|xen_domctl_memory_mapping
name|memory_mapping
decl_stmt|;
name|struct
name|xen_domctl_ioport_mapping
name|ioport_mapping
decl_stmt|;
name|struct
name|xen_domctl_pin_mem_cacheattr
name|pin_mem_cacheattr
decl_stmt|;
name|struct
name|xen_domctl_ext_vcpucontext
name|ext_vcpucontext
decl_stmt|;
name|struct
name|xen_domctl_set_opt_feature
name|set_opt_feature
decl_stmt|;
name|struct
name|xen_domctl_set_target
name|set_target
decl_stmt|;
name|struct
name|xen_domctl_subscribe
name|subscribe
decl_stmt|;
name|struct
name|xen_domctl_debug_op
name|debug_op
decl_stmt|;
name|struct
name|xen_domctl_mem_event_op
name|mem_event_op
decl_stmt|;
name|struct
name|xen_domctl_mem_sharing_op
name|mem_sharing_op
decl_stmt|;
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
name|struct
name|xen_domctl_cpuid
name|cpuid
decl_stmt|;
name|struct
name|xen_domctl_vcpuextstate
name|vcpuextstate
decl_stmt|;
endif|#
directive|endif
name|struct
name|xen_domctl_set_access_required
name|access_required
decl_stmt|;
name|struct
name|xen_domctl_audit_p2m
name|audit_p2m
decl_stmt|;
name|struct
name|xen_domctl_set_virq_handler
name|set_virq_handler
decl_stmt|;
name|struct
name|xen_domctl_gdbsx_memio
name|gdbsx_guest_memio
decl_stmt|;
name|struct
name|xen_domctl_gdbsx_pauseunp_vcpu
name|gdbsx_pauseunp_vcpu
decl_stmt|;
name|struct
name|xen_domctl_gdbsx_domstatus
name|gdbsx_domstatus
decl_stmt|;
name|uint8_t
name|pad
index|[
literal|128
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
name|xen_domctl
name|xen_domctl_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_domctl_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XEN_PUBLIC_DOMCTL_H__ */
end_comment

begin_comment
comment|/*  * Local variables:  * mode: C  * c-set-style: "BSD"  * c-basic-offset: 4  * tab-width: 4  * indent-tabs-mode: nil  * End:  */
end_comment

end_unit

