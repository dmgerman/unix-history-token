begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2009 Marius Strobl<marius@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SPARC64_PCI_FIREREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_SPARC64_PCI_FIREREG_H_
end_define

begin_define
define|#
directive|define
name|FIRE_NINTR
value|3
end_define

begin_comment
comment|/* 2 OFW + 1 MSIq */
end_comment

begin_define
define|#
directive|define
name|FIRE_NRANGE
value|4
end_define

begin_define
define|#
directive|define
name|FIRE_NREG
value|2
end_define

begin_define
define|#
directive|define
name|FIRE_PCI
value|0
end_define

begin_define
define|#
directive|define
name|FIRE_CTRL
value|1
end_define

begin_comment
comment|/* PCI configuration and status registers */
end_comment

begin_define
define|#
directive|define
name|FO_PCI_INT_MAP_BASE
value|0x01000
end_define

begin_define
define|#
directive|define
name|FO_PCI_INT_CLR_BASE
value|0x01400
end_define

begin_define
define|#
directive|define
name|FO_PCI_EQ_BASE_ADDR
value|0x10000
end_define

begin_define
define|#
directive|define
name|FO_PCI_EQ_CTRL_SET_BASE
value|0x11000
end_define

begin_define
define|#
directive|define
name|FO_PCI_EQ_CTRL_CLR_BASE
value|0x11200
end_define

begin_define
define|#
directive|define
name|FO_PCI_EQ_TL_BASE
value|0x11600
end_define

begin_define
define|#
directive|define
name|FO_PCI_EQ_HD_BASE
value|0x11800
end_define

begin_define
define|#
directive|define
name|FO_PCI_MSI_MAP_BASE
value|0x20000
end_define

begin_define
define|#
directive|define
name|FO_PCI_MSI_CLR_BASE
value|0x28000
end_define

begin_define
define|#
directive|define
name|FO_PCI_ERR_COR
value|0x30000
end_define

begin_define
define|#
directive|define
name|FO_PCI_ERR_NONFATAL
value|0x30008
end_define

begin_define
define|#
directive|define
name|FO_PCI_ERR_FATAL
value|0x30010
end_define

begin_define
define|#
directive|define
name|FO_PCI_PM_PME
value|0x30018
end_define

begin_define
define|#
directive|define
name|FO_PCI_PME_TO_ACK
value|0x30020
end_define

begin_define
define|#
directive|define
name|FO_PCI_IMU_INT_EN
value|0x31008
end_define

begin_define
define|#
directive|define
name|FO_PCI_IMU_INT_STAT
value|0x31010
end_define

begin_define
define|#
directive|define
name|FO_PCI_IMU_ERR_STAT_CLR
value|0x31018
end_define

begin_define
define|#
directive|define
name|FO_PCI_IMU_RDS_ERR_LOG
value|0x31028
end_define

begin_define
define|#
directive|define
name|FO_PCI_IMU_SCS_ERR_LOG
value|0x31030
end_define

begin_define
define|#
directive|define
name|FO_PCI_IMU_EQS_ERR_LOG
value|0x31038
end_define

begin_define
define|#
directive|define
name|FO_PCI_DMC_CORE_BLOCK_INT_EN
value|0x31800
end_define

begin_define
define|#
directive|define
name|FO_PCI_DMC_CORE_BLOCK_ERR_STAT
value|0x31808
end_define

begin_define
define|#
directive|define
name|FO_PCI_MULTI_CORE_ERR_STAT
value|0x31810
end_define

begin_define
define|#
directive|define
name|FO_PCI_MSI_32_BIT_ADDR
value|0x34000
end_define

begin_define
define|#
directive|define
name|FO_PCI_MSI_64_BIT_ADDR
value|0x34008
end_define

begin_define
define|#
directive|define
name|FO_PCI_MMU
value|0x40000
end_define

begin_define
define|#
directive|define
name|FO_PCI_MMU_INT_EN
value|0x41008
end_define

begin_define
define|#
directive|define
name|FO_PCI_MMU_INT_STAT
value|0x41010
end_define

begin_define
define|#
directive|define
name|FO_PCI_MMU_ERR_STAT_CLR
value|0x41018
end_define

begin_define
define|#
directive|define
name|FO_PCI_MMU_TRANS_FAULT_ADDR
value|0x41028
end_define

begin_define
define|#
directive|define
name|FO_PCI_MMU_TRANS_FAULT_STAT
value|0x41030
end_define

begin_define
define|#
directive|define
name|FO_PCI_ILU_INT_EN
value|0x51008
end_define

begin_define
define|#
directive|define
name|FO_PCI_ILU_INT_STAT
value|0x51010
end_define

begin_define
define|#
directive|define
name|FO_PCI_ILU_ERR_STAT_CLR
value|0x51018
end_define

begin_define
define|#
directive|define
name|FO_PCI_DMC_DBG_SEL_PORTA
value|0x53000
end_define

begin_define
define|#
directive|define
name|FO_PCI_DMC_DBG_SEL_PORTB
value|0x53008
end_define

begin_define
define|#
directive|define
name|FO_PCI_PEC_CORE_BLOCK_INT_EN
value|0x51800
end_define

begin_define
define|#
directive|define
name|FO_PCI_PEC_CORE_BLOCK_INT_STAT
value|0x51808
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_CTRL
value|0x80000
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_OEVENT_INT_EN
value|0x81008
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_OEVENT_INT_STAT
value|0x81010
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_OEVENT_STAT_CLR
value|0x81018
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_RX_OEVENT_HDR1_LOG
value|0x81028
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_RX_OEVENT_HDR2_LOG
value|0x81030
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_TX_OEVENT_HDR1_LOG
value|0x81038
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_TX_OEVENT_HDR2_LOG
value|0x81040
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_DEV_CTRL
value|0x90008
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_LNK_CTRL
value|0x90020
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_LNK_STAT
value|0x90028
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_UERR_INT_EN
value|0x91008
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_UERR_INT_STAT
value|0x91010
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_UERR_STAT_CLR
value|0x91018
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_RX_UERR_HDR1_LOG
value|0x91028
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_RX_UERR_HDR2_LOG
value|0x91030
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_TX_UERR_HDR1_LOG
value|0x91038
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_TX_UERR_HDR2_LOG
value|0x91040
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_CERR_INT_EN
value|0xa1008
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_CERR_INT_STAT
value|0xa1010
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_CERR_STAT_CLR
value|0xa1018
end_define

begin_define
define|#
directive|define
name|FO_PCI_LPU_RST
value|0xe2008
end_define

begin_define
define|#
directive|define
name|FO_PCI_LPU_INT_STAT
value|0xe2040
end_define

begin_define
define|#
directive|define
name|FO_PCI_LPU_INT_MASK
value|0xe0248
end_define

begin_define
define|#
directive|define
name|FO_PCI_LPU_LNK_LYR_CFG
value|0xe2200
end_define

begin_define
define|#
directive|define
name|FO_PCI_LPU_LNK_LYR_INT_STAT
value|0xe2210
end_define

begin_define
define|#
directive|define
name|FO_PCI_LPU_FLW_CTRL_UPDT_CTRL
value|0xe2240
end_define

begin_define
define|#
directive|define
name|FO_PCI_LPU_TXLNK_FREQ_LAT_TMR_THRS
value|0xe2400
end_define

begin_define
define|#
directive|define
name|FO_PCI_LPU_TXLNK_RPLY_TMR_THRS
value|0xe2410
end_define

begin_define
define|#
directive|define
name|FO_PCI_LPU_TXLNK_RTR_FIFO_PTR
value|0xe2430
end_define

begin_define
define|#
directive|define
name|FO_PCI_LPU_PHY_LYR_INT_STAT
value|0xe2610
end_define

begin_define
define|#
directive|define
name|FO_PCI_LPU_LTSSM_CFG2
value|0xe2788
end_define

begin_define
define|#
directive|define
name|FO_PCI_LPU_LTSSM_CFG3
value|0xe2790
end_define

begin_define
define|#
directive|define
name|FO_PCI_LPU_LTSSM_CFG4
value|0xe2798
end_define

begin_define
define|#
directive|define
name|FO_PCI_LPU_LTSSM_CFG5
value|0xe27a0
end_define

begin_comment
comment|/* PCI interrupt mapping registers */
end_comment

begin_define
define|#
directive|define
name|FO_PCI_IMAP_MDO_MODE
value|0x8000000000000000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_IMAP_V
value|0x0000000080000000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_PCI_IMAP_T_JPID_MASK
value|0x000000007c000000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_PCI_IMAP_T_JPID_SHFT
value|26
end_define

begin_define
define|#
directive|define
name|OBERON_PCI_IMAP_T_DESTID_MASK
value|0x000000007fe00000ULL
end_define

begin_define
define|#
directive|define
name|OBERON_PCI_IMAP_T_DESTID_SHFT
value|21
end_define

begin_define
define|#
directive|define
name|FO_PCI_IMAP_INT_CTRL_NUM_MASK
value|0x00000000000003c0ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_IMAP_INT_CTRL_NUM_SHFT
value|6
end_define

begin_comment
comment|/* PCI interrupt clear registers - use INTCLR_* from<machine/bus_common.h> */
end_comment

begin_comment
comment|/* PCI event queue base address register */
end_comment

begin_define
define|#
directive|define
name|FO_PCI_EQ_BASE_ADDR_BYPASS
value|0xfffc000000000000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_EQ_BASE_ADDR_MASK
value|0xfffffffffff80000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_EQ_BASE_ADDR_SHFT
value|19
end_define

begin_comment
comment|/* PCI event queue control set registers */
end_comment

begin_define
define|#
directive|define
name|FO_PCI_EQ_CTRL_SET_ENOVERR
value|0x0200000000000000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_EQ_CTRL_SET_EN
value|0x0000100000000000ULL
end_define

begin_comment
comment|/* PCI event queue control clear registers */
end_comment

begin_define
define|#
directive|define
name|FO_PCI_EQ_CTRL_CLR_COVERR
value|0x0200000000000000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_EQ_CTRL_CLR_E2I
value|0x0000800000000000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_EQ_CTRL_CLR_DIS
value|0x0000100000000000ULL
end_define

begin_comment
comment|/* PCI event queue tail registers */
end_comment

begin_define
define|#
directive|define
name|FO_PCI_EQ_TL_OVERR
value|0x0200000000000000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_EQ_TL_MASK
value|0x000000000000007fULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_EQ_TL_SHFT
value|0
end_define

begin_comment
comment|/* PCI event queue head registers */
end_comment

begin_define
define|#
directive|define
name|FO_PCI_EQ_HD_MASK
value|0x000000000000007fULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_EQ_HD_SHFT
value|0
end_define

begin_comment
comment|/* PCI MSI mapping registers */
end_comment

