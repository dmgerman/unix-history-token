begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CHAP-MD5 (RFC 1994)  * Copyright (c) 2007-2009, Jouni Malinen<j@w1.fi>  *  * This software may be distributed under the terms of the BSD license.  * See README for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CHAP_H
end_ifndef

begin_define
define|#
directive|define
name|CHAP_H
end_define

begin_define
define|#
directive|define
name|CHAP_MD5_LEN
value|16
end_define

begin_function_decl
name|int
name|chap_md5
parameter_list|(
name|u8
name|id
parameter_list|,
specifier|const
name|u8
modifier|*
name|secret
parameter_list|,
name|size_t
name|secret_len
parameter_list|,
specifier|const
name|u8
modifier|*
name|challenge
parameter_list|,
name|size_t
name|challenge_len
parameter_list|,
name|u8
modifier|*
name|response
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CHAP_H */
end_comment

end_unit

