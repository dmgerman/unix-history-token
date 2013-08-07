begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * tree_conflicts.h: declarations related to tree conflicts  *  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_LIBSVN_WC_TREE_CONFLICTS_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_LIBSVN_WC_TREE_CONFLICTS_H
end_define

begin_include
include|#
directive|include
file|<apr_pools.h>
end_include

begin_include
include|#
directive|include
file|<apr_tables.h>
end_include

begin_include
include|#
directive|include
file|"svn_string.h"
end_include

begin_include
include|#
directive|include
file|"svn_wc.h"
end_include

begin_include
include|#
directive|include
file|"private/svn_token.h"
end_include

begin_include
include|#
directive|include
file|"private/svn_skel.h"
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
comment|/*  * See the notes/tree-conflicts/ directory for more information  * about tree conflicts in general.  *  * A given directory may contain potentially many tree conflicts.  * Each tree conflict is identified by the path of the file  * or directory (both a.k.a node) that it affects.  * We call this file or directory the "victim" of the tree conflict.  *  * For example, a file that is deleted by an update but locally  * modified by the user is a victim of a tree conflict.  *  * For now, tree conflict victims are always direct children of the  * directory in which the tree conflict is recorded.  * This may change once the way Subversion handles adm areas changes.  *  * If a directory has tree conflicts, the "tree-conflict-data" field  * in the entry for the directory contains one or more tree conflict  * descriptions stored using the "skel" format.  */
name|svn_error_t
modifier|*
name|svn_wc__serialize_conflict
parameter_list|(
name|svn_skel_t
modifier|*
modifier|*
name|skel
parameter_list|,
specifier|const
name|svn_wc_conflict_description2_t
modifier|*
name|conflict
parameter_list|,
name|apr_pool_t
modifier|*
name|result_pool
parameter_list|,
name|apr_pool_t
modifier|*
name|scratch_pool
parameter_list|)
function_decl|;
comment|/* Parse a newly allocated svn_wc_conflict_description2_t object from the  * provided SKEL. Return the result in *CONFLICT, allocated in RESULT_POOL.  * DIR_PATH is the path to the WC directory whose conflicts are being read.  * Use SCRATCH_POOL for temporary allocations.  */
name|svn_error_t
modifier|*
name|svn_wc__deserialize_conflict
parameter_list|(
specifier|const
name|svn_wc_conflict_description2_t
modifier|*
modifier|*
name|conflict
parameter_list|,
specifier|const
name|svn_skel_t
modifier|*
name|skel
parameter_list|,
specifier|const
name|char
modifier|*
name|dir_path
parameter_list|,
name|apr_pool_t
modifier|*
name|result_pool
parameter_list|,
name|apr_pool_t
modifier|*
name|scratch_pool
parameter_list|)
function_decl|;
comment|/* Token mapping tables.  */
specifier|extern
specifier|const
name|svn_token_map_t
name|svn_wc__operation_map
index|[]
decl_stmt|;
specifier|extern
specifier|const
name|svn_token_map_t
name|svn_wc__conflict_action_map
index|[]
decl_stmt|;
specifier|extern
specifier|const
name|svn_token_map_t
name|svn_wc__conflict_reason_map
index|[]
decl_stmt|;
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
comment|/* SVN_LIBSVN_WC_TREE_CONFLICTS_H */
end_comment

end_unit

