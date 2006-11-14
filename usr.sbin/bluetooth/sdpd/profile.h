begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * profile.h  *  * Copyright (c) 2004 Maksim Yevmenkin<m_evmenkin@yahoo.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Id: profile.h,v 1.6 2004/01/13 19:31:54 max Exp $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PROFILE_H_
end_ifndef

begin_define
define|#
directive|define
name|_PROFILE_H_
end_define

begin_comment
comment|/*  * Attribute descriptor  */
end_comment

begin_typedef
typedef|typedef
name|int32_t
function_decl|(
name|profile_attr_create_t
function_decl|)
parameter_list|(
name|uint8_t
modifier|*
name|buf
parameter_list|,
name|uint8_t
specifier|const
modifier|*
specifier|const
name|eob
parameter_list|,
name|uint8_t
specifier|const
modifier|*
name|data
parameter_list|,
name|uint32_t
name|datalen
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|profile_attr_create_t
modifier|*
name|profile_attr_create_p
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int32_t
function_decl|(
name|profile_data_valid_t
function_decl|)
parameter_list|(
name|uint8_t
specifier|const
modifier|*
name|data
parameter_list|,
name|uint32_t
name|datalen
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|profile_data_valid_t
modifier|*
name|profile_data_valid_p
typedef|;
end_typedef

begin_struct
struct|struct
name|attr
block|{
name|uint16_t
name|attr
decl_stmt|;
comment|/* attribute id */
name|profile_attr_create_p
name|create
decl_stmt|;
comment|/* create attr value */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|attr
name|attr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|attr
modifier|*
name|attr_p
typedef|;
end_typedef

begin_comment
comment|/*  * Profile descriptor  */
end_comment

begin_struct
struct|struct
name|profile
block|{
name|uint16_t
name|uuid
decl_stmt|;
comment|/* profile uuid */
name|uint16_t
name|dsize
decl_stmt|;
comment|/* profile data size */
name|profile_data_valid_p
name|valid
decl_stmt|;
comment|/* profile data validator */
name|attr_t
specifier|const
modifier|*
specifier|const
name|attrs
decl_stmt|;
comment|/* supported attributes */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|profile
name|profile_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|profile
modifier|*
name|profile_p
typedef|;
end_typedef

begin_function_decl
name|profile_p
name|profile_get_descriptor
parameter_list|(
name|uint16_t
name|uuid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|profile_attr_create_p
name|profile_get_attr
parameter_list|(
specifier|const
name|profile_p
name|profile
parameter_list|,
name|uint16_t
name|attr
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|profile_attr_create_t
name|common_profile_create_service_record_handle
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|profile_attr_create_t
name|common_profile_create_service_class_id_list
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|profile_attr_create_t
name|common_profile_create_bluetooth_profile_descriptor_list
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|profile_attr_create_t
name|common_profile_create_language_base_attribute_id_list
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|profile_attr_create_t
name|common_profile_create_service_provider_name
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|profile_attr_create_t
name|common_profile_create_string8
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|profile_attr_create_t
name|rfcomm_profile_create_protocol_descriptor_list
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|profile_attr_create_t
name|obex_profile_create_protocol_descriptor_list
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|profile_attr_create_t
name|obex_profile_create_supported_formats_list
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|profile_data_valid_t
name|common_profile_server_channel_valid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|profile_data_valid_t
name|obex_profile_data_valid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ndef _PROFILE_H_ */
end_comment

end_unit

