begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ssl/tls1.h */
end_comment

begin_comment
comment|/* Copyright (C) 1995-1998 Eric Young (eay@cryptsoft.com)  * All rights reserved.  *  * This package is an SSL implementation written  * by Eric Young (eay@cryptsoft.com).  * The implementation was written so as to conform with Netscapes SSL.  *   * This library is free for commercial and non-commercial use as long as  * the following conditions are aheared to.  The following conditions  * apply to all code found in this distribution, be it the RC4, RSA,  * lhash, DES, etc., code; not just the SSL code.  The SSL documentation  * included with this distribution is covered by the same copyright terms  * except that the holder is Tim Hudson (tjh@cryptsoft.com).  *   * Copyright remains Eric Young's, and as such any Copyright notices in  * the code are not to be removed.  * If this package is used in a product, Eric Young should be given attribution  * as the author of the parts of the library used.  * This can be in the form of a textual message at program startup or  * in documentation (online or textual) provided with the package.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *    "This product includes cryptographic software written by  *     Eric Young (eay@cryptsoft.com)"  *    The word 'cryptographic' can be left out if the rouines from the library  *    being used are not cryptographic related :-).  * 4. If you include any Windows specific code (or a derivative thereof) from   *    the apps directory (application code) you must include an acknowledgement:  *    "This product includes software written by Tim Hudson (tjh@cryptsoft.com)"  *   * THIS SOFTWARE IS PROVIDED BY ERIC YOUNG ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *   * The licence and distribution terms for any publically available version or  * derivative of this code cannot be changed.  i.e. this code cannot simply be  * copied and put under another distribution licence  * [including the GNU Public Licence.]  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HEADER_TLS1_H
end_ifndef

begin_define
define|#
directive|define
name|HEADER_TLS1_H
end_define

begin_include
include|#
directive|include
file|<openssl/buffer.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
define|#
directive|define
name|TLS1_ALLOW_EXPERIMENTAL_CIPHERSUITES
value|1
define|#
directive|define
name|TLS1_VERSION
value|0x0301
define|#
directive|define
name|TLS1_VERSION_MAJOR
value|0x03
define|#
directive|define
name|TLS1_VERSION_MINOR
value|0x01
define|#
directive|define
name|TLS1_AD_DECRYPTION_FAILED
value|21
define|#
directive|define
name|TLS1_AD_RECORD_OVERFLOW
value|22
define|#
directive|define
name|TLS1_AD_UNKNOWN_CA
value|48
comment|/* fatal */
define|#
directive|define
name|TLS1_AD_ACCESS_DENIED
value|49
comment|/* fatal */
define|#
directive|define
name|TLS1_AD_DECODE_ERROR
value|50
comment|/* fatal */
define|#
directive|define
name|TLS1_AD_DECRYPT_ERROR
value|51
define|#
directive|define
name|TLS1_AD_EXPORT_RESTRICTION
value|60
comment|/* fatal */
define|#
directive|define
name|TLS1_AD_PROTOCOL_VERSION
value|70
comment|/* fatal */
define|#
directive|define
name|TLS1_AD_INSUFFICIENT_SECURITY
value|71
comment|/* fatal */
define|#
directive|define
name|TLS1_AD_INTERNAL_ERROR
value|80
comment|/* fatal */
define|#
directive|define
name|TLS1_AD_USER_CANCELLED
value|90
define|#
directive|define
name|TLS1_AD_NO_RENEGOTIATION
value|100
comment|/* Additional TLS ciphersuites from draft-ietf-tls-56-bit-ciphersuites-00.txt  * (available if TLS1_ALLOW_EXPERIMENTAL_CIPHERSUITES is defined, see  * s3_lib.c).  We actually treat them like SSL 3.0 ciphers, which we probably  * shouldn't. */
define|#
directive|define
name|TLS1_CK_RSA_EXPORT1024_WITH_RC4_56_MD5
value|0x03000060
define|#
directive|define
name|TLS1_CK_RSA_EXPORT1024_WITH_RC2_CBC_56_MD5
value|0x03000061
define|#
directive|define
name|TLS1_CK_RSA_EXPORT1024_WITH_DES_CBC_SHA
value|0x03000062
define|#
directive|define
name|TLS1_CK_DHE_DSS_EXPORT1024_WITH_DES_CBC_SHA
value|0x03000063
define|#
directive|define
name|TLS1_CK_RSA_EXPORT1024_WITH_RC4_56_SHA
value|0x03000064
define|#
directive|define
name|TLS1_CK_DHE_DSS_EXPORT1024_WITH_RC4_56_SHA
value|0x03000065
define|#
directive|define
name|TLS1_CK_DHE_DSS_WITH_RC4_128_SHA
value|0x03000066
comment|/* XXX  * Inconsistency alert:  * The OpenSSL names of ciphers with ephemeral DH here include the string  * "DHE", while elsewhere it has always been "EDH".  * (The alias for the list of all such ciphers also is "EDH".)  * The specifications speak of "EDH"; maybe we should allow both forms  * for everything. */
define|#
directive|define
name|TLS1_TXT_RSA_EXPORT1024_WITH_RC4_56_MD5
value|"EXP1024-RC4-MD5"
define|#
directive|define
name|TLS1_TXT_RSA_EXPORT1024_WITH_RC2_CBC_56_MD5
value|"EXP1024-RC2-CBC-MD5"
define|#
directive|define
name|TLS1_TXT_RSA_EXPORT1024_WITH_DES_CBC_SHA
value|"EXP1024-DES-CBC-SHA"
define|#
directive|define
name|TLS1_TXT_DHE_DSS_EXPORT1024_WITH_DES_CBC_SHA
value|"EXP1024-DHE-DSS-DES-CBC-SHA"
define|#
directive|define
name|TLS1_TXT_RSA_EXPORT1024_WITH_RC4_56_SHA
value|"EXP1024-RC4-SHA"
define|#
directive|define
name|TLS1_TXT_DHE_DSS_EXPORT1024_WITH_RC4_56_SHA
value|"EXP1024-DHE-DSS-RC4-SHA"
define|#
directive|define
name|TLS1_TXT_DHE_DSS_WITH_RC4_128_SHA
value|"DHE-DSS-RC4-SHA"
define|#
directive|define
name|TLS_CT_RSA_SIGN
value|1
define|#
directive|define
name|TLS_CT_DSS_SIGN
value|2
define|#
directive|define
name|TLS_CT_RSA_FIXED_DH
value|3
define|#
directive|define
name|TLS_CT_DSS_FIXED_DH
value|4
define|#
directive|define
name|TLS_CT_NUMBER
value|4
define|#
directive|define
name|TLS1_FINISH_MAC_LENGTH
value|12
define|#
directive|define
name|TLS_MD_MAX_CONST_SIZE
value|20
define|#
directive|define
name|TLS_MD_CLIENT_FINISH_CONST
value|"client finished"
define|#
directive|define
name|TLS_MD_CLIENT_FINISH_CONST_SIZE
value|15
define|#
directive|define
name|TLS_MD_SERVER_FINISH_CONST
value|"server finished"
define|#
directive|define
name|TLS_MD_SERVER_FINISH_CONST_SIZE
value|15
define|#
directive|define
name|TLS_MD_SERVER_WRITE_KEY_CONST
value|"server write key"
define|#
directive|define
name|TLS_MD_SERVER_WRITE_KEY_CONST_SIZE
value|16
define|#
directive|define
name|TLS_MD_KEY_EXPANSION_CONST
value|"key expansion"
define|#
directive|define
name|TLS_MD_KEY_EXPANSION_CONST_SIZE
value|13
define|#
directive|define
name|TLS_MD_CLIENT_WRITE_KEY_CONST
value|"client write key"
define|#
directive|define
name|TLS_MD_CLIENT_WRITE_KEY_CONST_SIZE
value|16
define|#
directive|define
name|TLS_MD_SERVER_WRITE_KEY_CONST
value|"server write key"
define|#
directive|define
name|TLS_MD_SERVER_WRITE_KEY_CONST_SIZE
value|16
define|#
directive|define
name|TLS_MD_IV_BLOCK_CONST
value|"IV block"
define|#
directive|define
name|TLS_MD_IV_BLOCK_CONST_SIZE
value|8
define|#
directive|define
name|TLS_MD_MASTER_SECRET_CONST
value|"master secret"
define|#
directive|define
name|TLS_MD_MASTER_SECRET_CONST_SIZE
value|13
ifdef|#
directive|ifdef
name|CHARSET_EBCDIC
undef|#
directive|undef
name|TLS_MD_CLIENT_FINISH_CONST
define|#
directive|define
name|TLS_MD_CLIENT_FINISH_CONST
value|"\x63\x6c\x69\x65\x6e\x74\x20\x66\x69\x6e\x69\x73\x68\x65\x64"
comment|/*client finished*/
undef|#
directive|undef
name|TLS_MD_SERVER_FINISH_CONST
define|#
directive|define
name|TLS_MD_SERVER_FINISH_CONST
value|"\x73\x65\x72\x76\x65\x72\x20\x66\x69\x6e\x69\x73\x68\x65\x64"
comment|/*server finished*/
undef|#
directive|undef
name|TLS_MD_SERVER_WRITE_KEY_CONST
define|#
directive|define
name|TLS_MD_SERVER_WRITE_KEY_CONST
value|"\x73\x65\x72\x76\x65\x72\x20\x77\x72\x69\x74\x65\x20\x6b\x65\x79"
comment|/*server write key*/
undef|#
directive|undef
name|TLS_MD_KEY_EXPANSION_CONST
define|#
directive|define
name|TLS_MD_KEY_EXPANSION_CONST
value|"\x6b\x65\x79\x20\x65\x78\x70\x61\x6e\x73\x69\x6f\x6e"
comment|/*key expansion*/
undef|#
directive|undef
name|TLS_MD_CLIENT_WRITE_KEY_CONST
define|#
directive|define
name|TLS_MD_CLIENT_WRITE_KEY_CONST
value|"\x63\x6c\x69\x65\x6e\x74\x20\x77\x72\x69\x74\x65\x20\x6b\x65\x79"
comment|/*client write key*/
undef|#
directive|undef
name|TLS_MD_SERVER_WRITE_KEY_CONST
define|#
directive|define
name|TLS_MD_SERVER_WRITE_KEY_CONST
value|"\x73\x65\x72\x76\x65\x72\x20\x77\x72\x69\x74\x65\x20\x6b\x65\x79"
comment|/*server write key*/
undef|#
directive|undef
name|TLS_MD_IV_BLOCK_CONST
define|#
directive|define
name|TLS_MD_IV_BLOCK_CONST
value|"\x49\x56\x20\x62\x6c\x6f\x63\x6b"
comment|/*IV block*/
undef|#
directive|undef
name|TLS_MD_MASTER_SECRET_CONST
define|#
directive|define
name|TLS_MD_MASTER_SECRET_CONST
value|"\x6d\x61\x73\x74\x65\x72\x20\x73\x65\x63\x72\x65\x74"
comment|/*master secret*/
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

