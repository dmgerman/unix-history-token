begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $OpenBSD: cipher-aesctr.h,v 1.1 2014/04/29 15:39:33 markus Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2014 Markus Friedl  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|OPENSSH_AESCTR_H
end_ifndef

begin_define
define|#
directive|define
name|OPENSSH_AESCTR_H
end_define

begin_include
include|#
directive|include
file|"rijndael.h"
end_include

begin_define
define|#
directive|define
name|AES_BLOCK_SIZE
value|16
end_define

begin_typedef
typedef|typedef
struct|struct
name|aesctr_ctx
block|{
name|int
name|rounds
decl_stmt|;
comment|/* keylen-dependent #rounds */
name|u32
name|ek
index|[
literal|4
operator|*
operator|(
name|AES_MAXROUNDS
operator|+
literal|1
operator|)
index|]
decl_stmt|;
comment|/* encrypt key schedule */
name|u8
name|ctr
index|[
name|AES_BLOCK_SIZE
index|]
decl_stmt|;
comment|/* counter */
block|}
name|aesctr_ctx
typedef|;
end_typedef

begin_function_decl
name|void
name|aesctr_keysetup
parameter_list|(
name|aesctr_ctx
modifier|*
name|x
parameter_list|,
specifier|const
name|u8
modifier|*
name|k
parameter_list|,
name|u32
name|kbits
parameter_list|,
name|u32
name|ivbits
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|aesctr_ivsetup
parameter_list|(
name|aesctr_ctx
modifier|*
name|x
parameter_list|,
specifier|const
name|u8
modifier|*
name|iv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|aesctr_encrypt_bytes
parameter_list|(
name|aesctr_ctx
modifier|*
name|x
parameter_list|,
specifier|const
name|u8
modifier|*
name|m
parameter_list|,
name|u8
modifier|*
name|c
parameter_list|,
name|u32
name|bytes
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

