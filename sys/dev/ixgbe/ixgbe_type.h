begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************    Copyright (c) 2001-2017, Intel Corporation   All rights reserved.    Redistribution and use in source and binary forms, with or without   modification, are permitted provided that the following conditions are met:     1. Redistributions of source code must retain the above copyright notice,       this list of conditions and the following disclaimer.     2. Redistributions in binary form must reproduce the above copyright       notice, this list of conditions and the following disclaimer in the       documentation and/or other materials provided with the distribution.     3. Neither the name of the Intel Corporation nor the names of its       contributors may be used to endorse or promote products derived from       this software without specific prior written permission.    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE   IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE   ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE   LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS   INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN   CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)   ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE   POSSIBILITY OF SUCH DAMAGE.  ******************************************************************************/
end_comment

begin_comment
comment|/*$FreeBSD$*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IXGBE_TYPE_H_
end_ifndef

begin_define
define|#
directive|define
name|_IXGBE_TYPE_H_
end_define

begin_comment
comment|/*  * The following is a brief description of the error categories used by the  * ERROR_REPORT* macros.  *  * - IXGBE_ERROR_INVALID_STATE  * This category is for errors which represent a serious failure state that is  * unexpected, and could be potentially harmful to device operation. It should  * not be used for errors relating to issues that can be worked around or  * ignored.  *  * - IXGBE_ERROR_POLLING  * This category is for errors related to polling/timeout issues and should be  * used in any case where the timeout occurred, or a failure to obtain a lock, or  * failure to receive data within the time limit.  *  * - IXGBE_ERROR_CAUTION  * This category should be used for reporting issues that may be the cause of  * other errors, such as temperature warnings. It should indicate an event which  * could be serious, but hasn't necessarily caused problems yet.  *  * - IXGBE_ERROR_SOFTWARE  * This category is intended for errors due to software state preventing  * something. The category is not intended for errors due to bad arguments, or  * due to unsupported features. It should be used when a state occurs which  * prevents action but is not a serious issue.  *  * - IXGBE_ERROR_ARGUMENT  * This category is for when a bad or invalid argument is passed. It should be  * used whenever a function is called and error checking has detected the  * argument is wrong or incorrect.  *  * - IXGBE_ERROR_UNSUPPORTED  * This category is for errors which are due to unsupported circumstances or  * configuration issues. It should not be used when the issue is due to an  * invalid argument, but for when something has occurred that is unsupported  * (Ex: Flow control autonegotiation or an unsupported SFP+ module.)  */
end_comment

begin_include
include|#
directive|include
file|"ixgbe_osdep.h"
end_include

begin_comment
comment|/* Override this by setting IOMEM in your ixgbe_osdep.h header */
end_comment

begin_define
define|#
directive|define
name|IOMEM
end_define

begin_comment
comment|/* Vendor ID */
end_comment

begin_define
define|#
directive|define
name|IXGBE_INTEL_VENDOR_ID
value|0x8086
end_define

begin_comment
comment|/* Device IDs */
end_comment

begin_define
define|#
directive|define
name|IXGBE_DEV_ID_82598
value|0x10B6
end_define

begin_define
define|#
directive|define
name|IXGBE_DEV_ID_82598_BX
value|0x1508
end_define

begin_define
define|#
directive|define
name|IXGBE_DEV_ID_82598AF_DUAL_PORT
value|0x10C6
end_define

begin_define
define|#
directive|define
name|IXGBE_DEV_ID_82598AF_SINGLE_PORT
value|0x10C7
end_define

begin_define
define|#
directive|define
name|IXGBE_DEV_ID_82598AT
value|0x10C8
end_define

begin_define
define|#
directive|define
name|IXGBE_DEV_ID_82598AT2
value|0x150B
end_define

begin_define
define|#
directive|define
name|IXGBE_DEV_ID_82598EB_SFP_LOM
value|0x10DB
end_define

begin_define
define|#
directive|define
name|IXGBE_DEV_ID_82598EB_CX4
value|0x10DD
end_define

begin_define
define|#
directive|define
name|IXGBE_DEV_ID_82598_CX4_DUAL_PORT
value|0x10EC
end_define

begin_define
define|#
directive|define
name|IXGBE_DEV_ID_82598_DA_DUAL_PORT
value|0x10F1
end_define

begin_define
define|#
directive|define
name|IXGBE_DEV_ID_82598_SR_DUAL_PORT_EM
value|0x10E1
end_define

begin_define
define|#
directive|define
name|IXGBE_DEV_ID_82598EB_XF_LR
value|0x10F4
end_define

begin_define
define|#
directive|define
name|IXGBE_DEV_ID_82599_KX4
value|0x10F7
end_define

begin_define
define|#
directive|define
name|IXGBE_DEV_ID_82599_KX4_MEZZ
value|0x1514
end_define

begin_define
define|#
directive|define
name|IXGBE_DEV_ID_82599_KR
value|0x1517
end_define

begin_define
define|#
directive|define
name|IXGBE_DEV_ID_82599_COMBO_BACKPLANE
value|0x10F8
end_define

begin_define
define|#
directive|define
name|IXGBE_SUBDEV_ID_82599_KX4_KR_MEZZ
value|0x000C
end_define

begin_define
define|#
directive|define
name|IXGBE_DEV_ID_82599_CX4
value|0x10F9
end_define

begin_define
define|#
directive|define
name|IXGBE_DEV_ID_82599_SFP
value|0x10FB
end_define

begin_define
define|#
directive|define
name|IXGBE_SUBDEV_ID_82599_SFP
value|0x11A9
end_define

begin_define
define|#
directive|define
name|IXGBE_SUBDEV_ID_82599_SFP_WOL0
value|0x1071
end_define

begin_define
define|#
directive|define
name|IXGBE_SUBDEV_ID_82599_RNDC
value|0x1F72
end_define

begin_define
define|#
directive|define
name|IXGBE_SUBDEV_ID_82599_560FLR
value|0x17D0
end_define

begin_define
define|#
directive|define
name|IXGBE_SUBDEV_ID_82599_ECNA_DP
value|0x0470
end_define

begin_define
define|#
directive|define
name|IXGBE_SUBDEV_ID_82599_SP_560FLR
value|0x211B
end_define

begin_define
define|#
directive|define
name|IXGBE_SUBDEV_ID_82599_LOM_SNAP6
value|0x2159
end_define

begin_define
define|#
directive|define
name|IXGBE_SUBDEV_ID_82599_SFP_1OCP
value|0x000D
end_define

begin_define
define|#
directive|define
name|IXGBE_SUBDEV_ID_82599_SFP_2OCP
value|0x0008
end_define

begin_define
define|#
directive|define
name|IXGBE_SUBDEV_ID_82599_SFP_LOM_OEM1
value|0x8976
end_define

begin_define
define|#
directive|define
name|IXGBE_SUBDEV_ID_82599_SFP_LOM_OEM2
value|0x06EE
end_define

begin_define
define|#
directive|define
name|IXGBE_DEV_ID_82599_BACKPLANE_FCOE
value|0x152A
end_define

begin_define
define|#
directive|define
name|IXGBE_DEV_ID_82599_SFP_FCOE
value|0x1529
end_define

begin_define
define|#
directive|define
name|IXGBE_DEV_ID_82599_SFP_EM
value|0x1507
end_define

begin_define
define|#
directive|define
name|IXGBE_DEV_ID_82599_SFP_SF2
value|0x154D
end_define

begin_define
define|#
directive|define
name|IXGBE_DEV_ID_82599_SFP_SF_QP
value|0x154A
end_define

begin_define
define|#
directive|define
name|IXGBE_DEV_ID_82599_QSFP_SF_QP
value|0x1558
end_define

begin_define
define|#
directive|define
name|IXGBE_DEV_ID_82599EN_SFP
value|0x1557
end_define

begin_define
define|#
directive|define
name|IXGBE_SUBDEV_ID_82599EN_SFP_OCP1
value|0x0001
end_define

begin_define
define|#
directive|define
name|IXGBE_DEV_ID_82599_XAUI_LOM
value|0x10FC
end_define

begin_define
define|#
directive|define
name|IXGBE_DEV_ID_82599_T3_LOM
value|0x151C
end_define

begin_define
define|#
directive|define
name|IXGBE_DEV_ID_82599_VF
value|0x10ED
end_define

begin_define
define|#
directive|define
name|IXGBE_DEV_ID_82599_VF_HV
value|0x152E
end_define

begin_define
define|#
directive|define
name|IXGBE_DEV_ID_82599_BYPASS
value|0x155D
end_define

begin_define
define|#
directive|define
name|IXGBE_DEV_ID_X540T
value|0x1528
end_define

begin_define
define|#
directive|define
name|IXGBE_DEV_ID_X540_VF
value|0x1515
end_define

begin_define
define|#
directive|define
name|IXGBE_DEV_ID_X540_VF_HV
value|0x1530
end_define

begin_define
define|#
directive|define
name|IXGBE_DEV_ID_X540_BYPASS
value|0x155C
end_define

begin_define
define|#
directive|define
name|IXGBE_DEV_ID_X540T1
value|0x1560
end_define

begin_define
define|#
directive|define
name|IXGBE_DEV_ID_X550T
value|0x1563
end_define

begin_define
define|#
directive|define
name|IXGBE_DEV_ID_X550T1
value|0x15D1
end_define

begin_define
define|#
directive|define
name|IXGBE_DEV_ID_X550EM_A_KR
value|0x15C2
end_define

begin_define
define|#
directive|define
name|IXGBE_DEV_ID_X550EM_A_KR_L
value|0x15C3
end_define

begin_define
define|#
directive|define
name|IXGBE_DEV_ID_X550EM_A_SFP_N
value|0x15C4
end_define

begin_define
define|#
directive|define
name|IXGBE_DEV_ID_X550EM_A_SGMII
value|0x15C6
end_define

begin_define
define|#
directive|define
name|IXGBE_DEV_ID_X550EM_A_SGMII_L
value|0x15C7
end_define

begin_define
define|#
directive|define
name|IXGBE_DEV_ID_X550EM_A_10G_T
value|0x15C8
end_define

begin_define
define|#
directive|define
name|IXGBE_DEV_ID_X550EM_A_QSFP
value|0x15CA
end_define

begin_define
define|#
directive|define
name|IXGBE_DEV_ID_X550EM_A_QSFP_N
value|0x15CC
end_define

begin_define
define|#
directive|define
name|IXGBE_DEV_ID_X550EM_A_SFP
value|0x15CE
end_define

begin_define
define|#
directive|define
name|IXGBE_DEV_ID_X550EM_A_1G_T
value|0x15E4
end_define

begin_define
define|#
directive|define
name|IXGBE_DEV_ID_X550EM_A_1G_T_L
value|0x15E5
end_define

begin_define
define|#
directive|define
name|IXGBE_DEV_ID_X550EM_X_KX4
value|0x15AA
end_define

begin_define
define|#
directive|define
name|IXGBE_DEV_ID_X550EM_X_KR
value|0x15AB
end_define

begin_define
define|#
directive|define
name|IXGBE_DEV_ID_X550EM_X_SFP
value|0x15AC
end_define

begin_define
define|#
directive|define
name|IXGBE_DEV_ID_X550EM_X_10G_T
value|0x15AD
end_define

begin_define
define|#
directive|define
name|IXGBE_DEV_ID_X550EM_X_1G_T
value|0x15AE
end_define

begin_define
define|#
directive|define
name|IXGBE_DEV_ID_X550EM_X_XFI
value|0x15B0
end_define

begin_define
define|#
directive|define
name|IXGBE_DEV_ID_X550_VF_HV
value|0x1564
end_define

begin_define
define|#
directive|define
name|IXGBE_DEV_ID_X550_VF
value|0x1565
end_define

begin_define
define|#
directive|define
name|IXGBE_DEV_ID_X550EM_A_VF
value|0x15C5
end_define

begin_define
define|#
directive|define
name|IXGBE_DEV_ID_X550EM_A_VF_HV
value|0x15B4
end_define

begin_define
define|#
directive|define
name|IXGBE_DEV_ID_X550EM_X_VF
value|0x15A8
end_define

begin_define
define|#
directive|define
name|IXGBE_DEV_ID_X550EM_X_VF_HV
value|0x15A9
end_define

begin_define
define|#
directive|define
name|IXGBE_CAT
parameter_list|(
name|r
parameter_list|,
name|m
parameter_list|)
value|IXGBE_##r##m
end_define

begin_define
define|#
directive|define
name|IXGBE_BY_MAC
parameter_list|(
name|_hw
parameter_list|,
name|r
parameter_list|)
value|((_hw)->mvals[IXGBE_CAT(r, _IDX)])
end_define

begin_comment
comment|/* General Registers */
end_comment

begin_define
define|#
directive|define
name|IXGBE_CTRL
value|0x00000
end_define

begin_define
define|#
directive|define
name|IXGBE_STATUS
value|0x00008
end_define

begin_define
define|#
directive|define
name|IXGBE_CTRL_EXT
value|0x00018
end_define

begin_define
define|#
directive|define
name|IXGBE_ESDP
value|0x00020
end_define

begin_define
define|#
directive|define
name|IXGBE_EODSDP
value|0x00028
end_define

begin_define
define|#
directive|define
name|IXGBE_I2CCTL_82599
value|0x00028
end_define

begin_define
define|#
directive|define
name|IXGBE_I2CCTL
value|IXGBE_I2CCTL_82599
end_define

begin_define
define|#
directive|define
name|IXGBE_I2CCTL_X540
value|IXGBE_I2CCTL_82599
end_define

begin_define
define|#
directive|define
name|IXGBE_I2CCTL_X550
value|0x15F5C
end_define

begin_define
define|#
directive|define
name|IXGBE_I2CCTL_X550EM_x
value|IXGBE_I2CCTL_X550
end_define

begin_define
define|#
directive|define
name|IXGBE_I2CCTL_X550EM_a
value|IXGBE_I2CCTL_X550
end_define

begin_define
define|#
directive|define
name|IXGBE_I2CCTL_BY_MAC
parameter_list|(
name|_hw
parameter_list|)
value|IXGBE_BY_MAC((_hw), I2CCTL)
end_define

begin_define
define|#
directive|define
name|IXGBE_PHY_GPIO
value|0x00028
end_define

begin_define
define|#
directive|define
name|IXGBE_MAC_GPIO
value|0x00030
end_define

begin_define
define|#
directive|define
name|IXGBE_PHYINT_STATUS0
value|0x00100
end_define

begin_define
define|#
directive|define
name|IXGBE_PHYINT_STATUS1
value|0x00104
end_define

begin_define
define|#
directive|define
name|IXGBE_PHYINT_STATUS2
value|0x00108
end_define

begin_define
define|#
directive|define
name|IXGBE_LEDCTL
value|0x00200
end_define

begin_define
define|#
directive|define
name|IXGBE_FRTIMER
value|0x00048
end_define

begin_define
define|#
directive|define
name|IXGBE_TCPTIMER
value|0x0004C
end_define

begin_define
define|#
directive|define
name|IXGBE_CORESPARE
value|0x00600
end_define

begin_define
define|#
directive|define
name|IXGBE_EXVET
value|0x05078
end_define

begin_comment
comment|/* NVM Registers */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EEC
value|0x10010
end_define

begin_define
define|#
directive|define
name|IXGBE_EEC_X540
value|IXGBE_EEC
end_define

begin_define
define|#
directive|define
name|IXGBE_EEC_X550
value|IXGBE_EEC
end_define

begin_define
define|#
directive|define
name|IXGBE_EEC_X550EM_x
value|IXGBE_EEC
end_define

begin_define
define|#
directive|define
name|IXGBE_EEC_X550EM_a
value|0x15FF8
end_define

begin_define
define|#
directive|define
name|IXGBE_EEC_BY_MAC
parameter_list|(
name|_hw
parameter_list|)
value|IXGBE_BY_MAC((_hw), EEC)
end_define

begin_define
define|#
directive|define
name|IXGBE_EERD
value|0x10014
end_define

begin_define
define|#
directive|define
name|IXGBE_EEWR
value|0x10018
end_define

begin_define
define|#
directive|define
name|IXGBE_FLA
value|0x1001C
end_define

begin_define
define|#
directive|define
name|IXGBE_FLA_X540
value|IXGBE_FLA
end_define

begin_define
define|#
directive|define
name|IXGBE_FLA_X550
value|IXGBE_FLA
end_define

begin_define
define|#
directive|define
name|IXGBE_FLA_X550EM_x
value|IXGBE_FLA
end_define

begin_define
define|#
directive|define
name|IXGBE_FLA_X550EM_a
value|0x15F68
end_define

begin_define
define|#
directive|define
name|IXGBE_FLA_BY_MAC
parameter_list|(
name|_hw
parameter_list|)
value|IXGBE_BY_MAC((_hw), FLA)
end_define

begin_define
define|#
directive|define
name|IXGBE_EEMNGCTL
value|0x10110
end_define

begin_define
define|#
directive|define
name|IXGBE_EEMNGDATA
value|0x10114
end_define

begin_define
define|#
directive|define
name|IXGBE_FLMNGCTL
value|0x10118
end_define

begin_define
define|#
directive|define
name|IXGBE_FLMNGDATA
value|0x1011C
end_define

begin_define
define|#
directive|define
name|IXGBE_FLMNGCNT
value|0x10120
end_define

begin_define
define|#
directive|define
name|IXGBE_FLOP
value|0x1013C
end_define

begin_define
define|#
directive|define
name|IXGBE_GRC
value|0x10200
end_define

begin_define
define|#
directive|define
name|IXGBE_GRC_X540
value|IXGBE_GRC
end_define

begin_define
define|#
directive|define
name|IXGBE_GRC_X550
value|IXGBE_GRC
end_define

begin_define
define|#
directive|define
name|IXGBE_GRC_X550EM_x
value|IXGBE_GRC
end_define

begin_define
define|#
directive|define
name|IXGBE_GRC_X550EM_a
value|0x15F64
end_define

begin_define
define|#
directive|define
name|IXGBE_GRC_BY_MAC
parameter_list|(
name|_hw
parameter_list|)
value|IXGBE_BY_MAC((_hw), GRC)
end_define

begin_define
define|#
directive|define
name|IXGBE_SRAMREL
value|0x10210
end_define

begin_define
define|#
directive|define
name|IXGBE_SRAMREL_X540
value|IXGBE_SRAMREL
end_define

begin_define
define|#
directive|define
name|IXGBE_SRAMREL_X550
value|IXGBE_SRAMREL
end_define

begin_define
define|#
directive|define
name|IXGBE_SRAMREL_X550EM_x
value|IXGBE_SRAMREL
end_define

begin_define
define|#
directive|define
name|IXGBE_SRAMREL_X550EM_a
value|0x15F6C
end_define

begin_define
define|#
directive|define
name|IXGBE_SRAMREL_BY_MAC
parameter_list|(
name|_hw
parameter_list|)
value|IXGBE_BY_MAC((_hw), SRAMREL)
end_define

begin_define
define|#
directive|define
name|IXGBE_PHYDBG
value|0x10218
end_define

begin_comment
comment|/* General Receive Control */
end_comment

begin_define
define|#
directive|define
name|IXGBE_GRC_MNG
value|0x00000001
end_define

begin_comment
comment|/* Manageability Enable */
end_comment

begin_define
define|#
directive|define
name|IXGBE_GRC_APME
value|0x00000002
end_define

begin_comment
comment|/* APM enabled in EEPROM */
end_comment

begin_define
define|#
directive|define
name|IXGBE_VPDDIAG0
value|0x10204
end_define

begin_define
define|#
directive|define
name|IXGBE_VPDDIAG1
value|0x10208
end_define

begin_comment
comment|/* I2CCTL Bit Masks */
end_comment

begin_define
define|#
directive|define
name|IXGBE_I2C_CLK_IN
value|0x00000001
end_define

begin_define
define|#
directive|define
name|IXGBE_I2C_CLK_IN_X540
value|IXGBE_I2C_CLK_IN
end_define

begin_define
define|#
directive|define
name|IXGBE_I2C_CLK_IN_X550
value|0x00004000
end_define

begin_define
define|#
directive|define
name|IXGBE_I2C_CLK_IN_X550EM_x
value|IXGBE_I2C_CLK_IN_X550
end_define

begin_define
define|#
directive|define
name|IXGBE_I2C_CLK_IN_X550EM_a
value|IXGBE_I2C_CLK_IN_X550
end_define

begin_define
define|#
directive|define
name|IXGBE_I2C_CLK_IN_BY_MAC
parameter_list|(
name|_hw
parameter_list|)
value|IXGBE_BY_MAC((_hw), I2C_CLK_IN)
end_define

begin_define
define|#
directive|define
name|IXGBE_I2C_CLK_OUT
value|0x00000002
end_define

begin_define
define|#
directive|define
name|IXGBE_I2C_CLK_OUT_X540
value|IXGBE_I2C_CLK_OUT
end_define

begin_define
define|#
directive|define
name|IXGBE_I2C_CLK_OUT_X550
value|0x00000200
end_define

begin_define
define|#
directive|define
name|IXGBE_I2C_CLK_OUT_X550EM_x
value|IXGBE_I2C_CLK_OUT_X550
end_define

begin_define
define|#
directive|define
name|IXGBE_I2C_CLK_OUT_X550EM_a
value|IXGBE_I2C_CLK_OUT_X550
end_define

begin_define
define|#
directive|define
name|IXGBE_I2C_CLK_OUT_BY_MAC
parameter_list|(
name|_hw
parameter_list|)
value|IXGBE_BY_MAC((_hw), I2C_CLK_OUT)
end_define

begin_define
define|#
directive|define
name|IXGBE_I2C_DATA_IN
value|0x00000004
end_define

begin_define
define|#
directive|define
name|IXGBE_I2C_DATA_IN_X540
value|IXGBE_I2C_DATA_IN
end_define

begin_define
define|#
directive|define
name|IXGBE_I2C_DATA_IN_X550
value|0x00001000
end_define

begin_define
define|#
directive|define
name|IXGBE_I2C_DATA_IN_X550EM_x
value|IXGBE_I2C_DATA_IN_X550
end_define

begin_define
define|#
directive|define
name|IXGBE_I2C_DATA_IN_X550EM_a
value|IXGBE_I2C_DATA_IN_X550
end_define

begin_define
define|#
directive|define
name|IXGBE_I2C_DATA_IN_BY_MAC
parameter_list|(
name|_hw
parameter_list|)
value|IXGBE_BY_MAC((_hw), I2C_DATA_IN)
end_define

begin_define
define|#
directive|define
name|IXGBE_I2C_DATA_OUT
value|0x00000008
end_define

begin_define
define|#
directive|define
name|IXGBE_I2C_DATA_OUT_X540
value|IXGBE_I2C_DATA_OUT
end_define

begin_define
define|#
directive|define
name|IXGBE_I2C_DATA_OUT_X550
value|0x00000400
end_define

begin_define
define|#
directive|define
name|IXGBE_I2C_DATA_OUT_X550EM_x
value|IXGBE_I2C_DATA_OUT_X550
end_define

begin_define
define|#
directive|define
name|IXGBE_I2C_DATA_OUT_X550EM_a
value|IXGBE_I2C_DATA_OUT_X550
end_define

begin_define
define|#
directive|define
name|IXGBE_I2C_DATA_OUT_BY_MAC
parameter_list|(
name|_hw
parameter_list|)
value|IXGBE_BY_MAC((_hw), I2C_DATA_OUT)
end_define

begin_define
define|#
directive|define
name|IXGBE_I2C_DATA_OE_N_EN
value|0
end_define

begin_define
define|#
directive|define
name|IXGBE_I2C_DATA_OE_N_EN_X540
value|IXGBE_I2C_DATA_OE_N_EN
end_define

begin_define
define|#
directive|define
name|IXGBE_I2C_DATA_OE_N_EN_X550
value|0x00000800
end_define

begin_define
define|#
directive|define
name|IXGBE_I2C_DATA_OE_N_EN_X550EM_x
value|IXGBE_I2C_DATA_OE_N_EN_X550
end_define

begin_define
define|#
directive|define
name|IXGBE_I2C_DATA_OE_N_EN_X550EM_a
value|IXGBE_I2C_DATA_OE_N_EN_X550
end_define

begin_define
define|#
directive|define
name|IXGBE_I2C_DATA_OE_N_EN_BY_MAC
parameter_list|(
name|_hw
parameter_list|)
value|IXGBE_BY_MAC((_hw), I2C_DATA_OE_N_EN)
end_define

begin_define
define|#
directive|define
name|IXGBE_I2C_BB_EN
value|0
end_define

begin_define
define|#
directive|define
name|IXGBE_I2C_BB_EN_X540
value|IXGBE_I2C_BB_EN
end_define

begin_define
define|#
directive|define
name|IXGBE_I2C_BB_EN_X550
value|0x00000100
end_define

begin_define
define|#
directive|define
name|IXGBE_I2C_BB_EN_X550EM_x
value|IXGBE_I2C_BB_EN_X550
end_define

begin_define
define|#
directive|define
name|IXGBE_I2C_BB_EN_X550EM_a
value|IXGBE_I2C_BB_EN_X550
end_define

begin_define
define|#
directive|define
name|IXGBE_I2C_BB_EN_BY_MAC
parameter_list|(
name|_hw
parameter_list|)
value|IXGBE_BY_MAC((_hw), I2C_BB_EN)
end_define

begin_define
define|#
directive|define
name|IXGBE_I2C_CLK_OE_N_EN
value|0
end_define

begin_define
define|#
directive|define
name|IXGBE_I2C_CLK_OE_N_EN_X540
value|IXGBE_I2C_CLK_OE_N_EN
end_define

begin_define
define|#
directive|define
name|IXGBE_I2C_CLK_OE_N_EN_X550
value|0x00002000
end_define

begin_define
define|#
directive|define
name|IXGBE_I2C_CLK_OE_N_EN_X550EM_x
value|IXGBE_I2C_CLK_OE_N_EN_X550
end_define

begin_define
define|#
directive|define
name|IXGBE_I2C_CLK_OE_N_EN_X550EM_a
value|IXGBE_I2C_CLK_OE_N_EN_X550
end_define

begin_define
define|#
directive|define
name|IXGBE_I2C_CLK_OE_N_EN_BY_MAC
parameter_list|(
name|_hw
parameter_list|)
value|IXGBE_BY_MAC((_hw), I2C_CLK_OE_N_EN)
end_define

begin_define
define|#
directive|define
name|IXGBE_I2C_CLOCK_STRETCHING_TIMEOUT
value|500
end_define

begin_comment
comment|/* Interrupt Registers */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EICR
value|0x00800
end_define

begin_define
define|#
directive|define
name|IXGBE_EICS
value|0x00808
end_define

begin_define
define|#
directive|define
name|IXGBE_EIMS
value|0x00880
end_define

begin_define
define|#
directive|define
name|IXGBE_EIMC
value|0x00888
end_define

begin_define
define|#
directive|define
name|IXGBE_EIAC
value|0x00810
end_define

begin_define
define|#
directive|define
name|IXGBE_EIAM
value|0x00890
end_define

begin_define
define|#
directive|define
name|IXGBE_EICS_EX
parameter_list|(
name|_i
parameter_list|)
value|(0x00A90 + (_i) * 4)
end_define

begin_define
define|#
directive|define
name|IXGBE_EIMS_EX
parameter_list|(
name|_i
parameter_list|)
value|(0x00AA0 + (_i) * 4)
end_define

begin_define
define|#
directive|define
name|IXGBE_EIMC_EX
parameter_list|(
name|_i
parameter_list|)
value|(0x00AB0 + (_i) * 4)
end_define

begin_define
define|#
directive|define
name|IXGBE_EIAM_EX
parameter_list|(
name|_i
parameter_list|)
value|(0x00AD0 + (_i) * 4)
end_define

begin_comment
comment|/* 82599 EITR is only 12 bits, with the lower 3 always zero */
end_comment

begin_comment
comment|/*  * 82598 EITR is 16 bits but set the limits based on the max  * supported by all ixgbe hardware  */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MAX_INT_RATE
value|488281
end_define

begin_define
define|#
directive|define
name|IXGBE_MIN_INT_RATE
value|956
end_define

begin_define
define|#
directive|define
name|IXGBE_MAX_EITR
value|0x00000FF8
end_define

begin_define
define|#
directive|define
name|IXGBE_MIN_EITR
value|8
end_define

begin_define
define|#
directive|define
name|IXGBE_EITR
parameter_list|(
name|_i
parameter_list|)
value|(((_i)<= 23) ? (0x00820 + ((_i) * 4)) : \ 				 (0x012300 + (((_i) - 24) * 4)))
end_define

begin_define
define|#
directive|define
name|IXGBE_EITR_ITR_INT_MASK
value|0x00000FF8
end_define

begin_define
define|#
directive|define
name|IXGBE_EITR_LLI_MOD
value|0x00008000
end_define

begin_define
define|#
directive|define
name|IXGBE_EITR_CNT_WDIS
value|0x80000000
end_define

begin_define
define|#
directive|define
name|IXGBE_IVAR
parameter_list|(
name|_i
parameter_list|)
value|(0x00900 + ((_i) * 4))
end_define

begin_comment
comment|/* 24 at 0x900-0x960 */
end_comment

begin_define
define|#
directive|define
name|IXGBE_IVAR_MISC
value|0x00A00
end_define

begin_comment
comment|/* misc MSI-X interrupt causes */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EITRSEL
value|0x00894
end_define

begin_define
define|#
directive|define
name|IXGBE_MSIXT
value|0x00000
end_define

begin_comment
comment|/* MSI-X Table. 0x0000 - 0x01C */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MSIXPBA
value|0x02000
end_define

begin_comment
comment|/* MSI-X Pending bit array */
end_comment

begin_define
define|#
directive|define
name|IXGBE_PBACL
parameter_list|(
name|_i
parameter_list|)
value|(((_i) == 0) ? (0x11068) : (0x110C0 + ((_i) * 4)))
end_define

begin_define
define|#
directive|define
name|IXGBE_GPIE
value|0x00898
end_define

begin_comment
comment|/* Flow Control Registers */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FCADBUL
value|0x03210
end_define

begin_define
define|#
directive|define
name|IXGBE_FCADBUH
value|0x03214
end_define

begin_define
define|#
directive|define
name|IXGBE_FCAMACL
value|0x04328
end_define

begin_define
define|#
directive|define
name|IXGBE_FCAMACH
value|0x0432C
end_define

begin_define
define|#
directive|define
name|IXGBE_FCRTH_82599
parameter_list|(
name|_i
parameter_list|)
value|(0x03260 + ((_i) * 4))
end_define

begin_comment
comment|/* 8 of these (0-7) */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FCRTL_82599
parameter_list|(
name|_i
parameter_list|)
value|(0x03220 + ((_i) * 4))
end_define

begin_comment
comment|/* 8 of these (0-7) */
end_comment

begin_define
define|#
directive|define
name|IXGBE_PFCTOP
value|0x03008
end_define

begin_define
define|#
directive|define
name|IXGBE_FCTTV
parameter_list|(
name|_i
parameter_list|)
value|(0x03200 + ((_i) * 4))
end_define

begin_comment
comment|/* 4 of these (0-3) */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FCRTL
parameter_list|(
name|_i
parameter_list|)
value|(0x03220 + ((_i) * 8))
end_define

begin_comment
comment|/* 8 of these (0-7) */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FCRTH
parameter_list|(
name|_i
parameter_list|)
value|(0x03260 + ((_i) * 8))
end_define

begin_comment
comment|/* 8 of these (0-7) */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FCRTV
value|0x032A0
end_define

begin_define
define|#
directive|define
name|IXGBE_FCCFG
value|0x03D00
end_define

begin_define
define|#
directive|define
name|IXGBE_TFCS
value|0x0CE00
end_define

begin_comment
comment|/* Receive DMA Registers */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RDBAL
parameter_list|(
name|_i
parameter_list|)
value|(((_i)< 64) ? (0x01000 + ((_i) * 0x40)) : \ 			 (0x0D000 + (((_i) - 64) * 0x40)))
end_define

begin_define
define|#
directive|define
name|IXGBE_RDBAH
parameter_list|(
name|_i
parameter_list|)
value|(((_i)< 64) ? (0x01004 + ((_i) * 0x40)) : \ 			 (0x0D004 + (((_i) - 64) * 0x40)))
end_define

begin_define
define|#
directive|define
name|IXGBE_RDLEN
parameter_list|(
name|_i
parameter_list|)
value|(((_i)< 64) ? (0x01008 + ((_i) * 0x40)) : \ 			 (0x0D008 + (((_i) - 64) * 0x40)))
end_define

begin_define
define|#
directive|define
name|IXGBE_RDH
parameter_list|(
name|_i
parameter_list|)
value|(((_i)< 64) ? (0x01010 + ((_i) * 0x40)) : \ 			 (0x0D010 + (((_i) - 64) * 0x40)))
end_define

begin_define
define|#
directive|define
name|IXGBE_RDT
parameter_list|(
name|_i
parameter_list|)
value|(((_i)< 64) ? (0x01018 + ((_i) * 0x40)) : \ 			 (0x0D018 + (((_i) - 64) * 0x40)))
end_define

begin_define
define|#
directive|define
name|IXGBE_RXDCTL
parameter_list|(
name|_i
parameter_list|)
value|(((_i)< 64) ? (0x01028 + ((_i) * 0x40)) : \ 				 (0x0D028 + (((_i) - 64) * 0x40)))
end_define

begin_define
define|#
directive|define
name|IXGBE_RSCCTL
parameter_list|(
name|_i
parameter_list|)
value|(((_i)< 64) ? (0x0102C + ((_i) * 0x40)) : \ 				 (0x0D02C + (((_i) - 64) * 0x40)))
end_define

begin_define
define|#
directive|define
name|IXGBE_RSCDBU
value|0x03028
end_define

begin_define
define|#
directive|define
name|IXGBE_RDDCC
value|0x02F20
end_define

begin_define
define|#
directive|define
name|IXGBE_RXMEMWRAP
value|0x03190
end_define

begin_define
define|#
directive|define
name|IXGBE_STARCTRL
value|0x03024
end_define

begin_comment
comment|/*  * Split and Replication Receive Control Registers  * 00-15 : 0x02100 + n*4  * 16-64 : 0x01014 + n*0x40  * 64-127: 0x0D014 + (n-64)*0x40  */
end_comment

begin_define
define|#
directive|define
name|IXGBE_SRRCTL
parameter_list|(
name|_i
parameter_list|)
value|(((_i)<= 15) ? (0x02100 + ((_i) * 4)) : \ 				 (((_i)< 64) ? (0x01014 + ((_i) * 0x40)) : \ 				 (0x0D014 + (((_i) - 64) * 0x40))))
end_define

begin_comment
comment|/*  * Rx DCA Control Register:  * 00-15 : 0x02200 + n*4  * 16-64 : 0x0100C + n*0x40  * 64-127: 0x0D00C + (n-64)*0x40  */
end_comment

begin_define
define|#
directive|define
name|IXGBE_DCA_RXCTRL
parameter_list|(
name|_i
parameter_list|)
value|(((_i)<= 15) ? (0x02200 + ((_i) * 4)) : \ 				 (((_i)< 64) ? (0x0100C + ((_i) * 0x40)) : \ 				 (0x0D00C + (((_i) - 64) * 0x40))))
end_define

begin_define
define|#
directive|define
name|IXGBE_RDRXCTL
value|0x02F00
end_define

begin_comment
comment|/* 8 of these 0x03C00 - 0x03C1C */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXPBSIZE
parameter_list|(
name|_i
parameter_list|)
value|(0x03C00 + ((_i) * 4))
end_define

begin_define
define|#
directive|define
name|IXGBE_RXCTRL
value|0x03000
end_define

begin_define
define|#
directive|define
name|IXGBE_DROPEN
value|0x03D04
end_define

begin_define
define|#
directive|define
name|IXGBE_RXPBSIZE_SHIFT
value|10
end_define

begin_define
define|#
directive|define
name|IXGBE_RXPBSIZE_MASK
value|0x000FFC00
end_define

begin_comment
comment|/* Receive Registers */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXCSUM
value|0x05000
end_define

begin_define
define|#
directive|define
name|IXGBE_RFCTL
value|0x05008
end_define

begin_define
define|#
directive|define
name|IXGBE_DRECCCTL
value|0x02F08
end_define

begin_define
define|#
directive|define
name|IXGBE_DRECCCTL_DISABLE
value|0
end_define

begin_define
define|#
directive|define
name|IXGBE_DRECCCTL2
value|0x02F8C
end_define

begin_comment
comment|/* Multicast Table Array - 128 entries */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MTA
parameter_list|(
name|_i
parameter_list|)
value|(0x05200 + ((_i) * 4))
end_define

begin_define
define|#
directive|define
name|IXGBE_RAL
parameter_list|(
name|_i
parameter_list|)
value|(((_i)<= 15) ? (0x05400 + ((_i) * 8)) : \ 				 (0x0A200 + ((_i) * 8)))
end_define

begin_define
define|#
directive|define
name|IXGBE_RAH
parameter_list|(
name|_i
parameter_list|)
value|(((_i)<= 15) ? (0x05404 + ((_i) * 8)) : \ 				 (0x0A204 + ((_i) * 8)))
end_define

begin_define
define|#
directive|define
name|IXGBE_MPSAR_LO
parameter_list|(
name|_i
parameter_list|)
value|(0x0A600 + ((_i) * 8))
end_define

begin_define
define|#
directive|define
name|IXGBE_MPSAR_HI
parameter_list|(
name|_i
parameter_list|)
value|(0x0A604 + ((_i) * 8))
end_define

begin_comment
comment|/* Packet split receive type */
end_comment

begin_define
define|#
directive|define
name|IXGBE_PSRTYPE
parameter_list|(
name|_i
parameter_list|)
value|(((_i)<= 15) ? (0x05480 + ((_i) * 4)) : \ 				 (0x0EA00 + ((_i) * 4)))
end_define

begin_comment
comment|/* array of 4096 1-bit vlan filters */
end_comment

begin_define
define|#
directive|define
name|IXGBE_VFTA
parameter_list|(
name|_i
parameter_list|)
value|(0x0A000 + ((_i) * 4))
end_define

begin_comment
comment|/*array of 4096 4-bit vlan vmdq indices */
end_comment

begin_define
define|#
directive|define
name|IXGBE_VFTAVIND
parameter_list|(
name|_j
parameter_list|,
name|_i
parameter_list|)
value|(0x0A200 + ((_j) * 0x200) + ((_i) * 4))
end_define

begin_define
define|#
directive|define
name|IXGBE_FCTRL
value|0x05080
end_define

begin_define
define|#
directive|define
name|IXGBE_VLNCTRL
value|0x05088
end_define

begin_define
define|#
directive|define
name|IXGBE_MCSTCTRL
value|0x05090
end_define

begin_define
define|#
directive|define
name|IXGBE_MRQC
value|0x05818
end_define

begin_define
define|#
directive|define
name|IXGBE_SAQF
parameter_list|(
name|_i
parameter_list|)
value|(0x0E000 + ((_i) * 4))
end_define

begin_comment
comment|/* Source Address Queue Filter */
end_comment

begin_define
define|#
directive|define
name|IXGBE_DAQF
parameter_list|(
name|_i
parameter_list|)
value|(0x0E200 + ((_i) * 4))
end_define

begin_comment
comment|/* Dest. Address Queue Filter */
end_comment

begin_define
define|#
directive|define
name|IXGBE_SDPQF
parameter_list|(
name|_i
parameter_list|)
value|(0x0E400 + ((_i) * 4))
end_define

begin_comment
comment|/* Src Dest. Addr Queue Filter */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FTQF
parameter_list|(
name|_i
parameter_list|)
value|(0x0E600 + ((_i) * 4))
end_define

begin_comment
comment|/* Five Tuple Queue Filter */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ETQF
parameter_list|(
name|_i
parameter_list|)
value|(0x05128 + ((_i) * 4))
end_define

begin_comment
comment|/* EType Queue Filter */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ETQS
parameter_list|(
name|_i
parameter_list|)
value|(0x0EC00 + ((_i) * 4))
end_define

begin_comment
comment|/* EType Queue Select */
end_comment

begin_define
define|#
directive|define
name|IXGBE_SYNQF
value|0x0EC30
end_define

begin_comment
comment|/* SYN Packet Queue Filter */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RQTC
value|0x0EC70
end_define

begin_define
define|#
directive|define
name|IXGBE_MTQC
value|0x08120
end_define

begin_define
define|#
directive|define
name|IXGBE_VLVF
parameter_list|(
name|_i
parameter_list|)
value|(0x0F100 + ((_i) * 4))
end_define

begin_comment
comment|/* 64 of these (0-63) */
end_comment

begin_define
define|#
directive|define
name|IXGBE_VLVFB
parameter_list|(
name|_i
parameter_list|)
value|(0x0F200 + ((_i) * 4))
end_define

begin_comment
comment|/* 128 of these (0-127) */
end_comment

begin_define
define|#
directive|define
name|IXGBE_VMVIR
parameter_list|(
name|_i
parameter_list|)
value|(0x08000 + ((_i) * 4))
end_define

begin_comment
comment|/* 64 of these (0-63) */
end_comment

begin_define
define|#
directive|define
name|IXGBE_PFFLPL
value|0x050B0
end_define

begin_define
define|#
directive|define
name|IXGBE_PFFLPH
value|0x050B4
end_define

begin_define
define|#
directive|define
name|IXGBE_VT_CTL
value|0x051B0
end_define

begin_define
define|#
directive|define
name|IXGBE_PFMAILBOX
parameter_list|(
name|_i
parameter_list|)
value|(0x04B00 + (4 * (_i)))
end_define

begin_comment
comment|/* 64 total */
end_comment

begin_comment
comment|/* 64 Mailboxes, 16 DW each */
end_comment

begin_define
define|#
directive|define
name|IXGBE_PFMBMEM
parameter_list|(
name|_i
parameter_list|)
value|(0x13000 + (64 * (_i)))
end_define

begin_define
define|#
directive|define
name|IXGBE_PFMBICR
parameter_list|(
name|_i
parameter_list|)
value|(0x00710 + (4 * (_i)))
end_define

begin_comment
comment|/* 4 total */
end_comment

begin_define
define|#
directive|define
name|IXGBE_PFMBIMR
parameter_list|(
name|_i
parameter_list|)
value|(0x00720 + (4 * (_i)))
end_define

begin_comment
comment|/* 4 total */
end_comment

begin_define
define|#
directive|define
name|IXGBE_VFRE
parameter_list|(
name|_i
parameter_list|)
value|(0x051E0 + ((_i) * 4))
end_define

begin_define
define|#
directive|define
name|IXGBE_VFTE
parameter_list|(
name|_i
parameter_list|)
value|(0x08110 + ((_i) * 4))
end_define

begin_define
define|#
directive|define
name|IXGBE_VMECM
parameter_list|(
name|_i
parameter_list|)
value|(0x08790 + ((_i) * 4))
end_define

begin_define
define|#
directive|define
name|IXGBE_QDE
value|0x2F04
end_define

begin_define
define|#
directive|define
name|IXGBE_VMTXSW
parameter_list|(
name|_i
parameter_list|)
value|(0x05180 + ((_i) * 4))
end_define

begin_comment
comment|/* 2 total */
end_comment

begin_define
define|#
directive|define
name|IXGBE_VMOLR
parameter_list|(
name|_i
parameter_list|)
value|(0x0F000 + ((_i) * 4))
end_define

begin_comment
comment|/* 64 total */
end_comment

begin_define
define|#
directive|define
name|IXGBE_UTA
parameter_list|(
name|_i
parameter_list|)
value|(0x0F400 + ((_i) * 4))
end_define

begin_define
define|#
directive|define
name|IXGBE_MRCTL
parameter_list|(
name|_i
parameter_list|)
value|(0x0F600 + ((_i) * 4))
end_define

begin_define
define|#
directive|define
name|IXGBE_VMRVLAN
parameter_list|(
name|_i
parameter_list|)
value|(0x0F610 + ((_i) * 4))
end_define

begin_define
define|#
directive|define
name|IXGBE_VMRVM
parameter_list|(
name|_i
parameter_list|)
value|(0x0F630 + ((_i) * 4))
end_define

begin_define
define|#
directive|define
name|IXGBE_LVMMC_RX
value|0x2FA8
end_define

begin_define
define|#
directive|define
name|IXGBE_LVMMC_TX
value|0x8108
end_define

begin_define
define|#
directive|define
name|IXGBE_LMVM_RX
value|0x2FA4
end_define

begin_define
define|#
directive|define
name|IXGBE_LMVM_TX
value|0x8124
end_define

begin_define
define|#
directive|define
name|IXGBE_WQBR_RX
parameter_list|(
name|_i
parameter_list|)
value|(0x2FB0 + ((_i) * 4))
end_define

begin_comment
comment|/* 4 total */
end_comment

begin_define
define|#
directive|define
name|IXGBE_WQBR_TX
parameter_list|(
name|_i
parameter_list|)
value|(0x8130 + ((_i) * 4))
end_define

begin_comment
comment|/* 4 total */
end_comment

begin_define
define|#
directive|define
name|IXGBE_L34T_IMIR
parameter_list|(
name|_i
parameter_list|)
value|(0x0E800 + ((_i) * 4))
end_define

begin_comment
comment|/*128 of these (0-127)*/
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXFECCERR0
value|0x051B8
end_define

begin_define
define|#
directive|define
name|IXGBE_LLITHRESH
value|0x0EC90
end_define

begin_define
define|#
directive|define
name|IXGBE_IMIR
parameter_list|(
name|_i
parameter_list|)
value|(0x05A80 + ((_i) * 4))
end_define

begin_comment
comment|/* 8 of these (0-7) */
end_comment

begin_define
define|#
directive|define
name|IXGBE_IMIREXT
parameter_list|(
name|_i
parameter_list|)
value|(0x05AA0 + ((_i) * 4))
end_define

begin_comment
comment|/* 8 of these (0-7) */
end_comment

begin_define
define|#
directive|define
name|IXGBE_IMIRVP
value|0x05AC0
end_define

begin_define
define|#
directive|define
name|IXGBE_VMD_CTL
value|0x0581C
end_define

begin_define
define|#
directive|define
name|IXGBE_RETA
parameter_list|(
name|_i
parameter_list|)
value|(0x05C00 + ((_i) * 4))
end_define

begin_comment
comment|/* 32 of these (0-31) */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ERETA
parameter_list|(
name|_i
parameter_list|)
value|(0x0EE80 + ((_i) * 4))
end_define

begin_comment
comment|/* 96 of these (0-95) */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RSSRK
parameter_list|(
name|_i
parameter_list|)
value|(0x05C80 + ((_i) * 4))
end_define

begin_comment
comment|/* 10 of these (0-9) */
end_comment

begin_comment
comment|/* Registers for setting up RSS on X550 with SRIOV  * _p - pool number (0..63)  * _i - index (0..10 for PFVFRSSRK, 0..15 for PFVFRETA)  */
end_comment

begin_define
define|#
directive|define
name|IXGBE_PFVFMRQC
parameter_list|(
name|_p
parameter_list|)
value|(0x03400 + ((_p) * 4))
end_define

begin_define
define|#
directive|define
name|IXGBE_PFVFRSSRK
parameter_list|(
name|_i
parameter_list|,
name|_p
parameter_list|)
value|(0x018000 + ((_i) * 4) + ((_p) * 0x40))
end_define

begin_define
define|#
directive|define
name|IXGBE_PFVFRETA
parameter_list|(
name|_i
parameter_list|,
name|_p
parameter_list|)
value|(0x019000 + ((_i) * 4) + ((_p) * 0x40))
end_define

begin_comment
comment|/* Flow Director registers */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FDIRCTRL
value|0x0EE00
end_define

begin_define
define|#
directive|define
name|IXGBE_FDIRHKEY
value|0x0EE68
end_define

begin_define
define|#
directive|define
name|IXGBE_FDIRSKEY
value|0x0EE6C
end_define

begin_define
define|#
directive|define
name|IXGBE_FDIRDIP4M
value|0x0EE3C
end_define

begin_define
define|#
directive|define
name|IXGBE_FDIRSIP4M
value|0x0EE40
end_define

begin_define
define|#
directive|define
name|IXGBE_FDIRTCPM
value|0x0EE44
end_define

begin_define
define|#
directive|define
name|IXGBE_FDIRUDPM
value|0x0EE48
end_define

begin_define
define|#
directive|define
name|IXGBE_FDIRSCTPM
value|0x0EE78
end_define

begin_define
define|#
directive|define
name|IXGBE_FDIRIP6M
value|0x0EE74
end_define

begin_define
define|#
directive|define
name|IXGBE_FDIRM
value|0x0EE70
end_define

begin_comment
comment|/* Flow Director Stats registers */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FDIRFREE
value|0x0EE38
end_define

begin_define
define|#
directive|define
name|IXGBE_FDIRLEN
value|0x0EE4C
end_define

begin_define
define|#
directive|define
name|IXGBE_FDIRUSTAT
value|0x0EE50
end_define

begin_define
define|#
directive|define
name|IXGBE_FDIRFSTAT
value|0x0EE54
end_define

begin_define
define|#
directive|define
name|IXGBE_FDIRMATCH
value|0x0EE58
end_define

begin_define
define|#
directive|define
name|IXGBE_FDIRMISS
value|0x0EE5C
end_define

begin_comment
comment|/* Flow Director Programming registers */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FDIRSIPv6
parameter_list|(
name|_i
parameter_list|)
value|(0x0EE0C + ((_i) * 4))
end_define

begin_comment
comment|/* 3 of these (0-2) */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FDIRIPSA
value|0x0EE18
end_define

begin_define
define|#
directive|define
name|IXGBE_FDIRIPDA
value|0x0EE1C
end_define

begin_define
define|#
directive|define
name|IXGBE_FDIRPORT
value|0x0EE20
end_define

begin_define
define|#
directive|define
name|IXGBE_FDIRVLAN
value|0x0EE24
end_define

begin_define
define|#
directive|define
name|IXGBE_FDIRHASH
value|0x0EE28
end_define

begin_define
define|#
directive|define
name|IXGBE_FDIRCMD
value|0x0EE2C
end_define

begin_comment
comment|/* Transmit DMA registers */
end_comment

begin_define
define|#
directive|define
name|IXGBE_TDBAL
parameter_list|(
name|_i
parameter_list|)
value|(0x06000 + ((_i) * 0x40))
end_define

begin_comment
comment|/* 32 of them (0-31)*/
end_comment

begin_define
define|#
directive|define
name|IXGBE_TDBAH
parameter_list|(
name|_i
parameter_list|)
value|(0x06004 + ((_i) * 0x40))
end_define

begin_define
define|#
directive|define
name|IXGBE_TDLEN
parameter_list|(
name|_i
parameter_list|)
value|(0x06008 + ((_i) * 0x40))
end_define

begin_define
define|#
directive|define
name|IXGBE_TDH
parameter_list|(
name|_i
parameter_list|)
value|(0x06010 + ((_i) * 0x40))
end_define

begin_define
define|#
directive|define
name|IXGBE_TDT
parameter_list|(
name|_i
parameter_list|)
value|(0x06018 + ((_i) * 0x40))
end_define

begin_define
define|#
directive|define
name|IXGBE_TXDCTL
parameter_list|(
name|_i
parameter_list|)
value|(0x06028 + ((_i) * 0x40))
end_define

begin_define
define|#
directive|define
name|IXGBE_TDWBAL
parameter_list|(
name|_i
parameter_list|)
value|(0x06038 + ((_i) * 0x40))
end_define

begin_define
define|#
directive|define
name|IXGBE_TDWBAH
parameter_list|(
name|_i
parameter_list|)
value|(0x0603C + ((_i) * 0x40))
end_define

begin_define
define|#
directive|define
name|IXGBE_DTXCTL
value|0x07E00
end_define

begin_define
define|#
directive|define
name|IXGBE_DMATXCTL
value|0x04A80
end_define

begin_define
define|#
directive|define
name|IXGBE_PFVFSPOOF
parameter_list|(
name|_i
parameter_list|)
value|(0x08200 + ((_i) * 4))
end_define

begin_comment
comment|/* 8 of these 0 - 7 */
end_comment

begin_define
define|#
directive|define
name|IXGBE_PFDTXGSWC
value|0x08220
end_define

begin_define
define|#
directive|define
name|IXGBE_DTXMXSZRQ
value|0x08100
end_define

begin_define
define|#
directive|define
name|IXGBE_DTXTCPFLGL
value|0x04A88
end_define

begin_define
define|#
directive|define
name|IXGBE_DTXTCPFLGH
value|0x04A8C
end_define

begin_define
define|#
directive|define
name|IXGBE_LBDRPEN
value|0x0CA00
end_define

begin_define
define|#
directive|define
name|IXGBE_TXPBTHRESH
parameter_list|(
name|_i
parameter_list|)
value|(0x04950 + ((_i) * 4))
end_define

begin_comment
comment|/* 8 of these 0 - 7 */
end_comment

begin_define
define|#
directive|define
name|IXGBE_DMATXCTL_TE
value|0x1
end_define

begin_comment
comment|/* Transmit Enable */
end_comment

begin_define
define|#
directive|define
name|IXGBE_DMATXCTL_NS
value|0x2
end_define

begin_comment
comment|/* No Snoop LSO hdr buffer */
end_comment

begin_define
define|#
directive|define
name|IXGBE_DMATXCTL_GDV
value|0x8
end_define

begin_comment
comment|/* Global Double VLAN */
end_comment

begin_define
define|#
directive|define
name|IXGBE_DMATXCTL_MDP_EN
value|0x20
end_define

begin_comment
comment|/* Bit 5 */
end_comment

begin_define
define|#
directive|define
name|IXGBE_DMATXCTL_MBINTEN
value|0x40
end_define

begin_comment
comment|/* Bit 6 */
end_comment

begin_define
define|#
directive|define
name|IXGBE_DMATXCTL_VT_SHIFT
value|16
end_define

begin_comment
comment|/* VLAN EtherType */
end_comment

begin_define
define|#
directive|define
name|IXGBE_PFDTXGSWC_VT_LBEN
value|0x1
end_define

begin_comment
comment|/* Local L2 VT switch enable */
end_comment

begin_comment
comment|/* Anti-spoofing defines */
end_comment

begin_define
define|#
directive|define
name|IXGBE_SPOOF_MACAS_MASK
value|0xFF
end_define

begin_define
define|#
directive|define
name|IXGBE_SPOOF_VLANAS_MASK
value|0xFF00
end_define

begin_define
define|#
directive|define
name|IXGBE_SPOOF_VLANAS_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|IXGBE_SPOOF_ETHERTYPEAS
value|0xFF000000
end_define

begin_define
define|#
directive|define
name|IXGBE_SPOOF_ETHERTYPEAS_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|IXGBE_PFVFSPOOF_REG_COUNT
value|8
end_define

begin_comment
comment|/* 16 of these (0-15) */
end_comment

begin_define
define|#
directive|define
name|IXGBE_DCA_TXCTRL
parameter_list|(
name|_i
parameter_list|)
value|(0x07200 + ((_i) * 4))
end_define

begin_comment
comment|/* Tx DCA Control register : 128 of these (0-127) */
end_comment

begin_define
define|#
directive|define
name|IXGBE_DCA_TXCTRL_82599
parameter_list|(
name|_i
parameter_list|)
value|(0x0600C + ((_i) * 0x40))
end_define

begin_define
define|#
directive|define
name|IXGBE_TIPG
value|0x0CB00
end_define

begin_define
define|#
directive|define
name|IXGBE_TXPBSIZE
parameter_list|(
name|_i
parameter_list|)
value|(0x0CC00 + ((_i) * 4))
end_define

begin_comment
comment|/* 8 of these */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MNGTXMAP
value|0x0CD10
end_define

begin_define
define|#
directive|define
name|IXGBE_TIPG_FIBER_DEFAULT
value|3
end_define

begin_define
define|#
directive|define
name|IXGBE_TXPBSIZE_SHIFT
value|10
end_define

begin_comment
comment|/* Wake up registers */
end_comment

begin_define
define|#
directive|define
name|IXGBE_WUC
value|0x05800
end_define

begin_define
define|#
directive|define
name|IXGBE_WUFC
value|0x05808
end_define

begin_define
define|#
directive|define
name|IXGBE_WUS
value|0x05810
end_define

begin_define
define|#
directive|define
name|IXGBE_IPAV
value|0x05838
end_define

begin_define
define|#
directive|define
name|IXGBE_IP4AT
value|0x05840
end_define

begin_comment
comment|/* IPv4 table 0x5840-0x5858 */
end_comment

begin_define
define|#
directive|define
name|IXGBE_IP6AT
value|0x05880
end_define

begin_comment
comment|/* IPv6 table 0x5880-0x588F */
end_comment

begin_define
define|#
directive|define
name|IXGBE_WUPL
value|0x05900
end_define

begin_define
define|#
directive|define
name|IXGBE_WUPM
value|0x05A00
end_define

begin_comment
comment|/* wake up pkt memory 0x5A00-0x5A7C */
end_comment

begin_define
define|#
directive|define
name|IXGBE_PROXYS
value|0x05F60
end_define

begin_comment
comment|/* Proxying Status Register */
end_comment

begin_define
define|#
directive|define
name|IXGBE_PROXYFC
value|0x05F64
end_define

begin_comment
comment|/* Proxying Filter Control Register */
end_comment

begin_define
define|#
directive|define
name|IXGBE_VXLANCTRL
value|0x0000507C
end_define

begin_comment
comment|/* Rx filter VXLAN UDPPORT Register */
end_comment

begin_comment
comment|/* masks for accessing VXLAN and GENEVE UDP ports */
end_comment

begin_define
define|#
directive|define
name|IXGBE_VXLANCTRL_VXLAN_UDPPORT_MASK
value|0x0000ffff
end_define

begin_comment
comment|/* VXLAN port */
end_comment

begin_define
define|#
directive|define
name|IXGBE_VXLANCTRL_GENEVE_UDPPORT_MASK
value|0xffff0000
end_define

begin_comment
comment|/* GENEVE port */
end_comment

begin_define
define|#
directive|define
name|IXGBE_VXLANCTRL_ALL_UDPPORT_MASK
value|0xffffffff
end_define

begin_comment
comment|/* GENEVE/VXLAN */
end_comment

begin_define
define|#
directive|define
name|IXGBE_VXLANCTRL_GENEVE_UDPPORT_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|IXGBE_FHFT
parameter_list|(
name|_n
parameter_list|)
value|(0x09000 + ((_n) * 0x100))
end_define

begin_comment
comment|/* Flex host filter table */
end_comment

begin_comment
comment|/* Ext Flexible Host Filter Table */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FHFT_EXT
parameter_list|(
name|_n
parameter_list|)
value|(0x09800 + ((_n) * 0x100))
end_define

begin_define
define|#
directive|define
name|IXGBE_FHFT_EXT_X550
parameter_list|(
name|_n
parameter_list|)
value|(0x09600 + ((_n) * 0x100))
end_define

begin_comment
comment|/* Four Flexible Filters are supported */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FLEXIBLE_FILTER_COUNT_MAX
value|4
end_define

begin_comment
comment|/* Six Flexible Filters are supported */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FLEXIBLE_FILTER_COUNT_MAX_6
value|6
end_define

begin_comment
comment|/* Eight Flexible Filters are supported */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FLEXIBLE_FILTER_COUNT_MAX_8
value|8
end_define

begin_define
define|#
directive|define
name|IXGBE_EXT_FLEXIBLE_FILTER_COUNT_MAX
value|2
end_define

begin_comment
comment|/* Each Flexible Filter is at most 128 (0x80) bytes in length */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FLEXIBLE_FILTER_SIZE_MAX
value|128
end_define

begin_define
define|#
directive|define
name|IXGBE_FHFT_LENGTH_OFFSET
value|0xFC
end_define

begin_comment
comment|/* Length byte in FHFT */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FHFT_LENGTH_MASK
value|0x0FF
end_define

begin_comment
comment|/* Length in lower byte */
end_comment

begin_comment
comment|/* Definitions for power management and wakeup registers */
end_comment

begin_comment
comment|/* Wake Up Control */
end_comment

begin_define
define|#
directive|define
name|IXGBE_WUC_PME_EN
value|0x00000002
end_define

begin_comment
comment|/* PME Enable */
end_comment

begin_define
define|#
directive|define
name|IXGBE_WUC_PME_STATUS
value|0x00000004
end_define

begin_comment
comment|/* PME Status */
end_comment

begin_define
define|#
directive|define
name|IXGBE_WUC_WKEN
value|0x00000010
end_define

begin_comment
comment|/* Enable PE_WAKE_N pin assertion  */
end_comment

begin_comment
comment|/* Wake Up Filter Control */
end_comment

begin_define
define|#
directive|define
name|IXGBE_WUFC_LNKC
value|0x00000001
end_define

begin_comment
comment|/* Link Status Change Wakeup Enable */
end_comment

begin_define
define|#
directive|define
name|IXGBE_WUFC_MAG
value|0x00000002
end_define

begin_comment
comment|/* Magic Packet Wakeup Enable */
end_comment

begin_define
define|#
directive|define
name|IXGBE_WUFC_EX
value|0x00000004
end_define

begin_comment
comment|/* Directed Exact Wakeup Enable */
end_comment

begin_define
define|#
directive|define
name|IXGBE_WUFC_MC
value|0x00000008
end_define

begin_comment
comment|/* Directed Multicast Wakeup Enable */
end_comment

begin_define
define|#
directive|define
name|IXGBE_WUFC_BC
value|0x00000010
end_define

begin_comment
comment|/* Broadcast Wakeup Enable */
end_comment

begin_define
define|#
directive|define
name|IXGBE_WUFC_ARP
value|0x00000020
end_define

begin_comment
comment|/* ARP Request Packet Wakeup Enable */
end_comment

begin_define
define|#
directive|define
name|IXGBE_WUFC_IPV4
value|0x00000040
end_define

begin_comment
comment|/* Directed IPv4 Packet Wakeup Enable */
end_comment

begin_define
define|#
directive|define
name|IXGBE_WUFC_IPV6
value|0x00000080
end_define

begin_comment
comment|/* Directed IPv6 Packet Wakeup Enable */
end_comment

begin_define
define|#
directive|define
name|IXGBE_WUFC_MNG
value|0x00000100
end_define

begin_comment
comment|/* Directed Mgmt Packet Wakeup Enable */
end_comment

begin_define
define|#
directive|define
name|IXGBE_WUFC_IGNORE_TCO
value|0x00008000
end_define

begin_comment
comment|/* Ignore WakeOn TCO packets */
end_comment

begin_define
define|#
directive|define
name|IXGBE_WUFC_FLX0
value|0x00010000
end_define

begin_comment
comment|/* Flexible Filter 0 Enable */
end_comment

begin_define
define|#
directive|define
name|IXGBE_WUFC_FLX1
value|0x00020000
end_define

begin_comment
comment|/* Flexible Filter 1 Enable */
end_comment

begin_define
define|#
directive|define
name|IXGBE_WUFC_FLX2
value|0x00040000
end_define

begin_comment
comment|/* Flexible Filter 2 Enable */
end_comment

begin_define
define|#
directive|define
name|IXGBE_WUFC_FLX3
value|0x00080000
end_define

begin_comment
comment|/* Flexible Filter 3 Enable */
end_comment

begin_define
define|#
directive|define
name|IXGBE_WUFC_FLX4
value|0x00100000
end_define

begin_comment
comment|/* Flexible Filter 4 Enable */
end_comment

begin_define
define|#
directive|define
name|IXGBE_WUFC_FLX5
value|0x00200000
end_define

begin_comment
comment|/* Flexible Filter 5 Enable */
end_comment

begin_define
define|#
directive|define
name|IXGBE_WUFC_FLX_FILTERS
value|0x000F0000
end_define

begin_comment
comment|/* Mask for 4 flex filters */
end_comment

begin_define
define|#
directive|define
name|IXGBE_WUFC_FLX_FILTERS_6
value|0x003F0000
end_define

begin_comment
comment|/* Mask for 6 flex filters */
end_comment

begin_define
define|#
directive|define
name|IXGBE_WUFC_FLX_FILTERS_8
value|0x00FF0000
end_define

begin_comment
comment|/* Mask for 8 flex filters */
end_comment

begin_define
define|#
directive|define
name|IXGBE_WUFC_FW_RST_WK
value|0x80000000
end_define

begin_comment
comment|/* Ena wake on FW reset assertion */
end_comment

begin_comment
comment|/* Mask for Ext. flex filters */
end_comment

begin_define
define|#
directive|define
name|IXGBE_WUFC_EXT_FLX_FILTERS
value|0x00300000
end_define

begin_define
define|#
directive|define
name|IXGBE_WUFC_ALL_FILTERS
value|0x000F00FF
end_define

begin_comment
comment|/* Mask all 4 flex filters */
end_comment

begin_define
define|#
directive|define
name|IXGBE_WUFC_ALL_FILTERS_6
value|0x003F00FF
end_define

begin_comment
comment|/* Mask all 6 flex filters */
end_comment

begin_define
define|#
directive|define
name|IXGBE_WUFC_ALL_FILTERS_8
value|0x00FF00FF
end_define

begin_comment
comment|/* Mask all 8 flex filters */
end_comment

begin_define
define|#
directive|define
name|IXGBE_WUFC_FLX_OFFSET
value|16
end_define

begin_comment
comment|/* Offset to the Flexible Filters bits */
end_comment

begin_comment
comment|/* Wake Up Status */
end_comment

begin_define
define|#
directive|define
name|IXGBE_WUS_LNKC
value|IXGBE_WUFC_LNKC
end_define

begin_define
define|#
directive|define
name|IXGBE_WUS_MAG
value|IXGBE_WUFC_MAG
end_define

begin_define
define|#
directive|define
name|IXGBE_WUS_EX
value|IXGBE_WUFC_EX
end_define

begin_define
define|#
directive|define
name|IXGBE_WUS_MC
value|IXGBE_WUFC_MC
end_define

begin_define
define|#
directive|define
name|IXGBE_WUS_BC
value|IXGBE_WUFC_BC
end_define

begin_define
define|#
directive|define
name|IXGBE_WUS_ARP
value|IXGBE_WUFC_ARP
end_define

begin_define
define|#
directive|define
name|IXGBE_WUS_IPV4
value|IXGBE_WUFC_IPV4
end_define

begin_define
define|#
directive|define
name|IXGBE_WUS_IPV6
value|IXGBE_WUFC_IPV6
end_define

begin_define
define|#
directive|define
name|IXGBE_WUS_MNG
value|IXGBE_WUFC_MNG
end_define

begin_define
define|#
directive|define
name|IXGBE_WUS_FLX0
value|IXGBE_WUFC_FLX0
end_define

begin_define
define|#
directive|define
name|IXGBE_WUS_FLX1
value|IXGBE_WUFC_FLX1
end_define

begin_define
define|#
directive|define
name|IXGBE_WUS_FLX2
value|IXGBE_WUFC_FLX2
end_define

begin_define
define|#
directive|define
name|IXGBE_WUS_FLX3
value|IXGBE_WUFC_FLX3
end_define

begin_define
define|#
directive|define
name|IXGBE_WUS_FLX4
value|IXGBE_WUFC_FLX4
end_define

begin_define
define|#
directive|define
name|IXGBE_WUS_FLX5
value|IXGBE_WUFC_FLX5
end_define

begin_define
define|#
directive|define
name|IXGBE_WUS_FLX_FILTERS
value|IXGBE_WUFC_FLX_FILTERS
end_define

begin_define
define|#
directive|define
name|IXGBE_WUS_FW_RST_WK
value|IXGBE_WUFC_FW_RST_WK
end_define

begin_comment
comment|/* Proxy Status */
end_comment

begin_define
define|#
directive|define
name|IXGBE_PROXYS_EX
value|0x00000004
end_define

begin_comment
comment|/* Exact packet received */
end_comment

begin_define
define|#
directive|define
name|IXGBE_PROXYS_ARP_DIR
value|0x00000020
end_define

begin_comment
comment|/* ARP w/filter match received */
end_comment

begin_define
define|#
directive|define
name|IXGBE_PROXYS_NS
value|0x00000200
end_define

begin_comment
comment|/* IPV6 NS received */
end_comment

begin_define
define|#
directive|define
name|IXGBE_PROXYS_NS_DIR
value|0x00000400
end_define

begin_comment
comment|/* IPV6 NS w/DA match received */
end_comment

begin_define
define|#
directive|define
name|IXGBE_PROXYS_ARP
value|0x00000800
end_define

begin_comment
comment|/* ARP request packet received */
end_comment

begin_define
define|#
directive|define
name|IXGBE_PROXYS_MLD
value|0x00001000
end_define

begin_comment
comment|/* IPv6 MLD packet received */
end_comment

begin_comment
comment|/* Proxying Filter Control */
end_comment

begin_define
define|#
directive|define
name|IXGBE_PROXYFC_ENABLE
value|0x00000001
end_define

begin_comment
comment|/* Port Proxying Enable */
end_comment

begin_define
define|#
directive|define
name|IXGBE_PROXYFC_EX
value|0x00000004
end_define

begin_comment
comment|/* Directed Exact Proxy Enable */
end_comment

begin_define
define|#
directive|define
name|IXGBE_PROXYFC_ARP_DIR
value|0x00000020
end_define

begin_comment
comment|/* Directed ARP Proxy Enable */
end_comment

begin_define
define|#
directive|define
name|IXGBE_PROXYFC_NS
value|0x00000200
end_define

begin_comment
comment|/* IPv6 Neighbor Solicitation */
end_comment

begin_define
define|#
directive|define
name|IXGBE_PROXYFC_ARP
value|0x00000800
end_define

begin_comment
comment|/* ARP Request Proxy Enable */
end_comment

begin_define
define|#
directive|define
name|IXGBE_PROXYFC_MLD
value|0x00000800
end_define

begin_comment
comment|/* IPv6 MLD Proxy Enable */
end_comment

begin_define
define|#
directive|define
name|IXGBE_PROXYFC_NO_TCO
value|0x00008000
end_define

begin_comment
comment|/* Ignore TCO packets */
end_comment

begin_define
define|#
directive|define
name|IXGBE_WUPL_LENGTH_MASK
value|0xFFFF
end_define

begin_comment
comment|/* DCB registers */
end_comment

begin_define
define|#
directive|define
name|IXGBE_DCB_MAX_TRAFFIC_CLASS
value|8
end_define

begin_define
define|#
directive|define
name|IXGBE_RMCS
value|0x03D00
end_define

begin_define
define|#
directive|define
name|IXGBE_DPMCS
value|0x07F40
end_define

begin_define
define|#
directive|define
name|IXGBE_PDPMCS
value|0x0CD00
end_define

begin_define
define|#
directive|define
name|IXGBE_RUPPBMR
value|0x050A0
end_define

begin_define
define|#
directive|define
name|IXGBE_RT2CR
parameter_list|(
name|_i
parameter_list|)
value|(0x03C20 + ((_i) * 4))
end_define

begin_comment
comment|/* 8 of these (0-7) */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RT2SR
parameter_list|(
name|_i
parameter_list|)
value|(0x03C40 + ((_i) * 4))
end_define

begin_comment
comment|/* 8 of these (0-7) */
end_comment

begin_define
define|#
directive|define
name|IXGBE_TDTQ2TCCR
parameter_list|(
name|_i
parameter_list|)
value|(0x0602C + ((_i) * 0x40))
end_define

begin_comment
comment|/* 8 of these (0-7) */
end_comment

begin_define
define|#
directive|define
name|IXGBE_TDTQ2TCSR
parameter_list|(
name|_i
parameter_list|)
value|(0x0622C + ((_i) * 0x40))
end_define

begin_comment
comment|/* 8 of these (0-7) */
end_comment

begin_define
define|#
directive|define
name|IXGBE_TDPT2TCCR
parameter_list|(
name|_i
parameter_list|)
value|(0x0CD20 + ((_i) * 4))
end_define

begin_comment
comment|/* 8 of these (0-7) */
end_comment

begin_define
define|#
directive|define
name|IXGBE_TDPT2TCSR
parameter_list|(
name|_i
parameter_list|)
value|(0x0CD40 + ((_i) * 4))
end_define

begin_comment
comment|/* 8 of these (0-7) */
end_comment

begin_comment
comment|/* Power Management */
end_comment

begin_comment
comment|/* DMA Coalescing configuration */
end_comment

begin_struct
struct|struct
name|ixgbe_dmac_config
block|{
name|u16
name|watchdog_timer
decl_stmt|;
comment|/* usec units */
name|bool
name|fcoe_en
decl_stmt|;
name|u32
name|link_speed
decl_stmt|;
name|u8
name|fcoe_tc
decl_stmt|;
name|u8
name|num_tcs
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * DMA Coalescing threshold Rx PB TC[n] value in Kilobyte by link speed.  * DMACRXT = 10Gbps = 10,000 bits / usec = 1250 bytes / usec 70 * 1250 ==  * 87500 bytes [85KB]  */
end_comment

begin_define
define|#
directive|define
name|IXGBE_DMACRXT_10G
value|0x55
end_define

begin_define
define|#
directive|define
name|IXGBE_DMACRXT_1G
value|0x09
end_define

begin_define
define|#
directive|define
name|IXGBE_DMACRXT_100M
value|0x01
end_define

begin_comment
comment|/* DMA Coalescing registers */
end_comment

begin_define
define|#
directive|define
name|IXGBE_DMCMNGTH
value|0x15F20
end_define

begin_comment
comment|/* Management Threshold */
end_comment

begin_define
define|#
directive|define
name|IXGBE_DMACR
value|0x02400
end_define

begin_comment
comment|/* Control register */
end_comment

begin_define
define|#
directive|define
name|IXGBE_DMCTH
parameter_list|(
name|_i
parameter_list|)
value|(0x03300 + ((_i) * 4))
end_define

begin_comment
comment|/* 8 of these */
end_comment

begin_define
define|#
directive|define
name|IXGBE_DMCTLX
value|0x02404
end_define

begin_comment
comment|/* Time to Lx request */
end_comment

begin_comment
comment|/* DMA Coalescing register fields */
end_comment

begin_define
define|#
directive|define
name|IXGBE_DMCMNGTH_DMCMNGTH_MASK
value|0x000FFFF0
end_define

begin_comment
comment|/* Mng Threshold mask */
end_comment

begin_define
define|#
directive|define
name|IXGBE_DMCMNGTH_DMCMNGTH_SHIFT
value|4
end_define

begin_comment
comment|/* Management Threshold shift */
end_comment

begin_define
define|#
directive|define
name|IXGBE_DMACR_DMACWT_MASK
value|0x0000FFFF
end_define

begin_comment
comment|/* Watchdog Timer mask */
end_comment

begin_define
define|#
directive|define
name|IXGBE_DMACR_HIGH_PRI_TC_MASK
value|0x00FF0000
end_define

begin_define
define|#
directive|define
name|IXGBE_DMACR_HIGH_PRI_TC_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|IXGBE_DMACR_EN_MNG_IND
value|0x10000000
end_define

begin_comment
comment|/* Enable Mng Indications */
end_comment

begin_define
define|#
directive|define
name|IXGBE_DMACR_LX_COAL_IND
value|0x40000000
end_define

begin_comment
comment|/* Lx Coalescing indicate */
end_comment

begin_define
define|#
directive|define
name|IXGBE_DMACR_DMAC_EN
value|0x80000000
end_define

begin_comment
comment|/* DMA Coalescing Enable */
end_comment

begin_define
define|#
directive|define
name|IXGBE_DMCTH_DMACRXT_MASK
value|0x000001FF
end_define

begin_comment
comment|/* Receive Threshold mask */
end_comment

begin_define
define|#
directive|define
name|IXGBE_DMCTLX_TTLX_MASK
value|0x00000FFF
end_define

begin_comment
comment|/* Time to Lx request mask */
end_comment

begin_comment
comment|/* EEE registers */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EEER
value|0x043A0
end_define

begin_comment
comment|/* EEE register */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EEE_STAT
value|0x04398
end_define

begin_comment
comment|/* EEE Status */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EEE_SU
value|0x04380
end_define

begin_comment
comment|/* EEE Set up */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EEE_SU_TEEE_DLY_SHIFT
value|26
end_define

begin_define
define|#
directive|define
name|IXGBE_TLPIC
value|0x041F4
end_define

begin_comment
comment|/* EEE Tx LPI count */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RLPIC
value|0x041F8
end_define

begin_comment
comment|/* EEE Rx LPI count */
end_comment

begin_comment
comment|/* EEE register fields */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EEER_TX_LPI_EN
value|0x00010000
end_define

begin_comment
comment|/* Enable EEE LPI TX path */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EEER_RX_LPI_EN
value|0x00020000
end_define

begin_comment
comment|/* Enable EEE LPI RX path */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EEE_STAT_NEG
value|0x20000000
end_define

begin_comment
comment|/* EEE support neg on link */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EEE_RX_LPI_STATUS
value|0x40000000
end_define

begin_comment
comment|/* RX Link in LPI status */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EEE_TX_LPI_STATUS
value|0x80000000
end_define

begin_comment
comment|/* TX Link in LPI status */
end_comment

begin_comment
comment|/* Security Control Registers */
end_comment

begin_define
define|#
directive|define
name|IXGBE_SECTXCTRL
value|0x08800
end_define

begin_define
define|#
directive|define
name|IXGBE_SECTXSTAT
value|0x08804
end_define

begin_define
define|#
directive|define
name|IXGBE_SECTXBUFFAF
value|0x08808
end_define

begin_define
define|#
directive|define
name|IXGBE_SECTXMINIFG
value|0x08810
end_define

begin_define
define|#
directive|define
name|IXGBE_SECRXCTRL
value|0x08D00
end_define

begin_define
define|#
directive|define
name|IXGBE_SECRXSTAT
value|0x08D04
end_define

begin_comment
comment|/* Security Bit Fields and Masks */
end_comment

begin_define
define|#
directive|define
name|IXGBE_SECTXCTRL_SECTX_DIS
value|0x00000001
end_define

begin_define
define|#
directive|define
name|IXGBE_SECTXCTRL_TX_DIS
value|0x00000002
end_define

begin_define
define|#
directive|define
name|IXGBE_SECTXCTRL_STORE_FORWARD
value|0x00000004
end_define

begin_define
define|#
directive|define
name|IXGBE_SECTXSTAT_SECTX_RDY
value|0x00000001
end_define

begin_define
define|#
directive|define
name|IXGBE_SECTXSTAT_ECC_TXERR
value|0x00000002
end_define

begin_define
define|#
directive|define
name|IXGBE_SECRXCTRL_SECRX_DIS
value|0x00000001
end_define

begin_define
define|#
directive|define
name|IXGBE_SECRXCTRL_RX_DIS
value|0x00000002
end_define

begin_define
define|#
directive|define
name|IXGBE_SECRXSTAT_SECRX_RDY
value|0x00000001
end_define

begin_define
define|#
directive|define
name|IXGBE_SECRXSTAT_ECC_RXERR
value|0x00000002
end_define

begin_comment
comment|/* LinkSec (MacSec) Registers */
end_comment

begin_define
define|#
directive|define
name|IXGBE_LSECTXCAP
value|0x08A00
end_define

begin_define
define|#
directive|define
name|IXGBE_LSECRXCAP
value|0x08F00
end_define

begin_define
define|#
directive|define
name|IXGBE_LSECTXCTRL
value|0x08A04
end_define

begin_define
define|#
directive|define
name|IXGBE_LSECTXSCL
value|0x08A08
end_define

begin_comment
comment|/* SCI Low */
end_comment

begin_define
define|#
directive|define
name|IXGBE_LSECTXSCH
value|0x08A0C
end_define

begin_comment
comment|/* SCI High */
end_comment

begin_define
define|#
directive|define
name|IXGBE_LSECTXSA
value|0x08A10
end_define

begin_define
define|#
directive|define
name|IXGBE_LSECTXPN0
value|0x08A14
end_define

begin_define
define|#
directive|define
name|IXGBE_LSECTXPN1
value|0x08A18
end_define

begin_define
define|#
directive|define
name|IXGBE_LSECTXKEY0
parameter_list|(
name|_n
parameter_list|)
value|(0x08A1C + (4 * (_n)))
end_define

begin_comment
comment|/* 4 of these (0-3) */
end_comment

begin_define
define|#
directive|define
name|IXGBE_LSECTXKEY1
parameter_list|(
name|_n
parameter_list|)
value|(0x08A2C + (4 * (_n)))
end_define

begin_comment
comment|/* 4 of these (0-3) */
end_comment

begin_define
define|#
directive|define
name|IXGBE_LSECRXCTRL
value|0x08F04
end_define

begin_define
define|#
directive|define
name|IXGBE_LSECRXSCL
value|0x08F08
end_define

begin_define
define|#
directive|define
name|IXGBE_LSECRXSCH
value|0x08F0C
end_define

begin_define
define|#
directive|define
name|IXGBE_LSECRXSA
parameter_list|(
name|_i
parameter_list|)
value|(0x08F10 + (4 * (_i)))
end_define

begin_comment
comment|/* 2 of these (0-1) */
end_comment

begin_define
define|#
directive|define
name|IXGBE_LSECRXPN
parameter_list|(
name|_i
parameter_list|)
value|(0x08F18 + (4 * (_i)))
end_define

begin_comment
comment|/* 2 of these (0-1) */
end_comment

begin_define
define|#
directive|define
name|IXGBE_LSECRXKEY
parameter_list|(
name|_n
parameter_list|,
name|_m
parameter_list|)
value|(0x08F20 + ((0x10 * (_n)) + (4 * (_m))))
end_define

begin_define
define|#
directive|define
name|IXGBE_LSECTXUT
value|0x08A3C
end_define

begin_comment
comment|/* OutPktsUntagged */
end_comment

begin_define
define|#
directive|define
name|IXGBE_LSECTXPKTE
value|0x08A40
end_define

begin_comment
comment|/* OutPktsEncrypted */
end_comment

begin_define
define|#
directive|define
name|IXGBE_LSECTXPKTP
value|0x08A44
end_define

begin_comment
comment|/* OutPktsProtected */
end_comment

begin_define
define|#
directive|define
name|IXGBE_LSECTXOCTE
value|0x08A48
end_define

begin_comment
comment|/* OutOctetsEncrypted */
end_comment

begin_define
define|#
directive|define
name|IXGBE_LSECTXOCTP
value|0x08A4C
end_define

begin_comment
comment|/* OutOctetsProtected */
end_comment

begin_define
define|#
directive|define
name|IXGBE_LSECRXUT
value|0x08F40
end_define

begin_comment
comment|/* InPktsUntagged/InPktsNoTag */
end_comment

begin_define
define|#
directive|define
name|IXGBE_LSECRXOCTD
value|0x08F44
end_define

begin_comment
comment|/* InOctetsDecrypted */
end_comment

begin_define
define|#
directive|define
name|IXGBE_LSECRXOCTV
value|0x08F48
end_define

begin_comment
comment|/* InOctetsValidated */
end_comment

begin_define
define|#
directive|define
name|IXGBE_LSECRXBAD
value|0x08F4C
end_define

begin_comment
comment|/* InPktsBadTag */
end_comment

begin_define
define|#
directive|define
name|IXGBE_LSECRXNOSCI
value|0x08F50
end_define

begin_comment
comment|/* InPktsNoSci */
end_comment

begin_define
define|#
directive|define
name|IXGBE_LSECRXUNSCI
value|0x08F54
end_define

begin_comment
comment|/* InPktsUnknownSci */
end_comment

begin_define
define|#
directive|define
name|IXGBE_LSECRXUNCH
value|0x08F58
end_define

begin_comment
comment|/* InPktsUnchecked */
end_comment

begin_define
define|#
directive|define
name|IXGBE_LSECRXDELAY
value|0x08F5C
end_define

begin_comment
comment|/* InPktsDelayed */
end_comment

begin_define
define|#
directive|define
name|IXGBE_LSECRXLATE
value|0x08F60
end_define

begin_comment
comment|/* InPktsLate */
end_comment

begin_define
define|#
directive|define
name|IXGBE_LSECRXOK
parameter_list|(
name|_n
parameter_list|)
value|(0x08F64 + (0x04 * (_n)))
end_define

begin_comment
comment|/* InPktsOk */
end_comment

begin_define
define|#
directive|define
name|IXGBE_LSECRXINV
parameter_list|(
name|_n
parameter_list|)
value|(0x08F6C + (0x04 * (_n)))
end_define

begin_comment
comment|/* InPktsInvalid */
end_comment

begin_define
define|#
directive|define
name|IXGBE_LSECRXNV
parameter_list|(
name|_n
parameter_list|)
value|(0x08F74 + (0x04 * (_n)))
end_define

begin_comment
comment|/* InPktsNotValid */
end_comment

begin_define
define|#
directive|define
name|IXGBE_LSECRXUNSA
value|0x08F7C
end_define

begin_comment
comment|/* InPktsUnusedSa */
end_comment

begin_define
define|#
directive|define
name|IXGBE_LSECRXNUSA
value|0x08F80
end_define

begin_comment
comment|/* InPktsNotUsingSa */
end_comment

begin_comment
comment|/* LinkSec (MacSec) Bit Fields and Masks */
end_comment

begin_define
define|#
directive|define
name|IXGBE_LSECTXCAP_SUM_MASK
value|0x00FF0000
end_define

begin_define
define|#
directive|define
name|IXGBE_LSECTXCAP_SUM_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|IXGBE_LSECRXCAP_SUM_MASK
value|0x00FF0000
end_define

begin_define
define|#
directive|define
name|IXGBE_LSECRXCAP_SUM_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|IXGBE_LSECTXCTRL_EN_MASK
value|0x00000003
end_define

begin_define
define|#
directive|define
name|IXGBE_LSECTXCTRL_DISABLE
value|0x0
end_define

begin_define
define|#
directive|define
name|IXGBE_LSECTXCTRL_AUTH
value|0x1
end_define

begin_define
define|#
directive|define
name|IXGBE_LSECTXCTRL_AUTH_ENCRYPT
value|0x2
end_define

begin_define
define|#
directive|define
name|IXGBE_LSECTXCTRL_AISCI
value|0x00000020
end_define

begin_define
define|#
directive|define
name|IXGBE_LSECTXCTRL_PNTHRSH_MASK
value|0xFFFFFF00
end_define

begin_define
define|#
directive|define
name|IXGBE_LSECTXCTRL_RSV_MASK
value|0x000000D8
end_define

begin_define
define|#
directive|define
name|IXGBE_LSECRXCTRL_EN_MASK
value|0x0000000C
end_define

begin_define
define|#
directive|define
name|IXGBE_LSECRXCTRL_EN_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|IXGBE_LSECRXCTRL_DISABLE
value|0x0
end_define

begin_define
define|#
directive|define
name|IXGBE_LSECRXCTRL_CHECK
value|0x1
end_define

begin_define
define|#
directive|define
name|IXGBE_LSECRXCTRL_STRICT
value|0x2
end_define

begin_define
define|#
directive|define
name|IXGBE_LSECRXCTRL_DROP
value|0x3
end_define

begin_define
define|#
directive|define
name|IXGBE_LSECRXCTRL_PLSH
value|0x00000040
end_define

begin_define
define|#
directive|define
name|IXGBE_LSECRXCTRL_RP
value|0x00000080
end_define

begin_define
define|#
directive|define
name|IXGBE_LSECRXCTRL_RSV_MASK
value|0xFFFFFF33
end_define

begin_comment
comment|/* IpSec Registers */
end_comment

begin_define
define|#
directive|define
name|IXGBE_IPSTXIDX
value|0x08900
end_define

begin_define
define|#
directive|define
name|IXGBE_IPSTXSALT
value|0x08904
end_define

begin_define
define|#
directive|define
name|IXGBE_IPSTXKEY
parameter_list|(
name|_i
parameter_list|)
value|(0x08908 + (4 * (_i)))
end_define

begin_comment
comment|/* 4 of these (0-3) */
end_comment

begin_define
define|#
directive|define
name|IXGBE_IPSRXIDX
value|0x08E00
end_define

begin_define
define|#
directive|define
name|IXGBE_IPSRXIPADDR
parameter_list|(
name|_i
parameter_list|)
value|(0x08E04 + (4 * (_i)))
end_define

begin_comment
comment|/* 4 of these (0-3) */
end_comment

begin_define
define|#
directive|define
name|IXGBE_IPSRXSPI
value|0x08E14
end_define

begin_define
define|#
directive|define
name|IXGBE_IPSRXIPIDX
value|0x08E18
end_define

begin_define
define|#
directive|define
name|IXGBE_IPSRXKEY
parameter_list|(
name|_i
parameter_list|)
value|(0x08E1C + (4 * (_i)))
end_define

begin_comment
comment|/* 4 of these (0-3) */
end_comment

begin_define
define|#
directive|define
name|IXGBE_IPSRXSALT
value|0x08E2C
end_define

begin_define
define|#
directive|define
name|IXGBE_IPSRXMOD
value|0x08E30
end_define

begin_define
define|#
directive|define
name|IXGBE_SECTXCTRL_STORE_FORWARD_ENABLE
value|0x4
end_define

begin_comment
comment|/* DCB registers */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RTRPCS
value|0x02430
end_define

begin_define
define|#
directive|define
name|IXGBE_RTTDCS
value|0x04900
end_define

begin_define
define|#
directive|define
name|IXGBE_RTTDCS_ARBDIS
value|0x00000040
end_define

begin_comment
comment|/* DCB arbiter disable */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RTTPCS
value|0x0CD00
end_define

begin_define
define|#
directive|define
name|IXGBE_RTRUP2TC
value|0x03020
end_define

begin_define
define|#
directive|define
name|IXGBE_RTTUP2TC
value|0x0C800
end_define

begin_define
define|#
directive|define
name|IXGBE_RTRPT4C
parameter_list|(
name|_i
parameter_list|)
value|(0x02140 + ((_i) * 4))
end_define

begin_comment
comment|/* 8 of these (0-7) */
end_comment

begin_define
define|#
directive|define
name|IXGBE_TXLLQ
parameter_list|(
name|_i
parameter_list|)
value|(0x082E0 + ((_i) * 4))
end_define

begin_comment
comment|/* 4 of these (0-3) */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RTRPT4S
parameter_list|(
name|_i
parameter_list|)
value|(0x02160 + ((_i) * 4))
end_define

begin_comment
comment|/* 8 of these (0-7) */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RTTDT2C
parameter_list|(
name|_i
parameter_list|)
value|(0x04910 + ((_i) * 4))
end_define

begin_comment
comment|/* 8 of these (0-7) */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RTTDT2S
parameter_list|(
name|_i
parameter_list|)
value|(0x04930 + ((_i) * 4))
end_define

begin_comment
comment|/* 8 of these (0-7) */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RTTPT2C
parameter_list|(
name|_i
parameter_list|)
value|(0x0CD20 + ((_i) * 4))
end_define

begin_comment
comment|/* 8 of these (0-7) */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RTTPT2S
parameter_list|(
name|_i
parameter_list|)
value|(0x0CD40 + ((_i) * 4))
end_define

begin_comment
comment|/* 8 of these (0-7) */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RTTDQSEL
value|0x04904
end_define

begin_define
define|#
directive|define
name|IXGBE_RTTDT1C
value|0x04908
end_define

begin_define
define|#
directive|define
name|IXGBE_RTTDT1S
value|0x0490C
end_define

begin_define
define|#
directive|define
name|IXGBE_RTTDTECC
value|0x04990
end_define

begin_define
define|#
directive|define
name|IXGBE_RTTDTECC_NO_BCN
value|0x00000100
end_define

begin_define
define|#
directive|define
name|IXGBE_RTTBCNRC
value|0x04984
end_define

begin_define
define|#
directive|define
name|IXGBE_RTTBCNRC_RS_ENA
value|0x80000000
end_define

begin_define
define|#
directive|define
name|IXGBE_RTTBCNRC_RF_DEC_MASK
value|0x00003FFF
end_define

begin_define
define|#
directive|define
name|IXGBE_RTTBCNRC_RF_INT_SHIFT
value|14
end_define

begin_define
define|#
directive|define
name|IXGBE_RTTBCNRC_RF_INT_MASK
define|\
value|(IXGBE_RTTBCNRC_RF_DEC_MASK<< IXGBE_RTTBCNRC_RF_INT_SHIFT)
end_define

begin_define
define|#
directive|define
name|IXGBE_RTTBCNRM
value|0x04980
end_define

begin_comment
comment|/* BCN (for DCB) Registers */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RTTBCNRS
value|0x04988
end_define

begin_define
define|#
directive|define
name|IXGBE_RTTBCNCR
value|0x08B00
end_define

begin_define
define|#
directive|define
name|IXGBE_RTTBCNACH
value|0x08B04
end_define

begin_define
define|#
directive|define
name|IXGBE_RTTBCNACL
value|0x08B08
end_define

begin_define
define|#
directive|define
name|IXGBE_RTTBCNTG
value|0x04A90
end_define

begin_define
define|#
directive|define
name|IXGBE_RTTBCNIDX
value|0x08B0C
end_define

begin_define
define|#
directive|define
name|IXGBE_RTTBCNCP
value|0x08B10
end_define

begin_define
define|#
directive|define
name|IXGBE_RTFRTIMER
value|0x08B14
end_define

begin_define
define|#
directive|define
name|IXGBE_RTTBCNRTT
value|0x05150
end_define

begin_define
define|#
directive|define
name|IXGBE_RTTBCNRD
value|0x0498C
end_define

begin_comment
comment|/* FCoE DMA Context Registers */
end_comment

begin_comment
comment|/* FCoE Direct DMA Context */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FCDDC
parameter_list|(
name|_i
parameter_list|,
name|_j
parameter_list|)
value|(0x20000 + ((_i) * 0x4) + ((_j) * 0x10))
end_define

begin_define
define|#
directive|define
name|IXGBE_FCPTRL
value|0x02410
end_define

begin_comment
comment|/* FC User Desc. PTR Low */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FCPTRH
value|0x02414
end_define

begin_comment
comment|/* FC USer Desc. PTR High */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FCBUFF
value|0x02418
end_define

begin_comment
comment|/* FC Buffer Control */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FCDMARW
value|0x02420
end_define

begin_comment
comment|/* FC Receive DMA RW */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FCBUFF_VALID
value|(1<< 0)
end_define

begin_comment
comment|/* DMA Context Valid */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FCBUFF_BUFFSIZE
value|(3<< 3)
end_define

begin_comment
comment|/* User Buffer Size */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FCBUFF_WRCONTX
value|(1<< 7)
end_define

begin_comment
comment|/* 0: Initiator, 1: Target */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FCBUFF_BUFFCNT
value|0x0000ff00
end_define

begin_comment
comment|/* Number of User Buffers */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FCBUFF_OFFSET
value|0xffff0000
end_define

begin_comment
comment|/* User Buffer Offset */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FCBUFF_BUFFSIZE_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|IXGBE_FCBUFF_BUFFCNT_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|IXGBE_FCBUFF_OFFSET_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|IXGBE_FCDMARW_WE
value|(1<< 14)
end_define

begin_comment
comment|/* Write enable */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FCDMARW_RE
value|(1<< 15)
end_define

begin_comment
comment|/* Read enable */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FCDMARW_FCOESEL
value|0x000001ff
end_define

begin_comment
comment|/* FC X_ID: 11 bits */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FCDMARW_LASTSIZE
value|0xffff0000
end_define

begin_comment
comment|/* Last User Buffer Size */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FCDMARW_LASTSIZE_SHIFT
value|16
end_define

begin_comment
comment|/* FCoE SOF/EOF */
end_comment

begin_define
define|#
directive|define
name|IXGBE_TEOFF
value|0x04A94
end_define

begin_comment
comment|/* Tx FC EOF */
end_comment

begin_define
define|#
directive|define
name|IXGBE_TSOFF
value|0x04A98
end_define

begin_comment
comment|/* Tx FC SOF */
end_comment

begin_define
define|#
directive|define
name|IXGBE_REOFF
value|0x05158
end_define

begin_comment
comment|/* Rx FC EOF */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RSOFF
value|0x051F8
end_define

begin_comment
comment|/* Rx FC SOF */
end_comment

begin_comment
comment|/* FCoE Filter Context Registers */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FCD_ID
value|0x05114
end_define

begin_comment
comment|/* FCoE D_ID */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FCSMAC
value|0x0510C
end_define

begin_comment
comment|/* FCoE Source MAC */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FCFLTRW_SMAC_HIGH_SHIFT
value|16
end_define

begin_comment
comment|/* FCoE Direct Filter Context */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FCDFC
parameter_list|(
name|_i
parameter_list|,
name|_j
parameter_list|)
value|(0x28000 + ((_i) * 0x4) + ((_j) * 0x10))
end_define

begin_define
define|#
directive|define
name|IXGBE_FCDFCD
parameter_list|(
name|_i
parameter_list|)
value|(0x30000 + ((_i) * 0x4))
end_define

begin_define
define|#
directive|define
name|IXGBE_FCFLT
value|0x05108
end_define

begin_comment
comment|/* FC FLT Context */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FCFLTRW
value|0x05110
end_define

begin_comment
comment|/* FC Filter RW Control */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FCPARAM
value|0x051d8
end_define

begin_comment
comment|/* FC Offset Parameter */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FCFLT_VALID
value|(1<< 0)
end_define

begin_comment
comment|/* Filter Context Valid */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FCFLT_FIRST
value|(1<< 1)
end_define

begin_comment
comment|/* Filter First */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FCFLT_SEQID
value|0x00ff0000
end_define

begin_comment
comment|/* Sequence ID */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FCFLT_SEQCNT
value|0xff000000
end_define

begin_comment
comment|/* Sequence Count */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FCFLTRW_RVALDT
value|(1<< 13)
end_define

begin_comment
comment|/* Fast Re-Validation */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FCFLTRW_WE
value|(1<< 14)
end_define

begin_comment
comment|/* Write Enable */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FCFLTRW_RE
value|(1<< 15)
end_define

begin_comment
comment|/* Read Enable */
end_comment

begin_comment
comment|/* FCoE Receive Control */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FCRXCTRL
value|0x05100
end_define

begin_comment
comment|/* FC Receive Control */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FCRXCTRL_FCOELLI
value|(1<< 0)
end_define

begin_comment
comment|/* Low latency interrupt */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FCRXCTRL_SAVBAD
value|(1<< 1)
end_define

begin_comment
comment|/* Save Bad Frames */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FCRXCTRL_FRSTRDH
value|(1<< 2)
end_define

begin_comment
comment|/* EN 1st Read Header */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FCRXCTRL_LASTSEQH
value|(1<< 3)
end_define

begin_comment
comment|/* EN Last Header in Seq */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FCRXCTRL_ALLH
value|(1<< 4)
end_define

begin_comment
comment|/* EN All Headers */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FCRXCTRL_FRSTSEQH
value|(1<< 5)
end_define

begin_comment
comment|/* EN 1st Seq. Header */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FCRXCTRL_ICRC
value|(1<< 6)
end_define

begin_comment
comment|/* Ignore Bad FC CRC */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FCRXCTRL_FCCRCBO
value|(1<< 7)
end_define

begin_comment
comment|/* FC CRC Byte Ordering */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FCRXCTRL_FCOEVER
value|0x00000f00
end_define

begin_comment
comment|/* FCoE Version: 4 bits */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FCRXCTRL_FCOEVER_SHIFT
value|8
end_define

begin_comment
comment|/* FCoE Redirection */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FCRECTL
value|0x0ED00
end_define

begin_comment
comment|/* FC Redirection Control */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FCRETA0
value|0x0ED10
end_define

begin_comment
comment|/* FC Redirection Table 0 */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FCRETA
parameter_list|(
name|_i
parameter_list|)
value|(IXGBE_FCRETA0 + ((_i) * 4))
end_define

begin_comment
comment|/* FCoE Redir */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FCRECTL_ENA
value|0x1
end_define

begin_comment
comment|/* FCoE Redir Table Enable */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FCRETASEL_ENA
value|0x2
end_define

begin_comment
comment|/* FCoE FCRETASEL bit */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FCRETA_SIZE
value|8
end_define

begin_comment
comment|/* Max entries in FCRETA */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FCRETA_ENTRY_MASK
value|0x0000007f
end_define

begin_comment
comment|/* 7 bits for the queue index */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FCRETA_SIZE_X550
value|32
end_define

begin_comment
comment|/* Max entries in FCRETA */
end_comment

begin_comment
comment|/* Higher 7 bits for the queue index */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FCRETA_ENTRY_HIGH_MASK
value|0x007F0000
end_define

begin_define
define|#
directive|define
name|IXGBE_FCRETA_ENTRY_HIGH_SHIFT
value|16
end_define

begin_comment
comment|/* Stats registers */
end_comment

begin_define
define|#
directive|define
name|IXGBE_CRCERRS
value|0x04000
end_define

begin_define
define|#
directive|define
name|IXGBE_ILLERRC
value|0x04004
end_define

begin_define
define|#
directive|define
name|IXGBE_ERRBC
value|0x04008
end_define

begin_define
define|#
directive|define
name|IXGBE_MSPDC
value|0x04010
end_define

begin_define
define|#
directive|define
name|IXGBE_MPC
parameter_list|(
name|_i
parameter_list|)
value|(0x03FA0 + ((_i) * 4))
end_define

begin_comment
comment|/* 8 of these 3FA0-3FBC*/
end_comment

begin_define
define|#
directive|define
name|IXGBE_MLFC
value|0x04034
end_define

begin_define
define|#
directive|define
name|IXGBE_MRFC
value|0x04038
end_define

begin_define
define|#
directive|define
name|IXGBE_RLEC
value|0x04040
end_define

begin_define
define|#
directive|define
name|IXGBE_LXONTXC
value|0x03F60
end_define

begin_define
define|#
directive|define
name|IXGBE_LXONRXC
value|0x0CF60
end_define

begin_define
define|#
directive|define
name|IXGBE_LXOFFTXC
value|0x03F68
end_define

begin_define
define|#
directive|define
name|IXGBE_LXOFFRXC
value|0x0CF68
end_define

begin_define
define|#
directive|define
name|IXGBE_LXONRXCNT
value|0x041A4
end_define

begin_define
define|#
directive|define
name|IXGBE_LXOFFRXCNT
value|0x041A8
end_define

begin_define
define|#
directive|define
name|IXGBE_PXONRXCNT
parameter_list|(
name|_i
parameter_list|)
value|(0x04140 + ((_i) * 4))
end_define

begin_comment
comment|/* 8 of these */
end_comment

begin_define
define|#
directive|define
name|IXGBE_PXOFFRXCNT
parameter_list|(
name|_i
parameter_list|)
value|(0x04160 + ((_i) * 4))
end_define

begin_comment
comment|/* 8 of these */
end_comment

begin_define
define|#
directive|define
name|IXGBE_PXON2OFFCNT
parameter_list|(
name|_i
parameter_list|)
value|(0x03240 + ((_i) * 4))
end_define

begin_comment
comment|/* 8 of these */
end_comment

begin_define
define|#
directive|define
name|IXGBE_PXONTXC
parameter_list|(
name|_i
parameter_list|)
value|(0x03F00 + ((_i) * 4))
end_define

begin_comment
comment|/* 8 of these 3F00-3F1C*/
end_comment

begin_define
define|#
directive|define
name|IXGBE_PXONRXC
parameter_list|(
name|_i
parameter_list|)
value|(0x0CF00 + ((_i) * 4))
end_define

begin_comment
comment|/* 8 of these CF00-CF1C*/
end_comment

begin_define
define|#
directive|define
name|IXGBE_PXOFFTXC
parameter_list|(
name|_i
parameter_list|)
value|(0x03F20 + ((_i) * 4))
end_define

begin_comment
comment|/* 8 of these 3F20-3F3C*/
end_comment

begin_define
define|#
directive|define
name|IXGBE_PXOFFRXC
parameter_list|(
name|_i
parameter_list|)
value|(0x0CF20 + ((_i) * 4))
end_define

begin_comment
comment|/* 8 of these CF20-CF3C*/
end_comment

begin_define
define|#
directive|define
name|IXGBE_PRC64
value|0x0405C
end_define

begin_define
define|#
directive|define
name|IXGBE_PRC127
value|0x04060
end_define

begin_define
define|#
directive|define
name|IXGBE_PRC255
value|0x04064
end_define

begin_define
define|#
directive|define
name|IXGBE_PRC511
value|0x04068
end_define

begin_define
define|#
directive|define
name|IXGBE_PRC1023
value|0x0406C
end_define

begin_define
define|#
directive|define
name|IXGBE_PRC1522
value|0x04070
end_define

begin_define
define|#
directive|define
name|IXGBE_GPRC
value|0x04074
end_define

begin_define
define|#
directive|define
name|IXGBE_BPRC
value|0x04078
end_define

begin_define
define|#
directive|define
name|IXGBE_MPRC
value|0x0407C
end_define

begin_define
define|#
directive|define
name|IXGBE_GPTC
value|0x04080
end_define

begin_define
define|#
directive|define
name|IXGBE_GORCL
value|0x04088
end_define

begin_define
define|#
directive|define
name|IXGBE_GORCH
value|0x0408C
end_define

begin_define
define|#
directive|define
name|IXGBE_GOTCL
value|0x04090
end_define

begin_define
define|#
directive|define
name|IXGBE_GOTCH
value|0x04094
end_define

begin_define
define|#
directive|define
name|IXGBE_RNBC
parameter_list|(
name|_i
parameter_list|)
value|(0x03FC0 + ((_i) * 4))
end_define

begin_comment
comment|/* 8 of these 3FC0-3FDC*/
end_comment

begin_define
define|#
directive|define
name|IXGBE_RUC
value|0x040A4
end_define

begin_define
define|#
directive|define
name|IXGBE_RFC
value|0x040A8
end_define

begin_define
define|#
directive|define
name|IXGBE_ROC
value|0x040AC
end_define

begin_define
define|#
directive|define
name|IXGBE_RJC
value|0x040B0
end_define

begin_define
define|#
directive|define
name|IXGBE_MNGPRC
value|0x040B4
end_define

begin_define
define|#
directive|define
name|IXGBE_MNGPDC
value|0x040B8
end_define

begin_define
define|#
directive|define
name|IXGBE_MNGPTC
value|0x0CF90
end_define

begin_define
define|#
directive|define
name|IXGBE_TORL
value|0x040C0
end_define

begin_define
define|#
directive|define
name|IXGBE_TORH
value|0x040C4
end_define

begin_define
define|#
directive|define
name|IXGBE_TPR
value|0x040D0
end_define

begin_define
define|#
directive|define
name|IXGBE_TPT
value|0x040D4
end_define

begin_define
define|#
directive|define
name|IXGBE_PTC64
value|0x040D8
end_define

begin_define
define|#
directive|define
name|IXGBE_PTC127
value|0x040DC
end_define

begin_define
define|#
directive|define
name|IXGBE_PTC255
value|0x040E0
end_define

begin_define
define|#
directive|define
name|IXGBE_PTC511
value|0x040E4
end_define

begin_define
define|#
directive|define
name|IXGBE_PTC1023
value|0x040E8
end_define

begin_define
define|#
directive|define
name|IXGBE_PTC1522
value|0x040EC
end_define

begin_define
define|#
directive|define
name|IXGBE_MPTC
value|0x040F0
end_define

begin_define
define|#
directive|define
name|IXGBE_BPTC
value|0x040F4
end_define

begin_define
define|#
directive|define
name|IXGBE_XEC
value|0x04120
end_define

begin_define
define|#
directive|define
name|IXGBE_SSVPC
value|0x08780
end_define

begin_define
define|#
directive|define
name|IXGBE_RQSMR
parameter_list|(
name|_i
parameter_list|)
value|(0x02300 + ((_i) * 4))
end_define

begin_define
define|#
directive|define
name|IXGBE_TQSMR
parameter_list|(
name|_i
parameter_list|)
value|(((_i)<= 7) ? (0x07300 + ((_i) * 4)) : \ 			 (0x08600 + ((_i) * 4)))
end_define

begin_define
define|#
directive|define
name|IXGBE_TQSM
parameter_list|(
name|_i
parameter_list|)
value|(0x08600 + ((_i) * 4))
end_define

begin_define
define|#
directive|define
name|IXGBE_QPRC
parameter_list|(
name|_i
parameter_list|)
value|(0x01030 + ((_i) * 0x40))
end_define

begin_comment
comment|/* 16 of these */
end_comment

begin_define
define|#
directive|define
name|IXGBE_QPTC
parameter_list|(
name|_i
parameter_list|)
value|(0x06030 + ((_i) * 0x40))
end_define

begin_comment
comment|/* 16 of these */
end_comment

begin_define
define|#
directive|define
name|IXGBE_QBRC
parameter_list|(
name|_i
parameter_list|)
value|(0x01034 + ((_i) * 0x40))
end_define

begin_comment
comment|/* 16 of these */
end_comment

begin_define
define|#
directive|define
name|IXGBE_QBTC
parameter_list|(
name|_i
parameter_list|)
value|(0x06034 + ((_i) * 0x40))
end_define

begin_comment
comment|/* 16 of these */
end_comment

begin_define
define|#
directive|define
name|IXGBE_QBRC_L
parameter_list|(
name|_i
parameter_list|)
value|(0x01034 + ((_i) * 0x40))
end_define

begin_comment
comment|/* 16 of these */
end_comment

begin_define
define|#
directive|define
name|IXGBE_QBRC_H
parameter_list|(
name|_i
parameter_list|)
value|(0x01038 + ((_i) * 0x40))
end_define

begin_comment
comment|/* 16 of these */
end_comment

begin_define
define|#
directive|define
name|IXGBE_QPRDC
parameter_list|(
name|_i
parameter_list|)
value|(0x01430 + ((_i) * 0x40))
end_define

begin_comment
comment|/* 16 of these */
end_comment

begin_define
define|#
directive|define
name|IXGBE_QBTC_L
parameter_list|(
name|_i
parameter_list|)
value|(0x08700 + ((_i) * 0x8))
end_define

begin_comment
comment|/* 16 of these */
end_comment

begin_define
define|#
directive|define
name|IXGBE_QBTC_H
parameter_list|(
name|_i
parameter_list|)
value|(0x08704 + ((_i) * 0x8))
end_define

begin_comment
comment|/* 16 of these */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FCCRC
value|0x05118
end_define

begin_comment
comment|/* Num of Good Eth CRC w/ Bad FC CRC */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FCOERPDC
value|0x0241C
end_define

begin_comment
comment|/* FCoE Rx Packets Dropped Count */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FCLAST
value|0x02424
end_define

begin_comment
comment|/* FCoE Last Error Count */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FCOEPRC
value|0x02428
end_define

begin_comment
comment|/* Number of FCoE Packets Received */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FCOEDWRC
value|0x0242C
end_define

begin_comment
comment|/* Number of FCoE DWords Received */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FCOEPTC
value|0x08784
end_define

begin_comment
comment|/* Number of FCoE Packets Transmitted */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FCOEDWTC
value|0x08788
end_define

begin_comment
comment|/* Number of FCoE DWords Transmitted */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FCCRC_CNT_MASK
value|0x0000FFFF
end_define

begin_comment
comment|/* CRC_CNT: bit 0 - 15 */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FCLAST_CNT_MASK
value|0x0000FFFF
end_define

begin_comment
comment|/* Last_CNT: bit 0 - 15 */
end_comment

begin_define
define|#
directive|define
name|IXGBE_O2BGPTC
value|0x041C4
end_define

begin_define
define|#
directive|define
name|IXGBE_O2BSPC
value|0x087B0
end_define

begin_define
define|#
directive|define
name|IXGBE_B2OSPC
value|0x041C0
end_define

begin_define
define|#
directive|define
name|IXGBE_B2OGPRC
value|0x02F90
end_define

begin_define
define|#
directive|define
name|IXGBE_BUPRC
value|0x04180
end_define

begin_define
define|#
directive|define
name|IXGBE_BMPRC
value|0x04184
end_define

begin_define
define|#
directive|define
name|IXGBE_BBPRC
value|0x04188
end_define

begin_define
define|#
directive|define
name|IXGBE_BUPTC
value|0x0418C
end_define

begin_define
define|#
directive|define
name|IXGBE_BMPTC
value|0x04190
end_define

begin_define
define|#
directive|define
name|IXGBE_BBPTC
value|0x04194
end_define

begin_define
define|#
directive|define
name|IXGBE_BCRCERRS
value|0x04198
end_define

begin_define
define|#
directive|define
name|IXGBE_BXONRXC
value|0x0419C
end_define

begin_define
define|#
directive|define
name|IXGBE_BXOFFRXC
value|0x041E0
end_define

begin_define
define|#
directive|define
name|IXGBE_BXONTXC
value|0x041E4
end_define

begin_define
define|#
directive|define
name|IXGBE_BXOFFTXC
value|0x041E8
end_define

begin_comment
comment|/* Management */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MAVTV
parameter_list|(
name|_i
parameter_list|)
value|(0x05010 + ((_i) * 4))
end_define

begin_comment
comment|/* 8 of these (0-7) */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MFUTP
parameter_list|(
name|_i
parameter_list|)
value|(0x05030 + ((_i) * 4))
end_define

begin_comment
comment|/* 8 of these (0-7) */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MANC
value|0x05820
end_define

begin_define
define|#
directive|define
name|IXGBE_MFVAL
value|0x05824
end_define

begin_define
define|#
directive|define
name|IXGBE_MANC2H
value|0x05860
end_define

begin_define
define|#
directive|define
name|IXGBE_MDEF
parameter_list|(
name|_i
parameter_list|)
value|(0x05890 + ((_i) * 4))
end_define

begin_comment
comment|/* 8 of these (0-7) */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MIPAF
value|0x058B0
end_define

begin_define
define|#
directive|define
name|IXGBE_MMAL
parameter_list|(
name|_i
parameter_list|)
value|(0x05910 + ((_i) * 8))
end_define

begin_comment
comment|/* 4 of these (0-3) */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MMAH
parameter_list|(
name|_i
parameter_list|)
value|(0x05914 + ((_i) * 8))
end_define

begin_comment
comment|/* 4 of these (0-3) */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FTFT
value|0x09400
end_define

begin_comment
comment|/* 0x9400-0x97FC */
end_comment

begin_define
define|#
directive|define
name|IXGBE_METF
parameter_list|(
name|_i
parameter_list|)
value|(0x05190 + ((_i) * 4))
end_define

begin_comment
comment|/* 4 of these (0-3) */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MDEF_EXT
parameter_list|(
name|_i
parameter_list|)
value|(0x05160 + ((_i) * 4))
end_define

begin_comment
comment|/* 8 of these (0-7) */
end_comment

begin_define
define|#
directive|define
name|IXGBE_LSWFW
value|0x15F14
end_define

begin_define
define|#
directive|define
name|IXGBE_BMCIP
parameter_list|(
name|_i
parameter_list|)
value|(0x05050 + ((_i) * 4))
end_define

begin_comment
comment|/* 0x5050-0x505C */
end_comment

begin_define
define|#
directive|define
name|IXGBE_BMCIPVAL
value|0x05060
end_define

begin_define
define|#
directive|define
name|IXGBE_BMCIP_IPADDR_TYPE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|IXGBE_BMCIP_IPADDR_VALID
value|0x00000002
end_define

begin_comment
comment|/* Management Bit Fields and Masks */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MANC_MPROXYE
value|0x40000000
end_define

begin_comment
comment|/* Management Proxy Enable */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MANC_RCV_TCO_EN
value|0x00020000
end_define

begin_comment
comment|/* Rcv TCO packet enable */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MANC_EN_BMC2OS
value|0x10000000
end_define

begin_comment
comment|/* Ena BMC2OS and OS2BMC traffic */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MANC_EN_BMC2OS_SHIFT
value|28
end_define

begin_comment
comment|/* Firmware Semaphore Register */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FWSM_MODE_MASK
value|0xE
end_define

begin_define
define|#
directive|define
name|IXGBE_FWSM_TS_ENABLED
value|0x1
end_define

begin_define
define|#
directive|define
name|IXGBE_FWSM_FW_MODE_PT
value|0x4
end_define

begin_comment
comment|/* ARC Subsystem registers */
end_comment

begin_define
define|#
directive|define
name|IXGBE_HICR
value|0x15F00
end_define

begin_define
define|#
directive|define
name|IXGBE_FWSTS
value|0x15F0C
end_define

begin_define
define|#
directive|define
name|IXGBE_HSMC0R
value|0x15F04
end_define

begin_define
define|#
directive|define
name|IXGBE_HSMC1R
value|0x15F08
end_define

begin_define
define|#
directive|define
name|IXGBE_SWSR
value|0x15F10
end_define

begin_define
define|#
directive|define
name|IXGBE_HFDR
value|0x15FE8
end_define

begin_define
define|#
directive|define
name|IXGBE_FLEX_MNG
value|0x15800
end_define

begin_comment
comment|/* 0x15800 - 0x15EFC */
end_comment

begin_define
define|#
directive|define
name|IXGBE_HICR_EN
value|0x01
end_define

begin_comment
comment|/* Enable bit - RO */
end_comment

begin_comment
comment|/* Driver sets this bit when done to put command in RAM */
end_comment

begin_define
define|#
directive|define
name|IXGBE_HICR_C
value|0x02
end_define

begin_define
define|#
directive|define
name|IXGBE_HICR_SV
value|0x04
end_define

begin_comment
comment|/* Status Validity */
end_comment

begin_define
define|#
directive|define
name|IXGBE_HICR_FW_RESET_ENABLE
value|0x40
end_define

begin_define
define|#
directive|define
name|IXGBE_HICR_FW_RESET
value|0x80
end_define

begin_comment
comment|/* PCI-E registers */
end_comment

begin_define
define|#
directive|define
name|IXGBE_GCR
value|0x11000
end_define

begin_define
define|#
directive|define
name|IXGBE_GTV
value|0x11004
end_define

begin_define
define|#
directive|define
name|IXGBE_FUNCTAG
value|0x11008
end_define

begin_define
define|#
directive|define
name|IXGBE_GLT
value|0x1100C
end_define

begin_define
define|#
directive|define
name|IXGBE_PCIEPIPEADR
value|0x11004
end_define

begin_define
define|#
directive|define
name|IXGBE_PCIEPIPEDAT
value|0x11008
end_define

begin_define
define|#
directive|define
name|IXGBE_GSCL_1
value|0x11010
end_define

begin_define
define|#
directive|define
name|IXGBE_GSCL_2
value|0x11014
end_define

begin_define
define|#
directive|define
name|IXGBE_GSCL_1_X540
value|IXGBE_GSCL_1
end_define

begin_define
define|#
directive|define
name|IXGBE_GSCL_2_X540
value|IXGBE_GSCL_2
end_define

begin_define
define|#
directive|define
name|IXGBE_GSCL_3
value|0x11018
end_define

begin_define
define|#
directive|define
name|IXGBE_GSCL_4
value|0x1101C
end_define

begin_define
define|#
directive|define
name|IXGBE_GSCN_0
value|0x11020
end_define

begin_define
define|#
directive|define
name|IXGBE_GSCN_1
value|0x11024
end_define

begin_define
define|#
directive|define
name|IXGBE_GSCN_2
value|0x11028
end_define

begin_define
define|#
directive|define
name|IXGBE_GSCN_3
value|0x1102C
end_define

begin_define
define|#
directive|define
name|IXGBE_GSCN_0_X540
value|IXGBE_GSCN_0
end_define

begin_define
define|#
directive|define
name|IXGBE_GSCN_1_X540
value|IXGBE_GSCN_1
end_define

begin_define
define|#
directive|define
name|IXGBE_GSCN_2_X540
value|IXGBE_GSCN_2
end_define

begin_define
define|#
directive|define
name|IXGBE_GSCN_3_X540
value|IXGBE_GSCN_3
end_define

begin_define
define|#
directive|define
name|IXGBE_FACTPS
value|0x10150
end_define

begin_define
define|#
directive|define
name|IXGBE_FACTPS_X540
value|IXGBE_FACTPS
end_define

begin_define
define|#
directive|define
name|IXGBE_GSCL_1_X550
value|0x11800
end_define

begin_define
define|#
directive|define
name|IXGBE_GSCL_2_X550
value|0x11804
end_define

begin_define
define|#
directive|define
name|IXGBE_GSCL_1_X550EM_x
value|IXGBE_GSCL_1_X550
end_define

begin_define
define|#
directive|define
name|IXGBE_GSCL_2_X550EM_x
value|IXGBE_GSCL_2_X550
end_define

begin_define
define|#
directive|define
name|IXGBE_GSCN_0_X550
value|0x11820
end_define

begin_define
define|#
directive|define
name|IXGBE_GSCN_1_X550
value|0x11824
end_define

begin_define
define|#
directive|define
name|IXGBE_GSCN_2_X550
value|0x11828
end_define

begin_define
define|#
directive|define
name|IXGBE_GSCN_3_X550
value|0x1182C
end_define

begin_define
define|#
directive|define
name|IXGBE_GSCN_0_X550EM_x
value|IXGBE_GSCN_0_X550
end_define

begin_define
define|#
directive|define
name|IXGBE_GSCN_1_X550EM_x
value|IXGBE_GSCN_1_X550
end_define

begin_define
define|#
directive|define
name|IXGBE_GSCN_2_X550EM_x
value|IXGBE_GSCN_2_X550
end_define

begin_define
define|#
directive|define
name|IXGBE_GSCN_3_X550EM_x
value|IXGBE_GSCN_3_X550
end_define

begin_define
define|#
directive|define
name|IXGBE_FACTPS_X550
value|IXGBE_FACTPS
end_define

begin_define
define|#
directive|define
name|IXGBE_FACTPS_X550EM_x
value|IXGBE_FACTPS
end_define

begin_define
define|#
directive|define
name|IXGBE_GSCL_1_X550EM_a
value|IXGBE_GSCL_1_X550
end_define

begin_define
define|#
directive|define
name|IXGBE_GSCL_2_X550EM_a
value|IXGBE_GSCL_2_X550
end_define

begin_define
define|#
directive|define
name|IXGBE_GSCN_0_X550EM_a
value|IXGBE_GSCN_0_X550
end_define

begin_define
define|#
directive|define
name|IXGBE_GSCN_1_X550EM_a
value|IXGBE_GSCN_1_X550
end_define

begin_define
define|#
directive|define
name|IXGBE_GSCN_2_X550EM_a
value|IXGBE_GSCN_2_X550
end_define

begin_define
define|#
directive|define
name|IXGBE_GSCN_3_X550EM_a
value|IXGBE_GSCN_3_X550
end_define

begin_define
define|#
directive|define
name|IXGBE_FACTPS_X550EM_a
value|0x15FEC
end_define

begin_define
define|#
directive|define
name|IXGBE_FACTPS_BY_MAC
parameter_list|(
name|_hw
parameter_list|)
value|IXGBE_BY_MAC((_hw), FACTPS)
end_define

begin_define
define|#
directive|define
name|IXGBE_PCIEANACTL
value|0x11040
end_define

begin_define
define|#
directive|define
name|IXGBE_SWSM
value|0x10140
end_define

begin_define
define|#
directive|define
name|IXGBE_SWSM_X540
value|IXGBE_SWSM
end_define

begin_define
define|#
directive|define
name|IXGBE_SWSM_X550
value|IXGBE_SWSM
end_define

begin_define
define|#
directive|define
name|IXGBE_SWSM_X550EM_x
value|IXGBE_SWSM
end_define

begin_define
define|#
directive|define
name|IXGBE_SWSM_X550EM_a
value|0x15F70
end_define

begin_define
define|#
directive|define
name|IXGBE_SWSM_BY_MAC
parameter_list|(
name|_hw
parameter_list|)
value|IXGBE_BY_MAC((_hw), SWSM)
end_define

begin_define
define|#
directive|define
name|IXGBE_FWSM
value|0x10148
end_define

begin_define
define|#
directive|define
name|IXGBE_FWSM_X540
value|IXGBE_FWSM
end_define

begin_define
define|#
directive|define
name|IXGBE_FWSM_X550
value|IXGBE_FWSM
end_define

begin_define
define|#
directive|define
name|IXGBE_FWSM_X550EM_x
value|IXGBE_FWSM
end_define

begin_define
define|#
directive|define
name|IXGBE_FWSM_X550EM_a
value|0x15F74
end_define

begin_define
define|#
directive|define
name|IXGBE_FWSM_BY_MAC
parameter_list|(
name|_hw
parameter_list|)
value|IXGBE_BY_MAC((_hw), FWSM)
end_define

begin_define
define|#
directive|define
name|IXGBE_SWFW_SYNC
value|IXGBE_GSSR
end_define

begin_define
define|#
directive|define
name|IXGBE_SWFW_SYNC_X540
value|IXGBE_SWFW_SYNC
end_define

begin_define
define|#
directive|define
name|IXGBE_SWFW_SYNC_X550
value|IXGBE_SWFW_SYNC
end_define

begin_define
define|#
directive|define
name|IXGBE_SWFW_SYNC_X550EM_x
value|IXGBE_SWFW_SYNC
end_define

begin_define
define|#
directive|define
name|IXGBE_SWFW_SYNC_X550EM_a
value|0x15F78
end_define

begin_define
define|#
directive|define
name|IXGBE_SWFW_SYNC_BY_MAC
parameter_list|(
name|_hw
parameter_list|)
value|IXGBE_BY_MAC((_hw), SWFW_SYNC)
end_define

begin_define
define|#
directive|define
name|IXGBE_GSSR
value|0x10160
end_define

begin_define
define|#
directive|define
name|IXGBE_MREVID
value|0x11064
end_define

begin_define
define|#
directive|define
name|IXGBE_DCA_ID
value|0x11070
end_define

begin_define
define|#
directive|define
name|IXGBE_DCA_CTRL
value|0x11074
end_define

begin_comment
comment|/* PCI-E registers 82599-Specific */
end_comment

begin_define
define|#
directive|define
name|IXGBE_GCR_EXT
value|0x11050
end_define

begin_define
define|#
directive|define
name|IXGBE_GSCL_5_82599
value|0x11030
end_define

begin_define
define|#
directive|define
name|IXGBE_GSCL_6_82599
value|0x11034
end_define

begin_define
define|#
directive|define
name|IXGBE_GSCL_7_82599
value|0x11038
end_define

begin_define
define|#
directive|define
name|IXGBE_GSCL_8_82599
value|0x1103C
end_define

begin_define
define|#
directive|define
name|IXGBE_GSCL_5_X540
value|IXGBE_GSCL_5_82599
end_define

begin_define
define|#
directive|define
name|IXGBE_GSCL_6_X540
value|IXGBE_GSCL_6_82599
end_define

begin_define
define|#
directive|define
name|IXGBE_GSCL_7_X540
value|IXGBE_GSCL_7_82599
end_define

begin_define
define|#
directive|define
name|IXGBE_GSCL_8_X540
value|IXGBE_GSCL_8_82599
end_define

begin_define
define|#
directive|define
name|IXGBE_PHYADR_82599
value|0x11040
end_define

begin_define
define|#
directive|define
name|IXGBE_PHYDAT_82599
value|0x11044
end_define

begin_define
define|#
directive|define
name|IXGBE_PHYCTL_82599
value|0x11048
end_define

begin_define
define|#
directive|define
name|IXGBE_PBACLR_82599
value|0x11068
end_define

begin_define
define|#
directive|define
name|IXGBE_CIAA
value|0x11088
end_define

begin_define
define|#
directive|define
name|IXGBE_CIAD
value|0x1108C
end_define

begin_define
define|#
directive|define
name|IXGBE_CIAA_82599
value|IXGBE_CIAA
end_define

begin_define
define|#
directive|define
name|IXGBE_CIAD_82599
value|IXGBE_CIAD
end_define

begin_define
define|#
directive|define
name|IXGBE_CIAA_X540
value|IXGBE_CIAA
end_define

begin_define
define|#
directive|define
name|IXGBE_CIAD_X540
value|IXGBE_CIAD
end_define

begin_define
define|#
directive|define
name|IXGBE_GSCL_5_X550
value|0x11810
end_define

begin_define
define|#
directive|define
name|IXGBE_GSCL_6_X550
value|0x11814
end_define

begin_define
define|#
directive|define
name|IXGBE_GSCL_7_X550
value|0x11818
end_define

begin_define
define|#
directive|define
name|IXGBE_GSCL_8_X550
value|0x1181C
end_define

begin_define
define|#
directive|define
name|IXGBE_GSCL_5_X550EM_x
value|IXGBE_GSCL_5_X550
end_define

begin_define
define|#
directive|define
name|IXGBE_GSCL_6_X550EM_x
value|IXGBE_GSCL_6_X550
end_define

begin_define
define|#
directive|define
name|IXGBE_GSCL_7_X550EM_x
value|IXGBE_GSCL_7_X550
end_define

begin_define
define|#
directive|define
name|IXGBE_GSCL_8_X550EM_x
value|IXGBE_GSCL_8_X550
end_define

begin_define
define|#
directive|define
name|IXGBE_CIAA_X550
value|0x11508
end_define

begin_define
define|#
directive|define
name|IXGBE_CIAD_X550
value|0x11510
end_define

begin_define
define|#
directive|define
name|IXGBE_CIAA_X550EM_x
value|IXGBE_CIAA_X550
end_define

begin_define
define|#
directive|define
name|IXGBE_CIAD_X550EM_x
value|IXGBE_CIAD_X550
end_define

begin_define
define|#
directive|define
name|IXGBE_GSCL_5_X550EM_a
value|IXGBE_GSCL_5_X550
end_define

begin_define
define|#
directive|define
name|IXGBE_GSCL_6_X550EM_a
value|IXGBE_GSCL_6_X550
end_define

begin_define
define|#
directive|define
name|IXGBE_GSCL_7_X550EM_a
value|IXGBE_GSCL_7_X550
end_define

begin_define
define|#
directive|define
name|IXGBE_GSCL_8_X550EM_a
value|IXGBE_GSCL_8_X550
end_define

begin_define
define|#
directive|define
name|IXGBE_CIAA_X550EM_a
value|IXGBE_CIAA_X550
end_define

begin_define
define|#
directive|define
name|IXGBE_CIAD_X550EM_a
value|IXGBE_CIAD_X550
end_define

begin_define
define|#
directive|define
name|IXGBE_CIAA_BY_MAC
parameter_list|(
name|_hw
parameter_list|)
value|IXGBE_BY_MAC((_hw), CIAA)
end_define

begin_define
define|#
directive|define
name|IXGBE_CIAD_BY_MAC
parameter_list|(
name|_hw
parameter_list|)
value|IXGBE_BY_MAC((_hw), CIAD)
end_define

begin_define
define|#
directive|define
name|IXGBE_PICAUSE
value|0x110B0
end_define

begin_define
define|#
directive|define
name|IXGBE_PIENA
value|0x110B8
end_define

begin_define
define|#
directive|define
name|IXGBE_CDQ_MBR_82599
value|0x110B4
end_define

begin_define
define|#
directive|define
name|IXGBE_PCIESPARE
value|0x110BC
end_define

begin_define
define|#
directive|define
name|IXGBE_MISC_REG_82599
value|0x110F0
end_define

begin_define
define|#
directive|define
name|IXGBE_ECC_CTRL_0_82599
value|0x11100
end_define

begin_define
define|#
directive|define
name|IXGBE_ECC_CTRL_1_82599
value|0x11104
end_define

begin_define
define|#
directive|define
name|IXGBE_ECC_STATUS_82599
value|0x110E0
end_define

begin_define
define|#
directive|define
name|IXGBE_BAR_CTRL_82599
value|0x110F4
end_define

begin_comment
comment|/* PCI Express Control */
end_comment

begin_define
define|#
directive|define
name|IXGBE_GCR_CMPL_TMOUT_MASK
value|0x0000F000
end_define

begin_define
define|#
directive|define
name|IXGBE_GCR_CMPL_TMOUT_10ms
value|0x00001000
end_define

begin_define
define|#
directive|define
name|IXGBE_GCR_CMPL_TMOUT_RESEND
value|0x00010000
end_define

begin_define
define|#
directive|define
name|IXGBE_GCR_CAP_VER2
value|0x00040000
end_define

begin_define
define|#
directive|define
name|IXGBE_GCR_EXT_MSIX_EN
value|0x80000000
end_define

begin_define
define|#
directive|define
name|IXGBE_GCR_EXT_BUFFERS_CLEAR
value|0x40000000
end_define

begin_define
define|#
directive|define
name|IXGBE_GCR_EXT_VT_MODE_16
value|0x00000001
end_define

begin_define
define|#
directive|define
name|IXGBE_GCR_EXT_VT_MODE_32
value|0x00000002
end_define

begin_define
define|#
directive|define
name|IXGBE_GCR_EXT_VT_MODE_64
value|0x00000003
end_define

begin_define
define|#
directive|define
name|IXGBE_GCR_EXT_SRIOV
value|(IXGBE_GCR_EXT_MSIX_EN | \ 					 IXGBE_GCR_EXT_VT_MODE_64)
end_define

begin_define
define|#
directive|define
name|IXGBE_GCR_EXT_VT_MODE_MASK
value|0x00000003
end_define

begin_comment
comment|/* Time Sync Registers */
end_comment

begin_define
define|#
directive|define
name|IXGBE_TSYNCRXCTL
value|0x05188
end_define

begin_comment
comment|/* Rx Time Sync Control register - RW */
end_comment

begin_define
define|#
directive|define
name|IXGBE_TSYNCTXCTL
value|0x08C00
end_define

begin_comment
comment|/* Tx Time Sync Control register - RW */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXSTMPL
value|0x051E8
end_define

begin_comment
comment|/* Rx timestamp Low - RO */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXSTMPH
value|0x051A4
end_define

begin_comment
comment|/* Rx timestamp High - RO */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXSATRL
value|0x051A0
end_define

begin_comment
comment|/* Rx timestamp attribute low - RO */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXSATRH
value|0x051A8
end_define

begin_comment
comment|/* Rx timestamp attribute high - RO */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXMTRL
value|0x05120
end_define

begin_comment
comment|/* RX message type register low - RW */
end_comment

begin_define
define|#
directive|define
name|IXGBE_TXSTMPL
value|0x08C04
end_define

begin_comment
comment|/* Tx timestamp value Low - RO */
end_comment

begin_define
define|#
directive|define
name|IXGBE_TXSTMPH
value|0x08C08
end_define

begin_comment
comment|/* Tx timestamp value High - RO */
end_comment

begin_define
define|#
directive|define
name|IXGBE_SYSTIML
value|0x08C0C
end_define

begin_comment
comment|/* System time register Low - RO */
end_comment

begin_define
define|#
directive|define
name|IXGBE_SYSTIMH
value|0x08C10
end_define

begin_comment
comment|/* System time register High - RO */
end_comment

begin_define
define|#
directive|define
name|IXGBE_SYSTIMR
value|0x08C58
end_define

begin_comment
comment|/* System time register Residue - RO */
end_comment

begin_define
define|#
directive|define
name|IXGBE_TIMINCA
value|0x08C14
end_define

begin_comment
comment|/* Increment attributes register - RW */
end_comment

begin_define
define|#
directive|define
name|IXGBE_TIMADJL
value|0x08C18
end_define

begin_comment
comment|/* Time Adjustment Offset register Low - RW */
end_comment

begin_define
define|#
directive|define
name|IXGBE_TIMADJH
value|0x08C1C
end_define

begin_comment
comment|/* Time Adjustment Offset register High - RW */
end_comment

begin_define
define|#
directive|define
name|IXGBE_TSAUXC
value|0x08C20
end_define

begin_comment
comment|/* TimeSync Auxiliary Control register - RW */
end_comment

begin_define
define|#
directive|define
name|IXGBE_TRGTTIML0
value|0x08C24
end_define

begin_comment
comment|/* Target Time Register 0 Low - RW */
end_comment

begin_define
define|#
directive|define
name|IXGBE_TRGTTIMH0
value|0x08C28
end_define

begin_comment
comment|/* Target Time Register 0 High - RW */
end_comment

begin_define
define|#
directive|define
name|IXGBE_TRGTTIML1
value|0x08C2C
end_define

begin_comment
comment|/* Target Time Register 1 Low - RW */
end_comment

begin_define
define|#
directive|define
name|IXGBE_TRGTTIMH1
value|0x08C30
end_define

begin_comment
comment|/* Target Time Register 1 High - RW */
end_comment

begin_define
define|#
directive|define
name|IXGBE_CLKTIML
value|0x08C34
end_define

begin_comment
comment|/* Clock Out Time Register Low - RW */
end_comment

begin_define
define|#
directive|define
name|IXGBE_CLKTIMH
value|0x08C38
end_define

begin_comment
comment|/* Clock Out Time Register High - RW */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FREQOUT0
value|0x08C34
end_define

begin_comment
comment|/* Frequency Out 0 Control register - RW */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FREQOUT1
value|0x08C38
end_define

begin_comment
comment|/* Frequency Out 1 Control register - RW */
end_comment

begin_define
define|#
directive|define
name|IXGBE_AUXSTMPL0
value|0x08C3C
end_define

begin_comment
comment|/* Auxiliary Time Stamp 0 register Low - RO */
end_comment

begin_define
define|#
directive|define
name|IXGBE_AUXSTMPH0
value|0x08C40
end_define

begin_comment
comment|/* Auxiliary Time Stamp 0 register High - RO */
end_comment

begin_define
define|#
directive|define
name|IXGBE_AUXSTMPL1
value|0x08C44
end_define

begin_comment
comment|/* Auxiliary Time Stamp 1 register Low - RO */
end_comment

begin_define
define|#
directive|define
name|IXGBE_AUXSTMPH1
value|0x08C48
end_define

begin_comment
comment|/* Auxiliary Time Stamp 1 register High - RO */
end_comment

begin_define
define|#
directive|define
name|IXGBE_TSIM
value|0x08C68
end_define

begin_comment
comment|/* TimeSync Interrupt Mask Register - RW */
end_comment

begin_define
define|#
directive|define
name|IXGBE_TSICR
value|0x08C60
end_define

begin_comment
comment|/* TimeSync Interrupt Cause Register - WO */
end_comment

begin_define
define|#
directive|define
name|IXGBE_TSSDP
value|0x0003C
end_define

begin_comment
comment|/* TimeSync SDP Configuration Register - RW */
end_comment

begin_comment
comment|/* Diagnostic Registers */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RDSTATCTL
value|0x02C20
end_define

begin_define
define|#
directive|define
name|IXGBE_RDSTAT
parameter_list|(
name|_i
parameter_list|)
value|(0x02C00 + ((_i) * 4))
end_define

begin_comment
comment|/* 0x02C00-0x02C1C */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RDHMPN
value|0x02F08
end_define

begin_define
define|#
directive|define
name|IXGBE_RIC_DW
parameter_list|(
name|_i
parameter_list|)
value|(0x02F10 + ((_i) * 4))
end_define

begin_define
define|#
directive|define
name|IXGBE_RDPROBE
value|0x02F20
end_define

begin_define
define|#
directive|define
name|IXGBE_RDMAM
value|0x02F30
end_define

begin_define
define|#
directive|define
name|IXGBE_RDMAD
value|0x02F34
end_define

begin_define
define|#
directive|define
name|IXGBE_TDHMPN
value|0x07F08
end_define

begin_define
define|#
directive|define
name|IXGBE_TDHMPN2
value|0x082FC
end_define

begin_define
define|#
directive|define
name|IXGBE_TXDESCIC
value|0x082CC
end_define

begin_define
define|#
directive|define
name|IXGBE_TIC_DW
parameter_list|(
name|_i
parameter_list|)
value|(0x07F10 + ((_i) * 4))
end_define

begin_define
define|#
directive|define
name|IXGBE_TIC_DW2
parameter_list|(
name|_i
parameter_list|)
value|(0x082B0 + ((_i) * 4))
end_define

begin_define
define|#
directive|define
name|IXGBE_TDPROBE
value|0x07F20
end_define

begin_define
define|#
directive|define
name|IXGBE_TXBUFCTRL
value|0x0C600
end_define

begin_define
define|#
directive|define
name|IXGBE_TXBUFDATA0
value|0x0C610
end_define

begin_define
define|#
directive|define
name|IXGBE_TXBUFDATA1
value|0x0C614
end_define

begin_define
define|#
directive|define
name|IXGBE_TXBUFDATA2
value|0x0C618
end_define

begin_define
define|#
directive|define
name|IXGBE_TXBUFDATA3
value|0x0C61C
end_define

begin_define
define|#
directive|define
name|IXGBE_RXBUFCTRL
value|0x03600
end_define

begin_define
define|#
directive|define
name|IXGBE_RXBUFDATA0
value|0x03610
end_define

begin_define
define|#
directive|define
name|IXGBE_RXBUFDATA1
value|0x03614
end_define

begin_define
define|#
directive|define
name|IXGBE_RXBUFDATA2
value|0x03618
end_define

begin_define
define|#
directive|define
name|IXGBE_RXBUFDATA3
value|0x0361C
end_define

begin_define
define|#
directive|define
name|IXGBE_PCIE_DIAG
parameter_list|(
name|_i
parameter_list|)
value|(0x11090 + ((_i) * 4))
end_define

begin_comment
comment|/* 8 of these */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RFVAL
value|0x050A4
end_define

begin_define
define|#
directive|define
name|IXGBE_MDFTC1
value|0x042B8
end_define

begin_define
define|#
directive|define
name|IXGBE_MDFTC2
value|0x042C0
end_define

begin_define
define|#
directive|define
name|IXGBE_MDFTFIFO1
value|0x042C4
end_define

begin_define
define|#
directive|define
name|IXGBE_MDFTFIFO2
value|0x042C8
end_define

begin_define
define|#
directive|define
name|IXGBE_MDFTS
value|0x042CC
end_define

begin_define
define|#
directive|define
name|IXGBE_RXDATAWRPTR
parameter_list|(
name|_i
parameter_list|)
value|(0x03700 + ((_i) * 4))
end_define

begin_comment
comment|/* 8 of these 3700-370C*/
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXDESCWRPTR
parameter_list|(
name|_i
parameter_list|)
value|(0x03710 + ((_i) * 4))
end_define

begin_comment
comment|/* 8 of these 3710-371C*/
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXDATARDPTR
parameter_list|(
name|_i
parameter_list|)
value|(0x03720 + ((_i) * 4))
end_define

begin_comment
comment|/* 8 of these 3720-372C*/
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXDESCRDPTR
parameter_list|(
name|_i
parameter_list|)
value|(0x03730 + ((_i) * 4))
end_define

begin_comment
comment|/* 8 of these 3730-373C*/
end_comment

begin_define
define|#
directive|define
name|IXGBE_TXDATAWRPTR
parameter_list|(
name|_i
parameter_list|)
value|(0x0C700 + ((_i) * 4))
end_define

begin_comment
comment|/* 8 of these C700-C70C*/
end_comment

begin_define
define|#
directive|define
name|IXGBE_TXDESCWRPTR
parameter_list|(
name|_i
parameter_list|)
value|(0x0C710 + ((_i) * 4))
end_define

begin_comment
comment|/* 8 of these C710-C71C*/
end_comment

begin_define
define|#
directive|define
name|IXGBE_TXDATARDPTR
parameter_list|(
name|_i
parameter_list|)
value|(0x0C720 + ((_i) * 4))
end_define

begin_comment
comment|/* 8 of these C720-C72C*/
end_comment

begin_define
define|#
directive|define
name|IXGBE_TXDESCRDPTR
parameter_list|(
name|_i
parameter_list|)
value|(0x0C730 + ((_i) * 4))
end_define

begin_comment
comment|/* 8 of these C730-C73C*/
end_comment

begin_define
define|#
directive|define
name|IXGBE_PCIEECCCTL
value|0x1106C
end_define

begin_define
define|#
directive|define
name|IXGBE_RXWRPTR
parameter_list|(
name|_i
parameter_list|)
value|(0x03100 + ((_i) * 4))
end_define

begin_comment
comment|/* 8 of these 3100-310C*/
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXUSED
parameter_list|(
name|_i
parameter_list|)
value|(0x03120 + ((_i) * 4))
end_define

begin_comment
comment|/* 8 of these 3120-312C*/
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXRDPTR
parameter_list|(
name|_i
parameter_list|)
value|(0x03140 + ((_i) * 4))
end_define

begin_comment
comment|/* 8 of these 3140-314C*/
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXRDWRPTR
parameter_list|(
name|_i
parameter_list|)
value|(0x03160 + ((_i) * 4))
end_define

begin_comment
comment|/* 8 of these 3160-310C*/
end_comment

begin_define
define|#
directive|define
name|IXGBE_TXWRPTR
parameter_list|(
name|_i
parameter_list|)
value|(0x0C100 + ((_i) * 4))
end_define

begin_comment
comment|/* 8 of these C100-C10C*/
end_comment

begin_define
define|#
directive|define
name|IXGBE_TXUSED
parameter_list|(
name|_i
parameter_list|)
value|(0x0C120 + ((_i) * 4))
end_define

begin_comment
comment|/* 8 of these C120-C12C*/
end_comment

begin_define
define|#
directive|define
name|IXGBE_TXRDPTR
parameter_list|(
name|_i
parameter_list|)
value|(0x0C140 + ((_i) * 4))
end_define

begin_comment
comment|/* 8 of these C140-C14C*/
end_comment

begin_define
define|#
directive|define
name|IXGBE_TXRDWRPTR
parameter_list|(
name|_i
parameter_list|)
value|(0x0C160 + ((_i) * 4))
end_define

begin_comment
comment|/* 8 of these C160-C10C*/
end_comment

begin_define
define|#
directive|define
name|IXGBE_PCIEECCCTL0
value|0x11100
end_define

begin_define
define|#
directive|define
name|IXGBE_PCIEECCCTL1
value|0x11104
end_define

begin_define
define|#
directive|define
name|IXGBE_RXDBUECC
value|0x03F70
end_define

begin_define
define|#
directive|define
name|IXGBE_TXDBUECC
value|0x0CF70
end_define

begin_define
define|#
directive|define
name|IXGBE_RXDBUEST
value|0x03F74
end_define

begin_define
define|#
directive|define
name|IXGBE_TXDBUEST
value|0x0CF74
end_define

begin_define
define|#
directive|define
name|IXGBE_PBTXECC
value|0x0C300
end_define

begin_define
define|#
directive|define
name|IXGBE_PBRXECC
value|0x03300
end_define

begin_define
define|#
directive|define
name|IXGBE_GHECCR
value|0x110B0
end_define

begin_comment
comment|/* MAC Registers */
end_comment

begin_define
define|#
directive|define
name|IXGBE_PCS1GCFIG
value|0x04200
end_define

begin_define
define|#
directive|define
name|IXGBE_PCS1GLCTL
value|0x04208
end_define

begin_define
define|#
directive|define
name|IXGBE_PCS1GLSTA
value|0x0420C
end_define

begin_define
define|#
directive|define
name|IXGBE_PCS1GDBG0
value|0x04210
end_define

begin_define
define|#
directive|define
name|IXGBE_PCS1GDBG1
value|0x04214
end_define

begin_define
define|#
directive|define
name|IXGBE_PCS1GANA
value|0x04218
end_define

begin_define
define|#
directive|define
name|IXGBE_PCS1GANLP
value|0x0421C
end_define

begin_define
define|#
directive|define
name|IXGBE_PCS1GANNP
value|0x04220
end_define

begin_define
define|#
directive|define
name|IXGBE_PCS1GANLPNP
value|0x04224
end_define

begin_define
define|#
directive|define
name|IXGBE_HLREG0
value|0x04240
end_define

begin_define
define|#
directive|define
name|IXGBE_HLREG1
value|0x04244
end_define

begin_define
define|#
directive|define
name|IXGBE_PAP
value|0x04248
end_define

begin_define
define|#
directive|define
name|IXGBE_MACA
value|0x0424C
end_define

begin_define
define|#
directive|define
name|IXGBE_APAE
value|0x04250
end_define

begin_define
define|#
directive|define
name|IXGBE_ARD
value|0x04254
end_define

begin_define
define|#
directive|define
name|IXGBE_AIS
value|0x04258
end_define

begin_define
define|#
directive|define
name|IXGBE_MSCA
value|0x0425C
end_define

begin_define
define|#
directive|define
name|IXGBE_MSRWD
value|0x04260
end_define

begin_define
define|#
directive|define
name|IXGBE_MLADD
value|0x04264
end_define

begin_define
define|#
directive|define
name|IXGBE_MHADD
value|0x04268
end_define

begin_define
define|#
directive|define
name|IXGBE_MAXFRS
value|0x04268
end_define

begin_define
define|#
directive|define
name|IXGBE_TREG
value|0x0426C
end_define

begin_define
define|#
directive|define
name|IXGBE_PCSS1
value|0x04288
end_define

begin_define
define|#
directive|define
name|IXGBE_PCSS2
value|0x0428C
end_define

begin_define
define|#
directive|define
name|IXGBE_XPCSS
value|0x04290
end_define

begin_define
define|#
directive|define
name|IXGBE_MFLCN
value|0x04294
end_define

begin_define
define|#
directive|define
name|IXGBE_SERDESC
value|0x04298
end_define

begin_define
define|#
directive|define
name|IXGBE_MAC_SGMII_BUSY
value|0x04298
end_define

begin_define
define|#
directive|define
name|IXGBE_MACS
value|0x0429C
end_define

begin_define
define|#
directive|define
name|IXGBE_AUTOC
value|0x042A0
end_define

begin_define
define|#
directive|define
name|IXGBE_LINKS
value|0x042A4
end_define

begin_define
define|#
directive|define
name|IXGBE_LINKS2
value|0x04324
end_define

begin_define
define|#
directive|define
name|IXGBE_AUTOC2
value|0x042A8
end_define

begin_define
define|#
directive|define
name|IXGBE_AUTOC3
value|0x042AC
end_define

begin_define
define|#
directive|define
name|IXGBE_ANLP1
value|0x042B0
end_define

begin_define
define|#
directive|define
name|IXGBE_ANLP2
value|0x042B4
end_define

begin_define
define|#
directive|define
name|IXGBE_MACC
value|0x04330
end_define

begin_define
define|#
directive|define
name|IXGBE_ATLASCTL
value|0x04800
end_define

begin_define
define|#
directive|define
name|IXGBE_MMNGC
value|0x042D0
end_define

begin_define
define|#
directive|define
name|IXGBE_ANLPNP1
value|0x042D4
end_define

begin_define
define|#
directive|define
name|IXGBE_ANLPNP2
value|0x042D8
end_define

begin_define
define|#
directive|define
name|IXGBE_KRPCSFC
value|0x042E0
end_define

begin_define
define|#
directive|define
name|IXGBE_KRPCSS
value|0x042E4
end_define

begin_define
define|#
directive|define
name|IXGBE_FECS1
value|0x042E8
end_define

begin_define
define|#
directive|define
name|IXGBE_FECS2
value|0x042EC
end_define

begin_define
define|#
directive|define
name|IXGBE_SMADARCTL
value|0x14F10
end_define

begin_define
define|#
directive|define
name|IXGBE_MPVC
value|0x04318
end_define

begin_define
define|#
directive|define
name|IXGBE_SGMIIC
value|0x04314
end_define

begin_comment
comment|/* Statistics Registers */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXNFGPC
value|0x041B0
end_define

begin_define
define|#
directive|define
name|IXGBE_RXNFGBCL
value|0x041B4
end_define

begin_define
define|#
directive|define
name|IXGBE_RXNFGBCH
value|0x041B8
end_define

begin_define
define|#
directive|define
name|IXGBE_RXDGPC
value|0x02F50
end_define

begin_define
define|#
directive|define
name|IXGBE_RXDGBCL
value|0x02F54
end_define

begin_define
define|#
directive|define
name|IXGBE_RXDGBCH
value|0x02F58
end_define

begin_define
define|#
directive|define
name|IXGBE_RXDDGPC
value|0x02F5C
end_define

begin_define
define|#
directive|define
name|IXGBE_RXDDGBCL
value|0x02F60
end_define

begin_define
define|#
directive|define
name|IXGBE_RXDDGBCH
value|0x02F64
end_define

begin_define
define|#
directive|define
name|IXGBE_RXLPBKGPC
value|0x02F68
end_define

begin_define
define|#
directive|define
name|IXGBE_RXLPBKGBCL
value|0x02F6C
end_define

begin_define
define|#
directive|define
name|IXGBE_RXLPBKGBCH
value|0x02F70
end_define

begin_define
define|#
directive|define
name|IXGBE_RXDLPBKGPC
value|0x02F74
end_define

begin_define
define|#
directive|define
name|IXGBE_RXDLPBKGBCL
value|0x02F78
end_define

begin_define
define|#
directive|define
name|IXGBE_RXDLPBKGBCH
value|0x02F7C
end_define

begin_define
define|#
directive|define
name|IXGBE_TXDGPC
value|0x087A0
end_define

begin_define
define|#
directive|define
name|IXGBE_TXDGBCL
value|0x087A4
end_define

begin_define
define|#
directive|define
name|IXGBE_TXDGBCH
value|0x087A8
end_define

begin_define
define|#
directive|define
name|IXGBE_RXDSTATCTRL
value|0x02F40
end_define

begin_comment
comment|/* Copper Pond 2 link timeout */
end_comment

begin_define
define|#
directive|define
name|IXGBE_VALIDATE_LINK_READY_TIMEOUT
value|50
end_define

begin_comment
comment|/* Omer CORECTL */
end_comment

begin_define
define|#
directive|define
name|IXGBE_CORECTL
value|0x014F00
end_define

begin_comment
comment|/* BARCTRL */
end_comment

begin_define
define|#
directive|define
name|IXGBE_BARCTRL
value|0x110F4
end_define

begin_define
define|#
directive|define
name|IXGBE_BARCTRL_FLSIZE
value|0x0700
end_define

begin_define
define|#
directive|define
name|IXGBE_BARCTRL_FLSIZE_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|IXGBE_BARCTRL_CSRSIZE
value|0x2000
end_define

begin_comment
comment|/* RSCCTL Bit Masks */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RSCCTL_RSCEN
value|0x01
end_define

begin_define
define|#
directive|define
name|IXGBE_RSCCTL_MAXDESC_1
value|0x00
end_define

begin_define
define|#
directive|define
name|IXGBE_RSCCTL_MAXDESC_4
value|0x04
end_define

begin_define
define|#
directive|define
name|IXGBE_RSCCTL_MAXDESC_8
value|0x08
end_define

begin_define
define|#
directive|define
name|IXGBE_RSCCTL_MAXDESC_16
value|0x0C
end_define

begin_define
define|#
directive|define
name|IXGBE_RSCCTL_TS_DIS
value|0x02
end_define

begin_comment
comment|/* RSCDBU Bit Masks */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RSCDBU_RSCSMALDIS_MASK
value|0x0000007F
end_define

begin_define
define|#
directive|define
name|IXGBE_RSCDBU_RSCACKDIS
value|0x00000080
end_define

begin_comment
comment|/* RDRXCTL Bit Masks */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RDRXCTL_RDMTS_1_2
value|0x00000000
end_define

begin_comment
comment|/* Rx Desc Min THLD Size */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RDRXCTL_CRCSTRIP
value|0x00000002
end_define

begin_comment
comment|/* CRC Strip */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RDRXCTL_PSP
value|0x00000004
end_define

begin_comment
comment|/* Pad Small Packet */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RDRXCTL_MVMEN
value|0x00000020
end_define

begin_define
define|#
directive|define
name|IXGBE_RDRXCTL_RSC_PUSH_DIS
value|0x00000020
end_define

begin_define
define|#
directive|define
name|IXGBE_RDRXCTL_DMAIDONE
value|0x00000008
end_define

begin_comment
comment|/* DMA init cycle done */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RDRXCTL_RSC_PUSH
value|0x00000080
end_define

begin_define
define|#
directive|define
name|IXGBE_RDRXCTL_AGGDIS
value|0x00010000
end_define

begin_comment
comment|/* Aggregation disable */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RDRXCTL_RSCFRSTSIZE
value|0x003E0000
end_define

begin_comment
comment|/* RSC First packet size */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RDRXCTL_RSCLLIDIS
value|0x00800000
end_define

begin_comment
comment|/* Disable RSC compl on LLI*/
end_comment

begin_define
define|#
directive|define
name|IXGBE_RDRXCTL_RSCACKC
value|0x02000000
end_define

begin_comment
comment|/* must set 1 when RSC ena */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RDRXCTL_FCOE_WRFIX
value|0x04000000
end_define

begin_comment
comment|/* must set 1 when RSC ena */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RDRXCTL_MBINTEN
value|0x10000000
end_define

begin_define
define|#
directive|define
name|IXGBE_RDRXCTL_MDP_EN
value|0x20000000
end_define

begin_comment
comment|/* RQTC Bit Masks and Shifts */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RQTC_SHIFT_TC
parameter_list|(
name|_i
parameter_list|)
value|((_i) * 4)
end_define

begin_define
define|#
directive|define
name|IXGBE_RQTC_TC0_MASK
value|(0x7<< 0)
end_define

begin_define
define|#
directive|define
name|IXGBE_RQTC_TC1_MASK
value|(0x7<< 4)
end_define

begin_define
define|#
directive|define
name|IXGBE_RQTC_TC2_MASK
value|(0x7<< 8)
end_define

begin_define
define|#
directive|define
name|IXGBE_RQTC_TC3_MASK
value|(0x7<< 12)
end_define

begin_define
define|#
directive|define
name|IXGBE_RQTC_TC4_MASK
value|(0x7<< 16)
end_define

begin_define
define|#
directive|define
name|IXGBE_RQTC_TC5_MASK
value|(0x7<< 20)
end_define

begin_define
define|#
directive|define
name|IXGBE_RQTC_TC6_MASK
value|(0x7<< 24)
end_define

begin_define
define|#
directive|define
name|IXGBE_RQTC_TC7_MASK
value|(0x7<< 28)
end_define

begin_comment
comment|/* PSRTYPE.RQPL Bit masks and shift */
end_comment

begin_define
define|#
directive|define
name|IXGBE_PSRTYPE_RQPL_MASK
value|0x7
end_define

begin_define
define|#
directive|define
name|IXGBE_PSRTYPE_RQPL_SHIFT
value|29
end_define

begin_comment
comment|/* CTRL Bit Masks */
end_comment

begin_define
define|#
directive|define
name|IXGBE_CTRL_GIO_DIS
value|0x00000004
end_define

begin_comment
comment|/* Global IO Master Disable bit */
end_comment

begin_define
define|#
directive|define
name|IXGBE_CTRL_LNK_RST
value|0x00000008
end_define

begin_comment
comment|/* Link Reset. Resets everything. */
end_comment

begin_define
define|#
directive|define
name|IXGBE_CTRL_RST
value|0x04000000
end_define

begin_comment
comment|/* Reset (SW) */
end_comment

begin_define
define|#
directive|define
name|IXGBE_CTRL_RST_MASK
value|(IXGBE_CTRL_LNK_RST | IXGBE_CTRL_RST)
end_define

begin_comment
comment|/* FACTPS */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FACTPS_MNGCG
value|0x20000000
end_define

begin_comment
comment|/* Manageblility Clock Gated */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FACTPS_LFS
value|0x40000000
end_define

begin_comment
comment|/* LAN Function Select */
end_comment

begin_comment
comment|/* MHADD Bit Masks */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MHADD_MFS_MASK
value|0xFFFF0000
end_define

begin_define
define|#
directive|define
name|IXGBE_MHADD_MFS_SHIFT
value|16
end_define

begin_comment
comment|/* Extended Device Control */
end_comment

begin_define
define|#
directive|define
name|IXGBE_CTRL_EXT_PFRSTD
value|0x00004000
end_define

begin_comment
comment|/* Physical Function Reset Done */
end_comment

begin_define
define|#
directive|define
name|IXGBE_CTRL_EXT_NS_DIS
value|0x00010000
end_define

begin_comment
comment|/* No Snoop disable */
end_comment

begin_define
define|#
directive|define
name|IXGBE_CTRL_EXT_RO_DIS
value|0x00020000
end_define

begin_comment
comment|/* Relaxed Ordering disable */
end_comment

begin_define
define|#
directive|define
name|IXGBE_CTRL_EXT_DRV_LOAD
value|0x10000000
end_define

begin_comment
comment|/* Driver loaded bit for FW */
end_comment

begin_comment
comment|/* Direct Cache Access (DCA) definitions */
end_comment

begin_define
define|#
directive|define
name|IXGBE_DCA_CTRL_DCA_ENABLE
value|0x00000000
end_define

begin_comment
comment|/* DCA Enable */
end_comment

begin_define
define|#
directive|define
name|IXGBE_DCA_CTRL_DCA_DISABLE
value|0x00000001
end_define

begin_comment
comment|/* DCA Disable */
end_comment

begin_define
define|#
directive|define
name|IXGBE_DCA_CTRL_DCA_MODE_CB1
value|0x00
end_define

begin_comment
comment|/* DCA Mode CB1 */
end_comment

begin_define
define|#
directive|define
name|IXGBE_DCA_CTRL_DCA_MODE_CB2
value|0x02
end_define

begin_comment
comment|/* DCA Mode CB2 */
end_comment

begin_define
define|#
directive|define
name|IXGBE_DCA_RXCTRL_CPUID_MASK
value|0x0000001F
end_define

begin_comment
comment|/* Rx CPUID Mask */
end_comment

begin_define
define|#
directive|define
name|IXGBE_DCA_RXCTRL_CPUID_MASK_82599
value|0xFF000000
end_define

begin_comment
comment|/* Rx CPUID Mask */
end_comment

begin_define
define|#
directive|define
name|IXGBE_DCA_RXCTRL_CPUID_SHIFT_82599
value|24
end_define

begin_comment
comment|/* Rx CPUID Shift */
end_comment

begin_define
define|#
directive|define
name|IXGBE_DCA_RXCTRL_DESC_DCA_EN
value|(1<< 5)
end_define

begin_comment
comment|/* Rx Desc enable */
end_comment

begin_define
define|#
directive|define
name|IXGBE_DCA_RXCTRL_HEAD_DCA_EN
value|(1<< 6)
end_define

begin_comment
comment|/* Rx Desc header ena */
end_comment

begin_define
define|#
directive|define
name|IXGBE_DCA_RXCTRL_DATA_DCA_EN
value|(1<< 7)
end_define

begin_comment
comment|/* Rx Desc payload ena */
end_comment

begin_define
define|#
directive|define
name|IXGBE_DCA_RXCTRL_DESC_RRO_EN
value|(1<< 9)
end_define

begin_comment
comment|/* Rx rd Desc Relax Order */
end_comment

begin_define
define|#
directive|define
name|IXGBE_DCA_RXCTRL_DATA_WRO_EN
value|(1<< 13)
end_define

begin_comment
comment|/* Rx wr data Relax Order */
end_comment

begin_define
define|#
directive|define
name|IXGBE_DCA_RXCTRL_HEAD_WRO_EN
value|(1<< 15)
end_define

begin_comment
comment|/* Rx wr header RO */
end_comment

begin_define
define|#
directive|define
name|IXGBE_DCA_TXCTRL_CPUID_MASK
value|0x0000001F
end_define

begin_comment
comment|/* Tx CPUID Mask */
end_comment

begin_define
define|#
directive|define
name|IXGBE_DCA_TXCTRL_CPUID_MASK_82599
value|0xFF000000
end_define

begin_comment
comment|/* Tx CPUID Mask */
end_comment

begin_define
define|#
directive|define
name|IXGBE_DCA_TXCTRL_CPUID_SHIFT_82599
value|24
end_define

begin_comment
comment|/* Tx CPUID Shift */
end_comment

begin_define
define|#
directive|define
name|IXGBE_DCA_TXCTRL_DESC_DCA_EN
value|(1<< 5)
end_define

begin_comment
comment|/* DCA Tx Desc enable */
end_comment

begin_define
define|#
directive|define
name|IXGBE_DCA_TXCTRL_DESC_RRO_EN
value|(1<< 9)
end_define

begin_comment
comment|/* Tx rd Desc Relax Order */
end_comment

begin_define
define|#
directive|define
name|IXGBE_DCA_TXCTRL_DESC_WRO_EN
value|(1<< 11)
end_define

begin_comment
comment|/* Tx Desc writeback RO bit */
end_comment

begin_define
define|#
directive|define
name|IXGBE_DCA_TXCTRL_DATA_RRO_EN
value|(1<< 13)
end_define

begin_comment
comment|/* Tx rd data Relax Order */
end_comment

begin_define
define|#
directive|define
name|IXGBE_DCA_MAX_QUEUES_82598
value|16
end_define

begin_comment
comment|/* DCA regs only on 16 queues */
end_comment

begin_comment
comment|/* MSCA Bit Masks */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MSCA_NP_ADDR_MASK
value|0x0000FFFF
end_define

begin_comment
comment|/* MDI Addr (new prot) */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MSCA_NP_ADDR_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|IXGBE_MSCA_DEV_TYPE_MASK
value|0x001F0000
end_define

begin_comment
comment|/* Dev Type (new prot) */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MSCA_DEV_TYPE_SHIFT
value|16
end_define

begin_comment
comment|/* Register Address (old prot */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MSCA_PHY_ADDR_MASK
value|0x03E00000
end_define

begin_comment
comment|/* PHY Address mask */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MSCA_PHY_ADDR_SHIFT
value|21
end_define

begin_comment
comment|/* PHY Address shift*/
end_comment

begin_define
define|#
directive|define
name|IXGBE_MSCA_OP_CODE_MASK
value|0x0C000000
end_define

begin_comment
comment|/* OP CODE mask */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MSCA_OP_CODE_SHIFT
value|26
end_define

begin_comment
comment|/* OP CODE shift */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MSCA_ADDR_CYCLE
value|0x00000000
end_define

begin_comment
comment|/* OP CODE 00 (addr cycle) */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MSCA_WRITE
value|0x04000000
end_define

begin_comment
comment|/* OP CODE 01 (wr) */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MSCA_READ
value|0x0C000000
end_define

begin_comment
comment|/* OP CODE 11 (rd) */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MSCA_READ_AUTOINC
value|0x08000000
end_define

begin_comment
comment|/* OP CODE 10 (rd auto inc)*/
end_comment

begin_define
define|#
directive|define
name|IXGBE_MSCA_ST_CODE_MASK
value|0x30000000
end_define

begin_comment
comment|/* ST Code mask */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MSCA_ST_CODE_SHIFT
value|28
end_define

begin_comment
comment|/* ST Code shift */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MSCA_NEW_PROTOCOL
value|0x00000000
end_define

begin_comment
comment|/* ST CODE 00 (new prot) */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MSCA_OLD_PROTOCOL
value|0x10000000
end_define

begin_comment
comment|/* ST CODE 01 (old prot) */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MSCA_MDI_COMMAND
value|0x40000000
end_define

begin_comment
comment|/* Initiate MDI command */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MSCA_MDI_IN_PROG_EN
value|0x80000000
end_define

begin_comment
comment|/* MDI in progress ena */
end_comment

begin_comment
comment|/* MSRWD bit masks */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MSRWD_WRITE_DATA_MASK
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|IXGBE_MSRWD_WRITE_DATA_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|IXGBE_MSRWD_READ_DATA_MASK
value|0xFFFF0000
end_define

begin_define
define|#
directive|define
name|IXGBE_MSRWD_READ_DATA_SHIFT
value|16
end_define

begin_comment
comment|/* Atlas registers */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ATLAS_PDN_LPBK
value|0x24
end_define

begin_define
define|#
directive|define
name|IXGBE_ATLAS_PDN_10G
value|0xB
end_define

begin_define
define|#
directive|define
name|IXGBE_ATLAS_PDN_1G
value|0xC
end_define

begin_define
define|#
directive|define
name|IXGBE_ATLAS_PDN_AN
value|0xD
end_define

begin_comment
comment|/* Atlas bit masks */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ATLASCTL_WRITE_CMD
value|0x00010000
end_define

begin_define
define|#
directive|define
name|IXGBE_ATLAS_PDN_TX_REG_EN
value|0x10
end_define

begin_define
define|#
directive|define
name|IXGBE_ATLAS_PDN_TX_10G_QL_ALL
value|0xF0
end_define

begin_define
define|#
directive|define
name|IXGBE_ATLAS_PDN_TX_1G_QL_ALL
value|0xF0
end_define

begin_define
define|#
directive|define
name|IXGBE_ATLAS_PDN_TX_AN_QL_ALL
value|0xF0
end_define

begin_comment
comment|/* Omer bit masks */
end_comment

begin_define
define|#
directive|define
name|IXGBE_CORECTL_WRITE_CMD
value|0x00010000
end_define

begin_comment
comment|/* Device Type definitions for new protocol MDIO commands */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MDIO_ZERO_DEV_TYPE
value|0x0
end_define

begin_define
define|#
directive|define
name|IXGBE_MDIO_PMA_PMD_DEV_TYPE
value|0x1
end_define

begin_define
define|#
directive|define
name|IXGBE_MDIO_PCS_DEV_TYPE
value|0x3
end_define

begin_define
define|#
directive|define
name|IXGBE_MDIO_PHY_XS_DEV_TYPE
value|0x4
end_define

begin_define
define|#
directive|define
name|IXGBE_MDIO_AUTO_NEG_DEV_TYPE
value|0x7
end_define

begin_define
define|#
directive|define
name|IXGBE_MDIO_VENDOR_SPECIFIC_1_DEV_TYPE
value|0x1E
end_define

begin_comment
comment|/* Device 30 */
end_comment

begin_define
define|#
directive|define
name|IXGBE_TWINAX_DEV
value|1
end_define

begin_define
define|#
directive|define
name|IXGBE_MDIO_COMMAND_TIMEOUT
value|100
end_define

begin_comment
comment|/* PHY Timeout for 1 GB mode */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MDIO_VENDOR_SPECIFIC_1_CONTROL
value|0x0
end_define

begin_comment
comment|/* VS1 Ctrl Reg */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MDIO_VENDOR_SPECIFIC_1_STATUS
value|0x1
end_define

begin_comment
comment|/* VS1 Status Reg */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MDIO_VENDOR_SPECIFIC_1_LINK_STATUS
value|0x0008
end_define

begin_comment
comment|/* 1 = Link Up */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MDIO_VENDOR_SPECIFIC_1_SPEED_STATUS
value|0x0010
end_define

begin_comment
comment|/* 0-10G, 1-1G */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MDIO_VENDOR_SPECIFIC_1_10G_SPEED
value|0x0018
end_define

begin_define
define|#
directive|define
name|IXGBE_MDIO_VENDOR_SPECIFIC_1_1G_SPEED
value|0x0010
end_define

begin_define
define|#
directive|define
name|IXGBE_MDIO_AUTO_NEG_CONTROL
value|0x0
end_define

begin_comment
comment|/* AUTO_NEG Control Reg */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MDIO_AUTO_NEG_STATUS
value|0x1
end_define

begin_comment
comment|/* AUTO_NEG Status Reg */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MDIO_AUTO_NEG_VENDOR_STAT
value|0xC800
end_define

begin_comment
comment|/* AUTO_NEG Vendor Status Reg */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MDIO_AUTO_NEG_VENDOR_TX_ALARM
value|0xCC00
end_define

begin_comment
comment|/* AUTO_NEG Vendor TX Reg */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MDIO_AUTO_NEG_VENDOR_TX_ALARM2
value|0xCC01
end_define

begin_comment
comment|/* AUTO_NEG Vendor Tx Reg */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MDIO_AUTO_NEG_VEN_LSC
value|0x1
end_define

begin_comment
comment|/* AUTO_NEG Vendor Tx LSC */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MDIO_AUTO_NEG_ADVT
value|0x10
end_define

begin_comment
comment|/* AUTO_NEG Advt Reg */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MDIO_AUTO_NEG_LP
value|0x13
end_define

begin_comment
comment|/* AUTO_NEG LP Status Reg */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MDIO_AUTO_NEG_EEE_ADVT
value|0x3C
end_define

begin_comment
comment|/* AUTO_NEG EEE Advt Reg */
end_comment

begin_define
define|#
directive|define
name|IXGBE_AUTO_NEG_10GBASE_EEE_ADVT
value|0x8
end_define

begin_comment
comment|/* AUTO NEG EEE 10GBaseT Advt */
end_comment

begin_define
define|#
directive|define
name|IXGBE_AUTO_NEG_1000BASE_EEE_ADVT
value|0x4
end_define

begin_comment
comment|/* AUTO NEG EEE 1000BaseT Advt */
end_comment

begin_define
define|#
directive|define
name|IXGBE_AUTO_NEG_100BASE_EEE_ADVT
value|0x2
end_define

begin_comment
comment|/* AUTO NEG EEE 100BaseT Advt */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MDIO_PHY_XS_CONTROL
value|0x0
end_define

begin_comment
comment|/* PHY_XS Control Reg */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MDIO_PHY_XS_RESET
value|0x8000
end_define

begin_comment
comment|/* PHY_XS Reset */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MDIO_PHY_ID_HIGH
value|0x2
end_define

begin_comment
comment|/* PHY ID High Reg*/
end_comment

begin_define
define|#
directive|define
name|IXGBE_MDIO_PHY_ID_LOW
value|0x3
end_define

begin_comment
comment|/* PHY ID Low Reg*/
end_comment

begin_define
define|#
directive|define
name|IXGBE_MDIO_PHY_SPEED_ABILITY
value|0x4
end_define

begin_comment
comment|/* Speed Ability Reg */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MDIO_PHY_SPEED_10G
value|0x0001
end_define

begin_comment
comment|/* 10G capable */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MDIO_PHY_SPEED_1G
value|0x0010
end_define

begin_comment
comment|/* 1G capable */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MDIO_PHY_SPEED_100M
value|0x0020
end_define

begin_comment
comment|/* 100M capable */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MDIO_PHY_EXT_ABILITY
value|0xB
end_define

begin_comment
comment|/* Ext Ability Reg */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MDIO_PHY_10GBASET_ABILITY
value|0x0004
end_define

begin_comment
comment|/* 10GBaseT capable */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MDIO_PHY_1000BASET_ABILITY
value|0x0020
end_define

begin_comment
comment|/* 1000BaseT capable */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MDIO_PHY_100BASETX_ABILITY
value|0x0080
end_define

begin_comment
comment|/* 100BaseTX capable */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MDIO_PHY_SET_LOW_POWER_MODE
value|0x0800
end_define

begin_comment
comment|/* Set low power mode */
end_comment

begin_define
define|#
directive|define
name|IXGBE_AUTO_NEG_LP_STATUS
value|0xE820
end_define

begin_comment
comment|/* AUTO NEG Rx LP Status Reg */
end_comment

begin_define
define|#
directive|define
name|IXGBE_AUTO_NEG_LP_1000BASE_CAP
value|0x8000
end_define

begin_comment
comment|/* AUTO NEG Rx LP 1000BaseT Cap */
end_comment

begin_define
define|#
directive|define
name|IXGBE_AUTO_NEG_LP_10GBASE_CAP
value|0x0800
end_define

begin_comment
comment|/* AUTO NEG Rx LP 10GBaseT Cap */
end_comment

begin_define
define|#
directive|define
name|IXGBE_AUTO_NEG_10GBASET_STAT
value|0x0021
end_define

begin_comment
comment|/* AUTO NEG 10G BaseT Stat */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MDIO_TX_VENDOR_ALARMS_3
value|0xCC02
end_define

begin_comment
comment|/* Vendor Alarms 3 Reg */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MDIO_TX_VENDOR_ALARMS_3_RST_MASK
value|0x3
end_define

begin_comment
comment|/* PHY Reset Complete Mask */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MDIO_GLOBAL_RES_PR_10
value|0xC479
end_define

begin_comment
comment|/* Global Resv Provisioning 10 Reg */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MDIO_POWER_UP_STALL
value|0x8000
end_define

begin_comment
comment|/* Power Up Stall */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MDIO_GLOBAL_INT_CHIP_STD_MASK
value|0xFF00
end_define

begin_comment
comment|/* int std mask */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MDIO_GLOBAL_CHIP_STD_INT_FLAG
value|0xFC00
end_define

begin_comment
comment|/* chip std int flag */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MDIO_GLOBAL_INT_CHIP_VEN_MASK
value|0xFF01
end_define

begin_comment
comment|/* int chip-wide mask */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MDIO_GLOBAL_INT_CHIP_VEN_FLAG
value|0xFC01
end_define

begin_comment
comment|/* int chip-wide mask */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MDIO_GLOBAL_ALARM_1
value|0xCC00
end_define

begin_comment
comment|/* Global alarm 1 */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MDIO_GLOBAL_ALM_1_DEV_FAULT
value|0x0010
end_define

begin_comment
comment|/* device fault */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MDIO_GLOBAL_ALM_1_HI_TMP_FAIL
value|0x4000
end_define

begin_comment
comment|/* high temp failure */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MDIO_GLOBAL_FAULT_MSG
value|0xC850
end_define

begin_comment
comment|/* Global Fault Message */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MDIO_GLOBAL_FAULT_MSG_HI_TMP
value|0x8007
end_define

begin_comment
comment|/* high temp failure */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MDIO_GLOBAL_INT_MASK
value|0xD400
end_define

begin_comment
comment|/* Global int mask */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MDIO_GLOBAL_AN_VEN_ALM_INT_EN
value|0x1000
end_define

begin_comment
comment|/* autoneg vendor alarm int enable */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MDIO_GLOBAL_ALARM_1_INT
value|0x4
end_define

begin_comment
comment|/* int in Global alarm 1 */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MDIO_GLOBAL_VEN_ALM_INT_EN
value|0x1
end_define

begin_comment
comment|/* vendor alarm int enable */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MDIO_GLOBAL_STD_ALM2_INT
value|0x200
end_define

begin_comment
comment|/* vendor alarm2 int mask */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MDIO_GLOBAL_INT_HI_TEMP_EN
value|0x4000
end_define

begin_comment
comment|/* int high temp enable */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MDIO_GLOBAL_INT_DEV_FAULT_EN
value|0x0010
end_define

begin_comment
comment|/* int dev fault enable */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MDIO_PMA_PMD_CONTROL_ADDR
value|0x0000
end_define

begin_comment
comment|/* PMA/PMD Control Reg */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MDIO_PMA_PMD_SDA_SCL_ADDR
value|0xC30A
end_define

begin_comment
comment|/* PHY_XS SDA/SCL Addr Reg */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MDIO_PMA_PMD_SDA_SCL_DATA
value|0xC30B
end_define

begin_comment
comment|/* PHY_XS SDA/SCL Data Reg */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MDIO_PMA_PMD_SDA_SCL_STAT
value|0xC30C
end_define

begin_comment
comment|/* PHY_XS SDA/SCL Status Reg */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MDIO_PMA_TX_VEN_LASI_INT_MASK
value|0xD401
end_define

begin_comment
comment|/* PHY TX Vendor LASI */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MDIO_PMA_TX_VEN_LASI_INT_EN
value|0x1
end_define

begin_comment
comment|/* PHY TX Vendor LASI enable */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MDIO_PMD_STD_TX_DISABLE_CNTR
value|0x9
end_define

begin_comment
comment|/* Standard Transmit Dis Reg */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MDIO_PMD_GLOBAL_TX_DISABLE
value|0x0001
end_define

begin_comment
comment|/* PMD Global Transmit Dis */
end_comment

begin_define
define|#
directive|define
name|IXGBE_PCRC8ECL
value|0x0E810
end_define

begin_comment
comment|/* PCR CRC-8 Error Count Lo */
end_comment

begin_define
define|#
directive|define
name|IXGBE_PCRC8ECH
value|0x0E811
end_define

begin_comment
comment|/* PCR CRC-8 Error Count Hi */
end_comment

begin_define
define|#
directive|define
name|IXGBE_PCRC8ECH_MASK
value|0x1F
end_define

begin_define
define|#
directive|define
name|IXGBE_LDPCECL
value|0x0E820
end_define

begin_comment
comment|/* PCR Uncorrected Error Count Lo */
end_comment

begin_define
define|#
directive|define
name|IXGBE_LDPCECH
value|0x0E821
end_define

begin_comment
comment|/* PCR Uncorrected Error Count Hi */
end_comment

begin_comment
comment|/* MII clause 22/28 definitions */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MDIO_PHY_LOW_POWER_MODE
value|0x0800
end_define

begin_define
define|#
directive|define
name|IXGBE_MDIO_XENPAK_LASI_STATUS
value|0x9005
end_define

begin_comment
comment|/* XENPAK LASI Status register*/
end_comment

begin_define
define|#
directive|define
name|IXGBE_XENPAK_LASI_LINK_STATUS_ALARM
value|0x1
end_define

begin_comment
comment|/* Link Status Alarm change */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MDIO_AUTO_NEG_LINK_STATUS
value|0x4
end_define

begin_comment
comment|/* Indicates if link is up */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MDIO_AUTO_NEG_VENDOR_STATUS_MASK
value|0x7
end_define

begin_comment
comment|/* Speed/Duplex Mask */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MDIO_AUTO_NEG_VEN_STAT_SPEED_MASK
value|0x6
end_define

begin_comment
comment|/* Speed Mask */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MDIO_AUTO_NEG_VENDOR_STATUS_10M_HALF
value|0x0
end_define

begin_comment
comment|/* 10Mb/s Half Duplex */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MDIO_AUTO_NEG_VENDOR_STATUS_10M_FULL
value|0x1
end_define

begin_comment
comment|/* 10Mb/s Full Duplex */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MDIO_AUTO_NEG_VENDOR_STATUS_100M_HALF
value|0x2
end_define

begin_comment
comment|/* 100Mb/s Half Duplex */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MDIO_AUTO_NEG_VENDOR_STATUS_100M_FULL
value|0x3
end_define

begin_comment
comment|/* 100Mb/s Full Duplex */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MDIO_AUTO_NEG_VENDOR_STATUS_1GB_HALF
value|0x4
end_define

begin_comment
comment|/* 1Gb/s Half Duplex */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MDIO_AUTO_NEG_VENDOR_STATUS_1GB_FULL
value|0x5
end_define

begin_comment
comment|/* 1Gb/s Full Duplex */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MDIO_AUTO_NEG_VENDOR_STATUS_10GB_HALF
value|0x6
end_define

begin_comment
comment|/* 10Gb/s Half Duplex */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MDIO_AUTO_NEG_VENDOR_STATUS_10GB_FULL
value|0x7
end_define

begin_comment
comment|/* 10Gb/s Full Duplex */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MDIO_AUTO_NEG_VENDOR_STATUS_1GB
value|0x4
end_define

begin_comment
comment|/* 1Gb/s */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MDIO_AUTO_NEG_VENDOR_STATUS_10GB
value|0x6
end_define

begin_comment
comment|/* 10Gb/s */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MII_10GBASE_T_AUTONEG_CTRL_REG
value|0x20
end_define

begin_comment
comment|/* 10G Control Reg */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MII_AUTONEG_VENDOR_PROVISION_1_REG
value|0xC400
end_define

begin_comment
comment|/* 1G Provisioning 1 */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MII_AUTONEG_XNP_TX_REG
value|0x17
end_define

begin_comment
comment|/* 1G XNP Transmit */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MII_AUTONEG_ADVERTISE_REG
value|0x10
end_define

begin_comment
comment|/* 100M Advertisement */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MII_10GBASE_T_ADVERTISE
value|0x1000
end_define

begin_comment
comment|/* full duplex, bit:12*/
end_comment

begin_define
define|#
directive|define
name|IXGBE_MII_1GBASE_T_ADVERTISE_XNP_TX
value|0x4000
end_define

begin_comment
comment|/* full duplex, bit:14*/
end_comment

begin_define
define|#
directive|define
name|IXGBE_MII_1GBASE_T_ADVERTISE
value|0x8000
end_define

begin_comment
comment|/* full duplex, bit:15*/
end_comment

begin_define
define|#
directive|define
name|IXGBE_MII_2_5GBASE_T_ADVERTISE
value|0x0400
end_define

begin_define
define|#
directive|define
name|IXGBE_MII_5GBASE_T_ADVERTISE
value|0x0800
end_define

begin_define
define|#
directive|define
name|IXGBE_MII_100BASE_T_ADVERTISE
value|0x0100
end_define

begin_comment
comment|/* full duplex, bit:8 */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MII_100BASE_T_ADVERTISE_HALF
value|0x0080
end_define

begin_comment
comment|/* half duplex, bit:7 */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MII_RESTART
value|0x200
end_define

begin_define
define|#
directive|define
name|IXGBE_MII_AUTONEG_COMPLETE
value|0x20
end_define

begin_define
define|#
directive|define
name|IXGBE_MII_AUTONEG_LINK_UP
value|0x04
end_define

begin_define
define|#
directive|define
name|IXGBE_MII_AUTONEG_REG
value|0x0
end_define

begin_define
define|#
directive|define
name|IXGBE_PHY_REVISION_MASK
value|0xFFFFFFF0
end_define

begin_define
define|#
directive|define
name|IXGBE_MAX_PHY_ADDR
value|32
end_define

begin_comment
comment|/* PHY IDs*/
end_comment

begin_define
define|#
directive|define
name|TN1010_PHY_ID
value|0x00A19410
end_define

begin_define
define|#
directive|define
name|TNX_FW_REV
value|0xB
end_define

begin_define
define|#
directive|define
name|X540_PHY_ID
value|0x01540200
end_define

begin_define
define|#
directive|define
name|X550_PHY_ID2
value|0x01540223
end_define

begin_define
define|#
directive|define
name|X550_PHY_ID3
value|0x01540221
end_define

begin_define
define|#
directive|define
name|X557_PHY_ID
value|0x01540240
end_define

begin_define
define|#
directive|define
name|X557_PHY_ID2
value|0x01540250
end_define

begin_define
define|#
directive|define
name|AQ_FW_REV
value|0x20
end_define

begin_define
define|#
directive|define
name|QT2022_PHY_ID
value|0x0043A400
end_define

begin_define
define|#
directive|define
name|ATH_PHY_ID
value|0x03429050
end_define

begin_comment
comment|/* PHY Types */
end_comment

begin_define
define|#
directive|define
name|IXGBE_M88E1500_E_PHY_ID
value|0x01410DD0
end_define

begin_define
define|#
directive|define
name|IXGBE_M88E1543_E_PHY_ID
value|0x01410EA0
end_define

begin_comment
comment|/* Special PHY Init Routine */
end_comment

begin_define
define|#
directive|define
name|IXGBE_PHY_INIT_OFFSET_NL
value|0x002B
end_define

begin_define
define|#
directive|define
name|IXGBE_PHY_INIT_END_NL
value|0xFFFF
end_define

begin_define
define|#
directive|define
name|IXGBE_CONTROL_MASK_NL
value|0xF000
end_define

begin_define
define|#
directive|define
name|IXGBE_DATA_MASK_NL
value|0x0FFF
end_define

begin_define
define|#
directive|define
name|IXGBE_CONTROL_SHIFT_NL
value|12
end_define

begin_define
define|#
directive|define
name|IXGBE_DELAY_NL
value|0
end_define

begin_define
define|#
directive|define
name|IXGBE_DATA_NL
value|1
end_define

begin_define
define|#
directive|define
name|IXGBE_CONTROL_NL
value|0x000F
end_define

begin_define
define|#
directive|define
name|IXGBE_CONTROL_EOL_NL
value|0x0FFF
end_define

begin_define
define|#
directive|define
name|IXGBE_CONTROL_SOL_NL
value|0x0000
end_define

begin_comment
comment|/* General purpose Interrupt Enable */
end_comment

begin_define
define|#
directive|define
name|IXGBE_SDP0_GPIEN
value|0x00000001
end_define

begin_comment
comment|/* SDP0 */
end_comment

begin_define
define|#
directive|define
name|IXGBE_SDP1_GPIEN
value|0x00000002
end_define

begin_comment
comment|/* SDP1 */
end_comment

begin_define
define|#
directive|define
name|IXGBE_SDP2_GPIEN
value|0x00000004
end_define

begin_comment
comment|/* SDP2 */
end_comment

begin_define
define|#
directive|define
name|IXGBE_SDP0_GPIEN_X540
value|0x00000002
end_define

begin_comment
comment|/* SDP0 on X540 and X550 */
end_comment

begin_define
define|#
directive|define
name|IXGBE_SDP1_GPIEN_X540
value|0x00000004
end_define

begin_comment
comment|/* SDP1 on X540 and X550 */
end_comment

begin_define
define|#
directive|define
name|IXGBE_SDP2_GPIEN_X540
value|0x00000008
end_define

begin_comment
comment|/* SDP2 on X540 and X550 */
end_comment

begin_define
define|#
directive|define
name|IXGBE_SDP0_GPIEN_X550
value|IXGBE_SDP0_GPIEN_X540
end_define

begin_define
define|#
directive|define
name|IXGBE_SDP1_GPIEN_X550
value|IXGBE_SDP1_GPIEN_X540
end_define

begin_define
define|#
directive|define
name|IXGBE_SDP2_GPIEN_X550
value|IXGBE_SDP2_GPIEN_X540
end_define

begin_define
define|#
directive|define
name|IXGBE_SDP0_GPIEN_X550EM_x
value|IXGBE_SDP0_GPIEN_X540
end_define

begin_define
define|#
directive|define
name|IXGBE_SDP1_GPIEN_X550EM_x
value|IXGBE_SDP1_GPIEN_X540
end_define

begin_define
define|#
directive|define
name|IXGBE_SDP2_GPIEN_X550EM_x
value|IXGBE_SDP2_GPIEN_X540
end_define

begin_define
define|#
directive|define
name|IXGBE_SDP0_GPIEN_X550EM_a
value|IXGBE_SDP0_GPIEN_X540
end_define

begin_define
define|#
directive|define
name|IXGBE_SDP1_GPIEN_X550EM_a
value|IXGBE_SDP1_GPIEN_X540
end_define

begin_define
define|#
directive|define
name|IXGBE_SDP2_GPIEN_X550EM_a
value|IXGBE_SDP2_GPIEN_X540
end_define

begin_define
define|#
directive|define
name|IXGBE_SDP0_GPIEN_BY_MAC
parameter_list|(
name|_hw
parameter_list|)
value|IXGBE_BY_MAC((_hw), SDP0_GPIEN)
end_define

begin_define
define|#
directive|define
name|IXGBE_SDP1_GPIEN_BY_MAC
parameter_list|(
name|_hw
parameter_list|)
value|IXGBE_BY_MAC((_hw), SDP1_GPIEN)
end_define

begin_define
define|#
directive|define
name|IXGBE_SDP2_GPIEN_BY_MAC
parameter_list|(
name|_hw
parameter_list|)
value|IXGBE_BY_MAC((_hw), SDP2_GPIEN)
end_define

begin_define
define|#
directive|define
name|IXGBE_GPIE_MSIX_MODE
value|0x00000010
end_define

begin_comment
comment|/* MSI-X mode */
end_comment

begin_define
define|#
directive|define
name|IXGBE_GPIE_OCD
value|0x00000020
end_define

begin_comment
comment|/* Other Clear Disable */
end_comment

begin_define
define|#
directive|define
name|IXGBE_GPIE_EIMEN
value|0x00000040
end_define

begin_comment
comment|/* Immediate Interrupt Enable */
end_comment

begin_define
define|#
directive|define
name|IXGBE_GPIE_EIAME
value|0x40000000
end_define

begin_define
define|#
directive|define
name|IXGBE_GPIE_PBA_SUPPORT
value|0x80000000
end_define

begin_define
define|#
directive|define
name|IXGBE_GPIE_RSC_DELAY_SHIFT
value|11
end_define

begin_define
define|#
directive|define
name|IXGBE_GPIE_VTMODE_MASK
value|0x0000C000
end_define

begin_comment
comment|/* VT Mode Mask */
end_comment

begin_define
define|#
directive|define
name|IXGBE_GPIE_VTMODE_16
value|0x00004000
end_define

begin_comment
comment|/* 16 VFs 8 queues per VF */
end_comment

begin_define
define|#
directive|define
name|IXGBE_GPIE_VTMODE_32
value|0x00008000
end_define

begin_comment
comment|/* 32 VFs 4 queues per VF */
end_comment

begin_define
define|#
directive|define
name|IXGBE_GPIE_VTMODE_64
value|0x0000C000
end_define

begin_comment
comment|/* 64 VFs 2 queues per VF */
end_comment

begin_comment
comment|/* Packet Buffer Initialization */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MAX_PACKET_BUFFERS
value|8
end_define

begin_define
define|#
directive|define
name|IXGBE_TXPBSIZE_20KB
value|0x00005000
end_define

begin_comment
comment|/* 20KB Packet Buffer */
end_comment

begin_define
define|#
directive|define
name|IXGBE_TXPBSIZE_40KB
value|0x0000A000
end_define

begin_comment
comment|/* 40KB Packet Buffer */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXPBSIZE_48KB
value|0x0000C000
end_define

begin_comment
comment|/* 48KB Packet Buffer */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXPBSIZE_64KB
value|0x00010000
end_define

begin_comment
comment|/* 64KB Packet Buffer */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXPBSIZE_80KB
value|0x00014000
end_define

begin_comment
comment|/* 80KB Packet Buffer */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXPBSIZE_128KB
value|0x00020000
end_define

begin_comment
comment|/* 128KB Packet Buffer */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXPBSIZE_MAX
value|0x00080000
end_define

begin_comment
comment|/* 512KB Packet Buffer */
end_comment

begin_define
define|#
directive|define
name|IXGBE_TXPBSIZE_MAX
value|0x00028000
end_define

begin_comment
comment|/* 160KB Packet Buffer */
end_comment

begin_define
define|#
directive|define
name|IXGBE_TXPKT_SIZE_MAX
value|0xA
end_define

begin_comment
comment|/* Max Tx Packet size */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MAX_PB
value|8
end_define

begin_comment
comment|/* Packet buffer allocation strategies */
end_comment

begin_enum
enum|enum
block|{
name|PBA_STRATEGY_EQUAL
init|=
literal|0
block|,
comment|/* Distribute PB space equally */
define|#
directive|define
name|PBA_STRATEGY_EQUAL
value|PBA_STRATEGY_EQUAL
name|PBA_STRATEGY_WEIGHTED
init|=
literal|1
block|,
comment|/* Weight front half of TCs */
define|#
directive|define
name|PBA_STRATEGY_WEIGHTED
value|PBA_STRATEGY_WEIGHTED
block|}
enum|;
end_enum

begin_comment
comment|/* Transmit Flow Control status */
end_comment

begin_define
define|#
directive|define
name|IXGBE_TFCS_TXOFF
value|0x00000001
end_define

begin_define
define|#
directive|define
name|IXGBE_TFCS_TXOFF0
value|0x00000100
end_define

begin_define
define|#
directive|define
name|IXGBE_TFCS_TXOFF1
value|0x00000200
end_define

begin_define
define|#
directive|define
name|IXGBE_TFCS_TXOFF2
value|0x00000400
end_define

begin_define
define|#
directive|define
name|IXGBE_TFCS_TXOFF3
value|0x00000800
end_define

begin_define
define|#
directive|define
name|IXGBE_TFCS_TXOFF4
value|0x00001000
end_define

begin_define
define|#
directive|define
name|IXGBE_TFCS_TXOFF5
value|0x00002000
end_define

begin_define
define|#
directive|define
name|IXGBE_TFCS_TXOFF6
value|0x00004000
end_define

begin_define
define|#
directive|define
name|IXGBE_TFCS_TXOFF7
value|0x00008000
end_define

begin_comment
comment|/* TCP Timer */
end_comment

begin_define
define|#
directive|define
name|IXGBE_TCPTIMER_KS
value|0x00000100
end_define

begin_define
define|#
directive|define
name|IXGBE_TCPTIMER_COUNT_ENABLE
value|0x00000200
end_define

begin_define
define|#
directive|define
name|IXGBE_TCPTIMER_COUNT_FINISH
value|0x00000400
end_define

begin_define
define|#
directive|define
name|IXGBE_TCPTIMER_LOOP
value|0x00000800
end_define

begin_define
define|#
directive|define
name|IXGBE_TCPTIMER_DURATION_MASK
value|0x000000FF
end_define

begin_comment
comment|/* HLREG0 Bit Masks */
end_comment

begin_define
define|#
directive|define
name|IXGBE_HLREG0_TXCRCEN
value|0x00000001
end_define

begin_comment
comment|/* bit  0 */
end_comment

begin_define
define|#
directive|define
name|IXGBE_HLREG0_RXCRCSTRP
value|0x00000002
end_define

begin_comment
comment|/* bit  1 */
end_comment

begin_define
define|#
directive|define
name|IXGBE_HLREG0_JUMBOEN
value|0x00000004
end_define

begin_comment
comment|/* bit  2 */
end_comment

begin_define
define|#
directive|define
name|IXGBE_HLREG0_TXPADEN
value|0x00000400
end_define

begin_comment
comment|/* bit 10 */
end_comment

begin_define
define|#
directive|define
name|IXGBE_HLREG0_TXPAUSEEN
value|0x00001000
end_define

begin_comment
comment|/* bit 12 */
end_comment

begin_define
define|#
directive|define
name|IXGBE_HLREG0_RXPAUSEEN
value|0x00004000
end_define

begin_comment
comment|/* bit 14 */
end_comment

begin_define
define|#
directive|define
name|IXGBE_HLREG0_LPBK
value|0x00008000
end_define

begin_comment
comment|/* bit 15 */
end_comment

begin_define
define|#
directive|define
name|IXGBE_HLREG0_MDCSPD
value|0x00010000
end_define

begin_comment
comment|/* bit 16 */
end_comment

begin_define
define|#
directive|define
name|IXGBE_HLREG0_CONTMDC
value|0x00020000
end_define

begin_comment
comment|/* bit 17 */
end_comment

begin_define
define|#
directive|define
name|IXGBE_HLREG0_CTRLFLTR
value|0x00040000
end_define

begin_comment
comment|/* bit 18 */
end_comment

begin_define
define|#
directive|define
name|IXGBE_HLREG0_PREPEND
value|0x00F00000
end_define

begin_comment
comment|/* bits 20-23 */
end_comment

begin_define
define|#
directive|define
name|IXGBE_HLREG0_PRIPAUSEEN
value|0x01000000
end_define

begin_comment
comment|/* bit 24 */
end_comment

begin_define
define|#
directive|define
name|IXGBE_HLREG0_RXPAUSERECDA
value|0x06000000
end_define

begin_comment
comment|/* bits 25-26 */
end_comment

begin_define
define|#
directive|define
name|IXGBE_HLREG0_RXLNGTHERREN
value|0x08000000
end_define

begin_comment
comment|/* bit 27 */
end_comment

begin_define
define|#
directive|define
name|IXGBE_HLREG0_RXPADSTRIPEN
value|0x10000000
end_define

begin_comment
comment|/* bit 28 */
end_comment

begin_comment
comment|/* VMD_CTL bitmasks */
end_comment

begin_define
define|#
directive|define
name|IXGBE_VMD_CTL_VMDQ_EN
value|0x00000001
end_define

begin_define
define|#
directive|define
name|IXGBE_VMD_CTL_VMDQ_FILTER
value|0x00000002
end_define

begin_comment
comment|/* VT_CTL bitmasks */
end_comment

begin_define
define|#
directive|define
name|IXGBE_VT_CTL_DIS_DEFPL
value|0x20000000
end_define

begin_comment
comment|/* disable default pool */
end_comment

begin_define
define|#
directive|define
name|IXGBE_VT_CTL_REPLEN
value|0x40000000
end_define

begin_comment
comment|/* replication enabled */
end_comment

begin_define
define|#
directive|define
name|IXGBE_VT_CTL_VT_ENABLE
value|0x00000001
end_define

begin_comment
comment|/* Enable VT Mode */
end_comment

begin_define
define|#
directive|define
name|IXGBE_VT_CTL_POOL_SHIFT
value|7
end_define

begin_define
define|#
directive|define
name|IXGBE_VT_CTL_POOL_MASK
value|(0x3F<< IXGBE_VT_CTL_POOL_SHIFT)
end_define

begin_comment
comment|/* VMOLR bitmasks */
end_comment

begin_define
define|#
directive|define
name|IXGBE_VMOLR_UPE
value|0x00400000
end_define

begin_comment
comment|/* unicast promiscuous */
end_comment

begin_define
define|#
directive|define
name|IXGBE_VMOLR_VPE
value|0x00800000
end_define

begin_comment
comment|/* VLAN promiscuous */
end_comment

begin_define
define|#
directive|define
name|IXGBE_VMOLR_AUPE
value|0x01000000
end_define

begin_comment
comment|/* accept untagged packets */
end_comment

begin_define
define|#
directive|define
name|IXGBE_VMOLR_ROMPE
value|0x02000000
end_define

begin_comment
comment|/* accept packets in MTA tbl */
end_comment

begin_define
define|#
directive|define
name|IXGBE_VMOLR_ROPE
value|0x04000000
end_define

begin_comment
comment|/* accept packets in UC tbl */
end_comment

begin_define
define|#
directive|define
name|IXGBE_VMOLR_BAM
value|0x08000000
end_define

begin_comment
comment|/* accept broadcast packets */
end_comment

begin_define
define|#
directive|define
name|IXGBE_VMOLR_MPE
value|0x10000000
end_define

begin_comment
comment|/* multicast promiscuous */
end_comment

begin_comment
comment|/* VFRE bitmask */
end_comment

begin_define
define|#
directive|define
name|IXGBE_VFRE_ENABLE_ALL
value|0xFFFFFFFF
end_define

begin_define
define|#
directive|define
name|IXGBE_VF_INIT_TIMEOUT
value|200
end_define

begin_comment
comment|/* Number of retries to clear RSTI */
end_comment

begin_comment
comment|/* RDHMPN and TDHMPN bitmasks */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RDHMPN_RDICADDR
value|0x007FF800
end_define

begin_define
define|#
directive|define
name|IXGBE_RDHMPN_RDICRDREQ
value|0x00800000
end_define

begin_define
define|#
directive|define
name|IXGBE_RDHMPN_RDICADDR_SHIFT
value|11
end_define

begin_define
define|#
directive|define
name|IXGBE_TDHMPN_TDICADDR
value|0x003FF800
end_define

begin_define
define|#
directive|define
name|IXGBE_TDHMPN_TDICRDREQ
value|0x00800000
end_define

begin_define
define|#
directive|define
name|IXGBE_TDHMPN_TDICADDR_SHIFT
value|11
end_define

begin_define
define|#
directive|define
name|IXGBE_RDMAM_MEM_SEL_SHIFT
value|13
end_define

begin_define
define|#
directive|define
name|IXGBE_RDMAM_DWORD_SHIFT
value|9
end_define

begin_define
define|#
directive|define
name|IXGBE_RDMAM_DESC_COMP_FIFO
value|1
end_define

begin_define
define|#
directive|define
name|IXGBE_RDMAM_DFC_CMD_FIFO
value|2
end_define

begin_define
define|#
directive|define
name|IXGBE_RDMAM_RSC_HEADER_ADDR
value|3
end_define

begin_define
define|#
directive|define
name|IXGBE_RDMAM_TCN_STATUS_RAM
value|4
end_define

begin_define
define|#
directive|define
name|IXGBE_RDMAM_WB_COLL_FIFO
value|5
end_define

begin_define
define|#
directive|define
name|IXGBE_RDMAM_QSC_CNT_RAM
value|6
end_define

begin_define
define|#
directive|define
name|IXGBE_RDMAM_QSC_FCOE_RAM
value|7
end_define

begin_define
define|#
directive|define
name|IXGBE_RDMAM_QSC_QUEUE_CNT
value|8
end_define

begin_define
define|#
directive|define
name|IXGBE_RDMAM_QSC_QUEUE_RAM
value|0xA
end_define

begin_define
define|#
directive|define
name|IXGBE_RDMAM_QSC_RSC_RAM
value|0xB
end_define

begin_define
define|#
directive|define
name|IXGBE_RDMAM_DESC_COM_FIFO_RANGE
value|135
end_define

begin_define
define|#
directive|define
name|IXGBE_RDMAM_DESC_COM_FIFO_COUNT
value|4
end_define

begin_define
define|#
directive|define
name|IXGBE_RDMAM_DFC_CMD_FIFO_RANGE
value|48
end_define

begin_define
define|#
directive|define
name|IXGBE_RDMAM_DFC_CMD_FIFO_COUNT
value|7
end_define

begin_define
define|#
directive|define
name|IXGBE_RDMAM_RSC_HEADER_ADDR_RANGE
value|32
end_define

begin_define
define|#
directive|define
name|IXGBE_RDMAM_RSC_HEADER_ADDR_COUNT
value|4
end_define

begin_define
define|#
directive|define
name|IXGBE_RDMAM_TCN_STATUS_RAM_RANGE
value|256
end_define

begin_define
define|#
directive|define
name|IXGBE_RDMAM_TCN_STATUS_RAM_COUNT
value|9
end_define

begin_define
define|#
directive|define
name|IXGBE_RDMAM_WB_COLL_FIFO_RANGE
value|8
end_define

begin_define
define|#
directive|define
name|IXGBE_RDMAM_WB_COLL_FIFO_COUNT
value|4
end_define

begin_define
define|#
directive|define
name|IXGBE_RDMAM_QSC_CNT_RAM_RANGE
value|64
end_define

begin_define
define|#
directive|define
name|IXGBE_RDMAM_QSC_CNT_RAM_COUNT
value|4
end_define

begin_define
define|#
directive|define
name|IXGBE_RDMAM_QSC_FCOE_RAM_RANGE
value|512
end_define

begin_define
define|#
directive|define
name|IXGBE_RDMAM_QSC_FCOE_RAM_COUNT
value|5
end_define

begin_define
define|#
directive|define
name|IXGBE_RDMAM_QSC_QUEUE_CNT_RANGE
value|32
end_define

begin_define
define|#
directive|define
name|IXGBE_RDMAM_QSC_QUEUE_CNT_COUNT
value|4
end_define

begin_define
define|#
directive|define
name|IXGBE_RDMAM_QSC_QUEUE_RAM_RANGE
value|128
end_define

begin_define
define|#
directive|define
name|IXGBE_RDMAM_QSC_QUEUE_RAM_COUNT
value|8
end_define

begin_define
define|#
directive|define
name|IXGBE_RDMAM_QSC_RSC_RAM_RANGE
value|32
end_define

begin_define
define|#
directive|define
name|IXGBE_RDMAM_QSC_RSC_RAM_COUNT
value|8
end_define

begin_define
define|#
directive|define
name|IXGBE_TXDESCIC_READY
value|0x80000000
end_define

begin_comment
comment|/* Receive Checksum Control */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXCSUM_IPPCSE
value|0x00001000
end_define

begin_comment
comment|/* IP payload checksum enable */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXCSUM_PCSD
value|0x00002000
end_define

begin_comment
comment|/* packet checksum disabled */
end_comment

begin_comment
comment|/* FCRTL Bit Masks */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FCRTL_XONE
value|0x80000000
end_define

begin_comment
comment|/* XON enable */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FCRTH_FCEN
value|0x80000000
end_define

begin_comment
comment|/* Packet buffer fc enable */
end_comment

begin_comment
comment|/* PAP bit masks*/
end_comment

begin_define
define|#
directive|define
name|IXGBE_PAP_TXPAUSECNT_MASK
value|0x0000FFFF
end_define

begin_comment
comment|/* Pause counter mask */
end_comment

begin_comment
comment|/* RMCS Bit Masks */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RMCS_RRM
value|0x00000002
end_define

begin_comment
comment|/* Rx Recycle Mode enable */
end_comment

begin_comment
comment|/* Receive Arbitration Control: 0 Round Robin, 1 DFP */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RMCS_RAC
value|0x00000004
end_define

begin_comment
comment|/* Deficit Fixed Prio ena */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RMCS_DFP
value|IXGBE_RMCS_RAC
end_define

begin_define
define|#
directive|define
name|IXGBE_RMCS_TFCE_802_3X
value|0x00000008
end_define

begin_comment
comment|/* Tx Priority FC ena */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RMCS_TFCE_PRIORITY
value|0x00000010
end_define

begin_comment
comment|/* Tx Priority FC ena */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RMCS_ARBDIS
value|0x00000040
end_define

begin_comment
comment|/* Arbitration disable bit */
end_comment

begin_comment
comment|/* FCCFG Bit Masks */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FCCFG_TFCE_802_3X
value|0x00000008
end_define

begin_comment
comment|/* Tx link FC enable */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FCCFG_TFCE_PRIORITY
value|0x00000010
end_define

begin_comment
comment|/* Tx priority FC enable */
end_comment

begin_comment
comment|/* Interrupt register bitmasks */
end_comment

begin_comment
comment|/* Extended Interrupt Cause Read */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EICR_RTX_QUEUE
value|0x0000FFFF
end_define

begin_comment
comment|/* RTx Queue Interrupt */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EICR_FLOW_DIR
value|0x00010000
end_define

begin_comment
comment|/* FDir Exception */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EICR_RX_MISS
value|0x00020000
end_define

begin_comment
comment|/* Packet Buffer Overrun */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EICR_PCI
value|0x00040000
end_define

begin_comment
comment|/* PCI Exception */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EICR_MAILBOX
value|0x00080000
end_define

begin_comment
comment|/* VF to PF Mailbox Interrupt */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EICR_LSC
value|0x00100000
end_define

begin_comment
comment|/* Link Status Change */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EICR_LINKSEC
value|0x00200000
end_define

begin_comment
comment|/* PN Threshold */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EICR_MNG
value|0x00400000
end_define

begin_comment
comment|/* Manageability Event Interrupt */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EICR_TS
value|0x00800000
end_define

begin_comment
comment|/* Thermal Sensor Event */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EICR_TIMESYNC
value|0x01000000
end_define

begin_comment
comment|/* Timesync Event */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EICR_GPI_SDP0
value|0x01000000
end_define

begin_comment
comment|/* Gen Purpose Interrupt on SDP0 */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EICR_GPI_SDP1
value|0x02000000
end_define

begin_comment
comment|/* Gen Purpose Interrupt on SDP1 */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EICR_GPI_SDP2
value|0x04000000
end_define

begin_comment
comment|/* Gen Purpose Interrupt on SDP2 */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EICR_ECC
value|0x10000000
end_define

begin_comment
comment|/* ECC Error */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EICR_GPI_SDP0_X540
value|0x02000000
end_define

begin_comment
comment|/* Gen Purpose Interrupt on SDP0 */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EICR_GPI_SDP1_X540
value|0x04000000
end_define

begin_comment
comment|/* Gen Purpose Interrupt on SDP1 */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EICR_GPI_SDP2_X540
value|0x08000000
end_define

begin_comment
comment|/* Gen Purpose Interrupt on SDP2 */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EICR_GPI_SDP0_X550
value|IXGBE_EICR_GPI_SDP0_X540
end_define

begin_define
define|#
directive|define
name|IXGBE_EICR_GPI_SDP1_X550
value|IXGBE_EICR_GPI_SDP1_X540
end_define

begin_define
define|#
directive|define
name|IXGBE_EICR_GPI_SDP2_X550
value|IXGBE_EICR_GPI_SDP2_X540
end_define

begin_define
define|#
directive|define
name|IXGBE_EICR_GPI_SDP0_X550EM_x
value|IXGBE_EICR_GPI_SDP0_X540
end_define

begin_define
define|#
directive|define
name|IXGBE_EICR_GPI_SDP1_X550EM_x
value|IXGBE_EICR_GPI_SDP1_X540
end_define

begin_define
define|#
directive|define
name|IXGBE_EICR_GPI_SDP2_X550EM_x
value|IXGBE_EICR_GPI_SDP2_X540
end_define

begin_define
define|#
directive|define
name|IXGBE_EICR_GPI_SDP0_X550EM_a
value|IXGBE_EICR_GPI_SDP0_X540
end_define

begin_define
define|#
directive|define
name|IXGBE_EICR_GPI_SDP1_X550EM_a
value|IXGBE_EICR_GPI_SDP1_X540
end_define

begin_define
define|#
directive|define
name|IXGBE_EICR_GPI_SDP2_X550EM_a
value|IXGBE_EICR_GPI_SDP2_X540
end_define

begin_define
define|#
directive|define
name|IXGBE_EICR_GPI_SDP0_BY_MAC
parameter_list|(
name|_hw
parameter_list|)
value|IXGBE_BY_MAC((_hw), EICR_GPI_SDP0)
end_define

begin_define
define|#
directive|define
name|IXGBE_EICR_GPI_SDP1_BY_MAC
parameter_list|(
name|_hw
parameter_list|)
value|IXGBE_BY_MAC((_hw), EICR_GPI_SDP1)
end_define

begin_define
define|#
directive|define
name|IXGBE_EICR_GPI_SDP2_BY_MAC
parameter_list|(
name|_hw
parameter_list|)
value|IXGBE_BY_MAC((_hw), EICR_GPI_SDP2)
end_define

begin_define
define|#
directive|define
name|IXGBE_EICR_PBUR
value|0x10000000
end_define

begin_comment
comment|/* Packet Buffer Handler Error */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EICR_DHER
value|0x20000000
end_define

begin_comment
comment|/* Descriptor Handler Error */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EICR_TCP_TIMER
value|0x40000000
end_define

begin_comment
comment|/* TCP Timer */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EICR_OTHER
value|0x80000000
end_define

begin_comment
comment|/* Interrupt Cause Active */
end_comment

begin_comment
comment|/* Extended Interrupt Cause Set */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EICS_RTX_QUEUE
value|IXGBE_EICR_RTX_QUEUE
end_define

begin_comment
comment|/* RTx Queue Interrupt */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EICS_FLOW_DIR
value|IXGBE_EICR_FLOW_DIR
end_define

begin_comment
comment|/* FDir Exception */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EICS_RX_MISS
value|IXGBE_EICR_RX_MISS
end_define

begin_comment
comment|/* Pkt Buffer Overrun */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EICS_PCI
value|IXGBE_EICR_PCI
end_define

begin_comment
comment|/* PCI Exception */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EICS_MAILBOX
value|IXGBE_EICR_MAILBOX
end_define

begin_comment
comment|/* VF to PF Mailbox Int */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EICS_LSC
value|IXGBE_EICR_LSC
end_define

begin_comment
comment|/* Link Status Change */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EICS_MNG
value|IXGBE_EICR_MNG
end_define

begin_comment
comment|/* MNG Event Interrupt */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EICS_TIMESYNC
value|IXGBE_EICR_TIMESYNC
end_define

begin_comment
comment|/* Timesync Event */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EICS_GPI_SDP0
value|IXGBE_EICR_GPI_SDP0
end_define

begin_comment
comment|/* SDP0 Gen Purpose Int */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EICS_GPI_SDP1
value|IXGBE_EICR_GPI_SDP1
end_define

begin_comment
comment|/* SDP1 Gen Purpose Int */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EICS_GPI_SDP2
value|IXGBE_EICR_GPI_SDP2
end_define

begin_comment
comment|/* SDP2 Gen Purpose Int */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EICS_ECC
value|IXGBE_EICR_ECC
end_define

begin_comment
comment|/* ECC Error */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EICS_GPI_SDP0_BY_MAC
parameter_list|(
name|_hw
parameter_list|)
value|IXGBE_EICR_GPI_SDP0_BY_MAC(_hw)
end_define

begin_define
define|#
directive|define
name|IXGBE_EICS_GPI_SDP1_BY_MAC
parameter_list|(
name|_hw
parameter_list|)
value|IXGBE_EICR_GPI_SDP1_BY_MAC(_hw)
end_define

begin_define
define|#
directive|define
name|IXGBE_EICS_GPI_SDP2_BY_MAC
parameter_list|(
name|_hw
parameter_list|)
value|IXGBE_EICR_GPI_SDP2_BY_MAC(_hw)
end_define

begin_define
define|#
directive|define
name|IXGBE_EICS_PBUR
value|IXGBE_EICR_PBUR
end_define

begin_comment
comment|/* Pkt Buf Handler Err */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EICS_DHER
value|IXGBE_EICR_DHER
end_define

begin_comment
comment|/* Desc Handler Error */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EICS_TCP_TIMER
value|IXGBE_EICR_TCP_TIMER
end_define

begin_comment
comment|/* TCP Timer */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EICS_OTHER
value|IXGBE_EICR_OTHER
end_define

begin_comment
comment|/* INT Cause Active */
end_comment

begin_comment
comment|/* Extended Interrupt Mask Set */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EIMS_RTX_QUEUE
value|IXGBE_EICR_RTX_QUEUE
end_define

begin_comment
comment|/* RTx Queue Interrupt */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EIMS_FLOW_DIR
value|IXGBE_EICR_FLOW_DIR
end_define

begin_comment
comment|/* FDir Exception */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EIMS_RX_MISS
value|IXGBE_EICR_RX_MISS
end_define

begin_comment
comment|/* Packet Buffer Overrun */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EIMS_PCI
value|IXGBE_EICR_PCI
end_define

begin_comment
comment|/* PCI Exception */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EIMS_MAILBOX
value|IXGBE_EICR_MAILBOX
end_define

begin_comment
comment|/* VF to PF Mailbox Int */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EIMS_LSC
value|IXGBE_EICR_LSC
end_define

begin_comment
comment|/* Link Status Change */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EIMS_MNG
value|IXGBE_EICR_MNG
end_define

begin_comment
comment|/* MNG Event Interrupt */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EIMS_TS
value|IXGBE_EICR_TS
end_define

begin_comment
comment|/* Thermal Sensor Event */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EIMS_TIMESYNC
value|IXGBE_EICR_TIMESYNC
end_define

begin_comment
comment|/* Timesync Event */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EIMS_GPI_SDP0
value|IXGBE_EICR_GPI_SDP0
end_define

begin_comment
comment|/* SDP0 Gen Purpose Int */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EIMS_GPI_SDP1
value|IXGBE_EICR_GPI_SDP1
end_define

begin_comment
comment|/* SDP1 Gen Purpose Int */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EIMS_GPI_SDP2
value|IXGBE_EICR_GPI_SDP2
end_define

begin_comment
comment|/* SDP2 Gen Purpose Int */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EIMS_ECC
value|IXGBE_EICR_ECC
end_define

begin_comment
comment|/* ECC Error */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EIMS_GPI_SDP0_BY_MAC
parameter_list|(
name|_hw
parameter_list|)
value|IXGBE_EICR_GPI_SDP0_BY_MAC(_hw)
end_define

begin_define
define|#
directive|define
name|IXGBE_EIMS_GPI_SDP1_BY_MAC
parameter_list|(
name|_hw
parameter_list|)
value|IXGBE_EICR_GPI_SDP1_BY_MAC(_hw)
end_define

begin_define
define|#
directive|define
name|IXGBE_EIMS_GPI_SDP2_BY_MAC
parameter_list|(
name|_hw
parameter_list|)
value|IXGBE_EICR_GPI_SDP2_BY_MAC(_hw)
end_define

begin_define
define|#
directive|define
name|IXGBE_EIMS_PBUR
value|IXGBE_EICR_PBUR
end_define

begin_comment
comment|/* Pkt Buf Handler Err */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EIMS_DHER
value|IXGBE_EICR_DHER
end_define

begin_comment
comment|/* Descr Handler Error */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EIMS_TCP_TIMER
value|IXGBE_EICR_TCP_TIMER
end_define

begin_comment
comment|/* TCP Timer */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EIMS_OTHER
value|IXGBE_EICR_OTHER
end_define

begin_comment
comment|/* INT Cause Active */
end_comment

begin_comment
comment|/* Extended Interrupt Mask Clear */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EIMC_RTX_QUEUE
value|IXGBE_EICR_RTX_QUEUE
end_define

begin_comment
comment|/* RTx Queue Interrupt */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EIMC_FLOW_DIR
value|IXGBE_EICR_FLOW_DIR
end_define

begin_comment
comment|/* FDir Exception */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EIMC_RX_MISS
value|IXGBE_EICR_RX_MISS
end_define

begin_comment
comment|/* Packet Buffer Overrun */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EIMC_PCI
value|IXGBE_EICR_PCI
end_define

begin_comment
comment|/* PCI Exception */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EIMC_MAILBOX
value|IXGBE_EICR_MAILBOX
end_define

begin_comment
comment|/* VF to PF Mailbox Int */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EIMC_LSC
value|IXGBE_EICR_LSC
end_define

begin_comment
comment|/* Link Status Change */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EIMC_MNG
value|IXGBE_EICR_MNG
end_define

begin_comment
comment|/* MNG Event Interrupt */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EIMC_TIMESYNC
value|IXGBE_EICR_TIMESYNC
end_define

begin_comment
comment|/* Timesync Event */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EIMC_GPI_SDP0
value|IXGBE_EICR_GPI_SDP0
end_define

begin_comment
comment|/* SDP0 Gen Purpose Int */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EIMC_GPI_SDP1
value|IXGBE_EICR_GPI_SDP1
end_define

begin_comment
comment|/* SDP1 Gen Purpose Int */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EIMC_GPI_SDP2
value|IXGBE_EICR_GPI_SDP2
end_define

begin_comment
comment|/* SDP2 Gen Purpose Int */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EIMC_ECC
value|IXGBE_EICR_ECC
end_define

begin_comment
comment|/* ECC Error */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EIMC_GPI_SDP0_BY_MAC
parameter_list|(
name|_hw
parameter_list|)
value|IXGBE_EICR_GPI_SDP0_BY_MAC(_hw)
end_define

begin_define
define|#
directive|define
name|IXGBE_EIMC_GPI_SDP1_BY_MAC
parameter_list|(
name|_hw
parameter_list|)
value|IXGBE_EICR_GPI_SDP1_BY_MAC(_hw)
end_define

begin_define
define|#
directive|define
name|IXGBE_EIMC_GPI_SDP2_BY_MAC
parameter_list|(
name|_hw
parameter_list|)
value|IXGBE_EICR_GPI_SDP2_BY_MAC(_hw)
end_define

begin_define
define|#
directive|define
name|IXGBE_EIMC_PBUR
value|IXGBE_EICR_PBUR
end_define

begin_comment
comment|/* Pkt Buf Handler Err */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EIMC_DHER
value|IXGBE_EICR_DHER
end_define

begin_comment
comment|/* Desc Handler Err */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EIMC_TCP_TIMER
value|IXGBE_EICR_TCP_TIMER
end_define

begin_comment
comment|/* TCP Timer */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EIMC_OTHER
value|IXGBE_EICR_OTHER
end_define

begin_comment
comment|/* INT Cause Active */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EIMS_ENABLE_MASK
value|( \ 				IXGBE_EIMS_RTX_QUEUE	| \ 				IXGBE_EIMS_LSC		| \ 				IXGBE_EIMS_TCP_TIMER	| \ 				IXGBE_EIMS_OTHER)
end_define

begin_comment
comment|/* Immediate Interrupt Rx (A.K.A. Low Latency Interrupt) */
end_comment

begin_define
define|#
directive|define
name|IXGBE_IMIR_PORT_IM_EN
value|0x00010000
end_define

begin_comment
comment|/* TCP port enable */
end_comment

begin_define
define|#
directive|define
name|IXGBE_IMIR_PORT_BP
value|0x00020000
end_define

begin_comment
comment|/* TCP port check bypass */
end_comment

begin_define
define|#
directive|define
name|IXGBE_IMIREXT_SIZE_BP
value|0x00001000
end_define

begin_comment
comment|/* Packet size bypass */
end_comment

begin_define
define|#
directive|define
name|IXGBE_IMIREXT_CTRL_URG
value|0x00002000
end_define

begin_comment
comment|/* Check URG bit in header */
end_comment

begin_define
define|#
directive|define
name|IXGBE_IMIREXT_CTRL_ACK
value|0x00004000
end_define

begin_comment
comment|/* Check ACK bit in header */
end_comment

begin_define
define|#
directive|define
name|IXGBE_IMIREXT_CTRL_PSH
value|0x00008000
end_define

begin_comment
comment|/* Check PSH bit in header */
end_comment

begin_define
define|#
directive|define
name|IXGBE_IMIREXT_CTRL_RST
value|0x00010000
end_define

begin_comment
comment|/* Check RST bit in header */
end_comment

begin_define
define|#
directive|define
name|IXGBE_IMIREXT_CTRL_SYN
value|0x00020000
end_define

begin_comment
comment|/* Check SYN bit in header */
end_comment

begin_define
define|#
directive|define
name|IXGBE_IMIREXT_CTRL_FIN
value|0x00040000
end_define

begin_comment
comment|/* Check FIN bit in header */
end_comment

begin_define
define|#
directive|define
name|IXGBE_IMIREXT_CTRL_BP
value|0x00080000
end_define

begin_comment
comment|/* Bypass check of control bits */
end_comment

begin_define
define|#
directive|define
name|IXGBE_IMIR_SIZE_BP_82599
value|0x00001000
end_define

begin_comment
comment|/* Packet size bypass */
end_comment

begin_define
define|#
directive|define
name|IXGBE_IMIR_CTRL_URG_82599
value|0x00002000
end_define

begin_comment
comment|/* Check URG bit in header */
end_comment

begin_define
define|#
directive|define
name|IXGBE_IMIR_CTRL_ACK_82599
value|0x00004000
end_define

begin_comment
comment|/* Check ACK bit in header */
end_comment

begin_define
define|#
directive|define
name|IXGBE_IMIR_CTRL_PSH_82599
value|0x00008000
end_define

begin_comment
comment|/* Check PSH bit in header */
end_comment

begin_define
define|#
directive|define
name|IXGBE_IMIR_CTRL_RST_82599
value|0x00010000
end_define

begin_comment
comment|/* Check RST bit in header */
end_comment

begin_define
define|#
directive|define
name|IXGBE_IMIR_CTRL_SYN_82599
value|0x00020000
end_define

begin_comment
comment|/* Check SYN bit in header */
end_comment

begin_define
define|#
directive|define
name|IXGBE_IMIR_CTRL_FIN_82599
value|0x00040000
end_define

begin_comment
comment|/* Check FIN bit in header */
end_comment

begin_define
define|#
directive|define
name|IXGBE_IMIR_CTRL_BP_82599
value|0x00080000
end_define

begin_comment
comment|/* Bypass chk of ctrl bits */
end_comment

begin_define
define|#
directive|define
name|IXGBE_IMIR_LLI_EN_82599
value|0x00100000
end_define

begin_comment
comment|/* Enables low latency Int */
end_comment

begin_define
define|#
directive|define
name|IXGBE_IMIR_RX_QUEUE_MASK_82599
value|0x0000007F
end_define

begin_comment
comment|/* Rx Queue Mask */
end_comment

begin_define
define|#
directive|define
name|IXGBE_IMIR_RX_QUEUE_SHIFT_82599
value|21
end_define

begin_comment
comment|/* Rx Queue Shift */
end_comment

begin_define
define|#
directive|define
name|IXGBE_IMIRVP_PRIORITY_MASK
value|0x00000007
end_define

begin_comment
comment|/* VLAN priority mask */
end_comment

begin_define
define|#
directive|define
name|IXGBE_IMIRVP_PRIORITY_EN
value|0x00000008
end_define

begin_comment
comment|/* VLAN priority enable */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MAX_FTQF_FILTERS
value|128
end_define

begin_define
define|#
directive|define
name|IXGBE_FTQF_PROTOCOL_MASK
value|0x00000003
end_define

begin_define
define|#
directive|define
name|IXGBE_FTQF_PROTOCOL_TCP
value|0x00000000
end_define

begin_define
define|#
directive|define
name|IXGBE_FTQF_PROTOCOL_UDP
value|0x00000001
end_define

begin_define
define|#
directive|define
name|IXGBE_FTQF_PROTOCOL_SCTP
value|2
end_define

begin_define
define|#
directive|define
name|IXGBE_FTQF_PRIORITY_MASK
value|0x00000007
end_define

begin_define
define|#
directive|define
name|IXGBE_FTQF_PRIORITY_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|IXGBE_FTQF_POOL_MASK
value|0x0000003F
end_define

begin_define
define|#
directive|define
name|IXGBE_FTQF_POOL_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|IXGBE_FTQF_5TUPLE_MASK_MASK
value|0x0000001F
end_define

begin_define
define|#
directive|define
name|IXGBE_FTQF_5TUPLE_MASK_SHIFT
value|25
end_define

begin_define
define|#
directive|define
name|IXGBE_FTQF_SOURCE_ADDR_MASK
value|0x1E
end_define

begin_define
define|#
directive|define
name|IXGBE_FTQF_DEST_ADDR_MASK
value|0x1D
end_define

begin_define
define|#
directive|define
name|IXGBE_FTQF_SOURCE_PORT_MASK
value|0x1B
end_define

begin_define
define|#
directive|define
name|IXGBE_FTQF_DEST_PORT_MASK
value|0x17
end_define

begin_define
define|#
directive|define
name|IXGBE_FTQF_PROTOCOL_COMP_MASK
value|0x0F
end_define

begin_define
define|#
directive|define
name|IXGBE_FTQF_POOL_MASK_EN
value|0x40000000
end_define

begin_define
define|#
directive|define
name|IXGBE_FTQF_QUEUE_ENABLE
value|0x80000000
end_define

begin_comment
comment|/* Interrupt clear mask */
end_comment

begin_define
define|#
directive|define
name|IXGBE_IRQ_CLEAR_MASK
value|0xFFFFFFFF
end_define

begin_comment
comment|/* Interrupt Vector Allocation Registers */
end_comment

begin_define
define|#
directive|define
name|IXGBE_IVAR_REG_NUM
value|25
end_define

begin_define
define|#
directive|define
name|IXGBE_IVAR_REG_NUM_82599
value|64
end_define

begin_define
define|#
directive|define
name|IXGBE_IVAR_TXRX_ENTRY
value|96
end_define

begin_define
define|#
directive|define
name|IXGBE_IVAR_RX_ENTRY
value|64
end_define

begin_define
define|#
directive|define
name|IXGBE_IVAR_RX_QUEUE
parameter_list|(
name|_i
parameter_list|)
value|(0 + (_i))
end_define

begin_define
define|#
directive|define
name|IXGBE_IVAR_TX_QUEUE
parameter_list|(
name|_i
parameter_list|)
value|(64 + (_i))
end_define

begin_define
define|#
directive|define
name|IXGBE_IVAR_TX_ENTRY
value|32
end_define

begin_define
define|#
directive|define
name|IXGBE_IVAR_TCP_TIMER_INDEX
value|96
end_define

begin_comment
comment|/* 0 based index */
end_comment

begin_define
define|#
directive|define
name|IXGBE_IVAR_OTHER_CAUSES_INDEX
value|97
end_define

begin_comment
comment|/* 0 based index */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MSIX_VECTOR
parameter_list|(
name|_i
parameter_list|)
value|(0 + (_i))
end_define

begin_define
define|#
directive|define
name|IXGBE_IVAR_ALLOC_VAL
value|0x80
end_define

begin_comment
comment|/* Interrupt Allocation valid */
end_comment

begin_comment
comment|/* ETYPE Queue Filter/Select Bit Masks */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MAX_ETQF_FILTERS
value|8
end_define

begin_define
define|#
directive|define
name|IXGBE_ETQF_FCOE
value|0x08000000
end_define

begin_comment
comment|/* bit 27 */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ETQF_BCN
value|0x10000000
end_define

begin_comment
comment|/* bit 28 */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ETQF_TX_ANTISPOOF
value|0x20000000
end_define

begin_comment
comment|/* bit 29 */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ETQF_1588
value|0x40000000
end_define

begin_comment
comment|/* bit 30 */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ETQF_FILTER_EN
value|0x80000000
end_define

begin_comment
comment|/* bit 31 */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ETQF_POOL_ENABLE
value|(1<< 26)
end_define

begin_comment
comment|/* bit 26 */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ETQF_POOL_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|IXGBE_ETQS_RX_QUEUE
value|0x007F0000
end_define

begin_comment
comment|/* bits 22:16 */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ETQS_RX_QUEUE_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|IXGBE_ETQS_LLI
value|0x20000000
end_define

begin_comment
comment|/* bit 29 */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ETQS_QUEUE_EN
value|0x80000000
end_define

begin_comment
comment|/* bit 31 */
end_comment

begin_comment
comment|/*  * ETQF filter list: one static filter per filter consumer. This is  *		   to avoid filter collisions later. Add new filters  *		   here!!  *  * Current filters:  *	EAPOL 802.1x (0x888e): Filter 0  *	FCoE (0x8906):	 Filter 2  *	1588 (0x88f7):	 Filter 3  *	FIP  (0x8914):	 Filter 4  *	LLDP (0x88CC):	 Filter 5  *	LACP (0x8809):	 Filter 6  *	FC   (0x8808):	 Filter 7  */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ETQF_FILTER_EAPOL
value|0
end_define

begin_define
define|#
directive|define
name|IXGBE_ETQF_FILTER_FCOE
value|2
end_define

begin_define
define|#
directive|define
name|IXGBE_ETQF_FILTER_1588
value|3
end_define

begin_define
define|#
directive|define
name|IXGBE_ETQF_FILTER_FIP
value|4
end_define

begin_define
define|#
directive|define
name|IXGBE_ETQF_FILTER_LLDP
value|5
end_define

begin_define
define|#
directive|define
name|IXGBE_ETQF_FILTER_LACP
value|6
end_define

begin_define
define|#
directive|define
name|IXGBE_ETQF_FILTER_FC
value|7
end_define

begin_comment
comment|/* VLAN Control Bit Masks */
end_comment

begin_define
define|#
directive|define
name|IXGBE_VLNCTRL_VET
value|0x0000FFFF
end_define

begin_comment
comment|/* bits 0-15 */
end_comment

begin_define
define|#
directive|define
name|IXGBE_VLNCTRL_CFI
value|0x10000000
end_define

begin_comment
comment|/* bit 28 */
end_comment

begin_define
define|#
directive|define
name|IXGBE_VLNCTRL_CFIEN
value|0x20000000
end_define

begin_comment
comment|/* bit 29 */
end_comment

begin_define
define|#
directive|define
name|IXGBE_VLNCTRL_VFE
value|0x40000000
end_define

begin_comment
comment|/* bit 30 */
end_comment

begin_define
define|#
directive|define
name|IXGBE_VLNCTRL_VME
value|0x80000000
end_define

begin_comment
comment|/* bit 31 */
end_comment

begin_comment
comment|/* VLAN pool filtering masks */
end_comment

begin_define
define|#
directive|define
name|IXGBE_VLVF_VIEN
value|0x80000000
end_define

begin_comment
comment|/* filter is valid */
end_comment

begin_define
define|#
directive|define
name|IXGBE_VLVF_ENTRIES
value|64
end_define

begin_define
define|#
directive|define
name|IXGBE_VLVF_VLANID_MASK
value|0x00000FFF
end_define

begin_comment
comment|/* Per VF Port VLAN insertion rules */
end_comment

begin_define
define|#
directive|define
name|IXGBE_VMVIR_VLANA_DEFAULT
value|0x40000000
end_define

begin_comment
comment|/* Always use default VLAN */
end_comment

begin_define
define|#
directive|define
name|IXGBE_VMVIR_VLANA_NEVER
value|0x80000000
end_define

begin_comment
comment|/* Never insert VLAN tag */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ETHERNET_IEEE_VLAN_TYPE
value|0x8100
end_define

begin_comment
comment|/* 802.1q protocol */
end_comment

begin_comment
comment|/* STATUS Bit Masks */
end_comment

begin_define
define|#
directive|define
name|IXGBE_STATUS_LAN_ID
value|0x0000000C
end_define

begin_comment
comment|/* LAN ID */
end_comment

begin_define
define|#
directive|define
name|IXGBE_STATUS_LAN_ID_SHIFT
value|2
end_define

begin_comment
comment|/* LAN ID Shift*/
end_comment

begin_define
define|#
directive|define
name|IXGBE_STATUS_GIO
value|0x00080000
end_define

begin_comment
comment|/* GIO Master Ena Status */
end_comment

begin_define
define|#
directive|define
name|IXGBE_STATUS_LAN_ID_0
value|0x00000000
end_define

begin_comment
comment|/* LAN ID 0 */
end_comment

begin_define
define|#
directive|define
name|IXGBE_STATUS_LAN_ID_1
value|0x00000004
end_define

begin_comment
comment|/* LAN ID 1 */
end_comment

begin_comment
comment|/* ESDP Bit Masks */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ESDP_SDP0
value|0x00000001
end_define

begin_comment
comment|/* SDP0 Data Value */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ESDP_SDP1
value|0x00000002
end_define

begin_comment
comment|/* SDP1 Data Value */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ESDP_SDP2
value|0x00000004
end_define

begin_comment
comment|/* SDP2 Data Value */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ESDP_SDP3
value|0x00000008
end_define

begin_comment
comment|/* SDP3 Data Value */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ESDP_SDP4
value|0x00000010
end_define

begin_comment
comment|/* SDP4 Data Value */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ESDP_SDP5
value|0x00000020
end_define

begin_comment
comment|/* SDP5 Data Value */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ESDP_SDP6
value|0x00000040
end_define

begin_comment
comment|/* SDP6 Data Value */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ESDP_SDP7
value|0x00000080
end_define

begin_comment
comment|/* SDP7 Data Value */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ESDP_SDP0_DIR
value|0x00000100
end_define

begin_comment
comment|/* SDP0 IO direction */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ESDP_SDP1_DIR
value|0x00000200
end_define

begin_comment
comment|/* SDP1 IO direction */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ESDP_SDP2_DIR
value|0x00000400
end_define

begin_comment
comment|/* SDP1 IO direction */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ESDP_SDP3_DIR
value|0x00000800
end_define

begin_comment
comment|/* SDP3 IO direction */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ESDP_SDP4_DIR
value|0x00001000
end_define

begin_comment
comment|/* SDP4 IO direction */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ESDP_SDP5_DIR
value|0x00002000
end_define

begin_comment
comment|/* SDP5 IO direction */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ESDP_SDP6_DIR
value|0x00004000
end_define

begin_comment
comment|/* SDP6 IO direction */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ESDP_SDP7_DIR
value|0x00008000
end_define

begin_comment
comment|/* SDP7 IO direction */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ESDP_SDP0_NATIVE
value|0x00010000
end_define

begin_comment
comment|/* SDP0 IO mode */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ESDP_SDP1_NATIVE
value|0x00020000
end_define

begin_comment
comment|/* SDP1 IO mode */
end_comment

begin_comment
comment|/* LEDCTL Bit Masks */
end_comment

begin_define
define|#
directive|define
name|IXGBE_LED_IVRT_BASE
value|0x00000040
end_define

begin_define
define|#
directive|define
name|IXGBE_LED_BLINK_BASE
value|0x00000080
end_define

begin_define
define|#
directive|define
name|IXGBE_LED_MODE_MASK_BASE
value|0x0000000F
end_define

begin_define
define|#
directive|define
name|IXGBE_LED_OFFSET
parameter_list|(
name|_base
parameter_list|,
name|_i
parameter_list|)
value|(_base<< (8 * (_i)))
end_define

begin_define
define|#
directive|define
name|IXGBE_LED_MODE_SHIFT
parameter_list|(
name|_i
parameter_list|)
value|(8*(_i))
end_define

begin_define
define|#
directive|define
name|IXGBE_LED_IVRT
parameter_list|(
name|_i
parameter_list|)
value|IXGBE_LED_OFFSET(IXGBE_LED_IVRT_BASE, _i)
end_define

begin_define
define|#
directive|define
name|IXGBE_LED_BLINK
parameter_list|(
name|_i
parameter_list|)
value|IXGBE_LED_OFFSET(IXGBE_LED_BLINK_BASE, _i)
end_define

begin_define
define|#
directive|define
name|IXGBE_LED_MODE_MASK
parameter_list|(
name|_i
parameter_list|)
value|IXGBE_LED_OFFSET(IXGBE_LED_MODE_MASK_BASE, _i)
end_define

begin_define
define|#
directive|define
name|IXGBE_X557_LED_MANUAL_SET_MASK
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|IXGBE_X557_MAX_LED_INDEX
value|3
end_define

begin_define
define|#
directive|define
name|IXGBE_X557_LED_PROVISIONING
value|0xC430
end_define

begin_comment
comment|/* LED modes */
end_comment

begin_define
define|#
directive|define
name|IXGBE_LED_LINK_UP
value|0x0
end_define

begin_define
define|#
directive|define
name|IXGBE_LED_LINK_10G
value|0x1
end_define

begin_define
define|#
directive|define
name|IXGBE_LED_MAC
value|0x2
end_define

begin_define
define|#
directive|define
name|IXGBE_LED_FILTER
value|0x3
end_define

begin_define
define|#
directive|define
name|IXGBE_LED_LINK_ACTIVE
value|0x4
end_define

begin_define
define|#
directive|define
name|IXGBE_LED_LINK_1G
value|0x5
end_define

begin_define
define|#
directive|define
name|IXGBE_LED_ON
value|0xE
end_define

begin_define
define|#
directive|define
name|IXGBE_LED_OFF
value|0xF
end_define

begin_comment
comment|/* AUTOC Bit Masks */
end_comment

begin_define
define|#
directive|define
name|IXGBE_AUTOC_KX4_KX_SUPP_MASK
value|0xC0000000
end_define

begin_define
define|#
directive|define
name|IXGBE_AUTOC_KX4_SUPP
value|0x80000000
end_define

begin_define
define|#
directive|define
name|IXGBE_AUTOC_KX_SUPP
value|0x40000000
end_define

begin_define
define|#
directive|define
name|IXGBE_AUTOC_PAUSE
value|0x30000000
end_define

begin_define
define|#
directive|define
name|IXGBE_AUTOC_ASM_PAUSE
value|0x20000000
end_define

begin_define
define|#
directive|define
name|IXGBE_AUTOC_SYM_PAUSE
value|0x10000000
end_define

begin_define
define|#
directive|define
name|IXGBE_AUTOC_RF
value|0x08000000
end_define

begin_define
define|#
directive|define
name|IXGBE_AUTOC_PD_TMR
value|0x06000000
end_define

begin_define
define|#
directive|define
name|IXGBE_AUTOC_AN_RX_LOOSE
value|0x01000000
end_define

begin_define
define|#
directive|define
name|IXGBE_AUTOC_AN_RX_DRIFT
value|0x00800000
end_define

begin_define
define|#
directive|define
name|IXGBE_AUTOC_AN_RX_ALIGN
value|0x007C0000
end_define

begin_define
define|#
directive|define
name|IXGBE_AUTOC_FECA
value|0x00040000
end_define

begin_define
define|#
directive|define
name|IXGBE_AUTOC_FECR
value|0x00020000
end_define

begin_define
define|#
directive|define
name|IXGBE_AUTOC_KR_SUPP
value|0x00010000
end_define

begin_define
define|#
directive|define
name|IXGBE_AUTOC_AN_RESTART
value|0x00001000
end_define

begin_define
define|#
directive|define
name|IXGBE_AUTOC_FLU
value|0x00000001
end_define

begin_define
define|#
directive|define
name|IXGBE_AUTOC_LMS_SHIFT
value|13
end_define

begin_define
define|#
directive|define
name|IXGBE_AUTOC_LMS_10G_SERIAL
value|(0x3<< IXGBE_AUTOC_LMS_SHIFT)
end_define

begin_define
define|#
directive|define
name|IXGBE_AUTOC_LMS_KX4_KX_KR
value|(0x4<< IXGBE_AUTOC_LMS_SHIFT)
end_define

begin_define
define|#
directive|define
name|IXGBE_AUTOC_LMS_SGMII_1G_100M
value|(0x5<< IXGBE_AUTOC_LMS_SHIFT)
end_define

begin_define
define|#
directive|define
name|IXGBE_AUTOC_LMS_KX4_KX_KR_1G_AN
value|(0x6<< IXGBE_AUTOC_LMS_SHIFT)
end_define

begin_define
define|#
directive|define
name|IXGBE_AUTOC_LMS_KX4_KX_KR_SGMII
value|(0x7<< IXGBE_AUTOC_LMS_SHIFT)
end_define

begin_define
define|#
directive|define
name|IXGBE_AUTOC_LMS_MASK
value|(0x7<< IXGBE_AUTOC_LMS_SHIFT)
end_define

begin_define
define|#
directive|define
name|IXGBE_AUTOC_LMS_1G_LINK_NO_AN
value|(0x0<< IXGBE_AUTOC_LMS_SHIFT)
end_define

begin_define
define|#
directive|define
name|IXGBE_AUTOC_LMS_10G_LINK_NO_AN
value|(0x1<< IXGBE_AUTOC_LMS_SHIFT)
end_define

begin_define
define|#
directive|define
name|IXGBE_AUTOC_LMS_1G_AN
value|(0x2<< IXGBE_AUTOC_LMS_SHIFT)
end_define

begin_define
define|#
directive|define
name|IXGBE_AUTOC_LMS_KX4_AN
value|(0x4<< IXGBE_AUTOC_LMS_SHIFT)
end_define

begin_define
define|#
directive|define
name|IXGBE_AUTOC_LMS_KX4_AN_1G_AN
value|(0x6<< IXGBE_AUTOC_LMS_SHIFT)
end_define

begin_define
define|#
directive|define
name|IXGBE_AUTOC_LMS_ATTACH_TYPE
value|(0x7<< IXGBE_AUTOC_10G_PMA_PMD_SHIFT)
end_define

begin_define
define|#
directive|define
name|IXGBE_AUTOC_1G_PMA_PMD_MASK
value|0x00000200
end_define

begin_define
define|#
directive|define
name|IXGBE_AUTOC_1G_PMA_PMD_SHIFT
value|9
end_define

begin_define
define|#
directive|define
name|IXGBE_AUTOC_10G_PMA_PMD_MASK
value|0x00000180
end_define

begin_define
define|#
directive|define
name|IXGBE_AUTOC_10G_PMA_PMD_SHIFT
value|7
end_define

begin_define
define|#
directive|define
name|IXGBE_AUTOC_10G_XAUI
value|(0x0<< IXGBE_AUTOC_10G_PMA_PMD_SHIFT)
end_define

begin_define
define|#
directive|define
name|IXGBE_AUTOC_10G_KX4
value|(0x1<< IXGBE_AUTOC_10G_PMA_PMD_SHIFT)
end_define

begin_define
define|#
directive|define
name|IXGBE_AUTOC_10G_CX4
value|(0x2<< IXGBE_AUTOC_10G_PMA_PMD_SHIFT)
end_define

begin_define
define|#
directive|define
name|IXGBE_AUTOC_1G_BX
value|(0x0<< IXGBE_AUTOC_1G_PMA_PMD_SHIFT)
end_define

begin_define
define|#
directive|define
name|IXGBE_AUTOC_1G_KX
value|(0x1<< IXGBE_AUTOC_1G_PMA_PMD_SHIFT)
end_define

begin_define
define|#
directive|define
name|IXGBE_AUTOC_1G_SFI
value|(0x0<< IXGBE_AUTOC_1G_PMA_PMD_SHIFT)
end_define

begin_define
define|#
directive|define
name|IXGBE_AUTOC_1G_KX_BX
value|(0x1<< IXGBE_AUTOC_1G_PMA_PMD_SHIFT)
end_define

begin_define
define|#
directive|define
name|IXGBE_AUTOC2_UPPER_MASK
value|0xFFFF0000
end_define

begin_define
define|#
directive|define
name|IXGBE_AUTOC2_10G_SERIAL_PMA_PMD_MASK
value|0x00030000
end_define

begin_define
define|#
directive|define
name|IXGBE_AUTOC2_10G_SERIAL_PMA_PMD_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|IXGBE_AUTOC2_10G_KR
value|(0x0<< IXGBE_AUTOC2_10G_SERIAL_PMA_PMD_SHIFT)
end_define

begin_define
define|#
directive|define
name|IXGBE_AUTOC2_10G_XFI
value|(0x1<< IXGBE_AUTOC2_10G_SERIAL_PMA_PMD_SHIFT)
end_define

begin_define
define|#
directive|define
name|IXGBE_AUTOC2_10G_SFI
value|(0x2<< IXGBE_AUTOC2_10G_SERIAL_PMA_PMD_SHIFT)
end_define

begin_define
define|#
directive|define
name|IXGBE_AUTOC2_LINK_DISABLE_ON_D3_MASK
value|0x50000000
end_define

begin_define
define|#
directive|define
name|IXGBE_AUTOC2_LINK_DISABLE_MASK
value|0x70000000
end_define

begin_define
define|#
directive|define
name|IXGBE_MACC_FLU
value|0x00000001
end_define

begin_define
define|#
directive|define
name|IXGBE_MACC_FSV_10G
value|0x00030000
end_define

begin_define
define|#
directive|define
name|IXGBE_MACC_FS
value|0x00040000
end_define

begin_define
define|#
directive|define
name|IXGBE_MAC_RX2TX_LPBK
value|0x00000002
end_define

begin_comment
comment|/* Veto Bit definition */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MMNGC_MNG_VETO
value|0x00000001
end_define

begin_comment
comment|/* LINKS Bit Masks */
end_comment

begin_define
define|#
directive|define
name|IXGBE_LINKS_KX_AN_COMP
value|0x80000000
end_define

begin_define
define|#
directive|define
name|IXGBE_LINKS_UP
value|0x40000000
end_define

begin_define
define|#
directive|define
name|IXGBE_LINKS_SPEED
value|0x20000000
end_define

begin_define
define|#
directive|define
name|IXGBE_LINKS_MODE
value|0x18000000
end_define

begin_define
define|#
directive|define
name|IXGBE_LINKS_RX_MODE
value|0x06000000
end_define

begin_define
define|#
directive|define
name|IXGBE_LINKS_TX_MODE
value|0x01800000
end_define

begin_define
define|#
directive|define
name|IXGBE_LINKS_XGXS_EN
value|0x00400000
end_define

begin_define
define|#
directive|define
name|IXGBE_LINKS_SGMII_EN
value|0x02000000
end_define

begin_define
define|#
directive|define
name|IXGBE_LINKS_PCS_1G_EN
value|0x00200000
end_define

begin_define
define|#
directive|define
name|IXGBE_LINKS_1G_AN_EN
value|0x00100000
end_define

begin_define
define|#
directive|define
name|IXGBE_LINKS_KX_AN_IDLE
value|0x00080000
end_define

begin_define
define|#
directive|define
name|IXGBE_LINKS_1G_SYNC
value|0x00040000
end_define

begin_define
define|#
directive|define
name|IXGBE_LINKS_10G_ALIGN
value|0x00020000
end_define

begin_define
define|#
directive|define
name|IXGBE_LINKS_10G_LANE_SYNC
value|0x00017000
end_define

begin_define
define|#
directive|define
name|IXGBE_LINKS_TL_FAULT
value|0x00001000
end_define

begin_define
define|#
directive|define
name|IXGBE_LINKS_SIGNAL
value|0x00000F00
end_define

begin_define
define|#
directive|define
name|IXGBE_LINKS_SPEED_NON_STD
value|0x08000000
end_define

begin_define
define|#
directive|define
name|IXGBE_LINKS_SPEED_82599
value|0x30000000
end_define

begin_define
define|#
directive|define
name|IXGBE_LINKS_SPEED_10G_82599
value|0x30000000
end_define

begin_define
define|#
directive|define
name|IXGBE_LINKS_SPEED_1G_82599
value|0x20000000
end_define

begin_define
define|#
directive|define
name|IXGBE_LINKS_SPEED_100_82599
value|0x10000000
end_define

begin_define
define|#
directive|define
name|IXGBE_LINKS_SPEED_10_X550EM_A
value|0x00000000
end_define

begin_define
define|#
directive|define
name|IXGBE_LINK_UP_TIME
value|90
end_define

begin_comment
comment|/* 9.0 Seconds */
end_comment

begin_define
define|#
directive|define
name|IXGBE_AUTO_NEG_TIME
value|45
end_define

begin_comment
comment|/* 4.5 Seconds */
end_comment

begin_define
define|#
directive|define
name|IXGBE_LINKS2_AN_SUPPORTED
value|0x00000040
end_define

begin_comment
comment|/* PCS1GLSTA Bit Masks */
end_comment

begin_define
define|#
directive|define
name|IXGBE_PCS1GLSTA_LINK_OK
value|1
end_define

begin_define
define|#
directive|define
name|IXGBE_PCS1GLSTA_SYNK_OK
value|0x10
end_define

begin_define
define|#
directive|define
name|IXGBE_PCS1GLSTA_AN_COMPLETE
value|0x10000
end_define

begin_define
define|#
directive|define
name|IXGBE_PCS1GLSTA_AN_PAGE_RX
value|0x20000
end_define

begin_define
define|#
directive|define
name|IXGBE_PCS1GLSTA_AN_TIMED_OUT
value|0x40000
end_define

begin_define
define|#
directive|define
name|IXGBE_PCS1GLSTA_AN_REMOTE_FAULT
value|0x80000
end_define

begin_define
define|#
directive|define
name|IXGBE_PCS1GLSTA_AN_ERROR_RWS
value|0x100000
end_define

begin_define
define|#
directive|define
name|IXGBE_PCS1GANA_SYM_PAUSE
value|0x80
end_define

begin_define
define|#
directive|define
name|IXGBE_PCS1GANA_ASM_PAUSE
value|0x100
end_define

begin_comment
comment|/* PCS1GLCTL Bit Masks */
end_comment

begin_define
define|#
directive|define
name|IXGBE_PCS1GLCTL_AN_1G_TIMEOUT_EN
value|0x00040000
end_define

begin_comment
comment|/* PCS 1G autoneg to en */
end_comment

begin_define
define|#
directive|define
name|IXGBE_PCS1GLCTL_FLV_LINK_UP
value|1
end_define

begin_define
define|#
directive|define
name|IXGBE_PCS1GLCTL_FORCE_LINK
value|0x20
end_define

begin_define
define|#
directive|define
name|IXGBE_PCS1GLCTL_LOW_LINK_LATCH
value|0x40
end_define

begin_define
define|#
directive|define
name|IXGBE_PCS1GLCTL_AN_ENABLE
value|0x10000
end_define

begin_define
define|#
directive|define
name|IXGBE_PCS1GLCTL_AN_RESTART
value|0x20000
end_define

begin_comment
comment|/* ANLP1 Bit Masks */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ANLP1_PAUSE
value|0x0C00
end_define

begin_define
define|#
directive|define
name|IXGBE_ANLP1_SYM_PAUSE
value|0x0400
end_define

begin_define
define|#
directive|define
name|IXGBE_ANLP1_ASM_PAUSE
value|0x0800
end_define

begin_define
define|#
directive|define
name|IXGBE_ANLP1_AN_STATE_MASK
value|0x000f0000
end_define

begin_comment
comment|/* SW Semaphore Register bitmasks */
end_comment

begin_define
define|#
directive|define
name|IXGBE_SWSM_SMBI
value|0x00000001
end_define

begin_comment
comment|/* Driver Semaphore bit */
end_comment

begin_define
define|#
directive|define
name|IXGBE_SWSM_SWESMBI
value|0x00000002
end_define

begin_comment
comment|/* FW Semaphore bit */
end_comment

begin_define
define|#
directive|define
name|IXGBE_SWSM_WMNG
value|0x00000004
end_define

begin_comment
comment|/* Wake MNG Clock */
end_comment

begin_define
define|#
directive|define
name|IXGBE_SWFW_REGSMP
value|0x80000000
end_define

begin_comment
comment|/* Register Semaphore bit 31 */
end_comment

begin_comment
comment|/* SW_FW_SYNC/GSSR definitions */
end_comment

begin_define
define|#
directive|define
name|IXGBE_GSSR_EEP_SM
value|0x0001
end_define

begin_define
define|#
directive|define
name|IXGBE_GSSR_PHY0_SM
value|0x0002
end_define

begin_define
define|#
directive|define
name|IXGBE_GSSR_PHY1_SM
value|0x0004
end_define

begin_define
define|#
directive|define
name|IXGBE_GSSR_MAC_CSR_SM
value|0x0008
end_define

begin_define
define|#
directive|define
name|IXGBE_GSSR_FLASH_SM
value|0x0010
end_define

begin_define
define|#
directive|define
name|IXGBE_GSSR_NVM_UPDATE_SM
value|0x0200
end_define

begin_define
define|#
directive|define
name|IXGBE_GSSR_SW_MNG_SM
value|0x0400
end_define

begin_define
define|#
directive|define
name|IXGBE_GSSR_TOKEN_SM
value|0x40000000
end_define

begin_comment
comment|/* SW bit for shared access */
end_comment

begin_define
define|#
directive|define
name|IXGBE_GSSR_SHARED_I2C_SM
value|0x1806
end_define

begin_comment
comment|/* Wait for both phys and both I2Cs */
end_comment

begin_define
define|#
directive|define
name|IXGBE_GSSR_I2C_MASK
value|0x1800
end_define

begin_define
define|#
directive|define
name|IXGBE_GSSR_NVM_PHY_MASK
value|0xF
end_define

begin_comment
comment|/* FW Status register bitmask */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FWSTS_FWRI
value|0x00000200
end_define

begin_comment
comment|/* Firmware Reset Indication */
end_comment

begin_comment
comment|/* EEC Register */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EEC_SK
value|0x00000001
end_define

begin_comment
comment|/* EEPROM Clock */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EEC_CS
value|0x00000002
end_define

begin_comment
comment|/* EEPROM Chip Select */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EEC_DI
value|0x00000004
end_define

begin_comment
comment|/* EEPROM Data In */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EEC_DO
value|0x00000008
end_define

begin_comment
comment|/* EEPROM Data Out */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EEC_FWE_MASK
value|0x00000030
end_define

begin_comment
comment|/* FLASH Write Enable */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EEC_FWE_DIS
value|0x00000010
end_define

begin_comment
comment|/* Disable FLASH writes */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EEC_FWE_EN
value|0x00000020
end_define

begin_comment
comment|/* Enable FLASH writes */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EEC_FWE_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|IXGBE_EEC_REQ
value|0x00000040
end_define

begin_comment
comment|/* EEPROM Access Request */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EEC_GNT
value|0x00000080
end_define

begin_comment
comment|/* EEPROM Access Grant */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EEC_PRES
value|0x00000100
end_define

begin_comment
comment|/* EEPROM Present */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EEC_ARD
value|0x00000200
end_define

begin_comment
comment|/* EEPROM Auto Read Done */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EEC_FLUP
value|0x00800000
end_define

begin_comment
comment|/* Flash update command */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EEC_SEC1VAL
value|0x02000000
end_define

begin_comment
comment|/* Sector 1 Valid */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EEC_FLUDONE
value|0x04000000
end_define

begin_comment
comment|/* Flash update done */
end_comment

begin_comment
comment|/* EEPROM Addressing bits based on type (0-small, 1-large) */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EEC_ADDR_SIZE
value|0x00000400
end_define

begin_define
define|#
directive|define
name|IXGBE_EEC_SIZE
value|0x00007800
end_define

begin_comment
comment|/* EEPROM Size */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EERD_MAX_ADDR
value|0x00003FFF
end_define

begin_comment
comment|/* EERD alows 14 bits for addr. */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EEC_SIZE_SHIFT
value|11
end_define

begin_define
define|#
directive|define
name|IXGBE_EEPROM_WORD_SIZE_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|IXGBE_EEPROM_OPCODE_BITS
value|8
end_define

begin_comment
comment|/* FLA Register */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FLA_LOCKED
value|0x00000040
end_define

begin_comment
comment|/* Part Number String Length */
end_comment

begin_define
define|#
directive|define
name|IXGBE_PBANUM_LENGTH
value|11
end_define

begin_comment
comment|/* Checksum and EEPROM pointers */
end_comment

begin_define
define|#
directive|define
name|IXGBE_PBANUM_PTR_GUARD
value|0xFAFA
end_define

begin_define
define|#
directive|define
name|IXGBE_EEPROM_CHECKSUM
value|0x3F
end_define

begin_define
define|#
directive|define
name|IXGBE_EEPROM_SUM
value|0xBABA
end_define

begin_define
define|#
directive|define
name|IXGBE_EEPROM_CTRL_4
value|0x45
end_define

begin_define
define|#
directive|define
name|IXGBE_EE_CTRL_4_INST_ID
value|0x10
end_define

begin_define
define|#
directive|define
name|IXGBE_EE_CTRL_4_INST_ID_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|IXGBE_PCIE_ANALOG_PTR
value|0x03
end_define

begin_define
define|#
directive|define
name|IXGBE_ATLAS0_CONFIG_PTR
value|0x04
end_define

begin_define
define|#
directive|define
name|IXGBE_PHY_PTR
value|0x04
end_define

begin_define
define|#
directive|define
name|IXGBE_ATLAS1_CONFIG_PTR
value|0x05
end_define

begin_define
define|#
directive|define
name|IXGBE_OPTION_ROM_PTR
value|0x05
end_define

begin_define
define|#
directive|define
name|IXGBE_PCIE_GENERAL_PTR
value|0x06
end_define

begin_define
define|#
directive|define
name|IXGBE_PCIE_CONFIG0_PTR
value|0x07
end_define

begin_define
define|#
directive|define
name|IXGBE_PCIE_CONFIG1_PTR
value|0x08
end_define

begin_define
define|#
directive|define
name|IXGBE_CORE0_PTR
value|0x09
end_define

begin_define
define|#
directive|define
name|IXGBE_CORE1_PTR
value|0x0A
end_define

begin_define
define|#
directive|define
name|IXGBE_MAC0_PTR
value|0x0B
end_define

begin_define
define|#
directive|define
name|IXGBE_MAC1_PTR
value|0x0C
end_define

begin_define
define|#
directive|define
name|IXGBE_CSR0_CONFIG_PTR
value|0x0D
end_define

begin_define
define|#
directive|define
name|IXGBE_CSR1_CONFIG_PTR
value|0x0E
end_define

begin_define
define|#
directive|define
name|IXGBE_PCIE_ANALOG_PTR_X550
value|0x02
end_define

begin_define
define|#
directive|define
name|IXGBE_SHADOW_RAM_SIZE_X550
value|0x4000
end_define

begin_define
define|#
directive|define
name|IXGBE_IXGBE_PCIE_GENERAL_SIZE
value|0x24
end_define

begin_define
define|#
directive|define
name|IXGBE_PCIE_CONFIG_SIZE
value|0x08
end_define

begin_define
define|#
directive|define
name|IXGBE_EEPROM_LAST_WORD
value|0x41
end_define

begin_define
define|#
directive|define
name|IXGBE_FW_PTR
value|0x0F
end_define

begin_define
define|#
directive|define
name|IXGBE_PBANUM0_PTR
value|0x15
end_define

begin_define
define|#
directive|define
name|IXGBE_PBANUM1_PTR
value|0x16
end_define

begin_define
define|#
directive|define
name|IXGBE_ALT_MAC_ADDR_PTR
value|0x37
end_define

begin_define
define|#
directive|define
name|IXGBE_FREE_SPACE_PTR
value|0X3E
end_define

begin_define
define|#
directive|define
name|IXGBE_SAN_MAC_ADDR_PTR
value|0x28
end_define

begin_define
define|#
directive|define
name|IXGBE_DEVICE_CAPS
value|0x2C
end_define

begin_define
define|#
directive|define
name|IXGBE_82599_SERIAL_NUMBER_MAC_ADDR
value|0x11
end_define

begin_define
define|#
directive|define
name|IXGBE_X550_SERIAL_NUMBER_MAC_ADDR
value|0x04
end_define

begin_define
define|#
directive|define
name|IXGBE_PCIE_MSIX_82599_CAPS
value|0x72
end_define

begin_define
define|#
directive|define
name|IXGBE_MAX_MSIX_VECTORS_82599
value|0x40
end_define

begin_define
define|#
directive|define
name|IXGBE_PCIE_MSIX_82598_CAPS
value|0x62
end_define

begin_define
define|#
directive|define
name|IXGBE_MAX_MSIX_VECTORS_82598
value|0x13
end_define

begin_comment
comment|/* MSI-X capability fields masks */
end_comment

begin_define
define|#
directive|define
name|IXGBE_PCIE_MSIX_TBL_SZ_MASK
value|0x7FF
end_define

begin_comment
comment|/* Legacy EEPROM word offsets */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ISCSI_BOOT_CAPS
value|0x0033
end_define

begin_define
define|#
directive|define
name|IXGBE_ISCSI_SETUP_PORT_0
value|0x0030
end_define

begin_define
define|#
directive|define
name|IXGBE_ISCSI_SETUP_PORT_1
value|0x0034
end_define

begin_comment
comment|/* EEPROM Commands - SPI */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EEPROM_MAX_RETRY_SPI
value|5000
end_define

begin_comment
comment|/* Max wait 5ms for RDY signal */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EEPROM_STATUS_RDY_SPI
value|0x01
end_define

begin_define
define|#
directive|define
name|IXGBE_EEPROM_READ_OPCODE_SPI
value|0x03
end_define

begin_comment
comment|/* EEPROM read opcode */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EEPROM_WRITE_OPCODE_SPI
value|0x02
end_define

begin_comment
comment|/* EEPROM write opcode */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EEPROM_A8_OPCODE_SPI
value|0x08
end_define

begin_comment
comment|/* opcode bit-3 = addr bit-8 */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EEPROM_WREN_OPCODE_SPI
value|0x06
end_define

begin_comment
comment|/* EEPROM set Write Ena latch */
end_comment

begin_comment
comment|/* EEPROM reset Write Enable latch */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EEPROM_WRDI_OPCODE_SPI
value|0x04
end_define

begin_define
define|#
directive|define
name|IXGBE_EEPROM_RDSR_OPCODE_SPI
value|0x05
end_define

begin_comment
comment|/* EEPROM read Status reg */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EEPROM_WRSR_OPCODE_SPI
value|0x01
end_define

begin_comment
comment|/* EEPROM write Status reg */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EEPROM_ERASE4K_OPCODE_SPI
value|0x20
end_define

begin_comment
comment|/* EEPROM ERASE 4KB */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EEPROM_ERASE64K_OPCODE_SPI
value|0xD8
end_define

begin_comment
comment|/* EEPROM ERASE 64KB */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EEPROM_ERASE256_OPCODE_SPI
value|0xDB
end_define

begin_comment
comment|/* EEPROM ERASE 256B */
end_comment

begin_comment
comment|/* EEPROM Read Register */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EEPROM_RW_REG_DATA
value|16
end_define

begin_comment
comment|/* data offset in EEPROM read reg */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EEPROM_RW_REG_DONE
value|2
end_define

begin_comment
comment|/* Offset to READ done bit */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EEPROM_RW_REG_START
value|1
end_define

begin_comment
comment|/* First bit to start operation */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EEPROM_RW_ADDR_SHIFT
value|2
end_define

begin_comment
comment|/* Shift to the address bits */
end_comment

begin_define
define|#
directive|define
name|IXGBE_NVM_POLL_WRITE
value|1
end_define

begin_comment
comment|/* Flag for polling for wr complete */
end_comment

begin_define
define|#
directive|define
name|IXGBE_NVM_POLL_READ
value|0
end_define

begin_comment
comment|/* Flag for polling for rd complete */
end_comment

begin_define
define|#
directive|define
name|NVM_INIT_CTRL_3
value|0x38
end_define

begin_define
define|#
directive|define
name|NVM_INIT_CTRL_3_LPLU
value|0x8
end_define

begin_define
define|#
directive|define
name|NVM_INIT_CTRL_3_D10GMP_PORT0
value|0x40
end_define

begin_define
define|#
directive|define
name|NVM_INIT_CTRL_3_D10GMP_PORT1
value|0x100
end_define

begin_define
define|#
directive|define
name|IXGBE_ETH_LENGTH_OF_ADDRESS
value|6
end_define

begin_define
define|#
directive|define
name|IXGBE_EEPROM_PAGE_SIZE_MAX
value|128
end_define

begin_define
define|#
directive|define
name|IXGBE_EEPROM_RD_BUFFER_MAX_COUNT
value|256
end_define

begin_comment
comment|/* words rd in burst */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EEPROM_WR_BUFFER_MAX_COUNT
value|256
end_define

begin_comment
comment|/* words wr in burst */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EEPROM_CTRL_2
value|1
end_define

begin_comment
comment|/* EEPROM CTRL word 2 */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EEPROM_CCD_BIT
value|2
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|IXGBE_EEPROM_GRANT_ATTEMPTS
end_ifndef

begin_define
define|#
directive|define
name|IXGBE_EEPROM_GRANT_ATTEMPTS
value|1000
end_define

begin_comment
comment|/* EEPROM attempts to gain grant */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Number of 5 microseconds we wait for EERD read and  * EERW write to complete */
end_comment

begin_define
define|#
directive|define
name|IXGBE_EERD_EEWR_ATTEMPTS
value|100000
end_define

begin_comment
comment|/* # attempts we wait for flush update to complete */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FLUDONE_ATTEMPTS
value|20000
end_define

begin_define
define|#
directive|define
name|IXGBE_PCIE_CTRL2
value|0x5
end_define

begin_comment
comment|/* PCIe Control 2 Offset */
end_comment

begin_define
define|#
directive|define
name|IXGBE_PCIE_CTRL2_DUMMY_ENABLE
value|0x8
end_define

begin_comment
comment|/* Dummy Function Enable */
end_comment

begin_define
define|#
directive|define
name|IXGBE_PCIE_CTRL2_LAN_DISABLE
value|0x2
end_define

begin_comment
comment|/* LAN PCI Disable */
end_comment

begin_define
define|#
directive|define
name|IXGBE_PCIE_CTRL2_DISABLE_SELECT
value|0x1
end_define

begin_comment
comment|/* LAN Disable Select */
end_comment

begin_define
define|#
directive|define
name|IXGBE_SAN_MAC_ADDR_PORT0_OFFSET
value|0x0
end_define

begin_define
define|#
directive|define
name|IXGBE_SAN_MAC_ADDR_PORT1_OFFSET
value|0x3
end_define

begin_define
define|#
directive|define
name|IXGBE_DEVICE_CAPS_ALLOW_ANY_SFP
value|0x1
end_define

begin_define
define|#
directive|define
name|IXGBE_DEVICE_CAPS_FCOE_OFFLOADS
value|0x2
end_define

begin_define
define|#
directive|define
name|IXGBE_DEVICE_CAPS_NO_CROSSTALK_WR
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|IXGBE_FW_LESM_PARAMETERS_PTR
value|0x2
end_define

begin_define
define|#
directive|define
name|IXGBE_FW_LESM_STATE_1
value|0x1
end_define

begin_define
define|#
directive|define
name|IXGBE_FW_LESM_STATE_ENABLED
value|0x8000
end_define

begin_comment
comment|/* LESM Enable bit */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FW_PASSTHROUGH_PATCH_CONFIG_PTR
value|0x4
end_define

begin_define
define|#
directive|define
name|IXGBE_FW_PATCH_VERSION_4
value|0x7
end_define

begin_define
define|#
directive|define
name|IXGBE_FCOE_IBA_CAPS_BLK_PTR
value|0x33
end_define

begin_comment
comment|/* iSCSI/FCOE block */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FCOE_IBA_CAPS_FCOE
value|0x20
end_define

begin_comment
comment|/* FCOE flags */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ISCSI_FCOE_BLK_PTR
value|0x17
end_define

begin_comment
comment|/* iSCSI/FCOE block */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ISCSI_FCOE_FLAGS_OFFSET
value|0x0
end_define

begin_comment
comment|/* FCOE flags */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ISCSI_FCOE_FLAGS_ENABLE
value|0x1
end_define

begin_comment
comment|/* FCOE flags enable bit */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ALT_SAN_MAC_ADDR_BLK_PTR
value|0x27
end_define

begin_comment
comment|/* Alt. SAN MAC block */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ALT_SAN_MAC_ADDR_CAPS_OFFSET
value|0x0
end_define

begin_comment
comment|/* Alt SAN MAC capability */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ALT_SAN_MAC_ADDR_PORT0_OFFSET
value|0x1
end_define

begin_comment
comment|/* Alt SAN MAC 0 offset */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ALT_SAN_MAC_ADDR_PORT1_OFFSET
value|0x4
end_define

begin_comment
comment|/* Alt SAN MAC 1 offset */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ALT_SAN_MAC_ADDR_WWNN_OFFSET
value|0x7
end_define

begin_comment
comment|/* Alt WWNN prefix offset */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ALT_SAN_MAC_ADDR_WWPN_OFFSET
value|0x8
end_define

begin_comment
comment|/* Alt WWPN prefix offset */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ALT_SAN_MAC_ADDR_CAPS_SANMAC
value|0x0
end_define

begin_comment
comment|/* Alt SAN MAC exists */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ALT_SAN_MAC_ADDR_CAPS_ALTWWN
value|0x1
end_define

begin_comment
comment|/* Alt WWN base exists */
end_comment

begin_comment
comment|/* FW header offset */
end_comment

begin_define
define|#
directive|define
name|IXGBE_X540_FW_PASSTHROUGH_PATCH_CONFIG_PTR
value|0x4
end_define

begin_define
define|#
directive|define
name|IXGBE_X540_FW_MODULE_MASK
value|0x7FFF
end_define

begin_comment
comment|/* 4KB multiplier */
end_comment

begin_define
define|#
directive|define
name|IXGBE_X540_FW_MODULE_LENGTH
value|0x1000
end_define

begin_comment
comment|/* version word 2 (month& day) */
end_comment

begin_define
define|#
directive|define
name|IXGBE_X540_FW_PATCH_VERSION_2
value|0x5
end_define

begin_comment
comment|/* version word 3 (silicon compatibility& year) */
end_comment

begin_define
define|#
directive|define
name|IXGBE_X540_FW_PATCH_VERSION_3
value|0x6
end_define

begin_comment
comment|/* version word 4 (major& minor numbers) */
end_comment

begin_define
define|#
directive|define
name|IXGBE_X540_FW_PATCH_VERSION_4
value|0x7
end_define

begin_define
define|#
directive|define
name|IXGBE_DEVICE_CAPS_WOL_PORT0_1
value|0x4
end_define

begin_comment
comment|/* WoL supported on ports 0& 1 */
end_comment

begin_define
define|#
directive|define
name|IXGBE_DEVICE_CAPS_WOL_PORT0
value|0x8
end_define

begin_comment
comment|/* WoL supported on port 0 */
end_comment

begin_define
define|#
directive|define
name|IXGBE_DEVICE_CAPS_WOL_MASK
value|0xC
end_define

begin_comment
comment|/* Mask for WoL capabilities */
end_comment

begin_comment
comment|/* PCI Bus Info */
end_comment

begin_define
define|#
directive|define
name|IXGBE_PCI_DEVICE_STATUS
value|0xAA
end_define

begin_define
define|#
directive|define
name|IXGBE_PCI_DEVICE_STATUS_TRANSACTION_PENDING
value|0x0020
end_define

begin_define
define|#
directive|define
name|IXGBE_PCI_LINK_STATUS
value|0xB2
end_define

begin_define
define|#
directive|define
name|IXGBE_PCI_DEVICE_CONTROL2
value|0xC8
end_define

begin_define
define|#
directive|define
name|IXGBE_PCI_LINK_WIDTH
value|0x3F0
end_define

begin_define
define|#
directive|define
name|IXGBE_PCI_LINK_WIDTH_1
value|0x10
end_define

begin_define
define|#
directive|define
name|IXGBE_PCI_LINK_WIDTH_2
value|0x20
end_define

begin_define
define|#
directive|define
name|IXGBE_PCI_LINK_WIDTH_4
value|0x40
end_define

begin_define
define|#
directive|define
name|IXGBE_PCI_LINK_WIDTH_8
value|0x80
end_define

begin_define
define|#
directive|define
name|IXGBE_PCI_LINK_SPEED
value|0xF
end_define

begin_define
define|#
directive|define
name|IXGBE_PCI_LINK_SPEED_2500
value|0x1
end_define

begin_define
define|#
directive|define
name|IXGBE_PCI_LINK_SPEED_5000
value|0x2
end_define

begin_define
define|#
directive|define
name|IXGBE_PCI_LINK_SPEED_8000
value|0x3
end_define

begin_define
define|#
directive|define
name|IXGBE_PCI_HEADER_TYPE_REGISTER
value|0x0E
end_define

begin_define
define|#
directive|define
name|IXGBE_PCI_HEADER_TYPE_MULTIFUNC
value|0x80
end_define

begin_define
define|#
directive|define
name|IXGBE_PCI_DEVICE_CONTROL2_16ms
value|0x0005
end_define

begin_define
define|#
directive|define
name|IXGBE_PCIDEVCTRL2_TIMEO_MASK
value|0xf
end_define

begin_define
define|#
directive|define
name|IXGBE_PCIDEVCTRL2_16_32ms_def
value|0x0
end_define

begin_define
define|#
directive|define
name|IXGBE_PCIDEVCTRL2_50_100us
value|0x1
end_define

begin_define
define|#
directive|define
name|IXGBE_PCIDEVCTRL2_1_2ms
value|0x2
end_define

begin_define
define|#
directive|define
name|IXGBE_PCIDEVCTRL2_16_32ms
value|0x5
end_define

begin_define
define|#
directive|define
name|IXGBE_PCIDEVCTRL2_65_130ms
value|0x6
end_define

begin_define
define|#
directive|define
name|IXGBE_PCIDEVCTRL2_260_520ms
value|0x9
end_define

begin_define
define|#
directive|define
name|IXGBE_PCIDEVCTRL2_1_2s
value|0xa
end_define

begin_define
define|#
directive|define
name|IXGBE_PCIDEVCTRL2_4_8s
value|0xd
end_define

begin_define
define|#
directive|define
name|IXGBE_PCIDEVCTRL2_17_34s
value|0xe
end_define

begin_comment
comment|/* Number of 100 microseconds we wait for PCI Express master disable */
end_comment

begin_define
define|#
directive|define
name|IXGBE_PCI_MASTER_DISABLE_TIMEOUT
value|800
end_define

begin_comment
comment|/* Check whether address is multicast. This is little-endian specific check.*/
end_comment

begin_define
define|#
directive|define
name|IXGBE_IS_MULTICAST
parameter_list|(
name|Address
parameter_list|)
define|\
value|(bool)(((u8 *)(Address))[0]& ((u8)0x01))
end_define

begin_comment
comment|/* Check whether an address is broadcast. */
end_comment

begin_define
define|#
directive|define
name|IXGBE_IS_BROADCAST
parameter_list|(
name|Address
parameter_list|)
define|\
value|((((u8 *)(Address))[0] == ((u8)0xff))&& \ 		(((u8 *)(Address))[1] == ((u8)0xff)))
end_define

begin_comment
comment|/* RAH */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RAH_VIND_MASK
value|0x003C0000
end_define

begin_define
define|#
directive|define
name|IXGBE_RAH_VIND_SHIFT
value|18
end_define

begin_define
define|#
directive|define
name|IXGBE_RAH_AV
value|0x80000000
end_define

begin_define
define|#
directive|define
name|IXGBE_CLEAR_VMDQ_ALL
value|0xFFFFFFFF
end_define

begin_comment
comment|/* Header split receive */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RFCTL_ISCSI_DIS
value|0x00000001
end_define

begin_define
define|#
directive|define
name|IXGBE_RFCTL_ISCSI_DWC_MASK
value|0x0000003E
end_define

begin_define
define|#
directive|define
name|IXGBE_RFCTL_ISCSI_DWC_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|IXGBE_RFCTL_RSC_DIS
value|0x00000020
end_define

begin_define
define|#
directive|define
name|IXGBE_RFCTL_NFSW_DIS
value|0x00000040
end_define

begin_define
define|#
directive|define
name|IXGBE_RFCTL_NFSR_DIS
value|0x00000080
end_define

begin_define
define|#
directive|define
name|IXGBE_RFCTL_NFS_VER_MASK
value|0x00000300
end_define

begin_define
define|#
directive|define
name|IXGBE_RFCTL_NFS_VER_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|IXGBE_RFCTL_NFS_VER_2
value|0
end_define

begin_define
define|#
directive|define
name|IXGBE_RFCTL_NFS_VER_3
value|1
end_define

begin_define
define|#
directive|define
name|IXGBE_RFCTL_NFS_VER_4
value|2
end_define

begin_define
define|#
directive|define
name|IXGBE_RFCTL_IPV6_DIS
value|0x00000400
end_define

begin_define
define|#
directive|define
name|IXGBE_RFCTL_IPV6_XSUM_DIS
value|0x00000800
end_define

begin_define
define|#
directive|define
name|IXGBE_RFCTL_IPFRSP_DIS
value|0x00004000
end_define

begin_define
define|#
directive|define
name|IXGBE_RFCTL_IPV6_EX_DIS
value|0x00010000
end_define

begin_define
define|#
directive|define
name|IXGBE_RFCTL_NEW_IPV6_EXT_DIS
value|0x00020000
end_define

begin_comment
comment|/* Transmit Config masks */
end_comment

begin_define
define|#
directive|define
name|IXGBE_TXDCTL_ENABLE
value|0x02000000
end_define

begin_comment
comment|/* Ena specific Tx Queue */
end_comment

begin_define
define|#
directive|define
name|IXGBE_TXDCTL_SWFLSH
value|0x04000000
end_define

begin_comment
comment|/* Tx Desc. wr-bk flushing */
end_comment

begin_define
define|#
directive|define
name|IXGBE_TXDCTL_WTHRESH_SHIFT
value|16
end_define

begin_comment
comment|/* shift to WTHRESH bits */
end_comment

begin_comment
comment|/* Enable short packet padding to 64 bytes */
end_comment

begin_define
define|#
directive|define
name|IXGBE_TX_PAD_ENABLE
value|0x00000400
end_define

begin_define
define|#
directive|define
name|IXGBE_JUMBO_FRAME_ENABLE
value|0x00000004
end_define

begin_comment
comment|/* Allow jumbo frames */
end_comment

begin_comment
comment|/* This allows for 16K packets + 4k for vlan */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MAX_FRAME_SZ
value|0x40040000
end_define

begin_define
define|#
directive|define
name|IXGBE_TDWBAL_HEAD_WB_ENABLE
value|0x1
end_define

begin_comment
comment|/* Tx head write-back enable */
end_comment

begin_define
define|#
directive|define
name|IXGBE_TDWBAL_SEQNUM_WB_ENABLE
value|0x2
end_define

begin_comment
comment|/* Tx seq# write-back enable */
end_comment

begin_comment
comment|/* Receive Config masks */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXCTRL_RXEN
value|0x00000001
end_define

begin_comment
comment|/* Enable Receiver */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXCTRL_DMBYPS
value|0x00000002
end_define

begin_comment
comment|/* Desc Monitor Bypass */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXDCTL_ENABLE
value|0x02000000
end_define

begin_comment
comment|/* Ena specific Rx Queue */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXDCTL_SWFLSH
value|0x04000000
end_define

begin_comment
comment|/* Rx Desc wr-bk flushing */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXDCTL_RLPMLMASK
value|0x00003FFF
end_define

begin_comment
comment|/* X540 supported only */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXDCTL_RLPML_EN
value|0x00008000
end_define

begin_define
define|#
directive|define
name|IXGBE_RXDCTL_VME
value|0x40000000
end_define

begin_comment
comment|/* VLAN mode enable */
end_comment

begin_define
define|#
directive|define
name|IXGBE_TSAUXC_EN_CLK
value|0x00000004
end_define

begin_define
define|#
directive|define
name|IXGBE_TSAUXC_SYNCLK
value|0x00000008
end_define

begin_define
define|#
directive|define
name|IXGBE_TSAUXC_SDP0_INT
value|0x00000040
end_define

begin_define
define|#
directive|define
name|IXGBE_TSAUXC_EN_TT0
value|0x00000001
end_define

begin_define
define|#
directive|define
name|IXGBE_TSAUXC_EN_TT1
value|0x00000002
end_define

begin_define
define|#
directive|define
name|IXGBE_TSAUXC_ST0
value|0x00000010
end_define

begin_define
define|#
directive|define
name|IXGBE_TSAUXC_DISABLE_SYSTIME
value|0x80000000
end_define

begin_define
define|#
directive|define
name|IXGBE_TSSDP_TS_SDP0_SEL_MASK
value|0x000000C0
end_define

begin_define
define|#
directive|define
name|IXGBE_TSSDP_TS_SDP0_CLK0
value|0x00000080
end_define

begin_define
define|#
directive|define
name|IXGBE_TSSDP_TS_SDP0_EN
value|0x00000100
end_define

begin_define
define|#
directive|define
name|IXGBE_TSYNCTXCTL_VALID
value|0x00000001
end_define

begin_comment
comment|/* Tx timestamp valid */
end_comment

begin_define
define|#
directive|define
name|IXGBE_TSYNCTXCTL_ENABLED
value|0x00000010
end_define

begin_comment
comment|/* Tx timestamping enabled */
end_comment

begin_define
define|#
directive|define
name|IXGBE_TSYNCRXCTL_VALID
value|0x00000001
end_define

begin_comment
comment|/* Rx timestamp valid */
end_comment

begin_define
define|#
directive|define
name|IXGBE_TSYNCRXCTL_TYPE_MASK
value|0x0000000E
end_define

begin_comment
comment|/* Rx type mask */
end_comment

begin_define
define|#
directive|define
name|IXGBE_TSYNCRXCTL_TYPE_L2_V2
value|0x00
end_define

begin_define
define|#
directive|define
name|IXGBE_TSYNCRXCTL_TYPE_L4_V1
value|0x02
end_define

begin_define
define|#
directive|define
name|IXGBE_TSYNCRXCTL_TYPE_L2_L4_V2
value|0x04
end_define

begin_define
define|#
directive|define
name|IXGBE_TSYNCRXCTL_TYPE_ALL
value|0x08
end_define

begin_define
define|#
directive|define
name|IXGBE_TSYNCRXCTL_TYPE_EVENT_V2
value|0x0A
end_define

begin_define
define|#
directive|define
name|IXGBE_TSYNCRXCTL_ENABLED
value|0x00000010
end_define

begin_comment
comment|/* Rx Timestamping enabled */
end_comment

begin_define
define|#
directive|define
name|IXGBE_TSYNCRXCTL_TSIP_UT_EN
value|0x00800000
end_define

begin_comment
comment|/* Rx Timestamp in Packet */
end_comment

begin_define
define|#
directive|define
name|IXGBE_TSYNCRXCTL_TSIP_UP_MASK
value|0xFF000000
end_define

begin_comment
comment|/* Rx Timestamp UP Mask */
end_comment

begin_define
define|#
directive|define
name|IXGBE_TSIM_SYS_WRAP
value|0x00000001
end_define

begin_define
define|#
directive|define
name|IXGBE_TSIM_TXTS
value|0x00000002
end_define

begin_define
define|#
directive|define
name|IXGBE_TSIM_TADJ
value|0x00000080
end_define

begin_define
define|#
directive|define
name|IXGBE_TSICR_SYS_WRAP
value|IXGBE_TSIM_SYS_WRAP
end_define

begin_define
define|#
directive|define
name|IXGBE_TSICR_TXTS
value|IXGBE_TSIM_TXTS
end_define

begin_define
define|#
directive|define
name|IXGBE_TSICR_TADJ
value|IXGBE_TSIM_TADJ
end_define

begin_define
define|#
directive|define
name|IXGBE_RXMTRL_V1_CTRLT_MASK
value|0x000000FF
end_define

begin_define
define|#
directive|define
name|IXGBE_RXMTRL_V1_SYNC_MSG
value|0x00
end_define

begin_define
define|#
directive|define
name|IXGBE_RXMTRL_V1_DELAY_REQ_MSG
value|0x01
end_define

begin_define
define|#
directive|define
name|IXGBE_RXMTRL_V1_FOLLOWUP_MSG
value|0x02
end_define

begin_define
define|#
directive|define
name|IXGBE_RXMTRL_V1_DELAY_RESP_MSG
value|0x03
end_define

begin_define
define|#
directive|define
name|IXGBE_RXMTRL_V1_MGMT_MSG
value|0x04
end_define

begin_define
define|#
directive|define
name|IXGBE_RXMTRL_V2_MSGID_MASK
value|0x0000FF00
end_define

begin_define
define|#
directive|define
name|IXGBE_RXMTRL_V2_SYNC_MSG
value|0x0000
end_define

begin_define
define|#
directive|define
name|IXGBE_RXMTRL_V2_DELAY_REQ_MSG
value|0x0100
end_define

begin_define
define|#
directive|define
name|IXGBE_RXMTRL_V2_PDELAY_REQ_MSG
value|0x0200
end_define

begin_define
define|#
directive|define
name|IXGBE_RXMTRL_V2_PDELAY_RESP_MSG
value|0x0300
end_define

begin_define
define|#
directive|define
name|IXGBE_RXMTRL_V2_FOLLOWUP_MSG
value|0x0800
end_define

begin_define
define|#
directive|define
name|IXGBE_RXMTRL_V2_DELAY_RESP_MSG
value|0x0900
end_define

begin_define
define|#
directive|define
name|IXGBE_RXMTRL_V2_PDELAY_FOLLOWUP_MSG
value|0x0A00
end_define

begin_define
define|#
directive|define
name|IXGBE_RXMTRL_V2_ANNOUNCE_MSG
value|0x0B00
end_define

begin_define
define|#
directive|define
name|IXGBE_RXMTRL_V2_SIGNALLING_MSG
value|0x0C00
end_define

begin_define
define|#
directive|define
name|IXGBE_RXMTRL_V2_MGMT_MSG
value|0x0D00
end_define

begin_define
define|#
directive|define
name|IXGBE_FCTRL_SBP
value|0x00000002
end_define

begin_comment
comment|/* Store Bad Packet */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FCTRL_MPE
value|0x00000100
end_define

begin_comment
comment|/* Multicast Promiscuous Ena*/
end_comment

begin_define
define|#
directive|define
name|IXGBE_FCTRL_UPE
value|0x00000200
end_define

begin_comment
comment|/* Unicast Promiscuous Ena */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FCTRL_BAM
value|0x00000400
end_define

begin_comment
comment|/* Broadcast Accept Mode */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FCTRL_PMCF
value|0x00001000
end_define

begin_comment
comment|/* Pass MAC Control Frames */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FCTRL_DPF
value|0x00002000
end_define

begin_comment
comment|/* Discard Pause Frame */
end_comment

begin_comment
comment|/* Receive Priority Flow Control Enable */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FCTRL_RPFCE
value|0x00004000
end_define

begin_define
define|#
directive|define
name|IXGBE_FCTRL_RFCE
value|0x00008000
end_define

begin_comment
comment|/* Receive Flow Control Ena */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MFLCN_PMCF
value|0x00000001
end_define

begin_comment
comment|/* Pass MAC Control Frames */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MFLCN_DPF
value|0x00000002
end_define

begin_comment
comment|/* Discard Pause Frame */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MFLCN_RPFCE
value|0x00000004
end_define

begin_comment
comment|/* Receive Priority FC Enable */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MFLCN_RFCE
value|0x00000008
end_define

begin_comment
comment|/* Receive FC Enable */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MFLCN_RPFCE_MASK
value|0x00000FF4
end_define

begin_comment
comment|/* Rx Priority FC bitmap mask */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MFLCN_RPFCE_SHIFT
value|4
end_define

begin_comment
comment|/* Rx Priority FC bitmap shift */
end_comment

begin_comment
comment|/* Multiple Receive Queue Control */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MRQC_RSSEN
value|0x00000001
end_define

begin_comment
comment|/* RSS Enable */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MRQC_MRQE_MASK
value|0xF
end_define

begin_comment
comment|/* Bits 3:0 */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MRQC_RT8TCEN
value|0x00000002
end_define

begin_comment
comment|/* 8 TC no RSS */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MRQC_RT4TCEN
value|0x00000003
end_define

begin_comment
comment|/* 4 TC no RSS */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MRQC_RTRSS8TCEN
value|0x00000004
end_define

begin_comment
comment|/* 8 TC w/ RSS */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MRQC_RTRSS4TCEN
value|0x00000005
end_define

begin_comment
comment|/* 4 TC w/ RSS */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MRQC_VMDQEN
value|0x00000008
end_define

begin_comment
comment|/* VMDq2 64 pools no RSS */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MRQC_VMDQRSS32EN
value|0x0000000A
end_define

begin_comment
comment|/* VMDq2 32 pools w/ RSS */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MRQC_VMDQRSS64EN
value|0x0000000B
end_define

begin_comment
comment|/* VMDq2 64 pools w/ RSS */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MRQC_VMDQRT8TCEN
value|0x0000000C
end_define

begin_comment
comment|/* VMDq2/RT 16 pool 8 TC */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MRQC_VMDQRT4TCEN
value|0x0000000D
end_define

begin_comment
comment|/* VMDq2/RT 32 pool 4 TC */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MRQC_L3L4TXSWEN
value|0x00008000
end_define

begin_comment
comment|/* Enable L3/L4 Tx switch */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MRQC_RSS_FIELD_MASK
value|0xFFFF0000
end_define

begin_define
define|#
directive|define
name|IXGBE_MRQC_RSS_FIELD_IPV4_TCP
value|0x00010000
end_define

begin_define
define|#
directive|define
name|IXGBE_MRQC_RSS_FIELD_IPV4
value|0x00020000
end_define

begin_define
define|#
directive|define
name|IXGBE_MRQC_RSS_FIELD_IPV6_EX_TCP
value|0x00040000
end_define

begin_define
define|#
directive|define
name|IXGBE_MRQC_RSS_FIELD_IPV6_EX
value|0x00080000
end_define

begin_define
define|#
directive|define
name|IXGBE_MRQC_RSS_FIELD_IPV6
value|0x00100000
end_define

begin_define
define|#
directive|define
name|IXGBE_MRQC_RSS_FIELD_IPV6_TCP
value|0x00200000
end_define

begin_define
define|#
directive|define
name|IXGBE_MRQC_RSS_FIELD_IPV4_UDP
value|0x00400000
end_define

begin_define
define|#
directive|define
name|IXGBE_MRQC_RSS_FIELD_IPV6_UDP
value|0x00800000
end_define

begin_define
define|#
directive|define
name|IXGBE_MRQC_RSS_FIELD_IPV6_EX_UDP
value|0x01000000
end_define

begin_define
define|#
directive|define
name|IXGBE_MRQC_MULTIPLE_RSS
value|0x00002000
end_define

begin_define
define|#
directive|define
name|IXGBE_MRQC_L3L4TXSWEN
value|0x00008000
end_define

begin_comment
comment|/* Queue Drop Enable */
end_comment

begin_define
define|#
directive|define
name|IXGBE_QDE_ENABLE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|IXGBE_QDE_HIDE_VLAN
value|0x00000002
end_define

begin_define
define|#
directive|define
name|IXGBE_QDE_IDX_MASK
value|0x00007F00
end_define

begin_define
define|#
directive|define
name|IXGBE_QDE_IDX_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|IXGBE_QDE_WRITE
value|0x00010000
end_define

begin_define
define|#
directive|define
name|IXGBE_QDE_READ
value|0x00020000
end_define

begin_define
define|#
directive|define
name|IXGBE_TXD_POPTS_IXSM
value|0x01
end_define

begin_comment
comment|/* Insert IP checksum */
end_comment

begin_define
define|#
directive|define
name|IXGBE_TXD_POPTS_TXSM
value|0x02
end_define

begin_comment
comment|/* Insert TCP/UDP checksum */
end_comment

begin_define
define|#
directive|define
name|IXGBE_TXD_CMD_EOP
value|0x01000000
end_define

begin_comment
comment|/* End of Packet */
end_comment

begin_define
define|#
directive|define
name|IXGBE_TXD_CMD_IFCS
value|0x02000000
end_define

begin_comment
comment|/* Insert FCS (Ethernet CRC) */
end_comment

begin_define
define|#
directive|define
name|IXGBE_TXD_CMD_IC
value|0x04000000
end_define

begin_comment
comment|/* Insert Checksum */
end_comment

begin_define
define|#
directive|define
name|IXGBE_TXD_CMD_RS
value|0x08000000
end_define

begin_comment
comment|/* Report Status */
end_comment

begin_define
define|#
directive|define
name|IXGBE_TXD_CMD_DEXT
value|0x20000000
end_define

begin_comment
comment|/* Desc extension (0 = legacy) */
end_comment

begin_define
define|#
directive|define
name|IXGBE_TXD_CMD_VLE
value|0x40000000
end_define

begin_comment
comment|/* Add VLAN tag */
end_comment

begin_define
define|#
directive|define
name|IXGBE_TXD_STAT_DD
value|0x00000001
end_define

begin_comment
comment|/* Descriptor Done */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXDADV_IPSEC_STATUS_SECP
value|0x00020000
end_define

begin_define
define|#
directive|define
name|IXGBE_RXDADV_IPSEC_ERROR_INVALID_PROTOCOL
value|0x08000000
end_define

begin_define
define|#
directive|define
name|IXGBE_RXDADV_IPSEC_ERROR_INVALID_LENGTH
value|0x10000000
end_define

begin_define
define|#
directive|define
name|IXGBE_RXDADV_IPSEC_ERROR_AUTH_FAILED
value|0x18000000
end_define

begin_define
define|#
directive|define
name|IXGBE_RXDADV_IPSEC_ERROR_BIT_MASK
value|0x18000000
end_define

begin_comment
comment|/* Multiple Transmit Queue Command Register */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MTQC_RT_ENA
value|0x1
end_define

begin_comment
comment|/* DCB Enable */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MTQC_VT_ENA
value|0x2
end_define

begin_comment
comment|/* VMDQ2 Enable */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MTQC_64Q_1PB
value|0x0
end_define

begin_comment
comment|/* 64 queues 1 pack buffer */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MTQC_32VF
value|0x8
end_define

begin_comment
comment|/* 4 TX Queues per pool w/32VF's */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MTQC_64VF
value|0x4
end_define

begin_comment
comment|/* 2 TX Queues per pool w/64VF's */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MTQC_4TC_4TQ
value|0x8
end_define

begin_comment
comment|/* 4 TC if RT_ENA and VT_ENA */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MTQC_8TC_8TQ
value|0xC
end_define

begin_comment
comment|/* 8 TC if RT_ENA or 8 TQ if VT_ENA */
end_comment

begin_comment
comment|/* Receive Descriptor bit definitions */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXD_STAT_DD
value|0x01
end_define

begin_comment
comment|/* Descriptor Done */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXD_STAT_EOP
value|0x02
end_define

begin_comment
comment|/* End of Packet */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXD_STAT_FLM
value|0x04
end_define

begin_comment
comment|/* FDir Match */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXD_STAT_VP
value|0x08
end_define

begin_comment
comment|/* IEEE VLAN Packet */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXDADV_NEXTP_MASK
value|0x000FFFF0
end_define

begin_comment
comment|/* Next Descriptor Index */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXDADV_NEXTP_SHIFT
value|0x00000004
end_define

begin_define
define|#
directive|define
name|IXGBE_RXD_STAT_UDPCS
value|0x10
end_define

begin_comment
comment|/* UDP xsum calculated */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXD_STAT_L4CS
value|0x20
end_define

begin_comment
comment|/* L4 xsum calculated */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXD_STAT_IPCS
value|0x40
end_define

begin_comment
comment|/* IP xsum calculated */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXD_STAT_PIF
value|0x80
end_define

begin_comment
comment|/* passed in-exact filter */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXD_STAT_CRCV
value|0x100
end_define

begin_comment
comment|/* Speculative CRC Valid */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXD_STAT_OUTERIPCS
value|0x100
end_define

begin_comment
comment|/* Cloud IP xsum calculated */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXD_STAT_VEXT
value|0x200
end_define

begin_comment
comment|/* 1st VLAN found */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXD_STAT_UDPV
value|0x400
end_define

begin_comment
comment|/* Valid UDP checksum */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXD_STAT_DYNINT
value|0x800
end_define

begin_comment
comment|/* Pkt caused INT via DYNINT */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXD_STAT_LLINT
value|0x800
end_define

begin_comment
comment|/* Pkt caused Low Latency Interrupt */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXD_STAT_TSIP
value|0x08000
end_define

begin_comment
comment|/* Time Stamp in packet buffer */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXD_STAT_TS
value|0x10000
end_define

begin_comment
comment|/* Time Stamp */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXD_STAT_SECP
value|0x20000
end_define

begin_comment
comment|/* Security Processing */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXD_STAT_LB
value|0x40000
end_define

begin_comment
comment|/* Loopback Status */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXD_STAT_ACK
value|0x8000
end_define

begin_comment
comment|/* ACK Packet indication */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXD_ERR_CE
value|0x01
end_define

begin_comment
comment|/* CRC Error */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXD_ERR_LE
value|0x02
end_define

begin_comment
comment|/* Length Error */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXD_ERR_PE
value|0x08
end_define

begin_comment
comment|/* Packet Error */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXD_ERR_OSE
value|0x10
end_define

begin_comment
comment|/* Oversize Error */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXD_ERR_USE
value|0x20
end_define

begin_comment
comment|/* Undersize Error */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXD_ERR_TCPE
value|0x40
end_define

begin_comment
comment|/* TCP/UDP Checksum Error */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXD_ERR_IPE
value|0x80
end_define

begin_comment
comment|/* IP Checksum Error */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXDADV_ERR_MASK
value|0xfff00000
end_define

begin_comment
comment|/* RDESC.ERRORS mask */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXDADV_ERR_SHIFT
value|20
end_define

begin_comment
comment|/* RDESC.ERRORS shift */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXDADV_ERR_OUTERIPER
value|0x04000000
end_define

begin_comment
comment|/* CRC IP Header error */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXDADV_ERR_RXE
value|0x20000000
end_define

begin_comment
comment|/* Any MAC Error */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXDADV_ERR_FCEOFE
value|0x80000000
end_define

begin_comment
comment|/* FCEOFe/IPE */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXDADV_ERR_FCERR
value|0x00700000
end_define

begin_comment
comment|/* FCERR/FDIRERR */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXDADV_ERR_FDIR_LEN
value|0x00100000
end_define

begin_comment
comment|/* FDIR Length error */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXDADV_ERR_FDIR_DROP
value|0x00200000
end_define

begin_comment
comment|/* FDIR Drop error */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXDADV_ERR_FDIR_COLL
value|0x00400000
end_define

begin_comment
comment|/* FDIR Collision error */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXDADV_ERR_HBO
value|0x00800000
end_define

begin_comment
comment|/*Header Buffer Overflow */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXDADV_ERR_CE
value|0x01000000
end_define

begin_comment
comment|/* CRC Error */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXDADV_ERR_LE
value|0x02000000
end_define

begin_comment
comment|/* Length Error */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXDADV_ERR_PE
value|0x08000000
end_define

begin_comment
comment|/* Packet Error */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXDADV_ERR_OSE
value|0x10000000
end_define

begin_comment
comment|/* Oversize Error */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXDADV_ERR_USE
value|0x20000000
end_define

begin_comment
comment|/* Undersize Error */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXDADV_ERR_TCPE
value|0x40000000
end_define

begin_comment
comment|/* TCP/UDP Checksum Error */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXDADV_ERR_IPE
value|0x80000000
end_define

begin_comment
comment|/* IP Checksum Error */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXD_VLAN_ID_MASK
value|0x0FFF
end_define

begin_comment
comment|/* VLAN ID is in lower 12 bits */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXD_PRI_MASK
value|0xE000
end_define

begin_comment
comment|/* Priority is in upper 3 bits */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXD_PRI_SHIFT
value|13
end_define

begin_define
define|#
directive|define
name|IXGBE_RXD_CFI_MASK
value|0x1000
end_define

begin_comment
comment|/* CFI is bit 12 */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXD_CFI_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|IXGBE_RXDADV_STAT_DD
value|IXGBE_RXD_STAT_DD
end_define

begin_comment
comment|/* Done */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXDADV_STAT_EOP
value|IXGBE_RXD_STAT_EOP
end_define

begin_comment
comment|/* End of Packet */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXDADV_STAT_FLM
value|IXGBE_RXD_STAT_FLM
end_define

begin_comment
comment|/* FDir Match */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXDADV_STAT_VP
value|IXGBE_RXD_STAT_VP
end_define

begin_comment
comment|/* IEEE VLAN Pkt */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXDADV_STAT_MASK
value|0x000fffff
end_define

begin_comment
comment|/* Stat/NEXTP: bit 0-19 */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXDADV_STAT_FCEOFS
value|0x00000040
end_define

begin_comment
comment|/* FCoE EOF/SOF Stat */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXDADV_STAT_FCSTAT
value|0x00000030
end_define

begin_comment
comment|/* FCoE Pkt Stat */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXDADV_STAT_FCSTAT_NOMTCH
value|0x00000000
end_define

begin_comment
comment|/* 00: No Ctxt Match */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXDADV_STAT_FCSTAT_NODDP
value|0x00000010
end_define

begin_comment
comment|/* 01: Ctxt w/o DDP */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXDADV_STAT_FCSTAT_FCPRSP
value|0x00000020
end_define

begin_comment
comment|/* 10: Recv. FCP_RSP */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXDADV_STAT_FCSTAT_DDP
value|0x00000030
end_define

begin_comment
comment|/* 11: Ctxt w/ DDP */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXDADV_STAT_TS
value|0x00010000
end_define

begin_comment
comment|/* IEEE1588 Time Stamp */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXDADV_STAT_TSIP
value|0x00008000
end_define

begin_comment
comment|/* Time Stamp in packet buffer */
end_comment

begin_comment
comment|/* PSRTYPE bit definitions */
end_comment

begin_define
define|#
directive|define
name|IXGBE_PSRTYPE_TCPHDR
value|0x00000010
end_define

begin_define
define|#
directive|define
name|IXGBE_PSRTYPE_UDPHDR
value|0x00000020
end_define

begin_define
define|#
directive|define
name|IXGBE_PSRTYPE_IPV4HDR
value|0x00000100
end_define

begin_define
define|#
directive|define
name|IXGBE_PSRTYPE_IPV6HDR
value|0x00000200
end_define

begin_define
define|#
directive|define
name|IXGBE_PSRTYPE_L2HDR
value|0x00001000
end_define

begin_comment
comment|/* SRRCTL bit definitions */
end_comment

begin_define
define|#
directive|define
name|IXGBE_SRRCTL_BSIZEPKT_SHIFT
value|10
end_define

begin_comment
comment|/* so many KBs */
end_comment

begin_define
define|#
directive|define
name|IXGBE_SRRCTL_BSIZEHDRSIZE_SHIFT
value|2
end_define

begin_comment
comment|/* 64byte resolution (>> 6) 					   * + at bit 8 offset (<< 8) 					   *  = (<< 2) 					   */
end_comment

begin_define
define|#
directive|define
name|IXGBE_SRRCTL_RDMTS_SHIFT
value|22
end_define

begin_define
define|#
directive|define
name|IXGBE_SRRCTL_RDMTS_MASK
value|0x01C00000
end_define

begin_define
define|#
directive|define
name|IXGBE_SRRCTL_DROP_EN
value|0x10000000
end_define

begin_define
define|#
directive|define
name|IXGBE_SRRCTL_BSIZEPKT_MASK
value|0x0000007F
end_define

begin_define
define|#
directive|define
name|IXGBE_SRRCTL_BSIZEHDR_MASK
value|0x00003F00
end_define

begin_define
define|#
directive|define
name|IXGBE_SRRCTL_DESCTYPE_LEGACY
value|0x00000000
end_define

begin_define
define|#
directive|define
name|IXGBE_SRRCTL_DESCTYPE_ADV_ONEBUF
value|0x02000000
end_define

begin_define
define|#
directive|define
name|IXGBE_SRRCTL_DESCTYPE_HDR_SPLIT
value|0x04000000
end_define

begin_define
define|#
directive|define
name|IXGBE_SRRCTL_DESCTYPE_HDR_REPLICATION_LARGE_PKT
value|0x08000000
end_define

begin_define
define|#
directive|define
name|IXGBE_SRRCTL_DESCTYPE_HDR_SPLIT_ALWAYS
value|0x0A000000
end_define

begin_define
define|#
directive|define
name|IXGBE_SRRCTL_DESCTYPE_MASK
value|0x0E000000
end_define

begin_define
define|#
directive|define
name|IXGBE_RXDPS_HDRSTAT_HDRSP
value|0x00008000
end_define

begin_define
define|#
directive|define
name|IXGBE_RXDPS_HDRSTAT_HDRLEN_MASK
value|0x000003FF
end_define

begin_define
define|#
directive|define
name|IXGBE_RXDADV_RSSTYPE_MASK
value|0x0000000F
end_define

begin_define
define|#
directive|define
name|IXGBE_RXDADV_PKTTYPE_MASK
value|0x0000FFF0
end_define

begin_define
define|#
directive|define
name|IXGBE_RXDADV_PKTTYPE_MASK_EX
value|0x0001FFF0
end_define

begin_define
define|#
directive|define
name|IXGBE_RXDADV_HDRBUFLEN_MASK
value|0x00007FE0
end_define

begin_define
define|#
directive|define
name|IXGBE_RXDADV_RSCCNT_MASK
value|0x001E0000
end_define

begin_define
define|#
directive|define
name|IXGBE_RXDADV_RSCCNT_SHIFT
value|17
end_define

begin_define
define|#
directive|define
name|IXGBE_RXDADV_HDRBUFLEN_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|IXGBE_RXDADV_SPLITHEADER_EN
value|0x00001000
end_define

begin_define
define|#
directive|define
name|IXGBE_RXDADV_SPH
value|0x8000
end_define

begin_comment
comment|/* RSS Hash results */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXDADV_RSSTYPE_NONE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|IXGBE_RXDADV_RSSTYPE_IPV4_TCP
value|0x00000001
end_define

begin_define
define|#
directive|define
name|IXGBE_RXDADV_RSSTYPE_IPV4
value|0x00000002
end_define

begin_define
define|#
directive|define
name|IXGBE_RXDADV_RSSTYPE_IPV6_TCP
value|0x00000003
end_define

begin_define
define|#
directive|define
name|IXGBE_RXDADV_RSSTYPE_IPV6_EX
value|0x00000004
end_define

begin_define
define|#
directive|define
name|IXGBE_RXDADV_RSSTYPE_IPV6
value|0x00000005
end_define

begin_define
define|#
directive|define
name|IXGBE_RXDADV_RSSTYPE_IPV6_TCP_EX
value|0x00000006
end_define

begin_define
define|#
directive|define
name|IXGBE_RXDADV_RSSTYPE_IPV4_UDP
value|0x00000007
end_define

begin_define
define|#
directive|define
name|IXGBE_RXDADV_RSSTYPE_IPV6_UDP
value|0x00000008
end_define

begin_define
define|#
directive|define
name|IXGBE_RXDADV_RSSTYPE_IPV6_UDP_EX
value|0x00000009
end_define

begin_comment
comment|/* RSS Packet Types as indicated in the receive descriptor. */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXDADV_PKTTYPE_NONE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|IXGBE_RXDADV_PKTTYPE_IPV4
value|0x00000010
end_define

begin_comment
comment|/* IPv4 hdr present */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXDADV_PKTTYPE_IPV4_EX
value|0x00000020
end_define

begin_comment
comment|/* IPv4 hdr + extensions */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXDADV_PKTTYPE_IPV6
value|0x00000040
end_define

begin_comment
comment|/* IPv6 hdr present */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXDADV_PKTTYPE_IPV6_EX
value|0x00000080
end_define

begin_comment
comment|/* IPv6 hdr + extensions */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXDADV_PKTTYPE_TCP
value|0x00000100
end_define

begin_comment
comment|/* TCP hdr present */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXDADV_PKTTYPE_UDP
value|0x00000200
end_define

begin_comment
comment|/* UDP hdr present */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXDADV_PKTTYPE_SCTP
value|0x00000400
end_define

begin_comment
comment|/* SCTP hdr present */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXDADV_PKTTYPE_NFS
value|0x00000800
end_define

begin_comment
comment|/* NFS hdr present */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXDADV_PKTTYPE_GENEVE
value|0x00000800
end_define

begin_comment
comment|/* GENEVE hdr present */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXDADV_PKTTYPE_VXLAN
value|0x00000800
end_define

begin_comment
comment|/* VXLAN hdr present */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXDADV_PKTTYPE_TUNNEL
value|0x00010000
end_define

begin_comment
comment|/* Tunnel type */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXDADV_PKTTYPE_IPSEC_ESP
value|0x00001000
end_define

begin_comment
comment|/* IPSec ESP */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXDADV_PKTTYPE_IPSEC_AH
value|0x00002000
end_define

begin_comment
comment|/* IPSec AH */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXDADV_PKTTYPE_LINKSEC
value|0x00004000
end_define

begin_comment
comment|/* LinkSec Encap */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXDADV_PKTTYPE_ETQF
value|0x00008000
end_define

begin_comment
comment|/* PKTTYPE is ETQF index */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXDADV_PKTTYPE_ETQF_MASK
value|0x00000070
end_define

begin_comment
comment|/* ETQF has 8 indices */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXDADV_PKTTYPE_ETQF_SHIFT
value|4
end_define

begin_comment
comment|/* Right-shift 4 bits */
end_comment

begin_comment
comment|/* Security Processing bit Indication */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXDADV_LNKSEC_STATUS_SECP
value|0x00020000
end_define

begin_define
define|#
directive|define
name|IXGBE_RXDADV_LNKSEC_ERROR_NO_SA_MATCH
value|0x08000000
end_define

begin_define
define|#
directive|define
name|IXGBE_RXDADV_LNKSEC_ERROR_REPLAY_ERROR
value|0x10000000
end_define

begin_define
define|#
directive|define
name|IXGBE_RXDADV_LNKSEC_ERROR_BIT_MASK
value|0x18000000
end_define

begin_define
define|#
directive|define
name|IXGBE_RXDADV_LNKSEC_ERROR_BAD_SIG
value|0x18000000
end_define

begin_comment
comment|/* Masks to determine if packets should be dropped due to frame errors */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RXD_ERR_FRAME_ERR_MASK
value|( \ 				IXGBE_RXD_ERR_CE | \ 				IXGBE_RXD_ERR_LE | \ 				IXGBE_RXD_ERR_PE | \ 				IXGBE_RXD_ERR_OSE | \ 				IXGBE_RXD_ERR_USE)
end_define

begin_define
define|#
directive|define
name|IXGBE_RXDADV_ERR_FRAME_ERR_MASK
value|( \ 				IXGBE_RXDADV_ERR_CE | \ 				IXGBE_RXDADV_ERR_LE | \ 				IXGBE_RXDADV_ERR_PE | \ 				IXGBE_RXDADV_ERR_OSE | \ 				IXGBE_RXDADV_ERR_USE)
end_define

begin_define
define|#
directive|define
name|IXGBE_RXDADV_ERR_FRAME_ERR_MASK_82599
value|IXGBE_RXDADV_ERR_RXE
end_define

begin_comment
comment|/* Multicast bit mask */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MCSTCTRL_MFE
value|0x4
end_define

begin_comment
comment|/* Number of Transmit and Receive Descriptors must be a multiple of 8 */
end_comment

begin_define
define|#
directive|define
name|IXGBE_REQ_TX_DESCRIPTOR_MULTIPLE
value|8
end_define

begin_define
define|#
directive|define
name|IXGBE_REQ_RX_DESCRIPTOR_MULTIPLE
value|8
end_define

begin_define
define|#
directive|define
name|IXGBE_REQ_TX_BUFFER_GRANULARITY
value|1024
end_define

begin_comment
comment|/* Vlan-specific macros */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RX_DESC_SPECIAL_VLAN_MASK
value|0x0FFF
end_define

begin_comment
comment|/* VLAN ID in lower 12 bits */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RX_DESC_SPECIAL_PRI_MASK
value|0xE000
end_define

begin_comment
comment|/* Priority in upper 3 bits */
end_comment

begin_define
define|#
directive|define
name|IXGBE_RX_DESC_SPECIAL_PRI_SHIFT
value|0x000D
end_define

begin_comment
comment|/* Priority in upper 3 of 16 */
end_comment

begin_define
define|#
directive|define
name|IXGBE_TX_DESC_SPECIAL_PRI_SHIFT
value|IXGBE_RX_DESC_SPECIAL_PRI_SHIFT
end_define

begin_comment
comment|/* SR-IOV specific macros */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MBVFICR_INDEX
parameter_list|(
name|vf_number
parameter_list|)
value|(vf_number>> 4)
end_define

begin_define
define|#
directive|define
name|IXGBE_MBVFICR
parameter_list|(
name|_i
parameter_list|)
value|(0x00710 + ((_i) * 4))
end_define

begin_define
define|#
directive|define
name|IXGBE_VFLRE
parameter_list|(
name|_i
parameter_list|)
value|(((_i& 1) ? 0x001C0 : 0x00600))
end_define

begin_define
define|#
directive|define
name|IXGBE_VFLREC
parameter_list|(
name|_i
parameter_list|)
value|(0x00700 + ((_i) * 4))
end_define

begin_comment
comment|/* Translated register #defines */
end_comment

begin_define
define|#
directive|define
name|IXGBE_PVFCTRL
parameter_list|(
name|P
parameter_list|)
value|(0x00300 + (4 * (P)))
end_define

begin_define
define|#
directive|define
name|IXGBE_PVFSTATUS
parameter_list|(
name|P
parameter_list|)
value|(0x00008 + (0 * (P)))
end_define

begin_define
define|#
directive|define
name|IXGBE_PVFLINKS
parameter_list|(
name|P
parameter_list|)
value|(0x042A4 + (0 * (P)))
end_define

begin_define
define|#
directive|define
name|IXGBE_PVFRTIMER
parameter_list|(
name|P
parameter_list|)
value|(0x00048 + (0 * (P)))
end_define

begin_define
define|#
directive|define
name|IXGBE_PVFMAILBOX
parameter_list|(
name|P
parameter_list|)
value|(0x04C00 + (4 * (P)))
end_define

begin_define
define|#
directive|define
name|IXGBE_PVFRXMEMWRAP
parameter_list|(
name|P
parameter_list|)
value|(0x03190 + (0 * (P)))
end_define

begin_define
define|#
directive|define
name|IXGBE_PVTEICR
parameter_list|(
name|P
parameter_list|)
value|(0x00B00 + (4 * (P)))
end_define

begin_define
define|#
directive|define
name|IXGBE_PVTEICS
parameter_list|(
name|P
parameter_list|)
value|(0x00C00 + (4 * (P)))
end_define

begin_define
define|#
directive|define
name|IXGBE_PVTEIMS
parameter_list|(
name|P
parameter_list|)
value|(0x00D00 + (4 * (P)))
end_define

begin_define
define|#
directive|define
name|IXGBE_PVTEIMC
parameter_list|(
name|P
parameter_list|)
value|(0x00E00 + (4 * (P)))
end_define

begin_define
define|#
directive|define
name|IXGBE_PVTEIAC
parameter_list|(
name|P
parameter_list|)
value|(0x00F00 + (4 * (P)))
end_define

begin_define
define|#
directive|define
name|IXGBE_PVTEIAM
parameter_list|(
name|P
parameter_list|)
value|(0x04D00 + (4 * (P)))
end_define

begin_define
define|#
directive|define
name|IXGBE_PVTEITR
parameter_list|(
name|P
parameter_list|)
value|(((P)< 24) ? (0x00820 + ((P) * 4)) : \ 				 (0x012300 + (((P) - 24) * 4)))
end_define

begin_define
define|#
directive|define
name|IXGBE_PVTIVAR
parameter_list|(
name|P
parameter_list|)
value|(0x12500 + (4 * (P)))
end_define

begin_define
define|#
directive|define
name|IXGBE_PVTIVAR_MISC
parameter_list|(
name|P
parameter_list|)
value|(0x04E00 + (4 * (P)))
end_define

begin_define
define|#
directive|define
name|IXGBE_PVTRSCINT
parameter_list|(
name|P
parameter_list|)
value|(0x12000 + (4 * (P)))
end_define

begin_define
define|#
directive|define
name|IXGBE_VFPBACL
parameter_list|(
name|P
parameter_list|)
value|(0x110C8 + (4 * (P)))
end_define

begin_define
define|#
directive|define
name|IXGBE_PVFRDBAL
parameter_list|(
name|P
parameter_list|)
value|((P< 64) ? (0x01000 + (0x40 * (P))) \ 				 : (0x0D000 + (0x40 * ((P) - 64))))
end_define

begin_define
define|#
directive|define
name|IXGBE_PVFRDBAH
parameter_list|(
name|P
parameter_list|)
value|((P< 64) ? (0x01004 + (0x40 * (P))) \ 				 : (0x0D004 + (0x40 * ((P) - 64))))
end_define

begin_define
define|#
directive|define
name|IXGBE_PVFRDLEN
parameter_list|(
name|P
parameter_list|)
value|((P< 64) ? (0x01008 + (0x40 * (P))) \ 				 : (0x0D008 + (0x40 * ((P) - 64))))
end_define

begin_define
define|#
directive|define
name|IXGBE_PVFRDH
parameter_list|(
name|P
parameter_list|)
value|((P< 64) ? (0x01010 + (0x40 * (P))) \ 				 : (0x0D010 + (0x40 * ((P) - 64))))
end_define

begin_define
define|#
directive|define
name|IXGBE_PVFRDT
parameter_list|(
name|P
parameter_list|)
value|((P< 64) ? (0x01018 + (0x40 * (P))) \ 				 : (0x0D018 + (0x40 * ((P) - 64))))
end_define

begin_define
define|#
directive|define
name|IXGBE_PVFRXDCTL
parameter_list|(
name|P
parameter_list|)
value|((P< 64) ? (0x01028 + (0x40 * (P))) \ 				 : (0x0D028 + (0x40 * ((P) - 64))))
end_define

begin_define
define|#
directive|define
name|IXGBE_PVFSRRCTL
parameter_list|(
name|P
parameter_list|)
value|((P< 64) ? (0x01014 + (0x40 * (P))) \ 				 : (0x0D014 + (0x40 * ((P) - 64))))
end_define

begin_define
define|#
directive|define
name|IXGBE_PVFPSRTYPE
parameter_list|(
name|P
parameter_list|)
value|(0x0EA00 + (4 * (P)))
end_define

begin_define
define|#
directive|define
name|IXGBE_PVFTDBAL
parameter_list|(
name|P
parameter_list|)
value|(0x06000 + (0x40 * (P)))
end_define

begin_define
define|#
directive|define
name|IXGBE_PVFTDBAH
parameter_list|(
name|P
parameter_list|)
value|(0x06004 + (0x40 * (P)))
end_define

begin_define
define|#
directive|define
name|IXGBE_PVFTDLEN
parameter_list|(
name|P
parameter_list|)
value|(0x06008 + (0x40 * (P)))
end_define

begin_define
define|#
directive|define
name|IXGBE_PVFTDH
parameter_list|(
name|P
parameter_list|)
value|(0x06010 + (0x40 * (P)))
end_define

begin_define
define|#
directive|define
name|IXGBE_PVFTDT
parameter_list|(
name|P
parameter_list|)
value|(0x06018 + (0x40 * (P)))
end_define

begin_define
define|#
directive|define
name|IXGBE_PVFTXDCTL
parameter_list|(
name|P
parameter_list|)
value|(0x06028 + (0x40 * (P)))
end_define

begin_define
define|#
directive|define
name|IXGBE_PVFTDWBAL
parameter_list|(
name|P
parameter_list|)
value|(0x06038 + (0x40 * (P)))
end_define

begin_define
define|#
directive|define
name|IXGBE_PVFTDWBAH
parameter_list|(
name|P
parameter_list|)
value|(0x0603C + (0x40 * (P)))
end_define

begin_define
define|#
directive|define
name|IXGBE_PVFDCA_RXCTRL
parameter_list|(
name|P
parameter_list|)
value|(((P)< 64) ? (0x0100C + (0x40 * (P))) \ 				 : (0x0D00C + (0x40 * ((P) - 64))))
end_define

begin_define
define|#
directive|define
name|IXGBE_PVFDCA_TXCTRL
parameter_list|(
name|P
parameter_list|)
value|(0x0600C + (0x40 * (P)))
end_define

begin_define
define|#
directive|define
name|IXGBE_PVFGPRC
parameter_list|(
name|x
parameter_list|)
value|(0x0101C + (0x40 * (x)))
end_define

begin_define
define|#
directive|define
name|IXGBE_PVFGPTC
parameter_list|(
name|x
parameter_list|)
value|(0x08300 + (0x04 * (x)))
end_define

begin_define
define|#
directive|define
name|IXGBE_PVFGORC_LSB
parameter_list|(
name|x
parameter_list|)
value|(0x01020 + (0x40 * (x)))
end_define

begin_define
define|#
directive|define
name|IXGBE_PVFGORC_MSB
parameter_list|(
name|x
parameter_list|)
value|(0x0D020 + (0x40 * (x)))
end_define

begin_define
define|#
directive|define
name|IXGBE_PVFGOTC_LSB
parameter_list|(
name|x
parameter_list|)
value|(0x08400 + (0x08 * (x)))
end_define

begin_define
define|#
directive|define
name|IXGBE_PVFGOTC_MSB
parameter_list|(
name|x
parameter_list|)
value|(0x08404 + (0x08 * (x)))
end_define

begin_define
define|#
directive|define
name|IXGBE_PVFMPRC
parameter_list|(
name|x
parameter_list|)
value|(0x0D01C + (0x40 * (x)))
end_define

begin_define
define|#
directive|define
name|IXGBE_PVFTDWBALn
parameter_list|(
name|q_per_pool
parameter_list|,
name|vf_number
parameter_list|,
name|vf_q_index
parameter_list|)
define|\
value|(IXGBE_PVFTDWBAL((q_per_pool)*(vf_number) + (vf_q_index)))
end_define

begin_define
define|#
directive|define
name|IXGBE_PVFTDWBAHn
parameter_list|(
name|q_per_pool
parameter_list|,
name|vf_number
parameter_list|,
name|vf_q_index
parameter_list|)
define|\
value|(IXGBE_PVFTDWBAH((q_per_pool)*(vf_number) + (vf_q_index)))
end_define

begin_define
define|#
directive|define
name|IXGBE_PVFTDHn
parameter_list|(
name|q_per_pool
parameter_list|,
name|vf_number
parameter_list|,
name|vf_q_index
parameter_list|)
define|\
value|(IXGBE_PVFTDH((q_per_pool)*(vf_number) + (vf_q_index)))
end_define

begin_define
define|#
directive|define
name|IXGBE_PVFTDTn
parameter_list|(
name|q_per_pool
parameter_list|,
name|vf_number
parameter_list|,
name|vf_q_index
parameter_list|)
define|\
value|(IXGBE_PVFTDT((q_per_pool)*(vf_number) + (vf_q_index)))
end_define

begin_comment
comment|/* Little Endian defines */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__le16
end_ifndef

begin_define
define|#
directive|define
name|__le16
value|u16
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__le32
end_ifndef

begin_define
define|#
directive|define
name|__le32
value|u32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__le64
end_ifndef

begin_define
define|#
directive|define
name|__le64
value|u64
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__be16
end_ifndef

begin_comment
comment|/* Big Endian defines */
end_comment

begin_define
define|#
directive|define
name|__be16
value|u16
end_define

begin_define
define|#
directive|define
name|__be32
value|u32
end_define

begin_define
define|#
directive|define
name|__be64
value|u64
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_enum
enum|enum
name|ixgbe_fdir_pballoc_type
block|{
name|IXGBE_FDIR_PBALLOC_NONE
init|=
literal|0
block|,
name|IXGBE_FDIR_PBALLOC_64K
init|=
literal|1
block|,
name|IXGBE_FDIR_PBALLOC_128K
init|=
literal|2
block|,
name|IXGBE_FDIR_PBALLOC_256K
init|=
literal|3
block|, }
enum|;
end_enum

begin_comment
comment|/* Flow Director register values */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FDIRCTRL_PBALLOC_64K
value|0x00000001
end_define

begin_define
define|#
directive|define
name|IXGBE_FDIRCTRL_PBALLOC_128K
value|0x00000002
end_define

begin_define
define|#
directive|define
name|IXGBE_FDIRCTRL_PBALLOC_256K
value|0x00000003
end_define

begin_define
define|#
directive|define
name|IXGBE_FDIRCTRL_INIT_DONE
value|0x00000008
end_define

begin_define
define|#
directive|define
name|IXGBE_FDIRCTRL_PERFECT_MATCH
value|0x00000010
end_define

begin_define
define|#
directive|define
name|IXGBE_FDIRCTRL_REPORT_STATUS
value|0x00000020
end_define

begin_define
define|#
directive|define
name|IXGBE_FDIRCTRL_REPORT_STATUS_ALWAYS
value|0x00000080
end_define

begin_define
define|#
directive|define
name|IXGBE_FDIRCTRL_DROP_Q_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|IXGBE_FDIRCTRL_DROP_Q_MASK
value|0x00007F00
end_define

begin_define
define|#
directive|define
name|IXGBE_FDIRCTRL_FLEX_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|IXGBE_FDIRCTRL_DROP_NO_MATCH
value|0x00008000
end_define

begin_define
define|#
directive|define
name|IXGBE_FDIRCTRL_FILTERMODE_SHIFT
value|21
end_define

begin_define
define|#
directive|define
name|IXGBE_FDIRCTRL_FILTERMODE_MACVLAN
value|0x0001
end_define

begin_comment
comment|/* bit 23:21, 001b */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FDIRCTRL_FILTERMODE_CLOUD
value|0x0002
end_define

begin_comment
comment|/* bit 23:21, 010b */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FDIRCTRL_SEARCHLIM
value|0x00800000
end_define

begin_define
define|#
directive|define
name|IXGBE_FDIRCTRL_FILTERMODE_MASK
value|0x00E00000
end_define

begin_define
define|#
directive|define
name|IXGBE_FDIRCTRL_MAX_LENGTH_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|IXGBE_FDIRCTRL_FULL_THRESH_MASK
value|0xF0000000
end_define

begin_define
define|#
directive|define
name|IXGBE_FDIRCTRL_FULL_THRESH_SHIFT
value|28
end_define

begin_define
define|#
directive|define
name|IXGBE_FDIRTCPM_DPORTM_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|IXGBE_FDIRUDPM_DPORTM_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|IXGBE_FDIRIP6M_DIPM_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|IXGBE_FDIRM_VLANID
value|0x00000001
end_define

begin_define
define|#
directive|define
name|IXGBE_FDIRM_VLANP
value|0x00000002
end_define

begin_define
define|#
directive|define
name|IXGBE_FDIRM_POOL
value|0x00000004
end_define

begin_define
define|#
directive|define
name|IXGBE_FDIRM_L4P
value|0x00000008
end_define

begin_define
define|#
directive|define
name|IXGBE_FDIRM_FLEX
value|0x00000010
end_define

begin_define
define|#
directive|define
name|IXGBE_FDIRM_DIPv6
value|0x00000020
end_define

begin_define
define|#
directive|define
name|IXGBE_FDIRM_L3P
value|0x00000040
end_define

begin_define
define|#
directive|define
name|IXGBE_FDIRIP6M_INNER_MAC
value|0x03F0
end_define

begin_comment
comment|/* bit 9:4 */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FDIRIP6M_TUNNEL_TYPE
value|0x0800
end_define

begin_comment
comment|/* bit 11 */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FDIRIP6M_TNI_VNI
value|0xF000
end_define

begin_comment
comment|/* bit 15:12 */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FDIRIP6M_TNI_VNI_24
value|0x1000
end_define

begin_comment
comment|/* bit 12 */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FDIRIP6M_ALWAYS_MASK
value|0x040F
end_define

begin_comment
comment|/* bit 10, 3:0 */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FDIRFREE_FREE_MASK
value|0xFFFF
end_define

begin_define
define|#
directive|define
name|IXGBE_FDIRFREE_FREE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|IXGBE_FDIRFREE_COLL_MASK
value|0x7FFF0000
end_define

begin_define
define|#
directive|define
name|IXGBE_FDIRFREE_COLL_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|IXGBE_FDIRLEN_MAXLEN_MASK
value|0x3F
end_define

begin_define
define|#
directive|define
name|IXGBE_FDIRLEN_MAXLEN_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|IXGBE_FDIRLEN_MAXHASH_MASK
value|0x7FFF0000
end_define

begin_define
define|#
directive|define
name|IXGBE_FDIRLEN_MAXHASH_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|IXGBE_FDIRUSTAT_ADD_MASK
value|0xFFFF
end_define

begin_define
define|#
directive|define
name|IXGBE_FDIRUSTAT_ADD_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|IXGBE_FDIRUSTAT_REMOVE_MASK
value|0xFFFF0000
end_define

begin_define
define|#
directive|define
name|IXGBE_FDIRUSTAT_REMOVE_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|IXGBE_FDIRFSTAT_FADD_MASK
value|0x00FF
end_define

begin_define
define|#
directive|define
name|IXGBE_FDIRFSTAT_FADD_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|IXGBE_FDIRFSTAT_FREMOVE_MASK
value|0xFF00
end_define

begin_define
define|#
directive|define
name|IXGBE_FDIRFSTAT_FREMOVE_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|IXGBE_FDIRPORT_DESTINATION_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|IXGBE_FDIRVLAN_FLEX_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|IXGBE_FDIRHASH_BUCKET_VALID_SHIFT
value|15
end_define

begin_define
define|#
directive|define
name|IXGBE_FDIRHASH_SIG_SW_INDEX_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|IXGBE_FDIRCMD_CMD_MASK
value|0x00000003
end_define

begin_define
define|#
directive|define
name|IXGBE_FDIRCMD_CMD_ADD_FLOW
value|0x00000001
end_define

begin_define
define|#
directive|define
name|IXGBE_FDIRCMD_CMD_REMOVE_FLOW
value|0x00000002
end_define

begin_define
define|#
directive|define
name|IXGBE_FDIRCMD_CMD_QUERY_REM_FILT
value|0x00000003
end_define

begin_define
define|#
directive|define
name|IXGBE_FDIRCMD_FILTER_VALID
value|0x00000004
end_define

begin_define
define|#
directive|define
name|IXGBE_FDIRCMD_FILTER_UPDATE
value|0x00000008
end_define

begin_define
define|#
directive|define
name|IXGBE_FDIRCMD_IPv6DMATCH
value|0x00000010
end_define

begin_define
define|#
directive|define
name|IXGBE_FDIRCMD_L4TYPE_UDP
value|0x00000020
end_define

begin_define
define|#
directive|define
name|IXGBE_FDIRCMD_L4TYPE_TCP
value|0x00000040
end_define

begin_define
define|#
directive|define
name|IXGBE_FDIRCMD_L4TYPE_SCTP
value|0x00000060
end_define

begin_define
define|#
directive|define
name|IXGBE_FDIRCMD_IPV6
value|0x00000080
end_define

begin_define
define|#
directive|define
name|IXGBE_FDIRCMD_CLEARHT
value|0x00000100
end_define

begin_define
define|#
directive|define
name|IXGBE_FDIRCMD_DROP
value|0x00000200
end_define

begin_define
define|#
directive|define
name|IXGBE_FDIRCMD_INT
value|0x00000400
end_define

begin_define
define|#
directive|define
name|IXGBE_FDIRCMD_LAST
value|0x00000800
end_define

begin_define
define|#
directive|define
name|IXGBE_FDIRCMD_COLLISION
value|0x00001000
end_define

begin_define
define|#
directive|define
name|IXGBE_FDIRCMD_QUEUE_EN
value|0x00008000
end_define

begin_define
define|#
directive|define
name|IXGBE_FDIRCMD_FLOW_TYPE_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|IXGBE_FDIRCMD_RX_QUEUE_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|IXGBE_FDIRCMD_TUNNEL_FILTER_SHIFT
value|23
end_define

begin_define
define|#
directive|define
name|IXGBE_FDIRCMD_VT_POOL_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|IXGBE_FDIR_INIT_DONE_POLL
value|10
end_define

begin_define
define|#
directive|define
name|IXGBE_FDIRCMD_CMD_POLL
value|10
end_define

begin_define
define|#
directive|define
name|IXGBE_FDIRCMD_TUNNEL_FILTER
value|0x00800000
end_define

begin_define
define|#
directive|define
name|IXGBE_FDIR_DROP_QUEUE
value|127
end_define

begin_comment
comment|/* Manageablility Host Interface defines */
end_comment

begin_define
define|#
directive|define
name|IXGBE_HI_MAX_BLOCK_BYTE_LENGTH
value|1792
end_define

begin_comment
comment|/* Num of bytes in range */
end_comment

begin_define
define|#
directive|define
name|IXGBE_HI_MAX_BLOCK_DWORD_LENGTH
value|448
end_define

begin_comment
comment|/* Num of dwords in range */
end_comment

begin_define
define|#
directive|define
name|IXGBE_HI_COMMAND_TIMEOUT
value|500
end_define

begin_comment
comment|/* Process HI command limit */
end_comment

begin_define
define|#
directive|define
name|IXGBE_HI_FLASH_ERASE_TIMEOUT
value|1000
end_define

begin_comment
comment|/* Process Erase command limit */
end_comment

begin_define
define|#
directive|define
name|IXGBE_HI_FLASH_UPDATE_TIMEOUT
value|5000
end_define

begin_comment
comment|/* Process Update command limit */
end_comment

begin_define
define|#
directive|define
name|IXGBE_HI_FLASH_APPLY_TIMEOUT
value|0
end_define

begin_comment
comment|/* Process Apply command limit */
end_comment

begin_define
define|#
directive|define
name|IXGBE_HI_PHY_MGMT_REQ_TIMEOUT
value|2000
end_define

begin_comment
comment|/* Wait up to 2 seconds */
end_comment

begin_comment
comment|/* CEM Support */
end_comment

begin_define
define|#
directive|define
name|FW_CEM_HDR_LEN
value|0x4
end_define

begin_define
define|#
directive|define
name|FW_CEM_CMD_DRIVER_INFO
value|0xDD
end_define

begin_define
define|#
directive|define
name|FW_CEM_CMD_DRIVER_INFO_LEN
value|0x5
end_define

begin_define
define|#
directive|define
name|FW_CEM_CMD_RESERVED
value|0X0
end_define

begin_define
define|#
directive|define
name|FW_CEM_UNUSED_VER
value|0x0
end_define

begin_define
define|#
directive|define
name|FW_CEM_MAX_RETRIES
value|3
end_define

begin_define
define|#
directive|define
name|FW_CEM_RESP_STATUS_SUCCESS
value|0x1
end_define

begin_define
define|#
directive|define
name|FW_CEM_DRIVER_VERSION_SIZE
value|39
end_define

begin_comment
comment|/* +9 would send 48 bytes to fw */
end_comment

begin_define
define|#
directive|define
name|FW_READ_SHADOW_RAM_CMD
value|0x31
end_define

begin_define
define|#
directive|define
name|FW_READ_SHADOW_RAM_LEN
value|0x6
end_define

begin_define
define|#
directive|define
name|FW_WRITE_SHADOW_RAM_CMD
value|0x33
end_define

begin_define
define|#
directive|define
name|FW_WRITE_SHADOW_RAM_LEN
value|0xA
end_define

begin_comment
comment|/* 8 plus 1 WORD to write */
end_comment

begin_define
define|#
directive|define
name|FW_SHADOW_RAM_DUMP_CMD
value|0x36
end_define

begin_define
define|#
directive|define
name|FW_SHADOW_RAM_DUMP_LEN
value|0
end_define

begin_define
define|#
directive|define
name|FW_DEFAULT_CHECKSUM
value|0xFF
end_define

begin_comment
comment|/* checksum always 0xFF */
end_comment

begin_define
define|#
directive|define
name|FW_NVM_DATA_OFFSET
value|3
end_define

begin_define
define|#
directive|define
name|FW_MAX_READ_BUFFER_SIZE
value|1024
end_define

begin_define
define|#
directive|define
name|FW_DISABLE_RXEN_CMD
value|0xDE
end_define

begin_define
define|#
directive|define
name|FW_DISABLE_RXEN_LEN
value|0x1
end_define

begin_define
define|#
directive|define
name|FW_PHY_MGMT_REQ_CMD
value|0x20
end_define

begin_define
define|#
directive|define
name|FW_PHY_TOKEN_REQ_CMD
value|0xA
end_define

begin_define
define|#
directive|define
name|FW_PHY_TOKEN_REQ_LEN
value|2
end_define

begin_define
define|#
directive|define
name|FW_PHY_TOKEN_REQ
value|0
end_define

begin_define
define|#
directive|define
name|FW_PHY_TOKEN_REL
value|1
end_define

begin_define
define|#
directive|define
name|FW_PHY_TOKEN_OK
value|1
end_define

begin_define
define|#
directive|define
name|FW_PHY_TOKEN_RETRY
value|0x80
end_define

begin_define
define|#
directive|define
name|FW_PHY_TOKEN_DELAY
value|5
end_define

begin_comment
comment|/* milliseconds */
end_comment

begin_define
define|#
directive|define
name|FW_PHY_TOKEN_WAIT
value|5
end_define

begin_comment
comment|/* seconds */
end_comment

begin_define
define|#
directive|define
name|FW_PHY_TOKEN_RETRIES
value|((FW_PHY_TOKEN_WAIT * 1000) / FW_PHY_TOKEN_DELAY)
end_define

begin_define
define|#
directive|define
name|FW_INT_PHY_REQ_CMD
value|0xB
end_define

begin_define
define|#
directive|define
name|FW_INT_PHY_REQ_LEN
value|10
end_define

begin_define
define|#
directive|define
name|FW_INT_PHY_REQ_READ
value|0
end_define

begin_define
define|#
directive|define
name|FW_INT_PHY_REQ_WRITE
value|1
end_define

begin_define
define|#
directive|define
name|FW_PHY_ACT_REQ_CMD
value|5
end_define

begin_define
define|#
directive|define
name|FW_PHY_ACT_DATA_COUNT
value|4
end_define

begin_define
define|#
directive|define
name|FW_PHY_ACT_REQ_LEN
value|(4 + 4 * FW_PHY_ACT_DATA_COUNT)
end_define

begin_define
define|#
directive|define
name|FW_PHY_ACT_INIT_PHY
value|1
end_define

begin_define
define|#
directive|define
name|FW_PHY_ACT_SETUP_LINK
value|2
end_define

begin_define
define|#
directive|define
name|FW_PHY_ACT_LINK_SPEED_10
value|(1u<< 0)
end_define

begin_define
define|#
directive|define
name|FW_PHY_ACT_LINK_SPEED_100
value|(1u<< 1)
end_define

begin_define
define|#
directive|define
name|FW_PHY_ACT_LINK_SPEED_1G
value|(1u<< 2)
end_define

begin_define
define|#
directive|define
name|FW_PHY_ACT_LINK_SPEED_2_5G
value|(1u<< 3)
end_define

begin_define
define|#
directive|define
name|FW_PHY_ACT_LINK_SPEED_5G
value|(1u<< 4)
end_define

begin_define
define|#
directive|define
name|FW_PHY_ACT_LINK_SPEED_10G
value|(1u<< 5)
end_define

begin_define
define|#
directive|define
name|FW_PHY_ACT_LINK_SPEED_20G
value|(1u<< 6)
end_define

begin_define
define|#
directive|define
name|FW_PHY_ACT_LINK_SPEED_25G
value|(1u<< 7)
end_define

begin_define
define|#
directive|define
name|FW_PHY_ACT_LINK_SPEED_40G
value|(1u<< 8)
end_define

begin_define
define|#
directive|define
name|FW_PHY_ACT_LINK_SPEED_50G
value|(1u<< 9)
end_define

begin_define
define|#
directive|define
name|FW_PHY_ACT_LINK_SPEED_100G
value|(1u<< 10)
end_define

begin_define
define|#
directive|define
name|FW_PHY_ACT_SETUP_LINK_PAUSE_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|FW_PHY_ACT_SETUP_LINK_PAUSE_MASK
value|(3u<< \ 					  FW_PHY_ACT_SETUP_LINK_PAUSE_SHIFT)
end_define

begin_define
define|#
directive|define
name|FW_PHY_ACT_SETUP_LINK_PAUSE_NONE
value|0u
end_define

begin_define
define|#
directive|define
name|FW_PHY_ACT_SETUP_LINK_PAUSE_TX
value|1u
end_define

begin_define
define|#
directive|define
name|FW_PHY_ACT_SETUP_LINK_PAUSE_RX
value|2u
end_define

begin_define
define|#
directive|define
name|FW_PHY_ACT_SETUP_LINK_PAUSE_RXTX
value|3u
end_define

begin_define
define|#
directive|define
name|FW_PHY_ACT_SETUP_LINK_LP
value|(1u<< 18)
end_define

begin_define
define|#
directive|define
name|FW_PHY_ACT_SETUP_LINK_HP
value|(1u<< 19)
end_define

begin_define
define|#
directive|define
name|FW_PHY_ACT_SETUP_LINK_EEE
value|(1u<< 20)
end_define

begin_define
define|#
directive|define
name|FW_PHY_ACT_SETUP_LINK_AN
value|(1u<< 22)
end_define

begin_define
define|#
directive|define
name|FW_PHY_ACT_SETUP_LINK_RSP_DOWN
value|(1u<< 0)
end_define

begin_define
define|#
directive|define
name|FW_PHY_ACT_GET_LINK_INFO
value|3
end_define

begin_define
define|#
directive|define
name|FW_PHY_ACT_GET_LINK_INFO_EEE
value|(1u<< 19)
end_define

begin_define
define|#
directive|define
name|FW_PHY_ACT_GET_LINK_INFO_FC_TX
value|(1u<< 20)
end_define

begin_define
define|#
directive|define
name|FW_PHY_ACT_GET_LINK_INFO_FC_RX
value|(1u<< 21)
end_define

begin_define
define|#
directive|define
name|FW_PHY_ACT_GET_LINK_INFO_POWER
value|(1u<< 22)
end_define

begin_define
define|#
directive|define
name|FW_PHY_ACT_GET_LINK_INFO_AN_COMPLETE
value|(1u<< 24)
end_define

begin_define
define|#
directive|define
name|FW_PHY_ACT_GET_LINK_INFO_TEMP
value|(1u<< 25)
end_define

begin_define
define|#
directive|define
name|FW_PHY_ACT_GET_LINK_INFO_LP_FC_TX
value|(1u<< 28)
end_define

begin_define
define|#
directive|define
name|FW_PHY_ACT_GET_LINK_INFO_LP_FC_RX
value|(1u<< 29)
end_define

begin_define
define|#
directive|define
name|FW_PHY_ACT_FORCE_LINK_DOWN
value|4
end_define

begin_define
define|#
directive|define
name|FW_PHY_ACT_FORCE_LINK_DOWN_OFF
value|(1u<< 0)
end_define

begin_define
define|#
directive|define
name|FW_PHY_ACT_PHY_SW_RESET
value|5
end_define

begin_define
define|#
directive|define
name|FW_PHY_ACT_PHY_HW_RESET
value|6
end_define

begin_define
define|#
directive|define
name|FW_PHY_ACT_GET_PHY_INFO
value|7
end_define

begin_define
define|#
directive|define
name|FW_PHY_ACT_UD_2
value|0x1002
end_define

begin_define
define|#
directive|define
name|FW_PHY_ACT_UD_2_10G_KR_EEE
value|(1u<< 6)
end_define

begin_define
define|#
directive|define
name|FW_PHY_ACT_UD_2_10G_KX4_EEE
value|(1u<< 5)
end_define

begin_define
define|#
directive|define
name|FW_PHY_ACT_UD_2_1G_KX_EEE
value|(1u<< 4)
end_define

begin_define
define|#
directive|define
name|FW_PHY_ACT_UD_2_10G_T_EEE
value|(1u<< 3)
end_define

begin_define
define|#
directive|define
name|FW_PHY_ACT_UD_2_1G_T_EEE
value|(1u<< 2)
end_define

begin_define
define|#
directive|define
name|FW_PHY_ACT_UD_2_100M_TX_EEE
value|(1u<< 1)
end_define

begin_define
define|#
directive|define
name|FW_PHY_ACT_RETRIES
value|50
end_define

begin_define
define|#
directive|define
name|FW_PHY_INFO_SPEED_MASK
value|0xFFFu
end_define

begin_define
define|#
directive|define
name|FW_PHY_INFO_ID_HI_MASK
value|0xFFFF0000u
end_define

begin_define
define|#
directive|define
name|FW_PHY_INFO_ID_LO_MASK
value|0x0000FFFFu
end_define

begin_comment
comment|/* Host Interface Command Structures */
end_comment

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|push
name|,
name|1
name|)
end_pragma

begin_struct
struct|struct
name|ixgbe_hic_hdr
block|{
name|u8
name|cmd
decl_stmt|;
name|u8
name|buf_len
decl_stmt|;
union|union
block|{
name|u8
name|cmd_resv
decl_stmt|;
name|u8
name|ret_status
decl_stmt|;
block|}
name|cmd_or_resp
union|;
name|u8
name|checksum
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ixgbe_hic_hdr2_req
block|{
name|u8
name|cmd
decl_stmt|;
name|u8
name|buf_lenh
decl_stmt|;
name|u8
name|buf_lenl
decl_stmt|;
name|u8
name|checksum
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ixgbe_hic_hdr2_rsp
block|{
name|u8
name|cmd
decl_stmt|;
name|u8
name|buf_lenl
decl_stmt|;
name|u8
name|buf_lenh_status
decl_stmt|;
comment|/* 7-5: high bits of buf_len, 4-0: status */
name|u8
name|checksum
decl_stmt|;
block|}
struct|;
end_struct

begin_union
union|union
name|ixgbe_hic_hdr2
block|{
name|struct
name|ixgbe_hic_hdr2_req
name|req
decl_stmt|;
name|struct
name|ixgbe_hic_hdr2_rsp
name|rsp
decl_stmt|;
block|}
union|;
end_union

begin_struct
struct|struct
name|ixgbe_hic_drv_info
block|{
name|struct
name|ixgbe_hic_hdr
name|hdr
decl_stmt|;
name|u8
name|port_num
decl_stmt|;
name|u8
name|ver_sub
decl_stmt|;
name|u8
name|ver_build
decl_stmt|;
name|u8
name|ver_min
decl_stmt|;
name|u8
name|ver_maj
decl_stmt|;
name|u8
name|pad
decl_stmt|;
comment|/* end spacing to ensure length is mult. of dword */
name|u16
name|pad2
decl_stmt|;
comment|/* end spacing to ensure length is mult. of dword2 */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ixgbe_hic_drv_info2
block|{
name|struct
name|ixgbe_hic_hdr
name|hdr
decl_stmt|;
name|u8
name|port_num
decl_stmt|;
name|u8
name|ver_sub
decl_stmt|;
name|u8
name|ver_build
decl_stmt|;
name|u8
name|ver_min
decl_stmt|;
name|u8
name|ver_maj
decl_stmt|;
name|char
name|driver_string
index|[
name|FW_CEM_DRIVER_VERSION_SIZE
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* These need to be dword aligned */
end_comment

begin_struct
struct|struct
name|ixgbe_hic_read_shadow_ram
block|{
name|union
name|ixgbe_hic_hdr2
name|hdr
decl_stmt|;
name|u32
name|address
decl_stmt|;
name|u16
name|length
decl_stmt|;
name|u16
name|pad2
decl_stmt|;
name|u16
name|data
decl_stmt|;
name|u16
name|pad3
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ixgbe_hic_write_shadow_ram
block|{
name|union
name|ixgbe_hic_hdr2
name|hdr
decl_stmt|;
name|u32
name|address
decl_stmt|;
name|u16
name|length
decl_stmt|;
name|u16
name|pad2
decl_stmt|;
name|u16
name|data
decl_stmt|;
name|u16
name|pad3
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ixgbe_hic_disable_rxen
block|{
name|struct
name|ixgbe_hic_hdr
name|hdr
decl_stmt|;
name|u8
name|port_number
decl_stmt|;
name|u8
name|pad2
decl_stmt|;
name|u16
name|pad3
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ixgbe_hic_phy_token_req
block|{
name|struct
name|ixgbe_hic_hdr
name|hdr
decl_stmt|;
name|u8
name|port_number
decl_stmt|;
name|u8
name|command_type
decl_stmt|;
name|u16
name|pad
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ixgbe_hic_internal_phy_req
block|{
name|struct
name|ixgbe_hic_hdr
name|hdr
decl_stmt|;
name|u8
name|port_number
decl_stmt|;
name|u8
name|command_type
decl_stmt|;
name|__be16
name|address
decl_stmt|;
name|u16
name|rsv1
decl_stmt|;
name|__be32
name|write_data
decl_stmt|;
name|u16
name|pad
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ixgbe_hic_internal_phy_resp
block|{
name|struct
name|ixgbe_hic_hdr
name|hdr
decl_stmt|;
name|__be32
name|read_data
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ixgbe_hic_phy_activity_req
block|{
name|struct
name|ixgbe_hic_hdr
name|hdr
decl_stmt|;
name|u8
name|port_number
decl_stmt|;
name|u8
name|pad
decl_stmt|;
name|__le16
name|activity_id
decl_stmt|;
name|__be32
name|data
index|[
name|FW_PHY_ACT_DATA_COUNT
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ixgbe_hic_phy_activity_resp
block|{
name|struct
name|ixgbe_hic_hdr
name|hdr
decl_stmt|;
name|__be32
name|data
index|[
name|FW_PHY_ACT_DATA_COUNT
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|pop
name|)
end_pragma

begin_comment
comment|/* Transmit Descriptor - Legacy */
end_comment

begin_struct
struct|struct
name|ixgbe_legacy_tx_desc
block|{
name|u64
name|buffer_addr
decl_stmt|;
comment|/* Address of the descriptor's data buffer */
union|union
block|{
name|__le32
name|data
decl_stmt|;
struct|struct
block|{
name|__le16
name|length
decl_stmt|;
comment|/* Data buffer length */
name|u8
name|cso
decl_stmt|;
comment|/* Checksum offset */
name|u8
name|cmd
decl_stmt|;
comment|/* Descriptor control */
block|}
name|flags
struct|;
block|}
name|lower
union|;
union|union
block|{
name|__le32
name|data
decl_stmt|;
struct|struct
block|{
name|u8
name|status
decl_stmt|;
comment|/* Descriptor status */
name|u8
name|css
decl_stmt|;
comment|/* Checksum start */
name|__le16
name|vlan
decl_stmt|;
block|}
name|fields
struct|;
block|}
name|upper
union|;
block|}
struct|;
end_struct

begin_comment
comment|/* Transmit Descriptor - Advanced */
end_comment

begin_union
union|union
name|ixgbe_adv_tx_desc
block|{
struct|struct
block|{
name|__le64
name|buffer_addr
decl_stmt|;
comment|/* Address of descriptor's data buf */
name|__le32
name|cmd_type_len
decl_stmt|;
name|__le32
name|olinfo_status
decl_stmt|;
block|}
name|read
struct|;
struct|struct
block|{
name|__le64
name|rsvd
decl_stmt|;
comment|/* Reserved */
name|__le32
name|nxtseq_seed
decl_stmt|;
name|__le32
name|status
decl_stmt|;
block|}
name|wb
struct|;
block|}
union|;
end_union

begin_comment
comment|/* Receive Descriptor - Legacy */
end_comment

begin_struct
struct|struct
name|ixgbe_legacy_rx_desc
block|{
name|__le64
name|buffer_addr
decl_stmt|;
comment|/* Address of the descriptor's data buffer */
name|__le16
name|length
decl_stmt|;
comment|/* Length of data DMAed into data buffer */
name|__le16
name|csum
decl_stmt|;
comment|/* Packet checksum */
name|u8
name|status
decl_stmt|;
comment|/* Descriptor status */
name|u8
name|errors
decl_stmt|;
comment|/* Descriptor Errors */
name|__le16
name|vlan
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Receive Descriptor - Advanced */
end_comment

begin_union
union|union
name|ixgbe_adv_rx_desc
block|{
struct|struct
block|{
name|__le64
name|pkt_addr
decl_stmt|;
comment|/* Packet buffer address */
name|__le64
name|hdr_addr
decl_stmt|;
comment|/* Header buffer address */
block|}
name|read
struct|;
struct|struct
block|{
struct|struct
block|{
union|union
block|{
name|__le32
name|data
decl_stmt|;
struct|struct
block|{
name|__le16
name|pkt_info
decl_stmt|;
comment|/* RSS, Pkt type */
name|__le16
name|hdr_info
decl_stmt|;
comment|/* Splithdr, hdrlen */
block|}
name|hs_rss
struct|;
block|}
name|lo_dword
union|;
union|union
block|{
name|__le32
name|rss
decl_stmt|;
comment|/* RSS Hash */
struct|struct
block|{
name|__le16
name|ip_id
decl_stmt|;
comment|/* IP id */
name|__le16
name|csum
decl_stmt|;
comment|/* Packet Checksum */
block|}
name|csum_ip
struct|;
block|}
name|hi_dword
union|;
block|}
name|lower
struct|;
struct|struct
block|{
name|__le32
name|status_error
decl_stmt|;
comment|/* ext status/error */
name|__le16
name|length
decl_stmt|;
comment|/* Packet length */
name|__le16
name|vlan
decl_stmt|;
comment|/* VLAN tag */
block|}
name|upper
struct|;
block|}
name|wb
struct|;
comment|/* writeback */
block|}
union|;
end_union

begin_comment
comment|/* Context descriptors */
end_comment

begin_struct
struct|struct
name|ixgbe_adv_tx_context_desc
block|{
name|__le32
name|vlan_macip_lens
decl_stmt|;
name|__le32
name|seqnum_seed
decl_stmt|;
name|__le32
name|type_tucmd_mlhl
decl_stmt|;
name|__le32
name|mss_l4len_idx
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Adv Transmit Descriptor Config Masks */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ADVTXD_DTALEN_MASK
value|0x0000FFFF
end_define

begin_comment
comment|/* Data buf length(bytes) */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ADVTXD_MAC_LINKSEC
value|0x00040000
end_define

begin_comment
comment|/* Insert LinkSec */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ADVTXD_MAC_TSTAMP
value|0x00080000
end_define

begin_comment
comment|/* IEEE1588 time stamp */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ADVTXD_IPSEC_SA_INDEX_MASK
value|0x000003FF
end_define

begin_comment
comment|/* IPSec SA index */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ADVTXD_IPSEC_ESP_LEN_MASK
value|0x000001FF
end_define

begin_comment
comment|/* IPSec ESP length */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ADVTXD_DTYP_MASK
value|0x00F00000
end_define

begin_comment
comment|/* DTYP mask */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ADVTXD_DTYP_CTXT
value|0x00200000
end_define

begin_comment
comment|/* Adv Context Desc */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ADVTXD_DTYP_DATA
value|0x00300000
end_define

begin_comment
comment|/* Adv Data Descriptor */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ADVTXD_DCMD_EOP
value|IXGBE_TXD_CMD_EOP
end_define

begin_comment
comment|/* End of Packet */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ADVTXD_DCMD_IFCS
value|IXGBE_TXD_CMD_IFCS
end_define

begin_comment
comment|/* Insert FCS */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ADVTXD_DCMD_RS
value|IXGBE_TXD_CMD_RS
end_define

begin_comment
comment|/* Report Status */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ADVTXD_DCMD_DDTYP_ISCSI
value|0x10000000
end_define

begin_comment
comment|/* DDP hdr type or iSCSI */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ADVTXD_DCMD_DEXT
value|IXGBE_TXD_CMD_DEXT
end_define

begin_comment
comment|/* Desc ext 1=Adv */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ADVTXD_DCMD_VLE
value|IXGBE_TXD_CMD_VLE
end_define

begin_comment
comment|/* VLAN pkt enable */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ADVTXD_DCMD_TSE
value|0x80000000
end_define

begin_comment
comment|/* TCP Seg enable */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ADVTXD_STAT_DD
value|IXGBE_TXD_STAT_DD
end_define

begin_comment
comment|/* Descriptor Done */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ADVTXD_STAT_SN_CRC
value|0x00000002
end_define

begin_comment
comment|/* NXTSEQ/SEED pres in WB */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ADVTXD_STAT_RSV
value|0x0000000C
end_define

begin_comment
comment|/* STA Reserved */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ADVTXD_IDX_SHIFT
value|4
end_define

begin_comment
comment|/* Adv desc Index shift */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ADVTXD_CC
value|0x00000080
end_define

begin_comment
comment|/* Check Context */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ADVTXD_POPTS_SHIFT
value|8
end_define

begin_comment
comment|/* Adv desc POPTS shift */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ADVTXD_POPTS_IXSM
value|(IXGBE_TXD_POPTS_IXSM<< \ 					 IXGBE_ADVTXD_POPTS_SHIFT)
end_define

begin_define
define|#
directive|define
name|IXGBE_ADVTXD_POPTS_TXSM
value|(IXGBE_TXD_POPTS_TXSM<< \ 					 IXGBE_ADVTXD_POPTS_SHIFT)
end_define

begin_define
define|#
directive|define
name|IXGBE_ADVTXD_POPTS_ISCO_1ST
value|0x00000000
end_define

begin_comment
comment|/* 1st TSO of iSCSI PDU */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ADVTXD_POPTS_ISCO_MDL
value|0x00000800
end_define

begin_comment
comment|/* Middle TSO of iSCSI PDU */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ADVTXD_POPTS_ISCO_LAST
value|0x00001000
end_define

begin_comment
comment|/* Last TSO of iSCSI PDU */
end_comment

begin_comment
comment|/* 1st&Last TSO-full iSCSI PDU */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ADVTXD_POPTS_ISCO_FULL
value|0x00001800
end_define

begin_define
define|#
directive|define
name|IXGBE_ADVTXD_POPTS_RSV
value|0x00002000
end_define

begin_comment
comment|/* POPTS Reserved */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ADVTXD_PAYLEN_SHIFT
value|14
end_define

begin_comment
comment|/* Adv desc PAYLEN shift */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ADVTXD_MACLEN_SHIFT
value|9
end_define

begin_comment
comment|/* Adv ctxt desc mac len shift */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ADVTXD_VLAN_SHIFT
value|16
end_define

begin_comment
comment|/* Adv ctxt vlan tag shift */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ADVTXD_TUCMD_IPV4
value|0x00000400
end_define

begin_comment
comment|/* IP Packet Type: 1=IPv4 */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ADVTXD_TUCMD_IPV6
value|0x00000000
end_define

begin_comment
comment|/* IP Packet Type: 0=IPv6 */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ADVTXD_TUCMD_L4T_UDP
value|0x00000000
end_define

begin_comment
comment|/* L4 Packet TYPE of UDP */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ADVTXD_TUCMD_L4T_TCP
value|0x00000800
end_define

begin_comment
comment|/* L4 Packet TYPE of TCP */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ADVTXD_TUCMD_L4T_SCTP
value|0x00001000
end_define

begin_comment
comment|/* L4 Packet TYPE of SCTP */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ADVTXD_TUCMD_L4T_RSV
value|0x00001800
end_define

begin_comment
comment|/* RSV L4 Packet TYPE */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ADVTXD_TUCMD_MKRREQ
value|0x00002000
end_define

begin_comment
comment|/* req Markers and CRC */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ADVTXD_POPTS_IPSEC
value|0x00000400
end_define

begin_comment
comment|/* IPSec offload request */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ADVTXD_TUCMD_IPSEC_TYPE_ESP
value|0x00002000
end_define

begin_comment
comment|/* IPSec Type ESP */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ADVTXD_TUCMD_IPSEC_ENCRYPT_EN
value|0x00004000
end_define

begin_comment
comment|/* ESP Encrypt Enable */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ADVTXT_TUCMD_FCOE
value|0x00008000
end_define

begin_comment
comment|/* FCoE Frame Type */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ADVTXD_FCOEF_EOF_MASK
value|(0x3<< 10)
end_define

begin_comment
comment|/* FC EOF index */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ADVTXD_FCOEF_SOF
value|((1<< 2)<< 10)
end_define

begin_comment
comment|/* FC SOF index */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ADVTXD_FCOEF_PARINC
value|((1<< 3)<< 10)
end_define

begin_comment
comment|/* Rel_Off in F_CTL */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ADVTXD_FCOEF_ORIE
value|((1<< 4)<< 10)
end_define

begin_comment
comment|/* Orientation End */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ADVTXD_FCOEF_ORIS
value|((1<< 5)<< 10)
end_define

begin_comment
comment|/* Orientation Start */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ADVTXD_FCOEF_EOF_N
value|(0x0<< 10)
end_define

begin_comment
comment|/* 00: EOFn */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ADVTXD_FCOEF_EOF_T
value|(0x1<< 10)
end_define

begin_comment
comment|/* 01: EOFt */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ADVTXD_FCOEF_EOF_NI
value|(0x2<< 10)
end_define

begin_comment
comment|/* 10: EOFni */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ADVTXD_FCOEF_EOF_A
value|(0x3<< 10)
end_define

begin_comment
comment|/* 11: EOFa */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ADVTXD_L4LEN_SHIFT
value|8
end_define

begin_comment
comment|/* Adv ctxt L4LEN shift */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ADVTXD_MSS_SHIFT
value|16
end_define

begin_comment
comment|/* Adv ctxt MSS shift */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ADVTXD_OUTER_IPLEN
value|16
end_define

begin_comment
comment|/* Adv ctxt OUTERIPLEN shift */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ADVTXD_TUNNEL_LEN
value|24
end_define

begin_comment
comment|/* Adv ctxt TUNNELLEN shift */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ADVTXD_TUNNEL_TYPE_SHIFT
value|16
end_define

begin_comment
comment|/* Adv Tx Desc Tunnel Type shift */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ADVTXD_OUTERIPCS_SHIFT
value|17
end_define

begin_comment
comment|/* Adv Tx Desc OUTERIPCS Shift */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ADVTXD_TUNNEL_TYPE_NVGRE
value|1
end_define

begin_comment
comment|/* Adv Tx Desc Tunnel Type NVGRE */
end_comment

begin_comment
comment|/* Adv Tx Desc OUTERIPCS Shift for X550EM_a */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ADVTXD_OUTERIPCS_SHIFT_X550EM_a
value|26
end_define

begin_comment
comment|/* Autonegotiation advertised speeds */
end_comment

begin_typedef
typedef|typedef
name|u32
name|ixgbe_autoneg_advertised
typedef|;
end_typedef

begin_comment
comment|/* Link speed */
end_comment

begin_typedef
typedef|typedef
name|u32
name|ixgbe_link_speed
typedef|;
end_typedef

begin_define
define|#
directive|define
name|IXGBE_LINK_SPEED_UNKNOWN
value|0
end_define

begin_define
define|#
directive|define
name|IXGBE_LINK_SPEED_10_FULL
value|0x0002
end_define

begin_define
define|#
directive|define
name|IXGBE_LINK_SPEED_100_FULL
value|0x0008
end_define

begin_define
define|#
directive|define
name|IXGBE_LINK_SPEED_1GB_FULL
value|0x0020
end_define

begin_define
define|#
directive|define
name|IXGBE_LINK_SPEED_2_5GB_FULL
value|0x0400
end_define

begin_define
define|#
directive|define
name|IXGBE_LINK_SPEED_5GB_FULL
value|0x0800
end_define

begin_define
define|#
directive|define
name|IXGBE_LINK_SPEED_10GB_FULL
value|0x0080
end_define

begin_define
define|#
directive|define
name|IXGBE_LINK_SPEED_82598_AUTONEG
value|(IXGBE_LINK_SPEED_1GB_FULL | \ 					 IXGBE_LINK_SPEED_10GB_FULL)
end_define

begin_define
define|#
directive|define
name|IXGBE_LINK_SPEED_82599_AUTONEG
value|(IXGBE_LINK_SPEED_100_FULL | \ 					 IXGBE_LINK_SPEED_1GB_FULL | \ 					 IXGBE_LINK_SPEED_10GB_FULL)
end_define

begin_comment
comment|/* Physical layer type */
end_comment

begin_typedef
typedef|typedef
name|u64
name|ixgbe_physical_layer
typedef|;
end_typedef

begin_define
define|#
directive|define
name|IXGBE_PHYSICAL_LAYER_UNKNOWN
value|0
end_define

begin_define
define|#
directive|define
name|IXGBE_PHYSICAL_LAYER_10GBASE_T
value|0x00001
end_define

begin_define
define|#
directive|define
name|IXGBE_PHYSICAL_LAYER_1000BASE_T
value|0x00002
end_define

begin_define
define|#
directive|define
name|IXGBE_PHYSICAL_LAYER_100BASE_TX
value|0x00004
end_define

begin_define
define|#
directive|define
name|IXGBE_PHYSICAL_LAYER_SFP_PLUS_CU
value|0x00008
end_define

begin_define
define|#
directive|define
name|IXGBE_PHYSICAL_LAYER_10GBASE_LR
value|0x00010
end_define

begin_define
define|#
directive|define
name|IXGBE_PHYSICAL_LAYER_10GBASE_LRM
value|0x00020
end_define

begin_define
define|#
directive|define
name|IXGBE_PHYSICAL_LAYER_10GBASE_SR
value|0x00040
end_define

begin_define
define|#
directive|define
name|IXGBE_PHYSICAL_LAYER_10GBASE_KX4
value|0x00080
end_define

begin_define
define|#
directive|define
name|IXGBE_PHYSICAL_LAYER_10GBASE_CX4
value|0x00100
end_define

begin_define
define|#
directive|define
name|IXGBE_PHYSICAL_LAYER_1000BASE_KX
value|0x00200
end_define

begin_define
define|#
directive|define
name|IXGBE_PHYSICAL_LAYER_1000BASE_BX
value|0x00400
end_define

begin_define
define|#
directive|define
name|IXGBE_PHYSICAL_LAYER_10GBASE_KR
value|0x00800
end_define

begin_define
define|#
directive|define
name|IXGBE_PHYSICAL_LAYER_10GBASE_XAUI
value|0x01000
end_define

begin_define
define|#
directive|define
name|IXGBE_PHYSICAL_LAYER_SFP_ACTIVE_DA
value|0x02000
end_define

begin_define
define|#
directive|define
name|IXGBE_PHYSICAL_LAYER_1000BASE_SX
value|0x04000
end_define

begin_define
define|#
directive|define
name|IXGBE_PHYSICAL_LAYER_10BASE_T
value|0x08000
end_define

begin_define
define|#
directive|define
name|IXGBE_PHYSICAL_LAYER_2500BASE_KX
value|0x10000
end_define

begin_comment
comment|/* Flow Control Data Sheet defined values  * Calculation and defines taken from 802.1bb Annex O  */
end_comment

begin_comment
comment|/* BitTimes (BT) conversion */
end_comment

begin_define
define|#
directive|define
name|IXGBE_BT2KB
parameter_list|(
name|BT
parameter_list|)
value|((BT + (8 * 1024 - 1)) / (8 * 1024))
end_define

begin_define
define|#
directive|define
name|IXGBE_B2BT
parameter_list|(
name|BT
parameter_list|)
value|(BT * 8)
end_define

begin_comment
comment|/* Calculate Delay to respond to PFC */
end_comment

begin_define
define|#
directive|define
name|IXGBE_PFC_D
value|672
end_define

begin_comment
comment|/* Calculate Cable Delay */
end_comment

begin_define
define|#
directive|define
name|IXGBE_CABLE_DC
value|5556
end_define

begin_comment
comment|/* Delay Copper */
end_comment

begin_define
define|#
directive|define
name|IXGBE_CABLE_DO
value|5000
end_define

begin_comment
comment|/* Delay Optical */
end_comment

begin_comment
comment|/* Calculate Interface Delay X540 */
end_comment

begin_define
define|#
directive|define
name|IXGBE_PHY_DC
value|25600
end_define

begin_comment
comment|/* Delay 10G BASET */
end_comment

begin_define
define|#
directive|define
name|IXGBE_MAC_DC
value|8192
end_define

begin_comment
comment|/* Delay Copper XAUI interface */
end_comment

begin_define
define|#
directive|define
name|IXGBE_XAUI_DC
value|(2 * 2048)
end_define

begin_comment
comment|/* Delay Copper Phy */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ID_X540
value|(IXGBE_MAC_DC + IXGBE_XAUI_DC + IXGBE_PHY_DC)
end_define

begin_comment
comment|/* Calculate Interface Delay 82598, 82599 */
end_comment

begin_define
define|#
directive|define
name|IXGBE_PHY_D
value|12800
end_define

begin_define
define|#
directive|define
name|IXGBE_MAC_D
value|4096
end_define

begin_define
define|#
directive|define
name|IXGBE_XAUI_D
value|(2 * 1024)
end_define

begin_define
define|#
directive|define
name|IXGBE_ID
value|(IXGBE_MAC_D + IXGBE_XAUI_D + IXGBE_PHY_D)
end_define

begin_comment
comment|/* Calculate Delay incurred from higher layer */
end_comment

begin_define
define|#
directive|define
name|IXGBE_HD
value|6144
end_define

begin_comment
comment|/* Calculate PCI Bus delay for low thresholds */
end_comment

begin_define
define|#
directive|define
name|IXGBE_PCI_DELAY
value|10000
end_define

begin_comment
comment|/* Calculate X540 delay value in bit times */
end_comment

begin_define
define|#
directive|define
name|IXGBE_DV_X540
parameter_list|(
name|_max_frame_link
parameter_list|,
name|_max_frame_tc
parameter_list|)
define|\
value|((36 * \ 			  (IXGBE_B2BT(_max_frame_link) + \ 			   IXGBE_PFC_D + \ 			   (2 * IXGBE_CABLE_DC) + \ 			   (2 * IXGBE_ID_X540) + \ 			   IXGBE_HD) / 25 + 1) + \ 			 2 * IXGBE_B2BT(_max_frame_tc))
end_define

begin_comment
comment|/* Calculate 82599, 82598 delay value in bit times */
end_comment

begin_define
define|#
directive|define
name|IXGBE_DV
parameter_list|(
name|_max_frame_link
parameter_list|,
name|_max_frame_tc
parameter_list|)
define|\
value|((36 * \ 			  (IXGBE_B2BT(_max_frame_link) + \ 			   IXGBE_PFC_D + \ 			   (2 * IXGBE_CABLE_DC) + \ 			   (2 * IXGBE_ID) + \ 			   IXGBE_HD) / 25 + 1) + \ 			 2 * IXGBE_B2BT(_max_frame_tc))
end_define

begin_comment
comment|/* Calculate low threshold delay values */
end_comment

begin_define
define|#
directive|define
name|IXGBE_LOW_DV_X540
parameter_list|(
name|_max_frame_tc
parameter_list|)
define|\
value|(2 * IXGBE_B2BT(_max_frame_tc) + \ 			(36 * IXGBE_PCI_DELAY / 25) + 1)
end_define

begin_define
define|#
directive|define
name|IXGBE_LOW_DV
parameter_list|(
name|_max_frame_tc
parameter_list|)
define|\
value|(2 * IXGBE_LOW_DV_X540(_max_frame_tc))
end_define

begin_comment
comment|/* Software ATR hash keys */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ATR_BUCKET_HASH_KEY
value|0x3DAD14E2
end_define

begin_define
define|#
directive|define
name|IXGBE_ATR_SIGNATURE_HASH_KEY
value|0x174D3614
end_define

begin_comment
comment|/* Software ATR input stream values and masks */
end_comment

begin_define
define|#
directive|define
name|IXGBE_ATR_HASH_MASK
value|0x7fff
end_define

begin_define
define|#
directive|define
name|IXGBE_ATR_L4TYPE_MASK
value|0x3
end_define

begin_define
define|#
directive|define
name|IXGBE_ATR_L4TYPE_UDP
value|0x1
end_define

begin_define
define|#
directive|define
name|IXGBE_ATR_L4TYPE_TCP
value|0x2
end_define

begin_define
define|#
directive|define
name|IXGBE_ATR_L4TYPE_SCTP
value|0x3
end_define

begin_define
define|#
directive|define
name|IXGBE_ATR_L4TYPE_IPV6_MASK
value|0x4
end_define

begin_define
define|#
directive|define
name|IXGBE_ATR_L4TYPE_TUNNEL_MASK
value|0x10
end_define

begin_enum
enum|enum
name|ixgbe_atr_flow_type
block|{
name|IXGBE_ATR_FLOW_TYPE_IPV4
init|=
literal|0x0
block|,
name|IXGBE_ATR_FLOW_TYPE_UDPV4
init|=
literal|0x1
block|,
name|IXGBE_ATR_FLOW_TYPE_TCPV4
init|=
literal|0x2
block|,
name|IXGBE_ATR_FLOW_TYPE_SCTPV4
init|=
literal|0x3
block|,
name|IXGBE_ATR_FLOW_TYPE_IPV6
init|=
literal|0x4
block|,
name|IXGBE_ATR_FLOW_TYPE_UDPV6
init|=
literal|0x5
block|,
name|IXGBE_ATR_FLOW_TYPE_TCPV6
init|=
literal|0x6
block|,
name|IXGBE_ATR_FLOW_TYPE_SCTPV6
init|=
literal|0x7
block|,
name|IXGBE_ATR_FLOW_TYPE_TUNNELED_IPV4
init|=
literal|0x10
block|,
name|IXGBE_ATR_FLOW_TYPE_TUNNELED_UDPV4
init|=
literal|0x11
block|,
name|IXGBE_ATR_FLOW_TYPE_TUNNELED_TCPV4
init|=
literal|0x12
block|,
name|IXGBE_ATR_FLOW_TYPE_TUNNELED_SCTPV4
init|=
literal|0x13
block|,
name|IXGBE_ATR_FLOW_TYPE_TUNNELED_IPV6
init|=
literal|0x14
block|,
name|IXGBE_ATR_FLOW_TYPE_TUNNELED_UDPV6
init|=
literal|0x15
block|,
name|IXGBE_ATR_FLOW_TYPE_TUNNELED_TCPV6
init|=
literal|0x16
block|,
name|IXGBE_ATR_FLOW_TYPE_TUNNELED_SCTPV6
init|=
literal|0x17
block|, }
enum|;
end_enum

begin_comment
comment|/* Flow Director ATR input struct. */
end_comment

begin_union
union|union
name|ixgbe_atr_input
block|{
comment|/* 	 * Byte layout in order, all values with MSB first: 	 * 	 * vm_pool	- 1 byte 	 * flow_type	- 1 byte 	 * vlan_id	- 2 bytes 	 * src_ip	- 16 bytes 	 * inner_mac	- 6 bytes 	 * cloud_mode	- 2 bytes 	 * tni_vni	- 4 bytes 	 * dst_ip	- 16 bytes 	 * src_port	- 2 bytes 	 * dst_port	- 2 bytes 	 * flex_bytes	- 2 bytes 	 * bkt_hash	- 2 bytes 	 */
struct|struct
block|{
name|u8
name|vm_pool
decl_stmt|;
name|u8
name|flow_type
decl_stmt|;
name|__be16
name|vlan_id
decl_stmt|;
name|__be32
name|dst_ip
index|[
literal|4
index|]
decl_stmt|;
name|__be32
name|src_ip
index|[
literal|4
index|]
decl_stmt|;
name|u8
name|inner_mac
index|[
literal|6
index|]
decl_stmt|;
name|__be16
name|tunnel_type
decl_stmt|;
name|__be32
name|tni_vni
decl_stmt|;
name|__be16
name|src_port
decl_stmt|;
name|__be16
name|dst_port
decl_stmt|;
name|__be16
name|flex_bytes
decl_stmt|;
name|__be16
name|bkt_hash
decl_stmt|;
block|}
name|formatted
struct|;
name|__be32
name|dword_stream
index|[
literal|14
index|]
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/* Flow Director compressed ATR hash input struct */
end_comment

begin_union
union|union
name|ixgbe_atr_hash_dword
block|{
struct|struct
block|{
name|u8
name|vm_pool
decl_stmt|;
name|u8
name|flow_type
decl_stmt|;
name|__be16
name|vlan_id
decl_stmt|;
block|}
name|formatted
struct|;
name|__be32
name|ip
decl_stmt|;
struct|struct
block|{
name|__be16
name|src
decl_stmt|;
name|__be16
name|dst
decl_stmt|;
block|}
name|port
struct|;
name|__be16
name|flex_bytes
decl_stmt|;
name|__be32
name|dword
decl_stmt|;
block|}
union|;
end_union

begin_define
define|#
directive|define
name|IXGBE_MVALS_INIT
parameter_list|(
name|m
parameter_list|)
define|\
value|IXGBE_CAT(EEC, m),		\ 	IXGBE_CAT(FLA, m),		\ 	IXGBE_CAT(GRC, m),		\ 	IXGBE_CAT(SRAMREL, m),		\ 	IXGBE_CAT(FACTPS, m),		\ 	IXGBE_CAT(SWSM, m),		\ 	IXGBE_CAT(SWFW_SYNC, m),	\ 	IXGBE_CAT(FWSM, m),		\ 	IXGBE_CAT(SDP0_GPIEN, m),	\ 	IXGBE_CAT(SDP1_GPIEN, m),	\ 	IXGBE_CAT(SDP2_GPIEN, m),	\ 	IXGBE_CAT(EICR_GPI_SDP0, m),	\ 	IXGBE_CAT(EICR_GPI_SDP1, m),	\ 	IXGBE_CAT(EICR_GPI_SDP2, m),	\ 	IXGBE_CAT(CIAA, m),		\ 	IXGBE_CAT(CIAD, m),		\ 	IXGBE_CAT(I2C_CLK_IN, m),	\ 	IXGBE_CAT(I2C_CLK_OUT, m),	\ 	IXGBE_CAT(I2C_DATA_IN, m),	\ 	IXGBE_CAT(I2C_DATA_OUT, m),	\ 	IXGBE_CAT(I2C_DATA_OE_N_EN, m),	\ 	IXGBE_CAT(I2C_BB_EN, m),	\ 	IXGBE_CAT(I2C_CLK_OE_N_EN, m),	\ 	IXGBE_CAT(I2CCTL, m)
end_define

begin_enum
enum|enum
name|ixgbe_mvals
block|{
name|IXGBE_MVALS_INIT
argument_list|(
name|_IDX
argument_list|)
block|,
name|IXGBE_MVALS_IDX_LIMIT
block|}
enum|;
end_enum

begin_comment
comment|/*  * Unavailable: The FCoE Boot Option ROM is not present in the flash.  * Disabled: Present; boot order is not set for any targets on the port.  * Enabled: Present; boot order is set for at least one target on the port.  */
end_comment

begin_enum
enum|enum
name|ixgbe_fcoe_boot_status
block|{
name|ixgbe_fcoe_bootstatus_disabled
init|=
literal|0
block|,
name|ixgbe_fcoe_bootstatus_enabled
init|=
literal|1
block|,
name|ixgbe_fcoe_bootstatus_unavailable
init|=
literal|0xFFFF
block|}
enum|;
end_enum

begin_enum
enum|enum
name|ixgbe_eeprom_type
block|{
name|ixgbe_eeprom_uninitialized
init|=
literal|0
block|,
name|ixgbe_eeprom_spi
block|,
name|ixgbe_flash
block|,
name|ixgbe_eeprom_none
comment|/* No NVM support */
block|}
enum|;
end_enum

begin_enum
enum|enum
name|ixgbe_mac_type
block|{
name|ixgbe_mac_unknown
init|=
literal|0
block|,
name|ixgbe_mac_82598EB
block|,
name|ixgbe_mac_82599EB
block|,
name|ixgbe_mac_82599_vf
block|,
name|ixgbe_mac_X540
block|,
name|ixgbe_mac_X540_vf
block|,
name|ixgbe_mac_X550
block|,
name|ixgbe_mac_X550EM_x
block|,
name|ixgbe_mac_X550EM_a
block|,
name|ixgbe_mac_X550_vf
block|,
name|ixgbe_mac_X550EM_x_vf
block|,
name|ixgbe_mac_X550EM_a_vf
block|,
name|ixgbe_num_macs
block|}
enum|;
end_enum

begin_enum
enum|enum
name|ixgbe_phy_type
block|{
name|ixgbe_phy_unknown
init|=
literal|0
block|,
name|ixgbe_phy_none
block|,
name|ixgbe_phy_tn
block|,
name|ixgbe_phy_aq
block|,
name|ixgbe_phy_x550em_kr
block|,
name|ixgbe_phy_x550em_kx4
block|,
name|ixgbe_phy_x550em_xfi
block|,
name|ixgbe_phy_x550em_ext_t
block|,
name|ixgbe_phy_ext_1g_t
block|,
name|ixgbe_phy_cu_unknown
block|,
name|ixgbe_phy_qt
block|,
name|ixgbe_phy_xaui
block|,
name|ixgbe_phy_nl
block|,
name|ixgbe_phy_sfp_passive_tyco
block|,
name|ixgbe_phy_sfp_passive_unknown
block|,
name|ixgbe_phy_sfp_active_unknown
block|,
name|ixgbe_phy_sfp_avago
block|,
name|ixgbe_phy_sfp_ftl
block|,
name|ixgbe_phy_sfp_ftl_active
block|,
name|ixgbe_phy_sfp_unknown
block|,
name|ixgbe_phy_sfp_intel
block|,
name|ixgbe_phy_qsfp_passive_unknown
block|,
name|ixgbe_phy_qsfp_active_unknown
block|,
name|ixgbe_phy_qsfp_intel
block|,
name|ixgbe_phy_qsfp_unknown
block|,
name|ixgbe_phy_sfp_unsupported
block|,
comment|/*Enforce bit set with unsupported module*/
name|ixgbe_phy_sgmii
block|,
name|ixgbe_phy_fw
block|,
name|ixgbe_phy_generic
block|}
enum|;
end_enum

begin_comment
comment|/*  * SFP+ module type IDs:  *  * ID	Module Type  * =============  * 0	SFP_DA_CU  * 1	SFP_SR  * 2	SFP_LR  * 3	SFP_DA_CU_CORE0 - 82599-specific  * 4	SFP_DA_CU_CORE1 - 82599-specific  * 5	SFP_SR/LR_CORE0 - 82599-specific  * 6	SFP_SR/LR_CORE1 - 82599-specific  */
end_comment

begin_enum
enum|enum
name|ixgbe_sfp_type
block|{
name|ixgbe_sfp_type_da_cu
init|=
literal|0
block|,
name|ixgbe_sfp_type_sr
init|=
literal|1
block|,
name|ixgbe_sfp_type_lr
init|=
literal|2
block|,
name|ixgbe_sfp_type_da_cu_core0
init|=
literal|3
block|,
name|ixgbe_sfp_type_da_cu_core1
init|=
literal|4
block|,
name|ixgbe_sfp_type_srlr_core0
init|=
literal|5
block|,
name|ixgbe_sfp_type_srlr_core1
init|=
literal|6
block|,
name|ixgbe_sfp_type_da_act_lmt_core0
init|=
literal|7
block|,
name|ixgbe_sfp_type_da_act_lmt_core1
init|=
literal|8
block|,
name|ixgbe_sfp_type_1g_cu_core0
init|=
literal|9
block|,
name|ixgbe_sfp_type_1g_cu_core1
init|=
literal|10
block|,
name|ixgbe_sfp_type_1g_sx_core0
init|=
literal|11
block|,
name|ixgbe_sfp_type_1g_sx_core1
init|=
literal|12
block|,
name|ixgbe_sfp_type_1g_lx_core0
init|=
literal|13
block|,
name|ixgbe_sfp_type_1g_lx_core1
init|=
literal|14
block|,
name|ixgbe_sfp_type_not_present
init|=
literal|0xFFFE
block|,
name|ixgbe_sfp_type_unknown
init|=
literal|0xFFFF
block|}
enum|;
end_enum

begin_enum
enum|enum
name|ixgbe_media_type
block|{
name|ixgbe_media_type_unknown
init|=
literal|0
block|,
name|ixgbe_media_type_fiber
block|,
name|ixgbe_media_type_fiber_fixed
block|,
name|ixgbe_media_type_fiber_qsfp
block|,
name|ixgbe_media_type_copper
block|,
name|ixgbe_media_type_backplane
block|,
name|ixgbe_media_type_cx4
block|,
name|ixgbe_media_type_virtual
block|}
enum|;
end_enum

begin_comment
comment|/* Flow Control Settings */
end_comment

begin_enum
enum|enum
name|ixgbe_fc_mode
block|{
name|ixgbe_fc_none
init|=
literal|0
block|,
name|ixgbe_fc_rx_pause
block|,
name|ixgbe_fc_tx_pause
block|,
name|ixgbe_fc_full
block|,
name|ixgbe_fc_default
block|}
enum|;
end_enum

begin_comment
comment|/* Smart Speed Settings */
end_comment

begin_define
define|#
directive|define
name|IXGBE_SMARTSPEED_MAX_RETRIES
value|3
end_define

begin_enum
enum|enum
name|ixgbe_smart_speed
block|{
name|ixgbe_smart_speed_auto
init|=
literal|0
block|,
name|ixgbe_smart_speed_on
block|,
name|ixgbe_smart_speed_off
block|}
enum|;
end_enum

begin_comment
comment|/* PCI bus types */
end_comment

begin_enum
enum|enum
name|ixgbe_bus_type
block|{
name|ixgbe_bus_type_unknown
init|=
literal|0
block|,
name|ixgbe_bus_type_pci
block|,
name|ixgbe_bus_type_pcix
block|,
name|ixgbe_bus_type_pci_express
block|,
name|ixgbe_bus_type_internal
block|,
name|ixgbe_bus_type_reserved
block|}
enum|;
end_enum

begin_comment
comment|/* PCI bus speeds */
end_comment

begin_enum
enum|enum
name|ixgbe_bus_speed
block|{
name|ixgbe_bus_speed_unknown
init|=
literal|0
block|,
name|ixgbe_bus_speed_33
init|=
literal|33
block|,
name|ixgbe_bus_speed_66
init|=
literal|66
block|,
name|ixgbe_bus_speed_100
init|=
literal|100
block|,
name|ixgbe_bus_speed_120
init|=
literal|120
block|,
name|ixgbe_bus_speed_133
init|=
literal|133
block|,
name|ixgbe_bus_speed_2500
init|=
literal|2500
block|,
name|ixgbe_bus_speed_5000
init|=
literal|5000
block|,
name|ixgbe_bus_speed_8000
init|=
literal|8000
block|,
name|ixgbe_bus_speed_reserved
block|}
enum|;
end_enum

begin_comment
comment|/* PCI bus widths */
end_comment

begin_enum
enum|enum
name|ixgbe_bus_width
block|{
name|ixgbe_bus_width_unknown
init|=
literal|0
block|,
name|ixgbe_bus_width_pcie_x1
init|=
literal|1
block|,
name|ixgbe_bus_width_pcie_x2
init|=
literal|2
block|,
name|ixgbe_bus_width_pcie_x4
init|=
literal|4
block|,
name|ixgbe_bus_width_pcie_x8
init|=
literal|8
block|,
name|ixgbe_bus_width_32
init|=
literal|32
block|,
name|ixgbe_bus_width_64
init|=
literal|64
block|,
name|ixgbe_bus_width_reserved
block|}
enum|;
end_enum

begin_struct
struct|struct
name|ixgbe_addr_filter_info
block|{
name|u32
name|num_mc_addrs
decl_stmt|;
name|u32
name|rar_used_count
decl_stmt|;
name|u32
name|mta_in_use
decl_stmt|;
name|u32
name|overflow_promisc
decl_stmt|;
name|bool
name|user_set_promisc
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Bus parameters */
end_comment

begin_struct
struct|struct
name|ixgbe_bus_info
block|{
name|enum
name|ixgbe_bus_speed
name|speed
decl_stmt|;
name|enum
name|ixgbe_bus_width
name|width
decl_stmt|;
name|enum
name|ixgbe_bus_type
name|type
decl_stmt|;
name|u16
name|func
decl_stmt|;
name|u8
name|lan_id
decl_stmt|;
name|u16
name|instance_id
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Flow control parameters */
end_comment

begin_struct
struct|struct
name|ixgbe_fc_info
block|{
name|u32
name|high_water
index|[
name|IXGBE_DCB_MAX_TRAFFIC_CLASS
index|]
decl_stmt|;
comment|/* Flow Ctrl High-water */
name|u32
name|low_water
index|[
name|IXGBE_DCB_MAX_TRAFFIC_CLASS
index|]
decl_stmt|;
comment|/* Flow Ctrl Low-water */
name|u16
name|pause_time
decl_stmt|;
comment|/* Flow Control Pause timer */
name|bool
name|send_xon
decl_stmt|;
comment|/* Flow control send XON */
name|bool
name|strict_ieee
decl_stmt|;
comment|/* Strict IEEE mode */
name|bool
name|disable_fc_autoneg
decl_stmt|;
comment|/* Do not autonegotiate FC */
name|bool
name|fc_was_autonegged
decl_stmt|;
comment|/* Is current_mode the result of autonegging? */
name|enum
name|ixgbe_fc_mode
name|current_mode
decl_stmt|;
comment|/* FC mode in effect */
name|enum
name|ixgbe_fc_mode
name|requested_mode
decl_stmt|;
comment|/* FC mode requested by caller */
block|}
struct|;
end_struct

begin_comment
comment|/* Statistics counters collected by the MAC */
end_comment

begin_struct
struct|struct
name|ixgbe_hw_stats
block|{
name|u64
name|crcerrs
decl_stmt|;
name|u64
name|illerrc
decl_stmt|;
name|u64
name|errbc
decl_stmt|;
name|u64
name|mspdc
decl_stmt|;
name|u64
name|mpctotal
decl_stmt|;
name|u64
name|mpc
index|[
literal|8
index|]
decl_stmt|;
name|u64
name|mlfc
decl_stmt|;
name|u64
name|mrfc
decl_stmt|;
name|u64
name|rlec
decl_stmt|;
name|u64
name|lxontxc
decl_stmt|;
name|u64
name|lxonrxc
decl_stmt|;
name|u64
name|lxofftxc
decl_stmt|;
name|u64
name|lxoffrxc
decl_stmt|;
name|u64
name|pxontxc
index|[
literal|8
index|]
decl_stmt|;
name|u64
name|pxonrxc
index|[
literal|8
index|]
decl_stmt|;
name|u64
name|pxofftxc
index|[
literal|8
index|]
decl_stmt|;
name|u64
name|pxoffrxc
index|[
literal|8
index|]
decl_stmt|;
name|u64
name|prc64
decl_stmt|;
name|u64
name|prc127
decl_stmt|;
name|u64
name|prc255
decl_stmt|;
name|u64
name|prc511
decl_stmt|;
name|u64
name|prc1023
decl_stmt|;
name|u64
name|prc1522
decl_stmt|;
name|u64
name|gprc
decl_stmt|;
name|u64
name|bprc
decl_stmt|;
name|u64
name|mprc
decl_stmt|;
name|u64
name|gptc
decl_stmt|;
name|u64
name|gorc
decl_stmt|;
name|u64
name|gotc
decl_stmt|;
name|u64
name|rnbc
index|[
literal|8
index|]
decl_stmt|;
name|u64
name|ruc
decl_stmt|;
name|u64
name|rfc
decl_stmt|;
name|u64
name|roc
decl_stmt|;
name|u64
name|rjc
decl_stmt|;
name|u64
name|mngprc
decl_stmt|;
name|u64
name|mngpdc
decl_stmt|;
name|u64
name|mngptc
decl_stmt|;
name|u64
name|tor
decl_stmt|;
name|u64
name|tpr
decl_stmt|;
name|u64
name|tpt
decl_stmt|;
name|u64
name|ptc64
decl_stmt|;
name|u64
name|ptc127
decl_stmt|;
name|u64
name|ptc255
decl_stmt|;
name|u64
name|ptc511
decl_stmt|;
name|u64
name|ptc1023
decl_stmt|;
name|u64
name|ptc1522
decl_stmt|;
name|u64
name|mptc
decl_stmt|;
name|u64
name|bptc
decl_stmt|;
name|u64
name|xec
decl_stmt|;
name|u64
name|qprc
index|[
literal|16
index|]
decl_stmt|;
name|u64
name|qptc
index|[
literal|16
index|]
decl_stmt|;
name|u64
name|qbrc
index|[
literal|16
index|]
decl_stmt|;
name|u64
name|qbtc
index|[
literal|16
index|]
decl_stmt|;
name|u64
name|qprdc
index|[
literal|16
index|]
decl_stmt|;
name|u64
name|pxon2offc
index|[
literal|8
index|]
decl_stmt|;
name|u64
name|fdirustat_add
decl_stmt|;
name|u64
name|fdirustat_remove
decl_stmt|;
name|u64
name|fdirfstat_fadd
decl_stmt|;
name|u64
name|fdirfstat_fremove
decl_stmt|;
name|u64
name|fdirmatch
decl_stmt|;
name|u64
name|fdirmiss
decl_stmt|;
name|u64
name|fccrc
decl_stmt|;
name|u64
name|fclast
decl_stmt|;
name|u64
name|fcoerpdc
decl_stmt|;
name|u64
name|fcoeprc
decl_stmt|;
name|u64
name|fcoeptc
decl_stmt|;
name|u64
name|fcoedwrc
decl_stmt|;
name|u64
name|fcoedwtc
decl_stmt|;
name|u64
name|fcoe_noddp
decl_stmt|;
name|u64
name|fcoe_noddp_ext_buff
decl_stmt|;
name|u64
name|ldpcec
decl_stmt|;
name|u64
name|pcrc8ec
decl_stmt|;
name|u64
name|b2ospc
decl_stmt|;
name|u64
name|b2ogprc
decl_stmt|;
name|u64
name|o2bgptc
decl_stmt|;
name|u64
name|o2bspc
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* forward declaration */
end_comment

begin_struct_decl
struct_decl|struct
name|ixgbe_hw
struct_decl|;
end_struct_decl

begin_comment
comment|/* iterator type for walking multicast address lists */
end_comment

begin_typedef
typedef|typedef
name|u8
modifier|*
function_decl|(
modifier|*
name|ixgbe_mc_addr_itr
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
name|hw
parameter_list|,
name|u8
modifier|*
modifier|*
name|mc_addr_ptr
parameter_list|,
name|u32
modifier|*
name|vmdq
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* Function pointer table */
end_comment

begin_struct
struct|struct
name|ixgbe_eeprom_operations
block|{
name|s32
function_decl|(
modifier|*
name|init_params
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|read
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|,
name|u16
parameter_list|,
name|u16
modifier|*
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|read_buffer
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|,
name|u16
parameter_list|,
name|u16
parameter_list|,
name|u16
modifier|*
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|write
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|,
name|u16
parameter_list|,
name|u16
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|write_buffer
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|,
name|u16
parameter_list|,
name|u16
parameter_list|,
name|u16
modifier|*
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|validate_checksum
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|,
name|u16
modifier|*
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|update_checksum
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|calc_checksum
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ixgbe_mac_operations
block|{
name|s32
function_decl|(
modifier|*
name|init_hw
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|reset_hw
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|start_hw
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|clear_hw_cntrs
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|enable_relaxed_ordering
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|)
function_decl|;
name|enum
name|ixgbe_media_type
function_decl|(
modifier|*
name|get_media_type
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|)
function_decl|;
name|u64
function_decl|(
modifier|*
name|get_supported_physical_layer
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|get_mac_addr
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|,
name|u8
modifier|*
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|get_san_mac_addr
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|,
name|u8
modifier|*
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|set_san_mac_addr
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|,
name|u8
modifier|*
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|get_device_caps
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|,
name|u16
modifier|*
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|get_wwn_prefix
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|,
name|u16
modifier|*
parameter_list|,
name|u16
modifier|*
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|get_fcoe_boot_status
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|,
name|u16
modifier|*
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|stop_adapter
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|get_bus_info
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|negotiate_api_version
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|set_lan_id
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|read_analog_reg8
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|,
name|u32
parameter_list|,
name|u8
modifier|*
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|write_analog_reg8
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|,
name|u32
parameter_list|,
name|u8
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|setup_sfp
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|enable_rx_dma
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|,
name|u32
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|disable_sec_rx_path
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|enable_sec_rx_path
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|acquire_swfw_sync
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|,
name|u32
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|release_swfw_sync
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|,
name|u32
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|init_swfw_sync
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|prot_autoc_read
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|,
name|bool
modifier|*
parameter_list|,
name|u32
modifier|*
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|prot_autoc_write
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|,
name|u32
parameter_list|,
name|bool
parameter_list|)
function_decl|;
comment|/* Link */
name|void
function_decl|(
modifier|*
name|disable_tx_laser
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|enable_tx_laser
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|flap_tx_laser
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|setup_link
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|,
name|ixgbe_link_speed
parameter_list|,
name|bool
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|setup_mac_link
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|,
name|ixgbe_link_speed
parameter_list|,
name|bool
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|check_link
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|,
name|ixgbe_link_speed
modifier|*
parameter_list|,
name|bool
modifier|*
parameter_list|,
name|bool
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|get_link_capabilities
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|,
name|ixgbe_link_speed
modifier|*
parameter_list|,
name|bool
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|set_rate_select_speed
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|,
name|ixgbe_link_speed
parameter_list|)
function_decl|;
comment|/* Packet Buffer manipulation */
name|void
function_decl|(
modifier|*
name|setup_rxpba
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|,
name|int
parameter_list|,
name|u32
parameter_list|,
name|int
parameter_list|)
function_decl|;
comment|/* LED */
name|s32
function_decl|(
modifier|*
name|led_on
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|,
name|u32
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|led_off
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|,
name|u32
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|blink_led_start
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|,
name|u32
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|blink_led_stop
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|,
name|u32
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|init_led_link_act
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|)
function_decl|;
comment|/* RAR, Multicast, VLAN */
name|s32
function_decl|(
modifier|*
name|set_rar
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|,
name|u32
parameter_list|,
name|u8
modifier|*
parameter_list|,
name|u32
parameter_list|,
name|u32
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|set_uc_addr
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|,
name|u32
parameter_list|,
name|u8
modifier|*
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|clear_rar
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|,
name|u32
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|insert_mac_addr
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|,
name|u8
modifier|*
parameter_list|,
name|u32
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|set_vmdq
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|,
name|u32
parameter_list|,
name|u32
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|set_vmdq_san_mac
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|,
name|u32
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|clear_vmdq
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|,
name|u32
parameter_list|,
name|u32
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|init_rx_addrs
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|update_uc_addr_list
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|,
name|u8
modifier|*
parameter_list|,
name|u32
parameter_list|,
name|ixgbe_mc_addr_itr
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|update_mc_addr_list
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|,
name|u8
modifier|*
parameter_list|,
name|u32
parameter_list|,
name|ixgbe_mc_addr_itr
parameter_list|,
name|bool
name|clear
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|update_xcast_mode
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|enable_mc
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|disable_mc
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|clear_vfta
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|set_vfta
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|,
name|u32
parameter_list|,
name|u32
parameter_list|,
name|bool
parameter_list|,
name|bool
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|set_vlvf
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|,
name|u32
parameter_list|,
name|u32
parameter_list|,
name|bool
parameter_list|,
name|u32
modifier|*
parameter_list|,
name|u32
parameter_list|,
name|bool
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|set_rlpml
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|,
name|u16
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|init_uta_tables
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|set_mac_anti_spoofing
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|,
name|bool
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|set_vlan_anti_spoofing
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|,
name|bool
parameter_list|,
name|int
parameter_list|)
function_decl|;
comment|/* Flow Control */
name|s32
function_decl|(
modifier|*
name|fc_enable
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|setup_fc
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|fc_autoneg
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|)
function_decl|;
comment|/* Manageability interface */
name|s32
function_decl|(
modifier|*
name|set_fw_drv_ver
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|,
name|u8
parameter_list|,
name|u8
parameter_list|,
name|u8
parameter_list|,
name|u8
parameter_list|,
name|u16
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|bypass_rw
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
name|hw
parameter_list|,
name|u32
name|cmd
parameter_list|,
name|u32
modifier|*
name|status
parameter_list|)
function_decl|;
name|bool
function_decl|(
modifier|*
name|bypass_valid_rd
function_decl|)
parameter_list|(
name|u32
name|in_reg
parameter_list|,
name|u32
name|out_reg
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|bypass_set
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
name|hw
parameter_list|,
name|u32
name|cmd
parameter_list|,
name|u32
name|event
parameter_list|,
name|u32
name|action
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|bypass_rd_eep
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
name|hw
parameter_list|,
name|u32
name|addr
parameter_list|,
name|u8
modifier|*
name|value
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|get_rtrup2tc
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
name|hw
parameter_list|,
name|u8
modifier|*
name|map
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|disable_rx
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|enable_rx
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|set_source_address_pruning
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|,
name|bool
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|set_ethertype_anti_spoofing
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|,
name|bool
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|dmac_update_tcs
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|dmac_config_tcs
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|dmac_config
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|setup_eee
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
name|hw
parameter_list|,
name|bool
name|enable_eee
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|read_iosf_sb_reg
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|,
name|u32
parameter_list|,
name|u32
parameter_list|,
name|u32
modifier|*
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|write_iosf_sb_reg
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|,
name|u32
parameter_list|,
name|u32
parameter_list|,
name|u32
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|disable_mdd
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|enable_mdd
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|mdd_event
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
name|hw
parameter_list|,
name|u32
modifier|*
name|vf_bitmap
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|restore_mdd_vf
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
name|hw
parameter_list|,
name|u32
name|vf
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ixgbe_phy_operations
block|{
name|s32
function_decl|(
modifier|*
name|identify
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|identify_sfp
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|init
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|reset
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|read_reg
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|,
name|u32
parameter_list|,
name|u32
parameter_list|,
name|u16
modifier|*
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|write_reg
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|,
name|u32
parameter_list|,
name|u32
parameter_list|,
name|u16
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|read_reg_mdi
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|,
name|u32
parameter_list|,
name|u32
parameter_list|,
name|u16
modifier|*
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|write_reg_mdi
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|,
name|u32
parameter_list|,
name|u32
parameter_list|,
name|u16
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|setup_link
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|setup_internal_link
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|setup_link_speed
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|,
name|ixgbe_link_speed
parameter_list|,
name|bool
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|check_link
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|,
name|ixgbe_link_speed
modifier|*
parameter_list|,
name|bool
modifier|*
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|get_firmware_version
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|,
name|u16
modifier|*
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|read_i2c_byte
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|,
name|u8
parameter_list|,
name|u8
parameter_list|,
name|u8
modifier|*
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|write_i2c_byte
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|,
name|u8
parameter_list|,
name|u8
parameter_list|,
name|u8
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|read_i2c_sff8472
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|,
name|u8
parameter_list|,
name|u8
modifier|*
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|read_i2c_eeprom
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|,
name|u8
parameter_list|,
name|u8
modifier|*
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|write_i2c_eeprom
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|,
name|u8
parameter_list|,
name|u8
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|i2c_bus_clear
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|check_overtemp
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|set_phy_power
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|,
name|bool
name|on
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|enter_lplu
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|handle_lasi
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|read_i2c_byte_unlocked
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|,
name|u8
name|offset
parameter_list|,
name|u8
name|addr
parameter_list|,
name|u8
modifier|*
name|value
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|write_i2c_byte_unlocked
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|,
name|u8
name|offset
parameter_list|,
name|u8
name|addr
parameter_list|,
name|u8
name|value
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ixgbe_link_operations
block|{
name|s32
function_decl|(
modifier|*
name|read_link
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|,
name|u8
name|addr
parameter_list|,
name|u16
name|reg
parameter_list|,
name|u16
modifier|*
name|val
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|read_link_unlocked
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|,
name|u8
name|addr
parameter_list|,
name|u16
name|reg
parameter_list|,
name|u16
modifier|*
name|val
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|write_link
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|,
name|u8
name|addr
parameter_list|,
name|u16
name|reg
parameter_list|,
name|u16
name|val
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|write_link_unlocked
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|,
name|u8
name|addr
parameter_list|,
name|u16
name|reg
parameter_list|,
name|u16
name|val
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ixgbe_link_info
block|{
name|struct
name|ixgbe_link_operations
name|ops
decl_stmt|;
name|u8
name|addr
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ixgbe_eeprom_info
block|{
name|struct
name|ixgbe_eeprom_operations
name|ops
decl_stmt|;
name|enum
name|ixgbe_eeprom_type
name|type
decl_stmt|;
name|u32
name|semaphore_delay
decl_stmt|;
name|u16
name|word_size
decl_stmt|;
name|u16
name|address_bits
decl_stmt|;
name|u16
name|word_page_size
decl_stmt|;
name|u16
name|ctrl_word_3
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IXGBE_FLAGS_DOUBLE_RESET_REQUIRED
value|0x01
end_define

begin_struct
struct|struct
name|ixgbe_mac_info
block|{
name|struct
name|ixgbe_mac_operations
name|ops
decl_stmt|;
name|enum
name|ixgbe_mac_type
name|type
decl_stmt|;
name|u8
name|addr
index|[
name|IXGBE_ETH_LENGTH_OF_ADDRESS
index|]
decl_stmt|;
name|u8
name|perm_addr
index|[
name|IXGBE_ETH_LENGTH_OF_ADDRESS
index|]
decl_stmt|;
name|u8
name|san_addr
index|[
name|IXGBE_ETH_LENGTH_OF_ADDRESS
index|]
decl_stmt|;
comment|/* prefix for World Wide Node Name (WWNN) */
name|u16
name|wwnn_prefix
decl_stmt|;
comment|/* prefix for World Wide Port Name (WWPN) */
name|u16
name|wwpn_prefix
decl_stmt|;
define|#
directive|define
name|IXGBE_MAX_MTA
value|128
name|u32
name|mta_shadow
index|[
name|IXGBE_MAX_MTA
index|]
decl_stmt|;
name|s32
name|mc_filter_type
decl_stmt|;
name|u32
name|mcft_size
decl_stmt|;
name|u32
name|vft_size
decl_stmt|;
name|u32
name|num_rar_entries
decl_stmt|;
name|u32
name|rar_highwater
decl_stmt|;
name|u32
name|rx_pb_size
decl_stmt|;
name|u32
name|max_tx_queues
decl_stmt|;
name|u32
name|max_rx_queues
decl_stmt|;
name|u32
name|orig_autoc
decl_stmt|;
name|u8
name|san_mac_rar_index
decl_stmt|;
name|bool
name|get_link_status
decl_stmt|;
name|u32
name|orig_autoc2
decl_stmt|;
name|u16
name|max_msix_vectors
decl_stmt|;
name|bool
name|arc_subsystem_valid
decl_stmt|;
name|bool
name|orig_link_settings_stored
decl_stmt|;
name|bool
name|autotry_restart
decl_stmt|;
name|u8
name|flags
decl_stmt|;
name|struct
name|ixgbe_dmac_config
name|dmac_config
decl_stmt|;
name|bool
name|set_lben
decl_stmt|;
name|u32
name|max_link_up_time
decl_stmt|;
name|u8
name|led_link_act
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ixgbe_phy_info
block|{
name|struct
name|ixgbe_phy_operations
name|ops
decl_stmt|;
name|enum
name|ixgbe_phy_type
name|type
decl_stmt|;
name|u32
name|addr
decl_stmt|;
name|u32
name|id
decl_stmt|;
name|enum
name|ixgbe_sfp_type
name|sfp_type
decl_stmt|;
name|bool
name|sfp_setup_needed
decl_stmt|;
name|u32
name|revision
decl_stmt|;
name|enum
name|ixgbe_media_type
name|media_type
decl_stmt|;
name|u32
name|phy_semaphore_mask
decl_stmt|;
name|bool
name|reset_disable
decl_stmt|;
name|ixgbe_autoneg_advertised
name|autoneg_advertised
decl_stmt|;
name|ixgbe_link_speed
name|speeds_supported
decl_stmt|;
name|ixgbe_link_speed
name|eee_speeds_supported
decl_stmt|;
name|ixgbe_link_speed
name|eee_speeds_advertised
decl_stmt|;
name|enum
name|ixgbe_smart_speed
name|smart_speed
decl_stmt|;
name|bool
name|smart_speed_active
decl_stmt|;
name|bool
name|multispeed_fiber
decl_stmt|;
name|bool
name|reset_if_overtemp
decl_stmt|;
name|bool
name|qsfp_shared_i2c_bus
decl_stmt|;
name|u32
name|nw_mng_if_sel
decl_stmt|;
block|}
struct|;
end_struct

begin_include
include|#
directive|include
file|"ixgbe_mbx.h"
end_include

begin_struct
struct|struct
name|ixgbe_mbx_operations
block|{
name|void
function_decl|(
modifier|*
name|init_params
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|read
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|,
name|u32
modifier|*
parameter_list|,
name|u16
parameter_list|,
name|u16
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|write
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|,
name|u32
modifier|*
parameter_list|,
name|u16
parameter_list|,
name|u16
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|read_posted
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|,
name|u32
modifier|*
parameter_list|,
name|u16
parameter_list|,
name|u16
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|write_posted
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|,
name|u32
modifier|*
parameter_list|,
name|u16
parameter_list|,
name|u16
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|check_for_msg
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|,
name|u16
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|check_for_ack
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|,
name|u16
parameter_list|)
function_decl|;
name|s32
function_decl|(
modifier|*
name|check_for_rst
function_decl|)
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|,
name|u16
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ixgbe_mbx_stats
block|{
name|u32
name|msgs_tx
decl_stmt|;
name|u32
name|msgs_rx
decl_stmt|;
name|u32
name|acks
decl_stmt|;
name|u32
name|reqs
decl_stmt|;
name|u32
name|rsts
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ixgbe_mbx_info
block|{
name|struct
name|ixgbe_mbx_operations
name|ops
decl_stmt|;
name|struct
name|ixgbe_mbx_stats
name|stats
decl_stmt|;
name|u32
name|timeout
decl_stmt|;
name|u32
name|usec_delay
decl_stmt|;
name|u32
name|v2p_mailbox
decl_stmt|;
name|u16
name|size
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ixgbe_hw
block|{
name|u8
name|IOMEM
modifier|*
name|hw_addr
decl_stmt|;
name|void
modifier|*
name|back
decl_stmt|;
name|struct
name|ixgbe_mac_info
name|mac
decl_stmt|;
name|struct
name|ixgbe_addr_filter_info
name|addr_ctrl
decl_stmt|;
name|struct
name|ixgbe_fc_info
name|fc
decl_stmt|;
name|struct
name|ixgbe_phy_info
name|phy
decl_stmt|;
name|struct
name|ixgbe_link_info
name|link
decl_stmt|;
name|struct
name|ixgbe_eeprom_info
name|eeprom
decl_stmt|;
name|struct
name|ixgbe_bus_info
name|bus
decl_stmt|;
name|struct
name|ixgbe_mbx_info
name|mbx
decl_stmt|;
specifier|const
name|u32
modifier|*
name|mvals
decl_stmt|;
name|u16
name|device_id
decl_stmt|;
name|u16
name|vendor_id
decl_stmt|;
name|u16
name|subsystem_device_id
decl_stmt|;
name|u16
name|subsystem_vendor_id
decl_stmt|;
name|u8
name|revision_id
decl_stmt|;
name|bool
name|adapter_stopped
decl_stmt|;
name|int
name|api_version
decl_stmt|;
name|bool
name|force_full_reset
decl_stmt|;
name|bool
name|allow_unsupported_sfp
decl_stmt|;
name|bool
name|wol_enabled
decl_stmt|;
name|bool
name|need_crosstalk_fix
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ixgbe_call_func
parameter_list|(
name|hw
parameter_list|,
name|func
parameter_list|,
name|params
parameter_list|,
name|error
parameter_list|)
define|\
value|(func != NULL) ? func params : error
end_define

begin_comment
comment|/* Error Codes */
end_comment

begin_define
define|#
directive|define
name|IXGBE_SUCCESS
value|0
end_define

begin_define
define|#
directive|define
name|IXGBE_ERR_EEPROM
value|-1
end_define

begin_define
define|#
directive|define
name|IXGBE_ERR_EEPROM_CHECKSUM
value|-2
end_define

begin_define
define|#
directive|define
name|IXGBE_ERR_PHY
value|-3
end_define

begin_define
define|#
directive|define
name|IXGBE_ERR_CONFIG
value|-4
end_define

begin_define
define|#
directive|define
name|IXGBE_ERR_PARAM
value|-5
end_define

begin_define
define|#
directive|define
name|IXGBE_ERR_MAC_TYPE
value|-6
end_define

begin_define
define|#
directive|define
name|IXGBE_ERR_UNKNOWN_PHY
value|-7
end_define

begin_define
define|#
directive|define
name|IXGBE_ERR_LINK_SETUP
value|-8
end_define

begin_define
define|#
directive|define
name|IXGBE_ERR_ADAPTER_STOPPED
value|-9
end_define

begin_define
define|#
directive|define
name|IXGBE_ERR_INVALID_MAC_ADDR
value|-10
end_define

begin_define
define|#
directive|define
name|IXGBE_ERR_DEVICE_NOT_SUPPORTED
value|-11
end_define

begin_define
define|#
directive|define
name|IXGBE_ERR_MASTER_REQUESTS_PENDING
value|-12
end_define

begin_define
define|#
directive|define
name|IXGBE_ERR_INVALID_LINK_SETTINGS
value|-13
end_define

begin_define
define|#
directive|define
name|IXGBE_ERR_AUTONEG_NOT_COMPLETE
value|-14
end_define

begin_define
define|#
directive|define
name|IXGBE_ERR_RESET_FAILED
value|-15
end_define

begin_define
define|#
directive|define
name|IXGBE_ERR_SWFW_SYNC
value|-16
end_define

begin_define
define|#
directive|define
name|IXGBE_ERR_PHY_ADDR_INVALID
value|-17
end_define

begin_define
define|#
directive|define
name|IXGBE_ERR_I2C
value|-18
end_define

begin_define
define|#
directive|define
name|IXGBE_ERR_SFP_NOT_SUPPORTED
value|-19
end_define

begin_define
define|#
directive|define
name|IXGBE_ERR_SFP_NOT_PRESENT
value|-20
end_define

begin_define
define|#
directive|define
name|IXGBE_ERR_SFP_NO_INIT_SEQ_PRESENT
value|-21
end_define

begin_define
define|#
directive|define
name|IXGBE_ERR_NO_SAN_ADDR_PTR
value|-22
end_define

begin_define
define|#
directive|define
name|IXGBE_ERR_FDIR_REINIT_FAILED
value|-23
end_define

begin_define
define|#
directive|define
name|IXGBE_ERR_EEPROM_VERSION
value|-24
end_define

begin_define
define|#
directive|define
name|IXGBE_ERR_NO_SPACE
value|-25
end_define

begin_define
define|#
directive|define
name|IXGBE_ERR_OVERTEMP
value|-26
end_define

begin_define
define|#
directive|define
name|IXGBE_ERR_FC_NOT_NEGOTIATED
value|-27
end_define

begin_define
define|#
directive|define
name|IXGBE_ERR_FC_NOT_SUPPORTED
value|-28
end_define

begin_define
define|#
directive|define
name|IXGBE_ERR_SFP_SETUP_NOT_COMPLETE
value|-30
end_define

begin_define
define|#
directive|define
name|IXGBE_ERR_PBA_SECTION
value|-31
end_define

begin_define
define|#
directive|define
name|IXGBE_ERR_INVALID_ARGUMENT
value|-32
end_define

begin_define
define|#
directive|define
name|IXGBE_ERR_HOST_INTERFACE_COMMAND
value|-33
end_define

begin_define
define|#
directive|define
name|IXGBE_ERR_OUT_OF_MEM
value|-34
end_define

begin_define
define|#
directive|define
name|IXGBE_BYPASS_FW_WRITE_FAILURE
value|-35
end_define

begin_define
define|#
directive|define
name|IXGBE_ERR_FEATURE_NOT_SUPPORTED
value|-36
end_define

begin_define
define|#
directive|define
name|IXGBE_ERR_EEPROM_PROTECTED_REGION
value|-37
end_define

begin_define
define|#
directive|define
name|IXGBE_ERR_FDIR_CMD_INCOMPLETE
value|-38
end_define

begin_define
define|#
directive|define
name|IXGBE_ERR_FW_RESP_INVALID
value|-39
end_define

begin_define
define|#
directive|define
name|IXGBE_ERR_TOKEN_RETRY
value|-40
end_define

begin_define
define|#
directive|define
name|IXGBE_NOT_IMPLEMENTED
value|0x7FFFFFFF
end_define

begin_define
define|#
directive|define
name|BYPASS_PAGE_CTL0
value|0x00000000
end_define

begin_define
define|#
directive|define
name|BYPASS_PAGE_CTL1
value|0x40000000
end_define

begin_define
define|#
directive|define
name|BYPASS_PAGE_CTL2
value|0x80000000
end_define

begin_define
define|#
directive|define
name|BYPASS_PAGE_M
value|0xc0000000
end_define

begin_define
define|#
directive|define
name|BYPASS_WE
value|0x20000000
end_define

begin_define
define|#
directive|define
name|BYPASS_AUTO
value|0x0
end_define

begin_define
define|#
directive|define
name|BYPASS_NOP
value|0x0
end_define

begin_define
define|#
directive|define
name|BYPASS_NORM
value|0x1
end_define

begin_define
define|#
directive|define
name|BYPASS_BYPASS
value|0x2
end_define

begin_define
define|#
directive|define
name|BYPASS_ISOLATE
value|0x3
end_define

begin_define
define|#
directive|define
name|BYPASS_EVENT_MAIN_ON
value|0x1
end_define

begin_define
define|#
directive|define
name|BYPASS_EVENT_AUX_ON
value|0x2
end_define

begin_define
define|#
directive|define
name|BYPASS_EVENT_MAIN_OFF
value|0x3
end_define

begin_define
define|#
directive|define
name|BYPASS_EVENT_AUX_OFF
value|0x4
end_define

begin_define
define|#
directive|define
name|BYPASS_EVENT_WDT_TO
value|0x5
end_define

begin_define
define|#
directive|define
name|BYPASS_EVENT_USR
value|0x6
end_define

begin_define
define|#
directive|define
name|BYPASS_MODE_OFF_M
value|0x00000003
end_define

begin_define
define|#
directive|define
name|BYPASS_STATUS_OFF_M
value|0x0000000c
end_define

begin_define
define|#
directive|define
name|BYPASS_AUX_ON_M
value|0x00000030
end_define

begin_define
define|#
directive|define
name|BYPASS_MAIN_ON_M
value|0x000000c0
end_define

begin_define
define|#
directive|define
name|BYPASS_MAIN_OFF_M
value|0x00000300
end_define

begin_define
define|#
directive|define
name|BYPASS_AUX_OFF_M
value|0x00000c00
end_define

begin_define
define|#
directive|define
name|BYPASS_WDTIMEOUT_M
value|0x00003000
end_define

begin_define
define|#
directive|define
name|BYPASS_WDT_ENABLE_M
value|0x00004000
end_define

begin_define
define|#
directive|define
name|BYPASS_WDT_VALUE_M
value|0x00070000
end_define

begin_define
define|#
directive|define
name|BYPASS_MODE_OFF_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|BYPASS_STATUS_OFF_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|BYPASS_AUX_ON_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|BYPASS_MAIN_ON_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|BYPASS_MAIN_OFF_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|BYPASS_AUX_OFF_SHIFT
value|10
end_define

begin_define
define|#
directive|define
name|BYPASS_WDTIMEOUT_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|BYPASS_WDT_ENABLE_SHIFT
value|14
end_define

begin_define
define|#
directive|define
name|BYPASS_WDT_TIME_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|BYPASS_WDT_1
value|0x0
end_define

begin_define
define|#
directive|define
name|BYPASS_WDT_1_5
value|0x1
end_define

begin_define
define|#
directive|define
name|BYPASS_WDT_2
value|0x2
end_define

begin_define
define|#
directive|define
name|BYPASS_WDT_3
value|0x3
end_define

begin_define
define|#
directive|define
name|BYPASS_WDT_4
value|0x4
end_define

begin_define
define|#
directive|define
name|BYPASS_WDT_8
value|0x5
end_define

begin_define
define|#
directive|define
name|BYPASS_WDT_16
value|0x6
end_define

begin_define
define|#
directive|define
name|BYPASS_WDT_32
value|0x7
end_define

begin_define
define|#
directive|define
name|BYPASS_WDT_OFF
value|0xffff
end_define

begin_define
define|#
directive|define
name|BYPASS_CTL1_TIME_M
value|0x01ffffff
end_define

begin_define
define|#
directive|define
name|BYPASS_CTL1_VALID_M
value|0x02000000
end_define

begin_define
define|#
directive|define
name|BYPASS_CTL1_OFFTRST_M
value|0x04000000
end_define

begin_define
define|#
directive|define
name|BYPASS_CTL1_WDT_PET_M
value|0x08000000
end_define

begin_define
define|#
directive|define
name|BYPASS_CTL1_VALID
value|0x02000000
end_define

begin_define
define|#
directive|define
name|BYPASS_CTL1_OFFTRST
value|0x04000000
end_define

begin_define
define|#
directive|define
name|BYPASS_CTL1_WDT_PET
value|0x08000000
end_define

begin_define
define|#
directive|define
name|BYPASS_CTL2_DATA_M
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|BYPASS_CTL2_OFFSET_M
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|BYPASS_CTL2_RW_M
value|0x00010000
end_define

begin_define
define|#
directive|define
name|BYPASS_CTL2_HEAD_M
value|0x0ff00000
end_define

begin_define
define|#
directive|define
name|BYPASS_CTL2_OFFSET_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|BYPASS_CTL2_HEAD_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|BYPASS_CTL2_RW
value|0x00010000
end_define

begin_struct
struct|struct
name|ixgbe_bypass_eeprom
block|{
name|u32
name|logs
decl_stmt|;
name|u32
name|clear_off
decl_stmt|;
name|u8
name|actions
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|BYPASS_MAX_LOGS
value|43
end_define

begin_define
define|#
directive|define
name|BYPASS_LOG_SIZE
value|5
end_define

begin_define
define|#
directive|define
name|BYPASS_LOG_LINE_SIZE
value|37
end_define

begin_define
define|#
directive|define
name|BYPASS_EEPROM_VER_ADD
value|0x02
end_define

begin_define
define|#
directive|define
name|BYPASS_LOG_TIME_M
value|0x01ffffff
end_define

begin_define
define|#
directive|define
name|BYPASS_LOG_TIME_VALID_M
value|0x02000000
end_define

begin_define
define|#
directive|define
name|BYPASS_LOG_HEAD_M
value|0x04000000
end_define

begin_define
define|#
directive|define
name|BYPASS_LOG_CLEAR_M
value|0x08000000
end_define

begin_define
define|#
directive|define
name|BYPASS_LOG_EVENT_M
value|0xf0000000
end_define

begin_define
define|#
directive|define
name|BYPASS_LOG_ACTION_M
value|0x03
end_define

begin_define
define|#
directive|define
name|BYPASS_LOG_EVENT_SHIFT
value|28
end_define

begin_define
define|#
directive|define
name|BYPASS_LOG_CLEAR_SHIFT
value|24
end_define

begin_comment
comment|/* bit offset */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FUSES0_GROUP
parameter_list|(
name|_i
parameter_list|)
value|(0x11158 + ((_i) * 4))
end_define

begin_define
define|#
directive|define
name|IXGBE_FUSES0_300MHZ
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|IXGBE_FUSES0_REV_MASK
value|(3<< 6)
end_define

begin_define
define|#
directive|define
name|IXGBE_KRM_PORT_CAR_GEN_CTRL
parameter_list|(
name|P
parameter_list|)
value|((P) ? 0x8010 : 0x4010)
end_define

begin_define
define|#
directive|define
name|IXGBE_KRM_LINK_S1
parameter_list|(
name|P
parameter_list|)
value|((P) ? 0x8200 : 0x4200)
end_define

begin_define
define|#
directive|define
name|IXGBE_KRM_LINK_CTRL_1
parameter_list|(
name|P
parameter_list|)
value|((P) ? 0x820C : 0x420C)
end_define

begin_define
define|#
directive|define
name|IXGBE_KRM_AN_CNTL_1
parameter_list|(
name|P
parameter_list|)
value|((P) ? 0x822C : 0x422C)
end_define

begin_define
define|#
directive|define
name|IXGBE_KRM_AN_CNTL_4
parameter_list|(
name|P
parameter_list|)
value|((P) ? 0x8238 : 0x4238)
end_define

begin_define
define|#
directive|define
name|IXGBE_KRM_AN_CNTL_8
parameter_list|(
name|P
parameter_list|)
value|((P) ? 0x8248 : 0x4248)
end_define

begin_define
define|#
directive|define
name|IXGBE_KRM_PCS_KX_AN
parameter_list|(
name|P
parameter_list|)
value|((P) ? 0x9918 : 0x5918)
end_define

begin_define
define|#
directive|define
name|IXGBE_KRM_PCS_KX_AN_LP
parameter_list|(
name|P
parameter_list|)
value|((P) ? 0x991C : 0x591C)
end_define

begin_define
define|#
directive|define
name|IXGBE_KRM_SGMII_CTRL
parameter_list|(
name|P
parameter_list|)
value|((P) ? 0x82A0 : 0x42A0)
end_define

begin_define
define|#
directive|define
name|IXGBE_KRM_LP_BASE_PAGE_HIGH
parameter_list|(
name|P
parameter_list|)
value|((P) ? 0x836C : 0x436C)
end_define

begin_define
define|#
directive|define
name|IXGBE_KRM_DSP_TXFFE_STATE_4
parameter_list|(
name|P
parameter_list|)
value|((P) ? 0x8634 : 0x4634)
end_define

begin_define
define|#
directive|define
name|IXGBE_KRM_DSP_TXFFE_STATE_5
parameter_list|(
name|P
parameter_list|)
value|((P) ? 0x8638 : 0x4638)
end_define

begin_define
define|#
directive|define
name|IXGBE_KRM_RX_TRN_LINKUP_CTRL
parameter_list|(
name|P
parameter_list|)
value|((P) ? 0x8B00 : 0x4B00)
end_define

begin_define
define|#
directive|define
name|IXGBE_KRM_PMD_DFX_BURNIN
parameter_list|(
name|P
parameter_list|)
value|((P) ? 0x8E00 : 0x4E00)
end_define

begin_define
define|#
directive|define
name|IXGBE_KRM_PMD_FLX_MASK_ST20
parameter_list|(
name|P
parameter_list|)
value|((P) ? 0x9054 : 0x5054)
end_define

begin_define
define|#
directive|define
name|IXGBE_KRM_TX_COEFF_CTRL_1
parameter_list|(
name|P
parameter_list|)
value|((P) ? 0x9520 : 0x5520)
end_define

begin_define
define|#
directive|define
name|IXGBE_KRM_RX_ANA_CTL
parameter_list|(
name|P
parameter_list|)
value|((P) ? 0x9A00 : 0x5A00)
end_define

begin_define
define|#
directive|define
name|IXGBE_KRM_PMD_FLX_MASK_ST20_SFI_10G_DA
value|~(0x3<< 20)
end_define

begin_define
define|#
directive|define
name|IXGBE_KRM_PMD_FLX_MASK_ST20_SFI_10G_SR
value|(1u<< 20)
end_define

begin_define
define|#
directive|define
name|IXGBE_KRM_PMD_FLX_MASK_ST20_SFI_10G_LR
value|(0x2<< 20)
end_define

begin_define
define|#
directive|define
name|IXGBE_KRM_PMD_FLX_MASK_ST20_SGMII_EN
value|(1u<< 25)
end_define

begin_define
define|#
directive|define
name|IXGBE_KRM_PMD_FLX_MASK_ST20_AN37_EN
value|(1u<< 26)
end_define

begin_define
define|#
directive|define
name|IXGBE_KRM_PMD_FLX_MASK_ST20_AN_EN
value|(1u<< 27)
end_define

begin_define
define|#
directive|define
name|IXGBE_KRM_PMD_FLX_MASK_ST20_SPEED_10M
value|~(0x7<< 28)
end_define

begin_define
define|#
directive|define
name|IXGBE_KRM_PMD_FLX_MASK_ST20_SPEED_100M
value|(1u<< 28)
end_define

begin_define
define|#
directive|define
name|IXGBE_KRM_PMD_FLX_MASK_ST20_SPEED_1G
value|(0x2<< 28)
end_define

begin_define
define|#
directive|define
name|IXGBE_KRM_PMD_FLX_MASK_ST20_SPEED_10G
value|(0x3<< 28)
end_define

begin_define
define|#
directive|define
name|IXGBE_KRM_PMD_FLX_MASK_ST20_SPEED_AN
value|(0x4<< 28)
end_define

begin_define
define|#
directive|define
name|IXGBE_KRM_PMD_FLX_MASK_ST20_SPEED_2_5G
value|(0x7<< 28)
end_define

begin_define
define|#
directive|define
name|IXGBE_KRM_PMD_FLX_MASK_ST20_SPEED_MASK
value|(0x7<< 28)
end_define

begin_define
define|#
directive|define
name|IXGBE_KRM_PMD_FLX_MASK_ST20_FW_AN_RESTART
value|(1u<< 31)
end_define

begin_define
define|#
directive|define
name|IXGBE_KRM_PORT_CAR_GEN_CTRL_NELB_32B
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|IXGBE_KRM_PORT_CAR_GEN_CTRL_NELB_KRPCS
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|IXGBE_KRM_LINK_CTRL_1_TETH_FORCE_SPEED_MASK
value|(0x7<< 8)
end_define

begin_define
define|#
directive|define
name|IXGBE_KRM_LINK_CTRL_1_TETH_FORCE_SPEED_1G
value|(2<< 8)
end_define

begin_define
define|#
directive|define
name|IXGBE_KRM_LINK_CTRL_1_TETH_FORCE_SPEED_10G
value|(4<< 8)
end_define

begin_define
define|#
directive|define
name|IXGBE_KRM_LINK_CTRL_1_TETH_AN_SGMII_EN
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|IXGBE_KRM_LINK_CTRL_1_TETH_AN_CLAUSE_37_EN
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|IXGBE_KRM_LINK_CTRL_1_TETH_AN_FEC_REQ
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|IXGBE_KRM_LINK_CTRL_1_TETH_AN_CAP_FEC
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|IXGBE_KRM_LINK_CTRL_1_TETH_AN_CAP_KX
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|IXGBE_KRM_LINK_CTRL_1_TETH_AN_CAP_KR
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|IXGBE_KRM_LINK_CTRL_1_TETH_EEE_CAP_KX
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|IXGBE_KRM_LINK_CTRL_1_TETH_EEE_CAP_KR
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|IXGBE_KRM_LINK_S1_MAC_AN_COMPLETE
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|IXGBE_KRM_LINK_CTRL_1_TETH_AN_ENABLE
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|IXGBE_KRM_LINK_CTRL_1_TETH_AN_RESTART
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|IXGBE_KRM_AN_CNTL_1_SYM_PAUSE
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|IXGBE_KRM_AN_CNTL_1_ASM_PAUSE
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|IXGBE_KRM_PCS_KX_AN_SYM_PAUSE
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|IXGBE_KRM_PCS_KX_AN_ASM_PAUSE
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|IXGBE_KRM_PCS_KX_AN_LP_SYM_PAUSE
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|IXGBE_KRM_PCS_KX_AN_LP_ASM_PAUSE
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|IXGBE_KRM_AN_CNTL_4_ECSR_AN37_OVER_73
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|IXGBE_KRM_AN_CNTL_8_LINEAR
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|IXGBE_KRM_AN_CNTL_8_LIMITING
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|IXGBE_KRM_LP_BASE_PAGE_HIGH_SYM_PAUSE
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|IXGBE_KRM_LP_BASE_PAGE_HIGH_ASM_PAUSE
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|IXGBE_KRM_SGMII_CTRL_MAC_TAR_FORCE_100_D
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|IXGBE_KRM_SGMII_CTRL_MAC_TAR_FORCE_10_D
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|IXGBE_KRM_DSP_TXFFE_STATE_C0_EN
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|IXGBE_KRM_DSP_TXFFE_STATE_CP1_CN1_EN
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|IXGBE_KRM_DSP_TXFFE_STATE_CO_ADAPT_EN
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|IXGBE_KRM_RX_TRN_LINKUP_CTRL_CONV_WO_PROTOCOL
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|IXGBE_KRM_RX_TRN_LINKUP_CTRL_PROTOCOL_BYPASS
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|IXGBE_KRM_PMD_DFX_BURNIN_TX_RX_KR_LB_MASK
value|(0x3<< 16)
end_define

begin_define
define|#
directive|define
name|IXGBE_KRM_TX_COEFF_CTRL_1_CMINUS1_OVRRD_EN
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|IXGBE_KRM_TX_COEFF_CTRL_1_CPLUS1_OVRRD_EN
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|IXGBE_KRM_TX_COEFF_CTRL_1_CZERO_EN
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|IXGBE_KRM_TX_COEFF_CTRL_1_OVRRD_EN
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|IXGBE_SB_IOSF_INDIRECT_CTRL
value|0x00011144
end_define

begin_define
define|#
directive|define
name|IXGBE_SB_IOSF_INDIRECT_DATA
value|0x00011148
end_define

begin_define
define|#
directive|define
name|IXGBE_SB_IOSF_CTRL_ADDR_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|IXGBE_SB_IOSF_CTRL_ADDR_MASK
value|0xFF
end_define

begin_define
define|#
directive|define
name|IXGBE_SB_IOSF_CTRL_RESP_STAT_SHIFT
value|18
end_define

begin_define
define|#
directive|define
name|IXGBE_SB_IOSF_CTRL_RESP_STAT_MASK
define|\
value|(0x3<< IXGBE_SB_IOSF_CTRL_RESP_STAT_SHIFT)
end_define

begin_define
define|#
directive|define
name|IXGBE_SB_IOSF_CTRL_CMPL_ERR_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|IXGBE_SB_IOSF_CTRL_CMPL_ERR_MASK
define|\
value|(0xFF<< IXGBE_SB_IOSF_CTRL_CMPL_ERR_SHIFT)
end_define

begin_define
define|#
directive|define
name|IXGBE_SB_IOSF_CTRL_TARGET_SELECT_SHIFT
value|28
end_define

begin_define
define|#
directive|define
name|IXGBE_SB_IOSF_CTRL_TARGET_SELECT_MASK
value|0x7
end_define

begin_define
define|#
directive|define
name|IXGBE_SB_IOSF_CTRL_BUSY_SHIFT
value|31
end_define

begin_define
define|#
directive|define
name|IXGBE_SB_IOSF_CTRL_BUSY
value|(1<< IXGBE_SB_IOSF_CTRL_BUSY_SHIFT)
end_define

begin_define
define|#
directive|define
name|IXGBE_SB_IOSF_TARGET_KR_PHY
value|0
end_define

begin_define
define|#
directive|define
name|IXGBE_NW_MNG_IF_SEL
value|0x00011178
end_define

begin_define
define|#
directive|define
name|IXGBE_NW_MNG_IF_SEL_MDIO_ACT
value|(1u<< 1)
end_define

begin_define
define|#
directive|define
name|IXGBE_NW_MNG_IF_SEL_MDIO_IF_MODE
value|(1u<< 2)
end_define

begin_define
define|#
directive|define
name|IXGBE_NW_MNG_IF_SEL_EN_SHARED_MDIO
value|(1u<< 13)
end_define

begin_define
define|#
directive|define
name|IXGBE_NW_MNG_IF_SEL_PHY_SPEED_10M
value|(1u<< 17)
end_define

begin_define
define|#
directive|define
name|IXGBE_NW_MNG_IF_SEL_PHY_SPEED_100M
value|(1u<< 18)
end_define

begin_define
define|#
directive|define
name|IXGBE_NW_MNG_IF_SEL_PHY_SPEED_1G
value|(1u<< 19)
end_define

begin_define
define|#
directive|define
name|IXGBE_NW_MNG_IF_SEL_PHY_SPEED_2_5G
value|(1u<< 20)
end_define

begin_define
define|#
directive|define
name|IXGBE_NW_MNG_IF_SEL_PHY_SPEED_10G
value|(1u<< 21)
end_define

begin_define
define|#
directive|define
name|IXGBE_NW_MNG_IF_SEL_SGMII_ENABLE
value|(1u<< 25)
end_define

begin_define
define|#
directive|define
name|IXGBE_NW_MNG_IF_SEL_INT_PHY_MODE
value|(1<< 24)
end_define

begin_comment
comment|/* X552 reg field only */
end_comment

begin_define
define|#
directive|define
name|IXGBE_NW_MNG_IF_SEL_MDIO_PHY_ADD_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|IXGBE_NW_MNG_IF_SEL_MDIO_PHY_ADD
define|\
value|(0x1F<< IXGBE_NW_MNG_IF_SEL_MDIO_PHY_ADD_SHIFT)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IXGBE_TYPE_H_ */
end_comment

end_unit

