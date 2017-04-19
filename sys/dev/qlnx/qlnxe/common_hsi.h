begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2017-2018 Cavium, Inc.   * All rights reserved.  *  *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *  *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *  *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  *  POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__COMMON_HSI__
end_ifndef

begin_define
define|#
directive|define
name|__COMMON_HSI__
end_define

begin_comment
comment|/********************************/
end_comment

begin_comment
comment|/* PROTOCOL COMMON FW CONSTANTS */
end_comment

begin_comment
comment|/********************************/
end_comment

begin_comment
comment|/* Temporarily here should be added to HSI automatically by resource allocation tool.*/
end_comment

begin_define
define|#
directive|define
name|T_TEST_AGG_INT_TEMP
value|6
end_define

begin_define
define|#
directive|define
name|M_TEST_AGG_INT_TEMP
value|8
end_define

begin_define
define|#
directive|define
name|U_TEST_AGG_INT_TEMP
value|6
end_define

begin_define
define|#
directive|define
name|X_TEST_AGG_INT_TEMP
value|14
end_define

begin_define
define|#
directive|define
name|Y_TEST_AGG_INT_TEMP
value|4
end_define

begin_define
define|#
directive|define
name|P_TEST_AGG_INT_TEMP
value|4
end_define

begin_define
define|#
directive|define
name|X_FINAL_CLEANUP_AGG_INT
value|1
end_define

begin_define
define|#
directive|define
name|EVENT_RING_PAGE_SIZE_BYTES
value|4096
end_define

begin_define
define|#
directive|define
name|NUM_OF_GLOBAL_QUEUES
value|128
end_define

begin_define
define|#
directive|define
name|COMMON_QUEUE_ENTRY_MAX_BYTE_SIZE
value|64
end_define

begin_define
define|#
directive|define
name|ISCSI_CDU_TASK_SEG_TYPE
value|0
end_define

begin_define
define|#
directive|define
name|FCOE_CDU_TASK_SEG_TYPE
value|0
end_define

begin_define
define|#
directive|define
name|RDMA_CDU_TASK_SEG_TYPE
value|1
end_define

begin_define
define|#
directive|define
name|FW_ASSERT_GENERAL_ATTN_IDX
value|32
end_define

begin_define
define|#
directive|define
name|MAX_PINNED_CCFC
value|32
end_define

begin_define
define|#
directive|define
name|EAGLE_ENG1_WORKAROUND_NIG_FLOWCTRL_MODE
value|3
end_define

begin_comment
comment|/* Queue Zone sizes in bytes */
end_comment

begin_define
define|#
directive|define
name|TSTORM_QZONE_SIZE
value|8
end_define

begin_comment
comment|/*tstorm_scsi_queue_zone*/
end_comment

begin_define
define|#
directive|define
name|MSTORM_QZONE_SIZE
value|16
end_define

begin_comment
comment|/*mstorm_eth_queue_zone. Used only for RX producer of VFs in backward compatibility mode.*/
end_comment

begin_define
define|#
directive|define
name|USTORM_QZONE_SIZE
value|8
end_define

begin_comment
comment|/*ustorm_eth_queue_zone*/
end_comment

begin_define
define|#
directive|define
name|XSTORM_QZONE_SIZE
value|8
end_define

begin_comment
comment|/*xstorm_eth_queue_zone*/
end_comment

begin_define
define|#
directive|define
name|YSTORM_QZONE_SIZE
value|0
end_define

begin_define
define|#
directive|define
name|PSTORM_QZONE_SIZE
value|0
end_define

begin_define
define|#
directive|define
name|MSTORM_VF_ZONE_DEFAULT_SIZE_LOG
value|7
end_define

begin_comment
comment|/*Log of mstorm default VF zone size.*/
end_comment

begin_define
define|#
directive|define
name|ETH_MAX_NUM_RX_QUEUES_PER_VF_DEFAULT
value|16
end_define

begin_comment
comment|/*Maximum number of RX queues that can be allocated to VF by default*/
end_comment

begin_define
define|#
directive|define
name|ETH_MAX_NUM_RX_QUEUES_PER_VF_DOUBLE
value|48
end_define

begin_comment
comment|/*Maximum number of RX queues that can be allocated to VF with doubled VF zone size. Up to 96 VF supported in this mode*/
end_comment

begin_define
define|#
directive|define
name|ETH_MAX_NUM_RX_QUEUES_PER_VF_QUAD
value|112
end_define

begin_comment
comment|/*Maximum number of RX queues that can be allocated to VF with 4 VF zone size. Up to 48 VF supported in this mode*/
end_comment

begin_comment
comment|/********************************/
end_comment

begin_comment
comment|/* CORE (LIGHT L2) FW CONSTANTS */
end_comment

begin_comment
comment|/********************************/
end_comment

begin_define
define|#
directive|define
name|CORE_LL2_MAX_RAMROD_PER_CON
value|8
end_define

begin_define
define|#
directive|define
name|CORE_LL2_TX_BD_PAGE_SIZE_BYTES
value|4096
end_define

begin_define
define|#
directive|define
name|CORE_LL2_RX_BD_PAGE_SIZE_BYTES
value|4096
end_define

begin_define
define|#
directive|define
name|CORE_LL2_RX_CQE_PAGE_SIZE_BYTES
value|4096
end_define

begin_define
define|#
directive|define
name|CORE_LL2_RX_NUM_NEXT_PAGE_BDS
value|1
end_define

begin_define
define|#
directive|define
name|CORE_LL2_TX_MAX_BDS_PER_PACKET
value|12
end_define

begin_define
define|#
directive|define
name|CORE_SPQE_PAGE_SIZE_BYTES
value|4096
end_define

begin_comment
comment|/*  * Usually LL2 queues are opened in pairs TX-RX.  * There is a hard restriction on number of RX queues (limited by Tstorm RAM) and TX counters (Pstorm RAM).  * Number of TX queues is almost unlimited.  * The constants are different so as to allow asymmetric LL2 connections  */
end_comment

begin_define
define|#
directive|define
name|MAX_NUM_LL2_RX_QUEUES
value|48
end_define

begin_define
define|#
directive|define
name|MAX_NUM_LL2_TX_STATS_COUNTERS
value|48
end_define

begin_comment
comment|///////////////////////////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|// Include firmware version number only- do not add constants here to avoid redundunt compilations
end_comment

begin_comment
comment|///////////////////////////////////////////////////////////////////////////////////////////////////
end_comment

begin_define
define|#
directive|define
name|FW_MAJOR_VERSION
value|8
end_define

begin_define
define|#
directive|define
name|FW_MINOR_VERSION
value|18
end_define

begin_define
define|#
directive|define
name|FW_REVISION_VERSION
value|14
end_define

begin_define
define|#
directive|define
name|FW_ENGINEERING_VERSION
value|0
end_define

begin_comment
comment|/***********************/
end_comment

begin_comment
comment|/* COMMON HW CONSTANTS */
end_comment

begin_comment
comment|/***********************/
end_comment

begin_comment
comment|/* PCI functions */
end_comment

begin_define
define|#
directive|define
name|MAX_NUM_PORTS_K2
value|(4)
end_define

begin_define
define|#
directive|define
name|MAX_NUM_PORTS_BB
value|(2)
end_define

begin_define
define|#
directive|define
name|MAX_NUM_PORTS
value|(MAX_NUM_PORTS_K2)
end_define

begin_define
define|#
directive|define
name|MAX_NUM_PFS_K2
value|(16)
end_define

begin_define
define|#
directive|define
name|MAX_NUM_PFS_BB
value|(8)
end_define

begin_define
define|#
directive|define
name|MAX_NUM_PFS
value|(MAX_NUM_PFS_K2)
end_define

begin_define
define|#
directive|define
name|MAX_NUM_OF_PFS_IN_CHIP
value|(16)
end_define

begin_comment
comment|/* On both engines */
end_comment

begin_define
define|#
directive|define
name|MAX_NUM_VFS_BB
value|(120)
end_define

begin_define
define|#
directive|define
name|MAX_NUM_VFS_K2
value|(192)
end_define

begin_define
define|#
directive|define
name|E4_MAX_NUM_VFS
value|(MAX_NUM_VFS_K2)
end_define

begin_define
define|#
directive|define
name|E5_MAX_NUM_VFS
value|(240)
end_define

begin_define
define|#
directive|define
name|COMMON_MAX_NUM_VFS
value|(E5_MAX_NUM_VFS)
end_define

begin_define
define|#
directive|define
name|MAX_NUM_FUNCTIONS_BB
value|(MAX_NUM_PFS_BB + MAX_NUM_VFS_BB)
end_define

begin_define
define|#
directive|define
name|MAX_NUM_FUNCTIONS_K2
value|(MAX_NUM_PFS_K2 + MAX_NUM_VFS_K2)
end_define

begin_define
define|#
directive|define
name|MAX_NUM_FUNCTIONS
value|(MAX_NUM_PFS + E4_MAX_NUM_VFS)
end_define

begin_comment
comment|/* in both BB and K2, the VF number starts from 16. so for arrays containing all */
end_comment

begin_comment
comment|/* possible PFs and VFs - we need a constant for this size */
end_comment

begin_define
define|#
directive|define
name|MAX_FUNCTION_NUMBER_BB
value|(MAX_NUM_PFS + MAX_NUM_VFS_BB)
end_define

begin_define
define|#
directive|define
name|MAX_FUNCTION_NUMBER_K2
value|(MAX_NUM_PFS + MAX_NUM_VFS_K2)
end_define

begin_define
define|#
directive|define
name|MAX_FUNCTION_NUMBER
value|(MAX_NUM_PFS + E4_MAX_NUM_VFS)
end_define

begin_define
define|#
directive|define
name|MAX_NUM_VPORTS_K2
value|(208)
end_define

begin_define
define|#
directive|define
name|MAX_NUM_VPORTS_BB
value|(160)
end_define

begin_define
define|#
directive|define
name|MAX_NUM_VPORTS
value|(MAX_NUM_VPORTS_K2)
end_define

begin_define
define|#
directive|define
name|MAX_NUM_L2_QUEUES_K2
value|(320)
end_define

begin_define
define|#
directive|define
name|MAX_NUM_L2_QUEUES_BB
value|(256)
end_define

begin_define
define|#
directive|define
name|MAX_NUM_L2_QUEUES
value|(MAX_NUM_L2_QUEUES_K2)
end_define

begin_comment
comment|/* Traffic classes in network-facing blocks (PBF, BTB, NIG, BRB, PRS and QM) */
end_comment

begin_comment
comment|// 4-Port K2.
end_comment

begin_define
define|#
directive|define
name|NUM_PHYS_TCS_4PORT_K2
value|(4)
end_define

begin_define
define|#
directive|define
name|NUM_OF_PHYS_TCS
value|(8)
end_define

begin_define
define|#
directive|define
name|NUM_TCS_4PORT_K2
value|(NUM_PHYS_TCS_4PORT_K2 + 1)
end_define

begin_define
define|#
directive|define
name|NUM_OF_TCS
value|(NUM_OF_PHYS_TCS + 1)
end_define

begin_define
define|#
directive|define
name|LB_TC
value|(NUM_OF_PHYS_TCS)
end_define

begin_comment
comment|/* Num of possible traffic priority values */
end_comment

begin_define
define|#
directive|define
name|NUM_OF_PRIO
value|(8)
end_define

begin_define
define|#
directive|define
name|MAX_NUM_VOQS_K2
value|(NUM_TCS_4PORT_K2 * MAX_NUM_PORTS_K2)
end_define

begin_define
define|#
directive|define
name|MAX_NUM_VOQS_BB
value|(NUM_OF_TCS * MAX_NUM_PORTS_BB)
end_define

begin_define
define|#
directive|define
name|MAX_NUM_VOQS
value|(MAX_NUM_VOQS_K2)
end_define

begin_define
define|#
directive|define
name|MAX_PHYS_VOQS
value|(NUM_OF_PHYS_TCS * MAX_NUM_PORTS_BB)
end_define

begin_comment
comment|/* CIDs */
end_comment

begin_define
define|#
directive|define
name|E4_NUM_OF_CONNECTION_TYPES
value|(8)
end_define

begin_define
define|#
directive|define
name|E5_NUM_OF_CONNECTION_TYPES
value|(16)
end_define

begin_define
define|#
directive|define
name|NUM_OF_TASK_TYPES
value|(8)
end_define

begin_define
define|#
directive|define
name|NUM_OF_LCIDS
value|(320)
end_define

begin_define
define|#
directive|define
name|NUM_OF_LTIDS
value|(320)
end_define

begin_comment
comment|/* Clock values */
end_comment

begin_define
define|#
directive|define
name|MASTER_CLK_FREQ_E4
value|(375e6)
end_define

begin_define
define|#
directive|define
name|STORM_CLK_FREQ_E4
value|(1000e6)
end_define

begin_define
define|#
directive|define
name|CLK25M_CLK_FREQ_E4
value|(25e6)
end_define

begin_define
define|#
directive|define
name|STORM_CLK_DUAL_CORE_FREQ_E5
value|(3000e6)
end_define

begin_comment
comment|/* Global PXP windows (GTT) */
end_comment

begin_define
define|#
directive|define
name|NUM_OF_GTT
value|19
end_define

begin_define
define|#
directive|define
name|GTT_DWORD_SIZE_BITS
value|10
end_define

begin_define
define|#
directive|define
name|GTT_BYTE_SIZE_BITS
value|(GTT_DWORD_SIZE_BITS + 2)
end_define

begin_define
define|#
directive|define
name|GTT_DWORD_SIZE
value|(1<< GTT_DWORD_SIZE_BITS)
end_define

begin_comment
comment|/* Tools Version */
end_comment

begin_define
define|#
directive|define
name|TOOLS_VERSION
value|10
end_define

begin_comment
comment|/*****************/
end_comment

begin_comment
comment|/* CDU CONSTANTS */
end_comment

begin_comment
comment|/*****************/
end_comment

begin_define
define|#
directive|define
name|CDU_SEG_TYPE_OFFSET_REG_TYPE_SHIFT
value|(17)
end_define

begin_define
define|#
directive|define
name|CDU_SEG_TYPE_OFFSET_REG_OFFSET_MASK
value|(0x1ffff)
end_define

begin_define
define|#
directive|define
name|CDU_VF_FL_SEG_TYPE_OFFSET_REG_TYPE_SHIFT
value|(12)
end_define

begin_define
define|#
directive|define
name|CDU_VF_FL_SEG_TYPE_OFFSET_REG_OFFSET_MASK
value|(0xfff)
end_define

begin_define
define|#
directive|define
name|CDU_CONTEXT_VALIDATION_CFG_ENABLE_SHIFT
value|(0)
end_define

begin_define
define|#
directive|define
name|CDU_CONTEXT_VALIDATION_CFG_VALIDATION_TYPE_SHIFT
value|(1)
end_define

begin_define
define|#
directive|define
name|CDU_CONTEXT_VALIDATION_CFG_USE_TYPE
value|(2)
end_define

begin_define
define|#
directive|define
name|CDU_CONTEXT_VALIDATION_CFG_USE_REGION
value|(3)
end_define

begin_define
define|#
directive|define
name|CDU_CONTEXT_VALIDATION_CFG_USE_CID
value|(4)
end_define

begin_define
define|#
directive|define
name|CDU_CONTEXT_VALIDATION_CFG_USE_ACTIVE
value|(5)
end_define

begin_comment
comment|/*****************/
end_comment

begin_comment
comment|/* DQ CONSTANTS  */
end_comment

begin_comment
comment|/*****************/
end_comment

begin_comment
comment|/* DEMS */
end_comment

begin_define
define|#
directive|define
name|DQ_DEMS_LEGACY
value|0
end_define

begin_define
define|#
directive|define
name|DQ_DEMS_TOE_MORE_TO_SEND
value|3
end_define

begin_define
define|#
directive|define
name|DQ_DEMS_TOE_LOCAL_ADV_WND
value|4
end_define

begin_define
define|#
directive|define
name|DQ_DEMS_ROCE_CQ_CONS
value|7
end_define

begin_comment
comment|/* XCM agg val selection (HW) */
end_comment

begin_define
define|#
directive|define
name|DQ_XCM_AGG_VAL_SEL_WORD2
value|0
end_define

begin_define
define|#
directive|define
name|DQ_XCM_AGG_VAL_SEL_WORD3
value|1
end_define

begin_define
define|#
directive|define
name|DQ_XCM_AGG_VAL_SEL_WORD4
value|2
end_define

begin_define
define|#
directive|define
name|DQ_XCM_AGG_VAL_SEL_WORD5
value|3
end_define

begin_define
define|#
directive|define
name|DQ_XCM_AGG_VAL_SEL_REG3
value|4
end_define

