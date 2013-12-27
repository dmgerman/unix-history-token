begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2009-2012 Microsoft Corp.  * Copyright (c) 2012 NetApp Inc.  * Copyright (c) 2012 Citrix Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
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

begin_comment
comment|/*  * MessageId: HV_STATUS_INSUFFICIENT_BUFFERS  * MessageText:  *    You did not supply enough message buffers to send a message.  */
end_comment

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
block|}
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

begin_comment
comment|/*  *  Connection identifier type  */
end_comment

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
name|__packed
name|hv_vmbus_connection_id
typedef|;
end_typedef

begin_comment
comment|/*  * Definition of the hv_vmbus_signal_event hypercall input structure  */
end_comment

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
name|__packed
name|hv_vmbus_input_signal_event
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint64_t
name|align8
decl_stmt|;
name|hv_vmbus_input_signal_event
name|event
decl_stmt|;
block|}
name|__packed
name|hv_vmbus_input_signal_event_buffer
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint64_t
name|guest_id
decl_stmt|;
name|void
modifier|*
name|hypercall_page
decl_stmt|;
name|hv_bool_uint8_t
name|syn_ic_initialized
decl_stmt|;
comment|/* 	 * This is used as an input param to HV_CALL_SIGNAL_EVENT hypercall. 	 * The input param is immutable  in our usage and 	 * must be dynamic mem (vs stack or global). 	 */
name|hv_vmbus_input_signal_event_buffer
modifier|*
name|signal_event_buffer
decl_stmt|;
comment|/* 	 * 8-bytes aligned of the buffer above 	 */
name|hv_vmbus_input_signal_event
modifier|*
name|signal_event_param
decl_stmt|;
name|hv_vmbus_handle
name|syn_ic_msg_page
index|[
name|MAXCPU
index|]
decl_stmt|;
name|hv_vmbus_handle
name|syn_ic_event_page
index|[
name|MAXCPU
index|]
decl_stmt|;
block|}
name|hv_vmbus_context
typedef|;
end_typedef

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
name|monitor_pages
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
comment|/** 	 * List of channels 	 */
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
name|hv_vmbus_handle
name|work_queue
decl_stmt|;
name|struct
name|sema
name|control_sema
decl_stmt|;
block|}
name|hv_vmbus_connection
typedef|;
end_typedef

begin_comment
comment|/*  * Declare the MSR used to identify the guest OS  */
end_comment

begin_define
define|#
directive|define
name|HV_X64_MSR_GUEST_OS_ID
value|0x40000000
end_define

begin_typedef
typedef|typedef
union|union
block|{
name|uint64_t
name|as_uint64_t
decl_stmt|;
struct|struct
block|{
name|uint64_t
name|build_number
range|:
literal|16
decl_stmt|;
name|uint64_t
name|service_version
range|:
literal|8
decl_stmt|;
comment|/* Service Pack, etc. */
name|uint64_t
name|minor_version
range|:
literal|8
decl_stmt|;
name|uint64_t
name|major_version
range|:
literal|8
decl_stmt|;
comment|/* 		 * HV_GUEST_OS_MICROSOFT_IDS (If Vendor=MS) 		 * HV_GUEST_OS_VENDOR 		 */
name|uint64_t
name|os_id
range|:
literal|8
decl_stmt|;
name|uint64_t
name|vendor_id
range|:
literal|16
decl_stmt|;
block|}
name|u
struct|;
block|}
name|hv_vmbus_x64_msr_guest_os_id_contents
typedef|;
end_typedef

begin_comment
comment|/*  *  Declare the MSR used to setup pages used to communicate with the hypervisor  */
end_comment

begin_define
define|#
directive|define
name|HV_X64_MSR_HYPERCALL
value|0x40000001
end_define

begin_typedef
typedef|typedef
union|union
block|{
name|uint64_t
name|as_uint64_t
decl_stmt|;
struct|struct
block|{
name|uint64_t
name|enable
range|:
literal|1
decl_stmt|;
name|uint64_t
name|reserved
range|:
literal|11
decl_stmt|;
name|uint64_t
name|guest_physical_address
range|:
literal|52
decl_stmt|;
block|}
name|u
struct|;
block|}
name|hv_vmbus_x64_msr_hypercall_contents
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
comment|/*  * The below CPUID leaves are present if VersionAndFeatures.HypervisorPresent  * is set by CPUID(HV_CPU_ID_FUNCTION_VERSION_AND_FEATURES).  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|HV_CPU_ID_FUNCTION_VERSION_AND_FEATURES
init|=
literal|0x00000001
block|,
name|HV_CPU_ID_FUNCTION_HV_VENDOR_AND_MAX_FUNCTION
init|=
literal|0x40000000
block|,
name|HV_CPU_ID_FUNCTION_HV_INTERFACE
init|=
literal|0x40000001
block|,
comment|/* 	 * The remaining functions depend on the value 	 * of hv_cpu_id_function_interface 	 */
name|HV_CPU_ID_FUNCTION_MS_HV_VERSION
init|=
literal|0x40000002
block|,
name|HV_CPU_ID_FUNCTION_MS_HV_FEATURES
init|=
literal|0x40000003
block|,
name|HV_CPU_ID_FUNCTION_MS_HV_ENLIGHTENMENT_INFORMATION
init|=
literal|0x40000004
block|,
name|HV_CPU_ID_FUNCTION_MS_HV_IMPLEMENTATION_LIMITS
init|=
literal|0x40000005
block|}
name|hv_vmbus_cpuid_function
typedef|;
end_typedef

