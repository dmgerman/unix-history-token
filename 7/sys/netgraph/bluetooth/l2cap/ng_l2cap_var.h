begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ng_l2cap_var.h  */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2001 Maksim Yevmenkin<m_evmenkin@yahoo.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Id: ng_l2cap_var.h,v 1.2 2003/04/28 21:44:59 max Exp $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETGRAPH_L2CAP_VAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETGRAPH_L2CAP_VAR_H_
end_define

begin_comment
comment|/* MALLOC decalation */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NG_SEPARATE_MALLOC
end_ifdef

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_NETGRAPH_L2CAP
argument_list|)
expr_stmt|;
end_expr_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|M_NETGRAPH_L2CAP
value|M_NETGRAPH
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NG_SEPARATE_MALLOC */
end_comment

begin_comment
comment|/* Debug */
end_comment

begin_define
define|#
directive|define
name|NG_L2CAP_ALERT
value|if (l2cap->debug>= NG_L2CAP_ALERT_LEVEL) printf
end_define

begin_define
define|#
directive|define
name|NG_L2CAP_ERR
value|if (l2cap->debug>= NG_L2CAP_ERR_LEVEL)   printf
end_define

begin_define
define|#
directive|define
name|NG_L2CAP_WARN
value|if (l2cap->debug>= NG_L2CAP_WARN_LEVEL)  printf
end_define

begin_define
define|#
directive|define
name|NG_L2CAP_INFO
value|if (l2cap->debug>= NG_L2CAP_INFO_LEVEL)  printf
end_define

begin_comment
comment|/* Wrapper around m_pullup */
end_comment

begin_define
define|#
directive|define
name|NG_L2CAP_M_PULLUP
parameter_list|(
name|m
parameter_list|,
name|s
parameter_list|)
define|\
value|do { \ 		if ((m)->m_len< (s)) \ 			(m) = m_pullup((m), (s)); \ 		if ((m) == NULL) \ 			NG_L2CAP_ALERT("%s: %s - m_pullup(%zd) failed\n", \ 				__func__, NG_NODE_NAME(l2cap->node), (s)); \ 	} while (0)
end_define

begin_comment
comment|/*  * L2CAP signaling command ident's are assigned relative to the connection,  * because there is only one signaling channel (cid == 0x01) for every   * connection. So up to 254 (0xff - 0x01) L2CAP commands can be pending at the   * same time for the same connection.  */
end_comment

begin_define
define|#
directive|define
name|NG_L2CAP_NULL_IDENT
value|0x00
end_define

begin_comment
comment|/* DO NOT USE THIS IDENT */
end_comment

begin_define
define|#
directive|define
name|NG_L2CAP_FIRST_IDENT
value|0x01
end_define

begin_comment
comment|/* dynamically alloc. (start) */
end_comment

begin_define
define|#
directive|define
name|NG_L2CAP_LAST_IDENT
value|0xff
end_define

begin_comment
comment|/* dynamically alloc. (end) */
end_comment

begin_comment
comment|/*   * L2CAP (Node private)  */
end_comment

begin_struct_decl
struct_decl|struct
name|ng_l2cap_con
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ng_l2cap_chan
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
struct|struct
name|ng_l2cap
block|{
name|node_p
name|node
decl_stmt|;
comment|/* node ptr */
name|ng_l2cap_node_debug_ep
name|debug
decl_stmt|;
comment|/* debug level */
name|ng_l2cap_node_flags_ep
name|flags
decl_stmt|;
comment|/* L2CAP node flags */
name|ng_l2cap_node_auto_discon_ep
name|discon_timo
decl_stmt|;
comment|/* auto discon. timeout */
name|u_int16_t
name|pkt_size
decl_stmt|;
comment|/* max. ACL packet size */
name|u_int16_t
name|num_pkts
decl_stmt|;
comment|/* out queue size */
name|bdaddr_t
name|bdaddr
decl_stmt|;
comment|/* unit BDADDR */
name|hook_p
name|hci
decl_stmt|;
comment|/* HCI downstream hook */
name|hook_p
name|l2c
decl_stmt|;
comment|/* L2CAP upstream hook */
name|hook_p
name|ctl
decl_stmt|;
comment|/* control hook */
name|LIST_HEAD
argument_list|(
argument_list|,
argument|ng_l2cap_con
argument_list|)
name|con_list
expr_stmt|;
comment|/* ACL connections */
name|u_int16_t
name|cid
decl_stmt|;
comment|/* last allocated CID */
name|LIST_HEAD
argument_list|(
argument_list|,
argument|ng_l2cap_chan
argument_list|)
name|chan_list
expr_stmt|;
comment|/* L2CAP channels */
block|}
name|ng_l2cap_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ng_l2cap_t
modifier|*
name|ng_l2cap_p
typedef|;
end_typedef

begin_comment
comment|/*   * L2CAP connection descriptor  */
end_comment

