begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************    Copyright (c) 2001-2014, Intel Corporation    All rights reserved.      Redistribution and use in source and binary forms, with or without    modification, are permitted provided that the following conditions are met:       1. Redistributions of source code must retain the above copyright notice,        this list of conditions and the following disclaimer.       2. Redistributions in binary form must reproduce the above copyright        notice, this list of conditions and the following disclaimer in the        documentation and/or other materials provided with the distribution.       3. Neither the name of the Intel Corporation nor the names of its        contributors may be used to endorse or promote products derived from        this software without specific prior written permission.      THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE    ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE    LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR    CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF    SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS    INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN    CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)    ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE   POSSIBILITY OF SUCH DAMAGE.  ******************************************************************************/
end_comment

begin_comment
comment|/*$FreeBSD$*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_E1000_ICH8LAN_H_
end_ifndef

begin_define
define|#
directive|define
name|_E1000_ICH8LAN_H_
end_define

begin_define
define|#
directive|define
name|ICH_FLASH_GFPREG
value|0x0000
end_define

begin_define
define|#
directive|define
name|ICH_FLASH_HSFSTS
value|0x0004
end_define

begin_define
define|#
directive|define
name|ICH_FLASH_HSFCTL
value|0x0006
end_define

begin_define
define|#
directive|define
name|ICH_FLASH_FADDR
value|0x0008
end_define

begin_define
define|#
directive|define
name|ICH_FLASH_FDATA0
value|0x0010
end_define

begin_comment
comment|/* Requires up to 10 seconds when MNG might be accessing part. */
end_comment

begin_define
define|#
directive|define
name|ICH_FLASH_READ_COMMAND_TIMEOUT
value|10000000
end_define

begin_define
define|#
directive|define
name|ICH_FLASH_WRITE_COMMAND_TIMEOUT
value|10000000
end_define

begin_define
define|#
directive|define
name|ICH_FLASH_ERASE_COMMAND_TIMEOUT
value|10000000
end_define

begin_define
define|#
directive|define
name|ICH_FLASH_LINEAR_ADDR_MASK
value|0x00FFFFFF
end_define

begin_define
define|#
directive|define
name|ICH_FLASH_CYCLE_REPEAT_COUNT
value|10
end_define

begin_define
define|#
directive|define
name|ICH_CYCLE_READ
value|0
end_define

begin_define
define|#
directive|define
name|ICH_CYCLE_WRITE
value|2
end_define

begin_define
define|#
directive|define
name|ICH_CYCLE_ERASE
value|3
end_define

begin_define
define|#
directive|define
name|FLASH_GFPREG_BASE_MASK
value|0x1FFF
end_define

begin_define
define|#
directive|define
name|FLASH_SECTOR_ADDR_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|ICH_FLASH_SEG_SIZE_256
value|256
end_define

begin_define
define|#
directive|define
name|ICH_FLASH_SEG_SIZE_4K
value|4096
end_define

begin_define
define|#
directive|define
name|ICH_FLASH_SEG_SIZE_8K
value|8192
end_define

begin_define
define|#
directive|define
name|ICH_FLASH_SEG_SIZE_64K
value|65536
end_define

begin_define
define|#
directive|define
name|E1000_ICH_FWSM_RSPCIPHY
value|0x00000040
end_define

begin_comment
comment|/* Reset PHY on PCI Reset */
end_comment

begin_comment
comment|/* FW established a valid mode */
end_comment

begin_define
define|#
directive|define
name|E1000_ICH_FWSM_FW_VALID
value|0x00008000
end_define

begin_define
define|#
directive|define
name|E1000_ICH_FWSM_PCIM2PCI
value|0x01000000
end_define

begin_comment
comment|/* ME PCIm-to-PCI active */
end_comment

begin_define
define|#
directive|define
name|E1000_ICH_FWSM_PCIM2PCI_COUNT
value|2000
end_define

begin_define
define|#
directive|define
name|E1000_ICH_MNG_IAMT_MODE
value|0x2
end_define

begin_define
define|#
directive|define
name|E1000_FWSM_WLOCK_MAC_MASK
value|0x0380
end_define

begin_define
define|#
directive|define
name|E1000_FWSM_WLOCK_MAC_SHIFT
value|7
end_define

