begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2017-2018 Cavium, Inc.   * All rights reserved.  *  *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *  *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *  *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  *  POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__TCP_COMMON__
end_ifndef

begin_define
define|#
directive|define
name|__TCP_COMMON__
end_define

begin_comment
comment|/********************/
end_comment

begin_comment
comment|/* TCP FW CONSTANTS */
end_comment

begin_comment
comment|/********************/
end_comment

begin_define
define|#
directive|define
name|TCP_INVALID_TIMEOUT_VAL
value|-1
end_define

begin_comment
comment|/*  * OOO opaque data received from LL2  */
end_comment

begin_struct
struct|struct
name|ooo_opaque
block|{
name|__le32
name|cid
comment|/* connection ID  */
decl_stmt|;
name|u8
name|drop_isle
comment|/* isle number of the first isle to drop */
decl_stmt|;
name|u8
name|drop_size
comment|/* number of isles to drop */
decl_stmt|;
name|u8
name|ooo_opcode
comment|/* (use enum tcp_seg_placement_event) */
decl_stmt|;
name|u8
name|ooo_isle
comment|/* OOO isle number to add the packet to */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * tcp connect mode enum  */
end_comment

begin_enum
enum|enum
name|tcp_connect_mode
block|{
name|TCP_CONNECT_ACTIVE
block|,
name|TCP_CONNECT_PASSIVE
block|,
name|MAX_TCP_CONNECT_MODE
block|}
enum|;
end_enum

begin_comment
comment|/*  * tcp function init parameters  */
end_comment

begin_struct
struct|struct
name|tcp_init_params
block|{
name|__le32
name|two_msl_timer
comment|/* 2MSL (used for TIME_WAIT state) timeout value */
decl_stmt|;
name|__le16
name|tx_sws_timer
comment|/* Transmission silly window syndrom timeout value */
decl_stmt|;
name|u8
name|maxFinRT
comment|/* Minimum Fin RT */
decl_stmt|;
name|u8
name|reserved
index|[
literal|9
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * tcp IPv4/IPv6 enum  */
end_comment

begin_enum
enum|enum
name|tcp_ip_version
block|{
name|TCP_IPV4
block|,
name|TCP_IPV6
block|,
name|MAX_TCP_IP_VERSION
block|}
enum|;
end_enum

begin_comment
comment|/*  * tcp offload parameters  */
end_comment

begin_struct
struct|struct
name|tcp_offload_params
block|{
name|__le16
name|local_mac_addr_lo
decl_stmt|;
name|__le16
name|local_mac_addr_mid
decl_stmt|;
name|__le16
name|local_mac_addr_hi
decl_stmt|;
name|__le16
name|remote_mac_addr_lo
decl_stmt|;
name|__le16
name|remote_mac_addr_mid
decl_stmt|;
name|__le16
name|remote_mac_addr_hi
decl_stmt|;
name|__le16
name|vlan_id
decl_stmt|;
name|u8
name|flags
decl_stmt|;
define|#
directive|define
name|TCP_OFFLOAD_PARAMS_TS_EN_MASK
value|0x1
comment|/* timestamp enable */
define|#
directive|define
name|TCP_OFFLOAD_PARAMS_TS_EN_SHIFT
value|0
define|#
directive|define
name|TCP_OFFLOAD_PARAMS_DA_EN_MASK
value|0x1
comment|/* delayed ack enabled */
define|#
directive|define
name|TCP_OFFLOAD_PARAMS_DA_EN_SHIFT
value|1
define|#
directive|define
name|TCP_OFFLOAD_PARAMS_KA_EN_MASK
value|0x1
comment|/* keep alive enabled */
define|#
directive|define
name|TCP_OFFLOAD_PARAMS_KA_EN_SHIFT
value|2
define|#
directive|define
name|TCP_OFFLOAD_PARAMS_NAGLE_EN_MASK
value|0x1
comment|/* nagle algorithm enabled */
define|#
directive|define
name|TCP_OFFLOAD_PARAMS_NAGLE_EN_SHIFT
value|3
define|#
directive|define
name|TCP_OFFLOAD_PARAMS_DA_CNT_EN_MASK
value|0x1
comment|/* delayed ack counter enabled */
define|#
directive|define
name|TCP_OFFLOAD_PARAMS_DA_CNT_EN_SHIFT
value|4
define|#
directive|define
name|TCP_OFFLOAD_PARAMS_FIN_SENT_MASK
value|0x1
comment|/* fin already sent to far end */
define|#
directive|define
name|TCP_OFFLOAD_PARAMS_FIN_SENT_SHIFT
value|5
define|#
directive|define
name|TCP_OFFLOAD_PARAMS_FIN_RECEIVED_MASK
value|0x1
comment|/* fin received */
define|#
directive|define
name|TCP_OFFLOAD_PARAMS_FIN_RECEIVED_SHIFT
value|6
define|#
directive|define
name|TCP_OFFLOAD_PARAMS_RESERVED0_MASK
value|0x1
define|#
directive|define
name|TCP_OFFLOAD_PARAMS_RESERVED0_SHIFT
value|7
name|u8
name|ip_version
decl_stmt|;
name|__le32
name|remote_ip
index|[
literal|4
index|]
decl_stmt|;
name|__le32
name|local_ip
index|[
literal|4
index|]
decl_stmt|;
name|__le32
name|flow_label
decl_stmt|;
name|u8
name|ttl
decl_stmt|;
name|u8
name|tos_or_tc
decl_stmt|;
name|__le16
name|remote_port
decl_stmt|;
name|__le16
name|local_port
decl_stmt|;
name|__le16
name|mss
comment|/* the mss derived from remote mss and local mtu, ipVersion options and tags */
decl_stmt|;
name|u8
name|rcv_wnd_scale
decl_stmt|;
name|u8
name|connect_mode
comment|/* TCP connect mode: use enum tcp_connect_mode */
decl_stmt|;
name|__le16
name|srtt
comment|/* in ms */
decl_stmt|;
name|__le32
name|cwnd
comment|/* absolute congestion window */
decl_stmt|;
name|__le32
name|ss_thresh
decl_stmt|;
name|__le16
name|reserved1
decl_stmt|;
name|u8
name|ka_max_probe_cnt
decl_stmt|;
name|u8
name|dup_ack_theshold
decl_stmt|;
name|__le32
name|rcv_next
decl_stmt|;
name|__le32
name|snd_una
decl_stmt|;
name|__le32
name|snd_next
decl_stmt|;
name|__le32
name|snd_max
decl_stmt|;
name|__le32
name|snd_wnd
comment|/* absolute send window (not scaled) */
decl_stmt|;
name|__le32
name|rcv_wnd
comment|/* absolute receive window (not scaled) */
decl_stmt|;
name|__le32
name|snd_wl1
comment|/* the segment sequence number used for the last window update */
decl_stmt|;
name|__le32
name|ts_recent
comment|/* The timestamp value to send in the next ACK */
decl_stmt|;
name|__le32
name|ts_recent_age
comment|/* The length of time, in ms, since the most recent timestamp was received */
decl_stmt|;
name|__le32
name|total_rt
comment|/* The total time, in ms, that has been spent retransmitting the current TCP segment */
decl_stmt|;
name|__le32
name|ka_timeout_delta
comment|/* The time remaining, in clock ticks, until the next keepalive timeout. A value of -1 indicates that the keepalive timer was not running when the connection was offloaded. */
decl_stmt|;
name|__le32
name|rt_timeout_delta
comment|/* The time remaining, in clock ticks, until the next retransmit timeout. A value of -1 indicates that the  retransmit timer was not running when the connection was offloaded. */
decl_stmt|;
name|u8
name|dup_ack_cnt
comment|/* The number of ACKs that have been accepted for the same sequence number */
decl_stmt|;
name|u8
name|snd_wnd_probe_cnt
comment|/* The current send window probe round */
decl_stmt|;
name|u8
name|ka_probe_cnt
comment|/* the number of keepalive probes that have been sent that have not received a response */
decl_stmt|;
name|u8
name|rt_cnt
comment|/* The number of retransmits that have been sent */
decl_stmt|;
name|__le16
name|rtt_var
comment|/* in ms */
decl_stmt|;
name|__le16
name|fw_internal
comment|/* fw internal use - initialize value = 0 */
decl_stmt|;
name|__le32
name|ka_timeout
comment|/* This member specifies, in ms, the timeout interval for inactivity before sending a keepalive probe */
decl_stmt|;
name|__le32
name|ka_interval
comment|/* This member specifies, in ms, the timeout after which to retransmit a keepalive frame if no response is received to a keepalive probe  */
decl_stmt|;
name|__le32
name|max_rt_time
comment|/* This member specifies, in ms, the maximum time that the offload target should spend retransmitting a segment */
decl_stmt|;
name|__le32
name|initial_rcv_wnd
comment|/* Initial receive window */
decl_stmt|;
name|u8
name|snd_wnd_scale
decl_stmt|;
name|u8
name|ack_frequency
comment|/* delayed ack counter threshold */
decl_stmt|;
name|__le16
name|da_timeout_value
comment|/* delayed ack timeout value in ms */
decl_stmt|;
name|__le32
name|reserved3
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * tcp offload parameters  */
end_comment

begin_struct
struct|struct
name|tcp_offload_params_opt2
block|{
name|__le16
name|local_mac_addr_lo
decl_stmt|;
name|__le16
name|local_mac_addr_mid
decl_stmt|;
name|__le16
name|local_mac_addr_hi
decl_stmt|;
name|__le16
name|remote_mac_addr_lo
decl_stmt|;
name|__le16
name|remote_mac_addr_mid
decl_stmt|;
name|__le16
name|remote_mac_addr_hi
decl_stmt|;
name|__le16
name|vlan_id
decl_stmt|;
name|u8
name|flags
decl_stmt|;
define|#
directive|define
name|TCP_OFFLOAD_PARAMS_OPT2_TS_EN_MASK
value|0x1
comment|/* timestamp enable */
define|#
directive|define
name|TCP_OFFLOAD_PARAMS_OPT2_TS_EN_SHIFT
value|0
define|#
directive|define
name|TCP_OFFLOAD_PARAMS_OPT2_DA_EN_MASK
value|0x1
comment|/* delayed ack enabled */
define|#
directive|define
name|TCP_OFFLOAD_PARAMS_OPT2_DA_EN_SHIFT
value|1
define|#
directive|define
name|TCP_OFFLOAD_PARAMS_OPT2_KA_EN_MASK
value|0x1
comment|/* keep alive enabled */
define|#
directive|define
name|TCP_OFFLOAD_PARAMS_OPT2_KA_EN_SHIFT
value|2
define|#
directive|define
name|TCP_OFFLOAD_PARAMS_OPT2_RESERVED0_MASK
value|0x1F
define|#
directive|define
name|TCP_OFFLOAD_PARAMS_OPT2_RESERVED0_SHIFT
value|3
name|u8
name|ip_version
decl_stmt|;
name|__le32
name|remote_ip
index|[
literal|4
index|]
decl_stmt|;
name|__le32
name|local_ip
index|[
literal|4
index|]
decl_stmt|;
name|__le32
name|flow_label
decl_stmt|;
name|u8
name|ttl
decl_stmt|;
name|u8
name|tos_or_tc
decl_stmt|;
name|__le16
name|remote_port
decl_stmt|;
name|__le16
name|local_port
decl_stmt|;
name|__le16
name|mss
comment|/* the mss derived from remote mss and local mtu, ipVersion options and tags */
decl_stmt|;
name|u8
name|rcv_wnd_scale
decl_stmt|;
name|u8
name|connect_mode
comment|/* TCP connect mode: use enum tcp_connect_mode */
decl_stmt|;
name|__le16
name|syn_ip_payload_length
comment|/* length of Tcp header in SYN packet - relevent for passive mode */
decl_stmt|;
name|__le32
name|syn_phy_addr_lo
comment|/* physical address (low) of SYN buffer - relevent for passive mode */
decl_stmt|;
name|__le32
name|syn_phy_addr_hi
comment|/* physical address (high) of SYN buffer - relevent for passive mode */
decl_stmt|;
name|__le32
name|reserved1
index|[
literal|22
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * tcp IPv4/IPv6 enum  */
end_comment

begin_enum
enum|enum
name|tcp_seg_placement_event
block|{
name|TCP_EVENT_ADD_PEN
block|,
name|TCP_EVENT_ADD_NEW_ISLE
block|,
name|TCP_EVENT_ADD_ISLE_RIGHT
block|,
name|TCP_EVENT_ADD_ISLE_LEFT
block|,
name|TCP_EVENT_JOIN
block|,
name|TCP_EVENT_DELETE_ISLES
block|,
name|TCP_EVENT_NOP
block|,
name|MAX_TCP_SEG_PLACEMENT_EVENT
block|}
enum|;
end_enum

begin_comment
comment|/*  * tcp init parameters  */
end_comment

begin_struct
struct|struct
name|tcp_update_params
block|{
name|__le16
name|flags
decl_stmt|;
define|#
directive|define
name|TCP_UPDATE_PARAMS_REMOTE_MAC_ADDR_CHANGED_MASK
value|0x1
define|#
directive|define
name|TCP_UPDATE_PARAMS_REMOTE_MAC_ADDR_CHANGED_SHIFT
value|0
define|#
directive|define
name|TCP_UPDATE_PARAMS_MSS_CHANGED_MASK
value|0x1
define|#
directive|define
name|TCP_UPDATE_PARAMS_MSS_CHANGED_SHIFT
value|1
define|#
directive|define
name|TCP_UPDATE_PARAMS_TTL_CHANGED_MASK
value|0x1
define|#
directive|define
name|TCP_UPDATE_PARAMS_TTL_CHANGED_SHIFT
value|2
define|#
directive|define
name|TCP_UPDATE_PARAMS_TOS_OR_TC_CHANGED_MASK
value|0x1
define|#
directive|define
name|TCP_UPDATE_PARAMS_TOS_OR_TC_CHANGED_SHIFT
value|3
define|#
directive|define
name|TCP_UPDATE_PARAMS_KA_TIMEOUT_CHANGED_MASK
value|0x1
define|#
directive|define
name|TCP_UPDATE_PARAMS_KA_TIMEOUT_CHANGED_SHIFT
value|4
define|#
directive|define
name|TCP_UPDATE_PARAMS_KA_INTERVAL_CHANGED_MASK
value|0x1
define|#
directive|define
name|TCP_UPDATE_PARAMS_KA_INTERVAL_CHANGED_SHIFT
value|5
define|#
directive|define
name|TCP_UPDATE_PARAMS_MAX_RT_TIME_CHANGED_MASK
value|0x1
define|#
directive|define
name|TCP_UPDATE_PARAMS_MAX_RT_TIME_CHANGED_SHIFT
value|6
define|#
directive|define
name|TCP_UPDATE_PARAMS_FLOW_LABEL_CHANGED_MASK
value|0x1
define|#
directive|define
name|TCP_UPDATE_PARAMS_FLOW_LABEL_CHANGED_SHIFT
value|7
define|#
directive|define
name|TCP_UPDATE_PARAMS_INITIAL_RCV_WND_CHANGED_MASK
value|0x1
define|#
directive|define
name|TCP_UPDATE_PARAMS_INITIAL_RCV_WND_CHANGED_SHIFT
value|8
define|#
directive|define
name|TCP_UPDATE_PARAMS_KA_MAX_PROBE_CNT_CHANGED_MASK
value|0x1
define|#
directive|define
name|TCP_UPDATE_PARAMS_KA_MAX_PROBE_CNT_CHANGED_SHIFT
value|9
define|#
directive|define
name|TCP_UPDATE_PARAMS_KA_EN_CHANGED_MASK
value|0x1
define|#
directive|define
name|TCP_UPDATE_PARAMS_KA_EN_CHANGED_SHIFT
value|10
define|#
directive|define
name|TCP_UPDATE_PARAMS_NAGLE_EN_CHANGED_MASK
value|0x1
define|#
directive|define
name|TCP_UPDATE_PARAMS_NAGLE_EN_CHANGED_SHIFT
value|11
define|#
directive|define
name|TCP_UPDATE_PARAMS_KA_EN_MASK
value|0x1
define|#
directive|define
name|TCP_UPDATE_PARAMS_KA_EN_SHIFT
value|12
define|#
directive|define
name|TCP_UPDATE_PARAMS_NAGLE_EN_MASK
value|0x1
define|#
directive|define
name|TCP_UPDATE_PARAMS_NAGLE_EN_SHIFT
value|13
define|#
directive|define
name|TCP_UPDATE_PARAMS_KA_RESTART_MASK
value|0x1
define|#
directive|define
name|TCP_UPDATE_PARAMS_KA_RESTART_SHIFT
value|14
define|#
directive|define
name|TCP_UPDATE_PARAMS_RETRANSMIT_RESTART_MASK
value|0x1
define|#
directive|define
name|TCP_UPDATE_PARAMS_RETRANSMIT_RESTART_SHIFT
value|15
name|__le16
name|remote_mac_addr_lo
decl_stmt|;
name|__le16
name|remote_mac_addr_mid
decl_stmt|;
name|__le16
name|remote_mac_addr_hi
decl_stmt|;
name|__le16
name|mss
decl_stmt|;
name|u8
name|ttl
decl_stmt|;
name|u8
name|tos_or_tc
decl_stmt|;
name|__le32
name|ka_timeout
decl_stmt|;
name|__le32
name|ka_interval
decl_stmt|;
name|__le32
name|max_rt_time
decl_stmt|;
name|__le32
name|flow_label
decl_stmt|;
name|__le32
name|initial_rcv_wnd
decl_stmt|;
name|u8
name|ka_max_probe_cnt
decl_stmt|;
name|u8
name|reserved1
index|[
literal|7
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * toe upload parameters  */
end_comment

begin_struct
struct|struct
name|tcp_upload_params
block|{
name|__le32
name|rcv_next
decl_stmt|;
name|__le32
name|snd_una
decl_stmt|;
name|__le32
name|snd_next
decl_stmt|;
name|__le32
name|snd_max
decl_stmt|;
name|__le32
name|snd_wnd
comment|/* absolute send window (not scaled) */
decl_stmt|;
name|__le32
name|rcv_wnd
comment|/* absolute receive window (not scaled) */
decl_stmt|;
name|__le32
name|snd_wl1
comment|/* the segment sequence number used for the last window update */
decl_stmt|;
name|__le32
name|cwnd
comment|/* absolute congestion window */
decl_stmt|;
name|__le32
name|ss_thresh
decl_stmt|;
name|__le16
name|srtt
comment|/* in ms */
decl_stmt|;
name|__le16
name|rtt_var
comment|/* in ms */
decl_stmt|;
name|__le32
name|ts_time
comment|/* The current value of the adjusted timestamp */
decl_stmt|;
name|__le32
name|ts_recent
comment|/* The timestamp value to send in the next ACK */
decl_stmt|;
name|__le32
name|ts_recent_age
comment|/* The length of time, in ms, since the most recent timestamp was received */
decl_stmt|;
name|__le32
name|total_rt
comment|/* The total time, in ms, that has been spent retransmitting the current TCP segment */
decl_stmt|;
name|__le32
name|ka_timeout_delta
comment|/* The time remaining, in clock ticks, until the next keepalive timeout. A value of -1 indicates that the keepalive timer was not running when the connection was offloaded. */
decl_stmt|;
name|__le32
name|rt_timeout_delta
comment|/* The time remaining, in clock ticks, until the next retransmit timeout. A value of -1 indicates that the  retransmit timer was not running when the connection was offloaded. */
decl_stmt|;
name|u8
name|dup_ack_cnt
comment|/* The number of ACKs that have been accepted for the same sequence number */
decl_stmt|;
name|u8
name|snd_wnd_probe_cnt
comment|/* The current send window probe round */
decl_stmt|;
name|u8
name|ka_probe_cnt
comment|/* the number of keepalive probes that have been sent that have not received a response */
decl_stmt|;
name|u8
name|rt_cnt
comment|/* The number of retransmits that have been sent */
decl_stmt|;
name|__le32
name|reserved
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __TCP_COMMON__ */
end_comment

end_unit

