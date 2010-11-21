begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* o_init.c */
end_comment

begin_comment
comment|/* Written by Dr Stephen N Henson (steve@openssl.org) for the OpenSSL  * project.  */
end_comment

begin_comment
comment|/* ====================================================================  * Copyright (c) 2007 The OpenSSL Project.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.   *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *  * 3. All advertising materials mentioning features or use of this  *    software must display the following acknowledgment:  *    "This product includes software developed by the OpenSSL Project  *    for use in the OpenSSL Toolkit. (http://www.openssl.org/)"  *  * 4. The names "OpenSSL Toolkit" and "OpenSSL Project" must not be used to  *    endorse or promote products derived from this software without  *    prior written permission. For written permission, please contact  *    openssl-core@openssl.org.  *  * 5. Products derived from this software may not be called "OpenSSL"  *    nor may "OpenSSL" appear in their names without prior written  *    permission of the OpenSSL Project.  *  * 6. Redistributions of any form whatsoever must retain the following  *    acknowledgment:  *    "This product includes software developed by the OpenSSL Project  *    for use in the OpenSSL Toolkit (http://www.openssl.org/)"  *  * THIS SOFTWARE IS PROVIDED BY THE OpenSSL PROJECT ``AS IS'' AND ANY  * EXPRESSED OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE OpenSSL PROJECT OR  * ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED  * OF THE POSSIBILITY OF SUCH DAMAGE.  * ====================================================================  *  * This product includes cryptographic software written by Eric Young  * (eay@cryptsoft.com).  This product includes software written by Tim  * Hudson (tjh@cryptsoft.com).  *  */
end_comment

begin_include
include|#
directive|include
file|<e_os.h>
end_include

begin_include
include|#
directive|include
file|<openssl/err.h>
end_include

begin_comment
comment|/* Internal only functions: only ever used here */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|OPENSSL_FIPS
end_ifdef

begin_function_decl
specifier|extern
name|void
name|int_ERR_lib_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|OPENSSL_NO_ENGINE
end_ifndef

begin_function_decl
specifier|extern
name|void
name|int_EVP_MD_init_engine_callbacks
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|int_EVP_CIPHER_init_engine_callbacks
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|int_RAND_init_engine_callbacks
parameter_list|(
name|void
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
comment|/* Perform any essential OpenSSL initialization operations.  * Currently only sets FIPS callbacks  */
end_comment

begin_function
name|void
name|OPENSSL_init
parameter_list|(
name|void
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|OPENSSL_FIPS
specifier|static
name|int
name|done
init|=
literal|0
decl_stmt|;
if|if
condition|(
operator|!
name|done
condition|)
block|{
name|int_ERR_lib_init
argument_list|()
expr_stmt|;
ifdef|#
directive|ifdef
name|CRYPTO_MDEBUG
name|CRYPTO_malloc_debug_init
argument_list|()
expr_stmt|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|OPENSSL_NO_ENGINE
name|int_EVP_MD_init_engine_callbacks
argument_list|()
expr_stmt|;
name|int_EVP_CIPHER_init_engine_callbacks
argument_list|()
expr_stmt|;
name|int_RAND_init_engine_callbacks
argument_list|()
expr_stmt|;
endif|#
directive|endif
name|done
operator|=
literal|1
expr_stmt|;
block|}
endif|#
directive|endif
block|}
end_function

end_unit

