begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2009-2012,2016 Microsoft Corp.  * Copyright (c) 2012 NetApp Inc.  * Copyright (c) 2012 Citrix Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__HYPERV_PRIV_H__
end_ifndef

begin_define
define|#
directive|define
name|__HYPERV_PRIV_H__
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/sema.h>
end_include

begin_include
include|#
directive|include
file|<dev/hyperv/include/hyperv.h>
end_include

begin_comment
comment|/*  *  Status codes for hypervisor operations.  */
end_comment

begin_typedef
typedef|typedef
name|uint16_t
name|hv_vmbus_status
typedef|;
end_typedef

begin_define
define|#
directive|define
name|HV_MESSAGE_SIZE
value|(256)
end_define

begin_define
define|#
directive|define
name|HV_MESSAGE_PAYLOAD_BYTE_COUNT
value|(240)
end_define

begin_define
define|#
directive|define
name|HV_MESSAGE_PAYLOAD_QWORD_COUNT
value|(30)
end_define

begin_define
define|#
directive|define
name|HV_ANY_VP
value|(0xFFFFFFFF)
end_define

begin_comment
comment|/*  * Synthetic interrupt controller flag constants.  */
end_comment

begin_define
define|#
directive|define
name|HV_EVENT_FLAGS_COUNT
value|(256 * 8)
end_define

begin_define
define|#
directive|define
name|HV_EVENT_FLAGS_BYTE_COUNT
value|(256)
end_define

begin_define
define|#
directive|define
name|HV_EVENT_FLAGS_DWORD_COUNT
value|(256 / sizeof(uint32_t))
end_define

begin_define
define|#
directive|define
name|HV_EVENT_FLAGS_ULONG_COUNT
value|(256 / sizeof(unsigned long))
end_define

begin_comment
comment|/**  * max channel count<== event_flags_dword_count * bit_of_dword  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__LP64__
end_ifdef

begin_define
define|#
directive|define
name|HV_CHANNEL_ULONG_LEN
value|(64)
end_define

begin_define
define|#
directive|define
name|HV_CHANNEL_ULONG_SHIFT
value|(6)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|HV_CHANNEL_ULONG_LEN
value|(32)
end_define

begin_define
define|#
directive|define
name|HV_CHANNEL_ULONG_SHIFT
value|(5)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|HV_CHANNEL_DWORD_LEN
value|(32)
end_define

begin_define
define|#
directive|define
name|HV_CHANNEL_MAX_COUNT
define|\
value|((HV_EVENT_FLAGS_DWORD_COUNT) * HV_CHANNEL_DWORD_LEN)
end_define

begin_comment
comment|/*  * MessageId: HV_STATUS_INSUFFICIENT_BUFFERS  * MessageText:  *    You did not supply enough message buffers to send a message.  */
end_comment

begin_define
define|#
directive|define
name|HV_STATUS_SUCCESS
value|((uint16_t)0)
end_define

begin_define
define|#
directive|define
name|HV_STATUS_INSUFFICIENT_BUFFERS
value|((uint16_t)0x0013)
end_define

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|hv_vmbus_channel_callback
function_decl|)
parameter_list|(
name|void
modifier|*
name|context
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|void
modifier|*
name|data
decl_stmt|;
name|uint32_t
name|length
decl_stmt|;
block|}
name|hv_vmbus_sg_buffer_list
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint32_t
name|current_interrupt_mask
decl_stmt|;
name|uint32_t
name|current_read_index
decl_stmt|;
name|uint32_t
name|current_write_index
decl_stmt|;
name|uint32_t
name|bytes_avail_to_read
decl_stmt|;
name|uint32_t
name|bytes_avail_to_write
decl_stmt|;
block|}
name|hv_vmbus_ring_buffer_debug_info
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint32_t
name|rel_id
decl_stmt|;
name|hv_vmbus_channel_state
name|state
decl_stmt|;
name|hv_guid
name|interface_type
decl_stmt|;
name|hv_guid
name|interface_instance
decl_stmt|;
name|uint32_t
name|monitor_id
decl_stmt|;
name|uint32_t
name|server_monitor_pending
decl_stmt|;
name|uint32_t
name|server_monitor_latency
decl_stmt|;
name|uint32_t
name|server_monitor_connection_id
decl_stmt|;
name|uint32_t
name|client_monitor_pending
decl_stmt|;
name|uint32_t
name|client_monitor_latency
decl_stmt|;
name|uint32_t
name|client_monitor_connection_id
decl_stmt|;
name|hv_vmbus_ring_buffer_debug_info
name|inbound
decl_stmt|;
name|hv_vmbus_ring_buffer_debug_info
name|outbound
decl_stmt|;
block|}
name|hv_vmbus_channel_debug_info
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
name|hv_vmbus_channel_version_supported
name|version_supported
decl_stmt|;
name|hv_vmbus_channel_open_result
name|open_result
decl_stmt|;
name|hv_vmbus_channel_gpadl_torndown
name|gpadl_torndown
decl_stmt|;
name|hv_vmbus_channel_gpadl_created
name|gpadl_created
decl_stmt|;
name|hv_vmbus_channel_version_response
name|version_response
decl_stmt|;
block|}
name|hv_vmbus_channel_msg_response
typedef|;
end_typedef

