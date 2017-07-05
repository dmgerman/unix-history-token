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
name|_IXGBE_PHY_H_
end_ifndef

begin_define
define|#
directive|define
name|_IXGBE_PHY_H_
end_define

begin_include
include|#
directive|include
file|"ixgbe_type.h"
end_include

begin_define
define|#
directive|define
name|IXGBE_I2C_EEPROM_DEV_ADDR
value|0xA0
end_define

begin_define
define|#
directive|define
name|IXGBE_I2C_EEPROM_DEV_ADDR2
value|0xA2
end_define

begin_define
define|#
directive|define
name|IXGBE_I2C_EEPROM_BANK_LEN
value|0xFF
end_define

begin_comment
comment|/* EEPROM byte offsets */
end_comment

begin_define
define|#
directive|define
name|IXGBE_SFF_IDENTIFIER
value|0x0
end_define

begin_define
define|#
directive|define
name|IXGBE_SFF_IDENTIFIER_SFP
value|0x3
end_define

begin_define
define|#
directive|define
name|IXGBE_SFF_VENDOR_OUI_BYTE0
value|0x25
end_define

begin_define
define|#
directive|define
name|IXGBE_SFF_VENDOR_OUI_BYTE1
value|0x26
end_define

begin_define
define|#
directive|define
name|IXGBE_SFF_VENDOR_OUI_BYTE2
value|0x27
end_define

begin_define
define|#
directive|define
name|IXGBE_SFF_1GBE_COMP_CODES
value|0x6
end_define

begin_define
define|#
directive|define
name|IXGBE_SFF_10GBE_COMP_CODES
value|0x3
end_define

begin_define
define|#
directive|define
name|IXGBE_SFF_CABLE_TECHNOLOGY
value|0x8
end_define

begin_define
define|#
directive|define
name|IXGBE_SFF_CABLE_SPEC_COMP
value|0x3C
end_define

begin_define
define|#
directive|define
name|IXGBE_SFF_SFF_8472_SWAP
value|0x5C
end_define

begin_define
define|#
directive|define
name|IXGBE_SFF_SFF_8472_COMP
value|0x5E
end_define

begin_define
define|#
directive|define
name|IXGBE_SFF_SFF_8472_OSCB
value|0x6E
end_define

begin_define
define|#
directive|define
name|IXGBE_SFF_SFF_8472_ESCB
value|0x76
end_define

begin_define
define|#
directive|define
name|IXGBE_SFF_IDENTIFIER_QSFP_PLUS
value|0xD
end_define

begin_define
define|#
directive|define
name|IXGBE_SFF_QSFP_VENDOR_OUI_BYTE0
value|0xA5
end_define

begin_define
define|#
directive|define
name|IXGBE_SFF_QSFP_VENDOR_OUI_BYTE1
value|0xA6
end_define

begin_define
define|#
directive|define
name|IXGBE_SFF_QSFP_VENDOR_OUI_BYTE2
value|0xA7
end_define

begin_define
define|#
directive|define
name|IXGBE_SFF_QSFP_CONNECTOR
value|0x82
end_define

begin_define
define|#
directive|define
name|IXGBE_SFF_QSFP_10GBE_COMP
value|0x83
end_define

begin_define
define|#
directive|define
name|IXGBE_SFF_QSFP_1GBE_COMP
value|0x86
end_define

begin_define
define|#
directive|define
name|IXGBE_SFF_QSFP_CABLE_LENGTH
value|0x92
end_define

begin_define
define|#
directive|define
name|IXGBE_SFF_QSFP_DEVICE_TECH
value|0x93
end_define

begin_comment
comment|/* Bitmasks */
end_comment

begin_define
define|#
directive|define
name|IXGBE_SFF_DA_PASSIVE_CABLE
value|0x4
end_define

begin_define
define|#
directive|define
name|IXGBE_SFF_DA_ACTIVE_CABLE
value|0x8
end_define

begin_define
define|#
directive|define
name|IXGBE_SFF_DA_SPEC_ACTIVE_LIMITING
value|0x4
end_define

begin_define
define|#
directive|define
name|IXGBE_SFF_1GBASESX_CAPABLE
value|0x1
end_define

begin_define
define|#
directive|define
name|IXGBE_SFF_1GBASELX_CAPABLE
value|0x2
end_define

begin_define
define|#
directive|define
name|IXGBE_SFF_1GBASET_CAPABLE
value|0x8
end_define

begin_define
define|#
directive|define
name|IXGBE_SFF_10GBASESR_CAPABLE
value|0x10
end_define

begin_define
define|#
directive|define
name|IXGBE_SFF_10GBASELR_CAPABLE
value|0x20
end_define

