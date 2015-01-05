begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: ssherr.c,v 1.1 2014/04/30 05:29:56 djm Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 2011 Damien Miller  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|"ssherr.h"
end_include

begin_function
specifier|const
name|char
modifier|*
name|ssh_err
parameter_list|(
name|int
name|n
parameter_list|)
block|{
switch|switch
condition|(
name|n
condition|)
block|{
case|case
name|SSH_ERR_SUCCESS
case|:
return|return
literal|"success"
return|;
case|case
name|SSH_ERR_INTERNAL_ERROR
case|:
return|return
literal|"unexpected internal error"
return|;
case|case
name|SSH_ERR_ALLOC_FAIL
case|:
return|return
literal|"memory allocation failed"
return|;
case|case
name|SSH_ERR_MESSAGE_INCOMPLETE
case|:
return|return
literal|"incomplete message"
return|;
case|case
name|SSH_ERR_INVALID_FORMAT
case|:
return|return
literal|"invalid format"
return|;
case|case
name|SSH_ERR_BIGNUM_IS_NEGATIVE
case|:
return|return
literal|"bignum is negative"
return|;
case|case
name|SSH_ERR_STRING_TOO_LARGE
case|:
return|return
literal|"string is too large"
return|;
case|case
name|SSH_ERR_BIGNUM_TOO_LARGE
case|:
return|return
literal|"bignum is too large"
return|;
case|case
name|SSH_ERR_ECPOINT_TOO_LARGE
case|:
return|return
literal|"elliptic curve point is too large"
return|;
case|case
name|SSH_ERR_NO_BUFFER_SPACE
case|:
return|return
literal|"insufficient buffer space"
return|;
case|case
name|SSH_ERR_INVALID_ARGUMENT
case|:
return|return
literal|"invalid argument"
return|;
case|case
name|SSH_ERR_KEY_BITS_MISMATCH
case|:
return|return
literal|"key bits do not match"
return|;
case|case
name|SSH_ERR_EC_CURVE_INVALID
case|:
return|return
literal|"invalid elliptic curve"
return|;
case|case
name|SSH_ERR_KEY_TYPE_MISMATCH
case|:
return|return
literal|"key type does not match"
return|;
case|case
name|SSH_ERR_KEY_TYPE_UNKNOWN
case|:
return|return
literal|"unknown or unsupported key type"
return|;
case|case
name|SSH_ERR_EC_CURVE_MISMATCH
case|:
return|return
literal|"elliptic curve does not match"
return|;
case|case
name|SSH_ERR_EXPECTED_CERT
case|:
return|return
literal|"plain key provided where certificate required"
return|;
case|case
name|SSH_ERR_KEY_LACKS_CERTBLOB
case|:
return|return
literal|"key lacks certificate data"
return|;
case|case
name|SSH_ERR_KEY_CERT_UNKNOWN_TYPE
case|:
return|return
literal|"unknown/unsupported certificate type"
return|;
case|case
name|SSH_ERR_KEY_CERT_INVALID_SIGN_KEY
case|:
return|return
literal|"invalid certificate signing key"
return|;
case|case
name|SSH_ERR_KEY_INVALID_EC_VALUE
case|:
return|return
literal|"invalid elliptic curve value"
return|;
case|case
name|SSH_ERR_SIGNATURE_INVALID
case|:
return|return
literal|"incorrect signature"
return|;
case|case
name|SSH_ERR_LIBCRYPTO_ERROR
case|:
return|return
literal|"error in libcrypto"
return|;
comment|/* XXX fetch and return */
case|case
name|SSH_ERR_UNEXPECTED_TRAILING_DATA
case|:
return|return
literal|"unexpected bytes remain after decoding"
return|;
case|case
name|SSH_ERR_SYSTEM_ERROR
case|:
return|return
name|strerror
argument_list|(
name|errno
argument_list|)
return|;
case|case
name|SSH_ERR_KEY_CERT_INVALID
case|:
return|return
literal|"invalid certificate"
return|;
case|case
name|SSH_ERR_AGENT_COMMUNICATION
case|:
return|return
literal|"communication with agent failed"
return|;
case|case
name|SSH_ERR_AGENT_FAILURE
case|:
return|return
literal|"agent refused operation"
return|;
case|case
name|SSH_ERR_DH_GEX_OUT_OF_RANGE
case|:
return|return
literal|"DH GEX group out of range"
return|;
case|case
name|SSH_ERR_DISCONNECTED
case|:
return|return
literal|"disconnected"
return|;
case|case
name|SSH_ERR_MAC_INVALID
case|:
return|return
literal|"message authentication code incorrect"
return|;
case|case
name|SSH_ERR_NO_CIPHER_ALG_MATCH
case|:
return|return
literal|"no matching cipher found"
return|;
case|case
name|SSH_ERR_NO_MAC_ALG_MATCH
case|:
return|return
literal|"no matching MAC found"
return|;
case|case
name|SSH_ERR_NO_COMPRESS_ALG_MATCH
case|:
return|return
literal|"no matching compression method found"
return|;
case|case
name|SSH_ERR_NO_KEX_ALG_MATCH
case|:
return|return
literal|"no matching key exchange method found"
return|;
case|case
name|SSH_ERR_NO_HOSTKEY_ALG_MATCH
case|:
return|return
literal|"no matching host key type found"
return|;
case|case
name|SSH_ERR_PROTOCOL_MISMATCH
case|:
return|return
literal|"protocol version mismatch"
return|;
case|case
name|SSH_ERR_NO_PROTOCOL_VERSION
case|:
return|return
literal|"could not read protocol version"
return|;
case|case
name|SSH_ERR_NO_HOSTKEY_LOADED
case|:
return|return
literal|"could not load host key"
return|;
case|case
name|SSH_ERR_NEED_REKEY
case|:
return|return
literal|"rekeying not supported by peer"
return|;
case|case
name|SSH_ERR_PASSPHRASE_TOO_SHORT
case|:
return|return
literal|"passphrase is too short (minimum four characters)"
return|;
case|case
name|SSH_ERR_FILE_CHANGED
case|:
return|return
literal|"file changed while reading"
return|;
case|case
name|SSH_ERR_KEY_UNKNOWN_CIPHER
case|:
return|return
literal|"key encrypted using unsupported cipher"
return|;
case|case
name|SSH_ERR_KEY_WRONG_PASSPHRASE
case|:
return|return
literal|"incorrect passphrase supplied to decrypt private key"
return|;
case|case
name|SSH_ERR_KEY_BAD_PERMISSIONS
case|:
return|return
literal|"bad permissions"
return|;
case|case
name|SSH_ERR_KEY_CERT_MISMATCH
case|:
return|return
literal|"certificate does not match key"
return|;
case|case
name|SSH_ERR_KEY_NOT_FOUND
case|:
return|return
literal|"key not found"
return|;
case|case
name|SSH_ERR_AGENT_NOT_PRESENT
case|:
return|return
literal|"agent not present"
return|;
case|case
name|SSH_ERR_AGENT_NO_IDENTITIES
case|:
return|return
literal|"agent contains no identities"
return|;
case|case
name|SSH_ERR_KRL_BAD_MAGIC
case|:
return|return
literal|"KRL file has invalid magic number"
return|;
case|case
name|SSH_ERR_KEY_REVOKED
case|:
return|return
literal|"Key is revoked"
return|;
default|default:
return|return
literal|"unknown error"
return|;
block|}
block|}
end_function

end_unit

