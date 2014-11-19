begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2009, Pyun YongHyeon<yongari@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IF_ALCREG_H
end_ifndef

begin_define
define|#
directive|define
name|_IF_ALCREG_H
end_define

begin_comment
comment|/*  * Atheros Communucations, Inc. PCI vendor ID  */
end_comment

begin_define
define|#
directive|define
name|VENDORID_ATHEROS
value|0x1969
end_define

begin_comment
comment|/*  * Atheros AR813x/AR815x device ID  */
end_comment

begin_define
define|#
directive|define
name|DEVICEID_ATHEROS_AR8131
value|0x1063
end_define

begin_comment
comment|/* L1C */
end_comment

begin_define
define|#
directive|define
name|DEVICEID_ATHEROS_AR8132
value|0x1062
end_define

begin_comment
comment|/* L2C */
end_comment

begin_define
define|#
directive|define
name|DEVICEID_ATHEROS_AR8151
value|0x1073
end_define

begin_comment
comment|/* L1D V1.0 */
end_comment

begin_define
define|#
directive|define
name|DEVICEID_ATHEROS_AR8151_V2
value|0x1083
end_define

begin_comment
comment|/* L1D V2.0 */
end_comment

begin_define
define|#
directive|define
name|DEVICEID_ATHEROS_AR8152_B
value|0x2060
end_define

begin_comment
comment|/* L2C V1.1 */
end_comment

begin_define
define|#
directive|define
name|DEVICEID_ATHEROS_AR8152_B2
value|0x2062
end_define

begin_comment
comment|/* L2C V2.0 */
end_comment

begin_define
define|#
directive|define
name|DEVICEID_ATHEROS_AR8161
value|0x1091
end_define

begin_define
define|#
directive|define
name|DEVICEID_ATHEROS_E2200
value|0xE091
end_define

begin_define
define|#
directive|define
name|DEVICEID_ATHEROS_AR8162
value|0x1090
end_define

begin_define
define|#
directive|define
name|DEVICEID_ATHEROS_AR8171
value|0x10A1
end_define

begin_define
define|#
directive|define
name|DEVICEID_ATHEROS_AR8172
value|0x10A0
end_define

begin_define
define|#
directive|define
name|ATHEROS_AR8152_B_V10
value|0xC0
end_define

begin_define
define|#
directive|define
name|ATHEROS_AR8152_B_V11
value|0xC1
end_define

begin_comment
comment|/*  * Atheros AR816x/AR817x revisions  */
end_comment

begin_define
define|#
directive|define
name|AR816X_REV_A0
value|0
end_define

begin_define
define|#
directive|define
name|AR816X_REV_A1
value|1
end_define

begin_define
define|#
directive|define
name|AR816X_REV_B0
value|2
end_define

begin_define
define|#
directive|define
name|AR816X_REV_C0
value|3
end_define

begin_define
define|#
directive|define
name|AR816X_REV_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|AR816X_REV
parameter_list|(
name|x
parameter_list|)
value|((x)>> AR816X_REV_SHIFT)
end_define

begin_comment
comment|/* 0x0000 - 0x02FF : PCIe configuration space */
end_comment

begin_define
define|#
directive|define
name|ALC_PEX_UNC_ERR_SEV
value|0x10C
end_define

begin_define
define|#
directive|define
name|PEX_UNC_ERR_SEV_TRN
value|0x00000001
end_define

begin_define
define|#
directive|define
name|PEX_UNC_ERR_SEV_DLP
value|0x00000010
end_define

begin_define
define|#
directive|define
name|PEX_UNC_ERR_SEV_PSN_TLP
value|0x00001000
end_define

begin_define
define|#
directive|define
name|PEX_UNC_ERR_SEV_FCP
value|0x00002000
end_define

begin_define
define|#
directive|define
name|PEX_UNC_ERR_SEV_CPL_TO
value|0x00004000
end_define

begin_define
define|#
directive|define
name|PEX_UNC_ERR_SEV_CA
value|0x00008000
end_define

begin_define
define|#
directive|define
name|PEX_UNC_ERR_SEV_UC
value|0x00010000
end_define

begin_define
define|#
directive|define
name|PEX_UNC_ERR_SEV_ROV
value|0x00020000
end_define

begin_define
define|#
directive|define
name|PEX_UNC_ERR_SEV_MLFP
value|0x00040000
end_define

begin_define
define|#
directive|define
name|PEX_UNC_ERR_SEV_ECRC
value|0x00080000
end_define

begin_define
define|#
directive|define
name|PEX_UNC_ERR_SEV_UR
value|0x00100000
end_define

begin_define
define|#
directive|define
name|ALC_EEPROM_LD
value|0x204
end_define

begin_comment
comment|/* AR816x */
end_comment

begin_define
define|#
directive|define
name|EEPROM_LD_START
value|0x00000001
end_define

begin_define
define|#
directive|define
name|EEPROM_LD_IDLE
value|0x00000010
end_define

begin_define
define|#
directive|define
name|EEPROM_LD_DONE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|EEPROM_LD_PROGRESS
value|0x00000020
end_define

begin_define
define|#
directive|define
name|EEPROM_LD_EXIST
value|0x00000100
end_define

begin_define
define|#
directive|define
name|EEPROM_LD_EEPROM_EXIST
value|0x00000200
end_define

begin_define
define|#
directive|define
name|EEPROM_LD_FLASH_EXIST
value|0x00000400
end_define

begin_define
define|#
directive|define
name|EEPROM_LD_FLASH_END_ADDR_MASK
value|0x03FF0000
end_define

begin_define
define|#
directive|define
name|EEPROM_LD_FLASH_END_ADDR_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|ALC_TWSI_CFG
value|0x218
end_define

begin_define
define|#
directive|define
name|TWSI_CFG_SW_LD_START
value|0x00000800
end_define

begin_define
define|#
directive|define
name|TWSI_CFG_HW_LD_START
value|0x00001000
end_define

begin_define
define|#
directive|define
name|TWSI_CFG_LD_EXIST
value|0x00400000
end_define

begin_define
define|#
directive|define
name|ALC_SLD
value|0x218
end_define

begin_comment
comment|/* AR816x */
end_comment

begin_define
define|#
directive|define
name|SLD_START
value|0x00000800
end_define

begin_define
define|#
directive|define
name|SLD_PROGRESS
value|0x00001000
end_define

begin_define
define|#
directive|define
name|SLD_IDLE
value|0x00002000
end_define

begin_define
define|#
directive|define
name|SLD_SLVADDR_MASK
value|0x007F0000
end_define

begin_define
define|#
directive|define
name|SLD_EXIST
value|0x00800000
end_define

begin_define
define|#
directive|define
name|SLD_FREQ_MASK
value|0x03000000
end_define

begin_define
define|#
directive|define
name|SLD_FREQ_100K
value|0x00000000
end_define

begin_define
define|#
directive|define
name|SLD_FREQ_200K
value|0x01000000
end_define

begin_define
define|#
directive|define
name|SLD_FREQ_300K
value|0x02000000
end_define

begin_define
define|#
directive|define
name|SLD_FREQ_400K
value|0x03000000
end_define

begin_define
define|#
directive|define
name|ALC_PCIE_PHYMISC
value|0x1000
end_define

begin_define
define|#
directive|define
name|PCIE_PHYMISC_FORCE_RCV_DET
value|0x00000004
end_define

begin_define
define|#
directive|define
name|ALC_PCIE_PHYMISC2
value|0x1004
end_define

begin_define
define|#
directive|define
name|PCIE_PHYMISC2_SERDES_CDR_MASK
value|0x00030000
end_define

begin_define
define|#
directive|define
name|PCIE_PHYMISC2_SERDES_TH_MASK
value|0x000C0000
end_define

begin_define
define|#
directive|define
name|PCIE_PHYMISC2_SERDES_CDR_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|PCIE_PHYMISC2_SERDES_TH_SHIFT
value|18
end_define

begin_define
define|#
directive|define
name|ALC_PDLL_TRNS1
value|0x1104
end_define

begin_define
define|#
directive|define
name|PDLL_TRNS1_D3PLLOFF_ENB
value|0x00000800
end_define

begin_define
define|#
directive|define
name|ALC_TWSI_DEBUG
value|0x1108
end_define

begin_define
define|#
directive|define
name|TWSI_DEBUG_DEV_EXIST
value|0x20000000
end_define

begin_define
define|#
directive|define
name|ALC_EEPROM_CFG
value|0x12C0
end_define

begin_define
define|#
directive|define
name|EEPROM_CFG_DATA_HI_MASK
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|EEPROM_CFG_ADDR_MASK
value|0x03FF0000
end_define

begin_define
define|#
directive|define
name|EEPROM_CFG_ACK
value|0x40000000
end_define

begin_define
define|#
directive|define
name|EEPROM_CFG_RW
value|0x80000000
end_define

begin_define
define|#
directive|define
name|EEPROM_CFG_DATA_HI_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|EEPROM_CFG_ADDR_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|ALC_EEPROM_DATA_LO
value|0x12C4
end_define

begin_define
define|#
directive|define
name|ALC_OPT_CFG
value|0x12F0
end_define

begin_define
define|#
directive|define
name|OPT_CFG_CLK_ENB
value|0x00000002
end_define

begin_define
define|#
directive|define
name|ALC_PM_CFG
value|0x12F8
end_define

begin_define
define|#
directive|define
name|PM_CFG_SERDES_ENB
value|0x00000001
end_define

begin_define
define|#
directive|define
name|PM_CFG_RBER_ENB
value|0x00000002
end_define

begin_define
define|#
directive|define
name|PM_CFG_CLK_REQ_ENB
value|0x00000004
end_define

begin_define
define|#
directive|define
name|PM_CFG_ASPM_L1_ENB
value|0x00000008
end_define

begin_define
define|#
directive|define
name|PM_CFG_SERDES_L1_ENB
value|0x00000010
end_define

begin_define
define|#
directive|define
name|PM_CFG_SERDES_PLL_L1_ENB
value|0x00000020
end_define

begin_define
define|#
directive|define
name|PM_CFG_SERDES_PD_EX_L1
value|0x00000040
end_define

begin_define
define|#
directive|define
name|PM_CFG_SERDES_BUDS_RX_L1_ENB
value|0x00000080
end_define

begin_define
define|#
directive|define
name|PM_CFG_L0S_ENTRY_TIMER_MASK
value|0x00000F00
end_define

begin_define
define|#
directive|define
name|PM_CFG_RX_L1_AFTER_L0S
value|0x00000800
end_define

begin_define
define|#
directive|define
name|PM_CFG_ASPM_L0S_ENB
value|0x00001000
end_define

begin_define
define|#
directive|define
name|PM_CFG_CLK_SWH_L1
value|0x00002000
end_define

begin_define
define|#
directive|define
name|PM_CFG_CLK_PWM_VER1_1
value|0x00004000
end_define

begin_define
define|#
directive|define
name|PM_CFG_PCIE_RECV
value|0x00008000
end_define

begin_define
define|#
directive|define
name|PM_CFG_L1_ENTRY_TIMER_MASK
value|0x000F0000
end_define

begin_define
define|#
directive|define
name|PM_CFG_L1_ENTRY_TIMER_816X_MASK
value|0x00070000
end_define

begin_define
define|#
directive|define
name|PM_CFG_TX_L1_AFTER_L0S
value|0x00080000
end_define

begin_define
define|#
directive|define
name|PM_CFG_PM_REQ_TIMER_MASK
value|0x00F00000
end_define

begin_define
define|#
directive|define
name|PM_CFG_LCKDET_TIMER_MASK
value|0x0F000000
end_define

begin_define
define|#
directive|define
name|PM_CFG_EN_BUFS_RX_L0S
value|0x10000000
end_define

begin_define
define|#
directive|define
name|PM_CFG_SA_DLY_ENB
value|0x20000000
end_define

begin_define
define|#
directive|define
name|PM_CFG_MAC_ASPM_CHK
value|0x40000000
end_define

begin_define
define|#
directive|define
name|PM_CFG_HOTRST
value|0x80000000
end_define

begin_define
define|#
directive|define
name|PM_CFG_L0S_ENTRY_TIMER_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|PM_CFG_L1_ENTRY_TIMER_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|PM_CFG_PM_REQ_TIMER_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|PM_CFG_LCKDET_TIMER_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|PM_CFG_L0S_ENTRY_TIMER_DEFAULT
value|6
end_define

begin_define
define|#
directive|define
name|PM_CFG_L1_ENTRY_TIMER_DEFAULT
value|1
end_define

begin_define
define|#
directive|define
name|PM_CFG_L1_ENTRY_TIMER_816X_DEFAULT
value|4
end_define

begin_define
define|#
directive|define
name|PM_CFG_LCKDET_TIMER_DEFAULT
value|12
end_define

begin_define
define|#
directive|define
name|PM_CFG_PM_REQ_TIMER_DEFAULT
value|12
end_define

