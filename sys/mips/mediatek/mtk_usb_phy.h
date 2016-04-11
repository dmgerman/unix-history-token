begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2016 Stanislav Galabov.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MTK_USB_PHY_H_
end_ifndef

begin_define
define|#
directive|define
name|_MTK_USB_PHY_H_
end_define

begin_define
define|#
directive|define
name|MT7621_FM_FEG_BASE
value|0x0100
end_define

begin_define
define|#
directive|define
name|MT7621_U2_BASE
value|0x0800
end_define

begin_define
define|#
directive|define
name|MT7621_U2_BASE_P1
value|0x1000
end_define

begin_define
define|#
directive|define
name|MT7621_SR_COEF
value|28
end_define

begin_define
define|#
directive|define
name|MT7628_FM_FEG_BASE
value|0x0f00
end_define

begin_define
define|#
directive|define
name|MT7628_U2_BASE
value|0x0800
end_define

begin_define
define|#
directive|define
name|MT7628_SR_COEF
value|32
end_define

begin_define
define|#
directive|define
name|U2_PHY_AC0
value|0x00
end_define

begin_define
define|#
directive|define
name|U2_PHY_AC1
value|0x04
end_define

begin_define
define|#
directive|define
name|U2_PHY_AC2
value|0x08
end_define

begin_define
define|#
directive|define
name|U2_PHY_ACR0
value|0x10
end_define

begin_define
define|#
directive|define
name|SRCAL_EN
value|(1<<23)
end_define

begin_define
define|#
directive|define
name|SRCTRL_MSK
value|0x7
end_define

begin_define
define|#
directive|define
name|SRCTRL_OFF
value|16
end_define

begin_define
define|#
directive|define
name|SRCTRL
value|(SRCTRL_MSK<<SRCTRL_OFF)
end_define

begin_define
define|#
directive|define
name|U2_PHY_ACR1
value|0x14
end_define

begin_define
define|#
directive|define
name|U2_PHY_ACR2
value|0x18
end_define

begin_define
define|#
directive|define
name|U2_PHY_ACR3
value|0x1C
end_define

begin_define
define|#
directive|define
name|U2_PHY_DCR0
value|0x60
end_define

begin_define
define|#
directive|define
name|U2_PHY_DCR1
value|0x64
end_define

begin_define
define|#
directive|define
name|U2_PHY_DTM0
value|0x68
end_define

begin_define
define|#
directive|define
name|U2_PHY_DTM1
value|0x6C
end_define

begin_define
define|#
directive|define
name|U2_PHY_FMCR0
value|0x00
end_define

begin_define
define|#
directive|define
name|CYCLECNT
value|(0xffffff)
end_define

begin_define
define|#
directive|define
name|FDET_EN
value|(1<<24)
end_define

begin_define
define|#
directive|define
name|U2_PHY_FMCR1
value|0x04
end_define

begin_define
define|#
directive|define
name|FRCK_EN
value|(1<<8)
end_define

begin_define
define|#
directive|define
name|U2_PHY_FMCR2
value|0x08
end_define

begin_define
define|#
directive|define
name|U2_PHY_FMMONR0
value|0x0C
end_define

begin_define
define|#
directive|define
name|U2_PHY_FMMONR1
value|0x10
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MTK_USB_PHY_H_ */
end_comment

end_unit

