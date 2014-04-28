begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013 Ganbold Tsagaankhuu<ganbold@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RK30_PMU_H_
end_ifndef

begin_define
define|#
directive|define
name|_RK30_PMU_H_
end_define

begin_define
define|#
directive|define
name|RK30_PMU_BASE
value|0xF0004000
end_define

begin_define
define|#
directive|define
name|PMU_WAKEUP_CFG0
value|0x00
end_define

begin_define
define|#
directive|define
name|PMU_WAKEUP_CFG1
value|0x04
end_define

begin_define
define|#
directive|define
name|PMU_PWRDN_CON
value|0x08
end_define

begin_define
define|#
directive|define
name|PMU_PWRDN_ST
value|0x0c
end_define

begin_define
define|#
directive|define
name|PMU_INT_CON
value|0x10
end_define

begin_define
define|#
directive|define
name|PMU_INT_ST
value|0x14
end_define

begin_define
define|#
directive|define
name|PMU_MISC_CON
value|0x18
end_define

begin_define
define|#
directive|define
name|PMU_OSC_CNT
value|0x1c
end_define

begin_define
define|#
directive|define
name|PMU_PLL_CNT
value|0x20
end_define

begin_define
define|#
directive|define
name|PMU_PMU_CNT
value|0x24
end_define

begin_define
define|#
directive|define
name|PMU_DDRIO_PWRON_CNT
value|0x28
end_define

begin_define
define|#
directive|define
name|PMU_WAKEUP_RST_CLR_CNT
value|0x2c
end_define

begin_define
define|#
directive|define
name|PMU_SCU_PWRDWN_CNT
value|0x30
end_define

begin_define
define|#
directive|define
name|PMU_SCU_PWRUP_CNT
value|0x34
end_define

begin_define
define|#
directive|define
name|PMU_MISC_CON1
value|0x38
end_define

begin_define
define|#
directive|define
name|PMU_GPIO0_CON
value|0x3c
end_define

begin_define
define|#
directive|define
name|PMU_SYS_REG0
value|0x40
end_define

begin_define
define|#
directive|define
name|PMU_SYS_REG1
value|0x44
end_define

begin_define
define|#
directive|define
name|PMU_SYS_REG2
value|0x48
end_define

begin_define
define|#
directive|define
name|PMU_SYS_REG3
value|0x4c
end_define

begin_define
define|#
directive|define
name|PMU_STOP_INT_DLY
value|0x60
end_define

begin_define
define|#
directive|define
name|PMU_GPIO0A_PULL
value|0x64
end_define

begin_define
define|#
directive|define
name|PMU_GPIO0B_PULL
value|0x68
end_define

begin_function_decl
name|void
name|rk30_pmu_gpio_pud
parameter_list|(
name|uint32_t
name|pin
parameter_list|,
name|uint32_t
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _RK30_PMU_H_ */
end_comment

end_unit

