begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  * @copyright  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  * @endcopyright  *  * @file svn_named_atomics.h  * @brief Structures and functions for machine-wide named atomics.  *        These atomics store 64 bit signed integer values and provide  *        a number of basic operations on them. Instead of an address,  *        these atomics are identified by strings / names.  We also support  *        namespaces - mainly to separate debug from production data.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_NAMED_ATOMICS_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_NAMED_ATOMICS_H
end_define

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
comment|/** An opaque structure that represents a namespace, i.e. a container  * for named atomics.  */
typedef|typedef
name|struct
name|svn_atomic_namespace__t
name|svn_atomic_namespace__t
typedef|;
comment|/** An opaque structure that represents a named, system-wide visible  * 64 bit integer with atomic access routines.  */
typedef|typedef
name|struct
name|svn_named_atomic__t
name|svn_named_atomic__t
typedef|;
comment|/** Maximum length of the name of any atomic (excluding the terminal NUL).  */
define|#
directive|define
name|SVN_NAMED_ATOMIC__MAX_NAME_LENGTH
value|30
comment|/** Returns #FALSE when named atomics are not available to our process  * and svn_atomic_namespace__create is likely to fail.  *  * @note The actual check will be performed only once and later  * changes in process privileges will not reflect in the outcome of future  * calls to this function.  */
name|svn_boolean_t
name|svn_named_atomic__is_supported
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/** Returns #TRUE on platforms that don't need expensive synchronization  * objects to serialize access to named atomics. If this returns #FALSE,  * reading from or modifying a #svn_named_atomic__t may be as expensive  * as a file system operation.  */
name|svn_boolean_t
name|svn_named_atomic__is_efficient
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/** Create a namespace (i.e. access object) with the given @a name and  * return it in @a *ns.  *  * Multiple access objects with the same name may be created.  They access  * the same shared memory region but have independent lifetimes.  *  * The access object will be allocated in @a result_pool and atomics gotten  * from this object will become invalid when the pool is being cleared.  */
name|svn_error_t
modifier|*
name|svn_atomic_namespace__create
parameter_list|(
name|svn_atomic_namespace__t
modifier|*
modifier|*
name|ns
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|apr_pool_t
modifier|*
name|result_pool
parameter_list|)
function_decl|;
comment|/** Removes persistent data structures (files in particular) that got  * created for the namespace given by @a name.  Use @a pool for temporary  * allocations.  *  * @note You must not call this while the respective namespace is still  * in use. Calling this multiple times for the same namespace is safe.  */
name|svn_error_t
modifier|*
name|svn_atomic_namespace__cleanup
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/** Find the atomic with the specified @a name in namespace @a ns and  * return it in @a *atomic.  If no object with that name can be found, the  * behavior depends on @a auto_create.  If it is @c FALSE, @a *atomic will  * be set to @c NULL. Otherwise, a new atomic will be created, its value  * set to 0 and the access structure be returned in @a *atomic.  *  * Note that @a name must not exceed #SVN_NAMED_ATOMIC__MAX_NAME_LENGTH  * characters and an error will be returned if the specified name is longer  * than supported.  *  * @note The lifetime of the atomic object is bound to the lifetime  * of the @a ns object, i.e. the pool the latter was created in.  * The data in the namespace persists as long as at least one process  * holds an #svn_atomic_namespace__t object corresponding to it.  */
name|svn_error_t
modifier|*
name|svn_named_atomic__get
parameter_list|(
name|svn_named_atomic__t
modifier|*
modifier|*
name|atomic
parameter_list|,
name|svn_atomic_namespace__t
modifier|*
name|ns
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|svn_boolean_t
name|auto_create
parameter_list|)
function_decl|;
comment|/** Read the @a atomic and return its current @a *value.  * An error will be returned if @a atomic is @c NULL.  */
name|svn_error_t
modifier|*
name|svn_named_atomic__read
parameter_list|(
name|apr_int64_t
modifier|*
name|value
parameter_list|,
name|svn_named_atomic__t
modifier|*
name|atomic
parameter_list|)
function_decl|;
comment|/** Set the data in @a atomic to @a new_value and return its old content  * in @a *old_value.  @a old_value may be NULL.  *  * An error will be returned if @a atomic is @c NULL.  */
name|svn_error_t
modifier|*
name|svn_named_atomic__write
parameter_list|(
name|apr_int64_t
modifier|*
name|old_value
parameter_list|,
name|apr_int64_t
name|new_value
parameter_list|,
name|svn_named_atomic__t
modifier|*
name|atomic
parameter_list|)
function_decl|;
comment|/** Add @a delta to the data in @a atomic and return its new value in  * @a *new_value.  @a new_value may be null.  *  * An error will be returned if @a atomic is @c NULL.  */
name|svn_error_t
modifier|*
name|svn_named_atomic__add
parameter_list|(
name|apr_int64_t
modifier|*
name|new_value
parameter_list|,
name|apr_int64_t
name|delta
parameter_list|,
name|svn_named_atomic__t
modifier|*
name|atomic
parameter_list|)
function_decl|;
comment|/** If the current data in @a atomic equals @a comperand, set it to  * @a new_value.  Return the initial value in @a *old_value.  * @a old_value may be NULL.  *  * An error will be returned if @a atomic is @c NULL.  */
name|svn_error_t
modifier|*
name|svn_named_atomic__cmpxchg
parameter_list|(
name|apr_int64_t
modifier|*
name|old_value
parameter_list|,
name|apr_int64_t
name|new_value
parameter_list|,
name|apr_int64_t
name|comperand
parameter_list|,
name|svn_named_atomic__t
modifier|*
name|atomic
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
comment|/* SVN_NAMED_ATOMICS_H */
end_comment

end_unit

