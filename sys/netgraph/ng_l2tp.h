begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001-2002 Packet Design, LLC.  * All rights reserved.  *   * Subject to the following obligations and disclaimer of warranty,  * use and redistribution of this software, in source or object code  * forms, with or without modifications are expressly permitted by  * Packet Design; provided, however, that:  *   *    (i)  Any and all reproductions of the source or object code  *         must include the copyright notice above and the following  *         disclaimer of warranties; and  *    (ii) No rights are granted, in any manner or form, to use  *         Packet Design trademarks, including the mark "PACKET DESIGN"  *         on advertising, endorsements, or otherwise except as such  *         appears in the above copyright notice or in the software.  *   * THIS SOFTWARE IS BEING PROVIDED BY PACKET DESIGN "AS IS", AND  * TO THE MAXIMUM EXTENT PERMITTED BY LAW, PACKET DESIGN MAKES NO  * REPRESENTATIONS OR WARRANTIES, EXPRESS OR IMPLIED, REGARDING  * THIS SOFTWARE, INCLUDING WITHOUT LIMITATION, ANY AND ALL IMPLIED  * WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE,  * OR NON-INFRINGEMENT.  PACKET DESIGN DOES NOT WARRANT, GUARANTEE,  * OR MAKE ANY REPRESENTATIONS REGARDING THE USE OF, OR THE RESULTS  * OF THE USE OF THIS SOFTWARE IN TERMS OF ITS CORRECTNESS, ACCURACY,  * RELIABILITY OR OTHERWISE.  IN NO EVENT SHALL PACKET DESIGN BE  * LIABLE FOR ANY DAMAGES RESULTING FROM OR ARISING OUT OF ANY USE  * OF THIS SOFTWARE, INCLUDING WITHOUT LIMITATION, ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, PUNITIVE, OR CONSEQUENTIAL  * DAMAGES, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES, LOSS OF  * USE, DATA OR PROFITS, HOWEVER CAUSED AND UNDER ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF  * THE USE OF THIS SOFTWARE, EVEN IF PACKET DESIGN IS ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  *   * Author: Archie Cobbs<archie@freebsd.org>  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETGRAPH_NG_L2TP_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETGRAPH_NG_L2TP_H_
end_define

begin_comment
comment|/* Node type name and magic cookie */
end_comment

begin_define
define|#
directive|define
name|NG_L2TP_NODE_TYPE
value|"l2tp"
end_define

begin_define
define|#
directive|define
name|NGM_L2TP_COOKIE
value|1091515793
end_define

begin_comment
comment|/* Hook names */
end_comment

begin_define
define|#
directive|define
name|NG_L2TP_HOOK_CTRL
value|"ctrl"
end_define

begin_comment
comment|/* control channel hook */
end_comment

begin_define
define|#
directive|define
name|NG_L2TP_HOOK_LOWER
value|"lower"
end_define

begin_comment
comment|/* hook to lower layers */
end_comment

begin_comment
comment|/* Session hooks: prefix plus hex session ID, e.g., "session_3e14" */
end_comment

begin_define
define|#
directive|define
name|NG_L2TP_HOOK_SESSION_P
value|"session_"
end_define

begin_comment
comment|/* session data hook (prefix) */
end_comment

begin_define
define|#
directive|define
name|NG_L2TP_HOOK_SESSION_F
value|"session_%04x"
end_define

begin_comment
comment|/* session data hook (format) */
end_comment

begin_comment
comment|/* Set intial sequence numbers to not yet enabled node. */
end_comment

begin_struct
struct|struct
name|ng_l2tp_seq_config
block|{
name|u_int16_t
name|ns
decl_stmt|;
comment|/* sequence number to send next */
name|u_int16_t
name|nr
decl_stmt|;
comment|/* sequence number to be recved next */
name|u_int16_t
name|rack
decl_stmt|;
comment|/* last 'nr' received */
name|u_int16_t
name|xack
decl_stmt|;
comment|/* last 'nr' sent */
block|}
struct|;
end_struct

begin_comment
comment|/* Keep this in sync with the above structure definition. */
end_comment

begin_define
define|#
directive|define
name|NG_L2TP_SEQ_CONFIG_TYPE_INFO
value|{			\ 	  { "ns",&ng_parse_uint16_type	},	\ 	  { "nr",&ng_parse_uint16_type	},	\ 	  { NULL }						\ }
end_define

begin_comment
comment|/* Configuration for a node */
end_comment

