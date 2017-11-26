begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: usbvar.h,v 1.2 1999/05/11 21:15:46 augustss Exp $	*/
end_comment

begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-2-Clause-NetBSD  *  * Copyright (c) 1999 Lennart Augustsson<augustss@netbsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_USBVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_USBVAR_H_
end_define

begin_struct
struct|struct
name|report_desc
block|{
name|uint32_t
name|size
decl_stmt|;
name|uint8_t
name|data
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* internal backwards compatibility functions */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HID_COMPAT7
end_ifdef

begin_function_decl
name|int
name|hid_set_immed_compat7
parameter_list|(
name|int
name|fd
parameter_list|,
name|int
name|enable
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hid_get_report_id_compat7
parameter_list|(
name|int
name|fd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|report_desc_t
name|hid_get_report_desc_compat7
parameter_list|(
name|int
name|fd
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|COMPAT_32BIT
end_ifdef

begin_define
define|#
directive|define
name|hid_pass_ptr
parameter_list|(
name|ptr
parameter_list|)
value|((uint64_t)(uintptr_t)(ptr))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|hid_pass_ptr
parameter_list|(
name|ptr
parameter_list|)
value|(ptr)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _USBVAR_H_ */
end_comment

end_unit

