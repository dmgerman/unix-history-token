begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 2015 John Wehle<john@feith.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ARM_AMLOGIC_AML8726_SOC_H
end_ifndef

begin_define
define|#
directive|define
name|_ARM_AMLOGIC_AML8726_SOC_H
end_define

begin_define
define|#
directive|define
name|AML_SOC_AOBUS_BASE_ADDR
value|0xc8100000
end_define

begin_define
define|#
directive|define
name|AML_SOC_CBUS_BASE_ADDR
value|0xc1100000
end_define

begin_function_decl
name|void
name|aml8726_identify_soc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* cbus */
end_comment

begin_define
define|#
directive|define
name|AML_SOC_HW_REV_REG
value|0x7d4c
end_define

begin_define
define|#
directive|define
name|AML_SOC_HW_REV_UNKNOWN
value|0xffffffff
end_define

begin_define
define|#
directive|define
name|AML_SOC_HW_REV_M3
value|0x15
end_define

begin_define
define|#
directive|define
name|AML_SOC_HW_REV_M6
value|0x16
end_define

begin_define
define|#
directive|define
name|AML_SOC_HW_REV_M6TV
value|0x17
end_define

begin_define
define|#
directive|define
name|AML_SOC_HW_REV_M6TVL
value|0x18
end_define

begin_define
define|#
directive|define
name|AML_SOC_HW_REV_M8
value|0x19
end_define

begin_define
define|#
directive|define
name|AML_SOC_HW_REV_M8B
value|0x1b
end_define

begin_define
define|#
directive|define
name|AML_SOC_METAL_REV_REG
value|0x81a8
end_define

begin_define
define|#
directive|define
name|AML_SOC_METAL_REV_UNKNOWN
value|0xffffffff
end_define

begin_define
define|#
directive|define
name|AML_SOC_M8_METAL_REV_A
value|0x11111111
end_define

begin_define
define|#
directive|define
name|AML_SOC_M8_METAL_REV_M2_A
value|0x11111112
end_define

begin_define
define|#
directive|define
name|AML_SOC_M8_METAL_REV_B
value|0x11111113
end_define

begin_define
define|#
directive|define
name|AML_SOC_M8_METAL_REV_C
value|0x11111133
end_define

begin_define
define|#
directive|define
name|AML_SOC_M8B_METAL_REV_A
value|0x11111111
end_define

begin_decl_stmt
specifier|extern
name|uint32_t
name|aml8726_soc_hw_rev
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint32_t
name|aml8726_soc_metal_rev
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ARM_AMLOGIC_AML8726_SOC_H */
end_comment

end_unit

