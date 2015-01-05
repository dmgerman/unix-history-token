begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $OpenBSD: buffer.h,v 1.25 2014/04/30 05:29:56 djm Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2012 Damien Miller<djm@mindrot.org>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* Emulation wrappers for legacy OpenSSH buffer API atop sshbuf */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BUFFER_H
end_ifndef

begin_define
define|#
directive|define
name|BUFFER_H
end_define

begin_include
include|#
directive|include
file|"sshbuf.h"
end_include

begin_typedef
typedef|typedef
name|struct
name|sshbuf
name|Buffer
typedef|;
end_typedef

begin_define
define|#
directive|define
name|buffer_init
parameter_list|(
name|b
parameter_list|)
value|sshbuf_init(b)
end_define

begin_define
define|#
directive|define
name|buffer_clear
parameter_list|(
name|b
parameter_list|)
value|sshbuf_reset(b)
end_define

begin_define
define|#
directive|define
name|buffer_free
parameter_list|(
name|b
parameter_list|)
value|sshbuf_free(b)
end_define

begin_define
define|#
directive|define
name|buffer_dump
parameter_list|(
name|b
parameter_list|)
value|sshbuf_dump(b, stderr)
end_define

begin_comment
comment|/* XXX cast is safe: sshbuf never stores more than len 2^31 */
end_comment

begin_define
define|#
directive|define
name|buffer_len
parameter_list|(
name|b
parameter_list|)
value|((u_int) sshbuf_len(b))
end_define

begin_define
define|#
directive|define
name|buffer_ptr
parameter_list|(
name|b
parameter_list|)
value|sshbuf_mutable_ptr(b)
end_define

begin_function_decl
name|void
name|buffer_append
parameter_list|(
name|Buffer
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|buffer_append_space
parameter_list|(
name|Buffer
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|buffer_check_alloc
parameter_list|(
name|Buffer
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|buffer_get
parameter_list|(
name|Buffer
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|buffer_consume
parameter_list|(
name|Buffer
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|buffer_consume_end
parameter_list|(
name|Buffer
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|buffer_get_ret
parameter_list|(
name|Buffer
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|buffer_consume_ret
parameter_list|(
name|Buffer
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|buffer_consume_end_ret
parameter_list|(
name|Buffer
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_include
include|#
directive|include
file|<openssl/bn.h>
end_include

begin_function_decl
name|void
name|buffer_put_bignum
parameter_list|(
name|Buffer
modifier|*
parameter_list|,
specifier|const
name|BIGNUM
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|buffer_put_bignum2
parameter_list|(
name|Buffer
modifier|*
parameter_list|,
specifier|const
name|BIGNUM
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|buffer_get_bignum
parameter_list|(
name|Buffer
modifier|*
parameter_list|,
name|BIGNUM
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|buffer_get_bignum2
parameter_list|(
name|Buffer
modifier|*
parameter_list|,
name|BIGNUM
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|buffer_put_bignum2_from_string
parameter_list|(
name|Buffer
modifier|*
parameter_list|,
specifier|const
name|u_char
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_short
name|buffer_get_short
parameter_list|(
name|Buffer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|buffer_put_short
parameter_list|(
name|Buffer
modifier|*
parameter_list|,
name|u_short
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|buffer_get_int
parameter_list|(
name|Buffer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|buffer_put_int
parameter_list|(
name|Buffer
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int64_t
name|buffer_get_int64
parameter_list|(
name|Buffer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|buffer_put_int64
parameter_list|(
name|Buffer
modifier|*
parameter_list|,
name|u_int64_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|buffer_get_char
parameter_list|(
name|Buffer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|buffer_put_char
parameter_list|(
name|Buffer
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|buffer_get_string
parameter_list|(
name|Buffer
modifier|*
parameter_list|,
name|u_int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|void
modifier|*
name|buffer_get_string_ptr
parameter_list|(
name|Buffer
modifier|*
parameter_list|,
name|u_int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|buffer_put_string
parameter_list|(
name|Buffer
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|buffer_get_cstring
parameter_list|(
name|Buffer
modifier|*
parameter_list|,
name|u_int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|buffer_put_cstring
parameter_list|(
name|Buffer
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|buffer_skip_string
parameter_list|(
name|b
parameter_list|)
value|(void)buffer_get_string_ptr(b, NULL);
end_define

begin_function_decl
name|int
name|buffer_put_bignum_ret
parameter_list|(
name|Buffer
modifier|*
parameter_list|,
specifier|const
name|BIGNUM
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|buffer_get_bignum_ret
parameter_list|(
name|Buffer
modifier|*
parameter_list|,
name|BIGNUM
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|buffer_put_bignum2_ret
parameter_list|(
name|Buffer
modifier|*
parameter_list|,
specifier|const
name|BIGNUM
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|buffer_get_bignum2_ret
parameter_list|(
name|Buffer
modifier|*
parameter_list|,
name|BIGNUM
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|buffer_get_short_ret
parameter_list|(
name|u_short
modifier|*
parameter_list|,
name|Buffer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|buffer_get_int_ret
parameter_list|(
name|u_int
modifier|*
parameter_list|,
name|Buffer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|buffer_get_int64_ret
parameter_list|(
name|u_int64_t
modifier|*
parameter_list|,
name|Buffer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|buffer_get_string_ret
parameter_list|(
name|Buffer
modifier|*
parameter_list|,
name|u_int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|buffer_get_cstring_ret
parameter_list|(
name|Buffer
modifier|*
parameter_list|,
name|u_int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|void
modifier|*
name|buffer_get_string_ptr_ret
parameter_list|(
name|Buffer
modifier|*
parameter_list|,
name|u_int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|buffer_get_char_ret
parameter_list|(
name|char
modifier|*
parameter_list|,
name|Buffer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|OPENSSL_HAS_ECC
end_ifdef

begin_include
include|#
directive|include
file|<openssl/ec.h>
end_include

begin_function_decl
name|int
name|buffer_put_ecpoint_ret
parameter_list|(
name|Buffer
modifier|*
parameter_list|,
specifier|const
name|EC_GROUP
modifier|*
parameter_list|,
specifier|const
name|EC_POINT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|buffer_put_ecpoint
parameter_list|(
name|Buffer
modifier|*
parameter_list|,
specifier|const
name|EC_GROUP
modifier|*
parameter_list|,
specifier|const
name|EC_POINT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|buffer_get_ecpoint_ret
parameter_list|(
name|Buffer
modifier|*
parameter_list|,
specifier|const
name|EC_GROUP
modifier|*
parameter_list|,
name|EC_POINT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|buffer_get_ecpoint
parameter_list|(
name|Buffer
modifier|*
parameter_list|,
specifier|const
name|EC_GROUP
modifier|*
parameter_list|,
name|EC_POINT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BUFFER_H */
end_comment

end_unit

