begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2008 Hans Petter Selasky. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* This file contains various macro functions. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_USB2_MFUNC_H_
end_ifndef

begin_define
define|#
directive|define
name|_USB2_MFUNC_H_
end_define

begin_define
define|#
directive|define
name|USB_LOG2
parameter_list|(
name|n
parameter_list|)
value|(	    \ ((x)<= (1<<0x00)) ? 0x00 : \ ((x)<= (1<<0x01)) ? 0x01 : \ ((x)<= (1<<0x02)) ? 0x02 : \ ((x)<= (1<<0x03)) ? 0x03 : \ ((x)<= (1<<0x04)) ? 0x04 : \ ((x)<= (1<<0x05)) ? 0x05 : \ ((x)<= (1<<0x06)) ? 0x06 : \ ((x)<= (1<<0x07)) ? 0x07 : \ ((x)<= (1<<0x08)) ? 0x08 : \ ((x)<= (1<<0x09)) ? 0x09 : \ ((x)<= (1<<0x0A)) ? 0x0A : \ ((x)<= (1<<0x0B)) ? 0x0B : \ ((x)<= (1<<0x0C)) ? 0x0C : \ ((x)<= (1<<0x0D)) ? 0x0D : \ ((x)<= (1<<0x0E)) ? 0x0E : \ ((x)<= (1<<0x0F)) ? 0x0F : \ ((x)<= (1<<0x10)) ? 0x10 : \ ((x)<= (1<<0x11)) ? 0x11 : \ ((x)<= (1<<0x12)) ? 0x12 : \ ((x)<= (1<<0x13)) ? 0x13 : \ ((x)<= (1<<0x14)) ? 0x14 : \ ((x)<= (1<<0x15)) ? 0x15 : \ ((x)<= (1<<0x16)) ? 0x16 : \ ((x)<= (1<<0x17)) ? 0x17 : \ ((x)<= (1<<0x18)) ? 0x18 : \ ((x)<= (1<<0x19)) ? 0x19 : \ ((x)<= (1<<0x1A)) ? 0x1A : \ ((x)<= (1<<0x1B)) ? 0x1B : \ ((x)<= (1<<0x1C)) ? 0x1C : \ ((x)<= (1<<0x1D)) ? 0x1D : \ ((x)<= (1<<0x1E)) ? 0x1E : \ 0x1F)
end_define

begin_comment
comment|/* helper for converting pointers to integers */
end_comment

begin_define
define|#
directive|define
name|USB_P2U
parameter_list|(
name|ptr
parameter_list|)
define|\
value|(((const uint8_t *)(ptr)) - ((const uint8_t *)0))
end_define

begin_comment
comment|/* helper for computing offsets */
end_comment

begin_define
define|#
directive|define
name|USB_ADD_BYTES
parameter_list|(
name|ptr
parameter_list|,
name|size
parameter_list|)
define|\
value|((void *)(USB_P2U(ptr) + (size)))
end_define

begin_comment
comment|/* debug macro */
end_comment

begin_define
define|#
directive|define
name|USB_ASSERT
value|KASSERT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _USB2_MFUNC_H_ */
end_comment

end_unit

