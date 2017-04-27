begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ng_btsocket.h  */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2001-2002 Maksim Yevmenkin<m_evmenkin@yahoo.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Id: ng_btsocket.h,v 1.8 2003/04/26 22:32:10 max Exp $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETGRAPH_BTSOCKET_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETGRAPH_BTSOCKET_H_
end_define

begin_comment
comment|/*  * Bluetooth protocols  */
end_comment

begin_define
define|#
directive|define
name|BLUETOOTH_PROTO_HCI
value|134
end_define

begin_comment
comment|/* HCI protocol number */
end_comment

begin_define
define|#
directive|define
name|BLUETOOTH_PROTO_L2CAP
value|135
end_define

begin_comment
comment|/* L2CAP protocol number */
end_comment

begin_define
define|#
directive|define
name|BLUETOOTH_PROTO_RFCOMM
value|136
end_define

begin_comment
comment|/* RFCOMM protocol number */
end_comment

begin_define
define|#
directive|define
name|BLUETOOTH_PROTO_SCO
value|137
end_define

begin_comment
comment|/* SCO protocol number */
end_comment

begin_comment
comment|/*  * Bluetooth version of struct sockaddr for raw HCI sockets  */
end_comment

begin_struct
struct|struct
name|sockaddr_hci
block|{
name|u_char
name|hci_len
decl_stmt|;
comment|/* total length */
name|u_char
name|hci_family
decl_stmt|;
comment|/* address family */
name|char
name|hci_node
index|[
literal|32
index|]
decl_stmt|;
comment|/* address (size == NG_NODESIZ ) */
block|}
struct|;
end_struct

begin_comment
comment|/* Raw HCI socket options */
end_comment

begin_define
define|#
directive|define
name|SOL_HCI_RAW
value|0x0802
end_define

begin_comment
comment|/* socket options level */
end_comment

begin_define
define|#
directive|define
name|SO_HCI_RAW_FILTER
value|1
end_define

begin_comment
comment|/* get/set filter on socket */
end_comment

begin_define
define|#
directive|define
name|SO_HCI_RAW_DIRECTION
value|2
end_define

begin_comment
comment|/* turn on/off direction info */
end_comment

begin_define
define|#
directive|define
name|SCM_HCI_RAW_DIRECTION
value|SO_HCI_RAW_DIRECTION
end_define

begin_comment
comment|/* cmsg_type  */
end_comment

begin_comment
comment|/*  * Raw HCI socket filter.  *  * For packet mask use (1<< (HCI packet indicator - 1))  * For event mask use (1<< (Event - 1))  */
end_comment

