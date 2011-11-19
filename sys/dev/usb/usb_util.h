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
name|_USB_UTIL_H_
end_ifndef

begin_define
define|#
directive|define
name|_USB_UTIL_H_
end_define

begin_function_decl
name|uint8_t
name|usb_make_str_desc
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|,
name|uint16_t
name|max_len
parameter_list|,
specifier|const
name|char
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usb_printbcd
parameter_list|(
name|char
modifier|*
name|p
parameter_list|,
name|uint16_t
name|p_len
parameter_list|,
name|uint16_t
name|bcd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usb_trim_spaces
parameter_list|(
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _USB_UTIL_H_ */
end_comment

end_unit

