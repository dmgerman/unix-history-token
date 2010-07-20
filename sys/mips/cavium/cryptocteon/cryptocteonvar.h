begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Octeon Crypto for OCF  *  * Written by David McCullough<david_mccullough@securecomputing.com>  * Copyright (C) 2009 David McCullough  *  * LICENSE TERMS  *  * The free distribution and use of this software in both source and binary  * form is allowed (with or without changes) provided that:  *  *   1. distributions of this source code include the above copyright  *      notice, this list of conditions and the following disclaimer;  *  *   2. distributions in binary form include the above copyright  *      notice, this list of conditions and the following disclaimer  *      in the documentation and/or other associated materials;  *  *   3. the copyright holder's name is not used to endorse products  *      built using this software without specific written permission.  *  * DISCLAIMER  *  * This software is provided 'as is' with no explicit or implied warranties  * in respect of its properties, including, but not limited to, correctness  * and/or fitness for purpose.  * ---------------------------------------------------------------------------  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MIPS_CAVIUM_CRYPTOCTEON_CRYPTOCTEONVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_MIPS_CAVIUM_CRYPTOCTEON_CRYPTOCTEONVAR_H_
end_define

begin_struct_decl
struct_decl|struct
name|octo_sess
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|int
name|octo_encrypt_t
parameter_list|(
name|struct
name|octo_sess
modifier|*
name|od
parameter_list|,
name|struct
name|iovec
modifier|*
name|iov
parameter_list|,
name|size_t
name|iovcnt
parameter_list|,
name|size_t
name|iovlen
parameter_list|,
name|int
name|auth_off
parameter_list|,
name|int
name|auth_len
parameter_list|,
name|int
name|crypt_off
parameter_list|,
name|int
name|crypt_len
parameter_list|,
name|int
name|icv_off
parameter_list|,
name|uint8_t
modifier|*
name|ivp
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|octo_decrypt_t
parameter_list|(
name|struct
name|octo_sess
modifier|*
name|od
parameter_list|,
name|struct
name|iovec
modifier|*
name|iov
parameter_list|,
name|size_t
name|iovcnt
parameter_list|,
name|size_t
name|iovlen
parameter_list|,
name|int
name|auth_off
parameter_list|,
name|int
name|auth_len
parameter_list|,
name|int
name|crypt_off
parameter_list|,
name|int
name|crypt_len
parameter_list|,
name|int
name|icv_off
parameter_list|,
name|uint8_t
modifier|*
name|ivp
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|octo_sess
block|{
name|int
name|octo_encalg
decl_stmt|;
define|#
directive|define
name|MAX_CIPHER_KEYLEN
value|64
name|char
name|octo_enckey
index|[
name|MAX_CIPHER_KEYLEN
index|]
decl_stmt|;
name|int
name|octo_encklen
decl_stmt|;
name|int
name|octo_macalg
decl_stmt|;
define|#
directive|define
name|MAX_HASH_KEYLEN
value|64
name|char
name|octo_mackey
index|[
name|MAX_HASH_KEYLEN
index|]
decl_stmt|;
name|int
name|octo_macklen
decl_stmt|;
name|int
name|octo_mackey_set
decl_stmt|;
name|int
name|octo_mlen
decl_stmt|;
name|int
name|octo_ivsize
decl_stmt|;
name|octo_encrypt_t
modifier|*
name|octo_encrypt
decl_stmt|;
name|octo_decrypt_t
modifier|*
name|octo_decrypt
decl_stmt|;
name|uint64_t
name|octo_hminner
index|[
literal|3
index|]
decl_stmt|;
name|uint64_t
name|octo_hmouter
index|[
literal|3
index|]
decl_stmt|;
name|struct
name|iovec
name|octo_iov
index|[
name|UIO_MAXIOV
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|dprintf
parameter_list|(
name|fmt
parameter_list|,
modifier|...
parameter_list|)
define|\
value|do {								\ 		if (cryptocteon_debug)					\ 			printf("%s: " fmt, __func__, ## __VA_ARGS__);	\ 	} while (0)
end_define

begin_decl_stmt
specifier|extern
name|int
name|cryptocteon_debug
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|octo_calc_hash
parameter_list|(
name|uint8_t
parameter_list|,
name|unsigned
name|char
modifier|*
parameter_list|,
name|uint64_t
modifier|*
parameter_list|,
name|uint64_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* XXX Actually just hashing functions, not encryption.  */
end_comment

begin_decl_stmt
name|octo_encrypt_t
name|octo_null_md5_encrypt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|octo_encrypt_t
name|octo_null_sha1_encrypt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|octo_encrypt_t
name|octo_des_cbc_encrypt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|octo_encrypt_t
name|octo_des_cbc_md5_encrypt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|octo_encrypt_t
name|octo_des_cbc_sha1_encrypt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|octo_decrypt_t
name|octo_des_cbc_decrypt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|octo_decrypt_t
name|octo_des_cbc_md5_decrypt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|octo_decrypt_t
name|octo_des_cbc_sha1_decrypt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|octo_encrypt_t
name|octo_aes_cbc_encrypt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|octo_encrypt_t
name|octo_aes_cbc_md5_encrypt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|octo_encrypt_t
name|octo_aes_cbc_sha1_encrypt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|octo_decrypt_t
name|octo_aes_cbc_decrypt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|octo_decrypt_t
name|octo_aes_cbc_md5_decrypt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|octo_decrypt_t
name|octo_aes_cbc_sha1_decrypt
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MIPS_CAVIUM_CRYPTOCTEON_CRYPTOCTEONVAR_H_ */
end_comment

end_unit

