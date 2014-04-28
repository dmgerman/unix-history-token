begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2009-2012 Microsoft Corp.  * Copyright (c) 2010-2012 Citrix Inc.  * Copyright (c) 2012 NetApp Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * HyperV vmbus (virtual machine bus) network VSC (virtual services client)  * header file  *  * (Updated from unencumbered NvspProtocol.h)  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__HV_NET_VSC_H__
end_ifndef

begin_define
define|#
directive|define
name|__HV_NET_VSC_H__
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

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
file|<sys/sx.h>
end_include

begin_include
include|#
directive|include
file|<dev/hyperv/include/hyperv.h>
end_include

begin_define
define|#
directive|define
name|NVSP_INVALID_PROTOCOL_VERSION
value|(0xFFFFFFFF)
end_define

begin_define
define|#
directive|define
name|NVSP_PROTOCOL_VERSION_1
value|2
end_define

begin_define
define|#
directive|define
name|NVSP_PROTOCOL_VERSION_2
value|0x30002
end_define

begin_define
define|#
directive|define
name|NVSP_MIN_PROTOCOL_VERSION
value|(NVSP_PROTOCOL_VERSION_1)
end_define

begin_define
define|#
directive|define
name|NVSP_MAX_PROTOCOL_VERSION
value|(NVSP_PROTOCOL_VERSION_2)
end_define

begin_define
define|#
directive|define
name|NVSP_PROTOCOL_VERSION_CURRENT
value|NVSP_PROTOCOL_VERSION_2
end_define

begin_define
define|#
directive|define
name|NVSP_OPERATIONAL_STATUS_OK
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|NVSP_OPERATIONAL_STATUS_DEGRADED
value|(0x00000001)
end_define

begin_define
define|#
directive|define
name|NVSP_OPERATIONAL_STATUS_NONRECOVERABLE
value|(0x00000002)
end_define

begin_define
define|#
directive|define
name|NVSP_OPERATIONAL_STATUS_NO_CONTACT
value|(0x00000003)
end_define

begin_define
define|#
directive|define
name|NVSP_OPERATIONAL_STATUS_LOST_COMMUNICATION
value|(0x00000004)
end_define

begin_comment
comment|/*  * Maximun number of transfer pages (packets) the VSP will use on a receive  */
end_comment

begin_define
define|#
directive|define
name|NVSP_MAX_PACKETS_PER_RECEIVE
value|375
end_define

begin_typedef
typedef|typedef
enum|enum
name|nvsp_msg_type_
block|{
name|nvsp_msg_type_none
init|=
literal|0
block|,
comment|/* 	 * Init Messages 	 */
name|nvsp_msg_type_init
init|=
literal|1
block|,
name|nvsp_msg_type_init_complete
init|=
literal|2
block|,
name|nvsp_version_msg_start
init|=
literal|100
block|,
comment|/* 	 * Version 1 Messages 	 */
name|nvsp_msg_1_type_send_ndis_vers
init|=
name|nvsp_version_msg_start
block|,
name|nvsp_msg_1_type_send_rx_buf
block|,
name|nvsp_msg_1_type_send_rx_buf_complete
block|,
name|nvsp_msg_1_type_revoke_rx_buf
block|,
name|nvsp_msg_1_type_send_send_buf
block|,
name|nvsp_msg_1_type_send_send_buf_complete
block|,
name|nvsp_msg_1_type_revoke_send_buf
block|,
name|nvsp_msg_1_type_send_rndis_pkt
block|,
name|nvsp_msg_1_type_send_rndis_pkt_complete
block|,
comment|/* 	 * Version 2 Messages 	 */
name|nvsp_msg_2_type_send_chimney_delegated_buf
block|,
name|nvsp_msg_2_type_send_chimney_delegated_buf_complete
block|,
name|nvsp_msg_2_type_revoke_chimney_delegated_buf
block|,
name|nvsp_msg_2_type_resume_chimney_rx_indication
block|,
name|nvsp_msg_2_type_terminate_chimney
block|,
name|nvsp_msg_2_type_terminate_chimney_complete
block|,
name|nvsp_msg_2_type_indicate_chimney_event
block|,
name|nvsp_msg_2_type_send_chimney_packet
block|,
name|nvsp_msg_2_type_send_chimney_packet_complete
block|,
name|nvsp_msg_2_type_post_chimney_rx_request
block|,
name|nvsp_msg_2_type_post_chimney_rx_request_complete
block|,
name|nvsp_msg_2_type_alloc_rx_buf
block|,
name|nvsp_msg_2_type_alloc_rx_buf_complete
block|,
name|nvsp_msg_2_type_free_rx_buf
block|,
name|nvsp_msg_2_send_vmq_rndis_pkt
block|,
name|nvsp_msg_2_send_vmq_rndis_pkt_complete
block|,
name|nvsp_msg_2_type_send_ndis_config
block|,
name|nvsp_msg_2_type_alloc_chimney_handle
block|,
name|nvsp_msg_2_type_alloc_chimney_handle_complete
block|, }
name|nvsp_msg_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
name|nvsp_status_
block|{
name|nvsp_status_none
init|=
literal|0
block|,
name|nvsp_status_success
block|,
name|nvsp_status_failure
block|,
comment|/* Deprecated */
name|nvsp_status_prot_vers_range_too_new
block|,
comment|/* Deprecated */
name|nvsp_status_prot_vers_range_too_old
block|,
name|nvsp_status_invalid_rndis_pkt
block|,
name|nvsp_status_busy
block|,
name|nvsp_status_max
block|, }
name|nvsp_status
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|nvsp_msg_hdr_
block|{
name|uint32_t
name|msg_type
decl_stmt|;
block|}
name|__packed
name|nvsp_msg_hdr
typedef|;
end_typedef