begin_define
define|#
directive|define
name|FO_PCI_MSI_MAP_V
value|0x8000000000000000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_MSI_MAP_EQWR_N
value|0x4000000000000000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_MSI_MAP_EQNUM_MASK
value|0x000000000000003fULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_MSI_MAP_EQNUM_SHFT
value|0
end_define

begin_comment
comment|/* PCI MSI clear registers */
end_comment

begin_define
define|#
directive|define
name|FO_PCI_MSI_CLR_EQWR_N
value|0x4000000000000000ULL
end_define

begin_comment
comment|/*  * PCI IMU interrupt enable, interrupt status and error status clear  * registers  */
end_comment

begin_define
define|#
directive|define
name|FO_PCI_IMU_ERR_INT_SPARE_S_MASK
value|0x00007c0000000000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_IMU_ERR_INT_SPARE_S_SHFT
value|42
end_define

begin_define
define|#
directive|define
name|FO_PCI_IMU_ERR_INT_EQ_OVER_S
value|0x0000020000000000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_IMU_ERR_INT_EQ_NOT_EN_S
value|0x0000010000000000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_IMU_ERR_INT_MSI_MAL_ERR_S
value|0x0000008000000000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_IMU_ERR_INT_MSI_PAR_ERR_S
value|0x0000004000000000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_IMU_ERR_INT_PMEACK_MES_NOT_EN_S
value|0x0000002000000000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_IMU_ERR_INT_PMPME_MES_NOT_EN_S
value|0x0000001000000000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_IMU_ERR_INT_FATAL_MES_NOT_EN_S
value|0x0000000800000000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_IMU_ERR_INT_NFATAL_MES_NOT_EN_S
value|0x0000000400000000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_IMU_ERR_INT_COR_MES_NOT_EN_S
value|0x0000000200000000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_IMU_ERR_INT_MSI_NOT_EN_S
value|0x0000000100000000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_IMU_ERR_INT_SPARE_P_MASK
value|0x0000000000007c00ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_IMU_ERR_INT_SPARE_P_SHFT
value|10
end_define

begin_define
define|#
directive|define
name|FO_PCI_IMU_ERR_INT_EQ_OVER_P
value|0x0000000000000200ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_IMU_ERR_INT_EQ_NOT_EN_P
value|0x0000000000000100ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_IMU_ERR_INT_MSI_MAL_ERR_P
value|0x0000000000000080ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_IMU_ERR_INT_MSI_PAR_ERR_P
value|0x0000000000000040ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_IMU_ERR_INT_PMEACK_MES_NOT_EN_P
value|0x0000000000000020ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_IMU_ERR_INT_PMPME_MES_NOT_EN_P
value|0x0000000000000010ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_IMU_ERR_INT_FATAL_MES_NOT_EN_P
value|0x0000000000000008ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_IMU_ERR_INT_NFATAL_MES_NOT_EN_P
value|0x0000000000000004ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_IMU_ERR_INT_COR_MES_NOT_EN_P
value|0x0000000000000002ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_IMU_ERR_INT_MSI_NOT_EN_P
value|0x0000000000000001ULL
end_define

begin_comment
comment|/* PCI IMU RDS error log register */
end_comment

begin_define
define|#
directive|define
name|FO_PCI_IMU_RDS_ERR_LOG_TYPE_MASK
value|0xfc00000000000000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_IMU_RDS_ERR_LOG_TYPE_SHFT
value|58
end_define

begin_define
define|#
directive|define
name|FO_PCI_IMU_RDS_ERR_LOG_LENGTH_MASK
value|0x03ff000000000000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_IMU_RDS_ERR_LOG_LENGTH_SHFT
value|48
end_define

begin_define
define|#
directive|define
name|FO_PCI_IMU_RDS_ERR_LOG_REQ_ID_MASK
value|0x0000ffff00000000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_IMU_RDS_ERR_LOG_REQ_ID_SHFT
value|32
end_define

begin_define
define|#
directive|define
name|FO_PCI_IMU_RDS_ERR_LOG_TLP_TAG_MASK
value|0x00000000ff000000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_IMU_RDS_ERR_LOG_TLP_TAG_SHFT
value|24
end_define

begin_define
define|#
directive|define
name|FO_PCI_IMU_RDS_ERR_LOG_BE_MCODE_MASK
value|0x0000000000ff0000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_IMU_RDS_ERR_LOG_BE_MCODE_SHFT
value|16
end_define

begin_define
define|#
directive|define
name|FO_PCI_IMU_RDS_ERR_LOG_MSI_DATA_MASK
value|0x000000000000ffffULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_IMU_RDS_ERR_LOG_MSI_DATA_SHFT
value|0
end_define

begin_comment
comment|/* PCI IMU SCS error log register */
end_comment

begin_define
define|#
directive|define
name|FO_PCI_IMU_SCS_ERR_LOG_TYPE_MASK
value|0xfc00000000000000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_IMU_SCS_ERR_LOG_TYPE_SHFT
value|58
end_define

begin_define
define|#
directive|define
name|FO_PCI_IMU_SCS_ERR_LOG_LENGTH_MASK
value|0x03ff000000000000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_IMU_SCS_ERR_LOG_LENGTH_SHFT
value|48
end_define

begin_define
define|#
directive|define
name|FO_PCI_IMU_SCS_ERR_LOG_REQ_ID_MASK
value|0x0000ffff00000000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_IMU_SCS_ERR_LOG_REQ_ID_SHFT
value|32
end_define

begin_define
define|#
directive|define
name|FO_PCI_IMU_SCS_ERR_LOG_TLP_TAG_MASK
value|0x00000000ff000000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_IMU_SCS_ERR_LOG_TLP_TAG_SHFT
value|24
end_define

begin_define
define|#
directive|define
name|FO_PCI_IMU_SCS_ERR_LOG_BE_MODE_MASK
value|0x0000000000ff0000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_IMU_SCS_ERR_LOG_BE_MCODE_SHFT
value|16
end_define

begin_define
define|#
directive|define
name|FO_PCI_IMU_SCS_ERR_LOG_EQ_NUM_MASK
value|0x000000000000003fULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_IMU_SCS_ERR_LOG_EQ_NUM_SHFT
value|0
end_define

begin_comment
comment|/* PCI IMU EQS error log register */
end_comment

begin_define
define|#
directive|define
name|FO_PCI_IMU_EQS_ERR_LOG_EQ_NUM_MASK
value|0x000000000000003fULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_IMU_EQS_ERROR_LOG_EQ_NUM_SHFT
value|0
end_define

begin_comment
comment|/*  * PCI ERR COR, ERR NONFATAL, ERR FATAL, PM PME and PME To ACK mapping  * registers  */
end_comment

begin_define
define|#
directive|define
name|FO_PCI_ERR_PME_V
value|0x8000000000000000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_ERR_PME_EQNUM_MASK
value|0x000000000000003fULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_ERR_PME_EQNUM_SHFT
value|0
end_define

begin_comment
comment|/* PCI DMC core and block interrupt enable register */
end_comment

begin_define
define|#
directive|define
name|FO_PCI_DMC_CORE_BLOCK_INT_EN_DMC
value|0x8000000000000000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_DMC_CORE_BLOCK_INT_EN_MMU
value|0x0000000000000002ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_DMC_CORE_BLOCK_INT_EN_IMU
value|0x0000000000000001ULL
end_define

begin_comment
comment|/* PCI DMC core and block error status register */
end_comment

begin_define
define|#
directive|define
name|FO_PCI_DMC_CORE_BLOCK_ERR_STAT_MMU
value|0x0000000000000002ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_DMC_CORE_BLOCK_ERR_STAT_IMU
value|0x0000000000000001ULL
end_define

begin_comment
comment|/* PCI multi core error status register */
end_comment

begin_define
define|#
directive|define
name|FO_PCI_MULTI_CORE_ERR_STAT_PEC
value|0x0000000000000002ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_MULTI_CORE_ERR_STAT_DMC
value|0x0000000000000001ULL
end_define

begin_comment
comment|/* PCI MSI 32-bit address register */
end_comment

begin_define
define|#
directive|define
name|FO_PCI_MSI_32_BIT_ADDR_MASK
value|0x00000000ffff0000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_MSI_32_BIT_ADDR_SHFT
value|16
end_define

begin_comment
comment|/* PCI MSI 64-bit address register */
end_comment

begin_define
define|#
directive|define
name|FO_PCI_MSI_64_BIT_ADDR_MASK
value|0x0000ffffffff0000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_MSI_64_BIT_ADDR_SHFT
value|16
end_define

begin_comment
comment|/*  * PCI MMU interrupt enable, interrupt status and error status clear  * registers  */
end_comment

begin_define
define|#
directive|define
name|FO_PCI_MMU_ERR_INT_S_MASK
value|0x0000ffff00000000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_MMU_ERR_INT_S_SHFT
value|32
end_define

begin_define
define|#
directive|define
name|FO_PCI_MMU_ERR_INT_TBW_DPE_S
value|0x0000800000000000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_MMU_ERR_INT_TBW_ERR_S
value|0x0000400000000000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_MMU_ERR_INT_TBW_UDE_S
value|0x0000200000000000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_MMU_ERR_INT_TBW_DME_S
value|0x0000100000000000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_MMU_ERR_INT_SPARE3_S
value|0x0000080000000000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_MMU_ERR_INT_SPARE2_S
value|0x0000040000000000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_MMU_ERR_INT_TTC_CAE_S
value|0x0000020000000000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_PCI_MMU_ERR_INT_TTC_DPE_S
value|0x0000010000000000ULL
end_define

begin_define
define|#
directive|define
name|OBERON_PCI_MMU_ERR_INT_TTC_DUE_S
value|0x0000010000000000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_MMU_ERR_INT_TTE_PRT_S
value|0x0000008000000000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_MMU_ERR_INT_TTE_INV_S
value|0x0000004000000000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_MMU_ERR_INT_TRN_OOR_S
value|0x0000002000000000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_MMU_ERR_INT_TRN_ERR_S
value|0x0000001000000000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_MMU_ERR_INT_SPARE1_S
value|0x0000000800000000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_MMU_ERR_INT_SPARE0_S
value|0x0000000400000000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_MMU_ERR_INT_BYP_OOR_S
value|0x0000000200000000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_MMU_ERR_INT_BYP_ERR_S
value|0x0000000100000000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_MMU_ERR_INT_P_MASK
value|0x000000000000ffffULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_MMU_ERR_INT_P_SHFT
value|0
end_define

begin_define
define|#
directive|define
name|FO_PCI_MMU_ERR_INT_TBW_DPE_P
value|0x0000000000008000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_MMU_ERR_INT_TBW_ERR_P
value|0x0000000000004000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_MMU_ERR_INT_TBW_UDE_P
value|0x0000000000002000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_MMU_ERR_INT_TBW_DME_P
value|0x0000000000001000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_MMU_ERR_INT_SPARE3_P
value|0x0000000000000800ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_MMU_ERR_INT_SPARE2_P
value|0x0000000000000400ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_MMU_ERR_INT_TTC_CAE_P
value|0x0000000000000200ULL
end_define

