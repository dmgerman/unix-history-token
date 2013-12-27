begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Licensed to the Apache Software Foundation (ASF) under one or more  * contributor license agreements.  See the NOTICE file distributed with  * this work for additional information regarding copyright ownership.  * The ASF licenses this file to You under the Apache License, Version 2.0  * (the "License"); you may not use this file except in compliance with  * the License.  You may obtain a copy of the License at  *  *     http://www.apache.org/licenses/LICENSE-2.0  *  * Unless required by applicable law or agreed to in writing, software  * distributed under the License is distributed on an "AS IS" BASIS,  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  * See the License for the specific language governing permissions and  * limitations under the License.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|APR_CRYPTO_H
end_ifndef

begin_define
define|#
directive|define
name|APR_CRYPTO_H
end_define

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
file|"apr_tables.h"
end_include

begin_include
include|#
directive|include
file|"apr_hash.h"
end_include

begin_include
include|#
directive|include
file|"apu_errno.h"
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
comment|/**  * @file apr_crypto.h  * @brief APR-UTIL Crypto library  */
comment|/**  * @defgroup APR_Util_Crypto Crypto routines  * @ingroup APR_Util  * @{  */
if|#
directive|if
name|APU_HAVE_CRYPTO
ifndef|#
directive|ifndef
name|APU_CRYPTO_RECOMMENDED_DRIVER
if|#
directive|if
name|APU_HAVE_OPENSSL
define|#
directive|define
name|APU_CRYPTO_RECOMMENDED_DRIVER
value|"openssl"
else|#
directive|else
if|#
directive|if
name|APU_HAVE_NSS
define|#
directive|define
name|APU_CRYPTO_RECOMMENDED_DRIVER
value|"nss"
else|#
directive|else
if|#
directive|if
name|APU_HAVE_MSCNG
define|#
directive|define
name|APU_CRYPTO_RECOMMENDED_DRIVER
value|"mscng"
else|#
directive|else
if|#
directive|if
name|APU_HAVE_MSCAPI
define|#
directive|define
name|APU_CRYPTO_RECOMMENDED_DRIVER
value|"mscapi"
else|#
directive|else
endif|#
directive|endif
endif|#
directive|endif
endif|#
directive|endif
endif|#
directive|endif
endif|#
directive|endif
comment|/**  * Symmetric Key types understood by the library.  *  * NOTE: It is expected that this list will grow over time.  *  * Interoperability Matrix:  *  * The matrix is based on the testcrypto.c unit test, which attempts to  * test whether a simple encrypt/decrypt will succeed, as well as testing  * whether an encrypted string by one library can be decrypted by the  * others.  *  * Some libraries will successfully encrypt and decrypt their own data,  * but won't decrypt data from another library. It is hoped that over  * time these anomalies will be found and fixed, but until then it is  * recommended that ciphers are chosen that interoperate across platform.  *  * An X below means the test passes, it does not necessarily mean that  * encryption performed is correct or secure. Applications should stick  * to ciphers that pass the interoperablity tests on the right hand side  * of the table.  *  * Aligned data is data whose length is a multiple of the block size for  * the chosen cipher. Padded data is data that is not aligned by block  * size and must be padded by the crypto library.  *  *                  OpenSSL      NSS      Interop  *                 Align Pad  Align Pad  Align Pad  * 3DES_192/CBC    X     X    X     X    X     X  * 3DES_192/ECB    X     X  * AES_256/CBC     X     X    X     X    X     X  * AES_256/ECB     X     X    X          X  * AES_192/CBC     X     X    X     X  * AES_192/ECB     X     X    X  * AES_128/CBC     X     X    X     X  * AES_128/ECB     X     X    X  *  * Conclusion: for padded data, use 3DES_192/CBC or AES_256/CBC. For  * aligned data, use 3DES_192/CBC, AES_256/CBC or AES_256/ECB.  */
typedef|typedef
enum|enum
block|{
name|APR_KEY_NONE
block|,
name|APR_KEY_3DES_192
block|,
comment|/** 192 bit (3-Key) 3DES */
name|APR_KEY_AES_128
block|,
comment|/** 128 bit AES */
name|APR_KEY_AES_192
block|,
comment|/** 192 bit AES */
name|APR_KEY_AES_256
comment|/** 256 bit AES */
block|}
name|apr_crypto_block_key_type_e
typedef|;
typedef|typedef
enum|enum
block|{
name|APR_MODE_NONE
block|,
comment|/** An error condition */
name|APR_MODE_ECB
block|,
comment|/** Electronic Code Book */
name|APR_MODE_CBC
comment|/** Cipher Block Chaining */
block|}
name|apr_crypto_block_key_mode_e
typedef|;
comment|/* These are opaque structs.  Instantiation is up to each backend */
typedef|typedef
name|struct
name|apr_crypto_driver_t
name|apr_crypto_driver_t
typedef|;
typedef|typedef
name|struct
name|apr_crypto_t
name|apr_crypto_t
typedef|;
typedef|typedef
name|struct
name|apr_crypto_config_t
name|apr_crypto_config_t
typedef|;
typedef|typedef
name|struct
name|apr_crypto_key_t
name|apr_crypto_key_t
typedef|;
typedef|typedef
name|struct
name|apr_crypto_block_t
name|apr_crypto_block_t
typedef|;
comment|/**  * @brief Perform once-only initialisation. Call once only.  *  * @param pool - pool to register any shutdown cleanups, etc  * @return APR_NOTIMPL in case of no crypto support.  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_crypto_init
argument_list|(
name|apr_pool_t
operator|*
name|pool
argument_list|)
expr_stmt|;
comment|/**  * @brief Register a cleanup to zero out the buffer provided  * when the pool is cleaned up.  *  * @param pool - pool to register the cleanup  * @param buffer - buffer to zero out  * @param size - size of the buffer to zero out  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_crypto_clear
argument_list|(
argument|apr_pool_t *pool
argument_list|,
argument|void *buffer
argument_list|,
argument|apr_size_t size
argument_list|)
empty_stmt|;
comment|/**  * @brief Get the driver struct for a name  *  * @param driver - pointer to driver struct.  * @param name - driver name  * @param params - array of initialisation parameters  * @param result - result and error message on failure  * @param pool - (process) pool to register cleanup  * @return APR_SUCCESS for success  * @return APR_ENOTIMPL for no driver (when DSO not enabled)  * @return APR_EDSOOPEN if DSO driver file can't be opened  * @return APR_ESYMNOTFOUND if the driver file doesn't contain a driver  * @remarks NSS: the params can have "dir", "key3", "cert7" and "secmod"  *  keys, each followed by an equal sign and a value. Such key/value pairs can  *  be delimited by space or tab. If the value contains a space, surround the  *  whole key value pair in quotes: "dir=My Directory".  * @remarks OpenSSL: currently no params are supported.  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_crypto_get_driver
argument_list|(
specifier|const
name|apr_crypto_driver_t
operator|*
operator|*
name|driver
argument_list|,
specifier|const
name|char
operator|*
name|name
argument_list|,
specifier|const
name|char
operator|*
name|params
argument_list|,
specifier|const
name|apu_err_t
operator|*
operator|*
name|result
argument_list|,
name|apr_pool_t
operator|*
name|pool
argument_list|)
expr_stmt|;
comment|/**  * @brief Return the name of the driver.  *  * @param driver - The driver in use.  * @return The name of the driver.  */
name|APU_DECLARE
argument_list|(
argument|const char *
argument_list|)
name|apr_crypto_driver_name
argument_list|(
specifier|const
name|apr_crypto_driver_t
operator|*
name|driver
argument_list|)
expr_stmt|;
comment|/**  * @brief Get the result of the last operation on a context. If the result  *        is NULL, the operation was successful.  * @param result - the result structure  * @param f - context pointer  * @return APR_SUCCESS for success  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_crypto_error
argument_list|(
specifier|const
name|apu_err_t
operator|*
operator|*
name|result
argument_list|,
specifier|const
name|apr_crypto_t
operator|*
name|f
argument_list|)
expr_stmt|;
comment|/**  * @brief Create a context for supporting encryption. Keys, certificates,  *        algorithms and other parameters will be set per context. More than  *        one context can be created at one time. A cleanup will be automatically  *        registered with the given pool to guarantee a graceful shutdown.  * @param f - context pointer will be written here  * @param driver - driver to use  * @param params - array of key parameters  * @param pool - process pool  * @return APR_ENOENGINE when the engine specified does not exist. APR_EINITENGINE  * if the engine cannot be initialised.  * @remarks NSS: currently no params are supported.  * @remarks OpenSSL: the params can have "engine" as a key, followed by an equal  *  sign and a value.  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_crypto_make
argument_list|(
name|apr_crypto_t
operator|*
operator|*
name|f
argument_list|,
specifier|const
name|apr_crypto_driver_t
operator|*
name|driver
argument_list|,
specifier|const
name|char
operator|*
name|params
argument_list|,
name|apr_pool_t
operator|*
name|pool
argument_list|)
expr_stmt|;
comment|/**  * @brief Get a hash table of key types, keyed by the name of the type against  * an integer pointer constant.  *  * @param types - hashtable of key types keyed to constants.  * @param f - encryption context  * @return APR_SUCCESS for success  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_crypto_get_block_key_types
argument_list|(
name|apr_hash_t
operator|*
operator|*
name|types
argument_list|,
specifier|const
name|apr_crypto_t
operator|*
name|f
argument_list|)
expr_stmt|;
comment|/**  * @brief Get a hash table of key modes, keyed by the name of the mode against  * an integer pointer constant.  *  * @param modes - hashtable of key modes keyed to constants.  * @param f - encryption context  * @return APR_SUCCESS for success  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_crypto_get_block_key_modes
argument_list|(
name|apr_hash_t
operator|*
operator|*
name|modes
argument_list|,
specifier|const
name|apr_crypto_t
operator|*
name|f
argument_list|)
expr_stmt|;
comment|/**  * @brief Create a key from the given passphrase. By default, the PBKDF2  *        algorithm is used to generate the key from the passphrase. It is expected  *        that the same pass phrase will generate the same key, regardless of the  *        backend crypto platform used. The key is cleaned up when the context  *        is cleaned, and may be reused with multiple encryption or decryption  *        operations.  * @note If *key is NULL, a apr_crypto_key_t will be created from a pool. If  *       *key is not NULL, *key must point at a previously created structure.  * @param key The key returned, see note.  * @param ivSize The size of the initialisation vector will be returned, based  *               on whether an IV is relevant for this type of crypto.  * @param pass The passphrase to use.  * @param passLen The passphrase length in bytes  * @param salt The salt to use.  * @param saltLen The salt length in bytes  * @param type 3DES_192, AES_128, AES_192, AES_256.  * @param mode Electronic Code Book / Cipher Block Chaining.  * @param doPad Pad if necessary.  * @param iterations Number of iterations to use in algorithm  * @param f The context to use.  * @param p The pool to use.  * @return Returns APR_ENOKEY if the pass phrase is missing or empty, or if a backend  *         error occurred while generating the key. APR_ENOCIPHER if the type or mode  *         is not supported by the particular backend. APR_EKEYTYPE if the key type is  *         not known. APR_EPADDING if padding was requested but is not supported.  *         APR_ENOTIMPL if not implemented.  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
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
empty_stmt|;
comment|/**  * @brief Initialise a context for encrypting arbitrary data using the given key.  * @note If *ctx is NULL, a apr_crypto_block_t will be created from a pool. If  *       *ctx is not NULL, *ctx must point at a previously created structure.  * @param ctx The block context returned, see note.  * @param iv Optional initialisation vector. If the buffer pointed to is NULL,  *           an IV will be created at random, in space allocated from the pool.  *           If the buffer pointed to is not NULL, the IV in the buffer will be  *           used.  * @param key The key structure to use.  * @param blockSize The block size of the cipher.  * @param p The pool to use.  * @return Returns APR_ENOIV if an initialisation vector is required but not specified.  *         Returns APR_EINIT if the backend failed to initialise the context. Returns  *         APR_ENOTIMPL if not implemented.  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
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
empty_stmt|;
comment|/**  * @brief Encrypt data provided by in, write it to out.  * @note The number of bytes written will be written to outlen. If  *       out is NULL, outlen will contain the maximum size of the  *       buffer needed to hold the data, including any data  *       generated by apr_crypto_block_encrypt_finish below. If *out points  *       to NULL, a buffer sufficiently large will be created from  *       the pool provided. If *out points to a not-NULL value, this  *       value will be used as a buffer instead.  * @param out Address of a buffer to which data will be written,  *        see note.  * @param outlen Length of the output will be written here.  * @param in Address of the buffer to read.  * @param inlen Length of the buffer to read.  * @param ctx The block context to use.  * @return APR_ECRYPT if an error occurred. Returns APR_ENOTIMPL if  *         not implemented.  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
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
empty_stmt|;
comment|/**  * @brief Encrypt final data block, write it to out.  * @note If necessary the final block will be written out after being  *       padded. Typically the final block will be written to the  *       same buffer used by apr_crypto_block_encrypt, offset by the  *       number of bytes returned as actually written by the  *       apr_crypto_block_encrypt() call. After this call, the context  *       is cleaned and can be reused by apr_crypto_block_encrypt_init().  * @param out Address of a buffer to which data will be written. This  *            buffer must already exist, and is usually the same  *            buffer used by apr_evp_crypt(). See note.  * @param outlen Length of the output will be written here.  * @param ctx The block context to use.  * @return APR_ECRYPT if an error occurred.  * @return APR_EPADDING if padding was enabled and the block was incorrectly  *         formatted.  * @return APR_ENOTIMPL if not implemented.  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_crypto_block_encrypt_finish
argument_list|(
argument|unsigned char *out
argument_list|,
argument|apr_size_t *outlen
argument_list|,
argument|apr_crypto_block_t *ctx
argument_list|)
empty_stmt|;
comment|/**  * @brief Initialise a context for decrypting arbitrary data using the given key.  * @note If *ctx is NULL, a apr_crypto_block_t will be created from a pool. If  *       *ctx is not NULL, *ctx must point at a previously created structure.  * @param ctx The block context returned, see note.  * @param blockSize The block size of the cipher.  * @param iv Optional initialisation vector.  * @param key The key structure to use.  * @param p The pool to use.  * @return Returns APR_ENOIV if an initialisation vector is required but not specified.  *         Returns APR_EINIT if the backend failed to initialise the context. Returns  *         APR_ENOTIMPL if not implemented.  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
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
empty_stmt|;
comment|/**  * @brief Decrypt data provided by in, write it to out.  * @note The number of bytes written will be written to outlen. If  *       out is NULL, outlen will contain the maximum size of the  *       buffer needed to hold the data, including any data  *       generated by apr_crypto_block_decrypt_finish below. If *out points  *       to NULL, a buffer sufficiently large will be created from  *       the pool provided. If *out points to a not-NULL value, this  *       value will be used as a buffer instead.  * @param out Address of a buffer to which data will be written,  *        see note.  * @param outlen Length of the output will be written here.  * @param in Address of the buffer to read.  * @param inlen Length of the buffer to read.  * @param ctx The block context to use.  * @return APR_ECRYPT if an error occurred. Returns APR_ENOTIMPL if  *         not implemented.  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
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
empty_stmt|;
comment|/**  * @brief Decrypt final data block, write it to out.  * @note If necessary the final block will be written out after being  *       padded. Typically the final block will be written to the  *       same buffer used by apr_crypto_block_decrypt, offset by the  *       number of bytes returned as actually written by the  *       apr_crypto_block_decrypt() call. After this call, the context  *       is cleaned and can be reused by apr_crypto_block_decrypt_init().  * @param out Address of a buffer to which data will be written. This  *            buffer must already exist, and is usually the same  *            buffer used by apr_evp_crypt(). See note.  * @param outlen Length of the output will be written here.  * @param ctx The block context to use.  * @return APR_ECRYPT if an error occurred.  * @return APR_EPADDING if padding was enabled and the block was incorrectly  *         formatted.  * @return APR_ENOTIMPL if not implemented.  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_crypto_block_decrypt_finish
argument_list|(
argument|unsigned char *out
argument_list|,
argument|apr_size_t *outlen
argument_list|,
argument|apr_crypto_block_t *ctx
argument_list|)
empty_stmt|;
comment|/**  * @brief Clean encryption / decryption context.  * @note After cleanup, a context is free to be reused if necessary.  * @param ctx The block context to use.  * @return Returns APR_ENOTIMPL if not supported.  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_crypto_block_cleanup
argument_list|(
name|apr_crypto_block_t
operator|*
name|ctx
argument_list|)
expr_stmt|;
comment|/**  * @brief Clean encryption / decryption context.  * @note After cleanup, a context is free to be reused if necessary.  * @param f The context to use.  * @return Returns APR_ENOTIMPL if not supported.  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_crypto_cleanup
argument_list|(
name|apr_crypto_t
operator|*
name|f
argument_list|)
expr_stmt|;
comment|/**  * @brief Shutdown the crypto library.  * @note After shutdown, it is expected that the init function can be called again.  * @param driver - driver to use  * @return Returns APR_ENOTIMPL if not supported.  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_crypto_shutdown
argument_list|(
specifier|const
name|apr_crypto_driver_t
operator|*
name|driver
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* APU_HAVE_CRYPTO */
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

end_unit

