begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*- ******************************************************************************** Copyright (C) 2015 Annapurna Labs Ltd.  This file may be licensed under the terms of the Annapurna Labs Commercial License Agreement.  Alternatively, this file can be distributed under the terms of the GNU General Public License V2 as published by the Free Software Foundation and can be found at http://www.gnu.org/licenses/gpl-2.0.html  Alternatively, redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:      *     Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.      *     Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *******************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__AL_HAL_UNIT_ADAPTER_REGS_H__
end_ifndef

begin_define
define|#
directive|define
name|__AL_HAL_UNIT_ADAPTER_REGS_H__
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
define|#
directive|define
name|AL_PCI_COMMAND
value|0x04
comment|/* 16 bits */
define|#
directive|define
name|AL_PCI_COMMAND_IO
value|0x1
comment|/* Enable response in I/O space */
define|#
directive|define
name|AL_PCI_COMMAND_MEMORY
value|0x2
comment|/* Enable response in Memory space */
define|#
directive|define
name|AL_PCI_COMMAND_MASTER
value|0x4
comment|/* Enable bus mastering */
define|#
directive|define
name|PCI_CLASS_REVISION
value|0x08
comment|/* High 24 bits are class, low 8 revision */
define|#
directive|define
name|AL_PCI_BASE_ADDRESS_SPACE_IO
value|0x01
define|#
directive|define
name|AL_PCI_BASE_ADDRESS_MEM_TYPE_64
value|0x04
comment|/* 64 bit address */
define|#
directive|define
name|AL_PCI_BASE_ADDRESS_MEM_PREFETCH
value|0x08
comment|/* prefetchable? */
define|#
directive|define
name|AL_PCI_BASE_ADDRESS_DEVICE_ID
value|0x0c
define|#
directive|define
name|AL_PCI_BASE_ADDRESS_0
value|0x10
define|#
directive|define
name|AL_PCI_BASE_ADDRESS_0_HI
value|0x14
define|#
directive|define
name|AL_PCI_BASE_ADDRESS_2
value|0x18
define|#
directive|define
name|AL_PCI_BASE_ADDRESS_2_HI
value|0x1c
define|#
directive|define
name|AL_PCI_BASE_ADDRESS_4
value|0x20
define|#
directive|define
name|AL_PCI_BASE_ADDRESS_4_HI
value|0x24
define|#
directive|define
name|AL_PCI_EXP_ROM_BASE_ADDRESS
value|0x30
define|#
directive|define
name|AL_PCI_AXI_CFG_AND_CTR_0
value|0x110
define|#
directive|define
name|AL_PCI_AXI_CFG_AND_CTR_1
value|0x130
define|#
directive|define
name|AL_PCI_AXI_CFG_AND_CTR_2
value|0x150
define|#
directive|define
name|AL_PCI_AXI_CFG_AND_CTR_3
value|0x170
define|#
directive|define
name|AL_PCI_APP_CONTROL
value|0x220
define|#
directive|define
name|AL_PCI_SRIOV_TOTAL_AND_INITIAL_VFS
value|0x30c
define|#
directive|define
name|AL_PCI_VF_BASE_ADDRESS_0
value|0x324
define|#
directive|define
name|AL_PCI_EXP_CAP_BASE
value|0x40
define|#
directive|define
name|AL_PCI_EXP_DEVCAP
value|4
comment|/* Device capabilities */
define|#
directive|define
name|AL_PCI_EXP_DEVCAP_PAYLOAD
value|0x07
comment|/* Max_Payload_Size */
define|#
directive|define
name|AL_PCI_EXP_DEVCAP_PHANTOM
value|0x18
comment|/* Phantom functions */
define|#
directive|define
name|AL_PCI_EXP_DEVCAP_EXT_TAG
value|0x20
comment|/* Extended tags */
define|#
directive|define
name|AL_PCI_EXP_DEVCAP_L0S
value|0x1c0
comment|/* L0s Acceptable Latency */
define|#
directive|define
name|AL_PCI_EXP_DEVCAP_L1
value|0xe00
comment|/* L1 Acceptable Latency */
define|#
directive|define
name|AL_PCI_EXP_DEVCAP_ATN_BUT
value|0x1000
comment|/* Attention Button Present */
define|#
directive|define
name|AL_PCI_EXP_DEVCAP_ATN_IND
value|0x2000
comment|/* Attention Indicator Present */
define|#
directive|define
name|AL_PCI_EXP_DEVCAP_PWR_IND
value|0x4000
comment|/* Power Indicator Present */
define|#
directive|define
name|AL_PCI_EXP_DEVCAP_RBER
value|0x8000
comment|/* Role-Based Error Reporting */
define|#
directive|define
name|AL_PCI_EXP_DEVCAP_PWR_VAL
value|0x3fc0000
comment|/* Slot Power Limit Value */
define|#
directive|define
name|AL_PCI_EXP_DEVCAP_PWR_SCL
value|0xc000000
comment|/* Slot Power Limit Scale */
define|#
directive|define
name|AL_PCI_EXP_DEVCAP_FLR
value|0x10000000
comment|/* Function Level Reset */
define|#
directive|define
name|AL_PCI_EXP_DEVCTL
value|8
comment|/* Device Control */
define|#
directive|define
name|AL_PCI_EXP_DEVCTL_CERE
value|0x0001
comment|/* Correctable Error Reporting En. */
define|#
directive|define
name|AL_PCI_EXP_DEVCTL_NFERE
value|0x0002
comment|/* Non-Fatal Error Reporting Enable */
define|#
directive|define
name|AL_PCI_EXP_DEVCTL_FERE
value|0x0004
comment|/* Fatal Error Reporting Enable */
define|#
directive|define
name|AL_PCI_EXP_DEVCTL_URRE
value|0x0008
comment|/* Unsupported Request Reporting En. */
define|#
directive|define
name|AL_PCI_EXP_DEVCTL_RELAX_EN
value|0x0010
comment|/* Enable relaxed ordering */
define|#
directive|define
name|AL_PCI_EXP_DEVCTL_PAYLOAD
value|0x00e0
comment|/* Max_Payload_Size */
define|#
directive|define
name|AL_PCI_EXP_DEVCTL_EXT_TAG
value|0x0100
comment|/* Extended Tag Field Enable */
define|#
directive|define
name|AL_PCI_EXP_DEVCTL_PHANTOM
value|0x0200
comment|/* Phantom Functions Enable */
define|#
directive|define
name|AL_PCI_EXP_DEVCTL_AUX_PME
value|0x0400
comment|/* Auxiliary Power PM Enable */
define|#
directive|define
name|AL_PCI_EXP_DEVCTL_NOSNOOP_EN
value|0x0800
comment|/* Enable No Snoop */
define|#
directive|define
name|AL_PCI_EXP_DEVCTL_READRQ
value|0x7000
comment|/* Max_Read_Request_Size */
define|#
directive|define
name|AL_PCI_EXP_DEVCTL_BCR_FLR
value|0x8000
comment|/* Bridge Configuration Retry / FLR */
define|#
directive|define
name|AL_PCI_EXP_DEVSTA
value|0xA
comment|/* Device Status */
define|#
directive|define
name|AL_PCI_EXP_DEVSTA_CED
value|0x01
comment|/* Correctable Error Detected */
define|#
directive|define
name|AL_PCI_EXP_DEVSTA_NFED
value|0x02
comment|/* Non-Fatal Error Detected */
define|#
directive|define
name|AL_PCI_EXP_DEVSTA_FED
value|0x04
comment|/* Fatal Error Detected */
define|#
directive|define
name|AL_PCI_EXP_DEVSTA_URD
value|0x08
comment|/* Unsupported Request Detected */
define|#
directive|define
name|AL_PCI_EXP_DEVSTA_AUXPD
value|0x10
comment|/* AUX Power Detected */
define|#
directive|define
name|AL_PCI_EXP_DEVSTA_TRPND
value|0x20
comment|/* Transactions Pending */
define|#
directive|define
name|AL_PCI_EXP_LNKCAP
value|0xC
comment|/* Link Capabilities */
define|#
directive|define
name|AL_PCI_EXP_LNKCAP_SLS
value|0xf
comment|/* Supported Link Speeds */
define|#
directive|define
name|AL_PCI_EXP_LNKCAP_SLS_2_5GB
value|0x1
comment|/* LNKCAP2 SLS Vector bit 0 (2.5GT/s) */
define|#
directive|define
name|AL_PCI_EXP_LNKCAP_SLS_5_0GB
value|0x2
comment|/* LNKCAP2 SLS Vector bit 1 (5.0GT/s) */
define|#
directive|define
name|AL_PCI_EXP_LNKCAP_MLW
value|0x3f0
comment|/* Maximum Link Width */
define|#
directive|define
name|AL_PCI_EXP_LNKCAP_ASPMS
value|0xc00
comment|/* ASPM Support */
define|#
directive|define
name|AL_PCI_EXP_LNKCAP_L0SEL
value|0x7000
comment|/* L0s Exit Latency */
define|#
directive|define
name|AL_PCI_EXP_LNKCAP_L1EL
value|0x38000
comment|/* L1 Exit Latency */
define|#
directive|define
name|AL_PCI_EXP_LNKCAP_CLKPM
value|0x40000
comment|/* L1 Clock Power Management */
define|#
directive|define
name|AL_PCI_EXP_LNKCAP_SDERC
value|0x80000
comment|/* Surprise Down Error Reporting Capable */
define|#
directive|define
name|AL_PCI_EXP_LNKCAP_DLLLARC
value|0x100000
comment|/* Data Link Layer Link Active Reporting Capable */
define|#
directive|define
name|AL_PCI_EXP_LNKCAP_LBNC
value|0x200000
comment|/* Link Bandwidth Notification Capability */
define|#
directive|define
name|AL_PCI_EXP_LNKCAP_PN
value|0xff000000
comment|/* Port Number */
define|#
directive|define
name|AL_PCI_EXP_LNKCTL
value|0x10
comment|/* Link Control */
define|#
directive|define
name|AL_PCI_EXP_LNKCTL_LNK_DIS
value|0x4
comment|/* Link Disable Status */
define|#
directive|define
name|AL_PCI_EXP_LNKCTL_LNK_RTRN
value|0x5
comment|/* Link Retrain Status */
define|#
directive|define
name|AL_PCI_EXP_LNKSTA
value|0x12
comment|/* Link Status */
define|#
directive|define
name|AL_PCI_EXP_LNKSTA_CLS
value|0x000f
comment|/* Current Link Speed */
define|#
directive|define
name|AL_PCI_EXP_LNKSTA_CLS_2_5GB
value|0x01
comment|/* Current Link Speed 2.5GT/s */
define|#
directive|define
name|AL_PCI_EXP_LNKSTA_CLS_5_0GB
value|0x02
comment|/* Current Link Speed 5.0GT/s */
define|#
directive|define
name|AL_PCI_EXP_LNKSTA_CLS_8_0GB
value|0x03
comment|/* Current Link Speed 8.0GT/s */
define|#
directive|define
name|AL_PCI_EXP_LNKSTA_NLW
value|0x03f0
comment|/* Nogotiated Link Width */
define|#
directive|define
name|AL_PCI_EXP_LNKSTA_NLW_SHIFT
value|4
comment|/* start of NLW mask in link status */
define|#
directive|define
name|AL_PCI_EXP_LNKSTA_LT
value|0x0800
comment|/* Link Training */
define|#
directive|define
name|AL_PCI_EXP_LNKSTA_SLC
value|0x1000
comment|/* Slot Clock Configuration */
define|#
directive|define
name|AL_PCI_EXP_LNKSTA_DLLLA
value|0x2000
comment|/* Data Link Layer Link Active */
define|#
directive|define
name|AL_PCI_EXP_LNKSTA_LBMS
value|0x4000
comment|/* Link Bandwidth Management Status */
define|#
directive|define
name|AL_PCI_EXP_LNKSTA_LABS
value|0x8000
comment|/* Link Autonomous Bandwidth Status */
define|#
directive|define
name|AL_PCI_EXP_LNKCTL2
value|0x30
comment|/* Link Control 2 */
define|#
directive|define
name|AL_PCI_MSIX_MSGCTRL
value|0
comment|/* MSIX message control reg */
define|#
directive|define
name|AL_PCI_MSIX_MSGCTRL_TBL_SIZE
value|0x7ff
comment|/* MSIX table size */
define|#
directive|define
name|AL_PCI_MSIX_MSGCTRL_TBL_SIZE_SHIFT
value|16
comment|/* MSIX table size shift */
define|#
directive|define
name|AL_PCI_MSIX_MSGCTRL_EN
value|0x80000000
comment|/* MSIX enable */
define|#
directive|define
name|AL_PCI_MSIX_MSGCTRL_MASK
value|0x40000000
comment|/* MSIX mask */
define|#
directive|define
name|AL_PCI_MSIX_TABLE
value|0x4
comment|/* MSIX table offset and bar reg */
define|#
directive|define
name|AL_PCI_MSIX_TABLE_OFFSET
value|0xfffffff8
comment|/* MSIX table offset */
define|#
directive|define
name|AL_PCI_MSIX_TABLE_BAR
value|0x7
comment|/* MSIX table BAR */
define|#
directive|define
name|AL_PCI_MSIX_PBA
value|0x8
comment|/* MSIX pba offset and bar reg */
define|#
directive|define
name|AL_PCI_MSIX_PBA_OFFSET
value|0xfffffff8
comment|/* MSIX pba offset */
define|#
directive|define
name|AL_PCI_MSIX_PBA_BAR
value|0x7
comment|/* MSIX pba BAR */
comment|/* Adapter power management register 0 */
define|#
directive|define
name|AL_ADAPTER_PM_0
value|0x80
define|#
directive|define
name|AL_ADAPTER_PM_0_PM_NEXT_CAP_MASK
value|0xff00
define|#
directive|define
name|AL_ADAPTER_PM_0_PM_NEXT_CAP_SHIFT
value|8
define|#
directive|define
name|AL_ADAPTER_PM_0_PM_NEXT_CAP_VAL_MSIX
value|0x90
comment|/* Adapter power management register 1 */
define|#
directive|define
name|AL_ADAPTER_PM_1
value|0x84
define|#
directive|define
name|AL_ADAPTER_PM_1_PME_EN
value|0x100
comment|/* PM enable */
define|#
directive|define
name|AL_ADAPTER_PM_1_PWR_STATE_MASK
value|0x3
comment|/* PM state mask */
define|#
directive|define
name|AL_ADAPTER_PM_1_PWR_STATE_D3
value|0x3
comment|/* PM D3 state */
comment|/* Sub Master Configuration& Control */
define|#
directive|define
name|AL_ADAPTER_SMCC
value|0x110
define|#
directive|define
name|AL_ADAPTER_SMCC_CONF_2
value|0x114
comment|/* Interrupt_Cause register */
define|#
directive|define
name|AL_ADAPTER_INT_CAUSE
value|0x1B0
define|#
directive|define
name|AL_ADAPTER_INT_CAUSE_WR_ERR
value|AL_BIT(1)
define|#
directive|define
name|AL_ADAPTER_INT_CAUSE_RD_ERR
value|AL_BIT(0)
comment|/* AXI_Master_Write_Error_Attribute_Latch register */
comment|/* AXI_Master_Read_Error_Attribute_Latch register */
define|#
directive|define
name|AL_ADAPTER_AXI_MSTR_WR_ERR_ATTR
value|0x1B4
define|#
directive|define
name|AL_ADAPTER_AXI_MSTR_RD_ERR_ATTR
value|0x1B8
define|#
directive|define
name|AL_ADAPTER_AXI_MSTR_RD_WR_ERR_ATTR_COMP_STAT_MASK
value|AL_FIELD_MASK(1, 0)
define|#
directive|define
name|AL_ADAPTER_AXI_MSTR_RD_WR_ERR_ATTR_COMP_STAT_SHIFT
value|0
define|#
directive|define
name|AL_ADAPTER_AXI_MSTR_RD_WR_ERR_ATTR_MSTR_ID_MASK
value|AL_FIELD_MASK(4, 2)
define|#
directive|define
name|AL_ADAPTER_AXI_MSTR_RD_WR_ERR_ATTR_MSTR_ID_SHIFT
value|2
define|#
directive|define
name|AL_ADAPTER_AXI_MSTR_RD_WR_ERR_ATTR_ADDR_TO
value|AL_BIT(8)
define|#
directive|define
name|AL_ADAPTER_AXI_MSTR_RD_WR_ERR_ATTR_COMP_ERR
value|AL_BIT(9)
define|#
directive|define
name|AL_ADAPTER_AXI_MSTR_RD_WR_ERR_ATTR_COMP_TO
value|AL_BIT(10)
define|#
directive|define
name|AL_ADAPTER_AXI_MSTR_RD_WR_ERR_ATTR_ERR_BLK
value|AL_BIT(11)
define|#
directive|define
name|AL_ADAPTER_AXI_MSTR_RD_ERR_ATTR_RD_PARITY_ERR
value|AL_BIT(12)
comment|/* Interrupt_Cause_mask register */
define|#
directive|define
name|AL_ADAPTER_INT_CAUSE_MASK
value|0x1BC
define|#
directive|define
name|AL_ADAPTER_INT_CAUSE_MASK_WR_ERR
value|AL_BIT(1)
define|#
directive|define
name|AL_ADAPTER_INT_CAUSE_MASK_RD_ERR
value|AL_BIT(0)
comment|/* AXI_Master_write_error_address_Latch register */
define|#
directive|define
name|AL_ADAPTER_AXI_MSTR_WR_ERR_LO_LATCH
value|0x1C0
comment|/* AXI_Master_write_error_address_high_Latch register */
define|#
directive|define
name|AL_ADAPTER_AXI_MSTR_WR_ERR_HI_LATCH
value|0x1C4
comment|/* AXI_Master_read_error_address_Latch register */
define|#
directive|define
name|AL_ADAPTER_AXI_MSTR_RD_ERR_LO_LATCH
value|0x1C8
comment|/* AXI_Master_read_error_address_high_Latch register */
define|#
directive|define
name|AL_ADAPTER_AXI_MSTR_RD_ERR_HI_LATCH
value|0x1CC
comment|/* AXI_Master_Timeout register */
define|#
directive|define
name|AL_ADAPTER_AXI_MSTR_TO
value|0x1D0
define|#
directive|define
name|AL_ADAPTER_AXI_MSTR_TO_WR_MASK
value|AL_FIELD_MASK(31, 16)
define|#
directive|define
name|AL_ADAPTER_AXI_MSTR_TO_WR_SHIFT
value|16
define|#
directive|define
name|AL_ADAPTER_AXI_MSTR_TO_RD_MASK
value|AL_FIELD_MASK(15, 0)
define|#
directive|define
name|AL_ADAPTER_AXI_MSTR_TO_RD_SHIFT
value|0
comment|/*  * Generic control registers  */
comment|/* Control 0 */
define|#
directive|define
name|AL_ADAPTER_GENERIC_CONTROL_0
value|0x1E0
comment|/* Control 2 */
define|#
directive|define
name|AL_ADAPTER_GENERIC_CONTROL_2
value|0x1E8
comment|/* Control 3 */
define|#
directive|define
name|AL_ADAPTER_GENERIC_CONTROL_3
value|0x1EC
comment|/* Control 9 */
define|#
directive|define
name|AL_ADAPTER_GENERIC_CONTROL_9
value|0x218
comment|/* Control 10 */
define|#
directive|define
name|AL_ADAPTER_GENERIC_CONTROL_10
value|0x21C
comment|/* Control 11 */
define|#
directive|define
name|AL_ADAPTER_GENERIC_CONTROL_11
value|0x220
comment|/* Control 12 */
define|#
directive|define
name|AL_ADAPTER_GENERIC_CONTROL_12
value|0x224
comment|/* Control 13 */
define|#
directive|define
name|AL_ADAPTER_GENERIC_CONTROL_13
value|0x228
comment|/* Control 14 */
define|#
directive|define
name|AL_ADAPTER_GENERIC_CONTROL_14
value|0x22C
comment|/* Control 15 */
define|#
directive|define
name|AL_ADAPTER_GENERIC_CONTROL_15
value|0x230
comment|/* Control 16 */
define|#
directive|define
name|AL_ADAPTER_GENERIC_CONTROL_16
value|0x234
comment|/* Control 17 */
define|#
directive|define
name|AL_ADAPTER_GENERIC_CONTROL_17
value|0x238
comment|/* Control 18 */
define|#
directive|define
name|AL_ADAPTER_GENERIC_CONTROL_18
value|0x23C
comment|/* Control 19 */
define|#
directive|define
name|AL_ADAPTER_GENERIC_CONTROL_19
value|0x240
comment|/* Enable clock gating */
define|#
directive|define
name|AL_ADAPTER_GENERIC_CONTROL_0_CLK_GATE_EN
value|0x01
comment|/* When set, all transactions through the PCI conf& mem BARs get timeout */
define|#
directive|define
name|AL_ADAPTER_GENERIC_CONTROL_0_ADAPTER_DIS
value|0x40
define|#
directive|define
name|AL_ADAPTER_GENERIC_CONTROL_0_ETH_RESET_1GMAC
value|AL_BIT(18)
define|#
directive|define
name|AL_ADAPTER_GENERIC_CONTROL_0_ETH_RESET_1GMAC_ON_FLR
value|AL_BIT(26)
comment|/*  * SATA registers only  */
comment|/* Select 125MHz free running clock from IOFAB main PLL as SATA OOB clock  * instead of using power management ref clock  */
define|#
directive|define
name|AL_ADAPTER_GENERIC_CONTROL_10_SATA_OOB_CLK_SEL
value|AL_BIT(26)
comment|/* AXUSER selection and value per bit (1 = address, 0 = register) */
comment|/* Rx */
define|#
directive|define
name|AL_ADPTR_GEN_CTL_12_SATA_AWUSER_VAL_MASK
value|AL_FIELD_MASK(15, 0)
define|#
directive|define
name|AL_ADPTR_GEN_CTL_12_SATA_AWUSER_VAL_SHIFT
value|0
define|#
directive|define
name|AL_ADPTR_GEN_CTL_12_SATA_AWUSER_SEL_MASK
value|AL_FIELD_MASK(31, 16)
define|#
directive|define
name|AL_ADPTR_GEN_CTL_12_SATA_AWUSER_SEL_SHIFT
value|16
comment|/* Tx */
define|#
directive|define
name|AL_ADPTR_GEN_CTL_13_SATA_ARUSER_VAL_MASK
value|AL_FIELD_MASK(15, 0)
define|#
directive|define
name|AL_ADPTR_GEN_CTL_13_SATA_ARUSER_VAL_SHIFT
value|0
define|#
directive|define
name|AL_ADPTR_GEN_CTL_13_SATA_ARUSER_SEL_MASK
value|AL_FIELD_MASK(31, 16)
define|#
directive|define
name|AL_ADPTR_GEN_CTL_13_SATA_ARUSER_SEL_SHIFT
value|16
comment|/* Central VMID enabler. If set, then each entry will be used as programmed */
define|#
directive|define
name|AL_ADPTR_GEN_CTL_14_SATA_MSIX_VMID_SEL
value|AL_BIT(0)
comment|/* Allow access to store VMID values per entry */
define|#
directive|define
name|AL_ADPTR_GEN_CTL_14_SATA_MSIX_VMID_ACCESS_EN
value|AL_BIT(1)
comment|/* VMID Address select */
comment|/* Tx */
define|#
directive|define
name|AL_ADPTR_GEN_CTL_14_SATA_VM_ARADDR_SEL_MASK
value|AL_FIELD_MASK(13, 8)
define|#
directive|define
name|AL_ADPTR_GEN_CTL_14_SATA_VM_ARADDR_SEL_SHIFT
value|8
comment|/* Rx */
define|#
directive|define
name|AL_ADPTR_GEN_CTL_14_SATA_VM_AWADDR_SEL_MASK
value|AL_FIELD_MASK(21, 16)
define|#
directive|define
name|AL_ADPTR_GEN_CTL_14_SATA_VM_AWADDR_SEL_SHIFT
value|16
comment|/* Address Value */
comment|/* Rx */
define|#
directive|define
name|AL_ADPTR_GEN_CTL_15_SATA_VM_AWDDR_HI
value|AL_FIELD_MASK(31, 0)
comment|/* Tx */
define|#
directive|define
name|AL_ADPTR_GEN_CTL_16_SATA_VM_ARDDR_HI
value|AL_FIELD_MASK(31, 0)
comment|/*  * ROB registers  */
comment|/* Read ROB_Enable, when disabled the read ROB is bypassed */
define|#
directive|define
name|AL_ADPTR_GEN_CTL_19_READ_ROB_EN
value|AL_BIT(0)
comment|/* Read force in-order of every read transaction */
define|#
directive|define
name|AL_ADPTR_GEN_CTL_19_READ_ROB_FORCE_INORDER
value|AL_BIT(1)
comment|/* Read software reset */
define|#
directive|define
name|AL_ADPTR_GEN_CTL_19_READ_ROB_SW_RESET
value|AL_BIT(15)
comment|/* Write ROB_Enable, when disabled_the_Write ROB is bypassed */
define|#
directive|define
name|AL_ADPTR_GEN_CTL_19_WRITE_ROB_EN
value|AL_BIT(16)
comment|/* Write force in-order of every write transaction */
define|#
directive|define
name|AL_ADPTR_GEN_CTL_19_WRITE_ROB_FORCE_INORDER
value|AL_BIT(17)
comment|/* Write software reset */
define|#
directive|define
name|AL_ADPTR_GEN_CTL_19_WRITE_ROB_SW_RESET
value|AL_BIT(31)
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