begin_define
define|#
directive|define
name|DQ_XCM_AGG_VAL_SEL_REG4
value|5
end_define

begin_define
define|#
directive|define
name|DQ_XCM_AGG_VAL_SEL_REG5
value|6
end_define

begin_define
define|#
directive|define
name|DQ_XCM_AGG_VAL_SEL_REG6
value|7
end_define

begin_comment
comment|/* XCM agg val selection (FW) */
end_comment

begin_define
define|#
directive|define
name|DQ_XCM_CORE_TX_BD_CONS_CMD
value|DQ_XCM_AGG_VAL_SEL_WORD3
end_define

begin_define
define|#
directive|define
name|DQ_XCM_CORE_TX_BD_PROD_CMD
value|DQ_XCM_AGG_VAL_SEL_WORD4
end_define

begin_define
define|#
directive|define
name|DQ_XCM_CORE_SPQ_PROD_CMD
value|DQ_XCM_AGG_VAL_SEL_WORD4
end_define

begin_define
define|#
directive|define
name|DQ_XCM_ETH_EDPM_NUM_BDS_CMD
value|DQ_XCM_AGG_VAL_SEL_WORD2
end_define

begin_define
define|#
directive|define
name|DQ_XCM_ETH_TX_BD_CONS_CMD
value|DQ_XCM_AGG_VAL_SEL_WORD3
end_define

begin_define
define|#
directive|define
name|DQ_XCM_ETH_TX_BD_PROD_CMD
value|DQ_XCM_AGG_VAL_SEL_WORD4
end_define

begin_define
define|#
directive|define
name|DQ_XCM_ETH_GO_TO_BD_CONS_CMD
value|DQ_XCM_AGG_VAL_SEL_WORD5
end_define

begin_define
define|#
directive|define
name|DQ_XCM_FCOE_SQ_CONS_CMD
value|DQ_XCM_AGG_VAL_SEL_WORD3
end_define

begin_define
define|#
directive|define
name|DQ_XCM_FCOE_SQ_PROD_CMD
value|DQ_XCM_AGG_VAL_SEL_WORD4
end_define

begin_define
define|#
directive|define
name|DQ_XCM_FCOE_X_FERQ_PROD_CMD
value|DQ_XCM_AGG_VAL_SEL_WORD5
end_define

begin_define
define|#
directive|define
name|DQ_XCM_ISCSI_SQ_CONS_CMD
value|DQ_XCM_AGG_VAL_SEL_WORD3
end_define

begin_define
define|#
directive|define
name|DQ_XCM_ISCSI_SQ_PROD_CMD
value|DQ_XCM_AGG_VAL_SEL_WORD4
end_define

begin_define
define|#
directive|define
name|DQ_XCM_ISCSI_MORE_TO_SEND_SEQ_CMD
value|DQ_XCM_AGG_VAL_SEL_REG3
end_define

begin_define
define|#
directive|define
name|DQ_XCM_ISCSI_EXP_STAT_SN_CMD
value|DQ_XCM_AGG_VAL_SEL_REG6
end_define

begin_define
define|#
directive|define
name|DQ_XCM_ROCE_SQ_PROD_CMD
value|DQ_XCM_AGG_VAL_SEL_WORD4
end_define

begin_define
define|#
directive|define
name|DQ_XCM_TOE_TX_BD_PROD_CMD
value|DQ_XCM_AGG_VAL_SEL_WORD4
end_define

begin_define
define|#
directive|define
name|DQ_XCM_TOE_MORE_TO_SEND_SEQ_CMD
value|DQ_XCM_AGG_VAL_SEL_REG3
end_define

begin_define
define|#
directive|define
name|DQ_XCM_TOE_LOCAL_ADV_WND_SEQ_CMD
value|DQ_XCM_AGG_VAL_SEL_REG4
end_define

begin_comment
comment|/* UCM agg val selection (HW) */
end_comment

begin_define
define|#
directive|define
name|DQ_UCM_AGG_VAL_SEL_WORD0
value|0
end_define

begin_define
define|#
directive|define
name|DQ_UCM_AGG_VAL_SEL_WORD1
value|1
end_define

begin_define
define|#
directive|define
name|DQ_UCM_AGG_VAL_SEL_WORD2
value|2
end_define

begin_define
define|#
directive|define
name|DQ_UCM_AGG_VAL_SEL_WORD3
value|3
end_define

begin_define
define|#
directive|define
name|DQ_UCM_AGG_VAL_SEL_REG0
value|4
end_define

begin_define
define|#
directive|define
name|DQ_UCM_AGG_VAL_SEL_REG1
value|5
end_define

begin_define
define|#
directive|define
name|DQ_UCM_AGG_VAL_SEL_REG2
value|6
end_define

begin_define
define|#
directive|define
name|DQ_UCM_AGG_VAL_SEL_REG3
value|7
end_define

begin_comment
comment|/* UCM agg val selection (FW) */
end_comment

begin_define
define|#
directive|define
name|DQ_UCM_ETH_PMD_TX_CONS_CMD
value|DQ_UCM_AGG_VAL_SEL_WORD2
end_define

begin_define
define|#
directive|define
name|DQ_UCM_ETH_PMD_RX_CONS_CMD
value|DQ_UCM_AGG_VAL_SEL_WORD3
end_define

begin_define
define|#
directive|define
name|DQ_UCM_ROCE_CQ_CONS_CMD
value|DQ_UCM_AGG_VAL_SEL_REG0
end_define

begin_define
define|#
directive|define
name|DQ_UCM_ROCE_CQ_PROD_CMD
value|DQ_UCM_AGG_VAL_SEL_REG2
end_define

begin_comment
comment|/* TCM agg val selection (HW) */
end_comment

begin_define
define|#
directive|define
name|DQ_TCM_AGG_VAL_SEL_WORD0
value|0
end_define

begin_define
define|#
directive|define
name|DQ_TCM_AGG_VAL_SEL_WORD1
value|1
end_define

begin_define
define|#
directive|define
name|DQ_TCM_AGG_VAL_SEL_WORD2
value|2
end_define

begin_define
define|#
directive|define
name|DQ_TCM_AGG_VAL_SEL_WORD3
value|3
end_define

begin_define
define|#
directive|define
name|DQ_TCM_AGG_VAL_SEL_REG1
value|4
end_define

begin_define
define|#
directive|define
name|DQ_TCM_AGG_VAL_SEL_REG2
value|5
end_define

begin_define
define|#
directive|define
name|DQ_TCM_AGG_VAL_SEL_REG6
value|6
end_define

begin_define
define|#
directive|define
name|DQ_TCM_AGG_VAL_SEL_REG9
value|7
end_define

begin_comment
comment|/* TCM agg val selection (FW) */
end_comment

begin_define
define|#
directive|define
name|DQ_TCM_L2B_BD_PROD_CMD
value|DQ_TCM_AGG_VAL_SEL_WORD1
end_define

begin_define
define|#
directive|define
name|DQ_TCM_ROCE_RQ_PROD_CMD
value|DQ_TCM_AGG_VAL_SEL_WORD0
end_define

begin_comment
comment|/* XCM agg counter flag selection (HW) */
end_comment

begin_define
define|#
directive|define
name|DQ_XCM_AGG_FLG_SHIFT_BIT14
value|0
end_define

begin_define
define|#
directive|define
name|DQ_XCM_AGG_FLG_SHIFT_BIT15
value|1
end_define

begin_define
define|#
directive|define
name|DQ_XCM_AGG_FLG_SHIFT_CF12
value|2
end_define

begin_define
define|#
directive|define
name|DQ_XCM_AGG_FLG_SHIFT_CF13
value|3
end_define

begin_define
define|#
directive|define
name|DQ_XCM_AGG_FLG_SHIFT_CF18
value|4
end_define

begin_define
define|#
directive|define
name|DQ_XCM_AGG_FLG_SHIFT_CF19
value|5
end_define

begin_define
define|#
directive|define
name|DQ_XCM_AGG_FLG_SHIFT_CF22
value|6
end_define

begin_define
define|#
directive|define
name|DQ_XCM_AGG_FLG_SHIFT_CF23
value|7
end_define

begin_comment
comment|/* XCM agg counter flag selection (FW) */
end_comment

begin_define
define|#
directive|define
name|DQ_XCM_CORE_DQ_CF_CMD
value|(1<< DQ_XCM_AGG_FLG_SHIFT_CF18)
end_define

begin_define
define|#
directive|define
name|DQ_XCM_CORE_TERMINATE_CMD
value|(1<< DQ_XCM_AGG_FLG_SHIFT_CF19)
end_define

begin_define
define|#
directive|define
name|DQ_XCM_CORE_SLOW_PATH_CMD
value|(1<< DQ_XCM_AGG_FLG_SHIFT_CF22)
end_define

begin_define
define|#
directive|define
name|DQ_XCM_ETH_DQ_CF_CMD
value|(1<< DQ_XCM_AGG_FLG_SHIFT_CF18)
end_define

begin_define
define|#
directive|define
name|DQ_XCM_ETH_TERMINATE_CMD
value|(1<< DQ_XCM_AGG_FLG_SHIFT_CF19)
end_define

begin_define
define|#
directive|define
name|DQ_XCM_ETH_SLOW_PATH_CMD
value|(1<< DQ_XCM_AGG_FLG_SHIFT_CF22)
end_define

begin_define
define|#
directive|define
name|DQ_XCM_ETH_TPH_EN_CMD
value|(1<< DQ_XCM_AGG_FLG_SHIFT_CF23)
end_define

begin_define
define|#
directive|define
name|DQ_XCM_FCOE_SLOW_PATH_CMD
value|(1<< DQ_XCM_AGG_FLG_SHIFT_CF22)
end_define

begin_define
define|#
directive|define
name|DQ_XCM_ISCSI_DQ_FLUSH_CMD
value|(1<< DQ_XCM_AGG_FLG_SHIFT_CF19)
end_define

begin_define
define|#
directive|define
name|DQ_XCM_ISCSI_SLOW_PATH_CMD
value|(1<< DQ_XCM_AGG_FLG_SHIFT_CF22)
end_define

begin_define
define|#
directive|define
name|DQ_XCM_ISCSI_PROC_ONLY_CLEANUP_CMD
value|(1<< DQ_XCM_AGG_FLG_SHIFT_CF23)
end_define

begin_define
define|#
directive|define
name|DQ_XCM_TOE_DQ_FLUSH_CMD
value|(1<< DQ_XCM_AGG_FLG_SHIFT_CF19)
end_define

begin_define
define|#
directive|define
name|DQ_XCM_TOE_SLOW_PATH_CMD
value|(1<< DQ_XCM_AGG_FLG_SHIFT_CF22)
end_define

begin_comment
comment|/* UCM agg counter flag selection (HW) */
end_comment

begin_define
define|#
directive|define
name|DQ_UCM_AGG_FLG_SHIFT_CF0
value|0
end_define

begin_define
define|#
directive|define
name|DQ_UCM_AGG_FLG_SHIFT_CF1
value|1
end_define

begin_define
define|#
directive|define
name|DQ_UCM_AGG_FLG_SHIFT_CF3
value|2
end_define

begin_define
define|#
directive|define
name|DQ_UCM_AGG_FLG_SHIFT_CF4
value|3
end_define

begin_define
define|#
directive|define
name|DQ_UCM_AGG_FLG_SHIFT_CF5
value|4
end_define

begin_define
define|#
directive|define
name|DQ_UCM_AGG_FLG_SHIFT_CF6
value|5
end_define

begin_define
define|#
directive|define
name|DQ_UCM_AGG_FLG_SHIFT_RULE0EN
value|6
end_define

begin_define
define|#
directive|define
name|DQ_UCM_AGG_FLG_SHIFT_RULE1EN
value|7
end_define

begin_comment
comment|/* UCM agg counter flag selection (FW) */
end_comment

begin_define
define|#
directive|define
name|DQ_UCM_ETH_PMD_TX_ARM_CMD
value|(1<< DQ_UCM_AGG_FLG_SHIFT_CF4)
end_define

begin_define
define|#
directive|define
name|DQ_UCM_ETH_PMD_RX_ARM_CMD
value|(1<< DQ_UCM_AGG_FLG_SHIFT_CF5)
end_define

begin_define
define|#
directive|define
name|DQ_UCM_ROCE_CQ_ARM_SE_CF_CMD
value|(1<< DQ_UCM_AGG_FLG_SHIFT_CF4)
end_define

begin_define
define|#
directive|define
name|DQ_UCM_ROCE_CQ_ARM_CF_CMD
value|(1<< DQ_UCM_AGG_FLG_SHIFT_CF5)
end_define

begin_define
define|#
directive|define
name|DQ_UCM_TOE_TIMER_STOP_ALL_CMD
value|(1<< DQ_UCM_AGG_FLG_SHIFT_CF3)
end_define

begin_define
define|#
directive|define
name|DQ_UCM_TOE_SLOW_PATH_CF_CMD
value|(1<< DQ_UCM_AGG_FLG_SHIFT_CF4)
end_define

begin_define
define|#
directive|define
name|DQ_UCM_TOE_DQ_CF_CMD
value|(1<< DQ_UCM_AGG_FLG_SHIFT_CF5)
end_define

begin_comment
comment|/* TCM agg counter flag selection (HW) */
end_comment

begin_define
define|#
directive|define
name|DQ_TCM_AGG_FLG_SHIFT_CF0
value|0
end_define

begin_define
define|#
directive|define
name|DQ_TCM_AGG_FLG_SHIFT_CF1
value|1
end_define

begin_define
define|#
directive|define
name|DQ_TCM_AGG_FLG_SHIFT_CF2
value|2
end_define

begin_define
define|#
directive|define
name|DQ_TCM_AGG_FLG_SHIFT_CF3
value|3
end_define

begin_define
define|#
directive|define
name|DQ_TCM_AGG_FLG_SHIFT_CF4
value|4
end_define

begin_define
define|#
directive|define
name|DQ_TCM_AGG_FLG_SHIFT_CF5
value|5
end_define

begin_define
define|#
directive|define
name|DQ_TCM_AGG_FLG_SHIFT_CF6
value|6
end_define

begin_define
define|#
directive|define
name|DQ_TCM_AGG_FLG_SHIFT_CF7
value|7
end_define

begin_comment
comment|/* TCM agg counter flag selection (FW) */
end_comment

begin_define
define|#
directive|define
name|DQ_TCM_FCOE_FLUSH_Q0_CMD
value|(1<< DQ_TCM_AGG_FLG_SHIFT_CF1)
end_define

begin_define
define|#
directive|define
name|DQ_TCM_FCOE_DUMMY_TIMER_CMD
value|(1<< DQ_TCM_AGG_FLG_SHIFT_CF2)
end_define

begin_define
define|#
directive|define
name|DQ_TCM_FCOE_TIMER_STOP_ALL_CMD
value|(1<< DQ_TCM_AGG_FLG_SHIFT_CF3)
end_define

begin_define
define|#
directive|define
name|DQ_TCM_ISCSI_FLUSH_Q0_CMD
value|(1<< DQ_TCM_AGG_FLG_SHIFT_CF1)
end_define

begin_define
define|#
directive|define
name|DQ_TCM_ISCSI_TIMER_STOP_ALL_CMD
value|(1<< DQ_TCM_AGG_FLG_SHIFT_CF3)
end_define

begin_define
define|#
directive|define
name|DQ_TCM_TOE_FLUSH_Q0_CMD
value|(1<< DQ_TCM_AGG_FLG_SHIFT_CF1)
end_define

begin_define
define|#
directive|define
name|DQ_TCM_TOE_TIMER_STOP_ALL_CMD
value|(1<< DQ_TCM_AGG_FLG_SHIFT_CF3)
end_define

begin_define
define|#
directive|define
name|DQ_TCM_IWARP_POST_RQ_CF_CMD
value|(1<< DQ_TCM_AGG_FLG_SHIFT_CF1)
end_define

begin_comment
comment|/* PWM address mapping */
end_comment

begin_define
define|#
directive|define
name|DQ_PWM_OFFSET_DPM_BASE
value|0x0
end_define

begin_define
define|#
directive|define
name|DQ_PWM_OFFSET_DPM_END
value|0x27
end_define

begin_define
define|#
directive|define
name|DQ_PWM_OFFSET_XCM16_BASE
value|0x40
end_define

begin_define
define|#
directive|define
name|DQ_PWM_OFFSET_XCM32_BASE
value|0x44
end_define

begin_define
define|#
directive|define
name|DQ_PWM_OFFSET_UCM16_BASE
value|0x48
end_define

begin_define
define|#
directive|define
name|DQ_PWM_OFFSET_UCM32_BASE
value|0x4C
end_define

begin_define
define|#
directive|define
name|DQ_PWM_OFFSET_UCM16_4
value|0x50
end_define