begin_define
define|#
directive|define
name|E1000_FWSM_ULP_CFG_DONE
value|0x00000400
end_define

begin_comment
comment|/* Low power cfg done */
end_comment

begin_comment
comment|/* Shared Receive Address Registers */
end_comment

begin_define
define|#
directive|define
name|E1000_SHRAL_PCH_LPT
parameter_list|(
name|_i
parameter_list|)
value|(0x05408 + ((_i) * 8))
end_define

begin_define
define|#
directive|define
name|E1000_SHRAH_PCH_LPT
parameter_list|(
name|_i
parameter_list|)
value|(0x0540C + ((_i) * 8))
end_define

begin_define
define|#
directive|define
name|E1000_H2ME
value|0x05B50
end_define

begin_comment
comment|/* Host to ME */
end_comment

begin_define
define|#
directive|define
name|E1000_H2ME_ULP
value|0x00000800
end_define

begin_comment
comment|/* ULP Indication Bit */
end_comment

begin_define
define|#
directive|define
name|E1000_H2ME_ENFORCE_SETTINGS
value|0x00001000
end_define

begin_comment
comment|/* Enforce Settings */
end_comment

begin_define
define|#
directive|define
name|ID_LED_DEFAULT_ICH8LAN
value|((ID_LED_DEF1_DEF2<< 12) | \ 				 (ID_LED_OFF1_OFF2<<  8) | \ 				 (ID_LED_OFF1_ON2<<  4) | \ 				 (ID_LED_DEF1_DEF2))
end_define

begin_define
define|#
directive|define
name|E1000_ICH_NVM_SIG_WORD
value|0x13
end_define

begin_define
define|#
directive|define
name|E1000_ICH_NVM_SIG_MASK
value|0xC000
end_define

begin_define
define|#
directive|define
name|E1000_ICH_NVM_VALID_SIG_MASK
value|0xC0
end_define

begin_define
define|#
directive|define
name|E1000_ICH_NVM_SIG_VALUE
value|0x80
end_define

begin_define
define|#
directive|define
name|E1000_ICH8_LAN_INIT_TIMEOUT
value|1500
end_define

begin_comment
comment|/* FEXT register bit definition */
end_comment

begin_define
define|#
directive|define
name|E1000_FEXT_PHY_CABLE_DISCONNECTED
value|0x00000004
end_define

begin_define
define|#
directive|define
name|E1000_FEXTNVM_SW_CONFIG
value|1
end_define

begin_define
define|#
directive|define
name|E1000_FEXTNVM_SW_CONFIG_ICH8M
value|(1<< 27)
end_define

begin_comment
comment|/* different on ICH8M */
end_comment

begin_define
define|#
directive|define
name|E1000_FEXTNVM3_PHY_CFG_COUNTER_MASK
value|0x0C000000
end_define

begin_define
define|#
directive|define
name|E1000_FEXTNVM3_PHY_CFG_COUNTER_50MSEC
value|0x08000000
end_define

begin_define
define|#
directive|define
name|E1000_FEXTNVM4_BEACON_DURATION_MASK
value|0x7
end_define

begin_define
define|#
directive|define
name|E1000_FEXTNVM4_BEACON_DURATION_8USEC
value|0x7
end_define

begin_define
define|#
directive|define
name|E1000_FEXTNVM4_BEACON_DURATION_16USEC
value|0x3
end_define

begin_define
define|#
directive|define
name|E1000_FEXTNVM6_REQ_PLL_CLK
value|0x00000100
end_define

begin_define
define|#
directive|define
name|E1000_FEXTNVM6_ENABLE_K1_ENTRY_CONDITION
value|0x00000200
end_define

begin_define
define|#
directive|define
name|E1000_FEXTNVM7_DISABLE_SMB_PERST
value|0x00000020
end_define

begin_define
define|#
directive|define
name|PCIE_ICH8_SNOOP_ALL
value|PCIE_NO_SNOOP_ALL
end_define

begin_define
define|#
directive|define
name|E1000_ICH_RAR_ENTRIES
value|7
end_define

begin_define
define|#
directive|define
name|E1000_PCH2_RAR_ENTRIES
value|5
end_define

begin_comment
comment|/* RAR[0], SHRA[0-3] */
end_comment

