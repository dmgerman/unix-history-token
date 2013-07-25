begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * blncache.h: DAV baseline information cache.  *  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_LIBSVN_RA_SERF_BLNCACHE_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_LIBSVN_RA_SERF_BLNCACHE_H
end_define

begin_include
include|#
directive|include
file|<apr_pools.h>
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
comment|/* Baseline information cache. Baseline information cache holds information  * about DAV baseline (bln):  * 1. URL of the baseline (bln)  * 2. Revision number associated with baseline  * 3. URL of baseline collection (bc).  */
typedef|typedef
name|struct
name|svn_ra_serf__blncache_t
name|svn_ra_serf__blncache_t
typedef|;
comment|/* Creates new instance of baseline cache. Sets BLNCACHE_P with  * a pointer to new instance, allocated in POOL.  */
name|svn_error_t
modifier|*
name|svn_ra_serf__blncache_create
parameter_list|(
name|svn_ra_serf__blncache_t
modifier|*
modifier|*
name|blncache_p
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/* Add information about baseline. BLNCACHE is a pointer to  * baseline cache previously created using svn_ra_serf__blncache_create  * function. BASELINE_URL is URL of baseline (can be NULL if unknown).  * REVNUM is revision number associated with baseline. Use SVN_INVALID_REVNUM  * to indicate that revision is unknown.  * BC_URL is URL of baseline collection (can be NULL if unknwon).  */
name|svn_error_t
modifier|*
name|svn_ra_serf__blncache_set
parameter_list|(
name|svn_ra_serf__blncache_t
modifier|*
name|blncache
parameter_list|,
specifier|const
name|char
modifier|*
name|baseline_url
parameter_list|,
name|svn_revnum_t
name|revnum
parameter_list|,
specifier|const
name|char
modifier|*
name|bc_url
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/* Sets *BC_URL_P with a pointer to baseline collection URL for the given  * REVNUM. *BC_URL_P will be NULL if cache doesn't have information about  * this baseline.  */
name|svn_error_t
modifier|*
name|svn_ra_serf__blncache_get_bc_url
parameter_list|(
specifier|const
name|char
modifier|*
modifier|*
name|bc_url_p
parameter_list|,
name|svn_ra_serf__blncache_t
modifier|*
name|blncache
parameter_list|,
name|svn_revnum_t
name|revnum
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/* Sets *BC_URL_P with pointer to baseline collection URL and *REVISION_P  * with revision number of baseline BASELINE_URL. *BC_URL_P will be NULL,  * *REVNUM_P will SVN_INVALID_REVNUM if cache doesn't have such  * information.  */
name|svn_error_t
modifier|*
name|svn_ra_serf__blncache_get_baseline_info
parameter_list|(
specifier|const
name|char
modifier|*
modifier|*
name|bc_url_p
parameter_list|,
name|svn_revnum_t
modifier|*
name|revnum_p
parameter_list|,
name|svn_ra_serf__blncache_t
modifier|*
name|blncache
parameter_list|,
specifier|const
name|char
modifier|*
name|baseline_url
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
comment|/* SVN_LIBSVN_RA_SERF_BLNCACHE_H*/
end_comment

end_unit

