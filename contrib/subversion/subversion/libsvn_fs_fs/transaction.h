begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* transaction.h --- transaction-related functions of FSFS  *  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_LIBSVN_FS__TRANSACTION_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_LIBSVN_FS__TRANSACTION_H
end_define

begin_include
include|#
directive|include
file|"fs.h"
end_include

begin_comment
comment|/* Return the transaction ID of TXN.  */
end_comment

begin_function_decl
specifier|const
name|svn_fs_fs__id_part_t
modifier|*
name|svn_fs_fs__txn_get_id
parameter_list|(
name|svn_fs_txn_t
modifier|*
name|txn
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Store NODEREV as the node-revision for the node whose id is ID in    FS, after setting its is_fresh_txn_root to FRESH_TXN_ROOT.  Do any    necessary temporary allocation in POOL. */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_fs__put_node_revision
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
name|svn_boolean_t
name|fresh_txn_root
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Find the paths which were changed in transaction TXN_ID of    filesystem FS and store them in *CHANGED_PATHS_P.    Get any temporary allocations from POOL. */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_fs__txn_changes_fetch
parameter_list|(
name|apr_hash_t
modifier|*
modifier|*
name|changed_paths_p
parameter_list|,
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
specifier|const
name|svn_fs_fs__id_part_t
modifier|*
name|txn_id
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Find the paths which were changed in revision REV of filesystem FS    and store them in *CHANGED_PATHS_P.  Get any temporary allocations    from POOL. */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_fs__paths_changed
parameter_list|(
name|apr_hash_t
modifier|*
modifier|*
name|changed_paths_p
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
end_function_decl

begin_comment
comment|/* Create a new transaction in filesystem FS, based on revision REV,    and store it in *TXN_P.  Allocate all necessary variables from    POOL. */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_fs__create_txn
parameter_list|(
name|svn_fs_txn_t
modifier|*
modifier|*
name|txn_p
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
end_function_decl

begin_comment
comment|/* Set the transaction property NAME to the value VALUE in transaction    TXN.  Perform temporary allocations from POOL. */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_fs__change_txn_prop
parameter_list|(
name|svn_fs_txn_t
modifier|*
name|txn
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
specifier|const
name|svn_string_t
modifier|*
name|value
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Change transaction properties in transaction TXN based on PROPS.    Perform temporary allocations from POOL. */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_fs__change_txn_props
parameter_list|(
name|svn_fs_txn_t
modifier|*
name|txn
parameter_list|,
specifier|const
name|apr_array_header_t
modifier|*
name|props
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Store a transaction record in *TXN_P for the transaction identified    by TXN_ID in filesystem FS.  Allocate everything from POOL. */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_fs__get_txn
parameter_list|(
name|transaction_t
modifier|*
modifier|*
name|txn_p
parameter_list|,
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
specifier|const
name|svn_fs_fs__id_part_t
modifier|*
name|txn_id
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return the next available copy_id in *COPY_ID for the transaction    TXN_ID in filesystem FS.  Allocate space in POOL. */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_fs__reserve_copy_id
parameter_list|(
name|svn_fs_fs__id_part_t
modifier|*
name|copy_id_p
parameter_list|,
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
specifier|const
name|svn_fs_fs__id_part_t
modifier|*
name|txn_id
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Create an entirely new mutable node in the filesystem FS, whose    node-revision is NODEREV.  Set *ID_P to the new node revision's ID.    Use POOL for any temporary allocation.  COPY_ID is the copy_id to    use in the node revision ID.  TXN_ID is the Subversion transaction    under which this occurs. */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_fs__create_node
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
name|svn_fs_fs__id_part_t
modifier|*
name|copy_id
parameter_list|,
specifier|const
name|svn_fs_fs__id_part_t
modifier|*
name|txn_id
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Remove all references to the transaction TXN_ID from filesystem FS.    Temporary allocations are from POOL. */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_fs__purge_txn
parameter_list|(
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
specifier|const
name|char
modifier|*
name|txn_id
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Abort the existing transaction TXN, performing any temporary    allocations in POOL. */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_fs__abort_txn
parameter_list|(
name|svn_fs_txn_t
modifier|*
name|txn
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Add or set in filesystem FS, transaction TXN_ID, in directory    PARENT_NODEREV a directory entry for NAME pointing to ID of type    KIND.  Allocations are done in POOL. */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_fs__set_entry
parameter_list|(
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
specifier|const
name|svn_fs_fs__id_part_t
modifier|*
name|txn_id
parameter_list|,
name|node_revision_t
modifier|*
name|parent_noderev
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
specifier|const
name|svn_fs_id_t
modifier|*
name|id
parameter_list|,
name|svn_node_kind_t
name|kind
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Add a change to the changes record for filesystem FS in transaction    TXN_ID.  Mark path PATH, having node-id ID, as changed according to    the type in CHANGE_KIND.  If the text representation was changed set    TEXT_MOD to TRUE, and likewise for PROP_MOD as well as MERGEINFO_MOD.    If this change was the result of a copy, set COPYFROM_REV and    COPYFROM_PATH to the revision and path of the copy source, otherwise    they should be set to SVN_INVALID_REVNUM and NULL.  Perform any    temporary allocations from POOL. */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_fs__add_change
parameter_list|(
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
specifier|const
name|svn_fs_fs__id_part_t
modifier|*
name|txn_id
parameter_list|,
specifier|const
name|char
modifier|*
name|path
parameter_list|,
specifier|const
name|svn_fs_id_t
modifier|*
name|id
parameter_list|,
name|svn_fs_path_change_kind_t
name|change_kind
parameter_list|,
name|svn_boolean_t
name|text_mod
parameter_list|,
name|svn_boolean_t
name|prop_mod
parameter_list|,
name|svn_boolean_t
name|mergeinfo_mod
parameter_list|,
name|svn_node_kind_t
name|node_kind
parameter_list|,
name|svn_revnum_t
name|copyfrom_rev
parameter_list|,
specifier|const
name|char
modifier|*
name|copyfrom_path
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return a writable stream in *STREAM that allows storing the text    representation of node-revision NODEREV in filesystem FS.    Allocations are from POOL. */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_fs__set_contents
parameter_list|(
name|svn_stream_t
modifier|*
modifier|*
name|stream
parameter_list|,
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
name|node_revision_t
modifier|*
name|noderev
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Create a node revision in FS which is an immediate successor of    OLD_ID, whose contents are NEW_NR.  Set *NEW_ID_P to the new node    revision's ID.  Use POOL for any temporary allocation.     COPY_ID, if non-NULL, is a key into the `copies' table, and    indicates that this new node is being created as the result of a    copy operation, and specifically which operation that was.  If    COPY_ID is NULL, then re-use the copy ID from the predecessor node.     TXN_ID is the Subversion transaction under which this occurs.     After this call, the deltification code assumes that the new node's    contents will change frequently, and will avoid representing other    nodes as deltas against this node's contents.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_fs__create_successor
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
name|old_idp
parameter_list|,
name|node_revision_t
modifier|*
name|new_noderev
parameter_list|,
specifier|const
name|svn_fs_fs__id_part_t
modifier|*
name|copy_id
parameter_list|,
specifier|const
name|svn_fs_fs__id_part_t
modifier|*
name|txn_id
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Write a new property list PROPLIST for node-revision NODEREV in    filesystem FS.  Perform any temporary allocations in POOL. */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_fs__set_proplist
parameter_list|(
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
name|node_revision_t
modifier|*
name|noderev
parameter_list|,
name|apr_hash_t
modifier|*
name|proplist
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Append the L2P and P2L indexes given by their proto index file names  * L2P_PROTO_INDEX and P2L_PROTO_INDEX to the revision / pack FILE.  * The latter contains revision(s) starting at REVISION in FS.  * Use POOL for temporary allocations.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_fs__add_index_data
parameter_list|(
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
name|apr_file_t
modifier|*
name|file
parameter_list|,
specifier|const
name|char
modifier|*
name|l2p_proto_index
parameter_list|,
specifier|const
name|char
modifier|*
name|p2l_proto_index
parameter_list|,
name|svn_revnum_t
name|revision
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Commit the transaction TXN in filesystem FS and return its new    revision number in *REV.  If the transaction is out of date, return    the error SVN_ERR_FS_TXN_OUT_OF_DATE. Use POOL for temporary    allocations. */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_fs__commit
parameter_list|(
name|svn_revnum_t
modifier|*
name|new_rev_p
parameter_list|,
name|svn_fs_t
modifier|*
name|fs
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
end_function_decl

begin_comment
comment|/* Set *NAMES_P to an array of names which are all the active    transactions in filesystem FS.  Allocate the array from POOL. */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_fs__list_transactions
parameter_list|(
name|apr_array_header_t
modifier|*
modifier|*
name|names_p
parameter_list|,
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Open the transaction named NAME in filesystem FS.  Set *TXN_P to  * the transaction. If there is no such transaction, return ` * SVN_ERR_FS_NO_SUCH_TRANSACTION.  Allocate the new transaction in  * POOL. */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_fs__open_txn
parameter_list|(
name|svn_fs_txn_t
modifier|*
modifier|*
name|txn_p
parameter_list|,
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
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
end_function_decl

begin_comment
comment|/* Return the property list from transaction TXN and store it in    *PROPLIST.  Allocate the property list from POOL. */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_fs__txn_proplist
parameter_list|(
name|apr_hash_t
modifier|*
modifier|*
name|table_p
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
end_function_decl

begin_comment
comment|/* Delete the mutable node-revision referenced by ID, along with any    mutable props or directory contents associated with it.  Perform    temporary allocations in POOL. */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_fs__delete_node_revision
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
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Retrieve information about the Subversion transaction SVN_TXN from    the `transactions' table of FS, allocating from POOL.  Set    *ROOT_ID_P to the ID of the transaction's root directory.  Set    *BASE_ROOT_ID_P to the ID of the root directory of the    transaction's base revision.     If there is no such transaction, SVN_ERR_FS_NO_SUCH_TRANSACTION is    the error returned.     Returns SVN_ERR_FS_TRANSACTION_NOT_MUTABLE if TXN_NAME refers to a    transaction that has already been committed.     Allocate *ROOT_ID_P and *BASE_ROOT_ID_P in POOL.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_fs__get_txn_ids
parameter_list|(
specifier|const
name|svn_fs_id_t
modifier|*
modifier|*
name|root_id_p
parameter_list|,
specifier|const
name|svn_fs_id_t
modifier|*
modifier|*
name|base_root_id_p
parameter_list|,
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
specifier|const
name|svn_fs_fs__id_part_t
modifier|*
name|txn_name
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Find the value of the property named PROPNAME in transaction TXN.    Return the contents in *VALUE_P.  The contents will be allocated    from POOL. */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_fs__txn_prop
parameter_list|(
name|svn_string_t
modifier|*
modifier|*
name|value_p
parameter_list|,
name|svn_fs_txn_t
modifier|*
name|txn
parameter_list|,
specifier|const
name|char
modifier|*
name|propname
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Begin a new transaction in filesystem FS, based on existing    revision REV.  The new transaction is returned in *TXN_P.  Allocate    the new transaction structure from POOL. */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_fs__begin_txn
parameter_list|(
name|svn_fs_txn_t
modifier|*
modifier|*
name|txn_p
parameter_list|,
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
name|svn_revnum_t
name|rev
parameter_list|,
name|apr_uint32_t
name|flags
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