begin_define
define|#
directive|define
name|IXGBE_SFF_SOFT_RS_SELECT_MASK
value|0x8
end_define

begin_define
define|#
directive|define
name|IXGBE_SFF_SOFT_RS_SELECT_10G
value|0x8
end_define

begin_define
define|#
directive|define
name|IXGBE_SFF_SOFT_RS_SELECT_1G
value|0x0
end_define

begin_define
define|#
directive|define
name|IXGBE_SFF_ADDRESSING_MODE
value|0x4
end_define

begin_define
define|#
directive|define
name|IXGBE_SFF_QSFP_DA_ACTIVE_CABLE
value|0x1
end_define

begin_define
define|#
directive|define
name|IXGBE_SFF_QSFP_DA_PASSIVE_CABLE
value|0x8
end_define

begin_define
define|#
directive|define
name|IXGBE_SFF_QSFP_CONNECTOR_NOT_SEPARABLE
value|0x23
end_define

begin_define
define|#
directive|define
name|IXGBE_SFF_QSFP_TRANSMITER_850NM_VCSEL
value|0x0
end_define

begin_define
define|#
directive|define
name|IXGBE_I2C_EEPROM_READ_MASK
value|0x100
end_define

begin_define
define|#
directive|define
name|IXGBE_I2C_EEPROM_STATUS_MASK
value|0x3
end_define

begin_define
define|#
directive|define
name|IXGBE_I2C_EEPROM_STATUS_NO_OPERATION
value|0x0
end_define

begin_define
define|#
directive|define
name|IXGBE_I2C_EEPROM_STATUS_PASS
value|0x1
end_define

begin_define
define|#
directive|define
name|IXGBE_I2C_EEPROM_STATUS_FAIL
value|0x2
end_define

begin_define
define|#
directive|define
name|IXGBE_I2C_EEPROM_STATUS_IN_PROGRESS
value|0x3
end_define

begin_define
define|#
directive|define
name|IXGBE_CS4227
value|0xBE
end_define

begin_comment
comment|/* CS4227 address */
end_comment

begin_define
define|#
directive|define
name|IXGBE_CS4227_GLOBAL_ID_LSB
value|0
end_define

begin_define
define|#
directive|define
name|IXGBE_CS4227_GLOBAL_ID_MSB
value|1
end_define

begin_define
define|#
directive|define
name|IXGBE_CS4227_SCRATCH
value|2
end_define

begin_define
define|#
directive|define
name|IXGBE_CS4227_GLOBAL_ID_VALUE
value|0x03E5
end_define

begin_define
define|#
directive|define
name|IXGBE_CS4227_EFUSE_PDF_SKU
value|0x19F
end_define

begin_define
define|#
directive|define
name|IXGBE_CS4223_SKU_ID
value|0x0010
end_define

begin_comment
comment|/* Quad port */
end_comment

begin_define
define|#
directive|define
name|IXGBE_CS4227_SKU_ID
value|0x0014
end_define

begin_comment
comment|/* Dual port */
end_comment

begin_define
define|#
directive|define
name|IXGBE_CS4227_RESET_PENDING
value|0x1357
end_define

begin_define
define|#
directive|define
name|IXGBE_CS4227_RESET_COMPLETE
value|0x5AA5
end_define

begin_define
define|#
directive|define
name|IXGBE_CS4227_RETRIES
value|15
end_define

begin_define
define|#
directive|define
name|IXGBE_CS4227_EFUSE_STATUS
value|0x0181
end_define

begin_define
define|#
directive|define
name|IXGBE_CS4227_LINE_SPARE22_MSB
value|0x12AD
end_define

begin_comment
comment|/* Reg to program speed */
end_comment

begin_define
define|#
directive|define
name|IXGBE_CS4227_LINE_SPARE24_LSB
value|0x12B0
end_define

begin_comment
comment|/* Reg to program EDC */
end_comment

begin_define
define|#
directive|define
name|IXGBE_CS4227_HOST_SPARE22_MSB
value|0x1AAD
end_define

begin_comment
comment|/* Reg to program speed */
end_comment

begin_define
define|#
directive|define
name|IXGBE_CS4227_HOST_SPARE24_LSB
value|0x1AB0
end_define

begin_comment
comment|/* Reg to program EDC */
end_comment

begin_define
define|#
directive|define
name|IXGBE_CS4227_EEPROM_STATUS
value|0x5001
end_define

begin_define
define|#
directive|define
name|IXGBE_CS4227_EEPROM_LOAD_OK
value|0x0001
end_define

begin_define
define|#
directive|define
name|IXGBE_CS4227_SPEED_1G
value|0x8000
end_define

