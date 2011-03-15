begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2007-2010 Broadcom Corporation. All rights reserved.  *  *    Gary Zambrano<zambrano@broadcom.com>  *    David Christensen<davidch@broadcom.com>  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of Broadcom Corporation nor the name of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written consent.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS'  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*$FreeBSD$*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BXE_LINK_H
end_ifndef

begin_define
define|#
directive|define
name|BXE_LINK_H
end_define

begin_comment
comment|/*  * Defines  */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_PHY_DEV_ADDR
value|3
end_define

begin_define
define|#
directive|define
name|FLOW_CTRL_AUTO
value|PORT_FEATURE_FLOW_CONTROL_AUTO
end_define

begin_define
define|#
directive|define
name|FLOW_CTRL_TX
value|PORT_FEATURE_FLOW_CONTROL_TX
end_define

begin_define
define|#
directive|define
name|FLOW_CTRL_RX
value|PORT_FEATURE_FLOW_CONTROL_RX
end_define

begin_define
define|#
directive|define
name|FLOW_CTRL_BOTH
value|PORT_FEATURE_FLOW_CONTROL_BOTH
end_define

begin_define
define|#
directive|define
name|FLOW_CTRL_NONE
value|PORT_FEATURE_FLOW_CONTROL_NONE
end_define

begin_define
define|#
directive|define
name|SPEED_AUTO_NEG
value|0
end_define

begin_define
define|#
directive|define
name|SPEED_12000
value|12000
end_define

begin_define
define|#
directive|define
name|SPEED_12500
value|12500
end_define

begin_define
define|#
directive|define
name|SPEED_13000
value|13000
end_define

begin_define
define|#
directive|define
name|SPEED_15000
value|15000
end_define

begin_define
define|#
directive|define
name|SPEED_16000
value|16000
end_define

begin_define
define|#
directive|define
name|SFP_EEPROM_VENDOR_NAME_ADDR
value|0x14
end_define

begin_define
define|#
directive|define
name|SFP_EEPROM_VENDOR_NAME_SIZE
value|16
end_define

begin_define
define|#
directive|define
name|SFP_EEPROM_VENDOR_OUI_ADDR
value|0x25
end_define

begin_define
define|#
directive|define
name|SFP_EEPROM_VENDOR_OUI_SIZE
value|3
end_define

begin_define
define|#
directive|define
name|SFP_EEPROM_PART_NO_ADDR
value|0x28
end_define

begin_define
define|#
directive|define
name|SFP_EEPROM_PART_NO_SIZE
value|16
end_define

begin_define
define|#
directive|define
name|PWR_FLT_ERR_MSG_LEN
value|250
end_define

begin_comment
comment|/*  * Structs  */
end_comment

begin_comment
comment|/* Inputs parameters to the CLC. */
end_comment

