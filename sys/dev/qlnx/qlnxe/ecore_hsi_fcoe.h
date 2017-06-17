begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2017-2018 Cavium, Inc.   * All rights reserved.  *  *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *  *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *  *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  *  POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ECORE_HSI_FCOE__
end_ifndef

begin_define
define|#
directive|define
name|__ECORE_HSI_FCOE__
end_define

begin_comment
comment|/****************************************/
end_comment

begin_comment
comment|/* Add include to common storage target */
end_comment

begin_comment
comment|/****************************************/
end_comment

begin_include
include|#
directive|include
file|"storage_common.h"
end_include

begin_comment
comment|/************************************************************************/
end_comment

begin_comment
comment|/* Add include to common fcoe target for both eCore and protocol driver */
end_comment

begin_comment
comment|/************************************************************************/
end_comment

begin_include
include|#
directive|include
file|"fcoe_common.h"
end_include

begin_comment
comment|/*  * The fcoe storm context of Ystorm  */
end_comment

begin_struct
struct|struct
name|ystorm_fcoe_conn_st_ctx
block|{
name|u8
name|func_mode
comment|/* Function mode */
decl_stmt|;
name|u8
name|cos
comment|/* Transmission cos */
decl_stmt|;
name|u8
name|conf_version
comment|/* Is dcb_version or vntag_version changed */
decl_stmt|;
name|u8
name|eth_hdr_size
comment|/* Ethernet header size */
decl_stmt|;
name|__le16
name|stat_ram_addr
comment|/* Statistics ram adderss */
decl_stmt|;
name|__le16
name|mtu
comment|/* MTU limitation */
decl_stmt|;
name|__le16
name|max_fc_payload_len
comment|/* Max payload length according to target limitation and mtu. 8 bytes aligned (required for protection fast-path) */
decl_stmt|;
name|__le16
name|tx_max_fc_pay_len
comment|/* Max payload length according to target limitation */
decl_stmt|;
name|u8
name|fcp_cmd_size
comment|/* FCP cmd size. for performance reasons */
decl_stmt|;
name|u8
name|fcp_rsp_size
comment|/* FCP RSP size. for performance reasons */
decl_stmt|;
name|__le16
name|mss
comment|/* MSS for PBF (MSS we negotiate with target - protection data per segment. If we are not in perf mode it will be according to worse case) */
decl_stmt|;
name|struct
name|regpair
name|reserved
decl_stmt|;
name|__le16
name|min_frame_size
comment|/* The minimum ETH frame size required for transmission (including ETH header) */
decl_stmt|;
name|u8
name|protection_info_flags
decl_stmt|;
define|#
directive|define
name|YSTORM_FCOE_CONN_ST_CTX_SUPPORT_PROTECTION_MASK
value|0x1
comment|/* Does this connection support protection (if couple of GOS share this connection itÃ Ã¢âÂ¬Ã¢âÂ¢s enough that one of them support protection) */
define|#
directive|define
name|YSTORM_FCOE_CONN_ST_CTX_SUPPORT_PROTECTION_SHIFT
value|0
define|#
directive|define
name|YSTORM_FCOE_CONN_ST_CTX_VALID_MASK
value|0x1
comment|/* Are we in protection perf mode (there is only one protection mode for this connection and we manage to create mss that contain fixed amount of protection segment and we are only restrict by the target limitation and not line mss this is critical since if line mss restrict us we canÃ Ã¢âÂ¬Ã¢âÂ¢t rely on this size Ã Ã¢âÂ¬Ã¢â¬Å it depends on vlan num) */
define|#
directive|define
name|YSTORM_FCOE_CONN_ST_CTX_VALID_SHIFT
value|1
define|#
directive|define
name|YSTORM_FCOE_CONN_ST_CTX_RESERVED1_MASK
value|0x3F
define|#
directive|define
name|YSTORM_FCOE_CONN_ST_CTX_RESERVED1_SHIFT
value|2
name|u8
name|dst_protection_per_mss
comment|/* Destination Protection data per mss (if we are not in perf mode it will be worse case). Destination is the data add/remove from the transmitted packet (as opposed to src which is data validate by the nic they might not be identical) */
decl_stmt|;
name|u8
name|src_protection_per_mss
comment|/* Source Protection data per mss (if we are not in perf mode it will be worse case). Source  is the data validated by the nic  (as opposed to destination which is data add/remove from the transmitted packet they might not be identical) */
decl_stmt|;
name|u8
name|ptu_log_page_size
comment|/* 0-4K, 1-8K, 2-16K, 3-32K... */
decl_stmt|;
name|u8
name|flags
decl_stmt|;
define|#
directive|define
name|YSTORM_FCOE_CONN_ST_CTX_INNER_VLAN_FLAG_MASK
value|0x1
comment|/* Inner Vlan flag */
define|#
directive|define
name|YSTORM_FCOE_CONN_ST_CTX_INNER_VLAN_FLAG_SHIFT
value|0
define|#
directive|define
name|YSTORM_FCOE_CONN_ST_CTX_OUTER_VLAN_FLAG_MASK
value|0x1
comment|/* Outer Vlan flag */
define|#
directive|define
name|YSTORM_FCOE_CONN_ST_CTX_OUTER_VLAN_FLAG_SHIFT
value|1
define|#
directive|define
name|YSTORM_FCOE_CONN_ST_CTX_RSRV_MASK
value|0x3F
define|#
directive|define
name|YSTORM_FCOE_CONN_ST_CTX_RSRV_SHIFT
value|2
name|u8
name|fcp_xfer_size
comment|/* FCP xfer size. for performance reasons */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * FCoE 16-bits vlan structure  */
end_comment

begin_struct
struct|struct
name|fcoe_vlan_fields
block|{
name|__le16
name|fields
decl_stmt|;
define|#
directive|define
name|FCOE_VLAN_FIELDS_VID_MASK
value|0xFFF
define|#
directive|define
name|FCOE_VLAN_FIELDS_VID_SHIFT
value|0
define|#
directive|define
name|FCOE_VLAN_FIELDS_CLI_MASK
value|0x1
define|#
directive|define
name|FCOE_VLAN_FIELDS_CLI_SHIFT
value|12
define|#
directive|define
name|FCOE_VLAN_FIELDS_PRI_MASK
value|0x7
define|#
directive|define
name|FCOE_VLAN_FIELDS_PRI_SHIFT
value|13
block|}
struct|;
end_struct

begin_comment
comment|/*  * FCoE 16-bits vlan union  */
end_comment

begin_union
union|union
name|fcoe_vlan_field_union
block|{
name|struct
name|fcoe_vlan_fields
name|fields
comment|/* Parameters field */
decl_stmt|;
name|__le16
name|val
comment|/* Global value */
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/*  * FCoE 16-bits vlan, vif union  */
end_comment

begin_union
union|union
name|fcoe_vlan_vif_field_union
block|{
name|union
name|fcoe_vlan_field_union
name|vlan
comment|/* Vlan */
decl_stmt|;
name|__le16
name|vif
comment|/* VIF */
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/*  * Ethernet context section  */
end_comment

begin_struct
struct|struct
name|pstorm_fcoe_eth_context_section
block|{
name|u8
name|remote_addr_3
comment|/* Remote Mac Address, used in PBF Header Builder Command */
decl_stmt|;
name|u8
name|remote_addr_2
comment|/* Remote Mac Address, used in PBF Header Builder Command */
decl_stmt|;
name|u8
name|remote_addr_1
comment|/* Remote Mac Address, used in PBF Header Builder Command */
decl_stmt|;
name|u8
name|remote_addr_0
comment|/* Remote Mac Address, used in PBF Header Builder Command */
decl_stmt|;
name|u8
name|local_addr_1
comment|/* Local Mac Address, used in PBF Header Builder Command */
decl_stmt|;
name|u8
name|local_addr_0
comment|/* Local Mac Address, used in PBF Header Builder Command */
decl_stmt|;
name|u8
name|remote_addr_5
comment|/* Remote Mac Address, used in PBF Header Builder Command */
decl_stmt|;
name|u8
name|remote_addr_4
comment|/* Remote Mac Address, used in PBF Header Builder Command */
decl_stmt|;
name|u8
name|local_addr_5
comment|/* Local Mac Address, used in PBF Header Builder Command */
decl_stmt|;
name|u8
name|local_addr_4
comment|/* Loca lMac Address, used in PBF Header Builder Command */
decl_stmt|;
name|u8
name|local_addr_3
comment|/* Local Mac Address, used in PBF Header Builder Command */
decl_stmt|;
name|u8
name|local_addr_2
comment|/* Local Mac Address, used in PBF Header Builder Command */
decl_stmt|;
name|union
name|fcoe_vlan_vif_field_union
name|vif_outer_vlan
comment|/* Union of VIF and outer vlan */
decl_stmt|;
name|__le16
name|vif_outer_eth_type
comment|/* reserved place for Ethernet type */
decl_stmt|;
name|union
name|fcoe_vlan_vif_field_union
name|inner_vlan
comment|/* inner vlan tag */
decl_stmt|;
name|__le16
name|inner_eth_type
comment|/* reserved place for Ethernet type */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The fcoe storm context of Pstorm  */
end_comment

begin_struct
struct|struct
name|pstorm_fcoe_conn_st_ctx
block|{
name|u8
name|func_mode
comment|/* Function mode */
decl_stmt|;
name|u8
name|cos
comment|/* Transmission cos */
decl_stmt|;
name|u8
name|conf_version
comment|/* Is dcb_version or vntag_version changed */
decl_stmt|;
name|u8
name|rsrv
decl_stmt|;
name|__le16
name|stat_ram_addr
comment|/* Statistics ram adderss */
decl_stmt|;
name|__le16
name|mss
comment|/* MSS for PBF (MSS we negotiate with target - protection data per segment. If we are not in perf mode it will be according to worse case) */
decl_stmt|;
name|struct
name|regpair
name|abts_cleanup_addr
comment|/* Host addr of ABTS /Cleanup info. since we pass it  through session context, we pass only the addr to save space */
decl_stmt|;
name|struct
name|pstorm_fcoe_eth_context_section
name|eth
comment|/* Source mac */
decl_stmt|;
name|u8
name|sid_2
comment|/* SID FC address - Third byte that is sent to NW via PBF For example is SID is 01:02:03 then sid_2 is 0x03 */
decl_stmt|;
name|u8
name|sid_1
comment|/* SID FC address - Second byte that is sent to NW via PBF */
decl_stmt|;
name|u8
name|sid_0
comment|/* SID FC address - First byte that is sent to NW via PBF */
decl_stmt|;
name|u8
name|flags
decl_stmt|;
define|#
directive|define
name|PSTORM_FCOE_CONN_ST_CTX_VNTAG_VLAN_MASK
value|0x1
comment|/* Is inner vlan taken from vntag default vlan (in this case I have to update inner vlan each time the default change) */
define|#
directive|define
name|PSTORM_FCOE_CONN_ST_CTX_VNTAG_VLAN_SHIFT
value|0
define|#
directive|define
name|PSTORM_FCOE_CONN_ST_CTX_SUPPORT_REC_RR_TOV_MASK
value|0x1
comment|/* AreSupport rec_tov timer */
define|#
directive|define
name|PSTORM_FCOE_CONN_ST_CTX_SUPPORT_REC_RR_TOV_SHIFT
value|1
define|#
directive|define
name|PSTORM_FCOE_CONN_ST_CTX_INNER_VLAN_FLAG_MASK
value|0x1
comment|/* Inner Vlan flag */
define|#
directive|define
name|PSTORM_FCOE_CONN_ST_CTX_INNER_VLAN_FLAG_SHIFT
value|2
define|#
directive|define
name|PSTORM_FCOE_CONN_ST_CTX_OUTER_VLAN_FLAG_MASK
value|0x1
comment|/* Outer Vlan flag */
define|#
directive|define
name|PSTORM_FCOE_CONN_ST_CTX_OUTER_VLAN_FLAG_SHIFT
value|3
define|#
directive|define
name|PSTORM_FCOE_CONN_ST_CTX_RESERVED_MASK
value|0xF
define|#
directive|define
name|PSTORM_FCOE_CONN_ST_CTX_RESERVED_SHIFT
value|4
name|u8
name|did_2
comment|/* DID FC address - Third byte that is sent to NW via PBF */
decl_stmt|;
name|u8
name|did_1
comment|/* DID FC address - Second byte that is sent to NW via PBF */
decl_stmt|;
name|u8
name|did_0
comment|/* DID FC address - First byte that is sent to NW via PBF */
decl_stmt|;
name|u8
name|src_mac_index
decl_stmt|;
name|__le16
name|rec_rr_tov_val
comment|/* REC_TOV value negotiated during PLOGI (in msec) */
decl_stmt|;
name|u8
name|q_relative_offset
comment|/* CQ, RQ (and CMDQ) relative offset for connection */
decl_stmt|;
name|u8
name|reserved1
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The fcoe storm context of Xstorm  */
end_comment

begin_struct
struct|struct
name|xstorm_fcoe_conn_st_ctx
block|{
name|u8
name|func_mode
comment|/* Function mode */
decl_stmt|;
name|u8
name|src_mac_index
comment|/* Index to the src_mac arr held in the xStorm RAM. Provided at the xStorm offload connection handler */
decl_stmt|;
name|u8
name|conf_version
comment|/* Advance if vntag/dcb version advance */
decl_stmt|;
name|u8
name|cached_wqes_avail
comment|/* Number of cached wqes available */
decl_stmt|;
name|__le16
name|stat_ram_addr
comment|/* Statistics ram adderss */
decl_stmt|;
name|u8
name|flags
decl_stmt|;
define|#
directive|define
name|XSTORM_FCOE_CONN_ST_CTX_SQ_DEFERRED_MASK
value|0x1
comment|/* SQ deferred (happens when we wait for xfer wqe to complete cleanup/abts */
define|#
directive|define
name|XSTORM_FCOE_CONN_ST_CTX_SQ_DEFERRED_SHIFT
value|0
define|#
directive|define
name|XSTORM_FCOE_CONN_ST_CTX_INNER_VLAN_FLAG_MASK
value|0x1
comment|/* Inner vlan flag Ã¢â¬  for calculating eth header size */
define|#
directive|define
name|XSTORM_FCOE_CONN_ST_CTX_INNER_VLAN_FLAG_SHIFT
value|1
define|#
directive|define
name|XSTORM_FCOE_CONN_ST_CTX_INNER_VLAN_FLAG_ORIG_MASK
value|0x1
comment|/* Original vlan configuration. used when we switch from dcb enable to dcb disabled */
define|#
directive|define
name|XSTORM_FCOE_CONN_ST_CTX_INNER_VLAN_FLAG_ORIG_SHIFT
value|2
define|#
directive|define
name|XSTORM_FCOE_CONN_ST_CTX_LAST_QUEUE_HANDLED_MASK
value|0x3
define|#
directive|define
name|XSTORM_FCOE_CONN_ST_CTX_LAST_QUEUE_HANDLED_SHIFT
value|3
define|#
directive|define
name|XSTORM_FCOE_CONN_ST_CTX_RSRV_MASK
value|0x7
define|#
directive|define
name|XSTORM_FCOE_CONN_ST_CTX_RSRV_SHIFT
value|5
name|u8
name|cached_wqes_offset
comment|/* Offset of first valid cached wqe */
decl_stmt|;
name|u8
name|reserved2
decl_stmt|;
name|u8
name|eth_hdr_size
comment|/* Ethernet header size */
decl_stmt|;
name|u8
name|seq_id
comment|/* Sequence id */
decl_stmt|;
name|u8
name|max_conc_seqs
comment|/* Max concurrent sequence id */
decl_stmt|;
name|__le16
name|num_pages_in_pbl
comment|/* Num of pages in SQ/RESPQ/XFERQ Pbl */
decl_stmt|;
name|__le16
name|reserved
decl_stmt|;
name|struct
name|regpair
name|sq_pbl_addr
comment|/* SQ address */
decl_stmt|;
name|struct
name|regpair
name|sq_curr_page_addr
comment|/* SQ current page address */
decl_stmt|;
name|struct
name|regpair
name|sq_next_page_addr
comment|/* SQ next page address */
decl_stmt|;
name|struct
name|regpair
name|xferq_pbl_addr
comment|/* XFERQ address */
decl_stmt|;
name|struct
name|regpair
name|xferq_curr_page_addr
comment|/* XFERQ current page address */
decl_stmt|;
name|struct
name|regpair
name|xferq_next_page_addr
comment|/* XFERQ next page address */
decl_stmt|;
name|struct
name|regpair
name|respq_pbl_addr
comment|/* RESPQ address */
decl_stmt|;
name|struct
name|regpair
name|respq_curr_page_addr
comment|/* RESPQ current page address */
decl_stmt|;
name|struct
name|regpair
name|respq_next_page_addr
comment|/* RESPQ next page address */
decl_stmt|;
name|__le16
name|mtu
comment|/* MTU limitation */
decl_stmt|;
name|__le16
name|tx_max_fc_pay_len
comment|/* Max payload length according to target limitation */
decl_stmt|;
name|__le16
name|max_fc_payload_len
comment|/* Max payload length according to target limitation and mtu. Aligned to 4 bytes. */
decl_stmt|;
name|__le16
name|min_frame_size
comment|/* The minimum ETH frame size required for transmission (including ETH header, excluding ETH CRC */
decl_stmt|;
name|__le16
name|sq_pbl_next_index
comment|/* Next index of SQ Pbl */
decl_stmt|;
name|__le16
name|respq_pbl_next_index
comment|/* Next index of RESPQ Pbl */
decl_stmt|;
name|u8
name|fcp_cmd_byte_credit
comment|/* Pre-calculated byte credit that single FCP command can consume */
decl_stmt|;
name|u8
name|fcp_rsp_byte_credit
comment|/* Pre-calculated byte credit that single FCP RSP can consume. */
decl_stmt|;
name|__le16
name|protection_info
decl_stmt|;
define|#
directive|define
name|XSTORM_FCOE_CONN_ST_CTX_PROTECTION_PERF_MASK
value|0x1
comment|/* Intend to accelerate the protection flows */
define|#
directive|define
name|XSTORM_FCOE_CONN_ST_CTX_PROTECTION_PERF_SHIFT
value|0
define|#
directive|define
name|XSTORM_FCOE_CONN_ST_CTX_SUPPORT_PROTECTION_MASK
value|0x1
comment|/* Does this connection support protection (if couple of GOS share this connection is enough that one of them support protection) */
define|#
directive|define
name|XSTORM_FCOE_CONN_ST_CTX_SUPPORT_PROTECTION_SHIFT
value|1
define|#
directive|define
name|XSTORM_FCOE_CONN_ST_CTX_VALID_MASK
value|0x1
comment|/* Are we in protection perf mode (there is only one protection mode for this connection and we manage to create mss that contain fixed amount of protection segment and we are only restrict by the target limitation and not line mss this is critical since if line mss restrict us we canÃ¢â¬â¢t rely on this size Ã¢â¬  it depends on vlan num) */
define|#
directive|define
name|XSTORM_FCOE_CONN_ST_CTX_VALID_SHIFT
value|2
define|#
directive|define
name|XSTORM_FCOE_CONN_ST_CTX_FRAME_PROT_ALIGNED_MASK
value|0x1
comment|/* Is size of tx_max_pay_len_prot can be aligned to protection intervals. This means that pure data in each frame is 2k exactly, and protection intervals are no bigger than 2k */
define|#
directive|define
name|XSTORM_FCOE_CONN_ST_CTX_FRAME_PROT_ALIGNED_SHIFT
value|3
define|#
directive|define
name|XSTORM_FCOE_CONN_ST_CTX_RESERVED3_MASK
value|0xF
define|#
directive|define
name|XSTORM_FCOE_CONN_ST_CTX_RESERVED3_SHIFT
value|4
define|#
directive|define
name|XSTORM_FCOE_CONN_ST_CTX_DST_PROTECTION_PER_MSS_MASK
value|0xFF
comment|/* Destination Pro tection data per mss (if we are not in perf mode it will be worse case). Destination is the data add/remove from the transmitted packet (as opposed to src which is data validate by the nic they might not be identical) */
define|#
directive|define
name|XSTORM_FCOE_CONN_ST_CTX_DST_PROTECTION_PER_MSS_SHIFT
value|8
name|__le16
name|xferq_pbl_next_index
comment|/* Next index of XFERQ Pbl */
decl_stmt|;
name|__le16
name|page_size
comment|/* Page size (in bytes) */
decl_stmt|;
name|u8
name|mid_seq
comment|/* Equals 1 for Middle sequence indication, otherwise 0 */
decl_stmt|;
name|u8
name|fcp_xfer_byte_credit
comment|/* Pre-calculated byte credit that single FCP command can consume */
decl_stmt|;
name|u8
name|reserved1
index|[
literal|2
index|]
decl_stmt|;
name|struct
name|fcoe_wqe
name|cached_wqes
index|[
literal|16
index|]
comment|/* cached wqe (8) = 8*8*8Bytes */
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|e4_xstorm_fcoe_conn_ag_ctx
block|{
name|u8
name|reserved0
comment|/* cdu_validation */
decl_stmt|;
name|u8
name|fcoe_state
comment|/* state */
decl_stmt|;
name|u8
name|flags0
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_EXIST_IN_QM0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_EXIST_IN_QM0_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_RESERVED1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_RESERVED1_SHIFT
value|1
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_RESERVED2_MASK
value|0x1
comment|/* exist_in_qm2 */
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_RESERVED2_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_EXIST_IN_QM3_MASK
value|0x1
comment|/* exist_in_qm3 */
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_EXIST_IN_QM3_SHIFT
value|3
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_RESERVED3_MASK
value|0x1
comment|/* bit4 */
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_RESERVED3_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_RESERVED4_MASK
value|0x1
comment|/* cf_array_active */
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_RESERVED4_SHIFT
value|5
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_RESERVED5_MASK
value|0x1
comment|/* bit6 */
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_RESERVED5_SHIFT
value|6
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_RESERVED6_MASK
value|0x1
comment|/* bit7 */
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_RESERVED6_SHIFT
value|7
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_RESERVED7_MASK
value|0x1
comment|/* bit8 */
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_RESERVED7_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_RESERVED8_MASK
value|0x1
comment|/* bit9 */
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_RESERVED8_SHIFT
value|1
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_RESERVED9_MASK
value|0x1
comment|/* bit10 */
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_RESERVED9_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_BIT11_MASK
value|0x1
comment|/* bit11 */
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_BIT11_SHIFT
value|3
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_BIT12_MASK
value|0x1
comment|/* bit12 */
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_BIT12_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_BIT13_MASK
value|0x1
comment|/* bit13 */
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_BIT13_SHIFT
value|5
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_BIT14_MASK
value|0x1
comment|/* bit14 */
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_BIT14_SHIFT
value|6
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_BIT15_MASK
value|0x1
comment|/* bit15 */
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_BIT15_SHIFT
value|7
name|u8
name|flags2
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_CF0_MASK
value|0x3
comment|/* timer0cf */
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_CF0_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_CF1_MASK
value|0x3
comment|/* timer1cf */
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_CF1_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_CF2_MASK
value|0x3
comment|/* timer2cf */
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_CF2_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_CF3_MASK
value|0x3
comment|/* timer_stop_all */
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_CF3_SHIFT
value|6
name|u8
name|flags3
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_CF4_MASK
value|0x3
comment|/* cf4 */
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_CF4_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_CF5_MASK
value|0x3
comment|/* cf5 */
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_CF5_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_CF6_MASK
value|0x3
comment|/* cf6 */
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_CF6_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_CF7_MASK
value|0x3
comment|/* cf7 */
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_CF7_SHIFT
value|6
name|u8
name|flags4
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_CF8_MASK
value|0x3
comment|/* cf8 */
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_CF8_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_CF9_MASK
value|0x3
comment|/* cf9 */
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_CF9_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_CF10_MASK
value|0x3
comment|/* cf10 */
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_CF10_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_CF11_MASK
value|0x3
comment|/* cf11 */
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_CF11_SHIFT
value|6
name|u8
name|flags5
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_CF12_MASK
value|0x3
comment|/* cf12 */
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_CF12_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_CF13_MASK
value|0x3
comment|/* cf13 */
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_CF13_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_CF14_MASK
value|0x3
comment|/* cf14 */
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_CF14_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_CF15_MASK
value|0x3
comment|/* cf15 */
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_CF15_SHIFT
value|6
name|u8
name|flags6
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_CF16_MASK
value|0x3
comment|/* cf16 */
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_CF16_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_CF17_MASK
value|0x3
comment|/* cf_array_cf */
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_CF17_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_CF18_MASK
value|0x3
comment|/* cf18 */
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_CF18_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_DQ_CF_MASK
value|0x3
comment|/* cf19 */
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_DQ_CF_SHIFT
value|6
name|u8
name|flags7
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_FLUSH_Q0_MASK
value|0x3
comment|/* cf20 */
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_FLUSH_Q0_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_RESERVED10_MASK
value|0x3
comment|/* cf21 */
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_RESERVED10_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_SLOW_PATH_MASK
value|0x3
comment|/* cf22 */
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_SLOW_PATH_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_CF0EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_CF0EN_SHIFT
value|6
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_CF1EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_CF1EN_SHIFT
value|7
name|u8
name|flags8
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_CF2EN_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_CF2EN_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_CF3EN_MASK
value|0x1
comment|/* cf3en */
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_CF3EN_SHIFT
value|1
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_CF4EN_MASK
value|0x1
comment|/* cf4en */
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_CF4EN_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_CF5EN_MASK
value|0x1
comment|/* cf5en */
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_CF5EN_SHIFT
value|3
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_CF6EN_MASK
value|0x1
comment|/* cf6en */
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_CF6EN_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_CF7EN_MASK
value|0x1
comment|/* cf7en */
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_CF7EN_SHIFT
value|5
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_CF8EN_MASK
value|0x1
comment|/* cf8en */
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_CF8EN_SHIFT
value|6
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_CF9EN_MASK
value|0x1
comment|/* cf9en */
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_CF9EN_SHIFT
value|7
name|u8
name|flags9
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_CF10EN_MASK
value|0x1
comment|/* cf10en */
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_CF10EN_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_CF11EN_MASK
value|0x1
comment|/* cf11en */
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_CF11EN_SHIFT
value|1
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_CF12EN_MASK
value|0x1
comment|/* cf12en */
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_CF12EN_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_CF13EN_MASK
value|0x1
comment|/* cf13en */
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_CF13EN_SHIFT
value|3
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_CF14EN_MASK
value|0x1
comment|/* cf14en */
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_CF14EN_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_CF15EN_MASK
value|0x1
comment|/* cf15en */
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_CF15EN_SHIFT
value|5
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_CF16EN_MASK
value|0x1
comment|/* cf16en */
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_CF16EN_SHIFT
value|6
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_CF17EN_MASK
value|0x1
comment|/* cf_array_cf_en */
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_CF17EN_SHIFT
value|7
name|u8
name|flags10
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_CF18EN_MASK
value|0x1
comment|/* cf18en */
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_CF18EN_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_DQ_CF_EN_MASK
value|0x1
comment|/* cf19en */
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_DQ_CF_EN_SHIFT
value|1
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_FLUSH_Q0_EN_MASK
value|0x1
comment|/* cf20en */
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_FLUSH_Q0_EN_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_RESERVED11_MASK
value|0x1
comment|/* cf21en */
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_RESERVED11_SHIFT
value|3
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_SLOW_PATH_EN_MASK
value|0x1
comment|/* cf22en */
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_SLOW_PATH_EN_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_CF23EN_MASK
value|0x1
comment|/* cf23en */
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_CF23EN_SHIFT
value|5
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_RESERVED12_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_RESERVED12_SHIFT
value|6
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_RESERVED13_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_RESERVED13_SHIFT
value|7
name|u8
name|flags11
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_RESERVED14_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_RESERVED14_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_RESERVED15_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_RESERVED15_SHIFT
value|1
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_RESERVED16_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_RESERVED16_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_RULE5EN_MASK
value|0x1
comment|/* rule5en */
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_RULE5EN_SHIFT
value|3
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_RULE6EN_MASK
value|0x1
comment|/* rule6en */
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_RULE6EN_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_RULE7EN_MASK
value|0x1
comment|/* rule7en */
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_RULE7EN_SHIFT
value|5
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_A0_RESERVED1_MASK
value|0x1
comment|/* rule8en */
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_A0_RESERVED1_SHIFT
value|6
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_XFERQ_DECISION_EN_MASK
value|0x1
comment|/* rule9en */
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_XFERQ_DECISION_EN_SHIFT
value|7
name|u8
name|flags12
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_SQ_DECISION_EN_MASK
value|0x1
comment|/* rule10en */
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_SQ_DECISION_EN_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_RULE11EN_MASK
value|0x1
comment|/* rule11en */
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_RULE11EN_SHIFT
value|1
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_A0_RESERVED2_MASK
value|0x1
comment|/* rule12en */
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_A0_RESERVED2_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_A0_RESERVED3_MASK
value|0x1
comment|/* rule13en */
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_A0_RESERVED3_SHIFT
value|3
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_RULE14EN_MASK
value|0x1
comment|/* rule14en */
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_RULE14EN_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_RULE15EN_MASK
value|0x1
comment|/* rule15en */
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_RULE15EN_SHIFT
value|5
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_RULE16EN_MASK
value|0x1
comment|/* rule16en */
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_RULE16EN_SHIFT
value|6
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_RULE17EN_MASK
value|0x1
comment|/* rule17en */
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_RULE17EN_SHIFT
value|7
name|u8
name|flags13
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_RESPQ_DECISION_EN_MASK
value|0x1
comment|/* rule18en */
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_RESPQ_DECISION_EN_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_RULE19EN_MASK
value|0x1
comment|/* rule19en */
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_RULE19EN_SHIFT
value|1
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_A0_RESERVED4_MASK
value|0x1
comment|/* rule20en */
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_A0_RESERVED4_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_A0_RESERVED5_MASK
value|0x1
comment|/* rule21en */
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_A0_RESERVED5_SHIFT
value|3
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_A0_RESERVED6_MASK
value|0x1
comment|/* rule22en */
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_A0_RESERVED6_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_A0_RESERVED7_MASK
value|0x1
comment|/* rule23en */
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_A0_RESERVED7_SHIFT
value|5
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_A0_RESERVED8_MASK
value|0x1
comment|/* rule24en */
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_A0_RESERVED8_SHIFT
value|6
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_A0_RESERVED9_MASK
value|0x1
comment|/* rule25en */
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_A0_RESERVED9_SHIFT
value|7
name|u8
name|flags14
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_BIT16_MASK
value|0x1
comment|/* bit16 */
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_BIT16_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_BIT17_MASK
value|0x1
comment|/* bit17 */
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_BIT17_SHIFT
value|1
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_BIT18_MASK
value|0x1
comment|/* bit18 */
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_BIT18_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_BIT19_MASK
value|0x1
comment|/* bit19 */
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_BIT19_SHIFT
value|3
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_BIT20_MASK
value|0x1
comment|/* bit20 */
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_BIT20_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_BIT21_MASK
value|0x1
comment|/* bit21 */
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_BIT21_SHIFT
value|5
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_CF23_MASK
value|0x3
comment|/* cf23 */
define|#
directive|define
name|E4_XSTORM_FCOE_CONN_AG_CTX_CF23_SHIFT
value|6
name|u8
name|byte2
comment|/* byte2 */
decl_stmt|;
name|__le16
name|physical_q0
comment|/* physical_q0 */
decl_stmt|;
name|__le16
name|word1
comment|/* physical_q1 */
decl_stmt|;
name|__le16
name|word2
comment|/* physical_q2 */
decl_stmt|;
name|__le16
name|sq_cons
comment|/* word3 */
decl_stmt|;
name|__le16
name|sq_prod
comment|/* word4 */
decl_stmt|;
name|__le16
name|xferq_prod
comment|/* word5 */
decl_stmt|;
name|__le16
name|xferq_cons
comment|/* conn_dpi */
decl_stmt|;
name|u8
name|byte3
comment|/* byte3 */
decl_stmt|;
name|u8
name|byte4
comment|/* byte4 */
decl_stmt|;
name|u8
name|byte5
comment|/* byte5 */
decl_stmt|;
name|u8
name|byte6
comment|/* byte6 */
decl_stmt|;
name|__le32
name|remain_io
comment|/* reg0 */
decl_stmt|;
name|__le32
name|reg1
comment|/* reg1 */
decl_stmt|;
name|__le32
name|reg2
comment|/* reg2 */
decl_stmt|;
name|__le32
name|reg3
comment|/* reg3 */
decl_stmt|;
name|__le32
name|reg4
comment|/* reg4 */
decl_stmt|;
name|__le32
name|reg5
comment|/* cf_array0 */
decl_stmt|;
name|__le32
name|reg6
comment|/* cf_array1 */
decl_stmt|;
name|__le16
name|respq_prod
comment|/* word7 */
decl_stmt|;
name|__le16
name|respq_cons
comment|/* word8 */
decl_stmt|;
name|__le16
name|word9
comment|/* word9 */
decl_stmt|;
name|__le16
name|word10
comment|/* word10 */
decl_stmt|;
name|__le32
name|reg7
comment|/* reg7 */
decl_stmt|;
name|__le32
name|reg8
comment|/* reg8 */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The fcoe storm context of Ustorm  */
end_comment

begin_struct
struct|struct
name|ustorm_fcoe_conn_st_ctx
block|{
name|struct
name|regpair
name|respq_pbl_addr
comment|/* RespQ Pbl base address */
decl_stmt|;
name|__le16
name|num_pages_in_pbl
comment|/* Number of RespQ pbl pages (both have same wqe size) */
decl_stmt|;
name|u8
name|ptu_log_page_size
comment|/* 0-4K, 1-8K, 2-16K, 3-32K... */
decl_stmt|;
name|u8
name|log_page_size
decl_stmt|;
name|__le16
name|respq_prod
comment|/* RespQ producer */
decl_stmt|;
name|u8
name|reserved
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|e4_tstorm_fcoe_conn_ag_ctx
block|{
name|u8
name|reserved0
comment|/* cdu_validation */
decl_stmt|;
name|u8
name|fcoe_state
comment|/* state */
decl_stmt|;
name|u8
name|flags0
decl_stmt|;
define|#
directive|define
name|E4_TSTORM_FCOE_CONN_AG_CTX_EXIST_IN_QM0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E4_TSTORM_FCOE_CONN_AG_CTX_EXIST_IN_QM0_SHIFT
value|0
define|#
directive|define
name|E4_TSTORM_FCOE_CONN_AG_CTX_BIT1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E4_TSTORM_FCOE_CONN_AG_CTX_BIT1_SHIFT
value|1
define|#
directive|define
name|E4_TSTORM_FCOE_CONN_AG_CTX_BIT2_MASK
value|0x1
comment|/* bit2 */
define|#
directive|define
name|E4_TSTORM_FCOE_CONN_AG_CTX_BIT2_SHIFT
value|2
define|#
directive|define
name|E4_TSTORM_FCOE_CONN_AG_CTX_BIT3_MASK
value|0x1
comment|/* bit3 */
define|#
directive|define
name|E4_TSTORM_FCOE_CONN_AG_CTX_BIT3_SHIFT
value|3
define|#
directive|define
name|E4_TSTORM_FCOE_CONN_AG_CTX_BIT4_MASK
value|0x1
comment|/* bit4 */
define|#
directive|define
name|E4_TSTORM_FCOE_CONN_AG_CTX_BIT4_SHIFT
value|4
define|#
directive|define
name|E4_TSTORM_FCOE_CONN_AG_CTX_BIT5_MASK
value|0x1
comment|/* bit5 */
define|#
directive|define
name|E4_TSTORM_FCOE_CONN_AG_CTX_BIT5_SHIFT
value|5
define|#
directive|define
name|E4_TSTORM_FCOE_CONN_AG_CTX_DUMMY_TIMER_CF_MASK
value|0x3
comment|/* timer0cf */
define|#
directive|define
name|E4_TSTORM_FCOE_CONN_AG_CTX_DUMMY_TIMER_CF_SHIFT
value|6
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E4_TSTORM_FCOE_CONN_AG_CTX_FLUSH_Q0_CF_MASK
value|0x3
comment|/* timer1cf */
define|#
directive|define
name|E4_TSTORM_FCOE_CONN_AG_CTX_FLUSH_Q0_CF_SHIFT
value|0
define|#
directive|define
name|E4_TSTORM_FCOE_CONN_AG_CTX_CF2_MASK
value|0x3
comment|/* timer2cf */
define|#
directive|define
name|E4_TSTORM_FCOE_CONN_AG_CTX_CF2_SHIFT
value|2
define|#
directive|define
name|E4_TSTORM_FCOE_CONN_AG_CTX_TIMER_STOP_ALL_CF_MASK
value|0x3
comment|/* timer_stop_all */
define|#
directive|define
name|E4_TSTORM_FCOE_CONN_AG_CTX_TIMER_STOP_ALL_CF_SHIFT
value|4
define|#
directive|define
name|E4_TSTORM_FCOE_CONN_AG_CTX_CF4_MASK
value|0x3
comment|/* cf4 */
define|#
directive|define
name|E4_TSTORM_FCOE_CONN_AG_CTX_CF4_SHIFT
value|6
name|u8
name|flags2
decl_stmt|;
define|#
directive|define
name|E4_TSTORM_FCOE_CONN_AG_CTX_CF5_MASK
value|0x3
comment|/* cf5 */
define|#
directive|define
name|E4_TSTORM_FCOE_CONN_AG_CTX_CF5_SHIFT
value|0
define|#
directive|define
name|E4_TSTORM_FCOE_CONN_AG_CTX_CF6_MASK
value|0x3
comment|/* cf6 */
define|#
directive|define
name|E4_TSTORM_FCOE_CONN_AG_CTX_CF6_SHIFT
value|2
define|#
directive|define
name|E4_TSTORM_FCOE_CONN_AG_CTX_CF7_MASK
value|0x3
comment|/* cf7 */
define|#
directive|define
name|E4_TSTORM_FCOE_CONN_AG_CTX_CF7_SHIFT
value|4
define|#
directive|define
name|E4_TSTORM_FCOE_CONN_AG_CTX_CF8_MASK
value|0x3
comment|/* cf8 */
define|#
directive|define
name|E4_TSTORM_FCOE_CONN_AG_CTX_CF8_SHIFT
value|6
name|u8
name|flags3
decl_stmt|;
define|#
directive|define
name|E4_TSTORM_FCOE_CONN_AG_CTX_CF9_MASK
value|0x3
comment|/* cf9 */
define|#
directive|define
name|E4_TSTORM_FCOE_CONN_AG_CTX_CF9_SHIFT
value|0
define|#
directive|define
name|E4_TSTORM_FCOE_CONN_AG_CTX_CF10_MASK
value|0x3
comment|/* cf10 */
define|#
directive|define
name|E4_TSTORM_FCOE_CONN_AG_CTX_CF10_SHIFT
value|2
define|#
directive|define
name|E4_TSTORM_FCOE_CONN_AG_CTX_DUMMY_TIMER_CF_EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E4_TSTORM_FCOE_CONN_AG_CTX_DUMMY_TIMER_CF_EN_SHIFT
value|4
define|#
directive|define
name|E4_TSTORM_FCOE_CONN_AG_CTX_FLUSH_Q0_CF_EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E4_TSTORM_FCOE_CONN_AG_CTX_FLUSH_Q0_CF_EN_SHIFT
value|5
define|#
directive|define
name|E4_TSTORM_FCOE_CONN_AG_CTX_CF2EN_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E4_TSTORM_FCOE_CONN_AG_CTX_CF2EN_SHIFT
value|6
define|#
directive|define
name|E4_TSTORM_FCOE_CONN_AG_CTX_TIMER_STOP_ALL_CF_EN_MASK
value|0x1
comment|/* cf3en */
define|#
directive|define
name|E4_TSTORM_FCOE_CONN_AG_CTX_TIMER_STOP_ALL_CF_EN_SHIFT
value|7
name|u8
name|flags4
decl_stmt|;
define|#
directive|define
name|E4_TSTORM_FCOE_CONN_AG_CTX_CF4EN_MASK
value|0x1
comment|/* cf4en */
define|#
directive|define
name|E4_TSTORM_FCOE_CONN_AG_CTX_CF4EN_SHIFT
value|0
define|#
directive|define
name|E4_TSTORM_FCOE_CONN_AG_CTX_CF5EN_MASK
value|0x1
comment|/* cf5en */
define|#
directive|define
name|E4_TSTORM_FCOE_CONN_AG_CTX_CF5EN_SHIFT
value|1
define|#
directive|define
name|E4_TSTORM_FCOE_CONN_AG_CTX_CF6EN_MASK
value|0x1
comment|/* cf6en */
define|#
directive|define
name|E4_TSTORM_FCOE_CONN_AG_CTX_CF6EN_SHIFT
value|2
define|#
directive|define
name|E4_TSTORM_FCOE_CONN_AG_CTX_CF7EN_MASK
value|0x1
comment|/* cf7en */
define|#
directive|define
name|E4_TSTORM_FCOE_CONN_AG_CTX_CF7EN_SHIFT
value|3
define|#
directive|define
name|E4_TSTORM_FCOE_CONN_AG_CTX_CF8EN_MASK
value|0x1
comment|/* cf8en */
define|#
directive|define
name|E4_TSTORM_FCOE_CONN_AG_CTX_CF8EN_SHIFT
value|4
define|#
directive|define
name|E4_TSTORM_FCOE_CONN_AG_CTX_CF9EN_MASK
value|0x1
comment|/* cf9en */
define|#
directive|define
name|E4_TSTORM_FCOE_CONN_AG_CTX_CF9EN_SHIFT
value|5
define|#
directive|define
name|E4_TSTORM_FCOE_CONN_AG_CTX_CF10EN_MASK
value|0x1
comment|/* cf10en */
define|#
directive|define
name|E4_TSTORM_FCOE_CONN_AG_CTX_CF10EN_SHIFT
value|6
define|#
directive|define
name|E4_TSTORM_FCOE_CONN_AG_CTX_RULE0EN_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E4_TSTORM_FCOE_CONN_AG_CTX_RULE0EN_SHIFT
value|7
name|u8
name|flags5
decl_stmt|;
define|#
directive|define
name|E4_TSTORM_FCOE_CONN_AG_CTX_RULE1EN_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E4_TSTORM_FCOE_CONN_AG_CTX_RULE1EN_SHIFT
value|0
define|#
directive|define
name|E4_TSTORM_FCOE_CONN_AG_CTX_RULE2EN_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E4_TSTORM_FCOE_CONN_AG_CTX_RULE2EN_SHIFT
value|1
define|#
directive|define
name|E4_TSTORM_FCOE_CONN_AG_CTX_RULE3EN_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E4_TSTORM_FCOE_CONN_AG_CTX_RULE3EN_SHIFT
value|2
define|#
directive|define
name|E4_TSTORM_FCOE_CONN_AG_CTX_RULE4EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E4_TSTORM_FCOE_CONN_AG_CTX_RULE4EN_SHIFT
value|3
define|#
directive|define
name|E4_TSTORM_FCOE_CONN_AG_CTX_RULE5EN_MASK
value|0x1
comment|/* rule5en */
define|#
directive|define
name|E4_TSTORM_FCOE_CONN_AG_CTX_RULE5EN_SHIFT
value|4
define|#
directive|define
name|E4_TSTORM_FCOE_CONN_AG_CTX_RULE6EN_MASK
value|0x1
comment|/* rule6en */
define|#
directive|define
name|E4_TSTORM_FCOE_CONN_AG_CTX_RULE6EN_SHIFT
value|5
define|#
directive|define
name|E4_TSTORM_FCOE_CONN_AG_CTX_RULE7EN_MASK
value|0x1
comment|/* rule7en */
define|#
directive|define
name|E4_TSTORM_FCOE_CONN_AG_CTX_RULE7EN_SHIFT
value|6
define|#
directive|define
name|E4_TSTORM_FCOE_CONN_AG_CTX_RULE8EN_MASK
value|0x1
comment|/* rule8en */
define|#
directive|define
name|E4_TSTORM_FCOE_CONN_AG_CTX_RULE8EN_SHIFT
value|7
name|__le32
name|reg0
comment|/* reg0 */
decl_stmt|;
name|__le32
name|reg1
comment|/* reg1 */
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|e4_ustorm_fcoe_conn_ag_ctx
block|{
name|u8
name|byte0
comment|/* cdu_validation */
decl_stmt|;
name|u8
name|byte1
comment|/* state */
decl_stmt|;
name|u8
name|flags0
decl_stmt|;
define|#
directive|define
name|E4_USTORM_FCOE_CONN_AG_CTX_BIT0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E4_USTORM_FCOE_CONN_AG_CTX_BIT0_SHIFT
value|0
define|#
directive|define
name|E4_USTORM_FCOE_CONN_AG_CTX_BIT1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E4_USTORM_FCOE_CONN_AG_CTX_BIT1_SHIFT
value|1
define|#
directive|define
name|E4_USTORM_FCOE_CONN_AG_CTX_CF0_MASK
value|0x3
comment|/* timer0cf */
define|#
directive|define
name|E4_USTORM_FCOE_CONN_AG_CTX_CF0_SHIFT
value|2
define|#
directive|define
name|E4_USTORM_FCOE_CONN_AG_CTX_CF1_MASK
value|0x3
comment|/* timer1cf */
define|#
directive|define
name|E4_USTORM_FCOE_CONN_AG_CTX_CF1_SHIFT
value|4
define|#
directive|define
name|E4_USTORM_FCOE_CONN_AG_CTX_CF2_MASK
value|0x3
comment|/* timer2cf */
define|#
directive|define
name|E4_USTORM_FCOE_CONN_AG_CTX_CF2_SHIFT
value|6
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E4_USTORM_FCOE_CONN_AG_CTX_CF3_MASK
value|0x3
comment|/* timer_stop_all */
define|#
directive|define
name|E4_USTORM_FCOE_CONN_AG_CTX_CF3_SHIFT
value|0
define|#
directive|define
name|E4_USTORM_FCOE_CONN_AG_CTX_CF4_MASK
value|0x3
comment|/* cf4 */
define|#
directive|define
name|E4_USTORM_FCOE_CONN_AG_CTX_CF4_SHIFT
value|2
define|#
directive|define
name|E4_USTORM_FCOE_CONN_AG_CTX_CF5_MASK
value|0x3
comment|/* cf5 */
define|#
directive|define
name|E4_USTORM_FCOE_CONN_AG_CTX_CF5_SHIFT
value|4
define|#
directive|define
name|E4_USTORM_FCOE_CONN_AG_CTX_CF6_MASK
value|0x3
comment|/* cf6 */
define|#
directive|define
name|E4_USTORM_FCOE_CONN_AG_CTX_CF6_SHIFT
value|6
name|u8
name|flags2
decl_stmt|;
define|#
directive|define
name|E4_USTORM_FCOE_CONN_AG_CTX_CF0EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E4_USTORM_FCOE_CONN_AG_CTX_CF0EN_SHIFT
value|0
define|#
directive|define
name|E4_USTORM_FCOE_CONN_AG_CTX_CF1EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E4_USTORM_FCOE_CONN_AG_CTX_CF1EN_SHIFT
value|1
define|#
directive|define
name|E4_USTORM_FCOE_CONN_AG_CTX_CF2EN_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E4_USTORM_FCOE_CONN_AG_CTX_CF2EN_SHIFT
value|2
define|#
directive|define
name|E4_USTORM_FCOE_CONN_AG_CTX_CF3EN_MASK
value|0x1
comment|/* cf3en */
define|#
directive|define
name|E4_USTORM_FCOE_CONN_AG_CTX_CF3EN_SHIFT
value|3
define|#
directive|define
name|E4_USTORM_FCOE_CONN_AG_CTX_CF4EN_MASK
value|0x1
comment|/* cf4en */
define|#
directive|define
name|E4_USTORM_FCOE_CONN_AG_CTX_CF4EN_SHIFT
value|4
define|#
directive|define
name|E4_USTORM_FCOE_CONN_AG_CTX_CF5EN_MASK
value|0x1
comment|/* cf5en */
define|#
directive|define
name|E4_USTORM_FCOE_CONN_AG_CTX_CF5EN_SHIFT
value|5
define|#
directive|define
name|E4_USTORM_FCOE_CONN_AG_CTX_CF6EN_MASK
value|0x1
comment|/* cf6en */
define|#
directive|define
name|E4_USTORM_FCOE_CONN_AG_CTX_CF6EN_SHIFT
value|6
define|#
directive|define
name|E4_USTORM_FCOE_CONN_AG_CTX_RULE0EN_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E4_USTORM_FCOE_CONN_AG_CTX_RULE0EN_SHIFT
value|7
name|u8
name|flags3
decl_stmt|;
define|#
directive|define
name|E4_USTORM_FCOE_CONN_AG_CTX_RULE1EN_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E4_USTORM_FCOE_CONN_AG_CTX_RULE1EN_SHIFT
value|0
define|#
directive|define
name|E4_USTORM_FCOE_CONN_AG_CTX_RULE2EN_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E4_USTORM_FCOE_CONN_AG_CTX_RULE2EN_SHIFT
value|1
define|#
directive|define
name|E4_USTORM_FCOE_CONN_AG_CTX_RULE3EN_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E4_USTORM_FCOE_CONN_AG_CTX_RULE3EN_SHIFT
value|2
define|#
directive|define
name|E4_USTORM_FCOE_CONN_AG_CTX_RULE4EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E4_USTORM_FCOE_CONN_AG_CTX_RULE4EN_SHIFT
value|3
define|#
directive|define
name|E4_USTORM_FCOE_CONN_AG_CTX_RULE5EN_MASK
value|0x1
comment|/* rule5en */
define|#
directive|define
name|E4_USTORM_FCOE_CONN_AG_CTX_RULE5EN_SHIFT
value|4
define|#
directive|define
name|E4_USTORM_FCOE_CONN_AG_CTX_RULE6EN_MASK
value|0x1
comment|/* rule6en */
define|#
directive|define
name|E4_USTORM_FCOE_CONN_AG_CTX_RULE6EN_SHIFT
value|5
define|#
directive|define
name|E4_USTORM_FCOE_CONN_AG_CTX_RULE7EN_MASK
value|0x1
comment|/* rule7en */
define|#
directive|define
name|E4_USTORM_FCOE_CONN_AG_CTX_RULE7EN_SHIFT
value|6
define|#
directive|define
name|E4_USTORM_FCOE_CONN_AG_CTX_RULE8EN_MASK
value|0x1
comment|/* rule8en */
define|#
directive|define
name|E4_USTORM_FCOE_CONN_AG_CTX_RULE8EN_SHIFT
value|7
name|u8
name|byte2
comment|/* byte2 */
decl_stmt|;
name|u8
name|byte3
comment|/* byte3 */
decl_stmt|;
name|__le16
name|word0
comment|/* conn_dpi */
decl_stmt|;
name|__le16
name|word1
comment|/* word1 */
decl_stmt|;
name|__le32
name|reg0
comment|/* reg0 */
decl_stmt|;
name|__le32
name|reg1
comment|/* reg1 */
decl_stmt|;
name|__le32
name|reg2
comment|/* reg2 */
decl_stmt|;
name|__le32
name|reg3
comment|/* reg3 */
decl_stmt|;
name|__le16
name|word2
comment|/* word2 */
decl_stmt|;
name|__le16
name|word3
comment|/* word3 */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The fcoe storm context of Tstorm  */
end_comment

begin_struct
struct|struct
name|tstorm_fcoe_conn_st_ctx
block|{
name|__le16
name|stat_ram_addr
comment|/* Statistics ram adderss */
decl_stmt|;
name|__le16
name|rx_max_fc_payload_len
comment|/* Max rx fc payload length. provided in ramrod */
decl_stmt|;
name|__le16
name|e_d_tov_val
comment|/* E_D_TOV value negotiated during PLOGI (in msec) */
decl_stmt|;
name|u8
name|flags
decl_stmt|;
define|#
directive|define
name|TSTORM_FCOE_CONN_ST_CTX_INC_SEQ_CNT_MASK
value|0x1
comment|/* Does the target support increment sequence counter */
define|#
directive|define
name|TSTORM_FCOE_CONN_ST_CTX_INC_SEQ_CNT_SHIFT
value|0
define|#
directive|define
name|TSTORM_FCOE_CONN_ST_CTX_SUPPORT_CONF_MASK
value|0x1
comment|/* Does the connection support CONF REQ transmission */
define|#
directive|define
name|TSTORM_FCOE_CONN_ST_CTX_SUPPORT_CONF_SHIFT
value|1
define|#
directive|define
name|TSTORM_FCOE_CONN_ST_CTX_DEF_Q_IDX_MASK
value|0x3F
comment|/* Default queue index the connection associated to */
define|#
directive|define
name|TSTORM_FCOE_CONN_ST_CTX_DEF_Q_IDX_SHIFT
value|2
name|u8
name|timers_cleanup_invocation_cnt
comment|/* This variable is incremented each time the tStorm handler for timers cleanup is invoked within the same timers cleanup flow */
decl_stmt|;
name|__le32
name|reserved1
index|[
literal|2
index|]
decl_stmt|;
name|__le32
name|dstMacAddressBytes0To3
comment|/* destination MAC address: Bytes 0-3. */
decl_stmt|;
name|__le16
name|dstMacAddressBytes4To5
comment|/* destination MAC address: Bytes 4-5. */
decl_stmt|;
name|__le16
name|ramrodEcho
comment|/* Saved ramrod echo - needed for 2nd round of terminate_conn (flush Q0) */
decl_stmt|;
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|TSTORM_FCOE_CONN_ST_CTX_MODE_MASK
value|0x3
comment|/* Indicate the mode of the connection: Target or Initiator, use enum fcoe_mode_type */
define|#
directive|define
name|TSTORM_FCOE_CONN_ST_CTX_MODE_SHIFT
value|0
define|#
directive|define
name|TSTORM_FCOE_CONN_ST_CTX_RESERVED_MASK
value|0x3F
define|#
directive|define
name|TSTORM_FCOE_CONN_ST_CTX_RESERVED_SHIFT
value|2
name|u8
name|q_relative_offset
comment|/* CQ, RQ and CMDQ relative offset for connection */
decl_stmt|;
name|u8
name|bdq_resource_id
comment|/* The BDQ resource ID to which this function is mapped */
decl_stmt|;
name|u8
name|reserved0
index|[
literal|5
index|]
comment|/* Alignment to 128b */
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|e4_mstorm_fcoe_conn_ag_ctx
block|{
name|u8
name|byte0
comment|/* cdu_validation */
decl_stmt|;
name|u8
name|byte1
comment|/* state */
decl_stmt|;
name|u8
name|flags0
decl_stmt|;
define|#
directive|define
name|E4_MSTORM_FCOE_CONN_AG_CTX_BIT0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E4_MSTORM_FCOE_CONN_AG_CTX_BIT0_SHIFT
value|0
define|#
directive|define
name|E4_MSTORM_FCOE_CONN_AG_CTX_BIT1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E4_MSTORM_FCOE_CONN_AG_CTX_BIT1_SHIFT
value|1
define|#
directive|define
name|E4_MSTORM_FCOE_CONN_AG_CTX_CF0_MASK
value|0x3
comment|/* cf0 */
define|#
directive|define
name|E4_MSTORM_FCOE_CONN_AG_CTX_CF0_SHIFT
value|2
define|#
directive|define
name|E4_MSTORM_FCOE_CONN_AG_CTX_CF1_MASK
value|0x3
comment|/* cf1 */
define|#
directive|define
name|E4_MSTORM_FCOE_CONN_AG_CTX_CF1_SHIFT
value|4
define|#
directive|define
name|E4_MSTORM_FCOE_CONN_AG_CTX_CF2_MASK
value|0x3
comment|/* cf2 */
define|#
directive|define
name|E4_MSTORM_FCOE_CONN_AG_CTX_CF2_SHIFT
value|6
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E4_MSTORM_FCOE_CONN_AG_CTX_CF0EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E4_MSTORM_FCOE_CONN_AG_CTX_CF0EN_SHIFT
value|0
define|#
directive|define
name|E4_MSTORM_FCOE_CONN_AG_CTX_CF1EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E4_MSTORM_FCOE_CONN_AG_CTX_CF1EN_SHIFT
value|1
define|#
directive|define
name|E4_MSTORM_FCOE_CONN_AG_CTX_CF2EN_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E4_MSTORM_FCOE_CONN_AG_CTX_CF2EN_SHIFT
value|2
define|#
directive|define
name|E4_MSTORM_FCOE_CONN_AG_CTX_RULE0EN_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E4_MSTORM_FCOE_CONN_AG_CTX_RULE0EN_SHIFT
value|3
define|#
directive|define
name|E4_MSTORM_FCOE_CONN_AG_CTX_RULE1EN_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E4_MSTORM_FCOE_CONN_AG_CTX_RULE1EN_SHIFT
value|4
define|#
directive|define
name|E4_MSTORM_FCOE_CONN_AG_CTX_RULE2EN_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E4_MSTORM_FCOE_CONN_AG_CTX_RULE2EN_SHIFT
value|5
define|#
directive|define
name|E4_MSTORM_FCOE_CONN_AG_CTX_RULE3EN_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E4_MSTORM_FCOE_CONN_AG_CTX_RULE3EN_SHIFT
value|6
define|#
directive|define
name|E4_MSTORM_FCOE_CONN_AG_CTX_RULE4EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E4_MSTORM_FCOE_CONN_AG_CTX_RULE4EN_SHIFT
value|7
name|__le16
name|word0
comment|/* word0 */
decl_stmt|;
name|__le16
name|word1
comment|/* word1 */
decl_stmt|;
name|__le32
name|reg0
comment|/* reg0 */
decl_stmt|;
name|__le32
name|reg1
comment|/* reg1 */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Fast path part of the fcoe storm context of Mstorm  */
end_comment

begin_struct
struct|struct
name|fcoe_mstorm_fcoe_conn_st_ctx_fp
block|{
name|__le16
name|xfer_prod
comment|/* XferQ producer */
decl_stmt|;
name|__le16
name|reserved1
decl_stmt|;
name|u8
name|protection_info
decl_stmt|;
define|#
directive|define
name|FCOE_MSTORM_FCOE_CONN_ST_CTX_FP_SUPPORT_PROTECTION_MASK
value|0x1
comment|/* Does this connection support protection (if couple of GOS share this connection it is enough that one of them support protection) */
define|#
directive|define
name|FCOE_MSTORM_FCOE_CONN_ST_CTX_FP_SUPPORT_PROTECTION_SHIFT
value|0
define|#
directive|define
name|FCOE_MSTORM_FCOE_CONN_ST_CTX_FP_VALID_MASK
value|0x1
comment|/* Are we in protection perf mode (there is only one protection mode for this connection and we manage to create mss that contain fixed amount of protection segment and we are only restrict by the target limitation and not line mss Ã¢â¬  this is critical since if line mss restrict us we canÃ¢â¬â¢t rely on this size Ã¢â¬  it depends on vlan num) */
define|#
directive|define
name|FCOE_MSTORM_FCOE_CONN_ST_CTX_FP_VALID_SHIFT
value|1
define|#
directive|define
name|FCOE_MSTORM_FCOE_CONN_ST_CTX_FP_RESERVED0_MASK
value|0x3F
define|#
directive|define
name|FCOE_MSTORM_FCOE_CONN_ST_CTX_FP_RESERVED0_SHIFT
value|2
name|u8
name|q_relative_offset
comment|/* CQ, RQ and CMDQ relative offset for connection */
decl_stmt|;
name|u8
name|reserved2
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Non fast path part of the fcoe storm context of Mstorm  */
end_comment

begin_struct
struct|struct
name|fcoe_mstorm_fcoe_conn_st_ctx_non_fp
block|{
name|__le16
name|conn_id
comment|/* Driver connection ID. To be used by slowpaths to fill EQ placement params */
decl_stmt|;
name|__le16
name|stat_ram_addr
comment|/* Statistics ram adderss */
decl_stmt|;
name|__le16
name|num_pages_in_pbl
comment|/* Number of XferQ/RespQ pbl pages (both have same wqe size) */
decl_stmt|;
name|u8
name|ptu_log_page_size
comment|/* 0-4K, 1-8K, 2-16K, 3-32K... */
decl_stmt|;
name|u8
name|log_page_size
decl_stmt|;
name|__le16
name|unsolicited_cq_count
comment|/* Counts number of CQs done due to unsolicited packets on this connection */
decl_stmt|;
name|__le16
name|cmdq_count
comment|/* Counts number of CMDQs done on this connection */
decl_stmt|;
name|u8
name|bdq_resource_id
comment|/* BDQ Resource ID */
decl_stmt|;
name|u8
name|reserved0
index|[
literal|3
index|]
comment|/* Padding bytes for 2nd RegPair */
decl_stmt|;
name|struct
name|regpair
name|xferq_pbl_addr
comment|/* XferQ Pbl base address */
decl_stmt|;
name|struct
name|regpair
name|reserved1
decl_stmt|;
name|struct
name|regpair
name|reserved2
index|[
literal|3
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The fcoe storm context of Mstorm  */
end_comment

begin_struct
struct|struct
name|mstorm_fcoe_conn_st_ctx
block|{
name|struct
name|fcoe_mstorm_fcoe_conn_st_ctx_fp
name|fp
comment|/* Fast path part of the fcoe storm context of Mstorm */
decl_stmt|;
name|struct
name|fcoe_mstorm_fcoe_conn_st_ctx_non_fp
name|non_fp
comment|/* Non fast path part of the fcoe storm context of Mstorm */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * fcoe connection context  */
end_comment

begin_struct
struct|struct
name|e4_fcoe_conn_context
block|{
name|struct
name|ystorm_fcoe_conn_st_ctx
name|ystorm_st_context
comment|/* ystorm storm context */
decl_stmt|;
name|struct
name|pstorm_fcoe_conn_st_ctx
name|pstorm_st_context
comment|/* pstorm storm context */
decl_stmt|;
name|struct
name|regpair
name|pstorm_st_padding
index|[
literal|2
index|]
comment|/* padding */
decl_stmt|;
name|struct
name|xstorm_fcoe_conn_st_ctx
name|xstorm_st_context
comment|/* xstorm storm context */
decl_stmt|;
name|struct
name|e4_xstorm_fcoe_conn_ag_ctx
name|xstorm_ag_context
comment|/* xstorm aggregative context */
decl_stmt|;
name|struct
name|regpair
name|xstorm_ag_padding
index|[
literal|6
index|]
comment|/* padding */
decl_stmt|;
name|struct
name|ustorm_fcoe_conn_st_ctx
name|ustorm_st_context
comment|/* ustorm storm context */
decl_stmt|;
name|struct
name|regpair
name|ustorm_st_padding
index|[
literal|2
index|]
comment|/* padding */
decl_stmt|;
name|struct
name|e4_tstorm_fcoe_conn_ag_ctx
name|tstorm_ag_context
comment|/* tstorm aggregative context */
decl_stmt|;
name|struct
name|regpair
name|tstorm_ag_padding
index|[
literal|2
index|]
comment|/* padding */
decl_stmt|;
name|struct
name|timers_context
name|timer_context
comment|/* timer context */
decl_stmt|;
name|struct
name|e4_ustorm_fcoe_conn_ag_ctx
name|ustorm_ag_context
comment|/* ustorm aggregative context */
decl_stmt|;
name|struct
name|tstorm_fcoe_conn_st_ctx
name|tstorm_st_context
comment|/* tstorm storm context */
decl_stmt|;
name|struct
name|e4_mstorm_fcoe_conn_ag_ctx
name|mstorm_ag_context
comment|/* mstorm aggregative context */
decl_stmt|;
name|struct
name|mstorm_fcoe_conn_st_ctx
name|mstorm_st_context
comment|/* mstorm storm context */
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|e5_xstorm_fcoe_conn_ag_ctx
block|{
name|u8
name|reserved0
comment|/* cdu_validation */
decl_stmt|;
name|u8
name|state_and_core_id
comment|/* state_and_core_id */
decl_stmt|;
name|u8
name|flags0
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_EXIST_IN_QM0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_EXIST_IN_QM0_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_RESERVED1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_RESERVED1_SHIFT
value|1
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_RESERVED2_MASK
value|0x1
comment|/* exist_in_qm2 */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_RESERVED2_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_EXIST_IN_QM3_MASK
value|0x1
comment|/* exist_in_qm3 */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_EXIST_IN_QM3_SHIFT
value|3
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_RESERVED3_MASK
value|0x1
comment|/* bit4 */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_RESERVED3_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_RESERVED4_MASK
value|0x1
comment|/* cf_array_active */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_RESERVED4_SHIFT
value|5
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_RESERVED5_MASK
value|0x1
comment|/* bit6 */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_RESERVED5_SHIFT
value|6
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_RESERVED6_MASK
value|0x1
comment|/* bit7 */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_RESERVED6_SHIFT
value|7
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_RESERVED7_MASK
value|0x1
comment|/* bit8 */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_RESERVED7_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_RESERVED8_MASK
value|0x1
comment|/* bit9 */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_RESERVED8_SHIFT
value|1
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_RESERVED9_MASK
value|0x1
comment|/* bit10 */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_RESERVED9_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_BIT11_MASK
value|0x1
comment|/* bit11 */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_BIT11_SHIFT
value|3
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_BIT12_MASK
value|0x1
comment|/* bit12 */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_BIT12_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_BIT13_MASK
value|0x1
comment|/* bit13 */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_BIT13_SHIFT
value|5
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_BIT14_MASK
value|0x1
comment|/* bit14 */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_BIT14_SHIFT
value|6
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_BIT15_MASK
value|0x1
comment|/* bit15 */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_BIT15_SHIFT
value|7
name|u8
name|flags2
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_CF0_MASK
value|0x3
comment|/* timer0cf */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_CF0_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_CF1_MASK
value|0x3
comment|/* timer1cf */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_CF1_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_CF2_MASK
value|0x3
comment|/* timer2cf */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_CF2_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_CF3_MASK
value|0x3
comment|/* timer_stop_all */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_CF3_SHIFT
value|6
name|u8
name|flags3
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_CF4_MASK
value|0x3
comment|/* cf4 */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_CF4_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_CF5_MASK
value|0x3
comment|/* cf5 */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_CF5_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_CF6_MASK
value|0x3
comment|/* cf6 */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_CF6_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_CF7_MASK
value|0x3
comment|/* cf7 */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_CF7_SHIFT
value|6
name|u8
name|flags4
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_CF8_MASK
value|0x3
comment|/* cf8 */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_CF8_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_CF9_MASK
value|0x3
comment|/* cf9 */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_CF9_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_CF10_MASK
value|0x3
comment|/* cf10 */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_CF10_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_CF11_MASK
value|0x3
comment|/* cf11 */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_CF11_SHIFT
value|6
name|u8
name|flags5
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_CF12_MASK
value|0x3
comment|/* cf12 */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_CF12_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_CF13_MASK
value|0x3
comment|/* cf13 */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_CF13_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_CF14_MASK
value|0x3
comment|/* cf14 */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_CF14_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_CF15_MASK
value|0x3
comment|/* cf15 */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_CF15_SHIFT
value|6
name|u8
name|flags6
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_CF16_MASK
value|0x3
comment|/* cf16 */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_CF16_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_CF17_MASK
value|0x3
comment|/* cf_array_cf */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_CF17_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_CF18_MASK
value|0x3
comment|/* cf18 */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_CF18_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_DQ_CF_MASK
value|0x3
comment|/* cf19 */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_DQ_CF_SHIFT
value|6
name|u8
name|flags7
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_FLUSH_Q0_MASK
value|0x3
comment|/* cf20 */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_FLUSH_Q0_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_RESERVED10_MASK
value|0x3
comment|/* cf21 */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_RESERVED10_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_SLOW_PATH_MASK
value|0x3
comment|/* cf22 */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_SLOW_PATH_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_CF0EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_CF0EN_SHIFT
value|6
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_CF1EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_CF1EN_SHIFT
value|7
name|u8
name|flags8
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_CF2EN_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_CF2EN_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_CF3EN_MASK
value|0x1
comment|/* cf3en */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_CF3EN_SHIFT
value|1
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_CF4EN_MASK
value|0x1
comment|/* cf4en */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_CF4EN_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_CF5EN_MASK
value|0x1
comment|/* cf5en */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_CF5EN_SHIFT
value|3
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_CF6EN_MASK
value|0x1
comment|/* cf6en */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_CF6EN_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_CF7EN_MASK
value|0x1
comment|/* cf7en */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_CF7EN_SHIFT
value|5
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_CF8EN_MASK
value|0x1
comment|/* cf8en */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_CF8EN_SHIFT
value|6
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_CF9EN_MASK
value|0x1
comment|/* cf9en */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_CF9EN_SHIFT
value|7
name|u8
name|flags9
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_CF10EN_MASK
value|0x1
comment|/* cf10en */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_CF10EN_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_CF11EN_MASK
value|0x1
comment|/* cf11en */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_CF11EN_SHIFT
value|1
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_CF12EN_MASK
value|0x1
comment|/* cf12en */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_CF12EN_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_CF13EN_MASK
value|0x1
comment|/* cf13en */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_CF13EN_SHIFT
value|3
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_CF14EN_MASK
value|0x1
comment|/* cf14en */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_CF14EN_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_CF15EN_MASK
value|0x1
comment|/* cf15en */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_CF15EN_SHIFT
value|5
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_CF16EN_MASK
value|0x1
comment|/* cf16en */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_CF16EN_SHIFT
value|6
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_CF17EN_MASK
value|0x1
comment|/* cf_array_cf_en */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_CF17EN_SHIFT
value|7
name|u8
name|flags10
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_CF18EN_MASK
value|0x1
comment|/* cf18en */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_CF18EN_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_DQ_CF_EN_MASK
value|0x1
comment|/* cf19en */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_DQ_CF_EN_SHIFT
value|1
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_FLUSH_Q0_EN_MASK
value|0x1
comment|/* cf20en */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_FLUSH_Q0_EN_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_RESERVED11_MASK
value|0x1
comment|/* cf21en */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_RESERVED11_SHIFT
value|3
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_SLOW_PATH_EN_MASK
value|0x1
comment|/* cf22en */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_SLOW_PATH_EN_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_CF23EN_MASK
value|0x1
comment|/* cf23en */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_CF23EN_SHIFT
value|5
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_RESERVED12_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_RESERVED12_SHIFT
value|6
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_RESERVED13_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_RESERVED13_SHIFT
value|7
name|u8
name|flags11
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_RESERVED14_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_RESERVED14_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_RESERVED15_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_RESERVED15_SHIFT
value|1
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_RESERVED16_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_RESERVED16_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_RULE5EN_MASK
value|0x1
comment|/* rule5en */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_RULE5EN_SHIFT
value|3
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_RULE6EN_MASK
value|0x1
comment|/* rule6en */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_RULE6EN_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_RULE7EN_MASK
value|0x1
comment|/* rule7en */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_RULE7EN_SHIFT
value|5
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_A0_RESERVED1_MASK
value|0x1
comment|/* rule8en */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_A0_RESERVED1_SHIFT
value|6
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_XFERQ_DECISION_EN_MASK
value|0x1
comment|/* rule9en */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_XFERQ_DECISION_EN_SHIFT
value|7
name|u8
name|flags12
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_SQ_DECISION_EN_MASK
value|0x1
comment|/* rule10en */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_SQ_DECISION_EN_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_RULE11EN_MASK
value|0x1
comment|/* rule11en */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_RULE11EN_SHIFT
value|1
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_A0_RESERVED2_MASK
value|0x1
comment|/* rule12en */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_A0_RESERVED2_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_A0_RESERVED3_MASK
value|0x1
comment|/* rule13en */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_A0_RESERVED3_SHIFT
value|3
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_RULE14EN_MASK
value|0x1
comment|/* rule14en */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_RULE14EN_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_RULE15EN_MASK
value|0x1
comment|/* rule15en */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_RULE15EN_SHIFT
value|5
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_RULE16EN_MASK
value|0x1
comment|/* rule16en */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_RULE16EN_SHIFT
value|6
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_RULE17EN_MASK
value|0x1
comment|/* rule17en */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_RULE17EN_SHIFT
value|7
name|u8
name|flags13
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_RESPQ_DECISION_EN_MASK
value|0x1
comment|/* rule18en */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_RESPQ_DECISION_EN_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_RULE19EN_MASK
value|0x1
comment|/* rule19en */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_RULE19EN_SHIFT
value|1
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_A0_RESERVED4_MASK
value|0x1
comment|/* rule20en */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_A0_RESERVED4_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_A0_RESERVED5_MASK
value|0x1
comment|/* rule21en */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_A0_RESERVED5_SHIFT
value|3
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_A0_RESERVED6_MASK
value|0x1
comment|/* rule22en */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_A0_RESERVED6_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_A0_RESERVED7_MASK
value|0x1
comment|/* rule23en */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_A0_RESERVED7_SHIFT
value|5
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_A0_RESERVED8_MASK
value|0x1
comment|/* rule24en */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_A0_RESERVED8_SHIFT
value|6
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_A0_RESERVED9_MASK
value|0x1
comment|/* rule25en */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_A0_RESERVED9_SHIFT
value|7
name|u8
name|flags14
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_BIT16_MASK
value|0x1
comment|/* bit16 */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_BIT16_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_BIT17_MASK
value|0x1
comment|/* bit17 */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_BIT17_SHIFT
value|1
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_BIT18_MASK
value|0x1
comment|/* bit18 */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_BIT18_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_BIT19_MASK
value|0x1
comment|/* bit19 */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_BIT19_SHIFT
value|3
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_BIT20_MASK
value|0x1
comment|/* bit20 */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_BIT20_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_BIT21_MASK
value|0x1
comment|/* bit21 */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_BIT21_SHIFT
value|5
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_CF23_MASK
value|0x3
comment|/* cf23 */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_CF23_SHIFT
value|6
name|u8
name|byte2
comment|/* byte2 */
decl_stmt|;
name|__le16
name|physical_q0
comment|/* physical_q0 */
decl_stmt|;
name|__le16
name|word1
comment|/* physical_q1 */
decl_stmt|;
name|__le16
name|word2
comment|/* physical_q2 */
decl_stmt|;
name|__le16
name|sq_cons
comment|/* word3 */
decl_stmt|;
name|__le16
name|sq_prod
comment|/* word4 */
decl_stmt|;
name|__le16
name|xferq_prod
comment|/* word5 */
decl_stmt|;
name|__le16
name|xferq_cons
comment|/* conn_dpi */
decl_stmt|;
name|u8
name|byte3
comment|/* byte3 */
decl_stmt|;
name|u8
name|byte4
comment|/* byte4 */
decl_stmt|;
name|u8
name|byte5
comment|/* byte5 */
decl_stmt|;
name|u8
name|byte6
comment|/* byte6 */
decl_stmt|;
name|__le32
name|remain_io
comment|/* reg0 */
decl_stmt|;
name|__le32
name|reg1
comment|/* reg1 */
decl_stmt|;
name|__le32
name|reg2
comment|/* reg2 */
decl_stmt|;
name|__le32
name|reg3
comment|/* reg3 */
decl_stmt|;
name|__le32
name|reg4
comment|/* reg4 */
decl_stmt|;
name|__le32
name|reg5
comment|/* cf_array0 */
decl_stmt|;
name|__le32
name|reg6
comment|/* cf_array1 */
decl_stmt|;
name|u8
name|flags15
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_E4_RESERVED1_MASK
value|0x1
comment|/* bit22 */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_E4_RESERVED1_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_E4_RESERVED2_MASK
value|0x1
comment|/* bit23 */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_E4_RESERVED2_SHIFT
value|1
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_E4_RESERVED3_MASK
value|0x1
comment|/* bit24 */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_E4_RESERVED3_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_E4_RESERVED4_MASK
value|0x3
comment|/* cf24 */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_E4_RESERVED4_SHIFT
value|3
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_E4_RESERVED5_MASK
value|0x1
comment|/* cf24en */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_E4_RESERVED5_SHIFT
value|5
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_E4_RESERVED6_MASK
value|0x1
comment|/* rule26en */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_E4_RESERVED6_SHIFT
value|6
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_E4_RESERVED7_MASK
value|0x1
comment|/* rule27en */
define|#
directive|define
name|E5_XSTORM_FCOE_CONN_AG_CTX_E4_RESERVED7_SHIFT
value|7
name|u8
name|byte7
comment|/* byte7 */
decl_stmt|;
name|__le16
name|respq_prod
comment|/* word7 */
decl_stmt|;
name|__le16
name|respq_cons
comment|/* word8 */
decl_stmt|;
name|__le16
name|word9
comment|/* word9 */
decl_stmt|;
name|__le16
name|word10
comment|/* word10 */
decl_stmt|;
name|__le16
name|word11
comment|/* word11 */
decl_stmt|;
name|__le32
name|reg7
comment|/* reg7 */
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|e5_tstorm_fcoe_conn_ag_ctx
block|{
name|u8
name|reserved0
comment|/* cdu_validation */
decl_stmt|;
name|u8
name|state_and_core_id
comment|/* state_and_core_id */
decl_stmt|;
name|u8
name|flags0
decl_stmt|;
define|#
directive|define
name|E5_TSTORM_FCOE_CONN_AG_CTX_EXIST_IN_QM0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E5_TSTORM_FCOE_CONN_AG_CTX_EXIST_IN_QM0_SHIFT
value|0
define|#
directive|define
name|E5_TSTORM_FCOE_CONN_AG_CTX_BIT1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E5_TSTORM_FCOE_CONN_AG_CTX_BIT1_SHIFT
value|1
define|#
directive|define
name|E5_TSTORM_FCOE_CONN_AG_CTX_BIT2_MASK
value|0x1
comment|/* bit2 */
define|#
directive|define
name|E5_TSTORM_FCOE_CONN_AG_CTX_BIT2_SHIFT
value|2
define|#
directive|define
name|E5_TSTORM_FCOE_CONN_AG_CTX_BIT3_MASK
value|0x1
comment|/* bit3 */
define|#
directive|define
name|E5_TSTORM_FCOE_CONN_AG_CTX_BIT3_SHIFT
value|3
define|#
directive|define
name|E5_TSTORM_FCOE_CONN_AG_CTX_BIT4_MASK
value|0x1
comment|/* bit4 */
define|#
directive|define
name|E5_TSTORM_FCOE_CONN_AG_CTX_BIT4_SHIFT
value|4
define|#
directive|define
name|E5_TSTORM_FCOE_CONN_AG_CTX_BIT5_MASK
value|0x1
comment|/* bit5 */
define|#
directive|define
name|E5_TSTORM_FCOE_CONN_AG_CTX_BIT5_SHIFT
value|5
define|#
directive|define
name|E5_TSTORM_FCOE_CONN_AG_CTX_DUMMY_TIMER_CF_MASK
value|0x3
comment|/* timer0cf */
define|#
directive|define
name|E5_TSTORM_FCOE_CONN_AG_CTX_DUMMY_TIMER_CF_SHIFT
value|6
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E5_TSTORM_FCOE_CONN_AG_CTX_FLUSH_Q0_CF_MASK
value|0x3
comment|/* timer1cf */
define|#
directive|define
name|E5_TSTORM_FCOE_CONN_AG_CTX_FLUSH_Q0_CF_SHIFT
value|0
define|#
directive|define
name|E5_TSTORM_FCOE_CONN_AG_CTX_CF2_MASK
value|0x3
comment|/* timer2cf */
define|#
directive|define
name|E5_TSTORM_FCOE_CONN_AG_CTX_CF2_SHIFT
value|2
define|#
directive|define
name|E5_TSTORM_FCOE_CONN_AG_CTX_TIMER_STOP_ALL_CF_MASK
value|0x3
comment|/* timer_stop_all */
define|#
directive|define
name|E5_TSTORM_FCOE_CONN_AG_CTX_TIMER_STOP_ALL_CF_SHIFT
value|4
define|#
directive|define
name|E5_TSTORM_FCOE_CONN_AG_CTX_CF4_MASK
value|0x3
comment|/* cf4 */
define|#
directive|define
name|E5_TSTORM_FCOE_CONN_AG_CTX_CF4_SHIFT
value|6
name|u8
name|flags2
decl_stmt|;
define|#
directive|define
name|E5_TSTORM_FCOE_CONN_AG_CTX_CF5_MASK
value|0x3
comment|/* cf5 */
define|#
directive|define
name|E5_TSTORM_FCOE_CONN_AG_CTX_CF5_SHIFT
value|0
define|#
directive|define
name|E5_TSTORM_FCOE_CONN_AG_CTX_CF6_MASK
value|0x3
comment|/* cf6 */
define|#
directive|define
name|E5_TSTORM_FCOE_CONN_AG_CTX_CF6_SHIFT
value|2
define|#
directive|define
name|E5_TSTORM_FCOE_CONN_AG_CTX_CF7_MASK
value|0x3
comment|/* cf7 */
define|#
directive|define
name|E5_TSTORM_FCOE_CONN_AG_CTX_CF7_SHIFT
value|4
define|#
directive|define
name|E5_TSTORM_FCOE_CONN_AG_CTX_CF8_MASK
value|0x3
comment|/* cf8 */
define|#
directive|define
name|E5_TSTORM_FCOE_CONN_AG_CTX_CF8_SHIFT
value|6
name|u8
name|flags3
decl_stmt|;
define|#
directive|define
name|E5_TSTORM_FCOE_CONN_AG_CTX_CF9_MASK
value|0x3
comment|/* cf9 */
define|#
directive|define
name|E5_TSTORM_FCOE_CONN_AG_CTX_CF9_SHIFT
value|0
define|#
directive|define
name|E5_TSTORM_FCOE_CONN_AG_CTX_CF10_MASK
value|0x3
comment|/* cf10 */
define|#
directive|define
name|E5_TSTORM_FCOE_CONN_AG_CTX_CF10_SHIFT
value|2
define|#
directive|define
name|E5_TSTORM_FCOE_CONN_AG_CTX_DUMMY_TIMER_CF_EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E5_TSTORM_FCOE_CONN_AG_CTX_DUMMY_TIMER_CF_EN_SHIFT
value|4
define|#
directive|define
name|E5_TSTORM_FCOE_CONN_AG_CTX_FLUSH_Q0_CF_EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E5_TSTORM_FCOE_CONN_AG_CTX_FLUSH_Q0_CF_EN_SHIFT
value|5
define|#
directive|define
name|E5_TSTORM_FCOE_CONN_AG_CTX_CF2EN_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E5_TSTORM_FCOE_CONN_AG_CTX_CF2EN_SHIFT
value|6
define|#
directive|define
name|E5_TSTORM_FCOE_CONN_AG_CTX_TIMER_STOP_ALL_CF_EN_MASK
value|0x1
comment|/* cf3en */
define|#
directive|define
name|E5_TSTORM_FCOE_CONN_AG_CTX_TIMER_STOP_ALL_CF_EN_SHIFT
value|7
name|u8
name|flags4
decl_stmt|;
define|#
directive|define
name|E5_TSTORM_FCOE_CONN_AG_CTX_CF4EN_MASK
value|0x1
comment|/* cf4en */
define|#
directive|define
name|E5_TSTORM_FCOE_CONN_AG_CTX_CF4EN_SHIFT
value|0
define|#
directive|define
name|E5_TSTORM_FCOE_CONN_AG_CTX_CF5EN_MASK
value|0x1
comment|/* cf5en */
define|#
directive|define
name|E5_TSTORM_FCOE_CONN_AG_CTX_CF5EN_SHIFT
value|1
define|#
directive|define
name|E5_TSTORM_FCOE_CONN_AG_CTX_CF6EN_MASK
value|0x1
comment|/* cf6en */
define|#
directive|define
name|E5_TSTORM_FCOE_CONN_AG_CTX_CF6EN_SHIFT
value|2
define|#
directive|define
name|E5_TSTORM_FCOE_CONN_AG_CTX_CF7EN_MASK
value|0x1
comment|/* cf7en */
define|#
directive|define
name|E5_TSTORM_FCOE_CONN_AG_CTX_CF7EN_SHIFT
value|3
define|#
directive|define
name|E5_TSTORM_FCOE_CONN_AG_CTX_CF8EN_MASK
value|0x1
comment|/* cf8en */
define|#
directive|define
name|E5_TSTORM_FCOE_CONN_AG_CTX_CF8EN_SHIFT
value|4
define|#
directive|define
name|E5_TSTORM_FCOE_CONN_AG_CTX_CF9EN_MASK
value|0x1
comment|/* cf9en */
define|#
directive|define
name|E5_TSTORM_FCOE_CONN_AG_CTX_CF9EN_SHIFT
value|5
define|#
directive|define
name|E5_TSTORM_FCOE_CONN_AG_CTX_CF10EN_MASK
value|0x1
comment|/* cf10en */
define|#
directive|define
name|E5_TSTORM_FCOE_CONN_AG_CTX_CF10EN_SHIFT
value|6
define|#
directive|define
name|E5_TSTORM_FCOE_CONN_AG_CTX_RULE0EN_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E5_TSTORM_FCOE_CONN_AG_CTX_RULE0EN_SHIFT
value|7
name|u8
name|flags5
decl_stmt|;
define|#
directive|define
name|E5_TSTORM_FCOE_CONN_AG_CTX_RULE1EN_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E5_TSTORM_FCOE_CONN_AG_CTX_RULE1EN_SHIFT
value|0
define|#
directive|define
name|E5_TSTORM_FCOE_CONN_AG_CTX_RULE2EN_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E5_TSTORM_FCOE_CONN_AG_CTX_RULE2EN_SHIFT
value|1
define|#
directive|define
name|E5_TSTORM_FCOE_CONN_AG_CTX_RULE3EN_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E5_TSTORM_FCOE_CONN_AG_CTX_RULE3EN_SHIFT
value|2
define|#
directive|define
name|E5_TSTORM_FCOE_CONN_AG_CTX_RULE4EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E5_TSTORM_FCOE_CONN_AG_CTX_RULE4EN_SHIFT
value|3
define|#
directive|define
name|E5_TSTORM_FCOE_CONN_AG_CTX_RULE5EN_MASK
value|0x1
comment|/* rule5en */
define|#
directive|define
name|E5_TSTORM_FCOE_CONN_AG_CTX_RULE5EN_SHIFT
value|4
define|#
directive|define
name|E5_TSTORM_FCOE_CONN_AG_CTX_RULE6EN_MASK
value|0x1
comment|/* rule6en */
define|#
directive|define
name|E5_TSTORM_FCOE_CONN_AG_CTX_RULE6EN_SHIFT
value|5
define|#
directive|define
name|E5_TSTORM_FCOE_CONN_AG_CTX_RULE7EN_MASK
value|0x1
comment|/* rule7en */
define|#
directive|define
name|E5_TSTORM_FCOE_CONN_AG_CTX_RULE7EN_SHIFT
value|6
define|#
directive|define
name|E5_TSTORM_FCOE_CONN_AG_CTX_RULE8EN_MASK
value|0x1
comment|/* rule8en */
define|#
directive|define
name|E5_TSTORM_FCOE_CONN_AG_CTX_RULE8EN_SHIFT
value|7
name|u8
name|flags6
decl_stmt|;
define|#
directive|define
name|E5_TSTORM_FCOE_CONN_AG_CTX_E4_RESERVED1_MASK
value|0x1
comment|/* bit6 */
define|#
directive|define
name|E5_TSTORM_FCOE_CONN_AG_CTX_E4_RESERVED1_SHIFT
value|0
define|#
directive|define
name|E5_TSTORM_FCOE_CONN_AG_CTX_E4_RESERVED2_MASK
value|0x1
comment|/* bit7 */
define|#
directive|define
name|E5_TSTORM_FCOE_CONN_AG_CTX_E4_RESERVED2_SHIFT
value|1
define|#
directive|define
name|E5_TSTORM_FCOE_CONN_AG_CTX_E4_RESERVED3_MASK
value|0x1
comment|/* bit8 */
define|#
directive|define
name|E5_TSTORM_FCOE_CONN_AG_CTX_E4_RESERVED3_SHIFT
value|2
define|#
directive|define
name|E5_TSTORM_FCOE_CONN_AG_CTX_E4_RESERVED4_MASK
value|0x3
comment|/* cf11 */
define|#
directive|define
name|E5_TSTORM_FCOE_CONN_AG_CTX_E4_RESERVED4_SHIFT
value|3
define|#
directive|define
name|E5_TSTORM_FCOE_CONN_AG_CTX_E4_RESERVED5_MASK
value|0x1
comment|/* cf11en */
define|#
directive|define
name|E5_TSTORM_FCOE_CONN_AG_CTX_E4_RESERVED5_SHIFT
value|5
define|#
directive|define
name|E5_TSTORM_FCOE_CONN_AG_CTX_E4_RESERVED6_MASK
value|0x1
comment|/* rule9en */
define|#
directive|define
name|E5_TSTORM_FCOE_CONN_AG_CTX_E4_RESERVED6_SHIFT
value|6
define|#
directive|define
name|E5_TSTORM_FCOE_CONN_AG_CTX_E4_RESERVED7_MASK
value|0x1
comment|/* rule10en */
define|#
directive|define
name|E5_TSTORM_FCOE_CONN_AG_CTX_E4_RESERVED7_SHIFT
value|7
name|u8
name|byte2
comment|/* byte2 */
decl_stmt|;
name|__le16
name|word0
comment|/* word0 */
decl_stmt|;
name|__le32
name|reg0
comment|/* reg0 */
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|e5_ustorm_fcoe_conn_ag_ctx
block|{
name|u8
name|byte0
comment|/* cdu_validation */
decl_stmt|;
name|u8
name|byte1
comment|/* state_and_core_id */
decl_stmt|;
name|u8
name|flags0
decl_stmt|;
define|#
directive|define
name|E5_USTORM_FCOE_CONN_AG_CTX_BIT0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E5_USTORM_FCOE_CONN_AG_CTX_BIT0_SHIFT
value|0
define|#
directive|define
name|E5_USTORM_FCOE_CONN_AG_CTX_BIT1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E5_USTORM_FCOE_CONN_AG_CTX_BIT1_SHIFT
value|1
define|#
directive|define
name|E5_USTORM_FCOE_CONN_AG_CTX_CF0_MASK
value|0x3
comment|/* timer0cf */
define|#
directive|define
name|E5_USTORM_FCOE_CONN_AG_CTX_CF0_SHIFT
value|2
define|#
directive|define
name|E5_USTORM_FCOE_CONN_AG_CTX_CF1_MASK
value|0x3
comment|/* timer1cf */
define|#
directive|define
name|E5_USTORM_FCOE_CONN_AG_CTX_CF1_SHIFT
value|4
define|#
directive|define
name|E5_USTORM_FCOE_CONN_AG_CTX_CF2_MASK
value|0x3
comment|/* timer2cf */
define|#
directive|define
name|E5_USTORM_FCOE_CONN_AG_CTX_CF2_SHIFT
value|6
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E5_USTORM_FCOE_CONN_AG_CTX_CF3_MASK
value|0x3
comment|/* timer_stop_all */
define|#
directive|define
name|E5_USTORM_FCOE_CONN_AG_CTX_CF3_SHIFT
value|0
define|#
directive|define
name|E5_USTORM_FCOE_CONN_AG_CTX_CF4_MASK
value|0x3
comment|/* cf4 */
define|#
directive|define
name|E5_USTORM_FCOE_CONN_AG_CTX_CF4_SHIFT
value|2
define|#
directive|define
name|E5_USTORM_FCOE_CONN_AG_CTX_CF5_MASK
value|0x3
comment|/* cf5 */
define|#
directive|define
name|E5_USTORM_FCOE_CONN_AG_CTX_CF5_SHIFT
value|4
define|#
directive|define
name|E5_USTORM_FCOE_CONN_AG_CTX_CF6_MASK
value|0x3
comment|/* cf6 */
define|#
directive|define
name|E5_USTORM_FCOE_CONN_AG_CTX_CF6_SHIFT
value|6
name|u8
name|flags2
decl_stmt|;
define|#
directive|define
name|E5_USTORM_FCOE_CONN_AG_CTX_CF0EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E5_USTORM_FCOE_CONN_AG_CTX_CF0EN_SHIFT
value|0
define|#
directive|define
name|E5_USTORM_FCOE_CONN_AG_CTX_CF1EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E5_USTORM_FCOE_CONN_AG_CTX_CF1EN_SHIFT
value|1
define|#
directive|define
name|E5_USTORM_FCOE_CONN_AG_CTX_CF2EN_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E5_USTORM_FCOE_CONN_AG_CTX_CF2EN_SHIFT
value|2
define|#
directive|define
name|E5_USTORM_FCOE_CONN_AG_CTX_CF3EN_MASK
value|0x1
comment|/* cf3en */
define|#
directive|define
name|E5_USTORM_FCOE_CONN_AG_CTX_CF3EN_SHIFT
value|3
define|#
directive|define
name|E5_USTORM_FCOE_CONN_AG_CTX_CF4EN_MASK
value|0x1
comment|/* cf4en */
define|#
directive|define
name|E5_USTORM_FCOE_CONN_AG_CTX_CF4EN_SHIFT
value|4
define|#
directive|define
name|E5_USTORM_FCOE_CONN_AG_CTX_CF5EN_MASK
value|0x1
comment|/* cf5en */
define|#
directive|define
name|E5_USTORM_FCOE_CONN_AG_CTX_CF5EN_SHIFT
value|5
define|#
directive|define
name|E5_USTORM_FCOE_CONN_AG_CTX_CF6EN_MASK
value|0x1
comment|/* cf6en */
define|#
directive|define
name|E5_USTORM_FCOE_CONN_AG_CTX_CF6EN_SHIFT
value|6
define|#
directive|define
name|E5_USTORM_FCOE_CONN_AG_CTX_RULE0EN_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E5_USTORM_FCOE_CONN_AG_CTX_RULE0EN_SHIFT
value|7
name|u8
name|flags3
decl_stmt|;
define|#
directive|define
name|E5_USTORM_FCOE_CONN_AG_CTX_RULE1EN_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E5_USTORM_FCOE_CONN_AG_CTX_RULE1EN_SHIFT
value|0
define|#
directive|define
name|E5_USTORM_FCOE_CONN_AG_CTX_RULE2EN_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E5_USTORM_FCOE_CONN_AG_CTX_RULE2EN_SHIFT
value|1
define|#
directive|define
name|E5_USTORM_FCOE_CONN_AG_CTX_RULE3EN_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E5_USTORM_FCOE_CONN_AG_CTX_RULE3EN_SHIFT
value|2
define|#
directive|define
name|E5_USTORM_FCOE_CONN_AG_CTX_RULE4EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E5_USTORM_FCOE_CONN_AG_CTX_RULE4EN_SHIFT
value|3
define|#
directive|define
name|E5_USTORM_FCOE_CONN_AG_CTX_RULE5EN_MASK
value|0x1
comment|/* rule5en */
define|#
directive|define
name|E5_USTORM_FCOE_CONN_AG_CTX_RULE5EN_SHIFT
value|4
define|#
directive|define
name|E5_USTORM_FCOE_CONN_AG_CTX_RULE6EN_MASK
value|0x1
comment|/* rule6en */
define|#
directive|define
name|E5_USTORM_FCOE_CONN_AG_CTX_RULE6EN_SHIFT
value|5
define|#
directive|define
name|E5_USTORM_FCOE_CONN_AG_CTX_RULE7EN_MASK
value|0x1
comment|/* rule7en */
define|#
directive|define
name|E5_USTORM_FCOE_CONN_AG_CTX_RULE7EN_SHIFT
value|6
define|#
directive|define
name|E5_USTORM_FCOE_CONN_AG_CTX_RULE8EN_MASK
value|0x1
comment|/* rule8en */
define|#
directive|define
name|E5_USTORM_FCOE_CONN_AG_CTX_RULE8EN_SHIFT
value|7
name|u8
name|flags4
decl_stmt|;
define|#
directive|define
name|E5_USTORM_FCOE_CONN_AG_CTX_E4_RESERVED1_MASK
value|0x1
comment|/* bit2 */
define|#
directive|define
name|E5_USTORM_FCOE_CONN_AG_CTX_E4_RESERVED1_SHIFT
value|0
define|#
directive|define
name|E5_USTORM_FCOE_CONN_AG_CTX_E4_RESERVED2_MASK
value|0x1
comment|/* bit3 */
define|#
directive|define
name|E5_USTORM_FCOE_CONN_AG_CTX_E4_RESERVED2_SHIFT
value|1
define|#
directive|define
name|E5_USTORM_FCOE_CONN_AG_CTX_E4_RESERVED3_MASK
value|0x3
comment|/* cf7 */
define|#
directive|define
name|E5_USTORM_FCOE_CONN_AG_CTX_E4_RESERVED3_SHIFT
value|2
define|#
directive|define
name|E5_USTORM_FCOE_CONN_AG_CTX_E4_RESERVED4_MASK
value|0x3
comment|/* cf8 */
define|#
directive|define
name|E5_USTORM_FCOE_CONN_AG_CTX_E4_RESERVED4_SHIFT
value|4
define|#
directive|define
name|E5_USTORM_FCOE_CONN_AG_CTX_E4_RESERVED5_MASK
value|0x1
comment|/* cf7en */
define|#
directive|define
name|E5_USTORM_FCOE_CONN_AG_CTX_E4_RESERVED5_SHIFT
value|6
define|#
directive|define
name|E5_USTORM_FCOE_CONN_AG_CTX_E4_RESERVED6_MASK
value|0x1
comment|/* cf8en */
define|#
directive|define
name|E5_USTORM_FCOE_CONN_AG_CTX_E4_RESERVED6_SHIFT
value|7
name|u8
name|byte2
comment|/* byte2 */
decl_stmt|;
name|__le16
name|word0
comment|/* conn_dpi */
decl_stmt|;
name|__le16
name|word1
comment|/* word1 */
decl_stmt|;
name|__le32
name|reg0
comment|/* reg0 */
decl_stmt|;
name|__le32
name|reg1
comment|/* reg1 */
decl_stmt|;
name|__le32
name|reg2
comment|/* reg2 */
decl_stmt|;
name|__le32
name|reg3
comment|/* reg3 */
decl_stmt|;
name|__le16
name|word2
comment|/* word2 */
decl_stmt|;
name|__le16
name|word3
comment|/* word3 */
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|e5_mstorm_fcoe_conn_ag_ctx
block|{
name|u8
name|byte0
comment|/* cdu_validation */
decl_stmt|;
name|u8
name|byte1
comment|/* state_and_core_id */
decl_stmt|;
name|u8
name|flags0
decl_stmt|;
define|#
directive|define
name|E5_MSTORM_FCOE_CONN_AG_CTX_BIT0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E5_MSTORM_FCOE_CONN_AG_CTX_BIT0_SHIFT
value|0
define|#
directive|define
name|E5_MSTORM_FCOE_CONN_AG_CTX_BIT1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E5_MSTORM_FCOE_CONN_AG_CTX_BIT1_SHIFT
value|1
define|#
directive|define
name|E5_MSTORM_FCOE_CONN_AG_CTX_CF0_MASK
value|0x3
comment|/* cf0 */
define|#
directive|define
name|E5_MSTORM_FCOE_CONN_AG_CTX_CF0_SHIFT
value|2
define|#
directive|define
name|E5_MSTORM_FCOE_CONN_AG_CTX_CF1_MASK
value|0x3
comment|/* cf1 */
define|#
directive|define
name|E5_MSTORM_FCOE_CONN_AG_CTX_CF1_SHIFT
value|4
define|#
directive|define
name|E5_MSTORM_FCOE_CONN_AG_CTX_CF2_MASK
value|0x3
comment|/* cf2 */
define|#
directive|define
name|E5_MSTORM_FCOE_CONN_AG_CTX_CF2_SHIFT
value|6
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E5_MSTORM_FCOE_CONN_AG_CTX_CF0EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E5_MSTORM_FCOE_CONN_AG_CTX_CF0EN_SHIFT
value|0
define|#
directive|define
name|E5_MSTORM_FCOE_CONN_AG_CTX_CF1EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E5_MSTORM_FCOE_CONN_AG_CTX_CF1EN_SHIFT
value|1
define|#
directive|define
name|E5_MSTORM_FCOE_CONN_AG_CTX_CF2EN_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E5_MSTORM_FCOE_CONN_AG_CTX_CF2EN_SHIFT
value|2
define|#
directive|define
name|E5_MSTORM_FCOE_CONN_AG_CTX_RULE0EN_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E5_MSTORM_FCOE_CONN_AG_CTX_RULE0EN_SHIFT
value|3
define|#
directive|define
name|E5_MSTORM_FCOE_CONN_AG_CTX_RULE1EN_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E5_MSTORM_FCOE_CONN_AG_CTX_RULE1EN_SHIFT
value|4
define|#
directive|define
name|E5_MSTORM_FCOE_CONN_AG_CTX_RULE2EN_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E5_MSTORM_FCOE_CONN_AG_CTX_RULE2EN_SHIFT
value|5
define|#
directive|define
name|E5_MSTORM_FCOE_CONN_AG_CTX_RULE3EN_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E5_MSTORM_FCOE_CONN_AG_CTX_RULE3EN_SHIFT
value|6
define|#
directive|define
name|E5_MSTORM_FCOE_CONN_AG_CTX_RULE4EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E5_MSTORM_FCOE_CONN_AG_CTX_RULE4EN_SHIFT
value|7
name|__le16
name|word0
comment|/* word0 */
decl_stmt|;
name|__le16
name|word1
comment|/* word1 */
decl_stmt|;
name|__le32
name|reg0
comment|/* reg0 */
decl_stmt|;
name|__le32
name|reg1
comment|/* reg1 */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * fcoe connection context  */
end_comment

begin_struct
struct|struct
name|e5_fcoe_conn_context
block|{
name|struct
name|ystorm_fcoe_conn_st_ctx
name|ystorm_st_context
comment|/* ystorm storm context */
decl_stmt|;
name|struct
name|pstorm_fcoe_conn_st_ctx
name|pstorm_st_context
comment|/* pstorm storm context */
decl_stmt|;
name|struct
name|regpair
name|pstorm_st_padding
index|[
literal|2
index|]
comment|/* padding */
decl_stmt|;
name|struct
name|xstorm_fcoe_conn_st_ctx
name|xstorm_st_context
comment|/* xstorm storm context */
decl_stmt|;
name|struct
name|e5_xstorm_fcoe_conn_ag_ctx
name|xstorm_ag_context
comment|/* xstorm aggregative context */
decl_stmt|;
name|struct
name|regpair
name|xstorm_ag_padding
index|[
literal|6
index|]
comment|/* padding */
decl_stmt|;
name|struct
name|ustorm_fcoe_conn_st_ctx
name|ustorm_st_context
comment|/* ustorm storm context */
decl_stmt|;
name|struct
name|regpair
name|ustorm_st_padding
index|[
literal|2
index|]
comment|/* padding */
decl_stmt|;
name|struct
name|e5_tstorm_fcoe_conn_ag_ctx
name|tstorm_ag_context
comment|/* tstorm aggregative context */
decl_stmt|;
name|struct
name|regpair
name|tstorm_ag_padding
index|[
literal|2
index|]
comment|/* padding */
decl_stmt|;
name|struct
name|timers_context
name|timer_context
comment|/* timer context */
decl_stmt|;
name|struct
name|e5_ustorm_fcoe_conn_ag_ctx
name|ustorm_ag_context
comment|/* ustorm aggregative context */
decl_stmt|;
name|struct
name|tstorm_fcoe_conn_st_ctx
name|tstorm_st_context
comment|/* tstorm storm context */
decl_stmt|;
name|struct
name|e5_mstorm_fcoe_conn_ag_ctx
name|mstorm_ag_context
comment|/* mstorm aggregative context */
decl_stmt|;
name|struct
name|mstorm_fcoe_conn_st_ctx
name|mstorm_st_context
comment|/* mstorm storm context */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * FCoE connection offload params passed by driver to FW in FCoE offload ramrod   */
end_comment

begin_struct
struct|struct
name|fcoe_conn_offload_ramrod_params
block|{
name|struct
name|fcoe_conn_offload_ramrod_data
name|offload_ramrod_data
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * FCoE connection terminate params passed by driver to FW in FCoE terminate conn ramrod   */
end_comment

begin_struct
struct|struct
name|fcoe_conn_terminate_ramrod_params
block|{
name|struct
name|fcoe_conn_terminate_ramrod_data
name|terminate_ramrod_data
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * FCoE event type  */
end_comment

begin_enum
enum|enum
name|fcoe_event_type
block|{
name|FCOE_EVENT_INIT_FUNC
comment|/* Slowpath completion on INIT_FUNC ramrod */
block|,
name|FCOE_EVENT_DESTROY_FUNC
comment|/* Slowpath completion on DESTROY_FUNC ramrod */
block|,
name|FCOE_EVENT_STAT_FUNC
comment|/* Slowpath completion on STAT_FUNC ramrod */
block|,
name|FCOE_EVENT_OFFLOAD_CONN
comment|/* Slowpath completion on OFFLOAD_CONN ramrod */
block|,
name|FCOE_EVENT_TERMINATE_CONN
comment|/* Slowpath completion on TERMINATE_CONN ramrod */
block|,
name|FCOE_EVENT_ERROR
comment|/* Error event */
block|,
name|MAX_FCOE_EVENT_TYPE
block|}
enum|;
end_enum

begin_comment
comment|/*  * FCoE init params passed by driver to FW in FCoE init ramrod   */
end_comment

begin_struct
struct|struct
name|fcoe_init_ramrod_params
block|{
name|struct
name|fcoe_init_func_ramrod_data
name|init_ramrod_data
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * FCoE ramrod Command IDs   */
end_comment

begin_enum
enum|enum
name|fcoe_ramrod_cmd_id
block|{
name|FCOE_RAMROD_CMD_ID_INIT_FUNC
comment|/* FCoE function init ramrod */
block|,
name|FCOE_RAMROD_CMD_ID_DESTROY_FUNC
comment|/* FCoE function destroy ramrod */
block|,
name|FCOE_RAMROD_CMD_ID_STAT_FUNC
comment|/* FCoE statistics ramrod */
block|,
name|FCOE_RAMROD_CMD_ID_OFFLOAD_CONN
comment|/* FCoE connection offload ramrod */
block|,
name|FCOE_RAMROD_CMD_ID_TERMINATE_CONN
comment|/* FCoE connection offload ramrod. Command ID known only to FW and VBD */
block|,
name|MAX_FCOE_RAMROD_CMD_ID
block|}
enum|;
end_enum

begin_comment
comment|/*  * FCoE statistics params buffer passed by driver to FW in FCoE statistics ramrod   */
end_comment

begin_struct
struct|struct
name|fcoe_stat_ramrod_params
block|{
name|struct
name|fcoe_stat_ramrod_data
name|stat_ramrod_data
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|e4_ystorm_fcoe_conn_ag_ctx
block|{
name|u8
name|byte0
comment|/* cdu_validation */
decl_stmt|;
name|u8
name|byte1
comment|/* state */
decl_stmt|;
name|u8
name|flags0
decl_stmt|;
define|#
directive|define
name|E4_YSTORM_FCOE_CONN_AG_CTX_BIT0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E4_YSTORM_FCOE_CONN_AG_CTX_BIT0_SHIFT
value|0
define|#
directive|define
name|E4_YSTORM_FCOE_CONN_AG_CTX_BIT1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E4_YSTORM_FCOE_CONN_AG_CTX_BIT1_SHIFT
value|1
define|#
directive|define
name|E4_YSTORM_FCOE_CONN_AG_CTX_CF0_MASK
value|0x3
comment|/* cf0 */
define|#
directive|define
name|E4_YSTORM_FCOE_CONN_AG_CTX_CF0_SHIFT
value|2
define|#
directive|define
name|E4_YSTORM_FCOE_CONN_AG_CTX_CF1_MASK
value|0x3
comment|/* cf1 */
define|#
directive|define
name|E4_YSTORM_FCOE_CONN_AG_CTX_CF1_SHIFT
value|4
define|#
directive|define
name|E4_YSTORM_FCOE_CONN_AG_CTX_CF2_MASK
value|0x3
comment|/* cf2 */
define|#
directive|define
name|E4_YSTORM_FCOE_CONN_AG_CTX_CF2_SHIFT
value|6
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E4_YSTORM_FCOE_CONN_AG_CTX_CF0EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E4_YSTORM_FCOE_CONN_AG_CTX_CF0EN_SHIFT
value|0
define|#
directive|define
name|E4_YSTORM_FCOE_CONN_AG_CTX_CF1EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E4_YSTORM_FCOE_CONN_AG_CTX_CF1EN_SHIFT
value|1
define|#
directive|define
name|E4_YSTORM_FCOE_CONN_AG_CTX_CF2EN_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E4_YSTORM_FCOE_CONN_AG_CTX_CF2EN_SHIFT
value|2
define|#
directive|define
name|E4_YSTORM_FCOE_CONN_AG_CTX_RULE0EN_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E4_YSTORM_FCOE_CONN_AG_CTX_RULE0EN_SHIFT
value|3
define|#
directive|define
name|E4_YSTORM_FCOE_CONN_AG_CTX_RULE1EN_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E4_YSTORM_FCOE_CONN_AG_CTX_RULE1EN_SHIFT
value|4
define|#
directive|define
name|E4_YSTORM_FCOE_CONN_AG_CTX_RULE2EN_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E4_YSTORM_FCOE_CONN_AG_CTX_RULE2EN_SHIFT
value|5
define|#
directive|define
name|E4_YSTORM_FCOE_CONN_AG_CTX_RULE3EN_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E4_YSTORM_FCOE_CONN_AG_CTX_RULE3EN_SHIFT
value|6
define|#
directive|define
name|E4_YSTORM_FCOE_CONN_AG_CTX_RULE4EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E4_YSTORM_FCOE_CONN_AG_CTX_RULE4EN_SHIFT
value|7
name|u8
name|byte2
comment|/* byte2 */
decl_stmt|;
name|u8
name|byte3
comment|/* byte3 */
decl_stmt|;
name|__le16
name|word0
comment|/* word0 */
decl_stmt|;
name|__le32
name|reg0
comment|/* reg0 */
decl_stmt|;
name|__le32
name|reg1
comment|/* reg1 */
decl_stmt|;
name|__le16
name|word1
comment|/* word1 */
decl_stmt|;
name|__le16
name|word2
comment|/* word2 */
decl_stmt|;
name|__le16
name|word3
comment|/* word3 */
decl_stmt|;
name|__le16
name|word4
comment|/* word4 */
decl_stmt|;
name|__le32
name|reg2
comment|/* reg2 */
decl_stmt|;
name|__le32
name|reg3
comment|/* reg3 */
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|e5_ystorm_fcoe_conn_ag_ctx
block|{
name|u8
name|byte0
comment|/* cdu_validation */
decl_stmt|;
name|u8
name|byte1
comment|/* state_and_core_id */
decl_stmt|;
name|u8
name|flags0
decl_stmt|;
define|#
directive|define
name|E5_YSTORM_FCOE_CONN_AG_CTX_BIT0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E5_YSTORM_FCOE_CONN_AG_CTX_BIT0_SHIFT
value|0
define|#
directive|define
name|E5_YSTORM_FCOE_CONN_AG_CTX_BIT1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E5_YSTORM_FCOE_CONN_AG_CTX_BIT1_SHIFT
value|1
define|#
directive|define
name|E5_YSTORM_FCOE_CONN_AG_CTX_CF0_MASK
value|0x3
comment|/* cf0 */
define|#
directive|define
name|E5_YSTORM_FCOE_CONN_AG_CTX_CF0_SHIFT
value|2
define|#
directive|define
name|E5_YSTORM_FCOE_CONN_AG_CTX_CF1_MASK
value|0x3
comment|/* cf1 */
define|#
directive|define
name|E5_YSTORM_FCOE_CONN_AG_CTX_CF1_SHIFT
value|4
define|#
directive|define
name|E5_YSTORM_FCOE_CONN_AG_CTX_CF2_MASK
value|0x3
comment|/* cf2 */
define|#
directive|define
name|E5_YSTORM_FCOE_CONN_AG_CTX_CF2_SHIFT
value|6
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E5_YSTORM_FCOE_CONN_AG_CTX_CF0EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E5_YSTORM_FCOE_CONN_AG_CTX_CF0EN_SHIFT
value|0
define|#
directive|define
name|E5_YSTORM_FCOE_CONN_AG_CTX_CF1EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E5_YSTORM_FCOE_CONN_AG_CTX_CF1EN_SHIFT
value|1
define|#
directive|define
name|E5_YSTORM_FCOE_CONN_AG_CTX_CF2EN_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E5_YSTORM_FCOE_CONN_AG_CTX_CF2EN_SHIFT
value|2
define|#
directive|define
name|E5_YSTORM_FCOE_CONN_AG_CTX_RULE0EN_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E5_YSTORM_FCOE_CONN_AG_CTX_RULE0EN_SHIFT
value|3
define|#
directive|define
name|E5_YSTORM_FCOE_CONN_AG_CTX_RULE1EN_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E5_YSTORM_FCOE_CONN_AG_CTX_RULE1EN_SHIFT
value|4
define|#
directive|define
name|E5_YSTORM_FCOE_CONN_AG_CTX_RULE2EN_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E5_YSTORM_FCOE_CONN_AG_CTX_RULE2EN_SHIFT
value|5
define|#
directive|define
name|E5_YSTORM_FCOE_CONN_AG_CTX_RULE3EN_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E5_YSTORM_FCOE_CONN_AG_CTX_RULE3EN_SHIFT
value|6
define|#
directive|define
name|E5_YSTORM_FCOE_CONN_AG_CTX_RULE4EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E5_YSTORM_FCOE_CONN_AG_CTX_RULE4EN_SHIFT
value|7
name|u8
name|byte2
comment|/* byte2 */
decl_stmt|;
name|u8
name|byte3
comment|/* byte3 */
decl_stmt|;
name|__le16
name|word0
comment|/* word0 */
decl_stmt|;
name|__le32
name|reg0
comment|/* reg0 */
decl_stmt|;
name|__le32
name|reg1
comment|/* reg1 */
decl_stmt|;
name|__le16
name|word1
comment|/* word1 */
decl_stmt|;
name|__le16
name|word2
comment|/* word2 */
decl_stmt|;
name|__le16
name|word3
comment|/* word3 */
decl_stmt|;
name|__le16
name|word4
comment|/* word4 */
decl_stmt|;
name|__le32
name|reg2
comment|/* reg2 */
decl_stmt|;
name|__le32
name|reg3
comment|/* reg3 */
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ECORE_HSI_FCOE__ */
end_comment

end_unit

