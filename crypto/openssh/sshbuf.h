begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: sshbuf.h,v 1.3 2014/06/24 01:13:21 djm Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 2011 Damien Miller  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SSHBUF_H
end_ifndef

begin_define
define|#
directive|define
name|_SSHBUF_H
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|WITH_OPENSSL
end_ifdef

begin_include
include|#
directive|include
file|<openssl/bn.h>
end_include

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OPENSSL_HAS_ECC */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WITH_OPENSSL */
end_comment

begin_define
define|#
directive|define
name|SSHBUF_SIZE_MAX
value|0x8000000
end_define

begin_comment
comment|/* Hard maximum size */
end_comment

begin_define
define|#
directive|define
name|SSHBUF_REFS_MAX
value|0x100000
end_define

begin_comment
comment|/* Max child buffers */
end_comment

begin_define
define|#
directive|define
name|SSHBUF_MAX_BIGNUM
value|(16384 / 8)
end_define

begin_comment
comment|/* Max bignum *bytes* */
end_comment

begin_define
define|#
directive|define
name|SSHBUF_MAX_ECPOINT
value|((528 * 2 / 8) + 1)
end_define

begin_comment
comment|/* Max EC point *bytes* */
end_comment

begin_comment
comment|/*  * NB. do not depend on the internals of this. It will be made opaque  * one day.  */
end_comment

begin_struct
struct|struct
name|sshbuf
block|{
name|u_char
modifier|*
name|d
decl_stmt|;
comment|/* Data */
specifier|const
name|u_char
modifier|*
name|cd
decl_stmt|;
comment|/* Const data */
name|size_t
name|off
decl_stmt|;
comment|/* First available byte is buf->d + buf->off */
name|size_t
name|size
decl_stmt|;
comment|/* Last byte is buf->d + buf->size - 1 */
name|size_t
name|max_size
decl_stmt|;
comment|/* Maximum size of buffer */
name|size_t
name|alloc
decl_stmt|;
comment|/* Total bytes allocated to buf->d */
name|int
name|readonly
decl_stmt|;
comment|/* Refers to external, const data */
name|int
name|dont_free
decl_stmt|;
comment|/* Kludge to support sshbuf_init */
name|u_int
name|refcount
decl_stmt|;
comment|/* Tracks self and number of child buffers */
name|struct
name|sshbuf
modifier|*
name|parent
decl_stmt|;
comment|/* If child, pointer to parent */
block|}
struct|;
end_struct

begin_ifndef
ifndef|#
directive|ifndef
name|SSHBUF_NO_DEPREACTED
end_ifndef

begin_comment
comment|/*  * NB. Please do not use sshbuf_init() in new code. Please use sshbuf_new()  * instead. sshbuf_init() is deprectated and will go away soon (it is  * only included to allow compat with buffer_* in OpenSSH)  */
end_comment