begin_define
define|#
directive|define
name|PM_CFG_PM_REQ_TIMER_816X_DEFAULT
value|15
end_define

begin_define
define|#
directive|define
name|ALC_LTSSM_ID_CFG
value|0x12FC
end_define

begin_define
define|#
directive|define
name|LTSSM_ID_WRO_ENB
value|0x00001000
end_define

begin_define
define|#
directive|define
name|ALC_MASTER_CFG
value|0x1400
end_define

begin_define
define|#
directive|define
name|MASTER_RESET
value|0x00000001
end_define

begin_define
define|#
directive|define
name|MASTER_TEST_MODE_MASK
value|0x0000000C
end_define

begin_define
define|#
directive|define
name|MASTER_BERT_START
value|0x00000010
end_define

begin_define
define|#
directive|define
name|MASTER_WAKEN_25M
value|0x00000020
end_define

begin_define
define|#
directive|define
name|MASTER_OOB_DIS_OFF
value|0x00000040
end_define

begin_define
define|#
directive|define
name|MASTER_SA_TIMER_ENB
value|0x00000080
end_define

begin_define
define|#
directive|define
name|MASTER_MTIMER_ENB
value|0x00000100
end_define

begin_define
define|#
directive|define
name|MASTER_MANUAL_INTR_ENB
value|0x00000200
end_define

begin_define
define|#
directive|define
name|MASTER_IM_TX_TIMER_ENB
value|0x00000400
end_define

begin_define
define|#
directive|define
name|MASTER_IM_RX_TIMER_ENB
value|0x00000800
end_define

begin_define
define|#
directive|define
name|MASTER_CLK_SEL_DIS
value|0x00001000
end_define

begin_define
define|#
directive|define
name|MASTER_CLK_SWH_MODE
value|0x00002000
end_define

begin_define
define|#
directive|define
name|MASTER_INTR_RD_CLR
value|0x00004000
end_define

begin_define
define|#
directive|define
name|MASTER_CHIP_REV_MASK
value|0x00FF0000
end_define

begin_define
define|#
directive|define
name|MASTER_CHIP_ID_MASK
value|0x7F000000
end_define

begin_define
define|#
directive|define
name|MASTER_OTP_SEL
value|0x80000000
end_define

begin_define
define|#
directive|define
name|MASTER_TEST_MODE_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|MASTER_CHIP_REV_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|MASTER_CHIP_ID_SHIFT
value|24
end_define

begin_comment
comment|/* Number of ticks per usec for AR813x/AR815x. */
end_comment

begin_define
define|#
directive|define
name|ALC_TICK_USECS
value|2
end_define

begin_define
define|#
directive|define
name|ALC_USECS
parameter_list|(
name|x
parameter_list|)
value|((x) / ALC_TICK_USECS)
end_define

begin_define
define|#
directive|define
name|ALC_MANUAL_TIMER
value|0x1404
end_define

begin_define
define|#
directive|define
name|ALC_IM_TIMER
value|0x1408
end_define

begin_define
define|#
directive|define
name|IM_TIMER_TX_MASK
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|IM_TIMER_RX_MASK
value|0xFFFF0000
end_define

begin_define
define|#
directive|define
name|IM_TIMER_TX_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|IM_TIMER_RX_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|ALC_IM_TIMER_MIN
value|0
end_define

begin_define
define|#
directive|define
name|ALC_IM_TIMER_MAX
value|130000
end_define

begin_comment
comment|/* 130ms */
end_comment

begin_comment
comment|/*  * 100us will ensure alc(4) wouldn't generate more than 10000 Rx  * interrupts in a second.  */
end_comment

begin_define
define|#
directive|define
name|ALC_IM_RX_TIMER_DEFAULT
value|100
end_define

begin_comment
comment|/* 100us */
end_comment

begin_comment
comment|/*  * alc(4) does not rely on Tx completion interrupts, so set it  * somewhat large value to reduce Tx completion interrupts.  */
end_comment

begin_define
define|#
directive|define
name|ALC_IM_TX_TIMER_DEFAULT
value|1000
end_define

begin_comment
comment|/* 1ms */
end_comment

begin_define
define|#
directive|define
name|ALC_GPHY_CFG
value|0x140C
end_define

begin_comment
comment|/* 16 bits, 32 bits on AR816x */
end_comment

begin_define
define|#
directive|define
name|GPHY_CFG_EXT_RESET
value|0x0001
end_define

begin_define
define|#
directive|define
name|GPHY_CFG_RTL_MODE
value|0x0002
end_define

begin_define
define|#
directive|define
name|GPHY_CFG_LED_MODE
value|0x0004
end_define

begin_define
define|#
directive|define
name|GPHY_CFG_ANEG_NOW
value|0x0008
end_define

begin_define
define|#
directive|define
name|GPHY_CFG_RECV_ANEG
value|0x0010
end_define

begin_define
define|#
directive|define
name|GPHY_CFG_GATE_25M_ENB
value|0x0020
end_define

begin_define
define|#
directive|define
name|GPHY_CFG_LPW_EXIT
value|0x0040
end_define

begin_define
define|#
directive|define
name|GPHY_CFG_PHY_IDDQ
value|0x0080
end_define

begin_define
define|#
directive|define
name|GPHY_CFG_PHY_IDDQ_DIS
value|0x0100
end_define

begin_define
define|#
directive|define
name|GPHY_CFG_PCLK_SEL_DIS
value|0x0200
end_define

begin_define
define|#
directive|define
name|GPHY_CFG_HIB_EN
value|0x0400
end_define

begin_define
define|#
directive|define
name|GPHY_CFG_HIB_PULSE
value|0x0800
end_define

begin_define
define|#
directive|define
name|GPHY_CFG_SEL_ANA_RESET
value|0x1000
end_define

begin_define
define|#
directive|define
name|GPHY_CFG_PHY_PLL_ON
value|0x2000
end_define

begin_define
define|#
directive|define
name|GPHY_CFG_PWDOWN_HW
value|0x4000
end_define

begin_define
define|#
directive|define
name|GPHY_CFG_PHY_PLL_BYPASS
value|0x8000
end_define

begin_define
define|#
directive|define
name|GPHY_CFG_100AB_ENB
value|0x00020000
end_define

begin_define
define|#
directive|define
name|ALC_IDLE_STATUS
value|0x1410
end_define

begin_define
define|#
directive|define
name|IDLE_STATUS_RXMAC
value|0x00000001
end_define

begin_define
define|#
directive|define
name|IDLE_STATUS_TXMAC
value|0x00000002
end_define

begin_define
define|#
directive|define
name|IDLE_STATUS_RXQ
value|0x00000004
end_define

begin_define
define|#
directive|define
name|IDLE_STATUS_TXQ
value|0x00000008
end_define

begin_define
define|#
directive|define
name|IDLE_STATUS_DMARD
value|0x00000010
end_define

begin_define
define|#
directive|define
name|IDLE_STATUS_DMAWR
value|0x00000020
end_define

begin_define
define|#
directive|define
name|IDLE_STATUS_SMB
value|0x00000040
end_define

begin_define
define|#
directive|define
name|IDLE_STATUS_CMB
value|0x00000080
end_define

begin_define
define|#
directive|define
name|ALC_MDIO
value|0x1414
end_define

begin_define
define|#
directive|define
name|MDIO_DATA_MASK
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|MDIO_REG_ADDR_MASK
value|0x001F0000
end_define

begin_define
define|#
directive|define
name|MDIO_OP_READ
value|0x00200000
end_define

begin_define
define|#
directive|define
name|MDIO_OP_WRITE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|MDIO_SUP_PREAMBLE
value|0x00400000
end_define

begin_define
define|#
directive|define
name|MDIO_OP_EXECUTE
value|0x00800000
end_define

begin_define
define|#
directive|define
name|MDIO_CLK_25_4
value|0x00000000
end_define

begin_define
define|#
directive|define
name|MDIO_CLK_25_6
value|0x02000000
end_define

begin_define
define|#
directive|define
name|MDIO_CLK_25_8
value|0x03000000
end_define

begin_define
define|#
directive|define
name|MDIO_CLK_25_10
value|0x04000000
end_define

begin_define
define|#
directive|define
name|MDIO_CLK_25_14
value|0x05000000
end_define

begin_define
define|#
directive|define
name|MDIO_CLK_25_20
value|0x06000000
end_define

begin_define
define|#
directive|define
name|MDIO_CLK_25_128
value|0x07000000
end_define

begin_define
define|#
directive|define
name|MDIO_OP_BUSY
value|0x08000000
end_define

begin_define
define|#
directive|define
name|MDIO_AP_ENB
value|0x10000000
end_define

begin_define
define|#
directive|define
name|MDIO_MODE_EXT
value|0x40000000
end_define

begin_define
define|#
directive|define
name|MDIO_DATA_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|MDIO_REG_ADDR_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|MDIO_REG_ADDR
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)<< MDIO_REG_ADDR_SHIFT)& MDIO_REG_ADDR_MASK)
end_define

begin_comment
comment|/* Default PHY address. */
end_comment

begin_define
define|#
directive|define
name|ALC_PHY_ADDR
value|0
end_define

begin_define
define|#
directive|define
name|ALC_PHY_STATUS
value|0x1418
end_define

begin_define
define|#
directive|define
name|PHY_STATUS_RECV_ENB
value|0x00000001
end_define

begin_define
define|#
directive|define
name|PHY_STATUS_GENERAL_MASK
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|PHY_STATUS_OE_PWSP_MASK
value|0x07FF0000
end_define

begin_define
define|#
directive|define
name|PHY_STATUS_LPW_STATE
value|0x80000000
end_define

begin_define
define|#
directive|define
name|PHY_STATIS_OE_PWSP_SHIFT
value|16
end_define

begin_comment
comment|/* Packet memory BIST. */
end_comment

begin_define
define|#
directive|define
name|ALC_BIST0
value|0x141C
end_define

begin_define
define|#
directive|define
name|BIST0_ENB
value|0x00000001
end_define

begin_define
define|#
directive|define
name|BIST0_SRAM_FAIL
value|0x00000002
end_define

begin_define
define|#
directive|define
name|BIST0_FUSE_FLAG
value|0x00000004
end_define

begin_comment
comment|/* PCIe retry buffer BIST. */
end_comment

begin_define
define|#
directive|define
name|ALC_BIST1
value|0x1420
end_define

begin_define
define|#
directive|define
name|BIST1_ENB
value|0x00000001
end_define

begin_define
define|#
directive|define
name|BIST1_SRAM_FAIL
value|0x00000002
end_define

begin_define
define|#
directive|define
name|BIST1_FUSE_FLAG
value|0x00000004
end_define

begin_define
define|#
directive|define
name|ALC_SERDES_LOCK
value|0x1424
end_define

begin_define
define|#
directive|define
name|SERDES_LOCK_DET
value|0x00000001
end_define

begin_define
define|#
directive|define
name|SERDES_LOCK_DET_ENB
value|0x00000002
end_define

begin_define
define|#
directive|define
name|SERDES_MAC_CLK_SLOWDOWN
value|0x00020000
end_define

begin_define
define|#
directive|define
name|SERDES_PHY_CLK_SLOWDOWN
value|0x00040000
end_define

begin_define
define|#
directive|define
name|ALC_LPI_CTL
value|0x1440
end_define

begin_define
define|#
directive|define
name|LPI_CTL_ENB
value|0x00000001
end_define

begin_define
define|#
directive|define
name|ALC_EXT_MDIO
value|0x1448
end_define

begin_define
define|#
directive|define
name|EXT_MDIO_REG_MASK
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|EXT_MDIO_DEVADDR_MASK
value|0x001F0000
end_define

begin_define
define|#
directive|define
name|EXT_MDIO_REG_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|EXT_MDIO_DEVADDR_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|EXT_MDIO_REG
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)<< EXT_MDIO_REG_SHIFT)& EXT_MDIO_REG_MASK)
end_define

begin_define
define|#
directive|define
name|EXT_MDIO_DEVADDR
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)<< EXT_MDIO_DEVADDR_SHIFT)& EXT_MDIO_DEVADDR_MASK)
end_define

begin_define
define|#
directive|define
name|ALC_IDLE_DECISN_TIMER
value|0x1474
end_define

begin_define
define|#
directive|define
name|IDLE_DECISN_TIMER_DEFAULT_1MS
value|0x400
end_define

begin_define
define|#
directive|define
name|ALC_MAC_CFG
value|0x1480
end_define

begin_define
define|#
directive|define
name|MAC_CFG_TX_ENB
value|0x00000001
end_define

begin_define
define|#
directive|define
name|MAC_CFG_RX_ENB
value|0x00000002
end_define

begin_define
define|#
directive|define
name|MAC_CFG_TX_FC
value|0x00000004
end_define

begin_define
define|#
directive|define
name|MAC_CFG_RX_FC
value|0x00000008
end_define

begin_define
define|#
directive|define
name|MAC_CFG_LOOP
value|0x00000010
end_define

