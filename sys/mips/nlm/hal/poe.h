begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003-2012 Broadcom Corporation  * All Rights Reserved  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *   * THIS SOFTWARE IS PROVIDED BY BROADCOM ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL BROADCOM OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR  * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE  * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN  * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__NLM_POE_H__
end_ifndef

begin_define
define|#
directive|define
name|__NLM_POE_H__
end_define

begin_comment
comment|/** * @file_name poe.h * @author Netlogic Microsystems * @brief Basic definitions of XLP Packet Order Engine */
end_comment

begin_comment
comment|/* POE specific registers */
end_comment

begin_define
define|#
directive|define
name|POE_CL0_ENQ_SPILL_BASE_LO
value|0x0
end_define

begin_define
define|#
directive|define
name|POE_CL1_ENQ_SPILL_BASE_LO
value|0x2
end_define

begin_define
define|#
directive|define
name|POE_CL2_ENQ_SPILL_BASE_LO
value|0x4
end_define

begin_define
define|#
directive|define
name|POE_CL3_ENQ_SPILL_BASE_LO
value|0x6
end_define

begin_define
define|#
directive|define
name|POE_CL4_ENQ_SPILL_BASE_LO
value|0x8
end_define

begin_define
define|#
directive|define
name|POE_CL5_ENQ_SPILL_BASE_LO
value|0xa
end_define

begin_define
define|#
directive|define
name|POE_CL6_ENQ_SPILL_BASE_LO
value|0xc
end_define

begin_define
define|#
directive|define
name|POE_CL7_ENQ_SPILL_BASE_LO
value|0xe
end_define

begin_define
define|#
directive|define
name|POE_CL0_ENQ_SPILL_BASE_HI
value|0x1
end_define

begin_define
define|#
directive|define
name|POE_CL1_ENQ_SPILL_BASE_HI
value|0x3
end_define

begin_define
define|#
directive|define
name|POE_CL2_ENQ_SPILL_BASE_HI
value|0x5
end_define

begin_define
define|#
directive|define
name|POE_CL3_ENQ_SPILL_BASE_HI
value|0x7
end_define

begin_define
define|#
directive|define
name|POE_CL4_ENQ_SPILL_BASE_HI
value|0x9
end_define

begin_define
define|#
directive|define
name|POE_CL5_ENQ_SPILL_BASE_HI
value|0xb
end_define

begin_define
define|#
directive|define
name|POE_CL6_ENQ_SPILL_BASE_HI
value|0xd
end_define

begin_define
define|#
directive|define
name|POE_CL7_ENQ_SPILL_BASE_HI
value|0xf
end_define

begin_define
define|#
directive|define
name|POE_CL0_DEQ_SPILL_BASE_LO
value|0x10
end_define

begin_define
define|#
directive|define
name|POE_CL1_DEQ_SPILL_BASE_LO
value|0x12
end_define

begin_define
define|#
directive|define
name|POE_CL2_DEQ_SPILL_BASE_LO
value|0x14
end_define

begin_define
define|#
directive|define
name|POE_CL3_DEQ_SPILL_BASE_LO
value|0x16
end_define

begin_define
define|#
directive|define
name|POE_CL4_DEQ_SPILL_BASE_LO
value|0x18
end_define

begin_define
define|#
directive|define
name|POE_CL5_DEQ_SPILL_BASE_LO
value|0x1a
end_define

begin_define
define|#
directive|define
name|POE_CL6_DEQ_SPILL_BASE_LO
value|0x1c
end_define

begin_define
define|#
directive|define
name|POE_CL7_DEQ_SPILL_BASE_LO
value|0x1e
end_define

begin_define
define|#
directive|define
name|POE_CL0_DEQ_SPILL_BASE_HI
value|0x11
end_define

begin_define
define|#
directive|define
name|POE_CL1_DEQ_SPILL_BASE_HI
value|0x13
end_define

begin_define
define|#
directive|define
name|POE_CL2_DEQ_SPILL_BASE_HI
value|0x15
end_define

