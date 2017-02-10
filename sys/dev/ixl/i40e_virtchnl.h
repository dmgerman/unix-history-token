begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************    Copyright (c) 2013-2015, Intel Corporation    All rights reserved.      Redistribution and use in source and binary forms, with or without    modification, are permitted provided that the following conditions are met:       1. Redistributions of source code must retain the above copyright notice,        this list of conditions and the following disclaimer.       2. Redistributions in binary form must reproduce the above copyright        notice, this list of conditions and the following disclaimer in the        documentation and/or other materials provided with the distribution.       3. Neither the name of the Intel Corporation nor the names of its        contributors may be used to endorse or promote products derived from        this software without specific prior written permission.      THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE    ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE    LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR    CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF    SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS    INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN    CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)    ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE   POSSIBILITY OF SUCH DAMAGE.  ******************************************************************************/
end_comment

begin_comment
comment|/*$FreeBSD$*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_I40E_VIRTCHNL_H_
end_ifndef

begin_define
define|#
directive|define
name|_I40E_VIRTCHNL_H_
end_define

begin_include
include|#
directive|include
file|"i40e_type.h"
end_include

begin_comment
comment|/* Description:  * This header file describes the VF-PF communication protocol used  * by the various i40e drivers.  *  * Admin queue buffer usage:  * desc->opcode is always i40e_aqc_opc_send_msg_to_pf  * flags, retval, datalen, and data addr are all used normally.  * Firmware copies the cookie fields when sending messages between the PF and  * VF, but uses all other fields internally. Due to this limitation, we  * must send all messages as "indirect", i.e. using an external buffer.  *  * All the vsi indexes are relative to the VF. Each VF can have maximum of  * three VSIs. All the queue indexes are relative to the VSI.  Each VF can  * have a maximum of sixteen queues for all of its VSIs.  *  * The PF is required to return a status code in v_retval for all messages  * except RESET_VF, which does not require any response. The return value is of  * i40e_status_code type, defined in the i40e_type.h.  *  * In general, VF driver initialization should roughly follow the order of these  * opcodes. The VF driver must first validate the API version of the PF driver,  * then request a reset, then get resources, then configure queues and  * interrupts. After these operations are complete, the VF driver may start  * its queues, optionally add MAC and VLAN filters, and process traffic.  */
end_comment

begin_comment
comment|/* Opcodes for VF-PF communication. These are placed in the v_opcode field  * of the virtchnl_msg structure.  */
end_comment

begin_enum
enum|enum
name|i40e_virtchnl_ops
block|{
comment|/* The PF sends status change events to VFs using  * the I40E_VIRTCHNL_OP_EVENT opcode.  * VFs send requests to the PF using the other ops.  */
name|I40E_VIRTCHNL_OP_UNKNOWN
init|=
literal|0
block|,
name|I40E_VIRTCHNL_OP_VERSION
init|=
literal|1
block|,
comment|/* must ALWAYS be 1 */
name|I40E_VIRTCHNL_OP_RESET_VF
init|=
literal|2
block|,
name|I40E_VIRTCHNL_OP_GET_VF_RESOURCES
init|=
literal|3
block|,
name|I40E_VIRTCHNL_OP_CONFIG_TX_QUEUE
init|=
literal|4
block|,
name|I40E_VIRTCHNL_OP_CONFIG_RX_QUEUE
init|=
literal|5
block|,
name|I40E_VIRTCHNL_OP_CONFIG_VSI_QUEUES
init|=
literal|6
block|,
name|I40E_VIRTCHNL_OP_CONFIG_IRQ_MAP
init|=
literal|7
block|,
name|I40E_VIRTCHNL_OP_ENABLE_QUEUES
init|=
literal|8
block|,
name|I40E_VIRTCHNL_OP_DISABLE_QUEUES
init|=
literal|9
block|,
name|I40E_VIRTCHNL_OP_ADD_ETHER_ADDRESS
init|=
literal|10
block|,
name|I40E_VIRTCHNL_OP_DEL_ETHER_ADDRESS
init|=
literal|11
block|,
name|I40E_VIRTCHNL_OP_ADD_VLAN
init|=
literal|12
block|,
name|I40E_VIRTCHNL_OP_DEL_VLAN
init|=
literal|13
block|,
name|I40E_VIRTCHNL_OP_CONFIG_PROMISCUOUS_MODE
init|=
literal|14
block|,
name|I40E_VIRTCHNL_OP_GET_STATS
init|=
literal|15
block|,
name|I40E_VIRTCHNL_OP_FCOE
init|=
literal|16
block|,
name|I40E_VIRTCHNL_OP_EVENT
init|=
literal|17
block|,
comment|/* must ALWAYS be 17 */
name|I40E_VIRTCHNL_OP_CONFIG_RSS_KEY
init|=
literal|23
block|,
name|I40E_VIRTCHNL_OP_CONFIG_RSS_LUT
init|=
literal|24
block|,
name|I40E_VIRTCHNL_OP_GET_RSS_HENA_CAPS
init|=
literal|25
block|,
name|I40E_VIRTCHNL_OP_SET_RSS_HENA
init|=
literal|26
block|,  }
enum|;
end_enum

