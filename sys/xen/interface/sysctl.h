begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  * sysctl.h  *   * System management operations. For use by node control stack.  *   * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to  * deal in the Software without restriction, including without limitation the  * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or  * sell copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER  * DEALINGS IN THE SOFTWARE.  *  * Copyright (c) 2002-2006, K Fraser  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XEN_PUBLIC_SYSCTL_H__
end_ifndef

begin_define
define|#
directive|define
name|__XEN_PUBLIC_SYSCTL_H__
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
literal|"sysctl operations are intended for use by node control tools only"
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
file|"domctl.h"
end_include

begin_define
define|#
directive|define
name|XEN_SYSCTL_INTERFACE_VERSION
value|0x00000006
end_define

begin_comment
comment|/*  * Read console content from Xen buffer ring.  */
end_comment

begin_define
define|#
directive|define
name|XEN_SYSCTL_readconsole
value|1
end_define

begin_struct
struct|struct
name|xen_sysctl_readconsole
block|{
comment|/* IN: Non-zero -> clear after reading. */
name|uint8_t
name|clear
decl_stmt|;
comment|/* IN: Non-zero -> start index specified by @index field. */
name|uint8_t
name|incremental
decl_stmt|;
name|uint8_t
name|pad0
decl_stmt|,
name|pad1
decl_stmt|;
comment|/*      * IN:  Start index for consuming from ring buffer (if @incremental);      * OUT: End index after consuming from ring buffer.      */
name|uint32_t
name|index
decl_stmt|;
comment|/* IN: Virtual address to write console data. */
name|XEN_GUEST_HANDLE_64
argument_list|(
argument|char
argument_list|)
name|buffer
expr_stmt|;
comment|/* IN: Size of buffer; OUT: Bytes written to buffer. */
name|uint32_t
name|count
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_sysctl_readconsole
name|xen_sysctl_readconsole_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_sysctl_readconsole_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Get trace buffers machine base address */
end_comment

begin_define
define|#
directive|define
name|XEN_SYSCTL_tbuf_op
value|2
end_define

begin_struct
struct|struct
name|xen_sysctl_tbuf_op
block|{
comment|/* IN variables */
define|#
directive|define
name|XEN_SYSCTL_TBUFOP_get_info
value|0
define|#
directive|define
name|XEN_SYSCTL_TBUFOP_set_cpu_mask
value|1
define|#
directive|define
name|XEN_SYSCTL_TBUFOP_set_evt_mask
value|2
define|#
directive|define
name|XEN_SYSCTL_TBUFOP_set_size
value|3
define|#
directive|define
name|XEN_SYSCTL_TBUFOP_enable
value|4
define|#
directive|define
name|XEN_SYSCTL_TBUFOP_disable
value|5
name|uint32_t
name|cmd
decl_stmt|;
comment|/* IN/OUT variables */
name|struct
name|xenctl_cpumap
name|cpu_mask
decl_stmt|;
name|uint32_t
name|evt_mask
decl_stmt|;
comment|/* OUT variables */
name|uint64_aligned_t
name|buffer_mfn
decl_stmt|;
name|uint32_t
name|size
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_sysctl_tbuf_op
name|xen_sysctl_tbuf_op_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_sysctl_tbuf_op_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Get physical information about the host machine  */
end_comment

begin_define
define|#
directive|define
name|XEN_SYSCTL_physinfo
value|3
end_define

begin_comment
comment|/* (x86) The platform supports HVM guests. */
end_comment

begin_define
define|#
directive|define
name|_XEN_SYSCTL_PHYSCAP_hvm
value|0
end_define

begin_define
define|#
directive|define
name|XEN_SYSCTL_PHYSCAP_hvm
value|(1u<<_XEN_SYSCTL_PHYSCAP_hvm)
end_define

begin_comment
comment|/* (x86) The platform supports HVM-guest direct access to I/O devices. */
end_comment

begin_define
define|#
directive|define
name|_XEN_SYSCTL_PHYSCAP_hvm_directio
value|1
end_define

begin_define
define|#
directive|define
name|XEN_SYSCTL_PHYSCAP_hvm_directio
value|(1u<<_XEN_SYSCTL_PHYSCAP_hvm_directio)
end_define

begin_struct
struct|struct
name|xen_sysctl_physinfo
block|{
name|uint32_t
name|threads_per_core
decl_stmt|;
name|uint32_t
name|cores_per_socket
decl_stmt|;
name|uint32_t
name|nr_cpus
decl_stmt|;
name|uint32_t
name|nr_nodes
decl_stmt|;
name|uint32_t
name|cpu_khz
decl_stmt|;
name|uint64_aligned_t
name|total_pages
decl_stmt|;
name|uint64_aligned_t
name|free_pages
decl_stmt|;
name|uint64_aligned_t
name|scrub_pages
decl_stmt|;
name|uint32_t
name|hw_cap
index|[
literal|8
index|]
decl_stmt|;
comment|/*      * IN: maximum addressable entry in the caller-provided cpu_to_node array.      * OUT: largest cpu identifier in the system.      * If OUT is greater than IN then the cpu_to_node array is truncated!      */
name|uint32_t
name|max_cpu_id
decl_stmt|;
comment|/*      * If not NULL, this array is filled with node identifier for each cpu.      * If a cpu has no node information (e.g., cpu not present) then the      * sentinel value ~0u is written.      * The size of this array is specified by the caller in @max_cpu_id.      * If the actual @max_cpu_id is smaller than the array then the trailing      * elements of the array will not be written by the sysctl.      */
name|XEN_GUEST_HANDLE_64
argument_list|(
argument|uint32
argument_list|)
name|cpu_to_node
expr_stmt|;
comment|/* XEN_SYSCTL_PHYSCAP_??? */
name|uint32_t
name|capabilities
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_sysctl_physinfo
name|xen_sysctl_physinfo_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_sysctl_physinfo_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Get the ID of the current scheduler.  */
end_comment

begin_define
define|#
directive|define
name|XEN_SYSCTL_sched_id
value|4
end_define

begin_struct
struct|struct
name|xen_sysctl_sched_id
block|{
comment|/* OUT variable */
name|uint32_t
name|sched_id
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_sysctl_sched_id
name|xen_sysctl_sched_id_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_sysctl_sched_id_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Interface for controlling Xen software performance counters. */
end_comment

begin_define
define|#
directive|define
name|XEN_SYSCTL_perfc_op
value|5
end_define

begin_comment
comment|/* Sub-operations: */
end_comment

begin_define
define|#
directive|define
name|XEN_SYSCTL_PERFCOP_reset
value|1
end_define

begin_comment
comment|/* Reset all counters to zero. */
end_comment

begin_define
define|#
directive|define
name|XEN_SYSCTL_PERFCOP_query
value|2
end_define

begin_comment
comment|/* Get perfctr information. */
end_comment

begin_struct
struct|struct
name|xen_sysctl_perfc_desc
block|{
name|char
name|name
index|[
literal|80
index|]
decl_stmt|;
comment|/* name of perf counter */
name|uint32_t
name|nr_vals
decl_stmt|;
comment|/* number of values for this counter */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_sysctl_perfc_desc
name|xen_sysctl_perfc_desc_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_sysctl_perfc_desc_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|uint32_t
name|xen_sysctl_perfc_val_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_sysctl_perfc_val_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|xen_sysctl_perfc_op
block|{
comment|/* IN variables. */
name|uint32_t
name|cmd
decl_stmt|;
comment|/*  XEN_SYSCTL_PERFCOP_??? */
comment|/* OUT variables. */
name|uint32_t
name|nr_counters
decl_stmt|;
comment|/*  number of counters description  */
name|uint32_t
name|nr_vals
decl_stmt|;
comment|/*  number of values  */
comment|/* counter information (or NULL) */
name|XEN_GUEST_HANDLE_64
argument_list|(
argument|xen_sysctl_perfc_desc_t
argument_list|)
name|desc
expr_stmt|;
comment|/* counter values (or NULL) */
name|XEN_GUEST_HANDLE_64
argument_list|(
argument|xen_sysctl_perfc_val_t
argument_list|)
name|val
expr_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_sysctl_perfc_op
name|xen_sysctl_perfc_op_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_sysctl_perfc_op_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|XEN_SYSCTL_getdomaininfolist
value|6
end_define

begin_struct
struct|struct
name|xen_sysctl_getdomaininfolist
block|{
comment|/* IN variables. */
name|domid_t
name|first_domain
decl_stmt|;
name|uint32_t
name|max_domains
decl_stmt|;
name|XEN_GUEST_HANDLE_64
argument_list|(
argument|xen_domctl_getdomaininfo_t
argument_list|)
name|buffer
expr_stmt|;
comment|/* OUT variables. */
name|uint32_t
name|num_domains
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_sysctl_getdomaininfolist
name|xen_sysctl_getdomaininfolist_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_sysctl_getdomaininfolist_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Inject debug keys into Xen. */
end_comment

begin_define
define|#
directive|define
name|XEN_SYSCTL_debug_keys
value|7
end_define

begin_struct
struct|struct
name|xen_sysctl_debug_keys
block|{
comment|/* IN variables. */
name|XEN_GUEST_HANDLE_64
argument_list|(
argument|char
argument_list|)
name|keys
expr_stmt|;
name|uint32_t
name|nr_keys
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_sysctl_debug_keys
name|xen_sysctl_debug_keys_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_sysctl_debug_keys_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Get physical CPU information. */
end_comment

begin_define
define|#
directive|define
name|XEN_SYSCTL_getcpuinfo
value|8
end_define

begin_struct
struct|struct
name|xen_sysctl_cpuinfo
block|{
name|uint64_aligned_t
name|idletime
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_sysctl_cpuinfo
name|xen_sysctl_cpuinfo_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_sysctl_cpuinfo_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|xen_sysctl_getcpuinfo
block|{
comment|/* IN variables. */
name|uint32_t
name|max_cpus
decl_stmt|;
name|XEN_GUEST_HANDLE_64
argument_list|(
argument|xen_sysctl_cpuinfo_t
argument_list|)
name|info
expr_stmt|;
comment|/* OUT variables. */
name|uint32_t
name|nr_cpus
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_sysctl_getcpuinfo
name|xen_sysctl_getcpuinfo_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_sysctl_getcpuinfo_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|XEN_SYSCTL_availheap
value|9
end_define

begin_struct
struct|struct
name|xen_sysctl_availheap
block|{
comment|/* IN variables. */
name|uint32_t
name|min_bitwidth
decl_stmt|;
comment|/* Smallest address width (zero if don't care). */
name|uint32_t
name|max_bitwidth
decl_stmt|;
comment|/* Largest address width (zero if don't care). */
name|int32_t
name|node
decl_stmt|;
comment|/* NUMA node of interest (-1 for all nodes). */
comment|/* OUT variables. */
name|uint64_aligned_t
name|avail_bytes
decl_stmt|;
comment|/* Bytes available in the specified region. */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_sysctl_availheap
name|xen_sysctl_availheap_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_sysctl_availheap_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|XEN_SYSCTL_get_pmstat
value|10
end_define

begin_struct
struct|struct
name|pm_px_val
block|{
name|uint64_aligned_t
name|freq
decl_stmt|;
comment|/* Px core frequency */
name|uint64_aligned_t
name|residency
decl_stmt|;
comment|/* Px residency time */
name|uint64_aligned_t
name|count
decl_stmt|;
comment|/* Px transition count */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|pm_px_val
name|pm_px_val_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|pm_px_val_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|pm_px_stat
block|{
name|uint8_t
name|total
decl_stmt|;
comment|/* total Px states */
name|uint8_t
name|usable
decl_stmt|;
comment|/* usable Px states */
name|uint8_t
name|last
decl_stmt|;
comment|/* last Px state */
name|uint8_t
name|cur
decl_stmt|;
comment|/* current Px state */
name|XEN_GUEST_HANDLE_64
argument_list|(
argument|uint64
argument_list|)
name|trans_pt
expr_stmt|;
comment|/* Px transition table */
name|XEN_GUEST_HANDLE_64
argument_list|(
argument|pm_px_val_t
argument_list|)
name|pt
expr_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|pm_px_stat
name|pm_px_stat_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|pm_px_stat_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|pm_cx_stat
block|{
name|uint32_t
name|nr
decl_stmt|;
comment|/* entry nr in triggers& residencies, including C0 */
name|uint32_t
name|last
decl_stmt|;
comment|/* last Cx state */
name|uint64_aligned_t
name|idle_time
decl_stmt|;
comment|/* idle time from boot */
name|XEN_GUEST_HANDLE_64
argument_list|(
argument|uint64
argument_list|)
name|triggers
expr_stmt|;
comment|/* Cx trigger counts */
name|XEN_GUEST_HANDLE_64
argument_list|(
argument|uint64
argument_list|)
name|residencies
expr_stmt|;
comment|/* Cx residencies */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|xen_sysctl_get_pmstat
block|{
define|#
directive|define
name|PMSTAT_CATEGORY_MASK
value|0xf0
define|#
directive|define
name|PMSTAT_PX
value|0x10
define|#
directive|define
name|PMSTAT_CX
value|0x20
define|#
directive|define
name|PMSTAT_get_max_px
value|(PMSTAT_PX | 0x1)
define|#
directive|define
name|PMSTAT_get_pxstat
value|(PMSTAT_PX | 0x2)
define|#
directive|define
name|PMSTAT_reset_pxstat
value|(PMSTAT_PX | 0x3)
define|#
directive|define
name|PMSTAT_get_max_cx
value|(PMSTAT_CX | 0x1)
define|#
directive|define
name|PMSTAT_get_cxstat
value|(PMSTAT_CX | 0x2)
define|#
directive|define
name|PMSTAT_reset_cxstat
value|(PMSTAT_CX | 0x3)
name|uint32_t
name|type
decl_stmt|;
name|uint32_t
name|cpuid
decl_stmt|;
union|union
block|{
name|struct
name|pm_px_stat
name|getpx
decl_stmt|;
name|struct
name|pm_cx_stat
name|getcx
decl_stmt|;
comment|/* other struct for tx, etc */
block|}
name|u
union|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_sysctl_get_pmstat
name|xen_sysctl_get_pmstat_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_sysctl_get_pmstat_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|XEN_SYSCTL_cpu_hotplug
value|11
end_define

begin_struct
struct|struct
name|xen_sysctl_cpu_hotplug
block|{
comment|/* IN variables */
name|uint32_t
name|cpu
decl_stmt|;
comment|/* Physical cpu. */
define|#
directive|define
name|XEN_SYSCTL_CPU_HOTPLUG_ONLINE
value|0
define|#
directive|define
name|XEN_SYSCTL_CPU_HOTPLUG_OFFLINE
value|1
name|uint32_t
name|op
decl_stmt|;
comment|/* hotplug opcode */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_sysctl_cpu_hotplug
name|xen_sysctl_cpu_hotplug_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_sysctl_cpu_hotplug_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|xen_sysctl
block|{
name|uint32_t
name|cmd
decl_stmt|;
name|uint32_t
name|interface_version
decl_stmt|;
comment|/* XEN_SYSCTL_INTERFACE_VERSION */
union|union
block|{
name|struct
name|xen_sysctl_readconsole
name|readconsole
decl_stmt|;
name|struct
name|xen_sysctl_tbuf_op
name|tbuf_op
decl_stmt|;
name|struct
name|xen_sysctl_physinfo
name|physinfo
decl_stmt|;
name|struct
name|xen_sysctl_sched_id
name|sched_id
decl_stmt|;
name|struct
name|xen_sysctl_perfc_op
name|perfc_op
decl_stmt|;
name|struct
name|xen_sysctl_getdomaininfolist
name|getdomaininfolist
decl_stmt|;
name|struct
name|xen_sysctl_debug_keys
name|debug_keys
decl_stmt|;
name|struct
name|xen_sysctl_getcpuinfo
name|getcpuinfo
decl_stmt|;
name|struct
name|xen_sysctl_availheap
name|availheap
decl_stmt|;
name|struct
name|xen_sysctl_get_pmstat
name|get_pmstat
decl_stmt|;
name|struct
name|xen_sysctl_cpu_hotplug
name|cpu_hotplug
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
name|xen_sysctl
name|xen_sysctl_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_sysctl_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XEN_PUBLIC_SYSCTL_H__ */
end_comment

begin_comment
comment|/*  * Local variables:  * mode: C  * c-set-style: "BSD"  * c-basic-offset: 4  * tab-width: 4  * indent-tabs-mode: nil  * End:  */
end_comment

end_unit

