begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Licensed to the Apache Software Foundation (ASF) under one or more  * contributor license agreements.  See the NOTICE file distributed with  * this work for additional information regarding copyright ownership.  * The ASF licenses this file to You under the Apache License, Version 2.0  * (the "License"); you may not use this file except in compliance with  * the License.  You may obtain a copy of the License at  *  *     http://www.apache.org/licenses/LICENSE-2.0  *  * Unless required by applicable law or agreed to in writing, software  * distributed under the License is distributed on an "AS IS" BASIS,  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  * See the License for the specific language governing permissions and  * limitations under the License.  */
end_comment

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"apu_config.h"
end_include

begin_include
include|#
directive|include
file|"apu.h"
end_include

begin_include
include|#
directive|include
file|"apr_pools.h"
end_include

begin_include
include|#
directive|include
file|"apr_dso.h"
end_include

begin_include
include|#
directive|include
file|"apr_strings.h"
end_include

begin_include
include|#
directive|include
file|"apr_hash.h"
end_include

begin_include
include|#
directive|include
file|"apr_thread_mutex.h"
end_include

begin_include
include|#
directive|include
file|"apr_lib.h"
end_include

begin_if
if|#
directive|if
name|APU_HAVE_CRYPTO
end_if

begin_include
include|#
directive|include
file|"apu_internal.h"
end_include

begin_include
include|#
directive|include
file|"apr_crypto_internal.h"
end_include

begin_include
include|#
directive|include
file|"apr_crypto.h"
end_include

begin_include
include|#
directive|include
file|"apu_version.h"
end_include

begin_decl_stmt
specifier|static
name|apr_hash_t
modifier|*
name|drivers
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|ERROR_SIZE
value|1024
end_define

begin_define
define|#
directive|define
name|CLEANUP_CAST
value|(apr_status_t (*)(void*))
end_define

begin_define
define|#
directive|define
name|APR_TYPEDEF_STRUCT
parameter_list|(
name|type
parameter_list|,
name|incompletion
parameter_list|)
define|\
value|struct type { \    incompletion \    void *unk[]; \ };
end_define

begin_macro
name|APR_TYPEDEF_STRUCT
argument_list|(
argument|apr_crypto_t
argument_list|,
argument|apr_pool_t *pool;     apr_crypto_driver_t *provider;
argument_list|)
end_macro

begin_macro
name|APR_TYPEDEF_STRUCT
argument_list|(
argument|apr_crypto_key_t
argument_list|,
argument|apr_pool_t *pool;     apr_crypto_driver_t *provider;     const apr_crypto_t *f;
argument_list|)
end_macro

begin_macro
name|APR_TYPEDEF_STRUCT
argument_list|(
argument|apr_crypto_block_t
argument_list|,
argument|apr_pool_t *pool;     apr_crypto_driver_t *provider;     const apr_crypto_t *f;
argument_list|)
end_macro

begin_typedef
typedef|typedef
struct|struct
name|apr_crypto_clear_t
block|{
name|void
modifier|*
name|buffer
decl_stmt|;
name|apr_size_t
name|size
decl_stmt|;
block|}
name|apr_crypto_clear_t
typedef|;
end_typedef

begin_if
if|#
directive|if
operator|!
name|APU_DSO_BUILD
end_if

begin_define
define|#
directive|define
name|DRIVER_LOAD
parameter_list|(
name|name
parameter_list|,
name|driver_name
parameter_list|,
name|pool
parameter_list|,
name|params
parameter_list|,
name|rv
parameter_list|,
name|result
parameter_list|)
define|\
value|{   \         extern const apr_crypto_driver_t driver_name; \         apr_hash_set(drivers,name,APR_HASH_KEY_STRING,&driver_name); \         if (driver_name.init) {     \             rv = driver_name.init(pool, params, result); \         }  \         *driver =&driver_name; \     }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function
specifier|static
name|apr_status_t
name|apr_crypto_term
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|)
block|{
comment|/* set drivers to NULL so init can work again */
name|drivers
operator|=
name|NULL
expr_stmt|;
comment|/* Everything else we need is handled by cleanups registered      * when we created mutexes and loaded DSOs      */
return|return
name|APR_SUCCESS
return|;
block|}
end_function

