begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * sdp.h  *  * Copyright (c) 2001-2003 Maksim Yevmenkin<m_evmenkin@yahoo.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Id: sdp.h,v 1.3 2003/09/05 00:33:59 max Exp $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SDP_H_
end_ifndef

begin_define
define|#
directive|define
name|_SDP_H_
end_define

begin_macro
name|__BEGIN_DECLS
end_macro

begin_comment
comment|/*  * Data representation (page 349)  */
end_comment

begin_comment
comment|/* Nil, the null type */
end_comment

begin_define
define|#
directive|define
name|SDP_DATA_NIL
value|0x00
end_define

begin_comment
comment|/* Unsigned integer */
end_comment

begin_define
define|#
directive|define
name|SDP_DATA_UINT8
value|0x08
end_define

begin_define
define|#
directive|define
name|SDP_DATA_UINT16
value|0x09
end_define

begin_define
define|#
directive|define
name|SDP_DATA_UINT32
value|0x0A
end_define

begin_define
define|#
directive|define
name|SDP_DATA_UINT64
value|0x0B
end_define

begin_define
define|#
directive|define
name|SDP_DATA_UINT128
value|0x0C
end_define

begin_comment
comment|/* Signed two's-complement integer */
end_comment

begin_define
define|#
directive|define
name|SDP_DATA_INT8
value|0x10
end_define

begin_define
define|#
directive|define
name|SDP_DATA_INT16
value|0x11
end_define

begin_define
define|#
directive|define
name|SDP_DATA_INT32
value|0x12
end_define

begin_define
define|#
directive|define
name|SDP_DATA_INT64
value|0x13
end_define

begin_define
define|#
directive|define
name|SDP_DATA_INT128
value|0x14
end_define

begin_comment
comment|/* UUID, a universally unique identifier */
end_comment

begin_define
define|#
directive|define
name|SDP_DATA_UUID16
value|0x19
end_define

begin_define
define|#
directive|define
name|SDP_DATA_UUID32
value|0x1A
end_define

begin_define
define|#
directive|define
name|SDP_DATA_UUID128
value|0x1C
end_define

begin_comment
comment|/* Text string */
end_comment

begin_define
define|#
directive|define
name|SDP_DATA_STR8
value|0x25
end_define

begin_define
define|#
directive|define
name|SDP_DATA_STR16
value|0x26
end_define

begin_define
define|#
directive|define
name|SDP_DATA_STR32
value|0x27
end_define

begin_comment
comment|/* Boolean */
end_comment

begin_define
define|#
directive|define
name|SDP_DATA_BOOL
value|0x28
end_define

begin_comment
comment|/*   * Data element sequence.  * A data element whose data field is a sequence of data elements  */
end_comment

begin_define
define|#
directive|define
name|SDP_DATA_SEQ8
value|0x35
end_define

begin_define
define|#
directive|define
name|SDP_DATA_SEQ16
value|0x36
end_define

begin_define
define|#
directive|define
name|SDP_DATA_SEQ32
value|0x37
end_define

begin_comment
comment|/*  * Data element alternative.  * A data element whose data field is a sequence of data elements from   * which one data element is to be selected.  */
end_comment

begin_define
define|#
directive|define
name|SDP_DATA_ALT8
value|0x3D
end_define

begin_define
define|#
directive|define
name|SDP_DATA_ALT16
value|0x3E
end_define

begin_define
define|#
directive|define
name|SDP_DATA_ALT32
value|0x3F
end_define

begin_comment
comment|/* URL, a uniform resource locator */
end_comment

begin_define
define|#
directive|define
name|SDP_DATA_URL8
value|0x45
end_define

begin_define
define|#
directive|define
name|SDP_DATA_URL16
value|0x46
end_define

begin_define
define|#
directive|define
name|SDP_DATA_URL32
value|0x47
end_define

begin_comment
comment|/*  * Protocols UUID (short) http://www.bluetoothsig.org/assigned-numbers/sdp.htm  * BASE UUID 00000000-0000-1000-8000-00805F9B34FB  */
end_comment

begin_define
define|#
directive|define
name|SDP_UUID_PROTOCOL_SDP
value|0x0001
end_define

begin_define
define|#
directive|define
name|SDP_UUID_PROTOCOL_UDP
value|0x0002
end_define

begin_define
define|#
directive|define
name|SDP_UUID_PROTOCOL_RFCOMM
value|0x0003
end_define

begin_define
define|#
directive|define
name|SDP_UUID_PROTOCOL_TCP
value|0x0004
end_define

begin_define
define|#
directive|define
name|SDP_UUID_PROTOCOL_TCS_BIN
value|0x0005
end_define

begin_define
define|#
directive|define
name|SDP_UUID_PROTOCOL_TCS_AT
value|0x0006
end_define

begin_define
define|#
directive|define
name|SDP_UUID_PROTOCOL_OBEX
value|0x0008
end_define

begin_define
define|#
directive|define
name|SDP_UUID_PROTOCOL_IP
value|0x0009
end_define

begin_define
define|#
directive|define
name|SDP_UUID_PROTOCOL_FTP
value|0x000A
end_define

begin_define
define|#
directive|define
name|SDP_UUID_PROTOCOL_HTTP
value|0x000C
end_define

begin_define
define|#
directive|define
name|SDP_UUID_PROTOCOL_WSP
value|0x000E
end_define

begin_define
define|#
directive|define
name|SDP_UUID_PROTOCOL_BNEP
value|0x000F
end_define

begin_define
define|#
directive|define
name|SDP_UUID_PROTOCOL_UPNP
value|0x0010
end_define