begin_define
define|#
directive|define
name|POE_CL3_DEQ_SPILL_BASE_HI
value|0x17
end_define

begin_define
define|#
directive|define
name|POE_CL4_DEQ_SPILL_BASE_HI
value|0x19
end_define

begin_define
define|#
directive|define
name|POE_CL5_DEQ_SPILL_BASE_HI
value|0x1b
end_define

begin_define
define|#
directive|define
name|POE_CL6_DEQ_SPILL_BASE_HI
value|0x1d
end_define

begin_define
define|#
directive|define
name|POE_CL7_DEQ_SPILL_BASE_HI
value|0x1f
end_define

begin_define
define|#
directive|define
name|POE_MSG_STORAGE_BASE_ADDR_LO
value|0x20
end_define

begin_define
define|#
directive|define
name|POE_MSG_STORAGE_BASE_ADDR_HI
value|0x21
end_define

begin_define
define|#
directive|define
name|POE_FBP_BASE_ADDR_LO
value|0x22
end_define

begin_define
define|#
directive|define
name|POE_FBP_BASE_ADDR_HI
value|0x23
end_define

begin_define
define|#
directive|define
name|POE_CL0_ENQ_SPILL_MAXLINE_LO
value|0x24
end_define

begin_define
define|#
directive|define
name|POE_CL1_ENQ_SPILL_MAXLINE_LO
value|0x25
end_define

begin_define
define|#
directive|define
name|POE_CL2_ENQ_SPILL_MAXLINE_LO
value|0x26
end_define

begin_define
define|#
directive|define
name|POE_CL3_ENQ_SPILL_MAXLINE_LO
value|0x27
end_define

begin_define
define|#
directive|define
name|POE_CL4_ENQ_SPILL_MAXLINE_LO
value|0x28
end_define

begin_define
define|#
directive|define
name|POE_CL5_ENQ_SPILL_MAXLINE_LO
value|0x29
end_define

begin_define
define|#
directive|define
name|POE_CL6_ENQ_SPILL_MAXLINE_LO
value|0x2a
end_define

begin_define
define|#
directive|define
name|POE_CL7_ENQ_SPILL_MAXLINE_LO
value|0x2b
end_define

begin_define
define|#
directive|define
name|POE_CL0_ENQ_SPILL_MAXLINE_HI
value|0x2c
end_define

begin_define
define|#
directive|define
name|POE_CL1_ENQ_SPILL_MAXLINE_HI
value|0x2d
end_define

begin_define
define|#
directive|define
name|POE_CL2_ENQ_SPILL_MAXLINE_HI
value|0x2e
end_define

begin_define
define|#
directive|define
name|POE_CL3_ENQ_SPILL_MAXLINE_HI
value|0x2f
end_define

begin_define
define|#
directive|define
name|POE_CL4_ENQ_SPILL_MAXLINE_HI
value|0x30
end_define

begin_define
define|#
directive|define
name|POE_CL5_ENQ_SPILL_MAXLINE_HI
value|0x31
end_define

begin_define
define|#
directive|define
name|POE_CL6_ENQ_SPILL_MAXLINE_HI
value|0x32
end_define

begin_define
define|#
directive|define
name|POE_CL7_ENQ_SPILL_MAXLINE_HI
value|0x33
end_define

begin_define
define|#
directive|define
name|POE_MAX_FLOW_MSG0
value|0x40
end_define

begin_define
define|#
directive|define
name|POE_MAX_FLOW_MSG1
value|0x41
end_define

begin_define
define|#
directive|define
name|POE_MAX_FLOW_MSG2
value|0x42
end_define

begin_define
define|#
directive|define
name|POE_MAX_FLOW_MSG3
value|0x43
end_define

begin_define
define|#
directive|define
name|POE_MAX_FLOW_MSG4
value|0x44
end_define

begin_define
define|#
directive|define
name|POE_MAX_FLOW_MSG5
value|0x45
end_define

begin_define
define|#
directive|define
name|POE_MAX_FLOW_MSG6
value|0x46
end_define

begin_define
define|#
directive|define
name|POE_MAX_FLOW_MSG7
value|0x47
end_define

