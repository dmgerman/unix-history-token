begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2009-2012 Microsoft Corp.  * Copyright (c) 2012 NetApp Inc.  * Copyright (c) 2012 Citrix Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/**  * HyperV definitions for messages that are sent between instances of the  * Channel Management Library in separate partitions, or in some cases,  * back to itself.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__HYPERV_H__
end_ifndef

begin_define
define|#
directive|define
name|__HYPERV_H__
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/mbuf.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/kthread.h>
end_include

begin_include
include|#
directive|include
file|<sys/taskqueue.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/sema.h>
end_include

begin_include
include|#
directive|include
file|<sys/smp.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_param.h>
end_include

begin_include
include|#
directive|include
file|<vm/pmap.h>
end_include

begin_include
include|#
directive|include
file|<amd64/include/xen/synch_bitops.h>
end_include

begin_include
include|#
directive|include
file|<amd64/include/atomic.h>
end_include

begin_typedef
typedef|typedef
name|uint8_t
name|hv_bool_uint8_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|HV_S_OK
value|0x00000000
end_define

begin_define
define|#
directive|define
name|HV_E_FAIL
value|0x80004005
end_define

begin_define
define|#
directive|define
name|HV_ERROR_NOT_SUPPORTED
value|0x80070032
end_define

begin_define
define|#
directive|define
name|HV_ERROR_MACHINE_LOCKED
value|0x800704F7
end_define

begin_comment
comment|/*  * VMBUS version is 32 bit, upper 16 bit for major_number and lower  * 16 bit for minor_number.  *  * 0.13  --  Windows Server 2008  * 1.1   --  Windows 7  * 2.4   --  Windows 8  * 3.0   --  Windows 8.1  */
end_comment

begin_define
define|#
directive|define
name|HV_VMBUS_VERSION_WS2008
value|((0<< 16) | (13))
end_define

begin_define
define|#
directive|define
name|HV_VMBUS_VERSION_WIN7
value|((1<< 16) | (1))
end_define

begin_define
define|#
directive|define
name|HV_VMBUS_VERSION_WIN8
value|((2<< 16) | (4))
end_define

begin_define
define|#
directive|define
name|HV_VMBUS_VERSION_WIN8_1
value|((3<< 16) | (0))
end_define

begin_define
define|#
directive|define
name|HV_VMBUS_VERSION_INVALID
value|-1
end_define

begin_define
define|#
directive|define
name|HV_VMBUS_VERSION_CURRENT
value|HV_VMBUS_VERSION_WIN8_1
end_define

begin_comment
comment|/*  * Make maximum size of pipe payload of 16K  */
end_comment

begin_define
define|#
directive|define
name|HV_MAX_PIPE_DATA_PAYLOAD
value|(sizeof(BYTE) * 16384)
end_define

begin_comment
comment|/*  * Define pipe_mode values  */
end_comment

begin_define
define|#
directive|define
name|HV_VMBUS_PIPE_TYPE_BYTE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|HV_VMBUS_PIPE_TYPE_MESSAGE
value|0x00000004
end_define

begin_comment
comment|/*  * The size of the user defined data buffer for non-pipe offers  */
end_comment

begin_define
define|#
directive|define
name|HV_MAX_USER_DEFINED_BYTES
value|120
end_define

begin_comment
comment|/*  *  The size of the user defined data buffer for pipe offers  */
end_comment

begin_define
define|#
directive|define
name|HV_MAX_PIPE_USER_DEFINED_BYTES
value|116
end_define

begin_define
define|#
directive|define
name|HV_MAX_PAGE_BUFFER_COUNT
value|32
end_define

begin_define
define|#
directive|define
name|HV_MAX_MULTIPAGE_BUFFER_COUNT
value|32
end_define

begin_define
define|#
directive|define
name|HV_ALIGN_UP
parameter_list|(
name|value
parameter_list|,
name|align
parameter_list|)
define|\
value|(((value)& (align-1)) ?				\ 		    (((value) + (align-1))& ~(align-1) ) : (value))
end_define

begin_define
define|#
directive|define
name|HV_ALIGN_DOWN
parameter_list|(
name|value
parameter_list|,
name|align
parameter_list|)
value|( (value)& ~(align-1) )
end_define

begin_define
define|#
directive|define
name|HV_NUM_PAGES_SPANNED
parameter_list|(
name|addr
parameter_list|,
name|len
parameter_list|)
define|\
value|((HV_ALIGN_UP(addr+len, PAGE_SIZE) -			\ 		    HV_ALIGN_DOWN(addr, PAGE_SIZE))>> PAGE_SHIFT )
end_define

begin_typedef
typedef|typedef
struct|struct
name|hv_guid
block|{
name|unsigned
name|char
name|data
index|[
literal|16
index|]
decl_stmt|;
block|}
name|__packed
name|hv_guid
typedef|;
end_typedef