begin_comment
comment|/* Virtual channel message descriptor. This overlays the admin queue  * descriptor. All other data is passed in external buffers.  */
end_comment

begin_struct
struct|struct
name|i40e_virtchnl_msg
block|{
name|u8
name|pad
index|[
literal|8
index|]
decl_stmt|;
comment|/* AQ flags/opcode/len/retval fields */
name|enum
name|i40e_virtchnl_ops
name|v_opcode
decl_stmt|;
comment|/* avoid confusion with desc->opcode */
name|enum
name|i40e_status_code
name|v_retval
decl_stmt|;
comment|/* ditto for desc->retval */
name|u32
name|vfid
decl_stmt|;
comment|/* used by PF when sending to VF */
block|}
struct|;
end_struct

begin_comment
comment|/* Message descriptions and data structures.*/
end_comment

begin_comment
comment|/* I40E_VIRTCHNL_OP_VERSION  * VF posts its version number to the PF. PF responds with its version number  * in the same format, along with a return code.  * Reply from PF has its major/minor versions also in param0 and param1.  * If there is a major version mismatch, then the VF cannot operate.  * If there is a minor version mismatch, then the VF can operate but should  * add a warning to the system log.  *  * This enum element MUST always be specified as == 1, regardless of other  * changes in the API. The PF must always respond to this message without  * error regardless of version mismatch.  */
end_comment

begin_define
define|#
directive|define
name|I40E_VIRTCHNL_VERSION_MAJOR
value|1
end_define

begin_define
define|#
directive|define
name|I40E_VIRTCHNL_VERSION_MINOR
value|1
end_define

begin_define
define|#
directive|define
name|I40E_VIRTCHNL_VERSION_MINOR_NO_VF_CAPS
value|0
end_define