begin_define
define|#
directive|define
name|SDP_UUID_PROTOCOL_HIDP
value|0x0011
end_define

begin_define
define|#
directive|define
name|SDP_UUID_PROTOCOL_HARDCOPY_CONTROL_CHANNEL
value|0x0012
end_define

begin_define
define|#
directive|define
name|SDP_UUID_PROTOCOL_HARDCOPY_DATA_CHANNEL
value|0x0014
end_define

begin_define
define|#
directive|define
name|SDP_UUID_PROTOCOL_HARDCOPY_NOTIFICATION
value|0x0016
end_define

begin_define
define|#
directive|define
name|SDP_UUID_PROTOCOL_AVCTP
value|0x0017
end_define

begin_define
define|#
directive|define
name|SDP_UUID_PROTOCOL_AVDTP
value|0x0019
end_define

begin_define
define|#
directive|define
name|SDP_UUID_PROTOCOL_CMPT
value|0x001B
end_define

begin_define
define|#
directive|define
name|SDP_UUID_PROTOCOL_UDI_C_PLANE
value|0x001D
end_define

begin_define
define|#
directive|define
name|SDP_UUID_PROTOCOL_L2CAP
value|0x0100
end_define

begin_comment
comment|/*  * Service class IDs http://www.bluetoothsig.org/assigned-numbers/sdp.htm  */
end_comment

begin_define
define|#
directive|define
name|SDP_SERVICE_CLASS_SERVICE_DISCOVERY_SERVER
value|0x1000
end_define

begin_define
define|#
directive|define
name|SDP_SERVICE_CLASS_BROWSE_GROUP_DESCRIPTOR
value|0x1001
end_define

begin_define
define|#
directive|define
name|SDP_SERVICE_CLASS_PUBLIC_BROWSE_GROUP
value|0x1002
end_define

begin_define
define|#
directive|define
name|SDP_SERVICE_CLASS_SERIAL_PORT
value|0x1101
end_define

begin_define
define|#
directive|define
name|SDP_SERVICE_CLASS_LAN_ACCESS_USING_PPP
value|0x1102
end_define

begin_define
define|#
directive|define
name|SDP_SERVICE_CLASS_DIALUP_NETWORKING
value|0x1103
end_define

begin_define
define|#
directive|define
name|SDP_SERVICE_CLASS_IR_MC_SYNC
value|0x1104
end_define

begin_define
define|#
directive|define
name|SDP_SERVICE_CLASS_OBEX_OBJECT_PUSH
value|0x1105
end_define

begin_define
define|#
directive|define
name|SDP_SERVICE_CLASS_OBEX_FILE_TRANSFER
value|0x1106
end_define

begin_define
define|#
directive|define
name|SDP_SERVICE_CLASS_IR_MC_SYNC_COMMAND
value|0x1107
end_define

begin_define
define|#
directive|define
name|SDP_SERVICE_CLASS_HEADSET
value|0x1108
end_define

begin_define
define|#
directive|define
name|SDP_SERVICE_CLASS_CORDLESS_TELEPHONY
value|0x1109
end_define

begin_define
define|#
directive|define
name|SDP_SERVICE_CLASS_AUDIO_SOURCE
value|0x110A
end_define

begin_define
define|#
directive|define
name|SDP_SERVICE_CLASS_AUDIO_SINK
value|0x110B
end_define

begin_define
define|#
directive|define
name|SDP_SERVICE_CLASS_AV_REMOTE_CONTROL_TARGET
value|0x110C
end_define

begin_define
define|#
directive|define
name|SDP_SERVICE_CLASS_ADVANCED_AUDIO_DISTRIBUTION
value|0x110D
end_define

begin_define
define|#
directive|define
name|SDP_SERVICE_CLASS_AV_REMOTE_CONTROL
value|0x110E
end_define

begin_define
define|#
directive|define
name|SDP_SERVICE_CLASS_VIDEO_CONFERENCING
value|0x110F
end_define

begin_define
define|#
directive|define
name|SDP_SERVICE_CLASS_INTERCOM
value|0x1110
end_define

begin_define
define|#
directive|define
name|SDP_SERVICE_CLASS_FAX
value|0x1111
end_define

begin_define
define|#
directive|define
name|SDP_SERVICE_CLASS_HEADSET_AUDIO_GATEWAY
value|0x1112
end_define

begin_define
define|#
directive|define
name|SDP_SERVICE_CLASS_WAP
value|0x1113
end_define

begin_define
define|#
directive|define
name|SDP_SERVICE_CLASS_WAP_CLIENT
value|0x1114
end_define

begin_define
define|#
directive|define
name|SDP_SERVICE_CLASS_PANU
value|0x1115
end_define

begin_define
define|#
directive|define
name|SDP_SERVICE_CLASS_NAP
value|0x1116
end_define

begin_define
define|#
directive|define
name|SDP_SERVICE_CLASS_GN
value|0x1117
end_define

begin_define
define|#
directive|define
name|SDP_SERVICE_CLASS_DIRECT_PRINTING
value|0x1118
end_define

begin_define
define|#
directive|define
name|SDP_SERVICE_CLASS_REFERENCE_PRINTING
value|0x1119
end_define

begin_define
define|#
directive|define
name|SDP_SERVICE_CLASS_IMAGING
value|0x111A
end_define

begin_define
define|#
directive|define
name|SDP_SERVICE_CLASS_IMAGING_RESPONDER
value|0x111B
end_define

begin_define
define|#
directive|define
name|SDP_SERVICE_CLASS_IMAGING_AUTOMATIC_ARCHIVE
value|0x111C
end_define

