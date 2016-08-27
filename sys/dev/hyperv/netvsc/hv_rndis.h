begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2009-2012,2016 Microsoft Corp.  * Copyright (c) 2010-2012 Citrix Inc.  * Copyright (c) 2012 NetApp Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__HV_RNDIS_H__
end_ifndef

begin_define
define|#
directive|define
name|__HV_RNDIS_H__
end_define

begin_include
include|#
directive|include
file|<net/rndis.h>
end_include

begin_comment
comment|/*  * NDIS protocol version numbers  */
end_comment

begin_define
define|#
directive|define
name|NDIS_VERSION_5_0
value|0x00050000
end_define

begin_define
define|#
directive|define
name|NDIS_VERSION_5_1
value|0x00050001
end_define

begin_define
define|#
directive|define
name|NDIS_VERSION_6_0
value|0x00060000
end_define

begin_define
define|#
directive|define
name|NDIS_VERSION_6_1
value|0x00060001
end_define

begin_define
define|#
directive|define
name|NDIS_VERSION_6_30
value|0x0006001e
end_define

begin_define
define|#
directive|define
name|NDIS_VERSION_MAJOR
parameter_list|(
name|ver
parameter_list|)
value|(((ver)& 0xffff0000)>> 16)
end_define

begin_define
define|#
directive|define
name|NDIS_VERSION_MINOR
parameter_list|(
name|ver
parameter_list|)
value|((ver)& 0xffff)
end_define

begin_comment
comment|/*  * Object Identifiers used by NdisRequest Query/Set Information  */
end_comment

begin_comment
comment|/*  * General Objects  */
end_comment

begin_define
define|#
directive|define
name|RNDIS_OID_GEN_SUPPORTED_LIST
value|0x00010101
end_define

begin_define
define|#
directive|define
name|RNDIS_OID_GEN_HARDWARE_STATUS
value|0x00010102
end_define

begin_define
define|#
directive|define
name|RNDIS_OID_GEN_MEDIA_SUPPORTED
value|0x00010103
end_define

begin_define
define|#
directive|define
name|RNDIS_OID_GEN_MEDIA_IN_USE
value|0x00010104
end_define

begin_define
define|#
directive|define
name|RNDIS_OID_GEN_MAXIMUM_LOOKAHEAD
value|0x00010105
end_define

begin_define
define|#
directive|define
name|RNDIS_OID_GEN_MAXIMUM_FRAME_SIZE
value|0x00010106
end_define

begin_define
define|#
directive|define
name|RNDIS_OID_GEN_LINK_SPEED
value|0x00010107
end_define

begin_define
define|#
directive|define
name|RNDIS_OID_GEN_TRANSMIT_BUFFER_SPACE
value|0x00010108
end_define

begin_define
define|#
directive|define
name|RNDIS_OID_GEN_RECEIVE_BUFFER_SPACE
value|0x00010109
end_define

begin_define
define|#
directive|define
name|RNDIS_OID_GEN_TRANSMIT_BLOCK_SIZE
value|0x0001010A
end_define

begin_define
define|#
directive|define
name|RNDIS_OID_GEN_RECEIVE_BLOCK_SIZE
value|0x0001010B
end_define

begin_define
define|#
directive|define
name|RNDIS_OID_GEN_VENDOR_ID
value|0x0001010C
end_define

begin_define
define|#
directive|define
name|RNDIS_OID_GEN_VENDOR_DESCRIPTION
value|0x0001010D
end_define

begin_define
define|#
directive|define
name|RNDIS_OID_GEN_CURRENT_PACKET_FILTER
value|0x0001010E
end_define

begin_define
define|#
directive|define
name|RNDIS_OID_GEN_CURRENT_LOOKAHEAD
value|0x0001010F
end_define

begin_define
define|#
directive|define
name|RNDIS_OID_GEN_DRIVER_VERSION
value|0x00010110
end_define

begin_define
define|#
directive|define
name|RNDIS_OID_GEN_MAXIMUM_TOTAL_SIZE
value|0x00010111
end_define

begin_define
define|#
directive|define
name|RNDIS_OID_GEN_PROTOCOL_OPTIONS
value|0x00010112
end_define

begin_define
define|#
directive|define
name|RNDIS_OID_GEN_MAC_OPTIONS
value|0x00010113
end_define

begin_define
define|#
directive|define
name|RNDIS_OID_GEN_MEDIA_CONNECT_STATUS
value|0x00010114
end_define

begin_define
define|#
directive|define
name|RNDIS_OID_GEN_MAXIMUM_SEND_PACKETS
value|0x00010115
end_define

begin_define
define|#
directive|define
name|RNDIS_OID_GEN_VENDOR_DRIVER_VERSION
value|0x00010116
end_define

begin_define
define|#
directive|define
name|RNDIS_OID_GEN_NETWORK_LAYER_ADDRESSES
value|0x00010118
end_define

begin_define
define|#
directive|define
name|RNDIS_OID_GEN_TRANSPORT_HEADER_OFFSET
value|0x00010119
end_define

begin_define
define|#
directive|define
name|RNDIS_OID_GEN_MACHINE_NAME
value|0x0001021A
end_define

begin_define
define|#
directive|define
name|RNDIS_OID_GEN_RNDIS_CONFIG_PARAMETER
value|0x0001021B
end_define

begin_comment
comment|/*  * For receive side scale  */
end_comment

begin_comment
comment|/* Query only */
end_comment

begin_define
define|#
directive|define
name|RNDIS_OID_GEN_RSS_CAPABILITIES
value|0x00010203
end_define

begin_comment
comment|/* Query and set */
end_comment

begin_define
define|#
directive|define
name|RNDIS_OID_GEN_RSS_PARAMETERS
value|0x00010204
end_define

begin_define
define|#
directive|define
name|RNDIS_OID_GEN_XMIT_OK
value|0x00020101
end_define

begin_define
define|#
directive|define
name|RNDIS_OID_GEN_RCV_OK
value|0x00020102
end_define

begin_define
define|#
directive|define
name|RNDIS_OID_GEN_XMIT_ERROR
value|0x00020103
end_define

begin_define
define|#
directive|define
name|RNDIS_OID_GEN_RCV_ERROR
value|0x00020104
end_define

begin_define
define|#
directive|define
name|RNDIS_OID_GEN_RCV_NO_BUFFER
value|0x00020105
end_define

begin_define
define|#
directive|define
name|RNDIS_OID_GEN_DIRECTED_BYTES_XMIT
value|0x00020201
end_define

begin_define
define|#
directive|define
name|RNDIS_OID_GEN_DIRECTED_FRAMES_XMIT
value|0x00020202
end_define

begin_define
define|#
directive|define
name|RNDIS_OID_GEN_MULTICAST_BYTES_XMIT
value|0x00020203
end_define

begin_define
define|#
directive|define
name|RNDIS_OID_GEN_MULTICAST_FRAMES_XMIT
value|0x00020204
end_define