begin_define
define|#
directive|define
name|DQ_PWM_OFFSET_TCM16_BASE
value|0x58
end_define

begin_define
define|#
directive|define
name|DQ_PWM_OFFSET_TCM32_BASE
value|0x5C
end_define

begin_define
define|#
directive|define
name|DQ_PWM_OFFSET_XCM_FLAGS
value|0x68
end_define

begin_define
define|#
directive|define
name|DQ_PWM_OFFSET_UCM_FLAGS
value|0x69
end_define

begin_define
define|#
directive|define
name|DQ_PWM_OFFSET_TCM_FLAGS
value|0x6B
end_define

begin_define
define|#
directive|define
name|DQ_PWM_OFFSET_XCM_RDMA_SQ_PROD
value|(DQ_PWM_OFFSET_XCM16_BASE + 2)
end_define

begin_define
define|#
directive|define
name|DQ_PWM_OFFSET_UCM_RDMA_CQ_CONS_32BIT
value|(DQ_PWM_OFFSET_UCM32_BASE)
end_define

begin_define
define|#
directive|define
name|DQ_PWM_OFFSET_UCM_RDMA_CQ_CONS_16BIT
value|(DQ_PWM_OFFSET_UCM16_4)
end_define

begin_define
define|#
directive|define
name|DQ_PWM_OFFSET_UCM_RDMA_INT_TIMEOUT
value|(DQ_PWM_OFFSET_UCM16_BASE + 2)
end_define

begin_define
define|#
directive|define
name|DQ_PWM_OFFSET_UCM_RDMA_ARM_FLAGS
value|(DQ_PWM_OFFSET_UCM_FLAGS)
end_define

begin_define
define|#
directive|define
name|DQ_PWM_OFFSET_TCM_ROCE_RQ_PROD
value|(DQ_PWM_OFFSET_TCM16_BASE + 1)
end_define

begin_define
define|#
directive|define
name|DQ_PWM_OFFSET_TCM_IWARP_RQ_PROD
value|(DQ_PWM_OFFSET_TCM16_BASE + 3)
end_define

begin_define
define|#
directive|define
name|DQ_REGION_SHIFT
value|(12)
end_define

begin_comment
comment|/* DPM */
end_comment

begin_define
define|#
directive|define
name|DQ_DPM_WQE_BUFF_SIZE
value|(320)
end_define

begin_comment
comment|// Conn type ranges
end_comment

begin_define
define|#
directive|define
name|DQ_CONN_TYPE_RANGE_SHIFT
value|(4)
end_define

begin_comment
comment|/*****************/
end_comment

begin_comment
comment|/* QM CONSTANTS  */
end_comment

begin_comment
comment|/*****************/
end_comment

begin_comment
comment|/* number of TX queues in the QM */
end_comment

begin_define
define|#
directive|define
name|MAX_QM_TX_QUEUES_K2
value|512
end_define

begin_define
define|#
directive|define
name|MAX_QM_TX_QUEUES_BB
value|448
end_define

begin_define
define|#
directive|define
name|MAX_QM_TX_QUEUES
value|MAX_QM_TX_QUEUES_K2
end_define

begin_comment
comment|/* number of Other queues in the QM */
end_comment

begin_define
define|#
directive|define
name|MAX_QM_OTHER_QUEUES_BB
value|64
end_define

begin_define
define|#
directive|define
name|MAX_QM_OTHER_QUEUES_K2
value|128
end_define

begin_define
define|#
directive|define
name|MAX_QM_OTHER_QUEUES
value|MAX_QM_OTHER_QUEUES_K2
end_define

begin_comment
comment|/* number of queues in a PF queue group */
end_comment

begin_define
define|#
directive|define
name|QM_PF_QUEUE_GROUP_SIZE
value|8
end_define

begin_comment
comment|/* the size of a single queue element in bytes */
end_comment

begin_define
define|#
directive|define
name|QM_PQ_ELEMENT_SIZE
value|4
end_define

begin_comment
comment|/* base number of Tx PQs in the CM PQ representation.    should be used when storing PQ IDs in CM PQ registers and context */
end_comment

begin_define
define|#
directive|define
name|CM_TX_PQ_BASE
value|0x200
end_define

begin_comment
comment|/* number of global Vport/QCN rate limiters */
end_comment

begin_define
define|#
directive|define
name|MAX_QM_GLOBAL_RLS
value|256
end_define

begin_comment
comment|/* QM registers data */
end_comment

begin_define
define|#
directive|define
name|QM_LINE_CRD_REG_WIDTH
value|16
end_define

begin_define
define|#
directive|define
name|QM_LINE_CRD_REG_SIGN_BIT
value|(1<< (QM_LINE_CRD_REG_WIDTH - 1))
end_define

begin_define
define|#
directive|define
name|QM_BYTE_CRD_REG_WIDTH
value|24
end_define

begin_define
define|#
directive|define
name|QM_BYTE_CRD_REG_SIGN_BIT
value|(1<< (QM_BYTE_CRD_REG_WIDTH - 1))
end_define

begin_define
define|#
directive|define
name|QM_WFQ_CRD_REG_WIDTH
value|32
end_define

begin_define
define|#
directive|define
name|QM_WFQ_CRD_REG_SIGN_BIT
value|(1<< (QM_WFQ_CRD_REG_WIDTH - 1))
end_define

begin_define
define|#
directive|define
name|QM_RL_CRD_REG_WIDTH
value|32
end_define

begin_define
define|#
directive|define
name|QM_RL_CRD_REG_SIGN_BIT
value|(1<< (QM_RL_CRD_REG_WIDTH - 1))
end_define

begin_comment
comment|/*****************/
end_comment

begin_comment
comment|/* CAU CONSTANTS */
end_comment

begin_comment
comment|/*****************/
end_comment

begin_define
define|#
directive|define
name|CAU_FSM_ETH_RX
value|0
end_define

begin_define
define|#
directive|define
name|CAU_FSM_ETH_TX
value|1
end_define

begin_comment
comment|/* Number of Protocol Indices per Status Block */
end_comment

begin_define
define|#
directive|define
name|PIS_PER_SB
value|12
end_define

begin_define
define|#
directive|define
name|CAU_HC_STOPPED_STATE
value|3
end_define

begin_comment
comment|/* fsm is stopped or not valid for this sb */
end_comment

begin_define
define|#
directive|define
name|CAU_HC_DISABLE_STATE
value|4
end_define

begin_comment
comment|/* fsm is working without interrupt coalescing for this sb*/
end_comment

begin_define
define|#
directive|define
name|CAU_HC_ENABLE_STATE
value|0
end_define

begin_comment
comment|/* fsm is working with interrupt coalescing for this sb*/
end_comment

begin_comment
comment|/*****************/
end_comment

begin_comment
comment|/* IGU CONSTANTS */
end_comment

begin_comment
comment|/*****************/
end_comment

begin_define
define|#
directive|define
name|MAX_SB_PER_PATH_K2
value|(368)
end_define

begin_define
define|#
directive|define
name|MAX_SB_PER_PATH_BB
value|(288)
end_define

begin_define
define|#
directive|define
name|MAX_TOT_SB_PER_PATH
value|MAX_SB_PER_PATH_K2
end_define

begin_define
define|#
directive|define
name|MAX_SB_PER_PF_MIMD
value|129
end_define

begin_define
define|#
directive|define
name|MAX_SB_PER_PF_SIMD
value|64
end_define

begin_define
define|#
directive|define
name|MAX_SB_PER_VF
value|64
end_define

begin_comment
comment|/* Memory addresses on the BAR for the IGU Sub Block */
end_comment

begin_define
define|#
directive|define
name|IGU_MEM_BASE
value|0x0000
end_define

begin_define
define|#
directive|define
name|IGU_MEM_MSIX_BASE
value|0x0000
end_define

begin_define
define|#
directive|define
name|IGU_MEM_MSIX_UPPER
value|0x0101
end_define

begin_define
define|#
directive|define
name|IGU_MEM_MSIX_RESERVED_UPPER
value|0x01ff
end_define

begin_define
define|#
directive|define
name|IGU_MEM_PBA_MSIX_BASE
value|0x0200
end_define

begin_define
define|#
directive|define
name|IGU_MEM_PBA_MSIX_UPPER
value|0x0202
end_define

begin_define
define|#
directive|define
name|IGU_MEM_PBA_MSIX_RESERVED_UPPER
value|0x03ff
end_define

begin_define
define|#
directive|define
name|IGU_CMD_INT_ACK_BASE
value|0x0400
end_define

begin_define
define|#
directive|define
name|IGU_CMD_INT_ACK_UPPER
value|(IGU_CMD_INT_ACK_BASE + MAX_TOT_SB_PER_PATH - 1)
end_define

begin_define
define|#
directive|define
name|IGU_CMD_INT_ACK_RESERVED_UPPER
value|0x05ff
end_define

begin_define
define|#
directive|define
name|IGU_CMD_ATTN_BIT_UPD_UPPER
value|0x05f0
end_define

begin_define
define|#
directive|define
name|IGU_CMD_ATTN_BIT_SET_UPPER
value|0x05f1
end_define

begin_define
define|#
directive|define
name|IGU_CMD_ATTN_BIT_CLR_UPPER
value|0x05f2
end_define

begin_define
define|#
directive|define
name|IGU_REG_SISR_MDPC_WMASK_UPPER
value|0x05f3
end_define

begin_define
define|#
directive|define
name|IGU_REG_SISR_MDPC_WMASK_LSB_UPPER
value|0x05f4
end_define

begin_define
define|#
directive|define
name|IGU_REG_SISR_MDPC_WMASK_MSB_UPPER
value|0x05f5
end_define

begin_define
define|#
directive|define
name|IGU_REG_SISR_MDPC_WOMASK_UPPER
value|0x05f6
end_define

begin_define
define|#
directive|define
name|IGU_CMD_PROD_UPD_BASE
value|0x0600
end_define

begin_define
define|#
directive|define
name|IGU_CMD_PROD_UPD_UPPER
value|(IGU_CMD_PROD_UPD_BASE + MAX_TOT_SB_PER_PATH  - 1)
end_define

begin_define
define|#
directive|define
name|IGU_CMD_PROD_UPD_RESERVED_UPPER
value|0x07ff
end_define

begin_comment
comment|/*****************/
end_comment

begin_comment
comment|/* PXP CONSTANTS */
end_comment

begin_comment
comment|/*****************/
end_comment

begin_comment
comment|/* Bars for Blocks */
end_comment

begin_define
define|#
directive|define
name|PXP_BAR_GRC
value|0
end_define

begin_define
define|#
directive|define
name|PXP_BAR_TSDM
value|0
end_define

begin_define
define|#
directive|define
name|PXP_BAR_USDM
value|0
end_define

begin_define
define|#
directive|define
name|PXP_BAR_XSDM
value|0
end_define

begin_define
define|#
directive|define
name|PXP_BAR_MSDM
value|0
end_define

begin_define
define|#
directive|define
name|PXP_BAR_YSDM
value|0
end_define

begin_define
define|#
directive|define
name|PXP_BAR_PSDM
value|0
end_define

begin_define
define|#
directive|define
name|PXP_BAR_IGU
value|0
end_define

begin_define
define|#
directive|define
name|PXP_BAR_DQ
value|1
end_define

begin_comment
comment|/* PTT and GTT */
end_comment

begin_define
define|#
directive|define
name|PXP_PER_PF_ENTRY_SIZE
value|8
end_define

begin_define
define|#
directive|define
name|PXP_NUM_GLOBAL_WINDOWS
value|243
end_define

begin_define
define|#
directive|define
name|PXP_GLOBAL_ENTRY_SIZE
value|4
end_define

begin_define
define|#
directive|define
name|PXP_ADMIN_WINDOW_ALLOWED_LENGTH
value|4
end_define

begin_define
define|#
directive|define
name|PXP_PF_WINDOW_ADMIN_START
value|0
end_define

begin_define
define|#
directive|define
name|PXP_PF_WINDOW_ADMIN_LENGTH
value|0x1000
end_define

begin_define
define|#
directive|define
name|PXP_PF_WINDOW_ADMIN_END
value|(PXP_PF_WINDOW_ADMIN_START + PXP_PF_WINDOW_ADMIN_LENGTH - 1)
end_define

begin_define
define|#
directive|define
name|PXP_PF_WINDOW_ADMIN_PER_PF_START
value|0
end_define

begin_define
define|#
directive|define
name|PXP_PF_WINDOW_ADMIN_PER_PF_LENGTH
value|(PXP_NUM_PF_WINDOWS * PXP_PER_PF_ENTRY_SIZE)
end_define

begin_define
define|#
directive|define
name|PXP_PF_WINDOW_ADMIN_PER_PF_END
value|(PXP_PF_WINDOW_ADMIN_PER_PF_START + PXP_PF_WINDOW_ADMIN_PER_PF_LENGTH - 1)
end_define

begin_define
define|#
directive|define
name|PXP_PF_WINDOW_ADMIN_GLOBAL_START
value|0x200
end_define

begin_define
define|#
directive|define
name|PXP_PF_WINDOW_ADMIN_GLOBAL_LENGTH
value|(PXP_NUM_GLOBAL_WINDOWS * PXP_GLOBAL_ENTRY_SIZE)
end_define

begin_define
define|#
directive|define
name|PXP_PF_WINDOW_ADMIN_GLOBAL_END
value|(PXP_PF_WINDOW_ADMIN_GLOBAL_START + PXP_PF_WINDOW_ADMIN_GLOBAL_LENGTH - 1)
end_define

begin_define
define|#
directive|define
name|PXP_PF_GLOBAL_PRETEND_ADDR
value|0x1f0
end_define

begin_define
define|#
directive|define
name|PXP_PF_ME_OPAQUE_MASK_ADDR
value|0xf4
end_define

begin_define
define|#
directive|define
name|PXP_PF_ME_OPAQUE_ADDR
value|0x1f8
end_define

begin_define
define|#
directive|define
name|PXP_PF_ME_CONCRETE_ADDR
value|0x1fc
end_define

begin_define
define|#
directive|define
name|PXP_NUM_PF_WINDOWS
value|12
end_define

begin_define
define|#
directive|define
name|PXP_EXTERNAL_BAR_PF_WINDOW_START
value|0x1000
end_define

begin_define
define|#
directive|define
name|PXP_EXTERNAL_BAR_PF_WINDOW_NUM
value|PXP_NUM_PF_WINDOWS
end_define

begin_define
define|#
directive|define
name|PXP_EXTERNAL_BAR_PF_WINDOW_SINGLE_SIZE
value|0x1000
end_define

begin_define
define|#
directive|define
name|PXP_EXTERNAL_BAR_PF_WINDOW_LENGTH
value|(PXP_EXTERNAL_BAR_PF_WINDOW_NUM * PXP_EXTERNAL_BAR_PF_WINDOW_SINGLE_SIZE)
end_define

begin_define
define|#
directive|define
name|PXP_EXTERNAL_BAR_PF_WINDOW_END
value|(PXP_EXTERNAL_BAR_PF_WINDOW_START + PXP_EXTERNAL_BAR_PF_WINDOW_LENGTH - 1)
end_define

begin_define
define|#
directive|define
name|PXP_EXTERNAL_BAR_GLOBAL_WINDOW_START
value|(PXP_EXTERNAL_BAR_PF_WINDOW_END + 1)
end_define

begin_define
define|#
directive|define
name|PXP_EXTERNAL_BAR_GLOBAL_WINDOW_NUM
value|PXP_NUM_GLOBAL_WINDOWS
end_define

begin_define
define|#
directive|define
name|PXP_EXTERNAL_BAR_GLOBAL_WINDOW_SINGLE_SIZE
value|0x1000
end_define

begin_define
define|#
directive|define
name|PXP_EXTERNAL_BAR_GLOBAL_WINDOW_LENGTH
value|(PXP_EXTERNAL_BAR_GLOBAL_WINDOW_NUM * PXP_EXTERNAL_BAR_GLOBAL_WINDOW_SINGLE_SIZE)
end_define

begin_define
define|#
directive|define
name|PXP_EXTERNAL_BAR_GLOBAL_WINDOW_END
value|(PXP_EXTERNAL_BAR_GLOBAL_WINDOW_START + PXP_EXTERNAL_BAR_GLOBAL_WINDOW_LENGTH - 1)
end_define

begin_comment
comment|/* PF BAR */
end_comment

begin_define
define|#
directive|define
name|PXP_BAR0_START_GRC
value|0x0000
end_define

begin_define
define|#
directive|define
name|PXP_BAR0_GRC_LENGTH
value|0x1C00000
end_define

begin_define
define|#
directive|define
name|PXP_BAR0_END_GRC
value|(PXP_BAR0_START_GRC + PXP_BAR0_GRC_LENGTH - 1)
end_define

