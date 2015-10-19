begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Wrapper functions for crypto libraries  * Copyright (c) 2004-2013, Jouni Malinen<j@w1.fi>  *  * This software may be distributed under the terms of the BSD license.  * See README for more details.  *  * This file defines the cryptographic functions that need to be implemented  * for wpa_supplicant and hostapd. When TLS is not used, internal  * implementation of MD5, SHA1, and AES is used and no external libraries are  * required. When TLS is enabled (e.g., by enabling EAP-TLS or EAP-PEAP), the  * crypto library used by the TLS implementation is expected to be used for  * non-TLS needs, too, in order to save space by not implementing these  * functions twice.  *  * Wrapper code for using each crypto library is in its own file (crypto*.c)  * and one of these files is build and linked in to provide the functions  * defined here.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CRYPTO_H
end_ifndef

begin_define
define|#
directive|define
name|CRYPTO_H
end_define

begin_comment
comment|/**  * md4_vector - MD4 hash for data vector  * @num_elem: Number of elements in the data vector  * @addr: Pointers to the data areas  * @len: Lengths of the data blocks  * @mac: Buffer for the hash  * Returns: 0 on success, -1 on failure  */
end_comment

begin_function_decl
name|int
name|md4_vector
parameter_list|(
name|size_t
name|num_elem
parameter_list|,
specifier|const
name|u8
modifier|*
name|addr
index|[]
parameter_list|,
specifier|const
name|size_t
modifier|*
name|len
parameter_list|,
name|u8
modifier|*
name|mac
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * md5_vector - MD5 hash for data vector  * @num_elem: Number of elements in the data vector  * @addr: Pointers to the data areas  * @len: Lengths of the data blocks  * @mac: Buffer for the hash  * Returns: 0 on success, -1 on failure  */
end_comment

begin_function_decl
name|int
name|md5_vector
parameter_list|(
name|size_t
name|num_elem
parameter_list|,
specifier|const
name|u8
modifier|*
name|addr
index|[]
parameter_list|,
specifier|const
name|size_t
modifier|*
name|len
parameter_list|,
name|u8
modifier|*
name|mac
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * sha1_vector - SHA-1 hash for data vector  * @num_elem: Number of elements in the data vector  * @addr: Pointers to the data areas  * @len: Lengths of the data blocks  * @mac: Buffer for the hash  * Returns: 0 on success, -1 on failure  */
end_comment

begin_function_decl
name|int
name|sha1_vector
parameter_list|(
name|size_t
name|num_elem
parameter_list|,
specifier|const
name|u8
modifier|*
name|addr
index|[]
parameter_list|,
specifier|const
name|size_t
modifier|*
name|len
parameter_list|,
name|u8
modifier|*
name|mac
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * fips186_2-prf - NIST FIPS Publication 186-2 change notice 1 PRF  * @seed: Seed/key for the PRF  * @seed_len: Seed length in bytes  * @x: Buffer for PRF output  * @xlen: Output length in bytes  * Returns: 0 on success, -1 on failure  *  * This function implements random number generation specified in NIST FIPS  * Publication 186-2 for EAP-SIM. This PRF uses a function that is similar to  * SHA-1, but has different message padding.  */
end_comment

begin_function_decl
name|int
name|__must_check
name|fips186_2_prf
parameter_list|(
specifier|const
name|u8
modifier|*
name|seed
parameter_list|,
name|size_t
name|seed_len
parameter_list|,
name|u8
modifier|*
name|x
parameter_list|,
name|size_t
name|xlen
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * sha256_vector - SHA256 hash for data vector  * @num_elem: Number of elements in the data vector  * @addr: Pointers to the data areas  * @len: Lengths of the data blocks  * @mac: Buffer for the hash  * Returns: 0 on success, -1 on failure  */
end_comment

begin_function_decl
name|int
name|sha256_vector
parameter_list|(
name|size_t
name|num_elem
parameter_list|,
specifier|const
name|u8
modifier|*
name|addr
index|[]
parameter_list|,
specifier|const
name|size_t
modifier|*
name|len
parameter_list|,
name|u8
modifier|*
name|mac
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * des_encrypt - Encrypt one block with DES  * @clear: 8 octets (in)  * @key: 7 octets (in) (no parity bits included)  * @cypher: 8 octets (out)  */
end_comment

begin_function_decl
name|void
name|des_encrypt
parameter_list|(
specifier|const
name|u8
modifier|*
name|clear
parameter_list|,
specifier|const
name|u8
modifier|*
name|key
parameter_list|,
name|u8
modifier|*
name|cypher
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * aes_encrypt_init - Initialize AES for encryption  * @key: Encryption key  * @len: Key length in bytes (usually 16, i.e., 128 bits)  * Returns: Pointer to context data or %NULL on failure  */
end_comment

begin_function_decl
name|void
modifier|*
name|aes_encrypt_init
parameter_list|(
specifier|const
name|u8
modifier|*
name|key
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * aes_encrypt - Encrypt one AES block  * @ctx: Context pointer from aes_encrypt_init()  * @plain: Plaintext data to be encrypted (16 bytes)  * @crypt: Buffer for the encrypted data (16 bytes)  */
end_comment

begin_function_decl
name|void
name|aes_encrypt
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|,
specifier|const
name|u8
modifier|*
name|plain
parameter_list|,
name|u8
modifier|*
name|crypt
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * aes_encrypt_deinit - Deinitialize AES encryption  * @ctx: Context pointer from aes_encrypt_init()  */
end_comment

begin_function_decl
name|void
name|aes_encrypt_deinit
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * aes_decrypt_init - Initialize AES for decryption  * @key: Decryption key  * @len: Key length in bytes (usually 16, i.e., 128 bits)  * Returns: Pointer to context data or %NULL on failure  */
end_comment

begin_function_decl
name|void
modifier|*
name|aes_decrypt_init
parameter_list|(
specifier|const
name|u8
modifier|*
name|key
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * aes_decrypt - Decrypt one AES block  * @ctx: Context pointer from aes_encrypt_init()  * @crypt: Encrypted data (16 bytes)  * @plain: Buffer for the decrypted data (16 bytes)  */
end_comment

begin_function_decl
name|void
name|aes_decrypt
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|,
specifier|const
name|u8
modifier|*
name|crypt
parameter_list|,
name|u8
modifier|*
name|plain
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * aes_decrypt_deinit - Deinitialize AES decryption  * @ctx: Context pointer from aes_encrypt_init()  */
end_comment

begin_function_decl
name|void
name|aes_decrypt_deinit
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|)
function_decl|;
end_function_decl

begin_enum
enum|enum
name|crypto_hash_alg
block|{
name|CRYPTO_HASH_ALG_MD5
block|,
name|CRYPTO_HASH_ALG_SHA1
block|,
name|CRYPTO_HASH_ALG_HMAC_MD5
block|,
name|CRYPTO_HASH_ALG_HMAC_SHA1
block|,
name|CRYPTO_HASH_ALG_SHA256
block|,
name|CRYPTO_HASH_ALG_HMAC_SHA256
block|}
enum|;
end_enum

begin_struct_decl
struct_decl|struct
name|crypto_hash
struct_decl|;
end_struct_decl

begin_comment
comment|/**  * crypto_hash_init - Initialize hash/HMAC function  * @alg: Hash algorithm  * @key: Key for keyed hash (e.g., HMAC) or %NULL if not needed  * @key_len: Length of the key in bytes  * Returns: Pointer to hash context to use with other hash functions or %NULL  * on failure  *  * This function is only used with internal TLSv1 implementation  * (CONFIG_TLS=internal). If that is not used, the crypto wrapper does not need  * to implement this.  */
end_comment

begin_function_decl
name|struct
name|crypto_hash
modifier|*
name|crypto_hash_init
parameter_list|(
name|enum
name|crypto_hash_alg
name|alg
parameter_list|,
specifier|const
name|u8
modifier|*
name|key
parameter_list|,
name|size_t
name|key_len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * crypto_hash_update - Add data to hash calculation  * @ctx: Context pointer from crypto_hash_init()  * @data: Data buffer to add  * @len: Length of the buffer  *  * This function is only used with internal TLSv1 implementation  * (CONFIG_TLS=internal). If that is not used, the crypto wrapper does not need  * to implement this.  */
end_comment

begin_function_decl
name|void
name|crypto_hash_update
parameter_list|(
name|struct
name|crypto_hash
modifier|*
name|ctx
parameter_list|,
specifier|const
name|u8
modifier|*
name|data
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * crypto_hash_finish - Complete hash calculation  * @ctx: Context pointer from crypto_hash_init()  * @hash: Buffer for hash value or %NULL if caller is just freeing the hash  * context  * @len: Pointer to length of the buffer or %NULL if caller is just freeing the  * hash context; on return, this is set to the actual length of the hash value  * Returns: 0 on success, -1 if buffer is too small (len set to needed length),  * or -2 on other failures (including failed crypto_hash_update() operations)  *  * This function calculates the hash value and frees the context buffer that  * was used for hash calculation.  *  * This function is only used with internal TLSv1 implementation  * (CONFIG_TLS=internal). If that is not used, the crypto wrapper does not need  * to implement this.  */
end_comment

begin_function_decl
name|int
name|crypto_hash_finish
parameter_list|(
name|struct
name|crypto_hash
modifier|*
name|ctx
parameter_list|,
name|u8
modifier|*
name|hash
parameter_list|,
name|size_t
modifier|*
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_enum
enum|enum
name|crypto_cipher_alg
block|{
name|CRYPTO_CIPHER_NULL
init|=
literal|0
block|,
name|CRYPTO_CIPHER_ALG_AES
block|,
name|CRYPTO_CIPHER_ALG_3DES
block|,
name|CRYPTO_CIPHER_ALG_DES
block|,
name|CRYPTO_CIPHER_ALG_RC2
block|,
name|CRYPTO_CIPHER_ALG_RC4
block|}
enum|;
end_enum

begin_struct_decl
struct_decl|struct
name|crypto_cipher
struct_decl|;
end_struct_decl

begin_comment
comment|/**  * crypto_cipher_init - Initialize block/stream cipher function  * @alg: Cipher algorithm  * @iv: Initialization vector for block ciphers or %NULL for stream ciphers  * @key: Cipher key  * @key_len: Length of key in bytes  * Returns: Pointer to cipher context to use with other cipher functions or  * %NULL on failure  *  * This function is only used with internal TLSv1 implementation  * (CONFIG_TLS=internal). If that is not used, the crypto wrapper does not need  * to implement this.  */
end_comment

begin_function_decl
name|struct
name|crypto_cipher
modifier|*
name|crypto_cipher_init
parameter_list|(
name|enum
name|crypto_cipher_alg
name|alg
parameter_list|,
specifier|const
name|u8
modifier|*
name|iv
parameter_list|,
specifier|const
name|u8
modifier|*
name|key
parameter_list|,
name|size_t
name|key_len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * crypto_cipher_encrypt - Cipher encrypt  * @ctx: Context pointer from crypto_cipher_init()  * @plain: Plaintext to cipher  * @crypt: Resulting ciphertext  * @len: Length of the plaintext  * Returns: 0 on success, -1 on failure  *  * This function is only used with internal TLSv1 implementation  * (CONFIG_TLS=internal). If that is not used, the crypto wrapper does not need  * to implement this.  */
end_comment

begin_function_decl
name|int
name|__must_check
name|crypto_cipher_encrypt
parameter_list|(
name|struct
name|crypto_cipher
modifier|*
name|ctx
parameter_list|,
specifier|const
name|u8
modifier|*
name|plain
parameter_list|,
name|u8
modifier|*
name|crypt
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * crypto_cipher_decrypt - Cipher decrypt  * @ctx: Context pointer from crypto_cipher_init()  * @crypt: Ciphertext to decrypt  * @plain: Resulting plaintext  * @len: Length of the cipher text  * Returns: 0 on success, -1 on failure  *  * This function is only used with internal TLSv1 implementation  * (CONFIG_TLS=internal). If that is not used, the crypto wrapper does not need  * to implement this.  */
end_comment

begin_function_decl
name|int
name|__must_check
name|crypto_cipher_decrypt
parameter_list|(
name|struct
name|crypto_cipher
modifier|*
name|ctx
parameter_list|,
specifier|const
name|u8
modifier|*
name|crypt
parameter_list|,
name|u8
modifier|*
name|plain
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * crypto_cipher_decrypt - Free cipher context  * @ctx: Context pointer from crypto_cipher_init()  *  * This function is only used with internal TLSv1 implementation  * (CONFIG_TLS=internal). If that is not used, the crypto wrapper does not need  * to implement this.  */
end_comment

begin_function_decl
name|void
name|crypto_cipher_deinit
parameter_list|(
name|struct
name|crypto_cipher
modifier|*
name|ctx
parameter_list|)
function_decl|;
end_function_decl

begin_struct_decl
struct_decl|struct
name|crypto_public_key
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|crypto_private_key
struct_decl|;
end_struct_decl

begin_comment
comment|/**  * crypto_public_key_import - Import an RSA public key  * @key: Key buffer (DER encoded RSA public key)  * @len: Key buffer length in bytes  * Returns: Pointer to the public key or %NULL on failure  *  * This function can just return %NULL if the crypto library supports X.509  * parsing. In that case, crypto_public_key_from_cert() is used to import the  * public key from a certificate.  *  * This function is only used with internal TLSv1 implementation  * (CONFIG_TLS=internal). If that is not used, the crypto wrapper does not need  * to implement this.  */
end_comment

begin_function_decl
name|struct
name|crypto_public_key
modifier|*
name|crypto_public_key_import
parameter_list|(
specifier|const
name|u8
modifier|*
name|key
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|crypto_public_key
modifier|*
name|crypto_public_key_import_parts
parameter_list|(
specifier|const
name|u8
modifier|*
name|n
parameter_list|,
name|size_t
name|n_len
parameter_list|,
specifier|const
name|u8
modifier|*
name|e
parameter_list|,
name|size_t
name|e_len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * crypto_private_key_import - Import an RSA private key  * @key: Key buffer (DER encoded RSA private key)  * @len: Key buffer length in bytes  * @passwd: Key encryption password or %NULL if key is not encrypted  * Returns: Pointer to the private key or %NULL on failure  *  * This function is only used with internal TLSv1 implementation  * (CONFIG_TLS=internal). If that is not used, the crypto wrapper does not need  * to implement this.  */
end_comment

begin_function_decl
name|struct
name|crypto_private_key
modifier|*
name|crypto_private_key_import
parameter_list|(
specifier|const
name|u8
modifier|*
name|key
parameter_list|,
name|size_t
name|len
parameter_list|,
specifier|const
name|char
modifier|*
name|passwd
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * crypto_public_key_from_cert - Import an RSA public key from a certificate  * @buf: DER encoded X.509 certificate  * @len: Certificate buffer length in bytes  * Returns: Pointer to public key or %NULL on failure  *  * This function can just return %NULL if the crypto library does not support  * X.509 parsing. In that case, internal code will be used to parse the  * certificate and public key is imported using crypto_public_key_import().  *  * This function is only used with internal TLSv1 implementation  * (CONFIG_TLS=internal). If that is not used, the crypto wrapper does not need  * to implement this.  */
end_comment

begin_function_decl
name|struct
name|crypto_public_key
modifier|*
name|crypto_public_key_from_cert
parameter_list|(
specifier|const
name|u8
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * crypto_public_key_encrypt_pkcs1_v15 - Public key encryption (PKCS #1 v1.5)  * @key: Public key  * @in: Plaintext buffer  * @inlen: Length of plaintext buffer in bytes  * @out: Output buffer for encrypted data  * @outlen: Length of output buffer in bytes; set to used length on success  * Returns: 0 on success, -1 on failure  *  * This function is only used with internal TLSv1 implementation  * (CONFIG_TLS=internal). If that is not used, the crypto wrapper does not need  * to implement this.  */
end_comment

begin_function_decl
name|int
name|__must_check
name|crypto_public_key_encrypt_pkcs1_v15
parameter_list|(
name|struct
name|crypto_public_key
modifier|*
name|key
parameter_list|,
specifier|const
name|u8
modifier|*
name|in
parameter_list|,
name|size_t
name|inlen
parameter_list|,
name|u8
modifier|*
name|out
parameter_list|,
name|size_t
modifier|*
name|outlen
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * crypto_private_key_decrypt_pkcs1_v15 - Private key decryption (PKCS #1 v1.5)  * @key: Private key  * @in: Encrypted buffer  * @inlen: Length of encrypted buffer in bytes  * @out: Output buffer for encrypted data  * @outlen: Length of output buffer in bytes; set to used length on success  * Returns: 0 on success, -1 on failure  *  * This function is only used with internal TLSv1 implementation  * (CONFIG_TLS=internal). If that is not used, the crypto wrapper does not need  * to implement this.  */
end_comment

begin_function_decl
name|int
name|__must_check
name|crypto_private_key_decrypt_pkcs1_v15
parameter_list|(
name|struct
name|crypto_private_key
modifier|*
name|key
parameter_list|,
specifier|const
name|u8
modifier|*
name|in
parameter_list|,
name|size_t
name|inlen
parameter_list|,
name|u8
modifier|*
name|out
parameter_list|,
name|size_t
modifier|*
name|outlen
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * crypto_private_key_sign_pkcs1 - Sign with private key (PKCS #1)  * @key: Private key from crypto_private_key_import()  * @in: Plaintext buffer  * @inlen: Length of plaintext buffer in bytes  * @out: Output buffer for encrypted (signed) data  * @outlen: Length of output buffer in bytes; set to used length on success  * Returns: 0 on success, -1 on failure  *  * This function is only used with internal TLSv1 implementation  * (CONFIG_TLS=internal). If that is not used, the crypto wrapper does not need  * to implement this.  */
end_comment

begin_function_decl
name|int
name|__must_check
name|crypto_private_key_sign_pkcs1
parameter_list|(
name|struct
name|crypto_private_key
modifier|*
name|key
parameter_list|,
specifier|const
name|u8
modifier|*
name|in
parameter_list|,
name|size_t
name|inlen
parameter_list|,
name|u8
modifier|*
name|out
parameter_list|,
name|size_t
modifier|*
name|outlen
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * crypto_public_key_free - Free public key  * @key: Public key  *  * This function is only used with internal TLSv1 implementation  * (CONFIG_TLS=internal). If that is not used, the crypto wrapper does not need  * to implement this.  */
end_comment

begin_function_decl
name|void
name|crypto_public_key_free
parameter_list|(
name|struct
name|crypto_public_key
modifier|*
name|key
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * crypto_private_key_free - Free private key  * @key: Private key from crypto_private_key_import()  *  * This function is only used with internal TLSv1 implementation  * (CONFIG_TLS=internal). If that is not used, the crypto wrapper does not need  * to implement this.  */
end_comment

begin_function_decl
name|void
name|crypto_private_key_free
parameter_list|(
name|struct
name|crypto_private_key
modifier|*
name|key
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * crypto_public_key_decrypt_pkcs1 - Decrypt PKCS #1 signature  * @key: Public key  * @crypt: Encrypted signature data (using the private key)  * @crypt_len: Encrypted signature data length  * @plain: Buffer for plaintext (at least crypt_len bytes)  * @plain_len: Plaintext length (max buffer size on input, real len on output);  * Returns: 0 on success, -1 on failure  */
end_comment

begin_function_decl
name|int
name|__must_check
name|crypto_public_key_decrypt_pkcs1
parameter_list|(
name|struct
name|crypto_public_key
modifier|*
name|key
parameter_list|,
specifier|const
name|u8
modifier|*
name|crypt
parameter_list|,
name|size_t
name|crypt_len
parameter_list|,
name|u8
modifier|*
name|plain
parameter_list|,
name|size_t
modifier|*
name|plain_len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * crypto_global_init - Initialize crypto wrapper  *  * This function is only used with internal TLSv1 implementation  * (CONFIG_TLS=internal). If that is not used, the crypto wrapper does not need  * to implement this.  */
end_comment

begin_function_decl
name|int
name|__must_check
name|crypto_global_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * crypto_global_deinit - Deinitialize crypto wrapper  *  * This function is only used with internal TLSv1 implementation  * (CONFIG_TLS=internal). If that is not used, the crypto wrapper does not need  * to implement this.  */
end_comment

begin_function_decl
name|void
name|crypto_global_deinit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * crypto_mod_exp - Modular exponentiation of large integers  * @base: Base integer (big endian byte array)  * @base_len: Length of base integer in bytes  * @power: Power integer (big endian byte array)  * @power_len: Length of power integer in bytes  * @modulus: Modulus integer (big endian byte array)  * @modulus_len: Length of modulus integer in bytes  * @result: Buffer for the result  * @result_len: Result length (max buffer size on input, real len on output)  * Returns: 0 on success, -1 on failure  *  * This function calculates result = base ^ power mod modulus. modules_len is  * used as the maximum size of modulus buffer. It is set to the used size on  * success.  *  * This function is only used with internal TLSv1 implementation  * (CONFIG_TLS=internal). If that is not used, the crypto wrapper does not need  * to implement this.  */
end_comment

begin_function_decl
name|int
name|__must_check
name|crypto_mod_exp
parameter_list|(
specifier|const
name|u8
modifier|*
name|base
parameter_list|,
name|size_t
name|base_len
parameter_list|,
specifier|const
name|u8
modifier|*
name|power
parameter_list|,
name|size_t
name|power_len
parameter_list|,
specifier|const
name|u8
modifier|*
name|modulus
parameter_list|,
name|size_t
name|modulus_len
parameter_list|,
name|u8
modifier|*
name|result
parameter_list|,
name|size_t
modifier|*
name|result_len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * rc4_skip - XOR RC4 stream to given data with skip-stream-start  * @key: RC4 key  * @keylen: RC4 key length  * @skip: number of bytes to skip from the beginning of the RC4 stream  * @data: data to be XOR'ed with RC4 stream  * @data_len: buf length  * Returns: 0 on success, -1 on failure  *  * Generate RC4 pseudo random stream for the given key, skip beginning of the  * stream, and XOR the end result with the data buffer to perform RC4  * encryption/decryption.  */
end_comment

begin_function_decl
name|int
name|rc4_skip
parameter_list|(
specifier|const
name|u8
modifier|*
name|key
parameter_list|,
name|size_t
name|keylen
parameter_list|,
name|size_t
name|skip
parameter_list|,
name|u8
modifier|*
name|data
parameter_list|,
name|size_t
name|data_len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * crypto_get_random - Generate cryptographically strong pseudy-random bytes  * @buf: Buffer for data  * @len: Number of bytes to generate  * Returns: 0 on success, -1 on failure  *  * If the PRNG does not have enough entropy to ensure unpredictable byte  * sequence, this functions must return -1.  */
end_comment

begin_function_decl
name|int
name|crypto_get_random
parameter_list|(
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * struct crypto_bignum - bignum  *  * Internal data structure for bignum implementation. The contents is specific  * to the used crypto library.  */
end_comment

begin_struct_decl
struct_decl|struct
name|crypto_bignum
struct_decl|;
end_struct_decl

begin_comment
comment|/**  * crypto_bignum_init - Allocate memory for bignum  * Returns: Pointer to allocated bignum or %NULL on failure  */
end_comment

begin_function_decl
name|struct
name|crypto_bignum
modifier|*
name|crypto_bignum_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * crypto_bignum_init_set - Allocate memory for bignum and set the value  * @buf: Buffer with unsigned binary value  * @len: Length of buf in octets  * Returns: Pointer to allocated bignum or %NULL on failure  */
end_comment

begin_function_decl
name|struct
name|crypto_bignum
modifier|*
name|crypto_bignum_init_set
parameter_list|(
specifier|const
name|u8
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * crypto_bignum_deinit - Free bignum  * @n: Bignum from crypto_bignum_init() or crypto_bignum_init_set()  * @clear: Whether to clear the value from memory  */
end_comment

begin_function_decl
name|void
name|crypto_bignum_deinit
parameter_list|(
name|struct
name|crypto_bignum
modifier|*
name|n
parameter_list|,
name|int
name|clear
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * crypto_bignum_to_bin - Set binary buffer to unsigned bignum  * @a: Bignum  * @buf: Buffer for the binary number  * @len: Length of @buf in octets  * @padlen: Length in octets to pad the result to or 0 to indicate no padding  * Returns: Number of octets written on success, -1 on failure  */
end_comment

begin_function_decl
name|int
name|crypto_bignum_to_bin
parameter_list|(
specifier|const
name|struct
name|crypto_bignum
modifier|*
name|a
parameter_list|,
name|u8
modifier|*
name|buf
parameter_list|,
name|size_t
name|buflen
parameter_list|,
name|size_t
name|padlen
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * crypto_bignum_add - c = a + b  * @a: Bignum  * @b: Bignum  * @c: Bignum; used to store the result of a + b  * Returns: 0 on success, -1 on failure  */
end_comment

begin_function_decl
name|int
name|crypto_bignum_add
parameter_list|(
specifier|const
name|struct
name|crypto_bignum
modifier|*
name|a
parameter_list|,
specifier|const
name|struct
name|crypto_bignum
modifier|*
name|b
parameter_list|,
name|struct
name|crypto_bignum
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * crypto_bignum_mod - c = a % b  * @a: Bignum  * @b: Bignum  * @c: Bignum; used to store the result of a % b  * Returns: 0 on success, -1 on failure  */
end_comment

begin_function_decl
name|int
name|crypto_bignum_mod
parameter_list|(
specifier|const
name|struct
name|crypto_bignum
modifier|*
name|a
parameter_list|,
specifier|const
name|struct
name|crypto_bignum
modifier|*
name|b
parameter_list|,
name|struct
name|crypto_bignum
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * crypto_bignum_exptmod - Modular exponentiation: d = a^b (mod c)  * @a: Bignum; base  * @b: Bignum; exponent  * @c: Bignum; modulus  * @d: Bignum; used to store the result of a^b (mod c)  * Returns: 0 on success, -1 on failure  */
end_comment

begin_function_decl
name|int
name|crypto_bignum_exptmod
parameter_list|(
specifier|const
name|struct
name|crypto_bignum
modifier|*
name|a
parameter_list|,
specifier|const
name|struct
name|crypto_bignum
modifier|*
name|b
parameter_list|,
specifier|const
name|struct
name|crypto_bignum
modifier|*
name|c
parameter_list|,
name|struct
name|crypto_bignum
modifier|*
name|d
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * crypto_bignum_inverse - Inverse a bignum so that a * c = 1 (mod b)  * @a: Bignum  * @b: Bignum  * @c: Bignum; used to store the result  * Returns: 0 on success, -1 on failure  */
end_comment

begin_function_decl
name|int
name|crypto_bignum_inverse
parameter_list|(
specifier|const
name|struct
name|crypto_bignum
modifier|*
name|a
parameter_list|,
specifier|const
name|struct
name|crypto_bignum
modifier|*
name|b
parameter_list|,
name|struct
name|crypto_bignum
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * crypto_bignum_sub - c = a - b  * @a: Bignum  * @b: Bignum  * @c: Bignum; used to store the result of a - b  * Returns: 0 on success, -1 on failure  */
end_comment

begin_function_decl
name|int
name|crypto_bignum_sub
parameter_list|(
specifier|const
name|struct
name|crypto_bignum
modifier|*
name|a
parameter_list|,
specifier|const
name|struct
name|crypto_bignum
modifier|*
name|b
parameter_list|,
name|struct
name|crypto_bignum
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * crypto_bignum_div - c = a / b  * @a: Bignum  * @b: Bignum  * @c: Bignum; used to store the result of a / b  * Returns: 0 on success, -1 on failure  */
end_comment

begin_function_decl
name|int
name|crypto_bignum_div
parameter_list|(
specifier|const
name|struct
name|crypto_bignum
modifier|*
name|a
parameter_list|,
specifier|const
name|struct
name|crypto_bignum
modifier|*
name|b
parameter_list|,
name|struct
name|crypto_bignum
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * crypto_bignum_mulmod - d = a * b (mod c)  * @a: Bignum  * @b: Bignum  * @c: Bignum  * @d: Bignum; used to store the result of (a * b) % c  * Returns: 0 on success, -1 on failure  */
end_comment

begin_function_decl
name|int
name|crypto_bignum_mulmod
parameter_list|(
specifier|const
name|struct
name|crypto_bignum
modifier|*
name|a
parameter_list|,
specifier|const
name|struct
name|crypto_bignum
modifier|*
name|b
parameter_list|,
specifier|const
name|struct
name|crypto_bignum
modifier|*
name|c
parameter_list|,
name|struct
name|crypto_bignum
modifier|*
name|d
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * crypto_bignum_cmp - Compare two bignums  * @a: Bignum  * @b: Bignum  * Returns: -1 if a< b, 0 if a == b, or 1 if a> b  */
end_comment

begin_function_decl
name|int
name|crypto_bignum_cmp
parameter_list|(
specifier|const
name|struct
name|crypto_bignum
modifier|*
name|a
parameter_list|,
specifier|const
name|struct
name|crypto_bignum
modifier|*
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * crypto_bignum_bits - Get size of a bignum in bits  * @a: Bignum  * Returns: Number of bits in the bignum  */
end_comment

begin_function_decl
name|int
name|crypto_bignum_bits
parameter_list|(
specifier|const
name|struct
name|crypto_bignum
modifier|*
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * crypto_bignum_is_zero - Is the given bignum zero  * @a: Bignum  * Returns: 1 if @a is zero or 0 if not  */
end_comment

begin_function_decl
name|int
name|crypto_bignum_is_zero
parameter_list|(
specifier|const
name|struct
name|crypto_bignum
modifier|*
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * crypto_bignum_is_one - Is the given bignum one  * @a: Bignum  * Returns: 1 if @a is one or 0 if not  */
end_comment

begin_function_decl
name|int
name|crypto_bignum_is_one
parameter_list|(
specifier|const
name|struct
name|crypto_bignum
modifier|*
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * crypto_bignum_legendre - Compute the Legendre symbol (a/p)  * @a: Bignum  * @p: Bignum  * Returns: Legendre symbol -1,0,1 on success; -2 on calculation failure  */
end_comment

begin_function_decl
name|int
name|crypto_bignum_legendre
parameter_list|(
specifier|const
name|struct
name|crypto_bignum
modifier|*
name|a
parameter_list|,
specifier|const
name|struct
name|crypto_bignum
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * struct crypto_ec - Elliptic curve context  *  * Internal data structure for EC implementation. The contents is specific  * to the used crypto library.  */
end_comment

begin_struct_decl
struct_decl|struct
name|crypto_ec
struct_decl|;
end_struct_decl

begin_comment
comment|/**  * crypto_ec_init - Initialize elliptic curve context  * @group: Identifying number for the ECC group (IANA "Group Description"  *	attribute registrty for RFC 2409)  * Returns: Pointer to EC context or %NULL on failure  */
end_comment

begin_function_decl
name|struct
name|crypto_ec
modifier|*
name|crypto_ec_init
parameter_list|(
name|int
name|group
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * crypto_ec_deinit - Deinitialize elliptic curve context  * @e: EC context from crypto_ec_init()  */
end_comment

begin_function_decl
name|void
name|crypto_ec_deinit
parameter_list|(
name|struct
name|crypto_ec
modifier|*
name|e
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * crypto_ec_prime_len - Get length of the prime in octets  * @e: EC context from crypto_ec_init()  * Returns: Length of the prime defining the group  */
end_comment

begin_function_decl
name|size_t
name|crypto_ec_prime_len
parameter_list|(
name|struct
name|crypto_ec
modifier|*
name|e
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * crypto_ec_prime_len_bits - Get length of the prime in bits  * @e: EC context from crypto_ec_init()  * Returns: Length of the prime defining the group in bits  */
end_comment

begin_function_decl
name|size_t
name|crypto_ec_prime_len_bits
parameter_list|(
name|struct
name|crypto_ec
modifier|*
name|e
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * crypto_ec_get_prime - Get prime defining an EC group  * @e: EC context from crypto_ec_init()  * Returns: Prime (bignum) defining the group  */
end_comment

begin_function_decl
specifier|const
name|struct
name|crypto_bignum
modifier|*
name|crypto_ec_get_prime
parameter_list|(
name|struct
name|crypto_ec
modifier|*
name|e
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * crypto_ec_get_order - Get order of an EC group  * @e: EC context from crypto_ec_init()  * Returns: Order (bignum) of the group  */
end_comment

begin_function_decl
specifier|const
name|struct
name|crypto_bignum
modifier|*
name|crypto_ec_get_order
parameter_list|(
name|struct
name|crypto_ec
modifier|*
name|e
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * struct crypto_ec_point - Elliptic curve point  *  * Internal data structure for EC implementation to represent a point. The  * contents is specific to the used crypto library.  */
end_comment

begin_struct_decl
struct_decl|struct
name|crypto_ec_point
struct_decl|;
end_struct_decl

begin_comment
comment|/**  * crypto_ec_point_init - Initialize data for an EC point  * @e: EC context from crypto_ec_init()  * Returns: Pointer to EC point data or %NULL on failure  */
end_comment

begin_function_decl
name|struct
name|crypto_ec_point
modifier|*
name|crypto_ec_point_init
parameter_list|(
name|struct
name|crypto_ec
modifier|*
name|e
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * crypto_ec_point_deinit - Deinitialize EC point data  * @p: EC point data from crypto_ec_point_init()  * @clear: Whether to clear the EC point value from memory  */
end_comment

begin_function_decl
name|void
name|crypto_ec_point_deinit
parameter_list|(
name|struct
name|crypto_ec_point
modifier|*
name|p
parameter_list|,
name|int
name|clear
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * crypto_ec_point_to_bin - Write EC point value as binary data  * @e: EC context from crypto_ec_init()  * @p: EC point data from crypto_ec_point_init()  * @x: Buffer for writing the binary data for x coordinate or %NULL if not used  * @y: Buffer for writing the binary data for y coordinate or %NULL if not used  * Returns: 0 on success, -1 on failure  *  * This function can be used to write an EC point as binary data in a format  * that has the x and y coordinates in big endian byte order fields padded to  * the length of the prime defining the group.  */
end_comment

begin_function_decl
name|int
name|crypto_ec_point_to_bin
parameter_list|(
name|struct
name|crypto_ec
modifier|*
name|e
parameter_list|,
specifier|const
name|struct
name|crypto_ec_point
modifier|*
name|point
parameter_list|,
name|u8
modifier|*
name|x
parameter_list|,
name|u8
modifier|*
name|y
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * crypto_ec_point_from_bin - Create EC point from binary data  * @e: EC context from crypto_ec_init()  * @val: Binary data to read the EC point from  * Returns: Pointer to EC point data or %NULL on failure  *  * This function readers x and y coordinates of the EC point from the provided  * buffer assuming the values are in big endian byte order with fields padded to  * the length of the prime defining the group.  */
end_comment

begin_function_decl
name|struct
name|crypto_ec_point
modifier|*
name|crypto_ec_point_from_bin
parameter_list|(
name|struct
name|crypto_ec
modifier|*
name|e
parameter_list|,
specifier|const
name|u8
modifier|*
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * crypto_bignum_add - c = a + b  * @e: EC context from crypto_ec_init()  * @a: Bignum  * @b: Bignum  * @c: Bignum; used to store the result of a + b  * Returns: 0 on success, -1 on failure  */
end_comment

begin_function_decl
name|int
name|crypto_ec_point_add
parameter_list|(
name|struct
name|crypto_ec
modifier|*
name|e
parameter_list|,
specifier|const
name|struct
name|crypto_ec_point
modifier|*
name|a
parameter_list|,
specifier|const
name|struct
name|crypto_ec_point
modifier|*
name|b
parameter_list|,
name|struct
name|crypto_ec_point
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * crypto_bignum_mul - res = b * p  * @e: EC context from crypto_ec_init()  * @p: EC point  * @b: Bignum  * @res: EC point; used to store the result of b * p  * Returns: 0 on success, -1 on failure  */
end_comment

begin_function_decl
name|int
name|crypto_ec_point_mul
parameter_list|(
name|struct
name|crypto_ec
modifier|*
name|e
parameter_list|,
specifier|const
name|struct
name|crypto_ec_point
modifier|*
name|p
parameter_list|,
specifier|const
name|struct
name|crypto_bignum
modifier|*
name|b
parameter_list|,
name|struct
name|crypto_ec_point
modifier|*
name|res
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * crypto_ec_point_invert - Compute inverse of an EC point  * @e: EC context from crypto_ec_init()  * @p: EC point to invert (and result of the operation)  * Returns: 0 on success, -1 on failure  */
end_comment

begin_function_decl
name|int
name|crypto_ec_point_invert
parameter_list|(
name|struct
name|crypto_ec
modifier|*
name|e
parameter_list|,
name|struct
name|crypto_ec_point
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * crypto_ec_point_solve_y_coord - Solve y coordinate for an x coordinate  * @e: EC context from crypto_ec_init()  * @p: EC point to use for the returning the result  * @x: x coordinate  * @y_bit: y-bit (0 or 1) for selecting the y value to use  * Returns: 0 on success, -1 on failure  */
end_comment

begin_function_decl
name|int
name|crypto_ec_point_solve_y_coord
parameter_list|(
name|struct
name|crypto_ec
modifier|*
name|e
parameter_list|,
name|struct
name|crypto_ec_point
modifier|*
name|p
parameter_list|,
specifier|const
name|struct
name|crypto_bignum
modifier|*
name|x
parameter_list|,
name|int
name|y_bit
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * crypto_ec_point_compute_y_sqr - Compute y^2 = x^3 + ax + b  * @e: EC context from crypto_ec_init()  * @x: x coordinate  * Returns: y^2 on success, %NULL failure  */
end_comment

begin_function_decl
name|struct
name|crypto_bignum
modifier|*
name|crypto_ec_point_compute_y_sqr
parameter_list|(
name|struct
name|crypto_ec
modifier|*
name|e
parameter_list|,
specifier|const
name|struct
name|crypto_bignum
modifier|*
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * crypto_ec_point_is_at_infinity - Check whether EC point is neutral element  * @e: EC context from crypto_ec_init()  * @p: EC point  * Returns: 1 if the specified EC point is the neutral element of the group or  *	0 if not  */
end_comment

begin_function_decl
name|int
name|crypto_ec_point_is_at_infinity
parameter_list|(
name|struct
name|crypto_ec
modifier|*
name|e
parameter_list|,
specifier|const
name|struct
name|crypto_ec_point
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * crypto_ec_point_is_on_curve - Check whether EC point is on curve  * @e: EC context from crypto_ec_init()  * @p: EC point  * Returns: 1 if the specified EC point is on the curve or 0 if not  */
end_comment

begin_function_decl
name|int
name|crypto_ec_point_is_on_curve
parameter_list|(
name|struct
name|crypto_ec
modifier|*
name|e
parameter_list|,
specifier|const
name|struct
name|crypto_ec_point
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * crypto_ec_point_cmp - Compare two EC points  * @e: EC context from crypto_ec_init()  * @a: EC point  * @b: EC point  * Returns: 0 on equal, non-zero otherwise  */
end_comment

begin_function_decl
name|int
name|crypto_ec_point_cmp
parameter_list|(
specifier|const
name|struct
name|crypto_ec
modifier|*
name|e
parameter_list|,
specifier|const
name|struct
name|crypto_ec_point
modifier|*
name|a
parameter_list|,
specifier|const
name|struct
name|crypto_ec_point
modifier|*
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CRYPTO_H */
end_comment

end_unit