begin_comment
comment|/*  * Init Messages  */
end_comment

begin_comment
comment|/*  * This message is used by the VSC to initialize the channel  * after the channels has been opened. This message should   * never include anything other then versioning (i.e. this  * message will be the same for ever).  *  * Forever is a long time.  The values have been redefined  * in Win7 to indicate major and minor protocol version  * number.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|nvsp_msg_init_
block|{
union|union
block|{
struct|struct
block|{
name|uint16_t
name|minor_protocol_version
decl_stmt|;
name|uint16_t
name|major_protocol_version
decl_stmt|;
block|}
name|s
struct|;
comment|/* Formerly min_protocol_version */
name|uint32_t
name|protocol_version
decl_stmt|;
block|}
name|p1
union|;
comment|/* Formerly max_protocol_version */
name|uint32_t
name|protocol_version_2
decl_stmt|;
block|}
name|__packed
name|nvsp_msg_init
typedef|;
end_typedef

begin_comment
comment|/*  * This message is used by the VSP to complete the initialization  * of the channel. This message should never include anything other   * then versioning (i.e. this message will be the same forever).  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|nvsp_msg_init_complete_
block|{
comment|/* Deprecated */
name|uint32_t
name|negotiated_prot_vers
decl_stmt|;
name|uint32_t
name|max_mdl_chain_len
decl_stmt|;
name|uint32_t
name|status
decl_stmt|;
block|}
name|__packed
name|nvsp_msg_init_complete
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
name|nvsp_msg_init_uber_
block|{
name|nvsp_msg_init
name|init
decl_stmt|;
name|nvsp_msg_init_complete
name|init_compl
decl_stmt|;
block|}
name|__packed
name|nvsp_msg_init_uber
typedef|;
end_typedef

begin_comment
comment|/*  * Version 1 Messages  */
end_comment

begin_comment
comment|/*  * This message is used by the VSC to send the NDIS version  * to the VSP.  The VSP can use this information when handling  * OIDs sent by the VSC.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|nvsp_1_msg_send_ndis_version_
block|{
name|uint32_t
name|ndis_major_vers
decl_stmt|;
comment|/* Deprecated */
name|uint32_t
name|ndis_minor_vers
decl_stmt|;
block|}
name|__packed
name|nvsp_1_msg_send_ndis_version
typedef|;
end_typedef

begin_comment
comment|/*  * This message is used by the VSC to send a receive buffer  * to the VSP. The VSP can then use the receive buffer to  * send data to the VSC.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|nvsp_1_msg_send_rx_buf_
block|{
name|uint32_t
name|gpadl_handle
decl_stmt|;
name|uint16_t
name|id
decl_stmt|;
block|}
name|__packed
name|nvsp_1_msg_send_rx_buf
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|nvsp_1_rx_buf_section_
block|{
name|uint32_t
name|offset
decl_stmt|;
name|uint32_t
name|sub_allocation_size
decl_stmt|;
name|uint32_t
name|num_sub_allocations
decl_stmt|;
name|uint32_t
name|end_offset
decl_stmt|;
block|}
name|__packed
name|nvsp_1_rx_buf_section
typedef|;
end_typedef

begin_comment
comment|/*  * This message is used by the VSP to acknowledge a receive   * buffer send by the VSC.  This message must be sent by the   * VSP before the VSP uses the receive buffer.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|nvsp_1_msg_send_rx_buf_complete_
block|{
name|uint32_t
name|status
decl_stmt|;
name|uint32_t
name|num_sections
decl_stmt|;
comment|/* 	 * The receive buffer is split into two parts, a large 	 * suballocation section and a small suballocation 	 * section. These sections are then suballocated by a  	 * certain size. 	 * 	 * For example, the following break up of the receive 	 * buffer has 6 large suballocations and 10 small 	 * suballocations. 	 * 	 * |            Large Section          |  |   Small Section   | 	 * ------------------------------------------------------------ 	 * |     |     |     |     |     |     |  | | | | | | | | | | | 	 * |                                      |   	 * LargeOffset                            SmallOffset 	 */
name|nvsp_1_rx_buf_section
name|sections
index|[
literal|1
index|]
decl_stmt|;
block|}
name|__packed
name|nvsp_1_msg_send_rx_buf_complete
typedef|;
end_typedef

begin_comment
comment|/*  * This message is sent by the VSC to revoke the receive buffer.  * After the VSP completes this transaction, the VSP should never  * use the receive buffer again.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|nvsp_1_msg_revoke_rx_buf_
block|{
name|uint16_t
name|id
decl_stmt|;
block|}
name|__packed
name|nvsp_1_msg_revoke_rx_buf
typedef|;
end_typedef

begin_comment
comment|/*  * This message is used by the VSC to send a send buffer  * to the VSP. The VSC can then use the send buffer to  * send data to the VSP.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|nvsp_1_msg_send_send_buf_
block|{
name|uint32_t
name|gpadl_handle
decl_stmt|;
name|uint16_t
name|id
decl_stmt|;
block|}
name|__packed
name|nvsp_1_msg_send_send_buf
typedef|;
end_typedef

begin_comment
comment|/*  * This message is used by the VSP to acknowledge a send   * buffer sent by the VSC. This message must be sent by the   * VSP before the VSP uses the sent buffer.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|nvsp_1_msg_send_send_buf_complete_
block|{
name|uint32_t
name|status
decl_stmt|;
comment|/* 	 * The VSC gets to choose the size of the send buffer and 	 * the VSP gets to choose the sections size of the buffer. 	 * This was done to enable dynamic reconfigurations when 	 * the cost of GPA-direct buffers decreases. 	 */
name|uint32_t
name|section_size
decl_stmt|;
block|}
name|__packed
name|nvsp_1_msg_send_send_buf_complete
typedef|;
end_typedef