begin_define
define|#
directive|define
name|PXP_BAR0_START_IGU
value|0x1C00000
end_define

begin_define
define|#
directive|define
name|PXP_BAR0_IGU_LENGTH
value|0x10000
end_define

begin_define
define|#
directive|define
name|PXP_BAR0_END_IGU
value|(PXP_BAR0_START_IGU + PXP_BAR0_IGU_LENGTH - 1)
end_define

begin_define
define|#
directive|define
name|PXP_BAR0_START_TSDM
value|0x1C80000
end_define

begin_define
define|#
directive|define
name|PXP_BAR0_SDM_LENGTH
value|0x40000
end_define

begin_define
define|#
directive|define
name|PXP_BAR0_SDM_RESERVED_LENGTH
value|0x40000
end_define

begin_define
define|#
directive|define
name|PXP_BAR0_END_TSDM
value|(PXP_BAR0_START_TSDM + PXP_BAR0_SDM_LENGTH - 1)
end_define

begin_define
define|#
directive|define
name|PXP_BAR0_START_MSDM
value|0x1D00000
end_define

begin_define
define|#
directive|define
name|PXP_BAR0_END_MSDM
value|(PXP_BAR0_START_MSDM + PXP_BAR0_SDM_LENGTH - 1)
end_define

begin_define
define|#
directive|define
name|PXP_BAR0_START_USDM
value|0x1D80000
end_define

begin_define
define|#
directive|define
name|PXP_BAR0_END_USDM
value|(PXP_BAR0_START_USDM + PXP_BAR0_SDM_LENGTH - 1)
end_define

begin_define
define|#
directive|define
name|PXP_BAR0_START_XSDM
value|0x1E00000
end_define

begin_define
define|#
directive|define
name|PXP_BAR0_END_XSDM
value|(PXP_BAR0_START_XSDM + PXP_BAR0_SDM_LENGTH - 1)
end_define

begin_define
define|#
directive|define
name|PXP_BAR0_START_YSDM
value|0x1E80000
end_define

begin_define
define|#
directive|define
name|PXP_BAR0_END_YSDM
value|(PXP_BAR0_START_YSDM + PXP_BAR0_SDM_LENGTH - 1)
end_define

begin_define
define|#
directive|define
name|PXP_BAR0_START_PSDM
value|0x1F00000
end_define

begin_define
define|#
directive|define
name|PXP_BAR0_END_PSDM
value|(PXP_BAR0_START_PSDM + PXP_BAR0_SDM_LENGTH - 1)
end_define

begin_define
define|#
directive|define
name|PXP_BAR0_FIRST_INVALID_ADDRESS
value|(PXP_BAR0_END_PSDM + 1)
end_define

begin_comment
comment|/* VF BAR */
end_comment

begin_define
define|#
directive|define
name|PXP_VF_BAR0
value|0
end_define

begin_define
define|#
directive|define
name|PXP_VF_BAR0_START_GRC
value|0x3E00
end_define

begin_define
define|#
directive|define
name|PXP_VF_BAR0_GRC_LENGTH
value|0x200
end_define

begin_define
define|#
directive|define
name|PXP_VF_BAR0_END_GRC
value|(PXP_VF_BAR0_START_GRC + PXP_VF_BAR0_GRC_LENGTH - 1)
end_define

begin_define
define|#
directive|define
name|PXP_VF_BAR0_START_IGU
value|0
end_define

begin_define
define|#
directive|define
name|PXP_VF_BAR0_IGU_LENGTH
value|0x3000
end_define

begin_define
define|#
directive|define
name|PXP_VF_BAR0_END_IGU
value|(PXP_VF_BAR0_START_IGU + PXP_VF_BAR0_IGU_LENGTH - 1)
end_define

begin_define
define|#
directive|define
name|PXP_VF_BAR0_START_DQ
value|0x3000
end_define

begin_define
define|#
directive|define
name|PXP_VF_BAR0_DQ_LENGTH
value|0x200
end_define

begin_define
define|#
directive|define
name|PXP_VF_BAR0_DQ_OPAQUE_OFFSET
value|0
end_define

begin_define
define|#
directive|define
name|PXP_VF_BAR0_ME_OPAQUE_ADDRESS
value|(PXP_VF_BAR0_START_DQ + PXP_VF_BAR0_DQ_OPAQUE_OFFSET)
end_define

begin_define
define|#
directive|define
name|PXP_VF_BAR0_ME_CONCRETE_ADDRESS
value|(PXP_VF_BAR0_ME_OPAQUE_ADDRESS + 4)
end_define

begin_define
define|#
directive|define
name|PXP_VF_BAR0_END_DQ
value|(PXP_VF_BAR0_START_DQ + PXP_VF_BAR0_DQ_LENGTH - 1)
end_define

begin_define
define|#
directive|define
name|PXP_VF_BAR0_START_TSDM_ZONE_B
value|0x3200
end_define

begin_define
define|#
directive|define
name|PXP_VF_BAR0_SDM_LENGTH_ZONE_B
value|0x200
end_define

begin_define
define|#
directive|define
name|PXP_VF_BAR0_END_TSDM_ZONE_B
value|(PXP_VF_BAR0_START_TSDM_ZONE_B + PXP_VF_BAR0_SDM_LENGTH_ZONE_B - 1)
end_define

begin_define
define|#
directive|define
name|PXP_VF_BAR0_START_MSDM_ZONE_B
value|0x3400
end_define

begin_define
define|#
directive|define
name|PXP_VF_BAR0_END_MSDM_ZONE_B
value|(PXP_VF_BAR0_START_MSDM_ZONE_B + PXP_VF_BAR0_SDM_LENGTH_ZONE_B - 1)
end_define

begin_define
define|#
directive|define
name|PXP_VF_BAR0_START_USDM_ZONE_B
value|0x3600
end_define

begin_define
define|#
directive|define
name|PXP_VF_BAR0_END_USDM_ZONE_B
value|(PXP_VF_BAR0_START_USDM_ZONE_B + PXP_VF_BAR0_SDM_LENGTH_ZONE_B - 1)
end_define

begin_define
define|#
directive|define
name|PXP_VF_BAR0_START_XSDM_ZONE_B
value|0x3800
end_define

begin_define
define|#
directive|define
name|PXP_VF_BAR0_END_XSDM_ZONE_B
value|(PXP_VF_BAR0_START_XSDM_ZONE_B + PXP_VF_BAR0_SDM_LENGTH_ZONE_B - 1)
end_define

begin_define
define|#
directive|define
name|PXP_VF_BAR0_START_YSDM_ZONE_B
value|0x3a00
end_define

begin_define
define|#
directive|define
name|PXP_VF_BAR0_END_YSDM_ZONE_B
value|(PXP_VF_BAR0_START_YSDM_ZONE_B + PXP_VF_BAR0_SDM_LENGTH_ZONE_B - 1)
end_define

begin_define
define|#
directive|define
name|PXP_VF_BAR0_START_PSDM_ZONE_B
value|0x3c00
end_define

begin_define
define|#
directive|define
name|PXP_VF_BAR0_END_PSDM_ZONE_B
value|(PXP_VF_BAR0_START_PSDM_ZONE_B + PXP_VF_BAR0_SDM_LENGTH_ZONE_B - 1)
end_define

begin_define
define|#
directive|define
name|PXP_VF_BAR0_START_SDM_ZONE_A
value|0x4000
end_define

begin_define
define|#
directive|define
name|PXP_VF_BAR0_END_SDM_ZONE_A
value|0x10000
end_define

begin_define
define|#
directive|define
name|PXP_VF_BAR0_GRC_WINDOW_LENGTH
value|32
end_define

begin_define
define|#
directive|define
name|PXP_ILT_PAGE_SIZE_NUM_BITS_MIN
value|12
end_define

begin_define
define|#
directive|define
name|PXP_ILT_BLOCK_FACTOR_MULTIPLIER
value|1024
end_define

begin_comment
comment|// ILT Records
end_comment

begin_define
define|#
directive|define
name|PXP_NUM_ILT_RECORDS_BB
value|7600
end_define

begin_define
define|#
directive|define
name|PXP_NUM_ILT_RECORDS_K2
value|11000
end_define

begin_define
define|#
directive|define
name|MAX_NUM_ILT_RECORDS
value|MAX(PXP_NUM_ILT_RECORDS_BB,PXP_NUM_ILT_RECORDS_K2)
end_define

begin_comment
comment|// Host Interface
end_comment

begin_define
define|#
directive|define
name|PXP_QUEUES_ZONE_MAX_NUM
value|320
end_define

begin_comment
comment|/*****************/
end_comment

begin_comment
comment|/* PRM CONSTANTS */
end_comment

begin_comment
comment|/*****************/
end_comment

begin_define
define|#
directive|define
name|PRM_DMA_PAD_BYTES_NUM
value|2
end_define

begin_comment
comment|/*****************/
end_comment

begin_comment
comment|/* SDMs CONSTANTS  */
end_comment

begin_comment
comment|/*****************/
end_comment

begin_define
define|#
directive|define
name|SDM_OP_GEN_TRIG_NONE
value|0
end_define

begin_define
define|#
directive|define
name|SDM_OP_GEN_TRIG_WAKE_THREAD
value|1
end_define

begin_define
define|#
directive|define
name|SDM_OP_GEN_TRIG_AGG_INT
value|2
end_define

begin_define
define|#
directive|define
name|SDM_OP_GEN_TRIG_LOADER
value|4
end_define

begin_define
define|#
directive|define
name|SDM_OP_GEN_TRIG_INDICATE_ERROR
value|6
end_define

begin_define
define|#
directive|define
name|SDM_OP_GEN_TRIG_INC_ORDER_CNT
value|9
end_define

begin_comment
comment|/////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|// Completion types
end_comment

begin_comment
comment|/////////////////////////////////////////////////////////////
end_comment

begin_define
define|#
directive|define
name|SDM_COMP_TYPE_NONE
value|0
end_define

begin_define
define|#
directive|define
name|SDM_COMP_TYPE_WAKE_THREAD
value|1
end_define

begin_define
define|#
directive|define
name|SDM_COMP_TYPE_AGG_INT
value|2
end_define

begin_define
define|#
directive|define
name|SDM_COMP_TYPE_CM
value|3
end_define

begin_comment
comment|// Send direct message to local CM and/or remote CMs. Destinations are defined by vector in CompParams.
end_comment

begin_define
define|#
directive|define
name|SDM_COMP_TYPE_LOADER
value|4
end_define

begin_define
define|#
directive|define
name|SDM_COMP_TYPE_PXP
value|5
end_define

begin_comment
comment|// Send direct message to PXP (like "internal write" command) to write to remote Storm RAM via remote SDM
end_comment

begin_define
define|#
directive|define
name|SDM_COMP_TYPE_INDICATE_ERROR
value|6
end_define

begin_comment
comment|// Indicate error per thread
end_comment

begin_define
define|#
directive|define
name|SDM_COMP_TYPE_RELEASE_THREAD
value|7
end_define

begin_comment
comment|// Obsolete in E5
end_comment

begin_define
define|#
directive|define
name|SDM_COMP_TYPE_RAM
value|8
end_define

begin_comment
comment|// Write to local RAM as a completion
end_comment

begin_define
define|#
directive|define
name|SDM_COMP_TYPE_INC_ORDER_CNT
value|9
end_define

begin_comment
comment|// Applicable only for E4
end_comment

begin_comment
comment|/******************/
end_comment

begin_comment
comment|/* PBF CONSTANTS  */
end_comment

begin_comment
comment|/******************/
end_comment

begin_comment
comment|/* Number of PBF command queue lines. Each line is 32B. */
end_comment

begin_define
define|#
directive|define
name|PBF_MAX_CMD_LINES
value|3328
end_define

begin_comment
comment|/* Number of BTB blocks. Each block is 256B. */
end_comment

begin_define
define|#
directive|define
name|BTB_MAX_BLOCKS
value|1440
end_define

begin_comment
comment|/*****************/
end_comment

begin_comment
comment|/* PRS CONSTANTS */
end_comment

begin_comment
comment|/*****************/
end_comment

begin_define
define|#
directive|define
name|PRS_GFT_CAM_LINES_NO_MATCH
value|31
end_define

begin_comment
comment|/*  * Async data KCQ CQE   */
end_comment

