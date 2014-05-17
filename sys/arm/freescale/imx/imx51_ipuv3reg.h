begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: imx51_ipuv3reg.h,v 1.1 2012/04/17 10:19:57 bsh Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 2011, 2012  Genetec Corporation.  All rights reserved.  * Written by Hashimoto Kenichi for Genetec Corporation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY GENETEC CORPORATION ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL GENETEC CORPORATION  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2012, 2013 The FreeBSD Foundation  * All rights reserved.  *  * Portions of this software were developed by Oleksandr Rybalko  * under sponsorship from the FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1.	Redistributions of source code must retain the above copyright  *	notice, this list of conditions and the following disclaimer.  * 2.	Redistributions in binary form must reproduce the above copyright  *	notice, this list of conditions and the following disclaimer in the  *	documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ARM_IMX_IMX51_IPUV3REG_H
end_ifndef

begin_define
define|#
directive|define
name|_ARM_IMX_IMX51_IPUV3REG_H
end_define

begin_comment
comment|/* register offset address */
end_comment

begin_comment
comment|/*  * CM  * Control Module  */
end_comment

begin_define
define|#
directive|define
name|IPU_CM_CONF
value|0x00000000
end_define

begin_define
define|#
directive|define
name|CM_CONF_CSI_SEL
value|0x80000000
end_define

begin_define
define|#
directive|define
name|CM_CONF_IC_INPUT
value|0x40000000
end_define

begin_define
define|#
directive|define
name|CM_CONF_CSI1_DATA_SOURCE
value|0x20000000
end_define

begin_define
define|#
directive|define
name|CM_CONF_CSI0_DATA_SOURCE
value|0x10000000
end_define

begin_define
define|#
directive|define
name|CM_CONF_VDI_DMFC_SYNC
value|0x08000000
end_define

begin_define
define|#
directive|define
name|CM_CONF_IC_DMFC_SYNC
value|0x04000000
end_define

begin_define
define|#
directive|define
name|CM_CONF_IC_DMFC_SEL
value|0x02000000
end_define

begin_define
define|#
directive|define
name|CM_CONF_ISP_DOUBLE_FLOW
value|0x01000000
end_define

begin_define
define|#
directive|define
name|CM_CONF_IDMAC_DISABLE
value|0x00400000
end_define

begin_define
define|#
directive|define
name|CM_CONF_IPU_DIAGBUS_ON
value|0x00200000
end_define

begin_define
define|#
directive|define
name|CM_CONF_IPU_DIAGBUS_MODE
value|0x001f0000
end_define

begin_define
define|#
directive|define
name|CM_CONF_VDI_EN
value|0x00001000
end_define

begin_define
define|#
directive|define
name|CM_CONF_SISG_EN
value|0x00000800
end_define

begin_define
define|#
directive|define
name|CM_CONF_DMFC_EN
value|0x00000400
end_define

begin_define
define|#
directive|define
name|CM_CONF_DC_EN
value|0x00000200
end_define

begin_define
define|#
directive|define
name|CM_CONF_SMFC_EN
value|0x00000100
end_define

begin_define
define|#
directive|define
name|CM_CONF_DI1_EN
value|0x00000080
end_define

begin_define
define|#
directive|define
name|CM_CONF_DI0_EN
value|0x00000040
end_define

begin_define
define|#
directive|define
name|CM_CONF_DP_EN
value|0x00000020
end_define

begin_define
define|#
directive|define
name|CM_CONF_ISP_EN
value|0x00000010
end_define

begin_define
define|#
directive|define
name|CM_CONF_IRT_EN
value|0x00000008
end_define

begin_define
define|#
directive|define
name|CM_CONF_IC_EN
value|0x00000004
end_define

begin_define
define|#
directive|define
name|CM_CONF_CSI1_EN
value|0x00000002
end_define

begin_define
define|#
directive|define
name|CM_CONF_CSI0_EN
value|0x00000001
end_define

begin_define
define|#
directive|define
name|IPU_SISG_CTRL0
value|0x00000004
end_define

begin_define
define|#
directive|define
name|IPU_SISG_CTRL1
value|0x00000008
end_define

begin_define
define|#
directive|define
name|IPU_CM_INT_CTRL_1
value|0x0000003c
end_define

begin_define
define|#
directive|define
name|IPU_CM_INT_CTRL_2
value|0x00000040
end_define

begin_define
define|#
directive|define
name|IPU_CM_INT_CTRL_3
value|0x00000044
end_define

begin_define
define|#
directive|define
name|IPU_CM_INT_CTRL_4
value|0x00000048
end_define

begin_define
define|#
directive|define
name|IPU_CM_INT_CTRL_5
value|0x0000004c
end_define

begin_define
define|#
directive|define
name|IPU_CM_INT_CTRL_6
value|0x00000050
end_define

begin_define
define|#
directive|define
name|IPU_CM_INT_CTRL_7
value|0x00000054
end_define

begin_define
define|#
directive|define
name|IPU_CM_INT_CTRL_8
value|0x00000058
end_define

begin_define
define|#
directive|define
name|IPU_CM_INT_CTRL_9
value|0x0000005c
end_define

begin_define
define|#
directive|define
name|IPU_CM_INT_CTRL_10
value|0x00000060
end_define

begin_define
define|#
directive|define
name|IPU_CM_INT_CTRL_11
value|0x00000064
end_define

begin_define
define|#
directive|define
name|IPU_CM_INT_CTRL_12
value|0x00000068
end_define

begin_define
define|#
directive|define
name|IPU_CM_INT_CTRL_13
value|0x0000006c
end_define

begin_define
define|#
directive|define
name|IPU_CM_INT_CTRL_14
value|0x00000070
end_define

begin_define
define|#
directive|define
name|IPU_CM_INT_CTRL_15
value|0x00000074
end_define

begin_define
define|#
directive|define
name|IPU_CM_SDMA_EVENT_1
value|0x00000078
end_define

begin_define
define|#
directive|define
name|IPU_CM_SDMA_EVENT_2
value|0x0000007c
end_define

begin_define
define|#
directive|define
name|IPU_CM_SDMA_EVENT_3
value|0x00000080
end_define

begin_define
define|#
directive|define
name|IPU_CM_SDMA_EVENT_4
value|0x00000084
end_define

begin_define
define|#
directive|define
name|IPU_CM_SDMA_EVENT_7
value|0x00000088
end_define

begin_define
define|#
directive|define
name|IPU_CM_SDMA_EVENT_8
value|0x0000008c
end_define

begin_define
define|#
directive|define
name|IPU_CM_SDMA_EVENT_11
value|0x00000090
end_define

begin_define
define|#
directive|define
name|IPU_CM_SDMA_EVENT_12
value|0x00000094
end_define

begin_define
define|#
directive|define
name|IPU_CM_SDMA_EVENT_13
value|0x00000098
end_define

begin_define
define|#
directive|define
name|IPU_CM_SDMA_EVENT_14
value|0x0000009c
end_define

begin_define
define|#
directive|define
name|IPU_CM_SRM_PRI1
value|0x000000a0
end_define

begin_define
define|#
directive|define
name|IPU_CM_SRM_PRI2
value|0x000000a4
end_define

begin_define
define|#
directive|define
name|IPU_CM_FS_PROC_FLOW1
value|0x000000a8
end_define

begin_define
define|#
directive|define
name|IPU_CM_FS_PROC_FLOW2
value|0x000000ac
end_define

begin_define
define|#
directive|define
name|IPU_CM_FS_PROC_FLOW3
value|0x000000b0
end_define

begin_define
define|#
directive|define
name|IPU_CM_FS_DISP_FLOW1
value|0x000000b4
end_define

begin_define
define|#
directive|define
name|IPU_CM_FS_DISP_FLOW2
value|0x000000b8
end_define

begin_define
define|#
directive|define
name|IPU_CM_SKIP
value|0x000000bc
end_define

begin_define
define|#
directive|define
name|IPU_CM_DISP_ALT_CONF
value|0x000000c0
end_define

begin_define
define|#
directive|define
name|IPU_CM_DISP_GEN
value|0x000000c4
end_define

begin_define
define|#
directive|define
name|CM_DISP_GEN_DI0_COUNTER_RELEASE
value|0x01000000
end_define

begin_define
define|#
directive|define
name|CM_DISP_GEN_DI1_COUNTER_RELEASE
value|0x00800000
end_define

begin_define
define|#
directive|define
name|CM_DISP_GEN_MCU_MAX_BURST_STOP
value|0x00400000
end_define

begin_define
define|#
directive|define
name|CM_DISP_GEN_MCU_T_SHIFT
value|18
end_define

begin_define
define|#
directive|define
name|CM_DISP_GEN_MCU_T
parameter_list|(
name|n
parameter_list|)
value|((n)<< CM_DISP_GEN_MCU_T_SHIFT)
end_define

begin_define
define|#
directive|define
name|IPU_CM_DISP_ALT1
value|0x000000c8
end_define

begin_define
define|#
directive|define
name|IPU_CM_DISP_ALT2
value|0x000000cc
end_define

begin_define
define|#
directive|define
name|IPU_CM_DISP_ALT3
value|0x000000d0
end_define

begin_define
define|#
directive|define
name|IPU_CM_DISP_ALT4
value|0x000000d4
end_define

begin_define
define|#
directive|define
name|IPU_CM_SNOOP
value|0x000000d8
end_define

begin_define
define|#
directive|define
name|IPU_CM_MEM_RST
value|0x000000dc
end_define

begin_define
define|#
directive|define
name|CM_MEM_START
value|0x80000000
end_define

begin_define
define|#
directive|define
name|CM_MEM_EN
value|0x007fffff
end_define

begin_define
define|#
directive|define
name|IPU_CM_PM
value|0x000000e0
end_define

begin_define
define|#
directive|define
name|IPU_CM_GPR
value|0x000000e4
end_define

begin_define
define|#
directive|define
name|CM_GPR_IPU_CH_BUF1_RDY1_CLR
value|0x80000000
end_define

begin_define
define|#
directive|define
name|CM_GPR_IPU_CH_BUF1_RDY0_CLR
value|0x40000000
end_define

begin_define
define|#
directive|define
name|CM_GPR_IPU_CH_BUF0_RDY1_CLR
value|0x20000000
end_define

begin_define
define|#
directive|define
name|CM_GPR_IPU_CH_BUF0_RDY0_CLR
value|0x10000000
end_define

begin_define
define|#
directive|define
name|CM_GPR_IPU_ALT_CH_BUF1_RDY1_CLR
value|0x08000000
end_define

begin_define
define|#
directive|define
name|CM_GPR_IPU_ALT_CH_BUF1_RDY0_CLR
value|0x04000000
end_define

begin_define
define|#
directive|define
name|CM_GPR_IPU_ALT_CH_BUF0_RDY1_CLR
value|0x02000000
end_define

begin_define
define|#
directive|define
name|CM_GPR_IPU_ALT_CH_BUF0_RDY0_CLR
value|0x01000000
end_define

begin_define
define|#
directive|define
name|CM_GPR_IPU_DI1_CLK_CHANGE_ACK_DIS
value|0x00800000
end_define

