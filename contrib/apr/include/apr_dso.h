begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Licensed to the Apache Software Foundation (ASF) under one or more  * contributor license agreements.  See the NOTICE file distributed with  * this work for additional information regarding copyright ownership.  * The ASF licenses this file to You under the Apache License, Version 2.0  * (the "License"); you may not use this file except in compliance with  * the License.  You may obtain a copy of the License at  *  *     http://www.apache.org/licenses/LICENSE-2.0  *  * Unless required by applicable law or agreed to in writing, software  * distributed under the License is distributed on an "AS IS" BASIS,  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  * See the License for the specific language governing permissions and  * limitations under the License.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|APR_DSO_DOT_H
end_ifndef

begin_define
define|#
directive|define
name|APR_DSO_DOT_H
end_define

begin_comment
comment|/**  * @file apr_dso.h  * @brief APR Dynamic Object Handling Routines  */
end_comment

begin_include
include|#
directive|include
file|"apr.h"
end_include

begin_include
include|#
directive|include
file|"apr_pools.h"
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
comment|/**  * @defgroup apr_dso Dynamic Object Handling  * @ingroup APR   * @{  */
if|#
directive|if
name|APR_HAS_DSO
operator|||
name|defined
argument_list|(
name|DOXYGEN
argument_list|)
comment|/**  * Structure for referencing dynamic objects  */
typedef|typedef
name|struct
name|apr_dso_handle_t
name|apr_dso_handle_t
typedef|;
comment|/**  * Structure for referencing symbols from dynamic objects  */
typedef|typedef
name|void
modifier|*
name|apr_dso_handle_sym_t
typedef|;
comment|/**  * Load a DSO library.  * @param res_handle Location to store new handle for the DSO.  * @param path Path to the DSO library  * @param ctx Pool to use.  * @bug We aught to provide an alternative to RTLD_GLOBAL, which  * is the only supported method of loading DSOs today.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_dso_load
argument_list|(
name|apr_dso_handle_t
operator|*
operator|*
name|res_handle
argument_list|,
specifier|const
name|char
operator|*
name|path
argument_list|,
name|apr_pool_t
operator|*
name|ctx
argument_list|)
expr_stmt|;
comment|/**  * Close a DSO library.  * @param handle handle to close.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_dso_unload
argument_list|(
name|apr_dso_handle_t
operator|*
name|handle
argument_list|)
expr_stmt|;
comment|/**  * Load a symbol from a DSO handle.  * @param ressym Location to store the loaded symbol  * @param handle handle to load the symbol from.  * @param symname Name of the symbol to load.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_dso_sym
argument_list|(
name|apr_dso_handle_sym_t
operator|*
name|ressym
argument_list|,
name|apr_dso_handle_t
operator|*
name|handle
argument_list|,
specifier|const
name|char
operator|*
name|symname
argument_list|)
expr_stmt|;
comment|/**  * Report more information when a DSO function fails.  * @param dso The dso handle that has been opened  * @param buf Location to store the dso error  * @param bufsize The size of the provided buffer  */
name|APR_DECLARE
argument_list|(
argument|const char *
argument_list|)
name|apr_dso_error
argument_list|(
argument|apr_dso_handle_t *dso
argument_list|,
argument|char *buf
argument_list|,
argument|apr_size_t bufsize
argument_list|)
empty_stmt|;
endif|#
directive|endif
comment|/* APR_HAS_DSO */
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

end_unit

