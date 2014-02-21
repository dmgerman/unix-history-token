begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  * @copyright  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  * @endcopyright  *  * @file svn_compat.h  * @brief Utilities to help applications provide backwards-compatibility  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_COMPAT_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_COMPAT_H
end_define

begin_include
include|#
directive|include
file|<apr_pools.h>
end_include

begin_include
include|#
directive|include
file|<apr_hash.h>
end_include

begin_include
include|#
directive|include
file|<apr_tables.h>
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
comment|/** Return, in @a *callback2 and @a *callback2_baton a function/baton that  * will call @a callback/@a callback_baton, allocating the @a *callback2_baton  * in @a pool.  *  * @note This is used by compatibility wrappers, which exist in more than  * Subversion core library.  *  * @since New in 1.4.  */
name|void
name|svn_compat_wrap_commit_callback
parameter_list|(
name|svn_commit_callback2_t
modifier|*
name|callback2
parameter_list|,
name|void
modifier|*
modifier|*
name|callback2_baton
parameter_list|,
name|svn_commit_callback_t
name|callback
parameter_list|,
name|void
modifier|*
name|callback_baton
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/** Clear svn:author, svn:date, and svn:log from @a revprops if not NULL.  * Use this if you must handle these three properties separately for  * compatibility reasons.  *  * @since New in 1.5.  */
name|void
name|svn_compat_log_revprops_clear
parameter_list|(
name|apr_hash_t
modifier|*
name|revprops
parameter_list|)
function_decl|;
comment|/** Return a list to pass to post-1.5 log-retrieval functions in order to  * retrieve the pre-1.5 set of revprops: svn:author, svn:date, and svn:log.  *  * @since New in 1.5.  */
name|apr_array_header_t
modifier|*
name|svn_compat_log_revprops_in
parameter_list|(
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/** Return, in @a **author, @a **date, and @a **message, the values of the  * svn:author, svn:date, and svn:log revprops from @a revprops.  If @a  * revprops is NULL, all return values are NULL.  Any return value may be  * NULL if the corresponding property is not set in @a revprops.  *  * @since New in 1.5.  */
name|void
name|svn_compat_log_revprops_out
parameter_list|(
specifier|const
name|char
modifier|*
modifier|*
name|author
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|date
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|message
parameter_list|,
name|apr_hash_t
modifier|*
name|revprops
parameter_list|)
function_decl|;
comment|/** Return, in @a *receiver2 and @a *receiver2_baton a function/baton that  * will call @a receiver/@a receiver_baton, allocating the @a *receiver2_baton  * in @a pool.  *  * @note This is used by compatibility wrappers, which exist in more than  * Subversion core library.  *  * @since New in 1.5.  */
name|void
name|svn_compat_wrap_log_receiver
parameter_list|(
name|svn_log_entry_receiver_t
modifier|*
name|receiver2
parameter_list|,
name|void
modifier|*
modifier|*
name|receiver2_baton
parameter_list|,
name|svn_log_message_receiver_t
name|receiver
parameter_list|,
name|void
modifier|*
name|receiver_baton
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
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
comment|/* SVN_COMPAT_H */
end_comment

end_unit