begin_struct
struct|struct
name|link_params
block|{
name|uint8_t
name|port
decl_stmt|;
comment|/* Default / User Configuration */
name|uint8_t
name|loopback_mode
decl_stmt|;
define|#
directive|define
name|LOOPBACK_NONE
value|0
define|#
directive|define
name|LOOPBACK_EMAC
value|1
define|#
directive|define
name|LOOPBACK_BMAC
value|2
define|#
directive|define
name|LOOPBACK_XGXS_10
value|3
define|#
directive|define
name|LOOPBACK_EXT_PHY
value|4
define|#
directive|define
name|LOOPBACK_EXT
value|5
name|uint16_t
name|req_duplex
decl_stmt|;
name|uint16_t
name|req_flow_ctrl
decl_stmt|;
comment|/* Should be set to TX / BOTH when req_flow_ctrl is set to AUTO. */
name|uint16_t
name|req_fc_auto_adv
decl_stmt|;
comment|/* Also determine AutoNeg. */
name|uint16_t
name|req_line_speed
decl_stmt|;
comment|/* Device parameters */
name|uint8_t
name|mac_addr
index|[
literal|6
index|]
decl_stmt|;
comment|/* shmem parameters */
name|uint32_t
name|shmem_base
decl_stmt|;
name|uint32_t
name|speed_cap_mask
decl_stmt|;
name|uint32_t
name|switch_cfg
decl_stmt|;
define|#
directive|define
name|SWITCH_CFG_1G
value|PORT_FEATURE_CON_SWITCH_1G_SWITCH
define|#
directive|define
name|SWITCH_CFG_10G
value|PORT_FEATURE_CON_SWITCH_10G_SWITCH
define|#
directive|define
name|SWITCH_CFG_AUTO_DETECT
value|PORT_FEATURE_CON_SWITCH_AUTO_DETECT
comment|/* Part of the hw_config read from the shmem. */
name|uint16_t
name|hw_led_mode
decl_stmt|;
comment|/* phy_addr populated by the CLC. */
name|uint8_t
name|phy_addr
decl_stmt|;
comment|/* uint8_t reserved1; */
name|uint32_t
name|lane_config
decl_stmt|;
name|uint32_t
name|ext_phy_config
decl_stmt|;
define|#
directive|define
name|XGXS_EXT_PHY_TYPE
parameter_list|(
name|ext_phy_config
parameter_list|)
define|\
value|((ext_phy_config)& PORT_HW_CFG_XGXS_EXT_PHY_TYPE_MASK)
define|#
directive|define
name|XGXS_EXT_PHY_ADDR
parameter_list|(
name|ext_phy_config
parameter_list|)
define|\
value|(((ext_phy_config)& PORT_HW_CFG_XGXS_EXT_PHY_ADDR_MASK)>>	\ 	    PORT_HW_CFG_XGXS_EXT_PHY_ADDR_SHIFT)
define|#
directive|define
name|SERDES_EXT_PHY_TYPE
parameter_list|(
name|ext_phy_config
parameter_list|)
define|\
value|((ext_phy_config)& PORT_HW_CFG_SERDES_EXT_PHY_TYPE_MASK)
comment|/* Phy register parameter */
name|uint32_t
name|chip_id
decl_stmt|;
name|uint16_t
name|xgxs_config_rx
index|[
literal|4
index|]
decl_stmt|;
comment|/* preemphasis values for the rx side */
name|uint16_t
name|xgxs_config_tx
index|[
literal|4
index|]
decl_stmt|;
comment|/* preemphasis values for the tx side */
name|uint32_t
name|feature_config_flags
decl_stmt|;
define|#
directive|define
name|FEATURE_CONFIG_OVERRIDE_PREEMPHASIS_ENABLED
value|(1<<0)
define|#
directive|define
name|FEATURE_CONFIG_PFC_ENABLED
value|(1<<1)
define|#
directive|define
name|FEATURE_CONFIG_BC_SUPPORTS_OPT_MDL_VRFY
value|(1<<2)
define|#
directive|define
name|FEATURE_CONFIG_BCM8727_NOC
value|(1<<3)
comment|/* Device pointer passed to all callback functions. */
name|struct
name|bxe_softc
modifier|*
name|sc
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Output parameters */
end_comment

begin_struct
struct|struct
name|link_vars
block|{
name|uint8_t
name|phy_flags
decl_stmt|;
name|uint8_t
name|mac_type
decl_stmt|;
define|#
directive|define
name|MAC_TYPE_NONE
value|0
define|#
directive|define
name|MAC_TYPE_EMAC
value|1
define|#
directive|define
name|MAC_TYPE_BMAC
value|2
comment|/* Internal phy link indication. */
name|uint8_t
name|phy_link_up
decl_stmt|;
name|uint8_t
name|link_up
decl_stmt|;
name|uint16_t
name|line_speed
decl_stmt|;
name|uint16_t
name|duplex
decl_stmt|;
name|uint16_t
name|flow_ctrl
decl_stmt|;
name|uint16_t
name|ieee_fc
decl_stmt|;
name|uint32_t
name|autoneg
decl_stmt|;
define|#
directive|define
name|AUTO_NEG_DISABLED
value|0x0
define|#
directive|define
name|AUTO_NEG_ENABLED
value|0x1
define|#
directive|define
name|AUTO_NEG_COMPLETE
value|0x2
define|#
directive|define
name|AUTO_NEG_PARALLEL_DETECTION_USED
value|0x4
comment|/* The same definitions as the shmem parameter. */
name|uint32_t
name|link_status
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Functions  */
end_comment

begin_comment
comment|/* Initialize the phy. */
end_comment

begin_function_decl
name|uint8_t
name|bxe_phy_init
parameter_list|(
name|struct
name|link_params
modifier|*
name|input
parameter_list|,
name|struct
name|link_vars
modifier|*
name|output
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Reset the link. Should be called when driver or interface goes down  * Before calling phy firmware upgrade, the reset_ext_phy should be set  * to 0.  */
end_comment

begin_function_decl
name|uint8_t
name|bxe_link_reset
parameter_list|(
name|struct
name|link_params
modifier|*
name|params
parameter_list|,
name|struct
name|link_vars
modifier|*
name|vars
parameter_list|,
name|uint8_t
name|reset_ext_phy
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* bxe_link_update should be called upon link interrupt */
end_comment

begin_function_decl
name|uint8_t
name|bxe_link_update
parameter_list|(
name|struct
name|link_params
modifier|*
name|input
parameter_list|,
name|struct
name|link_vars
modifier|*
name|output
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Use the following cl45 functions to read/write from external_phy  * In order to use it to read/write internal phy registers, use  * DEFAULT_PHY_DEV_ADDR as devad, and (_bank + (_addr& 0xf)) as  * Use ext_phy_type of 0 in case of cl22 over cl45  * the register.  */
end_comment

begin_function_decl
name|uint8_t
name|bxe_cl45_read
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|uint8_t
name|port
parameter_list|,
name|uint32_t
name|ext_phy_type
parameter_list|,
name|uint8_t
name|phy_addr
parameter_list|,
name|uint8_t
name|devad
parameter_list|,
name|uint16_t
name|reg
parameter_list|,
name|uint16_t
modifier|*
name|ret_val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint8_t
name|bxe_cl45_write
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|uint8_t
name|port
parameter_list|,
name|uint32_t
name|ext_phy_type
parameter_list|,
name|uint8_t
name|phy_addr
parameter_list|,
name|uint8_t
name|devad
parameter_list|,
name|uint16_t
name|reg
parameter_list|,
name|uint16_t
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Reads the link_status from the shmem, and update the link vars accordingly.  */
end_comment

begin_function_decl
name|void
name|bxe_link_status_update
parameter_list|(
name|struct
name|link_params
modifier|*
name|input
parameter_list|,
name|struct
name|link_vars
modifier|*
name|output
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Returns string representing the fw_version of the external phy. */
end_comment

begin_function_decl
name|uint8_t
name|bxe_get_ext_phy_fw_version
parameter_list|(
name|struct
name|link_params
modifier|*
name|params
parameter_list|,
name|uint8_t
name|driver_loaded
parameter_list|,
name|uint8_t
modifier|*
name|version
parameter_list|,
name|uint16_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Set/Unset the led  * Basically, the CLC takes care of the led for the link, but in case one needs  * to set/unset the led unnaturally, set the "mode" to LED_MODE_OPER to blink  * the led, and LED_MODE_OFF to set the led off.  */
end_comment

begin_function_decl
name|uint8_t
name|bxe_set_led
parameter_list|(
name|struct
name|link_params
modifier|*
name|params
parameter_list|,
name|uint8_t
name|mode
parameter_list|,
name|uint32_t
name|speed
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|LED_MODE_OFF
value|0
end_define

begin_define
define|#
directive|define
name|LED_MODE_OPER
value|2
end_define

begin_function_decl
name|uint8_t
name|bxe_override_led_value
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|uint8_t
name|port
parameter_list|,
name|uint32_t
name|led_idx
parameter_list|,
name|uint32_t
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * bxe_handle_module_detect_int should be called upon module detection  * interrupt.  */
end_comment

begin_function_decl
name|void
name|bxe_handle_module_detect_int
parameter_list|(
name|struct
name|link_params
modifier|*
name|params
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Get the actual link status. In case it returns 0, link is up, otherwise  * link is down.  */
end_comment

begin_function_decl
name|uint8_t
name|bxe_test_link
parameter_list|(
name|struct
name|link_params
modifier|*
name|input
parameter_list|,
name|struct
name|link_vars
modifier|*
name|vars
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* One-time initialization for external phy after power up. */
end_comment

begin_function_decl
name|uint8_t
name|bxe_common_init_phy
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|uint32_t
name|shmem_base
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Reset the external PHY using GPIO. */
end_comment

begin_function_decl
name|void
name|bxe_ext_phy_hw_reset
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|uint8_t
name|port
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bxe_sfx7101_sp_sw_reset
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|uint8_t
name|port
parameter_list|,
name|uint8_t
name|phy_addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint8_t
name|bxe_read_sfp_module_eeprom
parameter_list|(
name|struct
name|link_params
modifier|*
name|params
parameter_list|,
name|uint16_t
name|addr
parameter_list|,
name|uint8_t
name|byte_cnt
parameter_list|,
name|uint8_t
modifier|*
name|o_buf
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BXE_LINK_H */
end_comment

end_unit