begin_define
define|#
directive|define
name|FIRE_PCI_MMU_ERR_INT_TTC_DPE_P
value|0x0000000000000100ULL
end_define

begin_define
define|#
directive|define
name|OBERON_PCI_MMU_ERR_INT_TTC_DUE_P
value|0x0000000000000100ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_MMU_ERR_INT_TTE_PRT_P
value|0x0000000000000080ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_MMU_ERR_INT_TTE_INV_P
value|0x0000000000000040ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_MMU_ERR_INT_TRN_OOR_P
value|0x0000000000000020ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_MMU_ERR_INT_TRN_ERR_P
value|0x0000000000000010ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_MMU_ERR_INT_SPARE1_P
value|0x0000000000000008ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_MMU_ERR_INT_SPARE0_P
value|0x0000000000000004ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_MMU_ERR_INT_BYP_OOR_P
value|0x0000000000000002ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_MMU_ERR_INT_BYP_ERR_P
value|0x0000000000000001ULL
end_define

begin_comment
comment|/* PCI MMU translation fault address register */
end_comment

begin_define
define|#
directive|define
name|FO_PCI_MMU_TRANS_FAULT_ADDR_VA_MASK
value|0xfffffffffffffffcULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_MMU_TRANS_FAULT_ADDR_VA_SHFT
value|2
end_define

begin_comment
comment|/* PCI MMU translation fault status register */
end_comment

begin_define
define|#
directive|define
name|FO_PCI_MMU_TRANS_FAULT_STAT_ENTRY_MASK
value|0x000001ff00000000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_MMU_TRANS_FAULT_STAT_ENTRY_SHFT
value|32
end_define

begin_define
define|#
directive|define
name|FO_PCI_MMU_TRANS_FAULT_STAT_TYPE_MASK
value|0x00000000007f0000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_MMU_TRANS_FAULT_STAT_TYPE_SHFT
value|16
end_define

begin_define
define|#
directive|define
name|FO_PCI_MMU_TRANS_FAULT_STAT_ID_MASK
value|0x000000000000ffffULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_MMU_TRANS_FAULT_STAT_ID_SHFT
value|0
end_define

begin_comment
comment|/*  * PCI ILU interrupt enable, interrupt status and error status clear  * registers  */
end_comment

begin_define
define|#
directive|define
name|FO_PCI_ILU_ERR_INT_SPARE3_S
value|0x0000008000000000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_ILU_ERR_INT_SPARE2_S
value|0x0000004000000000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_ILU_ERR_INT_SPARE1_S
value|0x0000002000000000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_PCI_ILU_ERR_INT_IHB_PE_S
value|0x0000001000000000ULL
end_define

begin_define
define|#
directive|define
name|OBERON_PCI_ILU_ERR_INT_IHB_UE_S
value|0x0000001000000000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_ILU_ERR_INT_SPARE3_P
value|0x0000000000000080ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_ILU_ERR_INT_SPARE2_P
value|0x0000000000000040ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_ILU_ERR_INT_SPARE1_P
value|0x0000000000000020ULL
end_define

begin_define
define|#
directive|define
name|FIRE_PCI_ILU_ERR_INT_IHB_PE_P
value|0x0000000000000010ULL
end_define

begin_define
define|#
directive|define
name|OBERON_PCI_ILU_ERR_INT_IHB_UE_P
value|0x0000000000000010ULL
end_define

begin_comment
comment|/* PCI DMC debug select registers for port a/b */
end_comment

begin_define
define|#
directive|define
name|FO_PCI_DMC_DBG_SEL_PORT_BLCK_MASK
value|0x00000000000003c0ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_DMC_DBG_SEL_PORT_BLCK_SHFT
value|6
end_define

begin_define
define|#
directive|define
name|FO_PCI_DMC_DBG_SEL_PORT_SUB_MASK
value|0x0000000000000038ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_DMC_DBG_SEL_PORT_SUB_SHFT
value|3
end_define

begin_define
define|#
directive|define
name|FO_PCI_DMC_DBG_SEL_PORT_SUB_SGNL_MASK
value|0x0000000000000007ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_DMC_DBG_SEL_PORT_SUB_SGNL_SHFT
value|0
end_define

begin_comment
comment|/* PCI PEC core and block interrupt enable register */
end_comment

begin_define
define|#
directive|define
name|FO_PCI_PEC_CORE_BLOCK_INT_EN_PEC
value|0x8000000000000000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_PEC_CORE_BLOCK_INT_EN_ILU
value|0x0000000000000008ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_PEC_CORE_BLOCK_INT_EN_UERR
value|0x0000000000000004ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_PEC_CORE_BLOCK_INT_EN_CERR
value|0x0000000000000002ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_PEC_CORE_BLOCK_INT_EN_OEVENT
value|0x0000000000000001ULL
end_define

begin_comment
comment|/* PCI PEC core and block interrupt status register */
end_comment

begin_define
define|#
directive|define
name|FO_PCI_PEC_CORE_BLOCK_INT_STAT_ILU
value|0x0000000000000008ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_PEC_CORE_BLOCK_INT_STAT_UERR
value|0x0000000000000004ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_PEC_CORE_BLOCK_INT_STAT_CERR
value|0x0000000000000002ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_PEC_CORE_BLOCK_INT_STAT_OEVENT
value|0x0000000000000001ULL
end_define

begin_comment
comment|/* PCI TLU control register */
end_comment

begin_define
define|#
directive|define
name|FO_PCI_TLU_CTRL_L0S_TIM_MASK
value|0x00000000ff000000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_CTRL_L0S_TIM_SHFT
value|24
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_CTRL_NWPR_EN
value|0x0000000000100000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_CTRL_CTO_SEL_MASK
value|0x0000000000070000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_CTRL_CTO_SEL_SHFT
value|16
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_CTRL_CFG_MASK
value|0x000000000000ffffULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_CTRL_CFG_SHFT
value|0
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_CTRL_CFG_REMAIN_DETECT_QUIET
value|0x0000000000000100ULL
end_define

begin_comment
comment|/*  * PCI TLU other event interrupt enable, interrupt status and status clear  * registers  */
end_comment

begin_define
define|#
directive|define
name|FO_PCI_TLU_OEVENT_S_MASK
value|0x00ffffff00000000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_OEVENT_S_SHFT
value|32
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_OEVENT_SPARE_S
value|0x0080000000000000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_OEVENT_MFC_S
value|0x0040000000000000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_OEVENT_CTO_S
value|0x0020000000000000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_OEVENT_NFP_S
value|0x0010000000000000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_OEVENT_LWC_S
value|0x0008000000000000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_OEVENT_MRC_S
value|0x0004000000000000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_OEVENT_WUC_S
value|0x0002000000000000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_OEVENT_RUC_S
value|0x0001000000000000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_OEVENT_CRS_S
value|0x0000800000000000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_OEVENT_IIP_S
value|0x0000400000000000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_OEVENT_EDP_S
value|0x0000200000000000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_PCI_TLU_OEVENT_EHP_S
value|0x0000100000000000ULL
end_define

begin_define
define|#
directive|define
name|OBERON_PCI_TLU_OEVENT_EHBUE_S
value|0x0000100000000000ULL
end_define

begin_define
define|#
directive|define
name|OBERON_PCI_TLU_OEVENT_EDBUE_S
value|0x0000100000000000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_OEVENT_LIN_S
value|0x0000080000000000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_OEVENT_LRS_S
value|0x0000040000000000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_OEVENT_LDN_S
value|0x0000020000000000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_OEVENT_LUP_S
value|0x0000010000000000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_OEVENT_LPU_S_MASK
value|0x000000c000000000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_OEVENT_LPU_S_SHFT
value|38
end_define

begin_define
define|#
directive|define
name|OBERON_PCI_TLU_OEVENT_TLUEITMO_S
value|0x0000008000000000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_OEVENT_ERU_S
value|0x0000002000000000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_OEVENT_ERO_S
value|0x0000001000000000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_OEVENT_EMP_S
value|0x0000000800000000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_OEVENT_EPE_S
value|0x0000000400000000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_PCI_TLU_OEVENT_ERP_S
value|0x0000000200000000ULL
end_define

begin_define
define|#
directive|define
name|OBERON_PCI_TLU_OEVENT_ERBU_S
value|0x0000000200000000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_PCI_TLU_OEVENT_EIP_S
value|0x0000000100000000ULL
end_define

begin_define
define|#
directive|define
name|OBERON_PCI_TLU_OEVENT_EIUE_S
value|0x0000000100000000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_OEVENT_P_MASK
value|0x0000000000ffffffULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_OEVENT_P_SHFT
value|0
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_OEVENT_SPARE_P
value|0x0000000000800000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_OEVENT_MFC_P
value|0x0000000000400000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_OEVENT_CTO_P
value|0x0000000000200000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_OEVENT_NFP_P
value|0x0000000000100000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_OEVENT_LWC_P
value|0x0000000000080000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_OEVENT_MRC_P
value|0x0000000000040000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_OEVENT_WUC_P
value|0x0000000000020000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_OEVENT_RUC_P
value|0x0000000000010000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_OEVENT_CRS_P
value|0x0000000000008000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_OEVENT_IIP_P
value|0x0000000000004000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_OEVENT_EDP_P
value|0x0000000000002000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_PCI_TLU_OEVENT_EHP_P
value|0x0000000000001000ULL
end_define

begin_define
define|#
directive|define
name|OBERON_PCI_TLU_OEVENT_EHBUE_P
value|0x0000000000001000ULL
end_define

begin_define
define|#
directive|define
name|OBERON_PCI_TLU_OEVENT_EDBUE_P
value|0x0000000000001000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_OEVENT_LIN_P
value|0x0000000000000800ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_OEVENT_LRS_P
value|0x0000000000000400ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_OEVENT_LDN_P
value|0x0000000000000200ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_OEVENT_LUP_P
value|0x0000000000000100ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_OEVENT_LPU_P_MASK
value|0x00000000000000c0ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_OEVENT_LPU_P_SHFT
value|6
end_define

begin_define
define|#
directive|define
name|OBERON_PCI_TLU_OEVENT_TLUEITMO_P
value|0x0000000000000080ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_OEVENT_ERU_P
value|0x0000000000000020ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_OEVENT_ERO_P
value|0x0000000000000010ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_OEVENT_EMP_P
value|0x0000000000000008ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_OEVENT_EPE_P
value|0x0000000000000004ULL
end_define

begin_define
define|#
directive|define
name|FIRE_PCI_TLU_OEVENT_ERP_P
value|0x0000000000000002ULL
end_define

begin_define
define|#
directive|define
name|OBERON_PCI_TLU_OEVENT_ERBU_P
value|0x0000000000000002ULL
end_define

begin_define
define|#
directive|define
name|FIRE_PCI_TLU_OEVENT_EIP_P
value|0x0000000000000001ULL
end_define

begin_define
define|#
directive|define
name|OBERON_PCI_TLU_OEVENT_EIUE_P
value|0x0000000000000001ULL
end_define

