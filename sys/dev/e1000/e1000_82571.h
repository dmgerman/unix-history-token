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
name|_E1000_82571_H_
end_ifndef

begin_define
define|#
directive|define
name|_E1000_82571_H_
end_define

begin_define
define|#
directive|define
name|ID_LED_RESERVED_F746
value|0xF746
end_define

begin_define
define|#
directive|define
name|ID_LED_DEFAULT_82573
value|((ID_LED_DEF1_DEF2<< 12) | \ 				 (ID_LED_OFF1_ON2<<  8) | \ 				 (ID_LED_DEF1_DEF2<<  4) | \ 				 (ID_LED_DEF1_DEF2))
end_define

begin_define
define|#
directive|define
name|E1000_GCR_L1_ACT_WITHOUT_L0S_RX
value|0x08000000
end_define

begin_define
define|#
directive|define
name|AN_RETRY_COUNT
value|5
end_define

begin_comment
comment|/* Autoneg Retry Count value */
end_comment

begin_comment
comment|/* Intr Throttling - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_EITR_82574
parameter_list|(
name|_n
parameter_list|)
value|(0x000E8 + (0x4 * (_n)))
end_define

begin_define
define|#
directive|define
name|E1000_EIAC_82574
value|0x000DC
end_define

begin_comment
comment|/* Ext. Interrupt Auto Clear - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_EIAC_MASK_82574
value|0x01F00000
end_define

begin_define
define|#
directive|define
name|E1000_IVAR_INT_ALLOC_VALID
value|0x8
end_define

begin_comment
comment|/* Manageability Operation Mode mask */
end_comment

begin_define
define|#
directive|define
name|E1000_NVM_INIT_CTRL2_MNGM
value|0x6000
end_define

begin_define
define|#
directive|define
name|E1000_BASE1000T_STATUS
value|10
end_define

begin_define
define|#
directive|define
name|E1000_IDLE_ERROR_COUNT_MASK
value|0xFF
end_define

begin_define
define|#
directive|define
name|E1000_RECEIVE_ERROR_COUNTER
value|21
end_define

begin_define
define|#
directive|define
name|E1000_RECEIVE_ERROR_MAX
value|0xFFFF
end_define

begin_function_decl
name|bool
name|e1000_check_phy_82574
parameter_list|(
name|struct
name|e1000_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|e1000_get_laa_state_82571
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
name|e1000_set_laa_state_82571
parameter_list|(
name|struct
name|e1000_hw
modifier|*
name|hw
parameter_list|,
name|bool
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