begin_function_decl
name|int
name|snprintf_hv_guid
parameter_list|(
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
specifier|const
name|hv_guid
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|HV_NIC_GUID
define|\
value|.data = {0x63, 0x51, 0x61, 0xF8, 0x3E, 0xDF, 0xc5, 0x46,	\ 		0x91, 0x3F, 0xF2, 0xD2, 0xF9, 0x65, 0xED, 0x0E}
end_define

begin_define
define|#
directive|define
name|HV_IDE_GUID
define|\
value|.data = {0x32, 0x26, 0x41, 0x32, 0xcb, 0x86, 0xa2, 0x44,	\ 		 0x9b, 0x5c, 0x50, 0xd1, 0x41, 0x73, 0x54, 0xf5}
end_define

begin_define
define|#
directive|define
name|HV_SCSI_GUID
define|\
value|.data = {0xd9, 0x63, 0x61, 0xba, 0xa1, 0x04, 0x29, 0x4d,	\ 		 0xb6, 0x05, 0x72, 0xe2, 0xff, 0xb1, 0xdc, 0x7f}
end_define

begin_comment
comment|/*  * At the center of the Channel Management library is  * the Channel Offer. This struct contains the  * fundamental information about an offer.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|hv_vmbus_channel_offer
block|{
name|hv_guid
name|interface_type
decl_stmt|;
name|hv_guid
name|interface_instance
decl_stmt|;
name|uint64_t
name|interrupt_latency_in_100ns_units
decl_stmt|;
name|uint32_t
name|interface_revision
decl_stmt|;
name|uint32_t
name|server_context_area_size
decl_stmt|;
comment|/* in bytes */
name|uint16_t
name|channel_flags
decl_stmt|;
name|uint16_t
name|mmio_megabytes
decl_stmt|;
comment|/* in bytes * 1024 * 1024 */
union|union
block|{
comment|/*          * Non-pipes: The user has HV_MAX_USER_DEFINED_BYTES bytes.          */
struct|struct
block|{
name|uint8_t
name|user_defined
index|[
name|HV_MAX_USER_DEFINED_BYTES
index|]
decl_stmt|;
block|}
name|__packed
name|standard
struct|;
comment|/*          * Pipes: The following structure is an integrated pipe protocol, which          *        is implemented on top of standard user-defined data. pipe          *        clients  have HV_MAX_PIPE_USER_DEFINED_BYTES left for their          *        own use.          */
struct|struct
block|{
name|uint32_t
name|pipe_mode
decl_stmt|;
name|uint8_t
name|user_defined
index|[
name|HV_MAX_PIPE_USER_DEFINED_BYTES
index|]
decl_stmt|;
block|}
name|__packed
name|pipe
struct|;
block|}
name|u
union|;
comment|/* 	 * Sub_channel_index, newly added in Win8. 	 */
name|uint16_t
name|sub_channel_index
decl_stmt|;
name|uint16_t
name|padding
decl_stmt|;
block|}
name|__packed
name|hv_vmbus_channel_offer
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint32_t
name|hv_gpadl_handle
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
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
block|}
name|__packed
name|hv_vm_packet_descriptor
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint32_t
name|hv_previous_packet_offset
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|hv_previous_packet_offset
name|previous_packet_start_offset
decl_stmt|;
name|hv_vm_packet_descriptor
name|descriptor
decl_stmt|;
block|}
name|__packed
name|hv_vm_packet_header
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint32_t
name|byte_count
decl_stmt|;
name|uint32_t
name|byte_offset
decl_stmt|;
block|}
name|__packed
name|hv_vm_transfer_page
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|hv_vm_packet_descriptor
name|d
decl_stmt|;
name|uint16_t
name|transfer_page_set_id
decl_stmt|;
name|hv_bool_uint8_t
name|sender_owns_set
decl_stmt|;
name|uint8_t
name|reserved
decl_stmt|;
name|uint32_t
name|range_count
decl_stmt|;
name|hv_vm_transfer_page
name|ranges
index|[
literal|1
index|]
decl_stmt|;
block|}
name|__packed
name|hv_vm_transfer_page_packet_header
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|hv_vm_packet_descriptor
name|d
decl_stmt|;
name|uint32_t
name|gpadl
decl_stmt|;
name|uint32_t
name|reserved
decl_stmt|;
block|}
name|__packed
name|hv_vm_gpadl_packet_header
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|hv_vm_packet_descriptor
name|d
decl_stmt|;
name|uint32_t
name|gpadl
decl_stmt|;
name|uint16_t
name|transfer_page_set_id
decl_stmt|;
name|uint16_t
name|reserved
decl_stmt|;
block|}
name|__packed
name|hv_vm_add_remove_transfer_page_set
typedef|;
end_typedef

begin_comment
comment|/*  * This structure defines a range in guest  * physical space that can be made  * to look virtually contiguous.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint32_t
name|byte_count
decl_stmt|;
name|uint32_t
name|byte_offset
decl_stmt|;
name|uint64_t
name|pfn_array
index|[
literal|0
index|]
decl_stmt|;
block|}
name|__packed
name|hv_gpa_range
typedef|;
end_typedef

begin_comment
comment|/*  * This is the format for an Establish Gpadl packet, which contains a handle  * by which this GPADL will be known and a set of GPA ranges associated with  * it.  This can be converted to a MDL by the guest OS.  If there are multiple  * GPA ranges, then the resulting MDL will be "chained," representing multiple  * VA ranges.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|hv_vm_packet_descriptor
name|d
decl_stmt|;
name|uint32_t
name|gpadl
decl_stmt|;
name|uint32_t
name|range_count
decl_stmt|;
name|hv_gpa_range
name|range
index|[
literal|1
index|]
decl_stmt|;
block|}
name|__packed
name|hv_vm_establish_gpadl
typedef|;
end_typedef

begin_comment
comment|/*  * This is the format for a Teardown Gpadl packet, which indicates that the  * GPADL handle in the Establish Gpadl packet will never be referenced again.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|hv_vm_packet_descriptor
name|d
decl_stmt|;
name|uint32_t
name|gpadl
decl_stmt|;
comment|/* for alignment to a 8-byte boundary */
name|uint32_t
name|reserved
decl_stmt|;
block|}
name|__packed
name|hv_vm_teardown_gpadl
typedef|;
end_typedef