begin_define
define|#
directive|define
name|POE_MAX_MSG_CL0
value|0x48
end_define

begin_define
define|#
directive|define
name|POE_MAX_MSG_CL1
value|0x49
end_define

begin_define
define|#
directive|define
name|POE_MAX_MSG_CL2
value|0x4a
end_define

begin_define
define|#
directive|define
name|POE_MAX_MSG_CL3
value|0x4b
end_define

begin_define
define|#
directive|define
name|POE_MAX_MSG_CL4
value|0x4c
end_define

begin_define
define|#
directive|define
name|POE_MAX_MSG_CL5
value|0x4d
end_define

begin_define
define|#
directive|define
name|POE_MAX_MSG_CL6
value|0x4e
end_define

begin_define
define|#
directive|define
name|POE_MAX_MSG_CL7
value|0x4f
end_define

begin_define
define|#
directive|define
name|POE_MAX_LOC_BUF_STG_CL0
value|0x50
end_define

begin_define
define|#
directive|define
name|POE_MAX_LOC_BUF_STG_CL1
value|0x51
end_define

begin_define
define|#
directive|define
name|POE_MAX_LOC_BUF_STG_CL2
value|0x52
end_define

begin_define
define|#
directive|define
name|POE_MAX_LOC_BUF_STG_CL3
value|0x53
end_define

begin_define
define|#
directive|define
name|POE_MAX_LOC_BUF_STG_CL4
value|0x54
end_define

begin_define
define|#
directive|define
name|POE_MAX_LOC_BUF_STG_CL5
value|0x55
end_define

begin_define
define|#
directive|define
name|POE_MAX_LOC_BUF_STG_CL6
value|0x56
end_define

begin_define
define|#
directive|define
name|POE_MAX_LOC_BUF_STG_CL7
value|0x57
end_define

begin_define
define|#
directive|define
name|POE_ENQ_MSG_COUNT0_SIZE
value|0x58
end_define

begin_define
define|#
directive|define
name|POE_ENQ_MSG_COUNT1_SIZE
value|0x59
end_define

begin_define
define|#
directive|define
name|POE_ENQ_MSG_COUNT2_SIZE
value|0x5a
end_define

begin_define
define|#
directive|define
name|POE_ENQ_MSG_COUNT3_SIZE
value|0x5b
end_define

begin_define
define|#
directive|define
name|POE_ENQ_MSG_COUNT4_SIZE
value|0x5c
end_define

begin_define
define|#
directive|define
name|POE_ENQ_MSG_COUNT5_SIZE
value|0x5d
end_define

begin_define
define|#
directive|define
name|POE_ENQ_MSG_COUNT6_SIZE
value|0x5e
end_define

begin_define
define|#
directive|define
name|POE_ENQ_MSG_COUNT7_SIZE
value|0x5f
end_define

begin_define
define|#
directive|define
name|POE_ERR_MSG_DESCRIP_LO0
value|0x60
end_define

begin_define
define|#
directive|define
name|POE_ERR_MSG_DESCRIP_LO1
value|0x62
end_define

begin_define
define|#
directive|define
name|POE_ERR_MSG_DESCRIP_LO2
value|0x64
end_define

begin_define
define|#
directive|define
name|POE_ERR_MSG_DESCRIP_LO3
value|0x66
end_define

begin_define
define|#
directive|define
name|POE_ERR_MSG_DESCRIP_HI0
value|0x61
end_define

begin_define
define|#
directive|define
name|POE_ERR_MSG_DESCRIP_HI1
value|0x63
end_define

begin_define
define|#
directive|define
name|POE_ERR_MSG_DESCRIP_HI2
value|0x65
end_define

begin_define
define|#
directive|define
name|POE_ERR_MSG_DESCRIP_HI3
value|0x67
end_define

begin_define
define|#
directive|define
name|POE_OOO_MSG_CNT_LO
value|0x68
end_define

begin_define
define|#
directive|define
name|POE_IN_ORDER_MSG_CNT_LO
value|0x69
end_define

