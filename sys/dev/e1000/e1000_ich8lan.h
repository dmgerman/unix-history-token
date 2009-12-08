begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************    Copyright (c) 2001-2009, Intel Corporation    All rights reserved.      Redistribution and use in source and binary forms, with or without    modification, are permitted provided that the following conditions are met:       1. Redistributions of source code must retain the above copyright notice,        this list of conditions and the following disclaimer.       2. Redistributions in binary form must reproduce the above copyright        notice, this list of conditions and the following disclaimer in the        documentation and/or other materials provided with the distribution.       3. Neither the name of the Intel Corporation nor the names of its        contributors may be used to endorse or promote products derived from        this software without specific prior written permission.      THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE    ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE    LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR    CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF    SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS    INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN    CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)    ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE   POSSIBILITY OF SUCH DAMAGE.  ******************************************************************************/
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
name|ICH_FLASH_SECTOR_SIZE
value|4096
end_define

begin_define
define|#
directive|define
name|ICH_FLASH_REG_MAPSIZE
value|0x00A0
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

begin_define
define|#
directive|define
name|E1000_ICH_FWSM_DISSW
value|0x10000000
end_define

begin_comment
comment|/* FW Disables SW Writes */
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
name|E1000_ICH_MNG_IAMT_MODE
value|0x2
end_define

begin_define
define|#
directive|define
name|ID_LED_DEFAULT_ICH8LAN
value|((ID_LED_DEF1_DEF2<< 12) | \                                  (ID_LED_OFF1_OFF2<<  8) | \                                  (ID_LED_OFF1_ON2<<  4) | \                                  (ID_LED_DEF1_DEF2))
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
comment|/* Bit redefined for ICH8M */
end_comment

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
value|(((page)<< PHY_PAGE_SHIFT) | \                            ((reg)& MAX_PHY_REG_ADDRESS))
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
name|IGP3_CAPABILITY
value|PHY_REG(776, 19)
end_define

begin_comment
comment|/* Capability */
end_comment

begin_define
define|#
directive|define
name|IGP3_PM_CTRL
value|PHY_REG(769, 20)
end_define

begin_comment
comment|/* Power Management Control */
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

begin_define
define|#
directive|define
name|IGP3_PM_CTRL_FORCE_PWR_DOWN
value|0x0020
end_define

begin_comment
comment|/* PHY Wakeup Registers and defines */
end_comment

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
name|HV_SCC_UPPER
value|PHY_REG(778, 16)
end_define

begin_comment
comment|/* Single Collision Count */
end_comment

begin_define
define|#
directive|define
name|HV_SCC_LOWER
value|PHY_REG(778, 17)
end_define

begin_define
define|#
directive|define
name|HV_ECOL_UPPER
value|PHY_REG(778, 18)
end_define

begin_comment
comment|/* Excessive Collision Count */
end_comment

begin_define
define|#
directive|define
name|HV_ECOL_LOWER
value|PHY_REG(778, 19)
end_define

begin_define
define|#
directive|define
name|HV_MCC_UPPER
value|PHY_REG(778, 20)
end_define

begin_comment
comment|/* Multiple Collision Count */
end_comment

begin_define
define|#
directive|define
name|HV_MCC_LOWER
value|PHY_REG(778, 21)
end_define

begin_define
define|#
directive|define
name|HV_LATECOL_UPPER
value|PHY_REG(778, 23)
end_define

begin_comment
comment|/* Late Collision Count */
end_comment

begin_define
define|#
directive|define
name|HV_LATECOL_LOWER
value|PHY_REG(778, 24)
end_define

begin_define
define|#
directive|define
name|HV_COLC_UPPER
value|PHY_REG(778, 25)
end_define

begin_comment
comment|/* Collision Count */
end_comment

begin_define
define|#
directive|define
name|HV_COLC_LOWER
value|PHY_REG(778, 26)
end_define

begin_define
define|#
directive|define
name|HV_DC_UPPER
value|PHY_REG(778, 27)
end_define

begin_comment
comment|/* Defer Count */
end_comment

begin_define
define|#
directive|define
name|HV_DC_LOWER
value|PHY_REG(778, 28)
end_define

begin_define
define|#
directive|define
name|HV_TNCRS_UPPER
value|PHY_REG(778, 29)
end_define

begin_comment
comment|/* Transmit with no CRS */
end_comment

begin_define
define|#
directive|define
name|HV_TNCRS_LOWER
value|PHY_REG(778, 30)
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
name|HV_SMB_ADDR_PEC_EN
value|0x0200
end_define

begin_define
define|#
directive|define
name|HV_SMB_ADDR_VALID
value|0x0080
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

begin_define
define|#
directive|define
name|LCD_CFG_PHY_ADDR_BIT
value|0x0020
end_define

begin_comment
comment|/* Phy address bit from LCD Config word */
end_comment

begin_define
define|#
directive|define
name|SW_FLAG_TIMEOUT
value|1000
end_define

begin_comment
comment|/* SW Semaphore flag timeout in milliseconds */
end_comment

begin_comment
comment|/*  * Additional interrupts need to be handled for ICH family:  *  DSW = The FW changed the status of the DISSW bit in FWSM  *  PHYINT = The LAN connected device generates an interrupt  *  EPRST = Manageability reset event  */
end_comment

begin_define
define|#
directive|define
name|IMS_ICH_ENABLE_MASK
value|(\     E1000_IMS_DSW   | \     E1000_IMS_PHYINT | \     E1000_IMS_EPRST)
end_define

begin_comment
comment|/* Additional interrupt register bit definitions */
end_comment

begin_define
define|#
directive|define
name|E1000_ICR_LSECPNC
value|0x00004000
end_define

begin_comment
comment|/* PN threshold - client */
end_comment

begin_define
define|#
directive|define
name|E1000_IMS_LSECPNC
value|E1000_ICR_LSECPNC
end_define

begin_comment
comment|/* PN threshold - client */
end_comment

begin_define
define|#
directive|define
name|E1000_ICS_LSECPNC
value|E1000_ICR_LSECPNC
end_define

begin_comment
comment|/* PN threshold - client */
end_comment

begin_comment
comment|/* Security Processing bit Indication */
end_comment

begin_define
define|#
directive|define
name|E1000_RXDEXT_LINKSEC_STATUS_LSECH
value|0x01000000
end_define

begin_define
define|#
directive|define
name|E1000_RXDEXT_LINKSEC_ERROR_BIT_MASK
value|0x60000000
end_define

begin_define
define|#
directive|define
name|E1000_RXDEXT_LINKSEC_ERROR_NO_SA_MATCH
value|0x20000000
end_define

begin_define
define|#
directive|define
name|E1000_RXDEXT_LINKSEC_ERROR_REPLAY_ERROR
value|0x40000000
end_define

begin_define
define|#
directive|define
name|E1000_RXDEXT_LINKSEC_ERROR_BAD_SIG
value|0x60000000
end_define

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
name|e1000_disable_gig_wol_ich8lan
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
name|s32
name|e1000_oem_bits_config_ich8lan
parameter_list|(
name|struct
name|e1000_hw
modifier|*
name|hw
parameter_list|,
name|bool
name|d0_config
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|s32
name|e1000_hv_phy_powerdown_workaround_ich8lan
parameter_list|(
name|struct
name|e1000_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

