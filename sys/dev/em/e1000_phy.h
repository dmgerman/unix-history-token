begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*******************************************************************************    Copyright (c) 2001-2007, Intel Corporation    All rights reserved.      Redistribution and use in source and binary forms, with or without    modification, are permitted provided that the following conditions are met:       1. Redistributions of source code must retain the above copyright notice,        this list of conditions and the following disclaimer.       2. Redistributions in binary form must reproduce the above copyright        notice, this list of conditions and the following disclaimer in the        documentation and/or other materials provided with the distribution.       3. Neither the name of the Intel Corporation nor the names of its        contributors may be used to endorse or promote products derived from        this software without specific prior written permission.      THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE    ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE    LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR    CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF    SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS    INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN    CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)    ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE   POSSIBILITY OF SUCH DAMAGE.  *******************************************************************************/
end_comment

begin_comment
comment|/*  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_E1000_PHY_H_
end_ifndef

begin_define
define|#
directive|define
name|_E1000_PHY_H_
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|e1000_ms_hw_default
init|=
literal|0
block|,
name|e1000_ms_force_master
block|,
name|e1000_ms_force_slave
block|,
name|e1000_ms_auto
block|}
name|e1000_ms_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|e1000_smart_speed_default
init|=
literal|0
block|,
name|e1000_smart_speed_on
block|,
name|e1000_smart_speed_off
block|}
name|e1000_smart_speed
typedef|;
end_typedef

begin_include
include|#
directive|include
file|"e1000_api.h"
end_include

begin_function_decl
name|s32
name|e1000_check_downshift_generic
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
name|e1000_check_polarity_m88
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
name|e1000_check_polarity_igp
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
name|e1000_check_reset_block_generic
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
name|e1000_copper_link_autoneg
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
name|e1000_phy_force_speed_duplex
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
name|e1000_copper_link_setup_igp
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
name|e1000_copper_link_setup_m88
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
name|e1000_phy_force_speed_duplex_igp
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
name|e1000_phy_force_speed_duplex_m88
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
name|e1000_get_cable_length_m88
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
name|e1000_get_cable_length_igp_2
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
name|e1000_get_cfg_done_generic
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
name|e1000_get_phy_id
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
name|e1000_get_phy_info_igp
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
name|e1000_get_phy_info_m88
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
name|e1000_phy_sw_reset_generic
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
name|e1000_phy_force_speed_duplex_setup
parameter_list|(
name|struct
name|e1000_hw
modifier|*
name|hw
parameter_list|,
name|u16
modifier|*
name|phy_ctrl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|s32
name|e1000_phy_hw_reset_generic
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
name|e1000_phy_reset_dsp_generic
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
name|e1000_phy_setup_autoneg
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
name|e1000_read_kmrn_reg_generic
parameter_list|(
name|struct
name|e1000_hw
modifier|*
name|hw
parameter_list|,
name|u32
name|offset
parameter_list|,
name|u16
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|s32
name|e1000_read_phy_reg_igp
parameter_list|(
name|struct
name|e1000_hw
modifier|*
name|hw
parameter_list|,
name|u32
name|offset
parameter_list|,
name|u16
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|s32
name|e1000_read_phy_reg_m88
parameter_list|(
name|struct
name|e1000_hw
modifier|*
name|hw
parameter_list|,
name|u32
name|offset
parameter_list|,
name|u16
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|s32
name|e1000_set_d3_lplu_state_generic
parameter_list|(
name|struct
name|e1000_hw
modifier|*
name|hw
parameter_list|,
name|boolean_t
name|active
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|s32
name|e1000_setup_copper_link_generic
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
name|e1000_wait_autoneg_generic
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
name|e1000_write_kmrn_reg_generic
parameter_list|(
name|struct
name|e1000_hw
modifier|*
name|hw
parameter_list|,
name|u32
name|offset
parameter_list|,
name|u16
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|s32
name|e1000_write_phy_reg_igp
parameter_list|(
name|struct
name|e1000_hw
modifier|*
name|hw
parameter_list|,
name|u32
name|offset
parameter_list|,
name|u16
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|s32
name|e1000_write_phy_reg_m88
parameter_list|(
name|struct
name|e1000_hw
modifier|*
name|hw
parameter_list|,
name|u32
name|offset
parameter_list|,
name|u16
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|s32
name|e1000_phy_reset_dsp
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
name|e1000_phy_has_link_generic
parameter_list|(
name|struct
name|e1000_hw
modifier|*
name|hw
parameter_list|,
name|u32
name|iterations
parameter_list|,
name|u32
name|usec_interval
parameter_list|,
name|boolean_t
modifier|*
name|success
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|s32
name|e1000_phy_init_script_igp3
parameter_list|(
name|struct
name|e1000_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* IGP01E1000 Specific Registers */
end_comment

