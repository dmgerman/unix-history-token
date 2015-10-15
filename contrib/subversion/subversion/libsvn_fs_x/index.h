begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* index.h : interface to FSX indexing functionality  *  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_LIBSVN_FS__INDEX_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_LIBSVN_FS__INDEX_H
end_define

begin_include
include|#
directive|include
file|"fs.h"
end_include

begin_include
include|#
directive|include
file|"rev_file.h"
end_include

begin_comment
comment|/* Per-defined item index values.  They are used to identify empty or  * mandatory items.  */
end_comment

begin_define
define|#
directive|define
name|SVN_FS_X__ITEM_INDEX_UNUSED
value|0
end_define

begin_comment
comment|/* invalid / reserved value */
end_comment

begin_define
define|#
directive|define
name|SVN_FS_X__ITEM_INDEX_CHANGES
value|1
end_define

begin_comment
comment|/* list of changed paths */
end_comment

begin_define
define|#
directive|define
name|SVN_FS_X__ITEM_INDEX_ROOT_NODE
value|2
end_define

begin_comment
comment|/* the root noderev */
end_comment

begin_define
define|#
directive|define
name|SVN_FS_X__ITEM_INDEX_FIRST_USER
value|3
end_define

begin_comment
comment|/* first noderev to be freely                                                assigned */
end_comment

begin_comment
comment|/* Data / item types as stored in the phys-to-log index.  */
end_comment

begin_define
define|#
directive|define
name|SVN_FS_X__ITEM_TYPE_UNUSED
value|0
end_define

begin_comment
comment|/* file section not used */
end_comment

begin_define
define|#
directive|define
name|SVN_FS_X__ITEM_TYPE_FILE_REP
value|1
end_define

begin_comment
comment|/* item is a file representation */
end_comment

begin_define
define|#
directive|define
name|SVN_FS_X__ITEM_TYPE_DIR_REP
value|2
end_define

begin_comment
comment|/* item is a directory rep. */
end_comment

begin_define
define|#
directive|define
name|SVN_FS_X__ITEM_TYPE_FILE_PROPS
value|3
end_define

begin_comment
comment|/* item is a file property rep. */
end_comment

begin_define
define|#
directive|define
name|SVN_FS_X__ITEM_TYPE_DIR_PROPS
value|4
end_define

begin_comment
comment|/* item is a directory prop rep */
end_comment

begin_define
define|#
directive|define
name|SVN_FS_X__ITEM_TYPE_NODEREV
value|5
end_define

begin_comment
comment|/* item is a noderev */
end_comment

begin_define
define|#
directive|define
name|SVN_FS_X__ITEM_TYPE_CHANGES
value|6
end_define

begin_comment
comment|/* item is a changed paths list */
end_comment

begin_define
define|#
directive|define
name|SVN_FS_X__ITEM_TYPE_ANY_REP
value|7
end_define

begin_comment
comment|/* item is any representation.                                               Only used in pre-format7. */
end_comment

begin_define
define|#
directive|define
name|SVN_FS_X__ITEM_TYPE_CHANGES_CONT
value|8
end_define

begin_comment
comment|/* item is a changes container */
end_comment

begin_define
define|#
directive|define
name|SVN_FS_X__ITEM_TYPE_NODEREVS_CONT
value|9
end_define

begin_comment
comment|/* item is a noderevs container */
end_comment

begin_define
define|#
directive|define
name|SVN_FS_X__ITEM_TYPE_REPS_CONT
value|10
end_define

begin_comment
comment|/* item is a representations                                                  container */
end_comment

begin_comment
comment|/* (user visible) entry in the phys-to-log index.  It describes a section  * of some packed / non-packed rev file as containing a specific item.  * There must be no overlapping / conflicting entries.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|svn_fs_x__p2l_entry_t
block|{
comment|/* offset of the first byte that belongs to the item */
name|apr_off_t
name|offset
decl_stmt|;
comment|/* length of the item in bytes */
name|apr_off_t
name|size
decl_stmt|;
comment|/* type of the item (see SVN_FS_X__ITEM_TYPE_*) defines */
name|apr_uint32_t
name|type
decl_stmt|;
comment|/* modified FNV-1a checksum.  0 if unknown checksum */
name|apr_uint32_t
name|fnv1_checksum
decl_stmt|;
comment|/* Number of items in this block / container.  Their list can be found    * in *ITEMS.  0 for unused sections.  1 for non-container items,    *> 1 for containers. */
name|apr_uint32_t
name|item_count
decl_stmt|;
comment|/* List of items in that block / container */
name|svn_fs_x__id_t
modifier|*
name|items
decl_stmt|;
block|}
name|svn_fs_x__p2l_entry_t
typedef|;
end_typedef

