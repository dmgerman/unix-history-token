begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Licensed to the Apache Software Foundation (ASF) under one or more  * contributor license agreements.  See the NOTICE file distributed with  * this work for additional information regarding copyright ownership.  * The ASF licenses this file to You under the Apache License, Version 2.0  * (the "License"); you may not use this file except in compliance with  * the License.  You may obtain a copy of the License at  *  *     http://www.apache.org/licenses/LICENSE-2.0  *  * Unless required by applicable law or agreed to in writing, software  * distributed under the License is distributed on an "AS IS" BASIS,  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  * See the License for the specific language governing permissions and  * limitations under the License.  */
end_comment

begin_comment
comment|/**  * @file apr_uuid.h  * @brief APR UUID library  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|APR_UUID_H
end_ifndef

begin_define
define|#
directive|define
name|APR_UUID_H
end_define

begin_include
include|#
directive|include
file|"apu.h"
end_include

begin_include
include|#
directive|include
file|"apr_errno.h"
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
comment|/**  * @defgroup APR_UUID UUID Handling  * @ingroup APR  * @{  */
comment|/**  * we represent a UUID as a block of 16 bytes.  */
typedef|typedef
struct|struct
block|{
name|unsigned
name|char
name|data
index|[
literal|16
index|]
decl_stmt|;
comment|/**< the actual UUID */
block|}
name|apr_uuid_t
typedef|;
comment|/** UUIDs are formatted as: 00112233-4455-6677-8899-AABBCCDDEEFF */
define|#
directive|define
name|APR_UUID_FORMATTED_LENGTH
value|36
comment|/**  * Generate and return a (new) UUID  * @param uuid The resulting UUID  */
name|APU_DECLARE
argument_list|(
argument|void
argument_list|)
name|apr_uuid_get
argument_list|(
name|apr_uuid_t
operator|*
name|uuid
argument_list|)
expr_stmt|;
comment|/**  * Format a UUID into a string, following the standard format  * @param buffer The buffer to place the formatted UUID string into. It must  *               be at least APR_UUID_FORMATTED_LENGTH + 1 bytes long to hold  *               the formatted UUID and a null terminator  * @param uuid The UUID to format  */
name|APU_DECLARE
argument_list|(
argument|void
argument_list|)
name|apr_uuid_format
argument_list|(
name|char
operator|*
name|buffer
argument_list|,
specifier|const
name|apr_uuid_t
operator|*
name|uuid
argument_list|)
expr_stmt|;
comment|/**  * Parse a standard-format string into a UUID  * @param uuid The resulting UUID  * @param uuid_str The formatted UUID  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_uuid_parse
argument_list|(
name|apr_uuid_t
operator|*
name|uuid
argument_list|,
specifier|const
name|char
operator|*
name|uuid_str
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
comment|/* APR_UUID_H */
end_comment

end_unit