begin_comment
comment|/* PCI receive/transmit DLU/TLU other event header 1/2 log registers */
end_comment

begin_define
define|#
directive|define
name|FO_PCI_TLU_OEVENT_HDR_LOG_MASK
value|0xffffffffffffffffULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_OEVENT_HDR_LOG_SHFT
value|0
end_define

begin_comment
comment|/* PCI TLU device control register */
end_comment

begin_define
define|#
directive|define
name|FO_PCI_TLU_DEV_CTRL_MRRS_MASK
value|0x0000000000007000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_DEV_CTRL_MRRS_SHFT
value|12
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_DEV_CTRL_MPS_MASK
value|0x00000000000000e0ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_DEV_CTRL_MPS_SHFT
value|5
end_define

begin_comment
comment|/*  * PCI TLU uncorrectable error interrupt enable, interrupt status and  * status clear registers  */
end_comment

begin_define
define|#
directive|define
name|FO_PCI_TLU_UERR_INT_S_MASK
value|0x001fffff00000000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_UERR_INT_S_SHFT
value|32
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_UERR_INT_UR_S
value|0x0010000000000000ULL
end_define

begin_define
define|#
directive|define
name|OBERON_PCI_TLU_UERR_INT_ECRC_S
value|0x0008000000000000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_UERR_INT_MFP_S
value|0x0004000000000000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_UERR_INT_ROF_S
value|0x0002000000000000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_UERR_INT_UC_S
value|0x0001000000000000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_UERR_INT_CA_S
value|0x0000800000000000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_UERR_INT_CTO_S
value|0x0000400000000000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_UERR_INT_FCP_S
value|0x0000200000000000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_PCI_TLU_UERR_INT_PP_S
value|0x0000100000000000ULL
end_define

begin_define
define|#
directive|define
name|OBERON_PCI_TLU_UERR_INT_POIS_S
value|0x0000100000000000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_UERR_INT_DLP_S
value|0x0000001000000000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_UERR_INT_TE_S
value|0x0000000100000000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_UERR_INT_P_MASK
value|0x00000000001fffffULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_UERR_INT_P_SHFT
value|0
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_UERR_INT_UR_P
value|0x0000000000100000ULL
end_define

begin_define
define|#
directive|define
name|OBERON_PCI_TLU_UERR_INT_ECRC_P
value|0x0000000000080000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_UERR_INT_MFP_P
value|0x0000000000040000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_UERR_INT_ROF_P
value|0x0000000000020000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_UERR_INT_UC_P
value|0x0000000000010000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_UERR_INT_CA_P
value|0x0000000000008000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_UERR_INT_CTO_P
value|0x0000000000004000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_UERR_INT_FCP_P
value|0x0000000000002000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_PCI_TLU_UERR_INT_PP_P
value|0x0000000000001000ULL
end_define

begin_define
define|#
directive|define
name|OBERON_PCI_TLU_UERR_INT_POIS_P
value|0x0000000000001000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_UERR_INT_DLP_P
value|0x0000000000000010ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_UERR_INT_TE_P
value|0x0000000000000001ULL
end_define

begin_comment
comment|/*  * PCI TLU correctable error interrupt enable, interrupt status and  * status clear registers  */
end_comment

begin_define
define|#
directive|define
name|FO_PCI_TLU_CERR_INT_S_MASK
value|0x001fffff00000000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_CERR_INT_S_SHFT
value|32
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_CERR_INT_RTO_S
value|0x0000100000000000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_CERR_INT_RNR_S
value|0x0000010000000000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_CERR_INT_BDP_S
value|0x0000008000000000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_CERR_INT_BTP_S
value|0x0000004000000000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_CERR_INT_RE_S
value|0x0000000100000000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_CERR_INT_P_MASK
value|0x00000000001fffffULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_CERR_INT_P_SHFT
value|0
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_CERR_INT_RTO_P
value|0x0000000000001000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_CERR_INT_RNR_P
value|0x0000000000000100ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_CERR_INT_BDP_P
value|0x0000000000000080ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_CERR_INT_BTP_P
value|0x0000000000000040ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_CERR_INT_RE_P
value|0x0000000000000001ULL
end_define

begin_comment
comment|/* PCI TLU reset register */
end_comment

begin_define
define|#
directive|define
name|FO_PCI_LPU_RST_WE
value|0x0000000080000000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_LPU_RST_UNUSED_MASK
value|0x0000000000000e00ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_LPU_RST_UNUSED_SHFT
value|9
end_define

begin_define
define|#
directive|define
name|FO_PCI_LPU_RST_ERR
value|0x0000000000000100ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_LPU_RST_TXLINK
value|0x0000000000000080ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_LPU_RST_RXLINK
value|0x0000000000000040ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_LPU_RST_SMLINK
value|0x0000000000000020ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_LPU_RST_LTSSM
value|0x0000000000000010ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_LPU_RST_TXPHY
value|0x0000000000000008ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_LPU_RST_RXPHY
value|0x0000000000000004ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_LPU_RST_TXPCS
value|0x0000000000000002ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_LPU_RST_RXPCS
value|0x0000000000000001ULL
end_define

begin_comment
comment|/* PCI TLU link control register */
end_comment

begin_define
define|#
directive|define
name|FO_PCI_TLU_LNK_CTRL_EXTSYNC
value|0x0000000000000080ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_LNK_CTRL_CLK
value|0x0000000000000040ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_LNK_CTRL_RETRAIN
value|0x0000000000000020ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_LNK_CTRL_DIS
value|0x0000000000000010ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_LNK_CTRL_RCB
value|0x0000000000000008ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_LNK_CTRL_ASPM_L0S_L1S
value|0x0000000000000003ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_LNK_CTRL_ASPM_L1S
value|0x0000000000000002ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_LNK_CTRL_ASPM_L0S
value|0x0000000000000001ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_LNK_CTRL_ASPM_DIS
value|0x0000000000000000ULL
end_define

begin_comment
comment|/* PCI TLU link status register */
end_comment

begin_define
define|#
directive|define
name|FO_PCI_TLU_LNK_STAT_CLK
value|0x0000000000001000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_LNK_STAT_TRAIN
value|0x0000000000000800ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_LNK_STAT_ERR
value|0x0000000000000400ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_LNK_STAT_WDTH_MASK
value|0x00000000000003f0ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_LNK_STAT_WDTH_SHFT
value|4
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_LNK_STAT_SPEED_MASK
value|0x000000000000000fULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_LNK_STAT_SPEED_SHFT
value|0
end_define

begin_comment
comment|/*  * PCI receive/transmit DLU/TLU uncorrectable error header 1/2 log  * registers  */
end_comment

begin_define
define|#
directive|define
name|FO_PCI_TLU_UERR_HDR_LOG_MASK
value|0xffffffffffffffffULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_UERR_HDR_LOG_SHFT
value|0
end_define

begin_comment
comment|/* PCI DLU/LPU interrupt status and mask registers */
end_comment

begin_define
define|#
directive|define
name|FO_PCI_LPU_INT_INT
value|0x0000000080000000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_PCI_LPU_INT_PRF_CNT2_OFLW
value|0x0000000000000080ULL
end_define

begin_define
define|#
directive|define
name|FIRE_PCI_LPU_INT_PRF_CNT1_OFLW
value|0x0000000000000040ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_LPU_INT_LNK_LYR
value|0x0000000000000020ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_LPU_INT_PHY_ERR
value|0x0000000000000010ULL
end_define

begin_define
define|#
directive|define
name|FIRE_PCI_LPU_INT_LTSSM
value|0x0000000000000008ULL
end_define

begin_define
define|#
directive|define
name|FIRE_PCI_LPU_INT_PHY_TX
value|0x0000000000000004ULL
end_define

begin_define
define|#
directive|define
name|FIRE_PCI_LPU_INT_PHY_RX
value|0x0000000000000002ULL
end_define

begin_define
define|#
directive|define
name|FIRE_PCI_LPU_INT_PHY_GB
value|0x0000000000000001ULL
end_define

begin_comment
comment|/* PCI DLU/LPU link layer config register */
end_comment

begin_define
define|#
directive|define
name|FIRE_PCI_LPU_LNK_LYR_CFG_AUTO_UPDT_DIS
value|0x0000000000080000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_PCI_LPU_LNK_LYR_CFG_FREQ_NAK_EN
value|0x0000000000040000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_PCI_LPU_LNK_LYR_CFG_RPLY_AFTER_REQ
value|0x0000000000020000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_PCI_LPU_LNK_LYR_CFG_LAT_THRS_WR_EN
value|0x0000000000010000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_LPU_LNK_LYR_CFG_VC0_EN
value|0x0000000000000100ULL
end_define

begin_define
define|#
directive|define
name|FIRE_PCI_LPU_LNK_LYR_CFG_L0S_ADJ_FAC_EN
value|0x0000000000000010ULL
end_define

begin_define
define|#
directive|define
name|FIER_PCI_LPU_LNK_LYR_CFG_TLP_XMIT_FC_EN
value|0x0000000000000008ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_LPU_LNK_LYR_CFG_FREQ_ACK_EN
value|0x0000000000000004ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_LPU_LNK_LYR_CFG_RETRY_DIS
value|0x0000000000000002ULL
end_define

begin_comment
comment|/* PCI DLU/LPU link layer interrupt and status register */
end_comment

begin_define
define|#
directive|define
name|FO_PCI_LPU_LNK_LYR_INT_STAT_LNK_ERR_ACT
value|0x0000000080000000ULL
end_define

begin_define
define|#
directive|define
name|OBERON_PCI_LPU_LNK_LYR_INT_STAT_PBUS_PE
value|0x0000000000800000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_LPU_LNK_LYR_INT_STAT_USPRTD_DLLP
value|0x0000000000400000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_LPU_LNK_LYR_INT_STAT_DLLP_RX_ERR
value|0x0000000000200000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_LPU_LNK_LYR_INT_STAT_BAD_DLLP
value|0x0000000000100000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_LPU_LNK_LYR_INT_STAT_TLP_RX_ERR
value|0x0000000000040000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_LPU_LNK_LYR_INT_STAT_SRC_ERR_TLP
value|0x0000000000020000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_LPU_LNK_LYR_INT_STAT_BAD_TLP
value|0x0000000000010000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_LPU_LNK_LYR_INT_STAT_RBF_UDF_ERR
value|0x0000000000000200ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_LPU_LNK_LYR_INT_STAT_RBF_OVF_ERR
value|0x0000000000000100ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_LPU_LNK_LYR_INT_STAT_EG_TLPM_ERR
value|0x0000000000000080ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_LPU_LNK_LYR_INT_STAT_EG_TFRM_ERR
value|0x0000000000000040ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_LPU_LNK_LYR_INT_STAT_RBF_PE
value|0x0000000000000020ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_LPU_LNK_LYR_INT_STAT_EGRESS_PE
value|0x0000000000000010ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_LPU_LNK_LYR_INT_STAT_RPLY_TMR_TO
value|0x0000000000000004ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_LPU_LNK_LYR_INT_STAT_RPLY_NUM_RO
value|0x0000000000000002ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_LPU_LNK_LYR_INT_STAT_DLNK_PES
value|0x0000000000000001ULL
end_define