begin_define
define|#
directive|define
name|MAC_CFG_FULL_DUPLEX
value|0x00000020
end_define

begin_define
define|#
directive|define
name|MAC_CFG_TX_CRC_ENB
value|0x00000040
end_define

begin_define
define|#
directive|define
name|MAC_CFG_TX_AUTO_PAD
value|0x00000080
end_define

begin_define
define|#
directive|define
name|MAC_CFG_TX_LENCHK
value|0x00000100
end_define

begin_define
define|#
directive|define
name|MAC_CFG_RX_JUMBO_ENB
value|0x00000200
end_define

begin_define
define|#
directive|define
name|MAC_CFG_PREAMBLE_MASK
value|0x00003C00
end_define

begin_define
define|#
directive|define
name|MAC_CFG_VLAN_TAG_STRIP
value|0x00004000
end_define

begin_define
define|#
directive|define
name|MAC_CFG_PROMISC
value|0x00008000
end_define

begin_define
define|#
directive|define
name|MAC_CFG_TX_PAUSE
value|0x00010000
end_define

begin_define
define|#
directive|define
name|MAC_CFG_SCNT
value|0x00020000
end_define

begin_define
define|#
directive|define
name|MAC_CFG_SYNC_RST_TX
value|0x00040000
end_define

begin_define
define|#
directive|define
name|MAC_CFG_SIM_RST_TX
value|0x00080000
end_define

begin_define
define|#
directive|define
name|MAC_CFG_SPEED_MASK
value|0x00300000
end_define

begin_define
define|#
directive|define
name|MAC_CFG_SPEED_10_100
value|0x00100000
end_define

begin_define
define|#
directive|define
name|MAC_CFG_SPEED_1000
value|0x00200000
end_define

begin_define
define|#
directive|define
name|MAC_CFG_DBG_TX_BACKOFF
value|0x00400000
end_define

begin_define
define|#
directive|define
name|MAC_CFG_TX_JUMBO_ENB
value|0x00800000
end_define

begin_define
define|#
directive|define
name|MAC_CFG_RXCSUM_ENB
value|0x01000000
end_define

begin_define
define|#
directive|define
name|MAC_CFG_ALLMULTI
value|0x02000000
end_define

begin_define
define|#
directive|define
name|MAC_CFG_BCAST
value|0x04000000
end_define

begin_define
define|#
directive|define
name|MAC_CFG_DBG
value|0x08000000
end_define

begin_define
define|#
directive|define
name|MAC_CFG_SINGLE_PAUSE_ENB
value|0x10000000
end_define

begin_define
define|#
directive|define
name|MAC_CFG_HASH_ALG_CRC32
value|0x20000000
end_define

begin_define
define|#
directive|define
name|MAC_CFG_SPEED_MODE_SW
value|0x40000000
end_define

begin_define
define|#
directive|define
name|MAC_CFG_FAST_PAUSE
value|0x80000000
end_define

begin_define
define|#
directive|define
name|MAC_CFG_PREAMBLE_SHIFT
value|10
end_define

begin_define
define|#
directive|define
name|MAC_CFG_PREAMBLE_DEFAULT
value|7
end_define

begin_define
define|#
directive|define
name|ALC_IPG_IFG_CFG
value|0x1484
end_define

begin_define
define|#
directive|define
name|IPG_IFG_IPGT_MASK
value|0x0000007F
end_define

begin_define
define|#
directive|define
name|IPG_IFG_MIFG_MASK
value|0x0000FF00
end_define

begin_define
define|#
directive|define
name|IPG_IFG_IPG1_MASK
value|0x007F0000
end_define

begin_define
define|#
directive|define
name|IPG_IFG_IPG2_MASK
value|0x7F000000
end_define

begin_define
define|#
directive|define
name|IPG_IFG_IPGT_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|IPG_IFG_IPGT_DEFAULT
value|0x60
end_define

begin_define
define|#
directive|define
name|IPG_IFG_MIFG_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|IPG_IFG_MIFG_DEFAULT
value|0x50
end_define

begin_define
define|#
directive|define
name|IPG_IFG_IPG1_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|IPG_IFG_IPG1_DEFAULT
value|0x40
end_define

begin_define
define|#
directive|define
name|IPG_IFG_IPG2_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|IPG_IFG_IPG2_DEFAULT
value|0x60
end_define

begin_comment
comment|/* Station address. */
end_comment

begin_define
define|#
directive|define
name|ALC_PAR0
value|0x1488
end_define

begin_define
define|#
directive|define
name|ALC_PAR1
value|0x148C
end_define

begin_comment
comment|/* 64bit multicast hash register. */
end_comment

begin_define
define|#
directive|define
name|ALC_MAR0
value|0x1490
end_define

begin_define
define|#
directive|define
name|ALC_MAR1
value|0x1494
end_define

begin_comment
comment|/* half-duplex parameter configuration. */
end_comment

begin_define
define|#
directive|define
name|ALC_HDPX_CFG
value|0x1498
end_define

begin_define
define|#
directive|define
name|HDPX_CFG_LCOL_MASK
value|0x000003FF
end_define

begin_define
define|#
directive|define
name|HDPX_CFG_RETRY_MASK
value|0x0000F000
end_define

begin_define
define|#
directive|define
name|HDPX_CFG_EXC_DEF_EN
value|0x00010000
end_define

begin_define
define|#
directive|define
name|HDPX_CFG_NO_BACK_C
value|0x00020000
end_define

begin_define
define|#
directive|define
name|HDPX_CFG_NO_BACK_P
value|0x00040000
end_define

begin_define
define|#
directive|define
name|HDPX_CFG_ABEBE
value|0x00080000
end_define

begin_define
define|#
directive|define
name|HDPX_CFG_ABEBT_MASK
value|0x00F00000
end_define

begin_define
define|#
directive|define
name|HDPX_CFG_JAMIPG_MASK
value|0x0F000000
end_define

begin_define
define|#
directive|define
name|HDPX_CFG_LCOL_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|HDPX_CFG_LCOL_DEFAULT
value|0x37
end_define

begin_define
define|#
directive|define
name|HDPX_CFG_RETRY_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|HDPX_CFG_RETRY_DEFAULT
value|0x0F
end_define

begin_define
define|#
directive|define
name|HDPX_CFG_ABEBT_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|HDPX_CFG_ABEBT_DEFAULT
value|0x0A
end_define

begin_define
define|#
directive|define
name|HDPX_CFG_JAMIPG_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|HDPX_CFG_JAMIPG_DEFAULT
value|0x07
end_define

begin_define
define|#
directive|define
name|ALC_FRAME_SIZE
value|0x149C
end_define

begin_define
define|#
directive|define
name|ALC_WOL_CFG
value|0x14A0
end_define

begin_define
define|#
directive|define
name|WOL_CFG_PATTERN
value|0x00000001
end_define

begin_define
define|#
directive|define
name|WOL_CFG_PATTERN_ENB
value|0x00000002
end_define

begin_define
define|#
directive|define
name|WOL_CFG_MAGIC
value|0x00000004
end_define

begin_define
define|#
directive|define
name|WOL_CFG_MAGIC_ENB
value|0x00000008
end_define

begin_define
define|#
directive|define
name|WOL_CFG_LINK_CHG
value|0x00000010
end_define

begin_define
define|#
directive|define
name|WOL_CFG_LINK_CHG_ENB
value|0x00000020
end_define

begin_define
define|#
directive|define
name|WOL_CFG_PATTERN_DET
value|0x00000100
end_define

begin_define
define|#
directive|define
name|WOL_CFG_MAGIC_DET
value|0x00000200
end_define

begin_define
define|#
directive|define
name|WOL_CFG_LINK_CHG_DET
value|0x00000400
end_define

begin_define
define|#
directive|define
name|WOL_CFG_CLK_SWITCH_ENB
value|0x00008000
end_define

begin_define
define|#
directive|define
name|WOL_CFG_PATTERN0
value|0x00010000
end_define

begin_define
define|#
directive|define
name|WOL_CFG_PATTERN1
value|0x00020000
end_define

begin_define
define|#
directive|define
name|WOL_CFG_PATTERN2
value|0x00040000
end_define

begin_define
define|#
directive|define
name|WOL_CFG_PATTERN3
value|0x00080000
end_define

begin_define
define|#
directive|define
name|WOL_CFG_PATTERN4
value|0x00100000
end_define

begin_define
define|#
directive|define
name|WOL_CFG_PATTERN5
value|0x00200000
end_define

begin_define
define|#
directive|define
name|WOL_CFG_PATTERN6
value|0x00400000
end_define

begin_comment
comment|/* WOL pattern length. */
end_comment

begin_define
define|#
directive|define
name|ALC_PATTERN_CFG0
value|0x14A4
end_define

begin_define
define|#
directive|define
name|PATTERN_CFG_0_LEN_MASK
value|0x0000007F
end_define

begin_define
define|#
directive|define
name|PATTERN_CFG_1_LEN_MASK
value|0x00007F00
end_define

begin_define
define|#
directive|define
name|PATTERN_CFG_2_LEN_MASK
value|0x007F0000
end_define

begin_define
define|#
directive|define
name|PATTERN_CFG_3_LEN_MASK
value|0x7F000000
end_define

begin_define
define|#
directive|define
name|ALC_PATTERN_CFG1
value|0x14A8
end_define

begin_define
define|#
directive|define
name|PATTERN_CFG_4_LEN_MASK
value|0x0000007F
end_define

begin_define
define|#
directive|define
name|PATTERN_CFG_5_LEN_MASK
value|0x00007F00
end_define

begin_define
define|#
directive|define
name|PATTERN_CFG_6_LEN_MASK
value|0x007F0000
end_define

begin_comment
comment|/* RSS */
end_comment

begin_define
define|#
directive|define
name|ALC_RSS_KEY0
value|0x14B0
end_define

begin_define
define|#
directive|define
name|ALC_RSS_KEY1
value|0x14B4
end_define

begin_define
define|#
directive|define
name|ALC_RSS_KEY2
value|0x14B8
end_define

begin_define
define|#
directive|define
name|ALC_RSS_KEY3
value|0x14BC
end_define

begin_define
define|#
directive|define
name|ALC_RSS_KEY4
value|0x14C0
end_define

begin_define
define|#
directive|define
name|ALC_RSS_KEY5
value|0x14C4
end_define

begin_define
define|#
directive|define
name|ALC_RSS_KEY6
value|0x14C8
end_define

begin_define
define|#
directive|define
name|ALC_RSS_KEY7
value|0x14CC
end_define

begin_define
define|#
directive|define
name|ALC_RSS_KEY8
value|0x14D0
end_define

begin_define
define|#
directive|define
name|ALC_RSS_KEY9
value|0x14D4
end_define

begin_define
define|#
directive|define
name|ALC_RSS_IDT_TABLE0
value|0x14E0
end_define

begin_define
define|#
directive|define
name|ALC_TD_PRI2_HEAD_ADDR_LO
value|0x14E0
end_define

begin_comment
comment|/* AR816x */
end_comment

begin_define
define|#
directive|define
name|ALC_RSS_IDT_TABLE1
value|0x14E4
end_define

begin_define
define|#
directive|define
name|ALC_TD_PRI3_HEAD_ADDR_LO
value|0x14E4
end_define

begin_comment
comment|/* AR816x */
end_comment

begin_define
define|#
directive|define
name|ALC_RSS_IDT_TABLE2
value|0x14E8
end_define

begin_define
define|#
directive|define
name|ALC_RSS_IDT_TABLE3
value|0x14EC
end_define

begin_define
define|#
directive|define
name|ALC_RSS_IDT_TABLE4
value|0x14F0
end_define

begin_define
define|#
directive|define
name|ALC_RSS_IDT_TABLE5
value|0x14F4
end_define

begin_define
define|#
directive|define
name|ALC_RSS_IDT_TABLE6
value|0x14F8
end_define

begin_define
define|#
directive|define
name|ALC_RSS_IDT_TABLE7
value|0x14FC
end_define

begin_define
define|#
directive|define
name|ALC_SRAM_RD0_ADDR
value|0x1500
end_define

begin_define
define|#
directive|define
name|ALC_SRAM_RD1_ADDR
value|0x1504
end_define

begin_define
define|#
directive|define
name|ALC_SRAM_RD2_ADDR
value|0x1508
end_define

begin_define
define|#
directive|define
name|ALC_SRAM_RD3_ADDR
value|0x150C
end_define

begin_define
define|#
directive|define
name|RD_HEAD_ADDR_MASK
value|0x000003FF
end_define

begin_define
define|#
directive|define
name|RD_TAIL_ADDR_MASK
value|0x03FF0000
end_define

begin_define
define|#
directive|define
name|RD_HEAD_ADDR_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|RD_TAIL_ADDR_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|ALC_RD_NIC_LEN0
value|0x1510
end_define

begin_comment
comment|/* 8 bytes unit */
end_comment

begin_define
define|#
directive|define
name|RD_NIC_LEN_MASK
value|0x000003FF
end_define

