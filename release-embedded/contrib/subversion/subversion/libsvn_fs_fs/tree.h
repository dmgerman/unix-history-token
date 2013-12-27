begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* tree.h : internal interface to tree node functions  *  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_LIBSVN_FS_TREE_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_LIBSVN_FS_TREE_H
end_define

begin_include
include|#
directive|include
file|"fs.h"
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
comment|/* In POOL, create an instance of a DAG node 1st level cache.    The POOL will be cleared at regular intervals. */
name|fs_fs_dag_cache_t
modifier|*
name|svn_fs_fs__create_dag_cache
parameter_list|(
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/* Set *ROOT_P to the root directory of revision REV in filesystem FS.    Allocate the structure in POOL. */
name|svn_error_t
modifier|*
name|svn_fs_fs__revision_root
parameter_list|(
name|svn_fs_root_t
modifier|*
modifier|*
name|root_p
parameter_list|,
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
name|svn_revnum_t
name|rev
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/* Does nothing, but included for Subversion 1.0.x compatibility. */
name|svn_error_t
modifier|*
name|svn_fs_fs__deltify
parameter_list|(
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
name|svn_revnum_t
name|rev
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/* Commit the transaction TXN as a new revision.  Return the new    revision in *NEW_REV.  If the transaction conflicts with other    changes return SVN_ERR_FS_CONFLICT and set *CONFLICT_P to a string    that details the cause of the conflict.  Perform temporary    allocations in POOL. */
name|svn_error_t
modifier|*
name|svn_fs_fs__commit_txn
parameter_list|(
specifier|const
name|char
modifier|*
modifier|*
name|conflict_p
parameter_list|,
name|svn_revnum_t
modifier|*
name|new_rev
parameter_list|,
name|svn_fs_txn_t
modifier|*
name|txn
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/* Set ROOT_P to the root directory of transaction TXN.  Allocate the    structure in POOL. */
name|svn_error_t
modifier|*
name|svn_fs_fs__txn_root
parameter_list|(
name|svn_fs_root_t
modifier|*
modifier|*
name|root_p
parameter_list|,
name|svn_fs_txn_t
modifier|*
name|txn
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/* Set KIND_P to the node kind of the node at PATH in ROOT.    Allocate the structure in POOL. */
name|svn_error_t
modifier|*
name|svn_fs_fs__check_path
parameter_list|(
name|svn_node_kind_t
modifier|*
name|kind_p
parameter_list|,
name|svn_fs_root_t
modifier|*
name|root
parameter_list|,
specifier|const
name|char
modifier|*
name|path
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/* Implement root_vtable_t.node_id(). */
name|svn_error_t
modifier|*
name|svn_fs_fs__node_id
parameter_list|(
specifier|const
name|svn_fs_id_t
modifier|*
modifier|*
name|id_p
parameter_list|,
name|svn_fs_root_t
modifier|*
name|root
parameter_list|,
specifier|const
name|char
modifier|*
name|path
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/* Set *REVISION to the revision in which PATH under ROOT was created.    Use POOL for any temporary allocations.  If PATH is in an    uncommitted transaction, *REVISION will be set to    SVN_INVALID_REVNUM. */
name|svn_error_t
modifier|*
name|svn_fs_fs__node_created_rev
parameter_list|(
name|svn_revnum_t
modifier|*
name|revision
parameter_list|,
name|svn_fs_root_t
modifier|*
name|root
parameter_list|,
specifier|const
name|char
modifier|*
name|path
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/* Verify metadata for ROOT.    ### Currently only implemented for revision roots. */
name|svn_error_t
modifier|*
name|svn_fs_fs__verify_root
parameter_list|(
name|svn_fs_root_t
modifier|*
name|root
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
comment|/* SVN_LIBSVN_FS_TREE_H */
end_comment

end_unit

