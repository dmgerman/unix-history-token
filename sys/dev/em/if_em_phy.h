begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/************************************************************************* ************************************************************************** Copyright (c) 2001 Intel Corporation  All rights reserved.   Redistribution and use in source and binary forms of the Software, with or  without modification, are permitted provided that the following conditions  are met:    1. Redistributions of source code of the Software may retain the above      copyright notice, this list of conditions and the following disclaimer.    2. Redistributions in binary form of the Software may reproduce the above      copyright notice, this list of conditions and the following disclaimer      in the documentation and/or other materials provided with the      distribution.    3. Neither the name of the Intel Corporation nor the names of its      contributors shall be used to endorse or promote products derived from      this Software without specific prior written permission.  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  ARE DISCLAIMED. IN NO EVENT SHALL THE INTEL OR ITS CONTRIBUTORS BE LIABLE  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  SUCH DAMAGE. *************************************************************************** **************************************************************************/
end_comment

begin_comment
comment|/*$FreeBSD$*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_EM_PHY_H_
end_ifndef

begin_define
define|#
directive|define
name|_EM_PHY_H_
end_define

begin_comment
comment|/* * Workfile: phy.h  * Date: 9/25/01 2:40p  * Revision: 9  */
end_comment

begin_define
define|#
directive|define
name|_PHY_
end_define

begin_include
include|#
directive|include
file|<dev/em/if_em_osdep.h>
end_include

begin_typedef
typedef|typedef
enum|enum
block|{
name|PXN_PSSR_CABLE_LENGTH_50
init|=
literal|0
block|,
name|PXN_PSSR_CABLE_LENGTH_50_80
block|,
name|PXN_PSSR_CABLE_LENGTH_80_110
block|,
name|PXN_PSSR_CABLE_LENGTH_110_140
block|,
name|PXN_PSSR_CABLE_LENGTH_140
block|,
name|PXN_PSSR_CABLE_LENGTH_UNDEFINED
init|=
literal|0xFF
block|}
name|PXN_PSSR_CABLE_LENGTH_ENUM
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|PXN_PSCR_10BT_EXT_DIST_ENABLE_NORMAL
init|=
literal|0
block|,
name|PXN_PSCR_10BT_EXT_DIST_ENABLE_LOWER
block|,
name|PXN_PSCR_10BT_EXT_DIST_ENABLE_UNDEFINED
init|=
literal|0xFF
block|}
name|PXN_PSCR_10BT_EXT_DIST_ENABLE_ENUM
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|PXN_PSSR_REV_POLARITY_NORMAL
init|=
literal|0
block|,
name|PXN_PSSR_REV_POLARITY_REVERSED
block|,
name|PXN_PSSR_REV_POLARITY_UNDEFINED
init|=
literal|0xFF
block|}
name|PXN_PSSR_REV_POLARITY_ENUM
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|PXN_PSCR_POLARITY_REVERSAL_ENABLED
init|=
literal|0
block|,
name|PXN_PSCR_POLARITY_REVERSAL_DISABLED
block|,
name|PXN_PSCR_POLARITY_REVERSAL_UNDEFINED
init|=
literal|0xFF
block|}
name|PXN_PSCR_POLARITY_REVERSAL_ENUM
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|PXN_EPSCR_DOWN_NO_IDLE_NO_DETECT
init|=
literal|0
block|,
name|PXN_EPSCR_DOWN_NO_IDLE_DETECT
block|,
name|PXN_EPSCR_DOWN_NO_IDLE_UNDEFINED
init|=
literal|0xFF
block|}
name|PXN_EPSCR_DOWN_NO_IDLE_ENUM
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|PXN_PSCR_AUTO_X_MODE_MANUAL_MDI
init|=
literal|0
block|,
name|PXN_PSCR_AUTO_X_MODE_MANUAL_MDIX
block|,
name|PXN_PSCR_AUTO_X_MODE_AUTO_1
block|,
name|PXN_PSCR_AUTO_X_MODE_AUTO_2
block|,
name|PXN_PSCR_AUTO_X_MODE_UNDEFINED
init|=
literal|0xFF
block|}
name|PXN_PSCR_AUTO_X_MODE_ENUM
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|SR_1000T_RX_STATUS_NOT_OK
init|=
literal|0
block|,
name|SR_1000T_RX_STATUS_OK
block|,
name|SR_1000T_RX_STATUS_UNDEFINED
init|=
literal|0xFF
block|}
name|SR_1000T_RX_STATUS_ENUM
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|PXN_PSSR_CABLE_LENGTH_ENUM
name|CableLength
decl_stmt|;
name|PXN_PSCR_10BT_EXT_DIST_ENABLE_ENUM
name|Extended10BTDistance
decl_stmt|;
name|PXN_PSSR_REV_POLARITY_ENUM
name|CablePolarity
decl_stmt|;
name|PXN_PSCR_POLARITY_REVERSAL_ENUM
name|PolarityCorrection
decl_stmt|;
name|PXN_EPSCR_DOWN_NO_IDLE_ENUM
name|LinkReset
decl_stmt|;
name|PXN_PSCR_AUTO_X_MODE_ENUM
name|MDIXMode
decl_stmt|;
name|SR_1000T_RX_STATUS_ENUM
name|LocalRx
decl_stmt|;
name|SR_1000T_RX_STATUS_ENUM
name|RemoteRx
decl_stmt|;
block|}
name|phy_status_info_struct
typedef|;
end_typedef

