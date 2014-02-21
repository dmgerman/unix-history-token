begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Licensed to the Apache Software Foundation (ASF) under one or more  * contributor license agreements.  See the NOTICE file distributed with  * this work for additional information regarding copyright ownership.  * The ASF licenses this file to You under the Apache License, Version 2.0  * (the "License"); you may not use this file except in compliance with  * the License.  You may obtain a copy of the License at  *  *     http://www.apache.org/licenses/LICENSE-2.0  *  * Unless required by applicable law or agreed to in writing, software  * distributed under the License is distributed on an "AS IS" BASIS,  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  * See the License for the specific language governing permissions and  * limitations under the License.  */
end_comment

begin_comment
comment|/* NIST Secure Hash Algorithm  * 	heavily modified by Uwe Hollerbach uh@alumni.caltech edu  * 	from Peter C. Gutmann's implementation as found in  * 	Applied Cryptography by Bruce Schneier  * 	This code is hereby placed in the public domain  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|APR_SHA1_H
end_ifndef

begin_define
define|#
directive|define
name|APR_SHA1_H
end_define

begin_include
include|#
directive|include
file|"apu.h"
end_include

begin_include
include|#
directive|include
file|"apr_general.h"
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
comment|/**  * @file apr_sha1.h  * @brief APR-UTIL SHA1 library  */
comment|/** size of the SHA1 DIGEST */
define|#
directive|define
name|APR_SHA1_DIGESTSIZE
value|20
comment|/**  * Define the Magic String prefix that identifies a password as being  * hashed using our algorithm.  */
define|#
directive|define
name|APR_SHA1PW_ID
value|"{SHA}"
comment|/** length of the SHA Password */
define|#
directive|define
name|APR_SHA1PW_IDLEN
value|5
comment|/** @see apr_sha1_ctx_t */
typedef|typedef
name|struct
name|apr_sha1_ctx_t
name|apr_sha1_ctx_t
typedef|;
comment|/**   * SHA1 context structure  */
struct|struct
name|apr_sha1_ctx_t
block|{
comment|/** message digest */
name|apr_uint32_t
name|digest
index|[
literal|5
index|]
decl_stmt|;
comment|/** 64-bit bit counts */
name|apr_uint32_t
name|count_lo
decl_stmt|,
name|count_hi
decl_stmt|;
comment|/** SHA data buffer */
name|apr_uint32_t
name|data
index|[
literal|16
index|]
decl_stmt|;
comment|/** unprocessed amount in data */
name|int
name|local
decl_stmt|;
block|}
struct|;
comment|/**  * Provide a means to SHA1 crypt/encode a plaintext password in a way which  * makes password file compatible with those commonly use in netscape web  * and ldap installations.  * @param clear The plaintext password  * @param len The length of the plaintext password  * @param out The encrypted/encoded password  * @note SHA1 support is useful for migration purposes, but is less  *     secure than Apache's password format, since Apache's (MD5)  *     password format uses a random eight character salt to generate  *     one of many possible hashes for the same password.  Netscape  *     uses plain SHA1 without a salt, so the same password  *     will always generate the same hash, making it easier  *     to break since the search space is smaller.  */
name|APU_DECLARE
argument_list|(
argument|void
argument_list|)
name|apr_sha1_base64
argument_list|(
argument|const char *clear
argument_list|,
argument|int len
argument_list|,
argument|char *out
argument_list|)
empty_stmt|;
comment|/**  * Initialize the SHA digest  * @param context The SHA context to initialize  */
name|APU_DECLARE
argument_list|(
argument|void
argument_list|)
name|apr_sha1_init
argument_list|(
name|apr_sha1_ctx_t
operator|*
name|context
argument_list|)
expr_stmt|;
comment|/**  * Update the SHA digest  * @param context The SHA1 context to update  * @param input The buffer to add to the SHA digest  * @param inputLen The length of the input buffer  */
name|APU_DECLARE
argument_list|(
argument|void
argument_list|)
name|apr_sha1_update
argument_list|(
argument|apr_sha1_ctx_t *context
argument_list|,
argument|const char *input
argument_list|,
argument|unsigned int inputLen
argument_list|)
empty_stmt|;
comment|/**  * Update the SHA digest with binary data  * @param context The SHA1 context to update  * @param input The buffer to add to the SHA digest  * @param inputLen The length of the input buffer  */
name|APU_DECLARE
argument_list|(
argument|void
argument_list|)
name|apr_sha1_update_binary
argument_list|(
argument|apr_sha1_ctx_t *context
argument_list|,
argument|const unsigned char *input
argument_list|,
argument|unsigned int inputLen
argument_list|)
empty_stmt|;
comment|/**  * Finish computing the SHA digest  * @param digest the output buffer in which to store the digest  * @param context The context to finalize  */
name|APU_DECLARE
argument_list|(
argument|void
argument_list|)
name|apr_sha1_final
argument_list|(
argument|unsigned char digest[APR_SHA1_DIGESTSIZE]
argument_list|,
argument|apr_sha1_ctx_t *context
argument_list|)
empty_stmt|;
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
comment|/* APR_SHA1_H */
end_comment

end_unit

