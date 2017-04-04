begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2017-2018 Cavium, Inc.   * All rights reserved.  *  *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *  *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *  *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  *  POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ECORE_HSI_IWARP__
end_ifndef

begin_define
define|#
directive|define
name|__ECORE_HSI_IWARP__
end_define

begin_comment
comment|/************************************************************************/
end_comment

begin_comment
comment|/* Add include to ecore hsi rdma target for both roce and iwarp ecore driver */
end_comment

begin_comment
comment|/************************************************************************/
end_comment

begin_include
include|#
directive|include
file|"ecore_hsi_rdma.h"
end_include

begin_comment
comment|/************************************************************************/
end_comment

begin_comment
comment|/* Add include to common TCP target */
end_comment

begin_comment
comment|/************************************************************************/
end_comment

begin_include
include|#
directive|include
file|"tcp_common.h"
end_include

begin_comment
comment|/************************************************************************/
end_comment

begin_comment
comment|/* Add include to common iwarp target for both eCore and protocol iwarp driver */
end_comment

begin_comment
comment|/************************************************************************/
end_comment

begin_include
include|#
directive|include
file|"iwarp_common.h"
end_include

begin_comment
comment|/*  * The iwarp storm context of Ystorm  */
end_comment

begin_struct
struct|struct
name|ystorm_iwarp_conn_st_ctx
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
comment|/*  * The iwarp storm context of Pstorm  */
end_comment