begin_comment
comment|/*  * This message is sent by the VSC to revoke the send buffer.  * After the VSP completes this transaction, the vsp should never  * use the send buffer again.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|nvsp_1_msg_revoke_send_buf_
block|{
name|uint16_t
name|id
decl_stmt|;
block|}
name|__packed
name|nvsp_1_msg_revoke_send_buf
typedef|;
end_typedef

begin_comment
comment|/*  * This message is used by both the VSP and the VSC to send  * an RNDIS message to the opposite channel endpoint.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|nvsp_1_msg_send_rndis_pkt_
block|{
comment|/* 	 * This field is specified by RNIDS.  They assume there's 	 * two different channels of communication. However,  	 * the Network VSP only has one.  Therefore, the channel 	 * travels with the RNDIS packet. 	 */
name|uint32_t
name|chan_type
decl_stmt|;
comment|/* 	 * This field is used to send part or all of the data 	 * through a send buffer. This values specifies an  	 * index into the send buffer.  If the index is  	 * 0xFFFFFFFF, then the send buffer is not being used 	 * and all of the data was sent through other VMBus 	 * mechanisms. 	 */
name|uint32_t
name|send_buf_section_idx
decl_stmt|;
name|uint32_t
name|send_buf_section_size
decl_stmt|;
block|}
name|__packed
name|nvsp_1_msg_send_rndis_pkt
typedef|;
end_typedef

begin_comment
comment|/*  * This message is used by both the VSP and the VSC to complete  * a RNDIS message to the opposite channel endpoint.  At this  * point, the initiator of this message cannot use any resources  * associated with the original RNDIS packet.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|nvsp_1_msg_send_rndis_pkt_complete_
block|{
name|uint32_t
name|status
decl_stmt|;
block|}
name|__packed
name|nvsp_1_msg_send_rndis_pkt_complete
typedef|;
end_typedef

begin_comment
comment|/*  * Version 2 Messages  */
end_comment

begin_comment
comment|/*  * This message is used by the VSC to send the NDIS version  * to the VSP.  The VSP can use this information when handling  * OIDs sent by the VSC.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|nvsp_2_netvsc_capabilities_
block|{
union|union
block|{
name|uint64_t
name|as_uint64
decl_stmt|;
struct|struct
block|{
name|uint64_t
name|vmq
range|:
literal|1
decl_stmt|;
name|uint64_t
name|chimney
range|:
literal|1
decl_stmt|;
name|uint64_t
name|sriov
range|:
literal|1
decl_stmt|;
name|uint64_t
name|ieee8021q
range|:
literal|1
decl_stmt|;
name|uint64_t
name|correlationid
range|:
literal|1
decl_stmt|;
name|uint64_t
name|teaming
range|:
literal|1
decl_stmt|;
block|}
name|u2
struct|;
block|}
name|u1
union|;
block|}
name|__packed
name|nvsp_2_netvsc_capabilities
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|nvsp_2_msg_send_ndis_config_
block|{
name|uint32_t
name|mtu
decl_stmt|;
name|uint32_t
name|reserved
decl_stmt|;
name|nvsp_2_netvsc_capabilities
name|capabilities
decl_stmt|;
block|}
name|__packed
name|nvsp_2_msg_send_ndis_config
typedef|;
end_typedef

begin_comment
comment|/*  * NvspMessage2TypeSendChimneyDelegatedBuffer  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|nvsp_2_msg_send_chimney_buf_
block|{
comment|/* 	 * On WIN7 beta, delegated_obj_max_size is defined as a uint32_t 	 * Since WIN7 RC, it was split into two uint16_t.  To have the same 	 * struct layout, delegated_obj_max_size shall be the first field. 	 */
name|uint16_t
name|delegated_obj_max_size
decl_stmt|;
comment|/* 	 * The revision # of chimney protocol used between NVSC and NVSP. 	 * 	 * This revision is NOT related to the chimney revision between 	 * NDIS protocol and miniport drivers. 	 */
name|uint16_t
name|revision
decl_stmt|;
name|uint32_t
name|gpadl_handle
decl_stmt|;
block|}
name|__packed
name|nvsp_2_msg_send_chimney_buf
typedef|;
end_typedef

begin_comment
comment|/* Unsupported chimney revision 0 (only present in WIN7 beta) */
end_comment

begin_define
define|#
directive|define
name|NVSP_CHIMNEY_REVISION_0
value|0
end_define

begin_comment
comment|/* WIN7 Beta Chimney QFE */
end_comment

begin_define
define|#
directive|define
name|NVSP_CHIMNEY_REVISION_1
value|1
end_define

begin_comment
comment|/* The chimney revision since WIN7 RC */
end_comment

begin_define
define|#
directive|define
name|NVSP_CHIMNEY_REVISION_2
value|2
end_define

