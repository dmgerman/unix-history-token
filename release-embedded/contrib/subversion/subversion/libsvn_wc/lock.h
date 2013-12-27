begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * lock.h:  routines for locking working copy subdirectories.  *  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  */
end_comment

begin_escape
end_escape

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_LIBSVN_WC_LOCK_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_LIBSVN_WC_LOCK_H
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
file|"svn_types.h"
end_include

begin_include
include|#
directive|include
file|"svn_error.h"
end_include

begin_include
include|#
directive|include
file|"svn_wc.h"
end_include

begin_include
include|#
directive|include
file|"wc_db.h"
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
comment|/*** General utilities that may get moved upstairs at some point. */
comment|/* Store ENTRIES in the cache in ADM_ACCESS.  ENTRIES may be NULL. */
name|void
name|svn_wc__adm_access_set_entries
parameter_list|(
name|svn_wc_adm_access_t
modifier|*
name|adm_access
parameter_list|,
name|apr_hash_t
modifier|*
name|entries
parameter_list|)
function_decl|;
comment|/* Return the entries hash cached in ADM_ACCESS.  The returned hash may    be NULL.  */
name|apr_hash_t
modifier|*
name|svn_wc__adm_access_entries
parameter_list|(
name|svn_wc_adm_access_t
modifier|*
name|adm_access
parameter_list|)
function_decl|;
comment|/* Same as svn_wc__adm_retrieve_internal, but takes a DB and an absolute    directory path.  */
name|svn_wc_adm_access_t
modifier|*
name|svn_wc__adm_retrieve_internal2
parameter_list|(
name|svn_wc__db_t
modifier|*
name|db
parameter_list|,
specifier|const
name|char
modifier|*
name|abspath
parameter_list|,
name|apr_pool_t
modifier|*
name|scratch_pool
parameter_list|)
function_decl|;
comment|/* ### this is probably bunk. but I dunna want to trace backwards-compat    ### users of svn_wc_check_wc(). probably gonna be rewritten for wc-ng    ### in any case.     If CHECK_PATH is TRUE, a not-existing directory is not a working copy */
name|svn_error_t
modifier|*
name|svn_wc__internal_check_wc
parameter_list|(
name|int
modifier|*
name|wc_format
parameter_list|,
name|svn_wc__db_t
modifier|*
name|db
parameter_list|,
specifier|const
name|char
modifier|*
name|local_abspath
parameter_list|,
name|svn_boolean_t
name|check_path
parameter_list|,
name|apr_pool_t
modifier|*
name|scratch_pool
parameter_list|)
function_decl|;
comment|/* Return the working copy database associated with this access baton. */
name|svn_wc__db_t
modifier|*
name|svn_wc__adm_get_db
parameter_list|(
specifier|const
name|svn_wc_adm_access_t
modifier|*
name|adm_access
parameter_list|)
function_decl|;
comment|/* Get a reference to the baton's internal ABSPATH.  */
specifier|const
name|char
modifier|*
name|svn_wc__adm_access_abspath
parameter_list|(
specifier|const
name|svn_wc_adm_access_t
modifier|*
name|adm_access
parameter_list|)
function_decl|;
comment|/* Return the pool used by access baton ADM_ACCESS.  * Note: This is a non-deprecated variant of svn_wc_adm_access_pool for  * libsvn_wc internal usage only.  */
name|apr_pool_t
modifier|*
name|svn_wc__adm_access_pool_internal
parameter_list|(
specifier|const
name|svn_wc_adm_access_t
modifier|*
name|adm_access
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
comment|/* SVN_LIBSVN_WC_LOCK_H */
end_comment

end_unit