begin_comment
comment|/*  * This is the format for a GPA-Direct packet, which contains a set of GPA  * ranges, in addition to commands and/or data.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|hv_vm_packet_descriptor
name|d
decl_stmt|;
name|uint32_t
name|reserved
decl_stmt|;
name|uint32_t
name|range_count
decl_stmt|;
name|hv_gpa_range
name|range
index|[
literal|1
index|]
decl_stmt|;
block|}
name|__packed
name|hv_vm_data_gpa_direct
typedef|;
end_typedef

begin_comment
comment|/*  * This is the format for a Additional data Packet.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|hv_vm_packet_descriptor
name|d
decl_stmt|;
name|uint64_t
name|total_bytes
decl_stmt|;
name|uint32_t
name|byte_offset
decl_stmt|;
name|uint32_t
name|byte_count
decl_stmt|;
name|uint8_t
name|data
index|[
literal|1
index|]
decl_stmt|;
block|}
name|__packed
name|hv_vm_additional_data
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
name|hv_vm_packet_descriptor
name|simple_header
decl_stmt|;
name|hv_vm_transfer_page_packet_header
name|transfer_page_header
decl_stmt|;
name|hv_vm_gpadl_packet_header
name|gpadl_header
decl_stmt|;
name|hv_vm_add_remove_transfer_page_set
name|add_remove_transfer_page_header
decl_stmt|;
name|hv_vm_establish_gpadl
name|establish_gpadl_header
decl_stmt|;
name|hv_vm_teardown_gpadl
name|teardown_gpadl_header
decl_stmt|;
name|hv_vm_data_gpa_direct
name|data_gpa_direct_header
decl_stmt|;
block|}
name|__packed
name|hv_vm_packet_largest_possible_header
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|HV_VMBUS_PACKET_TYPE_INVALID
init|=
literal|0x0
block|,
name|HV_VMBUS_PACKET_TYPES_SYNCH
init|=
literal|0x1
block|,
name|HV_VMBUS_PACKET_TYPE_ADD_TRANSFER_PAGE_SET
init|=
literal|0x2
block|,
name|HV_VMBUS_PACKET_TYPE_REMOVE_TRANSFER_PAGE_SET
init|=
literal|0x3
block|,
name|HV_VMBUS_PACKET_TYPE_ESTABLISH_GPADL
init|=
literal|0x4
block|,
name|HV_VMBUS_PACKET_TYPE_TEAR_DOWN_GPADL
init|=
literal|0x5
block|,
name|HV_VMBUS_PACKET_TYPE_DATA_IN_BAND
init|=
literal|0x6
block|,
name|HV_VMBUS_PACKET_TYPE_DATA_USING_TRANSFER_PAGES
init|=
literal|0x7
block|,
name|HV_VMBUS_PACKET_TYPE_DATA_USING_GPADL
init|=
literal|0x8
block|,
name|HV_VMBUS_PACKET_TYPE_DATA_USING_GPA_DIRECT
init|=
literal|0x9
block|,
name|HV_VMBUS_PACKET_TYPE_CANCEL_REQUEST
init|=
literal|0xa
block|,
name|HV_VMBUS_PACKET_TYPE_COMPLETION
init|=
literal|0xb
block|,
name|HV_VMBUS_PACKET_TYPE_DATA_USING_ADDITIONAL_PACKETS
init|=
literal|0xc
block|,
name|HV_VMBUS_PACKET_TYPE_ADDITIONAL_DATA
init|=
literal|0xd
block|}
name|hv_vmbus_packet_type
typedef|;
end_typedef

begin_define
define|#
directive|define
name|HV_VMBUS_DATA_PACKET_FLAG_COMPLETION_REQUESTED
value|1
end_define

begin_comment
comment|/*  * Version 1 messages  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|HV_CHANNEL_MESSAGE_INVALID
init|=
literal|0
block|,
name|HV_CHANNEL_MESSAGE_OFFER_CHANNEL
init|=
literal|1
block|,
name|HV_CHANNEL_MESSAGE_RESCIND_CHANNEL_OFFER
init|=
literal|2
block|,
name|HV_CHANNEL_MESSAGE_REQUEST_OFFERS
init|=
literal|3
block|,
name|HV_CHANNEL_MESSAGE_ALL_OFFERS_DELIVERED
init|=
literal|4
block|,
name|HV_CHANNEL_MESSAGE_OPEN_CHANNEL
init|=
literal|5
block|,
name|HV_CHANNEL_MESSAGE_OPEN_CHANNEL_RESULT
init|=
literal|6
block|,
name|HV_CHANNEL_MESSAGE_CLOSE_CHANNEL
init|=
literal|7
block|,
name|HV_CHANNEL_MESSAGEL_GPADL_HEADER
init|=
literal|8
block|,
name|HV_CHANNEL_MESSAGE_GPADL_BODY
init|=
literal|9
block|,
name|HV_CHANNEL_MESSAGE_GPADL_CREATED
init|=
literal|10
block|,
name|HV_CHANNEL_MESSAGE_GPADL_TEARDOWN
init|=
literal|11
block|,
name|HV_CHANNEL_MESSAGE_GPADL_TORNDOWN
init|=
literal|12
block|,
name|HV_CHANNEL_MESSAGE_REL_ID_RELEASED
init|=
literal|13
block|,
name|HV_CHANNEL_MESSAGE_INITIATED_CONTACT
init|=
literal|14
block|,
name|HV_CHANNEL_MESSAGE_VERSION_RESPONSE
init|=
literal|15
block|,
name|HV_CHANNEL_MESSAGE_UNLOAD
init|=
literal|16
block|,
name|HV_CHANNEL_MESSAGE_COUNT
block|}
name|hv_vmbus_channel_msg_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|hv_vmbus_channel_msg_type
name|message_type
decl_stmt|;
name|uint32_t
name|padding
decl_stmt|;
block|}
name|__packed
name|hv_vmbus_channel_msg_header
typedef|;
end_typedef

begin_comment
comment|/*  * Query VMBus Version parameters  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|hv_vmbus_channel_msg_header
name|header
decl_stmt|;
name|uint32_t
name|version
decl_stmt|;
block|}
name|__packed
name|hv_vmbus_channel_query_vmbus_version
typedef|;
end_typedef

begin_comment
comment|/*  * VMBus Version Supported parameters  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|hv_vmbus_channel_msg_header
name|header
decl_stmt|;
name|hv_bool_uint8_t
name|version_supported
decl_stmt|;
block|}
name|__packed
name|hv_vmbus_channel_version_supported
typedef|;
end_typedef

begin_comment
comment|/*  * Channel Offer parameters  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|hv_vmbus_channel_msg_header
name|header
decl_stmt|;
name|hv_vmbus_channel_offer
name|offer
decl_stmt|;
name|uint32_t
name|child_rel_id
decl_stmt|;
name|uint8_t
name|monitor_id
decl_stmt|;
comment|/* 	 * This field has been split into a bit field on Win7 	 * and higher. 	 */
name|uint8_t
name|monitor_allocated
range|:
literal|1
decl_stmt|;
name|uint8_t
name|reserved
range|:
literal|7
decl_stmt|;
comment|/* 	 * Following fields were added in win7 and higher. 	 * Make sure to check the version before accessing these fields. 	 * 	 * If "is_dedicated_interrupt" is set, we must not set the 	 * associated bit in the channel bitmap while sending the 	 * interrupt to the host. 	 * 	 * connection_id is used in signaling the host. 	 */
name|uint16_t
name|is_dedicated_interrupt
range|:
literal|1
decl_stmt|;
name|uint16_t
name|reserved1
range|:
literal|15
decl_stmt|;
name|uint32_t
name|connection_id
decl_stmt|;
block|}
name|__packed
name|hv_vmbus_channel_offer_channel
typedef|;
end_typedef

