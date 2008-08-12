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
value|0x00000003
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
comment|/* IN variables. */
name|uint32_t
name|clear
decl_stmt|;
comment|/* Non-zero -> clear after reading. */
name|XEN_GUEST_HANDLE_64
argument_list|(
argument|char
argument_list|)
name|buffer
expr_stmt|;
comment|/* Buffer start */
comment|/* IN/OUT variables. */
name|uint32_t
name|count
decl_stmt|;
comment|/* In: Buffer size;  Out: Used buffer size  */
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
name|sockets_per_node
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
name|uint64_t
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