begin_define
define|#
directive|define
name|E1000_PCH_LPT_RAR_ENTRIES
value|12
end_define

begin_comment
comment|/* RAR[0], SHRA[0-10] */
end_comment

begin_define
define|#
directive|define
name|PHY_PAGE_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|PHY_REG
parameter_list|(
name|page
parameter_list|,
name|reg
parameter_list|)
value|(((page)<< PHY_PAGE_SHIFT) | \ 				 ((reg)& MAX_PHY_REG_ADDRESS))
end_define

begin_define
define|#
directive|define
name|IGP3_KMRN_DIAG
value|PHY_REG(770, 19)
end_define

begin_comment
comment|/* KMRN Diagnostic */
end_comment

begin_define
define|#
directive|define
name|IGP3_VR_CTRL
value|PHY_REG(776, 18)
end_define

begin_comment
comment|/* Voltage Regulator Control */
end_comment

begin_define
define|#
directive|define
name|IGP3_KMRN_DIAG_PCS_LOCK_LOSS
value|0x0002
end_define

begin_define
define|#
directive|define
name|IGP3_VR_CTRL_DEV_POWERDOWN_MODE_MASK
value|0x0300
end_define

begin_define
define|#
directive|define
name|IGP3_VR_CTRL_MODE_SHUTDOWN
value|0x0200
end_define

begin_comment
comment|/* PHY Wakeup Registers and defines */
end_comment

begin_define
define|#
directive|define
name|BM_PORT_GEN_CFG
value|PHY_REG(BM_PORT_CTRL_PAGE, 17)
end_define

begin_define
define|#
directive|define
name|BM_RCTL
value|PHY_REG(BM_WUC_PAGE, 0)
end_define

begin_define
define|#
directive|define
name|BM_WUC
value|PHY_REG(BM_WUC_PAGE, 1)
end_define

begin_define
define|#
directive|define
name|BM_WUFC
value|PHY_REG(BM_WUC_PAGE, 2)
end_define

begin_define
define|#
directive|define
name|BM_WUS
value|PHY_REG(BM_WUC_PAGE, 3)
end_define

begin_define
define|#
directive|define
name|BM_RAR_L
parameter_list|(
name|_i
parameter_list|)
value|(BM_PHY_REG(BM_WUC_PAGE, 16 + ((_i)<< 2)))
end_define

begin_define
define|#
directive|define
name|BM_RAR_M
parameter_list|(
name|_i
parameter_list|)
value|(BM_PHY_REG(BM_WUC_PAGE, 17 + ((_i)<< 2)))
end_define

begin_define
define|#
directive|define
name|BM_RAR_H
parameter_list|(
name|_i
parameter_list|)
value|(BM_PHY_REG(BM_WUC_PAGE, 18 + ((_i)<< 2)))
end_define

begin_define
define|#
directive|define
name|BM_RAR_CTRL
parameter_list|(
name|_i
parameter_list|)
value|(BM_PHY_REG(BM_WUC_PAGE, 19 + ((_i)<< 2)))
end_define

begin_define
define|#
directive|define
name|BM_MTA
parameter_list|(
name|_i
parameter_list|)
value|(BM_PHY_REG(BM_WUC_PAGE, 128 + ((_i)<< 1)))
end_define

begin_define
define|#
directive|define
name|BM_RCTL_UPE
value|0x0001
end_define

begin_comment
comment|/* Unicast Promiscuous Mode */
end_comment

begin_define
define|#
directive|define
name|BM_RCTL_MPE
value|0x0002
end_define

begin_comment
comment|/* Multicast Promiscuous Mode */
end_comment

begin_define
define|#
directive|define
name|BM_RCTL_MO_SHIFT
value|3
end_define

begin_comment
comment|/* Multicast Offset Shift */
end_comment

begin_define
define|#
directive|define
name|BM_RCTL_MO_MASK
value|(3<< 3)
end_define

begin_comment
comment|/* Multicast Offset Mask */
end_comment

begin_define
define|#
directive|define
name|BM_RCTL_BAM
value|0x0020
end_define

begin_comment
comment|/* Broadcast Accept Mode */
end_comment

begin_define
define|#
directive|define
name|BM_RCTL_PMCF
value|0x0040
end_define

