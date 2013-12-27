begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This is work is derived from material Copyright RSA Data Security, Inc.  *  * The RSA copyright statement and Licence for that original material is  * included below. This is followed by the Apache copyright statement and  * licence for the modifications made to that material.  */
end_comment

begin_comment
comment|/* Copyright (C) 1991-2, RSA Data Security, Inc. Created 1991. All    rights reserved.     License to copy and use this software is granted provided that it    is identified as the "RSA Data Security, Inc. MD5 Message-Digest    Algorithm" in all material mentioning or referencing this software    or this function.     License is also granted to make and use derivative works provided    that such works are identified as "derived from the RSA Data    Security, Inc. MD5 Message-Digest Algorithm" in all material    mentioning or referencing the derived work.     RSA Data Security, Inc. makes no representations concerning either    the merchantability of this software or the suitability of this    software for any particular purpose. It is provided "as is"    without express or implied warranty of any kind.     These notices must be retained in any copies of any part of this    documentation and/or software.  */
end_comment

begin_comment
comment|/* Licensed to the Apache Software Foundation (ASF) under one or more  * contributor license agreements.  See the NOTICE file distributed with  * this work for additional information regarding copyright ownership.  * The ASF licenses this file to You under the Apache License, Version 2.0  * (the "License"); you may not use this file except in compliance with  * the License.  You may obtain a copy of the License at  *  *     http://www.apache.org/licenses/LICENSE-2.0  *  * Unless required by applicable law or agreed to in writing, software  * distributed under the License is distributed on an "AS IS" BASIS,  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  * See the License for the specific language governing permissions and  * limitations under the License.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|APR_MD5_H
end_ifndef

begin_define
define|#
directive|define
name|APR_MD5_H
end_define

begin_include
include|#
directive|include
file|"apu.h"
end_include

begin_include
include|#
directive|include
file|"apr_xlate.h"
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
comment|/**  * @file apr_md5.h  * @brief APR MD5 Routines  */
comment|/**  * @defgroup APR_MD5 MD5 Routines  * @ingroup APR  * @{  */
comment|/** The MD5 digest size */
define|#
directive|define
name|APR_MD5_DIGESTSIZE
value|16
comment|/** @see apr_md5_ctx_t */
typedef|typedef
name|struct
name|apr_md5_ctx_t
name|apr_md5_ctx_t
typedef|;
comment|/** MD5 context. */
struct|struct
name|apr_md5_ctx_t
block|{
comment|/** state (ABCD) */
name|apr_uint32_t
name|state
index|[
literal|4
index|]
decl_stmt|;
comment|/** number of bits, modulo 2^64 (lsb first) */
name|apr_uint32_t
name|count
index|[
literal|2
index|]
decl_stmt|;
comment|/** input buffer */
name|unsigned
name|char
name|buffer
index|[
literal|64
index|]
decl_stmt|;
comment|/** translation handle       *  ignored if xlate is unsupported      */
name|apr_xlate_t
modifier|*
name|xlate
decl_stmt|;
block|}
struct|;
comment|/**  * MD5 Initialize.  Begins an MD5 operation, writing a new context.  * @param context The MD5 context to initialize.  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_md5_init
argument_list|(
name|apr_md5_ctx_t
operator|*
name|context
argument_list|)
expr_stmt|;
comment|/**  * MD5 translation setup.  Provides the APR translation handle to be used   * for translating the content before calculating the digest.  * @param context The MD5 content to set the translation for.  * @param xlate The translation handle to use for this MD5 context   */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_md5_set_xlate
argument_list|(
name|apr_md5_ctx_t
operator|*
name|context
argument_list|,
name|apr_xlate_t
operator|*
name|xlate
argument_list|)
expr_stmt|;
comment|/**  * MD5 block update operation.  Continue an MD5 message-digest operation,   * processing another message block, and updating the context.  * @param context The MD5 content to update.  * @param input next message block to update  * @param inputLen The length of the next message block  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_md5_update
argument_list|(
argument|apr_md5_ctx_t *context
argument_list|,
argument|const void *input
argument_list|,
argument|apr_size_t inputLen
argument_list|)
empty_stmt|;
comment|/**  * MD5 finalization.  Ends an MD5 message-digest operation, writing the   * message digest and zeroing the context  * @param digest The final MD5 digest  * @param context The MD5 content we are finalizing.  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_md5_final
argument_list|(
argument|unsigned char digest[APR_MD5_DIGESTSIZE]
argument_list|,
argument|apr_md5_ctx_t *context
argument_list|)
empty_stmt|;
comment|/**  * MD5 in one step  * @param digest The final MD5 digest  * @param input The message block to use  * @param inputLen The length of the message block  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_md5
argument_list|(
argument|unsigned char digest[APR_MD5_DIGESTSIZE]
argument_list|,
argument|const void *input
argument_list|,
argument|apr_size_t inputLen
argument_list|)
empty_stmt|;
comment|/**  * Encode a password using an MD5 algorithm  * @param password The password to encode  * @param salt The salt string to use for the encoding  * @param result The string to store the encoded password in  * @param nbytes The size of the result buffer  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_md5_encode
argument_list|(
argument|const char *password
argument_list|,
argument|const char *salt
argument_list|,
argument|char *result
argument_list|,
argument|apr_size_t nbytes
argument_list|)
empty_stmt|;
comment|/**  * Encode a password using the bcrypt algorithm  * @param password The password to encode  * @param count The cost of the encoding, possible values are 4 to 31  * @param salt Pointer to binary data to be used as salt for the encoding  * @param salt_len The size of the salt data (must be>= 16)  * @param out The string to store the encoded password in  * @param out_len The size of the result buffer (must be>= 61)  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_bcrypt_encode
argument_list|(
argument|const char *pw
argument_list|,
argument|unsigned int count
argument_list|,
argument|const unsigned char *salt
argument_list|,
argument|apr_size_t salt_len
argument_list|,
argument|char *out
argument_list|,
argument|apr_size_t out_len
argument_list|)
empty_stmt|;
comment|/**  * Validate hashes created by APR-supported algorithms: md5, bcrypt, and sha1.  * hashes created by crypt are supported only on platforms that provide  * crypt(3), so don't rely on that function unless you know that your  * application will be run only on platforms that support it.  On platforms  * that don't support crypt(3), this falls back to a clear text string  * comparison.  * @param passwd The password to validate  * @param hash The password to validate against  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_password_validate
argument_list|(
specifier|const
name|char
operator|*
name|passwd
argument_list|,
specifier|const
name|char
operator|*
name|hash
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
comment|/* !APR_MD5_H */
end_comment

end_unit

