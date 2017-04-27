begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ng_hci_var.h  */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2001 Maksim Yevmenkin<m_evmenkin@yahoo.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Id: ng_hci_var.h,v 1.3 2003/04/26 22:35:21 max Exp $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETGRAPH_HCI_VAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETGRAPH_HCI_VAR_H_
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
name|M_NETGRAPH_HCI
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
name|M_NETGRAPH_HCI
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
name|NG_HCI_ALERT
value|if (unit->debug>= NG_HCI_ALERT_LEVEL) printf
end_define

begin_define
define|#
directive|define
name|NG_HCI_ERR
value|if (unit->debug>= NG_HCI_ERR_LEVEL)   printf
end_define

begin_define
define|#
directive|define
name|NG_HCI_WARN
value|if (unit->debug>= NG_HCI_WARN_LEVEL)  printf
end_define

begin_define
define|#
directive|define
name|NG_HCI_INFO
value|if (unit->debug>= NG_HCI_INFO_LEVEL)  printf
end_define

begin_comment
comment|/* Wrapper around m_pullup */
end_comment

begin_define
define|#
directive|define
name|NG_HCI_M_PULLUP
parameter_list|(
name|m
parameter_list|,
name|s
parameter_list|)
define|\
value|do { 						\ 		if ((m)->m_len< (s)) 			\ 			(m) = m_pullup((m), (s)); 	\ 		if ((m) == NULL) 			\ 			NG_HCI_ALERT("%s: %s - m_pullup(%zd) failed\n", \ 				__func__, NG_NODE_NAME(unit->node), (s)); \ 	} while (0)
end_define

begin_comment
comment|/*  * Unit hardware buffer descriptor   */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ng_hci_unit_buff
block|{
name|u_int8_t
name|cmd_free
decl_stmt|;
comment|/* space available (cmds) */
name|u_int8_t
name|sco_size
decl_stmt|;
comment|/* max. size of one packet */
name|u_int16_t
name|sco_pkts
decl_stmt|;
comment|/* size of buffer (packets) */
name|u_int16_t
name|sco_free
decl_stmt|;
comment|/* space available (packets)*/
name|u_int16_t
name|acl_size
decl_stmt|;
comment|/* max. size of one packet */
name|u_int16_t
name|acl_pkts
decl_stmt|;
comment|/* size of buffer (packets) */
name|u_int16_t
name|acl_free
decl_stmt|;
comment|/* space available (packets)*/
block|}
name|ng_hci_unit_buff_t
typedef|;
end_typedef

begin_comment
comment|/*   * These macro's must be used everywhere in the code. So if extra locking   * is required later, it can be added without much troubles.  */
end_comment

begin_define
define|#
directive|define
name|NG_HCI_BUFF_CMD_SET
parameter_list|(
name|b
parameter_list|,
name|v
parameter_list|)
value|(b).cmd_free = (v)
end_define

begin_define
define|#
directive|define
name|NG_HCI_BUFF_CMD_GET
parameter_list|(
name|b
parameter_list|,
name|v
parameter_list|)
value|(v) = (b).cmd_free
end_define

begin_define
define|#
directive|define
name|NG_HCI_BUFF_CMD_USE
parameter_list|(
name|b
parameter_list|,
name|v
parameter_list|)
value|(b).cmd_free -= (v)
end_define

begin_define
define|#
directive|define
name|NG_HCI_BUFF_ACL_USE
parameter_list|(
name|b
parameter_list|,
name|v
parameter_list|)
value|(b).acl_free -= (v)
end_define