begin_comment
comment|/* Return a (deep) copy of ENTRY, allocated in RESULT_POOL.  */
end_comment

begin_function_decl
name|svn_fs_x__p2l_entry_t
modifier|*
name|svn_fs_x__p2l_entry_dup
parameter_list|(
specifier|const
name|svn_fs_x__p2l_entry_t
modifier|*
name|entry
parameter_list|,
name|apr_pool_t
modifier|*
name|result_pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Open / create a log-to-phys index file with the full file path name  * FILE_NAME.  Return the open file in *PROTO_INDEX allocated in  * RESULT_POOL.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_x__l2p_proto_index_open
parameter_list|(
name|apr_file_t
modifier|*
modifier|*
name|proto_index
parameter_list|,
specifier|const
name|char
modifier|*
name|file_name
parameter_list|,
name|apr_pool_t
modifier|*
name|result_pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Call this function before adding entries for the next revision to the  * log-to-phys index file in PROTO_INDEX.  Use SCRATCH_POOL for temporary  * allocations.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_x__l2p_proto_index_add_revision
parameter_list|(
name|apr_file_t
modifier|*
name|proto_index
parameter_list|,
name|apr_pool_t
modifier|*
name|scratch_pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Add a new mapping, ITEM_INDEX to the (OFFSET, SUB_ITEM) pair, to log-to-  * phys index file in PROTO_INDEX.  Please note that mappings may be added  * in any order but duplicate entries for the same ITEM_INDEX, SUB_ITEM  * are not supported.  Not all possible index values need to be used.  * (OFFSET, SUB_ITEM) may be (-1, 0) to mark 'invalid' item indexes but  * that is already implied for all item indexes not explicitly given a  * mapping.  *  * Use SCRATCH_POOL for temporary allocations.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_x__l2p_proto_index_add_entry
parameter_list|(
name|apr_file_t
modifier|*
name|proto_index
parameter_list|,
name|apr_off_t
name|offset
parameter_list|,
name|apr_uint32_t
name|sub_item
parameter_list|,
name|apr_uint64_t
name|item_index
parameter_list|,
name|apr_pool_t
modifier|*
name|scratch_pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Use the proto index file stored at PROTO_FILE_NAME, construct the final  * log-to-phys index and append it to INDEX_FILE.  The first revision will  * be REVISION, entries to the next revision will be assigned to REVISION+1  * and so forth.  *  * Return the MD5 checksum of the on-disk index data in *CHECKSUM, allocated  * in RESULT_POOL.  Use SCRATCH_POOL for temporary allocations.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_x__l2p_index_append
parameter_list|(
name|svn_checksum_t
modifier|*
modifier|*
name|checksum
parameter_list|,
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
name|apr_file_t
modifier|*
name|index_file
parameter_list|,
specifier|const
name|char
modifier|*
name|proto_file_name
parameter_list|,
name|svn_revnum_t
name|revision
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
comment|/* Open / create a phys-to-log index file with the full file path name  * FILE_NAME.  Return the open file in *PROTO_INDEX allocated in  * RESULT_POOL.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_x__p2l_proto_index_open
parameter_list|(
name|apr_file_t
modifier|*
modifier|*
name|proto_index
parameter_list|,
specifier|const
name|char
modifier|*
name|file_name
parameter_list|,
name|apr_pool_t
modifier|*
name|result_pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Add a new mapping ENTRY to the phys-to-log index file in PROTO_INDEX.  * The entries must be added in ascending offset order and must not leave  * intermittent ranges uncovered.  The revision value in ENTRY may be  * SVN_INVALID_REVISION.  Use SCRATCH_POOL for temporary allocations.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_x__p2l_proto_index_add_entry
parameter_list|(
name|apr_file_t
modifier|*
name|proto_index
parameter_list|,
specifier|const
name|svn_fs_x__p2l_entry_t
modifier|*
name|entry
parameter_list|,
name|apr_pool_t
modifier|*
name|scratch_pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Set *NEXT_OFFSET to the first offset behind the last entry in the  * phys-to-log proto index file PROTO_INDEX.  This will be 0 for empty  * index files.  Use SCRATCH_POOL for temporary allocations.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_x__p2l_proto_index_next_offset
parameter_list|(
name|apr_off_t
modifier|*
name|next_offset
parameter_list|,
name|apr_file_t
modifier|*
name|proto_index
parameter_list|,
name|apr_pool_t
modifier|*
name|scratch_pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Use the proto index file stored at PROTO_FILE_NAME, construct the final  * phys-to-log index and append it to INDEX_FILE.  Entries without a valid  * revision will be assigned to the REVISION given here.  *  * Return the MD5 checksum of the on-disk index data in *CHECKSUM, allocated  * in RESULT_POOL.  Use SCRATCH_POOL for temporary allocations.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_x__p2l_index_append
parameter_list|(
name|svn_checksum_t
modifier|*
modifier|*
name|checksum
parameter_list|,
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
name|apr_file_t
modifier|*
name|index_file
parameter_list|,
specifier|const
name|char
modifier|*
name|proto_file_name
parameter_list|,
name|svn_revnum_t
name|revision
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
comment|/* Use the phys-to-log mapping files in FS to build a list of entries  * that (at least partly) overlap with the range given by BLOCK_START  * offset and BLOCK_SIZE in the rep / pack file containing REVISION.  * Return the array in *ENTRIES with svn_fs_fs__p2l_entry_t as elements,  * allocated in RESULT_POOL.  REV_FILE determines whether to access single  * rev or pack file data.  If that is not available anymore (neither in  * cache nor on disk), return an error.  Use SCRATCH_POOL for temporary  * allocations.  *  * Note that (only) the first and the last mapping may cross a cluster  * boundary.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_x__p2l_index_lookup
parameter_list|(
name|apr_array_header_t
modifier|*
modifier|*
name|entries
parameter_list|,
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
name|svn_fs_x__revision_file_t
modifier|*
name|rev_file
parameter_list|,
name|svn_revnum_t
name|revision
parameter_list|,
name|apr_off_t
name|block_start
parameter_list|,
name|apr_off_t
name|block_size
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
comment|/* Use the phys-to-log mapping files in FS to return the entry for the  * container or single item starting at global OFFSET in the rep file  * containing REVISION in*ENTRY, allocated in RESULT_POOL.  Sets *ENTRY  * to NULL if no item starts at exactly that offset.  REV_FILE determines  * whether to access single rev or pack file data.  If that is not available  * anymore (neither in cache nor on disk), return an error.  * Use SCRATCH_POOL for temporary allocations.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_x__p2l_entry_lookup
parameter_list|(
name|svn_fs_x__p2l_entry_t
modifier|*
modifier|*
name|entry
parameter_list|,
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
name|svn_fs_x__revision_file_t
modifier|*
name|rev_file
parameter_list|,
name|svn_revnum_t
name|revision
parameter_list|,
name|apr_off_t
name|offset
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
comment|/* Use the phys-to-log mapping files in FS to return the svn_fs_x__id_t  * for the SUB_ITEM of the container starting at global OFFSET in the rep /  * pack file containing REVISION in *ITEM, allocated in RESULT_POOL.  Sets  * *ITEM to NULL if no element starts at exactly that offset or if it  * contains no more than SUB_ITEM sub-items.  *  * Use SCRATCH_POOL for temporary allocations.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_x__p2l_item_lookup
parameter_list|(
name|svn_fs_x__id_t
modifier|*
modifier|*
name|item
parameter_list|,
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
name|svn_fs_x__revision_file_t
modifier|*
name|rev_file
parameter_list|,
name|svn_revnum_t
name|revision
parameter_list|,
name|apr_off_t
name|offset
parameter_list|,
name|apr_uint32_t
name|sub_item
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
comment|/* For ITEM_ID in FS, return the position in the respective rev or pack file  * in *ABSOLUTE_POSITION and the *SUB_ITEM number within the object at that  * location. *SUB_ITEM will be 0 for non-container items.  *  * REV_FILE determines whether to access single rev or pack file data.  * If that is not available anymore (neither in cache nor on disk), re-open  * the rev / pack file and retry to open the index file.  For transaction  * content, REV_FILE may be NULL.  *  * Use SCRATCH_POOL for temporary allocations.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_x__item_offset
parameter_list|(
name|apr_off_t
modifier|*
name|absolute_position
parameter_list|,
name|apr_uint32_t
modifier|*
name|sub_item
parameter_list|,
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
name|svn_fs_x__revision_file_t
modifier|*
name|rev_file
parameter_list|,
specifier|const
name|svn_fs_x__id_t
modifier|*
name|item_id
parameter_list|,
name|apr_pool_t
modifier|*
name|scratch_pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Use the log-to-phys indexes in FS to determine the maximum item indexes  * assigned to revision START_REV to START_REV + COUNT - 1.  That is a  * close upper limit to the actual number of items in the respective revs.  * Return the results in *MAX_IDS,  allocated in RESULT_POOL.  * Use SCRATCH_POOL for temporary allocations.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_x__l2p_get_max_ids
parameter_list|(
name|apr_array_header_t
modifier|*
modifier|*
name|max_ids
parameter_list|,
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
name|svn_revnum_t
name|start_rev
parameter_list|,
name|apr_size_t
name|count
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
comment|/* In *OFFSET, return the first OFFSET in the pack / rev file containing  * REVISION in FS not covered by the log-to-phys index.  * Use SCRATCH_POOL for temporary allocations.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_x__p2l_get_max_offset
parameter_list|(
name|apr_off_t
modifier|*
name|offset
parameter_list|,
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
name|svn_fs_x__revision_file_t
modifier|*
name|rev_file
parameter_list|,
name|svn_revnum_t
name|revision
parameter_list|,
name|apr_pool_t
modifier|*
name|scratch_pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Index (re-)creation utilities.  */
end_comment

begin_comment
comment|/* For FS, create a new L2P auto-deleting proto index file in POOL and return  * its name in *PROTONAME.  All entries to write are given in ENTRIES and  * entries are of type svn_fs_fs__p2l_entry_t* (sic!).  The ENTRIES array  * will be reordered.  Give the proto index file the lifetime of RESULT_POOL  * and use SCRATCH_POOL for temporary allocations.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_x__l2p_index_from_p2l_entries
parameter_list|(
specifier|const
name|char
modifier|*
modifier|*
name|protoname
parameter_list|,
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
name|apr_array_header_t
modifier|*
name|entries
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
comment|/* For FS, create a new P2L auto-deleting proto index file in POOL and return  * its name in *PROTONAME.  All entries to write are given in ENTRIES and  * of type svn_fs_fs__p2l_entry_t*.  The FVN1 checksums are not taken from  * ENTRIES but are begin calculated from the current contents of REV_FILE  * as we go.  Give the proto index file the lifetime of RESULT_POOL and use  * SCRATCH_POOL for temporary allocations.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_x__p2l_index_from_p2l_entries
parameter_list|(
specifier|const
name|char
modifier|*
modifier|*
name|protoname
parameter_list|,
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
name|svn_fs_x__revision_file_t
modifier|*
name|rev_file
parameter_list|,
name|apr_array_header_t
modifier|*
name|entries
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
comment|/* Serialization and caching interface  */
end_comment

begin_comment
comment|/* We use this key type to address individual pages from both index types.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|svn_fs_x__page_cache_key_t
block|{
comment|/* in l2p: this is the revision of the items being mapped      in p2l: this is the start revision identifying the pack / rev file */
name|apr_uint32_t
name|revision
decl_stmt|;
comment|/* if TRUE, this is the index to a pack file    */
name|svn_boolean_t
name|is_packed
decl_stmt|;
comment|/* in l2p: page number within the revision    * in p2l: page number with the rev / pack file    */
name|apr_uint64_t
name|page
decl_stmt|;
block|}
name|svn_fs_x__page_cache_key_t
typedef|;
end_typedef

begin_comment
comment|/*  * Implements svn_cache__serialize_func_t for l2p_header_t objects.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_x__serialize_l2p_header
parameter_list|(
name|void
modifier|*
modifier|*
name|data
parameter_list|,
name|apr_size_t
modifier|*
name|data_len
parameter_list|,
name|void
modifier|*
name|in
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Implements svn_cache__deserialize_func_t for l2p_header_t objects.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_x__deserialize_l2p_header
parameter_list|(
name|void
modifier|*
modifier|*
name|out
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|apr_size_t
name|data_len
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Implements svn_cache__serialize_func_t for l2p_page_t objects.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_x__serialize_l2p_page
parameter_list|(
name|void
modifier|*
modifier|*
name|data
parameter_list|,
name|apr_size_t
modifier|*
name|data_len
parameter_list|,
name|void
modifier|*
name|in
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Implements svn_cache__deserialize_func_t for l2p_page_t objects.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_x__deserialize_l2p_page
parameter_list|(
name|void
modifier|*
modifier|*
name|out
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|apr_size_t
name|data_len
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Implements svn_cache__serialize_func_t for p2l_header_t objects.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_x__serialize_p2l_header
parameter_list|(
name|void
modifier|*
modifier|*
name|data
parameter_list|,
name|apr_size_t
modifier|*
name|data_len
parameter_list|,
name|void
modifier|*
name|in
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Implements svn_cache__deserialize_func_t for p2l_header_t objects.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_x__deserialize_p2l_header
parameter_list|(
name|void
modifier|*
modifier|*
name|out
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|apr_size_t
name|data_len
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Implements svn_cache__serialize_func_t for apr_array_header_t objects  * with elements of type svn_fs_x__p2l_entry_t.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_x__serialize_p2l_page
parameter_list|(
name|void
modifier|*
modifier|*
name|data
parameter_list|,
name|apr_size_t
modifier|*
name|data_len
parameter_list|,
name|void
modifier|*
name|in
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Implements svn_cache__deserialize_func_t for apr_array_header_t objects  * with elements of type svn_fs_x__p2l_entry_t.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_x__deserialize_p2l_page
parameter_list|(
name|void
modifier|*
modifier|*
name|out
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|apr_size_t
name|data_len
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