begin_define
define|#
directive|define
name|CM_GPR_IPU_DI0_CLK_CHANGE_ACK_DIS
value|0x00400000
end_define

begin_define
define|#
directive|define
name|CM_GPR_IPU_CH_BUF2_RDY1_CLR
value|0x00200000
end_define

begin_define
define|#
directive|define
name|CM_GPR_IPU_CH_BUF2_RDY0_CLR
value|0x00100000
end_define

begin_define
define|#
directive|define
name|CM_GPR_IPU_GP
parameter_list|(
name|n
parameter_list|)
value|__BIT((n))
end_define

begin_define
define|#
directive|define
name|IPU_CM_CH_DB_MODE_SEL_0
value|0x00000150
end_define

begin_define
define|#
directive|define
name|IPU_CM_CH_DB_MODE_SEL_1
value|0x00000154
end_define

begin_define
define|#
directive|define
name|IPU_CM_ALT_CH_DB_MODE_SEL_0
value|0x00000168
end_define

begin_define
define|#
directive|define
name|IPU_CM_ALT_CH_DB_MODE_SEL_1
value|0x0000016c
end_define

begin_define
define|#
directive|define
name|IPU_CM_CH_TRB_MODE_SEL_0
value|0x00000178
end_define

begin_define
define|#
directive|define
name|IPU_CM_CH_TRB_MODE_SEL_1
value|0x0000017c
end_define

begin_define
define|#
directive|define
name|IPU_CM_INT_STAT_1
value|0x00000200
end_define

begin_define
define|#
directive|define
name|IPU_CM_INT_STAT_2
value|0x00000204
end_define

begin_define
define|#
directive|define
name|IPU_CM_INT_STAT_3
value|0x00000208
end_define

begin_define
define|#
directive|define
name|IPU_CM_INT_STAT_4
value|0x0000020c
end_define

begin_define
define|#
directive|define
name|IPU_CM_INT_STAT_5
value|0x00000210
end_define

begin_define
define|#
directive|define
name|IPU_CM_INT_STAT_6
value|0x00000214
end_define

begin_define
define|#
directive|define
name|IPU_CM_INT_STAT_7
value|0x00000218
end_define

begin_define
define|#
directive|define
name|IPU_CM_INT_STAT_8
value|0x0000021c
end_define

begin_define
define|#
directive|define
name|IPU_CM_INT_STAT_9
value|0x00000220
end_define

begin_define
define|#
directive|define
name|IPU_CM_INT_STAT_10
value|0x00000224
end_define

begin_define
define|#
directive|define
name|IPU_CM_INT_STAT_11
value|0x00000228
end_define

begin_define
define|#
directive|define
name|IPU_CM_INT_STAT_12
value|0x0000022c
end_define

begin_define
define|#
directive|define
name|IPU_CM_INT_STAT_13
value|0x00000230
end_define

begin_define
define|#
directive|define
name|IPU_CM_INT_STAT_14
value|0x00000234
end_define

begin_define
define|#
directive|define
name|IPU_CM_INT_STAT_15
value|0x00000238
end_define

begin_define
define|#
directive|define
name|IPU_CM_CUR_BUF_0
value|0x0000023c
end_define

begin_define
define|#
directive|define
name|IPU_CM_CUR_BUF_1
value|0x00000240
end_define

begin_define
define|#
directive|define
name|IPU_CM_ALT_CUR_BUF_0
value|0x00000244
end_define

begin_define
define|#
directive|define
name|IPU_CM_ALT_CUR_BUF_1
value|0x00000248
end_define

begin_define
define|#
directive|define
name|IPU_CM_SRM_STAT
value|0x0000024c
end_define

begin_define
define|#
directive|define
name|IPU_CM_PROC_TASKS_STAT
value|0x00000250
end_define

begin_define
define|#
directive|define
name|IPU_CM_DISP_TASKS_STAT
value|0x00000254
end_define

begin_define
define|#
directive|define
name|IPU_CM_TRIPLE_CUR_BUF_0
value|0x00000258
end_define

begin_define
define|#
directive|define
name|IPU_CM_TRIPLE_CUR_BUF_1
value|0x0000025c
end_define

begin_define
define|#
directive|define
name|IPU_CM_TRIPLE_CUR_BUF_2
value|0x00000260
end_define

begin_define
define|#
directive|define
name|IPU_CM_TRIPLE_CUR_BUF_3
value|0x00000264
end_define

begin_define
define|#
directive|define
name|IPU_CM_CH_BUF0_RDY0
value|0x00000268
end_define

begin_define
define|#
directive|define
name|IPU_CM_CH_BUF0_RDY1
value|0x0000026c
end_define

begin_define
define|#
directive|define
name|IPU_CM_CH_BUF1_RDY0
value|0x00000270
end_define

begin_define
define|#
directive|define
name|IPU_CM_CH_BUF1_RDY1
value|0x00000274
end_define

begin_define
define|#
directive|define
name|IPU_CM_ALT_CH_BUF0_RDY0
value|0x00000278
end_define

begin_define
define|#
directive|define
name|IPU_CM_ALT_CH_BUF0_RDY1
value|0x0000027c
end_define

begin_define
define|#
directive|define
name|IPU_CM_ALT_CH_BUF1_RDY0
value|0x00000280
end_define

begin_define
define|#
directive|define
name|IPU_CM_ALT_CH_BUF1_RDY1
value|0x00000284
end_define

begin_define
define|#
directive|define
name|IPU_CM_CH_BUF2_RDY0
value|0x00000288
end_define

begin_define
define|#
directive|define
name|IPU_CM_CH_BUF2_RDY1
value|0x0000028c
end_define

begin_comment
comment|/*  * IDMAC  * Image DMA Controller  */
end_comment

begin_define
define|#
directive|define
name|IPU_IDMAC_CONF
value|0x00000000
end_define

begin_define
define|#
directive|define
name|IPU_IDMAC_CH_EN_1
value|0x00000004
end_define

begin_define
define|#
directive|define
name|IPU_IDMAC_CH_EN_2
value|0x00000008
end_define

begin_define
define|#
directive|define
name|IPU_IDMAC_SEP_ALPHA
value|0x0000000c
end_define

begin_define
define|#
directive|define
name|IPU_IDMAC_ALT_SEP_ALPHA
value|0x00000010
end_define

begin_define
define|#
directive|define
name|IPU_IDMAC_CH_PRI_1
value|0x00000014
end_define

begin_define
define|#
directive|define
name|IPU_IDMAC_CH_PRI_2
value|0x00000018
end_define

begin_define
define|#
directive|define
name|IPU_IDMAC_WM_EN_1
value|0x0000001c
end_define

begin_define
define|#
directive|define
name|IPU_IDMAC_WM_EN_2
value|0x00000020
end_define

begin_define
define|#
directive|define
name|IPU_IDMAC_LOCK_EN_1
value|0x00000024
end_define

begin_define
define|#
directive|define
name|IPU_IDMAC_LOCK_EN_2
value|0x00000028
end_define

begin_define
define|#
directive|define
name|IPU_IDMAC_SUB_ADDR_0
value|0x0000002c
end_define

begin_define
define|#
directive|define
name|IPU_IDMAC_SUB_ADDR_1
value|0x00000030
end_define

begin_define
define|#
directive|define
name|IPU_IDMAC_SUB_ADDR_2
value|0x00000034
end_define

begin_define
define|#
directive|define
name|IPU_IDMAC_SUB_ADDR_3
value|0x00000038
end_define

begin_define
define|#
directive|define
name|IPU_IDMAC_SUB_ADDR_4
value|0x0000003c
end_define

begin_define
define|#
directive|define
name|IPU_IDMAC_BNDM_EN_1
value|0x00000040
end_define

begin_define
define|#
directive|define
name|IPU_IDMAC_BNDM_EN_2
value|0x00000044
end_define

begin_define
define|#
directive|define
name|IPU_IDMAC_SC_CORD
value|0x00000048
end_define

begin_define
define|#
directive|define
name|IPU_IDMAC_SC_CORD1
value|0x0000004c
end_define

begin_define
define|#
directive|define
name|IPU_IDMAC_CH_BUSY_1
value|0x00000100
end_define

begin_define
define|#
directive|define
name|IPU_IDMAC_CH_BUSY_2
value|0x00000104
end_define

begin_define
define|#
directive|define
name|CH_PANNEL_BG
value|23
end_define

begin_define
define|#
directive|define
name|CH_PANNEL_FG
value|27
end_define

begin_comment
comment|/*  * DP  * Display Port  */
end_comment

begin_define
define|#
directive|define
name|IPU_DP_DEBUG_CNT
value|0x000000bc
end_define

begin_define
define|#
directive|define
name|IPU_DP_DEBUG_STAT
value|0x000000c0
end_define

begin_comment
comment|/*  * IC  * Image Converter  */
end_comment

begin_define
define|#
directive|define
name|IPU_IC_CONF
value|0x00000000
end_define

begin_define
define|#
directive|define
name|IPU_IC_PRP_ENC_RSC
value|0x00000004
end_define

begin_define
define|#
directive|define
name|IPU_IC_PRP_VF_RSC
value|0x00000008
end_define

begin_define
define|#
directive|define
name|IPU_IC_PP_RSC
value|0x0000000c
end_define

begin_define
define|#
directive|define
name|IPU_IC_CMBP_1
value|0x00000010
end_define

begin_define
define|#
directive|define
name|IPU_IC_CMBP_2
value|0x00000014
end_define

begin_define
define|#
directive|define
name|IPU_IC_IDMAC_1
value|0x00000018
end_define

begin_define
define|#
directive|define
name|IPU_IC_IDMAC_2
value|0x0000001c
end_define

begin_define
define|#
directive|define
name|IPU_IC_IDMAC_3
value|0x00000020
end_define

begin_define
define|#
directive|define
name|IPU_IC_IDMAC_4
value|0x00000024
end_define

begin_comment
comment|/*  * CSI  * Camera Sensor Interface  */
end_comment

begin_define
define|#
directive|define
name|IPU_CSI0_SENS_CONF
value|0x00000000
end_define

begin_define
define|#
directive|define
name|IPU_CSI0_SENS_FRM_SIZE
value|0x00000004
end_define

begin_define
define|#
directive|define
name|IPU_CSI0_ACT_FRM_SIZE
value|0x00000008
end_define

begin_define
define|#
directive|define
name|IPU_CSI0_OUT_FRM_CTRL
value|0x0000000c
end_define

begin_define
define|#
directive|define
name|IPU_CSI0_TST_CTRL
value|0x00000010
end_define

begin_define
define|#
directive|define
name|IPU_CSI0_CCIR_CODE_1
value|0x00000014
end_define

begin_define
define|#
directive|define
name|IPU_CSI0_CCIR_CODE_2
value|0x00000018
end_define

begin_define
define|#
directive|define
name|IPU_CSI0_CCIR_CODE_3
value|0x0000001c
end_define

begin_define
define|#
directive|define
name|IPU_CSI0_DI
value|0x00000020
end_define

begin_define
define|#
directive|define
name|IPU_CSI0_SKIP
value|0x00000024
end_define

begin_define
define|#
directive|define
name|IPU_CSI0_CPD_CTRL
value|0x00000028
end_define

