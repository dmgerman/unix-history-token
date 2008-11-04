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
name|_USB2_REVISION_H_
end_ifndef

begin_define
define|#
directive|define
name|_USB2_REVISION_H_
end_define

begin_include
include|#
directive|include
file|<dev/usb2/include/usb2_mfunc.h>
end_include

begin_comment
comment|/*  * The "USB_SPEED" macro defines all the supported USB speeds.  */
end_comment

begin_define
define|#
directive|define
name|USB_SPEED
parameter_list|(
name|m
parameter_list|,
name|n
parameter_list|)
define|\
value|m(n, USB_SPEED_VARIABLE)\ m(n, USB_SPEED_LOW)\ m(n, USB_SPEED_FULL)\ m(n, USB_SPEED_HIGH)\ m(n, USB_SPEED_SUPER)\  USB_MAKE_ENUM(USB_SPEED);
end_define

begin_comment
comment|/*  * The "USB_REV" macro defines all the supported USB revisions.  */
end_comment

begin_define
define|#
directive|define
name|USB_REV
parameter_list|(
name|m
parameter_list|,
name|n
parameter_list|)
define|\
value|m(n, USB_REV_UNKNOWN)\ m(n, USB_REV_PRE_1_0)\ m(n, USB_REV_1_0)\ m(n, USB_REV_1_1)\ m(n, USB_REV_2_0)\ m(n, USB_REV_2_5)\ m(n, USB_REV_3_0)\  USB_MAKE_ENUM(USB_REV);
end_define

begin_comment
comment|/*  * The "USB_MODE" macro defines all the supported USB modes.  */
end_comment

begin_define
define|#
directive|define
name|USB_MODE
parameter_list|(
name|m
parameter_list|,
name|n
parameter_list|)
define|\
value|m(n, USB_MODE_HOST)\ m(n, USB_MODE_DEVICE)\  USB_MAKE_ENUM(USB_MODE);
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _USB2_REVISION_H_ */
end_comment

end_unit