begin_function_decl
name|u16
name|em_read_phy_register
parameter_list|(
name|struct
name|adapter
modifier|*
name|Adapter
parameter_list|,
name|u32
name|RegAddress
parameter_list|,
name|u32
name|PhyAddress
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|em_write_phy_register
parameter_list|(
name|struct
name|adapter
modifier|*
name|Adapter
parameter_list|,
name|u32
name|RegAddress
parameter_list|,
name|u32
name|PhyAddress
parameter_list|,
name|u16
name|Data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|em_phy_hardware_reset
parameter_list|(
name|struct
name|adapter
modifier|*
name|Adapter
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u8
name|em_phy_reset
parameter_list|(
name|struct
name|adapter
modifier|*
name|Adapter
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u8
name|em_phy_setup
parameter_list|(
name|struct
name|adapter
modifier|*
name|Adapter
parameter_list|,
name|u32
name|DeviceControlReg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|em_configure_mac_to_phy_settings
parameter_list|(
name|struct
name|adapter
modifier|*
name|Adapter
parameter_list|,
name|u16
name|MiiRegisterData
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|em_configure_collision_distance
parameter_list|(
name|struct
name|adapter
modifier|*
name|Adapter
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|em_display_mii_contents
parameter_list|(
name|struct
name|adapter
modifier|*
name|Adapter
parameter_list|,
name|u8
name|PhyAddress
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u32
name|em_auto_detect_gigabit_phy
parameter_list|(
name|struct
name|adapter
modifier|*
name|Adapter
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|em_pxn_phy_reset_dsp
parameter_list|(
name|struct
name|adapter
modifier|*
name|Adapter
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|PxnIntegratedPhyLoopback
parameter_list|(
name|struct
name|adapter
modifier|*
name|Adapter
parameter_list|,
name|u16
name|Speed
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|PxnPhyEnableReceiver
parameter_list|(
name|struct
name|adapter
modifier|*
name|Adapter
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|PxnPhyDisableReceiver
parameter_list|(
name|struct
name|adapter
modifier|*
name|Adapter
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u8
name|em_wait_for_auto_neg
parameter_list|(
name|struct
name|adapter
modifier|*
name|Adapter
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u8
name|em_phy_get_status_info
parameter_list|(
name|struct
name|adapter
modifier|*
name|Adapter
parameter_list|,
name|phy_status_info_struct
modifier|*
name|PhyStatusInfo
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|E1000_CTRL_PHY_RESET_DIR
value|E1000_CTRL_SWDPIO0
end_define

begin_define
define|#
directive|define
name|E1000_CTRL_PHY_RESET
value|E1000_CTRL_SWDPIN0
end_define

begin_define
define|#
directive|define
name|E1000_CTRL_MDIO_DIR
value|E1000_CTRL_SWDPIO2
end_define

begin_define
define|#
directive|define
name|E1000_CTRL_MDIO
value|E1000_CTRL_SWDPIN2
end_define

begin_define
define|#
directive|define
name|E1000_CTRL_MDC_DIR
value|E1000_CTRL_SWDPIO3
end_define

begin_define
define|#
directive|define
name|E1000_CTRL_MDC
value|E1000_CTRL_SWDPIN3
end_define

begin_define
define|#
directive|define
name|E1000_CTRL_PHY_RESET_DIR4
value|E1000_EXCTRL_SWDPIO4
end_define

begin_define
define|#
directive|define
name|E1000_CTRL_PHY_RESET4
value|E1000_EXCTRL_SWDPIN4
end_define

begin_define
define|#
directive|define
name|PHY_MII_CTRL_REG
value|0x00
end_define

begin_define
define|#
directive|define
name|PHY_MII_STATUS_REG
value|0x01
end_define

begin_define
define|#
directive|define
name|PHY_PHY_ID_REG1
value|0x02
end_define

begin_define
define|#
directive|define
name|PHY_PHY_ID_REG2
value|0x03
end_define

begin_define
define|#
directive|define
name|PHY_AUTONEG_ADVERTISEMENT
value|0x04
end_define

begin_define
define|#
directive|define
name|PHY_AUTONEG_LP_BPA
value|0x05
end_define

begin_define
define|#
directive|define
name|PHY_AUTONEG_EXPANSION_REG
value|0x06
end_define

begin_define
define|#
directive|define
name|PHY_AUTONEG_NEXT_PAGE_TX
value|0x07
end_define

begin_define
define|#
directive|define
name|PHY_AUTONEG_LP_RX_NEXT_PAGE
value|0x08
end_define

begin_define
define|#
directive|define
name|PHY_1000T_CTRL_REG
value|0x09
end_define

begin_define
define|#
directive|define
name|PHY_1000T_STATUS_REG
value|0x0A
end_define

begin_define
define|#
directive|define
name|PHY_IEEE_EXT_STATUS_REG
value|0x0F
end_define

begin_define
define|#
directive|define
name|PXN_PHY_SPEC_CTRL_REG
value|0x10
end_define

begin_define
define|#
directive|define
name|PXN_PHY_SPEC_STAT_REG
value|0x11
end_define

begin_define
define|#
directive|define
name|PXN_INT_ENABLE_REG
value|0x12
end_define

begin_define
define|#
directive|define
name|PXN_INT_STATUS_REG
value|0x13
end_define

begin_define
define|#
directive|define
name|PXN_EXT_PHY_SPEC_CTRL_REG
value|0x14
end_define

begin_define
define|#
directive|define
name|PXN_RX_ERROR_COUNTER
value|0x15
end_define

begin_define
define|#
directive|define
name|PXN_LED_CTRL_REG
value|0x18
end_define

begin_define
define|#
directive|define
name|MAX_PHY_REG_ADDRESS
value|0x1F
end_define

begin_define
define|#
directive|define
name|MII_CR_SPEED_SELECT_MSB
value|0x0040
end_define

begin_define
define|#
directive|define
name|MII_CR_COLL_TEST_ENABLE
value|0x0080
end_define

begin_define
define|#
directive|define
name|MII_CR_FULL_DUPLEX
value|0x0100
end_define

begin_define
define|#
directive|define
name|MII_CR_RESTART_AUTO_NEG
value|0x0200
end_define

begin_define
define|#
directive|define
name|MII_CR_ISOLATE
value|0x0400
end_define

begin_define
define|#
directive|define
name|MII_CR_POWER_DOWN
value|0x0800
end_define

begin_define
define|#
directive|define
name|MII_CR_AUTO_NEG_EN
value|0x1000
end_define

begin_define
define|#
directive|define
name|MII_CR_SPEED_SELECT_LSB
value|0x2000
end_define

begin_define
define|#
directive|define
name|MII_CR_LOOPBACK
value|0x4000
end_define

begin_define
define|#
directive|define
name|MII_CR_RESET
value|0x8000
end_define

begin_define
define|#
directive|define
name|MII_SR_EXTENDED_CAPS
value|0x0001
end_define

begin_define
define|#
directive|define
name|MII_SR_JABBER_DETECT
value|0x0002
end_define

begin_define
define|#
directive|define
name|MII_SR_LINK_STATUS
value|0x0004
end_define

begin_define
define|#
directive|define
name|MII_SR_AUTONEG_CAPS
value|0x0008
end_define

begin_define
define|#
directive|define
name|MII_SR_REMOTE_FAULT
value|0x0010
end_define

begin_define
define|#
directive|define
name|MII_SR_AUTONEG_COMPLETE
value|0x0020
end_define

begin_define
define|#
directive|define
name|MII_SR_PREAMBLE_SUPPRESS
value|0x0040
end_define

begin_define
define|#
directive|define
name|MII_SR_EXTENDED_STATUS
value|0x0100
end_define

begin_define
define|#
directive|define
name|MII_SR_100T2_HD_CAPS
value|0x0200
end_define

begin_define
define|#
directive|define
name|MII_SR_100T2_FD_CAPS
value|0x0400
end_define

begin_define
define|#
directive|define
name|MII_SR_10T_HD_CAPS
value|0x0800
end_define

begin_define
define|#
directive|define
name|MII_SR_10T_FD_CAPS
value|0x1000
end_define

begin_define
define|#
directive|define
name|MII_SR_100X_HD_CAPS
value|0x2000
end_define

begin_define
define|#
directive|define
name|MII_SR_100X_FD_CAPS
value|0x4000
end_define

begin_define
define|#
directive|define
name|MII_SR_100T4_CAPS
value|0x8000
end_define

begin_define
define|#
directive|define
name|NWAY_AR_SELECTOR_FIELD
value|0x0001
end_define

begin_define
define|#
directive|define
name|NWAY_AR_10T_HD_CAPS
value|0x0020
end_define

begin_define
define|#
directive|define
name|NWAY_AR_10T_FD_CAPS
value|0x0040
end_define

begin_define
define|#
directive|define
name|NWAY_AR_100TX_HD_CAPS
value|0x0080
end_define

begin_define
define|#
directive|define
name|NWAY_AR_100TX_FD_CAPS
value|0x0100
end_define

begin_define
define|#
directive|define
name|NWAY_AR_100T4_CAPS
value|0x0200
end_define

begin_define
define|#
directive|define
name|NWAY_AR_PAUSE
value|0x0400
end_define

begin_define
define|#
directive|define
name|NWAY_AR_ASM_DIR
value|0x0800
end_define

begin_define
define|#
directive|define
name|NWAY_AR_REMOTE_FAULT
value|0x2000
end_define

begin_define
define|#
directive|define
name|NWAY_AR_NEXT_PAGE
value|0x8000
end_define

begin_define
define|#
directive|define
name|NWAY_LPAR_SELECTOR_FIELD
value|0x0000
end_define

begin_define
define|#
directive|define
name|NWAY_LPAR_10T_HD_CAPS
value|0x0020
end_define

begin_define
define|#
directive|define
name|NWAY_LPAR_10T_FD_CAPS
value|0x0040
end_define

begin_define
define|#
directive|define
name|NWAY_LPAR_100TX_HD_CAPS
value|0x0080
end_define

begin_define
define|#
directive|define
name|NWAY_LPAR_100TX_FD_CAPS
value|0x0100
end_define

begin_define
define|#
directive|define
name|NWAY_LPAR_100T4_CAPS
value|0x0200
end_define

begin_define
define|#
directive|define
name|NWAY_LPAR_PAUSE
value|0x0400
end_define

begin_define
define|#
directive|define
name|NWAY_LPAR_ASM_DIR
value|0x0800
end_define

begin_define
define|#
directive|define
name|NWAY_LPAR_REMOTE_FAULT
value|0x2000
end_define

begin_define
define|#
directive|define
name|NWAY_LPAR_ACKNOWLEDGE
value|0x4000
end_define

begin_define
define|#
directive|define
name|NWAY_LPAR_NEXT_PAGE
value|0x8000
end_define

begin_define
define|#
directive|define
name|NWAY_ER_LP_NWAY_CAPS
value|0x0001
end_define

begin_define
define|#
directive|define
name|NWAY_ER_PAGE_RXD
value|0x0002
end_define

begin_define
define|#
directive|define
name|NWAY_ER_NEXT_PAGE_CAPS
value|0x0004
end_define

begin_define
define|#
directive|define
name|NWAY_ER_LP_NEXT_PAGE_CAPS
value|0x0008
end_define

begin_define
define|#
directive|define
name|NWAY_ER_PAR_DETECT_FAULT
value|0x0100
end_define

begin_define
define|#
directive|define
name|NPTX_MSG_CODE_FIELD
value|0x0001
end_define

begin_define
define|#
directive|define
name|NPTX_TOGGLE
value|0x0800
end_define

begin_define
define|#
directive|define
name|NPTX_ACKNOWLDGE2
value|0x1000
end_define

begin_define
define|#
directive|define
name|NPTX_MSG_PAGE
value|0x2000
end_define

begin_define
define|#
directive|define
name|NPTX_NEXT_PAGE
value|0x8000
end_define

begin_define
define|#
directive|define
name|LP_RNPR_MSG_CODE_FIELD
value|0x0001
end_define

begin_define
define|#
directive|define
name|LP_RNPR_TOGGLE
value|0x0800
end_define

begin_define
define|#
directive|define
name|LP_RNPR_ACKNOWLDGE2
value|0x1000
end_define

begin_define
define|#
directive|define
name|LP_RNPR_MSG_PAGE
value|0x2000
end_define

begin_define
define|#
directive|define
name|LP_RNPR_ACKNOWLDGE
value|0x4000
end_define

begin_define
define|#
directive|define
name|LP_RNPR_NEXT_PAGE
value|0x8000
end_define

begin_define
define|#
directive|define
name|CR_1000T_ASYM_PAUSE
value|0x0080
end_define

begin_define
define|#
directive|define
name|CR_1000T_HD_CAPS
value|0x0100
end_define

begin_define
define|#
directive|define
name|CR_1000T_FD_CAPS
value|0x0200
end_define

begin_define
define|#
directive|define
name|CR_1000T_REPEATER_DTE
value|0x0400
end_define

begin_define
define|#
directive|define
name|CR_1000T_MS_VALUE
value|0x0800
end_define

begin_define
define|#
directive|define
name|CR_1000T_MS_ENABLE
value|0x1000
end_define

begin_define
define|#
directive|define
name|CR_1000T_TEST_MODE_NORMAL
value|0x0000
end_define

begin_define
define|#
directive|define
name|CR_1000T_TEST_MODE_1
value|0x2000
end_define

begin_define
define|#
directive|define
name|CR_1000T_TEST_MODE_2
value|0x4000
end_define

begin_define
define|#
directive|define
name|CR_1000T_TEST_MODE_3
value|0x6000
end_define

begin_define
define|#
directive|define
name|CR_1000T_TEST_MODE_4
value|0x8000
end_define

begin_define
define|#
directive|define
name|SR_1000T_IDLE_ERROR_CNT
value|0x00FF
end_define

begin_define
define|#
directive|define
name|SR_1000T_ASYM_PAUSE_DIR
value|0x0100
end_define

begin_define
define|#
directive|define
name|SR_1000T_LP_HD_CAPS
value|0x0400
end_define

begin_define
define|#
directive|define
name|SR_1000T_LP_FD_CAPS
value|0x0800
end_define

begin_define
define|#
directive|define
name|SR_1000T_REMOTE_RX_STATUS
value|0x1000
end_define

begin_define
define|#
directive|define
name|SR_1000T_LOCAL_RX_STATUS
value|0x2000
end_define

begin_define
define|#
directive|define
name|SR_1000T_MS_CONFIG_RES
value|0x4000
end_define

begin_define
define|#
directive|define
name|SR_1000T_MS_CONFIG_FAULT
value|0x8000
end_define

begin_define
define|#
directive|define
name|SR_1000T_REMOTE_RX_STATUS_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|SR_1000T_LOCAL_RX_STATUS_SHIFT
value|13
end_define

begin_define
define|#
directive|define
name|IEEE_ESR_1000T_HD_CAPS
value|0x1000
end_define

begin_define
define|#
directive|define
name|IEEE_ESR_1000T_FD_CAPS
value|0x2000
end_define

begin_define
define|#
directive|define
name|IEEE_ESR_1000X_HD_CAPS
value|0x4000
end_define

begin_define
define|#
directive|define
name|IEEE_ESR_1000X_FD_CAPS
value|0x8000
end_define

begin_define
define|#
directive|define
name|PHY_TX_POLARITY_MASK
value|0x0100
end_define

begin_define
define|#
directive|define
name|PHY_TX_NORMAL_POLARITY
value|0
end_define

begin_define
define|#
directive|define
name|AUTO_POLARITY_DISABLE
value|0x0010
end_define

begin_define
define|#
directive|define
name|PXN_PSCR_JABBER_DISABLE
value|0x0001
end_define

begin_define
define|#
directive|define
name|PXN_PSCR_POLARITY_REVERSAL
value|0x0002
end_define

begin_define
define|#
directive|define
name|PXN_PSCR_SQE_TEST
value|0x0004
end_define

begin_define
define|#
directive|define
name|PXN_PSCR_INT_FIFO_DISABLE
value|0x0008
end_define

begin_define
define|#
directive|define
name|PXN_PSCR_CLK125_DISABLE
value|0x0010
end_define

begin_define
define|#
directive|define
name|PXN_PSCR_MDI_MANUAL_MODE
value|0x0000
end_define

begin_define
define|#
directive|define
name|PXN_PSCR_MDIX_MANUAL_MODE
value|0x0020
end_define

begin_define
define|#
directive|define
name|PXN_PSCR_AUTO_X_1000T
value|0x0040
end_define

begin_define
define|#
directive|define
name|PXN_PSCR_AUTO_X_MODE
value|0x0060
end_define

begin_define
define|#
directive|define
name|PXN_PSCR_10BT_EXT_DIST_ENABLE
value|0x0080
end_define

begin_define
define|#
directive|define
name|PXN_PSCR_MII_5BIT_ENABLE
value|0x0100
end_define

begin_define
define|#
directive|define
name|PXN_PSCR_SCRAMBLER_DISABLE
value|0x0200
end_define

begin_define
define|#
directive|define
name|PXN_PSCR_FORCE_LINK_GOOD
value|0x0400
end_define

begin_define
define|#
directive|define
name|PXN_PSCR_ASSERT_CRS_ON_TX
value|0x0800
end_define

begin_define
define|#
directive|define
name|PXN_PSCR_RX_FIFO_DEPTH_6
value|0x0000
end_define

begin_define
define|#
directive|define
name|PXN_PSCR_RX_FIFO_DEPTH_8
value|0x1000
end_define

begin_define
define|#
directive|define
name|PXN_PSCR_RX_FIFO_DEPTH_10
value|0x2000
end_define

begin_define
define|#
directive|define
name|PXN_PSCR_RX_FIFO_DEPTH_12
value|0x3000
end_define

begin_define
define|#
directive|define
name|PXN_PSCR_TXFR_FIFO_DEPTH_6
value|0x0000
end_define

begin_define
define|#
directive|define
name|PXN_PSCR_TXFR_FIFO_DEPTH_8
value|0x4000
end_define

begin_define
define|#
directive|define
name|PXN_PSCR_TXFR_FIFO_DEPTH_10
value|0x8000
end_define

begin_define
define|#
directive|define
name|PXN_PSCR_TXFR_FIFO_DEPTH_12
value|0xC000
end_define

begin_define
define|#
directive|define
name|PXN_PSCR_POLARITY_REVERSAL_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|PXN_PSCR_AUTO_X_MODE_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|PXN_PSCR_10BT_EXT_DIST_ENABLE_SHIFT
value|7
end_define

begin_define
define|#
directive|define
name|PXN_PSSR_JABBER
value|0x0001
end_define

begin_define
define|#
directive|define
name|PXN_PSSR_REV_POLARITY
value|0x0002
end_define

begin_define
define|#
directive|define
name|PXN_PSSR_MDIX
value|0x0040
end_define

begin_define
define|#
directive|define
name|PXN_PSSR_CABLE_LENGTH
value|0x0380
end_define

begin_define
define|#
directive|define
name|PXN_PSSR_LINK
value|0x0400
end_define

begin_define
define|#
directive|define
name|PXN_PSSR_SPD_DPLX_RESOLVED
value|0x0800
end_define

begin_define
define|#
directive|define
name|PXN_PSSR_PAGE_RCVD
value|0x1000
end_define

begin_define
define|#
directive|define
name|PXN_PSSR_DPLX
value|0x2000
end_define

begin_define
define|#
directive|define
name|PXN_PSSR_SPEED
value|0xC000
end_define

begin_define
define|#
directive|define
name|PXN_PSSR_10MBS
value|0x0000
end_define

begin_define
define|#
directive|define
name|PXN_PSSR_100MBS
value|0x4000
end_define

begin_define
define|#
directive|define
name|PXN_PSSR_1000MBS
value|0x8000
end_define

begin_define
define|#
directive|define
name|PXN_PSSR_REV_POLARITY_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|PXN_PSSR_CABLE_LENGTH_SHIFT
value|7
end_define

begin_define
define|#
directive|define
name|PXN_IER_JABBER
value|0x0001
end_define

begin_define
define|#
directive|define
name|PXN_IER_POLARITY_CHANGE
value|0x0002
end_define

begin_define
define|#
directive|define
name|PXN_IER_MDIX_CHANGE
value|0x0040
end_define

begin_define
define|#
directive|define
name|PXN_IER_FIFO_OVER_UNDERUN
value|0x0080
end_define

begin_define
define|#
directive|define
name|PXN_IER_FALSE_CARRIER
value|0x0100
end_define

begin_define
define|#
directive|define
name|PXN_IER_SYMBOL_ERROR
value|0x0200
end_define

begin_define
define|#
directive|define
name|PXN_IER_LINK_STAT_CHANGE
value|0x0400
end_define

begin_define
define|#
directive|define
name|PXN_IER_AUTO_NEG_COMPLETE
value|0x0800
end_define

begin_define
define|#
directive|define
name|PXN_IER_PAGE_RECEIVED
value|0x1000
end_define

begin_define
define|#
directive|define
name|PXN_IER_DUPLEX_CHANGED
value|0x2000
end_define

begin_define
define|#
directive|define
name|PXN_IER_SPEED_CHANGED
value|0x4000
end_define

begin_define
define|#
directive|define
name|PXN_IER_AUTO_NEG_ERR
value|0x8000
end_define

begin_define
define|#
directive|define
name|PXN_ISR_JABBER
value|0x0001
end_define

begin_define
define|#
directive|define
name|PXN_ISR_POLARITY_CHANGE
value|0x0002
end_define

begin_define
define|#
directive|define
name|PXN_ISR_MDIX_CHANGE
value|0x0040
end_define

begin_define
define|#
directive|define
name|PXN_ISR_FIFO_OVER_UNDERUN
value|0x0080
end_define

begin_define
define|#
directive|define
name|PXN_ISR_FALSE_CARRIER
value|0x0100
end_define

begin_define
define|#
directive|define
name|PXN_ISR_SYMBOL_ERROR
value|0x0200
end_define

begin_define
define|#
directive|define
name|PXN_ISR_LINK_STAT_CHANGE
value|0x0400
end_define

begin_define
define|#
directive|define
name|PXN_ISR_AUTO_NEG_COMPLETE
value|0x0800
end_define

begin_define
define|#
directive|define
name|PXN_ISR_PAGE_RECEIVED
value|0x1000
end_define

begin_define
define|#
directive|define
name|PXN_ISR_DUPLEX_CHANGED
value|0x2000
end_define

begin_define
define|#
directive|define
name|PXN_ISR_SPEED_CHANGED
value|0x4000
end_define

begin_define
define|#
directive|define
name|PXN_ISR_AUTO_NEG_ERR
value|0x8000
end_define

begin_define
define|#
directive|define
name|PXN_EPSCR_FIBER_LOOPBACK
value|0x4000
end_define

begin_define
define|#
directive|define
name|PXN_EPSCR_DOWN_NO_IDLE
value|0x8000
end_define

begin_define
define|#
directive|define
name|PXN_EPSCR_TX_CLK_2_5
value|0x0060
end_define

begin_define
define|#
directive|define
name|PXN_EPSCR_TX_CLK_25
value|0x0070
end_define

begin_define
define|#
directive|define
name|PXN_EPSCR_TX_CLK_0
value|0x0000
end_define

begin_define
define|#
directive|define
name|PXN_EPSCR_DOWN_NO_IDLE_SHIFT
value|15
end_define

begin_define
define|#
directive|define
name|PXN_LCR_LED_TX
value|0x0001
end_define

begin_define
define|#
directive|define
name|PXN_LCR_LED_RX
value|0x0002
end_define

begin_define
define|#
directive|define
name|PXN_LCR_LED_DUPLEX
value|0x0004
end_define

begin_define
define|#
directive|define
name|PXN_LCR_LINK
value|0x0008
end_define

begin_define
define|#
directive|define
name|PXN_LCR_BLINK_RATE_42MS
value|0x0000
end_define

begin_define
define|#
directive|define
name|PXN_LCR_BLINK_RATE_84MS
value|0x0100
end_define

begin_define
define|#
directive|define
name|PXN_LCR_BLINK_RATE_170MS
value|0x0200
end_define

begin_define
define|#
directive|define
name|PXN_LCR_BLINK_RATE_340MS
value|0x0300
end_define

begin_define
define|#
directive|define
name|PXN_LCR_BLINK_RATE_670MS
value|0x0400
end_define

begin_define
define|#
directive|define
name|PXN_LCR_PULSE_STRETCH_OFF
value|0x0000
end_define

begin_define
define|#
directive|define
name|PXN_LCR_PULSE_STRETCH_21_42MS
value|0x1000
end_define

begin_define
define|#
directive|define
name|PXN_LCR_PULSE_STRETCH_42_84MS
value|0x2000
end_define

begin_define
define|#
directive|define
name|PXN_LCR_PULSE_STRETCH_84_170MS
value|0x3000
end_define

begin_define
define|#
directive|define
name|PXN_LCR_PULSE_STRETCH_170_340MS
value|0x4000
end_define

begin_define
define|#
directive|define
name|PXN_LCR_PULSE_STRETCH_340_670MS
value|0x5000
end_define

begin_define
define|#
directive|define
name|PXN_LCR_PULSE_STRETCH_670_13S
value|0x6000
end_define

begin_define
define|#
directive|define
name|PXN_LCR_PULSE_STRETCH_13_26S
value|0x7000
end_define

begin_define
define|#
directive|define
name|PHY_PREAMBLE
value|0xFFFFFFFF
end_define

begin_define
define|#
directive|define
name|PHY_SOF
value|0x01
end_define

begin_define
define|#
directive|define
name|PHY_OP_READ
value|0x02
end_define

begin_define
define|#
directive|define
name|PHY_OP_WRITE
value|0x01
end_define

begin_define
define|#
directive|define
name|PHY_TURNAROUND
value|0x02
end_define

begin_define
define|#
directive|define
name|PHY_PREAMBLE_SIZE
value|32
end_define

begin_define
define|#
directive|define
name|MII_CR_SPEED_1000
value|0x0040
end_define

begin_define
define|#
directive|define
name|MII_CR_SPEED_100
value|0x2000
end_define

begin_define
define|#
directive|define
name|MII_CR_SPEED_10
value|0x0000
end_define

begin_define
define|#
directive|define
name|E1000_PHY_ADDRESS
value|0x01
end_define

begin_define
define|#
directive|define
name|E1000_10MB_PHY_ADDRESS
value|0x02
end_define

begin_define
define|#
directive|define
name|PHY_AUTO_NEG_TIME
value|45
end_define

begin_define
define|#
directive|define
name|PAXSON_PHY_88E1000
value|0x01410C50
end_define

begin_define
define|#
directive|define
name|PAXSON_PHY_88E1000S
value|0x01410C40
end_define

begin_define
define|#
directive|define
name|PAXSON_PHY_INTEGRATED
value|0x01410C30
end_define

begin_define
define|#
directive|define
name|PHY_REVISION_MASK
value|0xFFFFFFF0
end_define

begin_define
define|#
directive|define
name|AUTONEG_ADVERTISE_SPEED_DEFAULT
value|0x002F
end_define

begin_define
define|#
directive|define
name|DEVICE_SPEED_MASK
value|0x00000300
end_define

begin_define
define|#
directive|define
name|REG4_SPEED_MASK
value|0x01E0
end_define

begin_define
define|#
directive|define
name|REG9_SPEED_MASK
value|0x0300
end_define

begin_define
define|#
directive|define
name|ADVERTISE_10_HALF
value|0x0001
end_define

begin_define
define|#
directive|define
name|ADVERTISE_10_FULL
value|0x0002
end_define

begin_define
define|#
directive|define
name|ADVERTISE_100_HALF
value|0x0004
end_define

begin_define
define|#
directive|define
name|ADVERTISE_100_FULL
value|0x0008
end_define

begin_define
define|#
directive|define
name|ADVERTISE_1000_HALF
value|0x0010
end_define

begin_define
define|#
directive|define
name|ADVERTISE_1000_FULL
value|0x0020
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _EM_PHY_H_ */
end_comment

end_unit

