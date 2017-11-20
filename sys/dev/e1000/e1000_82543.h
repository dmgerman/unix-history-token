begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************   SPDX-License-Identifier: BSD-3-Clause    Copyright (c) 2001-2015, Intel Corporation    All rights reserved.      Redistribution and use in source and binary forms, with or without    modification, are permitted provided that the following conditions are met:       1. Redistributions of source code must retain the above copyright notice,        this list of conditions and the following disclaimer.       2. Redistributions in binary form must reproduce the above copyright        notice, this list of conditions and the following disclaimer in the        documentation and/or other materials provided with the distribution.       3. Neither the name of the Intel Corporation nor the names of its        contributors may be used to endorse or promote products derived from        this software without specific prior written permission.      THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE    ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE    LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR    CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF    SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS    INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN    CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)    ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE   POSSIBILITY OF SUCH DAMAGE.  ******************************************************************************/
end_comment

begin_comment
comment|/*$FreeBSD$*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_E1000_82543_H_
end_ifndef

begin_define
define|#
directive|define
name|_E1000_82543_H_
end_define

begin_define
define|#
directive|define
name|PHY_PREAMBLE
value|0xFFFFFFFF
end_define

begin_define
define|#
directive|define
name|PHY_PREAMBLE_SIZE
value|32
end_define

begin_define
define|#
directive|define
name|PHY_SOF
value|0x1
end_define

begin_define
define|#
directive|define
name|PHY_OP_READ
value|0x2
end_define

begin_define
define|#
directive|define
name|PHY_OP_WRITE
value|0x1
end_define

begin_define
define|#
directive|define
name|PHY_TURNAROUND
value|0x2
end_define

begin_define
define|#
directive|define
name|TBI_COMPAT_ENABLED
value|0x1
end_define

begin_comment
comment|/* Global "knob" for the workaround */
end_comment

begin_comment
comment|/* If TBI_COMPAT_ENABLED, then this is the current state (on/off) */
end_comment

begin_define
define|#
directive|define
name|TBI_SBP_ENABLED
value|0x2
end_define

begin_function_decl
name|void
name|e1000_tbi_adjust_stats_82543
parameter_list|(
name|struct
name|e1000_hw
modifier|*
name|hw
parameter_list|,
name|struct
name|e1000_hw_stats
modifier|*
name|stats
parameter_list|,
name|u32
name|frame_len
parameter_list|,
name|u8
modifier|*
name|mac_addr
parameter_list|,
name|u32
name|max_frame_size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|e1000_set_tbi_compatibility_82543
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

begin_function_decl
name|bool
name|e1000_tbi_sbp_enabled_82543
parameter_list|(
name|struct
name|e1000_hw
modifier|*
name|hw
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

