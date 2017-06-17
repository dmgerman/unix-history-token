begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2017-2018 Cavium, Inc.   * All rights reserved.  *  *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *  *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *  *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  *  POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__FCOE_COMMON__
end_ifndef

begin_define
define|#
directive|define
name|__FCOE_COMMON__
end_define

begin_comment
comment|/*********************/
end_comment

begin_comment
comment|/* FCOE FW CONSTANTS */
end_comment

begin_comment
comment|/*********************/
end_comment

begin_define
define|#
directive|define
name|FC_ABTS_REPLY_MAX_PAYLOAD_LEN
value|12
end_define

begin_comment
comment|/*  * The fcoe storm task context protection-information of Ystorm  */
end_comment

begin_struct
struct|struct
name|protection_info_ctx
block|{
name|__le16
name|flags
decl_stmt|;
define|#
directive|define
name|PROTECTION_INFO_CTX_HOST_INTERFACE_MASK
value|0x3
comment|/* 0=none, 1=DIF, 2=DIX */
define|#
directive|define
name|PROTECTION_INFO_CTX_HOST_INTERFACE_SHIFT
value|0
define|#
directive|define
name|PROTECTION_INFO_CTX_DIF_TO_PEER_MASK
value|0x1
comment|/* 0=no, 1=yes */
define|#
directive|define
name|PROTECTION_INFO_CTX_DIF_TO_PEER_SHIFT
value|2
define|#
directive|define
name|PROTECTION_INFO_CTX_VALIDATE_DIX_APP_TAG_MASK
value|0x1
comment|/* 0=no, 1=yes */
define|#
directive|define
name|PROTECTION_INFO_CTX_VALIDATE_DIX_APP_TAG_SHIFT
value|3
define|#
directive|define
name|PROTECTION_INFO_CTX_INTERVAL_SIZE_LOG_MASK
value|0xF
comment|/* Protection log interval (9=512 10=1024  11=2048 12=4096 13=8192) */
define|#
directive|define
name|PROTECTION_INFO_CTX_INTERVAL_SIZE_LOG_SHIFT
value|4
define|#
directive|define
name|PROTECTION_INFO_CTX_VALIDATE_DIX_REF_TAG_MASK
value|0x1
comment|/* 0=no, 1=yes */
define|#
directive|define
name|PROTECTION_INFO_CTX_VALIDATE_DIX_REF_TAG_SHIFT
value|8
define|#
directive|define
name|PROTECTION_INFO_CTX_RESERVED0_MASK
value|0x7F
define|#
directive|define
name|PROTECTION_INFO_CTX_RESERVED0_SHIFT
value|9
name|u8
name|dix_block_size
comment|/* Source protection data size */
decl_stmt|;
name|u8
name|dst_size
comment|/* Destination protection data size */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The fcoe storm task context protection-information of Ystorm  */
end_comment

begin_union
union|union
name|protection_info_union_ctx
block|{
name|struct
name|protection_info_ctx
name|info
decl_stmt|;
name|__le32
name|value
comment|/* If and only if this field is not 0 then protection is set */
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/*  * FCP CMD payload  */
end_comment

begin_struct
struct|struct
name|fcoe_fcp_cmd_payload
block|{
name|__le32
name|opaque
index|[
literal|8
index|]
comment|/* The FCP_CMD payload */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * FCP RSP payload  */
end_comment

begin_struct
struct|struct
name|fcoe_fcp_rsp_payload
block|{
name|__le32
name|opaque
index|[
literal|6
index|]
comment|/* The FCP_RSP payload */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * FCP RSP payload  */
end_comment

begin_struct
struct|struct
name|fcp_rsp_payload_padded
block|{
name|struct
name|fcoe_fcp_rsp_payload
name|rsp_payload
comment|/* The FCP_RSP payload */
decl_stmt|;
name|__le32
name|reserved
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * FCP RSP payload  */
end_comment

begin_struct
struct|struct
name|fcoe_fcp_xfer_payload
block|{
name|__le32
name|opaque
index|[
literal|3
index|]
comment|/* The FCP_XFER payload */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * FCP RSP payload  */
end_comment

begin_struct
struct|struct
name|fcp_xfer_payload_padded
block|{
name|struct
name|fcoe_fcp_xfer_payload
name|xfer_payload
comment|/* The FCP_XFER payload */
decl_stmt|;
name|__le32
name|reserved
index|[
literal|5
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Task params  */
end_comment

begin_struct
struct|struct
name|fcoe_tx_data_params
block|{
name|__le32
name|data_offset
comment|/* Data offset */
decl_stmt|;
name|__le32
name|offset_in_io
comment|/* For sequence cleanup */
decl_stmt|;
name|u8
name|flags
decl_stmt|;
define|#
directive|define
name|FCOE_TX_DATA_PARAMS_OFFSET_IN_IO_VALID_MASK
value|0x1
comment|/* Should we send offset in IO */
define|#
directive|define
name|FCOE_TX_DATA_PARAMS_OFFSET_IN_IO_VALID_SHIFT
value|0
define|#
directive|define
name|FCOE_TX_DATA_PARAMS_DROP_DATA_MASK
value|0x1
comment|/* Should the PBF drop this data */
define|#
directive|define
name|FCOE_TX_DATA_PARAMS_DROP_DATA_SHIFT
value|1
define|#
directive|define
name|FCOE_TX_DATA_PARAMS_AFTER_SEQ_REC_MASK
value|0x1
comment|/* Indication if the task after seqqence recovery flow */
define|#
directive|define
name|FCOE_TX_DATA_PARAMS_AFTER_SEQ_REC_SHIFT
value|2
define|#
directive|define
name|FCOE_TX_DATA_PARAMS_RESERVED0_MASK
value|0x1F
define|#
directive|define
name|FCOE_TX_DATA_PARAMS_RESERVED0_SHIFT
value|3
name|u8
name|dif_residual
comment|/* Residual from protection interval */
decl_stmt|;
name|__le16
name|seq_cnt
comment|/* Sequence counter */
decl_stmt|;
name|__le16
name|single_sge_saved_offset
comment|/* Saved SGE length for single SGE case */
decl_stmt|;
name|__le16
name|next_dif_offset
comment|/* Tracking next DIF offset in FC payload */
decl_stmt|;
name|__le16
name|seq_id
comment|/* Sequence ID (Set [saved] upon seq_cnt==0 (start of sequence) and used throughout sequence) */
decl_stmt|;
name|__le16
name|reserved3
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Middle path parameters: FC header fields provided by the driver  */
end_comment

begin_struct
struct|struct
name|fcoe_tx_mid_path_params
block|{
name|__le32
name|parameter
decl_stmt|;
name|u8
name|r_ctl
decl_stmt|;
name|u8
name|type
decl_stmt|;
name|u8
name|cs_ctl
decl_stmt|;
name|u8
name|df_ctl
decl_stmt|;
name|__le16
name|rx_id
decl_stmt|;
name|__le16
name|ox_id
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Task params  */
end_comment

begin_struct
struct|struct
name|fcoe_tx_params
block|{
name|struct
name|fcoe_tx_data_params
name|data
comment|/* Data offset */
decl_stmt|;
name|struct
name|fcoe_tx_mid_path_params
name|mid_path
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Union of FCP CMD payload \ TX params \ ABTS \ Cleanup  */
end_comment

begin_union
union|union
name|fcoe_tx_info_union_ctx
block|{
name|struct
name|fcoe_fcp_cmd_payload
name|fcp_cmd_payload
comment|/* FCP CMD payload */
decl_stmt|;
name|struct
name|fcp_rsp_payload_padded
name|fcp_rsp_payload
comment|/* FCP RSP payload */
decl_stmt|;
name|struct
name|fcp_xfer_payload_padded
name|fcp_xfer_payload
comment|/* FCP XFER payload */
decl_stmt|;
name|struct
name|fcoe_tx_params
name|tx_params
comment|/* Task TX params */
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/*  * Data sgl  */
end_comment

begin_struct
struct|struct
name|fcoe_slow_sgl_ctx
block|{
name|struct
name|regpair
name|base_sgl_addr
comment|/* Address of first SGE in SGL */
decl_stmt|;
name|__le16
name|curr_sge_off
comment|/* Offset in current BD (in bytes) */
decl_stmt|;
name|__le16
name|remainder_num_sges
comment|/* Number of BDs */
decl_stmt|;
name|__le16
name|curr_sgl_index
comment|/* Index of current SGE */
decl_stmt|;
name|__le16
name|reserved
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Union of DIX SGL \ cached DIX sges  */
end_comment

begin_union
union|union
name|fcoe_dix_desc_ctx
block|{
name|struct
name|fcoe_slow_sgl_ctx
name|dix_sgl
comment|/* DIX slow-SGL data base */
decl_stmt|;
name|struct
name|scsi_sge
name|cached_dix_sge
comment|/* Cached DIX sge */
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/*  * The fcoe storm task context of Ystorm  */
end_comment

begin_struct
struct|struct
name|ystorm_fcoe_task_st_ctx
block|{
name|u8
name|task_type
comment|/* Task type. use enum fcoe_task_type  */
decl_stmt|;
name|u8
name|sgl_mode
decl_stmt|;
define|#
directive|define
name|YSTORM_FCOE_TASK_ST_CTX_TX_SGL_MODE_MASK
value|0x1
comment|/* use enum scsi_sgl_mode (use enum scsi_sgl_mode) */
define|#
directive|define
name|YSTORM_FCOE_TASK_ST_CTX_TX_SGL_MODE_SHIFT
value|0
define|#
directive|define
name|YSTORM_FCOE_TASK_ST_CTX_RSRV_MASK
value|0x7F
define|#
directive|define
name|YSTORM_FCOE_TASK_ST_CTX_RSRV_SHIFT
value|1
name|u8
name|cached_dix_sge
comment|/* Dix sge is cached on task context */
decl_stmt|;
name|u8
name|expect_first_xfer
comment|/* Will let Ystorm know when it should initialize fcp_cmd_payload_params_union.params */
decl_stmt|;
name|__le32
name|num_pbf_zero_write
comment|/* The amount of bytes that PBF should dummy write - Relevant for protection only. */
decl_stmt|;
name|union
name|protection_info_union_ctx
name|protection_info_union
comment|/* Protection information */
decl_stmt|;
name|__le32
name|data_2_trns_rem
comment|/* Entire SGL-buffer remainder */
decl_stmt|;
name|struct
name|scsi_sgl_params
name|sgl_params
decl_stmt|;
name|u8
name|reserved1
index|[
literal|12
index|]
decl_stmt|;
name|union
name|fcoe_tx_info_union_ctx
name|tx_info_union
comment|/* Union of FCP CMD payload / TX params / ABTS / Cleanup */
decl_stmt|;
name|union
name|fcoe_dix_desc_ctx
name|dix_desc
comment|/* Union of DIX SGL / cached DIX sges */
decl_stmt|;
name|struct
name|scsi_cached_sges
name|data_desc
comment|/* Data cached SGEs */
decl_stmt|;
name|__le16
name|ox_id
comment|/* OX-ID. Used in Target mode only */
decl_stmt|;
name|__le16
name|rx_id
comment|/* RX-ID. Used in Target mode only */
decl_stmt|;
name|__le32
name|task_rety_identifier
comment|/* Parameter field of the FCP CMDs FC header */
decl_stmt|;
name|u8
name|reserved2
index|[
literal|8
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|e4_ystorm_fcoe_task_ag_ctx
block|{
name|u8
name|byte0
comment|/* cdu_validation */
decl_stmt|;
name|u8
name|byte1
comment|/* state */
decl_stmt|;
name|__le16
name|word0
comment|/* icid */
decl_stmt|;
name|u8
name|flags0
decl_stmt|;
define|#
directive|define
name|E4_YSTORM_FCOE_TASK_AG_CTX_NIBBLE0_MASK
value|0xF
comment|/* connection_type */
define|#
directive|define
name|E4_YSTORM_FCOE_TASK_AG_CTX_NIBBLE0_SHIFT
value|0
define|#
directive|define
name|E4_YSTORM_FCOE_TASK_AG_CTX_BIT0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E4_YSTORM_FCOE_TASK_AG_CTX_BIT0_SHIFT
value|4
define|#
directive|define
name|E4_YSTORM_FCOE_TASK_AG_CTX_BIT1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E4_YSTORM_FCOE_TASK_AG_CTX_BIT1_SHIFT
value|5
define|#
directive|define
name|E4_YSTORM_FCOE_TASK_AG_CTX_BIT2_MASK
value|0x1
comment|/* bit2 */
define|#
directive|define
name|E4_YSTORM_FCOE_TASK_AG_CTX_BIT2_SHIFT
value|6
define|#
directive|define
name|E4_YSTORM_FCOE_TASK_AG_CTX_BIT3_MASK
value|0x1
comment|/* bit3 */
define|#
directive|define
name|E4_YSTORM_FCOE_TASK_AG_CTX_BIT3_SHIFT
value|7
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E4_YSTORM_FCOE_TASK_AG_CTX_CF0_MASK
value|0x3
comment|/* cf0 */
define|#
directive|define
name|E4_YSTORM_FCOE_TASK_AG_CTX_CF0_SHIFT
value|0
define|#
directive|define
name|E4_YSTORM_FCOE_TASK_AG_CTX_CF1_MASK
value|0x3
comment|/* cf1 */
define|#
directive|define
name|E4_YSTORM_FCOE_TASK_AG_CTX_CF1_SHIFT
value|2
define|#
directive|define
name|E4_YSTORM_FCOE_TASK_AG_CTX_CF2SPECIAL_MASK
value|0x3
comment|/* cf2special */
define|#
directive|define
name|E4_YSTORM_FCOE_TASK_AG_CTX_CF2SPECIAL_SHIFT
value|4
define|#
directive|define
name|E4_YSTORM_FCOE_TASK_AG_CTX_CF0EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E4_YSTORM_FCOE_TASK_AG_CTX_CF0EN_SHIFT
value|6
define|#
directive|define
name|E4_YSTORM_FCOE_TASK_AG_CTX_CF1EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E4_YSTORM_FCOE_TASK_AG_CTX_CF1EN_SHIFT
value|7
name|u8
name|flags2
decl_stmt|;
define|#
directive|define
name|E4_YSTORM_FCOE_TASK_AG_CTX_BIT4_MASK
value|0x1
comment|/* bit4 */
define|#
directive|define
name|E4_YSTORM_FCOE_TASK_AG_CTX_BIT4_SHIFT
value|0
define|#
directive|define
name|E4_YSTORM_FCOE_TASK_AG_CTX_RULE0EN_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E4_YSTORM_FCOE_TASK_AG_CTX_RULE0EN_SHIFT
value|1
define|#
directive|define
name|E4_YSTORM_FCOE_TASK_AG_CTX_RULE1EN_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E4_YSTORM_FCOE_TASK_AG_CTX_RULE1EN_SHIFT
value|2
define|#
directive|define
name|E4_YSTORM_FCOE_TASK_AG_CTX_RULE2EN_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E4_YSTORM_FCOE_TASK_AG_CTX_RULE2EN_SHIFT
value|3
define|#
directive|define
name|E4_YSTORM_FCOE_TASK_AG_CTX_RULE3EN_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E4_YSTORM_FCOE_TASK_AG_CTX_RULE3EN_SHIFT
value|4
define|#
directive|define
name|E4_YSTORM_FCOE_TASK_AG_CTX_RULE4EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E4_YSTORM_FCOE_TASK_AG_CTX_RULE4EN_SHIFT
value|5
define|#
directive|define
name|E4_YSTORM_FCOE_TASK_AG_CTX_RULE5EN_MASK
value|0x1
comment|/* rule5en */
define|#
directive|define
name|E4_YSTORM_FCOE_TASK_AG_CTX_RULE5EN_SHIFT
value|6
define|#
directive|define
name|E4_YSTORM_FCOE_TASK_AG_CTX_RULE6EN_MASK
value|0x1
comment|/* rule6en */
define|#
directive|define
name|E4_YSTORM_FCOE_TASK_AG_CTX_RULE6EN_SHIFT
value|7
name|u8
name|byte2
comment|/* byte2 */
decl_stmt|;
name|__le32
name|reg0
comment|/* reg0 */
decl_stmt|;
name|u8
name|byte3
comment|/* byte3 */
decl_stmt|;
name|u8
name|byte4
comment|/* byte4 */
decl_stmt|;
name|__le16
name|rx_id
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
name|__le16
name|word5
comment|/* word5 */
decl_stmt|;
name|__le32
name|reg1
comment|/* reg1 */
decl_stmt|;
name|__le32
name|reg2
comment|/* reg2 */
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|e4_tstorm_fcoe_task_ag_ctx
block|{
name|u8
name|reserved
comment|/* cdu_validation */
decl_stmt|;
name|u8
name|byte1
comment|/* state */
decl_stmt|;
name|__le16
name|icid
comment|/* icid */
decl_stmt|;
name|u8
name|flags0
decl_stmt|;
define|#
directive|define
name|E4_TSTORM_FCOE_TASK_AG_CTX_CONNECTION_TYPE_MASK
value|0xF
comment|/* connection_type */
define|#
directive|define
name|E4_TSTORM_FCOE_TASK_AG_CTX_CONNECTION_TYPE_SHIFT
value|0
define|#
directive|define
name|E4_TSTORM_FCOE_TASK_AG_CTX_EXIST_IN_QM0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E4_TSTORM_FCOE_TASK_AG_CTX_EXIST_IN_QM0_SHIFT
value|4
define|#
directive|define
name|E4_TSTORM_FCOE_TASK_AG_CTX_BIT1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E4_TSTORM_FCOE_TASK_AG_CTX_BIT1_SHIFT
value|5
define|#
directive|define
name|E4_TSTORM_FCOE_TASK_AG_CTX_WAIT_ABTS_RSP_F_MASK
value|0x1
comment|/* bit2 */
define|#
directive|define
name|E4_TSTORM_FCOE_TASK_AG_CTX_WAIT_ABTS_RSP_F_SHIFT
value|6
define|#
directive|define
name|E4_TSTORM_FCOE_TASK_AG_CTX_VALID_MASK
value|0x1
comment|/* bit3 */
define|#
directive|define
name|E4_TSTORM_FCOE_TASK_AG_CTX_VALID_SHIFT
value|7
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E4_TSTORM_FCOE_TASK_AG_CTX_FALSE_RR_TOV_MASK
value|0x1
comment|/* bit4 */
define|#
directive|define
name|E4_TSTORM_FCOE_TASK_AG_CTX_FALSE_RR_TOV_SHIFT
value|0
define|#
directive|define
name|E4_TSTORM_FCOE_TASK_AG_CTX_BIT5_MASK
value|0x1
comment|/* bit5 */
define|#
directive|define
name|E4_TSTORM_FCOE_TASK_AG_CTX_BIT5_SHIFT
value|1
define|#
directive|define
name|E4_TSTORM_FCOE_TASK_AG_CTX_REC_RR_TOV_CF_MASK
value|0x3
comment|/* timer0cf */
define|#
directive|define
name|E4_TSTORM_FCOE_TASK_AG_CTX_REC_RR_TOV_CF_SHIFT
value|2
define|#
directive|define
name|E4_TSTORM_FCOE_TASK_AG_CTX_ED_TOV_CF_MASK
value|0x3
comment|/* timer1cf */
define|#
directive|define
name|E4_TSTORM_FCOE_TASK_AG_CTX_ED_TOV_CF_SHIFT
value|4
define|#
directive|define
name|E4_TSTORM_FCOE_TASK_AG_CTX_CF2_MASK
value|0x3
comment|/* timer2cf */
define|#
directive|define
name|E4_TSTORM_FCOE_TASK_AG_CTX_CF2_SHIFT
value|6
name|u8
name|flags2
decl_stmt|;
define|#
directive|define
name|E4_TSTORM_FCOE_TASK_AG_CTX_TIMER_STOP_ALL_MASK
value|0x3
comment|/* timer_stop_all */
define|#
directive|define
name|E4_TSTORM_FCOE_TASK_AG_CTX_TIMER_STOP_ALL_SHIFT
value|0
define|#
directive|define
name|E4_TSTORM_FCOE_TASK_AG_CTX_EX_CLEANUP_CF_MASK
value|0x3
comment|/* cf4 */
define|#
directive|define
name|E4_TSTORM_FCOE_TASK_AG_CTX_EX_CLEANUP_CF_SHIFT
value|2
define|#
directive|define
name|E4_TSTORM_FCOE_TASK_AG_CTX_SEQ_INIT_CF_MASK
value|0x3
comment|/* cf5 */
define|#
directive|define
name|E4_TSTORM_FCOE_TASK_AG_CTX_SEQ_INIT_CF_SHIFT
value|4
define|#
directive|define
name|E4_TSTORM_FCOE_TASK_AG_CTX_SEQ_RECOVERY_CF_MASK
value|0x3
comment|/* cf6 */
define|#
directive|define
name|E4_TSTORM_FCOE_TASK_AG_CTX_SEQ_RECOVERY_CF_SHIFT
value|6
name|u8
name|flags3
decl_stmt|;
define|#
directive|define
name|E4_TSTORM_FCOE_TASK_AG_CTX_UNSOL_COMP_CF_MASK
value|0x3
comment|/* cf7 */
define|#
directive|define
name|E4_TSTORM_FCOE_TASK_AG_CTX_UNSOL_COMP_CF_SHIFT
value|0
define|#
directive|define
name|E4_TSTORM_FCOE_TASK_AG_CTX_REC_RR_TOV_CF_EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E4_TSTORM_FCOE_TASK_AG_CTX_REC_RR_TOV_CF_EN_SHIFT
value|2
define|#
directive|define
name|E4_TSTORM_FCOE_TASK_AG_CTX_ED_TOV_CF_EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E4_TSTORM_FCOE_TASK_AG_CTX_ED_TOV_CF_EN_SHIFT
value|3
define|#
directive|define
name|E4_TSTORM_FCOE_TASK_AG_CTX_CF2EN_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E4_TSTORM_FCOE_TASK_AG_CTX_CF2EN_SHIFT
value|4
define|#
directive|define
name|E4_TSTORM_FCOE_TASK_AG_CTX_TIMER_STOP_ALL_EN_MASK
value|0x1
comment|/* cf3en */
define|#
directive|define
name|E4_TSTORM_FCOE_TASK_AG_CTX_TIMER_STOP_ALL_EN_SHIFT
value|5
define|#
directive|define
name|E4_TSTORM_FCOE_TASK_AG_CTX_EX_CLEANUP_CF_EN_MASK
value|0x1
comment|/* cf4en */
define|#
directive|define
name|E4_TSTORM_FCOE_TASK_AG_CTX_EX_CLEANUP_CF_EN_SHIFT
value|6
define|#
directive|define
name|E4_TSTORM_FCOE_TASK_AG_CTX_SEQ_INIT_CF_EN_MASK
value|0x1
comment|/* cf5en */
define|#
directive|define
name|E4_TSTORM_FCOE_TASK_AG_CTX_SEQ_INIT_CF_EN_SHIFT
value|7
name|u8
name|flags4
decl_stmt|;
define|#
directive|define
name|E4_TSTORM_FCOE_TASK_AG_CTX_SEQ_RECOVERY_CF_EN_MASK
value|0x1
comment|/* cf6en */
define|#
directive|define
name|E4_TSTORM_FCOE_TASK_AG_CTX_SEQ_RECOVERY_CF_EN_SHIFT
value|0
define|#
directive|define
name|E4_TSTORM_FCOE_TASK_AG_CTX_UNSOL_COMP_CF_EN_MASK
value|0x1
comment|/* cf7en */
define|#
directive|define
name|E4_TSTORM_FCOE_TASK_AG_CTX_UNSOL_COMP_CF_EN_SHIFT
value|1
define|#
directive|define
name|E4_TSTORM_FCOE_TASK_AG_CTX_RULE0EN_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E4_TSTORM_FCOE_TASK_AG_CTX_RULE0EN_SHIFT
value|2
define|#
directive|define
name|E4_TSTORM_FCOE_TASK_AG_CTX_RULE1EN_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E4_TSTORM_FCOE_TASK_AG_CTX_RULE1EN_SHIFT
value|3
define|#
directive|define
name|E4_TSTORM_FCOE_TASK_AG_CTX_RULE2EN_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E4_TSTORM_FCOE_TASK_AG_CTX_RULE2EN_SHIFT
value|4
define|#
directive|define
name|E4_TSTORM_FCOE_TASK_AG_CTX_RULE3EN_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E4_TSTORM_FCOE_TASK_AG_CTX_RULE3EN_SHIFT
value|5
define|#
directive|define
name|E4_TSTORM_FCOE_TASK_AG_CTX_RULE4EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E4_TSTORM_FCOE_TASK_AG_CTX_RULE4EN_SHIFT
value|6
define|#
directive|define
name|E4_TSTORM_FCOE_TASK_AG_CTX_RULE5EN_MASK
value|0x1
comment|/* rule5en */
define|#
directive|define
name|E4_TSTORM_FCOE_TASK_AG_CTX_RULE5EN_SHIFT
value|7
name|u8
name|cleanup_state
comment|/* byte2 */
decl_stmt|;
name|__le16
name|last_sent_tid
comment|/* word1 */
decl_stmt|;
name|__le32
name|rec_rr_tov_exp_timeout
comment|/* reg0 */
decl_stmt|;
name|u8
name|byte3
comment|/* byte3 */
decl_stmt|;
name|u8
name|byte4
comment|/* byte4 */
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
name|data_offset_end_of_seq
comment|/* reg1 */
decl_stmt|;
name|__le32
name|data_offset_next
comment|/* reg2 */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Cached data sges  */
end_comment

begin_struct
struct|struct
name|fcoe_exp_ro
block|{
name|__le32
name|data_offset
comment|/* data-offset */
decl_stmt|;
name|__le32
name|reserved
comment|/* High data-offset */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Union of Cleanup address \ expected relative offsets  */
end_comment

begin_union
union|union
name|fcoe_cleanup_addr_exp_ro_union
block|{
name|struct
name|regpair
name|abts_rsp_fc_payload_hi
comment|/* Abts flow: first 64 bits of fcPayload, out of 96 */
decl_stmt|;
name|struct
name|fcoe_exp_ro
name|exp_ro
comment|/* Expected relative offsets */
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/*  * fields coppied from ABTSrsp pckt  */
end_comment

begin_struct
struct|struct
name|fcoe_abts_pkt
block|{
name|__le32
name|abts_rsp_fc_payload_lo
comment|/* Abts flow: last 32 bits of fcPayload, out of 96 */
decl_stmt|;
name|__le16
name|abts_rsp_rx_id
comment|/* Abts flow: rxId parameter of the abts packet */
decl_stmt|;
name|u8
name|abts_rsp_rctl
comment|/* Abts flow: rctl parameter of the abts packet */
decl_stmt|;
name|u8
name|reserved2
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * FW read- write (modifyable) part The fcoe task storm context of Tstorm  */
end_comment

begin_struct
struct|struct
name|fcoe_tstorm_fcoe_task_st_ctx_read_write
block|{
name|union
name|fcoe_cleanup_addr_exp_ro_union
name|cleanup_addr_exp_ro_union
comment|/* Union of Cleanup address / expected relative offsets */
decl_stmt|;
name|__le16
name|flags
decl_stmt|;
define|#
directive|define
name|FCOE_TSTORM_FCOE_TASK_ST_CTX_READ_WRITE_RX_SGL_MODE_MASK
value|0x1
comment|/* Rx SGL type. use enum scsi_sgl_mode  (use enum scsi_sgl_mode) */
define|#
directive|define
name|FCOE_TSTORM_FCOE_TASK_ST_CTX_READ_WRITE_RX_SGL_MODE_SHIFT
value|0
define|#
directive|define
name|FCOE_TSTORM_FCOE_TASK_ST_CTX_READ_WRITE_EXP_FIRST_FRAME_MASK
value|0x1
comment|/* Expected first frame flag */
define|#
directive|define
name|FCOE_TSTORM_FCOE_TASK_ST_CTX_READ_WRITE_EXP_FIRST_FRAME_SHIFT
value|1
define|#
directive|define
name|FCOE_TSTORM_FCOE_TASK_ST_CTX_READ_WRITE_SEQ_ACTIVE_MASK
value|0x1
comment|/* Sequence active */
define|#
directive|define
name|FCOE_TSTORM_FCOE_TASK_ST_CTX_READ_WRITE_SEQ_ACTIVE_SHIFT
value|2
define|#
directive|define
name|FCOE_TSTORM_FCOE_TASK_ST_CTX_READ_WRITE_SEQ_TIMEOUT_MASK
value|0x1
comment|/* Sequence timeout for an active Sequence */
define|#
directive|define
name|FCOE_TSTORM_FCOE_TASK_ST_CTX_READ_WRITE_SEQ_TIMEOUT_SHIFT
value|3
define|#
directive|define
name|FCOE_TSTORM_FCOE_TASK_ST_CTX_READ_WRITE_SINGLE_PKT_IN_EX_MASK
value|0x1
comment|/* Set by Data-in flow. Indicate that this exchange contains a single FCP DATA packet */
define|#
directive|define
name|FCOE_TSTORM_FCOE_TASK_ST_CTX_READ_WRITE_SINGLE_PKT_IN_EX_SHIFT
value|4
define|#
directive|define
name|FCOE_TSTORM_FCOE_TASK_ST_CTX_READ_WRITE_OOO_RX_SEQ_STAT_MASK
value|0x1
comment|/* The status of the current out of order received Sequence */
define|#
directive|define
name|FCOE_TSTORM_FCOE_TASK_ST_CTX_READ_WRITE_OOO_RX_SEQ_STAT_SHIFT
value|5
define|#
directive|define
name|FCOE_TSTORM_FCOE_TASK_ST_CTX_READ_WRITE_CQ_ADD_ADV_MASK
value|0x3
comment|/* number of additional CQE that will be produced for this task completion */
define|#
directive|define
name|FCOE_TSTORM_FCOE_TASK_ST_CTX_READ_WRITE_CQ_ADD_ADV_SHIFT
value|6
define|#
directive|define
name|FCOE_TSTORM_FCOE_TASK_ST_CTX_READ_WRITE_RSRV1_MASK
value|0xFF
define|#
directive|define
name|FCOE_TSTORM_FCOE_TASK_ST_CTX_READ_WRITE_RSRV1_SHIFT
value|8
name|__le16
name|seq_cnt
comment|/* Sequence counter */
decl_stmt|;
name|u8
name|seq_id
comment|/* Sequence id */
decl_stmt|;
name|u8
name|ooo_rx_seq_id
comment|/* The last out of order received SEQ_ID */
decl_stmt|;
name|__le16
name|rx_id
comment|/* RX_ID of the exchange - should match each packet expect for the first */
decl_stmt|;
name|struct
name|fcoe_abts_pkt
name|abts_data
comment|/* The last out of order received SEQ_CNT */
decl_stmt|;
name|__le32
name|e_d_tov_exp_timeout_val
comment|/* E_D_TOV timer val (in msec) */
decl_stmt|;
name|__le16
name|ooo_rx_seq_cnt
comment|/* The last out of order received SEQ_CNT */
decl_stmt|;
name|__le16
name|reserved1
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * FW read only part The fcoe task storm context of Tstorm  */
end_comment

begin_struct
struct|struct
name|fcoe_tstorm_fcoe_task_st_ctx_read_only
block|{
name|u8
name|task_type
comment|/* Task type. use enum fcoe_task_type */
decl_stmt|;
name|u8
name|dev_type
comment|/* Device type (disk or tape). use enum fcoe_device_type */
decl_stmt|;
name|u8
name|conf_supported
comment|/* Confirmation supported indication */
decl_stmt|;
name|u8
name|glbl_q_num
comment|/* Global RQ/CQ num to be used for sense data placement/completion */
decl_stmt|;
name|__le32
name|cid
comment|/* CID which that tasks associated to */
decl_stmt|;
name|__le32
name|fcp_cmd_trns_size
comment|/* IO size as reflected in FCP CMD */
decl_stmt|;
name|__le32
name|rsrv
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The fcoe task storm context of Tstorm  */
end_comment

begin_struct
struct|struct
name|tstorm_fcoe_task_st_ctx
block|{
name|struct
name|fcoe_tstorm_fcoe_task_st_ctx_read_write
name|read_write
comment|/* FW read- write (modifyable) part The fcoe task storm context of Tstorm */
decl_stmt|;
name|struct
name|fcoe_tstorm_fcoe_task_st_ctx_read_only
name|read_only
comment|/* FW read only part The fcoe task storm context of Tstorm */
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|e4_mstorm_fcoe_task_ag_ctx
block|{
name|u8
name|byte0
comment|/* cdu_validation */
decl_stmt|;
name|u8
name|byte1
comment|/* state */
decl_stmt|;
name|__le16
name|icid
comment|/* icid */
decl_stmt|;
name|u8
name|flags0
decl_stmt|;
define|#
directive|define
name|E4_MSTORM_FCOE_TASK_AG_CTX_CONNECTION_TYPE_MASK
value|0xF
comment|/* connection_type */
define|#
directive|define
name|E4_MSTORM_FCOE_TASK_AG_CTX_CONNECTION_TYPE_SHIFT
value|0
define|#
directive|define
name|E4_MSTORM_FCOE_TASK_AG_CTX_EXIST_IN_QM0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E4_MSTORM_FCOE_TASK_AG_CTX_EXIST_IN_QM0_SHIFT
value|4
define|#
directive|define
name|E4_MSTORM_FCOE_TASK_AG_CTX_CQE_PLACED_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E4_MSTORM_FCOE_TASK_AG_CTX_CQE_PLACED_SHIFT
value|5
define|#
directive|define
name|E4_MSTORM_FCOE_TASK_AG_CTX_BIT2_MASK
value|0x1
comment|/* bit2 */
define|#
directive|define
name|E4_MSTORM_FCOE_TASK_AG_CTX_BIT2_SHIFT
value|6
define|#
directive|define
name|E4_MSTORM_FCOE_TASK_AG_CTX_BIT3_MASK
value|0x1
comment|/* bit3 */
define|#
directive|define
name|E4_MSTORM_FCOE_TASK_AG_CTX_BIT3_SHIFT
value|7
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E4_MSTORM_FCOE_TASK_AG_CTX_EX_CLEANUP_CF_MASK
value|0x3
comment|/* cf0 */
define|#
directive|define
name|E4_MSTORM_FCOE_TASK_AG_CTX_EX_CLEANUP_CF_SHIFT
value|0
define|#
directive|define
name|E4_MSTORM_FCOE_TASK_AG_CTX_CF1_MASK
value|0x3
comment|/* cf1 */
define|#
directive|define
name|E4_MSTORM_FCOE_TASK_AG_CTX_CF1_SHIFT
value|2
define|#
directive|define
name|E4_MSTORM_FCOE_TASK_AG_CTX_CF2_MASK
value|0x3
comment|/* cf2 */
define|#
directive|define
name|E4_MSTORM_FCOE_TASK_AG_CTX_CF2_SHIFT
value|4
define|#
directive|define
name|E4_MSTORM_FCOE_TASK_AG_CTX_EX_CLEANUP_CF_EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E4_MSTORM_FCOE_TASK_AG_CTX_EX_CLEANUP_CF_EN_SHIFT
value|6
define|#
directive|define
name|E4_MSTORM_FCOE_TASK_AG_CTX_CF1EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E4_MSTORM_FCOE_TASK_AG_CTX_CF1EN_SHIFT
value|7
name|u8
name|flags2
decl_stmt|;
define|#
directive|define
name|E4_MSTORM_FCOE_TASK_AG_CTX_CF2EN_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E4_MSTORM_FCOE_TASK_AG_CTX_CF2EN_SHIFT
value|0
define|#
directive|define
name|E4_MSTORM_FCOE_TASK_AG_CTX_RULE0EN_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E4_MSTORM_FCOE_TASK_AG_CTX_RULE0EN_SHIFT
value|1
define|#
directive|define
name|E4_MSTORM_FCOE_TASK_AG_CTX_RULE1EN_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E4_MSTORM_FCOE_TASK_AG_CTX_RULE1EN_SHIFT
value|2
define|#
directive|define
name|E4_MSTORM_FCOE_TASK_AG_CTX_RULE2EN_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E4_MSTORM_FCOE_TASK_AG_CTX_RULE2EN_SHIFT
value|3
define|#
directive|define
name|E4_MSTORM_FCOE_TASK_AG_CTX_RULE3EN_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E4_MSTORM_FCOE_TASK_AG_CTX_RULE3EN_SHIFT
value|4
define|#
directive|define
name|E4_MSTORM_FCOE_TASK_AG_CTX_RULE4EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E4_MSTORM_FCOE_TASK_AG_CTX_RULE4EN_SHIFT
value|5
define|#
directive|define
name|E4_MSTORM_FCOE_TASK_AG_CTX_XFER_PLACEMENT_EN_MASK
value|0x1
comment|/* rule5en */
define|#
directive|define
name|E4_MSTORM_FCOE_TASK_AG_CTX_XFER_PLACEMENT_EN_SHIFT
value|6
define|#
directive|define
name|E4_MSTORM_FCOE_TASK_AG_CTX_RULE6EN_MASK
value|0x1
comment|/* rule6en */
define|#
directive|define
name|E4_MSTORM_FCOE_TASK_AG_CTX_RULE6EN_SHIFT
value|7
name|u8
name|cleanup_state
comment|/* byte2 */
decl_stmt|;
name|__le32
name|received_bytes
comment|/* reg0 */
decl_stmt|;
name|u8
name|byte3
comment|/* byte3 */
decl_stmt|;
name|u8
name|glbl_q_num
comment|/* byte4 */
decl_stmt|;
name|__le16
name|word1
comment|/* word1 */
decl_stmt|;
name|__le16
name|tid_to_xfer
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
name|__le16
name|word5
comment|/* word5 */
decl_stmt|;
name|__le32
name|expected_bytes
comment|/* reg1 */
decl_stmt|;
name|__le32
name|reg2
comment|/* reg2 */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The fcoe task storm context of Mstorm  */
end_comment

begin_struct
struct|struct
name|mstorm_fcoe_task_st_ctx
block|{
name|struct
name|regpair
name|rsp_buf_addr
comment|/* Buffer to place the sense/response data attached to FCP_RSP frame */
decl_stmt|;
name|__le32
name|rsrv
index|[
literal|2
index|]
decl_stmt|;
name|struct
name|scsi_sgl_params
name|sgl_params
decl_stmt|;
name|__le32
name|data_2_trns_rem
comment|/* Entire SGL buffer size remainder */
decl_stmt|;
name|__le32
name|data_buffer_offset
comment|/* Buffer offset */
decl_stmt|;
name|__le16
name|parent_id
comment|/* Used for multiple continuation in Target mode */
decl_stmt|;
name|__le16
name|flags
decl_stmt|;
define|#
directive|define
name|MSTORM_FCOE_TASK_ST_CTX_INTERVAL_SIZE_LOG_MASK
value|0xF
comment|/* Protection log interval (9=512 10=1024  11=2048 12=4096 13=8192) */
define|#
directive|define
name|MSTORM_FCOE_TASK_ST_CTX_INTERVAL_SIZE_LOG_SHIFT
value|0
define|#
directive|define
name|MSTORM_FCOE_TASK_ST_CTX_HOST_INTERFACE_MASK
value|0x3
comment|/* 0=none, 1=DIF, 2=DIX */
define|#
directive|define
name|MSTORM_FCOE_TASK_ST_CTX_HOST_INTERFACE_SHIFT
value|4
define|#
directive|define
name|MSTORM_FCOE_TASK_ST_CTX_DIF_TO_PEER_MASK
value|0x1
comment|/* 0=no, 1=yes */
define|#
directive|define
name|MSTORM_FCOE_TASK_ST_CTX_DIF_TO_PEER_SHIFT
value|6
define|#
directive|define
name|MSTORM_FCOE_TASK_ST_CTX_MP_INCLUDE_FC_HEADER_MASK
value|0x1
comment|/* 0 = 24 Bytes FC Header not included in Middle-Path placement, 1 = 24 Bytes FC Header included in MP placement */
define|#
directive|define
name|MSTORM_FCOE_TASK_ST_CTX_MP_INCLUDE_FC_HEADER_SHIFT
value|7
define|#
directive|define
name|MSTORM_FCOE_TASK_ST_CTX_DIX_BLOCK_SIZE_MASK
value|0x3
comment|/* DIX block size: can be 0:2B, 1:4B, 2:8B */
define|#
directive|define
name|MSTORM_FCOE_TASK_ST_CTX_DIX_BLOCK_SIZE_SHIFT
value|8
define|#
directive|define
name|MSTORM_FCOE_TASK_ST_CTX_VALIDATE_DIX_REF_TAG_MASK
value|0x1
comment|/* 0=no, 1=yes */
define|#
directive|define
name|MSTORM_FCOE_TASK_ST_CTX_VALIDATE_DIX_REF_TAG_SHIFT
value|10
define|#
directive|define
name|MSTORM_FCOE_TASK_ST_CTX_DIX_CACHED_SGE_FLG_MASK
value|0x1
comment|/* Indication to a single cached DIX SGE instead of SGL */
define|#
directive|define
name|MSTORM_FCOE_TASK_ST_CTX_DIX_CACHED_SGE_FLG_SHIFT
value|11
define|#
directive|define
name|MSTORM_FCOE_TASK_ST_CTX_DIF_SUPPORTED_MASK
value|0x1
define|#
directive|define
name|MSTORM_FCOE_TASK_ST_CTX_DIF_SUPPORTED_SHIFT
value|12
define|#
directive|define
name|MSTORM_FCOE_TASK_ST_CTX_TX_SGL_MODE_MASK
value|0x1
comment|/* use_enum scsi_sgl_mode (use enum scsi_sgl_mode) */
define|#
directive|define
name|MSTORM_FCOE_TASK_ST_CTX_TX_SGL_MODE_SHIFT
value|13
define|#
directive|define
name|MSTORM_FCOE_TASK_ST_CTX_RESERVED_MASK
value|0x3
define|#
directive|define
name|MSTORM_FCOE_TASK_ST_CTX_RESERVED_SHIFT
value|14
name|struct
name|scsi_cached_sges
name|data_desc
comment|/* Union of Data SGL / cached sge */
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|e4_ustorm_fcoe_task_ag_ctx
block|{
name|u8
name|reserved
comment|/* cdu_validation */
decl_stmt|;
name|u8
name|byte1
comment|/* state */
decl_stmt|;
name|__le16
name|icid
comment|/* icid */
decl_stmt|;
name|u8
name|flags0
decl_stmt|;
define|#
directive|define
name|E4_USTORM_FCOE_TASK_AG_CTX_CONNECTION_TYPE_MASK
value|0xF
comment|/* connection_type */
define|#
directive|define
name|E4_USTORM_FCOE_TASK_AG_CTX_CONNECTION_TYPE_SHIFT
value|0
define|#
directive|define
name|E4_USTORM_FCOE_TASK_AG_CTX_EXIST_IN_QM0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E4_USTORM_FCOE_TASK_AG_CTX_EXIST_IN_QM0_SHIFT
value|4
define|#
directive|define
name|E4_USTORM_FCOE_TASK_AG_CTX_BIT1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E4_USTORM_FCOE_TASK_AG_CTX_BIT1_SHIFT
value|5
define|#
directive|define
name|E4_USTORM_FCOE_TASK_AG_CTX_CF0_MASK
value|0x3
comment|/* timer0cf */
define|#
directive|define
name|E4_USTORM_FCOE_TASK_AG_CTX_CF0_SHIFT
value|6
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E4_USTORM_FCOE_TASK_AG_CTX_CF1_MASK
value|0x3
comment|/* timer1cf */
define|#
directive|define
name|E4_USTORM_FCOE_TASK_AG_CTX_CF1_SHIFT
value|0
define|#
directive|define
name|E4_USTORM_FCOE_TASK_AG_CTX_CF2_MASK
value|0x3
comment|/* timer2cf */
define|#
directive|define
name|E4_USTORM_FCOE_TASK_AG_CTX_CF2_SHIFT
value|2
define|#
directive|define
name|E4_USTORM_FCOE_TASK_AG_CTX_CF3_MASK
value|0x3
comment|/* timer_stop_all */
define|#
directive|define
name|E4_USTORM_FCOE_TASK_AG_CTX_CF3_SHIFT
value|4
define|#
directive|define
name|E4_USTORM_FCOE_TASK_AG_CTX_DIF_ERROR_CF_MASK
value|0x3
comment|/* cf4 */
define|#
directive|define
name|E4_USTORM_FCOE_TASK_AG_CTX_DIF_ERROR_CF_SHIFT
value|6
name|u8
name|flags2
decl_stmt|;
define|#
directive|define
name|E4_USTORM_FCOE_TASK_AG_CTX_CF0EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E4_USTORM_FCOE_TASK_AG_CTX_CF0EN_SHIFT
value|0
define|#
directive|define
name|E4_USTORM_FCOE_TASK_AG_CTX_CF1EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E4_USTORM_FCOE_TASK_AG_CTX_CF1EN_SHIFT
value|1
define|#
directive|define
name|E4_USTORM_FCOE_TASK_AG_CTX_CF2EN_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E4_USTORM_FCOE_TASK_AG_CTX_CF2EN_SHIFT
value|2
define|#
directive|define
name|E4_USTORM_FCOE_TASK_AG_CTX_CF3EN_MASK
value|0x1
comment|/* cf3en */
define|#
directive|define
name|E4_USTORM_FCOE_TASK_AG_CTX_CF3EN_SHIFT
value|3
define|#
directive|define
name|E4_USTORM_FCOE_TASK_AG_CTX_DIF_ERROR_CF_EN_MASK
value|0x1
comment|/* cf4en */
define|#
directive|define
name|E4_USTORM_FCOE_TASK_AG_CTX_DIF_ERROR_CF_EN_SHIFT
value|4
define|#
directive|define
name|E4_USTORM_FCOE_TASK_AG_CTX_RULE0EN_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E4_USTORM_FCOE_TASK_AG_CTX_RULE0EN_SHIFT
value|5
define|#
directive|define
name|E4_USTORM_FCOE_TASK_AG_CTX_RULE1EN_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E4_USTORM_FCOE_TASK_AG_CTX_RULE1EN_SHIFT
value|6
define|#
directive|define
name|E4_USTORM_FCOE_TASK_AG_CTX_RULE2EN_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E4_USTORM_FCOE_TASK_AG_CTX_RULE2EN_SHIFT
value|7
name|u8
name|flags3
decl_stmt|;
define|#
directive|define
name|E4_USTORM_FCOE_TASK_AG_CTX_RULE3EN_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E4_USTORM_FCOE_TASK_AG_CTX_RULE3EN_SHIFT
value|0
define|#
directive|define
name|E4_USTORM_FCOE_TASK_AG_CTX_RULE4EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E4_USTORM_FCOE_TASK_AG_CTX_RULE4EN_SHIFT
value|1
define|#
directive|define
name|E4_USTORM_FCOE_TASK_AG_CTX_RULE5EN_MASK
value|0x1
comment|/* rule5en */
define|#
directive|define
name|E4_USTORM_FCOE_TASK_AG_CTX_RULE5EN_SHIFT
value|2
define|#
directive|define
name|E4_USTORM_FCOE_TASK_AG_CTX_RULE6EN_MASK
value|0x1
comment|/* rule6en */
define|#
directive|define
name|E4_USTORM_FCOE_TASK_AG_CTX_RULE6EN_SHIFT
value|3
define|#
directive|define
name|E4_USTORM_FCOE_TASK_AG_CTX_DIF_ERROR_TYPE_MASK
value|0xF
comment|/* nibble1 */
define|#
directive|define
name|E4_USTORM_FCOE_TASK_AG_CTX_DIF_ERROR_TYPE_SHIFT
value|4
name|__le32
name|dif_err_intervals
comment|/* reg0 */
decl_stmt|;
name|__le32
name|dif_error_1st_interval
comment|/* reg1 */
decl_stmt|;
name|__le32
name|global_cq_num
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
comment|/* reg5 */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * fcoe task context  */
end_comment

begin_struct
struct|struct
name|e4_fcoe_task_context
block|{
name|struct
name|ystorm_fcoe_task_st_ctx
name|ystorm_st_context
comment|/* ystorm storm context */
decl_stmt|;
name|struct
name|regpair
name|ystorm_st_padding
index|[
literal|2
index|]
comment|/* padding */
decl_stmt|;
name|struct
name|tdif_task_context
name|tdif_context
comment|/* tdif context */
decl_stmt|;
name|struct
name|e4_ystorm_fcoe_task_ag_ctx
name|ystorm_ag_context
comment|/* ystorm aggregative context */
decl_stmt|;
name|struct
name|e4_tstorm_fcoe_task_ag_ctx
name|tstorm_ag_context
comment|/* tstorm aggregative context */
decl_stmt|;
name|struct
name|timers_context
name|timer_context
comment|/* timer context */
decl_stmt|;
name|struct
name|tstorm_fcoe_task_st_ctx
name|tstorm_st_context
comment|/* tstorm storm context */
decl_stmt|;
name|struct
name|regpair
name|tstorm_st_padding
index|[
literal|2
index|]
comment|/* padding */
decl_stmt|;
name|struct
name|e4_mstorm_fcoe_task_ag_ctx
name|mstorm_ag_context
comment|/* mstorm aggregative context */
decl_stmt|;
name|struct
name|mstorm_fcoe_task_st_ctx
name|mstorm_st_context
comment|/* mstorm storm context */
decl_stmt|;
name|struct
name|e4_ustorm_fcoe_task_ag_ctx
name|ustorm_ag_context
comment|/* ustorm aggregative context */
decl_stmt|;
name|struct
name|rdif_task_context
name|rdif_context
comment|/* rdif context */
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|e5_ystorm_fcoe_task_ag_ctx
block|{
name|u8
name|byte0
comment|/* cdu_validation */
decl_stmt|;
name|u8
name|byte1
comment|/* state_and_core_id */
decl_stmt|;
name|__le16
name|word0
comment|/* icid */
decl_stmt|;
name|u8
name|flags0
decl_stmt|;
define|#
directive|define
name|E5_YSTORM_FCOE_TASK_AG_CTX_NIBBLE0_MASK
value|0xF
comment|/* connection_type */
define|#
directive|define
name|E5_YSTORM_FCOE_TASK_AG_CTX_NIBBLE0_SHIFT
value|0
define|#
directive|define
name|E5_YSTORM_FCOE_TASK_AG_CTX_BIT0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E5_YSTORM_FCOE_TASK_AG_CTX_BIT0_SHIFT
value|4
define|#
directive|define
name|E5_YSTORM_FCOE_TASK_AG_CTX_BIT1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E5_YSTORM_FCOE_TASK_AG_CTX_BIT1_SHIFT
value|5
define|#
directive|define
name|E5_YSTORM_FCOE_TASK_AG_CTX_BIT2_MASK
value|0x1
comment|/* bit2 */
define|#
directive|define
name|E5_YSTORM_FCOE_TASK_AG_CTX_BIT2_SHIFT
value|6
define|#
directive|define
name|E5_YSTORM_FCOE_TASK_AG_CTX_BIT3_MASK
value|0x1
comment|/* bit3 */
define|#
directive|define
name|E5_YSTORM_FCOE_TASK_AG_CTX_BIT3_SHIFT
value|7
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E5_YSTORM_FCOE_TASK_AG_CTX_CF0_MASK
value|0x3
comment|/* cf0 */
define|#
directive|define
name|E5_YSTORM_FCOE_TASK_AG_CTX_CF0_SHIFT
value|0
define|#
directive|define
name|E5_YSTORM_FCOE_TASK_AG_CTX_CF1_MASK
value|0x3
comment|/* cf1 */
define|#
directive|define
name|E5_YSTORM_FCOE_TASK_AG_CTX_CF1_SHIFT
value|2
define|#
directive|define
name|E5_YSTORM_FCOE_TASK_AG_CTX_CF2SPECIAL_MASK
value|0x3
comment|/* cf2special */
define|#
directive|define
name|E5_YSTORM_FCOE_TASK_AG_CTX_CF2SPECIAL_SHIFT
value|4
define|#
directive|define
name|E5_YSTORM_FCOE_TASK_AG_CTX_CF0EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E5_YSTORM_FCOE_TASK_AG_CTX_CF0EN_SHIFT
value|6
define|#
directive|define
name|E5_YSTORM_FCOE_TASK_AG_CTX_CF1EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E5_YSTORM_FCOE_TASK_AG_CTX_CF1EN_SHIFT
value|7
name|u8
name|flags2
decl_stmt|;
define|#
directive|define
name|E5_YSTORM_FCOE_TASK_AG_CTX_BIT4_MASK
value|0x1
comment|/* bit4 */
define|#
directive|define
name|E5_YSTORM_FCOE_TASK_AG_CTX_BIT4_SHIFT
value|0
define|#
directive|define
name|E5_YSTORM_FCOE_TASK_AG_CTX_RULE0EN_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E5_YSTORM_FCOE_TASK_AG_CTX_RULE0EN_SHIFT
value|1
define|#
directive|define
name|E5_YSTORM_FCOE_TASK_AG_CTX_RULE1EN_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E5_YSTORM_FCOE_TASK_AG_CTX_RULE1EN_SHIFT
value|2
define|#
directive|define
name|E5_YSTORM_FCOE_TASK_AG_CTX_RULE2EN_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E5_YSTORM_FCOE_TASK_AG_CTX_RULE2EN_SHIFT
value|3
define|#
directive|define
name|E5_YSTORM_FCOE_TASK_AG_CTX_RULE3EN_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E5_YSTORM_FCOE_TASK_AG_CTX_RULE3EN_SHIFT
value|4
define|#
directive|define
name|E5_YSTORM_FCOE_TASK_AG_CTX_RULE4EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E5_YSTORM_FCOE_TASK_AG_CTX_RULE4EN_SHIFT
value|5
define|#
directive|define
name|E5_YSTORM_FCOE_TASK_AG_CTX_RULE5EN_MASK
value|0x1
comment|/* rule5en */
define|#
directive|define
name|E5_YSTORM_FCOE_TASK_AG_CTX_RULE5EN_SHIFT
value|6
define|#
directive|define
name|E5_YSTORM_FCOE_TASK_AG_CTX_RULE6EN_MASK
value|0x1
comment|/* rule6en */
define|#
directive|define
name|E5_YSTORM_FCOE_TASK_AG_CTX_RULE6EN_SHIFT
value|7
name|u8
name|flags3
decl_stmt|;
define|#
directive|define
name|E5_YSTORM_FCOE_TASK_AG_CTX_E4_RESERVED1_MASK
value|0x1
comment|/* bit5 */
define|#
directive|define
name|E5_YSTORM_FCOE_TASK_AG_CTX_E4_RESERVED1_SHIFT
value|0
define|#
directive|define
name|E5_YSTORM_FCOE_TASK_AG_CTX_E4_RESERVED2_MASK
value|0x3
comment|/* cf3 */
define|#
directive|define
name|E5_YSTORM_FCOE_TASK_AG_CTX_E4_RESERVED2_SHIFT
value|1
define|#
directive|define
name|E5_YSTORM_FCOE_TASK_AG_CTX_E4_RESERVED3_MASK
value|0x3
comment|/* cf4 */
define|#
directive|define
name|E5_YSTORM_FCOE_TASK_AG_CTX_E4_RESERVED3_SHIFT
value|3
define|#
directive|define
name|E5_YSTORM_FCOE_TASK_AG_CTX_E4_RESERVED4_MASK
value|0x1
comment|/* cf3en */
define|#
directive|define
name|E5_YSTORM_FCOE_TASK_AG_CTX_E4_RESERVED4_SHIFT
value|5
define|#
directive|define
name|E5_YSTORM_FCOE_TASK_AG_CTX_E4_RESERVED5_MASK
value|0x1
comment|/* cf4en */
define|#
directive|define
name|E5_YSTORM_FCOE_TASK_AG_CTX_E4_RESERVED5_SHIFT
value|6
define|#
directive|define
name|E5_YSTORM_FCOE_TASK_AG_CTX_E4_RESERVED6_MASK
value|0x1
comment|/* rule7en */
define|#
directive|define
name|E5_YSTORM_FCOE_TASK_AG_CTX_E4_RESERVED6_SHIFT
value|7
name|__le32
name|reg0
comment|/* reg0 */
decl_stmt|;
name|u8
name|byte2
comment|/* byte2 */
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
name|e4_reserved7
comment|/* byte5 */
decl_stmt|;
name|__le16
name|rx_id
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
name|__le16
name|word5
comment|/* word5 */
decl_stmt|;
name|__le16
name|e4_reserved8
comment|/* word6 */
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
name|e5_tstorm_fcoe_task_ag_ctx
block|{
name|u8
name|reserved
comment|/* cdu_validation */
decl_stmt|;
name|u8
name|byte1
comment|/* state_and_core_id */
decl_stmt|;
name|__le16
name|icid
comment|/* icid */
decl_stmt|;
name|u8
name|flags0
decl_stmt|;
define|#
directive|define
name|E5_TSTORM_FCOE_TASK_AG_CTX_CONNECTION_TYPE_MASK
value|0xF
comment|/* connection_type */
define|#
directive|define
name|E5_TSTORM_FCOE_TASK_AG_CTX_CONNECTION_TYPE_SHIFT
value|0
define|#
directive|define
name|E5_TSTORM_FCOE_TASK_AG_CTX_EXIST_IN_QM0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E5_TSTORM_FCOE_TASK_AG_CTX_EXIST_IN_QM0_SHIFT
value|4
define|#
directive|define
name|E5_TSTORM_FCOE_TASK_AG_CTX_BIT1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E5_TSTORM_FCOE_TASK_AG_CTX_BIT1_SHIFT
value|5
define|#
directive|define
name|E5_TSTORM_FCOE_TASK_AG_CTX_WAIT_ABTS_RSP_F_MASK
value|0x1
comment|/* bit2 */
define|#
directive|define
name|E5_TSTORM_FCOE_TASK_AG_CTX_WAIT_ABTS_RSP_F_SHIFT
value|6
define|#
directive|define
name|E5_TSTORM_FCOE_TASK_AG_CTX_VALID_MASK
value|0x1
comment|/* bit3 */
define|#
directive|define
name|E5_TSTORM_FCOE_TASK_AG_CTX_VALID_SHIFT
value|7
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E5_TSTORM_FCOE_TASK_AG_CTX_FALSE_RR_TOV_MASK
value|0x1
comment|/* bit4 */
define|#
directive|define
name|E5_TSTORM_FCOE_TASK_AG_CTX_FALSE_RR_TOV_SHIFT
value|0
define|#
directive|define
name|E5_TSTORM_FCOE_TASK_AG_CTX_BIT5_MASK
value|0x1
comment|/* bit5 */
define|#
directive|define
name|E5_TSTORM_FCOE_TASK_AG_CTX_BIT5_SHIFT
value|1
define|#
directive|define
name|E5_TSTORM_FCOE_TASK_AG_CTX_REC_RR_TOV_CF_MASK
value|0x3
comment|/* timer0cf */
define|#
directive|define
name|E5_TSTORM_FCOE_TASK_AG_CTX_REC_RR_TOV_CF_SHIFT
value|2
define|#
directive|define
name|E5_TSTORM_FCOE_TASK_AG_CTX_ED_TOV_CF_MASK
value|0x3
comment|/* timer1cf */
define|#
directive|define
name|E5_TSTORM_FCOE_TASK_AG_CTX_ED_TOV_CF_SHIFT
value|4
define|#
directive|define
name|E5_TSTORM_FCOE_TASK_AG_CTX_CF2_MASK
value|0x3
comment|/* timer2cf */
define|#
directive|define
name|E5_TSTORM_FCOE_TASK_AG_CTX_CF2_SHIFT
value|6
name|u8
name|flags2
decl_stmt|;
define|#
directive|define
name|E5_TSTORM_FCOE_TASK_AG_CTX_TIMER_STOP_ALL_MASK
value|0x3
comment|/* timer_stop_all */
define|#
directive|define
name|E5_TSTORM_FCOE_TASK_AG_CTX_TIMER_STOP_ALL_SHIFT
value|0
define|#
directive|define
name|E5_TSTORM_FCOE_TASK_AG_CTX_EX_CLEANUP_CF_MASK
value|0x3
comment|/* cf4 */
define|#
directive|define
name|E5_TSTORM_FCOE_TASK_AG_CTX_EX_CLEANUP_CF_SHIFT
value|2
define|#
directive|define
name|E5_TSTORM_FCOE_TASK_AG_CTX_SEQ_INIT_CF_MASK
value|0x3
comment|/* cf5 */
define|#
directive|define
name|E5_TSTORM_FCOE_TASK_AG_CTX_SEQ_INIT_CF_SHIFT
value|4
define|#
directive|define
name|E5_TSTORM_FCOE_TASK_AG_CTX_SEQ_RECOVERY_CF_MASK
value|0x3
comment|/* cf6 */
define|#
directive|define
name|E5_TSTORM_FCOE_TASK_AG_CTX_SEQ_RECOVERY_CF_SHIFT
value|6
name|u8
name|flags3
decl_stmt|;
define|#
directive|define
name|E5_TSTORM_FCOE_TASK_AG_CTX_UNSOL_COMP_CF_MASK
value|0x3
comment|/* cf7 */
define|#
directive|define
name|E5_TSTORM_FCOE_TASK_AG_CTX_UNSOL_COMP_CF_SHIFT
value|0
define|#
directive|define
name|E5_TSTORM_FCOE_TASK_AG_CTX_REC_RR_TOV_CF_EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E5_TSTORM_FCOE_TASK_AG_CTX_REC_RR_TOV_CF_EN_SHIFT
value|2
define|#
directive|define
name|E5_TSTORM_FCOE_TASK_AG_CTX_ED_TOV_CF_EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E5_TSTORM_FCOE_TASK_AG_CTX_ED_TOV_CF_EN_SHIFT
value|3
define|#
directive|define
name|E5_TSTORM_FCOE_TASK_AG_CTX_CF2EN_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E5_TSTORM_FCOE_TASK_AG_CTX_CF2EN_SHIFT
value|4
define|#
directive|define
name|E5_TSTORM_FCOE_TASK_AG_CTX_TIMER_STOP_ALL_EN_MASK
value|0x1
comment|/* cf3en */
define|#
directive|define
name|E5_TSTORM_FCOE_TASK_AG_CTX_TIMER_STOP_ALL_EN_SHIFT
value|5
define|#
directive|define
name|E5_TSTORM_FCOE_TASK_AG_CTX_EX_CLEANUP_CF_EN_MASK
value|0x1
comment|/* cf4en */
define|#
directive|define
name|E5_TSTORM_FCOE_TASK_AG_CTX_EX_CLEANUP_CF_EN_SHIFT
value|6
define|#
directive|define
name|E5_TSTORM_FCOE_TASK_AG_CTX_SEQ_INIT_CF_EN_MASK
value|0x1
comment|/* cf5en */
define|#
directive|define
name|E5_TSTORM_FCOE_TASK_AG_CTX_SEQ_INIT_CF_EN_SHIFT
value|7
name|u8
name|flags4
decl_stmt|;
define|#
directive|define
name|E5_TSTORM_FCOE_TASK_AG_CTX_SEQ_RECOVERY_CF_EN_MASK
value|0x1
comment|/* cf6en */
define|#
directive|define
name|E5_TSTORM_FCOE_TASK_AG_CTX_SEQ_RECOVERY_CF_EN_SHIFT
value|0
define|#
directive|define
name|E5_TSTORM_FCOE_TASK_AG_CTX_UNSOL_COMP_CF_EN_MASK
value|0x1
comment|/* cf7en */
define|#
directive|define
name|E5_TSTORM_FCOE_TASK_AG_CTX_UNSOL_COMP_CF_EN_SHIFT
value|1
define|#
directive|define
name|E5_TSTORM_FCOE_TASK_AG_CTX_RULE0EN_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E5_TSTORM_FCOE_TASK_AG_CTX_RULE0EN_SHIFT
value|2
define|#
directive|define
name|E5_TSTORM_FCOE_TASK_AG_CTX_RULE1EN_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E5_TSTORM_FCOE_TASK_AG_CTX_RULE1EN_SHIFT
value|3
define|#
directive|define
name|E5_TSTORM_FCOE_TASK_AG_CTX_RULE2EN_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E5_TSTORM_FCOE_TASK_AG_CTX_RULE2EN_SHIFT
value|4
define|#
directive|define
name|E5_TSTORM_FCOE_TASK_AG_CTX_RULE3EN_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E5_TSTORM_FCOE_TASK_AG_CTX_RULE3EN_SHIFT
value|5
define|#
directive|define
name|E5_TSTORM_FCOE_TASK_AG_CTX_RULE4EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E5_TSTORM_FCOE_TASK_AG_CTX_RULE4EN_SHIFT
value|6
define|#
directive|define
name|E5_TSTORM_FCOE_TASK_AG_CTX_RULE5EN_MASK
value|0x1
comment|/* rule5en */
define|#
directive|define
name|E5_TSTORM_FCOE_TASK_AG_CTX_RULE5EN_SHIFT
value|7
name|u8
name|cleanup_state
comment|/* byte2 */
decl_stmt|;
name|__le16
name|last_sent_tid
comment|/* word1 */
decl_stmt|;
name|__le32
name|rec_rr_tov_exp_timeout
comment|/* reg0 */
decl_stmt|;
name|u8
name|byte3
comment|/* regpair0 */
decl_stmt|;
name|u8
name|byte4
comment|/* byte4 */
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
name|data_offset_end_of_seq
comment|/* regpair1 */
decl_stmt|;
name|__le32
name|data_offset_next
comment|/* reg2 */
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|e5_mstorm_fcoe_task_ag_ctx
block|{
name|u8
name|byte0
comment|/* cdu_validation */
decl_stmt|;
name|u8
name|byte1
comment|/* state_and_core_id */
decl_stmt|;
name|__le16
name|icid
comment|/* icid */
decl_stmt|;
name|u8
name|flags0
decl_stmt|;
define|#
directive|define
name|E5_MSTORM_FCOE_TASK_AG_CTX_CONNECTION_TYPE_MASK
value|0xF
comment|/* connection_type */
define|#
directive|define
name|E5_MSTORM_FCOE_TASK_AG_CTX_CONNECTION_TYPE_SHIFT
value|0
define|#
directive|define
name|E5_MSTORM_FCOE_TASK_AG_CTX_EXIST_IN_QM0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E5_MSTORM_FCOE_TASK_AG_CTX_EXIST_IN_QM0_SHIFT
value|4
define|#
directive|define
name|E5_MSTORM_FCOE_TASK_AG_CTX_CQE_PLACED_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E5_MSTORM_FCOE_TASK_AG_CTX_CQE_PLACED_SHIFT
value|5
define|#
directive|define
name|E5_MSTORM_FCOE_TASK_AG_CTX_BIT2_MASK
value|0x1
comment|/* bit2 */
define|#
directive|define
name|E5_MSTORM_FCOE_TASK_AG_CTX_BIT2_SHIFT
value|6
define|#
directive|define
name|E5_MSTORM_FCOE_TASK_AG_CTX_BIT3_MASK
value|0x1
comment|/* bit3 */
define|#
directive|define
name|E5_MSTORM_FCOE_TASK_AG_CTX_BIT3_SHIFT
value|7
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E5_MSTORM_FCOE_TASK_AG_CTX_EX_CLEANUP_CF_MASK
value|0x3
comment|/* cf0 */
define|#
directive|define
name|E5_MSTORM_FCOE_TASK_AG_CTX_EX_CLEANUP_CF_SHIFT
value|0
define|#
directive|define
name|E5_MSTORM_FCOE_TASK_AG_CTX_CF1_MASK
value|0x3
comment|/* cf1 */
define|#
directive|define
name|E5_MSTORM_FCOE_TASK_AG_CTX_CF1_SHIFT
value|2
define|#
directive|define
name|E5_MSTORM_FCOE_TASK_AG_CTX_CF2_MASK
value|0x3
comment|/* cf2 */
define|#
directive|define
name|E5_MSTORM_FCOE_TASK_AG_CTX_CF2_SHIFT
value|4
define|#
directive|define
name|E5_MSTORM_FCOE_TASK_AG_CTX_EX_CLEANUP_CF_EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E5_MSTORM_FCOE_TASK_AG_CTX_EX_CLEANUP_CF_EN_SHIFT
value|6
define|#
directive|define
name|E5_MSTORM_FCOE_TASK_AG_CTX_CF1EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E5_MSTORM_FCOE_TASK_AG_CTX_CF1EN_SHIFT
value|7
name|u8
name|flags2
decl_stmt|;
define|#
directive|define
name|E5_MSTORM_FCOE_TASK_AG_CTX_CF2EN_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E5_MSTORM_FCOE_TASK_AG_CTX_CF2EN_SHIFT
value|0
define|#
directive|define
name|E5_MSTORM_FCOE_TASK_AG_CTX_RULE0EN_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E5_MSTORM_FCOE_TASK_AG_CTX_RULE0EN_SHIFT
value|1
define|#
directive|define
name|E5_MSTORM_FCOE_TASK_AG_CTX_RULE1EN_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E5_MSTORM_FCOE_TASK_AG_CTX_RULE1EN_SHIFT
value|2
define|#
directive|define
name|E5_MSTORM_FCOE_TASK_AG_CTX_RULE2EN_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E5_MSTORM_FCOE_TASK_AG_CTX_RULE2EN_SHIFT
value|3
define|#
directive|define
name|E5_MSTORM_FCOE_TASK_AG_CTX_RULE3EN_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E5_MSTORM_FCOE_TASK_AG_CTX_RULE3EN_SHIFT
value|4
define|#
directive|define
name|E5_MSTORM_FCOE_TASK_AG_CTX_RULE4EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E5_MSTORM_FCOE_TASK_AG_CTX_RULE4EN_SHIFT
value|5
define|#
directive|define
name|E5_MSTORM_FCOE_TASK_AG_CTX_XFER_PLACEMENT_EN_MASK
value|0x1
comment|/* rule5en */
define|#
directive|define
name|E5_MSTORM_FCOE_TASK_AG_CTX_XFER_PLACEMENT_EN_SHIFT
value|6
define|#
directive|define
name|E5_MSTORM_FCOE_TASK_AG_CTX_RULE6EN_MASK
value|0x1
comment|/* rule6en */
define|#
directive|define
name|E5_MSTORM_FCOE_TASK_AG_CTX_RULE6EN_SHIFT
value|7
name|u8
name|flags3
decl_stmt|;
define|#
directive|define
name|E5_MSTORM_FCOE_TASK_AG_CTX_E4_RESERVED1_MASK
value|0x1
comment|/* bit4 */
define|#
directive|define
name|E5_MSTORM_FCOE_TASK_AG_CTX_E4_RESERVED1_SHIFT
value|0
define|#
directive|define
name|E5_MSTORM_FCOE_TASK_AG_CTX_E4_RESERVED2_MASK
value|0x3
comment|/* cf3 */
define|#
directive|define
name|E5_MSTORM_FCOE_TASK_AG_CTX_E4_RESERVED2_SHIFT
value|1
define|#
directive|define
name|E5_MSTORM_FCOE_TASK_AG_CTX_E4_RESERVED3_MASK
value|0x3
comment|/* cf4 */
define|#
directive|define
name|E5_MSTORM_FCOE_TASK_AG_CTX_E4_RESERVED3_SHIFT
value|3
define|#
directive|define
name|E5_MSTORM_FCOE_TASK_AG_CTX_E4_RESERVED4_MASK
value|0x1
comment|/* cf3en */
define|#
directive|define
name|E5_MSTORM_FCOE_TASK_AG_CTX_E4_RESERVED4_SHIFT
value|5
define|#
directive|define
name|E5_MSTORM_FCOE_TASK_AG_CTX_E4_RESERVED5_MASK
value|0x1
comment|/* cf4en */
define|#
directive|define
name|E5_MSTORM_FCOE_TASK_AG_CTX_E4_RESERVED5_SHIFT
value|6
define|#
directive|define
name|E5_MSTORM_FCOE_TASK_AG_CTX_E4_RESERVED6_MASK
value|0x1
comment|/* rule7en */
define|#
directive|define
name|E5_MSTORM_FCOE_TASK_AG_CTX_E4_RESERVED6_SHIFT
value|7
name|__le32
name|received_bytes
comment|/* reg0 */
decl_stmt|;
name|u8
name|cleanup_state
comment|/* byte2 */
decl_stmt|;
name|u8
name|byte3
comment|/* byte3 */
decl_stmt|;
name|u8
name|glbl_q_num
comment|/* byte4 */
decl_stmt|;
name|u8
name|e4_reserved7
comment|/* byte5 */
decl_stmt|;
name|__le16
name|word1
comment|/* regpair0 */
decl_stmt|;
name|__le16
name|tid_to_xfer
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
name|__le16
name|word5
comment|/* regpair1 */
decl_stmt|;
name|__le16
name|e4_reserved8
comment|/* word6 */
decl_stmt|;
name|__le32
name|expected_bytes
comment|/* reg1 */
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|e5_ustorm_fcoe_task_ag_ctx
block|{
name|u8
name|reserved
comment|/* cdu_validation */
decl_stmt|;
name|u8
name|byte1
comment|/* state_and_core_id */
decl_stmt|;
name|__le16
name|icid
comment|/* icid */
decl_stmt|;
name|u8
name|flags0
decl_stmt|;
define|#
directive|define
name|E5_USTORM_FCOE_TASK_AG_CTX_CONNECTION_TYPE_MASK
value|0xF
comment|/* connection_type */
define|#
directive|define
name|E5_USTORM_FCOE_TASK_AG_CTX_CONNECTION_TYPE_SHIFT
value|0
define|#
directive|define
name|E5_USTORM_FCOE_TASK_AG_CTX_EXIST_IN_QM0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E5_USTORM_FCOE_TASK_AG_CTX_EXIST_IN_QM0_SHIFT
value|4
define|#
directive|define
name|E5_USTORM_FCOE_TASK_AG_CTX_BIT1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E5_USTORM_FCOE_TASK_AG_CTX_BIT1_SHIFT
value|5
define|#
directive|define
name|E5_USTORM_FCOE_TASK_AG_CTX_CF0_MASK
value|0x3
comment|/* timer0cf */
define|#
directive|define
name|E5_USTORM_FCOE_TASK_AG_CTX_CF0_SHIFT
value|6
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E5_USTORM_FCOE_TASK_AG_CTX_CF1_MASK
value|0x3
comment|/* timer1cf */
define|#
directive|define
name|E5_USTORM_FCOE_TASK_AG_CTX_CF1_SHIFT
value|0
define|#
directive|define
name|E5_USTORM_FCOE_TASK_AG_CTX_CF2_MASK
value|0x3
comment|/* timer2cf */
define|#
directive|define
name|E5_USTORM_FCOE_TASK_AG_CTX_CF2_SHIFT
value|2
define|#
directive|define
name|E5_USTORM_FCOE_TASK_AG_CTX_CF3_MASK
value|0x3
comment|/* timer_stop_all */
define|#
directive|define
name|E5_USTORM_FCOE_TASK_AG_CTX_CF3_SHIFT
value|4
define|#
directive|define
name|E5_USTORM_FCOE_TASK_AG_CTX_DIF_ERROR_CF_MASK
value|0x3
comment|/* dif_error_cf */
define|#
directive|define
name|E5_USTORM_FCOE_TASK_AG_CTX_DIF_ERROR_CF_SHIFT
value|6
name|u8
name|flags2
decl_stmt|;
define|#
directive|define
name|E5_USTORM_FCOE_TASK_AG_CTX_CF0EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E5_USTORM_FCOE_TASK_AG_CTX_CF0EN_SHIFT
value|0
define|#
directive|define
name|E5_USTORM_FCOE_TASK_AG_CTX_CF1EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E5_USTORM_FCOE_TASK_AG_CTX_CF1EN_SHIFT
value|1
define|#
directive|define
name|E5_USTORM_FCOE_TASK_AG_CTX_CF2EN_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E5_USTORM_FCOE_TASK_AG_CTX_CF2EN_SHIFT
value|2
define|#
directive|define
name|E5_USTORM_FCOE_TASK_AG_CTX_CF3EN_MASK
value|0x1
comment|/* cf3en */
define|#
directive|define
name|E5_USTORM_FCOE_TASK_AG_CTX_CF3EN_SHIFT
value|3
define|#
directive|define
name|E5_USTORM_FCOE_TASK_AG_CTX_DIF_ERROR_CF_EN_MASK
value|0x1
comment|/* cf4en */
define|#
directive|define
name|E5_USTORM_FCOE_TASK_AG_CTX_DIF_ERROR_CF_EN_SHIFT
value|4
define|#
directive|define
name|E5_USTORM_FCOE_TASK_AG_CTX_RULE0EN_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E5_USTORM_FCOE_TASK_AG_CTX_RULE0EN_SHIFT
value|5
define|#
directive|define
name|E5_USTORM_FCOE_TASK_AG_CTX_RULE1EN_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E5_USTORM_FCOE_TASK_AG_CTX_RULE1EN_SHIFT
value|6
define|#
directive|define
name|E5_USTORM_FCOE_TASK_AG_CTX_RULE2EN_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E5_USTORM_FCOE_TASK_AG_CTX_RULE2EN_SHIFT
value|7
name|u8
name|flags3
decl_stmt|;
define|#
directive|define
name|E5_USTORM_FCOE_TASK_AG_CTX_RULE3EN_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E5_USTORM_FCOE_TASK_AG_CTX_RULE3EN_SHIFT
value|0
define|#
directive|define
name|E5_USTORM_FCOE_TASK_AG_CTX_RULE4EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E5_USTORM_FCOE_TASK_AG_CTX_RULE4EN_SHIFT
value|1
define|#
directive|define
name|E5_USTORM_FCOE_TASK_AG_CTX_RULE5EN_MASK
value|0x1
comment|/* rule5en */
define|#
directive|define
name|E5_USTORM_FCOE_TASK_AG_CTX_RULE5EN_SHIFT
value|2
define|#
directive|define
name|E5_USTORM_FCOE_TASK_AG_CTX_RULE6EN_MASK
value|0x1
comment|/* rule6en */
define|#
directive|define
name|E5_USTORM_FCOE_TASK_AG_CTX_RULE6EN_SHIFT
value|3
define|#
directive|define
name|E5_USTORM_FCOE_TASK_AG_CTX_E4_RESERVED1_MASK
value|0x1
comment|/* bit2 */
define|#
directive|define
name|E5_USTORM_FCOE_TASK_AG_CTX_E4_RESERVED1_SHIFT
value|4
define|#
directive|define
name|E5_USTORM_FCOE_TASK_AG_CTX_E4_RESERVED2_MASK
value|0x1
comment|/* bit3 */
define|#
directive|define
name|E5_USTORM_FCOE_TASK_AG_CTX_E4_RESERVED2_SHIFT
value|5
define|#
directive|define
name|E5_USTORM_FCOE_TASK_AG_CTX_E4_RESERVED3_MASK
value|0x1
comment|/* bit4 */
define|#
directive|define
name|E5_USTORM_FCOE_TASK_AG_CTX_E4_RESERVED3_SHIFT
value|6
define|#
directive|define
name|E5_USTORM_FCOE_TASK_AG_CTX_E4_RESERVED4_MASK
value|0x1
comment|/* rule7en */
define|#
directive|define
name|E5_USTORM_FCOE_TASK_AG_CTX_E4_RESERVED4_SHIFT
value|7
name|u8
name|flags4
decl_stmt|;
define|#
directive|define
name|E5_USTORM_FCOE_TASK_AG_CTX_E4_RESERVED5_MASK
value|0x3
comment|/* cf5 */
define|#
directive|define
name|E5_USTORM_FCOE_TASK_AG_CTX_E4_RESERVED5_SHIFT
value|0
define|#
directive|define
name|E5_USTORM_FCOE_TASK_AG_CTX_E4_RESERVED6_MASK
value|0x1
comment|/* cf5en */
define|#
directive|define
name|E5_USTORM_FCOE_TASK_AG_CTX_E4_RESERVED6_SHIFT
value|2
define|#
directive|define
name|E5_USTORM_FCOE_TASK_AG_CTX_E4_RESERVED7_MASK
value|0x1
comment|/* rule8en */
define|#
directive|define
name|E5_USTORM_FCOE_TASK_AG_CTX_E4_RESERVED7_SHIFT
value|3
define|#
directive|define
name|E5_USTORM_FCOE_TASK_AG_CTX_DIF_ERROR_TYPE_MASK
value|0xF
comment|/* dif_error_type */
define|#
directive|define
name|E5_USTORM_FCOE_TASK_AG_CTX_DIF_ERROR_TYPE_SHIFT
value|4
name|u8
name|byte2
comment|/* byte2 */
decl_stmt|;
name|u8
name|byte3
comment|/* byte3 */
decl_stmt|;
name|u8
name|e4_reserved8
comment|/* byte4 */
decl_stmt|;
name|__le32
name|dif_err_intervals
comment|/* dif_err_intervals */
decl_stmt|;
name|__le32
name|dif_error_1st_interval
comment|/* dif_error_1st_interval */
decl_stmt|;
name|__le32
name|global_cq_num
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
block|}
struct|;
end_struct

begin_comment
comment|/*  * fcoe task context  */
end_comment

begin_struct
struct|struct
name|e5_fcoe_task_context
block|{
name|struct
name|ystorm_fcoe_task_st_ctx
name|ystorm_st_context
comment|/* ystorm storm context */
decl_stmt|;
name|struct
name|regpair
name|ystorm_st_padding
index|[
literal|2
index|]
comment|/* padding */
decl_stmt|;
name|struct
name|tdif_task_context
name|tdif_context
comment|/* tdif context */
decl_stmt|;
name|struct
name|e5_ystorm_fcoe_task_ag_ctx
name|ystorm_ag_context
comment|/* ystorm aggregative context */
decl_stmt|;
name|struct
name|e5_tstorm_fcoe_task_ag_ctx
name|tstorm_ag_context
comment|/* tstorm aggregative context */
decl_stmt|;
name|struct
name|timers_context
name|timer_context
comment|/* timer context */
decl_stmt|;
name|struct
name|tstorm_fcoe_task_st_ctx
name|tstorm_st_context
comment|/* tstorm storm context */
decl_stmt|;
name|struct
name|regpair
name|tstorm_st_padding
index|[
literal|2
index|]
comment|/* padding */
decl_stmt|;
name|struct
name|e5_mstorm_fcoe_task_ag_ctx
name|mstorm_ag_context
comment|/* mstorm aggregative context */
decl_stmt|;
name|struct
name|mstorm_fcoe_task_st_ctx
name|mstorm_st_context
comment|/* mstorm storm context */
decl_stmt|;
name|struct
name|e5_ustorm_fcoe_task_ag_ctx
name|ustorm_ag_context
comment|/* ustorm aggregative context */
decl_stmt|;
name|struct
name|rdif_task_context
name|rdif_context
comment|/* rdif context */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * FCoE additional WQE (Sq/ XferQ) information  */
end_comment

begin_union
union|union
name|fcoe_additional_info_union
block|{
name|__le32
name|previous_tid
comment|/* Previous tid. Used for Send XFER WQEs in Multiple continuation mode - Target only. */
decl_stmt|;
name|__le32
name|parent_tid
comment|/* Parent tid. Used for write tasks in a continuation mode - Target only */
decl_stmt|;
name|__le32
name|burst_length
comment|/* The desired burst length. */
decl_stmt|;
name|__le32
name|seq_rec_updated_offset
comment|/* The updated offset in SGL - Used in sequence recovery */
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/*  * FCoE Ramrod Command IDs   */
end_comment

begin_enum
enum|enum
name|fcoe_completion_status
block|{
name|FCOE_COMPLETION_STATUS_SUCCESS
comment|/* FCoE ramrod completed successfully */
block|,
name|FCOE_COMPLETION_STATUS_FCOE_VER_ERR
comment|/* Wrong FCoE version */
block|,
name|FCOE_COMPLETION_STATUS_SRC_MAC_ADD_ARR_ERR
comment|/* src_mac_arr for the current physical port is full- allocation failed */
block|,
name|MAX_FCOE_COMPLETION_STATUS
block|}
enum|;
end_enum

begin_comment
comment|/*  * FC address (SID/DID) network presentation   */
end_comment

begin_struct
struct|struct
name|fc_addr_nw
block|{
name|u8
name|addr_lo
comment|/* First byte of the SID/DID address that comes/goes from/to the NW (for example if SID is 11:22:33 - this is 0x11) */
decl_stmt|;
name|u8
name|addr_mid
decl_stmt|;
name|u8
name|addr_hi
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * FCoE connection offload  */
end_comment

begin_struct
struct|struct
name|fcoe_conn_offload_ramrod_data
block|{
name|struct
name|regpair
name|sq_pbl_addr
comment|/* SQ Pbl base address */
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
comment|/* XFERQ Pbl base address */
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
comment|/* RESPQ Pbl base address */
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
name|dst_mac_addr_lo
comment|/* First word of the MAC address that comes/goes from/to the NW (for example if MAC is 11:22:33:44:55:66 - this is 0x2211) */
decl_stmt|;
name|__le16
name|dst_mac_addr_mid
decl_stmt|;
name|__le16
name|dst_mac_addr_hi
decl_stmt|;
name|__le16
name|src_mac_addr_lo
comment|/* Source MAC address in NW order - First word of the MAC address that comes/goes from/to the NW (for example if MAC is 11:22:33:44:55:66 - this is 0x2211) */
decl_stmt|;
name|__le16
name|src_mac_addr_mid
decl_stmt|;
name|__le16
name|src_mac_addr_hi
decl_stmt|;
name|__le16
name|tx_max_fc_pay_len
comment|/* The maximum acceptable FC payload size (Buffer-to-buffer Receive Data_Field size) supported by target, received during both FLOGI and PLOGI, minimum value should be taken */
decl_stmt|;
name|__le16
name|e_d_tov_timer_val
comment|/* E_D_TOV timeout value in resolution of 1 msec */
decl_stmt|;
name|__le16
name|rx_max_fc_pay_len
comment|/* Maximum acceptable FC payload size supported by us */
decl_stmt|;
name|__le16
name|vlan_tag
decl_stmt|;
define|#
directive|define
name|FCOE_CONN_OFFLOAD_RAMROD_DATA_VLAN_ID_MASK
value|0xFFF
comment|/* Vlan id */
define|#
directive|define
name|FCOE_CONN_OFFLOAD_RAMROD_DATA_VLAN_ID_SHIFT
value|0
define|#
directive|define
name|FCOE_CONN_OFFLOAD_RAMROD_DATA_CFI_MASK
value|0x1
comment|/* Canonical format indicator */
define|#
directive|define
name|FCOE_CONN_OFFLOAD_RAMROD_DATA_CFI_SHIFT
value|12
define|#
directive|define
name|FCOE_CONN_OFFLOAD_RAMROD_DATA_PRIORITY_MASK
value|0x7
comment|/* Vlan priority */
define|#
directive|define
name|FCOE_CONN_OFFLOAD_RAMROD_DATA_PRIORITY_SHIFT
value|13
name|__le16
name|physical_q0
comment|/* Physical QM queue to be linked to logical queue 0 (fastPath queue) */
decl_stmt|;
name|__le16
name|rec_rr_tov_timer_val
comment|/* REC_TOV timeout value in resolution of 1 msec  */
decl_stmt|;
name|struct
name|fc_addr_nw
name|s_id
comment|/* Source ID in NW order, received during FLOGI */
decl_stmt|;
name|u8
name|max_conc_seqs_c3
comment|/* Maximum concurrent Sequences for Class 3 supported by target, received during PLOGI */
decl_stmt|;
name|struct
name|fc_addr_nw
name|d_id
comment|/* Destination ID in NW order, received after inquiry of the fabric network */
decl_stmt|;
name|u8
name|flags
decl_stmt|;
define|#
directive|define
name|FCOE_CONN_OFFLOAD_RAMROD_DATA_B_CONT_INCR_SEQ_CNT_MASK
value|0x1
comment|/* Continuously increasing SEQ_CNT indication, received during PLOGI */
define|#
directive|define
name|FCOE_CONN_OFFLOAD_RAMROD_DATA_B_CONT_INCR_SEQ_CNT_SHIFT
value|0
define|#
directive|define
name|FCOE_CONN_OFFLOAD_RAMROD_DATA_B_CONF_REQ_MASK
value|0x1
comment|/* Confirmation request supported */
define|#
directive|define
name|FCOE_CONN_OFFLOAD_RAMROD_DATA_B_CONF_REQ_SHIFT
value|1
define|#
directive|define
name|FCOE_CONN_OFFLOAD_RAMROD_DATA_B_REC_VALID_MASK
value|0x1
comment|/* REC allowed */
define|#
directive|define
name|FCOE_CONN_OFFLOAD_RAMROD_DATA_B_REC_VALID_SHIFT
value|2
define|#
directive|define
name|FCOE_CONN_OFFLOAD_RAMROD_DATA_B_VLAN_FLAG_MASK
value|0x1
comment|/* Does inner vlan exist */
define|#
directive|define
name|FCOE_CONN_OFFLOAD_RAMROD_DATA_B_VLAN_FLAG_SHIFT
value|3
define|#
directive|define
name|FCOE_CONN_OFFLOAD_RAMROD_DATA_MODE_MASK
value|0x3
comment|/* indication for conn mode: 0=Initiator, 1=Target, 2=Both Initiator and Traget */
define|#
directive|define
name|FCOE_CONN_OFFLOAD_RAMROD_DATA_MODE_SHIFT
value|4
define|#
directive|define
name|FCOE_CONN_OFFLOAD_RAMROD_DATA_RESERVED0_MASK
value|0x3
define|#
directive|define
name|FCOE_CONN_OFFLOAD_RAMROD_DATA_RESERVED0_SHIFT
value|6
name|__le16
name|conn_id
comment|/* Drivers connection ID. Should be sent in EQs to speed-up drivers access to connection data. */
decl_stmt|;
name|u8
name|def_q_idx
comment|/* Default queue number to be used for unsolicited traffic */
decl_stmt|;
name|u8
name|reserved
index|[
literal|5
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * FCoE terminate connection request   */
end_comment

begin_struct
struct|struct
name|fcoe_conn_terminate_ramrod_data
block|{
name|struct
name|regpair
name|terminate_params_addr
comment|/* Terminate params ptr */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Data sgl  */
end_comment

begin_struct
struct|struct
name|fcoe_fast_sgl_ctx
block|{
name|struct
name|regpair
name|sgl_start_addr
comment|/* Current sge address */
decl_stmt|;
name|__le32
name|sgl_byte_offset
comment|/* Byte offset from the beginning of the first page in the SGL. In case SGL starts in the middle of page then driver should init this value with the start offset */
decl_stmt|;
name|__le16
name|task_reuse_cnt
comment|/* The reuse count for that task. Wrap ion 4K value. */
decl_stmt|;
name|__le16
name|init_offset_in_first_sge
comment|/* offset from the beginning of the first page in the SGL, never changed by FW */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * FCoE firmware function init  */
end_comment

begin_struct
struct|struct
name|fcoe_init_func_ramrod_data
block|{
name|struct
name|scsi_init_func_params
name|func_params
comment|/* Common SCSI init params passed by driver to FW in function init ramrod */
decl_stmt|;
name|struct
name|scsi_init_func_queues
name|q_params
comment|/* SCSI RQ/CQ/CMDQ firmware function init parameters */
decl_stmt|;
name|__le16
name|mtu
comment|/* Max transmission unit */
decl_stmt|;
name|__le16
name|sq_num_pages_in_pbl
comment|/* Number of pages at Send Queue */
decl_stmt|;
name|__le32
name|reserved
index|[
literal|3
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * FCoE: Mode of the connection: Target or Initiator or both  */
end_comment

begin_enum
enum|enum
name|fcoe_mode_type
block|{
name|FCOE_INITIATOR_MODE
init|=
literal|0x0
block|,
name|FCOE_TARGET_MODE
init|=
literal|0x1
block|,
name|FCOE_BOTH_OR_NOT_CHOSEN
init|=
literal|0x3
block|,
name|MAX_FCOE_MODE_TYPE
block|}
enum|;
end_enum

begin_comment
comment|/*  * Per PF FCoE receive path statistics - tStorm RAM structure  */
end_comment

begin_struct
struct|struct
name|fcoe_rx_stat
block|{
name|struct
name|regpair
name|fcoe_rx_byte_cnt
comment|/* Number of FCoE bytes that were received */
decl_stmt|;
name|struct
name|regpair
name|fcoe_rx_data_pkt_cnt
comment|/* Number of FCoE FCP DATA packets that were received */
decl_stmt|;
name|struct
name|regpair
name|fcoe_rx_xfer_pkt_cnt
comment|/* Number of FCoE FCP XFER RDY packets that were received */
decl_stmt|;
name|struct
name|regpair
name|fcoe_rx_other_pkt_cnt
comment|/* Number of FCoE packets which are not DATA/XFER_RDY that were received */
decl_stmt|;
name|__le32
name|fcoe_silent_drop_pkt_cmdq_full_cnt
comment|/* Number of packets that were silently dropped since CMDQ was full */
decl_stmt|;
name|__le32
name|fcoe_silent_drop_pkt_rq_full_cnt
comment|/* Number of packets that were silently dropped since RQ (BDQ) was full */
decl_stmt|;
name|__le32
name|fcoe_silent_drop_pkt_crc_error_cnt
comment|/* Number of packets that were silently dropped due to FC CRC error */
decl_stmt|;
name|__le32
name|fcoe_silent_drop_pkt_task_invalid_cnt
comment|/* Number of packets that were silently dropped since task was not valid */
decl_stmt|;
name|__le32
name|fcoe_silent_drop_total_pkt_cnt
comment|/* Number of FCoE packets that were silently dropped */
decl_stmt|;
name|__le32
name|rsrv
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * FCoe statistics request   */
end_comment

begin_struct
struct|struct
name|fcoe_stat_ramrod_data
block|{
name|struct
name|regpair
name|stat_params_addr
comment|/* Statistics host address */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Per PF FCoE transmit path statistics - pStorm RAM structure  */
end_comment

begin_struct
struct|struct
name|fcoe_tx_stat
block|{
name|struct
name|regpair
name|fcoe_tx_byte_cnt
comment|/* Transmitted FCoE bytes count */
decl_stmt|;
name|struct
name|regpair
name|fcoe_tx_data_pkt_cnt
comment|/* Transmitted FCoE FCP DATA packets count */
decl_stmt|;
name|struct
name|regpair
name|fcoe_tx_xfer_pkt_cnt
comment|/* Transmitted FCoE XFER_RDY packets count */
decl_stmt|;
name|struct
name|regpair
name|fcoe_tx_other_pkt_cnt
comment|/* Transmitted FCoE packets which are not DATA/XFER_RDY count */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * FCoE SQ/XferQ element   */
end_comment

begin_struct
struct|struct
name|fcoe_wqe
block|{
name|__le16
name|task_id
comment|/* Initiator - The task identifier (OX_ID). Target - Continuation tid or RX_ID in non-continuation mode */
decl_stmt|;
name|__le16
name|flags
decl_stmt|;
define|#
directive|define
name|FCOE_WQE_REQ_TYPE_MASK
value|0xF
comment|/* Type of the wqe request. use enum fcoe_sqe_request_type  (use enum fcoe_sqe_request_type) */
define|#
directive|define
name|FCOE_WQE_REQ_TYPE_SHIFT
value|0
define|#
directive|define
name|FCOE_WQE_SGL_MODE_MASK
value|0x1
comment|/* The driver will give a hint about sizes of SGEs for better credits evaluation at Xstorm. use enum scsi_sgl_mode (use enum scsi_sgl_mode) */
define|#
directive|define
name|FCOE_WQE_SGL_MODE_SHIFT
value|4
define|#
directive|define
name|FCOE_WQE_CONTINUATION_MASK
value|0x1
comment|/* Indication if this wqe is a continuation to an existing task (Target only) */
define|#
directive|define
name|FCOE_WQE_CONTINUATION_SHIFT
value|5
define|#
directive|define
name|FCOE_WQE_SEND_AUTO_RSP_MASK
value|0x1
comment|/* Indication to FW to send FCP_RSP after all data was sent - Target only */
define|#
directive|define
name|FCOE_WQE_SEND_AUTO_RSP_SHIFT
value|6
define|#
directive|define
name|FCOE_WQE_RESERVED_MASK
value|0x1
define|#
directive|define
name|FCOE_WQE_RESERVED_SHIFT
value|7
define|#
directive|define
name|FCOE_WQE_NUM_SGES_MASK
value|0xF
comment|/* Number of SGEs. 8 = at least 8 sges */
define|#
directive|define
name|FCOE_WQE_NUM_SGES_SHIFT
value|8
define|#
directive|define
name|FCOE_WQE_RESERVED1_MASK
value|0xF
define|#
directive|define
name|FCOE_WQE_RESERVED1_SHIFT
value|12
name|union
name|fcoe_additional_info_union
name|additional_info_union
comment|/* Additional wqe information (if needed) */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * FCoE XFRQ element   */
end_comment

begin_struct
struct|struct
name|xfrqe_prot_flags
block|{
name|u8
name|flags
decl_stmt|;
define|#
directive|define
name|XFRQE_PROT_FLAGS_PROT_INTERVAL_SIZE_LOG_MASK
value|0xF
comment|/* Protection log interval (9=512 10=1024  11=2048 12=4096 13=8192) */
define|#
directive|define
name|XFRQE_PROT_FLAGS_PROT_INTERVAL_SIZE_LOG_SHIFT
value|0
define|#
directive|define
name|XFRQE_PROT_FLAGS_DIF_TO_PEER_MASK
value|0x1
comment|/* If DIF protection is configured against target (0=no, 1=yes) */
define|#
directive|define
name|XFRQE_PROT_FLAGS_DIF_TO_PEER_SHIFT
value|4
define|#
directive|define
name|XFRQE_PROT_FLAGS_HOST_INTERFACE_MASK
value|0x3
comment|/* If DIF/DIX protection is configured against the host (0=none, 1=DIF, 2=DIX) */
define|#
directive|define
name|XFRQE_PROT_FLAGS_HOST_INTERFACE_SHIFT
value|5
define|#
directive|define
name|XFRQE_PROT_FLAGS_RESERVED_MASK
value|0x1
comment|/* Must set to 0 */
define|#
directive|define
name|XFRQE_PROT_FLAGS_RESERVED_SHIFT
value|7
block|}
struct|;
end_struct

begin_comment
comment|/*  * FCoE doorbell data  */
end_comment

begin_struct
struct|struct
name|fcoe_db_data
block|{
name|u8
name|params
decl_stmt|;
define|#
directive|define
name|FCOE_DB_DATA_DEST_MASK
value|0x3
comment|/* destination of doorbell (use enum db_dest) */
define|#
directive|define
name|FCOE_DB_DATA_DEST_SHIFT
value|0
define|#
directive|define
name|FCOE_DB_DATA_AGG_CMD_MASK
value|0x3
comment|/* aggregative command to CM (use enum db_agg_cmd_sel) */
define|#
directive|define
name|FCOE_DB_DATA_AGG_CMD_SHIFT
value|2
define|#
directive|define
name|FCOE_DB_DATA_BYPASS_EN_MASK
value|0x1
comment|/* enable QM bypass */
define|#
directive|define
name|FCOE_DB_DATA_BYPASS_EN_SHIFT
value|4
define|#
directive|define
name|FCOE_DB_DATA_RESERVED_MASK
value|0x1
define|#
directive|define
name|FCOE_DB_DATA_RESERVED_SHIFT
value|5
define|#
directive|define
name|FCOE_DB_DATA_AGG_VAL_SEL_MASK
value|0x3
comment|/* aggregative value selection */
define|#
directive|define
name|FCOE_DB_DATA_AGG_VAL_SEL_SHIFT
value|6
name|u8
name|agg_flags
comment|/* bit for every DQ counter flags in CM context that DQ can increment */
decl_stmt|;
name|__le16
name|sq_prod
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __FCOE_COMMON__ */
end_comment

end_unit