begin_comment
comment|/*  * Rescind Offer parameters  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|hv_vmbus_channel_msg_header
name|header
decl_stmt|;
name|uint32_t
name|child_rel_id
decl_stmt|;
block|}
name|__packed
name|hv_vmbus_channel_rescind_offer
typedef|;
end_typedef

begin_comment
comment|/*  * Request Offer -- no parameters, SynIC message contains the partition ID  *  * Set Snoop -- no parameters, SynIC message contains the partition ID  *  * Clear Snoop -- no parameters, SynIC message contains the partition ID  *  * All Offers Delivered -- no parameters, SynIC message contains the  * partition ID  *  * Flush Client -- no parameters, SynIC message contains the partition ID  */
end_comment

begin_comment
comment|/*  * Open Channel parameters  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|hv_vmbus_channel_msg_header
name|header
decl_stmt|;
comment|/*      * Identifies the specific VMBus channel that is being opened.      */
name|uint32_t
name|child_rel_id
decl_stmt|;
comment|/*      * ID making a particular open request at a channel offer unique.      */
name|uint32_t
name|open_id
decl_stmt|;
comment|/*      * GPADL for the channel's ring buffer.      */
name|hv_gpadl_handle
name|ring_buffer_gpadl_handle
decl_stmt|;
comment|/*      * Before win8, all incoming channel interrupts are only      * delivered on cpu 0. Setting this value to 0 would      * preserve the earlier behavior.      */
name|uint32_t
name|target_vcpu
decl_stmt|;
comment|/*      * The upstream ring buffer begins at offset zero in the memory described      * by ring_buffer_gpadl_handle. The downstream ring buffer follows it at      * this offset (in pages).      */
name|uint32_t
name|downstream_ring_buffer_page_offset
decl_stmt|;
comment|/*      * User-specific data to be passed along to the server endpoint.      */
name|uint8_t
name|user_data
index|[
name|HV_MAX_USER_DEFINED_BYTES
index|]
decl_stmt|;
block|}
name|__packed
name|hv_vmbus_channel_open_channel
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint32_t
name|hv_nt_status
typedef|;
end_typedef

begin_comment
comment|/*  * Open Channel Result parameters  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|hv_vmbus_channel_msg_header
name|header
decl_stmt|;
name|uint32_t
name|child_rel_id
decl_stmt|;
name|uint32_t
name|open_id
decl_stmt|;
name|hv_nt_status
name|status
decl_stmt|;
block|}
name|__packed
name|hv_vmbus_channel_open_result
typedef|;
end_typedef

begin_comment
comment|/*  * Close channel parameters  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|hv_vmbus_channel_msg_header
name|header
decl_stmt|;
name|uint32_t
name|child_rel_id
decl_stmt|;
block|}
name|__packed
name|hv_vmbus_channel_close_channel
typedef|;
end_typedef

begin_comment
comment|/*  * Channel Message GPADL  */
end_comment

begin_define
define|#
directive|define
name|HV_GPADL_TYPE_RING_BUFFER
value|1
end_define

begin_define
define|#
directive|define
name|HV_GPADL_TYPE_SERVER_SAVE_AREA
value|2
end_define

begin_define
define|#
directive|define
name|HV_GPADL_TYPE_TRANSACTION
value|8
end_define

