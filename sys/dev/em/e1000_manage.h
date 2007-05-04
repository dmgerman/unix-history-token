begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*******************************************************************************    Copyright (c) 2001-2007, Intel Corporation    All rights reserved.      Redistribution and use in source and binary forms, with or without    modification, are permitted provided that the following conditions are met:       1. Redistributions of source code must retain the above copyright notice,        this list of conditions and the following disclaimer.       2. Redistributions in binary form must reproduce the above copyright        notice, this list of conditions and the following disclaimer in the        documentation and/or other materials provided with the distribution.       3. Neither the name of the Intel Corporation nor the names of its        contributors may be used to endorse or promote products derived from        this software without specific prior written permission.      THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE    ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE    LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR    CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF    SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS    INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN    CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)    ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE   POSSIBILITY OF SUCH DAMAGE.  *******************************************************************************/
end_comment

begin_function_decl
name|$FreeBSD$
ifndef|#
directive|ifndef
name|_E1000_MANAGE_H_
define|#
directive|define
name|_E1000_MANAGE_H_
include|#
directive|include
file|"e1000_api.h"
name|boolean_t
name|e1000_check_mng_mode_generic
parameter_list|(
name|struct
name|e1000_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|boolean_t
name|e1000_enable_tx_pkt_filtering_generic
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
name|e1000_mng_enable_host_if_generic
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
name|e1000_mng_host_if_write_generic
parameter_list|(
name|struct
name|e1000_hw
modifier|*
name|hw
parameter_list|,
name|u8
modifier|*
name|buffer
parameter_list|,
name|u16
name|length
parameter_list|,
name|u16
name|offset
parameter_list|,
name|u8
modifier|*
name|sum
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|s32
name|e1000_mng_write_cmd_header_generic
parameter_list|(
name|struct
name|e1000_hw
modifier|*
name|hw
parameter_list|,
name|struct
name|e1000_host_mng_command_header
modifier|*
name|hdr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|s32
name|e1000_mng_write_dhcp_info_generic
parameter_list|(
name|struct
name|e1000_hw
modifier|*
name|hw
parameter_list|,
name|u8
modifier|*
name|buffer
parameter_list|,
name|u16
name|length
parameter_list|)
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
enum|enum
block|{
name|e1000_mng_mode_none
init|=
literal|0
block|,
name|e1000_mng_mode_asf
block|,
name|e1000_mng_mode_pt
block|,
name|e1000_mng_mode_ipmi
block|,
name|e1000_mng_mode_host_if_only
block|}
name|e1000_mng_mode
typedef|;
end_typedef

begin_define
define|#
directive|define
name|E1000_FACTPS_MNGCG
value|0x20000000
end_define

begin_define
define|#
directive|define
name|E1000_FWSM_MODE_MASK
value|0xE
end_define

begin_define
define|#
directive|define
name|E1000_FWSM_MODE_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|E1000_MNG_IAMT_MODE
value|0x3
end_define

begin_define
define|#
directive|define
name|E1000_MNG_DHCP_COOKIE_LENGTH
value|0x10
end_define

begin_define
define|#
directive|define
name|E1000_MNG_DHCP_COOKIE_OFFSET
value|0x6F0
end_define

begin_define
define|#
directive|define
name|E1000_MNG_DHCP_COMMAND_TIMEOUT
value|10
end_define

begin_define
define|#
directive|define
name|E1000_MNG_DHCP_TX_PAYLOAD_CMD
value|64
end_define

begin_define
define|#
directive|define
name|E1000_MNG_DHCP_COOKIE_STATUS_PARSING
value|0x1
end_define

begin_define
define|#
directive|define
name|E1000_MNG_DHCP_COOKIE_STATUS_VLAN
value|0x2
end_define

begin_define
define|#
directive|define
name|E1000_VFTA_ENTRY_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|E1000_VFTA_ENTRY_MASK
value|0x7F
end_define

begin_define
define|#
directive|define
name|E1000_VFTA_ENTRY_BIT_SHIFT_MASK
value|0x1F
end_define

begin_define
define|#
directive|define
name|E1000_HI_MAX_BLOCK_BYTE_LENGTH
value|1792
end_define

begin_comment
comment|/* Number of bytes in range */
end_comment

begin_define
define|#
directive|define
name|E1000_HI_MAX_BLOCK_DWORD_LENGTH
value|448
end_define

begin_comment
comment|/* Number of dwords in range */
end_comment

begin_define
define|#
directive|define
name|E1000_HI_COMMAND_TIMEOUT
value|500
end_define

begin_comment
comment|/* Process HI command limit */
end_comment

begin_define
define|#
directive|define
name|E1000_HICR_EN
value|0x01
end_define

begin_comment
comment|/* Enable bit - RO */
end_comment

begin_define
define|#
directive|define
name|E1000_HICR_C
value|0x02
end_define

begin_comment
comment|/* Driver sets this bit when done                                           * to put command in RAM */
end_comment

begin_define
define|#
directive|define
name|E1000_HICR_SV
value|0x04
end_define

begin_comment
comment|/* Status Validity */
end_comment

begin_define
define|#
directive|define
name|E1000_HICR_FW_RESET_ENABLE
value|0x40
end_define

begin_define
define|#
directive|define
name|E1000_HICR_FW_RESET
value|0x80
end_define

begin_define
define|#
directive|define
name|E1000_IAMT_SIGNATURE
value|0x544D4149
end_define

begin_comment
comment|/* Intel(R) Active Management                                           * Technology signature */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

