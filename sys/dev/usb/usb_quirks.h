begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: usb_quirks.h,v 1.20 2001/04/15 09:38:01 augustss Exp $	*/
end_comment

begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 1998 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Lennart Augustsson (lennart@augustsson.net) at  * Carlstedt Research& Technology.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *        This product includes software developed by the NetBSD  *        Foundation, Inc. and its contributors.  * 4. Neither the name of The NetBSD Foundation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_struct
struct|struct
name|usbd_quirks
block|{
name|u_int32_t
name|uq_flags
decl_stmt|;
comment|/* Device problems: */
define|#
directive|define
name|UQ_NO_SET_PROTO
value|0x0001
comment|/* cannot handle SET PROTOCOL. */
define|#
directive|define
name|UQ_SWAP_UNICODE
value|0x0002
comment|/* has some Unicode strings swapped. */
define|#
directive|define
name|UQ_MS_REVZ
value|0x0004
comment|/* mouse has Z-axis reversed */
define|#
directive|define
name|UQ_NO_STRINGS
value|0x0008
comment|/* string descriptors are broken. */
define|#
directive|define
name|UQ_BAD_ADC
value|0x0010
comment|/* bad audio spec version number. */
define|#
directive|define
name|UQ_BUS_POWERED
value|0x0020
comment|/* device is bus powered, despite claim */
define|#
directive|define
name|UQ_BAD_AUDIO
value|0x0040
comment|/* device claims audio class, but isn't */
define|#
directive|define
name|UQ_SPUR_BUT_UP
value|0x0080
comment|/* spurious mouse button up events */
define|#
directive|define
name|UQ_AU_NO_XU
value|0x0100
comment|/* audio device has broken extension unit */
define|#
directive|define
name|UQ_POWER_CLAIM
value|0x0200
comment|/* hub lies about power status */
define|#
directive|define
name|UQ_AU_NO_FRAC
value|0x0400
comment|/* don't adjust for fractional samples */
define|#
directive|define
name|UQ_AU_INP_ASYNC
value|0x0800
comment|/* input is async despite claim of adaptive */
define|#
directive|define
name|UQ_ASSUME_CM_OVER_DATA
value|0x1000
comment|/* modem device breaks on cm over data */
define|#
directive|define
name|UQ_BROKEN_BIDIR
value|0x2000
comment|/* printer has broken bidir mode */
define|#
directive|define
name|UQ_OPEN_CLEARSTALL
value|0x4000
comment|/* device needs clear endpoint stall */
define|#
directive|define
name|UQ_HID_IGNORE
value|0x8000
comment|/* device should be ignored by hid class */
define|#
directive|define
name|UQ_KBD_IGNORE
value|0x18000
comment|/* device should be ignored by both kbd and hid class */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|usbd_quirks
name|usbd_no_quirk
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|const
name|struct
name|usbd_quirks
modifier|*
name|usbd_find_quirk
parameter_list|(
name|usb_device_descriptor_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

