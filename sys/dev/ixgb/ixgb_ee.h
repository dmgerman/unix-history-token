begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*******************************************************************************    Copyright (c) 2001-2004, Intel Corporation   All rights reserved.      Redistribution and use in source and binary forms, with or without   modification, are permitted provided that the following conditions are met:       1. Redistributions of source code must retain the above copyright notice,       this list of conditions and the following disclaimer.       2. Redistributions in binary form must reproduce the above copyright       notice, this list of conditions and the following disclaimer in the       documentation and/or other materials provided with the distribution.       3. Neither the name of the Intel Corporation nor the names of its       contributors may be used to endorse or promote products derived from       this software without specific prior written permission.      THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE   IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE   ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE   LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS   INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN   CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)   ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE   POSSIBILITY OF SUCH DAMAGE.  *******************************************************************************/
end_comment

begin_comment
comment|/*$FreeBSD$*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IXGB_EE_H_
end_ifndef

begin_define
define|#
directive|define
name|_IXGB_EE_H_
end_define

begin_define
define|#
directive|define
name|IXGB_EEPROM_SIZE
value|64
end_define

begin_comment
comment|/* Size in words */
end_comment

begin_define
define|#
directive|define
name|IXGB_ETH_LENGTH_OF_ADDRESS
value|6
end_define

begin_comment
comment|/* EEPROM Commands */
end_comment

begin_define
define|#
directive|define
name|EEPROM_READ_OPCODE
value|0x6
end_define

begin_comment
comment|/* EERPOM read opcode */
end_comment

begin_define
define|#
directive|define
name|EEPROM_WRITE_OPCODE
value|0x5
end_define

begin_comment
comment|/* EERPOM write opcode */
end_comment

begin_define
define|#
directive|define
name|EEPROM_ERASE_OPCODE
value|0x7
end_define

begin_comment
comment|/* EERPOM erase opcode */
end_comment

begin_define
define|#
directive|define
name|EEPROM_EWEN_OPCODE
value|0x13
end_define

begin_comment
comment|/* EERPOM erase/write enable */
end_comment

begin_define
define|#
directive|define
name|EEPROM_EWDS_OPCODE
value|0x10
end_define

begin_comment
comment|/* EERPOM erast/write disable */
end_comment

begin_comment
comment|/* EEPROM MAP (Word Offsets) */
end_comment

begin_define
define|#
directive|define
name|EEPROM_IA_1_2_REG
value|0x0000
end_define

begin_define
define|#
directive|define
name|EEPROM_IA_3_4_REG
value|0x0001
end_define

begin_define
define|#
directive|define
name|EEPROM_IA_5_6_REG
value|0x0002
end_define

begin_define
define|#
directive|define
name|EEPROM_COMPATIBILITY_REG
value|0x0003
end_define

begin_define
define|#
directive|define
name|EEPROM_PBA_1_2_REG
value|0x0008
end_define

begin_define
define|#
directive|define
name|EEPROM_PBA_3_4_REG
value|0x0009
end_define

begin_define
define|#
directive|define
name|EEPROM_INIT_CONTROL1_REG
value|0x000A
end_define

begin_define
define|#
directive|define
name|EEPROM_SUBSYS_ID_REG
value|0x000B
end_define

begin_define
define|#
directive|define
name|EEPROM_SUBVEND_ID_REG
value|0x000C
end_define

begin_define
define|#
directive|define
name|EEPROM_DEVICE_ID_REG
value|0x000D
end_define

begin_define
define|#
directive|define
name|EEPROM_VENDOR_ID_REG
value|0x000E
end_define

begin_define
define|#
directive|define
name|EEPROM_INIT_CONTROL2_REG
value|0x000F
end_define

begin_define
define|#
directive|define
name|EEPROM_SWDPINS_REG
value|0x0020
end_define

begin_define
define|#
directive|define
name|EEPROM_CIRCUIT_CTRL_REG
value|0x0021
end_define

begin_define
define|#
directive|define
name|EEPROM_D0_D3_POWER_REG
value|0x0022
end_define

begin_define
define|#
directive|define
name|EEPROM_FLASH_VERSION
value|0x0032
end_define

begin_define
define|#
directive|define
name|EEPROM_CHECKSUM_REG
value|0x003F
end_define

begin_comment
comment|/* Mask bits for fields in Word 0x0a of the EEPROM */
end_comment

begin_define
define|#
directive|define
name|EEPROM_ICW1_SIGNATURE_MASK
value|0xC000
end_define

begin_define
define|#
directive|define
name|EEPROM_ICW1_SIGNATURE_VALID
value|0x4000
end_define

begin_comment
comment|/* For checksumming, the sum of all words in the EEPROM should equal 0xBABA. */
end_comment

begin_define
define|#
directive|define
name|EEPROM_SUM
value|0xBABA
end_define

begin_comment
comment|/* EEPROM Map Sizes (Byte Counts) */
end_comment

begin_define
define|#
directive|define
name|PBA_SIZE
value|4
end_define

begin_comment
comment|/* EEPROM Map defines (WORD OFFSETS)*/
end_comment

begin_comment
comment|/* EEPROM structure */
end_comment

begin_struct
struct|struct
name|ixgb_ee_map_type
block|{
name|uint8_t
name|mac_addr
index|[
name|IXGB_ETH_LENGTH_OF_ADDRESS
index|]
decl_stmt|;
name|uint16_t
name|compatibility
decl_stmt|;
name|uint16_t
name|reserved1
index|[
literal|4
index|]
decl_stmt|;
name|uint32_t
name|pba_number
decl_stmt|;
name|uint16_t
name|init_ctrl_reg_1
decl_stmt|;
name|uint16_t
name|subsystem_id
decl_stmt|;
name|uint16_t
name|subvendor_id
decl_stmt|;
name|uint16_t
name|device_id
decl_stmt|;
name|uint16_t
name|vendor_id
decl_stmt|;
name|uint16_t
name|init_ctrl_reg_2
decl_stmt|;
name|uint16_t
name|oem_reserved
index|[
literal|16
index|]
decl_stmt|;
name|uint16_t
name|swdpins_reg
decl_stmt|;
name|uint16_t
name|circuit_ctrl_reg
decl_stmt|;
name|uint8_t
name|d3_power
decl_stmt|;
name|uint8_t
name|d0_power
decl_stmt|;
name|uint16_t
name|reserved2
index|[
literal|28
index|]
decl_stmt|;
name|uint16_t
name|checksum
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* EEPROM Functions */
end_comment

begin_function_decl
name|uint16_t
name|ixgb_read_eeprom
parameter_list|(
name|struct
name|ixgb_hw
modifier|*
name|hw
parameter_list|,
name|uint16_t
name|reg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|boolean_t
name|ixgb_validate_eeprom_checksum
parameter_list|(
name|struct
name|ixgb_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ixgb_update_eeprom_checksum
parameter_list|(
name|struct
name|ixgb_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ixgb_write_eeprom
parameter_list|(
name|struct
name|ixgb_hw
modifier|*
name|hw
parameter_list|,
name|uint16_t
name|reg
parameter_list|,
name|uint16_t
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IXGB_EE_H */
end_comment

end_unit