begin_struct
struct|struct
name|ng_btsocket_hci_raw_filter
block|{
name|bitstr_t
name|bit_decl
argument_list|(
name|packet_mask
argument_list|,
literal|32
argument_list|)
decl_stmt|;
name|bitstr_t
name|bit_decl
argument_list|(
name|event_mask
argument_list|,
operator|(
name|NG_HCI_EVENT_MASK_SIZE
operator|*
literal|8
operator|)
argument_list|)
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Raw HCI sockets ioctl's  */
end_comment

begin_comment
comment|/* Get state */
end_comment

begin_struct
struct|struct
name|ng_btsocket_hci_raw_node_state
block|{
name|ng_hci_node_state_ep
name|state
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SIOC_HCI_RAW_NODE_GET_STATE
define|\
value|_IOWR('b', NGM_HCI_NODE_GET_STATE, \ 		struct ng_btsocket_hci_raw_node_state)
end_define

begin_comment
comment|/* Initialize */
end_comment

begin_define
define|#
directive|define
name|SIOC_HCI_RAW_NODE_INIT
define|\
value|_IO('b', NGM_HCI_NODE_INIT)
end_define

begin_comment
comment|/* Get/Set debug level */
end_comment

begin_struct
struct|struct
name|ng_btsocket_hci_raw_node_debug
block|{
name|ng_hci_node_debug_ep
name|debug
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SIOC_HCI_RAW_NODE_GET_DEBUG
define|\
value|_IOWR('b', NGM_HCI_NODE_GET_DEBUG, \ 		struct ng_btsocket_hci_raw_node_debug)
end_define

begin_define
define|#
directive|define
name|SIOC_HCI_RAW_NODE_SET_DEBUG
define|\
value|_IOWR('b', NGM_HCI_NODE_SET_DEBUG, \ 		struct ng_btsocket_hci_raw_node_debug)
end_define

begin_comment
comment|/* Get buffer info */
end_comment

begin_struct
struct|struct
name|ng_btsocket_hci_raw_node_buffer
block|{
name|ng_hci_node_buffer_ep
name|buffer
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SIOC_HCI_RAW_NODE_GET_BUFFER
define|\
value|_IOWR('b', NGM_HCI_NODE_GET_BUFFER, \ 		struct ng_btsocket_hci_raw_node_buffer)
end_define

begin_comment
comment|/* Get BD_ADDR */
end_comment

begin_struct
struct|struct
name|ng_btsocket_hci_raw_node_bdaddr
block|{
name|bdaddr_t
name|bdaddr
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SIOC_HCI_RAW_NODE_GET_BDADDR
define|\
value|_IOWR('b', NGM_HCI_NODE_GET_BDADDR, \ 		struct ng_btsocket_hci_raw_node_bdaddr)
end_define

begin_comment
comment|/* Get features */
end_comment

begin_struct
struct|struct
name|ng_btsocket_hci_raw_node_features
block|{
name|u_int8_t
name|features
index|[
name|NG_HCI_FEATURES_SIZE
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SIOC_HCI_RAW_NODE_GET_FEATURES
define|\
value|_IOWR('b', NGM_HCI_NODE_GET_FEATURES, \ 		struct ng_btsocket_hci_raw_node_features)
end_define

begin_comment
comment|/* Get stat */
end_comment

begin_struct
struct|struct
name|ng_btsocket_hci_raw_node_stat
block|{
name|ng_hci_node_stat_ep
name|stat
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SIOC_HCI_RAW_NODE_GET_STAT
define|\
value|_IOWR('b', NGM_HCI_NODE_GET_STAT, \ 		struct ng_btsocket_hci_raw_node_stat)
end_define

begin_comment
comment|/* Reset stat */
end_comment

begin_define
define|#
directive|define
name|SIOC_HCI_RAW_NODE_RESET_STAT
define|\
value|_IO('b', NGM_HCI_NODE_RESET_STAT)
end_define

begin_comment
comment|/* Flush neighbor cache */
end_comment

begin_define
define|#
directive|define
name|SIOC_HCI_RAW_NODE_FLUSH_NEIGHBOR_CACHE
define|\
value|_IO('b', NGM_HCI_NODE_FLUSH_NEIGHBOR_CACHE)
end_define

begin_comment
comment|/* Get neighbor cache */
end_comment

begin_struct
struct|struct
name|ng_btsocket_hci_raw_node_neighbor_cache
block|{
name|u_int32_t
name|num_entries
decl_stmt|;
name|ng_hci_node_neighbor_cache_entry_ep
modifier|*
name|entries
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SIOC_HCI_RAW_NODE_GET_NEIGHBOR_CACHE
define|\
value|_IOWR('b', NGM_HCI_NODE_GET_NEIGHBOR_CACHE, \ 		struct ng_btsocket_hci_raw_node_neighbor_cache)
end_define

begin_comment
comment|/* Get connection list */
end_comment

begin_struct
struct|struct
name|ng_btsocket_hci_raw_con_list
block|{
name|u_int32_t
name|num_connections
decl_stmt|;
name|ng_hci_node_con_ep
modifier|*
name|connections
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SIOC_HCI_RAW_NODE_GET_CON_LIST
define|\
value|_IOWR('b', NGM_HCI_NODE_GET_CON_LIST, \ 		struct ng_btsocket_hci_raw_con_list)
end_define

begin_comment
comment|/* Get/Set link policy settings mask */
end_comment

begin_struct
struct|struct
name|ng_btsocket_hci_raw_node_link_policy_mask
block|{
name|ng_hci_node_link_policy_mask_ep
name|policy_mask
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SIOC_HCI_RAW_NODE_GET_LINK_POLICY_MASK
define|\
value|_IOWR('b', NGM_HCI_NODE_GET_LINK_POLICY_SETTINGS_MASK, \ 		struct ng_btsocket_hci_raw_node_link_policy_mask)
end_define

begin_define
define|#
directive|define
name|SIOC_HCI_RAW_NODE_SET_LINK_POLICY_MASK
define|\
value|_IOWR('b', NGM_HCI_NODE_SET_LINK_POLICY_SETTINGS_MASK, \ 		struct ng_btsocket_hci_raw_node_link_policy_mask)
end_define

begin_comment
comment|/* Get/Set packet mask */
end_comment

begin_struct
struct|struct
name|ng_btsocket_hci_raw_node_packet_mask
block|{
name|ng_hci_node_packet_mask_ep
name|packet_mask
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SIOC_HCI_RAW_NODE_GET_PACKET_MASK
define|\
value|_IOWR('b', NGM_HCI_NODE_GET_PACKET_MASK, \ 		struct ng_btsocket_hci_raw_node_packet_mask)
end_define

begin_define
define|#
directive|define
name|SIOC_HCI_RAW_NODE_SET_PACKET_MASK
define|\
value|_IOWR('b', NGM_HCI_NODE_SET_PACKET_MASK, \ 		struct ng_btsocket_hci_raw_node_packet_mask)
end_define

begin_comment
comment|/* Get/Set role switch */
end_comment

begin_struct
struct|struct
name|ng_btsocket_hci_raw_node_role_switch
block|{
name|ng_hci_node_role_switch_ep
name|role_switch
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SIOC_HCI_RAW_NODE_GET_ROLE_SWITCH
define|\
value|_IOWR('b', NGM_HCI_NODE_GET_ROLE_SWITCH, \ 		struct ng_btsocket_hci_raw_node_role_switch)
end_define

begin_define
define|#
directive|define
name|SIOC_HCI_RAW_NODE_SET_ROLE_SWITCH
define|\
value|_IOWR('b', NGM_HCI_NODE_SET_ROLE_SWITCH, \ 		struct ng_btsocket_hci_raw_node_role_switch)
end_define

begin_comment
comment|/* Get list of HCI node names */
end_comment

begin_struct
struct|struct
name|ng_btsocket_hci_raw_node_list_names
block|{
name|u_int32_t
name|num_names
decl_stmt|;
name|struct
name|nodeinfo
modifier|*
name|names
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SIOC_HCI_RAW_NODE_LIST_NAMES
define|\
value|_IOWR('b', NGM_HCI_NODE_LIST_NAMES, \ 		struct ng_btsocket_hci_raw_node_list_names)
end_define

begin_comment
comment|/*  * XXX FIXME: probably does not belong here  * Bluetooth version of struct sockaddr for SCO sockets (SEQPACKET)  */
end_comment

begin_struct
struct|struct
name|sockaddr_sco
block|{
name|u_char
name|sco_len
decl_stmt|;
comment|/* total length */
name|u_char
name|sco_family
decl_stmt|;
comment|/* address family */
name|bdaddr_t
name|sco_bdaddr
decl_stmt|;
comment|/* address */
block|}
struct|;
end_struct

begin_comment
comment|/* SCO socket options */
end_comment

begin_define
define|#
directive|define
name|SOL_SCO
value|0x0209
end_define

begin_comment
comment|/* socket options level */
end_comment

begin_define
define|#
directive|define
name|SO_SCO_MTU
value|1
end_define

begin_comment
comment|/* get sockets mtu */
end_comment

begin_define
define|#
directive|define
name|SO_SCO_CONNINFO
value|2
end_define

begin_comment
comment|/* get HCI connection handle */
end_comment

begin_comment
comment|/*  * XXX FIXME: probably does not belong here  * Bluetooth version of struct sockaddr for L2CAP sockets (RAW and SEQPACKET)  */
end_comment

begin_struct
struct|struct
name|sockaddr_l2cap_compat
block|{
name|u_char
name|l2cap_len
decl_stmt|;
comment|/* total length */
name|u_char
name|l2cap_family
decl_stmt|;
comment|/* address family */
name|u_int16_t
name|l2cap_psm
decl_stmt|;
comment|/* PSM (Protocol/Service Multiplexor) */
name|bdaddr_t
name|l2cap_bdaddr
decl_stmt|;
comment|/* address */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sockaddr_l2cap
block|{
name|u_char
name|l2cap_len
decl_stmt|;
comment|/* total length */
name|u_char
name|l2cap_family
decl_stmt|;
comment|/* address family */
name|u_int16_t
name|l2cap_psm
decl_stmt|;
comment|/* PSM (Protocol/Service Multiplexor) */
name|bdaddr_t
name|l2cap_bdaddr
decl_stmt|;
comment|/* address */
name|u_int16_t
name|l2cap_cid
decl_stmt|;
comment|/*cid*/
name|u_int8_t
name|l2cap_bdaddr_type
decl_stmt|;
comment|/*address type*/
block|}
struct|;
end_struct

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|L2CAP_SOCKET_CHECKED
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_KERNEL
argument_list|)
end_if

begin_warning
warning|#
directive|warning
literal|"Make sure new member of socket address initialized"
end_warning

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* L2CAP socket options */
end_comment

begin_define
define|#
directive|define
name|SOL_L2CAP
value|0x1609
end_define

begin_comment
comment|/* socket option level */
end_comment

begin_define
define|#
directive|define
name|SO_L2CAP_IMTU
value|1
end_define

begin_comment
comment|/* get/set incoming MTU */
end_comment

begin_define
define|#
directive|define
name|SO_L2CAP_OMTU
value|2
end_define

begin_comment
comment|/* get outgoing (peer incoming) MTU */
end_comment

begin_define
define|#
directive|define
name|SO_L2CAP_IFLOW
value|3
end_define

begin_comment
comment|/* get incoming flow spec. */
end_comment

begin_define
define|#
directive|define
name|SO_L2CAP_OFLOW
value|4
end_define

begin_comment
comment|/* get/set outgoing flow spec. */
end_comment

begin_define
define|#
directive|define
name|SO_L2CAP_FLUSH
value|5
end_define

begin_comment
comment|/* get/set flush timeout */
end_comment

begin_define
define|#
directive|define
name|SO_L2CAP_ENCRYPTED
value|6
end_define

begin_comment
comment|/* get/set whether wait for encryptin on connect */
end_comment

begin_comment
comment|/*  * Raw L2CAP sockets ioctl's  */
end_comment

begin_comment
comment|/* Ping */
end_comment

begin_struct
struct|struct
name|ng_btsocket_l2cap_raw_ping
block|{
name|u_int32_t
name|result
decl_stmt|;
name|u_int32_t
name|echo_size
decl_stmt|;
name|u_int8_t
modifier|*
name|echo_data
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SIOC_L2CAP_L2CA_PING
define|\
value|_IOWR('b', NGM_L2CAP_L2CA_PING, \ 		struct ng_btsocket_l2cap_raw_ping)
end_define

begin_comment
comment|/* Get info */
end_comment

begin_struct
struct|struct
name|ng_btsocket_l2cap_raw_get_info
block|{
name|u_int32_t
name|result
decl_stmt|;
name|u_int32_t
name|info_type
decl_stmt|;
name|u_int32_t
name|info_size
decl_stmt|;
name|u_int8_t
modifier|*
name|info_data
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SIOC_L2CAP_L2CA_GET_INFO
define|\
value|_IOWR('b', NGM_L2CAP_L2CA_GET_INFO, \ 		struct ng_btsocket_l2cap_raw_get_info)
end_define

begin_comment
comment|/* Get flags */
end_comment

begin_struct
struct|struct
name|ng_btsocket_l2cap_raw_node_flags
block|{
name|ng_l2cap_node_flags_ep
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SIOC_L2CAP_NODE_GET_FLAGS
define|\
value|_IOWR('b', NGM_L2CAP_NODE_GET_FLAGS, \ 		struct ng_btsocket_l2cap_raw_node_flags)
end_define

begin_comment
comment|/* Get/Set debug level */
end_comment

begin_struct
struct|struct
name|ng_btsocket_l2cap_raw_node_debug
block|{
name|ng_l2cap_node_debug_ep
name|debug
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SIOC_L2CAP_NODE_GET_DEBUG
define|\
value|_IOWR('b', NGM_L2CAP_NODE_GET_DEBUG, \ 		struct ng_btsocket_l2cap_raw_node_debug)
end_define

begin_define
define|#
directive|define
name|SIOC_L2CAP_NODE_SET_DEBUG
define|\
value|_IOWR('b', NGM_L2CAP_NODE_SET_DEBUG, \ 		struct ng_btsocket_l2cap_raw_node_debug)
end_define

begin_comment
comment|/* Get connection list */
end_comment

begin_struct
struct|struct
name|ng_btsocket_l2cap_raw_con_list
block|{
name|u_int32_t
name|num_connections
decl_stmt|;
name|ng_l2cap_node_con_ep
modifier|*
name|connections
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SIOC_L2CAP_NODE_GET_CON_LIST
define|\
value|_IOWR('b', NGM_L2CAP_NODE_GET_CON_LIST, \ 		struct ng_btsocket_l2cap_raw_con_list)
end_define

begin_comment
comment|/* Get channel list */
end_comment

begin_struct
struct|struct
name|ng_btsocket_l2cap_raw_chan_list
block|{
name|u_int32_t
name|num_channels
decl_stmt|;
name|ng_l2cap_node_chan_ep
modifier|*
name|channels
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SIOC_L2CAP_NODE_GET_CHAN_LIST
define|\
value|_IOWR('b', NGM_L2CAP_NODE_GET_CHAN_LIST, \ 		struct ng_btsocket_l2cap_raw_chan_list)
end_define

begin_comment
comment|/* Get/Set auto disconnect timeout */
end_comment

begin_struct
struct|struct
name|ng_btsocket_l2cap_raw_auto_discon_timo
block|{
name|ng_l2cap_node_auto_discon_ep
name|timeout
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SIOC_L2CAP_NODE_GET_AUTO_DISCON_TIMO
define|\
value|_IOWR('b', NGM_L2CAP_NODE_GET_AUTO_DISCON_TIMO, \ 		struct ng_btsocket_l2cap_raw_auto_discon_timo)
end_define

begin_define
define|#
directive|define
name|SIOC_L2CAP_NODE_SET_AUTO_DISCON_TIMO
define|\
value|_IOWR('b', NGM_L2CAP_NODE_SET_AUTO_DISCON_TIMO, \ 		struct ng_btsocket_l2cap_raw_auto_discon_timo)
end_define

begin_comment
comment|/*  * XXX FIXME: probably does not belong here  * Bluetooth version of struct sockaddr for RFCOMM sockets (STREAM)  */
end_comment

begin_struct
struct|struct
name|sockaddr_rfcomm
block|{
name|u_char
name|rfcomm_len
decl_stmt|;
comment|/* total length */
name|u_char
name|rfcomm_family
decl_stmt|;
comment|/* address family */
name|bdaddr_t
name|rfcomm_bdaddr
decl_stmt|;
comment|/* address */
name|u_int8_t
name|rfcomm_channel
decl_stmt|;
comment|/* channel */
block|}
struct|;
end_struct

begin_comment
comment|/* Flow control information */
end_comment

begin_struct
struct|struct
name|ng_btsocket_rfcomm_fc_info
block|{
name|u_int8_t
name|lmodem
decl_stmt|;
comment|/* modem signals (local) */
name|u_int8_t
name|rmodem
decl_stmt|;
comment|/* modem signals (remote) */
name|u_int8_t
name|tx_cred
decl_stmt|;
comment|/* TX credits */
name|u_int8_t
name|rx_cred
decl_stmt|;
comment|/* RX credits */
name|u_int8_t
name|cfc
decl_stmt|;
comment|/* credit flow control */
name|u_int8_t
name|reserved
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* STREAM RFCOMM socket options */
end_comment

begin_define
define|#
directive|define
name|SOL_RFCOMM
value|0x0816
end_define

begin_comment
comment|/* socket options level */
end_comment

begin_define
define|#
directive|define
name|SO_RFCOMM_MTU
value|1
end_define

begin_comment
comment|/* get channel MTU */
end_comment

begin_define
define|#
directive|define
name|SO_RFCOMM_FC_INFO
value|2
end_define

begin_comment
comment|/* get flow control information */
end_comment

begin_comment
comment|/*   * Netgraph node type name and cookie   */
end_comment

begin_define
define|#
directive|define
name|NG_BTSOCKET_HCI_RAW_NODE_TYPE
value|"btsock_hci_raw"
end_define

begin_define
define|#
directive|define
name|NG_BTSOCKET_L2CAP_RAW_NODE_TYPE
value|"btsock_l2c_raw"
end_define

begin_define
define|#
directive|define
name|NG_BTSOCKET_L2CAP_NODE_TYPE
value|"btsock_l2c"
end_define

begin_define
define|#
directive|define
name|NG_BTSOCKET_SCO_NODE_TYPE
value|"btsock_sco"
end_define

begin_comment
comment|/*  * Debug levels   */
end_comment

begin_define
define|#
directive|define
name|NG_BTSOCKET_ALERT_LEVEL
value|1
end_define

begin_define
define|#
directive|define
name|NG_BTSOCKET_ERR_LEVEL
value|2
end_define

begin_define
define|#
directive|define
name|NG_BTSOCKET_WARN_LEVEL
value|3
end_define

begin_define
define|#
directive|define
name|NG_BTSOCKET_INFO_LEVEL
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NETGRAPH_BTSOCKET_H_ */
end_comment

end_unit