begin_macro
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
end_macro

begin_macro
name|apr_crypto_init
argument_list|(
argument|apr_pool_t *pool
argument_list|)
end_macro

begin_block
block|{
name|apr_status_t
name|ret
init|=
name|APR_SUCCESS
decl_stmt|;
name|apr_pool_t
modifier|*
name|parent
decl_stmt|;
if|if
condition|(
name|drivers
operator|!=
name|NULL
condition|)
block|{
return|return
name|APR_SUCCESS
return|;
block|}
comment|/* Top level pool scope, need process-scope lifetime */
for|for
control|(
name|parent
operator|=
name|apr_pool_parent_get
argument_list|(
name|pool
argument_list|)
init|;
name|parent
operator|&&
name|parent
operator|!=
name|pool
condition|;
name|parent
operator|=
name|apr_pool_parent_get
argument_list|(
name|pool
argument_list|)
control|)
name|pool
operator|=
name|parent
expr_stmt|;
if|#
directive|if
name|APU_DSO_BUILD
comment|/* deprecate in 2.0 - permit implicit initialization */
name|apu_dso_init
argument_list|(
name|pool
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|drivers
operator|=
name|apr_hash_make
argument_list|(
name|pool
argument_list|)
expr_stmt|;
name|apr_pool_cleanup_register
argument_list|(
name|pool
argument_list|,
name|NULL
argument_list|,
name|apr_crypto_term
argument_list|,
name|apr_pool_cleanup_null
argument_list|)
expr_stmt|;
return|return
name|ret
return|;
block|}
end_block

begin_function
specifier|static
name|apr_status_t
name|crypto_clear
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|)
block|{
name|apr_crypto_clear_t
modifier|*
name|clear
init|=
operator|(
name|apr_crypto_clear_t
operator|*
operator|)
name|ptr
decl_stmt|;
name|memset
argument_list|(
name|clear
operator|->
name|buffer
argument_list|,
literal|0
argument_list|,
name|clear
operator|->
name|size
argument_list|)
expr_stmt|;
name|clear
operator|->
name|buffer
operator|=
name|NULL
expr_stmt|;
name|clear
operator|->
name|size
operator|=
literal|0
expr_stmt|;
return|return
name|APR_SUCCESS
return|;
block|}
end_function

begin_macro
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
end_macro

begin_macro
name|apr_crypto_clear
argument_list|(
argument|apr_pool_t *pool
argument_list|,
argument|void *buffer
argument_list|,
argument|apr_size_t size
argument_list|)
end_macro

begin_block
block|{
name|apr_crypto_clear_t
modifier|*
name|clear
init|=
name|apr_palloc
argument_list|(
name|pool
argument_list|,
sizeof|sizeof
argument_list|(
name|apr_crypto_clear_t
argument_list|)
argument_list|)
decl_stmt|;
name|clear
operator|->
name|buffer
operator|=
name|buffer
expr_stmt|;
name|clear
operator|->
name|size
operator|=
name|size
expr_stmt|;
name|apr_pool_cleanup_register
argument_list|(
name|pool
argument_list|,
name|clear
argument_list|,
name|crypto_clear
argument_list|,
name|apr_pool_cleanup_null
argument_list|)
expr_stmt|;
return|return
name|APR_SUCCESS
return|;
block|}
end_block

begin_macro
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
end_macro

begin_macro
name|apr_crypto_get_driver
argument_list|(
argument|const apr_crypto_driver_t **driver
argument_list|,
argument|const char *name
argument_list|,
argument|const char *params
argument_list|,
argument|const apu_err_t **result
argument_list|,
argument|apr_pool_t *pool
argument_list|)
end_macro

