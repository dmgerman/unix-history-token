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

begin_enum
enum|enum
block|{
name|UQ_NONE
block|,
name|UQ_AUDIO_SWAP_LR
block|,
comment|/* left and right sound channels are swapped */
name|UQ_AU_INP_ASYNC
block|,
comment|/* input is async despite claim of adaptive */
name|UQ_AU_NO_FRAC
block|,
comment|/* don't adjust for fractional samples */
name|UQ_AU_NO_XU
block|,
comment|/* audio device has broken extension unit */
name|UQ_BAD_ADC
block|,
comment|/* bad audio spec version number */
name|UQ_BAD_AUDIO
block|,
comment|/* device claims audio class, but isn't */
name|UQ_BROKEN_BIDIR
block|,
comment|/* printer has broken bidir mode */
name|UQ_BUS_POWERED
block|,
comment|/* device is bus powered, despite claim */
name|UQ_HID_IGNORE
block|,
comment|/* device should be ignored by hid class */
name|UQ_KBD_IGNORE
block|,
comment|/* device should be ignored by kbd class */
name|UQ_MS_BAD_CLASS
block|,
comment|/* doesn't identify properly */
name|UQ_MS_LEADING_BYTE
block|,
comment|/* mouse sends an unknown leading byte */
name|UQ_MS_REVZ
block|,
comment|/* mouse has Z-axis reversed */
name|UQ_NO_STRINGS
block|,
comment|/* string descriptors are broken */
name|UQ_OPEN_CLEARSTALL
block|,
comment|/* device needs clear endpoint stall */
name|UQ_POWER_CLAIM
block|,
comment|/* hub lies about power status */
name|UQ_SPUR_BUT_UP
block|,
comment|/* spurious mouse button up events */
name|UQ_SWAP_UNICODE
block|,
comment|/* has some Unicode strings swapped */
name|UQ_CFG_INDEX_1
block|,
comment|/* select configuration index 1 by default */
name|UQ_CFG_INDEX_2
block|,
comment|/* select configuration index 2 by default */
name|UQ_CFG_INDEX_3
block|,
comment|/* select configuration index 3 by default */
name|UQ_CFG_INDEX_4
block|,
comment|/* select configuration index 4 by default */
name|UQ_CFG_INDEX_0
block|,
comment|/* select configuration index 0 by default */
name|USB_QUIRK_MAX
block|}
enum|;
end_enum

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _USB2_QUIRK_H_ */
end_comment

end_unit