begin_define
define|#
directive|define
name|IPU_CSI0_CPD_OFFSET1
value|0x000000ec
end_define

begin_define
define|#
directive|define
name|IPU_CSI0_CPD_OFFSET2
value|0x000000f0
end_define

begin_define
define|#
directive|define
name|IPU_CSI1_SENS_CONF
value|0x00000000
end_define

begin_define
define|#
directive|define
name|IPU_CSI1_SENS_FRM_SIZE
value|0x00000004
end_define

begin_define
define|#
directive|define
name|IPU_CSI1_ACT_FRM_SIZE
value|0x00000008
end_define

begin_define
define|#
directive|define
name|IPU_CSI1_OUT_FRM_CTRL
value|0x0000000c
end_define

begin_define
define|#
directive|define
name|IPU_CSI1_TST_CTRL
value|0x00000010
end_define

begin_define
define|#
directive|define
name|IPU_CSI1_CCIR_CODE_1
value|0x00000014
end_define

begin_define
define|#
directive|define
name|IPU_CSI1_CCIR_CODE_2
value|0x00000018
end_define

begin_define
define|#
directive|define
name|IPU_CSI1_CCIR_CODE_3
value|0x0000001c
end_define

begin_define
define|#
directive|define
name|IPU_CSI1_DI
value|0x00000020
end_define

begin_define
define|#
directive|define
name|IPU_CSI1_SKIP
value|0x00000024
end_define

begin_define
define|#
directive|define
name|IPU_CSI1_CPD_CTRL
value|0x00000028
end_define

begin_define
define|#
directive|define
name|IPU_CSI1_CPD_OFFSET1
value|0x000000ec
end_define

begin_define
define|#
directive|define
name|IPU_CSI1_CPD_OFFSET2
value|0x000000f0
end_define

begin_comment
comment|/*  * DI  * Display Interface  */
end_comment

begin_define
define|#
directive|define
name|IPU_DI_GENERAL
value|0x00000000
end_define

begin_define
define|#
directive|define
name|DI_GENERAL_DISP_Y_SEL
value|0x70000000
end_define

begin_define
define|#
directive|define
name|DI_GENERAL_CLOCK_STOP_MODE
value|0x0f000000
end_define

begin_define
define|#
directive|define
name|DI_GENERAL_DISP_CLOCK_INIT
value|0x00800000
end_define

begin_define
define|#
directive|define
name|DI_GENERAL_MASK_SEL
value|0x00400000
end_define

begin_define
define|#
directive|define
name|DI_GENERAL_VSYNC_EXT
value|0x00200000
end_define

begin_define
define|#
directive|define
name|DI_GENERAL_CLK_EXT
value|0x00100000
end_define

begin_define
define|#
directive|define
name|DI_GENERAL_WATCHDOG_MODE
value|0x000c0000
end_define

begin_define
define|#
directive|define
name|DI_GENERAL_POLARITY_DISP_CLK
value|0x00020000
end_define

begin_define
define|#
directive|define
name|DI_GENERAL_SYNC_COUNT_SEL
value|0x0000f000
end_define

begin_define
define|#
directive|define
name|DI_GENERAL_ERR_TREATMENT
value|0x00000800
end_define

begin_define
define|#
directive|define
name|DI_GENERAL_ERM_VSYNC_SEL
value|0x00000400
end_define

begin_define
define|#
directive|define
name|DI_GENERAL_POLARITY_CS
parameter_list|(
name|n
parameter_list|)
value|(1<< ((n) + 8))
end_define

begin_define
define|#
directive|define
name|DI_GENERAL_POLARITY
parameter_list|(
name|n
parameter_list|)
value|(1<< ((n) - 1))
end_define

begin_define
define|#
directive|define
name|IPU_DI_BS_CLKGEN0
value|0x00000004
end_define

begin_define
define|#
directive|define
name|DI_BS_CLKGEN0_OFFSET_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|IPU_DI_BS_CLKGEN1
value|0x00000008
end_define

begin_define
define|#
directive|define
name|DI_BS_CLKGEN1_DOWN_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|DI_BS_CLKGEN1_UP_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|IPU_DI_SW_GEN0
parameter_list|(
name|n
parameter_list|)
value|(0x0000000c + ((n) - 1) * 4)
end_define

begin_define
define|#
directive|define
name|DI_SW_GEN0_RUN_VAL
value|0x7ff80000
end_define

begin_define
define|#
directive|define
name|DI_SW_GEN0_RUN_RESOL
value|0x00070000
end_define

begin_define
define|#
directive|define
name|DI_SW_GEN0_OFFSET_VAL
value|0x00007ff8
end_define

begin_define
define|#
directive|define
name|DI_SW_GEN0_OFFSET_RESOL
value|0x00000007
end_define

begin_define
define|#
directive|define
name|__DI_SW_GEN0
parameter_list|(
name|run_val
parameter_list|,
name|run_resol
parameter_list|,
name|offset_val
parameter_list|,
name|offset_resol
parameter_list|)
define|\
value|(((run_val)<< 19) | ((run_resol)<< 16) | 			\ 	 ((offset_val)<< 3) | (offset_resol))
end_define

begin_define
define|#
directive|define
name|IPU_DI_SW_GEN1
parameter_list|(
name|n
parameter_list|)
value|(0x00000030 + ((n) - 1) * 4)
end_define

begin_define
define|#
directive|define
name|DI_SW_GEN1_CNT_POL_GEN_EN
value|0x60000000
end_define

begin_define
define|#
directive|define
name|DI_SW_GEN1_CNT_AUTO_RELOAD
value|0x10000000
end_define

begin_define
define|#
directive|define
name|DI_SW_GEN1_CNT_CLR_SEL
value|0x0e000000
end_define

begin_define
define|#
directive|define
name|DI_SW_GEN1_CNT_DOWN
value|0x01ff0000
end_define

begin_define
define|#
directive|define
name|DI_SW_GEN1_CNT_POL_TRIG_SEL
value|0x00007000
end_define

begin_define
define|#
directive|define
name|DI_SW_GEN1_CNT_POL_CLR_SEL
value|0x00000e00
end_define

begin_define
define|#
directive|define
name|DI_SW_GEN1_CNT_UP
value|0x000001ff
end_define

begin_define
define|#
directive|define
name|__DI_SW_GEN1
parameter_list|(
name|pol_gen_en
parameter_list|,
name|auto_reload
parameter_list|,
name|clr_sel
parameter_list|,
name|down
parameter_list|,
name|pol_trig_sel
parameter_list|,
name|pol_clr_sel
parameter_list|,
name|up
parameter_list|)
define|\
value|(((pol_gen_en)<< 29) | ((auto_reload)<< 28) | \ 	 ((clr_sel)<< 25) |				\ 	    ((down)<< 16) | ((pol_trig_sel)<< 12) |	\ 	 ((pol_clr_sel)<< 9) | (up))
end_define

begin_define
define|#
directive|define
name|IPU_DI_SYNC_AS_GEN
value|0x00000054
end_define

begin_define
define|#
directive|define
name|DI_SYNC_AS_GEN_SYNC_START_EN
value|0x10000000
end_define

begin_define
define|#
directive|define
name|DI_SYNC_AS_GEN_VSYNC_SEL
value|0x0000e000
end_define

begin_define
define|#
directive|define
name|DI_SYNC_AS_GEN_VSYNC_SEL_SHIFT
value|13
end_define

begin_define
define|#
directive|define
name|DI_SYNC_AS_GEN_SYNC_STAR
value|0x00000fff
end_define

begin_define
define|#
directive|define
name|IPU_DI_DW_GEN
parameter_list|(
name|n
parameter_list|)
value|(0x00000058 + (n) * 4)
end_define

begin_define
define|#
directive|define
name|DI_DW_GEN_ACCESS_SIZE_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|DI_DW_GEN_COMPONNENT_SIZE_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|DI_DW_GEN_PIN_SHIFT
parameter_list|(
name|n
parameter_list|)
value|(((n) - 11) * 2)
end_define

begin_define
define|#
directive|define
name|DI_DW_GEN_PIN
parameter_list|(
name|n
parameter_list|)
value|__BITS(DI_DW_GEN_PIN_SHIFT(n) + 1, \ 					       DI_DW_GEN_PIN_SHIFT(n))
end_define

begin_define
define|#
directive|define
name|IPU_DI_DW_SET
parameter_list|(
name|n
parameter_list|,
name|m
parameter_list|)
value|(0x00000088 + (n) * 4 + (m) * 0x30)
end_define

begin_define
define|#
directive|define
name|DI_DW_SET_DOWN_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|DI_DW_SET_UP_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|IPU_DI_STP_REP
parameter_list|(
name|n
parameter_list|)
value|(0x00000148 + ((n - 1) / 2) * 4)
end_define

begin_define
define|#
directive|define
name|DI_STP_REP_SHIFT
parameter_list|(
name|n
parameter_list|)
value|(((n - 1) % 2) * 16)
end_define

begin_define
define|#
directive|define
name|DI_STP_REP_MASK
parameter_list|(
name|n
parameter_list|)
value|(0x00000fff<< DI_STP_REP_SHIFT((n)))
end_define

begin_define
define|#
directive|define
name|IPU_DI_SER_CONF
value|0x0000015c
end_define

begin_define
define|#
directive|define
name|IPU_DI_SSC
value|0x00000160
end_define

begin_define
define|#
directive|define
name|IPU_DI_POL
value|0x00000164
end_define

begin_define
define|#
directive|define
name|DI_POL_DRDY_POLARITY_17
value|0x00000040
end_define

begin_define
define|#
directive|define
name|DI_POL_DRDY_POLARITY_16
value|0x00000020
end_define

begin_define
define|#
directive|define
name|DI_POL_DRDY_POLARITY_15
value|0x00000010
end_define

begin_define
define|#
directive|define
name|DI_POL_DRDY_POLARITY_14
value|0x00000008
end_define

begin_define
define|#
directive|define
name|DI_POL_DRDY_POLARITY_13
value|0x00000004
end_define

begin_define
define|#
directive|define
name|DI_POL_DRDY_POLARITY_12
value|0x00000002
end_define

begin_define
define|#
directive|define
name|DI_POL_DRDY_POLARITY_11
value|0x00000001
end_define

begin_define
define|#
directive|define
name|IPU_DI_AW0
value|0x00000168
end_define

begin_define
define|#
directive|define
name|IPU_DI_AW1
value|0x0000016c
end_define

begin_define
define|#
directive|define
name|IPU_DI_SCR_CONF
value|0x00000170
end_define

begin_define
define|#
directive|define
name|IPU_DI_STAT
value|0x00000174
end_define

begin_comment
comment|/*  * SMFC  * Sensor Multi FIFO Controller  */
end_comment

begin_define
define|#
directive|define
name|IPU_SMFC_MAP
value|0x00000000
end_define

begin_define
define|#
directive|define
name|IPU_SMFC_WMC
value|0x00000004
end_define

begin_define
define|#
directive|define
name|IPU_SMFC_BS
value|0x00000008
end_define

begin_comment
comment|/*  * DC  * Display Controller  */
end_comment

begin_define
define|#
directive|define
name|IPU_DC_READ_CH_CONF
value|0x00000000
end_define

