begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* nodes-table.h : interface to `nodes' table  *  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_LIBSVN_FS_NODES_TABLE_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_LIBSVN_FS_NODES_TABLE_H
end_define

begin_define
define|#
directive|define
name|SVN_WANT_BDB
end_define

begin_include
include|#
directive|include
file|"svn_private_config.h"
end_include

begin_include
include|#
directive|include
file|"svn_fs.h"
end_include

begin_include
include|#
directive|include
file|"../trail.h"
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
comment|/* Creating and opening the `nodes' table.  */
comment|/* Open a `nodes' table in ENV.  If CREATE is non-zero, create    one if it doesn't exist.  Set *NODES_P to the new table.    Return a Berkeley DB error code.  */
name|int
name|svn_fs_bdb__open_nodes_table
parameter_list|(
name|DB
modifier|*
modifier|*
name|nodes_p
parameter_list|,
name|DB_ENV
modifier|*
name|env
parameter_list|,
name|svn_boolean_t
name|create
parameter_list|)
function_decl|;
comment|/* Check FS's `nodes' table to find an unused node number, and set    *ID_P to the ID of the first revision of an entirely new node in    FS, with copy_id COPY_ID, created in transaction TXN_ID, as part    of TRAIL.  Allocate the new ID, and do all temporary allocation,    in POOL.  */
name|svn_error_t
modifier|*
name|svn_fs_bdb__new_node_id
parameter_list|(
name|svn_fs_id_t
modifier|*
modifier|*
name|id_p
parameter_list|,
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
specifier|const
name|char
modifier|*
name|copy_id
parameter_list|,
specifier|const
name|char
modifier|*
name|txn_id
parameter_list|,
name|trail_t
modifier|*
name|trail
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/* Delete node revision ID from FS's `nodes' table, as part of TRAIL.    WARNING: This does not check that the node revision is mutable!    Callers should do that check themselves.     todo: Jim and Karl are both not sure whether it would be better for    this to check mutability or not.  On the one hand, having the    lowest level do that check would seem intuitively good.  On the    other hand, we'll need a way to delete even immutable nodes someday    -- for example, someone accidentally commits NDA-protected data to    a public repository and wants to remove it.  Thoughts?  */
name|svn_error_t
modifier|*
name|svn_fs_bdb__delete_nodes_entry
parameter_list|(
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
specifier|const
name|svn_fs_id_t
modifier|*
name|id
parameter_list|,
name|trail_t
modifier|*
name|trail
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/* Set *SUCCESSOR_P to the ID of an immediate successor to node    revision ID in FS that does not exist yet, as part of TRAIL.    Allocate *SUCCESSOR_P in POOL.     Use the current Subversion transaction name TXN_ID, and optionally    a copy id COPY_ID, in the determination of the new node revision    ID.  */
name|svn_error_t
modifier|*
name|svn_fs_bdb__new_successor_id
parameter_list|(
name|svn_fs_id_t
modifier|*
modifier|*
name|successor_p
parameter_list|,
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
specifier|const
name|svn_fs_id_t
modifier|*
name|id
parameter_list|,
specifier|const
name|char
modifier|*
name|copy_id
parameter_list|,
specifier|const
name|char
modifier|*
name|txn_id
parameter_list|,
name|trail_t
modifier|*
name|trail
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/* Set *NODEREV_P to the node-revision for the node ID in FS, as    part of TRAIL.  Do any allocations in POOL.  Allow NODEREV_P    to be NULL, in which case it is not used, and this function acts as    an existence check for ID in FS. */
name|svn_error_t
modifier|*
name|svn_fs_bdb__get_node_revision
parameter_list|(
name|node_revision_t
modifier|*
modifier|*
name|noderev_p
parameter_list|,
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
specifier|const
name|svn_fs_id_t
modifier|*
name|id
parameter_list|,
name|trail_t
modifier|*
name|trail
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/* Store NODEREV as the node-revision for the node whose id    is ID in FS, as part of TRAIL.  Do any necessary temporary    allocation in POOL.     After this call, the node table manager assumes that NODE's    contents will change frequently.  */
name|svn_error_t
modifier|*
name|svn_fs_bdb__put_node_revision
parameter_list|(
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
specifier|const
name|svn_fs_id_t
modifier|*
name|id
parameter_list|,
name|node_revision_t
modifier|*
name|noderev
parameter_list|,
name|trail_t
modifier|*
name|trail
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
comment|/* SVN_LIBSVN_FS_NODES_TABLE_H */
end_comment

end_unit