begin_comment
comment|/*  * NvspMessage2TypeSendChimneyDelegatedBufferComplete  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|nvsp_2_msg_send_chimney_buf_complete_
block|{
name|uint32_t
name|status
decl_stmt|;
comment|/* 	 * Maximum number outstanding sends and pre-posted receives. 	 * 	 * NVSC should not post more than SendQuota/ReceiveQuota packets. 	 * Otherwise, it can block the non-chimney path for an indefinite 	 * amount of time. 	 * (since chimney sends/receives are affected by the remote peer). 	 * 	 * Note: NVSP enforces the quota restrictions on a per-VMBCHANNEL 	 * basis.  It doesn't enforce the restriction separately for chimney 	 * send/receive.  If NVSC doesn't voluntarily enforce "SendQuota", 	 * it may kill its own network connectivity. 	 */
name|uint32_t
name|send_quota
decl_stmt|;
name|uint32_t
name|rx_quota
decl_stmt|;
block|}
name|__packed
name|nvsp_2_msg_send_chimney_buf_complete
typedef|;
end_typedef

begin_comment
comment|/*  * NvspMessage2TypeRevokeChimneyDelegatedBuffer  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|nvsp_2_msg_revoke_chimney_buf_
block|{
name|uint32_t
name|gpadl_handle
decl_stmt|;
block|}
name|__packed
name|nvsp_2_msg_revoke_chimney_buf
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NVSP_CHIMNEY_OBJECT_TYPE_NEIGHBOR
value|0
end_define

begin_define
define|#
directive|define
name|NVSP_CHIMNEY_OBJECT_TYPE_PATH4
value|1
end_define

begin_define
define|#
directive|define
name|NVSP_CHIMNEY_OBJECT_TYPE_PATH6
value|2
end_define

begin_define
define|#
directive|define
name|NVSP_CHIMNEY_OBJECT_TYPE_TCP
value|3
end_define

begin_comment
comment|/*  * NvspMessage2TypeAllocateChimneyHandle  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|nvsp_2_msg_alloc_chimney_handle_
block|{
name|uint64_t
name|vsc_context
decl_stmt|;
name|uint32_t
name|object_type
decl_stmt|;
block|}
name|__packed
name|nvsp_2_msg_alloc_chimney_handle
typedef|;
end_typedef

begin_comment
comment|/*  * NvspMessage2TypeAllocateChimneyHandleComplete  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|nvsp_2_msg_alloc_chimney_handle_complete_
block|{
name|uint32_t
name|vsp_handle
decl_stmt|;
block|}
name|__packed
name|nvsp_2_msg_alloc_chimney_handle_complete
typedef|;
end_typedef

begin_comment
comment|/*  * NvspMessage2TypeResumeChimneyRXIndication  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|nvsp_2_msg_resume_chimney_rx_indication
block|{
comment|/* 	 * Handle identifying the offloaded connection 	 */
name|uint32_t
name|vsp_tcp_handle
decl_stmt|;
block|}
name|__packed
name|nvsp_2_msg_resume_chimney_rx_indication
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NVSP_2_MSG_TERMINATE_CHIMNEY_FLAGS_FIRST_STAGE
value|(0x01u)
end_define

begin_define
define|#
directive|define
name|NVSP_2_MSG_TERMINATE_CHIMNEY_FLAGS_RESERVED
value|(~(0x01u))
end_define

begin_comment
comment|/*  * NvspMessage2TypeTerminateChimney  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|nvsp_2_msg_terminate_chimney_
block|{
comment|/* 	* Handle identifying the offloaded object 	*/
name|uint32_t
name|vsp_handle
decl_stmt|;
comment|/* 	 * Terminate Offload Flags 	 *     Bit 0: 	 *         When set to 0, terminate the offload at the destination NIC 	 *     Bit 1-31:  Reserved, shall be zero 	 */
name|uint32_t
name|flags
decl_stmt|;
union|union
block|{
comment|/* 		 * This field is valid only when bit 0 of flags is clear. 		 * It specifies the index into the premapped delegated 		 * object buffer.  The buffer was sent through the 		 * NvspMessage2TypeSendChimneyDelegatedBuffer 		 * message at initialization time. 		 * 		 * NVSP will write the delegated state into the delegated 		 * buffer upon upload completion. 		 */
name|uint32_t
name|index
decl_stmt|;
comment|/* 		 * This field is valid only when bit 0 of flags is set. 		 * 		 * The seqence number of the most recently accepted RX 		 * indication when VSC sets its TCP context into 		 * "terminating" state. 		 * 		 * This allows NVSP to determines if there are any in-flight 		 * RX indications for which the acceptance state is still 		 * undefined. 		 */
name|uint64_t
name|last_accepted_rx_seq_no
decl_stmt|;
block|}
name|f0
union|;
block|}
name|__packed
name|nvsp_2_msg_terminate_chimney
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NVSP_TERMINATE_CHIMNEY_COMPLETE_FLAG_DATA_CORRUPTED
value|0x0000001u
end_define

begin_comment
comment|/*  * NvspMessage2TypeTerminateChimneyComplete  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|nvsp_2_msg_terminate_chimney_complete_
block|{
name|uint64_t
name|vsc_context
decl_stmt|;
name|uint32_t
name|flags
decl_stmt|;
block|}
name|__packed
name|nvsp_2_msg_terminate_chimney_complete
typedef|;
end_typedef

begin_comment
comment|/*  * NvspMessage2TypeIndicateChimneyEvent  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|nvsp_2_msg_indicate_chimney_event_
block|{
comment|/* 	 * When VscTcpContext is 0, event_type is an NDIS_STATUS event code 	 * Otherwise, EventType is an TCP connection event (defined in 	 * NdisTcpOffloadEventHandler chimney DDK document). 	 */
name|uint32_t
name|event_type
decl_stmt|;
comment|/* 	 * When VscTcpContext is 0, EventType is an NDIS_STATUS event code 	 * Otherwise, EventType is an TCP connection event specific information 	 * (defined in NdisTcpOffloadEventHandler chimney DDK document). 	 */
name|uint32_t
name|event_specific_info
decl_stmt|;
comment|/* 	 * If not 0, the event is per-TCP connection event.  This field 	 * contains the VSC's TCP context. 	 * If 0, the event indication is global. 	 */
name|uint64_t
name|vsc_tcp_context
decl_stmt|;
block|}
name|__packed
name|nvsp_2_msg_indicate_chimney_event
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NVSP_1_CHIMNEY_SEND_INVALID_OOB_INDEX
value|0xffffu
end_define

