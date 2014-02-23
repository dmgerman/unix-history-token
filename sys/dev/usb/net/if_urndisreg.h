begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$ */
end_comment

begin_comment
comment|/*	$OpenBSD: if_urndisreg.h,v 1.19 2013/11/21 14:08:05 mpi Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2010 Jonathan Armani<armani@openbsd.org>  * Copyright (c) 2010 Fabien Romano<fabien@openbsd.org>  * Copyright (c) 2010 Michael Knudsen<mk@openbsd.org>  * All rights reserved.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IF_URNDISREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_IF_URNDISREG_H_
end_define

begin_define
define|#
directive|define
name|RNDIS_RESPONSE_LEN
value|1024
end_define

begin_comment
comment|/* bytes */
end_comment

begin_define
define|#
directive|define
name|RNDIS_RX_MAXLEN
value|(16 * 1024)
end_define

begin_define
define|#
directive|define
name|RNDIS_TX_FRAMES_MAX
value|8
end_define

begin_define
define|#
directive|define
name|RNDIS_TX_MAXLEN
value|MCLBYTES
end_define

begin_enum
enum|enum
block|{
name|URNDIS_BULK_RX
block|,
name|URNDIS_BULK_TX
block|,
name|URNDIS_INTR_RX
block|,
name|URNDIS_N_TRANSFER
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|urndis_softc
block|{
name|struct
name|usb_ether
name|sc_ue
decl_stmt|;
name|struct
name|mtx
name|sc_mtx
decl_stmt|;
comment|/* RNDIS device info */
name|uint32_t
name|sc_lim_pktsz
decl_stmt|;
name|uint32_t
name|sc_filter
decl_stmt|;
name|struct
name|usb_device
modifier|*
name|sc_udev
decl_stmt|;
name|struct
name|usb_xfer
modifier|*
name|sc_xfer
index|[
name|URNDIS_N_TRANSFER
index|]
decl_stmt|;
name|uint8_t
name|sc_ifaceno_ctl
decl_stmt|;
name|uint8_t
name|sc_response_buf
index|[
name|RNDIS_RESPONSE_LEN
index|]
name|__aligned
argument_list|(
literal|4
argument_list|)
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|URNDIS_LOCK
parameter_list|(
name|sc
parameter_list|)
value|mtx_lock(&(sc)->sc_mtx)
end_define

begin_define
define|#
directive|define
name|URNDIS_UNLOCK
parameter_list|(
name|sc
parameter_list|)
value|mtx_unlock(&(sc)->sc_mtx)
end_define

begin_define
define|#
directive|define
name|URNDIS_LOCK_ASSERT
parameter_list|(
name|sc
parameter_list|,
name|what
parameter_list|)
value|mtx_assert(&(sc)->sc_mtx, (what))
end_define

begin_define
define|#
directive|define
name|RNDIS_STATUS_BUFFER_OVERFLOW
value|0x80000005L
end_define

begin_define
define|#
directive|define
name|RNDIS_STATUS_FAILURE
value|0xC0000001L
end_define

begin_define
define|#
directive|define
name|RNDIS_STATUS_INVALID_DATA
value|0xC0010015L
end_define

begin_define
define|#
directive|define
name|RNDIS_STATUS_MEDIA_CONNECT
value|0x4001000BL
end_define

begin_define
define|#
directive|define
name|RNDIS_STATUS_MEDIA_DISCONNECT
value|0x4001000CL
end_define

begin_define
define|#
directive|define
name|RNDIS_STATUS_NOT_SUPPORTED
value|0xC00000BBL
end_define

begin_define
define|#
directive|define
name|RNDIS_STATUS_PENDING
value|STATUS_PENDING
end_define

begin_comment
comment|/* XXX */
end_comment

begin_define
define|#
directive|define
name|RNDIS_STATUS_RESOURCES
value|0xC000009AL
end_define

begin_define
define|#
directive|define
name|RNDIS_STATUS_SUCCESS
value|0x00000000L
end_define

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

begin_define
define|#
directive|define
name|OID_GEN_TRANSPORT_HEADER_OFFSET
value|0x00010119
end_define

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

begin_define
define|#
directive|define
name|OID_GEN_VLAN_ID
value|0x0001021C
end_define

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

begin_define
define|#
directive|define
name|RNDIS_MEDIUM_802_3
value|0x00000000
end_define

begin_comment
comment|/* Device flags */
end_comment

begin_define
define|#
directive|define
name|RNDIS_DF_CONNECTIONLESS
value|0x00000001
end_define

begin_define
define|#
directive|define
name|RNDIS_DF_CONNECTION_ORIENTED
value|0x00000002
end_define

begin_comment
comment|/*  * RNDIS data message  */
end_comment

begin_define
define|#
directive|define
name|REMOTE_NDIS_PACKET_MSG
value|0x00000001
end_define

begin_struct
struct|struct
name|urndis_packet_msg
block|{
name|uint32_t
name|rm_type
decl_stmt|;
name|uint32_t
name|rm_len
decl_stmt|;
name|uint32_t
name|rm_dataoffset
decl_stmt|;
name|uint32_t
name|rm_datalen
decl_stmt|;
name|uint32_t
name|rm_oobdataoffset
decl_stmt|;
name|uint32_t
name|rm_oobdatalen
decl_stmt|;
name|uint32_t
name|rm_oobdataelements
decl_stmt|;
name|uint32_t
name|rm_pktinfooffset
decl_stmt|;
name|uint32_t
name|rm_pktinfolen
decl_stmt|;
name|uint32_t
name|rm_vchandle
decl_stmt|;
name|uint32_t
name|rm_reserved
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * RNDIS control messages  */
end_comment

begin_struct
struct|struct
name|urndis_comp_hdr
block|{
name|uint32_t
name|rm_type
decl_stmt|;
name|uint32_t
name|rm_len
decl_stmt|;
name|uint32_t
name|rm_rid
decl_stmt|;
name|uint32_t
name|rm_status
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Initialize the device. */
end_comment

begin_define
define|#
directive|define
name|REMOTE_NDIS_INITIALIZE_MSG
value|0x00000002
end_define

begin_define
define|#
directive|define
name|REMOTE_NDIS_INITIALIZE_CMPLT
value|0x80000002
end_define

begin_struct
struct|struct
name|urndis_init_req
block|{
name|uint32_t
name|rm_type
decl_stmt|;
name|uint32_t
name|rm_len
decl_stmt|;
name|uint32_t
name|rm_rid
decl_stmt|;
name|uint32_t
name|rm_ver_major
decl_stmt|;
name|uint32_t
name|rm_ver_minor
decl_stmt|;
name|uint32_t
name|rm_max_xfersz
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|urndis_init_comp
block|{
name|uint32_t
name|rm_type
decl_stmt|;
name|uint32_t
name|rm_len
decl_stmt|;
name|uint32_t
name|rm_rid
decl_stmt|;
name|uint32_t
name|rm_status
decl_stmt|;
name|uint32_t
name|rm_ver_major
decl_stmt|;
name|uint32_t
name|rm_ver_minor
decl_stmt|;
name|uint32_t
name|rm_devflags
decl_stmt|;
name|uint32_t
name|rm_medium
decl_stmt|;
name|uint32_t
name|rm_pktmaxcnt
decl_stmt|;
name|uint32_t
name|rm_pktmaxsz
decl_stmt|;
name|uint32_t
name|rm_align
decl_stmt|;
name|uint32_t
name|rm_aflistoffset
decl_stmt|;
name|uint32_t
name|rm_aflistsz
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Halt the device.  No response sent. */
end_comment

begin_define
define|#
directive|define
name|REMOTE_NDIS_HALT_MSG
value|0x00000003
end_define

begin_struct
struct|struct
name|urndis_halt_req
block|{
name|uint32_t
name|rm_type
decl_stmt|;
name|uint32_t
name|rm_len
decl_stmt|;
name|uint32_t
name|rm_rid
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Send a query object. */
end_comment

begin_define
define|#
directive|define
name|REMOTE_NDIS_QUERY_MSG
value|0x00000004
end_define

begin_define
define|#
directive|define
name|REMOTE_NDIS_QUERY_CMPLT
value|0x80000004
end_define

begin_struct
struct|struct
name|urndis_query_req
block|{
name|uint32_t
name|rm_type
decl_stmt|;
name|uint32_t
name|rm_len
decl_stmt|;
name|uint32_t
name|rm_rid
decl_stmt|;
name|uint32_t
name|rm_oid
decl_stmt|;
name|uint32_t
name|rm_infobuflen
decl_stmt|;
name|uint32_t
name|rm_infobufoffset
decl_stmt|;
name|uint32_t
name|rm_devicevchdl
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|urndis_query_comp
block|{
name|uint32_t
name|rm_type
decl_stmt|;
name|uint32_t
name|rm_len
decl_stmt|;
name|uint32_t
name|rm_rid
decl_stmt|;
name|uint32_t
name|rm_status
decl_stmt|;
name|uint32_t
name|rm_infobuflen
decl_stmt|;
name|uint32_t
name|rm_infobufoffset
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Send a set object request. */
end_comment

begin_define
define|#
directive|define
name|REMOTE_NDIS_SET_MSG
value|0x00000005
end_define

begin_define
define|#
directive|define
name|REMOTE_NDIS_SET_CMPLT
value|0x80000005
end_define

begin_struct
struct|struct
name|urndis_set_req
block|{
name|uint32_t
name|rm_type
decl_stmt|;
name|uint32_t
name|rm_len
decl_stmt|;
name|uint32_t
name|rm_rid
decl_stmt|;
name|uint32_t
name|rm_oid
decl_stmt|;
name|uint32_t
name|rm_infobuflen
decl_stmt|;
name|uint32_t
name|rm_infobufoffset
decl_stmt|;
name|uint32_t
name|rm_devicevchdl
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|urndis_set_comp
block|{
name|uint32_t
name|rm_type
decl_stmt|;
name|uint32_t
name|rm_len
decl_stmt|;
name|uint32_t
name|rm_rid
decl_stmt|;
name|uint32_t
name|rm_status
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|REMOTE_NDIS_SET_PARAM_NUMERIC
value|0x00000000
end_define

begin_define
define|#
directive|define
name|REMOTE_NDIS_SET_PARAM_STRING
value|0x00000002
end_define

begin_struct
struct|struct
name|urndis_set_parameter
block|{
name|uint32_t
name|rm_nameoffset
decl_stmt|;
name|uint32_t
name|rm_namelen
decl_stmt|;
name|uint32_t
name|rm_type
decl_stmt|;
name|uint32_t
name|rm_valueoffset
decl_stmt|;
name|uint32_t
name|rm_valuelen
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Perform a soft reset on the device. */
end_comment

begin_define
define|#
directive|define
name|REMOTE_NDIS_RESET_MSG
value|0x00000006
end_define

begin_define
define|#
directive|define
name|REMOTE_NDIS_RESET_CMPLT
value|0x80000006
end_define

begin_struct
struct|struct
name|urndis_reset_req
block|{
name|uint32_t
name|rm_type
decl_stmt|;
name|uint32_t
name|rm_len
decl_stmt|;
name|uint32_t
name|rm_rid
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|urndis_reset_comp
block|{
name|uint32_t
name|rm_type
decl_stmt|;
name|uint32_t
name|rm_len
decl_stmt|;
name|uint32_t
name|rm_status
decl_stmt|;
name|uint32_t
name|rm_adrreset
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* 802.3 link-state or undefined message error. */
end_comment

begin_define
define|#
directive|define
name|REMOTE_NDIS_INDICATE_STATUS_MSG
value|0x00000007
end_define

begin_comment
comment|/* Keepalive messsage.  May be sent by device. */
end_comment

begin_define
define|#
directive|define
name|REMOTE_NDIS_KEEPALIVE_MSG
value|0x00000008
end_define

begin_define
define|#
directive|define
name|REMOTE_NDIS_KEEPALIVE_CMPLT
value|0x80000008
end_define

begin_struct
struct|struct
name|urndis_keepalive_req
block|{
name|uint32_t
name|rm_type
decl_stmt|;
name|uint32_t
name|rm_len
decl_stmt|;
name|uint32_t
name|rm_rid
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|urndis_keepalive_comp
block|{
name|uint32_t
name|rm_type
decl_stmt|;
name|uint32_t
name|rm_len
decl_stmt|;
name|uint32_t
name|rm_rid
decl_stmt|;
name|uint32_t
name|rm_status
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* packet filter bits used by OID_GEN_CURRENT_PACKET_FILTER */
end_comment

begin_define
define|#
directive|define
name|RNDIS_PACKET_TYPE_DIRECTED
value|0x00000001
end_define

begin_define
define|#
directive|define
name|RNDIS_PACKET_TYPE_MULTICAST
value|0x00000002
end_define

begin_define
define|#
directive|define
name|RNDIS_PACKET_TYPE_ALL_MULTICAST
value|0x00000004
end_define

begin_define
define|#
directive|define
name|RNDIS_PACKET_TYPE_BROADCAST
value|0x00000008
end_define

begin_define
define|#
directive|define
name|RNDIS_PACKET_TYPE_SOURCE_ROUTING
value|0x00000010
end_define

begin_define
define|#
directive|define
name|RNDIS_PACKET_TYPE_PROMISCUOUS
value|0x00000020
end_define

begin_define
define|#
directive|define
name|RNDIS_PACKET_TYPE_SMT
value|0x00000040
end_define

begin_define
define|#
directive|define
name|RNDIS_PACKET_TYPE_ALL_LOCAL
value|0x00000080
end_define

begin_define
define|#
directive|define
name|RNDIS_PACKET_TYPE_GROUP
value|0x00001000
end_define

begin_define
define|#
directive|define
name|RNDIS_PACKET_TYPE_ALL_FUNCTIONAL
value|0x00002000
end_define

begin_define
define|#
directive|define
name|RNDIS_PACKET_TYPE_FUNCTIONAL
value|0x00004000
end_define

begin_define
define|#
directive|define
name|RNDIS_PACKET_TYPE_MAC_FRAME
value|0x00008000
end_define

begin_comment
comment|/* RNDIS offsets */
end_comment

begin_define
define|#
directive|define
name|RNDIS_HEADER_OFFSET
value|8
end_define

begin_comment
comment|/* bytes */
end_comment

begin_define
define|#
directive|define
name|RNDIS_DATA_OFFSET
value|((uint32_t)(sizeof(struct urndis_packet_msg) - RNDIS_HEADER_OFFSET))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IF_URNDISREG_H_ */
end_comment

end_unit