begin_define
define|#
directive|define
name|RNDIS_OID_GEN_BROADCAST_BYTES_XMIT
value|0x00020205
end_define

begin_define
define|#
directive|define
name|RNDIS_OID_GEN_BROADCAST_FRAMES_XMIT
value|0x00020206
end_define

begin_define
define|#
directive|define
name|RNDIS_OID_GEN_DIRECTED_BYTES_RCV
value|0x00020207
end_define

begin_define
define|#
directive|define
name|RNDIS_OID_GEN_DIRECTED_FRAMES_RCV
value|0x00020208
end_define

begin_define
define|#
directive|define
name|RNDIS_OID_GEN_MULTICAST_BYTES_RCV
value|0x00020209
end_define

begin_define
define|#
directive|define
name|RNDIS_OID_GEN_MULTICAST_FRAMES_RCV
value|0x0002020A
end_define

begin_define
define|#
directive|define
name|RNDIS_OID_GEN_BROADCAST_BYTES_RCV
value|0x0002020B
end_define

begin_define
define|#
directive|define
name|RNDIS_OID_GEN_BROADCAST_FRAMES_RCV
value|0x0002020C
end_define

begin_define
define|#
directive|define
name|RNDIS_OID_GEN_RCV_CRC_ERROR
value|0x0002020D
end_define

begin_define
define|#
directive|define
name|RNDIS_OID_GEN_TRANSMIT_QUEUE_LENGTH
value|0x0002020E
end_define

begin_define
define|#
directive|define
name|RNDIS_OID_GEN_GET_TIME_CAPS
value|0x0002020F
end_define

begin_define
define|#
directive|define
name|RNDIS_OID_GEN_GET_NETCARD_TIME
value|0x00020210
end_define

begin_comment
comment|/*  * These are connection-oriented general OIDs.  * These replace the above OIDs for connection-oriented media.  */
end_comment

begin_define
define|#
directive|define
name|RNDIS_OID_GEN_CO_SUPPORTED_LIST
value|0x00010101
end_define

begin_define
define|#
directive|define
name|RNDIS_OID_GEN_CO_HARDWARE_STATUS
value|0x00010102
end_define

begin_define
define|#
directive|define
name|RNDIS_OID_GEN_CO_MEDIA_SUPPORTED
value|0x00010103
end_define

begin_define
define|#
directive|define
name|RNDIS_OID_GEN_CO_MEDIA_IN_USE
value|0x00010104
end_define

begin_define
define|#
directive|define
name|RNDIS_OID_GEN_CO_LINK_SPEED
value|0x00010105
end_define

begin_define
define|#
directive|define
name|RNDIS_OID_GEN_CO_VENDOR_ID
value|0x00010106
end_define

begin_define
define|#
directive|define
name|RNDIS_OID_GEN_CO_VENDOR_DESCRIPTION
value|0x00010107
end_define

begin_define
define|#
directive|define
name|RNDIS_OID_GEN_CO_DRIVER_VERSION
value|0x00010108
end_define

begin_define
define|#
directive|define
name|RNDIS_OID_GEN_CO_PROTOCOL_OPTIONS
value|0x00010109
end_define

begin_define
define|#
directive|define
name|RNDIS_OID_GEN_CO_MAC_OPTIONS
value|0x0001010A
end_define

begin_define
define|#
directive|define
name|RNDIS_OID_GEN_CO_MEDIA_CONNECT_STATUS
value|0x0001010B
end_define

begin_define
define|#
directive|define
name|RNDIS_OID_GEN_CO_VENDOR_DRIVER_VERSION
value|0x0001010C
end_define

begin_define
define|#
directive|define
name|RNDIS_OID_GEN_CO_MINIMUM_LINK_SPEED
value|0x0001010D
end_define

begin_define
define|#
directive|define
name|RNDIS_OID_GEN_CO_GET_TIME_CAPS
value|0x00010201
end_define

begin_define
define|#
directive|define
name|RNDIS_OID_GEN_CO_GET_NETCARD_TIME
value|0x00010202
end_define

begin_comment
comment|/*  * These are connection-oriented statistics OIDs.  */
end_comment

begin_define
define|#
directive|define
name|RNDIS_OID_GEN_CO_XMIT_PDUS_OK
value|0x00020101
end_define

begin_define
define|#
directive|define
name|RNDIS_OID_GEN_CO_RCV_PDUS_OK
value|0x00020102
end_define

begin_define
define|#
directive|define
name|RNDIS_OID_GEN_CO_XMIT_PDUS_ERROR
value|0x00020103
end_define

begin_define
define|#
directive|define
name|RNDIS_OID_GEN_CO_RCV_PDUS_ERROR
value|0x00020104
end_define

begin_define
define|#
directive|define
name|RNDIS_OID_GEN_CO_RCV_PDUS_NO_BUFFER
value|0x00020105
end_define

begin_define
define|#
directive|define
name|RNDIS_OID_GEN_CO_RCV_CRC_ERROR
value|0x00020201
end_define

begin_define
define|#
directive|define
name|RNDIS_OID_GEN_CO_TRANSMIT_QUEUE_LENGTH
value|0x00020202
end_define

begin_define
define|#
directive|define
name|RNDIS_OID_GEN_CO_BYTES_XMIT
value|0x00020203
end_define

begin_define
define|#
directive|define
name|RNDIS_OID_GEN_CO_BYTES_RCV
value|0x00020204
end_define

begin_define
define|#
directive|define
name|RNDIS_OID_GEN_CO_BYTES_XMIT_OUTSTANDING
value|0x00020205
end_define

begin_define
define|#
directive|define
name|RNDIS_OID_GEN_CO_NETCARD_LOAD
value|0x00020206
end_define

begin_comment
comment|/*  * These are objects for Connection-oriented media call-managers.  */
end_comment

begin_define
define|#
directive|define
name|RNDIS_OID_CO_ADD_PVC
value|0xFF000001
end_define

begin_define
define|#
directive|define
name|RNDIS_OID_CO_DELETE_PVC
value|0xFF000002
end_define

begin_define
define|#
directive|define
name|RNDIS_OID_CO_GET_CALL_INFORMATION
value|0xFF000003
end_define

begin_define
define|#
directive|define
name|RNDIS_OID_CO_ADD_ADDRESS
value|0xFF000004
end_define

begin_define
define|#
directive|define
name|RNDIS_OID_CO_DELETE_ADDRESS
value|0xFF000005
end_define

begin_define
define|#
directive|define
name|RNDIS_OID_CO_GET_ADDRESSES
value|0xFF000006
end_define

begin_define
define|#
directive|define
name|RNDIS_OID_CO_ADDRESS_CHANGE
value|0xFF000007
end_define

begin_define
define|#
directive|define
name|RNDIS_OID_CO_SIGNALING_ENABLED
value|0xFF000008
end_define

begin_define
define|#
directive|define
name|RNDIS_OID_CO_SIGNALING_DISABLED
value|0xFF000009
end_define

