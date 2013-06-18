begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* node-rev.h : interface to node revision retrieval and storage  *  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_LIBSVN_FS_NODE_REV_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_LIBSVN_FS_NODE_REV_H
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
file|"trail.h"
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
comment|/*** Functions. ***/
comment|/* Create an entirely new, mutable node in the filesystem FS, whose    NODE-REVISION is NODEREV, as part of TRAIL.  Set *ID_P to the new    node revision's ID.  Use POOL for any temporary allocation.     COPY_ID is the copy_id to use in the node revision ID returned in    *ID_P.     TXN_ID is the Subversion transaction under which this occurs.     After this call, the node table manager assumes that the new node's    contents will change frequently.  */
name|svn_error_t
modifier|*
name|svn_fs_base__create_node
parameter_list|(
specifier|const
name|svn_fs_id_t
modifier|*
modifier|*
name|id_p
parameter_list|,
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
name|node_revision_t
modifier|*
name|noderev
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
comment|/* Create a node revision in FS which is an immediate successor of    OLD_ID, whose contents are NEW_NR, as part of TRAIL.  Set *NEW_ID_P    to the new node revision's ID.  Use POOL for any temporary    allocation.     COPY_ID, if non-NULL, is a key into the `copies' table, and    indicates that this new node is being created as the result of a    copy operation, and specifically which operation that was.     TXN_ID is the Subversion transaction under which this occurs.     After this call, the deltification code assumes that the new node's    contents will change frequently, and will avoid representing other    nodes as deltas against this node's contents.  */
name|svn_error_t
modifier|*
name|svn_fs_base__create_successor
parameter_list|(
specifier|const
name|svn_fs_id_t
modifier|*
modifier|*
name|new_id_p
parameter_list|,
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
specifier|const
name|svn_fs_id_t
modifier|*
name|old_id
parameter_list|,
name|node_revision_t
modifier|*
name|new_nr
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
comment|/* Delete node revision ID from FS's `nodes' table, as part of TRAIL.    If ORIGIN_ALSO is set, also delete the record for this ID's node ID    from the `node-origins' index table (which is typically only done    if the caller thinks that ID points to the only node revision ID in    its line of history).     WARNING: This does not check that the node revision is mutable!    Callers should do that check themselves.  */
name|svn_error_t
modifier|*
name|svn_fs_base__delete_node_revision
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
name|svn_boolean_t
name|origin_also
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
comment|/* SVN_LIBSVN_FS_NODE_REV_H */
end_comment

end_unit

