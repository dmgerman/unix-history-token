begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * AES functions  * Copyright (c) 2003-2006, Jouni Malinen<j@w1.fi>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * Alternatively, this software may be distributed under the terms of BSD  * license.  *  * See README and COPYING for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|AES_H
end_ifndef

begin_define
define|#
directive|define
name|AES_H
end_define

begin_function_decl
name|void
modifier|*
name|aes_encrypt_init
parameter_list|(
specifier|const
name|u8
modifier|*
name|key
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|aes_encrypt
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|,
specifier|const
name|u8
modifier|*
name|plain
parameter_list|,
name|u8
modifier|*
name|crypt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|aes_encrypt_deinit
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|aes_decrypt_init
parameter_list|(
specifier|const
name|u8
modifier|*
name|key
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|aes_decrypt
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|,
specifier|const
name|u8
modifier|*
name|crypt
parameter_list|,
name|u8
modifier|*
name|plain
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|aes_decrypt_deinit
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AES_H */
end_comment

end_unit

