begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************    Copyright (c) 2001-2012, Intel Corporation    All rights reserved.      Redistribution and use in source and binary forms, with or without    modification, are permitted provided that the following conditions are met:       1. Redistributions of source code must retain the above copyright notice,        this list of conditions and the following disclaimer.       2. Redistributions in binary form must reproduce the above copyright        notice, this list of conditions and the following disclaimer in the        documentation and/or other materials provided with the distribution.       3. Neither the name of the Intel Corporation nor the names of its        contributors may be used to endorse or promote products derived from        this software without specific prior written permission.      THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE    ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE    LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR    CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF    SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS    INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN    CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)    ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE   POSSIBILITY OF SUCH DAMAGE.  ******************************************************************************/
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
name|e1000_read_invm_i211
parameter_list|(
name|struct
name|e1000_hw
modifier|*
name|hw
parameter_list|,
name|u8
name|address
parameter_list|,
name|u16
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|s32
name|e1000_check_for_copper_link_i210
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
name|e1000_set_ltr_i210
parameter_list|(
name|struct
name|e1000_hw
modifier|*
name|hw
parameter_list|,
name|bool
name|link
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
name|ID_LED_DEFAULT_I210
value|((ID_LED_OFF1_ON2<< 8) | \ 					 (ID_LED_DEF1_DEF2<<  4) | \ 					 (ID_LED_OFF1_OFF2))
end_define

begin_define
define|#
directive|define
name|ID_LED_DEFAULT_I210_SERDES
value|((ID_LED_DEF1_DEF2<< 8) | \ 					 (ID_LED_DEF1_DEF2<<  4) | \ 					 (ID_LED_DEF1_DEF2))
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

