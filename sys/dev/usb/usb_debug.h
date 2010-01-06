begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2008 Hans Petter Selasky. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* This file contains various factored out debug macros. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_USB_DEBUG_H_
end_ifndef

begin_define
define|#
directive|define
name|_USB_DEBUG_H_
end_define

begin_comment
comment|/* Declare global USB debug variable. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|usb_debug
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Check if USB debugging is enabled. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|USB_DEBUG_VAR
end_ifdef

begin_if
if|#
directive|if
operator|(
name|USB_DEBUG
operator|!=
literal|0
operator|)
end_if

begin_define
define|#
directive|define
name|DPRINTFN
parameter_list|(
name|n
parameter_list|,
name|fmt
parameter_list|,
modifier|...
parameter_list|)
value|do {		\   if ((USB_DEBUG_VAR)>= (n)) {			\     printf("%s: " fmt,				\ 	   __FUNCTION__,## __VA_ARGS__);	\   }						\ } while (0)
end_define

begin_define
define|#
directive|define
name|DPRINTF
parameter_list|(
modifier|...
parameter_list|)
value|DPRINTFN(1, __VA_ARGS__)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DPRINTF
parameter_list|(
modifier|...
parameter_list|)
value|do { } while (0)
end_define

begin_define
define|#
directive|define
name|DPRINTFN
parameter_list|(
modifier|...
parameter_list|)
value|do { } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_struct_decl
struct_decl|struct
name|usb_interface
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|usb_device
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|usb_endpoint
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|usb_xfer
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|usb_dump_iface
parameter_list|(
name|struct
name|usb_interface
modifier|*
name|iface
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usb_dump_device
parameter_list|(
name|struct
name|usb_device
modifier|*
name|udev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usb_dump_queue
parameter_list|(
name|struct
name|usb_endpoint
modifier|*
name|ep
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usb_dump_endpoint
parameter_list|(
name|struct
name|usb_endpoint
modifier|*
name|ep
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usb_dump_xfer
parameter_list|(
name|struct
name|usb_xfer
modifier|*
name|xfer
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _USB_DEBUG_H_ */
end_comment

end_unit

