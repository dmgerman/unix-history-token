begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* crypto/evp/e_old.c */
end_comment

begin_comment
comment|/*  * Written by Richard Levitte (richard@levitte.org) for the OpenSSL project  * 2004.  */
end_comment

begin_comment
comment|/* ====================================================================  * Copyright (c) 2004 The OpenSSL Project.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *  * 3. All advertising materials mentioning features or use of this  *    software must display the following acknowledgment:  *    "This product includes software developed by the OpenSSL Project  *    for use in the OpenSSL Toolkit. (http://www.openssl.org/)"  *  * 4. The names "OpenSSL Toolkit" and "OpenSSL Project" must not be used to  *    endorse or promote products derived from this software without  *    prior written permission. For written permission, please contact  *    openssl-core@openssl.org.  *  * 5. Products derived from this software may not be called "OpenSSL"  *    nor may "OpenSSL" appear in their names without prior written  *    permission of the OpenSSL Project.  *  * 6. Redistributions of any form whatsoever must retain the following  *    acknowledgment:  *    "This product includes software developed by the OpenSSL Project  *    for use in the OpenSSL Toolkit (http://www.openssl.org/)"  *  * THIS SOFTWARE IS PROVIDED BY THE OpenSSL PROJECT ``AS IS'' AND ANY  * EXPRESSED OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE OpenSSL PROJECT OR  * ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED  * OF THE POSSIBILITY OF SUCH DAMAGE.  * ====================================================================  *  * This product includes cryptographic software written by Eric Young  * (eay@cryptsoft.com).  This product includes software written by Tim  * Hudson (tjh@cryptsoft.com).  *  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|OPENSSL_NO_DEPRECATED
end_ifdef

begin_decl_stmt
specifier|static
name|void
modifier|*
name|dummy
init|=
operator|&
name|dummy
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<openssl/evp.h>
end_include

begin_comment
comment|/*  * Define some deprecated functions, so older programs don't crash and burn  * too quickly.  On Windows and VMS, these will never be used, since  * functions and variables in shared libraries are selected by entry point  * location, not by name.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|OPENSSL_NO_BF
end_ifndef

begin_undef
undef|#
directive|undef
name|EVP_bf_cfb
end_undef

begin_function_decl
specifier|const
name|EVP_CIPHER
modifier|*
name|EVP_bf_cfb
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|const
name|EVP_CIPHER
modifier|*
name|EVP_bf_cfb
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|EVP_bf_cfb64
argument_list|()
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|OPENSSL_NO_DES
end_ifndef

begin_undef
undef|#
directive|undef
name|EVP_des_cfb
end_undef

begin_function_decl
specifier|const
name|EVP_CIPHER
modifier|*
name|EVP_des_cfb
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|const
name|EVP_CIPHER
modifier|*
name|EVP_des_cfb
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|EVP_des_cfb64
argument_list|()
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|EVP_des_ede3_cfb
end_undef

begin_function_decl
specifier|const
name|EVP_CIPHER
modifier|*
name|EVP_des_ede3_cfb
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|const
name|EVP_CIPHER
modifier|*
name|EVP_des_ede3_cfb
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|EVP_des_ede3_cfb64
argument_list|()
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|EVP_des_ede_cfb
end_undef

begin_function_decl
specifier|const
name|EVP_CIPHER
modifier|*
name|EVP_des_ede_cfb
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|const
name|EVP_CIPHER
modifier|*
name|EVP_des_ede_cfb
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|EVP_des_ede_cfb64
argument_list|()
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|OPENSSL_NO_IDEA
end_ifndef

begin_undef
undef|#
directive|undef
name|EVP_idea_cfb
end_undef

begin_function_decl
specifier|const
name|EVP_CIPHER
modifier|*
name|EVP_idea_cfb
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|const
name|EVP_CIPHER
modifier|*
name|EVP_idea_cfb
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|EVP_idea_cfb64
argument_list|()
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|OPENSSL_NO_RC2
end_ifndef

begin_undef
undef|#
directive|undef
name|EVP_rc2_cfb
end_undef

begin_function_decl
specifier|const
name|EVP_CIPHER
modifier|*
name|EVP_rc2_cfb
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|const
name|EVP_CIPHER
modifier|*
name|EVP_rc2_cfb
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|EVP_rc2_cfb64
argument_list|()
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|OPENSSL_NO_CAST
end_ifndef

begin_undef
undef|#
directive|undef
name|EVP_cast5_cfb
end_undef

begin_function_decl
specifier|const
name|EVP_CIPHER
modifier|*
name|EVP_cast5_cfb
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|const
name|EVP_CIPHER
modifier|*
name|EVP_cast5_cfb
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|EVP_cast5_cfb64
argument_list|()
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|OPENSSL_NO_RC5
end_ifndef

begin_undef
undef|#
directive|undef
name|EVP_rc5_32_12_16_cfb
end_undef

begin_function_decl
specifier|const
name|EVP_CIPHER
modifier|*
name|EVP_rc5_32_12_16_cfb
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|const
name|EVP_CIPHER
modifier|*
name|EVP_rc5_32_12_16_cfb
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|EVP_rc5_32_12_16_cfb64
argument_list|()
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|OPENSSL_NO_AES
end_ifndef

begin_undef
undef|#
directive|undef
name|EVP_aes_128_cfb
end_undef

begin_function_decl
specifier|const
name|EVP_CIPHER
modifier|*
name|EVP_aes_128_cfb
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|const
name|EVP_CIPHER
modifier|*
name|EVP_aes_128_cfb
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|EVP_aes_128_cfb128
argument_list|()
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|EVP_aes_192_cfb
end_undef

begin_function_decl
specifier|const
name|EVP_CIPHER
modifier|*
name|EVP_aes_192_cfb
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|const
name|EVP_CIPHER
modifier|*
name|EVP_aes_192_cfb
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|EVP_aes_192_cfb128
argument_list|()
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|EVP_aes_256_cfb
end_undef

begin_function_decl
specifier|const
name|EVP_CIPHER
modifier|*
name|EVP_aes_256_cfb
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|const
name|EVP_CIPHER
modifier|*
name|EVP_aes_256_cfb
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|EVP_aes_256_cfb128
argument_list|()
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

