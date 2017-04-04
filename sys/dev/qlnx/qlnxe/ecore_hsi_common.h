begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2017-2018 Cavium, Inc.   * All rights reserved.  *  *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *  *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *  *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  *  POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ECORE_HSI_COMMON__
end_ifndef

begin_define
define|#
directive|define
name|__ECORE_HSI_COMMON__
end_define

begin_comment
comment|/********************************/
end_comment

begin_comment
comment|/* Add include to common target */
end_comment

begin_comment
comment|/********************************/
end_comment

begin_include
include|#
directive|include
file|"common_hsi.h"
end_include

begin_comment
comment|/*  * opcodes for the event ring  */
end_comment

begin_enum
enum|enum
name|common_event_opcode
block|{
name|COMMON_EVENT_PF_START
block|,
name|COMMON_EVENT_PF_STOP
block|,
name|COMMON_EVENT_VF_START
block|,
name|COMMON_EVENT_VF_STOP
block|,
name|COMMON_EVENT_VF_PF_CHANNEL
block|,
name|COMMON_EVENT_VF_FLR
block|,
name|COMMON_EVENT_PF_UPDATE
block|,
name|COMMON_EVENT_MALICIOUS_VF
block|,
name|COMMON_EVENT_RL_UPDATE
block|,
name|COMMON_EVENT_EMPTY
block|,
name|MAX_COMMON_EVENT_OPCODE
block|}
enum|;
end_enum

begin_comment
comment|/*  * Common Ramrod Command IDs  */
end_comment

begin_enum
enum|enum
name|common_ramrod_cmd_id
block|{
name|COMMON_RAMROD_UNUSED
block|,
name|COMMON_RAMROD_PF_START
comment|/* PF Function Start Ramrod */
block|,
name|COMMON_RAMROD_PF_STOP
comment|/* PF Function Stop Ramrod */
block|,
name|COMMON_RAMROD_VF_START
comment|/* VF Function Start */
block|,
name|COMMON_RAMROD_VF_STOP
comment|/* VF Function Stop Ramrod */
block|,
name|COMMON_RAMROD_PF_UPDATE
comment|/* PF update Ramrod */
block|,
name|COMMON_RAMROD_RL_UPDATE
comment|/* QCN/DCQCN RL update Ramrod */
block|,
name|COMMON_RAMROD_EMPTY
comment|/* Empty Ramrod */
block|,
name|MAX_COMMON_RAMROD_CMD_ID
block|}
enum|;
end_enum

begin_comment
comment|/*  * The core storm context for the Ystorm  */
end_comment

