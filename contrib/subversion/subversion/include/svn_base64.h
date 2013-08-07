begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  * @copyright  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  * @endcopyright  *  * @file svn_base64.h  * @brief Base64 encoding and decoding functions  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_BASE64_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_BASE64_H
end_define

begin_include
include|#
directive|include
file|<apr_pools.h>
end_include

begin_include
include|#
directive|include
file|"svn_types.h"
end_include

begin_include
include|#
directive|include
file|"svn_io.h"
end_include

begin_comment
comment|/* for svn_stream_t */
end_comment

begin_include
include|#
directive|include
file|"svn_string.h"
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
comment|/* __cplusplus */
comment|/**  *  *  * @defgroup base64 Base64 encoding/decoding functions  *  * @{  */
comment|/** Return a writable generic stream which will encode binary data in  * base64 format and write the encoded data to @a output.  Be sure to  * close the stream when done writing in order to squeeze out the last  * bit of encoded data.  The stream is allocated in @a pool.  */
name|svn_stream_t
modifier|*
name|svn_base64_encode
parameter_list|(
name|svn_stream_t
modifier|*
name|output
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/** Return a writable generic stream which will decode base64-encoded  * data and write the decoded data to @a output.  The stream is allocated  * in @a pool.  */
name|svn_stream_t
modifier|*
name|svn_base64_decode
parameter_list|(
name|svn_stream_t
modifier|*
name|output
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/** Encode an @c svn_stringbuf_t into base64.  *  * A simple interface for encoding base64 data assuming we have all of  * it present at once.  If @a break_lines is true, newlines will be  * inserted periodically; otherwise the string will only consist of  * base64 encoding characters.  The returned string will be allocated  * from @a pool.  *  * @since New in 1.6.  */
specifier|const
name|svn_string_t
modifier|*
name|svn_base64_encode_string2
parameter_list|(
specifier|const
name|svn_string_t
modifier|*
name|str
parameter_list|,
name|svn_boolean_t
name|break_lines
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/**  * Same as svn_base64_encode_string2, but with @a break_lines always  * TRUE.  *  * @deprecated Provided for backward compatibility with the 1.5 API.  */
name|SVN_DEPRECATED
specifier|const
name|svn_string_t
modifier|*
name|svn_base64_encode_string
parameter_list|(
specifier|const
name|svn_string_t
modifier|*
name|str
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/** Decode an @c svn_stringbuf_t from base64.  *  * A simple interface for decoding base64 data assuming we have all of  * it present at once.  The returned string will be allocated from @c  * pool.  *  */
specifier|const
name|svn_string_t
modifier|*
name|svn_base64_decode_string
parameter_list|(
specifier|const
name|svn_string_t
modifier|*
name|str
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/** Return a base64-encoded checksum for finalized @a digest.  *  * @a digest contains @c APR_MD5_DIGESTSIZE bytes of finalized data.  * Allocate the returned checksum in @a pool.  *  * @deprecated Provided for backward compatibility with the 1.5 API.  */
name|SVN_DEPRECATED
name|svn_stringbuf_t
modifier|*
name|svn_base64_from_md5
parameter_list|(
name|unsigned
name|char
name|digest
index|[]
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/** @} end group: Base64 encoding/decoding functions */
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __cplusplus */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SVN_BASE64_H */
end_comment

end_unit

