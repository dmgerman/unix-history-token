begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*******************************************************************************    Copyright (c) 2001-2002 Intel Corporation    All rights reserved.       Redistribution and use in source and binary forms of the Software, with or    without modification, are permitted provided that the following conditions    are met:        1. Redistributions of source code of the Software may retain the above        copyright notice, this list of conditions and the following disclaimer.        2. Redistributions in binary form of the Software may reproduce the above        copyright notice, this list of conditions and the following disclaimer        in the documentation and/or other materials provided with the        distribution.        3. Neither the name of the Intel Corporation nor the names of its        contributors shall be used to endorse or promote products derived from        this Software without specific prior written permission.      THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE    ARE DISCLAIMED. IN NO EVENT SHALL THE INTEL OR ITS CONTRIBUTORS BE LIABLE    FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL    DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR    SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER    CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT    LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY    OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF    SUCH DAMAGE.  *******************************************************************************/
end_comment

begin_comment
comment|/*$FreeBSD$*/
end_comment

begin_comment
comment|/* if_em_phy.h  * Structures, enums, and macros for the PHY  */
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

begin_include
include|#
directive|include
file|<dev/em/if_em_osdep.h>
end_include

begin_comment
comment|/* PHY status info structure and supporting enums */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|em_cable_length_50
init|=
literal|0
block|,
name|em_cable_length_50_80
block|,
name|em_cable_length_80_110
block|,
name|em_cable_length_110_140
block|,
name|em_cable_length_140
block|,
name|em_cable_length_undefined
init|=
literal|0xFF
block|}
name|em_cable_length
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|em_10bt_ext_dist_enable_normal
init|=
literal|0
block|,
name|em_10bt_ext_dist_enable_lower
block|,
name|em_10bt_ext_dist_enable_undefined
init|=
literal|0xFF
block|}
name|em_10bt_ext_dist_enable
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|em_rev_polarity_normal
init|=
literal|0
block|,
name|em_rev_polarity_reversed
block|,
name|em_rev_polarity_undefined
init|=
literal|0xFF
block|}
name|em_rev_polarity
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|em_polarity_reversal_enabled
init|=
literal|0
block|,
name|em_polarity_reversal_disabled
block|,
name|em_polarity_reversal_undefined
init|=
literal|0xFF
block|}
name|em_polarity_reversal
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|em_down_no_idle_no_detect
init|=
literal|0
block|,
name|em_down_no_idle_detect
block|,
name|em_down_no_idle_undefined
init|=
literal|0xFF
block|}
name|em_down_no_idle
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|em_auto_x_mode_manual_mdi
init|=
literal|0
block|,
name|em_auto_x_mode_manual_mdix
block|,
name|em_auto_x_mode_auto1
block|,
name|em_auto_x_mode_auto2
block|,
name|em_auto_x_mode_undefined
init|=
literal|0xFF
block|}
name|em_auto_x_mode
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|em_1000t_rx_status_not_ok
init|=
literal|0
block|,
name|em_1000t_rx_status_ok
block|,
name|em_1000t_rx_status_undefined
init|=
literal|0xFF
block|}
name|em_1000t_rx_status
typedef|;
end_typedef