begin_comment
comment|/*  * Represents each channel msg on the vmbus connection  * This is a variable-size data structure depending on  * the msg type itself  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|hv_vmbus_channel_msg_info
block|{
comment|/* 	 * Bookkeeping stuff 	 */
name|TAILQ_ENTRY
argument_list|(
argument|hv_vmbus_channel_msg_info
argument_list|)
name|msg_list_entry
expr_stmt|;
comment|/* 	 * So far, this is only used to handle 	 * gpadl body message 	 */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|hv_vmbus_channel_msg_info
argument_list|)
name|sub_msg_list_anchor
expr_stmt|;
comment|/* 	 * Synchronize the request/response if 	 * needed. 	 * KYS: Use a semaphore for now. 	 * Not perf critical. 	 */
name|struct
name|sema
name|wait_sema
decl_stmt|;
name|hv_vmbus_channel_msg_response
name|response
decl_stmt|;
name|uint32_t
name|message_size
decl_stmt|;
comment|/** 	 * The channel message that goes out on 	 *  the "wire". It will contain at 	 *  minimum the 	 *  hv_vmbus_channel_msg_header 	 * header. 	 */
name|unsigned
name|char
name|msg
index|[
literal|0
index|]
decl_stmt|;
block|}
name|hv_vmbus_channel_msg_info
typedef|;
end_typedef

begin_comment
comment|/*  * The format must be the same as hv_vm_data_gpa_direct  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|hv_vmbus_channel_packet_page_buffer
block|{
name|uint16_t
name|type
decl_stmt|;
name|uint16_t
name|data_offset8
decl_stmt|;
name|uint16_t
name|length8
decl_stmt|;
name|uint16_t
name|flags
decl_stmt|;
name|uint64_t
name|transaction_id
decl_stmt|;
name|uint32_t
name|reserved
decl_stmt|;
name|uint32_t
name|range_count
decl_stmt|;
name|hv_vmbus_page_buffer
name|range
index|[
name|HV_MAX_PAGE_BUFFER_COUNT
index|]
decl_stmt|;
block|}
name|__packed
name|hv_vmbus_channel_packet_page_buffer
typedef|;
end_typedef

begin_comment
comment|/*  * The format must be the same as hv_vm_data_gpa_direct  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|hv_vmbus_channel_packet_multipage_buffer
block|{
name|uint16_t
name|type
decl_stmt|;
name|uint16_t
name|data_offset8
decl_stmt|;
name|uint16_t
name|length8
decl_stmt|;
name|uint16_t
name|flags
decl_stmt|;
name|uint64_t
name|transaction_id
decl_stmt|;
name|uint32_t
name|reserved
decl_stmt|;
name|uint32_t
name|range_count
decl_stmt|;
comment|/* Always 1 in this case */
name|hv_vmbus_multipage_buffer
name|range
decl_stmt|;
block|}
name|__packed
name|hv_vmbus_channel_packet_multipage_buffer
typedef|;
end_typedef

begin_enum
enum|enum
block|{
name|HV_VMBUS_MESSAGE_CONNECTION_ID
init|=
literal|1
block|,
name|HV_VMBUS_MESSAGE_PORT_ID
init|=
literal|1
block|,
name|HV_VMBUS_EVENT_CONNECTION_ID
init|=
literal|2
block|,
name|HV_VMBUS_EVENT_PORT_ID
init|=
literal|2
block|,
name|HV_VMBUS_MONITOR_CONNECTION_ID
init|=
literal|3
block|,
name|HV_VMBUS_MONITOR_PORT_ID
init|=
literal|3
block|,
name|HV_VMBUS_MESSAGE_SINT
init|=
literal|2
block|,
name|HV_VMBUS_TIMER_SINT
init|=
literal|4
block|, }
enum|;
end_enum

