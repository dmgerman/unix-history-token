begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*******************************************************************************    Copyright (c) 2001-2007, Intel Corporation    All rights reserved.      Redistribution and use in source and binary forms, with or without    modification, are permitted provided that the following conditions are met:       1. Redistributions of source code must retain the above copyright notice,        this list of conditions and the following disclaimer.       2. Redistributions in binary form must reproduce the above copyright        notice, this list of conditions and the following disclaimer in the        documentation and/or other materials provided with the distribution.       3. Neither the name of the Intel Corporation nor the names of its        contributors may be used to endorse or promote products derived from        this software without specific prior written permission.      THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE    ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE    LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR    CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF    SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS    INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN    CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)    ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE   POSSIBILITY OF SUCH DAMAGE.  *******************************************************************************/
end_comment

begin_macro
name|$FreeBSD$
end_macro

begin_ifndef
ifndef|#
directive|ifndef
name|_E1000_82541_H_
end_ifndef

begin_define
define|#
directive|define
name|_E1000_82541_H_
end_define

begin_include
include|#
directive|include
file|"e1000_api.h"
end_include

begin_define
define|#
directive|define
name|NVM_WORD_SIZE_BASE_SHIFT_82541
value|(NVM_WORD_SIZE_BASE_SHIFT + 1)
end_define

begin_define
define|#
directive|define
name|IGP01E1000_PHY_CHANNEL_NUM
value|4
end_define

begin_define
define|#
directive|define
name|IGP01E1000_PHY_AGC_A
value|0x1172
end_define

begin_define
define|#
directive|define
name|IGP01E1000_PHY_AGC_B
value|0x1272
end_define

begin_define
define|#
directive|define
name|IGP01E1000_PHY_AGC_C
value|0x1472
end_define

begin_define
define|#
directive|define
name|IGP01E1000_PHY_AGC_D
value|0x1872
end_define

begin_define
define|#
directive|define
name|IGP01E1000_PHY_AGC_PARAM_A
value|0x1171
end_define

begin_define
define|#
directive|define
name|IGP01E1000_PHY_AGC_PARAM_B
value|0x1271
end_define

begin_define
define|#
directive|define
name|IGP01E1000_PHY_AGC_PARAM_C
value|0x1471
end_define

begin_define
define|#
directive|define
name|IGP01E1000_PHY_AGC_PARAM_D
value|0x1871
end_define

begin_define
define|#
directive|define
name|IGP01E1000_PHY_EDAC_MU_INDEX
value|0xC000
end_define

begin_define
define|#
directive|define
name|IGP01E1000_PHY_EDAC_SIGN_EXT_9_BITS
value|0x8000
end_define

begin_define
define|#
directive|define
name|IGP01E1000_PHY_DSP_RESET
value|0x1F33
end_define

begin_define
define|#
directive|define
name|IGP01E1000_PHY_DSP_FFE
value|0x1F35
end_define

begin_define
define|#
directive|define
name|IGP01E1000_PHY_DSP_FFE_CM_CP
value|0x0069
end_define

begin_define
define|#
directive|define
name|IGP01E1000_PHY_DSP_FFE_DEFAULT
value|0x002A
end_define

begin_define
define|#
directive|define
name|IGP01E1000_IEEE_FORCE_GIG
value|0x0140
end_define

begin_define
define|#
directive|define
name|IGP01E1000_IEEE_RESTART_AUTONEG
value|0x3300
end_define

begin_define
define|#
directive|define
name|IGP01E1000_AGC_LENGTH_SHIFT
value|7
end_define

begin_define
define|#
directive|define
name|IGP01E1000_AGC_RANGE
value|10
end_define

begin_define
define|#
directive|define
name|FFE_IDLE_ERR_COUNT_TIMEOUT_20
value|20
end_define

begin_define
define|#
directive|define
name|FFE_IDLE_ERR_COUNT_TIMEOUT_100
value|100
end_define

begin_define
define|#
directive|define
name|IGP01E1000_ANALOG_FUSE_STATUS
value|0x20D0
end_define

begin_define
define|#
directive|define
name|IGP01E1000_ANALOG_SPARE_FUSE_STATUS
value|0x20D1
end_define

begin_define
define|#
directive|define
name|IGP01E1000_ANALOG_FUSE_CONTROL
value|0x20DC
end_define

begin_define
define|#
directive|define
name|IGP01E1000_ANALOG_FUSE_BYPASS
value|0x20DE
end_define

begin_define
define|#
directive|define
name|IGP01E1000_ANALOG_SPARE_FUSE_ENABLED
value|0x0100
end_define

begin_define
define|#
directive|define
name|IGP01E1000_ANALOG_FUSE_FINE_MASK
value|0x0F80
end_define

begin_define
define|#
directive|define
name|IGP01E1000_ANALOG_FUSE_COARSE_MASK
value|0x0070
end_define

begin_define
define|#
directive|define
name|IGP01E1000_ANALOG_FUSE_COARSE_THRESH
value|0x0040
end_define

begin_define
define|#
directive|define
name|IGP01E1000_ANALOG_FUSE_COARSE_10
value|0x0010
end_define

begin_define
define|#
directive|define
name|IGP01E1000_ANALOG_FUSE_FINE_1
value|0x0080
end_define

begin_define
define|#
directive|define
name|IGP01E1000_ANALOG_FUSE_FINE_10
value|0x0500
end_define

begin_define
define|#
directive|define
name|IGP01E1000_ANALOG_FUSE_POLY_MASK
value|0xF000
end_define

begin_define
define|#
directive|define
name|IGP01E1000_ANALOG_FUSE_ENABLE_SW_CONTROL
value|0x0002
end_define

begin_define
define|#
directive|define
name|IGP01E1000_MSE_CHANNEL_D
value|0x000F
end_define

begin_define
define|#
directive|define
name|IGP01E1000_MSE_CHANNEL_C
value|0x00F0
end_define

begin_define
define|#
directive|define
name|IGP01E1000_MSE_CHANNEL_B
value|0x0F00
end_define

begin_define
define|#
directive|define
name|IGP01E1000_MSE_CHANNEL_A
value|0xF000
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