begin_define
define|#
directive|define
name|POE_LOC_BUF_STOR_CNT_LO
value|0x6a
end_define

begin_define
define|#
directive|define
name|POE_EXT_BUF_STOR_CNT_LO
value|0x6b
end_define

begin_define
define|#
directive|define
name|POE_LOC_BUF_ALLOC_CNT_LO
value|0x6c
end_define

begin_define
define|#
directive|define
name|POE_EXT_BUF_ALLOC_CNT_LO
value|0x6d
end_define

begin_define
define|#
directive|define
name|POE_OOO_MSG_CNT_HI
value|0x6e
end_define

begin_define
define|#
directive|define
name|POE_IN_ORDER_MSG_CNT_HI
value|0x6f
end_define

begin_define
define|#
directive|define
name|POE_LOC_BUF_STOR_CNT_HI
value|0x70
end_define

begin_define
define|#
directive|define
name|POE_EXT_BUF_STOR_CNT_HI
value|0x71
end_define

begin_define
define|#
directive|define
name|POE_LOC_BUF_ALLOC_CNT_HI
value|0x72
end_define

begin_define
define|#
directive|define
name|POE_EXT_BUF_ALLOC_CNT_HI
value|0x73
end_define

begin_define
define|#
directive|define
name|POE_MODE_ERR_FLOW_ID
value|0x74
end_define

begin_define
define|#
directive|define
name|POE_STATISTICS_ENABLE
value|0x75
end_define

begin_define
define|#
directive|define
name|POE_MAX_SIZE_FLOW
value|0x76
end_define

begin_define
define|#
directive|define
name|POE_MAX_SIZE
value|0x77
end_define

begin_define
define|#
directive|define
name|POE_FBP_SP
value|0x78
end_define

begin_define
define|#
directive|define
name|POE_FBP_SP_EN
value|0x79
end_define

begin_define
define|#
directive|define
name|POE_LOC_ALLOC_EN
value|0x7a
end_define

begin_define
define|#
directive|define
name|POE_EXT_ALLOC_EN
value|0x7b
end_define

begin_define
define|#
directive|define
name|POE_DISTR_0_DROP_CNT
value|0xc0
end_define

begin_define
define|#
directive|define
name|POE_DISTR_1_DROP_CNT
value|0xc1
end_define

begin_define
define|#
directive|define
name|POE_DISTR_2_DROP_CNT
value|0xc2
end_define

begin_define
define|#
directive|define
name|POE_DISTR_3_DROP_CNT
value|0xc3
end_define

begin_define
define|#
directive|define
name|POE_DISTR_4_DROP_CNT
value|0xc4
end_define

begin_define
define|#
directive|define
name|POE_DISTR_5_DROP_CNT
value|0xc5
end_define

begin_define
define|#
directive|define
name|POE_DISTR_6_DROP_CNT
value|0xc6
end_define

begin_define
define|#
directive|define
name|POE_DISTR_7_DROP_CNT
value|0xc7
end_define

begin_define
define|#
directive|define
name|POE_DISTR_8_DROP_CNT
value|0xc8
end_define

begin_define
define|#
directive|define
name|POE_DISTR_9_DROP_CNT
value|0xc9
end_define

begin_define
define|#
directive|define
name|POE_DISTR_10_DROP_CNT
value|0xca
end_define

begin_define
define|#
directive|define
name|POE_DISTR_11_DROP_CNT
value|0xcb
end_define

begin_define
define|#
directive|define
name|POE_DISTR_12_DROP_CNT
value|0xcc
end_define

begin_define
define|#
directive|define
name|POE_DISTR_13_DROP_CNT
value|0xcd
end_define

begin_define
define|#
directive|define
name|POE_DISTR_14_DROP_CNT
value|0xce
end_define

begin_define
define|#
directive|define
name|POE_DISTR_15_DROP_CNT
value|0xcf
end_define

begin_define
define|#
directive|define
name|POE_CLASS_0_DROP_CNT
value|0xd0
end_define

begin_define
define|#
directive|define
name|POE_CLASS_1_DROP_CNT
value|0xd1
end_define

