begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $OpenBSD: cipher-chachapoly.h,v 1.1 2013/11/21 00:45:44 djm Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) Damien Miller 2013<djm@mindrot.org>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CHACHA_POLY_AEAD_H
end_ifndef

begin_define
define|#
directive|define
name|CHACHA_POLY_AEAD_H
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|"chacha.h"
end_include

begin_include
include|#
directive|include
file|"poly1305.h"
end_include

begin_define
define|#
directive|define
name|CHACHA_KEYLEN
value|32
end_define

begin_comment
comment|/* Only 256 bit keys used here */
end_comment

begin_struct
struct|struct
name|chachapoly_ctx
block|{
name|struct
name|chacha_ctx
name|main_ctx
decl_stmt|,
name|header_ctx
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|chachapoly_init
parameter_list|(
name|struct
name|chachapoly_ctx
modifier|*
name|cpctx
parameter_list|,
specifier|const
name|u_char
modifier|*
name|key
parameter_list|,
name|u_int
name|keylen
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__bounded__
parameter_list|(
name|__buffer__
parameter_list|,
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|int
name|chachapoly_crypt
parameter_list|(
name|struct
name|chachapoly_ctx
modifier|*
name|cpctx
parameter_list|,
name|u_int
name|seqnr
parameter_list|,
name|u_char
modifier|*
name|dest
parameter_list|,
specifier|const
name|u_char
modifier|*
name|src
parameter_list|,
name|u_int
name|len
parameter_list|,
name|u_int
name|aadlen
parameter_list|,
name|u_int
name|authlen
parameter_list|,
name|int
name|do_encrypt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|chachapoly_get_length
parameter_list|(
name|struct
name|chachapoly_ctx
modifier|*
name|cpctx
parameter_list|,
name|u_int
modifier|*
name|plenp
parameter_list|,
name|u_int
name|seqnr
parameter_list|,
specifier|const
name|u_char
modifier|*
name|cp
parameter_list|,
name|u_int
name|len
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__bounded__
parameter_list|(
name|__buffer__
parameter_list|,
function_decl|4
operator|,
function_decl|5
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CHACHA_POLY_AEAD_H */
end_comment

end_unit