begin_define
define|#
directive|define
name|IGP01E1000_PHY_PORT_CONFIG
value|0x10
end_define

begin_comment
comment|/* Port Config */
end_comment

begin_define
define|#
directive|define
name|IGP01E1000_PHY_PORT_STATUS
value|0x11
end_define

begin_comment
comment|/* Status */
end_comment

begin_define
define|#
directive|define
name|IGP01E1000_PHY_PORT_CTRL
value|0x12
end_define

begin_comment
comment|/* Control */
end_comment

begin_define
define|#
directive|define
name|IGP01E1000_PHY_LINK_HEALTH
value|0x13
end_define

begin_comment
comment|/* PHY Link Health */
end_comment

begin_define
define|#
directive|define
name|IGP01E1000_GMII_FIFO
value|0x14
end_define

begin_comment
comment|/* GMII FIFO */
end_comment

begin_define
define|#
directive|define
name|IGP01E1000_PHY_CHANNEL_QUALITY
value|0x15
end_define

begin_comment
comment|/* PHY Channel Quality */
end_comment

begin_define
define|#
directive|define
name|IGP02E1000_PHY_POWER_MGMT
value|0x19
end_define

begin_comment
comment|/* Power Management */
end_comment

begin_define
define|#
directive|define
name|IGP01E1000_PHY_PAGE_SELECT
value|0x1F
end_define

begin_comment
comment|/* Page Select */
end_comment

begin_define
define|#
directive|define
name|IGP01E1000_PHY_PCS_INIT_REG
value|0x00B4
end_define

begin_define
define|#
directive|define
name|IGP01E1000_PHY_POLARITY_MASK
value|0x0078
end_define

begin_define
define|#
directive|define
name|IGP01E1000_PSCR_AUTO_MDIX
value|0x1000
end_define

begin_define
define|#
directive|define
name|IGP01E1000_PSCR_FORCE_MDI_MDIX
value|0x2000
end_define

begin_comment
comment|/* 0=MDI, 1=MDIX */
end_comment

begin_define
define|#
directive|define
name|IGP01E1000_PSCFR_SMART_SPEED
value|0x0080
end_define

begin_define
define|#
directive|define
name|IGP01E1000_GMII_FLEX_SPD
value|0x0010
end_define

begin_comment
comment|/* Enable flexible speed                                                   * on link-up */
end_comment

begin_define
define|#
directive|define
name|IGP01E1000_GMII_SPD
value|0x0020
end_define

begin_comment
comment|/* Enable SPD */
end_comment

begin_define
define|#
directive|define
name|IGP02E1000_PM_SPD
value|0x0001
end_define

begin_comment
comment|/* Smart Power Down */
end_comment

begin_define
define|#
directive|define
name|IGP02E1000_PM_D0_LPLU
value|0x0002
end_define

begin_comment
comment|/* For D0a states */
end_comment

begin_define
define|#
directive|define
name|IGP02E1000_PM_D3_LPLU
value|0x0004
end_define

begin_comment
comment|/* For all other states */
end_comment

begin_define
define|#
directive|define
name|IGP01E1000_PLHR_SS_DOWNGRADE
value|0x8000
end_define

begin_define
define|#
directive|define
name|IGP01E1000_PSSR_POLARITY_REVERSED
value|0x0002
end_define

begin_define
define|#
directive|define
name|IGP01E1000_PSSR_MDIX
value|0x0008
end_define

begin_define
define|#
directive|define
name|IGP01E1000_PSSR_SPEED_MASK
value|0xC000
end_define

begin_define
define|#
directive|define
name|IGP01E1000_PSSR_SPEED_1000MBPS
value|0xC000
end_define

begin_define
define|#
directive|define
name|IGP02E1000_PHY_CHANNEL_NUM
value|4
end_define

begin_define
define|#
directive|define
name|IGP02E1000_PHY_AGC_A
value|0x11B1
end_define

begin_define
define|#
directive|define
name|IGP02E1000_PHY_AGC_B
value|0x12B1
end_define

begin_define
define|#
directive|define
name|IGP02E1000_PHY_AGC_C
value|0x14B1
end_define