begin_define
define|#
directive|define
name|SDP_SERVICE_CLASS_IMAGING_REFERENCED_OBJECTS
value|0x111D
end_define

begin_define
define|#
directive|define
name|SDP_SERVICE_CLASS_HANDSFREE
value|0x111E
end_define

begin_define
define|#
directive|define
name|SDP_SERVICE_CLASS_HANDSFREE_AUDIO_GATEWAY
value|0x111F
end_define

begin_define
define|#
directive|define
name|SDP_SERVICE_CLASS_DIRECT_PRINTING_REFERENCE_OBJECTS
value|0x1120
end_define

begin_define
define|#
directive|define
name|SDP_SERVICE_CLASS_REFLECTED_UI
value|0x1121
end_define

begin_define
define|#
directive|define
name|SDP_SERVICE_CLASS_BASIC_PRINTING
value|0x1122
end_define

begin_define
define|#
directive|define
name|SDP_SERVICE_CLASS_PRINTING_STATUS
value|0x1123
end_define

begin_define
define|#
directive|define
name|SDP_SERVICE_CLASS_HUMAN_INTERFACE_DEVICE
value|0x1124
end_define

begin_define
define|#
directive|define
name|SDP_SERVICE_CLASS_HARDCOPY_CABLE_REPLACEMENT
value|0x1125
end_define

begin_define
define|#
directive|define
name|SDP_SERVICE_CLASS_HCR_PRINT
value|0x1126
end_define

begin_define
define|#
directive|define
name|SDP_SERVICE_CLASS_HCR_SCAN
value|0x1127
end_define

begin_define
define|#
directive|define
name|SDP_SERVICE_CLASS_COMMON_ISDN_ACCESS
value|0x1128
end_define

begin_define
define|#
directive|define
name|SDP_SERVICE_CLASS_VIDEO_CONFERENCING_GW
value|0x1129
end_define

begin_define
define|#
directive|define
name|SDP_SERVICE_CLASS_UDI_MT
value|0x112A
end_define

begin_define
define|#
directive|define
name|SDP_SERVICE_CLASS_UDI_TA
value|0x112B
end_define

begin_define
define|#
directive|define
name|SDP_SERVICE_CLASS_AUDIO_VIDEO
value|0x112C
end_define

begin_define
define|#
directive|define
name|SDP_SERVICE_CLASS_SIM_ACCESS
value|0x112D
end_define

begin_define
define|#
directive|define
name|SDP_SERVICE_CLASS_PNP_INFORMATION
value|0x1200
end_define

begin_define
define|#
directive|define
name|SDP_SERVICE_CLASS_GENERIC_NETWORKING
value|0x1201
end_define

begin_define
define|#
directive|define
name|SDP_SERVICE_CLASS_GENERIC_FILE_TRANSFER
value|0x1202
end_define

begin_define
define|#
directive|define
name|SDP_SERVICE_CLASS_GENERIC_AUDIO
value|0x1203
end_define

begin_define
define|#
directive|define
name|SDP_SERVICE_CLASS_GENERIC_TELEPHONY
value|0x1204
end_define

begin_define
define|#
directive|define
name|SDP_SERVICE_CLASS_UPNP
value|0x1205
end_define

begin_define
define|#
directive|define
name|SDP_SERVICE_CLASS_UPNP_IP
value|0x1206
end_define

begin_define
define|#
directive|define
name|SDP_SERVICE_CLASS_ESDP_UPNP_IP_PAN
value|0x1300
end_define

begin_define
define|#
directive|define
name|SDP_SERVICE_CLASS_ESDP_UPNP_IP_LAP
value|0x1301
end_define

begin_define
define|#
directive|define
name|SDP_SERVICE_CLASS_ESDP_UPNP_L2CAP
value|0x1302
end_define

begin_comment
comment|/*  * Universal attribute definitions (page 366) and  * http://www.bluetoothsig.org/assigned-numbers/sdp.htm  */
end_comment

begin_define
define|#
directive|define
name|SDP_ATTR_RANGE
parameter_list|(
name|lo
parameter_list|,
name|hi
parameter_list|)
define|\
value|(uint32_t)(((uint16_t)(lo)<< 16) | ((uint16_t)(hi)))
end_define

begin_define
define|#
directive|define
name|SDP_ATTR_SERVICE_RECORD_HANDLE
value|0x0000
end_define

begin_define
define|#
directive|define
name|SDP_ATTR_SERVICE_CLASS_ID_LIST
value|0x0001
end_define

begin_define
define|#
directive|define
name|SDP_ATTR_SERVICE_RECORD_STATE
value|0x0002
end_define

begin_define
define|#
directive|define
name|SDP_ATTR_SERVICE_ID
value|0x0003
end_define

begin_define
define|#
directive|define
name|SDP_ATTR_PROTOCOL_DESCRIPTOR_LIST
value|0x0004
end_define

begin_define
define|#
directive|define
name|SDP_ATTR_BROWSE_GROUP_LIST
value|0x0005
end_define

begin_define
define|#
directive|define
name|SDP_ATTR_LANGUAGE_BASE_ATTRIBUTE_ID_LIST
value|0x0006
end_define

begin_define
define|#
directive|define
name|SDP_ATTR_SERVICE_INFO_TIME_TO_LIVE
value|0x0007
end_define

begin_define
define|#
directive|define
name|SDP_ATTR_SERVICE_AVAILABILITY
value|0x0008
end_define

begin_define
define|#
directive|define
name|SDP_ATTR_BLUETOOTH_PROFILE_DESCRIPTOR_LIST
value|0x0009
end_define

