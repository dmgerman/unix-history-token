begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* fs.h : interface to Subversion filesystem, private to libsvn_fs  *  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_LIBSVN_FS_FS_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_LIBSVN_FS_FS_H
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
file|<apr_network_io.h>
end_include

begin_include
include|#
directive|include
file|"svn_fs.h"
end_include

begin_include
include|#
directive|include
file|"svn_config.h"
end_include

begin_include
include|#
directive|include
file|"private/svn_atomic.h"
end_include

begin_include
include|#
directive|include
file|"private/svn_cache.h"
end_include

begin_include
include|#
directive|include
file|"private/svn_fs_private.h"
end_include

begin_include
include|#
directive|include
file|"private/svn_sqlite.h"
end_include

begin_include
include|#
directive|include
file|"private/svn_mutex.h"
end_include

begin_include
include|#
directive|include
file|"private/svn_named_atomic.h"
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
comment|/*** The filesystem structure.  ***/
comment|/* Following are defines that specify the textual elements of the    native filesystem directories and revision files. */
comment|/* Names of special files in the fs_fs filesystem. */
define|#
directive|define
name|PATH_FORMAT
value|"format"
comment|/* Contains format number */
define|#
directive|define
name|PATH_UUID
value|"uuid"
comment|/* Contains UUID */
define|#
directive|define
name|PATH_CURRENT
value|"current"
comment|/* Youngest revision */
define|#
directive|define
name|PATH_LOCK_FILE
value|"write-lock"
comment|/* Revision lock file */
define|#
directive|define
name|PATH_REVS_DIR
value|"revs"
comment|/* Directory of revisions */
define|#
directive|define
name|PATH_REVPROPS_DIR
value|"revprops"
comment|/* Directory of revprops */
define|#
directive|define
name|PATH_TXNS_DIR
value|"transactions"
comment|/* Directory of transactions */
define|#
directive|define
name|PATH_NODE_ORIGINS_DIR
value|"node-origins"
comment|/* Lazy node-origin cache */
define|#
directive|define
name|PATH_TXN_PROTOS_DIR
value|"txn-protorevs"
comment|/* Directory of proto-revs */
define|#
directive|define
name|PATH_TXN_CURRENT
value|"txn-current"
comment|/* File with next txn key */
define|#
directive|define
name|PATH_TXN_CURRENT_LOCK
value|"txn-current-lock"
comment|/* Lock for txn-current */
define|#
directive|define
name|PATH_LOCKS_DIR
value|"locks"
comment|/* Directory of locks */
define|#
directive|define
name|PATH_MIN_UNPACKED_REV
value|"min-unpacked-rev"
comment|/* Oldest revision which                                                     has not been packed. */
define|#
directive|define
name|PATH_REVPROP_GENERATION
value|"revprop-generation"
comment|/* Current revprop generation*/
define|#
directive|define
name|PATH_MANIFEST
value|"manifest"
comment|/* Manifest file name */
define|#
directive|define
name|PATH_PACKED
value|"pack"
comment|/* Packed revision data file */
define|#
directive|define
name|PATH_EXT_PACKED_SHARD
value|".pack"
comment|/* Extension for packed                                                     shards */
comment|/* If you change this, look at tests/svn_test_fs.c(maybe_install_fsfs_conf) */
define|#
directive|define
name|PATH_CONFIG
value|"fsfs.conf"
comment|/* Configuration */
comment|/* Names of special files and file extensions for transactions */
define|#
directive|define
name|PATH_CHANGES
value|"changes"
comment|/* Records changes made so far */
define|#
directive|define
name|PATH_TXN_PROPS
value|"props"
comment|/* Transaction properties */
define|#
directive|define
name|PATH_NEXT_IDS
value|"next-ids"
comment|/* Next temporary ID assignments */
define|#
directive|define
name|PATH_PREFIX_NODE
value|"node."
comment|/* Prefix for node filename */
define|#
directive|define
name|PATH_EXT_TXN
value|".txn"
comment|/* Extension of txn dir */
define|#
directive|define
name|PATH_EXT_CHILDREN
value|".children"
comment|/* Extension for dir contents */
define|#
directive|define
name|PATH_EXT_PROPS
value|".props"
comment|/* Extension for node props */
define|#
directive|define
name|PATH_EXT_REV
value|".rev"
comment|/* Extension of protorev file */
define|#
directive|define
name|PATH_EXT_REV_LOCK
value|".rev-lock"
comment|/* Extension of protorev lock file */
comment|/* Names of files in legacy FS formats */
define|#
directive|define
name|PATH_REV
value|"rev"
comment|/* Proto rev file */
define|#
directive|define
name|PATH_REV_LOCK
value|"rev-lock"
comment|/* Proto rev (write) lock file */
comment|/* Names of sections and options in fsfs.conf. */
define|#
directive|define
name|CONFIG_SECTION_CACHES
value|"caches"
define|#
directive|define
name|CONFIG_OPTION_FAIL_STOP
value|"fail-stop"
define|#
directive|define
name|CONFIG_SECTION_REP_SHARING
value|"rep-sharing"
define|#
directive|define
name|CONFIG_OPTION_ENABLE_REP_SHARING
value|"enable-rep-sharing"
define|#
directive|define
name|CONFIG_SECTION_DELTIFICATION
value|"deltification"
define|#
directive|define
name|CONFIG_OPTION_ENABLE_DIR_DELTIFICATION
value|"enable-dir-deltification"
define|#
directive|define
name|CONFIG_OPTION_ENABLE_PROPS_DELTIFICATION
value|"enable-props-deltification"
define|#
directive|define
name|CONFIG_OPTION_MAX_DELTIFICATION_WALK
value|"max-deltification-walk"
define|#
directive|define
name|CONFIG_OPTION_MAX_LINEAR_DELTIFICATION
value|"max-linear-deltification"
define|#
directive|define
name|CONFIG_SECTION_PACKED_REVPROPS
value|"packed-revprops"
define|#
directive|define
name|CONFIG_OPTION_REVPROP_PACK_SIZE
value|"revprop-pack-size"
define|#
directive|define
name|CONFIG_OPTION_COMPRESS_PACKED_REVPROPS
value|"compress-packed-revprops"
comment|/* The format number of this filesystem.    This is independent of the repository format number, and    independent of any other FS back ends. */
define|#
directive|define
name|SVN_FS_FS__FORMAT_NUMBER
value|6
comment|/* The minimum format number that supports svndiff version 1.  */
define|#
directive|define
name|SVN_FS_FS__MIN_SVNDIFF1_FORMAT
value|2
comment|/* The minimum format number that supports transaction ID generation    using a transaction sequence in the txn-current file. */
define|#
directive|define
name|SVN_FS_FS__MIN_TXN_CURRENT_FORMAT
value|3
comment|/* The minimum format number that supports the "layout" filesystem    format option. */
define|#
directive|define
name|SVN_FS_FS__MIN_LAYOUT_FORMAT_OPTION_FORMAT
value|3
comment|/* The minimum format number that stores protorevs in a separate directory. */
define|#
directive|define
name|SVN_FS_FS__MIN_PROTOREVS_DIR_FORMAT
value|3
comment|/* The minimum format number that doesn't keep node and copy ID counters. */
define|#
directive|define
name|SVN_FS_FS__MIN_NO_GLOBAL_IDS_FORMAT
value|3
comment|/* The minimum format number that maintains minfo-here and minfo-count    noderev fields. */
define|#
directive|define
name|SVN_FS_FS__MIN_MERGEINFO_FORMAT
value|3
comment|/* The minimum format number that allows rep sharing. */
define|#
directive|define
name|SVN_FS_FS__MIN_REP_SHARING_FORMAT
value|4
comment|/* The minimum format number that supports packed shards. */
define|#
directive|define
name|SVN_FS_FS__MIN_PACKED_FORMAT
value|4
comment|/* The minimum format number that stores node kinds in changed-paths lists. */
define|#
directive|define
name|SVN_FS_FS__MIN_KIND_IN_CHANGED_FORMAT
value|4
comment|/* 1.8 deltification options should work with any FSFS repo but to avoid  * issues with very old servers, restrict those options to the 1.6+ format*/
define|#
directive|define
name|SVN_FS_FS__MIN_DELTIFICATION_FORMAT
value|4
comment|/* The 1.7-dev format, never released, that packed revprops into SQLite    revprops.db . */
define|#
directive|define
name|SVN_FS_FS__PACKED_REVPROP_SQLITE_DEV_FORMAT
value|5
comment|/* The minimum format number that supports packed revprops. */
define|#
directive|define
name|SVN_FS_FS__MIN_PACKED_REVPROP_FORMAT
value|6
comment|/* The minimum format number that supports a configuration file (fsfs.conf) */
define|#
directive|define
name|SVN_FS_FS__MIN_CONFIG_FILE
value|4
comment|/* Private FSFS-specific data shared between all svn_txn_t objects that    relate to a particular transaction in a filesystem (as identified    by transaction id and filesystem UUID).  Objects of this type are    allocated in their own subpool of the common pool. */
typedef|typedef
struct|struct
name|fs_fs_shared_txn_data_t
block|{
comment|/* The next transaction in the list, or NULL if there is no following      transaction. */
name|struct
name|fs_fs_shared_txn_data_t
modifier|*
name|next
decl_stmt|;
comment|/* This transaction's ID.  For repositories whose format is less      than SVN_FS_FS__MIN_TXN_CURRENT_FORMAT, the ID is in the form<rev>-<uniqueifier>, where<uniqueifier> runs from 0-99999 (see      create_txn_dir_pre_1_5() in fs_fs.c).  For newer repositories,      the form is<rev>-<200 digit base 36 number> (see      create_txn_dir() in fs_fs.c). */
name|char
name|txn_id
index|[
name|SVN_FS__TXN_MAX_LEN
operator|+
literal|1
index|]
decl_stmt|;
comment|/* Whether the transaction's prototype revision file is locked for      writing by any thread in this process (including the current      thread; recursive locks are not permitted).  This is effectively      a non-recursive mutex. */
name|svn_boolean_t
name|being_written
decl_stmt|;
comment|/* The pool in which this object has been allocated; a subpool of the      common pool. */
name|apr_pool_t
modifier|*
name|pool
decl_stmt|;
block|}
name|fs_fs_shared_txn_data_t
typedef|;
comment|/* On most operating systems apr implements file locks per process, not    per file.  On Windows apr implements the locking as per file handle    locks, so we don't have to add our own mutex for just in-process    synchronization. */
comment|/* Compare ../libsvn_subr/named_atomic.c:USE_THREAD_MUTEX */
if|#
directive|if
name|APR_HAS_THREADS
operator|&&
operator|!
name|defined
argument_list|(
name|WIN32
argument_list|)
define|#
directive|define
name|SVN_FS_FS__USE_LOCK_MUTEX
value|1
else|#
directive|else
define|#
directive|define
name|SVN_FS_FS__USE_LOCK_MUTEX
value|0
endif|#
directive|endif
comment|/* Private FSFS-specific data shared between all svn_fs_t objects that    relate to a particular filesystem, as identified by filesystem UUID.    Objects of this type are allocated in the common pool. */
typedef|typedef
struct|struct
name|fs_fs_shared_data_t
block|{
comment|/* A list of shared transaction objects for each transaction that is      currently active, or NULL if none are.  All access to this list,      including the contents of the objects stored in it, is synchronised      under TXN_LIST_LOCK. */
name|fs_fs_shared_txn_data_t
modifier|*
name|txns
decl_stmt|;
comment|/* A free transaction object, or NULL if there is no free object.      Access to this object is synchronised under TXN_LIST_LOCK. */
name|fs_fs_shared_txn_data_t
modifier|*
name|free_txn
decl_stmt|;
comment|/* A lock for intra-process synchronization when accessing the TXNS list. */
name|svn_mutex__t
modifier|*
name|txn_list_lock
decl_stmt|;
comment|/* A lock for intra-process synchronization when grabbing the      repository write lock. */
name|svn_mutex__t
modifier|*
name|fs_write_lock
decl_stmt|;
comment|/* A lock for intra-process synchronization when locking the      txn-current file. */
name|svn_mutex__t
modifier|*
name|txn_current_lock
decl_stmt|;
comment|/* The common pool, under which this object is allocated, subpools      of which are used to allocate the transaction objects. */
name|apr_pool_t
modifier|*
name|common_pool
decl_stmt|;
block|}
name|fs_fs_shared_data_t
typedef|;
comment|/* Data structure for the 1st level DAG node cache. */
typedef|typedef
name|struct
name|fs_fs_dag_cache_t
name|fs_fs_dag_cache_t
typedef|;
comment|/* Key type for all caches that use revision + offset / counter as key. */
typedef|typedef
struct|struct
name|pair_cache_key_t
block|{
name|svn_revnum_t
name|revision
decl_stmt|;
name|apr_int64_t
name|second
decl_stmt|;
block|}
name|pair_cache_key_t
typedef|;
comment|/* Private (non-shared) FSFS-specific data for each svn_fs_t object.    Any caches in here may be NULL. */
typedef|typedef
struct|struct
name|fs_fs_data_t
block|{
comment|/* The format number of this FS. */
name|int
name|format
decl_stmt|;
comment|/* The maximum number of files to store per directory (for sharded      layouts) or zero (for linear layouts). */
name|int
name|max_files_per_dir
decl_stmt|;
comment|/* The revision that was youngest, last time we checked. */
name|svn_revnum_t
name|youngest_rev_cache
decl_stmt|;
comment|/* The fsfs.conf file, parsed.  Allocated in FS->pool. */
name|svn_config_t
modifier|*
name|config
decl_stmt|;
comment|/* Caches of immutable data.  (Note that if these are created with      svn_cache__create_memcache, the data can be shared between      multiple svn_fs_t's for the same filesystem.) */
comment|/* A cache of revision root IDs, mapping from (svn_revnum_t *) to      (svn_fs_id_t *).  (Not threadsafe.) */
name|svn_cache__t
modifier|*
name|rev_root_id_cache
decl_stmt|;
comment|/* Caches native dag_node_t* instances and acts as a 1st level cache */
name|fs_fs_dag_cache_t
modifier|*
name|dag_node_cache
decl_stmt|;
comment|/* DAG node cache for immutable nodes.  Maps (revision, fspath)      to (dag_node_t *). This is the 2nd level cache for DAG nodes. */
name|svn_cache__t
modifier|*
name|rev_node_cache
decl_stmt|;
comment|/* A cache of the contents of immutable directories; maps from      unparsed FS ID to a apr_hash_t * mapping (const char *) dirent      names to (svn_fs_dirent_t *). */
name|svn_cache__t
modifier|*
name|dir_cache
decl_stmt|;
comment|/* Fulltext cache; currently only used with memcached.  Maps from      rep key (revision/offset) to svn_stringbuf_t. */
name|svn_cache__t
modifier|*
name|fulltext_cache
decl_stmt|;
comment|/* Access object to the atomics namespace used by revprop caching.      Will be NULL until the first access. */
name|svn_atomic_namespace__t
modifier|*
name|revprop_namespace
decl_stmt|;
comment|/* Access object to the revprop "generation". Will be NULL until      the first access. */
name|svn_named_atomic__t
modifier|*
name|revprop_generation
decl_stmt|;
comment|/* Access object to the revprop update timeout. Will be NULL until      the first access. */
name|svn_named_atomic__t
modifier|*
name|revprop_timeout
decl_stmt|;
comment|/* Revision property cache.  Maps from (rev,generation) to apr_hash_t. */
name|svn_cache__t
modifier|*
name|revprop_cache
decl_stmt|;
comment|/* Node properties cache.  Maps from rep key to apr_hash_t. */
name|svn_cache__t
modifier|*
name|properties_cache
decl_stmt|;
comment|/* Pack manifest cache; a cache mapping (svn_revnum_t) shard number to      a manifest; and a manifest is a mapping from (svn_revnum_t) revision      number offset within a shard to (apr_off_t) byte-offset in the      respective pack file. */
name|svn_cache__t
modifier|*
name|packed_offset_cache
decl_stmt|;
comment|/* Cache for txdelta_window_t objects; the key is (revFilePath, offset) */
name|svn_cache__t
modifier|*
name|txdelta_window_cache
decl_stmt|;
comment|/* Cache for combined windows as svn_stringbuf_t objects;      the key is (revFilePath, offset) */
name|svn_cache__t
modifier|*
name|combined_window_cache
decl_stmt|;
comment|/* Cache for node_revision_t objects; the key is (revision, id offset) */
name|svn_cache__t
modifier|*
name|node_revision_cache
decl_stmt|;
comment|/* Cache for change lists as APR arrays of change_t * objects; the key      is the revision */
name|svn_cache__t
modifier|*
name|changes_cache
decl_stmt|;
comment|/* Cache for svn_mergeinfo_t objects; the key is a combination of      revision, inheritance flags and path. */
name|svn_cache__t
modifier|*
name|mergeinfo_cache
decl_stmt|;
comment|/* Cache for presence of svn_mergeinfo_t on a noderev; the key is a      combination of revision, inheritance flags and path; value is "1"      if the node has mergeinfo, "0" if it doesn't. */
name|svn_cache__t
modifier|*
name|mergeinfo_existence_cache
decl_stmt|;
comment|/* TRUE while the we hold a lock on the write lock file. */
name|svn_boolean_t
name|has_write_lock
decl_stmt|;
comment|/* If set, there are or have been more than one concurrent transaction */
name|svn_boolean_t
name|concurrent_transactions
decl_stmt|;
comment|/* Temporary cache for changed directories yet to be committed; maps from      unparsed FS ID to ###x.  NULL outside transactions. */
name|svn_cache__t
modifier|*
name|txn_dir_cache
decl_stmt|;
comment|/* Data shared between all svn_fs_t objects for a given filesystem. */
name|fs_fs_shared_data_t
modifier|*
name|shared
decl_stmt|;
comment|/* The sqlite database used for rep caching. */
name|svn_sqlite__db_t
modifier|*
name|rep_cache_db
decl_stmt|;
comment|/* Thread-safe boolean */
name|svn_atomic_t
name|rep_cache_db_opened
decl_stmt|;
comment|/* The oldest revision not in a pack file.  It also applies to revprops    * if revprop packing has been enabled by the FSFS format version. */
name|svn_revnum_t
name|min_unpacked_rev
decl_stmt|;
comment|/* Whether rep-sharing is supported by the filesystem    * and allowed by the configuration. */
name|svn_boolean_t
name|rep_sharing_allowed
decl_stmt|;
comment|/* File size limit in bytes up to which multiple revprops shall be packed    * into a single file. */
name|apr_int64_t
name|revprop_pack_size
decl_stmt|;
comment|/* Whether packed revprop files shall be compressed. */
name|svn_boolean_t
name|compress_packed_revprops
decl_stmt|;
comment|/* Whether directory nodes shall be deltified just like file nodes. */
name|svn_boolean_t
name|deltify_directories
decl_stmt|;
comment|/* Whether nodes properties shall be deltified. */
name|svn_boolean_t
name|deltify_properties
decl_stmt|;
comment|/* Restart deltification histories after each multiple of this value */
name|apr_int64_t
name|max_deltification_walk
decl_stmt|;
comment|/* Maximum number of length of the linear part at the top of the    * deltification history after which skip deltas will be used. */
name|apr_int64_t
name|max_linear_deltification
decl_stmt|;
comment|/* Pointer to svn_fs_open. */
name|svn_error_t
modifier|*
function_decl|(
modifier|*
name|svn_fs_open_
function_decl|)
parameter_list|(
name|svn_fs_t
modifier|*
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|apr_hash_t
modifier|*
parameter_list|,
name|apr_pool_t
modifier|*
parameter_list|)
function_decl|;
block|}
name|fs_fs_data_t
typedef|;
comment|/*** Filesystem Transaction ***/
typedef|typedef
struct|struct
name|transaction_t
block|{
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
comment|/*** Representation ***/
comment|/* If you add fields to this, check to see if you need to change  * svn_fs_fs__rep_copy. */
typedef|typedef
struct|struct
name|representation_t
block|{
comment|/* Checksums for the contents produced by this representation.      This checksum is for the contents the rep shows to consumers,      regardless of how the rep stores the data under the hood.  It is      independent of the storage (fulltext, delta, whatever).       If checksum is NULL, then for compatibility behave as though this      checksum matches the expected checksum.       The md5 checksum is always filled, unless this is rep which was      retrieved from the rep-cache.  The sha1 checksum is only computed on      a write, for use with rep-sharing; it may be read from an existing      representation, but otherwise it is NULL. */
name|svn_checksum_t
modifier|*
name|md5_checksum
decl_stmt|;
name|svn_checksum_t
modifier|*
name|sha1_checksum
decl_stmt|;
comment|/* Revision where this representation is located. */
name|svn_revnum_t
name|revision
decl_stmt|;
comment|/* Offset into the revision file where it is located. */
name|apr_off_t
name|offset
decl_stmt|;
comment|/* The size of the representation in bytes as seen in the revision      file. */
name|svn_filesize_t
name|size
decl_stmt|;
comment|/* The size of the fulltext of the representation. If this is 0,    * the fulltext size is equal to representation size in the rev file, */
name|svn_filesize_t
name|expanded_size
decl_stmt|;
comment|/* Is this representation a transaction? */
specifier|const
name|char
modifier|*
name|txn_id
decl_stmt|;
comment|/* For rep-sharing, we need a way of uniquifying node-revs which share the      same representation (see svn_fs_fs__noderev_same_rep_key() ).  So, we      store the original txn of the node rev (not the rep!), along with some      intra-node uniqification content.       May be NULL, in which case, it is considered to match other NULL      values.*/
specifier|const
name|char
modifier|*
name|uniquifier
decl_stmt|;
block|}
name|representation_t
typedef|;
comment|/*** Node-Revision ***/
comment|/* If you add fields to this, check to see if you need to change  * copy_node_revision in dag.c. */
typedef|typedef
struct|struct
name|node_revision_t
block|{
comment|/* node kind */
name|svn_node_kind_t
name|kind
decl_stmt|;
comment|/* The node-id for this node-rev. */
specifier|const
name|svn_fs_id_t
modifier|*
name|id
decl_stmt|;
comment|/* predecessor node revision id, or NULL if there is no predecessor      for this node revision */
specifier|const
name|svn_fs_id_t
modifier|*
name|predecessor_id
decl_stmt|;
comment|/* If this node-rev is a copy, where was it copied from? */
specifier|const
name|char
modifier|*
name|copyfrom_path
decl_stmt|;
name|svn_revnum_t
name|copyfrom_rev
decl_stmt|;
comment|/* Helper for history tracing, root of the parent tree from whence      this node-rev was copied. */
name|svn_revnum_t
name|copyroot_rev
decl_stmt|;
specifier|const
name|char
modifier|*
name|copyroot_path
decl_stmt|;
comment|/* number of predecessors this node revision has (recursively), or      -1 if not known (for backward compatibility). */
name|int
name|predecessor_count
decl_stmt|;
comment|/* representation key for this node's properties.  may be NULL if      there are no properties.  */
name|representation_t
modifier|*
name|prop_rep
decl_stmt|;
comment|/* representation for this node's data.  may be NULL if there is      no data. */
name|representation_t
modifier|*
name|data_rep
decl_stmt|;
comment|/* path at which this node first came into existence.  */
specifier|const
name|char
modifier|*
name|created_path
decl_stmt|;
comment|/* is this the unmodified root of a transaction? */
name|svn_boolean_t
name|is_fresh_txn_root
decl_stmt|;
comment|/* Number of nodes with svn:mergeinfo properties that are      descendants of this node (including it itself) */
name|apr_int64_t
name|mergeinfo_count
decl_stmt|;
comment|/* Does this node itself have svn:mergeinfo? */
name|svn_boolean_t
name|has_mergeinfo
decl_stmt|;
block|}
name|node_revision_t
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
comment|/* Node kind (possibly svn_node_unknown). */
name|svn_node_kind_t
name|node_kind
decl_stmt|;
comment|/* Copyfrom revision and path. */
name|svn_revnum_t
name|copyfrom_rev
decl_stmt|;
specifier|const
name|char
modifier|*
name|copyfrom_path
decl_stmt|;
block|}
name|change_t
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
comment|/* SVN_LIBSVN_FS_FS_H */
end_comment

end_unit

