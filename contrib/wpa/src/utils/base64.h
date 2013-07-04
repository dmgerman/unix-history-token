begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Base64 encoding/decoding (RFC1341)  * Copyright (c) 2005, Jouni Malinen<j@w1.fi>  *  * This software may be distributed under the terms of the BSD license.  * See README for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BASE64_H
end_ifndef

begin_define
define|#
directive|define
name|BASE64_H
end_define

begin_function_decl
name|unsigned
name|char
modifier|*
name|base64_encode
parameter_list|(
specifier|const
name|unsigned
name|char
modifier|*
name|src
parameter_list|,
name|size_t
name|len
parameter_list|,
name|size_t
modifier|*
name|out_len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|char
modifier|*
name|base64_decode
parameter_list|(
specifier|const
name|unsigned
name|char
modifier|*
name|src
parameter_list|,
name|size_t
name|len
parameter_list|,
name|size_t
modifier|*
name|out_len
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BASE64_H */
end_comment

end_unit