begin_struct
struct|struct
name|ng_l2tp_config
block|{
name|u_char
name|enabled
decl_stmt|;
comment|/* enables traffic flow */
name|u_char
name|match_id
decl_stmt|;
comment|/* tunnel id must match 'tunnel_id' */
name|u_int16_t
name|tunnel_id
decl_stmt|;
comment|/* local tunnel id */
name|u_int16_t
name|peer_id
decl_stmt|;
comment|/* peer's tunnel id */
name|u_int16_t
name|peer_win
decl_stmt|;
comment|/* peer's max recv window size */
name|u_int16_t
name|rexmit_max
decl_stmt|;
comment|/* max retransmits before failure */
name|u_int16_t
name|rexmit_max_to
decl_stmt|;
comment|/* max delay between retransmits */
block|}
struct|;
end_struct

begin_comment
comment|/* Keep this in sync with the above structure definition */
end_comment

begin_define
define|#
directive|define
name|NG_L2TP_CONFIG_TYPE_INFO
value|{			\ 	  { "enabled",&ng_parse_uint8_type	},	\ 	  { "match_id",&ng_parse_uint8_type	},	\ 	  { "tunnel_id",&ng_parse_hint16_type	},	\ 	  { "peer_id",&ng_parse_hint16_type	},	\ 	  { "peer_win",&ng_parse_uint16_type	},	\ 	  { "rexmit_max",&ng_parse_uint16_type	},	\ 	  { "rexmit_max_to",&ng_parse_uint16_type	},	\ 	  { NULL }						\ }
end_define

begin_comment
comment|/* Configuration for a session hook */
end_comment

begin_struct
struct|struct
name|ng_l2tp_sess_config
block|{
name|u_int16_t
name|session_id
decl_stmt|;
comment|/* local session id */
name|u_int16_t
name|peer_id
decl_stmt|;
comment|/* peer's session id */
name|u_char
name|control_dseq
decl_stmt|;
comment|/* whether we control data sequencing */
name|u_char
name|enable_dseq
decl_stmt|;
comment|/* whether to enable data sequencing */
name|u_char
name|include_length
decl_stmt|;
comment|/* whether to include length field */
block|}
struct|;
end_struct

begin_comment
comment|/* Keep this in sync with the above structure definition */
end_comment

begin_define
define|#
directive|define
name|NG_L2TP_SESS_CONFIG_TYPE_INFO
value|{			\ 	  { "session_id",&ng_parse_hint16_type	},	\ 	  { "peer_id",&ng_parse_hint16_type	},	\ 	  { "control_dseq",&ng_parse_uint8_type	},	\ 	  { "enable_dseq",&ng_parse_uint8_type	},	\ 	  { "include_length",&ng_parse_uint8_type	},	\ 	  { NULL }						\ }
end_define

begin_comment
comment|/* Statistics struct */
end_comment

begin_struct
struct|struct
name|ng_l2tp_stats
block|{
name|u_int32_t
name|xmitPackets
decl_stmt|;
comment|/* number of packets xmit */
name|u_int32_t
name|xmitOctets
decl_stmt|;
comment|/* number of octets xmit */
name|u_int32_t
name|xmitZLBs
decl_stmt|;
comment|/* ack-only packets transmitted */
name|u_int32_t
name|xmitDrops
decl_stmt|;
comment|/* xmits dropped due to full window */
name|u_int32_t
name|xmitTooBig
decl_stmt|;
comment|/* ctrl pkts dropped because too big */
name|u_int32_t
name|xmitInvalid
decl_stmt|;
comment|/* ctrl packets with no session ID */
name|u_int32_t
name|xmitDataTooBig
decl_stmt|;
comment|/* data pkts dropped because too big */
name|u_int32_t
name|xmitRetransmits
decl_stmt|;
comment|/* retransmitted packets */
name|u_int32_t
name|recvPackets
decl_stmt|;
comment|/* number of packets rec'd */
name|u_int32_t
name|recvOctets
decl_stmt|;
comment|/* number of octets rec'd */
name|u_int32_t
name|recvRunts
decl_stmt|;
comment|/* too short packets rec'd */
name|u_int32_t
name|recvInvalid
decl_stmt|;
comment|/* invalid packets rec'd */
name|u_int32_t
name|recvWrongTunnel
decl_stmt|;
comment|/* packets rec'd with wrong tunnel id */
name|u_int32_t
name|recvUnknownSID
decl_stmt|;
comment|/* pkts rec'd with unknown session id */
name|u_int32_t
name|recvBadAcks
decl_stmt|;
comment|/* ctrl pkts rec'd with invalid 'nr' */
name|u_int32_t
name|recvOutOfOrder
decl_stmt|;
comment|/* out of order ctrl pkts rec'd */
name|u_int32_t
name|recvDuplicates
decl_stmt|;
comment|/* duplicate ctrl pkts rec'd */
name|u_int32_t
name|recvDataDrops
decl_stmt|;
comment|/* dup/out of order data pkts rec'd */
name|u_int32_t
name|recvZLBs
decl_stmt|;
comment|/* ack-only packets rec'd */
name|u_int32_t
name|memoryFailures
decl_stmt|;
comment|/* times we couldn't allocate memory */
block|}
struct|;
end_struct

