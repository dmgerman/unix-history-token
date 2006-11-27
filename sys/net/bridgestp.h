begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: if_bridgevar.h,v 1.4 2003/07/08 07:13:50 itojun Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright 2001 Wasabi Systems, Inc.  * All rights reserved.  *  * Written by Jason R. Thorpe for Wasabi Systems, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed for the NetBSD Project by  *	Wasabi Systems, Inc.  * 4. The name of Wasabi Systems, Inc. may not be used to endorse  *    or promote products derived from this software without specific prior  *    written permission.  *  * THIS SOFTWARE IS PROVIDED BY WASABI SYSTEMS, INC. ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL WASABI SYSTEMS, INC  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1999, 2000 Jason L. Wright (jason@thought.net)  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Jason L. Wright  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN  * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  * OpenBSD: if_bridge.h,v 1.14 2001/03/22 03:48:29 jason Exp  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Data structure and control definitions for STP interfaces.  */
end_comment

begin_include
include|#
directive|include
file|<sys/callout.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_comment
comment|/* STP port states */
end_comment

begin_define
define|#
directive|define
name|BSTP_IFSTATE_DISABLED
value|0
end_define

begin_define
define|#
directive|define
name|BSTP_IFSTATE_LISTENING
value|1
end_define

begin_define
define|#
directive|define
name|BSTP_IFSTATE_LEARNING
value|2
end_define

begin_define
define|#
directive|define
name|BSTP_IFSTATE_FORWARDING
value|3
end_define

begin_define
define|#
directive|define
name|BSTP_IFSTATE_BLOCKING
value|4
end_define

begin_define
define|#
directive|define
name|BSTP_IFSTATE_DISCARDING
value|5
end_define

begin_define
define|#
directive|define
name|BSTP_TCSTATE_ACTIVE
value|1
end_define

begin_define
define|#
directive|define
name|BSTP_TCSTATE_DETECTED
value|2
end_define

begin_define
define|#
directive|define
name|BSTP_TCSTATE_INACTIVE
value|3
end_define

begin_define
define|#
directive|define
name|BSTP_TCSTATE_LEARNING
value|4
end_define

begin_define
define|#
directive|define
name|BSTP_TCSTATE_PROPAG
value|5
end_define

begin_define
define|#
directive|define
name|BSTP_TCSTATE_ACK
value|6
end_define

begin_define
define|#
directive|define
name|BSTP_TCSTATE_TC
value|7
end_define

begin_define
define|#
directive|define
name|BSTP_TCSTATE_TCN
value|8
end_define

begin_define
define|#
directive|define
name|BSTP_ROLE_DISABLED
value|0
end_define

begin_define
define|#
directive|define
name|BSTP_ROLE_ROOT
value|1
end_define

begin_define
define|#
directive|define
name|BSTP_ROLE_DESIGNATED
value|2
end_define

begin_define
define|#
directive|define
name|BSTP_ROLE_ALTERNATE
value|3
end_define

begin_define
define|#
directive|define
name|BSTP_ROLE_BACKUP
value|4
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/* STP port flags */
end_comment

begin_define
define|#
directive|define
name|BSTP_PORT_CANMIGRATE
value|0x0001
end_define

begin_define
define|#
directive|define
name|BSTP_PORT_NEWINFO
value|0x0002
end_define

begin_define
define|#
directive|define
name|BSTP_PORT_DISPUTED
value|0x0004
end_define

begin_define
define|#
directive|define
name|BSTP_PORT_ADMCOST
value|0x0008
end_define

begin_define
define|#
directive|define
name|BSTP_PORT_AUTOEDGE
value|0x0010
end_define

begin_define
define|#
directive|define
name|BSTP_PORT_AUTOP2P
value|0x0020
end_define

begin_comment
comment|/* BPDU priority */
end_comment

begin_define
define|#
directive|define
name|BSTP_PDU_SUPERIOR
value|1
end_define

begin_define
define|#
directive|define
name|BSTP_PDU_REPEATED
value|2
end_define

begin_define
define|#
directive|define
name|BSTP_PDU_INFERIOR
value|3
end_define

begin_define
define|#
directive|define
name|BSTP_PDU_INFERIORALT
value|4
end_define

begin_define
define|#
directive|define
name|BSTP_PDU_OTHER
value|5
end_define

