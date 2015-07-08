begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2013 The TCPDUMP project  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS  * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE  * COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,  * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN  * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* OpenFlow: protocol between controller and datapath. */
end_comment

begin_comment
comment|/* for netdissect_options */
end_comment

begin_include
include|#
directive|include
file|"netdissect.h"
end_include

begin_define
define|#
directive|define
name|OF_HEADER_LEN
value|8
end_define

begin_define
define|#
directive|define
name|ONF_EXP_ONF
value|0x4f4e4600
end_define

begin_define
define|#
directive|define
name|ONF_EXP_BUTE
value|0xff000001
end_define

begin_define
define|#
directive|define
name|ONF_EXP_NOVIFLOW
value|0xff000002
end_define

begin_define
define|#
directive|define
name|ONF_EXP_L3
value|0xff000003
end_define

begin_define
define|#
directive|define
name|ONF_EXP_L4L7
value|0xff000004
end_define

begin_define
define|#
directive|define
name|ONF_EXP_WMOB
value|0xff000005
end_define

begin_define
define|#
directive|define
name|ONF_EXP_FABS
value|0xff000006
end_define

begin_define
define|#
directive|define
name|ONF_EXP_OTRANS
value|0xff000007
end_define

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|tok
name|onf_exp_str
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Routines to print packets for various versions of OpenFlow.  */
end_comment

begin_function_decl
specifier|extern
specifier|const
name|u_char
modifier|*
name|of10_header_body_print
parameter_list|(
name|netdissect_options
modifier|*
name|ndo
parameter_list|,
specifier|const
name|u_char
modifier|*
parameter_list|,
specifier|const
name|u_char
modifier|*
parameter_list|,
specifier|const
name|uint8_t
parameter_list|,
specifier|const
name|uint16_t
parameter_list|,
specifier|const
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|of_vendor_name
parameter_list|(
specifier|const
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

end_unit

