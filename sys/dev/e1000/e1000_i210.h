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
name|_E1000_I210_H_
end_ifndef

begin_define
define|#
directive|define
name|_E1000_I210_H_
end_define

begin_function_decl
name|bool
name|e1000_get_flash_presence_i210
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
name|e1000_update_flash_i210
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
name|e1000_update_nvm_checksum_i210
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
name|e1000_validate_nvm_checksum_i210
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
name|e1000_write_nvm_srwr_i210
parameter_list|(
name|struct
name|e1000_hw
modifier|*
name|hw
parameter_list|,
name|u16
name|offset
parameter_list|,
name|u16
name|words
parameter_list|,
name|u16
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|s32
name|e1000_read_nvm_srrd_i210
parameter_list|(
name|struct
name|e1000_hw
modifier|*
name|hw
parameter_list|,
name|u16
name|offset
parameter_list|,
name|u16
name|words
parameter_list|,
name|u16
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|s32
name|e1000_acquire_swfw_sync_i210
parameter_list|(
name|struct
name|e1000_hw
modifier|*
name|hw
parameter_list|,
name|u16
name|mask
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|e1000_release_swfw_sync_i210
parameter_list|(
name|struct
name|e1000_hw
modifier|*
name|hw
parameter_list|,
name|u16
name|mask
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|s32
name|e1000_read_xmdio_reg
parameter_list|(
name|struct
name|e1000_hw
modifier|*
name|hw
parameter_list|,
name|u16
name|addr
parameter_list|,
name|u8
name|dev_addr
parameter_list|,
name|u16
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|s32
name|e1000_write_xmdio_reg
parameter_list|(
name|struct
name|e1000_hw
modifier|*
name|hw
parameter_list|,
name|u16
name|addr
parameter_list|,
name|u8
name|dev_addr
parameter_list|,
name|u16
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|s32
name|e1000_init_hw_i210
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
name|E1000_STM_OPCODE
value|0xDB00
end_define

begin_define
define|#
directive|define
name|E1000_EEPROM_FLASH_SIZE_WORD
value|0x11
end_define

begin_define
define|#
directive|define
name|INVM_DWORD_TO_RECORD_TYPE
parameter_list|(
name|invm_dword
parameter_list|)
define|\
value|(u8)((invm_dword)& 0x7)
end_define

begin_define
define|#
directive|define
name|INVM_DWORD_TO_WORD_ADDRESS
parameter_list|(
name|invm_dword
parameter_list|)
define|\
value|(u8)(((invm_dword)& 0x0000FE00)>> 9)
end_define

begin_define
define|#
directive|define
name|INVM_DWORD_TO_WORD_DATA
parameter_list|(
name|invm_dword
parameter_list|)
define|\
value|(u16)(((invm_dword)& 0xFFFF0000)>> 16)
end_define

begin_enum
enum|enum
name|E1000_INVM_STRUCTURE_TYPE
block|{
name|E1000_INVM_UNINITIALIZED_STRUCTURE
init|=
literal|0x00
block|,
name|E1000_INVM_WORD_AUTOLOAD_STRUCTURE
init|=
literal|0x01
block|,
name|E1000_INVM_CSR_AUTOLOAD_STRUCTURE
init|=
literal|0x02
block|,
name|E1000_INVM_PHY_REGISTER_AUTOLOAD_STRUCTURE
init|=
literal|0x03
block|,
name|E1000_INVM_RSA_KEY_SHA256_STRUCTURE
init|=
literal|0x04
block|,
name|E1000_INVM_INVALIDATED_STRUCTURE
init|=
literal|0x0F
block|, }
enum|;
end_enum

begin_define
define|#
directive|define
name|E1000_INVM_RSA_KEY_SHA256_DATA_SIZE_IN_DWORDS
value|8
end_define

begin_define
define|#
directive|define
name|E1000_INVM_CSR_AUTOLOAD_DATA_SIZE_IN_DWORDS
value|1
end_define

begin_define
define|#
directive|define
name|E1000_INVM_ULT_BYTES_SIZE
value|8
end_define

begin_define
define|#
directive|define
name|E1000_INVM_RECORD_SIZE_IN_BYTES
value|4
end_define

begin_define
define|#
directive|define
name|E1000_INVM_VER_FIELD_ONE
value|0x1FF8
end_define

begin_define
define|#
directive|define
name|E1000_INVM_VER_FIELD_TWO
value|0x7FE000
end_define

begin_define
define|#
directive|define
name|E1000_INVM_IMGTYPE_FIELD
value|0x1F800000
end_define

begin_define
define|#
directive|define
name|E1000_INVM_MAJOR_MASK
value|0x3F0
end_define

begin_define
define|#
directive|define
name|E1000_INVM_MINOR_MASK
value|0xF
end_define

begin_define
define|#
directive|define
name|E1000_INVM_MAJOR_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|ID_LED_DEFAULT_I210
value|((ID_LED_OFF1_ON2<< 8) | \ 					 (ID_LED_DEF1_DEF2<<  4) | \ 					 (ID_LED_OFF1_OFF2))
end_define

begin_define
define|#
directive|define
name|ID_LED_DEFAULT_I210_SERDES
value|((ID_LED_DEF1_DEF2<< 8) | \ 					 (ID_LED_DEF1_DEF2<<  4) | \ 					 (ID_LED_OFF1_ON2))
end_define

begin_comment
comment|/* NVM offset defaults for I211 devices */
end_comment

begin_define
define|#
directive|define
name|NVM_INIT_CTRL_2_DEFAULT_I211
value|0X7243
end_define

begin_define
define|#
directive|define
name|NVM_INIT_CTRL_4_DEFAULT_I211
value|0x00C1
end_define

begin_define
define|#
directive|define
name|NVM_LED_1_CFG_DEFAULT_I211
value|0x0184
end_define

begin_define
define|#
directive|define
name|NVM_LED_0_2_CFG_DEFAULT_I211
value|0x200C
end_define

begin_comment
comment|/* PLL Defines */
end_comment

begin_define
define|#
directive|define
name|E1000_PCI_PMCSR
value|0x44
end_define

begin_define
define|#
directive|define
name|E1000_PCI_PMCSR_D3
value|0x03
end_define

begin_define
define|#
directive|define
name|E1000_MAX_PLL_TRIES
value|5
end_define

begin_define
define|#
directive|define
name|E1000_PHY_PLL_UNCONF
value|0xFF
end_define

begin_define
define|#
directive|define
name|E1000_PHY_PLL_FREQ_PAGE
value|0xFC0000
end_define

begin_define
define|#
directive|define
name|E1000_PHY_PLL_FREQ_REG
value|0x000E
end_define

begin_define
define|#
directive|define
name|E1000_INVM_DEFAULT_AL
value|0x202F
end_define

begin_define
define|#
directive|define
name|E1000_INVM_AUTOLOAD
value|0x0A
end_define

begin_define
define|#
directive|define
name|E1000_INVM_PLL_WO_VAL
value|0x0010
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

