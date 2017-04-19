begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2017-2018 Cavium, Inc.   * All rights reserved.  *  *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *  *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *  *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  *  POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ECORE_HSI_INIT_FUNC__
end_ifndef

begin_define
define|#
directive|define
name|__ECORE_HSI_INIT_FUNC__
end_define

begin_comment
comment|/********************************/
end_comment

begin_comment
comment|/* HSI Init Functions constants */
end_comment

begin_comment
comment|/********************************/
end_comment

begin_comment
comment|/* Number of VLAN priorities */
end_comment

begin_define
define|#
directive|define
name|NUM_OF_VLAN_PRIORITIES
value|8
end_define

begin_comment
comment|/* Size of CRC8 lookup table */
end_comment

begin_define
define|#
directive|define
name|CRC8_TABLE_SIZE
value|256
end_define

begin_comment
comment|/*  * BRB RAM init requirements  */
end_comment

begin_struct
struct|struct
name|init_brb_ram_req
block|{
name|__le32
name|guranteed_per_tc
comment|/* guaranteed size per TC, in bytes */
decl_stmt|;
name|__le32
name|headroom_per_tc
comment|/* headroom size per TC, in bytes */
decl_stmt|;
name|__le32
name|min_pkt_size
comment|/* min packet size, in bytes */
decl_stmt|;
name|__le32
name|max_ports_per_engine
comment|/* min packet size, in bytes */
decl_stmt|;
name|u8
name|num_active_tcs
index|[
name|MAX_NUM_PORTS
index|]
comment|/* number of active TCs per port */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * ETS per-TC init requirements  */
end_comment

begin_struct
struct|struct
name|init_ets_tc_req
block|{
name|u8
name|use_sp
comment|/* if set, this TC participates in the arbitration with a strict priority (the priority is equal to the TC ID) */
decl_stmt|;
name|u8
name|use_wfq
comment|/* if set, this TC participates in the arbitration with a WFQ weight (indicated by the weight field) */
decl_stmt|;
name|__le16
name|weight
comment|/* An arbitration weight. Valid only if use_wfq is set. */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * ETS init requirements  */
end_comment

begin_struct
struct|struct
name|init_ets_req
block|{
name|__le32
name|mtu
comment|/* Max packet size (in bytes) */
decl_stmt|;
name|struct
name|init_ets_tc_req
name|tc_req
index|[
name|NUM_OF_TCS
index|]
comment|/* ETS initialization requirements per TC. */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * NIG LB RL init requirements  */
end_comment

begin_struct
struct|struct
name|init_nig_lb_rl_req
block|{
name|__le16
name|lb_mac_rate
comment|/* Global MAC+LB RL rate (in Mbps). If set to 0, the RL will be disabled. */
decl_stmt|;
name|__le16
name|lb_rate
comment|/* Global LB RL rate (in Mbps). If set to 0, the RL will be disabled. */
decl_stmt|;
name|__le32
name|mtu
comment|/* Max packet size (in bytes) */
decl_stmt|;
name|__le16
name|tc_rate
index|[
name|NUM_OF_PHYS_TCS
index|]
comment|/* RL rate per physical TC (in Mbps). If set to 0, the RL will be disabled. */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * NIG TC mapping for each priority  */
end_comment

begin_struct
struct|struct
name|init_nig_pri_tc_map_entry
block|{
name|u8
name|tc_id
comment|/* the mapped TC ID */
decl_stmt|;
name|u8
name|valid
comment|/* indicates if the mapping entry is valid */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * NIG priority to TC map init requirements  */
end_comment

begin_struct
struct|struct
name|init_nig_pri_tc_map_req
block|{
name|struct
name|init_nig_pri_tc_map_entry
name|pri
index|[
name|NUM_OF_VLAN_PRIORITIES
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * QM per-port init parameters  */
end_comment

begin_struct
struct|struct
name|init_qm_port_params
block|{
name|u8
name|active
comment|/* Indicates if this port is active */
decl_stmt|;
name|u8
name|active_phys_tcs
comment|/* Vector of valid bits for active TCs used by this port */
decl_stmt|;
name|__le16
name|num_pbf_cmd_lines
comment|/* number of PBF command lines that can be used by this port */
decl_stmt|;
name|__le16
name|num_btb_blocks
comment|/* number of BTB blocks that can be used by this port */
decl_stmt|;
name|__le16
name|reserved
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * QM per-PQ init parameters  */
end_comment

begin_struct
struct|struct
name|init_qm_pq_params
block|{
name|u8
name|vport_id
comment|/* VPORT ID */
decl_stmt|;
name|u8
name|tc_id
comment|/* TC ID */
decl_stmt|;
name|u8
name|wrr_group
comment|/* WRR group */
decl_stmt|;
name|u8
name|rl_valid
comment|/* Indicates if a rate limiter should be allocated for the PQ (0/1) */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * QM per-vport init parameters  */
end_comment

begin_struct
struct|struct
name|init_qm_vport_params
block|{
name|__le32
name|vport_rl
comment|/* rate limit in Mb/sec units. a value of 0 means dont configure. ignored if VPORT RL is globally disabled. */
decl_stmt|;
name|__le16
name|vport_wfq
comment|/* WFQ weight. A value of 0 means dont configure. ignored if VPORT WFQ is globally disabled. */
decl_stmt|;
name|__le16
name|first_tx_pq_id
index|[
name|NUM_OF_TCS
index|]
comment|/* the first Tx PQ ID associated with this VPORT for each TC. */
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ECORE_HSI_INIT_FUNC__ */
end_comment

end_unit

