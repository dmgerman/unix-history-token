begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $OpenBSD: jpake.h,v 1.2 2009/03/05 07:18:19 djm Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2008 Damien Miller.  All rights reserved.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|JPAKE_H
end_ifndef

begin_define
define|#
directive|define
name|JPAKE_H
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<openssl/bn.h>
end_include

begin_comment
comment|/* Set JPAKE_DEBUG in CFLAGS for privacy-violating debugging */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|JPAKE_DEBUG
end_ifndef

begin_define
define|#
directive|define
name|JPAKE_DEBUG_BN
parameter_list|(
name|a
parameter_list|)
end_define

begin_define
define|#
directive|define
name|JPAKE_DEBUG_BUF
parameter_list|(
name|a
parameter_list|)
end_define

begin_define
define|#
directive|define
name|JPAKE_DEBUG_CTX
parameter_list|(
name|a
parameter_list|)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|JPAKE_DEBUG_BN
parameter_list|(
name|a
parameter_list|)
value|debug3_bn a
end_define

begin_define
define|#
directive|define
name|JPAKE_DEBUG_BUF
parameter_list|(
name|a
parameter_list|)
value|debug3_buf a
end_define

begin_define
define|#
directive|define
name|JPAKE_DEBUG_CTX
parameter_list|(
name|a
parameter_list|)
value|jpake_dump a
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* JPAKE_DEBUG */
end_comment

begin_define
define|#
directive|define
name|KZP_ID_LEN
value|16
end_define

begin_comment
comment|/* Length of client and server IDs */
end_comment