begin_define
define|#
directive|define
name|NVSP_1_CHIMNEY_SEND_INVALID_SECTION_INDEX
value|0xffffu
end_define

begin_comment
comment|/*  * NvspMessage2TypeSendChimneyPacket  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|nvsp_2_msg_send_chimney_pkt_
block|{
comment|/*      * Identify the TCP connection for which this chimney send is      */
name|uint32_t
name|vsp_tcp_handle
decl_stmt|;
comment|/*      * This field is used to send part or all of the data      * through a send buffer. This values specifies an      * index into the send buffer. If the index is      * 0xFFFF, then the send buffer is not being used      * and all of the data was sent through other VMBus      * mechanisms.      */
name|uint16_t
name|send_buf_section_index
decl_stmt|;
name|uint16_t
name|send_buf_section_size
decl_stmt|;
comment|/*      * OOB Data Index      * This an index to the OOB data buffer. If the index is 0xFFFFFFFF,      * then there is no OOB data.      *      * This field shall be always 0xFFFFFFFF for now. It is reserved for      * the future.      */
name|uint16_t
name|oob_data_index
decl_stmt|;
comment|/*      * DisconnectFlags = 0      *      Normal chimney send. See MiniportTcpOffloadSend for details.      *      * DisconnectFlags = TCP_DISCONNECT_GRACEFUL_CLOSE (0x01)      *      Graceful disconnect. See MiniportTcpOffloadDisconnect for details.      *      * DisconnectFlags = TCP_DISCONNECT_ABORTIVE_CLOSE (0x02)      *      Abortive disconnect. See MiniportTcpOffloadDisconnect for details.      */
name|uint16_t
name|disconnect_flags
decl_stmt|;
name|uint32_t
name|seq_no
decl_stmt|;
block|}
name|__packed
name|nvsp_2_msg_send_chimney_pkt
typedef|;
end_typedef

begin_comment
comment|/*  * NvspMessage2TypeSendChimneyPacketComplete  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|nvsp_2_msg_send_chimney_pkt_complete_
block|{
comment|/*      * The NDIS_STATUS for the chimney send      */
name|uint32_t
name|status
decl_stmt|;
comment|/*      * Number of bytes that have been sent to the peer (and ACKed by the peer).      */
name|uint32_t
name|bytes_transferred
decl_stmt|;
block|}
name|__packed
name|nvsp_2_msg_send_chimney_pkt_complete
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NVSP_1_CHIMNEY_RECV_FLAG_NO_PUSH
value|0x0001u
end_define

begin_define
define|#
directive|define
name|NVSP_1_CHIMNEY_RECV_INVALID_OOB_INDEX
value|0xffffu
end_define

begin_comment
comment|/*  * NvspMessage2TypePostChimneyRecvRequest  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|nvsp_2_msg_post_chimney_rx_request_
block|{
comment|/* 	 * Identify the TCP connection which this chimney receive request 	 * is for. 	 */
name|uint32_t
name|vsp_tcp_handle
decl_stmt|;
comment|/* 	 * OOB Data Index 	 * This an index to the OOB data buffer. If the index is 0xFFFFFFFF, 	 * then there is no OOB data. 	 * 	 * This field shall be always 0xFFFFFFFF for now. It is reserved for 	 * the future. 	 */
name|uint32_t
name|oob_data_index
decl_stmt|;
comment|/* 	 * Bit 0 	 *      When it is set, this is a "no-push" receive. 	 *      When it is clear, this is a "push" receive. 	 * 	 * Bit 1-15:  Reserved and shall be zero 	 */
name|uint16_t
name|flags
decl_stmt|;
comment|/* 	 * For debugging and diagnoses purpose. 	 * The SeqNo is per TCP connection and starts from 0. 	 */
name|uint32_t
name|seq_no
decl_stmt|;
block|}
name|__packed
name|nvsp_2_msg_post_chimney_rx_request
typedef|;
end_typedef

begin_comment
comment|/*  * NvspMessage2TypePostChimneyRecvRequestComplete  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|nvsp_2_msg_post_chimney_rx_request_complete_
block|{
comment|/* 	 * The NDIS_STATUS for the chimney send 	 */
name|uint32_t
name|status
decl_stmt|;
comment|/* 	 * Number of bytes that have been sent to the peer (and ACKed by 	 * the peer). 	 */
name|uint32_t
name|bytes_xferred
decl_stmt|;
block|}
name|__packed
name|nvsp_2_msg_post_chimney_rx_request_complete
typedef|;
end_typedef

begin_comment
comment|/*  * NvspMessage2TypeAllocateReceiveBuffer  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|nvsp_2_msg_alloc_rx_buf_
block|{
comment|/* 	 * Allocation ID to match the allocation request and response 	 */
name|uint32_t
name|allocation_id
decl_stmt|;
comment|/* 	 * Length of the VM shared memory receive buffer that needs to 	 * be allocated 	 */
name|uint32_t
name|length
decl_stmt|;
block|}
name|__packed
name|nvsp_2_msg_alloc_rx_buf
typedef|;
end_typedef

