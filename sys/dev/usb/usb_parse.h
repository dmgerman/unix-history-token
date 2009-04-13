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
name|_USB2_PARSE_H_
end_ifndef

begin_define
define|#
directive|define
name|_USB2_PARSE_H_
end_define

begin_comment
comment|/* structures */
end_comment

begin_struct
struct|struct
name|usb2_idesc_parse_state
block|{
name|struct
name|usb2_descriptor
modifier|*
name|desc
decl_stmt|;
name|uint8_t
name|iface_index
decl_stmt|;
comment|/* current interface index */
name|uint8_t
name|iface_no_last
decl_stmt|;
name|uint8_t
name|iface_index_alt
decl_stmt|;
comment|/* current alternate setting */
block|}
struct|;
end_struct

begin_comment
comment|/* prototypes */
end_comment

begin_function_decl
name|struct
name|usb2_descriptor
modifier|*
name|usb2_desc_foreach
parameter_list|(
name|struct
name|usb2_config_descriptor
modifier|*
name|cd
parameter_list|,
name|struct
name|usb2_descriptor
modifier|*
name|desc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|usb2_interface_descriptor
modifier|*
name|usb2_idesc_foreach
parameter_list|(
name|struct
name|usb2_config_descriptor
modifier|*
name|cd
parameter_list|,
name|struct
name|usb2_idesc_parse_state
modifier|*
name|ps
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|usb2_endpoint_descriptor
modifier|*
name|usb2_edesc_foreach
parameter_list|(
name|struct
name|usb2_config_descriptor
modifier|*
name|cd
parameter_list|,
name|struct
name|usb2_endpoint_descriptor
modifier|*
name|ped
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint8_t
name|usb2_get_no_descriptors
parameter_list|(
name|struct
name|usb2_config_descriptor
modifier|*
name|cd
parameter_list|,
name|uint8_t
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint8_t
name|usb2_get_no_alts
parameter_list|(
name|struct
name|usb2_config_descriptor
modifier|*
name|cd
parameter_list|,
name|struct
name|usb2_interface_descriptor
modifier|*
name|id
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _USB2_PARSE_H_ */
end_comment

end_unit