begin_define
define|#
directive|define
name|IPU_DC_READ_CH_ADDR
value|0x00000004
end_define

begin_define
define|#
directive|define
name|IPU_DC_RL0_CH_0
value|0x00000008
end_define

begin_define
define|#
directive|define
name|IPU_DC_RL1_CH_0
value|0x0000000c
end_define

begin_define
define|#
directive|define
name|IPU_DC_RL2_CH_0
value|0x00000010
end_define

begin_define
define|#
directive|define
name|IPU_DC_RL3_CH_0
value|0x00000014
end_define

begin_define
define|#
directive|define
name|IPU_DC_RL4_CH_0
value|0x00000018
end_define

begin_define
define|#
directive|define
name|IPU_DC_WR_CH_CONF_1
value|0x0000001c
end_define

begin_define
define|#
directive|define
name|IPU_DC_WR_CH_ADDR_1
value|0x00000020
end_define

begin_define
define|#
directive|define
name|IPU_DC_RL0_CH_1
value|0x00000024
end_define

begin_define
define|#
directive|define
name|IPU_DC_RL1_CH_1
value|0x00000028
end_define

begin_define
define|#
directive|define
name|IPU_DC_RL2_CH_1
value|0x0000002c
end_define

begin_define
define|#
directive|define
name|IPU_DC_RL3_CH_1
value|0x00000030
end_define

begin_define
define|#
directive|define
name|IPU_DC_RL4_CH_1
value|0x00000034
end_define

begin_define
define|#
directive|define
name|IPU_DC_WR_CH_CONF_2
value|0x00000038
end_define

begin_define
define|#
directive|define
name|IPU_DC_WR_CH_ADDR_2
value|0x0000003c
end_define

begin_define
define|#
directive|define
name|IPU_DC_RL0_CH_2
value|0x00000040
end_define

begin_define
define|#
directive|define
name|IPU_DC_RL1_CH_2
value|0x00000044
end_define

begin_define
define|#
directive|define
name|IPU_DC_RL2_CH_2
value|0x00000048
end_define

begin_define
define|#
directive|define
name|IPU_DC_RL3_CH_2
value|0x0000004c
end_define

begin_define
define|#
directive|define
name|IPU_DC_RL4_CH_2
value|0x00000050
end_define

begin_define
define|#
directive|define
name|IPU_DC_CMD_CH_CONF_3
value|0x00000054
end_define

begin_define
define|#
directive|define
name|IPU_DC_CMD_CH_CONF_4
value|0x00000058
end_define

begin_define
define|#
directive|define
name|IPU_DC_WR_CH_CONF_5
value|0x0000005c
end_define

begin_define
define|#
directive|define
name|IPU_DC_WR_CH_ADDR_5
value|0x00000060
end_define

begin_define
define|#
directive|define
name|IPU_DC_RL0_CH_5
value|0x00000064
end_define

begin_define
define|#
directive|define
name|IPU_DC_RL1_CH_5
value|0x00000068
end_define

begin_define
define|#
directive|define
name|IPU_DC_RL2_CH_5
value|0x0000006c
end_define

begin_define
define|#
directive|define
name|IPU_DC_RL3_CH_5
value|0x00000070
end_define

begin_define
define|#
directive|define
name|IPU_DC_RL4_CH_5
value|0x00000074
end_define

begin_define
define|#
directive|define
name|IPU_DC_WR_CH_CONF_6
value|0x00000078
end_define

begin_define
define|#
directive|define
name|IPU_DC_WR_CH_ADDR_6
value|0x0000007c
end_define

begin_define
define|#
directive|define
name|IPU_DC_RL0_CH_6
value|0x00000080
end_define

begin_define
define|#
directive|define
name|IPU_DC_RL1_CH_6
value|0x00000084
end_define

begin_define
define|#
directive|define
name|IPU_DC_RL2_CH_6
value|0x00000088
end_define

begin_define
define|#
directive|define
name|IPU_DC_RL3_CH_6
value|0x0000008c
end_define

begin_define
define|#
directive|define
name|IPU_DC_RL4_CH_6
value|0x00000090
end_define

begin_define
define|#
directive|define
name|IPU_DC_WR_CH_CONF1_8
value|0x00000094
end_define

begin_define
define|#
directive|define
name|IPU_DC_WR_CH_CONF2_8
value|0x00000098
end_define

begin_define
define|#
directive|define
name|IPU_DC_RL1_CH_8
value|0x0000009c
end_define

begin_define
define|#
directive|define
name|IPU_DC_RL2_CH_8
value|0x000000a0
end_define

begin_define
define|#
directive|define
name|IPU_DC_RL3_CH_8
value|0x000000a4
end_define

begin_define
define|#
directive|define
name|IPU_DC_RL4_CH_8
value|0x000000a8
end_define

begin_define
define|#
directive|define
name|IPU_DC_RL5_CH_8
value|0x000000ac
end_define

begin_define
define|#
directive|define
name|IPU_DC_RL6_CH_8
value|0x000000b0
end_define

begin_define
define|#
directive|define
name|IPU_DC_WR_CH_CONF1_9
value|0x000000b4
end_define

begin_define
define|#
directive|define
name|IPU_DC_WR_CH_CONF2_9
value|0x000000b8
end_define

begin_define
define|#
directive|define
name|IPU_DC_RL1_CH_9
value|0x000000bc
end_define

begin_define
define|#
directive|define
name|IPU_DC_RL2_CH_9
value|0x000000c0
end_define

begin_define
define|#
directive|define
name|IPU_DC_RL3_CH_9
value|0x000000c4
end_define

begin_define
define|#
directive|define
name|IPU_DC_RL4_CH_9
value|0x000000c8
end_define

begin_define
define|#
directive|define
name|IPU_DC_RL5_CH_9
value|0x000000cc
end_define

begin_define
define|#
directive|define
name|IPU_DC_RL6_CH_9
value|0x000000d0
end_define

begin_define
define|#
directive|define
name|IPU_DC_RL
parameter_list|(
name|chan_base
parameter_list|,
name|evt
parameter_list|)
value|((chan_base) + (evt / 2) *0x4)
end_define

begin_define
define|#
directive|define
name|DC_RL_CH_0
value|IPU_DC_RL0_CH_0
end_define

begin_define
define|#
directive|define
name|DC_RL_CH_1
value|IPU_DC_RL0_CH_1
end_define

begin_define
define|#
directive|define
name|DC_RL_CH_2
value|IPU_DC_RL0_CH_2
end_define

begin_define
define|#
directive|define
name|DC_RL_CH_5
value|IPU_DC_RL0_CH_5
end_define

begin_define
define|#
directive|define
name|DC_RL_CH_6
value|IPU_DC_RL0_CH_6
end_define

begin_define
define|#
directive|define
name|DC_RL_CH_8
value|IPU_DC_RL0_CH_8
end_define

begin_define
define|#
directive|define
name|DC_RL_EVT_NF
value|0
end_define

begin_define
define|#
directive|define
name|DC_RL_EVT_NL
value|1
end_define

begin_define
define|#
directive|define
name|DC_RL_EVT_EOF
value|2
end_define

begin_define
define|#
directive|define
name|DC_RL_EVT_NFIELD
value|3
end_define

begin_define
define|#
directive|define
name|DC_RL_EVT_EOL
value|4
end_define

begin_define
define|#
directive|define
name|DC_RL_EVT_EOFIELD
value|5
end_define

begin_define
define|#
directive|define
name|DC_RL_EVT_NEW_ADDR
value|6
end_define

begin_define
define|#
directive|define
name|DC_RL_EVT_NEW_CHAN
value|7
end_define

begin_define
define|#
directive|define
name|DC_RL_EVT_NEW_DATA
value|8
end_define

begin_define
define|#
directive|define
name|IPU_DC_GEN
value|0x000000d4
end_define

begin_define
define|#
directive|define
name|IPU_DC_DISP_CONF1_0
value|0x000000d8
end_define

begin_define
define|#
directive|define
name|IPU_DC_DISP_CONF1_1
value|0x000000dc
end_define

begin_define
define|#
directive|define
name|IPU_DC_DISP_CONF1_2
value|0x000000e0
end_define

begin_define
define|#
directive|define
name|IPU_DC_DISP_CONF1_3
value|0x000000e4
end_define

begin_define
define|#
directive|define
name|IPU_DC_DISP_CONF2_0
value|0x000000e8
end_define

begin_define
define|#
directive|define
name|IPU_DC_DISP_CONF2_1
value|0x000000ec
end_define

begin_define
define|#
directive|define
name|IPU_DC_DISP_CONF2_2
value|0x000000f0
end_define

begin_define
define|#
directive|define
name|IPU_DC_DISP_CONF2_3
value|0x000000f4
end_define

begin_define
define|#
directive|define
name|IPU_DC_DI0_CONF_1
value|0x000000f8
end_define

begin_define
define|#
directive|define
name|IPU_DC_DI0_CONF_2
value|0x000000fc
end_define

begin_define
define|#
directive|define
name|IPU_DC_DI1_CONF_1
value|0x00000100
end_define

begin_define
define|#
directive|define
name|IPU_DC_DI1_CONF_2
value|0x00000104
end_define

begin_define
define|#
directive|define
name|IPU_DC_MAP_CONF_PNTR
parameter_list|(
name|n
parameter_list|)
value|(0x00000108 + (n) * 4)
end_define

begin_define
define|#
directive|define
name|IPU_DC_MAP_CONF_0
value|0x00000108
end_define

begin_define
define|#
directive|define
name|IPU_DC_MAP_CONF_1
value|0x0000010c
end_define

begin_define
define|#
directive|define
name|IPU_DC_MAP_CONF_2
value|0x00000110
end_define

begin_define
define|#
directive|define
name|IPU_DC_MAP_CONF_3
value|0x00000114
end_define

begin_define
define|#
directive|define
name|IPU_DC_MAP_CONF_4
value|0x00000118
end_define

begin_define
define|#
directive|define
name|IPU_DC_MAP_CONF_5
value|0x0000011c
end_define

begin_define
define|#
directive|define
name|IPU_DC_MAP_CONF_6
value|0x00000120
end_define

begin_define
define|#
directive|define
name|IPU_DC_MAP_CONF_7
value|0x00000124
end_define

begin_define
define|#
directive|define
name|IPU_DC_MAP_CONF_8
value|0x00000128
end_define

begin_define
define|#
directive|define
name|IPU_DC_MAP_CONF_9
value|0x0000012c
end_define

begin_define
define|#
directive|define
name|IPU_DC_MAP_CONF_10
value|0x00000130
end_define

begin_define
define|#
directive|define
name|IPU_DC_MAP_CONF_11
value|0x00000134
end_define

begin_define
define|#
directive|define
name|IPU_DC_MAP_CONF_12
value|0x00000138
end_define

begin_define
define|#
directive|define
name|IPU_DC_MAP_CONF_13
value|0x0000013c
end_define

begin_define
define|#
directive|define
name|IPU_DC_MAP_CONF_14
value|0x00000140
end_define

begin_define
define|#
directive|define
name|IPU_DC_MAP_CONF_MASK
parameter_list|(
name|n
parameter_list|)
value|(0x00000144 + (n) * 4)
end_define

