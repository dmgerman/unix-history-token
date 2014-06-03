begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $OpenBSD: digest.h,v 1.2 2014/01/27 18:58:14 markus Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2013 Damien Miller<djm@mindrot.org>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DIGEST_H
end_ifndef

begin_define
define|#
directive|define
name|_DIGEST_H
end_define

begin_comment
comment|/* Maximum digest output length */
end_comment

begin_define
define|#
directive|define
name|SSH_DIGEST_MAX_LENGTH
value|64
end_define

begin_comment
comment|/* Digest algorithms */
end_comment

begin_define
define|#
directive|define
name|SSH_DIGEST_MD5
value|0
end_define

begin_define
define|#
directive|define
name|SSH_DIGEST_RIPEMD160
value|1
end_define

begin_define
define|#
directive|define
name|SSH_DIGEST_SHA1
value|2
end_define

begin_define
define|#
directive|define
name|SSH_DIGEST_SHA256
value|3
end_define

begin_define
define|#
directive|define
name|SSH_DIGEST_SHA384
value|4
end_define

begin_define
define|#
directive|define
name|SSH_DIGEST_SHA512
value|5
end_define

begin_define
define|#
directive|define
name|SSH_DIGEST_MAX
value|6
end_define

begin_struct_decl
struct_decl|struct
name|ssh_digest_ctx
struct_decl|;
end_struct_decl

begin_comment
comment|/* Returns the algorithm's digest length in bytes or 0 for invalid algorithm */
end_comment

begin_function_decl
name|size_t
name|ssh_digest_bytes
parameter_list|(
name|int
name|alg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Returns the block size of the digest, e.g. for implementing HMAC */
end_comment

begin_function_decl
name|size_t
name|ssh_digest_blocksize
parameter_list|(
name|struct
name|ssh_digest_ctx
modifier|*
name|ctx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Copies internal state of digest of 'from' to 'to' */
end_comment

begin_function_decl
name|int
name|ssh_digest_copy_state
parameter_list|(
name|struct
name|ssh_digest_ctx
modifier|*
name|from
parameter_list|,
name|struct
name|ssh_digest_ctx
modifier|*
name|to
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* One-shot API */
end_comment

begin_function_decl
name|int
name|ssh_digest_memory
parameter_list|(
name|int
name|alg
parameter_list|,
specifier|const
name|void
modifier|*
name|m
parameter_list|,
name|size_t
name|mlen
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

begin_expr_stmt
unit|)))
name|__attribute__
argument_list|(
operator|(
name|__bounded__
argument_list|(
name|__buffer__
argument_list|,
literal|4
argument_list|,
literal|5
argument_list|)
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|int
name|ssh_digest_buffer
parameter_list|(
name|int
name|alg
parameter_list|,
specifier|const
name|Buffer
modifier|*
name|b
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
function_decl|3
operator|,
function_decl|4
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* Update API */
end_comment

begin_function_decl
name|struct
name|ssh_digest_ctx
modifier|*
name|ssh_digest_start
parameter_list|(
name|int
name|alg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssh_digest_update
parameter_list|(
name|struct
name|ssh_digest_ctx
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
name|ssh_digest_update_buffer
parameter_list|(
name|struct
name|ssh_digest_ctx
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
name|ssh_digest_final
parameter_list|(
name|struct
name|ssh_digest_ctx
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
name|ssh_digest_free
parameter_list|(
name|struct
name|ssh_digest_ctx
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
comment|/* _DIGEST_H */
end_comment

end_unit