begin_comment
comment|/* Pass MAC Control Frames */
end_comment

begin_define
define|#
directive|define
name|BM_RCTL_RFCE
value|0x0080
end_define

begin_comment
comment|/* Rx Flow Control Enable */
end_comment

begin_define
define|#
directive|define
name|HV_LED_CONFIG
value|PHY_REG(768, 30)
end_define

begin_comment
comment|/* LED Configuration */
end_comment

begin_define
define|#
directive|define
name|HV_MUX_DATA_CTRL
value|PHY_REG(776, 16)
end_define

begin_define
define|#
directive|define
name|HV_MUX_DATA_CTRL_GEN_TO_MAC
value|0x0400
end_define

begin_define
define|#
directive|define
name|HV_MUX_DATA_CTRL_FORCE_SPEED
value|0x0004
end_define

begin_define
define|#
directive|define
name|HV_STATS_PAGE
value|778
end_define

begin_comment
comment|/* Half-duplex collision counts */
end_comment

begin_define
define|#
directive|define
name|HV_SCC_UPPER
value|PHY_REG(HV_STATS_PAGE, 16)
end_define

begin_comment
comment|/* Single Collision */
end_comment

begin_define
define|#
directive|define
name|HV_SCC_LOWER
value|PHY_REG(HV_STATS_PAGE, 17)
end_define

begin_define
define|#
directive|define
name|HV_ECOL_UPPER
value|PHY_REG(HV_STATS_PAGE, 18)
end_define

begin_comment
comment|/* Excessive Coll. */
end_comment

begin_define
define|#
directive|define
name|HV_ECOL_LOWER
value|PHY_REG(HV_STATS_PAGE, 19)
end_define

begin_define
define|#
directive|define
name|HV_MCC_UPPER
value|PHY_REG(HV_STATS_PAGE, 20)
end_define

begin_comment
comment|/* Multiple Collision */
end_comment

begin_define
define|#
directive|define
name|HV_MCC_LOWER
value|PHY_REG(HV_STATS_PAGE, 21)
end_define

begin_define
define|#
directive|define
name|HV_LATECOL_UPPER
value|PHY_REG(HV_STATS_PAGE, 23)
end_define

begin_comment
comment|/* Late Collision */
end_comment

begin_define
define|#
directive|define
name|HV_LATECOL_LOWER
value|PHY_REG(HV_STATS_PAGE, 24)
end_define

begin_define
define|#
directive|define
name|HV_COLC_UPPER
value|PHY_REG(HV_STATS_PAGE, 25)
end_define

begin_comment
comment|/* Collision */
end_comment

begin_define
define|#
directive|define
name|HV_COLC_LOWER
value|PHY_REG(HV_STATS_PAGE, 26)
end_define

begin_define
define|#
directive|define
name|HV_DC_UPPER
value|PHY_REG(HV_STATS_PAGE, 27)
end_define

begin_comment
comment|/* Defer Count */
end_comment

begin_define
define|#
directive|define
name|HV_DC_LOWER
value|PHY_REG(HV_STATS_PAGE, 28)
end_define

begin_define
define|#
directive|define
name|HV_TNCRS_UPPER
value|PHY_REG(HV_STATS_PAGE, 29)
end_define

begin_comment
comment|/* Tx with no CRS */
end_comment

begin_define
define|#
directive|define
name|HV_TNCRS_LOWER
value|PHY_REG(HV_STATS_PAGE, 30)
end_define

begin_define
define|#
directive|define
name|E1000_FCRTV_PCH
value|0x05F40
end_define

begin_comment
comment|/* PCH Flow Control Refresh Timer Value */
end_comment

begin_define
define|#
directive|define
name|E1000_NVM_K1_CONFIG
value|0x1B
end_define

begin_comment
comment|/* NVM K1 Config Word */
end_comment

begin_define
define|#
directive|define
name|E1000_NVM_K1_ENABLE
value|0x1
end_define

begin_comment
comment|/* NVM Enable K1 bit */
end_comment

begin_comment
comment|/* SMBus Control Phy Register */
end_comment

begin_define
define|#
directive|define
name|CV_SMB_CTRL
value|PHY_REG(769, 23)
end_define

begin_define
define|#
directive|define
name|CV_SMB_CTRL_FORCE_SMBUS
value|0x0001
end_define

