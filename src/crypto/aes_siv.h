begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * AES SIV (RFC 5297)  * Copyright (c) 2013 Cozybit, Inc.  *  * This software may be distributed under the terms of the BSD license.  * See README for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|AES_SIV_H
end_ifndef

begin_define
define|#
directive|define
name|AES_SIV_H
end_define

begin_function_decl
name|int
name|aes_siv_encrypt
parameter_list|(
specifier|const
name|u8
modifier|*
name|key
parameter_list|,
specifier|const
name|u8
modifier|*
name|pw
parameter_list|,
name|size_t
name|pwlen
parameter_list|,
name|size_t
name|num_elem
parameter_list|,
specifier|const
name|u8
modifier|*
name|addr
index|[]
parameter_list|,
specifier|const
name|size_t
modifier|*
name|len
parameter_list|,
name|u8
modifier|*
name|out
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|aes_siv_decrypt
parameter_list|(
specifier|const
name|u8
modifier|*
name|key
parameter_list|,
specifier|const
name|u8
modifier|*
name|iv_crypt
parameter_list|,
name|size_t
name|iv_c_len
parameter_list|,
name|size_t
name|num_elem
parameter_list|,
specifier|const
name|u8
modifier|*
name|addr
index|[]
parameter_list|,
specifier|const
name|size_t
modifier|*
name|len
parameter_list|,
name|u8
modifier|*
name|out
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AES_SIV_H */
end_comment

end_unit

