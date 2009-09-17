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
name|_USB2_SW_TRANSFER_H_
end_ifndef

begin_define
define|#
directive|define
name|_USB2_SW_TRANSFER_H_
end_define

begin_comment
comment|/* Software transfer function state argument values */
end_comment

begin_enum
enum|enum
block|{
name|USB_SW_TR_SETUP
block|,
name|USB_SW_TR_STATUS
block|,
name|USB_SW_TR_PRE_DATA
block|,
name|USB_SW_TR_POST_DATA
block|,
name|USB_SW_TR_PRE_CALLBACK
block|, }
enum|;
end_enum

begin_struct_decl
struct_decl|struct
name|usb2_sw_transfer
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|void
function_decl|(
name|usb2_sw_transfer_func_t
function_decl|)
parameter_list|(
name|struct
name|usb2_xfer
modifier|*
parameter_list|,
name|struct
name|usb2_sw_transfer
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * The following structure is used to keep the state of a standard  * root transfer.  */
end_comment

begin_struct
struct|struct
name|usb2_sw_transfer
block|{
name|struct
name|usb2_device_request
name|req
decl_stmt|;
name|struct
name|usb2_xfer
modifier|*
name|xfer
decl_stmt|;
name|uint8_t
modifier|*
name|ptr
decl_stmt|;
name|uint16_t
name|len
decl_stmt|;
name|uint8_t
name|state
decl_stmt|;
name|usb2_error_t
name|err
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* prototypes */
end_comment

begin_function_decl
name|void
name|usb2_sw_transfer
parameter_list|(
name|struct
name|usb2_sw_transfer
modifier|*
name|std
parameter_list|,
name|usb2_sw_transfer_func_t
modifier|*
name|func
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _USB2_SW_TRANSFER_H_ */
end_comment

end_unit