begin_define
define|#
directive|define
name|IXGBE_CS4227_SPEED_10G
value|0
end_define

begin_define
define|#
directive|define
name|IXGBE_CS4227_EDC_MODE_CX1
value|0x0002
end_define

begin_define
define|#
directive|define
name|IXGBE_CS4227_EDC_MODE_SR
value|0x0004
end_define

begin_define
define|#
directive|define
name|IXGBE_CS4227_EDC_MODE_DIAG
value|0x0008
end_define

begin_define
define|#
directive|define
name|IXGBE_CS4227_RESET_HOLD
value|500
end_define

begin_comment
comment|/* microseconds */
end_comment

begin_define
define|#
directive|define
name|IXGBE_CS4227_RESET_DELAY
value|450
end_define

begin_comment
comment|/* milliseconds */
end_comment

begin_define
define|#
directive|define
name|IXGBE_CS4227_CHECK_DELAY
value|30
end_define

begin_comment
comment|/* milliseconds */
end_comment

begin_define
define|#
directive|define
name|IXGBE_PE
value|0xE0
end_define

begin_comment
comment|/* Port expander address */
end_comment

begin_define
define|#
directive|define
name|IXGBE_PE_OUTPUT
value|1
end_define

begin_comment
comment|/* Output register offset */
end_comment

begin_define
define|#
directive|define
name|IXGBE_PE_CONFIG
value|3
end_define

begin_comment
comment|/* Config register offset */
end_comment

begin_define
define|#
directive|define
name|IXGBE_PE_BIT1
value|(1<< 1)
end_define

begin_comment
comment|/* Flow control defines */
end_comment

begin_define
define|#
directive|define
name|IXGBE_TAF_SYM_PAUSE
value|0x400
end_define

begin_define
define|#
directive|define
name|IXGBE_TAF_ASM_PAUSE
value|0x800
end_define

begin_comment
comment|/* Bit-shift macros */
end_comment

begin_define
define|#
directive|define
name|IXGBE_SFF_VENDOR_OUI_BYTE0_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|IXGBE_SFF_VENDOR_OUI_BYTE1_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|IXGBE_SFF_VENDOR_OUI_BYTE2_SHIFT
value|8
end_define

begin_comment
comment|/* Vendor OUIs: format of OUI is 0x[byte0][byte1][byte2][00] */
end_comment

begin_define
define|#
directive|define
name|IXGBE_SFF_VENDOR_OUI_TYCO
value|0x00407600
end_define

begin_define
define|#
directive|define
name|IXGBE_SFF_VENDOR_OUI_FTL
value|0x00906500
end_define

begin_define
define|#
directive|define
name|IXGBE_SFF_VENDOR_OUI_AVAGO
value|0x00176A00
end_define

begin_define
define|#
directive|define
name|IXGBE_SFF_VENDOR_OUI_INTEL
value|0x001B2100
end_define

begin_comment
comment|/* I2C SDA and SCL timing parameters for standard mode */
end_comment

begin_define
define|#
directive|define
name|IXGBE_I2C_T_HD_STA
value|4
end_define

begin_define
define|#
directive|define
name|IXGBE_I2C_T_LOW
value|5
end_define

begin_define
define|#
directive|define
name|IXGBE_I2C_T_HIGH
value|4
end_define

begin_define
define|#
directive|define
name|IXGBE_I2C_T_SU_STA
value|5
end_define

begin_define
define|#
directive|define
name|IXGBE_I2C_T_HD_DATA
value|5
end_define

begin_define
define|#
directive|define
name|IXGBE_I2C_T_SU_DATA
value|1
end_define

begin_define
define|#
directive|define
name|IXGBE_I2C_T_RISE
value|1
end_define

begin_define
define|#
directive|define
name|IXGBE_I2C_T_FALL
value|1
end_define

begin_define
define|#
directive|define
name|IXGBE_I2C_T_SU_STO
value|4
end_define

begin_define
define|#
directive|define
name|IXGBE_I2C_T_BUF
value|5
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|IXGBE_SFP_DETECT_RETRIES
end_ifndef

begin_define
define|#
directive|define
name|IXGBE_SFP_DETECT_RETRIES
value|10
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IXGBE_SFP_DETECT_RETRIES */
end_comment

begin_define
define|#
directive|define
name|IXGBE_TN_LASI_STATUS_REG
value|0x9005
end_define

begin_define
define|#
directive|define
name|IXGBE_TN_LASI_STATUS_TEMP_ALARM
value|0x0008
end_define

begin_comment
comment|/* SFP+ SFF-8472 Compliance */
end_comment

