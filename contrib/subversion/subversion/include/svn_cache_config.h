begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  * @copyright  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  * @endcopyright  *  * @file svn_cache_config.h  * @brief Configuration interface to internal Subversion caches.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_CACHE_CONFIG_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_CACHE_CONFIG_H
end_define

begin_include
include|#
directive|include
file|<apr.h>
end_include

begin_include
include|#
directive|include
file|"svn_types.h"
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
comment|/** @defgroup svn_fs_cache_config caching configuration  * @{  * @since New in 1.7. */
comment|/** Cache resource settings. It controls what caches, in what size and    how they will be created. The settings apply for the whole process.     @since New in 1.7.  */
typedef|typedef
struct|struct
name|svn_cache_config_t
block|{
comment|/** total cache size in bytes. Please note that this is only soft limit      to the total application memory usage and will be exceeded due to      temporary objects and other program state.      May be 0, resulting in default caching code being used. */
name|apr_uint64_t
name|cache_size
decl_stmt|;
comment|/** maximum number of files kept open */
name|apr_size_t
name|file_handle_count
decl_stmt|;
comment|/** is this application guaranteed to be single-threaded? */
name|svn_boolean_t
name|single_threaded
decl_stmt|;
block|}
name|svn_cache_config_t
typedef|;
comment|/** Get the current cache configuration. If it has not been set,    this function will return the default settings.     @since New in 1.7.  */
specifier|const
name|svn_cache_config_t
modifier|*
name|svn_cache_config_get
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/** Set the cache configuration. Please note that it may not change    the actual configuration *in use*. Therefore, call it before reading    data from any repo and call it only once.     This function is not thread-safe. Therefore, it should be called    from the processes' initialization code only.     @since New in 1.7.  */
name|void
name|svn_cache_config_set
parameter_list|(
specifier|const
name|svn_cache_config_t
modifier|*
name|settings
parameter_list|)
function_decl|;
comment|/** @} */
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

begin_comment
comment|/* __cplusplus */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SVN_CACHE_CONFIG_H */
end_comment

end_unit