begin_comment
comment|/*  * 802.3 Objects (Ethernet)  */
end_comment

begin_define
define|#
directive|define
name|RNDIS_OID_802_3_PERMANENT_ADDRESS
value|0x01010101
end_define

begin_define
define|#
directive|define
name|RNDIS_OID_802_3_CURRENT_ADDRESS
value|0x01010102
end_define

begin_define
define|#
directive|define
name|RNDIS_OID_802_3_MULTICAST_LIST
value|0x01010103
end_define

begin_define
define|#
directive|define
name|RNDIS_OID_802_3_MAXIMUM_LIST_SIZE
value|0x01010104
end_define

begin_define
define|#
directive|define
name|RNDIS_OID_802_3_MAC_OPTIONS
value|0x01010105
end_define

begin_comment
comment|/*  *  */
end_comment

begin_define
define|#
directive|define
name|NDIS_802_3_MAC_OPTION_PRIORITY
value|0x00000001
end_define

begin_define
define|#
directive|define
name|RNDIS_OID_802_3_RCV_ERROR_ALIGNMENT
value|0x01020101
end_define

begin_define
define|#
directive|define
name|RNDIS_OID_802_3_XMIT_ONE_COLLISION
value|0x01020102
end_define

begin_define
define|#
directive|define
name|RNDIS_OID_802_3_XMIT_MORE_COLLISIONS
value|0x01020103
end_define

begin_define
define|#
directive|define
name|RNDIS_OID_802_3_XMIT_DEFERRED
value|0x01020201
end_define

begin_define
define|#
directive|define
name|RNDIS_OID_802_3_XMIT_MAX_COLLISIONS
value|0x01020202
end_define

begin_define
define|#
directive|define
name|RNDIS_OID_802_3_RCV_OVERRUN
value|0x01020203
end_define

begin_define
define|#
directive|define
name|RNDIS_OID_802_3_XMIT_UNDERRUN
value|0x01020204
end_define

begin_define
define|#
directive|define
name|RNDIS_OID_802_3_XMIT_HEARTBEAT_FAILURE
value|0x01020205
end_define

begin_define
define|#
directive|define
name|RNDIS_OID_802_3_XMIT_TIMES_CRS_LOST
value|0x01020206
end_define

begin_define
define|#
directive|define
name|RNDIS_OID_802_3_XMIT_LATE_COLLISIONS
value|0x01020207
end_define

begin_comment
comment|/*  * RNDIS MP custom OID for test  */
end_comment

begin_define
define|#
directive|define
name|OID_RNDISMP_GET_RECEIVE_BUFFERS
value|0xFFA0C90D
end_define

begin_comment
comment|// Query only
end_comment

begin_comment
comment|/*  * Remote NDIS offload parameters  */
end_comment

begin_define
define|#
directive|define
name|RNDIS_OBJECT_TYPE_DEFAULT
value|0x80
end_define

begin_define
define|#
directive|define
name|RNDIS_OFFLOAD_PARAMETERS_REVISION_3
value|3
end_define

begin_define
define|#
directive|define
name|RNDIS_OFFLOAD_PARAMETERS_NO_CHANGE
value|0
end_define

begin_define
define|#
directive|define
name|RNDIS_OFFLOAD_PARAMETERS_LSOV2_DISABLED
value|1
end_define

begin_define
define|#
directive|define
name|RNDIS_OFFLOAD_PARAMETERS_LSOV2_ENABLED
value|2
end_define

begin_define
define|#
directive|define
name|RNDIS_OFFLOAD_PARAMETERS_LSOV1_ENABLED
value|2
end_define

begin_define
define|#
directive|define
name|RNDIS_OFFLOAD_PARAMETERS_RSC_DISABLED
value|1
end_define

begin_define
define|#
directive|define
name|RNDIS_OFFLOAD_PARAMETERS_RSC_ENABLED
value|2
end_define

begin_define
define|#
directive|define
name|RNDIS_OFFLOAD_PARAMETERS_TX_RX_DISABLED
value|1
end_define

begin_define
define|#
directive|define
name|RNDIS_OFFLOAD_PARAMETERS_TX_ENABLED_RX_DISABLED
value|2
end_define

begin_define
define|#
directive|define
name|RNDIS_OFFLOAD_PARAMETERS_RX_ENABLED_TX_DISABLED
value|3
end_define

begin_define
define|#
directive|define
name|RNDIS_OFFLOAD_PARAMETERS_TX_RX_ENABLED
value|4
end_define

begin_define
define|#
directive|define
name|RNDIS_TCP_LARGE_SEND_OFFLOAD_V2_TYPE
value|1
end_define

begin_define
define|#
directive|define
name|RNDIS_TCP_LARGE_SEND_OFFLOAD_IPV4
value|0
end_define

begin_define
define|#
directive|define
name|RNDIS_TCP_LARGE_SEND_OFFLOAD_IPV6
value|1
end_define

begin_define
define|#
directive|define
name|RNDIS_OID_TCP_OFFLOAD_CURRENT_CONFIG
value|0xFC01020B
end_define

begin_comment
comment|/* query only */
end_comment

begin_define
define|#
directive|define
name|RNDIS_OID_TCP_OFFLOAD_PARAMETERS
value|0xFC01020C
end_define

begin_comment
comment|/* set only */
end_comment

begin_define
define|#
directive|define
name|RNDIS_OID_TCP_OFFLOAD_HARDWARE_CAPABILITIES
value|0xFC01020D
end_define

begin_comment
comment|/* query only */
end_comment

begin_define
define|#
directive|define
name|RNDIS_OID_TCP_CONNECTION_OFFLOAD_CURRENT_CONFIG
value|0xFC01020E
end_define

begin_comment
comment|/* query only */
end_comment

begin_define
define|#
directive|define
name|RNDIS_OID_TCP_CONNECTION_OFFLOAD_HARDWARE_CAPABILITIES
value|0xFC01020F
end_define

begin_comment
comment|/* query */
end_comment

begin_define
define|#
directive|define
name|RNDIS_OID_OFFLOAD_ENCAPSULATION
value|0x0101010A
end_define

begin_comment
comment|/* set/query */
end_comment

begin_comment
comment|/*  * NdisInitialize message  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|rndis_initialize_request_
block|{
comment|/* RNDIS request ID */
name|uint32_t
name|request_id
decl_stmt|;
name|uint32_t
name|major_version
decl_stmt|;
name|uint32_t
name|minor_version
decl_stmt|;
name|uint32_t
name|max_xfer_size
decl_stmt|;
block|}
name|rndis_initialize_request
typedef|;
end_typedef

