begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Licensed to the Apache Software Foundation (ASF) under one or more  * contributor license agreements.  See the NOTICE file distributed with  * this work for additional information regarding copyright ownership.  * The ASF licenses this file to You under the Apache License, Version 2.0  * (the "License"); you may not use this file except in compliance with  * the License.  You may obtain a copy of the License at  *  *     http://www.apache.org/licenses/LICENSE-2.0  *  * Unless required by applicable law or agreed to in writing, software  * distributed under the License is distributed on an "AS IS" BASIS,  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  * See the License for the specific language governing permissions and  * limitations under the License.  */
end_comment

begin_comment
comment|/* This is derived from material copyright RSA Data Security, Inc.  * Their notice is reproduced below in its entirety.  *  * Copyright (C) 1991-2, RSA Data Security, Inc. Created 1991. All  * rights reserved.  *  * License to copy and use this software is granted provided that it  * is identified as the "RSA Data Security, Inc. MD4 Message-Digest  * Algorithm" in all material mentioning or referencing this software  * or this function.  *  * License is also granted to make and use derivative works provided  * that such works are identified as "derived from the RSA Data  * Security, Inc. MD4 Message-Digest Algorithm" in all material  * mentioning or referencing the derived work.  *  * RSA Data Security, Inc. makes no representations concerning either  * the merchantability of this software or the suitability of this  * software for any particular purpose. It is provided "as is"  * without express or implied warranty of any kind.  *  * These notices must be retained in any copies of any part of this  * documentation and/or software.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|APR_MD4_H
end_ifndef

begin_define
define|#
directive|define
name|APR_MD4_H
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

begin_comment
comment|/**  * @file apr_md4.h  * @brief APR-UTIL MD4 Library  */
end_comment

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
comment|/**  * @defgroup APR_Util_MD4 MD4 Library  * @ingroup APR_Util  * @{  */
comment|/** The digestsize for MD4 */
define|#
directive|define
name|APR_MD4_DIGESTSIZE
value|16
comment|/** @see apr_md4_ctx_t */
typedef|typedef
name|struct
name|apr_md4_ctx_t
name|apr_md4_ctx_t
typedef|;
comment|/** MD4 context. */
struct|struct
name|apr_md4_ctx_t
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
if|#
directive|if
name|APR_HAS_XLATE
comment|/** translation handle */
name|apr_xlate_t
modifier|*
name|xlate
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
comment|/**  * MD4 Initialize.  Begins an MD4 operation, writing a new context.  * @param context The MD4 context to initialize.  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_md4_init
argument_list|(
name|apr_md4_ctx_t
operator|*
name|context
argument_list|)
expr_stmt|;
if|#
directive|if
name|APR_HAS_XLATE
comment|/**  * MDr4 translation setup.  Provides the APR translation handle to be used   * for translating the content before calculating the digest.  * @param context The MD4 content to set the translation for.  * @param xlate The translation handle to use for this MD4 context   */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_md4_set_xlate
argument_list|(
name|apr_md4_ctx_t
operator|*
name|context
argument_list|,
name|apr_xlate_t
operator|*
name|xlate
argument_list|)
expr_stmt|;
else|#
directive|else
define|#
directive|define
name|apr_md4_set_xlate
parameter_list|(
name|context
parameter_list|,
name|xlate
parameter_list|)
value|APR_ENOTIMPL
endif|#
directive|endif
comment|/**  * MD4 block update operation.  Continue an MD4 message-digest operation,   * processing another message block, and updating the context.  * @param context The MD4 content to update.  * @param input next message block to update  * @param inputLen The length of the next message block  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_md4_update
argument_list|(
argument|apr_md4_ctx_t *context
argument_list|,
argument|const unsigned char *input
argument_list|,
argument|apr_size_t inputLen
argument_list|)
empty_stmt|;
comment|/**  * MD4 finalization.  Ends an MD4 message-digest operation, writing the   * message digest and zeroing the context  * @param digest The final MD4 digest  * @param context The MD4 content we are finalizing.  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_md4_final
argument_list|(
argument|unsigned char digest[APR_MD4_DIGESTSIZE]
argument_list|,
argument|apr_md4_ctx_t *context
argument_list|)
empty_stmt|;
comment|/**  * MD4 digest computation  * @param digest The MD4 digest  * @param input message block to use  * @param inputLen The length of the message block  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_md4
argument_list|(
argument|unsigned char digest[APR_MD4_DIGESTSIZE]
argument_list|,
argument|const unsigned char *input
argument_list|,
argument|apr_size_t inputLen
argument_list|)
empty_stmt|;
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
comment|/* !APR_MD4_H */
end_comment

end_unit