begin_comment
comment|/*  * The number of PFNs in a GPADL message is defined by the number of pages  * that would be spanned by byte_count and byte_offset.  If the implied number  * of PFNs won't fit in this packet, there will be a follow-up packet that  * contains more  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|hv_vmbus_channel_msg_header
name|header
decl_stmt|;
name|uint32_t
name|child_rel_id
decl_stmt|;
name|uint32_t
name|gpadl
decl_stmt|;
name|uint16_t
name|range_buf_len
decl_stmt|;
name|uint16_t
name|range_count
decl_stmt|;
name|hv_gpa_range
name|range
index|[
literal|0
index|]
decl_stmt|;
block|}
name|__packed
name|hv_vmbus_channel_gpadl_header
typedef|;
end_typedef

begin_comment
comment|/*  * This is the follow-up packet that contains more PFNs  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|hv_vmbus_channel_msg_header
name|header
decl_stmt|;
name|uint32_t
name|message_number
decl_stmt|;
name|uint32_t
name|gpadl
decl_stmt|;
name|uint64_t
name|pfn
index|[
literal|0
index|]
decl_stmt|;
block|}
name|__packed
name|hv_vmbus_channel_gpadl_body
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|hv_vmbus_channel_msg_header
name|header
decl_stmt|;
name|uint32_t
name|child_rel_id
decl_stmt|;
name|uint32_t
name|gpadl
decl_stmt|;
name|uint32_t
name|creation_status
decl_stmt|;
block|}
name|__packed
name|hv_vmbus_channel_gpadl_created
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|hv_vmbus_channel_msg_header
name|header
decl_stmt|;
name|uint32_t
name|child_rel_id
decl_stmt|;
name|uint32_t
name|gpadl
decl_stmt|;
block|}
name|__packed
name|hv_vmbus_channel_gpadl_teardown
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|hv_vmbus_channel_msg_header
name|header
decl_stmt|;
name|uint32_t
name|gpadl
decl_stmt|;
block|}
name|__packed
name|hv_vmbus_channel_gpadl_torndown
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|hv_vmbus_channel_msg_header
name|header
decl_stmt|;
name|uint32_t
name|child_rel_id
decl_stmt|;
block|}
name|__packed
name|hv_vmbus_channel_relid_released
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|hv_vmbus_channel_msg_header
name|header
decl_stmt|;
name|uint32_t
name|vmbus_version_requested
decl_stmt|;
name|uint32_t
name|padding2
decl_stmt|;
name|uint64_t
name|interrupt_page
decl_stmt|;
name|uint64_t
name|monitor_page_1
decl_stmt|;
name|uint64_t
name|monitor_page_2
decl_stmt|;
block|}
name|__packed
name|hv_vmbus_channel_initiate_contact
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|hv_vmbus_channel_msg_header
name|header
decl_stmt|;
name|hv_bool_uint8_t
name|version_supported
decl_stmt|;
block|}
name|__packed
name|hv_vmbus_channel_version_response
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|hv_vmbus_channel_msg_header
name|hv_vmbus_channel_unload
typedef|;
end_typedef

begin_define
define|#
directive|define
name|HW_MACADDR_LEN
value|6
end_define

begin_comment
comment|/*  * Fixme:  Added to quiet "typeof" errors involving hv_vmbus.h when  * the including C file was compiled with "-std=c99".  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|typeof
end_ifndef

begin_define
define|#
directive|define
name|typeof
value|__typeof
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NULL
end_ifndef

begin_define
define|#
directive|define
name|NULL
value|(void *)0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|void
modifier|*
name|hv_vmbus_handle
typedef|;
end_typedef

begin_ifndef
ifndef|#
directive|ifndef
name|CONTAINING_RECORD
end_ifndef

begin_define
define|#
directive|define
name|CONTAINING_RECORD
parameter_list|(
name|address
parameter_list|,
name|type
parameter_list|,
name|field
parameter_list|)
value|((type *)(	\ 		(uint8_t *)(address) -				\ 		(uint8_t *)(&((type *)0)->field)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONTAINING_RECORD */
end_comment

begin_define
define|#
directive|define
name|container_of
parameter_list|(
name|ptr
parameter_list|,
name|type
parameter_list|,
name|member
parameter_list|)
value|({				\ 		__typeof__( ((type *)0)->member ) *__mptr = (ptr);	\ 		(type *)( (char *)__mptr - offsetof(type,member) );})
end_define