begin_struct_decl
struct_decl|struct
name|ng_l2cap_cmd
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
struct|struct
name|ng_l2cap_con
block|{
name|ng_l2cap_p
name|l2cap
decl_stmt|;
comment|/* pointer to L2CAP */
name|u_int16_t
name|state
decl_stmt|;
comment|/* ACL connection state */
name|u_int16_t
name|flags
decl_stmt|;
comment|/* ACL connection flags */
name|int32_t
name|refcnt
decl_stmt|;
comment|/* reference count */
name|bdaddr_t
name|remote
decl_stmt|;
comment|/* remote unit address */
name|u_int16_t
name|con_handle
decl_stmt|;
comment|/* ACL connection handle */
name|struct
name|callout
name|con_timo
decl_stmt|;
comment|/* connection timeout */
name|u_int8_t
name|ident
decl_stmt|;
comment|/* last allocated ident */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|ng_l2cap_cmd
argument_list|)
name|cmd_list
expr_stmt|;
comment|/* pending L2CAP cmds */
name|struct
name|mbuf
modifier|*
name|tx_pkt
decl_stmt|;
comment|/* xmitted L2CAP packet */
name|int
name|pending
decl_stmt|;
comment|/* num. of pending pkts */
name|struct
name|mbuf
modifier|*
name|rx_pkt
decl_stmt|;
comment|/* received L2CAP packet */
name|int
name|rx_pkt_len
decl_stmt|;
comment|/* packet len. so far */
name|LIST_ENTRY
argument_list|(
argument|ng_l2cap_con
argument_list|)
name|next
expr_stmt|;
comment|/* link */
block|}
name|ng_l2cap_con_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ng_l2cap_con_t
modifier|*
name|ng_l2cap_con_p
typedef|;
end_typedef

begin_comment
comment|/*  * L2CAP channel descriptor  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ng_l2cap_chan
block|{
name|ng_l2cap_con_p
name|con
decl_stmt|;
comment|/* pointer to connection */
name|u_int16_t
name|state
decl_stmt|;
comment|/* channel state */
name|u_int8_t
name|cfg_state
decl_stmt|;
comment|/* configuration state */
define|#
directive|define
name|NG_L2CAP_CFG_IN
value|(1<< 0)
comment|/* incoming cfg path done */
define|#
directive|define
name|NG_L2CAP_CFG_OUT
value|(1<< 1)
comment|/* outgoing cfg path done */
define|#
directive|define
name|NG_L2CAP_CFG_BOTH
value|(NG_L2CAP_CFG_IN|NG_L2CAP_CFG_OUT)
name|u_int8_t
name|ident
decl_stmt|;
comment|/* last L2CAP req. ident */
name|u_int16_t
name|psm
decl_stmt|;
comment|/* channel PSM */
name|u_int16_t
name|scid
decl_stmt|;
comment|/* source channel ID */
name|u_int16_t
name|dcid
decl_stmt|;
comment|/* destination channel ID */
name|u_int16_t
name|imtu
decl_stmt|;
comment|/* incoming channel MTU */
name|ng_l2cap_flow_t
name|iflow
decl_stmt|;
comment|/* incoming flow control */
name|u_int16_t
name|omtu
decl_stmt|;
comment|/* outgoing channel MTU */
name|ng_l2cap_flow_t
name|oflow
decl_stmt|;
comment|/* outgoing flow control */
name|u_int16_t
name|flush_timo
decl_stmt|;
comment|/* flush timeout */
name|u_int16_t
name|link_timo
decl_stmt|;
comment|/* link timeout */
name|LIST_ENTRY
argument_list|(
argument|ng_l2cap_chan
argument_list|)
name|next
expr_stmt|;
comment|/* link */
block|}
name|ng_l2cap_chan_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ng_l2cap_chan_t
modifier|*
name|ng_l2cap_chan_p
typedef|;
end_typedef

begin_comment
comment|/*  * L2CAP command descriptor  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ng_l2cap_cmd
block|{
name|ng_l2cap_con_p
name|con
decl_stmt|;
comment|/* L2CAP connection */
name|ng_l2cap_chan_p
name|ch
decl_stmt|;
comment|/* L2CAP channel */
name|u_int16_t
name|flags
decl_stmt|;
comment|/* command flags */
define|#
directive|define
name|NG_L2CAP_CMD_PENDING
value|(1<< 0)
comment|/* command is pending */
name|u_int8_t
name|code
decl_stmt|;
comment|/* L2CAP command opcode */
name|u_int8_t
name|ident
decl_stmt|;
comment|/* L2CAP command ident */
name|u_int32_t
name|token
decl_stmt|;
comment|/* L2CA message token */
name|struct
name|callout
name|timo
decl_stmt|;
comment|/* RTX/ERTX timeout */
name|struct
name|mbuf
modifier|*
name|aux
decl_stmt|;
comment|/* optional data */
name|TAILQ_ENTRY
argument_list|(
argument|ng_l2cap_cmd
argument_list|)
name|next
expr_stmt|;
comment|/* link */
block|}
name|ng_l2cap_cmd_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ng_l2cap_cmd_t
modifier|*
name|ng_l2cap_cmd_p
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ndef _NETGRAPH_L2CAP_VAR_H_ */
end_comment

end_unit

