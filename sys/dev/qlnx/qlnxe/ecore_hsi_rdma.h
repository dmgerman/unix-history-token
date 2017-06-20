begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2017-2018 Cavium, Inc.   * All rights reserved.  *  *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *  *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *  *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  *  POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ECORE_HSI_RDMA__
end_ifndef

begin_define
define|#
directive|define
name|__ECORE_HSI_RDMA__
end_define

begin_comment
comment|/************************************************************************/
end_comment

begin_comment
comment|/* Add include to common rdma target for both eCore and protocol rdma driver */
end_comment

begin_comment
comment|/************************************************************************/
end_comment

begin_include
include|#
directive|include
file|"rdma_common.h"
end_include

begin_comment
comment|/*  * The rdma task context of Mstorm  */
end_comment

begin_struct
struct|struct
name|ystorm_rdma_task_st_ctx
block|{
name|struct
name|regpair
name|temp
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|e4_ystorm_rdma_task_ag_ctx
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
name|msem_ctx_upd_seq
comment|/* icid */
decl_stmt|;
name|u8
name|flags0
decl_stmt|;
define|#
directive|define
name|E4_YSTORM_RDMA_TASK_AG_CTX_CONNECTION_TYPE_MASK
value|0xF
comment|/* connection_type */
define|#
directive|define
name|E4_YSTORM_RDMA_TASK_AG_CTX_CONNECTION_TYPE_SHIFT
value|0
define|#
directive|define
name|E4_YSTORM_RDMA_TASK_AG_CTX_EXIST_IN_QM0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E4_YSTORM_RDMA_TASK_AG_CTX_EXIST_IN_QM0_SHIFT
value|4
define|#
directive|define
name|E4_YSTORM_RDMA_TASK_AG_CTX_BIT1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E4_YSTORM_RDMA_TASK_AG_CTX_BIT1_SHIFT
value|5
define|#
directive|define
name|E4_YSTORM_RDMA_TASK_AG_CTX_VALID_MASK
value|0x1
comment|/* bit2 */
define|#
directive|define
name|E4_YSTORM_RDMA_TASK_AG_CTX_VALID_SHIFT
value|6
define|#
directive|define
name|E4_YSTORM_RDMA_TASK_AG_CTX_BIT3_MASK
value|0x1
comment|/* bit3 */
define|#
directive|define
name|E4_YSTORM_RDMA_TASK_AG_CTX_BIT3_SHIFT
value|7
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E4_YSTORM_RDMA_TASK_AG_CTX_CF0_MASK
value|0x3
comment|/* cf0 */
define|#
directive|define
name|E4_YSTORM_RDMA_TASK_AG_CTX_CF0_SHIFT
value|0
define|#
directive|define
name|E4_YSTORM_RDMA_TASK_AG_CTX_CF1_MASK
value|0x3
comment|/* cf1 */
define|#
directive|define
name|E4_YSTORM_RDMA_TASK_AG_CTX_CF1_SHIFT
value|2
define|#
directive|define
name|E4_YSTORM_RDMA_TASK_AG_CTX_CF2SPECIAL_MASK
value|0x3
comment|/* cf2special */
define|#
directive|define
name|E4_YSTORM_RDMA_TASK_AG_CTX_CF2SPECIAL_SHIFT
value|4
define|#
directive|define
name|E4_YSTORM_RDMA_TASK_AG_CTX_CF0EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E4_YSTORM_RDMA_TASK_AG_CTX_CF0EN_SHIFT
value|6
define|#
directive|define
name|E4_YSTORM_RDMA_TASK_AG_CTX_CF1EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E4_YSTORM_RDMA_TASK_AG_CTX_CF1EN_SHIFT
value|7
name|u8
name|flags2
decl_stmt|;
define|#
directive|define
name|E4_YSTORM_RDMA_TASK_AG_CTX_BIT4_MASK
value|0x1
comment|/* bit4 */
define|#
directive|define
name|E4_YSTORM_RDMA_TASK_AG_CTX_BIT4_SHIFT
value|0
define|#
directive|define
name|E4_YSTORM_RDMA_TASK_AG_CTX_RULE0EN_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E4_YSTORM_RDMA_TASK_AG_CTX_RULE0EN_SHIFT
value|1
define|#
directive|define
name|E4_YSTORM_RDMA_TASK_AG_CTX_RULE1EN_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E4_YSTORM_RDMA_TASK_AG_CTX_RULE1EN_SHIFT
value|2
define|#
directive|define
name|E4_YSTORM_RDMA_TASK_AG_CTX_RULE2EN_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E4_YSTORM_RDMA_TASK_AG_CTX_RULE2EN_SHIFT
value|3
define|#
directive|define
name|E4_YSTORM_RDMA_TASK_AG_CTX_RULE3EN_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E4_YSTORM_RDMA_TASK_AG_CTX_RULE3EN_SHIFT
value|4
define|#
directive|define
name|E4_YSTORM_RDMA_TASK_AG_CTX_RULE4EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E4_YSTORM_RDMA_TASK_AG_CTX_RULE4EN_SHIFT
value|5
define|#
directive|define
name|E4_YSTORM_RDMA_TASK_AG_CTX_RULE5EN_MASK
value|0x1
comment|/* rule5en */
define|#
directive|define
name|E4_YSTORM_RDMA_TASK_AG_CTX_RULE5EN_SHIFT
value|6
define|#
directive|define
name|E4_YSTORM_RDMA_TASK_AG_CTX_RULE6EN_MASK
value|0x1
comment|/* rule6en */
define|#
directive|define
name|E4_YSTORM_RDMA_TASK_AG_CTX_RULE6EN_SHIFT
value|7
name|u8
name|key
comment|/* byte2 */
decl_stmt|;
name|__le32
name|mw_cnt
comment|/* reg0 */
decl_stmt|;
name|u8
name|ref_cnt_seq
comment|/* byte3 */
decl_stmt|;
name|u8
name|ctx_upd_seq
comment|/* byte4 */
decl_stmt|;
name|__le16
name|dif_flags
comment|/* word1 */
decl_stmt|;
name|__le16
name|tx_ref_count
comment|/* word2 */
decl_stmt|;
name|__le16
name|last_used_ltid
comment|/* word3 */
decl_stmt|;
name|__le16
name|parent_mr_lo
comment|/* word4 */
decl_stmt|;
name|__le16
name|parent_mr_hi
comment|/* word5 */
decl_stmt|;
name|__le32
name|fbo_lo
comment|/* reg1 */
decl_stmt|;
name|__le32
name|fbo_hi
comment|/* reg2 */
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|e4_mstorm_rdma_task_ag_ctx
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
name|E4_MSTORM_RDMA_TASK_AG_CTX_CONNECTION_TYPE_MASK
value|0xF
comment|/* connection_type */
define|#
directive|define
name|E4_MSTORM_RDMA_TASK_AG_CTX_CONNECTION_TYPE_SHIFT
value|0
define|#
directive|define
name|E4_MSTORM_RDMA_TASK_AG_CTX_EXIST_IN_QM0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E4_MSTORM_RDMA_TASK_AG_CTX_EXIST_IN_QM0_SHIFT
value|4
define|#
directive|define
name|E4_MSTORM_RDMA_TASK_AG_CTX_BIT1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E4_MSTORM_RDMA_TASK_AG_CTX_BIT1_SHIFT
value|5
define|#
directive|define
name|E4_MSTORM_RDMA_TASK_AG_CTX_BIT2_MASK
value|0x1
comment|/* bit2 */
define|#
directive|define
name|E4_MSTORM_RDMA_TASK_AG_CTX_BIT2_SHIFT
value|6
define|#
directive|define
name|E4_MSTORM_RDMA_TASK_AG_CTX_BIT3_MASK
value|0x1
comment|/* bit3 */
define|#
directive|define
name|E4_MSTORM_RDMA_TASK_AG_CTX_BIT3_SHIFT
value|7
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E4_MSTORM_RDMA_TASK_AG_CTX_CF0_MASK
value|0x3
comment|/* cf0 */
define|#
directive|define
name|E4_MSTORM_RDMA_TASK_AG_CTX_CF0_SHIFT
value|0
define|#
directive|define
name|E4_MSTORM_RDMA_TASK_AG_CTX_CF1_MASK
value|0x3
comment|/* cf1 */
define|#
directive|define
name|E4_MSTORM_RDMA_TASK_AG_CTX_CF1_SHIFT
value|2
define|#
directive|define
name|E4_MSTORM_RDMA_TASK_AG_CTX_CF2_MASK
value|0x3
comment|/* cf2 */
define|#
directive|define
name|E4_MSTORM_RDMA_TASK_AG_CTX_CF2_SHIFT
value|4
define|#
directive|define
name|E4_MSTORM_RDMA_TASK_AG_CTX_CF0EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E4_MSTORM_RDMA_TASK_AG_CTX_CF0EN_SHIFT
value|6
define|#
directive|define
name|E4_MSTORM_RDMA_TASK_AG_CTX_CF1EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E4_MSTORM_RDMA_TASK_AG_CTX_CF1EN_SHIFT
value|7
name|u8
name|flags2
decl_stmt|;
define|#
directive|define
name|E4_MSTORM_RDMA_TASK_AG_CTX_CF2EN_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E4_MSTORM_RDMA_TASK_AG_CTX_CF2EN_SHIFT
value|0
define|#
directive|define
name|E4_MSTORM_RDMA_TASK_AG_CTX_RULE0EN_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E4_MSTORM_RDMA_TASK_AG_CTX_RULE0EN_SHIFT
value|1
define|#
directive|define
name|E4_MSTORM_RDMA_TASK_AG_CTX_RULE1EN_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E4_MSTORM_RDMA_TASK_AG_CTX_RULE1EN_SHIFT
value|2
define|#
directive|define
name|E4_MSTORM_RDMA_TASK_AG_CTX_RULE2EN_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E4_MSTORM_RDMA_TASK_AG_CTX_RULE2EN_SHIFT
value|3
define|#
directive|define
name|E4_MSTORM_RDMA_TASK_AG_CTX_RULE3EN_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E4_MSTORM_RDMA_TASK_AG_CTX_RULE3EN_SHIFT
value|4
define|#
directive|define
name|E4_MSTORM_RDMA_TASK_AG_CTX_RULE4EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E4_MSTORM_RDMA_TASK_AG_CTX_RULE4EN_SHIFT
value|5
define|#
directive|define
name|E4_MSTORM_RDMA_TASK_AG_CTX_RULE5EN_MASK
value|0x1
comment|/* rule5en */
define|#
directive|define
name|E4_MSTORM_RDMA_TASK_AG_CTX_RULE5EN_SHIFT
value|6
define|#
directive|define
name|E4_MSTORM_RDMA_TASK_AG_CTX_RULE6EN_MASK
value|0x1
comment|/* rule6en */
define|#
directive|define
name|E4_MSTORM_RDMA_TASK_AG_CTX_RULE6EN_SHIFT
value|7
name|u8
name|key
comment|/* byte2 */
decl_stmt|;
name|__le32
name|mw_cnt
comment|/* reg0 */
decl_stmt|;
name|u8
name|ref_cnt_seq
comment|/* byte3 */
decl_stmt|;
name|u8
name|ctx_upd_seq
comment|/* byte4 */
decl_stmt|;
name|__le16
name|dif_flags
comment|/* word1 */
decl_stmt|;
name|__le16
name|tx_ref_count
comment|/* word2 */
decl_stmt|;
name|__le16
name|last_used_ltid
comment|/* word3 */
decl_stmt|;
name|__le16
name|parent_mr_lo
comment|/* word4 */
decl_stmt|;
name|__le16
name|parent_mr_hi
comment|/* word5 */
decl_stmt|;
name|__le32
name|fbo_lo
comment|/* reg1 */
decl_stmt|;
name|__le32
name|fbo_hi
comment|/* reg2 */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The roce task context of Mstorm  */
end_comment

begin_struct
struct|struct
name|mstorm_rdma_task_st_ctx
block|{
name|struct
name|regpair
name|temp
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The roce task context of Ustorm  */
end_comment

begin_struct
struct|struct
name|ustorm_rdma_task_st_ctx
block|{
name|struct
name|regpair
name|temp
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|e4_ustorm_rdma_task_ag_ctx
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
name|E4_USTORM_RDMA_TASK_AG_CTX_CONNECTION_TYPE_MASK
value|0xF
comment|/* connection_type */
define|#
directive|define
name|E4_USTORM_RDMA_TASK_AG_CTX_CONNECTION_TYPE_SHIFT
value|0
define|#
directive|define
name|E4_USTORM_RDMA_TASK_AG_CTX_EXIST_IN_QM0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E4_USTORM_RDMA_TASK_AG_CTX_EXIST_IN_QM0_SHIFT
value|4
define|#
directive|define
name|E4_USTORM_RDMA_TASK_AG_CTX_DIF_RUNT_VALID_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E4_USTORM_RDMA_TASK_AG_CTX_DIF_RUNT_VALID_SHIFT
value|5
define|#
directive|define
name|E4_USTORM_RDMA_TASK_AG_CTX_DIF_WRITE_RESULT_CF_MASK
value|0x3
comment|/* timer0cf */
define|#
directive|define
name|E4_USTORM_RDMA_TASK_AG_CTX_DIF_WRITE_RESULT_CF_SHIFT
value|6
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E4_USTORM_RDMA_TASK_AG_CTX_DIF_RESULT_TOGGLE_BIT_MASK
value|0x3
comment|/* timer1cf */
define|#
directive|define
name|E4_USTORM_RDMA_TASK_AG_CTX_DIF_RESULT_TOGGLE_BIT_SHIFT
value|0
define|#
directive|define
name|E4_USTORM_RDMA_TASK_AG_CTX_DIF_TX_IO_FLG_MASK
value|0x3
comment|/* timer2cf */
define|#
directive|define
name|E4_USTORM_RDMA_TASK_AG_CTX_DIF_TX_IO_FLG_SHIFT
value|2
define|#
directive|define
name|E4_USTORM_RDMA_TASK_AG_CTX_CF3_MASK
value|0x3
comment|/* timer_stop_all */
define|#
directive|define
name|E4_USTORM_RDMA_TASK_AG_CTX_CF3_SHIFT
value|4
define|#
directive|define
name|E4_USTORM_RDMA_TASK_AG_CTX_DIF_ERROR_CF_MASK
value|0x3
comment|/* cf4 */
define|#
directive|define
name|E4_USTORM_RDMA_TASK_AG_CTX_DIF_ERROR_CF_SHIFT
value|6
name|u8
name|flags2
decl_stmt|;
define|#
directive|define
name|E4_USTORM_RDMA_TASK_AG_CTX_DIF_WRITE_RESULT_CF_EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E4_USTORM_RDMA_TASK_AG_CTX_DIF_WRITE_RESULT_CF_EN_SHIFT
value|0
define|#
directive|define
name|E4_USTORM_RDMA_TASK_AG_CTX_RESERVED2_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E4_USTORM_RDMA_TASK_AG_CTX_RESERVED2_SHIFT
value|1
define|#
directive|define
name|E4_USTORM_RDMA_TASK_AG_CTX_RESERVED3_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E4_USTORM_RDMA_TASK_AG_CTX_RESERVED3_SHIFT
value|2
define|#
directive|define
name|E4_USTORM_RDMA_TASK_AG_CTX_CF3EN_MASK
value|0x1
comment|/* cf3en */
define|#
directive|define
name|E4_USTORM_RDMA_TASK_AG_CTX_CF3EN_SHIFT
value|3
define|#
directive|define
name|E4_USTORM_RDMA_TASK_AG_CTX_DIF_ERROR_CF_EN_MASK
value|0x1
comment|/* cf4en */
define|#
directive|define
name|E4_USTORM_RDMA_TASK_AG_CTX_DIF_ERROR_CF_EN_SHIFT
value|4
define|#
directive|define
name|E4_USTORM_RDMA_TASK_AG_CTX_RULE0EN_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E4_USTORM_RDMA_TASK_AG_CTX_RULE0EN_SHIFT
value|5
define|#
directive|define
name|E4_USTORM_RDMA_TASK_AG_CTX_RULE1EN_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E4_USTORM_RDMA_TASK_AG_CTX_RULE1EN_SHIFT
value|6
define|#
directive|define
name|E4_USTORM_RDMA_TASK_AG_CTX_RULE2EN_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E4_USTORM_RDMA_TASK_AG_CTX_RULE2EN_SHIFT
value|7
name|u8
name|flags3
decl_stmt|;
define|#
directive|define
name|E4_USTORM_RDMA_TASK_AG_CTX_RULE3EN_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E4_USTORM_RDMA_TASK_AG_CTX_RULE3EN_SHIFT
value|0
define|#
directive|define
name|E4_USTORM_RDMA_TASK_AG_CTX_RULE4EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E4_USTORM_RDMA_TASK_AG_CTX_RULE4EN_SHIFT
value|1
define|#
directive|define
name|E4_USTORM_RDMA_TASK_AG_CTX_RULE5EN_MASK
value|0x1
comment|/* rule5en */
define|#
directive|define
name|E4_USTORM_RDMA_TASK_AG_CTX_RULE5EN_SHIFT
value|2
define|#
directive|define
name|E4_USTORM_RDMA_TASK_AG_CTX_RULE6EN_MASK
value|0x1
comment|/* rule6en */
define|#
directive|define
name|E4_USTORM_RDMA_TASK_AG_CTX_RULE6EN_SHIFT
value|3
define|#
directive|define
name|E4_USTORM_RDMA_TASK_AG_CTX_DIF_ERROR_TYPE_MASK
value|0xF
comment|/* nibble1 */
define|#
directive|define
name|E4_USTORM_RDMA_TASK_AG_CTX_DIF_ERROR_TYPE_SHIFT
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
name|reg2
comment|/* reg2 */
decl_stmt|;
name|__le32
name|dif_runt_value
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
comment|/*  * RDMA task context  */
end_comment

begin_struct
struct|struct
name|e4_rdma_task_context
block|{
name|struct
name|ystorm_rdma_task_st_ctx
name|ystorm_st_context
comment|/* ystorm storm context */
decl_stmt|;
name|struct
name|e4_ystorm_rdma_task_ag_ctx
name|ystorm_ag_context
comment|/* ystorm aggregative context */
decl_stmt|;
name|struct
name|tdif_task_context
name|tdif_context
comment|/* tdif context */
decl_stmt|;
name|struct
name|e4_mstorm_rdma_task_ag_ctx
name|mstorm_ag_context
comment|/* mstorm aggregative context */
decl_stmt|;
name|struct
name|mstorm_rdma_task_st_ctx
name|mstorm_st_context
comment|/* mstorm storm context */
decl_stmt|;
name|struct
name|rdif_task_context
name|rdif_context
comment|/* rdif context */
decl_stmt|;
name|struct
name|ustorm_rdma_task_st_ctx
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
name|e4_ustorm_rdma_task_ag_ctx
name|ustorm_ag_context
comment|/* ustorm aggregative context */
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|e5_ystorm_rdma_task_ag_ctx
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
name|msem_ctx_upd_seq
comment|/* icid */
decl_stmt|;
name|u8
name|flags0
decl_stmt|;
define|#
directive|define
name|E5_YSTORM_RDMA_TASK_AG_CTX_CONNECTION_TYPE_MASK
value|0xF
comment|/* connection_type */
define|#
directive|define
name|E5_YSTORM_RDMA_TASK_AG_CTX_CONNECTION_TYPE_SHIFT
value|0
define|#
directive|define
name|E5_YSTORM_RDMA_TASK_AG_CTX_EXIST_IN_QM0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E5_YSTORM_RDMA_TASK_AG_CTX_EXIST_IN_QM0_SHIFT
value|4
define|#
directive|define
name|E5_YSTORM_RDMA_TASK_AG_CTX_BIT1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E5_YSTORM_RDMA_TASK_AG_CTX_BIT1_SHIFT
value|5
define|#
directive|define
name|E5_YSTORM_RDMA_TASK_AG_CTX_VALID_MASK
value|0x1
comment|/* bit2 */
define|#
directive|define
name|E5_YSTORM_RDMA_TASK_AG_CTX_VALID_SHIFT
value|6
define|#
directive|define
name|E5_YSTORM_RDMA_TASK_AG_CTX_BIT3_MASK
value|0x1
comment|/* bit3 */
define|#
directive|define
name|E5_YSTORM_RDMA_TASK_AG_CTX_BIT3_SHIFT
value|7
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E5_YSTORM_RDMA_TASK_AG_CTX_CF0_MASK
value|0x3
comment|/* cf0 */
define|#
directive|define
name|E5_YSTORM_RDMA_TASK_AG_CTX_CF0_SHIFT
value|0
define|#
directive|define
name|E5_YSTORM_RDMA_TASK_AG_CTX_CF1_MASK
value|0x3
comment|/* cf1 */
define|#
directive|define
name|E5_YSTORM_RDMA_TASK_AG_CTX_CF1_SHIFT
value|2
define|#
directive|define
name|E5_YSTORM_RDMA_TASK_AG_CTX_CF2SPECIAL_MASK
value|0x3
comment|/* cf2special */
define|#
directive|define
name|E5_YSTORM_RDMA_TASK_AG_CTX_CF2SPECIAL_SHIFT
value|4
define|#
directive|define
name|E5_YSTORM_RDMA_TASK_AG_CTX_CF0EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E5_YSTORM_RDMA_TASK_AG_CTX_CF0EN_SHIFT
value|6
define|#
directive|define
name|E5_YSTORM_RDMA_TASK_AG_CTX_CF1EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E5_YSTORM_RDMA_TASK_AG_CTX_CF1EN_SHIFT
value|7
name|u8
name|flags2
decl_stmt|;
define|#
directive|define
name|E5_YSTORM_RDMA_TASK_AG_CTX_BIT4_MASK
value|0x1
comment|/* bit4 */
define|#
directive|define
name|E5_YSTORM_RDMA_TASK_AG_CTX_BIT4_SHIFT
value|0
define|#
directive|define
name|E5_YSTORM_RDMA_TASK_AG_CTX_RULE0EN_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E5_YSTORM_RDMA_TASK_AG_CTX_RULE0EN_SHIFT
value|1
define|#
directive|define
name|E5_YSTORM_RDMA_TASK_AG_CTX_RULE1EN_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E5_YSTORM_RDMA_TASK_AG_CTX_RULE1EN_SHIFT
value|2
define|#
directive|define
name|E5_YSTORM_RDMA_TASK_AG_CTX_RULE2EN_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E5_YSTORM_RDMA_TASK_AG_CTX_RULE2EN_SHIFT
value|3
define|#
directive|define
name|E5_YSTORM_RDMA_TASK_AG_CTX_RULE3EN_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E5_YSTORM_RDMA_TASK_AG_CTX_RULE3EN_SHIFT
value|4
define|#
directive|define
name|E5_YSTORM_RDMA_TASK_AG_CTX_RULE4EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E5_YSTORM_RDMA_TASK_AG_CTX_RULE4EN_SHIFT
value|5
define|#
directive|define
name|E5_YSTORM_RDMA_TASK_AG_CTX_RULE5EN_MASK
value|0x1
comment|/* rule5en */
define|#
directive|define
name|E5_YSTORM_RDMA_TASK_AG_CTX_RULE5EN_SHIFT
value|6
define|#
directive|define
name|E5_YSTORM_RDMA_TASK_AG_CTX_RULE6EN_MASK
value|0x1
comment|/* rule6en */
define|#
directive|define
name|E5_YSTORM_RDMA_TASK_AG_CTX_RULE6EN_SHIFT
value|7
name|u8
name|flags3
decl_stmt|;
define|#
directive|define
name|E5_YSTORM_RDMA_TASK_AG_CTX_E4_RESERVED1_MASK
value|0x1
comment|/* bit5 */
define|#
directive|define
name|E5_YSTORM_RDMA_TASK_AG_CTX_E4_RESERVED1_SHIFT
value|0
define|#
directive|define
name|E5_YSTORM_RDMA_TASK_AG_CTX_E4_RESERVED2_MASK
value|0x3
comment|/* cf3 */
define|#
directive|define
name|E5_YSTORM_RDMA_TASK_AG_CTX_E4_RESERVED2_SHIFT
value|1
define|#
directive|define
name|E5_YSTORM_RDMA_TASK_AG_CTX_E4_RESERVED3_MASK
value|0x3
comment|/* cf4 */
define|#
directive|define
name|E5_YSTORM_RDMA_TASK_AG_CTX_E4_RESERVED3_SHIFT
value|3
define|#
directive|define
name|E5_YSTORM_RDMA_TASK_AG_CTX_E4_RESERVED4_MASK
value|0x1
comment|/* cf3en */
define|#
directive|define
name|E5_YSTORM_RDMA_TASK_AG_CTX_E4_RESERVED4_SHIFT
value|5
define|#
directive|define
name|E5_YSTORM_RDMA_TASK_AG_CTX_E4_RESERVED5_MASK
value|0x1
comment|/* cf4en */
define|#
directive|define
name|E5_YSTORM_RDMA_TASK_AG_CTX_E4_RESERVED5_SHIFT
value|6
define|#
directive|define
name|E5_YSTORM_RDMA_TASK_AG_CTX_E4_RESERVED6_MASK
value|0x1
comment|/* rule7en */
define|#
directive|define
name|E5_YSTORM_RDMA_TASK_AG_CTX_E4_RESERVED6_SHIFT
value|7
name|__le32
name|mw_cnt
comment|/* reg0 */
decl_stmt|;
name|u8
name|key
comment|/* byte2 */
decl_stmt|;
name|u8
name|ref_cnt_seq
comment|/* byte3 */
decl_stmt|;
name|u8
name|ctx_upd_seq
comment|/* byte4 */
decl_stmt|;
name|u8
name|e4_reserved7
comment|/* byte5 */
decl_stmt|;
name|__le16
name|dif_flags
comment|/* word1 */
decl_stmt|;
name|__le16
name|tx_ref_count
comment|/* word2 */
decl_stmt|;
name|__le16
name|last_used_ltid
comment|/* word3 */
decl_stmt|;
name|__le16
name|parent_mr_lo
comment|/* word4 */
decl_stmt|;
name|__le16
name|parent_mr_hi
comment|/* word5 */
decl_stmt|;
name|__le16
name|e4_reserved8
comment|/* word6 */
decl_stmt|;
name|__le32
name|fbo_lo
comment|/* reg1 */
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|e5_mstorm_rdma_task_ag_ctx
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
name|E5_MSTORM_RDMA_TASK_AG_CTX_CONNECTION_TYPE_MASK
value|0xF
comment|/* connection_type */
define|#
directive|define
name|E5_MSTORM_RDMA_TASK_AG_CTX_CONNECTION_TYPE_SHIFT
value|0
define|#
directive|define
name|E5_MSTORM_RDMA_TASK_AG_CTX_EXIST_IN_QM0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E5_MSTORM_RDMA_TASK_AG_CTX_EXIST_IN_QM0_SHIFT
value|4
define|#
directive|define
name|E5_MSTORM_RDMA_TASK_AG_CTX_BIT1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E5_MSTORM_RDMA_TASK_AG_CTX_BIT1_SHIFT
value|5
define|#
directive|define
name|E5_MSTORM_RDMA_TASK_AG_CTX_BIT2_MASK
value|0x1
comment|/* bit2 */
define|#
directive|define
name|E5_MSTORM_RDMA_TASK_AG_CTX_BIT2_SHIFT
value|6
define|#
directive|define
name|E5_MSTORM_RDMA_TASK_AG_CTX_BIT3_MASK
value|0x1
comment|/* bit3 */
define|#
directive|define
name|E5_MSTORM_RDMA_TASK_AG_CTX_BIT3_SHIFT
value|7
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E5_MSTORM_RDMA_TASK_AG_CTX_CF0_MASK
value|0x3
comment|/* cf0 */
define|#
directive|define
name|E5_MSTORM_RDMA_TASK_AG_CTX_CF0_SHIFT
value|0
define|#
directive|define
name|E5_MSTORM_RDMA_TASK_AG_CTX_CF1_MASK
value|0x3
comment|/* cf1 */
define|#
directive|define
name|E5_MSTORM_RDMA_TASK_AG_CTX_CF1_SHIFT
value|2
define|#
directive|define
name|E5_MSTORM_RDMA_TASK_AG_CTX_CF2_MASK
value|0x3
comment|/* cf2 */
define|#
directive|define
name|E5_MSTORM_RDMA_TASK_AG_CTX_CF2_SHIFT
value|4
define|#
directive|define
name|E5_MSTORM_RDMA_TASK_AG_CTX_CF0EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E5_MSTORM_RDMA_TASK_AG_CTX_CF0EN_SHIFT
value|6
define|#
directive|define
name|E5_MSTORM_RDMA_TASK_AG_CTX_CF1EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E5_MSTORM_RDMA_TASK_AG_CTX_CF1EN_SHIFT
value|7
name|u8
name|flags2
decl_stmt|;
define|#
directive|define
name|E5_MSTORM_RDMA_TASK_AG_CTX_CF2EN_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E5_MSTORM_RDMA_TASK_AG_CTX_CF2EN_SHIFT
value|0
define|#
directive|define
name|E5_MSTORM_RDMA_TASK_AG_CTX_RULE0EN_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E5_MSTORM_RDMA_TASK_AG_CTX_RULE0EN_SHIFT
value|1
define|#
directive|define
name|E5_MSTORM_RDMA_TASK_AG_CTX_RULE1EN_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E5_MSTORM_RDMA_TASK_AG_CTX_RULE1EN_SHIFT
value|2
define|#
directive|define
name|E5_MSTORM_RDMA_TASK_AG_CTX_RULE2EN_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E5_MSTORM_RDMA_TASK_AG_CTX_RULE2EN_SHIFT
value|3
define|#
directive|define
name|E5_MSTORM_RDMA_TASK_AG_CTX_RULE3EN_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E5_MSTORM_RDMA_TASK_AG_CTX_RULE3EN_SHIFT
value|4
define|#
directive|define
name|E5_MSTORM_RDMA_TASK_AG_CTX_RULE4EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E5_MSTORM_RDMA_TASK_AG_CTX_RULE4EN_SHIFT
value|5
define|#
directive|define
name|E5_MSTORM_RDMA_TASK_AG_CTX_RULE5EN_MASK
value|0x1
comment|/* rule5en */
define|#
directive|define
name|E5_MSTORM_RDMA_TASK_AG_CTX_RULE5EN_SHIFT
value|6
define|#
directive|define
name|E5_MSTORM_RDMA_TASK_AG_CTX_RULE6EN_MASK
value|0x1
comment|/* rule6en */
define|#
directive|define
name|E5_MSTORM_RDMA_TASK_AG_CTX_RULE6EN_SHIFT
value|7
name|u8
name|flags3
decl_stmt|;
define|#
directive|define
name|E5_MSTORM_RDMA_TASK_AG_CTX_E4_RESERVED1_MASK
value|0x1
comment|/* bit4 */
define|#
directive|define
name|E5_MSTORM_RDMA_TASK_AG_CTX_E4_RESERVED1_SHIFT
value|0
define|#
directive|define
name|E5_MSTORM_RDMA_TASK_AG_CTX_E4_RESERVED2_MASK
value|0x3
comment|/* cf3 */
define|#
directive|define
name|E5_MSTORM_RDMA_TASK_AG_CTX_E4_RESERVED2_SHIFT
value|1
define|#
directive|define
name|E5_MSTORM_RDMA_TASK_AG_CTX_E4_RESERVED3_MASK
value|0x3
comment|/* cf4 */
define|#
directive|define
name|E5_MSTORM_RDMA_TASK_AG_CTX_E4_RESERVED3_SHIFT
value|3
define|#
directive|define
name|E5_MSTORM_RDMA_TASK_AG_CTX_E4_RESERVED4_MASK
value|0x1
comment|/* cf3en */
define|#
directive|define
name|E5_MSTORM_RDMA_TASK_AG_CTX_E4_RESERVED4_SHIFT
value|5
define|#
directive|define
name|E5_MSTORM_RDMA_TASK_AG_CTX_E4_RESERVED5_MASK
value|0x1
comment|/* cf4en */
define|#
directive|define
name|E5_MSTORM_RDMA_TASK_AG_CTX_E4_RESERVED5_SHIFT
value|6
define|#
directive|define
name|E5_MSTORM_RDMA_TASK_AG_CTX_E4_RESERVED6_MASK
value|0x1
comment|/* rule7en */
define|#
directive|define
name|E5_MSTORM_RDMA_TASK_AG_CTX_E4_RESERVED6_SHIFT
value|7
name|__le32
name|mw_cnt
comment|/* reg0 */
decl_stmt|;
name|u8
name|key
comment|/* byte2 */
decl_stmt|;
name|u8
name|ref_cnt_seq
comment|/* byte3 */
decl_stmt|;
name|u8
name|ctx_upd_seq
comment|/* byte4 */
decl_stmt|;
name|u8
name|e4_reserved7
comment|/* byte5 */
decl_stmt|;
name|__le16
name|dif_flags
comment|/* regpair0 */
decl_stmt|;
name|__le16
name|tx_ref_count
comment|/* word2 */
decl_stmt|;
name|__le16
name|last_used_ltid
comment|/* word3 */
decl_stmt|;
name|__le16
name|parent_mr_lo
comment|/* word4 */
decl_stmt|;
name|__le16
name|parent_mr_hi
comment|/* regpair1 */
decl_stmt|;
name|__le16
name|e4_reserved8
comment|/* word6 */
decl_stmt|;
name|__le32
name|fbo_lo
comment|/* reg1 */
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|e5_ustorm_rdma_task_ag_ctx
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
name|E5_USTORM_RDMA_TASK_AG_CTX_CONNECTION_TYPE_MASK
value|0xF
comment|/* connection_type */
define|#
directive|define
name|E5_USTORM_RDMA_TASK_AG_CTX_CONNECTION_TYPE_SHIFT
value|0
define|#
directive|define
name|E5_USTORM_RDMA_TASK_AG_CTX_EXIST_IN_QM0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E5_USTORM_RDMA_TASK_AG_CTX_EXIST_IN_QM0_SHIFT
value|4
define|#
directive|define
name|E5_USTORM_RDMA_TASK_AG_CTX_DIF_RUNT_VALID_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E5_USTORM_RDMA_TASK_AG_CTX_DIF_RUNT_VALID_SHIFT
value|5
define|#
directive|define
name|E5_USTORM_RDMA_TASK_AG_CTX_DIF_WRITE_RESULT_CF_MASK
value|0x3
comment|/* timer0cf */
define|#
directive|define
name|E5_USTORM_RDMA_TASK_AG_CTX_DIF_WRITE_RESULT_CF_SHIFT
value|6
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E5_USTORM_RDMA_TASK_AG_CTX_DIF_RESULT_TOGGLE_BIT_MASK
value|0x3
comment|/* timer1cf */
define|#
directive|define
name|E5_USTORM_RDMA_TASK_AG_CTX_DIF_RESULT_TOGGLE_BIT_SHIFT
value|0
define|#
directive|define
name|E5_USTORM_RDMA_TASK_AG_CTX_DIF_TX_IO_FLG_MASK
value|0x3
comment|/* timer2cf */
define|#
directive|define
name|E5_USTORM_RDMA_TASK_AG_CTX_DIF_TX_IO_FLG_SHIFT
value|2
define|#
directive|define
name|E5_USTORM_RDMA_TASK_AG_CTX_CF3_MASK
value|0x3
comment|/* timer_stop_all */
define|#
directive|define
name|E5_USTORM_RDMA_TASK_AG_CTX_CF3_SHIFT
value|4
define|#
directive|define
name|E5_USTORM_RDMA_TASK_AG_CTX_DIF_ERROR_CF_MASK
value|0x3
comment|/* dif_error_cf */
define|#
directive|define
name|E5_USTORM_RDMA_TASK_AG_CTX_DIF_ERROR_CF_SHIFT
value|6
name|u8
name|flags2
decl_stmt|;
define|#
directive|define
name|E5_USTORM_RDMA_TASK_AG_CTX_DIF_WRITE_RESULT_CF_EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E5_USTORM_RDMA_TASK_AG_CTX_DIF_WRITE_RESULT_CF_EN_SHIFT
value|0
define|#
directive|define
name|E5_USTORM_RDMA_TASK_AG_CTX_RESERVED2_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E5_USTORM_RDMA_TASK_AG_CTX_RESERVED2_SHIFT
value|1
define|#
directive|define
name|E5_USTORM_RDMA_TASK_AG_CTX_RESERVED3_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E5_USTORM_RDMA_TASK_AG_CTX_RESERVED3_SHIFT
value|2
define|#
directive|define
name|E5_USTORM_RDMA_TASK_AG_CTX_CF3EN_MASK
value|0x1
comment|/* cf3en */
define|#
directive|define
name|E5_USTORM_RDMA_TASK_AG_CTX_CF3EN_SHIFT
value|3
define|#
directive|define
name|E5_USTORM_RDMA_TASK_AG_CTX_DIF_ERROR_CF_EN_MASK
value|0x1
comment|/* cf4en */
define|#
directive|define
name|E5_USTORM_RDMA_TASK_AG_CTX_DIF_ERROR_CF_EN_SHIFT
value|4
define|#
directive|define
name|E5_USTORM_RDMA_TASK_AG_CTX_RULE0EN_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E5_USTORM_RDMA_TASK_AG_CTX_RULE0EN_SHIFT
value|5
define|#
directive|define
name|E5_USTORM_RDMA_TASK_AG_CTX_RULE1EN_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E5_USTORM_RDMA_TASK_AG_CTX_RULE1EN_SHIFT
value|6
define|#
directive|define
name|E5_USTORM_RDMA_TASK_AG_CTX_RULE2EN_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E5_USTORM_RDMA_TASK_AG_CTX_RULE2EN_SHIFT
value|7
name|u8
name|flags3
decl_stmt|;
define|#
directive|define
name|E5_USTORM_RDMA_TASK_AG_CTX_RULE3EN_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E5_USTORM_RDMA_TASK_AG_CTX_RULE3EN_SHIFT
value|0
define|#
directive|define
name|E5_USTORM_RDMA_TASK_AG_CTX_RULE4EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E5_USTORM_RDMA_TASK_AG_CTX_RULE4EN_SHIFT
value|1
define|#
directive|define
name|E5_USTORM_RDMA_TASK_AG_CTX_RULE5EN_MASK
value|0x1
comment|/* rule5en */
define|#
directive|define
name|E5_USTORM_RDMA_TASK_AG_CTX_RULE5EN_SHIFT
value|2
define|#
directive|define
name|E5_USTORM_RDMA_TASK_AG_CTX_RULE6EN_MASK
value|0x1
comment|/* rule6en */
define|#
directive|define
name|E5_USTORM_RDMA_TASK_AG_CTX_RULE6EN_SHIFT
value|3
define|#
directive|define
name|E5_USTORM_RDMA_TASK_AG_CTX_E4_RESERVED1_MASK
value|0x1
comment|/* bit2 */
define|#
directive|define
name|E5_USTORM_RDMA_TASK_AG_CTX_E4_RESERVED1_SHIFT
value|4
define|#
directive|define
name|E5_USTORM_RDMA_TASK_AG_CTX_E4_RESERVED2_MASK
value|0x1
comment|/* bit3 */
define|#
directive|define
name|E5_USTORM_RDMA_TASK_AG_CTX_E4_RESERVED2_SHIFT
value|5
define|#
directive|define
name|E5_USTORM_RDMA_TASK_AG_CTX_E4_RESERVED3_MASK
value|0x1
comment|/* bit4 */
define|#
directive|define
name|E5_USTORM_RDMA_TASK_AG_CTX_E4_RESERVED3_SHIFT
value|6
define|#
directive|define
name|E5_USTORM_RDMA_TASK_AG_CTX_E4_RESERVED4_MASK
value|0x1
comment|/* rule7en */
define|#
directive|define
name|E5_USTORM_RDMA_TASK_AG_CTX_E4_RESERVED4_SHIFT
value|7
name|u8
name|flags4
decl_stmt|;
define|#
directive|define
name|E5_USTORM_RDMA_TASK_AG_CTX_E4_RESERVED5_MASK
value|0x3
comment|/* cf5 */
define|#
directive|define
name|E5_USTORM_RDMA_TASK_AG_CTX_E4_RESERVED5_SHIFT
value|0
define|#
directive|define
name|E5_USTORM_RDMA_TASK_AG_CTX_E4_RESERVED6_MASK
value|0x1
comment|/* cf5en */
define|#
directive|define
name|E5_USTORM_RDMA_TASK_AG_CTX_E4_RESERVED6_SHIFT
value|2
define|#
directive|define
name|E5_USTORM_RDMA_TASK_AG_CTX_E4_RESERVED7_MASK
value|0x1
comment|/* rule8en */
define|#
directive|define
name|E5_USTORM_RDMA_TASK_AG_CTX_E4_RESERVED7_SHIFT
value|3
define|#
directive|define
name|E5_USTORM_RDMA_TASK_AG_CTX_DIF_ERROR_TYPE_MASK
value|0xF
comment|/* dif_error_type */
define|#
directive|define
name|E5_USTORM_RDMA_TASK_AG_CTX_DIF_ERROR_TYPE_SHIFT
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
name|reg2
comment|/* reg2 */
decl_stmt|;
name|__le32
name|dif_runt_value
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
comment|/*  * RDMA task context  */
end_comment

begin_struct
struct|struct
name|e5_rdma_task_context
block|{
name|struct
name|ystorm_rdma_task_st_ctx
name|ystorm_st_context
comment|/* ystorm storm context */
decl_stmt|;
name|struct
name|e5_ystorm_rdma_task_ag_ctx
name|ystorm_ag_context
comment|/* ystorm aggregative context */
decl_stmt|;
name|struct
name|tdif_task_context
name|tdif_context
comment|/* tdif context */
decl_stmt|;
name|struct
name|e5_mstorm_rdma_task_ag_ctx
name|mstorm_ag_context
comment|/* mstorm aggregative context */
decl_stmt|;
name|struct
name|mstorm_rdma_task_st_ctx
name|mstorm_st_context
comment|/* mstorm storm context */
decl_stmt|;
name|struct
name|rdif_task_context
name|rdif_context
comment|/* rdif context */
decl_stmt|;
name|struct
name|ustorm_rdma_task_st_ctx
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
name|e5_ustorm_rdma_task_ag_ctx
name|ustorm_ag_context
comment|/* ustorm aggregative context */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * rdma function init ramrod data  */
end_comment

begin_struct
struct|struct
name|rdma_close_func_ramrod_data
block|{
name|u8
name|cnq_start_offset
decl_stmt|;
name|u8
name|num_cnqs
decl_stmt|;
name|u8
name|vf_id
comment|/* This field should be assigned to Virtual Function ID if vf_valid == 1. Otherwise its dont care */
decl_stmt|;
name|u8
name|vf_valid
decl_stmt|;
name|u8
name|reserved
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * rdma function init CNQ parameters  */
end_comment

begin_struct
struct|struct
name|rdma_cnq_params
block|{
name|__le16
name|sb_num
comment|/* Status block number used by the queue */
decl_stmt|;
name|u8
name|sb_index
comment|/* Status block index used by the queue */
decl_stmt|;
name|u8
name|num_pbl_pages
comment|/* Number of pages in the PBL allocated for this queue */
decl_stmt|;
name|__le32
name|reserved
decl_stmt|;
name|struct
name|regpair
name|pbl_base_addr
comment|/* Address to the first entry of the queue PBL */
decl_stmt|;
name|__le16
name|queue_zone_num
comment|/* Queue Zone ID used for CNQ consumer update */
decl_stmt|;
name|u8
name|reserved1
index|[
literal|6
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * rdma create cq ramrod data  */
end_comment

begin_struct
struct|struct
name|rdma_create_cq_ramrod_data
block|{
name|struct
name|regpair
name|cq_handle
decl_stmt|;
name|struct
name|regpair
name|pbl_addr
decl_stmt|;
name|__le32
name|max_cqes
decl_stmt|;
name|__le16
name|pbl_num_pages
decl_stmt|;
name|__le16
name|dpi
decl_stmt|;
name|u8
name|is_two_level_pbl
decl_stmt|;
name|u8
name|cnq_id
decl_stmt|;
name|u8
name|pbl_log_page_size
decl_stmt|;
name|u8
name|toggle_bit
decl_stmt|;
name|__le16
name|int_timeout
comment|/* Timeout used for interrupt moderation */
decl_stmt|;
name|__le16
name|reserved1
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * rdma deregister tid ramrod data  */
end_comment

begin_struct
struct|struct
name|rdma_deregister_tid_ramrod_data
block|{
name|__le32
name|itid
decl_stmt|;
name|__le32
name|reserved
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * rdma destroy cq output params  */
end_comment

begin_struct
struct|struct
name|rdma_destroy_cq_output_params
block|{
name|__le16
name|cnq_num
comment|/* Sequence number of completion notification sent for the cq on the associated CNQ */
decl_stmt|;
name|__le16
name|reserved0
decl_stmt|;
name|__le32
name|reserved1
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * rdma destroy cq ramrod data  */
end_comment

begin_struct
struct|struct
name|rdma_destroy_cq_ramrod_data
block|{
name|struct
name|regpair
name|output_params_addr
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * RDMA slow path EQ cmd IDs  */
end_comment

begin_enum
enum|enum
name|rdma_event_opcode
block|{
name|RDMA_EVENT_UNUSED
block|,
name|RDMA_EVENT_FUNC_INIT
block|,
name|RDMA_EVENT_FUNC_CLOSE
block|,
name|RDMA_EVENT_REGISTER_MR
block|,
name|RDMA_EVENT_DEREGISTER_MR
block|,
name|RDMA_EVENT_CREATE_CQ
block|,
name|RDMA_EVENT_RESIZE_CQ
block|,
name|RDMA_EVENT_DESTROY_CQ
block|,
name|RDMA_EVENT_CREATE_SRQ
block|,
name|RDMA_EVENT_MODIFY_SRQ
block|,
name|RDMA_EVENT_DESTROY_SRQ
block|,
name|MAX_RDMA_EVENT_OPCODE
block|}
enum|;
end_enum

begin_comment
comment|/*  * RDMA FW return code for slow path ramrods  */
end_comment

begin_enum
enum|enum
name|rdma_fw_return_code
block|{
name|RDMA_RETURN_OK
init|=
literal|0
block|,
name|RDMA_RETURN_REGISTER_MR_BAD_STATE_ERR
block|,
name|RDMA_RETURN_DEREGISTER_MR_BAD_STATE_ERR
block|,
name|RDMA_RETURN_RESIZE_CQ_ERR
block|,
name|RDMA_RETURN_NIG_DRAIN_REQ
block|,
name|MAX_RDMA_FW_RETURN_CODE
block|}
enum|;
end_enum

begin_comment
comment|/*  * rdma function init header  */
end_comment

begin_struct
struct|struct
name|rdma_init_func_hdr
block|{
name|u8
name|cnq_start_offset
comment|/* First RDMA CNQ */
decl_stmt|;
name|u8
name|num_cnqs
comment|/* Number of CNQs */
decl_stmt|;
name|u8
name|cq_ring_mode
comment|/* 0 for 32 bit cq producer and consumer counters and 1 for 16 bit */
decl_stmt|;
name|u8
name|vf_id
comment|/* This field should be assigned to Virtual Function ID if vf_valid == 1. Otherwise its dont care */
decl_stmt|;
name|u8
name|vf_valid
decl_stmt|;
name|u8
name|reserved
index|[
literal|3
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * rdma function init ramrod data  */
end_comment

begin_struct
struct|struct
name|rdma_init_func_ramrod_data
block|{
name|struct
name|rdma_init_func_hdr
name|params_header
decl_stmt|;
name|struct
name|rdma_cnq_params
name|cnq_params
index|[
name|NUM_OF_GLOBAL_QUEUES
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * RDMA ramrod command IDs  */
end_comment

begin_enum
enum|enum
name|rdma_ramrod_cmd_id
block|{
name|RDMA_RAMROD_UNUSED
block|,
name|RDMA_RAMROD_FUNC_INIT
block|,
name|RDMA_RAMROD_FUNC_CLOSE
block|,
name|RDMA_RAMROD_REGISTER_MR
block|,
name|RDMA_RAMROD_DEREGISTER_MR
block|,
name|RDMA_RAMROD_CREATE_CQ
block|,
name|RDMA_RAMROD_RESIZE_CQ
block|,
name|RDMA_RAMROD_DESTROY_CQ
block|,
name|RDMA_RAMROD_CREATE_SRQ
block|,
name|RDMA_RAMROD_MODIFY_SRQ
block|,
name|RDMA_RAMROD_DESTROY_SRQ
block|,
name|MAX_RDMA_RAMROD_CMD_ID
block|}
enum|;
end_enum

begin_comment
comment|/*  * rdma register tid ramrod data  */
end_comment

begin_struct
struct|struct
name|rdma_register_tid_ramrod_data
block|{
name|__le32
name|flags
decl_stmt|;
define|#
directive|define
name|RDMA_REGISTER_TID_RAMROD_DATA_MAX_ID_MASK
value|0x3FFFF
define|#
directive|define
name|RDMA_REGISTER_TID_RAMROD_DATA_MAX_ID_SHIFT
value|0
define|#
directive|define
name|RDMA_REGISTER_TID_RAMROD_DATA_PAGE_SIZE_LOG_MASK
value|0x1F
define|#
directive|define
name|RDMA_REGISTER_TID_RAMROD_DATA_PAGE_SIZE_LOG_SHIFT
value|18
define|#
directive|define
name|RDMA_REGISTER_TID_RAMROD_DATA_TWO_LEVEL_PBL_MASK
value|0x1
define|#
directive|define
name|RDMA_REGISTER_TID_RAMROD_DATA_TWO_LEVEL_PBL_SHIFT
value|23
define|#
directive|define
name|RDMA_REGISTER_TID_RAMROD_DATA_ZERO_BASED_MASK
value|0x1
define|#
directive|define
name|RDMA_REGISTER_TID_RAMROD_DATA_ZERO_BASED_SHIFT
value|24
define|#
directive|define
name|RDMA_REGISTER_TID_RAMROD_DATA_PHY_MR_MASK
value|0x1
define|#
directive|define
name|RDMA_REGISTER_TID_RAMROD_DATA_PHY_MR_SHIFT
value|25
define|#
directive|define
name|RDMA_REGISTER_TID_RAMROD_DATA_REMOTE_READ_MASK
value|0x1
define|#
directive|define
name|RDMA_REGISTER_TID_RAMROD_DATA_REMOTE_READ_SHIFT
value|26
define|#
directive|define
name|RDMA_REGISTER_TID_RAMROD_DATA_REMOTE_WRITE_MASK
value|0x1
define|#
directive|define
name|RDMA_REGISTER_TID_RAMROD_DATA_REMOTE_WRITE_SHIFT
value|27
define|#
directive|define
name|RDMA_REGISTER_TID_RAMROD_DATA_REMOTE_ATOMIC_MASK
value|0x1
define|#
directive|define
name|RDMA_REGISTER_TID_RAMROD_DATA_REMOTE_ATOMIC_SHIFT
value|28
define|#
directive|define
name|RDMA_REGISTER_TID_RAMROD_DATA_LOCAL_WRITE_MASK
value|0x1
define|#
directive|define
name|RDMA_REGISTER_TID_RAMROD_DATA_LOCAL_WRITE_SHIFT
value|29
define|#
directive|define
name|RDMA_REGISTER_TID_RAMROD_DATA_LOCAL_READ_MASK
value|0x1
define|#
directive|define
name|RDMA_REGISTER_TID_RAMROD_DATA_LOCAL_READ_SHIFT
value|30
define|#
directive|define
name|RDMA_REGISTER_TID_RAMROD_DATA_ENABLE_MW_BIND_MASK
value|0x1
define|#
directive|define
name|RDMA_REGISTER_TID_RAMROD_DATA_ENABLE_MW_BIND_SHIFT
value|31
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|RDMA_REGISTER_TID_RAMROD_DATA_PBL_PAGE_SIZE_LOG_MASK
value|0x1F
define|#
directive|define
name|RDMA_REGISTER_TID_RAMROD_DATA_PBL_PAGE_SIZE_LOG_SHIFT
value|0
define|#
directive|define
name|RDMA_REGISTER_TID_RAMROD_DATA_TID_TYPE_MASK
value|0x7
define|#
directive|define
name|RDMA_REGISTER_TID_RAMROD_DATA_TID_TYPE_SHIFT
value|5
name|u8
name|flags2
decl_stmt|;
define|#
directive|define
name|RDMA_REGISTER_TID_RAMROD_DATA_DMA_MR_MASK
value|0x1
comment|/* Bit indicating that this MR is DMA_MR meaning SGEs that use it have the physical address on them */
define|#
directive|define
name|RDMA_REGISTER_TID_RAMROD_DATA_DMA_MR_SHIFT
value|0
define|#
directive|define
name|RDMA_REGISTER_TID_RAMROD_DATA_DIF_ON_HOST_FLG_MASK
value|0x1
comment|/* Bit indicating that this MR has DIF protection enabled. */
define|#
directive|define
name|RDMA_REGISTER_TID_RAMROD_DATA_DIF_ON_HOST_FLG_SHIFT
value|1
define|#
directive|define
name|RDMA_REGISTER_TID_RAMROD_DATA_RESERVED1_MASK
value|0x3F
define|#
directive|define
name|RDMA_REGISTER_TID_RAMROD_DATA_RESERVED1_SHIFT
value|2
name|u8
name|key
decl_stmt|;
name|u8
name|length_hi
decl_stmt|;
name|u8
name|vf_id
comment|/* This field should be assigned to Virtual Function ID if vf_valid == 1. Otherwise its dont care */
decl_stmt|;
name|u8
name|vf_valid
decl_stmt|;
name|__le16
name|pd
decl_stmt|;
name|__le32
name|length_lo
comment|/* lower 32 bits of the registered MR length. */
decl_stmt|;
name|__le32
name|itid
decl_stmt|;
name|__le32
name|reserved2
decl_stmt|;
name|struct
name|regpair
name|va
decl_stmt|;
name|struct
name|regpair
name|pbl_base
decl_stmt|;
name|struct
name|regpair
name|dif_error_addr
comment|/* DIF TX IO writes error information to this location when memory region is invalidated. */
decl_stmt|;
name|struct
name|regpair
name|dif_runt_addr
comment|/* DIF RX IO writes runt value to this location when last RDMA Read of the IO has completed. */
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
comment|/*  * rdma resize cq output params  */
end_comment

begin_struct
struct|struct
name|rdma_resize_cq_output_params
block|{
name|__le32
name|old_cq_cons
comment|/* cq consumer value on old PBL */
decl_stmt|;
name|__le32
name|old_cq_prod
comment|/* cq producer value on old PBL */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * rdma resize cq ramrod data  */
end_comment

begin_struct
struct|struct
name|rdma_resize_cq_ramrod_data
block|{
name|u8
name|flags
decl_stmt|;
define|#
directive|define
name|RDMA_RESIZE_CQ_RAMROD_DATA_TOGGLE_BIT_MASK
value|0x1
define|#
directive|define
name|RDMA_RESIZE_CQ_RAMROD_DATA_TOGGLE_BIT_SHIFT
value|0
define|#
directive|define
name|RDMA_RESIZE_CQ_RAMROD_DATA_IS_TWO_LEVEL_PBL_MASK
value|0x1
define|#
directive|define
name|RDMA_RESIZE_CQ_RAMROD_DATA_IS_TWO_LEVEL_PBL_SHIFT
value|1
define|#
directive|define
name|RDMA_RESIZE_CQ_RAMROD_DATA_RESERVED_MASK
value|0x3F
define|#
directive|define
name|RDMA_RESIZE_CQ_RAMROD_DATA_RESERVED_SHIFT
value|2
name|u8
name|pbl_log_page_size
decl_stmt|;
name|__le16
name|pbl_num_pages
decl_stmt|;
name|__le32
name|max_cqes
decl_stmt|;
name|struct
name|regpair
name|pbl_addr
decl_stmt|;
name|struct
name|regpair
name|output_params_addr
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The rdma storm context of Mstorm  */
end_comment

begin_struct
struct|struct
name|rdma_srq_context
block|{
name|struct
name|regpair
name|temp
index|[
literal|8
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * rdma create qp requester ramrod data  */
end_comment

begin_struct
struct|struct
name|rdma_srq_create_ramrod_data
block|{
name|struct
name|regpair
name|pbl_base_addr
comment|/* SRQ PBL base address */
decl_stmt|;
name|__le16
name|pages_in_srq_pbl
comment|/* Number of pages in PBL */
decl_stmt|;
name|__le16
name|pd_id
decl_stmt|;
name|struct
name|rdma_srq_id
name|srq_id
comment|/* SRQ Index */
decl_stmt|;
name|__le16
name|page_size
comment|/* Page size in SGEs(16 bytes) elements. Supports up to 2M bytes page size */
decl_stmt|;
name|__le16
name|reserved1
decl_stmt|;
name|__le32
name|reserved2
decl_stmt|;
name|struct
name|regpair
name|producers_addr
comment|/* SRQ PBL base address */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * rdma create qp requester ramrod data  */
end_comment

begin_struct
struct|struct
name|rdma_srq_destroy_ramrod_data
block|{
name|struct
name|rdma_srq_id
name|srq_id
comment|/* SRQ Index */
decl_stmt|;
name|__le32
name|reserved
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * rdma create qp requester ramrod data  */
end_comment

begin_struct
struct|struct
name|rdma_srq_modify_ramrod_data
block|{
name|struct
name|rdma_srq_id
name|srq_id
comment|/* SRQ Index */
decl_stmt|;
name|__le32
name|wqe_limit
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * RDMA Tid type enumeration (for register_tid ramrod)  */
end_comment

begin_enum
enum|enum
name|rdma_tid_type
block|{
name|RDMA_TID_REGISTERED_MR
block|,
name|RDMA_TID_FMR
block|,
name|RDMA_TID_MW_TYPE1
block|,
name|RDMA_TID_MW_TYPE2A
block|,
name|MAX_RDMA_TID_TYPE
block|}
enum|;
end_enum

begin_struct
struct|struct
name|E4XstormRoceConnAgCtxDqExtLdPart
block|{
name|u8
name|reserved0
comment|/* cdu_validation */
decl_stmt|;
name|u8
name|state
comment|/* state */
decl_stmt|;
name|u8
name|flags0
decl_stmt|;
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_EXIST_IN_QM0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_EXIST_IN_QM0_SHIFT
value|0
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_BIT1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_BIT1_SHIFT
value|1
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_BIT2_MASK
value|0x1
comment|/* exist_in_qm2 */
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_BIT2_SHIFT
value|2
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_EXIST_IN_QM3_MASK
value|0x1
comment|/* exist_in_qm3 */
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_EXIST_IN_QM3_SHIFT
value|3
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_BIT4_MASK
value|0x1
comment|/* bit4 */
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_BIT4_SHIFT
value|4
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_BIT5_MASK
value|0x1
comment|/* cf_array_active */
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_BIT5_SHIFT
value|5
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_BIT6_MASK
value|0x1
comment|/* bit6 */
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_BIT6_SHIFT
value|6
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_BIT7_MASK
value|0x1
comment|/* bit7 */
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_BIT7_SHIFT
value|7
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_BIT8_MASK
value|0x1
comment|/* bit8 */
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_BIT8_SHIFT
value|0
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_BIT9_MASK
value|0x1
comment|/* bit9 */
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_BIT9_SHIFT
value|1
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_BIT10_MASK
value|0x1
comment|/* bit10 */
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_BIT10_SHIFT
value|2
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_BIT11_MASK
value|0x1
comment|/* bit11 */
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_BIT11_SHIFT
value|3
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_BIT12_MASK
value|0x1
comment|/* bit12 */
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_BIT12_SHIFT
value|4
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_MSTORM_FLUSH_MASK
value|0x1
comment|/* bit13 */
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_MSTORM_FLUSH_SHIFT
value|5
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_BIT14_MASK
value|0x1
comment|/* bit14 */
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_BIT14_SHIFT
value|6
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_YSTORM_FLUSH_MASK
value|0x1
comment|/* bit15 */
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_YSTORM_FLUSH_SHIFT
value|7
name|u8
name|flags2
decl_stmt|;
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_CF0_MASK
value|0x3
comment|/* timer0cf */
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_CF0_SHIFT
value|0
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_CF1_MASK
value|0x3
comment|/* timer1cf */
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_CF1_SHIFT
value|2
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_CF2_MASK
value|0x3
comment|/* timer2cf */
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_CF2_SHIFT
value|4
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_CF3_MASK
value|0x3
comment|/* timer_stop_all */
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_CF3_SHIFT
value|6
name|u8
name|flags3
decl_stmt|;
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_CF4_MASK
value|0x3
comment|/* cf4 */
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_CF4_SHIFT
value|0
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_CF5_MASK
value|0x3
comment|/* cf5 */
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_CF5_SHIFT
value|2
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_CF6_MASK
value|0x3
comment|/* cf6 */
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_CF6_SHIFT
value|4
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_FLUSH_Q0_CF_MASK
value|0x3
comment|/* cf7 */
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_FLUSH_Q0_CF_SHIFT
value|6
name|u8
name|flags4
decl_stmt|;
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_CF8_MASK
value|0x3
comment|/* cf8 */
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_CF8_SHIFT
value|0
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_CF9_MASK
value|0x3
comment|/* cf9 */
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_CF9_SHIFT
value|2
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_CF10_MASK
value|0x3
comment|/* cf10 */
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_CF10_SHIFT
value|4
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_CF11_MASK
value|0x3
comment|/* cf11 */
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_CF11_SHIFT
value|6
name|u8
name|flags5
decl_stmt|;
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_CF12_MASK
value|0x3
comment|/* cf12 */
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_CF12_SHIFT
value|0
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_CF13_MASK
value|0x3
comment|/* cf13 */
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_CF13_SHIFT
value|2
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_CF14_MASK
value|0x3
comment|/* cf14 */
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_CF14_SHIFT
value|4
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_CF15_MASK
value|0x3
comment|/* cf15 */
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_CF15_SHIFT
value|6
name|u8
name|flags6
decl_stmt|;
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_CF16_MASK
value|0x3
comment|/* cf16 */
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_CF16_SHIFT
value|0
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_CF17_MASK
value|0x3
comment|/* cf_array_cf */
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_CF17_SHIFT
value|2
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_CF18_MASK
value|0x3
comment|/* cf18 */
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_CF18_SHIFT
value|4
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_CF19_MASK
value|0x3
comment|/* cf19 */
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_CF19_SHIFT
value|6
name|u8
name|flags7
decl_stmt|;
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_CF20_MASK
value|0x3
comment|/* cf20 */
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_CF20_SHIFT
value|0
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_CF21_MASK
value|0x3
comment|/* cf21 */
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_CF21_SHIFT
value|2
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_SLOW_PATH_MASK
value|0x3
comment|/* cf22 */
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_SLOW_PATH_SHIFT
value|4
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_CF0EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_CF0EN_SHIFT
value|6
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_CF1EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_CF1EN_SHIFT
value|7
name|u8
name|flags8
decl_stmt|;
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_CF2EN_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_CF2EN_SHIFT
value|0
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_CF3EN_MASK
value|0x1
comment|/* cf3en */
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_CF3EN_SHIFT
value|1
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_CF4EN_MASK
value|0x1
comment|/* cf4en */
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_CF4EN_SHIFT
value|2
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_CF5EN_MASK
value|0x1
comment|/* cf5en */
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_CF5EN_SHIFT
value|3
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_CF6EN_MASK
value|0x1
comment|/* cf6en */
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_CF6EN_SHIFT
value|4
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_FLUSH_Q0_CF_EN_MASK
value|0x1
comment|/* cf7en */
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_FLUSH_Q0_CF_EN_SHIFT
value|5
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_CF8EN_MASK
value|0x1
comment|/* cf8en */
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_CF8EN_SHIFT
value|6
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_CF9EN_MASK
value|0x1
comment|/* cf9en */
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_CF9EN_SHIFT
value|7
name|u8
name|flags9
decl_stmt|;
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_CF10EN_MASK
value|0x1
comment|/* cf10en */
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_CF10EN_SHIFT
value|0
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_CF11EN_MASK
value|0x1
comment|/* cf11en */
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_CF11EN_SHIFT
value|1
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_CF12EN_MASK
value|0x1
comment|/* cf12en */
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_CF12EN_SHIFT
value|2
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_CF13EN_MASK
value|0x1
comment|/* cf13en */
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_CF13EN_SHIFT
value|3
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_CF14EN_MASK
value|0x1
comment|/* cf14en */
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_CF14EN_SHIFT
value|4
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_CF15EN_MASK
value|0x1
comment|/* cf15en */
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_CF15EN_SHIFT
value|5
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_CF16EN_MASK
value|0x1
comment|/* cf16en */
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_CF16EN_SHIFT
value|6
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_CF17EN_MASK
value|0x1
comment|/* cf_array_cf_en */
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_CF17EN_SHIFT
value|7
name|u8
name|flags10
decl_stmt|;
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_CF18EN_MASK
value|0x1
comment|/* cf18en */
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_CF18EN_SHIFT
value|0
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_CF19EN_MASK
value|0x1
comment|/* cf19en */
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_CF19EN_SHIFT
value|1
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_CF20EN_MASK
value|0x1
comment|/* cf20en */
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_CF20EN_SHIFT
value|2
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_CF21EN_MASK
value|0x1
comment|/* cf21en */
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_CF21EN_SHIFT
value|3
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_SLOW_PATH_EN_MASK
value|0x1
comment|/* cf22en */
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_SLOW_PATH_EN_SHIFT
value|4
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_CF23EN_MASK
value|0x1
comment|/* cf23en */
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_CF23EN_SHIFT
value|5
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_RULE0EN_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_RULE0EN_SHIFT
value|6
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_RULE1EN_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_RULE1EN_SHIFT
value|7
name|u8
name|flags11
decl_stmt|;
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_RULE2EN_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_RULE2EN_SHIFT
value|0
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_RULE3EN_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_RULE3EN_SHIFT
value|1
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_RULE4EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_RULE4EN_SHIFT
value|2
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_RULE5EN_MASK
value|0x1
comment|/* rule5en */
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_RULE5EN_SHIFT
value|3
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_RULE6EN_MASK
value|0x1
comment|/* rule6en */
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_RULE6EN_SHIFT
value|4
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_RULE7EN_MASK
value|0x1
comment|/* rule7en */
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_RULE7EN_SHIFT
value|5
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_A0_RESERVED1_MASK
value|0x1
comment|/* rule8en */
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_A0_RESERVED1_SHIFT
value|6
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_RULE9EN_MASK
value|0x1
comment|/* rule9en */
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_RULE9EN_SHIFT
value|7
name|u8
name|flags12
decl_stmt|;
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_RULE10EN_MASK
value|0x1
comment|/* rule10en */
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_RULE10EN_SHIFT
value|0
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_RULE11EN_MASK
value|0x1
comment|/* rule11en */
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_RULE11EN_SHIFT
value|1
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_A0_RESERVED2_MASK
value|0x1
comment|/* rule12en */
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_A0_RESERVED2_SHIFT
value|2
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_A0_RESERVED3_MASK
value|0x1
comment|/* rule13en */
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_A0_RESERVED3_SHIFT
value|3
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_RULE14EN_MASK
value|0x1
comment|/* rule14en */
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_RULE14EN_SHIFT
value|4
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_RULE15EN_MASK
value|0x1
comment|/* rule15en */
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_RULE15EN_SHIFT
value|5
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_RULE16EN_MASK
value|0x1
comment|/* rule16en */
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_RULE16EN_SHIFT
value|6
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_RULE17EN_MASK
value|0x1
comment|/* rule17en */
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_RULE17EN_SHIFT
value|7
name|u8
name|flags13
decl_stmt|;
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_RULE18EN_MASK
value|0x1
comment|/* rule18en */
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_RULE18EN_SHIFT
value|0
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_RULE19EN_MASK
value|0x1
comment|/* rule19en */
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_RULE19EN_SHIFT
value|1
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_A0_RESERVED4_MASK
value|0x1
comment|/* rule20en */
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_A0_RESERVED4_SHIFT
value|2
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_A0_RESERVED5_MASK
value|0x1
comment|/* rule21en */
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_A0_RESERVED5_SHIFT
value|3
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_A0_RESERVED6_MASK
value|0x1
comment|/* rule22en */
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_A0_RESERVED6_SHIFT
value|4
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_A0_RESERVED7_MASK
value|0x1
comment|/* rule23en */
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_A0_RESERVED7_SHIFT
value|5
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_A0_RESERVED8_MASK
value|0x1
comment|/* rule24en */
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_A0_RESERVED8_SHIFT
value|6
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_A0_RESERVED9_MASK
value|0x1
comment|/* rule25en */
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_A0_RESERVED9_SHIFT
value|7
name|u8
name|flags14
decl_stmt|;
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_MIGRATION_MASK
value|0x1
comment|/* bit16 */
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_MIGRATION_SHIFT
value|0
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_BIT17_MASK
value|0x1
comment|/* bit17 */
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_BIT17_SHIFT
value|1
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_DPM_PORT_NUM_MASK
value|0x3
comment|/* bit18 */
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_DPM_PORT_NUM_SHIFT
value|2
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_RESERVED_MASK
value|0x1
comment|/* bit20 */
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_RESERVED_SHIFT
value|4
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_ROCE_EDPM_ENABLE_MASK
value|0x1
comment|/* bit21 */
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_ROCE_EDPM_ENABLE_SHIFT
value|5
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_CF23_MASK
value|0x3
comment|/* cf23 */
define|#
directive|define
name|E4XSTORMROCECONNAGCTXDQEXTLDPART_CF23_SHIFT
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
name|conn_dpi
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
name|snd_nxt_psn
comment|/* reg3 */
decl_stmt|;
name|__le32
name|reg4
comment|/* reg4 */
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|e4_mstorm_rdma_conn_ag_ctx
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
name|E4_MSTORM_RDMA_CONN_AG_CTX_BIT0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E4_MSTORM_RDMA_CONN_AG_CTX_BIT0_SHIFT
value|0
define|#
directive|define
name|E4_MSTORM_RDMA_CONN_AG_CTX_BIT1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E4_MSTORM_RDMA_CONN_AG_CTX_BIT1_SHIFT
value|1
define|#
directive|define
name|E4_MSTORM_RDMA_CONN_AG_CTX_CF0_MASK
value|0x3
comment|/* cf0 */
define|#
directive|define
name|E4_MSTORM_RDMA_CONN_AG_CTX_CF0_SHIFT
value|2
define|#
directive|define
name|E4_MSTORM_RDMA_CONN_AG_CTX_CF1_MASK
value|0x3
comment|/* cf1 */
define|#
directive|define
name|E4_MSTORM_RDMA_CONN_AG_CTX_CF1_SHIFT
value|4
define|#
directive|define
name|E4_MSTORM_RDMA_CONN_AG_CTX_CF2_MASK
value|0x3
comment|/* cf2 */
define|#
directive|define
name|E4_MSTORM_RDMA_CONN_AG_CTX_CF2_SHIFT
value|6
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E4_MSTORM_RDMA_CONN_AG_CTX_CF0EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E4_MSTORM_RDMA_CONN_AG_CTX_CF0EN_SHIFT
value|0
define|#
directive|define
name|E4_MSTORM_RDMA_CONN_AG_CTX_CF1EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E4_MSTORM_RDMA_CONN_AG_CTX_CF1EN_SHIFT
value|1
define|#
directive|define
name|E4_MSTORM_RDMA_CONN_AG_CTX_CF2EN_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E4_MSTORM_RDMA_CONN_AG_CTX_CF2EN_SHIFT
value|2
define|#
directive|define
name|E4_MSTORM_RDMA_CONN_AG_CTX_RULE0EN_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E4_MSTORM_RDMA_CONN_AG_CTX_RULE0EN_SHIFT
value|3
define|#
directive|define
name|E4_MSTORM_RDMA_CONN_AG_CTX_RULE1EN_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E4_MSTORM_RDMA_CONN_AG_CTX_RULE1EN_SHIFT
value|4
define|#
directive|define
name|E4_MSTORM_RDMA_CONN_AG_CTX_RULE2EN_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E4_MSTORM_RDMA_CONN_AG_CTX_RULE2EN_SHIFT
value|5
define|#
directive|define
name|E4_MSTORM_RDMA_CONN_AG_CTX_RULE3EN_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E4_MSTORM_RDMA_CONN_AG_CTX_RULE3EN_SHIFT
value|6
define|#
directive|define
name|E4_MSTORM_RDMA_CONN_AG_CTX_RULE4EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E4_MSTORM_RDMA_CONN_AG_CTX_RULE4EN_SHIFT
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

begin_struct
struct|struct
name|e4_tstorm_rdma_conn_ag_ctx
block|{
name|u8
name|reserved0
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
name|E4_TSTORM_RDMA_CONN_AG_CTX_EXIST_IN_QM0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E4_TSTORM_RDMA_CONN_AG_CTX_EXIST_IN_QM0_SHIFT
value|0
define|#
directive|define
name|E4_TSTORM_RDMA_CONN_AG_CTX_BIT1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E4_TSTORM_RDMA_CONN_AG_CTX_BIT1_SHIFT
value|1
define|#
directive|define
name|E4_TSTORM_RDMA_CONN_AG_CTX_BIT2_MASK
value|0x1
comment|/* bit2 */
define|#
directive|define
name|E4_TSTORM_RDMA_CONN_AG_CTX_BIT2_SHIFT
value|2
define|#
directive|define
name|E4_TSTORM_RDMA_CONN_AG_CTX_BIT3_MASK
value|0x1
comment|/* bit3 */
define|#
directive|define
name|E4_TSTORM_RDMA_CONN_AG_CTX_BIT3_SHIFT
value|3
define|#
directive|define
name|E4_TSTORM_RDMA_CONN_AG_CTX_BIT4_MASK
value|0x1
comment|/* bit4 */
define|#
directive|define
name|E4_TSTORM_RDMA_CONN_AG_CTX_BIT4_SHIFT
value|4
define|#
directive|define
name|E4_TSTORM_RDMA_CONN_AG_CTX_BIT5_MASK
value|0x1
comment|/* bit5 */
define|#
directive|define
name|E4_TSTORM_RDMA_CONN_AG_CTX_BIT5_SHIFT
value|5
define|#
directive|define
name|E4_TSTORM_RDMA_CONN_AG_CTX_CF0_MASK
value|0x3
comment|/* timer0cf */
define|#
directive|define
name|E4_TSTORM_RDMA_CONN_AG_CTX_CF0_SHIFT
value|6
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E4_TSTORM_RDMA_CONN_AG_CTX_CF1_MASK
value|0x3
comment|/* timer1cf */
define|#
directive|define
name|E4_TSTORM_RDMA_CONN_AG_CTX_CF1_SHIFT
value|0
define|#
directive|define
name|E4_TSTORM_RDMA_CONN_AG_CTX_CF2_MASK
value|0x3
comment|/* timer2cf */
define|#
directive|define
name|E4_TSTORM_RDMA_CONN_AG_CTX_CF2_SHIFT
value|2
define|#
directive|define
name|E4_TSTORM_RDMA_CONN_AG_CTX_TIMER_STOP_ALL_CF_MASK
value|0x3
comment|/* timer_stop_all */
define|#
directive|define
name|E4_TSTORM_RDMA_CONN_AG_CTX_TIMER_STOP_ALL_CF_SHIFT
value|4
define|#
directive|define
name|E4_TSTORM_RDMA_CONN_AG_CTX_FLUSH_Q0_CF_MASK
value|0x3
comment|/* cf4 */
define|#
directive|define
name|E4_TSTORM_RDMA_CONN_AG_CTX_FLUSH_Q0_CF_SHIFT
value|6
name|u8
name|flags2
decl_stmt|;
define|#
directive|define
name|E4_TSTORM_RDMA_CONN_AG_CTX_MSTORM_FLUSH_CF_MASK
value|0x3
comment|/* cf5 */
define|#
directive|define
name|E4_TSTORM_RDMA_CONN_AG_CTX_MSTORM_FLUSH_CF_SHIFT
value|0
define|#
directive|define
name|E4_TSTORM_RDMA_CONN_AG_CTX_CF6_MASK
value|0x3
comment|/* cf6 */
define|#
directive|define
name|E4_TSTORM_RDMA_CONN_AG_CTX_CF6_SHIFT
value|2
define|#
directive|define
name|E4_TSTORM_RDMA_CONN_AG_CTX_CF7_MASK
value|0x3
comment|/* cf7 */
define|#
directive|define
name|E4_TSTORM_RDMA_CONN_AG_CTX_CF7_SHIFT
value|4
define|#
directive|define
name|E4_TSTORM_RDMA_CONN_AG_CTX_CF8_MASK
value|0x3
comment|/* cf8 */
define|#
directive|define
name|E4_TSTORM_RDMA_CONN_AG_CTX_CF8_SHIFT
value|6
name|u8
name|flags3
decl_stmt|;
define|#
directive|define
name|E4_TSTORM_RDMA_CONN_AG_CTX_CF9_MASK
value|0x3
comment|/* cf9 */
define|#
directive|define
name|E4_TSTORM_RDMA_CONN_AG_CTX_CF9_SHIFT
value|0
define|#
directive|define
name|E4_TSTORM_RDMA_CONN_AG_CTX_CF10_MASK
value|0x3
comment|/* cf10 */
define|#
directive|define
name|E4_TSTORM_RDMA_CONN_AG_CTX_CF10_SHIFT
value|2
define|#
directive|define
name|E4_TSTORM_RDMA_CONN_AG_CTX_CF0EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E4_TSTORM_RDMA_CONN_AG_CTX_CF0EN_SHIFT
value|4
define|#
directive|define
name|E4_TSTORM_RDMA_CONN_AG_CTX_CF1EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E4_TSTORM_RDMA_CONN_AG_CTX_CF1EN_SHIFT
value|5
define|#
directive|define
name|E4_TSTORM_RDMA_CONN_AG_CTX_CF2EN_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E4_TSTORM_RDMA_CONN_AG_CTX_CF2EN_SHIFT
value|6
define|#
directive|define
name|E4_TSTORM_RDMA_CONN_AG_CTX_TIMER_STOP_ALL_CF_EN_MASK
value|0x1
comment|/* cf3en */
define|#
directive|define
name|E4_TSTORM_RDMA_CONN_AG_CTX_TIMER_STOP_ALL_CF_EN_SHIFT
value|7
name|u8
name|flags4
decl_stmt|;
define|#
directive|define
name|E4_TSTORM_RDMA_CONN_AG_CTX_FLUSH_Q0_CF_EN_MASK
value|0x1
comment|/* cf4en */
define|#
directive|define
name|E4_TSTORM_RDMA_CONN_AG_CTX_FLUSH_Q0_CF_EN_SHIFT
value|0
define|#
directive|define
name|E4_TSTORM_RDMA_CONN_AG_CTX_MSTORM_FLUSH_CF_EN_MASK
value|0x1
comment|/* cf5en */
define|#
directive|define
name|E4_TSTORM_RDMA_CONN_AG_CTX_MSTORM_FLUSH_CF_EN_SHIFT
value|1
define|#
directive|define
name|E4_TSTORM_RDMA_CONN_AG_CTX_CF6EN_MASK
value|0x1
comment|/* cf6en */
define|#
directive|define
name|E4_TSTORM_RDMA_CONN_AG_CTX_CF6EN_SHIFT
value|2
define|#
directive|define
name|E4_TSTORM_RDMA_CONN_AG_CTX_CF7EN_MASK
value|0x1
comment|/* cf7en */
define|#
directive|define
name|E4_TSTORM_RDMA_CONN_AG_CTX_CF7EN_SHIFT
value|3
define|#
directive|define
name|E4_TSTORM_RDMA_CONN_AG_CTX_CF8EN_MASK
value|0x1
comment|/* cf8en */
define|#
directive|define
name|E4_TSTORM_RDMA_CONN_AG_CTX_CF8EN_SHIFT
value|4
define|#
directive|define
name|E4_TSTORM_RDMA_CONN_AG_CTX_CF9EN_MASK
value|0x1
comment|/* cf9en */
define|#
directive|define
name|E4_TSTORM_RDMA_CONN_AG_CTX_CF9EN_SHIFT
value|5
define|#
directive|define
name|E4_TSTORM_RDMA_CONN_AG_CTX_CF10EN_MASK
value|0x1
comment|/* cf10en */
define|#
directive|define
name|E4_TSTORM_RDMA_CONN_AG_CTX_CF10EN_SHIFT
value|6
define|#
directive|define
name|E4_TSTORM_RDMA_CONN_AG_CTX_RULE0EN_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E4_TSTORM_RDMA_CONN_AG_CTX_RULE0EN_SHIFT
value|7
name|u8
name|flags5
decl_stmt|;
define|#
directive|define
name|E4_TSTORM_RDMA_CONN_AG_CTX_RULE1EN_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E4_TSTORM_RDMA_CONN_AG_CTX_RULE1EN_SHIFT
value|0
define|#
directive|define
name|E4_TSTORM_RDMA_CONN_AG_CTX_RULE2EN_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E4_TSTORM_RDMA_CONN_AG_CTX_RULE2EN_SHIFT
value|1
define|#
directive|define
name|E4_TSTORM_RDMA_CONN_AG_CTX_RULE3EN_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E4_TSTORM_RDMA_CONN_AG_CTX_RULE3EN_SHIFT
value|2
define|#
directive|define
name|E4_TSTORM_RDMA_CONN_AG_CTX_RULE4EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E4_TSTORM_RDMA_CONN_AG_CTX_RULE4EN_SHIFT
value|3
define|#
directive|define
name|E4_TSTORM_RDMA_CONN_AG_CTX_RULE5EN_MASK
value|0x1
comment|/* rule5en */
define|#
directive|define
name|E4_TSTORM_RDMA_CONN_AG_CTX_RULE5EN_SHIFT
value|4
define|#
directive|define
name|E4_TSTORM_RDMA_CONN_AG_CTX_RULE6EN_MASK
value|0x1
comment|/* rule6en */
define|#
directive|define
name|E4_TSTORM_RDMA_CONN_AG_CTX_RULE6EN_SHIFT
value|5
define|#
directive|define
name|E4_TSTORM_RDMA_CONN_AG_CTX_RULE7EN_MASK
value|0x1
comment|/* rule7en */
define|#
directive|define
name|E4_TSTORM_RDMA_CONN_AG_CTX_RULE7EN_SHIFT
value|6
define|#
directive|define
name|E4_TSTORM_RDMA_CONN_AG_CTX_RULE8EN_MASK
value|0x1
comment|/* rule8en */
define|#
directive|define
name|E4_TSTORM_RDMA_CONN_AG_CTX_RULE8EN_SHIFT
value|7
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
name|__le32
name|reg4
comment|/* reg4 */
decl_stmt|;
name|__le32
name|reg5
comment|/* reg5 */
decl_stmt|;
name|__le32
name|reg6
comment|/* reg6 */
decl_stmt|;
name|__le32
name|reg7
comment|/* reg7 */
decl_stmt|;
name|__le32
name|reg8
comment|/* reg8 */
decl_stmt|;
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
name|u8
name|byte4
comment|/* byte4 */
decl_stmt|;
name|u8
name|byte5
comment|/* byte5 */
decl_stmt|;
name|__le16
name|word1
comment|/* word1 */
decl_stmt|;
name|__le16
name|word2
comment|/* conn_dpi */
decl_stmt|;
name|__le16
name|word3
comment|/* word3 */
decl_stmt|;
name|__le32
name|reg9
comment|/* reg9 */
decl_stmt|;
name|__le32
name|reg10
comment|/* reg10 */
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|e4_tstorm_rdma_task_ag_ctx
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
name|E4_TSTORM_RDMA_TASK_AG_CTX_NIBBLE0_MASK
value|0xF
comment|/* connection_type */
define|#
directive|define
name|E4_TSTORM_RDMA_TASK_AG_CTX_NIBBLE0_SHIFT
value|0
define|#
directive|define
name|E4_TSTORM_RDMA_TASK_AG_CTX_BIT0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E4_TSTORM_RDMA_TASK_AG_CTX_BIT0_SHIFT
value|4
define|#
directive|define
name|E4_TSTORM_RDMA_TASK_AG_CTX_BIT1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E4_TSTORM_RDMA_TASK_AG_CTX_BIT1_SHIFT
value|5
define|#
directive|define
name|E4_TSTORM_RDMA_TASK_AG_CTX_BIT2_MASK
value|0x1
comment|/* bit2 */
define|#
directive|define
name|E4_TSTORM_RDMA_TASK_AG_CTX_BIT2_SHIFT
value|6
define|#
directive|define
name|E4_TSTORM_RDMA_TASK_AG_CTX_BIT3_MASK
value|0x1
comment|/* bit3 */
define|#
directive|define
name|E4_TSTORM_RDMA_TASK_AG_CTX_BIT3_SHIFT
value|7
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E4_TSTORM_RDMA_TASK_AG_CTX_BIT4_MASK
value|0x1
comment|/* bit4 */
define|#
directive|define
name|E4_TSTORM_RDMA_TASK_AG_CTX_BIT4_SHIFT
value|0
define|#
directive|define
name|E4_TSTORM_RDMA_TASK_AG_CTX_BIT5_MASK
value|0x1
comment|/* bit5 */
define|#
directive|define
name|E4_TSTORM_RDMA_TASK_AG_CTX_BIT5_SHIFT
value|1
define|#
directive|define
name|E4_TSTORM_RDMA_TASK_AG_CTX_CF0_MASK
value|0x3
comment|/* timer0cf */
define|#
directive|define
name|E4_TSTORM_RDMA_TASK_AG_CTX_CF0_SHIFT
value|2
define|#
directive|define
name|E4_TSTORM_RDMA_TASK_AG_CTX_CF1_MASK
value|0x3
comment|/* timer1cf */
define|#
directive|define
name|E4_TSTORM_RDMA_TASK_AG_CTX_CF1_SHIFT
value|4
define|#
directive|define
name|E4_TSTORM_RDMA_TASK_AG_CTX_CF2_MASK
value|0x3
comment|/* timer2cf */
define|#
directive|define
name|E4_TSTORM_RDMA_TASK_AG_CTX_CF2_SHIFT
value|6
name|u8
name|flags2
decl_stmt|;
define|#
directive|define
name|E4_TSTORM_RDMA_TASK_AG_CTX_CF3_MASK
value|0x3
comment|/* timer_stop_all */
define|#
directive|define
name|E4_TSTORM_RDMA_TASK_AG_CTX_CF3_SHIFT
value|0
define|#
directive|define
name|E4_TSTORM_RDMA_TASK_AG_CTX_CF4_MASK
value|0x3
comment|/* cf4 */
define|#
directive|define
name|E4_TSTORM_RDMA_TASK_AG_CTX_CF4_SHIFT
value|2
define|#
directive|define
name|E4_TSTORM_RDMA_TASK_AG_CTX_CF5_MASK
value|0x3
comment|/* cf5 */
define|#
directive|define
name|E4_TSTORM_RDMA_TASK_AG_CTX_CF5_SHIFT
value|4
define|#
directive|define
name|E4_TSTORM_RDMA_TASK_AG_CTX_CF6_MASK
value|0x3
comment|/* cf6 */
define|#
directive|define
name|E4_TSTORM_RDMA_TASK_AG_CTX_CF6_SHIFT
value|6
name|u8
name|flags3
decl_stmt|;
define|#
directive|define
name|E4_TSTORM_RDMA_TASK_AG_CTX_CF7_MASK
value|0x3
comment|/* cf7 */
define|#
directive|define
name|E4_TSTORM_RDMA_TASK_AG_CTX_CF7_SHIFT
value|0
define|#
directive|define
name|E4_TSTORM_RDMA_TASK_AG_CTX_CF0EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E4_TSTORM_RDMA_TASK_AG_CTX_CF0EN_SHIFT
value|2
define|#
directive|define
name|E4_TSTORM_RDMA_TASK_AG_CTX_CF1EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E4_TSTORM_RDMA_TASK_AG_CTX_CF1EN_SHIFT
value|3
define|#
directive|define
name|E4_TSTORM_RDMA_TASK_AG_CTX_CF2EN_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E4_TSTORM_RDMA_TASK_AG_CTX_CF2EN_SHIFT
value|4
define|#
directive|define
name|E4_TSTORM_RDMA_TASK_AG_CTX_CF3EN_MASK
value|0x1
comment|/* cf3en */
define|#
directive|define
name|E4_TSTORM_RDMA_TASK_AG_CTX_CF3EN_SHIFT
value|5
define|#
directive|define
name|E4_TSTORM_RDMA_TASK_AG_CTX_CF4EN_MASK
value|0x1
comment|/* cf4en */
define|#
directive|define
name|E4_TSTORM_RDMA_TASK_AG_CTX_CF4EN_SHIFT
value|6
define|#
directive|define
name|E4_TSTORM_RDMA_TASK_AG_CTX_CF5EN_MASK
value|0x1
comment|/* cf5en */
define|#
directive|define
name|E4_TSTORM_RDMA_TASK_AG_CTX_CF5EN_SHIFT
value|7
name|u8
name|flags4
decl_stmt|;
define|#
directive|define
name|E4_TSTORM_RDMA_TASK_AG_CTX_CF6EN_MASK
value|0x1
comment|/* cf6en */
define|#
directive|define
name|E4_TSTORM_RDMA_TASK_AG_CTX_CF6EN_SHIFT
value|0
define|#
directive|define
name|E4_TSTORM_RDMA_TASK_AG_CTX_CF7EN_MASK
value|0x1
comment|/* cf7en */
define|#
directive|define
name|E4_TSTORM_RDMA_TASK_AG_CTX_CF7EN_SHIFT
value|1
define|#
directive|define
name|E4_TSTORM_RDMA_TASK_AG_CTX_RULE0EN_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E4_TSTORM_RDMA_TASK_AG_CTX_RULE0EN_SHIFT
value|2
define|#
directive|define
name|E4_TSTORM_RDMA_TASK_AG_CTX_RULE1EN_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E4_TSTORM_RDMA_TASK_AG_CTX_RULE1EN_SHIFT
value|3
define|#
directive|define
name|E4_TSTORM_RDMA_TASK_AG_CTX_RULE2EN_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E4_TSTORM_RDMA_TASK_AG_CTX_RULE2EN_SHIFT
value|4
define|#
directive|define
name|E4_TSTORM_RDMA_TASK_AG_CTX_RULE3EN_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E4_TSTORM_RDMA_TASK_AG_CTX_RULE3EN_SHIFT
value|5
define|#
directive|define
name|E4_TSTORM_RDMA_TASK_AG_CTX_RULE4EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E4_TSTORM_RDMA_TASK_AG_CTX_RULE4EN_SHIFT
value|6
define|#
directive|define
name|E4_TSTORM_RDMA_TASK_AG_CTX_RULE5EN_MASK
value|0x1
comment|/* rule5en */
define|#
directive|define
name|E4_TSTORM_RDMA_TASK_AG_CTX_RULE5EN_SHIFT
value|7
name|u8
name|byte2
comment|/* byte2 */
decl_stmt|;
name|__le16
name|word1
comment|/* word1 */
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
name|e4_ustorm_rdma_conn_ag_ctx
block|{
name|u8
name|reserved
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
name|E4_USTORM_RDMA_CONN_AG_CTX_EXIST_IN_QM0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E4_USTORM_RDMA_CONN_AG_CTX_EXIST_IN_QM0_SHIFT
value|0
define|#
directive|define
name|E4_USTORM_RDMA_CONN_AG_CTX_BIT1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E4_USTORM_RDMA_CONN_AG_CTX_BIT1_SHIFT
value|1
define|#
directive|define
name|E4_USTORM_RDMA_CONN_AG_CTX_FLUSH_Q0_CF_MASK
value|0x3
comment|/* timer0cf */
define|#
directive|define
name|E4_USTORM_RDMA_CONN_AG_CTX_FLUSH_Q0_CF_SHIFT
value|2
define|#
directive|define
name|E4_USTORM_RDMA_CONN_AG_CTX_CF1_MASK
value|0x3
comment|/* timer1cf */
define|#
directive|define
name|E4_USTORM_RDMA_CONN_AG_CTX_CF1_SHIFT
value|4
define|#
directive|define
name|E4_USTORM_RDMA_CONN_AG_CTX_CF2_MASK
value|0x3
comment|/* timer2cf */
define|#
directive|define
name|E4_USTORM_RDMA_CONN_AG_CTX_CF2_SHIFT
value|6
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E4_USTORM_RDMA_CONN_AG_CTX_CF3_MASK
value|0x3
comment|/* timer_stop_all */
define|#
directive|define
name|E4_USTORM_RDMA_CONN_AG_CTX_CF3_SHIFT
value|0
define|#
directive|define
name|E4_USTORM_RDMA_CONN_AG_CTX_CQ_ARM_SE_CF_MASK
value|0x3
comment|/* cf4 */
define|#
directive|define
name|E4_USTORM_RDMA_CONN_AG_CTX_CQ_ARM_SE_CF_SHIFT
value|2
define|#
directive|define
name|E4_USTORM_RDMA_CONN_AG_CTX_CQ_ARM_CF_MASK
value|0x3
comment|/* cf5 */
define|#
directive|define
name|E4_USTORM_RDMA_CONN_AG_CTX_CQ_ARM_CF_SHIFT
value|4
define|#
directive|define
name|E4_USTORM_RDMA_CONN_AG_CTX_CF6_MASK
value|0x3
comment|/* cf6 */
define|#
directive|define
name|E4_USTORM_RDMA_CONN_AG_CTX_CF6_SHIFT
value|6
name|u8
name|flags2
decl_stmt|;
define|#
directive|define
name|E4_USTORM_RDMA_CONN_AG_CTX_FLUSH_Q0_CF_EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E4_USTORM_RDMA_CONN_AG_CTX_FLUSH_Q0_CF_EN_SHIFT
value|0
define|#
directive|define
name|E4_USTORM_RDMA_CONN_AG_CTX_CF1EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E4_USTORM_RDMA_CONN_AG_CTX_CF1EN_SHIFT
value|1
define|#
directive|define
name|E4_USTORM_RDMA_CONN_AG_CTX_CF2EN_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E4_USTORM_RDMA_CONN_AG_CTX_CF2EN_SHIFT
value|2
define|#
directive|define
name|E4_USTORM_RDMA_CONN_AG_CTX_CF3EN_MASK
value|0x1
comment|/* cf3en */
define|#
directive|define
name|E4_USTORM_RDMA_CONN_AG_CTX_CF3EN_SHIFT
value|3
define|#
directive|define
name|E4_USTORM_RDMA_CONN_AG_CTX_CQ_ARM_SE_CF_EN_MASK
value|0x1
comment|/* cf4en */
define|#
directive|define
name|E4_USTORM_RDMA_CONN_AG_CTX_CQ_ARM_SE_CF_EN_SHIFT
value|4
define|#
directive|define
name|E4_USTORM_RDMA_CONN_AG_CTX_CQ_ARM_CF_EN_MASK
value|0x1
comment|/* cf5en */
define|#
directive|define
name|E4_USTORM_RDMA_CONN_AG_CTX_CQ_ARM_CF_EN_SHIFT
value|5
define|#
directive|define
name|E4_USTORM_RDMA_CONN_AG_CTX_CF6EN_MASK
value|0x1
comment|/* cf6en */
define|#
directive|define
name|E4_USTORM_RDMA_CONN_AG_CTX_CF6EN_SHIFT
value|6
define|#
directive|define
name|E4_USTORM_RDMA_CONN_AG_CTX_CQ_SE_EN_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E4_USTORM_RDMA_CONN_AG_CTX_CQ_SE_EN_SHIFT
value|7
name|u8
name|flags3
decl_stmt|;
define|#
directive|define
name|E4_USTORM_RDMA_CONN_AG_CTX_CQ_EN_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E4_USTORM_RDMA_CONN_AG_CTX_CQ_EN_SHIFT
value|0
define|#
directive|define
name|E4_USTORM_RDMA_CONN_AG_CTX_RULE2EN_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E4_USTORM_RDMA_CONN_AG_CTX_RULE2EN_SHIFT
value|1
define|#
directive|define
name|E4_USTORM_RDMA_CONN_AG_CTX_RULE3EN_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E4_USTORM_RDMA_CONN_AG_CTX_RULE3EN_SHIFT
value|2
define|#
directive|define
name|E4_USTORM_RDMA_CONN_AG_CTX_RULE4EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E4_USTORM_RDMA_CONN_AG_CTX_RULE4EN_SHIFT
value|3
define|#
directive|define
name|E4_USTORM_RDMA_CONN_AG_CTX_RULE5EN_MASK
value|0x1
comment|/* rule5en */
define|#
directive|define
name|E4_USTORM_RDMA_CONN_AG_CTX_RULE5EN_SHIFT
value|4
define|#
directive|define
name|E4_USTORM_RDMA_CONN_AG_CTX_RULE6EN_MASK
value|0x1
comment|/* rule6en */
define|#
directive|define
name|E4_USTORM_RDMA_CONN_AG_CTX_RULE6EN_SHIFT
value|5
define|#
directive|define
name|E4_USTORM_RDMA_CONN_AG_CTX_RULE7EN_MASK
value|0x1
comment|/* rule7en */
define|#
directive|define
name|E4_USTORM_RDMA_CONN_AG_CTX_RULE7EN_SHIFT
value|6
define|#
directive|define
name|E4_USTORM_RDMA_CONN_AG_CTX_RULE8EN_MASK
value|0x1
comment|/* rule8en */
define|#
directive|define
name|E4_USTORM_RDMA_CONN_AG_CTX_RULE8EN_SHIFT
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
name|conn_dpi
comment|/* conn_dpi */
decl_stmt|;
name|__le16
name|word1
comment|/* word1 */
decl_stmt|;
name|__le32
name|cq_cons
comment|/* reg0 */
decl_stmt|;
name|__le32
name|cq_se_prod
comment|/* reg1 */
decl_stmt|;
name|__le32
name|cq_prod
comment|/* reg2 */
decl_stmt|;
name|__le32
name|reg3
comment|/* reg3 */
decl_stmt|;
name|__le16
name|int_timeout
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
name|e4_xstorm_rdma_conn_ag_ctx
block|{
name|u8
name|reserved0
comment|/* cdu_validation */
decl_stmt|;
name|u8
name|state
comment|/* state */
decl_stmt|;
name|u8
name|flags0
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_EXIST_IN_QM0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_EXIST_IN_QM0_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_BIT1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_BIT1_SHIFT
value|1
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_BIT2_MASK
value|0x1
comment|/* exist_in_qm2 */
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_BIT2_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_EXIST_IN_QM3_MASK
value|0x1
comment|/* exist_in_qm3 */
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_EXIST_IN_QM3_SHIFT
value|3
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_BIT4_MASK
value|0x1
comment|/* bit4 */
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_BIT4_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_BIT5_MASK
value|0x1
comment|/* cf_array_active */
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_BIT5_SHIFT
value|5
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_BIT6_MASK
value|0x1
comment|/* bit6 */
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_BIT6_SHIFT
value|6
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_BIT7_MASK
value|0x1
comment|/* bit7 */
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_BIT7_SHIFT
value|7
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_BIT8_MASK
value|0x1
comment|/* bit8 */
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_BIT8_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_BIT9_MASK
value|0x1
comment|/* bit9 */
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_BIT9_SHIFT
value|1
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_BIT10_MASK
value|0x1
comment|/* bit10 */
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_BIT10_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_BIT11_MASK
value|0x1
comment|/* bit11 */
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_BIT11_SHIFT
value|3
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_BIT12_MASK
value|0x1
comment|/* bit12 */
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_BIT12_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_MSTORM_FLUSH_MASK
value|0x1
comment|/* bit13 */
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_MSTORM_FLUSH_SHIFT
value|5
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_BIT14_MASK
value|0x1
comment|/* bit14 */
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_BIT14_SHIFT
value|6
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_YSTORM_FLUSH_MASK
value|0x1
comment|/* bit15 */
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_YSTORM_FLUSH_SHIFT
value|7
name|u8
name|flags2
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_CF0_MASK
value|0x3
comment|/* timer0cf */
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_CF0_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_CF1_MASK
value|0x3
comment|/* timer1cf */
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_CF1_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_CF2_MASK
value|0x3
comment|/* timer2cf */
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_CF2_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_CF3_MASK
value|0x3
comment|/* timer_stop_all */
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_CF3_SHIFT
value|6
name|u8
name|flags3
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_CF4_MASK
value|0x3
comment|/* cf4 */
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_CF4_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_CF5_MASK
value|0x3
comment|/* cf5 */
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_CF5_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_CF6_MASK
value|0x3
comment|/* cf6 */
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_CF6_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_FLUSH_Q0_CF_MASK
value|0x3
comment|/* cf7 */
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_FLUSH_Q0_CF_SHIFT
value|6
name|u8
name|flags4
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_CF8_MASK
value|0x3
comment|/* cf8 */
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_CF8_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_CF9_MASK
value|0x3
comment|/* cf9 */
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_CF9_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_CF10_MASK
value|0x3
comment|/* cf10 */
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_CF10_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_CF11_MASK
value|0x3
comment|/* cf11 */
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_CF11_SHIFT
value|6
name|u8
name|flags5
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_CF12_MASK
value|0x3
comment|/* cf12 */
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_CF12_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_CF13_MASK
value|0x3
comment|/* cf13 */
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_CF13_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_CF14_MASK
value|0x3
comment|/* cf14 */
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_CF14_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_CF15_MASK
value|0x3
comment|/* cf15 */
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_CF15_SHIFT
value|6
name|u8
name|flags6
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_CF16_MASK
value|0x3
comment|/* cf16 */
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_CF16_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_CF17_MASK
value|0x3
comment|/* cf_array_cf */
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_CF17_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_CF18_MASK
value|0x3
comment|/* cf18 */
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_CF18_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_CF19_MASK
value|0x3
comment|/* cf19 */
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_CF19_SHIFT
value|6
name|u8
name|flags7
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_CF20_MASK
value|0x3
comment|/* cf20 */
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_CF20_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_CF21_MASK
value|0x3
comment|/* cf21 */
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_CF21_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_SLOW_PATH_MASK
value|0x3
comment|/* cf22 */
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_SLOW_PATH_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_CF0EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_CF0EN_SHIFT
value|6
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_CF1EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_CF1EN_SHIFT
value|7
name|u8
name|flags8
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_CF2EN_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_CF2EN_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_CF3EN_MASK
value|0x1
comment|/* cf3en */
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_CF3EN_SHIFT
value|1
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_CF4EN_MASK
value|0x1
comment|/* cf4en */
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_CF4EN_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_CF5EN_MASK
value|0x1
comment|/* cf5en */
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_CF5EN_SHIFT
value|3
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_CF6EN_MASK
value|0x1
comment|/* cf6en */
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_CF6EN_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_FLUSH_Q0_CF_EN_MASK
value|0x1
comment|/* cf7en */
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_FLUSH_Q0_CF_EN_SHIFT
value|5
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_CF8EN_MASK
value|0x1
comment|/* cf8en */
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_CF8EN_SHIFT
value|6
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_CF9EN_MASK
value|0x1
comment|/* cf9en */
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_CF9EN_SHIFT
value|7
name|u8
name|flags9
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_CF10EN_MASK
value|0x1
comment|/* cf10en */
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_CF10EN_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_CF11EN_MASK
value|0x1
comment|/* cf11en */
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_CF11EN_SHIFT
value|1
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_CF12EN_MASK
value|0x1
comment|/* cf12en */
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_CF12EN_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_CF13EN_MASK
value|0x1
comment|/* cf13en */
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_CF13EN_SHIFT
value|3
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_CF14EN_MASK
value|0x1
comment|/* cf14en */
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_CF14EN_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_CF15EN_MASK
value|0x1
comment|/* cf15en */
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_CF15EN_SHIFT
value|5
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_CF16EN_MASK
value|0x1
comment|/* cf16en */
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_CF16EN_SHIFT
value|6
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_CF17EN_MASK
value|0x1
comment|/* cf_array_cf_en */
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_CF17EN_SHIFT
value|7
name|u8
name|flags10
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_CF18EN_MASK
value|0x1
comment|/* cf18en */
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_CF18EN_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_CF19EN_MASK
value|0x1
comment|/* cf19en */
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_CF19EN_SHIFT
value|1
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_CF20EN_MASK
value|0x1
comment|/* cf20en */
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_CF20EN_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_CF21EN_MASK
value|0x1
comment|/* cf21en */
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_CF21EN_SHIFT
value|3
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_SLOW_PATH_EN_MASK
value|0x1
comment|/* cf22en */
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_SLOW_PATH_EN_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_CF23EN_MASK
value|0x1
comment|/* cf23en */
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_CF23EN_SHIFT
value|5
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_RULE0EN_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_RULE0EN_SHIFT
value|6
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_RULE1EN_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_RULE1EN_SHIFT
value|7
name|u8
name|flags11
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_RULE2EN_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_RULE2EN_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_RULE3EN_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_RULE3EN_SHIFT
value|1
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_RULE4EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_RULE4EN_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_RULE5EN_MASK
value|0x1
comment|/* rule5en */
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_RULE5EN_SHIFT
value|3
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_RULE6EN_MASK
value|0x1
comment|/* rule6en */
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_RULE6EN_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_RULE7EN_MASK
value|0x1
comment|/* rule7en */
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_RULE7EN_SHIFT
value|5
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_A0_RESERVED1_MASK
value|0x1
comment|/* rule8en */
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_A0_RESERVED1_SHIFT
value|6
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_RULE9EN_MASK
value|0x1
comment|/* rule9en */
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_RULE9EN_SHIFT
value|7
name|u8
name|flags12
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_RULE10EN_MASK
value|0x1
comment|/* rule10en */
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_RULE10EN_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_RULE11EN_MASK
value|0x1
comment|/* rule11en */
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_RULE11EN_SHIFT
value|1
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_A0_RESERVED2_MASK
value|0x1
comment|/* rule12en */
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_A0_RESERVED2_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_A0_RESERVED3_MASK
value|0x1
comment|/* rule13en */
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_A0_RESERVED3_SHIFT
value|3
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_RULE14EN_MASK
value|0x1
comment|/* rule14en */
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_RULE14EN_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_RULE15EN_MASK
value|0x1
comment|/* rule15en */
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_RULE15EN_SHIFT
value|5
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_RULE16EN_MASK
value|0x1
comment|/* rule16en */
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_RULE16EN_SHIFT
value|6
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_RULE17EN_MASK
value|0x1
comment|/* rule17en */
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_RULE17EN_SHIFT
value|7
name|u8
name|flags13
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_RULE18EN_MASK
value|0x1
comment|/* rule18en */
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_RULE18EN_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_RULE19EN_MASK
value|0x1
comment|/* rule19en */
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_RULE19EN_SHIFT
value|1
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_A0_RESERVED4_MASK
value|0x1
comment|/* rule20en */
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_A0_RESERVED4_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_A0_RESERVED5_MASK
value|0x1
comment|/* rule21en */
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_A0_RESERVED5_SHIFT
value|3
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_A0_RESERVED6_MASK
value|0x1
comment|/* rule22en */
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_A0_RESERVED6_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_A0_RESERVED7_MASK
value|0x1
comment|/* rule23en */
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_A0_RESERVED7_SHIFT
value|5
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_A0_RESERVED8_MASK
value|0x1
comment|/* rule24en */
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_A0_RESERVED8_SHIFT
value|6
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_A0_RESERVED9_MASK
value|0x1
comment|/* rule25en */
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_A0_RESERVED9_SHIFT
value|7
name|u8
name|flags14
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_MIGRATION_MASK
value|0x1
comment|/* bit16 */
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_MIGRATION_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_BIT17_MASK
value|0x1
comment|/* bit17 */
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_BIT17_SHIFT
value|1
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_DPM_PORT_NUM_MASK
value|0x3
comment|/* bit18 */
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_DPM_PORT_NUM_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_RESERVED_MASK
value|0x1
comment|/* bit20 */
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_RESERVED_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_ROCE_EDPM_ENABLE_MASK
value|0x1
comment|/* bit21 */
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_ROCE_EDPM_ENABLE_SHIFT
value|5
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_CF23_MASK
value|0x3
comment|/* cf23 */
define|#
directive|define
name|E4_XSTORM_RDMA_CONN_AG_CTX_CF23_SHIFT
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
name|conn_dpi
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
name|snd_nxt_psn
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
block|}
struct|;
end_struct

begin_struct
struct|struct
name|e4_ystorm_rdma_conn_ag_ctx
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
name|E4_YSTORM_RDMA_CONN_AG_CTX_BIT0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E4_YSTORM_RDMA_CONN_AG_CTX_BIT0_SHIFT
value|0
define|#
directive|define
name|E4_YSTORM_RDMA_CONN_AG_CTX_BIT1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E4_YSTORM_RDMA_CONN_AG_CTX_BIT1_SHIFT
value|1
define|#
directive|define
name|E4_YSTORM_RDMA_CONN_AG_CTX_CF0_MASK
value|0x3
comment|/* cf0 */
define|#
directive|define
name|E4_YSTORM_RDMA_CONN_AG_CTX_CF0_SHIFT
value|2
define|#
directive|define
name|E4_YSTORM_RDMA_CONN_AG_CTX_CF1_MASK
value|0x3
comment|/* cf1 */
define|#
directive|define
name|E4_YSTORM_RDMA_CONN_AG_CTX_CF1_SHIFT
value|4
define|#
directive|define
name|E4_YSTORM_RDMA_CONN_AG_CTX_CF2_MASK
value|0x3
comment|/* cf2 */
define|#
directive|define
name|E4_YSTORM_RDMA_CONN_AG_CTX_CF2_SHIFT
value|6
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E4_YSTORM_RDMA_CONN_AG_CTX_CF0EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E4_YSTORM_RDMA_CONN_AG_CTX_CF0EN_SHIFT
value|0
define|#
directive|define
name|E4_YSTORM_RDMA_CONN_AG_CTX_CF1EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E4_YSTORM_RDMA_CONN_AG_CTX_CF1EN_SHIFT
value|1
define|#
directive|define
name|E4_YSTORM_RDMA_CONN_AG_CTX_CF2EN_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E4_YSTORM_RDMA_CONN_AG_CTX_CF2EN_SHIFT
value|2
define|#
directive|define
name|E4_YSTORM_RDMA_CONN_AG_CTX_RULE0EN_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E4_YSTORM_RDMA_CONN_AG_CTX_RULE0EN_SHIFT
value|3
define|#
directive|define
name|E4_YSTORM_RDMA_CONN_AG_CTX_RULE1EN_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E4_YSTORM_RDMA_CONN_AG_CTX_RULE1EN_SHIFT
value|4
define|#
directive|define
name|E4_YSTORM_RDMA_CONN_AG_CTX_RULE2EN_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E4_YSTORM_RDMA_CONN_AG_CTX_RULE2EN_SHIFT
value|5
define|#
directive|define
name|E4_YSTORM_RDMA_CONN_AG_CTX_RULE3EN_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E4_YSTORM_RDMA_CONN_AG_CTX_RULE3EN_SHIFT
value|6
define|#
directive|define
name|E4_YSTORM_RDMA_CONN_AG_CTX_RULE4EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E4_YSTORM_RDMA_CONN_AG_CTX_RULE4EN_SHIFT
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
name|e5_mstorm_rdma_conn_ag_ctx
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
name|E5_MSTORM_RDMA_CONN_AG_CTX_BIT0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E5_MSTORM_RDMA_CONN_AG_CTX_BIT0_SHIFT
value|0
define|#
directive|define
name|E5_MSTORM_RDMA_CONN_AG_CTX_BIT1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E5_MSTORM_RDMA_CONN_AG_CTX_BIT1_SHIFT
value|1
define|#
directive|define
name|E5_MSTORM_RDMA_CONN_AG_CTX_CF0_MASK
value|0x3
comment|/* cf0 */
define|#
directive|define
name|E5_MSTORM_RDMA_CONN_AG_CTX_CF0_SHIFT
value|2
define|#
directive|define
name|E5_MSTORM_RDMA_CONN_AG_CTX_CF1_MASK
value|0x3
comment|/* cf1 */
define|#
directive|define
name|E5_MSTORM_RDMA_CONN_AG_CTX_CF1_SHIFT
value|4
define|#
directive|define
name|E5_MSTORM_RDMA_CONN_AG_CTX_CF2_MASK
value|0x3
comment|/* cf2 */
define|#
directive|define
name|E5_MSTORM_RDMA_CONN_AG_CTX_CF2_SHIFT
value|6
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E5_MSTORM_RDMA_CONN_AG_CTX_CF0EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E5_MSTORM_RDMA_CONN_AG_CTX_CF0EN_SHIFT
value|0
define|#
directive|define
name|E5_MSTORM_RDMA_CONN_AG_CTX_CF1EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E5_MSTORM_RDMA_CONN_AG_CTX_CF1EN_SHIFT
value|1
define|#
directive|define
name|E5_MSTORM_RDMA_CONN_AG_CTX_CF2EN_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E5_MSTORM_RDMA_CONN_AG_CTX_CF2EN_SHIFT
value|2
define|#
directive|define
name|E5_MSTORM_RDMA_CONN_AG_CTX_RULE0EN_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E5_MSTORM_RDMA_CONN_AG_CTX_RULE0EN_SHIFT
value|3
define|#
directive|define
name|E5_MSTORM_RDMA_CONN_AG_CTX_RULE1EN_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E5_MSTORM_RDMA_CONN_AG_CTX_RULE1EN_SHIFT
value|4
define|#
directive|define
name|E5_MSTORM_RDMA_CONN_AG_CTX_RULE2EN_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E5_MSTORM_RDMA_CONN_AG_CTX_RULE2EN_SHIFT
value|5
define|#
directive|define
name|E5_MSTORM_RDMA_CONN_AG_CTX_RULE3EN_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E5_MSTORM_RDMA_CONN_AG_CTX_RULE3EN_SHIFT
value|6
define|#
directive|define
name|E5_MSTORM_RDMA_CONN_AG_CTX_RULE4EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E5_MSTORM_RDMA_CONN_AG_CTX_RULE4EN_SHIFT
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

begin_struct
struct|struct
name|e5_tstorm_rdma_conn_ag_ctx
block|{
name|u8
name|reserved0
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
name|E5_TSTORM_RDMA_CONN_AG_CTX_EXIST_IN_QM0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E5_TSTORM_RDMA_CONN_AG_CTX_EXIST_IN_QM0_SHIFT
value|0
define|#
directive|define
name|E5_TSTORM_RDMA_CONN_AG_CTX_BIT1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E5_TSTORM_RDMA_CONN_AG_CTX_BIT1_SHIFT
value|1
define|#
directive|define
name|E5_TSTORM_RDMA_CONN_AG_CTX_BIT2_MASK
value|0x1
comment|/* bit2 */
define|#
directive|define
name|E5_TSTORM_RDMA_CONN_AG_CTX_BIT2_SHIFT
value|2
define|#
directive|define
name|E5_TSTORM_RDMA_CONN_AG_CTX_BIT3_MASK
value|0x1
comment|/* bit3 */
define|#
directive|define
name|E5_TSTORM_RDMA_CONN_AG_CTX_BIT3_SHIFT
value|3
define|#
directive|define
name|E5_TSTORM_RDMA_CONN_AG_CTX_BIT4_MASK
value|0x1
comment|/* bit4 */
define|#
directive|define
name|E5_TSTORM_RDMA_CONN_AG_CTX_BIT4_SHIFT
value|4
define|#
directive|define
name|E5_TSTORM_RDMA_CONN_AG_CTX_BIT5_MASK
value|0x1
comment|/* bit5 */
define|#
directive|define
name|E5_TSTORM_RDMA_CONN_AG_CTX_BIT5_SHIFT
value|5
define|#
directive|define
name|E5_TSTORM_RDMA_CONN_AG_CTX_CF0_MASK
value|0x3
comment|/* timer0cf */
define|#
directive|define
name|E5_TSTORM_RDMA_CONN_AG_CTX_CF0_SHIFT
value|6
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E5_TSTORM_RDMA_CONN_AG_CTX_CF1_MASK
value|0x3
comment|/* timer1cf */
define|#
directive|define
name|E5_TSTORM_RDMA_CONN_AG_CTX_CF1_SHIFT
value|0
define|#
directive|define
name|E5_TSTORM_RDMA_CONN_AG_CTX_CF2_MASK
value|0x3
comment|/* timer2cf */
define|#
directive|define
name|E5_TSTORM_RDMA_CONN_AG_CTX_CF2_SHIFT
value|2
define|#
directive|define
name|E5_TSTORM_RDMA_CONN_AG_CTX_TIMER_STOP_ALL_CF_MASK
value|0x3
comment|/* timer_stop_all */
define|#
directive|define
name|E5_TSTORM_RDMA_CONN_AG_CTX_TIMER_STOP_ALL_CF_SHIFT
value|4
define|#
directive|define
name|E5_TSTORM_RDMA_CONN_AG_CTX_FLUSH_Q0_CF_MASK
value|0x3
comment|/* cf4 */
define|#
directive|define
name|E5_TSTORM_RDMA_CONN_AG_CTX_FLUSH_Q0_CF_SHIFT
value|6
name|u8
name|flags2
decl_stmt|;
define|#
directive|define
name|E5_TSTORM_RDMA_CONN_AG_CTX_MSTORM_FLUSH_CF_MASK
value|0x3
comment|/* cf5 */
define|#
directive|define
name|E5_TSTORM_RDMA_CONN_AG_CTX_MSTORM_FLUSH_CF_SHIFT
value|0
define|#
directive|define
name|E5_TSTORM_RDMA_CONN_AG_CTX_CF6_MASK
value|0x3
comment|/* cf6 */
define|#
directive|define
name|E5_TSTORM_RDMA_CONN_AG_CTX_CF6_SHIFT
value|2
define|#
directive|define
name|E5_TSTORM_RDMA_CONN_AG_CTX_CF7_MASK
value|0x3
comment|/* cf7 */
define|#
directive|define
name|E5_TSTORM_RDMA_CONN_AG_CTX_CF7_SHIFT
value|4
define|#
directive|define
name|E5_TSTORM_RDMA_CONN_AG_CTX_CF8_MASK
value|0x3
comment|/* cf8 */
define|#
directive|define
name|E5_TSTORM_RDMA_CONN_AG_CTX_CF8_SHIFT
value|6
name|u8
name|flags3
decl_stmt|;
define|#
directive|define
name|E5_TSTORM_RDMA_CONN_AG_CTX_CF9_MASK
value|0x3
comment|/* cf9 */
define|#
directive|define
name|E5_TSTORM_RDMA_CONN_AG_CTX_CF9_SHIFT
value|0
define|#
directive|define
name|E5_TSTORM_RDMA_CONN_AG_CTX_CF10_MASK
value|0x3
comment|/* cf10 */
define|#
directive|define
name|E5_TSTORM_RDMA_CONN_AG_CTX_CF10_SHIFT
value|2
define|#
directive|define
name|E5_TSTORM_RDMA_CONN_AG_CTX_CF0EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E5_TSTORM_RDMA_CONN_AG_CTX_CF0EN_SHIFT
value|4
define|#
directive|define
name|E5_TSTORM_RDMA_CONN_AG_CTX_CF1EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E5_TSTORM_RDMA_CONN_AG_CTX_CF1EN_SHIFT
value|5
define|#
directive|define
name|E5_TSTORM_RDMA_CONN_AG_CTX_CF2EN_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E5_TSTORM_RDMA_CONN_AG_CTX_CF2EN_SHIFT
value|6
define|#
directive|define
name|E5_TSTORM_RDMA_CONN_AG_CTX_TIMER_STOP_ALL_CF_EN_MASK
value|0x1
comment|/* cf3en */
define|#
directive|define
name|E5_TSTORM_RDMA_CONN_AG_CTX_TIMER_STOP_ALL_CF_EN_SHIFT
value|7
name|u8
name|flags4
decl_stmt|;
define|#
directive|define
name|E5_TSTORM_RDMA_CONN_AG_CTX_FLUSH_Q0_CF_EN_MASK
value|0x1
comment|/* cf4en */
define|#
directive|define
name|E5_TSTORM_RDMA_CONN_AG_CTX_FLUSH_Q0_CF_EN_SHIFT
value|0
define|#
directive|define
name|E5_TSTORM_RDMA_CONN_AG_CTX_MSTORM_FLUSH_CF_EN_MASK
value|0x1
comment|/* cf5en */
define|#
directive|define
name|E5_TSTORM_RDMA_CONN_AG_CTX_MSTORM_FLUSH_CF_EN_SHIFT
value|1
define|#
directive|define
name|E5_TSTORM_RDMA_CONN_AG_CTX_CF6EN_MASK
value|0x1
comment|/* cf6en */
define|#
directive|define
name|E5_TSTORM_RDMA_CONN_AG_CTX_CF6EN_SHIFT
value|2
define|#
directive|define
name|E5_TSTORM_RDMA_CONN_AG_CTX_CF7EN_MASK
value|0x1
comment|/* cf7en */
define|#
directive|define
name|E5_TSTORM_RDMA_CONN_AG_CTX_CF7EN_SHIFT
value|3
define|#
directive|define
name|E5_TSTORM_RDMA_CONN_AG_CTX_CF8EN_MASK
value|0x1
comment|/* cf8en */
define|#
directive|define
name|E5_TSTORM_RDMA_CONN_AG_CTX_CF8EN_SHIFT
value|4
define|#
directive|define
name|E5_TSTORM_RDMA_CONN_AG_CTX_CF9EN_MASK
value|0x1
comment|/* cf9en */
define|#
directive|define
name|E5_TSTORM_RDMA_CONN_AG_CTX_CF9EN_SHIFT
value|5
define|#
directive|define
name|E5_TSTORM_RDMA_CONN_AG_CTX_CF10EN_MASK
value|0x1
comment|/* cf10en */
define|#
directive|define
name|E5_TSTORM_RDMA_CONN_AG_CTX_CF10EN_SHIFT
value|6
define|#
directive|define
name|E5_TSTORM_RDMA_CONN_AG_CTX_RULE0EN_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E5_TSTORM_RDMA_CONN_AG_CTX_RULE0EN_SHIFT
value|7
name|u8
name|flags5
decl_stmt|;
define|#
directive|define
name|E5_TSTORM_RDMA_CONN_AG_CTX_RULE1EN_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E5_TSTORM_RDMA_CONN_AG_CTX_RULE1EN_SHIFT
value|0
define|#
directive|define
name|E5_TSTORM_RDMA_CONN_AG_CTX_RULE2EN_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E5_TSTORM_RDMA_CONN_AG_CTX_RULE2EN_SHIFT
value|1
define|#
directive|define
name|E5_TSTORM_RDMA_CONN_AG_CTX_RULE3EN_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E5_TSTORM_RDMA_CONN_AG_CTX_RULE3EN_SHIFT
value|2
define|#
directive|define
name|E5_TSTORM_RDMA_CONN_AG_CTX_RULE4EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E5_TSTORM_RDMA_CONN_AG_CTX_RULE4EN_SHIFT
value|3
define|#
directive|define
name|E5_TSTORM_RDMA_CONN_AG_CTX_RULE5EN_MASK
value|0x1
comment|/* rule5en */
define|#
directive|define
name|E5_TSTORM_RDMA_CONN_AG_CTX_RULE5EN_SHIFT
value|4
define|#
directive|define
name|E5_TSTORM_RDMA_CONN_AG_CTX_RULE6EN_MASK
value|0x1
comment|/* rule6en */
define|#
directive|define
name|E5_TSTORM_RDMA_CONN_AG_CTX_RULE6EN_SHIFT
value|5
define|#
directive|define
name|E5_TSTORM_RDMA_CONN_AG_CTX_RULE7EN_MASK
value|0x1
comment|/* rule7en */
define|#
directive|define
name|E5_TSTORM_RDMA_CONN_AG_CTX_RULE7EN_SHIFT
value|6
define|#
directive|define
name|E5_TSTORM_RDMA_CONN_AG_CTX_RULE8EN_MASK
value|0x1
comment|/* rule8en */
define|#
directive|define
name|E5_TSTORM_RDMA_CONN_AG_CTX_RULE8EN_SHIFT
value|7
name|u8
name|flags6
decl_stmt|;
define|#
directive|define
name|E5_TSTORM_RDMA_CONN_AG_CTX_E4_RESERVED1_MASK
value|0x1
comment|/* bit6 */
define|#
directive|define
name|E5_TSTORM_RDMA_CONN_AG_CTX_E4_RESERVED1_SHIFT
value|0
define|#
directive|define
name|E5_TSTORM_RDMA_CONN_AG_CTX_E4_RESERVED2_MASK
value|0x1
comment|/* bit7 */
define|#
directive|define
name|E5_TSTORM_RDMA_CONN_AG_CTX_E4_RESERVED2_SHIFT
value|1
define|#
directive|define
name|E5_TSTORM_RDMA_CONN_AG_CTX_E4_RESERVED3_MASK
value|0x1
comment|/* bit8 */
define|#
directive|define
name|E5_TSTORM_RDMA_CONN_AG_CTX_E4_RESERVED3_SHIFT
value|2
define|#
directive|define
name|E5_TSTORM_RDMA_CONN_AG_CTX_E4_RESERVED4_MASK
value|0x3
comment|/* cf11 */
define|#
directive|define
name|E5_TSTORM_RDMA_CONN_AG_CTX_E4_RESERVED4_SHIFT
value|3
define|#
directive|define
name|E5_TSTORM_RDMA_CONN_AG_CTX_E4_RESERVED5_MASK
value|0x1
comment|/* cf11en */
define|#
directive|define
name|E5_TSTORM_RDMA_CONN_AG_CTX_E4_RESERVED5_SHIFT
value|5
define|#
directive|define
name|E5_TSTORM_RDMA_CONN_AG_CTX_E4_RESERVED6_MASK
value|0x1
comment|/* rule9en */
define|#
directive|define
name|E5_TSTORM_RDMA_CONN_AG_CTX_E4_RESERVED6_SHIFT
value|6
define|#
directive|define
name|E5_TSTORM_RDMA_CONN_AG_CTX_E4_RESERVED7_MASK
value|0x1
comment|/* rule10en */
define|#
directive|define
name|E5_TSTORM_RDMA_CONN_AG_CTX_E4_RESERVED7_SHIFT
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
comment|/* reg5 */
decl_stmt|;
name|__le32
name|reg6
comment|/* reg6 */
decl_stmt|;
name|__le32
name|reg7
comment|/* reg7 */
decl_stmt|;
name|__le32
name|reg8
comment|/* reg8 */
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
name|e4_reserved8
comment|/* byte6 */
decl_stmt|;
name|__le16
name|word1
comment|/* word1 */
decl_stmt|;
name|__le16
name|word2
comment|/* conn_dpi */
decl_stmt|;
name|__le32
name|reg9
comment|/* reg9 */
decl_stmt|;
name|__le16
name|word3
comment|/* word3 */
decl_stmt|;
name|__le16
name|e4_reserved9
comment|/* word4 */
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|e5_tstorm_rdma_task_ag_ctx
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
name|E5_TSTORM_RDMA_TASK_AG_CTX_NIBBLE0_MASK
value|0xF
comment|/* connection_type */
define|#
directive|define
name|E5_TSTORM_RDMA_TASK_AG_CTX_NIBBLE0_SHIFT
value|0
define|#
directive|define
name|E5_TSTORM_RDMA_TASK_AG_CTX_BIT0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E5_TSTORM_RDMA_TASK_AG_CTX_BIT0_SHIFT
value|4
define|#
directive|define
name|E5_TSTORM_RDMA_TASK_AG_CTX_BIT1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E5_TSTORM_RDMA_TASK_AG_CTX_BIT1_SHIFT
value|5
define|#
directive|define
name|E5_TSTORM_RDMA_TASK_AG_CTX_BIT2_MASK
value|0x1
comment|/* bit2 */
define|#
directive|define
name|E5_TSTORM_RDMA_TASK_AG_CTX_BIT2_SHIFT
value|6
define|#
directive|define
name|E5_TSTORM_RDMA_TASK_AG_CTX_BIT3_MASK
value|0x1
comment|/* bit3 */
define|#
directive|define
name|E5_TSTORM_RDMA_TASK_AG_CTX_BIT3_SHIFT
value|7
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E5_TSTORM_RDMA_TASK_AG_CTX_BIT4_MASK
value|0x1
comment|/* bit4 */
define|#
directive|define
name|E5_TSTORM_RDMA_TASK_AG_CTX_BIT4_SHIFT
value|0
define|#
directive|define
name|E5_TSTORM_RDMA_TASK_AG_CTX_BIT5_MASK
value|0x1
comment|/* bit5 */
define|#
directive|define
name|E5_TSTORM_RDMA_TASK_AG_CTX_BIT5_SHIFT
value|1
define|#
directive|define
name|E5_TSTORM_RDMA_TASK_AG_CTX_CF0_MASK
value|0x3
comment|/* timer0cf */
define|#
directive|define
name|E5_TSTORM_RDMA_TASK_AG_CTX_CF0_SHIFT
value|2
define|#
directive|define
name|E5_TSTORM_RDMA_TASK_AG_CTX_CF1_MASK
value|0x3
comment|/* timer1cf */
define|#
directive|define
name|E5_TSTORM_RDMA_TASK_AG_CTX_CF1_SHIFT
value|4
define|#
directive|define
name|E5_TSTORM_RDMA_TASK_AG_CTX_CF2_MASK
value|0x3
comment|/* timer2cf */
define|#
directive|define
name|E5_TSTORM_RDMA_TASK_AG_CTX_CF2_SHIFT
value|6
name|u8
name|flags2
decl_stmt|;
define|#
directive|define
name|E5_TSTORM_RDMA_TASK_AG_CTX_CF3_MASK
value|0x3
comment|/* timer_stop_all */
define|#
directive|define
name|E5_TSTORM_RDMA_TASK_AG_CTX_CF3_SHIFT
value|0
define|#
directive|define
name|E5_TSTORM_RDMA_TASK_AG_CTX_CF4_MASK
value|0x3
comment|/* cf4 */
define|#
directive|define
name|E5_TSTORM_RDMA_TASK_AG_CTX_CF4_SHIFT
value|2
define|#
directive|define
name|E5_TSTORM_RDMA_TASK_AG_CTX_CF5_MASK
value|0x3
comment|/* cf5 */
define|#
directive|define
name|E5_TSTORM_RDMA_TASK_AG_CTX_CF5_SHIFT
value|4
define|#
directive|define
name|E5_TSTORM_RDMA_TASK_AG_CTX_CF6_MASK
value|0x3
comment|/* cf6 */
define|#
directive|define
name|E5_TSTORM_RDMA_TASK_AG_CTX_CF6_SHIFT
value|6
name|u8
name|flags3
decl_stmt|;
define|#
directive|define
name|E5_TSTORM_RDMA_TASK_AG_CTX_CF7_MASK
value|0x3
comment|/* cf7 */
define|#
directive|define
name|E5_TSTORM_RDMA_TASK_AG_CTX_CF7_SHIFT
value|0
define|#
directive|define
name|E5_TSTORM_RDMA_TASK_AG_CTX_CF0EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E5_TSTORM_RDMA_TASK_AG_CTX_CF0EN_SHIFT
value|2
define|#
directive|define
name|E5_TSTORM_RDMA_TASK_AG_CTX_CF1EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E5_TSTORM_RDMA_TASK_AG_CTX_CF1EN_SHIFT
value|3
define|#
directive|define
name|E5_TSTORM_RDMA_TASK_AG_CTX_CF2EN_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E5_TSTORM_RDMA_TASK_AG_CTX_CF2EN_SHIFT
value|4
define|#
directive|define
name|E5_TSTORM_RDMA_TASK_AG_CTX_CF3EN_MASK
value|0x1
comment|/* cf3en */
define|#
directive|define
name|E5_TSTORM_RDMA_TASK_AG_CTX_CF3EN_SHIFT
value|5
define|#
directive|define
name|E5_TSTORM_RDMA_TASK_AG_CTX_CF4EN_MASK
value|0x1
comment|/* cf4en */
define|#
directive|define
name|E5_TSTORM_RDMA_TASK_AG_CTX_CF4EN_SHIFT
value|6
define|#
directive|define
name|E5_TSTORM_RDMA_TASK_AG_CTX_CF5EN_MASK
value|0x1
comment|/* cf5en */
define|#
directive|define
name|E5_TSTORM_RDMA_TASK_AG_CTX_CF5EN_SHIFT
value|7
name|u8
name|flags4
decl_stmt|;
define|#
directive|define
name|E5_TSTORM_RDMA_TASK_AG_CTX_CF6EN_MASK
value|0x1
comment|/* cf6en */
define|#
directive|define
name|E5_TSTORM_RDMA_TASK_AG_CTX_CF6EN_SHIFT
value|0
define|#
directive|define
name|E5_TSTORM_RDMA_TASK_AG_CTX_CF7EN_MASK
value|0x1
comment|/* cf7en */
define|#
directive|define
name|E5_TSTORM_RDMA_TASK_AG_CTX_CF7EN_SHIFT
value|1
define|#
directive|define
name|E5_TSTORM_RDMA_TASK_AG_CTX_RULE0EN_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E5_TSTORM_RDMA_TASK_AG_CTX_RULE0EN_SHIFT
value|2
define|#
directive|define
name|E5_TSTORM_RDMA_TASK_AG_CTX_RULE1EN_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E5_TSTORM_RDMA_TASK_AG_CTX_RULE1EN_SHIFT
value|3
define|#
directive|define
name|E5_TSTORM_RDMA_TASK_AG_CTX_RULE2EN_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E5_TSTORM_RDMA_TASK_AG_CTX_RULE2EN_SHIFT
value|4
define|#
directive|define
name|E5_TSTORM_RDMA_TASK_AG_CTX_RULE3EN_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E5_TSTORM_RDMA_TASK_AG_CTX_RULE3EN_SHIFT
value|5
define|#
directive|define
name|E5_TSTORM_RDMA_TASK_AG_CTX_RULE4EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E5_TSTORM_RDMA_TASK_AG_CTX_RULE4EN_SHIFT
value|6
define|#
directive|define
name|E5_TSTORM_RDMA_TASK_AG_CTX_RULE5EN_MASK
value|0x1
comment|/* rule5en */
define|#
directive|define
name|E5_TSTORM_RDMA_TASK_AG_CTX_RULE5EN_SHIFT
value|7
name|u8
name|byte2
comment|/* byte2 */
decl_stmt|;
name|__le16
name|word1
comment|/* word1 */
decl_stmt|;
name|__le32
name|reg0
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
name|reg1
comment|/* regpair1 */
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
name|e5_ustorm_rdma_conn_ag_ctx
block|{
name|u8
name|reserved
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
name|E5_USTORM_RDMA_CONN_AG_CTX_EXIST_IN_QM0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E5_USTORM_RDMA_CONN_AG_CTX_EXIST_IN_QM0_SHIFT
value|0
define|#
directive|define
name|E5_USTORM_RDMA_CONN_AG_CTX_BIT1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E5_USTORM_RDMA_CONN_AG_CTX_BIT1_SHIFT
value|1
define|#
directive|define
name|E5_USTORM_RDMA_CONN_AG_CTX_FLUSH_Q0_CF_MASK
value|0x3
comment|/* timer0cf */
define|#
directive|define
name|E5_USTORM_RDMA_CONN_AG_CTX_FLUSH_Q0_CF_SHIFT
value|2
define|#
directive|define
name|E5_USTORM_RDMA_CONN_AG_CTX_CF1_MASK
value|0x3
comment|/* timer1cf */
define|#
directive|define
name|E5_USTORM_RDMA_CONN_AG_CTX_CF1_SHIFT
value|4
define|#
directive|define
name|E5_USTORM_RDMA_CONN_AG_CTX_CF2_MASK
value|0x3
comment|/* timer2cf */
define|#
directive|define
name|E5_USTORM_RDMA_CONN_AG_CTX_CF2_SHIFT
value|6
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E5_USTORM_RDMA_CONN_AG_CTX_CF3_MASK
value|0x3
comment|/* timer_stop_all */
define|#
directive|define
name|E5_USTORM_RDMA_CONN_AG_CTX_CF3_SHIFT
value|0
define|#
directive|define
name|E5_USTORM_RDMA_CONN_AG_CTX_CQ_ARM_SE_CF_MASK
value|0x3
comment|/* cf4 */
define|#
directive|define
name|E5_USTORM_RDMA_CONN_AG_CTX_CQ_ARM_SE_CF_SHIFT
value|2
define|#
directive|define
name|E5_USTORM_RDMA_CONN_AG_CTX_CQ_ARM_CF_MASK
value|0x3
comment|/* cf5 */
define|#
directive|define
name|E5_USTORM_RDMA_CONN_AG_CTX_CQ_ARM_CF_SHIFT
value|4
define|#
directive|define
name|E5_USTORM_RDMA_CONN_AG_CTX_CF6_MASK
value|0x3
comment|/* cf6 */
define|#
directive|define
name|E5_USTORM_RDMA_CONN_AG_CTX_CF6_SHIFT
value|6
name|u8
name|flags2
decl_stmt|;
define|#
directive|define
name|E5_USTORM_RDMA_CONN_AG_CTX_FLUSH_Q0_CF_EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E5_USTORM_RDMA_CONN_AG_CTX_FLUSH_Q0_CF_EN_SHIFT
value|0
define|#
directive|define
name|E5_USTORM_RDMA_CONN_AG_CTX_CF1EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E5_USTORM_RDMA_CONN_AG_CTX_CF1EN_SHIFT
value|1
define|#
directive|define
name|E5_USTORM_RDMA_CONN_AG_CTX_CF2EN_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E5_USTORM_RDMA_CONN_AG_CTX_CF2EN_SHIFT
value|2
define|#
directive|define
name|E5_USTORM_RDMA_CONN_AG_CTX_CF3EN_MASK
value|0x1
comment|/* cf3en */
define|#
directive|define
name|E5_USTORM_RDMA_CONN_AG_CTX_CF3EN_SHIFT
value|3
define|#
directive|define
name|E5_USTORM_RDMA_CONN_AG_CTX_CQ_ARM_SE_CF_EN_MASK
value|0x1
comment|/* cf4en */
define|#
directive|define
name|E5_USTORM_RDMA_CONN_AG_CTX_CQ_ARM_SE_CF_EN_SHIFT
value|4
define|#
directive|define
name|E5_USTORM_RDMA_CONN_AG_CTX_CQ_ARM_CF_EN_MASK
value|0x1
comment|/* cf5en */
define|#
directive|define
name|E5_USTORM_RDMA_CONN_AG_CTX_CQ_ARM_CF_EN_SHIFT
value|5
define|#
directive|define
name|E5_USTORM_RDMA_CONN_AG_CTX_CF6EN_MASK
value|0x1
comment|/* cf6en */
define|#
directive|define
name|E5_USTORM_RDMA_CONN_AG_CTX_CF6EN_SHIFT
value|6
define|#
directive|define
name|E5_USTORM_RDMA_CONN_AG_CTX_CQ_SE_EN_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E5_USTORM_RDMA_CONN_AG_CTX_CQ_SE_EN_SHIFT
value|7
name|u8
name|flags3
decl_stmt|;
define|#
directive|define
name|E5_USTORM_RDMA_CONN_AG_CTX_CQ_EN_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E5_USTORM_RDMA_CONN_AG_CTX_CQ_EN_SHIFT
value|0
define|#
directive|define
name|E5_USTORM_RDMA_CONN_AG_CTX_RULE2EN_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E5_USTORM_RDMA_CONN_AG_CTX_RULE2EN_SHIFT
value|1
define|#
directive|define
name|E5_USTORM_RDMA_CONN_AG_CTX_RULE3EN_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E5_USTORM_RDMA_CONN_AG_CTX_RULE3EN_SHIFT
value|2
define|#
directive|define
name|E5_USTORM_RDMA_CONN_AG_CTX_RULE4EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E5_USTORM_RDMA_CONN_AG_CTX_RULE4EN_SHIFT
value|3
define|#
directive|define
name|E5_USTORM_RDMA_CONN_AG_CTX_RULE5EN_MASK
value|0x1
comment|/* rule5en */
define|#
directive|define
name|E5_USTORM_RDMA_CONN_AG_CTX_RULE5EN_SHIFT
value|4
define|#
directive|define
name|E5_USTORM_RDMA_CONN_AG_CTX_RULE6EN_MASK
value|0x1
comment|/* rule6en */
define|#
directive|define
name|E5_USTORM_RDMA_CONN_AG_CTX_RULE6EN_SHIFT
value|5
define|#
directive|define
name|E5_USTORM_RDMA_CONN_AG_CTX_RULE7EN_MASK
value|0x1
comment|/* rule7en */
define|#
directive|define
name|E5_USTORM_RDMA_CONN_AG_CTX_RULE7EN_SHIFT
value|6
define|#
directive|define
name|E5_USTORM_RDMA_CONN_AG_CTX_RULE8EN_MASK
value|0x1
comment|/* rule8en */
define|#
directive|define
name|E5_USTORM_RDMA_CONN_AG_CTX_RULE8EN_SHIFT
value|7
name|u8
name|flags4
decl_stmt|;
define|#
directive|define
name|E5_USTORM_RDMA_CONN_AG_CTX_E4_RESERVED1_MASK
value|0x1
comment|/* bit2 */
define|#
directive|define
name|E5_USTORM_RDMA_CONN_AG_CTX_E4_RESERVED1_SHIFT
value|0
define|#
directive|define
name|E5_USTORM_RDMA_CONN_AG_CTX_E4_RESERVED2_MASK
value|0x1
comment|/* bit3 */
define|#
directive|define
name|E5_USTORM_RDMA_CONN_AG_CTX_E4_RESERVED2_SHIFT
value|1
define|#
directive|define
name|E5_USTORM_RDMA_CONN_AG_CTX_E4_RESERVED3_MASK
value|0x3
comment|/* cf7 */
define|#
directive|define
name|E5_USTORM_RDMA_CONN_AG_CTX_E4_RESERVED3_SHIFT
value|2
define|#
directive|define
name|E5_USTORM_RDMA_CONN_AG_CTX_E4_RESERVED4_MASK
value|0x3
comment|/* cf8 */
define|#
directive|define
name|E5_USTORM_RDMA_CONN_AG_CTX_E4_RESERVED4_SHIFT
value|4
define|#
directive|define
name|E5_USTORM_RDMA_CONN_AG_CTX_E4_RESERVED5_MASK
value|0x1
comment|/* cf7en */
define|#
directive|define
name|E5_USTORM_RDMA_CONN_AG_CTX_E4_RESERVED5_SHIFT
value|6
define|#
directive|define
name|E5_USTORM_RDMA_CONN_AG_CTX_E4_RESERVED6_MASK
value|0x1
comment|/* cf8en */
define|#
directive|define
name|E5_USTORM_RDMA_CONN_AG_CTX_E4_RESERVED6_SHIFT
value|7
name|u8
name|byte2
comment|/* byte2 */
decl_stmt|;
name|__le16
name|conn_dpi
comment|/* conn_dpi */
decl_stmt|;
name|__le16
name|word1
comment|/* word1 */
decl_stmt|;
name|__le32
name|cq_cons
comment|/* reg0 */
decl_stmt|;
name|__le32
name|cq_se_prod
comment|/* reg1 */
decl_stmt|;
name|__le32
name|cq_prod
comment|/* reg2 */
decl_stmt|;
name|__le32
name|reg3
comment|/* reg3 */
decl_stmt|;
name|__le16
name|int_timeout
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
name|e5_xstorm_rdma_conn_ag_ctx
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
name|E5_XSTORM_RDMA_CONN_AG_CTX_EXIST_IN_QM0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_EXIST_IN_QM0_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_BIT1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_BIT1_SHIFT
value|1
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_BIT2_MASK
value|0x1
comment|/* exist_in_qm2 */
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_BIT2_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_EXIST_IN_QM3_MASK
value|0x1
comment|/* exist_in_qm3 */
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_EXIST_IN_QM3_SHIFT
value|3
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_BIT4_MASK
value|0x1
comment|/* bit4 */
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_BIT4_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_BIT5_MASK
value|0x1
comment|/* cf_array_active */
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_BIT5_SHIFT
value|5
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_BIT6_MASK
value|0x1
comment|/* bit6 */
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_BIT6_SHIFT
value|6
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_BIT7_MASK
value|0x1
comment|/* bit7 */
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_BIT7_SHIFT
value|7
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_BIT8_MASK
value|0x1
comment|/* bit8 */
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_BIT8_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_BIT9_MASK
value|0x1
comment|/* bit9 */
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_BIT9_SHIFT
value|1
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_BIT10_MASK
value|0x1
comment|/* bit10 */
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_BIT10_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_BIT11_MASK
value|0x1
comment|/* bit11 */
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_BIT11_SHIFT
value|3
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_BIT12_MASK
value|0x1
comment|/* bit12 */
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_BIT12_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_BIT13_MASK
value|0x1
comment|/* bit13 */
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_BIT13_SHIFT
value|5
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_BIT14_MASK
value|0x1
comment|/* bit14 */
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_BIT14_SHIFT
value|6
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_YSTORM_FLUSH_MASK
value|0x1
comment|/* bit15 */
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_YSTORM_FLUSH_SHIFT
value|7
name|u8
name|flags2
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_CF0_MASK
value|0x3
comment|/* timer0cf */
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_CF0_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_CF1_MASK
value|0x3
comment|/* timer1cf */
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_CF1_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_CF2_MASK
value|0x3
comment|/* timer2cf */
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_CF2_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_CF3_MASK
value|0x3
comment|/* timer_stop_all */
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_CF3_SHIFT
value|6
name|u8
name|flags3
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_CF4_MASK
value|0x3
comment|/* cf4 */
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_CF4_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_CF5_MASK
value|0x3
comment|/* cf5 */
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_CF5_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_CF6_MASK
value|0x3
comment|/* cf6 */
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_CF6_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_FLUSH_Q0_CF_MASK
value|0x3
comment|/* cf7 */
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_FLUSH_Q0_CF_SHIFT
value|6
name|u8
name|flags4
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_CF8_MASK
value|0x3
comment|/* cf8 */
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_CF8_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_CF9_MASK
value|0x3
comment|/* cf9 */
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_CF9_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_CF10_MASK
value|0x3
comment|/* cf10 */
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_CF10_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_CF11_MASK
value|0x3
comment|/* cf11 */
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_CF11_SHIFT
value|6
name|u8
name|flags5
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_CF12_MASK
value|0x3
comment|/* cf12 */
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_CF12_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_CF13_MASK
value|0x3
comment|/* cf13 */
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_CF13_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_CF14_MASK
value|0x3
comment|/* cf14 */
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_CF14_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_CF15_MASK
value|0x3
comment|/* cf15 */
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_CF15_SHIFT
value|6
name|u8
name|flags6
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_CF16_MASK
value|0x3
comment|/* cf16 */
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_CF16_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_CF17_MASK
value|0x3
comment|/* cf_array_cf */
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_CF17_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_CF18_MASK
value|0x3
comment|/* cf18 */
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_CF18_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_CF19_MASK
value|0x3
comment|/* cf19 */
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_CF19_SHIFT
value|6
name|u8
name|flags7
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_CF20_MASK
value|0x3
comment|/* cf20 */
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_CF20_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_CF21_MASK
value|0x3
comment|/* cf21 */
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_CF21_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_SLOW_PATH_MASK
value|0x3
comment|/* cf22 */
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_SLOW_PATH_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_CF0EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_CF0EN_SHIFT
value|6
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_CF1EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_CF1EN_SHIFT
value|7
name|u8
name|flags8
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_CF2EN_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_CF2EN_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_CF3EN_MASK
value|0x1
comment|/* cf3en */
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_CF3EN_SHIFT
value|1
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_CF4EN_MASK
value|0x1
comment|/* cf4en */
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_CF4EN_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_CF5EN_MASK
value|0x1
comment|/* cf5en */
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_CF5EN_SHIFT
value|3
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_CF6EN_MASK
value|0x1
comment|/* cf6en */
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_CF6EN_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_FLUSH_Q0_CF_EN_MASK
value|0x1
comment|/* cf7en */
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_FLUSH_Q0_CF_EN_SHIFT
value|5
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_CF8EN_MASK
value|0x1
comment|/* cf8en */
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_CF8EN_SHIFT
value|6
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_CF9EN_MASK
value|0x1
comment|/* cf9en */
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_CF9EN_SHIFT
value|7
name|u8
name|flags9
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_CF10EN_MASK
value|0x1
comment|/* cf10en */
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_CF10EN_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_CF11EN_MASK
value|0x1
comment|/* cf11en */
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_CF11EN_SHIFT
value|1
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_CF12EN_MASK
value|0x1
comment|/* cf12en */
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_CF12EN_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_CF13EN_MASK
value|0x1
comment|/* cf13en */
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_CF13EN_SHIFT
value|3
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_CF14EN_MASK
value|0x1
comment|/* cf14en */
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_CF14EN_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_CF15EN_MASK
value|0x1
comment|/* cf15en */
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_CF15EN_SHIFT
value|5
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_CF16EN_MASK
value|0x1
comment|/* cf16en */
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_CF16EN_SHIFT
value|6
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_CF17EN_MASK
value|0x1
comment|/* cf_array_cf_en */
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_CF17EN_SHIFT
value|7
name|u8
name|flags10
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_CF18EN_MASK
value|0x1
comment|/* cf18en */
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_CF18EN_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_CF19EN_MASK
value|0x1
comment|/* cf19en */
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_CF19EN_SHIFT
value|1
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_CF20EN_MASK
value|0x1
comment|/* cf20en */
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_CF20EN_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_CF21EN_MASK
value|0x1
comment|/* cf21en */
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_CF21EN_SHIFT
value|3
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_SLOW_PATH_EN_MASK
value|0x1
comment|/* cf22en */
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_SLOW_PATH_EN_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_CF23EN_MASK
value|0x1
comment|/* cf23en */
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_CF23EN_SHIFT
value|5
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_RULE0EN_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_RULE0EN_SHIFT
value|6
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_RULE1EN_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_RULE1EN_SHIFT
value|7
name|u8
name|flags11
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_RULE2EN_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_RULE2EN_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_RULE3EN_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_RULE3EN_SHIFT
value|1
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_RULE4EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_RULE4EN_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_RULE5EN_MASK
value|0x1
comment|/* rule5en */
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_RULE5EN_SHIFT
value|3
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_RULE6EN_MASK
value|0x1
comment|/* rule6en */
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_RULE6EN_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_RULE7EN_MASK
value|0x1
comment|/* rule7en */
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_RULE7EN_SHIFT
value|5
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_A0_RESERVED1_MASK
value|0x1
comment|/* rule8en */
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_A0_RESERVED1_SHIFT
value|6
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_RULE9EN_MASK
value|0x1
comment|/* rule9en */
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_RULE9EN_SHIFT
value|7
name|u8
name|flags12
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_RULE10EN_MASK
value|0x1
comment|/* rule10en */
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_RULE10EN_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_RULE11EN_MASK
value|0x1
comment|/* rule11en */
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_RULE11EN_SHIFT
value|1
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_A0_RESERVED2_MASK
value|0x1
comment|/* rule12en */
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_A0_RESERVED2_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_A0_RESERVED3_MASK
value|0x1
comment|/* rule13en */
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_A0_RESERVED3_SHIFT
value|3
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_RULE14EN_MASK
value|0x1
comment|/* rule14en */
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_RULE14EN_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_RULE15EN_MASK
value|0x1
comment|/* rule15en */
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_RULE15EN_SHIFT
value|5
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_RULE16EN_MASK
value|0x1
comment|/* rule16en */
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_RULE16EN_SHIFT
value|6
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_RULE17EN_MASK
value|0x1
comment|/* rule17en */
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_RULE17EN_SHIFT
value|7
name|u8
name|flags13
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_RULE18EN_MASK
value|0x1
comment|/* rule18en */
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_RULE18EN_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_RULE19EN_MASK
value|0x1
comment|/* rule19en */
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_RULE19EN_SHIFT
value|1
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_A0_RESERVED4_MASK
value|0x1
comment|/* rule20en */
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_A0_RESERVED4_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_A0_RESERVED5_MASK
value|0x1
comment|/* rule21en */
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_A0_RESERVED5_SHIFT
value|3
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_A0_RESERVED6_MASK
value|0x1
comment|/* rule22en */
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_A0_RESERVED6_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_A0_RESERVED7_MASK
value|0x1
comment|/* rule23en */
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_A0_RESERVED7_SHIFT
value|5
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_A0_RESERVED8_MASK
value|0x1
comment|/* rule24en */
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_A0_RESERVED8_SHIFT
value|6
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_A0_RESERVED9_MASK
value|0x1
comment|/* rule25en */
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_A0_RESERVED9_SHIFT
value|7
name|u8
name|flags14
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_MIGRATION_MASK
value|0x1
comment|/* bit16 */
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_MIGRATION_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_BIT17_MASK
value|0x1
comment|/* bit17 */
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_BIT17_SHIFT
value|1
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_DPM_PORT_NUM_MASK
value|0x3
comment|/* bit18 */
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_DPM_PORT_NUM_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_RESERVED_MASK
value|0x1
comment|/* bit20 */
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_RESERVED_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_ROCE_EDPM_ENABLE_MASK
value|0x1
comment|/* bit21 */
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_ROCE_EDPM_ENABLE_SHIFT
value|5
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_CF23_MASK
value|0x3
comment|/* cf23 */
define|#
directive|define
name|E5_XSTORM_RDMA_CONN_AG_CTX_CF23_SHIFT
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
name|conn_dpi
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
name|snd_nxt_psn
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
block|}
struct|;
end_struct

begin_struct
struct|struct
name|e5_ystorm_rdma_conn_ag_ctx
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
name|E5_YSTORM_RDMA_CONN_AG_CTX_BIT0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E5_YSTORM_RDMA_CONN_AG_CTX_BIT0_SHIFT
value|0
define|#
directive|define
name|E5_YSTORM_RDMA_CONN_AG_CTX_BIT1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E5_YSTORM_RDMA_CONN_AG_CTX_BIT1_SHIFT
value|1
define|#
directive|define
name|E5_YSTORM_RDMA_CONN_AG_CTX_CF0_MASK
value|0x3
comment|/* cf0 */
define|#
directive|define
name|E5_YSTORM_RDMA_CONN_AG_CTX_CF0_SHIFT
value|2
define|#
directive|define
name|E5_YSTORM_RDMA_CONN_AG_CTX_CF1_MASK
value|0x3
comment|/* cf1 */
define|#
directive|define
name|E5_YSTORM_RDMA_CONN_AG_CTX_CF1_SHIFT
value|4
define|#
directive|define
name|E5_YSTORM_RDMA_CONN_AG_CTX_CF2_MASK
value|0x3
comment|/* cf2 */
define|#
directive|define
name|E5_YSTORM_RDMA_CONN_AG_CTX_CF2_SHIFT
value|6
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E5_YSTORM_RDMA_CONN_AG_CTX_CF0EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E5_YSTORM_RDMA_CONN_AG_CTX_CF0EN_SHIFT
value|0
define|#
directive|define
name|E5_YSTORM_RDMA_CONN_AG_CTX_CF1EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E5_YSTORM_RDMA_CONN_AG_CTX_CF1EN_SHIFT
value|1
define|#
directive|define
name|E5_YSTORM_RDMA_CONN_AG_CTX_CF2EN_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E5_YSTORM_RDMA_CONN_AG_CTX_CF2EN_SHIFT
value|2
define|#
directive|define
name|E5_YSTORM_RDMA_CONN_AG_CTX_RULE0EN_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E5_YSTORM_RDMA_CONN_AG_CTX_RULE0EN_SHIFT
value|3
define|#
directive|define
name|E5_YSTORM_RDMA_CONN_AG_CTX_RULE1EN_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E5_YSTORM_RDMA_CONN_AG_CTX_RULE1EN_SHIFT
value|4
define|#
directive|define
name|E5_YSTORM_RDMA_CONN_AG_CTX_RULE2EN_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E5_YSTORM_RDMA_CONN_AG_CTX_RULE2EN_SHIFT
value|5
define|#
directive|define
name|E5_YSTORM_RDMA_CONN_AG_CTX_RULE3EN_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E5_YSTORM_RDMA_CONN_AG_CTX_RULE3EN_SHIFT
value|6
define|#
directive|define
name|E5_YSTORM_RDMA_CONN_AG_CTX_RULE4EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E5_YSTORM_RDMA_CONN_AG_CTX_RULE4EN_SHIFT
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
comment|/* __ECORE_HSI_RDMA__ */
end_comment

end_unit

