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
name|_USB_DYNAMIC_H_
end_ifndef

begin_define
define|#
directive|define
name|_USB_DYNAMIC_H_
end_define

begin_comment
comment|/* prototypes */
end_comment

begin_struct_decl
struct_decl|struct
name|usb_device
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|usbd_lookup_info
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|usb_device_request
struct_decl|;
end_struct_decl

begin_comment
comment|/* typedefs */
end_comment

begin_typedef
typedef|typedef
name|usb_error_t
function_decl|(
name|usb_temp_setup_by_index_t
function_decl|)
parameter_list|(
name|struct
name|usb_device
modifier|*
name|udev
parameter_list|,
name|uint16_t
name|index
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|uint8_t
function_decl|(
name|usb_test_quirk_t
function_decl|)
parameter_list|(
specifier|const
name|struct
name|usbd_lookup_info
modifier|*
name|info
parameter_list|,
name|uint16_t
name|quirk
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
name|usb_quirk_ioctl_t
function_decl|)
parameter_list|(
name|unsigned
name|long
name|cmd
parameter_list|,
name|caddr_t
name|data
parameter_list|,
name|int
name|fflag
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
name|usb_temp_unsetup_t
function_decl|)
parameter_list|(
name|struct
name|usb_device
modifier|*
name|udev
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* global function pointers */
end_comment

begin_decl_stmt
specifier|extern
name|usb_handle_req_t
modifier|*
name|usb_temp_get_desc_p
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|usb_temp_setup_by_index_t
modifier|*
name|usb_temp_setup_by_index_p
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|usb_temp_unsetup_t
modifier|*
name|usb_temp_unsetup_p
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|usb_test_quirk_t
modifier|*
name|usb_test_quirk_p
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|usb_quirk_ioctl_t
modifier|*
name|usb_quirk_ioctl_p
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|devclass_t
name|usb_devclass_ptr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* function prototypes */
end_comment

begin_function_decl
name|void
name|usb_temp_unload
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usb_quirk_unload
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usb_bus_unload
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _USB_DYNAMIC_H_ */
end_comment

end_unit

