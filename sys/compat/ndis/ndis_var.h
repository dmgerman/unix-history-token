begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003  *	Bill Paul<wpaul@windriver.com>.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Bill Paul.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY Bill Paul AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL Bill Paul OR THE VOICES IN HIS HEAD  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NDIS_VAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_NDIS_VAR_H_
end_define

begin_comment
comment|/* Forward declarations */
end_comment

begin_struct_decl
struct_decl|struct
name|ndis_miniport_block
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ndis_mdriver_block
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|struct
name|ndis_miniport_block
name|ndis_miniport_block
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|ndis_mdriver_block
name|ndis_mdriver_block
typedef|;
end_typedef

begin_comment
comment|/* Base types */
end_comment

begin_typedef
typedef|typedef
name|uint32_t
name|ndis_status
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
modifier|*
name|ndis_handle
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint32_t
name|ndis_oid
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint32_t
name|ndis_error_code
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|register_t
name|ndis_kspin_lock
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint8_t
name|ndis_kirql
typedef|;
end_typedef

begin_comment
comment|/*  * NDIS status codes (there are lots of them). The ones that  * don't seem to fit the pattern are actually mapped to generic  * NT status codes.  */
end_comment

begin_define
define|#
directive|define
name|NDIS_STATUS_SUCCESS
value|0
end_define

begin_define
define|#
directive|define
name|NDIS_STATUS_PENDING
value|0x00000103
end_define

begin_define
define|#
directive|define
name|NDIS_STATUS_NOT_RECOGNIZED
value|0x00010001
end_define

begin_define
define|#
directive|define
name|NDIS_STATUS_NOT_COPIED
value|0x00010002
end_define

begin_define
define|#
directive|define
name|NDIS_STATUS_NOT_ACCEPTED
value|0x00010003
end_define

begin_define
define|#
directive|define
name|NDIS_STATUS_CALL_ACTIVE
value|0x00010007
end_define

begin_define
define|#
directive|define
name|NDIS_STATUS_ONLINE
value|0x40010003
end_define

begin_define
define|#
directive|define
name|NDIS_STATUS_RESET_START
value|0x40010004
end_define

begin_define
define|#
directive|define
name|NDIS_STATUS_RESET_END
value|0x40010005
end_define

begin_define
define|#
directive|define
name|NDIS_STATUS_RING_STATUS
value|0x40010006
end_define

begin_define
define|#
directive|define
name|NDIS_STATUS_CLOSED
value|0x40010007
end_define

begin_define
define|#
directive|define
name|NDIS_STATUS_WAN_LINE_UP
value|0x40010008
end_define

begin_define
define|#
directive|define
name|NDIS_STATUS_WAN_LINE_DOWN
value|0x40010009
end_define

begin_define
define|#
directive|define
name|NDIS_STATUS_WAN_FRAGMENT
value|0x4001000A
end_define

begin_define
define|#
directive|define
name|NDIS_STATUS_MEDIA_CONNECT
value|0x4001000B
end_define

begin_define
define|#
directive|define
name|NDIS_STATUS_MEDIA_DISCONNECT
value|0x4001000C
end_define

begin_define
define|#
directive|define
name|NDIS_STATUS_HARDWARE_LINE_UP
value|0x4001000D
end_define

begin_define
define|#
directive|define
name|NDIS_STATUS_HARDWARE_LINE_DOWN
value|0x4001000E
end_define

begin_define
define|#
directive|define
name|NDIS_STATUS_INTERFACE_UP
value|0x4001000F
end_define

begin_define
define|#
directive|define
name|NDIS_STATUS_INTERFACE_DOWN
value|0x40010010
end_define

begin_define
define|#
directive|define
name|NDIS_STATUS_MEDIA_BUSY
value|0x40010011
end_define

begin_define
define|#
directive|define
name|NDIS_STATUS_MEDIA_SPECIFIC_INDICATION
value|0x40010012
end_define

begin_define
define|#
directive|define
name|NDIS_STATUS_WW_INDICATION
value|NDIS_STATUS_MEDIA_SPECIFIC_INDICATION
end_define

begin_define
define|#
directive|define
name|NDIS_STATUS_LINK_SPEED_CHANGE
value|0x40010013
end_define

begin_define
define|#
directive|define
name|NDIS_STATUS_WAN_GET_STATS
value|0x40010014
end_define

begin_define
define|#
directive|define
name|NDIS_STATUS_WAN_CO_FRAGMENT
value|0x40010015
end_define

begin_define
define|#
directive|define
name|NDIS_STATUS_WAN_CO_LINKPARAMS
value|0x40010016
end_define

begin_define
define|#
directive|define
name|NDIS_STATUS_NOT_RESETTABLE
value|0x80010001
end_define

begin_define
define|#
directive|define
name|NDIS_STATUS_SOFT_ERRORS
value|0x80010003
end_define

begin_define
define|#
directive|define
name|NDIS_STATUS_HARD_ERRORS
value|0x80010004
end_define

begin_define
define|#
directive|define
name|NDIS_STATUS_BUFFER_OVERFLOW
value|0x80000005
end_define

begin_define
define|#
directive|define
name|NDIS_STATUS_FAILURE
value|0xC0000001
end_define

begin_define
define|#
directive|define
name|NDIS_STATUS_RESOURCES
value|0xC000009A
end_define

begin_define
define|#
directive|define
name|NDIS_STATUS_CLOSING
value|0xC0010002
end_define

begin_define
define|#
directive|define
name|NDIS_STATUS_BAD_VERSION
value|0xC0010004
end_define

begin_define
define|#
directive|define
name|NDIS_STATUS_BAD_CHARACTERISTICS
value|0xC0010005
end_define

begin_define
define|#
directive|define
name|NDIS_STATUS_ADAPTER_NOT_FOUND
value|0xC0010006
end_define

begin_define
define|#
directive|define
name|NDIS_STATUS_OPEN_FAILED
value|0xC0010007
end_define

begin_define
define|#
directive|define
name|NDIS_STATUS_DEVICE_FAILED
value|0xC0010008
end_define

begin_define
define|#
directive|define
name|NDIS_STATUS_MULTICAST_FULL
value|0xC0010009
end_define

begin_define
define|#
directive|define
name|NDIS_STATUS_MULTICAST_EXISTS
value|0xC001000A
end_define

begin_define
define|#
directive|define
name|NDIS_STATUS_MULTICAST_NOT_FOUND
value|0xC001000B
end_define

begin_define
define|#
directive|define
name|NDIS_STATUS_REQUEST_ABORTED
value|0xC001000C
end_define

begin_define
define|#
directive|define
name|NDIS_STATUS_RESET_IN_PROGRESS
value|0xC001000D
end_define

begin_define
define|#
directive|define
name|NDIS_STATUS_CLOSING_INDICATING
value|0xC001000E
end_define

begin_define
define|#
directive|define
name|NDIS_STATUS_NOT_SUPPORTED
value|0xC00000BB
end_define

begin_define
define|#
directive|define
name|NDIS_STATUS_INVALID_PACKET
value|0xC001000F
end_define

begin_define
define|#
directive|define
name|NDIS_STATUS_OPEN_LIST_FULL
value|0xC0010010
end_define

begin_define
define|#
directive|define
name|NDIS_STATUS_ADAPTER_NOT_READY
value|0xC0010011
end_define

begin_define
define|#
directive|define
name|NDIS_STATUS_ADAPTER_NOT_OPEN
value|0xC0010012
end_define

begin_define
define|#
directive|define
name|NDIS_STATUS_NOT_INDICATING
value|0xC0010013
end_define

begin_define
define|#
directive|define
name|NDIS_STATUS_INVALID_LENGTH
value|0xC0010014
end_define

begin_define
define|#
directive|define
name|NDIS_STATUS_INVALID_DATA
value|0xC0010015
end_define

begin_define
define|#
directive|define
name|NDIS_STATUS_BUFFER_TOO_SHORT
value|0xC0010016
end_define

begin_define
define|#
directive|define
name|NDIS_STATUS_INVALID_OID
value|0xC0010017
end_define

begin_define
define|#
directive|define
name|NDIS_STATUS_ADAPTER_REMOVED
value|0xC0010018
end_define

begin_define
define|#
directive|define
name|NDIS_STATUS_UNSUPPORTED_MEDIA
value|0xC0010019
end_define

begin_define
define|#
directive|define
name|NDIS_STATUS_GROUP_ADDRESS_IN_USE
value|0xC001001A
end_define

begin_define
define|#
directive|define
name|NDIS_STATUS_FILE_NOT_FOUND
value|0xC001001B
end_define

begin_define
define|#
directive|define
name|NDIS_STATUS_ERROR_READING_FILE
value|0xC001001C
end_define

begin_define
define|#
directive|define
name|NDIS_STATUS_ALREADY_MAPPED
value|0xC001001D
end_define

begin_define
define|#
directive|define
name|NDIS_STATUS_RESOURCE_CONFLICT
value|0xC001001E
end_define

begin_define
define|#
directive|define
name|NDIS_STATUS_NO_CABLE
value|0xC001001F
end_define

begin_define
define|#
directive|define
name|NDIS_STATUS_INVALID_SAP
value|0xC0010020
end_define

begin_define
define|#
directive|define
name|NDIS_STATUS_SAP_IN_USE
value|0xC0010021
end_define

begin_define
define|#
directive|define
name|NDIS_STATUS_INVALID_ADDRESS
value|0xC0010022
end_define

begin_define
define|#
directive|define
name|NDIS_STATUS_VC_NOT_ACTIVATED
value|0xC0010023
end_define

begin_define
define|#
directive|define
name|NDIS_STATUS_DEST_OUT_OF_ORDER
value|0xC0010024
end_define

begin_define
define|#
directive|define
name|NDIS_STATUS_VC_NOT_AVAILABLE
value|0xC0010025
end_define

begin_define
define|#
directive|define
name|NDIS_STATUS_CELLRATE_NOT_AVAILABLE
value|0xC0010026
end_define

begin_define
define|#
directive|define
name|NDIS_STATUS_INCOMPATABLE_QOS
value|0xC0010027
end_define

begin_define
define|#
directive|define
name|NDIS_STATUS_AAL_PARAMS_UNSUPPORTED
value|0xC0010028
end_define

begin_define
define|#
directive|define
name|NDIS_STATUS_NO_ROUTE_TO_DESTINATION
value|0xC0010029
end_define

begin_define
define|#
directive|define
name|NDIS_STATUS_TOKEN_RING_OPEN_ERROR
value|0xC0011000
end_define

begin_define
define|#
directive|define
name|NDIS_STATUS_INVALID_DEVICE_REQUEST
value|0xC0000010
end_define

begin_define
define|#
directive|define
name|NDIS_STATUS_NETWORK_UNREACHABLE
value|0xC000023C
end_define

begin_comment
comment|/*  * NDIS event codes. They are usually reported to NdisWriteErrorLogEntry().  */
end_comment

begin_define
define|#
directive|define
name|EVENT_NDIS_RESOURCE_CONFLICT
value|0xC0001388
end_define

begin_define
define|#
directive|define
name|EVENT_NDIS_OUT_OF_RESOURCE
value|0xC0001389
end_define

begin_define
define|#
directive|define
name|EVENT_NDIS_HARDWARE_FAILURE
value|0xC000138A
end_define

begin_define
define|#
directive|define
name|EVENT_NDIS_ADAPTER_NOT_FOUND
value|0xC000138B
end_define

begin_define
define|#
directive|define
name|EVENT_NDIS_INTERRUPT_CONNECT
value|0xC000138C
end_define

begin_define
define|#
directive|define
name|EVENT_NDIS_DRIVER_FAILURE
value|0xC000138D
end_define

begin_define
define|#
directive|define
name|EVENT_NDIS_BAD_VERSION
value|0xC000138E
end_define

begin_define
define|#
directive|define
name|EVENT_NDIS_TIMEOUT
value|0x8000138F
end_define

begin_define
define|#
directive|define
name|EVENT_NDIS_NETWORK_ADDRESS
value|0xC0001390
end_define

begin_define
define|#
directive|define
name|EVENT_NDIS_UNSUPPORTED_CONFIGURATION
value|0xC0001391
end_define

begin_define
define|#
directive|define
name|EVENT_NDIS_INVALID_VALUE_FROM_ADAPTER
value|0xC0001392
end_define

begin_define
define|#
directive|define
name|EVENT_NDIS_MISSING_CONFIGURATION_PARAMETER
value|0xC0001393
end_define

begin_define
define|#
directive|define
name|EVENT_NDIS_BAD_IO_BASE_ADDRESS
value|0xC0001394
end_define

begin_define
define|#
directive|define
name|EVENT_NDIS_RECEIVE_SPACE_SMALL
value|0x40001395
end_define

begin_define
define|#
directive|define
name|EVENT_NDIS_ADAPTER_DISABLED
value|0x80001396
end_define

begin_define
define|#
directive|define
name|EVENT_NDIS_IO_PORT_CONFLICT
value|0x80001397
end_define

begin_define
define|#
directive|define
name|EVENT_NDIS_PORT_OR_DMA_CONFLICT
value|0x80001398
end_define

begin_define
define|#
directive|define
name|EVENT_NDIS_MEMORY_CONFLICT
value|0x80001399
end_define

begin_define
define|#
directive|define
name|EVENT_NDIS_INTERRUPT_CONFLICT
value|0x8000139A
end_define

begin_define
define|#
directive|define
name|EVENT_NDIS_DMA_CONFLICT
value|0x8000139B
end_define

begin_define
define|#
directive|define
name|EVENT_NDIS_INVALID_DOWNLOAD_FILE_ERROR
value|0xC000139C
end_define

begin_define
define|#
directive|define
name|EVENT_NDIS_MAXRECEIVES_ERROR
value|0x8000139D
end_define

begin_define
define|#
directive|define
name|EVENT_NDIS_MAXTRANSMITS_ERROR
value|0x8000139E
end_define

begin_define
define|#
directive|define
name|EVENT_NDIS_MAXFRAMESIZE_ERROR
value|0x8000139F
end_define

begin_define
define|#
directive|define
name|EVENT_NDIS_MAXINTERNALBUFS_ERROR
value|0x800013A0
end_define