begin_comment
comment|/*  * NvspMessage2TypeAllocateReceiveBufferComplete  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|nvsp_2_msg_alloc_rx_buf_complete_
block|{
comment|/* 	 * The NDIS_STATUS code for buffer allocation 	 */
name|uint32_t
name|status
decl_stmt|;
comment|/* 	 * Allocation ID from NVSP_2_MESSAGE_ALLOCATE_RECEIVE_BUFFER 	 */
name|uint32_t
name|allocation_id
decl_stmt|;
comment|/* 	 * GPADL handle for the allocated receive buffer 	 */
name|uint32_t
name|gpadl_handle
decl_stmt|;
comment|/* 	 * Receive buffer ID that is further used in 	 * NvspMessage2SendVmqRndisPacket 	 */
name|uint64_t
name|rx_buf_id
decl_stmt|;
block|}
name|__packed
name|nvsp_2_msg_alloc_rx_buf_complete
typedef|;
end_typedef

begin_comment
comment|/*  * NvspMessage2TypeFreeReceiveBuffer  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|nvsp_2_msg_free_rx_buf_
block|{
comment|/* 	 * Receive buffer ID previous returned in 	 * NvspMessage2TypeAllocateReceiveBufferComplete message 	 */
name|uint64_t
name|rx_buf_id
decl_stmt|;
block|}
name|__packed
name|nvsp_2_msg_free_rx_buf
typedef|;
end_typedef

begin_comment
comment|/*  * This structure is used in defining the buffers in  * NVSP_2_MESSAGE_SEND_VMQ_RNDIS_PACKET structure  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|nvsp_xfer_page_range_
block|{
comment|/* 	 * Specifies the ID of the receive buffer that has the buffer. This 	 * ID can be the general receive buffer ID specified in 	 * NvspMessage1TypeSendReceiveBuffer or it can be the shared memory 	 * receive buffer ID allocated by the VSC and specified in 	 * NvspMessage2TypeAllocateReceiveBufferComplete message 	 */
name|uint64_t
name|xfer_page_set_id
decl_stmt|;
comment|/* 	 * Number of bytes 	 */
name|uint32_t
name|byte_count
decl_stmt|;
comment|/* 	 * Offset in bytes from the beginning of the buffer 	 */
name|uint32_t
name|byte_offset
decl_stmt|;
block|}
name|__packed
name|nvsp_xfer_page_range
typedef|;
end_typedef

begin_comment
comment|/*  * NvspMessage2SendVmqRndisPacket  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|nvsp_2_msg_send_vmq_rndis_pkt_
block|{
comment|/* 	 * This field is specified by RNIDS. They assume there's 	 * two different channels of communication. However, 	 * the Network VSP only has one. Therefore, the channel 	 * travels with the RNDIS packet. It must be RMC_DATA 	 */
name|uint32_t
name|channel_type
decl_stmt|;
comment|/* 	 * Only the Range element corresponding to the RNDIS header of 	 * the first RNDIS message in the multiple RNDIS messages sent 	 * in one NVSP message.  Information about the data portions as well 	 * as the subsequent RNDIS messages in the same NVSP message are 	 * embedded in the RNDIS header itself 	 */
name|nvsp_xfer_page_range
name|range
decl_stmt|;
block|}
name|__packed
name|nvsp_2_msg_send_vmq_rndis_pkt
typedef|;
end_typedef

