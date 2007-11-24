begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * WPA Supplicant / wrapper functions for crypto libraries  * Copyright (c) 2004-2005, Jouni Malinen<jkmaline@cc.hut.fi>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * Alternatively, this software may be distributed under the terms of BSD  * license.  *  * See README and COPYING for more details.  *  * This file defines the cryptographic functions that need to be implemented  * for wpa_supplicant and hostapd. When TLS is not used, internal  * implementation of MD5, SHA1, and AES is used and no external libraries are  * required. When TLS is enabled (e.g., by enabling EAP-TLS or EAP-PEAP), the  * crypto library used by the TLS implementation is expected to be used for  * non-TLS needs, too, in order to save space by not implementing these  * functions twice.  *  * Wrapper code for using each crypto library is in its own file (crypto*.c)  * and one of these files is build and linked in to provide the functions  * defined here.  */
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
comment|/**  * sha1_transform - Perform one SHA-1 transform step  * @state: SHA-1 state  * @data: Input data for the SHA-1 transform  *  * This function is used to implement random number generation specified in  * NIST FIPS Publication 186-2 for EAP-SIM. This PRF uses a function that is  * similar to SHA-1, but has different message padding and as such, access to  * just part of the SHA-1 is needed.  */
end_comment

begin_function_decl
name|void
name|sha1_transform
parameter_list|(
name|u8
modifier|*
name|state
parameter_list|,
specifier|const
name|u8
name|data
index|[
literal|64
index|]
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CRYPTO_H */
end_comment

end_unit