begin_define
define|#
directive|define
name|POE_CLASS_2_DROP_CNT
value|0xd2
end_define

begin_define
define|#
directive|define
name|POE_CLASS_3_DROP_CNT
value|0xd3
end_define

begin_define
define|#
directive|define
name|POE_CLASS_4_DROP_CNT
value|0xd4
end_define

begin_define
define|#
directive|define
name|POE_CLASS_5_DROP_CNT
value|0xd5
end_define

begin_define
define|#
directive|define
name|POE_CLASS_6_DROP_CNT
value|0xd6
end_define

begin_define
define|#
directive|define
name|POE_CLASS_7_DROP_CNT
value|0xd7
end_define

begin_define
define|#
directive|define
name|POE_DISTR_C0_DROP_CNT
value|0xd8
end_define

begin_define
define|#
directive|define
name|POE_DISTR_C1_DROP_CNT
value|0xd9
end_define

begin_define
define|#
directive|define
name|POE_DISTR_C2_DROP_CNT
value|0xda
end_define

begin_define
define|#
directive|define
name|POE_DISTR_C3_DROP_CNT
value|0xdb
end_define

begin_define
define|#
directive|define
name|POE_DISTR_C4_DROP_CNT
value|0xdc
end_define

begin_define
define|#
directive|define
name|POE_DISTR_C5_DROP_CNT
value|0xdd
end_define

begin_define
define|#
directive|define
name|POE_DISTR_C6_DROP_CNT
value|0xde
end_define

begin_define
define|#
directive|define
name|POE_DISTR_C7_DROP_CNT
value|0xdf
end_define

begin_define
define|#
directive|define
name|POE_CPU_DROP_CNT
value|0xe0
end_define

begin_define
define|#
directive|define
name|POE_MAX_FLOW_DROP_CNT
value|0xe1
end_define

begin_define
define|#
directive|define
name|POE_INTERRUPT_VEC
value|0x140
end_define

begin_define
define|#
directive|define
name|POE_INTERRUPT_MASK
value|0x141
end_define

begin_define
define|#
directive|define
name|POE_FATALERR_MASK
value|0x142
end_define

begin_define
define|#
directive|define
name|POE_IDI_CFG
value|0x143
end_define

begin_define
define|#
directive|define
name|POE_TIMEOUT_VALUE
value|0x144
end_define

begin_define
define|#
directive|define
name|POE_CACHE_ALLOC_EN
value|0x145
end_define

begin_define
define|#
directive|define
name|POE_FBP_ECC_ERR_CNT
value|0x146
end_define

begin_define
define|#
directive|define
name|POE_MSG_STRG_ECC_ERR_CNT
value|0x147
end_define

begin_define
define|#
directive|define
name|POE_FID_INFO_ECC_ERR_CNT
value|0x148
end_define

begin_define
define|#
directive|define
name|POE_MSG_INFO_ECC_ERR_CNT
value|0x149
end_define

begin_define
define|#
directive|define
name|POE_LL_ECC_ERR_CNT
value|0x14a
end_define

begin_define
define|#
directive|define
name|POE_SIZE_ECC_ERR_CNT
value|0x14b
end_define

begin_define
define|#
directive|define
name|POE_FMN_TXCR_ECC_ERR_CNT
value|0x14c
end_define

begin_define
define|#
directive|define
name|POE_ENQ_INSPIL_ECC_ERR_CNT
value|0x14d
end_define

begin_define
define|#
directive|define
name|POE_ENQ_OUTSPIL_ECC_ERR_CNT
value|0x14e
end_define

begin_define
define|#
directive|define
name|POE_DEQ_OUTSPIL_ECC_ERR_CNT
value|0x14f
end_define

begin_define
define|#
directive|define
name|POE_ENQ_MSG_SENT
value|0x150
end_define

begin_define
define|#
directive|define
name|POE_ENQ_MSG_CNT
value|0x151
end_define

begin_define
define|#
directive|define
name|POE_FID_RDATA
value|0x152
end_define