begin_define
define|#
directive|define
name|ALC_RD_NIC_LEN1
value|0x1514
end_define

begin_define
define|#
directive|define
name|ALC_SRAM_TD_ADDR
value|0x1518
end_define

begin_define
define|#
directive|define
name|TD_HEAD_ADDR_MASK
value|0x000003FF
end_define

begin_define
define|#
directive|define
name|TD_TAIL_ADDR_MASK
value|0x03FF0000
end_define

begin_define
define|#
directive|define
name|TD_HEAD_ADDR_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|TD_TAIL_ADDR_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|ALC_SRAM_TD_LEN
value|0x151C
end_define

begin_comment
comment|/* 8 bytes unit */
end_comment

begin_define
define|#
directive|define
name|SRAM_TD_LEN_MASK
value|0x000003FF
end_define

begin_define
define|#
directive|define
name|ALC_SRAM_RX_FIFO_ADDR
value|0x1520
end_define

begin_define
define|#
directive|define
name|ALC_SRAM_RX_FIFO_LEN
value|0x1524
end_define

begin_define
define|#
directive|define
name|SRAM_RX_FIFO_LEN_MASK
value|0x00000FFF
end_define

begin_define
define|#
directive|define
name|SRAM_RX_FIFO_LEN_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|ALC_SRAM_TX_FIFO_ADDR
value|0x1528
end_define

begin_define
define|#
directive|define
name|ALC_SRAM_TX_FIFO_LEN
value|0x152C
end_define

begin_define
define|#
directive|define
name|ALC_SRAM_TCPH_ADDR
value|0x1530
end_define

begin_define
define|#
directive|define
name|SRAM_TCPH_ADDR_MASK
value|0x00000FFF
end_define

begin_define
define|#
directive|define
name|SRAM_PATH_ADDR_MASK
value|0x0FFF0000
end_define

begin_define
define|#
directive|define
name|SRAM_TCPH_ADDR_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|SRAM_PKTH_ADDR_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|ALC_DMA_BLOCK
value|0x1534
end_define

begin_define
define|#
directive|define
name|DMA_BLOCK_LOAD
value|0x00000001
end_define

begin_define
define|#
directive|define
name|ALC_RX_BASE_ADDR_HI
value|0x1540
end_define

begin_define
define|#
directive|define
name|ALC_TX_BASE_ADDR_HI
value|0x1544
end_define

begin_define
define|#
directive|define
name|ALC_SMB_BASE_ADDR_HI
value|0x1548
end_define

begin_define
define|#
directive|define
name|ALC_SMB_BASE_ADDR_LO
value|0x154C
end_define

begin_define
define|#
directive|define
name|ALC_RD0_HEAD_ADDR_LO
value|0x1550
end_define

begin_define
define|#
directive|define
name|ALC_RD1_HEAD_ADDR_LO
value|0x1554
end_define

begin_define
define|#
directive|define
name|ALC_RD2_HEAD_ADDR_LO
value|0x1558
end_define

begin_define
define|#
directive|define
name|ALC_RD3_HEAD_ADDR_LO
value|0x155C
end_define

begin_define
define|#
directive|define
name|ALC_RD_RING_CNT
value|0x1560
end_define

begin_define
define|#
directive|define
name|RD_RING_CNT_MASK
value|0x00000FFF
end_define

begin_define
define|#
directive|define
name|RD_RING_CNT_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|ALC_RX_BUF_SIZE
value|0x1564
end_define

begin_define
define|#
directive|define
name|RX_BUF_SIZE_MASK
value|0x0000FFFF
end_define

begin_comment
comment|/*  * If larger buffer size than 1536 is specified the controller  * will be locked up. This is hardware limitation.  */
end_comment

begin_define
define|#
directive|define
name|RX_BUF_SIZE_MAX
value|1536
end_define

begin_define
define|#
directive|define
name|ALC_RRD0_HEAD_ADDR_LO
value|0x1568
end_define

begin_define
define|#
directive|define
name|ALC_RRD1_HEAD_ADDR_LO
value|0x156C
end_define

begin_define
define|#
directive|define
name|ALC_RRD2_HEAD_ADDR_LO
value|0x1570
end_define

begin_define
define|#
directive|define
name|ALC_RRD3_HEAD_ADDR_LO
value|0x1574
end_define

begin_define
define|#
directive|define
name|ALC_RRD_RING_CNT
value|0x1578
end_define

begin_define
define|#
directive|define
name|RRD_RING_CNT_MASK
value|0x00000FFF
end_define

begin_define
define|#
directive|define
name|RRD_RING_CNT_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|ALC_TDH_HEAD_ADDR_LO
value|0x157C
end_define

begin_define
define|#
directive|define
name|ALC_TD_PRI1_HEAD_ADDR_LO
value|0x157C
end_define

begin_comment
comment|/* AR816x */
end_comment

begin_define
define|#
directive|define
name|ALC_TDL_HEAD_ADDR_LO
value|0x1580
end_define

begin_define
define|#
directive|define
name|ALC_TD_PRI0_HEAD_ADDR_LO
value|0x1580
end_define

begin_comment
comment|/* AR816x */
end_comment

begin_define
define|#
directive|define
name|ALC_TD_RING_CNT
value|0x1584
end_define

begin_define
define|#
directive|define
name|TD_RING_CNT_MASK
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|TD_RING_CNT_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|ALC_CMB_BASE_ADDR_LO
value|0x1588
end_define

begin_define
define|#
directive|define
name|ALC_TXQ_CFG
value|0x1590
end_define

begin_define
define|#
directive|define
name|TXQ_CFG_TD_BURST_MASK
value|0x0000000F
end_define

begin_define
define|#
directive|define
name|TXQ_CFG_IP_OPTION_ENB
value|0x00000010
end_define

begin_define
define|#
directive|define
name|TXQ_CFG_ENB
value|0x00000020
end_define

begin_define
define|#
directive|define
name|TXQ_CFG_ENHANCED_MODE
value|0x00000040
end_define

begin_define
define|#
directive|define
name|TXQ_CFG_8023_ENB
value|0x00000080
end_define

begin_define
define|#
directive|define
name|TXQ_CFG_TX_FIFO_BURST_MASK
value|0xFFFF0000
end_define

begin_define
define|#
directive|define
name|TXQ_CFG_TD_BURST_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|TXQ_CFG_TD_BURST_DEFAULT
value|5
end_define

begin_define
define|#
directive|define
name|TXQ_CFG_TX_FIFO_BURST_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|ALC_TSO_OFFLOAD_THRESH
value|0x1594
end_define

begin_comment
comment|/* 8 bytes unit */
end_comment

begin_define
define|#
directive|define
name|TSO_OFFLOAD_THRESH_MASK
value|0x000007FF
end_define

begin_define
define|#
directive|define
name|TSO_OFFLOAD_ERRLGPKT_DROP_ENB
value|0x00000800
end_define

begin_define
define|#
directive|define
name|TSO_OFFLOAD_THRESH_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|TSO_OFFLOAD_THRESH_UNIT
value|8
end_define

begin_define
define|#
directive|define
name|TSO_OFFLOAD_THRESH_UNIT_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|ALC_TXF_WATER_MARK
value|0x1598
end_define

begin_comment
comment|/* 8 bytes unit */
end_comment

begin_define
define|#
directive|define
name|TXF_WATER_MARK_HI_MASK
value|0x00000FFF
end_define

begin_define
define|#
directive|define
name|TXF_WATER_MARK_LO_MASK
value|0x0FFF0000
end_define

begin_define
define|#
directive|define
name|TXF_WATER_MARK_BURST_ENB
value|0x80000000
end_define

begin_define
define|#
directive|define
name|TXF_WATER_MARK_LO_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|TXF_WATER_MARK_HI_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|ALC_THROUGHPUT_MON
value|0x159C
end_define

begin_define
define|#
directive|define
name|THROUGHPUT_MON_RATE_MASK
value|0x00000003
end_define

begin_define
define|#
directive|define
name|THROUGHPUT_MON_ENB
value|0x00000080
end_define

begin_define
define|#
directive|define
name|THROUGHPUT_MON_RATE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|ALC_RXQ_CFG
value|0x15A0
end_define

begin_define
define|#
directive|define
name|RXQ_CFG_ASPM_THROUGHPUT_LIMIT_MASK
value|0x00000003
end_define

begin_define
define|#
directive|define
name|RXQ_CFG_ASPM_THROUGHPUT_LIMIT_NONE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|RXQ_CFG_ASPM_THROUGHPUT_LIMIT_1M
value|0x00000001
end_define

begin_define
define|#
directive|define
name|RXQ_CFG_ASPM_THROUGHPUT_LIMIT_10M
value|0x00000002
end_define

begin_define
define|#
directive|define
name|RXQ_CFG_ASPM_THROUGHPUT_LIMIT_100M
value|0x00000003
end_define

begin_define
define|#
directive|define
name|RXQ_CFG_QUEUE1_ENB
value|0x00000010
end_define

begin_define
define|#
directive|define
name|RXQ_CFG_QUEUE2_ENB
value|0x00000020
end_define

begin_define
define|#
directive|define
name|RXQ_CFG_QUEUE3_ENB
value|0x00000040
end_define

begin_define
define|#
directive|define
name|RXQ_CFG_IPV6_CSUM_ENB
value|0x00000080
end_define

begin_define
define|#
directive|define
name|RXQ_CFG_RSS_HASH_TBL_LEN_MASK
value|0x0000FF00
end_define

begin_define
define|#
directive|define
name|RXQ_CFG_RSS_HASH_IPV4
value|0x00010000
end_define

begin_define
define|#
directive|define
name|RXQ_CFG_RSS_HASH_IPV4_TCP
value|0x00020000
end_define

begin_define
define|#
directive|define
name|RXQ_CFG_RSS_HASH_IPV6
value|0x00040000
end_define

begin_define
define|#
directive|define
name|RXQ_CFG_RSS_HASH_IPV6_TCP
value|0x00080000
end_define

begin_define
define|#
directive|define
name|RXQ_CFG_RD_BURST_MASK
value|0x03F00000
end_define

begin_define
define|#
directive|define
name|RXQ_CFG_RSS_MODE_DIS
value|0x00000000
end_define

begin_define
define|#
directive|define
name|RXQ_CFG_RSS_MODE_SQSINT
value|0x04000000
end_define

begin_define
define|#
directive|define
name|RXQ_CFG_RSS_MODE_MQUESINT
value|0x08000000
end_define

begin_define
define|#
directive|define
name|RXQ_CFG_RSS_MODE_MQUEMINT
value|0x0C000000
end_define

begin_define
define|#
directive|define
name|RXQ_CFG_NIP_QUEUE_SEL_TBL
value|0x10000000
end_define

begin_define
define|#
directive|define
name|RXQ_CFG_RSS_HASH_ENB
value|0x20000000
end_define

begin_define
define|#
directive|define
name|RXQ_CFG_CUT_THROUGH_ENB
value|0x40000000
end_define

begin_define
define|#
directive|define
name|RXQ_CFG_QUEUE0_ENB
value|0x80000000
end_define

begin_define
define|#
directive|define
name|RXQ_CFG_RSS_HASH_TBL_LEN_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|RXQ_CFG_RD_BURST_DEFAULT
value|8
end_define

begin_define
define|#
directive|define
name|RXQ_CFG_RD_BURST_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|RXQ_CFG_ENB
define|\
value|(RXQ_CFG_QUEUE0_ENB | RXQ_CFG_QUEUE1_ENB |	\ 	 RXQ_CFG_QUEUE2_ENB | RXQ_CFG_QUEUE3_ENB)
end_define

begin_comment
comment|/* AR816x specific bits */
end_comment

begin_define
define|#
directive|define
name|RXQ_CFG_816X_RSS_HASH_IPV4
value|0x00000004
end_define

begin_define
define|#
directive|define
name|RXQ_CFG_816X_RSS_HASH_IPV4_TCP
value|0x00000008
end_define

begin_define
define|#
directive|define
name|RXQ_CFG_816X_RSS_HASH_IPV6
value|0x00000010
end_define

begin_define
define|#
directive|define
name|RXQ_CFG_816X_RSS_HASH_IPV6_TCP
value|0x00000020
end_define

begin_define
define|#
directive|define
name|RXQ_CFG_816X_RSS_HASH_MASK
value|0x0000003C
end_define

begin_define
define|#
directive|define
name|RXQ_CFG_816X_IPV6_PARSE_ENB
value|0x00000080
end_define

begin_define
define|#
directive|define
name|RXQ_CFG_816X_IDT_TBL_SIZE_MASK
value|0x0001FF00
end_define

begin_define
define|#
directive|define
name|RXQ_CFG_816X_IDT_TBL_SIZE_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|RXQ_CFG_816X_IDT_TBL_SIZE_DEFAULT
value|0x100
end_define

begin_define
define|#
directive|define
name|ALC_RX_RD_FREE_THRESH
value|0x15A4
end_define

begin_comment
comment|/* 8 bytes unit. */
end_comment

