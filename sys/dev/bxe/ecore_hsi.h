begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2007-2014 QLogic Corporation. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS'  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  */
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
comment|/* 0x488 */
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
name|DRV_MSG_SEQ_NUMBER_MASK
value|0x0000ffff
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
index|[
literal|1
index|]
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
comment|/* 0x0108 */
name|uint32_t
name|swim_funcs
decl_stmt|;
name|uint32_t
name|swim_main_cb
decl_stmt|;
comment|/* 	 * bitmap notifying which VIF profiles stored in nvram are enabled by 	 * switch 	 */
name|uint32_t
name|afex_profiles_enabled
index|[
literal|2
index|]
decl_stmt|;
comment|/* generic flags controlled by the driver */
name|uint32_t
name|drv_flags
decl_stmt|;
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
name|uint32_t
name|ncsi_oem_data_addr
decl_stmt|;
name|uint32_t
name|sensor_data_addr
decl_stmt|;
name|uint32_t
name|buffer_block_addr
decl_stmt|;
name|uint32_t
name|sensor_data_req_update_interval
decl_stmt|;
name|uint32_t
name|temperature_in_half_celsius
decl_stmt|;
name|uint32_t
name|glob_struct_in_host
decl_stmt|;
name|uint32_t
name|dcbx_neg_res_ext_offset
decl_stmt|;
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
name|uint32_t
name|extended_dev_info_shared_cfg_size
decl_stmt|;
name|uint32_t
name|dcbx_en
index|[
name|PORT_MAX
index|]
decl_stmt|;
comment|/* The offset points to the multi threaded meta structure */
name|uint32_t
name|multi_thread_data_offset
decl_stmt|;
comment|/* address of DMAable host address holding values from the drivers */
name|uint32_t
name|drv_info_host_addr_lo
decl_stmt|;
name|uint32_t
name|drv_info_host_addr_hi
decl_stmt|;
comment|/* general values written by the MFW (such as current version) */
name|uint32_t
name|drv_info_control
decl_stmt|;
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
name|struct
name|eee_remote_vals
name|eee_remote_vals
index|[
name|PORT_MAX
index|]
decl_stmt|;
name|uint32_t
name|pf_allocation
index|[
name|E2_FUNC_MAX
index|]
decl_stmt|;
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
comment|/* Link Flap Avoidance */
name|uint32_t
name|lfa_host_addr
index|[
name|PORT_MAX
index|]
decl_stmt|;
comment|/* External PHY temperature in deg C. */
name|uint32_t
name|extphy_temps_in_celsius
decl_stmt|;
define|#
directive|define
name|EXTPHY1_TEMP_MASK
value|0x0000ffff
define|#
directive|define
name|EXTPHY1_TEMP_SHIFT
value|0
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
value|(1<<0)
name|uint32_t
name|ibft_host_addr_hi
decl_stmt|;
comment|/* Initialize by uEFI ROM */
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
value|8
end_define

begin_define
define|#
directive|define
name|BCM_5710_FW_REVISION_VERSION
value|51
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
comment|/*  * dmae command structure  */
end_comment