begin_comment
comment|/*  * Response to NdisInitialize  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|rndis_initialize_complete_
block|{
comment|/* RNDIS request ID */
name|uint32_t
name|request_id
decl_stmt|;
comment|/* RNDIS status */
name|uint32_t
name|status
decl_stmt|;
name|uint32_t
name|major_version
decl_stmt|;
name|uint32_t
name|minor_version
decl_stmt|;
name|uint32_t
name|device_flags
decl_stmt|;
comment|/* RNDIS medium */
name|uint32_t
name|medium
decl_stmt|;
name|uint32_t
name|max_pkts_per_msg
decl_stmt|;
name|uint32_t
name|max_xfer_size
decl_stmt|;
name|uint32_t
name|pkt_align_factor
decl_stmt|;
name|uint32_t
name|af_list_offset
decl_stmt|;
name|uint32_t
name|af_list_size
decl_stmt|;
block|}
name|rndis_initialize_complete
typedef|;
end_typedef

begin_comment
comment|/*  * Call manager devices only: Information about an address family  * supported by the device is appended to the response to NdisInitialize.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|rndis_co_address_family_
block|{
comment|/* RNDIS AF */
name|uint32_t
name|address_family
decl_stmt|;
name|uint32_t
name|major_version
decl_stmt|;
name|uint32_t
name|minor_version
decl_stmt|;
block|}
name|rndis_co_address_family
typedef|;
end_typedef

begin_comment
comment|/*  * NdisHalt message  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|rndis_halt_request_
block|{
comment|/* RNDIS request ID */
name|uint32_t
name|request_id
decl_stmt|;
block|}
name|rndis_halt_request
typedef|;
end_typedef

begin_comment
comment|/*  * NdisQueryRequest message  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|rndis_query_request_
block|{
comment|/* RNDIS request ID */
name|uint32_t
name|request_id
decl_stmt|;
comment|/* RNDIS OID */
name|uint32_t
name|oid
decl_stmt|;
name|uint32_t
name|info_buffer_length
decl_stmt|;
name|uint32_t
name|info_buffer_offset
decl_stmt|;
comment|/* RNDIS handle */
name|uint32_t
name|device_vc_handle
decl_stmt|;
block|}
name|rndis_query_request
typedef|;
end_typedef

begin_comment
comment|/*  * Response to NdisQueryRequest  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|rndis_query_complete_
block|{
comment|/* RNDIS request ID */
name|uint32_t
name|request_id
decl_stmt|;
comment|/* RNDIS status */
name|uint32_t
name|status
decl_stmt|;
name|uint32_t
name|info_buffer_length
decl_stmt|;
name|uint32_t
name|info_buffer_offset
decl_stmt|;
block|}
name|rndis_query_complete
typedef|;
end_typedef

begin_comment
comment|/*  * NdisSetRequest message  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|rndis_set_request_
block|{
comment|/* RNDIS request ID */
name|uint32_t
name|request_id
decl_stmt|;
comment|/* RNDIS OID */
name|uint32_t
name|oid
decl_stmt|;
name|uint32_t
name|info_buffer_length
decl_stmt|;
name|uint32_t
name|info_buffer_offset
decl_stmt|;
comment|/* RNDIS handle */
name|uint32_t
name|device_vc_handle
decl_stmt|;
block|}
name|rndis_set_request
typedef|;
end_typedef

begin_comment
comment|/*  * Response to NdisSetRequest  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|rndis_set_complete_
block|{
comment|/* RNDIS request ID */
name|uint32_t
name|request_id
decl_stmt|;
comment|/* RNDIS status */
name|uint32_t
name|status
decl_stmt|;
block|}
name|rndis_set_complete
typedef|;
end_typedef

begin_comment
comment|/*  * NdisReset message  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|rndis_reset_request_
block|{
name|uint32_t
name|reserved
decl_stmt|;
block|}
name|rndis_reset_request
typedef|;
end_typedef

begin_comment
comment|/*  * Response to NdisReset  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|rndis_reset_complete_
block|{
comment|/* RNDIS status */
name|uint32_t
name|status
decl_stmt|;
name|uint32_t
name|addressing_reset
decl_stmt|;
block|}
name|rndis_reset_complete
typedef|;
end_typedef

begin_comment
comment|/*  * NdisMIndicateStatus message  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|rndis_indicate_status_
block|{
comment|/* RNDIS status */
name|uint32_t
name|status
decl_stmt|;
name|uint32_t
name|status_buf_length
decl_stmt|;
name|uint32_t
name|status_buf_offset
decl_stmt|;
block|}
name|rndis_indicate_status
typedef|;
end_typedef

begin_comment
comment|/*  * Diagnostic information passed as the status buffer in  * rndis_indicate_status messages signifying error conditions.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|rndis_diagnostic_info_
block|{
comment|/* RNDIS status */
name|uint32_t
name|diag_status
decl_stmt|;
name|uint32_t
name|error_offset
decl_stmt|;
block|}
name|rndis_diagnostic_info
typedef|;
end_typedef

begin_comment
comment|/*  * NdisKeepAlive message  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|rndis_keepalive_request_
block|{
comment|/* RNDIS request ID */
name|uint32_t
name|request_id
decl_stmt|;
block|}
name|rndis_keepalive_request
typedef|;
end_typedef

begin_comment
comment|/*  * Response to NdisKeepAlive  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|rndis_keepalive_complete_
block|{
comment|/* RNDIS request ID */
name|uint32_t
name|request_id
decl_stmt|;
comment|/* RNDIS status */
name|uint32_t
name|status
decl_stmt|;
block|}
name|rndis_keepalive_complete
typedef|;
end_typedef

begin_comment
comment|/*  * Data message. All offset fields contain byte offsets from the beginning  * of the rndis_packet structure. All length fields are in bytes.  * VcHandle is set to 0 for connectionless data, otherwise it  * contains the VC handle.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|rndis_packet_
block|{
name|uint32_t
name|data_offset
decl_stmt|;
name|uint32_t
name|data_length
decl_stmt|;
name|uint32_t
name|oob_data_offset
decl_stmt|;
name|uint32_t
name|oob_data_length
decl_stmt|;
name|uint32_t
name|num_oob_data_elements
decl_stmt|;
name|uint32_t
name|per_pkt_info_offset
decl_stmt|;
name|uint32_t
name|per_pkt_info_length
decl_stmt|;
comment|/* RNDIS handle */
name|uint32_t
name|vc_handle
decl_stmt|;
name|uint32_t
name|reserved
decl_stmt|;
block|}
name|rndis_packet
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|rndis_packet_ex_
block|{
name|uint32_t
name|data_offset
decl_stmt|;
name|uint32_t
name|data_length
decl_stmt|;
name|uint32_t
name|oob_data_offset
decl_stmt|;
name|uint32_t
name|oob_data_length
decl_stmt|;
name|uint32_t
name|num_oob_data_elements
decl_stmt|;
name|uint32_t
name|per_pkt_info_offset
decl_stmt|;
name|uint32_t
name|per_pkt_info_length
decl_stmt|;
comment|/* RNDIS handle */
name|uint32_t
name|vc_handle
decl_stmt|;
name|uint32_t
name|reserved
decl_stmt|;
name|uint64_t
name|data_buf_id
decl_stmt|;
name|uint32_t
name|data_buf_offset
decl_stmt|;
name|uint64_t
name|next_header_buf_id
decl_stmt|;
name|uint32_t
name|next_header_byte_offset
decl_stmt|;
name|uint32_t
name|next_header_byte_count
decl_stmt|;
block|}
name|rndis_packet_ex
typedef|;
end_typedef

