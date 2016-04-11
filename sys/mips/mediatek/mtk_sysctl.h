begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2016 Stanislav Galabov.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MTK_SYSCTL_H_
end_ifndef

begin_define
define|#
directive|define
name|_MTK_SYSCTL_H_
end_define

begin_comment
comment|/* System Control */
end_comment

begin_define
define|#
directive|define
name|SYSCTL_CHIPID0_3
value|0x00
end_define

begin_define
define|#
directive|define
name|SYSCTL_CHIPID4_7
value|0x04
end_define

begin_define
define|#
directive|define
name|SYSCTL_REVID
value|0x0C
end_define

begin_define
define|#
directive|define
name|SYSCTL_REVID_MASK
value|0xFFFF
end_define

begin_define
define|#
directive|define
name|SYSCTL_MT7621_REV_E
value|0x0101
end_define

begin_define
define|#
directive|define
name|SYSCTL_SYSCFG
value|0x10
end_define

begin_define
define|#
directive|define
name|SYSCTL_SYSCFG1
value|0x14
end_define

begin_define
define|#
directive|define
name|SYSCTL_CLKCFG0
value|0x2C
end_define

begin_define
define|#
directive|define
name|SYSCTL_CLKCFG1
value|0x30
end_define

begin_define
define|#
directive|define
name|SYSCTL_RSTCTRL
value|0x34
end_define

begin_define
define|#
directive|define
name|SYSCTL_GPIOMODE
value|0x60
end_define

begin_define
define|#
directive|define
name|SYSCTL_CUR_CLK_STS
value|0x44
end_define

begin_define
define|#
directive|define
name|SYSCTL_MT7620_CPLL_CFG0
value|0x54
end_define

begin_define
define|#
directive|define
name|SYSCTL_MT7620_CPLL_CFG1
value|0x58
end_define

begin_define
define|#
directive|define
name|SYSCFG1_USB_HOST_MODE
value|(1<<10)
end_define

begin_function_decl
specifier|extern
name|uint32_t
name|mtk_sysctl_get
parameter_list|(
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mtk_sysctl_set
parameter_list|(
name|uint32_t
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mtk_sysctl_clr_set
parameter_list|(
name|uint32_t
parameter_list|,
name|uint32_t
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MTK_SYSCTL_H_ */
end_comment

end_unit