begin_comment
comment|/* BPDU flags */
end_comment

begin_define
define|#
directive|define
name|BSTP_PDU_PRMASK
value|0x0c
end_define

begin_comment
comment|/* Port Role */
end_comment

begin_define
define|#
directive|define
name|BSTP_PDU_PRSHIFT
value|2
end_define

begin_comment
comment|/* Port Role offset */
end_comment

begin_define
define|#
directive|define
name|BSTP_PDU_F_UNKN
value|0x00
end_define

begin_comment
comment|/* Unknown port    (00) */
end_comment

begin_define
define|#
directive|define
name|BSTP_PDU_F_ALT
value|0x01
end_define

begin_comment
comment|/* Alt/Backup port (01) */
end_comment

begin_define
define|#
directive|define
name|BSTP_PDU_F_ROOT
value|0x02
end_define

begin_comment
comment|/* Root port       (10) */
end_comment

begin_define
define|#
directive|define
name|BSTP_PDU_F_DESG
value|0x03
end_define

begin_comment
comment|/* Designated port (11) */
end_comment

begin_define
define|#
directive|define
name|BSTP_PDU_STPMASK
value|0x81
end_define

begin_comment
comment|/* strip unused STP flags */
end_comment

begin_define
define|#
directive|define
name|BSTP_PDU_RSTPMASK
value|0x7f
end_define

begin_comment
comment|/* strip unused RSTP flags */
end_comment

begin_define
define|#
directive|define
name|BSTP_PDU_F_TC
value|0x01
end_define

begin_comment
comment|/* Topology change */
end_comment

begin_define
define|#
directive|define
name|BSTP_PDU_F_P
value|0x02
end_define

begin_comment
comment|/* Proposal flag */
end_comment

begin_define
define|#
directive|define
name|BSTP_PDU_F_L
value|0x10
end_define

begin_comment
comment|/* Learning flag */
end_comment

begin_define
define|#
directive|define
name|BSTP_PDU_F_F
value|0x20
end_define

begin_comment
comment|/* Forwarding flag */
end_comment

begin_define
define|#
directive|define
name|BSTP_PDU_F_A
value|0x40
end_define

begin_comment
comment|/* Agreement flag */
end_comment

begin_define
define|#
directive|define
name|BSTP_PDU_F_TCA
value|0x80
end_define

begin_comment
comment|/* Topology change ack */
end_comment

begin_comment
comment|/*  * Spanning tree defaults.  */
end_comment

begin_define
define|#
directive|define
name|BSTP_DEFAULT_MAX_AGE
value|(20 * 256)
end_define

begin_define
define|#
directive|define
name|BSTP_DEFAULT_HELLO_TIME
value|(2 * 256)
end_define

begin_define
define|#
directive|define
name|BSTP_DEFAULT_FORWARD_DELAY
value|(15 * 256)
end_define

begin_define
define|#
directive|define
name|BSTP_DEFAULT_HOLD_TIME
value|(1 * 256)
end_define

begin_define
define|#
directive|define
name|BSTP_DEFAULT_MIGRATE_DELAY
value|(3 * 256)
end_define

begin_define
define|#
directive|define
name|BSTP_DEFAULT_HOLD_COUNT
value|6
end_define

begin_define
define|#
directive|define
name|BSTP_DEFAULT_BRIDGE_PRIORITY
value|0x8000
end_define

begin_define
define|#
directive|define
name|BSTP_DEFAULT_PORT_PRIORITY
value|0x80
end_define

begin_define
define|#
directive|define
name|BSTP_DEFAULT_PATH_COST
value|55
end_define

begin_define
define|#
directive|define
name|BSTP_MIN_HELLO_TIME
value|(1 * 256)
end_define

begin_define
define|#
directive|define
name|BSTP_MIN_MAX_AGE
value|(6 * 256)
end_define

begin_define
define|#
directive|define
name|BSTP_MIN_FORWARD_DELAY
value|(4 * 256)
end_define

begin_define
define|#
directive|define
name|BSTP_MIN_HOLD_COUNT
value|1
end_define

begin_define
define|#
directive|define
name|BSTP_MAX_HELLO_TIME
value|(2 * 256)
end_define

begin_define
define|#
directive|define
name|BSTP_MAX_MAX_AGE
value|(40 * 256)
end_define