begin_define
define|#
directive|define
name|HV_PRESENT_BIT
value|0x80000000
end_define

begin_define
define|#
directive|define
name|HV_HYPERCALL_PARAM_ALIGN
value|sizeof(uint64_t)
end_define

begin_struct_decl
struct_decl|struct
name|vmbus_message
struct_decl|;
end_struct_decl

begin_union_decl
union_decl|union
name|vmbus_event_flags
union_decl|;
end_union_decl

begin_comment
comment|/*  * Define hypervisor message types  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|HV_MESSAGE_TYPE_NONE
init|=
literal|0x00000000
block|,
comment|/* 	 * Memory access messages 	 */
name|HV_MESSAGE_TYPE_UNMAPPED_GPA
init|=
literal|0x80000000
block|,
name|HV_MESSAGE_TYPE_GPA_INTERCEPT
init|=
literal|0x80000001
block|,
comment|/* 	 * Timer notification messages 	 */
name|HV_MESSAGE_TIMER_EXPIRED
init|=
literal|0x80000010
block|,
comment|/* 	 * Error messages 	 */
name|HV_MESSAGE_TYPE_INVALID_VP_REGISTER_VALUE
init|=
literal|0x80000020
block|,
name|HV_MESSAGE_TYPE_UNRECOVERABLE_EXCEPTION
init|=
literal|0x80000021
block|,
name|HV_MESSAGE_TYPE_UNSUPPORTED_FEATURE
init|=
literal|0x80000022
block|,
comment|/* 	 * Trace buffer complete messages 	 */
name|HV_MESSAGE_TYPE_EVENT_LOG_BUFFER_COMPLETE
init|=
literal|0x80000040
block|,
comment|/* 	 * Platform-specific processor intercept messages 	 */
name|HV_MESSAGE_TYPE_X64_IO_PORT_INTERCEPT
init|=
literal|0x80010000
block|,
name|HV_MESSAGE_TYPE_X64_MSR_INTERCEPT
init|=
literal|0x80010001
block|,
name|HV_MESSAGE_TYPE_X64_CPU_INTERCEPT
init|=
literal|0x80010002
block|,
name|HV_MESSAGE_TYPE_X64_EXCEPTION_INTERCEPT
init|=
literal|0x80010003
block|,
name|HV_MESSAGE_TYPE_X64_APIC_EOI
init|=
literal|0x80010004
block|,
name|HV_MESSAGE_TYPE_X64_LEGACY_FP_ERROR
init|=
literal|0x80010005
block|}
name|hv_vmbus_msg_type
typedef|;
end_typedef

begin_comment
comment|/*  * Define port identifier type  */
end_comment

begin_typedef
typedef|typedef
union|union
name|_hv_vmbus_port_id
block|{
name|uint32_t
name|as_uint32_t
decl_stmt|;
struct|struct
block|{
name|uint32_t
name|id
range|:
literal|24
decl_stmt|;
name|uint32_t
name|reserved
range|:
literal|8
decl_stmt|;
block|}
name|u
struct|;
block|}
name|hv_vmbus_port_id
typedef|;
end_typedef

begin_comment
comment|/*  * Define synthetic interrupt controller message flag  */
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|uint8_t
name|as_uint8_t
decl_stmt|;
struct|struct
block|{
name|uint8_t
name|message_pending
range|:
literal|1
decl_stmt|;
name|uint8_t
name|reserved
range|:
literal|7
decl_stmt|;
block|}
name|u
struct|;
block|}
name|hv_vmbus_msg_flags
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint64_t
name|hv_vmbus_partition_id
typedef|;
end_typedef