begin_comment
comment|/* I218 Ultra Low Power Configuration 1 Register */
end_comment

begin_define
define|#
directive|define
name|I218_ULP_CONFIG1
value|PHY_REG(779, 16)
end_define

begin_define
define|#
directive|define
name|I218_ULP_CONFIG1_START
value|0x0001
end_define

begin_comment
comment|/* Start auto ULP config */
end_comment

begin_define
define|#
directive|define
name|I218_ULP_CONFIG1_IND
value|0x0004
end_define

begin_comment
comment|/* Pwr up from ULP indication */
end_comment

begin_define
define|#
directive|define
name|I218_ULP_CONFIG1_STICKY_ULP
value|0x0010
end_define

begin_comment
comment|/* Set sticky ULP mode */
end_comment

begin_define
define|#
directive|define
name|I218_ULP_CONFIG1_INBAND_EXIT
value|0x0020
end_define

begin_comment
comment|/* Inband on ULP exit */
end_comment

begin_define
define|#
directive|define
name|I218_ULP_CONFIG1_WOL_HOST
value|0x0040
end_define

begin_comment
comment|/* WoL Host on ULP exit */
end_comment

begin_define
define|#
directive|define
name|I218_ULP_CONFIG1_RESET_TO_SMBUS
value|0x0100
end_define

begin_comment
comment|/* Reset to SMBus mode */
end_comment

begin_define
define|#
directive|define
name|I218_ULP_CONFIG1_DISABLE_SMB_PERST
value|0x1000
end_define

begin_comment
comment|/* Disable on PERST# */
end_comment

begin_comment
comment|/* SMBus Address Phy Register */
end_comment

begin_define
define|#
directive|define
name|HV_SMB_ADDR
value|PHY_REG(768, 26)
end_define

begin_define
define|#
directive|define
name|HV_SMB_ADDR_MASK
value|0x007F
end_define

begin_define
define|#
directive|define
name|HV_SMB_ADDR_PEC_EN
value|0x0200
end_define

begin_define
define|#
directive|define
name|HV_SMB_ADDR_VALID
value|0x0080
end_define

begin_define
define|#
directive|define
name|HV_SMB_ADDR_FREQ_MASK
value|0x1100
end_define

begin_define
define|#
directive|define
name|HV_SMB_ADDR_FREQ_LOW_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|HV_SMB_ADDR_FREQ_HIGH_SHIFT
value|12
end_define

begin_comment
comment|/* Strapping Option Register - RO */
end_comment

begin_define
define|#
directive|define
name|E1000_STRAP
value|0x0000C
end_define

begin_define
define|#
directive|define
name|E1000_STRAP_SMBUS_ADDRESS_MASK
value|0x00FE0000
end_define

begin_define
define|#
directive|define
name|E1000_STRAP_SMBUS_ADDRESS_SHIFT
value|17
end_define

begin_define
define|#
directive|define
name|E1000_STRAP_SMT_FREQ_MASK
value|0x00003000
end_define

begin_define
define|#
directive|define
name|E1000_STRAP_SMT_FREQ_SHIFT
value|12
end_define

begin_comment
comment|/* OEM Bits Phy Register */
end_comment

begin_define
define|#
directive|define
name|HV_OEM_BITS
value|PHY_REG(768, 25)
end_define

begin_define
define|#
directive|define
name|HV_OEM_BITS_LPLU
value|0x0004
end_define

begin_comment
comment|/* Low Power Link Up */
end_comment

begin_define
define|#
directive|define
name|HV_OEM_BITS_GBE_DIS
value|0x0040
end_define

begin_comment
comment|/* Gigabit Disable */
end_comment

begin_define
define|#
directive|define
name|HV_OEM_BITS_RESTART_AN
value|0x0400
end_define

begin_comment
comment|/* Restart Auto-negotiation */
end_comment

begin_comment
comment|/* KMRN Mode Control */
end_comment

begin_define
define|#
directive|define
name|HV_KMRN_MODE_CTRL
value|PHY_REG(769, 16)
end_define

begin_define
define|#
directive|define
name|HV_KMRN_MDIO_SLOW
value|0x0400
end_define

begin_comment
comment|/* KMRN FIFO Control and Status */
end_comment