begin_define
define|#
directive|define
name|BSTP_MAX_FORWARD_DELAY
value|(30 * 256)
end_define

begin_define
define|#
directive|define
name|BSTP_MAX_HOLD_COUNT
value|10
end_define

begin_define
define|#
directive|define
name|BSTP_MAX_PRIORITY
value|61440
end_define

begin_define
define|#
directive|define
name|BSTP_MAX_PORT_PRIORITY
value|240
end_define

begin_define
define|#
directive|define
name|BSTP_MAX_PATH_COST
value|200000000
end_define

begin_comment
comment|/* BPDU message types */
end_comment

begin_define
define|#
directive|define
name|BSTP_MSGTYPE_CFG
value|0x00
end_define

begin_comment
comment|/* Configuration */
end_comment

begin_define
define|#
directive|define
name|BSTP_MSGTYPE_RSTP
value|0x02
end_define

begin_comment
comment|/* Rapid STP */
end_comment

begin_define
define|#
directive|define
name|BSTP_MSGTYPE_TCN
value|0x80
end_define

begin_comment
comment|/* Topology chg notification */
end_comment

begin_comment
comment|/* Protocol versions */
end_comment

begin_define
define|#
directive|define
name|BSTP_PROTO_ID
value|0x00
end_define

begin_define
define|#
directive|define
name|BSTP_PROTO_STP
value|0x00
end_define

begin_define
define|#
directive|define
name|BSTP_PROTO_RSTP
value|0x02
end_define

begin_define
define|#
directive|define
name|BSTP_PROTO_MAX
value|BSTP_PROTO_RSTP
end_define

begin_define
define|#
directive|define
name|BSTP_INFO_RECIEVED
value|1
end_define

begin_define
define|#
directive|define
name|BSTP_INFO_MINE
value|2
end_define

begin_define
define|#
directive|define
name|BSTP_INFO_AGED
value|3
end_define

begin_define
define|#
directive|define
name|BSTP_INFO_DISABLED
value|4
end_define

begin_define
define|#
directive|define
name|BSTP_MESSAGE_AGE_INCR
value|(1 * 256)
end_define

begin_comment
comment|/* in 256ths of a second */
end_comment

begin_define
define|#
directive|define
name|BSTP_TICK_VAL
value|(1 * 256)
end_define

begin_comment
comment|/* in 256ths of a second */
end_comment

begin_define
define|#
directive|define
name|BSTP_LINK_TIMER
value|(BSTP_TICK_VAL * 15)
end_define

begin_comment
comment|/*  * Driver callbacks for STP state changes  */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|bstp_state_cb_t
function_decl|)
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|bstp_rtage_cb_t
function_decl|)
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * Because BPDU's do not make nicely aligned structures, two different  * declarations are used: bstp_?bpdu (wire representation, packed) and  * bstp_*_unit (internal, nicely aligned version).  */
end_comment

begin_comment
comment|/* configuration bridge protocol data unit */
end_comment

begin_struct
struct|struct
name|bstp_cbpdu
block|{
name|uint8_t
name|cbu_dsap
decl_stmt|;
comment|/* LLC: destination sap */
name|uint8_t
name|cbu_ssap
decl_stmt|;
comment|/* LLC: source sap */
name|uint8_t
name|cbu_ctl
decl_stmt|;
comment|/* LLC: control */
name|uint16_t
name|cbu_protoid
decl_stmt|;
comment|/* protocol id */
name|uint8_t
name|cbu_protover
decl_stmt|;
comment|/* protocol version */
name|uint8_t
name|cbu_bpdutype
decl_stmt|;
comment|/* message type */
name|uint8_t
name|cbu_flags
decl_stmt|;
comment|/* flags (below) */
comment|/* root id */
name|uint16_t
name|cbu_rootpri
decl_stmt|;
comment|/* root priority */
name|uint8_t
name|cbu_rootaddr
index|[
literal|6
index|]
decl_stmt|;
comment|/* root address */
name|uint32_t
name|cbu_rootpathcost
decl_stmt|;
comment|/* root path cost */
comment|/* bridge id */
name|uint16_t
name|cbu_bridgepri
decl_stmt|;
comment|/* bridge priority */
name|uint8_t
name|cbu_bridgeaddr
index|[
literal|6
index|]
decl_stmt|;
comment|/* bridge address */
name|uint16_t
name|cbu_portid
decl_stmt|;
comment|/* port id */
name|uint16_t
name|cbu_messageage
decl_stmt|;
comment|/* current message age */
name|uint16_t
name|cbu_maxage
decl_stmt|;
comment|/* maximum age */
name|uint16_t
name|cbu_hellotime
decl_stmt|;
comment|/* hello time */
name|uint16_t
name|cbu_forwarddelay
decl_stmt|;
comment|/* forwarding delay */
name|uint8_t
name|cbu_versionlen
decl_stmt|;
comment|/* version 1 length */
block|}
name|__attribute__
argument_list|(
operator|(
name|__packed__
operator|)
argument_list|)
struct|;
end_struct