begin_comment
comment|/*  * This message is used by the VSC to complete  * a RNDIS VMQ message to the VSP.  At this point,  * the initiator of this message can use any resources  * associated with the original RNDIS VMQ packet.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|nvsp_2_msg_send_vmq_rndis_pkt_complete_
block|{
name|uint32_t
name|status
decl_stmt|;
block|}
name|__packed
name|nvsp_2_msg_send_vmq_rndis_pkt_complete
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
name|nvsp_1_msg_uber_
block|{
name|nvsp_1_msg_send_ndis_version
name|send_ndis_vers
decl_stmt|;
name|nvsp_1_msg_send_rx_buf
name|send_rx_buf
decl_stmt|;
name|nvsp_1_msg_send_rx_buf_complete
name|send_rx_buf_complete
decl_stmt|;
name|nvsp_1_msg_revoke_rx_buf
name|revoke_rx_buf
decl_stmt|;
name|nvsp_1_msg_send_send_buf
name|send_send_buf
decl_stmt|;
name|nvsp_1_msg_send_send_buf_complete
name|send_send_buf_complete
decl_stmt|;
name|nvsp_1_msg_revoke_send_buf
name|revoke_send_buf
decl_stmt|;
name|nvsp_1_msg_send_rndis_pkt
name|send_rndis_pkt
decl_stmt|;
name|nvsp_1_msg_send_rndis_pkt_complete
name|send_rndis_pkt_complete
decl_stmt|;
block|}
name|__packed
name|nvsp_1_msg_uber
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
name|nvsp_2_msg_uber_
block|{
name|nvsp_2_msg_send_ndis_config
name|send_ndis_config
decl_stmt|;
name|nvsp_2_msg_send_chimney_buf
name|send_chimney_buf
decl_stmt|;
name|nvsp_2_msg_send_chimney_buf_complete
name|send_chimney_buf_complete
decl_stmt|;
name|nvsp_2_msg_revoke_chimney_buf
name|revoke_chimney_buf
decl_stmt|;
name|nvsp_2_msg_resume_chimney_rx_indication
name|resume_chimney_rx_indication
decl_stmt|;
name|nvsp_2_msg_terminate_chimney
name|terminate_chimney
decl_stmt|;
name|nvsp_2_msg_terminate_chimney_complete
name|terminate_chimney_complete
decl_stmt|;
name|nvsp_2_msg_indicate_chimney_event
name|indicate_chimney_event
decl_stmt|;
name|nvsp_2_msg_send_chimney_pkt
name|send_chimney_packet
decl_stmt|;
name|nvsp_2_msg_send_chimney_pkt_complete
name|send_chimney_packet_complete
decl_stmt|;
name|nvsp_2_msg_post_chimney_rx_request
name|post_chimney_rx_request
decl_stmt|;
name|nvsp_2_msg_post_chimney_rx_request_complete
name|post_chimney_rx_request_complete
decl_stmt|;
name|nvsp_2_msg_alloc_rx_buf
name|alloc_rx_buffer
decl_stmt|;
name|nvsp_2_msg_alloc_rx_buf_complete
name|alloc_rx_buffer_complete
decl_stmt|;
name|nvsp_2_msg_free_rx_buf
name|free_rx_buffer
decl_stmt|;
name|nvsp_2_msg_send_vmq_rndis_pkt
name|send_vmq_rndis_pkt
decl_stmt|;
name|nvsp_2_msg_send_vmq_rndis_pkt_complete
name|send_vmq_rndis_pkt_complete
decl_stmt|;
name|nvsp_2_msg_alloc_chimney_handle
name|alloc_chimney_handle
decl_stmt|;
name|nvsp_2_msg_alloc_chimney_handle_complete
name|alloc_chimney_handle_complete
decl_stmt|;
block|}
name|__packed
name|nvsp_2_msg_uber
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
name|nvsp_all_msgs_
block|{
name|nvsp_msg_init_uber
name|init_msgs
decl_stmt|;
name|nvsp_1_msg_uber
name|vers_1_msgs
decl_stmt|;
name|nvsp_2_msg_uber
name|vers_2_msgs
decl_stmt|;
block|}
name|__packed
name|nvsp_all_msgs
typedef|;
end_typedef

begin_comment
comment|/*  * ALL Messages  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|nvsp_msg_
block|{
name|nvsp_msg_hdr
name|hdr
decl_stmt|;
name|nvsp_all_msgs
name|msgs
decl_stmt|;
block|}
name|__packed
name|nvsp_msg
typedef|;
end_typedef

begin_comment
comment|/*  * The following arguably belongs in a separate header file  */
end_comment

begin_comment
comment|/*  * Defines  */
end_comment

begin_define
define|#
directive|define
name|NETVSC_SEND_BUFFER_SIZE
value|(64*1024)
end_define

begin_comment
comment|/* 64K */
end_comment

begin_define
define|#
directive|define
name|NETVSC_SEND_BUFFER_ID
value|0xface
end_define

begin_define
define|#
directive|define
name|NETVSC_RECEIVE_BUFFER_SIZE
value|(1024*1024)
end_define

begin_comment
comment|/* 1MB */
end_comment

begin_define
define|#
directive|define
name|NETVSC_RECEIVE_BUFFER_ID
value|0xcafe
end_define

begin_define
define|#
directive|define
name|NETVSC_RECEIVE_SG_COUNT
value|1
end_define

begin_comment
comment|/* Preallocated receive packets */
end_comment

begin_define
define|#
directive|define
name|NETVSC_RECEIVE_PACKETLIST_COUNT
value|256
end_define

begin_comment
comment|/*  * Maximum MTU we permit to be configured for a netvsc interface.  * When the code was developed, a max MTU of 12232 was tested and  * proven to work.  9K is a reasonable maximum for an Ethernet.  */
end_comment

begin_define
define|#
directive|define
name|NETVSC_MAX_CONFIGURABLE_MTU
value|(9 * 1024)
end_define

begin_comment
comment|/*  * Data types  */
end_comment

begin_comment
comment|/*  * Per netvsc channel-specific  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|netvsc_dev_
block|{
name|struct
name|hv_device
modifier|*
name|dev
decl_stmt|;
name|int
name|num_outstanding_sends
decl_stmt|;
comment|/* List of free preallocated NETVSC_PACKET to represent RX packet */
name|STAILQ_HEAD
argument_list|(
argument|PQ
argument_list|,
argument|netvsc_packet_
argument_list|)
name|myrx_packet_list
expr_stmt|;
name|struct
name|mtx
name|rx_pkt_list_lock
decl_stmt|;
comment|/* Send buffer allocated by us but manages by NetVSP */
name|void
modifier|*
name|send_buf
decl_stmt|;
name|uint32_t
name|send_buf_size
decl_stmt|;
name|uint32_t
name|send_buf_gpadl_handle
decl_stmt|;
name|uint32_t
name|send_section_size
decl_stmt|;
comment|/* Receive buffer allocated by us but managed by NetVSP */
name|void
modifier|*
name|rx_buf
decl_stmt|;
name|uint32_t
name|rx_buf_size
decl_stmt|;
name|uint32_t
name|rx_buf_gpadl_handle
decl_stmt|;
name|uint32_t
name|rx_section_count
decl_stmt|;
name|nvsp_1_rx_buf_section
modifier|*
name|rx_sections
decl_stmt|;
comment|/* Used for NetVSP initialization protocol */
name|struct
name|sema
name|channel_init_sema
decl_stmt|;
name|nvsp_msg
name|channel_init_packet
decl_stmt|;
name|nvsp_msg
name|revoke_packet
decl_stmt|;
comment|/*uint8_t				hw_mac_addr[HW_MACADDR_LEN];*/
comment|/* Holds rndis device info */
name|void
modifier|*
name|extension
decl_stmt|;
name|hv_bool_uint8_t
name|destroy
decl_stmt|;
comment|/* Negotiated NVSP version */
name|uint32_t
name|nvsp_version
decl_stmt|;
block|}
name|netvsc_dev
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|pfn_on_send_rx_completion
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_define
define|#
directive|define
name|NETVSC_DEVICE_RING_BUFFER_SIZE
value|(64 * PAGE_SIZE)
end_define