begin_struct
struct|struct
name|pstorm_iwarp_conn_st_ctx
block|{
name|__le32
name|reserved
index|[
literal|36
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The iwarp storm context of Xstorm  */
end_comment

begin_struct
struct|struct
name|xstorm_iwarp_conn_st_ctx
block|{
name|__le32
name|reserved
index|[
literal|44
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|e4_xstorm_iwarp_conn_ag_ctx
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
name|E4_XSTORM_IWARP_CONN_AG_CTX_EXIST_IN_QM0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_EXIST_IN_QM0_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_EXIST_IN_QM1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_EXIST_IN_QM1_SHIFT
value|1
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_EXIST_IN_QM2_MASK
value|0x1
comment|/* exist_in_qm2 */
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_EXIST_IN_QM2_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_EXIST_IN_QM3_MASK
value|0x1
comment|/* exist_in_qm3 */
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_EXIST_IN_QM3_SHIFT
value|3
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_BIT4_MASK
value|0x1
comment|/* bit4 */
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_BIT4_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_RESERVED2_MASK
value|0x1
comment|/* cf_array_active */
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_RESERVED2_SHIFT
value|5
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_BIT6_MASK
value|0x1
comment|/* bit6 */
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_BIT6_SHIFT
value|6
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_BIT7_MASK
value|0x1
comment|/* bit7 */
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_BIT7_SHIFT
value|7
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_BIT8_MASK
value|0x1
comment|/* bit8 */
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_BIT8_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_BIT9_MASK
value|0x1
comment|/* bit9 */
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_BIT9_SHIFT
value|1
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_BIT10_MASK
value|0x1
comment|/* bit10 */
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_BIT10_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_BIT11_MASK
value|0x1
comment|/* bit11 */
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_BIT11_SHIFT
value|3
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_BIT12_MASK
value|0x1
comment|/* bit12 */
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_BIT12_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_BIT13_MASK
value|0x1
comment|/* bit13 */
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_BIT13_SHIFT
value|5
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_BIT14_MASK
value|0x1
comment|/* bit14 */
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_BIT14_SHIFT
value|6
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_YSTORM_FLUSH_OR_REWIND_SND_MAX_MASK
value|0x1
comment|/* bit15 */
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_YSTORM_FLUSH_OR_REWIND_SND_MAX_SHIFT
value|7
name|u8
name|flags2
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_CF0_MASK
value|0x3
comment|/* timer0cf */
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_CF0_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_CF1_MASK
value|0x3
comment|/* timer1cf */
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_CF1_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_CF2_MASK
value|0x3
comment|/* timer2cf */
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_CF2_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_TIMER_STOP_ALL_MASK
value|0x3
comment|/* timer_stop_all */
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_TIMER_STOP_ALL_SHIFT
value|6
name|u8
name|flags3
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_CF4_MASK
value|0x3
comment|/* cf4 */
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_CF4_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_CF5_MASK
value|0x3
comment|/* cf5 */
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_CF5_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_CF6_MASK
value|0x3
comment|/* cf6 */
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_CF6_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_CF7_MASK
value|0x3
comment|/* cf7 */
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_CF7_SHIFT
value|6
name|u8
name|flags4
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_CF8_MASK
value|0x3
comment|/* cf8 */
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_CF8_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_CF9_MASK
value|0x3
comment|/* cf9 */
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_CF9_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_CF10_MASK
value|0x3
comment|/* cf10 */
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_CF10_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_CF11_MASK
value|0x3
comment|/* cf11 */
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_CF11_SHIFT
value|6
name|u8
name|flags5
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_CF12_MASK
value|0x3
comment|/* cf12 */
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_CF12_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_CF13_MASK
value|0x3
comment|/* cf13 */
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_CF13_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_SQ_FLUSH_CF_MASK
value|0x3
comment|/* cf14 */
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_SQ_FLUSH_CF_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_CF15_MASK
value|0x3
comment|/* cf15 */
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_CF15_SHIFT
value|6
name|u8
name|flags6
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_MPA_OR_ERROR_WAKEUP_TRIGGER_CF_MASK
value|0x3
comment|/* cf16 */
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_MPA_OR_ERROR_WAKEUP_TRIGGER_CF_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_CF17_MASK
value|0x3
comment|/* cf_array_cf */
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_CF17_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_CF18_MASK
value|0x3
comment|/* cf18 */
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_CF18_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_DQ_FLUSH_MASK
value|0x3
comment|/* cf19 */
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_DQ_FLUSH_SHIFT
value|6
name|u8
name|flags7
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_FLUSH_Q0_MASK
value|0x3
comment|/* cf20 */
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_FLUSH_Q0_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_FLUSH_Q1_MASK
value|0x3
comment|/* cf21 */
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_FLUSH_Q1_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_SLOW_PATH_MASK
value|0x3
comment|/* cf22 */
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_SLOW_PATH_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_CF0EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_CF0EN_SHIFT
value|6
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_CF1EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_CF1EN_SHIFT
value|7
name|u8
name|flags8
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_CF2EN_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_CF2EN_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_TIMER_STOP_ALL_EN_MASK
value|0x1
comment|/* cf3en */
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_TIMER_STOP_ALL_EN_SHIFT
value|1
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_CF4EN_MASK
value|0x1
comment|/* cf4en */
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_CF4EN_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_CF5EN_MASK
value|0x1
comment|/* cf5en */
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_CF5EN_SHIFT
value|3
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_CF6EN_MASK
value|0x1
comment|/* cf6en */
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_CF6EN_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_CF7EN_MASK
value|0x1
comment|/* cf7en */
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_CF7EN_SHIFT
value|5
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_CF8EN_MASK
value|0x1
comment|/* cf8en */
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_CF8EN_SHIFT
value|6
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_CF9EN_MASK
value|0x1
comment|/* cf9en */
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_CF9EN_SHIFT
value|7
name|u8
name|flags9
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_CF10EN_MASK
value|0x1
comment|/* cf10en */
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_CF10EN_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_CF11EN_MASK
value|0x1
comment|/* cf11en */
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_CF11EN_SHIFT
value|1
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_CF12EN_MASK
value|0x1
comment|/* cf12en */
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_CF12EN_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_CF13EN_MASK
value|0x1
comment|/* cf13en */
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_CF13EN_SHIFT
value|3
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_SQ_FLUSH_CF_EN_MASK
value|0x1
comment|/* cf14en */
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_SQ_FLUSH_CF_EN_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_CF15EN_MASK
value|0x1
comment|/* cf15en */
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_CF15EN_SHIFT
value|5
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_MPA_OR_ERROR_WAKEUP_TRIGGER_CF_EN_MASK
value|0x1
comment|/* cf16en */
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_MPA_OR_ERROR_WAKEUP_TRIGGER_CF_EN_SHIFT
value|6
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_CF17EN_MASK
value|0x1
comment|/* cf_array_cf_en */
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_CF17EN_SHIFT
value|7
name|u8
name|flags10
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_CF18EN_MASK
value|0x1
comment|/* cf18en */
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_CF18EN_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_DQ_FLUSH_EN_MASK
value|0x1
comment|/* cf19en */
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_DQ_FLUSH_EN_SHIFT
value|1
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_FLUSH_Q0_EN_MASK
value|0x1
comment|/* cf20en */
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_FLUSH_Q0_EN_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_FLUSH_Q1_EN_MASK
value|0x1
comment|/* cf21en */
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_FLUSH_Q1_EN_SHIFT
value|3
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_SLOW_PATH_EN_MASK
value|0x1
comment|/* cf22en */
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_SLOW_PATH_EN_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_CF23EN_MASK
value|0x1
comment|/* cf23en */
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_CF23EN_SHIFT
value|5
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_RULE0EN_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_RULE0EN_SHIFT
value|6
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_MORE_TO_SEND_RULE_EN_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_MORE_TO_SEND_RULE_EN_SHIFT
value|7
name|u8
name|flags11
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_TX_BLOCKED_EN_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_TX_BLOCKED_EN_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_RULE3EN_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_RULE3EN_SHIFT
value|1
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_RESERVED3_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_RESERVED3_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_RULE5EN_MASK
value|0x1
comment|/* rule5en */
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_RULE5EN_SHIFT
value|3
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_RULE6EN_MASK
value|0x1
comment|/* rule6en */
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_RULE6EN_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_RULE7EN_MASK
value|0x1
comment|/* rule7en */
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_RULE7EN_SHIFT
value|5
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_A0_RESERVED1_MASK
value|0x1
comment|/* rule8en */
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_A0_RESERVED1_SHIFT
value|6
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_RULE9EN_MASK
value|0x1
comment|/* rule9en */
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_RULE9EN_SHIFT
value|7
name|u8
name|flags12
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_SQ_NOT_EMPTY_RULE_EN_MASK
value|0x1
comment|/* rule10en */
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_SQ_NOT_EMPTY_RULE_EN_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_RULE11EN_MASK
value|0x1
comment|/* rule11en */
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_RULE11EN_SHIFT
value|1
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_A0_RESERVED2_MASK
value|0x1
comment|/* rule12en */
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_A0_RESERVED2_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_A0_RESERVED3_MASK
value|0x1
comment|/* rule13en */
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_A0_RESERVED3_SHIFT
value|3
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_SQ_FENCE_RULE_EN_MASK
value|0x1
comment|/* rule14en */
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_SQ_FENCE_RULE_EN_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_RULE15EN_MASK
value|0x1
comment|/* rule15en */
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_RULE15EN_SHIFT
value|5
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_RULE16EN_MASK
value|0x1
comment|/* rule16en */
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_RULE16EN_SHIFT
value|6
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_RULE17EN_MASK
value|0x1
comment|/* rule17en */
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_RULE17EN_SHIFT
value|7
name|u8
name|flags13
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_IRQ_NOT_EMPTY_RULE_EN_MASK
value|0x1
comment|/* rule18en */
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_IRQ_NOT_EMPTY_RULE_EN_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_HQ_NOT_FULL_RULE_EN_MASK
value|0x1
comment|/* rule19en */
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_HQ_NOT_FULL_RULE_EN_SHIFT
value|1
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_ORQ_RD_FENCE_RULE_EN_MASK
value|0x1
comment|/* rule20en */
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_ORQ_RD_FENCE_RULE_EN_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_RULE21EN_MASK
value|0x1
comment|/* rule21en */
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_RULE21EN_SHIFT
value|3
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_A0_RESERVED6_MASK
value|0x1
comment|/* rule22en */
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_A0_RESERVED6_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_ORQ_NOT_FULL_RULE_EN_MASK
value|0x1
comment|/* rule23en */
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_ORQ_NOT_FULL_RULE_EN_SHIFT
value|5
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_A0_RESERVED8_MASK
value|0x1
comment|/* rule24en */
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_A0_RESERVED8_SHIFT
value|6
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_A0_RESERVED9_MASK
value|0x1
comment|/* rule25en */
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_A0_RESERVED9_SHIFT
value|7
name|u8
name|flags14
decl_stmt|;
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_BIT16_MASK
value|0x1
comment|/* bit16 */
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_BIT16_SHIFT
value|0
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_BIT17_MASK
value|0x1
comment|/* bit17 */
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_BIT17_SHIFT
value|1
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_BIT18_MASK
value|0x1
comment|/* bit18 */
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_BIT18_SHIFT
value|2
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_E5_RESERVED1_MASK
value|0x1
comment|/* bit19 */
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_E5_RESERVED1_SHIFT
value|3
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_E5_RESERVED2_MASK
value|0x1
comment|/* bit20 */
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_E5_RESERVED2_SHIFT
value|4
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_E5_RESERVED3_MASK
value|0x1
comment|/* bit21 */
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_E5_RESERVED3_SHIFT
value|5
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_CF23_MASK
value|0x3
comment|/* cf23 */
define|#
directive|define
name|E4_XSTORM_IWARP_CONN_AG_CTX_CF23_SHIFT
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
name|sq_comp_cons
comment|/* physical_q2 */
decl_stmt|;
name|__le16
name|sq_tx_cons
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
name|more_to_send_seq
comment|/* reg3 */
decl_stmt|;
name|__le32
name|reg4
comment|/* reg4 */
decl_stmt|;
name|__le32
name|rewinded_snd_max
comment|/* cf_array0 */
decl_stmt|;
name|__le32
name|rd_msn
comment|/* cf_array1 */
decl_stmt|;
name|__le16
name|irq_prod_via_msdm
comment|/* word7 */
decl_stmt|;
name|__le16
name|irq_cons
comment|/* word8 */
decl_stmt|;
name|__le16
name|hq_cons_th_or_mpa_data
comment|/* word9 */
decl_stmt|;
name|__le16
name|hq_cons
comment|/* word10 */
decl_stmt|;
name|__le32
name|atom_msn
comment|/* reg7 */
decl_stmt|;
name|__le32
name|orq_cons
comment|/* reg8 */
decl_stmt|;
name|__le32
name|orq_cons_th
comment|/* reg9 */
decl_stmt|;
name|u8
name|byte7
comment|/* byte7 */
decl_stmt|;
name|u8
name|max_ord
comment|/* byte8 */
decl_stmt|;
name|u8
name|wqe_data_pad_bytes
comment|/* byte9 */
decl_stmt|;
name|u8
name|former_hq_prod
comment|/* byte10 */
decl_stmt|;
name|u8
name|irq_prod_via_msem
comment|/* byte11 */
decl_stmt|;
name|u8
name|byte12
comment|/* byte12 */
decl_stmt|;
name|u8
name|max_pkt_pdu_size_lo
comment|/* byte13 */
decl_stmt|;
name|u8
name|max_pkt_pdu_size_hi
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
name|e5_reserved4
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
name|shared_queue_page_addr_lo
comment|/* reg12 */
decl_stmt|;
name|__le32
name|shared_queue_page_addr_hi
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
name|e4_tstorm_iwarp_conn_ag_ctx
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
name|E4_TSTORM_IWARP_CONN_AG_CTX_EXIST_IN_QM0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E4_TSTORM_IWARP_CONN_AG_CTX_EXIST_IN_QM0_SHIFT
value|0
define|#
directive|define
name|E4_TSTORM_IWARP_CONN_AG_CTX_BIT1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E4_TSTORM_IWARP_CONN_AG_CTX_BIT1_SHIFT
value|1
define|#
directive|define
name|E4_TSTORM_IWARP_CONN_AG_CTX_BIT2_MASK
value|0x1
comment|/* bit2 */
define|#
directive|define
name|E4_TSTORM_IWARP_CONN_AG_CTX_BIT2_SHIFT
value|2
define|#
directive|define
name|E4_TSTORM_IWARP_CONN_AG_CTX_MSTORM_FLUSH_MASK
value|0x1
comment|/* bit3 */
define|#
directive|define
name|E4_TSTORM_IWARP_CONN_AG_CTX_MSTORM_FLUSH_SHIFT
value|3
define|#
directive|define
name|E4_TSTORM_IWARP_CONN_AG_CTX_BIT4_MASK
value|0x1
comment|/* bit4 */
define|#
directive|define
name|E4_TSTORM_IWARP_CONN_AG_CTX_BIT4_SHIFT
value|4
define|#
directive|define
name|E4_TSTORM_IWARP_CONN_AG_CTX_CACHED_ORQ_MASK
value|0x1
comment|/* bit5 */
define|#
directive|define
name|E4_TSTORM_IWARP_CONN_AG_CTX_CACHED_ORQ_SHIFT
value|5
define|#
directive|define
name|E4_TSTORM_IWARP_CONN_AG_CTX_CF0_MASK
value|0x3
comment|/* timer0cf */
define|#
directive|define
name|E4_TSTORM_IWARP_CONN_AG_CTX_CF0_SHIFT
value|6
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E4_TSTORM_IWARP_CONN_AG_CTX_RQ_POST_CF_MASK
value|0x3
comment|/* timer1cf */
define|#
directive|define
name|E4_TSTORM_IWARP_CONN_AG_CTX_RQ_POST_CF_SHIFT
value|0
define|#
directive|define
name|E4_TSTORM_IWARP_CONN_AG_CTX_FLUSH_OR_ERROR_DETECTED_MASK
value|0x3
comment|/* timer2cf */
define|#
directive|define
name|E4_TSTORM_IWARP_CONN_AG_CTX_FLUSH_OR_ERROR_DETECTED_SHIFT
value|2
define|#
directive|define
name|E4_TSTORM_IWARP_CONN_AG_CTX_TIMER_STOP_ALL_MASK
value|0x3
comment|/* timer_stop_all */
define|#
directive|define
name|E4_TSTORM_IWARP_CONN_AG_CTX_TIMER_STOP_ALL_SHIFT
value|4
define|#
directive|define
name|E4_TSTORM_IWARP_CONN_AG_CTX_CF4_MASK
value|0x3
comment|/* cf4 */
define|#
directive|define
name|E4_TSTORM_IWARP_CONN_AG_CTX_CF4_SHIFT
value|6
name|u8
name|flags2
decl_stmt|;
define|#
directive|define
name|E4_TSTORM_IWARP_CONN_AG_CTX_CF5_MASK
value|0x3
comment|/* cf5 */
define|#
directive|define
name|E4_TSTORM_IWARP_CONN_AG_CTX_CF5_SHIFT
value|0
define|#
directive|define
name|E4_TSTORM_IWARP_CONN_AG_CTX_CF6_MASK
value|0x3
comment|/* cf6 */
define|#
directive|define
name|E4_TSTORM_IWARP_CONN_AG_CTX_CF6_SHIFT
value|2
define|#
directive|define
name|E4_TSTORM_IWARP_CONN_AG_CTX_CF7_MASK
value|0x3
comment|/* cf7 */
define|#
directive|define
name|E4_TSTORM_IWARP_CONN_AG_CTX_CF7_SHIFT
value|4
define|#
directive|define
name|E4_TSTORM_IWARP_CONN_AG_CTX_CF8_MASK
value|0x3
comment|/* cf8 */
define|#
directive|define
name|E4_TSTORM_IWARP_CONN_AG_CTX_CF8_SHIFT
value|6
name|u8
name|flags3
decl_stmt|;
define|#
directive|define
name|E4_TSTORM_IWARP_CONN_AG_CTX_FLUSH_Q0_MASK
value|0x3
comment|/* cf9 */
define|#
directive|define
name|E4_TSTORM_IWARP_CONN_AG_CTX_FLUSH_Q0_SHIFT
value|0
define|#
directive|define
name|E4_TSTORM_IWARP_CONN_AG_CTX_CF10_MASK
value|0x3
comment|/* cf10 */
define|#
directive|define
name|E4_TSTORM_IWARP_CONN_AG_CTX_CF10_SHIFT
value|2
define|#
directive|define
name|E4_TSTORM_IWARP_CONN_AG_CTX_CF0EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E4_TSTORM_IWARP_CONN_AG_CTX_CF0EN_SHIFT
value|4
define|#
directive|define
name|E4_TSTORM_IWARP_CONN_AG_CTX_RQ_POST_CF_EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E4_TSTORM_IWARP_CONN_AG_CTX_RQ_POST_CF_EN_SHIFT
value|5
define|#
directive|define
name|E4_TSTORM_IWARP_CONN_AG_CTX_FLUSH_OR_ERROR_DETECTED_EN_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E4_TSTORM_IWARP_CONN_AG_CTX_FLUSH_OR_ERROR_DETECTED_EN_SHIFT
value|6
define|#
directive|define
name|E4_TSTORM_IWARP_CONN_AG_CTX_TIMER_STOP_ALL_EN_MASK
value|0x1
comment|/* cf3en */
define|#
directive|define
name|E4_TSTORM_IWARP_CONN_AG_CTX_TIMER_STOP_ALL_EN_SHIFT
value|7
name|u8
name|flags4
decl_stmt|;
define|#
directive|define
name|E4_TSTORM_IWARP_CONN_AG_CTX_CF4EN_MASK
value|0x1
comment|/* cf4en */
define|#
directive|define
name|E4_TSTORM_IWARP_CONN_AG_CTX_CF4EN_SHIFT
value|0
define|#
directive|define
name|E4_TSTORM_IWARP_CONN_AG_CTX_CF5EN_MASK
value|0x1
comment|/* cf5en */
define|#
directive|define
name|E4_TSTORM_IWARP_CONN_AG_CTX_CF5EN_SHIFT
value|1
define|#
directive|define
name|E4_TSTORM_IWARP_CONN_AG_CTX_CF6EN_MASK
value|0x1
comment|/* cf6en */
define|#
directive|define
name|E4_TSTORM_IWARP_CONN_AG_CTX_CF6EN_SHIFT
value|2
define|#
directive|define
name|E4_TSTORM_IWARP_CONN_AG_CTX_CF7EN_MASK
value|0x1
comment|/* cf7en */
define|#
directive|define
name|E4_TSTORM_IWARP_CONN_AG_CTX_CF7EN_SHIFT
value|3
define|#
directive|define
name|E4_TSTORM_IWARP_CONN_AG_CTX_CF8EN_MASK
value|0x1
comment|/* cf8en */
define|#
directive|define
name|E4_TSTORM_IWARP_CONN_AG_CTX_CF8EN_SHIFT
value|4
define|#
directive|define
name|E4_TSTORM_IWARP_CONN_AG_CTX_FLUSH_Q0_EN_MASK
value|0x1
comment|/* cf9en */
define|#
directive|define
name|E4_TSTORM_IWARP_CONN_AG_CTX_FLUSH_Q0_EN_SHIFT
value|5
define|#
directive|define
name|E4_TSTORM_IWARP_CONN_AG_CTX_CF10EN_MASK
value|0x1
comment|/* cf10en */
define|#
directive|define
name|E4_TSTORM_IWARP_CONN_AG_CTX_CF10EN_SHIFT
value|6
define|#
directive|define
name|E4_TSTORM_IWARP_CONN_AG_CTX_RULE0EN_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E4_TSTORM_IWARP_CONN_AG_CTX_RULE0EN_SHIFT
value|7
name|u8
name|flags5
decl_stmt|;
define|#
directive|define
name|E4_TSTORM_IWARP_CONN_AG_CTX_RULE1EN_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E4_TSTORM_IWARP_CONN_AG_CTX_RULE1EN_SHIFT
value|0
define|#
directive|define
name|E4_TSTORM_IWARP_CONN_AG_CTX_RULE2EN_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E4_TSTORM_IWARP_CONN_AG_CTX_RULE2EN_SHIFT
value|1
define|#
directive|define
name|E4_TSTORM_IWARP_CONN_AG_CTX_RULE3EN_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E4_TSTORM_IWARP_CONN_AG_CTX_RULE3EN_SHIFT
value|2
define|#
directive|define
name|E4_TSTORM_IWARP_CONN_AG_CTX_RULE4EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E4_TSTORM_IWARP_CONN_AG_CTX_RULE4EN_SHIFT
value|3
define|#
directive|define
name|E4_TSTORM_IWARP_CONN_AG_CTX_RULE5EN_MASK
value|0x1
comment|/* rule5en */
define|#
directive|define
name|E4_TSTORM_IWARP_CONN_AG_CTX_RULE5EN_SHIFT
value|4
define|#
directive|define
name|E4_TSTORM_IWARP_CONN_AG_CTX_SND_SQ_CONS_RULE_MASK
value|0x1
comment|/* rule6en */
define|#
directive|define
name|E4_TSTORM_IWARP_CONN_AG_CTX_SND_SQ_CONS_RULE_SHIFT
value|5
define|#
directive|define
name|E4_TSTORM_IWARP_CONN_AG_CTX_RULE7EN_MASK
value|0x1
comment|/* rule7en */
define|#
directive|define
name|E4_TSTORM_IWARP_CONN_AG_CTX_RULE7EN_SHIFT
value|6
define|#
directive|define
name|E4_TSTORM_IWARP_CONN_AG_CTX_RULE8EN_MASK
value|0x1
comment|/* rule8en */
define|#
directive|define
name|E4_TSTORM_IWARP_CONN_AG_CTX_RULE8EN_SHIFT
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
name|unaligned_nxt_seq
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
name|orq_cache_idx
comment|/* byte2 */
decl_stmt|;
name|u8
name|hq_prod
comment|/* byte3 */
decl_stmt|;
name|__le16
name|sq_tx_cons_th
comment|/* word0 */
decl_stmt|;
name|u8
name|orq_prod
comment|/* byte4 */
decl_stmt|;
name|u8
name|irq_cons
comment|/* byte5 */
decl_stmt|;
name|__le16
name|sq_tx_cons
comment|/* word1 */
decl_stmt|;
name|__le16
name|conn_dpi
comment|/* conn_dpi */
decl_stmt|;
name|__le16
name|rq_prod
comment|/* word3 */
decl_stmt|;
name|__le32
name|snd_seq
comment|/* reg9 */
decl_stmt|;
name|__le32
name|reg10
comment|/* reg10 */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The iwarp storm context of Tstorm  */
end_comment

begin_struct
struct|struct
name|tstorm_iwarp_conn_st_ctx
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

begin_comment
comment|/*  * The iwarp storm context of Mstorm  */
end_comment

begin_struct
struct|struct
name|mstorm_iwarp_conn_st_ctx
block|{
name|__le32
name|reserved
index|[
literal|32
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The iwarp storm context of Ustorm  */
end_comment

begin_struct
struct|struct
name|ustorm_iwarp_conn_st_ctx
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
comment|/*  * iwarp connection context  */
end_comment

begin_struct
struct|struct
name|iwarp_conn_context
block|{
name|struct
name|ystorm_iwarp_conn_st_ctx
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
name|pstorm_iwarp_conn_st_ctx
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
name|xstorm_iwarp_conn_st_ctx
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
name|e4_xstorm_iwarp_conn_ag_ctx
name|xstorm_ag_context
comment|/* xstorm aggregative context */
decl_stmt|;
name|struct
name|e4_tstorm_iwarp_conn_ag_ctx
name|tstorm_ag_context
comment|/* tstorm aggregative context */
decl_stmt|;
name|struct
name|timers_context
name|timer_context
comment|/* timer context */
decl_stmt|;
name|struct
name|e4_ustorm_rdma_conn_ag_ctx
name|ustorm_ag_context
comment|/* ustorm aggregative context */
decl_stmt|;
name|struct
name|tstorm_iwarp_conn_st_ctx
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
name|mstorm_iwarp_conn_st_ctx
name|mstorm_st_context
comment|/* mstorm storm context */
decl_stmt|;
name|struct
name|ustorm_iwarp_conn_st_ctx
name|ustorm_st_context
comment|/* ustorm storm context */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * iWARP create QP params passed by driver to FW in CreateQP Request Ramrod   */
end_comment

begin_struct
struct|struct
name|iwarp_create_qp_ramrod_data
block|{
name|u8
name|flags
decl_stmt|;
define|#
directive|define
name|IWARP_CREATE_QP_RAMROD_DATA_FMR_AND_RESERVED_EN_MASK
value|0x1
define|#
directive|define
name|IWARP_CREATE_QP_RAMROD_DATA_FMR_AND_RESERVED_EN_SHIFT
value|0
define|#
directive|define
name|IWARP_CREATE_QP_RAMROD_DATA_SIGNALED_COMP_MASK
value|0x1
define|#
directive|define
name|IWARP_CREATE_QP_RAMROD_DATA_SIGNALED_COMP_SHIFT
value|1
define|#
directive|define
name|IWARP_CREATE_QP_RAMROD_DATA_RDMA_RD_EN_MASK
value|0x1
define|#
directive|define
name|IWARP_CREATE_QP_RAMROD_DATA_RDMA_RD_EN_SHIFT
value|2
define|#
directive|define
name|IWARP_CREATE_QP_RAMROD_DATA_RDMA_WR_EN_MASK
value|0x1
define|#
directive|define
name|IWARP_CREATE_QP_RAMROD_DATA_RDMA_WR_EN_SHIFT
value|3
define|#
directive|define
name|IWARP_CREATE_QP_RAMROD_DATA_ATOMIC_EN_MASK
value|0x1
define|#
directive|define
name|IWARP_CREATE_QP_RAMROD_DATA_ATOMIC_EN_SHIFT
value|4
define|#
directive|define
name|IWARP_CREATE_QP_RAMROD_DATA_SRQ_FLG_MASK
value|0x1
define|#
directive|define
name|IWARP_CREATE_QP_RAMROD_DATA_SRQ_FLG_SHIFT
value|5
define|#
directive|define
name|IWARP_CREATE_QP_RAMROD_DATA_RESERVED0_MASK
value|0x3
define|#
directive|define
name|IWARP_CREATE_QP_RAMROD_DATA_RESERVED0_SHIFT
value|6
name|u8
name|reserved1
comment|/* Basic/Enhanced */
decl_stmt|;
name|__le16
name|pd
decl_stmt|;
name|__le16
name|sq_num_pages
decl_stmt|;
name|__le16
name|rq_num_pages
decl_stmt|;
name|__le32
name|reserved3
index|[
literal|2
index|]
decl_stmt|;
name|struct
name|regpair
name|qp_handle_for_cqe
comment|/* For use in CQEs */
decl_stmt|;
name|struct
name|rdma_srq_id
name|srq_id
decl_stmt|;
name|__le32
name|cq_cid_for_sq
comment|/* Cid of the CQ that will be posted from SQ */
decl_stmt|;
name|__le32
name|cq_cid_for_rq
comment|/* Cid of the CQ that will be posted from RQ */
decl_stmt|;
name|__le16
name|dpi
decl_stmt|;
name|__le16
name|physical_q0
comment|/* Physical QM queue to be tied to logical Q0 */
decl_stmt|;
name|__le16
name|physical_q1
comment|/* Physical QM queue to be tied to logical Q1 */
decl_stmt|;
name|u8
name|reserved2
index|[
literal|6
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * iWARP completion queue types  */
end_comment

begin_enum
enum|enum
name|iwarp_eqe_async_opcode
block|{
name|IWARP_EVENT_TYPE_ASYNC_CONNECT_COMPLETE
comment|/* Async completion oafter TCP 3-way handshake */
block|,
name|IWARP_EVENT_TYPE_ASYNC_ENHANCED_MPA_REPLY_ARRIVED
comment|/* Enhanced MPA reply arrived. Driver should either send RTR or reject */
block|,
name|IWARP_EVENT_TYPE_ASYNC_MPA_HANDSHAKE_COMPLETE
comment|/* MPA Negotiations completed */
block|,
name|IWARP_EVENT_TYPE_ASYNC_CID_CLEANED
comment|/* Async completion that indicates to the driver that the CID can be re-used. */
block|,
name|IWARP_EVENT_TYPE_ASYNC_EXCEPTION_DETECTED
comment|/* Async EQE indicating detection of an error/exception on a QP at Firmware */
block|,
name|IWARP_EVENT_TYPE_ASYNC_QP_IN_ERROR_STATE
comment|/* Async EQE indicating QP is in Error state. */
block|,
name|IWARP_EVENT_TYPE_ASYNC_CQ_OVERFLOW
comment|/* Async EQE indicating CQ, whose handle is sent with this event, has overflowed */
block|,
name|MAX_IWARP_EQE_ASYNC_OPCODE
block|}
enum|;
end_enum

begin_struct
struct|struct
name|iwarp_eqe_data_mpa_async_completion
block|{
name|__le16
name|ulp_data_len
comment|/* On active side, length of ULP Data, from peers MPA Connect Response */
decl_stmt|;
name|u8
name|reserved
index|[
literal|6
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|iwarp_eqe_data_tcp_async_completion
block|{
name|__le16
name|ulp_data_len
comment|/* On passive side, length of ULP Data, from peers active MPA Connect Request */
decl_stmt|;
name|u8
name|mpa_handshake_mode
comment|/* Negotiation type Basic/Enhanced */
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
comment|/*  * iWARP completion queue types  */
end_comment

begin_enum
enum|enum
name|iwarp_eqe_sync_opcode
block|{
name|IWARP_EVENT_TYPE_TCP_OFFLOAD
init|=
literal|11
comment|/* iWARP event queue response after option 2 offload Ramrod */
block|,
name|IWARP_EVENT_TYPE_TCP_ABORT
block|,
name|IWARP_EVENT_TYPE_MPA_OFFLOAD
comment|/* Synchronous completion for MPA offload Request */
block|,
name|IWARP_EVENT_TYPE_MPA_OFFLOAD_SEND_RTR
block|,
name|IWARP_EVENT_TYPE_CREATE_QP
block|,
name|IWARP_EVENT_TYPE_QUERY_QP
block|,
name|IWARP_EVENT_TYPE_MODIFY_QP
block|,
name|IWARP_EVENT_TYPE_DESTROY_QP
block|,
name|MAX_IWARP_EQE_SYNC_OPCODE
block|}
enum|;
end_enum

begin_comment
comment|/*  * iWARP EQE completion status   */
end_comment

begin_enum
enum|enum
name|iwarp_fw_return_code
block|{
name|IWARP_CONN_ERROR_TCP_CONNECT_INVALID_PACKET
init|=
literal|5
comment|/* Got invalid packet SYN/SYN-ACK */
block|,
name|IWARP_CONN_ERROR_TCP_CONNECTION_RST
comment|/* Got RST during offload TCP connection  */
block|,
name|IWARP_CONN_ERROR_TCP_CONNECT_TIMEOUT
comment|/* TCP connection setup timed out */
block|,
name|IWARP_CONN_ERROR_MPA_ERROR_REJECT
comment|/* Got Reject in MPA reply. */
block|,
name|IWARP_CONN_ERROR_MPA_NOT_SUPPORTED_VER
comment|/* Got MPA request with higher version that we support. */
block|,
name|IWARP_CONN_ERROR_MPA_RST
comment|/* Got RST during MPA negotiation */
block|,
name|IWARP_CONN_ERROR_MPA_FIN
comment|/* Got FIN during MPA negotiation */
block|,
name|IWARP_CONN_ERROR_MPA_RTR_MISMATCH
comment|/* RTR mismatch detected when MPA reply arrived. */
block|,
name|IWARP_CONN_ERROR_MPA_INSUF_IRD
comment|/* Insufficient IRD on the MPA reply that arrived. */
block|,
name|IWARP_CONN_ERROR_MPA_INVALID_PACKET
comment|/* Incoming MPAp acket failed on FW verifications */
block|,
name|IWARP_CONN_ERROR_MPA_LOCAL_ERROR
comment|/* Detected an internal error during MPA negotiation. */
block|,
name|IWARP_CONN_ERROR_MPA_TIMEOUT
comment|/* MPA negotiation timed out. */
block|,
name|IWARP_CONN_ERROR_MPA_TERMINATE
comment|/* Got Terminate during MPA negotiation. */
block|,
name|IWARP_QP_IN_ERROR_GOOD_CLOSE
comment|/* LLP connection was closed gracefully - Used for async IWARP_EVENT_TYPE_ASYNC_QP_IN_ERROR_STATE */
block|,
name|IWARP_QP_IN_ERROR_BAD_CLOSE
comment|/* LLP Connection was closed abortively - Used for async IWARP_EVENT_TYPE_ASYNC_QP_IN_ERROR_STATE */
block|,
name|IWARP_EXCEPTION_DETECTED_LLP_CLOSED
comment|/* LLP has been disociated from the QP, although the TCP connection may not be closed yet - Used for async IWARP_EVENT_TYPE_ASYNC_EXCEPTION_DETECTED */
block|,
name|IWARP_EXCEPTION_DETECTED_LLP_RESET
comment|/* LLP has Reset (either because of an RST, or a bad-close condition) - Used for async IWARP_EVENT_TYPE_ASYNC_EXCEPTION_DETECTED */
block|,
name|IWARP_EXCEPTION_DETECTED_IRQ_FULL
comment|/* Peer sent more outstanding Read Requests than IRD - Used for async IWARP_EVENT_TYPE_ASYNC_EXCEPTION_DETECTED */
block|,
name|IWARP_EXCEPTION_DETECTED_RQ_EMPTY
comment|/* SEND request received with RQ empty - Used for async IWARP_EVENT_TYPE_ASYNC_EXCEPTION_DETECTED */
block|,
name|IWARP_EXCEPTION_DETECTED_LLP_TIMEOUT
comment|/* TCP Retransmissions timed out - Used for async IWARP_EVENT_TYPE_ASYNC_EXCEPTION_DETECTED */
block|,
name|IWARP_EXCEPTION_DETECTED_REMOTE_PROTECTION_ERROR
comment|/* Peers Remote Access caused error */
block|,
name|IWARP_EXCEPTION_DETECTED_CQ_OVERFLOW
comment|/* CQ overflow detected */
block|,
name|IWARP_EXCEPTION_DETECTED_LOCAL_CATASTROPHIC
comment|/* Local catastrophic error detected - Used for async IWARP_EVENT_TYPE_ASYNC_EXCEPTION_DETECTED */
block|,
name|IWARP_EXCEPTION_DETECTED_LOCAL_ACCESS_ERROR
comment|/* Local Access error detected while responding - Used for async IWARP_EVENT_TYPE_ASYNC_EXCEPTION_DETECTED */
block|,
name|IWARP_EXCEPTION_DETECTED_REMOTE_OPERATION_ERROR
comment|/* An operation/protocol error caused by Remote Consumer */
block|,
name|IWARP_EXCEPTION_DETECTED_TERMINATE_RECEIVED
comment|/* Peer sent a TERMINATE message */
block|,
name|MAX_IWARP_FW_RETURN_CODE
block|}
enum|;
end_enum

begin_comment
comment|/*  * unaligned opaque data received from LL2  */
end_comment

begin_struct
struct|struct
name|iwarp_init_func_params
block|{
name|u8
name|ll2_ooo_q_index
comment|/* LL2 OOO queue id. The unaligned queue id will be + 1 */
decl_stmt|;
name|u8
name|reserved1
index|[
literal|7
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * iwarp func init ramrod data  */
end_comment

begin_struct
struct|struct
name|iwarp_init_func_ramrod_data
block|{
name|struct
name|rdma_init_func_ramrod_data
name|rdma
decl_stmt|;
name|struct
name|tcp_init_params
name|tcp
decl_stmt|;
name|struct
name|iwarp_init_func_params
name|iwarp
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * iWARP QP - possible states to transition to  */
end_comment

begin_enum
enum|enum
name|iwarp_modify_qp_new_state_type
block|{
name|IWARP_MODIFY_QP_STATE_CLOSING
init|=
literal|1
comment|/* graceful close */
block|,
name|IWARP_MODIFY_QP_STATE_ERROR
init|=
literal|2
comment|/* abortive close, if LLP connection still exists */
block|,
name|MAX_IWARP_MODIFY_QP_NEW_STATE_TYPE
block|}
enum|;
end_enum

begin_comment
comment|/*  * iwarp modify qp responder ramrod data  */
end_comment

begin_struct
struct|struct
name|iwarp_modify_qp_ramrod_data
block|{
name|__le16
name|transition_to_state
decl_stmt|;
name|__le16
name|flags
decl_stmt|;
define|#
directive|define
name|IWARP_MODIFY_QP_RAMROD_DATA_RDMA_RD_EN_MASK
value|0x1
define|#
directive|define
name|IWARP_MODIFY_QP_RAMROD_DATA_RDMA_RD_EN_SHIFT
value|0
define|#
directive|define
name|IWARP_MODIFY_QP_RAMROD_DATA_RDMA_WR_EN_MASK
value|0x1
define|#
directive|define
name|IWARP_MODIFY_QP_RAMROD_DATA_RDMA_WR_EN_SHIFT
value|1
define|#
directive|define
name|IWARP_MODIFY_QP_RAMROD_DATA_ATOMIC_EN_MASK
value|0x1
define|#
directive|define
name|IWARP_MODIFY_QP_RAMROD_DATA_ATOMIC_EN_SHIFT
value|2
define|#
directive|define
name|IWARP_MODIFY_QP_RAMROD_DATA_STATE_TRANS_EN_MASK
value|0x1
comment|/* change QP state as per transition_to_state field */
define|#
directive|define
name|IWARP_MODIFY_QP_RAMROD_DATA_STATE_TRANS_EN_SHIFT
value|3
define|#
directive|define
name|IWARP_MODIFY_QP_RAMROD_DATA_RDMA_OPS_EN_FLG_MASK
value|0x1
comment|/* If set, the rdma_rd/wr/atomic_en should be updated */
define|#
directive|define
name|IWARP_MODIFY_QP_RAMROD_DATA_RDMA_OPS_EN_FLG_SHIFT
value|4
define|#
directive|define
name|IWARP_MODIFY_QP_RAMROD_DATA_RESERVED_MASK
value|0x7FF
define|#
directive|define
name|IWARP_MODIFY_QP_RAMROD_DATA_RESERVED_SHIFT
value|5
name|__le32
name|reserved3
index|[
literal|3
index|]
decl_stmt|;
name|__le32
name|reserved4
index|[
literal|8
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * MPA params for Enhanced mode  */
end_comment

begin_struct
struct|struct
name|mpa_rq_params
block|{
name|__le32
name|ird
decl_stmt|;
name|__le32
name|ord
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * MPA host Address-Len for private data  */
end_comment

begin_struct
struct|struct
name|mpa_ulp_buffer
block|{
name|struct
name|regpair
name|addr
decl_stmt|;
name|__le16
name|len
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
comment|/*  * iWARP MPA offload params common to Basic and Enhanced modes  */
end_comment

begin_struct
struct|struct
name|mpa_outgoing_params
block|{
name|u8
name|crc_needed
decl_stmt|;
name|u8
name|reject
comment|/* Valid only for passive side. */
decl_stmt|;
name|u8
name|reserved
index|[
literal|6
index|]
decl_stmt|;
name|struct
name|mpa_rq_params
name|out_rq
decl_stmt|;
name|struct
name|mpa_ulp_buffer
name|outgoing_ulp_buffer
comment|/* ULP buffer populated by the host */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * iWARP MPA offload params passed by driver to FW in MPA Offload Request Ramrod   */
end_comment

begin_struct
struct|struct
name|iwarp_mpa_offload_ramrod_data
block|{
name|struct
name|mpa_outgoing_params
name|common
decl_stmt|;
name|__le32
name|tcp_cid
decl_stmt|;
name|u8
name|mode
comment|/* Basic/Enhanced */
decl_stmt|;
name|u8
name|tcp_connect_side
comment|/* Passive/Active. use enum tcp_connect_mode */
decl_stmt|;
name|u8
name|rtr_pref
decl_stmt|;
define|#
directive|define
name|IWARP_MPA_OFFLOAD_RAMROD_DATA_RTR_SUPPORTED_MASK
value|0x7
comment|/*  (use enum mpa_rtr_type) */
define|#
directive|define
name|IWARP_MPA_OFFLOAD_RAMROD_DATA_RTR_SUPPORTED_SHIFT
value|0
define|#
directive|define
name|IWARP_MPA_OFFLOAD_RAMROD_DATA_RESERVED1_MASK
value|0x1F
define|#
directive|define
name|IWARP_MPA_OFFLOAD_RAMROD_DATA_RESERVED1_SHIFT
value|3
name|u8
name|reserved2
decl_stmt|;
name|struct
name|mpa_ulp_buffer
name|incoming_ulp_buffer
comment|/* host buffer for placing the incoming MPA reply */
decl_stmt|;
name|struct
name|regpair
name|async_eqe_output_buf
comment|/* host buffer for async tcp/mpa completion information - must have space for at least 8 bytes */
decl_stmt|;
name|struct
name|regpair
name|handle_for_async
comment|/* a host cookie that will be echoed back with in every qp-specific async EQE */
decl_stmt|;
name|struct
name|regpair
name|shared_queue_addr
comment|/* Address of shared queue address that consist of SQ/RQ and FW internal queues (IRQ/ORQ/HQ) */
decl_stmt|;
name|u8
name|stats_counter_id
comment|/* Statistics counter ID to use */
decl_stmt|;
name|u8
name|reserved3
index|[
literal|15
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * iWARP TCP connection offload params passed by driver to FW   */
end_comment

begin_struct
struct|struct
name|iwarp_offload_params
block|{
name|struct
name|mpa_ulp_buffer
name|incoming_ulp_buffer
comment|/* host buffer for placing the incoming MPA request */
decl_stmt|;
name|struct
name|regpair
name|async_eqe_output_buf
comment|/* host buffer for async tcp/mpa completion information - must have space for at least 8 bytes */
decl_stmt|;
name|struct
name|regpair
name|handle_for_async
comment|/* host handle that will be echoed back with in every qp-specific async EQE */
decl_stmt|;
name|__le16
name|physical_q0
comment|/* Physical QM queue to be tied to logical Q0 */
decl_stmt|;
name|__le16
name|physical_q1
comment|/* Physical QM queue to be tied to logical Q1 */
decl_stmt|;
name|u8
name|stats_counter_id
comment|/* Statistics counter ID to use */
decl_stmt|;
name|u8
name|mpa_mode
comment|/* Basic/Enahnced. Used for a verification for incoming MPA request */
decl_stmt|;
name|u8
name|reserved
index|[
literal|10
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * iWARP query QP output params  */
end_comment

begin_struct
struct|struct
name|iwarp_query_qp_output_params
block|{
name|__le32
name|flags
decl_stmt|;
define|#
directive|define
name|IWARP_QUERY_QP_OUTPUT_PARAMS_ERROR_FLG_MASK
value|0x1
define|#
directive|define
name|IWARP_QUERY_QP_OUTPUT_PARAMS_ERROR_FLG_SHIFT
value|0
define|#
directive|define
name|IWARP_QUERY_QP_OUTPUT_PARAMS_RESERVED0_MASK
value|0x7FFFFFFF
define|#
directive|define
name|IWARP_QUERY_QP_OUTPUT_PARAMS_RESERVED0_SHIFT
value|1
name|u8
name|reserved1
index|[
literal|4
index|]
comment|/* 64 bit alignment */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * iWARP query QP ramrod data  */
end_comment

begin_struct
struct|struct
name|iwarp_query_qp_ramrod_data
block|{
name|struct
name|regpair
name|output_params_addr
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * iWARP Ramrod Command IDs   */
end_comment

begin_enum
enum|enum
name|iwarp_ramrod_cmd_id
block|{
name|IWARP_RAMROD_CMD_ID_TCP_OFFLOAD
init|=
literal|11
comment|/* iWARP TCP connection offload ramrod */
block|,
name|IWARP_RAMROD_CMD_ID_TCP_ABORT
comment|/* Abort TCP connection without changing the QP state. */
block|,
name|IWARP_RAMROD_CMD_ID_MPA_OFFLOAD
comment|/* iWARP MPA offload ramrod */
block|,
name|IWARP_RAMROD_CMD_ID_MPA_OFFLOAD_SEND_RTR
block|,
name|IWARP_RAMROD_CMD_ID_CREATE_QP
block|,
name|IWARP_RAMROD_CMD_ID_QUERY_QP
block|,
name|IWARP_RAMROD_CMD_ID_MODIFY_QP
block|,
name|IWARP_RAMROD_CMD_ID_DESTROY_QP
block|,
name|MAX_IWARP_RAMROD_CMD_ID
block|}
enum|;
end_enum

begin_comment
comment|/*  * Per PF iWARP retransmit path statistics  */
end_comment

begin_struct
struct|struct
name|iwarp_rxmit_stats_drv
block|{
name|struct
name|regpair
name|tx_go_to_slow_start_event_cnt
comment|/* Number of times slow start event occurred */
decl_stmt|;
name|struct
name|regpair
name|tx_fast_retransmit_event_cnt
comment|/* Number of times fast retransmit event occurred */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * iWARP and TCP connection offload params passed by driver to FW in iWARP offload ramrod   */
end_comment

begin_struct
struct|struct
name|iwarp_tcp_offload_ramrod_data
block|{
name|struct
name|iwarp_offload_params
name|iwarp
comment|/* iWARP connection offload params */
decl_stmt|;
name|struct
name|tcp_offload_params_opt2
name|tcp
comment|/* tcp offload params */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * iWARP MPA negotiation types  */
end_comment

begin_enum
enum|enum
name|mpa_negotiation_mode
block|{
name|MPA_NEGOTIATION_TYPE_BASIC
init|=
literal|1
block|,
name|MPA_NEGOTIATION_TYPE_ENHANCED
init|=
literal|2
block|,
name|MAX_MPA_NEGOTIATION_MODE
block|}
enum|;
end_enum

begin_comment
comment|/*  * iWARP MPA Enhanced mode RTR types  */
end_comment

begin_enum
enum|enum
name|mpa_rtr_type
block|{
name|MPA_RTR_TYPE_NONE
init|=
literal|0
comment|/* No RTR type */
block|,
name|MPA_RTR_TYPE_ZERO_SEND
init|=
literal|1
block|,
name|MPA_RTR_TYPE_ZERO_WRITE
init|=
literal|2
block|,
name|MPA_RTR_TYPE_ZERO_SEND_AND_WRITE
init|=
literal|3
block|,
name|MPA_RTR_TYPE_ZERO_READ
init|=
literal|4
block|,
name|MPA_RTR_TYPE_ZERO_SEND_AND_READ
init|=
literal|5
block|,
name|MPA_RTR_TYPE_ZERO_WRITE_AND_READ
init|=
literal|6
block|,
name|MPA_RTR_TYPE_ZERO_SEND_AND_WRITE_AND_READ
init|=
literal|7
block|,
name|MAX_MPA_RTR_TYPE
block|}
enum|;
end_enum

begin_comment
comment|/*  * unaligned opaque data received from LL2  */
end_comment

begin_struct
struct|struct
name|unaligned_opaque_data
block|{
name|__le16
name|first_mpa_offset
comment|/* offset of first MPA byte that should be processed */
decl_stmt|;
name|u8
name|tcp_payload_offset
comment|/* offset of first the byte that comes after the last byte of the TCP Hdr */
decl_stmt|;
name|u8
name|flags
decl_stmt|;
define|#
directive|define
name|UNALIGNED_OPAQUE_DATA_PKT_REACHED_WIN_RIGHT_EDGE_MASK
value|0x1
comment|/* packet reached window right edge */
define|#
directive|define
name|UNALIGNED_OPAQUE_DATA_PKT_REACHED_WIN_RIGHT_EDGE_SHIFT
value|0
define|#
directive|define
name|UNALIGNED_OPAQUE_DATA_RESERVED_MASK
value|0x7F
define|#
directive|define
name|UNALIGNED_OPAQUE_DATA_RESERVED_SHIFT
value|1
name|__le32
name|cid
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|e4_mstorm_iwarp_conn_ag_ctx
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
name|E4_MSTORM_IWARP_CONN_AG_CTX_EXIST_IN_QM0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E4_MSTORM_IWARP_CONN_AG_CTX_EXIST_IN_QM0_SHIFT
value|0
define|#
directive|define
name|E4_MSTORM_IWARP_CONN_AG_CTX_BIT1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E4_MSTORM_IWARP_CONN_AG_CTX_BIT1_SHIFT
value|1
define|#
directive|define
name|E4_MSTORM_IWARP_CONN_AG_CTX_INV_STAG_DONE_CF_MASK
value|0x3
comment|/* cf0 */
define|#
directive|define
name|E4_MSTORM_IWARP_CONN_AG_CTX_INV_STAG_DONE_CF_SHIFT
value|2
define|#
directive|define
name|E4_MSTORM_IWARP_CONN_AG_CTX_CF1_MASK
value|0x3
comment|/* cf1 */
define|#
directive|define
name|E4_MSTORM_IWARP_CONN_AG_CTX_CF1_SHIFT
value|4
define|#
directive|define
name|E4_MSTORM_IWARP_CONN_AG_CTX_CF2_MASK
value|0x3
comment|/* cf2 */
define|#
directive|define
name|E4_MSTORM_IWARP_CONN_AG_CTX_CF2_SHIFT
value|6
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E4_MSTORM_IWARP_CONN_AG_CTX_INV_STAG_DONE_CF_EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E4_MSTORM_IWARP_CONN_AG_CTX_INV_STAG_DONE_CF_EN_SHIFT
value|0
define|#
directive|define
name|E4_MSTORM_IWARP_CONN_AG_CTX_CF1EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E4_MSTORM_IWARP_CONN_AG_CTX_CF1EN_SHIFT
value|1
define|#
directive|define
name|E4_MSTORM_IWARP_CONN_AG_CTX_CF2EN_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E4_MSTORM_IWARP_CONN_AG_CTX_CF2EN_SHIFT
value|2
define|#
directive|define
name|E4_MSTORM_IWARP_CONN_AG_CTX_RULE0EN_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E4_MSTORM_IWARP_CONN_AG_CTX_RULE0EN_SHIFT
value|3
define|#
directive|define
name|E4_MSTORM_IWARP_CONN_AG_CTX_RULE1EN_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E4_MSTORM_IWARP_CONN_AG_CTX_RULE1EN_SHIFT
value|4
define|#
directive|define
name|E4_MSTORM_IWARP_CONN_AG_CTX_RULE2EN_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E4_MSTORM_IWARP_CONN_AG_CTX_RULE2EN_SHIFT
value|5
define|#
directive|define
name|E4_MSTORM_IWARP_CONN_AG_CTX_RCQ_CONS_EN_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E4_MSTORM_IWARP_CONN_AG_CTX_RCQ_CONS_EN_SHIFT
value|6
define|#
directive|define
name|E4_MSTORM_IWARP_CONN_AG_CTX_RULE4EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E4_MSTORM_IWARP_CONN_AG_CTX_RULE4EN_SHIFT
value|7
name|__le16
name|rcq_cons
comment|/* word0 */
decl_stmt|;
name|__le16
name|rcq_cons_th
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
name|e4_ustorm_iwarp_conn_ag_ctx
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
name|E4_USTORM_IWARP_CONN_AG_CTX_EXIST_IN_QM0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E4_USTORM_IWARP_CONN_AG_CTX_EXIST_IN_QM0_SHIFT
value|0
define|#
directive|define
name|E4_USTORM_IWARP_CONN_AG_CTX_BIT1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E4_USTORM_IWARP_CONN_AG_CTX_BIT1_SHIFT
value|1
define|#
directive|define
name|E4_USTORM_IWARP_CONN_AG_CTX_CF0_MASK
value|0x3
comment|/* timer0cf */
define|#
directive|define
name|E4_USTORM_IWARP_CONN_AG_CTX_CF0_SHIFT
value|2
define|#
directive|define
name|E4_USTORM_IWARP_CONN_AG_CTX_CF1_MASK
value|0x3
comment|/* timer1cf */
define|#
directive|define
name|E4_USTORM_IWARP_CONN_AG_CTX_CF1_SHIFT
value|4
define|#
directive|define
name|E4_USTORM_IWARP_CONN_AG_CTX_CF2_MASK
value|0x3
comment|/* timer2cf */
define|#
directive|define
name|E4_USTORM_IWARP_CONN_AG_CTX_CF2_SHIFT
value|6
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E4_USTORM_IWARP_CONN_AG_CTX_CF3_MASK
value|0x3
comment|/* timer_stop_all */
define|#
directive|define
name|E4_USTORM_IWARP_CONN_AG_CTX_CF3_SHIFT
value|0
define|#
directive|define
name|E4_USTORM_IWARP_CONN_AG_CTX_CQ_ARM_SE_CF_MASK
value|0x3
comment|/* cf4 */
define|#
directive|define
name|E4_USTORM_IWARP_CONN_AG_CTX_CQ_ARM_SE_CF_SHIFT
value|2
define|#
directive|define
name|E4_USTORM_IWARP_CONN_AG_CTX_CQ_ARM_CF_MASK
value|0x3
comment|/* cf5 */
define|#
directive|define
name|E4_USTORM_IWARP_CONN_AG_CTX_CQ_ARM_CF_SHIFT
value|4
define|#
directive|define
name|E4_USTORM_IWARP_CONN_AG_CTX_CF6_MASK
value|0x3
comment|/* cf6 */
define|#
directive|define
name|E4_USTORM_IWARP_CONN_AG_CTX_CF6_SHIFT
value|6
name|u8
name|flags2
decl_stmt|;
define|#
directive|define
name|E4_USTORM_IWARP_CONN_AG_CTX_CF0EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E4_USTORM_IWARP_CONN_AG_CTX_CF0EN_SHIFT
value|0
define|#
directive|define
name|E4_USTORM_IWARP_CONN_AG_CTX_CF1EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E4_USTORM_IWARP_CONN_AG_CTX_CF1EN_SHIFT
value|1
define|#
directive|define
name|E4_USTORM_IWARP_CONN_AG_CTX_CF2EN_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E4_USTORM_IWARP_CONN_AG_CTX_CF2EN_SHIFT
value|2
define|#
directive|define
name|E4_USTORM_IWARP_CONN_AG_CTX_CF3EN_MASK
value|0x1
comment|/* cf3en */
define|#
directive|define
name|E4_USTORM_IWARP_CONN_AG_CTX_CF3EN_SHIFT
value|3
define|#
directive|define
name|E4_USTORM_IWARP_CONN_AG_CTX_CQ_ARM_SE_CF_EN_MASK
value|0x1
comment|/* cf4en */
define|#
directive|define
name|E4_USTORM_IWARP_CONN_AG_CTX_CQ_ARM_SE_CF_EN_SHIFT
value|4
define|#
directive|define
name|E4_USTORM_IWARP_CONN_AG_CTX_CQ_ARM_CF_EN_MASK
value|0x1
comment|/* cf5en */
define|#
directive|define
name|E4_USTORM_IWARP_CONN_AG_CTX_CQ_ARM_CF_EN_SHIFT
value|5
define|#
directive|define
name|E4_USTORM_IWARP_CONN_AG_CTX_CF6EN_MASK
value|0x1
comment|/* cf6en */
define|#
directive|define
name|E4_USTORM_IWARP_CONN_AG_CTX_CF6EN_SHIFT
value|6
define|#
directive|define
name|E4_USTORM_IWARP_CONN_AG_CTX_CQ_SE_EN_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E4_USTORM_IWARP_CONN_AG_CTX_CQ_SE_EN_SHIFT
value|7
name|u8
name|flags3
decl_stmt|;
define|#
directive|define
name|E4_USTORM_IWARP_CONN_AG_CTX_CQ_EN_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E4_USTORM_IWARP_CONN_AG_CTX_CQ_EN_SHIFT
value|0
define|#
directive|define
name|E4_USTORM_IWARP_CONN_AG_CTX_RULE2EN_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E4_USTORM_IWARP_CONN_AG_CTX_RULE2EN_SHIFT
value|1
define|#
directive|define
name|E4_USTORM_IWARP_CONN_AG_CTX_RULE3EN_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E4_USTORM_IWARP_CONN_AG_CTX_RULE3EN_SHIFT
value|2
define|#
directive|define
name|E4_USTORM_IWARP_CONN_AG_CTX_RULE4EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E4_USTORM_IWARP_CONN_AG_CTX_RULE4EN_SHIFT
value|3
define|#
directive|define
name|E4_USTORM_IWARP_CONN_AG_CTX_RULE5EN_MASK
value|0x1
comment|/* rule5en */
define|#
directive|define
name|E4_USTORM_IWARP_CONN_AG_CTX_RULE5EN_SHIFT
value|4
define|#
directive|define
name|E4_USTORM_IWARP_CONN_AG_CTX_RULE6EN_MASK
value|0x1
comment|/* rule6en */
define|#
directive|define
name|E4_USTORM_IWARP_CONN_AG_CTX_RULE6EN_SHIFT
value|5
define|#
directive|define
name|E4_USTORM_IWARP_CONN_AG_CTX_RULE7EN_MASK
value|0x1
comment|/* rule7en */
define|#
directive|define
name|E4_USTORM_IWARP_CONN_AG_CTX_RULE7EN_SHIFT
value|6
define|#
directive|define
name|E4_USTORM_IWARP_CONN_AG_CTX_RULE8EN_MASK
value|0x1
comment|/* rule8en */
define|#
directive|define
name|E4_USTORM_IWARP_CONN_AG_CTX_RULE8EN_SHIFT
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
name|e4_ystorm_iwarp_conn_ag_ctx
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
name|E4_YSTORM_IWARP_CONN_AG_CTX_BIT0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E4_YSTORM_IWARP_CONN_AG_CTX_BIT0_SHIFT
value|0
define|#
directive|define
name|E4_YSTORM_IWARP_CONN_AG_CTX_BIT1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E4_YSTORM_IWARP_CONN_AG_CTX_BIT1_SHIFT
value|1
define|#
directive|define
name|E4_YSTORM_IWARP_CONN_AG_CTX_CF0_MASK
value|0x3
comment|/* cf0 */
define|#
directive|define
name|E4_YSTORM_IWARP_CONN_AG_CTX_CF0_SHIFT
value|2
define|#
directive|define
name|E4_YSTORM_IWARP_CONN_AG_CTX_CF1_MASK
value|0x3
comment|/* cf1 */
define|#
directive|define
name|E4_YSTORM_IWARP_CONN_AG_CTX_CF1_SHIFT
value|4
define|#
directive|define
name|E4_YSTORM_IWARP_CONN_AG_CTX_CF2_MASK
value|0x3
comment|/* cf2 */
define|#
directive|define
name|E4_YSTORM_IWARP_CONN_AG_CTX_CF2_SHIFT
value|6
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E4_YSTORM_IWARP_CONN_AG_CTX_CF0EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E4_YSTORM_IWARP_CONN_AG_CTX_CF0EN_SHIFT
value|0
define|#
directive|define
name|E4_YSTORM_IWARP_CONN_AG_CTX_CF1EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E4_YSTORM_IWARP_CONN_AG_CTX_CF1EN_SHIFT
value|1
define|#
directive|define
name|E4_YSTORM_IWARP_CONN_AG_CTX_CF2EN_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E4_YSTORM_IWARP_CONN_AG_CTX_CF2EN_SHIFT
value|2
define|#
directive|define
name|E4_YSTORM_IWARP_CONN_AG_CTX_RULE0EN_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E4_YSTORM_IWARP_CONN_AG_CTX_RULE0EN_SHIFT
value|3
define|#
directive|define
name|E4_YSTORM_IWARP_CONN_AG_CTX_RULE1EN_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E4_YSTORM_IWARP_CONN_AG_CTX_RULE1EN_SHIFT
value|4
define|#
directive|define
name|E4_YSTORM_IWARP_CONN_AG_CTX_RULE2EN_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E4_YSTORM_IWARP_CONN_AG_CTX_RULE2EN_SHIFT
value|5
define|#
directive|define
name|E4_YSTORM_IWARP_CONN_AG_CTX_RULE3EN_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E4_YSTORM_IWARP_CONN_AG_CTX_RULE3EN_SHIFT
value|6
define|#
directive|define
name|E4_YSTORM_IWARP_CONN_AG_CTX_RULE4EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E4_YSTORM_IWARP_CONN_AG_CTX_RULE4EN_SHIFT
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
name|e5_mstorm_iwarp_conn_ag_ctx
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
name|E5_MSTORM_IWARP_CONN_AG_CTX_EXIST_IN_QM0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E5_MSTORM_IWARP_CONN_AG_CTX_EXIST_IN_QM0_SHIFT
value|0
define|#
directive|define
name|E5_MSTORM_IWARP_CONN_AG_CTX_BIT1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E5_MSTORM_IWARP_CONN_AG_CTX_BIT1_SHIFT
value|1
define|#
directive|define
name|E5_MSTORM_IWARP_CONN_AG_CTX_INV_STAG_DONE_CF_MASK
value|0x3
comment|/* cf0 */
define|#
directive|define
name|E5_MSTORM_IWARP_CONN_AG_CTX_INV_STAG_DONE_CF_SHIFT
value|2
define|#
directive|define
name|E5_MSTORM_IWARP_CONN_AG_CTX_CF1_MASK
value|0x3
comment|/* cf1 */
define|#
directive|define
name|E5_MSTORM_IWARP_CONN_AG_CTX_CF1_SHIFT
value|4
define|#
directive|define
name|E5_MSTORM_IWARP_CONN_AG_CTX_CF2_MASK
value|0x3
comment|/* cf2 */
define|#
directive|define
name|E5_MSTORM_IWARP_CONN_AG_CTX_CF2_SHIFT
value|6
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E5_MSTORM_IWARP_CONN_AG_CTX_INV_STAG_DONE_CF_EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E5_MSTORM_IWARP_CONN_AG_CTX_INV_STAG_DONE_CF_EN_SHIFT
value|0
define|#
directive|define
name|E5_MSTORM_IWARP_CONN_AG_CTX_CF1EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E5_MSTORM_IWARP_CONN_AG_CTX_CF1EN_SHIFT
value|1
define|#
directive|define
name|E5_MSTORM_IWARP_CONN_AG_CTX_CF2EN_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E5_MSTORM_IWARP_CONN_AG_CTX_CF2EN_SHIFT
value|2
define|#
directive|define
name|E5_MSTORM_IWARP_CONN_AG_CTX_RULE0EN_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E5_MSTORM_IWARP_CONN_AG_CTX_RULE0EN_SHIFT
value|3
define|#
directive|define
name|E5_MSTORM_IWARP_CONN_AG_CTX_RULE1EN_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E5_MSTORM_IWARP_CONN_AG_CTX_RULE1EN_SHIFT
value|4
define|#
directive|define
name|E5_MSTORM_IWARP_CONN_AG_CTX_RULE2EN_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E5_MSTORM_IWARP_CONN_AG_CTX_RULE2EN_SHIFT
value|5
define|#
directive|define
name|E5_MSTORM_IWARP_CONN_AG_CTX_RCQ_CONS_EN_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E5_MSTORM_IWARP_CONN_AG_CTX_RCQ_CONS_EN_SHIFT
value|6
define|#
directive|define
name|E5_MSTORM_IWARP_CONN_AG_CTX_RULE4EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E5_MSTORM_IWARP_CONN_AG_CTX_RULE4EN_SHIFT
value|7
name|__le16
name|rcq_cons
comment|/* word0 */
decl_stmt|;
name|__le16
name|rcq_cons_th
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
name|e5_tstorm_iwarp_conn_ag_ctx
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
name|E5_TSTORM_IWARP_CONN_AG_CTX_EXIST_IN_QM0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E5_TSTORM_IWARP_CONN_AG_CTX_EXIST_IN_QM0_SHIFT
value|0
define|#
directive|define
name|E5_TSTORM_IWARP_CONN_AG_CTX_BIT1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E5_TSTORM_IWARP_CONN_AG_CTX_BIT1_SHIFT
value|1
define|#
directive|define
name|E5_TSTORM_IWARP_CONN_AG_CTX_BIT2_MASK
value|0x1
comment|/* bit2 */
define|#
directive|define
name|E5_TSTORM_IWARP_CONN_AG_CTX_BIT2_SHIFT
value|2
define|#
directive|define
name|E5_TSTORM_IWARP_CONN_AG_CTX_MSTORM_FLUSH_MASK
value|0x1
comment|/* bit3 */
define|#
directive|define
name|E5_TSTORM_IWARP_CONN_AG_CTX_MSTORM_FLUSH_SHIFT
value|3
define|#
directive|define
name|E5_TSTORM_IWARP_CONN_AG_CTX_BIT4_MASK
value|0x1
comment|/* bit4 */
define|#
directive|define
name|E5_TSTORM_IWARP_CONN_AG_CTX_BIT4_SHIFT
value|4
define|#
directive|define
name|E5_TSTORM_IWARP_CONN_AG_CTX_CACHED_ORQ_MASK
value|0x1
comment|/* bit5 */
define|#
directive|define
name|E5_TSTORM_IWARP_CONN_AG_CTX_CACHED_ORQ_SHIFT
value|5
define|#
directive|define
name|E5_TSTORM_IWARP_CONN_AG_CTX_CF0_MASK
value|0x3
comment|/* timer0cf */
define|#
directive|define
name|E5_TSTORM_IWARP_CONN_AG_CTX_CF0_SHIFT
value|6
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E5_TSTORM_IWARP_CONN_AG_CTX_RQ_POST_CF_MASK
value|0x3
comment|/* timer1cf */
define|#
directive|define
name|E5_TSTORM_IWARP_CONN_AG_CTX_RQ_POST_CF_SHIFT
value|0
define|#
directive|define
name|E5_TSTORM_IWARP_CONN_AG_CTX_FLUSH_OR_ERROR_DETECTED_MASK
value|0x3
comment|/* timer2cf */
define|#
directive|define
name|E5_TSTORM_IWARP_CONN_AG_CTX_FLUSH_OR_ERROR_DETECTED_SHIFT
value|2
define|#
directive|define
name|E5_TSTORM_IWARP_CONN_AG_CTX_TIMER_STOP_ALL_MASK
value|0x3
comment|/* timer_stop_all */
define|#
directive|define
name|E5_TSTORM_IWARP_CONN_AG_CTX_TIMER_STOP_ALL_SHIFT
value|4
define|#
directive|define
name|E5_TSTORM_IWARP_CONN_AG_CTX_CF4_MASK
value|0x3
comment|/* cf4 */
define|#
directive|define
name|E5_TSTORM_IWARP_CONN_AG_CTX_CF4_SHIFT
value|6
name|u8
name|flags2
decl_stmt|;
define|#
directive|define
name|E5_TSTORM_IWARP_CONN_AG_CTX_CF5_MASK
value|0x3
comment|/* cf5 */
define|#
directive|define
name|E5_TSTORM_IWARP_CONN_AG_CTX_CF5_SHIFT
value|0
define|#
directive|define
name|E5_TSTORM_IWARP_CONN_AG_CTX_CF6_MASK
value|0x3
comment|/* cf6 */
define|#
directive|define
name|E5_TSTORM_IWARP_CONN_AG_CTX_CF6_SHIFT
value|2
define|#
directive|define
name|E5_TSTORM_IWARP_CONN_AG_CTX_CF7_MASK
value|0x3
comment|/* cf7 */
define|#
directive|define
name|E5_TSTORM_IWARP_CONN_AG_CTX_CF7_SHIFT
value|4
define|#
directive|define
name|E5_TSTORM_IWARP_CONN_AG_CTX_CF8_MASK
value|0x3
comment|/* cf8 */
define|#
directive|define
name|E5_TSTORM_IWARP_CONN_AG_CTX_CF8_SHIFT
value|6
name|u8
name|flags3
decl_stmt|;
define|#
directive|define
name|E5_TSTORM_IWARP_CONN_AG_CTX_FLUSH_Q0_MASK
value|0x3
comment|/* cf9 */
define|#
directive|define
name|E5_TSTORM_IWARP_CONN_AG_CTX_FLUSH_Q0_SHIFT
value|0
define|#
directive|define
name|E5_TSTORM_IWARP_CONN_AG_CTX_CF10_MASK
value|0x3
comment|/* cf10 */
define|#
directive|define
name|E5_TSTORM_IWARP_CONN_AG_CTX_CF10_SHIFT
value|2
define|#
directive|define
name|E5_TSTORM_IWARP_CONN_AG_CTX_CF0EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E5_TSTORM_IWARP_CONN_AG_CTX_CF0EN_SHIFT
value|4
define|#
directive|define
name|E5_TSTORM_IWARP_CONN_AG_CTX_RQ_POST_CF_EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E5_TSTORM_IWARP_CONN_AG_CTX_RQ_POST_CF_EN_SHIFT
value|5
define|#
directive|define
name|E5_TSTORM_IWARP_CONN_AG_CTX_FLUSH_OR_ERROR_DETECTED_EN_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E5_TSTORM_IWARP_CONN_AG_CTX_FLUSH_OR_ERROR_DETECTED_EN_SHIFT
value|6
define|#
directive|define
name|E5_TSTORM_IWARP_CONN_AG_CTX_TIMER_STOP_ALL_EN_MASK
value|0x1
comment|/* cf3en */
define|#
directive|define
name|E5_TSTORM_IWARP_CONN_AG_CTX_TIMER_STOP_ALL_EN_SHIFT
value|7
name|u8
name|flags4
decl_stmt|;
define|#
directive|define
name|E5_TSTORM_IWARP_CONN_AG_CTX_CF4EN_MASK
value|0x1
comment|/* cf4en */
define|#
directive|define
name|E5_TSTORM_IWARP_CONN_AG_CTX_CF4EN_SHIFT
value|0
define|#
directive|define
name|E5_TSTORM_IWARP_CONN_AG_CTX_CF5EN_MASK
value|0x1
comment|/* cf5en */
define|#
directive|define
name|E5_TSTORM_IWARP_CONN_AG_CTX_CF5EN_SHIFT
value|1
define|#
directive|define
name|E5_TSTORM_IWARP_CONN_AG_CTX_CF6EN_MASK
value|0x1
comment|/* cf6en */
define|#
directive|define
name|E5_TSTORM_IWARP_CONN_AG_CTX_CF6EN_SHIFT
value|2
define|#
directive|define
name|E5_TSTORM_IWARP_CONN_AG_CTX_CF7EN_MASK
value|0x1
comment|/* cf7en */
define|#
directive|define
name|E5_TSTORM_IWARP_CONN_AG_CTX_CF7EN_SHIFT
value|3
define|#
directive|define
name|E5_TSTORM_IWARP_CONN_AG_CTX_CF8EN_MASK
value|0x1
comment|/* cf8en */
define|#
directive|define
name|E5_TSTORM_IWARP_CONN_AG_CTX_CF8EN_SHIFT
value|4
define|#
directive|define
name|E5_TSTORM_IWARP_CONN_AG_CTX_FLUSH_Q0_EN_MASK
value|0x1
comment|/* cf9en */
define|#
directive|define
name|E5_TSTORM_IWARP_CONN_AG_CTX_FLUSH_Q0_EN_SHIFT
value|5
define|#
directive|define
name|E5_TSTORM_IWARP_CONN_AG_CTX_CF10EN_MASK
value|0x1
comment|/* cf10en */
define|#
directive|define
name|E5_TSTORM_IWARP_CONN_AG_CTX_CF10EN_SHIFT
value|6
define|#
directive|define
name|E5_TSTORM_IWARP_CONN_AG_CTX_RULE0EN_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E5_TSTORM_IWARP_CONN_AG_CTX_RULE0EN_SHIFT
value|7
name|u8
name|flags5
decl_stmt|;
define|#
directive|define
name|E5_TSTORM_IWARP_CONN_AG_CTX_RULE1EN_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E5_TSTORM_IWARP_CONN_AG_CTX_RULE1EN_SHIFT
value|0
define|#
directive|define
name|E5_TSTORM_IWARP_CONN_AG_CTX_RULE2EN_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E5_TSTORM_IWARP_CONN_AG_CTX_RULE2EN_SHIFT
value|1
define|#
directive|define
name|E5_TSTORM_IWARP_CONN_AG_CTX_RULE3EN_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E5_TSTORM_IWARP_CONN_AG_CTX_RULE3EN_SHIFT
value|2
define|#
directive|define
name|E5_TSTORM_IWARP_CONN_AG_CTX_RULE4EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E5_TSTORM_IWARP_CONN_AG_CTX_RULE4EN_SHIFT
value|3
define|#
directive|define
name|E5_TSTORM_IWARP_CONN_AG_CTX_RULE5EN_MASK
value|0x1
comment|/* rule5en */
define|#
directive|define
name|E5_TSTORM_IWARP_CONN_AG_CTX_RULE5EN_SHIFT
value|4
define|#
directive|define
name|E5_TSTORM_IWARP_CONN_AG_CTX_SND_SQ_CONS_RULE_MASK
value|0x1
comment|/* rule6en */
define|#
directive|define
name|E5_TSTORM_IWARP_CONN_AG_CTX_SND_SQ_CONS_RULE_SHIFT
value|5
define|#
directive|define
name|E5_TSTORM_IWARP_CONN_AG_CTX_RULE7EN_MASK
value|0x1
comment|/* rule7en */
define|#
directive|define
name|E5_TSTORM_IWARP_CONN_AG_CTX_RULE7EN_SHIFT
value|6
define|#
directive|define
name|E5_TSTORM_IWARP_CONN_AG_CTX_RULE8EN_MASK
value|0x1
comment|/* rule8en */
define|#
directive|define
name|E5_TSTORM_IWARP_CONN_AG_CTX_RULE8EN_SHIFT
value|7
name|u8
name|flags6
decl_stmt|;
define|#
directive|define
name|E5_TSTORM_IWARP_CONN_AG_CTX_E4_RESERVED1_MASK
value|0x1
comment|/* bit6 */
define|#
directive|define
name|E5_TSTORM_IWARP_CONN_AG_CTX_E4_RESERVED1_SHIFT
value|0
define|#
directive|define
name|E5_TSTORM_IWARP_CONN_AG_CTX_E4_RESERVED2_MASK
value|0x1
comment|/* bit7 */
define|#
directive|define
name|E5_TSTORM_IWARP_CONN_AG_CTX_E4_RESERVED2_SHIFT
value|1
define|#
directive|define
name|E5_TSTORM_IWARP_CONN_AG_CTX_E4_RESERVED3_MASK
value|0x1
comment|/* bit8 */
define|#
directive|define
name|E5_TSTORM_IWARP_CONN_AG_CTX_E4_RESERVED3_SHIFT
value|2
define|#
directive|define
name|E5_TSTORM_IWARP_CONN_AG_CTX_E4_RESERVED4_MASK
value|0x3
comment|/* cf11 */
define|#
directive|define
name|E5_TSTORM_IWARP_CONN_AG_CTX_E4_RESERVED4_SHIFT
value|3
define|#
directive|define
name|E5_TSTORM_IWARP_CONN_AG_CTX_E4_RESERVED5_MASK
value|0x1
comment|/* cf11en */
define|#
directive|define
name|E5_TSTORM_IWARP_CONN_AG_CTX_E4_RESERVED5_SHIFT
value|5
define|#
directive|define
name|E5_TSTORM_IWARP_CONN_AG_CTX_E4_RESERVED6_MASK
value|0x1
comment|/* rule9en */
define|#
directive|define
name|E5_TSTORM_IWARP_CONN_AG_CTX_E4_RESERVED6_SHIFT
value|6
define|#
directive|define
name|E5_TSTORM_IWARP_CONN_AG_CTX_E4_RESERVED7_MASK
value|0x1
comment|/* rule10en */
define|#
directive|define
name|E5_TSTORM_IWARP_CONN_AG_CTX_E4_RESERVED7_SHIFT
value|7
name|u8
name|orq_cache_idx
comment|/* byte2 */
decl_stmt|;
name|__le16
name|sq_tx_cons_th
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
name|unaligned_nxt_seq
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
name|hq_prod
comment|/* byte3 */
decl_stmt|;
name|u8
name|orq_prod
comment|/* byte4 */
decl_stmt|;
name|u8
name|irq_cons
comment|/* byte5 */
decl_stmt|;
name|u8
name|e4_reserved8
comment|/* byte6 */
decl_stmt|;
name|__le16
name|sq_tx_cons
comment|/* word1 */
decl_stmt|;
name|__le16
name|conn_dpi
comment|/* conn_dpi */
decl_stmt|;
name|__le32
name|snd_seq
comment|/* reg9 */
decl_stmt|;
name|__le16
name|rq_prod
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
name|e5_ustorm_iwarp_conn_ag_ctx
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
name|E5_USTORM_IWARP_CONN_AG_CTX_EXIST_IN_QM0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E5_USTORM_IWARP_CONN_AG_CTX_EXIST_IN_QM0_SHIFT
value|0
define|#
directive|define
name|E5_USTORM_IWARP_CONN_AG_CTX_BIT1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E5_USTORM_IWARP_CONN_AG_CTX_BIT1_SHIFT
value|1
define|#
directive|define
name|E5_USTORM_IWARP_CONN_AG_CTX_CF0_MASK
value|0x3
comment|/* timer0cf */
define|#
directive|define
name|E5_USTORM_IWARP_CONN_AG_CTX_CF0_SHIFT
value|2
define|#
directive|define
name|E5_USTORM_IWARP_CONN_AG_CTX_CF1_MASK
value|0x3
comment|/* timer1cf */
define|#
directive|define
name|E5_USTORM_IWARP_CONN_AG_CTX_CF1_SHIFT
value|4
define|#
directive|define
name|E5_USTORM_IWARP_CONN_AG_CTX_CF2_MASK
value|0x3
comment|/* timer2cf */
define|#
directive|define
name|E5_USTORM_IWARP_CONN_AG_CTX_CF2_SHIFT
value|6
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E5_USTORM_IWARP_CONN_AG_CTX_CF3_MASK
value|0x3
comment|/* timer_stop_all */
define|#
directive|define
name|E5_USTORM_IWARP_CONN_AG_CTX_CF3_SHIFT
value|0
define|#
directive|define
name|E5_USTORM_IWARP_CONN_AG_CTX_CQ_ARM_SE_CF_MASK
value|0x3
comment|/* cf4 */
define|#
directive|define
name|E5_USTORM_IWARP_CONN_AG_CTX_CQ_ARM_SE_CF_SHIFT
value|2
define|#
directive|define
name|E5_USTORM_IWARP_CONN_AG_CTX_CQ_ARM_CF_MASK
value|0x3
comment|/* cf5 */
define|#
directive|define
name|E5_USTORM_IWARP_CONN_AG_CTX_CQ_ARM_CF_SHIFT
value|4
define|#
directive|define
name|E5_USTORM_IWARP_CONN_AG_CTX_CF6_MASK
value|0x3
comment|/* cf6 */
define|#
directive|define
name|E5_USTORM_IWARP_CONN_AG_CTX_CF6_SHIFT
value|6
name|u8
name|flags2
decl_stmt|;
define|#
directive|define
name|E5_USTORM_IWARP_CONN_AG_CTX_CF0EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E5_USTORM_IWARP_CONN_AG_CTX_CF0EN_SHIFT
value|0
define|#
directive|define
name|E5_USTORM_IWARP_CONN_AG_CTX_CF1EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E5_USTORM_IWARP_CONN_AG_CTX_CF1EN_SHIFT
value|1
define|#
directive|define
name|E5_USTORM_IWARP_CONN_AG_CTX_CF2EN_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E5_USTORM_IWARP_CONN_AG_CTX_CF2EN_SHIFT
value|2
define|#
directive|define
name|E5_USTORM_IWARP_CONN_AG_CTX_CF3EN_MASK
value|0x1
comment|/* cf3en */
define|#
directive|define
name|E5_USTORM_IWARP_CONN_AG_CTX_CF3EN_SHIFT
value|3
define|#
directive|define
name|E5_USTORM_IWARP_CONN_AG_CTX_CQ_ARM_SE_CF_EN_MASK
value|0x1
comment|/* cf4en */
define|#
directive|define
name|E5_USTORM_IWARP_CONN_AG_CTX_CQ_ARM_SE_CF_EN_SHIFT
value|4
define|#
directive|define
name|E5_USTORM_IWARP_CONN_AG_CTX_CQ_ARM_CF_EN_MASK
value|0x1
comment|/* cf5en */
define|#
directive|define
name|E5_USTORM_IWARP_CONN_AG_CTX_CQ_ARM_CF_EN_SHIFT
value|5
define|#
directive|define
name|E5_USTORM_IWARP_CONN_AG_CTX_CF6EN_MASK
value|0x1
comment|/* cf6en */
define|#
directive|define
name|E5_USTORM_IWARP_CONN_AG_CTX_CF6EN_SHIFT
value|6
define|#
directive|define
name|E5_USTORM_IWARP_CONN_AG_CTX_CQ_SE_EN_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E5_USTORM_IWARP_CONN_AG_CTX_CQ_SE_EN_SHIFT
value|7
name|u8
name|flags3
decl_stmt|;
define|#
directive|define
name|E5_USTORM_IWARP_CONN_AG_CTX_CQ_EN_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E5_USTORM_IWARP_CONN_AG_CTX_CQ_EN_SHIFT
value|0
define|#
directive|define
name|E5_USTORM_IWARP_CONN_AG_CTX_RULE2EN_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E5_USTORM_IWARP_CONN_AG_CTX_RULE2EN_SHIFT
value|1
define|#
directive|define
name|E5_USTORM_IWARP_CONN_AG_CTX_RULE3EN_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E5_USTORM_IWARP_CONN_AG_CTX_RULE3EN_SHIFT
value|2
define|#
directive|define
name|E5_USTORM_IWARP_CONN_AG_CTX_RULE4EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E5_USTORM_IWARP_CONN_AG_CTX_RULE4EN_SHIFT
value|3
define|#
directive|define
name|E5_USTORM_IWARP_CONN_AG_CTX_RULE5EN_MASK
value|0x1
comment|/* rule5en */
define|#
directive|define
name|E5_USTORM_IWARP_CONN_AG_CTX_RULE5EN_SHIFT
value|4
define|#
directive|define
name|E5_USTORM_IWARP_CONN_AG_CTX_RULE6EN_MASK
value|0x1
comment|/* rule6en */
define|#
directive|define
name|E5_USTORM_IWARP_CONN_AG_CTX_RULE6EN_SHIFT
value|5
define|#
directive|define
name|E5_USTORM_IWARP_CONN_AG_CTX_RULE7EN_MASK
value|0x1
comment|/* rule7en */
define|#
directive|define
name|E5_USTORM_IWARP_CONN_AG_CTX_RULE7EN_SHIFT
value|6
define|#
directive|define
name|E5_USTORM_IWARP_CONN_AG_CTX_RULE8EN_MASK
value|0x1
comment|/* rule8en */
define|#
directive|define
name|E5_USTORM_IWARP_CONN_AG_CTX_RULE8EN_SHIFT
value|7
name|u8
name|flags4
decl_stmt|;
define|#
directive|define
name|E5_USTORM_IWARP_CONN_AG_CTX_E4_RESERVED1_MASK
value|0x1
comment|/* bit2 */
define|#
directive|define
name|E5_USTORM_IWARP_CONN_AG_CTX_E4_RESERVED1_SHIFT
value|0
define|#
directive|define
name|E5_USTORM_IWARP_CONN_AG_CTX_E4_RESERVED2_MASK
value|0x1
comment|/* bit3 */
define|#
directive|define
name|E5_USTORM_IWARP_CONN_AG_CTX_E4_RESERVED2_SHIFT
value|1
define|#
directive|define
name|E5_USTORM_IWARP_CONN_AG_CTX_E4_RESERVED3_MASK
value|0x3
comment|/* cf7 */
define|#
directive|define
name|E5_USTORM_IWARP_CONN_AG_CTX_E4_RESERVED3_SHIFT
value|2
define|#
directive|define
name|E5_USTORM_IWARP_CONN_AG_CTX_E4_RESERVED4_MASK
value|0x3
comment|/* cf8 */
define|#
directive|define
name|E5_USTORM_IWARP_CONN_AG_CTX_E4_RESERVED4_SHIFT
value|4
define|#
directive|define
name|E5_USTORM_IWARP_CONN_AG_CTX_E4_RESERVED5_MASK
value|0x1
comment|/* cf7en */
define|#
directive|define
name|E5_USTORM_IWARP_CONN_AG_CTX_E4_RESERVED5_SHIFT
value|6
define|#
directive|define
name|E5_USTORM_IWARP_CONN_AG_CTX_E4_RESERVED6_MASK
value|0x1
comment|/* cf8en */
define|#
directive|define
name|E5_USTORM_IWARP_CONN_AG_CTX_E4_RESERVED6_SHIFT
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
name|e5_xstorm_iwarp_conn_ag_ctx
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
name|E5_XSTORM_IWARP_CONN_AG_CTX_EXIST_IN_QM0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_EXIST_IN_QM0_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_EXIST_IN_QM1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_EXIST_IN_QM1_SHIFT
value|1
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_RESERVED1_MASK
value|0x1
comment|/* exist_in_qm2 */
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_RESERVED1_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_EXIST_IN_QM3_MASK
value|0x1
comment|/* exist_in_qm3 */
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_EXIST_IN_QM3_SHIFT
value|3
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_BIT4_MASK
value|0x1
comment|/* bit4 */
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_BIT4_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_RESERVED2_MASK
value|0x1
comment|/* cf_array_active */
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_RESERVED2_SHIFT
value|5
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_BIT6_MASK
value|0x1
comment|/* bit6 */
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_BIT6_SHIFT
value|6
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_BIT7_MASK
value|0x1
comment|/* bit7 */
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_BIT7_SHIFT
value|7
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_BIT8_MASK
value|0x1
comment|/* bit8 */
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_BIT8_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_BIT9_MASK
value|0x1
comment|/* bit9 */
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_BIT9_SHIFT
value|1
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_BIT10_MASK
value|0x1
comment|/* bit10 */
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_BIT10_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_BIT11_MASK
value|0x1
comment|/* bit11 */
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_BIT11_SHIFT
value|3
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_BIT12_MASK
value|0x1
comment|/* bit12 */
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_BIT12_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_BIT13_MASK
value|0x1
comment|/* bit13 */
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_BIT13_SHIFT
value|5
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_BIT14_MASK
value|0x1
comment|/* bit14 */
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_BIT14_SHIFT
value|6
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_YSTORM_FLUSH_OR_REWIND_SND_MAX_MASK
value|0x1
comment|/* bit15 */
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_YSTORM_FLUSH_OR_REWIND_SND_MAX_SHIFT
value|7
name|u8
name|flags2
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_CF0_MASK
value|0x3
comment|/* timer0cf */
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_CF0_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_CF1_MASK
value|0x3
comment|/* timer1cf */
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_CF1_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_CF2_MASK
value|0x3
comment|/* timer2cf */
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_CF2_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_TIMER_STOP_ALL_MASK
value|0x3
comment|/* timer_stop_all */
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_TIMER_STOP_ALL_SHIFT
value|6
name|u8
name|flags3
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_CF4_MASK
value|0x3
comment|/* cf4 */
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_CF4_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_CF5_MASK
value|0x3
comment|/* cf5 */
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_CF5_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_CF6_MASK
value|0x3
comment|/* cf6 */
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_CF6_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_CF7_MASK
value|0x3
comment|/* cf7 */
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_CF7_SHIFT
value|6
name|u8
name|flags4
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_CF8_MASK
value|0x3
comment|/* cf8 */
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_CF8_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_CF9_MASK
value|0x3
comment|/* cf9 */
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_CF9_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_CF10_MASK
value|0x3
comment|/* cf10 */
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_CF10_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_CF11_MASK
value|0x3
comment|/* cf11 */
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_CF11_SHIFT
value|6
name|u8
name|flags5
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_CF12_MASK
value|0x3
comment|/* cf12 */
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_CF12_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_CF13_MASK
value|0x3
comment|/* cf13 */
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_CF13_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_SQ_FLUSH_CF_MASK
value|0x3
comment|/* cf14 */
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_SQ_FLUSH_CF_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_CF15_MASK
value|0x3
comment|/* cf15 */
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_CF15_SHIFT
value|6
name|u8
name|flags6
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_MPA_OR_ERROR_WAKEUP_TRIGGER_CF_MASK
value|0x3
comment|/* cf16 */
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_MPA_OR_ERROR_WAKEUP_TRIGGER_CF_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_CF17_MASK
value|0x3
comment|/* cf_array_cf */
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_CF17_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_CF18_MASK
value|0x3
comment|/* cf18 */
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_CF18_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_DQ_FLUSH_MASK
value|0x3
comment|/* cf19 */
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_DQ_FLUSH_SHIFT
value|6
name|u8
name|flags7
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_FLUSH_Q0_MASK
value|0x3
comment|/* cf20 */
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_FLUSH_Q0_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_FLUSH_Q1_MASK
value|0x3
comment|/* cf21 */
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_FLUSH_Q1_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_SLOW_PATH_MASK
value|0x3
comment|/* cf22 */
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_SLOW_PATH_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_CF0EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_CF0EN_SHIFT
value|6
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_CF1EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_CF1EN_SHIFT
value|7
name|u8
name|flags8
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_CF2EN_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_CF2EN_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_TIMER_STOP_ALL_EN_MASK
value|0x1
comment|/* cf3en */
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_TIMER_STOP_ALL_EN_SHIFT
value|1
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_CF4EN_MASK
value|0x1
comment|/* cf4en */
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_CF4EN_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_CF5EN_MASK
value|0x1
comment|/* cf5en */
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_CF5EN_SHIFT
value|3
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_CF6EN_MASK
value|0x1
comment|/* cf6en */
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_CF6EN_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_CF7EN_MASK
value|0x1
comment|/* cf7en */
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_CF7EN_SHIFT
value|5
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_CF8EN_MASK
value|0x1
comment|/* cf8en */
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_CF8EN_SHIFT
value|6
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_CF9EN_MASK
value|0x1
comment|/* cf9en */
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_CF9EN_SHIFT
value|7
name|u8
name|flags9
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_CF10EN_MASK
value|0x1
comment|/* cf10en */
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_CF10EN_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_CF11EN_MASK
value|0x1
comment|/* cf11en */
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_CF11EN_SHIFT
value|1
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_CF12EN_MASK
value|0x1
comment|/* cf12en */
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_CF12EN_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_CF13EN_MASK
value|0x1
comment|/* cf13en */
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_CF13EN_SHIFT
value|3
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_SQ_FLUSH_CF_EN_MASK
value|0x1
comment|/* cf14en */
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_SQ_FLUSH_CF_EN_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_CF15EN_MASK
value|0x1
comment|/* cf15en */
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_CF15EN_SHIFT
value|5
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_MPA_OR_ERROR_WAKEUP_TRIGGER_CF_EN_MASK
value|0x1
comment|/* cf16en */
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_MPA_OR_ERROR_WAKEUP_TRIGGER_CF_EN_SHIFT
value|6
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_CF17EN_MASK
value|0x1
comment|/* cf_array_cf_en */
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_CF17EN_SHIFT
value|7
name|u8
name|flags10
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_CF18EN_MASK
value|0x1
comment|/* cf18en */
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_CF18EN_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_DQ_FLUSH_EN_MASK
value|0x1
comment|/* cf19en */
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_DQ_FLUSH_EN_SHIFT
value|1
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_FLUSH_Q0_EN_MASK
value|0x1
comment|/* cf20en */
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_FLUSH_Q0_EN_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_FLUSH_Q1_EN_MASK
value|0x1
comment|/* cf21en */
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_FLUSH_Q1_EN_SHIFT
value|3
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_SLOW_PATH_EN_MASK
value|0x1
comment|/* cf22en */
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_SLOW_PATH_EN_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_CF23EN_MASK
value|0x1
comment|/* cf23en */
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_CF23EN_SHIFT
value|5
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_RULE0EN_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_RULE0EN_SHIFT
value|6
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_MORE_TO_SEND_RULE_EN_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_MORE_TO_SEND_RULE_EN_SHIFT
value|7
name|u8
name|flags11
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_TX_BLOCKED_EN_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_TX_BLOCKED_EN_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_RULE3EN_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_RULE3EN_SHIFT
value|1
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_RESERVED3_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_RESERVED3_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_RULE5EN_MASK
value|0x1
comment|/* rule5en */
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_RULE5EN_SHIFT
value|3
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_RULE6EN_MASK
value|0x1
comment|/* rule6en */
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_RULE6EN_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_RULE7EN_MASK
value|0x1
comment|/* rule7en */
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_RULE7EN_SHIFT
value|5
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_A0_RESERVED1_MASK
value|0x1
comment|/* rule8en */
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_A0_RESERVED1_SHIFT
value|6
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_RULE9EN_MASK
value|0x1
comment|/* rule9en */
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_RULE9EN_SHIFT
value|7
name|u8
name|flags12
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_SQ_NOT_EMPTY_RULE_EN_MASK
value|0x1
comment|/* rule10en */
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_SQ_NOT_EMPTY_RULE_EN_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_RULE11EN_MASK
value|0x1
comment|/* rule11en */
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_RULE11EN_SHIFT
value|1
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_A0_RESERVED2_MASK
value|0x1
comment|/* rule12en */
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_A0_RESERVED2_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_A0_RESERVED3_MASK
value|0x1
comment|/* rule13en */
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_A0_RESERVED3_SHIFT
value|3
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_SQ_FENCE_RULE_EN_MASK
value|0x1
comment|/* rule14en */
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_SQ_FENCE_RULE_EN_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_RULE15EN_MASK
value|0x1
comment|/* rule15en */
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_RULE15EN_SHIFT
value|5
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_RULE16EN_MASK
value|0x1
comment|/* rule16en */
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_RULE16EN_SHIFT
value|6
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_RULE17EN_MASK
value|0x1
comment|/* rule17en */
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_RULE17EN_SHIFT
value|7
name|u8
name|flags13
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_IRQ_NOT_EMPTY_RULE_EN_MASK
value|0x1
comment|/* rule18en */
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_IRQ_NOT_EMPTY_RULE_EN_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_HQ_NOT_FULL_RULE_EN_MASK
value|0x1
comment|/* rule19en */
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_HQ_NOT_FULL_RULE_EN_SHIFT
value|1
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_ORQ_RD_FENCE_RULE_EN_MASK
value|0x1
comment|/* rule20en */
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_ORQ_RD_FENCE_RULE_EN_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_RULE21EN_MASK
value|0x1
comment|/* rule21en */
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_RULE21EN_SHIFT
value|3
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_A0_RESERVED6_MASK
value|0x1
comment|/* rule22en */
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_A0_RESERVED6_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_ORQ_NOT_FULL_RULE_EN_MASK
value|0x1
comment|/* rule23en */
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_ORQ_NOT_FULL_RULE_EN_SHIFT
value|5
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_A0_RESERVED8_MASK
value|0x1
comment|/* rule24en */
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_A0_RESERVED8_SHIFT
value|6
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_A0_RESERVED9_MASK
value|0x1
comment|/* rule25en */
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_A0_RESERVED9_SHIFT
value|7
name|u8
name|flags14
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_BIT16_MASK
value|0x1
comment|/* bit16 */
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_BIT16_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_BIT17_MASK
value|0x1
comment|/* bit17 */
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_BIT17_SHIFT
value|1
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_DPM_PORT_NUM_MASK
value|0x3
comment|/* bit18 */
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_DPM_PORT_NUM_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_BIT20_MASK
value|0x1
comment|/* bit20 */
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_BIT20_SHIFT
value|4
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_RDMA_EDPM_ENABLE_MASK
value|0x1
comment|/* bit21 */
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_RDMA_EDPM_ENABLE_SHIFT
value|5
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_CF23_MASK
value|0x3
comment|/* cf23 */
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_CF23_SHIFT
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
name|sq_comp_cons
comment|/* physical_q2 */
decl_stmt|;
name|__le16
name|sq_tx_cons
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
name|more_to_send_seq
comment|/* reg3 */
decl_stmt|;
name|__le32
name|reg4
comment|/* reg4 */
decl_stmt|;
name|__le32
name|rewinded_snd_max
comment|/* cf_array0 */
decl_stmt|;
name|__le32
name|rd_msn
comment|/* cf_array1 */
decl_stmt|;
name|u8
name|flags15
decl_stmt|;
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_E4_RESERVED1_MASK
value|0x1
comment|/* bit22 */
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_E4_RESERVED1_SHIFT
value|0
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_E4_RESERVED2_MASK
value|0x1
comment|/* bit23 */
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_E4_RESERVED2_SHIFT
value|1
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_E4_RESERVED3_MASK
value|0x1
comment|/* bit24 */
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_E4_RESERVED3_SHIFT
value|2
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_E4_RESERVED4_MASK
value|0x3
comment|/* cf24 */
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_E4_RESERVED4_SHIFT
value|3
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_E4_RESERVED5_MASK
value|0x1
comment|/* cf24en */
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_E4_RESERVED5_SHIFT
value|5
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_E4_RESERVED6_MASK
value|0x1
comment|/* rule26en */
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_E4_RESERVED6_SHIFT
value|6
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_E4_RESERVED7_MASK
value|0x1
comment|/* rule27en */
define|#
directive|define
name|E5_XSTORM_IWARP_CONN_AG_CTX_E4_RESERVED7_SHIFT
value|7
name|u8
name|byte7
comment|/* byte7 */
decl_stmt|;
name|__le16
name|irq_prod_via_msdm
comment|/* word7 */
decl_stmt|;
name|__le16
name|irq_cons
comment|/* word8 */
decl_stmt|;
name|__le16
name|hq_cons_th_or_mpa_data
comment|/* word9 */
decl_stmt|;
name|__le16
name|hq_cons
comment|/* word10 */
decl_stmt|;
name|__le16
name|tx_rdma_edpm_usg_cnt
comment|/* word11 */
decl_stmt|;
name|__le32
name|atom_msn
comment|/* reg7 */
decl_stmt|;
name|__le32
name|orq_cons
comment|/* reg8 */
decl_stmt|;
name|__le32
name|orq_cons_th
comment|/* reg9 */
decl_stmt|;
name|u8
name|max_ord
comment|/* byte8 */
decl_stmt|;
name|u8
name|wqe_data_pad_bytes
comment|/* byte9 */
decl_stmt|;
name|u8
name|former_hq_prod
comment|/* byte10 */
decl_stmt|;
name|u8
name|irq_prod_via_msem
comment|/* byte11 */
decl_stmt|;
name|u8
name|byte12
comment|/* byte12 */
decl_stmt|;
name|u8
name|max_pkt_pdu_size_lo
comment|/* byte13 */
decl_stmt|;
name|u8
name|max_pkt_pdu_size_hi
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
name|shared_queue_page_addr_lo
comment|/* reg13 */
decl_stmt|;
name|__le32
name|shared_queue_page_addr_hi
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
name|e5_ystorm_iwarp_conn_ag_ctx
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
name|E5_YSTORM_IWARP_CONN_AG_CTX_BIT0_MASK
value|0x1
comment|/* exist_in_qm0 */
define|#
directive|define
name|E5_YSTORM_IWARP_CONN_AG_CTX_BIT0_SHIFT
value|0
define|#
directive|define
name|E5_YSTORM_IWARP_CONN_AG_CTX_BIT1_MASK
value|0x1
comment|/* exist_in_qm1 */
define|#
directive|define
name|E5_YSTORM_IWARP_CONN_AG_CTX_BIT1_SHIFT
value|1
define|#
directive|define
name|E5_YSTORM_IWARP_CONN_AG_CTX_CF0_MASK
value|0x3
comment|/* cf0 */
define|#
directive|define
name|E5_YSTORM_IWARP_CONN_AG_CTX_CF0_SHIFT
value|2
define|#
directive|define
name|E5_YSTORM_IWARP_CONN_AG_CTX_CF1_MASK
value|0x3
comment|/* cf1 */
define|#
directive|define
name|E5_YSTORM_IWARP_CONN_AG_CTX_CF1_SHIFT
value|4
define|#
directive|define
name|E5_YSTORM_IWARP_CONN_AG_CTX_CF2_MASK
value|0x3
comment|/* cf2 */
define|#
directive|define
name|E5_YSTORM_IWARP_CONN_AG_CTX_CF2_SHIFT
value|6
name|u8
name|flags1
decl_stmt|;
define|#
directive|define
name|E5_YSTORM_IWARP_CONN_AG_CTX_CF0EN_MASK
value|0x1
comment|/* cf0en */
define|#
directive|define
name|E5_YSTORM_IWARP_CONN_AG_CTX_CF0EN_SHIFT
value|0
define|#
directive|define
name|E5_YSTORM_IWARP_CONN_AG_CTX_CF1EN_MASK
value|0x1
comment|/* cf1en */
define|#
directive|define
name|E5_YSTORM_IWARP_CONN_AG_CTX_CF1EN_SHIFT
value|1
define|#
directive|define
name|E5_YSTORM_IWARP_CONN_AG_CTX_CF2EN_MASK
value|0x1
comment|/* cf2en */
define|#
directive|define
name|E5_YSTORM_IWARP_CONN_AG_CTX_CF2EN_SHIFT
value|2
define|#
directive|define
name|E5_YSTORM_IWARP_CONN_AG_CTX_RULE0EN_MASK
value|0x1
comment|/* rule0en */
define|#
directive|define
name|E5_YSTORM_IWARP_CONN_AG_CTX_RULE0EN_SHIFT
value|3
define|#
directive|define
name|E5_YSTORM_IWARP_CONN_AG_CTX_RULE1EN_MASK
value|0x1
comment|/* rule1en */
define|#
directive|define
name|E5_YSTORM_IWARP_CONN_AG_CTX_RULE1EN_SHIFT
value|4
define|#
directive|define
name|E5_YSTORM_IWARP_CONN_AG_CTX_RULE2EN_MASK
value|0x1
comment|/* rule2en */
define|#
directive|define
name|E5_YSTORM_IWARP_CONN_AG_CTX_RULE2EN_SHIFT
value|5
define|#
directive|define
name|E5_YSTORM_IWARP_CONN_AG_CTX_RULE3EN_MASK
value|0x1
comment|/* rule3en */
define|#
directive|define
name|E5_YSTORM_IWARP_CONN_AG_CTX_RULE3EN_SHIFT
value|6
define|#
directive|define
name|E5_YSTORM_IWARP_CONN_AG_CTX_RULE4EN_MASK
value|0x1
comment|/* rule4en */
define|#
directive|define
name|E5_YSTORM_IWARP_CONN_AG_CTX_RULE4EN_SHIFT
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
comment|/* __ECORE_HSI_IWARP__ */
end_comment

end_unit