begin_define
define|#
directive|define
name|IPU_DC_MAP_CONF_15
value|0x00000144
end_define

begin_define
define|#
directive|define
name|IPU_DC_MAP_CONF_16
value|0x00000148
end_define

begin_define
define|#
directive|define
name|IPU_DC_MAP_CONF_17
value|0x0000014c
end_define

begin_define
define|#
directive|define
name|IPU_DC_MAP_CONF_18
value|0x00000150
end_define

begin_define
define|#
directive|define
name|IPU_DC_MAP_CONF_19
value|0x00000154
end_define

begin_define
define|#
directive|define
name|IPU_DC_MAP_CONF_20
value|0x00000158
end_define

begin_define
define|#
directive|define
name|IPU_DC_MAP_CONF_21
value|0x0000015c
end_define

begin_define
define|#
directive|define
name|IPU_DC_MAP_CONF_22
value|0x00000160
end_define

begin_define
define|#
directive|define
name|IPU_DC_MAP_CONF_23
value|0x00000164
end_define

begin_define
define|#
directive|define
name|IPU_DC_MAP_CONF_24
value|0x00000168
end_define

begin_define
define|#
directive|define
name|IPU_DC_MAP_CONF_25
value|0x0000016c
end_define

begin_define
define|#
directive|define
name|IPU_DC_MAP_CONF_26
value|0x00000170
end_define

begin_define
define|#
directive|define
name|IPU_DC_UGDE
parameter_list|(
name|m
parameter_list|,
name|n
parameter_list|)
value|(0x00000174 + (m) * 0x10 + (n) +4)
end_define

begin_define
define|#
directive|define
name|IPU_DC_UGDE0_0
value|0x00000174
end_define

begin_define
define|#
directive|define
name|IPU_DC_UGDE0_1
value|0x00000178
end_define

begin_define
define|#
directive|define
name|IPU_DC_UGDE0_2
value|0x0000017c
end_define

begin_define
define|#
directive|define
name|IPU_DC_UGDE0_3
value|0x00000180
end_define

begin_define
define|#
directive|define
name|IPU_DC_UGDE1_0
value|0x00000184
end_define

begin_define
define|#
directive|define
name|IPU_DC_UGDE1_1
value|0x00000188
end_define

begin_define
define|#
directive|define
name|IPU_DC_UGDE1_2
value|0x0000018c
end_define

begin_define
define|#
directive|define
name|IPU_DC_UGDE1_3
value|0x00000190
end_define

begin_define
define|#
directive|define
name|IPU_DC_UGDE2_0
value|0x00000194
end_define

begin_define
define|#
directive|define
name|IPU_DC_UGDE2_1
value|0x00000198
end_define

begin_define
define|#
directive|define
name|IPU_DC_UGDE2_2
value|0x0000019c
end_define

begin_define
define|#
directive|define
name|IPU_DC_UGDE2_3
value|0x000001a0
end_define

begin_define
define|#
directive|define
name|IPU_DC_UGDE3_0
value|0x000001a4
end_define

begin_define
define|#
directive|define
name|IPU_DC_UGDE3_1
value|0x000001a8
end_define

begin_define
define|#
directive|define
name|IPU_DC_UGDE3_2
value|0x000001ac
end_define

begin_define
define|#
directive|define
name|IPU_DC_UGDE3_3
value|0x000001b0
end_define

begin_define
define|#
directive|define
name|IPU_DC_LLA0
value|0x000001b4
end_define

begin_define
define|#
directive|define
name|IPU_DC_LLA1
value|0x000001b8
end_define

begin_define
define|#
directive|define
name|IPU_DC_R_LLA0
value|0x000001bc
end_define

begin_define
define|#
directive|define
name|IPU_DC_R_LLA1
value|0x000001c0
end_define

begin_define
define|#
directive|define
name|IPU_DC_WR_CH_ADDR_5_ALT
value|0x000001c4
end_define

begin_define
define|#
directive|define
name|IPU_DC_STAT
value|0x000001c8
end_define

begin_comment
comment|/*  * DMFC  * Display Multi FIFO Controller  */
end_comment

begin_define
define|#
directive|define
name|IPU_DMFC_RD_CHAN
value|0x00000000
end_define

begin_define
define|#
directive|define
name|DMFC_RD_CHAN_PPW_C
value|0x03000000
end_define

begin_define
define|#
directive|define
name|DMFC_RD_CHAN_WM_DR_0
value|0x00e00000
end_define

begin_define
define|#
directive|define
name|DMFC_RD_CHAN_WM_SET_0
value|0x001c0000
end_define

begin_define
define|#
directive|define
name|DMFC_RD_CHAN_WM_EN_0
value|0x00020000
end_define

begin_define
define|#
directive|define
name|DMFC_RD_CHAN_BURST_SIZE_0
value|0x000000c0
end_define

begin_define
define|#
directive|define
name|IPU_DMFC_WR_CHAN
value|0x00000004
end_define

begin_define
define|#
directive|define
name|DMFC_WR_CHAN_BUSRT_SIZE_2C
value|0xc0000000
end_define

begin_define
define|#
directive|define
name|DMFC_WR_CHAN_FIFO_SIZE_2C
value|0x38000000
end_define

begin_define
define|#
directive|define
name|DMFC_WR_CHAN_ST_ADDR_2C
value|0x07000000
end_define

begin_define
define|#
directive|define
name|DMFC_WR_CHAN_BURST_SIZE_1C
value|0x00c00000
end_define

begin_define
define|#
directive|define
name|DMFC_WR_CHAN_FIFO_SIZE_1C
value|0x00380000
end_define

begin_define
define|#
directive|define
name|DMFC_WR_CHAN_ST_ADDR_1C
value|0x00070000
end_define

begin_define
define|#
directive|define
name|DMFC_WR_CHAN_BURST_SIZE_2
value|0x0000c000
end_define

begin_define
define|#
directive|define
name|DMFC_WR_CHAN_FIFO_SIZE_2
value|0x00003800
end_define

begin_define
define|#
directive|define
name|DMFC_WR_CHAN_ST_ADDR_2
value|0x00000700
end_define

begin_define
define|#
directive|define
name|DMFC_WR_CHAN_BURST_SIZE_1
value|0x000000c0
end_define

begin_define
define|#
directive|define
name|DMFC_WR_CHAN_FIFO_SIZE_1
value|0x00000038
end_define

begin_define
define|#
directive|define
name|DMFC_WR_CHAN_ST_ADDR_1
value|0x00000007
end_define

begin_define
define|#
directive|define
name|IPU_DMFC_WR_CHAN_DEF
value|0x00000008
end_define

begin_define
define|#
directive|define
name|DMFC_WR_CHAN_DEF_WM_CLR_2C
value|0xe0000000
end_define

begin_define
define|#
directive|define
name|DMFC_WR_CHAN_DEF_WM_SET_2C
value|0x1c000000
end_define

begin_define
define|#
directive|define
name|DMFC_WR_CHAN_DEF_WM_EN_2C
value|0x02000000
end_define

begin_define
define|#
directive|define
name|DMFC_WR_CHAN_DEF_WM_CLR_1C
value|0x00e00000
end_define

begin_define
define|#
directive|define
name|DMFC_WR_CHAN_DEF_WM_SET_1C
value|0x001c0000
end_define

begin_define
define|#
directive|define
name|DMFC_WR_CHAN_DEF_WM_EN_1C
value|0x00020000
end_define

begin_define
define|#
directive|define
name|DMFC_WR_CHAN_DEF_WM_CLR_2
value|0x0000e000
end_define

begin_define
define|#
directive|define
name|DMFC_WR_CHAN_DEF_WM_SET_2
value|0x00001c00
end_define

begin_define
define|#
directive|define
name|DMFC_WR_CHAN_DEF_WM_EN_2
value|0x00000200
end_define

begin_define
define|#
directive|define
name|DMFC_WR_CHAN_DEF_WM_CLR_1
value|0x000000e0
end_define

begin_define
define|#
directive|define
name|DMFC_WR_CHAN_DEF_WM_SET_1
value|0x0000000c
end_define

begin_define
define|#
directive|define
name|DMFC_WR_CHAN_DEF_WM_EN_1
value|0x00000002
end_define

begin_define
define|#
directive|define
name|IPU_DMFC_DP_CHAN
value|0x0000000c
end_define

begin_define
define|#
directive|define
name|DMFC_DP_CHAN_BUSRT_SIZE_6F
value|0xc0000000
end_define

begin_define
define|#
directive|define
name|DMFC_DP_CHAN_FIFO_SIZE_6F
value|0x38000000
end_define

begin_define
define|#
directive|define
name|DMFC_DP_CHAN_ST_ADDR_6F
value|0x07000000
end_define

begin_define
define|#
directive|define
name|DMFC_DP_CHAN_BURST_SIZE_6B
value|0x00c00000
end_define

begin_define
define|#
directive|define
name|DMFC_DP_CHAN_FIFO_SIZE_6B
value|0x00380000
end_define

begin_define
define|#
directive|define
name|DMFC_DP_CHAN_ST_ADDR_6B
value|0x00070000
end_define

begin_define
define|#
directive|define
name|DMFC_DP_CHAN_BURST_SIZE_5F
value|0x0000c000
end_define

begin_define
define|#
directive|define
name|DMFC_DP_CHAN_FIFO_SIZE_5F
value|0x00003800
end_define

begin_define
define|#
directive|define
name|DMFC_DP_CHAN_ST_ADDR_5F
value|0x00000700
end_define

begin_define
define|#
directive|define
name|DMFC_DP_CHAN_BURST_SIZE_5B
value|0x000000c0
end_define

begin_define
define|#
directive|define
name|DMFC_DP_CHAN_FIFO_SIZE_5B
value|0x00000038
end_define

begin_define
define|#
directive|define
name|DMFC_DP_CHAN_ST_ADDR_5B
value|0x00000007
end_define

begin_define
define|#
directive|define
name|IPU_DMFC_DP_CHAN_DEF
value|0x00000010
end_define

begin_define
define|#
directive|define
name|DMFC_DP_CHAN_DEF_WM_CLR_6F
value|0xe0000000
end_define

begin_define
define|#
directive|define
name|DMFC_DP_CHAN_DEF_WM_SET_6F
value|0x1c000000
end_define

begin_define
define|#
directive|define
name|DMFC_DP_CHAN_DEF_WM_EN_6F
value|0x02000000
end_define

begin_define
define|#
directive|define
name|DMFC_DP_CHAN_DEF_WM_CLR_6B
value|0x00e00000
end_define

begin_define
define|#
directive|define
name|DMFC_DP_CHAN_DEF_WM_SET_6B
value|0x001c0000
end_define

begin_define
define|#
directive|define
name|DMFC_DP_CHAN_DEF_WM_EN_6B
value|0x00020000
end_define

begin_define
define|#
directive|define
name|DMFC_DP_CHAN_DEF_WM_CLR_5F
value|0x0000e000
end_define

begin_define
define|#
directive|define
name|DMFC_DP_CHAN_DEF_WM_SET_5F
value|0x00001c00
end_define

