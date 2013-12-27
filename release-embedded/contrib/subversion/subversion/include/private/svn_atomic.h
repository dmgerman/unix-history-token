begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  * @copyright  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  * @endcopyright  *  * @file svn_atomic.h  * @brief Macros and functions for atomic operations  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_ATOMIC_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_ATOMIC_H
end_define

begin_include
include|#
directive|include
file|<apr_version.h>
end_include

begin_include
include|#
directive|include
file|<apr_atomic.h>
end_include

begin_include
include|#
directive|include
file|"svn_error.h"
end_include

begin_include
include|#
directive|include
file|"private/svn_dep_compat.h"
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
comment|/**  * @name Macro definitions for atomic types and operations  *  * @note These are necessary because the apr_atomic API changed somewhat  *       between apr-0.x and apr-1.x.  * @{  */
comment|/** The type used by all the other atomic operations. */
if|#
directive|if
name|APR_VERSION_AT_LEAST
argument_list|(
literal|1
operator|,
literal|0
operator|,
literal|0
argument_list|)
define|#
directive|define
name|svn_atomic_t
value|apr_uint32_t
else|#
directive|else
define|#
directive|define
name|svn_atomic_t
value|apr_atomic_t
endif|#
directive|endif
comment|/** Atomically read an #svn_atomic_t from memory. */
if|#
directive|if
name|APR_VERSION_AT_LEAST
argument_list|(
literal|1
operator|,
literal|0
operator|,
literal|0
argument_list|)
define|#
directive|define
name|svn_atomic_read
parameter_list|(
name|mem
parameter_list|)
value|apr_atomic_read32((mem))
else|#
directive|else
define|#
directive|define
name|svn_atomic_read
parameter_list|(
name|mem
parameter_list|)
value|apr_atomic_read((mem))
endif|#
directive|endif
comment|/** Atomically set an #svn_atomic_t in memory. */
if|#
directive|if
name|APR_VERSION_AT_LEAST
argument_list|(
literal|1
operator|,
literal|0
operator|,
literal|0
argument_list|)
define|#
directive|define
name|svn_atomic_set
parameter_list|(
name|mem
parameter_list|,
name|val
parameter_list|)
value|apr_atomic_set32((mem), (val))
else|#
directive|else
define|#
directive|define
name|svn_atomic_set
parameter_list|(
name|mem
parameter_list|,
name|val
parameter_list|)
value|apr_atomic_set((mem), (val))
endif|#
directive|endif
comment|/** Atomically increment an #svn_atomic_t. */
if|#
directive|if
name|APR_VERSION_AT_LEAST
argument_list|(
literal|1
operator|,
literal|0
operator|,
literal|0
argument_list|)
define|#
directive|define
name|svn_atomic_inc
parameter_list|(
name|mem
parameter_list|)
value|apr_atomic_inc32(mem)
else|#
directive|else
define|#
directive|define
name|svn_atomic_inc
parameter_list|(
name|mem
parameter_list|)
value|apr_atomic_inc(mem)
endif|#
directive|endif
comment|/** Atomically decrement an #svn_atomic_t. */
if|#
directive|if
name|APR_VERSION_AT_LEAST
argument_list|(
literal|1
operator|,
literal|0
operator|,
literal|0
argument_list|)
define|#
directive|define
name|svn_atomic_dec
parameter_list|(
name|mem
parameter_list|)
value|apr_atomic_dec32(mem)
else|#
directive|else
define|#
directive|define
name|svn_atomic_dec
parameter_list|(
name|mem
parameter_list|)
value|apr_atomic_dec(mem)
endif|#
directive|endif
comment|/**  * Atomic compare-and-swap.  *  * Compare the value that @a mem points to with @a cmp. If they are  * the same swap the value with @a with.  *  * @note svn_atomic_cas should not be combined with the other  *       svn_atomic operations.  A comment in apr_atomic.h explains  *       that on some platforms, the CAS function is implemented in a  *       way that is incompatible with the other atomic operations.  */
if|#
directive|if
name|APR_VERSION_AT_LEAST
argument_list|(
literal|1
operator|,
literal|0
operator|,
literal|0
argument_list|)
define|#
directive|define
name|svn_atomic_cas
parameter_list|(
name|mem
parameter_list|,
name|with
parameter_list|,
name|cmp
parameter_list|)
define|\
value|apr_atomic_cas32((mem), (with), (cmp))
else|#
directive|else
define|#
directive|define
name|svn_atomic_cas
parameter_list|(
name|mem
parameter_list|,
name|with
parameter_list|,
name|cmp
parameter_list|)
define|\
value|apr_atomic_cas((mem), (with), (cmp))
endif|#
directive|endif
comment|/** @} */
comment|/**  * Call an initialization function in a thread-safe manner.  *  * @a global_status must be a pointer to a global, zero-initialized  * #svn_atomic_t. @a init_func is a pointer to the function that performs  * the actual initialization. @a baton and and @a pool are passed on to the  * init_func for its use.  *  * @since New in 1.5.  */
name|svn_error_t
modifier|*
name|svn_atomic__init_once
parameter_list|(
specifier|volatile
name|svn_atomic_t
modifier|*
name|global_status
parameter_list|,
name|svn_error_t
modifier|*
function_decl|(
modifier|*
name|init_func
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|apr_pool_t
modifier|*
parameter_list|)
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
comment|/* SVN_ATOMIC_H */
end_comment

end_unit