begin_comment
comment|/*  * Define the format of the SIMP register  */
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|uint64_t
name|as_uint64_t
decl_stmt|;
struct|struct
block|{
name|uint64_t
name|simp_enabled
range|:
literal|1
decl_stmt|;
name|uint64_t
name|preserved
range|:
literal|11
decl_stmt|;
name|uint64_t
name|base_simp_gpa
range|:
literal|52
decl_stmt|;
block|}
name|u
struct|;
block|}
name|hv_vmbus_synic_simp
typedef|;
end_typedef

begin_comment
comment|/*  * Define the format of the SIEFP register  */
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|uint64_t
name|as_uint64_t
decl_stmt|;
struct|struct
block|{
name|uint64_t
name|siefp_enabled
range|:
literal|1
decl_stmt|;
name|uint64_t
name|preserved
range|:
literal|11
decl_stmt|;
name|uint64_t
name|base_siefp_gpa
range|:
literal|52
decl_stmt|;
block|}
name|u
struct|;
block|}
name|hv_vmbus_synic_siefp
typedef|;
end_typedef

begin_comment
comment|/*  * Define synthetic interrupt source  */
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|uint64_t
name|as_uint64_t
decl_stmt|;
struct|struct
block|{
name|uint64_t
name|vector
range|:
literal|8
decl_stmt|;
name|uint64_t
name|reserved1
range|:
literal|8
decl_stmt|;
name|uint64_t
name|masked
range|:
literal|1
decl_stmt|;
name|uint64_t
name|auto_eoi
range|:
literal|1
decl_stmt|;
name|uint64_t
name|reserved2
range|:
literal|46
decl_stmt|;
block|}
name|u
struct|;
block|}
name|hv_vmbus_synic_sint
typedef|;
end_typedef

begin_comment
comment|/*  * Define syn_ic control register  */
end_comment

begin_typedef
typedef|typedef
union|union
name|_hv_vmbus_synic_scontrol
block|{
name|uint64_t
name|as_uint64_t
decl_stmt|;
struct|struct
block|{
name|uint64_t
name|enable
range|:
literal|1
decl_stmt|;
name|uint64_t
name|reserved
range|:
literal|63
decl_stmt|;
block|}
name|u
struct|;
block|}
name|hv_vmbus_synic_scontrol
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
block|}
name|hv_vmbus_synic_event_flags
typedef|;
end_typedef

begin_comment
comment|/*  * Define synthetic interrupt controller model specific registers  */
end_comment

begin_define
define|#
directive|define
name|HV_X64_MSR_SCONTROL
value|(0x40000080)
end_define

begin_define
define|#
directive|define
name|HV_X64_MSR_SVERSION
value|(0x40000081)
end_define

begin_define
define|#
directive|define
name|HV_X64_MSR_SIEFP
value|(0x40000082)
end_define

begin_define
define|#
directive|define
name|HV_X64_MSR_SIMP
value|(0x40000083)
end_define

begin_define
define|#
directive|define
name|HV_X64_MSR_EOM
value|(0x40000084)
end_define

begin_define
define|#
directive|define
name|HV_X64_MSR_SINT0
value|(0x40000090)
end_define

begin_define
define|#
directive|define
name|HV_X64_MSR_SINT1
value|(0x40000091)
end_define

begin_define
define|#
directive|define
name|HV_X64_MSR_SINT2
value|(0x40000092)
end_define

begin_define
define|#
directive|define
name|HV_X64_MSR_SINT3
value|(0x40000093)
end_define

begin_define
define|#
directive|define
name|HV_X64_MSR_SINT4
value|(0x40000094)
end_define

begin_define
define|#
directive|define
name|HV_X64_MSR_SINT5
value|(0x40000095)
end_define