begin_define
define|#
directive|define
name|NETVSC_PACKET_MAXPAGE
value|16
end_define

begin_typedef
typedef|typedef
struct|struct
name|xfer_page_packet_
block|{
comment|/* 	 * This needs to be here because the network RX code casts 	 * an instantiation of this structure to a netvsc_packet. 	 */
name|STAILQ_ENTRY
argument_list|(
argument|netvsc_packet_
argument_list|)
name|mylist_entry
expr_stmt|;
name|uint32_t
name|count
decl_stmt|;
block|}
name|xfer_page_packet
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|netvsc_packet_
block|{
comment|/* 	 * List used when enqueued on&net_dev->rx_packet_list, 	 * and when enqueued within the netvsc code 	 */
name|STAILQ_ENTRY
argument_list|(
argument|netvsc_packet_
argument_list|)
name|mylist_entry
expr_stmt|;
name|struct
name|hv_device
modifier|*
name|device
decl_stmt|;
name|hv_bool_uint8_t
name|is_data_pkt
decl_stmt|;
comment|/* One byte */
name|uint16_t
name|vlan_tci
decl_stmt|;
name|xfer_page_packet
modifier|*
name|xfer_page_pkt
decl_stmt|;
comment|/* Completion */
union|union
block|{
struct|struct
block|{
name|uint64_t
name|rx_completion_tid
decl_stmt|;
name|void
modifier|*
name|rx_completion_context
decl_stmt|;
comment|/* This is no longer used */
name|pfn_on_send_rx_completion
name|on_rx_completion
decl_stmt|;
block|}
name|rx
struct|;
struct|struct
block|{
name|uint64_t
name|send_completion_tid
decl_stmt|;
name|void
modifier|*
name|send_completion_context
decl_stmt|;
comment|/* Still used in netvsc and filter code */
name|pfn_on_send_rx_completion
name|on_send_completion
decl_stmt|;
block|}
name|send
struct|;
block|}
name|compl
union|;
name|void
modifier|*
name|extension
decl_stmt|;
name|uint32_t
name|tot_data_buf_len
decl_stmt|;
name|uint32_t
name|page_buf_count
decl_stmt|;
name|hv_vmbus_page_buffer
name|page_buffers
index|[
name|NETVSC_PACKET_MAXPAGE
index|]
decl_stmt|;
block|}
name|netvsc_packet
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint8_t
name|mac_addr
index|[
literal|6
index|]
decl_stmt|;
comment|/* Assumption unsigned long */
name|hv_bool_uint8_t
name|link_state
decl_stmt|;
block|}
name|netvsc_device_info
typedef|;
end_typedef

begin_comment
comment|/*  * Device-specific softc structure  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|hn_softc
block|{
name|struct
name|ifnet
modifier|*
name|hn_ifp
decl_stmt|;
name|struct
name|arpcom
name|arpcom
decl_stmt|;
name|device_t
name|hn_dev
decl_stmt|;
name|uint8_t
name|hn_unit
decl_stmt|;
name|int
name|hn_carrier
decl_stmt|;
name|int
name|hn_if_flags
decl_stmt|;
name|struct
name|mtx
name|hn_lock
decl_stmt|;
name|int
name|hn_initdone
decl_stmt|;
comment|/* See hv_netvsc_drv_freebsd.c for rules on how to use */
name|int
name|temp_unusable
decl_stmt|;
name|struct
name|hv_device
modifier|*
name|hn_dev_obj
decl_stmt|;
name|netvsc_dev
modifier|*
name|net_dev
decl_stmt|;
block|}
name|hn_softc_t
typedef|;
end_typedef

begin_comment
comment|/*  * Externs  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|hv_promisc_mode
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|netvsc_linkstatus_callback
parameter_list|(
name|struct
name|hv_device
modifier|*
name|device_obj
parameter_list|,
name|uint32_t
name|status
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|netvsc_recv
parameter_list|(
name|struct
name|hv_device
modifier|*
name|device_obj
parameter_list|,
name|netvsc_packet
modifier|*
name|packet
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|netvsc_xmit_completion
parameter_list|(
name|void
modifier|*
name|context
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|hv_nv_on_receive_completion
parameter_list|(
name|void
modifier|*
name|context
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|netvsc_dev
modifier|*
name|hv_nv_on_device_add
parameter_list|(
name|struct
name|hv_device
modifier|*
name|device
parameter_list|,
name|void
modifier|*
name|additional_info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|hv_nv_on_device_remove
parameter_list|(
name|struct
name|hv_device
modifier|*
name|device
parameter_list|,
name|boolean_t
name|destroy_channel
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|hv_nv_on_send
parameter_list|(
name|struct
name|hv_device
modifier|*
name|device
parameter_list|,
name|netvsc_packet
modifier|*
name|pkt
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __HV_NET_VSC_H__ */
end_comment

end_unit

