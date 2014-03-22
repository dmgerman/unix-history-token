begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $OpenBSD: hmac.h,v 1.6 2014/01/27 18:58:14 markus Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2014 Markus Friedl.  All rights reserved.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_HMAC_H
end_ifndef

begin_define
define|#
directive|define
name|_HMAC_H
end_define

begin_comment
comment|/* Returns the algorithm's digest length in bytes or 0 for invalid algorithm */
end_comment

begin_function_decl
name|size_t
name|ssh_hmac_bytes
parameter_list|(
name|int
name|alg
parameter_list|)
function_decl|;
end_function_decl

begin_struct_decl
struct_decl|struct
name|ssh_hmac_ctx
struct_decl|;
end_struct_decl

begin_function_decl
name|struct
name|ssh_hmac_ctx
modifier|*
name|ssh_hmac_start
parameter_list|(
name|int
name|alg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Sets the state of the HMAC or resets the state if key == NULL */
end_comment

begin_function_decl
name|int
name|ssh_hmac_init
parameter_list|(
name|struct
name|ssh_hmac_ctx
modifier|*
name|ctx
parameter_list|,
specifier|const
name|void
modifier|*
name|key
parameter_list|,
name|size_t
name|klen
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
name|ssh_hmac_update
parameter_list|(
name|struct
name|ssh_hmac_ctx
modifier|*
name|ctx
parameter_list|,
specifier|const
name|void
modifier|*
name|m
parameter_list|,
name|size_t
name|mlen
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
name|ssh_hmac_update_buffer
parameter_list|(
name|struct
name|ssh_hmac_ctx
modifier|*
name|ctx
parameter_list|,
specifier|const
name|Buffer
modifier|*
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssh_hmac_final
parameter_list|(
name|struct
name|ssh_hmac_ctx
modifier|*
name|ctx
parameter_list|,
name|u_char
modifier|*
name|d
parameter_list|,
name|size_t
name|dlen
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
name|void
name|ssh_hmac_free
parameter_list|(
name|struct
name|ssh_hmac_ctx
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
comment|/* _HMAC_H */
end_comment

end_unit