begin_comment
comment|/* PCI DLU/LPU flow control update control register */
end_comment

begin_define
define|#
directive|define
name|FO_PCI_LPU_FLW_CTRL_UPDT_CTRL_FC0_C_EN
value|0x0000000000000004ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_LPU_FLW_CTRL_UPDT_CTRL_FC0_NP_EN
value|0x0000000000000002ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_LPU_FLW_CTRL_UPDT_CTRL_FC0_P_EN
value|0x0000000000000001ULL
end_define

begin_comment
comment|/* PCI DLU/LPU txlink ACKNAK latency timer threshold register */
end_comment

begin_define
define|#
directive|define
name|FO_PCI_LPU_TXLNK_FREQ_LAT_TMR_THRS_MASK
value|0x000000000000ffffULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_LPU_TXLNK_FREQ_LAT_TMR_THRS_SHFT
value|0
end_define

begin_comment
comment|/* PCI DLU/LPU txlink replay timer threshold register */
end_comment

begin_define
define|#
directive|define
name|FO_PCI_LPU_TXLNK_RPLY_TMR_THRS_MASK
value|0x00000000000fffffULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_LPU_TXLNK_RPLY_TMR_THRS_SHFT
value|0
end_define

begin_comment
comment|/* PCI DLU/LPU txlink FIFO pointer register */
end_comment

begin_define
define|#
directive|define
name|FO_PCI_LPU_TXLNK_RTR_FIFO_PTR_TL_MASK
value|0x00000000ffff0000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_LPU_TXLNK_RTR_FIFO_PTR_TL_SHFT
value|16
end_define

begin_define
define|#
directive|define
name|FO_PCI_LPU_TXLNK_RTR_FIFO_PTR_HD_MASK
value|0x000000000000ffffULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_LPU_TXLNK_RTR_FIFO_PTR_HD_SHFT
value|0
end_define

begin_comment
comment|/* PCI DLU/LPU phy layer interrupt and status register */
end_comment

begin_define
define|#
directive|define
name|FO_PCI_LPU_PHY_LYR_INT_STAT_PHY_LYR_ERR
value|0x0000000080000000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_LPU_PHY_LYR_INT_STAT_KC_DLLP_ERR
value|0x0000000000000800ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_LPU_PHY_LYR_INT_STAT_END_POS_ERR
value|0x0000000000000400ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_LPU_PHY_LYR_INT_STAT_LNK_ERR
value|0x0000000000000200ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_LPU_PHY_LYR_INT_STAT_TRN_ERR
value|0x0000000000000100ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_LPU_PHY_LYR_INT_STAT_EDB_DET
value|0x0000000000000080ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_LPU_PHY_LYR_INT_STAT_SDP_END
value|0x0000000000000040ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_LPU_PHY_LYR_INT_STAT_STP_END_EDB
value|0x0000000000000020ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_LPU_PHY_LYR_INT_STAT_INVC_ERR
value|0x0000000000000010ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_LPU_PHY_LYR_INT_STAT_MULTI_SDP
value|0x0000000000000008ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_LPU_PHY_LYR_INT_STAT_MULTI_STP
value|0x0000000000000004ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_LPU_PHY_LYR_INT_STAT_ILL_SDP_POS
value|0x0000000000000002ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_LPU_PHY_LYR_INT_STAT_ILL_STP_POS
value|0x0000000000000001ULL
end_define

begin_comment
comment|/* PCI DLU/LPU LTSSM config2 register */
end_comment

begin_define
define|#
directive|define
name|FO_PCI_LPU_LTSSM_CFG2_12_TO_MASK
value|0x00000000ffffffffULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_LPU_LTSSM_CFG2_12_TO_SHFT
value|0
end_define

begin_comment
comment|/* PCI DLU/LPU LTSSM config3 register */
end_comment

begin_define
define|#
directive|define
name|FO_PCI_LPU_LTSSM_CFG3_2_TO_MASK
value|0x00000000ffffffffULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_LPU_LTSSM_CFG3_2_TO_SHFT
value|0
end_define

begin_comment
comment|/* PCI DLU/LPU LTSSM config4 register */
end_comment

begin_define
define|#
directive|define
name|FO_PCI_LPU_LTSSM_CFG4_TRN_CTRL_MASK
value|0x00000000ff000000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_LPU_LTSSM_CFG4_TRN_CTRL_SHFT
value|24
end_define

begin_define
define|#
directive|define
name|FO_PCI_LPU_LTSSM_CFG4_DATA_RATE_MASK
value|0x0000000000ff0000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_LPU_LTSSM_CFG4_DATA_RATE_SHFT
value|16
end_define

begin_define
define|#
directive|define
name|FO_PCI_LPU_LTSSM_CFG4_N_FTS_MASK
value|0x000000000000ff00ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_LPU_LTSSM_CFG4_N_FTS_SHFT
value|8
end_define

begin_define
define|#
directive|define
name|FO_PCI_LPU_LTSSM_CFG4_LNK_NUM_MASK
value|0x00000000000000ffULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_LPU_LTSSM_CFG4_LNK_NUM_SHFT
value|0
end_define

begin_comment
comment|/* PCI DLU/LPU LTSSM config5 register */
end_comment

begin_define
define|#
directive|define
name|FO_PCI_LPU_LTSSM_CFG5_UNUSED0_MASK
value|0x00000000ffffe000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_LPU_LTSSM_CFG5_UNUSED0_SHFT
value|13
end_define

begin_define
define|#
directive|define
name|FO_PCI_LPU_LTSSM_CFG5_RCV_DET_TST_MODE
value|0x0000000000001000ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_LPU_LTSSM_CFG5_POLL_CMPLNC_DIS
value|0x0000000000000800ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_LPU_LTSSM_CFG5_TX_IDLE_TX_FTS
value|0x0000000000000400ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_LPU_LTSSM_CFG5_RX_FTS_RVR_LK
value|0x0000000000000200ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_LPU_LTSSM_CFG5_UNUSED1_MASK
value|0x0000000000000180ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_LPU_LTSSM_CFG5_UNUSED1_SHFT
value|7
end_define

begin_define
define|#
directive|define
name|FO_PCI_LPU_LTSSM_CFG5_LPBK_NTRY_ACTIVE
value|0x0000000000000040ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_LPU_LTSSM_CFG5_LPBK_NTRY_EXIT
value|0x0000000000000020ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_LPU_LTSSM_CFG5_LPBK_ACTIVE_EXIT
value|0x0000000000000010ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_LPU_LTSSM_CFG5_L1_IDLE_RCVRY_LK
value|0x0000000000000008ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_LPU_LTSSM_CFG5_L0_TRN_CNTRL_RST
value|0x0000000000000004ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_LPU_LTSSM_CFG5_L0_LPBK
value|0x0000000000000002ULL
end_define

begin_define
define|#
directive|define
name|FO_PCI_LPU_LTSSM_CFG5_UNUSED2
value|0x0000000000000001ULL
end_define

begin_comment
comment|/* Controller configuration and status registers */
end_comment

begin_define
define|#
directive|define
name|FIRE_JBUS_PAR_CTRL
value|0x60010
end_define

begin_define
define|#
directive|define
name|FO_XBC_ERR_LOG_EN
value|0x61000
end_define

begin_define
define|#
directive|define
name|FO_XBC_INT_EN
value|0x61008
end_define

begin_define
define|#
directive|define
name|FO_XBC_INT_STAT
value|0x61010
end_define

begin_define
define|#
directive|define
name|FO_XBC_ERR_STAT_CLR
value|0x61018
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_FATAL_RST_EN
value|0x61028
end_define

begin_define
define|#
directive|define
name|FIRE_JBCINT_ITRANS_ERR_LOG
value|0x61040
end_define

begin_define
define|#
directive|define
name|FIRE_JBCINT_ITRANS_ERR_LOG2
value|0x61048
end_define

begin_define
define|#
directive|define
name|FIRE_JBCINT_OTRANS_ERR_LOG
value|0x61040
end_define

begin_define
define|#
directive|define
name|FIRE_JBCINT_OTRANS_ERR_LOG2
value|0x61048
end_define

begin_define
define|#
directive|define
name|FIRE_FATAL_ERR_LOG
value|0x61050
end_define

begin_define
define|#
directive|define
name|FIRE_FATAL_ERR_LOG2
value|0x61058
end_define

begin_define
define|#
directive|define
name|FIRE_MERGE_TRANS_ERR_LOG
value|0x61060
end_define

begin_define
define|#
directive|define
name|FIRE_DMCINT_ODCD_ERR_LOG
value|0x61068
end_define

begin_define
define|#
directive|define
name|FIRE_DMCINT_IDC_ERR_LOG
value|0x61070
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_CSR_ERR_LOG
value|0x61078
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_CORE_BLOCK_INT_EN
value|0x61800
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_CORE_BLOCK_ERR_STAT
value|0x61808
end_define

begin_define
define|#
directive|define
name|FO_XBC_PRF_CNT_SEL
value|0x62000
end_define

begin_define
define|#
directive|define
name|FO_XBC_PRF_CNT0
value|0x62008
end_define

begin_define
define|#
directive|define
name|FO_XBC_PRF_CNT1
value|0x62010
end_define

begin_comment
comment|/* JBus parity control register */
end_comment

begin_define
define|#
directive|define
name|FIRE_JBUS_PAR_CTRL_P_EN
value|0x8000000000000000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBUS_PAR_CTRL_INVRTD_PAR_MASK
value|0x000000000000003cULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBUS_PAR_CTRL_INVRTD_PAR_SHFT
value|2
end_define

begin_define
define|#
directive|define
name|FIRE_JBUS_PAR_CTRL_NEXT_DATA
value|0x0000000000000002ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBUS_PAR_CTRL_NEXT_ADDR
value|0x0000000000000001ULL
end_define

begin_comment
comment|/* JBC error log enable register - may also apply to UBC */
end_comment