begin_define
define|#
directive|define
name|RX_RD_FREE_THRESH_HI_MASK
value|0x0000003F
end_define

begin_define
define|#
directive|define
name|RX_RD_FREE_THRESH_LO_MASK
value|0x00000FC0
end_define

begin_define
define|#
directive|define
name|RX_RD_FREE_THRESH_HI_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|RX_RD_FREE_THRESH_LO_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|RX_RD_FREE_THRESH_HI_DEFAULT
value|16
end_define

begin_define
define|#
directive|define
name|RX_RD_FREE_THRESH_LO_DEFAULT
value|8
end_define

begin_define
define|#
directive|define
name|ALC_RX_FIFO_PAUSE_THRESH
value|0x15A8
end_define

begin_define
define|#
directive|define
name|RX_FIFO_PAUSE_THRESH_LO_MASK
value|0x00000FFF
end_define

begin_define
define|#
directive|define
name|RX_FIFO_PAUSE_THRESH_HI_MASK
value|0x0FFF0000
end_define

begin_define
define|#
directive|define
name|RX_FIFO_PAUSE_THRESH_LO_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|RX_FIFO_PAUSE_THRESH_HI_SHIFT
value|16
end_define

begin_comment
comment|/*  * Size = tx-packet(1522) + IPG(12) + SOF(8) + 64(Pause) + IPG(12) + SOF(8) +  *	  rx-packet(1522) + delay-of-link(64)  *	= 3212.  */
end_comment

begin_define
define|#
directive|define
name|RX_FIFO_PAUSE_816X_RSVD
value|3212
end_define

begin_define
define|#
directive|define
name|ALC_RD_DMA_CFG
value|0x15AC
end_define

begin_define
define|#
directive|define
name|RD_DMA_CFG_THRESH_MASK
value|0x00000FFF
end_define

begin_comment
comment|/* 8 bytes unit */
end_comment

begin_define
define|#
directive|define
name|RD_DMA_CFG_TIMER_MASK
value|0xFFFF0000
end_define

begin_define
define|#
directive|define
name|RD_DMA_CFG_THRESH_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|RD_DMA_CFG_TIMER_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|RD_DMA_CFG_THRESH_DEFAULT
value|0x100
end_define

begin_define
define|#
directive|define
name|RD_DMA_CFG_TIMER_DEFAULT
value|0
end_define

begin_define
define|#
directive|define
name|RD_DMA_CFG_TICK_USECS
value|8
end_define

begin_define
define|#
directive|define
name|ALC_RD_DMA_CFG_USECS
parameter_list|(
name|x
parameter_list|)
value|((x) / RD_DMA_CFG_TICK_USECS)
end_define

begin_define
define|#
directive|define
name|ALC_RSS_HASH_VALUE
value|0x15B0
end_define

begin_define
define|#
directive|define
name|ALC_RSS_HASH_FLAG
value|0x15B4
end_define

begin_define
define|#
directive|define
name|ALC_RSS_CPU
value|0x15B8
end_define

begin_define
define|#
directive|define
name|ALC_DMA_CFG
value|0x15C0
end_define

begin_define
define|#
directive|define
name|DMA_CFG_IN_ORDER
value|0x00000001
end_define

begin_define
define|#
directive|define
name|DMA_CFG_ENH_ORDER
value|0x00000002
end_define

begin_define
define|#
directive|define
name|DMA_CFG_OUT_ORDER
value|0x00000004
end_define

begin_define
define|#
directive|define
name|DMA_CFG_RCB_64
value|0x00000000
end_define

begin_define
define|#
directive|define
name|DMA_CFG_RCB_128
value|0x00000008
end_define

begin_define
define|#
directive|define
name|DMA_CFG_PEND_AUTO_RST
value|0x00000008
end_define

begin_define
define|#
directive|define
name|DMA_CFG_RD_BURST_128
value|0x00000000
end_define

begin_define
define|#
directive|define
name|DMA_CFG_RD_BURST_256
value|0x00000010
end_define

begin_define
define|#
directive|define
name|DMA_CFG_RD_BURST_512
value|0x00000020
end_define

begin_define
define|#
directive|define
name|DMA_CFG_RD_BURST_1024
value|0x00000030
end_define

begin_define
define|#
directive|define
name|DMA_CFG_RD_BURST_2048
value|0x00000040
end_define

begin_define
define|#
directive|define
name|DMA_CFG_RD_BURST_4096
value|0x00000050
end_define

begin_define
define|#
directive|define
name|DMA_CFG_WR_BURST_128
value|0x00000000
end_define

begin_define
define|#
directive|define
name|DMA_CFG_WR_BURST_256
value|0x00000080
end_define

begin_define
define|#
directive|define
name|DMA_CFG_WR_BURST_512
value|0x00000100
end_define

begin_define
define|#
directive|define
name|DMA_CFG_WR_BURST_1024
value|0x00000180
end_define

begin_define
define|#
directive|define
name|DMA_CFG_WR_BURST_2048
value|0x00000200
end_define

begin_define
define|#
directive|define
name|DMA_CFG_WR_BURST_4096
value|0x00000280
end_define

begin_define
define|#
directive|define
name|DMA_CFG_RD_REQ_PRI
value|0x00000400
end_define

begin_define
define|#
directive|define
name|DMA_CFG_RD_DELAY_CNT_MASK
value|0x0000F800
end_define

begin_define
define|#
directive|define
name|DMA_CFG_WR_DELAY_CNT_MASK
value|0x000F0000
end_define

begin_define
define|#
directive|define
name|DMA_CFG_CMB_ENB
value|0x00100000
end_define

begin_define
define|#
directive|define
name|DMA_CFG_SMB_ENB
value|0x00200000
end_define

begin_define
define|#
directive|define
name|DMA_CFG_CMB_NOW
value|0x00400000
end_define

begin_define
define|#
directive|define
name|DMA_CFG_SMB_DIS
value|0x01000000
end_define

begin_define
define|#
directive|define
name|DMA_CFG_RD_CHNL_SEL_MASK
value|0x0C000000
end_define

begin_define
define|#
directive|define
name|DMA_CFG_RD_CHNL_SEL_1
value|0x00000000
end_define

begin_define
define|#
directive|define
name|DMA_CFG_RD_CHNL_SEL_2
value|0x04000000
end_define

begin_define
define|#
directive|define
name|DMA_CFG_RD_CHNL_SEL_3
value|0x08000000
end_define

begin_define
define|#
directive|define
name|DMA_CFG_RD_CHNL_SEL_4
value|0x0C000000
end_define

begin_define
define|#
directive|define
name|DMA_CFG_WSRAM_RDCTL
value|0x10000000
end_define

begin_define
define|#
directive|define
name|DMA_CFG_RD_PEND_CLR
value|0x20000000
end_define

begin_define
define|#
directive|define
name|DMA_CFG_WR_PEND_CLR
value|0x40000000
end_define

begin_define
define|#
directive|define
name|DMA_CFG_SMB_NOW
value|0x80000000
end_define

begin_define
define|#
directive|define
name|DMA_CFG_RD_BURST_MASK
value|0x07
end_define

begin_define
define|#
directive|define
name|DMA_CFG_RD_BURST_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|DMA_CFG_WR_BURST_MASK
value|0x07
end_define

begin_define
define|#
directive|define
name|DMA_CFG_WR_BURST_SHIFT
value|7
end_define

begin_define
define|#
directive|define
name|DMA_CFG_RD_DELAY_CNT_SHIFT
value|11
end_define

begin_define
define|#
directive|define
name|DMA_CFG_WR_DELAY_CNT_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|DMA_CFG_RD_DELAY_CNT_DEFAULT
value|15
end_define

begin_define
define|#
directive|define
name|DMA_CFG_WR_DELAY_CNT_DEFAULT
value|4
end_define

begin_define
define|#
directive|define
name|ALC_SMB_STAT_TIMER
value|0x15C4
end_define

begin_define
define|#
directive|define
name|SMB_STAT_TIMER_MASK
value|0x00FFFFFF
end_define

begin_define
define|#
directive|define
name|SMB_STAT_TIMER_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|ALC_CMB_TD_THRESH
value|0x15C8
end_define

begin_define
define|#
directive|define
name|CMB_TD_THRESH_MASK
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|CMB_TD_THRESH_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|ALC_CMB_TX_TIMER
value|0x15CC
end_define

begin_define
define|#
directive|define
name|CMB_TX_TIMER_MASK
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|CMB_TX_TIMER_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|ALC_MSI_MAP_TBL1
value|0x15D0
end_define

begin_define
define|#
directive|define
name|ALC_MSI_ID_MAP
value|0x15D4
end_define

begin_define
define|#
directive|define
name|ALC_MSI_MAP_TBL2
value|0x15D8
end_define

begin_define
define|#
directive|define
name|ALC_MBOX_RD0_PROD_IDX
value|0x15E0
end_define

begin_define
define|#
directive|define
name|ALC_MBOX_RD1_PROD_IDX
value|0x15E4
end_define

begin_define
define|#
directive|define
name|ALC_MBOX_RD2_PROD_IDX
value|0x15E8
end_define

begin_define
define|#
directive|define
name|ALC_MBOX_RD3_PROD_IDX
value|0x15EC
end_define

begin_define
define|#
directive|define
name|ALC_MBOX_RD_PROD_MASK
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|MBOX_RD_PROD_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|ALC_MBOX_TD_PROD_IDX
value|0x15F0
end_define

begin_define
define|#
directive|define
name|MBOX_TD_PROD_HI_IDX_MASK
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|MBOX_TD_PROD_LO_IDX_MASK
value|0xFFFF0000
end_define

begin_define
define|#
directive|define
name|MBOX_TD_PROD_HI_IDX_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|MBOX_TD_PROD_LO_IDX_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|ALC_MBOX_TD_PRI1_PROD_IDX
value|0x15F0
end_define

begin_comment
comment|/* 16 bits AR816x */
end_comment

begin_define
define|#
directive|define
name|ALC_MBOX_TD_PRI0_PROD_IDX
value|0x15F2
end_define

begin_comment
comment|/* 16 bits AR816x */
end_comment

begin_define
define|#
directive|define
name|ALC_MBOX_TD_CONS_IDX
value|0x15F4
end_define

begin_define
define|#
directive|define
name|MBOX_TD_CONS_HI_IDX_MASK
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|MBOX_TD_CONS_LO_IDX_MASK
value|0xFFFF0000
end_define

begin_define
define|#
directive|define
name|MBOX_TD_CONS_HI_IDX_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|MBOX_TD_CONS_LO_IDX_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|ALC_MBOX_TD_PRI1_CONS_IDX
value|0x15F4
end_define

begin_comment
comment|/* 16 bits AR816x */
end_comment

begin_define
define|#
directive|define
name|ALC_MBOX_TD_PRI0_CONS_IDX
value|0x15F6
end_define

begin_comment
comment|/* 16 bits AR816x */
end_comment

begin_define
define|#
directive|define
name|ALC_MBOX_RD01_CONS_IDX
value|0x15F8
end_define

begin_define
define|#
directive|define
name|MBOX_RD0_CONS_IDX_MASK
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|MBOX_RD1_CONS_IDX_MASK
value|0xFFFF0000
end_define

begin_define
define|#
directive|define
name|MBOX_RD0_CONS_IDX_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|MBOX_RD1_CONS_IDX_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|ALC_MBOX_RD23_CONS_IDX
value|0x15FC
end_define

begin_define
define|#
directive|define
name|MBOX_RD2_CONS_IDX_MASK
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|MBOX_RD3_CONS_IDX_MASK
value|0xFFFF0000
end_define

begin_define
define|#
directive|define
name|MBOX_RD2_CONS_IDX_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|MBOX_RD3_CONS_IDX_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|ALC_INTR_STATUS
value|0x1600
end_define

begin_define
define|#
directive|define
name|INTR_SMB
value|0x00000001
end_define

begin_define
define|#
directive|define
name|INTR_TIMER
value|0x00000002
end_define

begin_define
define|#
directive|define
name|INTR_MANUAL_TIMER
value|0x00000004
end_define

begin_define
define|#
directive|define
name|INTR_RX_FIFO_OFLOW
value|0x00000008
end_define

begin_define
define|#
directive|define
name|INTR_RD0_UNDERRUN
value|0x00000010
end_define

begin_define
define|#
directive|define
name|INTR_RD1_UNDERRUN
value|0x00000020
end_define

begin_define
define|#
directive|define
name|INTR_RD2_UNDERRUN
value|0x00000040
end_define

begin_define
define|#
directive|define
name|INTR_RD3_UNDERRUN
value|0x00000080
end_define

begin_define
define|#
directive|define
name|INTR_TX_FIFO_UNDERRUN
value|0x00000100
end_define

begin_define
define|#
directive|define
name|INTR_DMA_RD_TO_RST
value|0x00000200
end_define

begin_define
define|#
directive|define
name|INTR_DMA_WR_TO_RST
value|0x00000400
end_define

