begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2010-2011 Adrian Chadd, Xenion Pty Ltd.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ATH_AR9002PHY_H__
end_ifndef

begin_define
define|#
directive|define
name|__ATH_AR9002PHY_H__
end_define

begin_define
define|#
directive|define
name|AR_PHY_TX_PWRCTRL4
value|0xa264
end_define

begin_define
define|#
directive|define
name|AR_PHY_TX_PWRCTRL_PD_AVG_VALID
value|0x00000001
end_define

begin_define
define|#
directive|define
name|AR_PHY_TX_PWRCTRL_PD_AVG_VALID_S
value|0
end_define

begin_define
define|#
directive|define
name|AR_PHY_TX_PWRCTRL_PD_AVG_OUT
value|0x000001FE
end_define

begin_define
define|#
directive|define
name|AR_PHY_TX_PWRCTRL_PD_AVG_OUT_S
value|1
end_define

begin_define
define|#
directive|define
name|AR_PHY_TX_PWRCTRL6_0
value|0xa270
end_define

begin_define
define|#
directive|define
name|AR_PHY_TX_PWRCTRL6_1
value|0xb270
end_define

begin_define
define|#
directive|define
name|AR_PHY_TX_PWRCTRL_ERR_EST_MODE
value|0x03000000
end_define

begin_define
define|#
directive|define
name|AR_PHY_TX_PWRCTRL_ERR_EST_MODE_S
value|24
end_define

begin_define
define|#
directive|define
name|AR_PHY_TX_PWRCTRL7
value|0xa274
end_define

begin_define
define|#
directive|define
name|AR_PHY_TX_PWRCTRL_INIT_TX_GAIN
value|0x01F80000
end_define

begin_define
define|#
directive|define
name|AR_PHY_TX_PWRCTRL_INIT_TX_GAIN_S
value|19
end_define

begin_define
define|#
directive|define
name|AR_PHY_TX_PWRCTRL8
value|0xa278
end_define

begin_define
define|#
directive|define
name|AR_PHY_TX_PWRCTRL10
value|0xa394
end_define

begin_define
define|#
directive|define
name|AR_PHY_TX_GAIN_TBL1
value|0xa300
end_define

begin_define
define|#
directive|define
name|AR_PHY_TX_GAIN
value|0x0007F000
end_define

begin_define
define|#
directive|define
name|AR_PHY_TX_GAIN_S
value|12
end_define

begin_define
define|#
directive|define
name|AR_PHY_CH0_TX_PWRCTRL11
value|0xa398
end_define

begin_define
define|#
directive|define
name|AR_PHY_CH1_TX_PWRCTRL11
value|0xb398
end_define

begin_define
define|#
directive|define
name|AR_PHY_CH0_TX_PWRCTRL12
value|0xa3dc
end_define

begin_define
define|#
directive|define
name|AR_PHY_CH0_TX_PWRCTRL13
value|0xa3e0
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