begin_define
define|#
directive|define
name|SDP_ATTR_DOCUMENTATION_URL
value|0x000A
end_define

begin_define
define|#
directive|define
name|SDP_ATTR_CLIENT_EXECUTABLE_URL
value|0x000B
end_define

begin_define
define|#
directive|define
name|SDP_ATTR_ICON_URL
value|0x000C
end_define

begin_define
define|#
directive|define
name|SDP_ATTR_ADDITIONAL_PROTOCOL_DESCRIPTOR_LISTS
value|0x000D
end_define

begin_define
define|#
directive|define
name|SDP_ATTR_GROUP_ID
value|0x0200
end_define

begin_define
define|#
directive|define
name|SDP_ATTR_IP_SUBNET
value|0x0200
end_define

begin_define
define|#
directive|define
name|SDP_ATTR_VERSION_NUMBER_LIST
value|0x0200
end_define

begin_define
define|#
directive|define
name|SDP_ATTR_SERVICE_DATABASE_STATE
value|0x0201
end_define

begin_define
define|#
directive|define
name|SDP_ATTR_SERVICE_VERSION
value|0x0300
end_define

begin_define
define|#
directive|define
name|SDP_ATTR_EXTERNAL_NETWORK
value|0x0301
end_define

begin_define
define|#
directive|define
name|SDP_ATTR_NETWORK
value|0x0301
end_define

begin_define
define|#
directive|define
name|SDP_ATTR_SUPPORTED_DATA_STORES_LIST
value|0x0301
end_define

begin_define
define|#
directive|define
name|SDP_ATTR_FAX_CLASS1_SUPPORT
value|0x0302
end_define

begin_define
define|#
directive|define
name|SDP_ATTR_REMOTE_AUDIO_VOLUME_CONTROL
value|0x0302
end_define

begin_define
define|#
directive|define
name|SDP_ATTR_FAX_CLASS20_SUPPORT
value|0x0303
end_define

begin_define
define|#
directive|define
name|SDP_ATTR_SUPPORTED_FORMATS_LIST
value|0x0303
end_define

begin_define
define|#
directive|define
name|SDP_ATTR_FAX_CLASS2_SUPPORT
value|0x0304
end_define

begin_define
define|#
directive|define
name|SDP_ATTR_AUDIO_FEEDBACK_SUPPORT
value|0x0305
end_define

begin_define
define|#
directive|define
name|SDP_ATTR_NETWORK_ADDRESS
value|0x0306
end_define

begin_define
define|#
directive|define
name|SDP_ATTR_WAP_GATEWAY
value|0x0307
end_define

begin_define
define|#
directive|define
name|SDP_ATTR_HOME_PAGE_URL
value|0x0308
end_define

begin_define
define|#
directive|define
name|SDP_ATTR_WAP_STACK_TYPE
value|0x0309
end_define

begin_define
define|#
directive|define
name|SDP_ATTR_SECURITY_DESCRIPTION
value|0x030A
end_define

begin_define
define|#
directive|define
name|SDP_ATTR_NET_ACCESS_TYPE
value|0x030B
end_define

begin_define
define|#
directive|define
name|SDP_ATTR_MAX_NET_ACCESS_RATE
value|0x030C
end_define

begin_define
define|#
directive|define
name|SDP_ATTR_IPV4_SUBNET
value|0x030D
end_define

begin_define
define|#
directive|define
name|SDP_ATTR_IPV6_SUBNET
value|0x030E
end_define

begin_define
define|#
directive|define
name|SDP_ATTR_SUPPORTED_CAPABALITIES
value|0x0310
end_define

begin_define
define|#
directive|define
name|SDP_ATTR_SUPPORTED_FEATURES
value|0x0311
end_define

begin_define
define|#
directive|define
name|SDP_ATTR_SUPPORTED_FUNCTIONS
value|0x0312
end_define

begin_define
define|#
directive|define
name|SDP_ATTR_TOTAL_IMAGING_DATA_CAPACITY
value|0x0313
end_define

begin_comment
comment|/*  * The offset must be added to the attribute ID base (contained in the   * LANGUAGE_BASE_ATTRIBUTE_ID_LIST attribute) in order to compute the   * attribute ID for these attributes.  */
end_comment

begin_define
define|#
directive|define
name|SDP_ATTR_PRIMARY_LANGUAGE_BASE_ID
value|0x0100
end_define

begin_define
define|#
directive|define
name|SDP_ATTR_SERVICE_NAME_OFFSET
value|0x0000
end_define

begin_define
define|#
directive|define
name|SDP_ATTR_SERVICE_DESCRIPTION_OFFSET
value|0x0001
end_define

begin_define
define|#
directive|define
name|SDP_ATTR_PROVIDER_NAME_OFFSET
value|0x0002
end_define

begin_comment
comment|/*  * Protocol data unit (PDU) format (page 352)  */
end_comment

begin_define
define|#
directive|define
name|SDP_PDU_ERROR_RESPONSE
value|0x01
end_define

begin_define
define|#
directive|define
name|SDP_PDU_SERVICE_SEARCH_REQUEST
value|0x02
end_define

begin_define
define|#
directive|define
name|SDP_PDU_SERVICE_SEARCH_RESPONSE
value|0x03
end_define

begin_define
define|#
directive|define
name|SDP_PDU_SERVICE_ATTRIBUTE_REQUEST
value|0x04
end_define

begin_define
define|#
directive|define
name|SDP_PDU_SERVICE_ATTRIBUTE_RESPONSE
value|0x05
end_define

