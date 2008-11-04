begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2008 Hans Petter Selasky. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_USB2_QUIRK_H_
end_ifndef

begin_define
define|#
directive|define
name|_USB2_QUIRK_H_
end_define

begin_comment
comment|/* NOTE: UQ_NONE is not a valid quirk */
end_comment

begin_define
define|#
directive|define
name|USB_QUIRK
parameter_list|(
name|m
parameter_list|,
name|n
parameter_list|)
define|\
value|m(n, UQ_NONE)						\
comment|/* left and right sound channels are swapped */
value|\   m(n, UQ_AUDIO_SWAP_LR)				\
comment|/* input is async despite claim of adaptive */
value|\   m(n, UQ_AU_INP_ASYNC)					\
comment|/* don't adjust for fractional samples */
value|\   m(n, UQ_AU_NO_FRAC)					\
comment|/* audio device has broken extension unit */
value|\   m(n, UQ_AU_NO_XU)					\
comment|/* bad audio spec version number */
value|\   m(n, UQ_BAD_ADC)					\
comment|/* device claims audio class, but isn't */
value|\   m(n, UQ_BAD_AUDIO)					\
comment|/* printer has broken bidir mode */
value|\   m(n, UQ_BROKEN_BIDIR)					\
comment|/* device is bus powered, despite claim */
value|\   m(n, UQ_BUS_POWERED)					\
comment|/* device should be ignored by hid class */
value|\   m(n, UQ_HID_IGNORE)					\
comment|/* device should be ignored by kbd class */
value|\   m(n, UQ_KBD_IGNORE)					\
comment|/* doesn't identify properly */
value|\   m(n, UQ_MS_BAD_CLASS)					\
comment|/* mouse sends an unknown leading byte */
value|\   m(n, UQ_MS_LEADING_BYTE)				\
comment|/* mouse has Z-axis reversed */
value|\   m(n, UQ_MS_REVZ)					\
comment|/* string descriptors are broken */
value|\   m(n, UQ_NO_STRINGS)					\
comment|/* device needs clear endpoint stall */
value|\   m(n, UQ_OPEN_CLEARSTALL)				\
comment|/* hub lies about power status */
value|\   m(n, UQ_POWER_CLAIM)					\
comment|/* spurious mouse button up events */
value|\   m(n, UQ_SPUR_BUT_UP)					\
comment|/* has some Unicode strings swapped */
value|\   m(n, UQ_SWAP_UNICODE)					\
comment|/* select configuration index 1 by default */
value|\   m(n, UQ_CFG_INDEX_1)					\
comment|/* select configuration index 2 by default */
value|\   m(n, UQ_CFG_INDEX_2)					\
comment|/* select configuration index 3 by default */
value|\   m(n, UQ_CFG_INDEX_3)					\
comment|/* select configuration index 4 by default */
value|\   m(n, UQ_CFG_INDEX_4)					\
comment|/* select configuration index 0 by default */
value|\   m(n, UQ_CFG_INDEX_0)
end_define

begin_expr_stmt
name|USB_MAKE_ENUM
argument_list|(
name|USB_QUIRK
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _USB2_QUIRK_H_ */
end_comment

end_unit

