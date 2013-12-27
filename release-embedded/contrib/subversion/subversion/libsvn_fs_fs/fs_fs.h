begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* fs_fs.h : interface to the native filesystem layer  *  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_LIBSVN_FS__FS_FS_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_LIBSVN_FS__FS_FS_H
end_define

begin_include
include|#
directive|include
file|"fs.h"
end_include

begin_comment
comment|/* Open the fsfs filesystem pointed to by PATH and associate it with    filesystem object FS.  Use POOL for temporary allocations.     ### Some parts of *FS must have been initialized beforehand; some parts        (including FS->path) are initialized by this function. */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_fs__open
parameter_list|(
name|svn_fs_t
modifier|*
name|fs
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
end_function_decl

begin_comment
comment|/* Upgrade the fsfs filesystem FS.  Use POOL for temporary allocations. */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_fs__upgrade
parameter_list|(
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
comment|/* Verify metadata in fsfs filesystem FS.  Limit the checks to revisions  * START to END where possible.  Indicate progress via the optional  * NOTIFY_FUNC callback using NOTIFY_BATON.  The optional CANCEL_FUNC  * will periodically be called with CANCEL_BATON to allow for preemption.  * Use POOL for temporary allocations. */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_fs__verify
parameter_list|(
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
name|svn_revnum_t
name|start
parameter_list|,
name|svn_revnum_t
name|end
parameter_list|,
name|svn_fs_progress_notify_func_t
name|notify_func
parameter_list|,
name|void
modifier|*
name|notify_baton
parameter_list|,
name|svn_cancel_func_t
name|cancel_func
parameter_list|,
name|void
modifier|*
name|cancel_baton
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Copy the fsfs filesystem SRC_FS at SRC_PATH into a new copy DST_FS at  * DST_PATH. If INCREMENTAL is TRUE, do not re-copy data which already  * exists in DST_FS. Use POOL for temporary allocations. */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_fs__hotcopy
parameter_list|(
name|svn_fs_t
modifier|*
name|src_fs
parameter_list|,
name|svn_fs_t
modifier|*
name|dst_fs
parameter_list|,
specifier|const
name|char
modifier|*
name|src_path
parameter_list|,
specifier|const
name|char
modifier|*
name|dst_path
parameter_list|,
name|svn_boolean_t
name|incremental
parameter_list|,
name|svn_cancel_func_t
name|cancel_func
parameter_list|,
name|void
modifier|*
name|cancel_baton
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Recover the fsfs associated with filesystem FS.    Use optional CANCEL_FUNC/CANCEL_BATON for cancellation support.    Use POOL for temporary allocations. */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_fs__recover
parameter_list|(
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
name|svn_cancel_func_t
name|cancel_func
parameter_list|,
name|void
modifier|*
name|cancel_baton
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Set *NODEREV_P to the node-revision for the node ID in FS.  Do any    allocations in POOL. */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_fs__get_node_revision
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
name|apr_pool_t
modifier|*
name|pool
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
comment|/* Write the node-revision NODEREV into the stream OUTFILE, compatible with    filesystem format FORMAT.  Only write mergeinfo-related metadata if    INCLUDE_MERGEINFO is true.  Temporary allocations are from POOL. */
end_comment

begin_comment
comment|/* ### Currently used only by fs_fs.c */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_fs__write_noderev
parameter_list|(
name|svn_stream_t
modifier|*
name|outfile
parameter_list|,
name|node_revision_t
modifier|*
name|noderev
parameter_list|,
name|int
name|format
parameter_list|,
name|svn_boolean_t
name|include_mergeinfo
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Read a node-revision from STREAM. Set *NODEREV to the new structure,    allocated in POOL. */
end_comment

begin_comment
comment|/* ### Currently used only by fs_fs.c */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_fs__read_noderev
parameter_list|(
name|node_revision_t
modifier|*
modifier|*
name|noderev
parameter_list|,
name|svn_stream_t
modifier|*
name|stream
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Set *YOUNGEST to the youngest revision in filesystem FS.  Do any    temporary allocation in POOL. */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_fs__youngest_rev
parameter_list|(
name|svn_revnum_t
modifier|*
name|youngest
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
comment|/* Return an error iff REV does not exist in FS. */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_fs__revision_exists
parameter_list|(
name|svn_revnum_t
name|rev
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
comment|/* Set *ROOT_ID to the node-id for the root of revision REV in    filesystem FS.  Do any allocations in POOL. */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_fs__rev_get_root
parameter_list|(
name|svn_fs_id_t
modifier|*
modifier|*
name|root_id
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
comment|/* Set *ENTRIES to an apr_hash_t of dirent structs that contain the    directory entries of node-revision NODEREV in filesystem FS.  The    returned table (and its keys and values) is allocated in POOL,    which is also used for temporary allocations. */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_fs__rep_contents_dir
parameter_list|(
name|apr_hash_t
modifier|*
modifier|*
name|entries
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
comment|/* Set *DIRENT to the entry identified by NAME in the directory given    by NODEREV in filesystem FS.  If no such entry exits, *DIRENT will    be NULL. The returned object is allocated in RESULT_POOL; SCRATCH_POOL    used for temporary allocations. */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_fs__rep_contents_dir_entry
parameter_list|(
name|svn_fs_dirent_t
modifier|*
modifier|*
name|dirent
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
name|name
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
end_function_decl

begin_comment
comment|/* Set *CONTENTS to be a readable svn_stream_t that receives the text    representation of node-revision NODEREV as seen in filesystem FS.    Use POOL for temporary allocations. */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_fs__get_contents
parameter_list|(
name|svn_stream_t
modifier|*
modifier|*
name|contents
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
comment|/* Attempt to fetch the text representation of node-revision NODEREV as    seen in filesystem FS and pass it along with the BATON to the PROCESSOR.    Set *SUCCESS only of the data could be provided and the processing    had been called.    Use POOL for all allocations.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_fs__try_process_file_contents
parameter_list|(
name|svn_boolean_t
modifier|*
name|success
parameter_list|,
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
name|node_revision_t
modifier|*
name|noderev
parameter_list|,
name|svn_fs_process_contents_func_t
name|processor
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
end_function_decl

begin_comment
comment|/* Set *STREAM_P to a delta stream turning the contents of the file SOURCE into    the contents of the file TARGET, allocated in POOL.    If SOURCE is null, the empty string will be used. */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_fs__get_file_delta_stream
parameter_list|(
name|svn_txdelta_stream_t
modifier|*
modifier|*
name|stream_p
parameter_list|,
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
name|node_revision_t
modifier|*
name|source
parameter_list|,
name|node_revision_t
modifier|*
name|target
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Set *PROPLIST to be an apr_hash_t containing the property list of    node-revision NODEREV as seen in filesystem FS.  Use POOL for    temporary allocations. */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_fs__get_proplist
parameter_list|(
name|apr_hash_t
modifier|*
modifier|*
name|proplist
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
comment|/* Set *PROPLIST to be an apr_hash_t containing the property list of    revision REV as seen in filesystem FS.  Use POOL for temporary    allocations. */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_fs__revision_proplist
parameter_list|(
name|apr_hash_t
modifier|*
modifier|*
name|proplist
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
comment|/* Set *LENGTH to the be fulltext length of the node revision    specified by NODEREV.  Use POOL for temporary allocations. */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_fs__file_length
parameter_list|(
name|svn_filesize_t
modifier|*
name|length
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
comment|/* Return TRUE if the representation keys in A and B both point to the    same representation, else return FALSE. */
end_comment

begin_function_decl
name|svn_boolean_t
name|svn_fs_fs__noderev_same_rep_key
parameter_list|(
name|representation_t
modifier|*
name|a
parameter_list|,
name|representation_t
modifier|*
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return a copy of the representation REP allocated from POOL. */
end_comment

begin_function_decl
name|representation_t
modifier|*
name|svn_fs_fs__rep_copy
parameter_list|(
name|representation_t
modifier|*
name|rep
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return the recorded checksum of type KIND for the text representation    of NODREV into CHECKSUM, allocating from POOL.  If no stored checksum is    available, put all NULL into CHECKSUM. */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_fs__file_checksum
parameter_list|(
name|svn_checksum_t
modifier|*
modifier|*
name|checksum
parameter_list|,
name|node_revision_t
modifier|*
name|noderev
parameter_list|,
name|svn_checksum_kind_t
name|kind
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Find the paths which were changed in revision REV of filesystem FS    and store them in *CHANGED_PATHS_P.  Cached copyfrom information    will be stored in *COPYFROM_CACHE.  Get any temporary allocations    from POOL. */
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
name|apr_hash_t
modifier|*
name|copyfrom_cache
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
comment|/* Return whether or not the given FS supports mergeinfo metadata. */
end_comment

begin_function_decl
name|svn_boolean_t
name|svn_fs_fs__fs_supports_mergeinfo
parameter_list|(
name|svn_fs_t
modifier|*
name|fs
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
name|char
modifier|*
name|copy_id
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
name|char
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
comment|/* Add a change to the changes record for filesystem FS in transaction    TXN_ID.  Mark path PATH, having node-id ID, as changed according to    the type in CHANGE_KIND.  If the text representation was changed    set TEXT_MOD to TRUE, and likewise for PROP_MOD.  If this change    was the result of a copy, set COPYFROM_REV and COPYFROM_PATH to the    revision and path of the copy source, otherwise they should be set    to SVN_INVALID_REVNUM and NULL.  Perform any temporary allocations    from POOL. */
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
name|char
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
name|char
modifier|*
name|copy_id
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
comment|/* Commit the transaction TXN in filesystem FS and return its new    revision number in *REV.  If the transaction is out of date, return    the error SVN_ERR_FS_TXN_OUT_OF_DATE.  Use POOL for temporary    allocations. */
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
comment|/* Return the next available copy_id in *COPY_ID for the transaction    TXN_ID in filesystem FS.  Allocate space in POOL. */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_fs__reserve_copy_id
parameter_list|(
specifier|const
name|char
modifier|*
modifier|*
name|copy_id
parameter_list|,
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
comment|/* Create a fs_fs fileysystem referenced by FS at path PATH.  Get any    temporary allocations from POOL.     ### Some parts of *FS must have been initialized beforehand; some parts        (including FS->path) are initialized by this function. */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_fs__create
parameter_list|(
name|svn_fs_t
modifier|*
name|fs
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
end_function_decl

begin_comment
comment|/* Set the uuid of repository FS to UUID, if UUID is not NULL;    otherwise, set the uuid of FS to a newly generated UUID.  Perform    temporary allocations in POOL. */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_fs__set_uuid
parameter_list|(
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
specifier|const
name|char
modifier|*
name|uuid
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
name|proplist
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
name|changes
parameter_list|,
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
comment|/* Set *PATH to the path of REV in FS, whether in a pack file or not.    Allocate *PATH in POOL.     Note: If the caller does not have the write lock on FS, then the path is    not guaranteed to be correct or to remain correct after the function    returns, because the revision might become packed before or after this    call.  If a file exists at that path, then it is correct; if not, then    the caller should call update_min_unpacked_rev() and re-try once. */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_fs__path_rev_absolute
parameter_list|(
specifier|const
name|char
modifier|*
modifier|*
name|path
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
comment|/* Return the path to the 'current' file in FS.    Perform allocation in POOL. */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|svn_fs_fs__path_current
parameter_list|(
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
comment|/* Obtain a write lock on the filesystem FS in a subpool of POOL, call    BODY with BATON and that subpool, destroy the subpool (releasing the write    lock) and return what BODY returned. */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_fs__with_write_lock
parameter_list|(
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
name|svn_error_t
modifier|*
function_decl|(
modifier|*
name|body
function_decl|)
parameter_list|(
name|void
modifier|*
name|baton
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
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
end_function_decl

begin_comment
comment|/* Find the value of the property named PROPNAME in transaction TXN.    Return the contents in *VALUE_P.  The contents will be allocated    from POOL. */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_fs__revision_prop
parameter_list|(
name|svn_string_t
modifier|*
modifier|*
name|value_p
parameter_list|,
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
name|svn_revnum_t
name|rev
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
comment|/* Change, add, or delete a property on a revision REV in filesystem    FS.  NAME gives the name of the property, and value, if non-NULL,    gives the new contents of the property.  If value is NULL, then the    property will be deleted.  If OLD_VALUE_P is not NULL, do nothing unless the    preexisting value is *OLD_VALUE_P.  Do any temporary allocation in POOL.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_fs__change_rev_prop
parameter_list|(
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
name|svn_revnum_t
name|rev
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
specifier|const
name|svn_string_t
modifier|*
specifier|const
modifier|*
name|old_value_p
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
name|char
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
comment|/* If directory PATH does not exist, create it and give it the same    permissions as FS_PATH.*/
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_fs__ensure_dir_exists
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|,
specifier|const
name|char
modifier|*
name|fs_path
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Update the node origin index for FS, recording the mapping from    NODE_ID to NODE_REV_ID.  Use POOL for any temporary allocations.     Because this is just an "optional" cache, this function does not    return an error if the underlying storage is readonly; it still    returns an error for other error conditions.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_fs__set_node_origin
parameter_list|(
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
specifier|const
name|char
modifier|*
name|node_id
parameter_list|,
specifier|const
name|svn_fs_id_t
modifier|*
name|node_rev_id
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Set *ORIGIN_ID to the node revision ID from which the history of    all nodes in FS whose "Node ID" is NODE_ID springs, as determined    by a look in the index.  ORIGIN_ID needs to be parsed in an    FS-backend-specific way.  Use POOL for allocations.     If there is no entry for NODE_ID in the cache, return NULL    in *ORIGIN_ID. */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_fs__get_node_origin
parameter_list|(
specifier|const
name|svn_fs_id_t
modifier|*
modifier|*
name|origin_id
parameter_list|,
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
specifier|const
name|char
modifier|*
name|node_id
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Initialize all session-local caches in FS according to the global    cache settings. Use POOL for allocations.     Please note that it is permissible for this function to set some    or all of these caches to NULL, regardless of any setting. */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_fs__initialize_caches
parameter_list|(
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
comment|/* Initialize all transaction-local caches in FS according to the global    cache settings and make TXN_ID part of their key space. Use POOL for    allocations.     Please note that it is permissible for this function to set some or all    of these caches to NULL, regardless of any setting. */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_fs__initialize_txn_caches
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
comment|/* Resets the svn_cache__t structures local to the current transaction in FS.    Calling it more than once per txn or from outside any txn is allowed. */
end_comment

begin_function_decl
name|void
name|svn_fs_fs__reset_txn_caches
parameter_list|(
name|svn_fs_t
modifier|*
name|fs
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Possibly pack the repository at PATH.  This just take full shards, and    combines all the revision files into a single one, with a manifest header.    Use optional CANCEL_FUNC/CANCEL_BATON for cancellation support.     Existing filesystem references need not change.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_fs__pack
parameter_list|(
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
name|svn_fs_pack_notify_t
name|notify_func
parameter_list|,
name|void
modifier|*
name|notify_baton
parameter_list|,
name|svn_cancel_func_t
name|cancel_func
parameter_list|,
name|void
modifier|*
name|cancel_baton
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