begin_define
define|#
directive|define
name|EVENT_NDIS_MAXMULTICAST_ERROR
value|0x800013A1
end_define

begin_define
define|#
directive|define
name|EVENT_NDIS_PRODUCTID_ERROR
value|0x800013A2
end_define

begin_define
define|#
directive|define
name|EVENT_NDIS_LOBE_FAILUE_ERROR
value|0x800013A3
end_define

begin_define
define|#
directive|define
name|EVENT_NDIS_SIGNAL_LOSS_ERROR
value|0x800013A4
end_define

begin_define
define|#
directive|define
name|EVENT_NDIS_REMOVE_RECEIVED_ERROR
value|0x800013A5
end_define

begin_define
define|#
directive|define
name|EVENT_NDIS_TOKEN_RING_CORRECTION
value|0x400013A6
end_define

begin_define
define|#
directive|define
name|EVENT_NDIS_ADAPTER_CHECK_ERROR
value|0xC00013A7
end_define

begin_define
define|#
directive|define
name|EVENT_NDIS_RESET_FAILURE_ERROR
value|0x800013A8
end_define

begin_define
define|#
directive|define
name|EVENT_NDIS_CABLE_DISCONNECTED_ERROR
value|0x800013A9
end_define

begin_define
define|#
directive|define
name|EVENT_NDIS_RESET_FAILURE_CORRECTION
value|0x800013AA
end_define

begin_comment
comment|/*  * NDIS OIDs used by the queryinfo/setinfo routines.  * Some are required by all NDIS drivers, some are specific to  * a particular type of device, and some are purely optional.  * Unfortunately, one of the purely optional OIDs is the one  * that lets us set the MAC address of the device.  */
end_comment

begin_comment
comment|/* Required OIDs */
end_comment

begin_define
define|#
directive|define
name|OID_GEN_SUPPORTED_LIST
value|0x00010101
end_define

begin_define
define|#
directive|define
name|OID_GEN_HARDWARE_STATUS
value|0x00010102
end_define

begin_define
define|#
directive|define
name|OID_GEN_MEDIA_SUPPORTED
value|0x00010103
end_define

begin_define
define|#
directive|define
name|OID_GEN_MEDIA_IN_USE
value|0x00010104
end_define

begin_define
define|#
directive|define
name|OID_GEN_MAXIMUM_LOOKAHEAD
value|0x00010105
end_define

begin_define
define|#
directive|define
name|OID_GEN_MAXIMUM_FRAME_SIZE
value|0x00010106
end_define

begin_define
define|#
directive|define
name|OID_GEN_LINK_SPEED
value|0x00010107
end_define

begin_define
define|#
directive|define
name|OID_GEN_TRANSMIT_BUFFER_SPACE
value|0x00010108
end_define

begin_define
define|#
directive|define
name|OID_GEN_RECEIVE_BUFFER_SPACE
value|0x00010109
end_define

begin_define
define|#
directive|define
name|OID_GEN_TRANSMIT_BLOCK_SIZE
value|0x0001010A
end_define

begin_define
define|#
directive|define
name|OID_GEN_RECEIVE_BLOCK_SIZE
value|0x0001010B
end_define

begin_define
define|#
directive|define
name|OID_GEN_VENDOR_ID
value|0x0001010C
end_define

begin_define
define|#
directive|define
name|OID_GEN_VENDOR_DESCRIPTION
value|0x0001010D
end_define

begin_define
define|#
directive|define
name|OID_GEN_CURRENT_PACKET_FILTER
value|0x0001010E
end_define

begin_define
define|#
directive|define
name|OID_GEN_CURRENT_LOOKAHEAD
value|0x0001010F
end_define

begin_define
define|#
directive|define
name|OID_GEN_DRIVER_VERSION
value|0x00010110
end_define

begin_define
define|#
directive|define
name|OID_GEN_MAXIMUM_TOTAL_SIZE
value|0x00010111
end_define

begin_define
define|#
directive|define
name|OID_GEN_PROTOCOL_OPTIONS
value|0x00010112
end_define

begin_define
define|#
directive|define
name|OID_GEN_MAC_OPTIONS
value|0x00010113
end_define

begin_define
define|#
directive|define
name|OID_GEN_MEDIA_CONNECT_STATUS
value|0x00010114
end_define

begin_define
define|#
directive|define
name|OID_GEN_MAXIMUM_SEND_PACKETS
value|0x00010115
end_define

begin_define
define|#
directive|define
name|OID_GEN_VENDOR_DRIVER_VERSION
value|0x00010116
end_define

begin_define
define|#
directive|define
name|OID_GEN_SUPPORTED_GUIDS
value|0x00010117
end_define

begin_define
define|#
directive|define
name|OID_GEN_NETWORK_LAYER_ADDRESSES
value|0x00010118
end_define

begin_comment
comment|/* Set only */
end_comment

begin_define
define|#
directive|define
name|OID_GEN_TRANSPORT_HEADER_OFFSET
value|0x00010119
end_define

begin_comment
comment|/* Set only */
end_comment

begin_define
define|#
directive|define
name|OID_GEN_MACHINE_NAME
value|0x0001021A
end_define

begin_define
define|#
directive|define
name|OID_GEN_RNDIS_CONFIG_PARAMETER
value|0x0001021B
end_define

begin_comment
comment|/* Set only */
end_comment

begin_define
define|#
directive|define
name|OID_GEN_VLAN_ID
value|0x0001021C
end_define

begin_comment
comment|/* Optional OIDs. */
end_comment

begin_define
define|#
directive|define
name|OID_GEN_MEDIA_CAPABILITIES
value|0x00010201
end_define

begin_define
define|#
directive|define
name|OID_GEN_PHYSICAL_MEDIUM
value|0x00010202
end_define

begin_comment
comment|/* Required statistics OIDs. */
end_comment

begin_define
define|#
directive|define
name|OID_GEN_XMIT_OK
value|0x00020101
end_define

begin_define
define|#
directive|define
name|OID_GEN_RCV_OK
value|0x00020102
end_define

begin_define
define|#
directive|define
name|OID_GEN_XMIT_ERROR
value|0x00020103
end_define

begin_define
define|#
directive|define
name|OID_GEN_RCV_ERROR
value|0x00020104
end_define

begin_define
define|#
directive|define
name|OID_GEN_RCV_NO_BUFFER
value|0x00020105
end_define

begin_comment
comment|/* Optional OID statistics */
end_comment

begin_define
define|#
directive|define
name|OID_GEN_DIRECTED_BYTES_XMIT
value|0x00020201
end_define

begin_define
define|#
directive|define
name|OID_GEN_DIRECTED_FRAMES_XMIT
value|0x00020202
end_define

begin_define
define|#
directive|define
name|OID_GEN_MULTICAST_BYTES_XMIT
value|0x00020203
end_define

begin_define
define|#
directive|define
name|OID_GEN_MULTICAST_FRAMES_XMIT
value|0x00020204
end_define

begin_define
define|#
directive|define
name|OID_GEN_BROADCAST_BYTES_XMIT
value|0x00020205
end_define

begin_define
define|#
directive|define
name|OID_GEN_BROADCAST_FRAMES_XMIT
value|0x00020206
end_define

begin_define
define|#
directive|define
name|OID_GEN_DIRECTED_BYTES_RCV
value|0x00020207
end_define

begin_define
define|#
directive|define
name|OID_GEN_DIRECTED_FRAMES_RCV
value|0x00020208
end_define

begin_define
define|#
directive|define
name|OID_GEN_MULTICAST_BYTES_RCV
value|0x00020209
end_define

begin_define
define|#
directive|define
name|OID_GEN_MULTICAST_FRAMES_RCV
value|0x0002020A
end_define

begin_define
define|#
directive|define
name|OID_GEN_BROADCAST_BYTES_RCV
value|0x0002020B
end_define

begin_define
define|#
directive|define
name|OID_GEN_BROADCAST_FRAMES_RCV
value|0x0002020C
end_define

begin_define
define|#
directive|define
name|OID_GEN_RCV_CRC_ERROR
value|0x0002020D
end_define

begin_define
define|#
directive|define
name|OID_GEN_TRANSMIT_QUEUE_LENGTH
value|0x0002020E
end_define

begin_define
define|#
directive|define
name|OID_GEN_GET_TIME_CAPS
value|0x0002020F
end_define

begin_define
define|#
directive|define
name|OID_GEN_GET_NETCARD_TIME
value|0x00020210
end_define

begin_define
define|#
directive|define
name|OID_GEN_NETCARD_LOAD
value|0x00020211
end_define

begin_define
define|#
directive|define
name|OID_GEN_DEVICE_PROFILE
value|0x00020212
end_define

begin_comment
comment|/* 802.3 (ethernet) OIDs */
end_comment

begin_define
define|#
directive|define
name|OID_802_3_PERMANENT_ADDRESS
value|0x01010101
end_define

begin_define
define|#
directive|define
name|OID_802_3_CURRENT_ADDRESS
value|0x01010102
end_define

begin_define
define|#
directive|define
name|OID_802_3_MULTICAST_LIST
value|0x01010103
end_define

begin_define
define|#
directive|define
name|OID_802_3_MAXIMUM_LIST_SIZE
value|0x01010104
end_define

begin_define
define|#
directive|define
name|OID_802_3_MAC_OPTIONS
value|0x01010105
end_define

begin_define
define|#
directive|define
name|NDIS_802_3_MAC_OPTION_PRIORITY
value|0x00000001
end_define

begin_define
define|#
directive|define
name|OID_802_3_RCV_ERROR_ALIGNMENT
value|0x01020101
end_define

begin_define
define|#
directive|define
name|OID_802_3_XMIT_ONE_COLLISION
value|0x01020102
end_define

begin_define
define|#
directive|define
name|OID_802_3_XMIT_MORE_COLLISIONS
value|0x01020103
end_define

begin_define
define|#
directive|define
name|OID_802_3_XMIT_DEFERRED
value|0x01020201
end_define

begin_define
define|#
directive|define
name|OID_802_3_XMIT_MAX_COLLISIONS
value|0x01020202
end_define

begin_define
define|#
directive|define
name|OID_802_3_RCV_OVERRUN
value|0x01020203
end_define

begin_define
define|#
directive|define
name|OID_802_3_XMIT_UNDERRUN
value|0x01020204
end_define

begin_define
define|#
directive|define
name|OID_802_3_XMIT_HEARTBEAT_FAILURE
value|0x01020205
end_define

begin_define
define|#
directive|define
name|OID_802_3_XMIT_TIMES_CRS_LOST
value|0x01020206
end_define

begin_define
define|#
directive|define
name|OID_802_3_XMIT_LATE_COLLISIONS
value|0x01020207
end_define

begin_comment
comment|/* PnP and power management OIDs */
end_comment

begin_define
define|#
directive|define
name|OID_PNP_CAPABILITIES
value|0xFD010100
end_define

begin_define
define|#
directive|define
name|OID_PNP_SET_POWER
value|0xFD010101
end_define

begin_define
define|#
directive|define
name|OID_PNP_QUERY_POWER
value|0xFD010102
end_define

begin_define
define|#
directive|define
name|OID_PNP_ADD_WAKE_UP_PATTERN
value|0xFD010103
end_define

begin_define
define|#
directive|define
name|OID_PNP_REMOVE_WAKE_UP_PATTERN
value|0xFD010104
end_define

begin_define
define|#
directive|define
name|OID_PNP_WAKE_UP_PATTERN_LIST
value|0xFD010105
end_define

begin_define
define|#
directive|define
name|OID_PNP_ENABLE_WAKE_UP
value|0xFD010106
end_define

begin_comment
comment|/*  * These are the possible power states for  * OID_PNP_SET_POWER and OID_PNP_QUERY_POWER.  */
end_comment

begin_define
define|#
directive|define
name|NDIS_POWERSTATE_UNSPEC
value|0
end_define

begin_define
define|#
directive|define
name|NDIS_POWERSTATE_D0
value|1
end_define

begin_define
define|#
directive|define
name|NDIS_POWERSTATE_D1
value|2
end_define

begin_define
define|#
directive|define
name|NDIS_POWERSTATE_D2
value|3
end_define

begin_define
define|#
directive|define
name|NDIS_POWERSTATE_D3
value|4
end_define

begin_comment
comment|/*  * These are used with the MiniportPnpEventNotify() method.  */
end_comment

begin_define
define|#
directive|define
name|NDIS_POWERPROFILE_BATTERY
value|0
end_define

begin_define
define|#
directive|define
name|NDIS_POWERPROFILE_ACONLINE
value|1
end_define

begin_define
define|#
directive|define
name|NDIS_PNP_EVENT_QUERY_REMOVED
value|0
end_define

begin_define
define|#
directive|define
name|NDIS_PNP_EVENT_REMOVED
value|1
end_define

begin_define
define|#
directive|define
name|NDIS_PNP_EVENT_SURPRISE_REMOVED
value|2
end_define

begin_define
define|#
directive|define
name|NDIS_PNP_EVENT_QUERY_STOPPED
value|3
end_define

begin_define
define|#
directive|define
name|NDIS_PNP_EVENT_STOPPED
value|4
end_define

begin_define
define|#
directive|define
name|NDIS_PNP_EVENT_PROFILECHANGED
value|5
end_define

begin_comment
comment|/* PnP/PM Statistics (Optional). */
end_comment

begin_define
define|#
directive|define
name|OID_PNP_WAKE_UP_OK
value|0xFD020200
end_define

begin_define
define|#
directive|define
name|OID_PNP_WAKE_UP_ERROR
value|0xFD020201
end_define

begin_comment
comment|/* The following bits are defined for OID_PNP_ENABLE_WAKE_UP */
end_comment

begin_define
define|#
directive|define
name|NDIS_PNP_WAKE_UP_MAGIC_PACKET
value|0x00000001
end_define

begin_define
define|#
directive|define
name|NDIS_PNP_WAKE_UP_PATTERN_MATCH
value|0x00000002
end_define

begin_define
define|#
directive|define
name|NDIS_PNP_WAKE_UP_LINK_CHANGE
value|0x00000004
end_define

