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

begin_include
include|#
directive|include
file|"physdev.h"
end_include

begin_include
include|#
directive|include
file|"tmem.h"
end_include

begin_define
define|#
directive|define
name|XEN_SYSCTL_INTERFACE_VERSION
value|0x0000000C
end_define

begin_comment
comment|/*  * Read console content from Xen buffer ring.  */
end_comment

begin_comment
comment|/* XEN_SYSCTL_readconsole */
end_comment

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

begin_comment
comment|/* XEN_SYSCTL_tbuf_op */
end_comment

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
name|xenctl_bitmap
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
comment|/* Also an IN variable! */
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

begin_comment
comment|/* XEN_SYSCTL_physinfo */
end_comment

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
comment|/* # CPUs currently online */
name|uint32_t
name|max_cpu_id
decl_stmt|;
comment|/* Largest possible CPU ID on this host */
name|uint32_t
name|nr_nodes
decl_stmt|;
comment|/* # nodes currently online */
name|uint32_t
name|max_node_id
decl_stmt|;
comment|/* Largest possible node ID on this host */
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
name|uint64_aligned_t
name|outstanding_pages
decl_stmt|;
name|uint32_t
name|hw_cap
index|[
literal|8
index|]
decl_stmt|;
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

begin_comment
comment|/* XEN_SYSCTL_sched_id */
end_comment

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

begin_comment
comment|/* XEN_SYSCTL_perfc_op */
end_comment

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

begin_comment
comment|/* XEN_SYSCTL_getdomaininfolist */
end_comment

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

begin_comment
comment|/* XEN_SYSCTL_debug_keys */
end_comment

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

begin_comment
comment|/* XEN_SYSCTL_getcpuinfo */
end_comment

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

begin_comment
comment|/* XEN_SYSCTL_availheap */
end_comment

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

begin_comment
comment|/* XEN_SYSCTL_get_pmstat */
end_comment

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
name|uint32_t
name|nr_pc
decl_stmt|;
comment|/* entry nr in pc[] */
name|uint32_t
name|nr_cc
decl_stmt|;
comment|/* entry nr in cc[] */
comment|/*      * These two arrays may (and generally will) have unused slots; slots not      * having a corresponding hardware register will not be written by the      * hypervisor. It is therefore up to the caller to put a suitable sentinel      * into all slots before invoking the function.      * Indexing is 1-biased (PC1/CC1 being at index 0).      */
name|XEN_GUEST_HANDLE_64
argument_list|(
argument|uint64
argument_list|)
name|pc
expr_stmt|;
name|XEN_GUEST_HANDLE_64
argument_list|(
argument|uint64
argument_list|)
name|cc
expr_stmt|;
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

begin_comment
comment|/* XEN_SYSCTL_cpu_hotplug */
end_comment

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

begin_comment
comment|/*  * Get/set xen power management, include   * 1. cpufreq governors and related parameters  */
end_comment

begin_comment
comment|/* XEN_SYSCTL_pm_op */
end_comment

