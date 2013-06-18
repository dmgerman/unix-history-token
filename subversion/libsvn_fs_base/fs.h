begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* fs.h : interface to Subversion filesystem, private to libsvn_fs  *  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_LIBSVN_FS_BASE_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_LIBSVN_FS_BASE_H
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
file|"svn_fs.h"
end_include

begin_include
include|#
directive|include
file|"bdb/env.h"
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
comment|/*** Filesystem schema versions ***/
comment|/* The format number of this filesystem.  This is independent of the    repository format number, and independent of any other FS back    ends.  See the SVN_FS_BASE__MIN_*_FORMAT defines to get a sense of    what changes and features were added in which versions of this    back-end's format.  */
define|#
directive|define
name|SVN_FS_BASE__FORMAT_NUMBER
value|4
comment|/* Minimum format number that supports representation sharing.  This    also brings in the support for storing SHA1 checksums.   */
define|#
directive|define
name|SVN_FS_BASE__MIN_REP_SHARING_FORMAT
value|4
comment|/* Minimum format number that supports the 'miscellaneous' table */
define|#
directive|define
name|SVN_FS_BASE__MIN_MISCELLANY_FORMAT
value|4
comment|/* Minimum format number that supports forward deltas */
define|#
directive|define
name|SVN_FS_BASE__MIN_FORWARD_DELTAS_FORMAT
value|4
comment|/* Minimum format number that supports node-origins tracking */
define|#
directive|define
name|SVN_FS_BASE__MIN_NODE_ORIGINS_FORMAT
value|3
comment|/* Minimum format number that supports mergeinfo */
define|#
directive|define
name|SVN_FS_BASE__MIN_MERGEINFO_FORMAT
value|3
comment|/* Minimum format number that supports svndiff version 1.  */
define|#
directive|define
name|SVN_FS_BASE__MIN_SVNDIFF1_FORMAT
value|2
comment|/* Return SVN_ERR_UNSUPPORTED_FEATURE if the version of filesystem FS does    not indicate support for FEATURE (which REQUIRES a newer version). */
name|svn_error_t
modifier|*
name|svn_fs_base__test_required_feature_format
parameter_list|(
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
specifier|const
name|char
modifier|*
name|feature
parameter_list|,
name|int
name|requires
parameter_list|)
function_decl|;
comment|/*** Miscellany keys. ***/
comment|/* Revision at which the repo started using forward deltas. */
define|#
directive|define
name|SVN_FS_BASE__MISC_FORWARD_DELTA_UPGRADE
value|"forward-delta-rev"
comment|/*** The filesystem structure.  ***/
typedef|typedef
struct|struct
name|base_fs_data_t
block|{
comment|/* A Berkeley DB environment for all the filesystem's databases.      This establishes the scope of the filesystem's transactions.  */
name|bdb_env_baton_t
modifier|*
name|bdb
decl_stmt|;
comment|/* The filesystem's various tables.  See `structure' for details.  */
name|DB
modifier|*
name|changes
decl_stmt|;
name|DB
modifier|*
name|copies
decl_stmt|;
name|DB
modifier|*
name|nodes
decl_stmt|;
name|DB
modifier|*
name|representations
decl_stmt|;
name|DB
modifier|*
name|revisions
decl_stmt|;
name|DB
modifier|*
name|strings
decl_stmt|;
name|DB
modifier|*
name|transactions
decl_stmt|;
name|DB
modifier|*
name|uuids
decl_stmt|;
name|DB
modifier|*
name|locks
decl_stmt|;
name|DB
modifier|*
name|lock_tokens
decl_stmt|;
name|DB
modifier|*
name|node_origins
decl_stmt|;
name|DB
modifier|*
name|miscellaneous
decl_stmt|;
name|DB
modifier|*
name|checksum_reps
decl_stmt|;
comment|/* A boolean for tracking when we have a live Berkeley DB      transaction trail alive. */
name|svn_boolean_t
name|in_txn_trail
decl_stmt|;
comment|/* The format number of this FS. */
name|int
name|format
decl_stmt|;
block|}
name|base_fs_data_t
typedef|;
comment|/*** Filesystem Revision ***/
typedef|typedef
struct|struct
name|revision_t
block|{
comment|/* id of the transaction that was committed to create this      revision. */
specifier|const
name|char
modifier|*
name|txn_id
decl_stmt|;
block|}
name|revision_t
typedef|;
comment|/*** Transaction Kind ***/
typedef|typedef
enum|enum
name|transaction_kind_t
block|{
name|transaction_kind_normal
init|=
literal|1
block|,
comment|/* normal, uncommitted */
name|transaction_kind_committed
block|,
comment|/* committed */
name|transaction_kind_dead
comment|/* uncommitted and dead */
block|}
name|transaction_kind_t
typedef|;
comment|/*** Filesystem Transaction ***/
typedef|typedef
struct|struct
name|transaction_t
block|{
comment|/* kind of transaction. */
name|transaction_kind_t
name|kind
decl_stmt|;
comment|/* revision which this transaction was committed to create, or an      invalid revision number if this transaction was never committed. */
name|svn_revnum_t
name|revision
decl_stmt|;
comment|/* property list (const char * name, svn_string_t * value).      may be NULL if there are no properties.  */
name|apr_hash_t
modifier|*
name|proplist
decl_stmt|;
comment|/* node revision id of the root node.  */
specifier|const
name|svn_fs_id_t
modifier|*
name|root_id
decl_stmt|;
comment|/* node revision id of the node which is the root of the revision      upon which this txn is base.  (unfinished only) */
specifier|const
name|svn_fs_id_t
modifier|*
name|base_id
decl_stmt|;
comment|/* copies list (const char * copy_ids), or NULL if there have been      no copies in this transaction.  */
name|apr_array_header_t
modifier|*
name|copies
decl_stmt|;
block|}
name|transaction_t
typedef|;
comment|/*** Node-Revision ***/
typedef|typedef
struct|struct
name|node_revision_t
block|{
comment|/* node kind */
name|svn_node_kind_t
name|kind
decl_stmt|;
comment|/* predecessor node revision id, or NULL if there is no predecessor      for this node revision */
specifier|const
name|svn_fs_id_t
modifier|*
name|predecessor_id
decl_stmt|;
comment|/* number of predecessors this node revision has (recursively), or      -1 if not known (for backward compatibility). */
name|int
name|predecessor_count
decl_stmt|;
comment|/* representation key for this node's properties.  may be NULL if      there are no properties.  */
specifier|const
name|char
modifier|*
name|prop_key
decl_stmt|;
comment|/* representation key for this node's text data (files) or entries      list (dirs).  may be NULL if there are no contents.  */
specifier|const
name|char
modifier|*
name|data_key
decl_stmt|;
comment|/* data representation instance identifier.  Sounds fancy, but is      really just a way to distinguish between "I use the same rep key      as another node because we share ancestry and haven't had our      text touched at all" and "I use the same rep key as another node      only because one or both of us decided to pick up a shared      representation after-the-fact."  May be NULL (if this node      revision isn't using a shared rep, or isn't the original      "assignee" of a shared rep). */
specifier|const
name|char
modifier|*
name|data_key_uniquifier
decl_stmt|;
comment|/* representation key for this node's text-data-in-progess (files      only).  NULL if no edits are currently in-progress.  This field      is always NULL for kinds other than "file".  */
specifier|const
name|char
modifier|*
name|edit_key
decl_stmt|;
comment|/* path at which this node first came into existence.  */
specifier|const
name|char
modifier|*
name|created_path
decl_stmt|;
comment|/* does this node revision have the mergeinfo tracking property set      on it?  (only valid for FS schema 3 and newer) */
name|svn_boolean_t
name|has_mergeinfo
decl_stmt|;
comment|/* number of children of this node which have the mergeinfo tracking      property set  (0 for files; valid only for FS schema 3 and newer). */
name|apr_int64_t
name|mergeinfo_count
decl_stmt|;
block|}
name|node_revision_t
typedef|;
comment|/*** Representation Kind ***/
typedef|typedef
enum|enum
name|rep_kind_t
block|{
name|rep_kind_fulltext
init|=
literal|1
block|,
comment|/* fulltext */
name|rep_kind_delta
comment|/* delta */
block|}
name|rep_kind_t
typedef|;
comment|/*** "Delta" Offset/Window Chunk ***/
typedef|typedef
struct|struct
name|rep_delta_chunk_t
block|{
comment|/* diff format version number ### at this point, "svndiff" is the      only format used. */
name|apr_byte_t
name|version
decl_stmt|;
comment|/* starting offset of the data represented by this chunk */
name|svn_filesize_t
name|offset
decl_stmt|;
comment|/* string-key to which this representation points. */
specifier|const
name|char
modifier|*
name|string_key
decl_stmt|;
comment|/* size of the fulltext data represented by this delta window. */
name|apr_size_t
name|size
decl_stmt|;
comment|/* representation-key to use when needed source data for      undeltification. */
specifier|const
name|char
modifier|*
name|rep_key
decl_stmt|;
comment|/* apr_off_t rep_offset;  ### not implemented */
block|}
name|rep_delta_chunk_t
typedef|;
comment|/*** Representation ***/
typedef|typedef
struct|struct
name|representation_t
block|{
comment|/* representation kind */
name|rep_kind_t
name|kind
decl_stmt|;
comment|/* transaction ID under which representation was created (used as a      mutability flag when compared with a current editing      transaction). */
specifier|const
name|char
modifier|*
name|txn_id
decl_stmt|;
comment|/* Checksums for the contents produced by this representation.      These checksum is for the contents the rep shows to consumers,      regardless of how the rep stores the data under the hood.  It is      independent of the storage (fulltext, delta, whatever).       If this is NULL, then for compatibility behave as though      this checksum matches the expected checksum. */
name|svn_checksum_t
modifier|*
name|md5_checksum
decl_stmt|;
name|svn_checksum_t
modifier|*
name|sha1_checksum
decl_stmt|;
comment|/* kind-specific stuff */
union|union
block|{
comment|/* fulltext stuff */
struct|struct
block|{
comment|/* string-key which holds the fulltext data */
specifier|const
name|char
modifier|*
name|string_key
decl_stmt|;
block|}
name|fulltext
struct|;
comment|/* delta stuff */
struct|struct
block|{
comment|/* an array of rep_delta_chunk_t * chunks of delta          information */
name|apr_array_header_t
modifier|*
name|chunks
decl_stmt|;
block|}
name|delta
struct|;
block|}
name|contents
union|;
block|}
name|representation_t
typedef|;
comment|/*** Copy Kind ***/
typedef|typedef
enum|enum
name|copy_kind_t
block|{
name|copy_kind_real
init|=
literal|1
block|,
comment|/* real copy */
name|copy_kind_soft
comment|/* soft copy */
block|}
name|copy_kind_t
typedef|;
comment|/*** Copy ***/
typedef|typedef
struct|struct
name|copy_t
block|{
comment|/* What kind of copy occurred. */
name|copy_kind_t
name|kind
decl_stmt|;
comment|/* Path of copy source. */
specifier|const
name|char
modifier|*
name|src_path
decl_stmt|;
comment|/* Transaction id of copy source. */
specifier|const
name|char
modifier|*
name|src_txn_id
decl_stmt|;
comment|/* Node-revision of copy destination. */
specifier|const
name|svn_fs_id_t
modifier|*
name|dst_noderev_id
decl_stmt|;
block|}
name|copy_t
typedef|;
comment|/*** Change ***/
typedef|typedef
struct|struct
name|change_t
block|{
comment|/* Path of the change. */
specifier|const
name|char
modifier|*
name|path
decl_stmt|;
comment|/* Node revision ID of the change. */
specifier|const
name|svn_fs_id_t
modifier|*
name|noderev_id
decl_stmt|;
comment|/* The kind of change. */
name|svn_fs_path_change_kind_t
name|kind
decl_stmt|;
comment|/* Text or property mods? */
name|svn_boolean_t
name|text_mod
decl_stmt|;
name|svn_boolean_t
name|prop_mod
decl_stmt|;
block|}
name|change_t
typedef|;
comment|/*** Lock node ***/
typedef|typedef
struct|struct
name|lock_node_t
block|{
comment|/* entries list, maps (const char *) name --> (const char *) lock-node-id */
name|apr_hash_t
modifier|*
name|entries
decl_stmt|;
comment|/* optional lock-token, might be NULL. */
specifier|const
name|char
modifier|*
name|lock_token
decl_stmt|;
block|}
name|lock_node_t
typedef|;
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
comment|/* SVN_LIBSVN_FS_BASE_H */
end_comment

end_unit