begin_define
define|#
directive|define
name|HV_KMRN_FIFO_CTRLSTA
value|PHY_REG(770, 16)
end_define

begin_define
define|#
directive|define
name|HV_KMRN_FIFO_CTRLSTA_PREAMBLE_MASK
value|0x7000
end_define

begin_define
define|#
directive|define
name|HV_KMRN_FIFO_CTRLSTA_PREAMBLE_SHIFT
value|12
end_define

begin_comment
comment|/* PHY Power Management Control */
end_comment

begin_define
define|#
directive|define
name|HV_PM_CTRL
value|PHY_REG(770, 17)
end_define

begin_define
define|#
directive|define
name|HV_PM_CTRL_PLL_STOP_IN_K1_GIGA
value|0x100
end_define

begin_define
define|#
directive|define
name|HV_PM_CTRL_K1_ENABLE
value|0x4000
end_define

begin_define
define|#
directive|define
name|SW_FLAG_TIMEOUT
value|1000
end_define

begin_comment
comment|/* SW Semaphore flag timeout in ms */
end_comment

begin_comment
comment|/* Inband Control */
end_comment

begin_define
define|#
directive|define
name|I217_INBAND_CTRL
value|PHY_REG(770, 18)
end_define

begin_define
define|#
directive|define
name|I217_INBAND_CTRL_LINK_STAT_TX_TIMEOUT_MASK
value|0x3F00
end_define

begin_define
define|#
directive|define
name|I217_INBAND_CTRL_LINK_STAT_TX_TIMEOUT_SHIFT
value|8
end_define

begin_comment
comment|/* Low Power Idle GPIO Control */
end_comment

begin_define
define|#
directive|define
name|I217_LPI_GPIO_CTRL
value|PHY_REG(772, 18)
end_define

begin_define
define|#
directive|define
name|I217_LPI_GPIO_CTRL_AUTO_EN_LPI
value|0x0800
end_define

begin_comment
comment|/* PHY Low Power Idle Control */
end_comment

begin_define
define|#
directive|define
name|I82579_LPI_CTRL
value|PHY_REG(772, 20)
end_define

begin_define
define|#
directive|define
name|I82579_LPI_CTRL_100_ENABLE
value|0x2000
end_define

begin_define
define|#
directive|define
name|I82579_LPI_CTRL_1000_ENABLE
value|0x4000
end_define

begin_define
define|#
directive|define
name|I82579_LPI_CTRL_ENABLE_MASK
value|0x6000
end_define

begin_comment
comment|/* 82579 DFT Control */
end_comment

begin_define
define|#
directive|define
name|I82579_DFT_CTRL
value|PHY_REG(769, 20)
end_define

begin_define
define|#
directive|define
name|I82579_DFT_CTRL_GATE_PHY_RESET
value|0x0040
end_define

begin_comment
comment|/* Gate PHY Reset on MAC Reset */
end_comment

begin_comment
comment|/* Extended Management Interface (EMI) Registers */
end_comment

begin_define
define|#
directive|define
name|I82579_EMI_ADDR
value|0x10
end_define

begin_define
define|#
directive|define
name|I82579_EMI_DATA
value|0x11
end_define

begin_define
define|#
directive|define
name|I82579_LPI_UPDATE_TIMER
value|0x4805
end_define

begin_comment
comment|/* in 40ns units + 40 ns base value */
end_comment

begin_define
define|#
directive|define
name|I82579_MSE_THRESHOLD
value|0x084F
end_define

begin_comment
comment|/* 82579 Mean Square Error Threshold */
end_comment

begin_define
define|#
directive|define
name|I82577_MSE_THRESHOLD
value|0x0887
end_define

begin_comment
comment|/* 82577 Mean Square Error Threshold */
end_comment

begin_define
define|#
directive|define
name|I82579_MSE_LINK_DOWN
value|0x2411
end_define

begin_comment
comment|/* MSE count before dropping link */
end_comment

begin_define
define|#
directive|define
name|I82579_RX_CONFIG
value|0x3412
end_define

begin_comment
comment|/* Receive configuration */
end_comment

begin_define
define|#
directive|define
name|I82579_LPI_PLL_SHUT
value|0x4412
end_define