begin_struct
struct|struct
name|i40e_virtchnl_version_info
block|{
name|u32
name|major
decl_stmt|;
name|u32
name|minor
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* I40E_VIRTCHNL_OP_RESET_VF  * VF sends this request to PF with no parameters  * PF does NOT respond! VF driver must delay then poll VFGEN_RSTAT register  * until reset completion is indicated. The admin queue must be reinitialized  * after this operation.  *  * When reset is complete, PF must ensure that all queues in all VSIs associated  * with the VF are stopped, all queue configurations in the HMC are set to 0,  * and all MAC and VLAN filters (except the default MAC address) on all VSIs  * are cleared.  */
end_comment

begin_comment
comment|/* I40E_VIRTCHNL_OP_GET_VF_RESOURCES  * Version 1.0 VF sends this request to PF with no parameters  * Version 1.1 VF sends this request to PF with u32 bitmap of its capabilities  * PF responds with an indirect message containing  * i40e_virtchnl_vf_resource and one or more  * i40e_virtchnl_vsi_resource structures.  */
end_comment

begin_struct
struct|struct
name|i40e_virtchnl_vsi_resource
block|{
name|u16
name|vsi_id
decl_stmt|;
name|u16
name|num_queue_pairs
decl_stmt|;
name|enum
name|i40e_vsi_type
name|vsi_type
decl_stmt|;
name|u16
name|qset_handle
decl_stmt|;
name|u8
name|default_mac_addr
index|[
name|I40E_ETH_LENGTH_OF_ADDRESS
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* VF offload flags */
end_comment

begin_define
define|#
directive|define
name|I40E_VIRTCHNL_VF_OFFLOAD_L2
value|0x00000001
end_define

begin_define
define|#
directive|define
name|I40E_VIRTCHNL_VF_OFFLOAD_IWARP
value|0x00000002
end_define

begin_define
define|#
directive|define
name|I40E_VIRTCHNL_VF_OFFLOAD_FCOE
value|0x00000004
end_define

begin_define
define|#
directive|define
name|I40E_VIRTCHNL_VF_OFFLOAD_RSS_AQ
value|0x00000008
end_define

begin_define
define|#
directive|define
name|I40E_VIRTCHNL_VF_OFFLOAD_RSS_REG
value|0x00000010
end_define

begin_define
define|#
directive|define
name|I40E_VIRTCHNL_VF_OFFLOAD_WB_ON_ITR
value|0x00000020
end_define

begin_define
define|#
directive|define
name|I40E_VIRTCHNL_VF_OFFLOAD_VLAN
value|0x00010000
end_define

begin_define
define|#
directive|define
name|I40E_VIRTCHNL_VF_OFFLOAD_RX_POLLING
value|0x00020000
end_define

begin_define
define|#
directive|define
name|I40E_VIRTCHNL_VF_OFFLOAD_RSS_PCTYPE_V2
value|0x00040000
end_define

begin_define
define|#
directive|define
name|I40E_VIRTCHNL_VF_OFFLOAD_RSS_PF
value|0X00080000
end_define

begin_define
define|#
directive|define
name|I40E_VIRTCHNL_VF_OFFLOAD_ENCAP_CSUM
value|0X00100000
end_define

begin_define
define|#
directive|define
name|I40E_VF_BASE_MODE_OFFLOADS
value|(I40E_VIRTCHNL_VF_OFFLOAD_L2 | \ 				    I40E_VIRTCHNL_VF_OFFLOAD_VLAN | \ 				    I40E_VIRTCHNL_VF_OFFLOAD_RSS_PF)
end_define

begin_struct
struct|struct
name|i40e_virtchnl_vf_resource
block|{
name|u16
name|num_vsis
decl_stmt|;
name|u16
name|num_queue_pairs
decl_stmt|;
name|u16
name|max_vectors
decl_stmt|;
name|u16
name|max_mtu
decl_stmt|;
name|u32
name|vf_offload_flags
decl_stmt|;
name|u32
name|rss_key_size
decl_stmt|;
name|u32
name|rss_lut_size
decl_stmt|;
name|struct
name|i40e_virtchnl_vsi_resource
name|vsi_res
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* I40E_VIRTCHNL_OP_CONFIG_TX_QUEUE  * VF sends this message to set up parameters for one TX queue.  * External data buffer contains one instance of i40e_virtchnl_txq_info.  * PF configures requested queue and returns a status code.  */
end_comment

begin_comment
comment|/* Tx queue config info */
end_comment

begin_struct
struct|struct
name|i40e_virtchnl_txq_info
block|{
name|u16
name|vsi_id
decl_stmt|;
name|u16
name|queue_id
decl_stmt|;
name|u16
name|ring_len
decl_stmt|;
comment|/* number of descriptors, multiple of 8 */
name|u16
name|headwb_enabled
decl_stmt|;
name|u64
name|dma_ring_addr
decl_stmt|;
name|u64
name|dma_headwb_addr
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* I40E_VIRTCHNL_OP_CONFIG_RX_QUEUE  * VF sends this message to set up parameters for one RX queue.  * External data buffer contains one instance of i40e_virtchnl_rxq_info.  * PF configures requested queue and returns a status code.  */
end_comment

begin_comment
comment|/* Rx queue config info */
end_comment

begin_struct
struct|struct
name|i40e_virtchnl_rxq_info
block|{
name|u16
name|vsi_id
decl_stmt|;
name|u16
name|queue_id
decl_stmt|;
name|u32
name|ring_len
decl_stmt|;
comment|/* number of descriptors, multiple of 32 */
name|u16
name|hdr_size
decl_stmt|;
name|u16
name|splithdr_enabled
decl_stmt|;
name|u32
name|databuffer_size
decl_stmt|;
name|u32
name|max_pkt_size
decl_stmt|;
name|u64
name|dma_ring_addr
decl_stmt|;
name|enum
name|i40e_hmc_obj_rx_hsplit_0
name|rx_split_pos
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* I40E_VIRTCHNL_OP_CONFIG_VSI_QUEUES  * VF sends this message to set parameters for all active TX and RX queues  * associated with the specified VSI.  * PF configures queues and returns status.  * If the number of queues specified is greater than the number of queues  * associated with the VSI, an error is returned and no queues are configured.  */
end_comment

begin_struct
struct|struct
name|i40e_virtchnl_queue_pair_info
block|{
comment|/* NOTE: vsi_id and queue_id should be identical for both queues. */
name|struct
name|i40e_virtchnl_txq_info
name|txq
decl_stmt|;
name|struct
name|i40e_virtchnl_rxq_info
name|rxq
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|i40e_virtchnl_vsi_queue_config_info
block|{
name|u16
name|vsi_id
decl_stmt|;
name|u16
name|num_queue_pairs
decl_stmt|;
name|struct
name|i40e_virtchnl_queue_pair_info
name|qpair
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* I40E_VIRTCHNL_OP_CONFIG_IRQ_MAP  * VF uses this message to map vectors to queues.  * The rxq_map and txq_map fields are bitmaps used to indicate which queues  * are to be associated with the specified vector.  * The "other" causes are always mapped to vector 0.  * PF configures interrupt mapping and returns status.  */
end_comment

begin_struct
struct|struct
name|i40e_virtchnl_vector_map
block|{
name|u16
name|vsi_id
decl_stmt|;
name|u16
name|vector_id
decl_stmt|;
name|u16
name|rxq_map
decl_stmt|;
name|u16
name|txq_map
decl_stmt|;
name|u16
name|rxitr_idx
decl_stmt|;
name|u16
name|txitr_idx
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|i40e_virtchnl_irq_map_info
block|{
name|u16
name|num_vectors
decl_stmt|;
name|struct
name|i40e_virtchnl_vector_map
name|vecmap
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* I40E_VIRTCHNL_OP_ENABLE_QUEUES  * I40E_VIRTCHNL_OP_DISABLE_QUEUES  * VF sends these message to enable or disable TX/RX queue pairs.  * The queues fields are bitmaps indicating which queues to act upon.  * (Currently, we only support 16 queues per VF, but we make the field  * u32 to allow for expansion.)  * PF performs requested action and returns status.  */
end_comment

begin_struct
struct|struct
name|i40e_virtchnl_queue_select
block|{
name|u16
name|vsi_id
decl_stmt|;
name|u16
name|pad
decl_stmt|;
name|u32
name|rx_queues
decl_stmt|;
name|u32
name|tx_queues
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* I40E_VIRTCHNL_OP_ADD_ETHER_ADDRESS  * VF sends this message in order to add one or more unicast or multicast  * address filters for the specified VSI.  * PF adds the filters and returns status.  */
end_comment

begin_comment
comment|/* I40E_VIRTCHNL_OP_DEL_ETHER_ADDRESS  * VF sends this message in order to remove one or more unicast or multicast  * filters for the specified VSI.  * PF removes the filters and returns status.  */
end_comment

begin_struct
struct|struct
name|i40e_virtchnl_ether_addr
block|{
name|u8
name|addr
index|[
name|I40E_ETH_LENGTH_OF_ADDRESS
index|]
decl_stmt|;
name|u8
name|pad
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|i40e_virtchnl_ether_addr_list
block|{
name|u16
name|vsi_id
decl_stmt|;
name|u16
name|num_elements
decl_stmt|;
name|struct
name|i40e_virtchnl_ether_addr
name|list
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* I40E_VIRTCHNL_OP_ADD_VLAN  * VF sends this message to add one or more VLAN tag filters for receives.  * PF adds the filters and returns status.  * If a port VLAN is configured by the PF, this operation will return an  * error to the VF.  */
end_comment

begin_comment
comment|/* I40E_VIRTCHNL_OP_DEL_VLAN  * VF sends this message to remove one or more VLAN tag filters for receives.  * PF removes the filters and returns status.  * If a port VLAN is configured by the PF, this operation will return an  * error to the VF.  */
end_comment

begin_struct
struct|struct
name|i40e_virtchnl_vlan_filter_list
block|{
name|u16
name|vsi_id
decl_stmt|;
name|u16
name|num_elements
decl_stmt|;
name|u16
name|vlan_id
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* I40E_VIRTCHNL_OP_CONFIG_PROMISCUOUS_MODE  * VF sends VSI id and flags.  * PF returns status code in retval.  * Note: we assume that broadcast accept mode is always enabled.  */
end_comment

begin_struct
struct|struct
name|i40e_virtchnl_promisc_info
block|{
name|u16
name|vsi_id
decl_stmt|;
name|u16
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|I40E_FLAG_VF_UNICAST_PROMISC
value|0x00000001
end_define

begin_define
define|#
directive|define
name|I40E_FLAG_VF_MULTICAST_PROMISC
value|0x00000002
end_define

begin_comment
comment|/* I40E_VIRTCHNL_OP_GET_STATS  * VF sends this message to request stats for the selected VSI. VF uses  * the i40e_virtchnl_queue_select struct to specify the VSI. The queue_id  * field is ignored by the PF.  *  * PF replies with struct i40e_eth_stats in an external buffer.  */
end_comment

begin_comment
comment|/* I40E_VIRTCHNL_OP_CONFIG_RSS_KEY  * I40E_VIRTCHNL_OP_CONFIG_RSS_LUT  * VF sends these messages to configure RSS. Only supported if both PF  * and VF drivers set the I40E_VIRTCHNL_VF_OFFLOAD_RSS_PF bit during  * configuration negotiation. If this is the case, then the rss fields in  * the vf resource struct are valid.  * Both the key and LUT are initialized to 0 by the PF, meaning that  * RSS is effectively disabled until set up by the VF.  */
end_comment

begin_struct
struct|struct
name|i40e_virtchnl_rss_key
block|{
name|u16
name|vsi_id
decl_stmt|;
name|u16
name|key_len
decl_stmt|;
name|u8
name|key
index|[
literal|1
index|]
decl_stmt|;
comment|/* RSS hash key, packed bytes */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|i40e_virtchnl_rss_lut
block|{
name|u16
name|vsi_id
decl_stmt|;
name|u16
name|lut_entries
decl_stmt|;
name|u8
name|lut
index|[
literal|1
index|]
decl_stmt|;
comment|/* RSS lookup table*/
block|}
struct|;
end_struct

begin_comment
comment|/* I40E_VIRTCHNL_OP_GET_RSS_HENA_CAPS  * I40E_VIRTCHNL_OP_SET_RSS_HENA  * VF sends these messages to get and set the hash filter enable bits for RSS.  * By default, the PF sets these to all possible traffic types that the  * hardware supports. The VF can query this value if it wants to change the  * traffic types that are hashed by the hardware.  * Traffic types are defined in the i40e_filter_pctype enum in i40e_type.h  */
end_comment

begin_struct
struct|struct
name|i40e_virtchnl_rss_hena
block|{
name|u64
name|hena
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* I40E_VIRTCHNL_OP_EVENT  * PF sends this message to inform the VF driver of events that may affect it.  * No direct response is expected from the VF, though it may generate other  * messages in response to this one.  */
end_comment

begin_enum
enum|enum
name|i40e_virtchnl_event_codes
block|{
name|I40E_VIRTCHNL_EVENT_UNKNOWN
init|=
literal|0
block|,
name|I40E_VIRTCHNL_EVENT_LINK_CHANGE
block|,
name|I40E_VIRTCHNL_EVENT_RESET_IMPENDING
block|,
name|I40E_VIRTCHNL_EVENT_PF_DRIVER_CLOSE
block|, }
enum|;
end_enum

begin_define
define|#
directive|define
name|I40E_PF_EVENT_SEVERITY_INFO
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PF_EVENT_SEVERITY_ATTENTION
value|1
end_define

begin_define
define|#
directive|define
name|I40E_PF_EVENT_SEVERITY_ACTION_REQUIRED
value|2
end_define

begin_define
define|#
directive|define
name|I40E_PF_EVENT_SEVERITY_CERTAIN_DOOM
value|255
end_define

begin_struct
struct|struct
name|i40e_virtchnl_pf_event
block|{
name|enum
name|i40e_virtchnl_event_codes
name|event
decl_stmt|;
union|union
block|{
struct|struct
block|{
name|enum
name|i40e_aq_link_speed
name|link_speed
decl_stmt|;
name|bool
name|link_status
decl_stmt|;
block|}
name|link_event
struct|;
block|}
name|event_data
union|;
name|int
name|severity
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* VF reset states - these are written into the RSTAT register:  * I40E_VFGEN_RSTAT1 on the PF  * I40E_VFGEN_RSTAT on the VF  * When the PF initiates a reset, it writes 0  * When the reset is complete, it writes 1  * When the PF detects that the VF has recovered, it writes 2  * VF checks this register periodically to determine if a reset has occurred,  * then polls it to know when the reset is complete.  * If either the PF or VF reads the register while the hardware  * is in a reset state, it will return DEADBEEF, which, when masked  * will result in 3.  */
end_comment

begin_enum
enum|enum
name|i40e_vfr_states
block|{
name|I40E_VFR_INPROGRESS
init|=
literal|0
block|,
name|I40E_VFR_COMPLETED
block|,
name|I40E_VFR_VFACTIVE
block|,
name|I40E_VFR_UNKNOWN
block|, }
enum|;
end_enum

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _I40E_VIRTCHNL_H_ */
end_comment

end_unit

