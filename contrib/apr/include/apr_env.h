begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Licensed to the Apache Software Foundation (ASF) under one or more  * contributor license agreements.  See the NOTICE file distributed with  * this work for additional information regarding copyright ownership.  * The ASF licenses this file to You under the Apache License, Version 2.0  * (the "License"); you may not use this file except in compliance with  * the License.  You may obtain a copy of the License at  *  *     http://www.apache.org/licenses/LICENSE-2.0  *  * Unless required by applicable law or agreed to in writing, software  * distributed under the License is distributed on an "AS IS" BASIS,  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  * See the License for the specific language governing permissions and  * limitations under the License.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|APR_ENV_H
end_ifndef

begin_define
define|#
directive|define
name|APR_ENV_H
end_define

begin_comment
comment|/**  * @file apr_env.h  * @brief APR Environment functions  */
end_comment

begin_include
include|#
directive|include
file|"apr_errno.h"
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
comment|/* __cplusplus */
comment|/**  * @defgroup apr_env Functions for manipulating the environment  * @ingroup APR   * @{  */
comment|/**  * Get the value of an environment variable  * @param value the returned value, allocated from @a pool  * @param envvar the name of the environment variable  * @param pool where to allocate @a value and any temporary storage from  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_env_get
argument_list|(
name|char
operator|*
operator|*
name|value
argument_list|,
specifier|const
name|char
operator|*
name|envvar
argument_list|,
name|apr_pool_t
operator|*
name|pool
argument_list|)
expr_stmt|;
comment|/**  * Set the value of an environment variable  * @param envvar the name of the environment variable  * @param value the value to set  * @param pool where to allocate temporary storage from  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_env_set
argument_list|(
specifier|const
name|char
operator|*
name|envvar
argument_list|,
specifier|const
name|char
operator|*
name|value
argument_list|,
name|apr_pool_t
operator|*
name|pool
argument_list|)
expr_stmt|;
comment|/**  * Delete a variable from the environment  * @param envvar the name of the environment variable  * @param pool where to allocate temporary storage from  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_env_delete
argument_list|(
specifier|const
name|char
operator|*
name|envvar
argument_list|,
name|apr_pool_t
operator|*
name|pool
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
comment|/* ! APR_ENV_H */
end_comment

end_unit

