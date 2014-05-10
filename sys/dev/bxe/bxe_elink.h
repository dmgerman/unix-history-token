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
name|ELINK_H
end_ifndef

begin_define
define|#
directive|define
name|ELINK_H
end_define

begin_define
define|#
directive|define
name|ELINK_DEBUG
end_define

begin_comment
comment|/***********************************************************/
end_comment

begin_comment
comment|/*                  CLC Call backs functions               */
end_comment

begin_comment
comment|/***********************************************************/
end_comment

begin_comment
comment|/* CLC device structure */
end_comment

begin_struct_decl
struct_decl|struct
name|bxe_softc
struct_decl|;
end_struct_decl

begin_function_decl
specifier|extern
name|uint32_t
name|elink_cb_reg_read
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|uint32_t
name|reg_addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|elink_cb_reg_write
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|uint32_t
name|reg_addr
parameter_list|,
name|uint32_t
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* wb_write - pointer to 2 32 bits vars to be passed to the DMAE*/
end_comment

begin_function_decl
specifier|extern
name|void
name|elink_cb_reg_wb_write
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|uint32_t
name|offset
parameter_list|,
name|uint32_t
modifier|*
name|wb_write
parameter_list|,
name|uint16_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|elink_cb_reg_wb_read
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|uint32_t
name|offset
parameter_list|,
name|uint32_t
modifier|*
name|wb_write
parameter_list|,
name|uint16_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* mode - 0( LOW ) /1(HIGH)*/
end_comment

begin_function_decl
specifier|extern
name|uint8_t
name|elink_cb_gpio_write
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|uint16_t
name|gpio_num
parameter_list|,
name|uint8_t
name|mode
parameter_list|,
name|uint8_t
name|port
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint8_t
name|elink_cb_gpio_mult_write
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|uint8_t
name|pins
parameter_list|,
name|uint8_t
name|mode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint32_t
name|elink_cb_gpio_read
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|uint16_t
name|gpio_num
parameter_list|,
name|uint8_t
name|port
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint8_t
name|elink_cb_gpio_int_write
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|uint16_t
name|gpio_num
parameter_list|,
name|uint8_t
name|mode
parameter_list|,
name|uint8_t
name|port
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint32_t
name|elink_cb_fw_command
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|uint32_t
name|command
parameter_list|,
name|uint32_t
name|param
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Delay */
end_comment

begin_function_decl
specifier|extern
name|void
name|elink_cb_udelay
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|uint32_t
name|microsecond
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* This function is called every 1024 bytes downloading of phy firmware. Driver can use it to print to screen indication for download progress */
end_comment

begin_function_decl
specifier|extern
name|void
name|elink_cb_download_progress
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|uint32_t
name|cur
parameter_list|,
name|uint32_t
name|total
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Each log type has its own parameters */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|elink_log_id
block|{
name|ELINK_LOG_ID_UNQUAL_IO_MODULE
init|=
literal|0
block|,
comment|/* uint8_t port, const char* vendor_name, const char* vendor_pn */
name|ELINK_LOG_ID_OVER_CURRENT
init|=
literal|1
block|,
comment|/* uint8_t port */
name|ELINK_LOG_ID_PHY_UNINITIALIZED
init|=
literal|2
block|,
comment|/* uint8_t port */
name|ELINK_LOG_ID_MDIO_ACCESS_TIMEOUT
init|=
literal|3
block|,
comment|/* No params */
name|ELINK_LOG_ID_NON_10G_MODULE
init|=
literal|4
block|,
comment|/* uint8_t port */
block|}
name|elink_log_id_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
name|elink_status
block|{
name|ELINK_STATUS_OK
init|=
literal|0
block|,
name|ELINK_STATUS_ERROR
block|,
name|ELINK_STATUS_TIMEOUT
block|,
name|ELINK_STATUS_NO_LINK
block|,
name|ELINK_STATUS_INVALID_IMAGE
block|,
name|ELINK_OP_NOT_SUPPORTED
init|=
literal|122
block|}
name|elink_status_t
typedef|;
end_typedef

begin_function_decl
specifier|extern
name|void
name|elink_cb_event_log
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
specifier|const
name|elink_log_id_t
name|log_id
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|elink_cb_load_warpcore_microcode
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint8_t
name|elink_cb_path_id
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|elink_cb_notify_link_changed
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ELINK_EVENT_LOG_LEVEL_ERROR
value|1
end_define

begin_define
define|#
directive|define
name|ELINK_EVENT_LOG_LEVEL_WARNING
value|2
end_define

begin_define
define|#
directive|define
name|ELINK_EVENT_ID_SFP_UNQUALIFIED_MODULE
value|1
end_define

begin_define
define|#
directive|define
name|ELINK_EVENT_ID_SFP_POWER_FAULT
value|2
end_define

begin_define
define|#
directive|define
name|ARRAY_SIZE
parameter_list|(
name|x
parameter_list|)
value|(sizeof(x)/sizeof(x[0]))
end_define

begin_comment
comment|/* Debug prints */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ELINK_DEBUG
end_ifdef

begin_function_decl
specifier|extern
name|void
name|elink_cb_dbg
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|char
modifier|*
name|fmt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|elink_cb_dbg1
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|char
modifier|*
name|fmt
parameter_list|,
name|uint32_t
name|arg1
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|elink_cb_dbg2
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|char
modifier|*
name|fmt
parameter_list|,
name|uint32_t
name|arg1
parameter_list|,
name|uint32_t
name|arg2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|elink_cb_dbg3
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|char
modifier|*
name|fmt
parameter_list|,
name|uint32_t
name|arg1
parameter_list|,
name|uint32_t
name|arg2
parameter_list|,
name|uint32_t
name|arg3
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ELINK_DEBUG_P0
parameter_list|(
name|sc
parameter_list|,
name|fmt
parameter_list|)
value|elink_cb_dbg(sc, fmt)
end_define

begin_define
define|#
directive|define
name|ELINK_DEBUG_P1
parameter_list|(
name|sc
parameter_list|,
name|fmt
parameter_list|,
name|arg1
parameter_list|)
value|elink_cb_dbg1(sc, fmt, arg1)
end_define