begin_function_decl
name|void
name|sshbuf_init
parameter_list|(
name|struct
name|sshbuf
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Create a new sshbuf buffer.  * Returns pointer to buffer on success, or NULL on allocation failure.  */
end_comment

begin_function_decl
name|struct
name|sshbuf
modifier|*
name|sshbuf_new
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Create a new, read-only sshbuf buffer from existing data.  * Returns pointer to buffer on success, or NULL on allocation failure.  */
end_comment

begin_function_decl
name|struct
name|sshbuf
modifier|*
name|sshbuf_from
parameter_list|(
specifier|const
name|void
modifier|*
name|blob
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Create a new, read-only sshbuf buffer from the contents of an existing  * buffer. The contents of "buf" must not change in the lifetime of the  * resultant buffer.  * Returns pointer to buffer on success, or NULL on allocation failure.  */
end_comment

begin_function_decl
name|struct
name|sshbuf
modifier|*
name|sshbuf_fromb
parameter_list|(
name|struct
name|sshbuf
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Create a new, read-only sshbuf buffer from the contents of a string in  * an existing buffer (the string is consumed in the process).  * The contents of "buf" must not change in the lifetime of the resultant  * buffer.  * Returns pointer to buffer on success, or NULL on allocation failure.  */
end_comment

begin_function_decl
name|int
name|sshbuf_froms
parameter_list|(
name|struct
name|sshbuf
modifier|*
name|buf
parameter_list|,
name|struct
name|sshbuf
modifier|*
modifier|*
name|bufp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Clear and free buf  */
end_comment

begin_function_decl
name|void
name|sshbuf_free
parameter_list|(
name|struct
name|sshbuf
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Reset buf, clearing its contents. NB. max_size is preserved.  */
end_comment

begin_function_decl
name|void
name|sshbuf_reset
parameter_list|(
name|struct
name|sshbuf
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Return the maximum size of buf  */
end_comment

begin_function_decl
name|size_t
name|sshbuf_max_size
parameter_list|(
specifier|const
name|struct
name|sshbuf
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Set the maximum size of buf  * Returns 0 on success, or a negative SSH_ERR_* error code on failure.  */
end_comment

begin_function_decl
name|int
name|sshbuf_set_max_size
parameter_list|(
name|struct
name|sshbuf
modifier|*
name|buf
parameter_list|,
name|size_t
name|max_size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Returns the length of data in buf  */
end_comment

begin_function_decl
name|size_t
name|sshbuf_len
parameter_list|(
specifier|const
name|struct
name|sshbuf
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Returns number of bytes left in buffer before hitting max_size.  */
end_comment

begin_function_decl
name|size_t
name|sshbuf_avail
parameter_list|(
specifier|const
name|struct
name|sshbuf
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Returns a read-only pointer to the start of the the data in buf  */
end_comment

begin_function_decl
specifier|const
name|u_char
modifier|*
name|sshbuf_ptr
parameter_list|(
specifier|const
name|struct
name|sshbuf
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Returns a mutable pointer to the start of the the data in buf, or  * NULL if the buffer is read-only.  */
end_comment

begin_function_decl
name|u_char
modifier|*
name|sshbuf_mutable_ptr
parameter_list|(
specifier|const
name|struct
name|sshbuf
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Check whether a reservation of size len will succeed in buf  * Safer to use than direct comparisons again sshbuf_avail as it copes  * with unsigned overflows correctly.  * Returns 0 on success, or a negative SSH_ERR_* error code on failure.  */
end_comment

begin_function_decl
name|int
name|sshbuf_check_reserve
parameter_list|(
specifier|const
name|struct
name|sshbuf
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Reserve len bytes in buf.  * Returns 0 on success and a pointer to the first reserved byte via the  * optional dpp parameter or a negative * SSH_ERR_* error code on failure.  */
end_comment

begin_function_decl
name|int
name|sshbuf_reserve
parameter_list|(
name|struct
name|sshbuf
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|,
name|u_char
modifier|*
modifier|*
name|dpp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Consume len bytes from the start of buf  * Returns 0 on success, or a negative SSH_ERR_* error code on failure.  */
end_comment

begin_function_decl
name|int
name|sshbuf_consume
parameter_list|(
name|struct
name|sshbuf
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Consume len bytes from the end of buf  * Returns 0 on success, or a negative SSH_ERR_* error code on failure.  */
end_comment

begin_function_decl
name|int
name|sshbuf_consume_end
parameter_list|(
name|struct
name|sshbuf
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Extract or deposit some bytes */
end_comment

begin_function_decl
name|int
name|sshbuf_get
parameter_list|(
name|struct
name|sshbuf
modifier|*
name|buf
parameter_list|,
name|void
modifier|*
name|v
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sshbuf_put
parameter_list|(
name|struct
name|sshbuf
modifier|*
name|buf
parameter_list|,
specifier|const
name|void
modifier|*
name|v
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sshbuf_putb
parameter_list|(
name|struct
name|sshbuf
modifier|*
name|buf
parameter_list|,
specifier|const
name|struct
name|sshbuf
modifier|*
name|v
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Append using a printf(3) format */
end_comment

begin_function_decl
name|int
name|sshbuf_putf
parameter_list|(
name|struct
name|sshbuf
modifier|*
name|buf
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
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
name|sshbuf_putfv
parameter_list|(
name|struct
name|sshbuf
modifier|*
name|buf
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
name|va_list
name|ap
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Functions to extract or store big-endian words of various sizes */
end_comment

begin_function_decl
name|int
name|sshbuf_get_u64
parameter_list|(
name|struct
name|sshbuf
modifier|*
name|buf
parameter_list|,
name|u_int64_t
modifier|*
name|valp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sshbuf_get_u32
parameter_list|(
name|struct
name|sshbuf
modifier|*
name|buf
parameter_list|,
name|u_int32_t
modifier|*
name|valp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sshbuf_get_u16
parameter_list|(
name|struct
name|sshbuf
modifier|*
name|buf
parameter_list|,
name|u_int16_t
modifier|*
name|valp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sshbuf_get_u8
parameter_list|(
name|struct
name|sshbuf
modifier|*
name|buf
parameter_list|,
name|u_char
modifier|*
name|valp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sshbuf_put_u64
parameter_list|(
name|struct
name|sshbuf
modifier|*
name|buf
parameter_list|,
name|u_int64_t
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sshbuf_put_u32
parameter_list|(
name|struct
name|sshbuf
modifier|*
name|buf
parameter_list|,
name|u_int32_t
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sshbuf_put_u16
parameter_list|(
name|struct
name|sshbuf
modifier|*
name|buf
parameter_list|,
name|u_int16_t
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sshbuf_put_u8
parameter_list|(
name|struct
name|sshbuf
modifier|*
name|buf
parameter_list|,
name|u_char
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Functions to extract or store SSH wire encoded strings (u32 len || data)  * The "cstring" variants admit no \0 characters in the string contents.  * Caller must free *valp.  */
end_comment

begin_function_decl
name|int
name|sshbuf_get_string
parameter_list|(
name|struct
name|sshbuf
modifier|*
name|buf
parameter_list|,
name|u_char
modifier|*
modifier|*
name|valp
parameter_list|,
name|size_t
modifier|*
name|lenp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sshbuf_get_cstring
parameter_list|(
name|struct
name|sshbuf
modifier|*
name|buf
parameter_list|,
name|char
modifier|*
modifier|*
name|valp
parameter_list|,
name|size_t
modifier|*
name|lenp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sshbuf_get_stringb
parameter_list|(
name|struct
name|sshbuf
modifier|*
name|buf
parameter_list|,
name|struct
name|sshbuf
modifier|*
name|v
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sshbuf_put_string
parameter_list|(
name|struct
name|sshbuf
modifier|*
name|buf
parameter_list|,
specifier|const
name|void
modifier|*
name|v
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sshbuf_put_cstring
parameter_list|(
name|struct
name|sshbuf
modifier|*
name|buf
parameter_list|,
specifier|const
name|char
modifier|*
name|v
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sshbuf_put_stringb
parameter_list|(
name|struct
name|sshbuf
modifier|*
name|buf
parameter_list|,
specifier|const
name|struct
name|sshbuf
modifier|*
name|v
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * "Direct" variant of sshbuf_get_string, returns pointer into the sshbuf to  * avoid an malloc+memcpy. The pointer is guaranteed to be valid until the  * next sshbuf-modifying function call. Caller does not free.  */
end_comment

begin_function_decl
name|int
name|sshbuf_get_string_direct
parameter_list|(
name|struct
name|sshbuf
modifier|*
name|buf
parameter_list|,
specifier|const
name|u_char
modifier|*
modifier|*
name|valp
parameter_list|,
name|size_t
modifier|*
name|lenp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Skip past a string */
end_comment

begin_define
define|#
directive|define
name|sshbuf_skip_string
parameter_list|(
name|buf
parameter_list|)
value|sshbuf_get_string_direct(buf, NULL, NULL)
end_define

begin_comment
comment|/* Another variant: "peeks" into the buffer without modifying it */
end_comment

begin_function_decl
name|int
name|sshbuf_peek_string_direct
parameter_list|(
specifier|const
name|struct
name|sshbuf
modifier|*
name|buf
parameter_list|,
specifier|const
name|u_char
modifier|*
modifier|*
name|valp
parameter_list|,
name|size_t
modifier|*
name|lenp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Functions to extract or store SSH wire encoded bignums and elliptic  * curve points.  */
end_comment

begin_function_decl
name|int
name|sshbuf_put_bignum2_bytes
parameter_list|(
name|struct
name|sshbuf
modifier|*
name|buf
parameter_list|,
specifier|const
name|void
modifier|*
name|v
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|WITH_OPENSSL
end_ifdef

begin_function_decl
name|int
name|sshbuf_get_bignum2
parameter_list|(
name|struct
name|sshbuf
modifier|*
name|buf
parameter_list|,
name|BIGNUM
modifier|*
name|v
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sshbuf_get_bignum1
parameter_list|(
name|struct
name|sshbuf
modifier|*
name|buf
parameter_list|,
name|BIGNUM
modifier|*
name|v
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sshbuf_put_bignum2
parameter_list|(
name|struct
name|sshbuf
modifier|*
name|buf
parameter_list|,
specifier|const
name|BIGNUM
modifier|*
name|v
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sshbuf_put_bignum1
parameter_list|(
name|struct
name|sshbuf
modifier|*
name|buf
parameter_list|,
specifier|const
name|BIGNUM
modifier|*
name|v
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|OPENSSL_HAS_ECC
end_ifdef

begin_function_decl
name|int
name|sshbuf_get_ec
parameter_list|(
name|struct
name|sshbuf
modifier|*
name|buf
parameter_list|,
name|EC_POINT
modifier|*
name|v
parameter_list|,
specifier|const
name|EC_GROUP
modifier|*
name|g
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sshbuf_get_eckey
parameter_list|(
name|struct
name|sshbuf
modifier|*
name|buf
parameter_list|,
name|EC_KEY
modifier|*
name|v
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sshbuf_put_ec
parameter_list|(
name|struct
name|sshbuf
modifier|*
name|buf
parameter_list|,
specifier|const
name|EC_POINT
modifier|*
name|v
parameter_list|,
specifier|const
name|EC_GROUP
modifier|*
name|g
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sshbuf_put_eckey
parameter_list|(
name|struct
name|sshbuf
modifier|*
name|buf
parameter_list|,
specifier|const
name|EC_KEY
modifier|*
name|v
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OPENSSL_HAS_ECC */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WITH_OPENSSL */
end_comment

begin_comment
comment|/* Dump the contents of the buffer in a human-readable format */
end_comment

begin_function_decl
name|void
name|sshbuf_dump
parameter_list|(
name|struct
name|sshbuf
modifier|*
name|buf
parameter_list|,
name|FILE
modifier|*
name|f
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Dump specified memory in a human-readable format */
end_comment

begin_function_decl
name|void
name|sshbuf_dump_data
parameter_list|(
specifier|const
name|void
modifier|*
name|s
parameter_list|,
name|size_t
name|len
parameter_list|,
name|FILE
modifier|*
name|f
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return the hexadecimal representation of the contents of the buffer */
end_comment

begin_function_decl
name|char
modifier|*
name|sshbuf_dtob16
parameter_list|(
name|struct
name|sshbuf
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Encode the contents of the buffer as base64 */
end_comment

begin_function_decl
name|char
modifier|*
name|sshbuf_dtob64
parameter_list|(
name|struct
name|sshbuf
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Decode base64 data and append it to the buffer */
end_comment

begin_function_decl
name|int
name|sshbuf_b64tod
parameter_list|(
name|struct
name|sshbuf
modifier|*
name|buf
parameter_list|,
specifier|const
name|char
modifier|*
name|b64
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Macros for decoding/encoding integers */
end_comment

begin_define
define|#
directive|define
name|PEEK_U64
parameter_list|(
name|p
parameter_list|)
define|\
value|(((u_int64_t)(((u_char *)(p))[0])<< 56) | \ 	 ((u_int64_t)(((u_char *)(p))[1])<< 48) | \ 	 ((u_int64_t)(((u_char *)(p))[2])<< 40) | \ 	 ((u_int64_t)(((u_char *)(p))[3])<< 32) | \ 	 ((u_int64_t)(((u_char *)(p))[4])<< 24) | \ 	 ((u_int64_t)(((u_char *)(p))[5])<< 16) | \ 	 ((u_int64_t)(((u_char *)(p))[6])<< 8) | \ 	  (u_int64_t)(((u_char *)(p))[7]))
end_define

begin_define
define|#
directive|define
name|PEEK_U32
parameter_list|(
name|p
parameter_list|)
define|\
value|(((u_int32_t)(((u_char *)(p))[0])<< 24) | \ 	 ((u_int32_t)(((u_char *)(p))[1])<< 16) | \ 	 ((u_int32_t)(((u_char *)(p))[2])<< 8) | \ 	  (u_int32_t)(((u_char *)(p))[3]))
end_define

begin_define
define|#
directive|define
name|PEEK_U16
parameter_list|(
name|p
parameter_list|)
define|\
value|(((u_int16_t)(((u_char *)(p))[0])<< 8) | \ 	  (u_int16_t)(((u_char *)(p))[1]))
end_define

begin_define
define|#
directive|define
name|POKE_U64
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
define|\
value|do { \ 		((u_char *)(p))[0] = (((u_int64_t)(v))>> 56)& 0xff; \ 		((u_char *)(p))[1] = (((u_int64_t)(v))>> 48)& 0xff; \ 		((u_char *)(p))[2] = (((u_int64_t)(v))>> 40)& 0xff; \ 		((u_char *)(p))[3] = (((u_int64_t)(v))>> 32)& 0xff; \ 		((u_char *)(p))[4] = (((u_int64_t)(v))>> 24)& 0xff; \ 		((u_char *)(p))[5] = (((u_int64_t)(v))>> 16)& 0xff; \ 		((u_char *)(p))[6] = (((u_int64_t)(v))>> 8)& 0xff; \ 		((u_char *)(p))[7] = ((u_int64_t)(v))& 0xff; \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|POKE_U32
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
define|\
value|do { \ 		((u_char *)(p))[0] = (((u_int64_t)(v))>> 24)& 0xff; \ 		((u_char *)(p))[1] = (((u_int64_t)(v))>> 16)& 0xff; \ 		((u_char *)(p))[2] = (((u_int64_t)(v))>> 8)& 0xff; \ 		((u_char *)(p))[3] = ((u_int64_t)(v))& 0xff; \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|POKE_U16
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
define|\
value|do { \ 		((u_char *)(p))[0] = (((u_int64_t)(v))>> 8)& 0xff; \ 		((u_char *)(p))[1] = ((u_int64_t)(v))& 0xff; \ 	} while (0)
end_define

begin_comment
comment|/* Internal definitions follow. Exposed for regress tests */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SSHBUF_INTERNAL
end_ifdef

begin_comment
comment|/*  * Return the allocation size of buf  */
end_comment

begin_function_decl
name|size_t
name|sshbuf_alloc
parameter_list|(
specifier|const
name|struct
name|sshbuf
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Increment the reference count of buf.  */
end_comment

begin_function_decl
name|int
name|sshbuf_set_parent
parameter_list|(
name|struct
name|sshbuf
modifier|*
name|child
parameter_list|,
name|struct
name|sshbuf
modifier|*
name|parent
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Return the parent buffer of buf, or NULL if it has no parent.  */
end_comment

begin_function_decl
specifier|const
name|struct
name|sshbuf
modifier|*
name|sshbuf_parent
parameter_list|(
specifier|const
name|struct
name|sshbuf
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Return the reference count of buf  */
end_comment

begin_function_decl
name|u_int
name|sshbuf_refcount
parameter_list|(
specifier|const
name|struct
name|sshbuf
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|SSHBUF_SIZE_INIT
value|256
end_define

begin_comment
comment|/* Initial allocation */
end_comment

begin_define
define|#
directive|define
name|SSHBUF_SIZE_INC
value|256
end_define

begin_comment
comment|/* Preferred increment length */
end_comment

begin_define
define|#
directive|define
name|SSHBUF_PACK_MIN
value|8192
end_define

begin_comment
comment|/* Minimim packable offset */
end_comment

begin_comment
comment|/* # define SSHBUF_ABORT abort */
end_comment

begin_comment
comment|/* # define SSHBUF_DEBUG */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SSHBUF_ABORT
end_ifndef

begin_define
define|#
directive|define
name|SSHBUF_ABORT
parameter_list|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SSHBUF_DEBUG
end_ifdef

begin_define
define|#
directive|define
name|SSHBUF_TELL
parameter_list|(
name|what
parameter_list|)
value|do { \ 		printf("%s:%d %s: %s size %zu alloc %zu off %zu max %zu\n", \ 		    __FILE__, __LINE__, __func__, what, \ 		    buf->size, buf->alloc, buf->off, buf->max_size); \ 		fflush(stdout); \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|SSHBUF_DBG
parameter_list|(
name|x
parameter_list|)
value|do { \ 		printf("%s:%d %s: ", __FILE__, __LINE__, __func__); \ 		printf x; \ 		printf("\n"); \ 		fflush(stdout); \ 	} while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SSHBUF_TELL
parameter_list|(
name|what
parameter_list|)
end_define

begin_define
define|#
directive|define
name|SSHBUF_DBG
parameter_list|(
name|x
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SSHBUF_INTERNAL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SSHBUF_H */
end_comment

end_unit