begin_comment
comment|/*  * Define synthetic interrupt controller message header  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|hv_vmbus_msg_type
name|message_type
decl_stmt|;
name|uint8_t
name|payload_size
decl_stmt|;
name|hv_vmbus_msg_flags
name|message_flags
decl_stmt|;
name|uint8_t
name|reserved
index|[
literal|2
index|]
decl_stmt|;
union|union
block|{
name|hv_vmbus_partition_id
name|sender
decl_stmt|;
name|hv_vmbus_port_id
name|port
decl_stmt|;
block|}
name|u
union|;
block|}
name|hv_vmbus_msg_header
typedef|;
end_typedef

begin_comment
comment|/*  *  Define synthetic interrupt controller message format  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|vmbus_message
block|{
name|hv_vmbus_msg_header
name|header
decl_stmt|;
union|union
block|{
name|uint64_t
name|payload
index|[
name|HV_MESSAGE_PAYLOAD_QWORD_COUNT
index|]
decl_stmt|;
block|}
name|u
union|;
block|}
name|hv_vmbus_message
typedef|;
end_typedef

begin_comment
comment|/*  *  Maximum channels is determined by the size of the interrupt  *  page which is PAGE_SIZE. 1/2 of PAGE_SIZE is for  *  send endpoint interrupt and the other is receive  *  endpoint interrupt.  *  *   Note: (PAGE_SIZE>> 1)<< 3 allocates 16348 channels  */
end_comment

begin_define
define|#
directive|define
name|HV_MAX_NUM_CHANNELS
value|(PAGE_SIZE>> 1)<< 3
end_define

begin_comment
comment|/*  * (The value here must be in multiple of 32)  */
end_comment

begin_define
define|#
directive|define
name|HV_MAX_NUM_CHANNELS_SUPPORTED
value|256
end_define

begin_comment
comment|/*  * VM Bus connection states  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|HV_DISCONNECTED
block|,
name|HV_CONNECTING
block|,
name|HV_CONNECTED
block|,
name|HV_DISCONNECTING
block|}
name|hv_vmbus_connect_state
typedef|;
end_typedef

begin_define
define|#
directive|define
name|HV_MAX_SIZE_CHANNEL_MESSAGE
value|HV_MESSAGE_PAYLOAD_BYTE_COUNT
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|hv_vmbus_connect_state
name|connect_state
decl_stmt|;
name|uint32_t
name|next_gpadl_handle
decl_stmt|;
comment|/** 	 * Represents channel interrupts. Each bit position 	 * represents a channel. 	 * When a channel sends an interrupt via VMBUS, it 	 * finds its bit in the send_interrupt_page, set it and 	 * calls Hv to generate a port event. The other end 	 * receives the port event and parse the 	 * recv_interrupt_page to see which bit is set 	 */
name|void
modifier|*
name|interrupt_page
decl_stmt|;
name|void
modifier|*
name|send_interrupt_page
decl_stmt|;
name|void
modifier|*
name|recv_interrupt_page
decl_stmt|;
comment|/* 	 * 2 pages - 1st page for parent->child 	 * notification and 2nd is child->parent 	 * notification 	 */
name|void
modifier|*
name|monitor_page_1
decl_stmt|;
name|void
modifier|*
name|monitor_page_2
decl_stmt|;
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|hv_vmbus_channel_msg_info
argument_list|)
name|channel_msg_anchor
expr_stmt|;
name|struct
name|mtx
name|channel_msg_lock
decl_stmt|;
comment|/** 	 * List of primary channels. Sub channels will be linked 	 * under their primary channel. 	 */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|hv_vmbus_channel
argument_list|)
name|channel_anchor
expr_stmt|;
name|struct
name|mtx
name|channel_lock
decl_stmt|;
comment|/** 	 * channel table for fast lookup through id. 	*/
name|hv_vmbus_channel
modifier|*
modifier|*
name|channels
decl_stmt|;
block|}
name|hv_vmbus_connection
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
name|uint32_t
name|as_uint32_t
decl_stmt|;
struct|struct
block|{
name|uint32_t
name|group_enable
range|:
literal|4
decl_stmt|;
name|uint32_t
name|rsvd_z
range|:
literal|28
decl_stmt|;
block|}
name|u
struct|;
block|}
name|hv_vmbus_monitor_trigger_state
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
name|uint64_t
name|as_uint64_t
decl_stmt|;
struct|struct
block|{
name|uint32_t
name|pending
decl_stmt|;
name|uint32_t
name|armed
decl_stmt|;
block|}
name|u
struct|;
block|}
name|hv_vmbus_monitor_trigger_group
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|hv_vmbus_connection_id
name|connection_id
decl_stmt|;
name|uint16_t
name|flag_number
decl_stmt|;
name|uint16_t
name|rsvd_z
decl_stmt|;
block|}
name|hv_vmbus_monitor_parameter
typedef|;
end_typedef