begin_struct
struct|struct
name|ystorm_core_conn_st_ctx
block|{
name|__le32
name|reserved
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The core storm context for the Pstorm  */
end_comment

begin_struct
struct|struct
name|pstorm_core_conn_st_ctx
block|{
name|__le32
name|reserved
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Core Slowpath Connection storm context of Xstorm  */
end_comment

begin_struct
struct|struct
name|xstorm_core_conn_st_ctx
block|{
name|__le32
name|spq_base_lo
comment|/* SPQ Ring Base Address low dword */
decl_stmt|;
name|__le32
name|spq_base_hi
comment|/* SPQ Ring Base Address high dword */
decl_stmt|;
name|struct
name|regpair
name|consolid_base_addr
comment|/* Consolidation Ring Base Address */
decl_stmt|;
name|__le16
name|spq_cons
comment|/* SPQ Ring Consumer */
decl_stmt|;
name|__le16
name|consolid_cons
comment|/* Consolidation Ring Consumer */
decl_stmt|;
name|__le32
name|reserved0
index|[
literal|55
index|]
comment|/* Pad to 15 cycles */
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|e4_xstorm_core_conn_ag_ctx
block|{
name|u8
name|reserved0
comment|/* cdu_validation */
decl_stmt|;
name|u8
name|core_state
comment|/* state */
decl_stmt|;
name|u8
name|flags0
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_EXIST_IN_QM0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_EXIST_IN_QM0_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_RESERVED1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_RESERVED1_SHIFT
value|1
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_RESERVED2_MASK
value|0x1
comment|/* exist_in_qm2 */
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_RESERVED2_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_EXIST_IN_QM3_MASK
value|0x1
comment|/* exist_in_qm3 */
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_EXIST_IN_QM3_SHIFT
value|3
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_RESERVED3_MASK
value|0x1
comment|/* bit4 */
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_RESERVED3_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_RESERVED4_MASK
value|0x1
comment|/* cf_array_active */
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_RESERVED4_SHIFT
value|5
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_RESERVED5_MASK
value|0x1
comment|/* bit6 */
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_RESERVED5_SHIFT
value|6
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_RESERVED6_MASK
value|0x1
comment|/* bit7 */
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_RESERVED6_SHIFT
value|7
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_RESERVED7_MASK
value|0x1
comment|/* bit8 */
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_RESERVED7_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_RESERVED8_MASK
value|0x1
comment|/* bit9 */
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_RESERVED8_SHIFT
value|1
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_RESERVED9_MASK
value|0x1
comment|/* bit10 */
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_RESERVED9_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_BIT11_MASK
value|0x1
comment|/* bit11 */
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_BIT11_SHIFT
value|3
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_BIT12_MASK
value|0x1
comment|/* bit12 */
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_BIT12_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_BIT13_MASK
value|0x1
comment|/* bit13 */
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_BIT13_SHIFT
value|5
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_TX_RULE_ACTIVE_MASK
value|0x1
comment|/* bit14 */
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_TX_RULE_ACTIVE_SHIFT
value|6
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_DQ_CF_ACTIVE_MASK
value|0x1
comment|/* bit15 */
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_DQ_CF_ACTIVE_SHIFT
value|7
name|u8
name|flags2
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_CF0_MASK
value|0x3
comment|/* timer0cf */
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_CF0_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_CF1_MASK
value|0x3
comment|/* timer1cf */
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_CF1_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_CF2_MASK
value|0x3
comment|/* timer2cf */
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_CF2_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_CF3_MASK
value|0x3
comment|/* timer_stop_all */
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_CF3_SHIFT
value|6
name|u8
name|flags3
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_CF4_MASK
value|0x3
comment|/* cf4 */
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_CF4_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_CF5_MASK
value|0x3
comment|/* cf5 */
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_CF5_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_CF6_MASK
value|0x3
comment|/* cf6 */
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_CF6_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_CF7_MASK
value|0x3
comment|/* cf7 */
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_CF7_SHIFT
value|6
name|u8
name|flags4
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_CF8_MASK
value|0x3
comment|/* cf8 */
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_CF8_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_CF9_MASK
value|0x3
comment|/* cf9 */
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_CF9_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_CF10_MASK
value|0x3
comment|/* cf10 */
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_CF10_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_CF11_MASK
value|0x3
comment|/* cf11 */
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_CF11_SHIFT
value|6
name|u8
name|flags5
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_CF12_MASK
value|0x3
comment|/* cf12 */
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_CF12_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_CF13_MASK
value|0x3
comment|/* cf13 */
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_CF13_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_CF14_MASK
value|0x3
comment|/* cf14 */
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_CF14_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_CF15_MASK
value|0x3
comment|/* cf15 */
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_CF15_SHIFT
value|6
name|u8
name|flags6
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_CONSOLID_PROD_CF_MASK
value|0x3
comment|/* cf16 */
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_CONSOLID_PROD_CF_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_CF17_MASK
value|0x3
comment|/* cf_array_cf */
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_CF17_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_DQ_CF_MASK
value|0x3
comment|/* cf18 */
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_DQ_CF_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_TERMINATE_CF_MASK
value|0x3
comment|/* cf19 */
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_TERMINATE_CF_SHIFT
value|6
name|u8
name|flags7
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_FLUSH_Q0_MASK
value|0x3
comment|/* cf20 */
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_FLUSH_Q0_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_RESERVED10_MASK
value|0x3
comment|/* cf21 */
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_RESERVED10_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_SLOW_PATH_MASK
value|0x3
comment|/* cf22 */
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_SLOW_PATH_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_CF0EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_CF0EN_SHIFT
value|6
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_CF1EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_CF1EN_SHIFT
value|7
name|u8
name|flags8
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_CF2EN_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_CF2EN_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_CF3EN_MASK
value|0x1
comment|/* cf3en */
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_CF3EN_SHIFT
value|1
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_CF4EN_MASK
value|0x1
comment|/* cf4en */
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_CF4EN_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_CF5EN_MASK
value|0x1
comment|/* cf5en */
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_CF5EN_SHIFT
value|3
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_CF6EN_MASK
value|0x1
comment|/* cf6en */
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_CF6EN_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_CF7EN_MASK
value|0x1
comment|/* cf7en */
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_CF7EN_SHIFT
value|5
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_CF8EN_MASK
value|0x1
comment|/* cf8en */
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_CF8EN_SHIFT
value|6
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_CF9EN_MASK
value|0x1
comment|/* cf9en */
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_CF9EN_SHIFT
value|7
name|u8
name|flags9
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_CF10EN_MASK
value|0x1
comment|/* cf10en */
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_CF10EN_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_CF11EN_MASK
value|0x1
comment|/* cf11en */
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_CF11EN_SHIFT
value|1
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_CF12EN_MASK
value|0x1
comment|/* cf12en */
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_CF12EN_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_CF13EN_MASK
value|0x1
comment|/* cf13en */
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_CF13EN_SHIFT
value|3
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_CF14EN_MASK
value|0x1
comment|/* cf14en */
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_CF14EN_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_CF15EN_MASK
value|0x1
comment|/* cf15en */
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_CF15EN_SHIFT
value|5
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_CONSOLID_PROD_CF_EN_MASK
value|0x1
comment|/* cf16en */
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_CONSOLID_PROD_CF_EN_SHIFT
value|6
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_CF17EN_MASK
value|0x1
comment|/* cf_array_cf_en */
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_CF17EN_SHIFT
value|7
name|u8
name|flags10
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_DQ_CF_EN_MASK
value|0x1
comment|/* cf18en */
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_DQ_CF_EN_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_TERMINATE_CF_EN_MASK
value|0x1
comment|/* cf19en */
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_TERMINATE_CF_EN_SHIFT
value|1
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_FLUSH_Q0_EN_MASK
value|0x1
comment|/* cf20en */
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_FLUSH_Q0_EN_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_RESERVED11_MASK
value|0x1
comment|/* cf21en */
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_RESERVED11_SHIFT
value|3
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_SLOW_PATH_EN_MASK
value|0x1
comment|/* cf22en */
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_SLOW_PATH_EN_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_CF23EN_MASK
value|0x1
comment|/* cf23en */
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_CF23EN_SHIFT
value|5
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_RESERVED12_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_RESERVED12_SHIFT
value|6
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_RESERVED13_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_RESERVED13_SHIFT
value|7
name|u8
name|flags11
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_RESERVED14_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_RESERVED14_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_RESERVED15_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_RESERVED15_SHIFT
value|1
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_TX_DEC_RULE_EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_TX_DEC_RULE_EN_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_RULE5EN_MASK
value|0x1
comment|/* rule5en */
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_RULE5EN_SHIFT
value|3
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_RULE6EN_MASK
value|0x1
comment|/* rule6en */
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_RULE6EN_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_RULE7EN_MASK
value|0x1
comment|/* rule7en */
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_RULE7EN_SHIFT
value|5
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_A0_RESERVED1_MASK
value|0x1
comment|/* rule8en */
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_A0_RESERVED1_SHIFT
value|6
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_RULE9EN_MASK
value|0x1
comment|/* rule9en */
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_RULE9EN_SHIFT
value|7
name|u8
name|flags12
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_RULE10EN_MASK
value|0x1
comment|/* rule10en */
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_RULE10EN_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_RULE11EN_MASK
value|0x1
comment|/* rule11en */
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_RULE11EN_SHIFT
value|1
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_A0_RESERVED2_MASK
value|0x1
comment|/* rule12en */
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_A0_RESERVED2_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_A0_RESERVED3_MASK
value|0x1
comment|/* rule13en */
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_A0_RESERVED3_SHIFT
value|3
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_RULE14EN_MASK
value|0x1
comment|/* rule14en */
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_RULE14EN_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_RULE15EN_MASK
value|0x1
comment|/* rule15en */
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_RULE15EN_SHIFT
value|5
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_RULE16EN_MASK
value|0x1
comment|/* rule16en */
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_RULE16EN_SHIFT
value|6
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_RULE17EN_MASK
value|0x1
comment|/* rule17en */
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_RULE17EN_SHIFT
value|7
name|u8
name|flags13
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_RULE18EN_MASK
value|0x1
comment|/* rule18en */
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_RULE18EN_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_RULE19EN_MASK
value|0x1
comment|/* rule19en */
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_RULE19EN_SHIFT
value|1
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_A0_RESERVED4_MASK
value|0x1
comment|/* rule20en */
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_A0_RESERVED4_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_A0_RESERVED5_MASK
value|0x1
comment|/* rule21en */
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_A0_RESERVED5_SHIFT
value|3
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_A0_RESERVED6_MASK
value|0x1
comment|/* rule22en */
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_A0_RESERVED6_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_A0_RESERVED7_MASK
value|0x1
comment|/* rule23en */
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_A0_RESERVED7_SHIFT
value|5
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_A0_RESERVED8_MASK
value|0x1
comment|/* rule24en */
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_A0_RESERVED8_SHIFT
value|6
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_A0_RESERVED9_MASK
value|0x1
comment|/* rule25en */
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_A0_RESERVED9_SHIFT
value|7
name|u8
name|flags14
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_BIT16_MASK
value|0x1
comment|/* bit16 */
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_BIT16_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_BIT17_MASK
value|0x1
comment|/* bit17 */
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_BIT17_SHIFT
value|1
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_BIT18_MASK
value|0x1
comment|/* bit18 */
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_BIT18_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_BIT19_MASK
value|0x1
comment|/* bit19 */
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_BIT19_SHIFT
value|3
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_BIT20_MASK
value|0x1
comment|/* bit20 */
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_BIT20_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_BIT21_MASK
value|0x1
comment|/* bit21 */
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_BIT21_SHIFT
value|5
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_CF23_MASK
value|0x3
comment|/* cf23 */
define|#
directive|define
name|E4_XSTORM_CORE_CONN_AG_CTX_CF23_SHIFT
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
name|consolid_prod
comment|/* physical_q1 */
decl_stmt|;
name|__le16
name|reserved16
comment|/* physical_q2 */
decl_stmt|;
name|__le16
name|tx_bd_cons
comment|/* word3 */
decl_stmt|;
name|__le16
name|tx_bd_or_spq_prod
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
name|word7
comment|/* word7 */
decl_stmt|;
name|__le16
name|word8
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
name|__le32
name|reg9
comment|/* reg9 */
decl_stmt|;
name|u8
name|byte7
comment|/* byte7 */
decl_stmt|;
name|u8
name|byte8
comment|/* byte8 */
decl_stmt|;
name|u8
name|byte9
comment|/* byte9 */
decl_stmt|;
name|u8
name|byte10
comment|/* byte10 */
decl_stmt|;
name|u8
name|byte11
comment|/* byte11 */
decl_stmt|;
name|u8
name|byte12
comment|/* byte12 */
decl_stmt|;
name|u8
name|byte13
comment|/* byte13 */
decl_stmt|;
name|u8
name|byte14
comment|/* byte14 */
decl_stmt|;
name|u8
name|byte15
comment|/* byte15 */
decl_stmt|;
name|u8
name|e5_reserved
comment|/* e5_reserved */
decl_stmt|;
name|__le16
name|word11
comment|/* word11 */
decl_stmt|;
name|__le32
name|reg10
comment|/* reg10 */
decl_stmt|;
name|__le32
name|reg11
comment|/* reg11 */
decl_stmt|;
name|__le32
name|reg12
comment|/* reg12 */
decl_stmt|;
name|__le32
name|reg13
comment|/* reg13 */
decl_stmt|;
name|__le32
name|reg14
comment|/* reg14 */
decl_stmt|;
name|__le32
name|reg15
comment|/* reg15 */
decl_stmt|;
name|__le32
name|reg16
comment|/* reg16 */
decl_stmt|;
name|__le32
name|reg17
comment|/* reg17 */
decl_stmt|;
name|__le32
name|reg18
comment|/* reg18 */
decl_stmt|;
name|__le32
name|reg19
comment|/* reg19 */
decl_stmt|;
name|__le16
name|word12
comment|/* word12 */
decl_stmt|;
name|__le16
name|word13
comment|/* word13 */
decl_stmt|;
name|__le16
name|word14
comment|/* word14 */
decl_stmt|;
name|__le16
name|word15
comment|/* word15 */
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|e4_tstorm_core_conn_ag_ctx
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
name|E4_TSTORM_CORE_CONN_AG_CTX_BIT0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E4_TSTORM_CORE_CONN_AG_CTX_BIT0_SHIFT
value|0
define|#
directive|define
name|E4_TSTORM_CORE_CONN_AG_CTX_BIT1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E4_TSTORM_CORE_CONN_AG_CTX_BIT1_SHIFT
value|1
define|#
directive|define
name|E4_TSTORM_CORE_CONN_AG_CTX_BIT2_MASK
value|0x1
comment|/* bit2 */
define|#
directive|define
name|E4_TSTORM_CORE_CONN_AG_CTX_BIT2_SHIFT
value|2
define|#
directive|define
name|E4_TSTORM_CORE_CONN_AG_CTX_BIT3_MASK
value|0x1
comment|/* bit3 */
define|#
directive|define
name|E4_TSTORM_CORE_CONN_AG_CTX_BIT3_SHIFT
value|3
define|#
directive|define
name|E4_TSTORM_CORE_CONN_AG_CTX_BIT4_MASK
value|0x1
comment|/* bit4 */
define|#
directive|define
name|E4_TSTORM_CORE_CONN_AG_CTX_BIT4_SHIFT
value|4
define|#
directive|define
name|E4_TSTORM_CORE_CONN_AG_CTX_BIT5_MASK
value|0x1
comment|/* bit5 */
define|#
directive|define
name|E4_TSTORM_CORE_CONN_AG_CTX_BIT5_SHIFT
value|5
define|#
directive|define
name|E4_TSTORM_CORE_CONN_AG_CTX_CF0_MASK
value|0x3
comment|/* timer0cf */
define|#
directive|define
name|E4_TSTORM_CORE_CONN_AG_CTX_CF0_SHIFT
value|6
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E4_TSTORM_CORE_CONN_AG_CTX_CF1_MASK
value|0x3
comment|/* timer1cf */
define|#
directive|define
name|E4_TSTORM_CORE_CONN_AG_CTX_CF1_SHIFT
value|0
define|#
directive|define
name|E4_TSTORM_CORE_CONN_AG_CTX_CF2_MASK
value|0x3
comment|/* timer2cf */
define|#
directive|define
name|E4_TSTORM_CORE_CONN_AG_CTX_CF2_SHIFT
value|2
define|#
directive|define
name|E4_TSTORM_CORE_CONN_AG_CTX_CF3_MASK
value|0x3
comment|/* timer_stop_all */
define|#
directive|define
name|E4_TSTORM_CORE_CONN_AG_CTX_CF3_SHIFT
value|4
define|#
directive|define
name|E4_TSTORM_CORE_CONN_AG_CTX_CF4_MASK
value|0x3
comment|/* cf4 */
define|#
directive|define
name|E4_TSTORM_CORE_CONN_AG_CTX_CF4_SHIFT
value|6
name|u8
name|flags2
decl_stmt|;
define|#
directive|define
name|E4_TSTORM_CORE_CONN_AG_CTX_CF5_MASK
value|0x3
comment|/* cf5 */
define|#
directive|define
name|E4_TSTORM_CORE_CONN_AG_CTX_CF5_SHIFT
value|0
define|#
directive|define
name|E4_TSTORM_CORE_CONN_AG_CTX_CF6_MASK
value|0x3
comment|/* cf6 */
define|#
directive|define
name|E4_TSTORM_CORE_CONN_AG_CTX_CF6_SHIFT
value|2
define|#
directive|define
name|E4_TSTORM_CORE_CONN_AG_CTX_CF7_MASK
value|0x3
comment|/* cf7 */
define|#
directive|define
name|E4_TSTORM_CORE_CONN_AG_CTX_CF7_SHIFT
value|4
define|#
directive|define
name|E4_TSTORM_CORE_CONN_AG_CTX_CF8_MASK
value|0x3
comment|/* cf8 */
define|#
directive|define
name|E4_TSTORM_CORE_CONN_AG_CTX_CF8_SHIFT
value|6
name|u8
name|flags3
decl_stmt|;
define|#
directive|define
name|E4_TSTORM_CORE_CONN_AG_CTX_CF9_MASK
value|0x3
comment|/* cf9 */
define|#
directive|define
name|E4_TSTORM_CORE_CONN_AG_CTX_CF9_SHIFT
value|0
define|#
directive|define
name|E4_TSTORM_CORE_CONN_AG_CTX_CF10_MASK
value|0x3
comment|/* cf10 */
define|#
directive|define
name|E4_TSTORM_CORE_CONN_AG_CTX_CF10_SHIFT
value|2
define|#
directive|define
name|E4_TSTORM_CORE_CONN_AG_CTX_CF0EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E4_TSTORM_CORE_CONN_AG_CTX_CF0EN_SHIFT
value|4
define|#
directive|define
name|E4_TSTORM_CORE_CONN_AG_CTX_CF1EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E4_TSTORM_CORE_CONN_AG_CTX_CF1EN_SHIFT
value|5
define|#
directive|define
name|E4_TSTORM_CORE_CONN_AG_CTX_CF2EN_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E4_TSTORM_CORE_CONN_AG_CTX_CF2EN_SHIFT
value|6
define|#
directive|define
name|E4_TSTORM_CORE_CONN_AG_CTX_CF3EN_MASK
value|0x1
comment|/* cf3en */
define|#
directive|define
name|E4_TSTORM_CORE_CONN_AG_CTX_CF3EN_SHIFT
value|7
name|u8
name|flags4
decl_stmt|;
define|#
directive|define
name|E4_TSTORM_CORE_CONN_AG_CTX_CF4EN_MASK
value|0x1
comment|/* cf4en */
define|#
directive|define
name|E4_TSTORM_CORE_CONN_AG_CTX_CF4EN_SHIFT
value|0
define|#
directive|define
name|E4_TSTORM_CORE_CONN_AG_CTX_CF5EN_MASK
value|0x1
comment|/* cf5en */
define|#
directive|define
name|E4_TSTORM_CORE_CONN_AG_CTX_CF5EN_SHIFT
value|1
define|#
directive|define
name|E4_TSTORM_CORE_CONN_AG_CTX_CF6EN_MASK
value|0x1
comment|/* cf6en */
define|#
directive|define
name|E4_TSTORM_CORE_CONN_AG_CTX_CF6EN_SHIFT
value|2
define|#
directive|define
name|E4_TSTORM_CORE_CONN_AG_CTX_CF7EN_MASK
value|0x1
comment|/* cf7en */
define|#
directive|define
name|E4_TSTORM_CORE_CONN_AG_CTX_CF7EN_SHIFT
value|3
define|#
directive|define
name|E4_TSTORM_CORE_CONN_AG_CTX_CF8EN_MASK
value|0x1
comment|/* cf8en */
define|#
directive|define
name|E4_TSTORM_CORE_CONN_AG_CTX_CF8EN_SHIFT
value|4
define|#
directive|define
name|E4_TSTORM_CORE_CONN_AG_CTX_CF9EN_MASK
value|0x1
comment|/* cf9en */
define|#
directive|define
name|E4_TSTORM_CORE_CONN_AG_CTX_CF9EN_SHIFT
value|5
define|#
directive|define
name|E4_TSTORM_CORE_CONN_AG_CTX_CF10EN_MASK
value|0x1
comment|/* cf10en */
define|#
directive|define
name|E4_TSTORM_CORE_CONN_AG_CTX_CF10EN_SHIFT
value|6
define|#
directive|define
name|E4_TSTORM_CORE_CONN_AG_CTX_RULE0EN_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E4_TSTORM_CORE_CONN_AG_CTX_RULE0EN_SHIFT
value|7
name|u8
name|flags5
decl_stmt|;
define|#
directive|define
name|E4_TSTORM_CORE_CONN_AG_CTX_RULE1EN_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E4_TSTORM_CORE_CONN_AG_CTX_RULE1EN_SHIFT
value|0
define|#
directive|define
name|E4_TSTORM_CORE_CONN_AG_CTX_RULE2EN_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E4_TSTORM_CORE_CONN_AG_CTX_RULE2EN_SHIFT
value|1
define|#
directive|define
name|E4_TSTORM_CORE_CONN_AG_CTX_RULE3EN_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E4_TSTORM_CORE_CONN_AG_CTX_RULE3EN_SHIFT
value|2
define|#
directive|define
name|E4_TSTORM_CORE_CONN_AG_CTX_RULE4EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E4_TSTORM_CORE_CONN_AG_CTX_RULE4EN_SHIFT
value|3
define|#
directive|define
name|E4_TSTORM_CORE_CONN_AG_CTX_RULE5EN_MASK
value|0x1
comment|/* rule5en */
define|#
directive|define
name|E4_TSTORM_CORE_CONN_AG_CTX_RULE5EN_SHIFT
value|4
define|#
directive|define
name|E4_TSTORM_CORE_CONN_AG_CTX_RULE6EN_MASK
value|0x1
comment|/* rule6en */
define|#
directive|define
name|E4_TSTORM_CORE_CONN_AG_CTX_RULE6EN_SHIFT
value|5
define|#
directive|define
name|E4_TSTORM_CORE_CONN_AG_CTX_RULE7EN_MASK
value|0x1
comment|/* rule7en */
define|#
directive|define
name|E4_TSTORM_CORE_CONN_AG_CTX_RULE7EN_SHIFT
value|6
define|#
directive|define
name|E4_TSTORM_CORE_CONN_AG_CTX_RULE8EN_MASK
value|0x1
comment|/* rule8en */
define|#
directive|define
name|E4_TSTORM_CORE_CONN_AG_CTX_RULE8EN_SHIFT
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
name|e4_ustorm_core_conn_ag_ctx
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
name|E4_USTORM_CORE_CONN_AG_CTX_BIT0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E4_USTORM_CORE_CONN_AG_CTX_BIT0_SHIFT
value|0
define|#
directive|define
name|E4_USTORM_CORE_CONN_AG_CTX_BIT1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E4_USTORM_CORE_CONN_AG_CTX_BIT1_SHIFT
value|1
define|#
directive|define
name|E4_USTORM_CORE_CONN_AG_CTX_CF0_MASK
value|0x3
comment|/* timer0cf */
define|#
directive|define
name|E4_USTORM_CORE_CONN_AG_CTX_CF0_SHIFT
value|2
define|#
directive|define
name|E4_USTORM_CORE_CONN_AG_CTX_CF1_MASK
value|0x3
comment|/* timer1cf */
define|#
directive|define
name|E4_USTORM_CORE_CONN_AG_CTX_CF1_SHIFT
value|4
define|#
directive|define
name|E4_USTORM_CORE_CONN_AG_CTX_CF2_MASK
value|0x3
comment|/* timer2cf */
define|#
directive|define
name|E4_USTORM_CORE_CONN_AG_CTX_CF2_SHIFT
value|6
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E4_USTORM_CORE_CONN_AG_CTX_CF3_MASK
value|0x3
comment|/* timer_stop_all */
define|#
directive|define
name|E4_USTORM_CORE_CONN_AG_CTX_CF3_SHIFT
value|0
define|#
directive|define
name|E4_USTORM_CORE_CONN_AG_CTX_CF4_MASK
value|0x3
comment|/* cf4 */
define|#
directive|define
name|E4_USTORM_CORE_CONN_AG_CTX_CF4_SHIFT
value|2
define|#
directive|define
name|E4_USTORM_CORE_CONN_AG_CTX_CF5_MASK
value|0x3
comment|/* cf5 */
define|#
directive|define
name|E4_USTORM_CORE_CONN_AG_CTX_CF5_SHIFT
value|4
define|#
directive|define
name|E4_USTORM_CORE_CONN_AG_CTX_CF6_MASK
value|0x3
comment|/* cf6 */
define|#
directive|define
name|E4_USTORM_CORE_CONN_AG_CTX_CF6_SHIFT
value|6
name|u8
name|flags2
decl_stmt|;
define|#
directive|define
name|E4_USTORM_CORE_CONN_AG_CTX_CF0EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E4_USTORM_CORE_CONN_AG_CTX_CF0EN_SHIFT
value|0
define|#
directive|define
name|E4_USTORM_CORE_CONN_AG_CTX_CF1EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E4_USTORM_CORE_CONN_AG_CTX_CF1EN_SHIFT
value|1
define|#
directive|define
name|E4_USTORM_CORE_CONN_AG_CTX_CF2EN_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E4_USTORM_CORE_CONN_AG_CTX_CF2EN_SHIFT
value|2
define|#
directive|define
name|E4_USTORM_CORE_CONN_AG_CTX_CF3EN_MASK
value|0x1
comment|/* cf3en */
define|#
directive|define
name|E4_USTORM_CORE_CONN_AG_CTX_CF3EN_SHIFT
value|3
define|#
directive|define
name|E4_USTORM_CORE_CONN_AG_CTX_CF4EN_MASK
value|0x1
comment|/* cf4en */
define|#
directive|define
name|E4_USTORM_CORE_CONN_AG_CTX_CF4EN_SHIFT
value|4
define|#
directive|define
name|E4_USTORM_CORE_CONN_AG_CTX_CF5EN_MASK
value|0x1
comment|/* cf5en */
define|#
directive|define
name|E4_USTORM_CORE_CONN_AG_CTX_CF5EN_SHIFT
value|5
define|#
directive|define
name|E4_USTORM_CORE_CONN_AG_CTX_CF6EN_MASK
value|0x1
comment|/* cf6en */
define|#
directive|define
name|E4_USTORM_CORE_CONN_AG_CTX_CF6EN_SHIFT
value|6
define|#
directive|define
name|E4_USTORM_CORE_CONN_AG_CTX_RULE0EN_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E4_USTORM_CORE_CONN_AG_CTX_RULE0EN_SHIFT
value|7
name|u8
name|flags3
decl_stmt|;
define|#
directive|define
name|E4_USTORM_CORE_CONN_AG_CTX_RULE1EN_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E4_USTORM_CORE_CONN_AG_CTX_RULE1EN_SHIFT
value|0
define|#
directive|define
name|E4_USTORM_CORE_CONN_AG_CTX_RULE2EN_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E4_USTORM_CORE_CONN_AG_CTX_RULE2EN_SHIFT
value|1
define|#
directive|define
name|E4_USTORM_CORE_CONN_AG_CTX_RULE3EN_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E4_USTORM_CORE_CONN_AG_CTX_RULE3EN_SHIFT
value|2
define|#
directive|define
name|E4_USTORM_CORE_CONN_AG_CTX_RULE4EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E4_USTORM_CORE_CONN_AG_CTX_RULE4EN_SHIFT
value|3
define|#
directive|define
name|E4_USTORM_CORE_CONN_AG_CTX_RULE5EN_MASK
value|0x1
comment|/* rule5en */
define|#
directive|define
name|E4_USTORM_CORE_CONN_AG_CTX_RULE5EN_SHIFT
value|4
define|#
directive|define
name|E4_USTORM_CORE_CONN_AG_CTX_RULE6EN_MASK
value|0x1
comment|/* rule6en */
define|#
directive|define
name|E4_USTORM_CORE_CONN_AG_CTX_RULE6EN_SHIFT
value|5
define|#
directive|define
name|E4_USTORM_CORE_CONN_AG_CTX_RULE7EN_MASK
value|0x1
comment|/* rule7en */
define|#
directive|define
name|E4_USTORM_CORE_CONN_AG_CTX_RULE7EN_SHIFT
value|6
define|#
directive|define
name|E4_USTORM_CORE_CONN_AG_CTX_RULE8EN_MASK
value|0x1
comment|/* rule8en */
define|#
directive|define
name|E4_USTORM_CORE_CONN_AG_CTX_RULE8EN_SHIFT
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
name|rx_producers
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
comment|/*  * The core storm context for the Mstorm  */
end_comment

begin_struct
struct|struct
name|mstorm_core_conn_st_ctx
block|{
name|__le32
name|reserved
index|[
literal|24
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The core storm context for the Ustorm  */
end_comment

begin_struct
struct|struct
name|ustorm_core_conn_st_ctx
block|{
name|__le32
name|reserved
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * core connection context  */
end_comment

begin_struct
struct|struct
name|core_conn_context
block|{
name|struct
name|ystorm_core_conn_st_ctx
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
name|pstorm_core_conn_st_ctx
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
name|xstorm_core_conn_st_ctx
name|xstorm_st_context
comment|/* xstorm storm context */
decl_stmt|;
name|struct
name|e4_xstorm_core_conn_ag_ctx
name|xstorm_ag_context
comment|/* xstorm aggregative context */
decl_stmt|;
name|struct
name|e4_tstorm_core_conn_ag_ctx
name|tstorm_ag_context
comment|/* tstorm aggregative context */
decl_stmt|;
name|struct
name|e4_ustorm_core_conn_ag_ctx
name|ustorm_ag_context
comment|/* ustorm aggregative context */
decl_stmt|;
name|struct
name|mstorm_core_conn_st_ctx
name|mstorm_st_context
comment|/* mstorm storm context */
decl_stmt|;
name|struct
name|ustorm_core_conn_st_ctx
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
block|}
struct|;
end_struct

begin_comment
comment|/*  * How ll2 should deal with packet upon errors  */
end_comment

begin_enum
enum|enum
name|core_error_handle
block|{
name|LL2_DROP_PACKET
comment|/* If error occurs drop packet */
block|,
name|LL2_DO_NOTHING
comment|/* If error occurs do nothing */
block|,
name|LL2_ASSERT
comment|/* If error occurs assert */
block|,
name|MAX_CORE_ERROR_HANDLE
block|}
enum|;
end_enum

begin_comment
comment|/*  * opcodes for the event ring  */
end_comment

begin_enum
enum|enum
name|core_event_opcode
block|{
name|CORE_EVENT_TX_QUEUE_START
block|,
name|CORE_EVENT_TX_QUEUE_STOP
block|,
name|CORE_EVENT_RX_QUEUE_START
block|,
name|CORE_EVENT_RX_QUEUE_STOP
block|,
name|CORE_EVENT_RX_QUEUE_FLUSH
block|,
name|MAX_CORE_EVENT_OPCODE
block|}
enum|;
end_enum

begin_comment
comment|/*  * The L4 pseudo checksum mode for Core  */
end_comment

begin_enum
enum|enum
name|core_l4_pseudo_checksum_mode
block|{
name|CORE_L4_PSEUDO_CSUM_CORRECT_LENGTH
comment|/* Pseudo Checksum on packet is calculated with the correct packet length. */
block|,
name|CORE_L4_PSEUDO_CSUM_ZERO_LENGTH
comment|/* Pseudo Checksum on packet is calculated with zero length. */
block|,
name|MAX_CORE_L4_PSEUDO_CHECKSUM_MODE
block|}
enum|;
end_enum

begin_comment
comment|/*  * Light-L2 RX Producers in Tstorm RAM  */
end_comment

begin_struct
struct|struct
name|core_ll2_port_stats
block|{
name|struct
name|regpair
name|gsi_invalid_hdr
decl_stmt|;
name|struct
name|regpair
name|gsi_invalid_pkt_length
decl_stmt|;
name|struct
name|regpair
name|gsi_unsupported_pkt_typ
decl_stmt|;
name|struct
name|regpair
name|gsi_crcchksm_error
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Ethernet TX Per Queue Stats  */
end_comment

begin_struct
struct|struct
name|core_ll2_pstorm_per_queue_stat
block|{
name|struct
name|regpair
name|sent_ucast_bytes
comment|/* number of total bytes sent without errors */
decl_stmt|;
name|struct
name|regpair
name|sent_mcast_bytes
comment|/* number of total bytes sent without errors */
decl_stmt|;
name|struct
name|regpair
name|sent_bcast_bytes
comment|/* number of total bytes sent without errors */
decl_stmt|;
name|struct
name|regpair
name|sent_ucast_pkts
comment|/* number of total packets sent without errors */
decl_stmt|;
name|struct
name|regpair
name|sent_mcast_pkts
comment|/* number of total packets sent without errors */
decl_stmt|;
name|struct
name|regpair
name|sent_bcast_pkts
comment|/* number of total packets sent without errors */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Light-L2 RX Producers in Tstorm RAM  */
end_comment

begin_struct
struct|struct
name|core_ll2_rx_prod
block|{
name|__le16
name|bd_prod
comment|/* BD Producer */
decl_stmt|;
name|__le16
name|cqe_prod
comment|/* CQE Producer */
decl_stmt|;
name|__le32
name|reserved
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|core_ll2_tstorm_per_queue_stat
block|{
name|struct
name|regpair
name|packet_too_big_discard
comment|/* Number of packets discarded because they are bigger than MTU */
decl_stmt|;
name|struct
name|regpair
name|no_buff_discard
comment|/* Number of packets discarded due to lack of host buffers */
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|core_ll2_ustorm_per_queue_stat
block|{
name|struct
name|regpair
name|rcv_ucast_bytes
decl_stmt|;
name|struct
name|regpair
name|rcv_mcast_bytes
decl_stmt|;
name|struct
name|regpair
name|rcv_bcast_bytes
decl_stmt|;
name|struct
name|regpair
name|rcv_ucast_pkts
decl_stmt|;
name|struct
name|regpair
name|rcv_mcast_pkts
decl_stmt|;
name|struct
name|regpair
name|rcv_bcast_pkts
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Core Ramrod Command IDs (light L2)  */
end_comment

begin_enum
enum|enum
name|core_ramrod_cmd_id
block|{
name|CORE_RAMROD_UNUSED
block|,
name|CORE_RAMROD_RX_QUEUE_START
comment|/* RX Queue Start Ramrod */
block|,
name|CORE_RAMROD_TX_QUEUE_START
comment|/* TX Queue Start Ramrod */
block|,
name|CORE_RAMROD_RX_QUEUE_STOP
comment|/* RX Queue Stop Ramrod */
block|,
name|CORE_RAMROD_TX_QUEUE_STOP
comment|/* TX Queue Stop Ramrod */
block|,
name|CORE_RAMROD_RX_QUEUE_FLUSH
comment|/* RX Flush queue Ramrod */
block|,
name|MAX_CORE_RAMROD_CMD_ID
block|}
enum|;
end_enum

begin_comment
comment|/*  * Core RX CQE Type for Light L2  */
end_comment

begin_enum
enum|enum
name|core_roce_flavor_type
block|{
name|CORE_ROCE
block|,
name|CORE_RROCE
block|,
name|MAX_CORE_ROCE_FLAVOR_TYPE
block|}
enum|;
end_enum

begin_comment
comment|/*  * Specifies how ll2 should deal with packets errors: packet_too_big and no_buff  */
end_comment

begin_struct
struct|struct
name|core_rx_action_on_error
block|{
name|u8
name|error_type
decl_stmt|;
define|#
directive|define
name|CORE_RX_ACTION_ON_ERROR_PACKET_TOO_BIG_MASK
value|0x3
comment|/* ll2 how to handle error packet_too_big (use enum core_error_handle) */
define|#
directive|define
name|CORE_RX_ACTION_ON_ERROR_PACKET_TOO_BIG_SHIFT
value|0
define|#
directive|define
name|CORE_RX_ACTION_ON_ERROR_NO_BUFF_MASK
value|0x3
comment|/* ll2 how to handle error with no_buff  (use enum core_error_handle) */
define|#
directive|define
name|CORE_RX_ACTION_ON_ERROR_NO_BUFF_SHIFT
value|2
define|#
directive|define
name|CORE_RX_ACTION_ON_ERROR_RESERVED_MASK
value|0xF
define|#
directive|define
name|CORE_RX_ACTION_ON_ERROR_RESERVED_SHIFT
value|4
block|}
struct|;
end_struct

begin_comment
comment|/*  * Core RX BD for Light L2  */
end_comment

begin_struct
struct|struct
name|core_rx_bd
block|{
name|struct
name|regpair
name|addr
decl_stmt|;
name|__le16
name|reserved
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Core RX CM offload BD for Light L2  */
end_comment

begin_struct
struct|struct
name|core_rx_bd_with_buff_len
block|{
name|struct
name|regpair
name|addr
decl_stmt|;
name|__le16
name|buff_length
decl_stmt|;
name|__le16
name|reserved
index|[
literal|3
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Core RX CM offload BD for Light L2  */
end_comment

begin_union
union|union
name|core_rx_bd_union
block|{
name|struct
name|core_rx_bd
name|rx_bd
comment|/* Core Rx Bd static buffer size */
decl_stmt|;
name|struct
name|core_rx_bd_with_buff_len
name|rx_bd_with_len
comment|/* Core Rx Bd with dynamic buffer length */
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/*  * Opaque Data for Light L2 RX CQE .   */
end_comment

begin_struct
struct|struct
name|core_rx_cqe_opaque_data
block|{
name|__le32
name|data
index|[
literal|2
index|]
comment|/* Opaque CQE Data */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Core RX CQE Type for Light L2  */
end_comment

begin_enum
enum|enum
name|core_rx_cqe_type
block|{
name|CORE_RX_CQE_ILLIGAL_TYPE
comment|/* Bad RX Cqe type */
block|,
name|CORE_RX_CQE_TYPE_REGULAR
comment|/* Regular Core RX CQE */
block|,
name|CORE_RX_CQE_TYPE_GSI_OFFLOAD
comment|/* Fp Gsi offload RX CQE */
block|,
name|CORE_RX_CQE_TYPE_SLOW_PATH
comment|/* Slow path Core RX CQE */
block|,
name|MAX_CORE_RX_CQE_TYPE
block|}
enum|;
end_enum

begin_comment
comment|/*  * Core RX CQE for Light L2 .   */
end_comment

begin_struct
struct|struct
name|core_rx_fast_path_cqe
block|{
name|u8
name|type
comment|/* CQE type */
decl_stmt|;
name|u8
name|placement_offset
comment|/* Offset (in bytes) of the packet from start of the buffer */
decl_stmt|;
name|struct
name|parsing_and_err_flags
name|parse_flags
comment|/* Parsing and error flags from the parser */
decl_stmt|;
name|__le16
name|packet_length
comment|/* Total packet length (from the parser) */
decl_stmt|;
name|__le16
name|vlan
comment|/* 802.1q VLAN tag */
decl_stmt|;
name|struct
name|core_rx_cqe_opaque_data
name|opaque_data
comment|/* Opaque Data */
decl_stmt|;
name|struct
name|parsing_err_flags
name|err_flags
comment|/* bit- map: each bit represents a specific error. errors indications are provided by the cracker. see spec for detailed description */
decl_stmt|;
name|__le16
name|reserved0
decl_stmt|;
name|__le32
name|reserved1
index|[
literal|3
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Core Rx CM offload CQE .   */
end_comment

begin_struct
struct|struct
name|core_rx_gsi_offload_cqe
block|{
name|u8
name|type
comment|/* CQE type */
decl_stmt|;
name|u8
name|data_length_error
comment|/* set if gsi data is bigger than buff */
decl_stmt|;
name|struct
name|parsing_and_err_flags
name|parse_flags
comment|/* Parsing and error flags from the parser */
decl_stmt|;
name|__le16
name|data_length
comment|/* Total packet length (from the parser) */
decl_stmt|;
name|__le16
name|vlan
comment|/* 802.1q VLAN tag */
decl_stmt|;
name|__le32
name|src_mac_addrhi
comment|/* hi 4 bytes source mac address */
decl_stmt|;
name|__le16
name|src_mac_addrlo
comment|/* lo 2 bytes of source mac address */
decl_stmt|;
name|__le16
name|qp_id
comment|/* These are the lower 16 bit of QP id in RoCE BTH header */
decl_stmt|;
name|__le32
name|gid_dst
index|[
literal|4
index|]
comment|/* Gid destination address */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Core RX CQE for Light L2 .   */
end_comment

begin_struct
struct|struct
name|core_rx_slow_path_cqe
block|{
name|u8
name|type
comment|/* CQE type */
decl_stmt|;
name|u8
name|ramrod_cmd_id
decl_stmt|;
name|__le16
name|echo
decl_stmt|;
name|struct
name|core_rx_cqe_opaque_data
name|opaque_data
comment|/* Opaque Data */
decl_stmt|;
name|__le32
name|reserved1
index|[
literal|5
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Core RX CM offload BD for Light L2  */
end_comment

begin_union
union|union
name|core_rx_cqe_union
block|{
name|struct
name|core_rx_fast_path_cqe
name|rx_cqe_fp
comment|/* Fast path CQE */
decl_stmt|;
name|struct
name|core_rx_gsi_offload_cqe
name|rx_cqe_gsi
comment|/* GSI offload CQE */
decl_stmt|;
name|struct
name|core_rx_slow_path_cqe
name|rx_cqe_sp
comment|/* Slow path CQE */
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/*  * Ramrod data for rx queue start ramrod  */
end_comment

begin_struct
struct|struct
name|core_rx_start_ramrod_data
block|{
name|struct
name|regpair
name|bd_base
comment|/* bd address of the first bd page */
decl_stmt|;
name|struct
name|regpair
name|cqe_pbl_addr
comment|/* Base address on host of CQE PBL */
decl_stmt|;
name|__le16
name|mtu
comment|/* Maximum transmission unit */
decl_stmt|;
name|__le16
name|sb_id
comment|/* Status block ID */
decl_stmt|;
name|u8
name|sb_index
comment|/* index of the protocol index */
decl_stmt|;
name|u8
name|complete_cqe_flg
comment|/* post completion to the CQE ring if set */
decl_stmt|;
name|u8
name|complete_event_flg
comment|/* post completion to the event ring if set */
decl_stmt|;
name|u8
name|drop_ttl0_flg
comment|/* drop packet with ttl0 if set */
decl_stmt|;
name|__le16
name|num_of_pbl_pages
comment|/* Num of pages in CQE PBL */
decl_stmt|;
name|u8
name|inner_vlan_removal_en
comment|/* if set, 802.1q tags will be removed and copied to CQE */
decl_stmt|;
name|u8
name|queue_id
comment|/* Light L2 RX Queue ID */
decl_stmt|;
name|u8
name|main_func_queue
comment|/* Is this the main queue for the PF */
decl_stmt|;
name|u8
name|mf_si_bcast_accept_all
comment|/* Duplicate broadcast packets to LL2 main queue in mf_si mode. Valid if main_func_queue is set. */
decl_stmt|;
name|u8
name|mf_si_mcast_accept_all
comment|/* Duplicate multicast packets to LL2 main queue in mf_si mode. Valid if main_func_queue is set. */
decl_stmt|;
name|struct
name|core_rx_action_on_error
name|action_on_error
comment|/* Specifies how ll2 should deal with packets errors: packet_too_big and no_buff */
decl_stmt|;
name|u8
name|gsi_offload_flag
comment|/* set when in GSI offload mode on ROCE connection */
decl_stmt|;
name|u8
name|reserved
index|[
literal|7
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Ramrod data for rx queue stop ramrod  */
end_comment

begin_struct
struct|struct
name|core_rx_stop_ramrod_data
block|{
name|u8
name|complete_cqe_flg
comment|/* post completion to the CQE ring if set */
decl_stmt|;
name|u8
name|complete_event_flg
comment|/* post completion to the event ring if set */
decl_stmt|;
name|u8
name|queue_id
comment|/* Light L2 RX Queue ID */
decl_stmt|;
name|u8
name|reserved1
decl_stmt|;
name|__le16
name|reserved2
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Flags for Core TX BD  */
end_comment

begin_struct
struct|struct
name|core_tx_bd_data
block|{
name|__le16
name|as_bitfield
decl_stmt|;
define|#
directive|define
name|CORE_TX_BD_DATA_FORCE_VLAN_MODE_MASK
value|0x1
comment|/* Do not allow additional VLAN manipulations on this packet (DCB) */
define|#
directive|define
name|CORE_TX_BD_DATA_FORCE_VLAN_MODE_SHIFT
value|0
define|#
directive|define
name|CORE_TX_BD_DATA_VLAN_INSERTION_MASK
value|0x1
comment|/* Insert VLAN into packet */
define|#
directive|define
name|CORE_TX_BD_DATA_VLAN_INSERTION_SHIFT
value|1
define|#
directive|define
name|CORE_TX_BD_DATA_START_BD_MASK
value|0x1
comment|/* This is the first BD of the packet (for debug) */
define|#
directive|define
name|CORE_TX_BD_DATA_START_BD_SHIFT
value|2
define|#
directive|define
name|CORE_TX_BD_DATA_IP_CSUM_MASK
value|0x1
comment|/* Calculate the IP checksum for the packet */
define|#
directive|define
name|CORE_TX_BD_DATA_IP_CSUM_SHIFT
value|3
define|#
directive|define
name|CORE_TX_BD_DATA_L4_CSUM_MASK
value|0x1
comment|/* Calculate the L4 checksum for the packet */
define|#
directive|define
name|CORE_TX_BD_DATA_L4_CSUM_SHIFT
value|4
define|#
directive|define
name|CORE_TX_BD_DATA_IPV6_EXT_MASK
value|0x1
comment|/* Packet is IPv6 with extensions */
define|#
directive|define
name|CORE_TX_BD_DATA_IPV6_EXT_SHIFT
value|5
define|#
directive|define
name|CORE_TX_BD_DATA_L4_PROTOCOL_MASK
value|0x1
comment|/* If IPv6+ext, and if l4_csum is 1, than this field indicates L4 protocol: 0-TCP, 1-UDP */
define|#
directive|define
name|CORE_TX_BD_DATA_L4_PROTOCOL_SHIFT
value|6
define|#
directive|define
name|CORE_TX_BD_DATA_L4_PSEUDO_CSUM_MODE_MASK
value|0x1
comment|/* The pseudo checksum mode to place in the L4 checksum field. Required only when IPv6+ext and l4_csum is set. (use enum core_l4_pseudo_checksum_mode) */
define|#
directive|define
name|CORE_TX_BD_DATA_L4_PSEUDO_CSUM_MODE_SHIFT
value|7
define|#
directive|define
name|CORE_TX_BD_DATA_NBDS_MASK
value|0xF
comment|/* Number of BDs that make up one packet - width wide enough to present CORE_LL2_TX_MAX_BDS_PER_PACKET */
define|#
directive|define
name|CORE_TX_BD_DATA_NBDS_SHIFT
value|8
define|#
directive|define
name|CORE_TX_BD_DATA_ROCE_FLAV_MASK
value|0x1
comment|/* Use roce_flavor enum - Differentiate between Roce flavors is valid when connType is ROCE (use enum core_roce_flavor_type) */
define|#
directive|define
name|CORE_TX_BD_DATA_ROCE_FLAV_SHIFT
value|12
define|#
directive|define
name|CORE_TX_BD_DATA_IP_LEN_MASK
value|0x1
comment|/* Calculate ip length */
define|#
directive|define
name|CORE_TX_BD_DATA_IP_LEN_SHIFT
value|13
define|#
directive|define
name|CORE_TX_BD_DATA_RESERVED0_MASK
value|0x3
define|#
directive|define
name|CORE_TX_BD_DATA_RESERVED0_SHIFT
value|14
block|}
struct|;
end_struct

begin_comment
comment|/*  * Core TX BD for Light L2  */
end_comment

begin_struct
struct|struct
name|core_tx_bd
block|{
name|struct
name|regpair
name|addr
comment|/* Buffer Address */
decl_stmt|;
name|__le16
name|nbytes
comment|/* Number of Bytes in Buffer */
decl_stmt|;
name|__le16
name|nw_vlan_or_lb_echo
comment|/* Network packets: VLAN to insert to packet (if insertion flag set) LoopBack packets: echo data to pass to Rx */
decl_stmt|;
name|struct
name|core_tx_bd_data
name|bd_data
comment|/* BD Flags */
decl_stmt|;
name|__le16
name|bitfield1
decl_stmt|;
define|#
directive|define
name|CORE_TX_BD_L4_HDR_OFFSET_W_MASK
value|0x3FFF
comment|/* L4 Header Offset from start of packet (in Words). This is needed if both l4_csum and ipv6_ext are set */
define|#
directive|define
name|CORE_TX_BD_L4_HDR_OFFSET_W_SHIFT
value|0
define|#
directive|define
name|CORE_TX_BD_TX_DST_MASK
value|0x3
comment|/* Packet destination - Network, Loopback or Drop (use enum core_tx_dest) */
define|#
directive|define
name|CORE_TX_BD_TX_DST_SHIFT
value|14
block|}
struct|;
end_struct

begin_comment
comment|/*  * Light L2 TX Destination  */
end_comment

begin_enum
enum|enum
name|core_tx_dest
block|{
name|CORE_TX_DEST_NW
comment|/* TX Destination to the Network */
block|,
name|CORE_TX_DEST_LB
comment|/* TX Destination to the Loopback */
block|,
name|CORE_TX_DEST_RESERVED
block|,
name|CORE_TX_DEST_DROP
comment|/* TX Drop */
block|,
name|MAX_CORE_TX_DEST
block|}
enum|;
end_enum

begin_comment
comment|/*  * Ramrod data for tx queue start ramrod  */
end_comment

begin_struct
struct|struct
name|core_tx_start_ramrod_data
block|{
name|struct
name|regpair
name|pbl_base_addr
comment|/* Address of the pbl page */
decl_stmt|;
name|__le16
name|mtu
comment|/* Maximum transmission unit */
decl_stmt|;
name|__le16
name|sb_id
comment|/* Status block ID */
decl_stmt|;
name|u8
name|sb_index
comment|/* Status block protocol index */
decl_stmt|;
name|u8
name|stats_en
comment|/* Statistics Enable */
decl_stmt|;
name|u8
name|stats_id
comment|/* Statistics Counter ID */
decl_stmt|;
name|u8
name|conn_type
comment|/* connection type that loaded ll2 */
decl_stmt|;
name|__le16
name|pbl_size
comment|/* Number of BD pages pointed by PBL */
decl_stmt|;
name|__le16
name|qm_pq_id
comment|/* QM PQ ID */
decl_stmt|;
name|u8
name|gsi_offload_flag
comment|/* set when in GSI offload mode on ROCE connection */
decl_stmt|;
name|u8
name|resrved
index|[
literal|3
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Ramrod data for tx queue stop ramrod  */
end_comment

begin_struct
struct|struct
name|core_tx_stop_ramrod_data
block|{
name|__le32
name|reserved0
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Enum flag for what type of dcb data to update  */
end_comment

begin_enum
enum|enum
name|dcb_dscp_update_mode
block|{
name|DONT_UPDATE_DCB_DSCP
comment|/* use when no change should be done to dcb data */
block|,
name|UPDATE_DCB
comment|/* use to update only l2 (vlan) priority */
block|,
name|UPDATE_DSCP
comment|/* use to update only l3 dscp */
block|,
name|UPDATE_DCB_DSCP
comment|/* update vlan pri and dscp */
block|,
name|MAX_DCB_DSCP_UPDATE_MODE
block|}
enum|;
end_enum

begin_struct
struct|struct
name|eth_mstorm_per_pf_stat
block|{
name|struct
name|regpair
name|gre_discard_pkts
comment|/* Dropped GRE RX packets */
decl_stmt|;
name|struct
name|regpair
name|vxlan_discard_pkts
comment|/* Dropped VXLAN RX packets */
decl_stmt|;
name|struct
name|regpair
name|geneve_discard_pkts
comment|/* Dropped GENEVE RX packets */
decl_stmt|;
name|struct
name|regpair
name|lb_discard_pkts
comment|/* Dropped Tx switched packets */
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|eth_mstorm_per_queue_stat
block|{
name|struct
name|regpair
name|ttl0_discard
comment|/* Number of packets discarded because TTL=0 (in IPv4) or hopLimit=0 (in IPv6) */
decl_stmt|;
name|struct
name|regpair
name|packet_too_big_discard
comment|/* Number of packets discarded because they are bigger than MTU */
decl_stmt|;
name|struct
name|regpair
name|no_buff_discard
comment|/* Number of packets discarded due to lack of host buffers (BDs/SGEs/CQEs) */
decl_stmt|;
name|struct
name|regpair
name|not_active_discard
comment|/* Number of packets discarded because of no active Rx connection */
decl_stmt|;
name|struct
name|regpair
name|tpa_coalesced_pkts
comment|/* number of coalesced packets in all TPA aggregations */
decl_stmt|;
name|struct
name|regpair
name|tpa_coalesced_events
comment|/* total number of TPA aggregations */
decl_stmt|;
name|struct
name|regpair
name|tpa_aborts_num
comment|/* number of aggregations, which abnormally ended */
decl_stmt|;
name|struct
name|regpair
name|tpa_coalesced_bytes
comment|/* total TCP payload length in all TPA aggregations */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Ethernet TX Per PF  */
end_comment

begin_struct
struct|struct
name|eth_pstorm_per_pf_stat
block|{
name|struct
name|regpair
name|sent_lb_ucast_bytes
comment|/* number of total ucast bytes sent on loopback port without errors */
decl_stmt|;
name|struct
name|regpair
name|sent_lb_mcast_bytes
comment|/* number of total mcast bytes sent on loopback port without errors */
decl_stmt|;
name|struct
name|regpair
name|sent_lb_bcast_bytes
comment|/* number of total bcast bytes sent on loopback port without errors */
decl_stmt|;
name|struct
name|regpair
name|sent_lb_ucast_pkts
comment|/* number of total ucast packets sent on loopback port without errors */
decl_stmt|;
name|struct
name|regpair
name|sent_lb_mcast_pkts
comment|/* number of total mcast packets sent on loopback port without errors */
decl_stmt|;
name|struct
name|regpair
name|sent_lb_bcast_pkts
comment|/* number of total bcast packets sent on loopback port without errors */
decl_stmt|;
name|struct
name|regpair
name|sent_gre_bytes
comment|/* Sent GRE bytes */
decl_stmt|;
name|struct
name|regpair
name|sent_vxlan_bytes
comment|/* Sent VXLAN bytes */
decl_stmt|;
name|struct
name|regpair
name|sent_geneve_bytes
comment|/* Sent GENEVE bytes */
decl_stmt|;
name|struct
name|regpair
name|sent_gre_pkts
comment|/* Sent GRE packets */
decl_stmt|;
name|struct
name|regpair
name|sent_vxlan_pkts
comment|/* Sent VXLAN packets */
decl_stmt|;
name|struct
name|regpair
name|sent_geneve_pkts
comment|/* Sent GENEVE packets */
decl_stmt|;
name|struct
name|regpair
name|gre_drop_pkts
comment|/* Dropped GRE TX packets */
decl_stmt|;
name|struct
name|regpair
name|vxlan_drop_pkts
comment|/* Dropped VXLAN TX packets */
decl_stmt|;
name|struct
name|regpair
name|geneve_drop_pkts
comment|/* Dropped GENEVE TX packets */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Ethernet TX Per Queue Stats  */
end_comment

begin_struct
struct|struct
name|eth_pstorm_per_queue_stat
block|{
name|struct
name|regpair
name|sent_ucast_bytes
comment|/* number of total bytes sent without errors */
decl_stmt|;
name|struct
name|regpair
name|sent_mcast_bytes
comment|/* number of total bytes sent without errors */
decl_stmt|;
name|struct
name|regpair
name|sent_bcast_bytes
comment|/* number of total bytes sent without errors */
decl_stmt|;
name|struct
name|regpair
name|sent_ucast_pkts
comment|/* number of total packets sent without errors */
decl_stmt|;
name|struct
name|regpair
name|sent_mcast_pkts
comment|/* number of total packets sent without errors */
decl_stmt|;
name|struct
name|regpair
name|sent_bcast_pkts
comment|/* number of total packets sent without errors */
decl_stmt|;
name|struct
name|regpair
name|error_drop_pkts
comment|/* number of total packets dropped due to errors */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * ETH Rx producers data  */
end_comment

begin_struct
struct|struct
name|eth_rx_rate_limit
block|{
name|__le16
name|mult
comment|/* Rate Limit Multiplier - (Storm Clock (MHz) * 8 / Desired Bandwidth (MB/s)) */
decl_stmt|;
name|__le16
name|cnst
comment|/* Constant term to add (or subtract from number of cycles) */
decl_stmt|;
name|u8
name|add_sub_cnst
comment|/* Add (1) or subtract (0) constant term */
decl_stmt|;
name|u8
name|reserved0
decl_stmt|;
name|__le16
name|reserved1
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|eth_ustorm_per_pf_stat
block|{
name|struct
name|regpair
name|rcv_lb_ucast_bytes
comment|/* number of total ucast bytes received on loopback port without errors */
decl_stmt|;
name|struct
name|regpair
name|rcv_lb_mcast_bytes
comment|/* number of total mcast bytes received on loopback port without errors */
decl_stmt|;
name|struct
name|regpair
name|rcv_lb_bcast_bytes
comment|/* number of total bcast bytes received on loopback port without errors */
decl_stmt|;
name|struct
name|regpair
name|rcv_lb_ucast_pkts
comment|/* number of total ucast packets received on loopback port without errors */
decl_stmt|;
name|struct
name|regpair
name|rcv_lb_mcast_pkts
comment|/* number of total mcast packets received on loopback port without errors */
decl_stmt|;
name|struct
name|regpair
name|rcv_lb_bcast_pkts
comment|/* number of total bcast packets received on loopback port without errors */
decl_stmt|;
name|struct
name|regpair
name|rcv_gre_bytes
comment|/* Received GRE bytes */
decl_stmt|;
name|struct
name|regpair
name|rcv_vxlan_bytes
comment|/* Received VXLAN bytes */
decl_stmt|;
name|struct
name|regpair
name|rcv_geneve_bytes
comment|/* Received GENEVE bytes */
decl_stmt|;
name|struct
name|regpair
name|rcv_gre_pkts
comment|/* Received GRE packets */
decl_stmt|;
name|struct
name|regpair
name|rcv_vxlan_pkts
comment|/* Received VXLAN packets */
decl_stmt|;
name|struct
name|regpair
name|rcv_geneve_pkts
comment|/* Received GENEVE packets */
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|eth_ustorm_per_queue_stat
block|{
name|struct
name|regpair
name|rcv_ucast_bytes
decl_stmt|;
name|struct
name|regpair
name|rcv_mcast_bytes
decl_stmt|;
name|struct
name|regpair
name|rcv_bcast_bytes
decl_stmt|;
name|struct
name|regpair
name|rcv_ucast_pkts
decl_stmt|;
name|struct
name|regpair
name|rcv_mcast_pkts
decl_stmt|;
name|struct
name|regpair
name|rcv_bcast_pkts
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Event Ring Next Page Address  */
end_comment

begin_struct
struct|struct
name|event_ring_next_addr
block|{
name|struct
name|regpair
name|addr
comment|/* Next Page Address */
decl_stmt|;
name|__le32
name|reserved
index|[
literal|2
index|]
comment|/* Reserved */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Event Ring Element  */
end_comment

begin_union
union|union
name|event_ring_element
block|{
name|struct
name|event_ring_entry
name|entry
comment|/* Event Ring Entry */
decl_stmt|;
name|struct
name|event_ring_next_addr
name|next_addr
comment|/* Event Ring Next Page Address */
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/*  * Ports mode  */
end_comment

begin_enum
enum|enum
name|fw_flow_ctrl_mode
block|{
name|flow_ctrl_pause
block|,
name|flow_ctrl_pfc
block|,
name|MAX_FW_FLOW_CTRL_MODE
block|}
enum|;
end_enum

begin_comment
comment|/*  * Major and Minor hsi Versions  */
end_comment

begin_struct
struct|struct
name|hsi_fp_ver_struct
block|{
name|u8
name|minor_ver_arr
index|[
literal|2
index|]
comment|/* Minor Version of hsi loading pf */
decl_stmt|;
name|u8
name|major_ver_arr
index|[
literal|2
index|]
comment|/* Major Version of driver loading pf */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Integration Phase  */
end_comment

begin_enum
enum|enum
name|integ_phase
block|{
name|INTEG_PHASE_BB_A0_LATEST
init|=
literal|3
comment|/* BB A0 latest integration phase */
block|,
name|INTEG_PHASE_BB_B0_NO_MCP
init|=
literal|10
comment|/* BB B0 without MCP */
block|,
name|INTEG_PHASE_BB_B0_WITH_MCP
init|=
literal|11
comment|/* BB B0 with MCP */
block|,
name|MAX_INTEG_PHASE
block|}
enum|;
end_enum

begin_comment
comment|/*  * Ports mode  */
end_comment

begin_enum
enum|enum
name|iwarp_ll2_tx_queues
block|{
name|IWARP_LL2_IN_ORDER_TX_QUEUE
init|=
literal|1
comment|/* LL2 queue for OOO packets sent in-order by the driver */
block|,
name|IWARP_LL2_ALIGNED_TX_QUEUE
comment|/* LL2 queue for unaligned packets sent aligned by the driver */
block|,
name|IWARP_LL2_ALIGNED_RIGHT_TRIMMED_TX_QUEUE
comment|/* LL2 queue for unaligned packets sent aligned and was right-trimmed by the driver */
block|,
name|IWARP_LL2_ERROR
comment|/* Error indication */
block|,
name|MAX_IWARP_LL2_TX_QUEUES
block|}
enum|;
end_enum

begin_comment
comment|/*  * Malicious VF error ID  */
end_comment

begin_enum
enum|enum
name|malicious_vf_error_id
block|{
name|MALICIOUS_VF_NO_ERROR
comment|/* Zero placeholder value */
block|,
name|VF_PF_CHANNEL_NOT_READY
comment|/* Writing to VF/PF channel when it is not ready */
block|,
name|VF_ZONE_MSG_NOT_VALID
comment|/* VF channel message is not valid */
block|,
name|VF_ZONE_FUNC_NOT_ENABLED
comment|/* Parent PF of VF channel is not active */
block|,
name|ETH_PACKET_TOO_SMALL
comment|/* TX packet is shorter then reported on BDs or from minimal size */
block|,
name|ETH_ILLEGAL_VLAN_MODE
comment|/* Tx packet with marked as insert VLAN when its illegal */
block|,
name|ETH_MTU_VIOLATION
comment|/* TX packet is greater then MTU */
block|,
name|ETH_ILLEGAL_INBAND_TAGS
comment|/* TX packet has illegal inband tags marked */
block|,
name|ETH_VLAN_INSERT_AND_INBAND_VLAN
comment|/* Vlan cant be added to inband tag */
block|,
name|ETH_ILLEGAL_NBDS
comment|/* indicated number of BDs for the packet is illegal */
block|,
name|ETH_FIRST_BD_WO_SOP
comment|/* 1st BD must have start_bd flag set */
block|,
name|ETH_INSUFFICIENT_BDS
comment|/* There are not enough BDs for transmission of even one packet */
block|,
name|ETH_ILLEGAL_LSO_HDR_NBDS
comment|/* Header NBDs value is illegal */
block|,
name|ETH_ILLEGAL_LSO_MSS
comment|/* LSO MSS value is more than allowed */
block|,
name|ETH_ZERO_SIZE_BD
comment|/* empty BD (which not contains control flags) is illegal  */
block|,
name|ETH_ILLEGAL_LSO_HDR_LEN
comment|/* LSO header size is above the limit  */
block|,
name|ETH_INSUFFICIENT_PAYLOAD
comment|/* In LSO its expected that on the local BD ring there will be at least MSS bytes of data */
block|,
name|ETH_EDPM_OUT_OF_SYNC
comment|/* Valid BDs on local ring after EDPM L2 sync */
block|,
name|ETH_TUNN_IPV6_EXT_NBD_ERR
comment|/* Tunneled packet with IPv6+Ext without a proper number of BDs */
block|,
name|ETH_CONTROL_PACKET_VIOLATION
comment|/* VF sent control frame such as PFC */
block|,
name|ETH_ANTI_SPOOFING_ERR
comment|/* Anti-Spoofing verification failure */
block|,
name|MAX_MALICIOUS_VF_ERROR_ID
block|}
enum|;
end_enum

begin_comment
comment|/*  * Mstorm non-triggering VF zone  */
end_comment

begin_struct
struct|struct
name|mstorm_non_trigger_vf_zone
block|{
name|struct
name|eth_mstorm_per_queue_stat
name|eth_queue_stat
comment|/* VF statistic bucket */
decl_stmt|;
name|struct
name|eth_rx_prod_data
name|eth_rx_queue_producers
index|[
name|ETH_MAX_NUM_RX_QUEUES_PER_VF_QUAD
index|]
comment|/* VF RX queues producers */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Mstorm VF zone  */
end_comment

begin_struct
struct|struct
name|mstorm_vf_zone
block|{
name|struct
name|mstorm_non_trigger_vf_zone
name|non_trigger
comment|/* non-interrupt-triggering zone */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * personality per PF  */
end_comment

begin_enum
enum|enum
name|personality_type
block|{
name|BAD_PERSONALITY_TYP
block|,
name|PERSONALITY_ISCSI
comment|/* iSCSI and LL2 */
block|,
name|PERSONALITY_FCOE
comment|/* Fcoe and LL2 */
block|,
name|PERSONALITY_RDMA_AND_ETH
comment|/* Roce or Iwarp, Eth and LL2 */
block|,
name|PERSONALITY_RDMA
comment|/* Roce and LL2 */
block|,
name|PERSONALITY_CORE
comment|/* CORE(LL2) */
block|,
name|PERSONALITY_ETH
comment|/* Ethernet */
block|,
name|PERSONALITY_TOE
comment|/* Toe and LL2 */
block|,
name|MAX_PERSONALITY_TYPE
block|}
enum|;
end_enum

begin_comment
comment|/*  * tunnel configuration  */
end_comment

begin_struct
struct|struct
name|pf_start_tunnel_config
block|{
name|u8
name|set_vxlan_udp_port_flg
comment|/* Set VXLAN tunnel UDP destination port to vxlan_udp_port. If not set - FW will use a default port */
decl_stmt|;
name|u8
name|set_geneve_udp_port_flg
comment|/* Set GENEVE tunnel UDP destination port to geneve_udp_port. If not set - FW will use a default port */
decl_stmt|;
name|u8
name|tunnel_clss_vxlan
comment|/* Rx classification scheme for VXLAN tunnel. */
decl_stmt|;
name|u8
name|tunnel_clss_l2geneve
comment|/* Rx classification scheme for l2 GENEVE tunnel. */
decl_stmt|;
name|u8
name|tunnel_clss_ipgeneve
comment|/* Rx classification scheme for ip GENEVE tunnel. */
decl_stmt|;
name|u8
name|tunnel_clss_l2gre
comment|/* Rx classification scheme for l2 GRE tunnel. */
decl_stmt|;
name|u8
name|tunnel_clss_ipgre
comment|/* Rx classification scheme for ip GRE tunnel. */
decl_stmt|;
name|u8
name|reserved
decl_stmt|;
name|__le16
name|vxlan_udp_port
comment|/* VXLAN tunnel UDP destination port. Valid if set_vxlan_udp_port_flg=1 */
decl_stmt|;
name|__le16
name|geneve_udp_port
comment|/* GENEVE tunnel UDP destination port. Valid if set_geneve_udp_port_flg=1 */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Ramrod data for PF start ramrod  */
end_comment

begin_struct
struct|struct
name|pf_start_ramrod_data
block|{
name|struct
name|regpair
name|event_ring_pbl_addr
comment|/* Address of event ring PBL */
decl_stmt|;
name|struct
name|regpair
name|consolid_q_pbl_addr
comment|/* PBL address of consolidation queue */
decl_stmt|;
name|struct
name|pf_start_tunnel_config
name|tunnel_config
comment|/* tunnel configuration. */
decl_stmt|;
name|__le32
name|reserved
decl_stmt|;
name|__le16
name|event_ring_sb_id
comment|/* Status block ID */
decl_stmt|;
name|u8
name|base_vf_id
comment|/* All VfIds owned by Pf will be from baseVfId till baseVfId+numVfs */
decl_stmt|;
name|u8
name|num_vfs
comment|/* Amount of vfs owned by PF */
decl_stmt|;
name|u8
name|event_ring_num_pages
comment|/* Number of PBL pages in event ring */
decl_stmt|;
name|u8
name|event_ring_sb_index
comment|/* Status block index */
decl_stmt|;
name|u8
name|path_id
comment|/* HW path ID (engine ID) */
decl_stmt|;
name|u8
name|warning_as_error
comment|/* In FW asserts, treat warning as error */
decl_stmt|;
name|u8
name|dont_log_ramrods
comment|/* If not set - throw a warning for each ramrod (for debug) */
decl_stmt|;
name|u8
name|personality
comment|/* define what type of personality is new PF */
decl_stmt|;
name|__le16
name|log_type_mask
comment|/* Log type mask. Each bit set enables a corresponding event type logging. Event types are defined as ASSERT_LOG_TYPE_xxx */
decl_stmt|;
name|u8
name|mf_mode
comment|/* Multi function mode */
decl_stmt|;
name|u8
name|integ_phase
comment|/* Integration phase */
decl_stmt|;
name|u8
name|allow_npar_tx_switching
comment|/* If set, inter-pf tx switching is allowed in Switch Independent function mode */
decl_stmt|;
name|u8
name|inner_to_outer_pri_map
index|[
literal|8
index|]
comment|/* Map from inner to outer priority. Set pri_map_valid when init map */
decl_stmt|;
name|u8
name|pri_map_valid
comment|/* If inner_to_outer_pri_map is initialize then set pri_map_valid */
decl_stmt|;
name|__le32
name|outer_tag
comment|/* In case mf_mode is MF_OVLAN, this field specifies the outer vlan (lower 16 bits) and ethType to use (higher 16 bits) */
decl_stmt|;
name|struct
name|hsi_fp_ver_struct
name|hsi_fp_ver
comment|/* FP HSI version to be used by FW */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Data for port update ramrod  */
end_comment

begin_struct
struct|struct
name|protocol_dcb_data
block|{
name|u8
name|dcb_enable_flag
comment|/* dcbEnable flag value */
decl_stmt|;
name|u8
name|dscp_enable_flag
comment|/* If set use dscp value */
decl_stmt|;
name|u8
name|dcb_priority
comment|/* dcbPri flag value */
decl_stmt|;
name|u8
name|dcb_tc
comment|/* dcb TC value */
decl_stmt|;
name|u8
name|dscp_val
comment|/* dscp value to write if dscp_enable_flag is set */
decl_stmt|;
name|u8
name|reserved0
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Update tunnel configuration  */
end_comment

begin_struct
struct|struct
name|pf_update_tunnel_config
block|{
name|u8
name|update_rx_pf_clss
comment|/* Update RX per PF tunnel classification scheme. */
decl_stmt|;
name|u8
name|update_rx_def_ucast_clss
comment|/* Update per PORT default tunnel RX classification scheme for traffic with unknown unicast outer MAC in NPAR mode. */
decl_stmt|;
name|u8
name|update_rx_def_non_ucast_clss
comment|/* Update per PORT default tunnel RX classification scheme for traffic with non unicast outer MAC in NPAR mode. */
decl_stmt|;
name|u8
name|set_vxlan_udp_port_flg
comment|/* Update VXLAN tunnel UDP destination port. */
decl_stmt|;
name|u8
name|set_geneve_udp_port_flg
comment|/* Update GENEVE tunnel UDP destination port. */
decl_stmt|;
name|u8
name|tunnel_clss_vxlan
comment|/* Classification scheme for VXLAN tunnel. */
decl_stmt|;
name|u8
name|tunnel_clss_l2geneve
comment|/* Classification scheme for l2 GENEVE tunnel. */
decl_stmt|;
name|u8
name|tunnel_clss_ipgeneve
comment|/* Classification scheme for ip GENEVE tunnel. */
decl_stmt|;
name|u8
name|tunnel_clss_l2gre
comment|/* Classification scheme for l2 GRE tunnel. */
decl_stmt|;
name|u8
name|tunnel_clss_ipgre
comment|/* Classification scheme for ip GRE tunnel. */
decl_stmt|;
name|__le16
name|vxlan_udp_port
comment|/* VXLAN tunnel UDP destination port. */
decl_stmt|;
name|__le16
name|geneve_udp_port
comment|/* GENEVE tunnel UDP destination port. */
decl_stmt|;
name|__le16
name|reserved
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Data for port update ramrod  */
end_comment

begin_struct
struct|struct
name|pf_update_ramrod_data
block|{
name|u8
name|pf_id
decl_stmt|;
name|u8
name|update_eth_dcb_data_mode
comment|/* Update Eth DCB  data indication */
decl_stmt|;
name|u8
name|update_fcoe_dcb_data_mode
comment|/* Update FCOE DCB  data indication */
decl_stmt|;
name|u8
name|update_iscsi_dcb_data_mode
comment|/* Update iSCSI DCB  data indication */
decl_stmt|;
name|u8
name|update_roce_dcb_data_mode
comment|/* Update ROCE DCB  data indication */
decl_stmt|;
name|u8
name|update_rroce_dcb_data_mode
comment|/* Update RROCE (RoceV2) DCB  data indication */
decl_stmt|;
name|u8
name|update_iwarp_dcb_data_mode
comment|/* Update IWARP DCB  data indication */
decl_stmt|;
name|u8
name|update_mf_vlan_flag
comment|/* Update MF outer vlan Id */
decl_stmt|;
name|struct
name|protocol_dcb_data
name|eth_dcb_data
comment|/* core eth related fields */
decl_stmt|;
name|struct
name|protocol_dcb_data
name|fcoe_dcb_data
comment|/* core fcoe related fields */
decl_stmt|;
name|struct
name|protocol_dcb_data
name|iscsi_dcb_data
comment|/* core iscsi related fields */
decl_stmt|;
name|struct
name|protocol_dcb_data
name|roce_dcb_data
comment|/* core roce related fields */
decl_stmt|;
name|struct
name|protocol_dcb_data
name|rroce_dcb_data
comment|/* core roce related fields */
decl_stmt|;
name|struct
name|protocol_dcb_data
name|iwarp_dcb_data
comment|/* core iwarp related fields */
decl_stmt|;
name|__le16
name|mf_vlan
comment|/* new outer vlan id value */
decl_stmt|;
name|__le16
name|reserved
decl_stmt|;
name|struct
name|pf_update_tunnel_config
name|tunnel_config
comment|/* tunnel configuration. */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Ports mode  */
end_comment

begin_enum
enum|enum
name|ports_mode
block|{
name|ENGX2_PORTX1
comment|/* 2 engines x 1 port */
block|,
name|ENGX2_PORTX2
comment|/* 2 engines x 2 ports */
block|,
name|ENGX1_PORTX1
comment|/* 1 engine  x 1 port */
block|,
name|ENGX1_PORTX2
comment|/* 1 engine  x 2 ports */
block|,
name|ENGX1_PORTX4
comment|/* 1 engine  x 4 ports */
block|,
name|MAX_PORTS_MODE
block|}
enum|;
end_enum

begin_comment
comment|/*  * use to index in hsi_fp_[major|minor]_ver_arr per protocol  */
end_comment

begin_enum
enum|enum
name|protocol_version_array_key
block|{
name|ETH_VER_KEY
init|=
literal|0
block|,
name|ROCE_VER_KEY
block|,
name|MAX_PROTOCOL_VERSION_ARRAY_KEY
block|}
enum|;
end_enum

begin_comment
comment|/*  * RDMA TX Stats  */
end_comment

begin_struct
struct|struct
name|rdma_sent_stats
block|{
name|struct
name|regpair
name|sent_bytes
comment|/* number of total RDMA bytes sent */
decl_stmt|;
name|struct
name|regpair
name|sent_pkts
comment|/* number of total RDMA packets sent */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Pstorm non-triggering VF zone  */
end_comment

begin_struct
struct|struct
name|pstorm_non_trigger_vf_zone
block|{
name|struct
name|eth_pstorm_per_queue_stat
name|eth_queue_stat
comment|/* VF statistic bucket */
decl_stmt|;
name|struct
name|rdma_sent_stats
name|rdma_stats
comment|/* RoCE sent statistics */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Pstorm VF zone  */
end_comment

begin_struct
struct|struct
name|pstorm_vf_zone
block|{
name|struct
name|pstorm_non_trigger_vf_zone
name|non_trigger
comment|/* non-interrupt-triggering zone */
decl_stmt|;
name|struct
name|regpair
name|reserved
index|[
literal|7
index|]
comment|/* vf_zone size mus be power of 2 */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Ramrod Header of SPQE  */
end_comment

begin_struct
struct|struct
name|ramrod_header
block|{
name|__le32
name|cid
comment|/* Slowpath Connection CID */
decl_stmt|;
name|u8
name|cmd_id
comment|/* Ramrod Cmd (Per Protocol Type) */
decl_stmt|;
name|u8
name|protocol_id
comment|/* Ramrod Protocol ID */
decl_stmt|;
name|__le16
name|echo
comment|/* Ramrod echo */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * RDMA RX Stats  */
end_comment

begin_struct
struct|struct
name|rdma_rcv_stats
block|{
name|struct
name|regpair
name|rcv_bytes
comment|/* number of total RDMA bytes received */
decl_stmt|;
name|struct
name|regpair
name|rcv_pkts
comment|/* number of total RDMA packets received */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Data for update QCN/DCQCN RL ramrod  */
end_comment

begin_struct
struct|struct
name|rl_update_ramrod_data
block|{
name|u8
name|qcn_update_param_flg
comment|/* Update QCN global params: timeout. */
decl_stmt|;
name|u8
name|dcqcn_update_param_flg
comment|/* Update DCQCN global params: timeout, g, k. */
decl_stmt|;
name|u8
name|rl_init_flg
comment|/* Init RL parameters, when RL disabled. */
decl_stmt|;
name|u8
name|rl_start_flg
comment|/* Start RL in IDLE state. Set rate to maximum. */
decl_stmt|;
name|u8
name|rl_stop_flg
comment|/* Stop RL. */
decl_stmt|;
name|u8
name|rl_id_first
comment|/* ID of first or single RL, that will be updated. */
decl_stmt|;
name|u8
name|rl_id_last
comment|/* ID of last RL, that will be updated. If clear, single RL will updated. */
decl_stmt|;
name|u8
name|rl_dc_qcn_flg
comment|/* If set, RL will used for DCQCN. */
decl_stmt|;
name|__le32
name|rl_bc_rate
comment|/* Byte Counter Limit. */
decl_stmt|;
name|__le16
name|rl_max_rate
comment|/* Maximum rate in 1.6 Mbps resolution. */
decl_stmt|;
name|__le16
name|rl_r_ai
comment|/* Active increase rate. */
decl_stmt|;
name|__le16
name|rl_r_hai
comment|/* Hyper active increase rate. */
decl_stmt|;
name|__le16
name|dcqcn_g
comment|/* DCQCN Alpha update gain in 1/64K resolution . */
decl_stmt|;
name|__le32
name|dcqcn_k_us
comment|/* DCQCN Alpha update interval. */
decl_stmt|;
name|__le32
name|dcqcn_timeuot_us
comment|/* DCQCN timeout. */
decl_stmt|;
name|__le32
name|qcn_timeuot_us
comment|/* QCN timeout. */
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
comment|/*  * Slowpath Element (SPQE)  */
end_comment

begin_struct
struct|struct
name|slow_path_element
block|{
name|struct
name|ramrod_header
name|hdr
comment|/* Ramrod Header */
decl_stmt|;
name|struct
name|regpair
name|data_ptr
comment|/* Pointer to the Ramrod Data on the Host */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Tstorm non-triggering VF zone  */
end_comment

begin_struct
struct|struct
name|tstorm_non_trigger_vf_zone
block|{
name|struct
name|rdma_rcv_stats
name|rdma_stats
comment|/* RoCE received statistics */
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|tstorm_per_port_stat
block|{
name|struct
name|regpair
name|trunc_error_discard
comment|/* packet is dropped because it was truncated in NIG */
decl_stmt|;
name|struct
name|regpair
name|mac_error_discard
comment|/* packet is dropped because of Ethernet FCS error */
decl_stmt|;
name|struct
name|regpair
name|mftag_filter_discard
comment|/* packet is dropped because classification was unsuccessful */
decl_stmt|;
name|struct
name|regpair
name|eth_mac_filter_discard
comment|/* packet was passed to Ethernet and dropped because of no mac filter match */
decl_stmt|;
name|struct
name|regpair
name|ll2_mac_filter_discard
comment|/* packet passed to Light L2 and dropped because Light L2 is not configured for this PF */
decl_stmt|;
name|struct
name|regpair
name|ll2_conn_disabled_discard
comment|/* packet passed to Light L2 and dropped because Light L2 is not configured for this PF */
decl_stmt|;
name|struct
name|regpair
name|iscsi_irregular_pkt
comment|/* packet is an ISCSI irregular packet */
decl_stmt|;
name|struct
name|regpair
name|fcoe_irregular_pkt
comment|/* packet is an FCOE irregular packet */
decl_stmt|;
name|struct
name|regpair
name|roce_irregular_pkt
comment|/* packet is an ROCE irregular packet */
decl_stmt|;
name|struct
name|regpair
name|iwarp_irregular_pkt
comment|/* packet is an IWARP irregular packet */
decl_stmt|;
name|struct
name|regpair
name|eth_irregular_pkt
comment|/* packet is an ETH irregular packet */
decl_stmt|;
name|struct
name|regpair
name|toe_irregular_pkt
comment|/* packet is an TOE irregular packet */
decl_stmt|;
name|struct
name|regpair
name|preroce_irregular_pkt
comment|/* packet is an PREROCE irregular packet */
decl_stmt|;
name|struct
name|regpair
name|eth_gre_tunn_filter_discard
comment|/* GRE dropped packets */
decl_stmt|;
name|struct
name|regpair
name|eth_vxlan_tunn_filter_discard
comment|/* VXLAN dropped packets */
decl_stmt|;
name|struct
name|regpair
name|eth_geneve_tunn_filter_discard
comment|/* GENEVE dropped packets */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Tstorm VF zone  */
end_comment

begin_struct
struct|struct
name|tstorm_vf_zone
block|{
name|struct
name|tstorm_non_trigger_vf_zone
name|non_trigger
comment|/* non-interrupt-triggering zone */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Tunnel classification scheme  */
end_comment

begin_enum
enum|enum
name|tunnel_clss
block|{
name|TUNNEL_CLSS_MAC_VLAN
init|=
literal|0
comment|/* Use MAC and VLAN from first L2 header for vport classification. */
block|,
name|TUNNEL_CLSS_MAC_VNI
comment|/* Use MAC from first L2 header and VNI from tunnel header for vport classification */
block|,
name|TUNNEL_CLSS_INNER_MAC_VLAN
comment|/* Use MAC and VLAN from last L2 header for vport classification */
block|,
name|TUNNEL_CLSS_INNER_MAC_VNI
comment|/* Use MAC from last L2 header and VNI from tunnel header for vport classification */
block|,
name|TUNNEL_CLSS_MAC_VLAN_DUAL_STAGE
comment|/* Use MAC and VLAN from last L2 header for vport classification. If no exact match, use MAC and VLAN from first L2 header for classification. */
block|,
name|MAX_TUNNEL_CLSS
block|}
enum|;
end_enum

begin_comment
comment|/*  * Ustorm non-triggering VF zone  */
end_comment

begin_struct
struct|struct
name|ustorm_non_trigger_vf_zone
block|{
name|struct
name|eth_ustorm_per_queue_stat
name|eth_queue_stat
comment|/* VF statistic bucket */
decl_stmt|;
name|struct
name|regpair
name|vf_pf_msg_addr
comment|/* VF-PF message address */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Ustorm triggering VF zone  */
end_comment

begin_struct
struct|struct
name|ustorm_trigger_vf_zone
block|{
name|u8
name|vf_pf_msg_valid
comment|/* VF-PF message valid flag */
decl_stmt|;
name|u8
name|reserved
index|[
literal|7
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Ustorm VF zone  */
end_comment

begin_struct
struct|struct
name|ustorm_vf_zone
block|{
name|struct
name|ustorm_non_trigger_vf_zone
name|non_trigger
comment|/* non-interrupt-triggering zone */
decl_stmt|;
name|struct
name|ustorm_trigger_vf_zone
name|trigger
comment|/* interrupt triggering zone */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * VF-PF channel data  */
end_comment

begin_struct
struct|struct
name|vf_pf_channel_data
block|{
name|__le32
name|ready
comment|/* 0: VF-PF Channel NOT ready. Waiting for ack from PF driver. 1: VF-PF Channel is ready for a new transaction. */
decl_stmt|;
name|u8
name|valid
comment|/* 0: VF-PF Channel is invalid because of malicious VF. 1: VF-PF Channel is valid. */
decl_stmt|;
name|u8
name|reserved0
decl_stmt|;
name|__le16
name|reserved1
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Ramrod data for VF start ramrod  */
end_comment

begin_struct
struct|struct
name|vf_start_ramrod_data
block|{
name|u8
name|vf_id
comment|/* VF ID */
decl_stmt|;
name|u8
name|enable_flr_ack
comment|/* If set, initial cleanup ack will be sent to parent PF SP event queue */
decl_stmt|;
name|__le16
name|opaque_fid
comment|/* VF opaque FID */
decl_stmt|;
name|u8
name|personality
comment|/* define what type of personality is new VF */
decl_stmt|;
name|u8
name|reserved
index|[
literal|7
index|]
decl_stmt|;
name|struct
name|hsi_fp_ver_struct
name|hsi_fp_ver
comment|/* FP HSI version to be used by FW */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Ramrod data for VF start ramrod  */
end_comment

begin_struct
struct|struct
name|vf_stop_ramrod_data
block|{
name|u8
name|vf_id
comment|/* VF ID */
decl_stmt|;
name|u8
name|reserved0
decl_stmt|;
name|__le16
name|reserved1
decl_stmt|;
name|__le32
name|reserved2
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * VF zone size mode.  */
end_comment

begin_enum
enum|enum
name|vf_zone_size_mode
block|{
name|VF_ZONE_SIZE_MODE_DEFAULT
comment|/* Default VF zone size. Up to 192 VF supported. */
block|,
name|VF_ZONE_SIZE_MODE_DOUBLE
comment|/* Doubled VF zone size. Up to 96 VF supported. */
block|,
name|VF_ZONE_SIZE_MODE_QUAD
comment|/* Quad VF zone size. Up to 48 VF supported. */
block|,
name|MAX_VF_ZONE_SIZE_MODE
block|}
enum|;
end_enum

begin_comment
comment|/*  * Attentions status block  */
end_comment

begin_struct
struct|struct
name|atten_status_block
block|{
name|__le32
name|atten_bits
decl_stmt|;
name|__le32
name|atten_ack
decl_stmt|;
name|__le16
name|reserved0
decl_stmt|;
name|__le16
name|sb_index
comment|/* status block running index */
decl_stmt|;
name|__le32
name|reserved1
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Igu cleanup bit values to distinguish between clean or producer consumer update.  */
end_comment

begin_enum
enum|enum
name|command_type_bit
block|{
name|IGU_COMMAND_TYPE_NOP
init|=
literal|0
block|,
name|IGU_COMMAND_TYPE_SET
init|=
literal|1
block|,
name|MAX_COMMAND_TYPE_BIT
block|}
enum|;
end_enum

begin_comment
comment|/*  * DMAE command  */
end_comment

begin_struct
struct|struct
name|dmae_cmd
block|{
name|__le32
name|opcode
decl_stmt|;
define|#
directive|define
name|DMAE_CMD_SRC_MASK
value|0x1
comment|/* DMA Source. 0 - PCIe, 1 - GRC (use enum dmae_cmd_src_enum) */
define|#
directive|define
name|DMAE_CMD_SRC_SHIFT
value|0
define|#
directive|define
name|DMAE_CMD_DST_MASK
value|0x3
comment|/* DMA destination. 0 - None, 1 - PCIe, 2 - GRC, 3 - None (use enum dmae_cmd_dst_enum) */
define|#
directive|define
name|DMAE_CMD_DST_SHIFT
value|1
define|#
directive|define
name|DMAE_CMD_C_DST_MASK
value|0x1
comment|/* Completion destination. 0 - PCie, 1 - GRC (use enum dmae_cmd_c_dst_enum) */
define|#
directive|define
name|DMAE_CMD_C_DST_SHIFT
value|3
define|#
directive|define
name|DMAE_CMD_CRC_RESET_MASK
value|0x1
comment|/* Reset the CRC result (do not use the previous result as the seed) */
define|#
directive|define
name|DMAE_CMD_CRC_RESET_SHIFT
value|4
define|#
directive|define
name|DMAE_CMD_SRC_ADDR_RESET_MASK
value|0x1
comment|/* Reset the source address in the next go to the same source address of the previous go */
define|#
directive|define
name|DMAE_CMD_SRC_ADDR_RESET_SHIFT
value|5
define|#
directive|define
name|DMAE_CMD_DST_ADDR_RESET_MASK
value|0x1
comment|/* Reset the destination address in the next go to the same destination address of the previous go */
define|#
directive|define
name|DMAE_CMD_DST_ADDR_RESET_SHIFT
value|6
define|#
directive|define
name|DMAE_CMD_COMP_FUNC_MASK
value|0x1
comment|/* 0   completion function is the same as src function, 1 - 0   completion function is the same as dst function (use enum dmae_cmd_comp_func_enum) */
define|#
directive|define
name|DMAE_CMD_COMP_FUNC_SHIFT
value|7
define|#
directive|define
name|DMAE_CMD_COMP_WORD_EN_MASK
value|0x1
comment|/* 0 - Do not write a completion word, 1 - Write a completion word (use enum dmae_cmd_comp_word_en_enum) */
define|#
directive|define
name|DMAE_CMD_COMP_WORD_EN_SHIFT
value|8
define|#
directive|define
name|DMAE_CMD_COMP_CRC_EN_MASK
value|0x1
comment|/* 0 - Do not write a CRC word, 1 - Write a CRC word (use enum dmae_cmd_comp_crc_en_enum) */
define|#
directive|define
name|DMAE_CMD_COMP_CRC_EN_SHIFT
value|9
define|#
directive|define
name|DMAE_CMD_COMP_CRC_OFFSET_MASK
value|0x7
comment|/* The CRC word should be taken from the DMAE address space from address 9+X, where X is the value in these bits. */
define|#
directive|define
name|DMAE_CMD_COMP_CRC_OFFSET_SHIFT
value|10
define|#
directive|define
name|DMAE_CMD_RESERVED1_MASK
value|0x1
define|#
directive|define
name|DMAE_CMD_RESERVED1_SHIFT
value|13
define|#
directive|define
name|DMAE_CMD_ENDIANITY_MODE_MASK
value|0x3
define|#
directive|define
name|DMAE_CMD_ENDIANITY_MODE_SHIFT
value|14
define|#
directive|define
name|DMAE_CMD_ERR_HANDLING_MASK
value|0x3
comment|/* The field specifies how the completion word is affected by PCIe read error. 0   Send a regular completion, 1 - Send a completion with an error indication, 2   do not send a completion (use enum dmae_cmd_error_handling_enum) */
define|#
directive|define
name|DMAE_CMD_ERR_HANDLING_SHIFT
value|16
define|#
directive|define
name|DMAE_CMD_PORT_ID_MASK
value|0x3
comment|/* The port ID to be placed on the  RF FID  field of the GRC bus. this field is used both when GRC is the destination and when it is the source of the DMAE transaction. */
define|#
directive|define
name|DMAE_CMD_PORT_ID_SHIFT
value|18
define|#
directive|define
name|DMAE_CMD_SRC_PF_ID_MASK
value|0xF
comment|/* Source PCI function number [3:0] */
define|#
directive|define
name|DMAE_CMD_SRC_PF_ID_SHIFT
value|20
define|#
directive|define
name|DMAE_CMD_DST_PF_ID_MASK
value|0xF
comment|/* Destination PCI function number [3:0] */
define|#
directive|define
name|DMAE_CMD_DST_PF_ID_SHIFT
value|24
define|#
directive|define
name|DMAE_CMD_SRC_VF_ID_VALID_MASK
value|0x1
comment|/* Source VFID valid */
define|#
directive|define
name|DMAE_CMD_SRC_VF_ID_VALID_SHIFT
value|28
define|#
directive|define
name|DMAE_CMD_DST_VF_ID_VALID_MASK
value|0x1
comment|/* Destination VFID valid */
define|#
directive|define
name|DMAE_CMD_DST_VF_ID_VALID_SHIFT
value|29
define|#
directive|define
name|DMAE_CMD_RESERVED2_MASK
value|0x3
define|#
directive|define
name|DMAE_CMD_RESERVED2_SHIFT
value|30
name|__le32
name|src_addr_lo
comment|/* PCIe source address low in bytes or GRC source address in DW */
decl_stmt|;
name|__le32
name|src_addr_hi
comment|/* PCIe source address high in bytes or reserved (if source is GRC) */
decl_stmt|;
name|__le32
name|dst_addr_lo
comment|/* PCIe destination address low in bytes or GRC destination address in DW */
decl_stmt|;
name|__le32
name|dst_addr_hi
comment|/* PCIe destination address high in bytes or reserved (if destination is GRC) */
decl_stmt|;
name|__le16
name|length_dw
comment|/* Length in DW */
decl_stmt|;
name|__le16
name|opcode_b
decl_stmt|;
define|#
directive|define
name|DMAE_CMD_SRC_VF_ID_MASK
value|0xFF
comment|/* Source VF id */
define|#
directive|define
name|DMAE_CMD_SRC_VF_ID_SHIFT
value|0
define|#
directive|define
name|DMAE_CMD_DST_VF_ID_MASK
value|0xFF
comment|/* Destination VF id */
define|#
directive|define
name|DMAE_CMD_DST_VF_ID_SHIFT
value|8
name|__le32
name|comp_addr_lo
comment|/* PCIe completion address low in bytes or GRC completion address in DW */
decl_stmt|;
name|__le32
name|comp_addr_hi
comment|/* PCIe completion address high in bytes or reserved (if completion address is GRC) */
decl_stmt|;
name|__le32
name|comp_val
comment|/* Value to write to completion address */
decl_stmt|;
name|__le32
name|crc32
comment|/* crc16 result */
decl_stmt|;
name|__le32
name|crc_32_c
comment|/* crc32_c result */
decl_stmt|;
name|__le16
name|crc16
comment|/* crc16 result */
decl_stmt|;
name|__le16
name|crc16_c
comment|/* crc16_c result */
decl_stmt|;
name|__le16
name|crc10
comment|/* crc_t10 result */
decl_stmt|;
name|__le16
name|reserved
decl_stmt|;
name|__le16
name|xsum16
comment|/* checksum16 result  */
decl_stmt|;
name|__le16
name|xsum8
comment|/* checksum8 result  */
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
name|dmae_cmd_comp_crc_en_enum
block|{
name|dmae_cmd_comp_crc_disabled
comment|/* Do not write a CRC word */
block|,
name|dmae_cmd_comp_crc_enabled
comment|/* Write a CRC word */
block|,
name|MAX_DMAE_CMD_COMP_CRC_EN_ENUM
block|}
enum|;
end_enum

begin_enum
enum|enum
name|dmae_cmd_comp_func_enum
block|{
name|dmae_cmd_comp_func_to_src
comment|/* completion word and/or CRC will be sent to SRC-PCI function/SRC VFID */
block|,
name|dmae_cmd_comp_func_to_dst
comment|/* completion word and/or CRC will be sent to DST-PCI function/DST VFID */
block|,
name|MAX_DMAE_CMD_COMP_FUNC_ENUM
block|}
enum|;
end_enum

begin_enum
enum|enum
name|dmae_cmd_comp_word_en_enum
block|{
name|dmae_cmd_comp_word_disabled
comment|/* Do not write a completion word */
block|,
name|dmae_cmd_comp_word_enabled
comment|/* Write the completion word */
block|,
name|MAX_DMAE_CMD_COMP_WORD_EN_ENUM
block|}
enum|;
end_enum

begin_enum
enum|enum
name|dmae_cmd_c_dst_enum
block|{
name|dmae_cmd_c_dst_pcie
block|,
name|dmae_cmd_c_dst_grc
block|,
name|MAX_DMAE_CMD_C_DST_ENUM
block|}
enum|;
end_enum

begin_enum
enum|enum
name|dmae_cmd_dst_enum
block|{
name|dmae_cmd_dst_none_0
block|,
name|dmae_cmd_dst_pcie
block|,
name|dmae_cmd_dst_grc
block|,
name|dmae_cmd_dst_none_3
block|,
name|MAX_DMAE_CMD_DST_ENUM
block|}
enum|;
end_enum

begin_enum
enum|enum
name|dmae_cmd_error_handling_enum
block|{
name|dmae_cmd_error_handling_send_regular_comp
comment|/* Send a regular completion (with no error indication) */
block|,
name|dmae_cmd_error_handling_send_comp_with_err
comment|/* Send a completion with an error indication (i.e. set bit 31 of the completion word) */
block|,
name|dmae_cmd_error_handling_dont_send_comp
comment|/* Do not send a completion */
block|,
name|MAX_DMAE_CMD_ERROR_HANDLING_ENUM
block|}
enum|;
end_enum

begin_enum
enum|enum
name|dmae_cmd_src_enum
block|{
name|dmae_cmd_src_pcie
comment|/* The source is the PCIe */
block|,
name|dmae_cmd_src_grc
comment|/* The source is the GRC */
block|,
name|MAX_DMAE_CMD_SRC_ENUM
block|}
enum|;
end_enum

begin_struct
struct|struct
name|e4_mstorm_core_conn_ag_ctx
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
name|E4_MSTORM_CORE_CONN_AG_CTX_BIT0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E4_MSTORM_CORE_CONN_AG_CTX_BIT0_SHIFT
value|0
define|#
directive|define
name|E4_MSTORM_CORE_CONN_AG_CTX_BIT1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E4_MSTORM_CORE_CONN_AG_CTX_BIT1_SHIFT
value|1
define|#
directive|define
name|E4_MSTORM_CORE_CONN_AG_CTX_CF0_MASK
value|0x3
comment|/* cf0 */
define|#
directive|define
name|E4_MSTORM_CORE_CONN_AG_CTX_CF0_SHIFT
value|2
define|#
directive|define
name|E4_MSTORM_CORE_CONN_AG_CTX_CF1_MASK
value|0x3
comment|/* cf1 */
define|#
directive|define
name|E4_MSTORM_CORE_CONN_AG_CTX_CF1_SHIFT
value|4
define|#
directive|define
name|E4_MSTORM_CORE_CONN_AG_CTX_CF2_MASK
value|0x3
comment|/* cf2 */
define|#
directive|define
name|E4_MSTORM_CORE_CONN_AG_CTX_CF2_SHIFT
value|6
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E4_MSTORM_CORE_CONN_AG_CTX_CF0EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E4_MSTORM_CORE_CONN_AG_CTX_CF0EN_SHIFT
value|0
define|#
directive|define
name|E4_MSTORM_CORE_CONN_AG_CTX_CF1EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E4_MSTORM_CORE_CONN_AG_CTX_CF1EN_SHIFT
value|1
define|#
directive|define
name|E4_MSTORM_CORE_CONN_AG_CTX_CF2EN_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E4_MSTORM_CORE_CONN_AG_CTX_CF2EN_SHIFT
value|2
define|#
directive|define
name|E4_MSTORM_CORE_CONN_AG_CTX_RULE0EN_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E4_MSTORM_CORE_CONN_AG_CTX_RULE0EN_SHIFT
value|3
define|#
directive|define
name|E4_MSTORM_CORE_CONN_AG_CTX_RULE1EN_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E4_MSTORM_CORE_CONN_AG_CTX_RULE1EN_SHIFT
value|4
define|#
directive|define
name|E4_MSTORM_CORE_CONN_AG_CTX_RULE2EN_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E4_MSTORM_CORE_CONN_AG_CTX_RULE2EN_SHIFT
value|5
define|#
directive|define
name|E4_MSTORM_CORE_CONN_AG_CTX_RULE3EN_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E4_MSTORM_CORE_CONN_AG_CTX_RULE3EN_SHIFT
value|6
define|#
directive|define
name|E4_MSTORM_CORE_CONN_AG_CTX_RULE4EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E4_MSTORM_CORE_CONN_AG_CTX_RULE4EN_SHIFT
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
name|e4_ystorm_core_conn_ag_ctx
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
name|E4_YSTORM_CORE_CONN_AG_CTX_BIT0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E4_YSTORM_CORE_CONN_AG_CTX_BIT0_SHIFT
value|0
define|#
directive|define
name|E4_YSTORM_CORE_CONN_AG_CTX_BIT1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E4_YSTORM_CORE_CONN_AG_CTX_BIT1_SHIFT
value|1
define|#
directive|define
name|E4_YSTORM_CORE_CONN_AG_CTX_CF0_MASK
value|0x3
comment|/* cf0 */
define|#
directive|define
name|E4_YSTORM_CORE_CONN_AG_CTX_CF0_SHIFT
value|2
define|#
directive|define
name|E4_YSTORM_CORE_CONN_AG_CTX_CF1_MASK
value|0x3
comment|/* cf1 */
define|#
directive|define
name|E4_YSTORM_CORE_CONN_AG_CTX_CF1_SHIFT
value|4
define|#
directive|define
name|E4_YSTORM_CORE_CONN_AG_CTX_CF2_MASK
value|0x3
comment|/* cf2 */
define|#
directive|define
name|E4_YSTORM_CORE_CONN_AG_CTX_CF2_SHIFT
value|6
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E4_YSTORM_CORE_CONN_AG_CTX_CF0EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E4_YSTORM_CORE_CONN_AG_CTX_CF0EN_SHIFT
value|0
define|#
directive|define
name|E4_YSTORM_CORE_CONN_AG_CTX_CF1EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E4_YSTORM_CORE_CONN_AG_CTX_CF1EN_SHIFT
value|1
define|#
directive|define
name|E4_YSTORM_CORE_CONN_AG_CTX_CF2EN_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E4_YSTORM_CORE_CONN_AG_CTX_CF2EN_SHIFT
value|2
define|#
directive|define
name|E4_YSTORM_CORE_CONN_AG_CTX_RULE0EN_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E4_YSTORM_CORE_CONN_AG_CTX_RULE0EN_SHIFT
value|3
define|#
directive|define
name|E4_YSTORM_CORE_CONN_AG_CTX_RULE1EN_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E4_YSTORM_CORE_CONN_AG_CTX_RULE1EN_SHIFT
value|4
define|#
directive|define
name|E4_YSTORM_CORE_CONN_AG_CTX_RULE2EN_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E4_YSTORM_CORE_CONN_AG_CTX_RULE2EN_SHIFT
value|5
define|#
directive|define
name|E4_YSTORM_CORE_CONN_AG_CTX_RULE3EN_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E4_YSTORM_CORE_CONN_AG_CTX_RULE3EN_SHIFT
value|6
define|#
directive|define
name|E4_YSTORM_CORE_CONN_AG_CTX_RULE4EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E4_YSTORM_CORE_CONN_AG_CTX_RULE4EN_SHIFT
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
name|e5_mstorm_core_conn_ag_ctx
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
name|E5_MSTORM_CORE_CONN_AG_CTX_BIT0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E5_MSTORM_CORE_CONN_AG_CTX_BIT0_SHIFT
value|0
define|#
directive|define
name|E5_MSTORM_CORE_CONN_AG_CTX_BIT1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E5_MSTORM_CORE_CONN_AG_CTX_BIT1_SHIFT
value|1
define|#
directive|define
name|E5_MSTORM_CORE_CONN_AG_CTX_CF0_MASK
value|0x3
comment|/* cf0 */
define|#
directive|define
name|E5_MSTORM_CORE_CONN_AG_CTX_CF0_SHIFT
value|2
define|#
directive|define
name|E5_MSTORM_CORE_CONN_AG_CTX_CF1_MASK
value|0x3
comment|/* cf1 */
define|#
directive|define
name|E5_MSTORM_CORE_CONN_AG_CTX_CF1_SHIFT
value|4
define|#
directive|define
name|E5_MSTORM_CORE_CONN_AG_CTX_CF2_MASK
value|0x3
comment|/* cf2 */
define|#
directive|define
name|E5_MSTORM_CORE_CONN_AG_CTX_CF2_SHIFT
value|6
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E5_MSTORM_CORE_CONN_AG_CTX_CF0EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E5_MSTORM_CORE_CONN_AG_CTX_CF0EN_SHIFT
value|0
define|#
directive|define
name|E5_MSTORM_CORE_CONN_AG_CTX_CF1EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E5_MSTORM_CORE_CONN_AG_CTX_CF1EN_SHIFT
value|1
define|#
directive|define
name|E5_MSTORM_CORE_CONN_AG_CTX_CF2EN_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E5_MSTORM_CORE_CONN_AG_CTX_CF2EN_SHIFT
value|2
define|#
directive|define
name|E5_MSTORM_CORE_CONN_AG_CTX_RULE0EN_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E5_MSTORM_CORE_CONN_AG_CTX_RULE0EN_SHIFT
value|3
define|#
directive|define
name|E5_MSTORM_CORE_CONN_AG_CTX_RULE1EN_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E5_MSTORM_CORE_CONN_AG_CTX_RULE1EN_SHIFT
value|4
define|#
directive|define
name|E5_MSTORM_CORE_CONN_AG_CTX_RULE2EN_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E5_MSTORM_CORE_CONN_AG_CTX_RULE2EN_SHIFT
value|5
define|#
directive|define
name|E5_MSTORM_CORE_CONN_AG_CTX_RULE3EN_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E5_MSTORM_CORE_CONN_AG_CTX_RULE3EN_SHIFT
value|6
define|#
directive|define
name|E5_MSTORM_CORE_CONN_AG_CTX_RULE4EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E5_MSTORM_CORE_CONN_AG_CTX_RULE4EN_SHIFT
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
name|e5_tstorm_core_conn_ag_ctx
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
name|E5_TSTORM_CORE_CONN_AG_CTX_BIT0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E5_TSTORM_CORE_CONN_AG_CTX_BIT0_SHIFT
value|0
define|#
directive|define
name|E5_TSTORM_CORE_CONN_AG_CTX_BIT1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E5_TSTORM_CORE_CONN_AG_CTX_BIT1_SHIFT
value|1
define|#
directive|define
name|E5_TSTORM_CORE_CONN_AG_CTX_BIT2_MASK
value|0x1
comment|/* bit2 */
define|#
directive|define
name|E5_TSTORM_CORE_CONN_AG_CTX_BIT2_SHIFT
value|2
define|#
directive|define
name|E5_TSTORM_CORE_CONN_AG_CTX_BIT3_MASK
value|0x1
comment|/* bit3 */
define|#
directive|define
name|E5_TSTORM_CORE_CONN_AG_CTX_BIT3_SHIFT
value|3
define|#
directive|define
name|E5_TSTORM_CORE_CONN_AG_CTX_BIT4_MASK
value|0x1
comment|/* bit4 */
define|#
directive|define
name|E5_TSTORM_CORE_CONN_AG_CTX_BIT4_SHIFT
value|4
define|#
directive|define
name|E5_TSTORM_CORE_CONN_AG_CTX_BIT5_MASK
value|0x1
comment|/* bit5 */
define|#
directive|define
name|E5_TSTORM_CORE_CONN_AG_CTX_BIT5_SHIFT
value|5
define|#
directive|define
name|E5_TSTORM_CORE_CONN_AG_CTX_CF0_MASK
value|0x3
comment|/* timer0cf */
define|#
directive|define
name|E5_TSTORM_CORE_CONN_AG_CTX_CF0_SHIFT
value|6
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E5_TSTORM_CORE_CONN_AG_CTX_CF1_MASK
value|0x3
comment|/* timer1cf */
define|#
directive|define
name|E5_TSTORM_CORE_CONN_AG_CTX_CF1_SHIFT
value|0
define|#
directive|define
name|E5_TSTORM_CORE_CONN_AG_CTX_CF2_MASK
value|0x3
comment|/* timer2cf */
define|#
directive|define
name|E5_TSTORM_CORE_CONN_AG_CTX_CF2_SHIFT
value|2
define|#
directive|define
name|E5_TSTORM_CORE_CONN_AG_CTX_CF3_MASK
value|0x3
comment|/* timer_stop_all */
define|#
directive|define
name|E5_TSTORM_CORE_CONN_AG_CTX_CF3_SHIFT
value|4
define|#
directive|define
name|E5_TSTORM_CORE_CONN_AG_CTX_CF4_MASK
value|0x3
comment|/* cf4 */
define|#
directive|define
name|E5_TSTORM_CORE_CONN_AG_CTX_CF4_SHIFT
value|6
name|u8
name|flags2
decl_stmt|;
define|#
directive|define
name|E5_TSTORM_CORE_CONN_AG_CTX_CF5_MASK
value|0x3
comment|/* cf5 */
define|#
directive|define
name|E5_TSTORM_CORE_CONN_AG_CTX_CF5_SHIFT
value|0
define|#
directive|define
name|E5_TSTORM_CORE_CONN_AG_CTX_CF6_MASK
value|0x3
comment|/* cf6 */
define|#
directive|define
name|E5_TSTORM_CORE_CONN_AG_CTX_CF6_SHIFT
value|2
define|#
directive|define
name|E5_TSTORM_CORE_CONN_AG_CTX_CF7_MASK
value|0x3
comment|/* cf7 */
define|#
directive|define
name|E5_TSTORM_CORE_CONN_AG_CTX_CF7_SHIFT
value|4
define|#
directive|define
name|E5_TSTORM_CORE_CONN_AG_CTX_CF8_MASK
value|0x3
comment|/* cf8 */
define|#
directive|define
name|E5_TSTORM_CORE_CONN_AG_CTX_CF8_SHIFT
value|6
name|u8
name|flags3
decl_stmt|;
define|#
directive|define
name|E5_TSTORM_CORE_CONN_AG_CTX_CF9_MASK
value|0x3
comment|/* cf9 */
define|#
directive|define
name|E5_TSTORM_CORE_CONN_AG_CTX_CF9_SHIFT
value|0
define|#
directive|define
name|E5_TSTORM_CORE_CONN_AG_CTX_CF10_MASK
value|0x3
comment|/* cf10 */
define|#
directive|define
name|E5_TSTORM_CORE_CONN_AG_CTX_CF10_SHIFT
value|2
define|#
directive|define
name|E5_TSTORM_CORE_CONN_AG_CTX_CF0EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E5_TSTORM_CORE_CONN_AG_CTX_CF0EN_SHIFT
value|4
define|#
directive|define
name|E5_TSTORM_CORE_CONN_AG_CTX_CF1EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E5_TSTORM_CORE_CONN_AG_CTX_CF1EN_SHIFT
value|5
define|#
directive|define
name|E5_TSTORM_CORE_CONN_AG_CTX_CF2EN_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E5_TSTORM_CORE_CONN_AG_CTX_CF2EN_SHIFT
value|6
define|#
directive|define
name|E5_TSTORM_CORE_CONN_AG_CTX_CF3EN_MASK
value|0x1
comment|/* cf3en */
define|#
directive|define
name|E5_TSTORM_CORE_CONN_AG_CTX_CF3EN_SHIFT
value|7
name|u8
name|flags4
decl_stmt|;
define|#
directive|define
name|E5_TSTORM_CORE_CONN_AG_CTX_CF4EN_MASK
value|0x1
comment|/* cf4en */
define|#
directive|define
name|E5_TSTORM_CORE_CONN_AG_CTX_CF4EN_SHIFT
value|0
define|#
directive|define
name|E5_TSTORM_CORE_CONN_AG_CTX_CF5EN_MASK
value|0x1
comment|/* cf5en */
define|#
directive|define
name|E5_TSTORM_CORE_CONN_AG_CTX_CF5EN_SHIFT
value|1
define|#
directive|define
name|E5_TSTORM_CORE_CONN_AG_CTX_CF6EN_MASK
value|0x1
comment|/* cf6en */
define|#
directive|define
name|E5_TSTORM_CORE_CONN_AG_CTX_CF6EN_SHIFT
value|2
define|#
directive|define
name|E5_TSTORM_CORE_CONN_AG_CTX_CF7EN_MASK
value|0x1
comment|/* cf7en */
define|#
directive|define
name|E5_TSTORM_CORE_CONN_AG_CTX_CF7EN_SHIFT
value|3
define|#
directive|define
name|E5_TSTORM_CORE_CONN_AG_CTX_CF8EN_MASK
value|0x1
comment|/* cf8en */
define|#
directive|define
name|E5_TSTORM_CORE_CONN_AG_CTX_CF8EN_SHIFT
value|4
define|#
directive|define
name|E5_TSTORM_CORE_CONN_AG_CTX_CF9EN_MASK
value|0x1
comment|/* cf9en */
define|#
directive|define
name|E5_TSTORM_CORE_CONN_AG_CTX_CF9EN_SHIFT
value|5
define|#
directive|define
name|E5_TSTORM_CORE_CONN_AG_CTX_CF10EN_MASK
value|0x1
comment|/* cf10en */
define|#
directive|define
name|E5_TSTORM_CORE_CONN_AG_CTX_CF10EN_SHIFT
value|6
define|#
directive|define
name|E5_TSTORM_CORE_CONN_AG_CTX_RULE0EN_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E5_TSTORM_CORE_CONN_AG_CTX_RULE0EN_SHIFT
value|7
name|u8
name|flags5
decl_stmt|;
define|#
directive|define
name|E5_TSTORM_CORE_CONN_AG_CTX_RULE1EN_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E5_TSTORM_CORE_CONN_AG_CTX_RULE1EN_SHIFT
value|0
define|#
directive|define
name|E5_TSTORM_CORE_CONN_AG_CTX_RULE2EN_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E5_TSTORM_CORE_CONN_AG_CTX_RULE2EN_SHIFT
value|1
define|#
directive|define
name|E5_TSTORM_CORE_CONN_AG_CTX_RULE3EN_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E5_TSTORM_CORE_CONN_AG_CTX_RULE3EN_SHIFT
value|2
define|#
directive|define
name|E5_TSTORM_CORE_CONN_AG_CTX_RULE4EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E5_TSTORM_CORE_CONN_AG_CTX_RULE4EN_SHIFT
value|3
define|#
directive|define
name|E5_TSTORM_CORE_CONN_AG_CTX_RULE5EN_MASK
value|0x1
comment|/* rule5en */
define|#
directive|define
name|E5_TSTORM_CORE_CONN_AG_CTX_RULE5EN_SHIFT
value|4
define|#
directive|define
name|E5_TSTORM_CORE_CONN_AG_CTX_RULE6EN_MASK
value|0x1
comment|/* rule6en */
define|#
directive|define
name|E5_TSTORM_CORE_CONN_AG_CTX_RULE6EN_SHIFT
value|5
define|#
directive|define
name|E5_TSTORM_CORE_CONN_AG_CTX_RULE7EN_MASK
value|0x1
comment|/* rule7en */
define|#
directive|define
name|E5_TSTORM_CORE_CONN_AG_CTX_RULE7EN_SHIFT
value|6
define|#
directive|define
name|E5_TSTORM_CORE_CONN_AG_CTX_RULE8EN_MASK
value|0x1
comment|/* rule8en */
define|#
directive|define
name|E5_TSTORM_CORE_CONN_AG_CTX_RULE8EN_SHIFT
value|7
name|u8
name|flags6
decl_stmt|;
define|#
directive|define
name|E5_TSTORM_CORE_CONN_AG_CTX_E4_RESERVED1_MASK
value|0x1
comment|/* bit6 */
define|#
directive|define
name|E5_TSTORM_CORE_CONN_AG_CTX_E4_RESERVED1_SHIFT
value|0
define|#
directive|define
name|E5_TSTORM_CORE_CONN_AG_CTX_E4_RESERVED2_MASK
value|0x1
comment|/* bit7 */
define|#
directive|define
name|E5_TSTORM_CORE_CONN_AG_CTX_E4_RESERVED2_SHIFT
value|1
define|#
directive|define
name|E5_TSTORM_CORE_CONN_AG_CTX_E4_RESERVED3_MASK
value|0x1
comment|/* bit8 */
define|#
directive|define
name|E5_TSTORM_CORE_CONN_AG_CTX_E4_RESERVED3_SHIFT
value|2
define|#
directive|define
name|E5_TSTORM_CORE_CONN_AG_CTX_E4_RESERVED4_MASK
value|0x3
comment|/* cf11 */
define|#
directive|define
name|E5_TSTORM_CORE_CONN_AG_CTX_E4_RESERVED4_SHIFT
value|3
define|#
directive|define
name|E5_TSTORM_CORE_CONN_AG_CTX_E4_RESERVED5_MASK
value|0x1
comment|/* cf11en */
define|#
directive|define
name|E5_TSTORM_CORE_CONN_AG_CTX_E4_RESERVED5_SHIFT
value|5
define|#
directive|define
name|E5_TSTORM_CORE_CONN_AG_CTX_E4_RESERVED6_MASK
value|0x1
comment|/* rule9en */
define|#
directive|define
name|E5_TSTORM_CORE_CONN_AG_CTX_E4_RESERVED6_SHIFT
value|6
define|#
directive|define
name|E5_TSTORM_CORE_CONN_AG_CTX_E4_RESERVED7_MASK
value|0x1
comment|/* rule10en */
define|#
directive|define
name|E5_TSTORM_CORE_CONN_AG_CTX_E4_RESERVED7_SHIFT
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
name|e5_ustorm_core_conn_ag_ctx
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
name|E5_USTORM_CORE_CONN_AG_CTX_BIT0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E5_USTORM_CORE_CONN_AG_CTX_BIT0_SHIFT
value|0
define|#
directive|define
name|E5_USTORM_CORE_CONN_AG_CTX_BIT1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E5_USTORM_CORE_CONN_AG_CTX_BIT1_SHIFT
value|1
define|#
directive|define
name|E5_USTORM_CORE_CONN_AG_CTX_CF0_MASK
value|0x3
comment|/* timer0cf */
define|#
directive|define
name|E5_USTORM_CORE_CONN_AG_CTX_CF0_SHIFT
value|2
define|#
directive|define
name|E5_USTORM_CORE_CONN_AG_CTX_CF1_MASK
value|0x3
comment|/* timer1cf */
define|#
directive|define
name|E5_USTORM_CORE_CONN_AG_CTX_CF1_SHIFT
value|4
define|#
directive|define
name|E5_USTORM_CORE_CONN_AG_CTX_CF2_MASK
value|0x3
comment|/* timer2cf */
define|#
directive|define
name|E5_USTORM_CORE_CONN_AG_CTX_CF2_SHIFT
value|6
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E5_USTORM_CORE_CONN_AG_CTX_CF3_MASK
value|0x3
comment|/* timer_stop_all */
define|#
directive|define
name|E5_USTORM_CORE_CONN_AG_CTX_CF3_SHIFT
value|0
define|#
directive|define
name|E5_USTORM_CORE_CONN_AG_CTX_CF4_MASK
value|0x3
comment|/* cf4 */
define|#
directive|define
name|E5_USTORM_CORE_CONN_AG_CTX_CF4_SHIFT
value|2
define|#
directive|define
name|E5_USTORM_CORE_CONN_AG_CTX_CF5_MASK
value|0x3
comment|/* cf5 */
define|#
directive|define
name|E5_USTORM_CORE_CONN_AG_CTX_CF5_SHIFT
value|4
define|#
directive|define
name|E5_USTORM_CORE_CONN_AG_CTX_CF6_MASK
value|0x3
comment|/* cf6 */
define|#
directive|define
name|E5_USTORM_CORE_CONN_AG_CTX_CF6_SHIFT
value|6
name|u8
name|flags2
decl_stmt|;
define|#
directive|define
name|E5_USTORM_CORE_CONN_AG_CTX_CF0EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E5_USTORM_CORE_CONN_AG_CTX_CF0EN_SHIFT
value|0
define|#
directive|define
name|E5_USTORM_CORE_CONN_AG_CTX_CF1EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E5_USTORM_CORE_CONN_AG_CTX_CF1EN_SHIFT
value|1
define|#
directive|define
name|E5_USTORM_CORE_CONN_AG_CTX_CF2EN_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E5_USTORM_CORE_CONN_AG_CTX_CF2EN_SHIFT
value|2
define|#
directive|define
name|E5_USTORM_CORE_CONN_AG_CTX_CF3EN_MASK
value|0x1
comment|/* cf3en */
define|#
directive|define
name|E5_USTORM_CORE_CONN_AG_CTX_CF3EN_SHIFT
value|3
define|#
directive|define
name|E5_USTORM_CORE_CONN_AG_CTX_CF4EN_MASK
value|0x1
comment|/* cf4en */
define|#
directive|define
name|E5_USTORM_CORE_CONN_AG_CTX_CF4EN_SHIFT
value|4
define|#
directive|define
name|E5_USTORM_CORE_CONN_AG_CTX_CF5EN_MASK
value|0x1
comment|/* cf5en */
define|#
directive|define
name|E5_USTORM_CORE_CONN_AG_CTX_CF5EN_SHIFT
value|5
define|#
directive|define
name|E5_USTORM_CORE_CONN_AG_CTX_CF6EN_MASK
value|0x1
comment|/* cf6en */
define|#
directive|define
name|E5_USTORM_CORE_CONN_AG_CTX_CF6EN_SHIFT
value|6
define|#
directive|define
name|E5_USTORM_CORE_CONN_AG_CTX_RULE0EN_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E5_USTORM_CORE_CONN_AG_CTX_RULE0EN_SHIFT
value|7
name|u8
name|flags3
decl_stmt|;
define|#
directive|define
name|E5_USTORM_CORE_CONN_AG_CTX_RULE1EN_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E5_USTORM_CORE_CONN_AG_CTX_RULE1EN_SHIFT
value|0
define|#
directive|define
name|E5_USTORM_CORE_CONN_AG_CTX_RULE2EN_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E5_USTORM_CORE_CONN_AG_CTX_RULE2EN_SHIFT
value|1
define|#
directive|define
name|E5_USTORM_CORE_CONN_AG_CTX_RULE3EN_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E5_USTORM_CORE_CONN_AG_CTX_RULE3EN_SHIFT
value|2
define|#
directive|define
name|E5_USTORM_CORE_CONN_AG_CTX_RULE4EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E5_USTORM_CORE_CONN_AG_CTX_RULE4EN_SHIFT
value|3
define|#
directive|define
name|E5_USTORM_CORE_CONN_AG_CTX_RULE5EN_MASK
value|0x1
comment|/* rule5en */
define|#
directive|define
name|E5_USTORM_CORE_CONN_AG_CTX_RULE5EN_SHIFT
value|4
define|#
directive|define
name|E5_USTORM_CORE_CONN_AG_CTX_RULE6EN_MASK
value|0x1
comment|/* rule6en */
define|#
directive|define
name|E5_USTORM_CORE_CONN_AG_CTX_RULE6EN_SHIFT
value|5
define|#
directive|define
name|E5_USTORM_CORE_CONN_AG_CTX_RULE7EN_MASK
value|0x1
comment|/* rule7en */
define|#
directive|define
name|E5_USTORM_CORE_CONN_AG_CTX_RULE7EN_SHIFT
value|6
define|#
directive|define
name|E5_USTORM_CORE_CONN_AG_CTX_RULE8EN_MASK
value|0x1
comment|/* rule8en */
define|#
directive|define
name|E5_USTORM_CORE_CONN_AG_CTX_RULE8EN_SHIFT
value|7
name|u8
name|flags4
decl_stmt|;
define|#
directive|define
name|E5_USTORM_CORE_CONN_AG_CTX_E4_RESERVED1_MASK
value|0x1
comment|/* bit2 */
define|#
directive|define
name|E5_USTORM_CORE_CONN_AG_CTX_E4_RESERVED1_SHIFT
value|0
define|#
directive|define
name|E5_USTORM_CORE_CONN_AG_CTX_E4_RESERVED2_MASK
value|0x1
comment|/* bit3 */
define|#
directive|define
name|E5_USTORM_CORE_CONN_AG_CTX_E4_RESERVED2_SHIFT
value|1
define|#
directive|define
name|E5_USTORM_CORE_CONN_AG_CTX_E4_RESERVED3_MASK
value|0x3
comment|/* cf7 */
define|#
directive|define
name|E5_USTORM_CORE_CONN_AG_CTX_E4_RESERVED3_SHIFT
value|2
define|#
directive|define
name|E5_USTORM_CORE_CONN_AG_CTX_E4_RESERVED4_MASK
value|0x3
comment|/* cf8 */
define|#
directive|define
name|E5_USTORM_CORE_CONN_AG_CTX_E4_RESERVED4_SHIFT
value|4
define|#
directive|define
name|E5_USTORM_CORE_CONN_AG_CTX_E4_RESERVED5_MASK
value|0x1
comment|/* cf7en */
define|#
directive|define
name|E5_USTORM_CORE_CONN_AG_CTX_E4_RESERVED5_SHIFT
value|6
define|#
directive|define
name|E5_USTORM_CORE_CONN_AG_CTX_E4_RESERVED6_MASK
value|0x1
comment|/* cf8en */
define|#
directive|define
name|E5_USTORM_CORE_CONN_AG_CTX_E4_RESERVED6_SHIFT
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
name|rx_producers
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
name|e5_xstorm_core_conn_ag_ctx
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
name|E5_XSTORM_CORE_CONN_AG_CTX_EXIST_IN_QM0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_EXIST_IN_QM0_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_RESERVED1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_RESERVED1_SHIFT
value|1
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_RESERVED2_MASK
value|0x1
comment|/* exist_in_qm2 */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_RESERVED2_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_EXIST_IN_QM3_MASK
value|0x1
comment|/* exist_in_qm3 */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_EXIST_IN_QM3_SHIFT
value|3
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_RESERVED3_MASK
value|0x1
comment|/* bit4 */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_RESERVED3_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_RESERVED4_MASK
value|0x1
comment|/* cf_array_active */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_RESERVED4_SHIFT
value|5
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_RESERVED5_MASK
value|0x1
comment|/* bit6 */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_RESERVED5_SHIFT
value|6
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_RESERVED6_MASK
value|0x1
comment|/* bit7 */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_RESERVED6_SHIFT
value|7
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_RESERVED7_MASK
value|0x1
comment|/* bit8 */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_RESERVED7_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_RESERVED8_MASK
value|0x1
comment|/* bit9 */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_RESERVED8_SHIFT
value|1
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_RESERVED9_MASK
value|0x1
comment|/* bit10 */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_RESERVED9_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_BIT11_MASK
value|0x1
comment|/* bit11 */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_BIT11_SHIFT
value|3
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_BIT12_MASK
value|0x1
comment|/* bit12 */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_BIT12_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_BIT13_MASK
value|0x1
comment|/* bit13 */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_BIT13_SHIFT
value|5
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_TX_RULE_ACTIVE_MASK
value|0x1
comment|/* bit14 */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_TX_RULE_ACTIVE_SHIFT
value|6
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_DQ_CF_ACTIVE_MASK
value|0x1
comment|/* bit15 */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_DQ_CF_ACTIVE_SHIFT
value|7
name|u8
name|flags2
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_CF0_MASK
value|0x3
comment|/* timer0cf */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_CF0_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_CF1_MASK
value|0x3
comment|/* timer1cf */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_CF1_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_CF2_MASK
value|0x3
comment|/* timer2cf */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_CF2_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_CF3_MASK
value|0x3
comment|/* timer_stop_all */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_CF3_SHIFT
value|6
name|u8
name|flags3
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_CF4_MASK
value|0x3
comment|/* cf4 */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_CF4_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_CF5_MASK
value|0x3
comment|/* cf5 */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_CF5_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_CF6_MASK
value|0x3
comment|/* cf6 */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_CF6_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_CF7_MASK
value|0x3
comment|/* cf7 */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_CF7_SHIFT
value|6
name|u8
name|flags4
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_CF8_MASK
value|0x3
comment|/* cf8 */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_CF8_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_CF9_MASK
value|0x3
comment|/* cf9 */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_CF9_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_CF10_MASK
value|0x3
comment|/* cf10 */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_CF10_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_CF11_MASK
value|0x3
comment|/* cf11 */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_CF11_SHIFT
value|6
name|u8
name|flags5
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_CF12_MASK
value|0x3
comment|/* cf12 */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_CF12_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_CF13_MASK
value|0x3
comment|/* cf13 */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_CF13_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_CF14_MASK
value|0x3
comment|/* cf14 */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_CF14_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_CF15_MASK
value|0x3
comment|/* cf15 */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_CF15_SHIFT
value|6
name|u8
name|flags6
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_CONSOLID_PROD_CF_MASK
value|0x3
comment|/* cf16 */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_CONSOLID_PROD_CF_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_CF17_MASK
value|0x3
comment|/* cf_array_cf */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_CF17_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_DQ_CF_MASK
value|0x3
comment|/* cf18 */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_DQ_CF_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_TERMINATE_CF_MASK
value|0x3
comment|/* cf19 */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_TERMINATE_CF_SHIFT
value|6
name|u8
name|flags7
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_FLUSH_Q0_MASK
value|0x3
comment|/* cf20 */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_FLUSH_Q0_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_RESERVED10_MASK
value|0x3
comment|/* cf21 */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_RESERVED10_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_SLOW_PATH_MASK
value|0x3
comment|/* cf22 */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_SLOW_PATH_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_CF0EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_CF0EN_SHIFT
value|6
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_CF1EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_CF1EN_SHIFT
value|7
name|u8
name|flags8
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_CF2EN_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_CF2EN_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_CF3EN_MASK
value|0x1
comment|/* cf3en */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_CF3EN_SHIFT
value|1
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_CF4EN_MASK
value|0x1
comment|/* cf4en */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_CF4EN_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_CF5EN_MASK
value|0x1
comment|/* cf5en */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_CF5EN_SHIFT
value|3
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_CF6EN_MASK
value|0x1
comment|/* cf6en */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_CF6EN_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_CF7EN_MASK
value|0x1
comment|/* cf7en */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_CF7EN_SHIFT
value|5
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_CF8EN_MASK
value|0x1
comment|/* cf8en */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_CF8EN_SHIFT
value|6
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_CF9EN_MASK
value|0x1
comment|/* cf9en */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_CF9EN_SHIFT
value|7
name|u8
name|flags9
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_CF10EN_MASK
value|0x1
comment|/* cf10en */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_CF10EN_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_CF11EN_MASK
value|0x1
comment|/* cf11en */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_CF11EN_SHIFT
value|1
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_CF12EN_MASK
value|0x1
comment|/* cf12en */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_CF12EN_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_CF13EN_MASK
value|0x1
comment|/* cf13en */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_CF13EN_SHIFT
value|3
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_CF14EN_MASK
value|0x1
comment|/* cf14en */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_CF14EN_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_CF15EN_MASK
value|0x1
comment|/* cf15en */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_CF15EN_SHIFT
value|5
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_CONSOLID_PROD_CF_EN_MASK
value|0x1
comment|/* cf16en */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_CONSOLID_PROD_CF_EN_SHIFT
value|6
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_CF17EN_MASK
value|0x1
comment|/* cf_array_cf_en */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_CF17EN_SHIFT
value|7
name|u8
name|flags10
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_DQ_CF_EN_MASK
value|0x1
comment|/* cf18en */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_DQ_CF_EN_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_TERMINATE_CF_EN_MASK
value|0x1
comment|/* cf19en */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_TERMINATE_CF_EN_SHIFT
value|1
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_FLUSH_Q0_EN_MASK
value|0x1
comment|/* cf20en */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_FLUSH_Q0_EN_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_RESERVED11_MASK
value|0x1
comment|/* cf21en */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_RESERVED11_SHIFT
value|3
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_SLOW_PATH_EN_MASK
value|0x1
comment|/* cf22en */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_SLOW_PATH_EN_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_CF23EN_MASK
value|0x1
comment|/* cf23en */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_CF23EN_SHIFT
value|5
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_RESERVED12_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_RESERVED12_SHIFT
value|6
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_RESERVED13_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_RESERVED13_SHIFT
value|7
name|u8
name|flags11
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_RESERVED14_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_RESERVED14_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_RESERVED15_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_RESERVED15_SHIFT
value|1
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_TX_DEC_RULE_EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_TX_DEC_RULE_EN_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_RULE5EN_MASK
value|0x1
comment|/* rule5en */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_RULE5EN_SHIFT
value|3
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_RULE6EN_MASK
value|0x1
comment|/* rule6en */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_RULE6EN_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_RULE7EN_MASK
value|0x1
comment|/* rule7en */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_RULE7EN_SHIFT
value|5
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_A0_RESERVED1_MASK
value|0x1
comment|/* rule8en */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_A0_RESERVED1_SHIFT
value|6
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_RULE9EN_MASK
value|0x1
comment|/* rule9en */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_RULE9EN_SHIFT
value|7
name|u8
name|flags12
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_RULE10EN_MASK
value|0x1
comment|/* rule10en */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_RULE10EN_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_RULE11EN_MASK
value|0x1
comment|/* rule11en */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_RULE11EN_SHIFT
value|1
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_A0_RESERVED2_MASK
value|0x1
comment|/* rule12en */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_A0_RESERVED2_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_A0_RESERVED3_MASK
value|0x1
comment|/* rule13en */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_A0_RESERVED3_SHIFT
value|3
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_RULE14EN_MASK
value|0x1
comment|/* rule14en */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_RULE14EN_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_RULE15EN_MASK
value|0x1
comment|/* rule15en */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_RULE15EN_SHIFT
value|5
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_RULE16EN_MASK
value|0x1
comment|/* rule16en */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_RULE16EN_SHIFT
value|6
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_RULE17EN_MASK
value|0x1
comment|/* rule17en */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_RULE17EN_SHIFT
value|7
name|u8
name|flags13
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_RULE18EN_MASK
value|0x1
comment|/* rule18en */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_RULE18EN_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_RULE19EN_MASK
value|0x1
comment|/* rule19en */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_RULE19EN_SHIFT
value|1
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_A0_RESERVED4_MASK
value|0x1
comment|/* rule20en */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_A0_RESERVED4_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_A0_RESERVED5_MASK
value|0x1
comment|/* rule21en */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_A0_RESERVED5_SHIFT
value|3
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_A0_RESERVED6_MASK
value|0x1
comment|/* rule22en */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_A0_RESERVED6_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_A0_RESERVED7_MASK
value|0x1
comment|/* rule23en */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_A0_RESERVED7_SHIFT
value|5
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_A0_RESERVED8_MASK
value|0x1
comment|/* rule24en */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_A0_RESERVED8_SHIFT
value|6
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_A0_RESERVED9_MASK
value|0x1
comment|/* rule25en */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_A0_RESERVED9_SHIFT
value|7
name|u8
name|flags14
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_BIT16_MASK
value|0x1
comment|/* bit16 */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_BIT16_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_BIT17_MASK
value|0x1
comment|/* bit17 */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_BIT17_SHIFT
value|1
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_BIT18_MASK
value|0x1
comment|/* bit18 */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_BIT18_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_BIT19_MASK
value|0x1
comment|/* bit19 */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_BIT19_SHIFT
value|3
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_BIT20_MASK
value|0x1
comment|/* bit20 */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_BIT20_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_BIT21_MASK
value|0x1
comment|/* bit21 */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_BIT21_SHIFT
value|5
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_CF23_MASK
value|0x3
comment|/* cf23 */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_CF23_SHIFT
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
name|consolid_prod
comment|/* physical_q1 */
decl_stmt|;
name|__le16
name|reserved16
comment|/* physical_q2 */
decl_stmt|;
name|__le16
name|tx_bd_cons
comment|/* word3 */
decl_stmt|;
name|__le16
name|tx_bd_or_spq_prod
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
name|E5_XSTORM_CORE_CONN_AG_CTX_E4_RESERVED1_MASK
value|0x1
comment|/* bit22 */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_E4_RESERVED1_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_E4_RESERVED2_MASK
value|0x1
comment|/* bit23 */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_E4_RESERVED2_SHIFT
value|1
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_E4_RESERVED3_MASK
value|0x1
comment|/* bit24 */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_E4_RESERVED3_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_E4_RESERVED4_MASK
value|0x3
comment|/* cf24 */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_E4_RESERVED4_SHIFT
value|3
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_E4_RESERVED5_MASK
value|0x1
comment|/* cf24en */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_E4_RESERVED5_SHIFT
value|5
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_E4_RESERVED6_MASK
value|0x1
comment|/* rule26en */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_E4_RESERVED6_SHIFT
value|6
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_E4_RESERVED7_MASK
value|0x1
comment|/* rule27en */
define|#
directive|define
name|E5_XSTORM_CORE_CONN_AG_CTX_E4_RESERVED7_SHIFT
value|7
name|u8
name|byte7
comment|/* byte7 */
decl_stmt|;
name|__le16
name|word7
comment|/* word7 */
decl_stmt|;
name|__le16
name|word8
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
name|__le32
name|reg8
comment|/* reg8 */
decl_stmt|;
name|__le32
name|reg9
comment|/* reg9 */
decl_stmt|;
name|u8
name|byte8
comment|/* byte8 */
decl_stmt|;
name|u8
name|byte9
comment|/* byte9 */
decl_stmt|;
name|u8
name|byte10
comment|/* byte10 */
decl_stmt|;
name|u8
name|byte11
comment|/* byte11 */
decl_stmt|;
name|u8
name|byte12
comment|/* byte12 */
decl_stmt|;
name|u8
name|byte13
comment|/* byte13 */
decl_stmt|;
name|u8
name|byte14
comment|/* byte14 */
decl_stmt|;
name|u8
name|byte15
comment|/* byte15 */
decl_stmt|;
name|__le32
name|reg10
comment|/* reg10 */
decl_stmt|;
name|__le32
name|reg11
comment|/* reg11 */
decl_stmt|;
name|__le32
name|reg12
comment|/* reg12 */
decl_stmt|;
name|__le32
name|reg13
comment|/* reg13 */
decl_stmt|;
name|__le32
name|reg14
comment|/* reg14 */
decl_stmt|;
name|__le32
name|reg15
comment|/* reg15 */
decl_stmt|;
name|__le32
name|reg16
comment|/* reg16 */
decl_stmt|;
name|__le32
name|reg17
comment|/* reg17 */
decl_stmt|;
name|__le32
name|reg18
comment|/* reg18 */
decl_stmt|;
name|__le32
name|reg19
comment|/* reg19 */
decl_stmt|;
name|__le16
name|word12
comment|/* word12 */
decl_stmt|;
name|__le16
name|word13
comment|/* word13 */
decl_stmt|;
name|__le16
name|word14
comment|/* word14 */
decl_stmt|;
name|__le16
name|word15
comment|/* word15 */
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|e5_ystorm_core_conn_ag_ctx
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
name|E5_YSTORM_CORE_CONN_AG_CTX_BIT0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E5_YSTORM_CORE_CONN_AG_CTX_BIT0_SHIFT
value|0
define|#
directive|define
name|E5_YSTORM_CORE_CONN_AG_CTX_BIT1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E5_YSTORM_CORE_CONN_AG_CTX_BIT1_SHIFT
value|1
define|#
directive|define
name|E5_YSTORM_CORE_CONN_AG_CTX_CF0_MASK
value|0x3
comment|/* cf0 */
define|#
directive|define
name|E5_YSTORM_CORE_CONN_AG_CTX_CF0_SHIFT
value|2
define|#
directive|define
name|E5_YSTORM_CORE_CONN_AG_CTX_CF1_MASK
value|0x3
comment|/* cf1 */
define|#
directive|define
name|E5_YSTORM_CORE_CONN_AG_CTX_CF1_SHIFT
value|4
define|#
directive|define
name|E5_YSTORM_CORE_CONN_AG_CTX_CF2_MASK
value|0x3
comment|/* cf2 */
define|#
directive|define
name|E5_YSTORM_CORE_CONN_AG_CTX_CF2_SHIFT
value|6
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E5_YSTORM_CORE_CONN_AG_CTX_CF0EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E5_YSTORM_CORE_CONN_AG_CTX_CF0EN_SHIFT
value|0
define|#
directive|define
name|E5_YSTORM_CORE_CONN_AG_CTX_CF1EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E5_YSTORM_CORE_CONN_AG_CTX_CF1EN_SHIFT
value|1
define|#
directive|define
name|E5_YSTORM_CORE_CONN_AG_CTX_CF2EN_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E5_YSTORM_CORE_CONN_AG_CTX_CF2EN_SHIFT
value|2
define|#
directive|define
name|E5_YSTORM_CORE_CONN_AG_CTX_RULE0EN_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E5_YSTORM_CORE_CONN_AG_CTX_RULE0EN_SHIFT
value|3
define|#
directive|define
name|E5_YSTORM_CORE_CONN_AG_CTX_RULE1EN_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E5_YSTORM_CORE_CONN_AG_CTX_RULE1EN_SHIFT
value|4
define|#
directive|define
name|E5_YSTORM_CORE_CONN_AG_CTX_RULE2EN_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E5_YSTORM_CORE_CONN_AG_CTX_RULE2EN_SHIFT
value|5
define|#
directive|define
name|E5_YSTORM_CORE_CONN_AG_CTX_RULE3EN_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E5_YSTORM_CORE_CONN_AG_CTX_RULE3EN_SHIFT
value|6
define|#
directive|define
name|E5_YSTORM_CORE_CONN_AG_CTX_RULE4EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E5_YSTORM_CORE_CONN_AG_CTX_RULE4EN_SHIFT
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

begin_comment
comment|/*  * IGU cleanup command  */
end_comment

begin_struct
struct|struct
name|igu_cleanup
block|{
name|__le32
name|sb_id_and_flags
decl_stmt|;
define|#
directive|define
name|IGU_CLEANUP_RESERVED0_MASK
value|0x7FFFFFF
define|#
directive|define
name|IGU_CLEANUP_RESERVED0_SHIFT
value|0
define|#
directive|define
name|IGU_CLEANUP_CLEANUP_SET_MASK
value|0x1
comment|/* cleanup clear - 0, set - 1 */
define|#
directive|define
name|IGU_CLEANUP_CLEANUP_SET_SHIFT
value|27
define|#
directive|define
name|IGU_CLEANUP_CLEANUP_TYPE_MASK
value|0x7
define|#
directive|define
name|IGU_CLEANUP_CLEANUP_TYPE_SHIFT
value|28
define|#
directive|define
name|IGU_CLEANUP_COMMAND_TYPE_MASK
value|0x1
comment|/* must always be set (use enum command_type_bit) */
define|#
directive|define
name|IGU_CLEANUP_COMMAND_TYPE_SHIFT
value|31
name|__le32
name|reserved1
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * IGU firmware driver command  */
end_comment

begin_union
union|union
name|igu_command
block|{
name|struct
name|igu_prod_cons_update
name|prod_cons_update
decl_stmt|;
name|struct
name|igu_cleanup
name|cleanup
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/*  * IGU firmware driver command  */
end_comment

begin_struct
struct|struct
name|igu_command_reg_ctrl
block|{
name|__le16
name|opaque_fid
decl_stmt|;
name|__le16
name|igu_command_reg_ctrl_fields
decl_stmt|;
define|#
directive|define
name|IGU_COMMAND_REG_CTRL_PXP_BAR_ADDR_MASK
value|0xFFF
define|#
directive|define
name|IGU_COMMAND_REG_CTRL_PXP_BAR_ADDR_SHIFT
value|0
define|#
directive|define
name|IGU_COMMAND_REG_CTRL_RESERVED_MASK
value|0x7
define|#
directive|define
name|IGU_COMMAND_REG_CTRL_RESERVED_SHIFT
value|12
define|#
directive|define
name|IGU_COMMAND_REG_CTRL_COMMAND_TYPE_MASK
value|0x1
comment|/* command typ: 0 - read, 1 - write */
define|#
directive|define
name|IGU_COMMAND_REG_CTRL_COMMAND_TYPE_SHIFT
value|15
block|}
struct|;
end_struct

begin_comment
comment|/*  * IGU mapping line structure  */
end_comment

begin_struct
struct|struct
name|igu_mapping_line
block|{
name|__le32
name|igu_mapping_line_fields
decl_stmt|;
define|#
directive|define
name|IGU_MAPPING_LINE_VALID_MASK
value|0x1
define|#
directive|define
name|IGU_MAPPING_LINE_VALID_SHIFT
value|0
define|#
directive|define
name|IGU_MAPPING_LINE_VECTOR_NUMBER_MASK
value|0xFF
define|#
directive|define
name|IGU_MAPPING_LINE_VECTOR_NUMBER_SHIFT
value|1
define|#
directive|define
name|IGU_MAPPING_LINE_FUNCTION_NUMBER_MASK
value|0xFF
comment|/* In BB: VF-0-120, PF-0-7; In K2: VF-0-191, PF-0-15 */
define|#
directive|define
name|IGU_MAPPING_LINE_FUNCTION_NUMBER_SHIFT
value|9
define|#
directive|define
name|IGU_MAPPING_LINE_PF_VALID_MASK
value|0x1
comment|/* PF-1, VF-0 */
define|#
directive|define
name|IGU_MAPPING_LINE_PF_VALID_SHIFT
value|17
define|#
directive|define
name|IGU_MAPPING_LINE_IPS_GROUP_MASK
value|0x3F
define|#
directive|define
name|IGU_MAPPING_LINE_IPS_GROUP_SHIFT
value|18
define|#
directive|define
name|IGU_MAPPING_LINE_RESERVED_MASK
value|0xFF
define|#
directive|define
name|IGU_MAPPING_LINE_RESERVED_SHIFT
value|24
block|}
struct|;
end_struct

begin_comment
comment|/*  * IGU MSIX line structure  */
end_comment

begin_struct
struct|struct
name|igu_msix_vector
block|{
name|struct
name|regpair
name|address
decl_stmt|;
name|__le32
name|data
decl_stmt|;
name|__le32
name|msix_vector_fields
decl_stmt|;
define|#
directive|define
name|IGU_MSIX_VECTOR_MASK_BIT_MASK
value|0x1
define|#
directive|define
name|IGU_MSIX_VECTOR_MASK_BIT_SHIFT
value|0
define|#
directive|define
name|IGU_MSIX_VECTOR_RESERVED0_MASK
value|0x7FFF
define|#
directive|define
name|IGU_MSIX_VECTOR_RESERVED0_SHIFT
value|1
define|#
directive|define
name|IGU_MSIX_VECTOR_STEERING_TAG_MASK
value|0xFF
define|#
directive|define
name|IGU_MSIX_VECTOR_STEERING_TAG_SHIFT
value|16
define|#
directive|define
name|IGU_MSIX_VECTOR_RESERVED1_MASK
value|0xFF
define|#
directive|define
name|IGU_MSIX_VECTOR_RESERVED1_SHIFT
value|24
block|}
struct|;
end_struct

begin_comment
comment|/*  * per encapsulation type enabling flags  */
end_comment

begin_struct
struct|struct
name|prs_reg_encapsulation_type_en
block|{
name|u8
name|flags
decl_stmt|;
define|#
directive|define
name|PRS_REG_ENCAPSULATION_TYPE_EN_ETH_OVER_GRE_ENABLE_MASK
value|0x1
comment|/* Enable bit for Ethernet-over-GRE (L2 GRE) encapsulation. */
define|#
directive|define
name|PRS_REG_ENCAPSULATION_TYPE_EN_ETH_OVER_GRE_ENABLE_SHIFT
value|0
define|#
directive|define
name|PRS_REG_ENCAPSULATION_TYPE_EN_IP_OVER_GRE_ENABLE_MASK
value|0x1
comment|/* Enable bit for IP-over-GRE (IP GRE) encapsulation. */
define|#
directive|define
name|PRS_REG_ENCAPSULATION_TYPE_EN_IP_OVER_GRE_ENABLE_SHIFT
value|1
define|#
directive|define
name|PRS_REG_ENCAPSULATION_TYPE_EN_VXLAN_ENABLE_MASK
value|0x1
comment|/* Enable bit for VXLAN encapsulation. */
define|#
directive|define
name|PRS_REG_ENCAPSULATION_TYPE_EN_VXLAN_ENABLE_SHIFT
value|2
define|#
directive|define
name|PRS_REG_ENCAPSULATION_TYPE_EN_T_TAG_ENABLE_MASK
value|0x1
comment|/* Enable bit for T-Tag encapsulation. */
define|#
directive|define
name|PRS_REG_ENCAPSULATION_TYPE_EN_T_TAG_ENABLE_SHIFT
value|3
define|#
directive|define
name|PRS_REG_ENCAPSULATION_TYPE_EN_ETH_OVER_GENEVE_ENABLE_MASK
value|0x1
comment|/* Enable bit for Ethernet-over-GENEVE (L2 GENEVE) encapsulation. */
define|#
directive|define
name|PRS_REG_ENCAPSULATION_TYPE_EN_ETH_OVER_GENEVE_ENABLE_SHIFT
value|4
define|#
directive|define
name|PRS_REG_ENCAPSULATION_TYPE_EN_IP_OVER_GENEVE_ENABLE_MASK
value|0x1
comment|/* Enable bit for IP-over-GENEVE (IP GENEVE) encapsulation. */
define|#
directive|define
name|PRS_REG_ENCAPSULATION_TYPE_EN_IP_OVER_GENEVE_ENABLE_SHIFT
value|5
define|#
directive|define
name|PRS_REG_ENCAPSULATION_TYPE_EN_RESERVED_MASK
value|0x3
define|#
directive|define
name|PRS_REG_ENCAPSULATION_TYPE_EN_RESERVED_SHIFT
value|6
block|}
struct|;
end_struct

begin_enum
enum|enum
name|pxp_tph_st_hint
block|{
name|TPH_ST_HINT_BIDIR
comment|/* Read/Write access by Host and Device */
block|,
name|TPH_ST_HINT_REQUESTER
comment|/* Read/Write access by Device */
block|,
name|TPH_ST_HINT_TARGET
comment|/* Device Write and Host Read, or Host Write and Device Read */
block|,
name|TPH_ST_HINT_TARGET_PRIO
comment|/* Device Write and Host Read, or Host Write and Device Read - with temporal reuse */
block|,
name|MAX_PXP_TPH_ST_HINT
block|}
enum|;
end_enum

begin_comment
comment|/*  * QM hardware structure of enable bypass credit mask  */
end_comment

begin_struct
struct|struct
name|qm_rf_bypass_mask
block|{
name|u8
name|flags
decl_stmt|;
define|#
directive|define
name|QM_RF_BYPASS_MASK_LINEVOQ_MASK
value|0x1
define|#
directive|define
name|QM_RF_BYPASS_MASK_LINEVOQ_SHIFT
value|0
define|#
directive|define
name|QM_RF_BYPASS_MASK_RESERVED0_MASK
value|0x1
define|#
directive|define
name|QM_RF_BYPASS_MASK_RESERVED0_SHIFT
value|1
define|#
directive|define
name|QM_RF_BYPASS_MASK_PFWFQ_MASK
value|0x1
define|#
directive|define
name|QM_RF_BYPASS_MASK_PFWFQ_SHIFT
value|2
define|#
directive|define
name|QM_RF_BYPASS_MASK_VPWFQ_MASK
value|0x1
define|#
directive|define
name|QM_RF_BYPASS_MASK_VPWFQ_SHIFT
value|3
define|#
directive|define
name|QM_RF_BYPASS_MASK_PFRL_MASK
value|0x1
define|#
directive|define
name|QM_RF_BYPASS_MASK_PFRL_SHIFT
value|4
define|#
directive|define
name|QM_RF_BYPASS_MASK_VPQCNRL_MASK
value|0x1
define|#
directive|define
name|QM_RF_BYPASS_MASK_VPQCNRL_SHIFT
value|5
define|#
directive|define
name|QM_RF_BYPASS_MASK_FWPAUSE_MASK
value|0x1
define|#
directive|define
name|QM_RF_BYPASS_MASK_FWPAUSE_SHIFT
value|6
define|#
directive|define
name|QM_RF_BYPASS_MASK_RESERVED1_MASK
value|0x1
define|#
directive|define
name|QM_RF_BYPASS_MASK_RESERVED1_SHIFT
value|7
block|}
struct|;
end_struct

begin_comment
comment|/*  * QM hardware structure of opportunistic credit mask  */
end_comment

begin_struct
struct|struct
name|qm_rf_opportunistic_mask
block|{
name|__le16
name|flags
decl_stmt|;
define|#
directive|define
name|QM_RF_OPPORTUNISTIC_MASK_LINEVOQ_MASK
value|0x1
define|#
directive|define
name|QM_RF_OPPORTUNISTIC_MASK_LINEVOQ_SHIFT
value|0
define|#
directive|define
name|QM_RF_OPPORTUNISTIC_MASK_BYTEVOQ_MASK
value|0x1
define|#
directive|define
name|QM_RF_OPPORTUNISTIC_MASK_BYTEVOQ_SHIFT
value|1
define|#
directive|define
name|QM_RF_OPPORTUNISTIC_MASK_PFWFQ_MASK
value|0x1
define|#
directive|define
name|QM_RF_OPPORTUNISTIC_MASK_PFWFQ_SHIFT
value|2
define|#
directive|define
name|QM_RF_OPPORTUNISTIC_MASK_VPWFQ_MASK
value|0x1
define|#
directive|define
name|QM_RF_OPPORTUNISTIC_MASK_VPWFQ_SHIFT
value|3
define|#
directive|define
name|QM_RF_OPPORTUNISTIC_MASK_PFRL_MASK
value|0x1
define|#
directive|define
name|QM_RF_OPPORTUNISTIC_MASK_PFRL_SHIFT
value|4
define|#
directive|define
name|QM_RF_OPPORTUNISTIC_MASK_VPQCNRL_MASK
value|0x1
define|#
directive|define
name|QM_RF_OPPORTUNISTIC_MASK_VPQCNRL_SHIFT
value|5
define|#
directive|define
name|QM_RF_OPPORTUNISTIC_MASK_FWPAUSE_MASK
value|0x1
define|#
directive|define
name|QM_RF_OPPORTUNISTIC_MASK_FWPAUSE_SHIFT
value|6
define|#
directive|define
name|QM_RF_OPPORTUNISTIC_MASK_RESERVED0_MASK
value|0x1
define|#
directive|define
name|QM_RF_OPPORTUNISTIC_MASK_RESERVED0_SHIFT
value|7
define|#
directive|define
name|QM_RF_OPPORTUNISTIC_MASK_QUEUEEMPTY_MASK
value|0x1
define|#
directive|define
name|QM_RF_OPPORTUNISTIC_MASK_QUEUEEMPTY_SHIFT
value|8
define|#
directive|define
name|QM_RF_OPPORTUNISTIC_MASK_RESERVED1_MASK
value|0x7F
define|#
directive|define
name|QM_RF_OPPORTUNISTIC_MASK_RESERVED1_SHIFT
value|9
block|}
struct|;
end_struct

begin_comment
comment|/*  * QM hardware structure of QM map memory  */
end_comment

begin_struct
struct|struct
name|qm_rf_pq_map
block|{
name|__le32
name|reg
decl_stmt|;
define|#
directive|define
name|QM_RF_PQ_MAP_PQ_VALID_MASK
value|0x1
comment|/* PQ active */
define|#
directive|define
name|QM_RF_PQ_MAP_PQ_VALID_SHIFT
value|0
define|#
directive|define
name|QM_RF_PQ_MAP_RL_ID_MASK
value|0xFF
comment|/* RL ID */
define|#
directive|define
name|QM_RF_PQ_MAP_RL_ID_SHIFT
value|1
define|#
directive|define
name|QM_RF_PQ_MAP_VP_PQ_ID_MASK
value|0x1FF
comment|/* the first PQ associated with the VPORT and VOQ of this PQ */
define|#
directive|define
name|QM_RF_PQ_MAP_VP_PQ_ID_SHIFT
value|9
define|#
directive|define
name|QM_RF_PQ_MAP_VOQ_MASK
value|0x1F
comment|/* VOQ */
define|#
directive|define
name|QM_RF_PQ_MAP_VOQ_SHIFT
value|18
define|#
directive|define
name|QM_RF_PQ_MAP_WRR_WEIGHT_GROUP_MASK
value|0x3
comment|/* WRR weight */
define|#
directive|define
name|QM_RF_PQ_MAP_WRR_WEIGHT_GROUP_SHIFT
value|23
define|#
directive|define
name|QM_RF_PQ_MAP_RL_VALID_MASK
value|0x1
comment|/* RL active */
define|#
directive|define
name|QM_RF_PQ_MAP_RL_VALID_SHIFT
value|25
define|#
directive|define
name|QM_RF_PQ_MAP_RESERVED_MASK
value|0x3F
define|#
directive|define
name|QM_RF_PQ_MAP_RESERVED_SHIFT
value|26
block|}
struct|;
end_struct

begin_comment
comment|/*  * Completion params for aggregated interrupt completion  */
end_comment

begin_struct
struct|struct
name|sdm_agg_int_comp_params
block|{
name|__le16
name|params
decl_stmt|;
define|#
directive|define
name|SDM_AGG_INT_COMP_PARAMS_AGG_INT_INDEX_MASK
value|0x3F
comment|/* the number of aggregated interrupt, 0-31 */
define|#
directive|define
name|SDM_AGG_INT_COMP_PARAMS_AGG_INT_INDEX_SHIFT
value|0
define|#
directive|define
name|SDM_AGG_INT_COMP_PARAMS_AGG_VECTOR_ENABLE_MASK
value|0x1
comment|/* 1 - set a bit in aggregated vector, 0 - dont set */
define|#
directive|define
name|SDM_AGG_INT_COMP_PARAMS_AGG_VECTOR_ENABLE_SHIFT
value|6
define|#
directive|define
name|SDM_AGG_INT_COMP_PARAMS_AGG_VECTOR_BIT_MASK
value|0x1FF
comment|/* Number of bit in the aggregated vector, 0-279 (TBD) */
define|#
directive|define
name|SDM_AGG_INT_COMP_PARAMS_AGG_VECTOR_BIT_SHIFT
value|7
block|}
struct|;
end_struct

begin_comment
comment|/*  * SDM operation gen command (generate aggregative interrupt)  */
end_comment

begin_struct
struct|struct
name|sdm_op_gen
block|{
name|__le32
name|command
decl_stmt|;
define|#
directive|define
name|SDM_OP_GEN_COMP_PARAM_MASK
value|0xFFFF
comment|/* completion parameters 0-15 */
define|#
directive|define
name|SDM_OP_GEN_COMP_PARAM_SHIFT
value|0
define|#
directive|define
name|SDM_OP_GEN_COMP_TYPE_MASK
value|0xF
comment|/* completion type 16-19 */
define|#
directive|define
name|SDM_OP_GEN_COMP_TYPE_SHIFT
value|16
define|#
directive|define
name|SDM_OP_GEN_RESERVED_MASK
value|0xFFF
comment|/* reserved 20-31 */
define|#
directive|define
name|SDM_OP_GEN_RESERVED_SHIFT
value|20
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ECORE_HSI_COMMON__ */
end_comment

end_unit