begin_define
define|#
directive|define
name|DMFC_DP_CHAN_DEF_WM_EN_5F
value|0x00000200
end_define

begin_define
define|#
directive|define
name|DMFC_DP_CHAN_DEF_WM_CLR_5B
value|0x000000e0
end_define

begin_define
define|#
directive|define
name|DMFC_DP_CHAN_DEF_WM_SET_5B
value|0x0000001c
end_define

begin_define
define|#
directive|define
name|DMFC_DP_CHAN_DEF_WM_EN_5B
value|0x00000002
end_define

begin_define
define|#
directive|define
name|IPU_DMFC_GENERAL1
value|0x00000014
end_define

begin_define
define|#
directive|define
name|DMFC_GENERAL1_WAIT4EOT_9
value|0x01000000
end_define

begin_define
define|#
directive|define
name|DMFC_GENERAL1_WAIT4EOT_6F
value|0x00800000
end_define

begin_define
define|#
directive|define
name|DMFC_GENERAL1_WAIT4EOT_6B
value|0x00400000
end_define

begin_define
define|#
directive|define
name|DMFC_GENERAL1_WAIT4EOT_5F
value|0x00200000
end_define

begin_define
define|#
directive|define
name|DMFC_GENERAL1_WAIT4EOT_5B
value|0x00100000
end_define

begin_define
define|#
directive|define
name|DMFC_GENERAL1_WAIT4EOT_4
value|0x00080000
end_define

begin_define
define|#
directive|define
name|DMFC_GENERAL1_WAIT4EOT_3
value|0x00040000
end_define

begin_define
define|#
directive|define
name|DMFC_GENERAL1_WAIT4EOT_2
value|0x00020000
end_define

begin_define
define|#
directive|define
name|DMFC_GENERAL1_WAIT4EOT_1
value|0x00010000
end_define

begin_define
define|#
directive|define
name|DMFC_GENERAL1_WM_CLR_9
value|0x0000e000
end_define

begin_define
define|#
directive|define
name|DMFC_GENERAL1_WM_SET_9
value|0x00001c00
end_define

begin_define
define|#
directive|define
name|DMFC_GENERAL1_BURST_SIZE_9
value|0x00000060
end_define

begin_define
define|#
directive|define
name|DMFC_GENERAL1_DCDP_SYNC_PR
value|0x00000003
end_define

begin_define
define|#
directive|define
name|DCDP_SYNC_PR_FORBIDDEN
value|0
end_define

begin_define
define|#
directive|define
name|DCDP_SYNC_PR_DC_DP
value|1
end_define

begin_define
define|#
directive|define
name|DCDP_SYNC_PR_DP_DC
value|2
end_define

begin_define
define|#
directive|define
name|DCDP_SYNC_PR_ROUNDROBIN
value|3
end_define

begin_define
define|#
directive|define
name|IPU_DMFC_GENERAL2
value|0x00000018
end_define

begin_define
define|#
directive|define
name|DMFC_GENERAL2_FRAME_HEIGHT_RD
value|0x1fff0000
end_define

begin_define
define|#
directive|define
name|DMFC_GENERAL2_FRAME_WIDTH_RD
value|0x00001fff
end_define

begin_define
define|#
directive|define
name|IPU_DMFC_IC_CTRL
value|0x0000001c
end_define

begin_define
define|#
directive|define
name|DMFC_IC_CTRL_IC_FRAME_HEIGHT_RD
value|0xfff80000
end_define

begin_define
define|#
directive|define
name|DMFC_IC_CTRL_IC_FRAME_WIDTH_RD
value|0x0007ffc0
end_define

begin_define
define|#
directive|define
name|DMFC_IC_CTRL_IC_PPW_C
value|0x00000030
end_define

begin_define
define|#
directive|define
name|DMFC_IC_CTRL_IC_IN_PORT
value|0x00000007
end_define

begin_define
define|#
directive|define
name|IC_IN_PORT_CH28
value|0
end_define

begin_define
define|#
directive|define
name|IC_IN_PORT_CH41
value|1
end_define

begin_define
define|#
directive|define
name|IC_IN_PORT_DISABLE
value|2
end_define

begin_define
define|#
directive|define
name|IC_IN_PORT_CH23
value|4
end_define

begin_define
define|#
directive|define
name|IC_IN_PORT_CH27
value|5
end_define

begin_define
define|#
directive|define
name|IC_IN_PORT_CH24
value|6
end_define

begin_define
define|#
directive|define
name|IC_IN_PORT_CH29
value|7
end_define

begin_define
define|#
directive|define
name|IPU_DMFC_WR_CHAN_ALT
value|0x00000020
end_define

begin_define
define|#
directive|define
name|IPU_DMFC_WR_CHAN_DEF_ALT
value|0x00000024
end_define

begin_define
define|#
directive|define
name|IPU_DMFC_DP_CHAN_ALT
value|0x00000028
end_define

begin_define
define|#
directive|define
name|IPU_DMFC_DP_CHAN_DEF_ALT
value|0x0000002c
end_define

begin_define
define|#
directive|define
name|DMFC_DP_CHAN_DEF_ALT_WM_CLR_6F_ALT
value|0xe0000000
end_define

begin_define
define|#
directive|define
name|DMFC_DP_CHAN_DEF_ALT_WM_SET_6F_ALT
value|0x1c000000
end_define

begin_define
define|#
directive|define
name|DMFC_DP_CHAN_DEF_ALT_WM_EN_6F_ALT
value|0x02000000
end_define

begin_define
define|#
directive|define
name|DMFC_DP_CHAN_DEF_ALT_WM_CLR_6B_ALT
value|0x00e00000
end_define

begin_define
define|#
directive|define
name|DMFC_DP_CHAN_DEF_ALT_WM_SET_6B_ALT
value|0x001c0000
end_define

begin_define
define|#
directive|define
name|DMFC_DP_CHAN_DEF_ALT_WM_EN_6B_ALT
value|0x00020000
end_define

begin_define
define|#
directive|define
name|DMFC_DP_CHAN_DEF_ALT_WM_CLR_5B_ALT
value|0x000000e0
end_define

begin_define
define|#
directive|define
name|DMFC_DP_CHAN_DEF_ALT_WM_SET_5B_ALT
value|0x0000001c
end_define

begin_define
define|#
directive|define
name|DMFC_DP_CHAN_DEF_ALT_WM_EN_5B_ALT
value|0x00000002
end_define

begin_define
define|#
directive|define
name|IPU_DMFC_GENERAL1_ALT
value|0x00000030
end_define

begin_define
define|#
directive|define
name|DMFC_GENERAL1_ALT_WAIT4EOT_6F_ALT
value|0x00800000
end_define

begin_define
define|#
directive|define
name|DMFC_GENERAL1_ALT_WAIT4EOT_6B_ALT
value|0x00400000
end_define

begin_define
define|#
directive|define
name|DMFC_GENERAL1_ALT_WAIT4EOT_5B_ALT
value|0x00100000
end_define

begin_define
define|#
directive|define
name|DMFC_GENERAL1_ALT_WAIT4EOT_2_ALT
value|0x00020000
end_define

begin_define
define|#
directive|define
name|IPU_DMFC_STAT
value|0x00000034
end_define

begin_define
define|#
directive|define
name|DMFC_STAT_IC_BUFFER_EMPTY
value|0x02000000
end_define

begin_define
define|#
directive|define
name|DMFC_STAT_IC_BUFFER_FULL
value|0x01000000
end_define

begin_define
define|#
directive|define
name|DMFC_STAT_FIFO_EMPTY
parameter_list|(
name|n
parameter_list|)
value|__BIT(12 + (n))
end_define

begin_define
define|#
directive|define
name|DMFC_STAT_FIFO_FULL
parameter_list|(
name|n
parameter_list|)
value|__BIT((n))
end_define

begin_comment
comment|/*  * VCI  * Video De Interkacing Module  */
end_comment

begin_define
define|#
directive|define
name|IPU_VDI_FSIZE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|IPU_VDI_C
value|0x00000004
end_define

begin_comment
comment|/*  * DP  * Display Processor  */
end_comment

begin_define
define|#
directive|define
name|IPU_DP_COM_CONF_SYNC
value|0x00000000
end_define

begin_define
define|#
directive|define
name|DP_FG_EN_SYNC
value|0x00000001
end_define

begin_define
define|#
directive|define
name|DP_DP_GWAM_SYNC
value|0x00000004
end_define

begin_define
define|#
directive|define
name|IPU_DP_GRAPH_WIND_CTRL_SYNC
value|0x00000004
end_define

begin_define
define|#
directive|define
name|IPU_DP_FG_POS_SYNC
value|0x00000008
end_define

begin_define
define|#
directive|define
name|IPU_DP_CUR_POS_SYNC
value|0x0000000c
end_define

begin_define
define|#
directive|define
name|IPU_DP_CUR_MAP_SYNC
value|0x00000010
end_define

begin_define
define|#
directive|define
name|IPU_DP_CSC_SYNC_0
value|0x00000054
end_define

begin_define
define|#
directive|define
name|IPU_DP_CSC_SYNC_1
value|0x00000058
end_define

begin_define
define|#
directive|define
name|IPU_DP_CUR_POS_ALT
value|0x0000005c
end_define

begin_define
define|#
directive|define
name|IPU_DP_COM_CONF_ASYNC0
value|0x00000060
end_define

begin_define
define|#
directive|define
name|IPU_DP_GRAPH_WIND_CTRL_ASYNC0
value|0x00000064
end_define

begin_define
define|#
directive|define
name|IPU_DP_FG_POS_ASYNC0
value|0x00000068
end_define

begin_define
define|#
directive|define
name|IPU_DP_CUR_POS_ASYNC0
value|0x0000006c
end_define

begin_define
define|#
directive|define
name|IPU_DP_CUR_MAP_ASYNC0
value|0x00000070
end_define

begin_define
define|#
directive|define
name|IPU_DP_CSC_ASYNC0_0
value|0x000000b4
end_define

begin_define
define|#
directive|define
name|IPU_DP_CSC_ASYNC0_1
value|0x000000b8
end_define

begin_define
define|#
directive|define
name|IPU_DP_COM_CONF_ASYNC1
value|0x000000bc
end_define

begin_define
define|#
directive|define
name|IPU_DP_GRAPH_WIND_CTRL_ASYNC1
value|0x000000c0
end_define

begin_define
define|#
directive|define
name|IPU_DP_FG_POS_ASYNC1
value|0x000000c4
end_define

begin_define
define|#
directive|define
name|IPU_DP_CUR_POS_ASYNC1
value|0x000000c8
end_define

begin_define
define|#
directive|define
name|IPU_DP_CUR_MAP_ASYNC1
value|0x000000cc
end_define

begin_define
define|#
directive|define
name|IPU_DP_CSC_ASYNC1_0
value|0x00000110
end_define

begin_define
define|#
directive|define
name|IPU_DP_CSC_ASYNC1_1
value|0x00000114
end_define

begin_comment
comment|/* IDMA parameter */
end_comment

