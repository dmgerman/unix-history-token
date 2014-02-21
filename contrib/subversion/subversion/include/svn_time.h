begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  * @copyright  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  * @endcopyright  *  * @file svn_time.h  * @brief Time/date utilities  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_TIME_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_TIME_H
end_define

begin_include
include|#
directive|include
file|<apr_pools.h>
end_include

begin_include
include|#
directive|include
file|<apr_time.h>
end_include

begin_include
include|#
directive|include
file|"svn_error.h"
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
comment|/** Convert @a when to a<tt>const char *</tt> representation allocated  * in @a pool.  Use svn_time_from_cstring() for the reverse  * conversion.  */
specifier|const
name|char
modifier|*
name|svn_time_to_cstring
parameter_list|(
name|apr_time_t
name|when
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/** Convert @a data to an @c apr_time_t @a when.  * Use @a pool for temporary memory allocation.  */
name|svn_error_t
modifier|*
name|svn_time_from_cstring
parameter_list|(
name|apr_time_t
modifier|*
name|when
parameter_list|,
specifier|const
name|char
modifier|*
name|data
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/** Convert @a when to a<tt>const char *</tt> representation allocated  * in @a pool, suitable for human display in UTF8.  */
specifier|const
name|char
modifier|*
name|svn_time_to_human_cstring
parameter_list|(
name|apr_time_t
name|when
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/** Convert a human-readable date @a text into an @c apr_time_t, using  * @a now as the current time and storing the result in @a result.  * The local time zone will be used to compute the appropriate GMT  * offset if @a text contains a local time specification.  Set @a  * matched to indicate whether or not @a text was parsed successfully.  * Perform any allocation in @a pool.  Return an error iff an internal  * error (rather than a simple parse error) occurs.  */
name|svn_error_t
modifier|*
name|svn_parse_date
parameter_list|(
name|svn_boolean_t
modifier|*
name|matched
parameter_list|,
name|apr_time_t
modifier|*
name|result
parameter_list|,
specifier|const
name|char
modifier|*
name|text
parameter_list|,
name|apr_time_t
name|now
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/** Sleep until the next second, to ensure that any files modified  * after we exit have a different timestamp than the one we recorded.  *  * @deprecated Provided for backward compatibility with the 1.5 API.  * Use svn_io_sleep_for_timestamps() instead.  */
name|SVN_DEPRECATED
name|void
name|svn_sleep_for_timestamps
parameter_list|(
name|void
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
comment|/* SVN_TIME_H */
end_comment

end_unit