begin_define
define|#
directive|define
name|POE_FID_WDATA
value|0x153
end_define

begin_define
define|#
directive|define
name|POE_FID_CMD
value|0x154
end_define

begin_define
define|#
directive|define
name|POE_FID_ADDR
value|0x155
end_define

begin_define
define|#
directive|define
name|POE_MSG_INFO_CMD
value|0x156
end_define

begin_define
define|#
directive|define
name|POE_MSG_INFO_ADDR
value|0x157
end_define

begin_define
define|#
directive|define
name|POE_MSG_INFO_RDATA
value|0x158
end_define

begin_define
define|#
directive|define
name|POE_LL_CMD
value|0x159
end_define

begin_define
define|#
directive|define
name|POE_LL_ADDR
value|0x15a
end_define

begin_define
define|#
directive|define
name|POE_LL_RDATA
value|0x15b
end_define

begin_define
define|#
directive|define
name|POE_MSG_STG_CMD
value|0x15c
end_define

begin_define
define|#
directive|define
name|POE_MSG_STG_ADDR
value|0x15d
end_define

begin_define
define|#
directive|define
name|POE_MSG_STG_RDATA
value|0x15e
end_define

begin_define
define|#
directive|define
name|POE_DISTR_THRESHOLD_0
value|0x1c0
end_define

begin_define
define|#
directive|define
name|POE_DISTR_THRESHOLD_1
value|0x1c1
end_define

begin_define
define|#
directive|define
name|POE_DISTR_THRESHOLD_2
value|0x1c2
end_define

begin_define
define|#
directive|define
name|POE_DISTR_THRESHOLD_3
value|0x1c3
end_define

begin_define
define|#
directive|define
name|POE_DISTR_THRESHOLD_4
value|0x1c4
end_define

begin_define
define|#
directive|define
name|POE_DISTR_THRESHOLD
parameter_list|(
name|i
parameter_list|)
value|(0x1c0 + (i))
end_define

begin_define
define|#
directive|define
name|POE_DISTR_EN
value|0x1c5
end_define

begin_define
define|#
directive|define
name|POE_ENQ_SPILL_THOLD
value|0x1c8
end_define

begin_define
define|#
directive|define
name|POE_DEQ_SPILL_THOLD
value|0x1c9
end_define

begin_define
define|#
directive|define
name|POE_DEQ_SPILL_TIMER
value|0x1ca
end_define

begin_define
define|#
directive|define
name|POE_DISTR_CLASS_DROP_EN
value|0x1cb
end_define

begin_define
define|#
directive|define
name|POE_DISTR_VEC_DROP_EN
value|0x1cc
end_define

begin_define
define|#
directive|define
name|POE_DISTR_DROP_TIMER
value|0x1cd
end_define

begin_define
define|#
directive|define
name|POE_ERROR_LOG_W0
value|0x1ce
end_define

begin_define
define|#
directive|define
name|POE_ERROR_LOG_W1
value|0x1cf
end_define

begin_define
define|#
directive|define
name|POE_ERROR_LOG_W2
value|0x1d0
end_define

begin_define
define|#
directive|define
name|POE_ERR_INJ_CTRL0
value|0x1d1
end_define

begin_define
define|#
directive|define
name|POE_TX_TIMER
value|0x1d4
end_define

begin_define
define|#
directive|define
name|NUM_DIST_VEC
value|16
end_define

begin_define
define|#
directive|define
name|NUM_WORDS_PER_DV
value|16
end_define

begin_define
define|#
directive|define
name|MAX_DV_TBL_ENTRIES
value|(NUM_DIST_VEC * NUM_WORDS_PER_DV)
end_define

begin_define
define|#
directive|define
name|POE_DIST_THRESHOLD_VAL
value|0xa
end_define

begin_comment
comment|/*  * POE distribution vectors  *  * Each vector is 512 bit with msb indicating vc 512 and lsb indicating vc 0  * 512-bit-vector is specified as 16 32-bit words.  * Left most word has the vc range 511-479 right most word has vc range 31 - 0  * Each word has the MSB select higer vc number and LSB select lower vc num  */
end_comment

