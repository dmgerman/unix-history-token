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

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

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
name|BSTP_MSGTYPE_TCN
value|0x80
end_define

begin_comment
comment|/* Topology chg notification */
end_comment

begin_comment
comment|/* BPDU flags */
end_comment

begin_define
define|#
directive|define
name|BSTP_FLAG_TC
value|0x01
end_define

begin_comment
comment|/* Topology change */
end_comment

begin_define
define|#
directive|define
name|BSTP_FLAG_TCA
value|0x80
end_define

begin_comment
comment|/* Topology change ack */
end_comment

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
value|(BSTP_TICK_VAL * 30)
end_define

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
name|uint16_t
name|active
decl_stmt|;
name|uint16_t
name|value
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|bstp_config_unit
block|{
name|uint64_t
name|cu_rootid
decl_stmt|;
name|uint64_t
name|cu_bridge_id
decl_stmt|;
name|uint32_t
name|cu_root_path_cost
decl_stmt|;
name|uint16_t
name|cu_message_age
decl_stmt|;
name|uint16_t
name|cu_max_age
decl_stmt|;
name|uint16_t
name|cu_hello_time
decl_stmt|;
name|uint16_t
name|cu_forward_delay
decl_stmt|;
name|uint16_t
name|cu_port_id
decl_stmt|;
name|uint8_t
name|cu_message_type
decl_stmt|;
name|uint8_t
name|cu_topology_change_acknowledgment
decl_stmt|;
name|uint8_t
name|cu_topology_change
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

begin_comment
comment|/*  * Bridge interface list entry.  */
end_comment

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
name|int
name|bp_active
decl_stmt|;
name|uint64_t
name|bp_designated_root
decl_stmt|;
name|uint64_t
name|bp_designated_bridge
decl_stmt|;
name|uint32_t
name|bp_path_cost
decl_stmt|;
name|uint32_t
name|bp_designated_cost
decl_stmt|;
name|struct
name|bstp_timer
name|bp_hold_timer
decl_stmt|;
name|struct
name|bstp_timer
name|bp_message_age_timer
decl_stmt|;
name|struct
name|bstp_timer
name|bp_forward_delay_timer
decl_stmt|;
name|struct
name|bstp_config_unit
name|bp_config_bpdu
decl_stmt|;
name|uint16_t
name|bp_port_id
decl_stmt|;
name|uint16_t
name|bp_designated_port
decl_stmt|;
name|uint8_t
name|bp_state
decl_stmt|;
name|uint8_t
name|bp_topology_change_acknowledge
decl_stmt|;
name|uint8_t
name|bp_config_pending
decl_stmt|;
name|uint8_t
name|bp_change_detection_enabled
decl_stmt|;
name|uint8_t
name|bp_priority
decl_stmt|;
name|uint32_t
name|bp_forward_transitions
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
name|struct
name|mtx
name|bs_mtx
decl_stmt|;
name|uint64_t
name|bs_designated_root
decl_stmt|;
name|uint64_t
name|bs_bridge_id
decl_stmt|;
name|struct
name|bstp_port
modifier|*
name|bs_root_port
decl_stmt|;
name|uint32_t
name|bs_root_path_cost
decl_stmt|;
name|uint16_t
name|bs_max_age
decl_stmt|;
name|uint16_t
name|bs_hello_time
decl_stmt|;
name|uint16_t
name|bs_forward_delay
decl_stmt|;
name|uint16_t
name|bs_bridge_max_age
decl_stmt|;
name|uint16_t
name|bs_bridge_hello_time
decl_stmt|;
name|uint16_t
name|bs_bridge_forward_delay
decl_stmt|;
name|uint16_t
name|bs_topology_change_time
decl_stmt|;
name|uint16_t
name|bs_hold_time
decl_stmt|;
name|uint16_t
name|bs_bridge_priority
decl_stmt|;
name|uint8_t
name|bs_topology_change_detected
decl_stmt|;
name|uint8_t
name|bs_topology_change
decl_stmt|;
name|struct
name|bstp_timer
name|bs_hello_timer
decl_stmt|;
name|struct
name|bstp_timer
name|bs_topology_change_timer
decl_stmt|;
name|struct
name|bstp_timer
name|bs_tcn_timer
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
value|mtx_init(&(_bs)->bs_mtx, "bstp", \ 					    NULL, MTX_DEF)
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
name|bstp_reinit
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
name|bstp_add
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
name|void
name|bstp_delete
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