begin_struct
struct|struct
name|dmae_command
block|{
name|uint32_t
name|opcode
decl_stmt|;
define|#
directive|define
name|DMAE_COMMAND_SRC
value|(0x1<<0)
comment|/* BitField opcode	Whether the source is the PCIe or the GRC. 0- The source is the PCIe 1- The source is the GRC. */
define|#
directive|define
name|DMAE_COMMAND_SRC_SHIFT
value|0
define|#
directive|define
name|DMAE_COMMAND_DST
value|(0x3<<1)
comment|/* BitField opcode	The destination of the DMA can be: 0-None 1-PCIe 2-GRC 3-None  */
define|#
directive|define
name|DMAE_COMMAND_DST_SHIFT
value|1
define|#
directive|define
name|DMAE_COMMAND_C_DST
value|(0x1<<3)
comment|/* BitField opcode	The destination of the completion: 0-PCIe 1-GRC */
define|#
directive|define
name|DMAE_COMMAND_C_DST_SHIFT
value|3
define|#
directive|define
name|DMAE_COMMAND_C_TYPE_ENABLE
value|(0x1<<4)
comment|/* BitField opcode	Whether to write a completion word to the completion destination: 0-Do not write a completion word 1-Write the completion word  */
define|#
directive|define
name|DMAE_COMMAND_C_TYPE_ENABLE_SHIFT
value|4
define|#
directive|define
name|DMAE_COMMAND_C_TYPE_CRC_ENABLE
value|(0x1<<5)
comment|/* BitField opcode	Whether to write a CRC word to the completion destination 0-Do not write a CRC word 1-Write a CRC word  */
define|#
directive|define
name|DMAE_COMMAND_C_TYPE_CRC_ENABLE_SHIFT
value|5
define|#
directive|define
name|DMAE_COMMAND_C_TYPE_CRC_OFFSET
value|(0x7<<6)
comment|/* BitField opcode	The CRC word should be taken from the DMAE GRC space from address 9+X, where X is the value in these bits. */
define|#
directive|define
name|DMAE_COMMAND_C_TYPE_CRC_OFFSET_SHIFT
value|6
define|#
directive|define
name|DMAE_COMMAND_ENDIANITY
value|(0x3<<9)
comment|/* BitField opcode	swapping mode. */
define|#
directive|define
name|DMAE_COMMAND_ENDIANITY_SHIFT
value|9
define|#
directive|define
name|DMAE_COMMAND_PORT
value|(0x1<<11)
comment|/* BitField opcode	Which network port ID to present to the PCI request interface */
define|#
directive|define
name|DMAE_COMMAND_PORT_SHIFT
value|11
define|#
directive|define
name|DMAE_COMMAND_CRC_RESET
value|(0x1<<12)
comment|/* BitField opcode	reset crc result */
define|#
directive|define
name|DMAE_COMMAND_CRC_RESET_SHIFT
value|12
define|#
directive|define
name|DMAE_COMMAND_SRC_RESET
value|(0x1<<13)
comment|/* BitField opcode	reset source address in next go */
define|#
directive|define
name|DMAE_COMMAND_SRC_RESET_SHIFT
value|13
define|#
directive|define
name|DMAE_COMMAND_DST_RESET
value|(0x1<<14)
comment|/* BitField opcode	reset dest address in next go */
define|#
directive|define
name|DMAE_COMMAND_DST_RESET_SHIFT
value|14
define|#
directive|define
name|DMAE_COMMAND_E1HVN
value|(0x3<<15)
comment|/* BitField opcode	vnic number E2 and onwards source vnic */
define|#
directive|define
name|DMAE_COMMAND_E1HVN_SHIFT
value|15
define|#
directive|define
name|DMAE_COMMAND_DST_VN
value|(0x3<<17)
comment|/* BitField opcode	E2 and onwards dest vnic */
define|#
directive|define
name|DMAE_COMMAND_DST_VN_SHIFT
value|17
define|#
directive|define
name|DMAE_COMMAND_C_FUNC
value|(0x1<<19)
comment|/* BitField opcode	E2 and onwards which function gets the completion src_vn(e1hvn)-0 dst_vn-1 */
define|#
directive|define
name|DMAE_COMMAND_C_FUNC_SHIFT
value|19
define|#
directive|define
name|DMAE_COMMAND_ERR_POLICY
value|(0x3<<20)
comment|/* BitField opcode	E2 and onwards what to do when theres a completion and a PCI error regular-0 error indication-1 no completion-2 */
define|#
directive|define
name|DMAE_COMMAND_ERR_POLICY_SHIFT
value|20
define|#
directive|define
name|DMAE_COMMAND_RESERVED0
value|(0x3FF<<22)
comment|/* BitField opcode	 */
define|#
directive|define
name|DMAE_COMMAND_RESERVED0_SHIFT
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
name|DMAE_COMMAND_SRC_VFID
value|(0x3F<<0)
comment|/* BitField opcode_iovE2 and onward, set to 0 for backward compatibility	source VF id */
define|#
directive|define
name|DMAE_COMMAND_SRC_VFID_SHIFT
value|0
define|#
directive|define
name|DMAE_COMMAND_SRC_VFPF
value|(0x1<<6)
comment|/* BitField opcode_iovE2 and onward, set to 0 for backward compatibility	selects the source function PF-0, VF-1 */
define|#
directive|define
name|DMAE_COMMAND_SRC_VFPF_SHIFT
value|6
define|#
directive|define
name|DMAE_COMMAND_RESERVED1
value|(0x1<<7)
comment|/* BitField opcode_iovE2 and onward, set to 0 for backward compatibility	 */
define|#
directive|define
name|DMAE_COMMAND_RESERVED1_SHIFT
value|7
define|#
directive|define
name|DMAE_COMMAND_DST_VFID
value|(0x3F<<8)
comment|/* BitField opcode_iovE2 and onward, set to 0 for backward compatibility	destination VF id */
define|#
directive|define
name|DMAE_COMMAND_DST_VFID_SHIFT
value|8
define|#
directive|define
name|DMAE_COMMAND_DST_VFPF
value|(0x1<<14)
comment|/* BitField opcode_iovE2 and onward, set to 0 for backward compatibility	selects the destination function PF-0, VF-1 */
define|#
directive|define
name|DMAE_COMMAND_DST_VFPF_SHIFT
value|14
define|#
directive|define
name|DMAE_COMMAND_RESERVED2
value|(0x1<<15)
comment|/* BitField opcode_iovE2 and onward, set to 0 for backward compatibility	 */
define|#
directive|define
name|DMAE_COMMAND_RESERVED2_SHIFT
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
name|DMAE_COMMAND_SRC_VFID
value|(0x3F<<0)
comment|/* BitField opcode_iovE2 and onward, set to 0 for backward compatibility	source VF id */
define|#
directive|define
name|DMAE_COMMAND_SRC_VFID_SHIFT
value|0
define|#
directive|define
name|DMAE_COMMAND_SRC_VFPF
value|(0x1<<6)
comment|/* BitField opcode_iovE2 and onward, set to 0 for backward compatibility	selects the source function PF-0, VF-1 */
define|#
directive|define
name|DMAE_COMMAND_SRC_VFPF_SHIFT
value|6
define|#
directive|define
name|DMAE_COMMAND_RESERVED1
value|(0x1<<7)
comment|/* BitField opcode_iovE2 and onward, set to 0 for backward compatibility	 */
define|#
directive|define
name|DMAE_COMMAND_RESERVED1_SHIFT
value|7
define|#
directive|define
name|DMAE_COMMAND_DST_VFID
value|(0x3F<<8)
comment|/* BitField opcode_iovE2 and onward, set to 0 for backward compatibility	destination VF id */
define|#
directive|define
name|DMAE_COMMAND_DST_VFID_SHIFT
value|8
define|#
directive|define
name|DMAE_COMMAND_DST_VFPF
value|(0x1<<14)
comment|/* BitField opcode_iovE2 and onward, set to 0 for backward compatibility	selects the destination function PF-0, VF-1 */
define|#
directive|define
name|DMAE_COMMAND_DST_VFPF_SHIFT
value|14
define|#
directive|define
name|DMAE_COMMAND_RESERVED2
value|(0x1<<15)
comment|/* BitField opcode_iovE2 and onward, set to 0 for backward compatibility	 */
define|#
directive|define
name|DMAE_COMMAND_RESERVED2_SHIFT
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
name|doorbell_hdr
block|{
name|uint8_t
name|header
decl_stmt|;
define|#
directive|define
name|DOORBELL_HDR_RX
value|(0x1<<0)
comment|/* BitField header	1 for rx doorbell, 0 for tx doorbell */
define|#
directive|define
name|DOORBELL_HDR_RX_SHIFT
value|0
define|#
directive|define
name|DOORBELL_HDR_DB_TYPE
value|(0x1<<1)
comment|/* BitField header	0 for normal doorbell, 1 for advertise wnd doorbell */
define|#
directive|define
name|DOORBELL_HDR_DB_TYPE_SHIFT
value|1
define|#
directive|define
name|DOORBELL_HDR_DPM_SIZE
value|(0x3<<2)
comment|/* BitField header	rdma tx only: DPM transaction size specifier (64/128/256/512 bytes) */
define|#
directive|define
name|DOORBELL_HDR_DPM_SIZE_SHIFT
value|2
define|#
directive|define
name|DOORBELL_HDR_CONN_TYPE
value|(0xF<<4)
comment|/* BitField header	connection type */
define|#
directive|define
name|DOORBELL_HDR_CONN_TYPE_SHIFT
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
name|doorbell_hdr
name|hdr
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|struct
name|doorbell_hdr
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
name|PARSING_FLAGS_VLAN
value|(0x1<<1)
comment|/* BitField flagscontext flags	0 or 1 */
define|#
directive|define
name|PARSING_FLAGS_VLAN_SHIFT
value|1
define|#
directive|define
name|PARSING_FLAGS_EXTRA_VLAN
value|(0x1<<2)
comment|/* BitField flagscontext flags	0 or 1 */
define|#
directive|define
name|PARSING_FLAGS_EXTRA_VLAN_SHIFT
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
name|__reserved_0
comment|/* data of client 0 of the timers block*/
decl_stmt|;
name|uint32_t
name|__reserved_1
comment|/* data of client 1 of the timers block*/
decl_stmt|;
name|uint32_t
name|__reserved_2
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
name|doorbell_hdr
name|header
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|struct
name|doorbell_hdr
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
name|doorbell_hdr
name|header
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|struct
name|doorbell_hdr
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
name|regpair
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
name|regpair_native
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
name|uint32_t
name|reserved0
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
name|regpair
name|bd_page_base
comment|/* BD page base address at the host */
decl_stmt|;
name|struct
name|regpair
name|sge_page_base
comment|/* SGE page base address at the host */
decl_stmt|;
name|struct
name|regpair
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
name|uint32_t
name|reserved6
index|[
literal|2
index|]
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
name|regpair
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
name|uint32_t
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
comment|/* BitField cmd_general_data	command opcode for MAC/VLAN/PAIR (use enum classify_rule) */
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
name|reserved5
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
name|ETH_FAST_PATH_RX_CQE_RESERVED0
value|(0x3<<6)
comment|/* BitField type_error_flags	 */
define|#
directive|define
name|ETH_FAST_PATH_RX_CQE_RESERVED0_SHIFT
value|6
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
name|uint32_t
name|reserved1
index|[
literal|8
index|]
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
name|regpair
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
comment|/*  * tunneling related data.  */
end_comment

begin_struct
struct|struct
name|eth_tunnel_data
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
name|fw_ip_hdr_csum
comment|/* Fw Ip header checksum (with ALL ip header fields) for the outer IP header */
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
name|fw_ip_hdr_csum
comment|/* Fw Ip header checksum (with ALL ip header fields) for the outer IP header */
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
name|flags
decl_stmt|;
define|#
directive|define
name|ETH_TUNNEL_DATA_IP_HDR_TYPE_OUTER
value|(0x1<<0)
comment|/* BitField flags	Set in case outer IP header is ipV6 */
define|#
directive|define
name|ETH_TUNNEL_DATA_IP_HDR_TYPE_OUTER_SHIFT
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
name|uint8_t
name|ip_hdr_start_inner_w
comment|/* Inner IP header offset in WORDs (16-bit) from start of packet */
decl_stmt|;
name|uint16_t
name|pseudo_csum
comment|/* Pseudo checksum with  length  field=0 */
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
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
name|ETH_TUNNEL_DATA_IP_HDR_TYPE_OUTER
value|(0x1<<0)
comment|/* BitField flags	Set in case outer IP header is ipV6 */
define|#
directive|define
name|ETH_TUNNEL_DATA_IP_HDR_TYPE_OUTER_SHIFT
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
endif|#
directive|endif
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
name|regpair
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
name|ETH_RSS_MODE_ESX51
comment|/* RSS mode for Vmware ESX 5.1 (Only do RSS if packet is UDP with dst port that matches the UDP 4-tuble Destination Port mask and value) */
block|,
name|ETH_RSS_MODE_REGULAR
comment|/* Regular (ndis-like) RSS */
block|,
name|ETH_RSS_MODE_VLAN_PRI
comment|/* RSS based on inner-vlan priority field */
block|,
name|ETH_RSS_MODE_E1HOV_PRI
comment|/* RSS based on outer-vlan priority field */
block|,
name|ETH_RSS_MODE_IP_DSCP
comment|/* RSS based on IPv4 DSCP field */
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
name|capabilities
decl_stmt|;
define|#
directive|define
name|ETH_RSS_UPDATE_RAMROD_DATA_IPV4_CAPABILITY
value|(0x1<<0)
comment|/* BitField capabilitiesFunction RSS capabilities	configuration of the IpV4 2-tupple capability */
define|#
directive|define
name|ETH_RSS_UPDATE_RAMROD_DATA_IPV4_CAPABILITY_SHIFT
value|0
define|#
directive|define
name|ETH_RSS_UPDATE_RAMROD_DATA_IPV4_TCP_CAPABILITY
value|(0x1<<1)
comment|/* BitField capabilitiesFunction RSS capabilities	configuration of the IpV4 4-tupple capability for TCP */
define|#
directive|define
name|ETH_RSS_UPDATE_RAMROD_DATA_IPV4_TCP_CAPABILITY_SHIFT
value|1
define|#
directive|define
name|ETH_RSS_UPDATE_RAMROD_DATA_IPV4_UDP_CAPABILITY
value|(0x1<<2)
comment|/* BitField capabilitiesFunction RSS capabilities	configuration of the IpV4 4-tupple capability for UDP */
define|#
directive|define
name|ETH_RSS_UPDATE_RAMROD_DATA_IPV4_UDP_CAPABILITY_SHIFT
value|2
define|#
directive|define
name|ETH_RSS_UPDATE_RAMROD_DATA_IPV6_CAPABILITY
value|(0x1<<3)
comment|/* BitField capabilitiesFunction RSS capabilities	configuration of the IpV6 2-tupple capability */
define|#
directive|define
name|ETH_RSS_UPDATE_RAMROD_DATA_IPV6_CAPABILITY_SHIFT
value|3
define|#
directive|define
name|ETH_RSS_UPDATE_RAMROD_DATA_IPV6_TCP_CAPABILITY
value|(0x1<<4)
comment|/* BitField capabilitiesFunction RSS capabilities	configuration of the IpV6 4-tupple capability for TCP */
define|#
directive|define
name|ETH_RSS_UPDATE_RAMROD_DATA_IPV6_TCP_CAPABILITY_SHIFT
value|4
define|#
directive|define
name|ETH_RSS_UPDATE_RAMROD_DATA_IPV6_UDP_CAPABILITY
value|(0x1<<5)
comment|/* BitField capabilitiesFunction RSS capabilities	configuration of the IpV6 4-tupple capability for UDP */
define|#
directive|define
name|ETH_RSS_UPDATE_RAMROD_DATA_IPV6_UDP_CAPABILITY_SHIFT
value|5
define|#
directive|define
name|ETH_RSS_UPDATE_RAMROD_DATA_EN_5_TUPLE_CAPABILITY
value|(0x1<<6)
comment|/* BitField capabilitiesFunction RSS capabilities	configuration of the 5-tupple capability */
define|#
directive|define
name|ETH_RSS_UPDATE_RAMROD_DATA_EN_5_TUPLE_CAPABILITY_SHIFT
value|6
define|#
directive|define
name|ETH_RSS_UPDATE_RAMROD_DATA_UPDATE_RSS_KEY
value|(0x1<<7)
comment|/* BitField capabilitiesFunction RSS capabilities	if set update the rss keys */
define|#
directive|define
name|ETH_RSS_UPDATE_RAMROD_DATA_UPDATE_RSS_KEY_SHIFT
value|7
name|uint8_t
name|rss_result_mask
comment|/* The mask for the lower byte of RSS result - defines which section of the indirection table will be used. To enable all table put here 0x7F */
decl_stmt|;
name|uint8_t
name|rss_mode
comment|/* The RSS mode for this function */
decl_stmt|;
name|uint16_t
name|udp_4tuple_dst_port_mask
comment|/* If UDP 4-tuple enabled, packets that match the mask and value are 4-tupled, the rest are 2-tupled. (Set to 0 to match all) */
decl_stmt|;
name|uint16_t
name|udp_4tuple_dst_port_value
comment|/* If UDP 4-tuple enabled, packets that match the mask and value are 4-tupled, the rest are 2-tupled. (Set to 0 to match all) */
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
name|reserved3
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
name|spe_hdr
block|{
name|uint32_t
name|conn_and_cmd_data
decl_stmt|;
define|#
directive|define
name|SPE_HDR_CID
value|(0xFFFFFF<<0)
comment|/* BitField conn_and_cmd_data	 */
define|#
directive|define
name|SPE_HDR_CID_SHIFT
value|0
define|#
directive|define
name|SPE_HDR_CMD_ID
value|(0xFF<<24)
comment|/* BitField conn_and_cmd_data	command id of the ramrod- use enum common_spqe_cmd_id/eth_spqe_cmd_id/toe_spqe_cmd_id  */
define|#
directive|define
name|SPE_HDR_CMD_ID_SHIFT
value|24
name|uint16_t
name|type
decl_stmt|;
define|#
directive|define
name|SPE_HDR_CONN_TYPE
value|(0xFF<<0)
comment|/* BitField type	connection type. (3 bits are used) (use enum connection_type) */
define|#
directive|define
name|SPE_HDR_CONN_TYPE_SHIFT
value|0
define|#
directive|define
name|SPE_HDR_FUNCTION_ID
value|(0xFF<<8)
comment|/* BitField type	 */
define|#
directive|define
name|SPE_HDR_FUNCTION_ID_SHIFT
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
name|regpair
name|client_update_ramrod_data
comment|/* The address of the data for client update ramrod */
decl_stmt|;
name|struct
name|regpair
name|client_init_ramrod_init_data
comment|/* The data for client setup ramrod */
decl_stmt|;
name|struct
name|eth_halt_ramrod_data
name|halt_ramrod_data
comment|/* Includes the client id to be deleted */
decl_stmt|;
name|struct
name|regpair
name|update_data_addr
comment|/* physical address of the eth_rss_update_ramrod_data struct, as allocated by the driver */
decl_stmt|;
name|struct
name|eth_common_ramrod_data
name|common_ramrod_data
comment|/* The data contain client ID need to the ramrod */
decl_stmt|;
name|struct
name|regpair
name|classify_cfg_addr
comment|/* physical address of the eth_classify_rules_ramrod_data struct, as allocated by the driver */
decl_stmt|;
name|struct
name|regpair
name|filter_cfg_addr
comment|/* physical address of the eth_filter_cfg_ramrod_data struct, as allocated by the driver */
decl_stmt|;
name|struct
name|regpair
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
name|spe_hdr
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
value|(0xF<<0)
comment|/* BitField general_data	contains the number of BDs that contain Ethernet/IP/TCP headers, for full/partial LSO modes */
define|#
directive|define
name|ETH_TX_START_BD_HDR_NBDS_SHIFT
value|0
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
name|uint16_t
name|reserved2
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
name|reserved3
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
name|regpair
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
name|regpair_native
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
name|regpair
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
comment|/* If set, inter-pf tx switching is allowed in Switch Independant function mode. (E2/E3 Only) */
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
name|gre_tunnel_mode
comment|/* GRE Tunnel Mode to enable on the Function (E2/E3 Only) */
decl_stmt|;
name|uint8_t
name|gre_tunnel_rss
comment|/* Type of RSS to perform on GRE Tunneled packets */
decl_stmt|;
name|uint8_t
name|nvgre_clss_en
comment|/* If set, NVGRE tunneled packets are classified according to their inner MAC (gre_mode must be NVGRE_TUNNEL) */
decl_stmt|;
name|uint16_t
name|reserved1
index|[
literal|2
index|]
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
name|reserved1
decl_stmt|;
name|uint8_t
name|update_gre_cfg_flg
comment|/* If set, GRE config for the function will be updated according to the gre_tunnel_rss and nvgre_clss_en fields */
decl_stmt|;
name|uint8_t
name|gre_tunnel_mode
comment|/* GRE Tunnel Mode to enable on the Function (E2/E3 Only) */
decl_stmt|;
name|uint8_t
name|gre_tunnel_rss
comment|/* Type of RSS to perform on GRE Tunneled packets */
decl_stmt|;
name|uint8_t
name|nvgre_clss_en
comment|/* If set, NVGRE tunneled packets are classified according to their inner MAC (gre_mode must be NVGRE_TUNNEL) */
decl_stmt|;
name|uint32_t
name|reserved3
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
comment|/*  * GRE RSS Mode  */
end_comment

begin_enum
enum|enum
name|gre_rss_mode
block|{
name|GRE_OUTER_HEADERS_RSS
comment|/* RSS for GRE Packets is performed on the outer headers */
block|,
name|GRE_INNER_HEADERS_RSS
comment|/* RSS for GRE Packets is performed on the inner headers */
block|,
name|NVGRE_KEY_ENTROPY_RSS
comment|/* RSS for NVGRE Packets is done based on a hash containing the entropy bits from the GRE Key Field (gre_tunnel must be NVGRE_TUNNEL) */
block|,
name|MAX_GRE_RSS_MODE
block|}
enum|;
end_enum

begin_comment
comment|/*  * GRE Tunnel Mode  */
end_comment

begin_enum
enum|enum
name|gre_tunnel_type
block|{
name|NO_GRE_TUNNEL
block|,
name|NVGRE_TUNNEL
comment|/* NV-GRE Tunneling Microsoft L2 over GRE. GRE header contains mandatory Key Field. */
block|,
name|L2GRE_TUNNEL
comment|/* L2-GRE Tunneling General L2 over GRE. GRE can contain Key field with Tenant ID and Sequence Field */
block|,
name|IPGRE_TUNNEL
comment|/* IP-GRE Tunneling IP over GRE. GRE may contain Key field with Tenant ID, Sequence Field and/or Checksum Field */
block|,
name|MAX_GRE_TUNNEL_TYPE
block|}
enum|;
end_enum

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
name|regpair_native
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
name|regpair_native
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
name|regpair_native
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
name|regpair
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
name|regpair
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
name|regpair
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
name|regpair
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
name|regpair
name|ucast_no_buff_bytes
comment|/* the number of unicast bytes received from network dropped because of no buffer at host */
decl_stmt|;
name|struct
name|regpair
name|mcast_no_buff_bytes
comment|/* the number of multicast bytes received from network dropped because of no buffer at host */
decl_stmt|;
name|struct
name|regpair
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
name|regpair
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
name|regpair
name|ucast_bytes_sent
comment|/* number of total bytes sent without errors */
decl_stmt|;
name|struct
name|regpair
name|mcast_bytes_sent
comment|/* number of total bytes sent without errors */
decl_stmt|;
name|struct
name|regpair
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
name|regpair
name|phy_address
comment|/* SPE physical address */
decl_stmt|;
name|struct
name|regpair
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
name|spe_hdr
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
name|regpair
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
name|spe_hdr
name|hdr
comment|/* common data for all protocols */
decl_stmt|;
name|struct
name|regpair
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
name|regpair
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
name|regpair
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
name|regpair
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
name|regpair
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
name|regpair
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
name|regpair
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
name|regpair
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
name|regpair
name|reserved
decl_stmt|;
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