begin_block
block|{
if|#
directive|if
name|APU_DSO_BUILD
name|char
name|modname
index|[
literal|32
index|]
decl_stmt|;
name|char
name|symname
index|[
literal|34
index|]
decl_stmt|;
name|apr_dso_handle_t
modifier|*
name|dso
decl_stmt|;
name|apr_dso_handle_sym_t
name|symbol
decl_stmt|;
endif|#
directive|endif
name|apr_status_t
name|rv
decl_stmt|;
if|if
condition|(
name|result
condition|)
block|{
operator|*
name|result
operator|=
name|NULL
expr_stmt|;
comment|/* until further notice */
block|}
if|#
directive|if
name|APU_DSO_BUILD
name|rv
operator|=
name|apu_dso_mutex_lock
argument_list|()
expr_stmt|;
if|if
condition|(
name|rv
condition|)
block|{
return|return
name|rv
return|;
block|}
endif|#
directive|endif
operator|*
name|driver
operator|=
name|apr_hash_get
argument_list|(
name|drivers
argument_list|,
name|name
argument_list|,
name|APR_HASH_KEY_STRING
argument_list|)
expr_stmt|;
if|if
condition|(
operator|*
name|driver
condition|)
block|{
if|#
directive|if
name|APU_DSO_BUILD
name|apu_dso_mutex_unlock
argument_list|()
expr_stmt|;
endif|#
directive|endif
return|return
name|APR_SUCCESS
return|;
block|}
if|#
directive|if
name|APU_DSO_BUILD
comment|/* The driver DSO must have exactly the same lifetime as the      * drivers hash table; ignore the passed-in pool */
name|pool
operator|=
name|apr_hash_pool_get
argument_list|(
name|drivers
argument_list|)
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|NETWARE
argument_list|)
name|apr_snprintf
argument_list|(
name|modname
argument_list|,
sizeof|sizeof
argument_list|(
name|modname
argument_list|)
argument_list|,
literal|"crypto%s.nlm"
argument_list|,
name|name
argument_list|)
expr_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|WIN32
argument_list|)
operator|||
name|defined
argument_list|(
name|__CYGWIN__
argument_list|)
name|apr_snprintf
argument_list|(
name|modname
argument_list|,
sizeof|sizeof
argument_list|(
name|modname
argument_list|)
argument_list|,
literal|"apr_crypto_%s-"
name|APU_STRINGIFY
argument_list|(
name|APU_MAJOR_VERSION
argument_list|)
literal|".dll"
argument_list|,
name|name
argument_list|)
expr_stmt|;
else|#
directive|else
name|apr_snprintf
argument_list|(
name|modname
argument_list|,
sizeof|sizeof
argument_list|(
name|modname
argument_list|)
argument_list|,
literal|"apr_crypto_%s-"
name|APU_STRINGIFY
argument_list|(
name|APU_MAJOR_VERSION
argument_list|)
literal|".so"
argument_list|,
name|name
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|apr_snprintf
argument_list|(
name|symname
argument_list|,
sizeof|sizeof
argument_list|(
name|symname
argument_list|)
argument_list|,
literal|"apr_crypto_%s_driver"
argument_list|,
name|name
argument_list|)
expr_stmt|;
name|rv
operator|=
name|apu_dso_load
argument_list|(
operator|&
name|dso
argument_list|,
operator|&
name|symbol
argument_list|,
name|modname
argument_list|,
name|symname
argument_list|,
name|pool
argument_list|)
expr_stmt|;
if|if
condition|(
name|rv
operator|==
name|APR_SUCCESS
operator|||
name|rv
operator|==
name|APR_EINIT
condition|)
block|{
comment|/* previously loaded?!? */
operator|*
name|driver
operator|=
name|symbol
expr_stmt|;
name|name
operator|=
name|apr_pstrdup
argument_list|(
name|pool
argument_list|,
name|name
argument_list|)
expr_stmt|;
name|apr_hash_set
argument_list|(
name|drivers
argument_list|,
name|name
argument_list|,
name|APR_HASH_KEY_STRING
argument_list|,
operator|*
name|driver
argument_list|)
expr_stmt|;
name|rv
operator|=
name|APR_SUCCESS
expr_stmt|;
if|if
condition|(
operator|(
operator|*
name|driver
operator|)
operator|->
name|init
condition|)
block|{
name|rv
operator|=
operator|(
operator|*
name|driver
operator|)
operator|->
name|init
argument_list|(
name|pool
argument_list|,
name|params
argument_list|,
name|result
argument_list|)
expr_stmt|;
block|}
block|}
name|apu_dso_mutex_unlock
argument_list|()
expr_stmt|;
if|if
condition|(
name|APR_SUCCESS
operator|!=
name|rv
operator|&&
name|result
operator|&&
operator|!
operator|*
name|result
condition|)
block|{
name|char
modifier|*
name|buffer
init|=
name|apr_pcalloc
argument_list|(
name|pool
argument_list|,
name|ERROR_SIZE
argument_list|)
decl_stmt|;
name|apu_err_t
modifier|*
name|err
init|=
name|apr_pcalloc
argument_list|(
name|pool
argument_list|,
sizeof|sizeof
argument_list|(
name|apu_err_t
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|err
operator|&&
name|buffer
condition|)
block|{
name|apr_dso_error
argument_list|(
name|dso
argument_list|,
name|buffer
argument_list|,
name|ERROR_SIZE
operator|-
literal|1
argument_list|)
expr_stmt|;
name|err
operator|->
name|msg
operator|=
name|buffer
expr_stmt|;
name|err
operator|->
name|reason
operator|=
name|apr_pstrdup
argument_list|(
name|pool
argument_list|,
name|modname
argument_list|)
expr_stmt|;
operator|*
name|result
operator|=
name|err
expr_stmt|;
block|}
block|}
else|#
directive|else
comment|/* not builtin and !APR_HAS_DSO => not implemented */
name|rv
operator|=
name|APR_ENOTIMPL
expr_stmt|;
comment|/* Load statically-linked drivers: */
if|#
directive|if
name|APU_HAVE_OPENSSL
if|if
condition|(
name|name
index|[
literal|0
index|]
operator|==
literal|'o'
operator|&&
operator|!
name|strcmp
argument_list|(
name|name
argument_list|,
literal|"openssl"
argument_list|)
condition|)
block|{
name|DRIVER_LOAD
argument_list|(
literal|"openssl"
argument_list|,
name|apr_crypto_openssl_driver
argument_list|,
name|pool
argument_list|,
name|params
argument_list|,
name|rv
argument_list|,
name|result
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
if|#
directive|if
name|APU_HAVE_NSS
if|if
condition|(
name|name
index|[
literal|0
index|]
operator|==
literal|'n'
operator|&&
operator|!
name|strcmp
argument_list|(
name|name
argument_list|,
literal|"nss"
argument_list|)
condition|)
block|{
name|DRIVER_LOAD
argument_list|(
literal|"nss"
argument_list|,
name|apr_crypto_nss_driver
argument_list|,
name|pool
argument_list|,
name|params
argument_list|,
name|rv
argument_list|,
name|result
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
if|#
directive|if
name|APU_HAVE_MSCAPI
if|if
condition|(
name|name
index|[
literal|0
index|]
operator|==
literal|'m'
operator|&&
operator|!
name|strcmp
argument_list|(
name|name
argument_list|,
literal|"mscapi"
argument_list|)
condition|)
block|{
name|DRIVER_LOAD
argument_list|(
literal|"mscapi"
argument_list|,
name|apr_crypto_mscapi_driver
argument_list|,
name|pool
argument_list|,
name|params
argument_list|,
name|rv
argument_list|,
name|result
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
if|#
directive|if
name|APU_HAVE_MSCNG
if|if
condition|(
name|name
index|[
literal|0
index|]
operator|==
literal|'m'
operator|&&
operator|!
name|strcmp
argument_list|(
name|name
argument_list|,
literal|"mscng"
argument_list|)
condition|)
block|{
name|DRIVER_LOAD
argument_list|(
literal|"mscng"
argument_list|,
name|apr_crypto_mscng_driver
argument_list|,
name|pool
argument_list|,
name|params
argument_list|,
name|rv
argument_list|,
name|result
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
endif|#
directive|endif
return|return
name|rv
return|;
block|}
end_block

begin_comment
comment|/**  * @brief Return the name of the driver.  *  * @param driver - The driver in use.  * @return The name of the driver.  */
end_comment

begin_macro
name|APU_DECLARE
argument_list|(
argument|const char *
argument_list|)
end_macro

begin_macro
name|apr_crypto_driver_name
argument_list|(
argument|const apr_crypto_driver_t *driver
argument_list|)
end_macro

begin_block
block|{
return|return
name|driver
operator|->
name|name
return|;
block|}
end_block

begin_comment
comment|/**  * @brief Get the result of the last operation on a context. If the result  *        is NULL, the operation was successful.  * @param result - the result structure  * @param f - context pointer  * @return APR_SUCCESS for success  */
end_comment

begin_macro
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
end_macro

begin_macro
name|apr_crypto_error
argument_list|(
argument|const apu_err_t **result
argument_list|,
argument|const apr_crypto_t *f
argument_list|)
end_macro

begin_block
block|{
return|return
name|f
operator|->
name|provider
operator|->
name|error
argument_list|(
name|result
argument_list|,
name|f
argument_list|)
return|;
block|}
end_block

begin_comment
comment|/**  * @brief Create a context for supporting encryption. Keys, certificates,  *        algorithms and other parameters will be set per context. More than  *        one context can be created at one time. A cleanup will be automatically  *        registered with the given pool to guarantee a graceful shutdown.  * @param f - context pointer will be written here  * @param driver - driver to use  * @param params - array of key parameters  * @param pool - process pool  * @return APR_ENOENGINE when the engine specified does not exist. APR_EINITENGINE  * if the engine cannot be initialised.  * @remarks NSS: currently no params are supported.  * @remarks OpenSSL: the params can have "engine" as a key, followed by an equal  *  sign and a value.  */
end_comment

begin_macro
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
end_macro

begin_macro
name|apr_crypto_make
argument_list|(
argument|apr_crypto_t **f
argument_list|,
argument|const apr_crypto_driver_t *driver
argument_list|,
argument|const char *params
argument_list|,
argument|apr_pool_t *pool
argument_list|)
end_macro

begin_block
block|{
return|return
name|driver
operator|->
name|make
argument_list|(
name|f
argument_list|,
name|driver
argument_list|,
name|params
argument_list|,
name|pool
argument_list|)
return|;
block|}
end_block

begin_comment
comment|/**  * @brief Get a hash table of key types, keyed by the name of the type against  * an integer pointer constant.  *  * @param types - hashtable of key types keyed to constants.  * @param f - encryption context  * @return APR_SUCCESS for success  */
end_comment

begin_macro
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
end_macro

begin_macro
name|apr_crypto_get_block_key_types
argument_list|(
argument|apr_hash_t **types
argument_list|,
argument|const apr_crypto_t *f
argument_list|)
end_macro

begin_block
block|{
return|return
name|f
operator|->
name|provider
operator|->
name|get_block_key_types
argument_list|(
name|types
argument_list|,
name|f
argument_list|)
return|;
block|}
end_block

begin_comment
comment|/**  * @brief Get a hash table of key modes, keyed by the name of the mode against  * an integer pointer constant.  *  * @param modes - hashtable of key modes keyed to constants.  * @param f - encryption context  * @return APR_SUCCESS for success  */
end_comment

begin_macro
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
end_macro

begin_macro
name|apr_crypto_get_block_key_modes
argument_list|(
argument|apr_hash_t **modes
argument_list|,
argument|const apr_crypto_t *f
argument_list|)
end_macro

begin_block
block|{
return|return
name|f
operator|->
name|provider
operator|->
name|get_block_key_modes
argument_list|(
name|modes
argument_list|,
name|f
argument_list|)
return|;
block|}
end_block

begin_comment
comment|/**  * @brief Create a key from the given passphrase. By default, the PBKDF2  *        algorithm is used to generate the key from the passphrase. It is expected  *        that the same pass phrase will generate the same key, regardless of the  *        backend crypto platform used. The key is cleaned up when the context  *        is cleaned, and may be reused with multiple encryption or decryption  *        operations.  * @note If *key is NULL, a apr_crypto_key_t will be created from a pool. If  *       *key is not NULL, *key must point at a previously created structure.  * @param key The key returned, see note.  * @param ivSize The size of the initialisation vector will be returned, based  *               on whether an IV is relevant for this type of crypto.  * @param pass The passphrase to use.  * @param passLen The passphrase length in bytes  * @param salt The salt to use.  * @param saltLen The salt length in bytes  * @param type 3DES_192, AES_128, AES_192, AES_256.  * @param mode Electronic Code Book / Cipher Block Chaining.  * @param doPad Pad if necessary.  * @param iterations Number of iterations to use in algorithm  * @param f The context to use.  * @param p The pool to use.  * @return Returns APR_ENOKEY if the pass phrase is missing or empty, or if a backend  *         error occurred while generating the key. APR_ENOCIPHER if the type or mode  *         is not supported by the particular backend. APR_EKEYTYPE if the key type is  *         not known. APR_EPADDING if padding was requested but is not supported.  *         APR_ENOTIMPL if not implemented.  */
end_comment

begin_macro
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
end_macro

begin_macro
name|apr_crypto_passphrase
argument_list|(
argument|apr_crypto_key_t **key
argument_list|,
argument|apr_size_t *ivSize
argument_list|,
argument|const char *pass
argument_list|,
argument|apr_size_t passLen
argument_list|,
argument|const unsigned char * salt
argument_list|,
argument|apr_size_t saltLen
argument_list|,
argument|const apr_crypto_block_key_type_e type
argument_list|,
argument|const apr_crypto_block_key_mode_e mode
argument_list|,
argument|const int doPad
argument_list|,
argument|const int iterations
argument_list|,
argument|const apr_crypto_t *f
argument_list|,
argument|apr_pool_t *p
argument_list|)
end_macro

begin_block
block|{
return|return
name|f
operator|->
name|provider
operator|->
name|passphrase
argument_list|(
name|key
argument_list|,
name|ivSize
argument_list|,
name|pass
argument_list|,
name|passLen
argument_list|,
name|salt
argument_list|,
name|saltLen
argument_list|,
name|type
argument_list|,
name|mode
argument_list|,
name|doPad
argument_list|,
name|iterations
argument_list|,
name|f
argument_list|,
name|p
argument_list|)
return|;
block|}
end_block

begin_comment
comment|/**  * @brief Initialise a context for encrypting arbitrary data using the given key.  * @note If *ctx is NULL, a apr_crypto_block_t will be created from a pool. If  *       *ctx is not NULL, *ctx must point at a previously created structure.  * @param ctx The block context returned, see note.  * @param iv Optional initialisation vector. If the buffer pointed to is NULL,  *           an IV will be created at random, in space allocated from the pool.  *           If the buffer pointed to is not NULL, the IV in the buffer will be  *           used.  * @param key The key structure to use.  * @param blockSize The block size of the cipher.  * @param p The pool to use.  * @return Returns APR_ENOIV if an initialisation vector is required but not specified.  *         Returns APR_EINIT if the backend failed to initialise the context. Returns  *         APR_ENOTIMPL if not implemented.  */
end_comment

begin_macro
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
end_macro

begin_macro
name|apr_crypto_block_encrypt_init
argument_list|(
argument|apr_crypto_block_t **ctx
argument_list|,
argument|const unsigned char **iv
argument_list|,
argument|const apr_crypto_key_t *key
argument_list|,
argument|apr_size_t *blockSize
argument_list|,
argument|apr_pool_t *p
argument_list|)
end_macro

begin_block
block|{
return|return
name|key
operator|->
name|provider
operator|->
name|block_encrypt_init
argument_list|(
name|ctx
argument_list|,
name|iv
argument_list|,
name|key
argument_list|,
name|blockSize
argument_list|,
name|p
argument_list|)
return|;
block|}
end_block

begin_comment
comment|/**  * @brief Encrypt data provided by in, write it to out.  * @note The number of bytes written will be written to outlen. If  *       out is NULL, outlen will contain the maximum size of the  *       buffer needed to hold the data, including any data  *       generated by apr_crypto_block_encrypt_finish below. If *out points  *       to NULL, a buffer sufficiently large will be created from  *       the pool provided. If *out points to a not-NULL value, this  *       value will be used as a buffer instead.  * @param out Address of a buffer to which data will be written,  *        see note.  * @param outlen Length of the output will be written here.  * @param in Address of the buffer to read.  * @param inlen Length of the buffer to read.  * @param ctx The block context to use.  * @return APR_ECRYPT if an error occurred. Returns APR_ENOTIMPL if  *         not implemented.  */
end_comment

begin_macro
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
end_macro

begin_macro
name|apr_crypto_block_encrypt
argument_list|(
argument|unsigned char **out
argument_list|,
argument|apr_size_t *outlen
argument_list|,
argument|const unsigned char *in
argument_list|,
argument|apr_size_t inlen
argument_list|,
argument|apr_crypto_block_t *ctx
argument_list|)
end_macro

begin_block
block|{
return|return
name|ctx
operator|->
name|provider
operator|->
name|block_encrypt
argument_list|(
name|out
argument_list|,
name|outlen
argument_list|,
name|in
argument_list|,
name|inlen
argument_list|,
name|ctx
argument_list|)
return|;
block|}
end_block

begin_comment
comment|/**  * @brief Encrypt final data block, write it to out.  * @note If necessary the final block will be written out after being  *       padded. Typically the final block will be written to the  *       same buffer used by apr_crypto_block_encrypt, offset by the  *       number of bytes returned as actually written by the  *       apr_crypto_block_encrypt() call. After this call, the context  *       is cleaned and can be reused by apr_crypto_block_encrypt_init().  * @param out Address of a buffer to which data will be written. This  *            buffer must already exist, and is usually the same  *            buffer used by apr_evp_crypt(). See note.  * @param outlen Length of the output will be written here.  * @param ctx The block context to use.  * @return APR_ECRYPT if an error occurred.  * @return APR_EPADDING if padding was enabled and the block was incorrectly  *         formatted.  * @return APR_ENOTIMPL if not implemented.  */
end_comment

begin_macro
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
end_macro

begin_macro
name|apr_crypto_block_encrypt_finish
argument_list|(
argument|unsigned char *out
argument_list|,
argument|apr_size_t *outlen
argument_list|,
argument|apr_crypto_block_t *ctx
argument_list|)
end_macro

begin_block
block|{
return|return
name|ctx
operator|->
name|provider
operator|->
name|block_encrypt_finish
argument_list|(
name|out
argument_list|,
name|outlen
argument_list|,
name|ctx
argument_list|)
return|;
block|}
end_block

begin_comment
comment|/**  * @brief Initialise a context for decrypting arbitrary data using the given key.  * @note If *ctx is NULL, a apr_crypto_block_t will be created from a pool. If  *       *ctx is not NULL, *ctx must point at a previously created structure.  * @param ctx The block context returned, see note.  * @param blockSize The block size of the cipher.  * @param iv Optional initialisation vector.  * @param key The key structure to use.  * @param p The pool to use.  * @return Returns APR_ENOIV if an initialisation vector is required but not specified.  *         Returns APR_EINIT if the backend failed to initialise the context. Returns  *         APR_ENOTIMPL if not implemented.  */
end_comment

begin_macro
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
end_macro

begin_macro
name|apr_crypto_block_decrypt_init
argument_list|(
argument|apr_crypto_block_t **ctx
argument_list|,
argument|apr_size_t *blockSize
argument_list|,
argument|const unsigned char *iv
argument_list|,
argument|const apr_crypto_key_t *key
argument_list|,
argument|apr_pool_t *p
argument_list|)
end_macro

begin_block
block|{
return|return
name|key
operator|->
name|provider
operator|->
name|block_decrypt_init
argument_list|(
name|ctx
argument_list|,
name|blockSize
argument_list|,
name|iv
argument_list|,
name|key
argument_list|,
name|p
argument_list|)
return|;
block|}
end_block

begin_comment
comment|/**  * @brief Decrypt data provided by in, write it to out.  * @note The number of bytes written will be written to outlen. If  *       out is NULL, outlen will contain the maximum size of the  *       buffer needed to hold the data, including any data  *       generated by apr_crypto_block_decrypt_finish below. If *out points  *       to NULL, a buffer sufficiently large will be created from  *       the pool provided. If *out points to a not-NULL value, this  *       value will be used as a buffer instead.  * @param out Address of a buffer to which data will be written,  *        see note.  * @param outlen Length of the output will be written here.  * @param in Address of the buffer to read.  * @param inlen Length of the buffer to read.  * @param ctx The block context to use.  * @return APR_ECRYPT if an error occurred. Returns APR_ENOTIMPL if  *         not implemented.  */
end_comment

begin_macro
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
end_macro

begin_macro
name|apr_crypto_block_decrypt
argument_list|(
argument|unsigned char **out
argument_list|,
argument|apr_size_t *outlen
argument_list|,
argument|const unsigned char *in
argument_list|,
argument|apr_size_t inlen
argument_list|,
argument|apr_crypto_block_t *ctx
argument_list|)
end_macro

begin_block
block|{
return|return
name|ctx
operator|->
name|provider
operator|->
name|block_decrypt
argument_list|(
name|out
argument_list|,
name|outlen
argument_list|,
name|in
argument_list|,
name|inlen
argument_list|,
name|ctx
argument_list|)
return|;
block|}
end_block

begin_comment
comment|/**  * @brief Decrypt final data block, write it to out.  * @note If necessary the final block will be written out after being  *       padded. Typically the final block will be written to the  *       same buffer used by apr_crypto_block_decrypt, offset by the  *       number of bytes returned as actually written by the  *       apr_crypto_block_decrypt() call. After this call, the context  *       is cleaned and can be reused by apr_crypto_block_decrypt_init().  * @param out Address of a buffer to which data will be written. This  *            buffer must already exist, and is usually the same  *            buffer used by apr_evp_crypt(). See note.  * @param outlen Length of the output will be written here.  * @param ctx The block context to use.  * @return APR_ECRYPT if an error occurred.  * @return APR_EPADDING if padding was enabled and the block was incorrectly  *         formatted.  * @return APR_ENOTIMPL if not implemented.  */
end_comment

begin_macro
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
end_macro

begin_macro
name|apr_crypto_block_decrypt_finish
argument_list|(
argument|unsigned char *out
argument_list|,
argument|apr_size_t *outlen
argument_list|,
argument|apr_crypto_block_t *ctx
argument_list|)
end_macro

begin_block
block|{
return|return
name|ctx
operator|->
name|provider
operator|->
name|block_decrypt_finish
argument_list|(
name|out
argument_list|,
name|outlen
argument_list|,
name|ctx
argument_list|)
return|;
block|}
end_block

begin_comment
comment|/**  * @brief Clean encryption / decryption context.  * @note After cleanup, a context is free to be reused if necessary.  * @param ctx The block context to use.  * @return Returns APR_ENOTIMPL if not supported.  */
end_comment

begin_macro
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
end_macro

begin_macro
name|apr_crypto_block_cleanup
argument_list|(
argument|apr_crypto_block_t *ctx
argument_list|)
end_macro

begin_block
block|{
return|return
name|ctx
operator|->
name|provider
operator|->
name|block_cleanup
argument_list|(
name|ctx
argument_list|)
return|;
block|}
end_block

begin_comment
comment|/**  * @brief Clean encryption / decryption context.  * @note After cleanup, a context is free to be reused if necessary.  * @param f The context to use.  * @return Returns APR_ENOTIMPL if not supported.  */
end_comment

begin_macro
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
end_macro

begin_macro
name|apr_crypto_cleanup
argument_list|(
argument|apr_crypto_t *f
argument_list|)
end_macro

begin_block
block|{
return|return
name|f
operator|->
name|provider
operator|->
name|cleanup
argument_list|(
name|f
argument_list|)
return|;
block|}
end_block

begin_comment
comment|/**  * @brief Shutdown the crypto library.  * @note After shutdown, it is expected that the init function can be called again.  * @param driver - driver to use  * @return Returns APR_ENOTIMPL if not supported.  */
end_comment

begin_macro
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
end_macro

begin_macro
name|apr_crypto_shutdown
argument_list|(
argument|const apr_crypto_driver_t *driver
argument_list|)
end_macro

begin_block
block|{
return|return
name|driver
operator|->
name|shutdown
argument_list|()
return|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* APU_HAVE_CRYPTO */
end_comment

end_unit