begin_comment
comment|/*  * Optional Out of Band data associated with a Data message.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|rndis_oobd_
block|{
name|uint32_t
name|size
decl_stmt|;
comment|/* RNDIS class ID */
name|uint32_t
name|type
decl_stmt|;
name|uint32_t
name|class_info_offset
decl_stmt|;
block|}
name|rndis_oobd
typedef|;
end_typedef

begin_comment
comment|/*  * Packet extension field contents associated with a Data message.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|rndis_per_packet_info_
block|{
name|uint32_t
name|size
decl_stmt|;
name|uint32_t
name|type
decl_stmt|;
name|uint32_t
name|per_packet_info_offset
decl_stmt|;
block|}
name|rndis_per_packet_info
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
name|ndis_per_pkt_infotype_
block|{
name|tcpip_chksum_info
block|,
name|ipsec_info
block|,
name|tcp_large_send_info
block|,
name|classification_handle_info
block|,
name|ndis_reserved
block|,
name|sgl_info
block|,
name|ieee_8021q_info
block|,
name|original_pkt_info
block|,
name|pkt_cancel_id
block|,
name|original_netbuf_list
block|,
name|cached_netbuf_list
block|,
name|short_pkt_padding_info
block|,
name|max_perpkt_info
block|}
name|ndis_per_pkt_infotype
typedef|;
end_typedef

begin_define
define|#
directive|define
name|nbl_hash_value
value|pkt_cancel_id
end_define

begin_define
define|#
directive|define
name|nbl_hash_info
value|original_netbuf_list
end_define

begin_typedef
typedef|typedef
struct|struct
name|ndis_8021q_info_
block|{
union|union
block|{
struct|struct
block|{
name|uint32_t
name|user_pri
range|:
literal|3
decl_stmt|;
comment|/* User Priority */
name|uint32_t
name|cfi
range|:
literal|1
decl_stmt|;
comment|/* Canonical Format ID */
name|uint32_t
name|vlan_id
range|:
literal|12
decl_stmt|;
name|uint32_t
name|reserved
range|:
literal|16
decl_stmt|;
block|}
name|s1
struct|;
name|uint32_t
name|value
decl_stmt|;
block|}
name|u1
union|;
block|}
name|ndis_8021q_info
typedef|;
end_typedef