begin_define
define|#
directive|define
name|SDP_PDU_SERVICE_SEARCH_ATTRIBUTE_REQUEST
value|0x06
end_define

begin_define
define|#
directive|define
name|SDP_PDU_SERVICE_SEARCH_ATTRIBUTE_RESPONSE
value|0x07
end_define

begin_struct
struct|struct
name|sdp_pdu
block|{
name|uint8_t
name|pid
decl_stmt|;
comment|/* PDU ID - SDP_PDU_xxx */
name|uint16_t
name|tid
decl_stmt|;
comment|/* transaction ID */
name|uint16_t
name|len
decl_stmt|;
comment|/* parameters length (in bytes) */
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|sdp_pdu
name|sdp_pdu_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|sdp_pdu
modifier|*
name|sdp_pdu_p
typedef|;
end_typedef

begin_comment
comment|/*  * Error codes for SDP_PDU_ERROR_RESPONSE  */
end_comment

begin_define
define|#
directive|define
name|SDP_ERROR_CODE_INVALID_SDP_VERSION
value|0x0001
end_define

begin_define
define|#
directive|define
name|SDP_ERROR_CODE_INVALID_SERVICE_RECORD_HANDLE
value|0x0002
end_define

begin_define
define|#
directive|define
name|SDP_ERROR_CODE_INVALID_REQUEST_SYNTAX
value|0x0003
end_define

begin_define
define|#
directive|define
name|SDP_ERROR_CODE_INVALID_PDU_SIZE
value|0x0004
end_define

begin_define
define|#
directive|define
name|SDP_ERROR_CODE_INVALID_CONTINUATION_STATE
value|0x0005
end_define

begin_define
define|#
directive|define
name|SDP_ERROR_CODE_INSUFFICIENT_RESOURCES
value|0x0006
end_define

begin_comment
comment|/*  * SDP int128/uint128 parameter  */
end_comment

begin_struct
struct|struct
name|int128
block|{
name|int8_t
name|b
index|[
literal|16
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|int128
name|int128_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|int128
name|uint128_t
typedef|;
end_typedef

begin_comment
comment|/*  * SDP attribute  */
end_comment

begin_struct
struct|struct
name|sdp_attr
block|{
name|uint16_t
name|flags
decl_stmt|;
define|#
directive|define
name|SDP_ATTR_OK
value|(0<< 0)
define|#
directive|define
name|SDP_ATTR_INVALID
value|(1<< 0)
define|#
directive|define
name|SDP_ATTR_TRUNCATED
value|(1<< 1)
name|uint16_t
name|attr
decl_stmt|;
comment|/* SDP_ATTR_xxx */
name|uint32_t
name|vlen
decl_stmt|;
comment|/* length of the value[] in bytes */
name|uint8_t
modifier|*
name|value
decl_stmt|;
comment|/* base pointer */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|sdp_attr
name|sdp_attr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|sdp_attr
modifier|*
name|sdp_attr_p
typedef|;
end_typedef

begin_comment
comment|/******************************************************************************  * User interface  *****************************************************************************/
end_comment

begin_comment
comment|/* Inline versions of get/put byte/short/long. Pointer is advanced */
end_comment

begin_define
define|#
directive|define
name|SDP_GET8
parameter_list|(
name|b
parameter_list|,
name|cp
parameter_list|)
value|{ \ 	register uint8_t *t_cp = (uint8_t *)(cp); \ 	(b) = *t_cp; \ 	(cp) ++; \ }
end_define

begin_define
define|#
directive|define
name|SDP_GET16
parameter_list|(
name|s
parameter_list|,
name|cp
parameter_list|)
value|{ \ 	register uint8_t *t_cp = (uint8_t *)(cp); \ 	(s) = ((uint16_t)t_cp[0]<< 8) \ 	    | ((uint16_t)t_cp[1]) \ 	    ; \ 	(cp) += 2; \ }
end_define

begin_define
define|#
directive|define
name|SDP_GET32
parameter_list|(
name|l
parameter_list|,
name|cp
parameter_list|)
value|{ \ 	register uint8_t *t_cp = (uint8_t *)(cp); \ 	(l) = ((uint32_t)t_cp[0]<< 24) \ 	    | ((uint32_t)t_cp[1]<< 16) \ 	    | ((uint32_t)t_cp[2]<< 8) \ 	    | ((uint32_t)t_cp[3]) \ 	    ; \ 	(cp) += 4; \ }
end_define

begin_define
define|#
directive|define
name|SDP_GET64
parameter_list|(
name|l
parameter_list|,
name|cp
parameter_list|)
value|{ \ 	register uint8_t *t_cp = (uint8_t *)(cp); \ 	(l) = ((uint64_t)t_cp[0]<< 56) \ 	    | ((uint64_t)t_cp[1]<< 48) \ 	    | ((uint64_t)t_cp[2]<< 40) \ 	    | ((uint64_t)t_cp[3]<< 32) \ 	    | ((uint64_t)t_cp[4]<< 24) \ 	    | ((uint64_t)t_cp[5]<< 16) \ 	    | ((uint64_t)t_cp[6]<< 8) \ 	    | ((uint64_t)t_cp[7]) \ 	    ; \ 	(cp) += 8; \ }
end_define

begin_if
if|#
directive|if
name|BYTE_ORDER
operator|==
name|LITTLE_ENDIAN
end_if

begin_define
define|#
directive|define
name|SDP_GET128
parameter_list|(
name|l
parameter_list|,
name|cp
parameter_list|)
value|{ \ 	register uint8_t *t_cp = (uint8_t *)(cp); \ 	(l)->b[15] = *t_cp++; \ 	(l)->b[14] = *t_cp++; \ 	(l)->b[13] = *t_cp++; \ 	(l)->b[12] = *t_cp++; \ 	(l)->b[11] = *t_cp++; \ 	(l)->b[10] = *t_cp++; \ 	(l)->b[9]  = *t_cp++; \ 	(l)->b[8]  = *t_cp++; \ 	(l)->b[7]  = *t_cp++; \ 	(l)->b[6]  = *t_cp++; \ 	(l)->b[5]  = *t_cp++; \ 	(l)->b[4]  = *t_cp++; \ 	(l)->b[3]  = *t_cp++; \ 	(l)->b[2]  = *t_cp++; \ 	(l)->b[1]  = *t_cp++; \ 	(l)->b[0]  = *t_cp++; \ 	(cp) += 16; \ }
end_define

begin_define
define|#
directive|define
name|SDP_GET_UUID128
parameter_list|(
name|l
parameter_list|,
name|cp
parameter_list|)
value|{ \ 	register uint8_t *t_cp = (uint8_t *)(cp); \ 	(l)->b[0]  = *t_cp++; \ 	(l)->b[1]  = *t_cp++; \ 	(l)->b[2]  = *t_cp++; \ 	(l)->b[3]  = *t_cp++; \ 	(l)->b[4]  = *t_cp++; \ 	(l)->b[5]  = *t_cp++; \ 	(l)->b[6]  = *t_cp++; \ 	(l)->b[7]  = *t_cp++; \ 	(l)->b[8]  = *t_cp++; \ 	(l)->b[9]  = *t_cp++; \ 	(l)->b[10] = *t_cp++; \ 	(l)->b[11] = *t_cp++; \ 	(l)->b[12] = *t_cp++; \ 	(l)->b[13] = *t_cp++; \ 	(l)->b[14] = *t_cp++; \ 	(l)->b[15] = *t_cp++; \ 	(cp) += 16; \ }
end_define

begin_elif
elif|#
directive|elif
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
end_elif

begin_define
define|#
directive|define
name|SDP_GET128
parameter_list|(
name|l
parameter_list|,
name|cp
parameter_list|)
value|{ \ 	register uint8_t *t_cp = (uint8_t *)(cp); \ 	(l)->b[0]  = *t_cp++; \ 	(l)->b[1]  = *t_cp++; \ 	(l)->b[2]  = *t_cp++; \ 	(l)->b[3]  = *t_cp++; \ 	(l)->b[4]  = *t_cp++; \ 	(l)->b[5]  = *t_cp++; \ 	(l)->b[6]  = *t_cp++; \ 	(l)->b[7]  = *t_cp++; \ 	(l)->b[8]  = *t_cp++; \ 	(l)->b[9]  = *t_cp++; \ 	(l)->b[10] = *t_cp++; \ 	(l)->b[11] = *t_cp++; \ 	(l)->b[12] = *t_cp++; \ 	(l)->b[13] = *t_cp++; \ 	(l)->b[14] = *t_cp++; \ 	(l)->b[15] = *t_cp++; \ 	(cp) += 16; \ }
end_define

begin_define
define|#
directive|define
name|SDP_GET_UUID128
parameter_list|(
name|l
parameter_list|,
name|cp
parameter_list|)
value|SDP_GET128(l, cp)
end_define

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
literal|"Unsupported BYTE_ORDER"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BYTE_ORDER */
end_comment

begin_define
define|#
directive|define
name|SDP_PUT8
parameter_list|(
name|b
parameter_list|,
name|cp
parameter_list|)
value|{ \ 	register uint8_t t_b = (uint8_t)(b); \ 	register uint8_t *t_cp = (uint8_t *)(cp); \ 	*t_cp = t_b; \ 	(cp) ++; \ }
end_define

begin_define
define|#
directive|define
name|SDP_PUT16
parameter_list|(
name|s
parameter_list|,
name|cp
parameter_list|)
value|{ \ 	register uint16_t t_s = (uint16_t)(s); \ 	register uint8_t *t_cp = (uint8_t *)(cp); \ 	*t_cp++ = t_s>> 8; \ 	*t_cp   = t_s; \ 	(cp) += 2; \ }
end_define

begin_define
define|#
directive|define
name|SDP_PUT32
parameter_list|(
name|l
parameter_list|,
name|cp
parameter_list|)
value|{ \ 	register uint32_t t_l = (uint32_t)(l); \ 	register uint8_t *t_cp = (uint8_t *)(cp); \ 	*t_cp++ = t_l>> 24; \ 	*t_cp++ = t_l>> 16; \ 	*t_cp++ = t_l>> 8; \ 	*t_cp   = t_l; \ 	(cp) += 4; \ }
end_define

begin_define
define|#
directive|define
name|SDP_PUT64
parameter_list|(
name|l
parameter_list|,
name|cp
parameter_list|)
value|{ \ 	register uint64_t t_l = (uint64_t)(l); \ 	register uint8_t *t_cp = (uint8_t *)(cp); \ 	*t_cp++ = t_l>> 56; \ 	*t_cp++ = t_l>> 48; \ 	*t_cp++ = t_l>> 40; \ 	*t_cp++ = t_l>> 32; \ 	*t_cp++ = t_l>> 24; \ 	*t_cp++ = t_l>> 16; \ 	*t_cp++ = t_l>> 8; \ 	*t_cp   = t_l; \ 	(cp) += 8; \ }
end_define

begin_if
if|#
directive|if
name|BYTE_ORDER
operator|==
name|LITTLE_ENDIAN
end_if

begin_define
define|#
directive|define
name|SDP_PUT128
parameter_list|(
name|l
parameter_list|,
name|cp
parameter_list|)
value|{ \ 	register uint8_t *t_cp = (uint8_t *)(cp); \ 	*t_cp++ = (l)->b[15]; \ 	*t_cp++ = (l)->b[14]; \ 	*t_cp++ = (l)->b[13]; \ 	*t_cp++ = (l)->b[12]; \ 	*t_cp++ = (l)->b[11]; \ 	*t_cp++ = (l)->b[10]; \ 	*t_cp++ = (l)->b[9];  \ 	*t_cp++ = (l)->b[8];  \ 	*t_cp++ = (l)->b[7];  \ 	*t_cp++ = (l)->b[6];  \ 	*t_cp++ = (l)->b[5];  \ 	*t_cp++ = (l)->b[4];  \ 	*t_cp++ = (l)->b[3];  \ 	*t_cp++ = (l)->b[2];  \ 	*t_cp++ = (l)->b[1];  \ 	*t_cp   = (l)->b[0];  \ 	(cp) += 16; \ }
end_define

begin_define
define|#
directive|define
name|SDP_PUT_UUID128
parameter_list|(
name|l
parameter_list|,
name|cp
parameter_list|)
value|{ \ 	register uint8_t *t_cp = (uint8_t *)(cp); \ 	*t_cp++ = (l)->b[0];  \ 	*t_cp++ = (l)->b[1];  \ 	*t_cp++ = (l)->b[2];  \ 	*t_cp++ = (l)->b[3];  \ 	*t_cp++ = (l)->b[4];  \ 	*t_cp++ = (l)->b[5];  \ 	*t_cp++ = (l)->b[6];  \ 	*t_cp++ = (l)->b[7];  \ 	*t_cp++ = (l)->b[8];  \ 	*t_cp++ = (l)->b[9];  \ 	*t_cp++ = (l)->b[10]; \ 	*t_cp++ = (l)->b[11]; \ 	*t_cp++ = (l)->b[12]; \ 	*t_cp++ = (l)->b[13]; \ 	*t_cp++ = (l)->b[14]; \ 	*t_cp   = (l)->b[15]; \ 	(cp) += 16; \ }
end_define

begin_elif
elif|#
directive|elif
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
end_elif

begin_define
define|#
directive|define
name|SDP_PUT128
parameter_list|(
name|l
parameter_list|,
name|cp
parameter_list|)
value|{ \ 	register uint8_t *t_cp = (uint8_t *)(cp); \ 	*t_cp++ = (l)->b[0];  \ 	*t_cp++ = (l)->b[1];  \ 	*t_cp++ = (l)->b[2];  \ 	*t_cp++ = (l)->b[3];  \ 	*t_cp++ = (l)->b[4];  \ 	*t_cp++ = (l)->b[5];  \ 	*t_cp++ = (l)->b[6];  \ 	*t_cp++ = (l)->b[7];  \ 	*t_cp++ = (l)->b[8];  \ 	*t_cp++ = (l)->b[9];  \ 	*t_cp++ = (l)->b[10]; \ 	*t_cp++ = (l)->b[11]; \ 	*t_cp++ = (l)->b[12]; \ 	*t_cp++ = (l)->b[13]; \ 	*t_cp++ = (l)->b[14]; \ 	*t_cp   = (l)->b[15]; \ 	(cp) += 16; \ }
end_define

begin_define
define|#
directive|define
name|SDP_PUT_UUID128
parameter_list|(
name|l
parameter_list|,
name|cp
parameter_list|)
value|SDP_PUT128(l, cp)
end_define

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
literal|"Unsupported BYTE_ORDER"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BYTE_ORDER */
end_comment

begin_function_decl
name|void
modifier|*
name|sdp_open
parameter_list|(
name|bdaddr_t
specifier|const
modifier|*
name|l
parameter_list|,
name|bdaddr_t
specifier|const
modifier|*
name|r
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|sdp_open_local
parameter_list|(
name|char
specifier|const
modifier|*
name|control
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|sdp_close
parameter_list|(
name|void
modifier|*
name|xs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|sdp_error
parameter_list|(
name|void
modifier|*
name|xs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|sdp_search
parameter_list|(
name|void
modifier|*
name|xs
parameter_list|,
name|uint32_t
name|plen
parameter_list|,
name|uint16_t
specifier|const
modifier|*
name|pp
parameter_list|,
name|uint32_t
name|alen
parameter_list|,
name|uint32_t
specifier|const
modifier|*
name|ap
parameter_list|,
name|uint32_t
name|vlen
parameter_list|,
name|sdp_attr_t
modifier|*
name|vp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
specifier|const
modifier|*
name|sdp_attr2desc
parameter_list|(
name|uint16_t
name|attr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
specifier|const
modifier|*
name|sdp_uuid2desc
parameter_list|(
name|uint16_t
name|uuid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sdp_print
parameter_list|(
name|uint32_t
name|level
parameter_list|,
name|uint8_t
specifier|const
modifier|*
name|start
parameter_list|,
name|uint8_t
specifier|const
modifier|*
name|end
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/******************************************************************************  * sdpd interface and Bluetooth profiles data  *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|SDP_LOCAL_PATH
value|"/var/run/sdp"
end_define

begin_define
define|#
directive|define
name|SDP_LOCAL_MTU
value|4096
end_define

begin_comment
comment|/*  * These are NOT defined in spec and only accepted on control sockets.  * The response to these request always will be SDP_PDU_ERROR_RESPONSE.  * The first 2 bytes (after PDU header) is an error code (in network  * byte order). The rest of the data (pdu->len - 2) is a response data  * and depend on the request.  *  * SDP_PDU_SERVICE_REGISTER_REQUEST  * 	pdu_header_t	hdr;  *	u_int16_t	uuid;	service class UUID (network byte order)  *	bdaddr_t	bdaddr;	local BD_ADDR (or ANY)  *	profile data[pdu->len - sizeof(uuid) - sizeof(bdaddr)]  *  * in successful reponse additional data will contain 4 bytes record handle  *  *  * SDP_PDU_SERVICE_UNREGISTER_REQUEST  *	pdu_header_t	hdr;  *	u_int32_t	record_handle;	(network byte order)  *   * no additional data in response.  *  *  * SDP_PDU_SERVICE_CHANGE_REQUEST  * 	pdu_header_t	hdr;  *	u_int32_t	record_handle;	(network byte order)  *	profile data[pdu->len - sizeof(record_handle)]  *  * no additional data in response.  */
end_comment

begin_define
define|#
directive|define
name|SDP_PDU_SERVICE_REGISTER_REQUEST
value|0x81
end_define

begin_define
define|#
directive|define
name|SDP_PDU_SERVICE_UNREGISTER_REQUEST
value|0x82
end_define

begin_define
define|#
directive|define
name|SDP_PDU_SERVICE_CHANGE_REQUEST
value|0x83
end_define

begin_struct
struct|struct
name|sdp_dun_profile
block|{
name|uint8_t
name|server_channel
decl_stmt|;
name|uint8_t
name|audio_feedback_support
decl_stmt|;
name|uint8_t
name|reserved
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|sdp_dun_profile
name|sdp_dun_profile_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|sdp_dun_profile
modifier|*
name|sdp_dun_profile_p
typedef|;
end_typedef

begin_struct
struct|struct
name|sdp_ftrn_profile
block|{
name|uint8_t
name|server_channel
decl_stmt|;
name|uint8_t
name|reserved
index|[
literal|3
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|sdp_ftrn_profile
name|sdp_ftrn_profile_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|sdp_ftrn_profile
modifier|*
name|sdp_ftrn_profile_p
typedef|;
end_typedef

begin_comment
comment|/* Keep this in sync with sdp_opush_profile */
end_comment

begin_struct
struct|struct
name|sdp_irmc_profile
block|{
name|uint8_t
name|server_channel
decl_stmt|;
name|uint8_t
name|supported_formats_size
decl_stmt|;
name|uint8_t
name|supported_formats
index|[
literal|30
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|sdp_irmc_profile
name|sdp_irmc_profile_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|sdp_irmc_profile
modifier|*
name|sdp_irmc_profile_p
typedef|;
end_typedef

begin_struct
struct|struct
name|sdp_irmc_command_profile
block|{
name|uint8_t
name|server_channel
decl_stmt|;
name|uint8_t
name|reserved
index|[
literal|3
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|sdp_irmc_command_profile
name|sdp_irmc_command_profile_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|sdp_irmc_command_profile
modifier|*
name|sdp_irmc_command_profile_p
typedef|;
end_typedef

begin_struct
struct|struct
name|sdp_lan_profile
block|{
name|uint8_t
name|server_channel
decl_stmt|;
name|uint8_t
name|load_factor
decl_stmt|;
name|uint8_t
name|reserved
decl_stmt|;
name|uint8_t
name|ip_subnet_radius
decl_stmt|;
name|uint32_t
name|ip_subnet
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|sdp_lan_profile
name|sdp_lan_profile_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|sdp_lan_profile
modifier|*
name|sdp_lan_profile_p
typedef|;
end_typedef

begin_comment
comment|/* Keep this in sync with sdp_irmc_profile */
end_comment

begin_struct
struct|struct
name|sdp_opush_profile
block|{
name|uint8_t
name|server_channel
decl_stmt|;
name|uint8_t
name|supported_formats_size
decl_stmt|;
name|uint8_t
name|supported_formats
index|[
literal|30
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|sdp_opush_profile
name|sdp_opush_profile_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|sdp_opush_profile
modifier|*
name|sdp_opush_profile_p
typedef|;
end_typedef

begin_struct
struct|struct
name|sdp_sp_profile
block|{
name|uint8_t
name|server_channel
decl_stmt|;
name|uint8_t
name|reserved
index|[
literal|3
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|sdp_sp_profile
name|sdp_sp_profile_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|sdp_sp_profile
modifier|*
name|sdp_sp_profile_p
typedef|;
end_typedef

begin_function_decl
name|int32_t
name|sdp_register_service
parameter_list|(
name|void
modifier|*
name|xss
parameter_list|,
name|uint16_t
name|uuid
parameter_list|,
name|bdaddr_p
specifier|const
name|bdaddr
parameter_list|,
name|uint8_t
specifier|const
modifier|*
name|data
parameter_list|,
name|uint32_t
name|datalen
parameter_list|,
name|uint32_t
modifier|*
name|handle
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|sdp_unregister_service
parameter_list|(
name|void
modifier|*
name|xss
parameter_list|,
name|uint32_t
name|handle
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|sdp_change_service
parameter_list|(
name|void
modifier|*
name|xss
parameter_list|,
name|uint32_t
name|handle
parameter_list|,
name|uint8_t
specifier|const
modifier|*
name|data
parameter_list|,
name|uint32_t
name|datalen
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ndef _SDP_H_ */
end_comment

end_unit

