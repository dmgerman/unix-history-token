begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* crypto/evp/digest.c */
end_comment

begin_comment
comment|/* Copyright (C) 1995-1998 Eric Young (eay@cryptsoft.com)  * All rights reserved.  *  * This package is an SSL implementation written  * by Eric Young (eay@cryptsoft.com).  * The implementation was written so as to conform with Netscapes SSL.  *   * This library is free for commercial and non-commercial use as long as  * the following conditions are aheared to.  The following conditions  * apply to all code found in this distribution, be it the RC4, RSA,  * lhash, DES, etc., code; not just the SSL code.  The SSL documentation  * included with this distribution is covered by the same copyright terms  * except that the holder is Tim Hudson (tjh@cryptsoft.com).  *   * Copyright remains Eric Young's, and as such any Copyright notices in  * the code are not to be removed.  * If this package is used in a product, Eric Young should be given attribution  * as the author of the parts of the library used.  * This can be in the form of a textual message at program startup or  * in documentation (online or textual) provided with the package.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *    "This product includes cryptographic software written by  *     Eric Young (eay@cryptsoft.com)"  *    The word 'cryptographic' can be left out if the rouines from the library  *    being used are not cryptographic related :-).  * 4. If you include any Windows specific code (or a derivative thereof) from   *    the apps directory (application code) you must include an acknowledgement:  *    "This product includes software written by Tim Hudson (tjh@cryptsoft.com)"  *   * THIS SOFTWARE IS PROVIDED BY ERIC YOUNG ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *   * The licence and distribution terms for any publically available version or  * derivative of this code cannot be changed.  i.e. this code cannot simply be  * copied and put under another distribution licence  * [including the GNU Public Licence.]  */
end_comment

begin_comment
comment|/* ====================================================================  * Copyright (c) 1998-2001 The OpenSSL Project.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.   *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *  * 3. All advertising materials mentioning features or use of this  *    software must display the following acknowledgment:  *    "This product includes software developed by the OpenSSL Project  *    for use in the OpenSSL Toolkit. (http://www.openssl.org/)"  *  * 4. The names "OpenSSL Toolkit" and "OpenSSL Project" must not be used to  *    endorse or promote products derived from this software without  *    prior written permission. For written permission, please contact  *    openssl-core@openssl.org.  *  * 5. Products derived from this software may not be called "OpenSSL"  *    nor may "OpenSSL" appear in their names without prior written  *    permission of the OpenSSL Project.  *  * 6. Redistributions of any form whatsoever must retain the following  *    acknowledgment:  *    "This product includes software developed by the OpenSSL Project  *    for use in the OpenSSL Toolkit (http://www.openssl.org/)"  *  * THIS SOFTWARE IS PROVIDED BY THE OpenSSL PROJECT ``AS IS'' AND ANY  * EXPRESSED OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE OpenSSL PROJECT OR  * ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED  * OF THE POSSIBILITY OF SUCH DAMAGE.  * ====================================================================  *  * This product includes cryptographic software written by Eric Young  * (eay@cryptsoft.com).  This product includes software written by Tim  * Hudson (tjh@cryptsoft.com).  *  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"cryptlib.h"
end_include

begin_include
include|#
directive|include
file|<openssl/objects.h>
end_include

begin_include
include|#
directive|include
file|<openssl/evp.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|OPENSSL_NO_ENGINE
end_ifndef

begin_include
include|#
directive|include
file|<openssl/engine.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"evp_locl.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|OPENSSL_NO_ENGINE
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|OPENSSL_FIPS
end_ifdef

begin_function
specifier|static
name|int
name|do_evp_md_engine_full
parameter_list|(
name|EVP_MD_CTX
modifier|*
name|ctx
parameter_list|,
specifier|const
name|EVP_MD
modifier|*
modifier|*
name|ptype
parameter_list|,
name|ENGINE
modifier|*
name|impl
parameter_list|)
block|{
if|if
condition|(
operator|*
name|ptype
condition|)
block|{
comment|/* Ensure an ENGINE left lying around from last time is cleared 		 * (the previous check attempted to avoid this if the same 		 * ENGINE and EVP_MD could be used). */
if|if
condition|(
name|ctx
operator|->
name|engine
condition|)
name|ENGINE_finish
argument_list|(
name|ctx
operator|->
name|engine
argument_list|)
expr_stmt|;
if|if
condition|(
name|impl
condition|)
block|{
if|if
condition|(
operator|!
name|ENGINE_init
argument_list|(
name|impl
argument_list|)
condition|)
block|{
name|EVPerr
argument_list|(
name|EVP_F_DO_EVP_MD_ENGINE_FULL
argument_list|,
name|EVP_R_INITIALIZATION_ERROR
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
block|}
else|else
comment|/* Ask if an ENGINE is reserved for this job */
name|impl
operator|=
name|ENGINE_get_digest_engine
argument_list|(
operator|(
operator|*
name|ptype
operator|)
operator|->
name|type
argument_list|)
expr_stmt|;
if|if
condition|(
name|impl
condition|)
block|{
comment|/* There's an ENGINE for this job ... (apparently) */
specifier|const
name|EVP_MD
modifier|*
name|d
init|=
name|ENGINE_get_digest
argument_list|(
name|impl
argument_list|,
operator|(
operator|*
name|ptype
operator|)
operator|->
name|type
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|d
condition|)
block|{
comment|/* Same comment from evp_enc.c */
name|EVPerr
argument_list|(
name|EVP_F_DO_EVP_MD_ENGINE_FULL
argument_list|,
name|EVP_R_INITIALIZATION_ERROR
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
comment|/* We'll use the ENGINE's private digest definition */
operator|*
name|ptype
operator|=
name|d
expr_stmt|;
comment|/* Store the ENGINE functional reference so we know 			 * 'type' came from an ENGINE and we need to release 			 * it when done. */
name|ctx
operator|->
name|engine
operator|=
name|impl
expr_stmt|;
block|}
else|else
name|ctx
operator|->
name|engine
operator|=
name|NULL
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|!
name|ctx
operator|->
name|digest
condition|)
block|{
name|EVPerr
argument_list|(
name|EVP_F_DO_EVP_MD_ENGINE_FULL
argument_list|,
name|EVP_R_NO_DIGEST_SET
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
return|return
literal|1
return|;
block|}
end_function

begin_function
name|void
name|int_EVP_MD_init_engine_callbacks
parameter_list|(
name|void
parameter_list|)
block|{
name|int_EVP_MD_set_engine_callbacks
argument_list|(
name|ENGINE_init
argument_list|,
name|ENGINE_finish
argument_list|,
name|do_evp_md_engine_full
argument_list|)
expr_stmt|;
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