begin_comment
comment|/* 802.11 OIDs */
end_comment

begin_define
define|#
directive|define
name|OID_802_11_BSSID
value|0x0D010101
end_define

begin_define
define|#
directive|define
name|OID_802_11_SSID
value|0x0D010102
end_define

begin_define
define|#
directive|define
name|OID_802_11_NETWORK_TYPES_SUPPORTED
value|0x0D010203
end_define

begin_define
define|#
directive|define
name|OID_802_11_NETWORK_TYPE_IN_USE
value|0x0D010204
end_define

begin_define
define|#
directive|define
name|OID_802_11_TX_POWER_LEVEL
value|0x0D010205
end_define

begin_define
define|#
directive|define
name|OID_802_11_RSSI
value|0x0D010206
end_define

begin_define
define|#
directive|define
name|OID_802_11_RSSI_TRIGGER
value|0x0D010207
end_define

begin_define
define|#
directive|define
name|OID_802_11_INFRASTRUCTURE_MODE
value|0x0D010108
end_define

begin_define
define|#
directive|define
name|OID_802_11_FRAGMENTATION_THRESHOLD
value|0x0D010209
end_define

begin_define
define|#
directive|define
name|OID_802_11_RTS_THRESHOLD
value|0x0D01020A
end_define

begin_define
define|#
directive|define
name|OID_802_11_NUMBER_OF_ANTENNAS
value|0x0D01020B
end_define

begin_define
define|#
directive|define
name|OID_802_11_RX_ANTENNA_SELECTED
value|0x0D01020C
end_define

begin_define
define|#
directive|define
name|OID_802_11_TX_ANTENNA_SELECTED
value|0x0D01020D
end_define

begin_define
define|#
directive|define
name|OID_802_11_SUPPORTED_RATES
value|0x0D01020E
end_define

begin_define
define|#
directive|define
name|OID_802_11_DESIRED_RATES
value|0x0D010210
end_define

begin_define
define|#
directive|define
name|OID_802_11_CONFIGURATION
value|0x0D010211
end_define

begin_define
define|#
directive|define
name|OID_802_11_STATISTICS
value|0x0D020212
end_define

begin_define
define|#
directive|define
name|OID_802_11_ADD_WEP
value|0x0D010113
end_define

begin_define
define|#
directive|define
name|OID_802_11_REMOVE_WEP
value|0x0D010114
end_define

begin_define
define|#
directive|define
name|OID_802_11_DISASSOCIATE
value|0x0D010115
end_define

begin_define
define|#
directive|define
name|OID_802_11_POWER_MODE
value|0x0D010216
end_define

begin_define
define|#
directive|define
name|OID_802_11_BSSID_LIST
value|0x0D010217
end_define

begin_define
define|#
directive|define
name|OID_802_11_AUTHENTICATION_MODE
value|0x0D010118
end_define

begin_define
define|#
directive|define
name|OID_802_11_PRIVACY_FILTER
value|0x0D010119
end_define

begin_define
define|#
directive|define
name|OID_802_11_BSSID_LIST_SCAN
value|0x0D01011A
end_define

begin_define
define|#
directive|define
name|OID_802_11_WEP_STATUS
value|0x0D01011B
end_define

begin_define
define|#
directive|define
name|OID_802_11_ENCRYPTION_STATUS
value|OID_802_11_WEP_STATUS
end_define

begin_define
define|#
directive|define
name|OID_802_11_RELOAD_DEFAULTS
value|0x0D01011C
end_define

begin_define
define|#
directive|define
name|OID_802_11_ADD_KEY
value|0x0D01011D
end_define

begin_define
define|#
directive|define
name|OID_802_11_REMOVE_KEY
value|0x0D01011E
end_define

begin_define
define|#
directive|define
name|OID_802_11_ASSOCIATION_INFORMATION
value|0x0D01011F
end_define

begin_define
define|#
directive|define
name|OID_802_11_TEST
value|0x0D010120
end_define

begin_define
define|#
directive|define
name|OID_802_11_CAPABILITY
value|0x0D010122
end_define

begin_define
define|#
directive|define
name|OID_802_11_PMKID
value|0x0D010123
end_define

begin_comment
comment|/* structures/definitions for 802.11 */
end_comment

begin_define
define|#
directive|define
name|NDIS_80211_NETTYPE_11FH
value|0x00000000
end_define

begin_define
define|#
directive|define
name|NDIS_80211_NETTYPE_11DS
value|0x00000001
end_define

begin_define
define|#
directive|define
name|NDIS_80211_NETTYPE_11OFDM5
value|0x00000002
end_define

begin_define
define|#
directive|define
name|NDIS_80211_NETTYPE_11OFDM24
value|0x00000003
end_define

begin_define
define|#
directive|define
name|NDIS_80211_NETTYPE_AUTO
value|0x00000004
end_define

