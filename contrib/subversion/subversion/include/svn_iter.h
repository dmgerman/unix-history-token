begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  * @copyright  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  * @endcopyright  *  * @file svn_iter.h  * @brief The Subversion Iteration drivers helper routines  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_ITER_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_ITER_H
end_define

begin_include
include|#
directive|include
file|<apr.h>
end_include

begin_comment
comment|/* for apr_ssize_t */
end_comment

begin_include
include|#
directive|include
file|<apr_pools.h>
end_include

begin_comment
comment|/* for apr_pool_t */
end_comment

begin_include
include|#
directive|include
file|<apr_hash.h>
end_include

begin_comment
comment|/* for apr_hash_t */
end_comment

begin_include
include|#
directive|include
file|<apr_tables.h>
end_include

begin_comment
comment|/* for apr_array_header_t */
end_comment

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
comment|/** Callback function for use with svn_iter_apr_hash().  * Use @a pool for temporary allocation, it's cleared between invocations.  *  * @a key, @a klen and @a val are the values normally retrieved with  * apr_hash_this().  *  * @a baton is the baton passed into svn_iter_apr_hash().  *  * @since New in 1.5.  */
typedef|typedef
name|svn_error_t
modifier|*
function_decl|(
modifier|*
name|svn_iter_apr_hash_cb_t
function_decl|)
parameter_list|(
name|void
modifier|*
name|baton
parameter_list|,
specifier|const
name|void
modifier|*
name|key
parameter_list|,
name|apr_ssize_t
name|klen
parameter_list|,
name|void
modifier|*
name|val
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/** Iterate over the elements in @a hash, calling @a func for each one until  * there are no more elements or @a func returns an error.  *  * Uses @a pool for temporary allocations.  *  * If @a completed is not NULL, then on return - if @a func returns no  * errors - @a *completed will be set to @c TRUE.  *  * If @a func returns an error other than @c SVN_ERR_ITER_BREAK, that  * error is returned.  When @a func returns @c SVN_ERR_ITER_BREAK,  * iteration is interrupted, but no error is returned and @a *completed is  * set to @c FALSE (even if this iteration was the last one).  *  * @since New in 1.5.  */
name|svn_error_t
modifier|*
name|svn_iter_apr_hash
parameter_list|(
name|svn_boolean_t
modifier|*
name|completed
parameter_list|,
name|apr_hash_t
modifier|*
name|hash
parameter_list|,
name|svn_iter_apr_hash_cb_t
name|func
parameter_list|,
name|void
modifier|*
name|baton
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/** Iteration callback used in conjuction with svn_iter_apr_array().  *  * Use @a pool for temporary allocation, it's cleared between invocations.  *  * @a baton is the baton passed to svn_iter_apr_array().  @a item  * is a pointer to the item written to the array with the APR_ARRAY_PUSH()  * macro.  *  * @since New in 1.5.  */
typedef|typedef
name|svn_error_t
modifier|*
function_decl|(
modifier|*
name|svn_iter_apr_array_cb_t
function_decl|)
parameter_list|(
name|void
modifier|*
name|baton
parameter_list|,
name|void
modifier|*
name|item
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/** Iterate over the elements in @a array calling @a func for each one until  * there are no more elements or @a func returns an error.  *  * Uses @a pool for temporary allocations.  *  * If @a completed is not NULL, then on return - if @a func returns no  * errors - @a *completed will be set to @c TRUE.  *  * If @a func returns an error other than @c SVN_ERR_ITER_BREAK, that  * error is returned.  When @a func returns @c SVN_ERR_ITER_BREAK,  * iteration is interrupted, but no error is returned and @a *completed is  * set to @c FALSE (even if this iteration was the last one).  *  * @since New in 1.5.  */
name|svn_error_t
modifier|*
name|svn_iter_apr_array
parameter_list|(
name|svn_boolean_t
modifier|*
name|completed
parameter_list|,
specifier|const
name|apr_array_header_t
modifier|*
name|array
parameter_list|,
name|svn_iter_apr_array_cb_t
name|func
parameter_list|,
name|void
modifier|*
name|baton
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/** Internal routine used by svn_iter_break() macro.  */
name|svn_error_t
modifier|*
name|svn_iter__break
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/** Helper macro to break looping in svn_iter_apr_array() and  * svn_iter_apr_hash() driven loops.  *  * @note The error is just a means of communicating between  *       driver and callback.  There is no need for it to exist  *       past the lifetime of the iterpool.  *  * @since New in 1.5.  */
define|#
directive|define
name|svn_iter_break
parameter_list|(
name|pool
parameter_list|)
value|return svn_iter__break()
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
comment|/* SVN_ITER_H */
end_comment

end_unit

