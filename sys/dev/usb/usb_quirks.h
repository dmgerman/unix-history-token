begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: usb_quirks.h,v 1.7 1999/06/26 00:09:15 augustss Exp $	*/
end_comment

begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1998 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Lennart Augustsson (augustss@carlstedt.se) at  * Carlstedt Research& Technology.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *        This product includes software developed by the NetBSD  *        Foundation, Inc. and its contributors.  * 4. Neither the name of The NetBSD Foundation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
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
value|0x01
comment|/* cannot handle SET PROTOCOL. */
define|#
directive|define
name|UQ_SWAP_UNICODE
value|0x02
comment|/* has some Unicode strings swapped. */
define|#
directive|define
name|UQ_MS_REVZ
value|0x04
comment|/* mouse has Z-axis reversed */
define|#
directive|define
name|UQ_NO_STRINGS
value|0x08
comment|/* string descriptors are broken. */
define|#
directive|define
name|UQ_BAD_ADC
value|0x10
comment|/* bad audio spec version number. */
define|#
directive|define
name|UQ_BUS_POWERED
value|0x20
comment|/* device is bus powered, despite claim */
define|#
directive|define
name|UQ_SPUR_BUT_UP
value|0x40
comment|/* spurious mouse button up events */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|usbd_quirks
name|usbd_no_quirk
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|usbd_quirks
modifier|*
name|usbd_find_quirk
name|__P
argument_list|(
operator|(
name|usb_device_descriptor_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

