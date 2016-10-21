begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010 Damien Bergamini<damien.bergamini@free.fr>  * Copyright (c) 2016 Andriy Voskoboinyk<avos@FreeBSD.org>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  * $OpenBSD: if_urtwnreg.h,v 1.3 2010/11/16 18:02:59 damien Exp $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|R92CU_REG_H
end_ifndef

begin_define
define|#
directive|define
name|R92CU_REG_H
end_define

begin_include
include|#
directive|include
file|<dev/rtwn/rtl8192c/r92c_reg.h>
end_include

begin_comment
comment|/*  * MAC registers.  */
end_comment

begin_comment
comment|/* System Configuration. */
end_comment

begin_define
define|#
directive|define
name|R92C_USB_SIE_INTF
value|0x0e0
end_define

begin_comment
comment|/*  * USB registers.  */
end_comment

begin_define
define|#
directive|define
name|R92C_USB_SUSPEND
value|0xfe10
end_define

begin_define
define|#
directive|define
name|R92C_USB_INFO
value|0xfe17
end_define

begin_define
define|#
directive|define
name|R92C_USB_SPECIAL_OPTION
value|0xfe55
end_define

begin_define
define|#
directive|define
name|R92C_USB_HCPWM
value|0xfe57
end_define

begin_define
define|#
directive|define
name|R92C_USB_HRPWM
value|0xfe58
end_define

begin_define
define|#
directive|define
name|R92C_USB_DMA_AGG_TO
value|0xfe5b
end_define

begin_define
define|#
directive|define
name|R92C_USB_AGG_TO
value|0xfe5c
end_define

begin_define
define|#
directive|define
name|R92C_USB_AGG_TH
value|0xfe5d
end_define

begin_define
define|#
directive|define
name|R92C_USB_VID
value|0xfe60
end_define

begin_define
define|#
directive|define
name|R92C_USB_PID
value|0xfe62
end_define

begin_define
define|#
directive|define
name|R92C_USB_OPTIONAL
value|0xfe64
end_define

begin_define
define|#
directive|define
name|R92C_USB_EP
value|0xfe65
end_define

begin_define
define|#
directive|define
name|R92C_USB_PHY
value|0xfe68
end_define

begin_define
define|#
directive|define
name|R92C_USB_MAC_ADDR
value|0xfe70
end_define

begin_define
define|#
directive|define
name|R92C_USB_STRING
value|0xfe80
end_define

begin_comment
comment|/* Bits for R92C_USB_SPECIAL_OPTION. */
end_comment

begin_define
define|#
directive|define
name|R92C_USB_SPECIAL_OPTION_AGG_EN
value|0x08
end_define

begin_define
define|#
directive|define
name|R92C_USB_SPECIAL_OPTION_INT_BULK_SEL
value|0x10
end_define

begin_comment
comment|/* Bits for R92C_USB_EP. */
end_comment

begin_define
define|#
directive|define
name|R92C_USB_EP_HQ_M
value|0x000f
end_define

begin_define
define|#
directive|define
name|R92C_USB_EP_HQ_S
value|0
end_define

begin_define
define|#
directive|define
name|R92C_USB_EP_NQ_M
value|0x00f0
end_define

begin_define
define|#
directive|define
name|R92C_USB_EP_NQ_S
value|4
end_define

begin_define
define|#
directive|define
name|R92C_USB_EP_LQ_M
value|0x0f00
end_define

begin_define
define|#
directive|define
name|R92C_USB_EP_LQ_S
value|8
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* R92CU_REG_H */
end_comment

end_unit