begin_struct
struct|struct
name|xen_userspace
block|{
name|uint32_t
name|scaling_setspeed
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_userspace
name|xen_userspace_t
typedef|;
end_typedef

begin_struct
struct|struct
name|xen_ondemand
block|{
name|uint32_t
name|sampling_rate_max
decl_stmt|;
name|uint32_t
name|sampling_rate_min
decl_stmt|;
name|uint32_t
name|sampling_rate
decl_stmt|;
name|uint32_t
name|up_threshold
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_ondemand
name|xen_ondemand_t
typedef|;
end_typedef

begin_comment
comment|/*   * cpufreq para name of this structure named   * same as sysfs file name of native linux  */
end_comment

begin_define
define|#
directive|define
name|CPUFREQ_NAME_LEN
value|16
end_define

begin_struct
struct|struct
name|xen_get_cpufreq_para
block|{
comment|/* IN/OUT variable */
name|uint32_t
name|cpu_num
decl_stmt|;
name|uint32_t
name|freq_num
decl_stmt|;
name|uint32_t
name|gov_num
decl_stmt|;
comment|/* for all governors */
comment|/* OUT variable */
name|XEN_GUEST_HANDLE_64
argument_list|(
argument|uint32
argument_list|)
name|affected_cpus
expr_stmt|;
name|XEN_GUEST_HANDLE_64
argument_list|(
argument|uint32
argument_list|)
name|scaling_available_frequencies
expr_stmt|;
name|XEN_GUEST_HANDLE_64
argument_list|(
argument|char
argument_list|)
name|scaling_available_governors
expr_stmt|;
name|char
name|scaling_driver
index|[
name|CPUFREQ_NAME_LEN
index|]
decl_stmt|;
name|uint32_t
name|cpuinfo_cur_freq
decl_stmt|;
name|uint32_t
name|cpuinfo_max_freq
decl_stmt|;
name|uint32_t
name|cpuinfo_min_freq
decl_stmt|;
name|uint32_t
name|scaling_cur_freq
decl_stmt|;
name|char
name|scaling_governor
index|[
name|CPUFREQ_NAME_LEN
index|]
decl_stmt|;
name|uint32_t
name|scaling_max_freq
decl_stmt|;
name|uint32_t
name|scaling_min_freq
decl_stmt|;
comment|/* for specific governor */
union|union
block|{
name|struct
name|xen_userspace
name|userspace
decl_stmt|;
name|struct
name|xen_ondemand
name|ondemand
decl_stmt|;
block|}
name|u
union|;
name|int32_t
name|turbo_enabled
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|xen_set_cpufreq_gov
block|{
name|char
name|scaling_governor
index|[
name|CPUFREQ_NAME_LEN
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|xen_set_cpufreq_para
block|{
define|#
directive|define
name|SCALING_MAX_FREQ
value|1
define|#
directive|define
name|SCALING_MIN_FREQ
value|2
define|#
directive|define
name|SCALING_SETSPEED
value|3
define|#
directive|define
name|SAMPLING_RATE
value|4
define|#
directive|define
name|UP_THRESHOLD
value|5
name|uint32_t
name|ctrl_type
decl_stmt|;
name|uint32_t
name|ctrl_value
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|xen_sysctl_pm_op
block|{
define|#
directive|define
name|PM_PARA_CATEGORY_MASK
value|0xf0
define|#
directive|define
name|CPUFREQ_PARA
value|0x10
comment|/* cpufreq command type */
define|#
directive|define
name|GET_CPUFREQ_PARA
value|(CPUFREQ_PARA | 0x01)
define|#
directive|define
name|SET_CPUFREQ_GOV
value|(CPUFREQ_PARA | 0x02)
define|#
directive|define
name|SET_CPUFREQ_PARA
value|(CPUFREQ_PARA | 0x03)
define|#
directive|define
name|GET_CPUFREQ_AVGFREQ
value|(CPUFREQ_PARA | 0x04)
comment|/* set/reset scheduler power saving option */
define|#
directive|define
name|XEN_SYSCTL_pm_op_set_sched_opt_smt
value|0x21
comment|/* cpuidle max_cstate access command */
define|#
directive|define
name|XEN_SYSCTL_pm_op_get_max_cstate
value|0x22
define|#
directive|define
name|XEN_SYSCTL_pm_op_set_max_cstate
value|0x23
comment|/* set scheduler migration cost value */
define|#
directive|define
name|XEN_SYSCTL_pm_op_set_vcpu_migration_delay
value|0x24
define|#
directive|define
name|XEN_SYSCTL_pm_op_get_vcpu_migration_delay
value|0x25
comment|/* enable/disable turbo mode when in dbs governor */
define|#
directive|define
name|XEN_SYSCTL_pm_op_enable_turbo
value|0x26
define|#
directive|define
name|XEN_SYSCTL_pm_op_disable_turbo
value|0x27
name|uint32_t
name|cmd
decl_stmt|;
name|uint32_t
name|cpuid
decl_stmt|;
union|union
block|{
name|struct
name|xen_get_cpufreq_para
name|get_para
decl_stmt|;
name|struct
name|xen_set_cpufreq_gov
name|set_gov
decl_stmt|;
name|struct
name|xen_set_cpufreq_para
name|set_para
decl_stmt|;
name|uint64_aligned_t
name|get_avgfreq
decl_stmt|;
name|uint32_t
name|set_sched_opt_smt
decl_stmt|;
name|uint32_t
name|get_max_cstate
decl_stmt|;
name|uint32_t
name|set_max_cstate
decl_stmt|;
name|uint32_t
name|get_vcpu_migration_delay
decl_stmt|;
name|uint32_t
name|set_vcpu_migration_delay
decl_stmt|;
block|}
name|u
union|;
block|}
struct|;
end_struct

begin_comment
comment|/* XEN_SYSCTL_page_offline_op */
end_comment

begin_struct
struct|struct
name|xen_sysctl_page_offline_op
block|{
comment|/* IN: range of page to be offlined */
define|#
directive|define
name|sysctl_page_offline
value|1
define|#
directive|define
name|sysctl_page_online
value|2
define|#
directive|define
name|sysctl_query_page_offline
value|3
name|uint32_t
name|cmd
decl_stmt|;
name|uint32_t
name|start
decl_stmt|;
name|uint32_t
name|end
decl_stmt|;
comment|/* OUT: result of page offline request */
comment|/*      * bit 0~15: result flags      * bit 16~31: owner      */
name|XEN_GUEST_HANDLE
argument_list|(
argument|uint32
argument_list|)
name|status
expr_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PG_OFFLINE_STATUS_MASK
value|(0xFFUL)
end_define

begin_comment
comment|/* The result is invalid, i.e. HV does not handle it */
end_comment

begin_define
define|#
directive|define
name|PG_OFFLINE_INVALID
value|(0x1UL<< 0)
end_define

begin_define
define|#
directive|define
name|PG_OFFLINE_OFFLINED
value|(0x1UL<< 1)
end_define

begin_define
define|#
directive|define
name|PG_OFFLINE_PENDING
value|(0x1UL<< 2)
end_define

begin_define
define|#
directive|define
name|PG_OFFLINE_FAILED
value|(0x1UL<< 3)
end_define

begin_define
define|#
directive|define
name|PG_OFFLINE_AGAIN
value|(0x1UL<< 4)
end_define

begin_define
define|#
directive|define
name|PG_ONLINE_FAILED
value|PG_OFFLINE_FAILED
end_define

begin_define
define|#
directive|define
name|PG_ONLINE_ONLINED
value|PG_OFFLINE_OFFLINED
end_define

begin_define
define|#
directive|define
name|PG_OFFLINE_STATUS_OFFLINED
value|(0x1UL<< 1)
end_define

begin_define
define|#
directive|define
name|PG_OFFLINE_STATUS_ONLINE
value|(0x1UL<< 2)
end_define

begin_define
define|#
directive|define
name|PG_OFFLINE_STATUS_OFFLINE_PENDING
value|(0x1UL<< 3)
end_define

begin_define
define|#
directive|define
name|PG_OFFLINE_STATUS_BROKEN
value|(0x1UL<< 4)
end_define

begin_define
define|#
directive|define
name|PG_OFFLINE_MISC_MASK
value|(0xFFUL<< 4)
end_define

begin_comment
comment|/* valid when PG_OFFLINE_FAILED or PG_OFFLINE_PENDING */
end_comment

begin_define
define|#
directive|define
name|PG_OFFLINE_XENPAGE
value|(0x1UL<< 8)
end_define

begin_define
define|#
directive|define
name|PG_OFFLINE_DOM0PAGE
value|(0x1UL<< 9)
end_define

begin_define
define|#
directive|define
name|PG_OFFLINE_ANONYMOUS
value|(0x1UL<< 10)
end_define

begin_define
define|#
directive|define
name|PG_OFFLINE_NOT_CONV_RAM
value|(0x1UL<< 11)
end_define

begin_define
define|#
directive|define
name|PG_OFFLINE_OWNED
value|(0x1UL<< 12)
end_define

begin_define
define|#
directive|define
name|PG_OFFLINE_BROKEN
value|(0x1UL<< 13)
end_define

begin_define
define|#
directive|define
name|PG_ONLINE_BROKEN
value|PG_OFFLINE_BROKEN
end_define

begin_define
define|#
directive|define
name|PG_OFFLINE_OWNER_SHIFT
value|16
end_define

begin_comment
comment|/* XEN_SYSCTL_lockprof_op */
end_comment

begin_comment
comment|/* Sub-operations: */
end_comment

begin_define
define|#
directive|define
name|XEN_SYSCTL_LOCKPROF_reset
value|1
end_define

begin_comment
comment|/* Reset all profile data to zero. */
end_comment

begin_define
define|#
directive|define
name|XEN_SYSCTL_LOCKPROF_query
value|2
end_define

begin_comment
comment|/* Get lock profile information. */
end_comment

begin_comment
comment|/* Record-type: */
end_comment

begin_define
define|#
directive|define
name|LOCKPROF_TYPE_GLOBAL
value|0
end_define

begin_comment
comment|/* global lock, idx meaningless */
end_comment

begin_define
define|#
directive|define
name|LOCKPROF_TYPE_PERDOM
value|1
end_define

begin_comment
comment|/* per-domain lock, idx is domid */
end_comment

begin_define
define|#
directive|define
name|LOCKPROF_TYPE_N
value|2
end_define

begin_comment
comment|/* number of types */
end_comment

begin_struct
struct|struct
name|xen_sysctl_lockprof_data
block|{
name|char
name|name
index|[
literal|40
index|]
decl_stmt|;
comment|/* lock name (may include up to 2 %d specifiers) */
name|int32_t
name|type
decl_stmt|;
comment|/* LOCKPROF_TYPE_??? */
name|int32_t
name|idx
decl_stmt|;
comment|/* index (e.g. domain id) */
name|uint64_aligned_t
name|lock_cnt
decl_stmt|;
comment|/* # of locking succeeded */
name|uint64_aligned_t
name|block_cnt
decl_stmt|;
comment|/* # of wait for lock */
name|uint64_aligned_t
name|lock_time
decl_stmt|;
comment|/* nsecs lock held */
name|uint64_aligned_t
name|block_time
decl_stmt|;
comment|/* nsecs waited for lock */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_sysctl_lockprof_data
name|xen_sysctl_lockprof_data_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_sysctl_lockprof_data_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|xen_sysctl_lockprof_op
block|{
comment|/* IN variables. */
name|uint32_t
name|cmd
decl_stmt|;
comment|/* XEN_SYSCTL_LOCKPROF_??? */
name|uint32_t
name|max_elem
decl_stmt|;
comment|/* size of output buffer */
comment|/* OUT variables (query only). */
name|uint32_t
name|nr_elem
decl_stmt|;
comment|/* number of elements available */
name|uint64_aligned_t
name|time
decl_stmt|;
comment|/* nsecs of profile measurement */
comment|/* profile information (or NULL) */
name|XEN_GUEST_HANDLE_64
argument_list|(
argument|xen_sysctl_lockprof_data_t
argument_list|)
name|data
expr_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_sysctl_lockprof_op
name|xen_sysctl_lockprof_op_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_sysctl_lockprof_op_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* XEN_SYSCTL_cputopoinfo */
end_comment

begin_define
define|#
directive|define
name|XEN_INVALID_CORE_ID
value|(~0U)
end_define

begin_define
define|#
directive|define
name|XEN_INVALID_SOCKET_ID
value|(~0U)
end_define

begin_define
define|#
directive|define
name|XEN_INVALID_NODE_ID
value|(~0U)
end_define

begin_struct
struct|struct
name|xen_sysctl_cputopo
block|{
name|uint32_t
name|core
decl_stmt|;
name|uint32_t
name|socket
decl_stmt|;
name|uint32_t
name|node
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_sysctl_cputopo
name|xen_sysctl_cputopo_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_sysctl_cputopo_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * IN:  *  - a NULL 'cputopo' handle is a request for maximun 'num_cpus'.  *  - otherwise it's the number of entries in 'cputopo'  *  * OUT:  *  - If 'num_cpus' is less than the number Xen wants to write but the handle  *    handle is not a NULL one, partial data gets returned and 'num_cpus' gets  *    updated to reflect the intended number.  *  - Otherwise, 'num_cpus' shall indicate the number of entries written, which  *    may be less than the input value.  */
end_comment

begin_struct
struct|struct
name|xen_sysctl_cputopoinfo
block|{
name|uint32_t
name|num_cpus
decl_stmt|;
name|XEN_GUEST_HANDLE_64
argument_list|(
argument|xen_sysctl_cputopo_t
argument_list|)
name|cputopo
expr_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_sysctl_cputopoinfo
name|xen_sysctl_cputopoinfo_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_sysctl_cputopoinfo_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* XEN_SYSCTL_numainfo */
end_comment

begin_define
define|#
directive|define
name|XEN_INVALID_MEM_SZ
value|(~0U)
end_define

begin_define
define|#
directive|define
name|XEN_INVALID_NODE_DIST
value|(~0U)
end_define

begin_struct
struct|struct
name|xen_sysctl_meminfo
block|{
name|uint64_t
name|memsize
decl_stmt|;
name|uint64_t
name|memfree
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_sysctl_meminfo
name|xen_sysctl_meminfo_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_sysctl_meminfo_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * IN:  *  - Both 'meminfo' and 'distance' handles being null is a request  *    for maximum value of 'num_nodes'.  *  - Otherwise it's the number of entries in 'meminfo' and square root  *    of number of entries in 'distance' (when corresponding handle is  *    non-null)  *  * OUT:  *  - If 'num_nodes' is less than the number Xen wants to write but either  *    handle is not a NULL one, partial data gets returned and 'num_nodes'  *    gets updated to reflect the intended number.  *  - Otherwise, 'num_nodes' shall indicate the number of entries written, which  *    may be less than the input value.  */
end_comment

begin_struct
struct|struct
name|xen_sysctl_numainfo
block|{
name|uint32_t
name|num_nodes
decl_stmt|;
name|XEN_GUEST_HANDLE_64
argument_list|(
argument|xen_sysctl_meminfo_t
argument_list|)
name|meminfo
expr_stmt|;
comment|/*      * Distance between nodes 'i' and 'j' is stored in index 'i*N + j',      * where N is the number of nodes that will be returned in 'num_nodes'      * (i.e. not 'num_nodes' provided by the caller)      */
name|XEN_GUEST_HANDLE_64
argument_list|(
argument|uint32
argument_list|)
name|distance
expr_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_sysctl_numainfo
name|xen_sysctl_numainfo_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_sysctl_numainfo_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* XEN_SYSCTL_cpupool_op */
end_comment

begin_define
define|#
directive|define
name|XEN_SYSCTL_CPUPOOL_OP_CREATE
value|1
end_define

begin_comment
comment|/* C */
end_comment

begin_define
define|#
directive|define
name|XEN_SYSCTL_CPUPOOL_OP_DESTROY
value|2
end_define

begin_comment
comment|/* D */
end_comment

begin_define
define|#
directive|define
name|XEN_SYSCTL_CPUPOOL_OP_INFO
value|3
end_define

begin_comment
comment|/* I */
end_comment

begin_define
define|#
directive|define
name|XEN_SYSCTL_CPUPOOL_OP_ADDCPU
value|4
end_define

begin_comment
comment|/* A */
end_comment

begin_define
define|#
directive|define
name|XEN_SYSCTL_CPUPOOL_OP_RMCPU
value|5
end_define

begin_comment
comment|/* R */
end_comment

begin_define
define|#
directive|define
name|XEN_SYSCTL_CPUPOOL_OP_MOVEDOMAIN
value|6
end_define

begin_comment
comment|/* M */
end_comment

begin_define
define|#
directive|define
name|XEN_SYSCTL_CPUPOOL_OP_FREEINFO
value|7
end_define

begin_comment
comment|/* F */
end_comment

begin_define
define|#
directive|define
name|XEN_SYSCTL_CPUPOOL_PAR_ANY
value|0xFFFFFFFF
end_define

begin_struct
struct|struct
name|xen_sysctl_cpupool_op
block|{
name|uint32_t
name|op
decl_stmt|;
comment|/* IN */
name|uint32_t
name|cpupool_id
decl_stmt|;
comment|/* IN: CDIARM OUT: CI */
name|uint32_t
name|sched_id
decl_stmt|;
comment|/* IN: C      OUT: I  */
name|uint32_t
name|domid
decl_stmt|;
comment|/* IN: M              */
name|uint32_t
name|cpu
decl_stmt|;
comment|/* IN: AR             */
name|uint32_t
name|n_dom
decl_stmt|;
comment|/*            OUT: I  */
name|struct
name|xenctl_bitmap
name|cpumap
decl_stmt|;
comment|/*     OUT: IF */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_sysctl_cpupool_op
name|xen_sysctl_cpupool_op_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_sysctl_cpupool_op_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|ARINC653_MAX_DOMAINS_PER_SCHEDULE
value|64
end_define

begin_comment
comment|/*  * This structure is used to pass a new ARINC653 schedule from a  * privileged domain (ie dom0) to Xen.  */
end_comment

begin_struct
struct|struct
name|xen_sysctl_arinc653_schedule
block|{
comment|/* major_frame holds the time for the new schedule's major frame      * in nanoseconds. */
name|uint64_aligned_t
name|major_frame
decl_stmt|;
comment|/* num_sched_entries holds how many of the entries in the      * sched_entries[] array are valid. */
name|uint8_t
name|num_sched_entries
decl_stmt|;
comment|/* The sched_entries array holds the actual schedule entries. */
struct|struct
block|{
comment|/* dom_handle must match a domain's UUID */
name|xen_domain_handle_t
name|dom_handle
decl_stmt|;
comment|/* If a domain has multiple VCPUs, vcpu_id specifies which one          * this schedule entry applies to. It should be set to 0 if          * there is only one VCPU for the domain. */
name|unsigned
name|int
name|vcpu_id
decl_stmt|;
comment|/* runtime specifies the amount of time that should be allocated          * to this VCPU per major frame. It is specified in nanoseconds */
name|uint64_aligned_t
name|runtime
decl_stmt|;
block|}
name|sched_entries
index|[
name|ARINC653_MAX_DOMAINS_PER_SCHEDULE
index|]
struct|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_sysctl_arinc653_schedule
name|xen_sysctl_arinc653_schedule_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_sysctl_arinc653_schedule_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|xen_sysctl_credit_schedule
block|{
comment|/* Length of timeslice in milliseconds */
define|#
directive|define
name|XEN_SYSCTL_CSCHED_TSLICE_MAX
value|1000
define|#
directive|define
name|XEN_SYSCTL_CSCHED_TSLICE_MIN
value|1
name|unsigned
name|tslice_ms
decl_stmt|;
comment|/* Rate limit (minimum timeslice) in microseconds */
define|#
directive|define
name|XEN_SYSCTL_SCHED_RATELIMIT_MAX
value|500000
define|#
directive|define
name|XEN_SYSCTL_SCHED_RATELIMIT_MIN
value|100
name|unsigned
name|ratelimit_us
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_sysctl_credit_schedule
name|xen_sysctl_credit_schedule_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_sysctl_credit_schedule_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* XEN_SYSCTL_scheduler_op */
end_comment

begin_comment
comment|/* Set or get info? */
end_comment

begin_define
define|#
directive|define
name|XEN_SYSCTL_SCHEDOP_putinfo
value|0
end_define

begin_define
define|#
directive|define
name|XEN_SYSCTL_SCHEDOP_getinfo
value|1
end_define

begin_struct
struct|struct
name|xen_sysctl_scheduler_op
block|{
name|uint32_t
name|cpupool_id
decl_stmt|;
comment|/* Cpupool whose scheduler is to be targetted. */
name|uint32_t
name|sched_id
decl_stmt|;
comment|/* XEN_SCHEDULER_* (domctl.h) */
name|uint32_t
name|cmd
decl_stmt|;
comment|/* XEN_SYSCTL_SCHEDOP_* */
union|union
block|{
struct|struct
name|xen_sysctl_sched_arinc653
block|{
name|XEN_GUEST_HANDLE_64
argument_list|(
argument|xen_sysctl_arinc653_schedule_t
argument_list|)
name|schedule
expr_stmt|;
block|}
name|sched_arinc653
struct|;
name|struct
name|xen_sysctl_credit_schedule
name|sched_credit
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
name|xen_sysctl_scheduler_op
name|xen_sysctl_scheduler_op_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_sysctl_scheduler_op_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* XEN_SYSCTL_coverage_op */
end_comment

begin_comment
comment|/*  * Get total size of information, to help allocate  * the buffer. The pointer points to a 32 bit value.  */
end_comment

begin_define
define|#
directive|define
name|XEN_SYSCTL_COVERAGE_get_total_size
value|0
end_define

begin_comment
comment|/*  * Read coverage information in a single run  * You must use a tool to split them.  */
end_comment

begin_define
define|#
directive|define
name|XEN_SYSCTL_COVERAGE_read
value|1
end_define

begin_comment
comment|/*  * Reset all the coverage counters to 0  * No parameters.  */
end_comment

begin_define
define|#
directive|define
name|XEN_SYSCTL_COVERAGE_reset
value|2
end_define

begin_comment
comment|/*  * Like XEN_SYSCTL_COVERAGE_read but reset also  * counters to 0 in a single call.  */
end_comment

begin_define
define|#
directive|define
name|XEN_SYSCTL_COVERAGE_read_and_reset
value|3
end_define

begin_struct
struct|struct
name|xen_sysctl_coverage_op
block|{
name|uint32_t
name|cmd
decl_stmt|;
comment|/* XEN_SYSCTL_COVERAGE_* */
union|union
block|{
name|uint32_t
name|total_size
decl_stmt|;
comment|/* OUT */
name|XEN_GUEST_HANDLE_64
argument_list|(
argument|uint8
argument_list|)
name|raw_info
expr_stmt|;
comment|/* OUT */
block|}
name|u
union|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_sysctl_coverage_op
name|xen_sysctl_coverage_op_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_sysctl_coverage_op_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|XEN_SYSCTL_PSR_CMT_get_total_rmid
value|0
end_define

begin_define
define|#
directive|define
name|XEN_SYSCTL_PSR_CMT_get_l3_upscaling_factor
value|1
end_define

begin_comment
comment|/* The L3 cache size is returned in KB unit */
end_comment

begin_define
define|#
directive|define
name|XEN_SYSCTL_PSR_CMT_get_l3_cache_size
value|2
end_define

begin_define
define|#
directive|define
name|XEN_SYSCTL_PSR_CMT_enabled
value|3
end_define

begin_define
define|#
directive|define
name|XEN_SYSCTL_PSR_CMT_get_l3_event_mask
value|4
end_define

begin_struct
struct|struct
name|xen_sysctl_psr_cmt_op
block|{
name|uint32_t
name|cmd
decl_stmt|;
comment|/* IN: XEN_SYSCTL_PSR_CMT_* */
name|uint32_t
name|flags
decl_stmt|;
comment|/* padding variable, may be extended for future use */
union|union
block|{
name|uint64_t
name|data
decl_stmt|;
comment|/* OUT */
struct|struct
block|{
name|uint32_t
name|cpu
decl_stmt|;
comment|/* IN */
name|uint32_t
name|rsvd
decl_stmt|;
block|}
name|l3_cache
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
name|xen_sysctl_psr_cmt_op
name|xen_sysctl_psr_cmt_op_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_sysctl_psr_cmt_op_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* XEN_SYSCTL_pcitopoinfo */
end_comment

begin_define
define|#
directive|define
name|XEN_INVALID_DEV
value|(XEN_INVALID_NODE_ID - 1)
end_define

begin_struct
struct|struct
name|xen_sysctl_pcitopoinfo
block|{
comment|/*      * IN: Number of elements in 'pcitopo' and 'nodes' arrays.      * OUT: Number of processed elements of those arrays.      */
name|uint32_t
name|num_devs
decl_stmt|;
comment|/* IN: list of devices for which node IDs are requested. */
name|XEN_GUEST_HANDLE_64
argument_list|(
argument|physdev_pci_device_t
argument_list|)
name|devs
expr_stmt|;
comment|/*      * OUT: node identifier for each device.      * If information for a particular device is not available then      * corresponding entry will be set to XEN_INVALID_NODE_ID. If      * device is not known to the hypervisor then XEN_INVALID_DEV      * will be provided.      */
name|XEN_GUEST_HANDLE_64
argument_list|(
argument|uint32
argument_list|)
name|nodes
expr_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_sysctl_pcitopoinfo
name|xen_sysctl_pcitopoinfo_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_sysctl_pcitopoinfo_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|XEN_SYSCTL_PSR_CAT_get_l3_info
value|0
end_define

begin_struct
struct|struct
name|xen_sysctl_psr_cat_op
block|{
name|uint32_t
name|cmd
decl_stmt|;
comment|/* IN: XEN_SYSCTL_PSR_CAT_* */
name|uint32_t
name|target
decl_stmt|;
comment|/* IN */
union|union
block|{
struct|struct
block|{
name|uint32_t
name|cbm_len
decl_stmt|;
comment|/* OUT: CBM length */
name|uint32_t
name|cos_max
decl_stmt|;
comment|/* OUT: Maximum COS */
block|}
name|l3_info
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
name|xen_sysctl_psr_cat_op
name|xen_sysctl_psr_cat_op_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_sysctl_psr_cat_op_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|XEN_SYSCTL_TMEM_OP_ALL_CLIENTS
value|0xFFFFU
end_define

begin_define
define|#
directive|define
name|XEN_SYSCTL_TMEM_OP_THAW
value|0
end_define

begin_define
define|#
directive|define
name|XEN_SYSCTL_TMEM_OP_FREEZE
value|1
end_define

begin_define
define|#
directive|define
name|XEN_SYSCTL_TMEM_OP_FLUSH
value|2
end_define

begin_define
define|#
directive|define
name|XEN_SYSCTL_TMEM_OP_DESTROY
value|3
end_define

begin_define
define|#
directive|define
name|XEN_SYSCTL_TMEM_OP_LIST
value|4
end_define

begin_define
define|#
directive|define
name|XEN_SYSCTL_TMEM_OP_SET_WEIGHT
value|5
end_define

begin_define
define|#
directive|define
name|XEN_SYSCTL_TMEM_OP_SET_CAP
value|6
end_define

begin_define
define|#
directive|define
name|XEN_SYSCTL_TMEM_OP_SET_COMPRESS
value|7
end_define

begin_define
define|#
directive|define
name|XEN_SYSCTL_TMEM_OP_QUERY_FREEABLE_MB
value|8
end_define

begin_define
define|#
directive|define
name|XEN_SYSCTL_TMEM_OP_SAVE_BEGIN
value|10
end_define

begin_define
define|#
directive|define
name|XEN_SYSCTL_TMEM_OP_SAVE_GET_VERSION
value|11
end_define

begin_define
define|#
directive|define
name|XEN_SYSCTL_TMEM_OP_SAVE_GET_MAXPOOLS
value|12
end_define

begin_define
define|#
directive|define
name|XEN_SYSCTL_TMEM_OP_SAVE_GET_CLIENT_WEIGHT
value|13
end_define

begin_define
define|#
directive|define
name|XEN_SYSCTL_TMEM_OP_SAVE_GET_CLIENT_CAP
value|14
end_define

begin_define
define|#
directive|define
name|XEN_SYSCTL_TMEM_OP_SAVE_GET_CLIENT_FLAGS
value|15
end_define

begin_define
define|#
directive|define
name|XEN_SYSCTL_TMEM_OP_SAVE_GET_POOL_FLAGS
value|16
end_define

begin_define
define|#
directive|define
name|XEN_SYSCTL_TMEM_OP_SAVE_GET_POOL_NPAGES
value|17
end_define

begin_define
define|#
directive|define
name|XEN_SYSCTL_TMEM_OP_SAVE_GET_POOL_UUID
value|18
end_define

begin_define
define|#
directive|define
name|XEN_SYSCTL_TMEM_OP_SAVE_GET_NEXT_PAGE
value|19
end_define

begin_define
define|#
directive|define
name|XEN_SYSCTL_TMEM_OP_SAVE_GET_NEXT_INV
value|20
end_define

begin_define
define|#
directive|define
name|XEN_SYSCTL_TMEM_OP_SAVE_END
value|21
end_define

begin_define
define|#
directive|define
name|XEN_SYSCTL_TMEM_OP_RESTORE_BEGIN
value|30
end_define

begin_define
define|#
directive|define
name|XEN_SYSCTL_TMEM_OP_RESTORE_PUT_PAGE
value|32
end_define

begin_define
define|#
directive|define
name|XEN_SYSCTL_TMEM_OP_RESTORE_FLUSH_PAGE
value|33
end_define

begin_comment
comment|/*  * XEN_SYSCTL_TMEM_OP_SAVE_GET_NEXT_[PAGE|INV] override the 'buf' in  * xen_sysctl_tmem_op with this structure - sometimes with an extra  * page tackled on.  */
end_comment

begin_struct
struct|struct
name|tmem_handle
block|{
name|uint32_t
name|pool_id
decl_stmt|;
name|uint32_t
name|index
decl_stmt|;
name|xen_tmem_oid_t
name|oid
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|xen_sysctl_tmem_op
block|{
name|uint32_t
name|cmd
decl_stmt|;
comment|/* IN: XEN_SYSCTL_TMEM_OP_* . */
name|int32_t
name|pool_id
decl_stmt|;
comment|/* IN: 0 by default unless _SAVE_*, RESTORE_* .*/
name|uint32_t
name|cli_id
decl_stmt|;
comment|/* IN: client id, 0 for XEN_SYSCTL_TMEM_QUERY_FREEABLE_MB                            for all others can be the domain id or                            XEN_SYSCTL_TMEM_OP_ALL_CLIENTS for all. */
name|uint32_t
name|arg1
decl_stmt|;
comment|/* IN: If not applicable to command use 0. */
name|uint32_t
name|arg2
decl_stmt|;
comment|/* IN: If not applicable to command use 0. */
name|uint32_t
name|pad
decl_stmt|;
comment|/* Padding so structure is the same under 32 and 64. */
name|xen_tmem_oid_t
name|oid
decl_stmt|;
comment|/* IN: If not applicable to command use 0s. */
name|XEN_GUEST_HANDLE_64
argument_list|(
argument|char
argument_list|)
name|buf
expr_stmt|;
comment|/* IN/OUT: Buffer to save and restore ops. */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xen_sysctl_tmem_op
name|xen_sysctl_tmem_op_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_sysctl_tmem_op_t
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
define|#
directive|define
name|XEN_SYSCTL_readconsole
value|1
define|#
directive|define
name|XEN_SYSCTL_tbuf_op
value|2
define|#
directive|define
name|XEN_SYSCTL_physinfo
value|3
define|#
directive|define
name|XEN_SYSCTL_sched_id
value|4
define|#
directive|define
name|XEN_SYSCTL_perfc_op
value|5
define|#
directive|define
name|XEN_SYSCTL_getdomaininfolist
value|6
define|#
directive|define
name|XEN_SYSCTL_debug_keys
value|7
define|#
directive|define
name|XEN_SYSCTL_getcpuinfo
value|8
define|#
directive|define
name|XEN_SYSCTL_availheap
value|9
define|#
directive|define
name|XEN_SYSCTL_get_pmstat
value|10
define|#
directive|define
name|XEN_SYSCTL_cpu_hotplug
value|11
define|#
directive|define
name|XEN_SYSCTL_pm_op
value|12
define|#
directive|define
name|XEN_SYSCTL_page_offline_op
value|14
define|#
directive|define
name|XEN_SYSCTL_lockprof_op
value|15
define|#
directive|define
name|XEN_SYSCTL_cputopoinfo
value|16
define|#
directive|define
name|XEN_SYSCTL_numainfo
value|17
define|#
directive|define
name|XEN_SYSCTL_cpupool_op
value|18
define|#
directive|define
name|XEN_SYSCTL_scheduler_op
value|19
define|#
directive|define
name|XEN_SYSCTL_coverage_op
value|20
define|#
directive|define
name|XEN_SYSCTL_psr_cmt_op
value|21
define|#
directive|define
name|XEN_SYSCTL_pcitopoinfo
value|22
define|#
directive|define
name|XEN_SYSCTL_psr_cat_op
value|23
define|#
directive|define
name|XEN_SYSCTL_tmem_op
value|24
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
name|xen_sysctl_cputopoinfo
name|cputopoinfo
decl_stmt|;
name|struct
name|xen_sysctl_pcitopoinfo
name|pcitopoinfo
decl_stmt|;
name|struct
name|xen_sysctl_numainfo
name|numainfo
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
name|struct
name|xen_sysctl_pm_op
name|pm_op
decl_stmt|;
name|struct
name|xen_sysctl_page_offline_op
name|page_offline
decl_stmt|;
name|struct
name|xen_sysctl_lockprof_op
name|lockprof_op
decl_stmt|;
name|struct
name|xen_sysctl_cpupool_op
name|cpupool_op
decl_stmt|;
name|struct
name|xen_sysctl_scheduler_op
name|scheduler_op
decl_stmt|;
name|struct
name|xen_sysctl_coverage_op
name|coverage_op
decl_stmt|;
name|struct
name|xen_sysctl_psr_cmt_op
name|psr_cmt_op
decl_stmt|;
name|struct
name|xen_sysctl_psr_cat_op
name|psr_cat_op
decl_stmt|;
name|struct
name|xen_sysctl_tmem_op
name|tmem_op
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
comment|/*  * Local variables:  * mode: C  * c-file-style: "BSD"  * c-basic-offset: 4  * tab-width: 4  * indent-tabs-mode: nil  * End:  */
end_comment

end_unit

