begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * EAP common peer/server definitions  * Copyright (c) 2004-2012, Jouni Malinen<j@w1.fi>  *  * This software may be distributed under the terms of the BSD license.  * See README for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|EAP_COMMON_H
end_ifndef

begin_define
define|#
directive|define
name|EAP_COMMON_H
end_define

begin_include
include|#
directive|include
file|"wpabuf.h"
end_include

begin_function_decl
name|int
name|eap_hdr_len_valid
parameter_list|(
specifier|const
name|struct
name|wpabuf
modifier|*
name|msg
parameter_list|,
name|size_t
name|min_payload
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|u8
modifier|*
name|eap_hdr_validate
parameter_list|(
name|int
name|vendor
parameter_list|,
name|EapType
name|eap_type
parameter_list|,
specifier|const
name|struct
name|wpabuf
modifier|*
name|msg
parameter_list|,
name|size_t
modifier|*
name|plen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|wpabuf
modifier|*
name|eap_msg_alloc
parameter_list|(
name|int
name|vendor
parameter_list|,
name|EapType
name|type
parameter_list|,
name|size_t
name|payload_len
parameter_list|,
name|u8
name|code
parameter_list|,
name|u8
name|identifier
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|eap_update_len
parameter_list|(
name|struct
name|wpabuf
modifier|*
name|msg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u8
name|eap_get_id
parameter_list|(
specifier|const
name|struct
name|wpabuf
modifier|*
name|msg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|EapType
name|eap_get_type
parameter_list|(
specifier|const
name|struct
name|wpabuf
modifier|*
name|msg
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EAP_COMMON_H */
end_comment

end_unit