begin_define
define|#
directive|define
name|FIRE_JBC_ERR_LOG_EN_SPARE_MASK
value|0x00000000e0000000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_ERR_LOG_EN_SPARE_SHFT
value|29
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_ERR_LOG_EN_PIO_UNMAP_RD
value|0x0000000010000000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_ERR_LOG_EN_ILL_ACC_RD
value|0x0000000008000000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_ERR_LOG_EN_EBUS_TO
value|0x0000000004000000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_ERR_LOG_EN_MB_PEA
value|0x0000000002000000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_ERR_LOG_EN_MB_PER
value|0x0000000001000000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_ERR_LOG_EN_MB_PEW
value|0x0000000000800000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_ERR_LOG_EN_UE_ASYN
value|0x0000000000400000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_ERR_LOG_EN_CE_ASYN
value|0x0000000000200000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_ERR_LOG_EN_JTE
value|0x0000000000100000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_ERR_LOG_EN_JBE
value|0x0000000000080000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_ERR_LOG_EN_JUE
value|0x0000000000040000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_ERR_LOG_EN_IJP
value|0x0000000000020000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_ERR_LOG_EN_ICISE
value|0x0000000000010000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_ERR_LOG_EN_CPE
value|0x0000000000008000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_ERR_LOG_EN_APE
value|0x0000000000004000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_ERR_LOG_EN_WR_DPE
value|0x0000000000002000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_ERR_LOG_EN_RD_DPE
value|0x0000000000001000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_ERR_LOG_EN_ILL_BMW
value|0x0000000000000800ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_ERR_LOG_EN_ILL_BMR
value|0x0000000000000400ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_ERR_LOG_EN_BJC
value|0x0000000000000200ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_ERR_LOG_EN_PIO_UNMAP
value|0x0000000000000100ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_ERR_LOG_EN_PIO_DPE
value|0x0000000000000080ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_ERR_LOG_EN_PIO_CPE
value|0x0000000000000040ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_ERR_LOG_EN_ILL_ACC
value|0x0000000000000020ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_ERR_LOG_EN_UNSOL_RD
value|0x0000000000000010ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_ERR_LOG_EN_UNSOL_INT
value|0x0000000000000008ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_ERR_LOG_EN_JTCEEW
value|0x0000000000000004ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_ERR_LOG_EN_JTCEEI
value|0x0000000000000002ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_ERR_LOG_EN_JTCEER
value|0x0000000000000001ULL
end_define

begin_comment
comment|/* JBC interrupt enable, interrupt status and error status clear registers */
end_comment

begin_define
define|#
directive|define
name|FIRE_JBC_ERR_INT_SPARE_S_MASK
value|0xe000000000000000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_ERR_INT_SPARE_S_SHFT
value|61
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_ERR_INT_PIO_UNMAP_RD_S
value|0x1000000000000000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_ERR_INT_ILL_ACC_RD_S
value|0x0800000000000000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_ERR_INT_EBUS_TO_S
value|0x0400000000000000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_ERR_INT_MB_PEA_S
value|0x0200000000000000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_ERR_INT_MB_PER_S
value|0x0100000000000000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_ERR_INT_MB_PEW_S
value|0x0080000000000000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_ERR_INT_UE_ASYN_S
value|0x0040000000000000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_ERR_INT_CE_ASYN_S
value|0x0020000000000000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_ERR_INT_JTE_S
value|0x0010000000000000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_ERR_INT_JBE_S
value|0x0008000000000000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_ERR_INT_JUE_S
value|0x0004000000000000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_ERR_INT_IJP_S
value|0x0002000000000000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_ERR_INT_ICISE_S
value|0x0001000000000000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_ERR_INT_CPE_S
value|0x0000800000000000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_ERR_INT_APE_S
value|0x0000400000000000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_ERR_INT_WR_DPE_S
value|0x0000200000000000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_ERR_INT_RD_DPE_S
value|0x0000100000000000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_ERR_INT_ILL_BMW_S
value|0x0000080000000000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_ERR_INT_ILL_BMR_S
value|0x0000040000000000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_ERR_INT_BJC_S
value|0x0000020000000000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_ERR_INT_PIO_UNMAP_S
value|0x0000010000000000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_ERR_INT_PIO_DPE_S
value|0x0000008000000000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_ERR_INT_PIO_CPE_S
value|0x0000004000000000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_ERR_INT_ILL_ACC_S
value|0x0000002000000000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_ERR_INT_UNSOL_RD_S
value|0x0000001000000000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_ERR_INT_UNSOL_INT_S
value|0x0000000800000000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_ERR_INT_JTCEEW_S
value|0x0000000400000000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_ERR_INT_JTCEEI_S
value|0x0000000200000000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_ERR_INT_JTCEER_S
value|0x0000000100000000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_ERR_INT_SPARE_P_MASK
value|0x00000000e0000000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_ERR_INT_SPARE_P_SHFT
value|29
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_ERR_INT_PIO_UNMAP_RD_P
value|0x0000000010000000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_ERR_INT_ILL_ACC_RD_P
value|0x0000000008000000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_ERR_INT_EBUS_TO_P
value|0x0000000004000000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_ERR_INT_MB_PEA_P
value|0x0000000002000000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_ERR_INT_MB_PER_P
value|0x0000000001000000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_ERR_INT_MB_PEW_P
value|0x0000000000800000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_ERR_INT_UE_ASYN_P
value|0x0000000000400000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_ERR_INT_CE_ASYN_P
value|0x0000000000200000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_ERR_INT_JTE_P
value|0x0000000000100000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_ERR_INT_JBE_P
value|0x0000000000080000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_ERR_INT_JUE_P
value|0x0000000000040000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_ERR_INT_IJP_P
value|0x0000000000020000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_ERR_INT_ICISE_P
value|0x0000000000010000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_ERR_INT_CPE_P
value|0x0000000000008000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_ERR_INT_APE_P
value|0x0000000000004000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_ERR_INT_WR_DPE_P
value|0x0000000000002000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_ERR_INT_RD_DPE_P
value|0x0000000000001000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_ERR_INT_ILL_BMW_P
value|0x0000000000000800ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_ERR_INT_ILL_BMR_P
value|0x0000000000000400ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_ERR_INT_BJC_P
value|0x0000000000000200ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_ERR_INT_PIO_UNMAP_P
value|0x0000000000000100ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_ERR_INT_PIO_DPE_P
value|0x0000000000000080ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_ERR_INT_PIO_CPE_P
value|0x0000000000000040ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_ERR_INT_ILL_ACC_P
value|0x0000000000000020ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_ERR_INT_UNSOL_RD_P
value|0x0000000000000010ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_ERR_INT_UNSOL_INT_P
value|0x0000000000000008ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_ERR_INT_JTCEEW_P
value|0x0000000000000004ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_ERR_INT_JTCEEI_P
value|0x0000000000000002ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_ERR_INT_JTCEER_P
value|0x0000000000000001ULL
end_define

begin_comment
comment|/* UBC interrupt enable, error status and error status clear registers */
end_comment

begin_define
define|#
directive|define
name|OBERON_UBC_ERR_INT_PIORBEUE_S
value|0x0004000000000000ULL
end_define

begin_define
define|#
directive|define
name|OBERON_UBC_ERR_INT_PIOWBEUE_S
value|0x0002000000000000ULL
end_define

begin_define
define|#
directive|define
name|OBERON_UBC_ERR_INT_PIOWTUE_S
value|0x0001000000000000ULL
end_define

begin_define
define|#
directive|define
name|OBERON_UBC_ERR_INT_MEMWTAXB_S
value|0x0000080000000000ULL
end_define

begin_define
define|#
directive|define
name|OBERON_UBC_ERR_INT_MEMRDAXB_S
value|0x0000040000000000ULL
end_define

begin_define
define|#
directive|define
name|OBERON_UBC_ERR_INT_DMAWTUEB_S
value|0x0000020000000000ULL
end_define

begin_define
define|#
directive|define
name|OBERON_UBC_ERR_INT_DMARDUEB_S
value|0x0000010000000000ULL
end_define

begin_define
define|#
directive|define
name|OBERON_UBC_ERR_INT_MEMWTAXA_S
value|0x0000000800000000ULL
end_define

begin_define
define|#
directive|define
name|OBERON_UBC_ERR_INT_MEMRDAXA_S
value|0x0000000400000000ULL
end_define

begin_define
define|#
directive|define
name|OBERON_UBC_ERR_INT_DMAWTUEA_S
value|0x0000000200000000ULL
end_define

begin_define
define|#
directive|define
name|OBERON_UBC_ERR_INT_DMARDUEA_S
value|0x0000000100000000ULL
end_define

begin_define
define|#
directive|define
name|OBERON_UBC_ERR_INT_PIORBEUE_P
value|0x0000000000040000ULL
end_define

begin_define
define|#
directive|define
name|OBERON_UBC_ERR_INT_PIOWBEUE_P
value|0x0000000000020000ULL
end_define

begin_define
define|#
directive|define
name|OBERON_UBC_ERR_INT_PIOWTUE_P
value|0x0000000000010000ULL
end_define

begin_define
define|#
directive|define
name|OBERON_UBC_ERR_INT_MEMWTAXB_P
value|0x0000000000000800ULL
end_define

begin_define
define|#
directive|define
name|OBERON_UBC_ERR_INT_MEMRDAXB_P
value|0x0000000000000400ULL
end_define

begin_define
define|#
directive|define
name|OBERON_UBC_ERR_INT_DMARDUEB_P
value|0x0000000000000200ULL
end_define

begin_define
define|#
directive|define
name|OBERON_UBC_ERR_INT_DMAWTUEB_P
value|0x0000000000000100ULL
end_define

begin_define
define|#
directive|define
name|OBERON_UBC_ERR_INT_MEMWTAXA_P
value|0x0000000000000008ULL
end_define

begin_define
define|#
directive|define
name|OBERON_UBC_ERR_INT_MEMRDAXA_P
value|0x0000000000000004ULL
end_define

begin_define
define|#
directive|define
name|OBERON_UBC_ERR_INT_DMAWTUEA_P
value|0x0000000000000002ULL
end_define

begin_define
define|#
directive|define
name|OBERON_UBC_ERR_INT_DMARDUEA_P
value|0x0000000000000001ULL
end_define

begin_comment
comment|/* JBC fatal reset enable register */
end_comment

begin_define
define|#
directive|define
name|FIRE_JBC_FATAL_RST_EN_SPARE_P_INT_MASK
value|0x000000000c000000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_FATAL_RST_EN_SPARE_P_INT_SHFT
value|26
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_FATAL_RST_EN_MB_PEA_P_INT
value|0x0000000002000000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_FATAL_RST_EN_CPE_P_INT
value|0x0000000000008000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_FATAL_RST_EN_APE_P_INT
value|0x0000000000004000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_FATAL_RST_EN_PIO_CPE_INT
value|0x0000000000000040ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_FATAL_RST_EN_JTCEEW_P_INT
value|0x0000000000000004ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_FATAL_RST_EN_JTCEEI_P_INT
value|0x0000000000000002ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_FATAL_RST_EN_JTCEER_P_INT
value|0x0000000000000001ULL
end_define

begin_comment
comment|/* JBC JBCINT in transaction error log register */
end_comment

begin_define
define|#
directive|define
name|FIRE_JBCINT_ITRANS_ERR_LOG_Q_WORD_MASK
value|0x00c0000000000000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBCINT_ITRANS_ERR_LOG_Q_WORD_SHFT
value|54
end_define

begin_define
define|#
directive|define
name|FIRE_JBCINT_ITRANS_ERR_LOG_TRANSID_MASK
value|0x0003000000000000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBCINT_ITRANS_ERR_LOG_TRANSID_SHFT
value|48
end_define

