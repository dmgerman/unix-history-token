begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * RSA  * Copyright (c) 2006, Jouni Malinen<j@w1.fi>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * Alternatively, this software may be distributed under the terms of BSD  * license.  *  * See README and COPYING for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|RSA_H
end_ifndef

begin_define
define|#
directive|define
name|RSA_H
end_define

begin_struct_decl
struct_decl|struct
name|crypto_rsa_key
struct_decl|;
end_struct_decl

begin_function_decl
name|struct
name|crypto_rsa_key
modifier|*
name|crypto_rsa_import_public_key
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
name|crypto_rsa_key
modifier|*
name|crypto_rsa_import_private_key
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
name|size_t
name|crypto_rsa_get_modulus_len
parameter_list|(
name|struct
name|crypto_rsa_key
modifier|*
name|key
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|crypto_rsa_exptmod
parameter_list|(
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
parameter_list|,
name|struct
name|crypto_rsa_key
modifier|*
name|key
parameter_list|,
name|int
name|use_private
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|crypto_rsa_free
parameter_list|(
name|struct
name|crypto_rsa_key
modifier|*
name|key
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* RSA_H */
end_comment

end_unit

