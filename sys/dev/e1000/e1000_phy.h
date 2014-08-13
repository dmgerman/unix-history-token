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
name|_E1000_PHY_H_
end_ifndef

begin_define
define|#
directive|define
name|_E1000_PHY_H_
end_define

begin_function_decl
name|void
name|e1000_init_phy_ops_generic
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
name|e1000_null_read_reg
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
name|void
name|e1000_null_phy_generic
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
name|e1000_null_lplu_state
parameter_list|(
name|struct
name|e1000_hw
modifier|*
name|hw
parameter_list|,
name|bool
name|active
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|s32
name|e1000_null_write_reg
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
name|e1000_null_set_page
parameter_list|(
name|struct
name|e1000_hw
modifier|*
name|hw
parameter_list|,
name|u16
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|s32
name|e1000_read_i2c_byte_null
parameter_list|(
name|struct
name|e1000_hw
modifier|*
name|hw
parameter_list|,
name|u8
name|byte_offset
parameter_list|,
name|u8
name|dev_addr
parameter_list|,
name|u8
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|s32
name|e1000_write_i2c_byte_null
parameter_list|(
name|struct
name|e1000_hw
modifier|*
name|hw
parameter_list|,
name|u8
name|byte_offset
parameter_list|,
name|u8
name|dev_addr
parameter_list|,
name|u8
name|data
parameter_list|)
function_decl|;
end_function_decl

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
name|e1000_check_polarity_ife
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
name|e1000_copper_link_setup_m88_gen2
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
name|e1000_phy_force_speed_duplex_ife
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
name|e1000_get_cable_length_m88_gen2
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
name|e1000_get_phy_info_ife
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
name|e1000_read_kmrn_reg_locked
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
name|e1000_set_page_igp
parameter_list|(
name|struct
name|e1000_hw
modifier|*
name|hw
parameter_list|,
name|u16
name|page
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
name|e1000_read_phy_reg_igp_locked
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
name|bool
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
name|e1000_write_kmrn_reg_locked
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
name|e1000_write_phy_reg_igp_locked
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
name|bool
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

begin_function_decl
name|enum
name|e1000_phy_type
name|e1000_get_phy_type_from_id
parameter_list|(
name|u32
name|phy_id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|s32
name|e1000_determine_phy_address
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
name|e1000_write_phy_reg_bm
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
name|e1000_read_phy_reg_bm
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
name|e1000_enable_phy_wakeup_reg_access_bm
parameter_list|(
name|struct
name|e1000_hw
modifier|*
name|hw
parameter_list|,
name|u16
modifier|*
name|phy_reg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|s32
name|e1000_disable_phy_wakeup_reg_access_bm
parameter_list|(
name|struct
name|e1000_hw
modifier|*
name|hw
parameter_list|,
name|u16
modifier|*
name|phy_reg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|s32
name|e1000_read_phy_reg_bm2
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
name|e1000_write_phy_reg_bm2
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
name|void
name|e1000_power_up_phy_copper
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
name|e1000_power_down_phy_copper
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
name|e1000_read_phy_reg_mdic
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
name|e1000_write_phy_reg_mdic
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
name|e1000_read_phy_reg_i2c
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
name|e1000_write_phy_reg_i2c
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
name|e1000_read_sfp_data_byte
parameter_list|(
name|struct
name|e1000_hw
modifier|*
name|hw
parameter_list|,
name|u16
name|offset
parameter_list|,
name|u8
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|s32
name|e1000_write_sfp_data_byte
parameter_list|(
name|struct
name|e1000_hw
modifier|*
name|hw
parameter_list|,
name|u16
name|offset
parameter_list|,
name|u8
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|s32
name|e1000_read_phy_reg_hv
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
name|e1000_read_phy_reg_hv_locked
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
name|e1000_read_phy_reg_page_hv
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
name|e1000_write_phy_reg_hv
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
name|e1000_write_phy_reg_hv_locked
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
name|e1000_write_phy_reg_page_hv
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
name|e1000_link_stall_workaround_hv
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
name|e1000_copper_link_setup_82577
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
name|e1000_check_polarity_82577
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
name|e1000_get_phy_info_82577
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
name|e1000_phy_force_speed_duplex_82577
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
name|e1000_get_cable_length_82577
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
name|e1000_write_phy_reg_gs40g
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
name|e1000_read_phy_reg_gs40g
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
name|e1000_read_phy_reg_mphy
parameter_list|(
name|struct
name|e1000_hw
modifier|*
name|hw
parameter_list|,
name|u32
name|address
parameter_list|,
name|u32
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|s32
name|e1000_write_phy_reg_mphy
parameter_list|(
name|struct
name|e1000_hw
modifier|*
name|hw
parameter_list|,
name|u32
name|address
parameter_list|,
name|u32
name|data
parameter_list|,
name|bool
name|line_override
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|e1000_is_mphy_ready
parameter_list|(
name|struct
name|e1000_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|E1000_MAX_PHY_ADDR
value|8
end_define

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
name|BM_PHY_PAGE_SELECT
value|22
end_define

begin_comment
comment|/* Page Select for BM */
end_comment

begin_define
define|#
directive|define
name|IGP_PAGE_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|PHY_REG_MASK
value|0x1F
end_define

begin_comment
comment|/* GS40G - I210 PHY defines */
end_comment

begin_define
define|#
directive|define
name|GS40G_PAGE_SELECT
value|0x16
end_define

begin_define
define|#
directive|define
name|GS40G_PAGE_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|GS40G_OFFSET_MASK
value|0xFFFF
end_define

begin_define
define|#
directive|define
name|GS40G_PAGE_2
value|0x20000
end_define

begin_define
define|#
directive|define
name|GS40G_MAC_REG2
value|0x15
end_define

begin_define
define|#
directive|define
name|GS40G_MAC_LB
value|0x4140
end_define

begin_define
define|#
directive|define
name|GS40G_MAC_SPEED_1G
value|0X0006
end_define

begin_define
define|#
directive|define
name|GS40G_COPPER_SPEC
value|0x0010
end_define

begin_comment
comment|/* BM/HV Specific Registers */
end_comment

begin_define
define|#
directive|define
name|BM_PORT_CTRL_PAGE
value|769
end_define

begin_define
define|#
directive|define
name|BM_WUC_PAGE
value|800
end_define

begin_define
define|#
directive|define
name|BM_WUC_ADDRESS_OPCODE
value|0x11
end_define

begin_define
define|#
directive|define
name|BM_WUC_DATA_OPCODE
value|0x12
end_define

begin_define
define|#
directive|define
name|BM_WUC_ENABLE_PAGE
value|BM_PORT_CTRL_PAGE
end_define

begin_define
define|#
directive|define
name|BM_WUC_ENABLE_REG
value|17
end_define

begin_define
define|#
directive|define
name|BM_WUC_ENABLE_BIT
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|BM_WUC_HOST_WU_BIT
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|BM_WUC_ME_WU_BIT
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|PHY_UPPER_SHIFT
value|21
end_define

begin_define
define|#
directive|define
name|BM_PHY_REG
parameter_list|(
name|page
parameter_list|,
name|reg
parameter_list|)
define|\
value|(((reg)& MAX_PHY_REG_ADDRESS) |\ 	 (((page)& 0xFFFF)<< PHY_PAGE_SHIFT) |\ 	 (((reg)& ~MAX_PHY_REG_ADDRESS)<< (PHY_UPPER_SHIFT - PHY_PAGE_SHIFT)))
end_define

begin_define
define|#
directive|define
name|BM_PHY_REG_PAGE
parameter_list|(
name|offset
parameter_list|)
define|\
value|((u16)(((offset)>> PHY_PAGE_SHIFT)& 0xFFFF))
end_define

begin_define
define|#
directive|define
name|BM_PHY_REG_NUM
parameter_list|(
name|offset
parameter_list|)
define|\
value|((u16)(((offset)& MAX_PHY_REG_ADDRESS) |\ 	 (((offset)>> (PHY_UPPER_SHIFT - PHY_PAGE_SHIFT))&\ 		~MAX_PHY_REG_ADDRESS)))
end_define

begin_define
define|#
directive|define
name|HV_INTC_FC_PAGE_START
value|768
end_define

begin_define
define|#
directive|define
name|I82578_ADDR_REG
value|29
end_define

begin_define
define|#
directive|define
name|I82577_ADDR_REG
value|16
end_define

begin_define
define|#
directive|define
name|I82577_CFG_REG
value|22
end_define

begin_define
define|#
directive|define
name|I82577_CFG_ASSERT_CRS_ON_TX
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|I82577_CFG_ENABLE_DOWNSHIFT
value|(3<< 10)
end_define

begin_comment
comment|/* auto downshift */
end_comment

begin_define
define|#
directive|define
name|I82577_CTRL_REG
value|23
end_define

begin_comment
comment|/* 82577 specific PHY registers */
end_comment

begin_define
define|#
directive|define
name|I82577_PHY_CTRL_2
value|18
end_define

begin_define
define|#
directive|define
name|I82577_PHY_LBK_CTRL
value|19
end_define

begin_define
define|#
directive|define
name|I82577_PHY_STATUS_2
value|26
end_define

begin_define
define|#
directive|define
name|I82577_PHY_DIAG_STATUS
value|31
end_define

begin_comment
comment|/* I82577 PHY Status 2 */
end_comment

begin_define
define|#
directive|define
name|I82577_PHY_STATUS2_REV_POLARITY
value|0x0400
end_define

begin_define
define|#
directive|define
name|I82577_PHY_STATUS2_MDIX
value|0x0800
end_define

begin_define
define|#
directive|define
name|I82577_PHY_STATUS2_SPEED_MASK
value|0x0300
end_define

begin_define
define|#
directive|define
name|I82577_PHY_STATUS2_SPEED_1000MBPS
value|0x0200
end_define

begin_comment
comment|/* I82577 PHY Control 2 */
end_comment

begin_define
define|#
directive|define
name|I82577_PHY_CTRL2_MANUAL_MDIX
value|0x0200
end_define

begin_define
define|#
directive|define
name|I82577_PHY_CTRL2_AUTO_MDI_MDIX
value|0x0400
end_define

begin_define
define|#
directive|define
name|I82577_PHY_CTRL2_MDIX_CFG_MASK
value|0x0600
end_define

begin_comment
comment|/* I82577 PHY Diagnostics Status */
end_comment

begin_define
define|#
directive|define
name|I82577_DSTATUS_CABLE_LENGTH
value|0x03FC
end_define

begin_define
define|#
directive|define
name|I82577_DSTATUS_CABLE_LENGTH_SHIFT
value|2
end_define

begin_comment
comment|/* 82580 PHY Power Management */
end_comment

begin_define
define|#
directive|define
name|E1000_82580_PHY_POWER_MGMT
value|0xE14
end_define

begin_define
define|#
directive|define
name|E1000_82580_PM_SPD
value|0x0001
end_define

begin_comment
comment|/* Smart Power Down */
end_comment

begin_define
define|#
directive|define
name|E1000_82580_PM_D0_LPLU
value|0x0002
end_define

begin_comment
comment|/* For D0a states */
end_comment

begin_define
define|#
directive|define
name|E1000_82580_PM_D3_LPLU
value|0x0004
end_define

begin_comment
comment|/* For all other states */
end_comment

begin_define
define|#
directive|define
name|E1000_82580_PM_GO_LINKD
value|0x0020
end_define

begin_comment
comment|/* Go Link Disconnect */
end_comment

begin_define
define|#
directive|define
name|E1000_MPHY_DIS_ACCESS
value|0x80000000
end_define

begin_comment
comment|/* disable_access bit */
end_comment

begin_define
define|#
directive|define
name|E1000_MPHY_ENA_ACCESS
value|0x40000000
end_define

begin_comment
comment|/* enable_access bit */
end_comment

begin_define
define|#
directive|define
name|E1000_MPHY_BUSY
value|0x00010000
end_define

begin_comment
comment|/* busy bit */
end_comment

begin_define
define|#
directive|define
name|E1000_MPHY_ADDRESS_FNC_OVERRIDE
value|0x20000000
end_define

begin_comment
comment|/* fnc_override bit */
end_comment

begin_define
define|#
directive|define
name|E1000_MPHY_ADDRESS_MASK
value|0x0000FFFF
end_define

begin_comment
comment|/* address mask */
end_comment

begin_comment
comment|/* BM PHY Copper Specific Control 1 */
end_comment

begin_define
define|#
directive|define
name|BM_CS_CTRL1
value|16
end_define

begin_comment
comment|/* BM PHY Copper Specific Status */
end_comment

begin_define
define|#
directive|define
name|BM_CS_STATUS
value|17
end_define

begin_define
define|#
directive|define
name|BM_CS_STATUS_LINK_UP
value|0x0400
end_define

begin_define
define|#
directive|define
name|BM_CS_STATUS_RESOLVED
value|0x0800
end_define

begin_define
define|#
directive|define
name|BM_CS_STATUS_SPEED_MASK
value|0xC000
end_define

begin_define
define|#
directive|define
name|BM_CS_STATUS_SPEED_1000
value|0x8000
end_define

begin_comment
comment|/* 82577 Mobile Phy Status Register */
end_comment

begin_define
define|#
directive|define
name|HV_M_STATUS
value|26
end_define

begin_define
define|#
directive|define
name|HV_M_STATUS_AUTONEG_COMPLETE
value|0x1000
end_define

begin_define
define|#
directive|define
name|HV_M_STATUS_SPEED_MASK
value|0x0300
end_define

begin_define
define|#
directive|define
name|HV_M_STATUS_SPEED_1000
value|0x0200
end_define

begin_define
define|#
directive|define
name|HV_M_STATUS_SPEED_100
value|0x0100
end_define

begin_define
define|#
directive|define
name|HV_M_STATUS_LINK_UP
value|0x0040
end_define

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

begin_comment
comment|/* Enable flexible speed on link-up */
end_comment

begin_define
define|#
directive|define
name|IGP01E1000_GMII_FLEX_SPD
value|0x0010
end_define

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
value|0x0800
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
comment|/* Course=15:13, Fine=12:9 */
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
name|E1000_KMRNCTRLSTA_CTRL_OFFSET
value|0x1
end_define

begin_comment
comment|/* Kumeran Control */
end_comment

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
name|E1000_KMRNCTRLSTA_TIMEOUTS
value|0x4
end_define

begin_comment
comment|/* Kumeran Timeouts */
end_comment

begin_define
define|#
directive|define
name|E1000_KMRNCTRLSTA_INBAND_PARAM
value|0x9
end_define

begin_comment
comment|/* Kumeran InBand Parameters */
end_comment

begin_define
define|#
directive|define
name|E1000_KMRNCTRLSTA_IBIST_DISABLE
value|0x0200
end_define

begin_comment
comment|/* Kumeran IBIST Disable */
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
name|E1000_KMRNCTRLSTA_K1_CONFIG
value|0x7
end_define

begin_define
define|#
directive|define
name|E1000_KMRNCTRLSTA_K1_ENABLE
value|0x0002
end_define

begin_comment
comment|/* enable K1 */
end_comment

begin_define
define|#
directive|define
name|E1000_KMRNCTRLSTA_HD_CTRL
value|0x10
end_define

begin_comment
comment|/* Kumeran HD Control */
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
comment|/* 100BaseTx PHY Special Ctrl */
end_comment

begin_define
define|#
directive|define
name|IFE_PHY_SPECIAL_CONTROL_LED
value|0x1B
end_define

begin_comment
comment|/* PHY Special and LED Ctrl */
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
comment|/* 1=enable auto, 0=disable */
end_comment

begin_comment
comment|/* SFP modules ID memory locations */
end_comment

begin_define
define|#
directive|define
name|E1000_SFF_IDENTIFIER_OFFSET
value|0x00
end_define

begin_define
define|#
directive|define
name|E1000_SFF_IDENTIFIER_SFF
value|0x02
end_define

begin_define
define|#
directive|define
name|E1000_SFF_IDENTIFIER_SFP
value|0x03
end_define

begin_define
define|#
directive|define
name|E1000_SFF_ETH_FLAGS_OFFSET
value|0x06
end_define

begin_comment
comment|/* Flags for SFP modules compatible with ETH up to 1Gb */
end_comment

begin_struct
struct|struct
name|sfp_e1000_flags
block|{
name|u8
name|e1000_base_sx
range|:
literal|1
decl_stmt|;
name|u8
name|e1000_base_lx
range|:
literal|1
decl_stmt|;
name|u8
name|e1000_base_cx
range|:
literal|1
decl_stmt|;
name|u8
name|e1000_base_t
range|:
literal|1
decl_stmt|;
name|u8
name|e100_base_lx
range|:
literal|1
decl_stmt|;
name|u8
name|e100_base_fx
range|:
literal|1
decl_stmt|;
name|u8
name|e10_base_bx10
range|:
literal|1
decl_stmt|;
name|u8
name|e10_base_px
range|:
literal|1
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Vendor OUIs: format of OUI is 0x[byte0][byte1][byte2][00] */
end_comment

begin_define
define|#
directive|define
name|E1000_SFF_VENDOR_OUI_TYCO
value|0x00407600
end_define

begin_define
define|#
directive|define
name|E1000_SFF_VENDOR_OUI_FTL
value|0x00906500
end_define

begin_define
define|#
directive|define
name|E1000_SFF_VENDOR_OUI_AVAGO
value|0x00176A00
end_define

begin_define
define|#
directive|define
name|E1000_SFF_VENDOR_OUI_INTEL
value|0x001B2100
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

