begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* crypto/evp/m_dss.c */
end_comment

begin_comment
comment|/* Copyright (C) 1995-1998 Eric Young (eay@cryptsoft.com)  * All rights reserved.  *  * This package is an SSL implementation written  * by Eric Young (eay@cryptsoft.com).  * The implementation was written so as to conform with Netscapes SSL.  *  * This library is free for commercial and non-commercial use as long as  * the following conditions are aheared to.  The following conditions  * apply to all code found in this distribution, be it the RC4, RSA,  * lhash, DES, etc., code; not just the SSL code.  The SSL documentation  * included with this distribution is covered by the same copyright terms  * except that the holder is Tim Hudson (tjh@cryptsoft.com).  *  * Copyright remains Eric Young's, and as such any Copyright notices in  * the code are not to be removed.  * If this package is used in a product, Eric Young should be given attribution  * as the author of the parts of the library used.  * This can be in the form of a textual message at program startup or  * in documentation (online or textual) provided with the package.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *    "This product includes cryptographic software written by  *     Eric Young (eay@cryptsoft.com)"  *    The word 'cryptographic' can be left out if the rouines from the library  *    being used are not cryptographic related :-).  * 4. If you include any Windows specific code (or a derivative thereof) from  *    the apps directory (application code) you must include an acknowledgement:  *    "This product includes software written by Tim Hudson (tjh@cryptsoft.com)"  *  * THIS SOFTWARE IS PROVIDED BY ERIC YOUNG ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * The licence and distribution terms for any publically available version or  * derivative of this code cannot be changed.  i.e. this code cannot simply be  * copied and put under another distribution licence  * [including the GNU Public Licence.]  */
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
file|<openssl/evp.h>
end_include

begin_include
include|#
directive|include
file|<openssl/objects.h>
end_include

begin_include
include|#
directive|include
file|<openssl/sha.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|OPENSSL_NO_DSA
end_ifndef

begin_include
include|#
directive|include
file|<openssl/dsa.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|OPENSSL_NO_SHA
end_ifndef

begin_function
specifier|static
name|int
name|init
parameter_list|(
name|EVP_MD_CTX
modifier|*
name|ctx
parameter_list|)
block|{
return|return
name|SHA1_Init
argument_list|(
name|ctx
operator|->
name|md_data
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|update
parameter_list|(
name|EVP_MD_CTX
modifier|*
name|ctx
parameter_list|,
specifier|const
name|void
modifier|*
name|data
parameter_list|,
name|size_t
name|count
parameter_list|)
block|{
return|return
name|SHA1_Update
argument_list|(
name|ctx
operator|->
name|md_data
argument_list|,
name|data
argument_list|,
name|count
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|final
parameter_list|(
name|EVP_MD_CTX
modifier|*
name|ctx
parameter_list|,
name|unsigned
name|char
modifier|*
name|md
parameter_list|)
block|{
return|return
name|SHA1_Final
argument_list|(
name|md
argument_list|,
name|ctx
operator|->
name|md_data
argument_list|)
return|;
block|}
end_function

begin_decl_stmt
specifier|static
specifier|const
name|EVP_MD
name|dsa_md
init|=
block|{
name|NID_dsaWithSHA
block|,
name|NID_dsaWithSHA
block|,
name|SHA_DIGEST_LENGTH
block|,
name|EVP_MD_FLAG_PKEY_DIGEST
block|,
name|init
block|,
name|update
block|,
name|final
block|,
name|NULL
block|,
name|NULL
block|,
name|EVP_PKEY_DSA_method
block|,
name|SHA_CBLOCK
block|,
sizeof|sizeof
argument_list|(
name|EVP_MD
operator|*
argument_list|)
operator|+
sizeof|sizeof
argument_list|(
name|SHA_CTX
argument_list|)
block|, }
decl_stmt|;
end_decl_stmt

begin_function
specifier|const
name|EVP_MD
modifier|*
name|EVP_dss
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
operator|&
name|dsa_md
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