begin_define
define|#
directive|define
name|ELINK_DEBUG_P2
parameter_list|(
name|sc
parameter_list|,
name|fmt
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|)
value|elink_cb_dbg2(sc, fmt, arg1, arg2)
end_define

begin_define
define|#
directive|define
name|ELINK_DEBUG_P3
parameter_list|(
name|sc
parameter_list|,
name|fmt
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|)
define|\
value|elink_cb_dbg3(sc, fmt, arg1, arg2, arg3)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ELINK_DEBUG_P0
parameter_list|(
name|sc
parameter_list|,
name|fmt
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ELINK_DEBUG_P1
parameter_list|(
name|sc
parameter_list|,
name|fmt
parameter_list|,
name|arg1
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ELINK_DEBUG_P2
parameter_list|(
name|sc
parameter_list|,
name|fmt
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ELINK_DEBUG_P3
parameter_list|(
name|sc
parameter_list|,
name|fmt
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/***********************************************************/
end_comment

begin_comment
comment|/*                         Defines                         */
end_comment

begin_comment
comment|/***********************************************************/
end_comment

begin_define
define|#
directive|define
name|ELINK_DEFAULT_PHY_DEV_ADDR
value|3
end_define

begin_define
define|#
directive|define
name|ELINK_E2_DEFAULT_PHY_DEV_ADDR
value|5
end_define

begin_define
define|#
directive|define
name|DUPLEX_FULL
value|1
end_define

begin_define
define|#
directive|define
name|DUPLEX_HALF
value|2
end_define

begin_define
define|#
directive|define
name|ELINK_FLOW_CTRL_AUTO
value|PORT_FEATURE_FLOW_CONTROL_AUTO
end_define

begin_define
define|#
directive|define
name|ELINK_FLOW_CTRL_TX
value|PORT_FEATURE_FLOW_CONTROL_TX
end_define

begin_define
define|#
directive|define
name|ELINK_FLOW_CTRL_RX
value|PORT_FEATURE_FLOW_CONTROL_RX
end_define

begin_define
define|#
directive|define
name|ELINK_FLOW_CTRL_BOTH
value|PORT_FEATURE_FLOW_CONTROL_BOTH
end_define

begin_define
define|#
directive|define
name|ELINK_FLOW_CTRL_NONE
value|PORT_FEATURE_FLOW_CONTROL_NONE
end_define

begin_define
define|#
directive|define
name|ELINK_NET_SERDES_IF_XFI
value|1
end_define

begin_define
define|#
directive|define
name|ELINK_NET_SERDES_IF_SFI
value|2
end_define

begin_define
define|#
directive|define
name|ELINK_NET_SERDES_IF_KR
value|3
end_define

begin_define
define|#
directive|define
name|ELINK_NET_SERDES_IF_DXGXS
value|4
end_define

begin_define
define|#
directive|define
name|ELINK_SPEED_AUTO_NEG
value|0
end_define

begin_define
define|#
directive|define
name|ELINK_SPEED_10
value|10
end_define

begin_define
define|#
directive|define
name|ELINK_SPEED_100
value|100
end_define

begin_define
define|#
directive|define
name|ELINK_SPEED_1000
value|1000
end_define

begin_define
define|#
directive|define
name|ELINK_SPEED_2500
value|2500
end_define

begin_define
define|#
directive|define
name|ELINK_SPEED_10000
value|10000
end_define

begin_define
define|#
directive|define
name|ELINK_SPEED_20000
value|20000
end_define

begin_define
define|#
directive|define
name|ELINK_I2C_DEV_ADDR_A0
value|0xa0
end_define

begin_define
define|#
directive|define
name|ELINK_I2C_DEV_ADDR_A2
value|0xa2
end_define

begin_define
define|#
directive|define
name|ELINK_SFP_EEPROM_PAGE_SIZE
value|16
end_define

begin_define
define|#
directive|define
name|ELINK_SFP_EEPROM_VENDOR_NAME_ADDR
value|0x14
end_define

begin_define
define|#
directive|define
name|ELINK_SFP_EEPROM_VENDOR_NAME_SIZE
value|16
end_define

begin_define
define|#
directive|define
name|ELINK_SFP_EEPROM_VENDOR_OUI_ADDR
value|0x25
end_define

begin_define
define|#
directive|define
name|ELINK_SFP_EEPROM_VENDOR_OUI_SIZE
value|3
end_define

begin_define
define|#
directive|define
name|ELINK_SFP_EEPROM_PART_NO_ADDR
value|0x28
end_define

begin_define
define|#
directive|define
name|ELINK_SFP_EEPROM_PART_NO_SIZE
value|16
end_define

begin_define
define|#
directive|define
name|ELINK_SFP_EEPROM_REVISION_ADDR
value|0x38
end_define

begin_define
define|#
directive|define
name|ELINK_SFP_EEPROM_REVISION_SIZE
value|4
end_define

begin_define
define|#
directive|define
name|ELINK_SFP_EEPROM_SERIAL_ADDR
value|0x44
end_define

begin_define
define|#
directive|define
name|ELINK_SFP_EEPROM_SERIAL_SIZE
value|16
end_define

begin_define
define|#
directive|define
name|ELINK_SFP_EEPROM_DATE_ADDR
value|0x54
end_define

begin_comment
comment|/* ASCII YYMMDD */
end_comment

begin_define
define|#
directive|define
name|ELINK_SFP_EEPROM_DATE_SIZE
value|6
end_define

begin_define
define|#
directive|define
name|ELINK_SFP_EEPROM_DIAG_TYPE_ADDR
value|0x5c
end_define

begin_define
define|#
directive|define
name|ELINK_SFP_EEPROM_DIAG_TYPE_SIZE
value|1
end_define

begin_define
define|#
directive|define
name|ELINK_SFP_EEPROM_DIAG_ADDR_CHANGE_REQ
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|ELINK_SFP_EEPROM_SFF_8472_COMP_ADDR
value|0x5e
end_define

begin_define
define|#
directive|define
name|ELINK_SFP_EEPROM_SFF_8472_COMP_SIZE
value|1
end_define

begin_define
define|#
directive|define
name|ELINK_SFP_EEPROM_A2_CHECKSUM_RANGE
value|0x5e
end_define

begin_define
define|#
directive|define
name|ELINK_SFP_EEPROM_A2_CC_DMI_ADDR
value|0x5f
end_define

begin_define
define|#
directive|define
name|ELINK_PWR_FLT_ERR_MSG_LEN
value|250
end_define

begin_define
define|#
directive|define
name|ELINK_XGXS_EXT_PHY_TYPE
parameter_list|(
name|ext_phy_config
parameter_list|)
define|\
value|((ext_phy_config)& PORT_HW_CFG_XGXS_EXT_PHY_TYPE_MASK)
end_define

begin_define
define|#
directive|define
name|ELINK_XGXS_EXT_PHY_ADDR
parameter_list|(
name|ext_phy_config
parameter_list|)
define|\
value|(((ext_phy_config)& PORT_HW_CFG_XGXS_EXT_PHY_ADDR_MASK)>> \ 		 PORT_HW_CFG_XGXS_EXT_PHY_ADDR_SHIFT)
end_define

begin_define
define|#
directive|define
name|ELINK_SERDES_EXT_PHY_TYPE
parameter_list|(
name|ext_phy_config
parameter_list|)
define|\
value|((ext_phy_config)& PORT_HW_CFG_SERDES_EXT_PHY_TYPE_MASK)
end_define

begin_comment
comment|/* Single Media Direct board is the plain 577xx board with CX4/RJ45 jacks */
end_comment

begin_define
define|#
directive|define
name|ELINK_SINGLE_MEDIA_DIRECT
parameter_list|(
name|params
parameter_list|)
value|(params->num_phys == 1)
end_define

begin_comment
comment|/* Single Media board contains single external phy */
end_comment

begin_define
define|#
directive|define
name|ELINK_SINGLE_MEDIA
parameter_list|(
name|params
parameter_list|)
value|(params->num_phys == 2)
end_define

begin_comment
comment|/* Dual Media board contains two external phy with different media */
end_comment

begin_define
define|#
directive|define
name|ELINK_DUAL_MEDIA
parameter_list|(
name|params
parameter_list|)
value|(params->num_phys == 3)
end_define

begin_define
define|#
directive|define
name|ELINK_FW_PARAM_PHY_ADDR_MASK
value|0x000000FF
end_define

begin_define
define|#
directive|define
name|ELINK_FW_PARAM_PHY_TYPE_MASK
value|0x0000FF00
end_define

begin_define
define|#
directive|define
name|ELINK_FW_PARAM_MDIO_CTRL_MASK
value|0xFFFF0000
end_define

begin_define
define|#
directive|define
name|ELINK_FW_PARAM_MDIO_CTRL_OFFSET
value|16
end_define

begin_define
define|#
directive|define
name|ELINK_FW_PARAM_PHY_ADDR
parameter_list|(
name|fw_param
parameter_list|)
value|(fw_param& \ 					   ELINK_FW_PARAM_PHY_ADDR_MASK)
end_define

begin_define
define|#
directive|define
name|ELINK_FW_PARAM_PHY_TYPE
parameter_list|(
name|fw_param
parameter_list|)
value|(fw_param& \ 					   ELINK_FW_PARAM_PHY_TYPE_MASK)
end_define

begin_define
define|#
directive|define
name|ELINK_FW_PARAM_MDIO_CTRL
parameter_list|(
name|fw_param
parameter_list|)
value|((fw_param& \ 					    ELINK_FW_PARAM_MDIO_CTRL_MASK)>> \ 					    ELINK_FW_PARAM_MDIO_CTRL_OFFSET)
end_define

begin_define
define|#
directive|define
name|ELINK_FW_PARAM_SET
parameter_list|(
name|phy_addr
parameter_list|,
name|phy_type
parameter_list|,
name|mdio_access
parameter_list|)
define|\
value|(phy_addr | phy_type | mdio_access<< ELINK_FW_PARAM_MDIO_CTRL_OFFSET)
end_define

begin_define
define|#
directive|define
name|ELINK_PFC_BRB_FULL_LB_XOFF_THRESHOLD
value|170
end_define

begin_define
define|#
directive|define
name|ELINK_PFC_BRB_FULL_LB_XON_THRESHOLD
value|250
end_define

begin_define
define|#
directive|define
name|ELINK_MAXVAL
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(((a)> (b)) ? (a) : (b))
end_define

begin_define
define|#
directive|define
name|ELINK_BMAC_CONTROL_RX_ENABLE
value|2
end_define

begin_comment
comment|/***********************************************************/
end_comment

begin_comment
comment|/*                         Structs                         */
end_comment

begin_comment
comment|/***********************************************************/
end_comment

begin_define
define|#
directive|define
name|ELINK_INT_PHY
value|0
end_define

begin_define
define|#
directive|define
name|ELINK_EXT_PHY1
value|1
end_define

begin_define
define|#
directive|define
name|ELINK_EXT_PHY2
value|2
end_define

begin_define
define|#
directive|define
name|ELINK_MAX_PHYS
value|3
end_define

begin_comment
comment|/* Same configuration is shared between the XGXS and the first external phy */
end_comment

begin_define
define|#
directive|define
name|ELINK_LINK_CONFIG_SIZE
value|(ELINK_MAX_PHYS - 1)
end_define

begin_define
define|#
directive|define
name|ELINK_LINK_CONFIG_IDX
parameter_list|(
name|_phy_idx
parameter_list|)
value|((_phy_idx == ELINK_INT_PHY) ? \ 					 0 : (_phy_idx - 1))
end_define

begin_comment
comment|/***********************************************************/
end_comment

begin_comment
comment|/*                      elink_phy struct                   */
end_comment

begin_comment
comment|/*  Defines the required arguments and function per phy    */
end_comment

begin_comment
comment|/***********************************************************/
end_comment

begin_struct_decl
struct_decl|struct
name|elink_vars
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|elink_params
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|elink_phy
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|uint8_t
function_decl|(
modifier|*
name|config_init_t
function_decl|)
parameter_list|(
name|struct
name|elink_phy
modifier|*
name|phy
parameter_list|,
name|struct
name|elink_params
modifier|*
name|params
parameter_list|,
name|struct
name|elink_vars
modifier|*
name|vars
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|uint8_t
function_decl|(
modifier|*
name|read_status_t
function_decl|)
parameter_list|(
name|struct
name|elink_phy
modifier|*
name|phy
parameter_list|,
name|struct
name|elink_params
modifier|*
name|params
parameter_list|,
name|struct
name|elink_vars
modifier|*
name|vars
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|link_reset_t
function_decl|)
parameter_list|(
name|struct
name|elink_phy
modifier|*
name|phy
parameter_list|,
name|struct
name|elink_params
modifier|*
name|params
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|config_loopback_t
function_decl|)
parameter_list|(
name|struct
name|elink_phy
modifier|*
name|phy
parameter_list|,
name|struct
name|elink_params
modifier|*
name|params
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|uint8_t
function_decl|(
modifier|*
name|format_fw_ver_t
function_decl|)
parameter_list|(
name|uint32_t
name|raw
parameter_list|,
name|uint8_t
modifier|*
name|str
parameter_list|,
name|uint16_t
modifier|*
name|len
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|hw_reset_t
function_decl|)
parameter_list|(
name|struct
name|elink_phy
modifier|*
name|phy
parameter_list|,
name|struct
name|elink_params
modifier|*
name|params
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|set_link_led_t
function_decl|)
parameter_list|(
name|struct
name|elink_phy
modifier|*
name|phy
parameter_list|,
name|struct
name|elink_params
modifier|*
name|params
parameter_list|,
name|uint8_t
name|mode
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|phy_specific_func_t
function_decl|)
parameter_list|(
name|struct
name|elink_phy
modifier|*
name|phy
parameter_list|,
name|struct
name|elink_params
modifier|*
name|params
parameter_list|,
name|uint32_t
name|action
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|elink_reg_set
block|{
name|uint8_t
name|devad
decl_stmt|;
name|uint16_t
name|reg
decl_stmt|;
name|uint16_t
name|val
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|elink_phy
block|{
name|uint32_t
name|type
decl_stmt|;
comment|/* Loaded during init */
name|uint8_t
name|addr
decl_stmt|;
name|uint8_t
name|def_md_devad
decl_stmt|;
name|uint16_t
name|flags
decl_stmt|;
comment|/* No Over-Current detection */
define|#
directive|define
name|ELINK_FLAGS_NOC
value|(1<<1)
comment|/* Fan failure detection required */
define|#
directive|define
name|ELINK_FLAGS_FAN_FAILURE_DET_REQ
value|(1<<2)
comment|/* Initialize first the XGXS and only then the phy itself */
define|#
directive|define
name|ELINK_FLAGS_INIT_XGXS_FIRST
value|(1<<3)
define|#
directive|define
name|ELINK_FLAGS_WC_DUAL_MODE
value|(1<<4)
define|#
directive|define
name|ELINK_FLAGS_4_PORT_MODE
value|(1<<5)
define|#
directive|define
name|ELINK_FLAGS_REARM_LATCH_SIGNAL
value|(1<<6)
define|#
directive|define
name|ELINK_FLAGS_SFP_NOT_APPROVED
value|(1<<7)
define|#
directive|define
name|ELINK_FLAGS_MDC_MDIO_WA
value|(1<<8)
define|#
directive|define
name|ELINK_FLAGS_DUMMY_READ
value|(1<<9)
define|#
directive|define
name|ELINK_FLAGS_MDC_MDIO_WA_B0
value|(1<<10)
define|#
directive|define
name|ELINK_FLAGS_SFP_MODULE_PLUGGED_IN_WC
value|(1<<11)
define|#
directive|define
name|ELINK_FLAGS_TX_ERROR_CHECK
value|(1<<12)
define|#
directive|define
name|ELINK_FLAGS_EEE
value|(1<<13)
define|#
directive|define
name|ELINK_FLAGS_TEMPERATURE
value|(1<<14)
define|#
directive|define
name|ELINK_FLAGS_MDC_MDIO_WA_G
value|(1<<15)
comment|/* preemphasis values for the rx side */
name|uint16_t
name|rx_preemphasis
index|[
literal|4
index|]
decl_stmt|;
comment|/* preemphasis values for the tx side */
name|uint16_t
name|tx_preemphasis
index|[
literal|4
index|]
decl_stmt|;
comment|/* EMAC address for access MDIO */
name|uint32_t
name|mdio_ctrl
decl_stmt|;
name|uint32_t
name|supported
decl_stmt|;
define|#
directive|define
name|ELINK_SUPPORTED_10baseT_Half
value|(1<<0)
define|#
directive|define
name|ELINK_SUPPORTED_10baseT_Full
value|(1<<1)
define|#
directive|define
name|ELINK_SUPPORTED_100baseT_Half
value|(1<<2)
define|#
directive|define
name|ELINK_SUPPORTED_100baseT_Full
value|(1<<3)
define|#
directive|define
name|ELINK_SUPPORTED_1000baseT_Full
value|(1<<4)
define|#
directive|define
name|ELINK_SUPPORTED_2500baseX_Full
value|(1<<5)
define|#
directive|define
name|ELINK_SUPPORTED_10000baseT_Full
value|(1<<6)
define|#
directive|define
name|ELINK_SUPPORTED_TP
value|(1<<7)
define|#
directive|define
name|ELINK_SUPPORTED_FIBRE
value|(1<<8)
define|#
directive|define
name|ELINK_SUPPORTED_Autoneg
value|(1<<9)
define|#
directive|define
name|ELINK_SUPPORTED_Pause
value|(1<<10)
define|#
directive|define
name|ELINK_SUPPORTED_Asym_Pause
value|(1<<11)
define|#
directive|define
name|ELINK_SUPPORTED_20000baseMLD2_Full
value|(1<<21)
define|#
directive|define
name|ELINK_SUPPORTED_20000baseKR2_Full
value|(1<<22)
name|uint32_t
name|media_type
decl_stmt|;
define|#
directive|define
name|ELINK_ETH_PHY_UNSPECIFIED
value|0x0
define|#
directive|define
name|ELINK_ETH_PHY_SFPP_10G_FIBER
value|0x1
define|#
directive|define
name|ELINK_ETH_PHY_XFP_FIBER
value|0x2
define|#
directive|define
name|ELINK_ETH_PHY_DA_TWINAX
value|0x3
define|#
directive|define
name|ELINK_ETH_PHY_BASE_T
value|0x4
define|#
directive|define
name|ELINK_ETH_PHY_SFP_1G_FIBER
value|0x5
define|#
directive|define
name|ELINK_ETH_PHY_KR
value|0xf0
define|#
directive|define
name|ELINK_ETH_PHY_CX4
value|0xf1
define|#
directive|define
name|ELINK_ETH_PHY_NOT_PRESENT
value|0xff
comment|/* The address in which version is located*/
name|uint32_t
name|ver_addr
decl_stmt|;
name|uint16_t
name|req_flow_ctrl
decl_stmt|;
name|uint16_t
name|req_line_speed
decl_stmt|;
name|uint32_t
name|speed_cap_mask
decl_stmt|;
name|uint16_t
name|req_duplex
decl_stmt|;
name|uint16_t
name|rsrv
decl_stmt|;
comment|/* Called per phy/port init, and it configures LASI, speed, autoneg, 	 duplex, flow control negotiation, etc. */
name|config_init_t
name|config_init
decl_stmt|;
comment|/* Called due to interrupt. It determines the link, speed */
name|read_status_t
name|read_status
decl_stmt|;
comment|/* Called when driver is unloading. Should reset the phy */
name|link_reset_t
name|link_reset
decl_stmt|;
comment|/* Set the loopback configuration for the phy */
name|config_loopback_t
name|config_loopback
decl_stmt|;
comment|/* Format the given raw number into str up to len */
name|format_fw_ver_t
name|format_fw_ver
decl_stmt|;
comment|/* Reset the phy (both ports) */
name|hw_reset_t
name|hw_reset
decl_stmt|;
comment|/* Set link led mode (on/off/oper)*/
name|set_link_led_t
name|set_link_led
decl_stmt|;
comment|/* PHY Specific tasks */
name|phy_specific_func_t
name|phy_specific_func
decl_stmt|;
define|#
directive|define
name|ELINK_DISABLE_TX
value|1
define|#
directive|define
name|ELINK_ENABLE_TX
value|2
define|#
directive|define
name|ELINK_PHY_INIT
value|3
block|}
struct|;
end_struct

begin_comment
comment|/* Inputs parameters to the CLC */
end_comment

begin_struct
struct|struct
name|elink_params
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
name|ELINK_LOOPBACK_NONE
value|0
define|#
directive|define
name|ELINK_LOOPBACK_EMAC
value|1
define|#
directive|define
name|ELINK_LOOPBACK_BMAC
value|2
define|#
directive|define
name|ELINK_LOOPBACK_XGXS
value|3
define|#
directive|define
name|ELINK_LOOPBACK_EXT_PHY
value|4
define|#
directive|define
name|ELINK_LOOPBACK_EXT
value|5
define|#
directive|define
name|ELINK_LOOPBACK_UMAC
value|6
define|#
directive|define
name|ELINK_LOOPBACK_XMAC
value|7
comment|/* Device parameters */
name|uint8_t
name|mac_addr
index|[
literal|6
index|]
decl_stmt|;
name|uint16_t
name|req_duplex
index|[
name|ELINK_LINK_CONFIG_SIZE
index|]
decl_stmt|;
name|uint16_t
name|req_flow_ctrl
index|[
name|ELINK_LINK_CONFIG_SIZE
index|]
decl_stmt|;
name|uint16_t
name|req_line_speed
index|[
name|ELINK_LINK_CONFIG_SIZE
index|]
decl_stmt|;
comment|/* Also determine AutoNeg */
comment|/* shmem parameters */
name|uint32_t
name|shmem_base
decl_stmt|;
name|uint32_t
name|shmem2_base
decl_stmt|;
name|uint32_t
name|speed_cap_mask
index|[
name|ELINK_LINK_CONFIG_SIZE
index|]
decl_stmt|;
name|uint32_t
name|switch_cfg
decl_stmt|;
define|#
directive|define
name|ELINK_SWITCH_CFG_1G
value|PORT_FEATURE_CON_SWITCH_1G_SWITCH
define|#
directive|define
name|ELINK_SWITCH_CFG_10G
value|PORT_FEATURE_CON_SWITCH_10G_SWITCH
define|#
directive|define
name|ELINK_SWITCH_CFG_AUTO_DETECT
value|PORT_FEATURE_CON_SWITCH_AUTO_DETECT
name|uint32_t
name|lane_config
decl_stmt|;
comment|/* Phy register parameter */
name|uint32_t
name|chip_id
decl_stmt|;
comment|/* features */
name|uint32_t
name|feature_config_flags
decl_stmt|;
define|#
directive|define
name|ELINK_FEATURE_CONFIG_OVERRIDE_PREEMPHASIS_ENABLED
value|(1<<0)
define|#
directive|define
name|ELINK_FEATURE_CONFIG_PFC_ENABLED
value|(1<<1)
define|#
directive|define
name|ELINK_FEATURE_CONFIG_BC_SUPPORTS_OPT_MDL_VRFY
value|(1<<2)
define|#
directive|define
name|ELINK_FEATURE_CONFIG_BC_SUPPORTS_DUAL_PHY_OPT_MDL_VRFY
value|(1<<3)
define|#
directive|define
name|ELINK_FEATURE_CONFIG_EMUL_DISABLE_EMAC
value|(1<<4)
define|#
directive|define
name|ELINK_FEATURE_CONFIG_EMUL_DISABLE_BMAC
value|(1<<5)
define|#
directive|define
name|ELINK_FEATURE_CONFIG_EMUL_DISABLE_UMAC
value|(1<<6)
define|#
directive|define
name|ELINK_FEATURE_CONFIG_EMUL_DISABLE_XMAC
value|(1<<7)
define|#
directive|define
name|ELINK_FEATURE_CONFIG_BC_SUPPORTS_AFEX
value|(1<<8)
define|#
directive|define
name|ELINK_FEATURE_CONFIG_AUTOGREEEN_ENABLED
value|(1<<9)
define|#
directive|define
name|ELINK_FEATURE_CONFIG_BC_SUPPORTS_SFP_TX_DISABLED
value|(1<<10)
define|#
directive|define
name|ELINK_FEATURE_CONFIG_DISABLE_REMOTE_FAULT_DET
value|(1<<11)
define|#
directive|define
name|ELINK_FEATURE_CONFIG_IEEE_PHY_TEST
value|(1<<12)
define|#
directive|define
name|ELINK_FEATURE_CONFIG_MT_SUPPORT
value|(1<<13)
define|#
directive|define
name|ELINK_FEATURE_CONFIG_BOOT_FROM_SAN
value|(1<<14)
comment|/* Will be populated during common init */
name|struct
name|elink_phy
name|phy
index|[
name|ELINK_MAX_PHYS
index|]
decl_stmt|;
comment|/* Will be populated during common init */
name|uint8_t
name|num_phys
decl_stmt|;
name|uint8_t
name|rsrv
decl_stmt|;
comment|/* Used to configure the EEE Tx LPI timer, has several modes of 	 * operation, according to bits 29:28 - 	 * 2'b00: Timer will be configured by nvram, output will be the value 	 *        from nvram. 	 * 2'b01: Timer will be configured by nvram, output will be in 	 *        microseconds. 	 * 2'b10: bits 1:0 contain an nvram value which will be used instead 	 *        of the one located in the nvram. Output will be that value. 	 * 2'b11: bits 19:0 contain the idle timer in microseconds; output 	 *        will be in microseconds. 	 * Bits 31:30 should be 2'b11 in order for EEE to be enabled. 	 */
name|uint32_t
name|eee_mode
decl_stmt|;
define|#
directive|define
name|ELINK_EEE_MODE_NVRAM_BALANCED_TIME
value|(0xa00)
define|#
directive|define
name|ELINK_EEE_MODE_NVRAM_AGGRESSIVE_TIME
value|(0x100)
define|#
directive|define
name|ELINK_EEE_MODE_NVRAM_LATENCY_TIME
value|(0x6000)
define|#
directive|define
name|ELINK_EEE_MODE_NVRAM_MASK
value|(0x3)
define|#
directive|define
name|ELINK_EEE_MODE_TIMER_MASK
value|(0xfffff)
define|#
directive|define
name|ELINK_EEE_MODE_OUTPUT_TIME
value|(1<<28)
define|#
directive|define
name|ELINK_EEE_MODE_OVERRIDE_NVRAM
value|(1<<29)
define|#
directive|define
name|ELINK_EEE_MODE_ENABLE_LPI
value|(1<<30)
define|#
directive|define
name|ELINK_EEE_MODE_ADV_LPI
value|(1<<31)
name|uint16_t
name|hw_led_mode
decl_stmt|;
comment|/* part of the hw_config read from the shmem */
name|uint32_t
name|multi_phy_config
decl_stmt|;
comment|/* Device pointer passed to all callback functions */
name|struct
name|bxe_softc
modifier|*
name|sc
decl_stmt|;
name|uint16_t
name|req_fc_auto_adv
decl_stmt|;
comment|/* Should be set to TX / BOTH when 				req_flow_ctrl is set to AUTO */
name|uint16_t
name|link_flags
decl_stmt|;
define|#
directive|define
name|ELINK_LINK_FLAGS_INT_DISABLED
value|(1<<0)
define|#
directive|define
name|ELINK_PHY_INITIALIZED
value|(1<<1)
name|uint32_t
name|lfa_base
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Output parameters */
end_comment

begin_struct
struct|struct
name|elink_vars
block|{
name|uint8_t
name|phy_flags
decl_stmt|;
define|#
directive|define
name|PHY_XGXS_FLAG
value|(1<<0)
define|#
directive|define
name|PHY_SGMII_FLAG
value|(1<<1)
define|#
directive|define
name|PHY_PHYSICAL_LINK_FLAG
value|(1<<2)
define|#
directive|define
name|PHY_HALF_OPEN_CONN_FLAG
value|(1<<3)
define|#
directive|define
name|PHY_OVER_CURRENT_FLAG
value|(1<<4)
define|#
directive|define
name|PHY_SFP_TX_FAULT_FLAG
value|(1<<5)
name|uint8_t
name|mac_type
decl_stmt|;
define|#
directive|define
name|ELINK_MAC_TYPE_NONE
value|0
define|#
directive|define
name|ELINK_MAC_TYPE_EMAC
value|1
define|#
directive|define
name|ELINK_MAC_TYPE_BMAC
value|2
define|#
directive|define
name|ELINK_MAC_TYPE_UMAC
value|3
define|#
directive|define
name|ELINK_MAC_TYPE_XMAC
value|4
name|uint8_t
name|phy_link_up
decl_stmt|;
comment|/* internal phy link indication */
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
comment|/* The same definitions as the shmem parameter */
name|uint32_t
name|link_status
decl_stmt|;
name|uint32_t
name|eee_status
decl_stmt|;
name|uint8_t
name|fault_detected
decl_stmt|;
name|uint8_t
name|check_kr2_recovery_cnt
decl_stmt|;
define|#
directive|define
name|ELINK_CHECK_KR2_RECOVERY_CNT
value|5
name|uint16_t
name|periodic_flags
decl_stmt|;
define|#
directive|define
name|ELINK_PERIODIC_FLAGS_LINK_EVENT
value|0x0001
name|uint32_t
name|aeu_int_mask
decl_stmt|;
name|uint8_t
name|rx_tx_asic_rst
decl_stmt|;
name|uint8_t
name|turn_to_run_wc_rt
decl_stmt|;
name|uint16_t
name|rsrv2
decl_stmt|;
comment|/* The same definitions as the shmem2 parameter */
name|uint32_t
name|link_attr_sync
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/***********************************************************/
end_comment

begin_comment
comment|/*                         Functions                       */
end_comment

begin_comment
comment|/***********************************************************/
end_comment

begin_function_decl
name|elink_status_t
name|elink_phy_init
parameter_list|(
name|struct
name|elink_params
modifier|*
name|params
parameter_list|,
name|struct
name|elink_vars
modifier|*
name|vars
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Reset the link. Should be called when driver or interface goes down    Before calling phy firmware upgrade, the reset_ext_phy should be set    to 0 */
end_comment

begin_function_decl
name|elink_status_t
name|elink_link_reset
parameter_list|(
name|struct
name|elink_params
modifier|*
name|params
parameter_list|,
name|struct
name|elink_vars
modifier|*
name|vars
parameter_list|,
name|uint8_t
name|reset_ext_phy
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|elink_status_t
name|elink_lfa_reset
parameter_list|(
name|struct
name|elink_params
modifier|*
name|params
parameter_list|,
name|struct
name|elink_vars
modifier|*
name|vars
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* elink_link_update should be called upon link interrupt */
end_comment

begin_function_decl
name|elink_status_t
name|elink_link_update
parameter_list|(
name|struct
name|elink_params
modifier|*
name|params
parameter_list|,
name|struct
name|elink_vars
modifier|*
name|vars
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* use the following phy functions to read/write from external_phy   In order to use it to read/write internal phy registers, use   ELINK_DEFAULT_PHY_DEV_ADDR as devad, and (_bank + (_addr& 0xf)) as   the register */
end_comment

begin_function_decl
name|elink_status_t
name|elink_phy_read
parameter_list|(
name|struct
name|elink_params
modifier|*
name|params
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
name|elink_status_t
name|elink_phy_write
parameter_list|(
name|struct
name|elink_params
modifier|*
name|params
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
comment|/* Reads the link_status from the shmem,    and update the link vars accordingly */
end_comment

begin_function_decl
name|void
name|elink_link_status_update
parameter_list|(
name|struct
name|elink_params
modifier|*
name|input
parameter_list|,
name|struct
name|elink_vars
modifier|*
name|output
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* returns string representing the fw_version of the external phy */
end_comment

begin_function_decl
name|elink_status_t
name|elink_get_ext_phy_fw_version
parameter_list|(
name|struct
name|elink_params
modifier|*
name|params
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
comment|/* Set/Unset the led    Basically, the CLC takes care of the led for the link, but in case one needs    to set/unset the led unnaturally, set the "mode" to ELINK_LED_MODE_OPER to    blink the led, and ELINK_LED_MODE_OFF to set the led off.*/
end_comment

begin_function_decl
name|elink_status_t
name|elink_set_led
parameter_list|(
name|struct
name|elink_params
modifier|*
name|params
parameter_list|,
name|struct
name|elink_vars
modifier|*
name|vars
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
name|ELINK_LED_MODE_OFF
value|0
end_define

begin_define
define|#
directive|define
name|ELINK_LED_MODE_ON
value|1
end_define

begin_define
define|#
directive|define
name|ELINK_LED_MODE_OPER
value|2
end_define

begin_define
define|#
directive|define
name|ELINK_LED_MODE_FRONT_PANEL_OFF
value|3
end_define

begin_comment
comment|/* elink_handle_module_detect_int should be called upon module detection    interrupt */
end_comment

begin_function_decl
name|void
name|elink_handle_module_detect_int
parameter_list|(
name|struct
name|elink_params
modifier|*
name|params
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Get the actual link status. In case it returns ELINK_STATUS_OK, link is up, 	otherwise link is down*/
end_comment

begin_function_decl
name|elink_status_t
name|elink_test_link
parameter_list|(
name|struct
name|elink_params
modifier|*
name|params
parameter_list|,
name|struct
name|elink_vars
modifier|*
name|vars
parameter_list|,
name|uint8_t
name|is_serdes
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* One-time initialization for external phy after power up */
end_comment

begin_function_decl
name|elink_status_t
name|elink_common_init_phy
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|uint32_t
name|shmem_base_path
index|[]
parameter_list|,
name|uint32_t
name|shmem2_base_path
index|[]
parameter_list|,
name|uint32_t
name|chip_id
parameter_list|,
name|uint8_t
name|one_port_enabled
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Reset the external PHY using GPIO */
end_comment

begin_function_decl
name|void
name|elink_ext_phy_hw_reset
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

begin_comment
comment|/* Reset the external of SFX7101 */
end_comment

begin_function_decl
name|void
name|elink_sfx7101_sp_sw_reset
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|elink_phy
modifier|*
name|phy
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Read "byte_cnt" bytes from address "addr" from the SFP+ EEPROM */
end_comment

begin_function_decl
name|elink_status_t
name|elink_read_sfp_module_eeprom
parameter_list|(
name|struct
name|elink_phy
modifier|*
name|phy
parameter_list|,
name|struct
name|elink_params
modifier|*
name|params
parameter_list|,
name|uint8_t
name|dev_addr
parameter_list|,
name|uint16_t
name|addr
parameter_list|,
name|uint16_t
name|byte_cnt
parameter_list|,
name|uint8_t
modifier|*
name|o_buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|elink_hw_reset_phy
parameter_list|(
name|struct
name|elink_params
modifier|*
name|params
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Check swap bit and adjust PHY order */
end_comment

begin_function_decl
name|uint32_t
name|elink_phy_selection
parameter_list|(
name|struct
name|elink_params
modifier|*
name|params
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Probe the phys on board, and populate them in "params" */
end_comment

begin_function_decl
name|elink_status_t
name|elink_phy_probe
parameter_list|(
name|struct
name|elink_params
modifier|*
name|params
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Checks if fan failure detection is required on one of the phys on board */
end_comment

begin_function_decl
name|uint8_t
name|elink_fan_failure_det_req
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|uint32_t
name|shmem_base
parameter_list|,
name|uint32_t
name|shmem2_base
parameter_list|,
name|uint8_t
name|port
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Open / close the gate between the NIG and the BRB */
end_comment

begin_function_decl
name|void
name|elink_set_rx_filter
parameter_list|(
name|struct
name|elink_params
modifier|*
name|params
parameter_list|,
name|uint8_t
name|en
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* DCBX structs */
end_comment

begin_comment
comment|/* Number of maximum COS per chip */
end_comment

begin_define
define|#
directive|define
name|ELINK_DCBX_E2E3_MAX_NUM_COS
value|(2)
end_define

begin_define
define|#
directive|define
name|ELINK_DCBX_E3B0_MAX_NUM_COS_PORT0
value|(6)
end_define

begin_define
define|#
directive|define
name|ELINK_DCBX_E3B0_MAX_NUM_COS_PORT1
value|(3)
end_define

begin_define
define|#
directive|define
name|ELINK_DCBX_E3B0_MAX_NUM_COS
value|( \ 			ELINK_MAXVAL(ELINK_DCBX_E3B0_MAX_NUM_COS_PORT0, \ 			    ELINK_DCBX_E3B0_MAX_NUM_COS_PORT1))
end_define

begin_define
define|#
directive|define
name|ELINK_DCBX_MAX_NUM_COS
value|( \ 			ELINK_MAXVAL(ELINK_DCBX_E3B0_MAX_NUM_COS, \ 			    ELINK_DCBX_E2E3_MAX_NUM_COS))
end_define

begin_comment
comment|/* PFC port configuration params */
end_comment

begin_struct
struct|struct
name|elink_nig_brb_pfc_port_params
block|{
comment|/* NIG */
name|uint32_t
name|pause_enable
decl_stmt|;
name|uint32_t
name|llfc_out_en
decl_stmt|;
name|uint32_t
name|llfc_enable
decl_stmt|;
name|uint32_t
name|pkt_priority_to_cos
decl_stmt|;
name|uint8_t
name|num_of_rx_cos_priority_mask
decl_stmt|;
name|uint32_t
name|rx_cos_priority_mask
index|[
name|ELINK_DCBX_MAX_NUM_COS
index|]
decl_stmt|;
name|uint32_t
name|llfc_high_priority_classes
decl_stmt|;
name|uint32_t
name|llfc_low_priority_classes
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* ETS port configuration params */
end_comment

begin_struct
struct|struct
name|elink_ets_bw_params
block|{
name|uint8_t
name|bw
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|elink_ets_sp_params
block|{
comment|/** 	 * valid values are 0 - 5. 0 is highest strict priority. 	 * There can't be two COS's with the same pri. 	 */
name|uint8_t
name|pri
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
name|elink_cos_state
block|{
name|elink_cos_state_strict
init|=
literal|0
block|,
name|elink_cos_state_bw
init|=
literal|1
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|elink_ets_cos_params
block|{
name|enum
name|elink_cos_state
name|state
decl_stmt|;
union|union
block|{
name|struct
name|elink_ets_bw_params
name|bw_params
decl_stmt|;
name|struct
name|elink_ets_sp_params
name|sp_params
decl_stmt|;
block|}
name|params
union|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|elink_ets_params
block|{
name|uint8_t
name|num_of_cos
decl_stmt|;
comment|/* Number of valid COS entries*/
name|struct
name|elink_ets_cos_params
name|cos
index|[
name|ELINK_DCBX_MAX_NUM_COS
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Used to update the PFC attributes in EMAC, BMAC, NIG and BRB  * when link is already up  */
end_comment

begin_function_decl
name|elink_status_t
name|elink_update_pfc
parameter_list|(
name|struct
name|elink_params
modifier|*
name|params
parameter_list|,
name|struct
name|elink_vars
modifier|*
name|vars
parameter_list|,
name|struct
name|elink_nig_brb_pfc_port_params
modifier|*
name|pfc_params
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Used to configure the ETS to disable */
end_comment

begin_function_decl
name|elink_status_t
name|elink_ets_disabled
parameter_list|(
name|struct
name|elink_params
modifier|*
name|params
parameter_list|,
name|struct
name|elink_vars
modifier|*
name|vars
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Used to configure the ETS to BW limited */
end_comment

begin_function_decl
name|void
name|elink_ets_bw_limit
parameter_list|(
specifier|const
name|struct
name|elink_params
modifier|*
name|params
parameter_list|,
specifier|const
name|uint32_t
name|cos0_bw
parameter_list|,
specifier|const
name|uint32_t
name|cos1_bw
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Used to configure the ETS to strict */
end_comment

begin_function_decl
name|elink_status_t
name|elink_ets_strict
parameter_list|(
specifier|const
name|struct
name|elink_params
modifier|*
name|params
parameter_list|,
specifier|const
name|uint8_t
name|strict_cos
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  Configure the COS to ETS according to BW and SP settings.*/
end_comment

begin_function_decl
name|elink_status_t
name|elink_ets_e3b0_config
parameter_list|(
specifier|const
name|struct
name|elink_params
modifier|*
name|params
parameter_list|,
specifier|const
name|struct
name|elink_vars
modifier|*
name|vars
parameter_list|,
name|struct
name|elink_ets_params
modifier|*
name|ets_params
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Read pfc statistic*/
end_comment

begin_function_decl
name|void
name|elink_pfc_statistic
parameter_list|(
name|struct
name|elink_params
modifier|*
name|params
parameter_list|,
name|struct
name|elink_vars
modifier|*
name|vars
parameter_list|,
name|uint32_t
name|pfc_frames_sent
index|[
literal|2
index|]
parameter_list|,
name|uint32_t
name|pfc_frames_received
index|[
literal|2
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|elink_init_mod_abs_int
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|elink_vars
modifier|*
name|vars
parameter_list|,
name|uint32_t
name|chip_id
parameter_list|,
name|uint32_t
name|shmem_base
parameter_list|,
name|uint32_t
name|shmem2_base
parameter_list|,
name|uint8_t
name|port
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|elink_status_t
name|elink_sfp_module_detection
parameter_list|(
name|struct
name|elink_phy
modifier|*
name|phy
parameter_list|,
name|struct
name|elink_params
modifier|*
name|params
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|elink_period_func
parameter_list|(
name|struct
name|elink_params
modifier|*
name|params
parameter_list|,
name|struct
name|elink_vars
modifier|*
name|vars
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|elink_status_t
name|elink_check_half_open_conn
parameter_list|(
name|struct
name|elink_params
modifier|*
name|params
parameter_list|,
name|struct
name|elink_vars
modifier|*
name|vars
parameter_list|,
name|uint8_t
name|notify
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|elink_enable_pmd_tx
parameter_list|(
name|struct
name|elink_params
modifier|*
name|params
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ELINK_H */
end_comment

end_unit