begin_define
define|#
directive|define
name|POE_DISTVECT_BASE
value|0x100
end_define

begin_define
define|#
directive|define
name|POE_DISTVECT
parameter_list|(
name|vec
parameter_list|)
value|(POE_DISTVECT_BASE + 16 * (vec))
end_define

begin_define
define|#
directive|define
name|POE_DISTVECT_OFFSET
parameter_list|(
name|node
parameter_list|,
name|cpu
parameter_list|)
value|(4 * (3 - (node)) + (3 - (cpu)/8))
end_define

begin_define
define|#
directive|define
name|POE_DISTVECT_SHIFT
parameter_list|(
name|node
parameter_list|,
name|cpu
parameter_list|)
value|(((cpu) % 8 ) * 4)
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|LOCORE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__ASSEMBLY__
argument_list|)
end_if

begin_define
define|#
directive|define
name|nlm_read_poe_reg
parameter_list|(
name|b
parameter_list|,
name|r
parameter_list|)
value|nlm_read_reg(b, r)
end_define

begin_define
define|#
directive|define
name|nlm_write_poe_reg
parameter_list|(
name|b
parameter_list|,
name|r
parameter_list|,
name|v
parameter_list|)
value|nlm_write_reg(b, r, v)
end_define

begin_define
define|#
directive|define
name|nlm_read_poedv_reg
parameter_list|(
name|b
parameter_list|,
name|r
parameter_list|)
value|nlm_read_reg_xkphys(b, r)
end_define

begin_define
define|#
directive|define
name|nlm_write_poedv_reg
parameter_list|(
name|b
parameter_list|,
name|r
parameter_list|,
name|v
parameter_list|)
value|nlm_write_reg_xkphys(b, r, v)
end_define

begin_define
define|#
directive|define
name|nlm_get_poe_pcibase
parameter_list|(
name|node
parameter_list|)
define|\
value|nlm_pcicfg_base(XLP_IO_POE_OFFSET(node))
end_define

begin_define
define|#
directive|define
name|nlm_get_poe_regbase
parameter_list|(
name|node
parameter_list|)
define|\
value|(nlm_get_poe_pcibase(node) + XLP_IO_PCI_HDRSZ)
end_define

begin_define
define|#
directive|define
name|nlm_get_poedv_regbase
parameter_list|(
name|node
parameter_list|)
define|\
value|nlm_xkphys_map_pcibar0(nlm_get_poe_pcibase(node))
end_define

