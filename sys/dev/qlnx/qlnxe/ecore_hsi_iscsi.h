begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2017-2018 Cavium, Inc.   * All rights reserved.  *  *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *  *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *  *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  *  POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ECORE_HSI_ISCSI__
end_ifndef

begin_define
define|#
directive|define
name|__ECORE_HSI_ISCSI__
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
comment|/*************************************************************************/
end_comment

begin_comment
comment|/* Add include to common iSCSI target for both eCore and protocol driver */
end_comment

begin_comment
comment|/************************************************************************/
end_comment

begin_include
include|#
directive|include
file|"iscsi_common.h"
end_include

begin_comment
comment|/*  * The iscsi storm connection context of Ystorm  */
end_comment

begin_struct
struct|struct
name|ystorm_iscsi_conn_st_ctx
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
comment|/*  * Combined iSCSI and TCP storm connection of Pstorm  */
end_comment

begin_struct
struct|struct
name|pstorm_iscsi_tcp_conn_st_ctx
block|{
name|__le32
name|tcp
index|[
literal|32
index|]
decl_stmt|;
name|__le32
name|iscsi
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The combined tcp and iscsi storm context of Xstorm  */
end_comment

begin_struct
struct|struct
name|xstorm_iscsi_tcp_conn_st_ctx
block|{
name|__le32
name|reserved_iscsi
index|[
literal|40
index|]
decl_stmt|;
name|__le32
name|reserved_tcp
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|e4_xstorm_iscsi_conn_ag_ctx
block|{
name|u8
name|cdu_validation
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
name|E4_XSTORM_ISCSI_CONN_AG_CTX_EXIST_IN_QM0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_EXIST_IN_QM0_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_EXIST_IN_QM1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_EXIST_IN_QM1_SHIFT
value|1
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_RESERVED1_MASK
value|0x1
comment|/* exist_in_qm2 */
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_RESERVED1_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_EXIST_IN_QM3_MASK
value|0x1
comment|/* exist_in_qm3 */
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_EXIST_IN_QM3_SHIFT
value|3
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_BIT4_MASK
value|0x1
comment|/* bit4 */
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_BIT4_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_RESERVED2_MASK
value|0x1
comment|/* cf_array_active */
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_RESERVED2_SHIFT
value|5
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_BIT6_MASK
value|0x1
comment|/* bit6 */
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_BIT6_SHIFT
value|6
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_BIT7_MASK
value|0x1
comment|/* bit7 */
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_BIT7_SHIFT
value|7
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_BIT8_MASK
value|0x1
comment|/* bit8 */
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_BIT8_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_BIT9_MASK
value|0x1
comment|/* bit9 */
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_BIT9_SHIFT
value|1
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_BIT10_MASK
value|0x1
comment|/* bit10 */
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_BIT10_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_BIT11_MASK
value|0x1
comment|/* bit11 */
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_BIT11_SHIFT
value|3
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_BIT12_MASK
value|0x1
comment|/* bit12 */
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_BIT12_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_BIT13_MASK
value|0x1
comment|/* bit13 */
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_BIT13_SHIFT
value|5
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_BIT14_MASK
value|0x1
comment|/* bit14 */
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_BIT14_SHIFT
value|6
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_TX_TRUNCATE_MASK
value|0x1
comment|/* bit15 */
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_TX_TRUNCATE_SHIFT
value|7
name|u8
name|flags2
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_CF0_MASK
value|0x3
comment|/* timer0cf */
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_CF0_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_CF1_MASK
value|0x3
comment|/* timer1cf */
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_CF1_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_CF2_MASK
value|0x3
comment|/* timer2cf */
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_CF2_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_TIMER_STOP_ALL_MASK
value|0x3
comment|/* timer_stop_all */
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_TIMER_STOP_ALL_SHIFT
value|6
name|u8
name|flags3
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_CF4_MASK
value|0x3
comment|/* cf4 */
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_CF4_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_CF5_MASK
value|0x3
comment|/* cf5 */
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_CF5_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_CF6_MASK
value|0x3
comment|/* cf6 */
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_CF6_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_CF7_MASK
value|0x3
comment|/* cf7 */
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_CF7_SHIFT
value|6
name|u8
name|flags4
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_CF8_MASK
value|0x3
comment|/* cf8 */
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_CF8_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_CF9_MASK
value|0x3
comment|/* cf9 */
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_CF9_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_CF10_MASK
value|0x3
comment|/* cf10 */
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_CF10_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_CF11_MASK
value|0x3
comment|/* cf11 */
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_CF11_SHIFT
value|6
name|u8
name|flags5
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_CF12_MASK
value|0x3
comment|/* cf12 */
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_CF12_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_CF13_MASK
value|0x3
comment|/* cf13 */
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_CF13_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_CF14_MASK
value|0x3
comment|/* cf14 */
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_CF14_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_UPDATE_STATE_TO_BASE_CF_MASK
value|0x3
comment|/* cf15 */
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_UPDATE_STATE_TO_BASE_CF_SHIFT
value|6
name|u8
name|flags6
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_CF16_MASK
value|0x3
comment|/* cf16 */
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_CF16_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_CF17_MASK
value|0x3
comment|/* cf_array_cf */
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_CF17_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_CF18_MASK
value|0x3
comment|/* cf18 */
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_CF18_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_DQ_FLUSH_MASK
value|0x3
comment|/* cf19 */
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_DQ_FLUSH_SHIFT
value|6
name|u8
name|flags7
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_MST_XCM_Q0_FLUSH_CF_MASK
value|0x3
comment|/* cf20 */
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_MST_XCM_Q0_FLUSH_CF_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_UST_XCM_Q1_FLUSH_CF_MASK
value|0x3
comment|/* cf21 */
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_UST_XCM_Q1_FLUSH_CF_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_SLOW_PATH_MASK
value|0x3
comment|/* cf22 */
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_SLOW_PATH_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_CF0EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_CF0EN_SHIFT
value|6
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_CF1EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_CF1EN_SHIFT
value|7
name|u8
name|flags8
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_CF2EN_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_CF2EN_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_TIMER_STOP_ALL_EN_MASK
value|0x1
comment|/* cf3en */
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_TIMER_STOP_ALL_EN_SHIFT
value|1
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_CF4EN_MASK
value|0x1
comment|/* cf4en */
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_CF4EN_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_CF5EN_MASK
value|0x1
comment|/* cf5en */
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_CF5EN_SHIFT
value|3
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_CF6EN_MASK
value|0x1
comment|/* cf6en */
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_CF6EN_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_CF7EN_MASK
value|0x1
comment|/* cf7en */
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_CF7EN_SHIFT
value|5
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_CF8EN_MASK
value|0x1
comment|/* cf8en */
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_CF8EN_SHIFT
value|6
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_CF9EN_MASK
value|0x1
comment|/* cf9en */
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_CF9EN_SHIFT
value|7
name|u8
name|flags9
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_CF10EN_MASK
value|0x1
comment|/* cf10en */
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_CF10EN_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_CF11EN_MASK
value|0x1
comment|/* cf11en */
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_CF11EN_SHIFT
value|1
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_CF12EN_MASK
value|0x1
comment|/* cf12en */
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_CF12EN_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_CF13EN_MASK
value|0x1
comment|/* cf13en */
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_CF13EN_SHIFT
value|3
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_CF14EN_MASK
value|0x1
comment|/* cf14en */
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_CF14EN_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_UPDATE_STATE_TO_BASE_CF_EN_MASK
value|0x1
comment|/* cf15en */
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_UPDATE_STATE_TO_BASE_CF_EN_SHIFT
value|5
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_CF16EN_MASK
value|0x1
comment|/* cf16en */
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_CF16EN_SHIFT
value|6
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_CF17EN_MASK
value|0x1
comment|/* cf_array_cf_en */
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_CF17EN_SHIFT
value|7
name|u8
name|flags10
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_CF18EN_MASK
value|0x1
comment|/* cf18en */
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_CF18EN_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_DQ_FLUSH_EN_MASK
value|0x1
comment|/* cf19en */
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_DQ_FLUSH_EN_SHIFT
value|1
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_MST_XCM_Q0_FLUSH_CF_EN_MASK
value|0x1
comment|/* cf20en */
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_MST_XCM_Q0_FLUSH_CF_EN_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_UST_XCM_Q1_FLUSH_CF_EN_MASK
value|0x1
comment|/* cf21en */
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_UST_XCM_Q1_FLUSH_CF_EN_SHIFT
value|3
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_SLOW_PATH_EN_MASK
value|0x1
comment|/* cf22en */
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_SLOW_PATH_EN_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_PROC_ONLY_CLEANUP_EN_MASK
value|0x1
comment|/* cf23en */
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_PROC_ONLY_CLEANUP_EN_SHIFT
value|5
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_RULE0EN_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_RULE0EN_SHIFT
value|6
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_MORE_TO_SEND_DEC_RULE_EN_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_MORE_TO_SEND_DEC_RULE_EN_SHIFT
value|7
name|u8
name|flags11
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_TX_BLOCKED_EN_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_TX_BLOCKED_EN_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_RULE3EN_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_RULE3EN_SHIFT
value|1
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_RESERVED3_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_RESERVED3_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_RULE5EN_MASK
value|0x1
comment|/* rule5en */
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_RULE5EN_SHIFT
value|3
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_RULE6EN_MASK
value|0x1
comment|/* rule6en */
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_RULE6EN_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_RULE7EN_MASK
value|0x1
comment|/* rule7en */
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_RULE7EN_SHIFT
value|5
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_A0_RESERVED1_MASK
value|0x1
comment|/* rule8en */
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_A0_RESERVED1_SHIFT
value|6
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_RULE9EN_MASK
value|0x1
comment|/* rule9en */
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_RULE9EN_SHIFT
value|7
name|u8
name|flags12
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_SQ_DEC_RULE_EN_MASK
value|0x1
comment|/* rule10en */
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_SQ_DEC_RULE_EN_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_RULE11EN_MASK
value|0x1
comment|/* rule11en */
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_RULE11EN_SHIFT
value|1
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_A0_RESERVED2_MASK
value|0x1
comment|/* rule12en */
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_A0_RESERVED2_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_A0_RESERVED3_MASK
value|0x1
comment|/* rule13en */
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_A0_RESERVED3_SHIFT
value|3
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_RULE14EN_MASK
value|0x1
comment|/* rule14en */
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_RULE14EN_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_RULE15EN_MASK
value|0x1
comment|/* rule15en */
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_RULE15EN_SHIFT
value|5
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_RULE16EN_MASK
value|0x1
comment|/* rule16en */
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_RULE16EN_SHIFT
value|6
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_RULE17EN_MASK
value|0x1
comment|/* rule17en */
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_RULE17EN_SHIFT
value|7
name|u8
name|flags13
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_R2TQ_DEC_RULE_EN_MASK
value|0x1
comment|/* rule18en */
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_R2TQ_DEC_RULE_EN_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_HQ_DEC_RULE_EN_MASK
value|0x1
comment|/* rule19en */
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_HQ_DEC_RULE_EN_SHIFT
value|1
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_A0_RESERVED4_MASK
value|0x1
comment|/* rule20en */
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_A0_RESERVED4_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_A0_RESERVED5_MASK
value|0x1
comment|/* rule21en */
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_A0_RESERVED5_SHIFT
value|3
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_A0_RESERVED6_MASK
value|0x1
comment|/* rule22en */
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_A0_RESERVED6_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_A0_RESERVED7_MASK
value|0x1
comment|/* rule23en */
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_A0_RESERVED7_SHIFT
value|5
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_A0_RESERVED8_MASK
value|0x1
comment|/* rule24en */
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_A0_RESERVED8_SHIFT
value|6
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_A0_RESERVED9_MASK
value|0x1
comment|/* rule25en */
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_A0_RESERVED9_SHIFT
value|7
name|u8
name|flags14
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_BIT16_MASK
value|0x1
comment|/* bit16 */
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_BIT16_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_BIT17_MASK
value|0x1
comment|/* bit17 */
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_BIT17_SHIFT
value|1
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_BIT18_MASK
value|0x1
comment|/* bit18 */
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_BIT18_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_BIT19_MASK
value|0x1
comment|/* bit19 */
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_BIT19_SHIFT
value|3
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_BIT20_MASK
value|0x1
comment|/* bit20 */
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_BIT20_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_DUMMY_READ_DONE_MASK
value|0x1
comment|/* bit21 */
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_DUMMY_READ_DONE_SHIFT
value|5
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_PROC_ONLY_CLEANUP_MASK
value|0x3
comment|/* cf23 */
define|#
directive|define
name|E4_XSTORM_ISCSI_CONN_AG_CTX_PROC_ONLY_CLEANUP_SHIFT
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
name|physical_q1
comment|/* physical_q1 */
decl_stmt|;
name|__le16
name|dummy_dorq_var
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
name|word5
comment|/* word5 */
decl_stmt|;
name|__le16
name|slow_io_total_data_tx_update
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
name|more_to_send_seq
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
name|hq_scan_next_relevant_ack
comment|/* cf_array1 */
decl_stmt|;
name|__le16
name|r2tq_prod
comment|/* word7 */
decl_stmt|;
name|__le16
name|r2tq_cons
comment|/* word8 */
decl_stmt|;
name|__le16
name|hq_prod
comment|/* word9 */
decl_stmt|;
name|__le16
name|hq_cons
comment|/* word10 */
decl_stmt|;
name|__le32
name|remain_seq
comment|/* reg7 */
decl_stmt|;
name|__le32
name|bytes_to_next_pdu
comment|/* reg8 */
decl_stmt|;
name|__le32
name|hq_tcp_seq
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
name|exp_stat_sn
comment|/* reg12 */
decl_stmt|;
name|__le32
name|ongoing_fast_rxmit_seq
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
block|}
struct|;
end_struct

begin_struct
struct|struct
name|e4_tstorm_iscsi_conn_ag_ctx
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
name|E4_TSTORM_ISCSI_CONN_AG_CTX_EXIST_IN_QM0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E4_TSTORM_ISCSI_CONN_AG_CTX_EXIST_IN_QM0_SHIFT
value|0
define|#
directive|define
name|E4_TSTORM_ISCSI_CONN_AG_CTX_BIT1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E4_TSTORM_ISCSI_CONN_AG_CTX_BIT1_SHIFT
value|1
define|#
directive|define
name|E4_TSTORM_ISCSI_CONN_AG_CTX_BIT2_MASK
value|0x1
comment|/* bit2 */
define|#
directive|define
name|E4_TSTORM_ISCSI_CONN_AG_CTX_BIT2_SHIFT
value|2
define|#
directive|define
name|E4_TSTORM_ISCSI_CONN_AG_CTX_BIT3_MASK
value|0x1
comment|/* bit3 */
define|#
directive|define
name|E4_TSTORM_ISCSI_CONN_AG_CTX_BIT3_SHIFT
value|3
define|#
directive|define
name|E4_TSTORM_ISCSI_CONN_AG_CTX_BIT4_MASK
value|0x1
comment|/* bit4 */
define|#
directive|define
name|E4_TSTORM_ISCSI_CONN_AG_CTX_BIT4_SHIFT
value|4
define|#
directive|define
name|E4_TSTORM_ISCSI_CONN_AG_CTX_BIT5_MASK
value|0x1
comment|/* bit5 */
define|#
directive|define
name|E4_TSTORM_ISCSI_CONN_AG_CTX_BIT5_SHIFT
value|5
define|#
directive|define
name|E4_TSTORM_ISCSI_CONN_AG_CTX_CF0_MASK
value|0x3
comment|/* timer0cf */
define|#
directive|define
name|E4_TSTORM_ISCSI_CONN_AG_CTX_CF0_SHIFT
value|6
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E4_TSTORM_ISCSI_CONN_AG_CTX_P2T_FLUSH_CF_MASK
value|0x3
comment|/* timer1cf */
define|#
directive|define
name|E4_TSTORM_ISCSI_CONN_AG_CTX_P2T_FLUSH_CF_SHIFT
value|0
define|#
directive|define
name|E4_TSTORM_ISCSI_CONN_AG_CTX_M2T_FLUSH_CF_MASK
value|0x3
comment|/* timer2cf */
define|#
directive|define
name|E4_TSTORM_ISCSI_CONN_AG_CTX_M2T_FLUSH_CF_SHIFT
value|2
define|#
directive|define
name|E4_TSTORM_ISCSI_CONN_AG_CTX_TIMER_STOP_ALL_MASK
value|0x3
comment|/* timer_stop_all */
define|#
directive|define
name|E4_TSTORM_ISCSI_CONN_AG_CTX_TIMER_STOP_ALL_SHIFT
value|4
define|#
directive|define
name|E4_TSTORM_ISCSI_CONN_AG_CTX_CF4_MASK
value|0x3
comment|/* cf4 */
define|#
directive|define
name|E4_TSTORM_ISCSI_CONN_AG_CTX_CF4_SHIFT
value|6
name|u8
name|flags2
decl_stmt|;
define|#
directive|define
name|E4_TSTORM_ISCSI_CONN_AG_CTX_CF5_MASK
value|0x3
comment|/* cf5 */
define|#
directive|define
name|E4_TSTORM_ISCSI_CONN_AG_CTX_CF5_SHIFT
value|0
define|#
directive|define
name|E4_TSTORM_ISCSI_CONN_AG_CTX_CF6_MASK
value|0x3
comment|/* cf6 */
define|#
directive|define
name|E4_TSTORM_ISCSI_CONN_AG_CTX_CF6_SHIFT
value|2
define|#
directive|define
name|E4_TSTORM_ISCSI_CONN_AG_CTX_CF7_MASK
value|0x3
comment|/* cf7 */
define|#
directive|define
name|E4_TSTORM_ISCSI_CONN_AG_CTX_CF7_SHIFT
value|4
define|#
directive|define
name|E4_TSTORM_ISCSI_CONN_AG_CTX_CF8_MASK
value|0x3
comment|/* cf8 */
define|#
directive|define
name|E4_TSTORM_ISCSI_CONN_AG_CTX_CF8_SHIFT
value|6
name|u8
name|flags3
decl_stmt|;
define|#
directive|define
name|E4_TSTORM_ISCSI_CONN_AG_CTX_FLUSH_Q0_MASK
value|0x3
comment|/* cf9 */
define|#
directive|define
name|E4_TSTORM_ISCSI_CONN_AG_CTX_FLUSH_Q0_SHIFT
value|0
define|#
directive|define
name|E4_TSTORM_ISCSI_CONN_AG_CTX_CF10_MASK
value|0x3
comment|/* cf10 */
define|#
directive|define
name|E4_TSTORM_ISCSI_CONN_AG_CTX_CF10_SHIFT
value|2
define|#
directive|define
name|E4_TSTORM_ISCSI_CONN_AG_CTX_CF0EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E4_TSTORM_ISCSI_CONN_AG_CTX_CF0EN_SHIFT
value|4
define|#
directive|define
name|E4_TSTORM_ISCSI_CONN_AG_CTX_P2T_FLUSH_CF_EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E4_TSTORM_ISCSI_CONN_AG_CTX_P2T_FLUSH_CF_EN_SHIFT
value|5
define|#
directive|define
name|E4_TSTORM_ISCSI_CONN_AG_CTX_M2T_FLUSH_CF_EN_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E4_TSTORM_ISCSI_CONN_AG_CTX_M2T_FLUSH_CF_EN_SHIFT
value|6
define|#
directive|define
name|E4_TSTORM_ISCSI_CONN_AG_CTX_TIMER_STOP_ALL_EN_MASK
value|0x1
comment|/* cf3en */
define|#
directive|define
name|E4_TSTORM_ISCSI_CONN_AG_CTX_TIMER_STOP_ALL_EN_SHIFT
value|7
name|u8
name|flags4
decl_stmt|;
define|#
directive|define
name|E4_TSTORM_ISCSI_CONN_AG_CTX_CF4EN_MASK
value|0x1
comment|/* cf4en */
define|#
directive|define
name|E4_TSTORM_ISCSI_CONN_AG_CTX_CF4EN_SHIFT
value|0
define|#
directive|define
name|E4_TSTORM_ISCSI_CONN_AG_CTX_CF5EN_MASK
value|0x1
comment|/* cf5en */
define|#
directive|define
name|E4_TSTORM_ISCSI_CONN_AG_CTX_CF5EN_SHIFT
value|1
define|#
directive|define
name|E4_TSTORM_ISCSI_CONN_AG_CTX_CF6EN_MASK
value|0x1
comment|/* cf6en */
define|#
directive|define
name|E4_TSTORM_ISCSI_CONN_AG_CTX_CF6EN_SHIFT
value|2
define|#
directive|define
name|E4_TSTORM_ISCSI_CONN_AG_CTX_CF7EN_MASK
value|0x1
comment|/* cf7en */
define|#
directive|define
name|E4_TSTORM_ISCSI_CONN_AG_CTX_CF7EN_SHIFT
value|3
define|#
directive|define
name|E4_TSTORM_ISCSI_CONN_AG_CTX_CF8EN_MASK
value|0x1
comment|/* cf8en */
define|#
directive|define
name|E4_TSTORM_ISCSI_CONN_AG_CTX_CF8EN_SHIFT
value|4
define|#
directive|define
name|E4_TSTORM_ISCSI_CONN_AG_CTX_FLUSH_Q0_EN_MASK
value|0x1
comment|/* cf9en */
define|#
directive|define
name|E4_TSTORM_ISCSI_CONN_AG_CTX_FLUSH_Q0_EN_SHIFT
value|5
define|#
directive|define
name|E4_TSTORM_ISCSI_CONN_AG_CTX_CF10EN_MASK
value|0x1
comment|/* cf10en */
define|#
directive|define
name|E4_TSTORM_ISCSI_CONN_AG_CTX_CF10EN_SHIFT
value|6
define|#
directive|define
name|E4_TSTORM_ISCSI_CONN_AG_CTX_RULE0EN_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E4_TSTORM_ISCSI_CONN_AG_CTX_RULE0EN_SHIFT
value|7
name|u8
name|flags5
decl_stmt|;
define|#
directive|define
name|E4_TSTORM_ISCSI_CONN_AG_CTX_RULE1EN_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E4_TSTORM_ISCSI_CONN_AG_CTX_RULE1EN_SHIFT
value|0
define|#
directive|define
name|E4_TSTORM_ISCSI_CONN_AG_CTX_RULE2EN_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E4_TSTORM_ISCSI_CONN_AG_CTX_RULE2EN_SHIFT
value|1
define|#
directive|define
name|E4_TSTORM_ISCSI_CONN_AG_CTX_RULE3EN_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E4_TSTORM_ISCSI_CONN_AG_CTX_RULE3EN_SHIFT
value|2
define|#
directive|define
name|E4_TSTORM_ISCSI_CONN_AG_CTX_RULE4EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E4_TSTORM_ISCSI_CONN_AG_CTX_RULE4EN_SHIFT
value|3
define|#
directive|define
name|E4_TSTORM_ISCSI_CONN_AG_CTX_RULE5EN_MASK
value|0x1
comment|/* rule5en */
define|#
directive|define
name|E4_TSTORM_ISCSI_CONN_AG_CTX_RULE5EN_SHIFT
value|4
define|#
directive|define
name|E4_TSTORM_ISCSI_CONN_AG_CTX_RULE6EN_MASK
value|0x1
comment|/* rule6en */
define|#
directive|define
name|E4_TSTORM_ISCSI_CONN_AG_CTX_RULE6EN_SHIFT
value|5
define|#
directive|define
name|E4_TSTORM_ISCSI_CONN_AG_CTX_RULE7EN_MASK
value|0x1
comment|/* rule7en */
define|#
directive|define
name|E4_TSTORM_ISCSI_CONN_AG_CTX_RULE7EN_SHIFT
value|6
define|#
directive|define
name|E4_TSTORM_ISCSI_CONN_AG_CTX_RULE8EN_MASK
value|0x1
comment|/* rule8en */
define|#
directive|define
name|E4_TSTORM_ISCSI_CONN_AG_CTX_RULE8EN_SHIFT
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
name|cid_offload_cnt
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
block|}
struct|;
end_struct

begin_struct
struct|struct
name|e4_ustorm_iscsi_conn_ag_ctx
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
name|E4_USTORM_ISCSI_CONN_AG_CTX_BIT0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E4_USTORM_ISCSI_CONN_AG_CTX_BIT0_SHIFT
value|0
define|#
directive|define
name|E4_USTORM_ISCSI_CONN_AG_CTX_BIT1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E4_USTORM_ISCSI_CONN_AG_CTX_BIT1_SHIFT
value|1
define|#
directive|define
name|E4_USTORM_ISCSI_CONN_AG_CTX_CF0_MASK
value|0x3
comment|/* timer0cf */
define|#
directive|define
name|E4_USTORM_ISCSI_CONN_AG_CTX_CF0_SHIFT
value|2
define|#
directive|define
name|E4_USTORM_ISCSI_CONN_AG_CTX_CF1_MASK
value|0x3
comment|/* timer1cf */
define|#
directive|define
name|E4_USTORM_ISCSI_CONN_AG_CTX_CF1_SHIFT
value|4
define|#
directive|define
name|E4_USTORM_ISCSI_CONN_AG_CTX_CF2_MASK
value|0x3
comment|/* timer2cf */
define|#
directive|define
name|E4_USTORM_ISCSI_CONN_AG_CTX_CF2_SHIFT
value|6
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E4_USTORM_ISCSI_CONN_AG_CTX_CF3_MASK
value|0x3
comment|/* timer_stop_all */
define|#
directive|define
name|E4_USTORM_ISCSI_CONN_AG_CTX_CF3_SHIFT
value|0
define|#
directive|define
name|E4_USTORM_ISCSI_CONN_AG_CTX_CF4_MASK
value|0x3
comment|/* cf4 */
define|#
directive|define
name|E4_USTORM_ISCSI_CONN_AG_CTX_CF4_SHIFT
value|2
define|#
directive|define
name|E4_USTORM_ISCSI_CONN_AG_CTX_CF5_MASK
value|0x3
comment|/* cf5 */
define|#
directive|define
name|E4_USTORM_ISCSI_CONN_AG_CTX_CF5_SHIFT
value|4
define|#
directive|define
name|E4_USTORM_ISCSI_CONN_AG_CTX_CF6_MASK
value|0x3
comment|/* cf6 */
define|#
directive|define
name|E4_USTORM_ISCSI_CONN_AG_CTX_CF6_SHIFT
value|6
name|u8
name|flags2
decl_stmt|;
define|#
directive|define
name|E4_USTORM_ISCSI_CONN_AG_CTX_CF0EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E4_USTORM_ISCSI_CONN_AG_CTX_CF0EN_SHIFT
value|0
define|#
directive|define
name|E4_USTORM_ISCSI_CONN_AG_CTX_CF1EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E4_USTORM_ISCSI_CONN_AG_CTX_CF1EN_SHIFT
value|1
define|#
directive|define
name|E4_USTORM_ISCSI_CONN_AG_CTX_CF2EN_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E4_USTORM_ISCSI_CONN_AG_CTX_CF2EN_SHIFT
value|2
define|#
directive|define
name|E4_USTORM_ISCSI_CONN_AG_CTX_CF3EN_MASK
value|0x1
comment|/* cf3en */
define|#
directive|define
name|E4_USTORM_ISCSI_CONN_AG_CTX_CF3EN_SHIFT
value|3
define|#
directive|define
name|E4_USTORM_ISCSI_CONN_AG_CTX_CF4EN_MASK
value|0x1
comment|/* cf4en */
define|#
directive|define
name|E4_USTORM_ISCSI_CONN_AG_CTX_CF4EN_SHIFT
value|4
define|#
directive|define
name|E4_USTORM_ISCSI_CONN_AG_CTX_CF5EN_MASK
value|0x1
comment|/* cf5en */
define|#
directive|define
name|E4_USTORM_ISCSI_CONN_AG_CTX_CF5EN_SHIFT
value|5
define|#
directive|define
name|E4_USTORM_ISCSI_CONN_AG_CTX_CF6EN_MASK
value|0x1
comment|/* cf6en */
define|#
directive|define
name|E4_USTORM_ISCSI_CONN_AG_CTX_CF6EN_SHIFT
value|6
define|#
directive|define
name|E4_USTORM_ISCSI_CONN_AG_CTX_RULE0EN_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E4_USTORM_ISCSI_CONN_AG_CTX_RULE0EN_SHIFT
value|7
name|u8
name|flags3
decl_stmt|;
define|#
directive|define
name|E4_USTORM_ISCSI_CONN_AG_CTX_RULE1EN_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E4_USTORM_ISCSI_CONN_AG_CTX_RULE1EN_SHIFT
value|0
define|#
directive|define
name|E4_USTORM_ISCSI_CONN_AG_CTX_RULE2EN_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E4_USTORM_ISCSI_CONN_AG_CTX_RULE2EN_SHIFT
value|1
define|#
directive|define
name|E4_USTORM_ISCSI_CONN_AG_CTX_RULE3EN_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E4_USTORM_ISCSI_CONN_AG_CTX_RULE3EN_SHIFT
value|2
define|#
directive|define
name|E4_USTORM_ISCSI_CONN_AG_CTX_RULE4EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E4_USTORM_ISCSI_CONN_AG_CTX_RULE4EN_SHIFT
value|3
define|#
directive|define
name|E4_USTORM_ISCSI_CONN_AG_CTX_RULE5EN_MASK
value|0x1
comment|/* rule5en */
define|#
directive|define
name|E4_USTORM_ISCSI_CONN_AG_CTX_RULE5EN_SHIFT
value|4
define|#
directive|define
name|E4_USTORM_ISCSI_CONN_AG_CTX_RULE6EN_MASK
value|0x1
comment|/* rule6en */
define|#
directive|define
name|E4_USTORM_ISCSI_CONN_AG_CTX_RULE6EN_SHIFT
value|5
define|#
directive|define
name|E4_USTORM_ISCSI_CONN_AG_CTX_RULE7EN_MASK
value|0x1
comment|/* rule7en */
define|#
directive|define
name|E4_USTORM_ISCSI_CONN_AG_CTX_RULE7EN_SHIFT
value|6
define|#
directive|define
name|E4_USTORM_ISCSI_CONN_AG_CTX_RULE8EN_MASK
value|0x1
comment|/* rule8en */
define|#
directive|define
name|E4_USTORM_ISCSI_CONN_AG_CTX_RULE8EN_SHIFT
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
comment|/*  * The iscsi storm connection context of Tstorm  */
end_comment

begin_struct
struct|struct
name|tstorm_iscsi_conn_st_ctx
block|{
name|__le32
name|reserved
index|[
literal|40
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|e4_mstorm_iscsi_conn_ag_ctx
block|{
name|u8
name|reserved
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
name|E4_MSTORM_ISCSI_CONN_AG_CTX_BIT0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E4_MSTORM_ISCSI_CONN_AG_CTX_BIT0_SHIFT
value|0
define|#
directive|define
name|E4_MSTORM_ISCSI_CONN_AG_CTX_BIT1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E4_MSTORM_ISCSI_CONN_AG_CTX_BIT1_SHIFT
value|1
define|#
directive|define
name|E4_MSTORM_ISCSI_CONN_AG_CTX_CF0_MASK
value|0x3
comment|/* cf0 */
define|#
directive|define
name|E4_MSTORM_ISCSI_CONN_AG_CTX_CF0_SHIFT
value|2
define|#
directive|define
name|E4_MSTORM_ISCSI_CONN_AG_CTX_CF1_MASK
value|0x3
comment|/* cf1 */
define|#
directive|define
name|E4_MSTORM_ISCSI_CONN_AG_CTX_CF1_SHIFT
value|4
define|#
directive|define
name|E4_MSTORM_ISCSI_CONN_AG_CTX_CF2_MASK
value|0x3
comment|/* cf2 */
define|#
directive|define
name|E4_MSTORM_ISCSI_CONN_AG_CTX_CF2_SHIFT
value|6
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E4_MSTORM_ISCSI_CONN_AG_CTX_CF0EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E4_MSTORM_ISCSI_CONN_AG_CTX_CF0EN_SHIFT
value|0
define|#
directive|define
name|E4_MSTORM_ISCSI_CONN_AG_CTX_CF1EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E4_MSTORM_ISCSI_CONN_AG_CTX_CF1EN_SHIFT
value|1
define|#
directive|define
name|E4_MSTORM_ISCSI_CONN_AG_CTX_CF2EN_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E4_MSTORM_ISCSI_CONN_AG_CTX_CF2EN_SHIFT
value|2
define|#
directive|define
name|E4_MSTORM_ISCSI_CONN_AG_CTX_RULE0EN_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E4_MSTORM_ISCSI_CONN_AG_CTX_RULE0EN_SHIFT
value|3
define|#
directive|define
name|E4_MSTORM_ISCSI_CONN_AG_CTX_RULE1EN_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E4_MSTORM_ISCSI_CONN_AG_CTX_RULE1EN_SHIFT
value|4
define|#
directive|define
name|E4_MSTORM_ISCSI_CONN_AG_CTX_RULE2EN_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E4_MSTORM_ISCSI_CONN_AG_CTX_RULE2EN_SHIFT
value|5
define|#
directive|define
name|E4_MSTORM_ISCSI_CONN_AG_CTX_RULE3EN_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E4_MSTORM_ISCSI_CONN_AG_CTX_RULE3EN_SHIFT
value|6
define|#
directive|define
name|E4_MSTORM_ISCSI_CONN_AG_CTX_RULE4EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E4_MSTORM_ISCSI_CONN_AG_CTX_RULE4EN_SHIFT
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
comment|/*  * Combined iSCSI and TCP storm connection of Mstorm  */
end_comment

begin_struct
struct|struct
name|mstorm_iscsi_tcp_conn_st_ctx
block|{
name|__le32
name|reserved_tcp
index|[
literal|20
index|]
decl_stmt|;
name|__le32
name|reserved_iscsi
index|[
literal|8
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The iscsi storm context of Ustorm  */
end_comment

begin_struct
struct|struct
name|ustorm_iscsi_conn_st_ctx
block|{
name|__le32
name|reserved
index|[
literal|52
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * iscsi connection context  */
end_comment

begin_struct
struct|struct
name|iscsi_conn_context
block|{
name|struct
name|ystorm_iscsi_conn_st_ctx
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
name|pstorm_iscsi_tcp_conn_st_ctx
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
name|pb_context
name|xpb2_context
comment|/* xpb2 context */
decl_stmt|;
name|struct
name|xstorm_iscsi_tcp_conn_st_ctx
name|xstorm_st_context
comment|/* xstorm storm context */
decl_stmt|;
name|struct
name|regpair
name|xstorm_st_padding
index|[
literal|2
index|]
comment|/* padding */
decl_stmt|;
name|struct
name|e4_xstorm_iscsi_conn_ag_ctx
name|xstorm_ag_context
comment|/* xstorm aggregative context */
decl_stmt|;
name|struct
name|e4_tstorm_iscsi_conn_ag_ctx
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
name|e4_ustorm_iscsi_conn_ag_ctx
name|ustorm_ag_context
comment|/* ustorm aggregative context */
decl_stmt|;
name|struct
name|pb_context
name|upb_context
comment|/* upb context */
decl_stmt|;
name|struct
name|tstorm_iscsi_conn_st_ctx
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
name|e4_mstorm_iscsi_conn_ag_ctx
name|mstorm_ag_context
comment|/* mstorm aggregative context */
decl_stmt|;
name|struct
name|mstorm_iscsi_tcp_conn_st_ctx
name|mstorm_st_context
comment|/* mstorm storm context */
decl_stmt|;
name|struct
name|ustorm_iscsi_conn_st_ctx
name|ustorm_st_context
comment|/* ustorm storm context */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * iSCSI init params passed by driver to FW in iSCSI init ramrod   */
end_comment

begin_struct
struct|struct
name|iscsi_init_ramrod_params
block|{
name|struct
name|iscsi_spe_func_init
name|iscsi_init_spe
comment|/* parameters initialized by the miniport and handed to bus-driver */
decl_stmt|;
name|struct
name|tcp_init_params
name|tcp_init
comment|/* TCP parameters initialized by the bus-driver */
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|e4_ystorm_iscsi_conn_ag_ctx
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
name|E4_YSTORM_ISCSI_CONN_AG_CTX_BIT0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E4_YSTORM_ISCSI_CONN_AG_CTX_BIT0_SHIFT
value|0
define|#
directive|define
name|E4_YSTORM_ISCSI_CONN_AG_CTX_BIT1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E4_YSTORM_ISCSI_CONN_AG_CTX_BIT1_SHIFT
value|1
define|#
directive|define
name|E4_YSTORM_ISCSI_CONN_AG_CTX_CF0_MASK
value|0x3
comment|/* cf0 */
define|#
directive|define
name|E4_YSTORM_ISCSI_CONN_AG_CTX_CF0_SHIFT
value|2
define|#
directive|define
name|E4_YSTORM_ISCSI_CONN_AG_CTX_CF1_MASK
value|0x3
comment|/* cf1 */
define|#
directive|define
name|E4_YSTORM_ISCSI_CONN_AG_CTX_CF1_SHIFT
value|4
define|#
directive|define
name|E4_YSTORM_ISCSI_CONN_AG_CTX_CF2_MASK
value|0x3
comment|/* cf2 */
define|#
directive|define
name|E4_YSTORM_ISCSI_CONN_AG_CTX_CF2_SHIFT
value|6
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E4_YSTORM_ISCSI_CONN_AG_CTX_CF0EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E4_YSTORM_ISCSI_CONN_AG_CTX_CF0EN_SHIFT
value|0
define|#
directive|define
name|E4_YSTORM_ISCSI_CONN_AG_CTX_CF1EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E4_YSTORM_ISCSI_CONN_AG_CTX_CF1EN_SHIFT
value|1
define|#
directive|define
name|E4_YSTORM_ISCSI_CONN_AG_CTX_CF2EN_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E4_YSTORM_ISCSI_CONN_AG_CTX_CF2EN_SHIFT
value|2
define|#
directive|define
name|E4_YSTORM_ISCSI_CONN_AG_CTX_RULE0EN_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E4_YSTORM_ISCSI_CONN_AG_CTX_RULE0EN_SHIFT
value|3
define|#
directive|define
name|E4_YSTORM_ISCSI_CONN_AG_CTX_RULE1EN_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E4_YSTORM_ISCSI_CONN_AG_CTX_RULE1EN_SHIFT
value|4
define|#
directive|define
name|E4_YSTORM_ISCSI_CONN_AG_CTX_RULE2EN_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E4_YSTORM_ISCSI_CONN_AG_CTX_RULE2EN_SHIFT
value|5
define|#
directive|define
name|E4_YSTORM_ISCSI_CONN_AG_CTX_RULE3EN_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E4_YSTORM_ISCSI_CONN_AG_CTX_RULE3EN_SHIFT
value|6
define|#
directive|define
name|E4_YSTORM_ISCSI_CONN_AG_CTX_RULE4EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E4_YSTORM_ISCSI_CONN_AG_CTX_RULE4EN_SHIFT
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
name|e5_mstorm_iscsi_conn_ag_ctx
block|{
name|u8
name|reserved
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
name|E5_MSTORM_ISCSI_CONN_AG_CTX_BIT0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E5_MSTORM_ISCSI_CONN_AG_CTX_BIT0_SHIFT
value|0
define|#
directive|define
name|E5_MSTORM_ISCSI_CONN_AG_CTX_BIT1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E5_MSTORM_ISCSI_CONN_AG_CTX_BIT1_SHIFT
value|1
define|#
directive|define
name|E5_MSTORM_ISCSI_CONN_AG_CTX_CF0_MASK
value|0x3
comment|/* cf0 */
define|#
directive|define
name|E5_MSTORM_ISCSI_CONN_AG_CTX_CF0_SHIFT
value|2
define|#
directive|define
name|E5_MSTORM_ISCSI_CONN_AG_CTX_CF1_MASK
value|0x3
comment|/* cf1 */
define|#
directive|define
name|E5_MSTORM_ISCSI_CONN_AG_CTX_CF1_SHIFT
value|4
define|#
directive|define
name|E5_MSTORM_ISCSI_CONN_AG_CTX_CF2_MASK
value|0x3
comment|/* cf2 */
define|#
directive|define
name|E5_MSTORM_ISCSI_CONN_AG_CTX_CF2_SHIFT
value|6
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E5_MSTORM_ISCSI_CONN_AG_CTX_CF0EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E5_MSTORM_ISCSI_CONN_AG_CTX_CF0EN_SHIFT
value|0
define|#
directive|define
name|E5_MSTORM_ISCSI_CONN_AG_CTX_CF1EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E5_MSTORM_ISCSI_CONN_AG_CTX_CF1EN_SHIFT
value|1
define|#
directive|define
name|E5_MSTORM_ISCSI_CONN_AG_CTX_CF2EN_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E5_MSTORM_ISCSI_CONN_AG_CTX_CF2EN_SHIFT
value|2
define|#
directive|define
name|E5_MSTORM_ISCSI_CONN_AG_CTX_RULE0EN_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E5_MSTORM_ISCSI_CONN_AG_CTX_RULE0EN_SHIFT
value|3
define|#
directive|define
name|E5_MSTORM_ISCSI_CONN_AG_CTX_RULE1EN_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E5_MSTORM_ISCSI_CONN_AG_CTX_RULE1EN_SHIFT
value|4
define|#
directive|define
name|E5_MSTORM_ISCSI_CONN_AG_CTX_RULE2EN_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E5_MSTORM_ISCSI_CONN_AG_CTX_RULE2EN_SHIFT
value|5
define|#
directive|define
name|E5_MSTORM_ISCSI_CONN_AG_CTX_RULE3EN_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E5_MSTORM_ISCSI_CONN_AG_CTX_RULE3EN_SHIFT
value|6
define|#
directive|define
name|E5_MSTORM_ISCSI_CONN_AG_CTX_RULE4EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E5_MSTORM_ISCSI_CONN_AG_CTX_RULE4EN_SHIFT
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
name|e5_tstorm_iscsi_conn_ag_ctx
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
name|E5_TSTORM_ISCSI_CONN_AG_CTX_EXIST_IN_QM0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E5_TSTORM_ISCSI_CONN_AG_CTX_EXIST_IN_QM0_SHIFT
value|0
define|#
directive|define
name|E5_TSTORM_ISCSI_CONN_AG_CTX_BIT1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E5_TSTORM_ISCSI_CONN_AG_CTX_BIT1_SHIFT
value|1
define|#
directive|define
name|E5_TSTORM_ISCSI_CONN_AG_CTX_BIT2_MASK
value|0x1
comment|/* bit2 */
define|#
directive|define
name|E5_TSTORM_ISCSI_CONN_AG_CTX_BIT2_SHIFT
value|2
define|#
directive|define
name|E5_TSTORM_ISCSI_CONN_AG_CTX_BIT3_MASK
value|0x1
comment|/* bit3 */
define|#
directive|define
name|E5_TSTORM_ISCSI_CONN_AG_CTX_BIT3_SHIFT
value|3
define|#
directive|define
name|E5_TSTORM_ISCSI_CONN_AG_CTX_BIT4_MASK
value|0x1
comment|/* bit4 */
define|#
directive|define
name|E5_TSTORM_ISCSI_CONN_AG_CTX_BIT4_SHIFT
value|4
define|#
directive|define
name|E5_TSTORM_ISCSI_CONN_AG_CTX_BIT5_MASK
value|0x1
comment|/* bit5 */
define|#
directive|define
name|E5_TSTORM_ISCSI_CONN_AG_CTX_BIT5_SHIFT
value|5
define|#
directive|define
name|E5_TSTORM_ISCSI_CONN_AG_CTX_CF0_MASK
value|0x3
comment|/* timer0cf */
define|#
directive|define
name|E5_TSTORM_ISCSI_CONN_AG_CTX_CF0_SHIFT
value|6
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E5_TSTORM_ISCSI_CONN_AG_CTX_P2T_FLUSH_CF_MASK
value|0x3
comment|/* timer1cf */
define|#
directive|define
name|E5_TSTORM_ISCSI_CONN_AG_CTX_P2T_FLUSH_CF_SHIFT
value|0
define|#
directive|define
name|E5_TSTORM_ISCSI_CONN_AG_CTX_M2T_FLUSH_CF_MASK
value|0x3
comment|/* timer2cf */
define|#
directive|define
name|E5_TSTORM_ISCSI_CONN_AG_CTX_M2T_FLUSH_CF_SHIFT
value|2
define|#
directive|define
name|E5_TSTORM_ISCSI_CONN_AG_CTX_TIMER_STOP_ALL_MASK
value|0x3
comment|/* timer_stop_all */
define|#
directive|define
name|E5_TSTORM_ISCSI_CONN_AG_CTX_TIMER_STOP_ALL_SHIFT
value|4
define|#
directive|define
name|E5_TSTORM_ISCSI_CONN_AG_CTX_CF4_MASK
value|0x3
comment|/* cf4 */
define|#
directive|define
name|E5_TSTORM_ISCSI_CONN_AG_CTX_CF4_SHIFT
value|6
name|u8
name|flags2
decl_stmt|;
define|#
directive|define
name|E5_TSTORM_ISCSI_CONN_AG_CTX_CF5_MASK
value|0x3
comment|/* cf5 */
define|#
directive|define
name|E5_TSTORM_ISCSI_CONN_AG_CTX_CF5_SHIFT
value|0
define|#
directive|define
name|E5_TSTORM_ISCSI_CONN_AG_CTX_CF6_MASK
value|0x3
comment|/* cf6 */
define|#
directive|define
name|E5_TSTORM_ISCSI_CONN_AG_CTX_CF6_SHIFT
value|2
define|#
directive|define
name|E5_TSTORM_ISCSI_CONN_AG_CTX_CF7_MASK
value|0x3
comment|/* cf7 */
define|#
directive|define
name|E5_TSTORM_ISCSI_CONN_AG_CTX_CF7_SHIFT
value|4
define|#
directive|define
name|E5_TSTORM_ISCSI_CONN_AG_CTX_CF8_MASK
value|0x3
comment|/* cf8 */
define|#
directive|define
name|E5_TSTORM_ISCSI_CONN_AG_CTX_CF8_SHIFT
value|6
name|u8
name|flags3
decl_stmt|;
define|#
directive|define
name|E5_TSTORM_ISCSI_CONN_AG_CTX_FLUSH_Q0_MASK
value|0x3
comment|/* cf9 */
define|#
directive|define
name|E5_TSTORM_ISCSI_CONN_AG_CTX_FLUSH_Q0_SHIFT
value|0
define|#
directive|define
name|E5_TSTORM_ISCSI_CONN_AG_CTX_CF10_MASK
value|0x3
comment|/* cf10 */
define|#
directive|define
name|E5_TSTORM_ISCSI_CONN_AG_CTX_CF10_SHIFT
value|2
define|#
directive|define
name|E5_TSTORM_ISCSI_CONN_AG_CTX_CF0EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E5_TSTORM_ISCSI_CONN_AG_CTX_CF0EN_SHIFT
value|4
define|#
directive|define
name|E5_TSTORM_ISCSI_CONN_AG_CTX_P2T_FLUSH_CF_EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E5_TSTORM_ISCSI_CONN_AG_CTX_P2T_FLUSH_CF_EN_SHIFT
value|5
define|#
directive|define
name|E5_TSTORM_ISCSI_CONN_AG_CTX_M2T_FLUSH_CF_EN_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E5_TSTORM_ISCSI_CONN_AG_CTX_M2T_FLUSH_CF_EN_SHIFT
value|6
define|#
directive|define
name|E5_TSTORM_ISCSI_CONN_AG_CTX_TIMER_STOP_ALL_EN_MASK
value|0x1
comment|/* cf3en */
define|#
directive|define
name|E5_TSTORM_ISCSI_CONN_AG_CTX_TIMER_STOP_ALL_EN_SHIFT
value|7
name|u8
name|flags4
decl_stmt|;
define|#
directive|define
name|E5_TSTORM_ISCSI_CONN_AG_CTX_CF4EN_MASK
value|0x1
comment|/* cf4en */
define|#
directive|define
name|E5_TSTORM_ISCSI_CONN_AG_CTX_CF4EN_SHIFT
value|0
define|#
directive|define
name|E5_TSTORM_ISCSI_CONN_AG_CTX_CF5EN_MASK
value|0x1
comment|/* cf5en */
define|#
directive|define
name|E5_TSTORM_ISCSI_CONN_AG_CTX_CF5EN_SHIFT
value|1
define|#
directive|define
name|E5_TSTORM_ISCSI_CONN_AG_CTX_CF6EN_MASK
value|0x1
comment|/* cf6en */
define|#
directive|define
name|E5_TSTORM_ISCSI_CONN_AG_CTX_CF6EN_SHIFT
value|2
define|#
directive|define
name|E5_TSTORM_ISCSI_CONN_AG_CTX_CF7EN_MASK
value|0x1
comment|/* cf7en */
define|#
directive|define
name|E5_TSTORM_ISCSI_CONN_AG_CTX_CF7EN_SHIFT
value|3
define|#
directive|define
name|E5_TSTORM_ISCSI_CONN_AG_CTX_CF8EN_MASK
value|0x1
comment|/* cf8en */
define|#
directive|define
name|E5_TSTORM_ISCSI_CONN_AG_CTX_CF8EN_SHIFT
value|4
define|#
directive|define
name|E5_TSTORM_ISCSI_CONN_AG_CTX_FLUSH_Q0_EN_MASK
value|0x1
comment|/* cf9en */
define|#
directive|define
name|E5_TSTORM_ISCSI_CONN_AG_CTX_FLUSH_Q0_EN_SHIFT
value|5
define|#
directive|define
name|E5_TSTORM_ISCSI_CONN_AG_CTX_CF10EN_MASK
value|0x1
comment|/* cf10en */
define|#
directive|define
name|E5_TSTORM_ISCSI_CONN_AG_CTX_CF10EN_SHIFT
value|6
define|#
directive|define
name|E5_TSTORM_ISCSI_CONN_AG_CTX_RULE0EN_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E5_TSTORM_ISCSI_CONN_AG_CTX_RULE0EN_SHIFT
value|7
name|u8
name|flags5
decl_stmt|;
define|#
directive|define
name|E5_TSTORM_ISCSI_CONN_AG_CTX_RULE1EN_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E5_TSTORM_ISCSI_CONN_AG_CTX_RULE1EN_SHIFT
value|0
define|#
directive|define
name|E5_TSTORM_ISCSI_CONN_AG_CTX_RULE2EN_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E5_TSTORM_ISCSI_CONN_AG_CTX_RULE2EN_SHIFT
value|1
define|#
directive|define
name|E5_TSTORM_ISCSI_CONN_AG_CTX_RULE3EN_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E5_TSTORM_ISCSI_CONN_AG_CTX_RULE3EN_SHIFT
value|2
define|#
directive|define
name|E5_TSTORM_ISCSI_CONN_AG_CTX_RULE4EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E5_TSTORM_ISCSI_CONN_AG_CTX_RULE4EN_SHIFT
value|3
define|#
directive|define
name|E5_TSTORM_ISCSI_CONN_AG_CTX_RULE5EN_MASK
value|0x1
comment|/* rule5en */
define|#
directive|define
name|E5_TSTORM_ISCSI_CONN_AG_CTX_RULE5EN_SHIFT
value|4
define|#
directive|define
name|E5_TSTORM_ISCSI_CONN_AG_CTX_RULE6EN_MASK
value|0x1
comment|/* rule6en */
define|#
directive|define
name|E5_TSTORM_ISCSI_CONN_AG_CTX_RULE6EN_SHIFT
value|5
define|#
directive|define
name|E5_TSTORM_ISCSI_CONN_AG_CTX_RULE7EN_MASK
value|0x1
comment|/* rule7en */
define|#
directive|define
name|E5_TSTORM_ISCSI_CONN_AG_CTX_RULE7EN_SHIFT
value|6
define|#
directive|define
name|E5_TSTORM_ISCSI_CONN_AG_CTX_RULE8EN_MASK
value|0x1
comment|/* rule8en */
define|#
directive|define
name|E5_TSTORM_ISCSI_CONN_AG_CTX_RULE8EN_SHIFT
value|7
name|u8
name|flags6
decl_stmt|;
define|#
directive|define
name|E5_TSTORM_ISCSI_CONN_AG_CTX_E4_RESERVED1_MASK
value|0x1
comment|/* bit6 */
define|#
directive|define
name|E5_TSTORM_ISCSI_CONN_AG_CTX_E4_RESERVED1_SHIFT
value|0
define|#
directive|define
name|E5_TSTORM_ISCSI_CONN_AG_CTX_E4_RESERVED2_MASK
value|0x1
comment|/* bit7 */
define|#
directive|define
name|E5_TSTORM_ISCSI_CONN_AG_CTX_E4_RESERVED2_SHIFT
value|1
define|#
directive|define
name|E5_TSTORM_ISCSI_CONN_AG_CTX_E4_RESERVED3_MASK
value|0x1
comment|/* bit8 */
define|#
directive|define
name|E5_TSTORM_ISCSI_CONN_AG_CTX_E4_RESERVED3_SHIFT
value|2
define|#
directive|define
name|E5_TSTORM_ISCSI_CONN_AG_CTX_E4_RESERVED4_MASK
value|0x3
comment|/* cf11 */
define|#
directive|define
name|E5_TSTORM_ISCSI_CONN_AG_CTX_E4_RESERVED4_SHIFT
value|3
define|#
directive|define
name|E5_TSTORM_ISCSI_CONN_AG_CTX_E4_RESERVED5_MASK
value|0x1
comment|/* cf11en */
define|#
directive|define
name|E5_TSTORM_ISCSI_CONN_AG_CTX_E4_RESERVED5_SHIFT
value|5
define|#
directive|define
name|E5_TSTORM_ISCSI_CONN_AG_CTX_E4_RESERVED6_MASK
value|0x1
comment|/* rule9en */
define|#
directive|define
name|E5_TSTORM_ISCSI_CONN_AG_CTX_E4_RESERVED6_SHIFT
value|6
define|#
directive|define
name|E5_TSTORM_ISCSI_CONN_AG_CTX_E4_RESERVED7_MASK
value|0x1
comment|/* rule10en */
define|#
directive|define
name|E5_TSTORM_ISCSI_CONN_AG_CTX_E4_RESERVED7_SHIFT
value|7
name|u8
name|cid_offload_cnt
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
block|}
struct|;
end_struct

begin_struct
struct|struct
name|e5_ustorm_iscsi_conn_ag_ctx
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
name|E5_USTORM_ISCSI_CONN_AG_CTX_BIT0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E5_USTORM_ISCSI_CONN_AG_CTX_BIT0_SHIFT
value|0
define|#
directive|define
name|E5_USTORM_ISCSI_CONN_AG_CTX_BIT1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E5_USTORM_ISCSI_CONN_AG_CTX_BIT1_SHIFT
value|1
define|#
directive|define
name|E5_USTORM_ISCSI_CONN_AG_CTX_CF0_MASK
value|0x3
comment|/* timer0cf */
define|#
directive|define
name|E5_USTORM_ISCSI_CONN_AG_CTX_CF0_SHIFT
value|2
define|#
directive|define
name|E5_USTORM_ISCSI_CONN_AG_CTX_CF1_MASK
value|0x3
comment|/* timer1cf */
define|#
directive|define
name|E5_USTORM_ISCSI_CONN_AG_CTX_CF1_SHIFT
value|4
define|#
directive|define
name|E5_USTORM_ISCSI_CONN_AG_CTX_CF2_MASK
value|0x3
comment|/* timer2cf */
define|#
directive|define
name|E5_USTORM_ISCSI_CONN_AG_CTX_CF2_SHIFT
value|6
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E5_USTORM_ISCSI_CONN_AG_CTX_CF3_MASK
value|0x3
comment|/* timer_stop_all */
define|#
directive|define
name|E5_USTORM_ISCSI_CONN_AG_CTX_CF3_SHIFT
value|0
define|#
directive|define
name|E5_USTORM_ISCSI_CONN_AG_CTX_CF4_MASK
value|0x3
comment|/* cf4 */
define|#
directive|define
name|E5_USTORM_ISCSI_CONN_AG_CTX_CF4_SHIFT
value|2
define|#
directive|define
name|E5_USTORM_ISCSI_CONN_AG_CTX_CF5_MASK
value|0x3
comment|/* cf5 */
define|#
directive|define
name|E5_USTORM_ISCSI_CONN_AG_CTX_CF5_SHIFT
value|4
define|#
directive|define
name|E5_USTORM_ISCSI_CONN_AG_CTX_CF6_MASK
value|0x3
comment|/* cf6 */
define|#
directive|define
name|E5_USTORM_ISCSI_CONN_AG_CTX_CF6_SHIFT
value|6
name|u8
name|flags2
decl_stmt|;
define|#
directive|define
name|E5_USTORM_ISCSI_CONN_AG_CTX_CF0EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E5_USTORM_ISCSI_CONN_AG_CTX_CF0EN_SHIFT
value|0
define|#
directive|define
name|E5_USTORM_ISCSI_CONN_AG_CTX_CF1EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E5_USTORM_ISCSI_CONN_AG_CTX_CF1EN_SHIFT
value|1
define|#
directive|define
name|E5_USTORM_ISCSI_CONN_AG_CTX_CF2EN_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E5_USTORM_ISCSI_CONN_AG_CTX_CF2EN_SHIFT
value|2
define|#
directive|define
name|E5_USTORM_ISCSI_CONN_AG_CTX_CF3EN_MASK
value|0x1
comment|/* cf3en */
define|#
directive|define
name|E5_USTORM_ISCSI_CONN_AG_CTX_CF3EN_SHIFT
value|3
define|#
directive|define
name|E5_USTORM_ISCSI_CONN_AG_CTX_CF4EN_MASK
value|0x1
comment|/* cf4en */
define|#
directive|define
name|E5_USTORM_ISCSI_CONN_AG_CTX_CF4EN_SHIFT
value|4
define|#
directive|define
name|E5_USTORM_ISCSI_CONN_AG_CTX_CF5EN_MASK
value|0x1
comment|/* cf5en */
define|#
directive|define
name|E5_USTORM_ISCSI_CONN_AG_CTX_CF5EN_SHIFT
value|5
define|#
directive|define
name|E5_USTORM_ISCSI_CONN_AG_CTX_CF6EN_MASK
value|0x1
comment|/* cf6en */
define|#
directive|define
name|E5_USTORM_ISCSI_CONN_AG_CTX_CF6EN_SHIFT
value|6
define|#
directive|define
name|E5_USTORM_ISCSI_CONN_AG_CTX_RULE0EN_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E5_USTORM_ISCSI_CONN_AG_CTX_RULE0EN_SHIFT
value|7
name|u8
name|flags3
decl_stmt|;
define|#
directive|define
name|E5_USTORM_ISCSI_CONN_AG_CTX_RULE1EN_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E5_USTORM_ISCSI_CONN_AG_CTX_RULE1EN_SHIFT
value|0
define|#
directive|define
name|E5_USTORM_ISCSI_CONN_AG_CTX_RULE2EN_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E5_USTORM_ISCSI_CONN_AG_CTX_RULE2EN_SHIFT
value|1
define|#
directive|define
name|E5_USTORM_ISCSI_CONN_AG_CTX_RULE3EN_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E5_USTORM_ISCSI_CONN_AG_CTX_RULE3EN_SHIFT
value|2
define|#
directive|define
name|E5_USTORM_ISCSI_CONN_AG_CTX_RULE4EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E5_USTORM_ISCSI_CONN_AG_CTX_RULE4EN_SHIFT
value|3
define|#
directive|define
name|E5_USTORM_ISCSI_CONN_AG_CTX_RULE5EN_MASK
value|0x1
comment|/* rule5en */
define|#
directive|define
name|E5_USTORM_ISCSI_CONN_AG_CTX_RULE5EN_SHIFT
value|4
define|#
directive|define
name|E5_USTORM_ISCSI_CONN_AG_CTX_RULE6EN_MASK
value|0x1
comment|/* rule6en */
define|#
directive|define
name|E5_USTORM_ISCSI_CONN_AG_CTX_RULE6EN_SHIFT
value|5
define|#
directive|define
name|E5_USTORM_ISCSI_CONN_AG_CTX_RULE7EN_MASK
value|0x1
comment|/* rule7en */
define|#
directive|define
name|E5_USTORM_ISCSI_CONN_AG_CTX_RULE7EN_SHIFT
value|6
define|#
directive|define
name|E5_USTORM_ISCSI_CONN_AG_CTX_RULE8EN_MASK
value|0x1
comment|/* rule8en */
define|#
directive|define
name|E5_USTORM_ISCSI_CONN_AG_CTX_RULE8EN_SHIFT
value|7
name|u8
name|flags4
decl_stmt|;
define|#
directive|define
name|E5_USTORM_ISCSI_CONN_AG_CTX_E4_RESERVED1_MASK
value|0x1
comment|/* bit2 */
define|#
directive|define
name|E5_USTORM_ISCSI_CONN_AG_CTX_E4_RESERVED1_SHIFT
value|0
define|#
directive|define
name|E5_USTORM_ISCSI_CONN_AG_CTX_E4_RESERVED2_MASK
value|0x1
comment|/* bit3 */
define|#
directive|define
name|E5_USTORM_ISCSI_CONN_AG_CTX_E4_RESERVED2_SHIFT
value|1
define|#
directive|define
name|E5_USTORM_ISCSI_CONN_AG_CTX_E4_RESERVED3_MASK
value|0x3
comment|/* cf7 */
define|#
directive|define
name|E5_USTORM_ISCSI_CONN_AG_CTX_E4_RESERVED3_SHIFT
value|2
define|#
directive|define
name|E5_USTORM_ISCSI_CONN_AG_CTX_E4_RESERVED4_MASK
value|0x3
comment|/* cf8 */
define|#
directive|define
name|E5_USTORM_ISCSI_CONN_AG_CTX_E4_RESERVED4_SHIFT
value|4
define|#
directive|define
name|E5_USTORM_ISCSI_CONN_AG_CTX_E4_RESERVED5_MASK
value|0x1
comment|/* cf7en */
define|#
directive|define
name|E5_USTORM_ISCSI_CONN_AG_CTX_E4_RESERVED5_SHIFT
value|6
define|#
directive|define
name|E5_USTORM_ISCSI_CONN_AG_CTX_E4_RESERVED6_MASK
value|0x1
comment|/* cf8en */
define|#
directive|define
name|E5_USTORM_ISCSI_CONN_AG_CTX_E4_RESERVED6_SHIFT
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
name|e5_xstorm_iscsi_conn_ag_ctx
block|{
name|u8
name|cdu_validation
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
name|E5_XSTORM_ISCSI_CONN_AG_CTX_EXIST_IN_QM0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_EXIST_IN_QM0_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_EXIST_IN_QM1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_EXIST_IN_QM1_SHIFT
value|1
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_RESERVED1_MASK
value|0x1
comment|/* exist_in_qm2 */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_RESERVED1_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_EXIST_IN_QM3_MASK
value|0x1
comment|/* exist_in_qm3 */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_EXIST_IN_QM3_SHIFT
value|3
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_BIT4_MASK
value|0x1
comment|/* bit4 */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_BIT4_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_RESERVED2_MASK
value|0x1
comment|/* cf_array_active */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_RESERVED2_SHIFT
value|5
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_BIT6_MASK
value|0x1
comment|/* bit6 */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_BIT6_SHIFT
value|6
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_BIT7_MASK
value|0x1
comment|/* bit7 */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_BIT7_SHIFT
value|7
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_BIT8_MASK
value|0x1
comment|/* bit8 */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_BIT8_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_BIT9_MASK
value|0x1
comment|/* bit9 */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_BIT9_SHIFT
value|1
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_BIT10_MASK
value|0x1
comment|/* bit10 */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_BIT10_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_BIT11_MASK
value|0x1
comment|/* bit11 */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_BIT11_SHIFT
value|3
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_BIT12_MASK
value|0x1
comment|/* bit12 */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_BIT12_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_BIT13_MASK
value|0x1
comment|/* bit13 */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_BIT13_SHIFT
value|5
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_BIT14_MASK
value|0x1
comment|/* bit14 */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_BIT14_SHIFT
value|6
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_TX_TRUNCATE_MASK
value|0x1
comment|/* bit15 */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_TX_TRUNCATE_SHIFT
value|7
name|u8
name|flags2
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_CF0_MASK
value|0x3
comment|/* timer0cf */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_CF0_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_CF1_MASK
value|0x3
comment|/* timer1cf */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_CF1_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_CF2_MASK
value|0x3
comment|/* timer2cf */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_CF2_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_TIMER_STOP_ALL_MASK
value|0x3
comment|/* timer_stop_all */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_TIMER_STOP_ALL_SHIFT
value|6
name|u8
name|flags3
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_CF4_MASK
value|0x3
comment|/* cf4 */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_CF4_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_CF5_MASK
value|0x3
comment|/* cf5 */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_CF5_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_CF6_MASK
value|0x3
comment|/* cf6 */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_CF6_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_CF7_MASK
value|0x3
comment|/* cf7 */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_CF7_SHIFT
value|6
name|u8
name|flags4
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_CF8_MASK
value|0x3
comment|/* cf8 */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_CF8_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_CF9_MASK
value|0x3
comment|/* cf9 */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_CF9_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_CF10_MASK
value|0x3
comment|/* cf10 */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_CF10_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_CF11_MASK
value|0x3
comment|/* cf11 */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_CF11_SHIFT
value|6
name|u8
name|flags5
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_CF12_MASK
value|0x3
comment|/* cf12 */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_CF12_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_CF13_MASK
value|0x3
comment|/* cf13 */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_CF13_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_CF14_MASK
value|0x3
comment|/* cf14 */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_CF14_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_UPDATE_STATE_TO_BASE_CF_MASK
value|0x3
comment|/* cf15 */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_UPDATE_STATE_TO_BASE_CF_SHIFT
value|6
name|u8
name|flags6
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_CF16_MASK
value|0x3
comment|/* cf16 */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_CF16_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_CF17_MASK
value|0x3
comment|/* cf_array_cf */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_CF17_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_CF18_MASK
value|0x3
comment|/* cf18 */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_CF18_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_DQ_FLUSH_MASK
value|0x3
comment|/* cf19 */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_DQ_FLUSH_SHIFT
value|6
name|u8
name|flags7
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_MST_XCM_Q0_FLUSH_CF_MASK
value|0x3
comment|/* cf20 */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_MST_XCM_Q0_FLUSH_CF_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_UST_XCM_Q1_FLUSH_CF_MASK
value|0x3
comment|/* cf21 */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_UST_XCM_Q1_FLUSH_CF_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_SLOW_PATH_MASK
value|0x3
comment|/* cf22 */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_SLOW_PATH_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_CF0EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_CF0EN_SHIFT
value|6
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_CF1EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_CF1EN_SHIFT
value|7
name|u8
name|flags8
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_CF2EN_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_CF2EN_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_TIMER_STOP_ALL_EN_MASK
value|0x1
comment|/* cf3en */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_TIMER_STOP_ALL_EN_SHIFT
value|1
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_CF4EN_MASK
value|0x1
comment|/* cf4en */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_CF4EN_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_CF5EN_MASK
value|0x1
comment|/* cf5en */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_CF5EN_SHIFT
value|3
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_CF6EN_MASK
value|0x1
comment|/* cf6en */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_CF6EN_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_CF7EN_MASK
value|0x1
comment|/* cf7en */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_CF7EN_SHIFT
value|5
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_CF8EN_MASK
value|0x1
comment|/* cf8en */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_CF8EN_SHIFT
value|6
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_CF9EN_MASK
value|0x1
comment|/* cf9en */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_CF9EN_SHIFT
value|7
name|u8
name|flags9
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_CF10EN_MASK
value|0x1
comment|/* cf10en */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_CF10EN_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_CF11EN_MASK
value|0x1
comment|/* cf11en */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_CF11EN_SHIFT
value|1
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_CF12EN_MASK
value|0x1
comment|/* cf12en */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_CF12EN_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_CF13EN_MASK
value|0x1
comment|/* cf13en */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_CF13EN_SHIFT
value|3
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_CF14EN_MASK
value|0x1
comment|/* cf14en */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_CF14EN_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_UPDATE_STATE_TO_BASE_CF_EN_MASK
value|0x1
comment|/* cf15en */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_UPDATE_STATE_TO_BASE_CF_EN_SHIFT
value|5
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_CF16EN_MASK
value|0x1
comment|/* cf16en */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_CF16EN_SHIFT
value|6
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_CF17EN_MASK
value|0x1
comment|/* cf_array_cf_en */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_CF17EN_SHIFT
value|7
name|u8
name|flags10
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_CF18EN_MASK
value|0x1
comment|/* cf18en */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_CF18EN_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_DQ_FLUSH_EN_MASK
value|0x1
comment|/* cf19en */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_DQ_FLUSH_EN_SHIFT
value|1
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_MST_XCM_Q0_FLUSH_CF_EN_MASK
value|0x1
comment|/* cf20en */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_MST_XCM_Q0_FLUSH_CF_EN_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_UST_XCM_Q1_FLUSH_CF_EN_MASK
value|0x1
comment|/* cf21en */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_UST_XCM_Q1_FLUSH_CF_EN_SHIFT
value|3
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_SLOW_PATH_EN_MASK
value|0x1
comment|/* cf22en */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_SLOW_PATH_EN_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_PROC_ONLY_CLEANUP_EN_MASK
value|0x1
comment|/* cf23en */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_PROC_ONLY_CLEANUP_EN_SHIFT
value|5
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_RULE0EN_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_RULE0EN_SHIFT
value|6
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_MORE_TO_SEND_DEC_RULE_EN_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_MORE_TO_SEND_DEC_RULE_EN_SHIFT
value|7
name|u8
name|flags11
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_TX_BLOCKED_EN_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_TX_BLOCKED_EN_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_RULE3EN_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_RULE3EN_SHIFT
value|1
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_RESERVED3_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_RESERVED3_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_RULE5EN_MASK
value|0x1
comment|/* rule5en */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_RULE5EN_SHIFT
value|3
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_RULE6EN_MASK
value|0x1
comment|/* rule6en */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_RULE6EN_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_RULE7EN_MASK
value|0x1
comment|/* rule7en */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_RULE7EN_SHIFT
value|5
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_A0_RESERVED1_MASK
value|0x1
comment|/* rule8en */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_A0_RESERVED1_SHIFT
value|6
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_RULE9EN_MASK
value|0x1
comment|/* rule9en */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_RULE9EN_SHIFT
value|7
name|u8
name|flags12
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_SQ_DEC_RULE_EN_MASK
value|0x1
comment|/* rule10en */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_SQ_DEC_RULE_EN_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_RULE11EN_MASK
value|0x1
comment|/* rule11en */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_RULE11EN_SHIFT
value|1
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_A0_RESERVED2_MASK
value|0x1
comment|/* rule12en */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_A0_RESERVED2_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_A0_RESERVED3_MASK
value|0x1
comment|/* rule13en */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_A0_RESERVED3_SHIFT
value|3
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_RULE14EN_MASK
value|0x1
comment|/* rule14en */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_RULE14EN_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_RULE15EN_MASK
value|0x1
comment|/* rule15en */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_RULE15EN_SHIFT
value|5
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_RULE16EN_MASK
value|0x1
comment|/* rule16en */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_RULE16EN_SHIFT
value|6
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_RULE17EN_MASK
value|0x1
comment|/* rule17en */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_RULE17EN_SHIFT
value|7
name|u8
name|flags13
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_R2TQ_DEC_RULE_EN_MASK
value|0x1
comment|/* rule18en */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_R2TQ_DEC_RULE_EN_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_HQ_DEC_RULE_EN_MASK
value|0x1
comment|/* rule19en */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_HQ_DEC_RULE_EN_SHIFT
value|1
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_A0_RESERVED4_MASK
value|0x1
comment|/* rule20en */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_A0_RESERVED4_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_A0_RESERVED5_MASK
value|0x1
comment|/* rule21en */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_A0_RESERVED5_SHIFT
value|3
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_A0_RESERVED6_MASK
value|0x1
comment|/* rule22en */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_A0_RESERVED6_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_A0_RESERVED7_MASK
value|0x1
comment|/* rule23en */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_A0_RESERVED7_SHIFT
value|5
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_A0_RESERVED8_MASK
value|0x1
comment|/* rule24en */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_A0_RESERVED8_SHIFT
value|6
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_A0_RESERVED9_MASK
value|0x1
comment|/* rule25en */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_A0_RESERVED9_SHIFT
value|7
name|u8
name|flags14
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_BIT16_MASK
value|0x1
comment|/* bit16 */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_BIT16_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_BIT17_MASK
value|0x1
comment|/* bit17 */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_BIT17_SHIFT
value|1
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_BIT18_MASK
value|0x1
comment|/* bit18 */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_BIT18_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_BIT19_MASK
value|0x1
comment|/* bit19 */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_BIT19_SHIFT
value|3
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_BIT20_MASK
value|0x1
comment|/* bit20 */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_BIT20_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_DUMMY_READ_DONE_MASK
value|0x1
comment|/* bit21 */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_DUMMY_READ_DONE_SHIFT
value|5
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_PROC_ONLY_CLEANUP_MASK
value|0x3
comment|/* cf23 */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_PROC_ONLY_CLEANUP_SHIFT
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
name|physical_q1
comment|/* physical_q1 */
decl_stmt|;
name|__le16
name|dummy_dorq_var
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
name|word5
comment|/* word5 */
decl_stmt|;
name|__le16
name|slow_io_total_data_tx_update
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
name|more_to_send_seq
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
name|hq_scan_next_relevant_ack
comment|/* cf_array1 */
decl_stmt|;
name|u8
name|flags15
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_E4_RESERVED1_MASK
value|0x1
comment|/* bit22 */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_E4_RESERVED1_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_E4_RESERVED2_MASK
value|0x1
comment|/* bit23 */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_E4_RESERVED2_SHIFT
value|1
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_E4_RESERVED3_MASK
value|0x1
comment|/* bit24 */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_E4_RESERVED3_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_E4_RESERVED4_MASK
value|0x3
comment|/* cf24 */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_E4_RESERVED4_SHIFT
value|3
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_E4_RESERVED5_MASK
value|0x1
comment|/* cf24en */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_E4_RESERVED5_SHIFT
value|5
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_E4_RESERVED6_MASK
value|0x1
comment|/* rule26en */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_E4_RESERVED6_SHIFT
value|6
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_E4_RESERVED7_MASK
value|0x1
comment|/* rule27en */
define|#
directive|define
name|E5_XSTORM_ISCSI_CONN_AG_CTX_E4_RESERVED7_SHIFT
value|7
name|u8
name|byte7
comment|/* byte7 */
decl_stmt|;
name|__le16
name|r2tq_prod
comment|/* word7 */
decl_stmt|;
name|__le16
name|r2tq_cons
comment|/* word8 */
decl_stmt|;
name|__le16
name|hq_prod
comment|/* word9 */
decl_stmt|;
name|__le16
name|hq_cons
comment|/* word10 */
decl_stmt|;
name|__le16
name|word11
comment|/* word11 */
decl_stmt|;
name|__le32
name|remain_seq
comment|/* reg7 */
decl_stmt|;
name|__le32
name|bytes_to_next_pdu
comment|/* reg8 */
decl_stmt|;
name|__le32
name|hq_tcp_seq
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
name|ongoing_fast_rxmit_seq
comment|/* reg13 */
decl_stmt|;
name|__le32
name|exp_stat_sn
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
block|}
struct|;
end_struct

begin_struct
struct|struct
name|e5_ystorm_iscsi_conn_ag_ctx
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
name|E5_YSTORM_ISCSI_CONN_AG_CTX_BIT0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E5_YSTORM_ISCSI_CONN_AG_CTX_BIT0_SHIFT
value|0
define|#
directive|define
name|E5_YSTORM_ISCSI_CONN_AG_CTX_BIT1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E5_YSTORM_ISCSI_CONN_AG_CTX_BIT1_SHIFT
value|1
define|#
directive|define
name|E5_YSTORM_ISCSI_CONN_AG_CTX_CF0_MASK
value|0x3
comment|/* cf0 */
define|#
directive|define
name|E5_YSTORM_ISCSI_CONN_AG_CTX_CF0_SHIFT
value|2
define|#
directive|define
name|E5_YSTORM_ISCSI_CONN_AG_CTX_CF1_MASK
value|0x3
comment|/* cf1 */
define|#
directive|define
name|E5_YSTORM_ISCSI_CONN_AG_CTX_CF1_SHIFT
value|4
define|#
directive|define
name|E5_YSTORM_ISCSI_CONN_AG_CTX_CF2_MASK
value|0x3
comment|/* cf2 */
define|#
directive|define
name|E5_YSTORM_ISCSI_CONN_AG_CTX_CF2_SHIFT
value|6
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E5_YSTORM_ISCSI_CONN_AG_CTX_CF0EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E5_YSTORM_ISCSI_CONN_AG_CTX_CF0EN_SHIFT
value|0
define|#
directive|define
name|E5_YSTORM_ISCSI_CONN_AG_CTX_CF1EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E5_YSTORM_ISCSI_CONN_AG_CTX_CF1EN_SHIFT
value|1
define|#
directive|define
name|E5_YSTORM_ISCSI_CONN_AG_CTX_CF2EN_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E5_YSTORM_ISCSI_CONN_AG_CTX_CF2EN_SHIFT
value|2
define|#
directive|define
name|E5_YSTORM_ISCSI_CONN_AG_CTX_RULE0EN_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E5_YSTORM_ISCSI_CONN_AG_CTX_RULE0EN_SHIFT
value|3
define|#
directive|define
name|E5_YSTORM_ISCSI_CONN_AG_CTX_RULE1EN_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E5_YSTORM_ISCSI_CONN_AG_CTX_RULE1EN_SHIFT
value|4
define|#
directive|define
name|E5_YSTORM_ISCSI_CONN_AG_CTX_RULE2EN_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E5_YSTORM_ISCSI_CONN_AG_CTX_RULE2EN_SHIFT
value|5
define|#
directive|define
name|E5_YSTORM_ISCSI_CONN_AG_CTX_RULE3EN_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E5_YSTORM_ISCSI_CONN_AG_CTX_RULE3EN_SHIFT
value|6
define|#
directive|define
name|E5_YSTORM_ISCSI_CONN_AG_CTX_RULE4EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E5_YSTORM_ISCSI_CONN_AG_CTX_RULE4EN_SHIFT
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
comment|/* __ECORE_HSI_ISCSI__ */
end_comment

end_unit