begin_struct
struct|struct
name|jpake_ctx
block|{
comment|/* Parameters */
name|struct
name|modp_group
modifier|*
name|grp
decl_stmt|;
comment|/* Private values shared by client and server */
name|BIGNUM
modifier|*
name|s
decl_stmt|;
comment|/* Secret (salted, crypted password) */
name|BIGNUM
modifier|*
name|k
decl_stmt|;
comment|/* Derived key */
comment|/* Client private values (NULL for server) */
name|BIGNUM
modifier|*
name|x1
decl_stmt|;
comment|/* random in Zq */
name|BIGNUM
modifier|*
name|x2
decl_stmt|;
comment|/* random in Z*q */
comment|/* Server private values (NULL for server) */
name|BIGNUM
modifier|*
name|x3
decl_stmt|;
comment|/* random in Zq */
name|BIGNUM
modifier|*
name|x4
decl_stmt|;
comment|/* random in Z*q */
comment|/* Step 1: C->S */
name|u_char
modifier|*
name|client_id
decl_stmt|;
comment|/* Anti-replay nonce */
name|u_int
name|client_id_len
decl_stmt|;
name|BIGNUM
modifier|*
name|g_x1
decl_stmt|;
comment|/* g^x1 */
name|BIGNUM
modifier|*
name|g_x2
decl_stmt|;
comment|/* g^x2 */
comment|/* Step 1: S->C */
name|u_char
modifier|*
name|server_id
decl_stmt|;
comment|/* Anti-replay nonce */
name|u_int
name|server_id_len
decl_stmt|;
name|BIGNUM
modifier|*
name|g_x3
decl_stmt|;
comment|/* g^x3 */
name|BIGNUM
modifier|*
name|g_x4
decl_stmt|;
comment|/* g^x4 */
comment|/* Step 2: C->S */
name|BIGNUM
modifier|*
name|a
decl_stmt|;
comment|/* g^((x1+x3+x4)*x2*s) */
comment|/* Step 2: S->C */
name|BIGNUM
modifier|*
name|b
decl_stmt|;
comment|/* g^((x1+x2+x3)*x4*s) */
comment|/* Confirmation: C->S */
name|u_char
modifier|*
name|h_k_cid_sessid
decl_stmt|;
comment|/* H(k || client_id || session_id) */
name|u_int
name|h_k_cid_sessid_len
decl_stmt|;
comment|/* Confirmation: S->C */
name|u_char
modifier|*
name|h_k_sid_sessid
decl_stmt|;
comment|/* H(k || server_id || session_id) */
name|u_int
name|h_k_sid_sessid_len
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* jpake.c */
end_comment

begin_function_decl
name|struct
name|modp_group
modifier|*
name|jpake_default_group
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|jpake_dump
parameter_list|(
name|struct
name|jpake_ctx
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__nonnull__
parameter_list|(
function_decl|2
end_function_decl

begin_expr_stmt
unit|)))
name|__attribute__
argument_list|(
operator|(
name|format
argument_list|(
name|printf
argument_list|,
literal|2
argument_list|,
literal|3
argument_list|)
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|struct
name|jpake_ctx
modifier|*
name|jpake_new
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|jpake_free
parameter_list|(
name|struct
name|jpake_ctx
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|jpake_step1
parameter_list|(
name|struct
name|modp_group
modifier|*
parameter_list|,
name|u_char
modifier|*
modifier|*
parameter_list|,
name|u_int
modifier|*
parameter_list|,
name|BIGNUM
modifier|*
modifier|*
parameter_list|,
name|BIGNUM
modifier|*
modifier|*
parameter_list|,
name|BIGNUM
modifier|*
modifier|*
parameter_list|,
name|BIGNUM
modifier|*
modifier|*
parameter_list|,
name|u_char
modifier|*
modifier|*
parameter_list|,
name|u_int
modifier|*
parameter_list|,
name|u_char
modifier|*
modifier|*
parameter_list|,
name|u_int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|jpake_step2
parameter_list|(
name|struct
name|modp_group
modifier|*
parameter_list|,
name|BIGNUM
modifier|*
parameter_list|,
name|BIGNUM
modifier|*
parameter_list|,
name|BIGNUM
modifier|*
parameter_list|,
name|BIGNUM
modifier|*
parameter_list|,
name|BIGNUM
modifier|*
parameter_list|,
specifier|const
name|u_char
modifier|*
parameter_list|,
name|u_int
parameter_list|,
specifier|const
name|u_char
modifier|*
parameter_list|,
name|u_int
parameter_list|,
specifier|const
name|u_char
modifier|*
parameter_list|,
name|u_int
parameter_list|,
specifier|const
name|u_char
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|BIGNUM
modifier|*
modifier|*
parameter_list|,
name|u_char
modifier|*
modifier|*
parameter_list|,
name|u_int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|jpake_confirm_hash
parameter_list|(
specifier|const
name|BIGNUM
modifier|*
parameter_list|,
specifier|const
name|u_char
modifier|*
parameter_list|,
name|u_int
parameter_list|,
specifier|const
name|u_char
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|u_char
modifier|*
modifier|*
parameter_list|,
name|u_int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|jpake_key_confirm
parameter_list|(
name|struct
name|modp_group
modifier|*
parameter_list|,
name|BIGNUM
modifier|*
parameter_list|,
name|BIGNUM
modifier|*
parameter_list|,
name|BIGNUM
modifier|*
parameter_list|,
name|BIGNUM
modifier|*
parameter_list|,
name|BIGNUM
modifier|*
parameter_list|,
name|BIGNUM
modifier|*
parameter_list|,
name|BIGNUM
modifier|*
parameter_list|,
specifier|const
name|u_char
modifier|*
parameter_list|,
name|u_int
parameter_list|,
specifier|const
name|u_char
modifier|*
parameter_list|,
name|u_int
parameter_list|,
specifier|const
name|u_char
modifier|*
parameter_list|,
name|u_int
parameter_list|,
specifier|const
name|u_char
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|BIGNUM
modifier|*
modifier|*
parameter_list|,
name|u_char
modifier|*
modifier|*
parameter_list|,
name|u_int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|jpake_check_confirm
parameter_list|(
specifier|const
name|BIGNUM
modifier|*
parameter_list|,
specifier|const
name|u_char
modifier|*
parameter_list|,
name|u_int
parameter_list|,
specifier|const
name|u_char
modifier|*
parameter_list|,
name|u_int
parameter_list|,
specifier|const
name|u_char
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* JPAKE_H */
end_comment

end_unit

