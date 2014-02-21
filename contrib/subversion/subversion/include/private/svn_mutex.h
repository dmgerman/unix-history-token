begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  * @copyright  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  * @endcopyright  *  * @file svn_mutex.h  * @brief Structures and functions for mutual exclusion  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_MUTEX_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_MUTEX_H
end_define

begin_include
include|#
directive|include
file|<apr_thread_mutex.h>
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
comment|/**  * This is a simple wrapper around @c apr_thread_mutex_t and will be a  * valid identifier even if APR does not support threading.  */
if|#
directive|if
name|APR_HAS_THREADS
comment|/** A mutex for synchronization between threads. It may be NULL, in  * which case no synchronization will take place. The latter is useful  * when implementing some functionality with optional synchronization.  */
typedef|typedef
name|apr_thread_mutex_t
name|svn_mutex__t
typedef|;
else|#
directive|else
comment|/** Dummy definition. The content will never be actually accessed.  */
typedef|typedef
name|void
name|svn_mutex__t
typedef|;
endif|#
directive|endif
comment|/** Initialize the @a *mutex. If @a mutex_required is TRUE, the mutex will  * actually be created with a lifetime defined by @a result_pool. Otherwise,  * the pointer will be set to @c NULL and svn_mutex__lock() as well as  * svn_mutex__unlock() will be no-ops.  *  * If threading is not supported by APR, this function is a no-op.  */
name|svn_error_t
modifier|*
name|svn_mutex__init
parameter_list|(
name|svn_mutex__t
modifier|*
modifier|*
name|mutex
parameter_list|,
name|svn_boolean_t
name|mutex_required
parameter_list|,
name|apr_pool_t
modifier|*
name|result_pool
parameter_list|)
function_decl|;
comment|/** Acquire the @a mutex, if that has been enabled in svn_mutex__init().  * Make sure to call svn_mutex__unlock() some time later in the same  * thread to release the mutex again. Recursive locking are not supported.  *  * @note You should use #SVN_MUTEX__WITH_LOCK instead of explicit lock  * acquisition and release.  */
name|svn_error_t
modifier|*
name|svn_mutex__lock
parameter_list|(
name|svn_mutex__t
modifier|*
name|mutex
parameter_list|)
function_decl|;
comment|/** Release the @a mutex, previously acquired using svn_mutex__lock()  * that has been enabled in svn_mutex__init().  *  * Since this is often used as part of the calling function's exit  * sequence, we accept that function's current return code in @a err.  * If it is not #SVN_NO_ERROR, it will be used as the return value -  * irrespective of the possible internal failures during unlock. If @a err  * is #SVN_NO_ERROR, internal failures of this function will be  * reported in the return value.  *  * @note You should use #SVN_MUTEX__WITH_LOCK instead of explicit lock  * acquisition and release.  */
name|svn_error_t
modifier|*
name|svn_mutex__unlock
parameter_list|(
name|svn_mutex__t
modifier|*
name|mutex
parameter_list|,
name|svn_error_t
modifier|*
name|err
parameter_list|)
function_decl|;
comment|/** Acquires the @a mutex, executes the expression @a expr and finally  * releases the @a mutex. If any of these steps fail, the function using  * this macro will return an #svn_error_t. This macro guarantees that  * the @a mutex will always be unlocked again if it got locked successfully  * by the first step.  *  * @note Prefer using this macro instead of explicit lock acquisition and  * release.  */
define|#
directive|define
name|SVN_MUTEX__WITH_LOCK
parameter_list|(
name|mutex
parameter_list|,
name|expr
parameter_list|)
define|\
value|do {                                                    \   svn_mutex__t *svn_mutex__m = (mutex);                 \   SVN_ERR(svn_mutex__lock(svn_mutex__m));               \   SVN_ERR(svn_mutex__unlock(svn_mutex__m, (expr)));     \ } while (0)
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
comment|/* SVN_MUTEX_H */
end_comment

end_unit

