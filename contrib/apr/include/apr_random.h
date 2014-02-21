begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Licensed to the Apache Software Foundation (ASF) under one or more  * contributor license agreements.  See the NOTICE file distributed with  * this work for additional information regarding copyright ownership.  * The ASF licenses this file to You under the Apache License, Version 2.0  * (the "License"); you may not use this file except in compliance with  * the License.  You may obtain a copy of the License at  *  *     http://www.apache.org/licenses/LICENSE-2.0  *  * Unless required by applicable law or agreed to in writing, software  * distributed under the License is distributed on an "AS IS" BASIS,  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  * See the License for the specific language governing permissions and  * limitations under the License.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|APR_RANDOM_H
end_ifndef

begin_define
define|#
directive|define
name|APR_RANDOM_H
end_define

begin_comment
comment|/**  * @file apr_random.h  * @brief APR PRNG routines  */
end_comment

begin_include
include|#
directive|include
file|"apr_pools.h"
end_include

begin_include
include|#
directive|include
file|"apr_thread_proc.h"
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
comment|/**  * @defgroup apr_random PRNG Routines  * @ingroup APR  * @{  */
typedef|typedef
name|struct
name|apr_crypto_hash_t
name|apr_crypto_hash_t
typedef|;
typedef|typedef
name|void
name|apr_crypto_hash_init_t
parameter_list|(
name|apr_crypto_hash_t
modifier|*
name|hash
parameter_list|)
function_decl|;
typedef|typedef
name|void
name|apr_crypto_hash_add_t
parameter_list|(
name|apr_crypto_hash_t
modifier|*
name|hash
parameter_list|,
specifier|const
name|void
modifier|*
name|data
parameter_list|,
name|apr_size_t
name|bytes
parameter_list|)
function_decl|;
typedef|typedef
name|void
name|apr_crypto_hash_finish_t
parameter_list|(
name|apr_crypto_hash_t
modifier|*
name|hash
parameter_list|,
name|unsigned
name|char
modifier|*
name|result
parameter_list|)
function_decl|;
comment|/* FIXME: make this opaque */
struct|struct
name|apr_crypto_hash_t
block|{
name|apr_crypto_hash_init_t
modifier|*
name|init
decl_stmt|;
name|apr_crypto_hash_add_t
modifier|*
name|add
decl_stmt|;
name|apr_crypto_hash_finish_t
modifier|*
name|finish
decl_stmt|;
name|apr_size_t
name|size
decl_stmt|;
name|void
modifier|*
name|data
decl_stmt|;
block|}
struct|;
comment|/**  * Allocate and initialize the SHA-256 context  * @param p The pool to allocate from  */
name|APR_DECLARE
argument_list|(
argument|apr_crypto_hash_t *
argument_list|)
name|apr_crypto_sha256_new
argument_list|(
name|apr_pool_t
operator|*
name|p
argument_list|)
expr_stmt|;
comment|/** Opaque PRNG structure. */
typedef|typedef
name|struct
name|apr_random_t
name|apr_random_t
typedef|;
comment|/**  * Initialize a PRNG state  * @param g The PRNG state  * @param p The pool to allocate from  * @param pool_hash Pool hash functions  * @param key_hash Key hash functions  * @param prng_hash PRNG hash functions  */
name|APR_DECLARE
argument_list|(
argument|void
argument_list|)
name|apr_random_init
argument_list|(
name|apr_random_t
operator|*
name|g
argument_list|,
name|apr_pool_t
operator|*
name|p
argument_list|,
name|apr_crypto_hash_t
operator|*
name|pool_hash
argument_list|,
name|apr_crypto_hash_t
operator|*
name|key_hash
argument_list|,
name|apr_crypto_hash_t
operator|*
name|prng_hash
argument_list|)
expr_stmt|;
comment|/**  * Allocate and initialize (apr_crypto_sha256_new) a new PRNG state.  * @param p The pool to allocate from  */
name|APR_DECLARE
argument_list|(
argument|apr_random_t *
argument_list|)
name|apr_random_standard_new
argument_list|(
name|apr_pool_t
operator|*
name|p
argument_list|)
expr_stmt|;
comment|/**  * Mix the randomness pools.  * @param g The PRNG state  * @param entropy_ Entropy buffer  * @param bytes Length of entropy_ in bytes  */
name|APR_DECLARE
argument_list|(
argument|void
argument_list|)
name|apr_random_add_entropy
argument_list|(
argument|apr_random_t *g
argument_list|,
argument|const void *entropy_
argument_list|,
argument|apr_size_t bytes
argument_list|)
empty_stmt|;
comment|/**  * Generate cryptographically insecure random bytes.  * @param g The RNG state  * @param random Buffer to fill with random bytes  * @param bytes Length of buffer in bytes  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_random_insecure_bytes
argument_list|(
argument|apr_random_t *g
argument_list|,
argument|void *random
argument_list|,
argument|apr_size_t bytes
argument_list|)
empty_stmt|;
comment|/**  * Generate cryptographically secure random bytes.  * @param g The RNG state  * @param random Buffer to fill with random bytes  * @param bytes Length of buffer in bytes  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_random_secure_bytes
argument_list|(
argument|apr_random_t *g
argument_list|,
argument|void *random
argument_list|,
argument|apr_size_t bytes
argument_list|)
empty_stmt|;
comment|/**  * Ensures that E bits of conditional entropy are mixed into the PRNG  * before any further randomness is extracted.  * @param g The RNG state  */
name|APR_DECLARE
argument_list|(
argument|void
argument_list|)
name|apr_random_barrier
argument_list|(
name|apr_random_t
operator|*
name|g
argument_list|)
expr_stmt|;
comment|/**  * Return APR_SUCCESS if the cryptographic PRNG has been seeded with  * enough data, APR_ENOTENOUGHENTROPY otherwise.  * @param r The RNG state  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_random_secure_ready
argument_list|(
name|apr_random_t
operator|*
name|r
argument_list|)
expr_stmt|;
comment|/**  * Return APR_SUCCESS if the PRNG has been seeded with enough data,  * APR_ENOTENOUGHENTROPY otherwise.  * @param r The PRNG state  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_random_insecure_ready
argument_list|(
name|apr_random_t
operator|*
name|r
argument_list|)
expr_stmt|;
comment|/**  * Mix the randomness pools after forking.  * @param proc The resulting process handle from apr_proc_fork()  * @remark Call this in the child after forking to mix the randomness  * pools. Note that its generally a bad idea to fork a process with a  * real PRNG in it - better to have the PRNG externally and get the  * randomness from there. However, if you really must do it, then you  * should supply all your entropy to all the PRNGs - don't worry, they  * won't produce the same output.  * @remark Note that apr_proc_fork() calls this for you, so only weird  * applications need ever call it themselves.  * @internal  */
name|APR_DECLARE
argument_list|(
argument|void
argument_list|)
name|apr_random_after_fork
argument_list|(
name|apr_proc_t
operator|*
name|proc
argument_list|)
expr_stmt|;
comment|/** @} */
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
comment|/* !APR_RANDOM_H */
end_comment

end_unit