begin_comment
comment|/* 	 * non-Interleaved parameter 	 * 	 * param 0: XV W0[ 9: 0] 	 *          YV W0[18:10] 	 *          XB W0[31:19] 	 * param 1: YB W0[43:32] 	 *          NSB W0[44] 	 *          CF W0[45] 	 *          UBO W0[61:46] 	 * param 2: UBO W0[67:62] 	 *          VBO W0[89:68] 	 *          IOX W0[93:90] 	 *          RDRW W0[94] 	 *          Reserved W0[95] 	 * param 3: Reserved W0[112:96] 	 *          S0 W0[113] 	 *          BNDM W0[116:114] 	 *          BM W0[118:117] 	 *          ROT W0[119] 	 *          HF W0[120] 	 *          VF W0[121] 	 *          THF W0[122] 	 *          CAP W0[123] 	 *          CAE W0[124] 	 *          FW W0[127:125] 	 * param 4: FW W0[137:128] 	 *          FH W0[149:138] 	 * param 5: EBA0 W1[28:0] 	 *          EBA1 W1[31:29] 	 * param 6: EBA1 W1[57:32] 	 *          ILO W1[63:58] 	 * param 7: ILO W1[77:64] 	 *          NPB W1[84:78] 	 *          PFS W1[88:85] 	 *          ALU W1[89] 	 *          ALBM W1[92:90] 	 *          ID W1[94:93] 	 *          TH W1[95] 	 * param 8: TH W1[101:96] 	 *          SLY W1[115:102] 	 *          WID3 W1[127:125] 	 * param 9: SLUV W1[141:128] 	 *          CRE W1[149] 	 * 	 * Interleaved parameter 	 * 	 * param 0: XV W0[ 9: 0] 	 *          YV W0[18:10] 	 *          XB W0[31:19] 	 * param 1: YB W0[43:32] 	 *          NSB W0[44] 	 *          CF W0[45] 	 *          SX W0[57:46] 	 *          SY W0[61:58] 	 * param 2: SY W0[68:62] 	 *          NS W0[78:69] 	 *          SDX W0[85:79] 	 *          SM W0[95:86] 	 * param 3: SCC W0[96] 	 *          SCE W0[97] 	 *          SDY W0[104:98] 	 *          SDRX W0[105] 	 *          SDRY W0[106] 	 *          BPP W0[109:107] 	 *	    DEC_SEL W0[111:110] 	 *          DIM W0[112] 	 *          SO W0[113] 	 *          BNDM W0[116:114] 	 *          BM W0[118:117] 	 *          ROT W0[119] 	 *          HF W0[120] 	 *          VF W0[121] 	 *          THF W0[122] 	 *          CAP W0[123] 	 *          CAE W0[124] 	 *          FW W0[127:125] 	 * param 4: FW W0[137:128] 	 *          FH W0[149:138] 	 * param 5: EBA0 W1[28:0] 	 *          EBA1 W1[31:29] 	 * param 6: EBA1 W1[57:32] 	 *          ILO W1[63:58] 	 * param 7: ILO W1[77:64] 	 *          NPB W1[84:78] 	 *          PFS W1[88:85] 	 *          ALU W1[89] 	 *          ALBM W1[92:90] 	 *          ID W1[94:93] 	 *          TH W1[95] 	 * param 8: TH W1[101:96] 	 *          SL W1[115:102] 	 *          WID0 W1[118:116] 	 *          WID1 W1[121:119] 	 *          WID2 W1[124:122] 	 *          WID3 W1[127:125] 	 * param 9: OFS0 W1[132:128] 	 *          OFS1 W1[137:133] 	 *          OFS2 W1[142:138] 	 *          OFS3 W1[147:143] 	 *          SXYS W1[148] 	 *          CRE W1[149] 	 *          DEC_SEL2 W1[150] 	 */
end_comment

begin_define
define|#
directive|define
name|__IDMA_PARAM
parameter_list|(
name|word
parameter_list|,
name|shift
parameter_list|,
name|size
parameter_list|)
define|\
value|((((word)& 0xff)<< 16) | (((shift)& 0xff)<< 8) | ((size)& 0xff))
end_define

begin_comment
comment|/* non-Interleaved parameter */
end_comment

begin_comment
comment|/* W0 */
end_comment

begin_define
define|#
directive|define
name|IDMAC_Ch_PARAM_XV
value|__IDMA_PARAM(0,  0, 10)
end_define

begin_define
define|#
directive|define
name|IDMAC_Ch_PARAM_YV
value|__IDMA_PARAM(0, 10,  9)
end_define

begin_define
define|#
directive|define
name|IDMAC_Ch_PARAM_XB
value|__IDMA_PARAM(0, 19, 13)
end_define

begin_define
define|#
directive|define
name|IDMAC_Ch_PARAM_YB
value|__IDMA_PARAM(0, 32, 12)
end_define

begin_define
define|#
directive|define
name|IDMAC_Ch_PARAM_NSB
value|__IDMA_PARAM(0, 44,  1)
end_define

begin_define
define|#
directive|define
name|IDMAC_Ch_PARAM_CF
value|__IDMA_PARAM(0, 45,  1)
end_define

begin_define
define|#
directive|define
name|IDMAC_Ch_PARAM_UBO
value|__IDMA_PARAM(0, 46, 22)
end_define

begin_define
define|#
directive|define
name|IDMAC_Ch_PARAM_VBO
value|__IDMA_PARAM(0, 68, 22)
end_define

begin_define
define|#
directive|define
name|IDMAC_Ch_PARAM_IOX
value|__IDMA_PARAM(0, 90,  4)
end_define

begin_define
define|#
directive|define
name|IDMAC_Ch_PARAM_RDRW
value|__IDMA_PARAM(0, 94,  1)
end_define

begin_define
define|#
directive|define
name|IDMAC_Ch_PARAM_S0
value|__IDMA_PARAM(0,113,  1)
end_define

begin_define
define|#
directive|define
name|IDMAC_Ch_PARAM_BNDM
value|__IDMA_PARAM(0,114,  3)
end_define

begin_define
define|#
directive|define
name|IDMAC_Ch_PARAM_BM
value|__IDMA_PARAM(0,117,  2)
end_define

begin_define
define|#
directive|define
name|IDMAC_Ch_PARAM_ROT
value|__IDMA_PARAM(0,119,  1)
end_define

begin_define
define|#
directive|define
name|IDMAC_Ch_PARAM_HF
value|__IDMA_PARAM(0,120,  1)
end_define

begin_define
define|#
directive|define
name|IDMAC_Ch_PARAM_VF
value|__IDMA_PARAM(0,121,  1)
end_define

begin_define
define|#
directive|define
name|IDMAC_Ch_PARAM_THF
value|__IDMA_PARAM(0,122,  1)
end_define

begin_define
define|#
directive|define
name|IDMAC_Ch_PARAM_CAP
value|__IDMA_PARAM(0,123,  1)
end_define

begin_define
define|#
directive|define
name|IDMAC_Ch_PARAM_CAE
value|__IDMA_PARAM(0,124,  1)
end_define

begin_define
define|#
directive|define
name|IDMAC_Ch_PARAM_FW
value|__IDMA_PARAM(0,125, 13)
end_define

begin_define
define|#
directive|define
name|IDMAC_Ch_PARAM_FH
value|__IDMA_PARAM(0,138, 12)
end_define

begin_comment
comment|/* W1 */
end_comment

begin_define
define|#
directive|define
name|IDMAC_Ch_PARAM_EBA0
value|__IDMA_PARAM(1,  0, 29)
end_define

begin_define
define|#
directive|define
name|IDMAC_Ch_PARAM_EBA1
value|__IDMA_PARAM(1, 29, 29)
end_define

begin_define
define|#
directive|define
name|IDMAC_Ch_PARAM_ILO
value|__IDMA_PARAM(1, 58, 20)
end_define

begin_define
define|#
directive|define
name|IDMAC_Ch_PARAM_NPB
value|__IDMA_PARAM(1, 78,  7)
end_define

begin_define
define|#
directive|define
name|IDMAC_Ch_PARAM_PFS
value|__IDMA_PARAM(1, 85,  4)
end_define

begin_define
define|#
directive|define
name|IDMAC_Ch_PARAM_ALU
value|__IDMA_PARAM(1, 89,  1)
end_define

begin_define
define|#
directive|define
name|IDMAC_Ch_PARAM_ALBM
value|__IDMA_PARAM(1, 90,  3)
end_define

begin_define
define|#
directive|define
name|IDMAC_Ch_PARAM_ID
value|__IDMA_PARAM(1, 93,  2)
end_define

begin_define
define|#
directive|define
name|IDMAC_Ch_PARAM_TH
value|__IDMA_PARAM(1, 95,  7)
end_define

begin_define
define|#
directive|define
name|IDMAC_Ch_PARAM_SL
value|__IDMA_PARAM(1,102, 14)
end_define

begin_define
define|#
directive|define
name|IDMAC_Ch_PARAM_WID3
value|__IDMA_PARAM(1,125,  3)
end_define

begin_define
define|#
directive|define
name|IDMAC_Ch_PARAM_SLUV
value|__IDMA_PARAM(1,128, 14)
end_define

begin_define
define|#
directive|define
name|IDMAC_Ch_PARAM_CRE
value|__IDMA_PARAM(1,149,  1)
end_define

begin_comment
comment|/* Interleaved parameter */
end_comment

begin_comment
comment|/* W0 */
end_comment

begin_define
define|#
directive|define
name|IDMAC_Ch_PARAM_XV
value|__IDMA_PARAM(0,  0, 10)
end_define

begin_define
define|#
directive|define
name|IDMAC_Ch_PARAM_YV
value|__IDMA_PARAM(0, 10,  9)
end_define

begin_define
define|#
directive|define
name|IDMAC_Ch_PARAM_XB
value|__IDMA_PARAM(0, 19, 13)
end_define

begin_define
define|#
directive|define
name|IDMAC_Ch_PARAM_YB
value|__IDMA_PARAM(0, 32, 12)
end_define

begin_define
define|#
directive|define
name|IDMAC_Ch_PARAM_NSB
value|__IDMA_PARAM(0, 44,  1)
end_define

begin_define
define|#
directive|define
name|IDMAC_Ch_PARAM_CF
value|__IDMA_PARAM(0, 45,  1)
end_define

begin_define
define|#
directive|define
name|IDMAC_Ch_PARAM_SX
value|__IDMA_PARAM(0, 46, 12)
end_define

begin_define
define|#
directive|define
name|IDMAC_Ch_PARAM_SY
value|__IDMA_PARAM(0, 58, 11)
end_define

begin_define
define|#
directive|define
name|IDMAC_Ch_PARAM_NS
value|__IDMA_PARAM(0, 69, 10)
end_define

begin_define
define|#
directive|define
name|IDMAC_Ch_PARAM_SDX
value|__IDMA_PARAM(0, 79,  7)
end_define

begin_define
define|#
directive|define
name|IDMAC_Ch_PARAM_SM
value|__IDMA_PARAM(0, 86, 10)
end_define

begin_define
define|#
directive|define
name|IDMAC_Ch_PARAM_SCC
value|__IDMA_PARAM(0, 96,  1)
end_define

begin_define
define|#
directive|define
name|IDMAC_Ch_PARAM_SCE
value|__IDMA_PARAM(0, 97,  1)
end_define

