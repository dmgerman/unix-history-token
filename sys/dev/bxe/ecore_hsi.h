begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-2-Clause  *  * Copyright (c) 2007-2017 QLogic Corporation. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|ECORE_HSI_H
end_ifndef

begin_define
define|#
directive|define
name|ECORE_HSI_H
end_define

begin_define
define|#
directive|define
name|FW_ENCODE_32BIT_PATTERN
value|0x1e1e1e1e
end_define

begin_struct
struct|struct
name|license_key
block|{
name|uint32_t
name|reserved
index|[
literal|6
index|]
decl_stmt|;
name|uint32_t
name|max_iscsi_conn
decl_stmt|;
define|#
directive|define
name|LICENSE_MAX_ISCSI_TRGT_CONN_MASK
value|0xFFFF
define|#
directive|define
name|LICENSE_MAX_ISCSI_TRGT_CONN_SHIFT
value|0
define|#
directive|define
name|LICENSE_MAX_ISCSI_INIT_CONN_MASK
value|0xFFFF0000
define|#
directive|define
name|LICENSE_MAX_ISCSI_INIT_CONN_SHIFT
value|16
name|uint32_t
name|reserved_a
decl_stmt|;
name|uint32_t
name|max_fcoe_conn
decl_stmt|;
define|#
directive|define
name|LICENSE_MAX_FCOE_TRGT_CONN_MASK
value|0xFFFF
define|#
directive|define
name|LICENSE_MAX_FCOE_TRGT_CONN_SHIFT
value|0
define|#
directive|define
name|LICENSE_MAX_FCOE_INIT_CONN_MASK
value|0xFFFF0000
define|#
directive|define
name|LICENSE_MAX_FCOE_INIT_CONN_SHIFT
value|16
name|uint32_t
name|reserved_b
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|license_key
name|license_key_t
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************  * Shared HW configuration                                                  *  ****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|PIN_CFG_NA
value|0x00000000
end_define

begin_define
define|#
directive|define
name|PIN_CFG_GPIO0_P0
value|0x00000001
end_define

begin_define
define|#
directive|define
name|PIN_CFG_GPIO1_P0
value|0x00000002
end_define

begin_define
define|#
directive|define
name|PIN_CFG_GPIO2_P0
value|0x00000003
end_define

begin_define
define|#
directive|define
name|PIN_CFG_GPIO3_P0
value|0x00000004
end_define

begin_define
define|#
directive|define
name|PIN_CFG_GPIO0_P1
value|0x00000005
end_define

begin_define
define|#
directive|define
name|PIN_CFG_GPIO1_P1
value|0x00000006
end_define

begin_define
define|#
directive|define
name|PIN_CFG_GPIO2_P1
value|0x00000007
end_define

begin_define
define|#
directive|define
name|PIN_CFG_GPIO3_P1
value|0x00000008
end_define

begin_define
define|#
directive|define
name|PIN_CFG_EPIO0
value|0x00000009
end_define

begin_define
define|#
directive|define
name|PIN_CFG_EPIO1
value|0x0000000a
end_define

begin_define
define|#
directive|define
name|PIN_CFG_EPIO2
value|0x0000000b
end_define

begin_define
define|#
directive|define
name|PIN_CFG_EPIO3
value|0x0000000c
end_define

begin_define
define|#
directive|define
name|PIN_CFG_EPIO4
value|0x0000000d
end_define

begin_define
define|#
directive|define
name|PIN_CFG_EPIO5
value|0x0000000e
end_define

begin_define
define|#
directive|define
name|PIN_CFG_EPIO6
value|0x0000000f
end_define

begin_define
define|#
directive|define
name|PIN_CFG_EPIO7
value|0x00000010
end_define

begin_define
define|#
directive|define
name|PIN_CFG_EPIO8
value|0x00000011
end_define

begin_define
define|#
directive|define
name|PIN_CFG_EPIO9
value|0x00000012
end_define

begin_define
define|#
directive|define
name|PIN_CFG_EPIO10
value|0x00000013
end_define

begin_define
define|#
directive|define
name|PIN_CFG_EPIO11
value|0x00000014
end_define

begin_define
define|#
directive|define
name|PIN_CFG_EPIO12
value|0x00000015
end_define

begin_define
define|#
directive|define
name|PIN_CFG_EPIO13
value|0x00000016
end_define

begin_define
define|#
directive|define
name|PIN_CFG_EPIO14
value|0x00000017
end_define

begin_define
define|#
directive|define
name|PIN_CFG_EPIO15
value|0x00000018
end_define

begin_define
define|#
directive|define
name|PIN_CFG_EPIO16
value|0x00000019
end_define

begin_define
define|#
directive|define
name|PIN_CFG_EPIO17
value|0x0000001a
end_define

begin_define
define|#
directive|define
name|PIN_CFG_EPIO18
value|0x0000001b
end_define

begin_define
define|#
directive|define
name|PIN_CFG_EPIO19
value|0x0000001c
end_define

begin_define
define|#
directive|define
name|PIN_CFG_EPIO20
value|0x0000001d
end_define

begin_define
define|#
directive|define
name|PIN_CFG_EPIO21
value|0x0000001e
end_define

begin_define
define|#
directive|define
name|PIN_CFG_EPIO22
value|0x0000001f
end_define

begin_define
define|#
directive|define
name|PIN_CFG_EPIO23
value|0x00000020
end_define

begin_define
define|#
directive|define
name|PIN_CFG_EPIO24
value|0x00000021
end_define

begin_define
define|#
directive|define
name|PIN_CFG_EPIO25
value|0x00000022
end_define

begin_define
define|#
directive|define
name|PIN_CFG_EPIO26
value|0x00000023
end_define

begin_define
define|#
directive|define
name|PIN_CFG_EPIO27
value|0x00000024
end_define

begin_define
define|#
directive|define
name|PIN_CFG_EPIO28
value|0x00000025
end_define

begin_define
define|#
directive|define
name|PIN_CFG_EPIO29
value|0x00000026
end_define

begin_define
define|#
directive|define
name|PIN_CFG_EPIO30
value|0x00000027
end_define

begin_define
define|#
directive|define
name|PIN_CFG_EPIO31
value|0x00000028
end_define

begin_comment
comment|/* EPIO definition */
end_comment

begin_define
define|#
directive|define
name|EPIO_CFG_NA
value|0x00000000
end_define

begin_define
define|#
directive|define
name|EPIO_CFG_EPIO0
value|0x00000001
end_define

begin_define
define|#
directive|define
name|EPIO_CFG_EPIO1
value|0x00000002
end_define

begin_define
define|#
directive|define
name|EPIO_CFG_EPIO2
value|0x00000003
end_define

begin_define
define|#
directive|define
name|EPIO_CFG_EPIO3
value|0x00000004
end_define

begin_define
define|#
directive|define
name|EPIO_CFG_EPIO4
value|0x00000005
end_define

begin_define
define|#
directive|define
name|EPIO_CFG_EPIO5
value|0x00000006
end_define

begin_define
define|#
directive|define
name|EPIO_CFG_EPIO6
value|0x00000007
end_define

begin_define
define|#
directive|define
name|EPIO_CFG_EPIO7
value|0x00000008
end_define

begin_define
define|#
directive|define
name|EPIO_CFG_EPIO8
value|0x00000009
end_define

begin_define
define|#
directive|define
name|EPIO_CFG_EPIO9
value|0x0000000a
end_define

begin_define
define|#
directive|define
name|EPIO_CFG_EPIO10
value|0x0000000b
end_define

begin_define
define|#
directive|define
name|EPIO_CFG_EPIO11
value|0x0000000c
end_define

begin_define
define|#
directive|define
name|EPIO_CFG_EPIO12
value|0x0000000d
end_define

begin_define
define|#
directive|define
name|EPIO_CFG_EPIO13
value|0x0000000e
end_define

begin_define
define|#
directive|define
name|EPIO_CFG_EPIO14
value|0x0000000f
end_define

begin_define
define|#
directive|define
name|EPIO_CFG_EPIO15
value|0x00000010
end_define

begin_define
define|#
directive|define
name|EPIO_CFG_EPIO16
value|0x00000011
end_define

begin_define
define|#
directive|define
name|EPIO_CFG_EPIO17
value|0x00000012
end_define

begin_define
define|#
directive|define
name|EPIO_CFG_EPIO18
value|0x00000013
end_define

begin_define
define|#
directive|define
name|EPIO_CFG_EPIO19
value|0x00000014
end_define

begin_define
define|#
directive|define
name|EPIO_CFG_EPIO20
value|0x00000015
end_define

begin_define
define|#
directive|define
name|EPIO_CFG_EPIO21
value|0x00000016
end_define

begin_define
define|#
directive|define
name|EPIO_CFG_EPIO22
value|0x00000017
end_define

begin_define
define|#
directive|define
name|EPIO_CFG_EPIO23
value|0x00000018
end_define

begin_define
define|#
directive|define
name|EPIO_CFG_EPIO24
value|0x00000019
end_define

begin_define
define|#
directive|define
name|EPIO_CFG_EPIO25
value|0x0000001a
end_define

begin_define
define|#
directive|define
name|EPIO_CFG_EPIO26
value|0x0000001b
end_define

begin_define
define|#
directive|define
name|EPIO_CFG_EPIO27
value|0x0000001c
end_define

begin_define
define|#
directive|define
name|EPIO_CFG_EPIO28
value|0x0000001d
end_define

begin_define
define|#
directive|define
name|EPIO_CFG_EPIO29
value|0x0000001e
end_define

begin_define
define|#
directive|define
name|EPIO_CFG_EPIO30
value|0x0000001f
end_define

begin_define
define|#
directive|define
name|EPIO_CFG_EPIO31
value|0x00000020
end_define

begin_struct
struct|struct
name|mac_addr
block|{
name|uint32_t
name|upper
decl_stmt|;
name|uint32_t
name|lower
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|shared_hw_cfg
block|{
comment|/* NVRAM Offset */
comment|/* Up to 16 bytes of NULL-terminated string */
name|uint8_t
name|part_num
index|[
literal|16
index|]
decl_stmt|;
comment|/* 0x104 */
name|uint32_t
name|config
decl_stmt|;
comment|/* 0x114 */
define|#
directive|define
name|SHARED_HW_CFG_MDIO_VOLTAGE_MASK
value|0x00000001
define|#
directive|define
name|SHARED_HW_CFG_MDIO_VOLTAGE_SHIFT
value|0
define|#
directive|define
name|SHARED_HW_CFG_MDIO_VOLTAGE_1_2V
value|0x00000000
define|#
directive|define
name|SHARED_HW_CFG_MDIO_VOLTAGE_2_5V
value|0x00000001
define|#
directive|define
name|SHARED_HW_CFG_PORT_SWAP
value|0x00000004
define|#
directive|define
name|SHARED_HW_CFG_BEACON_WOL_EN
value|0x00000008
define|#
directive|define
name|SHARED_HW_CFG_PCIE_GEN3_DISABLED
value|0x00000000
define|#
directive|define
name|SHARED_HW_CFG_PCIE_GEN3_ENABLED
value|0x00000010
define|#
directive|define
name|SHARED_HW_CFG_MFW_SELECT_MASK
value|0x00000700
define|#
directive|define
name|SHARED_HW_CFG_MFW_SELECT_SHIFT
value|8
comment|/* Whatever MFW found in NVM 	   (if multiple found, priority order is: NC-SI, UMP, IPMI) */
define|#
directive|define
name|SHARED_HW_CFG_MFW_SELECT_DEFAULT
value|0x00000000
define|#
directive|define
name|SHARED_HW_CFG_MFW_SELECT_NC_SI
value|0x00000100
define|#
directive|define
name|SHARED_HW_CFG_MFW_SELECT_UMP
value|0x00000200
define|#
directive|define
name|SHARED_HW_CFG_MFW_SELECT_IPMI
value|0x00000300
comment|/* Use SPIO4 as an arbiter between: 0-NC_SI, 1-IPMI 	  (can only be used when an add-in board, not BMC, pulls-down SPIO4) */
define|#
directive|define
name|SHARED_HW_CFG_MFW_SELECT_SPIO4_NC_SI_IPMI
value|0x00000400
comment|/* Use SPIO4 as an arbiter between: 0-UMP, 1-IPMI 	  (can only be used when an add-in board, not BMC, pulls-down SPIO4) */
define|#
directive|define
name|SHARED_HW_CFG_MFW_SELECT_SPIO4_UMP_IPMI
value|0x00000500
comment|/* Use SPIO4 as an arbiter between: 0-NC-SI, 1-UMP 	  (can only be used when an add-in board, not BMC, pulls-down SPIO4) */
define|#
directive|define
name|SHARED_HW_CFG_MFW_SELECT_SPIO4_NC_SI_UMP
value|0x00000600
comment|/* Adjust the PCIe G2 Tx amplitude driver for all Tx lanes. For 	   backwards compatibility, value of 0 is disabling this feature. 	    That means that though 0 is a valid value, it cannot be 	    configured. */
define|#
directive|define
name|SHARED_HW_CFG_G2_TX_DRIVE_MASK
value|0x0000F000
define|#
directive|define
name|SHARED_HW_CFG_G2_TX_DRIVE_SHIFT
value|12
define|#
directive|define
name|SHARED_HW_CFG_LED_MODE_MASK
value|0x000F0000
define|#
directive|define
name|SHARED_HW_CFG_LED_MODE_SHIFT
value|16
define|#
directive|define
name|SHARED_HW_CFG_LED_MAC1
value|0x00000000
define|#
directive|define
name|SHARED_HW_CFG_LED_PHY1
value|0x00010000
define|#
directive|define
name|SHARED_HW_CFG_LED_PHY2
value|0x00020000
define|#
directive|define
name|SHARED_HW_CFG_LED_PHY3
value|0x00030000
define|#
directive|define
name|SHARED_HW_CFG_LED_MAC2
value|0x00040000
define|#
directive|define
name|SHARED_HW_CFG_LED_PHY4
value|0x00050000
define|#
directive|define
name|SHARED_HW_CFG_LED_PHY5
value|0x00060000
define|#
directive|define
name|SHARED_HW_CFG_LED_PHY6
value|0x00070000
define|#
directive|define
name|SHARED_HW_CFG_LED_MAC3
value|0x00080000
define|#
directive|define
name|SHARED_HW_CFG_LED_PHY7
value|0x00090000
define|#
directive|define
name|SHARED_HW_CFG_LED_PHY9
value|0x000a0000
define|#
directive|define
name|SHARED_HW_CFG_LED_PHY11
value|0x000b0000
define|#
directive|define
name|SHARED_HW_CFG_LED_MAC4
value|0x000c0000
define|#
directive|define
name|SHARED_HW_CFG_LED_PHY8
value|0x000d0000
define|#
directive|define
name|SHARED_HW_CFG_LED_EXTPHY1
value|0x000e0000
define|#
directive|define
name|SHARED_HW_CFG_LED_EXTPHY2
value|0x000f0000
define|#
directive|define
name|SHARED_HW_CFG_SRIOV_MASK
value|0x40000000
define|#
directive|define
name|SHARED_HW_CFG_SRIOV_DISABLED
value|0x00000000
define|#
directive|define
name|SHARED_HW_CFG_SRIOV_ENABLED
value|0x40000000
define|#
directive|define
name|SHARED_HW_CFG_ATC_MASK
value|0x80000000
define|#
directive|define
name|SHARED_HW_CFG_ATC_DISABLED
value|0x00000000
define|#
directive|define
name|SHARED_HW_CFG_ATC_ENABLED
value|0x80000000
name|uint32_t
name|config2
decl_stmt|;
comment|/* 0x118 */
define|#
directive|define
name|SHARED_HW_CFG_PCIE_GEN2_MASK
value|0x00000100
define|#
directive|define
name|SHARED_HW_CFG_PCIE_GEN2_SHIFT
value|8
define|#
directive|define
name|SHARED_HW_CFG_PCIE_GEN2_DISABLED
value|0x00000000
define|#
directive|define
name|SHARED_HW_CFG_PCIE_GEN2_ENABLED
value|0x00000100
define|#
directive|define
name|SHARED_HW_CFG_SMBUS_TIMING_MASK
value|0x00001000
define|#
directive|define
name|SHARED_HW_CFG_SMBUS_TIMING_100KHZ
value|0x00000000
define|#
directive|define
name|SHARED_HW_CFG_SMBUS_TIMING_400KHZ
value|0x00001000
define|#
directive|define
name|SHARED_HW_CFG_HIDE_PORT1
value|0x00002000
comment|/* Output low when PERST is asserted */
define|#
directive|define
name|SHARED_HW_CFG_SPIO4_FOLLOW_PERST_MASK
value|0x00008000
define|#
directive|define
name|SHARED_HW_CFG_SPIO4_FOLLOW_PERST_DISABLED
value|0x00000000
define|#
directive|define
name|SHARED_HW_CFG_SPIO4_FOLLOW_PERST_ENABLED
value|0x00008000
define|#
directive|define
name|SHARED_HW_CFG_PCIE_GEN2_PREEMPHASIS_MASK
value|0x00070000
define|#
directive|define
name|SHARED_HW_CFG_PCIE_GEN2_PREEMPHASIS_SHIFT
value|16
define|#
directive|define
name|SHARED_HW_CFG_PCIE_GEN2_PREEMPHASIS_HW
value|0x00000000
define|#
directive|define
name|SHARED_HW_CFG_PCIE_GEN2_PREEMPHASIS_0DB
value|0x00010000
define|#
directive|define
name|SHARED_HW_CFG_PCIE_GEN2_PREEMPHASIS_3_5DB
value|0x00020000
define|#
directive|define
name|SHARED_HW_CFG_PCIE_GEN2_PREEMPHASIS_6_0DB
value|0x00030000
comment|/*  The fan failure mechanism is usually related to the PHY type 	      since the power consumption of the board is determined by the PHY. 	      Currently, fan is required for most designs with SFX7101, BCM8727 	      and BCM8481. If a fan is not required for a board which uses one 	      of those PHYs, this field should be set to "Disabled". If a fan is 	      required for a different PHY type, this option should be set to 	      "Enabled". The fan failure indication is expected on SPIO5 */
define|#
directive|define
name|SHARED_HW_CFG_FAN_FAILURE_MASK
value|0x00180000
define|#
directive|define
name|SHARED_HW_CFG_FAN_FAILURE_SHIFT
value|19
define|#
directive|define
name|SHARED_HW_CFG_FAN_FAILURE_PHY_TYPE
value|0x00000000
define|#
directive|define
name|SHARED_HW_CFG_FAN_FAILURE_DISABLED
value|0x00080000
define|#
directive|define
name|SHARED_HW_CFG_FAN_FAILURE_ENABLED
value|0x00100000
comment|/* ASPM Power Management support */
define|#
directive|define
name|SHARED_HW_CFG_ASPM_SUPPORT_MASK
value|0x00600000
define|#
directive|define
name|SHARED_HW_CFG_ASPM_SUPPORT_SHIFT
value|21
define|#
directive|define
name|SHARED_HW_CFG_ASPM_SUPPORT_L0S_L1_ENABLED
value|0x00000000
define|#
directive|define
name|SHARED_HW_CFG_ASPM_SUPPORT_L0S_DISABLED
value|0x00200000
define|#
directive|define
name|SHARED_HW_CFG_ASPM_SUPPORT_L1_DISABLED
value|0x00400000
define|#
directive|define
name|SHARED_HW_CFG_ASPM_SUPPORT_L0S_L1_DISABLED
value|0x00600000
comment|/* The value of PM_TL_IGNORE_REQS (bit0) in PCI register 	   tl_control_0 (register 0x2800) */
define|#
directive|define
name|SHARED_HW_CFG_PREVENT_L1_ENTRY_MASK
value|0x00800000
define|#
directive|define
name|SHARED_HW_CFG_PREVENT_L1_ENTRY_DISABLED
value|0x00000000
define|#
directive|define
name|SHARED_HW_CFG_PREVENT_L1_ENTRY_ENABLED
value|0x00800000
comment|/*  Set the MDC/MDIO access for the first external phy */
define|#
directive|define
name|SHARED_HW_CFG_MDC_MDIO_ACCESS1_MASK
value|0x1C000000
define|#
directive|define
name|SHARED_HW_CFG_MDC_MDIO_ACCESS1_SHIFT
value|26
define|#
directive|define
name|SHARED_HW_CFG_MDC_MDIO_ACCESS1_PHY_TYPE
value|0x00000000
define|#
directive|define
name|SHARED_HW_CFG_MDC_MDIO_ACCESS1_EMAC0
value|0x04000000
define|#
directive|define
name|SHARED_HW_CFG_MDC_MDIO_ACCESS1_EMAC1
value|0x08000000
define|#
directive|define
name|SHARED_HW_CFG_MDC_MDIO_ACCESS1_BOTH
value|0x0c000000
define|#
directive|define
name|SHARED_HW_CFG_MDC_MDIO_ACCESS1_SWAPPED
value|0x10000000
comment|/*  Set the MDC/MDIO access for the second external phy */
define|#
directive|define
name|SHARED_HW_CFG_MDC_MDIO_ACCESS2_MASK
value|0xE0000000
define|#
directive|define
name|SHARED_HW_CFG_MDC_MDIO_ACCESS2_SHIFT
value|29
define|#
directive|define
name|SHARED_HW_CFG_MDC_MDIO_ACCESS2_PHY_TYPE
value|0x00000000
define|#
directive|define
name|SHARED_HW_CFG_MDC_MDIO_ACCESS2_EMAC0
value|0x20000000
define|#
directive|define
name|SHARED_HW_CFG_MDC_MDIO_ACCESS2_EMAC1
value|0x40000000
define|#
directive|define
name|SHARED_HW_CFG_MDC_MDIO_ACCESS2_BOTH
value|0x60000000
define|#
directive|define
name|SHARED_HW_CFG_MDC_MDIO_ACCESS2_SWAPPED
value|0x80000000
comment|/*  Max number of PF MSIX vectors */
name|uint32_t
name|config_3
decl_stmt|;
comment|/* 0x11C */
define|#
directive|define
name|SHARED_HW_CFG_PF_MSIX_MAX_NUM_MASK
value|0x0000007F
define|#
directive|define
name|SHARED_HW_CFG_PF_MSIX_MAX_NUM_SHIFT
value|0
comment|/*  This field extends the mf mode chosen in nvm cfg #73 (as we ran           out of bits) */
define|#
directive|define
name|SHARED_HW_CFG_EXTENDED_MF_MODE_MASK
value|0x00000F00
define|#
directive|define
name|SHARED_HW_CFG_EXTENDED_MF_MODE_SHIFT
value|8
define|#
directive|define
name|SHARED_HW_CFG_EXTENDED_MF_MODE_NPAR1_DOT_5
value|0x00000000
define|#
directive|define
name|SHARED_HW_CFG_EXTENDED_MF_MODE_NPAR2_DOT_0
value|0x00000100
name|uint32_t
name|ump_nc_si_config
decl_stmt|;
comment|/* 0x120 */
define|#
directive|define
name|SHARED_HW_CFG_UMP_NC_SI_MII_MODE_MASK
value|0x00000003
define|#
directive|define
name|SHARED_HW_CFG_UMP_NC_SI_MII_MODE_SHIFT
value|0
define|#
directive|define
name|SHARED_HW_CFG_UMP_NC_SI_MII_MODE_MAC
value|0x00000000
define|#
directive|define
name|SHARED_HW_CFG_UMP_NC_SI_MII_MODE_PHY
value|0x00000001
define|#
directive|define
name|SHARED_HW_CFG_UMP_NC_SI_MII_MODE_MII
value|0x00000000
define|#
directive|define
name|SHARED_HW_CFG_UMP_NC_SI_MII_MODE_RMII
value|0x00000002
comment|/* Reserved bits: 226-230 */
comment|/*  The output pin template BSC_SEL which selects the I2C for this 	port in the I2C Mux */
name|uint32_t
name|board
decl_stmt|;
comment|/* 0x124 */
define|#
directive|define
name|SHARED_HW_CFG_E3_I2C_MUX0_MASK
value|0x0000003F
define|#
directive|define
name|SHARED_HW_CFG_E3_I2C_MUX0_SHIFT
value|0
define|#
directive|define
name|SHARED_HW_CFG_E3_I2C_MUX1_MASK
value|0x00000FC0
define|#
directive|define
name|SHARED_HW_CFG_E3_I2C_MUX1_SHIFT
value|6
comment|/* Use the PIN_CFG_XXX defines on top */
define|#
directive|define
name|SHARED_HW_CFG_BOARD_REV_MASK
value|0x00FF0000
define|#
directive|define
name|SHARED_HW_CFG_BOARD_REV_SHIFT
value|16
define|#
directive|define
name|SHARED_HW_CFG_BOARD_MAJOR_VER_MASK
value|0x0F000000
define|#
directive|define
name|SHARED_HW_CFG_BOARD_MAJOR_VER_SHIFT
value|24
define|#
directive|define
name|SHARED_HW_CFG_BOARD_MINOR_VER_MASK
value|0xF0000000
define|#
directive|define
name|SHARED_HW_CFG_BOARD_MINOR_VER_SHIFT
value|28
name|uint32_t
name|wc_lane_config
decl_stmt|;
comment|/* 0x128 */
define|#
directive|define
name|SHARED_HW_CFG_LANE_SWAP_CFG_MASK
value|0x0000FFFF
define|#
directive|define
name|SHARED_HW_CFG_LANE_SWAP_CFG_SHIFT
value|0
define|#
directive|define
name|SHARED_HW_CFG_LANE_SWAP_CFG_32103210
value|0x00001b1b
define|#
directive|define
name|SHARED_HW_CFG_LANE_SWAP_CFG_32100123
value|0x00001be4
define|#
directive|define
name|SHARED_HW_CFG_LANE_SWAP_CFG_31200213
value|0x000027d8
define|#
directive|define
name|SHARED_HW_CFG_LANE_SWAP_CFG_02133120
value|0x0000d827
define|#
directive|define
name|SHARED_HW_CFG_LANE_SWAP_CFG_01233210
value|0x0000e41b
define|#
directive|define
name|SHARED_HW_CFG_LANE_SWAP_CFG_01230123
value|0x0000e4e4
define|#
directive|define
name|SHARED_HW_CFG_LANE_SWAP_CFG_TX_MASK
value|0x000000FF
define|#
directive|define
name|SHARED_HW_CFG_LANE_SWAP_CFG_TX_SHIFT
value|0
define|#
directive|define
name|SHARED_HW_CFG_LANE_SWAP_CFG_RX_MASK
value|0x0000FF00
define|#
directive|define
name|SHARED_HW_CFG_LANE_SWAP_CFG_RX_SHIFT
value|8
comment|/* TX lane Polarity swap */
define|#
directive|define
name|SHARED_HW_CFG_TX_LANE0_POL_FLIP_ENABLED
value|0x00010000
define|#
directive|define
name|SHARED_HW_CFG_TX_LANE1_POL_FLIP_ENABLED
value|0x00020000
define|#
directive|define
name|SHARED_HW_CFG_TX_LANE2_POL_FLIP_ENABLED
value|0x00040000
define|#
directive|define
name|SHARED_HW_CFG_TX_LANE3_POL_FLIP_ENABLED
value|0x00080000
comment|/* TX lane Polarity swap */
define|#
directive|define
name|SHARED_HW_CFG_RX_LANE0_POL_FLIP_ENABLED
value|0x00100000
define|#
directive|define
name|SHARED_HW_CFG_RX_LANE1_POL_FLIP_ENABLED
value|0x00200000
define|#
directive|define
name|SHARED_HW_CFG_RX_LANE2_POL_FLIP_ENABLED
value|0x00400000
define|#
directive|define
name|SHARED_HW_CFG_RX_LANE3_POL_FLIP_ENABLED
value|0x00800000
comment|/*  Selects the port layout of the board */
define|#
directive|define
name|SHARED_HW_CFG_E3_PORT_LAYOUT_MASK
value|0x0F000000
define|#
directive|define
name|SHARED_HW_CFG_E3_PORT_LAYOUT_SHIFT
value|24
define|#
directive|define
name|SHARED_HW_CFG_E3_PORT_LAYOUT_2P_01
value|0x00000000
define|#
directive|define
name|SHARED_HW_CFG_E3_PORT_LAYOUT_2P_10
value|0x01000000
define|#
directive|define
name|SHARED_HW_CFG_E3_PORT_LAYOUT_4P_0123
value|0x02000000
define|#
directive|define
name|SHARED_HW_CFG_E3_PORT_LAYOUT_4P_1032
value|0x03000000
define|#
directive|define
name|SHARED_HW_CFG_E3_PORT_LAYOUT_4P_2301
value|0x04000000
define|#
directive|define
name|SHARED_HW_CFG_E3_PORT_LAYOUT_4P_3210
value|0x05000000
define|#
directive|define
name|SHARED_HW_CFG_E3_PORT_LAYOUT_2P_01_SIG
value|0x06000000
block|}
struct|;
end_struct

begin_comment
comment|/****************************************************************************  * Port HW configuration                                                    *  ****************************************************************************/
end_comment

begin_struct
struct|struct
name|port_hw_cfg
block|{
comment|/* port 0: 0x12c  port 1: 0x2bc */
name|uint32_t
name|pci_id
decl_stmt|;
define|#
directive|define
name|PORT_HW_CFG_PCI_DEVICE_ID_MASK
value|0x0000FFFF
define|#
directive|define
name|PORT_HW_CFG_PCI_DEVICE_ID_SHIFT
value|0
define|#
directive|define
name|PORT_HW_CFG_PCI_VENDOR_ID_MASK
value|0xFFFF0000
define|#
directive|define
name|PORT_HW_CFG_PCI_VENDOR_ID_SHIFT
value|16
name|uint32_t
name|pci_sub_id
decl_stmt|;
define|#
directive|define
name|PORT_HW_CFG_PCI_SUBSYS_VENDOR_ID_MASK
value|0x0000FFFF
define|#
directive|define
name|PORT_HW_CFG_PCI_SUBSYS_VENDOR_ID_SHIFT
value|0
define|#
directive|define
name|PORT_HW_CFG_PCI_SUBSYS_DEVICE_ID_MASK
value|0xFFFF0000
define|#
directive|define
name|PORT_HW_CFG_PCI_SUBSYS_DEVICE_ID_SHIFT
value|16
name|uint32_t
name|power_dissipated
decl_stmt|;
define|#
directive|define
name|PORT_HW_CFG_POWER_DIS_D0_MASK
value|0x000000FF
define|#
directive|define
name|PORT_HW_CFG_POWER_DIS_D0_SHIFT
value|0
define|#
directive|define
name|PORT_HW_CFG_POWER_DIS_D1_MASK
value|0x0000FF00
define|#
directive|define
name|PORT_HW_CFG_POWER_DIS_D1_SHIFT
value|8
define|#
directive|define
name|PORT_HW_CFG_POWER_DIS_D2_MASK
value|0x00FF0000
define|#
directive|define
name|PORT_HW_CFG_POWER_DIS_D2_SHIFT
value|16
define|#
directive|define
name|PORT_HW_CFG_POWER_DIS_D3_MASK
value|0xFF000000
define|#
directive|define
name|PORT_HW_CFG_POWER_DIS_D3_SHIFT
value|24
name|uint32_t
name|power_consumed
decl_stmt|;
define|#
directive|define
name|PORT_HW_CFG_POWER_CONS_D0_MASK
value|0x000000FF
define|#
directive|define
name|PORT_HW_CFG_POWER_CONS_D0_SHIFT
value|0
define|#
directive|define
name|PORT_HW_CFG_POWER_CONS_D1_MASK
value|0x0000FF00
define|#
directive|define
name|PORT_HW_CFG_POWER_CONS_D1_SHIFT
value|8
define|#
directive|define
name|PORT_HW_CFG_POWER_CONS_D2_MASK
value|0x00FF0000
define|#
directive|define
name|PORT_HW_CFG_POWER_CONS_D2_SHIFT
value|16
define|#
directive|define
name|PORT_HW_CFG_POWER_CONS_D3_MASK
value|0xFF000000
define|#
directive|define
name|PORT_HW_CFG_POWER_CONS_D3_SHIFT
value|24
name|uint32_t
name|mac_upper
decl_stmt|;
name|uint32_t
name|mac_lower
decl_stmt|;
comment|/* 0x140 */
define|#
directive|define
name|PORT_HW_CFG_UPPERMAC_MASK
value|0x0000FFFF
define|#
directive|define
name|PORT_HW_CFG_UPPERMAC_SHIFT
value|0
name|uint32_t
name|iscsi_mac_upper
decl_stmt|;
comment|/* Upper 16 bits are always zeroes */
name|uint32_t
name|iscsi_mac_lower
decl_stmt|;
name|uint32_t
name|rdma_mac_upper
decl_stmt|;
comment|/* Upper 16 bits are always zeroes */
name|uint32_t
name|rdma_mac_lower
decl_stmt|;
name|uint32_t
name|serdes_config
decl_stmt|;
define|#
directive|define
name|PORT_HW_CFG_SERDES_TX_DRV_PRE_EMPHASIS_MASK
value|0x0000FFFF
define|#
directive|define
name|PORT_HW_CFG_SERDES_TX_DRV_PRE_EMPHASIS_SHIFT
value|0
define|#
directive|define
name|PORT_HW_CFG_SERDES_RX_DRV_EQUALIZER_MASK
value|0xFFFF0000
define|#
directive|define
name|PORT_HW_CFG_SERDES_RX_DRV_EQUALIZER_SHIFT
value|16
comment|/*  Default values: 2P-64, 4P-32 */
name|uint32_t
name|reserved
decl_stmt|;
name|uint32_t
name|vf_config
decl_stmt|;
comment|/* 0x15C */
define|#
directive|define
name|PORT_HW_CFG_VF_PCI_DEVICE_ID_MASK
value|0xFFFF0000
define|#
directive|define
name|PORT_HW_CFG_VF_PCI_DEVICE_ID_SHIFT
value|16
name|uint32_t
name|mf_pci_id
decl_stmt|;
comment|/* 0x160 */
define|#
directive|define
name|PORT_HW_CFG_MF_PCI_DEVICE_ID_MASK
value|0x0000FFFF
define|#
directive|define
name|PORT_HW_CFG_MF_PCI_DEVICE_ID_SHIFT
value|0
comment|/*  Controls the TX laser of the SFP+ module */
name|uint32_t
name|sfp_ctrl
decl_stmt|;
comment|/* 0x164 */
define|#
directive|define
name|PORT_HW_CFG_TX_LASER_MASK
value|0x000000FF
define|#
directive|define
name|PORT_HW_CFG_TX_LASER_SHIFT
value|0
define|#
directive|define
name|PORT_HW_CFG_TX_LASER_MDIO
value|0x00000000
define|#
directive|define
name|PORT_HW_CFG_TX_LASER_GPIO0
value|0x00000001
define|#
directive|define
name|PORT_HW_CFG_TX_LASER_GPIO1
value|0x00000002
define|#
directive|define
name|PORT_HW_CFG_TX_LASER_GPIO2
value|0x00000003
define|#
directive|define
name|PORT_HW_CFG_TX_LASER_GPIO3
value|0x00000004
comment|/*  Controls the fault module LED of the SFP+ */
define|#
directive|define
name|PORT_HW_CFG_FAULT_MODULE_LED_MASK
value|0x0000FF00
define|#
directive|define
name|PORT_HW_CFG_FAULT_MODULE_LED_SHIFT
value|8
define|#
directive|define
name|PORT_HW_CFG_FAULT_MODULE_LED_GPIO0
value|0x00000000
define|#
directive|define
name|PORT_HW_CFG_FAULT_MODULE_LED_GPIO1
value|0x00000100
define|#
directive|define
name|PORT_HW_CFG_FAULT_MODULE_LED_GPIO2
value|0x00000200
define|#
directive|define
name|PORT_HW_CFG_FAULT_MODULE_LED_GPIO3
value|0x00000300
define|#
directive|define
name|PORT_HW_CFG_FAULT_MODULE_LED_DISABLED
value|0x00000400
comment|/*  The output pin TX_DIS that controls the TX laser of the SFP+ 	  module. Use the PIN_CFG_XXX defines on top */
name|uint32_t
name|e3_sfp_ctrl
decl_stmt|;
comment|/* 0x168 */
define|#
directive|define
name|PORT_HW_CFG_E3_TX_LASER_MASK
value|0x000000FF
define|#
directive|define
name|PORT_HW_CFG_E3_TX_LASER_SHIFT
value|0
comment|/*  The output pin for SFPP_TYPE which turns on the Fault module LED */
define|#
directive|define
name|PORT_HW_CFG_E3_FAULT_MDL_LED_MASK
value|0x0000FF00
define|#
directive|define
name|PORT_HW_CFG_E3_FAULT_MDL_LED_SHIFT
value|8
comment|/*  The input pin MOD_ABS that indicates whether SFP+ module is 	  present or not. Use the PIN_CFG_XXX defines on top */
define|#
directive|define
name|PORT_HW_CFG_E3_MOD_ABS_MASK
value|0x00FF0000
define|#
directive|define
name|PORT_HW_CFG_E3_MOD_ABS_SHIFT
value|16
comment|/*  The output pin PWRDIS_SFP_X which disable the power of the SFP+ 	  module. Use the PIN_CFG_XXX defines on top */
define|#
directive|define
name|PORT_HW_CFG_E3_PWR_DIS_MASK
value|0xFF000000
define|#
directive|define
name|PORT_HW_CFG_E3_PWR_DIS_SHIFT
value|24
comment|/* 	 * The input pin which signals module transmit fault. Use the 	 * PIN_CFG_XXX defines on top 	 */
name|uint32_t
name|e3_cmn_pin_cfg
decl_stmt|;
comment|/* 0x16C */
define|#
directive|define
name|PORT_HW_CFG_E3_TX_FAULT_MASK
value|0x000000FF
define|#
directive|define
name|PORT_HW_CFG_E3_TX_FAULT_SHIFT
value|0
comment|/*  The output pin which reset the PHY. Use the PIN_CFG_XXX defines on 	 top */
define|#
directive|define
name|PORT_HW_CFG_E3_PHY_RESET_MASK
value|0x0000FF00
define|#
directive|define
name|PORT_HW_CFG_E3_PHY_RESET_SHIFT
value|8
comment|/* 	 * The output pin which powers down the PHY. Use the PIN_CFG_XXX 	 * defines on top 	 */
define|#
directive|define
name|PORT_HW_CFG_E3_PWR_DOWN_MASK
value|0x00FF0000
define|#
directive|define
name|PORT_HW_CFG_E3_PWR_DOWN_SHIFT
value|16
comment|/*  The output pin values BSC_SEL which selects the I2C for this port 	  in the I2C Mux */
define|#
directive|define
name|PORT_HW_CFG_E3_I2C_MUX0_MASK
value|0x01000000
define|#
directive|define
name|PORT_HW_CFG_E3_I2C_MUX1_MASK
value|0x02000000
comment|/* 	 * The input pin I_FAULT which indicate over-current has occurred. 	 * Use the PIN_CFG_XXX defines on top 	 */
name|uint32_t
name|e3_cmn_pin_cfg1
decl_stmt|;
comment|/* 0x170 */
define|#
directive|define
name|PORT_HW_CFG_E3_OVER_CURRENT_MASK
value|0x000000FF
define|#
directive|define
name|PORT_HW_CFG_E3_OVER_CURRENT_SHIFT
value|0
comment|/*  pause on host ring */
name|uint32_t
name|generic_features
decl_stmt|;
comment|/* 0x174 */
define|#
directive|define
name|PORT_HW_CFG_PAUSE_ON_HOST_RING_MASK
value|0x00000001
define|#
directive|define
name|PORT_HW_CFG_PAUSE_ON_HOST_RING_SHIFT
value|0
define|#
directive|define
name|PORT_HW_CFG_PAUSE_ON_HOST_RING_DISABLED
value|0x00000000
define|#
directive|define
name|PORT_HW_CFG_PAUSE_ON_HOST_RING_ENABLED
value|0x00000001
comment|/* SFP+ Tx Equalization: NIC recommended and tested value is 0xBEB2 	 * LOM recommended and tested value is 0xBEB2. Using a different 	 * value means using a value not tested by BRCM 	 */
name|uint32_t
name|sfi_tap_values
decl_stmt|;
comment|/* 0x178 */
define|#
directive|define
name|PORT_HW_CFG_TX_EQUALIZATION_MASK
value|0x0000FFFF
define|#
directive|define
name|PORT_HW_CFG_TX_EQUALIZATION_SHIFT
value|0
comment|/* SFP+ Tx driver broadcast IDRIVER: NIC recommended and tested 	 * value is 0x2. LOM recommended and tested value is 0x2. Using a 	 * different value means using a value not tested by BRCM 	 */
define|#
directive|define
name|PORT_HW_CFG_TX_DRV_BROADCAST_MASK
value|0x000F0000
define|#
directive|define
name|PORT_HW_CFG_TX_DRV_BROADCAST_SHIFT
value|16
comment|/*  Set non-default values for TXFIR in SFP mode. */
define|#
directive|define
name|PORT_HW_CFG_TX_DRV_IFIR_MASK
value|0x00F00000
define|#
directive|define
name|PORT_HW_CFG_TX_DRV_IFIR_SHIFT
value|20
comment|/*  Set non-default values for IPREDRIVER in SFP mode. */
define|#
directive|define
name|PORT_HW_CFG_TX_DRV_IPREDRIVER_MASK
value|0x0F000000
define|#
directive|define
name|PORT_HW_CFG_TX_DRV_IPREDRIVER_SHIFT
value|24
comment|/*  Set non-default values for POST2 in SFP mode. */
define|#
directive|define
name|PORT_HW_CFG_TX_DRV_POST2_MASK
value|0xF0000000
define|#
directive|define
name|PORT_HW_CFG_TX_DRV_POST2_SHIFT
value|28
name|uint32_t
name|reserved0
index|[
literal|5
index|]
decl_stmt|;
comment|/* 0x17c */
name|uint32_t
name|aeu_int_mask
decl_stmt|;
comment|/* 0x190 */
name|uint32_t
name|media_type
decl_stmt|;
comment|/* 0x194 */
define|#
directive|define
name|PORT_HW_CFG_MEDIA_TYPE_PHY0_MASK
value|0x000000FF
define|#
directive|define
name|PORT_HW_CFG_MEDIA_TYPE_PHY0_SHIFT
value|0
define|#
directive|define
name|PORT_HW_CFG_MEDIA_TYPE_PHY1_MASK
value|0x0000FF00
define|#
directive|define
name|PORT_HW_CFG_MEDIA_TYPE_PHY1_SHIFT
value|8
define|#
directive|define
name|PORT_HW_CFG_MEDIA_TYPE_PHY2_MASK
value|0x00FF0000
define|#
directive|define
name|PORT_HW_CFG_MEDIA_TYPE_PHY2_SHIFT
value|16
comment|/*  4 times 16 bits for all 4 lanes. In case external PHY is present 	      (not direct mode), those values will not take effect on the 4 XGXS 	      lanes. For some external PHYs (such as 8706 and 8726) the values 	      will be used to configure the external PHY  in those cases, not 	      all 4 values are needed. */
name|uint16_t
name|xgxs_config_rx
index|[
literal|4
index|]
decl_stmt|;
comment|/* 0x198 */
name|uint16_t
name|xgxs_config_tx
index|[
literal|4
index|]
decl_stmt|;
comment|/* 0x1A0 */
comment|/* For storing FCOE mac on shared memory */
name|uint32_t
name|fcoe_fip_mac_upper
decl_stmt|;
define|#
directive|define
name|PORT_HW_CFG_FCOE_UPPERMAC_MASK
value|0x0000ffff
define|#
directive|define
name|PORT_HW_CFG_FCOE_UPPERMAC_SHIFT
value|0
name|uint32_t
name|fcoe_fip_mac_lower
decl_stmt|;
name|uint32_t
name|fcoe_wwn_port_name_upper
decl_stmt|;
name|uint32_t
name|fcoe_wwn_port_name_lower
decl_stmt|;
name|uint32_t
name|fcoe_wwn_node_name_upper
decl_stmt|;
name|uint32_t
name|fcoe_wwn_node_name_lower
decl_stmt|;
comment|/*  wwpn for npiv enabled */
name|uint32_t
name|wwpn_for_npiv_config
decl_stmt|;
comment|/* 0x1C0 */
define|#
directive|define
name|PORT_HW_CFG_WWPN_FOR_NPIV_ENABLED_MASK
value|0x00000001
define|#
directive|define
name|PORT_HW_CFG_WWPN_FOR_NPIV_ENABLED_SHIFT
value|0
define|#
directive|define
name|PORT_HW_CFG_WWPN_FOR_NPIV_ENABLED_DISABLED
value|0x00000000
define|#
directive|define
name|PORT_HW_CFG_WWPN_FOR_NPIV_ENABLED_ENABLED
value|0x00000001
comment|/*  wwpn for npiv valid addresses */
name|uint32_t
name|wwpn_for_npiv_valid_addresses
decl_stmt|;
comment|/* 0x1C4 */
define|#
directive|define
name|PORT_HW_CFG_WWPN_FOR_NPIV_ADDRESS_BITMAP_MASK
value|0x0000FFFF
define|#
directive|define
name|PORT_HW_CFG_WWPN_FOR_NPIV_ADDRESS_BITMAP_SHIFT
value|0
name|struct
name|mac_addr
name|wwpn_for_niv_macs
index|[
literal|16
index|]
decl_stmt|;
comment|/* Reserved bits: 2272-2336 For storing FCOE mac on shared memory */
name|uint32_t
name|Reserved1
index|[
literal|14
index|]
decl_stmt|;
name|uint32_t
name|pf_allocation
decl_stmt|;
comment|/* 0x280 */
comment|/* number of vfs per PF, if 0 - sriov disabled */
define|#
directive|define
name|PORT_HW_CFG_NUMBER_OF_VFS_MASK
value|0x000000FF
define|#
directive|define
name|PORT_HW_CFG_NUMBER_OF_VFS_SHIFT
value|0
comment|/*  Enable RJ45 magjack pair swapping on 10GBase-T PHY (0=default), 	      84833 only */
name|uint32_t
name|xgbt_phy_cfg
decl_stmt|;
comment|/* 0x284 */
define|#
directive|define
name|PORT_HW_CFG_RJ45_PAIR_SWAP_MASK
value|0x000000FF
define|#
directive|define
name|PORT_HW_CFG_RJ45_PAIR_SWAP_SHIFT
value|0
name|uint32_t
name|default_cfg
decl_stmt|;
comment|/* 0x288 */
define|#
directive|define
name|PORT_HW_CFG_GPIO0_CONFIG_MASK
value|0x00000003
define|#
directive|define
name|PORT_HW_CFG_GPIO0_CONFIG_SHIFT
value|0
define|#
directive|define
name|PORT_HW_CFG_GPIO0_CONFIG_NA
value|0x00000000
define|#
directive|define
name|PORT_HW_CFG_GPIO0_CONFIG_LOW
value|0x00000001
define|#
directive|define
name|PORT_HW_CFG_GPIO0_CONFIG_HIGH
value|0x00000002
define|#
directive|define
name|PORT_HW_CFG_GPIO0_CONFIG_INPUT
value|0x00000003
define|#
directive|define
name|PORT_HW_CFG_GPIO1_CONFIG_MASK
value|0x0000000C
define|#
directive|define
name|PORT_HW_CFG_GPIO1_CONFIG_SHIFT
value|2
define|#
directive|define
name|PORT_HW_CFG_GPIO1_CONFIG_NA
value|0x00000000
define|#
directive|define
name|PORT_HW_CFG_GPIO1_CONFIG_LOW
value|0x00000004
define|#
directive|define
name|PORT_HW_CFG_GPIO1_CONFIG_HIGH
value|0x00000008
define|#
directive|define
name|PORT_HW_CFG_GPIO1_CONFIG_INPUT
value|0x0000000c
define|#
directive|define
name|PORT_HW_CFG_GPIO2_CONFIG_MASK
value|0x00000030
define|#
directive|define
name|PORT_HW_CFG_GPIO2_CONFIG_SHIFT
value|4
define|#
directive|define
name|PORT_HW_CFG_GPIO2_CONFIG_NA
value|0x00000000
define|#
directive|define
name|PORT_HW_CFG_GPIO2_CONFIG_LOW
value|0x00000010
define|#
directive|define
name|PORT_HW_CFG_GPIO2_CONFIG_HIGH
value|0x00000020
define|#
directive|define
name|PORT_HW_CFG_GPIO2_CONFIG_INPUT
value|0x00000030
define|#
directive|define
name|PORT_HW_CFG_GPIO3_CONFIG_MASK
value|0x000000C0
define|#
directive|define
name|PORT_HW_CFG_GPIO3_CONFIG_SHIFT
value|6
define|#
directive|define
name|PORT_HW_CFG_GPIO3_CONFIG_NA
value|0x00000000
define|#
directive|define
name|PORT_HW_CFG_GPIO3_CONFIG_LOW
value|0x00000040
define|#
directive|define
name|PORT_HW_CFG_GPIO3_CONFIG_HIGH
value|0x00000080
define|#
directive|define
name|PORT_HW_CFG_GPIO3_CONFIG_INPUT
value|0x000000c0
comment|/*  When KR link is required to be set to force which is not 	      KR-compliant, this parameter determine what is the trigger for it. 	      When GPIO is selected, low input will force the speed. Currently 	      default speed is 1G. In the future, it may be widen to select the 	      forced speed in with another parameter. Note when force-1G is 	      enabled, it override option 56: Link Speed option. */
define|#
directive|define
name|PORT_HW_CFG_FORCE_KR_ENABLER_MASK
value|0x00000F00
define|#
directive|define
name|PORT_HW_CFG_FORCE_KR_ENABLER_SHIFT
value|8
define|#
directive|define
name|PORT_HW_CFG_FORCE_KR_ENABLER_NOT_FORCED
value|0x00000000
define|#
directive|define
name|PORT_HW_CFG_FORCE_KR_ENABLER_GPIO0_P0
value|0x00000100
define|#
directive|define
name|PORT_HW_CFG_FORCE_KR_ENABLER_GPIO1_P0
value|0x00000200
define|#
directive|define
name|PORT_HW_CFG_FORCE_KR_ENABLER_GPIO2_P0
value|0x00000300
define|#
directive|define
name|PORT_HW_CFG_FORCE_KR_ENABLER_GPIO3_P0
value|0x00000400
define|#
directive|define
name|PORT_HW_CFG_FORCE_KR_ENABLER_GPIO0_P1
value|0x00000500
define|#
directive|define
name|PORT_HW_CFG_FORCE_KR_ENABLER_GPIO1_P1
value|0x00000600
define|#
directive|define
name|PORT_HW_CFG_FORCE_KR_ENABLER_GPIO2_P1
value|0x00000700
define|#
directive|define
name|PORT_HW_CFG_FORCE_KR_ENABLER_GPIO3_P1
value|0x00000800
define|#
directive|define
name|PORT_HW_CFG_FORCE_KR_ENABLER_FORCED
value|0x00000900
comment|/*  Enable to determine with which GPIO to reset the external phy */
define|#
directive|define
name|PORT_HW_CFG_EXT_PHY_GPIO_RST_MASK
value|0x000F0000
define|#
directive|define
name|PORT_HW_CFG_EXT_PHY_GPIO_RST_SHIFT
value|16
define|#
directive|define
name|PORT_HW_CFG_EXT_PHY_GPIO_RST_PHY_TYPE
value|0x00000000
define|#
directive|define
name|PORT_HW_CFG_EXT_PHY_GPIO_RST_GPIO0_P0
value|0x00010000
define|#
directive|define
name|PORT_HW_CFG_EXT_PHY_GPIO_RST_GPIO1_P0
value|0x00020000
define|#
directive|define
name|PORT_HW_CFG_EXT_PHY_GPIO_RST_GPIO2_P0
value|0x00030000
define|#
directive|define
name|PORT_HW_CFG_EXT_PHY_GPIO_RST_GPIO3_P0
value|0x00040000
define|#
directive|define
name|PORT_HW_CFG_EXT_PHY_GPIO_RST_GPIO0_P1
value|0x00050000
define|#
directive|define
name|PORT_HW_CFG_EXT_PHY_GPIO_RST_GPIO1_P1
value|0x00060000
define|#
directive|define
name|PORT_HW_CFG_EXT_PHY_GPIO_RST_GPIO2_P1
value|0x00070000
define|#
directive|define
name|PORT_HW_CFG_EXT_PHY_GPIO_RST_GPIO3_P1
value|0x00080000
comment|/*  Enable BAM on KR */
define|#
directive|define
name|PORT_HW_CFG_ENABLE_BAM_ON_KR_MASK
value|0x00100000
define|#
directive|define
name|PORT_HW_CFG_ENABLE_BAM_ON_KR_SHIFT
value|20
define|#
directive|define
name|PORT_HW_CFG_ENABLE_BAM_ON_KR_DISABLED
value|0x00000000
define|#
directive|define
name|PORT_HW_CFG_ENABLE_BAM_ON_KR_ENABLED
value|0x00100000
comment|/*  Enable Common Mode Sense */
define|#
directive|define
name|PORT_HW_CFG_ENABLE_CMS_MASK
value|0x00200000
define|#
directive|define
name|PORT_HW_CFG_ENABLE_CMS_SHIFT
value|21
define|#
directive|define
name|PORT_HW_CFG_ENABLE_CMS_DISABLED
value|0x00000000
define|#
directive|define
name|PORT_HW_CFG_ENABLE_CMS_ENABLED
value|0x00200000
comment|/*  Determine the Serdes electrical interface   */
define|#
directive|define
name|PORT_HW_CFG_NET_SERDES_IF_MASK
value|0x0F000000
define|#
directive|define
name|PORT_HW_CFG_NET_SERDES_IF_SHIFT
value|24
define|#
directive|define
name|PORT_HW_CFG_NET_SERDES_IF_SGMII
value|0x00000000
define|#
directive|define
name|PORT_HW_CFG_NET_SERDES_IF_XFI
value|0x01000000
define|#
directive|define
name|PORT_HW_CFG_NET_SERDES_IF_SFI
value|0x02000000
define|#
directive|define
name|PORT_HW_CFG_NET_SERDES_IF_KR
value|0x03000000
define|#
directive|define
name|PORT_HW_CFG_NET_SERDES_IF_DXGXS
value|0x04000000
define|#
directive|define
name|PORT_HW_CFG_NET_SERDES_IF_KR2
value|0x05000000
comment|/*  SFP+ main TAP and post TAP volumes */
define|#
directive|define
name|PORT_HW_CFG_TAP_LEVELS_MASK
value|0x70000000
define|#
directive|define
name|PORT_HW_CFG_TAP_LEVELS_SHIFT
value|28
define|#
directive|define
name|PORT_HW_CFG_TAP_LEVELS_POST_15_MAIN_43
value|0x00000000
define|#
directive|define
name|PORT_HW_CFG_TAP_LEVELS_POST_14_MAIN_44
value|0x10000000
define|#
directive|define
name|PORT_HW_CFG_TAP_LEVELS_POST_13_MAIN_45
value|0x20000000
define|#
directive|define
name|PORT_HW_CFG_TAP_LEVELS_POST_12_MAIN_46
value|0x30000000
define|#
directive|define
name|PORT_HW_CFG_TAP_LEVELS_POST_11_MAIN_47
value|0x40000000
define|#
directive|define
name|PORT_HW_CFG_TAP_LEVELS_POST_10_MAIN_48
value|0x50000000
name|uint32_t
name|speed_capability_mask2
decl_stmt|;
comment|/* 0x28C */
define|#
directive|define
name|PORT_HW_CFG_SPEED_CAPABILITY2_D3_MASK
value|0x0000FFFF
define|#
directive|define
name|PORT_HW_CFG_SPEED_CAPABILITY2_D3_SHIFT
value|0
define|#
directive|define
name|PORT_HW_CFG_SPEED_CAPABILITY2_D3_10M_FULL
value|0x00000001
define|#
directive|define
name|PORT_HW_CFG_SPEED_CAPABILITY2_D3_10M_HALF
value|0x00000002
define|#
directive|define
name|PORT_HW_CFG_SPEED_CAPABILITY2_D3_100M_HALF
value|0x00000004
define|#
directive|define
name|PORT_HW_CFG_SPEED_CAPABILITY2_D3_100M_FULL
value|0x00000008
define|#
directive|define
name|PORT_HW_CFG_SPEED_CAPABILITY2_D3_1G
value|0x00000010
define|#
directive|define
name|PORT_HW_CFG_SPEED_CAPABILITY2_D3_2_5G
value|0x00000020
define|#
directive|define
name|PORT_HW_CFG_SPEED_CAPABILITY2_D3_10G
value|0x00000040
define|#
directive|define
name|PORT_HW_CFG_SPEED_CAPABILITY2_D3_20G
value|0x00000080
define|#
directive|define
name|PORT_HW_CFG_SPEED_CAPABILITY2_D0_MASK
value|0xFFFF0000
define|#
directive|define
name|PORT_HW_CFG_SPEED_CAPABILITY2_D0_SHIFT
value|16
define|#
directive|define
name|PORT_HW_CFG_SPEED_CAPABILITY2_D0_10M_FULL
value|0x00010000
define|#
directive|define
name|PORT_HW_CFG_SPEED_CAPABILITY2_D0_10M_HALF
value|0x00020000
define|#
directive|define
name|PORT_HW_CFG_SPEED_CAPABILITY2_D0_100M_HALF
value|0x00040000
define|#
directive|define
name|PORT_HW_CFG_SPEED_CAPABILITY2_D0_100M_FULL
value|0x00080000
define|#
directive|define
name|PORT_HW_CFG_SPEED_CAPABILITY2_D0_1G
value|0x00100000
define|#
directive|define
name|PORT_HW_CFG_SPEED_CAPABILITY2_D0_2_5G
value|0x00200000
define|#
directive|define
name|PORT_HW_CFG_SPEED_CAPABILITY2_D0_10G
value|0x00400000
define|#
directive|define
name|PORT_HW_CFG_SPEED_CAPABILITY2_D0_20G
value|0x00800000
comment|/*  In the case where two media types (e.g. copper and fiber) are 	      present and electrically active at the same time, PHY Selection 	      will determine which of the two PHYs will be designated as the 	      Active PHY and used for a connection to the network.  */
name|uint32_t
name|multi_phy_config
decl_stmt|;
comment|/* 0x290 */
define|#
directive|define
name|PORT_HW_CFG_PHY_SELECTION_MASK
value|0x00000007
define|#
directive|define
name|PORT_HW_CFG_PHY_SELECTION_SHIFT
value|0
define|#
directive|define
name|PORT_HW_CFG_PHY_SELECTION_HARDWARE_DEFAULT
value|0x00000000
define|#
directive|define
name|PORT_HW_CFG_PHY_SELECTION_FIRST_PHY
value|0x00000001
define|#
directive|define
name|PORT_HW_CFG_PHY_SELECTION_SECOND_PHY
value|0x00000002
define|#
directive|define
name|PORT_HW_CFG_PHY_SELECTION_FIRST_PHY_PRIORITY
value|0x00000003
define|#
directive|define
name|PORT_HW_CFG_PHY_SELECTION_SECOND_PHY_PRIORITY
value|0x00000004
comment|/*  When enabled, all second phy nvram parameters will be swapped 	      with the first phy parameters */
define|#
directive|define
name|PORT_HW_CFG_PHY_SWAPPED_MASK
value|0x00000008
define|#
directive|define
name|PORT_HW_CFG_PHY_SWAPPED_SHIFT
value|3
define|#
directive|define
name|PORT_HW_CFG_PHY_SWAPPED_DISABLED
value|0x00000000
define|#
directive|define
name|PORT_HW_CFG_PHY_SWAPPED_ENABLED
value|0x00000008
comment|/*  Address of the second external phy */
name|uint32_t
name|external_phy_config2
decl_stmt|;
comment|/* 0x294 */
define|#
directive|define
name|PORT_HW_CFG_XGXS_EXT_PHY2_ADDR_MASK
value|0x000000FF
define|#
directive|define
name|PORT_HW_CFG_XGXS_EXT_PHY2_ADDR_SHIFT
value|0
comment|/*  The second XGXS external PHY type */
define|#
directive|define
name|PORT_HW_CFG_XGXS_EXT_PHY2_TYPE_MASK
value|0x0000FF00
define|#
directive|define
name|PORT_HW_CFG_XGXS_EXT_PHY2_TYPE_SHIFT
value|8
define|#
directive|define
name|PORT_HW_CFG_XGXS_EXT_PHY2_TYPE_DIRECT
value|0x00000000
define|#
directive|define
name|PORT_HW_CFG_XGXS_EXT_PHY2_TYPE_BCM8071
value|0x00000100
define|#
directive|define
name|PORT_HW_CFG_XGXS_EXT_PHY2_TYPE_BCM8072
value|0x00000200
define|#
directive|define
name|PORT_HW_CFG_XGXS_EXT_PHY2_TYPE_BCM8073
value|0x00000300
define|#
directive|define
name|PORT_HW_CFG_XGXS_EXT_PHY2_TYPE_BCM8705
value|0x00000400
define|#
directive|define
name|PORT_HW_CFG_XGXS_EXT_PHY2_TYPE_BCM8706
value|0x00000500
define|#
directive|define
name|PORT_HW_CFG_XGXS_EXT_PHY2_TYPE_BCM8726
value|0x00000600
define|#
directive|define
name|PORT_HW_CFG_XGXS_EXT_PHY2_TYPE_BCM8481
value|0x00000700
define|#
directive|define
name|PORT_HW_CFG_XGXS_EXT_PHY2_TYPE_SFX7101
value|0x00000800
define|#
directive|define
name|PORT_HW_CFG_XGXS_EXT_PHY2_TYPE_BCM8727
value|0x00000900
define|#
directive|define
name|PORT_HW_CFG_XGXS_EXT_PHY2_TYPE_BCM8727_NOC
value|0x00000a00
define|#
directive|define
name|PORT_HW_CFG_XGXS_EXT_PHY2_TYPE_BCM84823
value|0x00000b00
define|#
directive|define
name|PORT_HW_CFG_XGXS_EXT_PHY2_TYPE_BCM54640
value|0x00000c00
define|#
directive|define
name|PORT_HW_CFG_XGXS_EXT_PHY2_TYPE_BCM84833
value|0x00000d00
define|#
directive|define
name|PORT_HW_CFG_XGXS_EXT_PHY2_TYPE_BCM54618SE
value|0x00000e00
define|#
directive|define
name|PORT_HW_CFG_XGXS_EXT_PHY2_TYPE_BCM8722
value|0x00000f00
define|#
directive|define
name|PORT_HW_CFG_XGXS_EXT_PHY2_TYPE_BCM54616
value|0x00001000
define|#
directive|define
name|PORT_HW_CFG_XGXS_EXT_PHY2_TYPE_BCM84834
value|0x00001100
define|#
directive|define
name|PORT_HW_CFG_XGXS_EXT_PHY2_TYPE_BCM84858
value|0x00001200
define|#
directive|define
name|PORT_HW_CFG_XGXS_EXT_PHY2_TYPE_FAILURE
value|0x0000fd00
define|#
directive|define
name|PORT_HW_CFG_XGXS_EXT_PHY2_TYPE_NOT_CONN
value|0x0000ff00
comment|/*  4 times 16 bits for all 4 lanes. For some external PHYs (such as 	      8706, 8726 and 8727) not all 4 values are needed. */
name|uint16_t
name|xgxs_config2_rx
index|[
literal|4
index|]
decl_stmt|;
comment|/* 0x296 */
name|uint16_t
name|xgxs_config2_tx
index|[
literal|4
index|]
decl_stmt|;
comment|/* 0x2A0 */
name|uint32_t
name|lane_config
decl_stmt|;
define|#
directive|define
name|PORT_HW_CFG_LANE_SWAP_CFG_MASK
value|0x0000FFFF
define|#
directive|define
name|PORT_HW_CFG_LANE_SWAP_CFG_SHIFT
value|0
comment|/* AN and forced */
define|#
directive|define
name|PORT_HW_CFG_LANE_SWAP_CFG_01230123
value|0x00001b1b
comment|/* forced only */
define|#
directive|define
name|PORT_HW_CFG_LANE_SWAP_CFG_01233210
value|0x00001be4
comment|/* forced only */
define|#
directive|define
name|PORT_HW_CFG_LANE_SWAP_CFG_31203120
value|0x0000d8d8
comment|/* forced only */
define|#
directive|define
name|PORT_HW_CFG_LANE_SWAP_CFG_32103210
value|0x0000e4e4
define|#
directive|define
name|PORT_HW_CFG_LANE_SWAP_CFG_TX_MASK
value|0x000000FF
define|#
directive|define
name|PORT_HW_CFG_LANE_SWAP_CFG_TX_SHIFT
value|0
define|#
directive|define
name|PORT_HW_CFG_LANE_SWAP_CFG_RX_MASK
value|0x0000FF00
define|#
directive|define
name|PORT_HW_CFG_LANE_SWAP_CFG_RX_SHIFT
value|8
define|#
directive|define
name|PORT_HW_CFG_LANE_SWAP_CFG_MASTER_MASK
value|0x0000C000
define|#
directive|define
name|PORT_HW_CFG_LANE_SWAP_CFG_MASTER_SHIFT
value|14
comment|/*  Indicate whether to swap the external phy polarity */
define|#
directive|define
name|PORT_HW_CFG_SWAP_PHY_POLARITY_MASK
value|0x00010000
define|#
directive|define
name|PORT_HW_CFG_SWAP_PHY_POLARITY_DISABLED
value|0x00000000
define|#
directive|define
name|PORT_HW_CFG_SWAP_PHY_POLARITY_ENABLED
value|0x00010000
name|uint32_t
name|external_phy_config
decl_stmt|;
define|#
directive|define
name|PORT_HW_CFG_XGXS_EXT_PHY_ADDR_MASK
value|0x000000FF
define|#
directive|define
name|PORT_HW_CFG_XGXS_EXT_PHY_ADDR_SHIFT
value|0
define|#
directive|define
name|PORT_HW_CFG_XGXS_EXT_PHY_TYPE_MASK
value|0x0000FF00
define|#
directive|define
name|PORT_HW_CFG_XGXS_EXT_PHY_TYPE_SHIFT
value|8
define|#
directive|define
name|PORT_HW_CFG_XGXS_EXT_PHY_TYPE_DIRECT
value|0x00000000
define|#
directive|define
name|PORT_HW_CFG_XGXS_EXT_PHY_TYPE_BCM8071
value|0x00000100
define|#
directive|define
name|PORT_HW_CFG_XGXS_EXT_PHY_TYPE_BCM8072
value|0x00000200
define|#
directive|define
name|PORT_HW_CFG_XGXS_EXT_PHY_TYPE_BCM8073
value|0x00000300
define|#
directive|define
name|PORT_HW_CFG_XGXS_EXT_PHY_TYPE_BCM8705
value|0x00000400
define|#
directive|define
name|PORT_HW_CFG_XGXS_EXT_PHY_TYPE_BCM8706
value|0x00000500
define|#
directive|define
name|PORT_HW_CFG_XGXS_EXT_PHY_TYPE_BCM8726
value|0x00000600
define|#
directive|define
name|PORT_HW_CFG_XGXS_EXT_PHY_TYPE_BCM8481
value|0x00000700
define|#
directive|define
name|PORT_HW_CFG_XGXS_EXT_PHY_TYPE_SFX7101
value|0x00000800
define|#
directive|define
name|PORT_HW_CFG_XGXS_EXT_PHY_TYPE_BCM8727
value|0x00000900
define|#
directive|define
name|PORT_HW_CFG_XGXS_EXT_PHY_TYPE_BCM8727_NOC
value|0x00000a00
define|#
directive|define
name|PORT_HW_CFG_XGXS_EXT_PHY_TYPE_BCM84823
value|0x00000b00
define|#
directive|define
name|PORT_HW_CFG_XGXS_EXT_PHY_TYPE_BCM54640
value|0x00000c00
define|#
directive|define
name|PORT_HW_CFG_XGXS_EXT_PHY_TYPE_BCM84833
value|0x00000d00
define|#
directive|define
name|PORT_HW_CFG_XGXS_EXT_PHY_TYPE_BCM54618SE
value|0x00000e00
define|#
directive|define
name|PORT_HW_CFG_XGXS_EXT_PHY_TYPE_BCM8722
value|0x00000f00
define|#
directive|define
name|PORT_HW_CFG_XGXS_EXT_PHY_TYPE_BCM54616
value|0x00001000
define|#
directive|define
name|PORT_HW_CFG_XGXS_EXT_PHY_TYPE_BCM84834
value|0x00001100
define|#
directive|define
name|PORT_HW_CFG_XGXS_EXT_PHY_TYPE_BCM84858
value|0x00001200
define|#
directive|define
name|PORT_HW_CFG_XGXS_EXT_PHY_TYPE_DIRECT_WC
value|0x0000fc00
define|#
directive|define
name|PORT_HW_CFG_XGXS_EXT_PHY_TYPE_FAILURE
value|0x0000fd00
define|#
directive|define
name|PORT_HW_CFG_XGXS_EXT_PHY_TYPE_NOT_CONN
value|0x0000ff00
define|#
directive|define
name|PORT_HW_CFG_SERDES_EXT_PHY_ADDR_MASK
value|0x00FF0000
define|#
directive|define
name|PORT_HW_CFG_SERDES_EXT_PHY_ADDR_SHIFT
value|16
define|#
directive|define
name|PORT_HW_CFG_SERDES_EXT_PHY_TYPE_MASK
value|0xFF000000
define|#
directive|define
name|PORT_HW_CFG_SERDES_EXT_PHY_TYPE_SHIFT
value|24
define|#
directive|define
name|PORT_HW_CFG_SERDES_EXT_PHY_TYPE_DIRECT
value|0x00000000
define|#
directive|define
name|PORT_HW_CFG_SERDES_EXT_PHY_TYPE_BCM5482
value|0x01000000
define|#
directive|define
name|PORT_HW_CFG_SERDES_EXT_PHY_TYPE_DIRECT_SD
value|0x02000000
define|#
directive|define
name|PORT_HW_CFG_SERDES_EXT_PHY_TYPE_NOT_CONN
value|0xff000000
name|uint32_t
name|speed_capability_mask
decl_stmt|;
define|#
directive|define
name|PORT_HW_CFG_SPEED_CAPABILITY_D3_MASK
value|0x0000FFFF
define|#
directive|define
name|PORT_HW_CFG_SPEED_CAPABILITY_D3_SHIFT
value|0
define|#
directive|define
name|PORT_HW_CFG_SPEED_CAPABILITY_D3_10M_FULL
value|0x00000001
define|#
directive|define
name|PORT_HW_CFG_SPEED_CAPABILITY_D3_10M_HALF
value|0x00000002
define|#
directive|define
name|PORT_HW_CFG_SPEED_CAPABILITY_D3_100M_HALF
value|0x00000004
define|#
directive|define
name|PORT_HW_CFG_SPEED_CAPABILITY_D3_100M_FULL
value|0x00000008
define|#
directive|define
name|PORT_HW_CFG_SPEED_CAPABILITY_D3_1G
value|0x00000010
define|#
directive|define
name|PORT_HW_CFG_SPEED_CAPABILITY_D3_2_5G
value|0x00000020
define|#
directive|define
name|PORT_HW_CFG_SPEED_CAPABILITY_D3_10G
value|0x00000040
define|#
directive|define
name|PORT_HW_CFG_SPEED_CAPABILITY_D3_20G
value|0x00000080
define|#
directive|define
name|PORT_HW_CFG_SPEED_CAPABILITY_D3_RESERVED
value|0x0000f000
define|#
directive|define
name|PORT_HW_CFG_SPEED_CAPABILITY_D0_MASK
value|0xFFFF0000
define|#
directive|define
name|PORT_HW_CFG_SPEED_CAPABILITY_D0_SHIFT
value|16
define|#
directive|define
name|PORT_HW_CFG_SPEED_CAPABILITY_D0_10M_FULL
value|0x00010000
define|#
directive|define
name|PORT_HW_CFG_SPEED_CAPABILITY_D0_10M_HALF
value|0x00020000
define|#
directive|define
name|PORT_HW_CFG_SPEED_CAPABILITY_D0_100M_HALF
value|0x00040000
define|#
directive|define
name|PORT_HW_CFG_SPEED_CAPABILITY_D0_100M_FULL
value|0x00080000
define|#
directive|define
name|PORT_HW_CFG_SPEED_CAPABILITY_D0_1G
value|0x00100000
define|#
directive|define
name|PORT_HW_CFG_SPEED_CAPABILITY_D0_2_5G
value|0x00200000
define|#
directive|define
name|PORT_HW_CFG_SPEED_CAPABILITY_D0_10G
value|0x00400000
define|#
directive|define
name|PORT_HW_CFG_SPEED_CAPABILITY_D0_20G
value|0x00800000
define|#
directive|define
name|PORT_HW_CFG_SPEED_CAPABILITY_D0_RESERVED
value|0xf0000000
comment|/*  A place to hold the original MAC address as a backup */
name|uint32_t
name|backup_mac_upper
decl_stmt|;
comment|/* 0x2B4 */
name|uint32_t
name|backup_mac_lower
decl_stmt|;
comment|/* 0x2B8 */
block|}
struct|;
end_struct

begin_comment
comment|/****************************************************************************  * Shared Feature configuration                                             *  ****************************************************************************/
end_comment

begin_struct
struct|struct
name|shared_feat_cfg
block|{
comment|/* NVRAM Offset */
name|uint32_t
name|config
decl_stmt|;
comment|/* 0x450 */
define|#
directive|define
name|SHARED_FEATURE_BMC_ECHO_MODE_EN
value|0x00000001
comment|/* Use NVRAM values instead of HW default values */
define|#
directive|define
name|SHARED_FEAT_CFG_OVERRIDE_PREEMPHASIS_CFG_MASK
define|\
value|0x00000002
define|#
directive|define
name|SHARED_FEAT_CFG_OVERRIDE_PREEMPHASIS_CFG_DISABLED
define|\
value|0x00000000
define|#
directive|define
name|SHARED_FEAT_CFG_OVERRIDE_PREEMPHASIS_CFG_ENABLED
define|\
value|0x00000002
define|#
directive|define
name|SHARED_FEAT_CFG_NCSI_ID_METHOD_MASK
value|0x00000008
define|#
directive|define
name|SHARED_FEAT_CFG_NCSI_ID_METHOD_SPIO
value|0x00000000
define|#
directive|define
name|SHARED_FEAT_CFG_NCSI_ID_METHOD_NVRAM
value|0x00000008
define|#
directive|define
name|SHARED_FEAT_CFG_NCSI_ID_MASK
value|0x00000030
define|#
directive|define
name|SHARED_FEAT_CFG_NCSI_ID_SHIFT
value|4
comment|/*  Override the OTP back to single function mode. When using GPIO, 	      high means only SF, 0 is according to CLP configuration */
define|#
directive|define
name|SHARED_FEAT_CFG_FORCE_SF_MODE_MASK
value|0x00000700
define|#
directive|define
name|SHARED_FEAT_CFG_FORCE_SF_MODE_SHIFT
value|8
define|#
directive|define
name|SHARED_FEAT_CFG_FORCE_SF_MODE_MF_ALLOWED
value|0x00000000
define|#
directive|define
name|SHARED_FEAT_CFG_FORCE_SF_MODE_FORCED_SF
value|0x00000100
define|#
directive|define
name|SHARED_FEAT_CFG_FORCE_SF_MODE_SPIO4
value|0x00000200
define|#
directive|define
name|SHARED_FEAT_CFG_FORCE_SF_MODE_SWITCH_INDEPT
value|0x00000300
define|#
directive|define
name|SHARED_FEAT_CFG_FORCE_SF_MODE_AFEX_MODE
value|0x00000400
define|#
directive|define
name|SHARED_FEAT_CFG_FORCE_SF_MODE_BD_MODE
value|0x00000500
define|#
directive|define
name|SHARED_FEAT_CFG_FORCE_SF_MODE_UFP_MODE
value|0x00000600
define|#
directive|define
name|SHARED_FEAT_CFG_FORCE_SF_MODE_EXTENDED_MODE
value|0x00000700
comment|/*  Act as if the FCoE license is invalid */
define|#
directive|define
name|SHARED_FEAT_CFG_PREVENT_FCOE
value|0x00001000
comment|/*  Force FLR capability to all ports */
define|#
directive|define
name|SHARED_FEAT_CFG_FORCE_FLR_CAPABILITY
value|0x00002000
comment|/*  Act as if the iSCSI license is invalid */
define|#
directive|define
name|SHARED_FEAT_CFG_PREVENT_ISCSI_MASK
value|0x00004000
define|#
directive|define
name|SHARED_FEAT_CFG_PREVENT_ISCSI_SHIFT
value|14
define|#
directive|define
name|SHARED_FEAT_CFG_PREVENT_ISCSI_DISABLED
value|0x00000000
define|#
directive|define
name|SHARED_FEAT_CFG_PREVENT_ISCSI_ENABLED
value|0x00004000
comment|/* The interval in seconds between sending LLDP packets. Set to zero 	   to disable the feature */
define|#
directive|define
name|SHARED_FEAT_CFG_LLDP_XMIT_INTERVAL_MASK
value|0x00FF0000
define|#
directive|define
name|SHARED_FEAT_CFG_LLDP_XMIT_INTERVAL_SHIFT
value|16
comment|/* The assigned device type ID for LLDP usage */
define|#
directive|define
name|SHARED_FEAT_CFG_LLDP_DEVICE_TYPE_ID_MASK
value|0xFF000000
define|#
directive|define
name|SHARED_FEAT_CFG_LLDP_DEVICE_TYPE_ID_SHIFT
value|24
block|}
struct|;
end_struct

begin_comment
comment|/****************************************************************************  * Port Feature configuration                                               *  ****************************************************************************/
end_comment

begin_struct
struct|struct
name|port_feat_cfg
block|{
comment|/* port 0: 0x454  port 1: 0x4c8 */
name|uint32_t
name|config
decl_stmt|;
define|#
directive|define
name|PORT_FEAT_CFG_BAR1_SIZE_MASK
value|0x0000000F
define|#
directive|define
name|PORT_FEAT_CFG_BAR1_SIZE_SHIFT
value|0
define|#
directive|define
name|PORT_FEAT_CFG_BAR1_SIZE_DISABLED
value|0x00000000
define|#
directive|define
name|PORT_FEAT_CFG_BAR1_SIZE_64K
value|0x00000001
define|#
directive|define
name|PORT_FEAT_CFG_BAR1_SIZE_128K
value|0x00000002
define|#
directive|define
name|PORT_FEAT_CFG_BAR1_SIZE_256K
value|0x00000003
define|#
directive|define
name|PORT_FEAT_CFG_BAR1_SIZE_512K
value|0x00000004
define|#
directive|define
name|PORT_FEAT_CFG_BAR1_SIZE_1M
value|0x00000005
define|#
directive|define
name|PORT_FEAT_CFG_BAR1_SIZE_2M
value|0x00000006
define|#
directive|define
name|PORT_FEAT_CFG_BAR1_SIZE_4M
value|0x00000007
define|#
directive|define
name|PORT_FEAT_CFG_BAR1_SIZE_8M
value|0x00000008
define|#
directive|define
name|PORT_FEAT_CFG_BAR1_SIZE_16M
value|0x00000009
define|#
directive|define
name|PORT_FEAT_CFG_BAR1_SIZE_32M
value|0x0000000a
define|#
directive|define
name|PORT_FEAT_CFG_BAR1_SIZE_64M
value|0x0000000b
define|#
directive|define
name|PORT_FEAT_CFG_BAR1_SIZE_128M
value|0x0000000c
define|#
directive|define
name|PORT_FEAT_CFG_BAR1_SIZE_256M
value|0x0000000d
define|#
directive|define
name|PORT_FEAT_CFG_BAR1_SIZE_512M
value|0x0000000e
define|#
directive|define
name|PORT_FEAT_CFG_BAR1_SIZE_1G
value|0x0000000f
define|#
directive|define
name|PORT_FEAT_CFG_BAR2_SIZE_MASK
value|0x000000F0
define|#
directive|define
name|PORT_FEAT_CFG_BAR2_SIZE_SHIFT
value|4
define|#
directive|define
name|PORT_FEAT_CFG_BAR2_SIZE_DISABLED
value|0x00000000
define|#
directive|define
name|PORT_FEAT_CFG_BAR2_SIZE_64K
value|0x00000010
define|#
directive|define
name|PORT_FEAT_CFG_BAR2_SIZE_128K
value|0x00000020
define|#
directive|define
name|PORT_FEAT_CFG_BAR2_SIZE_256K
value|0x00000030
define|#
directive|define
name|PORT_FEAT_CFG_BAR2_SIZE_512K
value|0x00000040
define|#
directive|define
name|PORT_FEAT_CFG_BAR2_SIZE_1M
value|0x00000050
define|#
directive|define
name|PORT_FEAT_CFG_BAR2_SIZE_2M
value|0x00000060
define|#
directive|define
name|PORT_FEAT_CFG_BAR2_SIZE_4M
value|0x00000070
define|#
directive|define
name|PORT_FEAT_CFG_BAR2_SIZE_8M
value|0x00000080
define|#
directive|define
name|PORT_FEAT_CFG_BAR2_SIZE_16M
value|0x00000090
define|#
directive|define
name|PORT_FEAT_CFG_BAR2_SIZE_32M
value|0x000000a0
define|#
directive|define
name|PORT_FEAT_CFG_BAR2_SIZE_64M
value|0x000000b0
define|#
directive|define
name|PORT_FEAT_CFG_BAR2_SIZE_128M
value|0x000000c0
define|#
directive|define
name|PORT_FEAT_CFG_BAR2_SIZE_256M
value|0x000000d0
define|#
directive|define
name|PORT_FEAT_CFG_BAR2_SIZE_512M
value|0x000000e0
define|#
directive|define
name|PORT_FEAT_CFG_BAR2_SIZE_1G
value|0x000000f0
define|#
directive|define
name|PORT_FEAT_CFG_DCBX_MASK
value|0x00000100
define|#
directive|define
name|PORT_FEAT_CFG_DCBX_DISABLED
value|0x00000000
define|#
directive|define
name|PORT_FEAT_CFG_DCBX_ENABLED
value|0x00000100
define|#
directive|define
name|PORT_FEAT_CFG_AUTOGREEEN_MASK
value|0x00000200
define|#
directive|define
name|PORT_FEAT_CFG_AUTOGREEEN_SHIFT
value|9
define|#
directive|define
name|PORT_FEAT_CFG_AUTOGREEEN_DISABLED
value|0x00000000
define|#
directive|define
name|PORT_FEAT_CFG_AUTOGREEEN_ENABLED
value|0x00000200
define|#
directive|define
name|PORT_FEAT_CFG_STORAGE_PERSONALITY_MASK
value|0x00000C00
define|#
directive|define
name|PORT_FEAT_CFG_STORAGE_PERSONALITY_SHIFT
value|10
define|#
directive|define
name|PORT_FEAT_CFG_STORAGE_PERSONALITY_DEFAULT
value|0x00000000
define|#
directive|define
name|PORT_FEAT_CFG_STORAGE_PERSONALITY_FCOE
value|0x00000400
define|#
directive|define
name|PORT_FEAT_CFG_STORAGE_PERSONALITY_ISCSI
value|0x00000800
define|#
directive|define
name|PORT_FEAT_CFG_STORAGE_PERSONALITY_BOTH
value|0x00000c00
define|#
directive|define
name|PORT_FEATURE_EN_SIZE_MASK
value|0x0f000000
define|#
directive|define
name|PORT_FEATURE_EN_SIZE_SHIFT
value|24
define|#
directive|define
name|PORT_FEATURE_WOL_ENABLED
value|0x01000000
define|#
directive|define
name|PORT_FEATURE_MBA_ENABLED
value|0x02000000
define|#
directive|define
name|PORT_FEATURE_MFW_ENABLED
value|0x04000000
comment|/* Advertise expansion ROM even if MBA is disabled */
define|#
directive|define
name|PORT_FEAT_CFG_FORCE_EXP_ROM_ADV_MASK
value|0x08000000
define|#
directive|define
name|PORT_FEAT_CFG_FORCE_EXP_ROM_ADV_DISABLED
value|0x00000000
define|#
directive|define
name|PORT_FEAT_CFG_FORCE_EXP_ROM_ADV_ENABLED
value|0x08000000
comment|/* Check the optic vendor via i2c against a list of approved modules 	   in a separate nvram image */
define|#
directive|define
name|PORT_FEAT_CFG_OPT_MDL_ENFRCMNT_MASK
value|0xE0000000
define|#
directive|define
name|PORT_FEAT_CFG_OPT_MDL_ENFRCMNT_SHIFT
value|29
define|#
directive|define
name|PORT_FEAT_CFG_OPT_MDL_ENFRCMNT_NO_ENFORCEMENT
define|\
value|0x00000000
define|#
directive|define
name|PORT_FEAT_CFG_OPT_MDL_ENFRCMNT_DISABLE_TX_LASER
define|\
value|0x20000000
define|#
directive|define
name|PORT_FEAT_CFG_OPT_MDL_ENFRCMNT_WARNING_MSG
value|0x40000000
define|#
directive|define
name|PORT_FEAT_CFG_OPT_MDL_ENFRCMNT_POWER_DOWN
value|0x60000000
name|uint32_t
name|wol_config
decl_stmt|;
comment|/* Default is used when driver sets to "auto" mode */
define|#
directive|define
name|PORT_FEATURE_WOL_ACPI_UPON_MGMT
value|0x00000010
name|uint32_t
name|mba_config
decl_stmt|;
define|#
directive|define
name|PORT_FEATURE_MBA_BOOT_AGENT_TYPE_MASK
value|0x00000007
define|#
directive|define
name|PORT_FEATURE_MBA_BOOT_AGENT_TYPE_SHIFT
value|0
define|#
directive|define
name|PORT_FEATURE_MBA_BOOT_AGENT_TYPE_PXE
value|0x00000000
define|#
directive|define
name|PORT_FEATURE_MBA_BOOT_AGENT_TYPE_RPL
value|0x00000001
define|#
directive|define
name|PORT_FEATURE_MBA_BOOT_AGENT_TYPE_BOOTP
value|0x00000002
define|#
directive|define
name|PORT_FEATURE_MBA_BOOT_AGENT_TYPE_ISCSIB
value|0x00000003
define|#
directive|define
name|PORT_FEATURE_MBA_BOOT_AGENT_TYPE_FCOE_BOOT
value|0x00000004
define|#
directive|define
name|PORT_FEATURE_MBA_BOOT_AGENT_TYPE_NONE
value|0x00000007
define|#
directive|define
name|PORT_FEATURE_MBA_BOOT_RETRY_MASK
value|0x00000038
define|#
directive|define
name|PORT_FEATURE_MBA_BOOT_RETRY_SHIFT
value|3
define|#
directive|define
name|PORT_FEATURE_MBA_SETUP_PROMPT_ENABLE
value|0x00000400
define|#
directive|define
name|PORT_FEATURE_MBA_HOTKEY_MASK
value|0x00000800
define|#
directive|define
name|PORT_FEATURE_MBA_HOTKEY_CTRL_S
value|0x00000000
define|#
directive|define
name|PORT_FEATURE_MBA_HOTKEY_CTRL_B
value|0x00000800
define|#
directive|define
name|PORT_FEATURE_MBA_EXP_ROM_SIZE_MASK
value|0x000FF000
define|#
directive|define
name|PORT_FEATURE_MBA_EXP_ROM_SIZE_SHIFT
value|12
define|#
directive|define
name|PORT_FEATURE_MBA_EXP_ROM_SIZE_DISABLED
value|0x00000000
define|#
directive|define
name|PORT_FEATURE_MBA_EXP_ROM_SIZE_2K
value|0x00001000
define|#
directive|define
name|PORT_FEATURE_MBA_EXP_ROM_SIZE_4K
value|0x00002000
define|#
directive|define
name|PORT_FEATURE_MBA_EXP_ROM_SIZE_8K
value|0x00003000
define|#
directive|define
name|PORT_FEATURE_MBA_EXP_ROM_SIZE_16K
value|0x00004000
define|#
directive|define
name|PORT_FEATURE_MBA_EXP_ROM_SIZE_32K
value|0x00005000
define|#
directive|define
name|PORT_FEATURE_MBA_EXP_ROM_SIZE_64K
value|0x00006000
define|#
directive|define
name|PORT_FEATURE_MBA_EXP_ROM_SIZE_128K
value|0x00007000
define|#
directive|define
name|PORT_FEATURE_MBA_EXP_ROM_SIZE_256K
value|0x00008000
define|#
directive|define
name|PORT_FEATURE_MBA_EXP_ROM_SIZE_512K
value|0x00009000
define|#
directive|define
name|PORT_FEATURE_MBA_EXP_ROM_SIZE_1M
value|0x0000a000
define|#
directive|define
name|PORT_FEATURE_MBA_EXP_ROM_SIZE_2M
value|0x0000b000
define|#
directive|define
name|PORT_FEATURE_MBA_EXP_ROM_SIZE_4M
value|0x0000c000
define|#
directive|define
name|PORT_FEATURE_MBA_EXP_ROM_SIZE_8M
value|0x0000d000
define|#
directive|define
name|PORT_FEATURE_MBA_EXP_ROM_SIZE_16M
value|0x0000e000
define|#
directive|define
name|PORT_FEATURE_MBA_EXP_ROM_SIZE_32M
value|0x0000f000
define|#
directive|define
name|PORT_FEATURE_MBA_MSG_TIMEOUT_MASK
value|0x00F00000
define|#
directive|define
name|PORT_FEATURE_MBA_MSG_TIMEOUT_SHIFT
value|20
define|#
directive|define
name|PORT_FEATURE_MBA_BIOS_BOOTSTRAP_MASK
value|0x03000000
define|#
directive|define
name|PORT_FEATURE_MBA_BIOS_BOOTSTRAP_SHIFT
value|24
define|#
directive|define
name|PORT_FEATURE_MBA_BIOS_BOOTSTRAP_AUTO
value|0x00000000
define|#
directive|define
name|PORT_FEATURE_MBA_BIOS_BOOTSTRAP_BBS
value|0x01000000
define|#
directive|define
name|PORT_FEATURE_MBA_BIOS_BOOTSTRAP_INT18H
value|0x02000000
define|#
directive|define
name|PORT_FEATURE_MBA_BIOS_BOOTSTRAP_INT19H
value|0x03000000
define|#
directive|define
name|PORT_FEATURE_MBA_LINK_SPEED_MASK
value|0x3C000000
define|#
directive|define
name|PORT_FEATURE_MBA_LINK_SPEED_SHIFT
value|26
define|#
directive|define
name|PORT_FEATURE_MBA_LINK_SPEED_AUTO
value|0x00000000
define|#
directive|define
name|PORT_FEATURE_MBA_LINK_SPEED_10M_HALF
value|0x04000000
define|#
directive|define
name|PORT_FEATURE_MBA_LINK_SPEED_10M_FULL
value|0x08000000
define|#
directive|define
name|PORT_FEATURE_MBA_LINK_SPEED_100M_HALF
value|0x0c000000
define|#
directive|define
name|PORT_FEATURE_MBA_LINK_SPEED_100M_FULL
value|0x10000000
define|#
directive|define
name|PORT_FEATURE_MBA_LINK_SPEED_1G
value|0x14000000
define|#
directive|define
name|PORT_FEATURE_MBA_LINK_SPEED_2_5G
value|0x18000000
define|#
directive|define
name|PORT_FEATURE_MBA_LINK_SPEED_10G
value|0x1c000000
define|#
directive|define
name|PORT_FEATURE_MBA_LINK_SPEED_20G
value|0x20000000
name|uint32_t
name|Reserved0
decl_stmt|;
comment|/* 0x460 */
name|uint32_t
name|mba_vlan_cfg
decl_stmt|;
define|#
directive|define
name|PORT_FEATURE_MBA_VLAN_TAG_MASK
value|0x0000FFFF
define|#
directive|define
name|PORT_FEATURE_MBA_VLAN_TAG_SHIFT
value|0
define|#
directive|define
name|PORT_FEATURE_MBA_VLAN_EN
value|0x00010000
define|#
directive|define
name|PORT_FEATUTE_BOFM_CFGD_EN
value|0x00020000
define|#
directive|define
name|PORT_FEATURE_BOFM_CFGD_FTGT
value|0x00040000
define|#
directive|define
name|PORT_FEATURE_BOFM_CFGD_VEN
value|0x00080000
name|uint32_t
name|Reserved1
decl_stmt|;
name|uint32_t
name|smbus_config
decl_stmt|;
define|#
directive|define
name|PORT_FEATURE_SMBUS_ADDR_MASK
value|0x000000fe
define|#
directive|define
name|PORT_FEATURE_SMBUS_ADDR_SHIFT
value|1
name|uint32_t
name|vf_config
decl_stmt|;
define|#
directive|define
name|PORT_FEAT_CFG_VF_BAR2_SIZE_MASK
value|0x0000000F
define|#
directive|define
name|PORT_FEAT_CFG_VF_BAR2_SIZE_SHIFT
value|0
define|#
directive|define
name|PORT_FEAT_CFG_VF_BAR2_SIZE_DISABLED
value|0x00000000
define|#
directive|define
name|PORT_FEAT_CFG_VF_BAR2_SIZE_4K
value|0x00000001
define|#
directive|define
name|PORT_FEAT_CFG_VF_BAR2_SIZE_8K
value|0x00000002
define|#
directive|define
name|PORT_FEAT_CFG_VF_BAR2_SIZE_16K
value|0x00000003
define|#
directive|define
name|PORT_FEAT_CFG_VF_BAR2_SIZE_32K
value|0x00000004
define|#
directive|define
name|PORT_FEAT_CFG_VF_BAR2_SIZE_64K
value|0x00000005
define|#
directive|define
name|PORT_FEAT_CFG_VF_BAR2_SIZE_128K
value|0x00000006
define|#
directive|define
name|PORT_FEAT_CFG_VF_BAR2_SIZE_256K
value|0x00000007
define|#
directive|define
name|PORT_FEAT_CFG_VF_BAR2_SIZE_512K
value|0x00000008
define|#
directive|define
name|PORT_FEAT_CFG_VF_BAR2_SIZE_1M
value|0x00000009
define|#
directive|define
name|PORT_FEAT_CFG_VF_BAR2_SIZE_2M
value|0x0000000a
define|#
directive|define
name|PORT_FEAT_CFG_VF_BAR2_SIZE_4M
value|0x0000000b
define|#
directive|define
name|PORT_FEAT_CFG_VF_BAR2_SIZE_8M
value|0x0000000c
define|#
directive|define
name|PORT_FEAT_CFG_VF_BAR2_SIZE_16M
value|0x0000000d
define|#
directive|define
name|PORT_FEAT_CFG_VF_BAR2_SIZE_32M
value|0x0000000e
define|#
directive|define
name|PORT_FEAT_CFG_VF_BAR2_SIZE_64M
value|0x0000000f
name|uint32_t
name|link_config
decl_stmt|;
comment|/* Used as HW defaults for the driver */
define|#
directive|define
name|PORT_FEATURE_FLOW_CONTROL_MASK
value|0x00000700
define|#
directive|define
name|PORT_FEATURE_FLOW_CONTROL_SHIFT
value|8
define|#
directive|define
name|PORT_FEATURE_FLOW_CONTROL_AUTO
value|0x00000000
define|#
directive|define
name|PORT_FEATURE_FLOW_CONTROL_TX
value|0x00000100
define|#
directive|define
name|PORT_FEATURE_FLOW_CONTROL_RX
value|0x00000200
define|#
directive|define
name|PORT_FEATURE_FLOW_CONTROL_BOTH
value|0x00000300
define|#
directive|define
name|PORT_FEATURE_FLOW_CONTROL_NONE
value|0x00000400
define|#
directive|define
name|PORT_FEATURE_FLOW_CONTROL_SAFC_RX
value|0x00000500
define|#
directive|define
name|PORT_FEATURE_FLOW_CONTROL_SAFC_TX
value|0x00000600
define|#
directive|define
name|PORT_FEATURE_FLOW_CONTROL_SAFC_BOTH
value|0x00000700
define|#
directive|define
name|PORT_FEATURE_LINK_SPEED_MASK
value|0x000F0000
define|#
directive|define
name|PORT_FEATURE_LINK_SPEED_SHIFT
value|16
define|#
directive|define
name|PORT_FEATURE_LINK_SPEED_AUTO
value|0x00000000
define|#
directive|define
name|PORT_FEATURE_LINK_SPEED_10M_HALF
value|0x00010000
define|#
directive|define
name|PORT_FEATURE_LINK_SPEED_10M_FULL
value|0x00020000
define|#
directive|define
name|PORT_FEATURE_LINK_SPEED_100M_HALF
value|0x00030000
define|#
directive|define
name|PORT_FEATURE_LINK_SPEED_100M_FULL
value|0x00040000
define|#
directive|define
name|PORT_FEATURE_LINK_SPEED_1G
value|0x00050000
define|#
directive|define
name|PORT_FEATURE_LINK_SPEED_2_5G
value|0x00060000
define|#
directive|define
name|PORT_FEATURE_LINK_SPEED_10G_CX4
value|0x00070000
define|#
directive|define
name|PORT_FEATURE_LINK_SPEED_20G
value|0x00080000
define|#
directive|define
name|PORT_FEATURE_CONNECTED_SWITCH_MASK
value|0x03000000
define|#
directive|define
name|PORT_FEATURE_CONNECTED_SWITCH_SHIFT
value|24
comment|/* (forced) low speed switch (< 10G) */
define|#
directive|define
name|PORT_FEATURE_CON_SWITCH_1G_SWITCH
value|0x00000000
comment|/* (forced) high speed switch (>= 10G) */
define|#
directive|define
name|PORT_FEATURE_CON_SWITCH_10G_SWITCH
value|0x01000000
define|#
directive|define
name|PORT_FEATURE_CON_SWITCH_AUTO_DETECT
value|0x02000000
define|#
directive|define
name|PORT_FEATURE_CON_SWITCH_ONE_TIME_DETECT
value|0x03000000
comment|/* The default for MCP link configuration, 	   uses the same defines as link_config */
name|uint32_t
name|mfw_wol_link_cfg
decl_stmt|;
comment|/* The default for the driver of the second external phy, 	   uses the same defines as link_config */
name|uint32_t
name|link_config2
decl_stmt|;
comment|/* 0x47C */
comment|/* The default for MCP of the second external phy, 	   uses the same defines as link_config */
name|uint32_t
name|mfw_wol_link_cfg2
decl_stmt|;
comment|/* 0x480 */
comment|/*  EEE power saving mode */
name|uint32_t
name|eee_power_mode
decl_stmt|;
comment|/* 0x484 */
define|#
directive|define
name|PORT_FEAT_CFG_EEE_POWER_MODE_MASK
value|0x000000FF
define|#
directive|define
name|PORT_FEAT_CFG_EEE_POWER_MODE_SHIFT
value|0
define|#
directive|define
name|PORT_FEAT_CFG_EEE_POWER_MODE_DISABLED
value|0x00000000
define|#
directive|define
name|PORT_FEAT_CFG_EEE_POWER_MODE_BALANCED
value|0x00000001
define|#
directive|define
name|PORT_FEAT_CFG_EEE_POWER_MODE_AGGRESSIVE
value|0x00000002
define|#
directive|define
name|PORT_FEAT_CFG_EEE_POWER_MODE_LOW_LATENCY
value|0x00000003
name|uint32_t
name|Reserved2
index|[
literal|16
index|]
decl_stmt|;
comment|/* 0x48C */
block|}
struct|;
end_struct

begin_comment
comment|/****************************************************************************  * Device Information                                                       *  ****************************************************************************/
end_comment

begin_struct
struct|struct
name|shm_dev_info
block|{
comment|/* size */
name|uint32_t
name|bc_rev
decl_stmt|;
comment|/* 8 bits each: major, minor, build */
comment|/* 4 */
name|struct
name|shared_hw_cfg
name|shared_hw_config
decl_stmt|;
comment|/* 40 */
name|struct
name|port_hw_cfg
name|port_hw_config
index|[
name|PORT_MAX
index|]
decl_stmt|;
comment|/* 400*2=800 */
name|struct
name|shared_feat_cfg
name|shared_feature_config
decl_stmt|;
comment|/* 4 */
name|struct
name|port_feat_cfg
name|port_feature_config
index|[
name|PORT_MAX
index|]
decl_stmt|;
comment|/* 116*2=232 */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|extended_dev_info_shared_cfg
block|{
comment|/* NVRAM OFFSET */
comment|/*  Threshold in celcius to start using the fan */
name|uint32_t
name|temperature_monitor1
decl_stmt|;
comment|/* 0x4000 */
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_TEMP_FAN_THRESH_MASK
value|0x0000007F
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_TEMP_FAN_THRESH_SHIFT
value|0
comment|/*  Threshold in celcius to shut down the board */
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_TEMP_SHUT_THRESH_MASK
value|0x00007F00
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_TEMP_SHUT_THRESH_SHIFT
value|8
comment|/*  EPIO of fan temperature status */
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_TEMP_FAN_EPIO_MASK
value|0x00FF0000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_TEMP_FAN_EPIO_SHIFT
value|16
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_TEMP_FAN_EPIO_NA
value|0x00000000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_TEMP_FAN_EPIO_EPIO0
value|0x00010000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_TEMP_FAN_EPIO_EPIO1
value|0x00020000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_TEMP_FAN_EPIO_EPIO2
value|0x00030000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_TEMP_FAN_EPIO_EPIO3
value|0x00040000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_TEMP_FAN_EPIO_EPIO4
value|0x00050000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_TEMP_FAN_EPIO_EPIO5
value|0x00060000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_TEMP_FAN_EPIO_EPIO6
value|0x00070000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_TEMP_FAN_EPIO_EPIO7
value|0x00080000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_TEMP_FAN_EPIO_EPIO8
value|0x00090000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_TEMP_FAN_EPIO_EPIO9
value|0x000a0000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_TEMP_FAN_EPIO_EPIO10
value|0x000b0000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_TEMP_FAN_EPIO_EPIO11
value|0x000c0000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_TEMP_FAN_EPIO_EPIO12
value|0x000d0000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_TEMP_FAN_EPIO_EPIO13
value|0x000e0000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_TEMP_FAN_EPIO_EPIO14
value|0x000f0000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_TEMP_FAN_EPIO_EPIO15
value|0x00100000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_TEMP_FAN_EPIO_EPIO16
value|0x00110000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_TEMP_FAN_EPIO_EPIO17
value|0x00120000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_TEMP_FAN_EPIO_EPIO18
value|0x00130000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_TEMP_FAN_EPIO_EPIO19
value|0x00140000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_TEMP_FAN_EPIO_EPIO20
value|0x00150000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_TEMP_FAN_EPIO_EPIO21
value|0x00160000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_TEMP_FAN_EPIO_EPIO22
value|0x00170000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_TEMP_FAN_EPIO_EPIO23
value|0x00180000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_TEMP_FAN_EPIO_EPIO24
value|0x00190000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_TEMP_FAN_EPIO_EPIO25
value|0x001a0000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_TEMP_FAN_EPIO_EPIO26
value|0x001b0000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_TEMP_FAN_EPIO_EPIO27
value|0x001c0000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_TEMP_FAN_EPIO_EPIO28
value|0x001d0000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_TEMP_FAN_EPIO_EPIO29
value|0x001e0000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_TEMP_FAN_EPIO_EPIO30
value|0x001f0000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_TEMP_FAN_EPIO_EPIO31
value|0x00200000
comment|/*  EPIO of shut down temperature status */
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_TEMP_SHUT_EPIO_MASK
value|0xFF000000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_TEMP_SHUT_EPIO_SHIFT
value|24
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_TEMP_SHUT_EPIO_NA
value|0x00000000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_TEMP_SHUT_EPIO_EPIO0
value|0x01000000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_TEMP_SHUT_EPIO_EPIO1
value|0x02000000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_TEMP_SHUT_EPIO_EPIO2
value|0x03000000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_TEMP_SHUT_EPIO_EPIO3
value|0x04000000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_TEMP_SHUT_EPIO_EPIO4
value|0x05000000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_TEMP_SHUT_EPIO_EPIO5
value|0x06000000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_TEMP_SHUT_EPIO_EPIO6
value|0x07000000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_TEMP_SHUT_EPIO_EPIO7
value|0x08000000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_TEMP_SHUT_EPIO_EPIO8
value|0x09000000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_TEMP_SHUT_EPIO_EPIO9
value|0x0a000000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_TEMP_SHUT_EPIO_EPIO10
value|0x0b000000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_TEMP_SHUT_EPIO_EPIO11
value|0x0c000000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_TEMP_SHUT_EPIO_EPIO12
value|0x0d000000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_TEMP_SHUT_EPIO_EPIO13
value|0x0e000000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_TEMP_SHUT_EPIO_EPIO14
value|0x0f000000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_TEMP_SHUT_EPIO_EPIO15
value|0x10000000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_TEMP_SHUT_EPIO_EPIO16
value|0x11000000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_TEMP_SHUT_EPIO_EPIO17
value|0x12000000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_TEMP_SHUT_EPIO_EPIO18
value|0x13000000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_TEMP_SHUT_EPIO_EPIO19
value|0x14000000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_TEMP_SHUT_EPIO_EPIO20
value|0x15000000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_TEMP_SHUT_EPIO_EPIO21
value|0x16000000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_TEMP_SHUT_EPIO_EPIO22
value|0x17000000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_TEMP_SHUT_EPIO_EPIO23
value|0x18000000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_TEMP_SHUT_EPIO_EPIO24
value|0x19000000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_TEMP_SHUT_EPIO_EPIO25
value|0x1a000000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_TEMP_SHUT_EPIO_EPIO26
value|0x1b000000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_TEMP_SHUT_EPIO_EPIO27
value|0x1c000000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_TEMP_SHUT_EPIO_EPIO28
value|0x1d000000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_TEMP_SHUT_EPIO_EPIO29
value|0x1e000000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_TEMP_SHUT_EPIO_EPIO30
value|0x1f000000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_TEMP_SHUT_EPIO_EPIO31
value|0x20000000
comment|/*  EPIO of shut down temperature status */
name|uint32_t
name|temperature_monitor2
decl_stmt|;
comment|/* 0x4004 */
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_TEMP_PERIOD_MASK
value|0x0000FFFF
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_TEMP_PERIOD_SHIFT
value|0
comment|/*  Sensor interface - Disabled / BSC / In the future - SMBUS */
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_SENSOR_INTERFACE_MASK
value|0x00030000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_SENSOR_INTERFACE_SHIFT
value|16
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_SENSOR_INTERFACE_DISABLED
value|0x00000000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_SENSOR_INTERFACE_BSC
value|0x00010000
comment|/*  On Board Sensor Address */
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_SENSOR_ADDR_MASK
value|0x03FC0000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_SENSOR_ADDR_SHIFT
value|18
comment|/*  MFW flavor to be used */
name|uint32_t
name|mfw_cfg
decl_stmt|;
comment|/* 0x4008 */
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_MFW_FLAVOR_MASK
value|0x000000FF
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_MFW_FLAVOR_SHIFT
value|0
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_MFW_FLAVOR_NA
value|0x00000000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_MFW_FLAVOR_A
value|0x00000001
comment|/*  Should NIC data query remain enabled upon last drv unload */
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_OCBB_EN_LAST_DRV_MASK
value|0x00000100
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_OCBB_EN_LAST_DRV_SHIFT
value|8
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_OCBB_EN_LAST_DRV_DISABLED
value|0x00000000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_OCBB_EN_LAST_DRV_ENABLED
value|0x00000100
comment|/*  Prevent OCBB feature */
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_OCBB_PREVENT_MASK
value|0x00000200
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_OCBB_PREVENT_SHIFT
value|9
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_OCBB_PREVENT_DISABLED
value|0x00000000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_OCBB_PREVENT_ENABLED
value|0x00000200
comment|/*  Enable DCi support */
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_DCI_SUPPORT_MASK
value|0x00000400
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_DCI_SUPPORT_SHIFT
value|10
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_DCI_SUPPORT_DISABLED
value|0x00000000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_DCI_SUPPORT_ENABLED
value|0x00000400
comment|/*  Reserved bits: 75-76 */
comment|/*  Hide DCBX feature in CCM/BACS menus */
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_HIDE_DCBX_FEAT_MASK
value|0x00010000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_HIDE_DCBX_FEAT_SHIFT
value|16
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_HIDE_DCBX_FEAT_DISABLED
value|0x00000000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_HIDE_DCBX_FEAT_ENABLED
value|0x00010000
name|uint32_t
name|smbus_config
decl_stmt|;
comment|/* 0x400C */
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_SMBUS_ADDR_MASK
value|0x000000FF
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_SMBUS_ADDR_SHIFT
value|0
comment|/*  Switching regulator loop gain */
name|uint32_t
name|board_cfg
decl_stmt|;
comment|/* 0x4010 */
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_LOOP_GAIN_MASK
value|0x0000000F
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_LOOP_GAIN_SHIFT
value|0
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_LOOP_GAIN_HW_DEFAULT
value|0x00000000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_LOOP_GAIN_X2
value|0x00000008
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_LOOP_GAIN_X4
value|0x00000009
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_LOOP_GAIN_X8
value|0x0000000a
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_LOOP_GAIN_X16
value|0x0000000b
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_LOOP_GAIN_DIV8
value|0x0000000c
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_LOOP_GAIN_DIV4
value|0x0000000d
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_LOOP_GAIN_DIV2
value|0x0000000e
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_LOOP_GAIN_X1
value|0x0000000f
comment|/*  whether shadow swim feature is supported */
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_SHADOW_SWIM_MASK
value|0x00000100
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_SHADOW_SWIM_SHIFT
value|8
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_SHADOW_SWIM_DISABLED
value|0x00000000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_SHADOW_SWIM_ENABLED
value|0x00000100
comment|/*  whether to show/hide SRIOV menu in CCM */
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_SRIOV_SHOW_MENU_MASK
value|0x00000200
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_SRIOV_SHOW_MENU_SHIFT
value|9
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_SRIOV_SHOW_MENU
value|0x00000000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_SRIOV_HIDE_MENU
value|0x00000200
comment|/*  Overide PCIE revision ID when enabled the, 	    revision ID will set to B1=='0x11' */
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_OVR_REV_ID_MASK
value|0x00000400
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_OVR_REV_ID_SHIFT
value|10
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_OVR_REV_ID_DISABLED
value|0x00000000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_OVR_REV_ID_ENABLED
value|0x00000400
comment|/*  Bypass slicer offset tuning */
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_BYPASS_SLICER_MASK
value|0x00000800
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_BYPASS_SLICER_SHIFT
value|11
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_BYPASS_SLICER_DISABLED
value|0x00000000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_BYPASS_SLICER_ENABLED
value|0x00000800
comment|/*  Control Revision ID */
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_REV_ID_CTRL_MASK
value|0x00003000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_REV_ID_CTRL_SHIFT
value|12
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_REV_ID_CTRL_PRESERVE
value|0x00000000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_REV_ID_CTRL_ACTUAL
value|0x00001000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_REV_ID_CTRL_FORCE_B0
value|0x00002000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_REV_ID_CTRL_FORCE_B1
value|0x00003000
comment|/*  Threshold in celcius for max continuous operation */
name|uint32_t
name|temperature_report
decl_stmt|;
comment|/* 0x4014 */
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_TEMP_MCOT_MASK
value|0x0000007F
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_TEMP_MCOT_SHIFT
value|0
comment|/*  Threshold in celcius for sensor caution */
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_TEMP_SCT_MASK
value|0x00007F00
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_TEMP_SCT_SHIFT
value|8
comment|/*  wwn node prefix to be used (unless value is 0) */
name|uint32_t
name|wwn_prefix
decl_stmt|;
comment|/* 0x4018 */
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_WWN_NODE_PREFIX0_MASK
value|0x000000FF
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_WWN_NODE_PREFIX0_SHIFT
value|0
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_WWN_NODE_PREFIX1_MASK
value|0x0000FF00
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_WWN_NODE_PREFIX1_SHIFT
value|8
comment|/*  wwn port prefix to be used (unless value is 0) */
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_WWN_PORT_PREFIX0_MASK
value|0x00FF0000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_WWN_PORT_PREFIX0_SHIFT
value|16
comment|/*  wwn port prefix to be used (unless value is 0) */
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_WWN_PORT_PREFIX1_MASK
value|0xFF000000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_WWN_PORT_PREFIX1_SHIFT
value|24
comment|/*  General debug nvm cfg */
name|uint32_t
name|dbg_cfg_flags
decl_stmt|;
comment|/* 0x401C */
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_DBG_MASK
value|0x000FFFFF
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_DBG_SHIFT
value|0
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_DBG_ENABLE
value|0x00000001
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_DBG_EN_SIGDET_FILTER
value|0x00000002
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_DBG_SET_LP_TX_PRESET7
value|0x00000004
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_DBG_SET_TX_ANA_DEFAULT
value|0x00000008
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_DBG_SET_PLL_ANA_DEFAULT
value|0x00000010
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_DBG_FORCE_G1PLL_RETUNE
value|0x00000020
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_DBG_SET_RX_ANA_DEFAULT
value|0x00000040
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_DBG_FORCE_SERDES_RX_CLK
value|0x00000080
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_DBG_DIS_RX_LP_EIEOS
value|0x00000100
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_DBG_FINALIZE_UCODE
value|0x00000200
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_DBG_HOLDOFF_REQ
value|0x00000400
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_DBG_RX_SIGDET_OVERRIDE
value|0x00000800
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_DBG_GP_PORG_UC_RESET
value|0x00001000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_DBG_SUPPRESS_COMPEN_EVT
value|0x00002000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_DBG_ADJ_TXEQ_P0_P1
value|0x00004000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_DBG_G3_PLL_RETUNE
value|0x00008000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_DBG_SET_MAC_PHY_CTL8
value|0x00010000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_DBG_DIS_MAC_G3_FRM_ERR
value|0x00020000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_DBG_INFERRED_EI
value|0x00040000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_DBG_GEN3_COMPLI_ENA
value|0x00080000
comment|/*  Override Rx signal detect threshold when enabled the threshold 	 * will be set staticaly 	 */
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_OVERRIDE_RX_SIG_MASK
value|0x00100000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_OVERRIDE_RX_SIG_SHIFT
value|20
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_OVERRIDE_RX_SIG_DISABLED
value|0x00000000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_OVERRIDE_RX_SIG_ENABLED
value|0x00100000
comment|/*  Debug signet rx threshold */
name|uint32_t
name|dbg_rx_sigdet_threshold
decl_stmt|;
comment|/* 0x4020 */
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_DBG_RX_SIGDET_MASK
value|0x00000007
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_DBG_RX_SIGDET_SHIFT
value|0
comment|/*  Enable IFFE feature */
name|uint32_t
name|iffe_features
decl_stmt|;
comment|/* 0x4024 */
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_ENABLE_IFFE_MASK
value|0x00000001
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_ENABLE_IFFE_SHIFT
value|0
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_ENABLE_IFFE_DISABLED
value|0x00000000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_ENABLE_IFFE_ENABLED
value|0x00000001
comment|/*  Allowable port enablement (bitmask for ports 3-1) */
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_OVERRIDE_PORT_MASK
value|0x0000000E
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_OVERRIDE_PORT_SHIFT
value|1
comment|/*  Allow iSCSI offload override */
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_OVERRIDE_ISCSI_MASK
value|0x00000010
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_OVERRIDE_ISCSI_SHIFT
value|4
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_OVERRIDE_ISCSI_DISABLED
value|0x00000000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_OVERRIDE_ISCSI_ENABLED
value|0x00000010
comment|/*  Allow FCoE offload override */
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_OVERRIDE_FCOE_MASK
value|0x00000020
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_OVERRIDE_FCOE_SHIFT
value|5
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_OVERRIDE_FCOE_DISABLED
value|0x00000000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_OVERRIDE_FCOE_ENABLED
value|0x00000020
comment|/*  Tie to adaptor */
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_TIE_ADAPTOR_MASK
value|0x00008000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_TIE_ADAPTOR_SHIFT
value|15
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_TIE_ADAPTOR_DISABLED
value|0x00000000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_TIE_ADAPTOR_ENABLED
value|0x00008000
comment|/*  Currently enabled port(s) (bitmask for ports 3-1) */
name|uint32_t
name|current_iffe_mask
decl_stmt|;
comment|/* 0x4028 */
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_CURRENT_CFG_MASK
value|0x0000000E
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_CURRENT_CFG_SHIFT
value|1
comment|/*  Current iSCSI offload  */
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_CURRENT_ISCSI_MASK
value|0x00000010
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_CURRENT_ISCSI_SHIFT
value|4
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_CURRENT_ISCSI_DISABLED
value|0x00000000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_CURRENT_ISCSI_ENABLED
value|0x00000010
comment|/*  Current FCoE offload  */
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_CURRENT_FCOE_MASK
value|0x00000020
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_CURRENT_FCOE_SHIFT
value|5
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_CURRENT_FCOE_DISABLED
value|0x00000000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_CURRENT_FCOE_ENABLED
value|0x00000020
comment|/* FW set this pin to "0" (assert) these signal if either of its MAC 	 * or PHY specific threshold values is exceeded. 	 * Values are standard GPIO/EPIO pins. 	 */
name|uint32_t
name|threshold_pin
decl_stmt|;
comment|/* 0x402C */
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_TCONTROL_PIN_MASK
value|0x000000FF
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_TCONTROL_PIN_SHIFT
value|0
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_TWARNING_PIN_MASK
value|0x0000FF00
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_TWARNING_PIN_SHIFT
value|8
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_TCRITICAL_PIN_MASK
value|0x00FF0000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_TCRITICAL_PIN_SHIFT
value|16
comment|/* MAC die temperature threshold in Celsius. */
name|uint32_t
name|mac_threshold_val
decl_stmt|;
comment|/* 0x4030 */
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_CONTROL_MAC_THRESH_MASK
value|0x000000FF
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_CONTROL_MAC_THRESH_SHIFT
value|0
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_WARNING_MAC_THRESH_MASK
value|0x0000FF00
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_WARNING_MAC_THRESH_SHIFT
value|8
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_CRITICAL_MAC_THRESH_MASK
value|0x00FF0000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_CRITICAL_MAC_THRESH_SHIFT
value|16
comment|/*  PHY die temperature threshold in Celsius. */
name|uint32_t
name|phy_threshold_val
decl_stmt|;
comment|/* 0x4034 */
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_CONTROL_PHY_THRESH_MASK
value|0x000000FF
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_CONTROL_PHY_THRESH_SHIFT
value|0
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_WARNING_PHY_THRESH_MASK
value|0x0000FF00
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_WARNING_PHY_THRESH_SHIFT
value|8
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_CRITICAL_PHY_THRESH_MASK
value|0x00FF0000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_CRITICAL_PHY_THRESH_SHIFT
value|16
comment|/* External pins to communicate with host. 	 * Values are standard GPIO/EPIO pins. 	 */
name|uint32_t
name|host_pin
decl_stmt|;
comment|/* 0x4038 */
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_I2C_ISOLATE_MASK
value|0x000000FF
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_I2C_ISOLATE_SHIFT
value|0
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_MEZZ_FAULT_MASK
value|0x0000FF00
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_MEZZ_FAULT_SHIFT
value|8
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_MEZZ_VPD_UPDATE_MASK
value|0x00FF0000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_MEZZ_VPD_UPDATE_SHIFT
value|16
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_VPD_CACHE_COMP_MASK
value|0xFF000000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_VPD_CACHE_COMP_SHIFT
value|24
comment|/*  Manufacture kit version */
name|uint32_t
name|manufacture_ver
decl_stmt|;
comment|/* 0x403C */
comment|/*  Manufacture timestamp */
name|uint32_t
name|manufacture_data
decl_stmt|;
comment|/* 0x4040 */
comment|/*  Number of ISCSI/FCOE cfg images */
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_NUM_ISCSI_FCOE_CFGS_MASK
value|0x00040000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_NUM_ISCSI_FCOE_CFGS_SHIFT18
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_NUM_ISCSI_FCOE_CFGS_2
value|0x00000000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_NUM_ISCSI_FCOE_CFGS_4
value|0x00040000
comment|/*  MCP crash dump trigger */
name|uint32_t
name|mcp_crash_dump
decl_stmt|;
comment|/* 0x4044 */
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_CRASH_DUMP_MASK
value|0x7FFFFFFF
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_CRASH_DUMP_SHIFT
value|0
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_CRASH_DUMP_DISABLED
value|0x00000000
define|#
directive|define
name|EXTENDED_DEV_INFO_SHARED_CFG_CRASH_DUMP_ENABLED
value|0x00000001
comment|/*  MBI version */
name|uint32_t
name|mbi_version
decl_stmt|;
comment|/* 0x4048 */
comment|/*  MBI date */
name|uint32_t
name|mbi_date
decl_stmt|;
comment|/* 0x404C */
block|}
struct|;
end_struct

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Missing either LITTLE_ENDIAN or BIG_ENDIAN definition."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|FUNC_0
value|0
end_define

begin_define
define|#
directive|define
name|FUNC_1
value|1
end_define

begin_define
define|#
directive|define
name|FUNC_2
value|2
end_define

begin_define
define|#
directive|define
name|FUNC_3
value|3
end_define

begin_define
define|#
directive|define
name|FUNC_4
value|4
end_define

begin_define
define|#
directive|define
name|FUNC_5
value|5
end_define

begin_define
define|#
directive|define
name|FUNC_6
value|6
end_define

begin_define
define|#
directive|define
name|FUNC_7
value|7
end_define

begin_define
define|#
directive|define
name|E1_FUNC_MAX
value|2
end_define

begin_define
define|#
directive|define
name|E1H_FUNC_MAX
value|8
end_define

begin_define
define|#
directive|define
name|E2_FUNC_MAX
value|4
end_define

begin_comment
comment|/* per path */
end_comment

begin_define
define|#
directive|define
name|VN_0
value|0
end_define

begin_define
define|#
directive|define
name|VN_1
value|1
end_define

begin_define
define|#
directive|define
name|VN_2
value|2
end_define

begin_define
define|#
directive|define
name|VN_3
value|3
end_define

begin_define
define|#
directive|define
name|E1VN_MAX
value|1
end_define

begin_define
define|#
directive|define
name|E1HVN_MAX
value|4
end_define

begin_define
define|#
directive|define
name|E2_VF_MAX
value|64
end_define

begin_comment
comment|/* HC_REG_VF_CONFIGURATION_SIZE */
end_comment

begin_comment
comment|/* This value (in milliseconds) determines the frequency of the driver  * issuing the PULSE message code.  The firmware monitors this periodic  * pulse to determine when to switch to an OS-absent mode. */
end_comment

begin_define
define|#
directive|define
name|DRV_PULSE_PERIOD_MS
value|250
end_define

begin_comment
comment|/* This value (in milliseconds) determines how long the driver should  * wait for an acknowledgement from the firmware before timing out.  Once  * the firmware has timed out, the driver will assume there is no firmware  * running and there won't be any firmware-driver synchronization during a  * driver reset. */
end_comment

begin_define
define|#
directive|define
name|FW_ACK_TIME_OUT_MS
value|5000
end_define

begin_define
define|#
directive|define
name|FW_ACK_POLL_TIME_MS
value|1
end_define

begin_define
define|#
directive|define
name|FW_ACK_NUM_OF_POLL
value|(FW_ACK_TIME_OUT_MS/FW_ACK_POLL_TIME_MS)
end_define

begin_define
define|#
directive|define
name|MFW_TRACE_SIGNATURE
value|0x54524342
end_define

begin_comment
comment|/****************************************************************************  * Driver<-> FW Mailbox                                                    *  ****************************************************************************/
end_comment

begin_struct
struct|struct
name|drv_port_mb
block|{
name|uint32_t
name|link_status
decl_stmt|;
comment|/* Driver should update this field on any link change event */
define|#
directive|define
name|LINK_STATUS_NONE
value|(0<<0)
define|#
directive|define
name|LINK_STATUS_LINK_FLAG_MASK
value|0x00000001
define|#
directive|define
name|LINK_STATUS_LINK_UP
value|0x00000001
define|#
directive|define
name|LINK_STATUS_SPEED_AND_DUPLEX_MASK
value|0x0000001E
define|#
directive|define
name|LINK_STATUS_SPEED_AND_DUPLEX_AN_NOT_COMPLETE
value|(0<<1)
define|#
directive|define
name|LINK_STATUS_SPEED_AND_DUPLEX_10THD
value|(1<<1)
define|#
directive|define
name|LINK_STATUS_SPEED_AND_DUPLEX_10TFD
value|(2<<1)
define|#
directive|define
name|LINK_STATUS_SPEED_AND_DUPLEX_100TXHD
value|(3<<1)
define|#
directive|define
name|LINK_STATUS_SPEED_AND_DUPLEX_100T4
value|(4<<1)
define|#
directive|define
name|LINK_STATUS_SPEED_AND_DUPLEX_100TXFD
value|(5<<1)
define|#
directive|define
name|LINK_STATUS_SPEED_AND_DUPLEX_1000THD
value|(6<<1)
define|#
directive|define
name|LINK_STATUS_SPEED_AND_DUPLEX_1000TFD
value|(7<<1)
define|#
directive|define
name|LINK_STATUS_SPEED_AND_DUPLEX_1000XFD
value|(7<<1)
define|#
directive|define
name|LINK_STATUS_SPEED_AND_DUPLEX_2500THD
value|(8<<1)
define|#
directive|define
name|LINK_STATUS_SPEED_AND_DUPLEX_2500TFD
value|(9<<1)
define|#
directive|define
name|LINK_STATUS_SPEED_AND_DUPLEX_2500XFD
value|(9<<1)
define|#
directive|define
name|LINK_STATUS_SPEED_AND_DUPLEX_10GTFD
value|(10<<1)
define|#
directive|define
name|LINK_STATUS_SPEED_AND_DUPLEX_10GXFD
value|(10<<1)
define|#
directive|define
name|LINK_STATUS_SPEED_AND_DUPLEX_20GTFD
value|(11<<1)
define|#
directive|define
name|LINK_STATUS_SPEED_AND_DUPLEX_20GXFD
value|(11<<1)
define|#
directive|define
name|LINK_STATUS_AUTO_NEGOTIATE_FLAG_MASK
value|0x00000020
define|#
directive|define
name|LINK_STATUS_AUTO_NEGOTIATE_ENABLED
value|0x00000020
define|#
directive|define
name|LINK_STATUS_AUTO_NEGOTIATE_COMPLETE
value|0x00000040
define|#
directive|define
name|LINK_STATUS_PARALLEL_DETECTION_FLAG_MASK
value|0x00000080
define|#
directive|define
name|LINK_STATUS_PARALLEL_DETECTION_USED
value|0x00000080
define|#
directive|define
name|LINK_STATUS_LINK_PARTNER_1000TFD_CAPABLE
value|0x00000200
define|#
directive|define
name|LINK_STATUS_LINK_PARTNER_1000THD_CAPABLE
value|0x00000400
define|#
directive|define
name|LINK_STATUS_LINK_PARTNER_100T4_CAPABLE
value|0x00000800
define|#
directive|define
name|LINK_STATUS_LINK_PARTNER_100TXFD_CAPABLE
value|0x00001000
define|#
directive|define
name|LINK_STATUS_LINK_PARTNER_100TXHD_CAPABLE
value|0x00002000
define|#
directive|define
name|LINK_STATUS_LINK_PARTNER_10TFD_CAPABLE
value|0x00004000
define|#
directive|define
name|LINK_STATUS_LINK_PARTNER_10THD_CAPABLE
value|0x00008000
define|#
directive|define
name|LINK_STATUS_TX_FLOW_CONTROL_FLAG_MASK
value|0x00010000
define|#
directive|define
name|LINK_STATUS_TX_FLOW_CONTROL_ENABLED
value|0x00010000
define|#
directive|define
name|LINK_STATUS_RX_FLOW_CONTROL_FLAG_MASK
value|0x00020000
define|#
directive|define
name|LINK_STATUS_RX_FLOW_CONTROL_ENABLED
value|0x00020000
define|#
directive|define
name|LINK_STATUS_LINK_PARTNER_FLOW_CONTROL_MASK
value|0x000C0000
define|#
directive|define
name|LINK_STATUS_LINK_PARTNER_NOT_PAUSE_CAPABLE
value|(0<<18)
define|#
directive|define
name|LINK_STATUS_LINK_PARTNER_SYMMETRIC_PAUSE
value|(1<<18)
define|#
directive|define
name|LINK_STATUS_LINK_PARTNER_ASYMMETRIC_PAUSE
value|(2<<18)
define|#
directive|define
name|LINK_STATUS_LINK_PARTNER_BOTH_PAUSE
value|(3<<18)
define|#
directive|define
name|LINK_STATUS_SERDES_LINK
value|0x00100000
define|#
directive|define
name|LINK_STATUS_LINK_PARTNER_2500XFD_CAPABLE
value|0x00200000
define|#
directive|define
name|LINK_STATUS_LINK_PARTNER_2500XHD_CAPABLE
value|0x00400000
define|#
directive|define
name|LINK_STATUS_LINK_PARTNER_10GXFD_CAPABLE
value|0x00800000
define|#
directive|define
name|LINK_STATUS_LINK_PARTNER_20GXFD_CAPABLE
value|0x10000000
define|#
directive|define
name|LINK_STATUS_PFC_ENABLED
value|0x20000000
define|#
directive|define
name|LINK_STATUS_PHYSICAL_LINK_FLAG
value|0x40000000
define|#
directive|define
name|LINK_STATUS_SFP_TX_FAULT
value|0x80000000
name|uint32_t
name|port_stx
decl_stmt|;
name|uint32_t
name|stat_nig_timer
decl_stmt|;
comment|/* MCP firmware does not use this field */
name|uint32_t
name|ext_phy_fw_version
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|drv_func_mb
block|{
name|uint32_t
name|drv_mb_header
decl_stmt|;
define|#
directive|define
name|DRV_MSG_CODE_MASK
value|0xffff0000
define|#
directive|define
name|DRV_MSG_CODE_LOAD_REQ
value|0x10000000
define|#
directive|define
name|DRV_MSG_CODE_LOAD_DONE
value|0x11000000
define|#
directive|define
name|DRV_MSG_CODE_UNLOAD_REQ_WOL_EN
value|0x20000000
define|#
directive|define
name|DRV_MSG_CODE_UNLOAD_REQ_WOL_DIS
value|0x20010000
define|#
directive|define
name|DRV_MSG_CODE_UNLOAD_REQ_WOL_MCP
value|0x20020000
define|#
directive|define
name|DRV_MSG_CODE_UNLOAD_DONE
value|0x21000000
define|#
directive|define
name|DRV_MSG_CODE_DCC_OK
value|0x30000000
define|#
directive|define
name|DRV_MSG_CODE_DCC_FAILURE
value|0x31000000
define|#
directive|define
name|DRV_MSG_CODE_DIAG_ENTER_REQ
value|0x50000000
define|#
directive|define
name|DRV_MSG_CODE_DIAG_EXIT_REQ
value|0x60000000
define|#
directive|define
name|DRV_MSG_CODE_VALIDATE_KEY
value|0x70000000
define|#
directive|define
name|DRV_MSG_CODE_GET_CURR_KEY
value|0x80000000
define|#
directive|define
name|DRV_MSG_CODE_GET_UPGRADE_KEY
value|0x81000000
define|#
directive|define
name|DRV_MSG_CODE_GET_MANUF_KEY
value|0x82000000
define|#
directive|define
name|DRV_MSG_CODE_LOAD_L2B_PRAM
value|0x90000000
define|#
directive|define
name|DRV_MSG_CODE_OEM_OK
value|0x00010000
define|#
directive|define
name|DRV_MSG_CODE_OEM_FAILURE
value|0x00020000
define|#
directive|define
name|DRV_MSG_CODE_OEM_UPDATE_SVID_OK
value|0x00030000
define|#
directive|define
name|DRV_MSG_CODE_OEM_UPDATE_SVID_FAILURE
value|0x00040000
comment|/* 	 * The optic module verification command requires bootcode 	 * v5.0.6 or later, te specific optic module verification command 	 * requires bootcode v5.2.12 or later 	 */
define|#
directive|define
name|DRV_MSG_CODE_VRFY_FIRST_PHY_OPT_MDL
value|0xa0000000
define|#
directive|define
name|REQ_BC_VER_4_VRFY_FIRST_PHY_OPT_MDL
value|0x00050006
define|#
directive|define
name|DRV_MSG_CODE_VRFY_SPECIFIC_PHY_OPT_MDL
value|0xa1000000
define|#
directive|define
name|REQ_BC_VER_4_VRFY_SPECIFIC_PHY_OPT_MDL
value|0x00050234
define|#
directive|define
name|DRV_MSG_CODE_VRFY_AFEX_SUPPORTED
value|0xa2000000
define|#
directive|define
name|REQ_BC_VER_4_VRFY_AFEX_SUPPORTED
value|0x00070002
define|#
directive|define
name|REQ_BC_VER_4_SFP_TX_DISABLE_SUPPORTED
value|0x00070014
define|#
directive|define
name|REQ_BC_VER_4_MT_SUPPORTED
value|0x00070201
define|#
directive|define
name|REQ_BC_VER_4_PFC_STATS_SUPPORTED
value|0x00070201
define|#
directive|define
name|REQ_BC_VER_4_FCOE_FEATURES
value|0x00070209
define|#
directive|define
name|DRV_MSG_CODE_DCBX_ADMIN_PMF_MSG
value|0xb0000000
define|#
directive|define
name|DRV_MSG_CODE_DCBX_PMF_DRV_OK
value|0xb2000000
define|#
directive|define
name|REQ_BC_VER_4_DCBX_ADMIN_MSG_NON_PMF
value|0x00070401
define|#
directive|define
name|DRV_MSG_CODE_VF_DISABLED_DONE
value|0xc0000000
define|#
directive|define
name|DRV_MSG_CODE_AFEX_DRIVER_SETMAC
value|0xd0000000
define|#
directive|define
name|DRV_MSG_CODE_AFEX_LISTGET_ACK
value|0xd1000000
define|#
directive|define
name|DRV_MSG_CODE_AFEX_LISTSET_ACK
value|0xd2000000
define|#
directive|define
name|DRV_MSG_CODE_AFEX_STATSGET_ACK
value|0xd3000000
define|#
directive|define
name|DRV_MSG_CODE_AFEX_VIFSET_ACK
value|0xd4000000
define|#
directive|define
name|DRV_MSG_CODE_DRV_INFO_ACK
value|0xd8000000
define|#
directive|define
name|DRV_MSG_CODE_DRV_INFO_NACK
value|0xd9000000
define|#
directive|define
name|DRV_MSG_CODE_EEE_RESULTS_ACK
value|0xda000000
define|#
directive|define
name|DRV_MSG_CODE_RMMOD
value|0xdb000000
define|#
directive|define
name|REQ_BC_VER_4_RMMOD_CMD
value|0x0007080f
define|#
directive|define
name|DRV_MSG_CODE_SET_MF_BW
value|0xe0000000
define|#
directive|define
name|REQ_BC_VER_4_SET_MF_BW
value|0x00060202
define|#
directive|define
name|DRV_MSG_CODE_SET_MF_BW_ACK
value|0xe1000000
define|#
directive|define
name|DRV_MSG_CODE_LINK_STATUS_CHANGED
value|0x01000000
define|#
directive|define
name|DRV_MSG_CODE_INITIATE_FLR
value|0x02000000
define|#
directive|define
name|REQ_BC_VER_4_INITIATE_FLR
value|0x00070213
define|#
directive|define
name|BIOS_MSG_CODE_LIC_CHALLENGE
value|0xff010000
define|#
directive|define
name|BIOS_MSG_CODE_LIC_RESPONSE
value|0xff020000
define|#
directive|define
name|BIOS_MSG_CODE_VIRT_MAC_PRIM
value|0xff030000
define|#
directive|define
name|BIOS_MSG_CODE_VIRT_MAC_ISCSI
value|0xff040000
define|#
directive|define
name|DRV_MSG_CODE_IMG_OFFSET_REQ
value|0xe2000000
define|#
directive|define
name|DRV_MSG_CODE_IMG_SIZE_REQ
value|0xe3000000
define|#
directive|define
name|DRV_MSG_CODE_UFP_CONFIG_ACK
value|0xe4000000
define|#
directive|define
name|DRV_MSG_SEQ_NUMBER_MASK
value|0x0000ffff
define|#
directive|define
name|DRV_MSG_CODE_CONFIG_CHANGE
value|0xC1000000
name|uint32_t
name|drv_mb_param
decl_stmt|;
define|#
directive|define
name|DRV_MSG_CODE_SET_MF_BW_MIN_MASK
value|0x00ff0000
define|#
directive|define
name|DRV_MSG_CODE_SET_MF_BW_MAX_MASK
value|0xff000000
define|#
directive|define
name|DRV_MSG_CODE_UNLOAD_NON_D3_POWER
value|0x00000001
define|#
directive|define
name|DRV_MSG_CODE_UNLOAD_SKIP_LINK_RESET
value|0x00000002
define|#
directive|define
name|DRV_MSG_CODE_LOAD_REQ_WITH_LFA
value|0x0000100a
define|#
directive|define
name|DRV_MSG_CODE_LOAD_REQ_FORCE_LFA
value|0x00002000
define|#
directive|define
name|DRV_MSG_CODE_USR_BLK_IMAGE_REQ
value|0x00000001
define|#
directive|define
name|DRV_MSG_CODE_ISCSI_PERS_IMAGE_REQ
value|0x00000002
define|#
directive|define
name|DRV_MSG_CODE_VPD_IMAGE_REQ
value|0x00000003
define|#
directive|define
name|DRV_MSG_CODE_CONFIG_CHANGE_MTU_SIZE
value|0x00000001
define|#
directive|define
name|DRV_MSG_CODE_CONFIG_CHANGE_MAC_ADD
value|0x00000002
define|#
directive|define
name|DRV_MSG_CODE_CONFIG_CHANGE_WOL_ENA
value|0x00000003
define|#
directive|define
name|DRV_MSG_CODE_CONFIG_CHANGE_ISCI_BOOT
value|0x00000004
define|#
directive|define
name|DRV_MSG_CODE_CONFIG_CHANGE_FCOE_BOOT
value|0x00000005
name|uint32_t
name|fw_mb_header
decl_stmt|;
define|#
directive|define
name|FW_MSG_CODE_MASK
value|0xffff0000
define|#
directive|define
name|FW_MSG_CODE_DRV_LOAD_COMMON
value|0x10100000
define|#
directive|define
name|FW_MSG_CODE_DRV_LOAD_PORT
value|0x10110000
define|#
directive|define
name|FW_MSG_CODE_DRV_LOAD_FUNCTION
value|0x10120000
comment|/* Load common chip is supported from bc 6.0.0  */
define|#
directive|define
name|REQ_BC_VER_4_DRV_LOAD_COMMON_CHIP
value|0x00060000
define|#
directive|define
name|FW_MSG_CODE_DRV_LOAD_COMMON_CHIP
value|0x10130000
define|#
directive|define
name|FW_MSG_CODE_DRV_LOAD_REFUSED
value|0x10200000
define|#
directive|define
name|FW_MSG_CODE_DRV_LOAD_DONE
value|0x11100000
define|#
directive|define
name|FW_MSG_CODE_DRV_UNLOAD_COMMON
value|0x20100000
define|#
directive|define
name|FW_MSG_CODE_DRV_UNLOAD_PORT
value|0x20110000
define|#
directive|define
name|FW_MSG_CODE_DRV_UNLOAD_FUNCTION
value|0x20120000
define|#
directive|define
name|FW_MSG_CODE_DRV_UNLOAD_DONE
value|0x21100000
define|#
directive|define
name|FW_MSG_CODE_DCC_DONE
value|0x30100000
define|#
directive|define
name|FW_MSG_CODE_LLDP_DONE
value|0x40100000
define|#
directive|define
name|FW_MSG_CODE_DIAG_ENTER_DONE
value|0x50100000
define|#
directive|define
name|FW_MSG_CODE_DIAG_REFUSE
value|0x50200000
define|#
directive|define
name|FW_MSG_CODE_DIAG_EXIT_DONE
value|0x60100000
define|#
directive|define
name|FW_MSG_CODE_VALIDATE_KEY_SUCCESS
value|0x70100000
define|#
directive|define
name|FW_MSG_CODE_VALIDATE_KEY_FAILURE
value|0x70200000
define|#
directive|define
name|FW_MSG_CODE_GET_KEY_DONE
value|0x80100000
define|#
directive|define
name|FW_MSG_CODE_NO_KEY
value|0x80f00000
define|#
directive|define
name|FW_MSG_CODE_LIC_INFO_NOT_READY
value|0x80f80000
define|#
directive|define
name|FW_MSG_CODE_L2B_PRAM_LOADED
value|0x90100000
define|#
directive|define
name|FW_MSG_CODE_L2B_PRAM_T_LOAD_FAILURE
value|0x90210000
define|#
directive|define
name|FW_MSG_CODE_L2B_PRAM_C_LOAD_FAILURE
value|0x90220000
define|#
directive|define
name|FW_MSG_CODE_L2B_PRAM_X_LOAD_FAILURE
value|0x90230000
define|#
directive|define
name|FW_MSG_CODE_L2B_PRAM_U_LOAD_FAILURE
value|0x90240000
define|#
directive|define
name|FW_MSG_CODE_VRFY_OPT_MDL_SUCCESS
value|0xa0100000
define|#
directive|define
name|FW_MSG_CODE_VRFY_OPT_MDL_INVLD_IMG
value|0xa0200000
define|#
directive|define
name|FW_MSG_CODE_VRFY_OPT_MDL_UNAPPROVED
value|0xa0300000
define|#
directive|define
name|FW_MSG_CODE_VF_DISABLED_DONE
value|0xb0000000
define|#
directive|define
name|FW_MSG_CODE_HW_SET_INVALID_IMAGE
value|0xb0100000
define|#
directive|define
name|FW_MSG_CODE_AFEX_DRIVER_SETMAC_DONE
value|0xd0100000
define|#
directive|define
name|FW_MSG_CODE_AFEX_LISTGET_ACK
value|0xd1100000
define|#
directive|define
name|FW_MSG_CODE_AFEX_LISTSET_ACK
value|0xd2100000
define|#
directive|define
name|FW_MSG_CODE_AFEX_STATSGET_ACK
value|0xd3100000
define|#
directive|define
name|FW_MSG_CODE_AFEX_VIFSET_ACK
value|0xd4100000
define|#
directive|define
name|FW_MSG_CODE_DRV_INFO_ACK
value|0xd8100000
define|#
directive|define
name|FW_MSG_CODE_DRV_INFO_NACK
value|0xd9100000
define|#
directive|define
name|FW_MSG_CODE_EEE_RESULS_ACK
value|0xda100000
define|#
directive|define
name|FW_MSG_CODE_RMMOD_ACK
value|0xdb100000
define|#
directive|define
name|FW_MSG_CODE_SET_MF_BW_SENT
value|0xe0000000
define|#
directive|define
name|FW_MSG_CODE_SET_MF_BW_DONE
value|0xe1000000
define|#
directive|define
name|FW_MSG_CODE_LINK_CHANGED_ACK
value|0x01100000
define|#
directive|define
name|FW_MSG_CODE_FLR_ACK
value|0x02000000
define|#
directive|define
name|FW_MSG_CODE_FLR_NACK
value|0x02100000
define|#
directive|define
name|FW_MSG_CODE_LIC_CHALLENGE
value|0xff010000
define|#
directive|define
name|FW_MSG_CODE_LIC_RESPONSE
value|0xff020000
define|#
directive|define
name|FW_MSG_CODE_VIRT_MAC_PRIM
value|0xff030000
define|#
directive|define
name|FW_MSG_CODE_VIRT_MAC_ISCSI
value|0xff040000
define|#
directive|define
name|FW_MSG_CODE_IMG_OFFSET_RESPONSE
value|0xe2100000
define|#
directive|define
name|FW_MSG_CODE_IMG_SIZE_RESPONSE
value|0xe3100000
define|#
directive|define
name|FW_MSG_CODE_OEM_ACK
value|0x00010000
define|#
directive|define
name|DRV_MSG_CODE_OEM_UPDATE_SVID_ACK
value|0x00020000
define|#
directive|define
name|FW_MSG_CODE_CONFIG_CHANGE_DONE
value|0xC2000000
define|#
directive|define
name|FW_MSG_SEQ_NUMBER_MASK
value|0x0000ffff
name|uint32_t
name|fw_mb_param
decl_stmt|;
define|#
directive|define
name|FW_PARAM_INVALID_IMG
value|0xffffffff
name|uint32_t
name|drv_pulse_mb
decl_stmt|;
define|#
directive|define
name|DRV_PULSE_SEQ_MASK
value|0x00007fff
define|#
directive|define
name|DRV_PULSE_SYSTEM_TIME_MASK
value|0xffff0000
comment|/* 	 * The system time is in the format of 	 * (year-2001)*12*32 + month*32 + day. 	 */
define|#
directive|define
name|DRV_PULSE_ALWAYS_ALIVE
value|0x00008000
comment|/* 	 * Indicate to the firmware not to go into the 	 * OS-absent when it is not getting driver pulse. 	 * This is used for debugging as well for PXE(MBA). 	 */
name|uint32_t
name|mcp_pulse_mb
decl_stmt|;
define|#
directive|define
name|MCP_PULSE_SEQ_MASK
value|0x00007fff
define|#
directive|define
name|MCP_PULSE_ALWAYS_ALIVE
value|0x00008000
comment|/* Indicates to the driver not to assert due to lack 	 * of MCP response */
define|#
directive|define
name|MCP_EVENT_MASK
value|0xffff0000
define|#
directive|define
name|MCP_EVENT_OTHER_DRIVER_RESET_REQ
value|0x00010000
name|uint32_t
name|iscsi_boot_signature
decl_stmt|;
name|uint32_t
name|iscsi_boot_block_offset
decl_stmt|;
name|uint32_t
name|drv_status
decl_stmt|;
define|#
directive|define
name|DRV_STATUS_PMF
value|0x00000001
define|#
directive|define
name|DRV_STATUS_VF_DISABLED
value|0x00000002
define|#
directive|define
name|DRV_STATUS_SET_MF_BW
value|0x00000004
define|#
directive|define
name|DRV_STATUS_LINK_EVENT
value|0x00000008
define|#
directive|define
name|DRV_STATUS_OEM_EVENT_MASK
value|0x00000070
define|#
directive|define
name|DRV_STATUS_OEM_DISABLE_ENABLE_PF
value|0x00000010
define|#
directive|define
name|DRV_STATUS_OEM_BANDWIDTH_ALLOCATION
value|0x00000020
define|#
directive|define
name|DRV_STATUS_OEM_FC_NPIV_UPDATE
value|0x00000040
define|#
directive|define
name|DRV_STATUS_OEM_UPDATE_SVID
value|0x00000080
define|#
directive|define
name|DRV_STATUS_DCC_EVENT_MASK
value|0x0000ff00
define|#
directive|define
name|DRV_STATUS_DCC_DISABLE_ENABLE_PF
value|0x00000100
define|#
directive|define
name|DRV_STATUS_DCC_BANDWIDTH_ALLOCATION
value|0x00000200
define|#
directive|define
name|DRV_STATUS_DCC_CHANGE_MAC_ADDRESS
value|0x00000400
define|#
directive|define
name|DRV_STATUS_DCC_RESERVED1
value|0x00000800
define|#
directive|define
name|DRV_STATUS_DCC_SET_PROTOCOL
value|0x00001000
define|#
directive|define
name|DRV_STATUS_DCC_SET_PRIORITY
value|0x00002000
define|#
directive|define
name|DRV_STATUS_DCBX_EVENT_MASK
value|0x000f0000
define|#
directive|define
name|DRV_STATUS_DCBX_NEGOTIATION_RESULTS
value|0x00010000
define|#
directive|define
name|DRV_STATUS_AFEX_EVENT_MASK
value|0x03f00000
define|#
directive|define
name|DRV_STATUS_AFEX_LISTGET_REQ
value|0x00100000
define|#
directive|define
name|DRV_STATUS_AFEX_LISTSET_REQ
value|0x00200000
define|#
directive|define
name|DRV_STATUS_AFEX_STATSGET_REQ
value|0x00400000
define|#
directive|define
name|DRV_STATUS_AFEX_VIFSET_REQ
value|0x00800000
define|#
directive|define
name|DRV_STATUS_DRV_INFO_REQ
value|0x04000000
define|#
directive|define
name|DRV_STATUS_EEE_NEGOTIATION_RESULTS
value|0x08000000
name|uint32_t
name|virt_mac_upper
decl_stmt|;
define|#
directive|define
name|VIRT_MAC_SIGN_MASK
value|0xffff0000
define|#
directive|define
name|VIRT_MAC_SIGNATURE
value|0x564d0000
name|uint32_t
name|virt_mac_lower
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/****************************************************************************  * Management firmware state                                                *  ****************************************************************************/
end_comment

begin_comment
comment|/* Allocate 440 bytes for management firmware */
end_comment

begin_define
define|#
directive|define
name|MGMTFW_STATE_WORD_SIZE
value|110
end_define

begin_struct
struct|struct
name|mgmtfw_state
block|{
name|uint32_t
name|opaque
index|[
name|MGMTFW_STATE_WORD_SIZE
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/****************************************************************************  * Multi-Function configuration                                             *  ****************************************************************************/
end_comment

begin_struct
struct|struct
name|shared_mf_cfg
block|{
name|uint32_t
name|clp_mb
decl_stmt|;
define|#
directive|define
name|SHARED_MF_CLP_SET_DEFAULT
value|0x00000000
comment|/* set by CLP */
define|#
directive|define
name|SHARED_MF_CLP_EXIT
value|0x00000001
comment|/* set by MCP */
define|#
directive|define
name|SHARED_MF_CLP_EXIT_DONE
value|0x00010000
block|}
struct|;
end_struct

begin_struct
struct|struct
name|port_mf_cfg
block|{
name|uint32_t
name|dynamic_cfg
decl_stmt|;
comment|/* device control channel */
define|#
directive|define
name|PORT_MF_CFG_E1HOV_TAG_MASK
value|0x0000ffff
define|#
directive|define
name|PORT_MF_CFG_E1HOV_TAG_SHIFT
value|0
define|#
directive|define
name|PORT_MF_CFG_E1HOV_TAG_DEFAULT
value|PORT_MF_CFG_E1HOV_TAG_MASK
name|uint32_t
name|reserved
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|func_mf_cfg
block|{
name|uint32_t
name|config
decl_stmt|;
comment|/* E/R/I/D */
comment|/* function 0 of each port cannot be hidden */
define|#
directive|define
name|FUNC_MF_CFG_FUNC_HIDE
value|0x00000001
define|#
directive|define
name|FUNC_MF_CFG_PROTOCOL_MASK
value|0x00000006
define|#
directive|define
name|FUNC_MF_CFG_PROTOCOL_FCOE
value|0x00000000
define|#
directive|define
name|FUNC_MF_CFG_PROTOCOL_ETHERNET
value|0x00000002
define|#
directive|define
name|FUNC_MF_CFG_PROTOCOL_ETHERNET_WITH_RDMA
value|0x00000004
define|#
directive|define
name|FUNC_MF_CFG_PROTOCOL_ISCSI
value|0x00000006
define|#
directive|define
name|FUNC_MF_CFG_PROTOCOL_DEFAULT
define|\
value|FUNC_MF_CFG_PROTOCOL_ETHERNET_WITH_RDMA
define|#
directive|define
name|FUNC_MF_CFG_FUNC_DISABLED
value|0x00000008
define|#
directive|define
name|FUNC_MF_CFG_FUNC_DELETED
value|0x00000010
define|#
directive|define
name|FUNC_MF_CFG_FUNC_BOOT_MASK
value|0x00000060
define|#
directive|define
name|FUNC_MF_CFG_FUNC_BOOT_BIOS_CTRL
value|0x00000000
define|#
directive|define
name|FUNC_MF_CFG_FUNC_BOOT_VCM_DISABLED
value|0x00000020
define|#
directive|define
name|FUNC_MF_CFG_FUNC_BOOT_VCM_ENABLED
value|0x00000040
comment|/* PRI */
comment|/* 0 - low priority, 3 - high priority */
define|#
directive|define
name|FUNC_MF_CFG_TRANSMIT_PRIORITY_MASK
value|0x00000300
define|#
directive|define
name|FUNC_MF_CFG_TRANSMIT_PRIORITY_SHIFT
value|8
define|#
directive|define
name|FUNC_MF_CFG_TRANSMIT_PRIORITY_DEFAULT
value|0x00000000
comment|/* MINBW, MAXBW */
comment|/* value range - 0..100, increments in 100Mbps */
define|#
directive|define
name|FUNC_MF_CFG_MIN_BW_MASK
value|0x00ff0000
define|#
directive|define
name|FUNC_MF_CFG_MIN_BW_SHIFT
value|16
define|#
directive|define
name|FUNC_MF_CFG_MIN_BW_DEFAULT
value|0x00000000
define|#
directive|define
name|FUNC_MF_CFG_MAX_BW_MASK
value|0xff000000
define|#
directive|define
name|FUNC_MF_CFG_MAX_BW_SHIFT
value|24
define|#
directive|define
name|FUNC_MF_CFG_MAX_BW_DEFAULT
value|0x64000000
name|uint32_t
name|mac_upper
decl_stmt|;
comment|/* MAC */
define|#
directive|define
name|FUNC_MF_CFG_UPPERMAC_MASK
value|0x0000ffff
define|#
directive|define
name|FUNC_MF_CFG_UPPERMAC_SHIFT
value|0
define|#
directive|define
name|FUNC_MF_CFG_UPPERMAC_DEFAULT
value|FUNC_MF_CFG_UPPERMAC_MASK
name|uint32_t
name|mac_lower
decl_stmt|;
define|#
directive|define
name|FUNC_MF_CFG_LOWERMAC_DEFAULT
value|0xffffffff
name|uint32_t
name|e1hov_tag
decl_stmt|;
comment|/* VNI */
define|#
directive|define
name|FUNC_MF_CFG_E1HOV_TAG_MASK
value|0x0000ffff
define|#
directive|define
name|FUNC_MF_CFG_E1HOV_TAG_SHIFT
value|0
define|#
directive|define
name|FUNC_MF_CFG_E1HOV_TAG_DEFAULT
value|FUNC_MF_CFG_E1HOV_TAG_MASK
comment|/* afex default VLAN ID - 12 bits */
define|#
directive|define
name|FUNC_MF_CFG_AFEX_VLAN_MASK
value|0x0fff0000
define|#
directive|define
name|FUNC_MF_CFG_AFEX_VLAN_SHIFT
value|16
name|uint32_t
name|afex_config
decl_stmt|;
define|#
directive|define
name|FUNC_MF_CFG_AFEX_COS_FILTER_MASK
value|0x000000ff
define|#
directive|define
name|FUNC_MF_CFG_AFEX_COS_FILTER_SHIFT
value|0
define|#
directive|define
name|FUNC_MF_CFG_AFEX_MBA_ENABLED_MASK
value|0x0000ff00
define|#
directive|define
name|FUNC_MF_CFG_AFEX_MBA_ENABLED_SHIFT
value|8
define|#
directive|define
name|FUNC_MF_CFG_AFEX_MBA_ENABLED_VAL
value|0x00000100
define|#
directive|define
name|FUNC_MF_CFG_AFEX_VLAN_MODE_MASK
value|0x000f0000
define|#
directive|define
name|FUNC_MF_CFG_AFEX_VLAN_MODE_SHIFT
value|16
name|uint32_t
name|pf_allocation
decl_stmt|;
comment|/* number of vfs in function, if 0 - sriov disabled */
define|#
directive|define
name|FUNC_MF_CFG_NUMBER_OF_VFS_MASK
value|0x000000FF
define|#
directive|define
name|FUNC_MF_CFG_NUMBER_OF_VFS_SHIFT
value|0
block|}
struct|;
end_struct

begin_enum
enum|enum
name|mf_cfg_afex_vlan_mode
block|{
name|FUNC_MF_CFG_AFEX_VLAN_TRUNK_MODE
init|=
literal|0
block|,
name|FUNC_MF_CFG_AFEX_VLAN_ACCESS_MODE
block|,
name|FUNC_MF_CFG_AFEX_VLAN_TRUNK_TAG_NATIVE_MODE
block|}
enum|;
end_enum

begin_comment
comment|/* This structure is not applicable and should not be accessed on 57711 */
end_comment

begin_struct
struct|struct
name|func_ext_cfg
block|{
name|uint32_t
name|func_cfg
decl_stmt|;
define|#
directive|define
name|MACP_FUNC_CFG_FLAGS_MASK
value|0x0000007F
define|#
directive|define
name|MACP_FUNC_CFG_FLAGS_SHIFT
value|0
define|#
directive|define
name|MACP_FUNC_CFG_FLAGS_ENABLED
value|0x00000001
define|#
directive|define
name|MACP_FUNC_CFG_FLAGS_ETHERNET
value|0x00000002
define|#
directive|define
name|MACP_FUNC_CFG_FLAGS_ISCSI_OFFLOAD
value|0x00000004
define|#
directive|define
name|MACP_FUNC_CFG_FLAGS_FCOE_OFFLOAD
value|0x00000008
define|#
directive|define
name|MACP_FUNC_CFG_PAUSE_ON_HOST_RING
value|0x00000080
name|uint32_t
name|iscsi_mac_addr_upper
decl_stmt|;
name|uint32_t
name|iscsi_mac_addr_lower
decl_stmt|;
name|uint32_t
name|fcoe_mac_addr_upper
decl_stmt|;
name|uint32_t
name|fcoe_mac_addr_lower
decl_stmt|;
name|uint32_t
name|fcoe_wwn_port_name_upper
decl_stmt|;
name|uint32_t
name|fcoe_wwn_port_name_lower
decl_stmt|;
name|uint32_t
name|fcoe_wwn_node_name_upper
decl_stmt|;
name|uint32_t
name|fcoe_wwn_node_name_lower
decl_stmt|;
name|uint32_t
name|preserve_data
decl_stmt|;
define|#
directive|define
name|MF_FUNC_CFG_PRESERVE_L2_MAC
value|(1<<0)
define|#
directive|define
name|MF_FUNC_CFG_PRESERVE_ISCSI_MAC
value|(1<<1)
define|#
directive|define
name|MF_FUNC_CFG_PRESERVE_FCOE_MAC
value|(1<<2)
define|#
directive|define
name|MF_FUNC_CFG_PRESERVE_FCOE_WWN_P
value|(1<<3)
define|#
directive|define
name|MF_FUNC_CFG_PRESERVE_FCOE_WWN_N
value|(1<<4)
define|#
directive|define
name|MF_FUNC_CFG_PRESERVE_TX_BW
value|(1<<5)
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mf_cfg
block|{
name|struct
name|shared_mf_cfg
name|shared_mf_config
decl_stmt|;
comment|/* 0x4 */
name|struct
name|port_mf_cfg
name|port_mf_config
index|[
name|NVM_PATH_MAX
index|]
index|[
name|PORT_MAX
index|]
decl_stmt|;
comment|/* 0x10*2=0x20 */
comment|/* for all chips, there are 8 mf functions */
name|struct
name|func_mf_cfg
name|func_mf_config
index|[
name|E1H_FUNC_MAX
index|]
decl_stmt|;
comment|/* 0x18 * 8 = 0xc0 */
comment|/* 	 * Extended configuration per function  - this array does not exist and 	 * should not be accessed on 57711 	 */
name|struct
name|func_ext_cfg
name|func_ext_config
index|[
name|E1H_FUNC_MAX
index|]
decl_stmt|;
comment|/* 0x28 * 8 = 0x140*/
block|}
struct|;
end_struct

begin_comment
comment|/* 0x224 */
end_comment

begin_comment
comment|/****************************************************************************  * Shared Memory Region                                                     *  ****************************************************************************/
end_comment

begin_struct
struct|struct
name|shmem_region
block|{
comment|/*   SharedMem Offset (size) */
name|uint32_t
name|validity_map
index|[
name|PORT_MAX
index|]
decl_stmt|;
comment|/* 0x0 (4*2 = 0x8) */
define|#
directive|define
name|SHR_MEM_FORMAT_REV_MASK
value|0xff000000
define|#
directive|define
name|SHR_MEM_FORMAT_REV_ID
value|('A'<<24)
comment|/* validity bits */
define|#
directive|define
name|SHR_MEM_VALIDITY_PCI_CFG
value|0x00100000
define|#
directive|define
name|SHR_MEM_VALIDITY_MB
value|0x00200000
define|#
directive|define
name|SHR_MEM_VALIDITY_DEV_INFO
value|0x00400000
define|#
directive|define
name|SHR_MEM_VALIDITY_RESERVED
value|0x00000007
comment|/* One licensing bit should be set */
define|#
directive|define
name|SHR_MEM_VALIDITY_LIC_KEY_IN_EFFECT_MASK
value|0x00000038
define|#
directive|define
name|SHR_MEM_VALIDITY_LIC_MANUF_KEY_IN_EFFECT
value|0x00000008
define|#
directive|define
name|SHR_MEM_VALIDITY_LIC_UPGRADE_KEY_IN_EFFECT
value|0x00000010
define|#
directive|define
name|SHR_MEM_VALIDITY_LIC_NO_KEY_IN_EFFECT
value|0x00000020
comment|/* Active MFW */
define|#
directive|define
name|SHR_MEM_VALIDITY_ACTIVE_MFW_UNKNOWN
value|0x00000000
define|#
directive|define
name|SHR_MEM_VALIDITY_ACTIVE_MFW_MASK
value|0x000001c0
define|#
directive|define
name|SHR_MEM_VALIDITY_ACTIVE_MFW_IPMI
value|0x00000040
define|#
directive|define
name|SHR_MEM_VALIDITY_ACTIVE_MFW_UMP
value|0x00000080
define|#
directive|define
name|SHR_MEM_VALIDITY_ACTIVE_MFW_NCSI
value|0x000000c0
define|#
directive|define
name|SHR_MEM_VALIDITY_ACTIVE_MFW_NONE
value|0x000001c0
name|struct
name|shm_dev_info
name|dev_info
decl_stmt|;
comment|/* 0x8     (0x438) */
name|license_key_t
name|drv_lic_key
index|[
name|PORT_MAX
index|]
decl_stmt|;
comment|/* 0x440 (52*2=0x68) */
comment|/* FW information (for internal FW use) */
name|uint32_t
name|fw_info_fio_offset
decl_stmt|;
comment|/* 0x4a8       (0x4) */
name|struct
name|mgmtfw_state
name|mgmtfw_state
decl_stmt|;
comment|/* 0x4ac     (0x1b8) */
name|struct
name|drv_port_mb
name|port_mb
index|[
name|PORT_MAX
index|]
decl_stmt|;
comment|/* 0x664 (16*2=0x20) */
ifdef|#
directive|ifdef
name|BMAPI
comment|/* This is a variable length array */
comment|/* the number of function depends on the chip type */
name|struct
name|drv_func_mb
name|func_mb
index|[
literal|1
index|]
decl_stmt|;
comment|/* 0x684 (44*2/4/8=0x58/0xb0/0x160) */
else|#
directive|else
comment|/* the number of function depends on the chip type */
name|struct
name|drv_func_mb
name|func_mb
index|[]
decl_stmt|;
comment|/* 0x684 (44*2/4/8=0x58/0xb0/0x160) */
endif|#
directive|endif
comment|/* BMAPI */
block|}
struct|;
end_struct

begin_comment
comment|/* 57710 = 0x6dc | 57711 = 0x7E4 | 57712 = 0x734 */
end_comment

begin_comment
comment|/****************************************************************************  * Shared Memory 2 Region                                                   *  ****************************************************************************/
end_comment

begin_comment
comment|/* The fw_flr_ack is actually built in the following way:                   */
end_comment

begin_comment
comment|/* 8 bit:  PF ack                                                           */
end_comment

begin_comment
comment|/* 64 bit: VF ack                                                           */
end_comment

begin_comment
comment|/* 8 bit:  ios_dis_ack                                                      */
end_comment

begin_comment
comment|/* In order to maintain endianity in the mailbox hsi, we want to keep using */
end_comment

begin_comment
comment|/* uint32_t. The fw must have the VF right after the PF since this is how it     */
end_comment

begin_comment
comment|/* access arrays(it expects always the VF to reside after the PF, and that  */
end_comment

begin_comment
comment|/* makes the calculation much easier for it. )                              */
end_comment

begin_comment
comment|/* In order to answer both limitations, and keep the struct small, the code */
end_comment

begin_comment
comment|/* will abuse the structure defined here to achieve the actual partition    */
end_comment

begin_comment
comment|/* above                                                                    */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_struct
struct|struct
name|fw_flr_ack
block|{
name|uint32_t
name|pf_ack
decl_stmt|;
name|uint32_t
name|vf_ack
decl_stmt|;
name|uint32_t
name|iov_dis_ack
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fw_flr_mb
block|{
name|uint32_t
name|aggint
decl_stmt|;
name|uint32_t
name|opgen_addr
decl_stmt|;
name|struct
name|fw_flr_ack
name|ack
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|eee_remote_vals
block|{
name|uint32_t
name|tx_tw
decl_stmt|;
name|uint32_t
name|rx_tw
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**** SUPPORT FOR SHMEM ARRRAYS ***  * The SHMEM HSI is aligned on 32 bit boundaries which makes it difficult to  * define arrays with storage types smaller then unsigned dwords.  * The macros below add generic support for SHMEM arrays with numeric elements  * that can span 2,4,8 or 16 bits. The array underlying type is a 32 bit dword  * array with individual bit-filed elements accessed using shifts and masks.  *  */
end_comment

begin_comment
comment|/* eb is the bitwidth of a single element */
end_comment

begin_define
define|#
directive|define
name|SHMEM_ARRAY_MASK
parameter_list|(
name|eb
parameter_list|)
value|((1<<(eb))-1)
end_define

begin_define
define|#
directive|define
name|SHMEM_ARRAY_ENTRY
parameter_list|(
name|i
parameter_list|,
name|eb
parameter_list|)
value|((i)/(32/(eb)))
end_define

begin_comment
comment|/* the bit-position macro allows the used to flip the order of the arrays  * elements on a per byte or word boundary.  *  * example: an array with 8 entries each 4 bit wide. This array will fit into  * a single dword. The diagrmas below show the array order of the nibbles.  *  * SHMEM_ARRAY_BITPOS(i, 4, 4) defines the stadard ordering:  *  *                |                |                |               |  *   0    |   1   |   2    |   3   |   4    |   5   |   6   |   7   |  *                |                |                |               |  *  * SHMEM_ARRAY_BITPOS(i, 4, 8) defines a flip ordering per byte:  *  *                |                |                |               |  *   1   |   0    |   3    |   2   |   5    |   4   |   7   |   6   |  *                |                |                |               |  *  * SHMEM_ARRAY_BITPOS(i, 4, 16) defines a flip ordering per word:  *  *                |                |                |               |  *   3   |   2    |   1   |   0    |   7   |   6    |   5   |   4   |  *                |                |                |               |  */
end_comment

begin_define
define|#
directive|define
name|SHMEM_ARRAY_BITPOS
parameter_list|(
name|i
parameter_list|,
name|eb
parameter_list|,
name|fb
parameter_list|)
define|\
value|((((32/(fb)) - 1 - ((i)/((fb)/(eb))) % (32/(fb))) * (fb)) + \ 	(((i)%((fb)/(eb))) * (eb)))
end_define

begin_define
define|#
directive|define
name|SHMEM_ARRAY_GET
parameter_list|(
name|a
parameter_list|,
name|i
parameter_list|,
name|eb
parameter_list|,
name|fb
parameter_list|)
define|\
value|((a[SHMEM_ARRAY_ENTRY(i, eb)]>> SHMEM_ARRAY_BITPOS(i, eb, fb))&  \ 	SHMEM_ARRAY_MASK(eb))
end_define

begin_define
define|#
directive|define
name|SHMEM_ARRAY_SET
parameter_list|(
name|a
parameter_list|,
name|i
parameter_list|,
name|eb
parameter_list|,
name|fb
parameter_list|,
name|val
parameter_list|)
define|\
value|do {									   \ 	a[SHMEM_ARRAY_ENTRY(i, eb)]&= ~(SHMEM_ARRAY_MASK(eb)<<	   \ 	SHMEM_ARRAY_BITPOS(i, eb, fb));					   \ 	a[SHMEM_ARRAY_ENTRY(i, eb)] |= (((val)& SHMEM_ARRAY_MASK(eb))<<  \ 	SHMEM_ARRAY_BITPOS(i, eb, fb));					   \ } while (0)
end_define

begin_comment
comment|/****START OF DCBX STRUCTURES DECLARATIONS****/
end_comment

begin_define
define|#
directive|define
name|DCBX_MAX_NUM_PRI_PG_ENTRIES
value|8
end_define

begin_define
define|#
directive|define
name|DCBX_PRI_PG_BITWIDTH
value|4
end_define

begin_define
define|#
directive|define
name|DCBX_PRI_PG_FBITS
value|8
end_define

begin_define
define|#
directive|define
name|DCBX_PRI_PG_GET
parameter_list|(
name|a
parameter_list|,
name|i
parameter_list|)
define|\
value|SHMEM_ARRAY_GET(a, i, DCBX_PRI_PG_BITWIDTH, DCBX_PRI_PG_FBITS)
end_define

begin_define
define|#
directive|define
name|DCBX_PRI_PG_SET
parameter_list|(
name|a
parameter_list|,
name|i
parameter_list|,
name|val
parameter_list|)
define|\
value|SHMEM_ARRAY_SET(a, i, DCBX_PRI_PG_BITWIDTH, DCBX_PRI_PG_FBITS, val)
end_define

begin_define
define|#
directive|define
name|DCBX_MAX_NUM_PG_BW_ENTRIES
value|8
end_define

begin_define
define|#
directive|define
name|DCBX_BW_PG_BITWIDTH
value|8
end_define

begin_define
define|#
directive|define
name|DCBX_PG_BW_GET
parameter_list|(
name|a
parameter_list|,
name|i
parameter_list|)
define|\
value|SHMEM_ARRAY_GET(a, i, DCBX_BW_PG_BITWIDTH, DCBX_BW_PG_BITWIDTH)
end_define

begin_define
define|#
directive|define
name|DCBX_PG_BW_SET
parameter_list|(
name|a
parameter_list|,
name|i
parameter_list|,
name|val
parameter_list|)
define|\
value|SHMEM_ARRAY_SET(a, i, DCBX_BW_PG_BITWIDTH, DCBX_BW_PG_BITWIDTH, val)
end_define

begin_define
define|#
directive|define
name|DCBX_STRICT_PRI_PG
value|15
end_define

begin_define
define|#
directive|define
name|DCBX_MAX_APP_PROTOCOL
value|16
end_define

begin_define
define|#
directive|define
name|DCBX_MAX_APP_LOCAL
value|32
end_define

begin_define
define|#
directive|define
name|FCOE_APP_IDX
value|0
end_define

begin_define
define|#
directive|define
name|ISCSI_APP_IDX
value|1
end_define

begin_define
define|#
directive|define
name|PREDEFINED_APP_IDX_MAX
value|2
end_define

begin_comment
comment|/* Big/Little endian have the same representation. */
end_comment

begin_struct
struct|struct
name|dcbx_ets_feature
block|{
comment|/* 	 * For Admin MIB - is this feature supported by the 	 * driver | For Local MIB - should this feature be enabled. 	 */
name|uint32_t
name|enabled
decl_stmt|;
name|uint32_t
name|pg_bw_tbl
index|[
literal|2
index|]
decl_stmt|;
name|uint32_t
name|pri_pg_tbl
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Driver structure in LE */
end_comment

begin_struct
struct|struct
name|dcbx_pfc_feature
block|{
ifdef|#
directive|ifdef
name|__BIG_ENDIAN
name|uint8_t
name|pri_en_bitmap
decl_stmt|;
define|#
directive|define
name|DCBX_PFC_PRI_0
value|0x01
define|#
directive|define
name|DCBX_PFC_PRI_1
value|0x02
define|#
directive|define
name|DCBX_PFC_PRI_2
value|0x04
define|#
directive|define
name|DCBX_PFC_PRI_3
value|0x08
define|#
directive|define
name|DCBX_PFC_PRI_4
value|0x10
define|#
directive|define
name|DCBX_PFC_PRI_5
value|0x20
define|#
directive|define
name|DCBX_PFC_PRI_6
value|0x40
define|#
directive|define
name|DCBX_PFC_PRI_7
value|0x80
name|uint8_t
name|pfc_caps
decl_stmt|;
name|uint8_t
name|reserved
decl_stmt|;
name|uint8_t
name|enabled
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint8_t
name|enabled
decl_stmt|;
name|uint8_t
name|reserved
decl_stmt|;
name|uint8_t
name|pfc_caps
decl_stmt|;
name|uint8_t
name|pri_en_bitmap
decl_stmt|;
define|#
directive|define
name|DCBX_PFC_PRI_0
value|0x01
define|#
directive|define
name|DCBX_PFC_PRI_1
value|0x02
define|#
directive|define
name|DCBX_PFC_PRI_2
value|0x04
define|#
directive|define
name|DCBX_PFC_PRI_3
value|0x08
define|#
directive|define
name|DCBX_PFC_PRI_4
value|0x10
define|#
directive|define
name|DCBX_PFC_PRI_5
value|0x20
define|#
directive|define
name|DCBX_PFC_PRI_6
value|0x40
define|#
directive|define
name|DCBX_PFC_PRI_7
value|0x80
endif|#
directive|endif
block|}
struct|;
end_struct

begin_struct
struct|struct
name|dcbx_app_priority_entry
block|{
ifdef|#
directive|ifdef
name|__BIG_ENDIAN
name|uint16_t
name|app_id
decl_stmt|;
name|uint8_t
name|pri_bitmap
decl_stmt|;
name|uint8_t
name|appBitfield
decl_stmt|;
define|#
directive|define
name|DCBX_APP_ENTRY_VALID
value|0x01
define|#
directive|define
name|DCBX_APP_ENTRY_SF_MASK
value|0x30
define|#
directive|define
name|DCBX_APP_ENTRY_SF_SHIFT
value|4
define|#
directive|define
name|DCBX_APP_SF_ETH_TYPE
value|0x10
define|#
directive|define
name|DCBX_APP_SF_PORT
value|0x20
define|#
directive|define
name|DCBX_APP_PRI_0
value|0x01
define|#
directive|define
name|DCBX_APP_PRI_1
value|0x02
define|#
directive|define
name|DCBX_APP_PRI_2
value|0x04
define|#
directive|define
name|DCBX_APP_PRI_3
value|0x08
define|#
directive|define
name|DCBX_APP_PRI_4
value|0x10
define|#
directive|define
name|DCBX_APP_PRI_5
value|0x20
define|#
directive|define
name|DCBX_APP_PRI_6
value|0x40
define|#
directive|define
name|DCBX_APP_PRI_7
value|0x80
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint8_t
name|appBitfield
decl_stmt|;
define|#
directive|define
name|DCBX_APP_ENTRY_VALID
value|0x01
define|#
directive|define
name|DCBX_APP_ENTRY_SF_MASK
value|0x30
define|#
directive|define
name|DCBX_APP_ENTRY_SF_SHIFT
value|4
define|#
directive|define
name|DCBX_APP_SF_ETH_TYPE
value|0x10
define|#
directive|define
name|DCBX_APP_SF_PORT
value|0x20
name|uint8_t
name|pri_bitmap
decl_stmt|;
name|uint16_t
name|app_id
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/* FW structure in BE */
end_comment

begin_struct
struct|struct
name|dcbx_app_priority_feature
block|{
ifdef|#
directive|ifdef
name|__BIG_ENDIAN
name|uint8_t
name|reserved
decl_stmt|;
name|uint8_t
name|default_pri
decl_stmt|;
name|uint8_t
name|tc_supported
decl_stmt|;
name|uint8_t
name|enabled
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint8_t
name|enabled
decl_stmt|;
name|uint8_t
name|tc_supported
decl_stmt|;
name|uint8_t
name|default_pri
decl_stmt|;
name|uint8_t
name|reserved
decl_stmt|;
endif|#
directive|endif
name|struct
name|dcbx_app_priority_entry
name|app_pri_tbl
index|[
name|DCBX_MAX_APP_PROTOCOL
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* FW structure in BE */
end_comment

begin_struct
struct|struct
name|dcbx_features
block|{
comment|/* PG feature */
name|struct
name|dcbx_ets_feature
name|ets
decl_stmt|;
comment|/* PFC feature */
name|struct
name|dcbx_pfc_feature
name|pfc
decl_stmt|;
comment|/* APP feature */
name|struct
name|dcbx_app_priority_feature
name|app
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* LLDP protocol parameters */
end_comment

begin_comment
comment|/* FW structure in BE */
end_comment

begin_struct
struct|struct
name|lldp_params
block|{
ifdef|#
directive|ifdef
name|__BIG_ENDIAN
name|uint8_t
name|msg_fast_tx_interval
decl_stmt|;
name|uint8_t
name|msg_tx_hold
decl_stmt|;
name|uint8_t
name|msg_tx_interval
decl_stmt|;
name|uint8_t
name|admin_status
decl_stmt|;
define|#
directive|define
name|LLDP_TX_ONLY
value|0x01
define|#
directive|define
name|LLDP_RX_ONLY
value|0x02
define|#
directive|define
name|LLDP_TX_RX
value|0x03
define|#
directive|define
name|LLDP_DISABLED
value|0x04
name|uint8_t
name|reserved1
decl_stmt|;
name|uint8_t
name|tx_fast
decl_stmt|;
name|uint8_t
name|tx_crd_max
decl_stmt|;
name|uint8_t
name|tx_crd
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint8_t
name|admin_status
decl_stmt|;
define|#
directive|define
name|LLDP_TX_ONLY
value|0x01
define|#
directive|define
name|LLDP_RX_ONLY
value|0x02
define|#
directive|define
name|LLDP_TX_RX
value|0x03
define|#
directive|define
name|LLDP_DISABLED
value|0x04
name|uint8_t
name|msg_tx_interval
decl_stmt|;
name|uint8_t
name|msg_tx_hold
decl_stmt|;
name|uint8_t
name|msg_fast_tx_interval
decl_stmt|;
name|uint8_t
name|tx_crd
decl_stmt|;
name|uint8_t
name|tx_crd_max
decl_stmt|;
name|uint8_t
name|tx_fast
decl_stmt|;
name|uint8_t
name|reserved1
decl_stmt|;
endif|#
directive|endif
define|#
directive|define
name|REM_CHASSIS_ID_STAT_LEN
value|4
define|#
directive|define
name|REM_PORT_ID_STAT_LEN
value|4
comment|/* Holds remote Chassis ID TLV header, subtype and 9B of payload. */
name|uint32_t
name|peer_chassis_id
index|[
name|REM_CHASSIS_ID_STAT_LEN
index|]
decl_stmt|;
comment|/* Holds remote Port ID TLV header, subtype and 9B of payload. */
name|uint32_t
name|peer_port_id
index|[
name|REM_PORT_ID_STAT_LEN
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|lldp_dcbx_stat
block|{
define|#
directive|define
name|LOCAL_CHASSIS_ID_STAT_LEN
value|2
define|#
directive|define
name|LOCAL_PORT_ID_STAT_LEN
value|2
comment|/* Holds local Chassis ID 8B payload of constant subtype 4. */
name|uint32_t
name|local_chassis_id
index|[
name|LOCAL_CHASSIS_ID_STAT_LEN
index|]
decl_stmt|;
comment|/* Holds local Port ID 8B payload of constant subtype 3. */
name|uint32_t
name|local_port_id
index|[
name|LOCAL_PORT_ID_STAT_LEN
index|]
decl_stmt|;
comment|/* Number of DCBX frames transmitted. */
name|uint32_t
name|num_tx_dcbx_pkts
decl_stmt|;
comment|/* Number of DCBX frames received. */
name|uint32_t
name|num_rx_dcbx_pkts
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* ADMIN MIB - DCBX local machine default configuration. */
end_comment

begin_struct
struct|struct
name|lldp_admin_mib
block|{
name|uint32_t
name|ver_cfg_flags
decl_stmt|;
define|#
directive|define
name|DCBX_ETS_CONFIG_TX_ENABLED
value|0x00000001
define|#
directive|define
name|DCBX_PFC_CONFIG_TX_ENABLED
value|0x00000002
define|#
directive|define
name|DCBX_APP_CONFIG_TX_ENABLED
value|0x00000004
define|#
directive|define
name|DCBX_ETS_RECO_TX_ENABLED
value|0x00000008
define|#
directive|define
name|DCBX_ETS_RECO_VALID
value|0x00000010
define|#
directive|define
name|DCBX_ETS_WILLING
value|0x00000020
define|#
directive|define
name|DCBX_PFC_WILLING
value|0x00000040
define|#
directive|define
name|DCBX_APP_WILLING
value|0x00000080
define|#
directive|define
name|DCBX_VERSION_CEE
value|0x00000100
define|#
directive|define
name|DCBX_VERSION_IEEE
value|0x00000200
define|#
directive|define
name|DCBX_DCBX_ENABLED
value|0x00000400
define|#
directive|define
name|DCBX_CEE_VERSION_MASK
value|0x0000f000
define|#
directive|define
name|DCBX_CEE_VERSION_SHIFT
value|12
define|#
directive|define
name|DCBX_CEE_MAX_VERSION_MASK
value|0x000f0000
define|#
directive|define
name|DCBX_CEE_MAX_VERSION_SHIFT
value|16
name|struct
name|dcbx_features
name|features
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* REMOTE MIB - remote machine DCBX configuration. */
end_comment

begin_struct
struct|struct
name|lldp_remote_mib
block|{
name|uint32_t
name|prefix_seq_num
decl_stmt|;
name|uint32_t
name|flags
decl_stmt|;
define|#
directive|define
name|DCBX_ETS_TLV_RX
value|0x00000001
define|#
directive|define
name|DCBX_PFC_TLV_RX
value|0x00000002
define|#
directive|define
name|DCBX_APP_TLV_RX
value|0x00000004
define|#
directive|define
name|DCBX_ETS_RX_ERROR
value|0x00000010
define|#
directive|define
name|DCBX_PFC_RX_ERROR
value|0x00000020
define|#
directive|define
name|DCBX_APP_RX_ERROR
value|0x00000040
define|#
directive|define
name|DCBX_ETS_REM_WILLING
value|0x00000100
define|#
directive|define
name|DCBX_PFC_REM_WILLING
value|0x00000200
define|#
directive|define
name|DCBX_APP_REM_WILLING
value|0x00000400
define|#
directive|define
name|DCBX_REMOTE_ETS_RECO_VALID
value|0x00001000
define|#
directive|define
name|DCBX_REMOTE_MIB_VALID
value|0x00002000
name|struct
name|dcbx_features
name|features
decl_stmt|;
name|uint32_t
name|suffix_seq_num
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* LOCAL MIB - operational DCBX configuration - transmitted on Tx LLDPDU. */
end_comment

begin_struct
struct|struct
name|lldp_local_mib
block|{
name|uint32_t
name|prefix_seq_num
decl_stmt|;
comment|/* Indicates if there is mismatch with negotiation results. */
name|uint32_t
name|error
decl_stmt|;
define|#
directive|define
name|DCBX_LOCAL_ETS_ERROR
value|0x00000001
define|#
directive|define
name|DCBX_LOCAL_PFC_ERROR
value|0x00000002
define|#
directive|define
name|DCBX_LOCAL_APP_ERROR
value|0x00000004
define|#
directive|define
name|DCBX_LOCAL_PFC_MISMATCH
value|0x00000010
define|#
directive|define
name|DCBX_LOCAL_APP_MISMATCH
value|0x00000020
define|#
directive|define
name|DCBX_REMOTE_MIB_ERROR
value|0x00000040
define|#
directive|define
name|DCBX_REMOTE_ETS_TLV_NOT_FOUND
value|0x00000080
define|#
directive|define
name|DCBX_REMOTE_PFC_TLV_NOT_FOUND
value|0x00000100
define|#
directive|define
name|DCBX_REMOTE_APP_TLV_NOT_FOUND
value|0x00000200
name|struct
name|dcbx_features
name|features
decl_stmt|;
name|uint32_t
name|suffix_seq_num
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|lldp_local_mib_ext
block|{
name|uint32_t
name|prefix_seq_num
decl_stmt|;
comment|/* APP TLV extension - 16 more entries for negotiation results*/
name|struct
name|dcbx_app_priority_entry
name|app_pri_tbl_ext
index|[
name|DCBX_MAX_APP_PROTOCOL
index|]
decl_stmt|;
name|uint32_t
name|suffix_seq_num
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/***END OF DCBX STRUCTURES DECLARATIONS***/
end_comment

begin_comment
comment|/***********************************************************/
end_comment

begin_comment
comment|/*                         Elink section                   */
end_comment

begin_comment
comment|/***********************************************************/
end_comment

begin_define
define|#
directive|define
name|SHMEM_LINK_CONFIG_SIZE
value|2
end_define

begin_struct
struct|struct
name|shmem_lfa
block|{
name|uint32_t
name|req_duplex
decl_stmt|;
define|#
directive|define
name|REQ_DUPLEX_PHY0_MASK
value|0x0000ffff
define|#
directive|define
name|REQ_DUPLEX_PHY0_SHIFT
value|0
define|#
directive|define
name|REQ_DUPLEX_PHY1_MASK
value|0xffff0000
define|#
directive|define
name|REQ_DUPLEX_PHY1_SHIFT
value|16
name|uint32_t
name|req_flow_ctrl
decl_stmt|;
define|#
directive|define
name|REQ_FLOW_CTRL_PHY0_MASK
value|0x0000ffff
define|#
directive|define
name|REQ_FLOW_CTRL_PHY0_SHIFT
value|0
define|#
directive|define
name|REQ_FLOW_CTRL_PHY1_MASK
value|0xffff0000
define|#
directive|define
name|REQ_FLOW_CTRL_PHY1_SHIFT
value|16
name|uint32_t
name|req_line_speed
decl_stmt|;
comment|/* Also determine AutoNeg */
define|#
directive|define
name|REQ_LINE_SPD_PHY0_MASK
value|0x0000ffff
define|#
directive|define
name|REQ_LINE_SPD_PHY0_SHIFT
value|0
define|#
directive|define
name|REQ_LINE_SPD_PHY1_MASK
value|0xffff0000
define|#
directive|define
name|REQ_LINE_SPD_PHY1_SHIFT
value|16
name|uint32_t
name|speed_cap_mask
index|[
name|SHMEM_LINK_CONFIG_SIZE
index|]
decl_stmt|;
name|uint32_t
name|additional_config
decl_stmt|;
define|#
directive|define
name|REQ_FC_AUTO_ADV_MASK
value|0x0000ffff
define|#
directive|define
name|REQ_FC_AUTO_ADV0_SHIFT
value|0
define|#
directive|define
name|NO_LFA_DUE_TO_DCC_MASK
value|0x00010000
name|uint32_t
name|lfa_sts
decl_stmt|;
define|#
directive|define
name|LFA_LINK_FLAP_REASON_OFFSET
value|0
define|#
directive|define
name|LFA_LINK_FLAP_REASON_MASK
value|0x000000ff
define|#
directive|define
name|LFA_LINK_DOWN
value|0x1
define|#
directive|define
name|LFA_LOOPBACK_ENABLED
value|0x2
define|#
directive|define
name|LFA_DUPLEX_MISMATCH
value|0x3
define|#
directive|define
name|LFA_MFW_IS_TOO_OLD
value|0x4
define|#
directive|define
name|LFA_LINK_SPEED_MISMATCH
value|0x5
define|#
directive|define
name|LFA_FLOW_CTRL_MISMATCH
value|0x6
define|#
directive|define
name|LFA_SPEED_CAP_MISMATCH
value|0x7
define|#
directive|define
name|LFA_DCC_LFA_DISABLED
value|0x8
define|#
directive|define
name|LFA_EEE_MISMATCH
value|0x9
define|#
directive|define
name|LINK_FLAP_AVOIDANCE_COUNT_OFFSET
value|8
define|#
directive|define
name|LINK_FLAP_AVOIDANCE_COUNT_MASK
value|0x0000ff00
define|#
directive|define
name|LINK_FLAP_COUNT_OFFSET
value|16
define|#
directive|define
name|LINK_FLAP_COUNT_MASK
value|0x00ff0000
define|#
directive|define
name|LFA_FLAGS_MASK
value|0xff000000
define|#
directive|define
name|SHMEM_LFA_DONT_CLEAR_STAT
value|(1<<24)
block|}
struct|;
end_struct

begin_comment
comment|/* Used to suppoert NSCI get OS driver version On driver load the version value will be set On driver unload driver value of 0x0 will be set */
end_comment

begin_struct
struct|struct
name|os_drv_ver
block|{
define|#
directive|define
name|DRV_VER_NOT_LOADED
value|0
comment|/*personalites orrder is importent */
define|#
directive|define
name|DRV_PERS_ETHERNET
value|0
define|#
directive|define
name|DRV_PERS_ISCSI
value|1
define|#
directive|define
name|DRV_PERS_FCOE
value|2
comment|/*shmem2 struct is constatnt can't add more personalites here*/
define|#
directive|define
name|MAX_DRV_PERS
value|3
name|uint32_t
name|versions
index|[
name|MAX_DRV_PERS
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|OEM_I2C_UUID_STR_ADDR
value|0x9f
end_define

begin_define
define|#
directive|define
name|OEM_I2C_CARD_SKU_STR_ADDR
value|0x3c
end_define

begin_define
define|#
directive|define
name|OEM_I2C_CARD_FN_STR_ADDR
value|0x48
end_define

begin_define
define|#
directive|define
name|OEM_I2C_CARD_NAME_STR_ADDR
value|0x10e
end_define

begin_define
define|#
directive|define
name|OEM_I2C_UUID_STR_LEN
value|16
end_define

begin_define
define|#
directive|define
name|OEM_I2C_CARD_SKU_STR_LEN
value|12
end_define

begin_define
define|#
directive|define
name|OEM_I2C_CARD_FN_STR_LEN
value|12
end_define

begin_define
define|#
directive|define
name|OEM_I2C_CARD_NAME_STR_LEN
value|128
end_define

begin_define
define|#
directive|define
name|OEM_I2C_CARD_VERSION_STR_LEN
value|36
end_define

begin_struct
struct|struct
name|oem_i2c_data_t
block|{
name|uint32_t
name|size
decl_stmt|;
name|uint8_t
name|uuid
index|[
name|OEM_I2C_UUID_STR_LEN
index|]
decl_stmt|;
name|uint8_t
name|card_sku
index|[
name|OEM_I2C_CARD_SKU_STR_LEN
index|]
decl_stmt|;
name|uint8_t
name|card_name
index|[
name|OEM_I2C_CARD_NAME_STR_LEN
index|]
decl_stmt|;
name|uint8_t
name|card_ver
index|[
name|OEM_I2C_CARD_VERSION_STR_LEN
index|]
decl_stmt|;
name|uint8_t
name|card_fn
index|[
name|OEM_I2C_CARD_FN_STR_LEN
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
name|curr_cfg_method_e
block|{
name|CURR_CFG_MET_NONE
init|=
literal|0
block|,
comment|/* default config */
name|CURR_CFG_MET_OS
init|=
literal|1
block|,
name|CURR_CFG_MET_VENDOR_SPEC
init|=
literal|2
block|,
comment|/* e.g. Option ROM, NPAR, O/S Cfg Utils */
name|CURR_CFG_MET_HP_OTHER
init|=
literal|3
block|,
name|CURR_CFG_MET_VC_CLP
init|=
literal|4
block|,
comment|/* C-Class SM-CLP */
name|CURR_CFG_MET_HP_CNU
init|=
literal|5
block|,
comment|/*  Converged Network Utility */
name|CURR_CFG_MET_HP_DCI
init|=
literal|6
block|,
comment|/* DCi (BD) changes */
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|FC_NPIV_WWPN_SIZE
value|8
end_define

begin_define
define|#
directive|define
name|FC_NPIV_WWNN_SIZE
value|8
end_define

begin_struct
struct|struct
name|bdn_npiv_settings
block|{
name|uint8_t
name|npiv_wwpn
index|[
name|FC_NPIV_WWPN_SIZE
index|]
decl_stmt|;
name|uint8_t
name|npiv_wwnn
index|[
name|FC_NPIV_WWNN_SIZE
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|bdn_fc_npiv_cfg
block|{
comment|/* hdr used internally by the MFW */
name|uint32_t
name|hdr
decl_stmt|;
name|uint32_t
name|num_of_npiv
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MAX_NUMBER_NPIV
value|64
end_define

begin_struct
struct|struct
name|bdn_fc_npiv_tbl
block|{
name|struct
name|bdn_fc_npiv_cfg
name|fc_npiv_cfg
decl_stmt|;
name|struct
name|bdn_npiv_settings
name|settings
index|[
name|MAX_NUMBER_NPIV
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mdump_driver_info
block|{
name|uint32_t
name|epoc
decl_stmt|;
name|uint32_t
name|drv_ver
decl_stmt|;
name|uint32_t
name|fw_ver
decl_stmt|;
name|uint32_t
name|valid_dump
decl_stmt|;
define|#
directive|define
name|FIRST_DUMP_VALID
value|(1<< 0)
define|#
directive|define
name|SECOND_DUMP_VALID
value|(1<< 1)
name|uint32_t
name|flags
decl_stmt|;
define|#
directive|define
name|ENABLE_ALL_TRIGGERS
value|(0x7fffffff)
define|#
directive|define
name|TRIGGER_MDUMP_ONCE
value|(1<< 31)
block|}
struct|;
end_struct

begin_struct
struct|struct
name|shmem2_region
block|{
name|uint32_t
name|size
decl_stmt|;
comment|/* 0x0000 */
name|uint32_t
name|dcc_support
decl_stmt|;
comment|/* 0x0004 */
define|#
directive|define
name|SHMEM_DCC_SUPPORT_NONE
value|0x00000000
define|#
directive|define
name|SHMEM_DCC_SUPPORT_DISABLE_ENABLE_PF_TLV
value|0x00000001
define|#
directive|define
name|SHMEM_DCC_SUPPORT_BANDWIDTH_ALLOCATION_TLV
value|0x00000004
define|#
directive|define
name|SHMEM_DCC_SUPPORT_CHANGE_MAC_ADDRESS_TLV
value|0x00000008
define|#
directive|define
name|SHMEM_DCC_SUPPORT_SET_PROTOCOL_TLV
value|0x00000040
define|#
directive|define
name|SHMEM_DCC_SUPPORT_SET_PRIORITY_TLV
value|0x00000080
name|uint32_t
name|ext_phy_fw_version2
index|[
name|PORT_MAX
index|]
decl_stmt|;
comment|/* 0x0008 */
comment|/* 	 * For backwards compatibility, if the mf_cfg_addr does not exist 	 * (the size filed is smaller than 0xc) the mf_cfg resides at the 	 * end of struct shmem_region 	 */
name|uint32_t
name|mf_cfg_addr
decl_stmt|;
comment|/* 0x0010 */
define|#
directive|define
name|SHMEM_MF_CFG_ADDR_NONE
value|0x00000000
name|struct
name|fw_flr_mb
name|flr_mb
decl_stmt|;
comment|/* 0x0014 */
name|uint32_t
name|dcbx_lldp_params_offset
decl_stmt|;
comment|/* 0x0028 */
define|#
directive|define
name|SHMEM_LLDP_DCBX_PARAMS_NONE
value|0x00000000
name|uint32_t
name|dcbx_neg_res_offset
decl_stmt|;
comment|/* 0x002c */
define|#
directive|define
name|SHMEM_DCBX_NEG_RES_NONE
value|0x00000000
name|uint32_t
name|dcbx_remote_mib_offset
decl_stmt|;
comment|/* 0x0030 */
define|#
directive|define
name|SHMEM_DCBX_REMOTE_MIB_NONE
value|0x00000000
comment|/* 	 * The other shmemX_base_addr holds the other path's shmem address 	 * required for example in case of common phy init, or for path1 to know 	 * the address of mcp debug trace which is located in offset from shmem 	 * of path0 	 */
name|uint32_t
name|other_shmem_base_addr
decl_stmt|;
comment|/* 0x0034 */
name|uint32_t
name|other_shmem2_base_addr
decl_stmt|;
comment|/* 0x0038 */
comment|/* 	 * mcp_vf_disabled is set by the MCP to indicate the driver about VFs 	 * which were disabled/flred 	 */
name|uint32_t
name|mcp_vf_disabled
index|[
name|E2_VF_MAX
operator|/
literal|32
index|]
decl_stmt|;
comment|/* 0x003c */
comment|/* 	 * drv_ack_vf_disabled is set by the PF driver to ack handled disabled 	 * VFs 	 */
name|uint32_t
name|drv_ack_vf_disabled
index|[
name|E2_FUNC_MAX
index|]
index|[
name|E2_VF_MAX
operator|/
literal|32
index|]
decl_stmt|;
comment|/* 0x0044 */
name|uint32_t
name|dcbx_lldp_dcbx_stat_offset
decl_stmt|;
comment|/* 0x0064 */
define|#
directive|define
name|SHMEM_LLDP_DCBX_STAT_NONE
value|0x00000000
comment|/* 	 * edebug_driver_if field is used to transfer messages between edebug 	 * app to the driver through shmem2. 	 * 	 * message format: 	 * bits 0-2 -  function number / instance of driver to perform request 	 * bits 3-5 -  op code / is_ack? 	 * bits 6-63 - data 	 */
name|uint32_t
name|edebug_driver_if
index|[
literal|2
index|]
decl_stmt|;
comment|/* 0x0068 */
define|#
directive|define
name|EDEBUG_DRIVER_IF_OP_CODE_GET_PHYS_ADDR
value|1
define|#
directive|define
name|EDEBUG_DRIVER_IF_OP_CODE_GET_BUS_ADDR
value|2
define|#
directive|define
name|EDEBUG_DRIVER_IF_OP_CODE_DISABLE_STAT
value|3
name|uint32_t
name|nvm_retain_bitmap_addr
decl_stmt|;
comment|/* 0x0070 */
comment|/* afex support of that driver */
name|uint32_t
name|afex_driver_support
decl_stmt|;
comment|/* 0x0074 */
define|#
directive|define
name|SHMEM_AFEX_VERSION_MASK
value|0x100f
define|#
directive|define
name|SHMEM_AFEX_SUPPORTED_VERSION_ONE
value|0x1001
define|#
directive|define
name|SHMEM_AFEX_REDUCED_DRV_LOADED
value|0x8000
comment|/* driver receives addr in scratchpad to which it should respond */
name|uint32_t
name|afex_scratchpad_addr_to_write
index|[
name|E2_FUNC_MAX
index|]
decl_stmt|;
comment|/* 	 * generic params from MCP to driver (value depends on the msg sent 	 * to driver 	 */
name|uint32_t
name|afex_param1_to_driver
index|[
name|E2_FUNC_MAX
index|]
decl_stmt|;
comment|/* 0x0088 */
name|uint32_t
name|afex_param2_to_driver
index|[
name|E2_FUNC_MAX
index|]
decl_stmt|;
comment|/* 0x0098 */
name|uint32_t
name|swim_base_addr
decl_stmt|;
comment|/* 0x00a8 */
name|uint32_t
name|swim_funcs
decl_stmt|;
comment|/* 0x00ac */
name|uint32_t
name|swim_main_cb
decl_stmt|;
comment|/* 0x00b0 */
comment|/* 	 * bitmap notifying which VIF profiles stored in nvram are enabled by 	 * switch 	 */
name|uint32_t
name|afex_profiles_enabled
index|[
literal|2
index|]
decl_stmt|;
comment|/* 0x00b4 */
comment|/* generic flags controlled by the driver */
name|uint32_t
name|drv_flags
decl_stmt|;
comment|/* 0x00bc */
define|#
directive|define
name|DRV_FLAGS_DCB_CONFIGURED
value|0x0
define|#
directive|define
name|DRV_FLAGS_DCB_CONFIGURATION_ABORTED
value|0x1
define|#
directive|define
name|DRV_FLAGS_DCB_MFW_CONFIGURED
value|0x2
define|#
directive|define
name|DRV_FLAGS_PORT_MASK
value|((1<< DRV_FLAGS_DCB_CONFIGURED) | \ 			(1<< DRV_FLAGS_DCB_CONFIGURATION_ABORTED) | \ 			(1<< DRV_FLAGS_DCB_MFW_CONFIGURED))
comment|/* Port offset*/
define|#
directive|define
name|DRV_FLAGS_P0_OFFSET
value|0
define|#
directive|define
name|DRV_FLAGS_P1_OFFSET
value|16
define|#
directive|define
name|DRV_FLAGS_GET_PORT_OFFSET
parameter_list|(
name|_port
parameter_list|)
value|((0 == _port) ? \ 						DRV_FLAGS_P0_OFFSET : \ 						DRV_FLAGS_P1_OFFSET)
define|#
directive|define
name|DRV_FLAGS_GET_PORT_MASK
parameter_list|(
name|_port
parameter_list|)
value|(DRV_FLAGS_PORT_MASK<< \ 	DRV_FLAGS_GET_PORT_OFFSET(_port))
define|#
directive|define
name|DRV_FLAGS_FILED_BY_PORT
parameter_list|(
name|_field_bit
parameter_list|,
name|_port
parameter_list|)
value|(1<< ( \ 	(_field_bit) + DRV_FLAGS_GET_PORT_OFFSET(_port)))
comment|/* pointer to extended dev_info shared data copied from nvm image */
name|uint32_t
name|extended_dev_info_shared_addr
decl_stmt|;
comment|/* 0x00c0 */
name|uint32_t
name|ncsi_oem_data_addr
decl_stmt|;
comment|/* 0x00c4 */
name|uint32_t
name|sensor_data_addr
decl_stmt|;
comment|/* 0x00c8 */
name|uint32_t
name|buffer_block_addr
decl_stmt|;
comment|/* 0x00cc */
name|uint32_t
name|sensor_data_req_update_interval
decl_stmt|;
comment|/* 0x00d0 */
name|uint32_t
name|temperature_in_half_celsius
decl_stmt|;
comment|/* 0x00d4 */
name|uint32_t
name|glob_struct_in_host
decl_stmt|;
comment|/* 0x00d8 */
name|uint32_t
name|dcbx_neg_res_ext_offset
decl_stmt|;
comment|/* 0x00dc */
define|#
directive|define
name|SHMEM_DCBX_NEG_RES_EXT_NONE
value|0x00000000
name|uint32_t
name|drv_capabilities_flag
index|[
name|E2_FUNC_MAX
index|]
decl_stmt|;
comment|/* 0x00e0 */
define|#
directive|define
name|DRV_FLAGS_CAPABILITIES_LOADED_SUPPORTED
value|0x00000001
define|#
directive|define
name|DRV_FLAGS_CAPABILITIES_LOADED_L2
value|0x00000002
define|#
directive|define
name|DRV_FLAGS_CAPABILITIES_LOADED_FCOE
value|0x00000004
define|#
directive|define
name|DRV_FLAGS_CAPABILITIES_LOADED_ISCSI
value|0x00000008
define|#
directive|define
name|DRV_FLAGS_MTU_MASK
value|0xffff0000
define|#
directive|define
name|DRV_FLAGS_MTU_SHIFT
value|16
name|uint32_t
name|extended_dev_info_shared_cfg_size
decl_stmt|;
comment|/* 0x00f0 */
name|uint32_t
name|dcbx_en
index|[
name|PORT_MAX
index|]
decl_stmt|;
comment|/* 0x00f4 */
comment|/* The offset points to the multi threaded meta structure */
name|uint32_t
name|multi_thread_data_offset
decl_stmt|;
comment|/* 0x00fc */
comment|/* address of DMAable host address holding values from the drivers */
name|uint32_t
name|drv_info_host_addr_lo
decl_stmt|;
comment|/* 0x0100 */
name|uint32_t
name|drv_info_host_addr_hi
decl_stmt|;
comment|/* 0x0104 */
comment|/* general values written by the MFW (such as current version) */
name|uint32_t
name|drv_info_control
decl_stmt|;
comment|/* 0x0108 */
define|#
directive|define
name|DRV_INFO_CONTROL_VER_MASK
value|0x000000ff
define|#
directive|define
name|DRV_INFO_CONTROL_VER_SHIFT
value|0
define|#
directive|define
name|DRV_INFO_CONTROL_OP_CODE_MASK
value|0x0000ff00
define|#
directive|define
name|DRV_INFO_CONTROL_OP_CODE_SHIFT
value|8
name|uint32_t
name|ibft_host_addr
decl_stmt|;
comment|/* initialized by option ROM */
comment|/* 0x010c */
name|struct
name|eee_remote_vals
name|eee_remote_vals
index|[
name|PORT_MAX
index|]
decl_stmt|;
comment|/* 0x0110 */
name|uint32_t
name|pf_allocation
index|[
name|E2_FUNC_MAX
index|]
decl_stmt|;
comment|/* 0x0120 */
define|#
directive|define
name|PF_ALLOACTION_MSIX_VECTORS_MASK
value|0x000000ff
comment|/* real value, as PCI config space can show only maximum of 64 vectors */
define|#
directive|define
name|PF_ALLOACTION_MSIX_VECTORS_SHIFT
value|0
comment|/* the status of EEE auto-negotiation 	 * bits 15:0 the configured tx-lpi entry timer value. Depends on bit 31. 	 * bits 19:16 the supported modes for EEE. 	 * bits 23:20 the speeds advertised for EEE. 	 * bits 27:24 the speeds the Link partner advertised for EEE. 	 * The supported/adv. modes in bits 27:19 originate from the 	 * SHMEM_EEE_XXX_ADV definitions (where XXX is replaced by speed). 	 * bit 28 when 1'b1 EEE was requested. 	 * bit 29 when 1'b1 tx lpi was requested. 	 * bit 30 when 1'b1 EEE was negotiated. Tx lpi will be asserted iff 	 * 30:29 are 2'b11. 	 * bit 31 when 1'b0 bits 15:0 contain a PORT_FEAT_CFG_EEE_ define as 	 * value. When 1'b1 those bits contains a value times 16 microseconds. 	 */
name|uint32_t
name|eee_status
index|[
name|PORT_MAX
index|]
decl_stmt|;
comment|/* 0x0130 */
define|#
directive|define
name|SHMEM_EEE_TIMER_MASK
value|0x0000ffff
define|#
directive|define
name|SHMEM_EEE_SUPPORTED_MASK
value|0x000f0000
define|#
directive|define
name|SHMEM_EEE_SUPPORTED_SHIFT
value|16
define|#
directive|define
name|SHMEM_EEE_ADV_STATUS_MASK
value|0x00f00000
define|#
directive|define
name|SHMEM_EEE_100M_ADV
value|(1<<0)
define|#
directive|define
name|SHMEM_EEE_1G_ADV
value|(1<<1)
define|#
directive|define
name|SHMEM_EEE_10G_ADV
value|(1<<2)
define|#
directive|define
name|SHMEM_EEE_ADV_STATUS_SHIFT
value|20
define|#
directive|define
name|SHMEM_EEE_LP_ADV_STATUS_MASK
value|0x0f000000
define|#
directive|define
name|SHMEM_EEE_LP_ADV_STATUS_SHIFT
value|24
define|#
directive|define
name|SHMEM_EEE_REQUESTED_BIT
value|0x10000000
define|#
directive|define
name|SHMEM_EEE_LPI_REQUESTED_BIT
value|0x20000000
define|#
directive|define
name|SHMEM_EEE_ACTIVE_BIT
value|0x40000000
define|#
directive|define
name|SHMEM_EEE_TIME_OUTPUT_BIT
value|0x80000000
name|uint32_t
name|sizeof_port_stats
decl_stmt|;
comment|/* 0x0138 */
comment|/* Link Flap Avoidance */
name|uint32_t
name|lfa_host_addr
index|[
name|PORT_MAX
index|]
decl_stmt|;
comment|/* 0x013c */
comment|/* External PHY temperature in deg C. */
name|uint32_t
name|extphy_temps_in_celsius
decl_stmt|;
comment|/* 0x0144 */
define|#
directive|define
name|EXTPHY1_TEMP_MASK
value|0x0000ffff
define|#
directive|define
name|EXTPHY1_TEMP_SHIFT
value|0
define|#
directive|define
name|ON_BOARD_TEMP_MASK
value|0xffff0000
define|#
directive|define
name|ON_BOARD_TEMP_SHIFT
value|16
name|uint32_t
name|ocdata_info_addr
decl_stmt|;
comment|/* Offset 0x148 */
name|uint32_t
name|drv_func_info_addr
decl_stmt|;
comment|/* Offset 0x14C */
name|uint32_t
name|drv_func_info_size
decl_stmt|;
comment|/* Offset 0x150 */
name|uint32_t
name|link_attr_sync
index|[
name|PORT_MAX
index|]
decl_stmt|;
comment|/* Offset 0x154 */
define|#
directive|define
name|LINK_ATTR_SYNC_KR2_ENABLE
value|0x00000001
define|#
directive|define
name|LINK_ATTR_84858
value|0x00000002
define|#
directive|define
name|LINK_SFP_EEPROM_COMP_CODE_MASK
value|0x0000ff00
define|#
directive|define
name|LINK_SFP_EEPROM_COMP_CODE_SHIFT
value|8
define|#
directive|define
name|LINK_SFP_EEPROM_COMP_CODE_SR
value|0x00001000
define|#
directive|define
name|LINK_SFP_EEPROM_COMP_CODE_LR
value|0x00002000
define|#
directive|define
name|LINK_SFP_EEPROM_COMP_CODE_LRM
value|0x00004000
name|uint32_t
name|ibft_host_addr_hi
decl_stmt|;
comment|/* Initialize by uEFI ROM Offset 0x158 */
name|uint32_t
name|fcode_ver
decl_stmt|;
comment|/* Offset 0x15c */
name|uint32_t
name|link_change_count
index|[
name|PORT_MAX
index|]
decl_stmt|;
comment|/* Offset 0x160-0x164 */
define|#
directive|define
name|LINK_CHANGE_COUNT_MASK
value|0xff
comment|/* Offset 0x168 */
comment|/* driver version for each personality*/
name|struct
name|os_drv_ver
name|func_os_drv_ver
index|[
name|E2_FUNC_MAX
index|]
decl_stmt|;
comment|/* Offset 0x16c */
comment|/* Flag to the driver that PF's drv_info_host_addr buffer was read  */
name|uint32_t
name|mfw_drv_indication
decl_stmt|;
comment|/* Offset 0x19c */
comment|/* We use inidcation for each PF (0..3) */
define|#
directive|define
name|MFW_DRV_IND_READ_DONE_OFFSET
parameter_list|(
name|_pf_
parameter_list|)
value|(1<< _pf_)
union|union
block|{
comment|/* For various OEMs */
comment|/* Offset 0x1a0 */
name|uint8_t
name|storage_boot_prog
index|[
name|E2_FUNC_MAX
index|]
decl_stmt|;
define|#
directive|define
name|STORAGE_BOOT_PROG_MASK
value|0x000000FF
define|#
directive|define
name|STORAGE_BOOT_PROG_NONE
value|0x00000000
define|#
directive|define
name|STORAGE_BOOT_PROG_ISCSI_IP_ACQUIRED
value|0x00000002
define|#
directive|define
name|STORAGE_BOOT_PROG_FCOE_FABRIC_LOGIN_SUCCESS
value|0x00000002
define|#
directive|define
name|STORAGE_BOOT_PROG_TARGET_FOUND
value|0x00000004
define|#
directive|define
name|STORAGE_BOOT_PROG_ISCSI_CHAP_SUCCESS
value|0x00000008
define|#
directive|define
name|STORAGE_BOOT_PROG_FCOE_LUN_FOUND
value|0x00000008
define|#
directive|define
name|STORAGE_BOOT_PROG_LOGGED_INTO_TGT
value|0x00000010
define|#
directive|define
name|STORAGE_BOOT_PROG_IMG_DOWNLOADED
value|0x00000020
define|#
directive|define
name|STORAGE_BOOT_PROG_OS_HANDOFF
value|0x00000040
define|#
directive|define
name|STORAGE_BOOT_PROG_COMPLETED
value|0x00000080
name|uint32_t
name|oem_i2c_data_addr
decl_stmt|;
block|}
name|u
union|;
comment|/* 9 entires for the C2S PCP map for each inner VLAN PCP + 1 default */
comment|/* For PCP values 0-3 use the map lower */
comment|/* 0xFF000000 - PCP 0, 0x00FF0000 - PCP 1, 	 * 0x0000FF00 - PCP 2, 0x000000FF PCP 3 	 */
name|uint32_t
name|c2s_pcp_map_lower
index|[
name|E2_FUNC_MAX
index|]
decl_stmt|;
comment|/* 0x1a4 */
comment|/* For PCP values 4-7 use the map upper */
comment|/* 0xFF000000 - PCP 4, 0x00FF0000 - PCP 5, 	 * 0x0000FF00 - PCP 6, 0x000000FF PCP 7 	 */
name|uint32_t
name|c2s_pcp_map_upper
index|[
name|E2_FUNC_MAX
index|]
decl_stmt|;
comment|/* 0x1b4 */
comment|/* For PCP default value get the MSB byte of the map default */
name|uint32_t
name|c2s_pcp_map_default
index|[
name|E2_FUNC_MAX
index|]
decl_stmt|;
comment|/* 0x1c4 */
comment|/* FC_NPIV table offset in NVRAM */
name|uint32_t
name|fc_npiv_nvram_tbl_addr
index|[
name|PORT_MAX
index|]
decl_stmt|;
comment|/* 0x1d4 */
comment|/* Shows last method that changed configuration of this device */
name|enum
name|curr_cfg_method_e
name|curr_cfg
decl_stmt|;
comment|/* 0x1dc */
comment|/* Storm FW version, shold be kept in the format 0xMMmmbbdd: 	 * MM - Major, mm - Minor, bb - Build ,dd - Drop 	 */
name|uint32_t
name|netproc_fw_ver
decl_stmt|;
comment|/* 0x1e0 */
comment|/* Option ROM SMASH CLP version */
name|uint32_t
name|clp_ver
decl_stmt|;
comment|/* 0x1e4 */
name|uint32_t
name|pcie_bus_num
decl_stmt|;
comment|/* 0x1e8 */
name|uint32_t
name|sriov_switch_mode
decl_stmt|;
comment|/* 0x1ec */
define|#
directive|define
name|SRIOV_SWITCH_MODE_NONE
value|0x0
define|#
directive|define
name|SRIOV_SWITCH_MODE_VEB
value|0x1
define|#
directive|define
name|SRIOV_SWITCH_MODE_VEPA
value|0x2
name|uint8_t
name|rsrv2
index|[
name|E2_FUNC_MAX
index|]
decl_stmt|;
comment|/* 0x1f0 */
name|uint32_t
name|img_inv_table_addr
decl_stmt|;
comment|/* Address to INV_TABLE_P */
comment|/* 0x1f4 */
name|uint32_t
name|mtu_size
index|[
name|E2_FUNC_MAX
index|]
decl_stmt|;
comment|/* 0x1f8 */
name|uint32_t
name|os_driver_state
index|[
name|E2_FUNC_MAX
index|]
decl_stmt|;
comment|/* 0x208 */
define|#
directive|define
name|OS_DRIVER_STATE_NOT_LOADED
value|0
comment|/* not installed */
define|#
directive|define
name|OS_DRIVER_STATE_LOADING
value|1
comment|/* transition state */
define|#
directive|define
name|OS_DRIVER_STATE_DISABLED
value|2
comment|/* installed but disabled */
define|#
directive|define
name|OS_DRIVER_STATE_ACTIVE
value|3
comment|/* installed and active */
comment|/* mini dump driver info */
name|struct
name|mdump_driver_info
name|drv_info
decl_stmt|;
comment|/* 0x218 */
comment|/* 0x22c */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|emac_stats
block|{
name|uint32_t
name|rx_stat_ifhcinoctets
decl_stmt|;
name|uint32_t
name|rx_stat_ifhcinbadoctets
decl_stmt|;
name|uint32_t
name|rx_stat_etherstatsfragments
decl_stmt|;
name|uint32_t
name|rx_stat_ifhcinucastpkts
decl_stmt|;
name|uint32_t
name|rx_stat_ifhcinmulticastpkts
decl_stmt|;
name|uint32_t
name|rx_stat_ifhcinbroadcastpkts
decl_stmt|;
name|uint32_t
name|rx_stat_dot3statsfcserrors
decl_stmt|;
name|uint32_t
name|rx_stat_dot3statsalignmenterrors
decl_stmt|;
name|uint32_t
name|rx_stat_dot3statscarriersenseerrors
decl_stmt|;
name|uint32_t
name|rx_stat_xonpauseframesreceived
decl_stmt|;
name|uint32_t
name|rx_stat_xoffpauseframesreceived
decl_stmt|;
name|uint32_t
name|rx_stat_maccontrolframesreceived
decl_stmt|;
name|uint32_t
name|rx_stat_xoffstateentered
decl_stmt|;
name|uint32_t
name|rx_stat_dot3statsframestoolong
decl_stmt|;
name|uint32_t
name|rx_stat_etherstatsjabbers
decl_stmt|;
name|uint32_t
name|rx_stat_etherstatsundersizepkts
decl_stmt|;
name|uint32_t
name|rx_stat_etherstatspkts64octets
decl_stmt|;
name|uint32_t
name|rx_stat_etherstatspkts65octetsto127octets
decl_stmt|;
name|uint32_t
name|rx_stat_etherstatspkts128octetsto255octets
decl_stmt|;
name|uint32_t
name|rx_stat_etherstatspkts256octetsto511octets
decl_stmt|;
name|uint32_t
name|rx_stat_etherstatspkts512octetsto1023octets
decl_stmt|;
name|uint32_t
name|rx_stat_etherstatspkts1024octetsto1522octets
decl_stmt|;
name|uint32_t
name|rx_stat_etherstatspktsover1522octets
decl_stmt|;
name|uint32_t
name|rx_stat_falsecarriererrors
decl_stmt|;
name|uint32_t
name|tx_stat_ifhcoutoctets
decl_stmt|;
name|uint32_t
name|tx_stat_ifhcoutbadoctets
decl_stmt|;
name|uint32_t
name|tx_stat_etherstatscollisions
decl_stmt|;
name|uint32_t
name|tx_stat_outxonsent
decl_stmt|;
name|uint32_t
name|tx_stat_outxoffsent
decl_stmt|;
name|uint32_t
name|tx_stat_flowcontroldone
decl_stmt|;
name|uint32_t
name|tx_stat_dot3statssinglecollisionframes
decl_stmt|;
name|uint32_t
name|tx_stat_dot3statsmultiplecollisionframes
decl_stmt|;
name|uint32_t
name|tx_stat_dot3statsdeferredtransmissions
decl_stmt|;
name|uint32_t
name|tx_stat_dot3statsexcessivecollisions
decl_stmt|;
name|uint32_t
name|tx_stat_dot3statslatecollisions
decl_stmt|;
name|uint32_t
name|tx_stat_ifhcoutucastpkts
decl_stmt|;
name|uint32_t
name|tx_stat_ifhcoutmulticastpkts
decl_stmt|;
name|uint32_t
name|tx_stat_ifhcoutbroadcastpkts
decl_stmt|;
name|uint32_t
name|tx_stat_etherstatspkts64octets
decl_stmt|;
name|uint32_t
name|tx_stat_etherstatspkts65octetsto127octets
decl_stmt|;
name|uint32_t
name|tx_stat_etherstatspkts128octetsto255octets
decl_stmt|;
name|uint32_t
name|tx_stat_etherstatspkts256octetsto511octets
decl_stmt|;
name|uint32_t
name|tx_stat_etherstatspkts512octetsto1023octets
decl_stmt|;
name|uint32_t
name|tx_stat_etherstatspkts1024octetsto1522octets
decl_stmt|;
name|uint32_t
name|tx_stat_etherstatspktsover1522octets
decl_stmt|;
name|uint32_t
name|tx_stat_dot3statsinternalmactransmiterrors
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|bmac1_stats
block|{
name|uint32_t
name|tx_stat_gtpkt_lo
decl_stmt|;
name|uint32_t
name|tx_stat_gtpkt_hi
decl_stmt|;
name|uint32_t
name|tx_stat_gtxpf_lo
decl_stmt|;
name|uint32_t
name|tx_stat_gtxpf_hi
decl_stmt|;
name|uint32_t
name|tx_stat_gtfcs_lo
decl_stmt|;
name|uint32_t
name|tx_stat_gtfcs_hi
decl_stmt|;
name|uint32_t
name|tx_stat_gtmca_lo
decl_stmt|;
name|uint32_t
name|tx_stat_gtmca_hi
decl_stmt|;
name|uint32_t
name|tx_stat_gtbca_lo
decl_stmt|;
name|uint32_t
name|tx_stat_gtbca_hi
decl_stmt|;
name|uint32_t
name|tx_stat_gtfrg_lo
decl_stmt|;
name|uint32_t
name|tx_stat_gtfrg_hi
decl_stmt|;
name|uint32_t
name|tx_stat_gtovr_lo
decl_stmt|;
name|uint32_t
name|tx_stat_gtovr_hi
decl_stmt|;
name|uint32_t
name|tx_stat_gt64_lo
decl_stmt|;
name|uint32_t
name|tx_stat_gt64_hi
decl_stmt|;
name|uint32_t
name|tx_stat_gt127_lo
decl_stmt|;
name|uint32_t
name|tx_stat_gt127_hi
decl_stmt|;
name|uint32_t
name|tx_stat_gt255_lo
decl_stmt|;
name|uint32_t
name|tx_stat_gt255_hi
decl_stmt|;
name|uint32_t
name|tx_stat_gt511_lo
decl_stmt|;
name|uint32_t
name|tx_stat_gt511_hi
decl_stmt|;
name|uint32_t
name|tx_stat_gt1023_lo
decl_stmt|;
name|uint32_t
name|tx_stat_gt1023_hi
decl_stmt|;
name|uint32_t
name|tx_stat_gt1518_lo
decl_stmt|;
name|uint32_t
name|tx_stat_gt1518_hi
decl_stmt|;
name|uint32_t
name|tx_stat_gt2047_lo
decl_stmt|;
name|uint32_t
name|tx_stat_gt2047_hi
decl_stmt|;
name|uint32_t
name|tx_stat_gt4095_lo
decl_stmt|;
name|uint32_t
name|tx_stat_gt4095_hi
decl_stmt|;
name|uint32_t
name|tx_stat_gt9216_lo
decl_stmt|;
name|uint32_t
name|tx_stat_gt9216_hi
decl_stmt|;
name|uint32_t
name|tx_stat_gt16383_lo
decl_stmt|;
name|uint32_t
name|tx_stat_gt16383_hi
decl_stmt|;
name|uint32_t
name|tx_stat_gtmax_lo
decl_stmt|;
name|uint32_t
name|tx_stat_gtmax_hi
decl_stmt|;
name|uint32_t
name|tx_stat_gtufl_lo
decl_stmt|;
name|uint32_t
name|tx_stat_gtufl_hi
decl_stmt|;
name|uint32_t
name|tx_stat_gterr_lo
decl_stmt|;
name|uint32_t
name|tx_stat_gterr_hi
decl_stmt|;
name|uint32_t
name|tx_stat_gtbyt_lo
decl_stmt|;
name|uint32_t
name|tx_stat_gtbyt_hi
decl_stmt|;
name|uint32_t
name|rx_stat_gr64_lo
decl_stmt|;
name|uint32_t
name|rx_stat_gr64_hi
decl_stmt|;
name|uint32_t
name|rx_stat_gr127_lo
decl_stmt|;
name|uint32_t
name|rx_stat_gr127_hi
decl_stmt|;
name|uint32_t
name|rx_stat_gr255_lo
decl_stmt|;
name|uint32_t
name|rx_stat_gr255_hi
decl_stmt|;
name|uint32_t
name|rx_stat_gr511_lo
decl_stmt|;
name|uint32_t
name|rx_stat_gr511_hi
decl_stmt|;
name|uint32_t
name|rx_stat_gr1023_lo
decl_stmt|;
name|uint32_t
name|rx_stat_gr1023_hi
decl_stmt|;
name|uint32_t
name|rx_stat_gr1518_lo
decl_stmt|;
name|uint32_t
name|rx_stat_gr1518_hi
decl_stmt|;
name|uint32_t
name|rx_stat_gr2047_lo
decl_stmt|;
name|uint32_t
name|rx_stat_gr2047_hi
decl_stmt|;
name|uint32_t
name|rx_stat_gr4095_lo
decl_stmt|;
name|uint32_t
name|rx_stat_gr4095_hi
decl_stmt|;
name|uint32_t
name|rx_stat_gr9216_lo
decl_stmt|;
name|uint32_t
name|rx_stat_gr9216_hi
decl_stmt|;
name|uint32_t
name|rx_stat_gr16383_lo
decl_stmt|;
name|uint32_t
name|rx_stat_gr16383_hi
decl_stmt|;
name|uint32_t
name|rx_stat_grmax_lo
decl_stmt|;
name|uint32_t
name|rx_stat_grmax_hi
decl_stmt|;
name|uint32_t
name|rx_stat_grpkt_lo
decl_stmt|;
name|uint32_t
name|rx_stat_grpkt_hi
decl_stmt|;
name|uint32_t
name|rx_stat_grfcs_lo
decl_stmt|;
name|uint32_t
name|rx_stat_grfcs_hi
decl_stmt|;
name|uint32_t
name|rx_stat_grmca_lo
decl_stmt|;
name|uint32_t
name|rx_stat_grmca_hi
decl_stmt|;
name|uint32_t
name|rx_stat_grbca_lo
decl_stmt|;
name|uint32_t
name|rx_stat_grbca_hi
decl_stmt|;
name|uint32_t
name|rx_stat_grxcf_lo
decl_stmt|;
name|uint32_t
name|rx_stat_grxcf_hi
decl_stmt|;
name|uint32_t
name|rx_stat_grxpf_lo
decl_stmt|;
name|uint32_t
name|rx_stat_grxpf_hi
decl_stmt|;
name|uint32_t
name|rx_stat_grxuo_lo
decl_stmt|;
name|uint32_t
name|rx_stat_grxuo_hi
decl_stmt|;
name|uint32_t
name|rx_stat_grjbr_lo
decl_stmt|;
name|uint32_t
name|rx_stat_grjbr_hi
decl_stmt|;
name|uint32_t
name|rx_stat_grovr_lo
decl_stmt|;
name|uint32_t
name|rx_stat_grovr_hi
decl_stmt|;
name|uint32_t
name|rx_stat_grflr_lo
decl_stmt|;
name|uint32_t
name|rx_stat_grflr_hi
decl_stmt|;
name|uint32_t
name|rx_stat_grmeg_lo
decl_stmt|;
name|uint32_t
name|rx_stat_grmeg_hi
decl_stmt|;
name|uint32_t
name|rx_stat_grmeb_lo
decl_stmt|;
name|uint32_t
name|rx_stat_grmeb_hi
decl_stmt|;
name|uint32_t
name|rx_stat_grbyt_lo
decl_stmt|;
name|uint32_t
name|rx_stat_grbyt_hi
decl_stmt|;
name|uint32_t
name|rx_stat_grund_lo
decl_stmt|;
name|uint32_t
name|rx_stat_grund_hi
decl_stmt|;
name|uint32_t
name|rx_stat_grfrg_lo
decl_stmt|;
name|uint32_t
name|rx_stat_grfrg_hi
decl_stmt|;
name|uint32_t
name|rx_stat_grerb_lo
decl_stmt|;
name|uint32_t
name|rx_stat_grerb_hi
decl_stmt|;
name|uint32_t
name|rx_stat_grfre_lo
decl_stmt|;
name|uint32_t
name|rx_stat_grfre_hi
decl_stmt|;
name|uint32_t
name|rx_stat_gripj_lo
decl_stmt|;
name|uint32_t
name|rx_stat_gripj_hi
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|bmac2_stats
block|{
name|uint32_t
name|tx_stat_gtpk_lo
decl_stmt|;
comment|/* gtpok */
name|uint32_t
name|tx_stat_gtpk_hi
decl_stmt|;
comment|/* gtpok */
name|uint32_t
name|tx_stat_gtxpf_lo
decl_stmt|;
comment|/* gtpf */
name|uint32_t
name|tx_stat_gtxpf_hi
decl_stmt|;
comment|/* gtpf */
name|uint32_t
name|tx_stat_gtpp_lo
decl_stmt|;
comment|/* NEW BMAC2 */
name|uint32_t
name|tx_stat_gtpp_hi
decl_stmt|;
comment|/* NEW BMAC2 */
name|uint32_t
name|tx_stat_gtfcs_lo
decl_stmt|;
name|uint32_t
name|tx_stat_gtfcs_hi
decl_stmt|;
name|uint32_t
name|tx_stat_gtuca_lo
decl_stmt|;
comment|/* NEW BMAC2 */
name|uint32_t
name|tx_stat_gtuca_hi
decl_stmt|;
comment|/* NEW BMAC2 */
name|uint32_t
name|tx_stat_gtmca_lo
decl_stmt|;
name|uint32_t
name|tx_stat_gtmca_hi
decl_stmt|;
name|uint32_t
name|tx_stat_gtbca_lo
decl_stmt|;
name|uint32_t
name|tx_stat_gtbca_hi
decl_stmt|;
name|uint32_t
name|tx_stat_gtovr_lo
decl_stmt|;
name|uint32_t
name|tx_stat_gtovr_hi
decl_stmt|;
name|uint32_t
name|tx_stat_gtfrg_lo
decl_stmt|;
name|uint32_t
name|tx_stat_gtfrg_hi
decl_stmt|;
name|uint32_t
name|tx_stat_gtpkt1_lo
decl_stmt|;
comment|/* gtpkt */
name|uint32_t
name|tx_stat_gtpkt1_hi
decl_stmt|;
comment|/* gtpkt */
name|uint32_t
name|tx_stat_gt64_lo
decl_stmt|;
name|uint32_t
name|tx_stat_gt64_hi
decl_stmt|;
name|uint32_t
name|tx_stat_gt127_lo
decl_stmt|;
name|uint32_t
name|tx_stat_gt127_hi
decl_stmt|;
name|uint32_t
name|tx_stat_gt255_lo
decl_stmt|;
name|uint32_t
name|tx_stat_gt255_hi
decl_stmt|;
name|uint32_t
name|tx_stat_gt511_lo
decl_stmt|;
name|uint32_t
name|tx_stat_gt511_hi
decl_stmt|;
name|uint32_t
name|tx_stat_gt1023_lo
decl_stmt|;
name|uint32_t
name|tx_stat_gt1023_hi
decl_stmt|;
name|uint32_t
name|tx_stat_gt1518_lo
decl_stmt|;
name|uint32_t
name|tx_stat_gt1518_hi
decl_stmt|;
name|uint32_t
name|tx_stat_gt2047_lo
decl_stmt|;
name|uint32_t
name|tx_stat_gt2047_hi
decl_stmt|;
name|uint32_t
name|tx_stat_gt4095_lo
decl_stmt|;
name|uint32_t
name|tx_stat_gt4095_hi
decl_stmt|;
name|uint32_t
name|tx_stat_gt9216_lo
decl_stmt|;
name|uint32_t
name|tx_stat_gt9216_hi
decl_stmt|;
name|uint32_t
name|tx_stat_gt16383_lo
decl_stmt|;
name|uint32_t
name|tx_stat_gt16383_hi
decl_stmt|;
name|uint32_t
name|tx_stat_gtmax_lo
decl_stmt|;
name|uint32_t
name|tx_stat_gtmax_hi
decl_stmt|;
name|uint32_t
name|tx_stat_gtufl_lo
decl_stmt|;
name|uint32_t
name|tx_stat_gtufl_hi
decl_stmt|;
name|uint32_t
name|tx_stat_gterr_lo
decl_stmt|;
name|uint32_t
name|tx_stat_gterr_hi
decl_stmt|;
name|uint32_t
name|tx_stat_gtbyt_lo
decl_stmt|;
name|uint32_t
name|tx_stat_gtbyt_hi
decl_stmt|;
name|uint32_t
name|rx_stat_gr64_lo
decl_stmt|;
name|uint32_t
name|rx_stat_gr64_hi
decl_stmt|;
name|uint32_t
name|rx_stat_gr127_lo
decl_stmt|;
name|uint32_t
name|rx_stat_gr127_hi
decl_stmt|;
name|uint32_t
name|rx_stat_gr255_lo
decl_stmt|;
name|uint32_t
name|rx_stat_gr255_hi
decl_stmt|;
name|uint32_t
name|rx_stat_gr511_lo
decl_stmt|;
name|uint32_t
name|rx_stat_gr511_hi
decl_stmt|;
name|uint32_t
name|rx_stat_gr1023_lo
decl_stmt|;
name|uint32_t
name|rx_stat_gr1023_hi
decl_stmt|;
name|uint32_t
name|rx_stat_gr1518_lo
decl_stmt|;
name|uint32_t
name|rx_stat_gr1518_hi
decl_stmt|;
name|uint32_t
name|rx_stat_gr2047_lo
decl_stmt|;
name|uint32_t
name|rx_stat_gr2047_hi
decl_stmt|;
name|uint32_t
name|rx_stat_gr4095_lo
decl_stmt|;
name|uint32_t
name|rx_stat_gr4095_hi
decl_stmt|;
name|uint32_t
name|rx_stat_gr9216_lo
decl_stmt|;
name|uint32_t
name|rx_stat_gr9216_hi
decl_stmt|;
name|uint32_t
name|rx_stat_gr16383_lo
decl_stmt|;
name|uint32_t
name|rx_stat_gr16383_hi
decl_stmt|;
name|uint32_t
name|rx_stat_grmax_lo
decl_stmt|;
name|uint32_t
name|rx_stat_grmax_hi
decl_stmt|;
name|uint32_t
name|rx_stat_grpkt_lo
decl_stmt|;
name|uint32_t
name|rx_stat_grpkt_hi
decl_stmt|;
name|uint32_t
name|rx_stat_grfcs_lo
decl_stmt|;
name|uint32_t
name|rx_stat_grfcs_hi
decl_stmt|;
name|uint32_t
name|rx_stat_gruca_lo
decl_stmt|;
name|uint32_t
name|rx_stat_gruca_hi
decl_stmt|;
name|uint32_t
name|rx_stat_grmca_lo
decl_stmt|;
name|uint32_t
name|rx_stat_grmca_hi
decl_stmt|;
name|uint32_t
name|rx_stat_grbca_lo
decl_stmt|;
name|uint32_t
name|rx_stat_grbca_hi
decl_stmt|;
name|uint32_t
name|rx_stat_grxpf_lo
decl_stmt|;
comment|/* grpf */
name|uint32_t
name|rx_stat_grxpf_hi
decl_stmt|;
comment|/* grpf */
name|uint32_t
name|rx_stat_grpp_lo
decl_stmt|;
name|uint32_t
name|rx_stat_grpp_hi
decl_stmt|;
name|uint32_t
name|rx_stat_grxuo_lo
decl_stmt|;
comment|/* gruo */
name|uint32_t
name|rx_stat_grxuo_hi
decl_stmt|;
comment|/* gruo */
name|uint32_t
name|rx_stat_grjbr_lo
decl_stmt|;
name|uint32_t
name|rx_stat_grjbr_hi
decl_stmt|;
name|uint32_t
name|rx_stat_grovr_lo
decl_stmt|;
name|uint32_t
name|rx_stat_grovr_hi
decl_stmt|;
name|uint32_t
name|rx_stat_grxcf_lo
decl_stmt|;
comment|/* grcf */
name|uint32_t
name|rx_stat_grxcf_hi
decl_stmt|;
comment|/* grcf */
name|uint32_t
name|rx_stat_grflr_lo
decl_stmt|;
name|uint32_t
name|rx_stat_grflr_hi
decl_stmt|;
name|uint32_t
name|rx_stat_grpok_lo
decl_stmt|;
name|uint32_t
name|rx_stat_grpok_hi
decl_stmt|;
name|uint32_t
name|rx_stat_grmeg_lo
decl_stmt|;
name|uint32_t
name|rx_stat_grmeg_hi
decl_stmt|;
name|uint32_t
name|rx_stat_grmeb_lo
decl_stmt|;
name|uint32_t
name|rx_stat_grmeb_hi
decl_stmt|;
name|uint32_t
name|rx_stat_grbyt_lo
decl_stmt|;
name|uint32_t
name|rx_stat_grbyt_hi
decl_stmt|;
name|uint32_t
name|rx_stat_grund_lo
decl_stmt|;
name|uint32_t
name|rx_stat_grund_hi
decl_stmt|;
name|uint32_t
name|rx_stat_grfrg_lo
decl_stmt|;
name|uint32_t
name|rx_stat_grfrg_hi
decl_stmt|;
name|uint32_t
name|rx_stat_grerb_lo
decl_stmt|;
comment|/* grerrbyt */
name|uint32_t
name|rx_stat_grerb_hi
decl_stmt|;
comment|/* grerrbyt */
name|uint32_t
name|rx_stat_grfre_lo
decl_stmt|;
comment|/* grfrerr */
name|uint32_t
name|rx_stat_grfre_hi
decl_stmt|;
comment|/* grfrerr */
name|uint32_t
name|rx_stat_gripj_lo
decl_stmt|;
name|uint32_t
name|rx_stat_gripj_hi
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mstat_stats
block|{
struct|struct
block|{
comment|/* OTE MSTAT on E3 has a bug where this register's contents are 		 * actually tx_gtxpok + tx_gtxpf + (possibly)tx_gtxpp 		 */
name|uint32_t
name|tx_gtxpok_lo
decl_stmt|;
name|uint32_t
name|tx_gtxpok_hi
decl_stmt|;
name|uint32_t
name|tx_gtxpf_lo
decl_stmt|;
name|uint32_t
name|tx_gtxpf_hi
decl_stmt|;
name|uint32_t
name|tx_gtxpp_lo
decl_stmt|;
name|uint32_t
name|tx_gtxpp_hi
decl_stmt|;
name|uint32_t
name|tx_gtfcs_lo
decl_stmt|;
name|uint32_t
name|tx_gtfcs_hi
decl_stmt|;
name|uint32_t
name|tx_gtuca_lo
decl_stmt|;
name|uint32_t
name|tx_gtuca_hi
decl_stmt|;
name|uint32_t
name|tx_gtmca_lo
decl_stmt|;
name|uint32_t
name|tx_gtmca_hi
decl_stmt|;
name|uint32_t
name|tx_gtgca_lo
decl_stmt|;
name|uint32_t
name|tx_gtgca_hi
decl_stmt|;
name|uint32_t
name|tx_gtpkt_lo
decl_stmt|;
name|uint32_t
name|tx_gtpkt_hi
decl_stmt|;
name|uint32_t
name|tx_gt64_lo
decl_stmt|;
name|uint32_t
name|tx_gt64_hi
decl_stmt|;
name|uint32_t
name|tx_gt127_lo
decl_stmt|;
name|uint32_t
name|tx_gt127_hi
decl_stmt|;
name|uint32_t
name|tx_gt255_lo
decl_stmt|;
name|uint32_t
name|tx_gt255_hi
decl_stmt|;
name|uint32_t
name|tx_gt511_lo
decl_stmt|;
name|uint32_t
name|tx_gt511_hi
decl_stmt|;
name|uint32_t
name|tx_gt1023_lo
decl_stmt|;
name|uint32_t
name|tx_gt1023_hi
decl_stmt|;
name|uint32_t
name|tx_gt1518_lo
decl_stmt|;
name|uint32_t
name|tx_gt1518_hi
decl_stmt|;
name|uint32_t
name|tx_gt2047_lo
decl_stmt|;
name|uint32_t
name|tx_gt2047_hi
decl_stmt|;
name|uint32_t
name|tx_gt4095_lo
decl_stmt|;
name|uint32_t
name|tx_gt4095_hi
decl_stmt|;
name|uint32_t
name|tx_gt9216_lo
decl_stmt|;
name|uint32_t
name|tx_gt9216_hi
decl_stmt|;
name|uint32_t
name|tx_gt16383_lo
decl_stmt|;
name|uint32_t
name|tx_gt16383_hi
decl_stmt|;
name|uint32_t
name|tx_gtufl_lo
decl_stmt|;
name|uint32_t
name|tx_gtufl_hi
decl_stmt|;
name|uint32_t
name|tx_gterr_lo
decl_stmt|;
name|uint32_t
name|tx_gterr_hi
decl_stmt|;
name|uint32_t
name|tx_gtbyt_lo
decl_stmt|;
name|uint32_t
name|tx_gtbyt_hi
decl_stmt|;
name|uint32_t
name|tx_collisions_lo
decl_stmt|;
name|uint32_t
name|tx_collisions_hi
decl_stmt|;
name|uint32_t
name|tx_singlecollision_lo
decl_stmt|;
name|uint32_t
name|tx_singlecollision_hi
decl_stmt|;
name|uint32_t
name|tx_multiplecollisions_lo
decl_stmt|;
name|uint32_t
name|tx_multiplecollisions_hi
decl_stmt|;
name|uint32_t
name|tx_deferred_lo
decl_stmt|;
name|uint32_t
name|tx_deferred_hi
decl_stmt|;
name|uint32_t
name|tx_excessivecollisions_lo
decl_stmt|;
name|uint32_t
name|tx_excessivecollisions_hi
decl_stmt|;
name|uint32_t
name|tx_latecollisions_lo
decl_stmt|;
name|uint32_t
name|tx_latecollisions_hi
decl_stmt|;
block|}
name|stats_tx
struct|;
struct|struct
block|{
name|uint32_t
name|rx_gr64_lo
decl_stmt|;
name|uint32_t
name|rx_gr64_hi
decl_stmt|;
name|uint32_t
name|rx_gr127_lo
decl_stmt|;
name|uint32_t
name|rx_gr127_hi
decl_stmt|;
name|uint32_t
name|rx_gr255_lo
decl_stmt|;
name|uint32_t
name|rx_gr255_hi
decl_stmt|;
name|uint32_t
name|rx_gr511_lo
decl_stmt|;
name|uint32_t
name|rx_gr511_hi
decl_stmt|;
name|uint32_t
name|rx_gr1023_lo
decl_stmt|;
name|uint32_t
name|rx_gr1023_hi
decl_stmt|;
name|uint32_t
name|rx_gr1518_lo
decl_stmt|;
name|uint32_t
name|rx_gr1518_hi
decl_stmt|;
name|uint32_t
name|rx_gr2047_lo
decl_stmt|;
name|uint32_t
name|rx_gr2047_hi
decl_stmt|;
name|uint32_t
name|rx_gr4095_lo
decl_stmt|;
name|uint32_t
name|rx_gr4095_hi
decl_stmt|;
name|uint32_t
name|rx_gr9216_lo
decl_stmt|;
name|uint32_t
name|rx_gr9216_hi
decl_stmt|;
name|uint32_t
name|rx_gr16383_lo
decl_stmt|;
name|uint32_t
name|rx_gr16383_hi
decl_stmt|;
name|uint32_t
name|rx_grpkt_lo
decl_stmt|;
name|uint32_t
name|rx_grpkt_hi
decl_stmt|;
name|uint32_t
name|rx_grfcs_lo
decl_stmt|;
name|uint32_t
name|rx_grfcs_hi
decl_stmt|;
name|uint32_t
name|rx_gruca_lo
decl_stmt|;
name|uint32_t
name|rx_gruca_hi
decl_stmt|;
name|uint32_t
name|rx_grmca_lo
decl_stmt|;
name|uint32_t
name|rx_grmca_hi
decl_stmt|;
name|uint32_t
name|rx_grbca_lo
decl_stmt|;
name|uint32_t
name|rx_grbca_hi
decl_stmt|;
name|uint32_t
name|rx_grxpf_lo
decl_stmt|;
name|uint32_t
name|rx_grxpf_hi
decl_stmt|;
name|uint32_t
name|rx_grxpp_lo
decl_stmt|;
name|uint32_t
name|rx_grxpp_hi
decl_stmt|;
name|uint32_t
name|rx_grxuo_lo
decl_stmt|;
name|uint32_t
name|rx_grxuo_hi
decl_stmt|;
name|uint32_t
name|rx_grovr_lo
decl_stmt|;
name|uint32_t
name|rx_grovr_hi
decl_stmt|;
name|uint32_t
name|rx_grxcf_lo
decl_stmt|;
name|uint32_t
name|rx_grxcf_hi
decl_stmt|;
name|uint32_t
name|rx_grflr_lo
decl_stmt|;
name|uint32_t
name|rx_grflr_hi
decl_stmt|;
name|uint32_t
name|rx_grpok_lo
decl_stmt|;
name|uint32_t
name|rx_grpok_hi
decl_stmt|;
name|uint32_t
name|rx_grbyt_lo
decl_stmt|;
name|uint32_t
name|rx_grbyt_hi
decl_stmt|;
name|uint32_t
name|rx_grund_lo
decl_stmt|;
name|uint32_t
name|rx_grund_hi
decl_stmt|;
name|uint32_t
name|rx_grfrg_lo
decl_stmt|;
name|uint32_t
name|rx_grfrg_hi
decl_stmt|;
name|uint32_t
name|rx_grerb_lo
decl_stmt|;
name|uint32_t
name|rx_grerb_hi
decl_stmt|;
name|uint32_t
name|rx_grfre_lo
decl_stmt|;
name|uint32_t
name|rx_grfre_hi
decl_stmt|;
name|uint32_t
name|rx_alignmenterrors_lo
decl_stmt|;
name|uint32_t
name|rx_alignmenterrors_hi
decl_stmt|;
name|uint32_t
name|rx_falsecarrier_lo
decl_stmt|;
name|uint32_t
name|rx_falsecarrier_hi
decl_stmt|;
name|uint32_t
name|rx_llfcmsgcnt_lo
decl_stmt|;
name|uint32_t
name|rx_llfcmsgcnt_hi
decl_stmt|;
block|}
name|stats_rx
struct|;
block|}
struct|;
end_struct

begin_union
union|union
name|mac_stats
block|{
name|struct
name|emac_stats
name|emac_stats
decl_stmt|;
name|struct
name|bmac1_stats
name|bmac1_stats
decl_stmt|;
name|struct
name|bmac2_stats
name|bmac2_stats
decl_stmt|;
name|struct
name|mstat_stats
name|mstat_stats
decl_stmt|;
block|}
union|;
end_union

begin_struct
struct|struct
name|mac_stx
block|{
comment|/* in_bad_octets */
name|uint32_t
name|rx_stat_ifhcinbadoctets_hi
decl_stmt|;
name|uint32_t
name|rx_stat_ifhcinbadoctets_lo
decl_stmt|;
comment|/* out_bad_octets */
name|uint32_t
name|tx_stat_ifhcoutbadoctets_hi
decl_stmt|;
name|uint32_t
name|tx_stat_ifhcoutbadoctets_lo
decl_stmt|;
comment|/* crc_receive_errors */
name|uint32_t
name|rx_stat_dot3statsfcserrors_hi
decl_stmt|;
name|uint32_t
name|rx_stat_dot3statsfcserrors_lo
decl_stmt|;
comment|/* alignment_errors */
name|uint32_t
name|rx_stat_dot3statsalignmenterrors_hi
decl_stmt|;
name|uint32_t
name|rx_stat_dot3statsalignmenterrors_lo
decl_stmt|;
comment|/* carrier_sense_errors */
name|uint32_t
name|rx_stat_dot3statscarriersenseerrors_hi
decl_stmt|;
name|uint32_t
name|rx_stat_dot3statscarriersenseerrors_lo
decl_stmt|;
comment|/* false_carrier_detections */
name|uint32_t
name|rx_stat_falsecarriererrors_hi
decl_stmt|;
name|uint32_t
name|rx_stat_falsecarriererrors_lo
decl_stmt|;
comment|/* runt_packets_received */
name|uint32_t
name|rx_stat_etherstatsundersizepkts_hi
decl_stmt|;
name|uint32_t
name|rx_stat_etherstatsundersizepkts_lo
decl_stmt|;
comment|/* jabber_packets_received */
name|uint32_t
name|rx_stat_dot3statsframestoolong_hi
decl_stmt|;
name|uint32_t
name|rx_stat_dot3statsframestoolong_lo
decl_stmt|;
comment|/* error_runt_packets_received */
name|uint32_t
name|rx_stat_etherstatsfragments_hi
decl_stmt|;
name|uint32_t
name|rx_stat_etherstatsfragments_lo
decl_stmt|;
comment|/* error_jabber_packets_received */
name|uint32_t
name|rx_stat_etherstatsjabbers_hi
decl_stmt|;
name|uint32_t
name|rx_stat_etherstatsjabbers_lo
decl_stmt|;
comment|/* control_frames_received */
name|uint32_t
name|rx_stat_maccontrolframesreceived_hi
decl_stmt|;
name|uint32_t
name|rx_stat_maccontrolframesreceived_lo
decl_stmt|;
name|uint32_t
name|rx_stat_mac_xpf_hi
decl_stmt|;
name|uint32_t
name|rx_stat_mac_xpf_lo
decl_stmt|;
name|uint32_t
name|rx_stat_mac_xcf_hi
decl_stmt|;
name|uint32_t
name|rx_stat_mac_xcf_lo
decl_stmt|;
comment|/* xoff_state_entered */
name|uint32_t
name|rx_stat_xoffstateentered_hi
decl_stmt|;
name|uint32_t
name|rx_stat_xoffstateentered_lo
decl_stmt|;
comment|/* pause_xon_frames_received */
name|uint32_t
name|rx_stat_xonpauseframesreceived_hi
decl_stmt|;
name|uint32_t
name|rx_stat_xonpauseframesreceived_lo
decl_stmt|;
comment|/* pause_xoff_frames_received */
name|uint32_t
name|rx_stat_xoffpauseframesreceived_hi
decl_stmt|;
name|uint32_t
name|rx_stat_xoffpauseframesreceived_lo
decl_stmt|;
comment|/* pause_xon_frames_transmitted */
name|uint32_t
name|tx_stat_outxonsent_hi
decl_stmt|;
name|uint32_t
name|tx_stat_outxonsent_lo
decl_stmt|;
comment|/* pause_xoff_frames_transmitted */
name|uint32_t
name|tx_stat_outxoffsent_hi
decl_stmt|;
name|uint32_t
name|tx_stat_outxoffsent_lo
decl_stmt|;
comment|/* flow_control_done */
name|uint32_t
name|tx_stat_flowcontroldone_hi
decl_stmt|;
name|uint32_t
name|tx_stat_flowcontroldone_lo
decl_stmt|;
comment|/* ether_stats_collisions */
name|uint32_t
name|tx_stat_etherstatscollisions_hi
decl_stmt|;
name|uint32_t
name|tx_stat_etherstatscollisions_lo
decl_stmt|;
comment|/* single_collision_transmit_frames */
name|uint32_t
name|tx_stat_dot3statssinglecollisionframes_hi
decl_stmt|;
name|uint32_t
name|tx_stat_dot3statssinglecollisionframes_lo
decl_stmt|;
comment|/* multiple_collision_transmit_frames */
name|uint32_t
name|tx_stat_dot3statsmultiplecollisionframes_hi
decl_stmt|;
name|uint32_t
name|tx_stat_dot3statsmultiplecollisionframes_lo
decl_stmt|;
comment|/* deferred_transmissions */
name|uint32_t
name|tx_stat_dot3statsdeferredtransmissions_hi
decl_stmt|;
name|uint32_t
name|tx_stat_dot3statsdeferredtransmissions_lo
decl_stmt|;
comment|/* excessive_collision_frames */
name|uint32_t
name|tx_stat_dot3statsexcessivecollisions_hi
decl_stmt|;
name|uint32_t
name|tx_stat_dot3statsexcessivecollisions_lo
decl_stmt|;
comment|/* late_collision_frames */
name|uint32_t
name|tx_stat_dot3statslatecollisions_hi
decl_stmt|;
name|uint32_t
name|tx_stat_dot3statslatecollisions_lo
decl_stmt|;
comment|/* frames_transmitted_64_bytes */
name|uint32_t
name|tx_stat_etherstatspkts64octets_hi
decl_stmt|;
name|uint32_t
name|tx_stat_etherstatspkts64octets_lo
decl_stmt|;
comment|/* frames_transmitted_65_127_bytes */
name|uint32_t
name|tx_stat_etherstatspkts65octetsto127octets_hi
decl_stmt|;
name|uint32_t
name|tx_stat_etherstatspkts65octetsto127octets_lo
decl_stmt|;
comment|/* frames_transmitted_128_255_bytes */
name|uint32_t
name|tx_stat_etherstatspkts128octetsto255octets_hi
decl_stmt|;
name|uint32_t
name|tx_stat_etherstatspkts128octetsto255octets_lo
decl_stmt|;
comment|/* frames_transmitted_256_511_bytes */
name|uint32_t
name|tx_stat_etherstatspkts256octetsto511octets_hi
decl_stmt|;
name|uint32_t
name|tx_stat_etherstatspkts256octetsto511octets_lo
decl_stmt|;
comment|/* frames_transmitted_512_1023_bytes */
name|uint32_t
name|tx_stat_etherstatspkts512octetsto1023octets_hi
decl_stmt|;
name|uint32_t
name|tx_stat_etherstatspkts512octetsto1023octets_lo
decl_stmt|;
comment|/* frames_transmitted_1024_1522_bytes */
name|uint32_t
name|tx_stat_etherstatspkts1024octetsto1522octets_hi
decl_stmt|;
name|uint32_t
name|tx_stat_etherstatspkts1024octetsto1522octets_lo
decl_stmt|;
comment|/* frames_transmitted_1523_9022_bytes */
name|uint32_t
name|tx_stat_etherstatspktsover1522octets_hi
decl_stmt|;
name|uint32_t
name|tx_stat_etherstatspktsover1522octets_lo
decl_stmt|;
name|uint32_t
name|tx_stat_mac_2047_hi
decl_stmt|;
name|uint32_t
name|tx_stat_mac_2047_lo
decl_stmt|;
name|uint32_t
name|tx_stat_mac_4095_hi
decl_stmt|;
name|uint32_t
name|tx_stat_mac_4095_lo
decl_stmt|;
name|uint32_t
name|tx_stat_mac_9216_hi
decl_stmt|;
name|uint32_t
name|tx_stat_mac_9216_lo
decl_stmt|;
name|uint32_t
name|tx_stat_mac_16383_hi
decl_stmt|;
name|uint32_t
name|tx_stat_mac_16383_lo
decl_stmt|;
comment|/* internal_mac_transmit_errors */
name|uint32_t
name|tx_stat_dot3statsinternalmactransmiterrors_hi
decl_stmt|;
name|uint32_t
name|tx_stat_dot3statsinternalmactransmiterrors_lo
decl_stmt|;
comment|/* if_out_discards */
name|uint32_t
name|tx_stat_mac_ufl_hi
decl_stmt|;
name|uint32_t
name|tx_stat_mac_ufl_lo
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MAC_STX_IDX_MAX
value|2
end_define

begin_struct
struct|struct
name|host_port_stats
block|{
name|uint32_t
name|host_port_stats_counter
decl_stmt|;
name|struct
name|mac_stx
name|mac_stx
index|[
name|MAC_STX_IDX_MAX
index|]
decl_stmt|;
name|uint32_t
name|brb_drop_hi
decl_stmt|;
name|uint32_t
name|brb_drop_lo
decl_stmt|;
name|uint32_t
name|not_used
decl_stmt|;
comment|/* obsolete as of MFW 7.2.1 */
name|uint32_t
name|pfc_frames_tx_hi
decl_stmt|;
name|uint32_t
name|pfc_frames_tx_lo
decl_stmt|;
name|uint32_t
name|pfc_frames_rx_hi
decl_stmt|;
name|uint32_t
name|pfc_frames_rx_lo
decl_stmt|;
name|uint32_t
name|eee_lpi_count_hi
decl_stmt|;
name|uint32_t
name|eee_lpi_count_lo
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|host_func_stats
block|{
name|uint32_t
name|host_func_stats_start
decl_stmt|;
name|uint32_t
name|total_bytes_received_hi
decl_stmt|;
name|uint32_t
name|total_bytes_received_lo
decl_stmt|;
name|uint32_t
name|total_bytes_transmitted_hi
decl_stmt|;
name|uint32_t
name|total_bytes_transmitted_lo
decl_stmt|;
name|uint32_t
name|total_unicast_packets_received_hi
decl_stmt|;
name|uint32_t
name|total_unicast_packets_received_lo
decl_stmt|;
name|uint32_t
name|total_multicast_packets_received_hi
decl_stmt|;
name|uint32_t
name|total_multicast_packets_received_lo
decl_stmt|;
name|uint32_t
name|total_broadcast_packets_received_hi
decl_stmt|;
name|uint32_t
name|total_broadcast_packets_received_lo
decl_stmt|;
name|uint32_t
name|total_unicast_packets_transmitted_hi
decl_stmt|;
name|uint32_t
name|total_unicast_packets_transmitted_lo
decl_stmt|;
name|uint32_t
name|total_multicast_packets_transmitted_hi
decl_stmt|;
name|uint32_t
name|total_multicast_packets_transmitted_lo
decl_stmt|;
name|uint32_t
name|total_broadcast_packets_transmitted_hi
decl_stmt|;
name|uint32_t
name|total_broadcast_packets_transmitted_lo
decl_stmt|;
name|uint32_t
name|valid_bytes_received_hi
decl_stmt|;
name|uint32_t
name|valid_bytes_received_lo
decl_stmt|;
name|uint32_t
name|host_func_stats_end
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* VIC definitions */
end_comment

begin_define
define|#
directive|define
name|VICSTATST_UIF_INDEX
value|2
end_define

begin_comment
comment|/*  * stats collected for afex.  * NOTE: structure is exactly as expected to be received by the switch.  *       order must remain exactly as is unless protocol changes !  */
end_comment

begin_struct
struct|struct
name|afex_stats
block|{
name|uint32_t
name|tx_unicast_frames_hi
decl_stmt|;
name|uint32_t
name|tx_unicast_frames_lo
decl_stmt|;
name|uint32_t
name|tx_unicast_bytes_hi
decl_stmt|;
name|uint32_t
name|tx_unicast_bytes_lo
decl_stmt|;
name|uint32_t
name|tx_multicast_frames_hi
decl_stmt|;
name|uint32_t
name|tx_multicast_frames_lo
decl_stmt|;
name|uint32_t
name|tx_multicast_bytes_hi
decl_stmt|;
name|uint32_t
name|tx_multicast_bytes_lo
decl_stmt|;
name|uint32_t
name|tx_broadcast_frames_hi
decl_stmt|;
name|uint32_t
name|tx_broadcast_frames_lo
decl_stmt|;
name|uint32_t
name|tx_broadcast_bytes_hi
decl_stmt|;
name|uint32_t
name|tx_broadcast_bytes_lo
decl_stmt|;
name|uint32_t
name|tx_frames_discarded_hi
decl_stmt|;
name|uint32_t
name|tx_frames_discarded_lo
decl_stmt|;
name|uint32_t
name|tx_frames_dropped_hi
decl_stmt|;
name|uint32_t
name|tx_frames_dropped_lo
decl_stmt|;
name|uint32_t
name|rx_unicast_frames_hi
decl_stmt|;
name|uint32_t
name|rx_unicast_frames_lo
decl_stmt|;
name|uint32_t
name|rx_unicast_bytes_hi
decl_stmt|;
name|uint32_t
name|rx_unicast_bytes_lo
decl_stmt|;
name|uint32_t
name|rx_multicast_frames_hi
decl_stmt|;
name|uint32_t
name|rx_multicast_frames_lo
decl_stmt|;
name|uint32_t
name|rx_multicast_bytes_hi
decl_stmt|;
name|uint32_t
name|rx_multicast_bytes_lo
decl_stmt|;
name|uint32_t
name|rx_broadcast_frames_hi
decl_stmt|;
name|uint32_t
name|rx_broadcast_frames_lo
decl_stmt|;
name|uint32_t
name|rx_broadcast_bytes_hi
decl_stmt|;
name|uint32_t
name|rx_broadcast_bytes_lo
decl_stmt|;
name|uint32_t
name|rx_frames_discarded_hi
decl_stmt|;
name|uint32_t
name|rx_frames_discarded_lo
decl_stmt|;
name|uint32_t
name|rx_frames_dropped_hi
decl_stmt|;
name|uint32_t
name|rx_frames_dropped_lo
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* To maintain backward compatibility between FW and drivers, new elements */
end_comment

begin_comment
comment|/* should be added to the end of the structure. */
end_comment

begin_comment
comment|/* Per  Port Statistics    */
end_comment

begin_struct
struct|struct
name|port_info
block|{
name|uint32_t
name|size
decl_stmt|;
comment|/* size of this structure (i.e. sizeof(port_info))  */
name|uint32_t
name|enabled
decl_stmt|;
comment|/* 0 =Disabled, 1= Enabled */
name|uint32_t
name|link_speed
decl_stmt|;
comment|/* multiplier of 100Mb */
name|uint32_t
name|wol_support
decl_stmt|;
comment|/* WoL Support (i.e. Non-Zero if WOL supported ) */
name|uint32_t
name|flow_control
decl_stmt|;
comment|/* 802.3X Flow Ctrl. 0=off 1=RX 2=TX 3=RX&TX.*/
name|uint32_t
name|flex10
decl_stmt|;
comment|/* Flex10 mode enabled. non zero = yes */
name|uint32_t
name|rx_drops
decl_stmt|;
comment|/* RX Discards. Counters roll over, never reset */
name|uint32_t
name|rx_errors
decl_stmt|;
comment|/* RX Errors. Physical Port Stats L95, All PFs and NC-SI. 				   This is flagged by Consumer as an error. */
name|uint32_t
name|rx_uncast_lo
decl_stmt|;
comment|/* RX Unicast Packets. Free running counters: */
name|uint32_t
name|rx_uncast_hi
decl_stmt|;
comment|/* RX Unicast Packets. Free running counters: */
name|uint32_t
name|rx_mcast_lo
decl_stmt|;
comment|/* RX Multicast Packets  */
name|uint32_t
name|rx_mcast_hi
decl_stmt|;
comment|/* RX Multicast Packets  */
name|uint32_t
name|rx_bcast_lo
decl_stmt|;
comment|/* RX Broadcast Packets  */
name|uint32_t
name|rx_bcast_hi
decl_stmt|;
comment|/* RX Broadcast Packets  */
name|uint32_t
name|tx_uncast_lo
decl_stmt|;
comment|/* TX Unicast Packets   */
name|uint32_t
name|tx_uncast_hi
decl_stmt|;
comment|/* TX Unicast Packets   */
name|uint32_t
name|tx_mcast_lo
decl_stmt|;
comment|/* TX Multicast Packets  */
name|uint32_t
name|tx_mcast_hi
decl_stmt|;
comment|/* TX Multicast Packets  */
name|uint32_t
name|tx_bcast_lo
decl_stmt|;
comment|/* TX Broadcast Packets  */
name|uint32_t
name|tx_bcast_hi
decl_stmt|;
comment|/* TX Broadcast Packets  */
name|uint32_t
name|tx_errors
decl_stmt|;
comment|/* TX Errors              */
name|uint32_t
name|tx_discards
decl_stmt|;
comment|/* TX Discards          */
name|uint32_t
name|rx_frames_lo
decl_stmt|;
comment|/* RX Frames received  */
name|uint32_t
name|rx_frames_hi
decl_stmt|;
comment|/* RX Frames received  */
name|uint32_t
name|rx_bytes_lo
decl_stmt|;
comment|/* RX Bytes received    */
name|uint32_t
name|rx_bytes_hi
decl_stmt|;
comment|/* RX Bytes received    */
name|uint32_t
name|tx_frames_lo
decl_stmt|;
comment|/* TX Frames sent      */
name|uint32_t
name|tx_frames_hi
decl_stmt|;
comment|/* TX Frames sent      */
name|uint32_t
name|tx_bytes_lo
decl_stmt|;
comment|/* TX Bytes sent        */
name|uint32_t
name|tx_bytes_hi
decl_stmt|;
comment|/* TX Bytes sent        */
name|uint32_t
name|link_status
decl_stmt|;
comment|/* Port P Link Status. 1:0 bit for port enabled. 				1:1 bit for link good, 				2:1 Set if link changed between last poll. */
name|uint32_t
name|tx_pfc_frames_lo
decl_stmt|;
comment|/* PFC Frames sent.    */
name|uint32_t
name|tx_pfc_frames_hi
decl_stmt|;
comment|/* PFC Frames sent.    */
name|uint32_t
name|rx_pfc_frames_lo
decl_stmt|;
comment|/* PFC Frames Received. */
name|uint32_t
name|rx_pfc_frames_hi
decl_stmt|;
comment|/* PFC Frames Received. */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|BCM_5710_FW_MAJOR_VERSION
value|7
end_define

begin_define
define|#
directive|define
name|BCM_5710_FW_MINOR_VERSION
value|13
end_define

begin_define
define|#
directive|define
name|BCM_5710_FW_REVISION_VERSION
value|1
end_define

begin_define
define|#
directive|define
name|BCM_5710_FW_ENGINEERING_VERSION
value|0
end_define

begin_define
define|#
directive|define
name|BCM_5710_FW_COMPILE_FLAGS
value|1
end_define

begin_comment
comment|/*  * attention bits $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|atten_sp_status_block
block|{
name|uint32_t
name|attn_bits
comment|/* 16 bit of attention signal lines */
decl_stmt|;
name|uint32_t
name|attn_bits_ack
comment|/* 16 bit of attention signal ack */
decl_stmt|;
name|uint8_t
name|status_block_id
comment|/* status block id */
decl_stmt|;
name|uint8_t
name|reserved0
comment|/* resreved for padding */
decl_stmt|;
name|uint16_t
name|attn_bits_index
comment|/* attention bits running index */
decl_stmt|;
name|uint32_t
name|reserved1
comment|/* resreved for padding */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The eth aggregative context of Cstorm  */
end_comment

begin_struct
struct|struct
name|cstorm_eth_ag_context
block|{
name|uint32_t
name|__reserved0
index|[
literal|10
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The iscsi aggregative context of Cstorm  */
end_comment

begin_struct
struct|struct
name|cstorm_iscsi_ag_context
block|{
name|uint32_t
name|agg_vars1
decl_stmt|;
define|#
directive|define
name|CSTORM_ISCSI_AG_CONTEXT_STATE
value|(0xFF<<0)
comment|/* BitField agg_vars1Various aggregative variables	The state of the connection */
define|#
directive|define
name|CSTORM_ISCSI_AG_CONTEXT_STATE_SHIFT
value|0
define|#
directive|define
name|__CSTORM_ISCSI_AG_CONTEXT_EXISTS_IN_QM0
value|(0x1<<8)
comment|/* BitField agg_vars1Various aggregative variables	The connection is currently registered to the QM with queue index 0 */
define|#
directive|define
name|__CSTORM_ISCSI_AG_CONTEXT_EXISTS_IN_QM0_SHIFT
value|8
define|#
directive|define
name|__CSTORM_ISCSI_AG_CONTEXT_EXISTS_IN_QM1
value|(0x1<<9)
comment|/* BitField agg_vars1Various aggregative variables	The connection is currently registered to the QM with queue index 1 */
define|#
directive|define
name|__CSTORM_ISCSI_AG_CONTEXT_EXISTS_IN_QM1_SHIFT
value|9
define|#
directive|define
name|__CSTORM_ISCSI_AG_CONTEXT_EXISTS_IN_QM2
value|(0x1<<10)
comment|/* BitField agg_vars1Various aggregative variables	The connection is currently registered to the QM with queue index 2 */
define|#
directive|define
name|__CSTORM_ISCSI_AG_CONTEXT_EXISTS_IN_QM2_SHIFT
value|10
define|#
directive|define
name|__CSTORM_ISCSI_AG_CONTEXT_EXISTS_IN_QM3
value|(0x1<<11)
comment|/* BitField agg_vars1Various aggregative variables	The connection is currently registered to the QM with queue index 3 */
define|#
directive|define
name|__CSTORM_ISCSI_AG_CONTEXT_EXISTS_IN_QM3_SHIFT
value|11
define|#
directive|define
name|__CSTORM_ISCSI_AG_CONTEXT_RESERVED_ULP_RX_SE_CF_EN
value|(0x1<<12)
comment|/* BitField agg_vars1Various aggregative variables	ULP Rx SE counter flag enable */
define|#
directive|define
name|__CSTORM_ISCSI_AG_CONTEXT_RESERVED_ULP_RX_SE_CF_EN_SHIFT
value|12
define|#
directive|define
name|__CSTORM_ISCSI_AG_CONTEXT_RESERVED_ULP_RX_INV_CF_EN
value|(0x1<<13)
comment|/* BitField agg_vars1Various aggregative variables	ULP Rx invalidate counter flag enable */
define|#
directive|define
name|__CSTORM_ISCSI_AG_CONTEXT_RESERVED_ULP_RX_INV_CF_EN_SHIFT
value|13
define|#
directive|define
name|__CSTORM_ISCSI_AG_CONTEXT_AUX4_CF
value|(0x3<<14)
comment|/* BitField agg_vars1Various aggregative variables	Aux 4 counter flag */
define|#
directive|define
name|__CSTORM_ISCSI_AG_CONTEXT_AUX4_CF_SHIFT
value|14
define|#
directive|define
name|__CSTORM_ISCSI_AG_CONTEXT_RESERVED66
value|(0x3<<16)
comment|/* BitField agg_vars1Various aggregative variables	The connection QOS */
define|#
directive|define
name|__CSTORM_ISCSI_AG_CONTEXT_RESERVED66_SHIFT
value|16
define|#
directive|define
name|__CSTORM_ISCSI_AG_CONTEXT_FIN_RECEIVED_CF_EN
value|(0x1<<18)
comment|/* BitField agg_vars1Various aggregative variables	Enable decision rule for fin_received_cf */
define|#
directive|define
name|__CSTORM_ISCSI_AG_CONTEXT_FIN_RECEIVED_CF_EN_SHIFT
value|18
define|#
directive|define
name|__CSTORM_ISCSI_AG_CONTEXT_AUX1_CF_EN
value|(0x1<<19)
comment|/* BitField agg_vars1Various aggregative variables	Enable decision rule for auxiliary counter flag 1 */
define|#
directive|define
name|__CSTORM_ISCSI_AG_CONTEXT_AUX1_CF_EN_SHIFT
value|19
define|#
directive|define
name|__CSTORM_ISCSI_AG_CONTEXT_AUX2_CF_EN
value|(0x1<<20)
comment|/* BitField agg_vars1Various aggregative variables	Enable decision rule for auxiliary counter flag 2 */
define|#
directive|define
name|__CSTORM_ISCSI_AG_CONTEXT_AUX2_CF_EN_SHIFT
value|20
define|#
directive|define
name|__CSTORM_ISCSI_AG_CONTEXT_AUX3_CF_EN
value|(0x1<<21)
comment|/* BitField agg_vars1Various aggregative variables	Enable decision rule for auxiliary counter flag 3 */
define|#
directive|define
name|__CSTORM_ISCSI_AG_CONTEXT_AUX3_CF_EN_SHIFT
value|21
define|#
directive|define
name|__CSTORM_ISCSI_AG_CONTEXT_AUX4_CF_EN
value|(0x1<<22)
comment|/* BitField agg_vars1Various aggregative variables	Enable decision rule for auxiliary counter flag 4 */
define|#
directive|define
name|__CSTORM_ISCSI_AG_CONTEXT_AUX4_CF_EN_SHIFT
value|22
define|#
directive|define
name|__CSTORM_ISCSI_AG_CONTEXT_REL_SEQ_RULE
value|(0x7<<23)
comment|/* BitField agg_vars1Various aggregative variables	0-NOP, 1-EQ, 2-NEQ, 3-GT, 4-GE, 5-LS, 6-LE */
define|#
directive|define
name|__CSTORM_ISCSI_AG_CONTEXT_REL_SEQ_RULE_SHIFT
value|23
define|#
directive|define
name|CSTORM_ISCSI_AG_CONTEXT_HQ_PROD_RULE
value|(0x3<<26)
comment|/* BitField agg_vars1Various aggregative variables	0-NOP, 1-EQ, 2-NEQ */
define|#
directive|define
name|CSTORM_ISCSI_AG_CONTEXT_HQ_PROD_RULE_SHIFT
value|26
define|#
directive|define
name|__CSTORM_ISCSI_AG_CONTEXT_RESERVED52
value|(0x3<<28)
comment|/* BitField agg_vars1Various aggregative variables	0-NOP, 1-EQ, 2-NEQ */
define|#
directive|define
name|__CSTORM_ISCSI_AG_CONTEXT_RESERVED52_SHIFT
value|28
define|#
directive|define
name|__CSTORM_ISCSI_AG_CONTEXT_RESERVED53
value|(0x3<<30)
comment|/* BitField agg_vars1Various aggregative variables	0-NOP, 1-EQ, 2-NEQ */
define|#
directive|define
name|__CSTORM_ISCSI_AG_CONTEXT_RESERVED53_SHIFT
value|30
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint8_t
name|__aux1_th
comment|/* Aux1 threhsold for the decision */
decl_stmt|;
name|uint8_t
name|__aux1_val
comment|/* Aux1 aggregation value */
decl_stmt|;
name|uint16_t
name|__agg_vars2
comment|/* Various aggregative variables*/
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|__agg_vars2
comment|/* Various aggregative variables*/
decl_stmt|;
name|uint8_t
name|__aux1_val
comment|/* Aux1 aggregation value */
decl_stmt|;
name|uint8_t
name|__aux1_th
comment|/* Aux1 threhsold for the decision */
decl_stmt|;
endif|#
directive|endif
name|uint32_t
name|rel_seq
comment|/* The sequence to release */
decl_stmt|;
name|uint32_t
name|rel_seq_th
comment|/* The threshold for the released sequence */
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|hq_cons
comment|/* The HQ Consumer */
decl_stmt|;
name|uint16_t
name|hq_prod
comment|/* The HQ producer */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|hq_prod
comment|/* The HQ producer */
decl_stmt|;
name|uint16_t
name|hq_cons
comment|/* The HQ Consumer */
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint8_t
name|__reserved62
comment|/* Mask value for the decision algorithm of the general flags */
decl_stmt|;
name|uint8_t
name|__reserved61
comment|/* General flags */
decl_stmt|;
name|uint8_t
name|__reserved60
comment|/* ORQ consumer updated by the completor */
decl_stmt|;
name|uint8_t
name|__reserved59
comment|/* ORQ ULP Rx consumer */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint8_t
name|__reserved59
comment|/* ORQ ULP Rx consumer */
decl_stmt|;
name|uint8_t
name|__reserved60
comment|/* ORQ consumer updated by the completor */
decl_stmt|;
name|uint8_t
name|__reserved61
comment|/* General flags */
decl_stmt|;
name|uint8_t
name|__reserved62
comment|/* Mask value for the decision algorithm of the general flags */
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|__reserved64
comment|/* RQ consumer kept by the completor */
decl_stmt|;
name|uint16_t
name|cq_u_prod
comment|/* Ustorm producer of CQ */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|cq_u_prod
comment|/* Ustorm producer of CQ */
decl_stmt|;
name|uint16_t
name|__reserved64
comment|/* RQ consumer kept by the completor */
decl_stmt|;
endif|#
directive|endif
name|uint32_t
name|__cq_u_prod1
comment|/* Ustorm producer of CQ 1 */
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|__agg_vars3
comment|/* Various aggregative variables*/
decl_stmt|;
name|uint16_t
name|cq_u_pend
comment|/* Ustorm pending completions of CQ */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|cq_u_pend
comment|/* Ustorm pending completions of CQ */
decl_stmt|;
name|uint16_t
name|__agg_vars3
comment|/* Various aggregative variables*/
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|__aux2_th
comment|/* Aux2 threhsold for the decision */
decl_stmt|;
name|uint16_t
name|aux2_val
comment|/* Aux2 aggregation value */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|aux2_val
comment|/* Aux2 aggregation value */
decl_stmt|;
name|uint16_t
name|__aux2_th
comment|/* Aux2 threhsold for the decision */
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/*  * The toe aggregative context of Cstorm  */
end_comment

begin_struct
struct|struct
name|cstorm_toe_ag_context
block|{
name|uint32_t
name|__agg_vars1
comment|/* Various aggregative variables*/
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint8_t
name|__aux1_th
comment|/* Aux1 threhsold for the decision */
decl_stmt|;
name|uint8_t
name|__aux1_val
comment|/* Aux1 aggregation value */
decl_stmt|;
name|uint16_t
name|__agg_vars2
comment|/* Various aggregative variables*/
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|__agg_vars2
comment|/* Various aggregative variables*/
decl_stmt|;
name|uint8_t
name|__aux1_val
comment|/* Aux1 aggregation value */
decl_stmt|;
name|uint8_t
name|__aux1_th
comment|/* Aux1 threhsold for the decision */
decl_stmt|;
endif|#
directive|endif
name|uint32_t
name|rel_seq
comment|/* The sequence to release */
decl_stmt|;
name|uint32_t
name|__rel_seq_threshold
comment|/* The threshold for the released sequence */
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|__reserved58
comment|/* The HQ Consumer */
decl_stmt|;
name|uint16_t
name|bd_prod
comment|/* The HQ producer */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|bd_prod
comment|/* The HQ producer */
decl_stmt|;
name|uint16_t
name|__reserved58
comment|/* The HQ Consumer */
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint8_t
name|__reserved62
comment|/* Mask value for the decision algorithm of the general flags */
decl_stmt|;
name|uint8_t
name|__reserved61
comment|/* General flags */
decl_stmt|;
name|uint8_t
name|__reserved60
comment|/* ORQ consumer updated by the completor */
decl_stmt|;
name|uint8_t
name|__completion_opcode
comment|/* ORQ ULP Rx consumer */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint8_t
name|__completion_opcode
comment|/* ORQ ULP Rx consumer */
decl_stmt|;
name|uint8_t
name|__reserved60
comment|/* ORQ consumer updated by the completor */
decl_stmt|;
name|uint8_t
name|__reserved61
comment|/* General flags */
decl_stmt|;
name|uint8_t
name|__reserved62
comment|/* Mask value for the decision algorithm of the general flags */
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|__reserved64
comment|/* RQ consumer kept by the completor */
decl_stmt|;
name|uint16_t
name|__reserved63
comment|/* RQ consumer updated by the ULP RX */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|__reserved63
comment|/* RQ consumer updated by the ULP RX */
decl_stmt|;
name|uint16_t
name|__reserved64
comment|/* RQ consumer kept by the completor */
decl_stmt|;
endif|#
directive|endif
name|uint32_t
name|snd_max
comment|/* The ACK sequence number received in the last completed DDP */
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|__agg_vars3
comment|/* Various aggregative variables*/
decl_stmt|;
name|uint16_t
name|__reserved67
comment|/* A counter for the number of RQ WQEs with invalidate the USTORM encountered */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|__reserved67
comment|/* A counter for the number of RQ WQEs with invalidate the USTORM encountered */
decl_stmt|;
name|uint16_t
name|__agg_vars3
comment|/* Various aggregative variables*/
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|__aux2_th
comment|/* Aux2 threhsold for the decision */
decl_stmt|;
name|uint16_t
name|__aux2_val
comment|/* Aux2 aggregation value */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|__aux2_val
comment|/* Aux2 aggregation value */
decl_stmt|;
name|uint16_t
name|__aux2_th
comment|/* Aux2 threhsold for the decision */
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/*  * dmae command structure  */
end_comment

begin_struct
struct|struct
name|dmae_cmd
block|{
name|uint32_t
name|opcode
decl_stmt|;
define|#
directive|define
name|DMAE_CMD_SRC
value|(0x1<<0)
comment|/* BitField opcode	Whether the source is the PCIe or the GRC. 0- The source is the PCIe 1- The source is the GRC. */
define|#
directive|define
name|DMAE_CMD_SRC_SHIFT
value|0
define|#
directive|define
name|DMAE_CMD_DST
value|(0x3<<1)
comment|/* BitField opcode	The destination of the DMA can be: 0-None 1-PCIe 2-GRC 3-None  */
define|#
directive|define
name|DMAE_CMD_DST_SHIFT
value|1
define|#
directive|define
name|DMAE_CMD_C_DST
value|(0x1<<3)
comment|/* BitField opcode	The destination of the completion: 0-PCIe 1-GRC */
define|#
directive|define
name|DMAE_CMD_C_DST_SHIFT
value|3
define|#
directive|define
name|DMAE_CMD_C_TYPE_ENABLE
value|(0x1<<4)
comment|/* BitField opcode	Whether to write a completion word to the completion destination: 0-Do not write a completion word 1-Write the completion word  */
define|#
directive|define
name|DMAE_CMD_C_TYPE_ENABLE_SHIFT
value|4
define|#
directive|define
name|DMAE_CMD_C_TYPE_CRC_ENABLE
value|(0x1<<5)
comment|/* BitField opcode	Whether to write a CRC word to the completion destination 0-Do not write a CRC word 1-Write a CRC word  */
define|#
directive|define
name|DMAE_CMD_C_TYPE_CRC_ENABLE_SHIFT
value|5
define|#
directive|define
name|DMAE_CMD_C_TYPE_CRC_OFFSET
value|(0x7<<6)
comment|/* BitField opcode	The CRC word should be taken from the DMAE GRC space from address 9+X, where X is the value in these bits. */
define|#
directive|define
name|DMAE_CMD_C_TYPE_CRC_OFFSET_SHIFT
value|6
define|#
directive|define
name|DMAE_CMD_ENDIANITY
value|(0x3<<9)
comment|/* BitField opcode	swapping mode. */
define|#
directive|define
name|DMAE_CMD_ENDIANITY_SHIFT
value|9
define|#
directive|define
name|DMAE_CMD_PORT
value|(0x1<<11)
comment|/* BitField opcode	Which network port ID to present to the PCI request interface */
define|#
directive|define
name|DMAE_CMD_PORT_SHIFT
value|11
define|#
directive|define
name|DMAE_CMD_CRC_RESET
value|(0x1<<12)
comment|/* BitField opcode	reset crc result */
define|#
directive|define
name|DMAE_CMD_CRC_RESET_SHIFT
value|12
define|#
directive|define
name|DMAE_CMD_SRC_RESET
value|(0x1<<13)
comment|/* BitField opcode	reset source address in next go */
define|#
directive|define
name|DMAE_CMD_SRC_RESET_SHIFT
value|13
define|#
directive|define
name|DMAE_CMD_DST_RESET
value|(0x1<<14)
comment|/* BitField opcode	reset dest address in next go */
define|#
directive|define
name|DMAE_CMD_DST_RESET_SHIFT
value|14
define|#
directive|define
name|DMAE_CMD_E1HVN
value|(0x3<<15)
comment|/* BitField opcode	vnic number E2 and onwards source vnic */
define|#
directive|define
name|DMAE_CMD_E1HVN_SHIFT
value|15
define|#
directive|define
name|DMAE_CMD_DST_VN
value|(0x3<<17)
comment|/* BitField opcode	E2 and onwards dest vnic */
define|#
directive|define
name|DMAE_CMD_DST_VN_SHIFT
value|17
define|#
directive|define
name|DMAE_CMD_C_FUNC
value|(0x1<<19)
comment|/* BitField opcode	E2 and onwards which function gets the completion src_vn(e1hvn)-0 dst_vn-1 */
define|#
directive|define
name|DMAE_CMD_C_FUNC_SHIFT
value|19
define|#
directive|define
name|DMAE_CMD_ERR_POLICY
value|(0x3<<20)
comment|/* BitField opcode	E2 and onwards what to do when theres a completion and a PCI error regular-0 error indication-1 no completion-2 */
define|#
directive|define
name|DMAE_CMD_ERR_POLICY_SHIFT
value|20
define|#
directive|define
name|DMAE_CMD_RESERVED0
value|(0x3FF<<22)
comment|/* BitField opcode	 */
define|#
directive|define
name|DMAE_CMD_RESERVED0_SHIFT
value|22
name|uint32_t
name|src_addr_lo
comment|/* source address low/grc address */
decl_stmt|;
name|uint32_t
name|src_addr_hi
comment|/* source address hi */
decl_stmt|;
name|uint32_t
name|dst_addr_lo
comment|/* dest address low/grc address */
decl_stmt|;
name|uint32_t
name|dst_addr_hi
comment|/* dest address hi */
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|opcode_iov
decl_stmt|;
define|#
directive|define
name|DMAE_CMD_SRC_VFID
value|(0x3F<<0)
comment|/* BitField opcode_iovE2 and onward, set to 0 for backward compatibility	source VF id */
define|#
directive|define
name|DMAE_CMD_SRC_VFID_SHIFT
value|0
define|#
directive|define
name|DMAE_CMD_SRC_VFPF
value|(0x1<<6)
comment|/* BitField opcode_iovE2 and onward, set to 0 for backward compatibility	selects the source function PF-0, VF-1 */
define|#
directive|define
name|DMAE_CMD_SRC_VFPF_SHIFT
value|6
define|#
directive|define
name|DMAE_CMD_RESERVED1
value|(0x1<<7)
comment|/* BitField opcode_iovE2 and onward, set to 0 for backward compatibility	 */
define|#
directive|define
name|DMAE_CMD_RESERVED1_SHIFT
value|7
define|#
directive|define
name|DMAE_CMD_DST_VFID
value|(0x3F<<8)
comment|/* BitField opcode_iovE2 and onward, set to 0 for backward compatibility	destination VF id */
define|#
directive|define
name|DMAE_CMD_DST_VFID_SHIFT
value|8
define|#
directive|define
name|DMAE_CMD_DST_VFPF
value|(0x1<<14)
comment|/* BitField opcode_iovE2 and onward, set to 0 for backward compatibility	selects the destination function PF-0, VF-1 */
define|#
directive|define
name|DMAE_CMD_DST_VFPF_SHIFT
value|14
define|#
directive|define
name|DMAE_CMD_RESERVED2
value|(0x1<<15)
comment|/* BitField opcode_iovE2 and onward, set to 0 for backward compatibility	 */
define|#
directive|define
name|DMAE_CMD_RESERVED2_SHIFT
value|15
name|uint16_t
name|len
comment|/* copy length */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|len
comment|/* copy length */
decl_stmt|;
name|uint16_t
name|opcode_iov
decl_stmt|;
define|#
directive|define
name|DMAE_CMD_SRC_VFID
value|(0x3F<<0)
comment|/* BitField opcode_iovE2 and onward, set to 0 for backward compatibility	source VF id */
define|#
directive|define
name|DMAE_CMD_SRC_VFID_SHIFT
value|0
define|#
directive|define
name|DMAE_CMD_SRC_VFPF
value|(0x1<<6)
comment|/* BitField opcode_iovE2 and onward, set to 0 for backward compatibility	selects the source function PF-0, VF-1 */
define|#
directive|define
name|DMAE_CMD_SRC_VFPF_SHIFT
value|6
define|#
directive|define
name|DMAE_CMD_RESERVED1
value|(0x1<<7)
comment|/* BitField opcode_iovE2 and onward, set to 0 for backward compatibility	 */
define|#
directive|define
name|DMAE_CMD_RESERVED1_SHIFT
value|7
define|#
directive|define
name|DMAE_CMD_DST_VFID
value|(0x3F<<8)
comment|/* BitField opcode_iovE2 and onward, set to 0 for backward compatibility	destination VF id */
define|#
directive|define
name|DMAE_CMD_DST_VFID_SHIFT
value|8
define|#
directive|define
name|DMAE_CMD_DST_VFPF
value|(0x1<<14)
comment|/* BitField opcode_iovE2 and onward, set to 0 for backward compatibility	selects the destination function PF-0, VF-1 */
define|#
directive|define
name|DMAE_CMD_DST_VFPF_SHIFT
value|14
define|#
directive|define
name|DMAE_CMD_RESERVED2
value|(0x1<<15)
comment|/* BitField opcode_iovE2 and onward, set to 0 for backward compatibility	 */
define|#
directive|define
name|DMAE_CMD_RESERVED2_SHIFT
value|15
endif|#
directive|endif
name|uint32_t
name|comp_addr_lo
comment|/* completion address low/grc address */
decl_stmt|;
name|uint32_t
name|comp_addr_hi
comment|/* completion address hi */
decl_stmt|;
name|uint32_t
name|comp_val
comment|/* value to write to completion address */
decl_stmt|;
name|uint32_t
name|crc32
comment|/* crc32 result */
decl_stmt|;
name|uint32_t
name|crc32_c
comment|/* crc32_c result */
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|crc16_c
comment|/* crc16_c result */
decl_stmt|;
name|uint16_t
name|crc16
comment|/* crc16 result */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|crc16
comment|/* crc16 result */
decl_stmt|;
name|uint16_t
name|crc16_c
comment|/* crc16_c result */
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|reserved3
decl_stmt|;
name|uint16_t
name|crc_t10
comment|/* crc_t10 result */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|crc_t10
comment|/* crc_t10 result */
decl_stmt|;
name|uint16_t
name|reserved3
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|xsum8
comment|/* checksum8 result */
decl_stmt|;
name|uint16_t
name|xsum16
comment|/* checksum16 result */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|xsum16
comment|/* checksum16 result */
decl_stmt|;
name|uint16_t
name|xsum8
comment|/* checksum8 result */
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/*  * common data for all protocols  */
end_comment

begin_struct
struct|struct
name|doorbell_hdr_t
block|{
name|uint8_t
name|data
decl_stmt|;
define|#
directive|define
name|DOORBELL_HDR_T_RX
value|(0x1<<0)
comment|/* BitField data	1 for rx doorbell, 0 for tx doorbell */
define|#
directive|define
name|DOORBELL_HDR_T_RX_SHIFT
value|0
define|#
directive|define
name|DOORBELL_HDR_T_DB_TYPE
value|(0x1<<1)
comment|/* BitField data	0 for normal doorbell, 1 for advertise wnd doorbell */
define|#
directive|define
name|DOORBELL_HDR_T_DB_TYPE_SHIFT
value|1
define|#
directive|define
name|DOORBELL_HDR_T_DPM_SIZE
value|(0x3<<2)
comment|/* BitField data	rdma tx only: DPM transaction size specifier (64/128/256/512 bytes) */
define|#
directive|define
name|DOORBELL_HDR_T_DPM_SIZE_SHIFT
value|2
define|#
directive|define
name|DOORBELL_HDR_T_CONN_TYPE
value|(0xF<<4)
comment|/* BitField data	connection type */
define|#
directive|define
name|DOORBELL_HDR_T_CONN_TYPE_SHIFT
value|4
block|}
struct|;
end_struct

begin_comment
comment|/*  * Ethernet doorbell  */
end_comment

begin_struct
struct|struct
name|eth_tx_doorbell
block|{
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|npackets
comment|/* number of data bytes that were added in the doorbell */
decl_stmt|;
name|uint8_t
name|params
decl_stmt|;
define|#
directive|define
name|ETH_TX_DOORBELL_NUM_BDS
value|(0x3F<<0)
comment|/* BitField params	number of buffer descriptors that were added in the doorbell */
define|#
directive|define
name|ETH_TX_DOORBELL_NUM_BDS_SHIFT
value|0
define|#
directive|define
name|ETH_TX_DOORBELL_RESERVED_TX_FIN_FLAG
value|(0x1<<6)
comment|/* BitField params	tx fin command flag */
define|#
directive|define
name|ETH_TX_DOORBELL_RESERVED_TX_FIN_FLAG_SHIFT
value|6
define|#
directive|define
name|ETH_TX_DOORBELL_SPARE
value|(0x1<<7)
comment|/* BitField params	doorbell queue spare flag */
define|#
directive|define
name|ETH_TX_DOORBELL_SPARE_SHIFT
value|7
name|struct
name|doorbell_hdr_t
name|hdr
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|struct
name|doorbell_hdr_t
name|hdr
decl_stmt|;
name|uint8_t
name|params
decl_stmt|;
define|#
directive|define
name|ETH_TX_DOORBELL_NUM_BDS
value|(0x3F<<0)
comment|/* BitField params	number of buffer descriptors that were added in the doorbell */
define|#
directive|define
name|ETH_TX_DOORBELL_NUM_BDS_SHIFT
value|0
define|#
directive|define
name|ETH_TX_DOORBELL_RESERVED_TX_FIN_FLAG
value|(0x1<<6)
comment|/* BitField params	tx fin command flag */
define|#
directive|define
name|ETH_TX_DOORBELL_RESERVED_TX_FIN_FLAG_SHIFT
value|6
define|#
directive|define
name|ETH_TX_DOORBELL_SPARE
value|(0x1<<7)
comment|/* BitField params	doorbell queue spare flag */
define|#
directive|define
name|ETH_TX_DOORBELL_SPARE_SHIFT
value|7
name|uint16_t
name|npackets
comment|/* number of data bytes that were added in the doorbell */
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/*  * 3 lines. status block $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|hc_status_block_e1x
block|{
name|uint16_t
name|index_values
index|[
name|HC_SB_MAX_INDICES_E1X
index|]
comment|/* indices reported by cstorm */
decl_stmt|;
name|uint16_t
name|running_index
index|[
name|HC_SB_MAX_SM
index|]
comment|/* Status Block running indices */
decl_stmt|;
name|uint32_t
name|rsrv
index|[
literal|11
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * host status block  */
end_comment

begin_struct
struct|struct
name|host_hc_status_block_e1x
block|{
name|struct
name|hc_status_block_e1x
name|sb
comment|/* fast path indices */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * 3 lines. status block $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|hc_status_block_e2
block|{
name|uint16_t
name|index_values
index|[
name|HC_SB_MAX_INDICES_E2
index|]
comment|/* indices reported by cstorm */
decl_stmt|;
name|uint16_t
name|running_index
index|[
name|HC_SB_MAX_SM
index|]
comment|/* Status Block running indices */
decl_stmt|;
name|uint32_t
name|reserved
index|[
literal|11
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * host status block  */
end_comment

begin_struct
struct|struct
name|host_hc_status_block_e2
block|{
name|struct
name|hc_status_block_e2
name|sb
comment|/* fast path indices */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * 5 lines. slow-path status block $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|hc_sp_status_block
block|{
name|uint16_t
name|index_values
index|[
name|HC_SP_SB_MAX_INDICES
index|]
comment|/* indices reported by cstorm */
decl_stmt|;
name|uint16_t
name|running_index
comment|/* Status Block running index */
decl_stmt|;
name|uint16_t
name|rsrv
decl_stmt|;
name|uint32_t
name|rsrv1
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * host status block  */
end_comment

begin_struct
struct|struct
name|host_sp_status_block
block|{
name|struct
name|atten_sp_status_block
name|atten_status_block
comment|/* attention bits section */
decl_stmt|;
name|struct
name|hc_sp_status_block
name|sp_sb
comment|/* slow path indices */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * IGU driver acknowledgment register  */
end_comment

begin_struct
struct|struct
name|igu_ack_register
block|{
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|sb_id_and_flags
decl_stmt|;
define|#
directive|define
name|IGU_ACK_REGISTER_STATUS_BLOCK_ID
value|(0x1F<<0)
comment|/* BitField sb_id_and_flags	0-15: non default status blocks, 16: default status block */
define|#
directive|define
name|IGU_ACK_REGISTER_STATUS_BLOCK_ID_SHIFT
value|0
define|#
directive|define
name|IGU_ACK_REGISTER_STORM_ID
value|(0x7<<5)
comment|/* BitField sb_id_and_flags	0-3:storm id, 4: attn status block (valid in default sb only) */
define|#
directive|define
name|IGU_ACK_REGISTER_STORM_ID_SHIFT
value|5
define|#
directive|define
name|IGU_ACK_REGISTER_UPDATE_INDEX
value|(0x1<<8)
comment|/* BitField sb_id_and_flags	if set, acknowledges status block index */
define|#
directive|define
name|IGU_ACK_REGISTER_UPDATE_INDEX_SHIFT
value|8
define|#
directive|define
name|IGU_ACK_REGISTER_INTERRUPT_MODE
value|(0x3<<9)
comment|/* BitField sb_id_and_flags	interrupt enable/disable/nop: use IGU_INT_xxx constants */
define|#
directive|define
name|IGU_ACK_REGISTER_INTERRUPT_MODE_SHIFT
value|9
define|#
directive|define
name|IGU_ACK_REGISTER_RESERVED
value|(0x1F<<11)
comment|/* BitField sb_id_and_flags	 */
define|#
directive|define
name|IGU_ACK_REGISTER_RESERVED_SHIFT
value|11
name|uint16_t
name|status_block_index
comment|/* status block index acknowledgement */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|status_block_index
comment|/* status block index acknowledgement */
decl_stmt|;
name|uint16_t
name|sb_id_and_flags
decl_stmt|;
define|#
directive|define
name|IGU_ACK_REGISTER_STATUS_BLOCK_ID
value|(0x1F<<0)
comment|/* BitField sb_id_and_flags	0-15: non default status blocks, 16: default status block */
define|#
directive|define
name|IGU_ACK_REGISTER_STATUS_BLOCK_ID_SHIFT
value|0
define|#
directive|define
name|IGU_ACK_REGISTER_STORM_ID
value|(0x7<<5)
comment|/* BitField sb_id_and_flags	0-3:storm id, 4: attn status block (valid in default sb only) */
define|#
directive|define
name|IGU_ACK_REGISTER_STORM_ID_SHIFT
value|5
define|#
directive|define
name|IGU_ACK_REGISTER_UPDATE_INDEX
value|(0x1<<8)
comment|/* BitField sb_id_and_flags	if set, acknowledges status block index */
define|#
directive|define
name|IGU_ACK_REGISTER_UPDATE_INDEX_SHIFT
value|8
define|#
directive|define
name|IGU_ACK_REGISTER_INTERRUPT_MODE
value|(0x3<<9)
comment|/* BitField sb_id_and_flags	interrupt enable/disable/nop: use IGU_INT_xxx constants */
define|#
directive|define
name|IGU_ACK_REGISTER_INTERRUPT_MODE_SHIFT
value|9
define|#
directive|define
name|IGU_ACK_REGISTER_RESERVED
value|(0x1F<<11)
comment|/* BitField sb_id_and_flags	 */
define|#
directive|define
name|IGU_ACK_REGISTER_RESERVED_SHIFT
value|11
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/*  * IGU driver acknowledgement register  */
end_comment

begin_struct
struct|struct
name|igu_backward_compatible
block|{
name|uint32_t
name|sb_id_and_flags
decl_stmt|;
define|#
directive|define
name|IGU_BACKWARD_COMPATIBLE_SB_INDEX
value|(0xFFFF<<0)
comment|/* BitField sb_id_and_flags	 */
define|#
directive|define
name|IGU_BACKWARD_COMPATIBLE_SB_INDEX_SHIFT
value|0
define|#
directive|define
name|IGU_BACKWARD_COMPATIBLE_SB_SELECT
value|(0x1F<<16)
comment|/* BitField sb_id_and_flags	 */
define|#
directive|define
name|IGU_BACKWARD_COMPATIBLE_SB_SELECT_SHIFT
value|16
define|#
directive|define
name|IGU_BACKWARD_COMPATIBLE_SEGMENT_ACCESS
value|(0x7<<21)
comment|/* BitField sb_id_and_flags	0-3:storm id, 4: attn status block (valid in default sb only) */
define|#
directive|define
name|IGU_BACKWARD_COMPATIBLE_SEGMENT_ACCESS_SHIFT
value|21
define|#
directive|define
name|IGU_BACKWARD_COMPATIBLE_BUPDATE
value|(0x1<<24)
comment|/* BitField sb_id_and_flags	if set, acknowledges status block index */
define|#
directive|define
name|IGU_BACKWARD_COMPATIBLE_BUPDATE_SHIFT
value|24
define|#
directive|define
name|IGU_BACKWARD_COMPATIBLE_ENABLE_INT
value|(0x3<<25)
comment|/* BitField sb_id_and_flags	interrupt enable/disable/nop: use IGU_INT_xxx constants */
define|#
directive|define
name|IGU_BACKWARD_COMPATIBLE_ENABLE_INT_SHIFT
value|25
define|#
directive|define
name|IGU_BACKWARD_COMPATIBLE_RESERVED_0
value|(0x1F<<27)
comment|/* BitField sb_id_and_flags	 */
define|#
directive|define
name|IGU_BACKWARD_COMPATIBLE_RESERVED_0_SHIFT
value|27
name|uint32_t
name|reserved_2
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * IGU driver acknowledgement register  */
end_comment

begin_struct
struct|struct
name|igu_regular
block|{
name|uint32_t
name|sb_id_and_flags
decl_stmt|;
define|#
directive|define
name|IGU_REGULAR_SB_INDEX
value|(0xFFFFF<<0)
comment|/* BitField sb_id_and_flags	 */
define|#
directive|define
name|IGU_REGULAR_SB_INDEX_SHIFT
value|0
define|#
directive|define
name|IGU_REGULAR_RESERVED0
value|(0x1<<20)
comment|/* BitField sb_id_and_flags	 */
define|#
directive|define
name|IGU_REGULAR_RESERVED0_SHIFT
value|20
define|#
directive|define
name|IGU_REGULAR_SEGMENT_ACCESS
value|(0x7<<21)
comment|/* BitField sb_id_and_flags	21-23 (use enum igu_seg_access) */
define|#
directive|define
name|IGU_REGULAR_SEGMENT_ACCESS_SHIFT
value|21
define|#
directive|define
name|IGU_REGULAR_BUPDATE
value|(0x1<<24)
comment|/* BitField sb_id_and_flags	 */
define|#
directive|define
name|IGU_REGULAR_BUPDATE_SHIFT
value|24
define|#
directive|define
name|IGU_REGULAR_ENABLE_INT
value|(0x3<<25)
comment|/* BitField sb_id_and_flags	interrupt enable/disable/nop (use enum igu_int_cmd) */
define|#
directive|define
name|IGU_REGULAR_ENABLE_INT_SHIFT
value|25
define|#
directive|define
name|IGU_REGULAR_RESERVED_1
value|(0x1<<27)
comment|/* BitField sb_id_and_flags	 */
define|#
directive|define
name|IGU_REGULAR_RESERVED_1_SHIFT
value|27
define|#
directive|define
name|IGU_REGULAR_CLEANUP_TYPE
value|(0x3<<28)
comment|/* BitField sb_id_and_flags	 */
define|#
directive|define
name|IGU_REGULAR_CLEANUP_TYPE_SHIFT
value|28
define|#
directive|define
name|IGU_REGULAR_CLEANUP_SET
value|(0x1<<30)
comment|/* BitField sb_id_and_flags	 */
define|#
directive|define
name|IGU_REGULAR_CLEANUP_SET_SHIFT
value|30
define|#
directive|define
name|IGU_REGULAR_BCLEANUP
value|(0x1<<31)
comment|/* BitField sb_id_and_flags	 */
define|#
directive|define
name|IGU_REGULAR_BCLEANUP_SHIFT
value|31
name|uint32_t
name|reserved_2
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * IGU driver acknowledgement register  */
end_comment

begin_union
union|union
name|igu_consprod_reg
block|{
name|struct
name|igu_regular
name|regular
decl_stmt|;
name|struct
name|igu_backward_compatible
name|backward_compatible
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/*  * Igu control commands  */
end_comment

begin_enum
enum|enum
name|igu_ctrl_cmd
block|{
name|IGU_CTRL_CMD_TYPE_RD
block|,
name|IGU_CTRL_CMD_TYPE_WR
block|,
name|MAX_IGU_CTRL_CMD
block|}
enum|;
end_enum

begin_comment
comment|/*  * Control register for the IGU command register  */
end_comment

begin_struct
struct|struct
name|igu_ctrl_reg
block|{
name|uint32_t
name|ctrl_data
decl_stmt|;
define|#
directive|define
name|IGU_CTRL_REG_ADDRESS
value|(0xFFF<<0)
comment|/* BitField ctrl_data	 */
define|#
directive|define
name|IGU_CTRL_REG_ADDRESS_SHIFT
value|0
define|#
directive|define
name|IGU_CTRL_REG_FID
value|(0x7F<<12)
comment|/* BitField ctrl_data	 */
define|#
directive|define
name|IGU_CTRL_REG_FID_SHIFT
value|12
define|#
directive|define
name|IGU_CTRL_REG_RESERVED
value|(0x1<<19)
comment|/* BitField ctrl_data	 */
define|#
directive|define
name|IGU_CTRL_REG_RESERVED_SHIFT
value|19
define|#
directive|define
name|IGU_CTRL_REG_TYPE
value|(0x1<<20)
comment|/* BitField ctrl_data	 (use enum igu_ctrl_cmd) */
define|#
directive|define
name|IGU_CTRL_REG_TYPE_SHIFT
value|20
define|#
directive|define
name|IGU_CTRL_REG_UNUSED
value|(0x7FF<<21)
comment|/* BitField ctrl_data	 */
define|#
directive|define
name|IGU_CTRL_REG_UNUSED_SHIFT
value|21
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
block|,
name|IGU_INT_DISABLE
block|,
name|IGU_INT_NOP
block|,
name|IGU_INT_NOP2
block|,
name|MAX_IGU_INT_CMD
block|}
enum|;
end_enum

begin_comment
comment|/*  * Igu segments  */
end_comment

begin_enum
enum|enum
name|igu_seg_access
block|{
name|IGU_SEG_ACCESS_NORM
block|,
name|IGU_SEG_ACCESS_DEF
block|,
name|IGU_SEG_ACCESS_ATTN
block|,
name|MAX_IGU_SEG_ACCESS
block|}
enum|;
end_enum

begin_comment
comment|/*  * iscsi doorbell  */
end_comment

begin_struct
struct|struct
name|iscsi_tx_doorbell
block|{
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|reserved
comment|/* number of data bytes that were added in the doorbell */
decl_stmt|;
name|uint8_t
name|params
decl_stmt|;
define|#
directive|define
name|ISCSI_TX_DOORBELL_NUM_WQES
value|(0x3F<<0)
comment|/* BitField params	number of buffer descriptors that were added in the doorbell */
define|#
directive|define
name|ISCSI_TX_DOORBELL_NUM_WQES_SHIFT
value|0
define|#
directive|define
name|ISCSI_TX_DOORBELL_RESERVED_TX_FIN_FLAG
value|(0x1<<6)
comment|/* BitField params	tx fin command flag */
define|#
directive|define
name|ISCSI_TX_DOORBELL_RESERVED_TX_FIN_FLAG_SHIFT
value|6
define|#
directive|define
name|ISCSI_TX_DOORBELL_SPARE
value|(0x1<<7)
comment|/* BitField params	doorbell queue spare flag */
define|#
directive|define
name|ISCSI_TX_DOORBELL_SPARE_SHIFT
value|7
name|struct
name|doorbell_hdr_t
name|hdr
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|struct
name|doorbell_hdr_t
name|hdr
decl_stmt|;
name|uint8_t
name|params
decl_stmt|;
define|#
directive|define
name|ISCSI_TX_DOORBELL_NUM_WQES
value|(0x3F<<0)
comment|/* BitField params	number of buffer descriptors that were added in the doorbell */
define|#
directive|define
name|ISCSI_TX_DOORBELL_NUM_WQES_SHIFT
value|0
define|#
directive|define
name|ISCSI_TX_DOORBELL_RESERVED_TX_FIN_FLAG
value|(0x1<<6)
comment|/* BitField params	tx fin command flag */
define|#
directive|define
name|ISCSI_TX_DOORBELL_RESERVED_TX_FIN_FLAG_SHIFT
value|6
define|#
directive|define
name|ISCSI_TX_DOORBELL_SPARE
value|(0x1<<7)
comment|/* BitField params	doorbell queue spare flag */
define|#
directive|define
name|ISCSI_TX_DOORBELL_SPARE_SHIFT
value|7
name|uint16_t
name|reserved
comment|/* number of data bytes that were added in the doorbell */
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/*  * Parser parsing flags field  */
end_comment

begin_struct
struct|struct
name|parsing_flags
block|{
name|uint16_t
name|flags
decl_stmt|;
define|#
directive|define
name|PARSING_FLAGS_ETHERNET_ADDRESS_TYPE
value|(0x1<<0)
comment|/* BitField flagscontext flags	0=non-unicast, 1=unicast (use enum prs_flags_eth_addr_type) */
define|#
directive|define
name|PARSING_FLAGS_ETHERNET_ADDRESS_TYPE_SHIFT
value|0
define|#
directive|define
name|PARSING_FLAGS_INNER_VLAN_EXIST
value|(0x1<<1)
comment|/* BitField flagscontext flags	0 or 1 */
define|#
directive|define
name|PARSING_FLAGS_INNER_VLAN_EXIST_SHIFT
value|1
define|#
directive|define
name|PARSING_FLAGS_OUTER_VLAN_EXIST
value|(0x1<<2)
comment|/* BitField flagscontext flags	0 or 1 */
define|#
directive|define
name|PARSING_FLAGS_OUTER_VLAN_EXIST_SHIFT
value|2
define|#
directive|define
name|PARSING_FLAGS_OVER_ETHERNET_PROTOCOL
value|(0x3<<3)
comment|/* BitField flagscontext flags	0=un-known, 1=Ipv4, 2=Ipv6,3=LLC SNAP un-known. LLC SNAP here refers only to LLC/SNAP packets that do not have Ipv4 or Ipv6 above them. Ipv4 and Ipv6 indications are even if they are over LLC/SNAP and not directly over Ethernet (use enum prs_flags_over_eth) */
define|#
directive|define
name|PARSING_FLAGS_OVER_ETHERNET_PROTOCOL_SHIFT
value|3
define|#
directive|define
name|PARSING_FLAGS_IP_OPTIONS
value|(0x1<<5)
comment|/* BitField flagscontext flags	0=no IP options / extension headers. 1=IP options / extension header exist */
define|#
directive|define
name|PARSING_FLAGS_IP_OPTIONS_SHIFT
value|5
define|#
directive|define
name|PARSING_FLAGS_FRAGMENTATION_STATUS
value|(0x1<<6)
comment|/* BitField flagscontext flags	0=non-fragmented, 1=fragmented */
define|#
directive|define
name|PARSING_FLAGS_FRAGMENTATION_STATUS_SHIFT
value|6
define|#
directive|define
name|PARSING_FLAGS_OVER_IP_PROTOCOL
value|(0x3<<7)
comment|/* BitField flagscontext flags	0=un-known, 1=TCP, 2=UDP (use enum prs_flags_over_ip) */
define|#
directive|define
name|PARSING_FLAGS_OVER_IP_PROTOCOL_SHIFT
value|7
define|#
directive|define
name|PARSING_FLAGS_PURE_ACK_INDICATION
value|(0x1<<9)
comment|/* BitField flagscontext flags	0=packet with data, 1=pure-ACK (use enum prs_flags_ack_type) */
define|#
directive|define
name|PARSING_FLAGS_PURE_ACK_INDICATION_SHIFT
value|9
define|#
directive|define
name|PARSING_FLAGS_TCP_OPTIONS_EXIST
value|(0x1<<10)
comment|/* BitField flagscontext flags	0=no TCP options. 1=TCP options */
define|#
directive|define
name|PARSING_FLAGS_TCP_OPTIONS_EXIST_SHIFT
value|10
define|#
directive|define
name|PARSING_FLAGS_TIME_STAMP_EXIST_FLAG
value|(0x1<<11)
comment|/* BitField flagscontext flags	According to the TCP header options parsing */
define|#
directive|define
name|PARSING_FLAGS_TIME_STAMP_EXIST_FLAG_SHIFT
value|11
define|#
directive|define
name|PARSING_FLAGS_CONNECTION_MATCH
value|(0x1<<12)
comment|/* BitField flagscontext flags	connection match in searcher indication */
define|#
directive|define
name|PARSING_FLAGS_CONNECTION_MATCH_SHIFT
value|12
define|#
directive|define
name|PARSING_FLAGS_LLC_SNAP
value|(0x1<<13)
comment|/* BitField flagscontext flags	LLC SNAP indication */
define|#
directive|define
name|PARSING_FLAGS_LLC_SNAP_SHIFT
value|13
define|#
directive|define
name|PARSING_FLAGS_RESERVED0
value|(0x3<<14)
comment|/* BitField flagscontext flags	 */
define|#
directive|define
name|PARSING_FLAGS_RESERVED0_SHIFT
value|14
block|}
struct|;
end_struct

begin_comment
comment|/*  * Parsing flags for TCP ACK type  */
end_comment

begin_enum
enum|enum
name|prs_flags_ack_type
block|{
name|PRS_FLAG_PUREACK_PIGGY
block|,
name|PRS_FLAG_PUREACK_PURE
block|,
name|MAX_PRS_FLAGS_ACK_TYPE
block|}
enum|;
end_enum

begin_comment
comment|/*  * Parsing flags for Ethernet address type  */
end_comment

begin_enum
enum|enum
name|prs_flags_eth_addr_type
block|{
name|PRS_FLAG_ETHTYPE_NON_UNICAST
block|,
name|PRS_FLAG_ETHTYPE_UNICAST
block|,
name|MAX_PRS_FLAGS_ETH_ADDR_TYPE
block|}
enum|;
end_enum

begin_comment
comment|/*  * Parsing flags for over-ethernet protocol  */
end_comment

begin_enum
enum|enum
name|prs_flags_over_eth
block|{
name|PRS_FLAG_OVERETH_UNKNOWN
block|,
name|PRS_FLAG_OVERETH_IPV4
block|,
name|PRS_FLAG_OVERETH_IPV6
block|,
name|PRS_FLAG_OVERETH_LLCSNAP_UNKNOWN
block|,
name|MAX_PRS_FLAGS_OVER_ETH
block|}
enum|;
end_enum

begin_comment
comment|/*  * Parsing flags for over-IP protocol  */
end_comment

begin_enum
enum|enum
name|prs_flags_over_ip
block|{
name|PRS_FLAG_OVERIP_UNKNOWN
block|,
name|PRS_FLAG_OVERIP_TCP
block|,
name|PRS_FLAG_OVERIP_UDP
block|,
name|MAX_PRS_FLAGS_OVER_IP
block|}
enum|;
end_enum

begin_comment
comment|/*  * SDM operation gen command (generate aggregative interrupt)  */
end_comment

begin_struct
struct|struct
name|sdm_op_gen
block|{
name|uint32_t
name|command
decl_stmt|;
define|#
directive|define
name|SDM_OP_GEN_COMP_PARAM
value|(0x1F<<0)
comment|/* BitField commandcomp_param and comp_type	thread ID/aggr interrupt number/counter depending on the completion type */
define|#
directive|define
name|SDM_OP_GEN_COMP_PARAM_SHIFT
value|0
define|#
directive|define
name|SDM_OP_GEN_COMP_TYPE
value|(0x7<<5)
comment|/* BitField commandcomp_param and comp_type	Direct messages to CM / PCI switch are not supported in operation_gen completion */
define|#
directive|define
name|SDM_OP_GEN_COMP_TYPE_SHIFT
value|5
define|#
directive|define
name|SDM_OP_GEN_AGG_VECT_IDX
value|(0xFF<<8)
comment|/* BitField commandcomp_param and comp_type	bit index in aggregated interrupt vector */
define|#
directive|define
name|SDM_OP_GEN_AGG_VECT_IDX_SHIFT
value|8
define|#
directive|define
name|SDM_OP_GEN_AGG_VECT_IDX_VALID
value|(0x1<<16)
comment|/* BitField commandcomp_param and comp_type	 */
define|#
directive|define
name|SDM_OP_GEN_AGG_VECT_IDX_VALID_SHIFT
value|16
define|#
directive|define
name|SDM_OP_GEN_RESERVED
value|(0x7FFF<<17)
comment|/* BitField commandcomp_param and comp_type	 */
define|#
directive|define
name|SDM_OP_GEN_RESERVED_SHIFT
value|17
block|}
struct|;
end_struct

begin_comment
comment|/*  * Timers connection context  */
end_comment

begin_struct
struct|struct
name|timers_block_context
block|{
name|uint32_t
name|__client0
comment|/* data of client 0 of the timers block*/
decl_stmt|;
name|uint32_t
name|__client1
comment|/* data of client 1 of the timers block*/
decl_stmt|;
name|uint32_t
name|__client2
comment|/* data of client 2 of the timers block*/
decl_stmt|;
name|uint32_t
name|flags
decl_stmt|;
define|#
directive|define
name|__TIMERS_BLOCK_CONTEXT_NUM_OF_ACTIVE_TIMERS
value|(0x3<<0)
comment|/* BitField flagscontext flags	number of active timers running */
define|#
directive|define
name|__TIMERS_BLOCK_CONTEXT_NUM_OF_ACTIVE_TIMERS_SHIFT
value|0
define|#
directive|define
name|TIMERS_BLOCK_CONTEXT_CONN_VALID_FLG
value|(0x1<<2)
comment|/* BitField flagscontext flags	flag: is connection valid (should be set by driver to 1 in toe/iscsi connections) */
define|#
directive|define
name|TIMERS_BLOCK_CONTEXT_CONN_VALID_FLG_SHIFT
value|2
define|#
directive|define
name|__TIMERS_BLOCK_CONTEXT_RESERVED0
value|(0x1FFFFFFF<<3)
comment|/* BitField flagscontext flags	 */
define|#
directive|define
name|__TIMERS_BLOCK_CONTEXT_RESERVED0_SHIFT
value|3
block|}
struct|;
end_struct

begin_comment
comment|/*  * advertise window doorbell  */
end_comment

begin_struct
struct|struct
name|toe_adv_wnd_doorbell
block|{
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|wnd_sz_lsb
comment|/* Less significant bits of advertise window update value */
decl_stmt|;
name|uint8_t
name|wnd_sz_msb
comment|/* Most significant bits of advertise window update value */
decl_stmt|;
name|struct
name|doorbell_hdr_t
name|hdr
comment|/* See description of the appropriate type */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|struct
name|doorbell_hdr_t
name|hdr
comment|/* See description of the appropriate type */
decl_stmt|;
name|uint8_t
name|wnd_sz_msb
comment|/* Most significant bits of advertise window update value */
decl_stmt|;
name|uint16_t
name|wnd_sz_lsb
comment|/* Less significant bits of advertise window update value */
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/*  * toe rx BDs update doorbell  */
end_comment

begin_struct
struct|struct
name|toe_rx_bds_doorbell
block|{
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|nbds
comment|/* BDs update value */
decl_stmt|;
name|uint8_t
name|params
decl_stmt|;
define|#
directive|define
name|TOE_RX_BDS_DOORBELL_RESERVED
value|(0x1F<<0)
comment|/* BitField params	reserved */
define|#
directive|define
name|TOE_RX_BDS_DOORBELL_RESERVED_SHIFT
value|0
define|#
directive|define
name|TOE_RX_BDS_DOORBELL_OPCODE
value|(0x7<<5)
comment|/* BitField params	BDs update doorbell opcode (2) */
define|#
directive|define
name|TOE_RX_BDS_DOORBELL_OPCODE_SHIFT
value|5
name|struct
name|doorbell_hdr_t
name|hdr
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|struct
name|doorbell_hdr_t
name|hdr
decl_stmt|;
name|uint8_t
name|params
decl_stmt|;
define|#
directive|define
name|TOE_RX_BDS_DOORBELL_RESERVED
value|(0x1F<<0)
comment|/* BitField params	reserved */
define|#
directive|define
name|TOE_RX_BDS_DOORBELL_RESERVED_SHIFT
value|0
define|#
directive|define
name|TOE_RX_BDS_DOORBELL_OPCODE
value|(0x7<<5)
comment|/* BitField params	BDs update doorbell opcode (2) */
define|#
directive|define
name|TOE_RX_BDS_DOORBELL_OPCODE_SHIFT
value|5
name|uint16_t
name|nbds
comment|/* BDs update value */
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/*  * toe rx bytes and BDs update doorbell  */
end_comment

begin_struct
struct|struct
name|toe_rx_bytes_and_bds_doorbell
block|{
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|nbytes
comment|/* nbytes */
decl_stmt|;
name|uint8_t
name|params
decl_stmt|;
define|#
directive|define
name|TOE_RX_BYTES_AND_BDS_DOORBELL_NBDS
value|(0x1F<<0)
comment|/* BitField params	producer delta from the last doorbell */
define|#
directive|define
name|TOE_RX_BYTES_AND_BDS_DOORBELL_NBDS_SHIFT
value|0
define|#
directive|define
name|TOE_RX_BYTES_AND_BDS_DOORBELL_OPCODE
value|(0x7<<5)
comment|/* BitField params	rx bytes and BDs update doorbell opcode (1) */
define|#
directive|define
name|TOE_RX_BYTES_AND_BDS_DOORBELL_OPCODE_SHIFT
value|5
name|struct
name|doorbell_hdr_t
name|hdr
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|struct
name|doorbell_hdr_t
name|hdr
decl_stmt|;
name|uint8_t
name|params
decl_stmt|;
define|#
directive|define
name|TOE_RX_BYTES_AND_BDS_DOORBELL_NBDS
value|(0x1F<<0)
comment|/* BitField params	producer delta from the last doorbell */
define|#
directive|define
name|TOE_RX_BYTES_AND_BDS_DOORBELL_NBDS_SHIFT
value|0
define|#
directive|define
name|TOE_RX_BYTES_AND_BDS_DOORBELL_OPCODE
value|(0x7<<5)
comment|/* BitField params	rx bytes and BDs update doorbell opcode (1) */
define|#
directive|define
name|TOE_RX_BYTES_AND_BDS_DOORBELL_OPCODE_SHIFT
value|5
name|uint16_t
name|nbytes
comment|/* nbytes */
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/*  * toe rx bytes doorbell  */
end_comment

begin_struct
struct|struct
name|toe_rx_byte_doorbell
block|{
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|nbytes_lsb
comment|/* bits [0:15] of nbytes */
decl_stmt|;
name|uint8_t
name|params
decl_stmt|;
define|#
directive|define
name|TOE_RX_BYTE_DOORBELL_NBYTES_MSB
value|(0x1F<<0)
comment|/* BitField params	bits [20:16] of nbytes */
define|#
directive|define
name|TOE_RX_BYTE_DOORBELL_NBYTES_MSB_SHIFT
value|0
define|#
directive|define
name|TOE_RX_BYTE_DOORBELL_OPCODE
value|(0x7<<5)
comment|/* BitField params	rx bytes doorbell opcode (0) */
define|#
directive|define
name|TOE_RX_BYTE_DOORBELL_OPCODE_SHIFT
value|5
name|struct
name|doorbell_hdr_t
name|hdr
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|struct
name|doorbell_hdr_t
name|hdr
decl_stmt|;
name|uint8_t
name|params
decl_stmt|;
define|#
directive|define
name|TOE_RX_BYTE_DOORBELL_NBYTES_MSB
value|(0x1F<<0)
comment|/* BitField params	bits [20:16] of nbytes */
define|#
directive|define
name|TOE_RX_BYTE_DOORBELL_NBYTES_MSB_SHIFT
value|0
define|#
directive|define
name|TOE_RX_BYTE_DOORBELL_OPCODE
value|(0x7<<5)
comment|/* BitField params	rx bytes doorbell opcode (0) */
define|#
directive|define
name|TOE_RX_BYTE_DOORBELL_OPCODE_SHIFT
value|5
name|uint16_t
name|nbytes_lsb
comment|/* bits [0:15] of nbytes */
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/*  * toe rx consume GRQ doorbell  */
end_comment

begin_struct
struct|struct
name|toe_rx_grq_doorbell
block|{
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|nbytes_lsb
comment|/* bits [0:15] of nbytes */
decl_stmt|;
name|uint8_t
name|params
decl_stmt|;
define|#
directive|define
name|TOE_RX_GRQ_DOORBELL_NBYTES_MSB
value|(0x1F<<0)
comment|/* BitField params	bits [20:16] of nbytes */
define|#
directive|define
name|TOE_RX_GRQ_DOORBELL_NBYTES_MSB_SHIFT
value|0
define|#
directive|define
name|TOE_RX_GRQ_DOORBELL_OPCODE
value|(0x7<<5)
comment|/* BitField params	rx GRQ doorbell opcode (4) */
define|#
directive|define
name|TOE_RX_GRQ_DOORBELL_OPCODE_SHIFT
value|5
name|struct
name|doorbell_hdr_t
name|hdr
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|struct
name|doorbell_hdr_t
name|hdr
decl_stmt|;
name|uint8_t
name|params
decl_stmt|;
define|#
directive|define
name|TOE_RX_GRQ_DOORBELL_NBYTES_MSB
value|(0x1F<<0)
comment|/* BitField params	bits [20:16] of nbytes */
define|#
directive|define
name|TOE_RX_GRQ_DOORBELL_NBYTES_MSB_SHIFT
value|0
define|#
directive|define
name|TOE_RX_GRQ_DOORBELL_OPCODE
value|(0x7<<5)
comment|/* BitField params	rx GRQ doorbell opcode (4) */
define|#
directive|define
name|TOE_RX_GRQ_DOORBELL_OPCODE_SHIFT
value|5
name|uint16_t
name|nbytes_lsb
comment|/* bits [0:15] of nbytes */
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/*  * toe doorbell  */
end_comment

begin_struct
struct|struct
name|toe_tx_doorbell
block|{
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|nbytes
comment|/* number of data bytes that were added in the doorbell */
decl_stmt|;
name|uint8_t
name|params
decl_stmt|;
define|#
directive|define
name|TOE_TX_DOORBELL_NUM_BDS
value|(0x3F<<0)
comment|/* BitField params	number of buffer descriptors that were added in the doorbell */
define|#
directive|define
name|TOE_TX_DOORBELL_NUM_BDS_SHIFT
value|0
define|#
directive|define
name|TOE_TX_DOORBELL_TX_FIN_FLAG
value|(0x1<<6)
comment|/* BitField params	tx fin command flag */
define|#
directive|define
name|TOE_TX_DOORBELL_TX_FIN_FLAG_SHIFT
value|6
define|#
directive|define
name|TOE_TX_DOORBELL_FLUSH
value|(0x1<<7)
comment|/* BitField params	doorbell queue spare flag */
define|#
directive|define
name|TOE_TX_DOORBELL_FLUSH_SHIFT
value|7
name|struct
name|doorbell_hdr_t
name|hdr
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|struct
name|doorbell_hdr_t
name|hdr
decl_stmt|;
name|uint8_t
name|params
decl_stmt|;
define|#
directive|define
name|TOE_TX_DOORBELL_NUM_BDS
value|(0x3F<<0)
comment|/* BitField params	number of buffer descriptors that were added in the doorbell */
define|#
directive|define
name|TOE_TX_DOORBELL_NUM_BDS_SHIFT
value|0
define|#
directive|define
name|TOE_TX_DOORBELL_TX_FIN_FLAG
value|(0x1<<6)
comment|/* BitField params	tx fin command flag */
define|#
directive|define
name|TOE_TX_DOORBELL_TX_FIN_FLAG_SHIFT
value|6
define|#
directive|define
name|TOE_TX_DOORBELL_FLUSH
value|(0x1<<7)
comment|/* BitField params	doorbell queue spare flag */
define|#
directive|define
name|TOE_TX_DOORBELL_FLUSH_SHIFT
value|7
name|uint16_t
name|nbytes
comment|/* number of data bytes that were added in the doorbell */
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/*  * The eth aggregative context of Tstorm  */
end_comment

begin_struct
struct|struct
name|tstorm_eth_ag_context
block|{
name|uint32_t
name|__reserved0
index|[
literal|14
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The fcoe extra aggregative context section of Tstorm  */
end_comment

begin_struct
struct|struct
name|tstorm_fcoe_extra_ag_context_section
block|{
name|uint32_t
name|__agg_val1
comment|/* aggregated value 1 */
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint8_t
name|__tcp_agg_vars2
comment|/* Various aggregative variables*/
decl_stmt|;
name|uint8_t
name|__agg_val3
comment|/* aggregated value 3 */
decl_stmt|;
name|uint16_t
name|__agg_val2
comment|/* aggregated value 2 */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|__agg_val2
comment|/* aggregated value 2 */
decl_stmt|;
name|uint8_t
name|__agg_val3
comment|/* aggregated value 3 */
decl_stmt|;
name|uint8_t
name|__tcp_agg_vars2
comment|/* Various aggregative variables*/
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|__agg_val5
decl_stmt|;
name|uint8_t
name|__agg_val6
decl_stmt|;
name|uint8_t
name|__tcp_agg_vars3
comment|/* Various aggregative variables*/
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint8_t
name|__tcp_agg_vars3
comment|/* Various aggregative variables*/
decl_stmt|;
name|uint8_t
name|__agg_val6
decl_stmt|;
name|uint16_t
name|__agg_val5
decl_stmt|;
endif|#
directive|endif
name|uint32_t
name|__lcq_prod
comment|/* Next sequence number to transmit, given by Tx */
decl_stmt|;
name|uint32_t
name|rtt_seq
comment|/* Rtt recording   sequence number */
decl_stmt|;
name|uint32_t
name|rtt_time
comment|/* Rtt recording   real time clock */
decl_stmt|;
name|uint32_t
name|__reserved66
decl_stmt|;
name|uint32_t
name|wnd_right_edge
comment|/* The right edge of the receive window. Updated by the XSTORM when a segment with ACK is transmitted */
decl_stmt|;
name|uint32_t
name|tcp_agg_vars1
decl_stmt|;
define|#
directive|define
name|TSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_FIN_SENT_FLAG
value|(0x1<<0)
comment|/* BitField tcp_agg_vars1Various aggregative variables	Sticky bit that is set when FIN is sent and remains set */
define|#
directive|define
name|TSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_FIN_SENT_FLAG_SHIFT
value|0
define|#
directive|define
name|TSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_LAST_PACKET_FIN_FLAG
value|(0x1<<1)
comment|/* BitField tcp_agg_vars1Various aggregative variables	The Tx indicates that it sent a FIN packet */
define|#
directive|define
name|TSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_LAST_PACKET_FIN_FLAG_SHIFT
value|1
define|#
directive|define
name|TSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_WND_UPD_CF
value|(0x3<<2)
comment|/* BitField tcp_agg_vars1Various aggregative variables	Counter flag to indicate a window update */
define|#
directive|define
name|TSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_WND_UPD_CF_SHIFT
value|2
define|#
directive|define
name|TSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_TIMEOUT_CF
value|(0x3<<4)
comment|/* BitField tcp_agg_vars1Various aggregative variables	Indicates that a timeout expired */
define|#
directive|define
name|TSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_TIMEOUT_CF_SHIFT
value|4
define|#
directive|define
name|TSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_WND_UPD_CF_EN
value|(0x1<<6)
comment|/* BitField tcp_agg_vars1Various aggregative variables	Enable the decision rule that considers the WndUpd counter flag */
define|#
directive|define
name|TSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_WND_UPD_CF_EN_SHIFT
value|6
define|#
directive|define
name|TSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_TIMEOUT_CF_EN
value|(0x1<<7)
comment|/* BitField tcp_agg_vars1Various aggregative variables	Enable the decision rule that considers the Timeout counter flag */
define|#
directive|define
name|TSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_TIMEOUT_CF_EN_SHIFT
value|7
define|#
directive|define
name|TSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_RETRANSMIT_SEQ_EN
value|(0x1<<8)
comment|/* BitField tcp_agg_vars1Various aggregative variables	If 1 then the Rxmit sequence decision rule is enabled */
define|#
directive|define
name|TSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_RETRANSMIT_SEQ_EN_SHIFT
value|8
define|#
directive|define
name|__TSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_LCQ_SND_EN
value|(0x1<<9)
comment|/* BitField tcp_agg_vars1Various aggregative variables	If set then the SendNext decision rule is enabled */
define|#
directive|define
name|__TSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_LCQ_SND_EN_SHIFT
value|9
define|#
directive|define
name|TSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_AUX1_FLAG
value|(0x1<<10)
comment|/* BitField tcp_agg_vars1Various aggregative variables	 */
define|#
directive|define
name|TSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_AUX1_FLAG_SHIFT
value|10
define|#
directive|define
name|TSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_AUX2_FLAG
value|(0x1<<11)
comment|/* BitField tcp_agg_vars1Various aggregative variables	 */
define|#
directive|define
name|TSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_AUX2_FLAG_SHIFT
value|11
define|#
directive|define
name|TSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_AUX1_CF_EN
value|(0x1<<12)
comment|/* BitField tcp_agg_vars1Various aggregative variables	 */
define|#
directive|define
name|TSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_AUX1_CF_EN_SHIFT
value|12
define|#
directive|define
name|TSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_AUX2_CF_EN
value|(0x1<<13)
comment|/* BitField tcp_agg_vars1Various aggregative variables	 */
define|#
directive|define
name|TSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_AUX2_CF_EN_SHIFT
value|13
define|#
directive|define
name|TSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_AUX1_CF
value|(0x3<<14)
comment|/* BitField tcp_agg_vars1Various aggregative variables	 */
define|#
directive|define
name|TSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_AUX1_CF_SHIFT
value|14
define|#
directive|define
name|TSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_AUX2_CF
value|(0x3<<16)
comment|/* BitField tcp_agg_vars1Various aggregative variables	 */
define|#
directive|define
name|TSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_AUX2_CF_SHIFT
value|16
define|#
directive|define
name|TSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_TX_BLOCKED
value|(0x1<<18)
comment|/* BitField tcp_agg_vars1Various aggregative variables	Indicates that Tx has more to send, but has not enough window to send it */
define|#
directive|define
name|TSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_TX_BLOCKED_SHIFT
value|18
define|#
directive|define
name|__TSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_AUX10_CF_EN
value|(0x1<<19)
comment|/* BitField tcp_agg_vars1Various aggregative variables	 */
define|#
directive|define
name|__TSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_AUX10_CF_EN_SHIFT
value|19
define|#
directive|define
name|__TSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_AUX11_CF_EN
value|(0x1<<20)
comment|/* BitField tcp_agg_vars1Various aggregative variables	 */
define|#
directive|define
name|__TSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_AUX11_CF_EN_SHIFT
value|20
define|#
directive|define
name|__TSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_AUX12_CF_EN
value|(0x1<<21)
comment|/* BitField tcp_agg_vars1Various aggregative variables	 */
define|#
directive|define
name|__TSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_AUX12_CF_EN_SHIFT
value|21
define|#
directive|define
name|__TSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_RESERVED1
value|(0x3<<22)
comment|/* BitField tcp_agg_vars1Various aggregative variables	 */
define|#
directive|define
name|__TSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_RESERVED1_SHIFT
value|22
define|#
directive|define
name|TSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_RETRANSMIT_PEND_SEQ
value|(0xF<<24)
comment|/* BitField tcp_agg_vars1Various aggregative variables	The sequence of the last fast retransmit or goto SS comand sent */
define|#
directive|define
name|TSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_RETRANSMIT_PEND_SEQ_SHIFT
value|24
define|#
directive|define
name|TSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_RETRANSMIT_DONE_SEQ
value|(0xF<<28)
comment|/* BitField tcp_agg_vars1Various aggregative variables	The sequence of the last fast retransmit or Goto SS command performed by the XSTORM */
define|#
directive|define
name|TSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_RETRANSMIT_DONE_SEQ_SHIFT
value|28
name|uint32_t
name|snd_max
comment|/* Maximum sequence number that was ever transmitted */
decl_stmt|;
name|uint32_t
name|__lcq_cons
comment|/* Last ACK sequence number sent by the Tx */
decl_stmt|;
name|uint32_t
name|__reserved2
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The fcoe aggregative context of Tstorm  */
end_comment

begin_struct
struct|struct
name|tstorm_fcoe_ag_context
block|{
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|ulp_credit
decl_stmt|;
name|uint8_t
name|agg_vars1
decl_stmt|;
define|#
directive|define
name|TSTORM_FCOE_AG_CONTEXT_EXISTS_IN_QM0
value|(0x1<<0)
comment|/* BitField agg_vars1Various aggregative variables	The connection is currently registered to the QM with queue index 0 */
define|#
directive|define
name|TSTORM_FCOE_AG_CONTEXT_EXISTS_IN_QM0_SHIFT
value|0
define|#
directive|define
name|TSTORM_FCOE_AG_CONTEXT_EXISTS_IN_QM1
value|(0x1<<1)
comment|/* BitField agg_vars1Various aggregative variables	The connection is currently registered to the QM with queue index 1 */
define|#
directive|define
name|TSTORM_FCOE_AG_CONTEXT_EXISTS_IN_QM1_SHIFT
value|1
define|#
directive|define
name|TSTORM_FCOE_AG_CONTEXT_EXISTS_IN_QM2
value|(0x1<<2)
comment|/* BitField agg_vars1Various aggregative variables	The connection is currently registered to the QM with queue index 2 */
define|#
directive|define
name|TSTORM_FCOE_AG_CONTEXT_EXISTS_IN_QM2_SHIFT
value|2
define|#
directive|define
name|TSTORM_FCOE_AG_CONTEXT_EXISTS_IN_QM3
value|(0x1<<3)
comment|/* BitField agg_vars1Various aggregative variables	The connection is currently registered to the QM with queue index 3 */
define|#
directive|define
name|TSTORM_FCOE_AG_CONTEXT_EXISTS_IN_QM3_SHIFT
value|3
define|#
directive|define
name|__TSTORM_FCOE_AG_CONTEXT_QUEUE0_FLUSH_CF
value|(0x3<<4)
comment|/* BitField agg_vars1Various aggregative variables	 */
define|#
directive|define
name|__TSTORM_FCOE_AG_CONTEXT_QUEUE0_FLUSH_CF_SHIFT
value|4
define|#
directive|define
name|__TSTORM_FCOE_AG_CONTEXT_AUX3_FLAG
value|(0x1<<6)
comment|/* BitField agg_vars1Various aggregative variables	 */
define|#
directive|define
name|__TSTORM_FCOE_AG_CONTEXT_AUX3_FLAG_SHIFT
value|6
define|#
directive|define
name|__TSTORM_FCOE_AG_CONTEXT_AUX4_FLAG
value|(0x1<<7)
comment|/* BitField agg_vars1Various aggregative variables	 */
define|#
directive|define
name|__TSTORM_FCOE_AG_CONTEXT_AUX4_FLAG_SHIFT
value|7
name|uint8_t
name|state
comment|/* The state of the connection */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint8_t
name|state
comment|/* The state of the connection */
decl_stmt|;
name|uint8_t
name|agg_vars1
decl_stmt|;
define|#
directive|define
name|TSTORM_FCOE_AG_CONTEXT_EXISTS_IN_QM0
value|(0x1<<0)
comment|/* BitField agg_vars1Various aggregative variables	The connection is currently registered to the QM with queue index 0 */
define|#
directive|define
name|TSTORM_FCOE_AG_CONTEXT_EXISTS_IN_QM0_SHIFT
value|0
define|#
directive|define
name|TSTORM_FCOE_AG_CONTEXT_EXISTS_IN_QM1
value|(0x1<<1)
comment|/* BitField agg_vars1Various aggregative variables	The connection is currently registered to the QM with queue index 1 */
define|#
directive|define
name|TSTORM_FCOE_AG_CONTEXT_EXISTS_IN_QM1_SHIFT
value|1
define|#
directive|define
name|TSTORM_FCOE_AG_CONTEXT_EXISTS_IN_QM2
value|(0x1<<2)
comment|/* BitField agg_vars1Various aggregative variables	The connection is currently registered to the QM with queue index 2 */
define|#
directive|define
name|TSTORM_FCOE_AG_CONTEXT_EXISTS_IN_QM2_SHIFT
value|2
define|#
directive|define
name|TSTORM_FCOE_AG_CONTEXT_EXISTS_IN_QM3
value|(0x1<<3)
comment|/* BitField agg_vars1Various aggregative variables	The connection is currently registered to the QM with queue index 3 */
define|#
directive|define
name|TSTORM_FCOE_AG_CONTEXT_EXISTS_IN_QM3_SHIFT
value|3
define|#
directive|define
name|__TSTORM_FCOE_AG_CONTEXT_QUEUE0_FLUSH_CF
value|(0x3<<4)
comment|/* BitField agg_vars1Various aggregative variables	 */
define|#
directive|define
name|__TSTORM_FCOE_AG_CONTEXT_QUEUE0_FLUSH_CF_SHIFT
value|4
define|#
directive|define
name|__TSTORM_FCOE_AG_CONTEXT_AUX3_FLAG
value|(0x1<<6)
comment|/* BitField agg_vars1Various aggregative variables	 */
define|#
directive|define
name|__TSTORM_FCOE_AG_CONTEXT_AUX3_FLAG_SHIFT
value|6
define|#
directive|define
name|__TSTORM_FCOE_AG_CONTEXT_AUX4_FLAG
value|(0x1<<7)
comment|/* BitField agg_vars1Various aggregative variables	 */
define|#
directive|define
name|__TSTORM_FCOE_AG_CONTEXT_AUX4_FLAG_SHIFT
value|7
name|uint16_t
name|ulp_credit
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|__agg_val4
decl_stmt|;
name|uint16_t
name|agg_vars2
decl_stmt|;
define|#
directive|define
name|__TSTORM_FCOE_AG_CONTEXT_AUX5_FLAG
value|(0x1<<0)
comment|/* BitField agg_vars2Various aggregative variables	 */
define|#
directive|define
name|__TSTORM_FCOE_AG_CONTEXT_AUX5_FLAG_SHIFT
value|0
define|#
directive|define
name|__TSTORM_FCOE_AG_CONTEXT_AUX6_FLAG
value|(0x1<<1)
comment|/* BitField agg_vars2Various aggregative variables	 */
define|#
directive|define
name|__TSTORM_FCOE_AG_CONTEXT_AUX6_FLAG_SHIFT
value|1
define|#
directive|define
name|__TSTORM_FCOE_AG_CONTEXT_AUX4_CF
value|(0x3<<2)
comment|/* BitField agg_vars2Various aggregative variables	 */
define|#
directive|define
name|__TSTORM_FCOE_AG_CONTEXT_AUX4_CF_SHIFT
value|2
define|#
directive|define
name|__TSTORM_FCOE_AG_CONTEXT_AUX5_CF
value|(0x3<<4)
comment|/* BitField agg_vars2Various aggregative variables	 */
define|#
directive|define
name|__TSTORM_FCOE_AG_CONTEXT_AUX5_CF_SHIFT
value|4
define|#
directive|define
name|__TSTORM_FCOE_AG_CONTEXT_AUX6_CF
value|(0x3<<6)
comment|/* BitField agg_vars2Various aggregative variables	 */
define|#
directive|define
name|__TSTORM_FCOE_AG_CONTEXT_AUX6_CF_SHIFT
value|6
define|#
directive|define
name|__TSTORM_FCOE_AG_CONTEXT_AUX7_CF
value|(0x3<<8)
comment|/* BitField agg_vars2Various aggregative variables	 */
define|#
directive|define
name|__TSTORM_FCOE_AG_CONTEXT_AUX7_CF_SHIFT
value|8
define|#
directive|define
name|__TSTORM_FCOE_AG_CONTEXT_AUX7_FLAG
value|(0x1<<10)
comment|/* BitField agg_vars2Various aggregative variables	 */
define|#
directive|define
name|__TSTORM_FCOE_AG_CONTEXT_AUX7_FLAG_SHIFT
value|10
define|#
directive|define
name|__TSTORM_FCOE_AG_CONTEXT_QUEUE0_FLUSH_CF_EN
value|(0x1<<11)
comment|/* BitField agg_vars2Various aggregative variables	 */
define|#
directive|define
name|__TSTORM_FCOE_AG_CONTEXT_QUEUE0_FLUSH_CF_EN_SHIFT
value|11
define|#
directive|define
name|TSTORM_FCOE_AG_CONTEXT_AUX4_CF_EN
value|(0x1<<12)
comment|/* BitField agg_vars2Various aggregative variables	 */
define|#
directive|define
name|TSTORM_FCOE_AG_CONTEXT_AUX4_CF_EN_SHIFT
value|12
define|#
directive|define
name|TSTORM_FCOE_AG_CONTEXT_AUX5_CF_EN
value|(0x1<<13)
comment|/* BitField agg_vars2Various aggregative variables	 */
define|#
directive|define
name|TSTORM_FCOE_AG_CONTEXT_AUX5_CF_EN_SHIFT
value|13
define|#
directive|define
name|TSTORM_FCOE_AG_CONTEXT_AUX6_CF_EN
value|(0x1<<14)
comment|/* BitField agg_vars2Various aggregative variables	 */
define|#
directive|define
name|TSTORM_FCOE_AG_CONTEXT_AUX6_CF_EN_SHIFT
value|14
define|#
directive|define
name|TSTORM_FCOE_AG_CONTEXT_AUX7_CF_EN
value|(0x1<<15)
comment|/* BitField agg_vars2Various aggregative variables	 */
define|#
directive|define
name|TSTORM_FCOE_AG_CONTEXT_AUX7_CF_EN_SHIFT
value|15
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|agg_vars2
decl_stmt|;
define|#
directive|define
name|__TSTORM_FCOE_AG_CONTEXT_AUX5_FLAG
value|(0x1<<0)
comment|/* BitField agg_vars2Various aggregative variables	 */
define|#
directive|define
name|__TSTORM_FCOE_AG_CONTEXT_AUX5_FLAG_SHIFT
value|0
define|#
directive|define
name|__TSTORM_FCOE_AG_CONTEXT_AUX6_FLAG
value|(0x1<<1)
comment|/* BitField agg_vars2Various aggregative variables	 */
define|#
directive|define
name|__TSTORM_FCOE_AG_CONTEXT_AUX6_FLAG_SHIFT
value|1
define|#
directive|define
name|__TSTORM_FCOE_AG_CONTEXT_AUX4_CF
value|(0x3<<2)
comment|/* BitField agg_vars2Various aggregative variables	 */
define|#
directive|define
name|__TSTORM_FCOE_AG_CONTEXT_AUX4_CF_SHIFT
value|2
define|#
directive|define
name|__TSTORM_FCOE_AG_CONTEXT_AUX5_CF
value|(0x3<<4)
comment|/* BitField agg_vars2Various aggregative variables	 */
define|#
directive|define
name|__TSTORM_FCOE_AG_CONTEXT_AUX5_CF_SHIFT
value|4
define|#
directive|define
name|__TSTORM_FCOE_AG_CONTEXT_AUX6_CF
value|(0x3<<6)
comment|/* BitField agg_vars2Various aggregative variables	 */
define|#
directive|define
name|__TSTORM_FCOE_AG_CONTEXT_AUX6_CF_SHIFT
value|6
define|#
directive|define
name|__TSTORM_FCOE_AG_CONTEXT_AUX7_CF
value|(0x3<<8)
comment|/* BitField agg_vars2Various aggregative variables	 */
define|#
directive|define
name|__TSTORM_FCOE_AG_CONTEXT_AUX7_CF_SHIFT
value|8
define|#
directive|define
name|__TSTORM_FCOE_AG_CONTEXT_AUX7_FLAG
value|(0x1<<10)
comment|/* BitField agg_vars2Various aggregative variables	 */
define|#
directive|define
name|__TSTORM_FCOE_AG_CONTEXT_AUX7_FLAG_SHIFT
value|10
define|#
directive|define
name|__TSTORM_FCOE_AG_CONTEXT_QUEUE0_FLUSH_CF_EN
value|(0x1<<11)
comment|/* BitField agg_vars2Various aggregative variables	 */
define|#
directive|define
name|__TSTORM_FCOE_AG_CONTEXT_QUEUE0_FLUSH_CF_EN_SHIFT
value|11
define|#
directive|define
name|TSTORM_FCOE_AG_CONTEXT_AUX4_CF_EN
value|(0x1<<12)
comment|/* BitField agg_vars2Various aggregative variables	 */
define|#
directive|define
name|TSTORM_FCOE_AG_CONTEXT_AUX4_CF_EN_SHIFT
value|12
define|#
directive|define
name|TSTORM_FCOE_AG_CONTEXT_AUX5_CF_EN
value|(0x1<<13)
comment|/* BitField agg_vars2Various aggregative variables	 */
define|#
directive|define
name|TSTORM_FCOE_AG_CONTEXT_AUX5_CF_EN_SHIFT
value|13
define|#
directive|define
name|TSTORM_FCOE_AG_CONTEXT_AUX6_CF_EN
value|(0x1<<14)
comment|/* BitField agg_vars2Various aggregative variables	 */
define|#
directive|define
name|TSTORM_FCOE_AG_CONTEXT_AUX6_CF_EN_SHIFT
value|14
define|#
directive|define
name|TSTORM_FCOE_AG_CONTEXT_AUX7_CF_EN
value|(0x1<<15)
comment|/* BitField agg_vars2Various aggregative variables	 */
define|#
directive|define
name|TSTORM_FCOE_AG_CONTEXT_AUX7_CF_EN_SHIFT
value|15
name|uint16_t
name|__agg_val4
decl_stmt|;
endif|#
directive|endif
name|struct
name|tstorm_fcoe_extra_ag_context_section
name|__extra_section
comment|/* Extra context section */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The iscsi aggregative context section of Tstorm  */
end_comment

begin_struct
struct|struct
name|tstorm_iscsi_tcp_ag_context_section
block|{
name|uint32_t
name|__agg_val1
comment|/* aggregated value 1 */
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint8_t
name|__tcp_agg_vars2
comment|/* Various aggregative variables*/
decl_stmt|;
name|uint8_t
name|__agg_val3
comment|/* aggregated value 3 */
decl_stmt|;
name|uint16_t
name|__agg_val2
comment|/* aggregated value 2 */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|__agg_val2
comment|/* aggregated value 2 */
decl_stmt|;
name|uint8_t
name|__agg_val3
comment|/* aggregated value 3 */
decl_stmt|;
name|uint8_t
name|__tcp_agg_vars2
comment|/* Various aggregative variables*/
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|__agg_val5
decl_stmt|;
name|uint8_t
name|__agg_val6
decl_stmt|;
name|uint8_t
name|__tcp_agg_vars3
comment|/* Various aggregative variables*/
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint8_t
name|__tcp_agg_vars3
comment|/* Various aggregative variables*/
decl_stmt|;
name|uint8_t
name|__agg_val6
decl_stmt|;
name|uint16_t
name|__agg_val5
decl_stmt|;
endif|#
directive|endif
name|uint32_t
name|snd_nxt
comment|/* Next sequence number to transmit, given by Tx */
decl_stmt|;
name|uint32_t
name|rtt_seq
comment|/* Rtt recording   sequence number */
decl_stmt|;
name|uint32_t
name|rtt_time
comment|/* Rtt recording   real time clock */
decl_stmt|;
name|uint32_t
name|wnd_right_edge_local
decl_stmt|;
name|uint32_t
name|wnd_right_edge
comment|/* The right edge of the receive window. Updated by the XSTORM when a segment with ACK is transmitted */
decl_stmt|;
name|uint32_t
name|tcp_agg_vars1
decl_stmt|;
define|#
directive|define
name|TSTORM_ISCSI_TCP_AG_CONTEXT_SECTION_FIN_SENT_FLAG
value|(0x1<<0)
comment|/* BitField tcp_agg_vars1Various aggregative variables	Sticky bit that is set when FIN is sent and remains set */
define|#
directive|define
name|TSTORM_ISCSI_TCP_AG_CONTEXT_SECTION_FIN_SENT_FLAG_SHIFT
value|0
define|#
directive|define
name|TSTORM_ISCSI_TCP_AG_CONTEXT_SECTION_LAST_PACKET_FIN_FLAG
value|(0x1<<1)
comment|/* BitField tcp_agg_vars1Various aggregative variables	The Tx indicates that it sent a FIN packet */
define|#
directive|define
name|TSTORM_ISCSI_TCP_AG_CONTEXT_SECTION_LAST_PACKET_FIN_FLAG_SHIFT
value|1
define|#
directive|define
name|TSTORM_ISCSI_TCP_AG_CONTEXT_SECTION_WND_UPD_CF
value|(0x3<<2)
comment|/* BitField tcp_agg_vars1Various aggregative variables	Counter flag to indicate a window update */
define|#
directive|define
name|TSTORM_ISCSI_TCP_AG_CONTEXT_SECTION_WND_UPD_CF_SHIFT
value|2
define|#
directive|define
name|TSTORM_ISCSI_TCP_AG_CONTEXT_SECTION_TIMEOUT_CF
value|(0x3<<4)
comment|/* BitField tcp_agg_vars1Various aggregative variables	Indicates that a timeout expired */
define|#
directive|define
name|TSTORM_ISCSI_TCP_AG_CONTEXT_SECTION_TIMEOUT_CF_SHIFT
value|4
define|#
directive|define
name|TSTORM_ISCSI_TCP_AG_CONTEXT_SECTION_WND_UPD_CF_EN
value|(0x1<<6)
comment|/* BitField tcp_agg_vars1Various aggregative variables	Enable the decision rule that considers the WndUpd counter flag */
define|#
directive|define
name|TSTORM_ISCSI_TCP_AG_CONTEXT_SECTION_WND_UPD_CF_EN_SHIFT
value|6
define|#
directive|define
name|TSTORM_ISCSI_TCP_AG_CONTEXT_SECTION_TIMEOUT_CF_EN
value|(0x1<<7)
comment|/* BitField tcp_agg_vars1Various aggregative variables	Enable the decision rule that considers the Timeout counter flag */
define|#
directive|define
name|TSTORM_ISCSI_TCP_AG_CONTEXT_SECTION_TIMEOUT_CF_EN_SHIFT
value|7
define|#
directive|define
name|TSTORM_ISCSI_TCP_AG_CONTEXT_SECTION_RETRANSMIT_SEQ_EN
value|(0x1<<8)
comment|/* BitField tcp_agg_vars1Various aggregative variables	If 1 then the Rxmit sequence decision rule is enabled */
define|#
directive|define
name|TSTORM_ISCSI_TCP_AG_CONTEXT_SECTION_RETRANSMIT_SEQ_EN_SHIFT
value|8
define|#
directive|define
name|TSTORM_ISCSI_TCP_AG_CONTEXT_SECTION_SND_NXT_EN
value|(0x1<<9)
comment|/* BitField tcp_agg_vars1Various aggregative variables	If set then the SendNext decision rule is enabled */
define|#
directive|define
name|TSTORM_ISCSI_TCP_AG_CONTEXT_SECTION_SND_NXT_EN_SHIFT
value|9
define|#
directive|define
name|TSTORM_ISCSI_TCP_AG_CONTEXT_SECTION_AUX1_FLAG
value|(0x1<<10)
comment|/* BitField tcp_agg_vars1Various aggregative variables	 */
define|#
directive|define
name|TSTORM_ISCSI_TCP_AG_CONTEXT_SECTION_AUX1_FLAG_SHIFT
value|10
define|#
directive|define
name|TSTORM_ISCSI_TCP_AG_CONTEXT_SECTION_AUX2_FLAG
value|(0x1<<11)
comment|/* BitField tcp_agg_vars1Various aggregative variables	 */
define|#
directive|define
name|TSTORM_ISCSI_TCP_AG_CONTEXT_SECTION_AUX2_FLAG_SHIFT
value|11
define|#
directive|define
name|TSTORM_ISCSI_TCP_AG_CONTEXT_SECTION_AUX1_CF_EN
value|(0x1<<12)
comment|/* BitField tcp_agg_vars1Various aggregative variables	 */
define|#
directive|define
name|TSTORM_ISCSI_TCP_AG_CONTEXT_SECTION_AUX1_CF_EN_SHIFT
value|12
define|#
directive|define
name|TSTORM_ISCSI_TCP_AG_CONTEXT_SECTION_AUX2_CF_EN
value|(0x1<<13)
comment|/* BitField tcp_agg_vars1Various aggregative variables	 */
define|#
directive|define
name|TSTORM_ISCSI_TCP_AG_CONTEXT_SECTION_AUX2_CF_EN_SHIFT
value|13
define|#
directive|define
name|TSTORM_ISCSI_TCP_AG_CONTEXT_SECTION_AUX1_CF
value|(0x3<<14)
comment|/* BitField tcp_agg_vars1Various aggregative variables	 */
define|#
directive|define
name|TSTORM_ISCSI_TCP_AG_CONTEXT_SECTION_AUX1_CF_SHIFT
value|14
define|#
directive|define
name|TSTORM_ISCSI_TCP_AG_CONTEXT_SECTION_AUX2_CF
value|(0x3<<16)
comment|/* BitField tcp_agg_vars1Various aggregative variables	 */
define|#
directive|define
name|TSTORM_ISCSI_TCP_AG_CONTEXT_SECTION_AUX2_CF_SHIFT
value|16
define|#
directive|define
name|TSTORM_ISCSI_TCP_AG_CONTEXT_SECTION_TX_BLOCKED
value|(0x1<<18)
comment|/* BitField tcp_agg_vars1Various aggregative variables	Indicates that Tx has more to send, but has not enough window to send it */
define|#
directive|define
name|TSTORM_ISCSI_TCP_AG_CONTEXT_SECTION_TX_BLOCKED_SHIFT
value|18
define|#
directive|define
name|__TSTORM_ISCSI_TCP_AG_CONTEXT_SECTION_AUX10_CF_EN
value|(0x1<<19)
comment|/* BitField tcp_agg_vars1Various aggregative variables	 */
define|#
directive|define
name|__TSTORM_ISCSI_TCP_AG_CONTEXT_SECTION_AUX10_CF_EN_SHIFT
value|19
define|#
directive|define
name|__TSTORM_ISCSI_TCP_AG_CONTEXT_SECTION_AUX11_CF_EN
value|(0x1<<20)
comment|/* BitField tcp_agg_vars1Various aggregative variables	 */
define|#
directive|define
name|__TSTORM_ISCSI_TCP_AG_CONTEXT_SECTION_AUX11_CF_EN_SHIFT
value|20
define|#
directive|define
name|__TSTORM_ISCSI_TCP_AG_CONTEXT_SECTION_AUX12_CF_EN
value|(0x1<<21)
comment|/* BitField tcp_agg_vars1Various aggregative variables	 */
define|#
directive|define
name|__TSTORM_ISCSI_TCP_AG_CONTEXT_SECTION_AUX12_CF_EN_SHIFT
value|21
define|#
directive|define
name|__TSTORM_ISCSI_TCP_AG_CONTEXT_SECTION_RESERVED1
value|(0x3<<22)
comment|/* BitField tcp_agg_vars1Various aggregative variables	 */
define|#
directive|define
name|__TSTORM_ISCSI_TCP_AG_CONTEXT_SECTION_RESERVED1_SHIFT
value|22
define|#
directive|define
name|TSTORM_ISCSI_TCP_AG_CONTEXT_SECTION_RETRANSMIT_PEND_SEQ
value|(0xF<<24)
comment|/* BitField tcp_agg_vars1Various aggregative variables	The sequence of the last fast retransmit or goto SS comand sent */
define|#
directive|define
name|TSTORM_ISCSI_TCP_AG_CONTEXT_SECTION_RETRANSMIT_PEND_SEQ_SHIFT
value|24
define|#
directive|define
name|TSTORM_ISCSI_TCP_AG_CONTEXT_SECTION_RETRANSMIT_DONE_SEQ
value|(0xF<<28)
comment|/* BitField tcp_agg_vars1Various aggregative variables	The sequence of the last fast retransmit or Goto SS command performed by the XSTORM */
define|#
directive|define
name|TSTORM_ISCSI_TCP_AG_CONTEXT_SECTION_RETRANSMIT_DONE_SEQ_SHIFT
value|28
name|uint32_t
name|snd_max
comment|/* Maximum sequence number that was ever transmitted */
decl_stmt|;
name|uint32_t
name|snd_una
comment|/* Last ACK sequence number sent by the Tx */
decl_stmt|;
name|uint32_t
name|__reserved2
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The iscsi aggregative context of Tstorm  */
end_comment

begin_struct
struct|struct
name|tstorm_iscsi_ag_context
block|{
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|ulp_credit
decl_stmt|;
name|uint8_t
name|agg_vars1
decl_stmt|;
define|#
directive|define
name|TSTORM_ISCSI_AG_CONTEXT_EXISTS_IN_QM0
value|(0x1<<0)
comment|/* BitField agg_vars1Various aggregative variables	The connection is currently registered to the QM with queue index 0 */
define|#
directive|define
name|TSTORM_ISCSI_AG_CONTEXT_EXISTS_IN_QM0_SHIFT
value|0
define|#
directive|define
name|TSTORM_ISCSI_AG_CONTEXT_EXISTS_IN_QM1
value|(0x1<<1)
comment|/* BitField agg_vars1Various aggregative variables	The connection is currently registered to the QM with queue index 1 */
define|#
directive|define
name|TSTORM_ISCSI_AG_CONTEXT_EXISTS_IN_QM1_SHIFT
value|1
define|#
directive|define
name|TSTORM_ISCSI_AG_CONTEXT_EXISTS_IN_QM2
value|(0x1<<2)
comment|/* BitField agg_vars1Various aggregative variables	The connection is currently registered to the QM with queue index 2 */
define|#
directive|define
name|TSTORM_ISCSI_AG_CONTEXT_EXISTS_IN_QM2_SHIFT
value|2
define|#
directive|define
name|TSTORM_ISCSI_AG_CONTEXT_EXISTS_IN_QM3
value|(0x1<<3)
comment|/* BitField agg_vars1Various aggregative variables	The connection is currently registered to the QM with queue index 3 */
define|#
directive|define
name|TSTORM_ISCSI_AG_CONTEXT_EXISTS_IN_QM3_SHIFT
value|3
define|#
directive|define
name|__TSTORM_ISCSI_AG_CONTEXT_QUEUES_FLUSH_Q0_CF
value|(0x3<<4)
comment|/* BitField agg_vars1Various aggregative variables	 */
define|#
directive|define
name|__TSTORM_ISCSI_AG_CONTEXT_QUEUES_FLUSH_Q0_CF_SHIFT
value|4
define|#
directive|define
name|__TSTORM_ISCSI_AG_CONTEXT_AUX3_FLAG
value|(0x1<<6)
comment|/* BitField agg_vars1Various aggregative variables	 */
define|#
directive|define
name|__TSTORM_ISCSI_AG_CONTEXT_AUX3_FLAG_SHIFT
value|6
define|#
directive|define
name|__TSTORM_ISCSI_AG_CONTEXT_ACK_ON_FIN_SENT_FLAG
value|(0x1<<7)
comment|/* BitField agg_vars1Various aggregative variables	 */
define|#
directive|define
name|__TSTORM_ISCSI_AG_CONTEXT_ACK_ON_FIN_SENT_FLAG_SHIFT
value|7
name|uint8_t
name|state
comment|/* The state of the connection */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint8_t
name|state
comment|/* The state of the connection */
decl_stmt|;
name|uint8_t
name|agg_vars1
decl_stmt|;
define|#
directive|define
name|TSTORM_ISCSI_AG_CONTEXT_EXISTS_IN_QM0
value|(0x1<<0)
comment|/* BitField agg_vars1Various aggregative variables	The connection is currently registered to the QM with queue index 0 */
define|#
directive|define
name|TSTORM_ISCSI_AG_CONTEXT_EXISTS_IN_QM0_SHIFT
value|0
define|#
directive|define
name|TSTORM_ISCSI_AG_CONTEXT_EXISTS_IN_QM1
value|(0x1<<1)
comment|/* BitField agg_vars1Various aggregative variables	The connection is currently registered to the QM with queue index 1 */
define|#
directive|define
name|TSTORM_ISCSI_AG_CONTEXT_EXISTS_IN_QM1_SHIFT
value|1
define|#
directive|define
name|TSTORM_ISCSI_AG_CONTEXT_EXISTS_IN_QM2
value|(0x1<<2)
comment|/* BitField agg_vars1Various aggregative variables	The connection is currently registered to the QM with queue index 2 */
define|#
directive|define
name|TSTORM_ISCSI_AG_CONTEXT_EXISTS_IN_QM2_SHIFT
value|2
define|#
directive|define
name|TSTORM_ISCSI_AG_CONTEXT_EXISTS_IN_QM3
value|(0x1<<3)
comment|/* BitField agg_vars1Various aggregative variables	The connection is currently registered to the QM with queue index 3 */
define|#
directive|define
name|TSTORM_ISCSI_AG_CONTEXT_EXISTS_IN_QM3_SHIFT
value|3
define|#
directive|define
name|__TSTORM_ISCSI_AG_CONTEXT_QUEUES_FLUSH_Q0_CF
value|(0x3<<4)
comment|/* BitField agg_vars1Various aggregative variables	 */
define|#
directive|define
name|__TSTORM_ISCSI_AG_CONTEXT_QUEUES_FLUSH_Q0_CF_SHIFT
value|4
define|#
directive|define
name|__TSTORM_ISCSI_AG_CONTEXT_AUX3_FLAG
value|(0x1<<6)
comment|/* BitField agg_vars1Various aggregative variables	 */
define|#
directive|define
name|__TSTORM_ISCSI_AG_CONTEXT_AUX3_FLAG_SHIFT
value|6
define|#
directive|define
name|__TSTORM_ISCSI_AG_CONTEXT_ACK_ON_FIN_SENT_FLAG
value|(0x1<<7)
comment|/* BitField agg_vars1Various aggregative variables	 */
define|#
directive|define
name|__TSTORM_ISCSI_AG_CONTEXT_ACK_ON_FIN_SENT_FLAG_SHIFT
value|7
name|uint16_t
name|ulp_credit
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|__agg_val4
decl_stmt|;
name|uint16_t
name|agg_vars2
decl_stmt|;
define|#
directive|define
name|__TSTORM_ISCSI_AG_CONTEXT_MSL_TIMER_SET_FLAG
value|(0x1<<0)
comment|/* BitField agg_vars2Various aggregative variables	 */
define|#
directive|define
name|__TSTORM_ISCSI_AG_CONTEXT_MSL_TIMER_SET_FLAG_SHIFT
value|0
define|#
directive|define
name|__TSTORM_ISCSI_AG_CONTEXT_FIN_SENT_FIRST_FLAG
value|(0x1<<1)
comment|/* BitField agg_vars2Various aggregative variables	 */
define|#
directive|define
name|__TSTORM_ISCSI_AG_CONTEXT_FIN_SENT_FIRST_FLAG_SHIFT
value|1
define|#
directive|define
name|__TSTORM_ISCSI_AG_CONTEXT_RST_SENT_CF
value|(0x3<<2)
comment|/* BitField agg_vars2Various aggregative variables	 */
define|#
directive|define
name|__TSTORM_ISCSI_AG_CONTEXT_RST_SENT_CF_SHIFT
value|2
define|#
directive|define
name|__TSTORM_ISCSI_AG_CONTEXT_WAKEUP_CALL_CF
value|(0x3<<4)
comment|/* BitField agg_vars2Various aggregative variables	 */
define|#
directive|define
name|__TSTORM_ISCSI_AG_CONTEXT_WAKEUP_CALL_CF_SHIFT
value|4
define|#
directive|define
name|__TSTORM_ISCSI_AG_CONTEXT_AUX6_CF
value|(0x3<<6)
comment|/* BitField agg_vars2Various aggregative variables	 */
define|#
directive|define
name|__TSTORM_ISCSI_AG_CONTEXT_AUX6_CF_SHIFT
value|6
define|#
directive|define
name|__TSTORM_ISCSI_AG_CONTEXT_AUX7_CF
value|(0x3<<8)
comment|/* BitField agg_vars2Various aggregative variables	 */
define|#
directive|define
name|__TSTORM_ISCSI_AG_CONTEXT_AUX7_CF_SHIFT
value|8
define|#
directive|define
name|__TSTORM_ISCSI_AG_CONTEXT_AUX7_FLAG
value|(0x1<<10)
comment|/* BitField agg_vars2Various aggregative variables	 */
define|#
directive|define
name|__TSTORM_ISCSI_AG_CONTEXT_AUX7_FLAG_SHIFT
value|10
define|#
directive|define
name|__TSTORM_ISCSI_AG_CONTEXT_QUEUES_FLUSH_Q0_CF_EN
value|(0x1<<11)
comment|/* BitField agg_vars2Various aggregative variables	 */
define|#
directive|define
name|__TSTORM_ISCSI_AG_CONTEXT_QUEUES_FLUSH_Q0_CF_EN_SHIFT
value|11
define|#
directive|define
name|__TSTORM_ISCSI_AG_CONTEXT_RST_SENT_CF_EN
value|(0x1<<12)
comment|/* BitField agg_vars2Various aggregative variables	 */
define|#
directive|define
name|__TSTORM_ISCSI_AG_CONTEXT_RST_SENT_CF_EN_SHIFT
value|12
define|#
directive|define
name|__TSTORM_ISCSI_AG_CONTEXT_WAKEUP_CALL_CF_EN
value|(0x1<<13)
comment|/* BitField agg_vars2Various aggregative variables	 */
define|#
directive|define
name|__TSTORM_ISCSI_AG_CONTEXT_WAKEUP_CALL_CF_EN_SHIFT
value|13
define|#
directive|define
name|TSTORM_ISCSI_AG_CONTEXT_AUX6_CF_EN
value|(0x1<<14)
comment|/* BitField agg_vars2Various aggregative variables	 */
define|#
directive|define
name|TSTORM_ISCSI_AG_CONTEXT_AUX6_CF_EN_SHIFT
value|14
define|#
directive|define
name|TSTORM_ISCSI_AG_CONTEXT_AUX7_CF_EN
value|(0x1<<15)
comment|/* BitField agg_vars2Various aggregative variables	 */
define|#
directive|define
name|TSTORM_ISCSI_AG_CONTEXT_AUX7_CF_EN_SHIFT
value|15
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|agg_vars2
decl_stmt|;
define|#
directive|define
name|__TSTORM_ISCSI_AG_CONTEXT_MSL_TIMER_SET_FLAG
value|(0x1<<0)
comment|/* BitField agg_vars2Various aggregative variables	 */
define|#
directive|define
name|__TSTORM_ISCSI_AG_CONTEXT_MSL_TIMER_SET_FLAG_SHIFT
value|0
define|#
directive|define
name|__TSTORM_ISCSI_AG_CONTEXT_FIN_SENT_FIRST_FLAG
value|(0x1<<1)
comment|/* BitField agg_vars2Various aggregative variables	 */
define|#
directive|define
name|__TSTORM_ISCSI_AG_CONTEXT_FIN_SENT_FIRST_FLAG_SHIFT
value|1
define|#
directive|define
name|__TSTORM_ISCSI_AG_CONTEXT_RST_SENT_CF
value|(0x3<<2)
comment|/* BitField agg_vars2Various aggregative variables	 */
define|#
directive|define
name|__TSTORM_ISCSI_AG_CONTEXT_RST_SENT_CF_SHIFT
value|2
define|#
directive|define
name|__TSTORM_ISCSI_AG_CONTEXT_WAKEUP_CALL_CF
value|(0x3<<4)
comment|/* BitField agg_vars2Various aggregative variables	 */
define|#
directive|define
name|__TSTORM_ISCSI_AG_CONTEXT_WAKEUP_CALL_CF_SHIFT
value|4
define|#
directive|define
name|__TSTORM_ISCSI_AG_CONTEXT_AUX6_CF
value|(0x3<<6)
comment|/* BitField agg_vars2Various aggregative variables	 */
define|#
directive|define
name|__TSTORM_ISCSI_AG_CONTEXT_AUX6_CF_SHIFT
value|6
define|#
directive|define
name|__TSTORM_ISCSI_AG_CONTEXT_AUX7_CF
value|(0x3<<8)
comment|/* BitField agg_vars2Various aggregative variables	 */
define|#
directive|define
name|__TSTORM_ISCSI_AG_CONTEXT_AUX7_CF_SHIFT
value|8
define|#
directive|define
name|__TSTORM_ISCSI_AG_CONTEXT_AUX7_FLAG
value|(0x1<<10)
comment|/* BitField agg_vars2Various aggregative variables	 */
define|#
directive|define
name|__TSTORM_ISCSI_AG_CONTEXT_AUX7_FLAG_SHIFT
value|10
define|#
directive|define
name|__TSTORM_ISCSI_AG_CONTEXT_QUEUES_FLUSH_Q0_CF_EN
value|(0x1<<11)
comment|/* BitField agg_vars2Various aggregative variables	 */
define|#
directive|define
name|__TSTORM_ISCSI_AG_CONTEXT_QUEUES_FLUSH_Q0_CF_EN_SHIFT
value|11
define|#
directive|define
name|__TSTORM_ISCSI_AG_CONTEXT_RST_SENT_CF_EN
value|(0x1<<12)
comment|/* BitField agg_vars2Various aggregative variables	 */
define|#
directive|define
name|__TSTORM_ISCSI_AG_CONTEXT_RST_SENT_CF_EN_SHIFT
value|12
define|#
directive|define
name|__TSTORM_ISCSI_AG_CONTEXT_WAKEUP_CALL_CF_EN
value|(0x1<<13)
comment|/* BitField agg_vars2Various aggregative variables	 */
define|#
directive|define
name|__TSTORM_ISCSI_AG_CONTEXT_WAKEUP_CALL_CF_EN_SHIFT
value|13
define|#
directive|define
name|TSTORM_ISCSI_AG_CONTEXT_AUX6_CF_EN
value|(0x1<<14)
comment|/* BitField agg_vars2Various aggregative variables	 */
define|#
directive|define
name|TSTORM_ISCSI_AG_CONTEXT_AUX6_CF_EN_SHIFT
value|14
define|#
directive|define
name|TSTORM_ISCSI_AG_CONTEXT_AUX7_CF_EN
value|(0x1<<15)
comment|/* BitField agg_vars2Various aggregative variables	 */
define|#
directive|define
name|TSTORM_ISCSI_AG_CONTEXT_AUX7_CF_EN_SHIFT
value|15
name|uint16_t
name|__agg_val4
decl_stmt|;
endif|#
directive|endif
name|struct
name|tstorm_iscsi_tcp_ag_context_section
name|tcp
comment|/* TCP context section, shared in TOE and iSCSI */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The tcp aggregative context section of Tstorm  */
end_comment

begin_struct
struct|struct
name|tstorm_tcp_tcp_ag_context_section
block|{
name|uint32_t
name|__agg_val1
comment|/* aggregated value 1 */
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint8_t
name|__tcp_agg_vars2
comment|/* Various aggregative variables*/
decl_stmt|;
name|uint8_t
name|__agg_val3
comment|/* aggregated value 3 */
decl_stmt|;
name|uint16_t
name|__agg_val2
comment|/* aggregated value 2 */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|__agg_val2
comment|/* aggregated value 2 */
decl_stmt|;
name|uint8_t
name|__agg_val3
comment|/* aggregated value 3 */
decl_stmt|;
name|uint8_t
name|__tcp_agg_vars2
comment|/* Various aggregative variables*/
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|__agg_val5
decl_stmt|;
name|uint8_t
name|__agg_val6
decl_stmt|;
name|uint8_t
name|__tcp_agg_vars3
comment|/* Various aggregative variables*/
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint8_t
name|__tcp_agg_vars3
comment|/* Various aggregative variables*/
decl_stmt|;
name|uint8_t
name|__agg_val6
decl_stmt|;
name|uint16_t
name|__agg_val5
decl_stmt|;
endif|#
directive|endif
name|uint32_t
name|snd_nxt
comment|/* Next sequence number to transmit, given by Tx */
decl_stmt|;
name|uint32_t
name|rtt_seq
comment|/* Rtt recording   sequence number */
decl_stmt|;
name|uint32_t
name|rtt_time
comment|/* Rtt recording   real time clock */
decl_stmt|;
name|uint32_t
name|__reserved66
decl_stmt|;
name|uint32_t
name|wnd_right_edge
comment|/* The right edge of the receive window. Updated by the XSTORM when a segment with ACK is transmitted */
decl_stmt|;
name|uint32_t
name|tcp_agg_vars1
decl_stmt|;
define|#
directive|define
name|TSTORM_TCP_TCP_AG_CONTEXT_SECTION_FIN_SENT_FLAG
value|(0x1<<0)
comment|/* BitField tcp_agg_vars1Various aggregative variables	Sticky bit that is set when FIN is sent and remains set */
define|#
directive|define
name|TSTORM_TCP_TCP_AG_CONTEXT_SECTION_FIN_SENT_FLAG_SHIFT
value|0
define|#
directive|define
name|TSTORM_TCP_TCP_AG_CONTEXT_SECTION_LAST_PACKET_FIN_FLAG
value|(0x1<<1)
comment|/* BitField tcp_agg_vars1Various aggregative variables	The Tx indicates that it sent a FIN packet */
define|#
directive|define
name|TSTORM_TCP_TCP_AG_CONTEXT_SECTION_LAST_PACKET_FIN_FLAG_SHIFT
value|1
define|#
directive|define
name|TSTORM_TCP_TCP_AG_CONTEXT_SECTION_WND_UPD_CF
value|(0x3<<2)
comment|/* BitField tcp_agg_vars1Various aggregative variables	Counter flag to indicate a window update */
define|#
directive|define
name|TSTORM_TCP_TCP_AG_CONTEXT_SECTION_WND_UPD_CF_SHIFT
value|2
define|#
directive|define
name|TSTORM_TCP_TCP_AG_CONTEXT_SECTION_TIMEOUT_CF
value|(0x3<<4)
comment|/* BitField tcp_agg_vars1Various aggregative variables	Indicates that a timeout expired */
define|#
directive|define
name|TSTORM_TCP_TCP_AG_CONTEXT_SECTION_TIMEOUT_CF_SHIFT
value|4
define|#
directive|define
name|TSTORM_TCP_TCP_AG_CONTEXT_SECTION_WND_UPD_CF_EN
value|(0x1<<6)
comment|/* BitField tcp_agg_vars1Various aggregative variables	Enable the decision rule that considers the WndUpd counter flag */
define|#
directive|define
name|TSTORM_TCP_TCP_AG_CONTEXT_SECTION_WND_UPD_CF_EN_SHIFT
value|6
define|#
directive|define
name|TSTORM_TCP_TCP_AG_CONTEXT_SECTION_TIMEOUT_CF_EN
value|(0x1<<7)
comment|/* BitField tcp_agg_vars1Various aggregative variables	Enable the decision rule that considers the Timeout counter flag */
define|#
directive|define
name|TSTORM_TCP_TCP_AG_CONTEXT_SECTION_TIMEOUT_CF_EN_SHIFT
value|7
define|#
directive|define
name|TSTORM_TCP_TCP_AG_CONTEXT_SECTION_RETRANSMIT_SEQ_EN
value|(0x1<<8)
comment|/* BitField tcp_agg_vars1Various aggregative variables	If 1 then the Rxmit sequence decision rule is enabled */
define|#
directive|define
name|TSTORM_TCP_TCP_AG_CONTEXT_SECTION_RETRANSMIT_SEQ_EN_SHIFT
value|8
define|#
directive|define
name|TSTORM_TCP_TCP_AG_CONTEXT_SECTION_SND_NXT_EN
value|(0x1<<9)
comment|/* BitField tcp_agg_vars1Various aggregative variables	If set then the SendNext decision rule is enabled */
define|#
directive|define
name|TSTORM_TCP_TCP_AG_CONTEXT_SECTION_SND_NXT_EN_SHIFT
value|9
define|#
directive|define
name|TSTORM_TCP_TCP_AG_CONTEXT_SECTION_AUX1_FLAG
value|(0x1<<10)
comment|/* BitField tcp_agg_vars1Various aggregative variables	 */
define|#
directive|define
name|TSTORM_TCP_TCP_AG_CONTEXT_SECTION_AUX1_FLAG_SHIFT
value|10
define|#
directive|define
name|TSTORM_TCP_TCP_AG_CONTEXT_SECTION_AUX2_FLAG
value|(0x1<<11)
comment|/* BitField tcp_agg_vars1Various aggregative variables	 */
define|#
directive|define
name|TSTORM_TCP_TCP_AG_CONTEXT_SECTION_AUX2_FLAG_SHIFT
value|11
define|#
directive|define
name|TSTORM_TCP_TCP_AG_CONTEXT_SECTION_AUX1_CF_EN
value|(0x1<<12)
comment|/* BitField tcp_agg_vars1Various aggregative variables	 */
define|#
directive|define
name|TSTORM_TCP_TCP_AG_CONTEXT_SECTION_AUX1_CF_EN_SHIFT
value|12
define|#
directive|define
name|TSTORM_TCP_TCP_AG_CONTEXT_SECTION_AUX2_CF_EN
value|(0x1<<13)
comment|/* BitField tcp_agg_vars1Various aggregative variables	 */
define|#
directive|define
name|TSTORM_TCP_TCP_AG_CONTEXT_SECTION_AUX2_CF_EN_SHIFT
value|13
define|#
directive|define
name|TSTORM_TCP_TCP_AG_CONTEXT_SECTION_AUX1_CF
value|(0x3<<14)
comment|/* BitField tcp_agg_vars1Various aggregative variables	 */
define|#
directive|define
name|TSTORM_TCP_TCP_AG_CONTEXT_SECTION_AUX1_CF_SHIFT
value|14
define|#
directive|define
name|TSTORM_TCP_TCP_AG_CONTEXT_SECTION_AUX2_CF
value|(0x3<<16)
comment|/* BitField tcp_agg_vars1Various aggregative variables	 */
define|#
directive|define
name|TSTORM_TCP_TCP_AG_CONTEXT_SECTION_AUX2_CF_SHIFT
value|16
define|#
directive|define
name|TSTORM_TCP_TCP_AG_CONTEXT_SECTION_TX_BLOCKED
value|(0x1<<18)
comment|/* BitField tcp_agg_vars1Various aggregative variables	Indicates that Tx has more to send, but has not enough window to send it */
define|#
directive|define
name|TSTORM_TCP_TCP_AG_CONTEXT_SECTION_TX_BLOCKED_SHIFT
value|18
define|#
directive|define
name|__TSTORM_TCP_TCP_AG_CONTEXT_SECTION_AUX10_CF_EN
value|(0x1<<19)
comment|/* BitField tcp_agg_vars1Various aggregative variables	 */
define|#
directive|define
name|__TSTORM_TCP_TCP_AG_CONTEXT_SECTION_AUX10_CF_EN_SHIFT
value|19
define|#
directive|define
name|__TSTORM_TCP_TCP_AG_CONTEXT_SECTION_AUX11_CF_EN
value|(0x1<<20)
comment|/* BitField tcp_agg_vars1Various aggregative variables	 */
define|#
directive|define
name|__TSTORM_TCP_TCP_AG_CONTEXT_SECTION_AUX11_CF_EN_SHIFT
value|20
define|#
directive|define
name|__TSTORM_TCP_TCP_AG_CONTEXT_SECTION_AUX12_CF_EN
value|(0x1<<21)
comment|/* BitField tcp_agg_vars1Various aggregative variables	 */
define|#
directive|define
name|__TSTORM_TCP_TCP_AG_CONTEXT_SECTION_AUX12_CF_EN_SHIFT
value|21
define|#
directive|define
name|__TSTORM_TCP_TCP_AG_CONTEXT_SECTION_RESERVED1
value|(0x3<<22)
comment|/* BitField tcp_agg_vars1Various aggregative variables	 */
define|#
directive|define
name|__TSTORM_TCP_TCP_AG_CONTEXT_SECTION_RESERVED1_SHIFT
value|22
define|#
directive|define
name|TSTORM_TCP_TCP_AG_CONTEXT_SECTION_RETRANSMIT_PEND_SEQ
value|(0xF<<24)
comment|/* BitField tcp_agg_vars1Various aggregative variables	The sequence of the last fast retransmit or goto SS comand sent */
define|#
directive|define
name|TSTORM_TCP_TCP_AG_CONTEXT_SECTION_RETRANSMIT_PEND_SEQ_SHIFT
value|24
define|#
directive|define
name|TSTORM_TCP_TCP_AG_CONTEXT_SECTION_RETRANSMIT_DONE_SEQ
value|(0xF<<28)
comment|/* BitField tcp_agg_vars1Various aggregative variables	The sequence of the last fast retransmit or Goto SS command performed by the XSTORM */
define|#
directive|define
name|TSTORM_TCP_TCP_AG_CONTEXT_SECTION_RETRANSMIT_DONE_SEQ_SHIFT
value|28
name|uint32_t
name|snd_max
comment|/* Maximum sequence number that was ever transmitted */
decl_stmt|;
name|uint32_t
name|snd_una
comment|/* Last ACK sequence number sent by the Tx */
decl_stmt|;
name|uint32_t
name|__reserved2
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The toe aggregative context section of Tstorm  */
end_comment

begin_struct
struct|struct
name|tstorm_toe_tcp_ag_context_section
block|{
name|uint32_t
name|__agg_val1
comment|/* aggregated value 1 */
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint8_t
name|__tcp_agg_vars2
comment|/* Various aggregative variables*/
decl_stmt|;
name|uint8_t
name|__agg_val3
comment|/* aggregated value 3 */
decl_stmt|;
name|uint16_t
name|__agg_val2
comment|/* aggregated value 2 */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|__agg_val2
comment|/* aggregated value 2 */
decl_stmt|;
name|uint8_t
name|__agg_val3
comment|/* aggregated value 3 */
decl_stmt|;
name|uint8_t
name|__tcp_agg_vars2
comment|/* Various aggregative variables*/
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|__agg_val5
decl_stmt|;
name|uint8_t
name|__agg_val6
decl_stmt|;
name|uint8_t
name|__tcp_agg_vars3
comment|/* Various aggregative variables*/
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint8_t
name|__tcp_agg_vars3
comment|/* Various aggregative variables*/
decl_stmt|;
name|uint8_t
name|__agg_val6
decl_stmt|;
name|uint16_t
name|__agg_val5
decl_stmt|;
endif|#
directive|endif
name|uint32_t
name|snd_nxt
comment|/* Next sequence number to transmit, given by Tx */
decl_stmt|;
name|uint32_t
name|rtt_seq
comment|/* Rtt recording   sequence number */
decl_stmt|;
name|uint32_t
name|rtt_time
comment|/* Rtt recording   real time clock */
decl_stmt|;
name|uint32_t
name|__reserved66
decl_stmt|;
name|uint32_t
name|wnd_right_edge
comment|/* The right edge of the receive window. Updated by the XSTORM when a segment with ACK is transmitted */
decl_stmt|;
name|uint32_t
name|tcp_agg_vars1
decl_stmt|;
define|#
directive|define
name|TSTORM_TOE_TCP_AG_CONTEXT_SECTION_FIN_SENT_FLAG
value|(0x1<<0)
comment|/* BitField tcp_agg_vars1Various aggregative variables	Sticky bit that is set when FIN is sent and remains set */
define|#
directive|define
name|TSTORM_TOE_TCP_AG_CONTEXT_SECTION_FIN_SENT_FLAG_SHIFT
value|0
define|#
directive|define
name|TSTORM_TOE_TCP_AG_CONTEXT_SECTION_LAST_PACKET_FIN_FLAG
value|(0x1<<1)
comment|/* BitField tcp_agg_vars1Various aggregative variables	The Tx indicates that it sent a FIN packet */
define|#
directive|define
name|TSTORM_TOE_TCP_AG_CONTEXT_SECTION_LAST_PACKET_FIN_FLAG_SHIFT
value|1
define|#
directive|define
name|TSTORM_TOE_TCP_AG_CONTEXT_SECTION_RESERVED52
value|(0x3<<2)
comment|/* BitField tcp_agg_vars1Various aggregative variables	Counter flag to indicate a window update */
define|#
directive|define
name|TSTORM_TOE_TCP_AG_CONTEXT_SECTION_RESERVED52_SHIFT
value|2
define|#
directive|define
name|TSTORM_TOE_TCP_AG_CONTEXT_SECTION_TIMEOUT_CF
value|(0x3<<4)
comment|/* BitField tcp_agg_vars1Various aggregative variables	Indicates that a timeout expired */
define|#
directive|define
name|TSTORM_TOE_TCP_AG_CONTEXT_SECTION_TIMEOUT_CF_SHIFT
value|4
define|#
directive|define
name|TSTORM_TOE_TCP_AG_CONTEXT_SECTION_RESERVED_WND_UPD_CF_EN
value|(0x1<<6)
comment|/* BitField tcp_agg_vars1Various aggregative variables	Enable the decision rule that considers the WndUpd counter flag */
define|#
directive|define
name|TSTORM_TOE_TCP_AG_CONTEXT_SECTION_RESERVED_WND_UPD_CF_EN_SHIFT
value|6
define|#
directive|define
name|TSTORM_TOE_TCP_AG_CONTEXT_SECTION_TIMEOUT_CF_EN
value|(0x1<<7)
comment|/* BitField tcp_agg_vars1Various aggregative variables	Enable the decision rule that considers the Timeout counter flag */
define|#
directive|define
name|TSTORM_TOE_TCP_AG_CONTEXT_SECTION_TIMEOUT_CF_EN_SHIFT
value|7
define|#
directive|define
name|TSTORM_TOE_TCP_AG_CONTEXT_SECTION_RETRANSMIT_SEQ_EN
value|(0x1<<8)
comment|/* BitField tcp_agg_vars1Various aggregative variables	If 1 then the Rxmit sequence decision rule is enabled */
define|#
directive|define
name|TSTORM_TOE_TCP_AG_CONTEXT_SECTION_RETRANSMIT_SEQ_EN_SHIFT
value|8
define|#
directive|define
name|TSTORM_TOE_TCP_AG_CONTEXT_SECTION_SND_NXT_EN
value|(0x1<<9)
comment|/* BitField tcp_agg_vars1Various aggregative variables	If set then the SendNext decision rule is enabled */
define|#
directive|define
name|TSTORM_TOE_TCP_AG_CONTEXT_SECTION_SND_NXT_EN_SHIFT
value|9
define|#
directive|define
name|TSTORM_TOE_TCP_AG_CONTEXT_SECTION_NEWRTTSAMPLE
value|(0x1<<10)
comment|/* BitField tcp_agg_vars1Various aggregative variables	 */
define|#
directive|define
name|TSTORM_TOE_TCP_AG_CONTEXT_SECTION_NEWRTTSAMPLE_SHIFT
value|10
define|#
directive|define
name|TSTORM_TOE_TCP_AG_CONTEXT_SECTION_RESERVED55
value|(0x1<<11)
comment|/* BitField tcp_agg_vars1Various aggregative variables	 */
define|#
directive|define
name|TSTORM_TOE_TCP_AG_CONTEXT_SECTION_RESERVED55_SHIFT
value|11
define|#
directive|define
name|TSTORM_TOE_TCP_AG_CONTEXT_SECTION_RESERVED_AUX1_CF_EN
value|(0x1<<12)
comment|/* BitField tcp_agg_vars1Various aggregative variables	 */
define|#
directive|define
name|TSTORM_TOE_TCP_AG_CONTEXT_SECTION_RESERVED_AUX1_CF_EN_SHIFT
value|12
define|#
directive|define
name|TSTORM_TOE_TCP_AG_CONTEXT_SECTION_RESERVED_AUX2_CF_EN
value|(0x1<<13)
comment|/* BitField tcp_agg_vars1Various aggregative variables	 */
define|#
directive|define
name|TSTORM_TOE_TCP_AG_CONTEXT_SECTION_RESERVED_AUX2_CF_EN_SHIFT
value|13
define|#
directive|define
name|TSTORM_TOE_TCP_AG_CONTEXT_SECTION_RESERVED56
value|(0x3<<14)
comment|/* BitField tcp_agg_vars1Various aggregative variables	 */
define|#
directive|define
name|TSTORM_TOE_TCP_AG_CONTEXT_SECTION_RESERVED56_SHIFT
value|14
define|#
directive|define
name|TSTORM_TOE_TCP_AG_CONTEXT_SECTION_RESERVED57
value|(0x3<<16)
comment|/* BitField tcp_agg_vars1Various aggregative variables	 */
define|#
directive|define
name|TSTORM_TOE_TCP_AG_CONTEXT_SECTION_RESERVED57_SHIFT
value|16
define|#
directive|define
name|TSTORM_TOE_TCP_AG_CONTEXT_SECTION_TX_BLOCKED
value|(0x1<<18)
comment|/* BitField tcp_agg_vars1Various aggregative variables	Indicates that Tx has more to send, but has not enough window to send it */
define|#
directive|define
name|TSTORM_TOE_TCP_AG_CONTEXT_SECTION_TX_BLOCKED_SHIFT
value|18
define|#
directive|define
name|__TSTORM_TOE_TCP_AG_CONTEXT_SECTION_AUX10_CF_EN
value|(0x1<<19)
comment|/* BitField tcp_agg_vars1Various aggregative variables	 */
define|#
directive|define
name|__TSTORM_TOE_TCP_AG_CONTEXT_SECTION_AUX10_CF_EN_SHIFT
value|19
define|#
directive|define
name|__TSTORM_TOE_TCP_AG_CONTEXT_SECTION_AUX11_CF_EN
value|(0x1<<20)
comment|/* BitField tcp_agg_vars1Various aggregative variables	 */
define|#
directive|define
name|__TSTORM_TOE_TCP_AG_CONTEXT_SECTION_AUX11_CF_EN_SHIFT
value|20
define|#
directive|define
name|__TSTORM_TOE_TCP_AG_CONTEXT_SECTION_AUX12_CF_EN
value|(0x1<<21)
comment|/* BitField tcp_agg_vars1Various aggregative variables	 */
define|#
directive|define
name|__TSTORM_TOE_TCP_AG_CONTEXT_SECTION_AUX12_CF_EN_SHIFT
value|21
define|#
directive|define
name|__TSTORM_TOE_TCP_AG_CONTEXT_SECTION_RESERVED1
value|(0x3<<22)
comment|/* BitField tcp_agg_vars1Various aggregative variables	 */
define|#
directive|define
name|__TSTORM_TOE_TCP_AG_CONTEXT_SECTION_RESERVED1_SHIFT
value|22
define|#
directive|define
name|TSTORM_TOE_TCP_AG_CONTEXT_SECTION_RETRANSMIT_PEND_SEQ
value|(0xF<<24)
comment|/* BitField tcp_agg_vars1Various aggregative variables	The sequence of the last fast retransmit or goto SS comand sent */
define|#
directive|define
name|TSTORM_TOE_TCP_AG_CONTEXT_SECTION_RETRANSMIT_PEND_SEQ_SHIFT
value|24
define|#
directive|define
name|TSTORM_TOE_TCP_AG_CONTEXT_SECTION_RETRANSMIT_DONE_SEQ
value|(0xF<<28)
comment|/* BitField tcp_agg_vars1Various aggregative variables	The sequence of the last fast retransmit or Goto SS command performed by the XSTORM */
define|#
directive|define
name|TSTORM_TOE_TCP_AG_CONTEXT_SECTION_RETRANSMIT_DONE_SEQ_SHIFT
value|28
name|uint32_t
name|snd_max
comment|/* Maximum sequence number that was ever transmitted */
decl_stmt|;
name|uint32_t
name|snd_una
comment|/* Last ACK sequence number sent by the Tx */
decl_stmt|;
name|uint32_t
name|__reserved2
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The toe aggregative context of Tstorm  */
end_comment

begin_struct
struct|struct
name|tstorm_toe_ag_context
block|{
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|reserved54
decl_stmt|;
name|uint8_t
name|agg_vars1
decl_stmt|;
define|#
directive|define
name|TSTORM_TOE_AG_CONTEXT_EXISTS_IN_QM0
value|(0x1<<0)
comment|/* BitField agg_vars1Various aggregative variables	The connection is currently registered to the QM with queue index 0 */
define|#
directive|define
name|TSTORM_TOE_AG_CONTEXT_EXISTS_IN_QM0_SHIFT
value|0
define|#
directive|define
name|TSTORM_TOE_AG_CONTEXT_RESERVED51
value|(0x1<<1)
comment|/* BitField agg_vars1Various aggregative variables	The connection is currently registered to the QM with queue index 1 */
define|#
directive|define
name|TSTORM_TOE_AG_CONTEXT_RESERVED51_SHIFT
value|1
define|#
directive|define
name|TSTORM_TOE_AG_CONTEXT_RESERVED52
value|(0x1<<2)
comment|/* BitField agg_vars1Various aggregative variables	The connection is currently registered to the QM with queue index 2 */
define|#
directive|define
name|TSTORM_TOE_AG_CONTEXT_RESERVED52_SHIFT
value|2
define|#
directive|define
name|TSTORM_TOE_AG_CONTEXT_RESERVED53
value|(0x1<<3)
comment|/* BitField agg_vars1Various aggregative variables	The connection is currently registered to the QM with queue index 3 */
define|#
directive|define
name|TSTORM_TOE_AG_CONTEXT_RESERVED53_SHIFT
value|3
define|#
directive|define
name|__TSTORM_TOE_AG_CONTEXT_QUEUES_FLUSH_Q0_CF
value|(0x3<<4)
comment|/* BitField agg_vars1Various aggregative variables	 */
define|#
directive|define
name|__TSTORM_TOE_AG_CONTEXT_QUEUES_FLUSH_Q0_CF_SHIFT
value|4
define|#
directive|define
name|__TSTORM_TOE_AG_CONTEXT_AUX3_FLAG
value|(0x1<<6)
comment|/* BitField agg_vars1Various aggregative variables	 */
define|#
directive|define
name|__TSTORM_TOE_AG_CONTEXT_AUX3_FLAG_SHIFT
value|6
define|#
directive|define
name|__TSTORM_TOE_AG_CONTEXT_AUX4_FLAG
value|(0x1<<7)
comment|/* BitField agg_vars1Various aggregative variables	 */
define|#
directive|define
name|__TSTORM_TOE_AG_CONTEXT_AUX4_FLAG_SHIFT
value|7
name|uint8_t
name|__state
comment|/* The state of the connection */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint8_t
name|__state
comment|/* The state of the connection */
decl_stmt|;
name|uint8_t
name|agg_vars1
decl_stmt|;
define|#
directive|define
name|TSTORM_TOE_AG_CONTEXT_EXISTS_IN_QM0
value|(0x1<<0)
comment|/* BitField agg_vars1Various aggregative variables	The connection is currently registered to the QM with queue index 0 */
define|#
directive|define
name|TSTORM_TOE_AG_CONTEXT_EXISTS_IN_QM0_SHIFT
value|0
define|#
directive|define
name|TSTORM_TOE_AG_CONTEXT_RESERVED51
value|(0x1<<1)
comment|/* BitField agg_vars1Various aggregative variables	The connection is currently registered to the QM with queue index 1 */
define|#
directive|define
name|TSTORM_TOE_AG_CONTEXT_RESERVED51_SHIFT
value|1
define|#
directive|define
name|TSTORM_TOE_AG_CONTEXT_RESERVED52
value|(0x1<<2)
comment|/* BitField agg_vars1Various aggregative variables	The connection is currently registered to the QM with queue index 2 */
define|#
directive|define
name|TSTORM_TOE_AG_CONTEXT_RESERVED52_SHIFT
value|2
define|#
directive|define
name|TSTORM_TOE_AG_CONTEXT_RESERVED53
value|(0x1<<3)
comment|/* BitField agg_vars1Various aggregative variables	The connection is currently registered to the QM with queue index 3 */
define|#
directive|define
name|TSTORM_TOE_AG_CONTEXT_RESERVED53_SHIFT
value|3
define|#
directive|define
name|__TSTORM_TOE_AG_CONTEXT_QUEUES_FLUSH_Q0_CF
value|(0x3<<4)
comment|/* BitField agg_vars1Various aggregative variables	 */
define|#
directive|define
name|__TSTORM_TOE_AG_CONTEXT_QUEUES_FLUSH_Q0_CF_SHIFT
value|4
define|#
directive|define
name|__TSTORM_TOE_AG_CONTEXT_AUX3_FLAG
value|(0x1<<6)
comment|/* BitField agg_vars1Various aggregative variables	 */
define|#
directive|define
name|__TSTORM_TOE_AG_CONTEXT_AUX3_FLAG_SHIFT
value|6
define|#
directive|define
name|__TSTORM_TOE_AG_CONTEXT_AUX4_FLAG
value|(0x1<<7)
comment|/* BitField agg_vars1Various aggregative variables	 */
define|#
directive|define
name|__TSTORM_TOE_AG_CONTEXT_AUX4_FLAG_SHIFT
value|7
name|uint16_t
name|reserved54
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|__agg_val4
decl_stmt|;
name|uint16_t
name|agg_vars2
decl_stmt|;
define|#
directive|define
name|__TSTORM_TOE_AG_CONTEXT_AUX5_FLAG
value|(0x1<<0)
comment|/* BitField agg_vars2Various aggregative variables	 */
define|#
directive|define
name|__TSTORM_TOE_AG_CONTEXT_AUX5_FLAG_SHIFT
value|0
define|#
directive|define
name|__TSTORM_TOE_AG_CONTEXT_AUX6_FLAG
value|(0x1<<1)
comment|/* BitField agg_vars2Various aggregative variables	 */
define|#
directive|define
name|__TSTORM_TOE_AG_CONTEXT_AUX6_FLAG_SHIFT
value|1
define|#
directive|define
name|__TSTORM_TOE_AG_CONTEXT_AUX4_CF
value|(0x3<<2)
comment|/* BitField agg_vars2Various aggregative variables	 */
define|#
directive|define
name|__TSTORM_TOE_AG_CONTEXT_AUX4_CF_SHIFT
value|2
define|#
directive|define
name|__TSTORM_TOE_AG_CONTEXT_AUX5_CF
value|(0x3<<4)
comment|/* BitField agg_vars2Various aggregative variables	 */
define|#
directive|define
name|__TSTORM_TOE_AG_CONTEXT_AUX5_CF_SHIFT
value|4
define|#
directive|define
name|__TSTORM_TOE_AG_CONTEXT_AUX6_CF
value|(0x3<<6)
comment|/* BitField agg_vars2Various aggregative variables	 */
define|#
directive|define
name|__TSTORM_TOE_AG_CONTEXT_AUX6_CF_SHIFT
value|6
define|#
directive|define
name|__TSTORM_TOE_AG_CONTEXT_AUX7_CF
value|(0x3<<8)
comment|/* BitField agg_vars2Various aggregative variables	 */
define|#
directive|define
name|__TSTORM_TOE_AG_CONTEXT_AUX7_CF_SHIFT
value|8
define|#
directive|define
name|__TSTORM_TOE_AG_CONTEXT_AUX7_FLAG
value|(0x1<<10)
comment|/* BitField agg_vars2Various aggregative variables	 */
define|#
directive|define
name|__TSTORM_TOE_AG_CONTEXT_AUX7_FLAG_SHIFT
value|10
define|#
directive|define
name|__TSTORM_TOE_AG_CONTEXT_QUEUES_FLUSH_Q0_CF_EN
value|(0x1<<11)
comment|/* BitField agg_vars2Various aggregative variables	 */
define|#
directive|define
name|__TSTORM_TOE_AG_CONTEXT_QUEUES_FLUSH_Q0_CF_EN_SHIFT
value|11
define|#
directive|define
name|TSTORM_TOE_AG_CONTEXT_RESERVED_AUX4_CF_EN
value|(0x1<<12)
comment|/* BitField agg_vars2Various aggregative variables	 */
define|#
directive|define
name|TSTORM_TOE_AG_CONTEXT_RESERVED_AUX4_CF_EN_SHIFT
value|12
define|#
directive|define
name|TSTORM_TOE_AG_CONTEXT_RESERVED_AUX5_CF_EN
value|(0x1<<13)
comment|/* BitField agg_vars2Various aggregative variables	 */
define|#
directive|define
name|TSTORM_TOE_AG_CONTEXT_RESERVED_AUX5_CF_EN_SHIFT
value|13
define|#
directive|define
name|TSTORM_TOE_AG_CONTEXT_RESERVED_AUX6_CF_EN
value|(0x1<<14)
comment|/* BitField agg_vars2Various aggregative variables	 */
define|#
directive|define
name|TSTORM_TOE_AG_CONTEXT_RESERVED_AUX6_CF_EN_SHIFT
value|14
define|#
directive|define
name|TSTORM_TOE_AG_CONTEXT_RESERVED_AUX7_CF_EN
value|(0x1<<15)
comment|/* BitField agg_vars2Various aggregative variables	 */
define|#
directive|define
name|TSTORM_TOE_AG_CONTEXT_RESERVED_AUX7_CF_EN_SHIFT
value|15
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|agg_vars2
decl_stmt|;
define|#
directive|define
name|__TSTORM_TOE_AG_CONTEXT_AUX5_FLAG
value|(0x1<<0)
comment|/* BitField agg_vars2Various aggregative variables	 */
define|#
directive|define
name|__TSTORM_TOE_AG_CONTEXT_AUX5_FLAG_SHIFT
value|0
define|#
directive|define
name|__TSTORM_TOE_AG_CONTEXT_AUX6_FLAG
value|(0x1<<1)
comment|/* BitField agg_vars2Various aggregative variables	 */
define|#
directive|define
name|__TSTORM_TOE_AG_CONTEXT_AUX6_FLAG_SHIFT
value|1
define|#
directive|define
name|__TSTORM_TOE_AG_CONTEXT_AUX4_CF
value|(0x3<<2)
comment|/* BitField agg_vars2Various aggregative variables	 */
define|#
directive|define
name|__TSTORM_TOE_AG_CONTEXT_AUX4_CF_SHIFT
value|2
define|#
directive|define
name|__TSTORM_TOE_AG_CONTEXT_AUX5_CF
value|(0x3<<4)
comment|/* BitField agg_vars2Various aggregative variables	 */
define|#
directive|define
name|__TSTORM_TOE_AG_CONTEXT_AUX5_CF_SHIFT
value|4
define|#
directive|define
name|__TSTORM_TOE_AG_CONTEXT_AUX6_CF
value|(0x3<<6)
comment|/* BitField agg_vars2Various aggregative variables	 */
define|#
directive|define
name|__TSTORM_TOE_AG_CONTEXT_AUX6_CF_SHIFT
value|6
define|#
directive|define
name|__TSTORM_TOE_AG_CONTEXT_AUX7_CF
value|(0x3<<8)
comment|/* BitField agg_vars2Various aggregative variables	 */
define|#
directive|define
name|__TSTORM_TOE_AG_CONTEXT_AUX7_CF_SHIFT
value|8
define|#
directive|define
name|__TSTORM_TOE_AG_CONTEXT_AUX7_FLAG
value|(0x1<<10)
comment|/* BitField agg_vars2Various aggregative variables	 */
define|#
directive|define
name|__TSTORM_TOE_AG_CONTEXT_AUX7_FLAG_SHIFT
value|10
define|#
directive|define
name|__TSTORM_TOE_AG_CONTEXT_QUEUES_FLUSH_Q0_CF_EN
value|(0x1<<11)
comment|/* BitField agg_vars2Various aggregative variables	 */
define|#
directive|define
name|__TSTORM_TOE_AG_CONTEXT_QUEUES_FLUSH_Q0_CF_EN_SHIFT
value|11
define|#
directive|define
name|TSTORM_TOE_AG_CONTEXT_RESERVED_AUX4_CF_EN
value|(0x1<<12)
comment|/* BitField agg_vars2Various aggregative variables	 */
define|#
directive|define
name|TSTORM_TOE_AG_CONTEXT_RESERVED_AUX4_CF_EN_SHIFT
value|12
define|#
directive|define
name|TSTORM_TOE_AG_CONTEXT_RESERVED_AUX5_CF_EN
value|(0x1<<13)
comment|/* BitField agg_vars2Various aggregative variables	 */
define|#
directive|define
name|TSTORM_TOE_AG_CONTEXT_RESERVED_AUX5_CF_EN_SHIFT
value|13
define|#
directive|define
name|TSTORM_TOE_AG_CONTEXT_RESERVED_AUX6_CF_EN
value|(0x1<<14)
comment|/* BitField agg_vars2Various aggregative variables	 */
define|#
directive|define
name|TSTORM_TOE_AG_CONTEXT_RESERVED_AUX6_CF_EN_SHIFT
value|14
define|#
directive|define
name|TSTORM_TOE_AG_CONTEXT_RESERVED_AUX7_CF_EN
value|(0x1<<15)
comment|/* BitField agg_vars2Various aggregative variables	 */
define|#
directive|define
name|TSTORM_TOE_AG_CONTEXT_RESERVED_AUX7_CF_EN_SHIFT
value|15
name|uint16_t
name|__agg_val4
decl_stmt|;
endif|#
directive|endif
name|struct
name|tstorm_toe_tcp_ag_context_section
name|tcp
comment|/* TCP context section, shared in TOE and iSCSI */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The eth aggregative context of Ustorm  */
end_comment

begin_struct
struct|struct
name|ustorm_eth_ag_context
block|{
name|uint32_t
name|__reserved0
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint8_t
name|cdu_usage
comment|/* Will be used by the CDU for validation of the CID/connection type on doorbells. */
decl_stmt|;
name|uint8_t
name|__reserved2
decl_stmt|;
name|uint16_t
name|__reserved1
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|__reserved1
decl_stmt|;
name|uint8_t
name|__reserved2
decl_stmt|;
name|uint8_t
name|cdu_usage
comment|/* Will be used by the CDU for validation of the CID/connection type on doorbells. */
decl_stmt|;
endif|#
directive|endif
name|uint32_t
name|__reserved3
index|[
literal|6
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The fcoe aggregative context of Ustorm  */
end_comment

begin_struct
struct|struct
name|ustorm_fcoe_ag_context
block|{
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint8_t
name|__aux_counter_flags
comment|/* auxiliary counter flags*/
decl_stmt|;
name|uint8_t
name|agg_vars2
decl_stmt|;
define|#
directive|define
name|USTORM_FCOE_AG_CONTEXT_TX_CF
value|(0x3<<0)
comment|/* BitField agg_vars2various aggregation variables	Set when a message was received from the Tx STORM. For future use. */
define|#
directive|define
name|USTORM_FCOE_AG_CONTEXT_TX_CF_SHIFT
value|0
define|#
directive|define
name|__USTORM_FCOE_AG_CONTEXT_TIMER_CF
value|(0x3<<2)
comment|/* BitField agg_vars2various aggregation variables	Set when a message was received from the Timer. */
define|#
directive|define
name|__USTORM_FCOE_AG_CONTEXT_TIMER_CF_SHIFT
value|2
define|#
directive|define
name|USTORM_FCOE_AG_CONTEXT_AGG_MISC4_RULE
value|(0x7<<4)
comment|/* BitField agg_vars2various aggregation variables	0-NOP,1-EQ,2-NEQ,3-GT_CYC,4-GT_ABS,5-LT_CYC,6-LT_ABS */
define|#
directive|define
name|USTORM_FCOE_AG_CONTEXT_AGG_MISC4_RULE_SHIFT
value|4
define|#
directive|define
name|__USTORM_FCOE_AG_CONTEXT_AGG_VAL2_MASK
value|(0x1<<7)
comment|/* BitField agg_vars2various aggregation variables	Used to mask the decision rule of AggVal2. Used in iSCSI. Should be 0 in all other protocols */
define|#
directive|define
name|__USTORM_FCOE_AG_CONTEXT_AGG_VAL2_MASK_SHIFT
value|7
name|uint8_t
name|agg_vars1
decl_stmt|;
define|#
directive|define
name|__USTORM_FCOE_AG_CONTEXT_EXISTS_IN_QM0
value|(0x1<<0)
comment|/* BitField agg_vars1various aggregation variables	The connection is currently registered to the QM with queue index 0 */
define|#
directive|define
name|__USTORM_FCOE_AG_CONTEXT_EXISTS_IN_QM0_SHIFT
value|0
define|#
directive|define
name|USTORM_FCOE_AG_CONTEXT_EXISTS_IN_QM1
value|(0x1<<1)
comment|/* BitField agg_vars1various aggregation variables	The connection is currently registered to the QM with queue index 1 */
define|#
directive|define
name|USTORM_FCOE_AG_CONTEXT_EXISTS_IN_QM1_SHIFT
value|1
define|#
directive|define
name|USTORM_FCOE_AG_CONTEXT_EXISTS_IN_QM2
value|(0x1<<2)
comment|/* BitField agg_vars1various aggregation variables	The connection is currently registered to the QM with queue index 2 */
define|#
directive|define
name|USTORM_FCOE_AG_CONTEXT_EXISTS_IN_QM2_SHIFT
value|2
define|#
directive|define
name|USTORM_FCOE_AG_CONTEXT_EXISTS_IN_QM3
value|(0x1<<3)
comment|/* BitField agg_vars1various aggregation variables	The connection is currently registered to the QM with queue index 3 */
define|#
directive|define
name|USTORM_FCOE_AG_CONTEXT_EXISTS_IN_QM3_SHIFT
value|3
define|#
directive|define
name|USTORM_FCOE_AG_CONTEXT_INV_CF
value|(0x3<<4)
comment|/* BitField agg_vars1various aggregation variables	Indicates a valid invalidate request. Set by the CMP STORM. */
define|#
directive|define
name|USTORM_FCOE_AG_CONTEXT_INV_CF_SHIFT
value|4
define|#
directive|define
name|USTORM_FCOE_AG_CONTEXT_COMPLETION_CF
value|(0x3<<6)
comment|/* BitField agg_vars1various aggregation variables	Set when a message was received from the CMP STORM. For future use. */
define|#
directive|define
name|USTORM_FCOE_AG_CONTEXT_COMPLETION_CF_SHIFT
value|6
name|uint8_t
name|state
comment|/* The state of the connection */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint8_t
name|state
comment|/* The state of the connection */
decl_stmt|;
name|uint8_t
name|agg_vars1
decl_stmt|;
define|#
directive|define
name|__USTORM_FCOE_AG_CONTEXT_EXISTS_IN_QM0
value|(0x1<<0)
comment|/* BitField agg_vars1various aggregation variables	The connection is currently registered to the QM with queue index 0 */
define|#
directive|define
name|__USTORM_FCOE_AG_CONTEXT_EXISTS_IN_QM0_SHIFT
value|0
define|#
directive|define
name|USTORM_FCOE_AG_CONTEXT_EXISTS_IN_QM1
value|(0x1<<1)
comment|/* BitField agg_vars1various aggregation variables	The connection is currently registered to the QM with queue index 1 */
define|#
directive|define
name|USTORM_FCOE_AG_CONTEXT_EXISTS_IN_QM1_SHIFT
value|1
define|#
directive|define
name|USTORM_FCOE_AG_CONTEXT_EXISTS_IN_QM2
value|(0x1<<2)
comment|/* BitField agg_vars1various aggregation variables	The connection is currently registered to the QM with queue index 2 */
define|#
directive|define
name|USTORM_FCOE_AG_CONTEXT_EXISTS_IN_QM2_SHIFT
value|2
define|#
directive|define
name|USTORM_FCOE_AG_CONTEXT_EXISTS_IN_QM3
value|(0x1<<3)
comment|/* BitField agg_vars1various aggregation variables	The connection is currently registered to the QM with queue index 3 */
define|#
directive|define
name|USTORM_FCOE_AG_CONTEXT_EXISTS_IN_QM3_SHIFT
value|3
define|#
directive|define
name|USTORM_FCOE_AG_CONTEXT_INV_CF
value|(0x3<<4)
comment|/* BitField agg_vars1various aggregation variables	Indicates a valid invalidate request. Set by the CMP STORM. */
define|#
directive|define
name|USTORM_FCOE_AG_CONTEXT_INV_CF_SHIFT
value|4
define|#
directive|define
name|USTORM_FCOE_AG_CONTEXT_COMPLETION_CF
value|(0x3<<6)
comment|/* BitField agg_vars1various aggregation variables	Set when a message was received from the CMP STORM. For future use. */
define|#
directive|define
name|USTORM_FCOE_AG_CONTEXT_COMPLETION_CF_SHIFT
value|6
name|uint8_t
name|agg_vars2
decl_stmt|;
define|#
directive|define
name|USTORM_FCOE_AG_CONTEXT_TX_CF
value|(0x3<<0)
comment|/* BitField agg_vars2various aggregation variables	Set when a message was received from the Tx STORM. For future use. */
define|#
directive|define
name|USTORM_FCOE_AG_CONTEXT_TX_CF_SHIFT
value|0
define|#
directive|define
name|__USTORM_FCOE_AG_CONTEXT_TIMER_CF
value|(0x3<<2)
comment|/* BitField agg_vars2various aggregation variables	Set when a message was received from the Timer. */
define|#
directive|define
name|__USTORM_FCOE_AG_CONTEXT_TIMER_CF_SHIFT
value|2
define|#
directive|define
name|USTORM_FCOE_AG_CONTEXT_AGG_MISC4_RULE
value|(0x7<<4)
comment|/* BitField agg_vars2various aggregation variables	0-NOP,1-EQ,2-NEQ,3-GT_CYC,4-GT_ABS,5-LT_CYC,6-LT_ABS */
define|#
directive|define
name|USTORM_FCOE_AG_CONTEXT_AGG_MISC4_RULE_SHIFT
value|4
define|#
directive|define
name|__USTORM_FCOE_AG_CONTEXT_AGG_VAL2_MASK
value|(0x1<<7)
comment|/* BitField agg_vars2various aggregation variables	Used to mask the decision rule of AggVal2. Used in iSCSI. Should be 0 in all other protocols */
define|#
directive|define
name|__USTORM_FCOE_AG_CONTEXT_AGG_VAL2_MASK_SHIFT
value|7
name|uint8_t
name|__aux_counter_flags
comment|/* auxiliary counter flags*/
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint8_t
name|cdu_usage
comment|/* Will be used by the CDU for validation of the CID/connection type on doorbells. */
decl_stmt|;
name|uint8_t
name|agg_misc2
decl_stmt|;
name|uint16_t
name|pbf_tx_seq_ack
comment|/* Sequence number of the last sequence transmitted by PBF. */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|pbf_tx_seq_ack
comment|/* Sequence number of the last sequence transmitted by PBF. */
decl_stmt|;
name|uint8_t
name|agg_misc2
decl_stmt|;
name|uint8_t
name|cdu_usage
comment|/* Will be used by the CDU for validation of the CID/connection type on doorbells. */
decl_stmt|;
endif|#
directive|endif
name|uint32_t
name|agg_misc4
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint8_t
name|agg_val3_th
decl_stmt|;
name|uint8_t
name|agg_val3
decl_stmt|;
name|uint16_t
name|agg_misc3
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|agg_misc3
decl_stmt|;
name|uint8_t
name|agg_val3
decl_stmt|;
name|uint8_t
name|agg_val3_th
decl_stmt|;
endif|#
directive|endif
name|uint32_t
name|expired_task_id
comment|/* Timer expiration task id */
decl_stmt|;
name|uint32_t
name|agg_misc4_th
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|cq_prod
comment|/* CQ producer updated by FW */
decl_stmt|;
name|uint16_t
name|cq_cons
comment|/* CQ consumer updated by driver via doorbell */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|cq_cons
comment|/* CQ consumer updated by driver via doorbell */
decl_stmt|;
name|uint16_t
name|cq_prod
comment|/* CQ producer updated by FW */
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|__reserved2
decl_stmt|;
name|uint8_t
name|decision_rules
decl_stmt|;
define|#
directive|define
name|USTORM_FCOE_AG_CONTEXT_CQ_DEC_RULE
value|(0x7<<0)
comment|/* BitField decision_rulesVarious decision rules	 */
define|#
directive|define
name|USTORM_FCOE_AG_CONTEXT_CQ_DEC_RULE_SHIFT
value|0
define|#
directive|define
name|__USTORM_FCOE_AG_CONTEXT_AGG_VAL3_RULE
value|(0x7<<3)
comment|/* BitField decision_rulesVarious decision rules	 */
define|#
directive|define
name|__USTORM_FCOE_AG_CONTEXT_AGG_VAL3_RULE_SHIFT
value|3
define|#
directive|define
name|USTORM_FCOE_AG_CONTEXT_CQ_ARM_N_FLAG
value|(0x1<<6)
comment|/* BitField decision_rulesVarious decision rules	CQ negative arm indication updated via doorbell */
define|#
directive|define
name|USTORM_FCOE_AG_CONTEXT_CQ_ARM_N_FLAG_SHIFT
value|6
define|#
directive|define
name|__USTORM_FCOE_AG_CONTEXT_RESERVED1
value|(0x1<<7)
comment|/* BitField decision_rulesVarious decision rules	 */
define|#
directive|define
name|__USTORM_FCOE_AG_CONTEXT_RESERVED1_SHIFT
value|7
name|uint8_t
name|decision_rule_enable_bits
decl_stmt|;
define|#
directive|define
name|__USTORM_FCOE_AG_CONTEXT_RESERVED_INV_CF_EN
value|(0x1<<0)
comment|/* BitField decision_rule_enable_bitsEnable bits for various decision rules	 */
define|#
directive|define
name|__USTORM_FCOE_AG_CONTEXT_RESERVED_INV_CF_EN_SHIFT
value|0
define|#
directive|define
name|USTORM_FCOE_AG_CONTEXT_COMPLETION_CF_EN
value|(0x1<<1)
comment|/* BitField decision_rule_enable_bitsEnable bits for various decision rules	 */
define|#
directive|define
name|USTORM_FCOE_AG_CONTEXT_COMPLETION_CF_EN_SHIFT
value|1
define|#
directive|define
name|USTORM_FCOE_AG_CONTEXT_TX_CF_EN
value|(0x1<<2)
comment|/* BitField decision_rule_enable_bitsEnable bits for various decision rules	 */
define|#
directive|define
name|USTORM_FCOE_AG_CONTEXT_TX_CF_EN_SHIFT
value|2
define|#
directive|define
name|__USTORM_FCOE_AG_CONTEXT_TIMER_CF_EN
value|(0x1<<3)
comment|/* BitField decision_rule_enable_bitsEnable bits for various decision rules	 */
define|#
directive|define
name|__USTORM_FCOE_AG_CONTEXT_TIMER_CF_EN_SHIFT
value|3
define|#
directive|define
name|__USTORM_FCOE_AG_CONTEXT_AUX1_CF_EN
value|(0x1<<4)
comment|/* BitField decision_rule_enable_bitsEnable bits for various decision rules	 */
define|#
directive|define
name|__USTORM_FCOE_AG_CONTEXT_AUX1_CF_EN_SHIFT
value|4
define|#
directive|define
name|__USTORM_FCOE_AG_CONTEXT_QUEUE0_CF_EN
value|(0x1<<5)
comment|/* BitField decision_rule_enable_bitsEnable bits for various decision rules	The flush queues counter flag en.  */
define|#
directive|define
name|__USTORM_FCOE_AG_CONTEXT_QUEUE0_CF_EN_SHIFT
value|5
define|#
directive|define
name|__USTORM_FCOE_AG_CONTEXT_AUX3_CF_EN
value|(0x1<<6)
comment|/* BitField decision_rule_enable_bitsEnable bits for various decision rules	 */
define|#
directive|define
name|__USTORM_FCOE_AG_CONTEXT_AUX3_CF_EN_SHIFT
value|6
define|#
directive|define
name|__USTORM_FCOE_AG_CONTEXT_DQ_CF_EN
value|(0x1<<7)
comment|/* BitField decision_rule_enable_bitsEnable bits for various decision rules	 */
define|#
directive|define
name|__USTORM_FCOE_AG_CONTEXT_DQ_CF_EN_SHIFT
value|7
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint8_t
name|decision_rule_enable_bits
decl_stmt|;
define|#
directive|define
name|__USTORM_FCOE_AG_CONTEXT_RESERVED_INV_CF_EN
value|(0x1<<0)
comment|/* BitField decision_rule_enable_bitsEnable bits for various decision rules	 */
define|#
directive|define
name|__USTORM_FCOE_AG_CONTEXT_RESERVED_INV_CF_EN_SHIFT
value|0
define|#
directive|define
name|USTORM_FCOE_AG_CONTEXT_COMPLETION_CF_EN
value|(0x1<<1)
comment|/* BitField decision_rule_enable_bitsEnable bits for various decision rules	 */
define|#
directive|define
name|USTORM_FCOE_AG_CONTEXT_COMPLETION_CF_EN_SHIFT
value|1
define|#
directive|define
name|USTORM_FCOE_AG_CONTEXT_TX_CF_EN
value|(0x1<<2)
comment|/* BitField decision_rule_enable_bitsEnable bits for various decision rules	 */
define|#
directive|define
name|USTORM_FCOE_AG_CONTEXT_TX_CF_EN_SHIFT
value|2
define|#
directive|define
name|__USTORM_FCOE_AG_CONTEXT_TIMER_CF_EN
value|(0x1<<3)
comment|/* BitField decision_rule_enable_bitsEnable bits for various decision rules	 */
define|#
directive|define
name|__USTORM_FCOE_AG_CONTEXT_TIMER_CF_EN_SHIFT
value|3
define|#
directive|define
name|__USTORM_FCOE_AG_CONTEXT_AUX1_CF_EN
value|(0x1<<4)
comment|/* BitField decision_rule_enable_bitsEnable bits for various decision rules	 */
define|#
directive|define
name|__USTORM_FCOE_AG_CONTEXT_AUX1_CF_EN_SHIFT
value|4
define|#
directive|define
name|__USTORM_FCOE_AG_CONTEXT_QUEUE0_CF_EN
value|(0x1<<5)
comment|/* BitField decision_rule_enable_bitsEnable bits for various decision rules	The flush queues counter flag en.  */
define|#
directive|define
name|__USTORM_FCOE_AG_CONTEXT_QUEUE0_CF_EN_SHIFT
value|5
define|#
directive|define
name|__USTORM_FCOE_AG_CONTEXT_AUX3_CF_EN
value|(0x1<<6)
comment|/* BitField decision_rule_enable_bitsEnable bits for various decision rules	 */
define|#
directive|define
name|__USTORM_FCOE_AG_CONTEXT_AUX3_CF_EN_SHIFT
value|6
define|#
directive|define
name|__USTORM_FCOE_AG_CONTEXT_DQ_CF_EN
value|(0x1<<7)
comment|/* BitField decision_rule_enable_bitsEnable bits for various decision rules	 */
define|#
directive|define
name|__USTORM_FCOE_AG_CONTEXT_DQ_CF_EN_SHIFT
value|7
name|uint8_t
name|decision_rules
decl_stmt|;
define|#
directive|define
name|USTORM_FCOE_AG_CONTEXT_CQ_DEC_RULE
value|(0x7<<0)
comment|/* BitField decision_rulesVarious decision rules	 */
define|#
directive|define
name|USTORM_FCOE_AG_CONTEXT_CQ_DEC_RULE_SHIFT
value|0
define|#
directive|define
name|__USTORM_FCOE_AG_CONTEXT_AGG_VAL3_RULE
value|(0x7<<3)
comment|/* BitField decision_rulesVarious decision rules	 */
define|#
directive|define
name|__USTORM_FCOE_AG_CONTEXT_AGG_VAL3_RULE_SHIFT
value|3
define|#
directive|define
name|USTORM_FCOE_AG_CONTEXT_CQ_ARM_N_FLAG
value|(0x1<<6)
comment|/* BitField decision_rulesVarious decision rules	CQ negative arm indication updated via doorbell */
define|#
directive|define
name|USTORM_FCOE_AG_CONTEXT_CQ_ARM_N_FLAG_SHIFT
value|6
define|#
directive|define
name|__USTORM_FCOE_AG_CONTEXT_RESERVED1
value|(0x1<<7)
comment|/* BitField decision_rulesVarious decision rules	 */
define|#
directive|define
name|__USTORM_FCOE_AG_CONTEXT_RESERVED1_SHIFT
value|7
name|uint16_t
name|__reserved2
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/*  * The iscsi aggregative context of Ustorm  */
end_comment

begin_struct
struct|struct
name|ustorm_iscsi_ag_context
block|{
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint8_t
name|__aux_counter_flags
comment|/* auxiliary counter flags*/
decl_stmt|;
name|uint8_t
name|agg_vars2
decl_stmt|;
define|#
directive|define
name|USTORM_ISCSI_AG_CONTEXT_TX_CF
value|(0x3<<0)
comment|/* BitField agg_vars2various aggregation variables	Set when a message was received from the Tx STORM. For future use. */
define|#
directive|define
name|USTORM_ISCSI_AG_CONTEXT_TX_CF_SHIFT
value|0
define|#
directive|define
name|__USTORM_ISCSI_AG_CONTEXT_TIMER_CF
value|(0x3<<2)
comment|/* BitField agg_vars2various aggregation variables	Set when a message was received from the Timer. */
define|#
directive|define
name|__USTORM_ISCSI_AG_CONTEXT_TIMER_CF_SHIFT
value|2
define|#
directive|define
name|USTORM_ISCSI_AG_CONTEXT_AGG_MISC4_RULE
value|(0x7<<4)
comment|/* BitField agg_vars2various aggregation variables	0-NOP,1-EQ,2-NEQ,3-GT_CYC,4-GT_ABS,5-LT_CYC,6-LT_ABS */
define|#
directive|define
name|USTORM_ISCSI_AG_CONTEXT_AGG_MISC4_RULE_SHIFT
value|4
define|#
directive|define
name|__USTORM_ISCSI_AG_CONTEXT_AGG_VAL2_MASK
value|(0x1<<7)
comment|/* BitField agg_vars2various aggregation variables	Used to mask the decision rule of AggVal2. Used in iSCSI. Should be 0 in all other protocols */
define|#
directive|define
name|__USTORM_ISCSI_AG_CONTEXT_AGG_VAL2_MASK_SHIFT
value|7
name|uint8_t
name|agg_vars1
decl_stmt|;
define|#
directive|define
name|__USTORM_ISCSI_AG_CONTEXT_EXISTS_IN_QM0
value|(0x1<<0)
comment|/* BitField agg_vars1various aggregation variables	The connection is currently registered to the QM with queue index 0 */
define|#
directive|define
name|__USTORM_ISCSI_AG_CONTEXT_EXISTS_IN_QM0_SHIFT
value|0
define|#
directive|define
name|USTORM_ISCSI_AG_CONTEXT_EXISTS_IN_QM1
value|(0x1<<1)
comment|/* BitField agg_vars1various aggregation variables	The connection is currently registered to the QM with queue index 1 */
define|#
directive|define
name|USTORM_ISCSI_AG_CONTEXT_EXISTS_IN_QM1_SHIFT
value|1
define|#
directive|define
name|USTORM_ISCSI_AG_CONTEXT_EXISTS_IN_QM2
value|(0x1<<2)
comment|/* BitField agg_vars1various aggregation variables	The connection is currently registered to the QM with queue index 2 */
define|#
directive|define
name|USTORM_ISCSI_AG_CONTEXT_EXISTS_IN_QM2_SHIFT
value|2
define|#
directive|define
name|USTORM_ISCSI_AG_CONTEXT_EXISTS_IN_QM3
value|(0x1<<3)
comment|/* BitField agg_vars1various aggregation variables	The connection is currently registered to the QM with queue index 3 */
define|#
directive|define
name|USTORM_ISCSI_AG_CONTEXT_EXISTS_IN_QM3_SHIFT
value|3
define|#
directive|define
name|USTORM_ISCSI_AG_CONTEXT_INV_CF
value|(0x3<<4)
comment|/* BitField agg_vars1various aggregation variables	Indicates a valid invalidate request. Set by the CMP STORM. */
define|#
directive|define
name|USTORM_ISCSI_AG_CONTEXT_INV_CF_SHIFT
value|4
define|#
directive|define
name|USTORM_ISCSI_AG_CONTEXT_COMPLETION_CF
value|(0x3<<6)
comment|/* BitField agg_vars1various aggregation variables	Set when a message was received from the CMP STORM. For future use. */
define|#
directive|define
name|USTORM_ISCSI_AG_CONTEXT_COMPLETION_CF_SHIFT
value|6
name|uint8_t
name|state
comment|/* The state of the connection */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint8_t
name|state
comment|/* The state of the connection */
decl_stmt|;
name|uint8_t
name|agg_vars1
decl_stmt|;
define|#
directive|define
name|__USTORM_ISCSI_AG_CONTEXT_EXISTS_IN_QM0
value|(0x1<<0)
comment|/* BitField agg_vars1various aggregation variables	The connection is currently registered to the QM with queue index 0 */
define|#
directive|define
name|__USTORM_ISCSI_AG_CONTEXT_EXISTS_IN_QM0_SHIFT
value|0
define|#
directive|define
name|USTORM_ISCSI_AG_CONTEXT_EXISTS_IN_QM1
value|(0x1<<1)
comment|/* BitField agg_vars1various aggregation variables	The connection is currently registered to the QM with queue index 1 */
define|#
directive|define
name|USTORM_ISCSI_AG_CONTEXT_EXISTS_IN_QM1_SHIFT
value|1
define|#
directive|define
name|USTORM_ISCSI_AG_CONTEXT_EXISTS_IN_QM2
value|(0x1<<2)
comment|/* BitField agg_vars1various aggregation variables	The connection is currently registered to the QM with queue index 2 */
define|#
directive|define
name|USTORM_ISCSI_AG_CONTEXT_EXISTS_IN_QM2_SHIFT
value|2
define|#
directive|define
name|USTORM_ISCSI_AG_CONTEXT_EXISTS_IN_QM3
value|(0x1<<3)
comment|/* BitField agg_vars1various aggregation variables	The connection is currently registered to the QM with queue index 3 */
define|#
directive|define
name|USTORM_ISCSI_AG_CONTEXT_EXISTS_IN_QM3_SHIFT
value|3
define|#
directive|define
name|USTORM_ISCSI_AG_CONTEXT_INV_CF
value|(0x3<<4)
comment|/* BitField agg_vars1various aggregation variables	Indicates a valid invalidate request. Set by the CMP STORM. */
define|#
directive|define
name|USTORM_ISCSI_AG_CONTEXT_INV_CF_SHIFT
value|4
define|#
directive|define
name|USTORM_ISCSI_AG_CONTEXT_COMPLETION_CF
value|(0x3<<6)
comment|/* BitField agg_vars1various aggregation variables	Set when a message was received from the CMP STORM. For future use. */
define|#
directive|define
name|USTORM_ISCSI_AG_CONTEXT_COMPLETION_CF_SHIFT
value|6
name|uint8_t
name|agg_vars2
decl_stmt|;
define|#
directive|define
name|USTORM_ISCSI_AG_CONTEXT_TX_CF
value|(0x3<<0)
comment|/* BitField agg_vars2various aggregation variables	Set when a message was received from the Tx STORM. For future use. */
define|#
directive|define
name|USTORM_ISCSI_AG_CONTEXT_TX_CF_SHIFT
value|0
define|#
directive|define
name|__USTORM_ISCSI_AG_CONTEXT_TIMER_CF
value|(0x3<<2)
comment|/* BitField agg_vars2various aggregation variables	Set when a message was received from the Timer. */
define|#
directive|define
name|__USTORM_ISCSI_AG_CONTEXT_TIMER_CF_SHIFT
value|2
define|#
directive|define
name|USTORM_ISCSI_AG_CONTEXT_AGG_MISC4_RULE
value|(0x7<<4)
comment|/* BitField agg_vars2various aggregation variables	0-NOP,1-EQ,2-NEQ,3-GT_CYC,4-GT_ABS,5-LT_CYC,6-LT_ABS */
define|#
directive|define
name|USTORM_ISCSI_AG_CONTEXT_AGG_MISC4_RULE_SHIFT
value|4
define|#
directive|define
name|__USTORM_ISCSI_AG_CONTEXT_AGG_VAL2_MASK
value|(0x1<<7)
comment|/* BitField agg_vars2various aggregation variables	Used to mask the decision rule of AggVal2. Used in iSCSI. Should be 0 in all other protocols */
define|#
directive|define
name|__USTORM_ISCSI_AG_CONTEXT_AGG_VAL2_MASK_SHIFT
value|7
name|uint8_t
name|__aux_counter_flags
comment|/* auxiliary counter flags*/
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint8_t
name|cdu_usage
comment|/* Will be used by the CDU for validation of the CID/connection type on doorbells. */
decl_stmt|;
name|uint8_t
name|agg_misc2
decl_stmt|;
name|uint16_t
name|__cq_local_comp_itt_val
comment|/* The local completion ITT to complete. Set by the CMP STORM RO for USTORM. */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|__cq_local_comp_itt_val
comment|/* The local completion ITT to complete. Set by the CMP STORM RO for USTORM. */
decl_stmt|;
name|uint8_t
name|agg_misc2
decl_stmt|;
name|uint8_t
name|cdu_usage
comment|/* Will be used by the CDU for validation of the CID/connection type on doorbells. */
decl_stmt|;
endif|#
directive|endif
name|uint32_t
name|agg_misc4
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint8_t
name|agg_val3_th
decl_stmt|;
name|uint8_t
name|agg_val3
decl_stmt|;
name|uint16_t
name|agg_misc3
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|agg_misc3
decl_stmt|;
name|uint8_t
name|agg_val3
decl_stmt|;
name|uint8_t
name|agg_val3_th
decl_stmt|;
endif|#
directive|endif
name|uint32_t
name|agg_val1
decl_stmt|;
name|uint32_t
name|agg_misc4_th
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|agg_val2_th
decl_stmt|;
name|uint16_t
name|agg_val2
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|agg_val2
decl_stmt|;
name|uint16_t
name|agg_val2_th
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|__reserved2
decl_stmt|;
name|uint8_t
name|decision_rules
decl_stmt|;
define|#
directive|define
name|USTORM_ISCSI_AG_CONTEXT_AGG_VAL2_RULE
value|(0x7<<0)
comment|/* BitField decision_rulesVarious decision rules	 */
define|#
directive|define
name|USTORM_ISCSI_AG_CONTEXT_AGG_VAL2_RULE_SHIFT
value|0
define|#
directive|define
name|__USTORM_ISCSI_AG_CONTEXT_AGG_VAL3_RULE
value|(0x7<<3)
comment|/* BitField decision_rulesVarious decision rules	 */
define|#
directive|define
name|__USTORM_ISCSI_AG_CONTEXT_AGG_VAL3_RULE_SHIFT
value|3
define|#
directive|define
name|USTORM_ISCSI_AG_CONTEXT_AGG_VAL2_ARM_N_FLAG
value|(0x1<<6)
comment|/* BitField decision_rulesVarious decision rules	 */
define|#
directive|define
name|USTORM_ISCSI_AG_CONTEXT_AGG_VAL2_ARM_N_FLAG_SHIFT
value|6
define|#
directive|define
name|__USTORM_ISCSI_AG_CONTEXT_RESERVED1
value|(0x1<<7)
comment|/* BitField decision_rulesVarious decision rules	 */
define|#
directive|define
name|__USTORM_ISCSI_AG_CONTEXT_RESERVED1_SHIFT
value|7
name|uint8_t
name|decision_rule_enable_bits
decl_stmt|;
define|#
directive|define
name|USTORM_ISCSI_AG_CONTEXT_INV_CF_EN
value|(0x1<<0)
comment|/* BitField decision_rule_enable_bitsEnable bits for various decision rules	 */
define|#
directive|define
name|USTORM_ISCSI_AG_CONTEXT_INV_CF_EN_SHIFT
value|0
define|#
directive|define
name|USTORM_ISCSI_AG_CONTEXT_COMPLETION_CF_EN
value|(0x1<<1)
comment|/* BitField decision_rule_enable_bitsEnable bits for various decision rules	 */
define|#
directive|define
name|USTORM_ISCSI_AG_CONTEXT_COMPLETION_CF_EN_SHIFT
value|1
define|#
directive|define
name|USTORM_ISCSI_AG_CONTEXT_TX_CF_EN
value|(0x1<<2)
comment|/* BitField decision_rule_enable_bitsEnable bits for various decision rules	 */
define|#
directive|define
name|USTORM_ISCSI_AG_CONTEXT_TX_CF_EN_SHIFT
value|2
define|#
directive|define
name|__USTORM_ISCSI_AG_CONTEXT_TIMER_CF_EN
value|(0x1<<3)
comment|/* BitField decision_rule_enable_bitsEnable bits for various decision rules	 */
define|#
directive|define
name|__USTORM_ISCSI_AG_CONTEXT_TIMER_CF_EN_SHIFT
value|3
define|#
directive|define
name|__USTORM_ISCSI_AG_CONTEXT_CQ_LOCAL_COMP_CF_EN
value|(0x1<<4)
comment|/* BitField decision_rule_enable_bitsEnable bits for various decision rules	The local completion counter flag enable. Enabled by USTORM at the beginning. */
define|#
directive|define
name|__USTORM_ISCSI_AG_CONTEXT_CQ_LOCAL_COMP_CF_EN_SHIFT
value|4
define|#
directive|define
name|__USTORM_ISCSI_AG_CONTEXT_QUEUES_FLUSH_Q0_CF_EN
value|(0x1<<5)
comment|/* BitField decision_rule_enable_bitsEnable bits for various decision rules	The flush queues counter flag en.  */
define|#
directive|define
name|__USTORM_ISCSI_AG_CONTEXT_QUEUES_FLUSH_Q0_CF_EN_SHIFT
value|5
define|#
directive|define
name|__USTORM_ISCSI_AG_CONTEXT_AUX3_CF_EN
value|(0x1<<6)
comment|/* BitField decision_rule_enable_bitsEnable bits for various decision rules	 */
define|#
directive|define
name|__USTORM_ISCSI_AG_CONTEXT_AUX3_CF_EN_SHIFT
value|6
define|#
directive|define
name|__USTORM_ISCSI_AG_CONTEXT_DQ_CF_EN
value|(0x1<<7)
comment|/* BitField decision_rule_enable_bitsEnable bits for various decision rules	 */
define|#
directive|define
name|__USTORM_ISCSI_AG_CONTEXT_DQ_CF_EN_SHIFT
value|7
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint8_t
name|decision_rule_enable_bits
decl_stmt|;
define|#
directive|define
name|USTORM_ISCSI_AG_CONTEXT_INV_CF_EN
value|(0x1<<0)
comment|/* BitField decision_rule_enable_bitsEnable bits for various decision rules	 */
define|#
directive|define
name|USTORM_ISCSI_AG_CONTEXT_INV_CF_EN_SHIFT
value|0
define|#
directive|define
name|USTORM_ISCSI_AG_CONTEXT_COMPLETION_CF_EN
value|(0x1<<1)
comment|/* BitField decision_rule_enable_bitsEnable bits for various decision rules	 */
define|#
directive|define
name|USTORM_ISCSI_AG_CONTEXT_COMPLETION_CF_EN_SHIFT
value|1
define|#
directive|define
name|USTORM_ISCSI_AG_CONTEXT_TX_CF_EN
value|(0x1<<2)
comment|/* BitField decision_rule_enable_bitsEnable bits for various decision rules	 */
define|#
directive|define
name|USTORM_ISCSI_AG_CONTEXT_TX_CF_EN_SHIFT
value|2
define|#
directive|define
name|__USTORM_ISCSI_AG_CONTEXT_TIMER_CF_EN
value|(0x1<<3)
comment|/* BitField decision_rule_enable_bitsEnable bits for various decision rules	 */
define|#
directive|define
name|__USTORM_ISCSI_AG_CONTEXT_TIMER_CF_EN_SHIFT
value|3
define|#
directive|define
name|__USTORM_ISCSI_AG_CONTEXT_CQ_LOCAL_COMP_CF_EN
value|(0x1<<4)
comment|/* BitField decision_rule_enable_bitsEnable bits for various decision rules	The local completion counter flag enable. Enabled by USTORM at the beginning. */
define|#
directive|define
name|__USTORM_ISCSI_AG_CONTEXT_CQ_LOCAL_COMP_CF_EN_SHIFT
value|4
define|#
directive|define
name|__USTORM_ISCSI_AG_CONTEXT_QUEUES_FLUSH_Q0_CF_EN
value|(0x1<<5)
comment|/* BitField decision_rule_enable_bitsEnable bits for various decision rules	The flush queues counter flag en.  */
define|#
directive|define
name|__USTORM_ISCSI_AG_CONTEXT_QUEUES_FLUSH_Q0_CF_EN_SHIFT
value|5
define|#
directive|define
name|__USTORM_ISCSI_AG_CONTEXT_AUX3_CF_EN
value|(0x1<<6)
comment|/* BitField decision_rule_enable_bitsEnable bits for various decision rules	 */
define|#
directive|define
name|__USTORM_ISCSI_AG_CONTEXT_AUX3_CF_EN_SHIFT
value|6
define|#
directive|define
name|__USTORM_ISCSI_AG_CONTEXT_DQ_CF_EN
value|(0x1<<7)
comment|/* BitField decision_rule_enable_bitsEnable bits for various decision rules	 */
define|#
directive|define
name|__USTORM_ISCSI_AG_CONTEXT_DQ_CF_EN_SHIFT
value|7
name|uint8_t
name|decision_rules
decl_stmt|;
define|#
directive|define
name|USTORM_ISCSI_AG_CONTEXT_AGG_VAL2_RULE
value|(0x7<<0)
comment|/* BitField decision_rulesVarious decision rules	 */
define|#
directive|define
name|USTORM_ISCSI_AG_CONTEXT_AGG_VAL2_RULE_SHIFT
value|0
define|#
directive|define
name|__USTORM_ISCSI_AG_CONTEXT_AGG_VAL3_RULE
value|(0x7<<3)
comment|/* BitField decision_rulesVarious decision rules	 */
define|#
directive|define
name|__USTORM_ISCSI_AG_CONTEXT_AGG_VAL3_RULE_SHIFT
value|3
define|#
directive|define
name|USTORM_ISCSI_AG_CONTEXT_AGG_VAL2_ARM_N_FLAG
value|(0x1<<6)
comment|/* BitField decision_rulesVarious decision rules	 */
define|#
directive|define
name|USTORM_ISCSI_AG_CONTEXT_AGG_VAL2_ARM_N_FLAG_SHIFT
value|6
define|#
directive|define
name|__USTORM_ISCSI_AG_CONTEXT_RESERVED1
value|(0x1<<7)
comment|/* BitField decision_rulesVarious decision rules	 */
define|#
directive|define
name|__USTORM_ISCSI_AG_CONTEXT_RESERVED1_SHIFT
value|7
name|uint16_t
name|__reserved2
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/*  * The toe aggregative context of Ustorm  */
end_comment

begin_struct
struct|struct
name|ustorm_toe_ag_context
block|{
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint8_t
name|__aux_counter_flags
comment|/* auxiliary counter flags*/
decl_stmt|;
name|uint8_t
name|__agg_vars2
comment|/* various aggregation variables*/
decl_stmt|;
name|uint8_t
name|__agg_vars1
comment|/* various aggregation variables*/
decl_stmt|;
name|uint8_t
name|__state
comment|/* The state of the connection */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint8_t
name|__state
comment|/* The state of the connection */
decl_stmt|;
name|uint8_t
name|__agg_vars1
comment|/* various aggregation variables*/
decl_stmt|;
name|uint8_t
name|__agg_vars2
comment|/* various aggregation variables*/
decl_stmt|;
name|uint8_t
name|__aux_counter_flags
comment|/* auxiliary counter flags*/
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint8_t
name|cdu_usage
comment|/* Will be used by the CDU for validation of the CID/connection type on doorbells. */
decl_stmt|;
name|uint8_t
name|__agg_misc2
decl_stmt|;
name|uint16_t
name|__agg_misc1
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|__agg_misc1
decl_stmt|;
name|uint8_t
name|__agg_misc2
decl_stmt|;
name|uint8_t
name|cdu_usage
comment|/* Will be used by the CDU for validation of the CID/connection type on doorbells. */
decl_stmt|;
endif|#
directive|endif
name|uint32_t
name|__agg_misc4
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint8_t
name|__agg_val3_th
decl_stmt|;
name|uint8_t
name|__agg_val3
decl_stmt|;
name|uint16_t
name|__agg_misc3
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|__agg_misc3
decl_stmt|;
name|uint8_t
name|__agg_val3
decl_stmt|;
name|uint8_t
name|__agg_val3_th
decl_stmt|;
endif|#
directive|endif
name|uint32_t
name|driver_doorbell_info_ptr_lo
comment|/* the host pointer that consist the struct of info updated */
decl_stmt|;
name|uint32_t
name|driver_doorbell_info_ptr_hi
comment|/* the host pointer that consist the struct of info updated */
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|__agg_val2_th
decl_stmt|;
name|uint16_t
name|rq_prod
comment|/* The RQ producer */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|rq_prod
comment|/* The RQ producer */
decl_stmt|;
name|uint16_t
name|__agg_val2_th
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|__reserved2
decl_stmt|;
name|uint8_t
name|decision_rules
decl_stmt|;
define|#
directive|define
name|__USTORM_TOE_AG_CONTEXT_AGG_VAL2_RULE
value|(0x7<<0)
comment|/* BitField decision_rulesVarious decision rules	 */
define|#
directive|define
name|__USTORM_TOE_AG_CONTEXT_AGG_VAL2_RULE_SHIFT
value|0
define|#
directive|define
name|__USTORM_TOE_AG_CONTEXT_AGG_VAL3_RULE
value|(0x7<<3)
comment|/* BitField decision_rulesVarious decision rules	 */
define|#
directive|define
name|__USTORM_TOE_AG_CONTEXT_AGG_VAL3_RULE_SHIFT
value|3
define|#
directive|define
name|USTORM_TOE_AG_CONTEXT_AGG_VAL2_ARM_N_FLAG
value|(0x1<<6)
comment|/* BitField decision_rulesVarious decision rules	 */
define|#
directive|define
name|USTORM_TOE_AG_CONTEXT_AGG_VAL2_ARM_N_FLAG_SHIFT
value|6
define|#
directive|define
name|__USTORM_TOE_AG_CONTEXT_RESERVED1
value|(0x1<<7)
comment|/* BitField decision_rulesVarious decision rules	 */
define|#
directive|define
name|__USTORM_TOE_AG_CONTEXT_RESERVED1_SHIFT
value|7
name|uint8_t
name|__decision_rule_enable_bits
comment|/* Enable bits for various decision rules*/
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint8_t
name|__decision_rule_enable_bits
comment|/* Enable bits for various decision rules*/
decl_stmt|;
name|uint8_t
name|decision_rules
decl_stmt|;
define|#
directive|define
name|__USTORM_TOE_AG_CONTEXT_AGG_VAL2_RULE
value|(0x7<<0)
comment|/* BitField decision_rulesVarious decision rules	 */
define|#
directive|define
name|__USTORM_TOE_AG_CONTEXT_AGG_VAL2_RULE_SHIFT
value|0
define|#
directive|define
name|__USTORM_TOE_AG_CONTEXT_AGG_VAL3_RULE
value|(0x7<<3)
comment|/* BitField decision_rulesVarious decision rules	 */
define|#
directive|define
name|__USTORM_TOE_AG_CONTEXT_AGG_VAL3_RULE_SHIFT
value|3
define|#
directive|define
name|USTORM_TOE_AG_CONTEXT_AGG_VAL2_ARM_N_FLAG
value|(0x1<<6)
comment|/* BitField decision_rulesVarious decision rules	 */
define|#
directive|define
name|USTORM_TOE_AG_CONTEXT_AGG_VAL2_ARM_N_FLAG_SHIFT
value|6
define|#
directive|define
name|__USTORM_TOE_AG_CONTEXT_RESERVED1
value|(0x1<<7)
comment|/* BitField decision_rulesVarious decision rules	 */
define|#
directive|define
name|__USTORM_TOE_AG_CONTEXT_RESERVED1_SHIFT
value|7
name|uint16_t
name|__reserved2
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/*  * The eth aggregative context of Xstorm  */
end_comment

begin_struct
struct|struct
name|xstorm_eth_ag_context
block|{
name|uint32_t
name|reserved0
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint8_t
name|cdu_reserved
comment|/* Used by the CDU for validation and debugging */
decl_stmt|;
name|uint8_t
name|reserved2
decl_stmt|;
name|uint16_t
name|reserved1
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|reserved1
decl_stmt|;
name|uint8_t
name|reserved2
decl_stmt|;
name|uint8_t
name|cdu_reserved
comment|/* Used by the CDU for validation and debugging */
decl_stmt|;
endif|#
directive|endif
name|uint32_t
name|reserved3
index|[
literal|30
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The fcoe aggregative context section of Xstorm  */
end_comment

begin_struct
struct|struct
name|xstorm_fcoe_extra_ag_context_section
block|{
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint8_t
name|tcp_agg_vars1
decl_stmt|;
define|#
directive|define
name|__XSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_RESERVED51
value|(0x3<<0)
comment|/* BitField tcp_agg_vars1Various aggregative variables	Counter flag used to rewind the DA timer */
define|#
directive|define
name|__XSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_RESERVED51_SHIFT
value|0
define|#
directive|define
name|__XSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_ACK_TO_FE_UPDATED
value|(0x3<<2)
comment|/* BitField tcp_agg_vars1Various aggregative variables	auxiliary counter flag 2 */
define|#
directive|define
name|__XSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_ACK_TO_FE_UPDATED_SHIFT
value|2
define|#
directive|define
name|XSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_SIDEBAND_SENT_CF
value|(0x3<<4)
comment|/* BitField tcp_agg_vars1Various aggregative variables	auxiliary counter flag 3 */
define|#
directive|define
name|XSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_SIDEBAND_SENT_CF_SHIFT
value|4
define|#
directive|define
name|__XSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_RESERVED_CLEAR_DA_TIMER_EN
value|(0x1<<6)
comment|/* BitField tcp_agg_vars1Various aggregative variables	If set enables sending clear commands as port of the DA decision rules */
define|#
directive|define
name|__XSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_RESERVED_CLEAR_DA_TIMER_EN_SHIFT
value|6
define|#
directive|define
name|__XSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_RESERVED_DA_EXPIRATION_FLAG
value|(0x1<<7)
comment|/* BitField tcp_agg_vars1Various aggregative variables	Indicates that there was a delayed ack timer expiration */
define|#
directive|define
name|__XSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_RESERVED_DA_EXPIRATION_FLAG_SHIFT
value|7
name|uint8_t
name|__reserved_da_cnt
comment|/* Counts the number of ACK requests received from the TSTORM with no registration to QM. */
decl_stmt|;
name|uint16_t
name|__mtu
comment|/* MSS used for nagle algorithm and for transmission */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|__mtu
comment|/* MSS used for nagle algorithm and for transmission */
decl_stmt|;
name|uint8_t
name|__reserved_da_cnt
comment|/* Counts the number of ACK requests received from the TSTORM with no registration to QM. */
decl_stmt|;
name|uint8_t
name|tcp_agg_vars1
decl_stmt|;
define|#
directive|define
name|__XSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_RESERVED51
value|(0x3<<0)
comment|/* BitField tcp_agg_vars1Various aggregative variables	Counter flag used to rewind the DA timer */
define|#
directive|define
name|__XSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_RESERVED51_SHIFT
value|0
define|#
directive|define
name|__XSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_ACK_TO_FE_UPDATED
value|(0x3<<2)
comment|/* BitField tcp_agg_vars1Various aggregative variables	auxiliary counter flag 2 */
define|#
directive|define
name|__XSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_ACK_TO_FE_UPDATED_SHIFT
value|2
define|#
directive|define
name|XSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_SIDEBAND_SENT_CF
value|(0x3<<4)
comment|/* BitField tcp_agg_vars1Various aggregative variables	auxiliary counter flag 3 */
define|#
directive|define
name|XSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_SIDEBAND_SENT_CF_SHIFT
value|4
define|#
directive|define
name|__XSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_RESERVED_CLEAR_DA_TIMER_EN
value|(0x1<<6)
comment|/* BitField tcp_agg_vars1Various aggregative variables	If set enables sending clear commands as port of the DA decision rules */
define|#
directive|define
name|__XSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_RESERVED_CLEAR_DA_TIMER_EN_SHIFT
value|6
define|#
directive|define
name|__XSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_RESERVED_DA_EXPIRATION_FLAG
value|(0x1<<7)
comment|/* BitField tcp_agg_vars1Various aggregative variables	Indicates that there was a delayed ack timer expiration */
define|#
directive|define
name|__XSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_RESERVED_DA_EXPIRATION_FLAG_SHIFT
value|7
endif|#
directive|endif
name|uint32_t
name|snd_nxt
comment|/* The current sequence number to send */
decl_stmt|;
name|uint32_t
name|__xfrqe_bd_addr_lo
comment|/* The Current transmission window in bytes */
decl_stmt|;
name|uint32_t
name|__xfrqe_bd_addr_hi
comment|/* The current Send UNA sequence number */
decl_stmt|;
name|uint32_t
name|__xfrqe_data1
comment|/* The current local advertised window to FE. */
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint8_t
name|__agg_val8_th
comment|/* aggregated value 8 - threshold */
decl_stmt|;
name|uint8_t
name|__tx_dest
comment|/* aggregated value 8 */
decl_stmt|;
name|uint16_t
name|tcp_agg_vars2
decl_stmt|;
define|#
directive|define
name|__XSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_RESERVED57
value|(0x1<<0)
comment|/* BitField tcp_agg_vars2Various aggregative variables	Used in TOE to indicate that FIN is sent on a BD to bypass the naggle rule */
define|#
directive|define
name|__XSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_RESERVED57_SHIFT
value|0
define|#
directive|define
name|__XSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_RESERVED58
value|(0x1<<1)
comment|/* BitField tcp_agg_vars2Various aggregative variables	Enables the tx window based decision */
define|#
directive|define
name|__XSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_RESERVED58_SHIFT
value|1
define|#
directive|define
name|__XSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_RESERVED59
value|(0x1<<2)
comment|/* BitField tcp_agg_vars2Various aggregative variables	The DA Timer status. If set indicates that the delayed ACK timer is active. */
define|#
directive|define
name|__XSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_RESERVED59_SHIFT
value|2
define|#
directive|define
name|__XSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_AUX3_FLAG
value|(0x1<<3)
comment|/* BitField tcp_agg_vars2Various aggregative variables	auxiliary flag 3 */
define|#
directive|define
name|__XSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_AUX3_FLAG_SHIFT
value|3
define|#
directive|define
name|__XSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_AUX4_FLAG
value|(0x1<<4)
comment|/* BitField tcp_agg_vars2Various aggregative variables	auxiliary flag 4 */
define|#
directive|define
name|__XSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_AUX4_FLAG_SHIFT
value|4
define|#
directive|define
name|__XSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_RESERVED60
value|(0x1<<5)
comment|/* BitField tcp_agg_vars2Various aggregative variables	Enable DA for the specific connection */
define|#
directive|define
name|__XSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_RESERVED60_SHIFT
value|5
define|#
directive|define
name|__XSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_RESERVED_ACK_TO_FE_UPDATED_EN
value|(0x1<<6)
comment|/* BitField tcp_agg_vars2Various aggregative variables	Enable decision rules based on aux2_cf */
define|#
directive|define
name|__XSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_RESERVED_ACK_TO_FE_UPDATED_EN_SHIFT
value|6
define|#
directive|define
name|XSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_SIDEBAND_SENT_CF_EN
value|(0x1<<7)
comment|/* BitField tcp_agg_vars2Various aggregative variables	Enable decision rules based on aux3_cf */
define|#
directive|define
name|XSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_SIDEBAND_SENT_CF_EN_SHIFT
value|7
define|#
directive|define
name|__XSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_RESERVED_TX_FIN_FLAG_EN
value|(0x1<<8)
comment|/* BitField tcp_agg_vars2Various aggregative variables	Enable Decision rule based on tx_fin_flag */
define|#
directive|define
name|__XSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_RESERVED_TX_FIN_FLAG_EN_SHIFT
value|8
define|#
directive|define
name|__XSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_AUX1_FLAG
value|(0x1<<9)
comment|/* BitField tcp_agg_vars2Various aggregative variables	auxiliary flag 1 */
define|#
directive|define
name|__XSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_AUX1_FLAG_SHIFT
value|9
define|#
directive|define
name|__XSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_SET_RTO_CF
value|(0x3<<10)
comment|/* BitField tcp_agg_vars2Various aggregative variables	counter flag for setting the rto timer */
define|#
directive|define
name|__XSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_SET_RTO_CF_SHIFT
value|10
define|#
directive|define
name|__XSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_TS_TO_ECHO_UPDATED_CF
value|(0x3<<12)
comment|/* BitField tcp_agg_vars2Various aggregative variables	timestamp was updated counter flag */
define|#
directive|define
name|__XSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_TS_TO_ECHO_UPDATED_CF_SHIFT
value|12
define|#
directive|define
name|__XSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_TX_DEST_UPDATED_CF
value|(0x3<<14)
comment|/* BitField tcp_agg_vars2Various aggregative variables	auxiliary counter flag 8 */
define|#
directive|define
name|__XSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_TX_DEST_UPDATED_CF_SHIFT
value|14
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|tcp_agg_vars2
decl_stmt|;
define|#
directive|define
name|__XSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_RESERVED57
value|(0x1<<0)
comment|/* BitField tcp_agg_vars2Various aggregative variables	Used in TOE to indicate that FIN is sent on a BD to bypass the naggle rule */
define|#
directive|define
name|__XSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_RESERVED57_SHIFT
value|0
define|#
directive|define
name|__XSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_RESERVED58
value|(0x1<<1)
comment|/* BitField tcp_agg_vars2Various aggregative variables	Enables the tx window based decision */
define|#
directive|define
name|__XSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_RESERVED58_SHIFT
value|1
define|#
directive|define
name|__XSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_RESERVED59
value|(0x1<<2)
comment|/* BitField tcp_agg_vars2Various aggregative variables	The DA Timer status. If set indicates that the delayed ACK timer is active. */
define|#
directive|define
name|__XSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_RESERVED59_SHIFT
value|2
define|#
directive|define
name|__XSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_AUX3_FLAG
value|(0x1<<3)
comment|/* BitField tcp_agg_vars2Various aggregative variables	auxiliary flag 3 */
define|#
directive|define
name|__XSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_AUX3_FLAG_SHIFT
value|3
define|#
directive|define
name|__XSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_AUX4_FLAG
value|(0x1<<4)
comment|/* BitField tcp_agg_vars2Various aggregative variables	auxiliary flag 4 */
define|#
directive|define
name|__XSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_AUX4_FLAG_SHIFT
value|4
define|#
directive|define
name|__XSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_RESERVED60
value|(0x1<<5)
comment|/* BitField tcp_agg_vars2Various aggregative variables	Enable DA for the specific connection */
define|#
directive|define
name|__XSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_RESERVED60_SHIFT
value|5
define|#
directive|define
name|__XSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_RESERVED_ACK_TO_FE_UPDATED_EN
value|(0x1<<6)
comment|/* BitField tcp_agg_vars2Various aggregative variables	Enable decision rules based on aux2_cf */
define|#
directive|define
name|__XSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_RESERVED_ACK_TO_FE_UPDATED_EN_SHIFT
value|6
define|#
directive|define
name|XSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_SIDEBAND_SENT_CF_EN
value|(0x1<<7)
comment|/* BitField tcp_agg_vars2Various aggregative variables	Enable decision rules based on aux3_cf */
define|#
directive|define
name|XSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_SIDEBAND_SENT_CF_EN_SHIFT
value|7
define|#
directive|define
name|__XSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_RESERVED_TX_FIN_FLAG_EN
value|(0x1<<8)
comment|/* BitField tcp_agg_vars2Various aggregative variables	Enable Decision rule based on tx_fin_flag */
define|#
directive|define
name|__XSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_RESERVED_TX_FIN_FLAG_EN_SHIFT
value|8
define|#
directive|define
name|__XSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_AUX1_FLAG
value|(0x1<<9)
comment|/* BitField tcp_agg_vars2Various aggregative variables	auxiliary flag 1 */
define|#
directive|define
name|__XSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_AUX1_FLAG_SHIFT
value|9
define|#
directive|define
name|__XSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_SET_RTO_CF
value|(0x3<<10)
comment|/* BitField tcp_agg_vars2Various aggregative variables	counter flag for setting the rto timer */
define|#
directive|define
name|__XSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_SET_RTO_CF_SHIFT
value|10
define|#
directive|define
name|__XSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_TS_TO_ECHO_UPDATED_CF
value|(0x3<<12)
comment|/* BitField tcp_agg_vars2Various aggregative variables	timestamp was updated counter flag */
define|#
directive|define
name|__XSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_TS_TO_ECHO_UPDATED_CF_SHIFT
value|12
define|#
directive|define
name|__XSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_TX_DEST_UPDATED_CF
value|(0x3<<14)
comment|/* BitField tcp_agg_vars2Various aggregative variables	auxiliary counter flag 8 */
define|#
directive|define
name|__XSTORM_FCOE_EXTRA_AG_CONTEXT_SECTION_TX_DEST_UPDATED_CF_SHIFT
value|14
name|uint8_t
name|__tx_dest
comment|/* aggregated value 8 */
decl_stmt|;
name|uint8_t
name|__agg_val8_th
comment|/* aggregated value 8 - threshold */
decl_stmt|;
endif|#
directive|endif
name|uint32_t
name|__sq_base_addr_lo
comment|/* The low page address which the SQ resides in host memory */
decl_stmt|;
name|uint32_t
name|__sq_base_addr_hi
comment|/* The high page address which the SQ resides in host memory */
decl_stmt|;
name|uint32_t
name|__xfrq_base_addr_lo
comment|/* The low page address which the XFRQ resides in host memory */
decl_stmt|;
name|uint32_t
name|__xfrq_base_addr_hi
comment|/* The high page address which the XFRQ resides in host memory */
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|__xfrq_cons
comment|/* The XFRQ consumer */
decl_stmt|;
name|uint16_t
name|__xfrq_prod
comment|/* The XFRQ producer, updated by Ustorm */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|__xfrq_prod
comment|/* The XFRQ producer, updated by Ustorm */
decl_stmt|;
name|uint16_t
name|__xfrq_cons
comment|/* The XFRQ consumer */
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint8_t
name|__tcp_agg_vars5
comment|/* Various aggregative variables*/
decl_stmt|;
name|uint8_t
name|__tcp_agg_vars4
comment|/* Various aggregative variables*/
decl_stmt|;
name|uint8_t
name|__tcp_agg_vars3
comment|/* Various aggregative variables*/
decl_stmt|;
name|uint8_t
name|__reserved_force_pure_ack_cnt
comment|/* The number of force ACK commands arrived from the TSTORM */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint8_t
name|__reserved_force_pure_ack_cnt
comment|/* The number of force ACK commands arrived from the TSTORM */
decl_stmt|;
name|uint8_t
name|__tcp_agg_vars3
comment|/* Various aggregative variables*/
decl_stmt|;
name|uint8_t
name|__tcp_agg_vars4
comment|/* Various aggregative variables*/
decl_stmt|;
name|uint8_t
name|__tcp_agg_vars5
comment|/* Various aggregative variables*/
decl_stmt|;
endif|#
directive|endif
name|uint32_t
name|__tcp_agg_vars6
comment|/* Various aggregative variables*/
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|__xfrqe_mng
comment|/* Misc aggregated variable 6 */
decl_stmt|;
name|uint16_t
name|__tcp_agg_vars7
comment|/* Various aggregative variables*/
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|__tcp_agg_vars7
comment|/* Various aggregative variables*/
decl_stmt|;
name|uint16_t
name|__xfrqe_mng
comment|/* Misc aggregated variable 6 */
decl_stmt|;
endif|#
directive|endif
name|uint32_t
name|__xfrqe_data0
comment|/* aggregated value 10 */
decl_stmt|;
name|uint32_t
name|__agg_val10_th
comment|/* aggregated value 10 - threshold */
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|__reserved3
decl_stmt|;
name|uint8_t
name|__reserved2
decl_stmt|;
name|uint8_t
name|__da_only_cnt
comment|/* counts delayed acks and not window updates */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint8_t
name|__da_only_cnt
comment|/* counts delayed acks and not window updates */
decl_stmt|;
name|uint8_t
name|__reserved2
decl_stmt|;
name|uint16_t
name|__reserved3
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/*  * The fcoe aggregative context of Xstorm  */
end_comment

begin_struct
struct|struct
name|xstorm_fcoe_ag_context
block|{
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|agg_val1
comment|/* aggregated value 1 */
decl_stmt|;
name|uint8_t
name|agg_vars1
decl_stmt|;
define|#
directive|define
name|__XSTORM_FCOE_AG_CONTEXT_EXISTS_IN_QM0
value|(0x1<<0)
comment|/* BitField agg_vars1Various aggregative variables	The connection is currently registered to the QM with queue index 0 */
define|#
directive|define
name|__XSTORM_FCOE_AG_CONTEXT_EXISTS_IN_QM0_SHIFT
value|0
define|#
directive|define
name|__XSTORM_FCOE_AG_CONTEXT_EXISTS_IN_QM1
value|(0x1<<1)
comment|/* BitField agg_vars1Various aggregative variables	The connection is currently registered to the QM with queue index 1 */
define|#
directive|define
name|__XSTORM_FCOE_AG_CONTEXT_EXISTS_IN_QM1_SHIFT
value|1
define|#
directive|define
name|__XSTORM_FCOE_AG_CONTEXT_RESERVED51
value|(0x1<<2)
comment|/* BitField agg_vars1Various aggregative variables	The connection is currently registered to the QM with queue index 2 */
define|#
directive|define
name|__XSTORM_FCOE_AG_CONTEXT_RESERVED51_SHIFT
value|2
define|#
directive|define
name|__XSTORM_FCOE_AG_CONTEXT_RESERVED52
value|(0x1<<3)
comment|/* BitField agg_vars1Various aggregative variables	The connection is currently registered to the QM with queue index 3 */
define|#
directive|define
name|__XSTORM_FCOE_AG_CONTEXT_RESERVED52_SHIFT
value|3
define|#
directive|define
name|__XSTORM_FCOE_AG_CONTEXT_MORE_TO_SEND_EN
value|(0x1<<4)
comment|/* BitField agg_vars1Various aggregative variables	Enables the decision rule of more_to_Send> 0 */
define|#
directive|define
name|__XSTORM_FCOE_AG_CONTEXT_MORE_TO_SEND_EN_SHIFT
value|4
define|#
directive|define
name|XSTORM_FCOE_AG_CONTEXT_NAGLE_EN
value|(0x1<<5)
comment|/* BitField agg_vars1Various aggregative variables	Enables the nagle decision */
define|#
directive|define
name|XSTORM_FCOE_AG_CONTEXT_NAGLE_EN_SHIFT
value|5
define|#
directive|define
name|__XSTORM_FCOE_AG_CONTEXT_DQ_SPARE_FLAG
value|(0x1<<6)
comment|/* BitField agg_vars1Various aggregative variables	Used for future indication by the Driver on a doorbell */
define|#
directive|define
name|__XSTORM_FCOE_AG_CONTEXT_DQ_SPARE_FLAG_SHIFT
value|6
define|#
directive|define
name|__XSTORM_FCOE_AG_CONTEXT_RESERVED_UNA_GT_NXT_EN
value|(0x1<<7)
comment|/* BitField agg_vars1Various aggregative variables	Enable decision rules based on equality between snd_una and snd_nxt */
define|#
directive|define
name|__XSTORM_FCOE_AG_CONTEXT_RESERVED_UNA_GT_NXT_EN_SHIFT
value|7
name|uint8_t
name|__state
comment|/* The state of the connection */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint8_t
name|__state
comment|/* The state of the connection */
decl_stmt|;
name|uint8_t
name|agg_vars1
decl_stmt|;
define|#
directive|define
name|__XSTORM_FCOE_AG_CONTEXT_EXISTS_IN_QM0
value|(0x1<<0)
comment|/* BitField agg_vars1Various aggregative variables	The connection is currently registered to the QM with queue index 0 */
define|#
directive|define
name|__XSTORM_FCOE_AG_CONTEXT_EXISTS_IN_QM0_SHIFT
value|0
define|#
directive|define
name|__XSTORM_FCOE_AG_CONTEXT_EXISTS_IN_QM1
value|(0x1<<1)
comment|/* BitField agg_vars1Various aggregative variables	The connection is currently registered to the QM with queue index 1 */
define|#
directive|define
name|__XSTORM_FCOE_AG_CONTEXT_EXISTS_IN_QM1_SHIFT
value|1
define|#
directive|define
name|__XSTORM_FCOE_AG_CONTEXT_RESERVED51
value|(0x1<<2)
comment|/* BitField agg_vars1Various aggregative variables	The connection is currently registered to the QM with queue index 2 */
define|#
directive|define
name|__XSTORM_FCOE_AG_CONTEXT_RESERVED51_SHIFT
value|2
define|#
directive|define
name|__XSTORM_FCOE_AG_CONTEXT_RESERVED52
value|(0x1<<3)
comment|/* BitField agg_vars1Various aggregative variables	The connection is currently registered to the QM with queue index 3 */
define|#
directive|define
name|__XSTORM_FCOE_AG_CONTEXT_RESERVED52_SHIFT
value|3
define|#
directive|define
name|__XSTORM_FCOE_AG_CONTEXT_MORE_TO_SEND_EN
value|(0x1<<4)
comment|/* BitField agg_vars1Various aggregative variables	Enables the decision rule of more_to_Send> 0 */
define|#
directive|define
name|__XSTORM_FCOE_AG_CONTEXT_MORE_TO_SEND_EN_SHIFT
value|4
define|#
directive|define
name|XSTORM_FCOE_AG_CONTEXT_NAGLE_EN
value|(0x1<<5)
comment|/* BitField agg_vars1Various aggregative variables	Enables the nagle decision */
define|#
directive|define
name|XSTORM_FCOE_AG_CONTEXT_NAGLE_EN_SHIFT
value|5
define|#
directive|define
name|__XSTORM_FCOE_AG_CONTEXT_DQ_SPARE_FLAG
value|(0x1<<6)
comment|/* BitField agg_vars1Various aggregative variables	Used for future indication by the Driver on a doorbell */
define|#
directive|define
name|__XSTORM_FCOE_AG_CONTEXT_DQ_SPARE_FLAG_SHIFT
value|6
define|#
directive|define
name|__XSTORM_FCOE_AG_CONTEXT_RESERVED_UNA_GT_NXT_EN
value|(0x1<<7)
comment|/* BitField agg_vars1Various aggregative variables	Enable decision rules based on equality between snd_una and snd_nxt */
define|#
directive|define
name|__XSTORM_FCOE_AG_CONTEXT_RESERVED_UNA_GT_NXT_EN_SHIFT
value|7
name|uint16_t
name|agg_val1
comment|/* aggregated value 1 */
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint8_t
name|cdu_reserved
comment|/* Used by the CDU for validation and debugging */
decl_stmt|;
name|uint8_t
name|__agg_vars4
comment|/* Various aggregative variables*/
decl_stmt|;
name|uint8_t
name|agg_vars3
decl_stmt|;
define|#
directive|define
name|XSTORM_FCOE_AG_CONTEXT_PHYSICAL_QUEUE_NUM2
value|(0x3F<<0)
comment|/* BitField agg_vars3Various aggregative variables	The physical queue number of queue index 2 */
define|#
directive|define
name|XSTORM_FCOE_AG_CONTEXT_PHYSICAL_QUEUE_NUM2_SHIFT
value|0
define|#
directive|define
name|__XSTORM_FCOE_AG_CONTEXT_AUX19_CF
value|(0x3<<6)
comment|/* BitField agg_vars3Various aggregative variables	auxiliary counter flag 19 */
define|#
directive|define
name|__XSTORM_FCOE_AG_CONTEXT_AUX19_CF_SHIFT
value|6
name|uint8_t
name|agg_vars2
decl_stmt|;
define|#
directive|define
name|__XSTORM_FCOE_AG_CONTEXT_DQ_CF
value|(0x3<<0)
comment|/* BitField agg_vars2Various aggregative variables	auxiliary counter flag 4 */
define|#
directive|define
name|__XSTORM_FCOE_AG_CONTEXT_DQ_CF_SHIFT
value|0
define|#
directive|define
name|__XSTORM_FCOE_AG_CONTEXT_DQ_SPARE_FLAG_EN
value|(0x1<<2)
comment|/* BitField agg_vars2Various aggregative variables	Enable decision rule based on dq_spare_flag */
define|#
directive|define
name|__XSTORM_FCOE_AG_CONTEXT_DQ_SPARE_FLAG_EN_SHIFT
value|2
define|#
directive|define
name|__XSTORM_FCOE_AG_CONTEXT_AUX8_FLAG
value|(0x1<<3)
comment|/* BitField agg_vars2Various aggregative variables	auxiliary flag 8 */
define|#
directive|define
name|__XSTORM_FCOE_AG_CONTEXT_AUX8_FLAG_SHIFT
value|3
define|#
directive|define
name|__XSTORM_FCOE_AG_CONTEXT_AUX9_FLAG
value|(0x1<<4)
comment|/* BitField agg_vars2Various aggregative variables	auxiliary flag 9 */
define|#
directive|define
name|__XSTORM_FCOE_AG_CONTEXT_AUX9_FLAG_SHIFT
value|4
define|#
directive|define
name|XSTORM_FCOE_AG_CONTEXT_DECISION_RULE1
value|(0x3<<5)
comment|/* BitField agg_vars2Various aggregative variables	0-NOP,1-EQ,2-NEQ */
define|#
directive|define
name|XSTORM_FCOE_AG_CONTEXT_DECISION_RULE1_SHIFT
value|5
define|#
directive|define
name|__XSTORM_FCOE_AG_CONTEXT_DQ_CF_EN
value|(0x1<<7)
comment|/* BitField agg_vars2Various aggregative variables	Enable decision rules based on aux4_cf */
define|#
directive|define
name|__XSTORM_FCOE_AG_CONTEXT_DQ_CF_EN_SHIFT
value|7
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint8_t
name|agg_vars2
decl_stmt|;
define|#
directive|define
name|__XSTORM_FCOE_AG_CONTEXT_DQ_CF
value|(0x3<<0)
comment|/* BitField agg_vars2Various aggregative variables	auxiliary counter flag 4 */
define|#
directive|define
name|__XSTORM_FCOE_AG_CONTEXT_DQ_CF_SHIFT
value|0
define|#
directive|define
name|__XSTORM_FCOE_AG_CONTEXT_DQ_SPARE_FLAG_EN
value|(0x1<<2)
comment|/* BitField agg_vars2Various aggregative variables	Enable decision rule based on dq_spare_flag */
define|#
directive|define
name|__XSTORM_FCOE_AG_CONTEXT_DQ_SPARE_FLAG_EN_SHIFT
value|2
define|#
directive|define
name|__XSTORM_FCOE_AG_CONTEXT_AUX8_FLAG
value|(0x1<<3)
comment|/* BitField agg_vars2Various aggregative variables	auxiliary flag 8 */
define|#
directive|define
name|__XSTORM_FCOE_AG_CONTEXT_AUX8_FLAG_SHIFT
value|3
define|#
directive|define
name|__XSTORM_FCOE_AG_CONTEXT_AUX9_FLAG
value|(0x1<<4)
comment|/* BitField agg_vars2Various aggregative variables	auxiliary flag 9 */
define|#
directive|define
name|__XSTORM_FCOE_AG_CONTEXT_AUX9_FLAG_SHIFT
value|4
define|#
directive|define
name|XSTORM_FCOE_AG_CONTEXT_DECISION_RULE1
value|(0x3<<5)
comment|/* BitField agg_vars2Various aggregative variables	0-NOP,1-EQ,2-NEQ */
define|#
directive|define
name|XSTORM_FCOE_AG_CONTEXT_DECISION_RULE1_SHIFT
value|5
define|#
directive|define
name|__XSTORM_FCOE_AG_CONTEXT_DQ_CF_EN
value|(0x1<<7)
comment|/* BitField agg_vars2Various aggregative variables	Enable decision rules based on aux4_cf */
define|#
directive|define
name|__XSTORM_FCOE_AG_CONTEXT_DQ_CF_EN_SHIFT
value|7
name|uint8_t
name|agg_vars3
decl_stmt|;
define|#
directive|define
name|XSTORM_FCOE_AG_CONTEXT_PHYSICAL_QUEUE_NUM2
value|(0x3F<<0)
comment|/* BitField agg_vars3Various aggregative variables	The physical queue number of queue index 2 */
define|#
directive|define
name|XSTORM_FCOE_AG_CONTEXT_PHYSICAL_QUEUE_NUM2_SHIFT
value|0
define|#
directive|define
name|__XSTORM_FCOE_AG_CONTEXT_AUX19_CF
value|(0x3<<6)
comment|/* BitField agg_vars3Various aggregative variables	auxiliary counter flag 19 */
define|#
directive|define
name|__XSTORM_FCOE_AG_CONTEXT_AUX19_CF_SHIFT
value|6
name|uint8_t
name|__agg_vars4
comment|/* Various aggregative variables*/
decl_stmt|;
name|uint8_t
name|cdu_reserved
comment|/* Used by the CDU for validation and debugging */
decl_stmt|;
endif|#
directive|endif
name|uint32_t
name|more_to_send
comment|/* The number of bytes left to send */
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|agg_vars5
decl_stmt|;
define|#
directive|define
name|XSTORM_FCOE_AG_CONTEXT_DECISION_RULE5
value|(0x3<<0)
comment|/* BitField agg_vars5Various aggregative variables	0-NOP,1-EQ,2-NEQ */
define|#
directive|define
name|XSTORM_FCOE_AG_CONTEXT_DECISION_RULE5_SHIFT
value|0
define|#
directive|define
name|XSTORM_FCOE_AG_CONTEXT_PHYSICAL_QUEUE_NUM0
value|(0x3F<<2)
comment|/* BitField agg_vars5Various aggregative variables	The physical queue number of queue index 0 */
define|#
directive|define
name|XSTORM_FCOE_AG_CONTEXT_PHYSICAL_QUEUE_NUM0_SHIFT
value|2
define|#
directive|define
name|XSTORM_FCOE_AG_CONTEXT_PHYSICAL_QUEUE_NUM1
value|(0x3F<<8)
comment|/* BitField agg_vars5Various aggregative variables	The physical queue number of queue index 1 */
define|#
directive|define
name|XSTORM_FCOE_AG_CONTEXT_PHYSICAL_QUEUE_NUM1_SHIFT
value|8
define|#
directive|define
name|__XSTORM_FCOE_AG_CONTEXT_CONFQ_DEC_RULE
value|(0x3<<14)
comment|/* BitField agg_vars5Various aggregative variables	0-NOP,1-EQ,2-NEQ */
define|#
directive|define
name|__XSTORM_FCOE_AG_CONTEXT_CONFQ_DEC_RULE_SHIFT
value|14
name|uint16_t
name|sq_cons
comment|/* The SQ consumer updated by Xstorm after consuming aother WQE */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|sq_cons
comment|/* The SQ consumer updated by Xstorm after consuming aother WQE */
decl_stmt|;
name|uint16_t
name|agg_vars5
decl_stmt|;
define|#
directive|define
name|XSTORM_FCOE_AG_CONTEXT_DECISION_RULE5
value|(0x3<<0)
comment|/* BitField agg_vars5Various aggregative variables	0-NOP,1-EQ,2-NEQ */
define|#
directive|define
name|XSTORM_FCOE_AG_CONTEXT_DECISION_RULE5_SHIFT
value|0
define|#
directive|define
name|XSTORM_FCOE_AG_CONTEXT_PHYSICAL_QUEUE_NUM0
value|(0x3F<<2)
comment|/* BitField agg_vars5Various aggregative variables	The physical queue number of queue index 0 */
define|#
directive|define
name|XSTORM_FCOE_AG_CONTEXT_PHYSICAL_QUEUE_NUM0_SHIFT
value|2
define|#
directive|define
name|XSTORM_FCOE_AG_CONTEXT_PHYSICAL_QUEUE_NUM1
value|(0x3F<<8)
comment|/* BitField agg_vars5Various aggregative variables	The physical queue number of queue index 1 */
define|#
directive|define
name|XSTORM_FCOE_AG_CONTEXT_PHYSICAL_QUEUE_NUM1_SHIFT
value|8
define|#
directive|define
name|__XSTORM_FCOE_AG_CONTEXT_CONFQ_DEC_RULE
value|(0x3<<14)
comment|/* BitField agg_vars5Various aggregative variables	0-NOP,1-EQ,2-NEQ */
define|#
directive|define
name|__XSTORM_FCOE_AG_CONTEXT_CONFQ_DEC_RULE_SHIFT
value|14
endif|#
directive|endif
name|struct
name|xstorm_fcoe_extra_ag_context_section
name|__extra_section
comment|/* Extra context section */
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|agg_vars7
decl_stmt|;
define|#
directive|define
name|__XSTORM_FCOE_AG_CONTEXT_AGG_VAL11_DECISION_RULE
value|(0x7<<0)
comment|/* BitField agg_vars7Various aggregative variables	0-NOP,1-EQ,2-NEQ,3-GT_CYC,4-GT_ABS,5-LT_CYC,6-LT_ABS */
define|#
directive|define
name|__XSTORM_FCOE_AG_CONTEXT_AGG_VAL11_DECISION_RULE_SHIFT
value|0
define|#
directive|define
name|__XSTORM_FCOE_AG_CONTEXT_AUX13_FLAG
value|(0x1<<3)
comment|/* BitField agg_vars7Various aggregative variables	auxiliary flag 13 */
define|#
directive|define
name|__XSTORM_FCOE_AG_CONTEXT_AUX13_FLAG_SHIFT
value|3
define|#
directive|define
name|__XSTORM_FCOE_AG_CONTEXT_QUEUE0_CF
value|(0x3<<4)
comment|/* BitField agg_vars7Various aggregative variables	auxiliary counter flag 18 */
define|#
directive|define
name|__XSTORM_FCOE_AG_CONTEXT_QUEUE0_CF_SHIFT
value|4
define|#
directive|define
name|XSTORM_FCOE_AG_CONTEXT_DECISION_RULE3
value|(0x3<<6)
comment|/* BitField agg_vars7Various aggregative variables	0-NOP,1-EQ,2-NEQ */
define|#
directive|define
name|XSTORM_FCOE_AG_CONTEXT_DECISION_RULE3_SHIFT
value|6
define|#
directive|define
name|XSTORM_FCOE_AG_CONTEXT_AUX1_CF
value|(0x3<<8)
comment|/* BitField agg_vars7Various aggregative variables	auxiliary counter flag 1 */
define|#
directive|define
name|XSTORM_FCOE_AG_CONTEXT_AUX1_CF_SHIFT
value|8
define|#
directive|define
name|__XSTORM_FCOE_AG_CONTEXT_RESERVED62
value|(0x1<<10)
comment|/* BitField agg_vars7Various aggregative variables	Mask the check of the completion sequence on retransmit */
define|#
directive|define
name|__XSTORM_FCOE_AG_CONTEXT_RESERVED62_SHIFT
value|10
define|#
directive|define
name|__XSTORM_FCOE_AG_CONTEXT_AUX1_CF_EN
value|(0x1<<11)
comment|/* BitField agg_vars7Various aggregative variables	Enable decision rules based on aux1_cf */
define|#
directive|define
name|__XSTORM_FCOE_AG_CONTEXT_AUX1_CF_EN_SHIFT
value|11
define|#
directive|define
name|__XSTORM_FCOE_AG_CONTEXT_AUX10_FLAG
value|(0x1<<12)
comment|/* BitField agg_vars7Various aggregative variables	auxiliary flag 10 */
define|#
directive|define
name|__XSTORM_FCOE_AG_CONTEXT_AUX10_FLAG_SHIFT
value|12
define|#
directive|define
name|__XSTORM_FCOE_AG_CONTEXT_AUX11_FLAG
value|(0x1<<13)
comment|/* BitField agg_vars7Various aggregative variables	auxiliary flag 11 */
define|#
directive|define
name|__XSTORM_FCOE_AG_CONTEXT_AUX11_FLAG_SHIFT
value|13
define|#
directive|define
name|__XSTORM_FCOE_AG_CONTEXT_AUX12_FLAG
value|(0x1<<14)
comment|/* BitField agg_vars7Various aggregative variables	auxiliary flag 12 */
define|#
directive|define
name|__XSTORM_FCOE_AG_CONTEXT_AUX12_FLAG_SHIFT
value|14
define|#
directive|define
name|__XSTORM_FCOE_AG_CONTEXT_AUX2_FLAG
value|(0x1<<15)
comment|/* BitField agg_vars7Various aggregative variables	auxiliary flag 2 */
define|#
directive|define
name|__XSTORM_FCOE_AG_CONTEXT_AUX2_FLAG_SHIFT
value|15
name|uint8_t
name|agg_val3_th
comment|/* Aggregated value 3 - threshold */
decl_stmt|;
name|uint8_t
name|agg_vars6
decl_stmt|;
define|#
directive|define
name|XSTORM_FCOE_AG_CONTEXT_DECISION_RULE6
value|(0x7<<0)
comment|/* BitField agg_vars6Various aggregative variables	0-NOP,1-EQ,2-NEQ,3-GT_CYC,4-GT_ABS,5-LT_CYC,6-LT_ABS */
define|#
directive|define
name|XSTORM_FCOE_AG_CONTEXT_DECISION_RULE6_SHIFT
value|0
define|#
directive|define
name|__XSTORM_FCOE_AG_CONTEXT_XFRQ_DEC_RULE
value|(0x7<<3)
comment|/* BitField agg_vars6Various aggregative variables	0-NOP,1-EQ,2-NEQ,3-GT_CYC,4-GT_ABS,5-LT_CYC,6-LT_ABS */
define|#
directive|define
name|__XSTORM_FCOE_AG_CONTEXT_XFRQ_DEC_RULE_SHIFT
value|3
define|#
directive|define
name|__XSTORM_FCOE_AG_CONTEXT_SQ_DEC_RULE
value|(0x3<<6)
comment|/* BitField agg_vars6Various aggregative variables	0-NOP,1-EQ,2-NEQ */
define|#
directive|define
name|__XSTORM_FCOE_AG_CONTEXT_SQ_DEC_RULE_SHIFT
value|6
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint8_t
name|agg_vars6
decl_stmt|;
define|#
directive|define
name|XSTORM_FCOE_AG_CONTEXT_DECISION_RULE6
value|(0x7<<0)
comment|/* BitField agg_vars6Various aggregative variables	0-NOP,1-EQ,2-NEQ,3-GT_CYC,4-GT_ABS,5-LT_CYC,6-LT_ABS */
define|#
directive|define
name|XSTORM_FCOE_AG_CONTEXT_DECISION_RULE6_SHIFT
value|0
define|#
directive|define
name|__XSTORM_FCOE_AG_CONTEXT_XFRQ_DEC_RULE
value|(0x7<<3)
comment|/* BitField agg_vars6Various aggregative variables	0-NOP,1-EQ,2-NEQ,3-GT_CYC,4-GT_ABS,5-LT_CYC,6-LT_ABS */
define|#
directive|define
name|__XSTORM_FCOE_AG_CONTEXT_XFRQ_DEC_RULE_SHIFT
value|3
define|#
directive|define
name|__XSTORM_FCOE_AG_CONTEXT_SQ_DEC_RULE
value|(0x3<<6)
comment|/* BitField agg_vars6Various aggregative variables	0-NOP,1-EQ,2-NEQ */
define|#
directive|define
name|__XSTORM_FCOE_AG_CONTEXT_SQ_DEC_RULE_SHIFT
value|6
name|uint8_t
name|agg_val3_th
comment|/* Aggregated value 3 - threshold */
decl_stmt|;
name|uint16_t
name|agg_vars7
decl_stmt|;
define|#
directive|define
name|__XSTORM_FCOE_AG_CONTEXT_AGG_VAL11_DECISION_RULE
value|(0x7<<0)
comment|/* BitField agg_vars7Various aggregative variables	0-NOP,1-EQ,2-NEQ,3-GT_CYC,4-GT_ABS,5-LT_CYC,6-LT_ABS */
define|#
directive|define
name|__XSTORM_FCOE_AG_CONTEXT_AGG_VAL11_DECISION_RULE_SHIFT
value|0
define|#
directive|define
name|__XSTORM_FCOE_AG_CONTEXT_AUX13_FLAG
value|(0x1<<3)
comment|/* BitField agg_vars7Various aggregative variables	auxiliary flag 13 */
define|#
directive|define
name|__XSTORM_FCOE_AG_CONTEXT_AUX13_FLAG_SHIFT
value|3
define|#
directive|define
name|__XSTORM_FCOE_AG_CONTEXT_QUEUE0_CF
value|(0x3<<4)
comment|/* BitField agg_vars7Various aggregative variables	auxiliary counter flag 18 */
define|#
directive|define
name|__XSTORM_FCOE_AG_CONTEXT_QUEUE0_CF_SHIFT
value|4
define|#
directive|define
name|XSTORM_FCOE_AG_CONTEXT_DECISION_RULE3
value|(0x3<<6)
comment|/* BitField agg_vars7Various aggregative variables	0-NOP,1-EQ,2-NEQ */
define|#
directive|define
name|XSTORM_FCOE_AG_CONTEXT_DECISION_RULE3_SHIFT
value|6
define|#
directive|define
name|XSTORM_FCOE_AG_CONTEXT_AUX1_CF
value|(0x3<<8)
comment|/* BitField agg_vars7Various aggregative variables	auxiliary counter flag 1 */
define|#
directive|define
name|XSTORM_FCOE_AG_CONTEXT_AUX1_CF_SHIFT
value|8
define|#
directive|define
name|__XSTORM_FCOE_AG_CONTEXT_RESERVED62
value|(0x1<<10)
comment|/* BitField agg_vars7Various aggregative variables	Mask the check of the completion sequence on retransmit */
define|#
directive|define
name|__XSTORM_FCOE_AG_CONTEXT_RESERVED62_SHIFT
value|10
define|#
directive|define
name|__XSTORM_FCOE_AG_CONTEXT_AUX1_CF_EN
value|(0x1<<11)
comment|/* BitField agg_vars7Various aggregative variables	Enable decision rules based on aux1_cf */
define|#
directive|define
name|__XSTORM_FCOE_AG_CONTEXT_AUX1_CF_EN_SHIFT
value|11
define|#
directive|define
name|__XSTORM_FCOE_AG_CONTEXT_AUX10_FLAG
value|(0x1<<12)
comment|/* BitField agg_vars7Various aggregative variables	auxiliary flag 10 */
define|#
directive|define
name|__XSTORM_FCOE_AG_CONTEXT_AUX10_FLAG_SHIFT
value|12
define|#
directive|define
name|__XSTORM_FCOE_AG_CONTEXT_AUX11_FLAG
value|(0x1<<13)
comment|/* BitField agg_vars7Various aggregative variables	auxiliary flag 11 */
define|#
directive|define
name|__XSTORM_FCOE_AG_CONTEXT_AUX11_FLAG_SHIFT
value|13
define|#
directive|define
name|__XSTORM_FCOE_AG_CONTEXT_AUX12_FLAG
value|(0x1<<14)
comment|/* BitField agg_vars7Various aggregative variables	auxiliary flag 12 */
define|#
directive|define
name|__XSTORM_FCOE_AG_CONTEXT_AUX12_FLAG_SHIFT
value|14
define|#
directive|define
name|__XSTORM_FCOE_AG_CONTEXT_AUX2_FLAG
value|(0x1<<15)
comment|/* BitField agg_vars7Various aggregative variables	auxiliary flag 2 */
define|#
directive|define
name|__XSTORM_FCOE_AG_CONTEXT_AUX2_FLAG_SHIFT
value|15
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|__agg_val11_th
comment|/* aggregated value 11 - threshold */
decl_stmt|;
name|uint16_t
name|__agg_val11
comment|/* aggregated value 11 */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|__agg_val11
comment|/* aggregated value 11 */
decl_stmt|;
name|uint16_t
name|__agg_val11_th
comment|/* aggregated value 11 - threshold */
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint8_t
name|__reserved1
decl_stmt|;
name|uint8_t
name|__agg_val6_th
comment|/* aggregated value 6 - threshold */
decl_stmt|;
name|uint16_t
name|__agg_val9
comment|/* aggregated value 9 */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|__agg_val9
comment|/* aggregated value 9 */
decl_stmt|;
name|uint8_t
name|__agg_val6_th
comment|/* aggregated value 6 - threshold */
decl_stmt|;
name|uint8_t
name|__reserved1
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|confq_cons
comment|/* CONFQ Consumer */
decl_stmt|;
name|uint16_t
name|confq_prod
comment|/* CONFQ Producer, updated by Ustorm - AggVal2 */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|confq_prod
comment|/* CONFQ Producer, updated by Ustorm - AggVal2 */
decl_stmt|;
name|uint16_t
name|confq_cons
comment|/* CONFQ Consumer */
decl_stmt|;
endif|#
directive|endif
name|uint32_t
name|agg_varint8_t
decl_stmt|;
define|#
directive|define
name|XSTORM_FCOE_AG_CONTEXT_AGG_MISC2
value|(0xFFFFFF<<0)
comment|/* BitField agg_varint8_tVarious aggregative variables	Misc aggregated variable 2 */
define|#
directive|define
name|XSTORM_FCOE_AG_CONTEXT_AGG_MISC2_SHIFT
value|0
define|#
directive|define
name|XSTORM_FCOE_AG_CONTEXT_AGG_MISC3
value|(0xFF<<24)
comment|/* BitField agg_varint8_tVarious aggregative variables	Misc aggregated variable 3 */
define|#
directive|define
name|XSTORM_FCOE_AG_CONTEXT_AGG_MISC3_SHIFT
value|24
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|__cache_wqe_db
comment|/* Misc aggregated variable 0 */
decl_stmt|;
name|uint16_t
name|sq_prod
comment|/* The SQ Producer updated by Xstorm after reading a bunch of WQEs into the context */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|sq_prod
comment|/* The SQ Producer updated by Xstorm after reading a bunch of WQEs into the context */
decl_stmt|;
name|uint16_t
name|__cache_wqe_db
comment|/* Misc aggregated variable 0 */
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint8_t
name|agg_val3
comment|/* Aggregated value 3 */
decl_stmt|;
name|uint8_t
name|agg_val6
comment|/* Aggregated value 6 */
decl_stmt|;
name|uint8_t
name|agg_val5_th
comment|/* Aggregated value 5 - threshold */
decl_stmt|;
name|uint8_t
name|agg_val5
comment|/* Aggregated value 5 */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint8_t
name|agg_val5
comment|/* Aggregated value 5 */
decl_stmt|;
name|uint8_t
name|agg_val5_th
comment|/* Aggregated value 5 - threshold */
decl_stmt|;
name|uint8_t
name|agg_val6
comment|/* Aggregated value 6 */
decl_stmt|;
name|uint8_t
name|agg_val3
comment|/* Aggregated value 3 */
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|__agg_misc1
comment|/* Spare value for aggregation. NOTE: this value is used in the retransmit decision rule if CmpSeqDecMask is 0. In that case it is intended to be CmpBdSize. */
decl_stmt|;
name|uint16_t
name|agg_limit1
comment|/* aggregated limit 1 */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|agg_limit1
comment|/* aggregated limit 1 */
decl_stmt|;
name|uint16_t
name|__agg_misc1
comment|/* Spare value for aggregation. NOTE: this value is used in the retransmit decision rule if CmpSeqDecMask is 0. In that case it is intended to be CmpBdSize. */
decl_stmt|;
endif|#
directive|endif
name|uint32_t
name|completion_seq
comment|/* The sequence number of the start completion point (BD) */
decl_stmt|;
name|uint32_t
name|confq_pbl_base_lo
comment|/* The CONFQ PBL base low address resides in host memory */
decl_stmt|;
name|uint32_t
name|confq_pbl_base_hi
comment|/* The CONFQ PBL base hihj address resides in host memory */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The tcp aggregative context section of Xstorm  */
end_comment

begin_struct
struct|struct
name|xstorm_tcp_tcp_ag_context_section
block|{
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint8_t
name|tcp_agg_vars1
decl_stmt|;
define|#
directive|define
name|__XSTORM_TCP_TCP_AG_CONTEXT_SECTION_SET_DA_TIMER_CF
value|(0x3<<0)
comment|/* BitField tcp_agg_vars1Various aggregative variables	Counter flag used to rewind the DA timer */
define|#
directive|define
name|__XSTORM_TCP_TCP_AG_CONTEXT_SECTION_SET_DA_TIMER_CF_SHIFT
value|0
define|#
directive|define
name|__XSTORM_TCP_TCP_AG_CONTEXT_SECTION_ACK_TO_FE_UPDATED
value|(0x3<<2)
comment|/* BitField tcp_agg_vars1Various aggregative variables	auxiliary counter flag 2 */
define|#
directive|define
name|__XSTORM_TCP_TCP_AG_CONTEXT_SECTION_ACK_TO_FE_UPDATED_SHIFT
value|2
define|#
directive|define
name|XSTORM_TCP_TCP_AG_CONTEXT_SECTION_SIDEBAND_SENT_CF
value|(0x3<<4)
comment|/* BitField tcp_agg_vars1Various aggregative variables	auxiliary counter flag 3 */
define|#
directive|define
name|XSTORM_TCP_TCP_AG_CONTEXT_SECTION_SIDEBAND_SENT_CF_SHIFT
value|4
define|#
directive|define
name|__XSTORM_TCP_TCP_AG_CONTEXT_SECTION_CLEAR_DA_TIMER_EN
value|(0x1<<6)
comment|/* BitField tcp_agg_vars1Various aggregative variables	If set enables sending clear commands as port of the DA decision rules */
define|#
directive|define
name|__XSTORM_TCP_TCP_AG_CONTEXT_SECTION_CLEAR_DA_TIMER_EN_SHIFT
value|6
define|#
directive|define
name|__XSTORM_TCP_TCP_AG_CONTEXT_SECTION_DA_EXPIRATION_FLAG
value|(0x1<<7)
comment|/* BitField tcp_agg_vars1Various aggregative variables	Indicates that there was a delayed ack timer expiration */
define|#
directive|define
name|__XSTORM_TCP_TCP_AG_CONTEXT_SECTION_DA_EXPIRATION_FLAG_SHIFT
value|7
name|uint8_t
name|__da_cnt
comment|/* Counts the number of ACK requests received from the TSTORM with no registration to QM. */
decl_stmt|;
name|uint16_t
name|mss
comment|/* MSS used for nagle algorithm and for transmission */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|mss
comment|/* MSS used for nagle algorithm and for transmission */
decl_stmt|;
name|uint8_t
name|__da_cnt
comment|/* Counts the number of ACK requests received from the TSTORM with no registration to QM. */
decl_stmt|;
name|uint8_t
name|tcp_agg_vars1
decl_stmt|;
define|#
directive|define
name|__XSTORM_TCP_TCP_AG_CONTEXT_SECTION_SET_DA_TIMER_CF
value|(0x3<<0)
comment|/* BitField tcp_agg_vars1Various aggregative variables	Counter flag used to rewind the DA timer */
define|#
directive|define
name|__XSTORM_TCP_TCP_AG_CONTEXT_SECTION_SET_DA_TIMER_CF_SHIFT
value|0
define|#
directive|define
name|__XSTORM_TCP_TCP_AG_CONTEXT_SECTION_ACK_TO_FE_UPDATED
value|(0x3<<2)
comment|/* BitField tcp_agg_vars1Various aggregative variables	auxiliary counter flag 2 */
define|#
directive|define
name|__XSTORM_TCP_TCP_AG_CONTEXT_SECTION_ACK_TO_FE_UPDATED_SHIFT
value|2
define|#
directive|define
name|XSTORM_TCP_TCP_AG_CONTEXT_SECTION_SIDEBAND_SENT_CF
value|(0x3<<4)
comment|/* BitField tcp_agg_vars1Various aggregative variables	auxiliary counter flag 3 */
define|#
directive|define
name|XSTORM_TCP_TCP_AG_CONTEXT_SECTION_SIDEBAND_SENT_CF_SHIFT
value|4
define|#
directive|define
name|__XSTORM_TCP_TCP_AG_CONTEXT_SECTION_CLEAR_DA_TIMER_EN
value|(0x1<<6)
comment|/* BitField tcp_agg_vars1Various aggregative variables	If set enables sending clear commands as port of the DA decision rules */
define|#
directive|define
name|__XSTORM_TCP_TCP_AG_CONTEXT_SECTION_CLEAR_DA_TIMER_EN_SHIFT
value|6
define|#
directive|define
name|__XSTORM_TCP_TCP_AG_CONTEXT_SECTION_DA_EXPIRATION_FLAG
value|(0x1<<7)
comment|/* BitField tcp_agg_vars1Various aggregative variables	Indicates that there was a delayed ack timer expiration */
define|#
directive|define
name|__XSTORM_TCP_TCP_AG_CONTEXT_SECTION_DA_EXPIRATION_FLAG_SHIFT
value|7
endif|#
directive|endif
name|uint32_t
name|snd_nxt
comment|/* The current sequence number to send */
decl_stmt|;
name|uint32_t
name|tx_wnd
comment|/* The Current transmission window in bytes */
decl_stmt|;
name|uint32_t
name|snd_una
comment|/* The current Send UNA sequence number */
decl_stmt|;
name|uint32_t
name|local_adv_wnd
comment|/* The current local advertised window to FE. */
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint8_t
name|__agg_val8_th
comment|/* aggregated value 8 - threshold */
decl_stmt|;
name|uint8_t
name|__tx_dest
comment|/* aggregated value 8 */
decl_stmt|;
name|uint16_t
name|tcp_agg_vars2
decl_stmt|;
define|#
directive|define
name|XSTORM_TCP_TCP_AG_CONTEXT_SECTION_TX_FIN_FLAG
value|(0x1<<0)
comment|/* BitField tcp_agg_vars2Various aggregative variables	Used in TOE to indicate that FIN is sent on a BD to bypass the naggle rule */
define|#
directive|define
name|XSTORM_TCP_TCP_AG_CONTEXT_SECTION_TX_FIN_FLAG_SHIFT
value|0
define|#
directive|define
name|__XSTORM_TCP_TCP_AG_CONTEXT_SECTION_TX_UNBLOCKED
value|(0x1<<1)
comment|/* BitField tcp_agg_vars2Various aggregative variables	Enables the tx window based decision */
define|#
directive|define
name|__XSTORM_TCP_TCP_AG_CONTEXT_SECTION_TX_UNBLOCKED_SHIFT
value|1
define|#
directive|define
name|__XSTORM_TCP_TCP_AG_CONTEXT_SECTION_DA_TIMER_ACTIVE
value|(0x1<<2)
comment|/* BitField tcp_agg_vars2Various aggregative variables	The DA Timer status. If set indicates that the delayed ACK timer is active. */
define|#
directive|define
name|__XSTORM_TCP_TCP_AG_CONTEXT_SECTION_DA_TIMER_ACTIVE_SHIFT
value|2
define|#
directive|define
name|__XSTORM_TCP_TCP_AG_CONTEXT_SECTION_AUX3_FLAG
value|(0x1<<3)
comment|/* BitField tcp_agg_vars2Various aggregative variables	auxiliary flag 3 */
define|#
directive|define
name|__XSTORM_TCP_TCP_AG_CONTEXT_SECTION_AUX3_FLAG_SHIFT
value|3
define|#
directive|define
name|__XSTORM_TCP_TCP_AG_CONTEXT_SECTION_AUX4_FLAG
value|(0x1<<4)
comment|/* BitField tcp_agg_vars2Various aggregative variables	auxiliary flag 4 */
define|#
directive|define
name|__XSTORM_TCP_TCP_AG_CONTEXT_SECTION_AUX4_FLAG_SHIFT
value|4
define|#
directive|define
name|XSTORM_TCP_TCP_AG_CONTEXT_SECTION_DA_ENABLE
value|(0x1<<5)
comment|/* BitField tcp_agg_vars2Various aggregative variables	Enable DA for the specific connection */
define|#
directive|define
name|XSTORM_TCP_TCP_AG_CONTEXT_SECTION_DA_ENABLE_SHIFT
value|5
define|#
directive|define
name|__XSTORM_TCP_TCP_AG_CONTEXT_SECTION_ACK_TO_FE_UPDATED_EN
value|(0x1<<6)
comment|/* BitField tcp_agg_vars2Various aggregative variables	Enable decision rules based on aux2_cf */
define|#
directive|define
name|__XSTORM_TCP_TCP_AG_CONTEXT_SECTION_ACK_TO_FE_UPDATED_EN_SHIFT
value|6
define|#
directive|define
name|XSTORM_TCP_TCP_AG_CONTEXT_SECTION_SIDEBAND_SENT_CF_EN
value|(0x1<<7)
comment|/* BitField tcp_agg_vars2Various aggregative variables	Enable decision rules based on aux3_cf */
define|#
directive|define
name|XSTORM_TCP_TCP_AG_CONTEXT_SECTION_SIDEBAND_SENT_CF_EN_SHIFT
value|7
define|#
directive|define
name|__XSTORM_TCP_TCP_AG_CONTEXT_SECTION_TX_FIN_FLAG_EN
value|(0x1<<8)
comment|/* BitField tcp_agg_vars2Various aggregative variables	Enable Decision rule based on tx_fin_flag */
define|#
directive|define
name|__XSTORM_TCP_TCP_AG_CONTEXT_SECTION_TX_FIN_FLAG_EN_SHIFT
value|8
define|#
directive|define
name|__XSTORM_TCP_TCP_AG_CONTEXT_SECTION_AUX1_FLAG
value|(0x1<<9)
comment|/* BitField tcp_agg_vars2Various aggregative variables	auxiliary flag 1 */
define|#
directive|define
name|__XSTORM_TCP_TCP_AG_CONTEXT_SECTION_AUX1_FLAG_SHIFT
value|9
define|#
directive|define
name|__XSTORM_TCP_TCP_AG_CONTEXT_SECTION_SET_RTO_CF
value|(0x3<<10)
comment|/* BitField tcp_agg_vars2Various aggregative variables	counter flag for setting the rto timer */
define|#
directive|define
name|__XSTORM_TCP_TCP_AG_CONTEXT_SECTION_SET_RTO_CF_SHIFT
value|10
define|#
directive|define
name|__XSTORM_TCP_TCP_AG_CONTEXT_SECTION_TS_TO_ECHO_UPDATED_CF
value|(0x3<<12)
comment|/* BitField tcp_agg_vars2Various aggregative variables	timestamp was updated counter flag */
define|#
directive|define
name|__XSTORM_TCP_TCP_AG_CONTEXT_SECTION_TS_TO_ECHO_UPDATED_CF_SHIFT
value|12
define|#
directive|define
name|__XSTORM_TCP_TCP_AG_CONTEXT_SECTION_TX_DEST_UPDATED_CF
value|(0x3<<14)
comment|/* BitField tcp_agg_vars2Various aggregative variables	auxiliary counter flag 8 */
define|#
directive|define
name|__XSTORM_TCP_TCP_AG_CONTEXT_SECTION_TX_DEST_UPDATED_CF_SHIFT
value|14
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|tcp_agg_vars2
decl_stmt|;
define|#
directive|define
name|XSTORM_TCP_TCP_AG_CONTEXT_SECTION_TX_FIN_FLAG
value|(0x1<<0)
comment|/* BitField tcp_agg_vars2Various aggregative variables	Used in TOE to indicate that FIN is sent on a BD to bypass the naggle rule */
define|#
directive|define
name|XSTORM_TCP_TCP_AG_CONTEXT_SECTION_TX_FIN_FLAG_SHIFT
value|0
define|#
directive|define
name|__XSTORM_TCP_TCP_AG_CONTEXT_SECTION_TX_UNBLOCKED
value|(0x1<<1)
comment|/* BitField tcp_agg_vars2Various aggregative variables	Enables the tx window based decision */
define|#
directive|define
name|__XSTORM_TCP_TCP_AG_CONTEXT_SECTION_TX_UNBLOCKED_SHIFT
value|1
define|#
directive|define
name|__XSTORM_TCP_TCP_AG_CONTEXT_SECTION_DA_TIMER_ACTIVE
value|(0x1<<2)
comment|/* BitField tcp_agg_vars2Various aggregative variables	The DA Timer status. If set indicates that the delayed ACK timer is active. */
define|#
directive|define
name|__XSTORM_TCP_TCP_AG_CONTEXT_SECTION_DA_TIMER_ACTIVE_SHIFT
value|2
define|#
directive|define
name|__XSTORM_TCP_TCP_AG_CONTEXT_SECTION_AUX3_FLAG
value|(0x1<<3)
comment|/* BitField tcp_agg_vars2Various aggregative variables	auxiliary flag 3 */
define|#
directive|define
name|__XSTORM_TCP_TCP_AG_CONTEXT_SECTION_AUX3_FLAG_SHIFT
value|3
define|#
directive|define
name|__XSTORM_TCP_TCP_AG_CONTEXT_SECTION_AUX4_FLAG
value|(0x1<<4)
comment|/* BitField tcp_agg_vars2Various aggregative variables	auxiliary flag 4 */
define|#
directive|define
name|__XSTORM_TCP_TCP_AG_CONTEXT_SECTION_AUX4_FLAG_SHIFT
value|4
define|#
directive|define
name|XSTORM_TCP_TCP_AG_CONTEXT_SECTION_DA_ENABLE
value|(0x1<<5)
comment|/* BitField tcp_agg_vars2Various aggregative variables	Enable DA for the specific connection */
define|#
directive|define
name|XSTORM_TCP_TCP_AG_CONTEXT_SECTION_DA_ENABLE_SHIFT
value|5
define|#
directive|define
name|__XSTORM_TCP_TCP_AG_CONTEXT_SECTION_ACK_TO_FE_UPDATED_EN
value|(0x1<<6)
comment|/* BitField tcp_agg_vars2Various aggregative variables	Enable decision rules based on aux2_cf */
define|#
directive|define
name|__XSTORM_TCP_TCP_AG_CONTEXT_SECTION_ACK_TO_FE_UPDATED_EN_SHIFT
value|6
define|#
directive|define
name|XSTORM_TCP_TCP_AG_CONTEXT_SECTION_SIDEBAND_SENT_CF_EN
value|(0x1<<7)
comment|/* BitField tcp_agg_vars2Various aggregative variables	Enable decision rules based on aux3_cf */
define|#
directive|define
name|XSTORM_TCP_TCP_AG_CONTEXT_SECTION_SIDEBAND_SENT_CF_EN_SHIFT
value|7
define|#
directive|define
name|__XSTORM_TCP_TCP_AG_CONTEXT_SECTION_TX_FIN_FLAG_EN
value|(0x1<<8)
comment|/* BitField tcp_agg_vars2Various aggregative variables	Enable Decision rule based on tx_fin_flag */
define|#
directive|define
name|__XSTORM_TCP_TCP_AG_CONTEXT_SECTION_TX_FIN_FLAG_EN_SHIFT
value|8
define|#
directive|define
name|__XSTORM_TCP_TCP_AG_CONTEXT_SECTION_AUX1_FLAG
value|(0x1<<9)
comment|/* BitField tcp_agg_vars2Various aggregative variables	auxiliary flag 1 */
define|#
directive|define
name|__XSTORM_TCP_TCP_AG_CONTEXT_SECTION_AUX1_FLAG_SHIFT
value|9
define|#
directive|define
name|__XSTORM_TCP_TCP_AG_CONTEXT_SECTION_SET_RTO_CF
value|(0x3<<10)
comment|/* BitField tcp_agg_vars2Various aggregative variables	counter flag for setting the rto timer */
define|#
directive|define
name|__XSTORM_TCP_TCP_AG_CONTEXT_SECTION_SET_RTO_CF_SHIFT
value|10
define|#
directive|define
name|__XSTORM_TCP_TCP_AG_CONTEXT_SECTION_TS_TO_ECHO_UPDATED_CF
value|(0x3<<12)
comment|/* BitField tcp_agg_vars2Various aggregative variables	timestamp was updated counter flag */
define|#
directive|define
name|__XSTORM_TCP_TCP_AG_CONTEXT_SECTION_TS_TO_ECHO_UPDATED_CF_SHIFT
value|12
define|#
directive|define
name|__XSTORM_TCP_TCP_AG_CONTEXT_SECTION_TX_DEST_UPDATED_CF
value|(0x3<<14)
comment|/* BitField tcp_agg_vars2Various aggregative variables	auxiliary counter flag 8 */
define|#
directive|define
name|__XSTORM_TCP_TCP_AG_CONTEXT_SECTION_TX_DEST_UPDATED_CF_SHIFT
value|14
name|uint8_t
name|__tx_dest
comment|/* aggregated value 8 */
decl_stmt|;
name|uint8_t
name|__agg_val8_th
comment|/* aggregated value 8 - threshold */
decl_stmt|;
endif|#
directive|endif
name|uint32_t
name|ack_to_far_end
comment|/* The ACK sequence to send to far end */
decl_stmt|;
name|uint32_t
name|rto_timer
comment|/* The RTO timer value */
decl_stmt|;
name|uint32_t
name|ka_timer
comment|/* The KA timer value */
decl_stmt|;
name|uint32_t
name|ts_to_echo
comment|/* The time stamp value to echo to far end */
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|__agg_val7_th
comment|/* aggregated value 7 - threshold */
decl_stmt|;
name|uint16_t
name|__agg_val7
comment|/* aggregated value 7 */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|__agg_val7
comment|/* aggregated value 7 */
decl_stmt|;
name|uint16_t
name|__agg_val7_th
comment|/* aggregated value 7 - threshold */
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint8_t
name|__tcp_agg_vars5
comment|/* Various aggregative variables*/
decl_stmt|;
name|uint8_t
name|__tcp_agg_vars4
comment|/* Various aggregative variables*/
decl_stmt|;
name|uint8_t
name|__tcp_agg_vars3
comment|/* Various aggregative variables*/
decl_stmt|;
name|uint8_t
name|__force_pure_ack_cnt
comment|/* The number of force ACK commands arrived from the TSTORM */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint8_t
name|__force_pure_ack_cnt
comment|/* The number of force ACK commands arrived from the TSTORM */
decl_stmt|;
name|uint8_t
name|__tcp_agg_vars3
comment|/* Various aggregative variables*/
decl_stmt|;
name|uint8_t
name|__tcp_agg_vars4
comment|/* Various aggregative variables*/
decl_stmt|;
name|uint8_t
name|__tcp_agg_vars5
comment|/* Various aggregative variables*/
decl_stmt|;
endif|#
directive|endif
name|uint32_t
name|tcp_agg_vars6
decl_stmt|;
define|#
directive|define
name|__XSTORM_TCP_TCP_AG_CONTEXT_SECTION_TS_TO_ECHO_CF_EN
value|(0x1<<0)
comment|/* BitField tcp_agg_vars6Various aggregative variables	Enable decision rules based on aux7_cf */
define|#
directive|define
name|__XSTORM_TCP_TCP_AG_CONTEXT_SECTION_TS_TO_ECHO_CF_EN_SHIFT
value|0
define|#
directive|define
name|__XSTORM_TCP_TCP_AG_CONTEXT_SECTION_TX_DEST_UPDATED_CF_EN
value|(0x1<<1)
comment|/* BitField tcp_agg_vars6Various aggregative variables	Enable decision rules based on aux8_cf */
define|#
directive|define
name|__XSTORM_TCP_TCP_AG_CONTEXT_SECTION_TX_DEST_UPDATED_CF_EN_SHIFT
value|1
define|#
directive|define
name|__XSTORM_TCP_TCP_AG_CONTEXT_SECTION_AUX9_CF_EN
value|(0x1<<2)
comment|/* BitField tcp_agg_vars6Various aggregative variables	Enable decision rules based on aux9_cf */
define|#
directive|define
name|__XSTORM_TCP_TCP_AG_CONTEXT_SECTION_AUX9_CF_EN_SHIFT
value|2
define|#
directive|define
name|__XSTORM_TCP_TCP_AG_CONTEXT_SECTION_AUX10_CF_EN
value|(0x1<<3)
comment|/* BitField tcp_agg_vars6Various aggregative variables	Enable decision rules based on aux10_cf */
define|#
directive|define
name|__XSTORM_TCP_TCP_AG_CONTEXT_SECTION_AUX10_CF_EN_SHIFT
value|3
define|#
directive|define
name|__XSTORM_TCP_TCP_AG_CONTEXT_SECTION_AUX6_FLAG
value|(0x1<<4)
comment|/* BitField tcp_agg_vars6Various aggregative variables	auxiliary flag 6 */
define|#
directive|define
name|__XSTORM_TCP_TCP_AG_CONTEXT_SECTION_AUX6_FLAG_SHIFT
value|4
define|#
directive|define
name|__XSTORM_TCP_TCP_AG_CONTEXT_SECTION_AUX7_FLAG
value|(0x1<<5)
comment|/* BitField tcp_agg_vars6Various aggregative variables	auxiliary flag 7 */
define|#
directive|define
name|__XSTORM_TCP_TCP_AG_CONTEXT_SECTION_AUX7_FLAG_SHIFT
value|5
define|#
directive|define
name|__XSTORM_TCP_TCP_AG_CONTEXT_SECTION_AUX5_CF
value|(0x3<<6)
comment|/* BitField tcp_agg_vars6Various aggregative variables	auxiliary counter flag 5 */
define|#
directive|define
name|__XSTORM_TCP_TCP_AG_CONTEXT_SECTION_AUX5_CF_SHIFT
value|6
define|#
directive|define
name|__XSTORM_TCP_TCP_AG_CONTEXT_SECTION_AUX9_CF
value|(0x3<<8)
comment|/* BitField tcp_agg_vars6Various aggregative variables	auxiliary counter flag 9 */
define|#
directive|define
name|__XSTORM_TCP_TCP_AG_CONTEXT_SECTION_AUX9_CF_SHIFT
value|8
define|#
directive|define
name|__XSTORM_TCP_TCP_AG_CONTEXT_SECTION_AUX10_CF
value|(0x3<<10)
comment|/* BitField tcp_agg_vars6Various aggregative variables	auxiliary counter flag 10 */
define|#
directive|define
name|__XSTORM_TCP_TCP_AG_CONTEXT_SECTION_AUX10_CF_SHIFT
value|10
define|#
directive|define
name|__XSTORM_TCP_TCP_AG_CONTEXT_SECTION_AUX11_CF
value|(0x3<<12)
comment|/* BitField tcp_agg_vars6Various aggregative variables	auxiliary counter flag 11 */
define|#
directive|define
name|__XSTORM_TCP_TCP_AG_CONTEXT_SECTION_AUX11_CF_SHIFT
value|12
define|#
directive|define
name|__XSTORM_TCP_TCP_AG_CONTEXT_SECTION_AUX12_CF
value|(0x3<<14)
comment|/* BitField tcp_agg_vars6Various aggregative variables	auxiliary counter flag 12 */
define|#
directive|define
name|__XSTORM_TCP_TCP_AG_CONTEXT_SECTION_AUX12_CF_SHIFT
value|14
define|#
directive|define
name|__XSTORM_TCP_TCP_AG_CONTEXT_SECTION_AUX13_CF
value|(0x3<<16)
comment|/* BitField tcp_agg_vars6Various aggregative variables	auxiliary counter flag 13 */
define|#
directive|define
name|__XSTORM_TCP_TCP_AG_CONTEXT_SECTION_AUX13_CF_SHIFT
value|16
define|#
directive|define
name|__XSTORM_TCP_TCP_AG_CONTEXT_SECTION_AUX14_CF
value|(0x3<<18)
comment|/* BitField tcp_agg_vars6Various aggregative variables	auxiliary counter flag 14 */
define|#
directive|define
name|__XSTORM_TCP_TCP_AG_CONTEXT_SECTION_AUX14_CF_SHIFT
value|18
define|#
directive|define
name|__XSTORM_TCP_TCP_AG_CONTEXT_SECTION_AUX15_CF
value|(0x3<<20)
comment|/* BitField tcp_agg_vars6Various aggregative variables	auxiliary counter flag 15 */
define|#
directive|define
name|__XSTORM_TCP_TCP_AG_CONTEXT_SECTION_AUX15_CF_SHIFT
value|20
define|#
directive|define
name|__XSTORM_TCP_TCP_AG_CONTEXT_SECTION_AUX16_CF
value|(0x3<<22)
comment|/* BitField tcp_agg_vars6Various aggregative variables	auxiliary counter flag 16 */
define|#
directive|define
name|__XSTORM_TCP_TCP_AG_CONTEXT_SECTION_AUX16_CF_SHIFT
value|22
define|#
directive|define
name|__XSTORM_TCP_TCP_AG_CONTEXT_SECTION_AUX17_CF
value|(0x3<<24)
comment|/* BitField tcp_agg_vars6Various aggregative variables	auxiliary counter flag 17 */
define|#
directive|define
name|__XSTORM_TCP_TCP_AG_CONTEXT_SECTION_AUX17_CF_SHIFT
value|24
define|#
directive|define
name|XSTORM_TCP_TCP_AG_CONTEXT_SECTION_ECE_FLAG
value|(0x1<<26)
comment|/* BitField tcp_agg_vars6Various aggregative variables	Can be also used as general purpose if ECN is not used */
define|#
directive|define
name|XSTORM_TCP_TCP_AG_CONTEXT_SECTION_ECE_FLAG_SHIFT
value|26
define|#
directive|define
name|__XSTORM_TCP_TCP_AG_CONTEXT_SECTION_RESERVED71
value|(0x1<<27)
comment|/* BitField tcp_agg_vars6Various aggregative variables	Can be also used as general purpose if ECN is not used */
define|#
directive|define
name|__XSTORM_TCP_TCP_AG_CONTEXT_SECTION_RESERVED71_SHIFT
value|27
define|#
directive|define
name|__XSTORM_TCP_TCP_AG_CONTEXT_SECTION_FORCE_PURE_ACK_CNT_DIRTY
value|(0x1<<28)
comment|/* BitField tcp_agg_vars6Various aggregative variables	This flag is set if the Force ACK count is set by the TSTORM. On QM output it is cleared. */
define|#
directive|define
name|__XSTORM_TCP_TCP_AG_CONTEXT_SECTION_FORCE_PURE_ACK_CNT_DIRTY_SHIFT
value|28
define|#
directive|define
name|__XSTORM_TCP_TCP_AG_CONTEXT_SECTION_TCP_AUTO_STOP_FLAG
value|(0x1<<29)
comment|/* BitField tcp_agg_vars6Various aggregative variables	Indicates that the connection is in autostop mode */
define|#
directive|define
name|__XSTORM_TCP_TCP_AG_CONTEXT_SECTION_TCP_AUTO_STOP_FLAG_SHIFT
value|29
define|#
directive|define
name|__XSTORM_TCP_TCP_AG_CONTEXT_SECTION_DO_TS_UPDATE_FLAG
value|(0x1<<30)
comment|/* BitField tcp_agg_vars6Various aggregative variables	This bit uses like a one shot that the TSTORM fires and the XSTORM arms. Used to allow a single TS update for each transmission */
define|#
directive|define
name|__XSTORM_TCP_TCP_AG_CONTEXT_SECTION_DO_TS_UPDATE_FLAG_SHIFT
value|30
define|#
directive|define
name|__XSTORM_TCP_TCP_AG_CONTEXT_SECTION_CANCEL_RETRANSMIT_FLAG
value|(0x1<<31)
comment|/* BitField tcp_agg_vars6Various aggregative variables	This bit is set by the TSTORM when need to cancel precious fast retransmit */
define|#
directive|define
name|__XSTORM_TCP_TCP_AG_CONTEXT_SECTION_CANCEL_RETRANSMIT_FLAG_SHIFT
value|31
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|__agg_misc6
comment|/* Misc aggregated variable 6 */
decl_stmt|;
name|uint16_t
name|__tcp_agg_vars7
comment|/* Various aggregative variables*/
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|__tcp_agg_vars7
comment|/* Various aggregative variables*/
decl_stmt|;
name|uint16_t
name|__agg_misc6
comment|/* Misc aggregated variable 6 */
decl_stmt|;
endif|#
directive|endif
name|uint32_t
name|__agg_val10
comment|/* aggregated value 10 */
decl_stmt|;
name|uint32_t
name|__agg_val10_th
comment|/* aggregated value 10 - threshold */
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|__reserved3
decl_stmt|;
name|uint8_t
name|__reserved2
decl_stmt|;
name|uint8_t
name|__da_only_cnt
comment|/* counts delayed acks and not window updates */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint8_t
name|__da_only_cnt
comment|/* counts delayed acks and not window updates */
decl_stmt|;
name|uint8_t
name|__reserved2
decl_stmt|;
name|uint16_t
name|__reserved3
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/*  * The iscsi aggregative context of Xstorm  */
end_comment

begin_struct
struct|struct
name|xstorm_iscsi_ag_context
block|{
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|agg_val1
comment|/* aggregated value 1 */
decl_stmt|;
name|uint8_t
name|agg_vars1
decl_stmt|;
define|#
directive|define
name|__XSTORM_ISCSI_AG_CONTEXT_EXISTS_IN_QM0
value|(0x1<<0)
comment|/* BitField agg_vars1Various aggregative variables	The connection is currently registered to the QM with queue index 0 */
define|#
directive|define
name|__XSTORM_ISCSI_AG_CONTEXT_EXISTS_IN_QM0_SHIFT
value|0
define|#
directive|define
name|XSTORM_ISCSI_AG_CONTEXT_EXISTS_IN_QM1
value|(0x1<<1)
comment|/* BitField agg_vars1Various aggregative variables	The connection is currently registered to the QM with queue index 1 */
define|#
directive|define
name|XSTORM_ISCSI_AG_CONTEXT_EXISTS_IN_QM1_SHIFT
value|1
define|#
directive|define
name|XSTORM_ISCSI_AG_CONTEXT_EXISTS_IN_QM2
value|(0x1<<2)
comment|/* BitField agg_vars1Various aggregative variables	The connection is currently registered to the QM with queue index 2 */
define|#
directive|define
name|XSTORM_ISCSI_AG_CONTEXT_EXISTS_IN_QM2_SHIFT
value|2
define|#
directive|define
name|XSTORM_ISCSI_AG_CONTEXT_EXISTS_IN_QM3
value|(0x1<<3)
comment|/* BitField agg_vars1Various aggregative variables	The connection is currently registered to the QM with queue index 3 */
define|#
directive|define
name|XSTORM_ISCSI_AG_CONTEXT_EXISTS_IN_QM3_SHIFT
value|3
define|#
directive|define
name|__XSTORM_ISCSI_AG_CONTEXT_MORE_TO_SEND_EN
value|(0x1<<4)
comment|/* BitField agg_vars1Various aggregative variables	Enables the decision rule of more_to_Send> 0 */
define|#
directive|define
name|__XSTORM_ISCSI_AG_CONTEXT_MORE_TO_SEND_EN_SHIFT
value|4
define|#
directive|define
name|XSTORM_ISCSI_AG_CONTEXT_NAGLE_EN
value|(0x1<<5)
comment|/* BitField agg_vars1Various aggregative variables	Enables the nagle decision */
define|#
directive|define
name|XSTORM_ISCSI_AG_CONTEXT_NAGLE_EN_SHIFT
value|5
define|#
directive|define
name|__XSTORM_ISCSI_AG_CONTEXT_DQ_SPARE_FLAG
value|(0x1<<6)
comment|/* BitField agg_vars1Various aggregative variables	Used for future indication by the Driver on a doorbell */
define|#
directive|define
name|__XSTORM_ISCSI_AG_CONTEXT_DQ_SPARE_FLAG_SHIFT
value|6
define|#
directive|define
name|__XSTORM_ISCSI_AG_CONTEXT_UNA_GT_NXT_EN
value|(0x1<<7)
comment|/* BitField agg_vars1Various aggregative variables	Enable decision rules based on equality between snd_una and snd_nxt */
define|#
directive|define
name|__XSTORM_ISCSI_AG_CONTEXT_UNA_GT_NXT_EN_SHIFT
value|7
name|uint8_t
name|state
comment|/* The state of the connection */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint8_t
name|state
comment|/* The state of the connection */
decl_stmt|;
name|uint8_t
name|agg_vars1
decl_stmt|;
define|#
directive|define
name|__XSTORM_ISCSI_AG_CONTEXT_EXISTS_IN_QM0
value|(0x1<<0)
comment|/* BitField agg_vars1Various aggregative variables	The connection is currently registered to the QM with queue index 0 */
define|#
directive|define
name|__XSTORM_ISCSI_AG_CONTEXT_EXISTS_IN_QM0_SHIFT
value|0
define|#
directive|define
name|XSTORM_ISCSI_AG_CONTEXT_EXISTS_IN_QM1
value|(0x1<<1)
comment|/* BitField agg_vars1Various aggregative variables	The connection is currently registered to the QM with queue index 1 */
define|#
directive|define
name|XSTORM_ISCSI_AG_CONTEXT_EXISTS_IN_QM1_SHIFT
value|1
define|#
directive|define
name|XSTORM_ISCSI_AG_CONTEXT_EXISTS_IN_QM2
value|(0x1<<2)
comment|/* BitField agg_vars1Various aggregative variables	The connection is currently registered to the QM with queue index 2 */
define|#
directive|define
name|XSTORM_ISCSI_AG_CONTEXT_EXISTS_IN_QM2_SHIFT
value|2
define|#
directive|define
name|XSTORM_ISCSI_AG_CONTEXT_EXISTS_IN_QM3
value|(0x1<<3)
comment|/* BitField agg_vars1Various aggregative variables	The connection is currently registered to the QM with queue index 3 */
define|#
directive|define
name|XSTORM_ISCSI_AG_CONTEXT_EXISTS_IN_QM3_SHIFT
value|3
define|#
directive|define
name|__XSTORM_ISCSI_AG_CONTEXT_MORE_TO_SEND_EN
value|(0x1<<4)
comment|/* BitField agg_vars1Various aggregative variables	Enables the decision rule of more_to_Send> 0 */
define|#
directive|define
name|__XSTORM_ISCSI_AG_CONTEXT_MORE_TO_SEND_EN_SHIFT
value|4
define|#
directive|define
name|XSTORM_ISCSI_AG_CONTEXT_NAGLE_EN
value|(0x1<<5)
comment|/* BitField agg_vars1Various aggregative variables	Enables the nagle decision */
define|#
directive|define
name|XSTORM_ISCSI_AG_CONTEXT_NAGLE_EN_SHIFT
value|5
define|#
directive|define
name|__XSTORM_ISCSI_AG_CONTEXT_DQ_SPARE_FLAG
value|(0x1<<6)
comment|/* BitField agg_vars1Various aggregative variables	Used for future indication by the Driver on a doorbell */
define|#
directive|define
name|__XSTORM_ISCSI_AG_CONTEXT_DQ_SPARE_FLAG_SHIFT
value|6
define|#
directive|define
name|__XSTORM_ISCSI_AG_CONTEXT_UNA_GT_NXT_EN
value|(0x1<<7)
comment|/* BitField agg_vars1Various aggregative variables	Enable decision rules based on equality between snd_una and snd_nxt */
define|#
directive|define
name|__XSTORM_ISCSI_AG_CONTEXT_UNA_GT_NXT_EN_SHIFT
value|7
name|uint16_t
name|agg_val1
comment|/* aggregated value 1 */
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint8_t
name|cdu_reserved
comment|/* Used by the CDU for validation and debugging */
decl_stmt|;
name|uint8_t
name|__agg_vars4
comment|/* Various aggregative variables*/
decl_stmt|;
name|uint8_t
name|agg_vars3
decl_stmt|;
define|#
directive|define
name|XSTORM_ISCSI_AG_CONTEXT_PHYSICAL_QUEUE_NUM2
value|(0x3F<<0)
comment|/* BitField agg_vars3Various aggregative variables	The physical queue number of queue index 2 */
define|#
directive|define
name|XSTORM_ISCSI_AG_CONTEXT_PHYSICAL_QUEUE_NUM2_SHIFT
value|0
define|#
directive|define
name|__XSTORM_ISCSI_AG_CONTEXT_RX_TS_EN_CF
value|(0x3<<6)
comment|/* BitField agg_vars3Various aggregative variables	auxiliary counter flag 19 */
define|#
directive|define
name|__XSTORM_ISCSI_AG_CONTEXT_RX_TS_EN_CF_SHIFT
value|6
name|uint8_t
name|agg_vars2
decl_stmt|;
define|#
directive|define
name|__XSTORM_ISCSI_AG_CONTEXT_DQ_CF
value|(0x3<<0)
comment|/* BitField agg_vars2Various aggregative variables	auxiliary counter flag 4 */
define|#
directive|define
name|__XSTORM_ISCSI_AG_CONTEXT_DQ_CF_SHIFT
value|0
define|#
directive|define
name|__XSTORM_ISCSI_AG_CONTEXT_DQ_SPARE_FLAG_EN
value|(0x1<<2)
comment|/* BitField agg_vars2Various aggregative variables	Enable decision rule based on dq_spare_flag */
define|#
directive|define
name|__XSTORM_ISCSI_AG_CONTEXT_DQ_SPARE_FLAG_EN_SHIFT
value|2
define|#
directive|define
name|__XSTORM_ISCSI_AG_CONTEXT_AUX8_FLAG
value|(0x1<<3)
comment|/* BitField agg_vars2Various aggregative variables	auxiliary flag 8 */
define|#
directive|define
name|__XSTORM_ISCSI_AG_CONTEXT_AUX8_FLAG_SHIFT
value|3
define|#
directive|define
name|__XSTORM_ISCSI_AG_CONTEXT_AUX9_FLAG
value|(0x1<<4)
comment|/* BitField agg_vars2Various aggregative variables	auxiliary flag 9 */
define|#
directive|define
name|__XSTORM_ISCSI_AG_CONTEXT_AUX9_FLAG_SHIFT
value|4
define|#
directive|define
name|XSTORM_ISCSI_AG_CONTEXT_DECISION_RULE1
value|(0x3<<5)
comment|/* BitField agg_vars2Various aggregative variables	0-NOP,1-EQ,2-NEQ */
define|#
directive|define
name|XSTORM_ISCSI_AG_CONTEXT_DECISION_RULE1_SHIFT
value|5
define|#
directive|define
name|__XSTORM_ISCSI_AG_CONTEXT_DQ_CF_EN
value|(0x1<<7)
comment|/* BitField agg_vars2Various aggregative variables	Enable decision rules based on aux4_cf */
define|#
directive|define
name|__XSTORM_ISCSI_AG_CONTEXT_DQ_CF_EN_SHIFT
value|7
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint8_t
name|agg_vars2
decl_stmt|;
define|#
directive|define
name|__XSTORM_ISCSI_AG_CONTEXT_DQ_CF
value|(0x3<<0)
comment|/* BitField agg_vars2Various aggregative variables	auxiliary counter flag 4 */
define|#
directive|define
name|__XSTORM_ISCSI_AG_CONTEXT_DQ_CF_SHIFT
value|0
define|#
directive|define
name|__XSTORM_ISCSI_AG_CONTEXT_DQ_SPARE_FLAG_EN
value|(0x1<<2)
comment|/* BitField agg_vars2Various aggregative variables	Enable decision rule based on dq_spare_flag */
define|#
directive|define
name|__XSTORM_ISCSI_AG_CONTEXT_DQ_SPARE_FLAG_EN_SHIFT
value|2
define|#
directive|define
name|__XSTORM_ISCSI_AG_CONTEXT_AUX8_FLAG
value|(0x1<<3)
comment|/* BitField agg_vars2Various aggregative variables	auxiliary flag 8 */
define|#
directive|define
name|__XSTORM_ISCSI_AG_CONTEXT_AUX8_FLAG_SHIFT
value|3
define|#
directive|define
name|__XSTORM_ISCSI_AG_CONTEXT_AUX9_FLAG
value|(0x1<<4)
comment|/* BitField agg_vars2Various aggregative variables	auxiliary flag 9 */
define|#
directive|define
name|__XSTORM_ISCSI_AG_CONTEXT_AUX9_FLAG_SHIFT
value|4
define|#
directive|define
name|XSTORM_ISCSI_AG_CONTEXT_DECISION_RULE1
value|(0x3<<5)
comment|/* BitField agg_vars2Various aggregative variables	0-NOP,1-EQ,2-NEQ */
define|#
directive|define
name|XSTORM_ISCSI_AG_CONTEXT_DECISION_RULE1_SHIFT
value|5
define|#
directive|define
name|__XSTORM_ISCSI_AG_CONTEXT_DQ_CF_EN
value|(0x1<<7)
comment|/* BitField agg_vars2Various aggregative variables	Enable decision rules based on aux4_cf */
define|#
directive|define
name|__XSTORM_ISCSI_AG_CONTEXT_DQ_CF_EN_SHIFT
value|7
name|uint8_t
name|agg_vars3
decl_stmt|;
define|#
directive|define
name|XSTORM_ISCSI_AG_CONTEXT_PHYSICAL_QUEUE_NUM2
value|(0x3F<<0)
comment|/* BitField agg_vars3Various aggregative variables	The physical queue number of queue index 2 */
define|#
directive|define
name|XSTORM_ISCSI_AG_CONTEXT_PHYSICAL_QUEUE_NUM2_SHIFT
value|0
define|#
directive|define
name|__XSTORM_ISCSI_AG_CONTEXT_RX_TS_EN_CF
value|(0x3<<6)
comment|/* BitField agg_vars3Various aggregative variables	auxiliary counter flag 19 */
define|#
directive|define
name|__XSTORM_ISCSI_AG_CONTEXT_RX_TS_EN_CF_SHIFT
value|6
name|uint8_t
name|__agg_vars4
comment|/* Various aggregative variables*/
decl_stmt|;
name|uint8_t
name|cdu_reserved
comment|/* Used by the CDU for validation and debugging */
decl_stmt|;
endif|#
directive|endif
name|uint32_t
name|more_to_send
comment|/* The number of bytes left to send */
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|agg_vars5
decl_stmt|;
define|#
directive|define
name|XSTORM_ISCSI_AG_CONTEXT_DECISION_RULE5
value|(0x3<<0)
comment|/* BitField agg_vars5Various aggregative variables	0-NOP,1-EQ,2-NEQ */
define|#
directive|define
name|XSTORM_ISCSI_AG_CONTEXT_DECISION_RULE5_SHIFT
value|0
define|#
directive|define
name|XSTORM_ISCSI_AG_CONTEXT_PHYSICAL_QUEUE_NUM0
value|(0x3F<<2)
comment|/* BitField agg_vars5Various aggregative variables	The physical queue number of queue index 0 */
define|#
directive|define
name|XSTORM_ISCSI_AG_CONTEXT_PHYSICAL_QUEUE_NUM0_SHIFT
value|2
define|#
directive|define
name|XSTORM_ISCSI_AG_CONTEXT_PHYSICAL_QUEUE_NUM1
value|(0x3F<<8)
comment|/* BitField agg_vars5Various aggregative variables	The physical queue number of queue index 1 */
define|#
directive|define
name|XSTORM_ISCSI_AG_CONTEXT_PHYSICAL_QUEUE_NUM1_SHIFT
value|8
define|#
directive|define
name|XSTORM_ISCSI_AG_CONTEXT_DECISION_RULE2
value|(0x3<<14)
comment|/* BitField agg_vars5Various aggregative variables	0-NOP,1-EQ,2-NEQ */
define|#
directive|define
name|XSTORM_ISCSI_AG_CONTEXT_DECISION_RULE2_SHIFT
value|14
name|uint16_t
name|sq_cons
comment|/* aggregated value 4 - threshold */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|sq_cons
comment|/* aggregated value 4 - threshold */
decl_stmt|;
name|uint16_t
name|agg_vars5
decl_stmt|;
define|#
directive|define
name|XSTORM_ISCSI_AG_CONTEXT_DECISION_RULE5
value|(0x3<<0)
comment|/* BitField agg_vars5Various aggregative variables	0-NOP,1-EQ,2-NEQ */
define|#
directive|define
name|XSTORM_ISCSI_AG_CONTEXT_DECISION_RULE5_SHIFT
value|0
define|#
directive|define
name|XSTORM_ISCSI_AG_CONTEXT_PHYSICAL_QUEUE_NUM0
value|(0x3F<<2)
comment|/* BitField agg_vars5Various aggregative variables	The physical queue number of queue index 0 */
define|#
directive|define
name|XSTORM_ISCSI_AG_CONTEXT_PHYSICAL_QUEUE_NUM0_SHIFT
value|2
define|#
directive|define
name|XSTORM_ISCSI_AG_CONTEXT_PHYSICAL_QUEUE_NUM1
value|(0x3F<<8)
comment|/* BitField agg_vars5Various aggregative variables	The physical queue number of queue index 1 */
define|#
directive|define
name|XSTORM_ISCSI_AG_CONTEXT_PHYSICAL_QUEUE_NUM1_SHIFT
value|8
define|#
directive|define
name|XSTORM_ISCSI_AG_CONTEXT_DECISION_RULE2
value|(0x3<<14)
comment|/* BitField agg_vars5Various aggregative variables	0-NOP,1-EQ,2-NEQ */
define|#
directive|define
name|XSTORM_ISCSI_AG_CONTEXT_DECISION_RULE2_SHIFT
value|14
endif|#
directive|endif
name|struct
name|xstorm_tcp_tcp_ag_context_section
name|tcp
comment|/* TCP context section, shared in TOE and ISCSI */
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|agg_vars7
decl_stmt|;
define|#
directive|define
name|__XSTORM_ISCSI_AG_CONTEXT_AGG_VAL11_DECISION_RULE
value|(0x7<<0)
comment|/* BitField agg_vars7Various aggregative variables	0-NOP,1-EQ,2-NEQ,3-GT_CYC,4-GT_ABS,5-LT_CYC,6-LT_ABS */
define|#
directive|define
name|__XSTORM_ISCSI_AG_CONTEXT_AGG_VAL11_DECISION_RULE_SHIFT
value|0
define|#
directive|define
name|__XSTORM_ISCSI_AG_CONTEXT_AUX13_FLAG
value|(0x1<<3)
comment|/* BitField agg_vars7Various aggregative variables	auxiliary flag 13 */
define|#
directive|define
name|__XSTORM_ISCSI_AG_CONTEXT_AUX13_FLAG_SHIFT
value|3
define|#
directive|define
name|__XSTORM_ISCSI_AG_CONTEXT_STORMS_SYNC_CF
value|(0x3<<4)
comment|/* BitField agg_vars7Various aggregative variables	Sync Tstorm and Xstorm */
define|#
directive|define
name|__XSTORM_ISCSI_AG_CONTEXT_STORMS_SYNC_CF_SHIFT
value|4
define|#
directive|define
name|XSTORM_ISCSI_AG_CONTEXT_DECISION_RULE3
value|(0x3<<6)
comment|/* BitField agg_vars7Various aggregative variables	0-NOP,1-EQ,2-NEQ */
define|#
directive|define
name|XSTORM_ISCSI_AG_CONTEXT_DECISION_RULE3_SHIFT
value|6
define|#
directive|define
name|XSTORM_ISCSI_AG_CONTEXT_AUX1_CF
value|(0x3<<8)
comment|/* BitField agg_vars7Various aggregative variables	auxiliary counter flag 1 */
define|#
directive|define
name|XSTORM_ISCSI_AG_CONTEXT_AUX1_CF_SHIFT
value|8
define|#
directive|define
name|__XSTORM_ISCSI_AG_CONTEXT_COMPLETION_SEQ_DECISION_MASK
value|(0x1<<10)
comment|/* BitField agg_vars7Various aggregative variables	Mask the check of the completion sequence on retransmit */
define|#
directive|define
name|__XSTORM_ISCSI_AG_CONTEXT_COMPLETION_SEQ_DECISION_MASK_SHIFT
value|10
define|#
directive|define
name|__XSTORM_ISCSI_AG_CONTEXT_AUX1_CF_EN
value|(0x1<<11)
comment|/* BitField agg_vars7Various aggregative variables	Enable decision rules based on aux1_cf */
define|#
directive|define
name|__XSTORM_ISCSI_AG_CONTEXT_AUX1_CF_EN_SHIFT
value|11
define|#
directive|define
name|__XSTORM_ISCSI_AG_CONTEXT_AUX10_FLAG
value|(0x1<<12)
comment|/* BitField agg_vars7Various aggregative variables	auxiliary flag 10 */
define|#
directive|define
name|__XSTORM_ISCSI_AG_CONTEXT_AUX10_FLAG_SHIFT
value|12
define|#
directive|define
name|__XSTORM_ISCSI_AG_CONTEXT_AUX11_FLAG
value|(0x1<<13)
comment|/* BitField agg_vars7Various aggregative variables	auxiliary flag 11 */
define|#
directive|define
name|__XSTORM_ISCSI_AG_CONTEXT_AUX11_FLAG_SHIFT
value|13
define|#
directive|define
name|__XSTORM_ISCSI_AG_CONTEXT_AUX12_FLAG
value|(0x1<<14)
comment|/* BitField agg_vars7Various aggregative variables	auxiliary flag 12 */
define|#
directive|define
name|__XSTORM_ISCSI_AG_CONTEXT_AUX12_FLAG_SHIFT
value|14
define|#
directive|define
name|__XSTORM_ISCSI_AG_CONTEXT_RX_WND_SCL_EN
value|(0x1<<15)
comment|/* BitField agg_vars7Various aggregative variables	auxiliary flag 2 */
define|#
directive|define
name|__XSTORM_ISCSI_AG_CONTEXT_RX_WND_SCL_EN_SHIFT
value|15
name|uint8_t
name|agg_val3_th
comment|/* Aggregated value 3 - threshold */
decl_stmt|;
name|uint8_t
name|agg_vars6
decl_stmt|;
define|#
directive|define
name|XSTORM_ISCSI_AG_CONTEXT_DECISION_RULE6
value|(0x7<<0)
comment|/* BitField agg_vars6Various aggregative variables	0-NOP,1-EQ,2-NEQ,3-GT_CYC,4-GT_ABS,5-LT_CYC,6-LT_ABS */
define|#
directive|define
name|XSTORM_ISCSI_AG_CONTEXT_DECISION_RULE6_SHIFT
value|0
define|#
directive|define
name|XSTORM_ISCSI_AG_CONTEXT_DECISION_RULE7
value|(0x7<<3)
comment|/* BitField agg_vars6Various aggregative variables	0-NOP,1-EQ,2-NEQ,3-GT_CYC,4-GT_ABS,5-LT_CYC,6-LT_ABS */
define|#
directive|define
name|XSTORM_ISCSI_AG_CONTEXT_DECISION_RULE7_SHIFT
value|3
define|#
directive|define
name|XSTORM_ISCSI_AG_CONTEXT_DECISION_RULE4
value|(0x3<<6)
comment|/* BitField agg_vars6Various aggregative variables	0-NOP,1-EQ,2-NEQ */
define|#
directive|define
name|XSTORM_ISCSI_AG_CONTEXT_DECISION_RULE4_SHIFT
value|6
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint8_t
name|agg_vars6
decl_stmt|;
define|#
directive|define
name|XSTORM_ISCSI_AG_CONTEXT_DECISION_RULE6
value|(0x7<<0)
comment|/* BitField agg_vars6Various aggregative variables	0-NOP,1-EQ,2-NEQ,3-GT_CYC,4-GT_ABS,5-LT_CYC,6-LT_ABS */
define|#
directive|define
name|XSTORM_ISCSI_AG_CONTEXT_DECISION_RULE6_SHIFT
value|0
define|#
directive|define
name|XSTORM_ISCSI_AG_CONTEXT_DECISION_RULE7
value|(0x7<<3)
comment|/* BitField agg_vars6Various aggregative variables	0-NOP,1-EQ,2-NEQ,3-GT_CYC,4-GT_ABS,5-LT_CYC,6-LT_ABS */
define|#
directive|define
name|XSTORM_ISCSI_AG_CONTEXT_DECISION_RULE7_SHIFT
value|3
define|#
directive|define
name|XSTORM_ISCSI_AG_CONTEXT_DECISION_RULE4
value|(0x3<<6)
comment|/* BitField agg_vars6Various aggregative variables	0-NOP,1-EQ,2-NEQ */
define|#
directive|define
name|XSTORM_ISCSI_AG_CONTEXT_DECISION_RULE4_SHIFT
value|6
name|uint8_t
name|agg_val3_th
comment|/* Aggregated value 3 - threshold */
decl_stmt|;
name|uint16_t
name|agg_vars7
decl_stmt|;
define|#
directive|define
name|__XSTORM_ISCSI_AG_CONTEXT_AGG_VAL11_DECISION_RULE
value|(0x7<<0)
comment|/* BitField agg_vars7Various aggregative variables	0-NOP,1-EQ,2-NEQ,3-GT_CYC,4-GT_ABS,5-LT_CYC,6-LT_ABS */
define|#
directive|define
name|__XSTORM_ISCSI_AG_CONTEXT_AGG_VAL11_DECISION_RULE_SHIFT
value|0
define|#
directive|define
name|__XSTORM_ISCSI_AG_CONTEXT_AUX13_FLAG
value|(0x1<<3)
comment|/* BitField agg_vars7Various aggregative variables	auxiliary flag 13 */
define|#
directive|define
name|__XSTORM_ISCSI_AG_CONTEXT_AUX13_FLAG_SHIFT
value|3
define|#
directive|define
name|__XSTORM_ISCSI_AG_CONTEXT_STORMS_SYNC_CF
value|(0x3<<4)
comment|/* BitField agg_vars7Various aggregative variables	Sync Tstorm and Xstorm */
define|#
directive|define
name|__XSTORM_ISCSI_AG_CONTEXT_STORMS_SYNC_CF_SHIFT
value|4
define|#
directive|define
name|XSTORM_ISCSI_AG_CONTEXT_DECISION_RULE3
value|(0x3<<6)
comment|/* BitField agg_vars7Various aggregative variables	0-NOP,1-EQ,2-NEQ */
define|#
directive|define
name|XSTORM_ISCSI_AG_CONTEXT_DECISION_RULE3_SHIFT
value|6
define|#
directive|define
name|XSTORM_ISCSI_AG_CONTEXT_AUX1_CF
value|(0x3<<8)
comment|/* BitField agg_vars7Various aggregative variables	auxiliary counter flag 1 */
define|#
directive|define
name|XSTORM_ISCSI_AG_CONTEXT_AUX1_CF_SHIFT
value|8
define|#
directive|define
name|__XSTORM_ISCSI_AG_CONTEXT_COMPLETION_SEQ_DECISION_MASK
value|(0x1<<10)
comment|/* BitField agg_vars7Various aggregative variables	Mask the check of the completion sequence on retransmit */
define|#
directive|define
name|__XSTORM_ISCSI_AG_CONTEXT_COMPLETION_SEQ_DECISION_MASK_SHIFT
value|10
define|#
directive|define
name|__XSTORM_ISCSI_AG_CONTEXT_AUX1_CF_EN
value|(0x1<<11)
comment|/* BitField agg_vars7Various aggregative variables	Enable decision rules based on aux1_cf */
define|#
directive|define
name|__XSTORM_ISCSI_AG_CONTEXT_AUX1_CF_EN_SHIFT
value|11
define|#
directive|define
name|__XSTORM_ISCSI_AG_CONTEXT_AUX10_FLAG
value|(0x1<<12)
comment|/* BitField agg_vars7Various aggregative variables	auxiliary flag 10 */
define|#
directive|define
name|__XSTORM_ISCSI_AG_CONTEXT_AUX10_FLAG_SHIFT
value|12
define|#
directive|define
name|__XSTORM_ISCSI_AG_CONTEXT_AUX11_FLAG
value|(0x1<<13)
comment|/* BitField agg_vars7Various aggregative variables	auxiliary flag 11 */
define|#
directive|define
name|__XSTORM_ISCSI_AG_CONTEXT_AUX11_FLAG_SHIFT
value|13
define|#
directive|define
name|__XSTORM_ISCSI_AG_CONTEXT_AUX12_FLAG
value|(0x1<<14)
comment|/* BitField agg_vars7Various aggregative variables	auxiliary flag 12 */
define|#
directive|define
name|__XSTORM_ISCSI_AG_CONTEXT_AUX12_FLAG_SHIFT
value|14
define|#
directive|define
name|__XSTORM_ISCSI_AG_CONTEXT_RX_WND_SCL_EN
value|(0x1<<15)
comment|/* BitField agg_vars7Various aggregative variables	auxiliary flag 2 */
define|#
directive|define
name|__XSTORM_ISCSI_AG_CONTEXT_RX_WND_SCL_EN_SHIFT
value|15
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|__agg_val11_th
comment|/* aggregated value 11 - threshold */
decl_stmt|;
name|uint16_t
name|__gen_data
comment|/* Used for Iscsi. In connection establishment, it uses as rxMss, and in connection termination, it uses as command Id: 1=L5CM_TX_ACK_ON_FIN_CMD 2=L5CM_SET_MSL_TIMER_CMD 3=L5CM_TX_RST_CMD */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|__gen_data
comment|/* Used for Iscsi. In connection establishment, it uses as rxMss, and in connection termination, it uses as command Id: 1=L5CM_TX_ACK_ON_FIN_CMD 2=L5CM_SET_MSL_TIMER_CMD 3=L5CM_TX_RST_CMD */
decl_stmt|;
name|uint16_t
name|__agg_val11_th
comment|/* aggregated value 11 - threshold */
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint8_t
name|__reserved1
decl_stmt|;
name|uint8_t
name|__agg_val6_th
comment|/* aggregated value 6 - threshold */
decl_stmt|;
name|uint16_t
name|__agg_val9
comment|/* aggregated value 9 */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|__agg_val9
comment|/* aggregated value 9 */
decl_stmt|;
name|uint8_t
name|__agg_val6_th
comment|/* aggregated value 6 - threshold */
decl_stmt|;
name|uint8_t
name|__reserved1
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|hq_prod
comment|/* The HQ producer threashold to compare the HQ consumer, which is the current HQ producer +1 - AggVal2Th */
decl_stmt|;
name|uint16_t
name|hq_cons
comment|/* HQ Consumer, updated by Cstorm - AggVal2 */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|hq_cons
comment|/* HQ Consumer, updated by Cstorm - AggVal2 */
decl_stmt|;
name|uint16_t
name|hq_prod
comment|/* The HQ producer threashold to compare the HQ consumer, which is the current HQ producer +1 - AggVal2Th */
decl_stmt|;
endif|#
directive|endif
name|uint32_t
name|agg_varint8_t
decl_stmt|;
define|#
directive|define
name|XSTORM_ISCSI_AG_CONTEXT_AGG_MISC2
value|(0xFFFFFF<<0)
comment|/* BitField agg_varint8_tVarious aggregative variables	Misc aggregated variable 2 */
define|#
directive|define
name|XSTORM_ISCSI_AG_CONTEXT_AGG_MISC2_SHIFT
value|0
define|#
directive|define
name|XSTORM_ISCSI_AG_CONTEXT_AGG_MISC3
value|(0xFF<<24)
comment|/* BitField agg_varint8_tVarious aggregative variables	Misc aggregated variable 3 */
define|#
directive|define
name|XSTORM_ISCSI_AG_CONTEXT_AGG_MISC3_SHIFT
value|24
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|r2tq_prod
comment|/* Misc aggregated variable 0 */
decl_stmt|;
name|uint16_t
name|sq_prod
comment|/* SQ Producer */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|sq_prod
comment|/* SQ Producer */
decl_stmt|;
name|uint16_t
name|r2tq_prod
comment|/* Misc aggregated variable 0 */
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint8_t
name|agg_val3
comment|/* Aggregated value 3 */
decl_stmt|;
name|uint8_t
name|agg_val6
comment|/* Aggregated value 6 */
decl_stmt|;
name|uint8_t
name|agg_val5_th
comment|/* Aggregated value 5 - threshold */
decl_stmt|;
name|uint8_t
name|agg_val5
comment|/* Aggregated value 5 */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint8_t
name|agg_val5
comment|/* Aggregated value 5 */
decl_stmt|;
name|uint8_t
name|agg_val5_th
comment|/* Aggregated value 5 - threshold */
decl_stmt|;
name|uint8_t
name|agg_val6
comment|/* Aggregated value 6 */
decl_stmt|;
name|uint8_t
name|agg_val3
comment|/* Aggregated value 3 */
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|__agg_misc1
comment|/* Spare value for aggregation. NOTE: this value is used in the retransmit decision rule if CmpSeqDecMask is 0. In that case it is intended to be CmpBdSize. */
decl_stmt|;
name|uint16_t
name|agg_limit1
comment|/* aggregated limit 1 */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|agg_limit1
comment|/* aggregated limit 1 */
decl_stmt|;
name|uint16_t
name|__agg_misc1
comment|/* Spare value for aggregation. NOTE: this value is used in the retransmit decision rule if CmpSeqDecMask is 0. In that case it is intended to be CmpBdSize. */
decl_stmt|;
endif|#
directive|endif
name|uint32_t
name|hq_cons_tcp_seq
comment|/* TCP sequence of the HQ BD pointed by hq_cons */
decl_stmt|;
name|uint32_t
name|exp_stat_sn
comment|/* expected status SN, updated by Ustorm */
decl_stmt|;
name|uint32_t
name|rst_seq_num
comment|/* spare aggregated variable 5 */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The toe aggregative context section of Xstorm  */
end_comment

begin_struct
struct|struct
name|xstorm_toe_tcp_ag_context_section
block|{
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint8_t
name|tcp_agg_vars1
decl_stmt|;
define|#
directive|define
name|__XSTORM_TOE_TCP_AG_CONTEXT_SECTION_SET_DA_TIMER_CF
value|(0x3<<0)
comment|/* BitField tcp_agg_vars1Various aggregative variables	Counter flag used to rewind the DA timer */
define|#
directive|define
name|__XSTORM_TOE_TCP_AG_CONTEXT_SECTION_SET_DA_TIMER_CF_SHIFT
value|0
define|#
directive|define
name|__XSTORM_TOE_TCP_AG_CONTEXT_SECTION_ACK_TO_FE_UPDATED
value|(0x3<<2)
comment|/* BitField tcp_agg_vars1Various aggregative variables	auxiliary counter flag 2 */
define|#
directive|define
name|__XSTORM_TOE_TCP_AG_CONTEXT_SECTION_ACK_TO_FE_UPDATED_SHIFT
value|2
define|#
directive|define
name|XSTORM_TOE_TCP_AG_CONTEXT_SECTION_SIDEBAND_SENT_CF
value|(0x3<<4)
comment|/* BitField tcp_agg_vars1Various aggregative variables	auxiliary counter flag 3 */
define|#
directive|define
name|XSTORM_TOE_TCP_AG_CONTEXT_SECTION_SIDEBAND_SENT_CF_SHIFT
value|4
define|#
directive|define
name|__XSTORM_TOE_TCP_AG_CONTEXT_SECTION_CLEAR_DA_TIMER_EN
value|(0x1<<6)
comment|/* BitField tcp_agg_vars1Various aggregative variables	If set enables sending clear commands as port of the DA decision rules */
define|#
directive|define
name|__XSTORM_TOE_TCP_AG_CONTEXT_SECTION_CLEAR_DA_TIMER_EN_SHIFT
value|6
define|#
directive|define
name|__XSTORM_TOE_TCP_AG_CONTEXT_SECTION_DA_EXPIRATION_FLAG
value|(0x1<<7)
comment|/* BitField tcp_agg_vars1Various aggregative variables	Indicates that there was a delayed ack timer expiration */
define|#
directive|define
name|__XSTORM_TOE_TCP_AG_CONTEXT_SECTION_DA_EXPIRATION_FLAG_SHIFT
value|7
name|uint8_t
name|__da_cnt
comment|/* Counts the number of ACK requests received from the TSTORM with no registration to QM. */
decl_stmt|;
name|uint16_t
name|mss
comment|/* MSS used for nagle algorithm and for transmission */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|mss
comment|/* MSS used for nagle algorithm and for transmission */
decl_stmt|;
name|uint8_t
name|__da_cnt
comment|/* Counts the number of ACK requests received from the TSTORM with no registration to QM. */
decl_stmt|;
name|uint8_t
name|tcp_agg_vars1
decl_stmt|;
define|#
directive|define
name|__XSTORM_TOE_TCP_AG_CONTEXT_SECTION_SET_DA_TIMER_CF
value|(0x3<<0)
comment|/* BitField tcp_agg_vars1Various aggregative variables	Counter flag used to rewind the DA timer */
define|#
directive|define
name|__XSTORM_TOE_TCP_AG_CONTEXT_SECTION_SET_DA_TIMER_CF_SHIFT
value|0
define|#
directive|define
name|__XSTORM_TOE_TCP_AG_CONTEXT_SECTION_ACK_TO_FE_UPDATED
value|(0x3<<2)
comment|/* BitField tcp_agg_vars1Various aggregative variables	auxiliary counter flag 2 */
define|#
directive|define
name|__XSTORM_TOE_TCP_AG_CONTEXT_SECTION_ACK_TO_FE_UPDATED_SHIFT
value|2
define|#
directive|define
name|XSTORM_TOE_TCP_AG_CONTEXT_SECTION_SIDEBAND_SENT_CF
value|(0x3<<4)
comment|/* BitField tcp_agg_vars1Various aggregative variables	auxiliary counter flag 3 */
define|#
directive|define
name|XSTORM_TOE_TCP_AG_CONTEXT_SECTION_SIDEBAND_SENT_CF_SHIFT
value|4
define|#
directive|define
name|__XSTORM_TOE_TCP_AG_CONTEXT_SECTION_CLEAR_DA_TIMER_EN
value|(0x1<<6)
comment|/* BitField tcp_agg_vars1Various aggregative variables	If set enables sending clear commands as port of the DA decision rules */
define|#
directive|define
name|__XSTORM_TOE_TCP_AG_CONTEXT_SECTION_CLEAR_DA_TIMER_EN_SHIFT
value|6
define|#
directive|define
name|__XSTORM_TOE_TCP_AG_CONTEXT_SECTION_DA_EXPIRATION_FLAG
value|(0x1<<7)
comment|/* BitField tcp_agg_vars1Various aggregative variables	Indicates that there was a delayed ack timer expiration */
define|#
directive|define
name|__XSTORM_TOE_TCP_AG_CONTEXT_SECTION_DA_EXPIRATION_FLAG_SHIFT
value|7
endif|#
directive|endif
name|uint32_t
name|snd_nxt
comment|/* The current sequence number to send */
decl_stmt|;
name|uint32_t
name|tx_wnd
comment|/* The Current transmission window in bytes */
decl_stmt|;
name|uint32_t
name|snd_una
comment|/* The current Send UNA sequence number */
decl_stmt|;
name|uint32_t
name|local_adv_wnd
comment|/* The current local advertised window to FE. */
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint8_t
name|__agg_val8_th
comment|/* aggregated value 8 - threshold */
decl_stmt|;
name|uint8_t
name|__tx_dest
comment|/* aggregated value 8 */
decl_stmt|;
name|uint16_t
name|tcp_agg_vars2
decl_stmt|;
define|#
directive|define
name|XSTORM_TOE_TCP_AG_CONTEXT_SECTION_TX_FIN_FLAG
value|(0x1<<0)
comment|/* BitField tcp_agg_vars2Various aggregative variables	Used in TOE to indicate that FIN is sent on a BD to bypass the naggle rule */
define|#
directive|define
name|XSTORM_TOE_TCP_AG_CONTEXT_SECTION_TX_FIN_FLAG_SHIFT
value|0
define|#
directive|define
name|__XSTORM_TOE_TCP_AG_CONTEXT_SECTION_TX_UNBLOCKED
value|(0x1<<1)
comment|/* BitField tcp_agg_vars2Various aggregative variables	Enables the tx window based decision */
define|#
directive|define
name|__XSTORM_TOE_TCP_AG_CONTEXT_SECTION_TX_UNBLOCKED_SHIFT
value|1
define|#
directive|define
name|__XSTORM_TOE_TCP_AG_CONTEXT_SECTION_DA_TIMER_ACTIVE
value|(0x1<<2)
comment|/* BitField tcp_agg_vars2Various aggregative variables	The DA Timer status. If set indicates that the delayed ACK timer is active. */
define|#
directive|define
name|__XSTORM_TOE_TCP_AG_CONTEXT_SECTION_DA_TIMER_ACTIVE_SHIFT
value|2
define|#
directive|define
name|__XSTORM_TOE_TCP_AG_CONTEXT_SECTION_AUX3_FLAG
value|(0x1<<3)
comment|/* BitField tcp_agg_vars2Various aggregative variables	auxiliary flag 3 */
define|#
directive|define
name|__XSTORM_TOE_TCP_AG_CONTEXT_SECTION_AUX3_FLAG_SHIFT
value|3
define|#
directive|define
name|__XSTORM_TOE_TCP_AG_CONTEXT_SECTION_AUX4_FLAG
value|(0x1<<4)
comment|/* BitField tcp_agg_vars2Various aggregative variables	auxiliary flag 4 */
define|#
directive|define
name|__XSTORM_TOE_TCP_AG_CONTEXT_SECTION_AUX4_FLAG_SHIFT
value|4
define|#
directive|define
name|XSTORM_TOE_TCP_AG_CONTEXT_SECTION_DA_ENABLE
value|(0x1<<5)
comment|/* BitField tcp_agg_vars2Various aggregative variables	Enable DA for the specific connection */
define|#
directive|define
name|XSTORM_TOE_TCP_AG_CONTEXT_SECTION_DA_ENABLE_SHIFT
value|5
define|#
directive|define
name|__XSTORM_TOE_TCP_AG_CONTEXT_SECTION_ACK_TO_FE_UPDATED_EN
value|(0x1<<6)
comment|/* BitField tcp_agg_vars2Various aggregative variables	Enable decision rules based on aux2_cf */
define|#
directive|define
name|__XSTORM_TOE_TCP_AG_CONTEXT_SECTION_ACK_TO_FE_UPDATED_EN_SHIFT
value|6
define|#
directive|define
name|XSTORM_TOE_TCP_AG_CONTEXT_SECTION_SIDEBAND_SENT_CF_EN
value|(0x1<<7)
comment|/* BitField tcp_agg_vars2Various aggregative variables	Enable decision rules based on aux3_cf */
define|#
directive|define
name|XSTORM_TOE_TCP_AG_CONTEXT_SECTION_SIDEBAND_SENT_CF_EN_SHIFT
value|7
define|#
directive|define
name|__XSTORM_TOE_TCP_AG_CONTEXT_SECTION_TX_FIN_FLAG_EN
value|(0x1<<8)
comment|/* BitField tcp_agg_vars2Various aggregative variables	Enable Decision rule based on tx_fin_flag */
define|#
directive|define
name|__XSTORM_TOE_TCP_AG_CONTEXT_SECTION_TX_FIN_FLAG_EN_SHIFT
value|8
define|#
directive|define
name|__XSTORM_TOE_TCP_AG_CONTEXT_SECTION_AUX1_FLAG
value|(0x1<<9)
comment|/* BitField tcp_agg_vars2Various aggregative variables	auxiliary flag 1 */
define|#
directive|define
name|__XSTORM_TOE_TCP_AG_CONTEXT_SECTION_AUX1_FLAG_SHIFT
value|9
define|#
directive|define
name|__XSTORM_TOE_TCP_AG_CONTEXT_SECTION_SET_RTO_CF
value|(0x3<<10)
comment|/* BitField tcp_agg_vars2Various aggregative variables	counter flag for setting the rto timer */
define|#
directive|define
name|__XSTORM_TOE_TCP_AG_CONTEXT_SECTION_SET_RTO_CF_SHIFT
value|10
define|#
directive|define
name|__XSTORM_TOE_TCP_AG_CONTEXT_SECTION_TS_TO_ECHO_UPDATED_CF
value|(0x3<<12)
comment|/* BitField tcp_agg_vars2Various aggregative variables	timestamp was updated counter flag */
define|#
directive|define
name|__XSTORM_TOE_TCP_AG_CONTEXT_SECTION_TS_TO_ECHO_UPDATED_CF_SHIFT
value|12
define|#
directive|define
name|__XSTORM_TOE_TCP_AG_CONTEXT_SECTION_TX_DEST_UPDATED_CF
value|(0x3<<14)
comment|/* BitField tcp_agg_vars2Various aggregative variables	auxiliary counter flag 8 */
define|#
directive|define
name|__XSTORM_TOE_TCP_AG_CONTEXT_SECTION_TX_DEST_UPDATED_CF_SHIFT
value|14
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|tcp_agg_vars2
decl_stmt|;
define|#
directive|define
name|XSTORM_TOE_TCP_AG_CONTEXT_SECTION_TX_FIN_FLAG
value|(0x1<<0)
comment|/* BitField tcp_agg_vars2Various aggregative variables	Used in TOE to indicate that FIN is sent on a BD to bypass the naggle rule */
define|#
directive|define
name|XSTORM_TOE_TCP_AG_CONTEXT_SECTION_TX_FIN_FLAG_SHIFT
value|0
define|#
directive|define
name|__XSTORM_TOE_TCP_AG_CONTEXT_SECTION_TX_UNBLOCKED
value|(0x1<<1)
comment|/* BitField tcp_agg_vars2Various aggregative variables	Enables the tx window based decision */
define|#
directive|define
name|__XSTORM_TOE_TCP_AG_CONTEXT_SECTION_TX_UNBLOCKED_SHIFT
value|1
define|#
directive|define
name|__XSTORM_TOE_TCP_AG_CONTEXT_SECTION_DA_TIMER_ACTIVE
value|(0x1<<2)
comment|/* BitField tcp_agg_vars2Various aggregative variables	The DA Timer status. If set indicates that the delayed ACK timer is active. */
define|#
directive|define
name|__XSTORM_TOE_TCP_AG_CONTEXT_SECTION_DA_TIMER_ACTIVE_SHIFT
value|2
define|#
directive|define
name|__XSTORM_TOE_TCP_AG_CONTEXT_SECTION_AUX3_FLAG
value|(0x1<<3)
comment|/* BitField tcp_agg_vars2Various aggregative variables	auxiliary flag 3 */
define|#
directive|define
name|__XSTORM_TOE_TCP_AG_CONTEXT_SECTION_AUX3_FLAG_SHIFT
value|3
define|#
directive|define
name|__XSTORM_TOE_TCP_AG_CONTEXT_SECTION_AUX4_FLAG
value|(0x1<<4)
comment|/* BitField tcp_agg_vars2Various aggregative variables	auxiliary flag 4 */
define|#
directive|define
name|__XSTORM_TOE_TCP_AG_CONTEXT_SECTION_AUX4_FLAG_SHIFT
value|4
define|#
directive|define
name|XSTORM_TOE_TCP_AG_CONTEXT_SECTION_DA_ENABLE
value|(0x1<<5)
comment|/* BitField tcp_agg_vars2Various aggregative variables	Enable DA for the specific connection */
define|#
directive|define
name|XSTORM_TOE_TCP_AG_CONTEXT_SECTION_DA_ENABLE_SHIFT
value|5
define|#
directive|define
name|__XSTORM_TOE_TCP_AG_CONTEXT_SECTION_ACK_TO_FE_UPDATED_EN
value|(0x1<<6)
comment|/* BitField tcp_agg_vars2Various aggregative variables	Enable decision rules based on aux2_cf */
define|#
directive|define
name|__XSTORM_TOE_TCP_AG_CONTEXT_SECTION_ACK_TO_FE_UPDATED_EN_SHIFT
value|6
define|#
directive|define
name|XSTORM_TOE_TCP_AG_CONTEXT_SECTION_SIDEBAND_SENT_CF_EN
value|(0x1<<7)
comment|/* BitField tcp_agg_vars2Various aggregative variables	Enable decision rules based on aux3_cf */
define|#
directive|define
name|XSTORM_TOE_TCP_AG_CONTEXT_SECTION_SIDEBAND_SENT_CF_EN_SHIFT
value|7
define|#
directive|define
name|__XSTORM_TOE_TCP_AG_CONTEXT_SECTION_TX_FIN_FLAG_EN
value|(0x1<<8)
comment|/* BitField tcp_agg_vars2Various aggregative variables	Enable Decision rule based on tx_fin_flag */
define|#
directive|define
name|__XSTORM_TOE_TCP_AG_CONTEXT_SECTION_TX_FIN_FLAG_EN_SHIFT
value|8
define|#
directive|define
name|__XSTORM_TOE_TCP_AG_CONTEXT_SECTION_AUX1_FLAG
value|(0x1<<9)
comment|/* BitField tcp_agg_vars2Various aggregative variables	auxiliary flag 1 */
define|#
directive|define
name|__XSTORM_TOE_TCP_AG_CONTEXT_SECTION_AUX1_FLAG_SHIFT
value|9
define|#
directive|define
name|__XSTORM_TOE_TCP_AG_CONTEXT_SECTION_SET_RTO_CF
value|(0x3<<10)
comment|/* BitField tcp_agg_vars2Various aggregative variables	counter flag for setting the rto timer */
define|#
directive|define
name|__XSTORM_TOE_TCP_AG_CONTEXT_SECTION_SET_RTO_CF_SHIFT
value|10
define|#
directive|define
name|__XSTORM_TOE_TCP_AG_CONTEXT_SECTION_TS_TO_ECHO_UPDATED_CF
value|(0x3<<12)
comment|/* BitField tcp_agg_vars2Various aggregative variables	timestamp was updated counter flag */
define|#
directive|define
name|__XSTORM_TOE_TCP_AG_CONTEXT_SECTION_TS_TO_ECHO_UPDATED_CF_SHIFT
value|12
define|#
directive|define
name|__XSTORM_TOE_TCP_AG_CONTEXT_SECTION_TX_DEST_UPDATED_CF
value|(0x3<<14)
comment|/* BitField tcp_agg_vars2Various aggregative variables	auxiliary counter flag 8 */
define|#
directive|define
name|__XSTORM_TOE_TCP_AG_CONTEXT_SECTION_TX_DEST_UPDATED_CF_SHIFT
value|14
name|uint8_t
name|__tx_dest
comment|/* aggregated value 8 */
decl_stmt|;
name|uint8_t
name|__agg_val8_th
comment|/* aggregated value 8 - threshold */
decl_stmt|;
endif|#
directive|endif
name|uint32_t
name|ack_to_far_end
comment|/* The ACK sequence to send to far end */
decl_stmt|;
name|uint32_t
name|rto_timer
comment|/* The RTO timer value */
decl_stmt|;
name|uint32_t
name|ka_timer
comment|/* The KA timer value */
decl_stmt|;
name|uint32_t
name|ts_to_echo
comment|/* The time stamp value to echo to far end */
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|__agg_val7_th
comment|/* aggregated value 7 - threshold */
decl_stmt|;
name|uint16_t
name|__agg_val7
comment|/* aggregated value 7 */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|__agg_val7
comment|/* aggregated value 7 */
decl_stmt|;
name|uint16_t
name|__agg_val7_th
comment|/* aggregated value 7 - threshold */
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint8_t
name|__tcp_agg_vars5
comment|/* Various aggregative variables*/
decl_stmt|;
name|uint8_t
name|__tcp_agg_vars4
comment|/* Various aggregative variables*/
decl_stmt|;
name|uint8_t
name|__tcp_agg_vars3
comment|/* Various aggregative variables*/
decl_stmt|;
name|uint8_t
name|__force_pure_ack_cnt
comment|/* The number of force ACK commands arrived from the TSTORM */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint8_t
name|__force_pure_ack_cnt
comment|/* The number of force ACK commands arrived from the TSTORM */
decl_stmt|;
name|uint8_t
name|__tcp_agg_vars3
comment|/* Various aggregative variables*/
decl_stmt|;
name|uint8_t
name|__tcp_agg_vars4
comment|/* Various aggregative variables*/
decl_stmt|;
name|uint8_t
name|__tcp_agg_vars5
comment|/* Various aggregative variables*/
decl_stmt|;
endif|#
directive|endif
name|uint32_t
name|tcp_agg_vars6
decl_stmt|;
define|#
directive|define
name|__XSTORM_TOE_TCP_AG_CONTEXT_SECTION_TS_TO_ECHO_CF_EN
value|(0x1<<0)
comment|/* BitField tcp_agg_vars6Various aggregative variables	Enable decision rules based on aux7_cf */
define|#
directive|define
name|__XSTORM_TOE_TCP_AG_CONTEXT_SECTION_TS_TO_ECHO_CF_EN_SHIFT
value|0
define|#
directive|define
name|__XSTORM_TOE_TCP_AG_CONTEXT_SECTION_TX_DEST_UPDATED_CF_EN
value|(0x1<<1)
comment|/* BitField tcp_agg_vars6Various aggregative variables	Enable decision rules based on aux8_cf */
define|#
directive|define
name|__XSTORM_TOE_TCP_AG_CONTEXT_SECTION_TX_DEST_UPDATED_CF_EN_SHIFT
value|1
define|#
directive|define
name|__XSTORM_TOE_TCP_AG_CONTEXT_SECTION_AUX9_CF_EN
value|(0x1<<2)
comment|/* BitField tcp_agg_vars6Various aggregative variables	Enable decision rules based on aux9_cf */
define|#
directive|define
name|__XSTORM_TOE_TCP_AG_CONTEXT_SECTION_AUX9_CF_EN_SHIFT
value|2
define|#
directive|define
name|__XSTORM_TOE_TCP_AG_CONTEXT_SECTION_AUX10_CF_EN
value|(0x1<<3)
comment|/* BitField tcp_agg_vars6Various aggregative variables	Enable decision rules based on aux10_cf */
define|#
directive|define
name|__XSTORM_TOE_TCP_AG_CONTEXT_SECTION_AUX10_CF_EN_SHIFT
value|3
define|#
directive|define
name|__XSTORM_TOE_TCP_AG_CONTEXT_SECTION_AUX6_FLAG
value|(0x1<<4)
comment|/* BitField tcp_agg_vars6Various aggregative variables	auxiliary flag 6 */
define|#
directive|define
name|__XSTORM_TOE_TCP_AG_CONTEXT_SECTION_AUX6_FLAG_SHIFT
value|4
define|#
directive|define
name|__XSTORM_TOE_TCP_AG_CONTEXT_SECTION_AUX7_FLAG
value|(0x1<<5)
comment|/* BitField tcp_agg_vars6Various aggregative variables	auxiliary flag 7 */
define|#
directive|define
name|__XSTORM_TOE_TCP_AG_CONTEXT_SECTION_AUX7_FLAG_SHIFT
value|5
define|#
directive|define
name|__XSTORM_TOE_TCP_AG_CONTEXT_SECTION_AUX5_CF
value|(0x3<<6)
comment|/* BitField tcp_agg_vars6Various aggregative variables	auxiliary counter flag 5 */
define|#
directive|define
name|__XSTORM_TOE_TCP_AG_CONTEXT_SECTION_AUX5_CF_SHIFT
value|6
define|#
directive|define
name|__XSTORM_TOE_TCP_AG_CONTEXT_SECTION_AUX9_CF
value|(0x3<<8)
comment|/* BitField tcp_agg_vars6Various aggregative variables	auxiliary counter flag 9 */
define|#
directive|define
name|__XSTORM_TOE_TCP_AG_CONTEXT_SECTION_AUX9_CF_SHIFT
value|8
define|#
directive|define
name|__XSTORM_TOE_TCP_AG_CONTEXT_SECTION_AUX10_CF
value|(0x3<<10)
comment|/* BitField tcp_agg_vars6Various aggregative variables	auxiliary counter flag 10 */
define|#
directive|define
name|__XSTORM_TOE_TCP_AG_CONTEXT_SECTION_AUX10_CF_SHIFT
value|10
define|#
directive|define
name|__XSTORM_TOE_TCP_AG_CONTEXT_SECTION_AUX11_CF
value|(0x3<<12)
comment|/* BitField tcp_agg_vars6Various aggregative variables	auxiliary counter flag 11 */
define|#
directive|define
name|__XSTORM_TOE_TCP_AG_CONTEXT_SECTION_AUX11_CF_SHIFT
value|12
define|#
directive|define
name|__XSTORM_TOE_TCP_AG_CONTEXT_SECTION_AUX12_CF
value|(0x3<<14)
comment|/* BitField tcp_agg_vars6Various aggregative variables	auxiliary counter flag 12 */
define|#
directive|define
name|__XSTORM_TOE_TCP_AG_CONTEXT_SECTION_AUX12_CF_SHIFT
value|14
define|#
directive|define
name|__XSTORM_TOE_TCP_AG_CONTEXT_SECTION_AUX13_CF
value|(0x3<<16)
comment|/* BitField tcp_agg_vars6Various aggregative variables	auxiliary counter flag 13 */
define|#
directive|define
name|__XSTORM_TOE_TCP_AG_CONTEXT_SECTION_AUX13_CF_SHIFT
value|16
define|#
directive|define
name|__XSTORM_TOE_TCP_AG_CONTEXT_SECTION_AUX14_CF
value|(0x3<<18)
comment|/* BitField tcp_agg_vars6Various aggregative variables	auxiliary counter flag 14 */
define|#
directive|define
name|__XSTORM_TOE_TCP_AG_CONTEXT_SECTION_AUX14_CF_SHIFT
value|18
define|#
directive|define
name|__XSTORM_TOE_TCP_AG_CONTEXT_SECTION_AUX15_CF
value|(0x3<<20)
comment|/* BitField tcp_agg_vars6Various aggregative variables	auxiliary counter flag 15 */
define|#
directive|define
name|__XSTORM_TOE_TCP_AG_CONTEXT_SECTION_AUX15_CF_SHIFT
value|20
define|#
directive|define
name|__XSTORM_TOE_TCP_AG_CONTEXT_SECTION_AUX16_CF
value|(0x3<<22)
comment|/* BitField tcp_agg_vars6Various aggregative variables	auxiliary counter flag 16 */
define|#
directive|define
name|__XSTORM_TOE_TCP_AG_CONTEXT_SECTION_AUX16_CF_SHIFT
value|22
define|#
directive|define
name|__XSTORM_TOE_TCP_AG_CONTEXT_SECTION_AUX17_CF
value|(0x3<<24)
comment|/* BitField tcp_agg_vars6Various aggregative variables	auxiliary counter flag 17 */
define|#
directive|define
name|__XSTORM_TOE_TCP_AG_CONTEXT_SECTION_AUX17_CF_SHIFT
value|24
define|#
directive|define
name|XSTORM_TOE_TCP_AG_CONTEXT_SECTION_ECE_FLAG
value|(0x1<<26)
comment|/* BitField tcp_agg_vars6Various aggregative variables	Can be also used as general purpose if ECN is not used */
define|#
directive|define
name|XSTORM_TOE_TCP_AG_CONTEXT_SECTION_ECE_FLAG_SHIFT
value|26
define|#
directive|define
name|__XSTORM_TOE_TCP_AG_CONTEXT_SECTION_RESERVED71
value|(0x1<<27)
comment|/* BitField tcp_agg_vars6Various aggregative variables	Can be also used as general purpose if ECN is not used */
define|#
directive|define
name|__XSTORM_TOE_TCP_AG_CONTEXT_SECTION_RESERVED71_SHIFT
value|27
define|#
directive|define
name|__XSTORM_TOE_TCP_AG_CONTEXT_SECTION_FORCE_PURE_ACK_CNT_DIRTY
value|(0x1<<28)
comment|/* BitField tcp_agg_vars6Various aggregative variables	This flag is set if the Force ACK count is set by the TSTORM. On QM output it is cleared. */
define|#
directive|define
name|__XSTORM_TOE_TCP_AG_CONTEXT_SECTION_FORCE_PURE_ACK_CNT_DIRTY_SHIFT
value|28
define|#
directive|define
name|__XSTORM_TOE_TCP_AG_CONTEXT_SECTION_TCP_AUTO_STOP_FLAG
value|(0x1<<29)
comment|/* BitField tcp_agg_vars6Various aggregative variables	Indicates that the connection is in autostop mode */
define|#
directive|define
name|__XSTORM_TOE_TCP_AG_CONTEXT_SECTION_TCP_AUTO_STOP_FLAG_SHIFT
value|29
define|#
directive|define
name|__XSTORM_TOE_TCP_AG_CONTEXT_SECTION_DO_TS_UPDATE_FLAG
value|(0x1<<30)
comment|/* BitField tcp_agg_vars6Various aggregative variables	This bit uses like a one shot that the TSTORM fires and the XSTORM arms. Used to allow a single TS update for each transmission */
define|#
directive|define
name|__XSTORM_TOE_TCP_AG_CONTEXT_SECTION_DO_TS_UPDATE_FLAG_SHIFT
value|30
define|#
directive|define
name|__XSTORM_TOE_TCP_AG_CONTEXT_SECTION_CANCEL_RETRANSMIT_FLAG
value|(0x1<<31)
comment|/* BitField tcp_agg_vars6Various aggregative variables	This bit is set by the TSTORM when need to cancel precious fast retransmit */
define|#
directive|define
name|__XSTORM_TOE_TCP_AG_CONTEXT_SECTION_CANCEL_RETRANSMIT_FLAG_SHIFT
value|31
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|__agg_misc6
comment|/* Misc aggregated variable 6 */
decl_stmt|;
name|uint16_t
name|__tcp_agg_vars7
comment|/* Various aggregative variables*/
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|__tcp_agg_vars7
comment|/* Various aggregative variables*/
decl_stmt|;
name|uint16_t
name|__agg_misc6
comment|/* Misc aggregated variable 6 */
decl_stmt|;
endif|#
directive|endif
name|uint32_t
name|__agg_val10
comment|/* aggregated value 10 */
decl_stmt|;
name|uint32_t
name|__agg_val10_th
comment|/* aggregated value 10 - threshold */
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|__reserved3
decl_stmt|;
name|uint8_t
name|__reserved2
decl_stmt|;
name|uint8_t
name|__da_only_cnt
comment|/* counts delayed acks and not window updates */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint8_t
name|__da_only_cnt
comment|/* counts delayed acks and not window updates */
decl_stmt|;
name|uint8_t
name|__reserved2
decl_stmt|;
name|uint16_t
name|__reserved3
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/*  * The toe aggregative context of Xstorm  */
end_comment

begin_struct
struct|struct
name|xstorm_toe_ag_context
block|{
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|agg_val1
comment|/* aggregated value 1 */
decl_stmt|;
name|uint8_t
name|agg_vars1
decl_stmt|;
define|#
directive|define
name|__XSTORM_TOE_AG_CONTEXT_EXISTS_IN_QM0
value|(0x1<<0)
comment|/* BitField agg_vars1Various aggregative variables	The connection is currently registered to the QM with queue index 0 */
define|#
directive|define
name|__XSTORM_TOE_AG_CONTEXT_EXISTS_IN_QM0_SHIFT
value|0
define|#
directive|define
name|__XSTORM_TOE_AG_CONTEXT_RESERVED50
value|(0x1<<1)
comment|/* BitField agg_vars1Various aggregative variables	The connection is currently registered to the QM with queue index 1 */
define|#
directive|define
name|__XSTORM_TOE_AG_CONTEXT_RESERVED50_SHIFT
value|1
define|#
directive|define
name|__XSTORM_TOE_AG_CONTEXT_RESERVED51
value|(0x1<<2)
comment|/* BitField agg_vars1Various aggregative variables	The connection is currently registered to the QM with queue index 2 */
define|#
directive|define
name|__XSTORM_TOE_AG_CONTEXT_RESERVED51_SHIFT
value|2
define|#
directive|define
name|__XSTORM_TOE_AG_CONTEXT_RESERVED52
value|(0x1<<3)
comment|/* BitField agg_vars1Various aggregative variables	The connection is currently registered to the QM with queue index 3 */
define|#
directive|define
name|__XSTORM_TOE_AG_CONTEXT_RESERVED52_SHIFT
value|3
define|#
directive|define
name|__XSTORM_TOE_AG_CONTEXT_MORE_TO_SEND_EN
value|(0x1<<4)
comment|/* BitField agg_vars1Various aggregative variables	Enables the decision rule of more_to_Send> 0 */
define|#
directive|define
name|__XSTORM_TOE_AG_CONTEXT_MORE_TO_SEND_EN_SHIFT
value|4
define|#
directive|define
name|XSTORM_TOE_AG_CONTEXT_NAGLE_EN
value|(0x1<<5)
comment|/* BitField agg_vars1Various aggregative variables	Enables the nagle decision */
define|#
directive|define
name|XSTORM_TOE_AG_CONTEXT_NAGLE_EN_SHIFT
value|5
define|#
directive|define
name|__XSTORM_TOE_AG_CONTEXT_DQ_FLUSH_FLAG
value|(0x1<<6)
comment|/* BitField agg_vars1Various aggregative variables	used to indicate last doorbell for specific connection */
define|#
directive|define
name|__XSTORM_TOE_AG_CONTEXT_DQ_FLUSH_FLAG_SHIFT
value|6
define|#
directive|define
name|__XSTORM_TOE_AG_CONTEXT_UNA_GT_NXT_EN
value|(0x1<<7)
comment|/* BitField agg_vars1Various aggregative variables	Enable decision rules based on equality between snd_una and snd_nxt */
define|#
directive|define
name|__XSTORM_TOE_AG_CONTEXT_UNA_GT_NXT_EN_SHIFT
value|7
name|uint8_t
name|__state
comment|/* The state of the connection */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint8_t
name|__state
comment|/* The state of the connection */
decl_stmt|;
name|uint8_t
name|agg_vars1
decl_stmt|;
define|#
directive|define
name|__XSTORM_TOE_AG_CONTEXT_EXISTS_IN_QM0
value|(0x1<<0)
comment|/* BitField agg_vars1Various aggregative variables	The connection is currently registered to the QM with queue index 0 */
define|#
directive|define
name|__XSTORM_TOE_AG_CONTEXT_EXISTS_IN_QM0_SHIFT
value|0
define|#
directive|define
name|__XSTORM_TOE_AG_CONTEXT_RESERVED50
value|(0x1<<1)
comment|/* BitField agg_vars1Various aggregative variables	The connection is currently registered to the QM with queue index 1 */
define|#
directive|define
name|__XSTORM_TOE_AG_CONTEXT_RESERVED50_SHIFT
value|1
define|#
directive|define
name|__XSTORM_TOE_AG_CONTEXT_RESERVED51
value|(0x1<<2)
comment|/* BitField agg_vars1Various aggregative variables	The connection is currently registered to the QM with queue index 2 */
define|#
directive|define
name|__XSTORM_TOE_AG_CONTEXT_RESERVED51_SHIFT
value|2
define|#
directive|define
name|__XSTORM_TOE_AG_CONTEXT_RESERVED52
value|(0x1<<3)
comment|/* BitField agg_vars1Various aggregative variables	The connection is currently registered to the QM with queue index 3 */
define|#
directive|define
name|__XSTORM_TOE_AG_CONTEXT_RESERVED52_SHIFT
value|3
define|#
directive|define
name|__XSTORM_TOE_AG_CONTEXT_MORE_TO_SEND_EN
value|(0x1<<4)
comment|/* BitField agg_vars1Various aggregative variables	Enables the decision rule of more_to_Send> 0 */
define|#
directive|define
name|__XSTORM_TOE_AG_CONTEXT_MORE_TO_SEND_EN_SHIFT
value|4
define|#
directive|define
name|XSTORM_TOE_AG_CONTEXT_NAGLE_EN
value|(0x1<<5)
comment|/* BitField agg_vars1Various aggregative variables	Enables the nagle decision */
define|#
directive|define
name|XSTORM_TOE_AG_CONTEXT_NAGLE_EN_SHIFT
value|5
define|#
directive|define
name|__XSTORM_TOE_AG_CONTEXT_DQ_FLUSH_FLAG
value|(0x1<<6)
comment|/* BitField agg_vars1Various aggregative variables	used to indicate last doorbell for specific connection */
define|#
directive|define
name|__XSTORM_TOE_AG_CONTEXT_DQ_FLUSH_FLAG_SHIFT
value|6
define|#
directive|define
name|__XSTORM_TOE_AG_CONTEXT_UNA_GT_NXT_EN
value|(0x1<<7)
comment|/* BitField agg_vars1Various aggregative variables	Enable decision rules based on equality between snd_una and snd_nxt */
define|#
directive|define
name|__XSTORM_TOE_AG_CONTEXT_UNA_GT_NXT_EN_SHIFT
value|7
name|uint16_t
name|agg_val1
comment|/* aggregated value 1 */
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint8_t
name|cdu_reserved
comment|/* Used by the CDU for validation and debugging */
decl_stmt|;
name|uint8_t
name|__agg_vars4
comment|/* Various aggregative variables*/
decl_stmt|;
name|uint8_t
name|agg_vars3
decl_stmt|;
define|#
directive|define
name|XSTORM_TOE_AG_CONTEXT_PHYSICAL_QUEUE_NUM2
value|(0x3F<<0)
comment|/* BitField agg_vars3Various aggregative variables	The physical queue number of queue index 2 */
define|#
directive|define
name|XSTORM_TOE_AG_CONTEXT_PHYSICAL_QUEUE_NUM2_SHIFT
value|0
define|#
directive|define
name|__XSTORM_TOE_AG_CONTEXT_QUEUES_FLUSH_Q1_CF
value|(0x3<<6)
comment|/* BitField agg_vars3Various aggregative variables	auxiliary counter flag 19 */
define|#
directive|define
name|__XSTORM_TOE_AG_CONTEXT_QUEUES_FLUSH_Q1_CF_SHIFT
value|6
name|uint8_t
name|agg_vars2
decl_stmt|;
define|#
directive|define
name|__XSTORM_TOE_AG_CONTEXT_DQ_CF
value|(0x3<<0)
comment|/* BitField agg_vars2Various aggregative variables	auxiliary counter flag 4 */
define|#
directive|define
name|__XSTORM_TOE_AG_CONTEXT_DQ_CF_SHIFT
value|0
define|#
directive|define
name|__XSTORM_TOE_AG_CONTEXT_DQ_FLUSH_FLAG_EN
value|(0x1<<2)
comment|/* BitField agg_vars2Various aggregative variables	Enable decision rule based on dq_spare_flag */
define|#
directive|define
name|__XSTORM_TOE_AG_CONTEXT_DQ_FLUSH_FLAG_EN_SHIFT
value|2
define|#
directive|define
name|__XSTORM_TOE_AG_CONTEXT_AUX8_FLAG
value|(0x1<<3)
comment|/* BitField agg_vars2Various aggregative variables	auxiliary flag 8 */
define|#
directive|define
name|__XSTORM_TOE_AG_CONTEXT_AUX8_FLAG_SHIFT
value|3
define|#
directive|define
name|__XSTORM_TOE_AG_CONTEXT_AUX9_FLAG
value|(0x1<<4)
comment|/* BitField agg_vars2Various aggregative variables	auxiliary flag 9 */
define|#
directive|define
name|__XSTORM_TOE_AG_CONTEXT_AUX9_FLAG_SHIFT
value|4
define|#
directive|define
name|XSTORM_TOE_AG_CONTEXT_RESERVED53
value|(0x3<<5)
comment|/* BitField agg_vars2Various aggregative variables	0-NOP,1-EQ,2-NEQ */
define|#
directive|define
name|XSTORM_TOE_AG_CONTEXT_RESERVED53_SHIFT
value|5
define|#
directive|define
name|__XSTORM_TOE_AG_CONTEXT_DQ_CF_EN
value|(0x1<<7)
comment|/* BitField agg_vars2Various aggregative variables	Enable decision rules based on aux4_cf */
define|#
directive|define
name|__XSTORM_TOE_AG_CONTEXT_DQ_CF_EN_SHIFT
value|7
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint8_t
name|agg_vars2
decl_stmt|;
define|#
directive|define
name|__XSTORM_TOE_AG_CONTEXT_DQ_CF
value|(0x3<<0)
comment|/* BitField agg_vars2Various aggregative variables	auxiliary counter flag 4 */
define|#
directive|define
name|__XSTORM_TOE_AG_CONTEXT_DQ_CF_SHIFT
value|0
define|#
directive|define
name|__XSTORM_TOE_AG_CONTEXT_DQ_FLUSH_FLAG_EN
value|(0x1<<2)
comment|/* BitField agg_vars2Various aggregative variables	Enable decision rule based on dq_spare_flag */
define|#
directive|define
name|__XSTORM_TOE_AG_CONTEXT_DQ_FLUSH_FLAG_EN_SHIFT
value|2
define|#
directive|define
name|__XSTORM_TOE_AG_CONTEXT_AUX8_FLAG
value|(0x1<<3)
comment|/* BitField agg_vars2Various aggregative variables	auxiliary flag 8 */
define|#
directive|define
name|__XSTORM_TOE_AG_CONTEXT_AUX8_FLAG_SHIFT
value|3
define|#
directive|define
name|__XSTORM_TOE_AG_CONTEXT_AUX9_FLAG
value|(0x1<<4)
comment|/* BitField agg_vars2Various aggregative variables	auxiliary flag 9 */
define|#
directive|define
name|__XSTORM_TOE_AG_CONTEXT_AUX9_FLAG_SHIFT
value|4
define|#
directive|define
name|XSTORM_TOE_AG_CONTEXT_RESERVED53
value|(0x3<<5)
comment|/* BitField agg_vars2Various aggregative variables	0-NOP,1-EQ,2-NEQ */
define|#
directive|define
name|XSTORM_TOE_AG_CONTEXT_RESERVED53_SHIFT
value|5
define|#
directive|define
name|__XSTORM_TOE_AG_CONTEXT_DQ_CF_EN
value|(0x1<<7)
comment|/* BitField agg_vars2Various aggregative variables	Enable decision rules based on aux4_cf */
define|#
directive|define
name|__XSTORM_TOE_AG_CONTEXT_DQ_CF_EN_SHIFT
value|7
name|uint8_t
name|agg_vars3
decl_stmt|;
define|#
directive|define
name|XSTORM_TOE_AG_CONTEXT_PHYSICAL_QUEUE_NUM2
value|(0x3F<<0)
comment|/* BitField agg_vars3Various aggregative variables	The physical queue number of queue index 2 */
define|#
directive|define
name|XSTORM_TOE_AG_CONTEXT_PHYSICAL_QUEUE_NUM2_SHIFT
value|0
define|#
directive|define
name|__XSTORM_TOE_AG_CONTEXT_QUEUES_FLUSH_Q1_CF
value|(0x3<<6)
comment|/* BitField agg_vars3Various aggregative variables	auxiliary counter flag 19 */
define|#
directive|define
name|__XSTORM_TOE_AG_CONTEXT_QUEUES_FLUSH_Q1_CF_SHIFT
value|6
name|uint8_t
name|__agg_vars4
comment|/* Various aggregative variables*/
decl_stmt|;
name|uint8_t
name|cdu_reserved
comment|/* Used by the CDU for validation and debugging */
decl_stmt|;
endif|#
directive|endif
name|uint32_t
name|more_to_send
comment|/* The number of bytes left to send */
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|agg_vars5
decl_stmt|;
define|#
directive|define
name|__XSTORM_TOE_AG_CONTEXT_RESERVED54
value|(0x3<<0)
comment|/* BitField agg_vars5Various aggregative variables	0-NOP,1-EQ,2-NEQ */
define|#
directive|define
name|__XSTORM_TOE_AG_CONTEXT_RESERVED54_SHIFT
value|0
define|#
directive|define
name|XSTORM_TOE_AG_CONTEXT_PHYSICAL_QUEUE_NUM0
value|(0x3F<<2)
comment|/* BitField agg_vars5Various aggregative variables	The physical queue number of queue index 0 */
define|#
directive|define
name|XSTORM_TOE_AG_CONTEXT_PHYSICAL_QUEUE_NUM0_SHIFT
value|2
define|#
directive|define
name|XSTORM_TOE_AG_CONTEXT_PHYSICAL_QUEUE_NUM1
value|(0x3F<<8)
comment|/* BitField agg_vars5Various aggregative variables	The physical queue number of queue index 1 */
define|#
directive|define
name|XSTORM_TOE_AG_CONTEXT_PHYSICAL_QUEUE_NUM1_SHIFT
value|8
define|#
directive|define
name|__XSTORM_TOE_AG_CONTEXT_RESERVED56
value|(0x3<<14)
comment|/* BitField agg_vars5Various aggregative variables	0-NOP,1-EQ,2-NEQ */
define|#
directive|define
name|__XSTORM_TOE_AG_CONTEXT_RESERVED56_SHIFT
value|14
name|uint16_t
name|__agg_val4_th
comment|/* aggregated value 4 - threshold */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|__agg_val4_th
comment|/* aggregated value 4 - threshold */
decl_stmt|;
name|uint16_t
name|agg_vars5
decl_stmt|;
define|#
directive|define
name|__XSTORM_TOE_AG_CONTEXT_RESERVED54
value|(0x3<<0)
comment|/* BitField agg_vars5Various aggregative variables	0-NOP,1-EQ,2-NEQ */
define|#
directive|define
name|__XSTORM_TOE_AG_CONTEXT_RESERVED54_SHIFT
value|0
define|#
directive|define
name|XSTORM_TOE_AG_CONTEXT_PHYSICAL_QUEUE_NUM0
value|(0x3F<<2)
comment|/* BitField agg_vars5Various aggregative variables	The physical queue number of queue index 0 */
define|#
directive|define
name|XSTORM_TOE_AG_CONTEXT_PHYSICAL_QUEUE_NUM0_SHIFT
value|2
define|#
directive|define
name|XSTORM_TOE_AG_CONTEXT_PHYSICAL_QUEUE_NUM1
value|(0x3F<<8)
comment|/* BitField agg_vars5Various aggregative variables	The physical queue number of queue index 1 */
define|#
directive|define
name|XSTORM_TOE_AG_CONTEXT_PHYSICAL_QUEUE_NUM1_SHIFT
value|8
define|#
directive|define
name|__XSTORM_TOE_AG_CONTEXT_RESERVED56
value|(0x3<<14)
comment|/* BitField agg_vars5Various aggregative variables	0-NOP,1-EQ,2-NEQ */
define|#
directive|define
name|__XSTORM_TOE_AG_CONTEXT_RESERVED56_SHIFT
value|14
endif|#
directive|endif
name|struct
name|xstorm_toe_tcp_ag_context_section
name|tcp
comment|/* TCP context section, shared in TOE and ISCSI */
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|__agg_vars7
comment|/* Various aggregative variables*/
decl_stmt|;
name|uint8_t
name|__agg_val3_th
comment|/* Aggregated value 3 - threshold */
decl_stmt|;
name|uint8_t
name|__agg_vars6
comment|/* Various aggregative variables*/
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint8_t
name|__agg_vars6
comment|/* Various aggregative variables*/
decl_stmt|;
name|uint8_t
name|__agg_val3_th
comment|/* Aggregated value 3 - threshold */
decl_stmt|;
name|uint16_t
name|__agg_vars7
comment|/* Various aggregative variables*/
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|__agg_val11_th
comment|/* aggregated value 11 - threshold */
decl_stmt|;
name|uint16_t
name|__agg_val11
comment|/* aggregated value 11 */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|__agg_val11
comment|/* aggregated value 11 */
decl_stmt|;
name|uint16_t
name|__agg_val11_th
comment|/* aggregated value 11 - threshold */
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint8_t
name|__reserved1
decl_stmt|;
name|uint8_t
name|__agg_val6_th
comment|/* aggregated value 6 - threshold */
decl_stmt|;
name|uint16_t
name|__agg_val9
comment|/* aggregated value 9 */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|__agg_val9
comment|/* aggregated value 9 */
decl_stmt|;
name|uint8_t
name|__agg_val6_th
comment|/* aggregated value 6 - threshold */
decl_stmt|;
name|uint8_t
name|__reserved1
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|__agg_val2_th
comment|/* Aggregated value 2 - threshold */
decl_stmt|;
name|uint16_t
name|cmp_bd_cons
comment|/* BD Consumer from the Completor */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|cmp_bd_cons
comment|/* BD Consumer from the Completor */
decl_stmt|;
name|uint16_t
name|__agg_val2_th
comment|/* Aggregated value 2 - threshold */
decl_stmt|;
endif|#
directive|endif
name|uint32_t
name|__agg_varint8_t
comment|/* Various aggregative variables*/
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|__agg_misc0
comment|/* Misc aggregated variable 0 */
decl_stmt|;
name|uint16_t
name|__agg_val4
comment|/* aggregated value 4 */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|__agg_val4
comment|/* aggregated value 4 */
decl_stmt|;
name|uint16_t
name|__agg_misc0
comment|/* Misc aggregated variable 0 */
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint8_t
name|__agg_val3
comment|/* Aggregated value 3 */
decl_stmt|;
name|uint8_t
name|__agg_val6
comment|/* Aggregated value 6 */
decl_stmt|;
name|uint8_t
name|__agg_val5_th
comment|/* Aggregated value 5 - threshold */
decl_stmt|;
name|uint8_t
name|__agg_val5
comment|/* Aggregated value 5 */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint8_t
name|__agg_val5
comment|/* Aggregated value 5 */
decl_stmt|;
name|uint8_t
name|__agg_val5_th
comment|/* Aggregated value 5 - threshold */
decl_stmt|;
name|uint8_t
name|__agg_val6
comment|/* Aggregated value 6 */
decl_stmt|;
name|uint8_t
name|__agg_val3
comment|/* Aggregated value 3 */
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|__agg_misc1
comment|/* Spare value for aggregation. NOTE: this value is used in the retransmit decision rule if CmpSeqDecMask is 0. In that case it is intended to be CmpBdSize. */
decl_stmt|;
name|uint16_t
name|__bd_ind_max_val
comment|/* modulo value for bd_prod */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|__bd_ind_max_val
comment|/* modulo value for bd_prod */
decl_stmt|;
name|uint16_t
name|__agg_misc1
comment|/* Spare value for aggregation. NOTE: this value is used in the retransmit decision rule if CmpSeqDecMask is 0. In that case it is intended to be CmpBdSize. */
decl_stmt|;
endif|#
directive|endif
name|uint32_t
name|cmp_bd_start_seq
comment|/* The sequence number of the start completion point (BD) */
decl_stmt|;
name|uint32_t
name|cmp_bd_page_0_to_31
comment|/* Misc aggregated variable 4 */
decl_stmt|;
name|uint32_t
name|cmp_bd_page_32_to_63
comment|/* spare aggregated variable 5 */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * doorbell message sent to the chip  */
end_comment

begin_struct
struct|struct
name|doorbell
block|{
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|zero_fill2
comment|/* driver must zero this field! */
decl_stmt|;
name|uint8_t
name|zero_fill1
comment|/* driver must zero this field! */
decl_stmt|;
name|struct
name|doorbell_hdr_t
name|header
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|struct
name|doorbell_hdr_t
name|header
decl_stmt|;
name|uint8_t
name|zero_fill1
comment|/* driver must zero this field! */
decl_stmt|;
name|uint16_t
name|zero_fill2
comment|/* driver must zero this field! */
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/*  * doorbell message sent to the chip  */
end_comment

begin_struct
struct|struct
name|doorbell_set_prod
block|{
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|prod
comment|/* Producer index to be set */
decl_stmt|;
name|uint8_t
name|zero_fill1
comment|/* driver must zero this field! */
decl_stmt|;
name|struct
name|doorbell_hdr_t
name|header
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|struct
name|doorbell_hdr_t
name|header
decl_stmt|;
name|uint8_t
name|zero_fill1
comment|/* driver must zero this field! */
decl_stmt|;
name|uint16_t
name|prod
comment|/* Producer index to be set */
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_struct
struct|struct
name|regpair_native_t
block|{
name|uint32_t
name|lo
comment|/* low word for reg-pair */
decl_stmt|;
name|uint32_t
name|hi
comment|/* high word for reg-pair */
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|regpair_t
block|{
name|uint32_t
name|lo
comment|/* low word for reg-pair */
decl_stmt|;
name|uint32_t
name|hi
comment|/* high word for reg-pair */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Classify rule opcodes in E2/E3  */
end_comment

begin_enum
enum|enum
name|classify_rule
block|{
name|CLASSIFY_RULE_OPCODE_MAC
comment|/* Add/remove a MAC address */
block|,
name|CLASSIFY_RULE_OPCODE_VLAN
comment|/* Add/remove a VLAN */
block|,
name|CLASSIFY_RULE_OPCODE_PAIR
comment|/* Add/remove a MAC-VLAN pair */
block|,
name|CLASSIFY_RULE_OPCODE_IMAC_VNI
comment|/* Add/remove an Inner MAC-VNI pair entry */
block|,
name|MAX_CLASSIFY_RULE
block|}
enum|;
end_enum

begin_comment
comment|/*  * Classify rule types in E2/E3  */
end_comment

begin_enum
enum|enum
name|classify_rule_action_type
block|{
name|CLASSIFY_RULE_REMOVE
block|,
name|CLASSIFY_RULE_ADD
block|,
name|MAX_CLASSIFY_RULE_ACTION_TYPE
block|}
enum|;
end_enum

begin_comment
comment|/*  * client init ramrod data $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|client_init_general_data
block|{
name|uint8_t
name|client_id
comment|/* client_id */
decl_stmt|;
name|uint8_t
name|statistics_counter_id
comment|/* statistics counter id */
decl_stmt|;
name|uint8_t
name|statistics_en_flg
comment|/* statistics en flg */
decl_stmt|;
name|uint8_t
name|is_fcoe_flg
comment|/* is this an fcoe connection. (1 bit is used) */
decl_stmt|;
name|uint8_t
name|activate_flg
comment|/* if 0 - the client is deactivate else the client is activate client (1 bit is used) */
decl_stmt|;
name|uint8_t
name|sp_client_id
comment|/* the slow path rings client Id. */
decl_stmt|;
name|uint16_t
name|mtu
comment|/* Host MTU from client config */
decl_stmt|;
name|uint8_t
name|statistics_zero_flg
comment|/* if set FW will reset the statistic counter of this client */
decl_stmt|;
name|uint8_t
name|func_id
comment|/* PCI function ID (0-71) */
decl_stmt|;
name|uint8_t
name|cos
comment|/* The connection cos, if applicable */
decl_stmt|;
name|uint8_t
name|traffic_type
decl_stmt|;
name|uint8_t
name|fp_hsi_ver
comment|/* Hsi version */
decl_stmt|;
name|uint8_t
name|reserved0
index|[
literal|3
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * client init rx data $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|client_init_rx_data
block|{
name|uint8_t
name|tpa_en
decl_stmt|;
define|#
directive|define
name|CLIENT_INIT_RX_DATA_TPA_EN_IPV4
value|(0x1<<0)
comment|/* BitField tpa_entpa_enable	tpa enable flg ipv4 */
define|#
directive|define
name|CLIENT_INIT_RX_DATA_TPA_EN_IPV4_SHIFT
value|0
define|#
directive|define
name|CLIENT_INIT_RX_DATA_TPA_EN_IPV6
value|(0x1<<1)
comment|/* BitField tpa_entpa_enable	tpa enable flg ipv6 */
define|#
directive|define
name|CLIENT_INIT_RX_DATA_TPA_EN_IPV6_SHIFT
value|1
define|#
directive|define
name|CLIENT_INIT_RX_DATA_TPA_MODE
value|(0x1<<2)
comment|/* BitField tpa_entpa_enable	tpa mode (LRO or GRO) (use enum tpa_mode) */
define|#
directive|define
name|CLIENT_INIT_RX_DATA_TPA_MODE_SHIFT
value|2
define|#
directive|define
name|CLIENT_INIT_RX_DATA_RESERVED5
value|(0x1F<<3)
comment|/* BitField tpa_entpa_enable	 */
define|#
directive|define
name|CLIENT_INIT_RX_DATA_RESERVED5_SHIFT
value|3
name|uint8_t
name|vmqueue_mode_en_flg
comment|/* If set, working in VMQueue mode (always consume one sge) */
decl_stmt|;
name|uint8_t
name|extra_data_over_sgl_en_flg
comment|/* if set, put over sgl data from end of input message */
decl_stmt|;
name|uint8_t
name|cache_line_alignment_log_size
comment|/* The log size of cache line alignment in bytes. Must be a power of 2. */
decl_stmt|;
name|uint8_t
name|enable_dynamic_hc
comment|/* If set, dynamic HC is enabled */
decl_stmt|;
name|uint8_t
name|max_sges_for_packet
comment|/* The maximal number of SGEs that can be used for one packet. depends on MTU and SGE size. must be 0 if SGEs are disabled */
decl_stmt|;
name|uint8_t
name|client_qzone_id
comment|/* used in E2 only, to specify the HW queue zone ID used for this client rx producers */
decl_stmt|;
name|uint8_t
name|drop_ip_cs_err_flg
comment|/* If set, this client drops packets with IP checksum error */
decl_stmt|;
name|uint8_t
name|drop_tcp_cs_err_flg
comment|/* If set, this client drops packets with TCP checksum error */
decl_stmt|;
name|uint8_t
name|drop_ttl0_flg
comment|/* If set, this client drops packets with TTL=0 */
decl_stmt|;
name|uint8_t
name|drop_udp_cs_err_flg
comment|/* If set, this client drops packets with UDP checksum error */
decl_stmt|;
name|uint8_t
name|inner_vlan_removal_enable_flg
comment|/* If set, inner VLAN removal is enabled for this client */
decl_stmt|;
name|uint8_t
name|outer_vlan_removal_enable_flg
comment|/* If set, outer VLAN removal is enabled for this client */
decl_stmt|;
name|uint8_t
name|status_block_id
comment|/* rx status block id */
decl_stmt|;
name|uint8_t
name|rx_sb_index_number
comment|/* status block indices */
decl_stmt|;
name|uint8_t
name|dont_verify_rings_pause_thr_flg
comment|/* If set, the rings pause thresholds will not be verified by firmware. */
decl_stmt|;
name|uint8_t
name|max_tpa_queues
comment|/* maximal TPA queues allowed for this client */
decl_stmt|;
name|uint8_t
name|silent_vlan_removal_flg
comment|/* if set, and the vlan is equal to requested vlan according to mask, the vlan will be remove without notifying the driver */
decl_stmt|;
name|uint16_t
name|max_bytes_on_bd
comment|/* Maximum bytes that can be placed on a BD. The BD allocated size should include 2 more bytes (ip alignment) and alignment size (in case the address is not aligned) */
decl_stmt|;
name|uint16_t
name|sge_buff_size
comment|/* Size of the buffers pointed by SGEs */
decl_stmt|;
name|uint8_t
name|approx_mcast_engine_id
comment|/* In Everest2, if is_approx_mcast is set, this field specified which approximate multicast engine is associate with this client */
decl_stmt|;
name|uint8_t
name|rss_engine_id
comment|/* In Everest2, if rss_mode is set, this field specified which RSS engine is associate with this client */
decl_stmt|;
name|struct
name|regpair_t
name|bd_page_base
comment|/* BD page base address at the host */
decl_stmt|;
name|struct
name|regpair_t
name|sge_page_base
comment|/* SGE page base address at the host */
decl_stmt|;
name|struct
name|regpair_t
name|cqe_page_base
comment|/* Completion queue base address */
decl_stmt|;
name|uint8_t
name|is_leading_rss
decl_stmt|;
name|uint8_t
name|is_approx_mcast
decl_stmt|;
name|uint16_t
name|max_agg_size
comment|/* maximal size for the aggregated TPA packets, reprted by the host */
decl_stmt|;
name|uint16_t
name|state
decl_stmt|;
define|#
directive|define
name|CLIENT_INIT_RX_DATA_UCAST_DROP_ALL
value|(0x1<<0)
comment|/* BitField staterx filters state	drop all unicast packets */
define|#
directive|define
name|CLIENT_INIT_RX_DATA_UCAST_DROP_ALL_SHIFT
value|0
define|#
directive|define
name|CLIENT_INIT_RX_DATA_UCAST_ACCEPT_ALL
value|(0x1<<1)
comment|/* BitField staterx filters state	accept all unicast packets (subject to vlan) */
define|#
directive|define
name|CLIENT_INIT_RX_DATA_UCAST_ACCEPT_ALL_SHIFT
value|1
define|#
directive|define
name|CLIENT_INIT_RX_DATA_UCAST_ACCEPT_UNMATCHED
value|(0x1<<2)
comment|/* BitField staterx filters state	accept all unmatched unicast packets (subject to vlan) */
define|#
directive|define
name|CLIENT_INIT_RX_DATA_UCAST_ACCEPT_UNMATCHED_SHIFT
value|2
define|#
directive|define
name|CLIENT_INIT_RX_DATA_MCAST_DROP_ALL
value|(0x1<<3)
comment|/* BitField staterx filters state	drop all multicast packets */
define|#
directive|define
name|CLIENT_INIT_RX_DATA_MCAST_DROP_ALL_SHIFT
value|3
define|#
directive|define
name|CLIENT_INIT_RX_DATA_MCAST_ACCEPT_ALL
value|(0x1<<4)
comment|/* BitField staterx filters state	accept all multicast packets (subject to vlan) */
define|#
directive|define
name|CLIENT_INIT_RX_DATA_MCAST_ACCEPT_ALL_SHIFT
value|4
define|#
directive|define
name|CLIENT_INIT_RX_DATA_BCAST_ACCEPT_ALL
value|(0x1<<5)
comment|/* BitField staterx filters state	accept all broadcast packets (subject to vlan) */
define|#
directive|define
name|CLIENT_INIT_RX_DATA_BCAST_ACCEPT_ALL_SHIFT
value|5
define|#
directive|define
name|CLIENT_INIT_RX_DATA_ACCEPT_ANY_VLAN
value|(0x1<<6)
comment|/* BitField staterx filters state	accept packets matched only by MAC (without checking vlan) */
define|#
directive|define
name|CLIENT_INIT_RX_DATA_ACCEPT_ANY_VLAN_SHIFT
value|6
define|#
directive|define
name|CLIENT_INIT_RX_DATA_RESERVED2
value|(0x1FF<<7)
comment|/* BitField staterx filters state	 */
define|#
directive|define
name|CLIENT_INIT_RX_DATA_RESERVED2_SHIFT
value|7
name|uint16_t
name|cqe_pause_thr_low
comment|/* number of remaining cqes under which, we send pause message */
decl_stmt|;
name|uint16_t
name|cqe_pause_thr_high
comment|/* number of remaining cqes above which, we send un-pause message */
decl_stmt|;
name|uint16_t
name|bd_pause_thr_low
comment|/* number of remaining bds under which, we send pause message */
decl_stmt|;
name|uint16_t
name|bd_pause_thr_high
comment|/* number of remaining bds above which, we send un-pause message */
decl_stmt|;
name|uint16_t
name|sge_pause_thr_low
comment|/* number of remaining sges under which, we send pause message */
decl_stmt|;
name|uint16_t
name|sge_pause_thr_high
comment|/* number of remaining sges above which, we send un-pause message */
decl_stmt|;
name|uint16_t
name|rx_cos_mask
comment|/* the bits that will be set on pfc/ safc paket whith will be genratet when this ring is full. for regular flow control set this to 1 */
decl_stmt|;
name|uint16_t
name|silent_vlan_value
comment|/* The vlan to compare, in case, silent vlan is set */
decl_stmt|;
name|uint16_t
name|silent_vlan_mask
comment|/* The vlan mask, in case, silent vlan is set */
decl_stmt|;
name|uint8_t
name|handle_ptp_pkts_flg
comment|/* If set, this client handles PTP Packets */
decl_stmt|;
name|uint8_t
name|reserved6
index|[
literal|3
index|]
decl_stmt|;
name|uint32_t
name|reserved7
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * client init tx data $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|client_init_tx_data
block|{
name|uint8_t
name|enforce_security_flg
comment|/* if set, security checks will be made for this connection */
decl_stmt|;
name|uint8_t
name|tx_status_block_id
comment|/* the number of status block to update */
decl_stmt|;
name|uint8_t
name|tx_sb_index_number
comment|/* the index to use inside the status block */
decl_stmt|;
name|uint8_t
name|tss_leading_client_id
comment|/* client ID of the leading TSS client, for TX classification source knock out */
decl_stmt|;
name|uint8_t
name|tx_switching_flg
comment|/* if set, tx switching will be done to packets on this connection */
decl_stmt|;
name|uint8_t
name|anti_spoofing_flg
comment|/* if set, anti spoofing check will be done to packets on this connection */
decl_stmt|;
name|uint16_t
name|default_vlan
comment|/* default vlan tag (id+pri). (valid if default_vlan_flg is set) */
decl_stmt|;
name|struct
name|regpair_t
name|tx_bd_page_base
comment|/* BD page base address at the host for TxBdCons */
decl_stmt|;
name|uint16_t
name|state
decl_stmt|;
define|#
directive|define
name|CLIENT_INIT_TX_DATA_UCAST_ACCEPT_ALL
value|(0x1<<0)
comment|/* BitField statetx filters state	accept all unicast packets (subject to vlan) */
define|#
directive|define
name|CLIENT_INIT_TX_DATA_UCAST_ACCEPT_ALL_SHIFT
value|0
define|#
directive|define
name|CLIENT_INIT_TX_DATA_MCAST_ACCEPT_ALL
value|(0x1<<1)
comment|/* BitField statetx filters state	accept all multicast packets (subject to vlan) */
define|#
directive|define
name|CLIENT_INIT_TX_DATA_MCAST_ACCEPT_ALL_SHIFT
value|1
define|#
directive|define
name|CLIENT_INIT_TX_DATA_BCAST_ACCEPT_ALL
value|(0x1<<2)
comment|/* BitField statetx filters state	accept all broadcast packets (subject to vlan) */
define|#
directive|define
name|CLIENT_INIT_TX_DATA_BCAST_ACCEPT_ALL_SHIFT
value|2
define|#
directive|define
name|CLIENT_INIT_TX_DATA_ACCEPT_ANY_VLAN
value|(0x1<<3)
comment|/* BitField statetx filters state	accept packets matched only by MAC (without checking vlan) */
define|#
directive|define
name|CLIENT_INIT_TX_DATA_ACCEPT_ANY_VLAN_SHIFT
value|3
define|#
directive|define
name|CLIENT_INIT_TX_DATA_RESERVED0
value|(0xFFF<<4)
comment|/* BitField statetx filters state	 */
define|#
directive|define
name|CLIENT_INIT_TX_DATA_RESERVED0_SHIFT
value|4
name|uint8_t
name|default_vlan_flg
comment|/* is default vlan valid for this client. */
decl_stmt|;
name|uint8_t
name|force_default_pri_flg
comment|/* if set, force default priority */
decl_stmt|;
name|uint8_t
name|tunnel_lso_inc_ip_id
comment|/* In case of LSO over IPv4 tunnel, whether to increment IP ID on external IP header or internal IP header */
decl_stmt|;
name|uint8_t
name|refuse_outband_vlan_flg
comment|/* if set, the FW will not add outband vlan on packet (even if will exist on BD). */
decl_stmt|;
name|uint8_t
name|tunnel_non_lso_pcsum_location
comment|/* In case of non-Lso encapsulated packets with L4 checksum offload, the pseudo checksum location - on packet or on BD. */
decl_stmt|;
name|uint8_t
name|tunnel_non_lso_outer_ip_csum_location
comment|/* In case of non-Lso encapsulated packets with outer L3 ip checksum offload, the pseudo checksum location - on packet or on BD. */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * client init ramrod data $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|client_init_ramrod_data
block|{
name|struct
name|client_init_general_data
name|general
comment|/* client init general data */
decl_stmt|;
name|struct
name|client_init_rx_data
name|rx
comment|/* client init rx data */
decl_stmt|;
name|struct
name|client_init_tx_data
name|tx
comment|/* client init tx data */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * client update ramrod data $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|client_update_ramrod_data
block|{
name|uint8_t
name|client_id
comment|/* the client to update */
decl_stmt|;
name|uint8_t
name|func_id
comment|/* PCI function ID this client belongs to (0-71) */
decl_stmt|;
name|uint8_t
name|inner_vlan_removal_enable_flg
comment|/* If set, inner VLAN removal is enabled for this client, will be change according to change flag */
decl_stmt|;
name|uint8_t
name|inner_vlan_removal_change_flg
comment|/* If set, inner VLAN removal flag will be set according to the enable flag */
decl_stmt|;
name|uint8_t
name|outer_vlan_removal_enable_flg
comment|/* If set, outer VLAN removal is enabled for this client, will be change according to change flag */
decl_stmt|;
name|uint8_t
name|outer_vlan_removal_change_flg
comment|/* If set, outer VLAN removal flag will be set according to the enable flag */
decl_stmt|;
name|uint8_t
name|anti_spoofing_enable_flg
comment|/* If set, anti spoofing is enabled for this client, will be change according to change flag */
decl_stmt|;
name|uint8_t
name|anti_spoofing_change_flg
comment|/* If set, anti spoofing flag will be set according to anti spoofing flag */
decl_stmt|;
name|uint8_t
name|activate_flg
comment|/* if 0 - the client is deactivate else the client is activate client (1 bit is used) */
decl_stmt|;
name|uint8_t
name|activate_change_flg
comment|/* If set, activate_flg will be checked */
decl_stmt|;
name|uint16_t
name|default_vlan
comment|/* default vlan tag (id+pri). (valid if default_vlan_flg is set) */
decl_stmt|;
name|uint8_t
name|default_vlan_enable_flg
decl_stmt|;
name|uint8_t
name|default_vlan_change_flg
decl_stmt|;
name|uint16_t
name|silent_vlan_value
comment|/* The vlan to compare, in case, silent vlan is set */
decl_stmt|;
name|uint16_t
name|silent_vlan_mask
comment|/* The vlan mask, in case, silent vlan is set */
decl_stmt|;
name|uint8_t
name|silent_vlan_removal_flg
comment|/* if set, and the vlan is equal to requested vlan according to mask, the vlan will be remove without notifying the driver */
decl_stmt|;
name|uint8_t
name|silent_vlan_change_flg
decl_stmt|;
name|uint8_t
name|refuse_outband_vlan_flg
comment|/* If set, the FW will not add outband vlan on packet (even if will exist on BD). */
decl_stmt|;
name|uint8_t
name|refuse_outband_vlan_change_flg
comment|/* If set, refuse_outband_vlan_flg will be updated. */
decl_stmt|;
name|uint8_t
name|tx_switching_flg
comment|/* If set, tx switching will be done to packets on this connection. */
decl_stmt|;
name|uint8_t
name|tx_switching_change_flg
comment|/* If set, tx_switching_flg will be updated. */
decl_stmt|;
name|uint8_t
name|handle_ptp_pkts_flg
comment|/* If set, this client handles PTP Packets */
decl_stmt|;
name|uint8_t
name|handle_ptp_pkts_change_flg
comment|/* If set, handle_ptp_pkts_flg will be updated. */
decl_stmt|;
name|uint16_t
name|reserved1
decl_stmt|;
name|uint32_t
name|echo
comment|/* echo value to be sent to driver on event ring */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The eth storm context of Cstorm  */
end_comment

begin_struct
struct|struct
name|cstorm_eth_st_context
block|{
name|uint32_t
name|__reserved0
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|double_regpair
block|{
name|uint32_t
name|regpair0_lo
comment|/* low word for reg-pair0 */
decl_stmt|;
name|uint32_t
name|regpair0_hi
comment|/* high word for reg-pair0 */
decl_stmt|;
name|uint32_t
name|regpair1_lo
comment|/* low word for reg-pair1 */
decl_stmt|;
name|uint32_t
name|regpair1_hi
comment|/* high word for reg-pair1 */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * 2nd parse bd type used in ethernet tx BDs  */
end_comment

begin_enum
enum|enum
name|eth_2nd_parse_bd_type
block|{
name|ETH_2ND_PARSE_BD_TYPE_LSO_TUNNEL
block|,
name|MAX_ETH_2ND_PARSE_BD_TYPE
block|}
enum|;
end_enum

begin_comment
comment|/*  * Ethernet address typesm used in ethernet tx BDs  */
end_comment

begin_enum
enum|enum
name|eth_addr_type
block|{
name|UNKNOWN_ADDRESS
block|,
name|UNICAST_ADDRESS
block|,
name|MULTICAST_ADDRESS
block|,
name|BROADCAST_ADDRESS
block|,
name|MAX_ETH_ADDR_TYPE
block|}
enum|;
end_enum

begin_comment
comment|/*  *  $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|eth_classify_cmd_header
block|{
name|uint8_t
name|cmd_general_data
decl_stmt|;
define|#
directive|define
name|ETH_CLASSIFY_CMD_HEADER_RX_CMD
value|(0x1<<0)
comment|/* BitField cmd_general_data	should this cmd be applied for Rx */
define|#
directive|define
name|ETH_CLASSIFY_CMD_HEADER_RX_CMD_SHIFT
value|0
define|#
directive|define
name|ETH_CLASSIFY_CMD_HEADER_TX_CMD
value|(0x1<<1)
comment|/* BitField cmd_general_data	should this cmd be applied for Tx */
define|#
directive|define
name|ETH_CLASSIFY_CMD_HEADER_TX_CMD_SHIFT
value|1
define|#
directive|define
name|ETH_CLASSIFY_CMD_HEADER_OPCODE
value|(0x3<<2)
comment|/* BitField cmd_general_data	command opcode for MAC/VLAN/PAIR/IMAC_VNI (use enum classify_rule) */
define|#
directive|define
name|ETH_CLASSIFY_CMD_HEADER_OPCODE_SHIFT
value|2
define|#
directive|define
name|ETH_CLASSIFY_CMD_HEADER_IS_ADD
value|(0x1<<4)
comment|/* BitField cmd_general_data	 (use enum classify_rule_action_type) */
define|#
directive|define
name|ETH_CLASSIFY_CMD_HEADER_IS_ADD_SHIFT
value|4
define|#
directive|define
name|ETH_CLASSIFY_CMD_HEADER_RESERVED0
value|(0x7<<5)
comment|/* BitField cmd_general_data	 */
define|#
directive|define
name|ETH_CLASSIFY_CMD_HEADER_RESERVED0_SHIFT
value|5
name|uint8_t
name|func_id
comment|/* the function id */
decl_stmt|;
name|uint8_t
name|client_id
decl_stmt|;
name|uint8_t
name|reserved1
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * header for eth classification config ramrod $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|eth_classify_header
block|{
name|uint8_t
name|rule_cnt
comment|/* number of rules in classification config ramrod */
decl_stmt|;
name|uint8_t
name|reserved0
decl_stmt|;
name|uint16_t
name|reserved1
decl_stmt|;
name|uint32_t
name|echo
comment|/* echo value to be sent to driver on event ring */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Command for adding/removing a Inner-MAC/VNI classification rule $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|eth_classify_imac_vni_cmd
block|{
name|struct
name|eth_classify_cmd_header
name|header
decl_stmt|;
name|uint32_t
name|vni
decl_stmt|;
name|uint16_t
name|imac_lsb
decl_stmt|;
name|uint16_t
name|imac_mid
decl_stmt|;
name|uint16_t
name|imac_msb
decl_stmt|;
name|uint16_t
name|reserved1
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Command for adding/removing a MAC classification rule $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|eth_classify_mac_cmd
block|{
name|struct
name|eth_classify_cmd_header
name|header
decl_stmt|;
name|uint16_t
name|reserved0
decl_stmt|;
name|uint16_t
name|inner_mac
decl_stmt|;
name|uint16_t
name|mac_lsb
decl_stmt|;
name|uint16_t
name|mac_mid
decl_stmt|;
name|uint16_t
name|mac_msb
decl_stmt|;
name|uint16_t
name|reserved1
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Command for adding/removing a MAC-VLAN pair classification rule $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|eth_classify_pair_cmd
block|{
name|struct
name|eth_classify_cmd_header
name|header
decl_stmt|;
name|uint16_t
name|reserved0
decl_stmt|;
name|uint16_t
name|inner_mac
decl_stmt|;
name|uint16_t
name|mac_lsb
decl_stmt|;
name|uint16_t
name|mac_mid
decl_stmt|;
name|uint16_t
name|mac_msb
decl_stmt|;
name|uint16_t
name|vlan
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Command for adding/removing a VLAN classification rule $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|eth_classify_vlan_cmd
block|{
name|struct
name|eth_classify_cmd_header
name|header
decl_stmt|;
name|uint32_t
name|reserved0
decl_stmt|;
name|uint32_t
name|reserved1
decl_stmt|;
name|uint16_t
name|reserved2
decl_stmt|;
name|uint16_t
name|vlan
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * union for eth classification rule $$KEEP_ENDIANNESS$$  */
end_comment

begin_union
union|union
name|eth_classify_rule_cmd
block|{
name|struct
name|eth_classify_mac_cmd
name|mac
decl_stmt|;
name|struct
name|eth_classify_vlan_cmd
name|vlan
decl_stmt|;
name|struct
name|eth_classify_pair_cmd
name|pair
decl_stmt|;
name|struct
name|eth_classify_imac_vni_cmd
name|imac_vni
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/*  * parameters for eth classification configuration ramrod $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|eth_classify_rules_ramrod_data
block|{
name|struct
name|eth_classify_header
name|header
decl_stmt|;
name|union
name|eth_classify_rule_cmd
name|rules
index|[
name|CLASSIFY_RULES_COUNT
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The data contain client ID need to the ramrod $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|eth_common_ramrod_data
block|{
name|uint32_t
name|client_id
comment|/* id of this client. (5 bits are used) */
decl_stmt|;
name|uint32_t
name|reserved1
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The eth storm context of Ustorm  */
end_comment

begin_struct
struct|struct
name|ustorm_eth_st_context
block|{
name|uint32_t
name|reserved0
index|[
literal|52
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The eth storm context of Tstorm  */
end_comment

begin_struct
struct|struct
name|tstorm_eth_st_context
block|{
name|uint32_t
name|__reserved0
index|[
literal|28
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The eth storm context of Xstorm  */
end_comment

begin_struct
struct|struct
name|xstorm_eth_st_context
block|{
name|uint32_t
name|reserved0
index|[
literal|60
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Ethernet connection context  */
end_comment

begin_struct
struct|struct
name|eth_context
block|{
name|struct
name|ustorm_eth_st_context
name|ustorm_st_context
comment|/* Ustorm storm context */
decl_stmt|;
name|struct
name|tstorm_eth_st_context
name|tstorm_st_context
comment|/* Tstorm storm context */
decl_stmt|;
name|struct
name|xstorm_eth_ag_context
name|xstorm_ag_context
comment|/* Xstorm aggregative context */
decl_stmt|;
name|struct
name|tstorm_eth_ag_context
name|tstorm_ag_context
comment|/* Tstorm aggregative context */
decl_stmt|;
name|struct
name|cstorm_eth_ag_context
name|cstorm_ag_context
comment|/* Cstorm aggregative context */
decl_stmt|;
name|struct
name|ustorm_eth_ag_context
name|ustorm_ag_context
comment|/* Ustorm aggregative context */
decl_stmt|;
name|struct
name|timers_block_context
name|timers_context
comment|/* Timers block context */
decl_stmt|;
name|struct
name|xstorm_eth_st_context
name|xstorm_st_context
comment|/* Xstorm storm context */
decl_stmt|;
name|struct
name|cstorm_eth_st_context
name|cstorm_st_context
comment|/* Cstorm storm context */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * union for sgl and raw data.  */
end_comment

begin_union
union|union
name|eth_sgl_or_raw_data
block|{
name|uint16_t
name|sgl
index|[
literal|8
index|]
comment|/* Scatter-gather list of SGEs used by this packet. This list includes the indices of the SGEs. */
decl_stmt|;
name|uint32_t
name|raw_data
index|[
literal|4
index|]
comment|/* raw data from Tstorm to the driver. */
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/*  * eth FP end aggregation CQE parameters struct $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|eth_end_agg_rx_cqe
block|{
name|uint8_t
name|type_error_flags
decl_stmt|;
define|#
directive|define
name|ETH_END_AGG_RX_CQE_TYPE
value|(0x3<<0)
comment|/* BitField type_error_flags	 (use enum eth_rx_cqe_type) */
define|#
directive|define
name|ETH_END_AGG_RX_CQE_TYPE_SHIFT
value|0
define|#
directive|define
name|ETH_END_AGG_RX_CQE_SGL_RAW_SEL
value|(0x1<<2)
comment|/* BitField type_error_flags	 (use enum eth_rx_fp_sel) */
define|#
directive|define
name|ETH_END_AGG_RX_CQE_SGL_RAW_SEL_SHIFT
value|2
define|#
directive|define
name|ETH_END_AGG_RX_CQE_RESERVED0
value|(0x1F<<3)
comment|/* BitField type_error_flags	 */
define|#
directive|define
name|ETH_END_AGG_RX_CQE_RESERVED0_SHIFT
value|3
name|uint8_t
name|reserved1
decl_stmt|;
name|uint8_t
name|queue_index
comment|/* The aggregation queue index of this packet */
decl_stmt|;
name|uint8_t
name|reserved2
decl_stmt|;
name|uint32_t
name|timestamp_delta
comment|/* timestamp delta between first packet to last packet in aggregation */
decl_stmt|;
name|uint16_t
name|num_of_coalesced_segs
comment|/* Num of coalesced segments. */
decl_stmt|;
name|uint16_t
name|pkt_len
comment|/* Packet length */
decl_stmt|;
name|uint8_t
name|pure_ack_count
comment|/* Number of pure acks coalesced. */
decl_stmt|;
name|uint8_t
name|reserved3
decl_stmt|;
name|uint16_t
name|reserved4
decl_stmt|;
name|union
name|eth_sgl_or_raw_data
name|sgl_or_raw_data
comment|/* union for sgl and raw data. */
decl_stmt|;
name|uint32_t
name|padding
index|[
literal|8
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * regular eth FP CQE parameters struct $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|eth_fast_path_rx_cqe
block|{
name|uint8_t
name|type_error_flags
decl_stmt|;
define|#
directive|define
name|ETH_FAST_PATH_RX_CQE_TYPE
value|(0x3<<0)
comment|/* BitField type_error_flags	 (use enum eth_rx_cqe_type) */
define|#
directive|define
name|ETH_FAST_PATH_RX_CQE_TYPE_SHIFT
value|0
define|#
directive|define
name|ETH_FAST_PATH_RX_CQE_SGL_RAW_SEL
value|(0x1<<2)
comment|/* BitField type_error_flags	 (use enum eth_rx_fp_sel) */
define|#
directive|define
name|ETH_FAST_PATH_RX_CQE_SGL_RAW_SEL_SHIFT
value|2
define|#
directive|define
name|ETH_FAST_PATH_RX_CQE_PHY_DECODE_ERR_FLG
value|(0x1<<3)
comment|/* BitField type_error_flags	Physical layer errors */
define|#
directive|define
name|ETH_FAST_PATH_RX_CQE_PHY_DECODE_ERR_FLG_SHIFT
value|3
define|#
directive|define
name|ETH_FAST_PATH_RX_CQE_IP_BAD_XSUM_FLG
value|(0x1<<4)
comment|/* BitField type_error_flags	IP checksum error */
define|#
directive|define
name|ETH_FAST_PATH_RX_CQE_IP_BAD_XSUM_FLG_SHIFT
value|4
define|#
directive|define
name|ETH_FAST_PATH_RX_CQE_L4_BAD_XSUM_FLG
value|(0x1<<5)
comment|/* BitField type_error_flags	TCP/UDP checksum error */
define|#
directive|define
name|ETH_FAST_PATH_RX_CQE_L4_BAD_XSUM_FLG_SHIFT
value|5
define|#
directive|define
name|ETH_FAST_PATH_RX_CQE_PTP_PKT
value|(0x1<<6)
comment|/* BitField type_error_flags	Is a PTP Timesync Packet */
define|#
directive|define
name|ETH_FAST_PATH_RX_CQE_PTP_PKT_SHIFT
value|6
define|#
directive|define
name|ETH_FAST_PATH_RX_CQE_RESERVED0
value|(0x1<<7)
comment|/* BitField type_error_flags	 */
define|#
directive|define
name|ETH_FAST_PATH_RX_CQE_RESERVED0_SHIFT
value|7
name|uint8_t
name|status_flags
decl_stmt|;
define|#
directive|define
name|ETH_FAST_PATH_RX_CQE_RSS_HASH_TYPE
value|(0x7<<0)
comment|/* BitField status_flags	 (use enum eth_rss_hash_type) */
define|#
directive|define
name|ETH_FAST_PATH_RX_CQE_RSS_HASH_TYPE_SHIFT
value|0
define|#
directive|define
name|ETH_FAST_PATH_RX_CQE_RSS_HASH_FLG
value|(0x1<<3)
comment|/* BitField status_flags	RSS hashing on/off */
define|#
directive|define
name|ETH_FAST_PATH_RX_CQE_RSS_HASH_FLG_SHIFT
value|3
define|#
directive|define
name|ETH_FAST_PATH_RX_CQE_BROADCAST_FLG
value|(0x1<<4)
comment|/* BitField status_flags	if set to 1, this is a broadcast packet */
define|#
directive|define
name|ETH_FAST_PATH_RX_CQE_BROADCAST_FLG_SHIFT
value|4
define|#
directive|define
name|ETH_FAST_PATH_RX_CQE_MAC_MATCH_FLG
value|(0x1<<5)
comment|/* BitField status_flags	if set to 1, the MAC address was matched in the tstorm CAM search */
define|#
directive|define
name|ETH_FAST_PATH_RX_CQE_MAC_MATCH_FLG_SHIFT
value|5
define|#
directive|define
name|ETH_FAST_PATH_RX_CQE_IP_XSUM_NO_VALIDATION_FLG
value|(0x1<<6)
comment|/* BitField status_flags	IP checksum validation was not performed (if packet is not IPv4) */
define|#
directive|define
name|ETH_FAST_PATH_RX_CQE_IP_XSUM_NO_VALIDATION_FLG_SHIFT
value|6
define|#
directive|define
name|ETH_FAST_PATH_RX_CQE_L4_XSUM_NO_VALIDATION_FLG
value|(0x1<<7)
comment|/* BitField status_flags	TCP/UDP checksum validation was not performed (if packet is not TCP/UDP or IPv6 extheaders exist) */
define|#
directive|define
name|ETH_FAST_PATH_RX_CQE_L4_XSUM_NO_VALIDATION_FLG_SHIFT
value|7
name|uint8_t
name|queue_index
comment|/* The aggregation queue index of this packet */
decl_stmt|;
name|uint8_t
name|placement_offset
comment|/* Placement offset from the start of the BD, in bytes */
decl_stmt|;
name|uint32_t
name|rss_hash_result
comment|/* RSS toeplitz hash result */
decl_stmt|;
name|uint16_t
name|vlan_tag
comment|/* Ethernet VLAN tag field */
decl_stmt|;
name|uint16_t
name|pkt_len_or_gro_seg_len
comment|/* Packet length (for non-TPA CQE) or GRO Segment Length (for TPA in GRO Mode) otherwise 0 */
decl_stmt|;
name|uint16_t
name|len_on_bd
comment|/* Number of bytes placed on the BD */
decl_stmt|;
name|struct
name|parsing_flags
name|pars_flags
decl_stmt|;
name|union
name|eth_sgl_or_raw_data
name|sgl_or_raw_data
comment|/* union for sgl and raw data. */
decl_stmt|;
name|uint8_t
name|tunn_type
comment|/* packet tunneling type */
decl_stmt|;
name|uint8_t
name|tunn_inner_hdrs_offset
comment|/* Offset to Inner Headers (for tunn_type != TUNN_TYPE_NONE) */
decl_stmt|;
name|uint16_t
name|reserved1
decl_stmt|;
name|uint32_t
name|tunn_tenant_id
comment|/* Tenant ID (for tunn_type != TUNN_TYPE_NONE */
decl_stmt|;
name|uint32_t
name|padding
index|[
literal|5
index|]
decl_stmt|;
name|uint32_t
name|marker
comment|/* Used internally by the driver */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Command for setting classification flags for a client $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|eth_filter_rules_cmd
block|{
name|uint8_t
name|cmd_general_data
decl_stmt|;
define|#
directive|define
name|ETH_FILTER_RULES_CMD_RX_CMD
value|(0x1<<0)
comment|/* BitField cmd_general_data	should this cmd be applied for Rx */
define|#
directive|define
name|ETH_FILTER_RULES_CMD_RX_CMD_SHIFT
value|0
define|#
directive|define
name|ETH_FILTER_RULES_CMD_TX_CMD
value|(0x1<<1)
comment|/* BitField cmd_general_data	should this cmd be applied for Tx */
define|#
directive|define
name|ETH_FILTER_RULES_CMD_TX_CMD_SHIFT
value|1
define|#
directive|define
name|ETH_FILTER_RULES_CMD_RESERVED0
value|(0x3F<<2)
comment|/* BitField cmd_general_data	 */
define|#
directive|define
name|ETH_FILTER_RULES_CMD_RESERVED0_SHIFT
value|2
name|uint8_t
name|func_id
comment|/* the function id */
decl_stmt|;
name|uint8_t
name|client_id
comment|/* the client id */
decl_stmt|;
name|uint8_t
name|reserved1
decl_stmt|;
name|uint16_t
name|state
decl_stmt|;
define|#
directive|define
name|ETH_FILTER_RULES_CMD_UCAST_DROP_ALL
value|(0x1<<0)
comment|/* BitField state	drop all unicast packets */
define|#
directive|define
name|ETH_FILTER_RULES_CMD_UCAST_DROP_ALL_SHIFT
value|0
define|#
directive|define
name|ETH_FILTER_RULES_CMD_UCAST_ACCEPT_ALL
value|(0x1<<1)
comment|/* BitField state	accept all unicast packets (subject to vlan) */
define|#
directive|define
name|ETH_FILTER_RULES_CMD_UCAST_ACCEPT_ALL_SHIFT
value|1
define|#
directive|define
name|ETH_FILTER_RULES_CMD_UCAST_ACCEPT_UNMATCHED
value|(0x1<<2)
comment|/* BitField state	accept all unmatched unicast packets */
define|#
directive|define
name|ETH_FILTER_RULES_CMD_UCAST_ACCEPT_UNMATCHED_SHIFT
value|2
define|#
directive|define
name|ETH_FILTER_RULES_CMD_MCAST_DROP_ALL
value|(0x1<<3)
comment|/* BitField state	drop all multicast packets */
define|#
directive|define
name|ETH_FILTER_RULES_CMD_MCAST_DROP_ALL_SHIFT
value|3
define|#
directive|define
name|ETH_FILTER_RULES_CMD_MCAST_ACCEPT_ALL
value|(0x1<<4)
comment|/* BitField state	accept all multicast packets (subject to vlan) */
define|#
directive|define
name|ETH_FILTER_RULES_CMD_MCAST_ACCEPT_ALL_SHIFT
value|4
define|#
directive|define
name|ETH_FILTER_RULES_CMD_BCAST_ACCEPT_ALL
value|(0x1<<5)
comment|/* BitField state	accept all broadcast packets (subject to vlan) */
define|#
directive|define
name|ETH_FILTER_RULES_CMD_BCAST_ACCEPT_ALL_SHIFT
value|5
define|#
directive|define
name|ETH_FILTER_RULES_CMD_ACCEPT_ANY_VLAN
value|(0x1<<6)
comment|/* BitField state	accept packets matched only by MAC (without checking vlan) */
define|#
directive|define
name|ETH_FILTER_RULES_CMD_ACCEPT_ANY_VLAN_SHIFT
value|6
define|#
directive|define
name|ETH_FILTER_RULES_CMD_RESERVED2
value|(0x1FF<<7)
comment|/* BitField state	 */
define|#
directive|define
name|ETH_FILTER_RULES_CMD_RESERVED2_SHIFT
value|7
name|uint16_t
name|reserved3
decl_stmt|;
name|struct
name|regpair_t
name|reserved4
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * parameters for eth classification filters ramrod $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|eth_filter_rules_ramrod_data
block|{
name|struct
name|eth_classify_header
name|header
decl_stmt|;
name|struct
name|eth_filter_rules_cmd
name|rules
index|[
name|FILTER_RULES_COUNT
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Hsi version  */
end_comment

begin_enum
enum|enum
name|eth_fp_hsi_ver
block|{
name|ETH_FP_HSI_VER_0
comment|/* Hsi which does not support tunnelling */
block|,
name|ETH_FP_HSI_VER_1
comment|/* Hsi does support tunnelling */
block|,
name|ETH_FP_HSI_VER_2
comment|/* Hsi which supports tunneling and UFP */
block|,
name|MAX_ETH_FP_HSI_VER
block|}
enum|;
end_enum

begin_comment
comment|/*  * parameters for eth classification configuration ramrod $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|eth_general_rules_ramrod_data
block|{
name|struct
name|eth_classify_header
name|header
decl_stmt|;
name|union
name|eth_classify_rule_cmd
name|rules
index|[
name|CLASSIFY_RULES_COUNT
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The data for Halt ramrod  */
end_comment

begin_struct
struct|struct
name|eth_halt_ramrod_data
block|{
name|uint32_t
name|client_id
comment|/* id of this client. (5 bits are used) */
decl_stmt|;
name|uint32_t
name|reserved0
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * destination and source mac address.  */
end_comment

begin_struct
struct|struct
name|eth_mac_addresses
block|{
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|dst_mid
comment|/* destination mac address 16 middle bits */
decl_stmt|;
name|uint16_t
name|dst_lo
comment|/* destination mac address 16 low bits */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|dst_lo
comment|/* destination mac address 16 low bits */
decl_stmt|;
name|uint16_t
name|dst_mid
comment|/* destination mac address 16 middle bits */
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|src_lo
comment|/* source mac address 16 low bits */
decl_stmt|;
name|uint16_t
name|dst_hi
comment|/* destination mac address 16 high bits */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|dst_hi
comment|/* destination mac address 16 high bits */
decl_stmt|;
name|uint16_t
name|src_lo
comment|/* source mac address 16 low bits */
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|src_hi
comment|/* source mac address 16 high bits */
decl_stmt|;
name|uint16_t
name|src_mid
comment|/* source mac address 16 middle bits */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|src_mid
comment|/* source mac address 16 middle bits */
decl_stmt|;
name|uint16_t
name|src_hi
comment|/* source mac address 16 high bits */
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/*  * tunneling related data. $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|eth_tunnel_data
block|{
name|uint16_t
name|dst_lo
comment|/* destination mac address 16 low bits */
decl_stmt|;
name|uint16_t
name|dst_mid
comment|/* destination mac address 16 middle bits */
decl_stmt|;
name|uint16_t
name|dst_hi
comment|/* destination mac address 16 high bits */
decl_stmt|;
name|uint16_t
name|fw_ip_hdr_csum
comment|/* Fw Ip header checksum (with ALL ip header fields) for the outer IP header */
decl_stmt|;
name|uint16_t
name|pseudo_csum
comment|/* Pseudo checksum with  length  field=0 */
decl_stmt|;
name|uint8_t
name|ip_hdr_start_inner_w
comment|/* Inner IP header offset in WORDs (16-bit) from start of packet */
decl_stmt|;
name|uint8_t
name|flags
decl_stmt|;
define|#
directive|define
name|ETH_TUNNEL_DATA_IPV6_OUTER
value|(0x1<<0)
comment|/* BitField flags	Set in case outer IP header is ipV6 */
define|#
directive|define
name|ETH_TUNNEL_DATA_IPV6_OUTER_SHIFT
value|0
define|#
directive|define
name|ETH_TUNNEL_DATA_RESERVED
value|(0x7F<<1)
comment|/* BitField flags	Should be set with 0 */
define|#
directive|define
name|ETH_TUNNEL_DATA_RESERVED_SHIFT
value|1
block|}
struct|;
end_struct

begin_comment
comment|/*  * union for mac addresses and for tunneling data. considered as tunneling data only if (tunnel_exist == 1).  */
end_comment

begin_union
union|union
name|eth_mac_addr_or_tunnel_data
block|{
name|struct
name|eth_mac_addresses
name|mac_addr
comment|/* destination and source mac addresses. */
decl_stmt|;
name|struct
name|eth_tunnel_data
name|tunnel_data
comment|/* tunneling related data. */
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/*  * Command for setting multicast classification for a client $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|eth_multicast_rules_cmd
block|{
name|uint8_t
name|cmd_general_data
decl_stmt|;
define|#
directive|define
name|ETH_MULTICAST_RULES_CMD_RX_CMD
value|(0x1<<0)
comment|/* BitField cmd_general_data	should this cmd be applied for Rx */
define|#
directive|define
name|ETH_MULTICAST_RULES_CMD_RX_CMD_SHIFT
value|0
define|#
directive|define
name|ETH_MULTICAST_RULES_CMD_TX_CMD
value|(0x1<<1)
comment|/* BitField cmd_general_data	should this cmd be applied for Tx */
define|#
directive|define
name|ETH_MULTICAST_RULES_CMD_TX_CMD_SHIFT
value|1
define|#
directive|define
name|ETH_MULTICAST_RULES_CMD_IS_ADD
value|(0x1<<2)
comment|/* BitField cmd_general_data	1 for add rule, 0 for remove rule */
define|#
directive|define
name|ETH_MULTICAST_RULES_CMD_IS_ADD_SHIFT
value|2
define|#
directive|define
name|ETH_MULTICAST_RULES_CMD_RESERVED0
value|(0x1F<<3)
comment|/* BitField cmd_general_data	 */
define|#
directive|define
name|ETH_MULTICAST_RULES_CMD_RESERVED0_SHIFT
value|3
name|uint8_t
name|func_id
comment|/* the function id */
decl_stmt|;
name|uint8_t
name|bin_id
comment|/* the bin to add this function to (0-255) */
decl_stmt|;
name|uint8_t
name|engine_id
comment|/* the approximate multicast engine id */
decl_stmt|;
name|uint32_t
name|reserved2
decl_stmt|;
name|struct
name|regpair_t
name|reserved3
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * parameters for multicast classification ramrod $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|eth_multicast_rules_ramrod_data
block|{
name|struct
name|eth_classify_header
name|header
decl_stmt|;
name|struct
name|eth_multicast_rules_cmd
name|rules
index|[
name|MULTICAST_RULES_COUNT
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Place holder for ramrods protocol specific data  */
end_comment

begin_struct
struct|struct
name|ramrod_data
block|{
name|uint32_t
name|data_lo
decl_stmt|;
name|uint32_t
name|data_hi
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * union for ramrod data for Ethernet protocol (CQE) (force size of 16 bits)  */
end_comment

begin_union
union|union
name|eth_ramrod_data
block|{
name|struct
name|ramrod_data
name|general
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/*  * RSS toeplitz hash type, as reported in CQE  */
end_comment

begin_enum
enum|enum
name|eth_rss_hash_type
block|{
name|DEFAULT_HASH_TYPE
block|,
name|IPV4_HASH_TYPE
block|,
name|TCP_IPV4_HASH_TYPE
block|,
name|IPV6_HASH_TYPE
block|,
name|TCP_IPV6_HASH_TYPE
block|,
name|VLAN_PRI_HASH_TYPE
block|,
name|E1HOV_PRI_HASH_TYPE
block|,
name|DSCP_HASH_TYPE
block|,
name|MAX_ETH_RSS_HASH_TYPE
block|}
enum|;
end_enum

begin_comment
comment|/*  * Ethernet RSS mode  */
end_comment

begin_enum
enum|enum
name|eth_rss_mode
block|{
name|ETH_RSS_MODE_DISABLED
block|,
name|ETH_RSS_MODE_REGULAR
comment|/* Regular (ndis-like) RSS */
block|,
name|ETH_RSS_MODE_ESX51
comment|/* RSS mode for Vmware ESX 5.1 (Only do RSS for VXLAN packets) */
block|,
name|ETH_RSS_MODE_VLAN_PRI
comment|/* RSS based on inner-vlan priority field (E1/E1h Only) */
block|,
name|ETH_RSS_MODE_E1HOV_PRI
comment|/* RSS based on outer-vlan priority field (E1/E1h Only) */
block|,
name|ETH_RSS_MODE_IP_DSCP
comment|/* RSS based on IPv4 DSCP field (E1/E1h Only) */
block|,
name|MAX_ETH_RSS_MODE
block|}
enum|;
end_enum

begin_comment
comment|/*  * parameters for RSS update ramrod (E2) $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|eth_rss_update_ramrod_data
block|{
name|uint8_t
name|rss_engine_id
decl_stmt|;
name|uint8_t
name|rss_mode
comment|/* The RSS mode for this function */
decl_stmt|;
name|uint16_t
name|capabilities
decl_stmt|;
define|#
directive|define
name|ETH_RSS_UPDATE_RAMROD_DATA_IPV4_CAPABILITY
value|(0x1<<0)
comment|/* BitField capabilitiesFunction RSS capabilities	configuration of the IpV4 2-tuple capability */
define|#
directive|define
name|ETH_RSS_UPDATE_RAMROD_DATA_IPV4_CAPABILITY_SHIFT
value|0
define|#
directive|define
name|ETH_RSS_UPDATE_RAMROD_DATA_IPV4_TCP_CAPABILITY
value|(0x1<<1)
comment|/* BitField capabilitiesFunction RSS capabilities	configuration of the IpV4 4-tuple capability for TCP */
define|#
directive|define
name|ETH_RSS_UPDATE_RAMROD_DATA_IPV4_TCP_CAPABILITY_SHIFT
value|1
define|#
directive|define
name|ETH_RSS_UPDATE_RAMROD_DATA_IPV4_UDP_CAPABILITY
value|(0x1<<2)
comment|/* BitField capabilitiesFunction RSS capabilities	configuration of the IpV4 4-tuple capability for UDP */
define|#
directive|define
name|ETH_RSS_UPDATE_RAMROD_DATA_IPV4_UDP_CAPABILITY_SHIFT
value|2
define|#
directive|define
name|ETH_RSS_UPDATE_RAMROD_DATA_IPV4_VXLAN_CAPABILITY
value|(0x1<<3)
comment|/* BitField capabilitiesFunction RSS capabilities	configuration of the IpV4 4-tuple capability for VXLAN Tunnels */
define|#
directive|define
name|ETH_RSS_UPDATE_RAMROD_DATA_IPV4_VXLAN_CAPABILITY_SHIFT
value|3
define|#
directive|define
name|ETH_RSS_UPDATE_RAMROD_DATA_IPV6_CAPABILITY
value|(0x1<<4)
comment|/* BitField capabilitiesFunction RSS capabilities	configuration of the IpV6 2-tuple capability */
define|#
directive|define
name|ETH_RSS_UPDATE_RAMROD_DATA_IPV6_CAPABILITY_SHIFT
value|4
define|#
directive|define
name|ETH_RSS_UPDATE_RAMROD_DATA_IPV6_TCP_CAPABILITY
value|(0x1<<5)
comment|/* BitField capabilitiesFunction RSS capabilities	configuration of the IpV6 4-tuple capability for TCP */
define|#
directive|define
name|ETH_RSS_UPDATE_RAMROD_DATA_IPV6_TCP_CAPABILITY_SHIFT
value|5
define|#
directive|define
name|ETH_RSS_UPDATE_RAMROD_DATA_IPV6_UDP_CAPABILITY
value|(0x1<<6)
comment|/* BitField capabilitiesFunction RSS capabilities	configuration of the IpV6 4-tuple capability for UDP */
define|#
directive|define
name|ETH_RSS_UPDATE_RAMROD_DATA_IPV6_UDP_CAPABILITY_SHIFT
value|6
define|#
directive|define
name|ETH_RSS_UPDATE_RAMROD_DATA_IPV6_VXLAN_CAPABILITY
value|(0x1<<7)
comment|/* BitField capabilitiesFunction RSS capabilities	configuration of the IpV6 4-tuple capability for VXLAN Tunnels */
define|#
directive|define
name|ETH_RSS_UPDATE_RAMROD_DATA_IPV6_VXLAN_CAPABILITY_SHIFT
value|7
define|#
directive|define
name|ETH_RSS_UPDATE_RAMROD_DATA_TUNN_INNER_HDRS_CAPABILITY
value|(0x1<<8)
comment|/* BitField capabilitiesFunction RSS capabilities	configuration of Tunnel Inner Headers capability. */
define|#
directive|define
name|ETH_RSS_UPDATE_RAMROD_DATA_TUNN_INNER_HDRS_CAPABILITY_SHIFT
value|8
define|#
directive|define
name|ETH_RSS_UPDATE_RAMROD_DATA_UPDATE_RSS_KEY
value|(0x1<<9)
comment|/* BitField capabilitiesFunction RSS capabilities	if set update the rss keys */
define|#
directive|define
name|ETH_RSS_UPDATE_RAMROD_DATA_UPDATE_RSS_KEY_SHIFT
value|9
define|#
directive|define
name|ETH_RSS_UPDATE_RAMROD_DATA_RESERVED
value|(0x3F<<10)
comment|/* BitField capabilitiesFunction RSS capabilities	 */
define|#
directive|define
name|ETH_RSS_UPDATE_RAMROD_DATA_RESERVED_SHIFT
value|10
name|uint8_t
name|rss_result_mask
comment|/* The mask for the lower byte of RSS result - defines which section of the indirection table will be used. To enable all table put here 0x7F */
decl_stmt|;
name|uint8_t
name|reserved3
decl_stmt|;
name|uint16_t
name|reserved4
decl_stmt|;
name|uint8_t
name|indirection_table
index|[
name|T_ETH_INDIRECTION_TABLE_SIZE
index|]
comment|/* RSS indirection table */
decl_stmt|;
name|uint32_t
name|rss_key
index|[
name|T_ETH_RSS_KEY
index|]
comment|/* RSS key supplied as by OS */
decl_stmt|;
name|uint32_t
name|echo
decl_stmt|;
name|uint32_t
name|reserved5
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The eth Rx Buffer Descriptor  */
end_comment

begin_struct
struct|struct
name|eth_rx_bd
block|{
name|uint32_t
name|addr_lo
comment|/* Single continuous buffer low pointer */
decl_stmt|;
name|uint32_t
name|addr_hi
comment|/* Single continuous buffer high pointer */
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|eth_rx_bd_next_page
block|{
name|uint32_t
name|addr_lo
comment|/* Next page low pointer */
decl_stmt|;
name|uint32_t
name|addr_hi
comment|/* Next page high pointer */
decl_stmt|;
name|uint8_t
name|reserved
index|[
literal|8
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Eth Rx Cqe structure- general structure for ramrods $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|common_ramrod_eth_rx_cqe
block|{
name|uint8_t
name|ramrod_type
decl_stmt|;
define|#
directive|define
name|COMMON_RAMROD_ETH_RX_CQE_TYPE
value|(0x3<<0)
comment|/* BitField ramrod_type	 (use enum eth_rx_cqe_type) */
define|#
directive|define
name|COMMON_RAMROD_ETH_RX_CQE_TYPE_SHIFT
value|0
define|#
directive|define
name|COMMON_RAMROD_ETH_RX_CQE_ERROR
value|(0x1<<2)
comment|/* BitField ramrod_type	 */
define|#
directive|define
name|COMMON_RAMROD_ETH_RX_CQE_ERROR_SHIFT
value|2
define|#
directive|define
name|COMMON_RAMROD_ETH_RX_CQE_RESERVED0
value|(0x1F<<3)
comment|/* BitField ramrod_type	 */
define|#
directive|define
name|COMMON_RAMROD_ETH_RX_CQE_RESERVED0_SHIFT
value|3
name|uint8_t
name|conn_type
comment|/* only 3 bits are used */
decl_stmt|;
name|uint16_t
name|reserved1
comment|/* protocol specific data */
decl_stmt|;
name|uint32_t
name|conn_and_cmd_data
decl_stmt|;
define|#
directive|define
name|COMMON_RAMROD_ETH_RX_CQE_CID
value|(0xFFFFFF<<0)
comment|/* BitField conn_and_cmd_data	 */
define|#
directive|define
name|COMMON_RAMROD_ETH_RX_CQE_CID_SHIFT
value|0
define|#
directive|define
name|COMMON_RAMROD_ETH_RX_CQE_CMD_ID
value|(0xFF<<24)
comment|/* BitField conn_and_cmd_data	command id of the ramrod- use RamrodCommandIdEnum */
define|#
directive|define
name|COMMON_RAMROD_ETH_RX_CQE_CMD_ID_SHIFT
value|24
name|struct
name|ramrod_data
name|protocol_data
comment|/* protocol specific data */
decl_stmt|;
name|uint32_t
name|echo
decl_stmt|;
name|uint32_t
name|reserved2
index|[
literal|11
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Rx Last CQE in page (in ETH)  */
end_comment

begin_struct
struct|struct
name|eth_rx_cqe_next_page
block|{
name|uint32_t
name|addr_lo
comment|/* Next page low pointer */
decl_stmt|;
name|uint32_t
name|addr_hi
comment|/* Next page high pointer */
decl_stmt|;
name|uint32_t
name|reserved
index|[
literal|14
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * union for all eth rx cqe types (fix their sizes)  */
end_comment

begin_union
union|union
name|eth_rx_cqe
block|{
name|struct
name|eth_fast_path_rx_cqe
name|fast_path_cqe
decl_stmt|;
name|struct
name|common_ramrod_eth_rx_cqe
name|ramrod_cqe
decl_stmt|;
name|struct
name|eth_rx_cqe_next_page
name|next_page_cqe
decl_stmt|;
name|struct
name|eth_end_agg_rx_cqe
name|end_agg_cqe
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/*  * Values for RX ETH CQE type field  */
end_comment

begin_enum
enum|enum
name|eth_rx_cqe_type
block|{
name|RX_ETH_CQE_TYPE_ETH_FASTPATH
comment|/* Fast path CQE */
block|,
name|RX_ETH_CQE_TYPE_ETH_RAMROD
comment|/* Slow path CQE */
block|,
name|RX_ETH_CQE_TYPE_ETH_START_AGG
comment|/* Fast path CQE */
block|,
name|RX_ETH_CQE_TYPE_ETH_STOP_AGG
comment|/* Slow path CQE */
block|,
name|MAX_ETH_RX_CQE_TYPE
block|}
enum|;
end_enum

begin_comment
comment|/*  * Type of SGL/Raw field in ETH RX fast path CQE  */
end_comment

begin_enum
enum|enum
name|eth_rx_fp_sel
block|{
name|ETH_FP_CQE_REGULAR
comment|/* Regular CQE- no extra data */
block|,
name|ETH_FP_CQE_RAW
comment|/* Extra data is raw data- iscsi OOO */
block|,
name|MAX_ETH_RX_FP_SEL
block|}
enum|;
end_enum

begin_comment
comment|/*  * The eth Rx SGE Descriptor  */
end_comment

begin_struct
struct|struct
name|eth_rx_sge
block|{
name|uint32_t
name|addr_lo
comment|/* Single continuous buffer low pointer */
decl_stmt|;
name|uint32_t
name|addr_hi
comment|/* Single continuous buffer high pointer */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * common data for all protocols $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|spe_hdr_t
block|{
name|uint32_t
name|conn_and_cmd_data
decl_stmt|;
define|#
directive|define
name|SPE_HDR_T_CID
value|(0xFFFFFF<<0)
comment|/* BitField conn_and_cmd_data	 */
define|#
directive|define
name|SPE_HDR_T_CID_SHIFT
value|0
define|#
directive|define
name|SPE_HDR_T_CMD_ID
value|(0xFFUL<<24)
comment|/* BitField conn_and_cmd_data	command id of the ramrod- use enum common_spqe_cmd_id/eth_spqe_cmd_id/toe_spqe_cmd_id  */
define|#
directive|define
name|SPE_HDR_T_CMD_ID_SHIFT
value|24
name|uint16_t
name|type
decl_stmt|;
define|#
directive|define
name|SPE_HDR_T_CONN_TYPE
value|(0xFF<<0)
comment|/* BitField type	connection type. (3 bits are used) (use enum connection_type) */
define|#
directive|define
name|SPE_HDR_T_CONN_TYPE_SHIFT
value|0
define|#
directive|define
name|SPE_HDR_T_FUNCTION_ID
value|(0xFF<<8)
comment|/* BitField type	 */
define|#
directive|define
name|SPE_HDR_T_FUNCTION_ID_SHIFT
value|8
name|uint16_t
name|reserved1
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * specific data for ethernet slow path element  */
end_comment

begin_union
union|union
name|eth_specific_data
block|{
name|uint8_t
name|protocol_data
index|[
literal|8
index|]
comment|/* to fix this structure size to 8 bytes */
decl_stmt|;
name|struct
name|regpair_t
name|client_update_ramrod_data
comment|/* The address of the data for client update ramrod */
decl_stmt|;
name|struct
name|regpair_t
name|client_init_ramrod_init_data
comment|/* The data for client setup ramrod */
decl_stmt|;
name|struct
name|eth_halt_ramrod_data
name|halt_ramrod_data
comment|/* Includes the client id to be deleted */
decl_stmt|;
name|struct
name|regpair_t
name|update_data_addr
comment|/* physical address of the eth_rss_update_ramrod_data struct, as allocated by the driver */
decl_stmt|;
name|struct
name|eth_common_ramrod_data
name|common_ramrod_data
comment|/* The data contain client ID need to the ramrod */
decl_stmt|;
name|struct
name|regpair_t
name|classify_cfg_addr
comment|/* physical address of the eth_classify_rules_ramrod_data struct, as allocated by the driver */
decl_stmt|;
name|struct
name|regpair_t
name|filter_cfg_addr
comment|/* physical address of the eth_filter_cfg_ramrod_data struct, as allocated by the driver */
decl_stmt|;
name|struct
name|regpair_t
name|mcast_cfg_addr
comment|/* physical address of the eth_mcast_cfg_ramrod_data struct, as allocated by the driver */
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/*  * Ethernet slow path element  */
end_comment

begin_struct
struct|struct
name|eth_spe
block|{
name|struct
name|spe_hdr_t
name|hdr
comment|/* common data for all protocols */
decl_stmt|;
name|union
name|eth_specific_data
name|data
comment|/* data specific to ethernet protocol */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Ethernet command ID for slow path elements  */
end_comment

begin_enum
enum|enum
name|eth_spqe_cmd_id
block|{
name|RAMROD_CMD_ID_ETH_UNUSED
block|,
name|RAMROD_CMD_ID_ETH_CLIENT_SETUP
comment|/* Setup a new L2 client */
block|,
name|RAMROD_CMD_ID_ETH_HALT
comment|/* Halt an L2 client */
block|,
name|RAMROD_CMD_ID_ETH_FORWARD_SETUP
comment|/* Setup a new FW channel */
block|,
name|RAMROD_CMD_ID_ETH_TX_QUEUE_SETUP
comment|/* Setup a new Tx only queue */
block|,
name|RAMROD_CMD_ID_ETH_CLIENT_UPDATE
comment|/* Update an L2 client configuration */
block|,
name|RAMROD_CMD_ID_ETH_EMPTY
comment|/* Empty ramrod - used to synchronize iSCSI OOO */
block|,
name|RAMROD_CMD_ID_ETH_TERMINATE
comment|/* Terminate an L2 client */
block|,
name|RAMROD_CMD_ID_ETH_TPA_UPDATE
comment|/* update the tpa roles in L2 client */
block|,
name|RAMROD_CMD_ID_ETH_CLASSIFICATION_RULES
comment|/* Add/remove classification filters for L2 client (in E2/E3 only) */
block|,
name|RAMROD_CMD_ID_ETH_FILTER_RULES
comment|/* Add/remove classification filters for L2 client (in E2/E3 only) */
block|,
name|RAMROD_CMD_ID_ETH_MULTICAST_RULES
comment|/* Add/remove multicast classification bin (in E2/E3 only) */
block|,
name|RAMROD_CMD_ID_ETH_RSS_UPDATE
comment|/* Update RSS configuration */
block|,
name|RAMROD_CMD_ID_ETH_SET_MAC
comment|/* Update RSS configuration */
block|,
name|MAX_ETH_SPQE_CMD_ID
block|}
enum|;
end_enum

begin_comment
comment|/*  * eth tpa update command  */
end_comment

begin_enum
enum|enum
name|eth_tpa_update_command
block|{
name|TPA_UPDATE_NONE_COMMAND
comment|/* nop command */
block|,
name|TPA_UPDATE_ENABLE_COMMAND
comment|/* enable command */
block|,
name|TPA_UPDATE_DISABLE_COMMAND
comment|/* disable command */
block|,
name|MAX_ETH_TPA_UPDATE_COMMAND
block|}
enum|;
end_enum

begin_comment
comment|/*  * In case of LSO over IPv4 tunnel, whether to increment IP ID on external IP header or internal IP header  */
end_comment

begin_enum
enum|enum
name|eth_tunnel_lso_inc_ip_id
block|{
name|EXT_HEADER
comment|/* Increment IP ID of external header (HW works on external, FW works on internal */
block|,
name|INT_HEADER
comment|/* Increment IP ID of internal header (HW works on internal, FW works on external */
block|,
name|MAX_ETH_TUNNEL_LSO_INC_IP_ID
block|}
enum|;
end_enum

begin_comment
comment|/*  * In case tunnel exist and L4 checksum offload (or outer ip header checksum), the pseudo checksum location, on packet or on BD.  */
end_comment

begin_enum
enum|enum
name|eth_tunnel_non_lso_csum_location
block|{
name|CSUM_ON_PKT
comment|/* checksum is on the packet. */
block|,
name|CSUM_ON_BD
comment|/* checksum is on the BD. */
block|,
name|MAX_ETH_TUNNEL_NON_LSO_CSUM_LOCATION
block|}
enum|;
end_enum

begin_comment
comment|/*  * Packet Tunneling Type  */
end_comment

begin_enum
enum|enum
name|eth_tunn_type
block|{
name|TUNN_TYPE_NONE
block|,
name|TUNN_TYPE_VXLAN
block|,
name|TUNN_TYPE_L2_GRE
comment|/* Ethernet over GRE */
block|,
name|TUNN_TYPE_IPV4_GRE
comment|/* IPv4 over GRE */
block|,
name|TUNN_TYPE_IPV6_GRE
comment|/* IPv6 over GRE */
block|,
name|TUNN_TYPE_L2_GENEVE
comment|/* Ethernet over GENEVE */
block|,
name|TUNN_TYPE_IPV4_GENEVE
comment|/* IPv4 over GENEVE */
block|,
name|TUNN_TYPE_IPV6_GENEVE
comment|/* IPv6 over GENEVE */
block|,
name|MAX_ETH_TUNN_TYPE
block|}
enum|;
end_enum

begin_comment
comment|/*  * Tx regular BD structure $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|eth_tx_bd
block|{
name|uint32_t
name|addr_lo
comment|/* Single continuous buffer low pointer */
decl_stmt|;
name|uint32_t
name|addr_hi
comment|/* Single continuous buffer high pointer */
decl_stmt|;
name|uint16_t
name|total_pkt_bytes
comment|/* Size of the entire packet, valid for non-LSO packets */
decl_stmt|;
name|uint16_t
name|nbytes
comment|/* Size of the data represented by the BD */
decl_stmt|;
name|uint8_t
name|reserved
index|[
literal|4
index|]
comment|/* keeps same size as other eth tx bd types */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * structure for easy accessibility to assembler  */
end_comment

begin_struct
struct|struct
name|eth_tx_bd_flags
block|{
name|uint8_t
name|as_bitfield
decl_stmt|;
define|#
directive|define
name|ETH_TX_BD_FLAGS_IP_CSUM
value|(0x1<<0)
comment|/* BitField as_bitfield	IP CKSUM flag,Relevant in START */
define|#
directive|define
name|ETH_TX_BD_FLAGS_IP_CSUM_SHIFT
value|0
define|#
directive|define
name|ETH_TX_BD_FLAGS_L4_CSUM
value|(0x1<<1)
comment|/* BitField as_bitfield	L4 CKSUM flag,Relevant in START */
define|#
directive|define
name|ETH_TX_BD_FLAGS_L4_CSUM_SHIFT
value|1
define|#
directive|define
name|ETH_TX_BD_FLAGS_VLAN_MODE
value|(0x3<<2)
comment|/* BitField as_bitfield	00 - no vlan; 01 - inband Vlan; 10 outband Vlan (use enum eth_tx_vlan_type) */
define|#
directive|define
name|ETH_TX_BD_FLAGS_VLAN_MODE_SHIFT
value|2
define|#
directive|define
name|ETH_TX_BD_FLAGS_START_BD
value|(0x1<<4)
comment|/* BitField as_bitfield	Start of packet BD */
define|#
directive|define
name|ETH_TX_BD_FLAGS_START_BD_SHIFT
value|4
define|#
directive|define
name|ETH_TX_BD_FLAGS_IS_UDP
value|(0x1<<5)
comment|/* BitField as_bitfield	flag that indicates that the current packet is a udp packet */
define|#
directive|define
name|ETH_TX_BD_FLAGS_IS_UDP_SHIFT
value|5
define|#
directive|define
name|ETH_TX_BD_FLAGS_SW_LSO
value|(0x1<<6)
comment|/* BitField as_bitfield	LSO flag, Relevant in START */
define|#
directive|define
name|ETH_TX_BD_FLAGS_SW_LSO_SHIFT
value|6
define|#
directive|define
name|ETH_TX_BD_FLAGS_IPV6
value|(0x1<<7)
comment|/* BitField as_bitfield	set in case ipV6 packet, Relevant in START */
define|#
directive|define
name|ETH_TX_BD_FLAGS_IPV6_SHIFT
value|7
block|}
struct|;
end_struct

begin_comment
comment|/*  * The eth Tx Buffer Descriptor $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|eth_tx_start_bd
block|{
name|uint32_t
name|addr_lo
comment|/* Single continuous buffer low pointer */
decl_stmt|;
name|uint32_t
name|addr_hi
comment|/* Single continuous buffer high pointer */
decl_stmt|;
name|uint16_t
name|nbd
comment|/* Num of BDs in packet: include parsInfoBD, Relevant in START(only in Everest) */
decl_stmt|;
name|uint16_t
name|nbytes
comment|/* Size of the data represented by the BD */
decl_stmt|;
name|uint16_t
name|vlan_or_ethertype
comment|/* Vlan structure: vlan_id is in lsb, then cfi and then priority vlan_id 12 bits (lsb), cfi 1 bit, priority 3 bits. In E2, this field should be set with etherType for VFs with no vlan */
decl_stmt|;
name|struct
name|eth_tx_bd_flags
name|bd_flags
decl_stmt|;
name|uint8_t
name|general_data
decl_stmt|;
define|#
directive|define
name|ETH_TX_START_BD_HDR_NBDS
value|(0x7<<0)
comment|/* BitField general_data	contains the number of BDs that contain Ethernet/IP/TCP headers, for full/partial LSO modes */
define|#
directive|define
name|ETH_TX_START_BD_HDR_NBDS_SHIFT
value|0
define|#
directive|define
name|ETH_TX_START_BD_NO_ADDED_TAGS
value|(0x1<<3)
comment|/* BitField general_data	If set, do not add any additional tags to the packet including MF Tags, Default VLAN or VLAN for the sake of DCB */
define|#
directive|define
name|ETH_TX_START_BD_NO_ADDED_TAGS_SHIFT
value|3
define|#
directive|define
name|ETH_TX_START_BD_FORCE_VLAN_MODE
value|(0x1<<4)
comment|/* BitField general_data	force vlan mode according to bds (vlan mode can change accroding to global configuration) */
define|#
directive|define
name|ETH_TX_START_BD_FORCE_VLAN_MODE_SHIFT
value|4
define|#
directive|define
name|ETH_TX_START_BD_PARSE_NBDS
value|(0x3<<5)
comment|/* BitField general_data	Determines the number of parsing BDs in packet. Number of parsing BDs in packet is (parse_nbds+1). */
define|#
directive|define
name|ETH_TX_START_BD_PARSE_NBDS_SHIFT
value|5
define|#
directive|define
name|ETH_TX_START_BD_TUNNEL_EXIST
value|(0x1<<7)
comment|/* BitField general_data	set in case of tunneling encapsulated packet */
define|#
directive|define
name|ETH_TX_START_BD_TUNNEL_EXIST_SHIFT
value|7
block|}
struct|;
end_struct

begin_comment
comment|/*  * Tx parsing BD structure for ETH E1/E1h $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|eth_tx_parse_bd_e1x
block|{
name|uint16_t
name|global_data
decl_stmt|;
define|#
directive|define
name|ETH_TX_PARSE_BD_E1X_IP_HDR_START_OFFSET_W
value|(0xF<<0)
comment|/* BitField global_data	IP header Offset in WORDs from start of packet */
define|#
directive|define
name|ETH_TX_PARSE_BD_E1X_IP_HDR_START_OFFSET_W_SHIFT
value|0
define|#
directive|define
name|ETH_TX_PARSE_BD_E1X_ETH_ADDR_TYPE
value|(0x3<<4)
comment|/* BitField global_data	marks ethernet address type (use enum eth_addr_type) */
define|#
directive|define
name|ETH_TX_PARSE_BD_E1X_ETH_ADDR_TYPE_SHIFT
value|4
define|#
directive|define
name|ETH_TX_PARSE_BD_E1X_PSEUDO_CS_WITHOUT_LEN
value|(0x1<<6)
comment|/* BitField global_data	 */
define|#
directive|define
name|ETH_TX_PARSE_BD_E1X_PSEUDO_CS_WITHOUT_LEN_SHIFT
value|6
define|#
directive|define
name|ETH_TX_PARSE_BD_E1X_LLC_SNAP_EN
value|(0x1<<7)
comment|/* BitField global_data	 */
define|#
directive|define
name|ETH_TX_PARSE_BD_E1X_LLC_SNAP_EN_SHIFT
value|7
define|#
directive|define
name|ETH_TX_PARSE_BD_E1X_NS_FLG
value|(0x1<<8)
comment|/* BitField global_data	an optional addition to ECN that protects against accidental or malicious concealment of marked packets from the TCP sender. */
define|#
directive|define
name|ETH_TX_PARSE_BD_E1X_NS_FLG_SHIFT
value|8
define|#
directive|define
name|ETH_TX_PARSE_BD_E1X_RESERVED0
value|(0x7F<<9)
comment|/* BitField global_data	reserved bit, should be set with 0 */
define|#
directive|define
name|ETH_TX_PARSE_BD_E1X_RESERVED0_SHIFT
value|9
name|uint8_t
name|tcp_flags
decl_stmt|;
define|#
directive|define
name|ETH_TX_PARSE_BD_E1X_FIN_FLG
value|(0x1<<0)
comment|/* BitField tcp_flagsState flags	End of data flag */
define|#
directive|define
name|ETH_TX_PARSE_BD_E1X_FIN_FLG_SHIFT
value|0
define|#
directive|define
name|ETH_TX_PARSE_BD_E1X_SYN_FLG
value|(0x1<<1)
comment|/* BitField tcp_flagsState flags	Synchronize sequence numbers flag */
define|#
directive|define
name|ETH_TX_PARSE_BD_E1X_SYN_FLG_SHIFT
value|1
define|#
directive|define
name|ETH_TX_PARSE_BD_E1X_RST_FLG
value|(0x1<<2)
comment|/* BitField tcp_flagsState flags	Reset connection flag */
define|#
directive|define
name|ETH_TX_PARSE_BD_E1X_RST_FLG_SHIFT
value|2
define|#
directive|define
name|ETH_TX_PARSE_BD_E1X_PSH_FLG
value|(0x1<<3)
comment|/* BitField tcp_flagsState flags	Push flag */
define|#
directive|define
name|ETH_TX_PARSE_BD_E1X_PSH_FLG_SHIFT
value|3
define|#
directive|define
name|ETH_TX_PARSE_BD_E1X_ACK_FLG
value|(0x1<<4)
comment|/* BitField tcp_flagsState flags	Acknowledgment number valid flag */
define|#
directive|define
name|ETH_TX_PARSE_BD_E1X_ACK_FLG_SHIFT
value|4
define|#
directive|define
name|ETH_TX_PARSE_BD_E1X_URG_FLG
value|(0x1<<5)
comment|/* BitField tcp_flagsState flags	Urgent pointer valid flag */
define|#
directive|define
name|ETH_TX_PARSE_BD_E1X_URG_FLG_SHIFT
value|5
define|#
directive|define
name|ETH_TX_PARSE_BD_E1X_ECE_FLG
value|(0x1<<6)
comment|/* BitField tcp_flagsState flags	ECN-Echo */
define|#
directive|define
name|ETH_TX_PARSE_BD_E1X_ECE_FLG_SHIFT
value|6
define|#
directive|define
name|ETH_TX_PARSE_BD_E1X_CWR_FLG
value|(0x1<<7)
comment|/* BitField tcp_flagsState flags	Congestion Window Reduced */
define|#
directive|define
name|ETH_TX_PARSE_BD_E1X_CWR_FLG_SHIFT
value|7
name|uint8_t
name|ip_hlen_w
comment|/* IP header length in WORDs */
decl_stmt|;
name|uint16_t
name|total_hlen_w
comment|/* IP+TCP+ETH */
decl_stmt|;
name|uint16_t
name|tcp_pseudo_csum
comment|/* Checksum of pseudo header with  length  field=0 */
decl_stmt|;
name|uint16_t
name|lso_mss
comment|/* for LSO mode */
decl_stmt|;
name|uint16_t
name|ip_id
comment|/* for LSO mode */
decl_stmt|;
name|uint32_t
name|tcp_send_seq
comment|/* for LSO mode */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Tx parsing BD structure for ETH E2 $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|eth_tx_parse_bd_e2
block|{
name|union
name|eth_mac_addr_or_tunnel_data
name|data
comment|/* union for mac addresses and for tunneling data. considered as tunneling data only if (tunnel_exist == 1). */
decl_stmt|;
name|uint32_t
name|parsing_data
decl_stmt|;
define|#
directive|define
name|ETH_TX_PARSE_BD_E2_L4_HDR_START_OFFSET_W
value|(0x7FF<<0)
comment|/* BitField parsing_data	TCP/UDP header Offset in WORDs from start of packet */
define|#
directive|define
name|ETH_TX_PARSE_BD_E2_L4_HDR_START_OFFSET_W_SHIFT
value|0
define|#
directive|define
name|ETH_TX_PARSE_BD_E2_TCP_HDR_LENGTH_DW
value|(0xF<<11)
comment|/* BitField parsing_data	TCP header size in DOUBLE WORDS */
define|#
directive|define
name|ETH_TX_PARSE_BD_E2_TCP_HDR_LENGTH_DW_SHIFT
value|11
define|#
directive|define
name|ETH_TX_PARSE_BD_E2_IPV6_WITH_EXT_HDR
value|(0x1<<15)
comment|/* BitField parsing_data	a flag to indicate an ipv6 packet with extension headers. If set on LSO packet, pseudo CS should be placed in TCP CS field without length field */
define|#
directive|define
name|ETH_TX_PARSE_BD_E2_IPV6_WITH_EXT_HDR_SHIFT
value|15
define|#
directive|define
name|ETH_TX_PARSE_BD_E2_LSO_MSS
value|(0x3FFF<<16)
comment|/* BitField parsing_data	for LSO mode */
define|#
directive|define
name|ETH_TX_PARSE_BD_E2_LSO_MSS_SHIFT
value|16
define|#
directive|define
name|ETH_TX_PARSE_BD_E2_ETH_ADDR_TYPE
value|(0x3<<30)
comment|/* BitField parsing_data	marks ethernet address type (use enum eth_addr_type) */
define|#
directive|define
name|ETH_TX_PARSE_BD_E2_ETH_ADDR_TYPE_SHIFT
value|30
block|}
struct|;
end_struct

begin_comment
comment|/*  * Tx 2nd parsing BD structure for ETH packet $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|eth_tx_parse_2nd_bd
block|{
name|uint16_t
name|global_data
decl_stmt|;
define|#
directive|define
name|ETH_TX_PARSE_2ND_BD_IP_HDR_START_OUTER_W
value|(0xF<<0)
comment|/* BitField global_data	Outer IP header offset in WORDs (16-bit) from start of packet */
define|#
directive|define
name|ETH_TX_PARSE_2ND_BD_IP_HDR_START_OUTER_W_SHIFT
value|0
define|#
directive|define
name|ETH_TX_PARSE_2ND_BD_RESERVED0
value|(0x1<<4)
comment|/* BitField global_data	should be set with 0 */
define|#
directive|define
name|ETH_TX_PARSE_2ND_BD_RESERVED0_SHIFT
value|4
define|#
directive|define
name|ETH_TX_PARSE_2ND_BD_LLC_SNAP_EN
value|(0x1<<5)
comment|/* BitField global_data	 */
define|#
directive|define
name|ETH_TX_PARSE_2ND_BD_LLC_SNAP_EN_SHIFT
value|5
define|#
directive|define
name|ETH_TX_PARSE_2ND_BD_NS_FLG
value|(0x1<<6)
comment|/* BitField global_data	an optional addition to ECN that protects against accidental or malicious concealment of marked packets from the TCP sender. */
define|#
directive|define
name|ETH_TX_PARSE_2ND_BD_NS_FLG_SHIFT
value|6
define|#
directive|define
name|ETH_TX_PARSE_2ND_BD_TUNNEL_UDP_EXIST
value|(0x1<<7)
comment|/* BitField global_data	Set in case UDP header exists in tunnel outer hedears. */
define|#
directive|define
name|ETH_TX_PARSE_2ND_BD_TUNNEL_UDP_EXIST_SHIFT
value|7
define|#
directive|define
name|ETH_TX_PARSE_2ND_BD_IP_HDR_LEN_OUTER_W
value|(0x1F<<8)
comment|/* BitField global_data	Outer IP header length in WORDs (16-bit). Valid only for IpV4. */
define|#
directive|define
name|ETH_TX_PARSE_2ND_BD_IP_HDR_LEN_OUTER_W_SHIFT
value|8
define|#
directive|define
name|ETH_TX_PARSE_2ND_BD_RESERVED1
value|(0x7<<13)
comment|/* BitField global_data	should be set with 0 */
define|#
directive|define
name|ETH_TX_PARSE_2ND_BD_RESERVED1_SHIFT
value|13
name|uint8_t
name|bd_type
decl_stmt|;
define|#
directive|define
name|ETH_TX_PARSE_2ND_BD_TYPE
value|(0xF<<0)
comment|/* BitField bd_type	Type of bd (use enum eth_2nd_parse_bd_type) */
define|#
directive|define
name|ETH_TX_PARSE_2ND_BD_TYPE_SHIFT
value|0
define|#
directive|define
name|ETH_TX_PARSE_2ND_BD_RESERVED2
value|(0xF<<4)
comment|/* BitField bd_type	 */
define|#
directive|define
name|ETH_TX_PARSE_2ND_BD_RESERVED2_SHIFT
value|4
name|uint8_t
name|reserved3
decl_stmt|;
name|uint8_t
name|tcp_flags
decl_stmt|;
define|#
directive|define
name|ETH_TX_PARSE_2ND_BD_FIN_FLG
value|(0x1<<0)
comment|/* BitField tcp_flagsState flags	End of data flag */
define|#
directive|define
name|ETH_TX_PARSE_2ND_BD_FIN_FLG_SHIFT
value|0
define|#
directive|define
name|ETH_TX_PARSE_2ND_BD_SYN_FLG
value|(0x1<<1)
comment|/* BitField tcp_flagsState flags	Synchronize sequence numbers flag */
define|#
directive|define
name|ETH_TX_PARSE_2ND_BD_SYN_FLG_SHIFT
value|1
define|#
directive|define
name|ETH_TX_PARSE_2ND_BD_RST_FLG
value|(0x1<<2)
comment|/* BitField tcp_flagsState flags	Reset connection flag */
define|#
directive|define
name|ETH_TX_PARSE_2ND_BD_RST_FLG_SHIFT
value|2
define|#
directive|define
name|ETH_TX_PARSE_2ND_BD_PSH_FLG
value|(0x1<<3)
comment|/* BitField tcp_flagsState flags	Push flag */
define|#
directive|define
name|ETH_TX_PARSE_2ND_BD_PSH_FLG_SHIFT
value|3
define|#
directive|define
name|ETH_TX_PARSE_2ND_BD_ACK_FLG
value|(0x1<<4)
comment|/* BitField tcp_flagsState flags	Acknowledgment number valid flag */
define|#
directive|define
name|ETH_TX_PARSE_2ND_BD_ACK_FLG_SHIFT
value|4
define|#
directive|define
name|ETH_TX_PARSE_2ND_BD_URG_FLG
value|(0x1<<5)
comment|/* BitField tcp_flagsState flags	Urgent pointer valid flag */
define|#
directive|define
name|ETH_TX_PARSE_2ND_BD_URG_FLG_SHIFT
value|5
define|#
directive|define
name|ETH_TX_PARSE_2ND_BD_ECE_FLG
value|(0x1<<6)
comment|/* BitField tcp_flagsState flags	ECN-Echo */
define|#
directive|define
name|ETH_TX_PARSE_2ND_BD_ECE_FLG_SHIFT
value|6
define|#
directive|define
name|ETH_TX_PARSE_2ND_BD_CWR_FLG
value|(0x1<<7)
comment|/* BitField tcp_flagsState flags	Congestion Window Reduced */
define|#
directive|define
name|ETH_TX_PARSE_2ND_BD_CWR_FLG_SHIFT
value|7
name|uint8_t
name|reserved4
decl_stmt|;
name|uint8_t
name|tunnel_udp_hdr_start_w
comment|/* Offset (in WORDs) from start of packet to tunnel UDP header. (if exist) */
decl_stmt|;
name|uint8_t
name|fw_ip_hdr_to_payload_w
comment|/* In IpV4, the length (in WORDs) from the FW IpV4 header start to the payload start. In IpV6, the length (in WORDs) from the FW IpV6 header end to the payload start. However, if extension headers are included, their length is counted here as well. */
decl_stmt|;
name|uint16_t
name|fw_ip_csum_wo_len_flags_frag
comment|/* For the IP header which is set by the FW, the IP checksum without length, flags and fragment offset. */
decl_stmt|;
name|uint16_t
name|hw_ip_id
comment|/* The IP ID to be set by HW for LSO packets in tunnel mode. */
decl_stmt|;
name|uint32_t
name|tcp_send_seq
comment|/* The TCP sequence number for LSO packets. */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The last BD in the BD memory will hold a pointer to the next BD memory  */
end_comment

begin_struct
struct|struct
name|eth_tx_next_bd
block|{
name|uint32_t
name|addr_lo
comment|/* Single continuous buffer low pointer */
decl_stmt|;
name|uint32_t
name|addr_hi
comment|/* Single continuous buffer high pointer */
decl_stmt|;
name|uint8_t
name|reserved
index|[
literal|8
index|]
comment|/* keeps same size as other eth tx bd types */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * union for 4 Bd types  */
end_comment

begin_union
union|union
name|eth_tx_bd_types
block|{
name|struct
name|eth_tx_start_bd
name|start_bd
comment|/* the first bd in a packets */
decl_stmt|;
name|struct
name|eth_tx_bd
name|reg_bd
comment|/* the common bd */
decl_stmt|;
name|struct
name|eth_tx_parse_bd_e1x
name|parse_bd_e1x
comment|/* parsing info BD for e1/e1h */
decl_stmt|;
name|struct
name|eth_tx_parse_bd_e2
name|parse_bd_e2
comment|/* parsing info BD for e2 */
decl_stmt|;
name|struct
name|eth_tx_parse_2nd_bd
name|parse_2nd_bd
comment|/* 2nd parsing info BD */
decl_stmt|;
name|struct
name|eth_tx_next_bd
name|next_bd
comment|/* Bd that contains the address of the next page */
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/*  * array of 13 bds as appears in the eth xstorm context  */
end_comment

begin_struct
struct|struct
name|eth_tx_bds_array
block|{
name|union
name|eth_tx_bd_types
name|bds
index|[
literal|13
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * VLAN mode on TX BDs  */
end_comment

begin_enum
enum|enum
name|eth_tx_vlan_type
block|{
name|X_ETH_NO_VLAN
block|,
name|X_ETH_OUTBAND_VLAN
block|,
name|X_ETH_INBAND_VLAN
block|,
name|X_ETH_FW_ADDED_VLAN
comment|/* Driver should not use this! */
block|,
name|MAX_ETH_TX_VLAN_TYPE
block|}
enum|;
end_enum

begin_comment
comment|/*  * Ethernet VLAN filtering mode in E1x  */
end_comment

begin_enum
enum|enum
name|eth_vlan_filter_mode
block|{
name|ETH_VLAN_FILTER_ANY_VLAN
comment|/* Dont filter by vlan */
block|,
name|ETH_VLAN_FILTER_SPECIFIC_VLAN
comment|/* Only the vlan_id is allowed */
block|,
name|ETH_VLAN_FILTER_CLASSIFY
comment|/* Vlan will be added to CAM for classification */
block|,
name|MAX_ETH_VLAN_FILTER_MODE
block|}
enum|;
end_enum

begin_comment
comment|/*  * MAC filtering configuration command header $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|mac_configuration_hdr
block|{
name|uint8_t
name|length
comment|/* number of entries valid in this command (6 bits) */
decl_stmt|;
name|uint8_t
name|offset
comment|/* offset of the first entry in the list */
decl_stmt|;
name|uint16_t
name|client_id
comment|/* the client id which this ramrod is sent on. 5b is used. */
decl_stmt|;
name|uint32_t
name|echo
comment|/* echo value to be sent to driver on event ring */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * MAC address in list for ramrod $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|mac_configuration_entry
block|{
name|uint16_t
name|lsb_mac_addr
comment|/* 2 LSB of MAC address (should be given in big endien - driver should do hton to this number!!!) */
decl_stmt|;
name|uint16_t
name|middle_mac_addr
comment|/* 2 middle bytes of MAC address (should be given in big endien - driver should do hton to this number!!!) */
decl_stmt|;
name|uint16_t
name|msb_mac_addr
comment|/* 2 MSB of MAC address (should be given in big endien - driver should do hton to this number!!!) */
decl_stmt|;
name|uint16_t
name|vlan_id
comment|/* The inner vlan id (12b). Used either in vlan_in_cam for mac_valn pair or for vlan filtering */
decl_stmt|;
name|uint8_t
name|pf_id
comment|/* The pf id, for multi function mode */
decl_stmt|;
name|uint8_t
name|flags
decl_stmt|;
define|#
directive|define
name|MAC_CONFIGURATION_ENTRY_ACTION_TYPE
value|(0x1<<0)
comment|/* BitField flags	configures the action to be done in cam (used only is slow path handlers) (use enum set_mac_action_type) */
define|#
directive|define
name|MAC_CONFIGURATION_ENTRY_ACTION_TYPE_SHIFT
value|0
define|#
directive|define
name|MAC_CONFIGURATION_ENTRY_RDMA_MAC
value|(0x1<<1)
comment|/* BitField flags	If set, this MAC also belongs to RDMA client */
define|#
directive|define
name|MAC_CONFIGURATION_ENTRY_RDMA_MAC_SHIFT
value|1
define|#
directive|define
name|MAC_CONFIGURATION_ENTRY_VLAN_FILTERING_MODE
value|(0x3<<2)
comment|/* BitField flags	 (use enum eth_vlan_filter_mode) */
define|#
directive|define
name|MAC_CONFIGURATION_ENTRY_VLAN_FILTERING_MODE_SHIFT
value|2
define|#
directive|define
name|MAC_CONFIGURATION_ENTRY_OVERRIDE_VLAN_REMOVAL
value|(0x1<<4)
comment|/* BitField flags	BitField flags  0 - cant remove vlan 1 - can remove vlan. relevant only to everest1 */
define|#
directive|define
name|MAC_CONFIGURATION_ENTRY_OVERRIDE_VLAN_REMOVAL_SHIFT
value|4
define|#
directive|define
name|MAC_CONFIGURATION_ENTRY_BROADCAST
value|(0x1<<5)
comment|/* BitField flags	BitField flags   0 - not broadcast 1 - broadcast. relevant only to everest1 */
define|#
directive|define
name|MAC_CONFIGURATION_ENTRY_BROADCAST_SHIFT
value|5
define|#
directive|define
name|MAC_CONFIGURATION_ENTRY_RESERVED1
value|(0x3<<6)
comment|/* BitField flags	 */
define|#
directive|define
name|MAC_CONFIGURATION_ENTRY_RESERVED1_SHIFT
value|6
name|uint16_t
name|reserved0
decl_stmt|;
name|uint32_t
name|clients_bit_vector
comment|/* Bit vector for the clients which should receive this MAC. */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * MAC filtering configuration command  */
end_comment

begin_struct
struct|struct
name|mac_configuration_cmd
block|{
name|struct
name|mac_configuration_hdr
name|hdr
comment|/* header */
decl_stmt|;
name|struct
name|mac_configuration_entry
name|config_table
index|[
literal|64
index|]
comment|/* table of 64 MAC configuration entries: addresses and target table entries */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Set-MAC command type (in E1x)  */
end_comment

begin_enum
enum|enum
name|set_mac_action_type
block|{
name|T_ETH_MAC_COMMAND_INVALIDATE
block|,
name|T_ETH_MAC_COMMAND_SET
block|,
name|MAX_SET_MAC_ACTION_TYPE
block|}
enum|;
end_enum

begin_comment
comment|/*  * Ethernet TPA Modes  */
end_comment

begin_enum
enum|enum
name|tpa_mode
block|{
name|TPA_LRO
comment|/* LRO mode TPA */
block|,
name|TPA_GRO
comment|/* GRO mode TPA */
block|,
name|MAX_TPA_MODE
block|}
enum|;
end_enum

begin_comment
comment|/*  * tpa update ramrod data $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|tpa_update_ramrod_data
block|{
name|uint8_t
name|update_ipv4
comment|/* none, enable or disable */
decl_stmt|;
name|uint8_t
name|update_ipv6
comment|/* none, enable or disable */
decl_stmt|;
name|uint8_t
name|client_id
comment|/* client init flow control data */
decl_stmt|;
name|uint8_t
name|max_tpa_queues
comment|/* maximal TPA queues allowed for this client */
decl_stmt|;
name|uint8_t
name|max_sges_for_packet
comment|/* The maximal number of SGEs that can be used for one packet. depends on MTU and SGE size. must be 0 if SGEs are disabled */
decl_stmt|;
name|uint8_t
name|complete_on_both_clients
comment|/* If set and the client has different sp_client, completion will be sent to both rings */
decl_stmt|;
name|uint8_t
name|dont_verify_rings_pause_thr_flg
comment|/* If set, the rings pause thresholds will not be verified by firmware. */
decl_stmt|;
name|uint8_t
name|tpa_mode
comment|/* TPA mode to use (LRO or GRO) */
decl_stmt|;
name|uint16_t
name|sge_buff_size
comment|/* Size of the buffers pointed by SGEs */
decl_stmt|;
name|uint16_t
name|max_agg_size
comment|/* maximal size for the aggregated TPA packets, reprted by the host */
decl_stmt|;
name|uint32_t
name|sge_page_base_lo
comment|/* The address to fetch the next sges from (low) */
decl_stmt|;
name|uint32_t
name|sge_page_base_hi
comment|/* The address to fetch the next sges from (high) */
decl_stmt|;
name|uint16_t
name|sge_pause_thr_low
comment|/* number of remaining sges under which, we send pause message */
decl_stmt|;
name|uint16_t
name|sge_pause_thr_high
comment|/* number of remaining sges above which, we send un-pause message */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * approximate-match multicast filtering for E1H per function in Tstorm  */
end_comment

begin_struct
struct|struct
name|tstorm_eth_approximate_match_multicast_filtering
block|{
name|uint32_t
name|mcast_add_hash_bit_array
index|[
literal|8
index|]
comment|/* Bit array for multicast hash filtering.Each bit supports a hash function result if to accept this multicast dst address. */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Common configuration parameters per function in Tstorm $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|tstorm_eth_function_common_config
block|{
name|uint16_t
name|config_flags
decl_stmt|;
define|#
directive|define
name|TSTORM_ETH_FUNCTION_COMMON_CONFIG_RSS_IPV4_CAPABILITY
value|(0x1<<0)
comment|/* BitField config_flagsGeneral configuration flags	configuration of the port RSS IpV4 2-tupple capability */
define|#
directive|define
name|TSTORM_ETH_FUNCTION_COMMON_CONFIG_RSS_IPV4_CAPABILITY_SHIFT
value|0
define|#
directive|define
name|TSTORM_ETH_FUNCTION_COMMON_CONFIG_RSS_IPV4_TCP_CAPABILITY
value|(0x1<<1)
comment|/* BitField config_flagsGeneral configuration flags	configuration of the port RSS IpV4 4-tupple capability */
define|#
directive|define
name|TSTORM_ETH_FUNCTION_COMMON_CONFIG_RSS_IPV4_TCP_CAPABILITY_SHIFT
value|1
define|#
directive|define
name|TSTORM_ETH_FUNCTION_COMMON_CONFIG_RSS_IPV6_CAPABILITY
value|(0x1<<2)
comment|/* BitField config_flagsGeneral configuration flags	configuration of the port RSS IpV4 2-tupple capability */
define|#
directive|define
name|TSTORM_ETH_FUNCTION_COMMON_CONFIG_RSS_IPV6_CAPABILITY_SHIFT
value|2
define|#
directive|define
name|TSTORM_ETH_FUNCTION_COMMON_CONFIG_RSS_IPV6_TCP_CAPABILITY
value|(0x1<<3)
comment|/* BitField config_flagsGeneral configuration flags	configuration of the port RSS IpV6 4-tupple capability */
define|#
directive|define
name|TSTORM_ETH_FUNCTION_COMMON_CONFIG_RSS_IPV6_TCP_CAPABILITY_SHIFT
value|3
define|#
directive|define
name|TSTORM_ETH_FUNCTION_COMMON_CONFIG_RSS_MODE
value|(0x7<<4)
comment|/* BitField config_flagsGeneral configuration flags	RSS mode of operation (use enum eth_rss_mode) */
define|#
directive|define
name|TSTORM_ETH_FUNCTION_COMMON_CONFIG_RSS_MODE_SHIFT
value|4
define|#
directive|define
name|TSTORM_ETH_FUNCTION_COMMON_CONFIG_VLAN_FILTERING_ENABLE
value|(0x1<<7)
comment|/* BitField config_flagsGeneral configuration flags	0 - Dont filter by vlan, 1 - Filter according to the vlans specificied in mac_filter_config */
define|#
directive|define
name|TSTORM_ETH_FUNCTION_COMMON_CONFIG_VLAN_FILTERING_ENABLE_SHIFT
value|7
define|#
directive|define
name|__TSTORM_ETH_FUNCTION_COMMON_CONFIG_RESERVED0
value|(0xFF<<8)
comment|/* BitField config_flagsGeneral configuration flags	 */
define|#
directive|define
name|__TSTORM_ETH_FUNCTION_COMMON_CONFIG_RESERVED0_SHIFT
value|8
name|uint8_t
name|rss_result_mask
comment|/* The mask for the lower byte of RSS result - defines which section of the indirection table will be used. To enable all table put here 0x7F */
decl_stmt|;
name|uint8_t
name|reserved1
decl_stmt|;
name|uint16_t
name|vlan_id
index|[
literal|2
index|]
comment|/* VLANs of this function. VLAN filtering is determine according to vlan_filtering_enable. */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * MAC filtering configuration parameters per port in Tstorm $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|tstorm_eth_mac_filter_config
block|{
name|uint32_t
name|ucast_drop_all
comment|/* bit vector in which the clients which drop all unicast packets are set */
decl_stmt|;
name|uint32_t
name|ucast_accept_all
comment|/* bit vector in which clients that accept all unicast packets are set */
decl_stmt|;
name|uint32_t
name|mcast_drop_all
comment|/* bit vector in which the clients which drop all multicast packets are set */
decl_stmt|;
name|uint32_t
name|mcast_accept_all
comment|/* bit vector in which clients that accept all multicast packets are set */
decl_stmt|;
name|uint32_t
name|bcast_accept_all
comment|/* bit vector in which clients that accept all broadcast packets are set */
decl_stmt|;
name|uint32_t
name|vlan_filter
index|[
literal|2
index|]
comment|/* bit vector for VLAN filtering. Clients which enforce filtering of vlan[x] should be marked in vlan_filter[x]. In E1 only vlan_filter[1] is checked. The primary vlan is taken from the CAM target table. */
decl_stmt|;
name|uint32_t
name|unmatched_unicast
comment|/* bit vector in which clients that accept unmatched unicast packets are set */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * tx only queue init ramrod data $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|tx_queue_init_ramrod_data
block|{
name|struct
name|client_init_general_data
name|general
comment|/* client init general data */
decl_stmt|;
name|struct
name|client_init_tx_data
name|tx
comment|/* client init tx data */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Three RX producers for ETH  */
end_comment

begin_struct
struct|struct
name|ustorm_eth_rx_producers
block|{
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|bd_prod
comment|/* Producer of the RX BD ring */
decl_stmt|;
name|uint16_t
name|cqe_prod
comment|/* Producer of the RX CQE ring */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|cqe_prod
comment|/* Producer of the RX CQE ring */
decl_stmt|;
name|uint16_t
name|bd_prod
comment|/* Producer of the RX BD ring */
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|reserved
decl_stmt|;
name|uint16_t
name|sge_prod
comment|/* Producer of the RX SGE ring */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|sge_prod
comment|/* Producer of the RX SGE ring */
decl_stmt|;
name|uint16_t
name|reserved
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/*  * ABTS info $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|fcoe_abts_info
block|{
name|uint16_t
name|aborted_task_id
comment|/* Task ID to be aborted */
decl_stmt|;
name|uint16_t
name|reserved0
decl_stmt|;
name|uint32_t
name|reserved1
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Fixed size structure in order to plant it in Union structure $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|fcoe_abts_rsp_union
block|{
name|uint8_t
name|r_ctl
comment|/* Only R_CTL part of the FC header in ABTS ACC or BA_RJT messages is placed */
decl_stmt|;
name|uint8_t
name|rsrv
index|[
literal|3
index|]
decl_stmt|;
name|uint32_t
name|abts_rsp_payload
index|[
literal|7
index|]
comment|/* The payload of  the ABTS ACC (12B) or the BA_RJT (4B) */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * 4 regs size $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|fcoe_bd_ctx
block|{
name|uint32_t
name|buf_addr_hi
comment|/* Higher buffer host address */
decl_stmt|;
name|uint32_t
name|buf_addr_lo
comment|/* Lower buffer host address */
decl_stmt|;
name|uint16_t
name|buf_len
comment|/* Buffer length (in bytes) */
decl_stmt|;
name|uint16_t
name|rsrv0
decl_stmt|;
name|uint16_t
name|flags
comment|/* BD flags */
decl_stmt|;
name|uint16_t
name|rsrv1
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * FCoE cached sges context $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|fcoe_cached_sge_ctx
block|{
name|struct
name|regpair_t
name|cur_buf_addr
comment|/* Current buffer address (in initialization it is the first cached buffer) */
decl_stmt|;
name|uint16_t
name|cur_buf_rem
comment|/* Remaining data in current buffer (in bytes) */
decl_stmt|;
name|uint16_t
name|second_buf_rem
comment|/* Remaining data in second buffer (in bytes) */
decl_stmt|;
name|struct
name|regpair_t
name|second_buf_addr
comment|/* Second cached buffer address */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Cleanup info $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|fcoe_cleanup_info
block|{
name|uint16_t
name|cleaned_task_id
comment|/* Task ID to be cleaned */
decl_stmt|;
name|uint16_t
name|rolled_tx_seq_cnt
comment|/* Tx sequence count */
decl_stmt|;
name|uint32_t
name|rolled_tx_data_offset
comment|/* Tx data offset */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Fcp RSP flags $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|fcoe_fcp_rsp_flags
block|{
name|uint8_t
name|flags
decl_stmt|;
define|#
directive|define
name|FCOE_FCP_RSP_FLAGS_FCP_RSP_LEN_VALID
value|(0x1<<0)
comment|/* BitField flags	 */
define|#
directive|define
name|FCOE_FCP_RSP_FLAGS_FCP_RSP_LEN_VALID_SHIFT
value|0
define|#
directive|define
name|FCOE_FCP_RSP_FLAGS_FCP_SNS_LEN_VALID
value|(0x1<<1)
comment|/* BitField flags	 */
define|#
directive|define
name|FCOE_FCP_RSP_FLAGS_FCP_SNS_LEN_VALID_SHIFT
value|1
define|#
directive|define
name|FCOE_FCP_RSP_FLAGS_FCP_RESID_OVER
value|(0x1<<2)
comment|/* BitField flags	 */
define|#
directive|define
name|FCOE_FCP_RSP_FLAGS_FCP_RESID_OVER_SHIFT
value|2
define|#
directive|define
name|FCOE_FCP_RSP_FLAGS_FCP_RESID_UNDER
value|(0x1<<3)
comment|/* BitField flags	 */
define|#
directive|define
name|FCOE_FCP_RSP_FLAGS_FCP_RESID_UNDER_SHIFT
value|3
define|#
directive|define
name|FCOE_FCP_RSP_FLAGS_FCP_CONF_REQ
value|(0x1<<4)
comment|/* BitField flags	 */
define|#
directive|define
name|FCOE_FCP_RSP_FLAGS_FCP_CONF_REQ_SHIFT
value|4
define|#
directive|define
name|FCOE_FCP_RSP_FLAGS_FCP_BIDI_FLAGS
value|(0x7<<5)
comment|/* BitField flags	 */
define|#
directive|define
name|FCOE_FCP_RSP_FLAGS_FCP_BIDI_FLAGS_SHIFT
value|5
block|}
struct|;
end_struct

begin_comment
comment|/*  * Fcp RSP payload $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|fcoe_fcp_rsp_payload
block|{
name|struct
name|regpair_t
name|reserved0
decl_stmt|;
name|uint32_t
name|fcp_resid
decl_stmt|;
name|uint8_t
name|scsi_status_code
decl_stmt|;
name|struct
name|fcoe_fcp_rsp_flags
name|fcp_flags
decl_stmt|;
name|uint16_t
name|retry_delay_timer
decl_stmt|;
name|uint32_t
name|fcp_rsp_len
decl_stmt|;
name|uint32_t
name|fcp_sns_len
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Fixed size structure in order to plant it in Union structure $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|fcoe_fcp_rsp_union
block|{
name|struct
name|fcoe_fcp_rsp_payload
name|payload
decl_stmt|;
name|struct
name|regpair_t
name|reserved0
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * FC header $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|fcoe_fc_hdr
block|{
name|uint8_t
name|s_id
index|[
literal|3
index|]
decl_stmt|;
name|uint8_t
name|cs_ctl
decl_stmt|;
name|uint8_t
name|d_id
index|[
literal|3
index|]
decl_stmt|;
name|uint8_t
name|r_ctl
decl_stmt|;
name|uint16_t
name|seq_cnt
decl_stmt|;
name|uint8_t
name|df_ctl
decl_stmt|;
name|uint8_t
name|seq_id
decl_stmt|;
name|uint8_t
name|f_ctl
index|[
literal|3
index|]
decl_stmt|;
name|uint8_t
name|type
decl_stmt|;
name|uint32_t
name|parameters
decl_stmt|;
name|uint16_t
name|rx_id
decl_stmt|;
name|uint16_t
name|ox_id
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * FC header union $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|fcoe_mp_rsp_union
block|{
name|struct
name|fcoe_fc_hdr
name|fc_hdr
comment|/* FC header copied into task context (middle path flows) */
decl_stmt|;
name|uint32_t
name|mp_payload_len
comment|/* Length of the MP payload that was placed */
decl_stmt|;
name|uint32_t
name|rsrv
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Completion information $$KEEP_ENDIANNESS$$  */
end_comment

begin_union
union|union
name|fcoe_comp_flow_info
block|{
name|struct
name|fcoe_fcp_rsp_union
name|fcp_rsp
comment|/* FCP_RSP payload */
decl_stmt|;
name|struct
name|fcoe_abts_rsp_union
name|abts_rsp
comment|/* ABTS ACC R_CTL part of the FC header ABTS ACC or BA_RJT payload frame */
decl_stmt|;
name|struct
name|fcoe_mp_rsp_union
name|mp_rsp
comment|/* FC header copied into task context (middle path flows) */
decl_stmt|;
name|uint32_t
name|opaque
index|[
literal|8
index|]
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/*  * External ABTS info $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|fcoe_ext_abts_info
block|{
name|uint32_t
name|rsrv0
index|[
literal|6
index|]
decl_stmt|;
name|struct
name|fcoe_abts_info
name|ctx
comment|/* ABTS information. Initialized by Xstorm */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * External cleanup info $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|fcoe_ext_cleanup_info
block|{
name|uint32_t
name|rsrv0
index|[
literal|6
index|]
decl_stmt|;
name|struct
name|fcoe_cleanup_info
name|ctx
comment|/* Cleanup information */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Fcoe FW Tx sequence context $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|fcoe_fw_tx_seq_ctx
block|{
name|uint32_t
name|data_offset
comment|/* The amount of data transmitted so far (equal to FCP_DATA PARAMETER field) */
decl_stmt|;
name|uint16_t
name|seq_cnt
comment|/* The last SEQ_CNT transmitted */
decl_stmt|;
name|uint16_t
name|rsrv0
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Fcoe external FW Tx sequence context $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|fcoe_ext_fw_tx_seq_ctx
block|{
name|uint32_t
name|rsrv0
index|[
literal|6
index|]
decl_stmt|;
name|struct
name|fcoe_fw_tx_seq_ctx
name|ctx
comment|/* TX sequence context */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * FCoE multiple sges context $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|fcoe_mul_sges_ctx
block|{
name|struct
name|regpair_t
name|cur_sge_addr
comment|/* Current BD address */
decl_stmt|;
name|uint16_t
name|cur_sge_off
comment|/* Offset in current BD (in bytes) */
decl_stmt|;
name|uint8_t
name|cur_sge_idx
comment|/* Current BD index in BD list */
decl_stmt|;
name|uint8_t
name|sgl_size
comment|/* Total number of BDs */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * FCoE external multiple sges context $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|fcoe_ext_mul_sges_ctx
block|{
name|struct
name|fcoe_mul_sges_ctx
name|mul_sgl
comment|/* SGL context */
decl_stmt|;
name|struct
name|regpair_t
name|rsrv0
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * FCP CMD payload $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|fcoe_fcp_cmd_payload
block|{
name|uint32_t
name|opaque
index|[
literal|8
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Fcp xfr rdy payload $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|fcoe_fcp_xfr_rdy_payload
block|{
name|uint32_t
name|burst_len
decl_stmt|;
name|uint32_t
name|data_ro
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * FC frame $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|fcoe_fc_frame
block|{
name|struct
name|fcoe_fc_hdr
name|fc_hdr
decl_stmt|;
name|uint32_t
name|reserved0
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * FCoE KCQ CQE parameters $$KEEP_ENDIANNESS$$  */
end_comment

begin_union
union|union
name|fcoe_kcqe_params
block|{
name|uint32_t
name|reserved0
index|[
literal|4
index|]
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/*  * FCoE KCQ CQE $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|fcoe_kcqe
block|{
name|uint32_t
name|fcoe_conn_id
comment|/* Drivers connection ID (only 16 bits are used) */
decl_stmt|;
name|uint32_t
name|completion_status
comment|/* 0=command completed successfully, 1=command failed */
decl_stmt|;
name|uint32_t
name|fcoe_conn_context_id
comment|/* Context ID of the FCoE connection */
decl_stmt|;
name|union
name|fcoe_kcqe_params
name|params
comment|/* command-specific parameters */
decl_stmt|;
name|uint16_t
name|qe_self_seq
comment|/* Self identifying sequence number */
decl_stmt|;
name|uint8_t
name|op_code
comment|/* FCoE KCQ opcode */
decl_stmt|;
name|uint8_t
name|flags
decl_stmt|;
define|#
directive|define
name|FCOE_KCQE_RESERVED0
value|(0x7<<0)
comment|/* BitField flags	 */
define|#
directive|define
name|FCOE_KCQE_RESERVED0_SHIFT
value|0
define|#
directive|define
name|FCOE_KCQE_RAMROD_COMPLETION
value|(0x1<<3)
comment|/* BitField flags	Everest only - indicates whether this KCQE is a ramrod completion */
define|#
directive|define
name|FCOE_KCQE_RAMROD_COMPLETION_SHIFT
value|3
define|#
directive|define
name|FCOE_KCQE_LAYER_CODE
value|(0x7<<4)
comment|/* BitField flags	protocol layer (L2,L3,L4,L5,iSCSI,FCoE) */
define|#
directive|define
name|FCOE_KCQE_LAYER_CODE_SHIFT
value|4
define|#
directive|define
name|FCOE_KCQE_LINKED_WITH_NEXT
value|(0x1<<7)
comment|/* BitField flags	Indicates whether this KCQE is linked with the next KCQE */
define|#
directive|define
name|FCOE_KCQE_LINKED_WITH_NEXT_SHIFT
value|7
block|}
struct|;
end_struct

begin_comment
comment|/*  * FCoE KWQE header $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|fcoe_kwqe_header
block|{
name|uint8_t
name|op_code
comment|/* FCoE KWQE opcode */
decl_stmt|;
name|uint8_t
name|flags
decl_stmt|;
define|#
directive|define
name|FCOE_KWQE_HEADER_RESERVED0
value|(0xF<<0)
comment|/* BitField flags	 */
define|#
directive|define
name|FCOE_KWQE_HEADER_RESERVED0_SHIFT
value|0
define|#
directive|define
name|FCOE_KWQE_HEADER_LAYER_CODE
value|(0x7<<4)
comment|/* BitField flags	protocol layer (L2,L3,L4,L5) */
define|#
directive|define
name|FCOE_KWQE_HEADER_LAYER_CODE_SHIFT
value|4
define|#
directive|define
name|FCOE_KWQE_HEADER_RESERVED1
value|(0x1<<7)
comment|/* BitField flags	 */
define|#
directive|define
name|FCOE_KWQE_HEADER_RESERVED1_SHIFT
value|7
block|}
struct|;
end_struct

begin_comment
comment|/*  * FCoE firmware init request 1 $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|fcoe_kwqe_init1
block|{
name|uint16_t
name|num_tasks
comment|/* Number of tasks in global task list */
decl_stmt|;
name|struct
name|fcoe_kwqe_header
name|hdr
comment|/* KWQ WQE header */
decl_stmt|;
name|uint32_t
name|task_list_pbl_addr_lo
comment|/* Lower 32-bit of Task List page table */
decl_stmt|;
name|uint32_t
name|task_list_pbl_addr_hi
comment|/* Higher 32-bit of Task List page table */
decl_stmt|;
name|uint32_t
name|dummy_buffer_addr_lo
comment|/* Lower 32-bit of dummy buffer */
decl_stmt|;
name|uint32_t
name|dummy_buffer_addr_hi
comment|/* Higher 32-bit of dummy buffer */
decl_stmt|;
name|uint16_t
name|sq_num_wqes
comment|/* Number of entries in the Send Queue */
decl_stmt|;
name|uint16_t
name|rq_num_wqes
comment|/* Number of entries in the Receive Queue */
decl_stmt|;
name|uint16_t
name|rq_buffer_log_size
comment|/* Log of the size of a single buffer (entry) in the RQ */
decl_stmt|;
name|uint16_t
name|cq_num_wqes
comment|/* Number of entries in the Completion Queue */
decl_stmt|;
name|uint16_t
name|mtu
comment|/* Max transmission unit */
decl_stmt|;
name|uint8_t
name|num_sessions_log
comment|/* Log of the number of sessions */
decl_stmt|;
name|uint8_t
name|flags
decl_stmt|;
define|#
directive|define
name|FCOE_KWQE_INIT1_LOG_PAGE_SIZE
value|(0xF<<0)
comment|/* BitField flags	log of page size value */
define|#
directive|define
name|FCOE_KWQE_INIT1_LOG_PAGE_SIZE_SHIFT
value|0
define|#
directive|define
name|FCOE_KWQE_INIT1_LOG_CACHED_PBES_PER_FUNC
value|(0x7<<4)
comment|/* BitField flags	 */
define|#
directive|define
name|FCOE_KWQE_INIT1_LOG_CACHED_PBES_PER_FUNC_SHIFT
value|4
define|#
directive|define
name|FCOE_KWQE_INIT1_CLASSIFY_FAILED_ALLOWED
value|(0x1<<7)
comment|/* BitField flags	Special MF mode where classification failure indication from HW is allowed */
define|#
directive|define
name|FCOE_KWQE_INIT1_CLASSIFY_FAILED_ALLOWED_SHIFT
value|7
block|}
struct|;
end_struct

begin_comment
comment|/*  * FCoE firmware init request 2 $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|fcoe_kwqe_init2
block|{
name|uint8_t
name|hsi_major_version
comment|/* Implies on a change broken previous HSI */
decl_stmt|;
name|uint8_t
name|hsi_minor_version
comment|/* Implies on a change which does not broken previous HSI */
decl_stmt|;
name|struct
name|fcoe_kwqe_header
name|hdr
comment|/* KWQ WQE header */
decl_stmt|;
name|uint32_t
name|hash_tbl_pbl_addr_lo
comment|/* Lower 32-bit of Hash table PBL */
decl_stmt|;
name|uint32_t
name|hash_tbl_pbl_addr_hi
comment|/* Higher 32-bit of Hash table PBL */
decl_stmt|;
name|uint32_t
name|t2_hash_tbl_addr_lo
comment|/* Lower 32-bit of T2 Hash table */
decl_stmt|;
name|uint32_t
name|t2_hash_tbl_addr_hi
comment|/* Higher 32-bit of T2 Hash table */
decl_stmt|;
name|uint32_t
name|t2_ptr_hash_tbl_addr_lo
comment|/* Lower 32-bit of T2 ptr Hash table */
decl_stmt|;
name|uint32_t
name|t2_ptr_hash_tbl_addr_hi
comment|/* Higher 32-bit of T2 ptr Hash table */
decl_stmt|;
name|uint32_t
name|free_list_count
comment|/* T2 free list count */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * FCoE firmware init request 3 $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|fcoe_kwqe_init3
block|{
name|uint16_t
name|reserved0
decl_stmt|;
name|struct
name|fcoe_kwqe_header
name|hdr
comment|/* KWQ WQE header */
decl_stmt|;
name|uint32_t
name|error_bit_map_lo
comment|/* 32 lower bits of error bitmap: 1=error, 0=warning */
decl_stmt|;
name|uint32_t
name|error_bit_map_hi
comment|/* 32 upper bits of error bitmap: 1=error, 0=warning */
decl_stmt|;
name|uint8_t
name|perf_config
comment|/* 0= no performance acceleration, 1=cached connection, 2=cached tasks, 3=both */
decl_stmt|;
name|uint8_t
name|reserved21
index|[
literal|3
index|]
decl_stmt|;
name|uint32_t
name|reserved2
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * FCoE connection offload request 1 $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|fcoe_kwqe_conn_offload1
block|{
name|uint16_t
name|fcoe_conn_id
comment|/* Drivers connection ID. Should be sent in KCQEs to speed-up drivers access to connection data. */
decl_stmt|;
name|struct
name|fcoe_kwqe_header
name|hdr
comment|/* KWQ WQE header */
decl_stmt|;
name|uint32_t
name|sq_addr_lo
comment|/* Lower 32-bit of SQ */
decl_stmt|;
name|uint32_t
name|sq_addr_hi
comment|/* Higher 32-bit of SQ */
decl_stmt|;
name|uint32_t
name|rq_pbl_addr_lo
comment|/* Lower 32-bit of RQ page table */
decl_stmt|;
name|uint32_t
name|rq_pbl_addr_hi
comment|/* Higher 32-bit of RQ page table */
decl_stmt|;
name|uint32_t
name|rq_first_pbe_addr_lo
comment|/* Lower 32-bit of first RQ pbe */
decl_stmt|;
name|uint32_t
name|rq_first_pbe_addr_hi
comment|/* Higher 32-bit of first RQ pbe */
decl_stmt|;
name|uint16_t
name|rq_prod
comment|/* Initial RQ producer */
decl_stmt|;
name|uint16_t
name|reserved0
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * FCoE connection offload request 2 $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|fcoe_kwqe_conn_offload2
block|{
name|uint16_t
name|tx_max_fc_pay_len
comment|/* The maximum acceptable FC payload size (Buffer-to-buffer Receive Data_Field size) supported by target, received during both FLOGI and PLOGI, minimum value should be taken */
decl_stmt|;
name|struct
name|fcoe_kwqe_header
name|hdr
comment|/* KWQ WQE header */
decl_stmt|;
name|uint32_t
name|cq_addr_lo
comment|/* Lower 32-bit of CQ */
decl_stmt|;
name|uint32_t
name|cq_addr_hi
comment|/* Higher 32-bit of CQ */
decl_stmt|;
name|uint32_t
name|xferq_addr_lo
comment|/* Lower 32-bit of XFERQ */
decl_stmt|;
name|uint32_t
name|xferq_addr_hi
comment|/* Higher 32-bit of XFERQ */
decl_stmt|;
name|uint32_t
name|conn_db_addr_lo
comment|/* Lower 32-bit of Conn DB (RQ prod and CQ arm bit) */
decl_stmt|;
name|uint32_t
name|conn_db_addr_hi
comment|/* Higher 32-bit of Conn DB (RQ prod and CQ arm bit) */
decl_stmt|;
name|uint32_t
name|reserved1
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * FCoE connection offload request 3 $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|fcoe_kwqe_conn_offload3
block|{
name|uint16_t
name|vlan_tag
decl_stmt|;
define|#
directive|define
name|FCOE_KWQE_CONN_OFFLOAD3_VLAN_ID
value|(0xFFF<<0)
comment|/* BitField vlan_tag	Vlan id */
define|#
directive|define
name|FCOE_KWQE_CONN_OFFLOAD3_VLAN_ID_SHIFT
value|0
define|#
directive|define
name|FCOE_KWQE_CONN_OFFLOAD3_CFI
value|(0x1<<12)
comment|/* BitField vlan_tag	Canonical format indicator */
define|#
directive|define
name|FCOE_KWQE_CONN_OFFLOAD3_CFI_SHIFT
value|12
define|#
directive|define
name|FCOE_KWQE_CONN_OFFLOAD3_PRIORITY
value|(0x7<<13)
comment|/* BitField vlan_tag	Vlan priority */
define|#
directive|define
name|FCOE_KWQE_CONN_OFFLOAD3_PRIORITY_SHIFT
value|13
name|struct
name|fcoe_kwqe_header
name|hdr
comment|/* KWQ WQE header */
decl_stmt|;
name|uint8_t
name|s_id
index|[
literal|3
index|]
comment|/* Source ID, received during FLOGI */
decl_stmt|;
name|uint8_t
name|tx_max_conc_seqs_c3
comment|/* Maximum concurrent Sequences for Class 3 supported by target, received during PLOGI */
decl_stmt|;
name|uint8_t
name|d_id
index|[
literal|3
index|]
comment|/* Destination ID, received after inquiry of the fabric network */
decl_stmt|;
name|uint8_t
name|flags
decl_stmt|;
define|#
directive|define
name|FCOE_KWQE_CONN_OFFLOAD3_B_MUL_N_PORT_IDS
value|(0x1<<0)
comment|/* BitField flags	Supporting multiple N_Port IDs indication, received during FLOGI */
define|#
directive|define
name|FCOE_KWQE_CONN_OFFLOAD3_B_MUL_N_PORT_IDS_SHIFT
value|0
define|#
directive|define
name|FCOE_KWQE_CONN_OFFLOAD3_B_E_D_TOV_RES
value|(0x1<<1)
comment|/* BitField flags	E_D_TOV resolution (0 - msec, 1 - nsec), negotiated in PLOGI */
define|#
directive|define
name|FCOE_KWQE_CONN_OFFLOAD3_B_E_D_TOV_RES_SHIFT
value|1
define|#
directive|define
name|FCOE_KWQE_CONN_OFFLOAD3_B_CONT_INCR_SEQ_CNT
value|(0x1<<2)
comment|/* BitField flags	Continuously increasing SEQ_CNT indication, received during PLOGI */
define|#
directive|define
name|FCOE_KWQE_CONN_OFFLOAD3_B_CONT_INCR_SEQ_CNT_SHIFT
value|2
define|#
directive|define
name|FCOE_KWQE_CONN_OFFLOAD3_B_CONF_REQ
value|(0x1<<3)
comment|/* BitField flags	Confirmation request supported */
define|#
directive|define
name|FCOE_KWQE_CONN_OFFLOAD3_B_CONF_REQ_SHIFT
value|3
define|#
directive|define
name|FCOE_KWQE_CONN_OFFLOAD3_B_REC_VALID
value|(0x1<<4)
comment|/* BitField flags	REC allowed */
define|#
directive|define
name|FCOE_KWQE_CONN_OFFLOAD3_B_REC_VALID_SHIFT
value|4
define|#
directive|define
name|FCOE_KWQE_CONN_OFFLOAD3_B_C2_VALID
value|(0x1<<5)
comment|/* BitField flags	Class 2 valid, received during PLOGI */
define|#
directive|define
name|FCOE_KWQE_CONN_OFFLOAD3_B_C2_VALID_SHIFT
value|5
define|#
directive|define
name|FCOE_KWQE_CONN_OFFLOAD3_B_ACK_0
value|(0x1<<6)
comment|/* BitField flags	ACK_0 capability supporting by target, received furing PLOGI */
define|#
directive|define
name|FCOE_KWQE_CONN_OFFLOAD3_B_ACK_0_SHIFT
value|6
define|#
directive|define
name|FCOE_KWQE_CONN_OFFLOAD3_B_VLAN_FLAG
value|(0x1<<7)
comment|/* BitField flags	Is inner vlan exist */
define|#
directive|define
name|FCOE_KWQE_CONN_OFFLOAD3_B_VLAN_FLAG_SHIFT
value|7
name|uint32_t
name|reserved
decl_stmt|;
name|uint32_t
name|confq_first_pbe_addr_lo
comment|/* The first page used when handling CONFQ - low address */
decl_stmt|;
name|uint32_t
name|confq_first_pbe_addr_hi
comment|/* The first page used when handling CONFQ - high address */
decl_stmt|;
name|uint16_t
name|tx_total_conc_seqs
comment|/* Total concurrent Sequences for all Classes supported by target, received during PLOGI */
decl_stmt|;
name|uint16_t
name|rx_max_fc_pay_len
comment|/* The maximum acceptable FC payload size (Buffer-to-buffer Receive Data_Field size) supported by us, sent during FLOGI/PLOGI */
decl_stmt|;
name|uint16_t
name|rx_total_conc_seqs
comment|/* Total concurrent Sequences for all Classes supported by us, sent during PLOGI */
decl_stmt|;
name|uint8_t
name|rx_max_conc_seqs_c3
comment|/* Maximum Concurrent Sequences for Class 3 supported by us, sent during PLOGI */
decl_stmt|;
name|uint8_t
name|rx_open_seqs_exch_c3
comment|/* Maximum Open Sequences per Exchange for Class 3 supported by us, sent during PLOGI */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * FCoE connection offload request 4 $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|fcoe_kwqe_conn_offload4
block|{
name|uint8_t
name|e_d_tov_timer_val
comment|/* E_D_TOV timer value in milliseconds/20, negotiated in PLOGI */
decl_stmt|;
name|uint8_t
name|reserved2
decl_stmt|;
name|struct
name|fcoe_kwqe_header
name|hdr
comment|/* KWQ WQE header */
decl_stmt|;
name|uint8_t
name|src_mac_addr_lo
index|[
literal|2
index|]
comment|/* Lower 16-bit of source MAC address  */
decl_stmt|;
name|uint8_t
name|src_mac_addr_mid
index|[
literal|2
index|]
comment|/* Mid 16-bit of source MAC address  */
decl_stmt|;
name|uint8_t
name|src_mac_addr_hi
index|[
literal|2
index|]
comment|/* Higher 16-bit of source MAC address */
decl_stmt|;
name|uint8_t
name|dst_mac_addr_hi
index|[
literal|2
index|]
comment|/* Higher 16-bit of destination MAC address */
decl_stmt|;
name|uint8_t
name|dst_mac_addr_lo
index|[
literal|2
index|]
comment|/* Lower 16-bit destination MAC address */
decl_stmt|;
name|uint8_t
name|dst_mac_addr_mid
index|[
literal|2
index|]
comment|/* Mid 16-bit destination MAC address */
decl_stmt|;
name|uint32_t
name|lcq_addr_lo
comment|/* Lower 32-bit of LCQ */
decl_stmt|;
name|uint32_t
name|lcq_addr_hi
comment|/* Higher 32-bit of LCQ */
decl_stmt|;
name|uint32_t
name|confq_pbl_base_addr_lo
comment|/* CONFQ PBL low address */
decl_stmt|;
name|uint32_t
name|confq_pbl_base_addr_hi
comment|/* CONFQ PBL high address */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * FCoE connection enable request $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|fcoe_kwqe_conn_enable_disable
block|{
name|uint16_t
name|reserved0
decl_stmt|;
name|struct
name|fcoe_kwqe_header
name|hdr
comment|/* KWQ WQE header */
decl_stmt|;
name|uint8_t
name|src_mac_addr_lo
index|[
literal|2
index|]
comment|/* Lower 16-bit of source MAC address (HBAs MAC address) */
decl_stmt|;
name|uint8_t
name|src_mac_addr_mid
index|[
literal|2
index|]
comment|/* Mid 16-bit of source MAC address (HBAs MAC address) */
decl_stmt|;
name|uint8_t
name|src_mac_addr_hi
index|[
literal|2
index|]
comment|/* Higher 16-bit of source MAC address (HBAs MAC address) */
decl_stmt|;
name|uint16_t
name|vlan_tag
decl_stmt|;
define|#
directive|define
name|FCOE_KWQE_CONN_ENABLE_DISABLE_VLAN_ID
value|(0xFFF<<0)
comment|/* BitField vlan_tagVlan tag	Vlan id */
define|#
directive|define
name|FCOE_KWQE_CONN_ENABLE_DISABLE_VLAN_ID_SHIFT
value|0
define|#
directive|define
name|FCOE_KWQE_CONN_ENABLE_DISABLE_CFI
value|(0x1<<12)
comment|/* BitField vlan_tagVlan tag	Canonical format indicator */
define|#
directive|define
name|FCOE_KWQE_CONN_ENABLE_DISABLE_CFI_SHIFT
value|12
define|#
directive|define
name|FCOE_KWQE_CONN_ENABLE_DISABLE_PRIORITY
value|(0x7<<13)
comment|/* BitField vlan_tagVlan tag	Vlan priority */
define|#
directive|define
name|FCOE_KWQE_CONN_ENABLE_DISABLE_PRIORITY_SHIFT
value|13
name|uint8_t
name|dst_mac_addr_lo
index|[
literal|2
index|]
comment|/* Lower 16-bit of destination MAC address (FCFs MAC address) */
decl_stmt|;
name|uint8_t
name|dst_mac_addr_mid
index|[
literal|2
index|]
comment|/* Mid 16-bit of destination MAC address (FCFs MAC address) */
decl_stmt|;
name|uint8_t
name|dst_mac_addr_hi
index|[
literal|2
index|]
comment|/* Higher 16-bit of destination MAC address (FCFs MAC address) */
decl_stmt|;
name|uint16_t
name|reserved1
decl_stmt|;
name|uint8_t
name|s_id
index|[
literal|3
index|]
comment|/* Source ID, received during FLOGI */
decl_stmt|;
name|uint8_t
name|vlan_flag
comment|/* Vlan flag */
decl_stmt|;
name|uint8_t
name|d_id
index|[
literal|3
index|]
comment|/* Destination ID, received after inquiry of the fabric network */
decl_stmt|;
name|uint8_t
name|reserved3
decl_stmt|;
name|uint32_t
name|context_id
comment|/* Context ID (cid) of the connection */
decl_stmt|;
name|uint32_t
name|conn_id
comment|/* FCoE Connection ID */
decl_stmt|;
name|uint32_t
name|reserved4
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * FCoE connection destroy request $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|fcoe_kwqe_conn_destroy
block|{
name|uint16_t
name|reserved0
decl_stmt|;
name|struct
name|fcoe_kwqe_header
name|hdr
comment|/* KWQ WQE header */
decl_stmt|;
name|uint32_t
name|context_id
comment|/* Context ID (cid) of the connection */
decl_stmt|;
name|uint32_t
name|conn_id
comment|/* FCoE Connection ID */
decl_stmt|;
name|uint32_t
name|reserved1
index|[
literal|5
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * FCoe destroy request $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|fcoe_kwqe_destroy
block|{
name|uint16_t
name|reserved0
decl_stmt|;
name|struct
name|fcoe_kwqe_header
name|hdr
comment|/* KWQ WQE header */
decl_stmt|;
name|uint32_t
name|reserved1
index|[
literal|7
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * FCoe statistics request $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|fcoe_kwqe_stat
block|{
name|uint16_t
name|reserved0
decl_stmt|;
name|struct
name|fcoe_kwqe_header
name|hdr
comment|/* KWQ WQE header */
decl_stmt|;
name|uint32_t
name|stat_params_addr_lo
comment|/* Statistics host address */
decl_stmt|;
name|uint32_t
name|stat_params_addr_hi
comment|/* Statistics host address */
decl_stmt|;
name|uint32_t
name|reserved1
index|[
literal|5
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * FCoE KWQ WQE $$KEEP_ENDIANNESS$$  */
end_comment

begin_union
union|union
name|fcoe_kwqe
block|{
name|struct
name|fcoe_kwqe_init1
name|init1
decl_stmt|;
name|struct
name|fcoe_kwqe_init2
name|init2
decl_stmt|;
name|struct
name|fcoe_kwqe_init3
name|init3
decl_stmt|;
name|struct
name|fcoe_kwqe_conn_offload1
name|conn_offload1
decl_stmt|;
name|struct
name|fcoe_kwqe_conn_offload2
name|conn_offload2
decl_stmt|;
name|struct
name|fcoe_kwqe_conn_offload3
name|conn_offload3
decl_stmt|;
name|struct
name|fcoe_kwqe_conn_offload4
name|conn_offload4
decl_stmt|;
name|struct
name|fcoe_kwqe_conn_enable_disable
name|conn_enable_disable
decl_stmt|;
name|struct
name|fcoe_kwqe_conn_destroy
name|conn_destroy
decl_stmt|;
name|struct
name|fcoe_kwqe_destroy
name|destroy
decl_stmt|;
name|struct
name|fcoe_kwqe_stat
name|statistics
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/*  * TX SGL context $$KEEP_ENDIANNESS$$  */
end_comment

begin_union
union|union
name|fcoe_sgl_union_ctx
block|{
name|struct
name|fcoe_cached_sge_ctx
name|cached_sge
comment|/* Cached SGEs context */
decl_stmt|;
name|struct
name|fcoe_ext_mul_sges_ctx
name|sgl
comment|/* SGL context */
decl_stmt|;
name|uint32_t
name|opaque
index|[
literal|5
index|]
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/*  * Data-In/ELS/BLS information $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|fcoe_read_flow_info
block|{
name|union
name|fcoe_sgl_union_ctx
name|sgl_ctx
comment|/* The SGL that would be used for data placement (20 bytes) */
decl_stmt|;
name|uint32_t
name|rsrv0
index|[
literal|3
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Fcoe stat context $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|fcoe_s_stat_ctx
block|{
name|uint8_t
name|flags
decl_stmt|;
define|#
directive|define
name|FCOE_S_STAT_CTX_ACTIVE
value|(0x1<<0)
comment|/* BitField flags	Active Sequence indication (0 - not avtive; 1 - active) */
define|#
directive|define
name|FCOE_S_STAT_CTX_ACTIVE_SHIFT
value|0
define|#
directive|define
name|FCOE_S_STAT_CTX_ACK_ABORT_SEQ_COND
value|(0x1<<1)
comment|/* BitField flags	Abort Sequence requested indication */
define|#
directive|define
name|FCOE_S_STAT_CTX_ACK_ABORT_SEQ_COND_SHIFT
value|1
define|#
directive|define
name|FCOE_S_STAT_CTX_ABTS_PERFORMED
value|(0x1<<2)
comment|/* BitField flags	ABTS (on Sequence) protocol complete indication (0 - not completed; 1 -completed by Recipient) */
define|#
directive|define
name|FCOE_S_STAT_CTX_ABTS_PERFORMED_SHIFT
value|2
define|#
directive|define
name|FCOE_S_STAT_CTX_SEQ_TIMEOUT
value|(0x1<<3)
comment|/* BitField flags	E_D_TOV timeout indication */
define|#
directive|define
name|FCOE_S_STAT_CTX_SEQ_TIMEOUT_SHIFT
value|3
define|#
directive|define
name|FCOE_S_STAT_CTX_P_RJT
value|(0x1<<4)
comment|/* BitField flags	P_RJT transmitted indication */
define|#
directive|define
name|FCOE_S_STAT_CTX_P_RJT_SHIFT
value|4
define|#
directive|define
name|FCOE_S_STAT_CTX_ACK_EOFT
value|(0x1<<5)
comment|/* BitField flags	ACK (EOFt) transmitted indication (0 - not tranmitted; 1 - transmitted) */
define|#
directive|define
name|FCOE_S_STAT_CTX_ACK_EOFT_SHIFT
value|5
define|#
directive|define
name|FCOE_S_STAT_CTX_RSRV1
value|(0x3<<6)
comment|/* BitField flags	 */
define|#
directive|define
name|FCOE_S_STAT_CTX_RSRV1_SHIFT
value|6
block|}
struct|;
end_struct

begin_comment
comment|/*  * Fcoe rx seq context $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|fcoe_rx_seq_ctx
block|{
name|uint8_t
name|seq_id
comment|/* The Sequence ID */
decl_stmt|;
name|struct
name|fcoe_s_stat_ctx
name|s_stat
comment|/* The Sequence status */
decl_stmt|;
name|uint16_t
name|seq_cnt
comment|/* The lowest SEQ_CNT received for the Sequence */
decl_stmt|;
name|uint32_t
name|low_exp_ro
comment|/* Report on the offset at the beginning of the Sequence */
decl_stmt|;
name|uint32_t
name|high_exp_ro
comment|/* The highest expected relative offset. The next buffer offset to be received in case of XFER_RDY or in FCP_DATA */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * FCoE RX statistics parameters section#0 $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|fcoe_rx_stat_params_section0
block|{
name|uint32_t
name|fcoe_rx_pkt_cnt
comment|/* Number of FCoE packets that were legally received */
decl_stmt|;
name|uint32_t
name|fcoe_rx_byte_cnt
comment|/* Number of FCoE bytes that were legally received */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * FCoE RX statistics parameters section#1 $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|fcoe_rx_stat_params_section1
block|{
name|uint32_t
name|fcoe_ver_cnt
comment|/* Number of packets with wrong FCoE version */
decl_stmt|;
name|uint32_t
name|fcoe_rx_drop_pkt_cnt
comment|/* Number of FCoE packets that were dropped */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * FCoE RX statistics parameters section#2 $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|fcoe_rx_stat_params_section2
block|{
name|uint32_t
name|fc_crc_cnt
comment|/* Number of packets with FC CRC error */
decl_stmt|;
name|uint32_t
name|eofa_del_cnt
comment|/* Number of packets with EOFa delimiter */
decl_stmt|;
name|uint32_t
name|miss_frame_cnt
comment|/* Number of missing packets */
decl_stmt|;
name|uint32_t
name|seq_timeout_cnt
comment|/* Number of sequence timeout expirations (E_D_TOV) */
decl_stmt|;
name|uint32_t
name|drop_seq_cnt
comment|/* Number of Sequences that were sropped */
decl_stmt|;
name|uint32_t
name|fcoe_rx_drop_pkt_cnt
comment|/* Number of FCoE packets that were dropped */
decl_stmt|;
name|uint32_t
name|fcp_rx_pkt_cnt
comment|/* Number of FCP packets that were legally received */
decl_stmt|;
name|uint32_t
name|reserved0
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Fcoe rx_wr union context $$KEEP_ENDIANNESS$$  */
end_comment

begin_union
union|union
name|fcoe_rx_wr_union_ctx
block|{
name|struct
name|fcoe_read_flow_info
name|read_info
comment|/* Data-In/ELS/BLS information */
decl_stmt|;
name|union
name|fcoe_comp_flow_info
name|comp_info
comment|/* Completion information */
decl_stmt|;
name|uint32_t
name|opaque
index|[
literal|8
index|]
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/*  * FCoE SQ element $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|fcoe_sqe
block|{
name|uint16_t
name|wqe
decl_stmt|;
define|#
directive|define
name|FCOE_SQE_TASK_ID
value|(0x7FFF<<0)
comment|/* BitField wqe	The task ID (OX_ID) to be processed */
define|#
directive|define
name|FCOE_SQE_TASK_ID_SHIFT
value|0
define|#
directive|define
name|FCOE_SQE_TOGGLE_BIT
value|(0x1<<15)
comment|/* BitField wqe	Toggle bit updated by the driver */
define|#
directive|define
name|FCOE_SQE_TOGGLE_BIT_SHIFT
value|15
block|}
struct|;
end_struct

begin_comment
comment|/*  * FCoE TX statistics parameters $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|fcoe_tx_stat_params
block|{
name|uint32_t
name|fcoe_tx_pkt_cnt
comment|/* Number of transmitted FCoE packets */
decl_stmt|;
name|uint32_t
name|fcoe_tx_byte_cnt
comment|/* Number of transmitted FCoE bytes */
decl_stmt|;
name|uint32_t
name|fcp_tx_pkt_cnt
comment|/* Number of transmitted FCP packets */
decl_stmt|;
name|uint32_t
name|reserved0
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * FCoE statistics parameters $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|fcoe_statistics_params
block|{
name|struct
name|fcoe_tx_stat_params
name|tx_stat
comment|/* FCoE TX statistics parameters */
decl_stmt|;
name|struct
name|fcoe_rx_stat_params_section0
name|rx_stat0
comment|/* FCoE RX statistics parameters section#0 */
decl_stmt|;
name|struct
name|fcoe_rx_stat_params_section1
name|rx_stat1
comment|/* FCoE RX statistics parameters section#1 */
decl_stmt|;
name|struct
name|fcoe_rx_stat_params_section2
name|rx_stat2
comment|/* FCoE RX statistics parameters section#2 */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * 14 regs $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|fcoe_tce_tx_only
block|{
name|union
name|fcoe_sgl_union_ctx
name|sgl_ctx
comment|/* TX SGL context */
decl_stmt|;
name|uint32_t
name|rsrv0
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * 32 bytes (8 regs) used for TX only purposes $$KEEP_ENDIANNESS$$  */
end_comment

begin_union
union|union
name|fcoe_tx_wr_rx_rd_union_ctx
block|{
name|struct
name|fcoe_fc_frame
name|tx_frame
comment|/* Middle-path/ABTS/Data-Out information */
decl_stmt|;
name|struct
name|fcoe_fcp_cmd_payload
name|fcp_cmd
comment|/* FCP_CMD payload */
decl_stmt|;
name|struct
name|fcoe_ext_cleanup_info
name|cleanup
comment|/* Task ID to be cleaned */
decl_stmt|;
name|struct
name|fcoe_ext_abts_info
name|abts
comment|/* Task ID to be aborted */
decl_stmt|;
name|struct
name|fcoe_ext_fw_tx_seq_ctx
name|tx_seq
comment|/* TX sequence information */
decl_stmt|;
name|uint32_t
name|opaque
index|[
literal|8
index|]
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/*  * tce_tx_wr_rx_rd_const $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|fcoe_tce_tx_wr_rx_rd_const
block|{
name|uint8_t
name|init_flags
decl_stmt|;
define|#
directive|define
name|FCOE_TCE_TX_WR_RX_RD_CONST_TASK_TYPE
value|(0x7<<0)
comment|/* BitField init_flags	Task type - Write / Read / Middle / Unsolicited / ABTS / Cleanup */
define|#
directive|define
name|FCOE_TCE_TX_WR_RX_RD_CONST_TASK_TYPE_SHIFT
value|0
define|#
directive|define
name|FCOE_TCE_TX_WR_RX_RD_CONST_DEV_TYPE
value|(0x1<<3)
comment|/* BitField init_flags	Tape/Disk device indication */
define|#
directive|define
name|FCOE_TCE_TX_WR_RX_RD_CONST_DEV_TYPE_SHIFT
value|3
define|#
directive|define
name|FCOE_TCE_TX_WR_RX_RD_CONST_CLASS_TYPE
value|(0x1<<4)
comment|/* BitField init_flags	Class 3/2 indication */
define|#
directive|define
name|FCOE_TCE_TX_WR_RX_RD_CONST_CLASS_TYPE_SHIFT
value|4
define|#
directive|define
name|FCOE_TCE_TX_WR_RX_RD_CONST_CACHED_SGE
value|(0x3<<5)
comment|/* BitField init_flags	Num of cached sge (0 - not cached sge) */
define|#
directive|define
name|FCOE_TCE_TX_WR_RX_RD_CONST_CACHED_SGE_SHIFT
value|5
define|#
directive|define
name|FCOE_TCE_TX_WR_RX_RD_CONST_SUPPORT_REC_TOV
value|(0x1<<7)
comment|/* BitField init_flags	Support REC_TOV flag, for FW use only */
define|#
directive|define
name|FCOE_TCE_TX_WR_RX_RD_CONST_SUPPORT_REC_TOV_SHIFT
value|7
name|uint8_t
name|tx_flags
decl_stmt|;
define|#
directive|define
name|FCOE_TCE_TX_WR_RX_RD_CONST_TX_VALID
value|(0x1<<0)
comment|/* BitField tx_flagsBoth TX and RX processing could read but only the TX could write	Indication of TX valid task */
define|#
directive|define
name|FCOE_TCE_TX_WR_RX_RD_CONST_TX_VALID_SHIFT
value|0
define|#
directive|define
name|FCOE_TCE_TX_WR_RX_RD_CONST_TX_STATE
value|(0xF<<1)
comment|/* BitField tx_flagsBoth TX and RX processing could read but only the TX could write	The TX state of the task */
define|#
directive|define
name|FCOE_TCE_TX_WR_RX_RD_CONST_TX_STATE_SHIFT
value|1
define|#
directive|define
name|FCOE_TCE_TX_WR_RX_RD_CONST_RSRV1
value|(0x1<<5)
comment|/* BitField tx_flagsBoth TX and RX processing could read but only the TX could write	 */
define|#
directive|define
name|FCOE_TCE_TX_WR_RX_RD_CONST_RSRV1_SHIFT
value|5
define|#
directive|define
name|FCOE_TCE_TX_WR_RX_RD_CONST_TX_SEQ_INIT
value|(0x1<<6)
comment|/* BitField tx_flagsBoth TX and RX processing could read but only the TX could write	TX Sequence initiative indication */
define|#
directive|define
name|FCOE_TCE_TX_WR_RX_RD_CONST_TX_SEQ_INIT_SHIFT
value|6
define|#
directive|define
name|FCOE_TCE_TX_WR_RX_RD_CONST_TX_COMP_TRNS
value|(0x1<<7)
comment|/* BitField tx_flagsBoth TX and RX processing could read but only the TX could write	Compelted full tranmission of this task */
define|#
directive|define
name|FCOE_TCE_TX_WR_RX_RD_CONST_TX_COMP_TRNS_SHIFT
value|7
name|uint16_t
name|rsrv3
decl_stmt|;
name|uint32_t
name|verify_tx_seq
comment|/* Sequence counter snapshot in order to verify target did not send FCP_RSP before the actual transmission of PBF from the SGL */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * tce_tx_wr_rx_rd $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|fcoe_tce_tx_wr_rx_rd
block|{
name|union
name|fcoe_tx_wr_rx_rd_union_ctx
name|union_ctx
comment|/* 32 (8 regs) bytes used for TX only purposes */
decl_stmt|;
name|struct
name|fcoe_tce_tx_wr_rx_rd_const
name|const_ctx
comment|/* Constant TX_WR_RX_RD */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * tce_rx_wr_tx_rd_const $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|fcoe_tce_rx_wr_tx_rd_const
block|{
name|uint32_t
name|data_2_trns
comment|/* The maximum amount of data that would be transferred in this task */
decl_stmt|;
name|uint32_t
name|init_flags
decl_stmt|;
define|#
directive|define
name|FCOE_TCE_RX_WR_TX_RD_CONST_CID
value|(0xFFFFFF<<0)
comment|/* BitField init_flags	The CID of the connection (used by the CHIP) */
define|#
directive|define
name|FCOE_TCE_RX_WR_TX_RD_CONST_CID_SHIFT
value|0
define|#
directive|define
name|FCOE_TCE_RX_WR_TX_RD_CONST_RSRV0
value|(0xFF<<24)
comment|/* BitField init_flags	 */
define|#
directive|define
name|FCOE_TCE_RX_WR_TX_RD_CONST_RSRV0_SHIFT
value|24
block|}
struct|;
end_struct

begin_comment
comment|/*  * tce_rx_wr_tx_rd_var $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|fcoe_tce_rx_wr_tx_rd_var
block|{
name|uint16_t
name|rx_flags
decl_stmt|;
define|#
directive|define
name|FCOE_TCE_RX_WR_TX_RD_VAR_RSRV1
value|(0xF<<0)
comment|/* BitField rx_flags	 */
define|#
directive|define
name|FCOE_TCE_RX_WR_TX_RD_VAR_RSRV1_SHIFT
value|0
define|#
directive|define
name|FCOE_TCE_RX_WR_TX_RD_VAR_NUM_RQ_WQE
value|(0x7<<4)
comment|/* BitField rx_flags	The number of RQ WQEs that were consumed (for sense data only) */
define|#
directive|define
name|FCOE_TCE_RX_WR_TX_RD_VAR_NUM_RQ_WQE_SHIFT
value|4
define|#
directive|define
name|FCOE_TCE_RX_WR_TX_RD_VAR_CONF_REQ
value|(0x1<<7)
comment|/* BitField rx_flags	Confirmation request indication */
define|#
directive|define
name|FCOE_TCE_RX_WR_TX_RD_VAR_CONF_REQ_SHIFT
value|7
define|#
directive|define
name|FCOE_TCE_RX_WR_TX_RD_VAR_RX_STATE
value|(0xF<<8)
comment|/* BitField rx_flags	The RX state of the task */
define|#
directive|define
name|FCOE_TCE_RX_WR_TX_RD_VAR_RX_STATE_SHIFT
value|8
define|#
directive|define
name|FCOE_TCE_RX_WR_TX_RD_VAR_EXP_FIRST_FRAME
value|(0x1<<12)
comment|/* BitField rx_flags	Indication on expecting to receive the first frame from target */
define|#
directive|define
name|FCOE_TCE_RX_WR_TX_RD_VAR_EXP_FIRST_FRAME_SHIFT
value|12
define|#
directive|define
name|FCOE_TCE_RX_WR_TX_RD_VAR_RX_SEQ_INIT
value|(0x1<<13)
comment|/* BitField rx_flags	RX Sequence initiative indication */
define|#
directive|define
name|FCOE_TCE_RX_WR_TX_RD_VAR_RX_SEQ_INIT_SHIFT
value|13
define|#
directive|define
name|FCOE_TCE_RX_WR_TX_RD_VAR_RSRV2
value|(0x1<<14)
comment|/* BitField rx_flags	 */
define|#
directive|define
name|FCOE_TCE_RX_WR_TX_RD_VAR_RSRV2_SHIFT
value|14
define|#
directive|define
name|FCOE_TCE_RX_WR_TX_RD_VAR_RX_VALID
value|(0x1<<15)
comment|/* BitField rx_flags	Indication of RX valid task */
define|#
directive|define
name|FCOE_TCE_RX_WR_TX_RD_VAR_RX_VALID_SHIFT
value|15
name|uint16_t
name|rx_id
comment|/* The RX_ID read from incoming frame and to be used in subsequent transmitting frames */
decl_stmt|;
name|struct
name|fcoe_fcp_xfr_rdy_payload
name|fcp_xfr_rdy
comment|/* Data-In/ELS/BLS information */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * tce_rx_wr_tx_rd $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|fcoe_tce_rx_wr_tx_rd
block|{
name|struct
name|fcoe_tce_rx_wr_tx_rd_const
name|const_ctx
comment|/* The RX_ID read from incoming frame and to be used in subsequent transmitting frames */
decl_stmt|;
name|struct
name|fcoe_tce_rx_wr_tx_rd_var
name|var_ctx
comment|/* The RX_ID read from incoming frame and to be used in subsequent transmitting frames */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * tce_rx_only $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|fcoe_tce_rx_only
block|{
name|struct
name|fcoe_rx_seq_ctx
name|rx_seq_ctx
comment|/* The context of current receiving Sequence */
decl_stmt|;
name|union
name|fcoe_rx_wr_union_ctx
name|union_ctx
comment|/* Read flow info/ Completion flow info */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * task_ctx_entry $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|fcoe_task_ctx_entry
block|{
name|struct
name|fcoe_tce_tx_only
name|txwr_only
comment|/* TX processing shall be the only one to read/write to this section */
decl_stmt|;
name|struct
name|fcoe_tce_tx_wr_rx_rd
name|txwr_rxrd
comment|/* TX processing shall write and RX shall read from this section */
decl_stmt|;
name|struct
name|fcoe_tce_rx_wr_tx_rd
name|rxwr_txrd
comment|/* RX processing shall write and TX shall read from this section */
decl_stmt|;
name|struct
name|fcoe_tce_rx_only
name|rxwr_only
comment|/* RX processing shall be the only one to read/write to this section */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * FCoE XFRQ element $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|fcoe_xfrqe
block|{
name|uint16_t
name|wqe
decl_stmt|;
define|#
directive|define
name|FCOE_XFRQE_TASK_ID
value|(0x7FFF<<0)
comment|/* BitField wqe	The task ID (OX_ID) to be processed */
define|#
directive|define
name|FCOE_XFRQE_TASK_ID_SHIFT
value|0
define|#
directive|define
name|FCOE_XFRQE_TOGGLE_BIT
value|(0x1<<15)
comment|/* BitField wqe	Toggle bit updated by the driver */
define|#
directive|define
name|FCOE_XFRQE_TOGGLE_BIT_SHIFT
value|15
block|}
struct|;
end_struct

begin_comment
comment|/*  * Cached SGEs $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|common_fcoe_sgl
block|{
name|struct
name|fcoe_bd_ctx
name|sge
index|[
literal|3
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * FCoE SQ\XFRQ element  */
end_comment

begin_struct
struct|struct
name|fcoe_cached_wqe
block|{
name|struct
name|fcoe_sqe
name|sqe
comment|/* SQ WQE */
decl_stmt|;
name|struct
name|fcoe_xfrqe
name|xfrqe
comment|/* XFRQ WQE */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * FCoE connection enable\disable params passed by driver to FW in FCoE enable ramrod $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|fcoe_conn_enable_disable_ramrod_params
block|{
name|struct
name|fcoe_kwqe_conn_enable_disable
name|enable_disable_kwqe
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * FCoE connection offload params passed by driver to FW in FCoE offload ramrod $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|fcoe_conn_offload_ramrod_params
block|{
name|struct
name|fcoe_kwqe_conn_offload1
name|offload_kwqe1
decl_stmt|;
name|struct
name|fcoe_kwqe_conn_offload2
name|offload_kwqe2
decl_stmt|;
name|struct
name|fcoe_kwqe_conn_offload3
name|offload_kwqe3
decl_stmt|;
name|struct
name|fcoe_kwqe_conn_offload4
name|offload_kwqe4
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ustorm_fcoe_mng_ctx
block|{
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint8_t
name|mid_seq_proc_flag
comment|/* Middle Sequence received processing */
decl_stmt|;
name|uint8_t
name|tce_in_cam_flag
comment|/* TCE in CAM indication */
decl_stmt|;
name|uint8_t
name|tce_on_ior_flag
comment|/* TCE on IOR indication (TCE on IORs but not necessarily in CAM) */
decl_stmt|;
name|uint8_t
name|en_cached_tce_flag
comment|/* TCE cached functionality enabled indication */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint8_t
name|en_cached_tce_flag
comment|/* TCE cached functionality enabled indication */
decl_stmt|;
name|uint8_t
name|tce_on_ior_flag
comment|/* TCE on IOR indication (TCE on IORs but not necessarily in CAM) */
decl_stmt|;
name|uint8_t
name|tce_in_cam_flag
comment|/* TCE in CAM indication */
decl_stmt|;
name|uint8_t
name|mid_seq_proc_flag
comment|/* Middle Sequence received processing */
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint8_t
name|tce_cam_addr
comment|/* CAM address of task context */
decl_stmt|;
name|uint8_t
name|cached_conn_flag
comment|/* Cached locked connection indication */
decl_stmt|;
name|uint16_t
name|rsrv0
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|rsrv0
decl_stmt|;
name|uint8_t
name|cached_conn_flag
comment|/* Cached locked connection indication */
decl_stmt|;
name|uint8_t
name|tce_cam_addr
comment|/* CAM address of task context */
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|dma_tce_ram_addr
comment|/* RAM address of task context when executing DMA operations (read/write) */
decl_stmt|;
name|uint16_t
name|tce_ram_addr
comment|/* RAM address of task context (might be in cached table or in scratchpad) */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|tce_ram_addr
comment|/* RAM address of task context (might be in cached table or in scratchpad) */
decl_stmt|;
name|uint16_t
name|dma_tce_ram_addr
comment|/* RAM address of task context when executing DMA operations (read/write) */
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|ox_id
comment|/* Last OX_ID that has been used */
decl_stmt|;
name|uint16_t
name|wr_done_seq
comment|/* Last task write done in the specific connection */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|wr_done_seq
comment|/* Last task write done in the specific connection */
decl_stmt|;
name|uint16_t
name|ox_id
comment|/* Last OX_ID that has been used */
decl_stmt|;
endif|#
directive|endif
name|struct
name|regpair_t
name|task_addr
comment|/* Last task address in used */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Parameters initialized during offloaded according to FLOGI/PLOGI/PRLI and used in FCoE context section  */
end_comment

begin_struct
struct|struct
name|ustorm_fcoe_params
block|{
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|fcoe_conn_id
comment|/* The connection ID that would be used by driver to identify the conneciton */
decl_stmt|;
name|uint16_t
name|flags
decl_stmt|;
define|#
directive|define
name|USTORM_FCOE_PARAMS_B_MUL_N_PORT_IDS
value|(0x1<<0)
comment|/* BitField flags	Supporting multiple N_Port IDs indication, received during FLOGI */
define|#
directive|define
name|USTORM_FCOE_PARAMS_B_MUL_N_PORT_IDS_SHIFT
value|0
define|#
directive|define
name|USTORM_FCOE_PARAMS_B_E_D_TOV_RES
value|(0x1<<1)
comment|/* BitField flags	E_D_TOV resolution (0 - msec, 1 - nsec), negotiated in PLOGI */
define|#
directive|define
name|USTORM_FCOE_PARAMS_B_E_D_TOV_RES_SHIFT
value|1
define|#
directive|define
name|USTORM_FCOE_PARAMS_B_CONT_INCR_SEQ_CNT
value|(0x1<<2)
comment|/* BitField flags	Continuously increasing SEQ_CNT indication, received during PLOGI */
define|#
directive|define
name|USTORM_FCOE_PARAMS_B_CONT_INCR_SEQ_CNT_SHIFT
value|2
define|#
directive|define
name|USTORM_FCOE_PARAMS_B_CONF_REQ
value|(0x1<<3)
comment|/* BitField flags	Confirmation request supported */
define|#
directive|define
name|USTORM_FCOE_PARAMS_B_CONF_REQ_SHIFT
value|3
define|#
directive|define
name|USTORM_FCOE_PARAMS_B_REC_VALID
value|(0x1<<4)
comment|/* BitField flags	REC allowed */
define|#
directive|define
name|USTORM_FCOE_PARAMS_B_REC_VALID_SHIFT
value|4
define|#
directive|define
name|USTORM_FCOE_PARAMS_B_CQ_TOGGLE_BIT
value|(0x1<<5)
comment|/* BitField flags	CQ toggle bit */
define|#
directive|define
name|USTORM_FCOE_PARAMS_B_CQ_TOGGLE_BIT_SHIFT
value|5
define|#
directive|define
name|USTORM_FCOE_PARAMS_B_XFRQ_TOGGLE_BIT
value|(0x1<<6)
comment|/* BitField flags	XFRQ toggle bit */
define|#
directive|define
name|USTORM_FCOE_PARAMS_B_XFRQ_TOGGLE_BIT_SHIFT
value|6
define|#
directive|define
name|USTORM_FCOE_PARAMS_B_CONFQ_TOGGLE_BIT
value|(0x1<<7)
comment|/* BitField flags	CONFQ toggle bit */
define|#
directive|define
name|USTORM_FCOE_PARAMS_B_CONFQ_TOGGLE_BIT_SHIFT
value|7
define|#
directive|define
name|USTORM_FCOE_PARAMS_RSRV0
value|(0xFF<<8)
comment|/* BitField flags	 */
define|#
directive|define
name|USTORM_FCOE_PARAMS_RSRV0_SHIFT
value|8
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|flags
decl_stmt|;
define|#
directive|define
name|USTORM_FCOE_PARAMS_B_MUL_N_PORT_IDS
value|(0x1<<0)
comment|/* BitField flags	Supporting multiple N_Port IDs indication, received during FLOGI */
define|#
directive|define
name|USTORM_FCOE_PARAMS_B_MUL_N_PORT_IDS_SHIFT
value|0
define|#
directive|define
name|USTORM_FCOE_PARAMS_B_E_D_TOV_RES
value|(0x1<<1)
comment|/* BitField flags	E_D_TOV resolution (0 - msec, 1 - nsec), negotiated in PLOGI */
define|#
directive|define
name|USTORM_FCOE_PARAMS_B_E_D_TOV_RES_SHIFT
value|1
define|#
directive|define
name|USTORM_FCOE_PARAMS_B_CONT_INCR_SEQ_CNT
value|(0x1<<2)
comment|/* BitField flags	Continuously increasing SEQ_CNT indication, received during PLOGI */
define|#
directive|define
name|USTORM_FCOE_PARAMS_B_CONT_INCR_SEQ_CNT_SHIFT
value|2
define|#
directive|define
name|USTORM_FCOE_PARAMS_B_CONF_REQ
value|(0x1<<3)
comment|/* BitField flags	Confirmation request supported */
define|#
directive|define
name|USTORM_FCOE_PARAMS_B_CONF_REQ_SHIFT
value|3
define|#
directive|define
name|USTORM_FCOE_PARAMS_B_REC_VALID
value|(0x1<<4)
comment|/* BitField flags	REC allowed */
define|#
directive|define
name|USTORM_FCOE_PARAMS_B_REC_VALID_SHIFT
value|4
define|#
directive|define
name|USTORM_FCOE_PARAMS_B_CQ_TOGGLE_BIT
value|(0x1<<5)
comment|/* BitField flags	CQ toggle bit */
define|#
directive|define
name|USTORM_FCOE_PARAMS_B_CQ_TOGGLE_BIT_SHIFT
value|5
define|#
directive|define
name|USTORM_FCOE_PARAMS_B_XFRQ_TOGGLE_BIT
value|(0x1<<6)
comment|/* BitField flags	XFRQ toggle bit */
define|#
directive|define
name|USTORM_FCOE_PARAMS_B_XFRQ_TOGGLE_BIT_SHIFT
value|6
define|#
directive|define
name|USTORM_FCOE_PARAMS_B_CONFQ_TOGGLE_BIT
value|(0x1<<7)
comment|/* BitField flags	CONFQ toggle bit */
define|#
directive|define
name|USTORM_FCOE_PARAMS_B_CONFQ_TOGGLE_BIT_SHIFT
value|7
define|#
directive|define
name|USTORM_FCOE_PARAMS_RSRV0
value|(0xFF<<8)
comment|/* BitField flags	 */
define|#
directive|define
name|USTORM_FCOE_PARAMS_RSRV0_SHIFT
value|8
name|uint16_t
name|fcoe_conn_id
comment|/* The connection ID that would be used by driver to identify the conneciton */
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint8_t
name|hc_csdm_byte_en
comment|/* Host coalescing Cstorm RAM address byte enable */
decl_stmt|;
name|uint8_t
name|func_id
comment|/* Function id */
decl_stmt|;
name|uint8_t
name|port_id
comment|/* Port id */
decl_stmt|;
name|uint8_t
name|vnic_id
comment|/* Vnic id */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint8_t
name|vnic_id
comment|/* Vnic id */
decl_stmt|;
name|uint8_t
name|port_id
comment|/* Port id */
decl_stmt|;
name|uint8_t
name|func_id
comment|/* Function id */
decl_stmt|;
name|uint8_t
name|hc_csdm_byte_en
comment|/* Host coalescing Cstorm RAM address byte enable */
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|rx_total_conc_seqs
comment|/* Total concurrent Sequences for all Classes supported by us, sent during PLOGI */
decl_stmt|;
name|uint16_t
name|rx_max_fc_pay_len
comment|/* The maximum acceptable FC payload size (Buffer-to-buffer Receive Data_Field size) supported by us, sent during FLOGI/PLOGI */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|rx_max_fc_pay_len
comment|/* The maximum acceptable FC payload size (Buffer-to-buffer Receive Data_Field size) supported by us, sent during FLOGI/PLOGI */
decl_stmt|;
name|uint16_t
name|rx_total_conc_seqs
comment|/* Total concurrent Sequences for all Classes supported by us, sent during PLOGI */
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint8_t
name|task_pbe_idx_off
comment|/* The first PBE for this specific task list in RAM */
decl_stmt|;
name|uint8_t
name|task_in_page_log_size
comment|/* Number of tasks in page (log 2) */
decl_stmt|;
name|uint16_t
name|rx_max_conc_seqs
comment|/* Maximum Concurrent Sequences for Class 3 supported by us, sent during PLOGI */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|rx_max_conc_seqs
comment|/* Maximum Concurrent Sequences for Class 3 supported by us, sent during PLOGI */
decl_stmt|;
name|uint8_t
name|task_in_page_log_size
comment|/* Number of tasks in page (log 2) */
decl_stmt|;
name|uint8_t
name|task_pbe_idx_off
comment|/* The first PBE for this specific task list in RAM */
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/*  * FCoE 16-bits index structure  */
end_comment

begin_struct
struct|struct
name|fcoe_idx16_fields
block|{
name|uint16_t
name|fields
decl_stmt|;
define|#
directive|define
name|FCOE_IDX16_FIELDS_IDX
value|(0x7FFF<<0)
comment|/* BitField fields	 */
define|#
directive|define
name|FCOE_IDX16_FIELDS_IDX_SHIFT
value|0
define|#
directive|define
name|FCOE_IDX16_FIELDS_MSB
value|(0x1<<15)
comment|/* BitField fields	 */
define|#
directive|define
name|FCOE_IDX16_FIELDS_MSB_SHIFT
value|15
block|}
struct|;
end_struct

begin_comment
comment|/*  * FCoE 16-bits index union  */
end_comment

begin_union
union|union
name|fcoe_idx16_field_union
block|{
name|struct
name|fcoe_idx16_fields
name|fields
comment|/* Parameters field */
decl_stmt|;
name|uint16_t
name|val
comment|/* Global value */
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/*  * Parameters required for placement according to SGL  */
end_comment

begin_struct
struct|struct
name|ustorm_fcoe_data_place_mng
block|{
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|sge_off
decl_stmt|;
name|uint8_t
name|num_sges
comment|/* Number of SGEs left to be used on context */
decl_stmt|;
name|uint8_t
name|sge_idx
comment|/* 0xFF value indicated loading SGL */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint8_t
name|sge_idx
comment|/* 0xFF value indicated loading SGL */
decl_stmt|;
name|uint8_t
name|num_sges
comment|/* Number of SGEs left to be used on context */
decl_stmt|;
name|uint16_t
name|sge_off
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/*  * Parameters required for placement according to SGL  */
end_comment

begin_struct
struct|struct
name|ustorm_fcoe_data_place
block|{
name|struct
name|ustorm_fcoe_data_place_mng
name|cached_mng
comment|/* 0xFF value indicated loading SGL */
decl_stmt|;
name|struct
name|fcoe_bd_ctx
name|cached_sge
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * TX processing shall write and RX processing shall read from this section  */
end_comment

begin_union
union|union
name|fcoe_u_tce_tx_wr_rx_rd_union
block|{
name|struct
name|fcoe_abts_info
name|abts
comment|/* ABTS information */
decl_stmt|;
name|struct
name|fcoe_cleanup_info
name|cleanup
comment|/* Cleanup information */
decl_stmt|;
name|struct
name|fcoe_fw_tx_seq_ctx
name|tx_seq_ctx
comment|/* TX sequence context */
decl_stmt|;
name|uint32_t
name|opaque
index|[
literal|2
index|]
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/*  * TX processing shall write and RX processing shall read from this section  */
end_comment

begin_struct
struct|struct
name|fcoe_u_tce_tx_wr_rx_rd
block|{
name|union
name|fcoe_u_tce_tx_wr_rx_rd_union
name|union_ctx
comment|/* FW DATA_OUT/CLEANUP information */
decl_stmt|;
name|struct
name|fcoe_tce_tx_wr_rx_rd_const
name|const_ctx
comment|/* TX processing shall write and RX shall read from this section */
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ustorm_fcoe_tce
block|{
name|struct
name|fcoe_u_tce_tx_wr_rx_rd
name|txwr_rxrd
comment|/* TX processing shall write and RX shall read from this section */
decl_stmt|;
name|struct
name|fcoe_tce_rx_wr_tx_rd
name|rxwr_txrd
comment|/* RX processing shall write and TX shall read from this section */
decl_stmt|;
name|struct
name|fcoe_tce_rx_only
name|rxwr
comment|/* RX processing shall be the only one to read/write to this section */
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ustorm_fcoe_cache_ctx
block|{
name|uint32_t
name|rsrv0
decl_stmt|;
name|struct
name|ustorm_fcoe_data_place
name|data_place
decl_stmt|;
name|struct
name|ustorm_fcoe_tce
name|tce
comment|/* Task context */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Ustorm FCoE Storm Context  */
end_comment

begin_struct
struct|struct
name|ustorm_fcoe_st_context
block|{
name|struct
name|ustorm_fcoe_mng_ctx
name|mng_ctx
comment|/* Managing the processing of the flow */
decl_stmt|;
name|struct
name|ustorm_fcoe_params
name|fcoe_params
comment|/* Align to 128 bytes */
decl_stmt|;
name|struct
name|regpair_t
name|cq_base_addr
comment|/* CQ current page host address */
decl_stmt|;
name|struct
name|regpair_t
name|rq_pbl_base
comment|/* PBL host address for RQ */
decl_stmt|;
name|struct
name|regpair_t
name|rq_cur_page_addr
comment|/* RQ current page host address */
decl_stmt|;
name|struct
name|regpair_t
name|confq_pbl_base_addr
comment|/* Base address of the CONFQ page list */
decl_stmt|;
name|struct
name|regpair_t
name|conn_db_base
comment|/* Connection data base address in host memory where RQ producer and CQ arm bit reside in */
decl_stmt|;
name|struct
name|regpair_t
name|xfrq_base_addr
comment|/* XFRQ base host address */
decl_stmt|;
name|struct
name|regpair_t
name|lcq_base_addr
comment|/* LCQ base host address */
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|union
name|fcoe_idx16_field_union
name|rq_cons
comment|/* RQ consumer advance for each RQ WQE consuming */
decl_stmt|;
name|union
name|fcoe_idx16_field_union
name|rq_prod
comment|/* RQ producer update by driver and read by FW (should be initialized to RQ size)  */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|union
name|fcoe_idx16_field_union
name|rq_prod
comment|/* RQ producer update by driver and read by FW (should be initialized to RQ size)  */
decl_stmt|;
name|union
name|fcoe_idx16_field_union
name|rq_cons
comment|/* RQ consumer advance for each RQ WQE consuming */
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|xfrq_prod
comment|/* XFRQ producer (No consumer is needed since Q can not be overloaded) */
decl_stmt|;
name|uint16_t
name|cq_cons
comment|/* CQ consumer copy of last update from driver (Q can not be overloaded) */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|cq_cons
comment|/* CQ consumer copy of last update from driver (Q can not be overloaded) */
decl_stmt|;
name|uint16_t
name|xfrq_prod
comment|/* XFRQ producer (No consumer is needed since Q can not be overloaded) */
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|lcq_cons
comment|/* lcq consumer */
decl_stmt|;
name|uint16_t
name|hc_cram_address
comment|/* Host coalescing Cstorm RAM address */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|hc_cram_address
comment|/* Host coalescing Cstorm RAM address */
decl_stmt|;
name|uint16_t
name|lcq_cons
comment|/* lcq consumer */
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|sq_xfrq_lcq_confq_size
comment|/* SQ/XFRQ/LCQ/CONFQ size */
decl_stmt|;
name|uint16_t
name|confq_prod
comment|/* CONFQ producer */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|confq_prod
comment|/* CONFQ producer */
decl_stmt|;
name|uint16_t
name|sq_xfrq_lcq_confq_size
comment|/* SQ/XFRQ/LCQ/CONFQ size */
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint8_t
name|hc_csdm_agg_int
comment|/* Host coalescing CSDM aggregative interrupts */
decl_stmt|;
name|uint8_t
name|rsrv2
decl_stmt|;
name|uint8_t
name|available_rqes
comment|/* Available RQEs */
decl_stmt|;
name|uint8_t
name|sp_q_flush_cnt
comment|/* The remain number of queues to be flushed (in QM) */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint8_t
name|sp_q_flush_cnt
comment|/* The remain number of queues to be flushed (in QM) */
decl_stmt|;
name|uint8_t
name|available_rqes
comment|/* Available RQEs */
decl_stmt|;
name|uint8_t
name|rsrv2
decl_stmt|;
name|uint8_t
name|hc_csdm_agg_int
comment|/* Host coalescing CSDM aggregative interrupts */
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|num_pend_tasks
comment|/* Number of pending tasks */
decl_stmt|;
name|uint16_t
name|pbf_ack_ram_addr
comment|/* PBF TX sequence ACK ram address */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|pbf_ack_ram_addr
comment|/* PBF TX sequence ACK ram address */
decl_stmt|;
name|uint16_t
name|num_pend_tasks
comment|/* Number of pending tasks */
decl_stmt|;
endif|#
directive|endif
name|struct
name|ustorm_fcoe_cache_ctx
name|cache_ctx
comment|/* Cached context */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The FCoE non-aggregative context of Tstorm  */
end_comment

begin_struct
struct|struct
name|tstorm_fcoe_st_context
block|{
name|struct
name|regpair_t
name|reserved0
decl_stmt|;
name|struct
name|regpair_t
name|reserved1
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Ethernet context section  */
end_comment

begin_struct
struct|struct
name|xstorm_fcoe_eth_context_section
block|{
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint8_t
name|remote_addr_4
comment|/* Remote Mac Address, used in PBF Header Builder Command */
decl_stmt|;
name|uint8_t
name|remote_addr_5
comment|/* Remote Mac Address, used in PBF Header Builder Command */
decl_stmt|;
name|uint8_t
name|local_addr_0
comment|/* Local Mac Address, used in PBF Header Builder Command */
decl_stmt|;
name|uint8_t
name|local_addr_1
comment|/* Local Mac Address, used in PBF Header Builder Command */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint8_t
name|local_addr_1
comment|/* Local Mac Address, used in PBF Header Builder Command */
decl_stmt|;
name|uint8_t
name|local_addr_0
comment|/* Local Mac Address, used in PBF Header Builder Command */
decl_stmt|;
name|uint8_t
name|remote_addr_5
comment|/* Remote Mac Address, used in PBF Header Builder Command */
decl_stmt|;
name|uint8_t
name|remote_addr_4
comment|/* Remote Mac Address, used in PBF Header Builder Command */
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint8_t
name|remote_addr_0
comment|/* Remote Mac Address, used in PBF Header Builder Command */
decl_stmt|;
name|uint8_t
name|remote_addr_1
comment|/* Remote Mac Address, used in PBF Header Builder Command */
decl_stmt|;
name|uint8_t
name|remote_addr_2
comment|/* Remote Mac Address, used in PBF Header Builder Command */
decl_stmt|;
name|uint8_t
name|remote_addr_3
comment|/* Remote Mac Address, used in PBF Header Builder Command */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint8_t
name|remote_addr_3
comment|/* Remote Mac Address, used in PBF Header Builder Command */
decl_stmt|;
name|uint8_t
name|remote_addr_2
comment|/* Remote Mac Address, used in PBF Header Builder Command */
decl_stmt|;
name|uint8_t
name|remote_addr_1
comment|/* Remote Mac Address, used in PBF Header Builder Command */
decl_stmt|;
name|uint8_t
name|remote_addr_0
comment|/* Remote Mac Address, used in PBF Header Builder Command */
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|reserved_vlan_type
comment|/* this field is not an absolute must, but the reseved was here */
decl_stmt|;
name|uint16_t
name|params
decl_stmt|;
define|#
directive|define
name|XSTORM_FCOE_ETH_CONTEXT_SECTION_VLAN_ID
value|(0xFFF<<0)
comment|/* BitField params	part of PBF Header Builder Command */
define|#
directive|define
name|XSTORM_FCOE_ETH_CONTEXT_SECTION_VLAN_ID_SHIFT
value|0
define|#
directive|define
name|XSTORM_FCOE_ETH_CONTEXT_SECTION_CFI
value|(0x1<<12)
comment|/* BitField params	Canonical format indicator, part of PBF Header Builder Command */
define|#
directive|define
name|XSTORM_FCOE_ETH_CONTEXT_SECTION_CFI_SHIFT
value|12
define|#
directive|define
name|XSTORM_FCOE_ETH_CONTEXT_SECTION_PRIORITY
value|(0x7<<13)
comment|/* BitField params	part of PBF Header Builder Command */
define|#
directive|define
name|XSTORM_FCOE_ETH_CONTEXT_SECTION_PRIORITY_SHIFT
value|13
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|params
decl_stmt|;
define|#
directive|define
name|XSTORM_FCOE_ETH_CONTEXT_SECTION_VLAN_ID
value|(0xFFF<<0)
comment|/* BitField params	part of PBF Header Builder Command */
define|#
directive|define
name|XSTORM_FCOE_ETH_CONTEXT_SECTION_VLAN_ID_SHIFT
value|0
define|#
directive|define
name|XSTORM_FCOE_ETH_CONTEXT_SECTION_CFI
value|(0x1<<12)
comment|/* BitField params	Canonical format indicator, part of PBF Header Builder Command */
define|#
directive|define
name|XSTORM_FCOE_ETH_CONTEXT_SECTION_CFI_SHIFT
value|12
define|#
directive|define
name|XSTORM_FCOE_ETH_CONTEXT_SECTION_PRIORITY
value|(0x7<<13)
comment|/* BitField params	part of PBF Header Builder Command */
define|#
directive|define
name|XSTORM_FCOE_ETH_CONTEXT_SECTION_PRIORITY_SHIFT
value|13
name|uint16_t
name|reserved_vlan_type
comment|/* this field is not an absolute must, but the reseved was here */
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint8_t
name|local_addr_2
comment|/* Local Mac Address, used in PBF Header Builder Command */
decl_stmt|;
name|uint8_t
name|local_addr_3
comment|/* Local Mac Address, used in PBF Header Builder Command */
decl_stmt|;
name|uint8_t
name|local_addr_4
comment|/* Loca lMac Address, used in PBF Header Builder Command */
decl_stmt|;
name|uint8_t
name|local_addr_5
comment|/* Local Mac Address, used in PBF Header Builder Command */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint8_t
name|local_addr_5
comment|/* Local Mac Address, used in PBF Header Builder Command */
decl_stmt|;
name|uint8_t
name|local_addr_4
comment|/* Loca lMac Address, used in PBF Header Builder Command */
decl_stmt|;
name|uint8_t
name|local_addr_3
comment|/* Local Mac Address, used in PBF Header Builder Command */
decl_stmt|;
name|uint8_t
name|local_addr_2
comment|/* Local Mac Address, used in PBF Header Builder Command */
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/*  * Flags used in FCoE context section - 1 byte  */
end_comment

begin_struct
struct|struct
name|xstorm_fcoe_context_flags
block|{
name|uint8_t
name|flags
decl_stmt|;
define|#
directive|define
name|XSTORM_FCOE_CONTEXT_FLAGS_B_PROC_Q
value|(0x3<<0)
comment|/* BitField flags	The current queue in process */
define|#
directive|define
name|XSTORM_FCOE_CONTEXT_FLAGS_B_PROC_Q_SHIFT
value|0
define|#
directive|define
name|XSTORM_FCOE_CONTEXT_FLAGS_B_MID_SEQ
value|(0x1<<2)
comment|/* BitField flags	Middle of Sequence indication */
define|#
directive|define
name|XSTORM_FCOE_CONTEXT_FLAGS_B_MID_SEQ_SHIFT
value|2
define|#
directive|define
name|XSTORM_FCOE_CONTEXT_FLAGS_B_BLOCK_SQ
value|(0x1<<3)
comment|/* BitField flags	Indicates whether the SQ is blocked since we are in the middle of ABTS/Cleanup procedure */
define|#
directive|define
name|XSTORM_FCOE_CONTEXT_FLAGS_B_BLOCK_SQ_SHIFT
value|3
define|#
directive|define
name|XSTORM_FCOE_CONTEXT_FLAGS_B_REC_SUPPORT
value|(0x1<<4)
comment|/* BitField flags	REC support */
define|#
directive|define
name|XSTORM_FCOE_CONTEXT_FLAGS_B_REC_SUPPORT_SHIFT
value|4
define|#
directive|define
name|XSTORM_FCOE_CONTEXT_FLAGS_B_SQ_TOGGLE
value|(0x1<<5)
comment|/* BitField flags	SQ toggle bit */
define|#
directive|define
name|XSTORM_FCOE_CONTEXT_FLAGS_B_SQ_TOGGLE_SHIFT
value|5
define|#
directive|define
name|XSTORM_FCOE_CONTEXT_FLAGS_B_XFRQ_TOGGLE
value|(0x1<<6)
comment|/* BitField flags	XFRQ toggle bit */
define|#
directive|define
name|XSTORM_FCOE_CONTEXT_FLAGS_B_XFRQ_TOGGLE_SHIFT
value|6
define|#
directive|define
name|XSTORM_FCOE_CONTEXT_FLAGS_B_VNTAG_VLAN
value|(0x1<<7)
comment|/* BitField flags	Are we using VNTag inner vlan - in this case we have to read it on every VNTag version change */
define|#
directive|define
name|XSTORM_FCOE_CONTEXT_FLAGS_B_VNTAG_VLAN_SHIFT
value|7
block|}
struct|;
end_struct

begin_struct
struct|struct
name|xstorm_fcoe_tce
block|{
name|struct
name|fcoe_tce_tx_only
name|txwr
comment|/* TX processing shall be the only one to read/write to this section */
decl_stmt|;
name|struct
name|fcoe_tce_tx_wr_rx_rd
name|txwr_rxrd
comment|/* TX processing shall write and RX processing shall read from this section */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * FCP_DATA parameters required for transmission  */
end_comment

begin_struct
struct|struct
name|xstorm_fcoe_fcp_data
block|{
name|uint32_t
name|io_rem
comment|/* IO remainder */
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|cached_sge_off
decl_stmt|;
name|uint8_t
name|cached_num_sges
comment|/* Number of SGEs on context */
decl_stmt|;
name|uint8_t
name|cached_sge_idx
comment|/* 0xFF value indicated loading SGL */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint8_t
name|cached_sge_idx
comment|/* 0xFF value indicated loading SGL */
decl_stmt|;
name|uint8_t
name|cached_num_sges
comment|/* Number of SGEs on context */
decl_stmt|;
name|uint16_t
name|cached_sge_off
decl_stmt|;
endif|#
directive|endif
name|uint32_t
name|buf_addr_hi_0
comment|/* Higher buffer host address */
decl_stmt|;
name|uint32_t
name|buf_addr_lo_0
comment|/* Lower buffer host address */
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|num_of_pending_tasks
comment|/* Num of pending tasks */
decl_stmt|;
name|uint16_t
name|buf_len_0
comment|/* Buffer length (in bytes) */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|buf_len_0
comment|/* Buffer length (in bytes) */
decl_stmt|;
name|uint16_t
name|num_of_pending_tasks
comment|/* Num of pending tasks */
decl_stmt|;
endif|#
directive|endif
name|uint32_t
name|buf_addr_hi_1
comment|/* Higher buffer host address */
decl_stmt|;
name|uint32_t
name|buf_addr_lo_1
comment|/* Lower buffer host address */
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|task_pbe_idx_off
comment|/* Task pbe index offset */
decl_stmt|;
name|uint16_t
name|buf_len_1
comment|/* Buffer length (in bytes) */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|buf_len_1
comment|/* Buffer length (in bytes) */
decl_stmt|;
name|uint16_t
name|task_pbe_idx_off
comment|/* Task pbe index offset */
decl_stmt|;
endif|#
directive|endif
name|uint32_t
name|buf_addr_hi_2
comment|/* Higher buffer host address */
decl_stmt|;
name|uint32_t
name|buf_addr_lo_2
comment|/* Lower buffer host address */
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|ox_id
comment|/* OX_ID */
decl_stmt|;
name|uint16_t
name|buf_len_2
comment|/* Buffer length (in bytes) */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|buf_len_2
comment|/* Buffer length (in bytes) */
decl_stmt|;
name|uint16_t
name|ox_id
comment|/* OX_ID */
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/*  * Continuation of Flags used in FCoE context section - 1 byte  */
end_comment

begin_struct
struct|struct
name|xstorm_fcoe_context_flags_cont
block|{
name|uint8_t
name|flags
decl_stmt|;
define|#
directive|define
name|XSTORM_FCOE_CONTEXT_FLAGS_CONT_B_CONFQ_TOGGLE
value|(0x1<<0)
comment|/* BitField flags	CONFQ toggle bit */
define|#
directive|define
name|XSTORM_FCOE_CONTEXT_FLAGS_CONT_B_CONFQ_TOGGLE_SHIFT
value|0
define|#
directive|define
name|XSTORM_FCOE_CONTEXT_FLAGS_CONT_VLAN_FLAG
value|(0x1<<1)
comment|/* BitField flags	Is any inner vlan exist */
define|#
directive|define
name|XSTORM_FCOE_CONTEXT_FLAGS_CONT_VLAN_FLAG_SHIFT
value|1
define|#
directive|define
name|XSTORM_FCOE_CONTEXT_FLAGS_CONT_RESERVED
value|(0x3F<<2)
comment|/* BitField flags	 */
define|#
directive|define
name|XSTORM_FCOE_CONTEXT_FLAGS_CONT_RESERVED_SHIFT
value|2
block|}
struct|;
end_struct

begin_comment
comment|/*  * vlan configuration  */
end_comment

begin_struct
struct|struct
name|xstorm_fcoe_vlan_conf
block|{
name|uint8_t
name|vlan_conf
decl_stmt|;
define|#
directive|define
name|XSTORM_FCOE_VLAN_CONF_INNER_VLAN_PRIORITY
value|(0x7<<0)
comment|/* BitField vlan_conf	Original inner vlan priority */
define|#
directive|define
name|XSTORM_FCOE_VLAN_CONF_INNER_VLAN_PRIORITY_SHIFT
value|0
define|#
directive|define
name|XSTORM_FCOE_VLAN_CONF_INNER_VLAN_FLAG
value|(0x1<<3)
comment|/* BitField vlan_conf	Original inner vlan flag */
define|#
directive|define
name|XSTORM_FCOE_VLAN_CONF_INNER_VLAN_FLAG_SHIFT
value|3
define|#
directive|define
name|XSTORM_FCOE_VLAN_CONF_OUTER_VLAN_PRIORITY
value|(0x7<<4)
comment|/* BitField vlan_conf	Original outer vlan priority */
define|#
directive|define
name|XSTORM_FCOE_VLAN_CONF_OUTER_VLAN_PRIORITY_SHIFT
value|4
define|#
directive|define
name|XSTORM_FCOE_VLAN_CONF_RESERVED
value|(0x1<<7)
comment|/* BitField vlan_conf	 */
define|#
directive|define
name|XSTORM_FCOE_VLAN_CONF_RESERVED_SHIFT
value|7
block|}
struct|;
end_struct

begin_comment
comment|/*  * FCoE 16-bits vlan structure  */
end_comment

begin_struct
struct|struct
name|fcoe_vlan_fields
block|{
name|uint16_t
name|fields
decl_stmt|;
define|#
directive|define
name|FCOE_VLAN_FIELDS_VID
value|(0xFFF<<0)
comment|/* BitField fields	 */
define|#
directive|define
name|FCOE_VLAN_FIELDS_VID_SHIFT
value|0
define|#
directive|define
name|FCOE_VLAN_FIELDS_CLI
value|(0x1<<12)
comment|/* BitField fields	 */
define|#
directive|define
name|FCOE_VLAN_FIELDS_CLI_SHIFT
value|12
define|#
directive|define
name|FCOE_VLAN_FIELDS_PRI
value|(0x7<<13)
comment|/* BitField fields	 */
define|#
directive|define
name|FCOE_VLAN_FIELDS_PRI_SHIFT
value|13
block|}
struct|;
end_struct

begin_comment
comment|/*  * FCoE 16-bits vlan union  */
end_comment

begin_union
union|union
name|fcoe_vlan_field_union
block|{
name|struct
name|fcoe_vlan_fields
name|fields
comment|/* Parameters field */
decl_stmt|;
name|uint16_t
name|val
comment|/* Global value */
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/*  * FCoE 16-bits vlan, vif union  */
end_comment

begin_union
union|union
name|fcoe_vlan_vif_field_union
block|{
name|union
name|fcoe_vlan_field_union
name|vlan
comment|/* Vlan */
decl_stmt|;
name|uint16_t
name|vif
comment|/* VIF */
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/*  * FCoE context section  */
end_comment

begin_struct
struct|struct
name|xstorm_fcoe_context_section
block|{
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint8_t
name|cs_ctl
comment|/* cs ctl */
decl_stmt|;
name|uint8_t
name|s_id
index|[
literal|3
index|]
comment|/* Source ID, received during FLOGI */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint8_t
name|s_id
index|[
literal|3
index|]
comment|/* Source ID, received during FLOGI */
decl_stmt|;
name|uint8_t
name|cs_ctl
comment|/* cs ctl */
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint8_t
name|rctl
comment|/* rctl */
decl_stmt|;
name|uint8_t
name|d_id
index|[
literal|3
index|]
comment|/* Destination ID, received after inquiry of the fabric network */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint8_t
name|d_id
index|[
literal|3
index|]
comment|/* Destination ID, received after inquiry of the fabric network */
decl_stmt|;
name|uint8_t
name|rctl
comment|/* rctl */
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|sq_xfrq_lcq_confq_size
comment|/* SQ/XFRQ/LCQ/CONFQ size */
decl_stmt|;
name|uint16_t
name|tx_max_fc_pay_len
comment|/* The maximum acceptable FC payload size (Buffer-to-buffer Receive Data_Field size) supported by target, received during both FLOGI and PLOGI, minimum value should be taken */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|tx_max_fc_pay_len
comment|/* The maximum acceptable FC payload size (Buffer-to-buffer Receive Data_Field size) supported by target, received during both FLOGI and PLOGI, minimum value should be taken */
decl_stmt|;
name|uint16_t
name|sq_xfrq_lcq_confq_size
comment|/* SQ/XFRQ/LCQ/CONFQ size */
decl_stmt|;
endif|#
directive|endif
name|uint32_t
name|lcq_prod
comment|/* LCQ producer value */
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint8_t
name|port_id
comment|/* Port ID */
decl_stmt|;
name|uint8_t
name|func_id
comment|/* Function ID */
decl_stmt|;
name|uint8_t
name|seq_id
comment|/* SEQ ID counter to be used in transmitted FC header */
decl_stmt|;
name|struct
name|xstorm_fcoe_context_flags
name|tx_flags
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|struct
name|xstorm_fcoe_context_flags
name|tx_flags
decl_stmt|;
name|uint8_t
name|seq_id
comment|/* SEQ ID counter to be used in transmitted FC header */
decl_stmt|;
name|uint8_t
name|func_id
comment|/* Function ID */
decl_stmt|;
name|uint8_t
name|port_id
comment|/* Port ID */
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|mtu
comment|/* MTU */
decl_stmt|;
name|uint8_t
name|func_mode
comment|/* Function mode */
decl_stmt|;
name|uint8_t
name|vnic_id
comment|/* Vnic ID */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint8_t
name|vnic_id
comment|/* Vnic ID */
decl_stmt|;
name|uint8_t
name|func_mode
comment|/* Function mode */
decl_stmt|;
name|uint16_t
name|mtu
comment|/* MTU */
decl_stmt|;
endif|#
directive|endif
name|struct
name|regpair_t
name|confq_curr_page_addr
comment|/* The current page of CONFQ to be processed */
decl_stmt|;
name|struct
name|fcoe_cached_wqe
name|cached_wqe
index|[
literal|8
index|]
comment|/* Up to 8 SQ/XFRQ WQEs read in one shot */
decl_stmt|;
name|struct
name|regpair_t
name|lcq_base_addr
comment|/* The page address which the LCQ resides in host memory */
decl_stmt|;
name|struct
name|xstorm_fcoe_tce
name|tce
comment|/* TX section task context */
decl_stmt|;
name|struct
name|xstorm_fcoe_fcp_data
name|fcp_data
comment|/* The parameters required for FCP_DATA Sequences transmission */
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint8_t
name|tx_max_conc_seqs_c3
comment|/* Maximum concurrent Sequences for Class 3 supported by traget, received during PLOGI */
decl_stmt|;
name|struct
name|xstorm_fcoe_context_flags_cont
name|tx_flags_cont
decl_stmt|;
name|uint8_t
name|dcb_val
comment|/* DCB val - let us know if dcb info changes */
decl_stmt|;
name|uint8_t
name|data_pb_cmd_size
comment|/* Data pb cmd size */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint8_t
name|data_pb_cmd_size
comment|/* Data pb cmd size */
decl_stmt|;
name|uint8_t
name|dcb_val
comment|/* DCB val - let us know if dcb info changes */
decl_stmt|;
name|struct
name|xstorm_fcoe_context_flags_cont
name|tx_flags_cont
decl_stmt|;
name|uint8_t
name|tx_max_conc_seqs_c3
comment|/* Maximum concurrent Sequences for Class 3 supported by traget, received during PLOGI */
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|fcoe_tx_stat_params_ram_addr
comment|/* stat Ram Addr */
decl_stmt|;
name|uint16_t
name|fcoe_tx_fc_seq_ram_addr
comment|/* Tx FC sequence Ram Addr */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|fcoe_tx_fc_seq_ram_addr
comment|/* Tx FC sequence Ram Addr */
decl_stmt|;
name|uint16_t
name|fcoe_tx_stat_params_ram_addr
comment|/* stat Ram Addr */
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint8_t
name|fcp_cmd_line_credit
decl_stmt|;
name|uint8_t
name|eth_hdr_size
comment|/* Ethernet header size without eth type */
decl_stmt|;
name|uint16_t
name|pbf_addr
comment|/* PBF addr */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|pbf_addr
comment|/* PBF addr */
decl_stmt|;
name|uint8_t
name|eth_hdr_size
comment|/* Ethernet header size without eth type */
decl_stmt|;
name|uint8_t
name|fcp_cmd_line_credit
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|union
name|fcoe_vlan_vif_field_union
name|multi_func_val
comment|/* Outer vlan vif union */
decl_stmt|;
name|uint8_t
name|page_log_size
comment|/* Page log size */
decl_stmt|;
name|struct
name|xstorm_fcoe_vlan_conf
name|orig_vlan_conf
comment|/* original vlan configuration, used when we switch from dcb enable to dcb disabled */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|struct
name|xstorm_fcoe_vlan_conf
name|orig_vlan_conf
comment|/* original vlan configuration, used when we switch from dcb enable to dcb disabled */
decl_stmt|;
name|uint8_t
name|page_log_size
comment|/* Page log size */
decl_stmt|;
name|union
name|fcoe_vlan_vif_field_union
name|multi_func_val
comment|/* Outer vlan vif union */
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|fcp_cmd_frame_size
comment|/* FCP_CMD frame size */
decl_stmt|;
name|uint16_t
name|pbf_addr_ff
comment|/* PBF addr with ff */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|pbf_addr_ff
comment|/* PBF addr with ff */
decl_stmt|;
name|uint16_t
name|fcp_cmd_frame_size
comment|/* FCP_CMD frame size */
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint8_t
name|vlan_num
comment|/* Vlan number */
decl_stmt|;
name|uint8_t
name|cos
comment|/* Cos */
decl_stmt|;
name|uint8_t
name|cache_xfrq_cons
comment|/* Cache xferq consumer */
decl_stmt|;
name|uint8_t
name|cache_sq_cons
comment|/* Cache sq consumer */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint8_t
name|cache_sq_cons
comment|/* Cache sq consumer */
decl_stmt|;
name|uint8_t
name|cache_xfrq_cons
comment|/* Cache xferq consumer */
decl_stmt|;
name|uint8_t
name|cos
comment|/* Cos */
decl_stmt|;
name|uint8_t
name|vlan_num
comment|/* Vlan number */
decl_stmt|;
endif|#
directive|endif
name|uint32_t
name|verify_tx_seq
comment|/* Sequence number of last transmitted sequence in order to verify target did not send FCP_RSP before the actual transmission of PBF from the SGL */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Xstorm FCoE Storm Context  */
end_comment

begin_struct
struct|struct
name|xstorm_fcoe_st_context
block|{
name|struct
name|xstorm_fcoe_eth_context_section
name|eth
decl_stmt|;
name|struct
name|xstorm_fcoe_context_section
name|fcoe
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Fcoe connection context  */
end_comment

begin_struct
struct|struct
name|fcoe_context
block|{
name|struct
name|ustorm_fcoe_st_context
name|ustorm_st_context
comment|/* Ustorm storm context */
decl_stmt|;
name|struct
name|tstorm_fcoe_st_context
name|tstorm_st_context
comment|/* Tstorm storm context */
decl_stmt|;
name|struct
name|xstorm_fcoe_ag_context
name|xstorm_ag_context
comment|/* Xstorm aggregative context */
decl_stmt|;
name|struct
name|tstorm_fcoe_ag_context
name|tstorm_ag_context
comment|/* Tstorm aggregative context */
decl_stmt|;
name|struct
name|ustorm_fcoe_ag_context
name|ustorm_ag_context
comment|/* Ustorm aggregative context */
decl_stmt|;
name|struct
name|timers_block_context
name|timers_context
comment|/* Timers block context */
decl_stmt|;
name|struct
name|xstorm_fcoe_st_context
name|xstorm_st_context
comment|/* Xstorm storm context */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * FCoE init params passed by driver to FW in FCoE init ramrod $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|fcoe_init_ramrod_params
block|{
name|struct
name|fcoe_kwqe_init1
name|init_kwqe1
decl_stmt|;
name|struct
name|fcoe_kwqe_init2
name|init_kwqe2
decl_stmt|;
name|struct
name|fcoe_kwqe_init3
name|init_kwqe3
decl_stmt|;
name|struct
name|regpair_t
name|eq_pbl_base
comment|/* Physical address of PBL */
decl_stmt|;
name|uint32_t
name|eq_pbl_size
comment|/* PBL size */
decl_stmt|;
name|uint32_t
name|reserved2
decl_stmt|;
name|uint16_t
name|eq_prod
comment|/* EQ prdocuer */
decl_stmt|;
name|uint16_t
name|sb_num
comment|/* Status block number */
decl_stmt|;
name|uint8_t
name|sb_id
comment|/* Status block id (EQ consumer) */
decl_stmt|;
name|uint8_t
name|reserved0
decl_stmt|;
name|uint16_t
name|reserved1
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * FCoE statistics params buffer passed by driver to FW in FCoE statistics ramrod $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|fcoe_stat_ramrod_params
block|{
name|struct
name|fcoe_kwqe_stat
name|stat_kwqe
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * CQ DB CQ producer and pending completion counter  */
end_comment

begin_struct
struct|struct
name|iscsi_cq_db_prod_pnd_cmpltn_cnt
block|{
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|cntr
comment|/* CQ pending completion counter */
decl_stmt|;
name|uint16_t
name|prod
comment|/* Ustorm CQ producer , updated by Ustorm */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|prod
comment|/* Ustorm CQ producer , updated by Ustorm */
decl_stmt|;
name|uint16_t
name|cntr
comment|/* CQ pending completion counter */
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/*  * CQ DB pending completion ITT array  */
end_comment

begin_struct
struct|struct
name|iscsi_cq_db_prod_pnd_cmpltn_cnt_arr
block|{
name|struct
name|iscsi_cq_db_prod_pnd_cmpltn_cnt
name|prod_pend_comp
index|[
literal|8
index|]
comment|/* CQ pending completion ITT array */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * CQ DB pending completion ITT array  */
end_comment

begin_struct
struct|struct
name|iscsi_cq_db_pnd_comp_itt_arr
block|{
name|uint16_t
name|itt
index|[
literal|8
index|]
comment|/* CQ pending completion ITT array */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Cstorm CQ sequence to notify array, updated by driver  */
end_comment

begin_struct
struct|struct
name|iscsi_cq_db_sqn_2_notify_arr
block|{
name|uint16_t
name|sqn
index|[
literal|8
index|]
comment|/* Cstorm CQ sequence to notify array, updated by driver */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * CQ DB  */
end_comment

begin_struct
struct|struct
name|iscsi_cq_db
block|{
name|struct
name|iscsi_cq_db_prod_pnd_cmpltn_cnt_arr
name|cq_u_prod_pend_comp_ctr_arr
comment|/* Ustorm CQ producer and pending completion counter array, updated by Ustorm */
decl_stmt|;
name|struct
name|iscsi_cq_db_pnd_comp_itt_arr
name|cq_c_pend_comp_itt_arr
comment|/* Cstorm CQ pending completion ITT array, updated by Cstorm */
decl_stmt|;
name|struct
name|iscsi_cq_db_sqn_2_notify_arr
name|cq_drv_sqn_2_notify_arr
comment|/* Cstorm CQ sequence to notify array, updated by driver */
decl_stmt|;
name|uint32_t
name|reserved
index|[
literal|4
index|]
comment|/* 16 byte allignment */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * iSCSI KCQ CQE parameters  */
end_comment

begin_union
union|union
name|iscsi_kcqe_params
block|{
name|uint32_t
name|reserved0
index|[
literal|4
index|]
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/*  * iSCSI KCQ CQE  */
end_comment

begin_struct
struct|struct
name|iscsi_kcqe
block|{
name|uint32_t
name|iscsi_conn_id
comment|/* Drivers connection ID (only 16 bits are used) */
decl_stmt|;
name|uint32_t
name|completion_status
comment|/* 0=command completed successfully, 1=command failed */
decl_stmt|;
name|uint32_t
name|iscsi_conn_context_id
comment|/* Context ID of the iSCSI connection */
decl_stmt|;
name|union
name|iscsi_kcqe_params
name|params
comment|/* command-specific parameters */
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint8_t
name|flags
decl_stmt|;
define|#
directive|define
name|ISCSI_KCQE_RESERVED0
value|(0x7<<0)
comment|/* BitField flags	 */
define|#
directive|define
name|ISCSI_KCQE_RESERVED0_SHIFT
value|0
define|#
directive|define
name|ISCSI_KCQE_RAMROD_COMPLETION
value|(0x1<<3)
comment|/* BitField flags	Everest only - indicates whether this KCQE is a ramrod completion */
define|#
directive|define
name|ISCSI_KCQE_RAMROD_COMPLETION_SHIFT
value|3
define|#
directive|define
name|ISCSI_KCQE_LAYER_CODE
value|(0x7<<4)
comment|/* BitField flags	protocol layer (L2,L3,L4,L5,iSCSI) */
define|#
directive|define
name|ISCSI_KCQE_LAYER_CODE_SHIFT
value|4
define|#
directive|define
name|ISCSI_KCQE_LINKED_WITH_NEXT
value|(0x1<<7)
comment|/* BitField flags	Indicates whether this KCQE is linked with the next KCQE */
define|#
directive|define
name|ISCSI_KCQE_LINKED_WITH_NEXT_SHIFT
value|7
name|uint8_t
name|op_code
comment|/* iSCSI KCQ opcode */
decl_stmt|;
name|uint16_t
name|qe_self_seq
comment|/* Self identifying sequence number */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|qe_self_seq
comment|/* Self identifying sequence number */
decl_stmt|;
name|uint8_t
name|op_code
comment|/* iSCSI KCQ opcode */
decl_stmt|;
name|uint8_t
name|flags
decl_stmt|;
define|#
directive|define
name|ISCSI_KCQE_RESERVED0
value|(0x7<<0)
comment|/* BitField flags	 */
define|#
directive|define
name|ISCSI_KCQE_RESERVED0_SHIFT
value|0
define|#
directive|define
name|ISCSI_KCQE_RAMROD_COMPLETION
value|(0x1<<3)
comment|/* BitField flags	Everest only - indicates whether this KCQE is a ramrod completion */
define|#
directive|define
name|ISCSI_KCQE_RAMROD_COMPLETION_SHIFT
value|3
define|#
directive|define
name|ISCSI_KCQE_LAYER_CODE
value|(0x7<<4)
comment|/* BitField flags	protocol layer (L2,L3,L4,L5,iSCSI) */
define|#
directive|define
name|ISCSI_KCQE_LAYER_CODE_SHIFT
value|4
define|#
directive|define
name|ISCSI_KCQE_LINKED_WITH_NEXT
value|(0x1<<7)
comment|/* BitField flags	Indicates whether this KCQE is linked with the next KCQE */
define|#
directive|define
name|ISCSI_KCQE_LINKED_WITH_NEXT_SHIFT
value|7
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/*  * iSCSI KWQE header  */
end_comment

begin_struct
struct|struct
name|iscsi_kwqe_header
block|{
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint8_t
name|flags
decl_stmt|;
define|#
directive|define
name|ISCSI_KWQE_HEADER_RESERVED0
value|(0xF<<0)
comment|/* BitField flags	 */
define|#
directive|define
name|ISCSI_KWQE_HEADER_RESERVED0_SHIFT
value|0
define|#
directive|define
name|ISCSI_KWQE_HEADER_LAYER_CODE
value|(0x7<<4)
comment|/* BitField flags	protocol layer (L2,L3,L4,L5,iSCSI) */
define|#
directive|define
name|ISCSI_KWQE_HEADER_LAYER_CODE_SHIFT
value|4
define|#
directive|define
name|ISCSI_KWQE_HEADER_RESERVED1
value|(0x1<<7)
comment|/* BitField flags	 */
define|#
directive|define
name|ISCSI_KWQE_HEADER_RESERVED1_SHIFT
value|7
name|uint8_t
name|op_code
comment|/* iSCSI KWQE opcode */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint8_t
name|op_code
comment|/* iSCSI KWQE opcode */
decl_stmt|;
name|uint8_t
name|flags
decl_stmt|;
define|#
directive|define
name|ISCSI_KWQE_HEADER_RESERVED0
value|(0xF<<0)
comment|/* BitField flags	 */
define|#
directive|define
name|ISCSI_KWQE_HEADER_RESERVED0_SHIFT
value|0
define|#
directive|define
name|ISCSI_KWQE_HEADER_LAYER_CODE
value|(0x7<<4)
comment|/* BitField flags	protocol layer (L2,L3,L4,L5,iSCSI) */
define|#
directive|define
name|ISCSI_KWQE_HEADER_LAYER_CODE_SHIFT
value|4
define|#
directive|define
name|ISCSI_KWQE_HEADER_RESERVED1
value|(0x1<<7)
comment|/* BitField flags	 */
define|#
directive|define
name|ISCSI_KWQE_HEADER_RESERVED1_SHIFT
value|7
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/*  * iSCSI firmware init request 1  */
end_comment

begin_struct
struct|struct
name|iscsi_kwqe_init1
block|{
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|struct
name|iscsi_kwqe_header
name|hdr
comment|/* KWQ WQE header */
decl_stmt|;
name|uint8_t
name|hsi_version
comment|/* HSI version number */
decl_stmt|;
name|uint8_t
name|num_cqs
comment|/* Number of completion queues */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint8_t
name|num_cqs
comment|/* Number of completion queues */
decl_stmt|;
name|uint8_t
name|hsi_version
comment|/* HSI version number */
decl_stmt|;
name|struct
name|iscsi_kwqe_header
name|hdr
comment|/* KWQ WQE header */
decl_stmt|;
endif|#
directive|endif
name|uint32_t
name|dummy_buffer_addr_lo
comment|/* Lower 32-bit of dummy buffer - Teton only */
decl_stmt|;
name|uint32_t
name|dummy_buffer_addr_hi
comment|/* Higher 32-bit of dummy buffer - Teton only */
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|num_ccells_per_conn
comment|/* Number of ccells per connection */
decl_stmt|;
name|uint16_t
name|num_tasks_per_conn
comment|/* Number of tasks per connection */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|num_tasks_per_conn
comment|/* Number of tasks per connection */
decl_stmt|;
name|uint16_t
name|num_ccells_per_conn
comment|/* Number of ccells per connection */
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|sq_wqes_per_page
comment|/* Number of work entries in a single page of SQ */
decl_stmt|;
name|uint16_t
name|sq_num_wqes
comment|/* Number of entries in the Send Queue */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|sq_num_wqes
comment|/* Number of entries in the Send Queue */
decl_stmt|;
name|uint16_t
name|sq_wqes_per_page
comment|/* Number of work entries in a single page of SQ */
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint8_t
name|cq_log_wqes_per_page
comment|/* Log of number of work entries in a single page of CQ */
decl_stmt|;
name|uint8_t
name|flags
decl_stmt|;
define|#
directive|define
name|ISCSI_KWQE_INIT1_PAGE_SIZE
value|(0xF<<0)
comment|/* BitField flags	page size code */
define|#
directive|define
name|ISCSI_KWQE_INIT1_PAGE_SIZE_SHIFT
value|0
define|#
directive|define
name|ISCSI_KWQE_INIT1_DELAYED_ACK_ENABLE
value|(0x1<<4)
comment|/* BitField flags	if set, delayed ack is enabled */
define|#
directive|define
name|ISCSI_KWQE_INIT1_DELAYED_ACK_ENABLE_SHIFT
value|4
define|#
directive|define
name|ISCSI_KWQE_INIT1_KEEP_ALIVE_ENABLE
value|(0x1<<5)
comment|/* BitField flags	if set, keep alive is enabled */
define|#
directive|define
name|ISCSI_KWQE_INIT1_KEEP_ALIVE_ENABLE_SHIFT
value|5
define|#
directive|define
name|ISCSI_KWQE_INIT1_RESERVED1
value|(0x3<<6)
comment|/* BitField flags	 */
define|#
directive|define
name|ISCSI_KWQE_INIT1_RESERVED1_SHIFT
value|6
name|uint16_t
name|cq_num_wqes
comment|/* Number of entries in the Completion Queue */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|cq_num_wqes
comment|/* Number of entries in the Completion Queue */
decl_stmt|;
name|uint8_t
name|flags
decl_stmt|;
define|#
directive|define
name|ISCSI_KWQE_INIT1_PAGE_SIZE
value|(0xF<<0)
comment|/* BitField flags	page size code */
define|#
directive|define
name|ISCSI_KWQE_INIT1_PAGE_SIZE_SHIFT
value|0
define|#
directive|define
name|ISCSI_KWQE_INIT1_DELAYED_ACK_ENABLE
value|(0x1<<4)
comment|/* BitField flags	if set, delayed ack is enabled */
define|#
directive|define
name|ISCSI_KWQE_INIT1_DELAYED_ACK_ENABLE_SHIFT
value|4
define|#
directive|define
name|ISCSI_KWQE_INIT1_KEEP_ALIVE_ENABLE
value|(0x1<<5)
comment|/* BitField flags	if set, keep alive is enabled */
define|#
directive|define
name|ISCSI_KWQE_INIT1_KEEP_ALIVE_ENABLE_SHIFT
value|5
define|#
directive|define
name|ISCSI_KWQE_INIT1_RESERVED1
value|(0x3<<6)
comment|/* BitField flags	 */
define|#
directive|define
name|ISCSI_KWQE_INIT1_RESERVED1_SHIFT
value|6
name|uint8_t
name|cq_log_wqes_per_page
comment|/* Log of number of work entries in a single page of CQ */
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|cq_num_pages
comment|/* Number of pages in CQ page table */
decl_stmt|;
name|uint16_t
name|sq_num_pages
comment|/* Number of pages in SQ page table */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|sq_num_pages
comment|/* Number of pages in SQ page table */
decl_stmt|;
name|uint16_t
name|cq_num_pages
comment|/* Number of pages in CQ page table */
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|rq_buffer_size
comment|/* Size of a single buffer (entry) in the RQ */
decl_stmt|;
name|uint16_t
name|rq_num_wqes
comment|/* Number of entries in the Receive Queue */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|rq_num_wqes
comment|/* Number of entries in the Receive Queue */
decl_stmt|;
name|uint16_t
name|rq_buffer_size
comment|/* Size of a single buffer (entry) in the RQ */
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/*  * iSCSI firmware init request 2  */
end_comment

begin_struct
struct|struct
name|iscsi_kwqe_init2
block|{
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|struct
name|iscsi_kwqe_header
name|hdr
comment|/* KWQ WQE header */
decl_stmt|;
name|uint16_t
name|max_cq_sqn
comment|/* CQ wraparound value */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|max_cq_sqn
comment|/* CQ wraparound value */
decl_stmt|;
name|struct
name|iscsi_kwqe_header
name|hdr
comment|/* KWQ WQE header */
decl_stmt|;
endif|#
directive|endif
name|uint32_t
name|error_bit_map
index|[
literal|2
index|]
comment|/* bit per error type, 0=error, 1=warning */
decl_stmt|;
name|uint32_t
name|tcp_keepalive
comment|/* TCP keepalive time in seconds */
decl_stmt|;
name|uint32_t
name|reserved1
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Initial iSCSI connection offload request 1  */
end_comment

begin_struct
struct|struct
name|iscsi_kwqe_conn_offload1
block|{
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|struct
name|iscsi_kwqe_header
name|hdr
comment|/* KWQ WQE header */
decl_stmt|;
name|uint16_t
name|iscsi_conn_id
comment|/* Drivers connection ID. Should be sent in KCQEs to speed-up drivers access to connection data. */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|iscsi_conn_id
comment|/* Drivers connection ID. Should be sent in KCQEs to speed-up drivers access to connection data. */
decl_stmt|;
name|struct
name|iscsi_kwqe_header
name|hdr
comment|/* KWQ WQE header */
decl_stmt|;
endif|#
directive|endif
name|uint32_t
name|sq_page_table_addr_lo
comment|/* Lower 32-bit of the SQs page table address */
decl_stmt|;
name|uint32_t
name|sq_page_table_addr_hi
comment|/* Higher 32-bit of the SQs page table address */
decl_stmt|;
name|uint32_t
name|cq_page_table_addr_lo
comment|/* Lower 32-bit of the CQs page table address */
decl_stmt|;
name|uint32_t
name|cq_page_table_addr_hi
comment|/* Higher 32-bit of the CQs page table address */
decl_stmt|;
name|uint32_t
name|reserved0
index|[
literal|3
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * iSCSI Page Table Entry (PTE)  */
end_comment

begin_struct
struct|struct
name|iscsi_pte
block|{
name|uint32_t
name|hi
comment|/* Higher 32 bits of address */
decl_stmt|;
name|uint32_t
name|lo
comment|/* Lower 32 bits of address */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Initial iSCSI connection offload request 2  */
end_comment

begin_struct
struct|struct
name|iscsi_kwqe_conn_offload2
block|{
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|struct
name|iscsi_kwqe_header
name|hdr
comment|/* KWQE header */
decl_stmt|;
name|uint16_t
name|reserved0
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|reserved0
decl_stmt|;
name|struct
name|iscsi_kwqe_header
name|hdr
comment|/* KWQE header */
decl_stmt|;
endif|#
directive|endif
name|uint32_t
name|rq_page_table_addr_lo
comment|/* Lower 32-bits of the RQs page table address */
decl_stmt|;
name|uint32_t
name|rq_page_table_addr_hi
comment|/* Higher 32-bits of the RQs page table address */
decl_stmt|;
name|struct
name|iscsi_pte
name|sq_first_pte
comment|/* first SQ page table entry (for FW caching) */
decl_stmt|;
name|struct
name|iscsi_pte
name|cq_first_pte
comment|/* first CQ page table entry (for FW caching) */
decl_stmt|;
name|uint32_t
name|num_additional_wqes
comment|/* Everest specific - number of offload3 KWQEs that will follow this KWQE */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Everest specific - Initial iSCSI connection offload request 3  */
end_comment

begin_struct
struct|struct
name|iscsi_kwqe_conn_offload3
block|{
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|struct
name|iscsi_kwqe_header
name|hdr
comment|/* KWQE header */
decl_stmt|;
name|uint16_t
name|reserved0
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|reserved0
decl_stmt|;
name|struct
name|iscsi_kwqe_header
name|hdr
comment|/* KWQE header */
decl_stmt|;
endif|#
directive|endif
name|uint32_t
name|reserved1
decl_stmt|;
name|struct
name|iscsi_pte
name|qp_first_pte
index|[
literal|3
index|]
comment|/* first page table entry of some iSCSI ring (for FW caching) */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * iSCSI connection update request  */
end_comment

begin_struct
struct|struct
name|iscsi_kwqe_conn_update
block|{
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|struct
name|iscsi_kwqe_header
name|hdr
comment|/* KWQE header */
decl_stmt|;
name|uint16_t
name|reserved0
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|reserved0
decl_stmt|;
name|struct
name|iscsi_kwqe_header
name|hdr
comment|/* KWQE header */
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint8_t
name|session_error_recovery_level
comment|/* iSCSI Error Recovery Level negotiated on this connection */
decl_stmt|;
name|uint8_t
name|max_outstanding_r2ts
comment|/* Maximum number of outstanding R2ts that a target can send for a command */
decl_stmt|;
name|uint8_t
name|reserved2
decl_stmt|;
name|uint8_t
name|conn_flags
decl_stmt|;
define|#
directive|define
name|ISCSI_KWQE_CONN_UPDATE_HEADER_DIGEST
value|(0x1<<0)
comment|/* BitField conn_flags	0=off, 1=on */
define|#
directive|define
name|ISCSI_KWQE_CONN_UPDATE_HEADER_DIGEST_SHIFT
value|0
define|#
directive|define
name|ISCSI_KWQE_CONN_UPDATE_DATA_DIGEST
value|(0x1<<1)
comment|/* BitField conn_flags	0=off, 1=on */
define|#
directive|define
name|ISCSI_KWQE_CONN_UPDATE_DATA_DIGEST_SHIFT
value|1
define|#
directive|define
name|ISCSI_KWQE_CONN_UPDATE_INITIAL_R2T
value|(0x1<<2)
comment|/* BitField conn_flags	0=no, 1=yes */
define|#
directive|define
name|ISCSI_KWQE_CONN_UPDATE_INITIAL_R2T_SHIFT
value|2
define|#
directive|define
name|ISCSI_KWQE_CONN_UPDATE_IMMEDIATE_DATA
value|(0x1<<3)
comment|/* BitField conn_flags	0=no, 1=yes */
define|#
directive|define
name|ISCSI_KWQE_CONN_UPDATE_IMMEDIATE_DATA_SHIFT
value|3
define|#
directive|define
name|ISCSI_KWQE_CONN_UPDATE_OOO_SUPPORT_MODE
value|(0x3<<4)
comment|/* BitField conn_flags	 (use enum tcp_tstorm_ooo) */
define|#
directive|define
name|ISCSI_KWQE_CONN_UPDATE_OOO_SUPPORT_MODE_SHIFT
value|4
define|#
directive|define
name|ISCSI_KWQE_CONN_UPDATE_RESERVED1
value|(0x3<<6)
comment|/* BitField conn_flags	 */
define|#
directive|define
name|ISCSI_KWQE_CONN_UPDATE_RESERVED1_SHIFT
value|6
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint8_t
name|conn_flags
decl_stmt|;
define|#
directive|define
name|ISCSI_KWQE_CONN_UPDATE_HEADER_DIGEST
value|(0x1<<0)
comment|/* BitField conn_flags	0=off, 1=on */
define|#
directive|define
name|ISCSI_KWQE_CONN_UPDATE_HEADER_DIGEST_SHIFT
value|0
define|#
directive|define
name|ISCSI_KWQE_CONN_UPDATE_DATA_DIGEST
value|(0x1<<1)
comment|/* BitField conn_flags	0=off, 1=on */
define|#
directive|define
name|ISCSI_KWQE_CONN_UPDATE_DATA_DIGEST_SHIFT
value|1
define|#
directive|define
name|ISCSI_KWQE_CONN_UPDATE_INITIAL_R2T
value|(0x1<<2)
comment|/* BitField conn_flags	0=no, 1=yes */
define|#
directive|define
name|ISCSI_KWQE_CONN_UPDATE_INITIAL_R2T_SHIFT
value|2
define|#
directive|define
name|ISCSI_KWQE_CONN_UPDATE_IMMEDIATE_DATA
value|(0x1<<3)
comment|/* BitField conn_flags	0=no, 1=yes */
define|#
directive|define
name|ISCSI_KWQE_CONN_UPDATE_IMMEDIATE_DATA_SHIFT
value|3
define|#
directive|define
name|ISCSI_KWQE_CONN_UPDATE_OOO_SUPPORT_MODE
value|(0x3<<4)
comment|/* BitField conn_flags	 (use enum tcp_tstorm_ooo) */
define|#
directive|define
name|ISCSI_KWQE_CONN_UPDATE_OOO_SUPPORT_MODE_SHIFT
value|4
define|#
directive|define
name|ISCSI_KWQE_CONN_UPDATE_RESERVED1
value|(0x3<<6)
comment|/* BitField conn_flags	 */
define|#
directive|define
name|ISCSI_KWQE_CONN_UPDATE_RESERVED1_SHIFT
value|6
name|uint8_t
name|reserved2
decl_stmt|;
name|uint8_t
name|max_outstanding_r2ts
comment|/* Maximum number of outstanding R2ts that a target can send for a command */
decl_stmt|;
name|uint8_t
name|session_error_recovery_level
comment|/* iSCSI Error Recovery Level negotiated on this connection */
decl_stmt|;
endif|#
directive|endif
name|uint32_t
name|context_id
comment|/* Context ID of the iSCSI connection */
decl_stmt|;
name|uint32_t
name|max_send_pdu_length
comment|/* Maximum length of a PDU that the target can receive */
decl_stmt|;
name|uint32_t
name|max_recv_pdu_length
comment|/* Maximum length of a PDU that the Initiator can receive */
decl_stmt|;
name|uint32_t
name|first_burst_length
comment|/* Maximum length of the immediate and unsolicited data that Initiator can send */
decl_stmt|;
name|uint32_t
name|max_burst_length
comment|/* Maximum length of the data that Initiator and target can send in one burst */
decl_stmt|;
name|uint32_t
name|exp_stat_sn
comment|/* Expected Status Serial Number */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * iSCSI destroy connection request  */
end_comment

begin_struct
struct|struct
name|iscsi_kwqe_conn_destroy
block|{
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|struct
name|iscsi_kwqe_header
name|hdr
comment|/* KWQ WQE header */
decl_stmt|;
name|uint16_t
name|iscsi_conn_id
comment|/* Drivers connection ID. Should be sent in KCQEs to speed-up drivers access to connection data. */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|iscsi_conn_id
comment|/* Drivers connection ID. Should be sent in KCQEs to speed-up drivers access to connection data. */
decl_stmt|;
name|struct
name|iscsi_kwqe_header
name|hdr
comment|/* KWQ WQE header */
decl_stmt|;
endif|#
directive|endif
name|uint32_t
name|context_id
comment|/* Context ID of the iSCSI connection */
decl_stmt|;
name|uint32_t
name|reserved1
index|[
literal|6
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * iSCSI KWQ WQE  */
end_comment

begin_union
union|union
name|iscsi_kwqe
block|{
name|struct
name|iscsi_kwqe_init1
name|init1
decl_stmt|;
name|struct
name|iscsi_kwqe_init2
name|init2
decl_stmt|;
name|struct
name|iscsi_kwqe_conn_offload1
name|conn_offload1
decl_stmt|;
name|struct
name|iscsi_kwqe_conn_offload2
name|conn_offload2
decl_stmt|;
name|struct
name|iscsi_kwqe_conn_offload3
name|conn_offload3
decl_stmt|;
name|struct
name|iscsi_kwqe_conn_update
name|conn_update
decl_stmt|;
name|struct
name|iscsi_kwqe_conn_destroy
name|conn_destroy
decl_stmt|;
block|}
union|;
end_union

begin_struct
struct|struct
name|iscsi_rq_db
block|{
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|reserved1
decl_stmt|;
name|uint16_t
name|rq_prod
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|rq_prod
decl_stmt|;
name|uint16_t
name|reserved1
decl_stmt|;
endif|#
directive|endif
name|uint32_t
name|__fw_hdr
index|[
literal|15
index|]
comment|/* Used by FW for partial header placement */
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|iscsi_sq_db
block|{
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|reserved0
comment|/* Pad structure size to 16 bytes */
decl_stmt|;
name|uint16_t
name|sq_prod
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|sq_prod
decl_stmt|;
name|uint16_t
name|reserved0
comment|/* Pad structure size to 16 bytes */
decl_stmt|;
endif|#
directive|endif
name|uint32_t
name|reserved1
index|[
literal|3
index|]
comment|/* Pad structure size to 16 bytes */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Tstorm Tcp flags  */
end_comment

begin_struct
struct|struct
name|tstorm_l5cm_tcp_flags
block|{
name|uint16_t
name|flags
decl_stmt|;
define|#
directive|define
name|TSTORM_L5CM_TCP_FLAGS_VLAN_ID
value|(0xFFF<<0)
comment|/* BitField flags	 */
define|#
directive|define
name|TSTORM_L5CM_TCP_FLAGS_VLAN_ID_SHIFT
value|0
define|#
directive|define
name|TSTORM_L5CM_TCP_FLAGS_DELAYED_ACK_EN
value|(0x1<<12)
comment|/* BitField flags	 */
define|#
directive|define
name|TSTORM_L5CM_TCP_FLAGS_DELAYED_ACK_EN_SHIFT
value|12
define|#
directive|define
name|TSTORM_L5CM_TCP_FLAGS_TS_ENABLED
value|(0x1<<13)
comment|/* BitField flags	 */
define|#
directive|define
name|TSTORM_L5CM_TCP_FLAGS_TS_ENABLED_SHIFT
value|13
define|#
directive|define
name|TSTORM_L5CM_TCP_FLAGS_RSRV1
value|(0x3<<14)
comment|/* BitField flags	 */
define|#
directive|define
name|TSTORM_L5CM_TCP_FLAGS_RSRV1_SHIFT
value|14
block|}
struct|;
end_struct

begin_comment
comment|/*  * Cstorm iSCSI Storm Context  */
end_comment

begin_struct
struct|struct
name|cstorm_iscsi_st_context
block|{
name|struct
name|iscsi_cq_db_prod_pnd_cmpltn_cnt_arr
name|cq_c_prod_pend_comp_ctr_arr
comment|/* Cstorm CQ producer and CQ pending completion array, updated by Cstorm */
decl_stmt|;
name|struct
name|iscsi_cq_db_sqn_2_notify_arr
name|cq_c_prod_sqn_arr
comment|/* Cstorm CQ producer sequence, updated by Cstorm */
decl_stmt|;
name|struct
name|iscsi_cq_db_sqn_2_notify_arr
name|cq_c_sqn_2_notify_arr
comment|/* Event Coalescing CQ sequence to notify driver, copied by Cstorm from CQ DB that is updated by Driver */
decl_stmt|;
name|struct
name|regpair_t
name|hq_pbl_base
comment|/* HQ PBL base */
decl_stmt|;
name|struct
name|regpair_t
name|hq_curr_pbe
comment|/* HQ current PBE */
decl_stmt|;
name|struct
name|regpair_t
name|task_pbl_base
comment|/* Task Context Entry PBL base */
decl_stmt|;
name|struct
name|regpair_t
name|cq_db_base
comment|/* pointer to CQ DB array. each CQ DB entry consists of CQ PBL, arm bit and idx to notify */
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|hq_bd_itt
comment|/* copied from HQ BD */
decl_stmt|;
name|uint16_t
name|iscsi_conn_id
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|iscsi_conn_id
decl_stmt|;
name|uint16_t
name|hq_bd_itt
comment|/* copied from HQ BD */
decl_stmt|;
endif|#
directive|endif
name|uint32_t
name|hq_bd_data_segment_len
comment|/* copied from HQ BD */
decl_stmt|;
name|uint32_t
name|hq_bd_buffer_offset
comment|/* copied from HQ BD */
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint8_t
name|rsrv
decl_stmt|;
name|uint8_t
name|cq_proc_en_bit_map
comment|/* CQ processing enable bit map, 1 bit per CQ */
decl_stmt|;
name|uint8_t
name|cq_pend_comp_itt_valid_bit_map
comment|/* CQ pending completion ITT valid bit map, 1 bit per CQ */
decl_stmt|;
name|uint8_t
name|hq_bd_opcode
comment|/* copied from HQ BD */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint8_t
name|hq_bd_opcode
comment|/* copied from HQ BD */
decl_stmt|;
name|uint8_t
name|cq_pend_comp_itt_valid_bit_map
comment|/* CQ pending completion ITT valid bit map, 1 bit per CQ */
decl_stmt|;
name|uint8_t
name|cq_proc_en_bit_map
comment|/* CQ processing enable bit map, 1 bit per CQ */
decl_stmt|;
name|uint8_t
name|rsrv
decl_stmt|;
endif|#
directive|endif
name|uint32_t
name|hq_tcp_seq
comment|/* TCP sequence of next BD to release */
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|flags
decl_stmt|;
define|#
directive|define
name|CSTORM_ISCSI_ST_CONTEXT_DATA_DIGEST_EN
value|(0x1<<0)
comment|/* BitField flags	 */
define|#
directive|define
name|CSTORM_ISCSI_ST_CONTEXT_DATA_DIGEST_EN_SHIFT
value|0
define|#
directive|define
name|CSTORM_ISCSI_ST_CONTEXT_HDR_DIGEST_EN
value|(0x1<<1)
comment|/* BitField flags	 */
define|#
directive|define
name|CSTORM_ISCSI_ST_CONTEXT_HDR_DIGEST_EN_SHIFT
value|1
define|#
directive|define
name|CSTORM_ISCSI_ST_CONTEXT_HQ_BD_CTXT_VALID
value|(0x1<<2)
comment|/* BitField flags	copied from HQ BD */
define|#
directive|define
name|CSTORM_ISCSI_ST_CONTEXT_HQ_BD_CTXT_VALID_SHIFT
value|2
define|#
directive|define
name|CSTORM_ISCSI_ST_CONTEXT_HQ_BD_LCL_CMPLN_FLG
value|(0x1<<3)
comment|/* BitField flags	copied from HQ BD */
define|#
directive|define
name|CSTORM_ISCSI_ST_CONTEXT_HQ_BD_LCL_CMPLN_FLG_SHIFT
value|3
define|#
directive|define
name|CSTORM_ISCSI_ST_CONTEXT_HQ_BD_WRITE_TASK
value|(0x1<<4)
comment|/* BitField flags	calculated using HQ BD opcode and write flag */
define|#
directive|define
name|CSTORM_ISCSI_ST_CONTEXT_HQ_BD_WRITE_TASK_SHIFT
value|4
define|#
directive|define
name|CSTORM_ISCSI_ST_CONTEXT_CTRL_FLAGS_RSRV
value|(0x7FF<<5)
comment|/* BitField flags	 */
define|#
directive|define
name|CSTORM_ISCSI_ST_CONTEXT_CTRL_FLAGS_RSRV_SHIFT
value|5
name|uint16_t
name|hq_cons
comment|/* HQ consumer */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|hq_cons
comment|/* HQ consumer */
decl_stmt|;
name|uint16_t
name|flags
decl_stmt|;
define|#
directive|define
name|CSTORM_ISCSI_ST_CONTEXT_DATA_DIGEST_EN
value|(0x1<<0)
comment|/* BitField flags	 */
define|#
directive|define
name|CSTORM_ISCSI_ST_CONTEXT_DATA_DIGEST_EN_SHIFT
value|0
define|#
directive|define
name|CSTORM_ISCSI_ST_CONTEXT_HDR_DIGEST_EN
value|(0x1<<1)
comment|/* BitField flags	 */
define|#
directive|define
name|CSTORM_ISCSI_ST_CONTEXT_HDR_DIGEST_EN_SHIFT
value|1
define|#
directive|define
name|CSTORM_ISCSI_ST_CONTEXT_HQ_BD_CTXT_VALID
value|(0x1<<2)
comment|/* BitField flags	copied from HQ BD */
define|#
directive|define
name|CSTORM_ISCSI_ST_CONTEXT_HQ_BD_CTXT_VALID_SHIFT
value|2
define|#
directive|define
name|CSTORM_ISCSI_ST_CONTEXT_HQ_BD_LCL_CMPLN_FLG
value|(0x1<<3)
comment|/* BitField flags	copied from HQ BD */
define|#
directive|define
name|CSTORM_ISCSI_ST_CONTEXT_HQ_BD_LCL_CMPLN_FLG_SHIFT
value|3
define|#
directive|define
name|CSTORM_ISCSI_ST_CONTEXT_HQ_BD_WRITE_TASK
value|(0x1<<4)
comment|/* BitField flags	calculated using HQ BD opcode and write flag */
define|#
directive|define
name|CSTORM_ISCSI_ST_CONTEXT_HQ_BD_WRITE_TASK_SHIFT
value|4
define|#
directive|define
name|CSTORM_ISCSI_ST_CONTEXT_CTRL_FLAGS_RSRV
value|(0x7FF<<5)
comment|/* BitField flags	 */
define|#
directive|define
name|CSTORM_ISCSI_ST_CONTEXT_CTRL_FLAGS_RSRV_SHIFT
value|5
endif|#
directive|endif
name|struct
name|regpair_t
name|rsrv1
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * SCSI read/write SQ WQE  */
end_comment

begin_struct
struct|struct
name|iscsi_cmd_pdu_hdr_little_endian
block|{
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint8_t
name|opcode
decl_stmt|;
name|uint8_t
name|op_attr
decl_stmt|;
define|#
directive|define
name|ISCSI_CMD_PDU_HDR_LITTLE_ENDIAN_ATTRIBUTES
value|(0x7<<0)
comment|/* BitField op_attr	Attributes of the SCSI command. To be sent with the outgoing command PDU. */
define|#
directive|define
name|ISCSI_CMD_PDU_HDR_LITTLE_ENDIAN_ATTRIBUTES_SHIFT
value|0
define|#
directive|define
name|ISCSI_CMD_PDU_HDR_LITTLE_ENDIAN_RSRV1
value|(0x3<<3)
comment|/* BitField op_attr	 */
define|#
directive|define
name|ISCSI_CMD_PDU_HDR_LITTLE_ENDIAN_RSRV1_SHIFT
value|3
define|#
directive|define
name|ISCSI_CMD_PDU_HDR_LITTLE_ENDIAN_WRITE_FLAG
value|(0x1<<5)
comment|/* BitField op_attr	Write bit. Initiator is expected to send the data to the target */
define|#
directive|define
name|ISCSI_CMD_PDU_HDR_LITTLE_ENDIAN_WRITE_FLAG_SHIFT
value|5
define|#
directive|define
name|ISCSI_CMD_PDU_HDR_LITTLE_ENDIAN_READ_FLAG
value|(0x1<<6)
comment|/* BitField op_attr	Read bit. Data from target is expected */
define|#
directive|define
name|ISCSI_CMD_PDU_HDR_LITTLE_ENDIAN_READ_FLAG_SHIFT
value|6
define|#
directive|define
name|ISCSI_CMD_PDU_HDR_LITTLE_ENDIAN_FINAL_FLAG
value|(0x1<<7)
comment|/* BitField op_attr	Final bit. Firmware can change this bit based on the command before putting it into the outgoing PDU. */
define|#
directive|define
name|ISCSI_CMD_PDU_HDR_LITTLE_ENDIAN_FINAL_FLAG_SHIFT
value|7
name|uint16_t
name|rsrv0
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|rsrv0
decl_stmt|;
name|uint8_t
name|op_attr
decl_stmt|;
define|#
directive|define
name|ISCSI_CMD_PDU_HDR_LITTLE_ENDIAN_ATTRIBUTES
value|(0x7<<0)
comment|/* BitField op_attr	Attributes of the SCSI command. To be sent with the outgoing command PDU. */
define|#
directive|define
name|ISCSI_CMD_PDU_HDR_LITTLE_ENDIAN_ATTRIBUTES_SHIFT
value|0
define|#
directive|define
name|ISCSI_CMD_PDU_HDR_LITTLE_ENDIAN_RSRV1
value|(0x3<<3)
comment|/* BitField op_attr	 */
define|#
directive|define
name|ISCSI_CMD_PDU_HDR_LITTLE_ENDIAN_RSRV1_SHIFT
value|3
define|#
directive|define
name|ISCSI_CMD_PDU_HDR_LITTLE_ENDIAN_WRITE_FLAG
value|(0x1<<5)
comment|/* BitField op_attr	Write bit. Initiator is expected to send the data to the target */
define|#
directive|define
name|ISCSI_CMD_PDU_HDR_LITTLE_ENDIAN_WRITE_FLAG_SHIFT
value|5
define|#
directive|define
name|ISCSI_CMD_PDU_HDR_LITTLE_ENDIAN_READ_FLAG
value|(0x1<<6)
comment|/* BitField op_attr	Read bit. Data from target is expected */
define|#
directive|define
name|ISCSI_CMD_PDU_HDR_LITTLE_ENDIAN_READ_FLAG_SHIFT
value|6
define|#
directive|define
name|ISCSI_CMD_PDU_HDR_LITTLE_ENDIAN_FINAL_FLAG
value|(0x1<<7)
comment|/* BitField op_attr	Final bit. Firmware can change this bit based on the command before putting it into the outgoing PDU. */
define|#
directive|define
name|ISCSI_CMD_PDU_HDR_LITTLE_ENDIAN_FINAL_FLAG_SHIFT
value|7
name|uint8_t
name|opcode
decl_stmt|;
endif|#
directive|endif
name|uint32_t
name|data_fields
decl_stmt|;
define|#
directive|define
name|ISCSI_CMD_PDU_HDR_LITTLE_ENDIAN_DATA_SEGMENT_LENGTH
value|(0xFFFFFF<<0)
comment|/* BitField data_fields	 */
define|#
directive|define
name|ISCSI_CMD_PDU_HDR_LITTLE_ENDIAN_DATA_SEGMENT_LENGTH_SHIFT
value|0
define|#
directive|define
name|ISCSI_CMD_PDU_HDR_LITTLE_ENDIAN_TOTAL_AHS_LENGTH
value|(0xFF<<24)
comment|/* BitField data_fields	 */
define|#
directive|define
name|ISCSI_CMD_PDU_HDR_LITTLE_ENDIAN_TOTAL_AHS_LENGTH_SHIFT
value|24
name|struct
name|regpair_t
name|lun
decl_stmt|;
name|uint32_t
name|itt
decl_stmt|;
name|uint32_t
name|expected_data_transfer_length
decl_stmt|;
name|uint32_t
name|cmd_sn
decl_stmt|;
name|uint32_t
name|exp_stat_sn
decl_stmt|;
name|uint32_t
name|scsi_command_block
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Buffer per connection, used in Tstorm  */
end_comment

begin_struct
struct|struct
name|iscsi_conn_buf
block|{
name|struct
name|regpair_t
name|reserved
index|[
literal|8
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * iSCSI context region, used only in iSCSI  */
end_comment

begin_struct
struct|struct
name|ustorm_iscsi_rq_db
block|{
name|struct
name|regpair_t
name|pbl_base
comment|/* Pointer to the rq page base list. */
decl_stmt|;
name|struct
name|regpair_t
name|curr_pbe
comment|/* Pointer to the current rq page base. */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * iSCSI context region, used only in iSCSI  */
end_comment

begin_struct
struct|struct
name|ustorm_iscsi_r2tq_db
block|{
name|struct
name|regpair_t
name|pbl_base
comment|/* Pointer to the r2tq page base list. */
decl_stmt|;
name|struct
name|regpair_t
name|curr_pbe
comment|/* Pointer to the current r2tq page base. */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * iSCSI context region, used only in iSCSI  */
end_comment

begin_struct
struct|struct
name|ustorm_iscsi_cq_db
block|{
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|cq_sn
comment|/* CQ serial number */
decl_stmt|;
name|uint16_t
name|prod
comment|/* CQ producer */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|prod
comment|/* CQ producer */
decl_stmt|;
name|uint16_t
name|cq_sn
comment|/* CQ serial number */
decl_stmt|;
endif|#
directive|endif
name|struct
name|regpair_t
name|curr_pbe
comment|/* Pointer to the current cq page base. */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * iSCSI context region, used only in iSCSI  */
end_comment

begin_struct
struct|struct
name|rings_db
block|{
name|struct
name|ustorm_iscsi_rq_db
name|rq
comment|/* RQ db. */
decl_stmt|;
name|struct
name|ustorm_iscsi_r2tq_db
name|r2tq
comment|/* R2TQ db. */
decl_stmt|;
name|struct
name|ustorm_iscsi_cq_db
name|cq
index|[
literal|8
index|]
comment|/* CQ db. */
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|rq_prod
comment|/* RQ prod */
decl_stmt|;
name|uint16_t
name|r2tq_prod
comment|/* R2TQ producer. */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|r2tq_prod
comment|/* R2TQ producer. */
decl_stmt|;
name|uint16_t
name|rq_prod
comment|/* RQ prod */
decl_stmt|;
endif|#
directive|endif
name|struct
name|regpair_t
name|cq_pbl_base
comment|/* Pointer to the cq page base list. */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * iSCSI context region, used only in iSCSI  */
end_comment

begin_struct
struct|struct
name|ustorm_iscsi_placement_db
block|{
name|uint32_t
name|sgl_base_lo
comment|/* SGL base address lo */
decl_stmt|;
name|uint32_t
name|sgl_base_hi
comment|/* SGL base address hi */
decl_stmt|;
name|uint32_t
name|local_sge_0_address_hi
comment|/* SGE address hi */
decl_stmt|;
name|uint32_t
name|local_sge_0_address_lo
comment|/* SGE address lo */
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|curr_sge_offset
comment|/* Current offset in the SGE */
decl_stmt|;
name|uint16_t
name|local_sge_0_size
comment|/* SGE size */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|local_sge_0_size
comment|/* SGE size */
decl_stmt|;
name|uint16_t
name|curr_sge_offset
comment|/* Current offset in the SGE */
decl_stmt|;
endif|#
directive|endif
name|uint32_t
name|local_sge_1_address_hi
comment|/* SGE address hi */
decl_stmt|;
name|uint32_t
name|local_sge_1_address_lo
comment|/* SGE address lo */
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint8_t
name|exp_padding_2b
comment|/* Number of padding bytes not yet processed */
decl_stmt|;
name|uint8_t
name|nal_len_3b
comment|/* Non 4 byte aligned bytes in the previous iteration */
decl_stmt|;
name|uint16_t
name|local_sge_1_size
comment|/* SGE size */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|local_sge_1_size
comment|/* SGE size */
decl_stmt|;
name|uint8_t
name|nal_len_3b
comment|/* Non 4 byte aligned bytes in the previous iteration */
decl_stmt|;
name|uint8_t
name|exp_padding_2b
comment|/* Number of padding bytes not yet processed */
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint8_t
name|sgl_size
comment|/* Number of SGEs remaining till end of SGL */
decl_stmt|;
name|uint8_t
name|local_sge_index_2b
comment|/* Index to the local SGE currently used */
decl_stmt|;
name|uint16_t
name|reserved7
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|reserved7
decl_stmt|;
name|uint8_t
name|local_sge_index_2b
comment|/* Index to the local SGE currently used */
decl_stmt|;
name|uint8_t
name|sgl_size
comment|/* Number of SGEs remaining till end of SGL */
decl_stmt|;
endif|#
directive|endif
name|uint32_t
name|rem_pdu
comment|/* Number of bytes remaining in PDU */
decl_stmt|;
name|uint32_t
name|place_db_bitfield_1
decl_stmt|;
define|#
directive|define
name|USTORM_ISCSI_PLACEMENT_DB_REM_PDU_PAYLOAD
value|(0xFFFFFF<<0)
comment|/* BitField place_db_bitfield_1place_db_bitfield_1	Number of bytes remaining in PDU payload */
define|#
directive|define
name|USTORM_ISCSI_PLACEMENT_DB_REM_PDU_PAYLOAD_SHIFT
value|0
define|#
directive|define
name|USTORM_ISCSI_PLACEMENT_DB_CQ_ID
value|(0xFF<<24)
comment|/* BitField place_db_bitfield_1place_db_bitfield_1	Temp task context - determines the CQ index for CQE placement */
define|#
directive|define
name|USTORM_ISCSI_PLACEMENT_DB_CQ_ID_SHIFT
value|24
name|uint32_t
name|place_db_bitfield_2
decl_stmt|;
define|#
directive|define
name|USTORM_ISCSI_PLACEMENT_DB_BYTES_2_TRUNCATE
value|(0xFFFFFF<<0)
comment|/* BitField place_db_bitfield_2place_db_bitfield_2	Bytes to truncate from the payload. */
define|#
directive|define
name|USTORM_ISCSI_PLACEMENT_DB_BYTES_2_TRUNCATE_SHIFT
value|0
define|#
directive|define
name|USTORM_ISCSI_PLACEMENT_DB_HOST_SGE_INDEX
value|(0xFF<<24)
comment|/* BitField place_db_bitfield_2place_db_bitfield_2	Sge index on host */
define|#
directive|define
name|USTORM_ISCSI_PLACEMENT_DB_HOST_SGE_INDEX_SHIFT
value|24
name|uint32_t
name|nal
decl_stmt|;
define|#
directive|define
name|USTORM_ISCSI_PLACEMENT_DB_REM_SGE_SIZE
value|(0xFFFFFF<<0)
comment|/* BitField nalNon aligned db	Number of bytes remaining in local SGEs */
define|#
directive|define
name|USTORM_ISCSI_PLACEMENT_DB_REM_SGE_SIZE_SHIFT
value|0
define|#
directive|define
name|USTORM_ISCSI_PLACEMENT_DB_EXP_DIGEST_3B
value|(0xFF<<24)
comment|/* BitField nalNon aligned db	Number of digest bytes not yet processed */
define|#
directive|define
name|USTORM_ISCSI_PLACEMENT_DB_EXP_DIGEST_3B_SHIFT
value|24
block|}
struct|;
end_struct

begin_comment
comment|/*  * Ustorm iSCSI Storm Context  */
end_comment

begin_struct
struct|struct
name|ustorm_iscsi_st_context
block|{
name|uint32_t
name|exp_stat_sn
comment|/* Expected status sequence number, incremented with each response/middle path/unsolicited received. */
decl_stmt|;
name|uint32_t
name|exp_data_sn
comment|/* Expected Data sequence number, incremented with each data in */
decl_stmt|;
name|struct
name|rings_db
name|ring
comment|/* rq, r2tq ,cq */
decl_stmt|;
name|struct
name|regpair_t
name|task_pbl_base
comment|/* Task PBL base will be read from RAM to context */
decl_stmt|;
name|struct
name|regpair_t
name|tce_phy_addr
comment|/* Pointer to the task context physical address */
decl_stmt|;
name|struct
name|ustorm_iscsi_placement_db
name|place_db
decl_stmt|;
name|uint32_t
name|reserved8
comment|/* reserved */
decl_stmt|;
name|uint32_t
name|rem_rcv_len
comment|/* Temp task context - Remaining bytes to end of task */
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|hdr_itt
comment|/* field copied from PDU header */
decl_stmt|;
name|uint16_t
name|iscsi_conn_id
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|iscsi_conn_id
decl_stmt|;
name|uint16_t
name|hdr_itt
comment|/* field copied from PDU header */
decl_stmt|;
endif|#
directive|endif
name|uint32_t
name|nal_bytes
comment|/* nal bytes read from BRB */
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint8_t
name|hdr_second_byte_union
comment|/* field copied from PDU header */
decl_stmt|;
name|uint8_t
name|bitfield_0
decl_stmt|;
define|#
directive|define
name|USTORM_ISCSI_ST_CONTEXT_BMIDDLEOFPDU
value|(0x1<<0)
comment|/* BitField bitfield_0bitfield_0	marks that processing of payload has started */
define|#
directive|define
name|USTORM_ISCSI_ST_CONTEXT_BMIDDLEOFPDU_SHIFT
value|0
define|#
directive|define
name|USTORM_ISCSI_ST_CONTEXT_BFENCECQE
value|(0x1<<1)
comment|/* BitField bitfield_0bitfield_0	marks that fence is need on the next CQE */
define|#
directive|define
name|USTORM_ISCSI_ST_CONTEXT_BFENCECQE_SHIFT
value|1
define|#
directive|define
name|USTORM_ISCSI_ST_CONTEXT_BRESETCRC
value|(0x1<<2)
comment|/* BitField bitfield_0bitfield_0	marks that a RESET should be sent to CRC machine. Used in NAL condition in the beginning of a PDU. */
define|#
directive|define
name|USTORM_ISCSI_ST_CONTEXT_BRESETCRC_SHIFT
value|2
define|#
directive|define
name|USTORM_ISCSI_ST_CONTEXT_RESERVED1
value|(0x1F<<3)
comment|/* BitField bitfield_0bitfield_0	reserved */
define|#
directive|define
name|USTORM_ISCSI_ST_CONTEXT_RESERVED1_SHIFT
value|3
name|uint8_t
name|task_pdu_cache_index
decl_stmt|;
name|uint8_t
name|task_pbe_cache_index
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint8_t
name|task_pbe_cache_index
decl_stmt|;
name|uint8_t
name|task_pdu_cache_index
decl_stmt|;
name|uint8_t
name|bitfield_0
decl_stmt|;
define|#
directive|define
name|USTORM_ISCSI_ST_CONTEXT_BMIDDLEOFPDU
value|(0x1<<0)
comment|/* BitField bitfield_0bitfield_0	marks that processing of payload has started */
define|#
directive|define
name|USTORM_ISCSI_ST_CONTEXT_BMIDDLEOFPDU_SHIFT
value|0
define|#
directive|define
name|USTORM_ISCSI_ST_CONTEXT_BFENCECQE
value|(0x1<<1)
comment|/* BitField bitfield_0bitfield_0	marks that fence is need on the next CQE */
define|#
directive|define
name|USTORM_ISCSI_ST_CONTEXT_BFENCECQE_SHIFT
value|1
define|#
directive|define
name|USTORM_ISCSI_ST_CONTEXT_BRESETCRC
value|(0x1<<2)
comment|/* BitField bitfield_0bitfield_0	marks that a RESET should be sent to CRC machine. Used in NAL condition in the beginning of a PDU. */
define|#
directive|define
name|USTORM_ISCSI_ST_CONTEXT_BRESETCRC_SHIFT
value|2
define|#
directive|define
name|USTORM_ISCSI_ST_CONTEXT_RESERVED1
value|(0x1F<<3)
comment|/* BitField bitfield_0bitfield_0	reserved */
define|#
directive|define
name|USTORM_ISCSI_ST_CONTEXT_RESERVED1_SHIFT
value|3
name|uint8_t
name|hdr_second_byte_union
comment|/* field copied from PDU header */
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|reserved3
comment|/* reserved */
decl_stmt|;
name|uint8_t
name|reserved2
comment|/* reserved */
decl_stmt|;
name|uint8_t
name|acDecrement
comment|/* Manage the AC decrement that should be done by USDM */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint8_t
name|acDecrement
comment|/* Manage the AC decrement that should be done by USDM */
decl_stmt|;
name|uint8_t
name|reserved2
comment|/* reserved */
decl_stmt|;
name|uint16_t
name|reserved3
comment|/* reserved */
decl_stmt|;
endif|#
directive|endif
name|uint32_t
name|task_stat
comment|/* counts dataIn for read and holds data outs, r2t for write */
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint8_t
name|hdr_opcode
comment|/* field copied from PDU header */
decl_stmt|;
name|uint8_t
name|num_cqs
comment|/* Number of CQs supported by this connection */
decl_stmt|;
name|uint16_t
name|reserved5
comment|/* reserved */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|reserved5
comment|/* reserved */
decl_stmt|;
name|uint8_t
name|num_cqs
comment|/* Number of CQs supported by this connection */
decl_stmt|;
name|uint8_t
name|hdr_opcode
comment|/* field copied from PDU header */
decl_stmt|;
endif|#
directive|endif
name|uint32_t
name|negotiated_rx
decl_stmt|;
define|#
directive|define
name|USTORM_ISCSI_ST_CONTEXT_MAX_RECV_PDU_LENGTH
value|(0xFFFFFF<<0)
comment|/* BitField negotiated_rx	 */
define|#
directive|define
name|USTORM_ISCSI_ST_CONTEXT_MAX_RECV_PDU_LENGTH_SHIFT
value|0
define|#
directive|define
name|USTORM_ISCSI_ST_CONTEXT_MAX_OUTSTANDING_R2TS
value|(0xFF<<24)
comment|/* BitField negotiated_rx	 */
define|#
directive|define
name|USTORM_ISCSI_ST_CONTEXT_MAX_OUTSTANDING_R2TS_SHIFT
value|24
name|uint32_t
name|negotiated_rx_and_flags
decl_stmt|;
define|#
directive|define
name|USTORM_ISCSI_ST_CONTEXT_MAX_BURST_LENGTH
value|(0xFFFFFF<<0)
comment|/* BitField negotiated_rx_and_flags	Negotiated maximum length of sequence */
define|#
directive|define
name|USTORM_ISCSI_ST_CONTEXT_MAX_BURST_LENGTH_SHIFT
value|0
define|#
directive|define
name|USTORM_ISCSI_ST_CONTEXT_B_CQE_POSTED_OR_HEADER_CACHED
value|(0x1<<24)
comment|/* BitField negotiated_rx_and_flags	Marks that unvalid CQE was already posted or PDU header was cachaed in RAM */
define|#
directive|define
name|USTORM_ISCSI_ST_CONTEXT_B_CQE_POSTED_OR_HEADER_CACHED_SHIFT
value|24
define|#
directive|define
name|USTORM_ISCSI_ST_CONTEXT_B_HDR_DIGEST_EN
value|(0x1<<25)
comment|/* BitField negotiated_rx_and_flags	Header digest support enable */
define|#
directive|define
name|USTORM_ISCSI_ST_CONTEXT_B_HDR_DIGEST_EN_SHIFT
value|25
define|#
directive|define
name|USTORM_ISCSI_ST_CONTEXT_B_DATA_DIGEST_EN
value|(0x1<<26)
comment|/* BitField negotiated_rx_and_flags	Data digest support enable */
define|#
directive|define
name|USTORM_ISCSI_ST_CONTEXT_B_DATA_DIGEST_EN_SHIFT
value|26
define|#
directive|define
name|USTORM_ISCSI_ST_CONTEXT_B_PROTOCOL_ERROR
value|(0x1<<27)
comment|/* BitField negotiated_rx_and_flags	 */
define|#
directive|define
name|USTORM_ISCSI_ST_CONTEXT_B_PROTOCOL_ERROR_SHIFT
value|27
define|#
directive|define
name|USTORM_ISCSI_ST_CONTEXT_B_TASK_VALID
value|(0x1<<28)
comment|/* BitField negotiated_rx_and_flags	temp task context */
define|#
directive|define
name|USTORM_ISCSI_ST_CONTEXT_B_TASK_VALID_SHIFT
value|28
define|#
directive|define
name|USTORM_ISCSI_ST_CONTEXT_TASK_TYPE
value|(0x3<<29)
comment|/* BitField negotiated_rx_and_flags	Task type: 0 = slow-path (non-RW) 1 = read 2 = write */
define|#
directive|define
name|USTORM_ISCSI_ST_CONTEXT_TASK_TYPE_SHIFT
value|29
define|#
directive|define
name|USTORM_ISCSI_ST_CONTEXT_B_ALL_DATA_ACKED
value|(0x1<<31)
comment|/* BitField negotiated_rx_and_flags	Set if all data is acked */
define|#
directive|define
name|USTORM_ISCSI_ST_CONTEXT_B_ALL_DATA_ACKED_SHIFT
value|31
block|}
struct|;
end_struct

begin_comment
comment|/*  * TCP context region, shared in TOE, RDMA and ISCSI  */
end_comment

begin_struct
struct|struct
name|tstorm_tcp_st_context_section
block|{
name|uint32_t
name|flags1
decl_stmt|;
define|#
directive|define
name|TSTORM_TCP_ST_CONTEXT_SECTION_RTT_SRTT
value|(0xFFFFFF<<0)
comment|/* BitField flags1various state flags	20b only, Smoothed Rount Trip Time */
define|#
directive|define
name|TSTORM_TCP_ST_CONTEXT_SECTION_RTT_SRTT_SHIFT
value|0
define|#
directive|define
name|TSTORM_TCP_ST_CONTEXT_SECTION_PAWS_INVALID
value|(0x1<<24)
comment|/* BitField flags1various state flags	PAWS asserted as invalid in KA flow */
define|#
directive|define
name|TSTORM_TCP_ST_CONTEXT_SECTION_PAWS_INVALID_SHIFT
value|24
define|#
directive|define
name|TSTORM_TCP_ST_CONTEXT_SECTION_TIMESTAMP_EXISTS
value|(0x1<<25)
comment|/* BitField flags1various state flags	Timestamps supported on this connection */
define|#
directive|define
name|TSTORM_TCP_ST_CONTEXT_SECTION_TIMESTAMP_EXISTS_SHIFT
value|25
define|#
directive|define
name|TSTORM_TCP_ST_CONTEXT_SECTION_RESERVED0
value|(0x1<<26)
comment|/* BitField flags1various state flags	 */
define|#
directive|define
name|TSTORM_TCP_ST_CONTEXT_SECTION_RESERVED0_SHIFT
value|26
define|#
directive|define
name|TSTORM_TCP_ST_CONTEXT_SECTION_STOP_RX_PAYLOAD
value|(0x1<<27)
comment|/* BitField flags1various state flags	stop receiving rx payload */
define|#
directive|define
name|TSTORM_TCP_ST_CONTEXT_SECTION_STOP_RX_PAYLOAD_SHIFT
value|27
define|#
directive|define
name|TSTORM_TCP_ST_CONTEXT_SECTION_KA_ENABLED
value|(0x1<<28)
comment|/* BitField flags1various state flags	Keep Alive enabled */
define|#
directive|define
name|TSTORM_TCP_ST_CONTEXT_SECTION_KA_ENABLED_SHIFT
value|28
define|#
directive|define
name|TSTORM_TCP_ST_CONTEXT_SECTION_FIRST_RTO_ESTIMATE
value|(0x1<<29)
comment|/* BitField flags1various state flags	First Retransmition Timout Estimation */
define|#
directive|define
name|TSTORM_TCP_ST_CONTEXT_SECTION_FIRST_RTO_ESTIMATE_SHIFT
value|29
define|#
directive|define
name|TSTORM_TCP_ST_CONTEXT_SECTION_MAX_SEG_RETRANSMIT_EN
value|(0x1<<30)
comment|/* BitField flags1various state flags	per connection flag, signals whether to check if rt count exceeds max_seg_retransmit */
define|#
directive|define
name|TSTORM_TCP_ST_CONTEXT_SECTION_MAX_SEG_RETRANSMIT_EN_SHIFT
value|30
define|#
directive|define
name|TSTORM_TCP_ST_CONTEXT_SECTION_LAST_ISLE_HAS_FIN
value|(0x1<<31)
comment|/* BitField flags1various state flags	last isle ends with FIN. FIN is counted as 1 byte for isle end sequence */
define|#
directive|define
name|TSTORM_TCP_ST_CONTEXT_SECTION_LAST_ISLE_HAS_FIN_SHIFT
value|31
name|uint32_t
name|flags2
decl_stmt|;
define|#
directive|define
name|TSTORM_TCP_ST_CONTEXT_SECTION_RTT_VARIATION
value|(0xFFFFFF<<0)
comment|/* BitField flags2various state flags	20b only, Round Trip Time variation */
define|#
directive|define
name|TSTORM_TCP_ST_CONTEXT_SECTION_RTT_VARIATION_SHIFT
value|0
define|#
directive|define
name|TSTORM_TCP_ST_CONTEXT_SECTION_DA_EN
value|(0x1<<24)
comment|/* BitField flags2various state flags	 */
define|#
directive|define
name|TSTORM_TCP_ST_CONTEXT_SECTION_DA_EN_SHIFT
value|24
define|#
directive|define
name|TSTORM_TCP_ST_CONTEXT_SECTION_DA_COUNTER_EN
value|(0x1<<25)
comment|/* BitField flags2various state flags	per GOS flags, but duplicated for each context */
define|#
directive|define
name|TSTORM_TCP_ST_CONTEXT_SECTION_DA_COUNTER_EN_SHIFT
value|25
define|#
directive|define
name|__TSTORM_TCP_ST_CONTEXT_SECTION_KA_PROBE_SENT
value|(0x1<<26)
comment|/* BitField flags2various state flags	keep alive packet was sent */
define|#
directive|define
name|__TSTORM_TCP_ST_CONTEXT_SECTION_KA_PROBE_SENT_SHIFT
value|26
define|#
directive|define
name|__TSTORM_TCP_ST_CONTEXT_SECTION_PERSIST_PROBE_SENT
value|(0x1<<27)
comment|/* BitField flags2various state flags	persist packet was sent */
define|#
directive|define
name|__TSTORM_TCP_ST_CONTEXT_SECTION_PERSIST_PROBE_SENT_SHIFT
value|27
define|#
directive|define
name|TSTORM_TCP_ST_CONTEXT_SECTION_UPDATE_L2_STATSTICS
value|(0x1<<28)
comment|/* BitField flags2various state flags	determines wheather or not to update l2 statistics */
define|#
directive|define
name|TSTORM_TCP_ST_CONTEXT_SECTION_UPDATE_L2_STATSTICS_SHIFT
value|28
define|#
directive|define
name|TSTORM_TCP_ST_CONTEXT_SECTION_UPDATE_L4_STATSTICS
value|(0x1<<29)
comment|/* BitField flags2various state flags	determines wheather or not to update l4 statistics */
define|#
directive|define
name|TSTORM_TCP_ST_CONTEXT_SECTION_UPDATE_L4_STATSTICS_SHIFT
value|29
define|#
directive|define
name|__TSTORM_TCP_ST_CONTEXT_SECTION_IN_WINDOW_RST_ATTACK
value|(0x1<<30)
comment|/* BitField flags2various state flags	possible blind-in-window RST attack detected */
define|#
directive|define
name|__TSTORM_TCP_ST_CONTEXT_SECTION_IN_WINDOW_RST_ATTACK_SHIFT
value|30
define|#
directive|define
name|__TSTORM_TCP_ST_CONTEXT_SECTION_IN_WINDOW_SYN_ATTACK
value|(0x1<<31)
comment|/* BitField flags2various state flags	possible blind-in-window SYN attack detected */
define|#
directive|define
name|__TSTORM_TCP_ST_CONTEXT_SECTION_IN_WINDOW_SYN_ATTACK_SHIFT
value|31
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|mss
decl_stmt|;
name|uint8_t
name|tcp_sm_state
comment|/* 3b only, Tcp state machine state */
decl_stmt|;
name|uint8_t
name|rto_exp
comment|/* 3b only, Exponential Backoff index */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint8_t
name|rto_exp
comment|/* 3b only, Exponential Backoff index */
decl_stmt|;
name|uint8_t
name|tcp_sm_state
comment|/* 3b only, Tcp state machine state */
decl_stmt|;
name|uint16_t
name|mss
decl_stmt|;
endif|#
directive|endif
name|uint32_t
name|rcv_nxt
comment|/* Receive sequence: next expected */
decl_stmt|;
name|uint32_t
name|timestamp_recent
comment|/* last timestamp from segTS */
decl_stmt|;
name|uint32_t
name|timestamp_recent_time
comment|/* time at which timestamp_recent has been set */
decl_stmt|;
name|uint32_t
name|cwnd
comment|/* Congestion window */
decl_stmt|;
name|uint32_t
name|ss_thresh
comment|/* Slow Start Threshold */
decl_stmt|;
name|uint32_t
name|cwnd_accum
comment|/* Congestion window accumilation */
decl_stmt|;
name|uint32_t
name|prev_seg_seq
comment|/* Sequence number used for last sndWnd update (was: snd_wnd_l1) */
decl_stmt|;
name|uint32_t
name|expected_rel_seq
comment|/* the last update of rel_seq */
decl_stmt|;
name|uint32_t
name|recover
comment|/* Recording of sndMax when we enter retransmit */
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint8_t
name|retransmit_count
comment|/* Number of times a packet was retransmitted */
decl_stmt|;
name|uint8_t
name|ka_max_probe_count
comment|/* Keep Alive maximum probe counter */
decl_stmt|;
name|uint8_t
name|persist_probe_count
comment|/* Persist probe counter */
decl_stmt|;
name|uint8_t
name|ka_probe_count
comment|/* Keep Alive probe counter */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint8_t
name|ka_probe_count
comment|/* Keep Alive probe counter */
decl_stmt|;
name|uint8_t
name|persist_probe_count
comment|/* Persist probe counter */
decl_stmt|;
name|uint8_t
name|ka_max_probe_count
comment|/* Keep Alive maximum probe counter */
decl_stmt|;
name|uint8_t
name|retransmit_count
comment|/* Number of times a packet was retransmitted */
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint8_t
name|statistics_counter_id
comment|/* The ID of the statistics client for counting common/L2 statistics */
decl_stmt|;
name|uint8_t
name|ooo_support_mode
decl_stmt|;
name|uint8_t
name|snd_wnd_scale
comment|/* 4b only, Far-end window (Snd.Wind.Scale) scale */
decl_stmt|;
name|uint8_t
name|dup_ack_count
comment|/* Duplicate Ack Counter */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint8_t
name|dup_ack_count
comment|/* Duplicate Ack Counter */
decl_stmt|;
name|uint8_t
name|snd_wnd_scale
comment|/* 4b only, Far-end window (Snd.Wind.Scale) scale */
decl_stmt|;
name|uint8_t
name|ooo_support_mode
decl_stmt|;
name|uint8_t
name|statistics_counter_id
comment|/* The ID of the statistics client for counting common/L2 statistics */
decl_stmt|;
endif|#
directive|endif
name|uint32_t
name|retransmit_start_time
comment|/* Used by retransmit as a recording of start time */
decl_stmt|;
name|uint32_t
name|ka_timeout
comment|/* Keep Alive timeout */
decl_stmt|;
name|uint32_t
name|ka_interval
comment|/* Keep Alive interval */
decl_stmt|;
name|uint32_t
name|isle_start_seq
comment|/* First Out-of-order isle start sequence */
decl_stmt|;
name|uint32_t
name|isle_end_seq
comment|/* First Out-of-order isle end sequence */
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|second_isle_address
comment|/* address of the second isle (if exists) in internal RAM */
decl_stmt|;
name|uint16_t
name|recent_seg_wnd
comment|/* Last far end window received (not scaled!) */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|recent_seg_wnd
comment|/* Last far end window received (not scaled!) */
decl_stmt|;
name|uint16_t
name|second_isle_address
comment|/* address of the second isle (if exists) in internal RAM */
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint8_t
name|max_isles_ever_happened
comment|/* for statistics only - max number of isles ever happened on this connection */
decl_stmt|;
name|uint8_t
name|isles_number
comment|/* number of isles */
decl_stmt|;
name|uint16_t
name|last_isle_address
comment|/* address of the last isle (if exists) in internal RAM */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|last_isle_address
comment|/* address of the last isle (if exists) in internal RAM */
decl_stmt|;
name|uint8_t
name|isles_number
comment|/* number of isles */
decl_stmt|;
name|uint8_t
name|max_isles_ever_happened
comment|/* for statistics only - max number of isles ever happened on this connection */
decl_stmt|;
endif|#
directive|endif
name|uint32_t
name|max_rt_time
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|lsb_mac_address
comment|/* TX source MAC LSB-16 */
decl_stmt|;
name|uint16_t
name|vlan_id
comment|/* Connection-configured VLAN ID */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|vlan_id
comment|/* Connection-configured VLAN ID */
decl_stmt|;
name|uint16_t
name|lsb_mac_address
comment|/* TX source MAC LSB-16 */
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|msb_mac_address
comment|/* TX source MAC MSB-16 */
decl_stmt|;
name|uint16_t
name|mid_mac_address
comment|/* TX source MAC MID-16 */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|mid_mac_address
comment|/* TX source MAC MID-16 */
decl_stmt|;
name|uint16_t
name|msb_mac_address
comment|/* TX source MAC MSB-16 */
decl_stmt|;
endif|#
directive|endif
name|uint32_t
name|rightmost_received_seq
comment|/* The maximum sequence ever received - used for The New Patent */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Termination variables  */
end_comment

begin_struct
struct|struct
name|iscsi_term_vars
block|{
name|uint8_t
name|BitMap
decl_stmt|;
define|#
directive|define
name|ISCSI_TERM_VARS_TCP_STATE
value|(0xF<<0)
comment|/* BitField BitMap	tcp state for the termination process */
define|#
directive|define
name|ISCSI_TERM_VARS_TCP_STATE_SHIFT
value|0
define|#
directive|define
name|ISCSI_TERM_VARS_FIN_RECEIVED_SBIT
value|(0x1<<4)
comment|/* BitField BitMap	fin received sticky bit */
define|#
directive|define
name|ISCSI_TERM_VARS_FIN_RECEIVED_SBIT_SHIFT
value|4
define|#
directive|define
name|ISCSI_TERM_VARS_ACK_ON_FIN_RECEIVED_SBIT
value|(0x1<<5)
comment|/* BitField BitMap	ack on fin received stick bit */
define|#
directive|define
name|ISCSI_TERM_VARS_ACK_ON_FIN_RECEIVED_SBIT_SHIFT
value|5
define|#
directive|define
name|ISCSI_TERM_VARS_TERM_ON_CHIP
value|(0x1<<6)
comment|/* BitField BitMap	termination on chip ( option2 ) */
define|#
directive|define
name|ISCSI_TERM_VARS_TERM_ON_CHIP_SHIFT
value|6
define|#
directive|define
name|ISCSI_TERM_VARS_RSRV
value|(0x1<<7)
comment|/* BitField BitMap	 */
define|#
directive|define
name|ISCSI_TERM_VARS_RSRV_SHIFT
value|7
block|}
struct|;
end_struct

begin_comment
comment|/*  * iSCSI context region, used only in iSCSI  */
end_comment

begin_struct
struct|struct
name|tstorm_iscsi_st_context_section
block|{
name|uint32_t
name|nalPayload
comment|/* Non-aligned payload */
decl_stmt|;
name|uint32_t
name|b2nh
comment|/* Number of bytes to next iSCSI header */
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|rq_cons
comment|/* RQ consumer */
decl_stmt|;
name|uint8_t
name|flags
decl_stmt|;
define|#
directive|define
name|TSTORM_ISCSI_ST_CONTEXT_SECTION_B_HDR_DIGEST_EN
value|(0x1<<0)
comment|/* BitField flags	header digest enable, set at login stage */
define|#
directive|define
name|TSTORM_ISCSI_ST_CONTEXT_SECTION_B_HDR_DIGEST_EN_SHIFT
value|0
define|#
directive|define
name|TSTORM_ISCSI_ST_CONTEXT_SECTION_B_DATA_DIGEST_EN
value|(0x1<<1)
comment|/* BitField flags	data digest enable, set at login stage */
define|#
directive|define
name|TSTORM_ISCSI_ST_CONTEXT_SECTION_B_DATA_DIGEST_EN_SHIFT
value|1
define|#
directive|define
name|TSTORM_ISCSI_ST_CONTEXT_SECTION_B_PARTIAL_HEADER
value|(0x1<<2)
comment|/* BitField flags	partial header flow indication */
define|#
directive|define
name|TSTORM_ISCSI_ST_CONTEXT_SECTION_B_PARTIAL_HEADER_SHIFT
value|2
define|#
directive|define
name|TSTORM_ISCSI_ST_CONTEXT_SECTION_B_FULL_FEATURE
value|(0x1<<3)
comment|/* BitField flags	 */
define|#
directive|define
name|TSTORM_ISCSI_ST_CONTEXT_SECTION_B_FULL_FEATURE_SHIFT
value|3
define|#
directive|define
name|TSTORM_ISCSI_ST_CONTEXT_SECTION_B_DROP_ALL_PDUS
value|(0x1<<4)
comment|/* BitField flags	 */
define|#
directive|define
name|TSTORM_ISCSI_ST_CONTEXT_SECTION_B_DROP_ALL_PDUS_SHIFT
value|4
define|#
directive|define
name|TSTORM_ISCSI_ST_CONTEXT_SECTION_NALLEN
value|(0x3<<5)
comment|/* BitField flags	Non-aligned length */
define|#
directive|define
name|TSTORM_ISCSI_ST_CONTEXT_SECTION_NALLEN_SHIFT
value|5
define|#
directive|define
name|TSTORM_ISCSI_ST_CONTEXT_SECTION_RSRV0
value|(0x1<<7)
comment|/* BitField flags	 */
define|#
directive|define
name|TSTORM_ISCSI_ST_CONTEXT_SECTION_RSRV0_SHIFT
value|7
name|uint8_t
name|hdr_bytes_2_fetch
comment|/* Number of bytes left to fetch to complete iSCSI header */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint8_t
name|hdr_bytes_2_fetch
comment|/* Number of bytes left to fetch to complete iSCSI header */
decl_stmt|;
name|uint8_t
name|flags
decl_stmt|;
define|#
directive|define
name|TSTORM_ISCSI_ST_CONTEXT_SECTION_B_HDR_DIGEST_EN
value|(0x1<<0)
comment|/* BitField flags	header digest enable, set at login stage */
define|#
directive|define
name|TSTORM_ISCSI_ST_CONTEXT_SECTION_B_HDR_DIGEST_EN_SHIFT
value|0
define|#
directive|define
name|TSTORM_ISCSI_ST_CONTEXT_SECTION_B_DATA_DIGEST_EN
value|(0x1<<1)
comment|/* BitField flags	data digest enable, set at login stage */
define|#
directive|define
name|TSTORM_ISCSI_ST_CONTEXT_SECTION_B_DATA_DIGEST_EN_SHIFT
value|1
define|#
directive|define
name|TSTORM_ISCSI_ST_CONTEXT_SECTION_B_PARTIAL_HEADER
value|(0x1<<2)
comment|/* BitField flags	partial header flow indication */
define|#
directive|define
name|TSTORM_ISCSI_ST_CONTEXT_SECTION_B_PARTIAL_HEADER_SHIFT
value|2
define|#
directive|define
name|TSTORM_ISCSI_ST_CONTEXT_SECTION_B_FULL_FEATURE
value|(0x1<<3)
comment|/* BitField flags	 */
define|#
directive|define
name|TSTORM_ISCSI_ST_CONTEXT_SECTION_B_FULL_FEATURE_SHIFT
value|3
define|#
directive|define
name|TSTORM_ISCSI_ST_CONTEXT_SECTION_B_DROP_ALL_PDUS
value|(0x1<<4)
comment|/* BitField flags	 */
define|#
directive|define
name|TSTORM_ISCSI_ST_CONTEXT_SECTION_B_DROP_ALL_PDUS_SHIFT
value|4
define|#
directive|define
name|TSTORM_ISCSI_ST_CONTEXT_SECTION_NALLEN
value|(0x3<<5)
comment|/* BitField flags	Non-aligned length */
define|#
directive|define
name|TSTORM_ISCSI_ST_CONTEXT_SECTION_NALLEN_SHIFT
value|5
define|#
directive|define
name|TSTORM_ISCSI_ST_CONTEXT_SECTION_RSRV0
value|(0x1<<7)
comment|/* BitField flags	 */
define|#
directive|define
name|TSTORM_ISCSI_ST_CONTEXT_SECTION_RSRV0_SHIFT
value|7
name|uint16_t
name|rq_cons
comment|/* RQ consumer */
decl_stmt|;
endif|#
directive|endif
name|struct
name|regpair_t
name|rq_db_phy_addr
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|struct
name|iscsi_term_vars
name|term_vars
comment|/* Termination variables */
decl_stmt|;
name|uint8_t
name|rsrv1
decl_stmt|;
name|uint16_t
name|iscsi_conn_id
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|iscsi_conn_id
decl_stmt|;
name|uint8_t
name|rsrv1
decl_stmt|;
name|struct
name|iscsi_term_vars
name|term_vars
comment|/* Termination variables */
decl_stmt|;
endif|#
directive|endif
name|uint32_t
name|process_nxt
comment|/* next TCP sequence to be processed by the iSCSI layer. */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The iSCSI non-aggregative context of Tstorm  */
end_comment

begin_struct
struct|struct
name|tstorm_iscsi_st_context
block|{
name|struct
name|tstorm_tcp_st_context_section
name|tcp
comment|/* TCP  context region, shared in TOE, RDMA and iSCSI */
decl_stmt|;
name|struct
name|tstorm_iscsi_st_context_section
name|iscsi
comment|/* iSCSI context region, used only in iSCSI */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Ethernet context section, shared in TOE, RDMA and ISCSI  */
end_comment

begin_struct
struct|struct
name|xstorm_eth_context_section
block|{
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint8_t
name|remote_addr_4
comment|/* Remote Mac Address, used in PBF Header Builder Command */
decl_stmt|;
name|uint8_t
name|remote_addr_5
comment|/* Remote Mac Address, used in PBF Header Builder Command */
decl_stmt|;
name|uint8_t
name|local_addr_0
comment|/* Local Mac Address, used in PBF Header Builder Command */
decl_stmt|;
name|uint8_t
name|local_addr_1
comment|/* Local Mac Address, used in PBF Header Builder Command */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint8_t
name|local_addr_1
comment|/* Local Mac Address, used in PBF Header Builder Command */
decl_stmt|;
name|uint8_t
name|local_addr_0
comment|/* Local Mac Address, used in PBF Header Builder Command */
decl_stmt|;
name|uint8_t
name|remote_addr_5
comment|/* Remote Mac Address, used in PBF Header Builder Command */
decl_stmt|;
name|uint8_t
name|remote_addr_4
comment|/* Remote Mac Address, used in PBF Header Builder Command */
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint8_t
name|remote_addr_0
comment|/* Remote Mac Address, used in PBF Header Builder Command */
decl_stmt|;
name|uint8_t
name|remote_addr_1
comment|/* Remote Mac Address, used in PBF Header Builder Command */
decl_stmt|;
name|uint8_t
name|remote_addr_2
comment|/* Remote Mac Address, used in PBF Header Builder Command */
decl_stmt|;
name|uint8_t
name|remote_addr_3
comment|/* Remote Mac Address, used in PBF Header Builder Command */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint8_t
name|remote_addr_3
comment|/* Remote Mac Address, used in PBF Header Builder Command */
decl_stmt|;
name|uint8_t
name|remote_addr_2
comment|/* Remote Mac Address, used in PBF Header Builder Command */
decl_stmt|;
name|uint8_t
name|remote_addr_1
comment|/* Remote Mac Address, used in PBF Header Builder Command */
decl_stmt|;
name|uint8_t
name|remote_addr_0
comment|/* Remote Mac Address, used in PBF Header Builder Command */
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|reserved_vlan_type
comment|/* this field is not an absolute must, but the reseved was here */
decl_stmt|;
name|uint16_t
name|vlan_params
decl_stmt|;
define|#
directive|define
name|XSTORM_ETH_CONTEXT_SECTION_VLAN_ID
value|(0xFFF<<0)
comment|/* BitField vlan_params	part of PBF Header Builder Command */
define|#
directive|define
name|XSTORM_ETH_CONTEXT_SECTION_VLAN_ID_SHIFT
value|0
define|#
directive|define
name|XSTORM_ETH_CONTEXT_SECTION_CFI
value|(0x1<<12)
comment|/* BitField vlan_params	Canonical format indicator, part of PBF Header Builder Command */
define|#
directive|define
name|XSTORM_ETH_CONTEXT_SECTION_CFI_SHIFT
value|12
define|#
directive|define
name|XSTORM_ETH_CONTEXT_SECTION_PRIORITY
value|(0x7<<13)
comment|/* BitField vlan_params	part of PBF Header Builder Command */
define|#
directive|define
name|XSTORM_ETH_CONTEXT_SECTION_PRIORITY_SHIFT
value|13
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|vlan_params
decl_stmt|;
define|#
directive|define
name|XSTORM_ETH_CONTEXT_SECTION_VLAN_ID
value|(0xFFF<<0)
comment|/* BitField vlan_params	part of PBF Header Builder Command */
define|#
directive|define
name|XSTORM_ETH_CONTEXT_SECTION_VLAN_ID_SHIFT
value|0
define|#
directive|define
name|XSTORM_ETH_CONTEXT_SECTION_CFI
value|(0x1<<12)
comment|/* BitField vlan_params	Canonical format indicator, part of PBF Header Builder Command */
define|#
directive|define
name|XSTORM_ETH_CONTEXT_SECTION_CFI_SHIFT
value|12
define|#
directive|define
name|XSTORM_ETH_CONTEXT_SECTION_PRIORITY
value|(0x7<<13)
comment|/* BitField vlan_params	part of PBF Header Builder Command */
define|#
directive|define
name|XSTORM_ETH_CONTEXT_SECTION_PRIORITY_SHIFT
value|13
name|uint16_t
name|reserved_vlan_type
comment|/* this field is not an absolute must, but the reseved was here */
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint8_t
name|local_addr_2
comment|/* Local Mac Address, used in PBF Header Builder Command */
decl_stmt|;
name|uint8_t
name|local_addr_3
comment|/* Local Mac Address, used in PBF Header Builder Command */
decl_stmt|;
name|uint8_t
name|local_addr_4
comment|/* Loca lMac Address, used in PBF Header Builder Command */
decl_stmt|;
name|uint8_t
name|local_addr_5
comment|/* Local Mac Address, used in PBF Header Builder Command */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint8_t
name|local_addr_5
comment|/* Local Mac Address, used in PBF Header Builder Command */
decl_stmt|;
name|uint8_t
name|local_addr_4
comment|/* Loca lMac Address, used in PBF Header Builder Command */
decl_stmt|;
name|uint8_t
name|local_addr_3
comment|/* Local Mac Address, used in PBF Header Builder Command */
decl_stmt|;
name|uint8_t
name|local_addr_2
comment|/* Local Mac Address, used in PBF Header Builder Command */
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/*  * IpV4 context section, shared in TOE, RDMA and ISCSI  */
end_comment

begin_struct
struct|struct
name|xstorm_ip_v4_context_section
block|{
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|__pbf_hdr_cmd_rsvd_id
decl_stmt|;
name|uint16_t
name|__pbf_hdr_cmd_rsvd_flags_offset
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|__pbf_hdr_cmd_rsvd_flags_offset
decl_stmt|;
name|uint16_t
name|__pbf_hdr_cmd_rsvd_id
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint8_t
name|__pbf_hdr_cmd_rsvd_ver_ihl
decl_stmt|;
name|uint8_t
name|tos
comment|/* Type Of Service, used in PBF Header Builder Command */
decl_stmt|;
name|uint16_t
name|__pbf_hdr_cmd_rsvd_length
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|__pbf_hdr_cmd_rsvd_length
decl_stmt|;
name|uint8_t
name|tos
comment|/* Type Of Service, used in PBF Header Builder Command */
decl_stmt|;
name|uint8_t
name|__pbf_hdr_cmd_rsvd_ver_ihl
decl_stmt|;
endif|#
directive|endif
name|uint32_t
name|ip_local_addr
comment|/* used in PBF Header Builder Command */
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint8_t
name|ttl
comment|/* Time to live, used in PBF Header Builder Command */
decl_stmt|;
name|uint8_t
name|__pbf_hdr_cmd_rsvd_protocol
decl_stmt|;
name|uint16_t
name|__pbf_hdr_cmd_rsvd_csum
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|__pbf_hdr_cmd_rsvd_csum
decl_stmt|;
name|uint8_t
name|__pbf_hdr_cmd_rsvd_protocol
decl_stmt|;
name|uint8_t
name|ttl
comment|/* Time to live, used in PBF Header Builder Command */
decl_stmt|;
endif|#
directive|endif
name|uint32_t
name|__pbf_hdr_cmd_rsvd_1
comment|/* places the ip_remote_addr field in the proper place in the regpair */
decl_stmt|;
name|uint32_t
name|ip_remote_addr
comment|/* used in PBF Header Builder Command */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * context section, shared in TOE, RDMA and ISCSI  */
end_comment

begin_struct
struct|struct
name|xstorm_padded_ip_v4_context_section
block|{
name|struct
name|xstorm_ip_v4_context_section
name|ip_v4
decl_stmt|;
name|uint32_t
name|reserved1
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * IpV6 context section, shared in TOE, RDMA and ISCSI  */
end_comment

begin_struct
struct|struct
name|xstorm_ip_v6_context_section
block|{
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|pbf_hdr_cmd_rsvd_payload_len
decl_stmt|;
name|uint8_t
name|pbf_hdr_cmd_rsvd_nxt_hdr
decl_stmt|;
name|uint8_t
name|hop_limit
comment|/* used in PBF Header Builder Command */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint8_t
name|hop_limit
comment|/* used in PBF Header Builder Command */
decl_stmt|;
name|uint8_t
name|pbf_hdr_cmd_rsvd_nxt_hdr
decl_stmt|;
name|uint16_t
name|pbf_hdr_cmd_rsvd_payload_len
decl_stmt|;
endif|#
directive|endif
name|uint32_t
name|priority_flow_label
decl_stmt|;
define|#
directive|define
name|XSTORM_IP_V6_CONTEXT_SECTION_FLOW_LABEL
value|(0xFFFFF<<0)
comment|/* BitField priority_flow_label	used in PBF Header Builder Command */
define|#
directive|define
name|XSTORM_IP_V6_CONTEXT_SECTION_FLOW_LABEL_SHIFT
value|0
define|#
directive|define
name|XSTORM_IP_V6_CONTEXT_SECTION_TRAFFIC_CLASS
value|(0xFF<<20)
comment|/* BitField priority_flow_label	used in PBF Header Builder Command */
define|#
directive|define
name|XSTORM_IP_V6_CONTEXT_SECTION_TRAFFIC_CLASS_SHIFT
value|20
define|#
directive|define
name|XSTORM_IP_V6_CONTEXT_SECTION_PBF_HDR_CMD_RSVD_VER
value|(0xF<<28)
comment|/* BitField priority_flow_label	 */
define|#
directive|define
name|XSTORM_IP_V6_CONTEXT_SECTION_PBF_HDR_CMD_RSVD_VER_SHIFT
value|28
name|uint32_t
name|ip_local_addr_lo_hi
comment|/* second 32 bits of Ip local Address, used in PBF Header Builder Command */
decl_stmt|;
name|uint32_t
name|ip_local_addr_lo_lo
comment|/* first 32 bits of Ip local Address, used in PBF Header Builder Command */
decl_stmt|;
name|uint32_t
name|ip_local_addr_hi_hi
comment|/* fourth 32 bits of Ip local Address, used in PBF Header Builder Command */
decl_stmt|;
name|uint32_t
name|ip_local_addr_hi_lo
comment|/* third 32 bits of Ip local Address, used in PBF Header Builder Command */
decl_stmt|;
name|uint32_t
name|ip_remote_addr_lo_hi
comment|/* second 32 bits of Ip remoteinsation Address, used in PBF Header Builder Command */
decl_stmt|;
name|uint32_t
name|ip_remote_addr_lo_lo
comment|/* first 32 bits of Ip remoteinsation Address, used in PBF Header Builder Command */
decl_stmt|;
name|uint32_t
name|ip_remote_addr_hi_hi
comment|/* fourth 32 bits of Ip remoteinsation Address, used in PBF Header Builder Command */
decl_stmt|;
name|uint32_t
name|ip_remote_addr_hi_lo
comment|/* third 32 bits of Ip remoteinsation Address, used in PBF Header Builder Command */
decl_stmt|;
block|}
struct|;
end_struct

begin_union
union|union
name|xstorm_ip_context_section_types
block|{
name|struct
name|xstorm_padded_ip_v4_context_section
name|padded_ip_v4
decl_stmt|;
name|struct
name|xstorm_ip_v6_context_section
name|ip_v6
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/*  * TCP context section, shared in TOE, RDMA and ISCSI  */
end_comment

begin_struct
struct|struct
name|xstorm_tcp_context_section
block|{
name|uint32_t
name|snd_max
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|remote_port
comment|/* used in PBF Header Builder Command */
decl_stmt|;
name|uint16_t
name|local_port
comment|/* used in PBF Header Builder Command */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|local_port
comment|/* used in PBF Header Builder Command */
decl_stmt|;
name|uint16_t
name|remote_port
comment|/* used in PBF Header Builder Command */
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint8_t
name|original_nagle_1b
decl_stmt|;
name|uint8_t
name|ts_enabled
comment|/* Only 1 bit is used */
decl_stmt|;
name|uint16_t
name|tcp_params
decl_stmt|;
define|#
directive|define
name|XSTORM_TCP_CONTEXT_SECTION_TOTAL_HEADER_SIZE
value|(0xFF<<0)
comment|/* BitField tcp_paramsTcp parameters	for ease of pbf command construction */
define|#
directive|define
name|XSTORM_TCP_CONTEXT_SECTION_TOTAL_HEADER_SIZE_SHIFT
value|0
define|#
directive|define
name|__XSTORM_TCP_CONTEXT_SECTION_ECT_BIT
value|(0x1<<8)
comment|/* BitField tcp_paramsTcp parameters	 */
define|#
directive|define
name|__XSTORM_TCP_CONTEXT_SECTION_ECT_BIT_SHIFT
value|8
define|#
directive|define
name|__XSTORM_TCP_CONTEXT_SECTION_ECN_ENABLED
value|(0x1<<9)
comment|/* BitField tcp_paramsTcp parameters	 */
define|#
directive|define
name|__XSTORM_TCP_CONTEXT_SECTION_ECN_ENABLED_SHIFT
value|9
define|#
directive|define
name|XSTORM_TCP_CONTEXT_SECTION_SACK_ENABLED
value|(0x1<<10)
comment|/* BitField tcp_paramsTcp parameters	Selective Ack Enabled */
define|#
directive|define
name|XSTORM_TCP_CONTEXT_SECTION_SACK_ENABLED_SHIFT
value|10
define|#
directive|define
name|XSTORM_TCP_CONTEXT_SECTION_SMALL_WIN_ADV
value|(0x1<<11)
comment|/* BitField tcp_paramsTcp parameters	window smaller than initial window was advertised to far end */
define|#
directive|define
name|XSTORM_TCP_CONTEXT_SECTION_SMALL_WIN_ADV_SHIFT
value|11
define|#
directive|define
name|XSTORM_TCP_CONTEXT_SECTION_FIN_SENT_FLAG
value|(0x1<<12)
comment|/* BitField tcp_paramsTcp parameters	 */
define|#
directive|define
name|XSTORM_TCP_CONTEXT_SECTION_FIN_SENT_FLAG_SHIFT
value|12
define|#
directive|define
name|XSTORM_TCP_CONTEXT_SECTION_WINDOW_SATURATED
value|(0x1<<13)
comment|/* BitField tcp_paramsTcp parameters	 */
define|#
directive|define
name|XSTORM_TCP_CONTEXT_SECTION_WINDOW_SATURATED_SHIFT
value|13
define|#
directive|define
name|XSTORM_TCP_CONTEXT_SECTION_SLOWPATH_QUEUES_FLUSH_COUNTER
value|(0x3<<14)
comment|/* BitField tcp_paramsTcp parameters	 */
define|#
directive|define
name|XSTORM_TCP_CONTEXT_SECTION_SLOWPATH_QUEUES_FLUSH_COUNTER_SHIFT
value|14
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|tcp_params
decl_stmt|;
define|#
directive|define
name|XSTORM_TCP_CONTEXT_SECTION_TOTAL_HEADER_SIZE
value|(0xFF<<0)
comment|/* BitField tcp_paramsTcp parameters	for ease of pbf command construction */
define|#
directive|define
name|XSTORM_TCP_CONTEXT_SECTION_TOTAL_HEADER_SIZE_SHIFT
value|0
define|#
directive|define
name|__XSTORM_TCP_CONTEXT_SECTION_ECT_BIT
value|(0x1<<8)
comment|/* BitField tcp_paramsTcp parameters	 */
define|#
directive|define
name|__XSTORM_TCP_CONTEXT_SECTION_ECT_BIT_SHIFT
value|8
define|#
directive|define
name|__XSTORM_TCP_CONTEXT_SECTION_ECN_ENABLED
value|(0x1<<9)
comment|/* BitField tcp_paramsTcp parameters	 */
define|#
directive|define
name|__XSTORM_TCP_CONTEXT_SECTION_ECN_ENABLED_SHIFT
value|9
define|#
directive|define
name|XSTORM_TCP_CONTEXT_SECTION_SACK_ENABLED
value|(0x1<<10)
comment|/* BitField tcp_paramsTcp parameters	Selective Ack Enabled */
define|#
directive|define
name|XSTORM_TCP_CONTEXT_SECTION_SACK_ENABLED_SHIFT
value|10
define|#
directive|define
name|XSTORM_TCP_CONTEXT_SECTION_SMALL_WIN_ADV
value|(0x1<<11)
comment|/* BitField tcp_paramsTcp parameters	window smaller than initial window was advertised to far end */
define|#
directive|define
name|XSTORM_TCP_CONTEXT_SECTION_SMALL_WIN_ADV_SHIFT
value|11
define|#
directive|define
name|XSTORM_TCP_CONTEXT_SECTION_FIN_SENT_FLAG
value|(0x1<<12)
comment|/* BitField tcp_paramsTcp parameters	 */
define|#
directive|define
name|XSTORM_TCP_CONTEXT_SECTION_FIN_SENT_FLAG_SHIFT
value|12
define|#
directive|define
name|XSTORM_TCP_CONTEXT_SECTION_WINDOW_SATURATED
value|(0x1<<13)
comment|/* BitField tcp_paramsTcp parameters	 */
define|#
directive|define
name|XSTORM_TCP_CONTEXT_SECTION_WINDOW_SATURATED_SHIFT
value|13
define|#
directive|define
name|XSTORM_TCP_CONTEXT_SECTION_SLOWPATH_QUEUES_FLUSH_COUNTER
value|(0x3<<14)
comment|/* BitField tcp_paramsTcp parameters	 */
define|#
directive|define
name|XSTORM_TCP_CONTEXT_SECTION_SLOWPATH_QUEUES_FLUSH_COUNTER_SHIFT
value|14
name|uint8_t
name|ts_enabled
comment|/* Only 1 bit is used */
decl_stmt|;
name|uint8_t
name|original_nagle_1b
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|pseudo_csum
comment|/* the precaluclated pseudo checksum header for pbf command construction */
decl_stmt|;
name|uint16_t
name|window_scaling_factor
comment|/*  local_adv_wnd by this variable to reach the advertised window to far end */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|window_scaling_factor
comment|/*  local_adv_wnd by this variable to reach the advertised window to far end */
decl_stmt|;
name|uint16_t
name|pseudo_csum
comment|/* the precaluclated pseudo checksum header for pbf command construction */
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|reserved2
comment|/* The ID of the statistics client for counting common/L2 statistics */
decl_stmt|;
name|uint8_t
name|statistics_counter_id
comment|/* The ID of the statistics client for counting common/L2 statistics */
decl_stmt|;
name|uint8_t
name|statistics_params
decl_stmt|;
define|#
directive|define
name|XSTORM_TCP_CONTEXT_SECTION_UPDATE_L2_STATSTICS
value|(0x1<<0)
comment|/* BitField statistics_paramsTcp parameters	set by the driver, determines wheather or not to update l2 statistics */
define|#
directive|define
name|XSTORM_TCP_CONTEXT_SECTION_UPDATE_L2_STATSTICS_SHIFT
value|0
define|#
directive|define
name|XSTORM_TCP_CONTEXT_SECTION_UPDATE_L4_STATSTICS
value|(0x1<<1)
comment|/* BitField statistics_paramsTcp parameters	set by the driver, determines wheather or not to update l4 statistics */
define|#
directive|define
name|XSTORM_TCP_CONTEXT_SECTION_UPDATE_L4_STATSTICS_SHIFT
value|1
define|#
directive|define
name|XSTORM_TCP_CONTEXT_SECTION_RESERVED
value|(0x3F<<2)
comment|/* BitField statistics_paramsTcp parameters	 */
define|#
directive|define
name|XSTORM_TCP_CONTEXT_SECTION_RESERVED_SHIFT
value|2
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint8_t
name|statistics_params
decl_stmt|;
define|#
directive|define
name|XSTORM_TCP_CONTEXT_SECTION_UPDATE_L2_STATSTICS
value|(0x1<<0)
comment|/* BitField statistics_paramsTcp parameters	set by the driver, determines wheather or not to update l2 statistics */
define|#
directive|define
name|XSTORM_TCP_CONTEXT_SECTION_UPDATE_L2_STATSTICS_SHIFT
value|0
define|#
directive|define
name|XSTORM_TCP_CONTEXT_SECTION_UPDATE_L4_STATSTICS
value|(0x1<<1)
comment|/* BitField statistics_paramsTcp parameters	set by the driver, determines wheather or not to update l4 statistics */
define|#
directive|define
name|XSTORM_TCP_CONTEXT_SECTION_UPDATE_L4_STATSTICS_SHIFT
value|1
define|#
directive|define
name|XSTORM_TCP_CONTEXT_SECTION_RESERVED
value|(0x3F<<2)
comment|/* BitField statistics_paramsTcp parameters	 */
define|#
directive|define
name|XSTORM_TCP_CONTEXT_SECTION_RESERVED_SHIFT
value|2
name|uint8_t
name|statistics_counter_id
comment|/* The ID of the statistics client for counting common/L2 statistics */
decl_stmt|;
name|uint16_t
name|reserved2
comment|/* The ID of the statistics client for counting common/L2 statistics */
decl_stmt|;
endif|#
directive|endif
name|uint32_t
name|ts_time_diff
comment|/* Time Stamp Offload, used in PBF Header Builder Command */
decl_stmt|;
name|uint32_t
name|__next_timer_expir
comment|/* Last Packet Real Time Clock Stamp */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Common context section, shared in TOE, RDMA and ISCSI  */
end_comment

begin_struct
struct|struct
name|xstorm_common_context_section
block|{
name|struct
name|xstorm_eth_context_section
name|ethernet
decl_stmt|;
name|union
name|xstorm_ip_context_section_types
name|ip_union
decl_stmt|;
name|struct
name|xstorm_tcp_context_section
name|tcp
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint8_t
name|__dcb_val
decl_stmt|;
name|uint8_t
name|flags
decl_stmt|;
define|#
directive|define
name|XSTORM_COMMON_CONTEXT_SECTION_PHYSQ_INITIALIZED
value|(0x1<<0)
comment|/* BitField flagsTcp parameters	part of the tx switching state machine */
define|#
directive|define
name|XSTORM_COMMON_CONTEXT_SECTION_PHYSQ_INITIALIZED_SHIFT
value|0
define|#
directive|define
name|XSTORM_COMMON_CONTEXT_SECTION_PBF_PORT
value|(0x7<<1)
comment|/* BitField flagsTcp parameters	determines to which voq credit will be returned */
define|#
directive|define
name|XSTORM_COMMON_CONTEXT_SECTION_PBF_PORT_SHIFT
value|1
define|#
directive|define
name|XSTORM_COMMON_CONTEXT_SECTION_VLAN_MODE
value|(0x1<<4)
comment|/* BitField flagsTcp parameters	Flag that states wether inner valn was provided by the OS */
define|#
directive|define
name|XSTORM_COMMON_CONTEXT_SECTION_VLAN_MODE_SHIFT
value|4
define|#
directive|define
name|XSTORM_COMMON_CONTEXT_SECTION_ORIGINAL_PRIORITY
value|(0x7<<5)
comment|/* BitField flagsTcp parameters	original priority given from the OS */
define|#
directive|define
name|XSTORM_COMMON_CONTEXT_SECTION_ORIGINAL_PRIORITY_SHIFT
value|5
name|uint8_t
name|outer_tag_flags
decl_stmt|;
define|#
directive|define
name|XSTORM_COMMON_CONTEXT_SECTION_DCB_OUTER_PRI
value|(0x7<<0)
comment|/* BitField outer_tag_flagsTcp parameters	Priority of outer tag in case of DCB enabled */
define|#
directive|define
name|XSTORM_COMMON_CONTEXT_SECTION_DCB_OUTER_PRI_SHIFT
value|0
define|#
directive|define
name|XSTORM_COMMON_CONTEXT_SECTION_OUTER_PRI
value|(0x7<<3)
comment|/* BitField outer_tag_flagsTcp parameters	Priority of outer tag in case of DCB disabled */
define|#
directive|define
name|XSTORM_COMMON_CONTEXT_SECTION_OUTER_PRI_SHIFT
value|3
define|#
directive|define
name|XSTORM_COMMON_CONTEXT_SECTION_RESERVED
value|(0x3<<6)
comment|/* BitField outer_tag_flagsTcp parameters	 */
define|#
directive|define
name|XSTORM_COMMON_CONTEXT_SECTION_RESERVED_SHIFT
value|6
name|uint8_t
name|ip_version_1b
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint8_t
name|ip_version_1b
decl_stmt|;
name|uint8_t
name|outer_tag_flags
decl_stmt|;
define|#
directive|define
name|XSTORM_COMMON_CONTEXT_SECTION_DCB_OUTER_PRI
value|(0x7<<0)
comment|/* BitField outer_tag_flagsTcp parameters	Priority of outer tag in case of DCB enabled */
define|#
directive|define
name|XSTORM_COMMON_CONTEXT_SECTION_DCB_OUTER_PRI_SHIFT
value|0
define|#
directive|define
name|XSTORM_COMMON_CONTEXT_SECTION_OUTER_PRI
value|(0x7<<3)
comment|/* BitField outer_tag_flagsTcp parameters	Priority of outer tag in case of DCB disabled */
define|#
directive|define
name|XSTORM_COMMON_CONTEXT_SECTION_OUTER_PRI_SHIFT
value|3
define|#
directive|define
name|XSTORM_COMMON_CONTEXT_SECTION_RESERVED
value|(0x3<<6)
comment|/* BitField outer_tag_flagsTcp parameters	 */
define|#
directive|define
name|XSTORM_COMMON_CONTEXT_SECTION_RESERVED_SHIFT
value|6
name|uint8_t
name|flags
decl_stmt|;
define|#
directive|define
name|XSTORM_COMMON_CONTEXT_SECTION_PHYSQ_INITIALIZED
value|(0x1<<0)
comment|/* BitField flagsTcp parameters	part of the tx switching state machine */
define|#
directive|define
name|XSTORM_COMMON_CONTEXT_SECTION_PHYSQ_INITIALIZED_SHIFT
value|0
define|#
directive|define
name|XSTORM_COMMON_CONTEXT_SECTION_PBF_PORT
value|(0x7<<1)
comment|/* BitField flagsTcp parameters	determines to which voq credit will be returned */
define|#
directive|define
name|XSTORM_COMMON_CONTEXT_SECTION_PBF_PORT_SHIFT
value|1
define|#
directive|define
name|XSTORM_COMMON_CONTEXT_SECTION_VLAN_MODE
value|(0x1<<4)
comment|/* BitField flagsTcp parameters	Flag that states wether inner valn was provided by the OS */
define|#
directive|define
name|XSTORM_COMMON_CONTEXT_SECTION_VLAN_MODE_SHIFT
value|4
define|#
directive|define
name|XSTORM_COMMON_CONTEXT_SECTION_ORIGINAL_PRIORITY
value|(0x7<<5)
comment|/* BitField flagsTcp parameters	original priority given from the OS */
define|#
directive|define
name|XSTORM_COMMON_CONTEXT_SECTION_ORIGINAL_PRIORITY_SHIFT
value|5
name|uint8_t
name|__dcb_val
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/*  * Flags used in ISCSI context section  */
end_comment

begin_struct
struct|struct
name|xstorm_iscsi_context_flags
block|{
name|uint8_t
name|flags
decl_stmt|;
define|#
directive|define
name|XSTORM_ISCSI_CONTEXT_FLAGS_B_IMMEDIATE_DATA
value|(0x1<<0)
comment|/* BitField flags	 */
define|#
directive|define
name|XSTORM_ISCSI_CONTEXT_FLAGS_B_IMMEDIATE_DATA_SHIFT
value|0
define|#
directive|define
name|XSTORM_ISCSI_CONTEXT_FLAGS_B_INITIAL_R2T
value|(0x1<<1)
comment|/* BitField flags	 */
define|#
directive|define
name|XSTORM_ISCSI_CONTEXT_FLAGS_B_INITIAL_R2T_SHIFT
value|1
define|#
directive|define
name|XSTORM_ISCSI_CONTEXT_FLAGS_B_EN_HEADER_DIGEST
value|(0x1<<2)
comment|/* BitField flags	 */
define|#
directive|define
name|XSTORM_ISCSI_CONTEXT_FLAGS_B_EN_HEADER_DIGEST_SHIFT
value|2
define|#
directive|define
name|XSTORM_ISCSI_CONTEXT_FLAGS_B_EN_DATA_DIGEST
value|(0x1<<3)
comment|/* BitField flags	 */
define|#
directive|define
name|XSTORM_ISCSI_CONTEXT_FLAGS_B_EN_DATA_DIGEST_SHIFT
value|3
define|#
directive|define
name|XSTORM_ISCSI_CONTEXT_FLAGS_B_HQ_BD_WRITTEN
value|(0x1<<4)
comment|/* BitField flags	 */
define|#
directive|define
name|XSTORM_ISCSI_CONTEXT_FLAGS_B_HQ_BD_WRITTEN_SHIFT
value|4
define|#
directive|define
name|XSTORM_ISCSI_CONTEXT_FLAGS_B_LAST_OP_SQ
value|(0x1<<5)
comment|/* BitField flags	 */
define|#
directive|define
name|XSTORM_ISCSI_CONTEXT_FLAGS_B_LAST_OP_SQ_SHIFT
value|5
define|#
directive|define
name|XSTORM_ISCSI_CONTEXT_FLAGS_B_UPDATE_SND_NXT
value|(0x1<<6)
comment|/* BitField flags	 */
define|#
directive|define
name|XSTORM_ISCSI_CONTEXT_FLAGS_B_UPDATE_SND_NXT_SHIFT
value|6
define|#
directive|define
name|XSTORM_ISCSI_CONTEXT_FLAGS_RESERVED4
value|(0x1<<7)
comment|/* BitField flags	 */
define|#
directive|define
name|XSTORM_ISCSI_CONTEXT_FLAGS_RESERVED4_SHIFT
value|7
block|}
struct|;
end_struct

begin_struct
struct|struct
name|iscsi_task_context_entry_x
block|{
name|uint32_t
name|data_out_buffer_offset
decl_stmt|;
name|uint32_t
name|itt
decl_stmt|;
name|uint32_t
name|data_sn
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|iscsi_task_context_entry_xuc_x_write_only
block|{
name|uint32_t
name|tx_r2t_sn
comment|/* Xstorm increments for every data-out seq sent. */
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|iscsi_task_context_entry_xuc_xu_write_both
block|{
name|uint32_t
name|sgl_base_lo
decl_stmt|;
name|uint32_t
name|sgl_base_hi
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint8_t
name|sgl_size
decl_stmt|;
name|uint8_t
name|sge_index
decl_stmt|;
name|uint16_t
name|sge_offset
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|sge_offset
decl_stmt|;
name|uint8_t
name|sge_index
decl_stmt|;
name|uint8_t
name|sgl_size
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/*  * iSCSI context section  */
end_comment

begin_struct
struct|struct
name|xstorm_iscsi_context_section
block|{
name|uint32_t
name|first_burst_length
decl_stmt|;
name|uint32_t
name|max_send_pdu_length
decl_stmt|;
name|struct
name|regpair_t
name|sq_pbl_base
decl_stmt|;
name|struct
name|regpair_t
name|sq_curr_pbe
decl_stmt|;
name|struct
name|regpair_t
name|hq_pbl_base
decl_stmt|;
name|struct
name|regpair_t
name|hq_curr_pbe_base
decl_stmt|;
name|struct
name|regpair_t
name|r2tq_pbl_base
decl_stmt|;
name|struct
name|regpair_t
name|r2tq_curr_pbe_base
decl_stmt|;
name|struct
name|regpair_t
name|task_pbl_base
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|data_out_count
decl_stmt|;
name|struct
name|xstorm_iscsi_context_flags
name|flags
decl_stmt|;
name|uint8_t
name|task_pbl_cache_idx
comment|/* All-ones value stands for PBL not cached */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint8_t
name|task_pbl_cache_idx
comment|/* All-ones value stands for PBL not cached */
decl_stmt|;
name|struct
name|xstorm_iscsi_context_flags
name|flags
decl_stmt|;
name|uint16_t
name|data_out_count
decl_stmt|;
endif|#
directive|endif
name|uint32_t
name|seq_more_2_send
decl_stmt|;
name|uint32_t
name|pdu_more_2_send
decl_stmt|;
name|struct
name|iscsi_task_context_entry_x
name|temp_tce_x
decl_stmt|;
name|struct
name|iscsi_task_context_entry_xuc_x_write_only
name|temp_tce_x_wr
decl_stmt|;
name|struct
name|iscsi_task_context_entry_xuc_xu_write_both
name|temp_tce_xu_wr
decl_stmt|;
name|struct
name|regpair_t
name|lun
decl_stmt|;
name|uint32_t
name|exp_data_transfer_len_ttt
comment|/* Overloaded with ttt in multi-pdu sequences flow. */
decl_stmt|;
name|uint32_t
name|pdu_data_2_rxmit
decl_stmt|;
name|uint32_t
name|rxmit_bytes_2_dr
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|rxmit_sge_offset
decl_stmt|;
name|uint16_t
name|hq_rxmit_cons
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|hq_rxmit_cons
decl_stmt|;
name|uint16_t
name|rxmit_sge_offset
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|r2tq_cons
decl_stmt|;
name|uint8_t
name|rxmit_flags
decl_stmt|;
define|#
directive|define
name|XSTORM_ISCSI_CONTEXT_SECTION_B_NEW_HQ_BD
value|(0x1<<0)
comment|/* BitField rxmit_flags	 */
define|#
directive|define
name|XSTORM_ISCSI_CONTEXT_SECTION_B_NEW_HQ_BD_SHIFT
value|0
define|#
directive|define
name|XSTORM_ISCSI_CONTEXT_SECTION_B_RXMIT_PDU_HDR
value|(0x1<<1)
comment|/* BitField rxmit_flags	 */
define|#
directive|define
name|XSTORM_ISCSI_CONTEXT_SECTION_B_RXMIT_PDU_HDR_SHIFT
value|1
define|#
directive|define
name|XSTORM_ISCSI_CONTEXT_SECTION_B_RXMIT_END_PDU
value|(0x1<<2)
comment|/* BitField rxmit_flags	 */
define|#
directive|define
name|XSTORM_ISCSI_CONTEXT_SECTION_B_RXMIT_END_PDU_SHIFT
value|2
define|#
directive|define
name|XSTORM_ISCSI_CONTEXT_SECTION_B_RXMIT_DR
value|(0x1<<3)
comment|/* BitField rxmit_flags	 */
define|#
directive|define
name|XSTORM_ISCSI_CONTEXT_SECTION_B_RXMIT_DR_SHIFT
value|3
define|#
directive|define
name|XSTORM_ISCSI_CONTEXT_SECTION_B_RXMIT_START_DR
value|(0x1<<4)
comment|/* BitField rxmit_flags	 */
define|#
directive|define
name|XSTORM_ISCSI_CONTEXT_SECTION_B_RXMIT_START_DR_SHIFT
value|4
define|#
directive|define
name|XSTORM_ISCSI_CONTEXT_SECTION_B_RXMIT_PADDING
value|(0x3<<5)
comment|/* BitField rxmit_flags	 */
define|#
directive|define
name|XSTORM_ISCSI_CONTEXT_SECTION_B_RXMIT_PADDING_SHIFT
value|5
define|#
directive|define
name|XSTORM_ISCSI_CONTEXT_SECTION_B_ISCSI_CONT_FAST_RXMIT
value|(0x1<<7)
comment|/* BitField rxmit_flags	 */
define|#
directive|define
name|XSTORM_ISCSI_CONTEXT_SECTION_B_ISCSI_CONT_FAST_RXMIT_SHIFT
value|7
name|uint8_t
name|rxmit_sge_idx
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint8_t
name|rxmit_sge_idx
decl_stmt|;
name|uint8_t
name|rxmit_flags
decl_stmt|;
define|#
directive|define
name|XSTORM_ISCSI_CONTEXT_SECTION_B_NEW_HQ_BD
value|(0x1<<0)
comment|/* BitField rxmit_flags	 */
define|#
directive|define
name|XSTORM_ISCSI_CONTEXT_SECTION_B_NEW_HQ_BD_SHIFT
value|0
define|#
directive|define
name|XSTORM_ISCSI_CONTEXT_SECTION_B_RXMIT_PDU_HDR
value|(0x1<<1)
comment|/* BitField rxmit_flags	 */
define|#
directive|define
name|XSTORM_ISCSI_CONTEXT_SECTION_B_RXMIT_PDU_HDR_SHIFT
value|1
define|#
directive|define
name|XSTORM_ISCSI_CONTEXT_SECTION_B_RXMIT_END_PDU
value|(0x1<<2)
comment|/* BitField rxmit_flags	 */
define|#
directive|define
name|XSTORM_ISCSI_CONTEXT_SECTION_B_RXMIT_END_PDU_SHIFT
value|2
define|#
directive|define
name|XSTORM_ISCSI_CONTEXT_SECTION_B_RXMIT_DR
value|(0x1<<3)
comment|/* BitField rxmit_flags	 */
define|#
directive|define
name|XSTORM_ISCSI_CONTEXT_SECTION_B_RXMIT_DR_SHIFT
value|3
define|#
directive|define
name|XSTORM_ISCSI_CONTEXT_SECTION_B_RXMIT_START_DR
value|(0x1<<4)
comment|/* BitField rxmit_flags	 */
define|#
directive|define
name|XSTORM_ISCSI_CONTEXT_SECTION_B_RXMIT_START_DR_SHIFT
value|4
define|#
directive|define
name|XSTORM_ISCSI_CONTEXT_SECTION_B_RXMIT_PADDING
value|(0x3<<5)
comment|/* BitField rxmit_flags	 */
define|#
directive|define
name|XSTORM_ISCSI_CONTEXT_SECTION_B_RXMIT_PADDING_SHIFT
value|5
define|#
directive|define
name|XSTORM_ISCSI_CONTEXT_SECTION_B_ISCSI_CONT_FAST_RXMIT
value|(0x1<<7)
comment|/* BitField rxmit_flags	 */
define|#
directive|define
name|XSTORM_ISCSI_CONTEXT_SECTION_B_ISCSI_CONT_FAST_RXMIT_SHIFT
value|7
name|uint16_t
name|r2tq_cons
decl_stmt|;
endif|#
directive|endif
name|uint32_t
name|hq_rxmit_tcp_seq
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Xstorm iSCSI Storm Context  */
end_comment

begin_struct
struct|struct
name|xstorm_iscsi_st_context
block|{
name|struct
name|xstorm_common_context_section
name|common
decl_stmt|;
name|struct
name|xstorm_iscsi_context_section
name|iscsi
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Iscsi connection context  */
end_comment

begin_struct
struct|struct
name|iscsi_context
block|{
name|struct
name|ustorm_iscsi_st_context
name|ustorm_st_context
comment|/* Ustorm storm context */
decl_stmt|;
name|struct
name|tstorm_iscsi_st_context
name|tstorm_st_context
comment|/* Tstorm storm context */
decl_stmt|;
name|struct
name|xstorm_iscsi_ag_context
name|xstorm_ag_context
comment|/* Xstorm aggregative context */
decl_stmt|;
name|struct
name|tstorm_iscsi_ag_context
name|tstorm_ag_context
comment|/* Tstorm aggregative context */
decl_stmt|;
name|struct
name|cstorm_iscsi_ag_context
name|cstorm_ag_context
comment|/* Cstorm aggregative context */
decl_stmt|;
name|struct
name|ustorm_iscsi_ag_context
name|ustorm_ag_context
comment|/* Ustorm aggregative context */
decl_stmt|;
name|struct
name|timers_block_context
name|timers_context
comment|/* Timers block context */
decl_stmt|;
name|struct
name|regpair_t
name|upb_context
comment|/* UPb context */
decl_stmt|;
name|struct
name|xstorm_iscsi_st_context
name|xstorm_st_context
comment|/* Xstorm storm context */
decl_stmt|;
name|struct
name|regpair_t
name|xpb_context
comment|/* XPb context (inside the PBF) */
decl_stmt|;
name|struct
name|cstorm_iscsi_st_context
name|cstorm_st_context
comment|/* Cstorm storm context */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * PDU header of an iSCSI DATA-OUT  */
end_comment

begin_struct
struct|struct
name|iscsi_data_pdu_hdr_little_endian
block|{
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint8_t
name|opcode
decl_stmt|;
name|uint8_t
name|op_attr
decl_stmt|;
define|#
directive|define
name|ISCSI_DATA_PDU_HDR_LITTLE_ENDIAN_RSRV1
value|(0x7F<<0)
comment|/* BitField op_attr	 */
define|#
directive|define
name|ISCSI_DATA_PDU_HDR_LITTLE_ENDIAN_RSRV1_SHIFT
value|0
define|#
directive|define
name|ISCSI_DATA_PDU_HDR_LITTLE_ENDIAN_FINAL_FLAG
value|(0x1<<7)
comment|/* BitField op_attr	 */
define|#
directive|define
name|ISCSI_DATA_PDU_HDR_LITTLE_ENDIAN_FINAL_FLAG_SHIFT
value|7
name|uint16_t
name|rsrv0
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|rsrv0
decl_stmt|;
name|uint8_t
name|op_attr
decl_stmt|;
define|#
directive|define
name|ISCSI_DATA_PDU_HDR_LITTLE_ENDIAN_RSRV1
value|(0x7F<<0)
comment|/* BitField op_attr	 */
define|#
directive|define
name|ISCSI_DATA_PDU_HDR_LITTLE_ENDIAN_RSRV1_SHIFT
value|0
define|#
directive|define
name|ISCSI_DATA_PDU_HDR_LITTLE_ENDIAN_FINAL_FLAG
value|(0x1<<7)
comment|/* BitField op_attr	 */
define|#
directive|define
name|ISCSI_DATA_PDU_HDR_LITTLE_ENDIAN_FINAL_FLAG_SHIFT
value|7
name|uint8_t
name|opcode
decl_stmt|;
endif|#
directive|endif
name|uint32_t
name|data_fields
decl_stmt|;
define|#
directive|define
name|ISCSI_DATA_PDU_HDR_LITTLE_ENDIAN_DATA_SEGMENT_LENGTH
value|(0xFFFFFF<<0)
comment|/* BitField data_fields	 */
define|#
directive|define
name|ISCSI_DATA_PDU_HDR_LITTLE_ENDIAN_DATA_SEGMENT_LENGTH_SHIFT
value|0
define|#
directive|define
name|ISCSI_DATA_PDU_HDR_LITTLE_ENDIAN_TOTAL_AHS_LENGTH
value|(0xFF<<24)
comment|/* BitField data_fields	 */
define|#
directive|define
name|ISCSI_DATA_PDU_HDR_LITTLE_ENDIAN_TOTAL_AHS_LENGTH_SHIFT
value|24
name|struct
name|regpair_t
name|lun
decl_stmt|;
name|uint32_t
name|itt
decl_stmt|;
name|uint32_t
name|ttt
decl_stmt|;
name|uint32_t
name|rsrv2
decl_stmt|;
name|uint32_t
name|exp_stat_sn
decl_stmt|;
name|uint32_t
name|rsrv3
decl_stmt|;
name|uint32_t
name|data_sn
decl_stmt|;
name|uint32_t
name|buffer_offset
decl_stmt|;
name|uint32_t
name|rsrv4
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * PDU header of an iSCSI login request  */
end_comment

begin_struct
struct|struct
name|iscsi_login_req_hdr_little_endian
block|{
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint8_t
name|opcode
decl_stmt|;
name|uint8_t
name|op_attr
decl_stmt|;
define|#
directive|define
name|ISCSI_LOGIN_REQ_HDR_LITTLE_ENDIAN_NSG
value|(0x3<<0)
comment|/* BitField op_attr	 */
define|#
directive|define
name|ISCSI_LOGIN_REQ_HDR_LITTLE_ENDIAN_NSG_SHIFT
value|0
define|#
directive|define
name|ISCSI_LOGIN_REQ_HDR_LITTLE_ENDIAN_CSG
value|(0x3<<2)
comment|/* BitField op_attr	 */
define|#
directive|define
name|ISCSI_LOGIN_REQ_HDR_LITTLE_ENDIAN_CSG_SHIFT
value|2
define|#
directive|define
name|ISCSI_LOGIN_REQ_HDR_LITTLE_ENDIAN_RSRV0
value|(0x3<<4)
comment|/* BitField op_attr	 */
define|#
directive|define
name|ISCSI_LOGIN_REQ_HDR_LITTLE_ENDIAN_RSRV0_SHIFT
value|4
define|#
directive|define
name|ISCSI_LOGIN_REQ_HDR_LITTLE_ENDIAN_CONTINUE_FLG
value|(0x1<<6)
comment|/* BitField op_attr	 */
define|#
directive|define
name|ISCSI_LOGIN_REQ_HDR_LITTLE_ENDIAN_CONTINUE_FLG_SHIFT
value|6
define|#
directive|define
name|ISCSI_LOGIN_REQ_HDR_LITTLE_ENDIAN_TRANSIT
value|(0x1<<7)
comment|/* BitField op_attr	 */
define|#
directive|define
name|ISCSI_LOGIN_REQ_HDR_LITTLE_ENDIAN_TRANSIT_SHIFT
value|7
name|uint8_t
name|version_max
decl_stmt|;
name|uint8_t
name|version_min
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint8_t
name|version_min
decl_stmt|;
name|uint8_t
name|version_max
decl_stmt|;
name|uint8_t
name|op_attr
decl_stmt|;
define|#
directive|define
name|ISCSI_LOGIN_REQ_HDR_LITTLE_ENDIAN_NSG
value|(0x3<<0)
comment|/* BitField op_attr	 */
define|#
directive|define
name|ISCSI_LOGIN_REQ_HDR_LITTLE_ENDIAN_NSG_SHIFT
value|0
define|#
directive|define
name|ISCSI_LOGIN_REQ_HDR_LITTLE_ENDIAN_CSG
value|(0x3<<2)
comment|/* BitField op_attr	 */
define|#
directive|define
name|ISCSI_LOGIN_REQ_HDR_LITTLE_ENDIAN_CSG_SHIFT
value|2
define|#
directive|define
name|ISCSI_LOGIN_REQ_HDR_LITTLE_ENDIAN_RSRV0
value|(0x3<<4)
comment|/* BitField op_attr	 */
define|#
directive|define
name|ISCSI_LOGIN_REQ_HDR_LITTLE_ENDIAN_RSRV0_SHIFT
value|4
define|#
directive|define
name|ISCSI_LOGIN_REQ_HDR_LITTLE_ENDIAN_CONTINUE_FLG
value|(0x1<<6)
comment|/* BitField op_attr	 */
define|#
directive|define
name|ISCSI_LOGIN_REQ_HDR_LITTLE_ENDIAN_CONTINUE_FLG_SHIFT
value|6
define|#
directive|define
name|ISCSI_LOGIN_REQ_HDR_LITTLE_ENDIAN_TRANSIT
value|(0x1<<7)
comment|/* BitField op_attr	 */
define|#
directive|define
name|ISCSI_LOGIN_REQ_HDR_LITTLE_ENDIAN_TRANSIT_SHIFT
value|7
name|uint8_t
name|opcode
decl_stmt|;
endif|#
directive|endif
name|uint32_t
name|data_fields
decl_stmt|;
define|#
directive|define
name|ISCSI_LOGIN_REQ_HDR_LITTLE_ENDIAN_DATA_SEGMENT_LENGTH
value|(0xFFFFFF<<0)
comment|/* BitField data_fields	 */
define|#
directive|define
name|ISCSI_LOGIN_REQ_HDR_LITTLE_ENDIAN_DATA_SEGMENT_LENGTH_SHIFT
value|0
define|#
directive|define
name|ISCSI_LOGIN_REQ_HDR_LITTLE_ENDIAN_TOTAL_AHS_LENGTH
value|(0xFF<<24)
comment|/* BitField data_fields	 */
define|#
directive|define
name|ISCSI_LOGIN_REQ_HDR_LITTLE_ENDIAN_TOTAL_AHS_LENGTH_SHIFT
value|24
name|uint32_t
name|isid_lo
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|isid_hi
decl_stmt|;
name|uint16_t
name|tsih
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|tsih
decl_stmt|;
name|uint16_t
name|isid_hi
decl_stmt|;
endif|#
directive|endif
name|uint32_t
name|itt
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|cid
decl_stmt|;
name|uint16_t
name|rsrv1
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|rsrv1
decl_stmt|;
name|uint16_t
name|cid
decl_stmt|;
endif|#
directive|endif
name|uint32_t
name|cmd_sn
decl_stmt|;
name|uint32_t
name|exp_stat_sn
decl_stmt|;
name|uint32_t
name|rsrv2
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * PDU header of an iSCSI logout request  */
end_comment

begin_struct
struct|struct
name|iscsi_logout_req_hdr_little_endian
block|{
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint8_t
name|opcode
decl_stmt|;
name|uint8_t
name|op_attr
decl_stmt|;
define|#
directive|define
name|ISCSI_LOGOUT_REQ_HDR_LITTLE_ENDIAN_REASON_CODE
value|(0x7F<<0)
comment|/* BitField op_attr	 */
define|#
directive|define
name|ISCSI_LOGOUT_REQ_HDR_LITTLE_ENDIAN_REASON_CODE_SHIFT
value|0
define|#
directive|define
name|ISCSI_LOGOUT_REQ_HDR_LITTLE_ENDIAN_RSRV1_1
value|(0x1<<7)
comment|/* BitField op_attr	this value must be 1 */
define|#
directive|define
name|ISCSI_LOGOUT_REQ_HDR_LITTLE_ENDIAN_RSRV1_1_SHIFT
value|7
name|uint16_t
name|rsrv0
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|rsrv0
decl_stmt|;
name|uint8_t
name|op_attr
decl_stmt|;
define|#
directive|define
name|ISCSI_LOGOUT_REQ_HDR_LITTLE_ENDIAN_REASON_CODE
value|(0x7F<<0)
comment|/* BitField op_attr	 */
define|#
directive|define
name|ISCSI_LOGOUT_REQ_HDR_LITTLE_ENDIAN_REASON_CODE_SHIFT
value|0
define|#
directive|define
name|ISCSI_LOGOUT_REQ_HDR_LITTLE_ENDIAN_RSRV1_1
value|(0x1<<7)
comment|/* BitField op_attr	this value must be 1 */
define|#
directive|define
name|ISCSI_LOGOUT_REQ_HDR_LITTLE_ENDIAN_RSRV1_1_SHIFT
value|7
name|uint8_t
name|opcode
decl_stmt|;
endif|#
directive|endif
name|uint32_t
name|data_fields
decl_stmt|;
define|#
directive|define
name|ISCSI_LOGOUT_REQ_HDR_LITTLE_ENDIAN_DATA_SEGMENT_LENGTH
value|(0xFFFFFF<<0)
comment|/* BitField data_fields	 */
define|#
directive|define
name|ISCSI_LOGOUT_REQ_HDR_LITTLE_ENDIAN_DATA_SEGMENT_LENGTH_SHIFT
value|0
define|#
directive|define
name|ISCSI_LOGOUT_REQ_HDR_LITTLE_ENDIAN_TOTAL_AHS_LENGTH
value|(0xFF<<24)
comment|/* BitField data_fields	 */
define|#
directive|define
name|ISCSI_LOGOUT_REQ_HDR_LITTLE_ENDIAN_TOTAL_AHS_LENGTH_SHIFT
value|24
name|uint32_t
name|rsrv2
index|[
literal|2
index|]
decl_stmt|;
name|uint32_t
name|itt
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|cid
decl_stmt|;
name|uint16_t
name|rsrv1
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|rsrv1
decl_stmt|;
name|uint16_t
name|cid
decl_stmt|;
endif|#
directive|endif
name|uint32_t
name|cmd_sn
decl_stmt|;
name|uint32_t
name|exp_stat_sn
decl_stmt|;
name|uint32_t
name|rsrv3
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * PDU header of an iSCSI TMF request  */
end_comment

begin_struct
struct|struct
name|iscsi_tmf_req_hdr_little_endian
block|{
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint8_t
name|opcode
decl_stmt|;
name|uint8_t
name|op_attr
decl_stmt|;
define|#
directive|define
name|ISCSI_TMF_REQ_HDR_LITTLE_ENDIAN_FUNCTION
value|(0x7F<<0)
comment|/* BitField op_attr	 */
define|#
directive|define
name|ISCSI_TMF_REQ_HDR_LITTLE_ENDIAN_FUNCTION_SHIFT
value|0
define|#
directive|define
name|ISCSI_TMF_REQ_HDR_LITTLE_ENDIAN_RSRV1_1
value|(0x1<<7)
comment|/* BitField op_attr	this value must be 1 */
define|#
directive|define
name|ISCSI_TMF_REQ_HDR_LITTLE_ENDIAN_RSRV1_1_SHIFT
value|7
name|uint16_t
name|rsrv0
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|rsrv0
decl_stmt|;
name|uint8_t
name|op_attr
decl_stmt|;
define|#
directive|define
name|ISCSI_TMF_REQ_HDR_LITTLE_ENDIAN_FUNCTION
value|(0x7F<<0)
comment|/* BitField op_attr	 */
define|#
directive|define
name|ISCSI_TMF_REQ_HDR_LITTLE_ENDIAN_FUNCTION_SHIFT
value|0
define|#
directive|define
name|ISCSI_TMF_REQ_HDR_LITTLE_ENDIAN_RSRV1_1
value|(0x1<<7)
comment|/* BitField op_attr	this value must be 1 */
define|#
directive|define
name|ISCSI_TMF_REQ_HDR_LITTLE_ENDIAN_RSRV1_1_SHIFT
value|7
name|uint8_t
name|opcode
decl_stmt|;
endif|#
directive|endif
name|uint32_t
name|data_fields
decl_stmt|;
define|#
directive|define
name|ISCSI_TMF_REQ_HDR_LITTLE_ENDIAN_DATA_SEGMENT_LENGTH
value|(0xFFFFFF<<0)
comment|/* BitField data_fields	 */
define|#
directive|define
name|ISCSI_TMF_REQ_HDR_LITTLE_ENDIAN_DATA_SEGMENT_LENGTH_SHIFT
value|0
define|#
directive|define
name|ISCSI_TMF_REQ_HDR_LITTLE_ENDIAN_TOTAL_AHS_LENGTH
value|(0xFF<<24)
comment|/* BitField data_fields	 */
define|#
directive|define
name|ISCSI_TMF_REQ_HDR_LITTLE_ENDIAN_TOTAL_AHS_LENGTH_SHIFT
value|24
name|struct
name|regpair_t
name|lun
decl_stmt|;
name|uint32_t
name|itt
decl_stmt|;
name|uint32_t
name|referenced_task_tag
decl_stmt|;
name|uint32_t
name|cmd_sn
decl_stmt|;
name|uint32_t
name|exp_stat_sn
decl_stmt|;
name|uint32_t
name|ref_cmd_sn
decl_stmt|;
name|uint32_t
name|exp_data_sn
decl_stmt|;
name|uint32_t
name|rsrv2
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * PDU header of an iSCSI Text request  */
end_comment

begin_struct
struct|struct
name|iscsi_text_req_hdr_little_endian
block|{
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint8_t
name|opcode
decl_stmt|;
name|uint8_t
name|op_attr
decl_stmt|;
define|#
directive|define
name|ISCSI_TEXT_REQ_HDR_LITTLE_ENDIAN_RSRV1
value|(0x3F<<0)
comment|/* BitField op_attr	 */
define|#
directive|define
name|ISCSI_TEXT_REQ_HDR_LITTLE_ENDIAN_RSRV1_SHIFT
value|0
define|#
directive|define
name|ISCSI_TEXT_REQ_HDR_LITTLE_ENDIAN_CONTINUE_FLG
value|(0x1<<6)
comment|/* BitField op_attr	 */
define|#
directive|define
name|ISCSI_TEXT_REQ_HDR_LITTLE_ENDIAN_CONTINUE_FLG_SHIFT
value|6
define|#
directive|define
name|ISCSI_TEXT_REQ_HDR_LITTLE_ENDIAN_FINAL
value|(0x1<<7)
comment|/* BitField op_attr	 */
define|#
directive|define
name|ISCSI_TEXT_REQ_HDR_LITTLE_ENDIAN_FINAL_SHIFT
value|7
name|uint16_t
name|rsrv0
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|rsrv0
decl_stmt|;
name|uint8_t
name|op_attr
decl_stmt|;
define|#
directive|define
name|ISCSI_TEXT_REQ_HDR_LITTLE_ENDIAN_RSRV1
value|(0x3F<<0)
comment|/* BitField op_attr	 */
define|#
directive|define
name|ISCSI_TEXT_REQ_HDR_LITTLE_ENDIAN_RSRV1_SHIFT
value|0
define|#
directive|define
name|ISCSI_TEXT_REQ_HDR_LITTLE_ENDIAN_CONTINUE_FLG
value|(0x1<<6)
comment|/* BitField op_attr	 */
define|#
directive|define
name|ISCSI_TEXT_REQ_HDR_LITTLE_ENDIAN_CONTINUE_FLG_SHIFT
value|6
define|#
directive|define
name|ISCSI_TEXT_REQ_HDR_LITTLE_ENDIAN_FINAL
value|(0x1<<7)
comment|/* BitField op_attr	 */
define|#
directive|define
name|ISCSI_TEXT_REQ_HDR_LITTLE_ENDIAN_FINAL_SHIFT
value|7
name|uint8_t
name|opcode
decl_stmt|;
endif|#
directive|endif
name|uint32_t
name|data_fields
decl_stmt|;
define|#
directive|define
name|ISCSI_TEXT_REQ_HDR_LITTLE_ENDIAN_DATA_SEGMENT_LENGTH
value|(0xFFFFFF<<0)
comment|/* BitField data_fields	 */
define|#
directive|define
name|ISCSI_TEXT_REQ_HDR_LITTLE_ENDIAN_DATA_SEGMENT_LENGTH_SHIFT
value|0
define|#
directive|define
name|ISCSI_TEXT_REQ_HDR_LITTLE_ENDIAN_TOTAL_AHS_LENGTH
value|(0xFF<<24)
comment|/* BitField data_fields	 */
define|#
directive|define
name|ISCSI_TEXT_REQ_HDR_LITTLE_ENDIAN_TOTAL_AHS_LENGTH_SHIFT
value|24
name|struct
name|regpair_t
name|lun
decl_stmt|;
name|uint32_t
name|itt
decl_stmt|;
name|uint32_t
name|ttt
decl_stmt|;
name|uint32_t
name|cmd_sn
decl_stmt|;
name|uint32_t
name|exp_stat_sn
decl_stmt|;
name|uint32_t
name|rsrv3
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * PDU header of an iSCSI Nop-Out  */
end_comment

begin_struct
struct|struct
name|iscsi_nop_out_hdr_little_endian
block|{
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint8_t
name|opcode
decl_stmt|;
name|uint8_t
name|op_attr
decl_stmt|;
define|#
directive|define
name|ISCSI_NOP_OUT_HDR_LITTLE_ENDIAN_RSRV1
value|(0x7F<<0)
comment|/* BitField op_attr	 */
define|#
directive|define
name|ISCSI_NOP_OUT_HDR_LITTLE_ENDIAN_RSRV1_SHIFT
value|0
define|#
directive|define
name|ISCSI_NOP_OUT_HDR_LITTLE_ENDIAN_RSRV2_1
value|(0x1<<7)
comment|/* BitField op_attr	this reserved bit must be set to 1 */
define|#
directive|define
name|ISCSI_NOP_OUT_HDR_LITTLE_ENDIAN_RSRV2_1_SHIFT
value|7
name|uint16_t
name|rsrv0
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|rsrv0
decl_stmt|;
name|uint8_t
name|op_attr
decl_stmt|;
define|#
directive|define
name|ISCSI_NOP_OUT_HDR_LITTLE_ENDIAN_RSRV1
value|(0x7F<<0)
comment|/* BitField op_attr	 */
define|#
directive|define
name|ISCSI_NOP_OUT_HDR_LITTLE_ENDIAN_RSRV1_SHIFT
value|0
define|#
directive|define
name|ISCSI_NOP_OUT_HDR_LITTLE_ENDIAN_RSRV2_1
value|(0x1<<7)
comment|/* BitField op_attr	this reserved bit must be set to 1 */
define|#
directive|define
name|ISCSI_NOP_OUT_HDR_LITTLE_ENDIAN_RSRV2_1_SHIFT
value|7
name|uint8_t
name|opcode
decl_stmt|;
endif|#
directive|endif
name|uint32_t
name|data_fields
decl_stmt|;
define|#
directive|define
name|ISCSI_NOP_OUT_HDR_LITTLE_ENDIAN_DATA_SEGMENT_LENGTH
value|(0xFFFFFF<<0)
comment|/* BitField data_fields	 */
define|#
directive|define
name|ISCSI_NOP_OUT_HDR_LITTLE_ENDIAN_DATA_SEGMENT_LENGTH_SHIFT
value|0
define|#
directive|define
name|ISCSI_NOP_OUT_HDR_LITTLE_ENDIAN_TOTAL_AHS_LENGTH
value|(0xFF<<24)
comment|/* BitField data_fields	 */
define|#
directive|define
name|ISCSI_NOP_OUT_HDR_LITTLE_ENDIAN_TOTAL_AHS_LENGTH_SHIFT
value|24
name|struct
name|regpair_t
name|lun
decl_stmt|;
name|uint32_t
name|itt
decl_stmt|;
name|uint32_t
name|ttt
decl_stmt|;
name|uint32_t
name|cmd_sn
decl_stmt|;
name|uint32_t
name|exp_stat_sn
decl_stmt|;
name|uint32_t
name|rsrv3
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * iscsi pdu headers in little endian form.  */
end_comment

begin_union
union|union
name|iscsi_pdu_headers_little_endian
block|{
name|uint32_t
name|fullHeaderSize
index|[
literal|12
index|]
comment|/* The full size of the header. protects the union size */
decl_stmt|;
name|struct
name|iscsi_cmd_pdu_hdr_little_endian
name|command_pdu_hdr
comment|/* PDU header of an iSCSI command - read,write  */
decl_stmt|;
name|struct
name|iscsi_data_pdu_hdr_little_endian
name|data_out_pdu_hdr
comment|/* PDU header of an iSCSI DATA-IN and DATA-OUT PDU  */
decl_stmt|;
name|struct
name|iscsi_login_req_hdr_little_endian
name|login_req_pdu_hdr
comment|/* PDU header of an iSCSI Login request */
decl_stmt|;
name|struct
name|iscsi_logout_req_hdr_little_endian
name|logout_req_pdu_hdr
comment|/* PDU header of an iSCSI Logout request */
decl_stmt|;
name|struct
name|iscsi_tmf_req_hdr_little_endian
name|tmf_req_pdu_hdr
comment|/* PDU header of an iSCSI TMF request */
decl_stmt|;
name|struct
name|iscsi_text_req_hdr_little_endian
name|text_req_pdu_hdr
comment|/* PDU header of an iSCSI Text request */
decl_stmt|;
name|struct
name|iscsi_nop_out_hdr_little_endian
name|nop_out_pdu_hdr
comment|/* PDU header of an iSCSI Nop-Out */
decl_stmt|;
block|}
union|;
end_union

begin_struct
struct|struct
name|iscsi_hq_bd
block|{
name|union
name|iscsi_pdu_headers_little_endian
name|pdu_header
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|reserved1
decl_stmt|;
name|uint16_t
name|lcl_cmp_flg
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|lcl_cmp_flg
decl_stmt|;
name|uint16_t
name|reserved1
decl_stmt|;
endif|#
directive|endif
name|uint32_t
name|sgl_base_lo
decl_stmt|;
name|uint32_t
name|sgl_base_hi
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint8_t
name|sgl_size
decl_stmt|;
name|uint8_t
name|sge_index
decl_stmt|;
name|uint16_t
name|sge_offset
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|sge_offset
decl_stmt|;
name|uint8_t
name|sge_index
decl_stmt|;
name|uint8_t
name|sgl_size
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/*  * CQE data for L2 OOO connection $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|iscsi_l2_ooo_data
block|{
name|uint32_t
name|iscsi_cid
comment|/* iSCSI context ID  */
decl_stmt|;
name|uint8_t
name|drop_isle
comment|/* isle number of the first isle to drop */
decl_stmt|;
name|uint8_t
name|drop_size
comment|/* number of isles to drop */
decl_stmt|;
name|uint8_t
name|ooo_opcode
comment|/* Out Of Order opcode (use enum tcp_ooo_event */
decl_stmt|;
name|uint8_t
name|ooo_isle
comment|/* OOO isle number to add the packet to */
decl_stmt|;
name|uint8_t
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
name|iscsi_task_context_entry_xuc_c_write_only
block|{
name|uint32_t
name|total_data_acked
comment|/* Xstorm inits to zero. C increments. U validates  */
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|iscsi_task_context_r2t_table_entry
block|{
name|uint32_t
name|ttt
decl_stmt|;
name|uint32_t
name|desired_data_len
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|iscsi_task_context_entry_xuc_u_write_only
block|{
name|uint32_t
name|exp_r2t_sn
comment|/* Xstorm inits to zero. U increments. */
decl_stmt|;
name|struct
name|iscsi_task_context_r2t_table_entry
name|r2t_table
index|[
literal|4
index|]
comment|/* U updates. X reads */
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|data_in_count
comment|/* X inits to zero. U increments. */
decl_stmt|;
name|uint8_t
name|cq_id
comment|/* X inits to zero. U uses. */
decl_stmt|;
name|uint8_t
name|valid_1b
comment|/* X sets. U resets. */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint8_t
name|valid_1b
comment|/* X sets. U resets. */
decl_stmt|;
name|uint8_t
name|cq_id
comment|/* X inits to zero. U uses. */
decl_stmt|;
name|uint16_t
name|data_in_count
comment|/* X inits to zero. U increments. */
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_struct
struct|struct
name|iscsi_task_context_entry_xuc
block|{
name|struct
name|iscsi_task_context_entry_xuc_c_write_only
name|write_c
comment|/* Cstorm only inits data here, without further change by any storm. */
decl_stmt|;
name|uint32_t
name|exp_data_transfer_len
comment|/* Xstorm only inits data here. */
decl_stmt|;
name|struct
name|iscsi_task_context_entry_xuc_x_write_only
name|write_x
comment|/* only Xstorm writes data here. */
decl_stmt|;
name|uint32_t
name|lun_lo
comment|/* Xstorm only inits data here. */
decl_stmt|;
name|struct
name|iscsi_task_context_entry_xuc_xu_write_both
name|write_xu
comment|/* Both X and U update this struct, but in different flow. */
decl_stmt|;
name|uint32_t
name|lun_hi
comment|/* Xstorm only inits data here. */
decl_stmt|;
name|struct
name|iscsi_task_context_entry_xuc_u_write_only
name|write_u
comment|/* Ustorm only inits data here, without further change by any storm. */
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|iscsi_task_context_entry_u
block|{
name|uint32_t
name|exp_r2t_buff_offset
decl_stmt|;
name|uint32_t
name|rem_rcv_len
decl_stmt|;
name|uint32_t
name|exp_data_sn
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|iscsi_task_context_entry
block|{
name|struct
name|iscsi_task_context_entry_x
name|tce_x
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|data_out_count
decl_stmt|;
name|uint16_t
name|rsrv0
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|rsrv0
decl_stmt|;
name|uint16_t
name|data_out_count
decl_stmt|;
endif|#
directive|endif
name|struct
name|iscsi_task_context_entry_xuc
name|tce_xuc
decl_stmt|;
name|struct
name|iscsi_task_context_entry_u
name|tce_u
decl_stmt|;
name|uint32_t
name|rsrv1
index|[
literal|7
index|]
comment|/* increase the size to 128 bytes */
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|iscsi_task_context_entry_xuc_x_init_only
block|{
name|struct
name|regpair_t
name|lun
comment|/* X inits. U validates */
decl_stmt|;
name|uint32_t
name|exp_data_transfer_len
comment|/* Xstorm inits to SQ WQE data. U validates */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The data afex vif list ramrod need $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|afex_vif_list_ramrod_data
block|{
name|uint8_t
name|afex_vif_list_command
comment|/* set get, clear all a VIF list id defined by enum vif_list_rule_kind */
decl_stmt|;
name|uint8_t
name|func_bit_map
comment|/* the function bit map to set */
decl_stmt|;
name|uint16_t
name|vif_list_index
comment|/* the VIF list, in a per pf vector  to add this function to */
decl_stmt|;
name|uint8_t
name|func_to_clear
comment|/* the func id to clear in case of clear func mode */
decl_stmt|;
name|uint8_t
name|echo
decl_stmt|;
name|uint16_t
name|reserved1
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  *  $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|c2s_pri_trans_table_entry
block|{
name|uint8_t
name|val
index|[
name|MAX_VLAN_PRIORITIES
index|]
comment|/* Inner to outer vlan priority translation table entry for current PF */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * cfc delete event data  $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|cfc_del_event_data
block|{
name|uint32_t
name|cid
comment|/* cid of deleted connection */
decl_stmt|;
name|uint32_t
name|reserved0
decl_stmt|;
name|uint32_t
name|reserved1
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * per-port SAFC demo variables  */
end_comment

begin_struct
struct|struct
name|cmng_flags_per_port
block|{
name|uint32_t
name|cmng_enables
decl_stmt|;
define|#
directive|define
name|CMNG_FLAGS_PER_PORT_FAIRNESS_VN
value|(0x1<<0)
comment|/* BitField cmng_enablesenables flag for fairness and rate shaping between protocols, vnics and COSes	if set, enable fairness between vnics */
define|#
directive|define
name|CMNG_FLAGS_PER_PORT_FAIRNESS_VN_SHIFT
value|0
define|#
directive|define
name|CMNG_FLAGS_PER_PORT_RATE_SHAPING_VN
value|(0x1<<1)
comment|/* BitField cmng_enablesenables flag for fairness and rate shaping between protocols, vnics and COSes	if set, enable rate shaping between vnics */
define|#
directive|define
name|CMNG_FLAGS_PER_PORT_RATE_SHAPING_VN_SHIFT
value|1
define|#
directive|define
name|CMNG_FLAGS_PER_PORT_FAIRNESS_COS
value|(0x1<<2)
comment|/* BitField cmng_enablesenables flag for fairness and rate shaping between protocols, vnics and COSes	if set, enable fairness between COSes */
define|#
directive|define
name|CMNG_FLAGS_PER_PORT_FAIRNESS_COS_SHIFT
value|2
define|#
directive|define
name|CMNG_FLAGS_PER_PORT_FAIRNESS_COS_MODE
value|(0x1<<3)
comment|/* BitField cmng_enablesenables flag for fairness and rate shaping between protocols, vnics and COSes	 (use enum fairness_mode) */
define|#
directive|define
name|CMNG_FLAGS_PER_PORT_FAIRNESS_COS_MODE_SHIFT
value|3
define|#
directive|define
name|__CMNG_FLAGS_PER_PORT_RESERVED0
value|(0xFFFFFFF<<4)
comment|/* BitField cmng_enablesenables flag for fairness and rate shaping between protocols, vnics and COSes	reserved */
define|#
directive|define
name|__CMNG_FLAGS_PER_PORT_RESERVED0_SHIFT
value|4
name|uint32_t
name|__reserved1
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * per-port rate shaping variables  */
end_comment

begin_struct
struct|struct
name|rate_shaping_vars_per_port
block|{
name|uint32_t
name|rs_periodic_timeout
comment|/* timeout of periodic timer */
decl_stmt|;
name|uint32_t
name|rs_threshold
comment|/* threshold, below which we start to stop queues */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * per-port fairness variables  */
end_comment

begin_struct
struct|struct
name|fairness_vars_per_port
block|{
name|uint32_t
name|upper_bound
comment|/* Quota for a protocol/vnic */
decl_stmt|;
name|uint32_t
name|fair_threshold
comment|/* almost-empty threshold */
decl_stmt|;
name|uint32_t
name|fairness_timeout
comment|/* timeout of fairness timer */
decl_stmt|;
name|uint32_t
name|reserved0
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * per-port SAFC variables  */
end_comment

begin_struct
struct|struct
name|safc_struct_per_port
block|{
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|__reserved1
decl_stmt|;
name|uint8_t
name|__reserved0
decl_stmt|;
name|uint8_t
name|safc_timeout_usec
comment|/* timeout to stop queues on SAFC pause command */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint8_t
name|safc_timeout_usec
comment|/* timeout to stop queues on SAFC pause command */
decl_stmt|;
name|uint8_t
name|__reserved0
decl_stmt|;
name|uint16_t
name|__reserved1
decl_stmt|;
endif|#
directive|endif
name|uint8_t
name|cos_to_traffic_types
index|[
name|MAX_COS_NUMBER
index|]
comment|/* translate cos to service traffics types */
decl_stmt|;
name|uint16_t
name|cos_to_pause_mask
index|[
name|NUM_OF_SAFC_BITS
index|]
comment|/* QM pause mask for each class of service in the SAFC frame */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Per-port congestion management variables  */
end_comment

begin_struct
struct|struct
name|cmng_struct_per_port
block|{
name|struct
name|rate_shaping_vars_per_port
name|rs_vars
decl_stmt|;
name|struct
name|fairness_vars_per_port
name|fair_vars
decl_stmt|;
name|struct
name|safc_struct_per_port
name|safc_vars
decl_stmt|;
name|struct
name|cmng_flags_per_port
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * a single rate shaping counter. can be used as protocol or vnic counter  */
end_comment

begin_struct
struct|struct
name|rate_shaping_counter
block|{
name|uint32_t
name|quota
comment|/* Quota for a protocol/vnic */
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|__reserved0
decl_stmt|;
name|uint16_t
name|rate
comment|/* Vnic/Protocol rate in units of Mega-bits/sec */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|rate
comment|/* Vnic/Protocol rate in units of Mega-bits/sec */
decl_stmt|;
name|uint16_t
name|__reserved0
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/*  * per-vnic rate shaping variables  */
end_comment

begin_struct
struct|struct
name|rate_shaping_vars_per_vn
block|{
name|struct
name|rate_shaping_counter
name|vn_counter
comment|/* per-vnic counter */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * per-vnic fairness variables  */
end_comment

begin_struct
struct|struct
name|fairness_vars_per_vn
block|{
name|uint32_t
name|cos_credit_delta
index|[
name|MAX_COS_NUMBER
index|]
comment|/* used for incrementing the credit */
decl_stmt|;
name|uint32_t
name|vn_credit_delta
comment|/* used for incrementing the credit */
decl_stmt|;
name|uint32_t
name|__reserved0
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * cmng port init state  */
end_comment

begin_struct
struct|struct
name|cmng_vnic
block|{
name|struct
name|rate_shaping_vars_per_vn
name|vnic_max_rate
index|[
literal|4
index|]
decl_stmt|;
name|struct
name|fairness_vars_per_vn
name|vnic_min_rate
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * cmng port init state  */
end_comment

begin_struct
struct|struct
name|cmng_init
block|{
name|struct
name|cmng_struct_per_port
name|port
decl_stmt|;
name|struct
name|cmng_vnic
name|vnic
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * driver parameters for congestion management init, all rates are in Mbps  */
end_comment

begin_struct
struct|struct
name|cmng_init_input
block|{
name|uint32_t
name|port_rate
decl_stmt|;
name|uint16_t
name|vnic_min_rate
index|[
literal|4
index|]
comment|/* rates are in Mbps */
decl_stmt|;
name|uint16_t
name|vnic_max_rate
index|[
literal|4
index|]
comment|/* rates are in Mbps */
decl_stmt|;
name|uint16_t
name|cos_min_rate
index|[
name|MAX_COS_NUMBER
index|]
comment|/* rates are in Mbps */
decl_stmt|;
name|uint16_t
name|cos_to_pause_mask
index|[
name|MAX_COS_NUMBER
index|]
decl_stmt|;
name|struct
name|cmng_flags_per_port
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Protocol-common command ID for slow path elements  */
end_comment

begin_enum
enum|enum
name|common_spqe_cmd_id
block|{
name|RAMROD_CMD_ID_COMMON_UNUSED
block|,
name|RAMROD_CMD_ID_COMMON_FUNCTION_START
comment|/* Start a function (for PFs only) */
block|,
name|RAMROD_CMD_ID_COMMON_FUNCTION_STOP
comment|/* Stop a function (for PFs only) */
block|,
name|RAMROD_CMD_ID_COMMON_FUNCTION_UPDATE
comment|/* niv update function */
block|,
name|RAMROD_CMD_ID_COMMON_CFC_DEL
comment|/* Delete a connection from CFC */
block|,
name|RAMROD_CMD_ID_COMMON_CFC_DEL_WB
comment|/* Delete a connection from CFC (with write back) */
block|,
name|RAMROD_CMD_ID_COMMON_STAT_QUERY
comment|/* Collect statistics counters */
block|,
name|RAMROD_CMD_ID_COMMON_STOP_TRAFFIC
comment|/* Stop Tx traffic (before DCB updates) */
block|,
name|RAMROD_CMD_ID_COMMON_START_TRAFFIC
comment|/* Start Tx traffic (after DCB updates) */
block|,
name|RAMROD_CMD_ID_COMMON_AFEX_VIF_LISTS
comment|/* niv vif lists */
block|,
name|RAMROD_CMD_ID_COMMON_SET_TIMESYNC
comment|/* Set Timesync Parameters (E3 Only) */
block|,
name|MAX_COMMON_SPQE_CMD_ID
block|}
enum|;
end_enum

begin_comment
comment|/*  * Per-protocol connection types  */
end_comment

begin_enum
enum|enum
name|connection_type
block|{
name|ETH_CONNECTION_TYPE
comment|/* Ethernet */
block|,
name|TOE_CONNECTION_TYPE
comment|/* TOE */
block|,
name|RDMA_CONNECTION_TYPE
comment|/* RDMA */
block|,
name|ISCSI_CONNECTION_TYPE
comment|/* iSCSI */
block|,
name|FCOE_CONNECTION_TYPE
comment|/* FCoE */
block|,
name|RESERVED_CONNECTION_TYPE_0
block|,
name|RESERVED_CONNECTION_TYPE_1
block|,
name|RESERVED_CONNECTION_TYPE_2
block|,
name|NONE_CONNECTION_TYPE
comment|/* General- used for common slow path */
block|,
name|MAX_CONNECTION_TYPE
block|}
enum|;
end_enum

begin_comment
comment|/*  * Cos modes  */
end_comment

begin_enum
enum|enum
name|cos_mode
block|{
name|OVERRIDE_COS
comment|/* Firmware deduce cos according to DCB */
block|,
name|STATIC_COS
comment|/* Firmware has constant queues per CoS */
block|,
name|FW_WRR
comment|/* Firmware keep fairness between different CoSes */
block|,
name|MAX_COS_MODE
block|}
enum|;
end_enum

begin_comment
comment|/*  * Dynamic HC counters set by the driver  */
end_comment

begin_struct
struct|struct
name|hc_dynamic_drv_counter
block|{
name|uint32_t
name|val
index|[
name|HC_SB_MAX_DYNAMIC_INDICES
index|]
comment|/* 4 bytes * 4 indices = 2 lines */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * zone A per-queue data  */
end_comment

begin_struct
struct|struct
name|cstorm_queue_zone_data
block|{
name|struct
name|hc_dynamic_drv_counter
name|hc_dyn_drv_cnt
comment|/* 4 bytes * 4 indices = 2 lines */
decl_stmt|;
name|struct
name|regpair_t
name|reserved
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Vf-PF channel data in cstorm ram (non-triggered zone)  */
end_comment

begin_struct
struct|struct
name|vf_pf_channel_zone_data
block|{
name|uint32_t
name|msg_addr_lo
comment|/* the message address on VF memory */
decl_stmt|;
name|uint32_t
name|msg_addr_hi
comment|/* the message address on VF memory */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * zone for VF non-triggered data  */
end_comment

begin_struct
struct|struct
name|non_trigger_vf_zone
block|{
name|struct
name|vf_pf_channel_zone_data
name|vf_pf_channel
comment|/* vf-pf channel zone data */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Vf-PF channel trigger zone in cstorm ram  */
end_comment

begin_struct
struct|struct
name|vf_pf_channel_zone_trigger
block|{
name|uint8_t
name|addr_valid
comment|/* indicates that a vf-pf message is pending. MUST be set AFTER the message address.  */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * zone that triggers the in-bound interrupt  */
end_comment

begin_struct
struct|struct
name|trigger_vf_zone
block|{
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|reserved1
decl_stmt|;
name|uint8_t
name|reserved0
decl_stmt|;
name|struct
name|vf_pf_channel_zone_trigger
name|vf_pf_channel
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|struct
name|vf_pf_channel_zone_trigger
name|vf_pf_channel
decl_stmt|;
name|uint8_t
name|reserved0
decl_stmt|;
name|uint16_t
name|reserved1
decl_stmt|;
endif|#
directive|endif
name|uint32_t
name|reserved2
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * zone B per-VF data  */
end_comment

begin_struct
struct|struct
name|cstorm_vf_zone_data
block|{
name|struct
name|non_trigger_vf_zone
name|non_trigger
comment|/* zone for VF non-triggered data */
decl_stmt|;
name|struct
name|trigger_vf_zone
name|trigger
comment|/* zone that triggers the in-bound interrupt */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Dynamic host coalescing init parameters, per state machine  */
end_comment

begin_struct
struct|struct
name|dynamic_hc_sm_config
block|{
name|uint32_t
name|threshold
index|[
literal|3
index|]
comment|/* thresholds of number of outstanding bytes */
decl_stmt|;
name|uint8_t
name|shift_per_protocol
index|[
name|HC_SB_MAX_DYNAMIC_INDICES
index|]
comment|/* bytes difference of each protocol is shifted right by this value */
decl_stmt|;
name|uint8_t
name|hc_timeout0
index|[
name|HC_SB_MAX_DYNAMIC_INDICES
index|]
comment|/* timeout for level 0 for each protocol, in units of usec */
decl_stmt|;
name|uint8_t
name|hc_timeout1
index|[
name|HC_SB_MAX_DYNAMIC_INDICES
index|]
comment|/* timeout for level 1 for each protocol, in units of usec */
decl_stmt|;
name|uint8_t
name|hc_timeout2
index|[
name|HC_SB_MAX_DYNAMIC_INDICES
index|]
comment|/* timeout for level 2 for each protocol, in units of usec */
decl_stmt|;
name|uint8_t
name|hc_timeout3
index|[
name|HC_SB_MAX_DYNAMIC_INDICES
index|]
comment|/* timeout for level 3 for each protocol, in units of usec */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Dynamic host coalescing init parameters  */
end_comment

begin_struct
struct|struct
name|dynamic_hc_config
block|{
name|struct
name|dynamic_hc_sm_config
name|sm_config
index|[
name|HC_SB_MAX_SM
index|]
comment|/* Configuration per state machine */
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|e2_integ_data
block|{
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint8_t
name|flags
decl_stmt|;
define|#
directive|define
name|E2_INTEG_DATA_TESTING_EN
value|(0x1<<0)
comment|/* BitField flags	integration testing enabled */
define|#
directive|define
name|E2_INTEG_DATA_TESTING_EN_SHIFT
value|0
define|#
directive|define
name|E2_INTEG_DATA_LB_TX
value|(0x1<<1)
comment|/* BitField flags	flag indicating this connection will transmit on loopback */
define|#
directive|define
name|E2_INTEG_DATA_LB_TX_SHIFT
value|1
define|#
directive|define
name|E2_INTEG_DATA_COS_TX
value|(0x1<<2)
comment|/* BitField flags	flag indicating this connection will transmit according to cos field */
define|#
directive|define
name|E2_INTEG_DATA_COS_TX_SHIFT
value|2
define|#
directive|define
name|E2_INTEG_DATA_OPPORTUNISTICQM
value|(0x1<<3)
comment|/* BitField flags	flag indicating this connection will activate the opportunistic QM credit flow */
define|#
directive|define
name|E2_INTEG_DATA_OPPORTUNISTICQM_SHIFT
value|3
define|#
directive|define
name|E2_INTEG_DATA_DPMTESTRELEASEDQ
value|(0x1<<4)
comment|/* BitField flags	flag indicating this connection will release the door bell queue (DQ) */
define|#
directive|define
name|E2_INTEG_DATA_DPMTESTRELEASEDQ_SHIFT
value|4
define|#
directive|define
name|E2_INTEG_DATA_RESERVED
value|(0x7<<5)
comment|/* BitField flags	 */
define|#
directive|define
name|E2_INTEG_DATA_RESERVED_SHIFT
value|5
name|uint8_t
name|cos
comment|/* cos of the connection (relevant only in cos transmitting connections, when cosTx is set */
decl_stmt|;
name|uint8_t
name|voq
comment|/* voq to return credit on. Normally equal to port (i.e. always 0 in E2 operational connections). in cos tests equal to cos. in loopback tests equal to LB_PORT (=4) */
decl_stmt|;
name|uint8_t
name|pbf_queue
comment|/* pbf queue to transmit on. Normally equal to port (i.e. always 0 in E2 operational connections). in cos tests equal to cos. in loopback tests equal to LB_PORT (=4) */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint8_t
name|pbf_queue
comment|/* pbf queue to transmit on. Normally equal to port (i.e. always 0 in E2 operational connections). in cos tests equal to cos. in loopback tests equal to LB_PORT (=4) */
decl_stmt|;
name|uint8_t
name|voq
comment|/* voq to return credit on. Normally equal to port (i.e. always 0 in E2 operational connections). in cos tests equal to cos. in loopback tests equal to LB_PORT (=4) */
decl_stmt|;
name|uint8_t
name|cos
comment|/* cos of the connection (relevant only in cos transmitting connections, when cosTx is set */
decl_stmt|;
name|uint8_t
name|flags
decl_stmt|;
define|#
directive|define
name|E2_INTEG_DATA_TESTING_EN
value|(0x1<<0)
comment|/* BitField flags	integration testing enabled */
define|#
directive|define
name|E2_INTEG_DATA_TESTING_EN_SHIFT
value|0
define|#
directive|define
name|E2_INTEG_DATA_LB_TX
value|(0x1<<1)
comment|/* BitField flags	flag indicating this connection will transmit on loopback */
define|#
directive|define
name|E2_INTEG_DATA_LB_TX_SHIFT
value|1
define|#
directive|define
name|E2_INTEG_DATA_COS_TX
value|(0x1<<2)
comment|/* BitField flags	flag indicating this connection will transmit according to cos field */
define|#
directive|define
name|E2_INTEG_DATA_COS_TX_SHIFT
value|2
define|#
directive|define
name|E2_INTEG_DATA_OPPORTUNISTICQM
value|(0x1<<3)
comment|/* BitField flags	flag indicating this connection will activate the opportunistic QM credit flow */
define|#
directive|define
name|E2_INTEG_DATA_OPPORTUNISTICQM_SHIFT
value|3
define|#
directive|define
name|E2_INTEG_DATA_DPMTESTRELEASEDQ
value|(0x1<<4)
comment|/* BitField flags	flag indicating this connection will release the door bell queue (DQ) */
define|#
directive|define
name|E2_INTEG_DATA_DPMTESTRELEASEDQ_SHIFT
value|4
define|#
directive|define
name|E2_INTEG_DATA_RESERVED
value|(0x7<<5)
comment|/* BitField flags	 */
define|#
directive|define
name|E2_INTEG_DATA_RESERVED_SHIFT
value|5
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|reserved3
decl_stmt|;
name|uint8_t
name|reserved2
decl_stmt|;
name|uint8_t
name|ramEn
comment|/* context area reserved for reading enable bit from ram */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint8_t
name|ramEn
comment|/* context area reserved for reading enable bit from ram */
decl_stmt|;
name|uint8_t
name|reserved2
decl_stmt|;
name|uint16_t
name|reserved3
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/*  * set mac event data  $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|eth_event_data
block|{
name|uint32_t
name|echo
comment|/* set mac echo data to return to driver */
decl_stmt|;
name|uint32_t
name|reserved0
decl_stmt|;
name|uint32_t
name|reserved1
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * pf-vf event data  $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|vf_pf_event_data
block|{
name|uint8_t
name|vf_id
comment|/* VF ID (0-63) */
decl_stmt|;
name|uint8_t
name|reserved0
decl_stmt|;
name|uint16_t
name|reserved1
decl_stmt|;
name|uint32_t
name|msg_addr_lo
comment|/* message address on Vf (low 32 bits) */
decl_stmt|;
name|uint32_t
name|msg_addr_hi
comment|/* message address on Vf (high 32 bits) */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * VF FLR event data  $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|vf_flr_event_data
block|{
name|uint8_t
name|vf_id
comment|/* VF ID (0-63) */
decl_stmt|;
name|uint8_t
name|reserved0
decl_stmt|;
name|uint16_t
name|reserved1
decl_stmt|;
name|uint32_t
name|reserved2
decl_stmt|;
name|uint32_t
name|reserved3
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * malicious VF event data  $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|malicious_vf_event_data
block|{
name|uint8_t
name|vf_id
comment|/* VF ID (0-63) */
decl_stmt|;
name|uint8_t
name|err_id
comment|/* reason for malicious notification */
decl_stmt|;
name|uint16_t
name|reserved1
decl_stmt|;
name|uint32_t
name|reserved2
decl_stmt|;
name|uint32_t
name|reserved3
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * vif list event data  $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|vif_list_event_data
block|{
name|uint8_t
name|func_bit_map
comment|/* bit map of pf indice */
decl_stmt|;
name|uint8_t
name|echo
decl_stmt|;
name|uint16_t
name|reserved0
decl_stmt|;
name|uint32_t
name|reserved1
decl_stmt|;
name|uint32_t
name|reserved2
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * function update event data  $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|function_update_event_data
block|{
name|uint8_t
name|echo
decl_stmt|;
name|uint8_t
name|reserved
decl_stmt|;
name|uint16_t
name|reserved0
decl_stmt|;
name|uint32_t
name|reserved1
decl_stmt|;
name|uint32_t
name|reserved2
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * union for all event ring message types  */
end_comment

begin_union
union|union
name|event_data
block|{
name|struct
name|vf_pf_event_data
name|vf_pf_event
comment|/* vf-pf event data */
decl_stmt|;
name|struct
name|eth_event_data
name|eth_event
comment|/* set mac event data */
decl_stmt|;
name|struct
name|cfc_del_event_data
name|cfc_del_event
comment|/* cfc delete event data */
decl_stmt|;
name|struct
name|vf_flr_event_data
name|vf_flr_event
comment|/* vf flr event data */
decl_stmt|;
name|struct
name|malicious_vf_event_data
name|malicious_vf_event
comment|/* malicious vf event data */
decl_stmt|;
name|struct
name|vif_list_event_data
name|vif_list_event
comment|/* vif list event data */
decl_stmt|;
name|struct
name|function_update_event_data
name|function_update_event
comment|/* function update event data */
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/*  * per PF event ring data  */
end_comment

begin_struct
struct|struct
name|event_ring_data
block|{
name|struct
name|regpair_native_t
name|base_addr
comment|/* ring base address */
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint8_t
name|index_id
comment|/* index ID within the status block */
decl_stmt|;
name|uint8_t
name|sb_id
comment|/* status block ID */
decl_stmt|;
name|uint16_t
name|producer
comment|/* event ring producer */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|producer
comment|/* event ring producer */
decl_stmt|;
name|uint8_t
name|sb_id
comment|/* status block ID */
decl_stmt|;
name|uint8_t
name|index_id
comment|/* index ID within the status block */
decl_stmt|;
endif|#
directive|endif
name|uint32_t
name|reserved0
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * event ring message element (each element is 128 bits) $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|event_ring_msg
block|{
name|uint8_t
name|opcode
decl_stmt|;
name|uint8_t
name|error
comment|/* error on the mesasage */
decl_stmt|;
name|uint16_t
name|reserved1
decl_stmt|;
name|union
name|event_data
name|data
comment|/* message data (96 bits data) */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * event ring next page element (128 bits)  */
end_comment

begin_struct
struct|struct
name|event_ring_next
block|{
name|struct
name|regpair_t
name|addr
comment|/* Address of the next page of the ring */
decl_stmt|;
name|uint32_t
name|reserved
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * union for event ring element types (each element is 128 bits)  */
end_comment

begin_union
union|union
name|event_ring_elem
block|{
name|struct
name|event_ring_msg
name|message
comment|/* event ring message */
decl_stmt|;
name|struct
name|event_ring_next
name|next_page
comment|/* event ring next page */
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/*  * Common event ring opcodes  */
end_comment

begin_enum
enum|enum
name|event_ring_opcode
block|{
name|EVENT_RING_OPCODE_VF_PF_CHANNEL
block|,
name|EVENT_RING_OPCODE_FUNCTION_START
comment|/* Start a function (for PFs only) */
block|,
name|EVENT_RING_OPCODE_FUNCTION_STOP
comment|/* Stop a function (for PFs only) */
block|,
name|EVENT_RING_OPCODE_CFC_DEL
comment|/* Delete a connection from CFC */
block|,
name|EVENT_RING_OPCODE_CFC_DEL_WB
comment|/* Delete a connection from CFC (with write back) */
block|,
name|EVENT_RING_OPCODE_STAT_QUERY
comment|/* Collect statistics counters */
block|,
name|EVENT_RING_OPCODE_STOP_TRAFFIC
comment|/* Stop Tx traffic (before DCB updates) */
block|,
name|EVENT_RING_OPCODE_START_TRAFFIC
comment|/* Start Tx traffic (after DCB updates) */
block|,
name|EVENT_RING_OPCODE_VF_FLR
comment|/* VF FLR indication for PF */
block|,
name|EVENT_RING_OPCODE_MALICIOUS_VF
comment|/* Malicious VF operation detected */
block|,
name|EVENT_RING_OPCODE_FORWARD_SETUP
comment|/* Initialize forward channel */
block|,
name|EVENT_RING_OPCODE_RSS_UPDATE_RULES
comment|/* Update RSS configuration */
block|,
name|EVENT_RING_OPCODE_FUNCTION_UPDATE
comment|/* function update */
block|,
name|EVENT_RING_OPCODE_AFEX_VIF_LISTS
comment|/* event ring opcode niv vif lists */
block|,
name|EVENT_RING_OPCODE_SET_MAC
comment|/* Add/remove MAC (in E1x only) */
block|,
name|EVENT_RING_OPCODE_CLASSIFICATION_RULES
comment|/* Add/remove MAC or VLAN (in E2/E3 only) */
block|,
name|EVENT_RING_OPCODE_FILTERS_RULES
comment|/* Add/remove classification filters for L2 client (in E2/E3 only) */
block|,
name|EVENT_RING_OPCODE_MULTICAST_RULES
comment|/* Add/remove multicast classification bin (in E2/E3 only) */
block|,
name|EVENT_RING_OPCODE_SET_TIMESYNC
comment|/* Set Timesync Parameters (E3 Only) */
block|,
name|MAX_EVENT_RING_OPCODE
block|}
enum|;
end_enum

begin_comment
comment|/*  * Modes for fairness algorithm  */
end_comment

begin_enum
enum|enum
name|fairness_mode
block|{
name|FAIRNESS_COS_WRR_MODE
comment|/* Weighted round robin mode (used in Google) */
block|,
name|FAIRNESS_COS_ETS_MODE
comment|/* ETS mode (used in FCoE) */
block|,
name|MAX_FAIRNESS_MODE
block|}
enum|;
end_enum

begin_comment
comment|/*  * Priority and cos $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|priority_cos
block|{
name|uint8_t
name|priority
comment|/* Priority */
decl_stmt|;
name|uint8_t
name|cos
comment|/* Cos */
decl_stmt|;
name|uint16_t
name|reserved1
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The data for flow control configuration $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|flow_control_configuration
block|{
name|struct
name|priority_cos
name|traffic_type_to_priority_cos
index|[
name|MAX_TRAFFIC_TYPES
index|]
comment|/* traffic_type to priority cos */
decl_stmt|;
name|uint8_t
name|dcb_enabled
comment|/* If DCB mode is enabled then traffic class to priority array is fully initialized and there must be inner VLAN */
decl_stmt|;
name|uint8_t
name|dcb_version
comment|/* DCB version Increase by one on each DCB update */
decl_stmt|;
name|uint8_t
name|dont_add_pri_0
comment|/* In case, the priority is 0, and the packet has no vlan, the firmware wont add vlan */
decl_stmt|;
name|uint8_t
name|reserved1
decl_stmt|;
name|uint32_t
name|reserved2
decl_stmt|;
name|uint8_t
name|dcb_outer_pri
index|[
name|MAX_TRAFFIC_TYPES
index|]
comment|/* Indicates the updated DCB outer tag priority per protocol */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  *  $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|function_start_data
block|{
name|uint8_t
name|function_mode
comment|/* the function mode */
decl_stmt|;
name|uint8_t
name|allow_npar_tx_switching
comment|/* If set, inter-pf tx switching is allowed in Switch Independent function mode. (E2/E3 Only) */
decl_stmt|;
name|uint16_t
name|sd_vlan_tag
comment|/* value of Vlan in case of switch depended multi-function mode */
decl_stmt|;
name|uint16_t
name|vif_id
comment|/* value of VIF id in case of NIV multi-function mode */
decl_stmt|;
name|uint8_t
name|path_id
decl_stmt|;
name|uint8_t
name|network_cos_mode
comment|/* The cos mode for network traffic. */
decl_stmt|;
name|uint8_t
name|dmae_cmd_id
comment|/* The DMAE command id to use for FW DMAE transactions */
decl_stmt|;
name|uint8_t
name|no_added_tags
comment|/* If set, the mfTag length is always zero (used in UFP) */
decl_stmt|;
name|uint16_t
name|reserved0
decl_stmt|;
name|uint32_t
name|reserved1
decl_stmt|;
name|uint8_t
name|inner_clss_vxlan
comment|/* Classification type for VXLAN */
decl_stmt|;
name|uint8_t
name|inner_clss_l2gre
comment|/* If set, classification on the inner MAC/VLAN of L2GRE tunneled packets is enabled */
decl_stmt|;
name|uint8_t
name|inner_clss_l2geneve
comment|/* If set, classification on the inner MAC/(VLAN or VNI) of L2GENEVE tunneled packets is enabled */
decl_stmt|;
name|uint8_t
name|inner_rss
comment|/* If set, RSS on the inner headers of tunneled packets is enabled */
decl_stmt|;
name|uint16_t
name|vxlan_dst_port
comment|/* UDP Destination Port to be recognised as VXLAN tunneled packets (0 is disabled) */
decl_stmt|;
name|uint16_t
name|geneve_dst_port
comment|/* UDP Destination Port to be recognised as GENEVE tunneled packets (0 is disabled) */
decl_stmt|;
name|uint8_t
name|sd_accept_mf_clss_fail
comment|/* If set, accept packets that fail Multi-Function Switch-Dependent classification. Only one VNIC on the port can have this set to 1 */
decl_stmt|;
name|uint8_t
name|sd_accept_mf_clss_fail_match_ethtype
comment|/* If set, accepted packets must match the ethertype of sd_clss_fail_ethtype */
decl_stmt|;
name|uint16_t
name|sd_accept_mf_clss_fail_ethtype
comment|/* Ethertype to match in the case of sd_accept_mf_clss_fail_match_ethtype */
decl_stmt|;
name|uint16_t
name|sd_vlan_eth_type
comment|/* Value of ether-type to use in the case of switch dependent multi-function mode. Setting this to 0 uses the default value of 0x8100 */
decl_stmt|;
name|uint8_t
name|sd_vlan_force_pri_flg
comment|/* If set, the SD Vlan Priority is forced to the value of the sd_vlan_pri_force_val field regardless of the DCB or inband VLAN priority. */
decl_stmt|;
name|uint8_t
name|sd_vlan_force_pri_val
comment|/* value to force SD Vlan Priority if sd_vlan_pri_force_flg is set */
decl_stmt|;
name|uint8_t
name|c2s_pri_tt_valid
comment|/* When set, c2s_pri_trans_table is valid */
decl_stmt|;
name|uint8_t
name|c2s_pri_default
comment|/* This value will be the sVlan pri value in case no Cvlan is present */
decl_stmt|;
name|uint8_t
name|reserved2
index|[
literal|6
index|]
decl_stmt|;
name|struct
name|c2s_pri_trans_table_entry
name|c2s_pri_trans_table
comment|/* Inner to outer vlan priority translation table entry for current PF */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  *  $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|function_update_data
block|{
name|uint8_t
name|vif_id_change_flg
comment|/* If set, vif_id will be checked */
decl_stmt|;
name|uint8_t
name|afex_default_vlan_change_flg
comment|/* If set, afex_default_vlan will be checked */
decl_stmt|;
name|uint8_t
name|allowed_priorities_change_flg
comment|/* If set, allowed_priorities will be checked */
decl_stmt|;
name|uint8_t
name|network_cos_mode_change_flg
comment|/* If set, network_cos_mode will be checked */
decl_stmt|;
name|uint16_t
name|vif_id
comment|/* value of VIF id in case of NIV multi-function mode */
decl_stmt|;
name|uint16_t
name|afex_default_vlan
comment|/* value of default Vlan in case of NIV mf */
decl_stmt|;
name|uint8_t
name|allowed_priorities
comment|/* bit vector of allowed Vlan priorities for this VIF */
decl_stmt|;
name|uint8_t
name|network_cos_mode
comment|/* The cos mode for network traffic. */
decl_stmt|;
name|uint8_t
name|lb_mode_en_change_flg
comment|/* If set, lb_mode_en will be checked */
decl_stmt|;
name|uint8_t
name|lb_mode_en
comment|/* If set, niv loopback mode will be enabled */
decl_stmt|;
name|uint8_t
name|tx_switch_suspend_change_flg
comment|/* If set, tx_switch_suspend will be checked */
decl_stmt|;
name|uint8_t
name|tx_switch_suspend
comment|/* If set, TX switching TO this function will be disabled and packets will be dropped */
decl_stmt|;
name|uint8_t
name|echo
decl_stmt|;
name|uint8_t
name|update_tunn_cfg_flg
comment|/* If set, tunneling config for the function will be updated according to the following fields */
decl_stmt|;
name|uint8_t
name|inner_clss_vxlan
comment|/* Classification type for VXLAN */
decl_stmt|;
name|uint8_t
name|inner_clss_l2gre
comment|/* If set, classification on the inner MAC/VLAN of L2GRE tunneled packets is enabled */
decl_stmt|;
name|uint8_t
name|inner_clss_l2geneve
comment|/* If set, classification on the inner MAC/(VLAN or VNI) of L2GENEVE tunneled packets is enabled */
decl_stmt|;
name|uint8_t
name|inner_rss
comment|/* If set, RSS on the inner headers of tunneled packets is enabled */
decl_stmt|;
name|uint16_t
name|vxlan_dst_port
comment|/* UDP Destination Port to be recognised as VXLAN tunneled packets (0 is disabled) */
decl_stmt|;
name|uint16_t
name|geneve_dst_port
comment|/* UDP Destination Port to be recognised as GENEVE tunneled packets (0 is disabled) */
decl_stmt|;
name|uint8_t
name|sd_vlan_force_pri_change_flg
comment|/* If set, the SD VLAN Priority Fixed configuration is updated from fields sd_vlan_pri_force_flg and sd_vlan_pri_force_val */
decl_stmt|;
name|uint8_t
name|sd_vlan_force_pri_flg
comment|/* If set, the SD Vlan Priority is forced to the value of the sd_vlan_pri_force_val field regardless of the DCB or inband VLAN priority. */
decl_stmt|;
name|uint8_t
name|sd_vlan_force_pri_val
comment|/* value to force SD Vlan Priority if sd_vlan_pri_force_flg is set */
decl_stmt|;
name|uint8_t
name|sd_vlan_tag_change_flg
comment|/* If set, the SD VLAN Tag is changed according to the field sd_vlan_tag */
decl_stmt|;
name|uint8_t
name|sd_vlan_eth_type_change_flg
comment|/* If set, the SD VLAN Ethertype is changed according to the field sd_vlan_eth_type */
decl_stmt|;
name|uint8_t
name|reserved1
decl_stmt|;
name|uint16_t
name|sd_vlan_tag
comment|/* New value of Outer Vlan in case of switch depended multi-function mode */
decl_stmt|;
name|uint16_t
name|sd_vlan_eth_type
comment|/* New value of ether-type in the case of switch dependent multi-function mode. Setting this to 0 restores the default value of 0x8100 */
decl_stmt|;
name|uint16_t
name|reserved0
decl_stmt|;
name|uint32_t
name|reserved2
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * FW version stored in the Xstorm RAM  */
end_comment

begin_struct
struct|struct
name|fw_version
block|{
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint8_t
name|engineering
comment|/* firmware current engineering version */
decl_stmt|;
name|uint8_t
name|revision
comment|/* firmware current revision version */
decl_stmt|;
name|uint8_t
name|minor
comment|/* firmware current minor version */
decl_stmt|;
name|uint8_t
name|major
comment|/* firmware current major version */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint8_t
name|major
comment|/* firmware current major version */
decl_stmt|;
name|uint8_t
name|minor
comment|/* firmware current minor version */
decl_stmt|;
name|uint8_t
name|revision
comment|/* firmware current revision version */
decl_stmt|;
name|uint8_t
name|engineering
comment|/* firmware current engineering version */
decl_stmt|;
endif|#
directive|endif
name|uint32_t
name|flags
decl_stmt|;
define|#
directive|define
name|FW_VERSION_OPTIMIZED
value|(0x1<<0)
comment|/* BitField flags	if set, this is optimized ASM */
define|#
directive|define
name|FW_VERSION_OPTIMIZED_SHIFT
value|0
define|#
directive|define
name|FW_VERSION_BIG_ENDIEN
value|(0x1<<1)
comment|/* BitField flags	if set, this is big-endien ASM */
define|#
directive|define
name|FW_VERSION_BIG_ENDIEN_SHIFT
value|1
define|#
directive|define
name|FW_VERSION_CHIP_VERSION
value|(0x3<<2)
comment|/* BitField flags	0 - E1, 1 - E1H */
define|#
directive|define
name|FW_VERSION_CHIP_VERSION_SHIFT
value|2
define|#
directive|define
name|__FW_VERSION_RESERVED
value|(0xFFFFFFF<<4)
comment|/* BitField flags	 */
define|#
directive|define
name|__FW_VERSION_RESERVED_SHIFT
value|4
block|}
struct|;
end_struct

begin_comment
comment|/*  * Dynamic Host-Coalescing - Driver(host) counters  */
end_comment

begin_struct
struct|struct
name|hc_dynamic_sb_drv_counters
block|{
name|uint32_t
name|dynamic_hc_drv_counter
index|[
name|HC_SB_MAX_DYNAMIC_INDICES
index|]
comment|/* Dynamic HC counters written by drivers */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * 2 bytes. configuration/state parameters for a single protocol index  */
end_comment

begin_struct
struct|struct
name|hc_index_data
block|{
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint8_t
name|flags
decl_stmt|;
define|#
directive|define
name|HC_INDEX_DATA_SM_ID
value|(0x1<<0)
comment|/* BitField flags	Index to a state machine. Can be 0 or 1 */
define|#
directive|define
name|HC_INDEX_DATA_SM_ID_SHIFT
value|0
define|#
directive|define
name|HC_INDEX_DATA_HC_ENABLED
value|(0x1<<1)
comment|/* BitField flags	if set, host coalescing would be done for this index */
define|#
directive|define
name|HC_INDEX_DATA_HC_ENABLED_SHIFT
value|1
define|#
directive|define
name|HC_INDEX_DATA_DYNAMIC_HC_ENABLED
value|(0x1<<2)
comment|/* BitField flags	if set, dynamic HC will be done for this index */
define|#
directive|define
name|HC_INDEX_DATA_DYNAMIC_HC_ENABLED_SHIFT
value|2
define|#
directive|define
name|HC_INDEX_DATA_RESERVE
value|(0x1F<<3)
comment|/* BitField flags	 */
define|#
directive|define
name|HC_INDEX_DATA_RESERVE_SHIFT
value|3
name|uint8_t
name|timeout
comment|/* the timeout values for this index. Units are 4 usec */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint8_t
name|timeout
comment|/* the timeout values for this index. Units are 4 usec */
decl_stmt|;
name|uint8_t
name|flags
decl_stmt|;
define|#
directive|define
name|HC_INDEX_DATA_SM_ID
value|(0x1<<0)
comment|/* BitField flags	Index to a state machine. Can be 0 or 1 */
define|#
directive|define
name|HC_INDEX_DATA_SM_ID_SHIFT
value|0
define|#
directive|define
name|HC_INDEX_DATA_HC_ENABLED
value|(0x1<<1)
comment|/* BitField flags	if set, host coalescing would be done for this index */
define|#
directive|define
name|HC_INDEX_DATA_HC_ENABLED_SHIFT
value|1
define|#
directive|define
name|HC_INDEX_DATA_DYNAMIC_HC_ENABLED
value|(0x1<<2)
comment|/* BitField flags	if set, dynamic HC will be done for this index */
define|#
directive|define
name|HC_INDEX_DATA_DYNAMIC_HC_ENABLED_SHIFT
value|2
define|#
directive|define
name|HC_INDEX_DATA_RESERVE
value|(0x1F<<3)
comment|/* BitField flags	 */
define|#
directive|define
name|HC_INDEX_DATA_RESERVE_SHIFT
value|3
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/*  * HC state-machine  */
end_comment

begin_struct
struct|struct
name|hc_status_block_sm
block|{
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint8_t
name|igu_seg_id
decl_stmt|;
name|uint8_t
name|igu_sb_id
comment|/* sb_id within the IGU */
decl_stmt|;
name|uint8_t
name|timer_value
comment|/* Determines the time_to_expire */
decl_stmt|;
name|uint8_t
name|__flags
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint8_t
name|__flags
decl_stmt|;
name|uint8_t
name|timer_value
comment|/* Determines the time_to_expire */
decl_stmt|;
name|uint8_t
name|igu_sb_id
comment|/* sb_id within the IGU */
decl_stmt|;
name|uint8_t
name|igu_seg_id
decl_stmt|;
endif|#
directive|endif
name|uint32_t
name|time_to_expire
comment|/* The time in which it expects to wake up */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * hold PCI identification variables- used in various places in firmware  */
end_comment

begin_struct
struct|struct
name|pci_entity
block|{
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint8_t
name|vf_valid
comment|/* If set, this is a VF, otherwise it is PF */
decl_stmt|;
name|uint8_t
name|vf_id
comment|/* VF ID (0-63). Value of 0xFF means VF not valid */
decl_stmt|;
name|uint8_t
name|vnic_id
comment|/* Virtual NIC ID (0-3) */
decl_stmt|;
name|uint8_t
name|pf_id
comment|/* PCI physical function number (0-7). The LSB of this field is the port ID */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint8_t
name|pf_id
comment|/* PCI physical function number (0-7). The LSB of this field is the port ID */
decl_stmt|;
name|uint8_t
name|vnic_id
comment|/* Virtual NIC ID (0-3) */
decl_stmt|;
name|uint8_t
name|vf_id
comment|/* VF ID (0-63). Value of 0xFF means VF not valid */
decl_stmt|;
name|uint8_t
name|vf_valid
comment|/* If set, this is a VF, otherwise it is PF */
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/*  * The fast-path status block meta-data, common to all chips  */
end_comment

begin_struct
struct|struct
name|hc_sb_data
block|{
name|struct
name|regpair_native_t
name|host_sb_addr
comment|/* Host status block address */
decl_stmt|;
name|struct
name|hc_status_block_sm
name|state_machine
index|[
name|HC_SB_MAX_SM
index|]
comment|/* Holds the state machines of the status block */
decl_stmt|;
name|struct
name|pci_entity
name|p_func
comment|/* vnic / port of the status block to be set by the driver */
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint8_t
name|rsrv0
decl_stmt|;
name|uint8_t
name|state
decl_stmt|;
name|uint8_t
name|dhc_qzone_id
comment|/* used in E2 only, to specify the HW queue zone ID used for this status block dynamic HC counters */
decl_stmt|;
name|uint8_t
name|same_igu_sb_1b
comment|/* Indicate that both state-machines acts like single sm */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint8_t
name|same_igu_sb_1b
comment|/* Indicate that both state-machines acts like single sm */
decl_stmt|;
name|uint8_t
name|dhc_qzone_id
comment|/* used in E2 only, to specify the HW queue zone ID used for this status block dynamic HC counters */
decl_stmt|;
name|uint8_t
name|state
decl_stmt|;
name|uint8_t
name|rsrv0
decl_stmt|;
endif|#
directive|endif
name|struct
name|regpair_native_t
name|rsrv1
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Segment types for host coaslescing  */
end_comment

begin_enum
enum|enum
name|hc_segment
block|{
name|HC_REGULAR_SEGMENT
block|,
name|HC_DEFAULT_SEGMENT
block|,
name|MAX_HC_SEGMENT
block|}
enum|;
end_enum

begin_comment
comment|/*  * The fast-path status block meta-data  */
end_comment

begin_struct
struct|struct
name|hc_sp_status_block_data
block|{
name|struct
name|regpair_native_t
name|host_sb_addr
comment|/* Host status block address */
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint8_t
name|rsrv1
decl_stmt|;
name|uint8_t
name|state
decl_stmt|;
name|uint8_t
name|igu_seg_id
comment|/* segment id of the IGU */
decl_stmt|;
name|uint8_t
name|igu_sb_id
comment|/* sb_id within the IGU */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint8_t
name|igu_sb_id
comment|/* sb_id within the IGU */
decl_stmt|;
name|uint8_t
name|igu_seg_id
comment|/* segment id of the IGU */
decl_stmt|;
name|uint8_t
name|state
decl_stmt|;
name|uint8_t
name|rsrv1
decl_stmt|;
endif|#
directive|endif
name|struct
name|pci_entity
name|p_func
comment|/* vnic / port of the status block to be set by the driver */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The fast-path status block meta-data  */
end_comment

begin_struct
struct|struct
name|hc_status_block_data_e1x
block|{
name|struct
name|hc_index_data
name|index_data
index|[
name|HC_SB_MAX_INDICES_E1X
index|]
comment|/* configuration/state parameters for a single protocol index */
decl_stmt|;
name|struct
name|hc_sb_data
name|common
comment|/* The fast-path status block meta-data, common to all chips */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The fast-path status block meta-data  */
end_comment

begin_struct
struct|struct
name|hc_status_block_data_e2
block|{
name|struct
name|hc_index_data
name|index_data
index|[
name|HC_SB_MAX_INDICES_E2
index|]
comment|/* configuration/state parameters for a single protocol index */
decl_stmt|;
name|struct
name|hc_sb_data
name|common
comment|/* The fast-path status block meta-data, common to all chips */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * IGU block operartion modes (in Everest2)  */
end_comment

begin_enum
enum|enum
name|igu_mode
block|{
name|HC_IGU_BC_MODE
comment|/* Backward compatible mode */
block|,
name|HC_IGU_NBC_MODE
comment|/* Non-backward compatible mode */
block|,
name|MAX_IGU_MODE
block|}
enum|;
end_enum

begin_comment
comment|/*  * Inner Headers Classification Type  */
end_comment

begin_enum
enum|enum
name|inner_clss_type
block|{
name|INNER_CLSS_DISABLED
comment|/* Inner Classification Disabled */
block|,
name|INNER_CLSS_USE_VLAN
comment|/* Inner Classification using MAC/Inner VLAN */
block|,
name|INNER_CLSS_USE_VNI
comment|/* Inner Classification using MAC/VNI (Only for VXLAN and GENEVE) */
block|,
name|MAX_INNER_CLSS_TYPE
block|}
enum|;
end_enum

begin_comment
comment|/*  * IP versions  */
end_comment

begin_enum
enum|enum
name|ip_ver
block|{
name|IP_V4
block|,
name|IP_V6
block|,
name|MAX_IP_VER
block|}
enum|;
end_enum

begin_comment
comment|/*  * Malicious VF error ID  */
end_comment

begin_enum
enum|enum
name|malicious_vf_error_id
block|{
name|MALICIOUS_VF_NO_ERROR
comment|/* Zero placeholder value */
block|,
name|VF_PF_CHANNEL_NOT_READY
comment|/* Writing to VF/PF channel when it is not ready */
block|,
name|ETH_ILLEGAL_BD_LENGTHS
comment|/* TX BD lengths error was detected */
block|,
name|ETH_PACKET_TOO_SHORT
comment|/* TX packet is shorter then reported on BDs */
block|,
name|ETH_PAYLOAD_TOO_BIG
comment|/* TX packet is greater then MTU */
block|,
name|ETH_ILLEGAL_ETH_TYPE
comment|/* TX packet reported without VLAN but eth type is 0x8100 */
block|,
name|ETH_ILLEGAL_LSO_HDR_LEN
comment|/* LSO header length on BDs and on hdr_nbd do not match */
block|,
name|ETH_TOO_MANY_BDS
comment|/* Tx packet has too many BDs */
block|,
name|ETH_ZERO_HDR_NBDS
comment|/* hdr_nbds field is zero */
block|,
name|ETH_START_BD_NOT_SET
comment|/* start_bd should be set on first TX BD in packet */
block|,
name|ETH_ILLEGAL_PARSE_NBDS
comment|/* Tx packet with parse_nbds field which is not legal */
block|,
name|ETH_IPV6_AND_CHECKSUM
comment|/* Tx packet with IP checksum on IPv6 */
block|,
name|ETH_VLAN_FLG_INCORRECT
comment|/* Tx packet with incorrect VLAN flag */
block|,
name|ETH_ILLEGAL_LSO_MSS
comment|/* Tx LSO packet with illegal MSS value */
block|,
name|ETH_TUNNEL_NOT_SUPPORTED
comment|/* Tunneling packets are not supported in current connection */
block|,
name|MAX_MALICIOUS_VF_ERROR_ID
block|}
enum|;
end_enum

begin_comment
comment|/*  * Multi-function modes  */
end_comment

begin_enum
enum|enum
name|mf_mode
block|{
name|SINGLE_FUNCTION
block|,
name|MULTI_FUNCTION_SD
comment|/* Switch dependent (vlan based) */
block|,
name|MULTI_FUNCTION_SI
comment|/* Switch independent (mac based) */
block|,
name|MULTI_FUNCTION_AFEX
comment|/* Switch dependent (niv based) */
block|,
name|MAX_MF_MODE
block|}
enum|;
end_enum

begin_comment
comment|/*  * Protocol-common statistics collected by the Tstorm (per pf) $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|tstorm_per_pf_stats
block|{
name|struct
name|regpair_t
name|rcv_error_bytes
comment|/* number of bytes received with errors */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  *  $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|per_pf_stats
block|{
name|struct
name|tstorm_per_pf_stats
name|tstorm_pf_statistics
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Protocol-common statistics collected by the Tstorm (per port) $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|tstorm_per_port_stats
block|{
name|uint32_t
name|mac_discard
comment|/* number of packets with mac errors */
decl_stmt|;
name|uint32_t
name|mac_filter_discard
comment|/* the number of good frames dropped because of no perfect match to MAC/VLAN address */
decl_stmt|;
name|uint32_t
name|brb_truncate_discard
comment|/* the number of packtes that were dropped because they were truncated in BRB */
decl_stmt|;
name|uint32_t
name|mf_tag_discard
comment|/* the number of good frames dropped because of no match to the outer vlan/VNtag */
decl_stmt|;
name|uint32_t
name|packet_drop
comment|/* general packet drop conter- incremented for every packet drop */
decl_stmt|;
name|uint32_t
name|reserved
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  *  $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|per_port_stats
block|{
name|struct
name|tstorm_per_port_stats
name|tstorm_port_statistics
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Protocol-common statistics collected by the Tstorm (per client) $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|tstorm_per_queue_stats
block|{
name|struct
name|regpair_t
name|rcv_ucast_bytes
comment|/* number of bytes in unicast packets received without errors and pass the filter */
decl_stmt|;
name|uint32_t
name|rcv_ucast_pkts
comment|/* number of unicast packets received without errors and pass the filter */
decl_stmt|;
name|uint32_t
name|checksum_discard
comment|/* number of total packets received with checksum error */
decl_stmt|;
name|struct
name|regpair_t
name|rcv_bcast_bytes
comment|/* number of bytes in broadcast packets received without errors and pass the filter */
decl_stmt|;
name|uint32_t
name|rcv_bcast_pkts
comment|/* number of packets in broadcast packets received without errors and pass the filter */
decl_stmt|;
name|uint32_t
name|pkts_too_big_discard
comment|/* number of too long packets received */
decl_stmt|;
name|struct
name|regpair_t
name|rcv_mcast_bytes
comment|/* number of bytes in multicast packets received without errors and pass the filter */
decl_stmt|;
name|uint32_t
name|rcv_mcast_pkts
comment|/* number of packets in multicast packets received without errors and pass the filter */
decl_stmt|;
name|uint32_t
name|ttl0_discard
comment|/* the number of good frames dropped because of TTL=0 */
decl_stmt|;
name|uint16_t
name|no_buff_discard
decl_stmt|;
name|uint16_t
name|reserved0
decl_stmt|;
name|uint32_t
name|reserved1
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Protocol-common statistics collected by the Ustorm (per client) $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|ustorm_per_queue_stats
block|{
name|struct
name|regpair_t
name|ucast_no_buff_bytes
comment|/* the number of unicast bytes received from network dropped because of no buffer at host */
decl_stmt|;
name|struct
name|regpair_t
name|mcast_no_buff_bytes
comment|/* the number of multicast bytes received from network dropped because of no buffer at host */
decl_stmt|;
name|struct
name|regpair_t
name|bcast_no_buff_bytes
comment|/* the number of broadcast bytes received from network dropped because of no buffer at host */
decl_stmt|;
name|uint32_t
name|ucast_no_buff_pkts
comment|/* the number of unicast frames received from network dropped because of no buffer at host */
decl_stmt|;
name|uint32_t
name|mcast_no_buff_pkts
comment|/* the number of unicast frames received from network dropped because of no buffer at host */
decl_stmt|;
name|uint32_t
name|bcast_no_buff_pkts
comment|/* the number of unicast frames received from network dropped because of no buffer at host */
decl_stmt|;
name|uint32_t
name|coalesced_pkts
comment|/* the number of packets coalesced in all aggregations */
decl_stmt|;
name|struct
name|regpair_t
name|coalesced_bytes
comment|/* the number of bytes coalesced in all aggregations */
decl_stmt|;
name|uint32_t
name|coalesced_events
comment|/* the number of aggregations */
decl_stmt|;
name|uint32_t
name|coalesced_aborts
comment|/* the number of exception which avoid aggregation */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Protocol-common statistics collected by the Xstorm (per client)  $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|xstorm_per_queue_stats
block|{
name|struct
name|regpair_t
name|ucast_bytes_sent
comment|/* number of total bytes sent without errors */
decl_stmt|;
name|struct
name|regpair_t
name|mcast_bytes_sent
comment|/* number of total bytes sent without errors */
decl_stmt|;
name|struct
name|regpair_t
name|bcast_bytes_sent
comment|/* number of total bytes sent without errors */
decl_stmt|;
name|uint32_t
name|ucast_pkts_sent
comment|/* number of total packets sent without errors */
decl_stmt|;
name|uint32_t
name|mcast_pkts_sent
comment|/* number of total packets sent without errors */
decl_stmt|;
name|uint32_t
name|bcast_pkts_sent
comment|/* number of total packets sent without errors */
decl_stmt|;
name|uint32_t
name|error_drop_pkts
comment|/* number of total packets drooped due to errors */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  *  $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|per_queue_stats
block|{
name|struct
name|tstorm_per_queue_stats
name|tstorm_queue_statistics
decl_stmt|;
name|struct
name|ustorm_per_queue_stats
name|ustorm_queue_statistics
decl_stmt|;
name|struct
name|xstorm_per_queue_stats
name|xstorm_queue_statistics
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * FW version stored in first line of pram $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|pram_fw_version
block|{
name|uint8_t
name|major
comment|/* firmware current major version */
decl_stmt|;
name|uint8_t
name|minor
comment|/* firmware current minor version */
decl_stmt|;
name|uint8_t
name|revision
comment|/* firmware current revision version */
decl_stmt|;
name|uint8_t
name|engineering
comment|/* firmware current engineering version */
decl_stmt|;
name|uint8_t
name|flags
decl_stmt|;
define|#
directive|define
name|PRAM_FW_VERSION_OPTIMIZED
value|(0x1<<0)
comment|/* BitField flags	if set, this is optimized ASM */
define|#
directive|define
name|PRAM_FW_VERSION_OPTIMIZED_SHIFT
value|0
define|#
directive|define
name|PRAM_FW_VERSION_STORM_ID
value|(0x3<<1)
comment|/* BitField flags	storm_id identification */
define|#
directive|define
name|PRAM_FW_VERSION_STORM_ID_SHIFT
value|1
define|#
directive|define
name|PRAM_FW_VERSION_BIG_ENDIEN
value|(0x1<<3)
comment|/* BitField flags	if set, this is big-endien ASM */
define|#
directive|define
name|PRAM_FW_VERSION_BIG_ENDIEN_SHIFT
value|3
define|#
directive|define
name|PRAM_FW_VERSION_CHIP_VERSION
value|(0x3<<4)
comment|/* BitField flags	0 - E1, 1 - E1H */
define|#
directive|define
name|PRAM_FW_VERSION_CHIP_VERSION_SHIFT
value|4
define|#
directive|define
name|__PRAM_FW_VERSION_RESERVED0
value|(0x3<<6)
comment|/* BitField flags	 */
define|#
directive|define
name|__PRAM_FW_VERSION_RESERVED0_SHIFT
value|6
block|}
struct|;
end_struct

begin_comment
comment|/*  * Ethernet slow path element  */
end_comment

begin_union
union|union
name|protocol_common_specific_data
block|{
name|uint8_t
name|protocol_data
index|[
literal|8
index|]
comment|/* to fix this structure size to 8 bytes */
decl_stmt|;
name|struct
name|regpair_t
name|phy_address
comment|/* SPE physical address */
decl_stmt|;
name|struct
name|regpair_t
name|mac_config_addr
comment|/* physical address of the MAC configuration command, as allocated by the driver */
decl_stmt|;
name|struct
name|afex_vif_list_ramrod_data
name|afex_vif_list_data
comment|/* The data afex vif list ramrod need */
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/*  * The send queue element  */
end_comment

begin_struct
struct|struct
name|protocol_common_spe
block|{
name|struct
name|spe_hdr_t
name|hdr
comment|/* SPE header */
decl_stmt|;
name|union
name|protocol_common_specific_data
name|data
comment|/* data specific to common protocol */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The data for the Set Timesync Ramrod $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|set_timesync_ramrod_data
block|{
name|uint8_t
name|drift_adjust_cmd
comment|/* Timesync Drift Adjust Command */
decl_stmt|;
name|uint8_t
name|offset_cmd
comment|/* Timesync Offset Command */
decl_stmt|;
name|uint8_t
name|add_sub_drift_adjust_value
comment|/* Whether to add(1)/subtract(0) Drift Adjust Value from the Offset */
decl_stmt|;
name|uint8_t
name|drift_adjust_value
comment|/* Drift Adjust Value (in ns) */
decl_stmt|;
name|uint32_t
name|drift_adjust_period
comment|/* Drift Adjust Period (in us) */
decl_stmt|;
name|struct
name|regpair_t
name|offset_delta
comment|/* Timesync Offset Delta (in ns) */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The send queue element  */
end_comment

begin_struct
struct|struct
name|slow_path_element
block|{
name|struct
name|spe_hdr_t
name|hdr
comment|/* common data for all protocols */
decl_stmt|;
name|struct
name|regpair_t
name|protocol_data
comment|/* additional data specific to the protocol */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Protocol-common statistics counter $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|stats_counter
block|{
name|uint16_t
name|xstats_counter
comment|/* xstorm statistics counter */
decl_stmt|;
name|uint16_t
name|reserved0
decl_stmt|;
name|uint32_t
name|reserved1
decl_stmt|;
name|uint16_t
name|tstats_counter
comment|/* tstorm statistics counter */
decl_stmt|;
name|uint16_t
name|reserved2
decl_stmt|;
name|uint32_t
name|reserved3
decl_stmt|;
name|uint16_t
name|ustats_counter
comment|/* ustorm statistics counter */
decl_stmt|;
name|uint16_t
name|reserved4
decl_stmt|;
name|uint32_t
name|reserved5
decl_stmt|;
name|uint16_t
name|cstats_counter
comment|/* ustorm statistics counter */
decl_stmt|;
name|uint16_t
name|reserved6
decl_stmt|;
name|uint32_t
name|reserved7
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  *  $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|stats_query_entry
block|{
name|uint8_t
name|kind
decl_stmt|;
name|uint8_t
name|index
comment|/* queue index */
decl_stmt|;
name|uint16_t
name|funcID
comment|/* the func the statistic will send to */
decl_stmt|;
name|uint32_t
name|reserved
decl_stmt|;
name|struct
name|regpair_t
name|address
comment|/* pxp address */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * statistic command $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|stats_query_cmd_group
block|{
name|struct
name|stats_query_entry
name|query
index|[
name|STATS_QUERY_CMD_COUNT
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * statistic command header $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|stats_query_header
block|{
name|uint8_t
name|cmd_num
comment|/* command number */
decl_stmt|;
name|uint8_t
name|reserved0
decl_stmt|;
name|uint16_t
name|drv_stats_counter
decl_stmt|;
name|uint32_t
name|reserved1
decl_stmt|;
name|struct
name|regpair_t
name|stats_counters_addrs
comment|/* stats counter */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Types of statistcis query entry  */
end_comment

begin_enum
enum|enum
name|stats_query_type
block|{
name|STATS_TYPE_QUEUE
block|,
name|STATS_TYPE_PORT
block|,
name|STATS_TYPE_PF
block|,
name|STATS_TYPE_TOE
block|,
name|STATS_TYPE_FCOE
block|,
name|MAX_STATS_QUERY_TYPE
block|}
enum|;
end_enum

begin_comment
comment|/*  * Indicate of the function status block state  */
end_comment

begin_enum
enum|enum
name|status_block_state
block|{
name|SB_DISABLED
block|,
name|SB_ENABLED
block|,
name|SB_CLEANED
block|,
name|MAX_STATUS_BLOCK_STATE
block|}
enum|;
end_enum

begin_comment
comment|/*  * Storm IDs (including attentions for IGU related enums)  */
end_comment

begin_enum
enum|enum
name|storm_id
block|{
name|USTORM_ID
block|,
name|CSTORM_ID
block|,
name|XSTORM_ID
block|,
name|TSTORM_ID
block|,
name|ATTENTION_ID
block|,
name|MAX_STORM_ID
block|}
enum|;
end_enum

begin_comment
comment|/*  * Taffic types used in ETS and flow control algorithms  */
end_comment

begin_enum
enum|enum
name|traffic_type
block|{
name|LLFC_TRAFFIC_TYPE_NW
comment|/* Networking */
block|,
name|LLFC_TRAFFIC_TYPE_FCOE
comment|/* FCoE */
block|,
name|LLFC_TRAFFIC_TYPE_ISCSI
comment|/* iSCSI */
block|,
name|MAX_TRAFFIC_TYPE
block|}
enum|;
end_enum

begin_comment
comment|/*  * zone A per-queue data  */
end_comment

begin_struct
struct|struct
name|tstorm_queue_zone_data
block|{
name|struct
name|regpair_t
name|reserved
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * zone B per-VF data  */
end_comment

begin_struct
struct|struct
name|tstorm_vf_zone_data
block|{
name|struct
name|regpair_t
name|reserved
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Add or Subtract Value for Set Timesync Ramrod  */
end_comment

begin_enum
enum|enum
name|ts_add_sub_value
block|{
name|TS_SUB_VALUE
comment|/* Subtract Value */
block|,
name|TS_ADD_VALUE
comment|/* Add Value */
block|,
name|MAX_TS_ADD_SUB_VALUE
block|}
enum|;
end_enum

begin_comment
comment|/*  * Drift-Adjust Commands for Set Timesync Ramrod  */
end_comment

begin_enum
enum|enum
name|ts_drift_adjust_cmd
block|{
name|TS_DRIFT_ADJUST_KEEP
comment|/* Keep Drift-Adjust at current values */
block|,
name|TS_DRIFT_ADJUST_SET
comment|/* Set Drift-Adjust */
block|,
name|TS_DRIFT_ADJUST_RESET
comment|/* Reset Drift-Adjust */
block|,
name|MAX_TS_DRIFT_ADJUST_CMD
block|}
enum|;
end_enum

begin_comment
comment|/*  * Offset Commands for Set Timesync Ramrod  */
end_comment

begin_enum
enum|enum
name|ts_offset_cmd
block|{
name|TS_OFFSET_KEEP
comment|/* Keep Offset at current values */
block|,
name|TS_OFFSET_INC
comment|/* Increase Offset by Offset Delta */
block|,
name|TS_OFFSET_DEC
comment|/* Decrease Offset by Offset Delta */
block|,
name|MAX_TS_OFFSET_CMD
block|}
enum|;
end_enum

begin_comment
comment|/*  * Input for measuring Pci Latency  */
end_comment

begin_struct
struct|struct
name|t_measure_pci_latency_ctrl
block|{
name|struct
name|regpair_t
name|read_addr
comment|/* Address to read from */
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint8_t
name|sleep
comment|/* Measure including a thread sleep */
decl_stmt|;
name|uint8_t
name|enable
comment|/* Enable PCI Latency measurements */
decl_stmt|;
name|uint8_t
name|func_id
comment|/* Function ID */
decl_stmt|;
name|uint8_t
name|read_size
comment|/* Amount of bytes to read */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint8_t
name|read_size
comment|/* Amount of bytes to read */
decl_stmt|;
name|uint8_t
name|func_id
comment|/* Function ID */
decl_stmt|;
name|uint8_t
name|enable
comment|/* Enable PCI Latency measurements */
decl_stmt|;
name|uint8_t
name|sleep
comment|/* Measure including a thread sleep */
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|num_meas
comment|/* Number of measurements to make */
decl_stmt|;
name|uint8_t
name|reserved
decl_stmt|;
name|uint8_t
name|period_10us
comment|/* Number of 10s of microseconds to wait between measurements */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint8_t
name|period_10us
comment|/* Number of 10s of microseconds to wait between measurements */
decl_stmt|;
name|uint8_t
name|reserved
decl_stmt|;
name|uint16_t
name|num_meas
comment|/* Number of measurements to make */
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/*  * Input for measuring Pci Latency  */
end_comment

begin_struct
struct|struct
name|t_measure_pci_latency_data
block|{
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|max_time_ns
comment|/* Maximum Time for a read (in ns) */
decl_stmt|;
name|uint16_t
name|min_time_ns
comment|/* Minimum Time for a read (in ns) */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|min_time_ns
comment|/* Minimum Time for a read (in ns) */
decl_stmt|;
name|uint16_t
name|max_time_ns
comment|/* Maximum Time for a read (in ns) */
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|reserved
decl_stmt|;
name|uint16_t
name|num_reads
comment|/* Number of reads - Used for Average */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|num_reads
comment|/* Number of reads - Used for Average */
decl_stmt|;
name|uint16_t
name|reserved
decl_stmt|;
endif|#
directive|endif
name|struct
name|regpair_t
name|sum_time_ns
comment|/* Sum of all the reads (in ns) - Used for Average */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * zone A per-queue data  */
end_comment

begin_struct
struct|struct
name|ustorm_queue_zone_data
block|{
name|struct
name|ustorm_eth_rx_producers
name|eth_rx_producers
comment|/* ETH RX rings producers */
decl_stmt|;
name|struct
name|regpair_t
name|reserved
index|[
literal|3
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * zone B per-VF data  */
end_comment

begin_struct
struct|struct
name|ustorm_vf_zone_data
block|{
name|struct
name|regpair_t
name|reserved
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * data per VF-PF channel  */
end_comment

begin_struct
struct|struct
name|vf_pf_channel_data
block|{
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|reserved0
decl_stmt|;
name|uint8_t
name|valid
comment|/* flag for channel validity. (cleared when identify a VF as malicious) */
decl_stmt|;
name|uint8_t
name|state
comment|/* channel state (ready / waiting for ack) */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint8_t
name|state
comment|/* channel state (ready / waiting for ack) */
decl_stmt|;
name|uint8_t
name|valid
comment|/* flag for channel validity. (cleared when identify a VF as malicious) */
decl_stmt|;
name|uint16_t
name|reserved0
decl_stmt|;
endif|#
directive|endif
name|uint32_t
name|reserved1
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * State of VF-PF channel  */
end_comment

begin_enum
enum|enum
name|vf_pf_channel_state
block|{
name|VF_PF_CHANNEL_STATE_READY
comment|/* Channel is ready to accept a message from VF */
block|,
name|VF_PF_CHANNEL_STATE_WAITING_FOR_ACK
comment|/* Channel waits for an ACK from PF */
block|,
name|MAX_VF_PF_CHANNEL_STATE
block|}
enum|;
end_enum

begin_comment
comment|/*  * vif_list_rule_kind  */
end_comment

begin_enum
enum|enum
name|vif_list_rule_kind
block|{
name|VIF_LIST_RULE_SET
block|,
name|VIF_LIST_RULE_GET
block|,
name|VIF_LIST_RULE_CLEAR_ALL
block|,
name|VIF_LIST_RULE_CLEAR_FUNC
block|,
name|MAX_VIF_LIST_RULE_KIND
block|}
enum|;
end_enum

begin_comment
comment|/*  * zone A per-queue data  */
end_comment

begin_struct
struct|struct
name|xstorm_queue_zone_data
block|{
name|struct
name|regpair_t
name|reserved
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * zone B per-VF data  */
end_comment

begin_struct
struct|struct
name|xstorm_vf_zone_data
block|{
name|struct
name|regpair_t
name|reserved
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Out-of-order states  */
end_comment

begin_enum
enum|enum
name|tcp_ooo_event
block|{
name|TCP_EVENT_ADD_PEN
init|=
literal|0
block|,
name|TCP_EVENT_ADD_NEW_ISLE
init|=
literal|1
block|,
name|TCP_EVENT_ADD_ISLE_RIGHT
init|=
literal|2
block|,
name|TCP_EVENT_ADD_ISLE_LEFT
init|=
literal|3
block|,
name|TCP_EVENT_JOIN
init|=
literal|4
block|,
name|TCP_EVENT_NOP
init|=
literal|5
block|,
name|MAX_TCP_OOO_EVENT
block|}
enum|;
end_enum

begin_comment
comment|/*  * OOO support modes  */
end_comment

begin_enum
enum|enum
name|tcp_tstorm_ooo
block|{
name|TCP_TSTORM_OOO_DROP_AND_PROC_ACK
block|,
name|TCP_TSTORM_OOO_SEND_PURE_ACK
block|,
name|TCP_TSTORM_OOO_SUPPORTED
block|,
name|MAX_TCP_TSTORM_OOO
block|}
enum|;
end_enum

begin_comment
comment|/*  * toe statistics collected by the Cstorm (per port)  */
end_comment

begin_struct
struct|struct
name|cstorm_toe_stats
block|{
name|uint32_t
name|no_tx_cqes
comment|/* count the number of time storm find that there are no more CQEs */
decl_stmt|;
name|uint32_t
name|reserved
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The toe storm context of Cstorm  */
end_comment

begin_struct
struct|struct
name|cstorm_toe_st_context
block|{
name|uint32_t
name|bds_ring_page_base_addr_lo
comment|/* Base address of next page in host bds ring */
decl_stmt|;
name|uint32_t
name|bds_ring_page_base_addr_hi
comment|/* Base address of next page in host bds ring */
decl_stmt|;
name|uint32_t
name|free_seq
comment|/* Sequnce number of the last byte that was free including */
decl_stmt|;
name|uint32_t
name|__last_rel_to_notify
comment|/* Accumulated release size for the next Chimney completion msg */
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|__rss_params_ram_line
comment|/* The ram line containing the rss params */
decl_stmt|;
name|uint16_t
name|bd_cons
comment|/* The bd s ring consumer  */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|bd_cons
comment|/* The bd s ring consumer  */
decl_stmt|;
name|uint16_t
name|__rss_params_ram_line
comment|/* The ram line containing the rss params */
decl_stmt|;
endif|#
directive|endif
name|uint32_t
name|cpu_id
comment|/* CPU id for sending completion for TSS (only 8 bits are used) */
decl_stmt|;
name|uint32_t
name|prev_snd_max
comment|/* last snd_max that was used for dynamic HC producer update */
decl_stmt|;
name|uint32_t
name|__reserved4
comment|/* reserved */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Cstorm Toe Storm Aligned Context  */
end_comment

begin_struct
struct|struct
name|cstorm_toe_st_aligned_context
block|{
name|struct
name|cstorm_toe_st_context
name|context
comment|/* context */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * prefetched isle bd  */
end_comment

begin_struct
struct|struct
name|ustorm_toe_prefetched_isle_bd
block|{
name|uint32_t
name|__addr_lo
comment|/* receive payload base address  - Single continuous buffer (page) pointer */
decl_stmt|;
name|uint32_t
name|__addr_hi
comment|/* receive payload base address  - Single continuous buffer (page) pointer */
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint8_t
name|__reserved1
comment|/* reserved */
decl_stmt|;
name|uint8_t
name|__isle_num
comment|/* isle_number of the pre-fetched BD */
decl_stmt|;
name|uint16_t
name|__buf_un_used
comment|/* Number of bytes left for placement in the pre fetched  application/grq bd   0 size for buffer is not valid */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|__buf_un_used
comment|/* Number of bytes left for placement in the pre fetched  application/grq bd   0 size for buffer is not valid */
decl_stmt|;
name|uint8_t
name|__isle_num
comment|/* isle_number of the pre-fetched BD */
decl_stmt|;
name|uint8_t
name|__reserved1
comment|/* reserved */
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/*  * ring params  */
end_comment

begin_struct
struct|struct
name|ustorm_toe_ring_params
block|{
name|uint32_t
name|rq_cons_addr_lo
comment|/* A pointer to the next to consume application bd */
decl_stmt|;
name|uint32_t
name|rq_cons_addr_hi
comment|/* A pointer to the next to consume application bd */
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint8_t
name|__rq_local_cons
comment|/* consumer of the local rq ring */
decl_stmt|;
name|uint8_t
name|__rq_local_prod
comment|/* producer of the local rq ring */
decl_stmt|;
name|uint16_t
name|rq_cons
comment|/* RQ consumer is the index of the next to consume application bd */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|rq_cons
comment|/* RQ consumer is the index of the next to consume application bd */
decl_stmt|;
name|uint8_t
name|__rq_local_prod
comment|/* producer of the local rq ring */
decl_stmt|;
name|uint8_t
name|__rq_local_cons
comment|/* consumer of the local rq ring */
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/*  * prefetched bd  */
end_comment

begin_struct
struct|struct
name|ustorm_toe_prefetched_bd
block|{
name|uint32_t
name|__addr_lo
comment|/* receive payload base address  - Single continuous buffer (page) pointer */
decl_stmt|;
name|uint32_t
name|__addr_hi
comment|/* receive payload base address  - Single continuous buffer (page) pointer */
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|flags
decl_stmt|;
define|#
directive|define
name|__USTORM_TOE_PREFETCHED_BD_START
value|(0x1<<0)
comment|/* BitField flagsbd command flags	this bd is the beginning of an application buffer */
define|#
directive|define
name|__USTORM_TOE_PREFETCHED_BD_START_SHIFT
value|0
define|#
directive|define
name|__USTORM_TOE_PREFETCHED_BD_END
value|(0x1<<1)
comment|/* BitField flagsbd command flags	this bd is the end of an application buffer */
define|#
directive|define
name|__USTORM_TOE_PREFETCHED_BD_END_SHIFT
value|1
define|#
directive|define
name|__USTORM_TOE_PREFETCHED_BD_NO_PUSH
value|(0x1<<2)
comment|/* BitField flagsbd command flags	this application buffer must not be partially completed */
define|#
directive|define
name|__USTORM_TOE_PREFETCHED_BD_NO_PUSH_SHIFT
value|2
define|#
directive|define
name|USTORM_TOE_PREFETCHED_BD_SPLIT
value|(0x1<<3)
comment|/* BitField flagsbd command flags	this application buffer is part of a bigger buffer and this buffer is not the last */
define|#
directive|define
name|USTORM_TOE_PREFETCHED_BD_SPLIT_SHIFT
value|3
define|#
directive|define
name|__USTORM_TOE_PREFETCHED_BD_RESERVED1
value|(0xFFF<<4)
comment|/* BitField flagsbd command flags	reserved */
define|#
directive|define
name|__USTORM_TOE_PREFETCHED_BD_RESERVED1_SHIFT
value|4
name|uint16_t
name|__buf_un_used
comment|/* Number of bytes left for placement in the pre fetched  application/grq bd   0 size for buffer is not valid */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|__buf_un_used
comment|/* Number of bytes left for placement in the pre fetched  application/grq bd   0 size for buffer is not valid */
decl_stmt|;
name|uint16_t
name|flags
decl_stmt|;
define|#
directive|define
name|__USTORM_TOE_PREFETCHED_BD_START
value|(0x1<<0)
comment|/* BitField flagsbd command flags	this bd is the beginning of an application buffer */
define|#
directive|define
name|__USTORM_TOE_PREFETCHED_BD_START_SHIFT
value|0
define|#
directive|define
name|__USTORM_TOE_PREFETCHED_BD_END
value|(0x1<<1)
comment|/* BitField flagsbd command flags	this bd is the end of an application buffer */
define|#
directive|define
name|__USTORM_TOE_PREFETCHED_BD_END_SHIFT
value|1
define|#
directive|define
name|__USTORM_TOE_PREFETCHED_BD_NO_PUSH
value|(0x1<<2)
comment|/* BitField flagsbd command flags	this application buffer must not be partially completed */
define|#
directive|define
name|__USTORM_TOE_PREFETCHED_BD_NO_PUSH_SHIFT
value|2
define|#
directive|define
name|USTORM_TOE_PREFETCHED_BD_SPLIT
value|(0x1<<3)
comment|/* BitField flagsbd command flags	this application buffer is part of a bigger buffer and this buffer is not the last */
define|#
directive|define
name|USTORM_TOE_PREFETCHED_BD_SPLIT_SHIFT
value|3
define|#
directive|define
name|__USTORM_TOE_PREFETCHED_BD_RESERVED1
value|(0xFFF<<4)
comment|/* BitField flagsbd command flags	reserved */
define|#
directive|define
name|__USTORM_TOE_PREFETCHED_BD_RESERVED1_SHIFT
value|4
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/*  * Ustorm Toe Storm Context  */
end_comment

begin_struct
struct|struct
name|ustorm_toe_st_context
block|{
name|uint32_t
name|__pen_rq_placed
comment|/* Number of bytes that were placed in the RQ and not completed yet. */
decl_stmt|;
name|uint32_t
name|pen_grq_placed_bytes
comment|/* The number of in-order bytes (peninsula) that were placed in the GRQ (excluding bytes that were already  copied  to RQ BDs or RQ dummy BDs) */
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint8_t
name|flags2
decl_stmt|;
define|#
directive|define
name|USTORM_TOE_ST_CONTEXT_IGNORE_GRQ_PUSH
value|(0x1<<0)
comment|/* BitField flags2various state flags	we will ignore grq push unless it is ping pong test */
define|#
directive|define
name|USTORM_TOE_ST_CONTEXT_IGNORE_GRQ_PUSH_SHIFT
value|0
define|#
directive|define
name|USTORM_TOE_ST_CONTEXT_PUSH_FLAG
value|(0x1<<1)
comment|/* BitField flags2various state flags	indicates if push timer is set */
define|#
directive|define
name|USTORM_TOE_ST_CONTEXT_PUSH_FLAG_SHIFT
value|1
define|#
directive|define
name|USTORM_TOE_ST_CONTEXT_RSS_UPDATE_ENABLED
value|(0x1<<2)
comment|/* BitField flags2various state flags	indicates if RSS update is supported */
define|#
directive|define
name|USTORM_TOE_ST_CONTEXT_RSS_UPDATE_ENABLED_SHIFT
value|2
define|#
directive|define
name|USTORM_TOE_ST_CONTEXT_RESERVED0
value|(0x1F<<3)
comment|/* BitField flags2various state flags	 */
define|#
directive|define
name|USTORM_TOE_ST_CONTEXT_RESERVED0_SHIFT
value|3
name|uint8_t
name|__indirection_shift
comment|/* Offset in bits of the cupid of this connection on the 64Bits fetched from internal memoy */
decl_stmt|;
name|uint16_t
name|indirection_ram_offset
comment|/* address offset in internal memory  from the beginning of the table  consisting the cpu id of this connection (Only 12 bits are used) */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|indirection_ram_offset
comment|/* address offset in internal memory  from the beginning of the table  consisting the cpu id of this connection (Only 12 bits are used) */
decl_stmt|;
name|uint8_t
name|__indirection_shift
comment|/* Offset in bits of the cupid of this connection on the 64Bits fetched from internal memoy */
decl_stmt|;
name|uint8_t
name|flags2
decl_stmt|;
define|#
directive|define
name|USTORM_TOE_ST_CONTEXT_IGNORE_GRQ_PUSH
value|(0x1<<0)
comment|/* BitField flags2various state flags	we will ignore grq push unless it is ping pong test */
define|#
directive|define
name|USTORM_TOE_ST_CONTEXT_IGNORE_GRQ_PUSH_SHIFT
value|0
define|#
directive|define
name|USTORM_TOE_ST_CONTEXT_PUSH_FLAG
value|(0x1<<1)
comment|/* BitField flags2various state flags	indicates if push timer is set */
define|#
directive|define
name|USTORM_TOE_ST_CONTEXT_PUSH_FLAG_SHIFT
value|1
define|#
directive|define
name|USTORM_TOE_ST_CONTEXT_RSS_UPDATE_ENABLED
value|(0x1<<2)
comment|/* BitField flags2various state flags	indicates if RSS update is supported */
define|#
directive|define
name|USTORM_TOE_ST_CONTEXT_RSS_UPDATE_ENABLED_SHIFT
value|2
define|#
directive|define
name|USTORM_TOE_ST_CONTEXT_RESERVED0
value|(0x1F<<3)
comment|/* BitField flags2various state flags	 */
define|#
directive|define
name|USTORM_TOE_ST_CONTEXT_RESERVED0_SHIFT
value|3
endif|#
directive|endif
name|uint32_t
name|__rq_available_bytes
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint8_t
name|isles_counter
comment|/* signals that dca is enabled */
decl_stmt|;
name|uint8_t
name|__push_timer_state
comment|/* indicates if push timer is set */
decl_stmt|;
name|uint16_t
name|rcv_indication_size
comment|/* The chip will release the current GRQ buffer to the driver when it knows that the driver has no knowledge of other GRQ payload that it can indicate and the current GRQ buffer has at least RcvIndicationSize bytes. */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|rcv_indication_size
comment|/* The chip will release the current GRQ buffer to the driver when it knows that the driver has no knowledge of other GRQ payload that it can indicate and the current GRQ buffer has at least RcvIndicationSize bytes. */
decl_stmt|;
name|uint8_t
name|__push_timer_state
comment|/* indicates if push timer is set */
decl_stmt|;
name|uint8_t
name|isles_counter
comment|/* signals that dca is enabled */
decl_stmt|;
endif|#
directive|endif
name|uint32_t
name|__min_expiration_time
comment|/* if the timer will expire before this time it will be considered as a race */
decl_stmt|;
name|uint32_t
name|initial_rcv_wnd
comment|/* the maximal advertized window */
decl_stmt|;
name|uint32_t
name|__bytes_cons
comment|/* the last rq_available_bytes producer that was read from host - used to know how many bytes were added */
decl_stmt|;
name|uint32_t
name|__prev_consumed_grq_bytes
comment|/* the last rq_available_bytes producer that was read from host - used to know how many bytes were added */
decl_stmt|;
name|uint32_t
name|prev_rcv_win_right_edge
comment|/* siquence of the last bytes that can be received - used to know how many bytes were added */
decl_stmt|;
name|uint32_t
name|rcv_nxt
comment|/* Receive sequence: next expected - of the right most received packet */
decl_stmt|;
name|struct
name|ustorm_toe_prefetched_isle_bd
name|__isle_bd
comment|/* prefetched bd for the isle */
decl_stmt|;
name|struct
name|ustorm_toe_ring_params
name|pen_ring_params
comment|/* peninsula ring params */
decl_stmt|;
name|struct
name|ustorm_toe_prefetched_bd
name|__pen_bd_0
comment|/* peninsula prefetched bd for the peninsula */
decl_stmt|;
name|struct
name|ustorm_toe_prefetched_bd
name|__pen_bd_1
comment|/* peninsula prefetched bd for the peninsula */
decl_stmt|;
name|struct
name|ustorm_toe_prefetched_bd
name|__pen_bd_2
comment|/* peninsula prefetched bd for the peninsula */
decl_stmt|;
name|struct
name|ustorm_toe_prefetched_bd
name|__pen_bd_3
comment|/* peninsula prefetched bd for the peninsula */
decl_stmt|;
name|struct
name|ustorm_toe_prefetched_bd
name|__pen_bd_4
comment|/* peninsula prefetched bd for the peninsula */
decl_stmt|;
name|struct
name|ustorm_toe_prefetched_bd
name|__pen_bd_5
comment|/* peninsula prefetched bd for the peninsula */
decl_stmt|;
name|struct
name|ustorm_toe_prefetched_bd
name|__pen_bd_6
comment|/* peninsula prefetched bd for the peninsula */
decl_stmt|;
name|struct
name|ustorm_toe_prefetched_bd
name|__pen_bd_7
comment|/* peninsula prefetched bd for the peninsula */
decl_stmt|;
name|struct
name|ustorm_toe_prefetched_bd
name|__pen_bd_8
comment|/* peninsula prefetched bd for the peninsula */
decl_stmt|;
name|struct
name|ustorm_toe_prefetched_bd
name|__pen_bd_9
comment|/* peninsula prefetched bd for the peninsula */
decl_stmt|;
name|uint32_t
name|__reserved3
comment|/* reserved */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Ustorm Toe Storm Aligned Context  */
end_comment

begin_struct
struct|struct
name|ustorm_toe_st_aligned_context
block|{
name|struct
name|ustorm_toe_st_context
name|context
comment|/* context */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * TOE context region, used only in TOE  */
end_comment

begin_struct
struct|struct
name|tstorm_toe_st_context_section
block|{
name|uint32_t
name|reserved0
index|[
literal|3
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The TOE non-aggregative context of Tstorm  */
end_comment

begin_struct
struct|struct
name|tstorm_toe_st_context
block|{
name|struct
name|tstorm_tcp_st_context_section
name|tcp
comment|/* TCP context region, shared in TOE, RDMA and ISCSI */
decl_stmt|;
name|struct
name|tstorm_toe_st_context_section
name|toe
comment|/* TOE context region, used only in TOE */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The TOE non-aggregative aligned context of Tstorm  */
end_comment

begin_struct
struct|struct
name|tstorm_toe_st_aligned_context
block|{
name|struct
name|tstorm_toe_st_context
name|context
comment|/* context */
decl_stmt|;
name|uint8_t
name|padding
index|[
literal|16
index|]
comment|/* padding to 64 byte aligned */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * TOE context section  */
end_comment

begin_struct
struct|struct
name|xstorm_toe_context_section
block|{
name|uint32_t
name|tx_bd_page_base_lo
comment|/* BD page base address at the host for TxBdCons */
decl_stmt|;
name|uint32_t
name|tx_bd_page_base_hi
comment|/* BD page base address at the host for TxBdCons */
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|tx_bd_offset
comment|/* The offset within the BD */
decl_stmt|;
name|uint16_t
name|tx_bd_cons
comment|/* The transmit BD cons pointer to the host ring */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|tx_bd_cons
comment|/* The transmit BD cons pointer to the host ring */
decl_stmt|;
name|uint16_t
name|tx_bd_offset
comment|/* The offset within the BD */
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|bd_prod
decl_stmt|;
name|uint16_t
name|seqMismatchCnt
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|seqMismatchCnt
decl_stmt|;
name|uint16_t
name|bd_prod
decl_stmt|;
endif|#
directive|endif
name|uint32_t
name|driver_doorbell_info_ptr_lo
decl_stmt|;
name|uint32_t
name|driver_doorbell_info_ptr_hi
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Xstorm Toe Storm Context  */
end_comment

begin_struct
struct|struct
name|xstorm_toe_st_context
block|{
name|struct
name|xstorm_common_context_section
name|common
decl_stmt|;
name|struct
name|xstorm_toe_context_section
name|toe
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Xstorm Toe Storm Aligned Context  */
end_comment

begin_struct
struct|struct
name|xstorm_toe_st_aligned_context
block|{
name|struct
name|xstorm_toe_st_context
name|context
comment|/* context */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Ethernet connection context  */
end_comment

begin_struct
struct|struct
name|toe_context
block|{
name|struct
name|ustorm_toe_st_aligned_context
name|ustorm_st_context
comment|/* Ustorm storm context */
decl_stmt|;
name|struct
name|tstorm_toe_st_aligned_context
name|tstorm_st_context
comment|/* Tstorm storm context */
decl_stmt|;
name|struct
name|xstorm_toe_ag_context
name|xstorm_ag_context
comment|/* Xstorm aggregative context */
decl_stmt|;
name|struct
name|tstorm_toe_ag_context
name|tstorm_ag_context
comment|/* Tstorm aggregative context */
decl_stmt|;
name|struct
name|cstorm_toe_ag_context
name|cstorm_ag_context
comment|/* Cstorm aggregative context */
decl_stmt|;
name|struct
name|ustorm_toe_ag_context
name|ustorm_ag_context
comment|/* Ustorm aggregative context */
decl_stmt|;
name|struct
name|timers_block_context
name|timers_context
comment|/* Timers block context */
decl_stmt|;
name|struct
name|xstorm_toe_st_aligned_context
name|xstorm_st_context
comment|/* Xstorm storm context */
decl_stmt|;
name|struct
name|cstorm_toe_st_aligned_context
name|cstorm_st_context
comment|/* Cstorm storm context */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * ramrod data for toe protocol initiate offload ramrod (CQE)  */
end_comment

begin_struct
struct|struct
name|toe_initiate_offload_ramrod_data
block|{
name|uint32_t
name|flags
decl_stmt|;
define|#
directive|define
name|TOE_INITIATE_OFFLOAD_RAMROD_DATA_SEARCH_CONFIG_FAILED
value|(0x1<<0)
comment|/* BitField flags	error in searcher configuration */
define|#
directive|define
name|TOE_INITIATE_OFFLOAD_RAMROD_DATA_SEARCH_CONFIG_FAILED_SHIFT
value|0
define|#
directive|define
name|TOE_INITIATE_OFFLOAD_RAMROD_DATA_LICENSE_FAILURE
value|(0x1<<1)
comment|/* BitField flags	license errors */
define|#
directive|define
name|TOE_INITIATE_OFFLOAD_RAMROD_DATA_LICENSE_FAILURE_SHIFT
value|1
define|#
directive|define
name|TOE_INITIATE_OFFLOAD_RAMROD_DATA_RESERVED0
value|(0x3FFFFFFF<<2)
comment|/* BitField flags	 */
define|#
directive|define
name|TOE_INITIATE_OFFLOAD_RAMROD_DATA_RESERVED0_SHIFT
value|2
name|uint32_t
name|reserved1
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * union for ramrod data for TOE protocol (CQE) (force size of 16 bits)  */
end_comment

begin_struct
struct|struct
name|toe_init_ramrod_data
block|{
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|reserved1
decl_stmt|;
name|uint8_t
name|reserved0
decl_stmt|;
name|uint8_t
name|rss_num
comment|/* the rss num in its rqr to complete this ramrod */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint8_t
name|rss_num
comment|/* the rss num in its rqr to complete this ramrod */
decl_stmt|;
name|uint8_t
name|reserved0
decl_stmt|;
name|uint16_t
name|reserved1
decl_stmt|;
endif|#
directive|endif
name|uint32_t
name|reserved2
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * next page pointer bd used in toe CQs and tx/rx bd chains  */
end_comment

begin_struct
struct|struct
name|toe_page_addr_bd
block|{
name|uint32_t
name|addr_lo
comment|/* page pointer */
decl_stmt|;
name|uint32_t
name|addr_hi
comment|/* page pointer */
decl_stmt|;
name|uint8_t
name|reserved
index|[
literal|8
index|]
comment|/* resereved for driver use */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * union for ramrod data for TOE protocol (CQE) (force size of 16 bits)  */
end_comment

begin_union
union|union
name|toe_ramrod_data
block|{
name|struct
name|ramrod_data
name|general
decl_stmt|;
name|struct
name|toe_initiate_offload_ramrod_data
name|initiate_offload
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/*  * TOE_RX_CQES_OPCODE_RSS_UPD results  */
end_comment

begin_enum
enum|enum
name|toe_rss_update_opcode
block|{
name|TOE_RSS_UPD_QUIET
block|,
name|TOE_RSS_UPD_SLEEPING
block|,
name|TOE_RSS_UPD_DELAYED
block|,
name|MAX_TOE_RSS_UPDATE_OPCODE
block|}
enum|;
end_enum

begin_comment
comment|/*  * union for ramrod data for TOE protocol (CQE) (force size of 16 bits)  */
end_comment

begin_struct
struct|struct
name|toe_rss_update_ramrod_data
block|{
name|uint8_t
name|indirection_table
index|[
literal|128
index|]
comment|/* RSS indirection table */
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|reserved0
decl_stmt|;
name|uint16_t
name|toe_rss_bitmap
comment|/* The bitmap specifies which toe rss chains to complete the ramrod on (0 bitmap is not valid option). The port is gleaned from the CID */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|toe_rss_bitmap
comment|/* The bitmap specifies which toe rss chains to complete the ramrod on (0 bitmap is not valid option). The port is gleaned from the CID */
decl_stmt|;
name|uint16_t
name|reserved0
decl_stmt|;
endif|#
directive|endif
name|uint32_t
name|reserved1
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The toe Rx Buffer Descriptor  */
end_comment

begin_struct
struct|struct
name|toe_rx_bd
block|{
name|uint32_t
name|addr_lo
comment|/* receive payload base address  - Single continuous buffer (page) pointer */
decl_stmt|;
name|uint32_t
name|addr_hi
comment|/* receive payload base address  - Single continuous buffer (page) pointer */
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|flags
decl_stmt|;
define|#
directive|define
name|TOE_RX_BD_START
value|(0x1<<0)
comment|/* BitField flagsbd command flags	this bd is the beginning of an application buffer */
define|#
directive|define
name|TOE_RX_BD_START_SHIFT
value|0
define|#
directive|define
name|TOE_RX_BD_END
value|(0x1<<1)
comment|/* BitField flagsbd command flags	this bd is the end of an application buffer */
define|#
directive|define
name|TOE_RX_BD_END_SHIFT
value|1
define|#
directive|define
name|TOE_RX_BD_NO_PUSH
value|(0x1<<2)
comment|/* BitField flagsbd command flags	this application buffer must not be partially completed */
define|#
directive|define
name|TOE_RX_BD_NO_PUSH_SHIFT
value|2
define|#
directive|define
name|TOE_RX_BD_SPLIT
value|(0x1<<3)
comment|/* BitField flagsbd command flags	this application buffer is part of a bigger buffer and this buffer is not the last */
define|#
directive|define
name|TOE_RX_BD_SPLIT_SHIFT
value|3
define|#
directive|define
name|TOE_RX_BD_RESERVED1
value|(0xFFF<<4)
comment|/* BitField flagsbd command flags	reserved */
define|#
directive|define
name|TOE_RX_BD_RESERVED1_SHIFT
value|4
name|uint16_t
name|size
comment|/* Size of the buffer pointed by the BD */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|size
comment|/* Size of the buffer pointed by the BD */
decl_stmt|;
name|uint16_t
name|flags
decl_stmt|;
define|#
directive|define
name|TOE_RX_BD_START
value|(0x1<<0)
comment|/* BitField flagsbd command flags	this bd is the beginning of an application buffer */
define|#
directive|define
name|TOE_RX_BD_START_SHIFT
value|0
define|#
directive|define
name|TOE_RX_BD_END
value|(0x1<<1)
comment|/* BitField flagsbd command flags	this bd is the end of an application buffer */
define|#
directive|define
name|TOE_RX_BD_END_SHIFT
value|1
define|#
directive|define
name|TOE_RX_BD_NO_PUSH
value|(0x1<<2)
comment|/* BitField flagsbd command flags	this application buffer must not be partially completed */
define|#
directive|define
name|TOE_RX_BD_NO_PUSH_SHIFT
value|2
define|#
directive|define
name|TOE_RX_BD_SPLIT
value|(0x1<<3)
comment|/* BitField flagsbd command flags	this application buffer is part of a bigger buffer and this buffer is not the last */
define|#
directive|define
name|TOE_RX_BD_SPLIT_SHIFT
value|3
define|#
directive|define
name|TOE_RX_BD_RESERVED1
value|(0xFFF<<4)
comment|/* BitField flagsbd command flags	reserved */
define|#
directive|define
name|TOE_RX_BD_RESERVED1_SHIFT
value|4
endif|#
directive|endif
name|uint32_t
name|dbg_bytes_prod
comment|/* a cyclic parameter that caounts how many byte were available for placement till no not including this bd */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * ramrod data for toe protocol General rx completion  */
end_comment

begin_struct
struct|struct
name|toe_rx_completion_ramrod_data
block|{
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|reserved0
decl_stmt|;
name|uint16_t
name|hash_value
comment|/* information for ustorm to use in completion */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|hash_value
comment|/* information for ustorm to use in completion */
decl_stmt|;
name|uint16_t
name|reserved0
decl_stmt|;
endif|#
directive|endif
name|uint32_t
name|reserved1
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * OOO params in union for TOE rx cqe data  */
end_comment

begin_struct
struct|struct
name|toe_rx_cqe_ooo_params
block|{
name|uint32_t
name|ooo_params
decl_stmt|;
define|#
directive|define
name|TOE_RX_CQE_OOO_PARAMS_NBYTES
value|(0xFFFFFF<<0)
comment|/* BitField ooo_paramsdata params for OOO cqe	connection nbytes */
define|#
directive|define
name|TOE_RX_CQE_OOO_PARAMS_NBYTES_SHIFT
value|0
define|#
directive|define
name|TOE_RX_CQE_OOO_PARAMS_ISLE_NUM
value|(0xFF<<24)
comment|/* BitField ooo_paramsdata params for OOO cqe	isle number for OOO completions */
define|#
directive|define
name|TOE_RX_CQE_OOO_PARAMS_ISLE_NUM_SHIFT
value|24
block|}
struct|;
end_struct

begin_comment
comment|/*  * in order params in union for TOE rx cqe data  */
end_comment

begin_struct
struct|struct
name|toe_rx_cqe_in_order_params
block|{
name|uint32_t
name|in_order_params
decl_stmt|;
define|#
directive|define
name|TOE_RX_CQE_IN_ORDER_PARAMS_NBYTES
value|(0xFFFFFFFF<<0)
comment|/* BitField in_order_paramsdata params for in order cqe	connection nbytes */
define|#
directive|define
name|TOE_RX_CQE_IN_ORDER_PARAMS_NBYTES_SHIFT
value|0
block|}
struct|;
end_struct

begin_comment
comment|/*  * union for TOE rx cqe data  */
end_comment

begin_union
union|union
name|toe_rx_cqe_data_union
block|{
name|struct
name|toe_rx_cqe_ooo_params
name|ooo_params
comment|/* data params for OOO cqe - nbytes and isle number */
decl_stmt|;
name|struct
name|toe_rx_cqe_in_order_params
name|in_order_params
comment|/* data params for in order cqe - nbytes */
decl_stmt|;
name|uint32_t
name|raw_data
comment|/* global data param */
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/*  * The toe Rx cq element  */
end_comment

begin_struct
struct|struct
name|toe_rx_cqe
block|{
name|uint32_t
name|params1
decl_stmt|;
define|#
directive|define
name|TOE_RX_CQE_CID
value|(0xFFFFFF<<0)
comment|/* BitField params1completion cid and opcode	connection id */
define|#
directive|define
name|TOE_RX_CQE_CID_SHIFT
value|0
define|#
directive|define
name|TOE_RX_CQE_COMPLETION_OPCODE
value|(0xFF<<24)
comment|/* BitField params1completion cid and opcode	completion opcode - use enum toe_rx_cqe_type or toe_rss_update_opcode */
define|#
directive|define
name|TOE_RX_CQE_COMPLETION_OPCODE_SHIFT
value|24
name|union
name|toe_rx_cqe_data_union
name|data
comment|/* completion cid and opcode */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * toe rx doorbell data in host memory  */
end_comment

begin_struct
struct|struct
name|toe_rx_db_data
block|{
name|uint32_t
name|rcv_win_right_edge
comment|/* siquence of the last bytes that can be received */
decl_stmt|;
name|uint32_t
name|bytes_prod
comment|/* cyclic counter of posted bytes */
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint8_t
name|reserved1
comment|/* reserved */
decl_stmt|;
name|uint8_t
name|flags
decl_stmt|;
define|#
directive|define
name|TOE_RX_DB_DATA_IGNORE_WND_UPDATES
value|(0x1<<0)
comment|/* BitField flags	ustorm ignores window updates when this flag is set */
define|#
directive|define
name|TOE_RX_DB_DATA_IGNORE_WND_UPDATES_SHIFT
value|0
define|#
directive|define
name|TOE_RX_DB_DATA_PARTIAL_FILLED_BUF
value|(0x1<<1)
comment|/* BitField flags	indicates if to set push timer due to partially filled receive request after offload */
define|#
directive|define
name|TOE_RX_DB_DATA_PARTIAL_FILLED_BUF_SHIFT
value|1
define|#
directive|define
name|TOE_RX_DB_DATA_RESERVED0
value|(0x3F<<2)
comment|/* BitField flags	 */
define|#
directive|define
name|TOE_RX_DB_DATA_RESERVED0_SHIFT
value|2
name|uint16_t
name|bds_prod
comment|/* cyclic counter of bds to post */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|bds_prod
comment|/* cyclic counter of bds to post */
decl_stmt|;
name|uint8_t
name|flags
decl_stmt|;
define|#
directive|define
name|TOE_RX_DB_DATA_IGNORE_WND_UPDATES
value|(0x1<<0)
comment|/* BitField flags	ustorm ignores window updates when this flag is set */
define|#
directive|define
name|TOE_RX_DB_DATA_IGNORE_WND_UPDATES_SHIFT
value|0
define|#
directive|define
name|TOE_RX_DB_DATA_PARTIAL_FILLED_BUF
value|(0x1<<1)
comment|/* BitField flags	indicates if to set push timer due to partially filled receive request after offload */
define|#
directive|define
name|TOE_RX_DB_DATA_PARTIAL_FILLED_BUF_SHIFT
value|1
define|#
directive|define
name|TOE_RX_DB_DATA_RESERVED0
value|(0x3F<<2)
comment|/* BitField flags	 */
define|#
directive|define
name|TOE_RX_DB_DATA_RESERVED0_SHIFT
value|2
name|uint8_t
name|reserved1
comment|/* reserved */
decl_stmt|;
endif|#
directive|endif
name|uint32_t
name|consumed_grq_bytes
comment|/* cyclic counter of consumed grq bytes */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The toe Rx Generic Buffer Descriptor  */
end_comment

begin_struct
struct|struct
name|toe_rx_grq_bd
block|{
name|uint32_t
name|addr_lo
comment|/* receive payload base address  - Single continuous buffer (page) pointer */
decl_stmt|;
name|uint32_t
name|addr_hi
comment|/* receive payload base address  - Single continuous buffer (page) pointer */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * toe slow path element  */
end_comment

begin_union
union|union
name|toe_spe_data
block|{
name|uint8_t
name|protocol_data
index|[
literal|8
index|]
comment|/* to fix this structure size to 8 bytes */
decl_stmt|;
name|struct
name|regpair_t
name|phys_addr
comment|/* used in initiate offload ramrod */
decl_stmt|;
name|struct
name|toe_rx_completion_ramrod_data
name|rx_completion
comment|/* used in all ramrods that have a general rx completion */
decl_stmt|;
name|struct
name|toe_init_ramrod_data
name|toe_init
comment|/* used in toe init ramrod */
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/*  * toe slow path element  */
end_comment

begin_struct
struct|struct
name|toe_spe
block|{
name|struct
name|spe_hdr_t
name|hdr
comment|/* common data for all protocols */
decl_stmt|;
name|union
name|toe_spe_data
name|toe_data
comment|/* data specific to toe protocol */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * TOE slow path opcodes (opcode 0 is illegal) - includes commands and completions  */
end_comment

begin_enum
enum|enum
name|toe_sq_opcode_type
block|{
name|CMP_OPCODE_TOE_GA
init|=
literal|1
block|,
name|CMP_OPCODE_TOE_GR
init|=
literal|2
block|,
name|CMP_OPCODE_TOE_GNI
init|=
literal|3
block|,
name|CMP_OPCODE_TOE_GAIR
init|=
literal|4
block|,
name|CMP_OPCODE_TOE_GAIL
init|=
literal|5
block|,
name|CMP_OPCODE_TOE_GRI
init|=
literal|6
block|,
name|CMP_OPCODE_TOE_GJ
init|=
literal|7
block|,
name|CMP_OPCODE_TOE_DGI
init|=
literal|8
block|,
name|CMP_OPCODE_TOE_CMP
init|=
literal|9
block|,
name|CMP_OPCODE_TOE_REL
init|=
literal|10
block|,
name|CMP_OPCODE_TOE_SKP
init|=
literal|11
block|,
name|CMP_OPCODE_TOE_URG
init|=
literal|12
block|,
name|CMP_OPCODE_TOE_RT_TO
init|=
literal|13
block|,
name|CMP_OPCODE_TOE_KA_TO
init|=
literal|14
block|,
name|CMP_OPCODE_TOE_MAX_RT
init|=
literal|15
block|,
name|CMP_OPCODE_TOE_DBT_RE
init|=
literal|16
block|,
name|CMP_OPCODE_TOE_SYN
init|=
literal|17
block|,
name|CMP_OPCODE_TOE_OPT_ERR
init|=
literal|18
block|,
name|CMP_OPCODE_TOE_FW2_TO
init|=
literal|19
block|,
name|CMP_OPCODE_TOE_2WY_CLS
init|=
literal|20
block|,
name|CMP_OPCODE_TOE_TX_CMP
init|=
literal|21
block|,
name|RAMROD_OPCODE_TOE_INIT
init|=
literal|32
block|,
name|RAMROD_OPCODE_TOE_RSS_UPDATE
init|=
literal|33
block|,
name|RAMROD_OPCODE_TOE_TERMINATE_RING
init|=
literal|34
block|,
name|CMP_OPCODE_TOE_RST_RCV
init|=
literal|48
block|,
name|CMP_OPCODE_TOE_FIN_RCV
init|=
literal|49
block|,
name|CMP_OPCODE_TOE_FIN_UPL
init|=
literal|50
block|,
name|CMP_OPCODE_TOE_SRC_ERR
init|=
literal|51
block|,
name|CMP_OPCODE_TOE_LCN_ERR
init|=
literal|52
block|,
name|RAMROD_OPCODE_TOE_INITIATE_OFFLOAD
init|=
literal|80
block|,
name|RAMROD_OPCODE_TOE_SEARCHER_DELETE
init|=
literal|81
block|,
name|RAMROD_OPCODE_TOE_TERMINATE
init|=
literal|82
block|,
name|RAMROD_OPCODE_TOE_QUERY
init|=
literal|83
block|,
name|RAMROD_OPCODE_TOE_RESET_SEND
init|=
literal|84
block|,
name|RAMROD_OPCODE_TOE_INVALIDATE
init|=
literal|85
block|,
name|RAMROD_OPCODE_TOE_EMPTY_RAMROD
init|=
literal|86
block|,
name|RAMROD_OPCODE_TOE_UPDATE
init|=
literal|87
block|,
name|MAX_TOE_SQ_OPCODE_TYPE
block|}
enum|;
end_enum

begin_comment
comment|/*  * Toe statistics collected by the Xstorm (per port)  */
end_comment

begin_struct
struct|struct
name|xstorm_toe_stats_section
block|{
name|uint32_t
name|tcp_out_segments
decl_stmt|;
name|uint32_t
name|tcp_retransmitted_segments
decl_stmt|;
name|struct
name|regpair_t
name|ip_out_octets
decl_stmt|;
name|uint32_t
name|ip_out_requests
decl_stmt|;
name|uint32_t
name|reserved
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Toe statistics collected by the Xstorm (per port)  */
end_comment

begin_struct
struct|struct
name|xstorm_toe_stats
block|{
name|struct
name|xstorm_toe_stats_section
name|statistics
index|[
literal|2
index|]
comment|/* 0 - ipv4 , 1 - ipv6 */
decl_stmt|;
name|uint32_t
name|reserved
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Toe statistics collected by the Tstorm (per port)  */
end_comment

begin_struct
struct|struct
name|tstorm_toe_stats_section
block|{
name|uint32_t
name|ip_in_receives
decl_stmt|;
name|uint32_t
name|ip_in_delivers
decl_stmt|;
name|struct
name|regpair_t
name|ip_in_octets
decl_stmt|;
name|uint32_t
name|tcp_in_errors
comment|/* all discards except discards already counted by Ipv4 stats */
decl_stmt|;
name|uint32_t
name|ip_in_header_errors
comment|/* IP checksum */
decl_stmt|;
name|uint32_t
name|ip_in_discards
comment|/* no resources */
decl_stmt|;
name|uint32_t
name|ip_in_truncated_packets
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Toe statistics collected by the Tstorm (per port)  */
end_comment

begin_struct
struct|struct
name|tstorm_toe_stats
block|{
name|struct
name|tstorm_toe_stats_section
name|statistics
index|[
literal|2
index|]
comment|/* 0 - ipv4 , 1 - ipv6 */
decl_stmt|;
name|uint32_t
name|reserved
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Eth statistics query structure for the eth_stats_query ramrod  */
end_comment

begin_struct
struct|struct
name|toe_stats_query
block|{
name|struct
name|xstorm_toe_stats
name|xstorm_toe
comment|/* Xstorm Toe statistics structure */
decl_stmt|;
name|struct
name|tstorm_toe_stats
name|tstorm_toe
comment|/* Tstorm Toe statistics structure */
decl_stmt|;
name|struct
name|cstorm_toe_stats
name|cstorm_toe
comment|/* Cstorm Toe statistics structure */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The toe Tx Buffer Descriptor  */
end_comment

begin_struct
struct|struct
name|toe_tx_bd
block|{
name|uint32_t
name|addr_lo
comment|/* tranasmit payload base address  - Single continuous buffer (page) pointer */
decl_stmt|;
name|uint32_t
name|addr_hi
comment|/* tranasmit payload base address  - Single continuous buffer (page) pointer */
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|flags
decl_stmt|;
define|#
directive|define
name|TOE_TX_BD_PUSH
value|(0x1<<0)
comment|/* BitField flagsbd command flags	End of data flag */
define|#
directive|define
name|TOE_TX_BD_PUSH_SHIFT
value|0
define|#
directive|define
name|TOE_TX_BD_NOTIFY
value|(0x1<<1)
comment|/* BitField flagsbd command flags	notify driver with released data bytes including this bd */
define|#
directive|define
name|TOE_TX_BD_NOTIFY_SHIFT
value|1
define|#
directive|define
name|TOE_TX_BD_FIN
value|(0x1<<2)
comment|/* BitField flagsbd command flags	send fin request */
define|#
directive|define
name|TOE_TX_BD_FIN_SHIFT
value|2
define|#
directive|define
name|TOE_TX_BD_LARGE_IO
value|(0x1<<3)
comment|/* BitField flagsbd command flags	this bd is part of an application buffer larger than mss */
define|#
directive|define
name|TOE_TX_BD_LARGE_IO_SHIFT
value|3
define|#
directive|define
name|TOE_TX_BD_RESERVED1
value|(0xFFF<<4)
comment|/* BitField flagsbd command flags	reserved */
define|#
directive|define
name|TOE_TX_BD_RESERVED1_SHIFT
value|4
name|uint16_t
name|size
comment|/* Size of the data represented by the BD */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|size
comment|/* Size of the data represented by the BD */
decl_stmt|;
name|uint16_t
name|flags
decl_stmt|;
define|#
directive|define
name|TOE_TX_BD_PUSH
value|(0x1<<0)
comment|/* BitField flagsbd command flags	End of data flag */
define|#
directive|define
name|TOE_TX_BD_PUSH_SHIFT
value|0
define|#
directive|define
name|TOE_TX_BD_NOTIFY
value|(0x1<<1)
comment|/* BitField flagsbd command flags	notify driver with released data bytes including this bd */
define|#
directive|define
name|TOE_TX_BD_NOTIFY_SHIFT
value|1
define|#
directive|define
name|TOE_TX_BD_FIN
value|(0x1<<2)
comment|/* BitField flagsbd command flags	send fin request */
define|#
directive|define
name|TOE_TX_BD_FIN_SHIFT
value|2
define|#
directive|define
name|TOE_TX_BD_LARGE_IO
value|(0x1<<3)
comment|/* BitField flagsbd command flags	this bd is part of an application buffer larger than mss */
define|#
directive|define
name|TOE_TX_BD_LARGE_IO_SHIFT
value|3
define|#
directive|define
name|TOE_TX_BD_RESERVED1
value|(0xFFF<<4)
comment|/* BitField flagsbd command flags	reserved */
define|#
directive|define
name|TOE_TX_BD_RESERVED1_SHIFT
value|4
endif|#
directive|endif
name|uint32_t
name|nextBdStartSeq
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The toe Tx cqe  */
end_comment

begin_struct
struct|struct
name|toe_tx_cqe
block|{
name|uint32_t
name|params
decl_stmt|;
define|#
directive|define
name|TOE_TX_CQE_CID
value|(0xFFFFFF<<0)
comment|/* BitField paramscompletion cid and opcode	connection id */
define|#
directive|define
name|TOE_TX_CQE_CID_SHIFT
value|0
define|#
directive|define
name|TOE_TX_CQE_COMPLETION_OPCODE
value|(0xFF<<24)
comment|/* BitField paramscompletion cid and opcode	completion opcode (use enum toe_tx_cqe_type) */
define|#
directive|define
name|TOE_TX_CQE_COMPLETION_OPCODE_SHIFT
value|24
name|uint32_t
name|len
comment|/* the more2release in Bytes */
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * toe tx doorbell data in host memory  */
end_comment

begin_struct
struct|struct
name|toe_tx_db_data
block|{
name|uint32_t
name|bytes_prod_seq
comment|/* greatest sequence the chip can transmit */
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|flags
decl_stmt|;
define|#
directive|define
name|TOE_TX_DB_DATA_FIN
value|(0x1<<0)
comment|/* BitField flags	flag for post FIN request */
define|#
directive|define
name|TOE_TX_DB_DATA_FIN_SHIFT
value|0
define|#
directive|define
name|TOE_TX_DB_DATA_FLUSH
value|(0x1<<1)
comment|/* BitField flags	flag for last doorbell - flushing doorbell queue */
define|#
directive|define
name|TOE_TX_DB_DATA_FLUSH_SHIFT
value|1
define|#
directive|define
name|TOE_TX_DB_DATA_RESERVE
value|(0x3FFF<<2)
comment|/* BitField flags	 */
define|#
directive|define
name|TOE_TX_DB_DATA_RESERVE_SHIFT
value|2
name|uint16_t
name|bds_prod
comment|/* cyclic counter of posted bds */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|bds_prod
comment|/* cyclic counter of posted bds */
decl_stmt|;
name|uint16_t
name|flags
decl_stmt|;
define|#
directive|define
name|TOE_TX_DB_DATA_FIN
value|(0x1<<0)
comment|/* BitField flags	flag for post FIN request */
define|#
directive|define
name|TOE_TX_DB_DATA_FIN_SHIFT
value|0
define|#
directive|define
name|TOE_TX_DB_DATA_FLUSH
value|(0x1<<1)
comment|/* BitField flags	flag for last doorbell - flushing doorbell queue */
define|#
directive|define
name|TOE_TX_DB_DATA_FLUSH_SHIFT
value|1
define|#
directive|define
name|TOE_TX_DB_DATA_RESERVE
value|(0x3FFF<<2)
comment|/* BitField flags	 */
define|#
directive|define
name|TOE_TX_DB_DATA_RESERVE_SHIFT
value|2
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/*  * sturct used in update ramrod. Driver notifies chip which fields have changed via the bitmap  $$KEEP_ENDIANNESS$$  */
end_comment

begin_struct
struct|struct
name|toe_update_ramrod_cached_params
block|{
name|uint16_t
name|changed_fields
decl_stmt|;
define|#
directive|define
name|TOE_UPDATE_RAMROD_CACHED_PARAMS_DEST_ADDR_CHANGED
value|(0x1<<0)
comment|/* BitField changed_fieldsbitmap for indicating changed fields	 */
define|#
directive|define
name|TOE_UPDATE_RAMROD_CACHED_PARAMS_DEST_ADDR_CHANGED_SHIFT
value|0
define|#
directive|define
name|TOE_UPDATE_RAMROD_CACHED_PARAMS_MSS_CHANGED
value|(0x1<<1)
comment|/* BitField changed_fieldsbitmap for indicating changed fields	 */
define|#
directive|define
name|TOE_UPDATE_RAMROD_CACHED_PARAMS_MSS_CHANGED_SHIFT
value|1
define|#
directive|define
name|TOE_UPDATE_RAMROD_CACHED_PARAMS_KA_TIMEOUT_CHANGED
value|(0x1<<2)
comment|/* BitField changed_fieldsbitmap for indicating changed fields	 */
define|#
directive|define
name|TOE_UPDATE_RAMROD_CACHED_PARAMS_KA_TIMEOUT_CHANGED_SHIFT
value|2
define|#
directive|define
name|TOE_UPDATE_RAMROD_CACHED_PARAMS_KA_INTERVAL_CHANGED
value|(0x1<<3)
comment|/* BitField changed_fieldsbitmap for indicating changed fields	 */
define|#
directive|define
name|TOE_UPDATE_RAMROD_CACHED_PARAMS_KA_INTERVAL_CHANGED_SHIFT
value|3
define|#
directive|define
name|TOE_UPDATE_RAMROD_CACHED_PARAMS_MAX_RT_CHANGED
value|(0x1<<4)
comment|/* BitField changed_fieldsbitmap for indicating changed fields	 */
define|#
directive|define
name|TOE_UPDATE_RAMROD_CACHED_PARAMS_MAX_RT_CHANGED_SHIFT
value|4
define|#
directive|define
name|TOE_UPDATE_RAMROD_CACHED_PARAMS_RCV_INDICATION_SIZE_CHANGED
value|(0x1<<5)
comment|/* BitField changed_fieldsbitmap for indicating changed fields	 */
define|#
directive|define
name|TOE_UPDATE_RAMROD_CACHED_PARAMS_RCV_INDICATION_SIZE_CHANGED_SHIFT
value|5
define|#
directive|define
name|TOE_UPDATE_RAMROD_CACHED_PARAMS_FLOW_LABEL_CHANGED
value|(0x1<<6)
comment|/* BitField changed_fieldsbitmap for indicating changed fields	 */
define|#
directive|define
name|TOE_UPDATE_RAMROD_CACHED_PARAMS_FLOW_LABEL_CHANGED_SHIFT
value|6
define|#
directive|define
name|TOE_UPDATE_RAMROD_CACHED_PARAMS_ENABLE_KEEPALIVE_CHANGED
value|(0x1<<7)
comment|/* BitField changed_fieldsbitmap for indicating changed fields	 */
define|#
directive|define
name|TOE_UPDATE_RAMROD_CACHED_PARAMS_ENABLE_KEEPALIVE_CHANGED_SHIFT
value|7
define|#
directive|define
name|TOE_UPDATE_RAMROD_CACHED_PARAMS_ENABLE_NAGLE_CHANGED
value|(0x1<<8)
comment|/* BitField changed_fieldsbitmap for indicating changed fields	 */
define|#
directive|define
name|TOE_UPDATE_RAMROD_CACHED_PARAMS_ENABLE_NAGLE_CHANGED_SHIFT
value|8
define|#
directive|define
name|TOE_UPDATE_RAMROD_CACHED_PARAMS_TTL_CHANGED
value|(0x1<<9)
comment|/* BitField changed_fieldsbitmap for indicating changed fields	 */
define|#
directive|define
name|TOE_UPDATE_RAMROD_CACHED_PARAMS_TTL_CHANGED_SHIFT
value|9
define|#
directive|define
name|TOE_UPDATE_RAMROD_CACHED_PARAMS_HOP_LIMIT_CHANGED
value|(0x1<<10)
comment|/* BitField changed_fieldsbitmap for indicating changed fields	 */
define|#
directive|define
name|TOE_UPDATE_RAMROD_CACHED_PARAMS_HOP_LIMIT_CHANGED_SHIFT
value|10
define|#
directive|define
name|TOE_UPDATE_RAMROD_CACHED_PARAMS_TOS_CHANGED
value|(0x1<<11)
comment|/* BitField changed_fieldsbitmap for indicating changed fields	 */
define|#
directive|define
name|TOE_UPDATE_RAMROD_CACHED_PARAMS_TOS_CHANGED_SHIFT
value|11
define|#
directive|define
name|TOE_UPDATE_RAMROD_CACHED_PARAMS_TRAFFIC_CLASS_CHANGED
value|(0x1<<12)
comment|/* BitField changed_fieldsbitmap for indicating changed fields	 */
define|#
directive|define
name|TOE_UPDATE_RAMROD_CACHED_PARAMS_TRAFFIC_CLASS_CHANGED_SHIFT
value|12
define|#
directive|define
name|TOE_UPDATE_RAMROD_CACHED_PARAMS_KA_MAX_PROBE_COUNT_CHANGED
value|(0x1<<13)
comment|/* BitField changed_fieldsbitmap for indicating changed fields	 */
define|#
directive|define
name|TOE_UPDATE_RAMROD_CACHED_PARAMS_KA_MAX_PROBE_COUNT_CHANGED_SHIFT
value|13
define|#
directive|define
name|TOE_UPDATE_RAMROD_CACHED_PARAMS_USER_PRIORITY_CHANGED
value|(0x1<<14)
comment|/* BitField changed_fieldsbitmap for indicating changed fields	 */
define|#
directive|define
name|TOE_UPDATE_RAMROD_CACHED_PARAMS_USER_PRIORITY_CHANGED_SHIFT
value|14
define|#
directive|define
name|TOE_UPDATE_RAMROD_CACHED_PARAMS_INITIAL_RCV_WND_CHANGED
value|(0x1<<15)
comment|/* BitField changed_fieldsbitmap for indicating changed fields	 */
define|#
directive|define
name|TOE_UPDATE_RAMROD_CACHED_PARAMS_INITIAL_RCV_WND_CHANGED_SHIFT
value|15
name|uint8_t
name|ka_restart
comment|/* Only 1 bit is used */
decl_stmt|;
name|uint8_t
name|retransmit_restart
comment|/* Only 1 bit is used */
decl_stmt|;
name|uint8_t
name|dest_addr
index|[
literal|6
index|]
decl_stmt|;
name|uint16_t
name|mss
decl_stmt|;
name|uint32_t
name|ka_timeout
decl_stmt|;
name|uint32_t
name|ka_interval
decl_stmt|;
name|uint32_t
name|max_rt
decl_stmt|;
name|uint32_t
name|flow_label
comment|/* Only 20 bits are used */
decl_stmt|;
name|uint16_t
name|rcv_indication_size
decl_stmt|;
name|uint8_t
name|enable_keepalive
comment|/* Only 1 bit is used */
decl_stmt|;
name|uint8_t
name|enable_nagle
comment|/* Only 1 bit is used */
decl_stmt|;
name|uint8_t
name|ttl
decl_stmt|;
name|uint8_t
name|hop_limit
decl_stmt|;
name|uint8_t
name|tos
decl_stmt|;
name|uint8_t
name|traffic_class
decl_stmt|;
name|uint8_t
name|ka_max_probe_count
decl_stmt|;
name|uint8_t
name|user_priority
comment|/* Only 4 bits are used */
decl_stmt|;
name|uint16_t
name|reserved2
decl_stmt|;
name|uint32_t
name|initial_rcv_wnd
decl_stmt|;
name|uint32_t
name|reserved1
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * rx rings pause data for E1h only  */
end_comment

begin_struct
struct|struct
name|ustorm_toe_rx_pause_data_e1h
block|{
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|grq_thr_low
comment|/* number of remaining grqes under which, we send pause message */
decl_stmt|;
name|uint16_t
name|cq_thr_low
comment|/* number of remaining cqes under which, we send pause message */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|cq_thr_low
comment|/* number of remaining cqes under which, we send pause message */
decl_stmt|;
name|uint16_t
name|grq_thr_low
comment|/* number of remaining grqes under which, we send pause message */
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|uint16_t
name|grq_thr_high
comment|/* number of remaining grqes above which, we send un-pause message */
decl_stmt|;
name|uint16_t
name|cq_thr_high
comment|/* number of remaining cqes above which, we send un-pause message */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|uint16_t
name|cq_thr_high
comment|/* number of remaining cqes above which, we send un-pause message */
decl_stmt|;
name|uint16_t
name|grq_thr_high
comment|/* number of remaining grqes above which, we send un-pause message */
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ECORE_HSI_H */
end_comment

end_unit