begin_define
define|#
directive|define
name|INTR_TX_CREDIT
value|0x00000800
end_define

begin_define
define|#
directive|define
name|INTR_GPHY
value|0x00001000
end_define

begin_define
define|#
directive|define
name|INTR_GPHY_LOW_PW
value|0x00002000
end_define

begin_define
define|#
directive|define
name|INTR_TXQ_TO_RST
value|0x00004000
end_define

begin_define
define|#
directive|define
name|INTR_TX_PKT0
value|0x00008000
end_define

begin_define
define|#
directive|define
name|INTR_RX_PKT0
value|0x00010000
end_define

begin_define
define|#
directive|define
name|INTR_RX_PKT1
value|0x00020000
end_define

begin_define
define|#
directive|define
name|INTR_RX_PKT2
value|0x00040000
end_define

begin_define
define|#
directive|define
name|INTR_RX_PKT3
value|0x00080000
end_define

begin_define
define|#
directive|define
name|INTR_MAC_RX
value|0x00100000
end_define

begin_define
define|#
directive|define
name|INTR_MAC_TX
value|0x00200000
end_define

begin_define
define|#
directive|define
name|INTR_UNDERRUN
value|0x00400000
end_define

begin_define
define|#
directive|define
name|INTR_FRAME_ERROR
value|0x00800000
end_define

begin_define
define|#
directive|define
name|INTR_FRAME_OK
value|0x01000000
end_define

begin_define
define|#
directive|define
name|INTR_CSUM_ERROR
value|0x02000000
end_define

begin_define
define|#
directive|define
name|INTR_PHY_LINK_DOWN
value|0x04000000
end_define

begin_define
define|#
directive|define
name|INTR_DIS_INT
value|0x80000000
end_define

begin_comment
comment|/* INTR status for AR816x/AR817x  4 TX queues, 8 RX queues */
end_comment

begin_define
define|#
directive|define
name|INTR_TX_PKT1
value|0x00000020
end_define

begin_define
define|#
directive|define
name|INTR_TX_PKT2
value|0x00000040
end_define

begin_define
define|#
directive|define
name|INTR_TX_PKT3
value|0x00000080
end_define

begin_define
define|#
directive|define
name|INTR_RX_PKT4
value|0x08000000
end_define

begin_define
define|#
directive|define
name|INTR_RX_PKT5
value|0x10000000
end_define

begin_define
define|#
directive|define
name|INTR_RX_PKT6
value|0x20000000
end_define

begin_define
define|#
directive|define
name|INTR_RX_PKT7
value|0x40000000
end_define

begin_comment
comment|/* Interrupt Mask Register */
end_comment

begin_define
define|#
directive|define
name|ALC_INTR_MASK
value|0x1604
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|notyet
end_ifdef

begin_define
define|#
directive|define
name|INTR_RX_PKT
define|\
value|(INTR_RX_PKT0 | INTR_RX_PKT1 | INTR_RX_PKT2 |	\ 	 INTR_RX_PKT3)
end_define

begin_define
define|#
directive|define
name|INTR_RD_UNDERRUN
define|\
value|(INTR_RD0_UNDERRUN | INTR_RD1_UNDERRUN |	\ 	INTR_RD2_UNDERRUN | INTR_RD3_UNDERRUN)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|INTR_TX_PKT
value|INTR_TX_PKT0
end_define

begin_define
define|#
directive|define
name|INTR_RX_PKT
value|INTR_RX_PKT0
end_define

begin_define
define|#
directive|define
name|INTR_RD_UNDERRUN
value|INTR_RD0_UNDERRUN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ALC_INTRS
define|\
value|(INTR_DMA_RD_TO_RST | INTR_DMA_WR_TO_RST |	\ 	INTR_TXQ_TO_RST	| INTR_RX_PKT | INTR_TX_PKT |	\ 	INTR_RX_FIFO_OFLOW | INTR_RD_UNDERRUN |		\ 	INTR_TX_FIFO_UNDERRUN)
end_define

begin_define
define|#
directive|define
name|ALC_INTR_RETRIG_TIMER
value|0x1608
end_define

begin_define
define|#
directive|define
name|INTR_RETRIG_TIMER_MASK
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|INTR_RETRIG_TIMER_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|ALC_HDS_CFG
value|0x160C
end_define

begin_define
define|#
directive|define
name|HDS_CFG_ENB
value|0x00000001
end_define

begin_define
define|#
directive|define
name|HDS_CFG_BACKFILLSIZE_MASK
value|0x000FFF00
end_define

begin_define
define|#
directive|define
name|HDS_CFG_MAX_HDRSIZE_MASK
value|0xFFF00000
end_define

begin_define
define|#
directive|define
name|HDS_CFG_BACKFILLSIZE_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|HDS_CFG_MAX_HDRSIZE_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|ALC_MBOX_TD_PRI3_PROD_IDX
value|0x1618
end_define

begin_comment
comment|/* 16 bits AR816x */
end_comment

begin_define
define|#
directive|define
name|ALC_MBOX_TD_PRI2_PROD_IDX
value|0x161A
end_define

begin_comment
comment|/* 16 bits AR816x */
end_comment

begin_define
define|#
directive|define
name|ALC_MBOX_TD_PRI3_CONS_IDX
value|0x161C
end_define

begin_comment
comment|/* 16 bits AR816x */
end_comment

begin_define
define|#
directive|define
name|ALC_MBOX_TD_PRI2_CONS_IDX
value|0x161E
end_define

begin_comment
comment|/* 16 bits AR816x */
end_comment

begin_comment
comment|/* AR813x/AR815x registers for MAC statistics */
end_comment

begin_define
define|#
directive|define
name|ALC_RX_MIB_BASE
value|0x1700
end_define

begin_define
define|#
directive|define
name|ALC_TX_MIB_BASE
value|0x1760
end_define

begin_define
define|#
directive|define
name|ALC_DRV
value|0x1804
end_define

begin_comment
comment|/* AR816x */
end_comment

begin_define
define|#
directive|define
name|DRV_ASPM_SPD10LMT_1M
value|0x00000000
end_define

begin_define
define|#
directive|define
name|DRV_ASPM_SPD10LMT_10M
value|0x00000001
end_define

begin_define
define|#
directive|define
name|DRV_ASPM_SPD10LMT_100M
value|0x00000002
end_define

begin_define
define|#
directive|define
name|DRV_ASPM_SPD10LMT_NO
value|0x00000003
end_define

begin_define
define|#
directive|define
name|DRV_ASPM_SPD10LMT_MASK
value|0x00000003
end_define

begin_define
define|#
directive|define
name|DRV_ASPM_SPD100LMT_1M
value|0x00000000
end_define

begin_define
define|#
directive|define
name|DRV_ASPM_SPD100LMT_10M
value|0x00000004
end_define

begin_define
define|#
directive|define
name|DRV_ASPM_SPD100LMT_100M
value|0x00000008
end_define

begin_define
define|#
directive|define
name|DRV_ASPM_SPD100LMT_NO
value|0x0000000C
end_define

begin_define
define|#
directive|define
name|DRV_ASPM_SPD100LMT_MASK
value|0x0000000C
end_define

begin_define
define|#
directive|define
name|DRV_ASPM_SPD1000LMT_100M
value|0x00000000
end_define

begin_define
define|#
directive|define
name|DRV_ASPM_SPD1000LMT_NO
value|0x00000010
end_define

begin_define
define|#
directive|define
name|DRV_ASPM_SPD1000LMT_1M
value|0x00000020
end_define

begin_define
define|#
directive|define
name|DRV_ASPM_SPD1000LMT_10M
value|0x00000030
end_define

begin_define
define|#
directive|define
name|DRV_ASPM_SPD1000LMT_MASK
value|0x00000000
end_define

begin_define
define|#
directive|define
name|DRV_WOLCAP_BIOS_EN
value|0x00000100
end_define

begin_define
define|#
directive|define
name|DRV_WOLMAGIC_EN
value|0x00000200
end_define

begin_define
define|#
directive|define
name|DRV_WOLLINKUP_EN
value|0x00000400
end_define

begin_define
define|#
directive|define
name|DRV_WOLPATTERN_EN
value|0x00000800
end_define

begin_define
define|#
directive|define
name|DRV_AZ_EN
value|0x00001000
end_define

begin_define
define|#
directive|define
name|DRV_WOLS5_BIOS_EN
value|0x00010000
end_define

begin_define
define|#
directive|define
name|DRV_WOLS5_EN
value|0x00020000
end_define

begin_define
define|#
directive|define
name|DRV_DISABLE
value|0x00040000
end_define

begin_define
define|#
directive|define
name|DRV_PHY_MASK
value|0x1FE00000
end_define

begin_define
define|#
directive|define
name|DRV_PHY_EEE
value|0x00200000
end_define

begin_define
define|#
directive|define
name|DRV_PHY_APAUSE
value|0x00400000
end_define

begin_define
define|#
directive|define
name|DRV_PHY_PAUSE
value|0x00800000
end_define

begin_define
define|#
directive|define
name|DRV_PHY_DUPLEX
value|0x01000000
end_define

begin_define
define|#
directive|define
name|DRV_PHY_10
value|0x02000000
end_define

begin_define
define|#
directive|define
name|DRV_PHY_100
value|0x04000000
end_define

begin_define
define|#
directive|define
name|DRV_PHY_1000
value|0x08000000
end_define

begin_define
define|#
directive|define
name|DRV_PHY_AUTO
value|0x10000000
end_define

begin_define
define|#
directive|define
name|DRV_PHY_SHIFT
value|21
end_define

begin_define
define|#
directive|define
name|ALC_CLK_GATING_CFG
value|0x1814
end_define

begin_define
define|#
directive|define
name|CLK_GATING_DMAW_ENB
value|0x0001
end_define

begin_define
define|#
directive|define
name|CLK_GATING_DMAR_ENB
value|0x0002
end_define

begin_define
define|#
directive|define
name|CLK_GATING_TXQ_ENB
value|0x0004
end_define

begin_define
define|#
directive|define
name|CLK_GATING_RXQ_ENB
value|0x0008
end_define

begin_define
define|#
directive|define
name|CLK_GATING_TXMAC_ENB
value|0x0010
end_define

begin_define
define|#
directive|define
name|CLK_GATING_RXMAC_ENB
value|0x0020
end_define

begin_define
define|#
directive|define
name|ALC_DEBUG_DATA0
value|0x1900
end_define

begin_define
define|#
directive|define
name|ALC_DEBUG_DATA1
value|0x1904
end_define

begin_define
define|#
directive|define
name|ALC_MSI_RETRANS_TIMER
value|0x1920
end_define

begin_define
define|#
directive|define
name|MSI_RETRANS_TIMER_MASK
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|MSI_RETRANS_MASK_SEL_STD
value|0x00000000
end_define

begin_define
define|#
directive|define
name|MSI_RETRANS_MASK_SEL_LINE
value|0x00010000
end_define

begin_define
define|#
directive|define
name|MSI_RETRANS_TIMER_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|ALC_WRR
value|0x1938
end_define

begin_define
define|#
directive|define
name|WRR_PRI0_MASK
value|0x0000001F
end_define

begin_define
define|#
directive|define
name|WRR_PRI1_MASK
value|0x00001F00
end_define

begin_define
define|#
directive|define
name|WRR_PRI2_MASK
value|0x001F0000
end_define

begin_define
define|#
directive|define
name|WRR_PRI3_MASK
value|0x1F000000
end_define

begin_define
define|#
directive|define
name|WRR_PRI_RESTRICT_MASK
value|0x60000000
end_define

begin_define
define|#
directive|define
name|WRR_PRI_RESTRICT_ALL
value|0x00000000
end_define

begin_define
define|#
directive|define
name|WRR_PRI_RESTRICT_HI
value|0x20000000
end_define

begin_define
define|#
directive|define
name|WRR_PRI_RESTRICT_HI2
value|0x40000000
end_define

begin_define
define|#
directive|define
name|WRR_PRI_RESTRICT_NONE
value|0x60000000
end_define

begin_define
define|#
directive|define
name|WRR_PRI0_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|WRR_PRI1_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|WRR_PRI2_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|WRR_PRI3_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|WRR_PRI_DEFAULT
value|4
end_define

begin_define
define|#
directive|define
name|WRR_PRI_RESTRICT_SHIFT
value|29
end_define

begin_define
define|#
directive|define
name|ALC_HQTD_CFG
value|0x193C
end_define

begin_define
define|#
directive|define
name|HQTD_CFG_Q1_BURST_MASK
value|0x0000000F
end_define

begin_define
define|#
directive|define
name|HQTD_CFG_Q2_BURST_MASK
value|0x000000F0
end_define

begin_define
define|#
directive|define
name|HQTD_CFG_Q3_BURST_MASK
value|0x00000F00
end_define

begin_define
define|#
directive|define
name|HQTD_CFG_BURST_ENB
value|0x80000000
end_define