begin_struct
struct|struct
name|rndis_object_header
block|{
name|uint8_t
name|type
decl_stmt|;
name|uint8_t
name|revision
decl_stmt|;
name|uint16_t
name|size
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
struct|struct
name|rndis_offload_params_
block|{
name|struct
name|rndis_object_header
name|header
decl_stmt|;
name|uint8_t
name|ipv4_csum
decl_stmt|;
name|uint8_t
name|tcp_ipv4_csum
decl_stmt|;
name|uint8_t
name|udp_ipv4_csum
decl_stmt|;
name|uint8_t
name|tcp_ipv6_csum
decl_stmt|;
name|uint8_t
name|udp_ipv6_csum
decl_stmt|;
name|uint8_t
name|lso_v1
decl_stmt|;
name|uint8_t
name|ip_sec_v1
decl_stmt|;
name|uint8_t
name|lso_v2_ipv4
decl_stmt|;
name|uint8_t
name|lso_v2_ipv6
decl_stmt|;
name|uint8_t
name|tcp_connection_ipv4
decl_stmt|;
name|uint8_t
name|tcp_connection_ipv6
decl_stmt|;
name|uint32_t
name|flags
decl_stmt|;
name|uint8_t
name|ip_sec_v2
decl_stmt|;
name|uint8_t
name|ip_sec_v2_ipv4
decl_stmt|;
struct|struct
block|{
name|uint8_t
name|rsc_ipv4
decl_stmt|;
name|uint8_t
name|rsc_ipv6
decl_stmt|;
block|}
struct|;
struct|struct
block|{
name|uint8_t
name|encapsulated_packet_task_offload
decl_stmt|;
name|uint8_t
name|encapsulation_types
decl_stmt|;
block|}
struct|;
block|}
name|rndis_offload_params
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|rndis_tcp_ip_csum_info_
block|{
union|union
block|{
struct|struct
block|{
name|uint32_t
name|is_ipv4
range|:
literal|1
decl_stmt|;
name|uint32_t
name|is_ipv6
range|:
literal|1
decl_stmt|;
name|uint32_t
name|tcp_csum
range|:
literal|1
decl_stmt|;
name|uint32_t
name|udp_csum
range|:
literal|1
decl_stmt|;
name|uint32_t
name|ip_header_csum
range|:
literal|1
decl_stmt|;
name|uint32_t
name|reserved
range|:
literal|11
decl_stmt|;
name|uint32_t
name|tcp_header_offset
range|:
literal|10
decl_stmt|;
block|}
name|xmit
struct|;
struct|struct
block|{
name|uint32_t
name|tcp_csum_failed
range|:
literal|1
decl_stmt|;
name|uint32_t
name|udp_csum_failed
range|:
literal|1
decl_stmt|;
name|uint32_t
name|ip_csum_failed
range|:
literal|1
decl_stmt|;
name|uint32_t
name|tcp_csum_succeeded
range|:
literal|1
decl_stmt|;
name|uint32_t
name|udp_csum_succeeded
range|:
literal|1
decl_stmt|;
name|uint32_t
name|ip_csum_succeeded
range|:
literal|1
decl_stmt|;
name|uint32_t
name|loopback
range|:
literal|1
decl_stmt|;
name|uint32_t
name|tcp_csum_value_invalid
range|:
literal|1
decl_stmt|;
name|uint32_t
name|ip_csum_value_invalid
range|:
literal|1
decl_stmt|;
block|}
name|receive
struct|;
name|uint32_t
name|value
decl_stmt|;
block|}
union|;
block|}
name|rndis_tcp_ip_csum_info
typedef|;
end_typedef

begin_struct
struct|struct
name|rndis_hash_value
block|{
name|uint32_t
name|hash_value
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|rndis_hash_info
block|{
name|uint32_t
name|hash_info
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|NDIS_HASH_FUNCTION_MASK
value|0x000000FF
end_define

begin_comment
comment|/* see hash function */
end_comment

begin_define
define|#
directive|define
name|NDIS_HASH_TYPE_MASK
value|0x00FFFF00
end_define

begin_comment
comment|/* see hash type */
end_comment

begin_comment
comment|/* hash function */
end_comment

begin_define
define|#
directive|define
name|NDIS_HASH_FUNCTION_TOEPLITZ
value|0x00000001
end_define

begin_comment
comment|/* hash type */
end_comment

begin_define
define|#
directive|define
name|NDIS_HASH_IPV4
value|0x00000100
end_define

begin_define
define|#
directive|define
name|NDIS_HASH_TCP_IPV4
value|0x00000200
end_define

begin_define
define|#
directive|define
name|NDIS_HASH_IPV6
value|0x00000400
end_define

begin_define
define|#
directive|define
name|NDIS_HASH_IPV6_EX
value|0x00000800
end_define

begin_define
define|#
directive|define
name|NDIS_HASH_TCP_IPV6
value|0x00001000
end_define

begin_define
define|#
directive|define
name|NDIS_HASH_TCP_IPV6_EX
value|0x00002000
end_define

begin_typedef
typedef|typedef
struct|struct
name|rndis_tcp_tso_info_
block|{
union|union
block|{
struct|struct
block|{
name|uint32_t
name|unused
range|:
literal|30
decl_stmt|;
name|uint32_t
name|type
range|:
literal|1
decl_stmt|;
name|uint32_t
name|reserved2
range|:
literal|1
decl_stmt|;
block|}
name|xmit
struct|;
struct|struct
block|{
name|uint32_t
name|mss
range|:
literal|20
decl_stmt|;
name|uint32_t
name|tcp_header_offset
range|:
literal|10
decl_stmt|;
name|uint32_t
name|type
range|:
literal|1
decl_stmt|;
name|uint32_t
name|reserved2
range|:
literal|1
decl_stmt|;
block|}
name|lso_v1_xmit
struct|;
struct|struct
block|{
name|uint32_t
name|tcp_payload
range|:
literal|30
decl_stmt|;
name|uint32_t
name|type
range|:
literal|1
decl_stmt|;
name|uint32_t
name|reserved2
range|:
literal|1
decl_stmt|;
block|}
name|lso_v1_xmit_complete
struct|;
struct|struct
block|{
name|uint32_t
name|mss
range|:
literal|20
decl_stmt|;
name|uint32_t
name|tcp_header_offset
range|:
literal|10
decl_stmt|;
name|uint32_t
name|type
range|:
literal|1
decl_stmt|;
name|uint32_t
name|ip_version
range|:
literal|1
decl_stmt|;
block|}
name|lso_v2_xmit
struct|;
struct|struct
block|{
name|uint32_t
name|reserved
range|:
literal|30
decl_stmt|;
name|uint32_t
name|type
range|:
literal|1
decl_stmt|;
name|uint32_t
name|reserved2
range|:
literal|1
decl_stmt|;
block|}
name|lso_v2_xmit_complete
struct|;
name|uint32_t
name|value
decl_stmt|;
block|}
union|;
block|}
name|rndis_tcp_tso_info
typedef|;
end_typedef

begin_define
define|#
directive|define
name|RNDIS_HASHVAL_PPI_SIZE
value|(sizeof(rndis_per_packet_info) + \ 				sizeof(struct rndis_hash_value))
end_define

begin_define
define|#
directive|define
name|RNDIS_VLAN_PPI_SIZE
value|(sizeof(rndis_per_packet_info) + \ 				sizeof(ndis_8021q_info))
end_define

begin_define
define|#
directive|define
name|RNDIS_CSUM_PPI_SIZE
value|(sizeof(rndis_per_packet_info) + \ 				sizeof(rndis_tcp_ip_csum_info))
end_define

begin_define
define|#
directive|define
name|RNDIS_TSO_PPI_SIZE
value|(sizeof(rndis_per_packet_info) + \ 				sizeof(rndis_tcp_tso_info))
end_define

begin_comment
comment|/*  * Format of Information buffer passed in a SetRequest for the OID  * OID_GEN_RNDIS_CONFIG_PARAMETER.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|rndis_config_parameter_info_
block|{
name|uint32_t
name|parameter_name_offset
decl_stmt|;
name|uint32_t
name|parameter_name_length
decl_stmt|;
name|uint32_t
name|parameter_type
decl_stmt|;
name|uint32_t
name|parameter_value_offset
decl_stmt|;
name|uint32_t
name|parameter_value_length
decl_stmt|;
block|}
name|rndis_config_parameter_info
typedef|;
end_typedef

begin_comment
comment|/*  * Values for ParameterType in rndis_config_parameter_info  */
end_comment

begin_define
define|#
directive|define
name|RNDIS_CONFIG_PARAM_TYPE_INTEGER
value|0
end_define

begin_define
define|#
directive|define
name|RNDIS_CONFIG_PARAM_TYPE_STRING
value|2
end_define

begin_comment
comment|/*  * CONDIS Miniport messages for connection oriented devices  * that do not implement a call manager.  */
end_comment

begin_comment
comment|/*  * CoNdisMiniportCreateVc message  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|rcondis_mp_create_vc_
block|{
comment|/* RNDIS request ID */
name|uint32_t
name|request_id
decl_stmt|;
comment|/* RNDIS handle */
name|uint32_t
name|ndis_vc_handle
decl_stmt|;
block|}
name|rcondis_mp_create_vc
typedef|;
end_typedef

begin_comment
comment|/*  * Response to CoNdisMiniportCreateVc  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|rcondis_mp_create_vc_complete_
block|{
comment|/* RNDIS request ID */
name|uint32_t
name|request_id
decl_stmt|;
comment|/* RNDIS handle */
name|uint32_t
name|device_vc_handle
decl_stmt|;
comment|/* RNDIS status */
name|uint32_t
name|status
decl_stmt|;
block|}
name|rcondis_mp_create_vc_complete
typedef|;
end_typedef

begin_comment
comment|/*  * CoNdisMiniportDeleteVc message  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|rcondis_mp_delete_vc_
block|{
comment|/* RNDIS request ID */
name|uint32_t
name|request_id
decl_stmt|;
comment|/* RNDIS handle */
name|uint32_t
name|device_vc_handle
decl_stmt|;
block|}
name|rcondis_mp_delete_vc
typedef|;
end_typedef

begin_comment
comment|/*  * Response to CoNdisMiniportDeleteVc  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|rcondis_mp_delete_vc_complete_
block|{
comment|/* RNDIS request ID */
name|uint32_t
name|request_id
decl_stmt|;
comment|/* RNDIS status */
name|uint32_t
name|status
decl_stmt|;
block|}
name|rcondis_mp_delete_vc_complete
typedef|;
end_typedef

begin_comment
comment|/*  * CoNdisMiniportQueryRequest message  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|rcondis_mp_query_request_
block|{
comment|/* RNDIS request ID */
name|uint32_t
name|request_id
decl_stmt|;
comment|/* RNDIS request type */
name|uint32_t
name|request_type
decl_stmt|;
comment|/* RNDIS OID */
name|uint32_t
name|oid
decl_stmt|;
comment|/* RNDIS handle */
name|uint32_t
name|device_vc_handle
decl_stmt|;
name|uint32_t
name|info_buf_length
decl_stmt|;
name|uint32_t
name|info_buf_offset
decl_stmt|;
block|}
name|rcondis_mp_query_request
typedef|;
end_typedef