begin_define
define|#
directive|define
name|IGP02E1000_PHY_AGC_D
value|0x18B1
end_define

begin_define
define|#
directive|define
name|IGP02E1000_AGC_LENGTH_SHIFT
value|9
end_define

begin_comment
comment|/* Course - 15:13, Fine - 12:9 */
end_comment

begin_define
define|#
directive|define
name|IGP02E1000_AGC_LENGTH_MASK
value|0x7F
end_define

begin_define
define|#
directive|define
name|IGP02E1000_AGC_RANGE
value|15
end_define

begin_define
define|#
directive|define
name|IGP03E1000_PHY_MISC_CTRL
value|0x1B
end_define

begin_define
define|#
directive|define
name|IGP03E1000_PHY_MISC_DUPLEX_MANUAL_SET
value|0x1000
end_define

begin_comment
comment|/* Manually Set Duplex */
end_comment

begin_define
define|#
directive|define
name|E1000_CABLE_LENGTH_UNDEFINED
value|0xFF
end_define

begin_define
define|#
directive|define
name|E1000_KMRNCTRLSTA_OFFSET
value|0x001F0000
end_define

begin_define
define|#
directive|define
name|E1000_KMRNCTRLSTA_OFFSET_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|E1000_KMRNCTRLSTA_REN
value|0x00200000
end_define

begin_define
define|#
directive|define
name|E1000_KMRNCTRLSTA_DIAG_OFFSET
value|0x3
end_define

begin_comment
comment|/* Kumeran Diagnostic */
end_comment

begin_define
define|#
directive|define
name|E1000_KMRNCTRLSTA_DIAG_NELPBK
value|0x1000
end_define

begin_comment
comment|/* Nearend Loopback mode */
end_comment

begin_define
define|#
directive|define
name|IFE_PHY_EXTENDED_STATUS_CONTROL
value|0x10
end_define

begin_define
define|#
directive|define
name|IFE_PHY_SPECIAL_CONTROL
value|0x11
end_define

begin_comment
comment|/* 100BaseTx PHY Special Control */
end_comment

begin_define
define|#
directive|define
name|IFE_PHY_SPECIAL_CONTROL_LED
value|0x1B
end_define

begin_comment
comment|/* PHY Special and LED Control */
end_comment

begin_define
define|#
directive|define
name|IFE_PHY_MDIX_CONTROL
value|0x1C
end_define

begin_comment
comment|/* MDI/MDI-X Control */
end_comment

begin_comment
comment|/* IFE PHY Extended Status Control */
end_comment

begin_define
define|#
directive|define
name|IFE_PESC_POLARITY_REVERSED
value|0x0100
end_define

begin_comment
comment|/* IFE PHY Special Control */
end_comment

begin_define
define|#
directive|define
name|IFE_PSC_AUTO_POLARITY_DISABLE
value|0x0010
end_define

begin_define
define|#
directive|define
name|IFE_PSC_FORCE_POLARITY
value|0x0020
end_define

begin_define
define|#
directive|define
name|IFE_PSC_DISABLE_DYNAMIC_POWER_DOWN
value|0x0100
end_define

begin_comment
comment|/* IFE PHY Special Control and LED Control */
end_comment

begin_define
define|#
directive|define
name|IFE_PSCL_PROBE_MODE
value|0x0020
end_define

begin_define
define|#
directive|define
name|IFE_PSCL_PROBE_LEDS_OFF
value|0x0006
end_define

begin_comment
comment|/* Force LEDs 0 and 2 off */
end_comment

begin_define
define|#
directive|define
name|IFE_PSCL_PROBE_LEDS_ON
value|0x0007
end_define

begin_comment
comment|/* Force LEDs 0 and 2 on */
end_comment

begin_comment
comment|/* IFE PHY MDIX Control */
end_comment

begin_define
define|#
directive|define
name|IFE_PMC_MDIX_STATUS
value|0x0020
end_define

begin_comment
comment|/* 1=MDI-X, 0=MDI */
end_comment

begin_define
define|#
directive|define
name|IFE_PMC_FORCE_MDIX
value|0x0040
end_define

begin_comment
comment|/* 1=force MDI-X, 0=force MDI */
end_comment

begin_define
define|#
directive|define
name|IFE_PMC_AUTO_MDIX
value|0x0080
end_define

begin_comment
comment|/* 1=enable auto MDI/MDI-X, 0=disable */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

