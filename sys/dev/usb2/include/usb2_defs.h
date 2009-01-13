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
name|_USB2_DEFS_H_
end_ifndef

begin_define
define|#
directive|define
name|_USB2_DEFS_H_
end_define

begin_comment
comment|/* Definition of some USB constants */
end_comment

begin_define
define|#
directive|define
name|USB_BUS_MAX
value|256
end_define

begin_comment
comment|/* units */
end_comment

begin_define
define|#
directive|define
name|USB_DEV_MAX
value|128
end_define

begin_comment
comment|/* units */
end_comment

begin_define
define|#
directive|define
name|USB_IFACE_MAX
value|32
end_define

begin_comment
comment|/* units */
end_comment

begin_define
define|#
directive|define
name|USB_EP_MAX
value|(2*16)
end_define

begin_comment
comment|/* hardcoded */
end_comment

begin_define
define|#
directive|define
name|USB_FIFO_MAX
value|(4 * USB_EP_MAX)
end_define

begin_define
define|#
directive|define
name|USB_MIN_DEVICES
value|2
end_define

begin_comment
comment|/* unused + root HUB */
end_comment

begin_define
define|#
directive|define
name|USB_MAX_DEVICES
value|USB_DEV_MAX
end_define

begin_comment
comment|/* including virtual root HUB and 					 * address zero */
end_comment

begin_define
define|#
directive|define
name|USB_MAX_ENDPOINTS
value|USB_EP_MAX
end_define

begin_comment
comment|/* 2 directions on 16 endpoints */
end_comment

begin_define
define|#
directive|define
name|USB_UNCONFIG_INDEX
value|0xFF
end_define

begin_comment
comment|/* internal use only */
end_comment

begin_define
define|#
directive|define
name|USB_IFACE_INDEX_ANY
value|0xFF
end_define

begin_comment
comment|/* internal use only */
end_comment

begin_define
define|#
directive|define
name|USB_START_ADDR
value|0
end_define

begin_comment
comment|/* default USB device BUS address 					 * after USB bus reset */
end_comment

begin_define
define|#
directive|define
name|USB_CONTROL_ENDPOINT
value|0
end_define

begin_comment
comment|/* default control endpoint */
end_comment

begin_define
define|#
directive|define
name|USB_FRAMES_PER_SECOND_FS
value|1000
end_define

begin_comment
comment|/* full speed */
end_comment

begin_define
define|#
directive|define
name|USB_FRAMES_PER_SECOND_HS
value|8000
end_define

begin_comment
comment|/* high speed */
end_comment

begin_define
define|#
directive|define
name|USB_FS_BYTES_PER_HS_UFRAME
value|188
end_define

begin_comment
comment|/* bytes */
end_comment

begin_define
define|#
directive|define
name|USB_HS_MICRO_FRAMES_MAX
value|8
end_define

begin_comment
comment|/* units */
end_comment

begin_comment
comment|/* sanity checks */
end_comment

begin_if
if|#
directive|if
operator|(
name|USB_FIFO_MAX
operator|<
name|USB_EP_MAX
operator|)
end_if

begin_error
error|#
directive|error
literal|"Misconfigured limits #1"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|USB_FIFO_MAX
operator|&
literal|1
operator|)
end_if

begin_error
error|#
directive|error
literal|"Misconfigured limits #2"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|USB_EP_MAX
operator|<
operator|(
literal|2
operator|*
literal|16
operator|)
operator|)
end_if

begin_error
error|#
directive|error
literal|"Misconfigured limits #3"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|USB_MAX_DEVICES
operator|<
name|USB_MIN_DEVICES
operator|)
end_if

begin_error
error|#
directive|error
literal|"Misconfigured limits #4"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _USB2_DEFS_H_ */
end_comment

end_unit

