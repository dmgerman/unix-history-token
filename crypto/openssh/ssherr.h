begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: ssherr.h,v 1.1 2014/04/30 05:29:56 djm Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 2011 Damien Miller  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SSHERR_H
end_ifndef

begin_define
define|#
directive|define
name|_SSHERR_H
end_define

begin_comment
comment|/* XXX are these too granular? not granular enough? I can't decide - djm */
end_comment

begin_comment
comment|/* Error codes */
end_comment

begin_define
define|#
directive|define
name|SSH_ERR_SUCCESS
value|0
end_define

begin_define
define|#
directive|define
name|SSH_ERR_INTERNAL_ERROR
value|-1
end_define

begin_define
define|#
directive|define
name|SSH_ERR_ALLOC_FAIL
value|-2
end_define

begin_define
define|#
directive|define
name|SSH_ERR_MESSAGE_INCOMPLETE
value|-3
end_define

begin_define
define|#
directive|define
name|SSH_ERR_INVALID_FORMAT
value|-4
end_define

begin_define
define|#
directive|define
name|SSH_ERR_BIGNUM_IS_NEGATIVE
value|-5
end_define

begin_define
define|#
directive|define
name|SSH_ERR_STRING_TOO_LARGE
value|-6
end_define

begin_define
define|#
directive|define
name|SSH_ERR_BIGNUM_TOO_LARGE
value|-7
end_define

begin_define
define|#
directive|define
name|SSH_ERR_ECPOINT_TOO_LARGE
value|-8
end_define

begin_define
define|#
directive|define
name|SSH_ERR_NO_BUFFER_SPACE
value|-9
end_define

begin_define
define|#
directive|define
name|SSH_ERR_INVALID_ARGUMENT
value|-10
end_define

begin_define
define|#
directive|define
name|SSH_ERR_KEY_BITS_MISMATCH
value|-11
end_define

begin_define
define|#
directive|define
name|SSH_ERR_EC_CURVE_INVALID
value|-12
end_define

begin_define
define|#
directive|define
name|SSH_ERR_KEY_TYPE_MISMATCH
value|-13
end_define

begin_define
define|#
directive|define
name|SSH_ERR_KEY_TYPE_UNKNOWN
value|-14
end_define

begin_comment
comment|/* XXX UNSUPPORTED? */
end_comment

begin_define
define|#
directive|define
name|SSH_ERR_EC_CURVE_MISMATCH
value|-15
end_define

begin_define
define|#
directive|define
name|SSH_ERR_EXPECTED_CERT
value|-16
end_define

begin_define
define|#
directive|define
name|SSH_ERR_KEY_LACKS_CERTBLOB
value|-17
end_define

begin_define
define|#
directive|define
name|SSH_ERR_KEY_CERT_UNKNOWN_TYPE
value|-18
end_define

begin_define
define|#
directive|define
name|SSH_ERR_KEY_CERT_INVALID_SIGN_KEY
value|-19
end_define

begin_define
define|#
directive|define
name|SSH_ERR_KEY_INVALID_EC_VALUE
value|-20
end_define

begin_define
define|#
directive|define
name|SSH_ERR_SIGNATURE_INVALID
value|-21
end_define

begin_define
define|#
directive|define
name|SSH_ERR_LIBCRYPTO_ERROR
value|-22
end_define

begin_define
define|#
directive|define
name|SSH_ERR_UNEXPECTED_TRAILING_DATA
value|-23
end_define

begin_define
define|#
directive|define
name|SSH_ERR_SYSTEM_ERROR
value|-24
end_define

begin_define
define|#
directive|define
name|SSH_ERR_KEY_CERT_INVALID
value|-25
end_define

begin_define
define|#
directive|define
name|SSH_ERR_AGENT_COMMUNICATION
value|-26
end_define

begin_define
define|#
directive|define
name|SSH_ERR_AGENT_FAILURE
value|-27
end_define

begin_define
define|#
directive|define
name|SSH_ERR_DH_GEX_OUT_OF_RANGE
value|-28
end_define

begin_define
define|#
directive|define
name|SSH_ERR_DISCONNECTED
value|-29
end_define

begin_define
define|#
directive|define
name|SSH_ERR_MAC_INVALID
value|-30
end_define

begin_define
define|#
directive|define
name|SSH_ERR_NO_CIPHER_ALG_MATCH
value|-31
end_define

begin_define
define|#
directive|define
name|SSH_ERR_NO_MAC_ALG_MATCH
value|-32
end_define

begin_define
define|#
directive|define
name|SSH_ERR_NO_COMPRESS_ALG_MATCH
value|-33
end_define

begin_define
define|#
directive|define
name|SSH_ERR_NO_KEX_ALG_MATCH
value|-34
end_define

begin_define
define|#
directive|define
name|SSH_ERR_NO_HOSTKEY_ALG_MATCH
value|-35
end_define

begin_define
define|#
directive|define
name|SSH_ERR_NO_HOSTKEY_LOADED
value|-36
end_define

begin_define
define|#
directive|define
name|SSH_ERR_PROTOCOL_MISMATCH
value|-37
end_define

begin_define
define|#
directive|define
name|SSH_ERR_NO_PROTOCOL_VERSION
value|-38
end_define

begin_define
define|#
directive|define
name|SSH_ERR_NEED_REKEY
value|-39
end_define

begin_define
define|#
directive|define
name|SSH_ERR_PASSPHRASE_TOO_SHORT
value|-40
end_define

begin_define
define|#
directive|define
name|SSH_ERR_FILE_CHANGED
value|-41
end_define

begin_define
define|#
directive|define
name|SSH_ERR_KEY_UNKNOWN_CIPHER
value|-42
end_define

begin_define
define|#
directive|define
name|SSH_ERR_KEY_WRONG_PASSPHRASE
value|-43
end_define

begin_define
define|#
directive|define
name|SSH_ERR_KEY_BAD_PERMISSIONS
value|-44
end_define

begin_define
define|#
directive|define
name|SSH_ERR_KEY_CERT_MISMATCH
value|-45
end_define

begin_define
define|#
directive|define
name|SSH_ERR_KEY_NOT_FOUND
value|-46
end_define

begin_define
define|#
directive|define
name|SSH_ERR_AGENT_NOT_PRESENT
value|-47
end_define

begin_define
define|#
directive|define
name|SSH_ERR_AGENT_NO_IDENTITIES
value|-48
end_define

begin_define
define|#
directive|define
name|SSH_ERR_BUFFER_READ_ONLY
value|-49
end_define

begin_define
define|#
directive|define
name|SSH_ERR_KRL_BAD_MAGIC
value|-50
end_define

begin_define
define|#
directive|define
name|SSH_ERR_KEY_REVOKED
value|-51
end_define

begin_comment
comment|/* Translate a numeric error code to a human-readable error string */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|ssh_err
parameter_list|(
name|int
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SSHERR_H */
end_comment

end_unit