begin_comment
comment|/* LPI PLL Shut Enable */
end_comment

begin_define
define|#
directive|define
name|I82579_EEE_PCS_STATUS
value|0x182E
end_define

begin_comment
comment|/* IEEE MMD Register 3.1>> 8 */
end_comment

begin_define
define|#
directive|define
name|I82579_EEE_CAPABILITY
value|0x0410
end_define

begin_comment
comment|/* IEEE MMD Register 3.20 */
end_comment

begin_define
define|#
directive|define
name|I82579_EEE_ADVERTISEMENT
value|0x040E
end_define

begin_comment
comment|/* IEEE MMD Register 7.60 */
end_comment

begin_define
define|#
directive|define
name|I82579_EEE_LP_ABILITY
value|0x040F
end_define

begin_comment
comment|/* IEEE MMD Register 7.61 */
end_comment

begin_define
define|#
directive|define
name|I82579_EEE_100_SUPPORTED
value|(1<< 1)
end_define

begin_comment
comment|/* 100BaseTx EEE */
end_comment

begin_define
define|#
directive|define
name|I82579_EEE_1000_SUPPORTED
value|(1<< 2)
end_define

begin_comment
comment|/* 1000BaseTx EEE */
end_comment

begin_define
define|#
directive|define
name|I82579_LPI_100_PLL_SHUT
value|(1<< 2)
end_define

begin_comment
comment|/* 100M LPI PLL Shut Enabled */
end_comment

begin_define
define|#
directive|define
name|I217_EEE_PCS_STATUS
value|0x9401
end_define

begin_comment
comment|/* IEEE MMD Register 3.1 */
end_comment

begin_define
define|#
directive|define
name|I217_EEE_CAPABILITY
value|0x8000
end_define

begin_comment
comment|/* IEEE MMD Register 3.20 */
end_comment

begin_define
define|#
directive|define
name|I217_EEE_ADVERTISEMENT
value|0x8001
end_define

begin_comment
comment|/* IEEE MMD Register 7.60 */
end_comment

begin_define
define|#
directive|define
name|I217_EEE_LP_ABILITY
value|0x8002
end_define

begin_comment
comment|/* IEEE MMD Register 7.61 */
end_comment

begin_define
define|#
directive|define
name|I217_RX_CONFIG
value|0xB20C
end_define

begin_comment
comment|/* Receive configuration */
end_comment

begin_define
define|#
directive|define
name|E1000_EEE_RX_LPI_RCVD
value|0x0400
end_define

begin_comment
comment|/* Tx LP idle received */
end_comment

begin_define
define|#
directive|define
name|E1000_EEE_TX_LPI_RCVD
value|0x0800
end_define

begin_comment
comment|/* Rx LP idle received */
end_comment

begin_comment
comment|/* Intel Rapid Start Technology Support */
end_comment

begin_define
define|#
directive|define
name|I217_PROXY_CTRL
value|BM_PHY_REG(BM_WUC_PAGE, 70)
end_define

begin_define
define|#
directive|define
name|I217_PROXY_CTRL_AUTO_DISABLE
value|0x0080
end_define

begin_define
define|#
directive|define
name|I217_SxCTRL
value|PHY_REG(BM_PORT_CTRL_PAGE, 28)
end_define

begin_define
define|#
directive|define
name|I217_SxCTRL_ENABLE_LPI_RESET
value|0x1000
end_define

begin_define
define|#
directive|define
name|I217_CGFREG
value|PHY_REG(772, 29)
end_define

begin_define
define|#
directive|define
name|I217_CGFREG_ENABLE_MTA_RESET
value|0x0002
end_define

begin_define
define|#
directive|define
name|I217_MEMPWR
value|PHY_REG(772, 26)
end_define

begin_define
define|#
directive|define
name|I217_MEMPWR_DISABLE_SMB_RELEASE
value|0x0010
end_define

begin_comment
comment|/* Receive Address Initial CRC Calculation */
end_comment

begin_define
define|#
directive|define
name|E1000_PCH_RAICC
parameter_list|(
name|_n
parameter_list|)
value|(0x05F50 + ((_n) * 4))
end_define

begin_comment
comment|/* Latency Tolerance Reporting */
end_comment

begin_define
define|#
directive|define
name|E1000_LTRV
value|0x000F8
end_define

