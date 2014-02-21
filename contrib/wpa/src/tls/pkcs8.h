begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * PKCS #8 (Private-key information syntax)  * Copyright (c) 2006-2009, Jouni Malinen<j@w1.fi>  *  * This software may be distributed under the terms of the BSD license.  * See README for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PKCS8_H
end_ifndef

begin_define
define|#
directive|define
name|PKCS8_H
end_define

begin_function_decl
name|struct
name|crypto_private_key
modifier|*
name|pkcs8_key_import
parameter_list|(
specifier|const
name|u8
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|crypto_private_key
modifier|*
name|pkcs8_enc_key_import
parameter_list|(
specifier|const
name|u8
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|,
specifier|const
name|char
modifier|*
name|passwd
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PKCS8_H */
end_comment

end_unit

