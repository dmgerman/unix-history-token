begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Licensed to the Apache Software Foundation (ASF) under one or more  * contributor license agreements.  See the NOTICE file distributed with  * this work for additional information regarding copyright ownership.  * The ASF licenses this file to You under the Apache License, Version 2.0  * (the "License"); you may not use this file except in compliance with  * the License.  You may obtain a copy of the License at  *  *     http://www.apache.org/licenses/LICENSE-2.0  *  * Unless required by applicable law or agreed to in writing, software  * distributed under the License is distributed on an "AS IS" BASIS,  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  * See the License for the specific language governing permissions and  * limitations under the License.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|APR_STRMATCH_H
end_ifndef

begin_define
define|#
directive|define
name|APR_STRMATCH_H
end_define

begin_comment
comment|/**  * @file apr_strmatch.h  * @brief APR-UTIL string matching routines  */
end_comment

begin_include
include|#
directive|include
file|"apu.h"
end_include

begin_include
include|#
directive|include
file|"apr_pools.h"
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
comment|/**  * @defgroup APR_Util_StrMatch String matching routines  * @ingroup APR_Util  * @{  */
comment|/** @see apr_strmatch_pattern */
typedef|typedef
name|struct
name|apr_strmatch_pattern
name|apr_strmatch_pattern
typedef|;
comment|/**  * Precompiled search pattern  */
struct|struct
name|apr_strmatch_pattern
block|{
comment|/** Function called to compare */
specifier|const
name|char
modifier|*
function_decl|(
modifier|*
name|compare
function_decl|)
parameter_list|(
specifier|const
name|apr_strmatch_pattern
modifier|*
name|this_pattern
parameter_list|,
specifier|const
name|char
modifier|*
name|s
parameter_list|,
name|apr_size_t
name|slen
parameter_list|)
function_decl|;
specifier|const
name|char
modifier|*
name|pattern
decl_stmt|;
comment|/**< Current pattern */
name|apr_size_t
name|length
decl_stmt|;
comment|/**< Current length */
name|void
modifier|*
name|context
decl_stmt|;
comment|/**< hook to add precomputed metadata */
block|}
struct|;
if|#
directive|if
name|defined
argument_list|(
name|DOXYGEN
argument_list|)
comment|/**  * Search for a precompiled pattern within a string  * @param pattern The pattern  * @param s The string in which to search for the pattern  * @param slen The length of s (excluding null terminator)  * @return A pointer to the first instance of the pattern in s, or  *         NULL if not found  */
name|APU_DECLARE
argument_list|(
argument|const char *
argument_list|)
name|apr_strmatch
argument_list|(
argument|const apr_strmatch_pattern *pattern
argument_list|,
argument|const char *s
argument_list|,
argument|apr_size_t slen
argument_list|)
empty_stmt|;
else|#
directive|else
define|#
directive|define
name|apr_strmatch
parameter_list|(
name|pattern
parameter_list|,
name|s
parameter_list|,
name|slen
parameter_list|)
value|(*((pattern)->compare))((pattern), (s), (slen))
endif|#
directive|endif
comment|/**  * Precompile a pattern for matching using the Boyer-Moore-Horspool algorithm  * @param p The pool from which to allocate the pattern  * @param s The pattern string  * @param case_sensitive Whether the matching should be case-sensitive  * @return a pointer to the compiled pattern, or NULL if compilation fails  */
name|APU_DECLARE
argument_list|(
argument|const apr_strmatch_pattern *
argument_list|)
name|apr_strmatch_precompile
argument_list|(
argument|apr_pool_t *p
argument_list|,
argument|const char *s
argument_list|,
argument|int case_sensitive
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
comment|/* !APR_STRMATCH_H */
end_comment

end_unit

