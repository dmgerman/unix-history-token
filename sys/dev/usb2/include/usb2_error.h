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
name|_USB2_ERROR_H_
end_ifndef

begin_define
define|#
directive|define
name|_USB2_ERROR_H_
end_define

begin_enum
enum|enum
block|{
comment|/* keep in sync with usb_errstr_table */
name|USB_ERR_NORMAL_COMPLETION
init|=
literal|0
block|,
name|USB_ERR_PENDING_REQUESTS
block|,
comment|/* 1 */
name|USB_ERR_NOT_STARTED
block|,
comment|/* 2 */
name|USB_ERR_INVAL
block|,
comment|/* 3 */
name|USB_ERR_NOMEM
block|,
comment|/* 4 */
name|USB_ERR_CANCELLED
block|,
comment|/* 5 */
name|USB_ERR_BAD_ADDRESS
block|,
comment|/* 6 */
name|USB_ERR_BAD_BUFSIZE
block|,
comment|/* 7 */
name|USB_ERR_BAD_FLAG
block|,
comment|/* 8 */
name|USB_ERR_NO_CALLBACK
block|,
comment|/* 9 */
name|USB_ERR_IN_USE
block|,
comment|/* 10 */
name|USB_ERR_NO_ADDR
block|,
comment|/* 11 */
name|USB_ERR_NO_PIPE
block|,
comment|/* 12 */
name|USB_ERR_ZERO_NFRAMES
block|,
comment|/* 13 */
name|USB_ERR_ZERO_MAXP
block|,
comment|/* 14 */
name|USB_ERR_SET_ADDR_FAILED
block|,
comment|/* 15 */
name|USB_ERR_NO_POWER
block|,
comment|/* 16 */
name|USB_ERR_TOO_DEEP
block|,
comment|/* 17 */
name|USB_ERR_IOERROR
block|,
comment|/* 18 */
name|USB_ERR_NOT_CONFIGURED
block|,
comment|/* 19 */
name|USB_ERR_TIMEOUT
block|,
comment|/* 20 */
name|USB_ERR_SHORT_XFER
block|,
comment|/* 21 */
name|USB_ERR_STALLED
block|,
comment|/* 22 */
name|USB_ERR_INTERRUPTED
block|,
comment|/* 23 */
name|USB_ERR_DMA_LOAD_FAILED
block|,
comment|/* 24 */
name|USB_ERR_BAD_CONTEXT
block|,
comment|/* 25 */
name|USB_ERR_NO_ROOT_HUB
block|,
comment|/* 26 */
name|USB_ERR_NO_INTR_THREAD
block|,
comment|/* 27 */
name|USB_ERR_NOT_LOCKED
block|,
comment|/* 28 */
name|USB_ERR_MAX
block|}
enum|;
end_enum

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _USB2_ERROR_H_ */
end_comment

end_unit

