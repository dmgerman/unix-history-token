begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* crypto/ecdh/ecdh.h */
end_comment

begin_comment
comment|/* ====================================================================  * Copyright 2002 Sun Microsystems, Inc. ALL RIGHTS RESERVED.  *  * The Elliptic Curve Public-Key Crypto Library (ECC Code) included  * herein is developed by SUN MICROSYSTEMS, INC., and is contributed  * to the OpenSSL project.  *  * The ECC Code is licensed pursuant to the OpenSSL open source  * license provided below.  *  * The ECDH software is originally written by Douglas Stebila of  * Sun Microsystems Laboratories.  *  */
end_comment

begin_comment
comment|/* ====================================================================  * Copyright (c) 2000-2002 The OpenSSL Project.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.   *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *  * 3. All advertising materials mentioning features or use of this  *    software must display the following acknowledgment:  *    "This product includes software developed by the OpenSSL Project  *    for use in the OpenSSL Toolkit. (http://www.OpenSSL.org/)"  *  * 4. The names "OpenSSL Toolkit" and "OpenSSL Project" must not be used to  *    endorse or promote products derived from this software without  *    prior written permission. For written permission, please contact  *    licensing@OpenSSL.org.  *  * 5. Products derived from this software may not be called "OpenSSL"  *    nor may "OpenSSL" appear in their names without prior written  *    permission of the OpenSSL Project.  *  * 6. Redistributions of any form whatsoever must retain the following  *    acknowledgment:  *    "This product includes software developed by the OpenSSL Project  *    for use in the OpenSSL Toolkit (http://www.OpenSSL.org/)"  *  * THIS SOFTWARE IS PROVIDED BY THE OpenSSL PROJECT ``AS IS'' AND ANY  * EXPRESSED OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE OpenSSL PROJECT OR  * ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED  * OF THE POSSIBILITY OF SUCH DAMAGE.  * ====================================================================  *  * This product includes cryptographic software written by Eric Young  * (eay@cryptsoft.com).  This product includes software written by Tim  * Hudson (tjh@cryptsoft.com).  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HEADER_ECDH_H
end_ifndef

begin_define
define|#
directive|define
name|HEADER_ECDH_H
end_define

begin_include
include|#
directive|include
file|<openssl/opensslconf.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|OPENSSL_NO_ECDH
end_ifdef

begin_error
error|#
directive|error
error|ECDH is disabled.
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<openssl/ec.h>
end_include

begin_include
include|#
directive|include
file|<openssl/ossl_typ.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|OPENSSL_NO_DEPRECATED
end_ifndef

begin_include
include|#
directive|include
file|<openssl/bn.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

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
specifier|const
name|ECDH_METHOD
modifier|*
name|ECDH_OpenSSL
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|void
name|ECDH_set_default_method
parameter_list|(
specifier|const
name|ECDH_METHOD
modifier|*
parameter_list|)
function_decl|;
specifier|const
name|ECDH_METHOD
modifier|*
name|ECDH_get_default_method
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|int
name|ECDH_set_method
parameter_list|(
name|EC_KEY
modifier|*
parameter_list|,
specifier|const
name|ECDH_METHOD
modifier|*
parameter_list|)
function_decl|;
name|int
name|ECDH_compute_key
parameter_list|(
name|void
modifier|*
name|out
parameter_list|,
name|size_t
name|outlen
parameter_list|,
specifier|const
name|EC_POINT
modifier|*
name|pub_key
parameter_list|,
name|EC_KEY
modifier|*
name|ecdh
parameter_list|,
name|void
modifier|*
function_decl|(
modifier|*
name|KDF
function_decl|)
parameter_list|(
specifier|const
name|void
modifier|*
name|in
parameter_list|,
name|size_t
name|inlen
parameter_list|,
name|void
modifier|*
name|out
parameter_list|,
name|size_t
modifier|*
name|outlen
parameter_list|)
parameter_list|)
function_decl|;
name|int
name|ECDH_get_ex_new_index
parameter_list|(
name|long
name|argl
parameter_list|,
name|void
modifier|*
name|argp
parameter_list|,
name|CRYPTO_EX_new
modifier|*
name|new_func
parameter_list|,
name|CRYPTO_EX_dup
modifier|*
name|dup_func
parameter_list|,
name|CRYPTO_EX_free
modifier|*
name|free_func
parameter_list|)
function_decl|;
name|int
name|ECDH_set_ex_data
parameter_list|(
name|EC_KEY
modifier|*
name|d
parameter_list|,
name|int
name|idx
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
name|void
modifier|*
name|ECDH_get_ex_data
parameter_list|(
name|EC_KEY
modifier|*
name|d
parameter_list|,
name|int
name|idx
parameter_list|)
function_decl|;
comment|/* BEGIN ERROR CODES */
comment|/* The following lines are auto generated by the script mkerr.pl. Any changes  * made after this point may be overwritten when the script is next run.  */
name|void
name|ERR_load_ECDH_strings
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/* Error codes for the ECDH functions. */
comment|/* Function codes. */
define|#
directive|define
name|ECDH_F_ECDH_COMPUTE_KEY
value|100
define|#
directive|define
name|ECDH_F_ECDH_DATA_NEW_METHOD
value|101
comment|/* Reason codes. */
define|#
directive|define
name|ECDH_R_KDF_FAILED
value|102
define|#
directive|define
name|ECDH_R_NO_PRIVATE_VALUE
value|100
define|#
directive|define
name|ECDH_R_POINT_ARITHMETIC_FAILURE
value|101
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