begin_define
define|#
directive|define
name|BSTP_BPDU_STP_LEN
value|(3 + 35)
end_define

begin_comment
comment|/* LLC + STP pdu */
end_comment

begin_define
define|#
directive|define
name|BSTP_BPDU_RSTP_LEN
value|(3 + 36)
end_define

begin_comment
comment|/* LLC + RSTP pdu */
end_comment

begin_comment
comment|/* topology change notification bridge protocol data unit */
end_comment

begin_struct
struct|struct
name|bstp_tbpdu
block|{
name|uint8_t
name|tbu_dsap
decl_stmt|;
comment|/* LLC: destination sap */
name|uint8_t
name|tbu_ssap
decl_stmt|;
comment|/* LLC: source sap */
name|uint8_t
name|tbu_ctl
decl_stmt|;
comment|/* LLC: control */
name|uint16_t
name|tbu_protoid
decl_stmt|;
comment|/* protocol id */
name|uint8_t
name|tbu_protover
decl_stmt|;
comment|/* protocol version */
name|uint8_t
name|tbu_bpdutype
decl_stmt|;
comment|/* message type */
block|}
name|__attribute__
argument_list|(
operator|(
name|__packed__
operator|)
argument_list|)
struct|;
end_struct

begin_comment
comment|/*  * Timekeeping structure used in spanning tree code.  */
end_comment

