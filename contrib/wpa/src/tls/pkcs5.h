begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * PKCS #5 (Password-based Encryption)  * Copyright (c) 2009, Jouni Malinen<j@w1.fi>  *  * This software may be distributed under the terms of the BSD license.  * See README for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PKCS5_H
end_ifndef

begin_define
define|#
directive|define
name|PKCS5_H
end_define

begin_function_decl
name|u8
modifier|*
name|pkcs5_decrypt
parameter_list|(
specifier|const
name|u8
modifier|*
name|enc_alg
parameter_list|,
name|size_t
name|enc_alg_len
parameter_list|,
specifier|const
name|u8
modifier|*
name|enc_data
parameter_list|,
name|size_t
name|enc_data_len
parameter_list|,
specifier|const
name|char
modifier|*
name|passwd
parameter_list|,
name|size_t
modifier|*
name|data_len
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PKCS5_H */
end_comment

end_unit