begin_define
define|#
directive|define
name|IXGBE_SFF_SFF_8472_UNSUP
value|0x00
end_define

begin_function_decl
name|s32
name|ixgbe_init_phy_ops_generic
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|ixgbe_validate_phy_addr
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
name|hw
parameter_list|,
name|u32
name|phy_addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|enum
name|ixgbe_phy_type
name|ixgbe_get_phy_type_from_id
parameter_list|(
name|u32
name|phy_id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|s32
name|ixgbe_get_phy_id
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|s32
name|ixgbe_identify_phy_generic
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|s32
name|ixgbe_reset_phy_generic
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|s32
name|ixgbe_read_phy_reg_mdi
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
name|hw
parameter_list|,
name|u32
name|reg_addr
parameter_list|,
name|u32
name|device_type
parameter_list|,
name|u16
modifier|*
name|phy_data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|s32
name|ixgbe_write_phy_reg_mdi
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
name|hw
parameter_list|,
name|u32
name|reg_addr
parameter_list|,
name|u32
name|device_type
parameter_list|,
name|u16
name|phy_data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|s32
name|ixgbe_read_phy_reg_generic
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
name|hw
parameter_list|,
name|u32
name|reg_addr
parameter_list|,
name|u32
name|device_type
parameter_list|,
name|u16
modifier|*
name|phy_data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|s32
name|ixgbe_write_phy_reg_generic
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
name|hw
parameter_list|,
name|u32
name|reg_addr
parameter_list|,
name|u32
name|device_type
parameter_list|,
name|u16
name|phy_data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|s32
name|ixgbe_setup_phy_link_generic
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|s32
name|ixgbe_setup_phy_link_speed_generic
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
name|hw
parameter_list|,
name|ixgbe_link_speed
name|speed
parameter_list|,
name|bool
name|autoneg_wait_to_complete
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|s32
name|ixgbe_get_copper_link_capabilities_generic
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
name|hw
parameter_list|,
name|ixgbe_link_speed
modifier|*
name|speed
parameter_list|,
name|bool
modifier|*
name|autoneg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|s32
name|ixgbe_check_reset_blocked
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* PHY specific */
end_comment

begin_function_decl
name|s32
name|ixgbe_check_phy_link_tnx
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
name|hw
parameter_list|,
name|ixgbe_link_speed
modifier|*
name|speed
parameter_list|,
name|bool
modifier|*
name|link_up
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|s32
name|ixgbe_setup_phy_link_tnx
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|s32
name|ixgbe_get_phy_firmware_version_tnx
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
name|hw
parameter_list|,
name|u16
modifier|*
name|firmware_version
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|s32
name|ixgbe_get_phy_firmware_version_generic
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
name|hw
parameter_list|,
name|u16
modifier|*
name|firmware_version
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|s32
name|ixgbe_reset_phy_nl
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|s32
name|ixgbe_set_copper_phy_power
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
name|hw
parameter_list|,
name|bool
name|on
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|s32
name|ixgbe_identify_module_generic
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|s32
name|ixgbe_identify_sfp_module_generic
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u64
name|ixgbe_get_supported_phy_sfp_layer_generic
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|s32
name|ixgbe_identify_qsfp_module_generic
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|s32
name|ixgbe_get_sfp_init_sequence_offsets
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
name|hw
parameter_list|,
name|u16
modifier|*
name|list_offset
parameter_list|,
name|u16
modifier|*
name|data_offset
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|s32
name|ixgbe_tn_check_overtemp
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|s32
name|ixgbe_read_i2c_byte_generic
parameter_list|(
name|struct
name|ixgbe_hw
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
name|ixgbe_read_i2c_byte_generic_unlocked
parameter_list|(
name|struct
name|ixgbe_hw
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
name|ixgbe_write_i2c_byte_generic
parameter_list|(
name|struct
name|ixgbe_hw
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
name|ixgbe_write_i2c_byte_generic_unlocked
parameter_list|(
name|struct
name|ixgbe_hw
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
name|ixgbe_read_i2c_eeprom_generic
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
name|hw
parameter_list|,
name|u8
name|byte_offset
parameter_list|,
name|u8
modifier|*
name|eeprom_data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|s32
name|ixgbe_write_i2c_eeprom_generic
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
name|hw
parameter_list|,
name|u8
name|byte_offset
parameter_list|,
name|u8
name|eeprom_data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ixgbe_i2c_bus_clear
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|s32
name|ixgbe_read_i2c_combined_generic_int
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
parameter_list|,
name|bool
name|lock
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|s32
name|ixgbe_write_i2c_combined_generic_int
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
parameter_list|,
name|bool
name|lock
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IXGBE_PHY_H_ */
end_comment

end_unit