begin_define
define|#
directive|define
name|IDMAC_Ch_PARAM_SDY
value|__IDMA_PARAM(0, 98,  7)
end_define

begin_define
define|#
directive|define
name|IDMAC_Ch_PARAM_SDRX
value|__IDMA_PARAM(0,105,  1)
end_define

begin_define
define|#
directive|define
name|IDMAC_Ch_PARAM_SDRY
value|__IDMA_PARAM(0,106,  1)
end_define

begin_define
define|#
directive|define
name|IDMAC_Ch_PARAM_BPP
value|__IDMA_PARAM(0,107,  3)
end_define

begin_define
define|#
directive|define
name|IDMAC_Ch_PARAM_DEC_SEL
value|__IDMA_PARAM(0,110,  2)
end_define

begin_define
define|#
directive|define
name|IDMAC_Ch_PARAM_DIM
value|__IDMA_PARAM(0,112,  1)
end_define

begin_define
define|#
directive|define
name|IDMAC_Ch_PARAM_SO
value|__IDMA_PARAM(0,113,  1)
end_define

begin_define
define|#
directive|define
name|IDMAC_Ch_PARAM_BNDM
value|__IDMA_PARAM(0,114,  3)
end_define

begin_define
define|#
directive|define
name|IDMAC_Ch_PARAM_BM
value|__IDMA_PARAM(0,117,  2)
end_define

begin_define
define|#
directive|define
name|IDMAC_Ch_PARAM_ROT
value|__IDMA_PARAM(0,119,  1)
end_define

begin_define
define|#
directive|define
name|IDMAC_Ch_PARAM_HF
value|__IDMA_PARAM(0,120,  1)
end_define

begin_define
define|#
directive|define
name|IDMAC_Ch_PARAM_VF
value|__IDMA_PARAM(0,121,  1)
end_define

begin_define
define|#
directive|define
name|IDMAC_Ch_PARAM_THF
value|__IDMA_PARAM(0,122,  1)
end_define

begin_define
define|#
directive|define
name|IDMAC_Ch_PARAM_CAP
value|__IDMA_PARAM(0,123,  1)
end_define

begin_define
define|#
directive|define
name|IDMAC_Ch_PARAM_CAE
value|__IDMA_PARAM(0,124,  1)
end_define

begin_define
define|#
directive|define
name|IDMAC_Ch_PARAM_FW
value|__IDMA_PARAM(0,125, 13)
end_define

begin_define
define|#
directive|define
name|IDMAC_Ch_PARAM_FH
value|__IDMA_PARAM(0,138, 12)
end_define

begin_comment
comment|/* W1 */
end_comment

begin_define
define|#
directive|define
name|IDMAC_Ch_PARAM_EBA0
value|__IDMA_PARAM(1,  0, 29)
end_define

begin_define
define|#
directive|define
name|IDMAC_Ch_PARAM_EBA1
value|__IDMA_PARAM(1, 29, 29)
end_define

begin_define
define|#
directive|define
name|IDMAC_Ch_PARAM_ILO
value|__IDMA_PARAM(1, 58, 20)
end_define

begin_define
define|#
directive|define
name|IDMAC_Ch_PARAM_NPB
value|__IDMA_PARAM(1, 78,  7)
end_define

begin_define
define|#
directive|define
name|IDMAC_Ch_PARAM_PFS
value|__IDMA_PARAM(1, 85,  4)
end_define

begin_define
define|#
directive|define
name|IDMAC_Ch_PARAM_ALU
value|__IDMA_PARAM(1, 89,  1)
end_define

begin_define
define|#
directive|define
name|IDMAC_Ch_PARAM_ALBM
value|__IDMA_PARAM(1, 90,  3)
end_define

begin_define
define|#
directive|define
name|IDMAC_Ch_PARAM_ID
value|__IDMA_PARAM(1, 93,  2)
end_define

begin_define
define|#
directive|define
name|IDMAC_Ch_PARAM_TH
value|__IDMA_PARAM(1, 95,  7)
end_define

begin_define
define|#
directive|define
name|IDMAC_Ch_PARAM_SL
value|__IDMA_PARAM(1,102, 14)
end_define

begin_define
define|#
directive|define
name|IDMAC_Ch_PARAM_WID0
value|__IDMA_PARAM(1,116,  3)
end_define

begin_define
define|#
directive|define
name|IDMAC_Ch_PARAM_WID1
value|__IDMA_PARAM(1,119,  3)
end_define

begin_define
define|#
directive|define
name|IDMAC_Ch_PARAM_WID2
value|__IDMA_PARAM(1,122,  3)
end_define

begin_define
define|#
directive|define
name|IDMAC_Ch_PARAM_WID3
value|__IDMA_PARAM(1,125,  3)
end_define

begin_define
define|#
directive|define
name|IDMAC_Ch_PARAM_OFS0
value|__IDMA_PARAM(1,128,  5)
end_define

begin_define
define|#
directive|define
name|IDMAC_Ch_PARAM_OFS1
value|__IDMA_PARAM(1,133,  5)
end_define

begin_define
define|#
directive|define
name|IDMAC_Ch_PARAM_OFS2
value|__IDMA_PARAM(1,138,  5)
end_define

begin_define
define|#
directive|define
name|IDMAC_Ch_PARAM_OFS3
value|__IDMA_PARAM(1,143,  5)
end_define

begin_define
define|#
directive|define
name|IDMAC_Ch_PARAM_SXYS
value|__IDMA_PARAM(1,148,  1)
end_define

begin_define
define|#
directive|define
name|IDMAC_Ch_PARAM_CRE
value|__IDMA_PARAM(1,149,  1)
end_define

begin_define
define|#
directive|define
name|IDMAC_Ch_PARAM_DEC_SEL2
value|__IDMA_PARAM(1,150,  1)
end_define

begin_comment
comment|/* XXX Temp */
end_comment

begin_define
define|#
directive|define
name|GPUMEM_BASE
value|0x20000000
end_define

begin_define
define|#
directive|define
name|GPUMEM_SIZE
value|0x20000
end_define

begin_define
define|#
directive|define
name|GPU_BASE
value|0x30000000
end_define

begin_define
define|#
directive|define
name|GPU_SIZE
value|0x10000000
end_define

begin_comment
comment|/*   * Image Processing Unit   *  * All addresses are relative to the base SoC address.   */
end_comment

begin_define
define|#
directive|define
name|IPU_CM_BASE
parameter_list|(
name|_base
parameter_list|)
value|((_base) + 0x1e000000)
end_define

begin_define
define|#
directive|define
name|IPU_CM_SIZE
value|0x8000
end_define

begin_define
define|#
directive|define
name|IPU_IDMAC_BASE
parameter_list|(
name|_base
parameter_list|)
value|((_base) + 0x1e008000)
end_define

begin_define
define|#
directive|define
name|IPU_IDMAC_SIZE
value|0x8000
end_define

begin_define
define|#
directive|define
name|IPU_DP_BASE
parameter_list|(
name|_base
parameter_list|)
value|((_base) + 0x1e018000)
end_define

begin_define
define|#
directive|define
name|IPU_DP_SIZE
value|0x8000
end_define

begin_define
define|#
directive|define
name|IPU_IC_BASE
parameter_list|(
name|_base
parameter_list|)
value|((_base) + 0x1e020000)
end_define

begin_define
define|#
directive|define
name|IPU_IC_SIZE
value|0x8000
end_define

begin_define
define|#
directive|define
name|IPU_IRT_BASE
parameter_list|(
name|_base
parameter_list|)
value|((_base) + 0x1e028000)
end_define

begin_define
define|#
directive|define
name|IPU_IRT_SIZE
value|0x8000
end_define

begin_define
define|#
directive|define
name|IPU_CSI0_BASE
parameter_list|(
name|_base
parameter_list|)
value|((_base) + 0x1e030000)
end_define

begin_define
define|#
directive|define
name|IPU_CSI0_SIZE
value|0x8000
end_define

begin_define
define|#
directive|define
name|IPU_CSI1_BASE
parameter_list|(
name|_base
parameter_list|)
value|((_base) + 0x1e038000)
end_define

begin_define
define|#
directive|define
name|IPU_CSI1_SIZE
value|0x8000
end_define

begin_define
define|#
directive|define
name|IPU_DI0_BASE
parameter_list|(
name|_base
parameter_list|)
value|((_base) + 0x1e040000)
end_define

begin_define
define|#
directive|define
name|IPU_DI0_SIZE
value|0x8000
end_define

begin_define
define|#
directive|define
name|IPU_DI1_BASE
parameter_list|(
name|_base
parameter_list|)
value|((_base) + 0x1e048000)
end_define

begin_define
define|#
directive|define
name|IPU_DI1_SIZE
value|0x8000
end_define

begin_define
define|#
directive|define
name|IPU_SMFC_BASE
parameter_list|(
name|_base
parameter_list|)
value|((_base) + 0x1e050000)
end_define

begin_define
define|#
directive|define
name|IPU_SMFC_SIZE
value|0x8000
end_define

begin_define
define|#
directive|define
name|IPU_DC_BASE
parameter_list|(
name|_base
parameter_list|)
value|((_base) + 0x1e058000)
end_define

begin_define
define|#
directive|define
name|IPU_DC_SIZE
value|0x8000
end_define

begin_define
define|#
directive|define
name|IPU_DMFC_BASE
parameter_list|(
name|_base
parameter_list|)
value|((_base) + 0x1e060000)
end_define

begin_define
define|#
directive|define
name|IPU_DMFC_SIZE
value|0x8000
end_define

begin_define
define|#
directive|define
name|IPU_VDI_BASE
parameter_list|(
name|_base
parameter_list|)
value|((_base) + 0x1e068000)
end_define

begin_define
define|#
directive|define
name|IPU_VDI_SIZE
value|0x8000
end_define

begin_define
define|#
directive|define
name|IPU_CPMEM_BASE
parameter_list|(
name|_base
parameter_list|)
value|((_base) + 0x1f000000)
end_define

begin_define
define|#
directive|define
name|IPU_CPMEM_SIZE
value|0x20000
end_define

begin_define
define|#
directive|define
name|IPU_LUT_BASE
parameter_list|(
name|_base
parameter_list|)
value|((_base) + 0x1f020000)
end_define

begin_define
define|#
directive|define
name|IPU_LUT_SIZE
value|0x20000
end_define

begin_define
define|#
directive|define
name|IPU_SRM_BASE
parameter_list|(
name|_base
parameter_list|)
value|((_base) + 0x1f040000)
end_define

begin_define
define|#
directive|define
name|IPU_SRM_SIZE
value|0x20000
end_define

begin_define
define|#
directive|define
name|IPU_TPM_BASE
parameter_list|(
name|_base
parameter_list|)
value|((_base) + 0x1f060000)
end_define

begin_define
define|#
directive|define
name|IPU_TPM_SIZE
value|0x20000
end_define

begin_define
define|#
directive|define
name|IPU_DCTMPL_BASE
parameter_list|(
name|_base
parameter_list|)
value|((_base) + 0x1f080000)
end_define

begin_define
define|#
directive|define
name|IPU_DCTMPL_SIZE
value|0x20000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ARM_IMX_IMX51_IPUV3REG_H */
end_comment

end_unit

