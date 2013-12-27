begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * PKCS #1 (RSA Encryption)  * Copyright (c) 2006-2009, Jouni Malinen<j@w1.fi>  *  * This software may be distributed under the terms of the BSD license.  * See README for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PKCS1_H
end_ifndef

begin_define
define|#
directive|define
name|PKCS1_H
end_define

begin_function_decl
name|int
name|pkcs1_encrypt
parameter_list|(
name|int
name|block_type
parameter_list|,
name|struct
name|crypto_rsa_key
modifier|*
name|key
parameter_list|,
name|int
name|use_private
parameter_list|,
specifier|const
name|u8
modifier|*
name|in
parameter_list|,
name|size_t
name|inlen
parameter_list|,
name|u8
modifier|*
name|out
parameter_list|,
name|size_t
modifier|*
name|outlen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pkcs1_v15_private_key_decrypt
parameter_list|(
name|struct
name|crypto_rsa_key
modifier|*
name|key
parameter_list|,
specifier|const
name|u8
modifier|*
name|in
parameter_list|,
name|size_t
name|inlen
parameter_list|,
name|u8
modifier|*
name|out
parameter_list|,
name|size_t
modifier|*
name|outlen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pkcs1_decrypt_public_key
parameter_list|(
name|struct
name|crypto_rsa_key
modifier|*
name|key
parameter_list|,
specifier|const
name|u8
modifier|*
name|crypt
parameter_list|,
name|size_t
name|crypt_len
parameter_list|,
name|u8
modifier|*
name|plain
parameter_list|,
name|size_t
modifier|*
name|plain_len
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PKCS1_H */
end_comment

end_unit

