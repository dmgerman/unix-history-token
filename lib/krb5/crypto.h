begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997 - 2008 Kungliga Tekniska HÃ¶gskolan  * (Royal Institute of Technology, Stockholm, Sweden).  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * 3. Neither the name of the Institute nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HEIMDAL_SMALLER
end_ifndef

begin_define
define|#
directive|define
name|DES3_OLD_ENCTYPE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|_krb5_key_data
block|{
name|krb5_keyblock
modifier|*
name|key
decl_stmt|;
name|krb5_data
modifier|*
name|schedule
decl_stmt|;
block|}
struct|;
end_struct

begin_struct_decl
struct_decl|struct
name|_krb5_key_usage
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|krb5_crypto_data
block|{
name|struct
name|_krb5_encryption_type
modifier|*
name|et
decl_stmt|;
name|struct
name|_krb5_key_data
name|key
decl_stmt|;
name|int
name|num_key_usage
decl_stmt|;
name|struct
name|_krb5_key_usage
modifier|*
name|key_usage
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CRYPTO_ETYPE
parameter_list|(
name|C
parameter_list|)
value|((C)->et->type)
end_define

begin_comment
comment|/* bits for `flags' below */
end_comment

begin_define
define|#
directive|define
name|F_KEYED
value|1
end_define

begin_comment
comment|/* checksum is keyed */
end_comment

begin_define
define|#
directive|define
name|F_CPROOF
value|2
end_define

begin_comment
comment|/* checksum is collision proof */
end_comment

begin_define
define|#
directive|define
name|F_DERIVED
value|4
end_define

begin_comment
comment|/* uses derived keys */
end_comment

begin_define
define|#
directive|define
name|F_VARIANT
value|8
end_define

begin_comment
comment|/* uses `variant' keys (6.4.3) */
end_comment

begin_define
define|#
directive|define
name|F_PSEUDO
value|16
end_define

begin_comment
comment|/* not a real protocol type */
end_comment

begin_define
define|#
directive|define
name|F_SPECIAL
value|32
end_define

begin_comment
comment|/* backwards */
end_comment

begin_define
define|#
directive|define
name|F_DISABLED
value|64
end_define

begin_comment
comment|/* enctype/checksum disabled */
end_comment

begin_define
define|#
directive|define
name|F_WEAK
value|128
end_define

begin_comment
comment|/* enctype is considered weak */
end_comment

begin_struct
struct|struct
name|salt_type
block|{
name|krb5_salttype
name|type
decl_stmt|;
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|krb5_error_code
function_decl|(
modifier|*
name|string_to_key
function_decl|)
parameter_list|(
name|krb5_context
parameter_list|,
name|krb5_enctype
parameter_list|,
name|krb5_data
parameter_list|,
name|krb5_salt
parameter_list|,
name|krb5_data
parameter_list|,
name|krb5_keyblock
modifier|*
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|_krb5_key_type
block|{
name|krb5_enctype
name|type
decl_stmt|;
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|size_t
name|bits
decl_stmt|;
name|size_t
name|size
decl_stmt|;
name|size_t
name|schedule_size
decl_stmt|;
name|void
function_decl|(
modifier|*
name|random_key
function_decl|)
parameter_list|(
name|krb5_context
parameter_list|,
name|krb5_keyblock
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|schedule
function_decl|)
parameter_list|(
name|krb5_context
parameter_list|,
name|struct
name|_krb5_key_type
modifier|*
parameter_list|,
name|struct
name|_krb5_key_data
modifier|*
parameter_list|)
function_decl|;
name|struct
name|salt_type
modifier|*
name|string_to_key
decl_stmt|;
name|void
function_decl|(
modifier|*
name|random_to_key
function_decl|)
parameter_list|(
name|krb5_context
parameter_list|,
name|krb5_keyblock
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|cleanup
function_decl|)
parameter_list|(
name|krb5_context
parameter_list|,
name|struct
name|_krb5_key_data
modifier|*
parameter_list|)
function_decl|;
specifier|const
name|EVP_CIPHER
modifier|*
function_decl|(
modifier|*
name|evp
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|_krb5_checksum_type
block|{
name|krb5_cksumtype
name|type
decl_stmt|;
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|size_t
name|blocksize
decl_stmt|;
name|size_t
name|checksumsize
decl_stmt|;
name|unsigned
name|flags
decl_stmt|;
name|krb5_error_code
function_decl|(
modifier|*
name|checksum
function_decl|)
parameter_list|(
name|krb5_context
name|context
parameter_list|,
name|struct
name|_krb5_key_data
modifier|*
name|key
parameter_list|,
specifier|const
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|,
name|unsigned
name|usage
parameter_list|,
name|Checksum
modifier|*
name|csum
parameter_list|)
function_decl|;
name|krb5_error_code
function_decl|(
modifier|*
name|verify
function_decl|)
parameter_list|(
name|krb5_context
name|context
parameter_list|,
name|struct
name|_krb5_key_data
modifier|*
name|key
parameter_list|,
specifier|const
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|,
name|unsigned
name|usage
parameter_list|,
name|Checksum
modifier|*
name|csum
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|_krb5_encryption_type
block|{
name|krb5_enctype
name|type
decl_stmt|;
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|size_t
name|blocksize
decl_stmt|;
name|size_t
name|padsize
decl_stmt|;
name|size_t
name|confoundersize
decl_stmt|;
name|struct
name|_krb5_key_type
modifier|*
name|keytype
decl_stmt|;
name|struct
name|_krb5_checksum_type
modifier|*
name|checksum
decl_stmt|;
name|struct
name|_krb5_checksum_type
modifier|*
name|keyed_checksum
decl_stmt|;
name|unsigned
name|flags
decl_stmt|;
name|krb5_error_code
function_decl|(
modifier|*
name|encrypt
function_decl|)
parameter_list|(
name|krb5_context
name|context
parameter_list|,
name|struct
name|_krb5_key_data
modifier|*
name|key
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|size_t
name|len
parameter_list|,
name|krb5_boolean
name|encryptp
parameter_list|,
name|int
name|usage
parameter_list|,
name|void
modifier|*
name|ivec
parameter_list|)
function_decl|;
name|size_t
name|prf_length
decl_stmt|;
name|krb5_error_code
function_decl|(
modifier|*
name|prf
function_decl|)
parameter_list|(
name|krb5_context
parameter_list|,
name|krb5_crypto
parameter_list|,
specifier|const
name|krb5_data
modifier|*
parameter_list|,
name|krb5_data
modifier|*
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ENCRYPTION_USAGE
parameter_list|(
name|U
parameter_list|)
value|(((U)<< 8) | 0xAA)
end_define

begin_define
define|#
directive|define
name|INTEGRITY_USAGE
parameter_list|(
name|U
parameter_list|)
value|(((U)<< 8) | 0x55)
end_define

begin_define
define|#
directive|define
name|CHECKSUM_USAGE
parameter_list|(
name|U
parameter_list|)
value|(((U)<< 8) | 0x99)
end_define

begin_comment
comment|/* Checksums */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|_krb5_checksum_type
name|_krb5_checksum_none
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|_krb5_checksum_type
name|_krb5_checksum_crc32
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|_krb5_checksum_type
name|_krb5_checksum_rsa_md4
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|_krb5_checksum_type
name|_krb5_checksum_rsa_md4_des
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|_krb5_checksum_type
name|_krb5_checksum_rsa_md5_des
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|_krb5_checksum_type
name|_krb5_checksum_rsa_md5_des3
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|_krb5_checksum_type
name|_krb5_checksum_rsa_md5
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|_krb5_checksum_type
name|_krb5_checksum_hmac_sha1_des3
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|_krb5_checksum_type
name|_krb5_checksum_hmac_sha1_aes128
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|_krb5_checksum_type
name|_krb5_checksum_hmac_sha1_aes256
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|_krb5_checksum_type
name|_krb5_checksum_hmac_md5
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|_krb5_checksum_type
name|_krb5_checksum_sha1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|_krb5_checksum_type
modifier|*
name|_krb5_checksum_types
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|_krb5_num_checksums
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Salts */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|salt_type
name|_krb5_AES_salt
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|salt_type
name|_krb5_arcfour_salt
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|salt_type
name|_krb5_des_salt
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|salt_type
name|_krb5_des3_salt
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|salt_type
name|_krb5_des3_salt_derived
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Encryption types */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|_krb5_encryption_type
name|_krb5_enctype_aes256_cts_hmac_sha1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|_krb5_encryption_type
name|_krb5_enctype_aes128_cts_hmac_sha1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|_krb5_encryption_type
name|_krb5_enctype_des3_cbc_sha1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|_krb5_encryption_type
name|_krb5_enctype_des3_cbc_md5
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|_krb5_encryption_type
name|_krb5_enctype_des3_cbc_none
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|_krb5_encryption_type
name|_krb5_enctype_arcfour_hmac_md5
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|_krb5_encryption_type
name|_krb5_enctype_des_cbc_md5
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|_krb5_encryption_type
name|_krb5_enctype_old_des3_cbc_sha1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|_krb5_encryption_type
name|_krb5_enctype_des_cbc_crc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|_krb5_encryption_type
name|_krb5_enctype_des_cbc_md4
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|_krb5_encryption_type
name|_krb5_enctype_des_cbc_md5
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|_krb5_encryption_type
name|_krb5_enctype_des_cbc_none
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|_krb5_encryption_type
name|_krb5_enctype_des_cfb64_none
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|_krb5_encryption_type
name|_krb5_enctype_des_pcbc_none
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|_krb5_encryption_type
name|_krb5_enctype_null
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|_krb5_encryption_type
modifier|*
name|_krb5_etypes
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|_krb5_num_etypes
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Interface to the EVP crypto layer provided by hcrypto */
end_comment

begin_struct
struct|struct
name|_krb5_evp_schedule
block|{
name|EVP_CIPHER_CTX
name|ectx
decl_stmt|;
name|EVP_CIPHER_CTX
name|dctx
decl_stmt|;
block|}
struct|;
end_struct

end_unit

