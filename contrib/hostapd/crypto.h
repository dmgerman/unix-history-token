begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * WPA Supplicant / wrapper functions for crypto libraries  * Copyright (c) 2004-2005, Jouni Malinen<j@w1.fi>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * Alternatively, this software may be distributed under the terms of BSD  * license.  *  * See README and COPYING for more details.  *  * This file defines the cryptographic functions that need to be implemented  * for wpa_supplicant and hostapd. When TLS is not used, internal  * implementation of MD5, SHA1, and AES is used and no external libraries are  * required. When TLS is enabled (e.g., by enabling EAP-TLS or EAP-PEAP), the  * crypto library used by the TLS implementation is expected to be used for  * non-TLS needs, too, in order to save space by not implementing these  * functions twice.  *  * Wrapper code for using each crypto library is in its own file (crypto*.c)  * and one of these files is build and linked in to provide the functions  * defined here.  */
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
comment|/**  * md4_vector - MD4 hash for data vector  * @num_elem: Number of elements in the data vector  * @addr: Pointers to the data areas  * @len: Lengths of the data blocks  * @mac: Buffer for the hash  */
end_comment

begin_function_decl
name|void
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
comment|/**  * md5_vector - MD5 hash for data vector  * @num_elem: Number of elements in the data vector  * @addr: Pointers to the data areas  * @len: Lengths of the data blocks  * @mac: Buffer for the hash  */
end_comment

begin_function_decl
name|void
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
comment|/**  * sha1_vector - SHA-1 hash for data vector  * @num_elem: Number of elements in the data vector  * @addr: Pointers to the data areas  * @len: Lengths of the data blocks  * @mac: Buffer for the hash  */
end_comment

begin_function_decl
name|void
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
comment|/**  * sha256_vector - SHA256 hash for data vector  * @num_elem: Number of elements in the data vector  * @addr: Pointers to the data areas  * @len: Lengths of the data blocks  * @mac: Buffer for the hash  */
end_comment

begin_function_decl
name|void
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

begin_comment
comment|/**  * crypto_private_key_import - Import an RSA private key  * @key: Key buffer (DER encoded RSA private key)  * @len: Key buffer length in bytes  * Returns: Pointer to the private key or %NULL on failure  *  * This function is only used with internal TLSv1 implementation  * (CONFIG_TLS=internal). If that is not used, the crypto wrapper does not need  * to implement this.  */
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
comment|/**  * crypto_private_key_sign_pkcs1 - Sign with private key (PKCS #1)  * @key: Private key from crypto_private_key_import()  * @in: Plaintext buffer  * @inlen: Length of plaintext buffer in bytes  * @out: Output buffer for encrypted (signed) data  * @outlen: Length of output buffer in bytes; set to used length on success  * Returns: 0 on success, -1 on failure  *  * This function is only used with internal TLSv1 implementation  * (CONFIG_TLS=internal). If that is not used, the crypto wrapper does not need  * to implement this.  */
end_comment

begin_function_decl
name|int
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CRYPTO_H */
end_comment

end_unit