begin_struct
struct|struct
name|em_phy_info
block|{
name|em_cable_length
name|cable_length
decl_stmt|;
name|em_10bt_ext_dist_enable
name|extended_10bt_distance
decl_stmt|;
name|em_rev_polarity
name|cable_polarity
decl_stmt|;
name|em_polarity_reversal
name|polarity_correction
decl_stmt|;
name|em_down_no_idle
name|link_reset
decl_stmt|;
name|em_auto_x_mode
name|mdix_mode
decl_stmt|;
name|em_1000t_rx_status
name|local_rx
decl_stmt|;
name|em_1000t_rx_status
name|remote_rx
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|em_phy_stats
block|{
name|uint32_t
name|idle_errors
decl_stmt|;
name|uint32_t
name|receive_errors
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Function Prototypes */
end_comment

begin_function_decl
name|uint16_t
name|em_read_phy_reg
parameter_list|(
name|struct
name|em_shared_adapter
modifier|*
name|shared
parameter_list|,
name|uint32_t
name|reg_addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|em_write_phy_reg
parameter_list|(
name|struct
name|em_shared_adapter
modifier|*
name|shared
parameter_list|,
name|uint32_t
name|reg_addr
parameter_list|,
name|uint16_t
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|em_phy_hw_reset
parameter_list|(
name|struct
name|em_shared_adapter
modifier|*
name|shared
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|boolean_t
name|em_phy_reset
parameter_list|(
name|struct
name|em_shared_adapter
modifier|*
name|shared
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|boolean_t
name|em_phy_setup
parameter_list|(
name|struct
name|em_shared_adapter
modifier|*
name|shared
parameter_list|,
name|uint32_t
name|ctrl_reg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|boolean_t
name|em_phy_setup_autoneg
parameter_list|(
name|struct
name|em_shared_adapter
modifier|*
name|shared
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|em_config_mac_to_phy
parameter_list|(
name|struct
name|em_shared_adapter
modifier|*
name|shared
parameter_list|,
name|uint16_t
name|mii_reg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|em_config_collision_dist
parameter_list|(
name|struct
name|em_shared_adapter
modifier|*
name|shared
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|em_display_mii
parameter_list|(
name|struct
name|em_shared_adapter
modifier|*
name|shared
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|boolean_t
name|em_detect_gig_phy
parameter_list|(
name|struct
name|em_shared_adapter
modifier|*
name|shared
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|em_phy_reset_dsp
parameter_list|(
name|struct
name|em_shared_adapter
modifier|*
name|shared
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|boolean_t
name|em_wait_autoneg
parameter_list|(
name|struct
name|em_shared_adapter
modifier|*
name|shared
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|boolean_t
name|em_phy_get_info
parameter_list|(
name|struct
name|em_shared_adapter
modifier|*
name|shared
parameter_list|,
name|struct
name|em_phy_info
modifier|*
name|phy_status_info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|boolean_t
name|em_validate_mdi_setting
parameter_list|(
name|struct
name|em_shared_adapter
modifier|*
name|shared
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Bit definitions for the Management Data IO (MDIO) and Management Data  * Clock (MDC) pins in the Device Control Register.  */
end_comment

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
value|E1000_CTRL_EXT_SDP4_DIR
end_define

begin_define
define|#
directive|define
name|E1000_CTRL_PHY_RESET4
value|E1000_CTRL_EXT_SDP4_DATA
end_define

begin_comment
comment|/* PHY 1000 MII Register/Bit Definitions */
end_comment

begin_comment
comment|/* PHY Registers defined by IEEE */
end_comment

begin_define
define|#
directive|define
name|PHY_CTRL
value|0x00
end_define

begin_comment
comment|/* Control Register */
end_comment

begin_define
define|#
directive|define
name|PHY_STATUS
value|0x01
end_define

begin_comment
comment|/* Status Regiser */
end_comment

begin_define
define|#
directive|define
name|PHY_ID1
value|0x02
end_define

begin_comment
comment|/* Phy Id Reg (word 1) */
end_comment

begin_define
define|#
directive|define
name|PHY_ID2
value|0x03
end_define

begin_comment
comment|/* Phy Id Reg (word 2) */
end_comment

begin_define
define|#
directive|define
name|PHY_AUTONEG_ADV
value|0x04
end_define

begin_comment
comment|/* Autoneg Advertisement */
end_comment

begin_define
define|#
directive|define
name|PHY_LP_ABILITY
value|0x05
end_define

begin_comment
comment|/* Link Partner Ability (Base Page) */
end_comment

begin_define
define|#
directive|define
name|PHY_AUTONEG_EXP
value|0x06
end_define

begin_comment
comment|/* Autoneg Expansion Reg */
end_comment

begin_define
define|#
directive|define
name|PHY_NEXT_PAGE_TX
value|0x07
end_define

begin_comment
comment|/* Next Page TX */
end_comment

begin_define
define|#
directive|define
name|PHY_LP_NEXT_PAGE
value|0x08
end_define

begin_comment
comment|/* Link Partner Next Page */
end_comment

begin_define
define|#
directive|define
name|PHY_1000T_CTRL
value|0x09
end_define

begin_comment
comment|/* 1000Base-T Control Reg */
end_comment

begin_define
define|#
directive|define
name|PHY_1000T_STATUS
value|0x0A
end_define

begin_comment
comment|/* 1000Base-T Status Reg */
end_comment

begin_define
define|#
directive|define
name|PHY_EXT_STATUS
value|0x0F
end_define

begin_comment
comment|/* Extended Status Reg */
end_comment

begin_comment
comment|/* M88E1000 Specific Registers */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PHY_SPEC_CTRL
value|0x10
end_define

begin_comment
comment|/* PHY Specific Control Register */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PHY_SPEC_STATUS
value|0x11
end_define

begin_comment
comment|/* PHY Specific Status Register */
end_comment

begin_define
define|#
directive|define
name|M88E1000_INT_ENABLE
value|0x12
end_define

begin_comment
comment|/* Interrupt Enable Register */
end_comment

begin_define
define|#
directive|define
name|M88E1000_INT_STATUS
value|0x13
end_define

begin_comment
comment|/* Interrupt Status Register */
end_comment

begin_define
define|#
directive|define
name|M88E1000_EXT_PHY_SPEC_CTRL
value|0x14
end_define

begin_comment
comment|/* Extended PHY Specific Control */
end_comment

begin_define
define|#
directive|define
name|M88E1000_RX_ERR_CNTR
value|0x15
end_define

begin_comment
comment|/* Receive Error Counter */
end_comment

begin_define
define|#
directive|define
name|MAX_PHY_REG_ADDRESS
value|0x1F
end_define

begin_comment
comment|/* 5 bit address bus (0-0x1F) */
end_comment

begin_comment
comment|/* PHY Control Register */
end_comment

begin_define
define|#
directive|define
name|MII_CR_SPEED_SELECT_MSB
value|0x0040
end_define

begin_comment
comment|/* bits 6,13: 10=1000, 01=100, 00=10 */
end_comment

begin_define
define|#
directive|define
name|MII_CR_COLL_TEST_ENABLE
value|0x0080
end_define

begin_comment
comment|/* Collision test enable */
end_comment

begin_define
define|#
directive|define
name|MII_CR_FULL_DUPLEX
value|0x0100
end_define

begin_comment
comment|/* FDX =1, half duplex =0 */
end_comment

begin_define
define|#
directive|define
name|MII_CR_RESTART_AUTO_NEG
value|0x0200
end_define

begin_comment
comment|/* Restart auto negotiation */
end_comment

begin_define
define|#
directive|define
name|MII_CR_ISOLATE
value|0x0400
end_define

begin_comment
comment|/* Isolate PHY from MII */
end_comment

begin_define
define|#
directive|define
name|MII_CR_POWER_DOWN
value|0x0800
end_define

begin_comment
comment|/* Power down */
end_comment

begin_define
define|#
directive|define
name|MII_CR_AUTO_NEG_EN
value|0x1000
end_define

begin_comment
comment|/* Auto Neg Enable */
end_comment

begin_define
define|#
directive|define
name|MII_CR_SPEED_SELECT_LSB
value|0x2000
end_define

begin_comment
comment|/* bits 6,13: 10=1000, 01=100, 00=10 */
end_comment

begin_define
define|#
directive|define
name|MII_CR_LOOPBACK
value|0x4000
end_define

begin_comment
comment|/* 0 = normal, 1 = loopback */
end_comment

begin_define
define|#
directive|define
name|MII_CR_RESET
value|0x8000
end_define

begin_comment
comment|/* 0 = normal, 1 = PHY reset */
end_comment

begin_comment
comment|/* PHY Status Register */
end_comment

begin_define
define|#
directive|define
name|MII_SR_EXTENDED_CAPS
value|0x0001
end_define

begin_comment
comment|/* Extended register capabilities */
end_comment

begin_define
define|#
directive|define
name|MII_SR_JABBER_DETECT
value|0x0002
end_define

begin_comment
comment|/* Jabber Detected */
end_comment

begin_define
define|#
directive|define
name|MII_SR_LINK_STATUS
value|0x0004
end_define

begin_comment
comment|/* Link Status 1 = link */
end_comment

begin_define
define|#
directive|define
name|MII_SR_AUTONEG_CAPS
value|0x0008
end_define

begin_comment
comment|/* Auto Neg Capable */
end_comment

begin_define
define|#
directive|define
name|MII_SR_REMOTE_FAULT
value|0x0010
end_define

begin_comment
comment|/* Remote Fault Detect */
end_comment

begin_define
define|#
directive|define
name|MII_SR_AUTONEG_COMPLETE
value|0x0020
end_define

begin_comment
comment|/* Auto Neg Complete */
end_comment

begin_define
define|#
directive|define
name|MII_SR_PREAMBLE_SUPPRESS
value|0x0040
end_define

begin_comment
comment|/* Preamble may be suppressed */
end_comment

begin_define
define|#
directive|define
name|MII_SR_EXTENDED_STATUS
value|0x0100
end_define

begin_comment
comment|/* Ext. status info in Reg 0x0F */
end_comment

begin_define
define|#
directive|define
name|MII_SR_100T2_HD_CAPS
value|0x0200
end_define

begin_comment
comment|/* 100T2 Half Duplex Capable */
end_comment

begin_define
define|#
directive|define
name|MII_SR_100T2_FD_CAPS
value|0x0400
end_define

begin_comment
comment|/* 100T2 Full Duplex Capable */
end_comment

begin_define
define|#
directive|define
name|MII_SR_10T_HD_CAPS
value|0x0800
end_define

begin_comment
comment|/* 10T   Half Duplex Capable */
end_comment

begin_define
define|#
directive|define
name|MII_SR_10T_FD_CAPS
value|0x1000
end_define

begin_comment
comment|/* 10T   Full Duplex Capable */
end_comment

begin_define
define|#
directive|define
name|MII_SR_100X_HD_CAPS
value|0x2000
end_define

begin_comment
comment|/* 100X  Half Duplex Capable */
end_comment

begin_define
define|#
directive|define
name|MII_SR_100X_FD_CAPS
value|0x4000
end_define

begin_comment
comment|/* 100X  Full Duplex Capable */
end_comment

begin_define
define|#
directive|define
name|MII_SR_100T4_CAPS
value|0x8000
end_define

begin_comment
comment|/* 100T4 Capable */
end_comment

begin_comment
comment|/* Autoneg Advertisement Register */
end_comment

begin_define
define|#
directive|define
name|NWAY_AR_SELECTOR_FIELD
value|0x0001
end_define

begin_comment
comment|/* indicates IEEE 802.3 CSMA/CD */
end_comment

begin_define
define|#
directive|define
name|NWAY_AR_10T_HD_CAPS
value|0x0020
end_define

begin_comment
comment|/* 10T   Half Duplex Capable */
end_comment

begin_define
define|#
directive|define
name|NWAY_AR_10T_FD_CAPS
value|0x0040
end_define

begin_comment
comment|/* 10T   Full Duplex Capable */
end_comment

begin_define
define|#
directive|define
name|NWAY_AR_100TX_HD_CAPS
value|0x0080
end_define

begin_comment
comment|/* 100TX Half Duplex Capable */
end_comment

begin_define
define|#
directive|define
name|NWAY_AR_100TX_FD_CAPS
value|0x0100
end_define

begin_comment
comment|/* 100TX Full Duplex Capable */
end_comment

begin_define
define|#
directive|define
name|NWAY_AR_100T4_CAPS
value|0x0200
end_define

begin_comment
comment|/* 100T4 Capable */
end_comment

begin_define
define|#
directive|define
name|NWAY_AR_PAUSE
value|0x0400
end_define

begin_comment
comment|/* Pause operation desired */
end_comment

begin_define
define|#
directive|define
name|NWAY_AR_ASM_DIR
value|0x0800
end_define

begin_comment
comment|/* Asymmetric Pause Direction bit */
end_comment

begin_define
define|#
directive|define
name|NWAY_AR_REMOTE_FAULT
value|0x2000
end_define

begin_comment
comment|/* Remote Fault detected */
end_comment

begin_define
define|#
directive|define
name|NWAY_AR_NEXT_PAGE
value|0x8000
end_define

begin_comment
comment|/* Next Page ability supported */
end_comment

begin_comment
comment|/* Link Partner Ability Register (Base Page) */
end_comment

begin_define
define|#
directive|define
name|NWAY_LPAR_SELECTOR_FIELD
value|0x0000
end_define

begin_comment
comment|/* LP protocol selector field */
end_comment

begin_define
define|#
directive|define
name|NWAY_LPAR_10T_HD_CAPS
value|0x0020
end_define

begin_comment
comment|/* LP is 10T   Half Duplex Capable */
end_comment

begin_define
define|#
directive|define
name|NWAY_LPAR_10T_FD_CAPS
value|0x0040
end_define

begin_comment
comment|/* LP is 10T   Full Duplex Capable */
end_comment

begin_define
define|#
directive|define
name|NWAY_LPAR_100TX_HD_CAPS
value|0x0080
end_define

begin_comment
comment|/* LP is 100TX Half Duplex Capable */
end_comment

begin_define
define|#
directive|define
name|NWAY_LPAR_100TX_FD_CAPS
value|0x0100
end_define

begin_comment
comment|/* LP is 100TX Full Duplex Capable */
end_comment

begin_define
define|#
directive|define
name|NWAY_LPAR_100T4_CAPS
value|0x0200
end_define

begin_comment
comment|/* LP is 100T4 Capable */
end_comment

begin_define
define|#
directive|define
name|NWAY_LPAR_PAUSE
value|0x0400
end_define

begin_comment
comment|/* LP Pause operation desired */
end_comment

begin_define
define|#
directive|define
name|NWAY_LPAR_ASM_DIR
value|0x0800
end_define

begin_comment
comment|/* LP Asymmetric Pause Direction bit */
end_comment

begin_define
define|#
directive|define
name|NWAY_LPAR_REMOTE_FAULT
value|0x2000
end_define

begin_comment
comment|/* LP has detected Remote Fault */
end_comment

begin_define
define|#
directive|define
name|NWAY_LPAR_ACKNOWLEDGE
value|0x4000
end_define

begin_comment
comment|/* LP has rx'd link code word */
end_comment

begin_define
define|#
directive|define
name|NWAY_LPAR_NEXT_PAGE
value|0x8000
end_define

begin_comment
comment|/* Next Page ability supported */
end_comment

begin_comment
comment|/* Autoneg Expansion Register */
end_comment

begin_define
define|#
directive|define
name|NWAY_ER_LP_NWAY_CAPS
value|0x0001
end_define

begin_comment
comment|/* LP has Auto Neg Capability */
end_comment

begin_define
define|#
directive|define
name|NWAY_ER_PAGE_RXD
value|0x0002
end_define

begin_comment
comment|/* LP is 10T   Half Duplex Capable */
end_comment

begin_define
define|#
directive|define
name|NWAY_ER_NEXT_PAGE_CAPS
value|0x0004
end_define

begin_comment
comment|/* LP is 10T   Full Duplex Capable */
end_comment

begin_define
define|#
directive|define
name|NWAY_ER_LP_NEXT_PAGE_CAPS
value|0x0008
end_define

begin_comment
comment|/* LP is 100TX Half Duplex Capable */
end_comment

begin_define
define|#
directive|define
name|NWAY_ER_PAR_DETECT_FAULT
value|0x0100
end_define

begin_comment
comment|/* LP is 100TX Full Duplex Capable */
end_comment

begin_comment
comment|/* Next Page TX Register */
end_comment

begin_define
define|#
directive|define
name|NPTX_MSG_CODE_FIELD
value|0x0001
end_define

begin_comment
comment|/* NP msg code or unformatted data */
end_comment

begin_define
define|#
directive|define
name|NPTX_TOGGLE
value|0x0800
end_define

begin_comment
comment|/* Toggles between exchanges                                     * of different NP                                     */
end_comment

begin_define
define|#
directive|define
name|NPTX_ACKNOWLDGE2
value|0x1000
end_define

begin_comment
comment|/* 1 = will comply with msg                                     * 0 = cannot comply with msg                                     */
end_comment

begin_define
define|#
directive|define
name|NPTX_MSG_PAGE
value|0x2000
end_define

begin_comment
comment|/* formatted(1)/unformatted(0) pg */
end_comment

begin_define
define|#
directive|define
name|NPTX_NEXT_PAGE
value|0x8000
end_define

begin_comment
comment|/* 1 = addition NP will follow                                      * 0 = sending last NP                                     */
end_comment

begin_comment
comment|/* Link Partner Next Page Register */
end_comment

begin_define
define|#
directive|define
name|LP_RNPR_MSG_CODE_FIELD
value|0x0001
end_define

begin_comment
comment|/* NP msg code or unformatted data */
end_comment

begin_define
define|#
directive|define
name|LP_RNPR_TOGGLE
value|0x0800
end_define

begin_comment
comment|/* Toggles between exchanges                                        * of different NP                                        */
end_comment

begin_define
define|#
directive|define
name|LP_RNPR_ACKNOWLDGE2
value|0x1000
end_define

begin_comment
comment|/* 1 = will comply with msg                                         * 0 = cannot comply with msg                                        */
end_comment

begin_define
define|#
directive|define
name|LP_RNPR_MSG_PAGE
value|0x2000
end_define

begin_comment
comment|/* formatted(1)/unformatted(0) pg */
end_comment

begin_define
define|#
directive|define
name|LP_RNPR_ACKNOWLDGE
value|0x4000
end_define

begin_comment
comment|/* 1 = ACK / 0 = NO ACK */
end_comment

begin_define
define|#
directive|define
name|LP_RNPR_NEXT_PAGE
value|0x8000
end_define

begin_comment
comment|/* 1 = addition NP will follow                                         * 0 = sending last NP                                          */
end_comment

begin_comment
comment|/* 1000BASE-T Control Register */
end_comment

begin_define
define|#
directive|define
name|CR_1000T_ASYM_PAUSE
value|0x0080
end_define

begin_comment
comment|/* Advertise asymmetric pause bit */
end_comment

begin_define
define|#
directive|define
name|CR_1000T_HD_CAPS
value|0x0100
end_define

begin_comment
comment|/* Advertise 1000T HD capability */
end_comment

begin_define
define|#
directive|define
name|CR_1000T_FD_CAPS
value|0x0200
end_define

begin_comment
comment|/* Advertise 1000T FD capability  */
end_comment

begin_define
define|#
directive|define
name|CR_1000T_REPEATER_DTE
value|0x0400
end_define

begin_comment
comment|/* 1=Repeater/switch device port */
end_comment

begin_comment
comment|/* 0=DTE device */
end_comment

begin_define
define|#
directive|define
name|CR_1000T_MS_VALUE
value|0x0800
end_define

begin_comment
comment|/* 1=Configure PHY as Master */
end_comment

begin_comment
comment|/* 0=Configure PHY as Slave */
end_comment

begin_define
define|#
directive|define
name|CR_1000T_MS_ENABLE
value|0x1000
end_define

begin_comment
comment|/* 1=Master/Slave manual config value */
end_comment

begin_comment
comment|/* 0=Automatic Master/Slave config */
end_comment

begin_define
define|#
directive|define
name|CR_1000T_TEST_MODE_NORMAL
value|0x0000
end_define

begin_comment
comment|/* Normal Operation */
end_comment

begin_define
define|#
directive|define
name|CR_1000T_TEST_MODE_1
value|0x2000
end_define

begin_comment
comment|/* Transmit Waveform test */
end_comment

begin_define
define|#
directive|define
name|CR_1000T_TEST_MODE_2
value|0x4000
end_define

begin_comment
comment|/* Master Transmit Jitter test */
end_comment

begin_define
define|#
directive|define
name|CR_1000T_TEST_MODE_3
value|0x6000
end_define

begin_comment
comment|/* Slave Transmit Jitter test */
end_comment

begin_define
define|#
directive|define
name|CR_1000T_TEST_MODE_4
value|0x8000
end_define

begin_comment
comment|/* Transmitter Distortion test */
end_comment

begin_comment
comment|/* 1000BASE-T Status Register */
end_comment

begin_define
define|#
directive|define
name|SR_1000T_IDLE_ERROR_CNT
value|0x00FF
end_define

begin_comment
comment|/* Num idle errors since last read */
end_comment

begin_define
define|#
directive|define
name|SR_1000T_ASYM_PAUSE_DIR
value|0x0100
end_define

begin_comment
comment|/* LP asymmetric pause direction bit */
end_comment

begin_define
define|#
directive|define
name|SR_1000T_LP_HD_CAPS
value|0x0400
end_define

begin_comment
comment|/* LP is 1000T HD capable */
end_comment

begin_define
define|#
directive|define
name|SR_1000T_LP_FD_CAPS
value|0x0800
end_define

begin_comment
comment|/* LP is 1000T FD capable */
end_comment

begin_define
define|#
directive|define
name|SR_1000T_REMOTE_RX_STATUS
value|0x1000
end_define

begin_comment
comment|/* Remote receiver OK */
end_comment

begin_define
define|#
directive|define
name|SR_1000T_LOCAL_RX_STATUS
value|0x2000
end_define

begin_comment
comment|/* Local receiver OK */
end_comment

begin_define
define|#
directive|define
name|SR_1000T_MS_CONFIG_RES
value|0x4000
end_define

begin_comment
comment|/* 1=Local TX is Master, 0=Slave */
end_comment

begin_define
define|#
directive|define
name|SR_1000T_MS_CONFIG_FAULT
value|0x8000
end_define

begin_comment
comment|/* Master/Slave config fault */
end_comment

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

begin_comment
comment|/* Extended Status Register */
end_comment

begin_define
define|#
directive|define
name|IEEE_ESR_1000T_HD_CAPS
value|0x1000
end_define

begin_comment
comment|/* 1000T HD capable */
end_comment

begin_define
define|#
directive|define
name|IEEE_ESR_1000T_FD_CAPS
value|0x2000
end_define

begin_comment
comment|/* 1000T FD capable */
end_comment

begin_define
define|#
directive|define
name|IEEE_ESR_1000X_HD_CAPS
value|0x4000
end_define

begin_comment
comment|/* 1000X HD capable */
end_comment

begin_define
define|#
directive|define
name|IEEE_ESR_1000X_FD_CAPS
value|0x8000
end_define

begin_comment
comment|/* 1000X FD capable */
end_comment

begin_define
define|#
directive|define
name|PHY_TX_POLARITY_MASK
value|0x0100
end_define

begin_comment
comment|/* register 10h bit 8 (polarity bit) */
end_comment

begin_define
define|#
directive|define
name|PHY_TX_NORMAL_POLARITY
value|0
end_define

begin_comment
comment|/* register 10h bit 8 (normal polarity) */
end_comment

begin_define
define|#
directive|define
name|AUTO_POLARITY_DISABLE
value|0x0010
end_define

begin_comment
comment|/* register 11h bit 4 */
end_comment

begin_comment
comment|/* (0=enable, 1=disable) */
end_comment

begin_comment
comment|/* M88E1000 PHY Specific Control Register */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PSCR_JABBER_DISABLE
value|0x0001
end_define

begin_comment
comment|/* 1=Jabber Function disabled */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PSCR_POLARITY_REVERSAL
value|0x0002
end_define

begin_comment
comment|/* 1=Polarity Reversal enabled */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PSCR_SQE_TEST
value|0x0004
end_define

begin_comment
comment|/* 1=SQE Test enabled */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PSCR_CLK125_DISABLE
value|0x0010
end_define

begin_comment
comment|/* 1=CLK125 low,                                                  * 0=CLK125 toggling                                                 */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PSCR_MDI_MANUAL_MODE
value|0x0000
end_define

begin_comment
comment|/* MDI Crossover Mode bits 6:5 */
end_comment

begin_comment
comment|/* Manual MDI configuration */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PSCR_MDIX_MANUAL_MODE
value|0x0020
end_define

begin_comment
comment|/* Manual MDIX configuration */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PSCR_AUTO_X_1000T
value|0x0040
end_define

begin_comment
comment|/* 1000BASE-T: Auto crossover,                                                 *  100BASE-TX/10BASE-T:                                                  *  MDI Mode                                                 */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PSCR_AUTO_X_MODE
value|0x0060
end_define

begin_comment
comment|/* Auto crossover enabled                                                  * all speeds.                                                  */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PSCR_10BT_EXT_DIST_ENABLE
value|0x0080
end_define

begin_comment
comment|/* 1=Enable Extended 10BASE-T distance                                          * (Lower 10BASE-T RX Threshold)                                          * 0=Normal 10BASE-T RX Threshold */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PSCR_MII_5BIT_ENABLE
value|0x0100
end_define

begin_comment
comment|/* 1=5-Bit interface in 100BASE-TX                                          * 0=MII interface in 100BASE-TX */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PSCR_SCRAMBLER_DISABLE
value|0x0200
end_define

begin_comment
comment|/* 1=Scrambler disable */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PSCR_FORCE_LINK_GOOD
value|0x0400
end_define

begin_comment
comment|/* 1=Force link good */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PSCR_ASSERT_CRS_ON_TX
value|0x0800
end_define

begin_comment
comment|/* 1=Assert CRS on Transmit */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PSCR_POLARITY_REVERSAL_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|M88E1000_PSCR_AUTO_X_MODE_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|M88E1000_PSCR_10BT_EXT_DIST_ENABLE_SHIFT
value|7
end_define

begin_comment
comment|/* M88E1000 PHY Specific Status Register */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PSSR_JABBER
value|0x0001
end_define

begin_comment
comment|/* 1=Jabber */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PSSR_REV_POLARITY
value|0x0002
end_define

begin_comment
comment|/* 1=Polarity reversed */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PSSR_MDIX
value|0x0040
end_define

begin_comment
comment|/* 1=MDIX; 0=MDI */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PSSR_CABLE_LENGTH
value|0x0380
end_define

begin_comment
comment|/* 0=<50M;1=50-80M;2=80-110M;                                             * 3=110-140M;4=>140M */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PSSR_LINK
value|0x0400
end_define

begin_comment
comment|/* 1=Link up, 0=Link down */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PSSR_SPD_DPLX_RESOLVED
value|0x0800
end_define

begin_comment
comment|/* 1=Speed& Duplex resolved */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PSSR_PAGE_RCVD
value|0x1000
end_define

begin_comment
comment|/* 1=Page received */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PSSR_DPLX
value|0x2000
end_define

begin_comment
comment|/* 1=Duplex 0=Half Duplex */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PSSR_SPEED
value|0xC000
end_define

begin_comment
comment|/* Speed, bits 14:15 */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PSSR_10MBS
value|0x0000
end_define

begin_comment
comment|/* 00=10Mbs */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PSSR_100MBS
value|0x4000
end_define

begin_comment
comment|/* 01=100Mbs */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PSSR_1000MBS
value|0x8000
end_define

begin_comment
comment|/* 10=1000Mbs */
end_comment

begin_define
define|#
directive|define
name|M88E1000_PSSR_REV_POLARITY_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|M88E1000_PSSR_MDIX_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|M88E1000_PSSR_CABLE_LENGTH_SHIFT
value|7
end_define

begin_comment
comment|/* M88E1000 Extended PHY Specific Control Register */
end_comment

begin_define
define|#
directive|define
name|M88E1000_EPSCR_FIBER_LOOPBACK
value|0x4000
end_define

begin_comment
comment|/* 1=Fiber loopback */
end_comment

begin_define
define|#
directive|define
name|M88E1000_EPSCR_DOWN_NO_IDLE
value|0x8000
end_define

begin_comment
comment|/* 1=Lost lock detect enabled.                                               * Will assert lost lock and bring                                               * link down if idle not seen                                               * within 1ms in 1000BASE-T                                                */
end_comment

begin_define
define|#
directive|define
name|M88E1000_EPSCR_TX_CLK_2_5
value|0x0060
end_define

begin_comment
comment|/* 2.5 MHz TX_CLK */
end_comment

begin_define
define|#
directive|define
name|M88E1000_EPSCR_TX_CLK_25
value|0x0070
end_define

begin_comment
comment|/* 25  MHz TX_CLK */
end_comment

begin_define
define|#
directive|define
name|M88E1000_EPSCR_TX_CLK_0
value|0x0000
end_define

begin_comment
comment|/* NO  TX_CLK */
end_comment

begin_define
define|#
directive|define
name|M88E1000_EPSCR_DOWN_NO_IDLE_SHIFT
value|15
end_define

begin_comment
comment|/* Bit definitions for valid PHY IDs. */
end_comment

begin_define
define|#
directive|define
name|M88E1000_12_PHY_ID
value|0x01410C50
end_define

begin_define
define|#
directive|define
name|M88E1000_14_PHY_ID
value|0x01410C40
end_define

begin_define
define|#
directive|define
name|M88E1000_I_PHY_ID
value|0x01410C30
end_define

begin_define
define|#
directive|define
name|M88E1011_I_PHY_ID
value|0x01410C20
end_define

begin_comment
comment|/* Miscellaneous PHY bit definitions. */
end_comment

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
name|PHY_AUTO_NEG_TIME
value|45
end_define

begin_comment
comment|/* 4.5 Seconds */
end_comment

begin_define
define|#
directive|define
name|PHY_FORCE_TIME
value|20
end_define

begin_comment
comment|/* 2.0 Seconds */
end_comment

begin_define
define|#
directive|define
name|PHY_REVISION_MASK
value|0xFFFFFFF0
end_define

begin_define
define|#
directive|define
name|DEVICE_SPEED_MASK
value|0x00000300
end_define

begin_comment
comment|/* Device Ctrl Reg Speed Mask */
end_comment

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

begin_define
define|#
directive|define
name|AUTONEG_ADVERTISE_SPEED_DEFAULT
value|0x002F
end_define

begin_comment
comment|/* Everything but 1000-Half */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _EM_PHY_H_ */
end_comment

end_unit