begin_comment
comment|/*  * CoNdisMiniportSetRequest message  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|rcondis_mp_set_request_
block|{
comment|/* RNDIS request ID */
name|uint32_t
name|request_id
decl_stmt|;
comment|/* RNDIS request type */
name|uint32_t
name|request_type
decl_stmt|;
comment|/* RNDIS OID */
name|uint32_t
name|oid
decl_stmt|;
comment|/* RNDIS handle */
name|uint32_t
name|device_vc_handle
decl_stmt|;
name|uint32_t
name|info_buf_length
decl_stmt|;
name|uint32_t
name|info_buf_offset
decl_stmt|;
block|}
name|rcondis_mp_set_request
typedef|;
end_typedef

begin_comment
comment|/*  * CoNdisIndicateStatus message  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|rcondis_indicate_status_
block|{
comment|/* RNDIS handle */
name|uint32_t
name|ndis_vc_handle
decl_stmt|;
comment|/* RNDIS status */
name|uint32_t
name|status
decl_stmt|;
name|uint32_t
name|status_buf_length
decl_stmt|;
name|uint32_t
name|status_buf_offset
decl_stmt|;
block|}
name|rcondis_indicate_status
typedef|;
end_typedef

begin_comment
comment|/*  * CONDIS Call/VC parameters  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|rcondis_specific_parameters_
block|{
name|uint32_t
name|parameter_type
decl_stmt|;
name|uint32_t
name|parameter_length
decl_stmt|;
name|uint32_t
name|parameter_offset
decl_stmt|;
block|}
name|rcondis_specific_parameters
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|rcondis_media_parameters_
block|{
name|uint32_t
name|flags
decl_stmt|;
name|uint32_t
name|reserved1
decl_stmt|;
name|uint32_t
name|reserved2
decl_stmt|;
name|rcondis_specific_parameters
name|media_specific
decl_stmt|;
block|}
name|rcondis_media_parameters
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|rndis_flowspec_
block|{
name|uint32_t
name|token_rate
decl_stmt|;
name|uint32_t
name|token_bucket_size
decl_stmt|;
name|uint32_t
name|peak_bandwidth
decl_stmt|;
name|uint32_t
name|latency
decl_stmt|;
name|uint32_t
name|delay_variation
decl_stmt|;
name|uint32_t
name|service_type
decl_stmt|;
name|uint32_t
name|max_sdu_size
decl_stmt|;
name|uint32_t
name|minimum_policed_size
decl_stmt|;
block|}
name|rndis_flowspec
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|rcondis_call_manager_parameters_
block|{
name|rndis_flowspec
name|transmit
decl_stmt|;
name|rndis_flowspec
name|receive
decl_stmt|;
name|rcondis_specific_parameters
name|call_mgr_specific
decl_stmt|;
block|}
name|rcondis_call_manager_parameters
typedef|;
end_typedef

begin_comment
comment|/*  * CoNdisMiniportActivateVc message  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|rcondis_mp_activate_vc_request_
block|{
comment|/* RNDIS request ID */
name|uint32_t
name|request_id
decl_stmt|;
name|uint32_t
name|flags
decl_stmt|;
comment|/* RNDIS handle */
name|uint32_t
name|device_vc_handle
decl_stmt|;
name|uint32_t
name|media_params_offset
decl_stmt|;
name|uint32_t
name|media_params_length
decl_stmt|;
name|uint32_t
name|call_mgr_params_offset
decl_stmt|;
name|uint32_t
name|call_mgr_params_length
decl_stmt|;
block|}
name|rcondis_mp_activate_vc_request
typedef|;
end_typedef

begin_comment
comment|/*  * Response to CoNdisMiniportActivateVc  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|rcondis_mp_activate_vc_complete_
block|{
comment|/* RNDIS request ID */
name|uint32_t
name|request_id
decl_stmt|;
comment|/* RNDIS status */
name|uint32_t
name|status
decl_stmt|;
block|}
name|rcondis_mp_activate_vc_complete
typedef|;
end_typedef

begin_comment
comment|/*  * CoNdisMiniportDeactivateVc message  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|rcondis_mp_deactivate_vc_request_
block|{
comment|/* RNDIS request ID */
name|uint32_t
name|request_id
decl_stmt|;
name|uint32_t
name|flags
decl_stmt|;
comment|/* RNDIS handle */
name|uint32_t
name|device_vc_handle
decl_stmt|;
block|}
name|rcondis_mp_deactivate_vc_request
typedef|;
end_typedef

begin_comment
comment|/*  * Response to CoNdisMiniportDeactivateVc  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|rcondis_mp_deactivate_vc_complete_
block|{
comment|/* RNDIS request ID */
name|uint32_t
name|request_id
decl_stmt|;
comment|/* RNDIS status */
name|uint32_t
name|status
decl_stmt|;
block|}
name|rcondis_mp_deactivate_vc_complete
typedef|;
end_typedef

begin_comment
comment|/*  * union with all of the RNDIS messages  */
end_comment

begin_typedef
typedef|typedef
union|union
name|rndis_msg_container_
block|{
name|rndis_packet
name|packet
decl_stmt|;
name|rndis_initialize_request
name|init_request
decl_stmt|;
name|rndis_halt_request
name|halt_request
decl_stmt|;
name|rndis_query_request
name|query_request
decl_stmt|;
name|rndis_set_request
name|set_request
decl_stmt|;
name|rndis_reset_request
name|reset_request
decl_stmt|;
name|rndis_keepalive_request
name|keepalive_request
decl_stmt|;
name|rndis_indicate_status
name|indicate_status
decl_stmt|;
name|rndis_initialize_complete
name|init_complete
decl_stmt|;
name|rndis_query_complete
name|query_complete
decl_stmt|;
name|rndis_set_complete
name|set_complete
decl_stmt|;
name|rndis_reset_complete
name|reset_complete
decl_stmt|;
name|rndis_keepalive_complete
name|keepalive_complete
decl_stmt|;
name|rcondis_mp_create_vc
name|co_miniport_create_vc
decl_stmt|;
name|rcondis_mp_delete_vc
name|co_miniport_delete_vc
decl_stmt|;
name|rcondis_indicate_status
name|co_miniport_status
decl_stmt|;
name|rcondis_mp_activate_vc_request
name|co_miniport_activate_vc
decl_stmt|;
name|rcondis_mp_deactivate_vc_request
name|co_miniport_deactivate_vc
decl_stmt|;
name|rcondis_mp_create_vc_complete
name|co_miniport_create_vc_complete
decl_stmt|;
name|rcondis_mp_delete_vc_complete
name|co_miniport_delete_vc_complete
decl_stmt|;
name|rcondis_mp_activate_vc_complete
name|co_miniport_activate_vc_complete
decl_stmt|;
name|rcondis_mp_deactivate_vc_complete
name|co_miniport_deactivate_vc_complete
decl_stmt|;
name|rndis_packet_ex
name|packet_ex
decl_stmt|;
block|}
name|rndis_msg_container
typedef|;
end_typedef