begin_define
define|#
directive|define
name|FIRE_JBCINT_ITRANS_ERR_LOG_ADDR_MASK
value|0x000007ffffffffffULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBCINT_ITRANS_ERR_LOG_ADDR_SHFT
value|0
end_define

begin_comment
comment|/* JBC JBCINT in transaction error log register 2 */
end_comment

begin_define
define|#
directive|define
name|FIRE_JBCINT_ITRANS_ERR_LOG2_ARB_WN_MASK
value|0x000ffffff0000000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBCINT_ITRANS_ERR_LOG2_ARB_WN_SHFT
value|28
end_define

begin_define
define|#
directive|define
name|FIRE_JBCINT_ITRANS_ERR_LOG2_J_REQ_MASK
value|0x000000000fe00000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBCINT_ITRANS_ERR_LOG2_J_REQ_SHFT
value|21
end_define

begin_define
define|#
directive|define
name|FIRE_JBCINT_ITRANS_ERR_LOG2_J_PACK_MASK
value|0x00000000001fffffULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBCINT_ITRANS_ERR_LOG2_J_PACK_SHFT
value|0
end_define

begin_comment
comment|/* JBC JBCINT out transaction error log register */
end_comment

begin_define
define|#
directive|define
name|FIRE_JBCINT_OTRANS_ERR_LOG_TRANSID_MASK
value|0x003f000000000000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBCINT_OTRANS_ERR_LOG_TRANSID_SHFT
value|48
end_define

begin_define
define|#
directive|define
name|FIRE_JBCINT_OTRANS_ERR_LOG_ADDR_MASK
value|0x000007ffffffffffULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBCINT_OTRANS_ERR_LOG_ADDR_SHFT
value|0
end_define

begin_comment
comment|/* JBC JBCINT out transaction error log register 2 */
end_comment

begin_define
define|#
directive|define
name|FIRE_JBCINT_OTRANS_ERR_LOG2_ARB_WN_MASK
value|0x000ffffff0000000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBCINT_OTRANS_ERR_LOG2_ARB_WN_SHFT
value|28
end_define

begin_define
define|#
directive|define
name|FIRE_JBCINT_OTRANS_ERR_LOG2_J_REQ_MASK
value|0x000000000fe00000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBCINT_OTRANS_ERR_LOG2_J_REQ_SHFT
value|21
end_define

begin_define
define|#
directive|define
name|FIRE_JBCINT_OTRANS_ERR_LOG2_J_PACK_MASK
value|0x00000000001fffffULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBCINT_OTRANS_ERR_LOG2_J_PACK_SHFT
value|0
end_define

begin_comment
comment|/* JBC merge transaction error log register */
end_comment

begin_define
define|#
directive|define
name|FIRE_FATAL_ERR_LOG_DATA_MASK
value|0xffffffffffffffffULL
end_define

begin_define
define|#
directive|define
name|FIRE_FATAL_ERR_LOG_DATA_SHFT
value|0
end_define

begin_comment
comment|/* JBC merge transaction error log register 2 */
end_comment

begin_define
define|#
directive|define
name|FIRE_FATAL_ERR_LOG2_ARB_WN_MASK
value|0x000ffffff0000000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_FATAL_ERR_LOG2_ARB_WN_SHFT
value|28
end_define

begin_define
define|#
directive|define
name|FIRE_FATAL_ERR_LOG2_J_REQ_MASK
value|0x000000000fe00000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_FATAL_ERR_LOG2_J_REQ_SHFT
value|21
end_define

begin_define
define|#
directive|define
name|FIRE_FATAL_ERR_LOG2_J_PACK_MASK
value|0x00000000001fffffULL
end_define

begin_define
define|#
directive|define
name|FIRE_FATAL_ERR_LOG2_J_PACK_SHFT
value|0
end_define

begin_comment
comment|/* JBC merge transaction error log register */
end_comment

begin_define
define|#
directive|define
name|FIRE_MERGE_TRANS_ERR_LOG_Q_WORD_MASK
value|0x00c0000000000000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_MERGE_TRANS_ERR_LOG_Q_WORD_SHFT
value|54
end_define

begin_define
define|#
directive|define
name|FIRE_MERGE_TRANS_ERR_LOG_TRANSID_MASK
value|0x0003000000000000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_MERGE_TRANS_ERR_LOG_TRANSID_SHFT
value|48
end_define

begin_define
define|#
directive|define
name|FIRE_MERGE_TRANS_ERR_LOG_JBC_TAG_MASK
value|0x0000f80000000000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_MERGE_TRANS_ERR_LOG_JBC_TAG_SHFT
value|43
end_define

begin_define
define|#
directive|define
name|FIRE_MERGE_TRANS_ERR_LOG_ADDR_MASK
value|0x000007ffffffffffULL
end_define

begin_define
define|#
directive|define
name|FIRE_MERGE_TRANS_ERR_LOG_ADDR_SHFT
value|0
end_define

begin_comment
comment|/* JBC DMCINT ODCD error log register */
end_comment

begin_define
define|#
directive|define
name|FIRE_DMCINT_ODCD_ERR_LOG_TRANS_ID_MASK
value|0x0030000000000000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_DMCINT_ODCD_ERR_LOG_TRANS_ID_SHFT
value|52
end_define

begin_define
define|#
directive|define
name|FIRE_DMCINT_ODCD_ERR_LOG_AID_MASK
value|0x000f000000000000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_DMCINT_ODCD_ERR_LOG_AID_SHFT
value|48
end_define

begin_define
define|#
directive|define
name|FIRE_DMCINT_ODCD_ERR_LOG_TTYPE_MASK
value|0x0000f80000000000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_DMCINT_ODCD_ERR_LOG_TTYPE_SHFT
value|43
end_define

begin_define
define|#
directive|define
name|FIRE_DMCINT_ODCD_ERR_LOG_ADDR_MASK
value|0x000007ffffffffffULL
end_define

begin_define
define|#
directive|define
name|FIRE_DMCINT_ODCD_ERR_LOG_ADDR_SHFT
value|0
end_define

begin_comment
comment|/* JBC DMCINT IDC error log register */
end_comment

begin_define
define|#
directive|define
name|FIRE_DMCINT_IDC_ERR_DMC_CTAG_MASK
value|0x000000000fff0000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_DMCINT_IDC_ERR_DMC_CTAG_SHFT
value|16
end_define

begin_define
define|#
directive|define
name|FIRE_DMCINT_IDC_ERR_TRANSID_MASK
value|0x000000000000c000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_DMCINT_IDC_ERR_AGNTID_MASK
value|0x0000000000003c00ULL
end_define

begin_define
define|#
directive|define
name|FIRE_DMCINT_IDC_ERR_AGNTID_SHFT
value|10
end_define

begin_define
define|#
directive|define
name|FIRE_DMCINT_IDC_ERR_SRCID_MASK
value|0x00000000000003e0ULL
end_define

begin_define
define|#
directive|define
name|FIRE_DMCINT_IDC_ERR_SRCID_SHFT
value|5
end_define

begin_define
define|#
directive|define
name|FIRE_DMCINT_IDC_ERR_TARGID_MASK
value|0x000000000000001fULL
end_define

begin_define
define|#
directive|define
name|FIRE_DMCINT_IDC_ERRO_TARGID_SHFT
value|0
end_define

begin_comment
comment|/* JBC CSR error log register */
end_comment

begin_define
define|#
directive|define
name|FIRE_JBC_CSR_ERR_LOG_WR
value|0x0000040000000000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_CSR_ERR_LOG_BMASK_MASK
value|0x000003fffc000000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_CSR_ERR_LOG_BMASK_SHFT
value|26
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_CSR_ERR_LOG_ADDR_MASK
value|0x0000000003ffffffULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_CSR_ERR_LOG_ADDR_SHFT
value|0
end_define

begin_comment
comment|/* JBC core and block interrupt enable register */
end_comment

begin_define
define|#
directive|define
name|FIRE_JBC_CORE_BLOCK_INT_EN_JBC
value|0x8000000000000000ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_CORE_BLOCK_INT_EN_CSR
value|0x0000000000000008ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_CORE_BLOCK_INT_EN_MERGE
value|0x0000000000000004ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_CORE_BLOCK_INT_EN_JBCINT
value|0x0000000000000002ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_CORE_BLOCK_INT_EN_DMCINT
value|0x0000000000000001ULL
end_define

begin_comment
comment|/* JBC core and block error status register */
end_comment

begin_define
define|#
directive|define
name|FIRE_JBC_CORE_BLOCK_ERR_STAT_CSR
value|0x0000000000000008ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_CORE_BLOCK_ERR_STAT_MERGE
value|0x0000000000000004ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_CORE_BLOCK_ERR_STAT_JBCINT
value|0x0000000000000002ULL
end_define

begin_define
define|#
directive|define
name|FIRE_JBC_CORE_BLOCK_ERR_STAT_DMCINT
value|0x0000000000000001ULL
end_define

begin_comment
comment|/* JBC performance counter select register - may also apply to UBC */
end_comment

begin_define
define|#
directive|define
name|FO_XBC_PRF_CNT_PIO_RD_PCIEB
value|0x0000000000000018ULL
end_define

begin_define
define|#
directive|define
name|FO_XBC_PRF_CNT_PIO_WR_PCIEB
value|0x0000000000000017ULL
end_define

begin_define
define|#
directive|define
name|FO_XBC_PRF_CNT_PIO_RD_PCIEA
value|0x0000000000000016ULL
end_define

begin_define
define|#
directive|define
name|FO_XBC_PRF_CNT_PIO_WR_PCIEA
value|0x0000000000000015ULL
end_define

begin_define
define|#
directive|define
name|FO_XBC_PRF_CNT_WB
value|0x0000000000000014ULL
end_define

begin_define
define|#
directive|define
name|FO_XBC_PRF_CNT_PIO_FRGN
value|0x0000000000000013ULL
end_define

begin_define
define|#
directive|define
name|FO_XBC_PRF_CNT_XB_NCHRNT
value|0x0000000000000012ULL
end_define

begin_define
define|#
directive|define
name|FO_XBC_PRF_CNT_FO_CHRNT
value|0x0000000000000011ULL
end_define

begin_define
define|#
directive|define
name|FO_XBC_PRF_CNT_XB_CHRNT
value|0x0000000000000010ULL
end_define

begin_define
define|#
directive|define
name|FO_XBC_PRF_CNT_AOKOFF_DOKOFF
value|0x000000000000000fULL
end_define

begin_define
define|#
directive|define
name|FO_XBC_PRF_CNT_DOKOFF
value|0x000000000000000eULL
end_define

begin_define
define|#
directive|define
name|FO_XBC_PRF_CNT_AOKOFF
value|0x000000000000000dULL
end_define

begin_define
define|#
directive|define
name|FO_XBC_PRF_CNT_RD_TOTAL
value|0x000000000000000cULL
end_define