begin_comment
comment|/*  * hv_vmbus_monitor_page Layout  * ------------------------------------------------------  * | 0   | trigger_state (4 bytes) | Rsvd1 (4 bytes)     |  * | 8   | trigger_group[0]                              |  * | 10  | trigger_group[1]                              |  * | 18  | trigger_group[2]                              |  * | 20  | trigger_group[3]                              |  * | 28  | Rsvd2[0]                                      |  * | 30  | Rsvd2[1]                                      |  * | 38  | Rsvd2[2]                                      |  * | 40  | next_check_time[0][0] | next_check_time[0][1] |  * | ...                                                 |  * | 240 | latency[0][0..3]                              |  * | 340 | Rsvz3[0]                                      |  * | 440 | parameter[0][0]                               |  * | 448 | parameter[0][1]                               |  * | ...                                                 |  * | 840 | Rsvd4[0]                                      |  * ------------------------------------------------------  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|hv_vmbus_monitor_trigger_state
name|trigger_state
decl_stmt|;
name|uint32_t
name|rsvd_z1
decl_stmt|;
name|hv_vmbus_monitor_trigger_group
name|trigger_group
index|[
literal|4
index|]
decl_stmt|;
name|uint64_t
name|rsvd_z2
index|[
literal|3
index|]
decl_stmt|;
name|int32_t
name|next_check_time
index|[
literal|4
index|]
index|[
literal|32
index|]
decl_stmt|;
name|uint16_t
name|latency
index|[
literal|4
index|]
index|[
literal|32
index|]
decl_stmt|;
name|uint64_t
name|rsvd_z3
index|[
literal|32
index|]
decl_stmt|;
name|hv_vmbus_monitor_parameter
name|parameter
index|[
literal|4
index|]
index|[
literal|32
index|]
decl_stmt|;
name|uint8_t
name|rsvd_z4
index|[
literal|1984
index|]
decl_stmt|;
block|}
name|hv_vmbus_monitor_page
typedef|;
end_typedef

begin_comment
comment|/*  *  Define the hv_vmbus_post_message hypercall input structure  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|hv_vmbus_connection_id
name|connection_id
decl_stmt|;
name|uint32_t
name|reserved
decl_stmt|;
name|hv_vmbus_msg_type
name|message_type
decl_stmt|;
name|uint32_t
name|payload_size
decl_stmt|;
name|uint64_t
name|payload
index|[
name|HV_MESSAGE_PAYLOAD_QWORD_COUNT
index|]
decl_stmt|;
block|}
name|hv_vmbus_input_post_message
typedef|;
end_typedef

begin_comment
comment|/*  * Define the synthetic interrupt controller event flags format  */
end_comment

begin_typedef
typedef|typedef
union|union
name|vmbus_event_flags
block|{
name|uint8_t
name|flags8
index|[
name|HV_EVENT_FLAGS_BYTE_COUNT
index|]
decl_stmt|;
name|uint32_t
name|flags32
index|[
name|HV_EVENT_FLAGS_DWORD_COUNT
index|]
decl_stmt|;
name|unsigned
name|long
name|flagsul
index|[
name|HV_EVENT_FLAGS_ULONG_COUNT
index|]
decl_stmt|;
block|}
name|hv_vmbus_synic_event_flags
typedef|;
end_typedef

begin_expr_stmt
name|CTASSERT
argument_list|(
sizeof|sizeof
argument_list|(
name|hv_vmbus_synic_event_flags
argument_list|)
operator|==
name|HV_EVENT_FLAGS_BYTE_COUNT
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Declare the various hypercall operations  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|HV_CALL_POST_MESSAGE
init|=
literal|0x005c
block|,
name|HV_CALL_SIGNAL_EVENT
init|=
literal|0x005d
block|, }
name|hv_vmbus_call_code
typedef|;
end_typedef

begin_comment
comment|/**  * Global variables  */
end_comment