begin_enum
enum|enum
block|{
name|HV_VMBUS_IVAR_TYPE
block|,
name|HV_VMBUS_IVAR_INSTANCE
block|,
name|HV_VMBUS_IVAR_NODE
block|,
name|HV_VMBUS_IVAR_DEVCTX
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|HV_VMBUS_ACCESSOR
parameter_list|(
name|var
parameter_list|,
name|ivar
parameter_list|,
name|type
parameter_list|)
define|\
value|__BUS_ACCESSOR(vmbus, var, HV_VMBUS, ivar, type)
end_define

begin_macro
name|HV_VMBUS_ACCESSOR
argument_list|(
argument|type
argument_list|,
argument|TYPE
argument_list|,
argument|const char *
argument_list|)
end_macro

begin_macro
name|HV_VMBUS_ACCESSOR
argument_list|(
argument|devctx
argument_list|,
argument|DEVCTX
argument_list|,
argument|struct hv_device *
argument_list|)
end_macro

begin_comment
comment|/*  * Common defines for Hyper-V ICs  */
end_comment

begin_define
define|#
directive|define
name|HV_ICMSGTYPE_NEGOTIATE
value|0
end_define

begin_define
define|#
directive|define
name|HV_ICMSGTYPE_HEARTBEAT
value|1
end_define

begin_define
define|#
directive|define
name|HV_ICMSGTYPE_KVPEXCHANGE
value|2
end_define

begin_define
define|#
directive|define
name|HV_ICMSGTYPE_SHUTDOWN
value|3
end_define

begin_define
define|#
directive|define
name|HV_ICMSGTYPE_TIMESYNC
value|4
end_define

begin_define
define|#
directive|define
name|HV_ICMSGTYPE_VSS
value|5
end_define

begin_define
define|#
directive|define
name|HV_ICMSGHDRFLAG_TRANSACTION
value|1
end_define

begin_define
define|#
directive|define
name|HV_ICMSGHDRFLAG_REQUEST
value|2
end_define

begin_define
define|#
directive|define
name|HV_ICMSGHDRFLAG_RESPONSE
value|4
end_define

begin_typedef
typedef|typedef
struct|struct
name|hv_vmbus_pipe_hdr
block|{
name|uint32_t
name|flags
decl_stmt|;
name|uint32_t
name|msgsize
decl_stmt|;
block|}
name|__packed
name|hv_vmbus_pipe_hdr
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|hv_vmbus_ic_version
block|{
name|uint16_t
name|major
decl_stmt|;
name|uint16_t
name|minor
decl_stmt|;
block|}
name|__packed
name|hv_vmbus_ic_version
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|hv_vmbus_icmsg_hdr
block|{
name|hv_vmbus_ic_version
name|icverframe
decl_stmt|;
name|uint16_t
name|icmsgtype
decl_stmt|;
name|hv_vmbus_ic_version
name|icvermsg
decl_stmt|;
name|uint16_t
name|icmsgsize
decl_stmt|;
name|uint32_t
name|status
decl_stmt|;
name|uint8_t
name|ictransaction_id
decl_stmt|;
name|uint8_t
name|icflags
decl_stmt|;
name|uint8_t
name|reserved
index|[
literal|2
index|]
decl_stmt|;
block|}
name|__packed
name|hv_vmbus_icmsg_hdr
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|hv_vmbus_icmsg_negotiate
block|{
name|uint16_t
name|icframe_vercnt
decl_stmt|;
name|uint16_t
name|icmsg_vercnt
decl_stmt|;
name|uint32_t
name|reserved
decl_stmt|;
name|hv_vmbus_ic_version
name|icversion_data
index|[
literal|1
index|]
decl_stmt|;
comment|/* any size array */
block|}
name|__packed
name|hv_vmbus_icmsg_negotiate
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|hv_vmbus_shutdown_msg_data
block|{
name|uint32_t
name|reason_code
decl_stmt|;
name|uint32_t
name|timeout_seconds
decl_stmt|;
name|uint32_t
name|flags
decl_stmt|;
name|uint8_t
name|display_message
index|[
literal|2048
index|]
decl_stmt|;
block|}
name|__packed
name|hv_vmbus_shutdown_msg_data
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|hv_vmbus_heartbeat_msg_data
block|{
name|uint64_t
name|seq_num
decl_stmt|;
name|uint32_t
name|reserved
index|[
literal|8
index|]
decl_stmt|;
block|}
name|__packed
name|hv_vmbus_heartbeat_msg_data
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* 	 * offset in bytes from the start of ring data below 	 */
specifier|volatile
name|uint32_t
name|write_index
decl_stmt|;
comment|/* 	 * offset in bytes from the start of ring data below 	 */
specifier|volatile
name|uint32_t
name|read_index
decl_stmt|;
comment|/* 	 * NOTE: The interrupt_mask field is used only for channels, but 	 * vmbus connection also uses this data structure 	 */
specifier|volatile
name|uint32_t
name|interrupt_mask
decl_stmt|;
comment|/* pad it to PAGE_SIZE so that data starts on a page */
name|uint8_t
name|reserved
index|[
literal|4084
index|]
decl_stmt|;
comment|/* 	 * WARNING: Ring data starts here + ring_data_start_offset 	 *  !!! DO NOT place any fields below this !!! 	 */
name|uint8_t
name|buffer
index|[
literal|0
index|]
decl_stmt|;
comment|/* doubles as interrupt mask */
block|}
name|__packed
name|hv_vmbus_ring_buffer
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|length
decl_stmt|;
name|int
name|offset
decl_stmt|;
name|uint64_t
name|pfn
decl_stmt|;
block|}
name|__packed
name|hv_vmbus_page_buffer
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|length
decl_stmt|;
name|int
name|offset
decl_stmt|;
name|uint64_t
name|pfn_array
index|[
name|HV_MAX_MULTIPAGE_BUFFER_COUNT
index|]
decl_stmt|;
block|}
name|__packed
name|hv_vmbus_multipage_buffer
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|hv_vmbus_ring_buffer
modifier|*
name|ring_buffer
decl_stmt|;
name|uint32_t
name|ring_size
decl_stmt|;
comment|/* Include the shared header */
name|struct
name|mtx
name|ring_lock
decl_stmt|;
name|uint32_t
name|ring_data_size
decl_stmt|;
comment|/* ring_size */
name|uint32_t
name|ring_data_start_offset
decl_stmt|;
block|}
name|hv_vmbus_ring_buffer_info
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|hv_vmbus_pfn_channel_callback
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
name|void
function_decl|(
modifier|*
name|hv_vmbus_sc_creation_callback
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
enum|enum
block|{
name|HV_CHANNEL_OFFER_STATE
block|,
name|HV_CHANNEL_OPENING_STATE
block|,
name|HV_CHANNEL_OPEN_STATE
block|,
name|HV_CHANNEL_OPENED_STATE
block|,
name|HV_CHANNEL_CLOSING_NONDESTRUCTIVE_STATE
block|, }
name|hv_vmbus_channel_state
typedef|;
end_typedef

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
name|hv_vmbus_channel
block|{
name|TAILQ_ENTRY
argument_list|(
argument|hv_vmbus_channel
argument_list|)
name|list_entry
expr_stmt|;
name|struct
name|hv_device
modifier|*
name|device
decl_stmt|;
name|hv_vmbus_channel_state
name|state
decl_stmt|;
name|hv_vmbus_channel_offer_channel
name|offer_msg
decl_stmt|;
comment|/* 	 * These are based on the offer_msg.monitor_id. 	 * Save it here for easy access. 	 */
name|uint8_t
name|monitor_group
decl_stmt|;
name|uint8_t
name|monitor_bit
decl_stmt|;
name|uint32_t
name|ring_buffer_gpadl_handle
decl_stmt|;
comment|/* 	 * Allocated memory for ring buffer 	 */
name|void
modifier|*
name|ring_buffer_pages
decl_stmt|;
name|unsigned
name|long
name|ring_buffer_size
decl_stmt|;
name|uint32_t
name|ring_buffer_page_count
decl_stmt|;
comment|/* 	 * send to parent 	 */
name|hv_vmbus_ring_buffer_info
name|outbound
decl_stmt|;
comment|/* 	 * receive from parent 	 */
name|hv_vmbus_ring_buffer_info
name|inbound
decl_stmt|;
name|struct
name|mtx
name|inbound_lock
decl_stmt|;
name|hv_vmbus_pfn_channel_callback
name|on_channel_callback
decl_stmt|;
name|void
modifier|*
name|channel_callback_context
decl_stmt|;
comment|/* 	 * If batched_reading is set to "true", mask the interrupt 	 * and read until the channel is empty. 	 * If batched_reading is set to "false", the channel is not 	 * going to perform batched reading. 	 * 	 * Batched reading is enabled by default; specific 	 * drivers that don't want this behavior can turn it off. 	 */
name|boolean_t
name|batched_reading
decl_stmt|;
name|boolean_t
name|is_dedicated_interrupt
decl_stmt|;
comment|/* 	 * Used as an input param for HV_CALL_SIGNAL_EVENT hypercall. 	 */
name|hv_vmbus_input_signal_event_buffer
name|signal_event_buffer
decl_stmt|;
comment|/* 	 * 8-bytes aligned of the buffer above 	 */
name|hv_vmbus_input_signal_event
modifier|*
name|signal_event_param
decl_stmt|;
comment|/* 	 * From Win8, this field specifies the target virtual process 	 * on which to deliver the interupt from the host to guest. 	 * Before Win8, all channel interrupts would only be 	 * delivered on cpu 0. Setting this value to 0 would preserve 	 * the earlier behavior. 	 */
name|uint32_t
name|target_vcpu
decl_stmt|;
comment|/* The corresponding CPUID in the guest */
name|uint32_t
name|target_cpu
decl_stmt|;
comment|/* 	 * Support for multi-channels. 	 * The initial offer is considered the primary channel and this 	 * offer message will indicate if the host supports multi-channels. 	 * The guest is free to ask for multi-channels to be offerred and can 	 * open these multi-channels as a normal "primary" channel. However, 	 * all multi-channels will have the same type and instance guids as the 	 * primary channel. Requests sent on a given channel will result in a 	 * response on the same channel. 	 */
comment|/* 	 * Multi-channel creation callback. This callback will be called in 	 * process context when a Multi-channel offer is received from the host. 	 * The guest can open the Multi-channel in the context of this callback. 	 */
name|hv_vmbus_sc_creation_callback
name|sc_creation_callback
decl_stmt|;
name|struct
name|mtx
name|sc_lock
decl_stmt|;
comment|/* 	 * Link list of all the multi-channels if this is a primary channel 	 */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|hv_vmbus_channel
argument_list|)
name|sc_list_anchor
expr_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|hv_vmbus_channel
argument_list|)
name|sc_list_entry
expr_stmt|;
comment|/* 	 * The primary channel this sub-channle belongs to. 	 * This will be NULL for the primary channel. 	 */
name|struct
name|hv_vmbus_channel
modifier|*
name|primary_channel
decl_stmt|;
comment|/* 	 * Support per channel state for use by vmbus drivers. 	 */
name|void
modifier|*
name|per_channel_state
decl_stmt|;
block|}
name|hv_vmbus_channel
typedef|;
end_typedef

