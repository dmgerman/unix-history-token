begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * crypto.h :  cryptographic routines  *  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_LIBSVN_SUBR_CRYPTO_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_LIBSVN_SUBR_CRYPTO_H
end_define

begin_comment
comment|/* Test for APR crypto and RNG support */
end_comment

begin_undef
undef|#
directive|undef
name|SVN_HAVE_CRYPTO
end_undef

begin_include
include|#
directive|include
file|<apr.h>
end_include

begin_include
include|#
directive|include
file|<apu.h>
end_include

begin_if
if|#
directive|if
name|APR_HAS_RANDOM
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|APU_HAVE_CRYPTO
argument_list|)
operator|&&
name|APU_HAVE_CRYPTO
end_if

begin_define
define|#
directive|define
name|SVN_HAVE_CRYPTO
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"svn_types.h"
end_include

begin_include
include|#
directive|include
file|"svn_string.h"
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
comment|/* __cplusplus */
comment|/* Opaque context for cryptographic operations.  */
typedef|typedef
name|struct
name|svn_crypto__ctx_t
name|svn_crypto__ctx_t
typedef|;
comment|/* Return TRUE iff Subversion's cryptographic support is available. */
name|svn_boolean_t
name|svn_crypto__is_available
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/* Set *CTX to new Subversion cryptographic context, based on an    APR-managed OpenSSL cryptography context object allocated    within RESULT_POOL.  */
comment|/* ### TODO: Should this be something done once with the resulting    ### svn_crypto__ctx_t object stored in svn_client_ctx_t?  */
name|svn_error_t
modifier|*
name|svn_crypto__context_create
parameter_list|(
name|svn_crypto__ctx_t
modifier|*
modifier|*
name|ctx
parameter_list|,
name|apr_pool_t
modifier|*
name|result_pool
parameter_list|)
function_decl|;
comment|/* Using a PBKDF2 derivative key based on MASTER, encrypt PLAINTEXT.    The salt used for PBKDF2 is returned in SALT, and the IV used for    the (AES-256/CBC) encryption is returned in IV. The resulting    encrypted data is returned in CIPHERTEXT.     Note that MASTER may be the plaintext obtained from the user or    some other OS-provided cryptographic store, or it can be a derivation    such as SHA1(plaintext). As long as the same octets are passed to    the decryption function, everything works just fine. (the SHA1    approach is suggested, to avoid keeping the plaintext master in    the process' memory space)  */
name|svn_error_t
modifier|*
name|svn_crypto__encrypt_password
parameter_list|(
specifier|const
name|svn_string_t
modifier|*
modifier|*
name|ciphertext
parameter_list|,
specifier|const
name|svn_string_t
modifier|*
modifier|*
name|iv
parameter_list|,
specifier|const
name|svn_string_t
modifier|*
modifier|*
name|salt
parameter_list|,
name|svn_crypto__ctx_t
modifier|*
name|ctx
parameter_list|,
specifier|const
name|char
modifier|*
name|plaintext
parameter_list|,
specifier|const
name|svn_string_t
modifier|*
name|master
parameter_list|,
name|apr_pool_t
modifier|*
name|result_pool
parameter_list|,
name|apr_pool_t
modifier|*
name|scratch_pool
parameter_list|)
function_decl|;
comment|/* Given the CIPHERTEXT which was encrypted using (AES-256/CBC) with    initialization vector given by IV, and a key derived using PBKDF2    with SALT and MASTER... return the decrypted password in PLAINTEXT.  */
name|svn_error_t
modifier|*
name|svn_crypto__decrypt_password
parameter_list|(
specifier|const
name|char
modifier|*
modifier|*
name|plaintext
parameter_list|,
name|svn_crypto__ctx_t
modifier|*
name|ctx
parameter_list|,
specifier|const
name|svn_string_t
modifier|*
name|ciphertext
parameter_list|,
specifier|const
name|svn_string_t
modifier|*
name|iv
parameter_list|,
specifier|const
name|svn_string_t
modifier|*
name|salt
parameter_list|,
specifier|const
name|svn_string_t
modifier|*
name|master
parameter_list|,
name|apr_pool_t
modifier|*
name|result_pool
parameter_list|,
name|apr_pool_t
modifier|*
name|scratch_pool
parameter_list|)
function_decl|;
comment|/* Generate the stuff Subversion needs to store in order to validate a    user-provided MASTER password:     Set *CIPHERTEXT to a block of encrypted data.     Set *IV and *SALT to the initialization vector and salt used for    encryption.     Set *CHECKTEXT to the check text used for validation.     CTX is a Subversion cryptographic context.  MASTER is the    encryption secret. */
name|svn_error_t
modifier|*
name|svn_crypto__generate_secret_checktext
parameter_list|(
specifier|const
name|svn_string_t
modifier|*
modifier|*
name|ciphertext
parameter_list|,
specifier|const
name|svn_string_t
modifier|*
modifier|*
name|iv
parameter_list|,
specifier|const
name|svn_string_t
modifier|*
modifier|*
name|salt
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|checktext
parameter_list|,
name|svn_crypto__ctx_t
modifier|*
name|ctx
parameter_list|,
specifier|const
name|svn_string_t
modifier|*
name|master
parameter_list|,
name|apr_pool_t
modifier|*
name|result_pool
parameter_list|,
name|apr_pool_t
modifier|*
name|scratch_pool
parameter_list|)
function_decl|;
comment|/* Set *IS_VALID to TRUE iff the encryption secret MASTER successfully    validates using Subversion cryptographic context CTX against    CIPHERTEXT, IV, SALT, and CHECKTEXT (which where probably generated    via previous call to svn_crypto__generate_secret_checktext()).     Use SCRATCH_POOL for necessary allocations. */
name|svn_error_t
modifier|*
name|svn_crypto__verify_secret
parameter_list|(
name|svn_boolean_t
modifier|*
name|is_valid
parameter_list|,
name|svn_crypto__ctx_t
modifier|*
name|ctx
parameter_list|,
specifier|const
name|svn_string_t
modifier|*
name|master
parameter_list|,
specifier|const
name|svn_string_t
modifier|*
name|ciphertext
parameter_list|,
specifier|const
name|svn_string_t
modifier|*
name|iv
parameter_list|,
specifier|const
name|svn_string_t
modifier|*
name|salt
parameter_list|,
specifier|const
name|char
modifier|*
name|checktext
parameter_list|,
name|apr_pool_t
modifier|*
name|scratch_pool
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

begin_comment
comment|/* __cplusplus */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SVN_LIBSVN_SUBR_CRYPTO_H */
end_comment

end_unit

