begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * MSCHAPV2 (RFC 2759)  * Copyright (c) 2004-2008, Jouni Malinen<j@w1.fi>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * Alternatively, this software may be distributed under the terms of BSD  * license.  *  * See README and COPYING for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MSCHAPV2_H
end_ifndef

begin_define
define|#
directive|define
name|MSCHAPV2_H
end_define

begin_define
define|#
directive|define
name|MSCHAPV2_CHAL_LEN
value|16
end_define

begin_define
define|#
directive|define
name|MSCHAPV2_NT_RESPONSE_LEN
value|24
end_define

begin_define
define|#
directive|define
name|MSCHAPV2_AUTH_RESPONSE_LEN
value|20
end_define

begin_define
define|#
directive|define
name|MSCHAPV2_MASTER_KEY_LEN
value|16
end_define

begin_function_decl
specifier|const
name|u8
modifier|*
name|mschapv2_remove_domain
parameter_list|(
specifier|const
name|u8
modifier|*
name|username
parameter_list|,
name|size_t
modifier|*
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mschapv2_derive_response
parameter_list|(
specifier|const
name|u8
modifier|*
name|username
parameter_list|,
name|size_t
name|username_len
parameter_list|,
specifier|const
name|u8
modifier|*
name|password
parameter_list|,
name|size_t
name|password_len
parameter_list|,
name|int
name|pwhash
parameter_list|,
specifier|const
name|u8
modifier|*
name|auth_challenge
parameter_list|,
specifier|const
name|u8
modifier|*
name|peer_challenge
parameter_list|,
name|u8
modifier|*
name|nt_response
parameter_list|,
name|u8
modifier|*
name|auth_response
parameter_list|,
name|u8
modifier|*
name|master_key
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mschapv2_verify_auth_response
parameter_list|(
specifier|const
name|u8
modifier|*
name|auth_response
parameter_list|,
specifier|const
name|u8
modifier|*
name|buf
parameter_list|,
name|size_t
name|buf_len
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MSCHAPV2_H */
end_comment

end_unit