begin_function
specifier|static
specifier|inline
name|void
name|hv_set_channel_read_state
parameter_list|(
name|hv_vmbus_channel
modifier|*
name|channel
parameter_list|,
name|boolean_t
name|state
parameter_list|)
block|{
name|channel
operator|->
name|batched_reading
operator|=
name|state
expr_stmt|;
block|}
end_function

begin_typedef
typedef|typedef
struct|struct
name|hv_device
block|{
name|hv_guid
name|class_id
decl_stmt|;
name|hv_guid
name|device_id
decl_stmt|;
name|device_t
name|device
decl_stmt|;
name|hv_vmbus_channel
modifier|*
name|channel
decl_stmt|;
block|}
name|hv_device
typedef|;
end_typedef

begin_function_decl
name|int
name|hv_vmbus_channel_recv_packet
parameter_list|(
name|hv_vmbus_channel
modifier|*
name|channel
parameter_list|,
name|void
modifier|*
name|buffer
parameter_list|,
name|uint32_t
name|buffer_len
parameter_list|,
name|uint32_t
modifier|*
name|buffer_actual_len
parameter_list|,
name|uint64_t
modifier|*
name|request_id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hv_vmbus_channel_recv_packet_raw
parameter_list|(
name|hv_vmbus_channel
modifier|*
name|channel
parameter_list|,
name|void
modifier|*
name|buffer
parameter_list|,
name|uint32_t
name|buffer_len
parameter_list|,
name|uint32_t
modifier|*
name|buffer_actual_len
parameter_list|,
name|uint64_t
modifier|*
name|request_id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hv_vmbus_channel_open
parameter_list|(
name|hv_vmbus_channel
modifier|*
name|channel
parameter_list|,
name|uint32_t
name|send_ring_buffer_size
parameter_list|,
name|uint32_t
name|recv_ring_buffer_size
parameter_list|,
name|void
modifier|*
name|user_data
parameter_list|,
name|uint32_t
name|user_data_len
parameter_list|,
name|hv_vmbus_pfn_channel_callback
name|pfn_on_channel_callback
parameter_list|,
name|void
modifier|*
name|context
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|hv_vmbus_channel_close
parameter_list|(
name|hv_vmbus_channel
modifier|*
name|channel
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hv_vmbus_channel_send_packet
parameter_list|(
name|hv_vmbus_channel
modifier|*
name|channel
parameter_list|,
name|void
modifier|*
name|buffer
parameter_list|,
name|uint32_t
name|buffer_len
parameter_list|,
name|uint64_t
name|request_id
parameter_list|,
name|hv_vmbus_packet_type
name|type
parameter_list|,
name|uint32_t
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hv_vmbus_channel_send_packet_pagebuffer
parameter_list|(
name|hv_vmbus_channel
modifier|*
name|channel
parameter_list|,
name|hv_vmbus_page_buffer
name|page_buffers
index|[]
parameter_list|,
name|uint32_t
name|page_count
parameter_list|,
name|void
modifier|*
name|buffer
parameter_list|,
name|uint32_t
name|buffer_len
parameter_list|,
name|uint64_t
name|request_id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hv_vmbus_channel_send_packet_multipagebuffer
parameter_list|(
name|hv_vmbus_channel
modifier|*
name|channel
parameter_list|,
name|hv_vmbus_multipage_buffer
modifier|*
name|multi_page_buffer
parameter_list|,
name|void
modifier|*
name|buffer
parameter_list|,
name|uint32_t
name|buffer_len
parameter_list|,
name|uint64_t
name|request_id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hv_vmbus_channel_establish_gpadl
parameter_list|(
name|hv_vmbus_channel
modifier|*
name|channel
parameter_list|,
comment|/* must be phys and virt contiguous */
name|void
modifier|*
name|contig_buffer
parameter_list|,
comment|/*  page-size multiple	*/
name|uint32_t
name|size
parameter_list|,
name|uint32_t
modifier|*
name|gpadl_handle
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hv_vmbus_channel_teardown_gpdal
parameter_list|(
name|hv_vmbus_channel
modifier|*
name|channel
parameter_list|,
name|uint32_t
name|gpadl_handle
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|hv_vmbus_channel
modifier|*
name|vmbus_select_outgoing_channel
parameter_list|(
name|struct
name|hv_vmbus_channel
modifier|*
name|promary
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Work abstraction defines  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|hv_work_queue
block|{
name|struct
name|taskqueue
modifier|*
name|queue
decl_stmt|;
name|struct
name|proc
modifier|*
name|proc
decl_stmt|;
name|struct
name|sema
modifier|*
name|work_sema
decl_stmt|;
block|}
name|hv_work_queue
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|hv_work_item
block|{
name|struct
name|task
name|work
decl_stmt|;
name|void
function_decl|(
modifier|*
name|callback
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
name|void
modifier|*
name|context
decl_stmt|;
name|hv_work_queue
modifier|*
name|wq
decl_stmt|;
block|}
name|hv_work_item
typedef|;
end_typedef

begin_function_decl
name|struct
name|hv_work_queue
modifier|*
name|hv_work_queue_create
parameter_list|(
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|hv_work_queue_close
parameter_list|(
name|struct
name|hv_work_queue
modifier|*
name|wq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hv_queue_work_item
parameter_list|(
name|hv_work_queue
modifier|*
name|wq
parameter_list|,
name|void
function_decl|(
modifier|*
name|callback
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
name|context
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @brief Get physical address from virtual  */
end_comment

begin_function
specifier|static
specifier|inline
name|unsigned
name|long
name|hv_get_phys_addr
parameter_list|(
name|void
modifier|*
name|virt
parameter_list|)
block|{
name|unsigned
name|long
name|ret
decl_stmt|;
name|ret
operator|=
operator|(
name|vtophys
argument_list|(
name|virt
argument_list|)
operator||
operator|(
operator|(
name|vm_offset_t
operator|)
name|virt
operator|&
name|PAGE_MASK
operator|)
operator|)
expr_stmt|;
return|return
operator|(
name|ret
operator|)
return|;
block|}
end_function

begin_comment
comment|/**  * KVP related structures  *   */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|hv_vmbus_service
block|{
name|hv_guid
name|guid
decl_stmt|;
comment|/* Hyper-V GUID */
name|char
modifier|*
name|name
decl_stmt|;
comment|/* name of service */
name|boolean_t
name|enabled
decl_stmt|;
comment|/* service enabled */
name|hv_work_queue
modifier|*
name|work_queue
decl_stmt|;
comment|/* background work queue */
comment|/*          * function to initialize service          */
name|int
function_decl|(
modifier|*
name|init
function_decl|)
parameter_list|(
name|struct
name|hv_vmbus_service
modifier|*
parameter_list|)
function_decl|;
comment|/*          * function to process Hyper-V messages          */
name|void
function_decl|(
modifier|*
name|callback
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
block|}
name|hv_vmbus_service
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|uint8_t
modifier|*
name|receive_buffer
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|hv_vmbus_service
name|service_table
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint32_t
name|hv_vmbus_protocal_version
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|hv_kvp_callback
parameter_list|(
name|void
modifier|*
name|context
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hv_kvp_init
parameter_list|(
name|hv_vmbus_service
modifier|*
name|serv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|hv_kvp_deinit
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
comment|/* __HYPERV_H__ */
end_comment

end_unit