begin_define
define|#
directive|define
name|HV_X64_MSR_SINT6
value|(0x40000096)
end_define

begin_define
define|#
directive|define
name|HV_X64_MSR_SINT7
value|(0x40000097)
end_define

begin_define
define|#
directive|define
name|HV_X64_MSR_SINT8
value|(0x40000098)
end_define

begin_define
define|#
directive|define
name|HV_X64_MSR_SINT9
value|(0x40000099)
end_define

begin_define
define|#
directive|define
name|HV_X64_MSR_SINT10
value|(0x4000009A)
end_define

begin_define
define|#
directive|define
name|HV_X64_MSR_SINT11
value|(0x4000009B)
end_define

begin_define
define|#
directive|define
name|HV_X64_MSR_SINT12
value|(0x4000009C)
end_define

begin_define
define|#
directive|define
name|HV_X64_MSR_SINT13
value|(0x4000009D)
end_define

begin_define
define|#
directive|define
name|HV_X64_MSR_SINT14
value|(0x4000009E)
end_define

begin_define
define|#
directive|define
name|HV_X64_MSR_SINT15
value|(0x4000009F)
end_define

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
name|hv_vmbus_context
name|hv_vmbus_g_context
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|hv_vmbus_connection
name|hv_vmbus_g_connection
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Private, VM Bus functions  */
end_comment

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
name|void
name|hv_vmbus_on_channel_message
parameter_list|(
name|void
modifier|*
name|context
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
name|int
name|hv_vmbus_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|hv_vmbus_cleanup
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
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|hv_vmbus_synic_init
parameter_list|(
name|void
modifier|*
name|irq_arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|hv_vmbus_synic_cleanup
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hv_vmbus_query_hypervisor_presence
parameter_list|(
name|void
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

begin_function_decl
name|hv_vmbus_channel
modifier|*
name|hv_vmbus_get_channel_from_rel_id
parameter_list|(
name|uint32_t
name|rel_id
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
name|uint32_t
name|child_rel_id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|hv_vmbus_on_events
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * The guest OS needs to register the guest ID with the hypervisor.  * The guest ID is a 64 bit entity and the structure of this ID is  * specified in the Hyper-V specification:  *  * http://msdn.microsoft.com/en-us/library/windows/  * hardware/ff542653%28v=vs.85%29.aspx  *  * While the current guideline does not specify how FreeBSD guest ID(s)  * need to be generated, our plan is to publish the guidelines for  * FreeBSD and other guest operating systems that currently are hosted  * on Hyper-V. The implementation here conforms to this yet  * unpublished guidelines.  *  * Bit(s)  * 63 - Indicates if the OS is Open Source or not; 1 is Open Source  * 62:56 - Os Type; Linux is 0x100, FreeBSD is 0x200  * 55:48 - Distro specific identification  * 47:16 - FreeBSD kernel version number  * 15:0  - Distro specific identification  *  */
end_comment

begin_define
define|#
directive|define
name|HV_FREEBSD_VENDOR_ID
value|0x8200
end_define

begin_define
define|#
directive|define
name|HV_FREEBSD_GUEST_ID
value|hv_generate_guest_id(0,0)
end_define

begin_function
specifier|static
specifier|inline
name|uint64_t
name|hv_generate_guest_id
parameter_list|(
name|uint8_t
name|distro_id_part1
parameter_list|,
name|uint16_t
name|distro_id_part2
parameter_list|)
block|{
name|uint64_t
name|guest_id
decl_stmt|;
name|guest_id
operator|=
operator|(
operator|(
operator|(
name|uint64_t
operator|)
name|HV_FREEBSD_VENDOR_ID
operator|)
operator|<<
literal|48
operator|)
expr_stmt|;
name|guest_id
operator||=
operator|(
operator|(
call|(
name|uint64_t
call|)
argument_list|(
name|distro_id_part1
argument_list|)
operator|)
operator|<<
literal|48
operator|)
expr_stmt|;
name|guest_id
operator||=
operator|(
operator|(
call|(
name|uint64_t
call|)
argument_list|(
name|__FreeBSD_version
argument_list|)
operator|)
operator|<<
literal|16
operator|)
expr_stmt|;
comment|/* in param.h */
name|guest_id
operator||=
operator|(
call|(
name|uint64_t
call|)
argument_list|(
name|distro_id_part2
argument_list|)
operator|)
expr_stmt|;
return|return
name|guest_id
return|;
block|}
end_function

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|int
name|vector
decl_stmt|;
name|void
modifier|*
name|page_buffers
index|[
literal|2
index|]
decl_stmt|;
block|}
name|hv_setup_args
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __HYPERV_PRIV_H__ */
end_comment

end_unit

