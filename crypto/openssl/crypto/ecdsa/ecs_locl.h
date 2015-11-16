begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* crypto/ecdsa/ecs_locl.h */
end_comment

begin_comment
comment|/*  * Written by Nils Larsch for the OpenSSL project  */
end_comment

begin_comment
comment|/* ====================================================================  * Copyright (c) 2000-2005 The OpenSSL Project.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *  * 3. All advertising materials mentioning features or use of this  *    software must display the following acknowledgment:  *    "This product includes software developed by the OpenSSL Project  *    for use in the OpenSSL Toolkit. (http://www.OpenSSL.org/)"  *  * 4. The names "OpenSSL Toolkit" and "OpenSSL Project" must not be used to  *    endorse or promote products derived from this software without  *    prior written permission. For written permission, please contact  *    licensing@OpenSSL.org.  *  * 5. Products derived from this software may not be called "OpenSSL"  *    nor may "OpenSSL" appear in their names without prior written  *    permission of the OpenSSL Project.  *  * 6. Redistributions of any form whatsoever must retain the following  *    acknowledgment:  *    "This product includes software developed by the OpenSSL Project  *    for use in the OpenSSL Toolkit (http://www.OpenSSL.org/)"  *  * THIS SOFTWARE IS PROVIDED BY THE OpenSSL PROJECT ``AS IS'' AND ANY  * EXPRESSED OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE OpenSSL PROJECT OR  * ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED  * OF THE POSSIBILITY OF SUCH DAMAGE.  * ====================================================================  *  * This product includes cryptographic software written by Eric Young  * (eay@cryptsoft.com).  This product includes software written by Tim  * Hudson (tjh@cryptsoft.com).  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HEADER_ECS_LOCL_H
end_ifndef

begin_define
define|#
directive|define
name|HEADER_ECS_LOCL_H
end_define

begin_include
include|#
directive|include
file|<openssl/ecdsa.h>
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
struct|struct
name|ecdsa_method
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|ECDSA_SIG
modifier|*
function_decl|(
modifier|*
name|ecdsa_do_sign
function_decl|)
parameter_list|(
specifier|const
name|unsigned
name|char
modifier|*
name|dgst
parameter_list|,
name|int
name|dgst_len
parameter_list|,
specifier|const
name|BIGNUM
modifier|*
name|inv
parameter_list|,
specifier|const
name|BIGNUM
modifier|*
name|rp
parameter_list|,
name|EC_KEY
modifier|*
name|eckey
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|ecdsa_sign_setup
function_decl|)
parameter_list|(
name|EC_KEY
modifier|*
name|eckey
parameter_list|,
name|BN_CTX
modifier|*
name|ctx
parameter_list|,
name|BIGNUM
modifier|*
modifier|*
name|kinv
parameter_list|,
name|BIGNUM
modifier|*
modifier|*
name|r
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|ecdsa_do_verify
function_decl|)
parameter_list|(
specifier|const
name|unsigned
name|char
modifier|*
name|dgst
parameter_list|,
name|int
name|dgst_len
parameter_list|,
specifier|const
name|ECDSA_SIG
modifier|*
name|sig
parameter_list|,
name|EC_KEY
modifier|*
name|eckey
parameter_list|)
function_decl|;
if|#
directive|if
literal|0
block|int (*init) (EC_KEY *eckey);     int (*finish) (EC_KEY *eckey);
endif|#
directive|endif
name|int
name|flags
decl_stmt|;
name|void
modifier|*
name|app_data
decl_stmt|;
block|}
struct|;
comment|/* The ECDSA_METHOD was allocated and can be freed */
define|#
directive|define
name|ECDSA_METHOD_FLAG_ALLOCATED
value|0x2
comment|/*  * If this flag is set the ECDSA method is FIPS compliant and can be used in  * FIPS mode. This is set in the validated module method. If an application  * sets this flag in its own methods it is its responsibility to ensure the  * result is compliant.  */
define|#
directive|define
name|ECDSA_FLAG_FIPS_METHOD
value|0x1
typedef|typedef
struct|struct
name|ecdsa_data_st
block|{
comment|/* EC_KEY_METH_DATA part */
name|int
function_decl|(
modifier|*
name|init
function_decl|)
parameter_list|(
name|EC_KEY
modifier|*
parameter_list|)
function_decl|;
comment|/* method (ECDSA) specific part */
name|ENGINE
modifier|*
name|engine
decl_stmt|;
name|int
name|flags
decl_stmt|;
specifier|const
name|ECDSA_METHOD
modifier|*
name|meth
decl_stmt|;
name|CRYPTO_EX_DATA
name|ex_data
decl_stmt|;
block|}
name|ECDSA_DATA
typedef|;
comment|/** ecdsa_check  * checks whether ECKEY->meth_data is a pointer to a ECDSA_DATA structure  * and if not it removes the old meth_data and creates a ECDSA_DATA structure.  * \param  eckey pointer to a EC_KEY object  * \return pointer to a ECDSA_DATA structure  */
name|ECDSA_DATA
modifier|*
name|ecdsa_check
parameter_list|(
name|EC_KEY
modifier|*
name|eckey
parameter_list|)
function_decl|;
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

begin_comment
comment|/* HEADER_ECS_LOCL_H */
end_comment

end_unit