begin_comment
comment|/* Keep this in sync with the above structure definition */
end_comment

begin_define
define|#
directive|define
name|NG_L2TP_STATS_TYPE_INFO
value|{			\ 	  { "xmitPackets",&ng_parse_uint32_type	},	\ 	  { "xmitOctets",&ng_parse_uint32_type	},	\ 	  { "xmitZLBs",&ng_parse_uint32_type	},	\ 	  { "xmitDrops",&ng_parse_uint32_type	},	\ 	  { "xmitTooBig",&ng_parse_uint32_type	},	\ 	  { "xmitInvalid",&ng_parse_uint32_type	},	\ 	  { "xmitDataTooBig",&ng_parse_uint32_type	},	\ 	  { "xmitRetransmits",&ng_parse_uint32_type	},	\ 	  { "recvPackets",&ng_parse_uint32_type	},	\ 	  { "recvOctets",&ng_parse_uint32_type	},	\ 	  { "recvRunts",&ng_parse_uint32_type	},	\ 	  { "recvInvalid",&ng_parse_uint32_type	},	\ 	  { "recvWrongTunnel",&ng_parse_uint32_type	},	\ 	  { "recvUnknownSID",&ng_parse_uint32_type	},	\ 	  { "recvBadAcks",&ng_parse_uint32_type	},	\ 	  { "recvOutOfOrder",&ng_parse_uint32_type	},	\ 	  { "recvDuplicates",&ng_parse_uint32_type	},	\ 	  { "recvDataDrops",&ng_parse_uint32_type	},	\ 	  { "recvZLBs",&ng_parse_uint32_type	},	\ 	  { "memoryFailures",&ng_parse_uint32_type	},	\ 	  { NULL }						\ }
end_define

begin_comment
comment|/* Session statistics struct. */
end_comment

begin_struct
struct|struct
name|ng_l2tp_session_stats
block|{
name|u_int64_t
name|xmitPackets
decl_stmt|;
comment|/* number of packets xmit */
name|u_int64_t
name|xmitOctets
decl_stmt|;
comment|/* number of octets xmit */
name|u_int64_t
name|recvPackets
decl_stmt|;
comment|/* number of packets received */
name|u_int64_t
name|recvOctets
decl_stmt|;
comment|/* number of octets received */
block|}
struct|;
end_struct

begin_comment
comment|/* Keep this in sync with the above structure definition. */
end_comment

begin_define
define|#
directive|define
name|NG_L2TP_SESSION_STATS_TYPE_INFO
value|{			\ 	  { "xmitPackets",&ng_parse_uint64_type	},	\ 	  { "xmitOctets",&ng_parse_uint64_type	},	\ 	  { "recvPackets",&ng_parse_uint64_type	},	\ 	  { "recvOctets",&ng_parse_uint64_type	},	\ 	  { NULL }						\ }
end_define

begin_comment
comment|/* Netgraph commands */
end_comment

begin_enum
enum|enum
block|{
name|NGM_L2TP_SET_CONFIG
init|=
literal|1
block|,
comment|/* supply a struct ng_l2tp_config */
name|NGM_L2TP_GET_CONFIG
block|,
comment|/* returns a struct ng_l2tp_config */
name|NGM_L2TP_SET_SESS_CONFIG
block|,
comment|/* supply struct ng_l2tp_sess_config */
name|NGM_L2TP_GET_SESS_CONFIG
block|,
comment|/* supply a session id (u_int16_t) */
name|NGM_L2TP_GET_STATS
block|,
comment|/* returns struct ng_l2tp_stats */
name|NGM_L2TP_CLR_STATS
block|,
comment|/* clears stats */
name|NGM_L2TP_GETCLR_STATS
block|,
comment|/* returns& clears stats */
name|NGM_L2TP_GET_SESSION_STATS
block|,
comment|/* returns session stats */
name|NGM_L2TP_CLR_SESSION_STATS
block|,
comment|/* clears session stats */
name|NGM_L2TP_GETCLR_SESSION_STATS
block|,
comment|/* returns& clears session stats */
name|NGM_L2TP_ACK_FAILURE
block|,
comment|/* sent *from* node after ack timeout */
name|NGM_L2TP_SET_SEQ
comment|/* supply a struct ng_l2tp_seq_config */
block|}
enum|;
end_enum

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NETGRAPH_NG_L2TP_H_ */
end_comment

end_unit