begin_comment
comment|/*  * Remote NDIS message format  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|rndis_msg_
block|{
name|uint32_t
name|ndis_msg_type
decl_stmt|;
comment|/*      * Total length of this message, from the beginning      * of the rndis_msg struct, in bytes.      */
name|uint32_t
name|msg_len
decl_stmt|;
comment|/* Actual message */
name|rndis_msg_container
name|msg
decl_stmt|;
block|}
name|rndis_msg
typedef|;
end_typedef

begin_comment
comment|/*  * Handy macros  */
end_comment

begin_comment
comment|/*  * get the size of an RNDIS message. Pass in the message type,   * rndis_set_request, rndis_packet for example  */
end_comment

begin_define
define|#
directive|define
name|RNDIS_MESSAGE_SIZE
parameter_list|(
name|message
parameter_list|)
define|\
value|(sizeof(message) + (sizeof(rndis_msg) - sizeof(rndis_msg_container)))
end_define

begin_comment
comment|/*  * get pointer to info buffer with message pointer  */
end_comment

begin_define
define|#
directive|define
name|MESSAGE_TO_INFO_BUFFER
parameter_list|(
name|message
parameter_list|)
define|\
value|(((PUCHAR)(message)) + message->InformationBufferOffset)
end_define

begin_comment
comment|/*  * get pointer to status buffer with message pointer  */
end_comment

begin_define
define|#
directive|define
name|MESSAGE_TO_STATUS_BUFFER
parameter_list|(
name|message
parameter_list|)
define|\
value|(((PUCHAR)(message)) + message->StatusBufferOffset)
end_define

begin_comment
comment|/*  * get pointer to OOBD buffer with message pointer  */
end_comment

begin_define
define|#
directive|define
name|MESSAGE_TO_OOBD_BUFFER
parameter_list|(
name|message
parameter_list|)
define|\
value|(((PUCHAR)(message)) + message->OOBDataOffset)
end_define

begin_comment
comment|/*  * get pointer to data buffer with message pointer  */
end_comment

begin_define
define|#
directive|define
name|MESSAGE_TO_DATA_BUFFER
parameter_list|(
name|message
parameter_list|)
define|\
value|(((PUCHAR)(message)) + message->PerPacketInfoOffset)
end_define

begin_comment
comment|/*  * get pointer to contained message from NDIS_MESSAGE pointer  */
end_comment

begin_define
define|#
directive|define
name|RNDIS_MESSAGE_PTR_TO_MESSAGE_PTR
parameter_list|(
name|rndis_message
parameter_list|)
define|\
value|((void *)&rndis_message->Message)
end_define

begin_comment
comment|/*  * get pointer to contained message from NDIS_MESSAGE pointer  */
end_comment

begin_define
define|#
directive|define
name|RNDIS_MESSAGE_RAW_PTR_TO_MESSAGE_PTR
parameter_list|(
name|rndis_message
parameter_list|)
define|\
value|((void *) rndis_message)
end_define

begin_comment
comment|/*  * Structures used in OID_RNDISMP_GET_RECEIVE_BUFFERS  */
end_comment

begin_define
define|#
directive|define
name|RNDISMP_RECEIVE_BUFFER_ELEM_FLAG_VMQ_RECEIVE_BUFFER
value|0x00000001
end_define

begin_typedef
typedef|typedef
struct|struct
name|rndismp_rx_buf_elem_
block|{
name|uint32_t
name|flags
decl_stmt|;
name|uint32_t
name|length
decl_stmt|;
name|uint64_t
name|rx_buf_id
decl_stmt|;
name|uint32_t
name|gpadl_handle
decl_stmt|;
name|void
modifier|*
name|rx_buf
decl_stmt|;
block|}
name|rndismp_rx_buf_elem
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|rndismp_rx_bufs_info_
block|{
name|uint32_t
name|num_rx_bufs
decl_stmt|;
name|rndismp_rx_buf_elem
name|rx_buf_elems
index|[
literal|1
index|]
decl_stmt|;
block|}
name|rndismp_rx_bufs_info
typedef|;
end_typedef

begin_define
define|#
directive|define
name|RNDIS_HEADER_SIZE
value|(sizeof(rndis_msg) - sizeof(rndis_msg_container))
end_define

begin_define
define|#
directive|define
name|NDIS_PACKET_TYPE_DIRECTED
value|0x00000001
end_define

begin_define
define|#
directive|define
name|NDIS_PACKET_TYPE_MULTICAST
value|0x00000002
end_define

begin_define
define|#
directive|define
name|NDIS_PACKET_TYPE_ALL_MULTICAST
value|0x00000004
end_define

begin_define
define|#
directive|define
name|NDIS_PACKET_TYPE_BROADCAST
value|0x00000008
end_define

begin_define
define|#
directive|define
name|NDIS_PACKET_TYPE_SOURCE_ROUTING
value|0x00000010
end_define

begin_define
define|#
directive|define
name|NDIS_PACKET_TYPE_PROMISCUOUS
value|0x00000020
end_define

begin_define
define|#
directive|define
name|NDIS_PACKET_TYPE_SMT
value|0x00000040
end_define

begin_define
define|#
directive|define
name|NDIS_PACKET_TYPE_ALL_LOCAL
value|0x00000080
end_define

begin_define
define|#
directive|define
name|NDIS_PACKET_TYPE_GROUP
value|0x00000100
end_define

begin_define
define|#
directive|define
name|NDIS_PACKET_TYPE_ALL_FUNCTIONAL
value|0x00000200
end_define

begin_define
define|#
directive|define
name|NDIS_PACKET_TYPE_FUNCTIONAL
value|0x00000400
end_define

begin_define
define|#
directive|define
name|NDIS_PACKET_TYPE_MAC_FRAME
value|0x00000800
end_define

begin_comment
comment|/*  * Externs  */
end_comment

begin_struct_decl
struct_decl|struct
name|hn_rx_ring
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|hn_tx_ring
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|hn_recvinfo
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|netvsc_recv
parameter_list|(
name|struct
name|hn_rx_ring
modifier|*
name|rxr
parameter_list|,
specifier|const
name|void
modifier|*
name|data
parameter_list|,
name|int
name|dlen
parameter_list|,
specifier|const
name|struct
name|hn_recvinfo
modifier|*
name|info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|netvsc_channel_rollup
parameter_list|(
name|struct
name|hn_rx_ring
modifier|*
name|rxr
parameter_list|,
name|struct
name|hn_tx_ring
modifier|*
name|txr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|hv_set_rppi_data
parameter_list|(
name|rndis_msg
modifier|*
name|rndis_mesg
parameter_list|,
name|uint32_t
name|rppi_size
parameter_list|,
name|int
name|pkt_type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|hv_get_ppi_data
parameter_list|(
name|rndis_packet
modifier|*
name|rpkt
parameter_list|,
name|uint32_t
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __HV_RNDIS_H__ */
end_comment

end_unit

