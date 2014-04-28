begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013 Ganbold Tsagaankhuu<ganbold@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_A20_CPU_CFG_H_
end_ifndef

begin_define
define|#
directive|define
name|_A20_CPU_CFG_H_
end_define

begin_define
define|#
directive|define
name|CPU_CFG_BASE
value|0xe1c25c00
end_define

begin_define
define|#
directive|define
name|CPU0_RST_CTRL
value|0x0040
end_define

begin_define
define|#
directive|define
name|CPU0_CTRL_REG
value|0x0044
end_define

begin_define
define|#
directive|define
name|CPU0_STATUS_REG
value|0x0048
end_define

begin_define
define|#
directive|define
name|CPU1_RST_CTRL
value|0x0080
end_define

begin_define
define|#
directive|define
name|CPU1_CTRL_REG
value|0x0084
end_define

begin_define
define|#
directive|define
name|CPU1_STATUS_REG
value|0x0088
end_define

begin_define
define|#
directive|define
name|GENER_CTRL_REG
value|0x0184
end_define

begin_define
define|#
directive|define
name|EVENT_IN_REG
value|0x0190
end_define

begin_define
define|#
directive|define
name|PRIVATE_REG
value|0x01a4
end_define

begin_define
define|#
directive|define
name|IDLE_CNT0_LOW_REG
value|0x0200
end_define

begin_define
define|#
directive|define
name|IDLE_CNT0_HIGH_REG
value|0x0204
end_define

begin_define
define|#
directive|define
name|IDLE_CNT0_CTRL_REG
value|0x0208
end_define

begin_define
define|#
directive|define
name|IDLE_CNT1_LOW_REG
value|0x0210
end_define

begin_define
define|#
directive|define
name|IDLE_CNT1_HIGH_REG
value|0x0214
end_define

begin_define
define|#
directive|define
name|IDLE_CNT1_CTRL_REG
value|0x0218
end_define

begin_define
define|#
directive|define
name|OSC24M_CNT64_CTRL_REG
value|0x0280
end_define

begin_define
define|#
directive|define
name|OSC24M_CNT64_LOW_REG
value|0x0284
end_define

begin_define
define|#
directive|define
name|OSC24M_CNT64_HIGH_REG
value|0x0288
end_define

begin_define
define|#
directive|define
name|LOSC_CNT64_CTRL_REG
value|0x0290
end_define

begin_define
define|#
directive|define
name|LOSC_CNT64_LOW_REG
value|0x0294
end_define

begin_define
define|#
directive|define
name|LOSC_CNT64_HIGH_REG
value|0x0298
end_define

begin_define
define|#
directive|define
name|CNT64_RL_EN
value|0x02
end_define

begin_comment
comment|/* read latch enable */
end_comment

begin_function_decl
name|uint64_t
name|a20_read_counter64
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _A20_CPU_CFG_H_ */
end_comment

end_unit

