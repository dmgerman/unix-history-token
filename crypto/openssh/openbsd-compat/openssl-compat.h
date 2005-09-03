begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: openssl-compat.h,v 1.1 2005/06/09 11:45:11 dtucker Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2005 Darren Tucker<dtucker@zip.com.au>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF MIND, USE, DATA OR PROFITS, WHETHER  * IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING  * OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_include
include|#
directive|include
file|"includes.h"
end_include

begin_include
include|#
directive|include
file|<openssl/evp.h>
end_include

begin_if
if|#
directive|if
name|OPENSSL_VERSION_NUMBER
operator|<
literal|0x00906000L
end_if

begin_define
define|#
directive|define
name|SSH_OLD_EVP
end_define

begin_define
define|#
directive|define
name|EVP_CIPHER_CTX_get_app_data
parameter_list|(
name|e
parameter_list|)
value|((e)->app_data)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|OPENSSL_VERSION_NUMBER
operator|<
literal|0x00907000L
end_if

begin_define
define|#
directive|define
name|EVP_aes_128_cbc
value|evp_rijndael
end_define

begin_define
define|#
directive|define
name|EVP_aes_192_cbc
value|evp_rijndael
end_define

begin_define
define|#
directive|define
name|EVP_aes_256_cbc
value|evp_rijndael
end_define

begin_function_decl
specifier|extern
specifier|const
name|EVP_CIPHER
modifier|*
name|evp_rijndael
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ssh_rijndael_iv
parameter_list|(
name|EVP_CIPHER_CTX
modifier|*
parameter_list|,
name|int
parameter_list|,
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

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|EVP_CTRL_SET_ACSS_MODE
argument_list|)
end_if

begin_if
if|#
directive|if
operator|(
name|OPENSSL_VERSION_NUMBER
operator|>=
literal|0x00907000L
operator|)
end_if

begin_define
define|#
directive|define
name|USE_CIPHER_ACSS
value|1
end_define

begin_function_decl
specifier|extern
specifier|const
name|EVP_CIPHER
modifier|*
name|evp_acss
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|EVP_acss
value|evp_acss
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|EVP_acss
value|NULL
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
comment|/*  * insert comment here  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SSH_OLD_EVP
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|SSH_DONT_REDEF_EVP
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|EVP_Cipher
end_ifdef

begin_undef
undef|#
directive|undef
name|EVP_Cipher
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|EVP_CipherInit
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|,
name|e
parameter_list|)
value|ssh_EVP_CipherInit((a),(b),(c),(d),(e))
end_define

begin_define
define|#
directive|define
name|EVP_Cipher
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|ssh_EVP_Cipher((a),(b),(c),(d))
end_define

begin_define
define|#
directive|define
name|EVP_CIPHER_CTX_cleanup
parameter_list|(
name|a
parameter_list|)
value|ssh_EVP_CIPHER_CTX_cleanup((a))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|ssh_EVP_CipherInit
parameter_list|(
name|EVP_CIPHER_CTX
modifier|*
parameter_list|,
specifier|const
name|EVP_CIPHER
modifier|*
parameter_list|,
name|unsigned
name|char
modifier|*
parameter_list|,
name|unsigned
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssh_EVP_Cipher
parameter_list|(
name|EVP_CIPHER_CTX
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssh_EVP_CIPHER_CTX_cleanup
parameter_list|(
name|EVP_CIPHER_CTX
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

