begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2009 Kungliga Tekniska HÃ¶gskolan  * (Royal Institute of Technology, Stockholm, Sweden).  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * 3. Neither the name of the Institute nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $Id$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HEIM_EVP_HCRYPTO_H
end_ifndef

begin_define
define|#
directive|define
name|HEIM_EVP_HCRYPTO_H
value|1
end_define

begin_comment
comment|/* symbol renaming */
end_comment

begin_define
define|#
directive|define
name|EVP_hcrypto_md2
value|hc_EVP_hcrypto_md2
end_define

begin_define
define|#
directive|define
name|EVP_hcrypto_md4
value|hc_EVP_hcrypto_md4
end_define

begin_define
define|#
directive|define
name|EVP_hcrypto_md5
value|hc_EVP_hcrypto_md5
end_define

begin_define
define|#
directive|define
name|EVP_hcrypto_sha1
value|hc_EVP_hcrypto_sha1
end_define

begin_define
define|#
directive|define
name|EVP_hcrypto_sha256
value|hc_EVP_hcrypto_sha256
end_define

begin_define
define|#
directive|define
name|EVP_hcrypto_sha384
value|hc_EVP_hcrypto_sha384
end_define

begin_define
define|#
directive|define
name|EVP_hcrypto_sha512
value|hc_EVP_hcrypto_sha512
end_define

begin_define
define|#
directive|define
name|EVP_hcrypto_des_cbc
value|hc_EVP_hcrypto_des_cbc
end_define

begin_define
define|#
directive|define
name|EVP_hcrypto_des_ede3_cbc
value|hc_EVP_hcrypto_des_ede3_cbc
end_define

begin_define
define|#
directive|define
name|EVP_hcrypto_aes_128_cbc
value|hc_EVP_hcrypto_aes_128_cbc
end_define

begin_define
define|#
directive|define
name|EVP_hcrypto_aes_192_cbc
value|hc_EVP_hcrypto_aes_192_cbc
end_define

begin_define
define|#
directive|define
name|EVP_hcrypto_aes_256_cbc
value|hc_EVP_hcrypto_aes_256_cbc
end_define

begin_define
define|#
directive|define
name|EVP_hcrypto_aes_128_cfb8
value|hc_EVP_hcrypto_aes_128_cfb8
end_define

begin_define
define|#
directive|define
name|EVP_hcrypto_aes_192_cfb8
value|hc_EVP_hcrypto_aes_192_cfb8
end_define

begin_define
define|#
directive|define
name|EVP_hcrypto_aes_256_cfb8
value|hc_EVP_hcrypto_aes_256_cfb8
end_define

begin_define
define|#
directive|define
name|EVP_hcrypto_rc4
value|hc_EVP_hcrypto_rc4
end_define

begin_define
define|#
directive|define
name|EVP_hcrypto_rc4_40
value|hc_EVP_hcrypto_rc4_40
end_define

begin_define
define|#
directive|define
name|EVP_hcrypto_rc2_40_cbc
value|hc_EVP_hcrypto_rc2_40_cbc
end_define

begin_define
define|#
directive|define
name|EVP_hcrypto_rc2_64_cbc
value|hc_EVP_hcrypto_rc2_64_cbc
end_define

begin_define
define|#
directive|define
name|EVP_hcrypto_rc2_cbc
value|hc_EVP_hcrypto_rc2_cbc
end_define

begin_define
define|#
directive|define
name|EVP_hcrypto_camellia_128_cbc
value|hc_EVP_hcrypto_camellia_128_cbc
end_define

begin_define
define|#
directive|define
name|EVP_hcrypto_camellia_192_cbc
value|hc_EVP_hcrypto_camellia_192_cbc
end_define

begin_define
define|#
directive|define
name|EVP_hcrypto_camellia_256_cbc
value|hc_EVP_hcrypto_camellia_256_cbc
end_define

begin_comment
comment|/*  *  */
end_comment

begin_function_decl
name|HC_CPP_BEGIN
specifier|const
name|EVP_MD
modifier|*
name|EVP_hcrypto_md2
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|EVP_MD
modifier|*
name|EVP_hcrypto_md4
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|EVP_MD
modifier|*
name|EVP_hcrypto_md5
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|EVP_MD
modifier|*
name|EVP_hcrypto_sha1
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|EVP_MD
modifier|*
name|EVP_hcrypto_sha256
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|EVP_MD
modifier|*
name|EVP_hcrypto_sha384
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|EVP_MD
modifier|*
name|EVP_hcrypto_sha512
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|EVP_CIPHER
modifier|*
name|EVP_hcrypto_rc4
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|EVP_CIPHER
modifier|*
name|EVP_hcrypto_rc4_40
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|EVP_CIPHER
modifier|*
name|EVP_hcrypto_rc2_cbc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|EVP_CIPHER
modifier|*
name|EVP_hcrypto_rc2_40_cbc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|EVP_CIPHER
modifier|*
name|EVP_hcrypto_rc2_64_cbc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|EVP_CIPHER
modifier|*
name|EVP_hcrypto_des_cbc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|EVP_CIPHER
modifier|*
name|EVP_hcrypto_des_ede3_cbc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|EVP_CIPHER
modifier|*
name|EVP_hcrypto_aes_128_cbc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|EVP_CIPHER
modifier|*
name|EVP_hcrypto_aes_192_cbc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|EVP_CIPHER
modifier|*
name|EVP_hcrypto_aes_256_cbc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|EVP_CIPHER
modifier|*
name|EVP_hcrypto_aes_128_cfb8
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|EVP_CIPHER
modifier|*
name|EVP_hcrypto_aes_192_cfb8
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|EVP_CIPHER
modifier|*
name|EVP_hcrypto_aes_256_cfb8
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|EVP_CIPHER
modifier|*
name|EVP_hcrypto_camellia_128_cbc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|EVP_CIPHER
modifier|*
name|EVP_hcrypto_camellia_192_cbc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|EVP_CIPHER
modifier|*
name|EVP_hcrypto_camellia_256_cbc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|HC_CPP_END
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HEIM_EVP_HCRYPTO_H */
end_comment

end_unit