begin_struct
struct|struct
name|ndis_80211_nettype_list
block|{
name|uint32_t
name|ntl_items
decl_stmt|;
name|uint32_t
name|ntl_type
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NDIS_80211_POWERMODE_CAM
value|0x00000000
end_define

begin_define
define|#
directive|define
name|NDIS_80211_POWERMODE_MAX_PSP
value|0x00000001
end_define

begin_define
define|#
directive|define
name|NDIS_80211_POWERMODE_FAST_PSP
value|0x00000002
end_define

begin_typedef
typedef|typedef
name|uint32_t
name|ndis_80211_power
typedef|;
end_typedef

begin_comment
comment|/* Power in milliwatts */
end_comment

begin_typedef
typedef|typedef
name|uint32_t
name|ndis_80211_rssi
typedef|;
end_typedef

begin_comment
comment|/* Signal strength in dBm */
end_comment

begin_struct
struct|struct
name|ndis_80211_config_fh
block|{
name|uint32_t
name|ncf_length
decl_stmt|;
name|uint32_t
name|ncf_hoppatterh
decl_stmt|;
name|uint32_t
name|ncf_hopset
decl_stmt|;
name|uint32_t
name|ncf_dwelltime
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ndis_80211_config_fh
name|ndis_80211_config_fh
typedef|;
end_typedef

begin_struct
struct|struct
name|ndis_80211_config
block|{
name|uint32_t
name|nc_length
decl_stmt|;
name|uint32_t
name|nc_beaconperiod
decl_stmt|;
name|uint32_t
name|nc_atimwin
decl_stmt|;
name|uint32_t
name|nc_dsconfig
decl_stmt|;
name|ndis_80211_config_fh
name|nc_fhconfig
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ndis_80211_config
name|ndis_80211_config
typedef|;
end_typedef

begin_struct
struct|struct
name|ndis_80211_stats
block|{
name|uint32_t
name|ns_length
decl_stmt|;
name|uint64_t
name|ns_txfragcnt
decl_stmt|;
name|uint64_t
name|ns_txmcastcnt
decl_stmt|;
name|uint64_t
name|ns_failedcnt
decl_stmt|;
name|uint64_t
name|ns_retrycnt
decl_stmt|;
name|uint64_t
name|ns_multiretrycnt
decl_stmt|;
name|uint64_t
name|ns_rtssuccesscnt
decl_stmt|;
name|uint64_t
name|ns_rtsfailcnt
decl_stmt|;
name|uint64_t
name|ns_ackfailcnt
decl_stmt|;
name|uint64_t
name|ns_dupeframecnt
decl_stmt|;
name|uint64_t
name|ns_rxfragcnt
decl_stmt|;
name|uint64_t
name|ns_rxmcastcnt
decl_stmt|;
name|uint64_t
name|ns_fcserrcnt
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ndis_80211_stats
name|ndis_80211_stats
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint32_t
name|ndis_80211_key_idx
typedef|;
end_typedef

begin_struct
struct|struct
name|ndis_80211_wep
block|{
name|uint32_t
name|nw_length
decl_stmt|;
name|uint32_t
name|nw_keyidx
decl_stmt|;
name|uint32_t
name|nw_keylen
decl_stmt|;
name|uint8_t
name|nw_keydata
index|[
literal|256
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ndis_80211_wep
name|ndis_80211_wep
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NDIS_80211_WEPKEY_TX
value|0x80000000
end_define

begin_define
define|#
directive|define
name|NDIS_80211_WEPKEY_PERCLIENT
value|0x40000000
end_define

begin_define
define|#
directive|define
name|NDIS_80211_NET_INFRA_IBSS
value|0x00000000
end_define

begin_define
define|#
directive|define
name|NDIS_80211_NET_INFRA_BSS
value|0x00000001
end_define

begin_define
define|#
directive|define
name|NDIS_80211_NET_INFRA_AUTO
value|0x00000002
end_define

begin_define
define|#
directive|define
name|NDIS_80211_AUTHMODE_OPEN
value|0x00000000
end_define

begin_define
define|#
directive|define
name|NDIS_80211_AUTHMODE_SHARED
value|0x00000001
end_define

begin_define
define|#
directive|define
name|NDIS_80211_AUTHMODE_AUTO
value|0x00000002
end_define

begin_define
define|#
directive|define
name|NDIS_80211_AUTHMODE_WPA
value|0x00000003
end_define

begin_define
define|#
directive|define
name|NDIS_80211_AUTHMODE_WPAPSK
value|0x00000004
end_define

begin_define
define|#
directive|define
name|NDIS_80211_AUTHMODE_WPANONE
value|0x00000005
end_define

begin_define
define|#
directive|define
name|NDIS_80211_AUTHMODE_WPA2
value|0x00000006
end_define

begin_define
define|#
directive|define
name|NDIS_80211_AUTHMODE_WPA2PSK
value|0x00000007
end_define

begin_typedef
typedef|typedef
name|uint8_t
name|ndis_80211_rates
index|[
literal|8
index|]
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint8_t
name|ndis_80211_rates_ex
index|[
literal|16
index|]
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint8_t
name|ndis_80211_macaddr
index|[
literal|6
index|]
typedef|;
end_typedef

begin_struct
struct|struct
name|ndis_80211_ssid
block|{
name|uint32_t
name|ns_ssidlen
decl_stmt|;
name|uint8_t
name|ns_ssid
index|[
literal|32
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ndis_80211_ssid
name|ndis_80211_ssid
typedef|;
end_typedef

begin_struct
struct|struct
name|ndis_wlan_bssid
block|{
name|uint32_t
name|nwb_length
decl_stmt|;
name|ndis_80211_macaddr
name|nwb_macaddr
decl_stmt|;
name|uint8_t
name|nwb_rsvd
index|[
literal|2
index|]
decl_stmt|;
name|ndis_80211_ssid
name|nwb_ssid
decl_stmt|;
name|uint32_t
name|nwb_privacy
decl_stmt|;
name|ndis_80211_rssi
name|nwb_rssi
decl_stmt|;
name|uint32_t
name|nwb_nettype
decl_stmt|;
name|ndis_80211_config
name|nwb_config
decl_stmt|;
name|uint32_t
name|nwb_netinfra
decl_stmt|;
name|ndis_80211_rates
name|nwb_supportedrates
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ndis_wlan_bssid
name|ndis_wlan_bssid
typedef|;
end_typedef

begin_struct
struct|struct
name|ndis_80211_bssid_list
block|{
name|uint32_t
name|nbl_items
decl_stmt|;
name|ndis_wlan_bssid
name|nbl_bssid
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ndis_80211_bssid_list
name|ndis_80211_bssid_list
typedef|;
end_typedef

begin_struct
struct|struct
name|ndis_wlan_bssid_ex
block|{
name|uint32_t
name|nwbx_len
decl_stmt|;
name|ndis_80211_macaddr
name|nwbx_macaddr
decl_stmt|;
name|uint8_t
name|nwbx_rsvd
index|[
literal|2
index|]
decl_stmt|;
name|ndis_80211_ssid
name|nwbx_ssid
decl_stmt|;
name|uint32_t
name|nwbx_privacy
decl_stmt|;
name|ndis_80211_rssi
name|nwbx_rssi
decl_stmt|;
name|uint32_t
name|nwbx_nettype
decl_stmt|;
name|ndis_80211_config
name|nwbx_config
decl_stmt|;
name|uint32_t
name|nwbx_netinfra
decl_stmt|;
name|ndis_80211_rates_ex
name|nwbx_supportedrates
decl_stmt|;
name|uint32_t
name|nwbx_ielen
decl_stmt|;
name|uint32_t
name|nwbx_ies
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ndis_wlan_bssid_ex
name|ndis_wlan_bssid_ex
typedef|;
end_typedef

begin_struct
struct|struct
name|ndis_80211_bssid_list_ex
block|{
name|uint32_t
name|nblx_items
decl_stmt|;
name|ndis_wlan_bssid_ex
name|nblx_bssid
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ndis_80211_bssid_list_ex
name|ndis_80211_bssid_list_ex
typedef|;
end_typedef

begin_struct
struct|struct
name|ndis_80211_fixed_ies
block|{
name|uint8_t
name|nfi_tstamp
index|[
literal|8
index|]
decl_stmt|;
name|uint16_t
name|nfi_beaconint
decl_stmt|;
name|uint16_t
name|nfi_caps
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ndis_80211_variable_ies
block|{
name|uint8_t
name|nvi_elemid
decl_stmt|;
name|uint8_t
name|nvi_len
decl_stmt|;
name|uint8_t
name|nvi_data
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|uint32_t
name|ndis_80211_fragthresh
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint32_t
name|ndis_80211_rtsthresh
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint32_t
name|ndis_80211_antenna
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NDIS_80211_PRIVFILT_ACCEPTALL
value|0x00000000
end_define

begin_define
define|#
directive|define
name|NDIS_80211_PRIVFILT_8021XWEP
value|0x00000001
end_define

begin_define
define|#
directive|define
name|NDIS_80211_WEPSTAT_ENABLED
value|0x00000000
end_define

begin_define
define|#
directive|define
name|NDIS_80211_WEPSTAT_ENC1ENABLED
value|NDIS_80211_WEPSTAT_ENABLED
end_define

begin_define
define|#
directive|define
name|NDIS_80211_WEPSTAT_DISABLED
value|0x00000001
end_define

begin_define
define|#
directive|define
name|NDIS_80211_WEPSTAT_ENCDISABLED
value|NDIS_80211_WEPSTAT_DISABLED
end_define

begin_define
define|#
directive|define
name|NDIS_80211_WEPSTAT_KEYABSENT
value|0x00000002
end_define

begin_define
define|#
directive|define
name|NDIS_80211_WEPSTAT_ENC1KEYABSENT
value|NDIS_80211_WEPSTAT_KEYABSENT
end_define

begin_define
define|#
directive|define
name|NDIS_80211_WEPSTAT_NOTSUPPORTED
value|0x00000003
end_define

begin_define
define|#
directive|define
name|NDIS_80211_WEPSTAT_ENCNOTSUPPORTED
value|NDIS_80211_WEPSTAT_NOTSUPPORTED
end_define

begin_define
define|#
directive|define
name|NDIS_80211_WEPSTAT_ENC2ENABLED
value|0x00000004
end_define

begin_define
define|#
directive|define
name|NDIS_80211_WEPSTAT_ENC2KEYABSENT
value|0x00000005
end_define

begin_define
define|#
directive|define
name|NDIS_80211_WEPSTAT_ENC3ENABLED
value|0x00000006
end_define

begin_define
define|#
directive|define
name|NDIS_80211_WEPSTAT_ENC3KEYABSENT
value|0x00000007
end_define

begin_define
define|#
directive|define
name|NDIS_80211_RELOADDEFAULT_WEP
value|0x00000000
end_define

begin_define
define|#
directive|define
name|NDIS_80211_STATUSTYPE_AUTH
value|0x00000000
end_define

begin_define
define|#
directive|define
name|NDIS_80211_STATUSTYPE_PMKIDLIST
value|0x00000001
end_define

begin_struct
struct|struct
name|ndis_80211_status_indication
block|{
name|uint32_t
name|nsi_type
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ndis_80211_status_indication
name|ndis_80211_status_indication
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NDIS_802_11_AUTH_REQUEST_REAUTH
value|0x01
end_define

begin_define
define|#
directive|define
name|NDIS_802_11_AUTH_REQUEST_KEYUPDATE
value|0x02
end_define

begin_define
define|#
directive|define
name|NDIS_802_11_AUTH_REQUEST_PAIRWISE_ERROR
value|0x06
end_define

begin_define
define|#
directive|define
name|NDIS_802_11_AUTH_REQUEST_GROUP_ERROR
value|0x0E
end_define

begin_struct
struct|struct
name|ndis_80211_auth_request
block|{
name|uint32_t
name|nar_len
decl_stmt|;
name|ndis_80211_macaddr
name|nar_bssid
decl_stmt|;
name|uint32_t
name|nar_flags
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ndis_80211_auth_request
name|ndis_80211_auth_request
typedef|;
end_typedef

begin_struct
struct|struct
name|ndis_80211_key
block|{
name|uint32_t
name|nk_len
decl_stmt|;
name|uint32_t
name|nk_keyidx
decl_stmt|;
name|uint32_t
name|nk_keylen
decl_stmt|;
name|ndis_80211_macaddr
name|nk_bssid
decl_stmt|;
name|uint8_t
name|nk_pad
index|[
literal|6
index|]
decl_stmt|;
name|uint64_t
name|nk_keyrsc
decl_stmt|;
name|uint8_t
name|nk_keydata
index|[
literal|32
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ndis_80211_key
name|ndis_80211_key
typedef|;
end_typedef

begin_struct
struct|struct
name|ndis_80211_remove_key
block|{
name|uint32_t
name|nk_len
decl_stmt|;
name|uint32_t
name|nk_keyidx
decl_stmt|;
name|ndis_80211_macaddr
name|nk_bssid
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ndis_80211_remove_key
name|ndis_80211_remove_key
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NDIS_80211_AI_REQFI_CAPABILITIES
value|0x00000001
end_define

begin_define
define|#
directive|define
name|NDIS_80211_AI_REQFI_LISTENINTERVAL
value|0x00000002
end_define

begin_define
define|#
directive|define
name|NDIS_80211_AI_REQFI_CURRENTAPADDRESS
value|0x00000004
end_define

begin_define
define|#
directive|define
name|NDIS_80211_AI_RESFI_CAPABILITIES
value|0x00000001
end_define

begin_define
define|#
directive|define
name|NDIS_80211_AI_RESFI_STATUSCODE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|NDIS_80211_AI_RESFI_ASSOCIATIONID
value|0x00000004
end_define

begin_struct
struct|struct
name|ndis_80211_ai_reqfi
block|{
name|uint16_t
name|naq_caps
decl_stmt|;
name|uint16_t
name|naq_listentint
decl_stmt|;
name|ndis_80211_macaddr
name|naq_currentapaddr
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ndis_80211_ai_reqfi
name|ndis_80211_ai_reqfi
typedef|;
end_typedef

begin_struct
struct|struct
name|ndis_80211_ai_resfi
block|{
name|uint16_t
name|nas_caps
decl_stmt|;
name|uint16_t
name|nas_statuscode
decl_stmt|;
name|uint16_t
name|nas_associd
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ndis_80211_ai_resfi
name|ndis_80211_ai_resfi
typedef|;
end_typedef

begin_struct
struct|struct
name|ndis_80211_assoc_info
block|{
name|uint32_t
name|nai_len
decl_stmt|;
name|uint16_t
name|nai_avail_req_fixed_ies
decl_stmt|;
name|ndis_80211_ai_reqfi
name|nai_req_fixed_ies
decl_stmt|;
name|uint32_t
name|nai_req_ielen
decl_stmt|;
name|uint32_t
name|nai_offset_req_ies
decl_stmt|;
name|uint16_t
name|nai_avail_resp_fixed_ies
decl_stmt|;
name|ndis_80211_ai_resfi
name|nai_resp_fixed_iex
decl_stmt|;
name|uint32_t
name|nai_resp_ielen
decl_stmt|;
name|uint32_t
name|nai_offset_resp_ies
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ndis_80211_assoc_info
name|ndis_80211_assoc_info
typedef|;
end_typedef

begin_struct
struct|struct
name|ndis_80211_auth_event
block|{
name|ndis_80211_status_indication
name|nae_status
decl_stmt|;
name|ndis_80211_auth_request
name|nae_request
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ndis_80211_auth_event
name|ndis_80211_auth_event
typedef|;
end_typedef

begin_struct
struct|struct
name|ndis_80211_test
block|{
name|uint32_t
name|nt_len
decl_stmt|;
name|uint32_t
name|nt_type
decl_stmt|;
union|union
block|{
name|ndis_80211_auth_event
name|nt_authevent
decl_stmt|;
name|uint32_t
name|nt_rssitrigger
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
name|ndis_80211_test
name|ndis_80211_test
typedef|;
end_typedef

begin_struct
struct|struct
name|ndis_80211_auth_encrypt
block|{
name|uint32_t
name|ne_authmode
decl_stmt|;
name|uint32_t
name|ne_cryptstat
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ndis_80211_auth_encrypt
name|ndis_80211_auth_encrypt
typedef|;
end_typedef

begin_struct
struct|struct
name|ndis_80211_caps
block|{
name|uint32_t
name|nc_len
decl_stmt|;
name|uint32_t
name|nc_ver
decl_stmt|;
name|uint32_t
name|nc_numpmkids
decl_stmt|;
name|ndis_80211_auth_encrypt
name|nc_authencs
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ndis_80211_caps
name|ndis_80211_caps
typedef|;
end_typedef

begin_struct
struct|struct
name|ndis_80211_bssidinfo
block|{
name|ndis_80211_macaddr
name|nb_bssid
decl_stmt|;
name|uint8_t
name|nb_pmkid
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
name|ndis_80211_bssidinfo
name|ndis_80211_bssidinfo
typedef|;
end_typedef

begin_struct
struct|struct
name|ndis_80211_pmkid
block|{
name|uint32_t
name|np_len
decl_stmt|;
name|uint32_t
name|np_bssidcnt
decl_stmt|;
name|ndis_80211_bssidinfo
name|np_bssidinfo
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ndis_80211_pmkid
name|ndis_80211_pmkid
typedef|;
end_typedef

begin_struct
struct|struct
name|ndis_80211_pmkid_cand
block|{
name|ndis_80211_macaddr
name|npc_bssid
decl_stmt|;
name|uint32_t
name|npc_flags
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ndis_80211_pmkid_cand
name|ndis_80211_pmkid_cand
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NDIS_802_11_PMKID_CANDIDATE_PREAUTH_ENABLED
value|(0x01)
end_define

begin_struct
struct|struct
name|ndis_80211_pmkid_candidate_list
block|{
name|uint32_t
name|npcl_version
decl_stmt|;
name|uint32_t
name|npcl_numcandidates
decl_stmt|;
name|ndis_80211_pmkid_cand
name|npcl_candidatelist
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ndis_80211_pmkid_candidate_list
name|ndis_80211_pmkid_candidate_list
typedef|;
end_typedef

begin_struct
struct|struct
name|ndis_80211_enc_indication
block|{
name|uint32_t
name|nei_statustype
decl_stmt|;
name|ndis_80211_pmkid_candidate_list
name|nei_pmkidlist
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ndis_80211_enc_indication
name|ndis_80211_enc_indication
typedef|;
end_typedef

begin_comment
comment|/* TCP OIDs. */
end_comment

begin_define
define|#
directive|define
name|OID_TCP_TASK_OFFLOAD
value|0xFC010201
end_define

begin_define
define|#
directive|define
name|OID_TCP_TASK_IPSEC_ADD_SA
value|0xFC010202
end_define

begin_define
define|#
directive|define
name|OID_TCP_TASK_IPSEC_DELETE_SA
value|0xFC010203
end_define

begin_define
define|#
directive|define
name|OID_TCP_SAN_SUPPORT
value|0xFC010204
end_define

begin_define
define|#
directive|define
name|NDIS_TASK_OFFLOAD_VERSION
value|1
end_define

begin_define
define|#
directive|define
name|NDIS_TASK_TCPIP_CSUM
value|0x00000000
end_define

begin_define
define|#
directive|define
name|NDIS_TASK_IPSEC
value|0x00000001
end_define

begin_define
define|#
directive|define
name|NDIS_TASK_TCP_LARGESEND
value|0x00000002
end_define

begin_define
define|#
directive|define
name|NDIS_ENCAP_UNSPEC
value|0x00000000
end_define

begin_define
define|#
directive|define
name|NDIS_ENCAP_NULL
value|0x00000001
end_define

begin_define
define|#
directive|define
name|NDIS_ENCAP_IEEE802_3
value|0x00000002
end_define

begin_define
define|#
directive|define
name|NDIS_ENCAP_IEEE802_5
value|0x00000003
end_define

begin_define
define|#
directive|define
name|NDIS_ENCAP_SNAP_ROUTED
value|0x00000004
end_define

begin_define
define|#
directive|define
name|NDIS_ENCAP_SNAP_BRIDGED
value|0x00000005
end_define

begin_define
define|#
directive|define
name|NDIS_ENCAPFLAG_FIXEDHDRLEN
value|0x00000001
end_define

begin_struct
struct|struct
name|ndis_encap_fmt
block|{
name|uint32_t
name|nef_encap
decl_stmt|;
name|uint32_t
name|nef_flags
decl_stmt|;
name|uint32_t
name|nef_encaphdrlen
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ndis_encap_fmt
name|ndis_encap_fmt
typedef|;
end_typedef

begin_struct
struct|struct
name|ndis_task_offload_hdr
block|{
name|uint32_t
name|ntoh_vers
decl_stmt|;
name|uint32_t
name|ntoh_len
decl_stmt|;
name|uint32_t
name|ntoh_rsvd
decl_stmt|;
name|uint32_t
name|ntoh_offset_firsttask
decl_stmt|;
name|ndis_encap_fmt
name|ntoh_encapfmt
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ndis_task_offload_hdr
name|ndis_task_offload_hdr
typedef|;
end_typedef

begin_struct
struct|struct
name|ndis_task_offload
block|{
name|uint32_t
name|nto_vers
decl_stmt|;
name|uint32_t
name|nto_len
decl_stmt|;
name|uint32_t
name|nto_task
decl_stmt|;
name|uint32_t
name|nto_offset_nexttask
decl_stmt|;
name|uint32_t
name|nto_taskbuflen
decl_stmt|;
name|uint8_t
name|nto_taskbuf
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ndis_task_offload
name|ndis_task_offload
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NDIS_TCPSUM_FLAGS_IP_OPTS
value|0x00000001
end_define

begin_define
define|#
directive|define
name|NDIS_TCPSUM_FLAGS_TCP_OPTS
value|0x00000002
end_define

begin_define
define|#
directive|define
name|NDIS_TCPSUM_FLAGS_TCP_CSUM
value|0x00000004
end_define

begin_define
define|#
directive|define
name|NDIS_TCPSUM_FLAGS_UDP_CSUM
value|0x00000008
end_define

begin_define
define|#
directive|define
name|NDIS_TCPSUM_FLAGS_IP_CSUM
value|0x00000010
end_define

begin_struct
struct|struct
name|ndis_task_tcpip_csum
block|{
name|uint32_t
name|nttc_v4tx
decl_stmt|;
name|uint32_t
name|nttc_v4rx
decl_stmt|;
name|uint32_t
name|nttc_v6tx
decl_stmt|;
name|uint32_t
name|nttc_v6rx
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ndis_task_tcpip_csum
name|ndis_task_tcpip_csum
typedef|;
end_typedef

begin_struct
struct|struct
name|ndis_task_tcp_largesend
block|{
name|uint32_t
name|nttl_vers
decl_stmt|;
name|uint32_t
name|nttl_maxofflen
decl_stmt|;
name|uint32_t
name|nttl_minsegcnt
decl_stmt|;
name|uint8_t
name|nttl_tcpopt
decl_stmt|;
name|uint8_t
name|nttl_ipopt
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ndis_task_tcp_largesend
name|ndis_task_tcp_largesend
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NDIS_IPSEC_AH_MD5
value|0x00000001
end_define

begin_define
define|#
directive|define
name|NDIS_IPSEC_AH_SHA1
value|0x00000002
end_define

begin_define
define|#
directive|define
name|NDIS_IPSEC_AH_TRANSPORT
value|0x00000004
end_define

begin_define
define|#
directive|define
name|NDIS_IPSEC_AH_TUNNEL
value|0x00000008
end_define

begin_define
define|#
directive|define
name|NDIS_IPSEC_AH_SEND
value|0x00000010
end_define

begin_define
define|#
directive|define
name|NDIS_IPSEC_AH_RECEIVE
value|0x00000020
end_define

begin_define
define|#
directive|define
name|NDIS_IPSEC_ESP_DES
value|0x00000001
end_define

begin_define
define|#
directive|define
name|NDIS_IPSEC_ESP_RSVD
value|0x00000002
end_define

begin_define
define|#
directive|define
name|NDIS_IPSEC_ESP_3DES
value|0x00000004
end_define

begin_define
define|#
directive|define
name|NDIS_IPSEC_ESP_NULL
value|0x00000008
end_define

begin_define
define|#
directive|define
name|NDIS_IPSEC_ESP_TRANSPORT
value|0x00000010
end_define

begin_define
define|#
directive|define
name|NDIS_IPSEC_ESP_TUNNEL
value|0x00000020
end_define

begin_define
define|#
directive|define
name|NDIS_IPSEC_ESP_SEND
value|0x00000040
end_define

begin_define
define|#
directive|define
name|NDIS_IPSEC_ESP_RECEIVE
value|0x00000080
end_define

begin_struct
struct|struct
name|ndis_task_ipsec
block|{
name|uint32_t
name|nti_ah_esp_combined
decl_stmt|;
name|uint32_t
name|nti_ah_transport_tunnel_combined
decl_stmt|;
name|uint32_t
name|nti_v4_options
decl_stmt|;
name|uint32_t
name|nti_rsvd
decl_stmt|;
name|uint32_t
name|nti_v4ah
decl_stmt|;
name|uint32_t
name|nti_v4esp
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ndis_task_ipsec
name|ndis_task_ipsec
typedef|;
end_typedef

begin_comment
comment|/*  * Attribures of NDIS drivers. Not all drivers support  * all attributes.  */
end_comment

begin_define
define|#
directive|define
name|NDIS_ATTRIBUTE_IGNORE_PACKET_TIMEOUT
value|0x00000001
end_define

begin_define
define|#
directive|define
name|NDIS_ATTRIBUTE_IGNORE_REQUEST_TIMEOUT
value|0x00000002
end_define

begin_define
define|#
directive|define
name|NDIS_ATTRIBUTE_IGNORE_TOKEN_RING_ERRORS
value|0x00000004
end_define

begin_define
define|#
directive|define
name|NDIS_ATTRIBUTE_BUS_MASTER
value|0x00000008
end_define

begin_define
define|#
directive|define
name|NDIS_ATTRIBUTE_INTERMEDIATE_DRIVER
value|0x00000010
end_define

begin_define
define|#
directive|define
name|NDIS_ATTRIBUTE_DESERIALIZE
value|0x00000020
end_define

begin_define
define|#
directive|define
name|NDIS_ATTRIBUTE_NO_HALT_ON_SUSPEND
value|0x00000040
end_define

begin_define
define|#
directive|define
name|NDIS_ATTRIBUTE_SURPRISE_REMOVE_OK
value|0x00000080
end_define

begin_define
define|#
directive|define
name|NDIS_ATTRIBUTE_NOT_CO_NDIS
value|0x00000100
end_define

begin_define
define|#
directive|define
name|NDIS_ATTRIBUTE_USES_SAFE_BUFFER_APIS
value|0x00000200
end_define

begin_define
define|#
directive|define
name|NDIS_SERIALIZED
parameter_list|(
name|block
parameter_list|)
define|\
value|(((block)->nmb_flags& NDIS_ATTRIBUTE_DESERIALIZE) == 0)
end_define

begin_enum
enum|enum
name|ndis_media_state
block|{
name|nmc_connected
block|,
name|nmc_disconnected
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|enum
name|ndis_media_state
name|ndis_media_state
typedef|;
end_typedef

begin_comment
comment|/* Ndis Packet Filter Bits (OID_GEN_CURRENT_PACKET_FILTER). */
end_comment

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
value|0x00001000
end_define

begin_define
define|#
directive|define
name|NDIS_PACKET_TYPE_ALL_FUNCTIONAL
value|0x00002000
end_define

begin_define
define|#
directive|define
name|NDIS_PACKET_TYPE_FUNCTIONAL
value|0x00004000
end_define

begin_define
define|#
directive|define
name|NDIS_PACKET_TYPE_MAC_FRAME
value|0x00008000
end_define

begin_comment
comment|/* Ndis MAC option bits (OID_GEN_MAC_OPTIONS). */
end_comment

begin_define
define|#
directive|define
name|NDIS_MAC_OPTION_COPY_LOOKAHEAD_DATA
value|0x00000001
end_define

begin_define
define|#
directive|define
name|NDIS_MAC_OPTION_RECEIVE_SERIALIZED
value|0x00000002
end_define

begin_define
define|#
directive|define
name|NDIS_MAC_OPTION_TRANSFERS_NOT_PEND
value|0x00000004
end_define

begin_define
define|#
directive|define
name|NDIS_MAC_OPTION_NO_LOOPBACK
value|0x00000008
end_define

begin_define
define|#
directive|define
name|NDIS_MAC_OPTION_FULL_DUPLEX
value|0x00000010
end_define

begin_define
define|#
directive|define
name|NDIS_MAC_OPTION_EOTX_INDICATION
value|0x00000020
end_define

begin_define
define|#
directive|define
name|NDIS_MAC_OPTION_8021P_PRIORITY
value|0x00000040
end_define

begin_define
define|#
directive|define
name|NDIS_MAC_OPTION_SUPPORTS_MAC_ADDRESS_OVERWRITE
value|0x00000080
end_define

begin_define
define|#
directive|define
name|NDIS_MAC_OPTION_RECEIVE_AT_DPC
value|0x00000100
end_define

begin_define
define|#
directive|define
name|NDIS_MAC_OPTION_8021Q_VLAN
value|0x00000200
end_define

begin_define
define|#
directive|define
name|NDIS_MAC_OPTION_RESERVED
value|0x80000000
end_define

begin_define
define|#
directive|define
name|NDIS_DMA_24BITS
value|0x00
end_define

begin_define
define|#
directive|define
name|NDIS_DMA_32BITS
value|0x01
end_define

begin_define
define|#
directive|define
name|NDIS_DMA_64BITS
value|0x02
end_define

begin_comment
comment|/* struct ndis_physaddr { #ifdef __i386__ 	uint64_t		np_quad; #endif #ifdef __amd64__ 	uint32_t		np_low; 	uint32_t		np_high; #define np_quad np_low #endif #ifdef notdef 	uint32_t		np_low; 	uint32_t		np_high; #endif }; */
end_comment

begin_typedef
typedef|typedef
name|struct
name|physaddr
name|ndis_physaddr
typedef|;
end_typedef

begin_struct
struct|struct
name|ndis_ansi_string
block|{
name|uint16_t
name|nas_len
decl_stmt|;
name|uint16_t
name|nas_maxlen
decl_stmt|;
name|char
modifier|*
name|nas_buf
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ndis_ansi_string
name|ndis_ansi_string
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|notdef
end_ifdef

begin_comment
comment|/*  * nus_buf is really a wchar_t *, but it's inconvenient to include  * all the necessary header goop needed to define it, and it's a  * pointer anyway, so for now, just make it a uint16_t *.  */
end_comment

begin_struct
struct|struct
name|ndis_unicode_string
block|{
name|uint16_t
name|nus_len
decl_stmt|;
name|uint16_t
name|nus_maxlen
decl_stmt|;
name|uint16_t
modifier|*
name|nus_buf
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ndis_unicode_string
name|ndis_unicode_string
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|unicode_string
name|ndis_unicode_string
typedef|;
end_typedef

begin_enum
enum|enum
name|ndis_parm_type
block|{
name|ndis_parm_int
block|,
name|ndis_parm_hexint
block|,
name|ndis_parm_string
block|,
name|ndis_parm_multistring
block|,
name|ndis_parm_binary
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|enum
name|ndis_parm_type
name|ndis_parm_type
typedef|;
end_typedef

begin_struct
struct|struct
name|ndis_binary_data
block|{
name|uint16_t
name|nbd_len
decl_stmt|;
name|void
modifier|*
name|nbd_buf
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ndis_binary_data
name|ndis_binary_data
typedef|;
end_typedef

begin_struct
struct|struct
name|ndis_config_parm
block|{
name|ndis_parm_type
name|ncp_type
decl_stmt|;
union|union
block|{
name|uint32_t
name|ncp_intdata
decl_stmt|;
name|ndis_unicode_string
name|ncp_stringdata
decl_stmt|;
name|ndis_binary_data
name|ncp_binarydata
decl_stmt|;
block|}
name|ncp_parmdata
union|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Not part of Windows NDIS spec; we uses this to keep a  * list of ndis_config_parm structures that we've allocated.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|ndis_config_parm
name|ndis_config_parm
typedef|;
end_typedef

begin_struct
struct|struct
name|ndis_parmlist_entry
block|{
name|list_entry
name|np_list
decl_stmt|;
name|ndis_config_parm
name|np_parm
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ndis_parmlist_entry
name|ndis_parmlist_entry
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|notdef
end_ifdef

begin_struct
struct|struct
name|ndis_list_entry
block|{
name|struct
name|ndis_list_entry
modifier|*
name|nle_flink
decl_stmt|;
name|struct
name|ndis_list_entry
modifier|*
name|nle_blink
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ndis_list_entry
name|ndis_list_entry
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|ndis_bind_paths
block|{
name|uint32_t
name|nbp_number
decl_stmt|;
name|ndis_unicode_string
name|nbp_paths
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ndis_bind_paths
name|ndis_bind_paths
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|notdef
end_ifdef

begin_struct
struct|struct
name|dispatch_header
block|{
name|uint8_t
name|dh_type
decl_stmt|;
name|uint8_t
name|dh_abs
decl_stmt|;
name|uint8_t
name|dh_size
decl_stmt|;
name|uint8_t
name|dh_inserted
decl_stmt|;
name|uint32_t
name|dh_sigstate
decl_stmt|;
name|list_entry
name|dh_waitlisthead
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|dispatch_header
value|nt_dispatch_header
end_define

begin_struct
struct|struct
name|ndis_ktimer
block|{
name|struct
name|dispatch_header
name|nk_header
decl_stmt|;
name|uint64_t
name|nk_duetime
decl_stmt|;
name|list_entry
name|nk_timerlistentry
decl_stmt|;
name|void
modifier|*
name|nk_dpc
decl_stmt|;
name|uint32_t
name|nk_period
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ndis_kevent
block|{
name|struct
name|dispatch_header
name|nk_header
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ndis_event
block|{
name|struct
name|nt_kevent
name|ne_event
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ndis_event
name|ndis_event
typedef|;
end_typedef

begin_comment
comment|/* Kernel defered procedure call (i.e. timer callback) */
end_comment

begin_struct_decl
struct_decl|struct
name|ndis_kdpc
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|ndis_kdpc_func
function_decl|)
parameter_list|(
name|struct
name|ndis_kdpc
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|ndis_kdpc
block|{
name|uint16_t
name|nk_type
decl_stmt|;
name|uint8_t
name|nk_num
decl_stmt|;
name|uint8_t
name|nk_importance
decl_stmt|;
name|list_entry
name|nk_dpclistentry
decl_stmt|;
name|ndis_kdpc_func
name|nk_deferedfunc
decl_stmt|;
name|void
modifier|*
name|nk_deferredctx
decl_stmt|;
name|void
modifier|*
name|nk_sysarg1
decl_stmt|;
name|void
modifier|*
name|nk_sysarg2
decl_stmt|;
name|uint32_t
modifier|*
name|nk_lock
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ndis_timer
block|{
name|struct
name|ktimer
name|nt_ktimer
decl_stmt|;
name|struct
name|kdpc
name|nt_kdpc
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ndis_timer
name|ndis_timer
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|ndis_timer_function
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|ndis_miniport_timer
block|{
name|struct
name|ktimer
name|nmt_ktimer
decl_stmt|;
name|struct
name|kdpc
name|nmt_kdpc
decl_stmt|;
name|ndis_timer_function
name|nmt_timerfunc
decl_stmt|;
name|void
modifier|*
name|nmt_timerctx
decl_stmt|;
name|ndis_miniport_block
modifier|*
name|nmt_block
decl_stmt|;
name|struct
name|ndis_miniport_timer
modifier|*
name|nmt_nexttimer
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ndis_miniport_timer
name|ndis_miniport_timer
typedef|;
end_typedef

begin_struct
struct|struct
name|ndis_spin_lock
block|{
name|ndis_kspin_lock
name|nsl_spinlock
decl_stmt|;
name|ndis_kirql
name|nsl_kirql
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ndis_spin_lock
name|ndis_spin_lock
typedef|;
end_typedef

begin_struct
struct|struct
name|ndis_rw_lock
block|{
union|union
block|{
name|kspin_lock
name|nrl_spinlock
decl_stmt|;
name|void
modifier|*
name|nrl_ctx
decl_stmt|;
block|}
name|u
union|;
name|uint8_t
name|nrl_rsvd
index|[
literal|16
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|nrl_spinlock
value|u.nrl_spinlock
end_define

begin_define
define|#
directive|define
name|nrl_ctx
value|u.nrl_ctx;
end_define

begin_typedef
typedef|typedef
name|struct
name|ndis_rw_lock
name|ndis_rw_lock
typedef|;
end_typedef

begin_struct
struct|struct
name|ndis_lock_state
block|{
name|uint16_t
name|nls_lockstate
decl_stmt|;
name|ndis_kirql
name|nls_oldirql
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ndis_lock_state
name|ndis_lock_state
typedef|;
end_typedef

begin_struct
struct|struct
name|ndis_request
block|{
name|uint8_t
name|nr_macreserved
index|[
literal|4
operator|*
sizeof|sizeof
argument_list|(
name|void
operator|*
argument_list|)
index|]
decl_stmt|;
name|uint32_t
name|nr_requesttype
decl_stmt|;
union|union
name|_ndis_data
block|{
struct|struct
name|_ndis_query_information
block|{
name|ndis_oid
name|nr_oid
decl_stmt|;
name|void
modifier|*
name|nr_infobuf
decl_stmt|;
name|uint32_t
name|nr_infobuflen
decl_stmt|;
name|uint32_t
name|nr_byteswritten
decl_stmt|;
name|uint32_t
name|nr_bytesneeded
decl_stmt|;
block|}
name|ndis_query_information
struct|;
struct|struct
name|_ndis_set_information
block|{
name|ndis_oid
name|nr_oid
decl_stmt|;
name|void
modifier|*
name|nr_infobuf
decl_stmt|;
name|uint32_t
name|nr_infobuflen
decl_stmt|;
name|uint32_t
name|nr_byteswritten
decl_stmt|;
name|uint32_t
name|nr_bytesneeded
decl_stmt|;
block|}
name|ndis_set_information
struct|;
block|}
name|ndis_data
union|;
comment|/* NDIS 5.0 extentions */
name|uint8_t
name|nr_ndis_rsvd
index|[
literal|9
operator|*
sizeof|sizeof
argument_list|(
name|void
operator|*
argument_list|)
index|]
decl_stmt|;
union|union
block|{
name|uint8_t
name|nr_callmgr_rsvd
index|[
literal|2
operator|*
sizeof|sizeof
argument_list|(
name|void
operator|*
argument_list|)
index|]
decl_stmt|;
name|uint8_t
name|nr_protocol_rsvd
index|[
literal|2
operator|*
sizeof|sizeof
argument_list|(
name|void
operator|*
argument_list|)
index|]
decl_stmt|;
block|}
name|u
union|;
name|uint8_t
name|nr_miniport_rsvd
index|[
literal|2
operator|*
sizeof|sizeof
argument_list|(
name|void
operator|*
argument_list|)
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ndis_request
name|ndis_request
typedef|;
end_typedef

begin_comment
comment|/*  * Filler, not used.  */
end_comment

begin_struct
struct|struct
name|ndis_miniport_interrupt
block|{
name|kinterrupt
modifier|*
name|ni_introbj
decl_stmt|;
name|ndis_kspin_lock
name|ni_dpccountlock
decl_stmt|;
name|void
modifier|*
name|ni_rsvd
decl_stmt|;
name|void
modifier|*
name|ni_isrfunc
decl_stmt|;
name|void
modifier|*
name|ni_dpcfunc
decl_stmt|;
name|kdpc
name|ni_dpc
decl_stmt|;
name|ndis_miniport_block
modifier|*
name|ni_block
decl_stmt|;
name|uint8_t
name|ni_dpccnt
decl_stmt|;
name|uint8_t
name|ni_filler1
decl_stmt|;
name|struct
name|nt_kevent
name|ni_dpcevt
decl_stmt|;
name|uint8_t
name|ni_shared
decl_stmt|;
name|uint8_t
name|ni_isrreq
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ndis_miniport_interrupt
name|ndis_miniport_interrupt
typedef|;
end_typedef

begin_enum
enum|enum
name|ndis_interrupt_mode
block|{
name|nim_level
block|,
name|nim_latched
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|enum
name|ndis_interrupt_mode
name|ndis_interrupt_mode
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NUMBER_OF_SINGLE_WORK_ITEMS
value|6
end_define

begin_struct_decl
struct_decl|struct
name|ndis_work_item
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|ndis_proc
function_decl|)
parameter_list|(
name|struct
name|ndis_work_item
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|ndis_work_item
block|{
name|void
modifier|*
name|nwi_ctx
decl_stmt|;
name|ndis_proc
name|nwi_func
decl_stmt|;
name|uint8_t
name|nwi_wraprsvd
index|[
sizeof|sizeof
argument_list|(
name|void
operator|*
argument_list|)
operator|*
literal|8
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ndis_work_item
name|ndis_work_item
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NdisInitializeWorkItem
parameter_list|(
name|w
parameter_list|,
name|f
parameter_list|,
name|c
parameter_list|)
define|\
value|do {				\ 		(w)->nwi_ctx = c;	\ 		(w)->nwi_func = f;	\ 	} while (0)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|notdef
end_ifdef

begin_struct
struct|struct
name|ndis_buffer
block|{
name|struct
name|ndis_buffer
modifier|*
name|nb_next
decl_stmt|;
name|uint16_t
name|nb_size
decl_stmt|;
name|uint16_t
name|nb_flags
decl_stmt|;
name|void
modifier|*
name|nb_process
decl_stmt|;
name|void
modifier|*
name|nb_mappedsystemva
decl_stmt|;
name|void
modifier|*
name|nb_startva
decl_stmt|;
name|uint32_t
name|nb_bytecount
decl_stmt|;
name|uint32_t
name|nb_byteoffset
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ndis_buffer
name|ndis_buffer
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|ndis_sc_element
block|{
name|ndis_physaddr
name|nse_addr
decl_stmt|;
name|uint32_t
name|nse_len
decl_stmt|;
name|uint32_t
modifier|*
name|nse_rsvd
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ndis_sc_element
name|ndis_sc_element
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NDIS_MAXSEG
value|32
end_define

begin_define
define|#
directive|define
name|NDIS_BUS_SPACE_SHARED_MAXADDR
value|0x3E7FFFFF
end_define

begin_struct
struct|struct
name|ndis_sc_list
block|{
name|uint32_t
name|nsl_frags
decl_stmt|;
name|uint32_t
modifier|*
name|nsl_rsvd
decl_stmt|;
name|ndis_sc_element
name|nsl_elements
index|[
name|NDIS_MAXSEG
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ndis_sc_list
name|ndis_sc_list
typedef|;
end_typedef

begin_struct
struct|struct
name|ndis_tcpip_csum
block|{
union|union
block|{
name|uint32_t
name|ntc_txflags
decl_stmt|;
name|uint32_t
name|ntc_rxflags
decl_stmt|;
name|uint32_t
name|ntc_val
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
name|ndis_tcpip_csum
name|ndis_tcpip_csum
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NDIS_TXCSUM_DO_IPV4
value|0x00000001
end_define

begin_define
define|#
directive|define
name|NDIS_TXCSUM_DO_IPV6
value|0x00000002
end_define

begin_define
define|#
directive|define
name|NDIS_TXCSUM_DO_TCP
value|0x00000004
end_define

begin_define
define|#
directive|define
name|NDIS_TXCSUM_DO_UDP
value|0x00000008
end_define

begin_define
define|#
directive|define
name|NDIS_TXCSUM_DO_IP
value|0x00000010
end_define

begin_define
define|#
directive|define
name|NDIS_RXCSUM_TCP_FAILED
value|0x00000001
end_define

begin_define
define|#
directive|define
name|NDIS_RXCSUM_UDP_FAILED
value|0x00000002
end_define

begin_define
define|#
directive|define
name|NDIS_RXCSUM_IP_FAILED
value|0x00000004
end_define

begin_define
define|#
directive|define
name|NDIS_RXCSUM_TCP_PASSED
value|0x00000008
end_define

begin_define
define|#
directive|define
name|NDIS_RXCSUM_UDP_PASSED
value|0x00000010
end_define

begin_define
define|#
directive|define
name|NDIS_RXCSUM_IP_PASSED
value|0x00000020
end_define

begin_define
define|#
directive|define
name|NDIS_RXCSUM_LOOPBACK
value|0x00000040
end_define

begin_struct
struct|struct
name|ndis_vlan
block|{
union|union
block|{
struct|struct
block|{
name|uint32_t
name|nvt_userprio
range|:
literal|3
decl_stmt|;
name|uint32_t
name|nvt_canformatid
range|:
literal|1
decl_stmt|;
name|uint32_t
name|nvt_vlanid
range|:
literal|12
decl_stmt|;
name|uint32_t
name|nvt_rsvd
range|:
literal|16
decl_stmt|;
block|}
name|nv_taghdr
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
name|ndis_vlan
name|ndis_vlan
typedef|;
end_typedef

begin_enum
enum|enum
name|ndis_perpkt_info
block|{
name|ndis_tcpipcsum_info
block|,
name|ndis_ipsec_info
block|,
name|ndis_largesend_info
block|,
name|ndis_classhandle_info
block|,
name|ndis_rsvd
block|,
name|ndis_sclist_info
block|,
name|ndis_ieee8021q_info
block|,
name|ndis_originalpkt_info
block|,
name|ndis_packetcancelid
block|,
name|ndis_maxpkt_info
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|enum
name|ndis_perpkt_info
name|ndis_perpkt_info
typedef|;
end_typedef

begin_struct
struct|struct
name|ndis_packet_extension
block|{
name|void
modifier|*
name|npe_info
index|[
name|ndis_maxpkt_info
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ndis_packet_extension
name|ndis_packet_extension
typedef|;
end_typedef

begin_struct
struct|struct
name|ndis_packet_private
block|{
name|uint32_t
name|npp_physcnt
decl_stmt|;
name|uint32_t
name|npp_totlen
decl_stmt|;
name|ndis_buffer
modifier|*
name|npp_head
decl_stmt|;
name|ndis_buffer
modifier|*
name|npp_tail
decl_stmt|;
name|void
modifier|*
name|npp_pool
decl_stmt|;
name|uint32_t
name|npp_count
decl_stmt|;
name|uint32_t
name|npp_flags
decl_stmt|;
name|uint8_t
name|npp_validcounts
decl_stmt|;
name|uint8_t
name|npp_ndispktflags
decl_stmt|;
name|uint16_t
name|npp_packetooboffset
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NDIS_FLAGS_PROTOCOL_ID_MASK
value|0x0000000F
end_define

begin_define
define|#
directive|define
name|NDIS_FLAGS_MULTICAST_PACKET
value|0x00000010
end_define

begin_define
define|#
directive|define
name|NDIS_FLAGS_RESERVED2
value|0x00000020
end_define

begin_define
define|#
directive|define
name|NDIS_FLAGS_RESERVED3
value|0x00000040
end_define

begin_define
define|#
directive|define
name|NDIS_FLAGS_DONT_LOOPBACK
value|0x00000080
end_define

begin_define
define|#
directive|define
name|NDIS_FLAGS_IS_LOOPBACK_PACKET
value|0x00000100
end_define

begin_define
define|#
directive|define
name|NDIS_FLAGS_LOOPBACK_ONLY
value|0x00000200
end_define

begin_define
define|#
directive|define
name|NDIS_FLAGS_RESERVED4
value|0x00000400
end_define

begin_define
define|#
directive|define
name|NDIS_FLAGS_DOUBLE_BUFFERED
value|0x00000800
end_define

begin_define
define|#
directive|define
name|NDIS_FLAGS_SENT_AT_DPC
value|0x00001000
end_define

begin_define
define|#
directive|define
name|NDIS_FLAGS_USES_SG_BUFFER_LIST
value|0x00002000
end_define

begin_define
define|#
directive|define
name|NDIS_PACKET_WRAPPER_RESERVED
value|0x3F
end_define

begin_define
define|#
directive|define
name|NDIS_PACKET_CONTAINS_MEDIA_SPECIFIC_INFO
value|0x40
end_define

begin_define
define|#
directive|define
name|NDIS_PACKET_ALLOCATED_BY_NDIS
value|0x80
end_define

begin_define
define|#
directive|define
name|NDIS_PROTOCOL_ID_DEFAULT
value|0x00
end_define

begin_define
define|#
directive|define
name|NDIS_PROTOCOL_ID_TCP_IP
value|0x02
end_define

begin_define
define|#
directive|define
name|NDIS_PROTOCOL_ID_IPX
value|0x06
end_define

begin_define
define|#
directive|define
name|NDIS_PROTOCOL_ID_NBF
value|0x07
end_define

begin_define
define|#
directive|define
name|NDIS_PROTOCOL_ID_MAX
value|0x0F
end_define

begin_define
define|#
directive|define
name|NDIS_PROTOCOL_ID_MASK
value|0x0F
end_define

begin_typedef
typedef|typedef
name|struct
name|ndis_packet_private
name|ndis_packet_private
typedef|;
end_typedef

begin_enum
enum|enum
name|ndis_classid
block|{
name|ndis_class_802_3prio
block|,
name|ndis_class_wirelesswan_mbx
block|,
name|ndis_class_irda_packetinfo
block|,
name|ndis_class_atm_aainfo
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|enum
name|ndis_classid
name|ndis_classid
typedef|;
end_typedef

begin_struct
struct|struct
name|ndis_mediaspecific_info
block|{
name|uint32_t
name|nmi_nextentoffset
decl_stmt|;
name|ndis_classid
name|nmi_classid
decl_stmt|;
name|uint32_t
name|nmi_size
decl_stmt|;
name|uint8_t
name|nmi_classinfo
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ndis_mediaspecific_info
name|ndis_mediaspecific_info
typedef|;
end_typedef

begin_struct
struct|struct
name|ndis_packet_oob
block|{
union|union
block|{
name|uint64_t
name|npo_timetotx
decl_stmt|;
name|uint64_t
name|npo_timetxed
decl_stmt|;
block|}
name|u
union|;
name|uint64_t
name|npo_timerxed
decl_stmt|;
name|uint32_t
name|npo_hdrlen
decl_stmt|;
name|uint32_t
name|npo_mediaspecific_len
decl_stmt|;
name|void
modifier|*
name|npo_mediaspecific
decl_stmt|;
name|ndis_status
name|npo_status
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ndis_packet_oob
name|ndis_packet_oob
typedef|;
end_typedef

begin_comment
comment|/*  * Our protocol private region for handling ethernet.  * We need this to stash some of the things returned  * by NdisMEthIndicateReceive().  */
end_comment

begin_struct
struct|struct
name|ndis_ethpriv
block|{
name|void
modifier|*
name|nep_ctx
decl_stmt|;
comment|/* packet context */
name|long
name|nep_offset
decl_stmt|;
comment|/* residual data to transfer */
name|void
modifier|*
name|nep_pad
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
name|ndis_ethpriv
name|ndis_ethpriv
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PROTOCOL_RESERVED_SIZE_IN_PACKET
value|(4 * sizeof(void *))
end_define

begin_struct
struct|struct
name|ndis_packet
block|{
name|ndis_packet_private
name|np_private
decl_stmt|;
union|union
block|{
comment|/* For connectionless miniports. */
struct|struct
block|{
name|uint8_t
name|np_miniport_rsvd
index|[
literal|2
operator|*
sizeof|sizeof
argument_list|(
name|void
operator|*
argument_list|)
index|]
decl_stmt|;
name|uint8_t
name|np_wrapper_rsvd
index|[
literal|2
operator|*
sizeof|sizeof
argument_list|(
name|void
operator|*
argument_list|)
index|]
decl_stmt|;
block|}
name|np_clrsvd
struct|;
comment|/* For de-serialized miniports */
struct|struct
block|{
name|uint8_t
name|np_miniport_rsvdex
index|[
literal|3
operator|*
sizeof|sizeof
argument_list|(
name|void
operator|*
argument_list|)
index|]
decl_stmt|;
name|uint8_t
name|np_wrapper_rsvdex
index|[
sizeof|sizeof
argument_list|(
name|void
operator|*
argument_list|)
index|]
decl_stmt|;
block|}
name|np_dsrsvd
struct|;
struct|struct
block|{
name|uint8_t
name|np_mac_rsvd
index|[
literal|4
operator|*
sizeof|sizeof
argument_list|(
name|void
operator|*
argument_list|)
index|]
decl_stmt|;
block|}
name|np_macrsvd
struct|;
block|}
name|u
union|;
name|uint32_t
modifier|*
name|np_rsvd
index|[
literal|2
index|]
decl_stmt|;
name|uint8_t
name|np_protocolreserved
index|[
name|PROTOCOL_RESERVED_SIZE_IN_PACKET
index|]
decl_stmt|;
comment|/* 	 * This next part is probably wrong, but we need some place 	 * to put the out of band data structure... 	 */
name|ndis_packet_oob
name|np_oob
decl_stmt|;
name|ndis_packet_extension
name|np_ext
decl_stmt|;
name|ndis_sc_list
name|np_sclist
decl_stmt|;
comment|/* BSD-specific stuff which should be invisible to drivers. */
name|uint32_t
name|np_refcnt
decl_stmt|;
name|void
modifier|*
name|np_softc
decl_stmt|;
name|void
modifier|*
name|np_m0
decl_stmt|;
name|int
name|np_txidx
decl_stmt|;
name|list_entry
name|np_list
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ndis_packet
name|ndis_packet
typedef|;
end_typedef

begin_struct
struct|struct
name|ndis_packet_pool
block|{
name|slist_header
name|np_head
decl_stmt|;
name|int
name|np_dead
decl_stmt|;
name|nt_kevent
name|np_event
decl_stmt|;
name|kspin_lock
name|np_lock
decl_stmt|;
name|int
name|np_cnt
decl_stmt|;
name|int
name|np_len
decl_stmt|;
name|int
name|np_protrsvd
decl_stmt|;
name|void
modifier|*
name|np_pktmem
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ndis_packet_pool
name|ndis_packet_pool
typedef|;
end_typedef

begin_comment
comment|/* mbuf ext type for NDIS */
end_comment

begin_define
define|#
directive|define
name|EXT_NDIS
value|EXT_NET_DRV
end_define

begin_comment
comment|/* mtx type for NDIS */
end_comment

begin_define
define|#
directive|define
name|MTX_NDIS_LOCK
value|"NDIS lock"
end_define

begin_struct
struct|struct
name|ndis_filterdbs
block|{
union|union
block|{
name|void
modifier|*
name|nf_ethdb
decl_stmt|;
name|void
modifier|*
name|nf_nulldb
decl_stmt|;
block|}
name|u
union|;
name|void
modifier|*
name|nf_trdb
decl_stmt|;
name|void
modifier|*
name|nf_fddidb
decl_stmt|;
name|void
modifier|*
name|nf_arcdb
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ndis_filterdbs
name|ndis_filterdbs
typedef|;
end_typedef

begin_define
define|#
directive|define
name|nf_ethdb
value|u.nf_ethdb
end_define

begin_enum
enum|enum
name|ndis_medium
block|{
name|NdisMedium802_3
block|,
name|NdisMedium802_5
block|,
name|NdisMediumFddi
block|,
name|NdisMediumWan
block|,
name|NdisMediumLocalTalk
block|,
name|NdisMediumDix
block|,
comment|/* defined for convenience, not a real medium */
name|NdisMediumArcnetRaw
block|,
name|NdisMediumArcnet878_2
block|,
name|NdisMediumAtm
block|,
name|NdisMediumWirelessWan
block|,
name|NdisMediumIrda
block|,
name|NdisMediumBpc
block|,
name|NdisMediumCoWan
block|,
name|NdisMedium1394
block|,
name|NdisMediumMax
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|enum
name|ndis_medium
name|ndis_medium
typedef|;
end_typedef

begin_comment
comment|/* enum interface_type { 	InterfaceTypeUndefined = -1, 	Internal, 	Isa, 	Eisa, 	MicroChannel, 	TurboChannel, 	PCIBus, 	VMEBus, 	NuBus, 	PCMCIABus, 	CBus, 	MPIBus, 	MPSABus, 	ProcessorInternal, 	InternalPowerBus, 	PNPISABus, 	PNPBus, 	MaximumInterfaceType }; */
end_comment

begin_enum
enum|enum
name|ndis_interface_type
block|{
name|NdisInterfaceInternal
init|=
name|Internal
block|,
name|NdisInterfaceIsa
init|=
name|Isa
block|,
name|NdisInterfaceEisa
init|=
name|Eisa
block|,
name|NdisInterfaceMca
init|=
name|MicroChannel
block|,
name|NdisInterfaceTurboChannel
init|=
name|TurboChannel
block|,
name|NdisInterfacePci
init|=
name|PCIBus
block|,
name|NdisInterfacePcMcia
init|=
name|PCMCIABus
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|enum
name|ndis_interface_type
name|ndis_interface_type
typedef|;
end_typedef

begin_struct
struct|struct
name|ndis_paddr_unit
block|{
name|ndis_physaddr
name|npu_physaddr
decl_stmt|;
name|uint32_t
name|npu_len
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ndis_paddr_unit
name|ndis_paddr_unit
typedef|;
end_typedef

begin_struct
struct|struct
name|ndis_map_arg
block|{
name|ndis_paddr_unit
modifier|*
name|nma_fraglist
decl_stmt|;
name|int
name|nma_cnt
decl_stmt|;
name|int
name|nma_max
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Miniport characteristics were originally defined in the NDIS 3.0  * spec and then extended twice, in NDIS 4.0 and 5.0.  */
end_comment

begin_struct
struct|struct
name|ndis_miniport_characteristics
block|{
comment|/* NDIS 3.0 */
name|uint8_t
name|nmc_version_major
decl_stmt|;
name|uint8_t
name|nmc_version_minor
decl_stmt|;
name|uint16_t
name|nmc_pad
decl_stmt|;
name|uint32_t
name|nmc_rsvd
decl_stmt|;
name|void
modifier|*
name|nmc_checkhang_func
decl_stmt|;
name|void
modifier|*
name|nmc_disable_interrupts_func
decl_stmt|;
name|void
modifier|*
name|nmc_enable_interrupts_func
decl_stmt|;
name|void
modifier|*
name|nmc_halt_func
decl_stmt|;
name|void
modifier|*
name|nmc_interrupt_func
decl_stmt|;
name|void
modifier|*
name|nmc_init_func
decl_stmt|;
name|void
modifier|*
name|nmc_isr_func
decl_stmt|;
name|void
modifier|*
name|nmc_queryinfo_func
decl_stmt|;
name|void
modifier|*
name|nmc_reconfig_func
decl_stmt|;
name|void
modifier|*
name|nmc_reset_func
decl_stmt|;
name|void
modifier|*
name|nmc_sendsingle_func
decl_stmt|;
name|void
modifier|*
name|nmc_setinfo_func
decl_stmt|;
name|void
modifier|*
name|nmc_transferdata_func
decl_stmt|;
comment|/* NDIS 4.0 extentions */
name|void
modifier|*
name|nmc_return_packet_func
decl_stmt|;
name|void
modifier|*
name|nmc_sendmulti_func
decl_stmt|;
name|void
modifier|*
name|nmc_allocate_complete_func
decl_stmt|;
comment|/* NDIS 5.0 extensions */
name|void
modifier|*
name|nmc_cocreatevc_func
decl_stmt|;
name|void
modifier|*
name|nmc_codeletevc_func
decl_stmt|;
name|void
modifier|*
name|nmc_coactivatevc_func
decl_stmt|;
name|void
modifier|*
name|nmc_codeactivatevc_func
decl_stmt|;
name|void
modifier|*
name|nmc_comultisend_func
decl_stmt|;
name|void
modifier|*
name|nmc_corequest_func
decl_stmt|;
comment|/* NDIS 5.1 extentions */
name|void
modifier|*
name|nmc_canceltxpkts_handler
decl_stmt|;
name|void
modifier|*
name|nmc_pnpevent_handler
decl_stmt|;
name|void
modifier|*
name|nmc_shutdown_handler
decl_stmt|;
name|void
modifier|*
name|nmc_rsvd0
decl_stmt|;
name|void
modifier|*
name|nmc_rsvd1
decl_stmt|;
name|void
modifier|*
name|nmc_rsvd2
decl_stmt|;
name|void
modifier|*
name|nmc_rsvd3
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ndis_miniport_characteristics
name|ndis_miniport_characteristics
typedef|;
end_typedef

begin_struct
struct|struct
name|ndis_driver_object
block|{
name|char
modifier|*
name|ndo_ifname
decl_stmt|;
name|void
modifier|*
name|ndo_softc
decl_stmt|;
name|ndis_miniport_characteristics
name|ndo_chars
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ndis_driver_object
name|ndis_driver_object
typedef|;
end_typedef

begin_struct
struct|struct
name|ndis_reference
block|{
name|ndis_kspin_lock
name|nr_spinlock
decl_stmt|;
name|uint16_t
name|nr_refcnt
decl_stmt|;
name|uint8_t
name|nr_closing
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ndis_reference
name|ndis_reference
typedef|;
end_typedef

begin_struct
struct|struct
name|ndis_timer_entry
block|{
name|struct
name|callout
name|nte_ch
decl_stmt|;
name|ndis_miniport_timer
modifier|*
name|nte_timer
decl_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|ndis_timer_entry
argument_list|)
name|link
expr_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|nte_head
argument_list|,
name|ndis_timer_entry
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|NDIS_FH_TYPE_VFS
value|0
end_define

begin_define
define|#
directive|define
name|NDIS_FH_TYPE_MODULE
value|1
end_define

begin_struct
struct|struct
name|ndis_fh
block|{
name|int
name|nf_type
decl_stmt|;
name|char
modifier|*
name|nf_name
decl_stmt|;
name|void
modifier|*
name|nf_vp
decl_stmt|;
name|void
modifier|*
name|nf_map
decl_stmt|;
name|uint32_t
name|nf_maplen
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ndis_fh
name|ndis_fh
typedef|;
end_typedef

begin_comment
comment|/*  * The miniport block is basically the internal NDIS handle. We need  * to define this because, unfortunately, it is not entirely opaque  * to NDIS drivers. For one thing, it contains the function pointer  * to the NDIS packet receive handler, which is invoked out of the  * NDIS block via a macro rather than a function pointer. (The  * NdisMIndicateReceivePacket() routine is a macro rather than  * a function.) For another, the driver maintains a pointer to the  * miniport block and passes it as a handle to various NDIS functions.  * (The driver never really knows this because it's hidden behind  * an ndis_handle though.)  *  * The miniport block has two parts: the first part contains fields  * that must never change, since they are referenced by driver  * binaries through macros. The second part is ignored by the driver,  * but contains various things used internaly by NDIS.SYS. In our  * case, we define the first 'immutable' part exactly as it appears  * in Windows, but don't bother duplicating the Windows definitions  * for the second part. Instead, we replace them with a few BSD-specific  * things.  */
end_comment

begin_struct
struct|struct
name|ndis_miniport_block
block|{
comment|/* 	 * Windows-specific portion -- DO NOT MODIFY OR NDIS 	 * DRIVERS WILL NOT WORK. 	 */
name|void
modifier|*
name|nmb_signature
decl_stmt|;
comment|/* magic number */
name|ndis_miniport_block
modifier|*
name|nmb_nextminiport
decl_stmt|;
name|ndis_mdriver_block
modifier|*
name|nmb_driverhandle
decl_stmt|;
name|ndis_handle
name|nmb_miniportadapterctx
decl_stmt|;
name|ndis_unicode_string
name|nmb_name
decl_stmt|;
name|ndis_bind_paths
modifier|*
name|nmb_bindpaths
decl_stmt|;
name|ndis_handle
name|nmb_openqueue
decl_stmt|;
name|ndis_reference
name|nmb_ref
decl_stmt|;
name|ndis_handle
name|nmb_devicectx
decl_stmt|;
name|uint8_t
name|nmb_padding
decl_stmt|;
name|uint8_t
name|nmb_lockacquired
decl_stmt|;
name|uint8_t
name|nmb_pmodeopens
decl_stmt|;
name|uint8_t
name|nmb_assignedcpu
decl_stmt|;
name|ndis_kspin_lock
name|nmb_lock
decl_stmt|;
name|ndis_request
modifier|*
name|nmb_mediarequest
decl_stmt|;
name|ndis_miniport_interrupt
modifier|*
name|nmb_interrupt
decl_stmt|;
name|uint32_t
name|nmb_flags
decl_stmt|;
name|uint32_t
name|nmb_pnpflags
decl_stmt|;
name|list_entry
name|nmb_packetlist
decl_stmt|;
name|ndis_packet
modifier|*
name|nmb_firstpendingtxpacket
decl_stmt|;
name|ndis_packet
modifier|*
name|nmb_returnpacketqueue
decl_stmt|;
name|uint32_t
name|nmb_requestbuffer
decl_stmt|;
name|void
modifier|*
name|nmb_setmcastbuf
decl_stmt|;
name|ndis_miniport_block
modifier|*
name|nmb_primaryminiport
decl_stmt|;
name|void
modifier|*
name|nmb_wrapperctx
decl_stmt|;
name|void
modifier|*
name|nmb_busdatactx
decl_stmt|;
name|uint32_t
name|nmb_pnpcaps
decl_stmt|;
name|cm_resource_list
modifier|*
name|nmb_resources
decl_stmt|;
name|ndis_timer
name|nmb_wkupdpctimer
decl_stmt|;
name|ndis_unicode_string
name|nmb_basename
decl_stmt|;
name|ndis_unicode_string
name|nmb_symlinkname
decl_stmt|;
name|uint32_t
name|nmb_checkforhangsecs
decl_stmt|;
name|uint16_t
name|nmb_cfhticks
decl_stmt|;
name|uint16_t
name|nmb_cfhcurrticks
decl_stmt|;
name|ndis_status
name|nmb_resetstatus
decl_stmt|;
name|ndis_handle
name|nmb_resetopen
decl_stmt|;
name|ndis_filterdbs
name|nmb_filterdbs
decl_stmt|;
name|void
modifier|*
name|nmb_pktind_func
decl_stmt|;
name|void
modifier|*
name|nmb_senddone_func
decl_stmt|;
name|void
modifier|*
name|nmb_sendrsrc_func
decl_stmt|;
name|void
modifier|*
name|nmb_resetdone_func
decl_stmt|;
name|ndis_medium
name|nmb_medium
decl_stmt|;
name|uint32_t
name|nmb_busnum
decl_stmt|;
name|uint32_t
name|nmb_bustype
decl_stmt|;
name|uint32_t
name|nmb_adaptertype
decl_stmt|;
name|device_object
modifier|*
name|nmb_deviceobj
decl_stmt|;
comment|/* Functional device */
name|device_object
modifier|*
name|nmb_physdeviceobj
decl_stmt|;
comment|/* Physical device */
name|device_object
modifier|*
name|nmb_nextdeviceobj
decl_stmt|;
comment|/* Next dev in stack */
name|void
modifier|*
name|nmb_mapreg
decl_stmt|;
name|void
modifier|*
name|nmb_callmgraflist
decl_stmt|;
name|void
modifier|*
name|nmb_miniportthread
decl_stmt|;
name|void
modifier|*
name|nmb_setinfobuf
decl_stmt|;
name|uint16_t
name|nmb_setinfobuflen
decl_stmt|;
name|uint16_t
name|nmb_maxsendpkts
decl_stmt|;
name|ndis_status
name|nmb_fakestatus
decl_stmt|;
name|void
modifier|*
name|nmb_lockhandler
decl_stmt|;
name|ndis_unicode_string
modifier|*
name|nmb_adapterinstancename
decl_stmt|;
name|void
modifier|*
name|nmb_timerqueue
decl_stmt|;
name|uint32_t
name|nmb_mactoptions
decl_stmt|;
name|ndis_request
modifier|*
name|nmb_pendingreq
decl_stmt|;
name|uint32_t
name|nmb_maxlongaddrs
decl_stmt|;
name|uint32_t
name|nmb_maxshortaddrs
decl_stmt|;
name|uint32_t
name|nmb_currlookahead
decl_stmt|;
name|uint32_t
name|nmb_maxlookahead
decl_stmt|;
name|void
modifier|*
name|nmb_interrupt_func
decl_stmt|;
name|void
modifier|*
name|nmb_disableintr_func
decl_stmt|;
name|void
modifier|*
name|nmb_enableintr_func
decl_stmt|;
name|void
modifier|*
name|nmb_sendpkts_func
decl_stmt|;
name|void
modifier|*
name|nmb_deferredsend_func
decl_stmt|;
name|void
modifier|*
name|nmb_ethrxindicate_func
decl_stmt|;
name|void
modifier|*
name|nmb_txrxindicate_func
decl_stmt|;
name|void
modifier|*
name|nmb_fddirxindicate_func
decl_stmt|;
name|void
modifier|*
name|nmb_ethrxdone_func
decl_stmt|;
name|void
modifier|*
name|nmb_txrxdone_func
decl_stmt|;
name|void
modifier|*
name|nmb_fddirxcond_func
decl_stmt|;
name|void
modifier|*
name|nmb_status_func
decl_stmt|;
name|void
modifier|*
name|nmb_statusdone_func
decl_stmt|;
name|void
modifier|*
name|nmb_tdcond_func
decl_stmt|;
name|void
modifier|*
name|nmb_querydone_func
decl_stmt|;
name|void
modifier|*
name|nmb_setdone_func
decl_stmt|;
name|void
modifier|*
name|nmb_wantxdone_func
decl_stmt|;
name|void
modifier|*
name|nmb_wanrx_func
decl_stmt|;
name|void
modifier|*
name|nmb_wanrxdone_func
decl_stmt|;
comment|/* 	 * End of windows-specific portion of miniport block. Everything 	 * below is BSD-specific. 	 */
name|list_entry
name|nmb_parmlist
decl_stmt|;
name|ndis_resource_list
modifier|*
name|nmb_rlist
decl_stmt|;
name|ndis_status
name|nmb_getstat
decl_stmt|;
name|nt_kevent
name|nmb_getevent
decl_stmt|;
name|ndis_status
name|nmb_setstat
decl_stmt|;
name|nt_kevent
name|nmb_setevent
decl_stmt|;
name|nt_kevent
name|nmb_resetevent
decl_stmt|;
name|io_workitem
modifier|*
name|nmb_returnitem
decl_stmt|;
name|ndis_miniport_timer
modifier|*
name|nmb_timerlist
decl_stmt|;
name|ndis_handle
name|nmb_rxpool
decl_stmt|;
name|list_entry
name|nmb_returnlist
decl_stmt|;
name|kspin_lock
name|nmb_returnlock
decl_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|ndis_miniport_block
argument_list|)
name|link
expr_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|nd_head
argument_list|,
name|ndis_miniport_block
argument_list|)
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|ndis_status
function_decl|(
modifier|*
name|ndis_init_handler
function_decl|)
parameter_list|(
name|ndis_status
modifier|*
parameter_list|,
name|uint32_t
modifier|*
parameter_list|,
name|ndis_medium
modifier|*
parameter_list|,
name|uint32_t
parameter_list|,
name|ndis_handle
parameter_list|,
name|ndis_handle
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|ndis_status
function_decl|(
modifier|*
name|ndis_queryinfo_handler
function_decl|)
parameter_list|(
name|ndis_handle
parameter_list|,
name|ndis_oid
parameter_list|,
name|void
modifier|*
parameter_list|,
name|uint32_t
parameter_list|,
name|uint32_t
modifier|*
parameter_list|,
name|uint32_t
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|ndis_status
function_decl|(
modifier|*
name|ndis_setinfo_handler
function_decl|)
parameter_list|(
name|ndis_handle
parameter_list|,
name|ndis_oid
parameter_list|,
name|void
modifier|*
parameter_list|,
name|uint32_t
parameter_list|,
name|uint32_t
modifier|*
parameter_list|,
name|uint32_t
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|ndis_status
function_decl|(
modifier|*
name|ndis_sendsingle_handler
function_decl|)
parameter_list|(
name|ndis_handle
parameter_list|,
name|ndis_packet
modifier|*
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|ndis_status
function_decl|(
modifier|*
name|ndis_sendmulti_handler
function_decl|)
parameter_list|(
name|ndis_handle
parameter_list|,
name|ndis_packet
modifier|*
modifier|*
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|ndis_isr_handler
function_decl|)
parameter_list|(
name|uint8_t
modifier|*
parameter_list|,
name|uint8_t
modifier|*
parameter_list|,
name|ndis_handle
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|ndis_interrupt_handler
function_decl|)
parameter_list|(
name|ndis_handle
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|ndis_reset_handler
function_decl|)
parameter_list|(
name|uint8_t
modifier|*
parameter_list|,
name|ndis_handle
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|ndis_halt_handler
function_decl|)
parameter_list|(
name|ndis_handle
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|ndis_return_handler
function_decl|)
parameter_list|(
name|ndis_handle
parameter_list|,
name|ndis_packet
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|ndis_enable_interrupts_handler
function_decl|)
parameter_list|(
name|ndis_handle
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|ndis_disable_interrupts_handler
function_decl|)
parameter_list|(
name|ndis_handle
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|ndis_shutdown_handler
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|ndis_allocdone_handler
function_decl|)
parameter_list|(
name|ndis_handle
parameter_list|,
name|void
modifier|*
parameter_list|,
name|ndis_physaddr
modifier|*
parameter_list|,
name|uint32_t
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|uint8_t
function_decl|(
modifier|*
name|ndis_checkforhang_handler
function_decl|)
parameter_list|(
name|ndis_handle
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|ndis_status
function_decl|(
modifier|*
name|driver_entry
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|unicode_string
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
specifier|extern
name|image_patch_table
name|ndis_functbl
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|NDIS_TASKQUEUE
value|1
end_define

begin_define
define|#
directive|define
name|NDIS_SWI
value|2
end_define

begin_define
define|#
directive|define
name|NDIS_PSTATE_RUNNING
value|1
end_define

begin_define
define|#
directive|define
name|NDIS_PSTATE_SLEEPING
value|2
end_define

begin_define
define|#
directive|define
name|NdisQueryPacket
parameter_list|(
name|p
parameter_list|,
name|pbufcnt
parameter_list|,
name|bufcnt
parameter_list|,
name|firstbuf
parameter_list|,
name|plen
parameter_list|)
define|\
value|do {								\ 		if ((firstbuf) != NULL) {				\ 			ndis_buffer		**_first;		\ 			_first = firstbuf;				\ 			*(_first) = (p)->np_private.npp_head;		\ 		}							\ 		if ((plen) || (bufcnt) || (pbufcnt)) {			\ 			if ((p)->np_private.npp_validcounts == FALSE) {	\ 				ndis_buffer		*tmp;		\ 				unsigned int		tlen = 0, pcnt = 0; \ 				unsigned int		add = 0;	\ 				unsigned int		pktlen, off;	\ 									\ 				tmp = (p)->np_private.npp_head;		\ 				while (tmp != NULL) {			\ 					off = MmGetMdlByteOffset(tmp);	\ 					pktlen = MmGetMdlByteCount(tmp);\ 					tlen += pktlen;			\ 					pcnt +=				\ 					    NDIS_BUFFER_TO_SPAN_PAGES(tmp); \ 					add++;				\ 					tmp = tmp->mdl_next;		\ 				}					\ 				(p)->np_private.npp_count = add;	\ 				(p)->np_private.npp_totlen = tlen;	\ 				(p)->np_private.npp_physcnt = pcnt;	\ 				(p)->np_private.npp_validcounts = TRUE;	\ 			}						\ 			if (pbufcnt) {					\ 				unsigned int		*_pbufcnt;	\ 				_pbufcnt = (pbufcnt);			\ 				*(_pbufcnt) = (p)->np_private.npp_physcnt; \ 			}						\ 			if (bufcnt) {					\ 				unsigned int		*_bufcnt;	\ 				_bufcnt = (bufcnt);			\ 				*(_bufcnt) = (p)->np_private.npp_count;	\ 			}						\ 			if (plen) {					\ 				unsigned int		*_plen;		\ 				_plen = (plen);				\ 				*(_plen) = (p)->np_private.npp_totlen;	\ 			}						\ 		}							\ 	} while (0)
end_define

begin_function_decl
name|__BEGIN_DECLS
specifier|extern
name|int
name|ndis_libinit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ndis_libfini
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ndis_load_driver
parameter_list|(
name|vm_offset_t
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ndis_unload_driver
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ndis_mtop
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|ndis_packet
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ndis_ptom
parameter_list|(
name|struct
name|mbuf
modifier|*
modifier|*
parameter_list|,
name|ndis_packet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ndis_get_info
parameter_list|(
name|void
modifier|*
parameter_list|,
name|ndis_oid
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ndis_set_info
parameter_list|(
name|void
modifier|*
parameter_list|,
name|ndis_oid
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ndis_get_supported_oids
parameter_list|(
name|void
modifier|*
parameter_list|,
name|ndis_oid
modifier|*
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ndis_send_packets
parameter_list|(
name|void
modifier|*
parameter_list|,
name|ndis_packet
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ndis_send_packet
parameter_list|(
name|void
modifier|*
parameter_list|,
name|ndis_packet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ndis_convert_res
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ndis_alloc_amem
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ndis_free_amem
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ndis_free_packet
parameter_list|(
name|ndis_packet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ndis_free_bufs
parameter_list|(
name|ndis_buffer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ndis_reset_nic
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ndis_halt_nic
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ndis_shutdown_nic
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ndis_init_nic
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ndis_return_packet
parameter_list|(
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ndis_init_dma
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ndis_destroy_dma
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ndis_create_sysctls
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ndis_add_sysctl
parameter_list|(
name|void
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ndis_flush_sysctls
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint32_t
name|NdisAddDevice
parameter_list|(
name|driver_object
modifier|*
parameter_list|,
name|device_object
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|NdisAllocatePacketPool
parameter_list|(
name|ndis_status
modifier|*
parameter_list|,
name|ndis_handle
modifier|*
parameter_list|,
name|uint32_t
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|NdisAllocatePacketPoolEx
parameter_list|(
name|ndis_status
modifier|*
parameter_list|,
name|ndis_handle
modifier|*
parameter_list|,
name|uint32_t
parameter_list|,
name|uint32_t
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint32_t
name|NdisPacketPoolUsage
parameter_list|(
name|ndis_handle
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|NdisFreePacketPool
parameter_list|(
name|ndis_handle
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|NdisAllocatePacket
parameter_list|(
name|ndis_status
modifier|*
parameter_list|,
name|ndis_packet
modifier|*
modifier|*
parameter_list|,
name|ndis_handle
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|NdisFreePacket
parameter_list|(
name|ndis_packet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|ndis_status
name|NdisScheduleWorkItem
parameter_list|(
name|ndis_work_item
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|NdisMSleep
parameter_list|(
name|uint32_t
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
comment|/* _NDIS_VAR_H_ */
end_comment

end_unit