begin_struct
struct|struct
name|async_data
block|{
name|__le32
name|cid
comment|/* Context ID of the connection */
decl_stmt|;
name|__le16
name|itid
comment|/* Task Id of the task (for error that happened on a a task) */
decl_stmt|;
name|u8
name|error_code
comment|/* error code - relevant only if the opcode indicates its an error */
decl_stmt|;
name|u8
name|fw_debug_param
comment|/* internal fw debug parameter */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Interrupt coalescing TimeSet  */
end_comment

begin_struct
struct|struct
name|coalescing_timeset
block|{
name|u8
name|value
decl_stmt|;
define|#
directive|define
name|COALESCING_TIMESET_TIMESET_MASK
value|0x7F
comment|/* Interrupt coalescing TimeSet (timeout_ticks = TimeSet shl (TimerRes+1)) */
define|#
directive|define
name|COALESCING_TIMESET_TIMESET_SHIFT
value|0
define|#
directive|define
name|COALESCING_TIMESET_VALID_MASK
value|0x1
comment|/* Only if this flag is set, timeset will take effect */
define|#
directive|define
name|COALESCING_TIMESET_VALID_SHIFT
value|7
block|}
struct|;
end_struct

begin_struct
struct|struct
name|common_queue_zone
block|{
name|__le16
name|ring_drv_data_consumer
decl_stmt|;
name|__le16
name|reserved
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * ETH Rx producers data  */
end_comment

begin_struct
struct|struct
name|eth_rx_prod_data
block|{
name|__le16
name|bd_prod
comment|/* BD producer. */
decl_stmt|;
name|__le16
name|cqe_prod
comment|/* CQE producer. */
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|regpair
block|{
name|__le32
name|lo
comment|/* low word for reg-pair */
decl_stmt|;
name|__le32
name|hi
comment|/* high word for reg-pair */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Event Ring VF-PF Channel data  */
end_comment

begin_struct
struct|struct
name|vf_pf_channel_eqe_data
block|{
name|struct
name|regpair
name|msg_addr
comment|/* VF-PF message address */
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|iscsi_eqe_data
block|{
name|__le32
name|cid
comment|/* Context ID of the connection */
decl_stmt|;
name|__le16
name|conn_id
comment|/* Task Id of the task (for error that happened on a a task) */
decl_stmt|;
name|u8
name|error_code
comment|/* error code - relevant only if the opcode indicates its an error */
decl_stmt|;
name|u8
name|error_pdu_opcode_reserved
decl_stmt|;
define|#
directive|define
name|ISCSI_EQE_DATA_ERROR_PDU_OPCODE_MASK
value|0x3F
comment|/* The processed PDUs opcode on which happened the error - updated for specific error codes, by defualt=0xFF */
define|#
directive|define
name|ISCSI_EQE_DATA_ERROR_PDU_OPCODE_SHIFT
value|0
define|#
directive|define
name|ISCSI_EQE_DATA_ERROR_PDU_OPCODE_VALID_MASK
value|0x1
comment|/* Indication for driver is the error_pdu_opcode field has valid value */
define|#
directive|define
name|ISCSI_EQE_DATA_ERROR_PDU_OPCODE_VALID_SHIFT
value|6
define|#
directive|define
name|ISCSI_EQE_DATA_RESERVED0_MASK
value|0x1
define|#
directive|define
name|ISCSI_EQE_DATA_RESERVED0_SHIFT
value|7
block|}
struct|;
end_struct

begin_comment
comment|/*  * RoCE Destroy Event Data  */
end_comment

begin_struct
struct|struct
name|rdma_eqe_destroy_qp
block|{
name|__le32
name|cid
comment|/* Dedicated field RoCE destroy QP event */
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
comment|/*  * RDMA Event Data Union  */
end_comment

begin_union
union|union
name|rdma_eqe_data
block|{
name|struct
name|regpair
name|async_handle
comment|/* Host handle for the Async Completions */
decl_stmt|;
name|struct
name|rdma_eqe_destroy_qp
name|rdma_destroy_qp_data
comment|/* RoCE Destroy Event Data */
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/*  * Event Ring malicious VF data  */
end_comment

begin_struct
struct|struct
name|malicious_vf_eqe_data
block|{
name|u8
name|vfId
comment|/* Malicious VF ID */
decl_stmt|;
name|u8
name|errId
comment|/* Malicious VF error */
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
comment|/*  * Event Ring initial cleanup data  */
end_comment

begin_struct
struct|struct
name|initial_cleanup_eqe_data
block|{
name|u8
name|vfId
comment|/* VF ID */
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
comment|/*  * Event Data Union  */
end_comment

begin_union
union|union
name|event_ring_data
block|{
name|u8
name|bytes
index|[
literal|8
index|]
comment|/* Byte Array */
decl_stmt|;
name|struct
name|vf_pf_channel_eqe_data
name|vf_pf_channel
comment|/* VF-PF Channel data */
decl_stmt|;
name|struct
name|iscsi_eqe_data
name|iscsi_info
comment|/* Dedicated fields to iscsi data */
decl_stmt|;
name|union
name|rdma_eqe_data
name|rdma_data
comment|/* Dedicated field for RDMA data */
decl_stmt|;
name|struct
name|malicious_vf_eqe_data
name|malicious_vf
comment|/* Malicious VF data */
decl_stmt|;
name|struct
name|initial_cleanup_eqe_data
name|vf_init_cleanup
comment|/* VF Initial Cleanup data */
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/*  * Event Ring Entry  */
end_comment

begin_struct
struct|struct
name|event_ring_entry
block|{
name|u8
name|protocol_id
comment|/* Event Protocol ID */
decl_stmt|;
name|u8
name|opcode
comment|/* Event Opcode */
decl_stmt|;
name|__le16
name|reserved0
comment|/* Reserved */
decl_stmt|;
name|__le16
name|echo
comment|/* Echo value from ramrod data on the host */
decl_stmt|;
name|u8
name|fw_return_code
comment|/* FW return code for SP ramrods */
decl_stmt|;
name|u8
name|flags
decl_stmt|;
define|#
directive|define
name|EVENT_RING_ENTRY_ASYNC_MASK
value|0x1
comment|/* 0: synchronous EQE - a completion of SP message. 1: asynchronous EQE */
define|#
directive|define
name|EVENT_RING_ENTRY_ASYNC_SHIFT
value|0
define|#
directive|define
name|EVENT_RING_ENTRY_RESERVED1_MASK
value|0x7F
define|#
directive|define
name|EVENT_RING_ENTRY_RESERVED1_SHIFT
value|1
name|union
name|event_ring_data
name|data
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Multi function mode  */
end_comment

begin_enum
enum|enum
name|mf_mode
block|{
name|ERROR_MODE
comment|/* Unsupported mode */
block|,
name|MF_OVLAN
comment|/* Multi function based on outer VLAN */
block|,
name|MF_NPAR
comment|/* Multi function based on MAC address (NIC partitioning) */
block|,
name|MAX_MF_MODE
block|}
enum|;
end_enum

begin_comment
comment|/*  * Per-protocol connection types  */
end_comment

begin_enum
enum|enum
name|protocol_type
block|{
name|PROTOCOLID_ISCSI
comment|/* iSCSI */
block|,
name|PROTOCOLID_FCOE
comment|/* FCoE */
block|,
name|PROTOCOLID_ROCE
comment|/* RoCE */
block|,
name|PROTOCOLID_CORE
comment|/* Core (light L2, slow path core) */
block|,
name|PROTOCOLID_ETH
comment|/* Ethernet */
block|,
name|PROTOCOLID_IWARP
comment|/* iWARP */
block|,
name|PROTOCOLID_TOE
comment|/* TOE */
block|,
name|PROTOCOLID_PREROCE
comment|/* Pre (tapeout) RoCE */
block|,
name|PROTOCOLID_COMMON
comment|/* ProtocolCommon */
block|,
name|PROTOCOLID_TCP
comment|/* TCP */
block|,
name|MAX_PROTOCOL_TYPE
block|}
enum|;
end_enum

begin_comment
comment|/*  * Ustorm Queue Zone  */
end_comment

begin_struct
struct|struct
name|ustorm_eth_queue_zone
block|{
name|struct
name|coalescing_timeset
name|int_coalescing_timeset
comment|/* Rx interrupt coalescing TimeSet */
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

begin_struct
struct|struct
name|ustorm_queue_zone
block|{
name|struct
name|ustorm_eth_queue_zone
name|eth
decl_stmt|;
name|struct
name|common_queue_zone
name|common
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * status block structure  */
end_comment

begin_struct
struct|struct
name|cau_pi_entry
block|{
name|__le32
name|prod
decl_stmt|;
define|#
directive|define
name|CAU_PI_ENTRY_PROD_VAL_MASK
value|0xFFFF
comment|/* A per protocol indexPROD value. */
define|#
directive|define
name|CAU_PI_ENTRY_PROD_VAL_SHIFT
value|0
define|#
directive|define
name|CAU_PI_ENTRY_PI_TIMESET_MASK
value|0x7F
comment|/* This value determines the TimeSet that the PI is associated with  */
define|#
directive|define
name|CAU_PI_ENTRY_PI_TIMESET_SHIFT
value|16
define|#
directive|define
name|CAU_PI_ENTRY_FSM_SEL_MASK
value|0x1
comment|/* Select the FSM within the SB */
define|#
directive|define
name|CAU_PI_ENTRY_FSM_SEL_SHIFT
value|23
define|#
directive|define
name|CAU_PI_ENTRY_RESERVED_MASK
value|0xFF
comment|/* Select the FSM within the SB */
define|#
directive|define
name|CAU_PI_ENTRY_RESERVED_SHIFT
value|24
block|}
struct|;
end_struct

begin_comment
comment|/*  * status block structure  */
end_comment

begin_struct
struct|struct
name|cau_sb_entry
block|{
name|__le32
name|data
decl_stmt|;
define|#
directive|define
name|CAU_SB_ENTRY_SB_PROD_MASK
value|0xFFFFFF
comment|/* The SB PROD index which is sent to the IGU. */
define|#
directive|define
name|CAU_SB_ENTRY_SB_PROD_SHIFT
value|0
define|#
directive|define
name|CAU_SB_ENTRY_STATE0_MASK
value|0xF
comment|/* RX state */
define|#
directive|define
name|CAU_SB_ENTRY_STATE0_SHIFT
value|24
define|#
directive|define
name|CAU_SB_ENTRY_STATE1_MASK
value|0xF
comment|/* TX state */
define|#
directive|define
name|CAU_SB_ENTRY_STATE1_SHIFT
value|28
name|__le32
name|params
decl_stmt|;
define|#
directive|define
name|CAU_SB_ENTRY_SB_TIMESET0_MASK
value|0x7F
comment|/* Indicates the RX TimeSet that this SB is associated with. */
define|#
directive|define
name|CAU_SB_ENTRY_SB_TIMESET0_SHIFT
value|0
define|#
directive|define
name|CAU_SB_ENTRY_SB_TIMESET1_MASK
value|0x7F
comment|/* Indicates the TX TimeSet that this SB is associated with. */
define|#
directive|define
name|CAU_SB_ENTRY_SB_TIMESET1_SHIFT
value|7
define|#
directive|define
name|CAU_SB_ENTRY_TIMER_RES0_MASK
value|0x3
comment|/* This value will determine the RX FSM timer resolution in ticks  */
define|#
directive|define
name|CAU_SB_ENTRY_TIMER_RES0_SHIFT
value|14
define|#
directive|define
name|CAU_SB_ENTRY_TIMER_RES1_MASK
value|0x3
comment|/* This value will determine the TX FSM timer resolution in ticks  */
define|#
directive|define
name|CAU_SB_ENTRY_TIMER_RES1_SHIFT
value|16
define|#
directive|define
name|CAU_SB_ENTRY_VF_NUMBER_MASK
value|0xFF
define|#
directive|define
name|CAU_SB_ENTRY_VF_NUMBER_SHIFT
value|18
define|#
directive|define
name|CAU_SB_ENTRY_VF_VALID_MASK
value|0x1
define|#
directive|define
name|CAU_SB_ENTRY_VF_VALID_SHIFT
value|26
define|#
directive|define
name|CAU_SB_ENTRY_PF_NUMBER_MASK
value|0xF
define|#
directive|define
name|CAU_SB_ENTRY_PF_NUMBER_SHIFT
value|27
define|#
directive|define
name|CAU_SB_ENTRY_TPH_MASK
value|0x1
comment|/* If set then indicates that the TPH STAG is equal to the SB number. Otherwise the STAG will be equal to all ones. */
define|#
directive|define
name|CAU_SB_ENTRY_TPH_SHIFT
value|31
block|}
struct|;
end_struct

begin_comment
comment|/*  * core doorbell data  */
end_comment

begin_struct
struct|struct
name|core_db_data
block|{
name|u8
name|params
decl_stmt|;
define|#
directive|define
name|CORE_DB_DATA_DEST_MASK
value|0x3
comment|/* destination of doorbell (use enum db_dest) */
define|#
directive|define
name|CORE_DB_DATA_DEST_SHIFT
value|0
define|#
directive|define
name|CORE_DB_DATA_AGG_CMD_MASK
value|0x3
comment|/* aggregative command to CM (use enum db_agg_cmd_sel) */
define|#
directive|define
name|CORE_DB_DATA_AGG_CMD_SHIFT
value|2
define|#
directive|define
name|CORE_DB_DATA_BYPASS_EN_MASK
value|0x1
comment|/* enable QM bypass */
define|#
directive|define
name|CORE_DB_DATA_BYPASS_EN_SHIFT
value|4
define|#
directive|define
name|CORE_DB_DATA_RESERVED_MASK
value|0x1
define|#
directive|define
name|CORE_DB_DATA_RESERVED_SHIFT
value|5
define|#
directive|define
name|CORE_DB_DATA_AGG_VAL_SEL_MASK
value|0x3
comment|/* aggregative value selection */
define|#
directive|define
name|CORE_DB_DATA_AGG_VAL_SEL_SHIFT
value|6
name|u8
name|agg_flags
comment|/* bit for every DQ counter flags in CM context that DQ can increment */
decl_stmt|;
name|__le16
name|spq_prod
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Enum of doorbell aggregative command selection  */
end_comment

begin_enum
enum|enum
name|db_agg_cmd_sel
block|{
name|DB_AGG_CMD_NOP
comment|/* No operation */
block|,
name|DB_AGG_CMD_SET
comment|/* Set the value */
block|,
name|DB_AGG_CMD_ADD
comment|/* Add the value */
block|,
name|DB_AGG_CMD_MAX
comment|/* Set max of current and new value */
block|,
name|MAX_DB_AGG_CMD_SEL
block|}
enum|;
end_enum

begin_comment
comment|/*  * Enum of doorbell destination  */
end_comment

begin_enum
enum|enum
name|db_dest
block|{
name|DB_DEST_XCM
comment|/* TX doorbell to XCM */
block|,
name|DB_DEST_UCM
comment|/* RX doorbell to UCM */
block|,
name|DB_DEST_TCM
comment|/* RX doorbell to TCM */
block|,
name|DB_NUM_DESTINATIONS
block|,
name|MAX_DB_DEST
block|}
enum|;
end_enum

begin_comment
comment|/*  * Enum of doorbell DPM types  */
end_comment

begin_enum
enum|enum
name|db_dpm_type
block|{
name|DPM_LEGACY
comment|/* Legacy DPM- to Xstorm RAM */
block|,
name|DPM_RDMA
comment|/* RDMA DPM (only RoCE in E4) - to NIG */
block|,
name|DPM_L2_INLINE
comment|/* L2 DPM inline- to PBF, with packet data on doorbell */
block|,
name|DPM_L2_BD
comment|/* L2 DPM with BD- to PBF, with TX BD data on doorbell */
block|,
name|MAX_DB_DPM_TYPE
block|}
enum|;
end_enum

begin_comment
comment|/*  * Structure for doorbell data, in L2 DPM mode, for the first doorbell in a DPM burst  */
end_comment

begin_struct
struct|struct
name|db_l2_dpm_data
block|{
name|__le16
name|icid
comment|/* internal CID */
decl_stmt|;
name|__le16
name|bd_prod
comment|/* bd producer value to update */
decl_stmt|;
name|__le32
name|params
decl_stmt|;
define|#
directive|define
name|DB_L2_DPM_DATA_SIZE_MASK
value|0x3F
comment|/* Size in QWORD-s of the DPM burst */
define|#
directive|define
name|DB_L2_DPM_DATA_SIZE_SHIFT
value|0
define|#
directive|define
name|DB_L2_DPM_DATA_DPM_TYPE_MASK
value|0x3
comment|/* Type of DPM transaction (DPM_L2_INLINE or DPM_L2_BD) (use enum db_dpm_type) */
define|#
directive|define
name|DB_L2_DPM_DATA_DPM_TYPE_SHIFT
value|6
define|#
directive|define
name|DB_L2_DPM_DATA_NUM_BDS_MASK
value|0xFF
comment|/* number of BD-s */
define|#
directive|define
name|DB_L2_DPM_DATA_NUM_BDS_SHIFT
value|8
define|#
directive|define
name|DB_L2_DPM_DATA_PKT_SIZE_MASK
value|0x7FF
comment|/* size of the packet to be transmitted in bytes */
define|#
directive|define
name|DB_L2_DPM_DATA_PKT_SIZE_SHIFT
value|16
define|#
directive|define
name|DB_L2_DPM_DATA_RESERVED0_MASK
value|0x1
define|#
directive|define
name|DB_L2_DPM_DATA_RESERVED0_SHIFT
value|27
define|#
directive|define
name|DB_L2_DPM_DATA_SGE_NUM_MASK
value|0x7
comment|/* In DPM_L2_BD mode: the number of SGE-s */
define|#
directive|define
name|DB_L2_DPM_DATA_SGE_NUM_SHIFT
value|28
define|#
directive|define
name|DB_L2_DPM_DATA_GFS_SRC_EN_MASK
value|0x1
comment|/* Flag indicating whether to enable GFS search */
define|#
directive|define
name|DB_L2_DPM_DATA_GFS_SRC_EN_SHIFT
value|31
block|}
struct|;
end_struct

begin_comment
comment|/*  * Structure for SGE in a DPM doorbell of type DPM_L2_BD  */
end_comment

begin_struct
struct|struct
name|db_l2_dpm_sge
block|{
name|struct
name|regpair
name|addr
comment|/* Single continuous buffer */
decl_stmt|;
name|__le16
name|nbytes
comment|/* Number of bytes in this BD. */
decl_stmt|;
name|__le16
name|bitfields
decl_stmt|;
define|#
directive|define
name|DB_L2_DPM_SGE_TPH_ST_INDEX_MASK
value|0x1FF
comment|/* The TPH STAG index value */
define|#
directive|define
name|DB_L2_DPM_SGE_TPH_ST_INDEX_SHIFT
value|0
define|#
directive|define
name|DB_L2_DPM_SGE_RESERVED0_MASK
value|0x3
define|#
directive|define
name|DB_L2_DPM_SGE_RESERVED0_SHIFT
value|9
define|#
directive|define
name|DB_L2_DPM_SGE_ST_VALID_MASK
value|0x1
comment|/* Indicate if ST hint is requested or not */
define|#
directive|define
name|DB_L2_DPM_SGE_ST_VALID_SHIFT
value|11
define|#
directive|define
name|DB_L2_DPM_SGE_RESERVED1_MASK
value|0xF
define|#
directive|define
name|DB_L2_DPM_SGE_RESERVED1_SHIFT
value|12
name|__le32
name|reserved2
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Structure for doorbell address, in legacy mode  */
end_comment

begin_struct
struct|struct
name|db_legacy_addr
block|{
name|__le32
name|addr
decl_stmt|;
define|#
directive|define
name|DB_LEGACY_ADDR_RESERVED0_MASK
value|0x3
define|#
directive|define
name|DB_LEGACY_ADDR_RESERVED0_SHIFT
value|0
define|#
directive|define
name|DB_LEGACY_ADDR_DEMS_MASK
value|0x7
comment|/* doorbell extraction mode specifier- 0 if not used */
define|#
directive|define
name|DB_LEGACY_ADDR_DEMS_SHIFT
value|2
define|#
directive|define
name|DB_LEGACY_ADDR_ICID_MASK
value|0x7FFFFFF
comment|/* internal CID */
define|#
directive|define
name|DB_LEGACY_ADDR_ICID_SHIFT
value|5
block|}
struct|;
end_struct

begin_comment
comment|/*  * Structure for doorbell address, in PWM mode  */
end_comment

begin_struct
struct|struct
name|db_pwm_addr
block|{
name|__le32
name|addr
decl_stmt|;
define|#
directive|define
name|DB_PWM_ADDR_RESERVED0_MASK
value|0x7
define|#
directive|define
name|DB_PWM_ADDR_RESERVED0_SHIFT
value|0
define|#
directive|define
name|DB_PWM_ADDR_OFFSET_MASK
value|0x7F
comment|/* Offset in PWM address space */
define|#
directive|define
name|DB_PWM_ADDR_OFFSET_SHIFT
value|3
define|#
directive|define
name|DB_PWM_ADDR_WID_MASK
value|0x3
comment|/* Window ID */
define|#
directive|define
name|DB_PWM_ADDR_WID_SHIFT
value|10
define|#
directive|define
name|DB_PWM_ADDR_DPI_MASK
value|0xFFFF
comment|/* Doorbell page ID */
define|#
directive|define
name|DB_PWM_ADDR_DPI_SHIFT
value|12
define|#
directive|define
name|DB_PWM_ADDR_RESERVED1_MASK
value|0xF
define|#
directive|define
name|DB_PWM_ADDR_RESERVED1_SHIFT
value|28
block|}
struct|;
end_struct

begin_comment
comment|/*  * Parameters to RDMA firmware, passed in EDPM doorbell  */
end_comment

begin_struct
struct|struct
name|db_rdma_dpm_params
block|{
name|__le32
name|params
decl_stmt|;
define|#
directive|define
name|DB_RDMA_DPM_PARAMS_SIZE_MASK
value|0x3F
comment|/* Size in QWORD-s of the DPM burst */
define|#
directive|define
name|DB_RDMA_DPM_PARAMS_SIZE_SHIFT
value|0
define|#
directive|define
name|DB_RDMA_DPM_PARAMS_DPM_TYPE_MASK
value|0x3
comment|/* Type of DPM transacation (DPM_RDMA) (use enum db_dpm_type) */
define|#
directive|define
name|DB_RDMA_DPM_PARAMS_DPM_TYPE_SHIFT
value|6
define|#
directive|define
name|DB_RDMA_DPM_PARAMS_OPCODE_MASK
value|0xFF
comment|/* opcode for RDMA operation */
define|#
directive|define
name|DB_RDMA_DPM_PARAMS_OPCODE_SHIFT
value|8
define|#
directive|define
name|DB_RDMA_DPM_PARAMS_WQE_SIZE_MASK
value|0x7FF
comment|/* the size of the WQE payload in bytes */
define|#
directive|define
name|DB_RDMA_DPM_PARAMS_WQE_SIZE_SHIFT
value|16
define|#
directive|define
name|DB_RDMA_DPM_PARAMS_RESERVED0_MASK
value|0x1
define|#
directive|define
name|DB_RDMA_DPM_PARAMS_RESERVED0_SHIFT
value|27
define|#
directive|define
name|DB_RDMA_DPM_PARAMS_COMPLETION_FLG_MASK
value|0x1
comment|/* RoCE completion flag */
define|#
directive|define
name|DB_RDMA_DPM_PARAMS_COMPLETION_FLG_SHIFT
value|28
define|#
directive|define
name|DB_RDMA_DPM_PARAMS_S_FLG_MASK
value|0x1
comment|/* RoCE S flag */
define|#
directive|define
name|DB_RDMA_DPM_PARAMS_S_FLG_SHIFT
value|29
define|#
directive|define
name|DB_RDMA_DPM_PARAMS_RESERVED1_MASK
value|0x1
define|#
directive|define
name|DB_RDMA_DPM_PARAMS_RESERVED1_SHIFT
value|30
define|#
directive|define
name|DB_RDMA_DPM_PARAMS_CONN_TYPE_IS_IWARP_MASK
value|0x1
comment|/* Connection type is iWARP */
define|#
directive|define
name|DB_RDMA_DPM_PARAMS_CONN_TYPE_IS_IWARP_SHIFT
value|31
block|}
struct|;
end_struct

begin_comment
comment|/*  * Structure for doorbell data, in RDMA DPM mode, for the first doorbell in a DPM burst  */
end_comment

begin_struct
struct|struct
name|db_rdma_dpm_data
block|{
name|__le16
name|icid
comment|/* internal CID */
decl_stmt|;
name|__le16
name|prod_val
comment|/* aggregated value to update */
decl_stmt|;
name|struct
name|db_rdma_dpm_params
name|params
comment|/* parameters passed to RDMA firmware */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Igu interrupt command  */
end_comment

begin_enum
enum|enum
name|igu_int_cmd
block|{
name|IGU_INT_ENABLE
init|=
literal|0
block|,
name|IGU_INT_DISABLE
init|=
literal|1
block|,
name|IGU_INT_NOP
init|=
literal|2
block|,
name|IGU_INT_NOP2
init|=
literal|3
block|,
name|MAX_IGU_INT_CMD
block|}
enum|;
end_enum

begin_comment
comment|/*  * IGU producer or consumer update command  */
end_comment

begin_struct
struct|struct
name|igu_prod_cons_update
block|{
name|__le32
name|sb_id_and_flags
decl_stmt|;
define|#
directive|define
name|IGU_PROD_CONS_UPDATE_SB_INDEX_MASK
value|0xFFFFFF
define|#
directive|define
name|IGU_PROD_CONS_UPDATE_SB_INDEX_SHIFT
value|0
define|#
directive|define
name|IGU_PROD_CONS_UPDATE_UPDATE_FLAG_MASK
value|0x1
define|#
directive|define
name|IGU_PROD_CONS_UPDATE_UPDATE_FLAG_SHIFT
value|24
define|#
directive|define
name|IGU_PROD_CONS_UPDATE_ENABLE_INT_MASK
value|0x3
comment|/* interrupt enable/disable/nop (use enum igu_int_cmd) */
define|#
directive|define
name|IGU_PROD_CONS_UPDATE_ENABLE_INT_SHIFT
value|25
define|#
directive|define
name|IGU_PROD_CONS_UPDATE_SEGMENT_ACCESS_MASK
value|0x1
comment|/*  (use enum igu_seg_access) */
define|#
directive|define
name|IGU_PROD_CONS_UPDATE_SEGMENT_ACCESS_SHIFT
value|27
define|#
directive|define
name|IGU_PROD_CONS_UPDATE_TIMER_MASK_MASK
value|0x1
define|#
directive|define
name|IGU_PROD_CONS_UPDATE_TIMER_MASK_SHIFT
value|28
define|#
directive|define
name|IGU_PROD_CONS_UPDATE_RESERVED0_MASK
value|0x3
define|#
directive|define
name|IGU_PROD_CONS_UPDATE_RESERVED0_SHIFT
value|29
define|#
directive|define
name|IGU_PROD_CONS_UPDATE_COMMAND_TYPE_MASK
value|0x1
comment|/* must always be set cleared (use enum command_type_bit) */
define|#
directive|define
name|IGU_PROD_CONS_UPDATE_COMMAND_TYPE_SHIFT
value|31
name|__le32
name|reserved1
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Igu segments access for default status block only  */
end_comment

begin_enum
enum|enum
name|igu_seg_access
block|{
name|IGU_SEG_ACCESS_REG
init|=
literal|0
block|,
name|IGU_SEG_ACCESS_ATTN
init|=
literal|1
block|,
name|MAX_IGU_SEG_ACCESS
block|}
enum|;
end_enum

begin_comment
comment|/*  * Enumeration for L3 type field of parsing_and_err_flags_union. L3Type: 0 - unknown (not ip) ,1 - Ipv4, 2 - Ipv6 (this field can be filled according to the last-ethertype)  */
end_comment

begin_enum
enum|enum
name|l3_type
block|{
name|e_l3Type_unknown
block|,
name|e_l3Type_ipv4
block|,
name|e_l3Type_ipv6
block|,
name|MAX_L3_TYPE
block|}
enum|;
end_enum

begin_comment
comment|/*  * Enumeration for l4Protocol field of parsing_and_err_flags_union. L4-protocol 0 - none, 1 - TCP, 2- UDP. if the packet is IPv4 fragment, and its not the first fragment, the protocol-type should be set to none.  */
end_comment

begin_enum
enum|enum
name|l4_protocol
block|{
name|e_l4Protocol_none
block|,
name|e_l4Protocol_tcp
block|,
name|e_l4Protocol_udp
block|,
name|MAX_L4_PROTOCOL
block|}
enum|;
end_enum

begin_comment
comment|/*  * Parsing and error flags field.  */
end_comment

begin_struct
struct|struct
name|parsing_and_err_flags
block|{
name|__le16
name|flags
decl_stmt|;
define|#
directive|define
name|PARSING_AND_ERR_FLAGS_L3TYPE_MASK
value|0x3
comment|/* L3Type: 0 - unknown (not ip) ,1 - Ipv4, 2 - Ipv6 (this field can be filled according to the last-ethertype) (use enum l3_type) */
define|#
directive|define
name|PARSING_AND_ERR_FLAGS_L3TYPE_SHIFT
value|0
define|#
directive|define
name|PARSING_AND_ERR_FLAGS_L4PROTOCOL_MASK
value|0x3
comment|/* L4-protocol 0 - none, 1 - TCP, 2- UDP. if the packet is IPv4 fragment, and its not the first fragment, the protocol-type should be set to none. (use enum l4_protocol) */
define|#
directive|define
name|PARSING_AND_ERR_FLAGS_L4PROTOCOL_SHIFT
value|2
define|#
directive|define
name|PARSING_AND_ERR_FLAGS_IPV4FRAG_MASK
value|0x1
comment|/* Set if the packet is IPv4 fragment. */
define|#
directive|define
name|PARSING_AND_ERR_FLAGS_IPV4FRAG_SHIFT
value|4
define|#
directive|define
name|PARSING_AND_ERR_FLAGS_TAG8021QEXIST_MASK
value|0x1
comment|/* Set if VLAN tag exists. Invalid if tunnel type are IP GRE or IP GENEVE. */
define|#
directive|define
name|PARSING_AND_ERR_FLAGS_TAG8021QEXIST_SHIFT
value|5
define|#
directive|define
name|PARSING_AND_ERR_FLAGS_L4CHKSMWASCALCULATED_MASK
value|0x1
comment|/* Set if L4 checksum was calculated. */
define|#
directive|define
name|PARSING_AND_ERR_FLAGS_L4CHKSMWASCALCULATED_SHIFT
value|6
define|#
directive|define
name|PARSING_AND_ERR_FLAGS_TIMESYNCPKT_MASK
value|0x1
comment|/* Set for PTP packet. */
define|#
directive|define
name|PARSING_AND_ERR_FLAGS_TIMESYNCPKT_SHIFT
value|7
define|#
directive|define
name|PARSING_AND_ERR_FLAGS_TIMESTAMPRECORDED_MASK
value|0x1
comment|/* Set if PTP timestamp recorded. */
define|#
directive|define
name|PARSING_AND_ERR_FLAGS_TIMESTAMPRECORDED_SHIFT
value|8
define|#
directive|define
name|PARSING_AND_ERR_FLAGS_IPHDRERROR_MASK
value|0x1
comment|/* Set if either version-mismatch or hdr-len-error or ipv4-cksm is set or ipv6 ver mismatch */
define|#
directive|define
name|PARSING_AND_ERR_FLAGS_IPHDRERROR_SHIFT
value|9
define|#
directive|define
name|PARSING_AND_ERR_FLAGS_L4CHKSMERROR_MASK
value|0x1
comment|/* Set if L4 checksum validation failed. Valid only if L4 checksum was calculated. */
define|#
directive|define
name|PARSING_AND_ERR_FLAGS_L4CHKSMERROR_SHIFT
value|10
define|#
directive|define
name|PARSING_AND_ERR_FLAGS_TUNNELEXIST_MASK
value|0x1
comment|/* Set if GRE/VXLAN/GENEVE tunnel detected. */
define|#
directive|define
name|PARSING_AND_ERR_FLAGS_TUNNELEXIST_SHIFT
value|11
define|#
directive|define
name|PARSING_AND_ERR_FLAGS_TUNNEL8021QTAGEXIST_MASK
value|0x1
comment|/* Set if VLAN tag exists in tunnel header. */
define|#
directive|define
name|PARSING_AND_ERR_FLAGS_TUNNEL8021QTAGEXIST_SHIFT
value|12
define|#
directive|define
name|PARSING_AND_ERR_FLAGS_TUNNELIPHDRERROR_MASK
value|0x1
comment|/* Set if either tunnel-ipv4-version-mismatch or tunnel-ipv4-hdr-len-error or tunnel-ipv4-cksm is set or tunneling ipv6 ver mismatch */
define|#
directive|define
name|PARSING_AND_ERR_FLAGS_TUNNELIPHDRERROR_SHIFT
value|13
define|#
directive|define
name|PARSING_AND_ERR_FLAGS_TUNNELL4CHKSMWASCALCULATED_MASK
value|0x1
comment|/* Set if GRE or VXLAN/GENEVE UDP checksum was calculated. */
define|#
directive|define
name|PARSING_AND_ERR_FLAGS_TUNNELL4CHKSMWASCALCULATED_SHIFT
value|14
define|#
directive|define
name|PARSING_AND_ERR_FLAGS_TUNNELL4CHKSMERROR_MASK
value|0x1
comment|/* Set if tunnel L4 checksum validation failed. Valid only if tunnel L4 checksum was calculated. */
define|#
directive|define
name|PARSING_AND_ERR_FLAGS_TUNNELL4CHKSMERROR_SHIFT
value|15
block|}
struct|;
end_struct

begin_comment
comment|/*  * Parsing error flags bitmap.  */
end_comment

begin_struct
struct|struct
name|parsing_err_flags
block|{
name|__le16
name|flags
decl_stmt|;
define|#
directive|define
name|PARSING_ERR_FLAGS_MAC_ERROR_MASK
value|0x1
comment|/* MAC error indication */
define|#
directive|define
name|PARSING_ERR_FLAGS_MAC_ERROR_SHIFT
value|0
define|#
directive|define
name|PARSING_ERR_FLAGS_TRUNC_ERROR_MASK
value|0x1
comment|/* truncation error indication */
define|#
directive|define
name|PARSING_ERR_FLAGS_TRUNC_ERROR_SHIFT
value|1
define|#
directive|define
name|PARSING_ERR_FLAGS_PKT_TOO_SMALL_MASK
value|0x1
comment|/* packet too small indication */
define|#
directive|define
name|PARSING_ERR_FLAGS_PKT_TOO_SMALL_SHIFT
value|2
define|#
directive|define
name|PARSING_ERR_FLAGS_ANY_HDR_MISSING_TAG_MASK
value|0x1
comment|/* Header Missing Tag */
define|#
directive|define
name|PARSING_ERR_FLAGS_ANY_HDR_MISSING_TAG_SHIFT
value|3
define|#
directive|define
name|PARSING_ERR_FLAGS_ANY_HDR_IP_VER_MISMTCH_MASK
value|0x1
comment|/* from frame cracker output */
define|#
directive|define
name|PARSING_ERR_FLAGS_ANY_HDR_IP_VER_MISMTCH_SHIFT
value|4
define|#
directive|define
name|PARSING_ERR_FLAGS_ANY_HDR_IP_V4_HDR_LEN_TOO_SMALL_MASK
value|0x1
comment|/* from frame cracker output */
define|#
directive|define
name|PARSING_ERR_FLAGS_ANY_HDR_IP_V4_HDR_LEN_TOO_SMALL_SHIFT
value|5
define|#
directive|define
name|PARSING_ERR_FLAGS_ANY_HDR_IP_BAD_TOTAL_LEN_MASK
value|0x1
comment|/* set this error if: 1. total-len is smaller than hdr-len 2. total-ip-len indicates number that is bigger than real packet length 3. tunneling: total-ip-length of the outer header points to offset that is smaller than the one pointed to by the total-ip-len of the inner hdr. */
define|#
directive|define
name|PARSING_ERR_FLAGS_ANY_HDR_IP_BAD_TOTAL_LEN_SHIFT
value|6
define|#
directive|define
name|PARSING_ERR_FLAGS_IP_V4_CHKSM_ERROR_MASK
value|0x1
comment|/* from frame cracker output */
define|#
directive|define
name|PARSING_ERR_FLAGS_IP_V4_CHKSM_ERROR_SHIFT
value|7
define|#
directive|define
name|PARSING_ERR_FLAGS_ANY_HDR_L4_IP_LEN_MISMTCH_MASK
value|0x1
comment|/* from frame cracker output. for either TCP or UDP */
define|#
directive|define
name|PARSING_ERR_FLAGS_ANY_HDR_L4_IP_LEN_MISMTCH_SHIFT
value|8
define|#
directive|define
name|PARSING_ERR_FLAGS_ZERO_UDP_IP_V6_CHKSM_MASK
value|0x1
comment|/* from frame cracker output */
define|#
directive|define
name|PARSING_ERR_FLAGS_ZERO_UDP_IP_V6_CHKSM_SHIFT
value|9
define|#
directive|define
name|PARSING_ERR_FLAGS_INNER_L4_CHKSM_ERROR_MASK
value|0x1
comment|/* cksm calculated and value isnt 0xffff or L4-cksm-wasnt-calculated for any reason, like: udp/ipv4 checksum is 0 etc. */
define|#
directive|define
name|PARSING_ERR_FLAGS_INNER_L4_CHKSM_ERROR_SHIFT
value|10
define|#
directive|define
name|PARSING_ERR_FLAGS_ANY_HDR_ZERO_TTL_OR_HOP_LIM_MASK
value|0x1
comment|/* from frame cracker output */
define|#
directive|define
name|PARSING_ERR_FLAGS_ANY_HDR_ZERO_TTL_OR_HOP_LIM_SHIFT
value|11
define|#
directive|define
name|PARSING_ERR_FLAGS_NON_8021Q_TAG_EXISTS_IN_BOTH_HDRS_MASK
value|0x1
comment|/* from frame cracker output */
define|#
directive|define
name|PARSING_ERR_FLAGS_NON_8021Q_TAG_EXISTS_IN_BOTH_HDRS_SHIFT
value|12
define|#
directive|define
name|PARSING_ERR_FLAGS_GENEVE_OPTION_OVERSIZED_MASK
value|0x1
comment|/* set if geneve option size was over 32 byte */
define|#
directive|define
name|PARSING_ERR_FLAGS_GENEVE_OPTION_OVERSIZED_SHIFT
value|13
define|#
directive|define
name|PARSING_ERR_FLAGS_TUNNEL_IP_V4_CHKSM_ERROR_MASK
value|0x1
comment|/* from frame cracker output */
define|#
directive|define
name|PARSING_ERR_FLAGS_TUNNEL_IP_V4_CHKSM_ERROR_SHIFT
value|14
define|#
directive|define
name|PARSING_ERR_FLAGS_TUNNEL_L4_CHKSM_ERROR_MASK
value|0x1
comment|/* from frame cracker output */
define|#
directive|define
name|PARSING_ERR_FLAGS_TUNNEL_L4_CHKSM_ERROR_SHIFT
value|15
block|}
struct|;
end_struct

begin_comment
comment|/*  * Pb context  */
end_comment

begin_struct
struct|struct
name|pb_context
block|{
name|__le32
name|crc
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Concrete Function ID.  */
end_comment

begin_struct
struct|struct
name|pxp_concrete_fid
block|{
name|__le16
name|fid
decl_stmt|;
define|#
directive|define
name|PXP_CONCRETE_FID_PFID_MASK
value|0xF
comment|/* Parent PFID */
define|#
directive|define
name|PXP_CONCRETE_FID_PFID_SHIFT
value|0
define|#
directive|define
name|PXP_CONCRETE_FID_PORT_MASK
value|0x3
comment|/* port number */
define|#
directive|define
name|PXP_CONCRETE_FID_PORT_SHIFT
value|4
define|#
directive|define
name|PXP_CONCRETE_FID_PATH_MASK
value|0x1
comment|/* path number */
define|#
directive|define
name|PXP_CONCRETE_FID_PATH_SHIFT
value|6
define|#
directive|define
name|PXP_CONCRETE_FID_VFVALID_MASK
value|0x1
define|#
directive|define
name|PXP_CONCRETE_FID_VFVALID_SHIFT
value|7
define|#
directive|define
name|PXP_CONCRETE_FID_VFID_MASK
value|0xFF
define|#
directive|define
name|PXP_CONCRETE_FID_VFID_SHIFT
value|8
block|}
struct|;
end_struct

begin_comment
comment|/*  * Concrete Function ID.  */
end_comment

begin_struct
struct|struct
name|pxp_pretend_concrete_fid
block|{
name|__le16
name|fid
decl_stmt|;
define|#
directive|define
name|PXP_PRETEND_CONCRETE_FID_PFID_MASK
value|0xF
comment|/* Parent PFID */
define|#
directive|define
name|PXP_PRETEND_CONCRETE_FID_PFID_SHIFT
value|0
define|#
directive|define
name|PXP_PRETEND_CONCRETE_FID_RESERVED_MASK
value|0x7
comment|/* port number. Only when part of ME register. */
define|#
directive|define
name|PXP_PRETEND_CONCRETE_FID_RESERVED_SHIFT
value|4
define|#
directive|define
name|PXP_PRETEND_CONCRETE_FID_VFVALID_MASK
value|0x1
define|#
directive|define
name|PXP_PRETEND_CONCRETE_FID_VFVALID_SHIFT
value|7
define|#
directive|define
name|PXP_PRETEND_CONCRETE_FID_VFID_MASK
value|0xFF
define|#
directive|define
name|PXP_PRETEND_CONCRETE_FID_VFID_SHIFT
value|8
block|}
struct|;
end_struct

begin_comment
comment|/*  * Function ID.  */
end_comment

begin_union
union|union
name|pxp_pretend_fid
block|{
name|struct
name|pxp_pretend_concrete_fid
name|concrete_fid
decl_stmt|;
name|__le16
name|opaque_fid
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/*  * Pxp Pretend Command Register.  */
end_comment

begin_struct
struct|struct
name|pxp_pretend_cmd
block|{
name|union
name|pxp_pretend_fid
name|fid
decl_stmt|;
name|__le16
name|control
decl_stmt|;
define|#
directive|define
name|PXP_PRETEND_CMD_PATH_MASK
value|0x1
define|#
directive|define
name|PXP_PRETEND_CMD_PATH_SHIFT
value|0
define|#
directive|define
name|PXP_PRETEND_CMD_USE_PORT_MASK
value|0x1
define|#
directive|define
name|PXP_PRETEND_CMD_USE_PORT_SHIFT
value|1
define|#
directive|define
name|PXP_PRETEND_CMD_PORT_MASK
value|0x3
define|#
directive|define
name|PXP_PRETEND_CMD_PORT_SHIFT
value|2
define|#
directive|define
name|PXP_PRETEND_CMD_RESERVED0_MASK
value|0xF
define|#
directive|define
name|PXP_PRETEND_CMD_RESERVED0_SHIFT
value|4
define|#
directive|define
name|PXP_PRETEND_CMD_RESERVED1_MASK
value|0xF
define|#
directive|define
name|PXP_PRETEND_CMD_RESERVED1_SHIFT
value|8
define|#
directive|define
name|PXP_PRETEND_CMD_PRETEND_PATH_MASK
value|0x1
comment|/* is pretend mode? */
define|#
directive|define
name|PXP_PRETEND_CMD_PRETEND_PATH_SHIFT
value|12
define|#
directive|define
name|PXP_PRETEND_CMD_PRETEND_PORT_MASK
value|0x1
comment|/* is pretend mode? */
define|#
directive|define
name|PXP_PRETEND_CMD_PRETEND_PORT_SHIFT
value|13
define|#
directive|define
name|PXP_PRETEND_CMD_PRETEND_FUNCTION_MASK
value|0x1
comment|/* is pretend mode? */
define|#
directive|define
name|PXP_PRETEND_CMD_PRETEND_FUNCTION_SHIFT
value|14
define|#
directive|define
name|PXP_PRETEND_CMD_IS_CONCRETE_MASK
value|0x1
comment|/* is fid concrete? */
define|#
directive|define
name|PXP_PRETEND_CMD_IS_CONCRETE_SHIFT
value|15
block|}
struct|;
end_struct

begin_comment
comment|/*  * PTT Record in PXP Admin Window.  */
end_comment

begin_struct
struct|struct
name|pxp_ptt_entry
block|{
name|__le32
name|offset
decl_stmt|;
define|#
directive|define
name|PXP_PTT_ENTRY_OFFSET_MASK
value|0x7FFFFF
define|#
directive|define
name|PXP_PTT_ENTRY_OFFSET_SHIFT
value|0
define|#
directive|define
name|PXP_PTT_ENTRY_RESERVED0_MASK
value|0x1FF
define|#
directive|define
name|PXP_PTT_ENTRY_RESERVED0_SHIFT
value|23
name|struct
name|pxp_pretend_cmd
name|pretend
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * VF Zone A Permission Register.  */
end_comment

begin_struct
struct|struct
name|pxp_vf_zone_a_permission
block|{
name|__le32
name|control
decl_stmt|;
define|#
directive|define
name|PXP_VF_ZONE_A_PERMISSION_VFID_MASK
value|0xFF
define|#
directive|define
name|PXP_VF_ZONE_A_PERMISSION_VFID_SHIFT
value|0
define|#
directive|define
name|PXP_VF_ZONE_A_PERMISSION_VALID_MASK
value|0x1
define|#
directive|define
name|PXP_VF_ZONE_A_PERMISSION_VALID_SHIFT
value|8
define|#
directive|define
name|PXP_VF_ZONE_A_PERMISSION_RESERVED0_MASK
value|0x7F
define|#
directive|define
name|PXP_VF_ZONE_A_PERMISSION_RESERVED0_SHIFT
value|9
define|#
directive|define
name|PXP_VF_ZONE_A_PERMISSION_RESERVED1_MASK
value|0xFFFF
define|#
directive|define
name|PXP_VF_ZONE_A_PERMISSION_RESERVED1_SHIFT
value|16
block|}
struct|;
end_struct

begin_comment
comment|/*  * Rdif context  */
end_comment

begin_struct
struct|struct
name|rdif_task_context
block|{
name|__le32
name|initialRefTag
decl_stmt|;
name|__le16
name|appTagValue
decl_stmt|;
name|__le16
name|appTagMask
decl_stmt|;
name|u8
name|flags0
decl_stmt|;
define|#
directive|define
name|RDIF_TASK_CONTEXT_IGNOREAPPTAG_MASK
value|0x1
define|#
directive|define
name|RDIF_TASK_CONTEXT_IGNOREAPPTAG_SHIFT
value|0
define|#
directive|define
name|RDIF_TASK_CONTEXT_INITIALREFTAGVALID_MASK
value|0x1
define|#
directive|define
name|RDIF_TASK_CONTEXT_INITIALREFTAGVALID_SHIFT
value|1
define|#
directive|define
name|RDIF_TASK_CONTEXT_HOSTGUARDTYPE_MASK
value|0x1
comment|/* 0 = IP checksum, 1 = CRC */
define|#
directive|define
name|RDIF_TASK_CONTEXT_HOSTGUARDTYPE_SHIFT
value|2
define|#
directive|define
name|RDIF_TASK_CONTEXT_SETERRORWITHEOP_MASK
value|0x1
define|#
directive|define
name|RDIF_TASK_CONTEXT_SETERRORWITHEOP_SHIFT
value|3
define|#
directive|define
name|RDIF_TASK_CONTEXT_PROTECTIONTYPE_MASK
value|0x3
comment|/* 1/2/3 - Protection Type */
define|#
directive|define
name|RDIF_TASK_CONTEXT_PROTECTIONTYPE_SHIFT
value|4
define|#
directive|define
name|RDIF_TASK_CONTEXT_CRC_SEED_MASK
value|0x1
comment|/* 0=0x0000, 1=0xffff */
define|#
directive|define
name|RDIF_TASK_CONTEXT_CRC_SEED_SHIFT
value|6
define|#
directive|define
name|RDIF_TASK_CONTEXT_KEEPREFTAGCONST_MASK
value|0x1
comment|/* Keep reference tag constant */
define|#
directive|define
name|RDIF_TASK_CONTEXT_KEEPREFTAGCONST_SHIFT
value|7
name|u8
name|partialDifData
index|[
literal|7
index|]
decl_stmt|;
name|__le16
name|partialCrcValue
decl_stmt|;
name|__le16
name|partialChecksumValue
decl_stmt|;
name|__le32
name|offsetInIO
decl_stmt|;
name|__le16
name|flags1
decl_stmt|;
define|#
directive|define
name|RDIF_TASK_CONTEXT_VALIDATEGUARD_MASK
value|0x1
define|#
directive|define
name|RDIF_TASK_CONTEXT_VALIDATEGUARD_SHIFT
value|0
define|#
directive|define
name|RDIF_TASK_CONTEXT_VALIDATEAPPTAG_MASK
value|0x1
define|#
directive|define
name|RDIF_TASK_CONTEXT_VALIDATEAPPTAG_SHIFT
value|1
define|#
directive|define
name|RDIF_TASK_CONTEXT_VALIDATEREFTAG_MASK
value|0x1
define|#
directive|define
name|RDIF_TASK_CONTEXT_VALIDATEREFTAG_SHIFT
value|2
define|#
directive|define
name|RDIF_TASK_CONTEXT_FORWARDGUARD_MASK
value|0x1
define|#
directive|define
name|RDIF_TASK_CONTEXT_FORWARDGUARD_SHIFT
value|3
define|#
directive|define
name|RDIF_TASK_CONTEXT_FORWARDAPPTAG_MASK
value|0x1
define|#
directive|define
name|RDIF_TASK_CONTEXT_FORWARDAPPTAG_SHIFT
value|4
define|#
directive|define
name|RDIF_TASK_CONTEXT_FORWARDREFTAG_MASK
value|0x1
define|#
directive|define
name|RDIF_TASK_CONTEXT_FORWARDREFTAG_SHIFT
value|5
define|#
directive|define
name|RDIF_TASK_CONTEXT_INTERVALSIZE_MASK
value|0x7
comment|/* 0=512B, 1=1KB, 2=2KB, 3=4KB, 4=8KB */
define|#
directive|define
name|RDIF_TASK_CONTEXT_INTERVALSIZE_SHIFT
value|6
define|#
directive|define
name|RDIF_TASK_CONTEXT_HOSTINTERFACE_MASK
value|0x3
comment|/* 0=None, 1=DIF, 2=DIX */
define|#
directive|define
name|RDIF_TASK_CONTEXT_HOSTINTERFACE_SHIFT
value|9
define|#
directive|define
name|RDIF_TASK_CONTEXT_DIFBEFOREDATA_MASK
value|0x1
comment|/* DIF tag right at the beginning of DIF interval */
define|#
directive|define
name|RDIF_TASK_CONTEXT_DIFBEFOREDATA_SHIFT
value|11
define|#
directive|define
name|RDIF_TASK_CONTEXT_RESERVED0_MASK
value|0x1
define|#
directive|define
name|RDIF_TASK_CONTEXT_RESERVED0_SHIFT
value|12
define|#
directive|define
name|RDIF_TASK_CONTEXT_NETWORKINTERFACE_MASK
value|0x1
comment|/* 0=None, 1=DIF */
define|#
directive|define
name|RDIF_TASK_CONTEXT_NETWORKINTERFACE_SHIFT
value|13
define|#
directive|define
name|RDIF_TASK_CONTEXT_FORWARDAPPTAGWITHMASK_MASK
value|0x1
comment|/* Forward application tag with mask */
define|#
directive|define
name|RDIF_TASK_CONTEXT_FORWARDAPPTAGWITHMASK_SHIFT
value|14
define|#
directive|define
name|RDIF_TASK_CONTEXT_FORWARDREFTAGWITHMASK_MASK
value|0x1
comment|/* Forward reference tag with mask */
define|#
directive|define
name|RDIF_TASK_CONTEXT_FORWARDREFTAGWITHMASK_SHIFT
value|15
name|__le16
name|state
decl_stmt|;
define|#
directive|define
name|RDIF_TASK_CONTEXT_RECEIVEDDIFBYTESLEFT_MASK
value|0xF
define|#
directive|define
name|RDIF_TASK_CONTEXT_RECEIVEDDIFBYTESLEFT_SHIFT
value|0
define|#
directive|define
name|RDIF_TASK_CONTEXT_TRANSMITEDDIFBYTESLEFT_MASK
value|0xF
define|#
directive|define
name|RDIF_TASK_CONTEXT_TRANSMITEDDIFBYTESLEFT_SHIFT
value|4
define|#
directive|define
name|RDIF_TASK_CONTEXT_ERRORINIO_MASK
value|0x1
define|#
directive|define
name|RDIF_TASK_CONTEXT_ERRORINIO_SHIFT
value|8
define|#
directive|define
name|RDIF_TASK_CONTEXT_CHECKSUMOVERFLOW_MASK
value|0x1
define|#
directive|define
name|RDIF_TASK_CONTEXT_CHECKSUMOVERFLOW_SHIFT
value|9
define|#
directive|define
name|RDIF_TASK_CONTEXT_REFTAGMASK_MASK
value|0xF
comment|/* mask for refernce tag handling */
define|#
directive|define
name|RDIF_TASK_CONTEXT_REFTAGMASK_SHIFT
value|10
define|#
directive|define
name|RDIF_TASK_CONTEXT_RESERVED1_MASK
value|0x3
define|#
directive|define
name|RDIF_TASK_CONTEXT_RESERVED1_SHIFT
value|14
name|__le32
name|reserved2
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * RSS hash type  */
end_comment

begin_enum
enum|enum
name|rss_hash_type
block|{
name|RSS_HASH_TYPE_DEFAULT
init|=
literal|0
block|,
name|RSS_HASH_TYPE_IPV4
init|=
literal|1
block|,
name|RSS_HASH_TYPE_TCP_IPV4
init|=
literal|2
block|,
name|RSS_HASH_TYPE_IPV6
init|=
literal|3
block|,
name|RSS_HASH_TYPE_TCP_IPV6
init|=
literal|4
block|,
name|RSS_HASH_TYPE_UDP_IPV4
init|=
literal|5
block|,
name|RSS_HASH_TYPE_UDP_IPV6
init|=
literal|6
block|,
name|MAX_RSS_HASH_TYPE
block|}
enum|;
end_enum

begin_comment
comment|/*  * status block structure  */
end_comment

begin_struct
struct|struct
name|status_block
block|{
name|__le16
name|pi_array
index|[
name|PIS_PER_SB
index|]
decl_stmt|;
name|__le32
name|sb_num
decl_stmt|;
define|#
directive|define
name|STATUS_BLOCK_SB_NUM_MASK
value|0x1FF
define|#
directive|define
name|STATUS_BLOCK_SB_NUM_SHIFT
value|0
define|#
directive|define
name|STATUS_BLOCK_ZERO_PAD_MASK
value|0x7F
define|#
directive|define
name|STATUS_BLOCK_ZERO_PAD_SHIFT
value|9
define|#
directive|define
name|STATUS_BLOCK_ZERO_PAD2_MASK
value|0xFFFF
define|#
directive|define
name|STATUS_BLOCK_ZERO_PAD2_SHIFT
value|16
name|__le32
name|prod_index
decl_stmt|;
define|#
directive|define
name|STATUS_BLOCK_PROD_INDEX_MASK
value|0xFFFFFF
define|#
directive|define
name|STATUS_BLOCK_PROD_INDEX_SHIFT
value|0
define|#
directive|define
name|STATUS_BLOCK_ZERO_PAD3_MASK
value|0xFF
define|#
directive|define
name|STATUS_BLOCK_ZERO_PAD3_SHIFT
value|24
block|}
struct|;
end_struct

begin_comment
comment|/*  * Tdif context  */
end_comment

begin_struct
struct|struct
name|tdif_task_context
block|{
name|__le32
name|initialRefTag
decl_stmt|;
name|__le16
name|appTagValue
decl_stmt|;
name|__le16
name|appTagMask
decl_stmt|;
name|__le16
name|partialCrcValueB
decl_stmt|;
name|__le16
name|partialChecksumValueB
decl_stmt|;
name|__le16
name|stateB
decl_stmt|;
define|#
directive|define
name|TDIF_TASK_CONTEXT_RECEIVEDDIFBYTESLEFTB_MASK
value|0xF
define|#
directive|define
name|TDIF_TASK_CONTEXT_RECEIVEDDIFBYTESLEFTB_SHIFT
value|0
define|#
directive|define
name|TDIF_TASK_CONTEXT_TRANSMITEDDIFBYTESLEFTB_MASK
value|0xF
define|#
directive|define
name|TDIF_TASK_CONTEXT_TRANSMITEDDIFBYTESLEFTB_SHIFT
value|4
define|#
directive|define
name|TDIF_TASK_CONTEXT_ERRORINIOB_MASK
value|0x1
define|#
directive|define
name|TDIF_TASK_CONTEXT_ERRORINIOB_SHIFT
value|8
define|#
directive|define
name|TDIF_TASK_CONTEXT_CHECKSUMOVERFLOW_MASK
value|0x1
define|#
directive|define
name|TDIF_TASK_CONTEXT_CHECKSUMOVERFLOW_SHIFT
value|9
define|#
directive|define
name|TDIF_TASK_CONTEXT_RESERVED0_MASK
value|0x3F
define|#
directive|define
name|TDIF_TASK_CONTEXT_RESERVED0_SHIFT
value|10
name|u8
name|reserved1
decl_stmt|;
name|u8
name|flags0
decl_stmt|;
define|#
directive|define
name|TDIF_TASK_CONTEXT_IGNOREAPPTAG_MASK
value|0x1
define|#
directive|define
name|TDIF_TASK_CONTEXT_IGNOREAPPTAG_SHIFT
value|0
define|#
directive|define
name|TDIF_TASK_CONTEXT_INITIALREFTAGVALID_MASK
value|0x1
define|#
directive|define
name|TDIF_TASK_CONTEXT_INITIALREFTAGVALID_SHIFT
value|1
define|#
directive|define
name|TDIF_TASK_CONTEXT_HOSTGUARDTYPE_MASK
value|0x1
comment|/* 0 = IP checksum, 1 = CRC */
define|#
directive|define
name|TDIF_TASK_CONTEXT_HOSTGUARDTYPE_SHIFT
value|2
define|#
directive|define
name|TDIF_TASK_CONTEXT_SETERRORWITHEOP_MASK
value|0x1
define|#
directive|define
name|TDIF_TASK_CONTEXT_SETERRORWITHEOP_SHIFT
value|3
define|#
directive|define
name|TDIF_TASK_CONTEXT_PROTECTIONTYPE_MASK
value|0x3
comment|/* 1/2/3 - Protection Type */
define|#
directive|define
name|TDIF_TASK_CONTEXT_PROTECTIONTYPE_SHIFT
value|4
define|#
directive|define
name|TDIF_TASK_CONTEXT_CRC_SEED_MASK
value|0x1
comment|/* 0=0x0000, 1=0xffff */
define|#
directive|define
name|TDIF_TASK_CONTEXT_CRC_SEED_SHIFT
value|6
define|#
directive|define
name|TDIF_TASK_CONTEXT_RESERVED2_MASK
value|0x1
define|#
directive|define
name|TDIF_TASK_CONTEXT_RESERVED2_SHIFT
value|7
name|__le32
name|flags1
decl_stmt|;
define|#
directive|define
name|TDIF_TASK_CONTEXT_VALIDATEGUARD_MASK
value|0x1
define|#
directive|define
name|TDIF_TASK_CONTEXT_VALIDATEGUARD_SHIFT
value|0
define|#
directive|define
name|TDIF_TASK_CONTEXT_VALIDATEAPPTAG_MASK
value|0x1
define|#
directive|define
name|TDIF_TASK_CONTEXT_VALIDATEAPPTAG_SHIFT
value|1
define|#
directive|define
name|TDIF_TASK_CONTEXT_VALIDATEREFTAG_MASK
value|0x1
define|#
directive|define
name|TDIF_TASK_CONTEXT_VALIDATEREFTAG_SHIFT
value|2
define|#
directive|define
name|TDIF_TASK_CONTEXT_FORWARDGUARD_MASK
value|0x1
define|#
directive|define
name|TDIF_TASK_CONTEXT_FORWARDGUARD_SHIFT
value|3
define|#
directive|define
name|TDIF_TASK_CONTEXT_FORWARDAPPTAG_MASK
value|0x1
define|#
directive|define
name|TDIF_TASK_CONTEXT_FORWARDAPPTAG_SHIFT
value|4
define|#
directive|define
name|TDIF_TASK_CONTEXT_FORWARDREFTAG_MASK
value|0x1
define|#
directive|define
name|TDIF_TASK_CONTEXT_FORWARDREFTAG_SHIFT
value|5
define|#
directive|define
name|TDIF_TASK_CONTEXT_INTERVALSIZE_MASK
value|0x7
comment|/* 0=512B, 1=1KB, 2=2KB, 3=4KB, 4=8KB */
define|#
directive|define
name|TDIF_TASK_CONTEXT_INTERVALSIZE_SHIFT
value|6
define|#
directive|define
name|TDIF_TASK_CONTEXT_HOSTINTERFACE_MASK
value|0x3
comment|/* 0=None, 1=DIF, 2=DIX */
define|#
directive|define
name|TDIF_TASK_CONTEXT_HOSTINTERFACE_SHIFT
value|9
define|#
directive|define
name|TDIF_TASK_CONTEXT_DIFBEFOREDATA_MASK
value|0x1
comment|/* DIF tag right at the beginning of DIF interval */
define|#
directive|define
name|TDIF_TASK_CONTEXT_DIFBEFOREDATA_SHIFT
value|11
define|#
directive|define
name|TDIF_TASK_CONTEXT_RESERVED3_MASK
value|0x1
comment|/* reserved */
define|#
directive|define
name|TDIF_TASK_CONTEXT_RESERVED3_SHIFT
value|12
define|#
directive|define
name|TDIF_TASK_CONTEXT_NETWORKINTERFACE_MASK
value|0x1
comment|/* 0=None, 1=DIF */
define|#
directive|define
name|TDIF_TASK_CONTEXT_NETWORKINTERFACE_SHIFT
value|13
define|#
directive|define
name|TDIF_TASK_CONTEXT_RECEIVEDDIFBYTESLEFTA_MASK
value|0xF
define|#
directive|define
name|TDIF_TASK_CONTEXT_RECEIVEDDIFBYTESLEFTA_SHIFT
value|14
define|#
directive|define
name|TDIF_TASK_CONTEXT_TRANSMITEDDIFBYTESLEFTA_MASK
value|0xF
define|#
directive|define
name|TDIF_TASK_CONTEXT_TRANSMITEDDIFBYTESLEFTA_SHIFT
value|18
define|#
directive|define
name|TDIF_TASK_CONTEXT_ERRORINIOA_MASK
value|0x1
define|#
directive|define
name|TDIF_TASK_CONTEXT_ERRORINIOA_SHIFT
value|22
define|#
directive|define
name|TDIF_TASK_CONTEXT_CHECKSUMOVERFLOWA_MASK
value|0x1
define|#
directive|define
name|TDIF_TASK_CONTEXT_CHECKSUMOVERFLOWA_SHIFT
value|23
define|#
directive|define
name|TDIF_TASK_CONTEXT_REFTAGMASK_MASK
value|0xF
comment|/* mask for refernce tag handling */
define|#
directive|define
name|TDIF_TASK_CONTEXT_REFTAGMASK_SHIFT
value|24
define|#
directive|define
name|TDIF_TASK_CONTEXT_FORWARDAPPTAGWITHMASK_MASK
value|0x1
comment|/* Forward application tag with mask */
define|#
directive|define
name|TDIF_TASK_CONTEXT_FORWARDAPPTAGWITHMASK_SHIFT
value|28
define|#
directive|define
name|TDIF_TASK_CONTEXT_FORWARDREFTAGWITHMASK_MASK
value|0x1
comment|/* Forward reference tag with mask */
define|#
directive|define
name|TDIF_TASK_CONTEXT_FORWARDREFTAGWITHMASK_SHIFT
value|29
define|#
directive|define
name|TDIF_TASK_CONTEXT_KEEPREFTAGCONST_MASK
value|0x1
comment|/* Keep reference tag constant */
define|#
directive|define
name|TDIF_TASK_CONTEXT_KEEPREFTAGCONST_SHIFT
value|30
define|#
directive|define
name|TDIF_TASK_CONTEXT_RESERVED4_MASK
value|0x1
define|#
directive|define
name|TDIF_TASK_CONTEXT_RESERVED4_SHIFT
value|31
name|__le32
name|offsetInIOB
decl_stmt|;
name|__le16
name|partialCrcValueA
decl_stmt|;
name|__le16
name|partialChecksumValueA
decl_stmt|;
name|__le32
name|offsetInIOA
decl_stmt|;
name|u8
name|partialDifDataA
index|[
literal|8
index|]
decl_stmt|;
name|u8
name|partialDifDataB
index|[
literal|8
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Timers context  */
end_comment

begin_struct
struct|struct
name|timers_context
block|{
name|__le32
name|logical_client_0
decl_stmt|;
define|#
directive|define
name|TIMERS_CONTEXT_EXPIRATIONTIMELC0_MASK
value|0x7FFFFFF
comment|/* Expiration time of logical client 0 */
define|#
directive|define
name|TIMERS_CONTEXT_EXPIRATIONTIMELC0_SHIFT
value|0
define|#
directive|define
name|TIMERS_CONTEXT_RESERVED0_MASK
value|0x1
define|#
directive|define
name|TIMERS_CONTEXT_RESERVED0_SHIFT
value|27
define|#
directive|define
name|TIMERS_CONTEXT_VALIDLC0_MASK
value|0x1
comment|/* Valid bit of logical client 0 */
define|#
directive|define
name|TIMERS_CONTEXT_VALIDLC0_SHIFT
value|28
define|#
directive|define
name|TIMERS_CONTEXT_ACTIVELC0_MASK
value|0x1
comment|/* Active bit of logical client 0 */
define|#
directive|define
name|TIMERS_CONTEXT_ACTIVELC0_SHIFT
value|29
define|#
directive|define
name|TIMERS_CONTEXT_RESERVED1_MASK
value|0x3
define|#
directive|define
name|TIMERS_CONTEXT_RESERVED1_SHIFT
value|30
name|__le32
name|logical_client_1
decl_stmt|;
define|#
directive|define
name|TIMERS_CONTEXT_EXPIRATIONTIMELC1_MASK
value|0x7FFFFFF
comment|/* Expiration time of logical client 1 */
define|#
directive|define
name|TIMERS_CONTEXT_EXPIRATIONTIMELC1_SHIFT
value|0
define|#
directive|define
name|TIMERS_CONTEXT_RESERVED2_MASK
value|0x1
define|#
directive|define
name|TIMERS_CONTEXT_RESERVED2_SHIFT
value|27
define|#
directive|define
name|TIMERS_CONTEXT_VALIDLC1_MASK
value|0x1
comment|/* Valid bit of logical client 1 */
define|#
directive|define
name|TIMERS_CONTEXT_VALIDLC1_SHIFT
value|28
define|#
directive|define
name|TIMERS_CONTEXT_ACTIVELC1_MASK
value|0x1
comment|/* Active bit of logical client 1 */
define|#
directive|define
name|TIMERS_CONTEXT_ACTIVELC1_SHIFT
value|29
define|#
directive|define
name|TIMERS_CONTEXT_RESERVED3_MASK
value|0x3
define|#
directive|define
name|TIMERS_CONTEXT_RESERVED3_SHIFT
value|30
name|__le32
name|logical_client_2
decl_stmt|;
define|#
directive|define
name|TIMERS_CONTEXT_EXPIRATIONTIMELC2_MASK
value|0x7FFFFFF
comment|/* Expiration time of logical client 2 */
define|#
directive|define
name|TIMERS_CONTEXT_EXPIRATIONTIMELC2_SHIFT
value|0
define|#
directive|define
name|TIMERS_CONTEXT_RESERVED4_MASK
value|0x1
define|#
directive|define
name|TIMERS_CONTEXT_RESERVED4_SHIFT
value|27
define|#
directive|define
name|TIMERS_CONTEXT_VALIDLC2_MASK
value|0x1
comment|/* Valid bit of logical client 2 */
define|#
directive|define
name|TIMERS_CONTEXT_VALIDLC2_SHIFT
value|28
define|#
directive|define
name|TIMERS_CONTEXT_ACTIVELC2_MASK
value|0x1
comment|/* Active bit of logical client 2 */
define|#
directive|define
name|TIMERS_CONTEXT_ACTIVELC2_SHIFT
value|29
define|#
directive|define
name|TIMERS_CONTEXT_RESERVED5_MASK
value|0x3
define|#
directive|define
name|TIMERS_CONTEXT_RESERVED5_SHIFT
value|30
name|__le32
name|host_expiration_fields
decl_stmt|;
define|#
directive|define
name|TIMERS_CONTEXT_HOSTEXPRIRATIONVALUE_MASK
value|0x7FFFFFF
comment|/* Expiration time on host (closest one) */
define|#
directive|define
name|TIMERS_CONTEXT_HOSTEXPRIRATIONVALUE_SHIFT
value|0
define|#
directive|define
name|TIMERS_CONTEXT_RESERVED6_MASK
value|0x1
define|#
directive|define
name|TIMERS_CONTEXT_RESERVED6_SHIFT
value|27
define|#
directive|define
name|TIMERS_CONTEXT_HOSTEXPRIRATIONVALID_MASK
value|0x1
comment|/* Valid bit of host expiration */
define|#
directive|define
name|TIMERS_CONTEXT_HOSTEXPRIRATIONVALID_SHIFT
value|28
define|#
directive|define
name|TIMERS_CONTEXT_RESERVED7_MASK
value|0x7
define|#
directive|define
name|TIMERS_CONTEXT_RESERVED7_SHIFT
value|29
block|}
struct|;
end_struct

begin_comment
comment|/*  * Enum for next_protocol field of tunnel_parsing_flags  */
end_comment

begin_enum
enum|enum
name|tunnel_next_protocol
block|{
name|e_unknown
init|=
literal|0
block|,
name|e_l2
init|=
literal|1
block|,
name|e_ipv4
init|=
literal|2
block|,
name|e_ipv6
init|=
literal|3
block|,
name|MAX_TUNNEL_NEXT_PROTOCOL
block|}
enum|;
end_enum

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __COMMON_HSI__ */
end_comment

end_unit