begin_define
define|#
directive|define
name|NG_HCI_BUFF_ACL_FREE
parameter_list|(
name|b
parameter_list|,
name|v
parameter_list|)
define|\
value|do { 						\ 		(b).acl_free += (v);			\ 		if ((b).acl_free> (b).acl_pkts) 	\ 			(b).acl_free = (b).acl_pkts; 	\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|NG_HCI_BUFF_ACL_AVAIL
parameter_list|(
name|b
parameter_list|,
name|v
parameter_list|)
value|(v) = (b).acl_free
end_define

begin_define
define|#
directive|define
name|NG_HCI_BUFF_ACL_TOTAL
parameter_list|(
name|b
parameter_list|,
name|v
parameter_list|)
value|(v) = (b).acl_pkts
end_define

begin_define
define|#
directive|define
name|NG_HCI_BUFF_ACL_SIZE
parameter_list|(
name|b
parameter_list|,
name|v
parameter_list|)
value|(v) = (b).acl_size
end_define

begin_define
define|#
directive|define
name|NG_HCI_BUFF_ACL_SET
parameter_list|(
name|b
parameter_list|,
name|n
parameter_list|,
name|s
parameter_list|,
name|f
parameter_list|)
define|\
value|do { 						\ 		(b).acl_free = (f); 			\ 		(b).acl_size = (s); 			\ 		(b).acl_pkts = (n); 			\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|NG_HCI_BUFF_SCO_USE
parameter_list|(
name|b
parameter_list|,
name|v
parameter_list|)
value|(b).sco_free -= (v)
end_define

begin_define
define|#
directive|define
name|NG_HCI_BUFF_SCO_FREE
parameter_list|(
name|b
parameter_list|,
name|v
parameter_list|)
define|\
value|do { 						\ 		(b).sco_free += (v); 			\ 		if ((b).sco_free> (b).sco_pkts) 	\ 			(b).sco_free = (b).sco_pkts; 	\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|NG_HCI_BUFF_SCO_AVAIL
parameter_list|(
name|b
parameter_list|,
name|v
parameter_list|)
value|(v) = (b).sco_free
end_define

begin_define
define|#
directive|define
name|NG_HCI_BUFF_SCO_TOTAL
parameter_list|(
name|b
parameter_list|,
name|v
parameter_list|)
value|(v) = (b).sco_pkts
end_define

begin_define
define|#
directive|define
name|NG_HCI_BUFF_SCO_SIZE
parameter_list|(
name|b
parameter_list|,
name|v
parameter_list|)
value|(v) = (b).sco_size
end_define

begin_define
define|#
directive|define
name|NG_HCI_BUFF_SCO_SET
parameter_list|(
name|b
parameter_list|,
name|n
parameter_list|,
name|s
parameter_list|,
name|f
parameter_list|)
define|\
value|do { 						\ 		(b).sco_free = (f); 			\ 		(b).sco_size = (s); 			\ 		(b).sco_pkts = (n); 			\ 	} while (0)
end_define

begin_comment
comment|/*   * Unit (Node private)  */
end_comment

begin_struct_decl
struct_decl|struct
name|ng_hci_unit_con
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ng_hci_neighbor
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
struct|struct
name|ng_hci_unit
block|{
name|node_p
name|node
decl_stmt|;
comment|/* node ptr */
name|ng_hci_node_debug_ep
name|debug
decl_stmt|;
comment|/* debug level */
name|ng_hci_node_state_ep
name|state
decl_stmt|;
comment|/* unit state */
name|bdaddr_t
name|bdaddr
decl_stmt|;
comment|/* unit address */
name|u_int8_t
name|features
index|[
name|NG_HCI_FEATURES_SIZE
index|]
decl_stmt|;
comment|/* LMP features */
name|ng_hci_node_link_policy_mask_ep
name|link_policy_mask
decl_stmt|;
comment|/* link policy mask */
name|ng_hci_node_packet_mask_ep
name|packet_mask
decl_stmt|;
comment|/* packet mask */
name|ng_hci_node_role_switch_ep
name|role_switch
decl_stmt|;
comment|/* role switch */
name|ng_hci_node_stat_ep
name|stat
decl_stmt|;
comment|/* statistic */
define|#
directive|define
name|NG_HCI_STAT_CMD_SENT
parameter_list|(
name|s
parameter_list|)
value|(s).cmd_sent ++
define|#
directive|define
name|NG_HCI_STAT_EVNT_RECV
parameter_list|(
name|s
parameter_list|)
value|(s).evnt_recv ++
define|#
directive|define
name|NG_HCI_STAT_ACL_SENT
parameter_list|(
name|s
parameter_list|,
name|n
parameter_list|)
value|(s).acl_sent += (n)
define|#
directive|define
name|NG_HCI_STAT_ACL_RECV
parameter_list|(
name|s
parameter_list|)
value|(s).acl_recv ++
define|#
directive|define
name|NG_HCI_STAT_SCO_SENT
parameter_list|(
name|s
parameter_list|,
name|n
parameter_list|)
value|(s).sco_sent += (n)
define|#
directive|define
name|NG_HCI_STAT_SCO_RECV
parameter_list|(
name|s
parameter_list|)
value|(s).sco_recv ++
define|#
directive|define
name|NG_HCI_STAT_BYTES_SENT
parameter_list|(
name|s
parameter_list|,
name|b
parameter_list|)
value|(s).bytes_sent += (b)
define|#
directive|define
name|NG_HCI_STAT_BYTES_RECV
parameter_list|(
name|s
parameter_list|,
name|b
parameter_list|)
value|(s).bytes_recv += (b)
define|#
directive|define
name|NG_HCI_STAT_RESET
parameter_list|(
name|s
parameter_list|)
value|bzero(&(s), sizeof((s)))
name|ng_hci_unit_buff_t
name|buffer
decl_stmt|;
comment|/* buffer info */
name|struct
name|callout
name|cmd_timo
decl_stmt|;
comment|/* command timeout */
name|ng_bt_mbufq_t
name|cmdq
decl_stmt|;
comment|/* command queue */
define|#
directive|define
name|NG_HCI_CMD_QUEUE_LEN
value|12
comment|/* max. size of cmd q */
name|hook_p
name|drv
decl_stmt|;
comment|/* driver hook */
name|hook_p
name|acl
decl_stmt|;
comment|/* upstream hook */
name|hook_p
name|sco
decl_stmt|;
comment|/* upstream hook */
name|hook_p
name|raw
decl_stmt|;
comment|/* upstream hook */
name|LIST_HEAD
argument_list|(
argument_list|,
argument|ng_hci_unit_con
argument_list|)
name|con_list
expr_stmt|;
comment|/* connections */
name|LIST_HEAD
argument_list|(
argument_list|,
argument|ng_hci_neighbor
argument_list|)
name|neighbors
expr_stmt|;
comment|/* unit neighbors */
block|}
name|ng_hci_unit_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ng_hci_unit_t
modifier|*
name|ng_hci_unit_p
typedef|;
end_typedef

begin_comment
comment|/*   * Unit connection descriptor  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ng_hci_unit_con
block|{
name|ng_hci_unit_p
name|unit
decl_stmt|;
comment|/* pointer back */
name|u_int16_t
name|state
decl_stmt|;
comment|/* con. state */
name|u_int16_t
name|flags
decl_stmt|;
comment|/* con. flags */
define|#
directive|define
name|NG_HCI_CON_TIMEOUT_PENDING
value|(1<< 0)
define|#
directive|define
name|NG_HCI_CON_NOTIFY_ACL
value|(1<< 1)
define|#
directive|define
name|NG_HCI_CON_NOTIFY_SCO
value|(1<< 2)
name|bdaddr_t
name|bdaddr
decl_stmt|;
comment|/* remote address */
name|u_int16_t
name|con_handle
decl_stmt|;
comment|/* con. handle */
name|u_int8_t
name|link_type
decl_stmt|;
comment|/* ACL or SCO */
name|u_int8_t
name|encryption_mode
decl_stmt|;
comment|/* none, p2p, ... */
name|u_int8_t
name|mode
decl_stmt|;
comment|/* ACTIVE, HOLD ... */
name|u_int8_t
name|role
decl_stmt|;
comment|/* MASTER/SLAVE */
name|struct
name|callout
name|con_timo
decl_stmt|;
comment|/* con. timeout */
name|int
name|pending
decl_stmt|;
comment|/* # of data pkts */
name|ng_bt_itemq_t
name|conq
decl_stmt|;
comment|/* con. queue */
name|LIST_ENTRY
argument_list|(
argument|ng_hci_unit_con
argument_list|)
name|next
expr_stmt|;
comment|/* next */
block|}
name|ng_hci_unit_con_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ng_hci_unit_con_t
modifier|*
name|ng_hci_unit_con_p
typedef|;
end_typedef

begin_comment
comment|/*  * Unit's neighbor descriptor.   * Neighbor is a remote unit that responded to our inquiry.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ng_hci_neighbor
block|{
name|struct
name|timeval
name|updated
decl_stmt|;
comment|/* entry was updated */
name|bdaddr_t
name|bdaddr
decl_stmt|;
comment|/* address */
name|u_int8_t
name|features
index|[
name|NG_HCI_FEATURES_SIZE
index|]
decl_stmt|;
comment|/* LMP features */
name|u_int8_t
name|addrtype
decl_stmt|;
comment|/*Address Type*/
name|u_int8_t
name|page_scan_rep_mode
decl_stmt|;
comment|/* PS rep. mode */
name|u_int8_t
name|page_scan_mode
decl_stmt|;
comment|/* page scan mode */
name|u_int16_t
name|clock_offset
decl_stmt|;
comment|/* clock offset */
name|uint8_t
name|extinq_size
decl_stmt|;
name|uint8_t
name|extinq_data
index|[
name|NG_HCI_EXTINQ_MAX
index|]
decl_stmt|;
name|LIST_ENTRY
argument_list|(
argument|ng_hci_neighbor
argument_list|)
name|next
expr_stmt|;
block|}
name|ng_hci_neighbor_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ng_hci_neighbor_t
modifier|*
name|ng_hci_neighbor_p
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ndef _NETGRAPH_HCI_VAR_H_ */
end_comment

end_unit

