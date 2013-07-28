begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Licensed to the Apache Software Foundation (ASF) under one or more  * contributor license agreements.  See the NOTICE file distributed with  * this work for additional information regarding copyright ownership.  * The ASF licenses this file to You under the Apache License, Version 2.0  * (the "License"); you may not use this file except in compliance with  * the License.  You may obtain a copy of the License at  *  *     http://www.apache.org/licenses/LICENSE-2.0  *  * Unless required by applicable law or agreed to in writing, software  * distributed under the License is distributed on an "AS IS" BASIS,  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  * See the License for the specific language governing permissions and  * limitations under the License.  */
end_comment

begin_comment
comment|/*  * FILE:        sha2.h  * AUTHOR:      Aaron D. Gifford<me@aarongifford.com>  *   * A licence was granted to the ASF by Aaron on 4 November 2003.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__SHA2_H__
end_ifndef

begin_define
define|#
directive|define
name|__SHA2_H__
end_define

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
include|#
directive|include
file|"apr.h"
comment|/*** SHA-256 Various Length Definitions ***********************/
define|#
directive|define
name|SHA256_BLOCK_LENGTH
value|64
define|#
directive|define
name|SHA256_DIGEST_LENGTH
value|32
define|#
directive|define
name|SHA256_DIGEST_STRING_LENGTH
value|(SHA256_DIGEST_LENGTH * 2 + 1)
comment|/*** SHA-256/384/512 Context Structures *******************************/
typedef|typedef
struct|struct
name|_SHA256_CTX
block|{
name|apr_uint32_t
name|state
index|[
literal|8
index|]
decl_stmt|;
name|apr_uint64_t
name|bitcount
decl_stmt|;
name|apr_byte_t
name|buffer
index|[
name|SHA256_BLOCK_LENGTH
index|]
decl_stmt|;
block|}
name|SHA256_CTX
typedef|;
comment|/*** SHA-256/384/512 Function Prototypes ******************************/
name|void
name|apr__SHA256_Init
parameter_list|(
name|SHA256_CTX
modifier|*
parameter_list|)
function_decl|;
name|void
name|apr__SHA256_Update
parameter_list|(
name|SHA256_CTX
modifier|*
parameter_list|,
specifier|const
name|apr_byte_t
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
name|void
name|apr__SHA256_Final
parameter_list|(
name|apr_byte_t
index|[
name|SHA256_DIGEST_LENGTH
index|]
parameter_list|,
name|SHA256_CTX
modifier|*
parameter_list|)
function_decl|;
name|char
modifier|*
name|apr__SHA256_End
parameter_list|(
name|SHA256_CTX
modifier|*
parameter_list|,
name|char
index|[
name|SHA256_DIGEST_STRING_LENGTH
index|]
parameter_list|)
function_decl|;
name|char
modifier|*
name|apr__SHA256_Data
parameter_list|(
specifier|const
name|apr_byte_t
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|char
index|[
name|SHA256_DIGEST_STRING_LENGTH
index|]
parameter_list|)
function_decl|;
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
comment|/* __SHA2_H__ */
end_comment

end_unit