begin_decl_stmt
specifier|extern
name|hv_vmbus_connection
name|hv_vmbus_g_connection
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|vmbus_msg_handler
function_decl|)
parameter_list|(
name|hv_vmbus_channel_msg_header
modifier|*
name|msg
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|hv_vmbus_channel_msg_table_entry
block|{
name|hv_vmbus_channel_msg_type
name|messageType
decl_stmt|;
name|vmbus_msg_handler
name|messageHandler
decl_stmt|;
block|}
name|hv_vmbus_channel_msg_table_entry
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|hv_vmbus_channel_msg_table_entry
name|g_channel_message_table
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Private, VM Bus functions  */
end_comment

begin_struct_decl
struct_decl|struct
name|sysctl_ctx_list
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|sysctl_oid_list
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|hv_ring_buffer_stat
parameter_list|(
name|struct
name|sysctl_ctx_list
modifier|*
name|ctx
parameter_list|,
name|struct
name|sysctl_oid_list
modifier|*
name|tree_node
parameter_list|,
name|hv_vmbus_ring_buffer_info
modifier|*
name|rbi
parameter_list|,
specifier|const
name|char
modifier|*
name|desc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hv_vmbus_ring_buffer_init
parameter_list|(
name|hv_vmbus_ring_buffer_info
modifier|*
name|ring_info
parameter_list|,
name|void
modifier|*
name|buffer
parameter_list|,
name|uint32_t
name|buffer_len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|hv_ring_buffer_cleanup
parameter_list|(
name|hv_vmbus_ring_buffer_info
modifier|*
name|ring_info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hv_ring_buffer_write
parameter_list|(
name|hv_vmbus_ring_buffer_info
modifier|*
name|ring_info
parameter_list|,
name|hv_vmbus_sg_buffer_list
name|sg_buffers
index|[]
parameter_list|,
name|uint32_t
name|sg_buff_count
parameter_list|,
name|boolean_t
modifier|*
name|need_sig
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hv_ring_buffer_peek
parameter_list|(
name|hv_vmbus_ring_buffer_info
modifier|*
name|ring_info
parameter_list|,
name|void
modifier|*
name|buffer
parameter_list|,
name|uint32_t
name|buffer_len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hv_ring_buffer_read
parameter_list|(
name|hv_vmbus_ring_buffer_info
modifier|*
name|ring_info
parameter_list|,
name|void
modifier|*
name|buffer
parameter_list|,
name|uint32_t
name|buffer_len
parameter_list|,
name|uint32_t
name|offset
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|hv_vmbus_get_ring_buffer_interrupt_mask
parameter_list|(
name|hv_vmbus_ring_buffer_info
modifier|*
name|ring_info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|hv_vmbus_dump_ring_info
parameter_list|(
name|hv_vmbus_ring_buffer_info
modifier|*
name|ring_info
parameter_list|,
name|char
modifier|*
name|prefix
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|hv_ring_buffer_read_begin
parameter_list|(
name|hv_vmbus_ring_buffer_info
modifier|*
name|ring_info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|hv_ring_buffer_read_end
parameter_list|(
name|hv_vmbus_ring_buffer_info
modifier|*
name|ring_info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|hv_vmbus_channel
modifier|*
name|hv_vmbus_allocate_channel
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|hv_vmbus_free_vmbus_channel
parameter_list|(
name|hv_vmbus_channel
modifier|*
name|channel
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hv_vmbus_request_channel_offers
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|hv_vmbus_release_unattached_channels
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint16_t
name|hv_vmbus_post_msg_via_msg_ipc
parameter_list|(
name|hv_vmbus_connection_id
name|connection_id
parameter_list|,
name|hv_vmbus_msg_type
name|message_type
parameter_list|,
name|void
modifier|*
name|payload
parameter_list|,
name|size_t
name|payload_size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint16_t
name|hv_vmbus_signal_event
parameter_list|(
name|void
modifier|*
name|con_id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|hv_device
modifier|*
name|hv_vmbus_child_device_create
parameter_list|(
name|hv_guid
name|device_type
parameter_list|,
name|hv_guid
name|device_instance
parameter_list|,
name|hv_vmbus_channel
modifier|*
name|channel
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hv_vmbus_child_device_register
parameter_list|(
name|struct
name|hv_device
modifier|*
name|child_dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hv_vmbus_child_device_unregister
parameter_list|(
name|struct
name|hv_device
modifier|*
name|child_dev
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Connection interfaces  */
end_comment

begin_function_decl
name|int
name|hv_vmbus_connect
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hv_vmbus_disconnect
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hv_vmbus_post_message
parameter_list|(
name|void
modifier|*
name|buffer
parameter_list|,
name|size_t
name|buf_size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hv_vmbus_set_event
parameter_list|(
name|hv_vmbus_channel
modifier|*
name|channel
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Event Timer interfaces  */
end_comment

begin_function_decl
name|void
name|hv_et_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|hv_et_intr
parameter_list|(
name|struct
name|trapframe
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Wait for device creation */
end_comment

begin_function_decl
name|void
name|vmbus_scan
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __HYPERV_PRIV_H__ */
end_comment

end_unit