begin_define
define|#
directive|define
name|E1000_LTRV_VALUE_MASK
value|0x000003FF
end_define

begin_define
define|#
directive|define
name|E1000_LTRV_SCALE_MAX
value|5
end_define

begin_define
define|#
directive|define
name|E1000_LTRV_SCALE_FACTOR
value|5
end_define

begin_define
define|#
directive|define
name|E1000_LTRV_SCALE_SHIFT
value|10
end_define

begin_define
define|#
directive|define
name|E1000_LTRV_SCALE_MASK
value|0x00001C00
end_define

begin_define
define|#
directive|define
name|E1000_LTRV_REQ_SHIFT
value|15
end_define

begin_define
define|#
directive|define
name|E1000_LTRV_NOSNOOP_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|E1000_LTRV_SEND
value|(1<< 30)
end_define

begin_comment
comment|/* Proprietary Latency Tolerance Reporting PCI Capability */
end_comment

begin_define
define|#
directive|define
name|E1000_PCI_LTR_CAP_LPT
value|0xA8
end_define

begin_comment
comment|/* OBFF Control& Threshold Defines */
end_comment

begin_define
define|#
directive|define
name|E1000_SVCR_OFF_EN
value|0x00000001
end_define

begin_define
define|#
directive|define
name|E1000_SVCR_OFF_MASKINT
value|0x00001000
end_define

begin_define
define|#
directive|define
name|E1000_SVCR_OFF_TIMER_MASK
value|0xFFFF0000
end_define

begin_define
define|#
directive|define
name|E1000_SVCR_OFF_TIMER_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|E1000_SVT_OFF_HWM_MASK
value|0x0000001F
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|QV_RELEASE
argument_list|)
operator|||
operator|!
name|defined
argument_list|(
name|NO_PCH_LPT_B0_SUPPORT
argument_list|)
end_if

begin_define
define|#
directive|define
name|E1000_PCI_REVISION_ID_REG
value|0x08
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(QV_RELEASE) || !defined(NO_PCH_LPT_B0_SUPPORT) */
end_comment

begin_function_decl
name|void
name|e1000_set_kmrn_lock_loss_workaround_ich8lan
parameter_list|(
name|struct
name|e1000_hw
modifier|*
name|hw
parameter_list|,
name|bool
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|e1000_igp3_phy_powerdown_workaround_ich8lan
parameter_list|(
name|struct
name|e1000_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|e1000_gig_downshift_workaround_ich8lan
parameter_list|(
name|struct
name|e1000_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|e1000_suspend_workarounds_ich8lan
parameter_list|(
name|struct
name|e1000_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|e1000_resume_workarounds_pchlan
parameter_list|(
name|struct
name|e1000_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|s32
name|e1000_configure_k1_ich8lan
parameter_list|(
name|struct
name|e1000_hw
modifier|*
name|hw
parameter_list|,
name|bool
name|k1_enable
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|e1000_copy_rx_addrs_to_phy_ich8lan
parameter_list|(
name|struct
name|e1000_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|s32
name|e1000_lv_jumbo_workaround_ich8lan
parameter_list|(
name|struct
name|e1000_hw
modifier|*
name|hw
parameter_list|,
name|bool
name|enable
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|s32
name|e1000_read_emi_reg_locked
parameter_list|(
name|struct
name|e1000_hw
modifier|*
name|hw
parameter_list|,
name|u16
name|addr
parameter_list|,
name|u16
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|s32
name|e1000_write_emi_reg_locked
parameter_list|(
name|struct
name|e1000_hw
modifier|*
name|hw
parameter_list|,
name|u16
name|addr
parameter_list|,
name|u16
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|s32
name|e1000_set_eee_pchlan
parameter_list|(
name|struct
name|e1000_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|s32
name|e1000_enable_ulp_lpt_lp
parameter_list|(
name|struct
name|e1000_hw
modifier|*
name|hw
parameter_list|,
name|bool
name|to_sx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|s32
name|e1000_disable_ulp_lpt_lp
parameter_list|(
name|struct
name|e1000_hw
modifier|*
name|hw
parameter_list|,
name|bool
name|force
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _E1000_ICH8LAN_H_ */
end_comment

end_unit