begin_function
specifier|static
name|__inline
name|int
name|nlm_poe_max_flows
parameter_list|(
name|uint64_t
name|poe_pcibase
parameter_list|)
block|{
return|return
operator|(
name|nlm_read_reg
argument_list|(
name|poe_pcibase
argument_list|,
name|XLP_PCI_DEVINFO_REG0
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Helper function, calculate the distribution vector  * cm0, cm1, cm2, cm3 : CPU masks for nodes 0..3  * thr_vcmask: destination VCs for a thread  */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|nlm_calc_poe_distvec
parameter_list|(
name|uint32_t
name|cm0
parameter_list|,
name|uint32_t
name|cm1
parameter_list|,
name|uint32_t
name|cm2
parameter_list|,
name|uint32_t
name|cm3
parameter_list|,
name|uint32_t
name|thr_vcmask
parameter_list|,
name|uint32_t
modifier|*
name|distvec
parameter_list|)
block|{
name|uint32_t
name|cpumask
init|=
literal|0
decl_stmt|,
name|val
decl_stmt|;
name|int
name|i
decl_stmt|,
name|cpu
decl_stmt|,
name|node
decl_stmt|,
name|startcpu
decl_stmt|,
name|index
decl_stmt|;
name|thr_vcmask
operator|&=
literal|0xf
expr_stmt|;
for|for
control|(
name|node
operator|=
literal|0
init|;
name|node
operator|<
name|XLP_MAX_NODES
condition|;
name|node
operator|++
control|)
block|{
switch|switch
condition|(
name|node
condition|)
block|{
case|case
literal|0
case|:
name|cpumask
operator|=
name|cm0
expr_stmt|;
break|break;
case|case
literal|1
case|:
name|cpumask
operator|=
name|cm1
expr_stmt|;
break|break;
case|case
literal|2
case|:
name|cpumask
operator|=
name|cm2
expr_stmt|;
break|break;
case|case
literal|3
case|:
name|cpumask
operator|=
name|cm3
expr_stmt|;
break|break;
block|}
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|4
condition|;
name|i
operator|++
control|)
block|{
name|val
operator|=
literal|0
expr_stmt|;
name|startcpu
operator|=
literal|31
operator|-
name|i
operator|*
literal|8
expr_stmt|;
for|for
control|(
name|cpu
operator|=
name|startcpu
init|;
name|cpu
operator|>=
name|startcpu
operator|-
literal|7
condition|;
name|cpu
operator|--
control|)
block|{
name|val
operator|<<=
literal|4
expr_stmt|;
if|if
condition|(
name|cpumask
operator|&
operator|(
literal|1U
operator|<<
name|cpu
operator|)
condition|)
name|val
operator||=
name|thr_vcmask
expr_stmt|;
block|}
name|index
operator|=
name|POE_DISTVECT_OFFSET
argument_list|(
name|node
argument_list|,
name|startcpu
argument_list|)
expr_stmt|;
name|distvec
index|[
name|index
index|]
operator|=
name|val
expr_stmt|;
block|}
block|}
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|nlm_write_poe_distvec
parameter_list|(
name|uint64_t
name|poedv_base
parameter_list|,
name|int
name|vec
parameter_list|,
name|uint32_t
modifier|*
name|distvec
parameter_list|)
block|{
name|uint32_t
name|reg
decl_stmt|;
name|int
name|i
decl_stmt|;
if|if
condition|(
name|vec
operator|<
literal|0
operator|||
name|vec
operator|>=
name|NUM_DIST_VEC
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|NUM_WORDS_PER_DV
condition|;
name|i
operator|++
control|)
block|{
name|reg
operator|=
name|POE_DISTVECT
argument_list|(
name|vec
argument_list|)
operator|+
name|i
expr_stmt|;
name|nlm_write_poedv_reg
argument_list|(
name|poedv_base
argument_list|,
name|reg
argument_list|,
name|distvec
index|[
name|i
index|]
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|nlm_config_poe
parameter_list|(
name|uint64_t
name|poe_base
parameter_list|,
name|uint64_t
name|poedv_base
parameter_list|)
block|{
name|uint32_t
name|zerodv
index|[
name|NUM_WORDS_PER_DV
index|]
decl_stmt|;
name|int
name|i
decl_stmt|;
comment|/* First disable distribution vector logic */
name|nlm_write_poe_reg
argument_list|(
name|poe_base
argument_list|,
name|POE_DISTR_EN
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|memset
argument_list|(
name|zerodv
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|zerodv
argument_list|)
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|NUM_DIST_VEC
condition|;
name|i
operator|++
control|)
name|nlm_write_poe_distvec
argument_list|(
name|poedv_base
argument_list|,
name|i
argument_list|,
name|zerodv
argument_list|)
expr_stmt|;
comment|/* set the threshold */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|5
condition|;
name|i
operator|++
control|)
name|nlm_write_poe_reg
argument_list|(
name|poe_base
argument_list|,
name|POE_DISTR_THRESHOLD
argument_list|(
name|i
argument_list|)
argument_list|,
name|POE_DIST_THRESHOLD_VAL
argument_list|)
expr_stmt|;
name|nlm_write_poe_reg
argument_list|(
name|poe_base
argument_list|,
name|POE_DISTR_EN
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|/* always enable local message store */
name|nlm_write_poe_reg
argument_list|(
name|poe_base
argument_list|,
name|POE_LOC_ALLOC_EN
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|nlm_write_poe_reg
argument_list|(
name|poe_base
argument_list|,
name|POE_TX_TIMER
argument_list|,
literal|0x3
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !(LOCORE)&& !(__ASSEMBLY__) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

