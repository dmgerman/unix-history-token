begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  * xenoprof.h  *   * Interface for enabling system wide profiling based on hardware performance  * counters  *   * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to  * deal in the Software without restriction, including without limitation the  * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or  * sell copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER  * DEALINGS IN THE SOFTWARE.  *  * Copyright (C) 2005 Hewlett-Packard Co.  * Written by Aravind Menon& Jose Renato Santos  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XEN_PUBLIC_XENOPROF_H__
end_ifndef

begin_define
define|#
directive|define
name|__XEN_PUBLIC_XENOPROF_H__
end_define

begin_include
include|#
directive|include
file|"xen.h"
end_include

begin_comment
comment|/*  * Commands to HYPERVISOR_xenoprof_op().  */
end_comment

begin_define
define|#
directive|define
name|XENOPROF_init
value|0
end_define

begin_define
define|#
directive|define
name|XENOPROF_reset_active_list
value|1
end_define

begin_define
define|#
directive|define
name|XENOPROF_reset_passive_list
value|2
end_define

begin_define
define|#
directive|define
name|XENOPROF_set_active
value|3
end_define

begin_define
define|#
directive|define
name|XENOPROF_set_passive
value|4
end_define

begin_define
define|#
directive|define
name|XENOPROF_reserve_counters
value|5
end_define

begin_define
define|#
directive|define
name|XENOPROF_counter
value|6
end_define

begin_define
define|#
directive|define
name|XENOPROF_setup_events
value|7
end_define

begin_define
define|#
directive|define
name|XENOPROF_enable_virq
value|8
end_define

begin_define
define|#
directive|define
name|XENOPROF_start
value|9
end_define

begin_define
define|#
directive|define
name|XENOPROF_stop
value|10
end_define

begin_define
define|#
directive|define
name|XENOPROF_disable_virq
value|11
end_define

begin_define
define|#
directive|define
name|XENOPROF_release_counters
value|12
end_define

begin_define
define|#
directive|define
name|XENOPROF_shutdown
value|13
end_define

begin_define
define|#
directive|define
name|XENOPROF_get_buffer
value|14
end_define

begin_define
define|#
directive|define
name|XENOPROF_set_backtrace
value|15
end_define

begin_define
define|#
directive|define
name|XENOPROF_last_op
value|15
end_define

begin_define
define|#
directive|define
name|MAX_OPROF_EVENTS
value|32
end_define

begin_define
define|#
directive|define
name|MAX_OPROF_DOMAINS
value|25
end_define

begin_define
define|#
directive|define
name|XENOPROF_CPU_TYPE_SIZE
value|64
end_define

begin_comment
comment|/* Xenoprof performance events (not Xen events) */
end_comment

begin_struct
struct|struct
name|event_log
block|{
name|uint64_t
name|eip
decl_stmt|;
name|uint8_t
name|mode
decl_stmt|;
name|uint8_t
name|event
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* PC value that indicates a special code */
end_comment

begin_define
define|#
directive|define
name|XENOPROF_ESCAPE_CODE
value|~0UL
end_define

begin_comment
comment|/* Transient events for the xenoprof->oprofile cpu buf */
end_comment

begin_define
define|#
directive|define
name|XENOPROF_TRACE_BEGIN
value|1
end_define

begin_comment
comment|/* Xenoprof buffer shared between Xen and domain - 1 per VCPU */
end_comment

begin_struct
struct|struct
name|xenoprof_buf
block|{
name|uint32_t
name|event_head
decl_stmt|;
name|uint32_t
name|event_tail
decl_stmt|;
name|uint32_t
name|event_size
decl_stmt|;
name|uint32_t
name|vcpu_id
decl_stmt|;
name|uint64_t
name|xen_samples
decl_stmt|;
name|uint64_t
name|kernel_samples
decl_stmt|;
name|uint64_t
name|user_samples
decl_stmt|;
name|uint64_t
name|lost_samples
decl_stmt|;
name|struct
name|event_log
name|event_log
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_ifndef
ifndef|#
directive|ifndef
name|__XEN__
end_ifndef

begin_typedef
typedef|typedef
name|struct
name|xenoprof_buf
name|xenoprof_buf_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xenoprof_buf_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|xenoprof_init
block|{
name|int32_t
name|num_events
decl_stmt|;
name|int32_t
name|is_primary
decl_stmt|;
name|char
name|cpu_type
index|[
name|XENOPROF_CPU_TYPE_SIZE
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xenoprof_init
name|xenoprof_init_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xenoprof_init_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|xenoprof_get_buffer
block|{
name|int32_t
name|max_samples
decl_stmt|;
name|int32_t
name|nbuf
decl_stmt|;
name|int32_t
name|bufsize
decl_stmt|;
name|uint64_t
name|buf_gmaddr
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xenoprof_get_buffer
name|xenoprof_get_buffer_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xenoprof_get_buffer_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|xenoprof_counter
block|{
name|uint32_t
name|ind
decl_stmt|;
name|uint64_t
name|count
decl_stmt|;
name|uint32_t
name|enabled
decl_stmt|;
name|uint32_t
name|event
decl_stmt|;
name|uint32_t
name|hypervisor
decl_stmt|;
name|uint32_t
name|kernel
decl_stmt|;
name|uint32_t
name|user
decl_stmt|;
name|uint64_t
name|unit_mask
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xenoprof_counter
name|xenoprof_counter_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xenoprof_counter_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
struct|struct
name|xenoprof_passive
block|{
name|uint16_t
name|domain_id
decl_stmt|;
name|int32_t
name|max_samples
decl_stmt|;
name|int32_t
name|nbuf
decl_stmt|;
name|int32_t
name|bufsize
decl_stmt|;
name|uint64_t
name|buf_gmaddr
decl_stmt|;
block|}
name|xenoprof_passive_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xenoprof_passive_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XEN_PUBLIC_XENOPROF_H__ */
end_comment

begin_comment
comment|/*  * Local variables:  * mode: C  * c-set-style: "BSD"  * c-basic-offset: 4  * tab-width: 4  * indent-tabs-mode: nil  * End:  */
end_comment

end_unit