begin_define
define|#
directive|define
name|HQTD_CFG_Q1_BURST_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|HQTD_CFG_Q2_BURST_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|HQTD_CFG_Q3_BURST_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|ALC_MISC
value|0x19C0
end_define

begin_define
define|#
directive|define
name|MISC_INTNLOSC_OPEN
value|0x00000008
end_define

begin_define
define|#
directive|define
name|MISC_ISO_ENB
value|0x00001000
end_define

begin_define
define|#
directive|define
name|MISC_PSW_OCP_MASK
value|0x00E00000
end_define

begin_define
define|#
directive|define
name|MISC_PSW_OCP_SHIFT
value|21
end_define

begin_define
define|#
directive|define
name|MISC_PSW_OCP_DEFAULT
value|7
end_define

begin_define
define|#
directive|define
name|ALC_MISC2
value|0x19C8
end_define

begin_define
define|#
directive|define
name|MISC2_CALB_START
value|0x00000001
end_define

begin_define
define|#
directive|define
name|ALC_MISC3
value|0x19CC
end_define

begin_define
define|#
directive|define
name|MISC3_25M_NOTO_INTNL
value|0x00000001
end_define

begin_define
define|#
directive|define
name|MISC3_25M_BY_SW
value|0x00000002
end_define

begin_define
define|#
directive|define
name|ALC_MII_DBG_ADDR
value|0x1D
end_define

begin_define
define|#
directive|define
name|ALC_MII_DBG_DATA
value|0x1E
end_define

begin_define
define|#
directive|define
name|MII_ANA_CFG0
value|0x00
end_define

begin_define
define|#
directive|define
name|ANA_RESTART_CAL
value|0x0001
end_define

begin_define
define|#
directive|define
name|ANA_MANUL_SWICH_ON_MASK
value|0x001E
end_define

begin_define
define|#
directive|define
name|ANA_MAN_ENABLE
value|0x0020
end_define

begin_define
define|#
directive|define
name|ANA_SEL_HSP
value|0x0040
end_define

begin_define
define|#
directive|define
name|ANA_EN_HB
value|0x0080
end_define

begin_define
define|#
directive|define
name|ANA_EN_HBIAS
value|0x0100
end_define

begin_define
define|#
directive|define
name|ANA_OEN_125M
value|0x0200
end_define

begin_define
define|#
directive|define
name|ANA_EN_LCKDT
value|0x0400
end_define

begin_define
define|#
directive|define
name|ANA_LCKDT_PHY
value|0x0800
end_define

begin_define
define|#
directive|define
name|ANA_AFE_MODE
value|0x1000
end_define

begin_define
define|#
directive|define
name|ANA_VCO_SLOW
value|0x2000
end_define

begin_define
define|#
directive|define
name|ANA_VCO_FAST
value|0x4000
end_define

begin_define
define|#
directive|define
name|ANA_SEL_CLK125M_DSP
value|0x8000
end_define

begin_define
define|#
directive|define
name|ANA_MANUL_SWICH_ON_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|MII_DBG_ANACTL
value|0x00
end_define

begin_define
define|#
directive|define
name|DBG_ANACTL_DEFAULT
value|0x02EF
end_define

begin_define
define|#
directive|define
name|MII_ANA_CFG4
value|0x04
end_define

begin_define
define|#
directive|define
name|ANA_IECHO_ADJ_MASK
value|0x0F
end_define

begin_define
define|#
directive|define
name|ANA_IECHO_ADJ_3_MASK
value|0x000F
end_define

begin_define
define|#
directive|define
name|ANA_IECHO_ADJ_2_MASK
value|0x00F0
end_define

begin_define
define|#
directive|define
name|ANA_IECHO_ADJ_1_MASK
value|0x0F00
end_define

begin_define
define|#
directive|define
name|ANA_IECHO_ADJ_0_MASK
value|0xF000
end_define

begin_define
define|#
directive|define
name|ANA_IECHO_ADJ_3_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|ANA_IECHO_ADJ_2_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|ANA_IECHO_ADJ_1_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|ANA_IECHO_ADJ_0_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|MII_DBG_SYSMODCTL
value|0x04
end_define

begin_define
define|#
directive|define
name|DBG_SYSMODCTL_DEFAULT
value|0xBB8B
end_define

begin_define
define|#
directive|define
name|MII_ANA_CFG5
value|0x05
end_define

begin_define
define|#
directive|define
name|ANA_SERDES_CDR_BW_MASK
value|0x0003
end_define

begin_define
define|#
directive|define
name|ANA_MS_PAD_DBG
value|0x0004
end_define

begin_define
define|#
directive|define
name|ANA_SPEEDUP_DBG
value|0x0008
end_define

begin_define
define|#
directive|define
name|ANA_SERDES_TH_LOS_MASK
value|0x0030
end_define

begin_define
define|#
directive|define
name|ANA_SERDES_EN_DEEM
value|0x0040
end_define

begin_define
define|#
directive|define
name|ANA_SERDES_TXELECIDLE
value|0x0080
end_define

begin_define
define|#
directive|define
name|ANA_SERDES_BEACON
value|0x0100
end_define

begin_define
define|#
directive|define
name|ANA_SERDES_HALFTXDR
value|0x0200
end_define

begin_define
define|#
directive|define
name|ANA_SERDES_SEL_HSP
value|0x0400
end_define

begin_define
define|#
directive|define
name|ANA_SERDES_EN_PLL
value|0x0800
end_define

begin_define
define|#
directive|define
name|ANA_SERDES_EN
value|0x1000
end_define

begin_define
define|#
directive|define
name|ANA_SERDES_EN_LCKDT
value|0x2000
end_define

begin_define
define|#
directive|define
name|ANA_SERDES_CDR_BW_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|ANA_SERDES_TH_LOS_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|MII_DBG_SRDSYSMOD
value|0x05
end_define

begin_define
define|#
directive|define
name|DBG_SRDSYSMOD_DEFAULT
value|0x2C46
end_define

begin_define
define|#
directive|define
name|MII_ANA_CFG11
value|0x0B
end_define

begin_define
define|#
directive|define
name|ANA_PS_HIB_EN
value|0x8000
end_define

begin_define
define|#
directive|define
name|MII_DBG_HIBNEG
value|0x0B
end_define

begin_define
define|#
directive|define
name|DBG_HIBNEG_HIB_PULSE
value|0x1000
end_define

begin_define
define|#
directive|define
name|DBG_HIBNEG_PSHIB_EN
value|0x8000
end_define

begin_define
define|#
directive|define
name|DBG_HIBNEG_DEFAULT
value|0xBC40
end_define

begin_define
define|#
directive|define
name|MII_ANA_CFG18
value|0x12
end_define

begin_define
define|#
directive|define
name|ANA_TEST_MODE_10BT_01MASK
value|0x0003
end_define

begin_define
define|#
directive|define
name|ANA_LOOP_SEL_10BT
value|0x0004
end_define

begin_define
define|#
directive|define
name|ANA_RGMII_MODE_SW
value|0x0008
end_define

begin_define
define|#
directive|define
name|ANA_EN_LONGECABLE
value|0x0010
end_define

begin_define
define|#
directive|define
name|ANA_TEST_MODE_10BT_2
value|0x0020
end_define

begin_define
define|#
directive|define
name|ANA_EN_10BT_IDLE
value|0x0400
end_define

begin_define
define|#
directive|define
name|ANA_EN_MASK_TB
value|0x0800
end_define

begin_define
define|#
directive|define
name|ANA_TRIGGER_SEL_TIMER_MASK
value|0x3000
end_define

begin_define
define|#
directive|define
name|ANA_INTERVAL_SEL_TIMER_MASK
value|0xC000
end_define

begin_define
define|#
directive|define
name|ANA_TEST_MODE_10BT_01SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|ANA_TRIGGER_SEL_TIMER_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|ANA_INTERVAL_SEL_TIMER_SHIFT
value|14
end_define

begin_define
define|#
directive|define
name|MII_DBG_TST10BTCFG
value|0x12
end_define

begin_define
define|#
directive|define
name|DBG_TST10BTCFG_DEFAULT
value|0x4C04
end_define

begin_define
define|#
directive|define
name|MII_DBG_AZ_ANADECT
value|0x15
end_define

begin_define
define|#
directive|define
name|DBG_AZ_ANADECT_DEFAULT
value|0x3220
end_define

begin_define
define|#
directive|define
name|DBG_AZ_ANADECT_LONG
value|0x3210
end_define

begin_define
define|#
directive|define
name|MII_DBG_MSE16DB
value|0x18
end_define

begin_define
define|#
directive|define
name|DBG_MSE16DB_UP
value|0x05EA
end_define

begin_define
define|#
directive|define
name|DBG_MSE16DB_DOWN
value|0x02EA
end_define

begin_define
define|#
directive|define
name|MII_DBG_MSE20DB
value|0x1C
end_define

begin_define
define|#
directive|define
name|DBG_MSE20DB_TH_MASK
value|0x01FC
end_define

begin_define
define|#
directive|define
name|DBG_MSE20DB_TH_DEFAULT
value|0x2E
end_define

begin_define
define|#
directive|define
name|DBG_MSE20DB_TH_HI
value|0x54
end_define

begin_define
define|#
directive|define
name|DBG_MSE20DB_TH_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|MII_DBG_AGC
value|0x23
end_define

begin_define
define|#
directive|define
name|DBG_AGC_2_VGA_MASK
value|0x3F00
end_define

begin_define
define|#
directive|define
name|DBG_AGC_2_VGA_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|DBG_AGC_LONG1G_LIMT
value|40
end_define

begin_define
define|#
directive|define
name|DBG_AGC_LONG100M_LIMT
value|44
end_define

begin_define
define|#
directive|define
name|MII_ANA_CFG41
value|0x29
end_define

begin_define
define|#
directive|define
name|ANA_TOP_PS_EN
value|0x8000
end_define

begin_define
define|#
directive|define
name|MII_DBG_LEGCYPS
value|0x29
end_define

begin_define
define|#
directive|define
name|DBG_LEGCYPS_ENB
value|0x8000
end_define

begin_define
define|#
directive|define
name|DBG_LEGCYPS_DEFAULT
value|0x129D
end_define

begin_define
define|#
directive|define
name|MII_ANA_CFG54
value|0x36
end_define

begin_define
define|#
directive|define
name|ANA_LONG_CABLE_TH_100_MASK
value|0x003F
end_define

begin_define
define|#
directive|define
name|ANA_DESERVED
value|0x0040
end_define

begin_define
define|#
directive|define
name|ANA_EN_LIT_CH
value|0x0080
end_define

begin_define
define|#
directive|define
name|ANA_SHORT_CABLE_TH_100_MASK
value|0x3F00
end_define

begin_define
define|#
directive|define
name|ANA_BP_BAD_LINK_ACCUM
value|0x4000
end_define

begin_define
define|#
directive|define
name|ANA_BP_SMALL_BW
value|0x8000
end_define

begin_define
define|#
directive|define
name|ANA_LONG_CABLE_TH_100_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|ANA_SHORT_CABLE_TH_100_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|MII_DBG_TST100BTCFG
value|0x36
end_define

begin_define
define|#
directive|define
name|DBG_TST100BTCFG_DEFAULT
value|0xE12C
end_define

begin_define
define|#
directive|define
name|MII_DBG_GREENCFG
value|0x3B
end_define

begin_define
define|#
directive|define
name|DBG_GREENCFG_DEFAULT
value|0x7078
end_define

begin_define
define|#
directive|define
name|MII_DBG_GREENCFG2
value|0x3D
end_define

begin_define
define|#
directive|define
name|DBG_GREENCFG2_GATE_DFSE_EN
value|0x0080
end_define

begin_define
define|#
directive|define
name|DBG_GREENCFG2_BP_GREEN
value|0x8000
end_define

begin_comment
comment|/* Device addr 3 */
end_comment

begin_define
define|#
directive|define
name|MII_EXT_PCS
value|3
end_define

begin_define
define|#
directive|define
name|MII_EXT_CLDCTL3
value|0x8003
end_define

begin_define
define|#
directive|define
name|EXT_CLDCTL3_BP_CABLE1TH_DET_GT
value|0x8000
end_define

begin_define
define|#
directive|define
name|MII_EXT_CLDCTL5
value|0x8005
end_define

begin_define
define|#
directive|define
name|EXT_CLDCTL5_BP_VD_HLFBIAS
value|0x4000
end_define

begin_define
define|#
directive|define
name|MII_EXT_CLDCTL6
value|0x8006
end_define

begin_define
define|#
directive|define
name|EXT_CLDCTL6_CAB_LEN_MASK
value|0x00FF
end_define

begin_define
define|#
directive|define
name|EXT_CLDCTL6_CAB_LEN_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|EXT_CLDCTL6_CAB_LEN_SHORT1G
value|116
end_define

begin_define
define|#
directive|define
name|EXT_CLDCTL6_CAB_LEN_SHORT100M
value|152
end_define