begin_define
define|#
directive|define
name|FO_XBC_PRF_CNT_WR_TOTAL
value|0x000000000000000bULL
end_define

begin_define
define|#
directive|define
name|FO_XBC_PRF_CNT_WR_PARTIAL
value|0x000000000000000aULL
end_define

begin_define
define|#
directive|define
name|FO_XBC_PRF_CNT_PIOS_CSR_RINGB
value|0x0000000000000009ULL
end_define

begin_define
define|#
directive|define
name|FO_XBC_PRF_CNT_PIOS_CSR_RINGA
value|0x0000000000000008ULL
end_define

begin_define
define|#
directive|define
name|FO_XBC_PRF_CNT_PIOS_EBUS
value|0x0000000000000007ULL
end_define

begin_define
define|#
directive|define
name|FO_XBC_PRF_CNT_PIOS_I2C
value|0x0000000000000006ULL
end_define

begin_define
define|#
directive|define
name|FO_XBC_PRF_CNT_RD_LAT_SMPLS
value|0x0000000000000005ULL
end_define

begin_define
define|#
directive|define
name|FO_XBC_PRF_CNT_RD_LAT
value|0x0000000000000004ULL
end_define

begin_define
define|#
directive|define
name|FO_XBC_PRF_CNT_ON_XB
value|0x0000000000000003ULL
end_define

begin_define
define|#
directive|define
name|FO_XBC_PRF_CNT_XB_IDL
value|0x0000000000000002ULL
end_define

begin_define
define|#
directive|define
name|FO_XBC_PRF_CNT_XB_CLK
value|0x0000000000000001ULL
end_define

begin_define
define|#
directive|define
name|FO_XBC_PRF_CNT_NONE
value|0x0000000000000000ULL
end_define

begin_define
define|#
directive|define
name|FO_XBC_PRF_CNT_CNT1_SHFT
value|8
end_define

begin_define
define|#
directive|define
name|FO_XBC_PRF_CNT_CNT0_SHFT
value|0
end_define

begin_comment
comment|/* JBC performance counter 0/1 registers - may also apply to UBC */
end_comment

begin_define
define|#
directive|define
name|FO_XBC_PRF_CNT_MASK
value|0xffffffffffffffffULL
end_define

begin_define
define|#
directive|define
name|FO_XBC_PRF_CNT_SHFT
value|0
end_define

begin_comment
comment|/* Lookup tables */
end_comment

begin_decl_stmt
specifier|const
name|uint16_t
specifier|const
name|fire_freq_nak_tmr_thrs
index|[
literal|6
index|]
index|[
literal|4
index|]
init|=
block|{
block|{
literal|0x00ed
block|,
literal|0x049
block|,
literal|0x043
block|,
literal|0x030
block|}
block|,
block|{
literal|0x01a0
block|,
literal|0x076
block|,
literal|0x06b
block|,
literal|0x048
block|}
block|,
block|{
literal|0x022f
block|,
literal|0x09a
block|,
literal|0x056
block|,
literal|0x056
block|}
block|,
block|{
literal|0x042f
block|,
literal|0x11a
block|,
literal|0x096
block|,
literal|0x096
block|}
block|,
block|{
literal|0x082f
block|,
literal|0x21a
block|,
literal|0x116
block|,
literal|0x116
block|}
block|,
block|{
literal|0x102f
block|,
literal|0x41a
block|,
literal|0x216
block|,
literal|0x216
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|uint16_t
specifier|const
name|fire_rply_tmr_thrs
index|[
literal|6
index|]
index|[
literal|4
index|]
init|=
block|{
block|{
literal|0x0379
block|,
literal|0x112
block|,
literal|0x0fc
block|,
literal|0x0b4
block|}
block|,
block|{
literal|0x0618
block|,
literal|0x1BA
block|,
literal|0x192
block|,
literal|0x10e
block|}
block|,
block|{
literal|0x0831
block|,
literal|0x242
block|,
literal|0x143
block|,
literal|0x143
block|}
block|,
block|{
literal|0x0fb1
block|,
literal|0x422
block|,
literal|0x233
block|,
literal|0x233
block|}
block|,
block|{
literal|0x1eb0
block|,
literal|0x7e1
block|,
literal|0x412
block|,
literal|0x412
block|}
block|,
block|{
literal|0x3cb0
block|,
literal|0xf61
block|,
literal|0x7d2
block|,
literal|0x7d2
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Register default values */
end_comment

begin_define
define|#
directive|define
name|FO_PCI_TLU_CTRL_L0S_TIM_DFLT
value|0xda
end_define

begin_define
define|#
directive|define
name|FO_PCI_TLU_CTRL_CFG_DFLT
value|0x1
end_define

begin_define
define|#
directive|define
name|FO_PCI_LPU_LTSSM_CFG2_12_TO_DFLT
value|0x2dc6c0
end_define

begin_define
define|#
directive|define
name|FO_PCI_LPU_LTSSM_CFG3_2_TO_DFLT
value|0x7a120
end_define

begin_define
define|#
directive|define
name|FO_PCI_LPU_LTSSM_CFG4_DATA_RATE_DFLT
value|0x2
end_define

begin_define
define|#
directive|define
name|FO_PCI_LPU_LTSSM_CFG4_N_FTS_DFLT
value|0x8c
end_define

begin_define
define|#
directive|define
name|OBERON_PCI_LPU_TXLNK_RPLY_TMR_THRS_DFLT
value|0xc9
end_define

begin_define
define|#
directive|define
name|FO_PCI_LPU_TXLNK_RTR_FIFO_PTR_HD_DFLT
value|0x0
end_define

begin_define
define|#
directive|define
name|FO_PCI_LPU_TXLNK_RTR_FIFO_PTR_TL_DFLT
value|0xffff
end_define

begin_comment
comment|/* INO macros */
end_comment

begin_define
define|#
directive|define
name|FO_EQ_FIRST_INO
value|0x18
end_define

begin_define
define|#
directive|define
name|FO_EQ_LAST_INO
value|0x3b
end_define

begin_define
define|#
directive|define
name|FO_DMC_PEC_INO
value|0x3e
end_define

begin_define
define|#
directive|define
name|FO_XCB_INO
value|0x3f
end_define

begin_define
define|#
directive|define
name|FO_MAX_INO
value|FO_XCB_INO
end_define

begin_comment
comment|/* Device space macros */
end_comment

begin_define
define|#
directive|define
name|FO_CONF_BUS_SHFT
value|20
end_define

begin_define
define|#
directive|define
name|FO_CONF_DEV_SHFT
value|15
end_define

begin_define
define|#
directive|define
name|FO_CONF_FUNC_SHFT
value|12
end_define

begin_define
define|#
directive|define
name|FO_CONF_REG_SHFT
value|0
end_define

begin_define
define|#
directive|define
name|FO_IO_SIZE
value|0x10000000
end_define

begin_define
define|#
directive|define
name|FO_MEM_SIZE
value|0x1ffff0000
end_define

begin_define
define|#
directive|define
name|FO_CONF_OFF
parameter_list|(
name|bus
parameter_list|,
name|slot
parameter_list|,
name|func
parameter_list|,
name|reg
parameter_list|)
define|\
value|(((bus)<< FO_CONF_BUS_SHFT) |					\ 	((slot)<< FO_CONF_DEV_SHFT) |					\ 	((func)<< FO_CONF_FUNC_SHFT) |					\ 	((reg)<< FO_CONF_REG_SHFT))
end_define

begin_comment
comment|/* Width of the physical addresses the IOMMU translates to */
end_comment

begin_define
define|#
directive|define
name|FIRE_IOMMU_BITS
value|43
end_define

begin_define
define|#
directive|define
name|OBERON_IOMMU_BITS
value|47
end_define

begin_comment
comment|/* Event queue macros */
end_comment

begin_define
define|#
directive|define
name|FO_EQ_ALIGNMENT
value|(512 * 1024)
end_define

begin_define
define|#
directive|define
name|FO_EQ_NRECORDS
value|128
end_define

begin_define
define|#
directive|define
name|FO_EQ_RECORD_SIZE
value|64
end_define

begin_comment
comment|/* Event queue record format */
end_comment

begin_struct
struct|struct
name|fo_msiq_record
block|{
name|uint64_t
name|fomqr_word0
decl_stmt|;
name|uint64_t
name|fomqr_word1
decl_stmt|;
name|uint64_t
name|fomqr_reserved
index|[
literal|6
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FO_MQR_WORD0_FMT_TYPE_MASK
value|0x7f00000000000000ULL
end_define

begin_define
define|#
directive|define
name|FO_MQR_WORD0_FMT_TYPE_SHFT
value|56
end_define

begin_define
define|#
directive|define
name|FO_MQR_WORD0_FMT_TYPE_MSI64
value|0x7800000000000000ULL
end_define

begin_define
define|#
directive|define
name|FO_MQR_WORD0_FMT_TYPE_MSI32
value|0x5800000000000000ULL
end_define

begin_define
define|#
directive|define
name|FO_MQR_WORD0_FMT_TYPE_MSG
value|0x3000000000000000ULL
end_define

begin_define
define|#
directive|define
name|FO_MQR_WORD0_FMT_TYPE_MSG_ROUTE_MASK
value|0x0700000000000000ULL
end_define

begin_define
define|#
directive|define
name|FO_MQR_WORD0_FMT_TYPE_MSG_ROUTE_SHFT
value|56
end_define

begin_define
define|#
directive|define
name|FO_MQR_WORD0_LENGTH_MASK
value|0x00ffc00000000000ULL
end_define

begin_define
define|#
directive|define
name|FO_MQR_WORD0_LENGTH_SHFT
value|46
end_define

begin_define
define|#
directive|define
name|FO_MQR_WORD0_ADDR0_MASK
value|0x00003fff00000000ULL
end_define

begin_define
define|#
directive|define
name|FO_MQR_WORD0_ADDR0_SHFT
value|32
end_define

begin_define
define|#
directive|define
name|FO_MQR_WORD0_RID_MASK
value|0x00000000ffff0000ULL
end_define

begin_define
define|#
directive|define
name|FO_MQR_WORD0_RID_SHFT
value|16
end_define

begin_define
define|#
directive|define
name|FO_MQR_WORD0_DATA0_MASK
value|0x000000000000ffffULL
end_define

begin_define
define|#
directive|define
name|FO_MQR_WORD0_DATA0_SHFT
value|0
end_define

begin_define
define|#
directive|define
name|FO_MQR_WORD1_ADDR1_MASK
value|0xffffffffffff0000ULL
end_define

begin_define
define|#
directive|define
name|FO_MQR_WORD1_ADDR1_SHFT
value|16
end_define

begin_define
define|#
directive|define
name|FO_MQR_WORD1_DATA1_MASK
value|0x000000000000ffffULL
end_define

begin_define
define|#
directive|define
name|FO_MQR_WORD1_DATA1_SHFT
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SPARC64_PCI_FIREREG_H_ */
end_comment

end_unit

