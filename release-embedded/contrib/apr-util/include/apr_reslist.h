begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Licensed to the Apache Software Foundation (ASF) under one or more  * contributor license agreements.  See the NOTICE file distributed with  * this work for additional information regarding copyright ownership.  * The ASF licenses this file to You under the Apache License, Version 2.0  * (the "License"); you may not use this file except in compliance with  * the License.  You may obtain a copy of the License at  *  *     http://www.apache.org/licenses/LICENSE-2.0  *  * Unless required by applicable law or agreed to in writing, software  * distributed under the License is distributed on an "AS IS" BASIS,  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  * See the License for the specific language governing permissions and  * limitations under the License.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|APR_RESLIST_H
end_ifndef

begin_define
define|#
directive|define
name|APR_RESLIST_H
end_define

begin_comment
comment|/**   * @file apr_reslist.h  * @brief APR-UTIL Resource List Routines  */
end_comment

begin_include
include|#
directive|include
file|"apr.h"
end_include

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

begin_include
include|#
directive|include
file|"apr_errno.h"
end_include

begin_include
include|#
directive|include
file|"apr_time.h"
end_include

begin_comment
comment|/**  * @defgroup APR_Util_RL Resource List Routines  * @ingroup APR_Util  * @{  */
end_comment

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
comment|/** Opaque resource list object */
typedef|typedef
name|struct
name|apr_reslist_t
name|apr_reslist_t
typedef|;
comment|/* Generic constructor called by resource list when it needs to create a  * resource.  * @param resource opaque resource  * @param params flags  * @param pool  Pool  */
typedef|typedef
name|apr_status_t
function_decl|(
modifier|*
name|apr_reslist_constructor
function_decl|)
parameter_list|(
name|void
modifier|*
modifier|*
name|resource
parameter_list|,
name|void
modifier|*
name|params
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/* Generic destructor called by resource list when it needs to destroy a  * resource.  * @param resource opaque resource  * @param params flags  * @param pool  Pool  */
typedef|typedef
name|apr_status_t
function_decl|(
modifier|*
name|apr_reslist_destructor
function_decl|)
parameter_list|(
name|void
modifier|*
name|resource
parameter_list|,
name|void
modifier|*
name|params
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/* Cleanup order modes */
define|#
directive|define
name|APR_RESLIST_CLEANUP_DEFAULT
value|0
comment|/**< default pool cleanup */
define|#
directive|define
name|APR_RESLIST_CLEANUP_FIRST
value|1
comment|/**< use pool pre cleanup */
comment|/**  * Create a new resource list with the following parameters:  * @param reslist An address where the pointer to the new resource  *                list will be stored.  * @param min Allowed minimum number of available resources. Zero  *            creates new resources only when needed.  * @param smax Resources will be destroyed during reslist maintenance to  *             meet this maximum restriction as they expire (reach their ttl).  * @param hmax Absolute maximum limit on the number of total resources.  * @param ttl If non-zero, sets the maximum amount of time in microseconds an  *            unused resource is valid.  Any resource which has exceeded this  *            time will be destroyed, either when encountered by  *            apr_reslist_acquire() or during reslist maintenance.  * @param con Constructor routine that is called to create a new resource.  * @param de Destructor routine that is called to destroy an expired resource.  * @param params Passed to constructor and deconstructor  * @param pool The pool from which to create this resource list. Also the  *             same pool that is passed to the constructor and destructor  *             routines.  * @remark If APR has been compiled without thread support, hmax will be  *         automatically set to 1 and values of min and smax will be forced to  *         1 for any non-zero value.  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_reslist_create
argument_list|(
argument|apr_reslist_t **reslist
argument_list|,
argument|int min
argument_list|,
argument|int smax
argument_list|,
argument|int hmax
argument_list|,
argument|apr_interval_time_t ttl
argument_list|,
argument|apr_reslist_constructor con
argument_list|,
argument|apr_reslist_destructor de
argument_list|,
argument|void *params
argument_list|,
argument|apr_pool_t *pool
argument_list|)
empty_stmt|;
comment|/**  * Destroy the given resource list and all resources controlled by  * this list.  * FIXME: Should this block until all resources become available,  *        or maybe just destroy all the free ones, or maybe destroy  *        them even though they might be in use by something else?  *        Currently it will abort if there are resources that haven't  *        been released, so there is an assumption that all resources  *        have been released to the list before calling this function.  * @param reslist The reslist to destroy  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_reslist_destroy
argument_list|(
name|apr_reslist_t
operator|*
name|reslist
argument_list|)
expr_stmt|;
comment|/**  * Retrieve a resource from the list, creating a new one if necessary.  * If we have met our maximum number of resources, we will block  * until one becomes available.  * @param reslist The resource list.  * @param resource An address where the pointer to the resource  *                will be stored.  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_reslist_acquire
argument_list|(
name|apr_reslist_t
operator|*
name|reslist
argument_list|,
name|void
operator|*
operator|*
name|resource
argument_list|)
expr_stmt|;
comment|/**  * Return a resource back to the list of available resources.  * @param reslist The resource list.  * @param resource The resource to return to the list.  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_reslist_release
argument_list|(
name|apr_reslist_t
operator|*
name|reslist
argument_list|,
name|void
operator|*
name|resource
argument_list|)
expr_stmt|;
comment|/**  * Set the timeout the acquire will wait for a free resource  * when the maximum number of resources is exceeded.  * @param reslist The resource list.  * @param timeout Timeout to wait. The zero waits forever.  */
name|APU_DECLARE
argument_list|(
argument|void
argument_list|)
name|apr_reslist_timeout_set
argument_list|(
argument|apr_reslist_t *reslist
argument_list|,
argument|apr_interval_time_t timeout
argument_list|)
empty_stmt|;
comment|/**  * Return the number of outstanding resources.  * @param reslist The resource list.  */
name|APU_DECLARE
argument_list|(
argument|apr_uint32_t
argument_list|)
name|apr_reslist_acquired_count
argument_list|(
name|apr_reslist_t
operator|*
name|reslist
argument_list|)
expr_stmt|;
comment|/**  * Invalidate a resource in the pool - e.g. a database connection  * that returns a "lost connection" error and can't be restored.  * Use this instead of apr_reslist_release if the resource is bad.  * @param reslist The resource list.  * @param resource The resource to invalidate.  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_reslist_invalidate
argument_list|(
name|apr_reslist_t
operator|*
name|reslist
argument_list|,
name|void
operator|*
name|resource
argument_list|)
expr_stmt|;
comment|/**  * Perform routine maintenance on the resource list. This call  * may instantiate new resources or expire old resources.  * @param reslist The resource list.  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_reslist_maintain
argument_list|(
name|apr_reslist_t
operator|*
name|reslist
argument_list|)
expr_stmt|;
comment|/**  * Set reslist cleanup order.  * @param reslist The resource list.  * @param mode Cleanup order mode  *<PRE>  *           APR_RESLIST_CLEANUP_DEFAULT  default pool cleanup order  *           APR_RESLIST_CLEANUP_FIRST    use pool pre cleanup  *</PRE>  * @remark If APR_RESLIST_CLEANUP_FIRST is used the destructors will  * be called before child pools of the pool used to create the reslist  * are destroyed. This allows to explicitly destroy the child pools  * inside reslist destructors.  */
name|APU_DECLARE
argument_list|(
argument|void
argument_list|)
name|apr_reslist_cleanup_order_set
argument_list|(
argument|apr_reslist_t *reslist
argument_list|,
argument|apr_uint32_t mode
argument_list|)
empty_stmt|;
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
comment|/** @} */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! APR_RESLIST_H */
end_comment

end_unit