begin_define
define|#
directive|define
name|MII_EXT_VDRVBIAS
value|0x8062
end_define

begin_define
define|#
directive|define
name|EXT_VDRVBIAS_DEFAULT
value|3
end_define

begin_comment
comment|/* Device addr 7 */
end_comment

begin_define
define|#
directive|define
name|MII_EXT_ANEG
value|7
end_define

begin_define
define|#
directive|define
name|MII_EXT_ANEG_LOCAL_EEEADV
value|0x3C
end_define

begin_define
define|#
directive|define
name|ANEG_LOCA_EEEADV_100BT
value|0x0002
end_define

begin_define
define|#
directive|define
name|ANEG_LOCA_EEEADV_1000BT
value|0x0004
end_define

begin_define
define|#
directive|define
name|MII_EXT_ANEG_AFE
value|0x801A
end_define

begin_define
define|#
directive|define
name|ANEG_AFEE_10BT_100M_TH
value|0x0040
end_define

begin_define
define|#
directive|define
name|MII_EXT_ANEG_S3DIG10
value|0x8023
end_define

begin_define
define|#
directive|define
name|ANEG_S3DIG10_SL
value|0x0001
end_define

begin_define
define|#
directive|define
name|ANEG_S3DIG10_DEFAULT
value|0
end_define

begin_define
define|#
directive|define
name|MII_EXT_ANEG_NLP78
value|0x8027
end_define

begin_define
define|#
directive|define
name|ANEG_NLP78_120M_DEFAULT
value|0x8A05
end_define

begin_comment
comment|/* Statistics counters collected by the MAC. */
end_comment

begin_struct
struct|struct
name|smb
block|{
comment|/* Rx stats. */
name|uint32_t
name|rx_frames
decl_stmt|;
name|uint32_t
name|rx_bcast_frames
decl_stmt|;
name|uint32_t
name|rx_mcast_frames
decl_stmt|;
name|uint32_t
name|rx_pause_frames
decl_stmt|;
name|uint32_t
name|rx_control_frames
decl_stmt|;
name|uint32_t
name|rx_crcerrs
decl_stmt|;
name|uint32_t
name|rx_lenerrs
decl_stmt|;
name|uint32_t
name|rx_bytes
decl_stmt|;
name|uint32_t
name|rx_runts
decl_stmt|;
name|uint32_t
name|rx_fragments
decl_stmt|;
name|uint32_t
name|rx_pkts_64
decl_stmt|;
name|uint32_t
name|rx_pkts_65_127
decl_stmt|;
name|uint32_t
name|rx_pkts_128_255
decl_stmt|;
name|uint32_t
name|rx_pkts_256_511
decl_stmt|;
name|uint32_t
name|rx_pkts_512_1023
decl_stmt|;
name|uint32_t
name|rx_pkts_1024_1518
decl_stmt|;
name|uint32_t
name|rx_pkts_1519_max
decl_stmt|;
name|uint32_t
name|rx_pkts_truncated
decl_stmt|;
name|uint32_t
name|rx_fifo_oflows
decl_stmt|;
name|uint32_t
name|rx_rrs_errs
decl_stmt|;
name|uint32_t
name|rx_alignerrs
decl_stmt|;
name|uint32_t
name|rx_bcast_bytes
decl_stmt|;
name|uint32_t
name|rx_mcast_bytes
decl_stmt|;
name|uint32_t
name|rx_pkts_filtered
decl_stmt|;
comment|/* Tx stats. */
name|uint32_t
name|tx_frames
decl_stmt|;
name|uint32_t
name|tx_bcast_frames
decl_stmt|;
name|uint32_t
name|tx_mcast_frames
decl_stmt|;
name|uint32_t
name|tx_pause_frames
decl_stmt|;
name|uint32_t
name|tx_excess_defer
decl_stmt|;
name|uint32_t
name|tx_control_frames
decl_stmt|;
name|uint32_t
name|tx_deferred
decl_stmt|;
name|uint32_t
name|tx_bytes
decl_stmt|;
name|uint32_t
name|tx_pkts_64
decl_stmt|;
name|uint32_t
name|tx_pkts_65_127
decl_stmt|;
name|uint32_t
name|tx_pkts_128_255
decl_stmt|;
name|uint32_t
name|tx_pkts_256_511
decl_stmt|;
name|uint32_t
name|tx_pkts_512_1023
decl_stmt|;
name|uint32_t
name|tx_pkts_1024_1518
decl_stmt|;
name|uint32_t
name|tx_pkts_1519_max
decl_stmt|;
name|uint32_t
name|tx_single_colls
decl_stmt|;
name|uint32_t
name|tx_multi_colls
decl_stmt|;
name|uint32_t
name|tx_late_colls
decl_stmt|;
name|uint32_t
name|tx_excess_colls
decl_stmt|;
name|uint32_t
name|tx_underrun
decl_stmt|;
name|uint32_t
name|tx_desc_underrun
decl_stmt|;
name|uint32_t
name|tx_lenerrs
decl_stmt|;
name|uint32_t
name|tx_pkts_truncated
decl_stmt|;
name|uint32_t
name|tx_bcast_bytes
decl_stmt|;
name|uint32_t
name|tx_mcast_bytes
decl_stmt|;
name|uint32_t
name|updated
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* CMB(Coalesing message block) */
end_comment

begin_struct
struct|struct
name|cmb
block|{
name|uint32_t
name|cons
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Rx free descriptor */
end_comment

begin_struct
struct|struct
name|rx_desc
block|{
name|uint64_t
name|addr
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Rx return descriptor */
end_comment

begin_struct
struct|struct
name|rx_rdesc
block|{
name|uint32_t
name|rdinfo
decl_stmt|;
define|#
directive|define
name|RRD_CSUM_MASK
value|0x0000FFFF
define|#
directive|define
name|RRD_RD_CNT_MASK
value|0x000F0000
define|#
directive|define
name|RRD_RD_IDX_MASK
value|0xFFF00000
define|#
directive|define
name|RRD_CSUM_SHIFT
value|0
define|#
directive|define
name|RRD_RD_CNT_SHIFT
value|16
define|#
directive|define
name|RRD_RD_IDX_SHIFT
value|20
define|#
directive|define
name|RRD_CSUM
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)& RRD_CSUM_MASK)>> RRD_CSUM_SHIFT)
define|#
directive|define
name|RRD_RD_CNT
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)& RRD_RD_CNT_MASK)>> RRD_RD_CNT_SHIFT)
define|#
directive|define
name|RRD_RD_IDX
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)& RRD_RD_IDX_MASK)>> RRD_RD_IDX_SHIFT)
name|uint32_t
name|rss
decl_stmt|;
name|uint32_t
name|vtag
decl_stmt|;
define|#
directive|define
name|RRD_VLAN_MASK
value|0x0000FFFF
define|#
directive|define
name|RRD_HEAD_LEN_MASK
value|0x00FF0000
define|#
directive|define
name|RRD_HDS_MASK
value|0x03000000
define|#
directive|define
name|RRD_HDS_NONE
value|0x00000000
define|#
directive|define
name|RRD_HDS_HEAD
value|0x01000000
define|#
directive|define
name|RRD_HDS_DATA
value|0x02000000
define|#
directive|define
name|RRD_CPU_MASK
value|0x0C000000
define|#
directive|define
name|RRD_HASH_FLAG_MASK
value|0xF0000000
define|#
directive|define
name|RRD_VLAN_SHIFT
value|0
define|#
directive|define
name|RRD_HEAD_LEN_SHIFT
value|16
define|#
directive|define
name|RRD_HDS_SHIFT
value|24
define|#
directive|define
name|RRD_CPU_SHIFT
value|26
define|#
directive|define
name|RRD_HASH_FLAG_SHIFT
value|28
define|#
directive|define
name|RRD_VLAN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)& RRD_VLAN_MASK)>> RRD_VLAN_SHIFT)
define|#
directive|define
name|RRD_HEAD_LEN
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)& RRD_HEAD_LEN_MASK)>> RRD_HEAD_LEN_SHIFT)
define|#
directive|define
name|RRD_CPU
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)& RRD_CPU_MASK)>> RRD_CPU_SHIFT)
name|uint32_t
name|status
decl_stmt|;
define|#
directive|define
name|RRD_LEN_MASK
value|0x00003FFF
define|#
directive|define
name|RRD_LEN_SHIFT
value|0
define|#
directive|define
name|RRD_TCP_UDPCSUM_NOK
value|0x00004000
define|#
directive|define
name|RRD_IPCSUM_NOK
value|0x00008000
define|#
directive|define
name|RRD_VLAN_TAG
value|0x00010000
define|#
directive|define
name|RRD_PROTO_MASK
value|0x000E0000
define|#
directive|define
name|RRD_PROTO_IPV4
value|0x00020000
define|#
directive|define
name|RRD_PROTO_IPV6
value|0x000C0000
define|#
directive|define
name|RRD_ERR_SUM
value|0x00100000
define|#
directive|define
name|RRD_ERR_CRC
value|0x00200000
define|#
directive|define
name|RRD_ERR_ALIGN
value|0x00400000
define|#
directive|define
name|RRD_ERR_TRUNC
value|0x00800000
define|#
directive|define
name|RRD_ERR_RUNT
value|0x01000000
define|#
directive|define
name|RRD_ERR_ICMP
value|0x02000000
define|#
directive|define
name|RRD_BCAST
value|0x04000000
define|#
directive|define
name|RRD_MCAST
value|0x08000000
define|#
directive|define
name|RRD_SNAP_LLC
value|0x10000000
define|#
directive|define
name|RRD_ETHER
value|0x00000000
define|#
directive|define
name|RRD_FIFO_FULL
value|0x20000000
define|#
directive|define
name|RRD_ERR_LENGTH
value|0x40000000
define|#
directive|define
name|RRD_VALID
value|0x80000000
define|#
directive|define
name|RRD_BYTES
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)& RRD_LEN_MASK)>> RRD_LEN_SHIFT)
define|#
directive|define
name|RRD_IPV4
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)& RRD_PROTO_MASK) == RRD_PROTO_IPV4)
block|}
struct|;
end_struct

begin_comment
comment|/* Tx descriptor */
end_comment

begin_struct
struct|struct
name|tx_desc
block|{
name|uint32_t
name|len
decl_stmt|;
define|#
directive|define
name|TD_BUFLEN_MASK
value|0x00003FFF
define|#
directive|define
name|TD_VLAN_MASK
value|0xFFFF0000
define|#
directive|define
name|TD_BUFLEN_SHIFT
value|0
define|#
directive|define
name|TX_BYTES
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)<< TD_BUFLEN_SHIFT)& TD_BUFLEN_MASK)
define|#
directive|define
name|TD_VLAN_SHIFT
value|16
name|uint32_t
name|flags
decl_stmt|;
define|#
directive|define
name|TD_L4HDR_OFFSET_MASK
value|0x000000FF
comment|/* byte unit */
define|#
directive|define
name|TD_TCPHDR_OFFSET_MASK
value|0x000000FF
comment|/* byte unit */
define|#
directive|define
name|TD_PLOAD_OFFSET_MASK
value|0x000000FF
comment|/* 2 bytes unit */
define|#
directive|define
name|TD_CUSTOM_CSUM
value|0x00000100
define|#
directive|define
name|TD_IPCSUM
value|0x00000200
define|#
directive|define
name|TD_TCPCSUM
value|0x00000400
define|#
directive|define
name|TD_UDPCSUM
value|0x00000800
define|#
directive|define
name|TD_TSO
value|0x00001000
define|#
directive|define
name|TD_TSO_DESCV1
value|0x00000000
define|#
directive|define
name|TD_TSO_DESCV2
value|0x00002000
define|#
directive|define
name|TD_CON_VLAN_TAG
value|0x00004000
define|#
directive|define
name|TD_INS_VLAN_TAG
value|0x00008000
define|#
directive|define
name|TD_IPV4_DESCV2
value|0x00010000
define|#
directive|define
name|TD_LLC_SNAP
value|0x00020000
define|#
directive|define
name|TD_ETHERNET
value|0x00000000
define|#
directive|define
name|TD_CUSTOM_CSUM_OFFSET_MASK
value|0x03FC0000
comment|/* 2 bytes unit */
define|#
directive|define
name|TD_CUSTOM_CSUM_EVEN_PAD
value|0x40000000
define|#
directive|define
name|TD_MSS_MASK
value|0x7FFC0000
define|#
directive|define
name|TD_EOP
value|0x80000000
define|#
directive|define
name|TD_L4HDR_OFFSET_SHIFT
value|0
define|#
directive|define
name|TD_TCPHDR_OFFSET_SHIFT
value|0
define|#
directive|define
name|TD_PLOAD_OFFSET_SHIFT
value|0
define|#
directive|define
name|TD_CUSTOM_CSUM_OFFSET_SHIFT
value|18
define|#
directive|define
name|TD_MSS_SHIFT
value|18
name|uint64_t
name|addr
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IF_ALCREG_H */
end_comment

end_unit