begin_struct
struct|struct
name|bstp_timer
block|{
name|int
name|active
decl_stmt|;
name|int
name|latched
decl_stmt|;
name|int
name|value
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|bstp_pri_vector
block|{
name|uint64_t
name|pv_root_id
decl_stmt|;
name|uint32_t
name|pv_cost
decl_stmt|;
name|uint64_t
name|pv_dbridge_id
decl_stmt|;
name|uint16_t
name|pv_dport_id
decl_stmt|;
name|uint16_t
name|pv_port_id
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|bstp_config_unit
block|{
name|struct
name|bstp_pri_vector
name|cu_pv
decl_stmt|;
name|uint16_t
name|cu_message_age
decl_stmt|;
name|uint16_t
name|cu_max_age
decl_stmt|;
name|uint16_t
name|cu_forward_delay
decl_stmt|;
name|uint16_t
name|cu_hello_time
decl_stmt|;
name|uint8_t
name|cu_message_type
decl_stmt|;
name|uint8_t
name|cu_topology_change_ack
decl_stmt|;
name|uint8_t
name|cu_topology_change
decl_stmt|;
name|uint8_t
name|cu_proposal
decl_stmt|;
name|uint8_t
name|cu_agree
decl_stmt|;
name|uint8_t
name|cu_learning
decl_stmt|;
name|uint8_t
name|cu_forwarding
decl_stmt|;
name|uint8_t
name|cu_role
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|bstp_tcn_unit
block|{
name|uint8_t
name|tu_message_type
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|bstp_port
block|{
name|LIST_ENTRY
argument_list|(
argument|bstp_port
argument_list|)
name|bp_next
expr_stmt|;
name|struct
name|ifnet
modifier|*
name|bp_ifp
decl_stmt|;
comment|/* parent if */
name|struct
name|bstp_state
modifier|*
name|bp_bs
decl_stmt|;
name|uint8_t
name|bp_active
decl_stmt|;
name|uint8_t
name|bp_protover
decl_stmt|;
name|uint32_t
name|bp_flags
decl_stmt|;
name|uint32_t
name|bp_path_cost
decl_stmt|;
name|uint16_t
name|bp_port_msg_age
decl_stmt|;
name|uint16_t
name|bp_port_max_age
decl_stmt|;
name|uint16_t
name|bp_port_fdelay
decl_stmt|;
name|uint16_t
name|bp_port_htime
decl_stmt|;
name|uint16_t
name|bp_desg_msg_age
decl_stmt|;
name|uint16_t
name|bp_desg_max_age
decl_stmt|;
name|uint16_t
name|bp_desg_fdelay
decl_stmt|;
name|uint16_t
name|bp_desg_htime
decl_stmt|;
name|struct
name|bstp_timer
name|bp_edge_delay_timer
decl_stmt|;
name|struct
name|bstp_timer
name|bp_forward_delay_timer
decl_stmt|;
name|struct
name|bstp_timer
name|bp_hello_timer
decl_stmt|;
name|struct
name|bstp_timer
name|bp_message_age_timer
decl_stmt|;
name|struct
name|bstp_timer
name|bp_migrate_delay_timer
decl_stmt|;
name|struct
name|bstp_timer
name|bp_recent_backup_timer
decl_stmt|;
name|struct
name|bstp_timer
name|bp_recent_root_timer
decl_stmt|;
name|struct
name|bstp_timer
name|bp_tc_timer
decl_stmt|;
name|struct
name|bstp_config_unit
name|bp_msg_cu
decl_stmt|;
name|struct
name|bstp_pri_vector
name|bp_desg_pv
decl_stmt|;
name|struct
name|bstp_pri_vector
name|bp_port_pv
decl_stmt|;
name|uint16_t
name|bp_port_id
decl_stmt|;
name|uint8_t
name|bp_state
decl_stmt|;
name|uint8_t
name|bp_tcstate
decl_stmt|;
name|uint8_t
name|bp_role
decl_stmt|;
name|uint8_t
name|bp_infois
decl_stmt|;
name|uint8_t
name|bp_tc_ack
decl_stmt|;
name|uint8_t
name|bp_tc_prop
decl_stmt|;
name|uint8_t
name|bp_fdbflush
decl_stmt|;
name|uint8_t
name|bp_priority
decl_stmt|;
name|uint8_t
name|bp_p2p_link
decl_stmt|;
name|uint8_t
name|bp_agree
decl_stmt|;
name|uint8_t
name|bp_agreed
decl_stmt|;
name|uint8_t
name|bp_sync
decl_stmt|;
name|uint8_t
name|bp_synced
decl_stmt|;
name|uint8_t
name|bp_proposing
decl_stmt|;
name|uint8_t
name|bp_proposed
decl_stmt|;
name|uint8_t
name|bp_operedge
decl_stmt|;
name|uint8_t
name|bp_reroot
decl_stmt|;
name|uint8_t
name|bp_rcvdtc
decl_stmt|;
name|uint8_t
name|bp_rcvdtca
decl_stmt|;
name|uint8_t
name|bp_rcvdtcn
decl_stmt|;
name|uint32_t
name|bp_forward_transitions
decl_stmt|;
name|uint8_t
name|bp_txcount
decl_stmt|;
name|struct
name|task
name|bp_statetask
decl_stmt|;
name|struct
name|task
name|bp_rtagetask
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Software state for each bridge STP.  */
end_comment

begin_struct
struct|struct
name|bstp_state
block|{
name|LIST_ENTRY
argument_list|(
argument|bstp_state
argument_list|)
name|bs_list
expr_stmt|;
name|uint8_t
name|bs_running
decl_stmt|;
name|struct
name|mtx
name|bs_mtx
decl_stmt|;
name|struct
name|bstp_pri_vector
name|bs_bridge_pv
decl_stmt|;
name|struct
name|bstp_pri_vector
name|bs_root_pv
decl_stmt|;
name|struct
name|bstp_port
modifier|*
name|bs_root_port
decl_stmt|;
name|uint8_t
name|bs_protover
decl_stmt|;
name|uint16_t
name|bs_migration_delay
decl_stmt|;
name|uint16_t
name|bs_edge_delay
decl_stmt|;
name|uint16_t
name|bs_bridge_max_age
decl_stmt|;
name|uint16_t
name|bs_bridge_fdelay
decl_stmt|;
name|uint16_t
name|bs_bridge_htime
decl_stmt|;
name|uint16_t
name|bs_root_msg_age
decl_stmt|;
name|uint16_t
name|bs_root_max_age
decl_stmt|;
name|uint16_t
name|bs_root_fdelay
decl_stmt|;
name|uint16_t
name|bs_root_htime
decl_stmt|;
name|uint16_t
name|bs_hold_time
decl_stmt|;
name|uint16_t
name|bs_bridge_priority
decl_stmt|;
name|uint8_t
name|bs_txholdcount
decl_stmt|;
name|uint8_t
name|bs_allsynced
decl_stmt|;
name|struct
name|callout
name|bs_bstpcallout
decl_stmt|;
comment|/* STP callout */
name|struct
name|bstp_timer
name|bs_link_timer
decl_stmt|;
name|struct
name|timeval
name|bs_last_tc_time
decl_stmt|;
name|LIST_HEAD
argument_list|(
argument_list|,
argument|bstp_port
argument_list|)
name|bs_bplist
expr_stmt|;
name|bstp_state_cb_t
name|bs_state_cb
decl_stmt|;
name|bstp_rtage_cb_t
name|bs_rtage_cb
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|BSTP_LOCK_INIT
parameter_list|(
name|_bs
parameter_list|)
value|mtx_init(&(_bs)->bs_mtx, "bstp", NULL, MTX_DEF)
end_define

begin_define
define|#
directive|define
name|BSTP_LOCK_DESTROY
parameter_list|(
name|_bs
parameter_list|)
value|mtx_destroy(&(_bs)->bs_mtx)
end_define

begin_define
define|#
directive|define
name|BSTP_LOCK
parameter_list|(
name|_bs
parameter_list|)
value|mtx_lock(&(_bs)->bs_mtx)
end_define

begin_define
define|#
directive|define
name|BSTP_UNLOCK
parameter_list|(
name|_bs
parameter_list|)
value|mtx_unlock(&(_bs)->bs_mtx)
end_define

begin_define
define|#
directive|define
name|BSTP_LOCK_ASSERT
parameter_list|(
name|_bs
parameter_list|)
value|mtx_assert(&(_bs)->bs_mtx, MA_OWNED)
end_define

begin_decl_stmt
specifier|extern
specifier|const
name|uint8_t
name|bstp_etheraddr
index|[]
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
function_decl|(
modifier|*
name|bstp_linkstate_p
function_decl|)
parameter_list|(
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|,
name|int
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bstp_attach
parameter_list|(
name|struct
name|bstp_state
modifier|*
parameter_list|,
name|bstp_state_cb_t
parameter_list|,
name|bstp_rtage_cb_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bstp_detach
parameter_list|(
name|struct
name|bstp_state
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bstp_init
parameter_list|(
name|struct
name|bstp_state
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bstp_stop
parameter_list|(
name|struct
name|bstp_state
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bstp_create
parameter_list|(
name|struct
name|bstp_state
modifier|*
parameter_list|,
name|struct
name|bstp_port
modifier|*
parameter_list|,
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bstp_enable
parameter_list|(
name|struct
name|bstp_port
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bstp_disable
parameter_list|(
name|struct
name|bstp_port
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bstp_destroy
parameter_list|(
name|struct
name|bstp_port
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bstp_linkstate
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bstp_set_htime
parameter_list|(
name|struct
name|bstp_state
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bstp_set_fdelay
parameter_list|(
name|struct
name|bstp_state
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bstp_set_maxage
parameter_list|(
name|struct
name|bstp_state
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bstp_set_holdcount
parameter_list|(
name|struct
name|bstp_state
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bstp_set_protocol
parameter_list|(
name|struct
name|bstp_state
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bstp_set_priority
parameter_list|(
name|struct
name|bstp_state
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bstp_set_port_priority
parameter_list|(
name|struct
name|bstp_port
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bstp_set_path_cost
parameter_list|(
name|struct
name|bstp_port
modifier|*
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bstp_set_edge
parameter_list|(
name|struct
name|bstp_port
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bstp_set_autoedge
parameter_list|(
name|struct
name|bstp_port
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bstp_set_p2p
parameter_list|(
name|struct
name|bstp_port
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bstp_set_autop2p
parameter_list|(
name|struct
name|bstp_port
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|mbuf
modifier|*
name|bstp_input
parameter_list|(
name|struct
name|bstp_port
modifier|*
parameter_list|,
name|struct
name|ifnet
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

end_unit

