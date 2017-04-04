begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2017-2018 Cavium, Inc.   * All rights reserved.  *  *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *  *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *  *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  *  POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ECORE_HSI_ETH__
end_ifndef

begin_define
define|#
directive|define
name|__ECORE_HSI_ETH__
end_define

begin_comment
comment|/************************************************************************/
end_comment

begin_comment
comment|/* Add include to common eth target for both eCore and protocol driver */
end_comment

begin_comment
comment|/************************************************************************/
end_comment

begin_include
include|#
directive|include
file|"eth_common.h"
end_include

begin_comment
comment|/*  * The eth storm context for the Tstorm  */
end_comment

begin_struct
struct|struct
name|tstorm_eth_conn_st_ctx
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
comment|/*  * The eth storm context for the Pstorm  */
end_comment

begin_struct
struct|struct
name|pstorm_eth_conn_st_ctx
block|{
name|__le32
name|reserved
index|[
literal|8
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The eth storm context for the Xstorm  */
end_comment

begin_struct
struct|struct
name|xstorm_eth_conn_st_ctx
block|{
name|__le32
name|reserved
index|[
literal|60
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|e4_xstorm_eth_conn_ag_ctx
block|{
name|u8
name|reserved0
comment|/* cdu_validation */
decl_stmt|;
name|u8
name|eth_state
comment|/* state */
decl_stmt|;
name|u8
name|flags0
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_EXIST_IN_QM0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_EXIST_IN_QM0_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_RESERVED1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_RESERVED1_SHIFT
value|1
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_RESERVED2_MASK
value|0x1
comment|/* exist_in_qm2 */
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_RESERVED2_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_EXIST_IN_QM3_MASK
value|0x1
comment|/* exist_in_qm3 */
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_EXIST_IN_QM3_SHIFT
value|3
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_RESERVED3_MASK
value|0x1
comment|/* bit4 */
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_RESERVED3_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_RESERVED4_MASK
value|0x1
comment|/* cf_array_active */
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_RESERVED4_SHIFT
value|5
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_RESERVED5_MASK
value|0x1
comment|/* bit6 */
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_RESERVED5_SHIFT
value|6
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_RESERVED6_MASK
value|0x1
comment|/* bit7 */
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_RESERVED6_SHIFT
value|7
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_RESERVED7_MASK
value|0x1
comment|/* bit8 */
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_RESERVED7_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_RESERVED8_MASK
value|0x1
comment|/* bit9 */
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_RESERVED8_SHIFT
value|1
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_RESERVED9_MASK
value|0x1
comment|/* bit10 */
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_RESERVED9_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_BIT11_MASK
value|0x1
comment|/* bit11 */
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_BIT11_SHIFT
value|3
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_BIT12_MASK
value|0x1
comment|/* bit12 */
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_BIT12_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_BIT13_MASK
value|0x1
comment|/* bit13 */
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_BIT13_SHIFT
value|5
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_TX_RULE_ACTIVE_MASK
value|0x1
comment|/* bit14 */
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_TX_RULE_ACTIVE_SHIFT
value|6
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_DQ_CF_ACTIVE_MASK
value|0x1
comment|/* bit15 */
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_DQ_CF_ACTIVE_SHIFT
value|7
name|u8
name|flags2
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_CF0_MASK
value|0x3
comment|/* timer0cf */
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_CF0_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_CF1_MASK
value|0x3
comment|/* timer1cf */
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_CF1_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_CF2_MASK
value|0x3
comment|/* timer2cf */
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_CF2_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_CF3_MASK
value|0x3
comment|/* timer_stop_all */
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_CF3_SHIFT
value|6
name|u8
name|flags3
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_CF4_MASK
value|0x3
comment|/* cf4 */
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_CF4_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_CF5_MASK
value|0x3
comment|/* cf5 */
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_CF5_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_CF6_MASK
value|0x3
comment|/* cf6 */
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_CF6_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_CF7_MASK
value|0x3
comment|/* cf7 */
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_CF7_SHIFT
value|6
name|u8
name|flags4
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_CF8_MASK
value|0x3
comment|/* cf8 */
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_CF8_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_CF9_MASK
value|0x3
comment|/* cf9 */
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_CF9_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_CF10_MASK
value|0x3
comment|/* cf10 */
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_CF10_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_CF11_MASK
value|0x3
comment|/* cf11 */
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_CF11_SHIFT
value|6
name|u8
name|flags5
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_CF12_MASK
value|0x3
comment|/* cf12 */
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_CF12_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_CF13_MASK
value|0x3
comment|/* cf13 */
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_CF13_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_CF14_MASK
value|0x3
comment|/* cf14 */
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_CF14_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_CF15_MASK
value|0x3
comment|/* cf15 */
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_CF15_SHIFT
value|6
name|u8
name|flags6
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_GO_TO_BD_CONS_CF_MASK
value|0x3
comment|/* cf16 */
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_GO_TO_BD_CONS_CF_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_MULTI_UNICAST_CF_MASK
value|0x3
comment|/* cf_array_cf */
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_MULTI_UNICAST_CF_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_DQ_CF_MASK
value|0x3
comment|/* cf18 */
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_DQ_CF_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_TERMINATE_CF_MASK
value|0x3
comment|/* cf19 */
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_TERMINATE_CF_SHIFT
value|6
name|u8
name|flags7
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_FLUSH_Q0_MASK
value|0x3
comment|/* cf20 */
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_FLUSH_Q0_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_RESERVED10_MASK
value|0x3
comment|/* cf21 */
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_RESERVED10_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_SLOW_PATH_MASK
value|0x3
comment|/* cf22 */
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_SLOW_PATH_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_CF0EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_CF0EN_SHIFT
value|6
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_CF1EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_CF1EN_SHIFT
value|7
name|u8
name|flags8
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_CF2EN_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_CF2EN_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_CF3EN_MASK
value|0x1
comment|/* cf3en */
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_CF3EN_SHIFT
value|1
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_CF4EN_MASK
value|0x1
comment|/* cf4en */
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_CF4EN_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_CF5EN_MASK
value|0x1
comment|/* cf5en */
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_CF5EN_SHIFT
value|3
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_CF6EN_MASK
value|0x1
comment|/* cf6en */
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_CF6EN_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_CF7EN_MASK
value|0x1
comment|/* cf7en */
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_CF7EN_SHIFT
value|5
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_CF8EN_MASK
value|0x1
comment|/* cf8en */
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_CF8EN_SHIFT
value|6
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_CF9EN_MASK
value|0x1
comment|/* cf9en */
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_CF9EN_SHIFT
value|7
name|u8
name|flags9
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_CF10EN_MASK
value|0x1
comment|/* cf10en */
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_CF10EN_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_CF11EN_MASK
value|0x1
comment|/* cf11en */
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_CF11EN_SHIFT
value|1
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_CF12EN_MASK
value|0x1
comment|/* cf12en */
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_CF12EN_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_CF13EN_MASK
value|0x1
comment|/* cf13en */
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_CF13EN_SHIFT
value|3
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_CF14EN_MASK
value|0x1
comment|/* cf14en */
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_CF14EN_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_CF15EN_MASK
value|0x1
comment|/* cf15en */
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_CF15EN_SHIFT
value|5
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_GO_TO_BD_CONS_CF_EN_MASK
value|0x1
comment|/* cf16en */
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_GO_TO_BD_CONS_CF_EN_SHIFT
value|6
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_MULTI_UNICAST_CF_EN_MASK
value|0x1
comment|/* cf_array_cf_en */
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_MULTI_UNICAST_CF_EN_SHIFT
value|7
name|u8
name|flags10
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_DQ_CF_EN_MASK
value|0x1
comment|/* cf18en */
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_DQ_CF_EN_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_TERMINATE_CF_EN_MASK
value|0x1
comment|/* cf19en */
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_TERMINATE_CF_EN_SHIFT
value|1
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_FLUSH_Q0_EN_MASK
value|0x1
comment|/* cf20en */
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_FLUSH_Q0_EN_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_RESERVED11_MASK
value|0x1
comment|/* cf21en */
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_RESERVED11_SHIFT
value|3
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_SLOW_PATH_EN_MASK
value|0x1
comment|/* cf22en */
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_SLOW_PATH_EN_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_TPH_ENABLE_EN_RESERVED_MASK
value|0x1
comment|/* cf23en */
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_TPH_ENABLE_EN_RESERVED_SHIFT
value|5
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_RESERVED12_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_RESERVED12_SHIFT
value|6
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_RESERVED13_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_RESERVED13_SHIFT
value|7
name|u8
name|flags11
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_RESERVED14_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_RESERVED14_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_RESERVED15_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_RESERVED15_SHIFT
value|1
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_TX_DEC_RULE_EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_TX_DEC_RULE_EN_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_RULE5EN_MASK
value|0x1
comment|/* rule5en */
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_RULE5EN_SHIFT
value|3
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_RULE6EN_MASK
value|0x1
comment|/* rule6en */
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_RULE6EN_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_RULE7EN_MASK
value|0x1
comment|/* rule7en */
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_RULE7EN_SHIFT
value|5
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_A0_RESERVED1_MASK
value|0x1
comment|/* rule8en */
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_A0_RESERVED1_SHIFT
value|6
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_RULE9EN_MASK
value|0x1
comment|/* rule9en */
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_RULE9EN_SHIFT
value|7
name|u8
name|flags12
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_RULE10EN_MASK
value|0x1
comment|/* rule10en */
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_RULE10EN_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_RULE11EN_MASK
value|0x1
comment|/* rule11en */
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_RULE11EN_SHIFT
value|1
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_A0_RESERVED2_MASK
value|0x1
comment|/* rule12en */
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_A0_RESERVED2_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_A0_RESERVED3_MASK
value|0x1
comment|/* rule13en */
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_A0_RESERVED3_SHIFT
value|3
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_RULE14EN_MASK
value|0x1
comment|/* rule14en */
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_RULE14EN_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_RULE15EN_MASK
value|0x1
comment|/* rule15en */
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_RULE15EN_SHIFT
value|5
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_RULE16EN_MASK
value|0x1
comment|/* rule16en */
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_RULE16EN_SHIFT
value|6
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_RULE17EN_MASK
value|0x1
comment|/* rule17en */
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_RULE17EN_SHIFT
value|7
name|u8
name|flags13
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_RULE18EN_MASK
value|0x1
comment|/* rule18en */
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_RULE18EN_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_RULE19EN_MASK
value|0x1
comment|/* rule19en */
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_RULE19EN_SHIFT
value|1
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_A0_RESERVED4_MASK
value|0x1
comment|/* rule20en */
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_A0_RESERVED4_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_A0_RESERVED5_MASK
value|0x1
comment|/* rule21en */
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_A0_RESERVED5_SHIFT
value|3
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_A0_RESERVED6_MASK
value|0x1
comment|/* rule22en */
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_A0_RESERVED6_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_A0_RESERVED7_MASK
value|0x1
comment|/* rule23en */
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_A0_RESERVED7_SHIFT
value|5
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_A0_RESERVED8_MASK
value|0x1
comment|/* rule24en */
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_A0_RESERVED8_SHIFT
value|6
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_A0_RESERVED9_MASK
value|0x1
comment|/* rule25en */
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_A0_RESERVED9_SHIFT
value|7
name|u8
name|flags14
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_EDPM_USE_EXT_HDR_MASK
value|0x1
comment|/* bit16 */
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_EDPM_USE_EXT_HDR_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_EDPM_SEND_RAW_L3L4_MASK
value|0x1
comment|/* bit17 */
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_EDPM_SEND_RAW_L3L4_SHIFT
value|1
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_EDPM_INBAND_PROP_HDR_MASK
value|0x1
comment|/* bit18 */
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_EDPM_INBAND_PROP_HDR_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_EDPM_SEND_EXT_TUNNEL_MASK
value|0x1
comment|/* bit19 */
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_EDPM_SEND_EXT_TUNNEL_SHIFT
value|3
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_L2_EDPM_ENABLE_MASK
value|0x1
comment|/* bit20 */
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_L2_EDPM_ENABLE_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_ROCE_EDPM_ENABLE_MASK
value|0x1
comment|/* bit21 */
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_ROCE_EDPM_ENABLE_SHIFT
value|5
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_TPH_ENABLE_MASK
value|0x3
comment|/* cf23 */
define|#
directive|define
name|E4_XSTORM_ETH_CONN_AG_CTX_TPH_ENABLE_SHIFT
value|6
name|u8
name|edpm_event_id
comment|/* byte2 */
decl_stmt|;
name|__le16
name|physical_q0
comment|/* physical_q0 */
decl_stmt|;
name|__le16
name|e5_reserved1
comment|/* physical_q1 */
decl_stmt|;
name|__le16
name|edpm_num_bds
comment|/* physical_q2 */
decl_stmt|;
name|__le16
name|tx_bd_cons
comment|/* word3 */
decl_stmt|;
name|__le16
name|tx_bd_prod
comment|/* word4 */
decl_stmt|;
name|__le16
name|tx_class
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

begin_comment
comment|/*  * The eth storm context for the Ystorm  */
end_comment

begin_struct
struct|struct
name|ystorm_eth_conn_st_ctx
block|{
name|__le32
name|reserved
index|[
literal|8
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|e4_ystorm_eth_conn_ag_ctx
block|{
name|u8
name|byte0
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
name|E4_YSTORM_ETH_CONN_AG_CTX_BIT0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E4_YSTORM_ETH_CONN_AG_CTX_BIT0_SHIFT
value|0
define|#
directive|define
name|E4_YSTORM_ETH_CONN_AG_CTX_BIT1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E4_YSTORM_ETH_CONN_AG_CTX_BIT1_SHIFT
value|1
define|#
directive|define
name|E4_YSTORM_ETH_CONN_AG_CTX_TX_BD_CONS_UPD_CF_MASK
value|0x3
comment|/* cf0 */
define|#
directive|define
name|E4_YSTORM_ETH_CONN_AG_CTX_TX_BD_CONS_UPD_CF_SHIFT
value|2
define|#
directive|define
name|E4_YSTORM_ETH_CONN_AG_CTX_PMD_TERMINATE_CF_MASK
value|0x3
comment|/* cf1 */
define|#
directive|define
name|E4_YSTORM_ETH_CONN_AG_CTX_PMD_TERMINATE_CF_SHIFT
value|4
define|#
directive|define
name|E4_YSTORM_ETH_CONN_AG_CTX_CF2_MASK
value|0x3
comment|/* cf2 */
define|#
directive|define
name|E4_YSTORM_ETH_CONN_AG_CTX_CF2_SHIFT
value|6
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E4_YSTORM_ETH_CONN_AG_CTX_TX_BD_CONS_UPD_CF_EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E4_YSTORM_ETH_CONN_AG_CTX_TX_BD_CONS_UPD_CF_EN_SHIFT
value|0
define|#
directive|define
name|E4_YSTORM_ETH_CONN_AG_CTX_PMD_TERMINATE_CF_EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E4_YSTORM_ETH_CONN_AG_CTX_PMD_TERMINATE_CF_EN_SHIFT
value|1
define|#
directive|define
name|E4_YSTORM_ETH_CONN_AG_CTX_CF2EN_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E4_YSTORM_ETH_CONN_AG_CTX_CF2EN_SHIFT
value|2
define|#
directive|define
name|E4_YSTORM_ETH_CONN_AG_CTX_RULE0EN_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E4_YSTORM_ETH_CONN_AG_CTX_RULE0EN_SHIFT
value|3
define|#
directive|define
name|E4_YSTORM_ETH_CONN_AG_CTX_RULE1EN_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E4_YSTORM_ETH_CONN_AG_CTX_RULE1EN_SHIFT
value|4
define|#
directive|define
name|E4_YSTORM_ETH_CONN_AG_CTX_RULE2EN_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E4_YSTORM_ETH_CONN_AG_CTX_RULE2EN_SHIFT
value|5
define|#
directive|define
name|E4_YSTORM_ETH_CONN_AG_CTX_RULE3EN_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E4_YSTORM_ETH_CONN_AG_CTX_RULE3EN_SHIFT
value|6
define|#
directive|define
name|E4_YSTORM_ETH_CONN_AG_CTX_RULE4EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E4_YSTORM_ETH_CONN_AG_CTX_RULE4EN_SHIFT
value|7
name|u8
name|tx_q0_int_coallecing_timeset
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
name|terminate_spqe
comment|/* reg0 */
decl_stmt|;
name|__le32
name|reg1
comment|/* reg1 */
decl_stmt|;
name|__le16
name|tx_bd_cons_upd
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
name|e4_tstorm_eth_conn_ag_ctx
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
name|E4_TSTORM_ETH_CONN_AG_CTX_BIT0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E4_TSTORM_ETH_CONN_AG_CTX_BIT0_SHIFT
value|0
define|#
directive|define
name|E4_TSTORM_ETH_CONN_AG_CTX_BIT1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E4_TSTORM_ETH_CONN_AG_CTX_BIT1_SHIFT
value|1
define|#
directive|define
name|E4_TSTORM_ETH_CONN_AG_CTX_BIT2_MASK
value|0x1
comment|/* bit2 */
define|#
directive|define
name|E4_TSTORM_ETH_CONN_AG_CTX_BIT2_SHIFT
value|2
define|#
directive|define
name|E4_TSTORM_ETH_CONN_AG_CTX_BIT3_MASK
value|0x1
comment|/* bit3 */
define|#
directive|define
name|E4_TSTORM_ETH_CONN_AG_CTX_BIT3_SHIFT
value|3
define|#
directive|define
name|E4_TSTORM_ETH_CONN_AG_CTX_BIT4_MASK
value|0x1
comment|/* bit4 */
define|#
directive|define
name|E4_TSTORM_ETH_CONN_AG_CTX_BIT4_SHIFT
value|4
define|#
directive|define
name|E4_TSTORM_ETH_CONN_AG_CTX_BIT5_MASK
value|0x1
comment|/* bit5 */
define|#
directive|define
name|E4_TSTORM_ETH_CONN_AG_CTX_BIT5_SHIFT
value|5
define|#
directive|define
name|E4_TSTORM_ETH_CONN_AG_CTX_CF0_MASK
value|0x3
comment|/* timer0cf */
define|#
directive|define
name|E4_TSTORM_ETH_CONN_AG_CTX_CF0_SHIFT
value|6
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E4_TSTORM_ETH_CONN_AG_CTX_CF1_MASK
value|0x3
comment|/* timer1cf */
define|#
directive|define
name|E4_TSTORM_ETH_CONN_AG_CTX_CF1_SHIFT
value|0
define|#
directive|define
name|E4_TSTORM_ETH_CONN_AG_CTX_CF2_MASK
value|0x3
comment|/* timer2cf */
define|#
directive|define
name|E4_TSTORM_ETH_CONN_AG_CTX_CF2_SHIFT
value|2
define|#
directive|define
name|E4_TSTORM_ETH_CONN_AG_CTX_CF3_MASK
value|0x3
comment|/* timer_stop_all */
define|#
directive|define
name|E4_TSTORM_ETH_CONN_AG_CTX_CF3_SHIFT
value|4
define|#
directive|define
name|E4_TSTORM_ETH_CONN_AG_CTX_CF4_MASK
value|0x3
comment|/* cf4 */
define|#
directive|define
name|E4_TSTORM_ETH_CONN_AG_CTX_CF4_SHIFT
value|6
name|u8
name|flags2
decl_stmt|;
define|#
directive|define
name|E4_TSTORM_ETH_CONN_AG_CTX_CF5_MASK
value|0x3
comment|/* cf5 */
define|#
directive|define
name|E4_TSTORM_ETH_CONN_AG_CTX_CF5_SHIFT
value|0
define|#
directive|define
name|E4_TSTORM_ETH_CONN_AG_CTX_CF6_MASK
value|0x3
comment|/* cf6 */
define|#
directive|define
name|E4_TSTORM_ETH_CONN_AG_CTX_CF6_SHIFT
value|2
define|#
directive|define
name|E4_TSTORM_ETH_CONN_AG_CTX_CF7_MASK
value|0x3
comment|/* cf7 */
define|#
directive|define
name|E4_TSTORM_ETH_CONN_AG_CTX_CF7_SHIFT
value|4
define|#
directive|define
name|E4_TSTORM_ETH_CONN_AG_CTX_CF8_MASK
value|0x3
comment|/* cf8 */
define|#
directive|define
name|E4_TSTORM_ETH_CONN_AG_CTX_CF8_SHIFT
value|6
name|u8
name|flags3
decl_stmt|;
define|#
directive|define
name|E4_TSTORM_ETH_CONN_AG_CTX_CF9_MASK
value|0x3
comment|/* cf9 */
define|#
directive|define
name|E4_TSTORM_ETH_CONN_AG_CTX_CF9_SHIFT
value|0
define|#
directive|define
name|E4_TSTORM_ETH_CONN_AG_CTX_CF10_MASK
value|0x3
comment|/* cf10 */
define|#
directive|define
name|E4_TSTORM_ETH_CONN_AG_CTX_CF10_SHIFT
value|2
define|#
directive|define
name|E4_TSTORM_ETH_CONN_AG_CTX_CF0EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E4_TSTORM_ETH_CONN_AG_CTX_CF0EN_SHIFT
value|4
define|#
directive|define
name|E4_TSTORM_ETH_CONN_AG_CTX_CF1EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E4_TSTORM_ETH_CONN_AG_CTX_CF1EN_SHIFT
value|5
define|#
directive|define
name|E4_TSTORM_ETH_CONN_AG_CTX_CF2EN_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E4_TSTORM_ETH_CONN_AG_CTX_CF2EN_SHIFT
value|6
define|#
directive|define
name|E4_TSTORM_ETH_CONN_AG_CTX_CF3EN_MASK
value|0x1
comment|/* cf3en */
define|#
directive|define
name|E4_TSTORM_ETH_CONN_AG_CTX_CF3EN_SHIFT
value|7
name|u8
name|flags4
decl_stmt|;
define|#
directive|define
name|E4_TSTORM_ETH_CONN_AG_CTX_CF4EN_MASK
value|0x1
comment|/* cf4en */
define|#
directive|define
name|E4_TSTORM_ETH_CONN_AG_CTX_CF4EN_SHIFT
value|0
define|#
directive|define
name|E4_TSTORM_ETH_CONN_AG_CTX_CF5EN_MASK
value|0x1
comment|/* cf5en */
define|#
directive|define
name|E4_TSTORM_ETH_CONN_AG_CTX_CF5EN_SHIFT
value|1
define|#
directive|define
name|E4_TSTORM_ETH_CONN_AG_CTX_CF6EN_MASK
value|0x1
comment|/* cf6en */
define|#
directive|define
name|E4_TSTORM_ETH_CONN_AG_CTX_CF6EN_SHIFT
value|2
define|#
directive|define
name|E4_TSTORM_ETH_CONN_AG_CTX_CF7EN_MASK
value|0x1
comment|/* cf7en */
define|#
directive|define
name|E4_TSTORM_ETH_CONN_AG_CTX_CF7EN_SHIFT
value|3
define|#
directive|define
name|E4_TSTORM_ETH_CONN_AG_CTX_CF8EN_MASK
value|0x1
comment|/* cf8en */
define|#
directive|define
name|E4_TSTORM_ETH_CONN_AG_CTX_CF8EN_SHIFT
value|4
define|#
directive|define
name|E4_TSTORM_ETH_CONN_AG_CTX_CF9EN_MASK
value|0x1
comment|/* cf9en */
define|#
directive|define
name|E4_TSTORM_ETH_CONN_AG_CTX_CF9EN_SHIFT
value|5
define|#
directive|define
name|E4_TSTORM_ETH_CONN_AG_CTX_CF10EN_MASK
value|0x1
comment|/* cf10en */
define|#
directive|define
name|E4_TSTORM_ETH_CONN_AG_CTX_CF10EN_SHIFT
value|6
define|#
directive|define
name|E4_TSTORM_ETH_CONN_AG_CTX_RULE0EN_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E4_TSTORM_ETH_CONN_AG_CTX_RULE0EN_SHIFT
value|7
name|u8
name|flags5
decl_stmt|;
define|#
directive|define
name|E4_TSTORM_ETH_CONN_AG_CTX_RULE1EN_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E4_TSTORM_ETH_CONN_AG_CTX_RULE1EN_SHIFT
value|0
define|#
directive|define
name|E4_TSTORM_ETH_CONN_AG_CTX_RULE2EN_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E4_TSTORM_ETH_CONN_AG_CTX_RULE2EN_SHIFT
value|1
define|#
directive|define
name|E4_TSTORM_ETH_CONN_AG_CTX_RULE3EN_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E4_TSTORM_ETH_CONN_AG_CTX_RULE3EN_SHIFT
value|2
define|#
directive|define
name|E4_TSTORM_ETH_CONN_AG_CTX_RULE4EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E4_TSTORM_ETH_CONN_AG_CTX_RULE4EN_SHIFT
value|3
define|#
directive|define
name|E4_TSTORM_ETH_CONN_AG_CTX_RULE5EN_MASK
value|0x1
comment|/* rule5en */
define|#
directive|define
name|E4_TSTORM_ETH_CONN_AG_CTX_RULE5EN_SHIFT
value|4
define|#
directive|define
name|E4_TSTORM_ETH_CONN_AG_CTX_RX_BD_EN_MASK
value|0x1
comment|/* rule6en */
define|#
directive|define
name|E4_TSTORM_ETH_CONN_AG_CTX_RX_BD_EN_SHIFT
value|5
define|#
directive|define
name|E4_TSTORM_ETH_CONN_AG_CTX_RULE7EN_MASK
value|0x1
comment|/* rule7en */
define|#
directive|define
name|E4_TSTORM_ETH_CONN_AG_CTX_RULE7EN_SHIFT
value|6
define|#
directive|define
name|E4_TSTORM_ETH_CONN_AG_CTX_RULE8EN_MASK
value|0x1
comment|/* rule8en */
define|#
directive|define
name|E4_TSTORM_ETH_CONN_AG_CTX_RULE8EN_SHIFT
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
name|rx_bd_cons
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
name|rx_bd_prod
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
name|e4_ustorm_eth_conn_ag_ctx
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
name|E4_USTORM_ETH_CONN_AG_CTX_BIT0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E4_USTORM_ETH_CONN_AG_CTX_BIT0_SHIFT
value|0
define|#
directive|define
name|E4_USTORM_ETH_CONN_AG_CTX_BIT1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E4_USTORM_ETH_CONN_AG_CTX_BIT1_SHIFT
value|1
define|#
directive|define
name|E4_USTORM_ETH_CONN_AG_CTX_TX_PMD_TERMINATE_CF_MASK
value|0x3
comment|/* timer0cf */
define|#
directive|define
name|E4_USTORM_ETH_CONN_AG_CTX_TX_PMD_TERMINATE_CF_SHIFT
value|2
define|#
directive|define
name|E4_USTORM_ETH_CONN_AG_CTX_RX_PMD_TERMINATE_CF_MASK
value|0x3
comment|/* timer1cf */
define|#
directive|define
name|E4_USTORM_ETH_CONN_AG_CTX_RX_PMD_TERMINATE_CF_SHIFT
value|4
define|#
directive|define
name|E4_USTORM_ETH_CONN_AG_CTX_CF2_MASK
value|0x3
comment|/* timer2cf */
define|#
directive|define
name|E4_USTORM_ETH_CONN_AG_CTX_CF2_SHIFT
value|6
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E4_USTORM_ETH_CONN_AG_CTX_CF3_MASK
value|0x3
comment|/* timer_stop_all */
define|#
directive|define
name|E4_USTORM_ETH_CONN_AG_CTX_CF3_SHIFT
value|0
define|#
directive|define
name|E4_USTORM_ETH_CONN_AG_CTX_TX_ARM_CF_MASK
value|0x3
comment|/* cf4 */
define|#
directive|define
name|E4_USTORM_ETH_CONN_AG_CTX_TX_ARM_CF_SHIFT
value|2
define|#
directive|define
name|E4_USTORM_ETH_CONN_AG_CTX_RX_ARM_CF_MASK
value|0x3
comment|/* cf5 */
define|#
directive|define
name|E4_USTORM_ETH_CONN_AG_CTX_RX_ARM_CF_SHIFT
value|4
define|#
directive|define
name|E4_USTORM_ETH_CONN_AG_CTX_TX_BD_CONS_UPD_CF_MASK
value|0x3
comment|/* cf6 */
define|#
directive|define
name|E4_USTORM_ETH_CONN_AG_CTX_TX_BD_CONS_UPD_CF_SHIFT
value|6
name|u8
name|flags2
decl_stmt|;
define|#
directive|define
name|E4_USTORM_ETH_CONN_AG_CTX_TX_PMD_TERMINATE_CF_EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E4_USTORM_ETH_CONN_AG_CTX_TX_PMD_TERMINATE_CF_EN_SHIFT
value|0
define|#
directive|define
name|E4_USTORM_ETH_CONN_AG_CTX_RX_PMD_TERMINATE_CF_EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E4_USTORM_ETH_CONN_AG_CTX_RX_PMD_TERMINATE_CF_EN_SHIFT
value|1
define|#
directive|define
name|E4_USTORM_ETH_CONN_AG_CTX_CF2EN_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E4_USTORM_ETH_CONN_AG_CTX_CF2EN_SHIFT
value|2
define|#
directive|define
name|E4_USTORM_ETH_CONN_AG_CTX_CF3EN_MASK
value|0x1
comment|/* cf3en */
define|#
directive|define
name|E4_USTORM_ETH_CONN_AG_CTX_CF3EN_SHIFT
value|3
define|#
directive|define
name|E4_USTORM_ETH_CONN_AG_CTX_TX_ARM_CF_EN_MASK
value|0x1
comment|/* cf4en */
define|#
directive|define
name|E4_USTORM_ETH_CONN_AG_CTX_TX_ARM_CF_EN_SHIFT
value|4
define|#
directive|define
name|E4_USTORM_ETH_CONN_AG_CTX_RX_ARM_CF_EN_MASK
value|0x1
comment|/* cf5en */
define|#
directive|define
name|E4_USTORM_ETH_CONN_AG_CTX_RX_ARM_CF_EN_SHIFT
value|5
define|#
directive|define
name|E4_USTORM_ETH_CONN_AG_CTX_TX_BD_CONS_UPD_CF_EN_MASK
value|0x1
comment|/* cf6en */
define|#
directive|define
name|E4_USTORM_ETH_CONN_AG_CTX_TX_BD_CONS_UPD_CF_EN_SHIFT
value|6
define|#
directive|define
name|E4_USTORM_ETH_CONN_AG_CTX_RULE0EN_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E4_USTORM_ETH_CONN_AG_CTX_RULE0EN_SHIFT
value|7
name|u8
name|flags3
decl_stmt|;
define|#
directive|define
name|E4_USTORM_ETH_CONN_AG_CTX_RULE1EN_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E4_USTORM_ETH_CONN_AG_CTX_RULE1EN_SHIFT
value|0
define|#
directive|define
name|E4_USTORM_ETH_CONN_AG_CTX_RULE2EN_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E4_USTORM_ETH_CONN_AG_CTX_RULE2EN_SHIFT
value|1
define|#
directive|define
name|E4_USTORM_ETH_CONN_AG_CTX_RULE3EN_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E4_USTORM_ETH_CONN_AG_CTX_RULE3EN_SHIFT
value|2
define|#
directive|define
name|E4_USTORM_ETH_CONN_AG_CTX_RULE4EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E4_USTORM_ETH_CONN_AG_CTX_RULE4EN_SHIFT
value|3
define|#
directive|define
name|E4_USTORM_ETH_CONN_AG_CTX_RULE5EN_MASK
value|0x1
comment|/* rule5en */
define|#
directive|define
name|E4_USTORM_ETH_CONN_AG_CTX_RULE5EN_SHIFT
value|4
define|#
directive|define
name|E4_USTORM_ETH_CONN_AG_CTX_RULE6EN_MASK
value|0x1
comment|/* rule6en */
define|#
directive|define
name|E4_USTORM_ETH_CONN_AG_CTX_RULE6EN_SHIFT
value|5
define|#
directive|define
name|E4_USTORM_ETH_CONN_AG_CTX_RULE7EN_MASK
value|0x1
comment|/* rule7en */
define|#
directive|define
name|E4_USTORM_ETH_CONN_AG_CTX_RULE7EN_SHIFT
value|6
define|#
directive|define
name|E4_USTORM_ETH_CONN_AG_CTX_RULE8EN_MASK
value|0x1
comment|/* rule8en */
define|#
directive|define
name|E4_USTORM_ETH_CONN_AG_CTX_RULE8EN_SHIFT
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
name|tx_bd_cons
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
name|tx_int_coallecing_timeset
comment|/* reg3 */
decl_stmt|;
name|__le16
name|tx_drv_bd_cons
comment|/* word2 */
decl_stmt|;
name|__le16
name|rx_drv_cqe_cons
comment|/* word3 */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The eth storm context for the Ustorm  */
end_comment

begin_struct
struct|struct
name|ustorm_eth_conn_st_ctx
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

begin_comment
comment|/*  * The eth storm context for the Mstorm  */
end_comment

begin_struct
struct|struct
name|mstorm_eth_conn_st_ctx
block|{
name|__le32
name|reserved
index|[
literal|8
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * eth connection context  */
end_comment

begin_struct
struct|struct
name|eth_conn_context
block|{
name|struct
name|tstorm_eth_conn_st_ctx
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
name|pstorm_eth_conn_st_ctx
name|pstorm_st_context
comment|/* pstorm storm context */
decl_stmt|;
name|struct
name|xstorm_eth_conn_st_ctx
name|xstorm_st_context
comment|/* xstorm storm context */
decl_stmt|;
name|struct
name|e4_xstorm_eth_conn_ag_ctx
name|xstorm_ag_context
comment|/* xstorm aggregative context */
decl_stmt|;
name|struct
name|ystorm_eth_conn_st_ctx
name|ystorm_st_context
comment|/* ystorm storm context */
decl_stmt|;
name|struct
name|e4_ystorm_eth_conn_ag_ctx
name|ystorm_ag_context
comment|/* ystorm aggregative context */
decl_stmt|;
name|struct
name|e4_tstorm_eth_conn_ag_ctx
name|tstorm_ag_context
comment|/* tstorm aggregative context */
decl_stmt|;
name|struct
name|e4_ustorm_eth_conn_ag_ctx
name|ustorm_ag_context
comment|/* ustorm aggregative context */
decl_stmt|;
name|struct
name|ustorm_eth_conn_st_ctx
name|ustorm_st_context
comment|/* ustorm storm context */
decl_stmt|;
name|struct
name|mstorm_eth_conn_st_ctx
name|mstorm_st_context
comment|/* mstorm storm context */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Ethernet filter types: mac/vlan/pair  */
end_comment

begin_enum
enum|enum
name|eth_error_code
block|{
name|ETH_OK
init|=
literal|0x00
comment|/* command succeeded */
block|,
name|ETH_FILTERS_MAC_ADD_FAIL_FULL
comment|/* mac add filters command failed due to cam full state */
block|,
name|ETH_FILTERS_MAC_ADD_FAIL_FULL_MTT2
comment|/* mac add filters command failed due to mtt2 full state */
block|,
name|ETH_FILTERS_MAC_ADD_FAIL_DUP_MTT2
comment|/* mac add filters command failed due to duplicate mac address */
block|,
name|ETH_FILTERS_MAC_ADD_FAIL_DUP_STT2
comment|/* mac add filters command failed due to duplicate mac address */
block|,
name|ETH_FILTERS_MAC_DEL_FAIL_NOF
comment|/* mac delete filters command failed due to not found state */
block|,
name|ETH_FILTERS_MAC_DEL_FAIL_NOF_MTT2
comment|/* mac delete filters command failed due to not found state */
block|,
name|ETH_FILTERS_MAC_DEL_FAIL_NOF_STT2
comment|/* mac delete filters command failed due to not found state */
block|,
name|ETH_FILTERS_MAC_ADD_FAIL_ZERO_MAC
comment|/* mac add filters command failed due to MAC Address of 00:00:00:00:00:00 */
block|,
name|ETH_FILTERS_VLAN_ADD_FAIL_FULL
comment|/* vlan add filters command failed due to cam full state */
block|,
name|ETH_FILTERS_VLAN_ADD_FAIL_DUP
comment|/* vlan add filters command failed due to duplicate VLAN filter */
block|,
name|ETH_FILTERS_VLAN_DEL_FAIL_NOF
comment|/* vlan delete filters command failed due to not found state */
block|,
name|ETH_FILTERS_VLAN_DEL_FAIL_NOF_TT1
comment|/* vlan delete filters command failed due to not found state */
block|,
name|ETH_FILTERS_PAIR_ADD_FAIL_DUP
comment|/* pair add filters command failed due to duplicate request */
block|,
name|ETH_FILTERS_PAIR_ADD_FAIL_FULL
comment|/* pair add filters command failed due to full state */
block|,
name|ETH_FILTERS_PAIR_ADD_FAIL_FULL_MAC
comment|/* pair add filters command failed due to full state */
block|,
name|ETH_FILTERS_PAIR_DEL_FAIL_NOF
comment|/* pair add filters command failed due not found state */
block|,
name|ETH_FILTERS_PAIR_DEL_FAIL_NOF_TT1
comment|/* pair add filters command failed due not found state */
block|,
name|ETH_FILTERS_PAIR_ADD_FAIL_ZERO_MAC
comment|/* pair add filters command failed due to MAC Address of 00:00:00:00:00:00 */
block|,
name|ETH_FILTERS_VNI_ADD_FAIL_FULL
comment|/* vni add filters command failed due to cam full state */
block|,
name|ETH_FILTERS_VNI_ADD_FAIL_DUP
comment|/* vni add filters command failed due to duplicate VNI filter */
block|,
name|ETH_FILTERS_GFT_UPDATE_FAIL
comment|/* Fail update GFT filter. */
block|,
name|MAX_ETH_ERROR_CODE
block|}
enum|;
end_enum

begin_comment
comment|/*  * opcodes for the event ring  */
end_comment

begin_enum
enum|enum
name|eth_event_opcode
block|{
name|ETH_EVENT_UNUSED
block|,
name|ETH_EVENT_VPORT_START
block|,
name|ETH_EVENT_VPORT_UPDATE
block|,
name|ETH_EVENT_VPORT_STOP
block|,
name|ETH_EVENT_TX_QUEUE_START
block|,
name|ETH_EVENT_TX_QUEUE_STOP
block|,
name|ETH_EVENT_RX_QUEUE_START
block|,
name|ETH_EVENT_RX_QUEUE_UPDATE
block|,
name|ETH_EVENT_RX_QUEUE_STOP
block|,
name|ETH_EVENT_FILTERS_UPDATE
block|,
name|ETH_EVENT_RX_ADD_OPENFLOW_FILTER
block|,
name|ETH_EVENT_RX_DELETE_OPENFLOW_FILTER
block|,
name|ETH_EVENT_RX_CREATE_OPENFLOW_ACTION
block|,
name|ETH_EVENT_RX_ADD_UDP_FILTER
block|,
name|ETH_EVENT_RX_DELETE_UDP_FILTER
block|,
name|ETH_EVENT_RX_CREATE_GFT_ACTION
block|,
name|ETH_EVENT_RX_GFT_UPDATE_FILTER
block|,
name|MAX_ETH_EVENT_OPCODE
block|}
enum|;
end_enum

begin_comment
comment|/*  * Classify rule types in E2/E3  */
end_comment

begin_enum
enum|enum
name|eth_filter_action
block|{
name|ETH_FILTER_ACTION_UNUSED
block|,
name|ETH_FILTER_ACTION_REMOVE
block|,
name|ETH_FILTER_ACTION_ADD
block|,
name|ETH_FILTER_ACTION_REMOVE_ALL
comment|/* Remove all filters of given type and vport ID. */
block|,
name|MAX_ETH_FILTER_ACTION
block|}
enum|;
end_enum

begin_comment
comment|/*  * Command for adding/removing a classification rule $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|eth_filter_cmd
block|{
name|u8
name|type
comment|/* Filter Type (MAC/VLAN/Pair/VNI) */
decl_stmt|;
name|u8
name|vport_id
comment|/* the vport id */
decl_stmt|;
name|u8
name|action
comment|/* filter command action: add/remove/replace */
decl_stmt|;
name|u8
name|reserved0
decl_stmt|;
name|__le32
name|vni
decl_stmt|;
name|__le16
name|mac_lsb
decl_stmt|;
name|__le16
name|mac_mid
decl_stmt|;
name|__le16
name|mac_msb
decl_stmt|;
name|__le16
name|vlan_id
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  *  $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|eth_filter_cmd_header
block|{
name|u8
name|rx
comment|/* If set, apply these commands to the RX path */
decl_stmt|;
name|u8
name|tx
comment|/* If set, apply these commands to the TX path */
decl_stmt|;
name|u8
name|cmd_cnt
comment|/* Number of filter commands */
decl_stmt|;
name|u8
name|assert_on_error
comment|/* 0 - dont assert in case of filter configuration error. Just return an error code. 1 - assert in case of filter configuration error. */
decl_stmt|;
name|u8
name|reserved1
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Ethernet filter types: mac/vlan/pair  */
end_comment

begin_enum
enum|enum
name|eth_filter_type
block|{
name|ETH_FILTER_TYPE_UNUSED
block|,
name|ETH_FILTER_TYPE_MAC
comment|/* Add/remove a MAC address */
block|,
name|ETH_FILTER_TYPE_VLAN
comment|/* Add/remove a VLAN */
block|,
name|ETH_FILTER_TYPE_PAIR
comment|/* Add/remove a MAC-VLAN pair */
block|,
name|ETH_FILTER_TYPE_INNER_MAC
comment|/* Add/remove a inner MAC address */
block|,
name|ETH_FILTER_TYPE_INNER_VLAN
comment|/* Add/remove a inner VLAN */
block|,
name|ETH_FILTER_TYPE_INNER_PAIR
comment|/* Add/remove a inner MAC-VLAN pair */
block|,
name|ETH_FILTER_TYPE_INNER_MAC_VNI_PAIR
comment|/* Add/remove a inner MAC-VNI pair */
block|,
name|ETH_FILTER_TYPE_MAC_VNI_PAIR
comment|/* Add/remove a MAC-VNI pair */
block|,
name|ETH_FILTER_TYPE_VNI
comment|/* Add/remove a VNI */
block|,
name|MAX_ETH_FILTER_TYPE
block|}
enum|;
end_enum

begin_comment
comment|/*  * eth IPv4 Fragment Type  */
end_comment

begin_enum
enum|enum
name|eth_ipv4_frag_type
block|{
name|ETH_IPV4_NOT_FRAG
comment|/* IPV4 Packet Not Fragmented */
block|,
name|ETH_IPV4_FIRST_FRAG
comment|/* First Fragment of IPv4 Packet (contains headers) */
block|,
name|ETH_IPV4_NON_FIRST_FRAG
comment|/* Non-First Fragment of IPv4 Packet (does not contain headers) */
block|,
name|MAX_ETH_IPV4_FRAG_TYPE
block|}
enum|;
end_enum

begin_comment
comment|/*  * eth IPv4 Fragment Type  */
end_comment

begin_enum
enum|enum
name|eth_ip_type
block|{
name|ETH_IPV4
comment|/* IPv4 */
block|,
name|ETH_IPV6
comment|/* IPv6 */
block|,
name|MAX_ETH_IP_TYPE
block|}
enum|;
end_enum

begin_comment
comment|/*  * Ethernet Ramrod Command IDs  */
end_comment

begin_enum
enum|enum
name|eth_ramrod_cmd_id
block|{
name|ETH_RAMROD_UNUSED
block|,
name|ETH_RAMROD_VPORT_START
comment|/* VPort Start Ramrod */
block|,
name|ETH_RAMROD_VPORT_UPDATE
comment|/* VPort Update Ramrod */
block|,
name|ETH_RAMROD_VPORT_STOP
comment|/* VPort Stop Ramrod */
block|,
name|ETH_RAMROD_RX_QUEUE_START
comment|/* RX Queue Start Ramrod */
block|,
name|ETH_RAMROD_RX_QUEUE_STOP
comment|/* RX Queue Stop Ramrod */
block|,
name|ETH_RAMROD_TX_QUEUE_START
comment|/* TX Queue Start Ramrod */
block|,
name|ETH_RAMROD_TX_QUEUE_STOP
comment|/* TX Queue Stop Ramrod */
block|,
name|ETH_RAMROD_FILTERS_UPDATE
comment|/* Add or Remove Mac/Vlan/Pair filters */
block|,
name|ETH_RAMROD_RX_QUEUE_UPDATE
comment|/* RX Queue Update Ramrod */
block|,
name|ETH_RAMROD_RX_CREATE_OPENFLOW_ACTION
comment|/* RX - Create an Openflow Action */
block|,
name|ETH_RAMROD_RX_ADD_OPENFLOW_FILTER
comment|/* RX - Add an Openflow Filter to the Searcher */
block|,
name|ETH_RAMROD_RX_DELETE_OPENFLOW_FILTER
comment|/* RX - Delete an Openflow Filter to the Searcher */
block|,
name|ETH_RAMROD_RX_ADD_UDP_FILTER
comment|/* RX - Add a UDP Filter to the Searcher */
block|,
name|ETH_RAMROD_RX_DELETE_UDP_FILTER
comment|/* RX - Delete a UDP Filter to the Searcher */
block|,
name|ETH_RAMROD_RX_CREATE_GFT_ACTION
comment|/* RX - Create a Gft Action */
block|,
name|ETH_RAMROD_GFT_UPDATE_FILTER
comment|/* RX - Add/Delete a GFT Filter to the Searcher */
block|,
name|MAX_ETH_RAMROD_CMD_ID
block|}
enum|;
end_enum

begin_comment
comment|/*  * return code from eth sp ramrods  */
end_comment

begin_struct
struct|struct
name|eth_return_code
block|{
name|u8
name|value
decl_stmt|;
define|#
directive|define
name|ETH_RETURN_CODE_ERR_CODE_MASK
value|0x1F
comment|/* error code (use enum eth_error_code) */
define|#
directive|define
name|ETH_RETURN_CODE_ERR_CODE_SHIFT
value|0
define|#
directive|define
name|ETH_RETURN_CODE_RESERVED_MASK
value|0x3
define|#
directive|define
name|ETH_RETURN_CODE_RESERVED_SHIFT
value|5
define|#
directive|define
name|ETH_RETURN_CODE_RX_TX_MASK
value|0x1
comment|/* rx path - 0, tx path - 1 */
define|#
directive|define
name|ETH_RETURN_CODE_RX_TX_SHIFT
value|7
block|}
struct|;
end_struct

begin_comment
comment|/*  * What to do in case an error occurs  */
end_comment

begin_enum
enum|enum
name|eth_tx_err
block|{
name|ETH_TX_ERR_DROP
comment|/* Drop erroneous packet. */
block|,
name|ETH_TX_ERR_ASSERT_MALICIOUS
comment|/* Assert an interrupt for PF, declare as malicious for VF */
block|,
name|MAX_ETH_TX_ERR
block|}
enum|;
end_enum

begin_comment
comment|/*  * Array of the different error type behaviors  */
end_comment

begin_struct
struct|struct
name|eth_tx_err_vals
block|{
name|__le16
name|values
decl_stmt|;
define|#
directive|define
name|ETH_TX_ERR_VALS_ILLEGAL_VLAN_MODE_MASK
value|0x1
comment|/* Wrong VLAN insertion mode (use enum eth_tx_err) */
define|#
directive|define
name|ETH_TX_ERR_VALS_ILLEGAL_VLAN_MODE_SHIFT
value|0
define|#
directive|define
name|ETH_TX_ERR_VALS_PACKET_TOO_SMALL_MASK
value|0x1
comment|/* Packet is below minimal size (use enum eth_tx_err) */
define|#
directive|define
name|ETH_TX_ERR_VALS_PACKET_TOO_SMALL_SHIFT
value|1
define|#
directive|define
name|ETH_TX_ERR_VALS_ANTI_SPOOFING_ERR_MASK
value|0x1
comment|/* Vport has sent spoofed packet (use enum eth_tx_err) */
define|#
directive|define
name|ETH_TX_ERR_VALS_ANTI_SPOOFING_ERR_SHIFT
value|2
define|#
directive|define
name|ETH_TX_ERR_VALS_ILLEGAL_INBAND_TAGS_MASK
value|0x1
comment|/* Packet with illegal type of inband tag (use enum eth_tx_err) */
define|#
directive|define
name|ETH_TX_ERR_VALS_ILLEGAL_INBAND_TAGS_SHIFT
value|3
define|#
directive|define
name|ETH_TX_ERR_VALS_VLAN_INSERTION_W_INBAND_TAG_MASK
value|0x1
comment|/* Packet marked for VLAN insertion when inband tag is present (use enum eth_tx_err) */
define|#
directive|define
name|ETH_TX_ERR_VALS_VLAN_INSERTION_W_INBAND_TAG_SHIFT
value|4
define|#
directive|define
name|ETH_TX_ERR_VALS_MTU_VIOLATION_MASK
value|0x1
comment|/* Non LSO packet larger than MTU (use enum eth_tx_err) */
define|#
directive|define
name|ETH_TX_ERR_VALS_MTU_VIOLATION_SHIFT
value|5
define|#
directive|define
name|ETH_TX_ERR_VALS_ILLEGAL_CONTROL_FRAME_MASK
value|0x1
comment|/* VF/PF has sent LLDP/PFC or any other type of control packet which is not allowed to (use enum eth_tx_err) */
define|#
directive|define
name|ETH_TX_ERR_VALS_ILLEGAL_CONTROL_FRAME_SHIFT
value|6
define|#
directive|define
name|ETH_TX_ERR_VALS_RESERVED_MASK
value|0x1FF
define|#
directive|define
name|ETH_TX_ERR_VALS_RESERVED_SHIFT
value|7
block|}
struct|;
end_struct

begin_comment
comment|/*  * vport rss configuration data  */
end_comment

begin_struct
struct|struct
name|eth_vport_rss_config
block|{
name|__le16
name|capabilities
decl_stmt|;
define|#
directive|define
name|ETH_VPORT_RSS_CONFIG_IPV4_CAPABILITY_MASK
value|0x1
comment|/* configuration of the IpV4 2-tuple capability */
define|#
directive|define
name|ETH_VPORT_RSS_CONFIG_IPV4_CAPABILITY_SHIFT
value|0
define|#
directive|define
name|ETH_VPORT_RSS_CONFIG_IPV6_CAPABILITY_MASK
value|0x1
comment|/* configuration of the IpV6 2-tuple capability */
define|#
directive|define
name|ETH_VPORT_RSS_CONFIG_IPV6_CAPABILITY_SHIFT
value|1
define|#
directive|define
name|ETH_VPORT_RSS_CONFIG_IPV4_TCP_CAPABILITY_MASK
value|0x1
comment|/* configuration of the IpV4 4-tuple capability for TCP */
define|#
directive|define
name|ETH_VPORT_RSS_CONFIG_IPV4_TCP_CAPABILITY_SHIFT
value|2
define|#
directive|define
name|ETH_VPORT_RSS_CONFIG_IPV6_TCP_CAPABILITY_MASK
value|0x1
comment|/* configuration of the IpV6 4-tuple capability for TCP */
define|#
directive|define
name|ETH_VPORT_RSS_CONFIG_IPV6_TCP_CAPABILITY_SHIFT
value|3
define|#
directive|define
name|ETH_VPORT_RSS_CONFIG_IPV4_UDP_CAPABILITY_MASK
value|0x1
comment|/* configuration of the IpV4 4-tuple capability for UDP */
define|#
directive|define
name|ETH_VPORT_RSS_CONFIG_IPV4_UDP_CAPABILITY_SHIFT
value|4
define|#
directive|define
name|ETH_VPORT_RSS_CONFIG_IPV6_UDP_CAPABILITY_MASK
value|0x1
comment|/* configuration of the IpV6 4-tuple capability for UDP */
define|#
directive|define
name|ETH_VPORT_RSS_CONFIG_IPV6_UDP_CAPABILITY_SHIFT
value|5
define|#
directive|define
name|ETH_VPORT_RSS_CONFIG_EN_5_TUPLE_CAPABILITY_MASK
value|0x1
comment|/* configuration of the 5-tuple capability */
define|#
directive|define
name|ETH_VPORT_RSS_CONFIG_EN_5_TUPLE_CAPABILITY_SHIFT
value|6
define|#
directive|define
name|ETH_VPORT_RSS_CONFIG_RESERVED0_MASK
value|0x1FF
comment|/* if set update the rss keys */
define|#
directive|define
name|ETH_VPORT_RSS_CONFIG_RESERVED0_SHIFT
value|7
name|u8
name|rss_id
comment|/* The RSS engine ID. Must be allocated to each vport with RSS enabled. Total number of RSS engines is ETH_RSS_ENGINE_NUM_ , according to chip type. */
decl_stmt|;
name|u8
name|rss_mode
comment|/* The RSS mode for this function */
decl_stmt|;
name|u8
name|update_rss_key
comment|/* if set update the rss key */
decl_stmt|;
name|u8
name|update_rss_ind_table
comment|/* if set update the indirection table values */
decl_stmt|;
name|u8
name|update_rss_capabilities
comment|/* if set update the capabilities and indirection table size. */
decl_stmt|;
name|u8
name|tbl_size
comment|/* rss mask (Tbl size) */
decl_stmt|;
name|__le32
name|reserved2
index|[
literal|2
index|]
decl_stmt|;
name|__le16
name|indirection_table
index|[
name|ETH_RSS_IND_TABLE_ENTRIES_NUM
index|]
comment|/* RSS indirection table */
decl_stmt|;
name|__le32
name|rss_key
index|[
name|ETH_RSS_KEY_SIZE_REGS
index|]
comment|/* RSS key supplied to us by OS */
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
comment|/*  * eth vport RSS mode  */
end_comment

begin_enum
enum|enum
name|eth_vport_rss_mode
block|{
name|ETH_VPORT_RSS_MODE_DISABLED
comment|/* RSS Disabled */
block|,
name|ETH_VPORT_RSS_MODE_REGULAR
comment|/* Regular (ndis-like) RSS */
block|,
name|MAX_ETH_VPORT_RSS_MODE
block|}
enum|;
end_enum

begin_comment
comment|/*  * Command for setting classification flags for a vport $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|eth_vport_rx_mode
block|{
name|__le16
name|state
decl_stmt|;
define|#
directive|define
name|ETH_VPORT_RX_MODE_UCAST_DROP_ALL_MASK
value|0x1
comment|/* drop all unicast packets */
define|#
directive|define
name|ETH_VPORT_RX_MODE_UCAST_DROP_ALL_SHIFT
value|0
define|#
directive|define
name|ETH_VPORT_RX_MODE_UCAST_ACCEPT_ALL_MASK
value|0x1
comment|/* accept all unicast packets (subject to vlan) */
define|#
directive|define
name|ETH_VPORT_RX_MODE_UCAST_ACCEPT_ALL_SHIFT
value|1
define|#
directive|define
name|ETH_VPORT_RX_MODE_UCAST_ACCEPT_UNMATCHED_MASK
value|0x1
comment|/* accept all unmatched unicast packets */
define|#
directive|define
name|ETH_VPORT_RX_MODE_UCAST_ACCEPT_UNMATCHED_SHIFT
value|2
define|#
directive|define
name|ETH_VPORT_RX_MODE_MCAST_DROP_ALL_MASK
value|0x1
comment|/* drop all multicast packets */
define|#
directive|define
name|ETH_VPORT_RX_MODE_MCAST_DROP_ALL_SHIFT
value|3
define|#
directive|define
name|ETH_VPORT_RX_MODE_MCAST_ACCEPT_ALL_MASK
value|0x1
comment|/* accept all multicast packets (subject to vlan) */
define|#
directive|define
name|ETH_VPORT_RX_MODE_MCAST_ACCEPT_ALL_SHIFT
value|4
define|#
directive|define
name|ETH_VPORT_RX_MODE_BCAST_ACCEPT_ALL_MASK
value|0x1
comment|/* accept all broadcast packets (subject to vlan) */
define|#
directive|define
name|ETH_VPORT_RX_MODE_BCAST_ACCEPT_ALL_SHIFT
value|5
define|#
directive|define
name|ETH_VPORT_RX_MODE_RESERVED1_MASK
value|0x3FF
define|#
directive|define
name|ETH_VPORT_RX_MODE_RESERVED1_SHIFT
value|6
name|__le16
name|reserved2
index|[
literal|3
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Command for setting tpa parameters  */
end_comment

begin_struct
struct|struct
name|eth_vport_tpa_param
block|{
name|u8
name|tpa_ipv4_en_flg
comment|/* Enable TPA for IPv4 packets */
decl_stmt|;
name|u8
name|tpa_ipv6_en_flg
comment|/* Enable TPA for IPv6 packets */
decl_stmt|;
name|u8
name|tpa_ipv4_tunn_en_flg
comment|/* Enable TPA for IPv4 over tunnel */
decl_stmt|;
name|u8
name|tpa_ipv6_tunn_en_flg
comment|/* Enable TPA for IPv6 over tunnel */
decl_stmt|;
name|u8
name|tpa_pkt_split_flg
comment|/* If set, start each tpa segment on new SGE (GRO mode). One SGE per segment allowed */
decl_stmt|;
name|u8
name|tpa_hdr_data_split_flg
comment|/* If set, put header of first TPA segment on bd and data on SGE */
decl_stmt|;
name|u8
name|tpa_gro_consistent_flg
comment|/* If set, GRO data consistent will checked for TPA continue */
decl_stmt|;
name|u8
name|tpa_max_aggs_num
comment|/* maximum number of opened aggregations per v-port  */
decl_stmt|;
name|__le16
name|tpa_max_size
comment|/* maximal size for the aggregated TPA packets */
decl_stmt|;
name|__le16
name|tpa_min_size_to_start
comment|/* minimum TCP payload size for a packet to start aggregation */
decl_stmt|;
name|__le16
name|tpa_min_size_to_cont
comment|/* minimum TCP payload size for a packet to continue aggregation */
decl_stmt|;
name|u8
name|max_buff_num
comment|/* maximal number of buffers that can be used for one aggregation */
decl_stmt|;
name|u8
name|reserved
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Command for setting classification flags for a vport $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|eth_vport_tx_mode
block|{
name|__le16
name|state
decl_stmt|;
define|#
directive|define
name|ETH_VPORT_TX_MODE_UCAST_DROP_ALL_MASK
value|0x1
comment|/* drop all unicast packets */
define|#
directive|define
name|ETH_VPORT_TX_MODE_UCAST_DROP_ALL_SHIFT
value|0
define|#
directive|define
name|ETH_VPORT_TX_MODE_UCAST_ACCEPT_ALL_MASK
value|0x1
comment|/* accept all unicast packets (subject to vlan) */
define|#
directive|define
name|ETH_VPORT_TX_MODE_UCAST_ACCEPT_ALL_SHIFT
value|1
define|#
directive|define
name|ETH_VPORT_TX_MODE_MCAST_DROP_ALL_MASK
value|0x1
comment|/* drop all multicast packets */
define|#
directive|define
name|ETH_VPORT_TX_MODE_MCAST_DROP_ALL_SHIFT
value|2
define|#
directive|define
name|ETH_VPORT_TX_MODE_MCAST_ACCEPT_ALL_MASK
value|0x1
comment|/* accept all multicast packets (subject to vlan) */
define|#
directive|define
name|ETH_VPORT_TX_MODE_MCAST_ACCEPT_ALL_SHIFT
value|3
define|#
directive|define
name|ETH_VPORT_TX_MODE_BCAST_ACCEPT_ALL_MASK
value|0x1
comment|/* accept all broadcast packets (subject to vlan) */
define|#
directive|define
name|ETH_VPORT_TX_MODE_BCAST_ACCEPT_ALL_SHIFT
value|4
define|#
directive|define
name|ETH_VPORT_TX_MODE_RESERVED1_MASK
value|0x7FF
define|#
directive|define
name|ETH_VPORT_TX_MODE_RESERVED1_SHIFT
value|5
name|__le16
name|reserved2
index|[
literal|3
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Ramrod data for rx create gft action  */
end_comment

begin_enum
enum|enum
name|gft_filter_update_action
block|{
name|GFT_ADD_FILTER
block|,
name|GFT_DELETE_FILTER
block|,
name|MAX_GFT_FILTER_UPDATE_ACTION
block|}
enum|;
end_enum

begin_comment
comment|/*  * Ramrod data for rx create gft action  */
end_comment

begin_enum
enum|enum
name|gft_logic_filter_type
block|{
name|GFT_FILTER_TYPE
comment|/* flow FW is GFT-logic as well */
block|,
name|RFS_FILTER_TYPE
comment|/* flow FW is A-RFS-logic */
block|,
name|MAX_GFT_LOGIC_FILTER_TYPE
block|}
enum|;
end_enum

begin_comment
comment|/*  * Ramrod data for rx add openflow filter  */
end_comment

begin_struct
struct|struct
name|rx_add_openflow_filter_data
block|{
name|__le16
name|action_icid
comment|/* CID of Action to run for this filter */
decl_stmt|;
name|u8
name|priority
comment|/* Searcher String - Packet priority */
decl_stmt|;
name|u8
name|reserved0
decl_stmt|;
name|__le32
name|tenant_id
comment|/* Searcher String - Tenant ID */
decl_stmt|;
name|__le16
name|dst_mac_hi
comment|/* Searcher String - Destination Mac Bytes 0 to 1 */
decl_stmt|;
name|__le16
name|dst_mac_mid
comment|/* Searcher String - Destination Mac Bytes 2 to 3 */
decl_stmt|;
name|__le16
name|dst_mac_lo
comment|/* Searcher String - Destination Mac Bytes 4 to 5 */
decl_stmt|;
name|__le16
name|src_mac_hi
comment|/* Searcher String - Source Mac 0 to 1 */
decl_stmt|;
name|__le16
name|src_mac_mid
comment|/* Searcher String - Source Mac 2 to 3 */
decl_stmt|;
name|__le16
name|src_mac_lo
comment|/* Searcher String - Source Mac 4 to 5 */
decl_stmt|;
name|__le16
name|vlan_id
comment|/* Searcher String - Vlan ID */
decl_stmt|;
name|__le16
name|l2_eth_type
comment|/* Searcher String - Last L2 Ethertype */
decl_stmt|;
name|u8
name|ipv4_dscp
comment|/* Searcher String - IPv4 6 MSBs of the TOS Field */
decl_stmt|;
name|u8
name|ipv4_frag_type
comment|/* Searcher String - IPv4 Fragmentation Type */
decl_stmt|;
name|u8
name|ipv4_over_ip
comment|/* Searcher String - IPv4 Over IP Type */
decl_stmt|;
name|u8
name|tenant_id_exists
comment|/* Searcher String - Tenant ID Exists */
decl_stmt|;
name|__le32
name|ipv4_dst_addr
comment|/* Searcher String - IPv4 Destination Address */
decl_stmt|;
name|__le32
name|ipv4_src_addr
comment|/* Searcher String - IPv4 Source Address */
decl_stmt|;
name|__le16
name|l4_dst_port
comment|/* Searcher String - TCP/UDP Destination Port */
decl_stmt|;
name|__le16
name|l4_src_port
comment|/* Searcher String - TCP/UDP Source Port */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Ramrod data for rx create gft action  */
end_comment

begin_struct
struct|struct
name|rx_create_gft_action_data
block|{
name|u8
name|vport_id
comment|/* Vport Id of GFT Action  */
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
comment|/*  * Ramrod data for rx create openflow action  */
end_comment

begin_struct
struct|struct
name|rx_create_openflow_action_data
block|{
name|u8
name|vport_id
comment|/* ID of RX queue */
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
comment|/*  * Ramrod data for rx queue start ramrod  */
end_comment

begin_struct
struct|struct
name|rx_queue_start_ramrod_data
block|{
name|__le16
name|rx_queue_id
comment|/* ID of RX queue */
decl_stmt|;
name|__le16
name|num_of_pbl_pages
comment|/* Num of pages in CQE PBL */
decl_stmt|;
name|__le16
name|bd_max_bytes
comment|/* maximal bytes that can be places on the bd */
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
name|vport_id
comment|/* ID of virtual port */
decl_stmt|;
name|u8
name|default_rss_queue_flg
comment|/* set queue as default rss queue if set */
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
name|stats_counter_id
comment|/* Statistics counter ID */
decl_stmt|;
name|u8
name|pin_context
comment|/* Pin context in CCFC to improve performance */
decl_stmt|;
name|u8
name|pxp_tph_valid_bd
comment|/* PXP command TPH Valid - for BD/SGE fetch */
decl_stmt|;
name|u8
name|pxp_tph_valid_pkt
comment|/* PXP command TPH Valid - for packet placement */
decl_stmt|;
name|u8
name|pxp_st_hint
comment|/* PXP command Steering tag hint. Use enum pxp_tph_st_hint */
decl_stmt|;
name|__le16
name|pxp_st_index
comment|/* PXP command Steering tag index */
decl_stmt|;
name|u8
name|pmd_mode
comment|/* Indicates that current queue belongs to poll-mode driver */
decl_stmt|;
name|u8
name|notify_en
comment|/* Indicates that the current queue is using the TX notification queue mechanism - should be set only for PMD queue */
decl_stmt|;
name|u8
name|toggle_val
comment|/* Initial value for the toggle valid bit - used in PMD mode */
decl_stmt|;
name|u8
name|vf_rx_prod_index
comment|/* Index of RX producers in VF zone. Used for VF only. */
decl_stmt|;
name|u8
name|vf_rx_prod_use_zone_a
comment|/* Backward compatibility mode. If set, unprotected mStorm queue zone will used for VF RX producers instead of VF zone. */
decl_stmt|;
name|u8
name|reserved
index|[
literal|5
index|]
decl_stmt|;
name|__le16
name|reserved1
comment|/* FW reserved. */
decl_stmt|;
name|struct
name|regpair
name|cqe_pbl_addr
comment|/* Base address on host of CQE PBL */
decl_stmt|;
name|struct
name|regpair
name|bd_base
comment|/* bd address of the first bd page */
decl_stmt|;
name|struct
name|regpair
name|reserved2
comment|/* FW reserved. */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Ramrod data for rx queue stop ramrod  */
end_comment

begin_struct
struct|struct
name|rx_queue_stop_ramrod_data
block|{
name|__le16
name|rx_queue_id
comment|/* ID of RX queue */
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
name|vport_id
comment|/* ID of virtual port */
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
comment|/*  * Ramrod data for rx queue update ramrod  */
end_comment

begin_struct
struct|struct
name|rx_queue_update_ramrod_data
block|{
name|__le16
name|rx_queue_id
comment|/* ID of RX queue */
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
name|vport_id
comment|/* ID of virtual port */
decl_stmt|;
name|u8
name|reserved
index|[
literal|4
index|]
decl_stmt|;
name|u8
name|reserved1
comment|/* FW reserved. */
decl_stmt|;
name|u8
name|reserved2
comment|/* FW reserved. */
decl_stmt|;
name|u8
name|reserved3
comment|/* FW reserved. */
decl_stmt|;
name|__le16
name|reserved4
comment|/* FW reserved. */
decl_stmt|;
name|__le16
name|reserved5
comment|/* FW reserved. */
decl_stmt|;
name|struct
name|regpair
name|reserved6
comment|/* FW reserved. */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Ramrod data for rx Add UDP Filter  */
end_comment

begin_struct
struct|struct
name|rx_udp_filter_data
block|{
name|__le16
name|action_icid
comment|/* CID of Action to run for this filter */
decl_stmt|;
name|__le16
name|vlan_id
comment|/* Searcher String - Vlan ID */
decl_stmt|;
name|u8
name|ip_type
comment|/* Searcher String - IP Type */
decl_stmt|;
name|u8
name|tenant_id_exists
comment|/* Searcher String - Tenant ID Exists */
decl_stmt|;
name|__le16
name|reserved1
decl_stmt|;
name|__le32
name|ip_dst_addr
index|[
literal|4
index|]
comment|/* Searcher String - IP Destination Address, for IPv4 use ip_dst_addr[0] only */
decl_stmt|;
name|__le32
name|ip_src_addr
index|[
literal|4
index|]
comment|/* Searcher String - IP Source Address, for IPv4 use ip_dst_addr[0] only */
decl_stmt|;
name|__le16
name|udp_dst_port
comment|/* Searcher String - UDP Destination Port */
decl_stmt|;
name|__le16
name|udp_src_port
comment|/* Searcher String - UDP Source Port */
decl_stmt|;
name|__le32
name|tenant_id
comment|/* Searcher String - Tenant ID */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Ramrod to add filter - filter is packet headr of type of packet wished to pass certin FW flow  */
end_comment

begin_struct
struct|struct
name|rx_update_gft_filter_data
block|{
name|struct
name|regpair
name|pkt_hdr_addr
comment|/* Pointer to Packet Header That Defines GFT Filter */
decl_stmt|;
name|__le16
name|pkt_hdr_length
comment|/* Packet Header Length */
decl_stmt|;
name|__le16
name|rx_qid_or_action_icid
comment|/* If is_rfs flag is set: Queue Id to associate filter with else: action icid */
decl_stmt|;
name|u8
name|vport_id
comment|/* Field is used if is_rfs flag is set: vport Id of which to associate filter with */
decl_stmt|;
name|u8
name|filter_type
comment|/* Use enum to set type of flow using gft HW logic blocks */
decl_stmt|;
name|u8
name|filter_action
comment|/* Use to set type of action on filter */
decl_stmt|;
name|u8
name|assert_on_error
comment|/* 0 - dont assert in case of error. Just return an error code. 1 - assert in case of error. */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Ramrod data for tx queue start ramrod  */
end_comment

begin_struct
struct|struct
name|tx_queue_start_ramrod_data
block|{
name|__le16
name|sb_id
comment|/* Status block ID */
decl_stmt|;
name|u8
name|sb_index
comment|/* Status block protocol index */
decl_stmt|;
name|u8
name|vport_id
comment|/* VPort ID */
decl_stmt|;
name|u8
name|reserved0
comment|/* FW reserved. (qcn_rl_en) */
decl_stmt|;
name|u8
name|stats_counter_id
comment|/* Statistics counter ID to use */
decl_stmt|;
name|__le16
name|qm_pq_id
comment|/* QM PQ ID */
decl_stmt|;
name|u8
name|flags
decl_stmt|;
define|#
directive|define
name|TX_QUEUE_START_RAMROD_DATA_DISABLE_OPPORTUNISTIC_MASK
value|0x1
comment|/* 0: Enable QM opportunistic flow. 1: Disable QM opportunistic flow */
define|#
directive|define
name|TX_QUEUE_START_RAMROD_DATA_DISABLE_OPPORTUNISTIC_SHIFT
value|0
define|#
directive|define
name|TX_QUEUE_START_RAMROD_DATA_TEST_MODE_PKT_DUP_MASK
value|0x1
comment|/* If set, Test Mode - packets will be duplicated by Xstorm handler */
define|#
directive|define
name|TX_QUEUE_START_RAMROD_DATA_TEST_MODE_PKT_DUP_SHIFT
value|1
define|#
directive|define
name|TX_QUEUE_START_RAMROD_DATA_TEST_MODE_TX_DEST_MASK
value|0x1
comment|/* If set, Test Mode - packets destination will be determined by dest_port_mode field from Tx BD */
define|#
directive|define
name|TX_QUEUE_START_RAMROD_DATA_TEST_MODE_TX_DEST_SHIFT
value|2
define|#
directive|define
name|TX_QUEUE_START_RAMROD_DATA_PMD_MODE_MASK
value|0x1
comment|/* Indicates that current queue belongs to poll-mode driver */
define|#
directive|define
name|TX_QUEUE_START_RAMROD_DATA_PMD_MODE_SHIFT
value|3
define|#
directive|define
name|TX_QUEUE_START_RAMROD_DATA_NOTIFY_EN_MASK
value|0x1
comment|/* Indicates that the current queue is using the TX notification queue mechanism - should be set only for PMD queue */
define|#
directive|define
name|TX_QUEUE_START_RAMROD_DATA_NOTIFY_EN_SHIFT
value|4
define|#
directive|define
name|TX_QUEUE_START_RAMROD_DATA_PIN_CONTEXT_MASK
value|0x1
comment|/* Pin context in CCFC to improve performance */
define|#
directive|define
name|TX_QUEUE_START_RAMROD_DATA_PIN_CONTEXT_SHIFT
value|5
define|#
directive|define
name|TX_QUEUE_START_RAMROD_DATA_RESERVED1_MASK
value|0x3
define|#
directive|define
name|TX_QUEUE_START_RAMROD_DATA_RESERVED1_SHIFT
value|6
name|u8
name|pxp_st_hint
comment|/* PXP command Steering tag hint */
decl_stmt|;
name|u8
name|pxp_tph_valid_bd
comment|/* PXP command TPH Valid - for BD fetch */
decl_stmt|;
name|u8
name|pxp_tph_valid_pkt
comment|/* PXP command TPH Valid - for packet fetch */
decl_stmt|;
name|__le16
name|pxp_st_index
comment|/* PXP command Steering tag index */
decl_stmt|;
name|__le16
name|comp_agg_size
comment|/* TX completion min agg size - for PMD queues */
decl_stmt|;
name|__le16
name|queue_zone_id
comment|/* queue zone ID to use */
decl_stmt|;
name|__le16
name|reserved2
comment|/* FW reserved. (test_dup_count) */
decl_stmt|;
name|__le16
name|pbl_size
comment|/* Number of BD pages pointed by PBL */
decl_stmt|;
name|__le16
name|tx_queue_id
comment|/* unique Queue ID - currently used only by PMD flow */
decl_stmt|;
name|__le16
name|same_as_last_id
comment|/* Unique Same-As-Last Resource ID - improves performance for same-as-last packets per connection (range 0..ETH_TX_NUM_SAME_AS_LAST_ENTRIES-1 IDs available) */
decl_stmt|;
name|__le16
name|reserved
index|[
literal|3
index|]
decl_stmt|;
name|struct
name|regpair
name|pbl_base_addr
comment|/* address of the pbl page */
decl_stmt|;
name|struct
name|regpair
name|bd_cons_address
comment|/* BD consumer address in host - for PMD queues */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Ramrod data for tx queue stop ramrod  */
end_comment

begin_struct
struct|struct
name|tx_queue_stop_ramrod_data
block|{
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
comment|/*  * Ramrod data for vport update ramrod  */
end_comment

begin_struct
struct|struct
name|vport_filter_update_ramrod_data
block|{
name|struct
name|eth_filter_cmd_header
name|filter_cmd_hdr
comment|/* Header for Filter Commands (RX/TX, Add/Remove/Replace, etc) */
decl_stmt|;
name|struct
name|eth_filter_cmd
name|filter_cmds
index|[
name|ETH_FILTER_RULES_COUNT
index|]
comment|/* Filter Commands */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Ramrod data for vport start ramrod  */
end_comment

begin_struct
struct|struct
name|vport_start_ramrod_data
block|{
name|u8
name|vport_id
decl_stmt|;
name|u8
name|sw_fid
decl_stmt|;
name|__le16
name|mtu
decl_stmt|;
name|u8
name|drop_ttl0_en
comment|/* if set, drop packet with ttl=0 */
decl_stmt|;
name|u8
name|inner_vlan_removal_en
decl_stmt|;
name|struct
name|eth_vport_rx_mode
name|rx_mode
comment|/* Rx filter data */
decl_stmt|;
name|struct
name|eth_vport_tx_mode
name|tx_mode
comment|/* Tx filter data */
decl_stmt|;
name|struct
name|eth_vport_tpa_param
name|tpa_param
comment|/* TPA configuration parameters */
decl_stmt|;
name|__le16
name|default_vlan
comment|/* Default Vlan value to be forced by FW */
decl_stmt|;
name|u8
name|tx_switching_en
comment|/* Tx switching is enabled for current Vport */
decl_stmt|;
name|u8
name|anti_spoofing_en
comment|/* Anti-spoofing verification is set for current Vport */
decl_stmt|;
name|u8
name|default_vlan_en
comment|/* If set, the default Vlan value is forced by the FW */
decl_stmt|;
name|u8
name|handle_ptp_pkts
comment|/* If set, the vport handles PTP Timesync Packets */
decl_stmt|;
name|u8
name|silent_vlan_removal_en
comment|/* If enable then innerVlan will be striped and not written to cqe */
decl_stmt|;
name|u8
name|untagged
comment|/* If set untagged filter (vlan0) is added to current Vport, otherwise port is marked as any-vlan */
decl_stmt|;
name|struct
name|eth_tx_err_vals
name|tx_err_behav
comment|/* Desired behavior per TX error type */
decl_stmt|;
name|u8
name|zero_placement_offset
comment|/* If set, ETH header padding will not inserted. placement_offset will be zero. */
decl_stmt|;
name|u8
name|ctl_frame_mac_check_en
comment|/* If set, Contorl frames will be filtered according to MAC check. */
decl_stmt|;
name|u8
name|ctl_frame_ethtype_check_en
comment|/* If set, Contorl frames will be filtered according to ethtype check. */
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
comment|/*  * Ramrod data for vport stop ramrod  */
end_comment

begin_struct
struct|struct
name|vport_stop_ramrod_data
block|{
name|u8
name|vport_id
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
comment|/*  * Ramrod data for vport update ramrod  */
end_comment

begin_struct
struct|struct
name|vport_update_ramrod_data_cmn
block|{
name|u8
name|vport_id
decl_stmt|;
name|u8
name|update_rx_active_flg
comment|/* set if rx active flag should be handled */
decl_stmt|;
name|u8
name|rx_active_flg
comment|/* rx active flag value */
decl_stmt|;
name|u8
name|update_tx_active_flg
comment|/* set if tx active flag should be handled */
decl_stmt|;
name|u8
name|tx_active_flg
comment|/* tx active flag value */
decl_stmt|;
name|u8
name|update_rx_mode_flg
comment|/* set if rx state data should be handled */
decl_stmt|;
name|u8
name|update_tx_mode_flg
comment|/* set if tx state data should be handled */
decl_stmt|;
name|u8
name|update_approx_mcast_flg
comment|/* set if approx. mcast data should be handled */
decl_stmt|;
name|u8
name|update_rss_flg
comment|/* set if rss data should be handled  */
decl_stmt|;
name|u8
name|update_inner_vlan_removal_en_flg
comment|/* set if inner_vlan_removal_en should be handled */
decl_stmt|;
name|u8
name|inner_vlan_removal_en
decl_stmt|;
name|u8
name|update_tpa_param_flg
comment|/* set if tpa parameters should be handled, TPA must be disable before */
decl_stmt|;
name|u8
name|update_tpa_en_flg
comment|/* set if tpa enable changes */
decl_stmt|;
name|u8
name|update_tx_switching_en_flg
comment|/* set if tx switching en flag should be handled */
decl_stmt|;
name|u8
name|tx_switching_en
comment|/* tx switching en value */
decl_stmt|;
name|u8
name|update_anti_spoofing_en_flg
comment|/* set if anti spoofing flag should be handled */
decl_stmt|;
name|u8
name|anti_spoofing_en
comment|/* Anti-spoofing verification en value */
decl_stmt|;
name|u8
name|update_handle_ptp_pkts
comment|/* set if handle_ptp_pkts should be handled. */
decl_stmt|;
name|u8
name|handle_ptp_pkts
comment|/* If set, the vport handles PTP Timesync Packets */
decl_stmt|;
name|u8
name|update_default_vlan_en_flg
comment|/* If set, the default Vlan enable flag is updated */
decl_stmt|;
name|u8
name|default_vlan_en
comment|/* If set, the default Vlan value is forced by the FW */
decl_stmt|;
name|u8
name|update_default_vlan_flg
comment|/* If set, the default Vlan value is updated */
decl_stmt|;
name|__le16
name|default_vlan
comment|/* Default Vlan value to be forced by FW */
decl_stmt|;
name|u8
name|update_accept_any_vlan_flg
comment|/* set if accept_any_vlan should be handled */
decl_stmt|;
name|u8
name|accept_any_vlan
comment|/* accept_any_vlan updated value */
decl_stmt|;
name|u8
name|silent_vlan_removal_en
comment|/* Set to remove vlan silently, update_inner_vlan_removal_en_flg must be enabled as well. If Rx is in noSgl mode send rx_queue_update_ramrod_data */
decl_stmt|;
name|u8
name|update_mtu_flg
comment|/* If set, MTU will be updated. Vport must be not active. */
decl_stmt|;
name|__le16
name|mtu
comment|/* New MTU value. Used if update_mtu_flg are set */
decl_stmt|;
name|u8
name|update_ctl_frame_checks_en_flg
comment|/* If set, ctl_frame_mac_check_en and ctl_frame_ethtype_check_en will be updated */
decl_stmt|;
name|u8
name|ctl_frame_mac_check_en
comment|/* If set, Contorl frames will be filtered according to MAC check. */
decl_stmt|;
name|u8
name|ctl_frame_ethtype_check_en
comment|/* If set, Contorl frames will be filtered according to ethtype check. */
decl_stmt|;
name|u8
name|reserved
index|[
literal|15
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|vport_update_ramrod_mcast
block|{
name|__le32
name|bins
index|[
name|ETH_MULTICAST_MAC_BINS_IN_REGS
index|]
comment|/* multicast bins */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Ramrod data for vport update ramrod  */
end_comment

begin_struct
struct|struct
name|vport_update_ramrod_data
block|{
name|struct
name|vport_update_ramrod_data_cmn
name|common
comment|/* Common data for all vport update ramrods */
decl_stmt|;
name|struct
name|eth_vport_rx_mode
name|rx_mode
comment|/* vport rx mode bitmap */
decl_stmt|;
name|struct
name|eth_vport_tx_mode
name|tx_mode
comment|/* vport tx mode bitmap */
decl_stmt|;
name|struct
name|eth_vport_tpa_param
name|tpa_param
comment|/* TPA configuration parameters */
decl_stmt|;
name|struct
name|vport_update_ramrod_mcast
name|approx_mcast
decl_stmt|;
name|struct
name|eth_vport_rss_config
name|rss_config
comment|/* rss config data */
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|E4XstormEthConnAgCtxDqExtLdPart
block|{
name|u8
name|reserved0
comment|/* cdu_validation */
decl_stmt|;
name|u8
name|eth_state
comment|/* state */
decl_stmt|;
name|u8
name|flags0
decl_stmt|;
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_EXIST_IN_QM0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_EXIST_IN_QM0_SHIFT
value|0
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_RESERVED1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_RESERVED1_SHIFT
value|1
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_RESERVED2_MASK
value|0x1
comment|/* exist_in_qm2 */
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_RESERVED2_SHIFT
value|2
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_EXIST_IN_QM3_MASK
value|0x1
comment|/* exist_in_qm3 */
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_EXIST_IN_QM3_SHIFT
value|3
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_RESERVED3_MASK
value|0x1
comment|/* bit4 */
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_RESERVED3_SHIFT
value|4
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_RESERVED4_MASK
value|0x1
comment|/* cf_array_active */
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_RESERVED4_SHIFT
value|5
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_RESERVED5_MASK
value|0x1
comment|/* bit6 */
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_RESERVED5_SHIFT
value|6
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_RESERVED6_MASK
value|0x1
comment|/* bit7 */
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_RESERVED6_SHIFT
value|7
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_RESERVED7_MASK
value|0x1
comment|/* bit8 */
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_RESERVED7_SHIFT
value|0
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_RESERVED8_MASK
value|0x1
comment|/* bit9 */
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_RESERVED8_SHIFT
value|1
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_RESERVED9_MASK
value|0x1
comment|/* bit10 */
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_RESERVED9_SHIFT
value|2
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_BIT11_MASK
value|0x1
comment|/* bit11 */
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_BIT11_SHIFT
value|3
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_BIT12_MASK
value|0x1
comment|/* bit12 */
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_BIT12_SHIFT
value|4
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_BIT13_MASK
value|0x1
comment|/* bit13 */
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_BIT13_SHIFT
value|5
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_TX_RULE_ACTIVE_MASK
value|0x1
comment|/* bit14 */
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_TX_RULE_ACTIVE_SHIFT
value|6
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_DQ_CF_ACTIVE_MASK
value|0x1
comment|/* bit15 */
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_DQ_CF_ACTIVE_SHIFT
value|7
name|u8
name|flags2
decl_stmt|;
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_CF0_MASK
value|0x3
comment|/* timer0cf */
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_CF0_SHIFT
value|0
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_CF1_MASK
value|0x3
comment|/* timer1cf */
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_CF1_SHIFT
value|2
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_CF2_MASK
value|0x3
comment|/* timer2cf */
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_CF2_SHIFT
value|4
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_CF3_MASK
value|0x3
comment|/* timer_stop_all */
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_CF3_SHIFT
value|6
name|u8
name|flags3
decl_stmt|;
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_CF4_MASK
value|0x3
comment|/* cf4 */
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_CF4_SHIFT
value|0
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_CF5_MASK
value|0x3
comment|/* cf5 */
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_CF5_SHIFT
value|2
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_CF6_MASK
value|0x3
comment|/* cf6 */
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_CF6_SHIFT
value|4
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_CF7_MASK
value|0x3
comment|/* cf7 */
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_CF7_SHIFT
value|6
name|u8
name|flags4
decl_stmt|;
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_CF8_MASK
value|0x3
comment|/* cf8 */
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_CF8_SHIFT
value|0
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_CF9_MASK
value|0x3
comment|/* cf9 */
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_CF9_SHIFT
value|2
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_CF10_MASK
value|0x3
comment|/* cf10 */
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_CF10_SHIFT
value|4
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_CF11_MASK
value|0x3
comment|/* cf11 */
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_CF11_SHIFT
value|6
name|u8
name|flags5
decl_stmt|;
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_CF12_MASK
value|0x3
comment|/* cf12 */
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_CF12_SHIFT
value|0
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_CF13_MASK
value|0x3
comment|/* cf13 */
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_CF13_SHIFT
value|2
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_CF14_MASK
value|0x3
comment|/* cf14 */
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_CF14_SHIFT
value|4
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_CF15_MASK
value|0x3
comment|/* cf15 */
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_CF15_SHIFT
value|6
name|u8
name|flags6
decl_stmt|;
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_GO_TO_BD_CONS_CF_MASK
value|0x3
comment|/* cf16 */
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_GO_TO_BD_CONS_CF_SHIFT
value|0
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_MULTI_UNICAST_CF_MASK
value|0x3
comment|/* cf_array_cf */
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_MULTI_UNICAST_CF_SHIFT
value|2
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_DQ_CF_MASK
value|0x3
comment|/* cf18 */
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_DQ_CF_SHIFT
value|4
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_TERMINATE_CF_MASK
value|0x3
comment|/* cf19 */
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_TERMINATE_CF_SHIFT
value|6
name|u8
name|flags7
decl_stmt|;
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_FLUSH_Q0_MASK
value|0x3
comment|/* cf20 */
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_FLUSH_Q0_SHIFT
value|0
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_RESERVED10_MASK
value|0x3
comment|/* cf21 */
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_RESERVED10_SHIFT
value|2
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_SLOW_PATH_MASK
value|0x3
comment|/* cf22 */
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_SLOW_PATH_SHIFT
value|4
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_CF0EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_CF0EN_SHIFT
value|6
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_CF1EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_CF1EN_SHIFT
value|7
name|u8
name|flags8
decl_stmt|;
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_CF2EN_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_CF2EN_SHIFT
value|0
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_CF3EN_MASK
value|0x1
comment|/* cf3en */
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_CF3EN_SHIFT
value|1
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_CF4EN_MASK
value|0x1
comment|/* cf4en */
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_CF4EN_SHIFT
value|2
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_CF5EN_MASK
value|0x1
comment|/* cf5en */
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_CF5EN_SHIFT
value|3
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_CF6EN_MASK
value|0x1
comment|/* cf6en */
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_CF6EN_SHIFT
value|4
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_CF7EN_MASK
value|0x1
comment|/* cf7en */
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_CF7EN_SHIFT
value|5
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_CF8EN_MASK
value|0x1
comment|/* cf8en */
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_CF8EN_SHIFT
value|6
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_CF9EN_MASK
value|0x1
comment|/* cf9en */
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_CF9EN_SHIFT
value|7
name|u8
name|flags9
decl_stmt|;
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_CF10EN_MASK
value|0x1
comment|/* cf10en */
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_CF10EN_SHIFT
value|0
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_CF11EN_MASK
value|0x1
comment|/* cf11en */
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_CF11EN_SHIFT
value|1
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_CF12EN_MASK
value|0x1
comment|/* cf12en */
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_CF12EN_SHIFT
value|2
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_CF13EN_MASK
value|0x1
comment|/* cf13en */
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_CF13EN_SHIFT
value|3
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_CF14EN_MASK
value|0x1
comment|/* cf14en */
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_CF14EN_SHIFT
value|4
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_CF15EN_MASK
value|0x1
comment|/* cf15en */
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_CF15EN_SHIFT
value|5
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_GO_TO_BD_CONS_CF_EN_MASK
value|0x1
comment|/* cf16en */
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_GO_TO_BD_CONS_CF_EN_SHIFT
value|6
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_MULTI_UNICAST_CF_EN_MASK
value|0x1
comment|/* cf_array_cf_en */
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_MULTI_UNICAST_CF_EN_SHIFT
value|7
name|u8
name|flags10
decl_stmt|;
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_DQ_CF_EN_MASK
value|0x1
comment|/* cf18en */
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_DQ_CF_EN_SHIFT
value|0
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_TERMINATE_CF_EN_MASK
value|0x1
comment|/* cf19en */
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_TERMINATE_CF_EN_SHIFT
value|1
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_FLUSH_Q0_EN_MASK
value|0x1
comment|/* cf20en */
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_FLUSH_Q0_EN_SHIFT
value|2
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_RESERVED11_MASK
value|0x1
comment|/* cf21en */
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_RESERVED11_SHIFT
value|3
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_SLOW_PATH_EN_MASK
value|0x1
comment|/* cf22en */
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_SLOW_PATH_EN_SHIFT
value|4
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_TPH_ENABLE_EN_RESERVED_MASK
value|0x1
comment|/* cf23en */
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_TPH_ENABLE_EN_RESERVED_SHIFT
value|5
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_RESERVED12_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_RESERVED12_SHIFT
value|6
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_RESERVED13_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_RESERVED13_SHIFT
value|7
name|u8
name|flags11
decl_stmt|;
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_RESERVED14_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_RESERVED14_SHIFT
value|0
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_RESERVED15_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_RESERVED15_SHIFT
value|1
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_TX_DEC_RULE_EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_TX_DEC_RULE_EN_SHIFT
value|2
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_RULE5EN_MASK
value|0x1
comment|/* rule5en */
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_RULE5EN_SHIFT
value|3
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_RULE6EN_MASK
value|0x1
comment|/* rule6en */
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_RULE6EN_SHIFT
value|4
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_RULE7EN_MASK
value|0x1
comment|/* rule7en */
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_RULE7EN_SHIFT
value|5
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_A0_RESERVED1_MASK
value|0x1
comment|/* rule8en */
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_A0_RESERVED1_SHIFT
value|6
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_RULE9EN_MASK
value|0x1
comment|/* rule9en */
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_RULE9EN_SHIFT
value|7
name|u8
name|flags12
decl_stmt|;
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_RULE10EN_MASK
value|0x1
comment|/* rule10en */
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_RULE10EN_SHIFT
value|0
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_RULE11EN_MASK
value|0x1
comment|/* rule11en */
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_RULE11EN_SHIFT
value|1
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_A0_RESERVED2_MASK
value|0x1
comment|/* rule12en */
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_A0_RESERVED2_SHIFT
value|2
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_A0_RESERVED3_MASK
value|0x1
comment|/* rule13en */
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_A0_RESERVED3_SHIFT
value|3
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_RULE14EN_MASK
value|0x1
comment|/* rule14en */
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_RULE14EN_SHIFT
value|4
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_RULE15EN_MASK
value|0x1
comment|/* rule15en */
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_RULE15EN_SHIFT
value|5
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_RULE16EN_MASK
value|0x1
comment|/* rule16en */
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_RULE16EN_SHIFT
value|6
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_RULE17EN_MASK
value|0x1
comment|/* rule17en */
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_RULE17EN_SHIFT
value|7
name|u8
name|flags13
decl_stmt|;
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_RULE18EN_MASK
value|0x1
comment|/* rule18en */
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_RULE18EN_SHIFT
value|0
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_RULE19EN_MASK
value|0x1
comment|/* rule19en */
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_RULE19EN_SHIFT
value|1
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_A0_RESERVED4_MASK
value|0x1
comment|/* rule20en */
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_A0_RESERVED4_SHIFT
value|2
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_A0_RESERVED5_MASK
value|0x1
comment|/* rule21en */
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_A0_RESERVED5_SHIFT
value|3
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_A0_RESERVED6_MASK
value|0x1
comment|/* rule22en */
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_A0_RESERVED6_SHIFT
value|4
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_A0_RESERVED7_MASK
value|0x1
comment|/* rule23en */
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_A0_RESERVED7_SHIFT
value|5
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_A0_RESERVED8_MASK
value|0x1
comment|/* rule24en */
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_A0_RESERVED8_SHIFT
value|6
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_A0_RESERVED9_MASK
value|0x1
comment|/* rule25en */
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_A0_RESERVED9_SHIFT
value|7
name|u8
name|flags14
decl_stmt|;
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_EDPM_USE_EXT_HDR_MASK
value|0x1
comment|/* bit16 */
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_EDPM_USE_EXT_HDR_SHIFT
value|0
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_EDPM_SEND_RAW_L3L4_MASK
value|0x1
comment|/* bit17 */
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_EDPM_SEND_RAW_L3L4_SHIFT
value|1
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_EDPM_INBAND_PROP_HDR_MASK
value|0x1
comment|/* bit18 */
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_EDPM_INBAND_PROP_HDR_SHIFT
value|2
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_EDPM_SEND_EXT_TUNNEL_MASK
value|0x1
comment|/* bit19 */
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_EDPM_SEND_EXT_TUNNEL_SHIFT
value|3
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_L2_EDPM_ENABLE_MASK
value|0x1
comment|/* bit20 */
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_L2_EDPM_ENABLE_SHIFT
value|4
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_ROCE_EDPM_ENABLE_MASK
value|0x1
comment|/* bit21 */
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_ROCE_EDPM_ENABLE_SHIFT
value|5
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_TPH_ENABLE_MASK
value|0x3
comment|/* cf23 */
define|#
directive|define
name|E4XSTORMETHCONNAGCTXDQEXTLDPART_TPH_ENABLE_SHIFT
value|6
name|u8
name|edpm_event_id
comment|/* byte2 */
decl_stmt|;
name|__le16
name|physical_q0
comment|/* physical_q0 */
decl_stmt|;
name|__le16
name|e5_reserved1
comment|/* physical_q1 */
decl_stmt|;
name|__le16
name|edpm_num_bds
comment|/* physical_q2 */
decl_stmt|;
name|__le16
name|tx_bd_cons
comment|/* word3 */
decl_stmt|;
name|__le16
name|tx_bd_prod
comment|/* word4 */
decl_stmt|;
name|__le16
name|tx_class
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
block|}
struct|;
end_struct

begin_struct
struct|struct
name|e4_mstorm_eth_conn_ag_ctx
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
name|E4_MSTORM_ETH_CONN_AG_CTX_EXIST_IN_QM0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E4_MSTORM_ETH_CONN_AG_CTX_EXIST_IN_QM0_SHIFT
value|0
define|#
directive|define
name|E4_MSTORM_ETH_CONN_AG_CTX_BIT1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E4_MSTORM_ETH_CONN_AG_CTX_BIT1_SHIFT
value|1
define|#
directive|define
name|E4_MSTORM_ETH_CONN_AG_CTX_CF0_MASK
value|0x3
comment|/* cf0 */
define|#
directive|define
name|E4_MSTORM_ETH_CONN_AG_CTX_CF0_SHIFT
value|2
define|#
directive|define
name|E4_MSTORM_ETH_CONN_AG_CTX_CF1_MASK
value|0x3
comment|/* cf1 */
define|#
directive|define
name|E4_MSTORM_ETH_CONN_AG_CTX_CF1_SHIFT
value|4
define|#
directive|define
name|E4_MSTORM_ETH_CONN_AG_CTX_CF2_MASK
value|0x3
comment|/* cf2 */
define|#
directive|define
name|E4_MSTORM_ETH_CONN_AG_CTX_CF2_SHIFT
value|6
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E4_MSTORM_ETH_CONN_AG_CTX_CF0EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E4_MSTORM_ETH_CONN_AG_CTX_CF0EN_SHIFT
value|0
define|#
directive|define
name|E4_MSTORM_ETH_CONN_AG_CTX_CF1EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E4_MSTORM_ETH_CONN_AG_CTX_CF1EN_SHIFT
value|1
define|#
directive|define
name|E4_MSTORM_ETH_CONN_AG_CTX_CF2EN_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E4_MSTORM_ETH_CONN_AG_CTX_CF2EN_SHIFT
value|2
define|#
directive|define
name|E4_MSTORM_ETH_CONN_AG_CTX_RULE0EN_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E4_MSTORM_ETH_CONN_AG_CTX_RULE0EN_SHIFT
value|3
define|#
directive|define
name|E4_MSTORM_ETH_CONN_AG_CTX_RULE1EN_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E4_MSTORM_ETH_CONN_AG_CTX_RULE1EN_SHIFT
value|4
define|#
directive|define
name|E4_MSTORM_ETH_CONN_AG_CTX_RULE2EN_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E4_MSTORM_ETH_CONN_AG_CTX_RULE2EN_SHIFT
value|5
define|#
directive|define
name|E4_MSTORM_ETH_CONN_AG_CTX_RULE3EN_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E4_MSTORM_ETH_CONN_AG_CTX_RULE3EN_SHIFT
value|6
define|#
directive|define
name|E4_MSTORM_ETH_CONN_AG_CTX_RULE4EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E4_MSTORM_ETH_CONN_AG_CTX_RULE4EN_SHIFT
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
name|e4_xstorm_eth_hw_conn_ag_ctx
block|{
name|u8
name|reserved0
comment|/* cdu_validation */
decl_stmt|;
name|u8
name|eth_state
comment|/* state */
decl_stmt|;
name|u8
name|flags0
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_EXIST_IN_QM0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_EXIST_IN_QM0_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_RESERVED1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_RESERVED1_SHIFT
value|1
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_RESERVED2_MASK
value|0x1
comment|/* exist_in_qm2 */
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_RESERVED2_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_EXIST_IN_QM3_MASK
value|0x1
comment|/* exist_in_qm3 */
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_EXIST_IN_QM3_SHIFT
value|3
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_RESERVED3_MASK
value|0x1
comment|/* bit4 */
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_RESERVED3_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_RESERVED4_MASK
value|0x1
comment|/* cf_array_active */
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_RESERVED4_SHIFT
value|5
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_RESERVED5_MASK
value|0x1
comment|/* bit6 */
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_RESERVED5_SHIFT
value|6
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_RESERVED6_MASK
value|0x1
comment|/* bit7 */
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_RESERVED6_SHIFT
value|7
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_RESERVED7_MASK
value|0x1
comment|/* bit8 */
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_RESERVED7_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_RESERVED8_MASK
value|0x1
comment|/* bit9 */
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_RESERVED8_SHIFT
value|1
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_RESERVED9_MASK
value|0x1
comment|/* bit10 */
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_RESERVED9_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_BIT11_MASK
value|0x1
comment|/* bit11 */
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_BIT11_SHIFT
value|3
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_BIT12_MASK
value|0x1
comment|/* bit12 */
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_BIT12_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_BIT13_MASK
value|0x1
comment|/* bit13 */
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_BIT13_SHIFT
value|5
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_TX_RULE_ACTIVE_MASK
value|0x1
comment|/* bit14 */
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_TX_RULE_ACTIVE_SHIFT
value|6
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_DQ_CF_ACTIVE_MASK
value|0x1
comment|/* bit15 */
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_DQ_CF_ACTIVE_SHIFT
value|7
name|u8
name|flags2
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_CF0_MASK
value|0x3
comment|/* timer0cf */
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_CF0_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_CF1_MASK
value|0x3
comment|/* timer1cf */
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_CF1_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_CF2_MASK
value|0x3
comment|/* timer2cf */
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_CF2_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_CF3_MASK
value|0x3
comment|/* timer_stop_all */
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_CF3_SHIFT
value|6
name|u8
name|flags3
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_CF4_MASK
value|0x3
comment|/* cf4 */
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_CF4_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_CF5_MASK
value|0x3
comment|/* cf5 */
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_CF5_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_CF6_MASK
value|0x3
comment|/* cf6 */
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_CF6_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_CF7_MASK
value|0x3
comment|/* cf7 */
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_CF7_SHIFT
value|6
name|u8
name|flags4
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_CF8_MASK
value|0x3
comment|/* cf8 */
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_CF8_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_CF9_MASK
value|0x3
comment|/* cf9 */
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_CF9_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_CF10_MASK
value|0x3
comment|/* cf10 */
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_CF10_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_CF11_MASK
value|0x3
comment|/* cf11 */
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_CF11_SHIFT
value|6
name|u8
name|flags5
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_CF12_MASK
value|0x3
comment|/* cf12 */
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_CF12_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_CF13_MASK
value|0x3
comment|/* cf13 */
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_CF13_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_CF14_MASK
value|0x3
comment|/* cf14 */
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_CF14_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_CF15_MASK
value|0x3
comment|/* cf15 */
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_CF15_SHIFT
value|6
name|u8
name|flags6
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_GO_TO_BD_CONS_CF_MASK
value|0x3
comment|/* cf16 */
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_GO_TO_BD_CONS_CF_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_MULTI_UNICAST_CF_MASK
value|0x3
comment|/* cf_array_cf */
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_MULTI_UNICAST_CF_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_DQ_CF_MASK
value|0x3
comment|/* cf18 */
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_DQ_CF_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_TERMINATE_CF_MASK
value|0x3
comment|/* cf19 */
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_TERMINATE_CF_SHIFT
value|6
name|u8
name|flags7
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_FLUSH_Q0_MASK
value|0x3
comment|/* cf20 */
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_FLUSH_Q0_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_RESERVED10_MASK
value|0x3
comment|/* cf21 */
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_RESERVED10_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_SLOW_PATH_MASK
value|0x3
comment|/* cf22 */
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_SLOW_PATH_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_CF0EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_CF0EN_SHIFT
value|6
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_CF1EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_CF1EN_SHIFT
value|7
name|u8
name|flags8
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_CF2EN_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_CF2EN_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_CF3EN_MASK
value|0x1
comment|/* cf3en */
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_CF3EN_SHIFT
value|1
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_CF4EN_MASK
value|0x1
comment|/* cf4en */
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_CF4EN_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_CF5EN_MASK
value|0x1
comment|/* cf5en */
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_CF5EN_SHIFT
value|3
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_CF6EN_MASK
value|0x1
comment|/* cf6en */
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_CF6EN_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_CF7EN_MASK
value|0x1
comment|/* cf7en */
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_CF7EN_SHIFT
value|5
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_CF8EN_MASK
value|0x1
comment|/* cf8en */
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_CF8EN_SHIFT
value|6
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_CF9EN_MASK
value|0x1
comment|/* cf9en */
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_CF9EN_SHIFT
value|7
name|u8
name|flags9
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_CF10EN_MASK
value|0x1
comment|/* cf10en */
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_CF10EN_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_CF11EN_MASK
value|0x1
comment|/* cf11en */
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_CF11EN_SHIFT
value|1
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_CF12EN_MASK
value|0x1
comment|/* cf12en */
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_CF12EN_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_CF13EN_MASK
value|0x1
comment|/* cf13en */
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_CF13EN_SHIFT
value|3
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_CF14EN_MASK
value|0x1
comment|/* cf14en */
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_CF14EN_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_CF15EN_MASK
value|0x1
comment|/* cf15en */
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_CF15EN_SHIFT
value|5
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_GO_TO_BD_CONS_CF_EN_MASK
value|0x1
comment|/* cf16en */
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_GO_TO_BD_CONS_CF_EN_SHIFT
value|6
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_MULTI_UNICAST_CF_EN_MASK
value|0x1
comment|/* cf_array_cf_en */
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_MULTI_UNICAST_CF_EN_SHIFT
value|7
name|u8
name|flags10
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_DQ_CF_EN_MASK
value|0x1
comment|/* cf18en */
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_DQ_CF_EN_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_TERMINATE_CF_EN_MASK
value|0x1
comment|/* cf19en */
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_TERMINATE_CF_EN_SHIFT
value|1
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_FLUSH_Q0_EN_MASK
value|0x1
comment|/* cf20en */
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_FLUSH_Q0_EN_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_RESERVED11_MASK
value|0x1
comment|/* cf21en */
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_RESERVED11_SHIFT
value|3
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_SLOW_PATH_EN_MASK
value|0x1
comment|/* cf22en */
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_SLOW_PATH_EN_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_TPH_ENABLE_EN_RESERVED_MASK
value|0x1
comment|/* cf23en */
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_TPH_ENABLE_EN_RESERVED_SHIFT
value|5
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_RESERVED12_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_RESERVED12_SHIFT
value|6
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_RESERVED13_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_RESERVED13_SHIFT
value|7
name|u8
name|flags11
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_RESERVED14_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_RESERVED14_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_RESERVED15_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_RESERVED15_SHIFT
value|1
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_TX_DEC_RULE_EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_TX_DEC_RULE_EN_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_RULE5EN_MASK
value|0x1
comment|/* rule5en */
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_RULE5EN_SHIFT
value|3
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_RULE6EN_MASK
value|0x1
comment|/* rule6en */
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_RULE6EN_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_RULE7EN_MASK
value|0x1
comment|/* rule7en */
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_RULE7EN_SHIFT
value|5
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_A0_RESERVED1_MASK
value|0x1
comment|/* rule8en */
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_A0_RESERVED1_SHIFT
value|6
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_RULE9EN_MASK
value|0x1
comment|/* rule9en */
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_RULE9EN_SHIFT
value|7
name|u8
name|flags12
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_RULE10EN_MASK
value|0x1
comment|/* rule10en */
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_RULE10EN_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_RULE11EN_MASK
value|0x1
comment|/* rule11en */
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_RULE11EN_SHIFT
value|1
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_A0_RESERVED2_MASK
value|0x1
comment|/* rule12en */
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_A0_RESERVED2_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_A0_RESERVED3_MASK
value|0x1
comment|/* rule13en */
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_A0_RESERVED3_SHIFT
value|3
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_RULE14EN_MASK
value|0x1
comment|/* rule14en */
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_RULE14EN_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_RULE15EN_MASK
value|0x1
comment|/* rule15en */
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_RULE15EN_SHIFT
value|5
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_RULE16EN_MASK
value|0x1
comment|/* rule16en */
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_RULE16EN_SHIFT
value|6
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_RULE17EN_MASK
value|0x1
comment|/* rule17en */
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_RULE17EN_SHIFT
value|7
name|u8
name|flags13
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_RULE18EN_MASK
value|0x1
comment|/* rule18en */
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_RULE18EN_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_RULE19EN_MASK
value|0x1
comment|/* rule19en */
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_RULE19EN_SHIFT
value|1
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_A0_RESERVED4_MASK
value|0x1
comment|/* rule20en */
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_A0_RESERVED4_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_A0_RESERVED5_MASK
value|0x1
comment|/* rule21en */
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_A0_RESERVED5_SHIFT
value|3
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_A0_RESERVED6_MASK
value|0x1
comment|/* rule22en */
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_A0_RESERVED6_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_A0_RESERVED7_MASK
value|0x1
comment|/* rule23en */
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_A0_RESERVED7_SHIFT
value|5
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_A0_RESERVED8_MASK
value|0x1
comment|/* rule24en */
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_A0_RESERVED8_SHIFT
value|6
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_A0_RESERVED9_MASK
value|0x1
comment|/* rule25en */
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_A0_RESERVED9_SHIFT
value|7
name|u8
name|flags14
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_EDPM_USE_EXT_HDR_MASK
value|0x1
comment|/* bit16 */
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_EDPM_USE_EXT_HDR_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_EDPM_SEND_RAW_L3L4_MASK
value|0x1
comment|/* bit17 */
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_EDPM_SEND_RAW_L3L4_SHIFT
value|1
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_EDPM_INBAND_PROP_HDR_MASK
value|0x1
comment|/* bit18 */
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_EDPM_INBAND_PROP_HDR_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_EDPM_SEND_EXT_TUNNEL_MASK
value|0x1
comment|/* bit19 */
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_EDPM_SEND_EXT_TUNNEL_SHIFT
value|3
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_L2_EDPM_ENABLE_MASK
value|0x1
comment|/* bit20 */
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_L2_EDPM_ENABLE_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_ROCE_EDPM_ENABLE_MASK
value|0x1
comment|/* bit21 */
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_ROCE_EDPM_ENABLE_SHIFT
value|5
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_TPH_ENABLE_MASK
value|0x3
comment|/* cf23 */
define|#
directive|define
name|E4_XSTORM_ETH_HW_CONN_AG_CTX_TPH_ENABLE_SHIFT
value|6
name|u8
name|edpm_event_id
comment|/* byte2 */
decl_stmt|;
name|__le16
name|physical_q0
comment|/* physical_q0 */
decl_stmt|;
name|__le16
name|e5_reserved1
comment|/* physical_q1 */
decl_stmt|;
name|__le16
name|edpm_num_bds
comment|/* physical_q2 */
decl_stmt|;
name|__le16
name|tx_bd_cons
comment|/* word3 */
decl_stmt|;
name|__le16
name|tx_bd_prod
comment|/* word4 */
decl_stmt|;
name|__le16
name|tx_class
comment|/* word5 */
decl_stmt|;
name|__le16
name|conn_dpi
comment|/* conn_dpi */
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|E5XstormEthConnAgCtxDqExtLdPart
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
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_EXIST_IN_QM0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_EXIST_IN_QM0_SHIFT
value|0
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_RESERVED1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_RESERVED1_SHIFT
value|1
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_RESERVED2_MASK
value|0x1
comment|/* exist_in_qm2 */
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_RESERVED2_SHIFT
value|2
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_EXIST_IN_QM3_MASK
value|0x1
comment|/* exist_in_qm3 */
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_EXIST_IN_QM3_SHIFT
value|3
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_RESERVED3_MASK
value|0x1
comment|/* bit4 */
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_RESERVED3_SHIFT
value|4
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_RESERVED4_MASK
value|0x1
comment|/* cf_array_active */
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_RESERVED4_SHIFT
value|5
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_RESERVED5_MASK
value|0x1
comment|/* bit6 */
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_RESERVED5_SHIFT
value|6
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_RESERVED6_MASK
value|0x1
comment|/* bit7 */
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_RESERVED6_SHIFT
value|7
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_RESERVED7_MASK
value|0x1
comment|/* bit8 */
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_RESERVED7_SHIFT
value|0
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_RESERVED8_MASK
value|0x1
comment|/* bit9 */
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_RESERVED8_SHIFT
value|1
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_RESERVED9_MASK
value|0x1
comment|/* bit10 */
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_RESERVED9_SHIFT
value|2
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_BIT11_MASK
value|0x1
comment|/* bit11 */
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_BIT11_SHIFT
value|3
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_BIT12_MASK
value|0x1
comment|/* bit12 */
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_BIT12_SHIFT
value|4
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_BIT13_MASK
value|0x1
comment|/* bit13 */
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_BIT13_SHIFT
value|5
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_TX_RULE_ACTIVE_MASK
value|0x1
comment|/* bit14 */
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_TX_RULE_ACTIVE_SHIFT
value|6
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_DQ_CF_ACTIVE_MASK
value|0x1
comment|/* bit15 */
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_DQ_CF_ACTIVE_SHIFT
value|7
name|u8
name|flags2
decl_stmt|;
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_CF0_MASK
value|0x3
comment|/* timer0cf */
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_CF0_SHIFT
value|0
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_CF1_MASK
value|0x3
comment|/* timer1cf */
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_CF1_SHIFT
value|2
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_CF2_MASK
value|0x3
comment|/* timer2cf */
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_CF2_SHIFT
value|4
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_CF3_MASK
value|0x3
comment|/* timer_stop_all */
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_CF3_SHIFT
value|6
name|u8
name|flags3
decl_stmt|;
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_CF4_MASK
value|0x3
comment|/* cf4 */
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_CF4_SHIFT
value|0
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_CF5_MASK
value|0x3
comment|/* cf5 */
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_CF5_SHIFT
value|2
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_CF6_MASK
value|0x3
comment|/* cf6 */
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_CF6_SHIFT
value|4
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_CF7_MASK
value|0x3
comment|/* cf7 */
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_CF7_SHIFT
value|6
name|u8
name|flags4
decl_stmt|;
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_CF8_MASK
value|0x3
comment|/* cf8 */
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_CF8_SHIFT
value|0
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_CF9_MASK
value|0x3
comment|/* cf9 */
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_CF9_SHIFT
value|2
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_CF10_MASK
value|0x3
comment|/* cf10 */
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_CF10_SHIFT
value|4
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_CF11_MASK
value|0x3
comment|/* cf11 */
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_CF11_SHIFT
value|6
name|u8
name|flags5
decl_stmt|;
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_CF12_MASK
value|0x3
comment|/* cf12 */
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_CF12_SHIFT
value|0
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_CF13_MASK
value|0x3
comment|/* cf13 */
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_CF13_SHIFT
value|2
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_CF14_MASK
value|0x3
comment|/* cf14 */
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_CF14_SHIFT
value|4
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_CF15_MASK
value|0x3
comment|/* cf15 */
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_CF15_SHIFT
value|6
name|u8
name|flags6
decl_stmt|;
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_GO_TO_BD_CONS_CF_MASK
value|0x3
comment|/* cf16 */
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_GO_TO_BD_CONS_CF_SHIFT
value|0
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_MULTI_UNICAST_CF_MASK
value|0x3
comment|/* cf_array_cf */
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_MULTI_UNICAST_CF_SHIFT
value|2
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_DQ_CF_MASK
value|0x3
comment|/* cf18 */
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_DQ_CF_SHIFT
value|4
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_TERMINATE_CF_MASK
value|0x3
comment|/* cf19 */
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_TERMINATE_CF_SHIFT
value|6
name|u8
name|flags7
decl_stmt|;
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_FLUSH_Q0_MASK
value|0x3
comment|/* cf20 */
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_FLUSH_Q0_SHIFT
value|0
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_RESERVED10_MASK
value|0x3
comment|/* cf21 */
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_RESERVED10_SHIFT
value|2
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_SLOW_PATH_MASK
value|0x3
comment|/* cf22 */
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_SLOW_PATH_SHIFT
value|4
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_CF0EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_CF0EN_SHIFT
value|6
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_CF1EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_CF1EN_SHIFT
value|7
name|u8
name|flags8
decl_stmt|;
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_CF2EN_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_CF2EN_SHIFT
value|0
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_CF3EN_MASK
value|0x1
comment|/* cf3en */
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_CF3EN_SHIFT
value|1
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_CF4EN_MASK
value|0x1
comment|/* cf4en */
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_CF4EN_SHIFT
value|2
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_CF5EN_MASK
value|0x1
comment|/* cf5en */
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_CF5EN_SHIFT
value|3
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_CF6EN_MASK
value|0x1
comment|/* cf6en */
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_CF6EN_SHIFT
value|4
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_CF7EN_MASK
value|0x1
comment|/* cf7en */
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_CF7EN_SHIFT
value|5
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_CF8EN_MASK
value|0x1
comment|/* cf8en */
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_CF8EN_SHIFT
value|6
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_CF9EN_MASK
value|0x1
comment|/* cf9en */
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_CF9EN_SHIFT
value|7
name|u8
name|flags9
decl_stmt|;
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_CF10EN_MASK
value|0x1
comment|/* cf10en */
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_CF10EN_SHIFT
value|0
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_CF11EN_MASK
value|0x1
comment|/* cf11en */
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_CF11EN_SHIFT
value|1
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_CF12EN_MASK
value|0x1
comment|/* cf12en */
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_CF12EN_SHIFT
value|2
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_CF13EN_MASK
value|0x1
comment|/* cf13en */
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_CF13EN_SHIFT
value|3
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_CF14EN_MASK
value|0x1
comment|/* cf14en */
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_CF14EN_SHIFT
value|4
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_CF15EN_MASK
value|0x1
comment|/* cf15en */
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_CF15EN_SHIFT
value|5
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_GO_TO_BD_CONS_CF_EN_MASK
value|0x1
comment|/* cf16en */
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_GO_TO_BD_CONS_CF_EN_SHIFT
value|6
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_MULTI_UNICAST_CF_EN_MASK
value|0x1
comment|/* cf_array_cf_en */
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_MULTI_UNICAST_CF_EN_SHIFT
value|7
name|u8
name|flags10
decl_stmt|;
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_DQ_CF_EN_MASK
value|0x1
comment|/* cf18en */
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_DQ_CF_EN_SHIFT
value|0
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_TERMINATE_CF_EN_MASK
value|0x1
comment|/* cf19en */
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_TERMINATE_CF_EN_SHIFT
value|1
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_FLUSH_Q0_EN_MASK
value|0x1
comment|/* cf20en */
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_FLUSH_Q0_EN_SHIFT
value|2
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_RESERVED11_MASK
value|0x1
comment|/* cf21en */
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_RESERVED11_SHIFT
value|3
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_SLOW_PATH_EN_MASK
value|0x1
comment|/* cf22en */
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_SLOW_PATH_EN_SHIFT
value|4
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_TPH_ENABLE_EN_RESERVED_MASK
value|0x1
comment|/* cf23en */
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_TPH_ENABLE_EN_RESERVED_SHIFT
value|5
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_RESERVED12_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_RESERVED12_SHIFT
value|6
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_RESERVED13_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_RESERVED13_SHIFT
value|7
name|u8
name|flags11
decl_stmt|;
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_RESERVED14_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_RESERVED14_SHIFT
value|0
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_RESERVED15_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_RESERVED15_SHIFT
value|1
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_TX_DEC_RULE_EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_TX_DEC_RULE_EN_SHIFT
value|2
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_RULE5EN_MASK
value|0x1
comment|/* rule5en */
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_RULE5EN_SHIFT
value|3
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_RULE6EN_MASK
value|0x1
comment|/* rule6en */
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_RULE6EN_SHIFT
value|4
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_RULE7EN_MASK
value|0x1
comment|/* rule7en */
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_RULE7EN_SHIFT
value|5
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_A0_RESERVED1_MASK
value|0x1
comment|/* rule8en */
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_A0_RESERVED1_SHIFT
value|6
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_RULE9EN_MASK
value|0x1
comment|/* rule9en */
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_RULE9EN_SHIFT
value|7
name|u8
name|flags12
decl_stmt|;
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_RULE10EN_MASK
value|0x1
comment|/* rule10en */
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_RULE10EN_SHIFT
value|0
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_RULE11EN_MASK
value|0x1
comment|/* rule11en */
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_RULE11EN_SHIFT
value|1
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_A0_RESERVED2_MASK
value|0x1
comment|/* rule12en */
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_A0_RESERVED2_SHIFT
value|2
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_A0_RESERVED3_MASK
value|0x1
comment|/* rule13en */
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_A0_RESERVED3_SHIFT
value|3
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_RULE14EN_MASK
value|0x1
comment|/* rule14en */
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_RULE14EN_SHIFT
value|4
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_RULE15EN_MASK
value|0x1
comment|/* rule15en */
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_RULE15EN_SHIFT
value|5
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_RULE16EN_MASK
value|0x1
comment|/* rule16en */
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_RULE16EN_SHIFT
value|6
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_RULE17EN_MASK
value|0x1
comment|/* rule17en */
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_RULE17EN_SHIFT
value|7
name|u8
name|flags13
decl_stmt|;
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_RULE18EN_MASK
value|0x1
comment|/* rule18en */
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_RULE18EN_SHIFT
value|0
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_RULE19EN_MASK
value|0x1
comment|/* rule19en */
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_RULE19EN_SHIFT
value|1
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_A0_RESERVED4_MASK
value|0x1
comment|/* rule20en */
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_A0_RESERVED4_SHIFT
value|2
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_A0_RESERVED5_MASK
value|0x1
comment|/* rule21en */
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_A0_RESERVED5_SHIFT
value|3
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_A0_RESERVED6_MASK
value|0x1
comment|/* rule22en */
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_A0_RESERVED6_SHIFT
value|4
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_A0_RESERVED7_MASK
value|0x1
comment|/* rule23en */
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_A0_RESERVED7_SHIFT
value|5
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_A0_RESERVED8_MASK
value|0x1
comment|/* rule24en */
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_A0_RESERVED8_SHIFT
value|6
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_A0_RESERVED9_MASK
value|0x1
comment|/* rule25en */
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_A0_RESERVED9_SHIFT
value|7
name|u8
name|flags14
decl_stmt|;
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_EDPM_USE_EXT_HDR_MASK
value|0x1
comment|/* bit16 */
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_EDPM_USE_EXT_HDR_SHIFT
value|0
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_EDPM_SEND_RAW_L3L4_MASK
value|0x1
comment|/* bit17 */
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_EDPM_SEND_RAW_L3L4_SHIFT
value|1
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_EDPM_INBAND_PROP_HDR_MASK
value|0x1
comment|/* bit18 */
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_EDPM_INBAND_PROP_HDR_SHIFT
value|2
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_EDPM_SEND_EXT_TUNNEL_MASK
value|0x1
comment|/* bit19 */
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_EDPM_SEND_EXT_TUNNEL_SHIFT
value|3
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_L2_EDPM_ENABLE_MASK
value|0x1
comment|/* bit20 */
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_L2_EDPM_ENABLE_SHIFT
value|4
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_ROCE_EDPM_ENABLE_MASK
value|0x1
comment|/* bit21 */
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_ROCE_EDPM_ENABLE_SHIFT
value|5
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_TPH_ENABLE_MASK
value|0x3
comment|/* cf23 */
define|#
directive|define
name|E5XSTORMETHCONNAGCTXDQEXTLDPART_TPH_ENABLE_SHIFT
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
name|tx_l2_edpm_usg_cnt
comment|/* physical_q1 */
decl_stmt|;
name|__le16
name|edpm_num_bds
comment|/* physical_q2 */
decl_stmt|;
name|__le16
name|tx_bd_cons
comment|/* word3 */
decl_stmt|;
name|__le16
name|tx_bd_prod
comment|/* word4 */
decl_stmt|;
name|__le16
name|tx_class
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
block|}
struct|;
end_struct

begin_struct
struct|struct
name|e5_mstorm_eth_conn_ag_ctx
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
name|E5_MSTORM_ETH_CONN_AG_CTX_EXIST_IN_QM0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E5_MSTORM_ETH_CONN_AG_CTX_EXIST_IN_QM0_SHIFT
value|0
define|#
directive|define
name|E5_MSTORM_ETH_CONN_AG_CTX_BIT1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E5_MSTORM_ETH_CONN_AG_CTX_BIT1_SHIFT
value|1
define|#
directive|define
name|E5_MSTORM_ETH_CONN_AG_CTX_CF0_MASK
value|0x3
comment|/* cf0 */
define|#
directive|define
name|E5_MSTORM_ETH_CONN_AG_CTX_CF0_SHIFT
value|2
define|#
directive|define
name|E5_MSTORM_ETH_CONN_AG_CTX_CF1_MASK
value|0x3
comment|/* cf1 */
define|#
directive|define
name|E5_MSTORM_ETH_CONN_AG_CTX_CF1_SHIFT
value|4
define|#
directive|define
name|E5_MSTORM_ETH_CONN_AG_CTX_CF2_MASK
value|0x3
comment|/* cf2 */
define|#
directive|define
name|E5_MSTORM_ETH_CONN_AG_CTX_CF2_SHIFT
value|6
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E5_MSTORM_ETH_CONN_AG_CTX_CF0EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E5_MSTORM_ETH_CONN_AG_CTX_CF0EN_SHIFT
value|0
define|#
directive|define
name|E5_MSTORM_ETH_CONN_AG_CTX_CF1EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E5_MSTORM_ETH_CONN_AG_CTX_CF1EN_SHIFT
value|1
define|#
directive|define
name|E5_MSTORM_ETH_CONN_AG_CTX_CF2EN_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E5_MSTORM_ETH_CONN_AG_CTX_CF2EN_SHIFT
value|2
define|#
directive|define
name|E5_MSTORM_ETH_CONN_AG_CTX_RULE0EN_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E5_MSTORM_ETH_CONN_AG_CTX_RULE0EN_SHIFT
value|3
define|#
directive|define
name|E5_MSTORM_ETH_CONN_AG_CTX_RULE1EN_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E5_MSTORM_ETH_CONN_AG_CTX_RULE1EN_SHIFT
value|4
define|#
directive|define
name|E5_MSTORM_ETH_CONN_AG_CTX_RULE2EN_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E5_MSTORM_ETH_CONN_AG_CTX_RULE2EN_SHIFT
value|5
define|#
directive|define
name|E5_MSTORM_ETH_CONN_AG_CTX_RULE3EN_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E5_MSTORM_ETH_CONN_AG_CTX_RULE3EN_SHIFT
value|6
define|#
directive|define
name|E5_MSTORM_ETH_CONN_AG_CTX_RULE4EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E5_MSTORM_ETH_CONN_AG_CTX_RULE4EN_SHIFT
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
name|e5_tstorm_eth_conn_ag_ctx
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
name|E5_TSTORM_ETH_CONN_AG_CTX_BIT0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E5_TSTORM_ETH_CONN_AG_CTX_BIT0_SHIFT
value|0
define|#
directive|define
name|E5_TSTORM_ETH_CONN_AG_CTX_BIT1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E5_TSTORM_ETH_CONN_AG_CTX_BIT1_SHIFT
value|1
define|#
directive|define
name|E5_TSTORM_ETH_CONN_AG_CTX_BIT2_MASK
value|0x1
comment|/* bit2 */
define|#
directive|define
name|E5_TSTORM_ETH_CONN_AG_CTX_BIT2_SHIFT
value|2
define|#
directive|define
name|E5_TSTORM_ETH_CONN_AG_CTX_BIT3_MASK
value|0x1
comment|/* bit3 */
define|#
directive|define
name|E5_TSTORM_ETH_CONN_AG_CTX_BIT3_SHIFT
value|3
define|#
directive|define
name|E5_TSTORM_ETH_CONN_AG_CTX_BIT4_MASK
value|0x1
comment|/* bit4 */
define|#
directive|define
name|E5_TSTORM_ETH_CONN_AG_CTX_BIT4_SHIFT
value|4
define|#
directive|define
name|E5_TSTORM_ETH_CONN_AG_CTX_BIT5_MASK
value|0x1
comment|/* bit5 */
define|#
directive|define
name|E5_TSTORM_ETH_CONN_AG_CTX_BIT5_SHIFT
value|5
define|#
directive|define
name|E5_TSTORM_ETH_CONN_AG_CTX_CF0_MASK
value|0x3
comment|/* timer0cf */
define|#
directive|define
name|E5_TSTORM_ETH_CONN_AG_CTX_CF0_SHIFT
value|6
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E5_TSTORM_ETH_CONN_AG_CTX_CF1_MASK
value|0x3
comment|/* timer1cf */
define|#
directive|define
name|E5_TSTORM_ETH_CONN_AG_CTX_CF1_SHIFT
value|0
define|#
directive|define
name|E5_TSTORM_ETH_CONN_AG_CTX_CF2_MASK
value|0x3
comment|/* timer2cf */
define|#
directive|define
name|E5_TSTORM_ETH_CONN_AG_CTX_CF2_SHIFT
value|2
define|#
directive|define
name|E5_TSTORM_ETH_CONN_AG_CTX_CF3_MASK
value|0x3
comment|/* timer_stop_all */
define|#
directive|define
name|E5_TSTORM_ETH_CONN_AG_CTX_CF3_SHIFT
value|4
define|#
directive|define
name|E5_TSTORM_ETH_CONN_AG_CTX_CF4_MASK
value|0x3
comment|/* cf4 */
define|#
directive|define
name|E5_TSTORM_ETH_CONN_AG_CTX_CF4_SHIFT
value|6
name|u8
name|flags2
decl_stmt|;
define|#
directive|define
name|E5_TSTORM_ETH_CONN_AG_CTX_CF5_MASK
value|0x3
comment|/* cf5 */
define|#
directive|define
name|E5_TSTORM_ETH_CONN_AG_CTX_CF5_SHIFT
value|0
define|#
directive|define
name|E5_TSTORM_ETH_CONN_AG_CTX_CF6_MASK
value|0x3
comment|/* cf6 */
define|#
directive|define
name|E5_TSTORM_ETH_CONN_AG_CTX_CF6_SHIFT
value|2
define|#
directive|define
name|E5_TSTORM_ETH_CONN_AG_CTX_CF7_MASK
value|0x3
comment|/* cf7 */
define|#
directive|define
name|E5_TSTORM_ETH_CONN_AG_CTX_CF7_SHIFT
value|4
define|#
directive|define
name|E5_TSTORM_ETH_CONN_AG_CTX_CF8_MASK
value|0x3
comment|/* cf8 */
define|#
directive|define
name|E5_TSTORM_ETH_CONN_AG_CTX_CF8_SHIFT
value|6
name|u8
name|flags3
decl_stmt|;
define|#
directive|define
name|E5_TSTORM_ETH_CONN_AG_CTX_CF9_MASK
value|0x3
comment|/* cf9 */
define|#
directive|define
name|E5_TSTORM_ETH_CONN_AG_CTX_CF9_SHIFT
value|0
define|#
directive|define
name|E5_TSTORM_ETH_CONN_AG_CTX_CF10_MASK
value|0x3
comment|/* cf10 */
define|#
directive|define
name|E5_TSTORM_ETH_CONN_AG_CTX_CF10_SHIFT
value|2
define|#
directive|define
name|E5_TSTORM_ETH_CONN_AG_CTX_CF0EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E5_TSTORM_ETH_CONN_AG_CTX_CF0EN_SHIFT
value|4
define|#
directive|define
name|E5_TSTORM_ETH_CONN_AG_CTX_CF1EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E5_TSTORM_ETH_CONN_AG_CTX_CF1EN_SHIFT
value|5
define|#
directive|define
name|E5_TSTORM_ETH_CONN_AG_CTX_CF2EN_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E5_TSTORM_ETH_CONN_AG_CTX_CF2EN_SHIFT
value|6
define|#
directive|define
name|E5_TSTORM_ETH_CONN_AG_CTX_CF3EN_MASK
value|0x1
comment|/* cf3en */
define|#
directive|define
name|E5_TSTORM_ETH_CONN_AG_CTX_CF3EN_SHIFT
value|7
name|u8
name|flags4
decl_stmt|;
define|#
directive|define
name|E5_TSTORM_ETH_CONN_AG_CTX_CF4EN_MASK
value|0x1
comment|/* cf4en */
define|#
directive|define
name|E5_TSTORM_ETH_CONN_AG_CTX_CF4EN_SHIFT
value|0
define|#
directive|define
name|E5_TSTORM_ETH_CONN_AG_CTX_CF5EN_MASK
value|0x1
comment|/* cf5en */
define|#
directive|define
name|E5_TSTORM_ETH_CONN_AG_CTX_CF5EN_SHIFT
value|1
define|#
directive|define
name|E5_TSTORM_ETH_CONN_AG_CTX_CF6EN_MASK
value|0x1
comment|/* cf6en */
define|#
directive|define
name|E5_TSTORM_ETH_CONN_AG_CTX_CF6EN_SHIFT
value|2
define|#
directive|define
name|E5_TSTORM_ETH_CONN_AG_CTX_CF7EN_MASK
value|0x1
comment|/* cf7en */
define|#
directive|define
name|E5_TSTORM_ETH_CONN_AG_CTX_CF7EN_SHIFT
value|3
define|#
directive|define
name|E5_TSTORM_ETH_CONN_AG_CTX_CF8EN_MASK
value|0x1
comment|/* cf8en */
define|#
directive|define
name|E5_TSTORM_ETH_CONN_AG_CTX_CF8EN_SHIFT
value|4
define|#
directive|define
name|E5_TSTORM_ETH_CONN_AG_CTX_CF9EN_MASK
value|0x1
comment|/* cf9en */
define|#
directive|define
name|E5_TSTORM_ETH_CONN_AG_CTX_CF9EN_SHIFT
value|5
define|#
directive|define
name|E5_TSTORM_ETH_CONN_AG_CTX_CF10EN_MASK
value|0x1
comment|/* cf10en */
define|#
directive|define
name|E5_TSTORM_ETH_CONN_AG_CTX_CF10EN_SHIFT
value|6
define|#
directive|define
name|E5_TSTORM_ETH_CONN_AG_CTX_RULE0EN_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E5_TSTORM_ETH_CONN_AG_CTX_RULE0EN_SHIFT
value|7
name|u8
name|flags5
decl_stmt|;
define|#
directive|define
name|E5_TSTORM_ETH_CONN_AG_CTX_RULE1EN_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E5_TSTORM_ETH_CONN_AG_CTX_RULE1EN_SHIFT
value|0
define|#
directive|define
name|E5_TSTORM_ETH_CONN_AG_CTX_RULE2EN_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E5_TSTORM_ETH_CONN_AG_CTX_RULE2EN_SHIFT
value|1
define|#
directive|define
name|E5_TSTORM_ETH_CONN_AG_CTX_RULE3EN_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E5_TSTORM_ETH_CONN_AG_CTX_RULE3EN_SHIFT
value|2
define|#
directive|define
name|E5_TSTORM_ETH_CONN_AG_CTX_RULE4EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E5_TSTORM_ETH_CONN_AG_CTX_RULE4EN_SHIFT
value|3
define|#
directive|define
name|E5_TSTORM_ETH_CONN_AG_CTX_RULE5EN_MASK
value|0x1
comment|/* rule5en */
define|#
directive|define
name|E5_TSTORM_ETH_CONN_AG_CTX_RULE5EN_SHIFT
value|4
define|#
directive|define
name|E5_TSTORM_ETH_CONN_AG_CTX_RX_BD_EN_MASK
value|0x1
comment|/* rule6en */
define|#
directive|define
name|E5_TSTORM_ETH_CONN_AG_CTX_RX_BD_EN_SHIFT
value|5
define|#
directive|define
name|E5_TSTORM_ETH_CONN_AG_CTX_RULE7EN_MASK
value|0x1
comment|/* rule7en */
define|#
directive|define
name|E5_TSTORM_ETH_CONN_AG_CTX_RULE7EN_SHIFT
value|6
define|#
directive|define
name|E5_TSTORM_ETH_CONN_AG_CTX_RULE8EN_MASK
value|0x1
comment|/* rule8en */
define|#
directive|define
name|E5_TSTORM_ETH_CONN_AG_CTX_RULE8EN_SHIFT
value|7
name|u8
name|flags6
decl_stmt|;
define|#
directive|define
name|E5_TSTORM_ETH_CONN_AG_CTX_E4_RESERVED1_MASK
value|0x1
comment|/* bit6 */
define|#
directive|define
name|E5_TSTORM_ETH_CONN_AG_CTX_E4_RESERVED1_SHIFT
value|0
define|#
directive|define
name|E5_TSTORM_ETH_CONN_AG_CTX_E4_RESERVED2_MASK
value|0x1
comment|/* bit7 */
define|#
directive|define
name|E5_TSTORM_ETH_CONN_AG_CTX_E4_RESERVED2_SHIFT
value|1
define|#
directive|define
name|E5_TSTORM_ETH_CONN_AG_CTX_E4_RESERVED3_MASK
value|0x1
comment|/* bit8 */
define|#
directive|define
name|E5_TSTORM_ETH_CONN_AG_CTX_E4_RESERVED3_SHIFT
value|2
define|#
directive|define
name|E5_TSTORM_ETH_CONN_AG_CTX_E4_RESERVED4_MASK
value|0x3
comment|/* cf11 */
define|#
directive|define
name|E5_TSTORM_ETH_CONN_AG_CTX_E4_RESERVED4_SHIFT
value|3
define|#
directive|define
name|E5_TSTORM_ETH_CONN_AG_CTX_E4_RESERVED5_MASK
value|0x1
comment|/* cf11en */
define|#
directive|define
name|E5_TSTORM_ETH_CONN_AG_CTX_E4_RESERVED5_SHIFT
value|5
define|#
directive|define
name|E5_TSTORM_ETH_CONN_AG_CTX_E4_RESERVED6_MASK
value|0x1
comment|/* rule9en */
define|#
directive|define
name|E5_TSTORM_ETH_CONN_AG_CTX_E4_RESERVED6_SHIFT
value|6
define|#
directive|define
name|E5_TSTORM_ETH_CONN_AG_CTX_E4_RESERVED7_MASK
value|0x1
comment|/* rule10en */
define|#
directive|define
name|E5_TSTORM_ETH_CONN_AG_CTX_E4_RESERVED7_SHIFT
value|7
name|u8
name|byte2
comment|/* byte2 */
decl_stmt|;
name|__le16
name|rx_bd_cons
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
name|rx_bd_prod
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
name|e5_ustorm_eth_conn_ag_ctx
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
name|E5_USTORM_ETH_CONN_AG_CTX_BIT0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E5_USTORM_ETH_CONN_AG_CTX_BIT0_SHIFT
value|0
define|#
directive|define
name|E5_USTORM_ETH_CONN_AG_CTX_BIT1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E5_USTORM_ETH_CONN_AG_CTX_BIT1_SHIFT
value|1
define|#
directive|define
name|E5_USTORM_ETH_CONN_AG_CTX_TX_PMD_TERMINATE_CF_MASK
value|0x3
comment|/* timer0cf */
define|#
directive|define
name|E5_USTORM_ETH_CONN_AG_CTX_TX_PMD_TERMINATE_CF_SHIFT
value|2
define|#
directive|define
name|E5_USTORM_ETH_CONN_AG_CTX_RX_PMD_TERMINATE_CF_MASK
value|0x3
comment|/* timer1cf */
define|#
directive|define
name|E5_USTORM_ETH_CONN_AG_CTX_RX_PMD_TERMINATE_CF_SHIFT
value|4
define|#
directive|define
name|E5_USTORM_ETH_CONN_AG_CTX_CF2_MASK
value|0x3
comment|/* timer2cf */
define|#
directive|define
name|E5_USTORM_ETH_CONN_AG_CTX_CF2_SHIFT
value|6
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E5_USTORM_ETH_CONN_AG_CTX_CF3_MASK
value|0x3
comment|/* timer_stop_all */
define|#
directive|define
name|E5_USTORM_ETH_CONN_AG_CTX_CF3_SHIFT
value|0
define|#
directive|define
name|E5_USTORM_ETH_CONN_AG_CTX_TX_ARM_CF_MASK
value|0x3
comment|/* cf4 */
define|#
directive|define
name|E5_USTORM_ETH_CONN_AG_CTX_TX_ARM_CF_SHIFT
value|2
define|#
directive|define
name|E5_USTORM_ETH_CONN_AG_CTX_RX_ARM_CF_MASK
value|0x3
comment|/* cf5 */
define|#
directive|define
name|E5_USTORM_ETH_CONN_AG_CTX_RX_ARM_CF_SHIFT
value|4
define|#
directive|define
name|E5_USTORM_ETH_CONN_AG_CTX_TX_BD_CONS_UPD_CF_MASK
value|0x3
comment|/* cf6 */
define|#
directive|define
name|E5_USTORM_ETH_CONN_AG_CTX_TX_BD_CONS_UPD_CF_SHIFT
value|6
name|u8
name|flags2
decl_stmt|;
define|#
directive|define
name|E5_USTORM_ETH_CONN_AG_CTX_TX_PMD_TERMINATE_CF_EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E5_USTORM_ETH_CONN_AG_CTX_TX_PMD_TERMINATE_CF_EN_SHIFT
value|0
define|#
directive|define
name|E5_USTORM_ETH_CONN_AG_CTX_RX_PMD_TERMINATE_CF_EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E5_USTORM_ETH_CONN_AG_CTX_RX_PMD_TERMINATE_CF_EN_SHIFT
value|1
define|#
directive|define
name|E5_USTORM_ETH_CONN_AG_CTX_CF2EN_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E5_USTORM_ETH_CONN_AG_CTX_CF2EN_SHIFT
value|2
define|#
directive|define
name|E5_USTORM_ETH_CONN_AG_CTX_CF3EN_MASK
value|0x1
comment|/* cf3en */
define|#
directive|define
name|E5_USTORM_ETH_CONN_AG_CTX_CF3EN_SHIFT
value|3
define|#
directive|define
name|E5_USTORM_ETH_CONN_AG_CTX_TX_ARM_CF_EN_MASK
value|0x1
comment|/* cf4en */
define|#
directive|define
name|E5_USTORM_ETH_CONN_AG_CTX_TX_ARM_CF_EN_SHIFT
value|4
define|#
directive|define
name|E5_USTORM_ETH_CONN_AG_CTX_RX_ARM_CF_EN_MASK
value|0x1
comment|/* cf5en */
define|#
directive|define
name|E5_USTORM_ETH_CONN_AG_CTX_RX_ARM_CF_EN_SHIFT
value|5
define|#
directive|define
name|E5_USTORM_ETH_CONN_AG_CTX_TX_BD_CONS_UPD_CF_EN_MASK
value|0x1
comment|/* cf6en */
define|#
directive|define
name|E5_USTORM_ETH_CONN_AG_CTX_TX_BD_CONS_UPD_CF_EN_SHIFT
value|6
define|#
directive|define
name|E5_USTORM_ETH_CONN_AG_CTX_RULE0EN_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E5_USTORM_ETH_CONN_AG_CTX_RULE0EN_SHIFT
value|7
name|u8
name|flags3
decl_stmt|;
define|#
directive|define
name|E5_USTORM_ETH_CONN_AG_CTX_RULE1EN_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E5_USTORM_ETH_CONN_AG_CTX_RULE1EN_SHIFT
value|0
define|#
directive|define
name|E5_USTORM_ETH_CONN_AG_CTX_RULE2EN_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E5_USTORM_ETH_CONN_AG_CTX_RULE2EN_SHIFT
value|1
define|#
directive|define
name|E5_USTORM_ETH_CONN_AG_CTX_RULE3EN_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E5_USTORM_ETH_CONN_AG_CTX_RULE3EN_SHIFT
value|2
define|#
directive|define
name|E5_USTORM_ETH_CONN_AG_CTX_RULE4EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E5_USTORM_ETH_CONN_AG_CTX_RULE4EN_SHIFT
value|3
define|#
directive|define
name|E5_USTORM_ETH_CONN_AG_CTX_RULE5EN_MASK
value|0x1
comment|/* rule5en */
define|#
directive|define
name|E5_USTORM_ETH_CONN_AG_CTX_RULE5EN_SHIFT
value|4
define|#
directive|define
name|E5_USTORM_ETH_CONN_AG_CTX_RULE6EN_MASK
value|0x1
comment|/* rule6en */
define|#
directive|define
name|E5_USTORM_ETH_CONN_AG_CTX_RULE6EN_SHIFT
value|5
define|#
directive|define
name|E5_USTORM_ETH_CONN_AG_CTX_RULE7EN_MASK
value|0x1
comment|/* rule7en */
define|#
directive|define
name|E5_USTORM_ETH_CONN_AG_CTX_RULE7EN_SHIFT
value|6
define|#
directive|define
name|E5_USTORM_ETH_CONN_AG_CTX_RULE8EN_MASK
value|0x1
comment|/* rule8en */
define|#
directive|define
name|E5_USTORM_ETH_CONN_AG_CTX_RULE8EN_SHIFT
value|7
name|u8
name|flags4
decl_stmt|;
define|#
directive|define
name|E5_USTORM_ETH_CONN_AG_CTX_E4_RESERVED1_MASK
value|0x1
comment|/* bit2 */
define|#
directive|define
name|E5_USTORM_ETH_CONN_AG_CTX_E4_RESERVED1_SHIFT
value|0
define|#
directive|define
name|E5_USTORM_ETH_CONN_AG_CTX_E4_RESERVED2_MASK
value|0x1
comment|/* bit3 */
define|#
directive|define
name|E5_USTORM_ETH_CONN_AG_CTX_E4_RESERVED2_SHIFT
value|1
define|#
directive|define
name|E5_USTORM_ETH_CONN_AG_CTX_E4_RESERVED3_MASK
value|0x3
comment|/* cf7 */
define|#
directive|define
name|E5_USTORM_ETH_CONN_AG_CTX_E4_RESERVED3_SHIFT
value|2
define|#
directive|define
name|E5_USTORM_ETH_CONN_AG_CTX_E4_RESERVED4_MASK
value|0x3
comment|/* cf8 */
define|#
directive|define
name|E5_USTORM_ETH_CONN_AG_CTX_E4_RESERVED4_SHIFT
value|4
define|#
directive|define
name|E5_USTORM_ETH_CONN_AG_CTX_E4_RESERVED5_MASK
value|0x1
comment|/* cf7en */
define|#
directive|define
name|E5_USTORM_ETH_CONN_AG_CTX_E4_RESERVED5_SHIFT
value|6
define|#
directive|define
name|E5_USTORM_ETH_CONN_AG_CTX_E4_RESERVED6_MASK
value|0x1
comment|/* cf8en */
define|#
directive|define
name|E5_USTORM_ETH_CONN_AG_CTX_E4_RESERVED6_SHIFT
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
name|tx_bd_cons
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
name|tx_int_coallecing_timeset
comment|/* reg3 */
decl_stmt|;
name|__le16
name|tx_drv_bd_cons
comment|/* word2 */
decl_stmt|;
name|__le16
name|rx_drv_cqe_cons
comment|/* word3 */
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|e5_xstorm_eth_conn_ag_ctx
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
name|E5_XSTORM_ETH_CONN_AG_CTX_EXIST_IN_QM0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_EXIST_IN_QM0_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_RESERVED1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_RESERVED1_SHIFT
value|1
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_RESERVED2_MASK
value|0x1
comment|/* exist_in_qm2 */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_RESERVED2_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_EXIST_IN_QM3_MASK
value|0x1
comment|/* exist_in_qm3 */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_EXIST_IN_QM3_SHIFT
value|3
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_RESERVED3_MASK
value|0x1
comment|/* bit4 */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_RESERVED3_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_RESERVED4_MASK
value|0x1
comment|/* cf_array_active */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_RESERVED4_SHIFT
value|5
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_RESERVED5_MASK
value|0x1
comment|/* bit6 */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_RESERVED5_SHIFT
value|6
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_RESERVED6_MASK
value|0x1
comment|/* bit7 */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_RESERVED6_SHIFT
value|7
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_RESERVED7_MASK
value|0x1
comment|/* bit8 */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_RESERVED7_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_RESERVED8_MASK
value|0x1
comment|/* bit9 */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_RESERVED8_SHIFT
value|1
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_RESERVED9_MASK
value|0x1
comment|/* bit10 */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_RESERVED9_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_BIT11_MASK
value|0x1
comment|/* bit11 */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_BIT11_SHIFT
value|3
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_BIT12_MASK
value|0x1
comment|/* bit12 */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_BIT12_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_BIT13_MASK
value|0x1
comment|/* bit13 */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_BIT13_SHIFT
value|5
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_TX_RULE_ACTIVE_MASK
value|0x1
comment|/* bit14 */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_TX_RULE_ACTIVE_SHIFT
value|6
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_DQ_CF_ACTIVE_MASK
value|0x1
comment|/* bit15 */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_DQ_CF_ACTIVE_SHIFT
value|7
name|u8
name|flags2
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_CF0_MASK
value|0x3
comment|/* timer0cf */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_CF0_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_CF1_MASK
value|0x3
comment|/* timer1cf */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_CF1_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_CF2_MASK
value|0x3
comment|/* timer2cf */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_CF2_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_CF3_MASK
value|0x3
comment|/* timer_stop_all */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_CF3_SHIFT
value|6
name|u8
name|flags3
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_CF4_MASK
value|0x3
comment|/* cf4 */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_CF4_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_CF5_MASK
value|0x3
comment|/* cf5 */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_CF5_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_CF6_MASK
value|0x3
comment|/* cf6 */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_CF6_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_CF7_MASK
value|0x3
comment|/* cf7 */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_CF7_SHIFT
value|6
name|u8
name|flags4
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_CF8_MASK
value|0x3
comment|/* cf8 */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_CF8_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_CF9_MASK
value|0x3
comment|/* cf9 */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_CF9_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_CF10_MASK
value|0x3
comment|/* cf10 */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_CF10_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_CF11_MASK
value|0x3
comment|/* cf11 */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_CF11_SHIFT
value|6
name|u8
name|flags5
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_CF12_MASK
value|0x3
comment|/* cf12 */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_CF12_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_CF13_MASK
value|0x3
comment|/* cf13 */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_CF13_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_CF14_MASK
value|0x3
comment|/* cf14 */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_CF14_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_CF15_MASK
value|0x3
comment|/* cf15 */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_CF15_SHIFT
value|6
name|u8
name|flags6
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_GO_TO_BD_CONS_CF_MASK
value|0x3
comment|/* cf16 */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_GO_TO_BD_CONS_CF_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_MULTI_UNICAST_CF_MASK
value|0x3
comment|/* cf_array_cf */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_MULTI_UNICAST_CF_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_DQ_CF_MASK
value|0x3
comment|/* cf18 */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_DQ_CF_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_TERMINATE_CF_MASK
value|0x3
comment|/* cf19 */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_TERMINATE_CF_SHIFT
value|6
name|u8
name|flags7
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_FLUSH_Q0_MASK
value|0x3
comment|/* cf20 */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_FLUSH_Q0_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_RESERVED10_MASK
value|0x3
comment|/* cf21 */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_RESERVED10_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_SLOW_PATH_MASK
value|0x3
comment|/* cf22 */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_SLOW_PATH_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_CF0EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_CF0EN_SHIFT
value|6
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_CF1EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_CF1EN_SHIFT
value|7
name|u8
name|flags8
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_CF2EN_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_CF2EN_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_CF3EN_MASK
value|0x1
comment|/* cf3en */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_CF3EN_SHIFT
value|1
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_CF4EN_MASK
value|0x1
comment|/* cf4en */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_CF4EN_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_CF5EN_MASK
value|0x1
comment|/* cf5en */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_CF5EN_SHIFT
value|3
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_CF6EN_MASK
value|0x1
comment|/* cf6en */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_CF6EN_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_CF7EN_MASK
value|0x1
comment|/* cf7en */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_CF7EN_SHIFT
value|5
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_CF8EN_MASK
value|0x1
comment|/* cf8en */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_CF8EN_SHIFT
value|6
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_CF9EN_MASK
value|0x1
comment|/* cf9en */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_CF9EN_SHIFT
value|7
name|u8
name|flags9
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_CF10EN_MASK
value|0x1
comment|/* cf10en */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_CF10EN_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_CF11EN_MASK
value|0x1
comment|/* cf11en */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_CF11EN_SHIFT
value|1
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_CF12EN_MASK
value|0x1
comment|/* cf12en */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_CF12EN_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_CF13EN_MASK
value|0x1
comment|/* cf13en */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_CF13EN_SHIFT
value|3
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_CF14EN_MASK
value|0x1
comment|/* cf14en */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_CF14EN_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_CF15EN_MASK
value|0x1
comment|/* cf15en */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_CF15EN_SHIFT
value|5
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_GO_TO_BD_CONS_CF_EN_MASK
value|0x1
comment|/* cf16en */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_GO_TO_BD_CONS_CF_EN_SHIFT
value|6
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_MULTI_UNICAST_CF_EN_MASK
value|0x1
comment|/* cf_array_cf_en */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_MULTI_UNICAST_CF_EN_SHIFT
value|7
name|u8
name|flags10
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_DQ_CF_EN_MASK
value|0x1
comment|/* cf18en */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_DQ_CF_EN_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_TERMINATE_CF_EN_MASK
value|0x1
comment|/* cf19en */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_TERMINATE_CF_EN_SHIFT
value|1
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_FLUSH_Q0_EN_MASK
value|0x1
comment|/* cf20en */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_FLUSH_Q0_EN_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_RESERVED11_MASK
value|0x1
comment|/* cf21en */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_RESERVED11_SHIFT
value|3
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_SLOW_PATH_EN_MASK
value|0x1
comment|/* cf22en */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_SLOW_PATH_EN_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_TPH_ENABLE_EN_RESERVED_MASK
value|0x1
comment|/* cf23en */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_TPH_ENABLE_EN_RESERVED_SHIFT
value|5
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_RESERVED12_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_RESERVED12_SHIFT
value|6
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_RESERVED13_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_RESERVED13_SHIFT
value|7
name|u8
name|flags11
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_RESERVED14_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_RESERVED14_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_RESERVED15_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_RESERVED15_SHIFT
value|1
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_TX_DEC_RULE_EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_TX_DEC_RULE_EN_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_RULE5EN_MASK
value|0x1
comment|/* rule5en */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_RULE5EN_SHIFT
value|3
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_RULE6EN_MASK
value|0x1
comment|/* rule6en */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_RULE6EN_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_RULE7EN_MASK
value|0x1
comment|/* rule7en */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_RULE7EN_SHIFT
value|5
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_A0_RESERVED1_MASK
value|0x1
comment|/* rule8en */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_A0_RESERVED1_SHIFT
value|6
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_RULE9EN_MASK
value|0x1
comment|/* rule9en */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_RULE9EN_SHIFT
value|7
name|u8
name|flags12
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_RULE10EN_MASK
value|0x1
comment|/* rule10en */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_RULE10EN_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_RULE11EN_MASK
value|0x1
comment|/* rule11en */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_RULE11EN_SHIFT
value|1
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_A0_RESERVED2_MASK
value|0x1
comment|/* rule12en */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_A0_RESERVED2_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_A0_RESERVED3_MASK
value|0x1
comment|/* rule13en */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_A0_RESERVED3_SHIFT
value|3
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_RULE14EN_MASK
value|0x1
comment|/* rule14en */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_RULE14EN_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_RULE15EN_MASK
value|0x1
comment|/* rule15en */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_RULE15EN_SHIFT
value|5
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_RULE16EN_MASK
value|0x1
comment|/* rule16en */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_RULE16EN_SHIFT
value|6
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_RULE17EN_MASK
value|0x1
comment|/* rule17en */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_RULE17EN_SHIFT
value|7
name|u8
name|flags13
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_RULE18EN_MASK
value|0x1
comment|/* rule18en */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_RULE18EN_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_RULE19EN_MASK
value|0x1
comment|/* rule19en */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_RULE19EN_SHIFT
value|1
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_A0_RESERVED4_MASK
value|0x1
comment|/* rule20en */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_A0_RESERVED4_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_A0_RESERVED5_MASK
value|0x1
comment|/* rule21en */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_A0_RESERVED5_SHIFT
value|3
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_A0_RESERVED6_MASK
value|0x1
comment|/* rule22en */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_A0_RESERVED6_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_A0_RESERVED7_MASK
value|0x1
comment|/* rule23en */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_A0_RESERVED7_SHIFT
value|5
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_A0_RESERVED8_MASK
value|0x1
comment|/* rule24en */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_A0_RESERVED8_SHIFT
value|6
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_A0_RESERVED9_MASK
value|0x1
comment|/* rule25en */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_A0_RESERVED9_SHIFT
value|7
name|u8
name|flags14
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_EDPM_USE_EXT_HDR_MASK
value|0x1
comment|/* bit16 */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_EDPM_USE_EXT_HDR_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_EDPM_SEND_RAW_L3L4_MASK
value|0x1
comment|/* bit17 */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_EDPM_SEND_RAW_L3L4_SHIFT
value|1
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_EDPM_INBAND_PROP_HDR_MASK
value|0x1
comment|/* bit18 */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_EDPM_INBAND_PROP_HDR_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_EDPM_SEND_EXT_TUNNEL_MASK
value|0x1
comment|/* bit19 */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_EDPM_SEND_EXT_TUNNEL_SHIFT
value|3
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_L2_EDPM_ENABLE_MASK
value|0x1
comment|/* bit20 */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_L2_EDPM_ENABLE_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_ROCE_EDPM_ENABLE_MASK
value|0x1
comment|/* bit21 */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_ROCE_EDPM_ENABLE_SHIFT
value|5
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_TPH_ENABLE_MASK
value|0x3
comment|/* cf23 */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_TPH_ENABLE_SHIFT
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
name|tx_l2_edpm_usg_cnt
comment|/* physical_q1 */
decl_stmt|;
name|__le16
name|edpm_num_bds
comment|/* physical_q2 */
decl_stmt|;
name|__le16
name|tx_bd_cons
comment|/* word3 */
decl_stmt|;
name|__le16
name|tx_bd_prod
comment|/* word4 */
decl_stmt|;
name|__le16
name|tx_class
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
name|E5_XSTORM_ETH_CONN_AG_CTX_E4_RESERVED1_MASK
value|0x1
comment|/* bit22 */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_E4_RESERVED1_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_E4_RESERVED2_MASK
value|0x1
comment|/* bit23 */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_E4_RESERVED2_SHIFT
value|1
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_E4_RESERVED3_MASK
value|0x1
comment|/* bit24 */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_E4_RESERVED3_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_E4_RESERVED4_MASK
value|0x3
comment|/* cf24 */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_E4_RESERVED4_SHIFT
value|3
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_E4_RESERVED5_MASK
value|0x1
comment|/* cf24en */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_E4_RESERVED5_SHIFT
value|5
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_E4_RESERVED6_MASK
value|0x1
comment|/* rule26en */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_E4_RESERVED6_SHIFT
value|6
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_E4_RESERVED7_MASK
value|0x1
comment|/* rule27en */
define|#
directive|define
name|E5_XSTORM_ETH_CONN_AG_CTX_E4_RESERVED7_SHIFT
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
name|e5_xstorm_eth_hw_conn_ag_ctx
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
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_EXIST_IN_QM0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_EXIST_IN_QM0_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_RESERVED1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_RESERVED1_SHIFT
value|1
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_RESERVED2_MASK
value|0x1
comment|/* exist_in_qm2 */
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_RESERVED2_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_EXIST_IN_QM3_MASK
value|0x1
comment|/* exist_in_qm3 */
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_EXIST_IN_QM3_SHIFT
value|3
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_RESERVED3_MASK
value|0x1
comment|/* bit4 */
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_RESERVED3_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_RESERVED4_MASK
value|0x1
comment|/* cf_array_active */
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_RESERVED4_SHIFT
value|5
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_RESERVED5_MASK
value|0x1
comment|/* bit6 */
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_RESERVED5_SHIFT
value|6
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_RESERVED6_MASK
value|0x1
comment|/* bit7 */
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_RESERVED6_SHIFT
value|7
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_RESERVED7_MASK
value|0x1
comment|/* bit8 */
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_RESERVED7_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_RESERVED8_MASK
value|0x1
comment|/* bit9 */
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_RESERVED8_SHIFT
value|1
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_RESERVED9_MASK
value|0x1
comment|/* bit10 */
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_RESERVED9_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_BIT11_MASK
value|0x1
comment|/* bit11 */
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_BIT11_SHIFT
value|3
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_BIT12_MASK
value|0x1
comment|/* bit12 */
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_BIT12_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_BIT13_MASK
value|0x1
comment|/* bit13 */
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_BIT13_SHIFT
value|5
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_TX_RULE_ACTIVE_MASK
value|0x1
comment|/* bit14 */
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_TX_RULE_ACTIVE_SHIFT
value|6
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_DQ_CF_ACTIVE_MASK
value|0x1
comment|/* bit15 */
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_DQ_CF_ACTIVE_SHIFT
value|7
name|u8
name|flags2
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_CF0_MASK
value|0x3
comment|/* timer0cf */
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_CF0_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_CF1_MASK
value|0x3
comment|/* timer1cf */
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_CF1_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_CF2_MASK
value|0x3
comment|/* timer2cf */
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_CF2_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_CF3_MASK
value|0x3
comment|/* timer_stop_all */
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_CF3_SHIFT
value|6
name|u8
name|flags3
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_CF4_MASK
value|0x3
comment|/* cf4 */
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_CF4_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_CF5_MASK
value|0x3
comment|/* cf5 */
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_CF5_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_CF6_MASK
value|0x3
comment|/* cf6 */
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_CF6_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_CF7_MASK
value|0x3
comment|/* cf7 */
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_CF7_SHIFT
value|6
name|u8
name|flags4
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_CF8_MASK
value|0x3
comment|/* cf8 */
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_CF8_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_CF9_MASK
value|0x3
comment|/* cf9 */
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_CF9_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_CF10_MASK
value|0x3
comment|/* cf10 */
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_CF10_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_CF11_MASK
value|0x3
comment|/* cf11 */
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_CF11_SHIFT
value|6
name|u8
name|flags5
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_CF12_MASK
value|0x3
comment|/* cf12 */
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_CF12_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_CF13_MASK
value|0x3
comment|/* cf13 */
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_CF13_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_CF14_MASK
value|0x3
comment|/* cf14 */
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_CF14_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_CF15_MASK
value|0x3
comment|/* cf15 */
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_CF15_SHIFT
value|6
name|u8
name|flags6
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_GO_TO_BD_CONS_CF_MASK
value|0x3
comment|/* cf16 */
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_GO_TO_BD_CONS_CF_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_MULTI_UNICAST_CF_MASK
value|0x3
comment|/* cf_array_cf */
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_MULTI_UNICAST_CF_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_DQ_CF_MASK
value|0x3
comment|/* cf18 */
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_DQ_CF_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_TERMINATE_CF_MASK
value|0x3
comment|/* cf19 */
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_TERMINATE_CF_SHIFT
value|6
name|u8
name|flags7
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_FLUSH_Q0_MASK
value|0x3
comment|/* cf20 */
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_FLUSH_Q0_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_RESERVED10_MASK
value|0x3
comment|/* cf21 */
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_RESERVED10_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_SLOW_PATH_MASK
value|0x3
comment|/* cf22 */
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_SLOW_PATH_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_CF0EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_CF0EN_SHIFT
value|6
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_CF1EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_CF1EN_SHIFT
value|7
name|u8
name|flags8
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_CF2EN_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_CF2EN_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_CF3EN_MASK
value|0x1
comment|/* cf3en */
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_CF3EN_SHIFT
value|1
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_CF4EN_MASK
value|0x1
comment|/* cf4en */
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_CF4EN_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_CF5EN_MASK
value|0x1
comment|/* cf5en */
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_CF5EN_SHIFT
value|3
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_CF6EN_MASK
value|0x1
comment|/* cf6en */
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_CF6EN_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_CF7EN_MASK
value|0x1
comment|/* cf7en */
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_CF7EN_SHIFT
value|5
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_CF8EN_MASK
value|0x1
comment|/* cf8en */
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_CF8EN_SHIFT
value|6
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_CF9EN_MASK
value|0x1
comment|/* cf9en */
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_CF9EN_SHIFT
value|7
name|u8
name|flags9
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_CF10EN_MASK
value|0x1
comment|/* cf10en */
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_CF10EN_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_CF11EN_MASK
value|0x1
comment|/* cf11en */
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_CF11EN_SHIFT
value|1
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_CF12EN_MASK
value|0x1
comment|/* cf12en */
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_CF12EN_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_CF13EN_MASK
value|0x1
comment|/* cf13en */
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_CF13EN_SHIFT
value|3
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_CF14EN_MASK
value|0x1
comment|/* cf14en */
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_CF14EN_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_CF15EN_MASK
value|0x1
comment|/* cf15en */
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_CF15EN_SHIFT
value|5
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_GO_TO_BD_CONS_CF_EN_MASK
value|0x1
comment|/* cf16en */
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_GO_TO_BD_CONS_CF_EN_SHIFT
value|6
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_MULTI_UNICAST_CF_EN_MASK
value|0x1
comment|/* cf_array_cf_en */
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_MULTI_UNICAST_CF_EN_SHIFT
value|7
name|u8
name|flags10
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_DQ_CF_EN_MASK
value|0x1
comment|/* cf18en */
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_DQ_CF_EN_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_TERMINATE_CF_EN_MASK
value|0x1
comment|/* cf19en */
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_TERMINATE_CF_EN_SHIFT
value|1
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_FLUSH_Q0_EN_MASK
value|0x1
comment|/* cf20en */
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_FLUSH_Q0_EN_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_RESERVED11_MASK
value|0x1
comment|/* cf21en */
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_RESERVED11_SHIFT
value|3
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_SLOW_PATH_EN_MASK
value|0x1
comment|/* cf22en */
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_SLOW_PATH_EN_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_TPH_ENABLE_EN_RESERVED_MASK
value|0x1
comment|/* cf23en */
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_TPH_ENABLE_EN_RESERVED_SHIFT
value|5
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_RESERVED12_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_RESERVED12_SHIFT
value|6
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_RESERVED13_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_RESERVED13_SHIFT
value|7
name|u8
name|flags11
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_RESERVED14_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_RESERVED14_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_RESERVED15_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_RESERVED15_SHIFT
value|1
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_TX_DEC_RULE_EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_TX_DEC_RULE_EN_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_RULE5EN_MASK
value|0x1
comment|/* rule5en */
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_RULE5EN_SHIFT
value|3
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_RULE6EN_MASK
value|0x1
comment|/* rule6en */
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_RULE6EN_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_RULE7EN_MASK
value|0x1
comment|/* rule7en */
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_RULE7EN_SHIFT
value|5
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_A0_RESERVED1_MASK
value|0x1
comment|/* rule8en */
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_A0_RESERVED1_SHIFT
value|6
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_RULE9EN_MASK
value|0x1
comment|/* rule9en */
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_RULE9EN_SHIFT
value|7
name|u8
name|flags12
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_RULE10EN_MASK
value|0x1
comment|/* rule10en */
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_RULE10EN_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_RULE11EN_MASK
value|0x1
comment|/* rule11en */
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_RULE11EN_SHIFT
value|1
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_A0_RESERVED2_MASK
value|0x1
comment|/* rule12en */
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_A0_RESERVED2_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_A0_RESERVED3_MASK
value|0x1
comment|/* rule13en */
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_A0_RESERVED3_SHIFT
value|3
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_RULE14EN_MASK
value|0x1
comment|/* rule14en */
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_RULE14EN_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_RULE15EN_MASK
value|0x1
comment|/* rule15en */
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_RULE15EN_SHIFT
value|5
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_RULE16EN_MASK
value|0x1
comment|/* rule16en */
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_RULE16EN_SHIFT
value|6
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_RULE17EN_MASK
value|0x1
comment|/* rule17en */
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_RULE17EN_SHIFT
value|7
name|u8
name|flags13
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_RULE18EN_MASK
value|0x1
comment|/* rule18en */
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_RULE18EN_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_RULE19EN_MASK
value|0x1
comment|/* rule19en */
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_RULE19EN_SHIFT
value|1
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_A0_RESERVED4_MASK
value|0x1
comment|/* rule20en */
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_A0_RESERVED4_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_A0_RESERVED5_MASK
value|0x1
comment|/* rule21en */
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_A0_RESERVED5_SHIFT
value|3
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_A0_RESERVED6_MASK
value|0x1
comment|/* rule22en */
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_A0_RESERVED6_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_A0_RESERVED7_MASK
value|0x1
comment|/* rule23en */
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_A0_RESERVED7_SHIFT
value|5
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_A0_RESERVED8_MASK
value|0x1
comment|/* rule24en */
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_A0_RESERVED8_SHIFT
value|6
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_A0_RESERVED9_MASK
value|0x1
comment|/* rule25en */
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_A0_RESERVED9_SHIFT
value|7
name|u8
name|flags14
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_EDPM_USE_EXT_HDR_MASK
value|0x1
comment|/* bit16 */
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_EDPM_USE_EXT_HDR_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_EDPM_SEND_RAW_L3L4_MASK
value|0x1
comment|/* bit17 */
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_EDPM_SEND_RAW_L3L4_SHIFT
value|1
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_EDPM_INBAND_PROP_HDR_MASK
value|0x1
comment|/* bit18 */
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_EDPM_INBAND_PROP_HDR_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_EDPM_SEND_EXT_TUNNEL_MASK
value|0x1
comment|/* bit19 */
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_EDPM_SEND_EXT_TUNNEL_SHIFT
value|3
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_L2_EDPM_ENABLE_MASK
value|0x1
comment|/* bit20 */
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_L2_EDPM_ENABLE_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_ROCE_EDPM_ENABLE_MASK
value|0x1
comment|/* bit21 */
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_ROCE_EDPM_ENABLE_SHIFT
value|5
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_TPH_ENABLE_MASK
value|0x3
comment|/* cf23 */
define|#
directive|define
name|E5_XSTORM_ETH_HW_CONN_AG_CTX_TPH_ENABLE_SHIFT
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
name|tx_l2_edpm_usg_cnt
comment|/* physical_q1 */
decl_stmt|;
name|__le16
name|edpm_num_bds
comment|/* physical_q2 */
decl_stmt|;
name|__le16
name|tx_bd_cons
comment|/* word3 */
decl_stmt|;
name|__le16
name|tx_bd_prod
comment|/* word4 */
decl_stmt|;
name|__le16
name|tx_class
comment|/* word5 */
decl_stmt|;
name|__le16
name|conn_dpi
comment|/* conn_dpi */
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|e5_ystorm_eth_conn_ag_ctx
block|{
name|u8
name|byte0
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
name|E5_YSTORM_ETH_CONN_AG_CTX_BIT0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E5_YSTORM_ETH_CONN_AG_CTX_BIT0_SHIFT
value|0
define|#
directive|define
name|E5_YSTORM_ETH_CONN_AG_CTX_BIT1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E5_YSTORM_ETH_CONN_AG_CTX_BIT1_SHIFT
value|1
define|#
directive|define
name|E5_YSTORM_ETH_CONN_AG_CTX_TX_BD_CONS_UPD_CF_MASK
value|0x3
comment|/* cf0 */
define|#
directive|define
name|E5_YSTORM_ETH_CONN_AG_CTX_TX_BD_CONS_UPD_CF_SHIFT
value|2
define|#
directive|define
name|E5_YSTORM_ETH_CONN_AG_CTX_PMD_TERMINATE_CF_MASK
value|0x3
comment|/* cf1 */
define|#
directive|define
name|E5_YSTORM_ETH_CONN_AG_CTX_PMD_TERMINATE_CF_SHIFT
value|4
define|#
directive|define
name|E5_YSTORM_ETH_CONN_AG_CTX_CF2_MASK
value|0x3
comment|/* cf2 */
define|#
directive|define
name|E5_YSTORM_ETH_CONN_AG_CTX_CF2_SHIFT
value|6
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E5_YSTORM_ETH_CONN_AG_CTX_TX_BD_CONS_UPD_CF_EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E5_YSTORM_ETH_CONN_AG_CTX_TX_BD_CONS_UPD_CF_EN_SHIFT
value|0
define|#
directive|define
name|E5_YSTORM_ETH_CONN_AG_CTX_PMD_TERMINATE_CF_EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E5_YSTORM_ETH_CONN_AG_CTX_PMD_TERMINATE_CF_EN_SHIFT
value|1
define|#
directive|define
name|E5_YSTORM_ETH_CONN_AG_CTX_CF2EN_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E5_YSTORM_ETH_CONN_AG_CTX_CF2EN_SHIFT
value|2
define|#
directive|define
name|E5_YSTORM_ETH_CONN_AG_CTX_RULE0EN_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E5_YSTORM_ETH_CONN_AG_CTX_RULE0EN_SHIFT
value|3
define|#
directive|define
name|E5_YSTORM_ETH_CONN_AG_CTX_RULE1EN_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E5_YSTORM_ETH_CONN_AG_CTX_RULE1EN_SHIFT
value|4
define|#
directive|define
name|E5_YSTORM_ETH_CONN_AG_CTX_RULE2EN_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E5_YSTORM_ETH_CONN_AG_CTX_RULE2EN_SHIFT
value|5
define|#
directive|define
name|E5_YSTORM_ETH_CONN_AG_CTX_RULE3EN_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E5_YSTORM_ETH_CONN_AG_CTX_RULE3EN_SHIFT
value|6
define|#
directive|define
name|E5_YSTORM_ETH_CONN_AG_CTX_RULE4EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E5_YSTORM_ETH_CONN_AG_CTX_RULE4EN_SHIFT
value|7
name|u8
name|tx_q0_int_coallecing_timeset
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
name|terminate_spqe
comment|/* reg0 */
decl_stmt|;
name|__le32
name|reg1
comment|/* reg1 */
decl_stmt|;
name|__le16
name|tx_bd_cons_upd
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
comment|/*  * GFT CAM line struct  */
end_comment

begin_struct
struct|struct
name|gft_cam_line
block|{
name|__le32
name|camline
decl_stmt|;
define|#
directive|define
name|GFT_CAM_LINE_VALID_MASK
value|0x1
comment|/* Indication if the line is valid. */
define|#
directive|define
name|GFT_CAM_LINE_VALID_SHIFT
value|0
define|#
directive|define
name|GFT_CAM_LINE_DATA_MASK
value|0x3FFF
comment|/* Data bits, the word that compared with the profile key */
define|#
directive|define
name|GFT_CAM_LINE_DATA_SHIFT
value|1
define|#
directive|define
name|GFT_CAM_LINE_MASK_BITS_MASK
value|0x3FFF
comment|/* Mask bits, indicate the bits in the data that are Dont-Care */
define|#
directive|define
name|GFT_CAM_LINE_MASK_BITS_SHIFT
value|15
define|#
directive|define
name|GFT_CAM_LINE_RESERVED1_MASK
value|0x7
define|#
directive|define
name|GFT_CAM_LINE_RESERVED1_SHIFT
value|29
block|}
struct|;
end_struct

begin_comment
comment|/*  * GFT CAM line struct (for driversim use)  */
end_comment

begin_struct
struct|struct
name|gft_cam_line_mapped
block|{
name|__le32
name|camline
decl_stmt|;
define|#
directive|define
name|GFT_CAM_LINE_MAPPED_VALID_MASK
value|0x1
comment|/* Indication if the line is valid. */
define|#
directive|define
name|GFT_CAM_LINE_MAPPED_VALID_SHIFT
value|0
define|#
directive|define
name|GFT_CAM_LINE_MAPPED_IP_VERSION_MASK
value|0x1
comment|/* use enum gft_profile_ip_version (use enum gft_profile_ip_version) */
define|#
directive|define
name|GFT_CAM_LINE_MAPPED_IP_VERSION_SHIFT
value|1
define|#
directive|define
name|GFT_CAM_LINE_MAPPED_TUNNEL_IP_VERSION_MASK
value|0x1
comment|/* use enum gft_profile_ip_version (use enum gft_profile_ip_version) */
define|#
directive|define
name|GFT_CAM_LINE_MAPPED_TUNNEL_IP_VERSION_SHIFT
value|2
define|#
directive|define
name|GFT_CAM_LINE_MAPPED_UPPER_PROTOCOL_TYPE_MASK
value|0xF
comment|/* use enum gft_profile_upper_protocol_type (use enum gft_profile_upper_protocol_type) */
define|#
directive|define
name|GFT_CAM_LINE_MAPPED_UPPER_PROTOCOL_TYPE_SHIFT
value|3
define|#
directive|define
name|GFT_CAM_LINE_MAPPED_TUNNEL_TYPE_MASK
value|0xF
comment|/* use enum gft_profile_tunnel_type (use enum gft_profile_tunnel_type) */
define|#
directive|define
name|GFT_CAM_LINE_MAPPED_TUNNEL_TYPE_SHIFT
value|7
define|#
directive|define
name|GFT_CAM_LINE_MAPPED_PF_ID_MASK
value|0xF
define|#
directive|define
name|GFT_CAM_LINE_MAPPED_PF_ID_SHIFT
value|11
define|#
directive|define
name|GFT_CAM_LINE_MAPPED_IP_VERSION_MASK_MASK
value|0x1
comment|/* use enum gft_profile_ip_version (use enum gft_profile_ip_version) */
define|#
directive|define
name|GFT_CAM_LINE_MAPPED_IP_VERSION_MASK_SHIFT
value|15
define|#
directive|define
name|GFT_CAM_LINE_MAPPED_TUNNEL_IP_VERSION_MASK_MASK
value|0x1
comment|/* use enum gft_profile_ip_version (use enum gft_profile_ip_version) */
define|#
directive|define
name|GFT_CAM_LINE_MAPPED_TUNNEL_IP_VERSION_MASK_SHIFT
value|16
define|#
directive|define
name|GFT_CAM_LINE_MAPPED_UPPER_PROTOCOL_TYPE_MASK_MASK
value|0xF
comment|/* use enum gft_profile_upper_protocol_type (use enum gft_profile_upper_protocol_type) */
define|#
directive|define
name|GFT_CAM_LINE_MAPPED_UPPER_PROTOCOL_TYPE_MASK_SHIFT
value|17
define|#
directive|define
name|GFT_CAM_LINE_MAPPED_TUNNEL_TYPE_MASK_MASK
value|0xF
comment|/* use enum gft_profile_tunnel_type (use enum gft_profile_tunnel_type) */
define|#
directive|define
name|GFT_CAM_LINE_MAPPED_TUNNEL_TYPE_MASK_SHIFT
value|21
define|#
directive|define
name|GFT_CAM_LINE_MAPPED_PF_ID_MASK_MASK
value|0xF
define|#
directive|define
name|GFT_CAM_LINE_MAPPED_PF_ID_MASK_SHIFT
value|25
define|#
directive|define
name|GFT_CAM_LINE_MAPPED_RESERVED1_MASK
value|0x7
define|#
directive|define
name|GFT_CAM_LINE_MAPPED_RESERVED1_SHIFT
value|29
block|}
struct|;
end_struct

begin_union
union|union
name|gft_cam_line_union
block|{
name|struct
name|gft_cam_line
name|cam_line
decl_stmt|;
name|struct
name|gft_cam_line_mapped
name|cam_line_mapped
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/*  * Used in gft_profile_key: Indication for ip version  */
end_comment

begin_enum
enum|enum
name|gft_profile_ip_version
block|{
name|GFT_PROFILE_IPV4
init|=
literal|0
block|,
name|GFT_PROFILE_IPV6
init|=
literal|1
block|,
name|MAX_GFT_PROFILE_IP_VERSION
block|}
enum|;
end_enum

begin_comment
comment|/*  * Profile key stucr fot GFT logic in Prs  */
end_comment

begin_struct
struct|struct
name|gft_profile_key
block|{
name|__le16
name|profile_key
decl_stmt|;
define|#
directive|define
name|GFT_PROFILE_KEY_IP_VERSION_MASK
value|0x1
comment|/* use enum gft_profile_ip_version (use enum gft_profile_ip_version) */
define|#
directive|define
name|GFT_PROFILE_KEY_IP_VERSION_SHIFT
value|0
define|#
directive|define
name|GFT_PROFILE_KEY_TUNNEL_IP_VERSION_MASK
value|0x1
comment|/* use enum gft_profile_ip_version (use enum gft_profile_ip_version) */
define|#
directive|define
name|GFT_PROFILE_KEY_TUNNEL_IP_VERSION_SHIFT
value|1
define|#
directive|define
name|GFT_PROFILE_KEY_UPPER_PROTOCOL_TYPE_MASK
value|0xF
comment|/* use enum gft_profile_upper_protocol_type (use enum gft_profile_upper_protocol_type) */
define|#
directive|define
name|GFT_PROFILE_KEY_UPPER_PROTOCOL_TYPE_SHIFT
value|2
define|#
directive|define
name|GFT_PROFILE_KEY_TUNNEL_TYPE_MASK
value|0xF
comment|/* use enum gft_profile_tunnel_type (use enum gft_profile_tunnel_type) */
define|#
directive|define
name|GFT_PROFILE_KEY_TUNNEL_TYPE_SHIFT
value|6
define|#
directive|define
name|GFT_PROFILE_KEY_PF_ID_MASK
value|0xF
define|#
directive|define
name|GFT_PROFILE_KEY_PF_ID_SHIFT
value|10
define|#
directive|define
name|GFT_PROFILE_KEY_RESERVED0_MASK
value|0x3
define|#
directive|define
name|GFT_PROFILE_KEY_RESERVED0_SHIFT
value|14
block|}
struct|;
end_struct

begin_comment
comment|/*  * Used in gft_profile_key: Indication for tunnel type  */
end_comment

begin_enum
enum|enum
name|gft_profile_tunnel_type
block|{
name|GFT_PROFILE_NO_TUNNEL
init|=
literal|0
block|,
name|GFT_PROFILE_VXLAN_TUNNEL
init|=
literal|1
block|,
name|GFT_PROFILE_GRE_MAC_OR_NVGRE_TUNNEL
init|=
literal|2
block|,
name|GFT_PROFILE_GRE_IP_TUNNEL
init|=
literal|3
block|,
name|GFT_PROFILE_GENEVE_MAC_TUNNEL
init|=
literal|4
block|,
name|GFT_PROFILE_GENEVE_IP_TUNNEL
init|=
literal|5
block|,
name|MAX_GFT_PROFILE_TUNNEL_TYPE
block|}
enum|;
end_enum

begin_comment
comment|/*  * Used in gft_profile_key: Indication for protocol type  */
end_comment

begin_enum
enum|enum
name|gft_profile_upper_protocol_type
block|{
name|GFT_PROFILE_ROCE_PROTOCOL
init|=
literal|0
block|,
name|GFT_PROFILE_RROCE_PROTOCOL
init|=
literal|1
block|,
name|GFT_PROFILE_FCOE_PROTOCOL
init|=
literal|2
block|,
name|GFT_PROFILE_ICMP_PROTOCOL
init|=
literal|3
block|,
name|GFT_PROFILE_ARP_PROTOCOL
init|=
literal|4
block|,
name|GFT_PROFILE_USER_TCP_SRC_PORT_1_INNER
init|=
literal|5
block|,
name|GFT_PROFILE_USER_TCP_DST_PORT_1_INNER
init|=
literal|6
block|,
name|GFT_PROFILE_TCP_PROTOCOL
init|=
literal|7
block|,
name|GFT_PROFILE_USER_UDP_DST_PORT_1_INNER
init|=
literal|8
block|,
name|GFT_PROFILE_USER_UDP_DST_PORT_2_OUTER
init|=
literal|9
block|,
name|GFT_PROFILE_UDP_PROTOCOL
init|=
literal|10
block|,
name|GFT_PROFILE_USER_IP_1_INNER
init|=
literal|11
block|,
name|GFT_PROFILE_USER_IP_2_OUTER
init|=
literal|12
block|,
name|GFT_PROFILE_USER_ETH_1_INNER
init|=
literal|13
block|,
name|GFT_PROFILE_USER_ETH_2_OUTER
init|=
literal|14
block|,
name|GFT_PROFILE_RAW
init|=
literal|15
block|,
name|MAX_GFT_PROFILE_UPPER_PROTOCOL_TYPE
block|}
enum|;
end_enum

begin_comment
comment|/*  * GFT RAM line struct  */
end_comment

begin_struct
struct|struct
name|gft_ram_line
block|{
name|__le32
name|lo
decl_stmt|;
define|#
directive|define
name|GFT_RAM_LINE_VLAN_SELECT_MASK
value|0x3
comment|/*  (use enum gft_vlan_select) */
define|#
directive|define
name|GFT_RAM_LINE_VLAN_SELECT_SHIFT
value|0
define|#
directive|define
name|GFT_RAM_LINE_TUNNEL_ENTROPHY_MASK
value|0x1
define|#
directive|define
name|GFT_RAM_LINE_TUNNEL_ENTROPHY_SHIFT
value|2
define|#
directive|define
name|GFT_RAM_LINE_TUNNEL_TTL_EQUAL_ONE_MASK
value|0x1
define|#
directive|define
name|GFT_RAM_LINE_TUNNEL_TTL_EQUAL_ONE_SHIFT
value|3
define|#
directive|define
name|GFT_RAM_LINE_TUNNEL_TTL_MASK
value|0x1
define|#
directive|define
name|GFT_RAM_LINE_TUNNEL_TTL_SHIFT
value|4
define|#
directive|define
name|GFT_RAM_LINE_TUNNEL_ETHERTYPE_MASK
value|0x1
define|#
directive|define
name|GFT_RAM_LINE_TUNNEL_ETHERTYPE_SHIFT
value|5
define|#
directive|define
name|GFT_RAM_LINE_TUNNEL_DST_PORT_MASK
value|0x1
define|#
directive|define
name|GFT_RAM_LINE_TUNNEL_DST_PORT_SHIFT
value|6
define|#
directive|define
name|GFT_RAM_LINE_TUNNEL_SRC_PORT_MASK
value|0x1
define|#
directive|define
name|GFT_RAM_LINE_TUNNEL_SRC_PORT_SHIFT
value|7
define|#
directive|define
name|GFT_RAM_LINE_TUNNEL_DSCP_MASK
value|0x1
define|#
directive|define
name|GFT_RAM_LINE_TUNNEL_DSCP_SHIFT
value|8
define|#
directive|define
name|GFT_RAM_LINE_TUNNEL_OVER_IP_PROTOCOL_MASK
value|0x1
define|#
directive|define
name|GFT_RAM_LINE_TUNNEL_OVER_IP_PROTOCOL_SHIFT
value|9
define|#
directive|define
name|GFT_RAM_LINE_TUNNEL_DST_IP_MASK
value|0x1
define|#
directive|define
name|GFT_RAM_LINE_TUNNEL_DST_IP_SHIFT
value|10
define|#
directive|define
name|GFT_RAM_LINE_TUNNEL_SRC_IP_MASK
value|0x1
define|#
directive|define
name|GFT_RAM_LINE_TUNNEL_SRC_IP_SHIFT
value|11
define|#
directive|define
name|GFT_RAM_LINE_TUNNEL_PRIORITY_MASK
value|0x1
define|#
directive|define
name|GFT_RAM_LINE_TUNNEL_PRIORITY_SHIFT
value|12
define|#
directive|define
name|GFT_RAM_LINE_TUNNEL_PROVIDER_VLAN_MASK
value|0x1
define|#
directive|define
name|GFT_RAM_LINE_TUNNEL_PROVIDER_VLAN_SHIFT
value|13
define|#
directive|define
name|GFT_RAM_LINE_TUNNEL_VLAN_MASK
value|0x1
define|#
directive|define
name|GFT_RAM_LINE_TUNNEL_VLAN_SHIFT
value|14
define|#
directive|define
name|GFT_RAM_LINE_TUNNEL_DST_MAC_MASK
value|0x1
define|#
directive|define
name|GFT_RAM_LINE_TUNNEL_DST_MAC_SHIFT
value|15
define|#
directive|define
name|GFT_RAM_LINE_TUNNEL_SRC_MAC_MASK
value|0x1
define|#
directive|define
name|GFT_RAM_LINE_TUNNEL_SRC_MAC_SHIFT
value|16
define|#
directive|define
name|GFT_RAM_LINE_TTL_EQUAL_ONE_MASK
value|0x1
define|#
directive|define
name|GFT_RAM_LINE_TTL_EQUAL_ONE_SHIFT
value|17
define|#
directive|define
name|GFT_RAM_LINE_TTL_MASK
value|0x1
define|#
directive|define
name|GFT_RAM_LINE_TTL_SHIFT
value|18
define|#
directive|define
name|GFT_RAM_LINE_ETHERTYPE_MASK
value|0x1
define|#
directive|define
name|GFT_RAM_LINE_ETHERTYPE_SHIFT
value|19
define|#
directive|define
name|GFT_RAM_LINE_RESERVED0_MASK
value|0x1
define|#
directive|define
name|GFT_RAM_LINE_RESERVED0_SHIFT
value|20
define|#
directive|define
name|GFT_RAM_LINE_TCP_FLAG_FIN_MASK
value|0x1
define|#
directive|define
name|GFT_RAM_LINE_TCP_FLAG_FIN_SHIFT
value|21
define|#
directive|define
name|GFT_RAM_LINE_TCP_FLAG_SYN_MASK
value|0x1
define|#
directive|define
name|GFT_RAM_LINE_TCP_FLAG_SYN_SHIFT
value|22
define|#
directive|define
name|GFT_RAM_LINE_TCP_FLAG_RST_MASK
value|0x1
define|#
directive|define
name|GFT_RAM_LINE_TCP_FLAG_RST_SHIFT
value|23
define|#
directive|define
name|GFT_RAM_LINE_TCP_FLAG_PSH_MASK
value|0x1
define|#
directive|define
name|GFT_RAM_LINE_TCP_FLAG_PSH_SHIFT
value|24
define|#
directive|define
name|GFT_RAM_LINE_TCP_FLAG_ACK_MASK
value|0x1
define|#
directive|define
name|GFT_RAM_LINE_TCP_FLAG_ACK_SHIFT
value|25
define|#
directive|define
name|GFT_RAM_LINE_TCP_FLAG_URG_MASK
value|0x1
define|#
directive|define
name|GFT_RAM_LINE_TCP_FLAG_URG_SHIFT
value|26
define|#
directive|define
name|GFT_RAM_LINE_TCP_FLAG_ECE_MASK
value|0x1
define|#
directive|define
name|GFT_RAM_LINE_TCP_FLAG_ECE_SHIFT
value|27
define|#
directive|define
name|GFT_RAM_LINE_TCP_FLAG_CWR_MASK
value|0x1
define|#
directive|define
name|GFT_RAM_LINE_TCP_FLAG_CWR_SHIFT
value|28
define|#
directive|define
name|GFT_RAM_LINE_TCP_FLAG_NS_MASK
value|0x1
define|#
directive|define
name|GFT_RAM_LINE_TCP_FLAG_NS_SHIFT
value|29
define|#
directive|define
name|GFT_RAM_LINE_DST_PORT_MASK
value|0x1
define|#
directive|define
name|GFT_RAM_LINE_DST_PORT_SHIFT
value|30
define|#
directive|define
name|GFT_RAM_LINE_SRC_PORT_MASK
value|0x1
define|#
directive|define
name|GFT_RAM_LINE_SRC_PORT_SHIFT
value|31
name|__le32
name|hi
decl_stmt|;
define|#
directive|define
name|GFT_RAM_LINE_DSCP_MASK
value|0x1
define|#
directive|define
name|GFT_RAM_LINE_DSCP_SHIFT
value|0
define|#
directive|define
name|GFT_RAM_LINE_OVER_IP_PROTOCOL_MASK
value|0x1
define|#
directive|define
name|GFT_RAM_LINE_OVER_IP_PROTOCOL_SHIFT
value|1
define|#
directive|define
name|GFT_RAM_LINE_DST_IP_MASK
value|0x1
define|#
directive|define
name|GFT_RAM_LINE_DST_IP_SHIFT
value|2
define|#
directive|define
name|GFT_RAM_LINE_SRC_IP_MASK
value|0x1
define|#
directive|define
name|GFT_RAM_LINE_SRC_IP_SHIFT
value|3
define|#
directive|define
name|GFT_RAM_LINE_PRIORITY_MASK
value|0x1
define|#
directive|define
name|GFT_RAM_LINE_PRIORITY_SHIFT
value|4
define|#
directive|define
name|GFT_RAM_LINE_PROVIDER_VLAN_MASK
value|0x1
define|#
directive|define
name|GFT_RAM_LINE_PROVIDER_VLAN_SHIFT
value|5
define|#
directive|define
name|GFT_RAM_LINE_VLAN_MASK
value|0x1
define|#
directive|define
name|GFT_RAM_LINE_VLAN_SHIFT
value|6
define|#
directive|define
name|GFT_RAM_LINE_DST_MAC_MASK
value|0x1
define|#
directive|define
name|GFT_RAM_LINE_DST_MAC_SHIFT
value|7
define|#
directive|define
name|GFT_RAM_LINE_SRC_MAC_MASK
value|0x1
define|#
directive|define
name|GFT_RAM_LINE_SRC_MAC_SHIFT
value|8
define|#
directive|define
name|GFT_RAM_LINE_TENANT_ID_MASK
value|0x1
define|#
directive|define
name|GFT_RAM_LINE_TENANT_ID_SHIFT
value|9
define|#
directive|define
name|GFT_RAM_LINE_RESERVED1_MASK
value|0x3FFFFF
define|#
directive|define
name|GFT_RAM_LINE_RESERVED1_SHIFT
value|10
block|}
struct|;
end_struct

begin_comment
comment|/*  * Used in the first 2 bits for gft_ram_line: Indication for vlan mask  */
end_comment

begin_enum
enum|enum
name|gft_vlan_select
block|{
name|INNER_PROVIDER_VLAN
init|=
literal|0
block|,
name|INNER_VLAN
init|=
literal|1
block|,
name|OUTER_PROVIDER_VLAN
init|=
literal|2
block|,
name|OUTER_VLAN
init|=
literal|3
block|,
name|MAX_GFT_VLAN_SELECT
block|}
enum|;
end_enum

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ECORE_HSI_ETH__ */
end_comment

end_unit

