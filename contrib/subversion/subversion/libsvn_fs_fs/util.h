begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* util.h --- utility functions for FSFS repo access  *  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_LIBSVN_FS__UTIL_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_LIBSVN_FS__UTIL_H
end_define

begin_include
include|#
directive|include
file|"svn_fs.h"
end_include

begin_include
include|#
directive|include
file|"id.h"
end_include

begin_comment
comment|/* Functions for dealing with recoverable errors on mutable files  *  * Revprops, current, and txn-current files are mutable; that is, they  * change as part of normal fsfs operation, in constrat to revs files, or  * the format file, which are written once at create (or upgrade) time.  * When more than one host writes to the same repository, we will  * sometimes see these recoverable errors when accesssing these files.  *  * These errors all relate to NFS, and thus we only use this retry code if  * ESTALE is defined.  *  ** ESTALE  *  * In NFS v3 and under, the server doesn't track opened files.  If you  * unlink(2) or rename(2) a file held open by another process *on the  * same host*, that host's kernel typically renames the file to  * .nfsXXXX and automatically deletes that when it's no longer open,  * but this behavior is not required.  *  * For obvious reasons, this does not work *across hosts*.  No one  * knows about the opened file; not the server, and not the deleting  * client.  So the file vanishes, and the reader gets stale NFS file  * handle.  *  ** EIO, ENOENT  *  * Some client implementations (at least the 2.6.18.5 kernel that ships  * with Ubuntu Dapper) sometimes give spurious ENOENT (only on open) or  * even EIO errors when trying to read these files that have been renamed  * over on some other host.  *  ** Solution  *  * Try open and read of such files in try_stringbuf_from_file().  Call  * this function within a loop of SVN_FS_FS__RECOVERABLE_RETRY_COUNT  * iterations (though, realistically, the second try will succeed).  */
end_comment

begin_define
define|#
directive|define
name|SVN_FS_FS__RECOVERABLE_RETRY_COUNT
value|10
end_define

begin_comment
comment|/* Return TRUE is REV is packed in FS, FALSE otherwise. */
end_comment

begin_function_decl
name|svn_boolean_t
name|svn_fs_fs__is_packed_rev
parameter_list|(
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
name|svn_revnum_t
name|rev
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return TRUE is REV's props have been packed in FS, FALSE otherwise. */
end_comment

begin_function_decl
name|svn_boolean_t
name|svn_fs_fs__is_packed_revprop
parameter_list|(
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
name|svn_revnum_t
name|rev
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return the first revision in the pack / rev file containing REVISION in  * filesystem FS.  For non-packed revs, this will simply be REVISION. */
end_comment

begin_function_decl
name|svn_revnum_t
name|svn_fs_fs__packed_base_rev
parameter_list|(
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
name|svn_revnum_t
name|revision
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return the full path of the rev shard directory that will contain  * revision REV in FS.  Allocate the result in POOL.  */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|svn_fs_fs__path_rev_shard
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
end_function_decl

begin_comment
comment|/* Return the full path of the non-packed rev file containing revision REV  * in FS.  Allocate the result in POOL.  */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|svn_fs_fs__path_rev
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
end_function_decl

begin_comment
comment|/* Return the path of the pack-related file that for revision REV in FS.  * KIND specifies the file name base, e.g. "manifest" or "pack".  * The result will be allocated in POOL.  */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|svn_fs_fs__path_rev_packed
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
name|kind
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return the full path of the "txn-current" file in FS.  * The result will be allocated in POOL.  */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|svn_fs_fs__path_txn_current
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
comment|/* Return the full path of the "txn-current-lock" file in FS.  * The result will be allocated in POOL.  */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|svn_fs_fs__path_txn_current_lock
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
comment|/* Return the full path of the global write lock file in FS.  * The result will be allocated in POOL.  */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|svn_fs_fs__path_lock
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
comment|/* Return the full path of the pack operation lock file in FS.  * The result will be allocated in POOL.  */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|svn_fs_fs__path_pack_lock
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
comment|/* Return the full path of the revprop generation file in FS.  * Allocate the result in POOL.  */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|svn_fs_fs__path_revprop_generation
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
comment|/* Return the full path of the revision properties pack shard directory  * that will contain the packed properties of revision REV in FS.  * Allocate the result in POOL.  */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|svn_fs_fs__path_revprops_pack_shard
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
end_function_decl

begin_comment
comment|/* Set *PATH to the path of REV in FS, whether in a pack file or not.    Allocate *PATH in POOL.     Note: If the caller does not have the write lock on FS, then the path is    not guaranteed to be correct or to remain correct after the function    returns, because the revision might become packed before or after this    call.  If a file exists at that path, then it is correct; if not, then    the caller should call update_min_unpacked_rev() and re-try once. */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|svn_fs_fs__path_rev_absolute
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
end_function_decl

begin_comment
comment|/* Return the full path of the revision properties shard directory that  * will contain the properties of revision REV in FS.  * Allocate the result in POOL.  */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|svn_fs_fs__path_revprops_shard
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
end_function_decl

begin_comment
comment|/* Return the full path of the non-packed revision properties file that  * contains the props for revision REV in FS.  Allocate the result in POOL.  */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|svn_fs_fs__path_revprops
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
end_function_decl

begin_comment
comment|/* Return the path of the file storing the oldest non-packed revision in FS.  * The result will be allocated in POOL.  */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|svn_fs_fs__path_min_unpacked_rev
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
comment|/* Return the path of the 'transactions' directory in FS.  * The result will be allocated in POOL.  */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|svn_fs_fs__path_txns_dir
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
comment|/* Return the path of the directory containing the transaction TXN_ID in FS.  * The result will be allocated in POOL.  */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|svn_fs_fs__path_txn_dir
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
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return the path of the 'txn-protorevs' directory in FS, even if that  * folder may not exist in FS.  The result will be allocated in POOL.  */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|svn_fs_fs__path_txn_proto_revs
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
comment|/* Return the path of the proto-revision file for transaction TXN_ID in FS.  * The result will be allocated in POOL.  */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|svn_fs_fs__path_txn_proto_rev
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
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return the path of the proto-revision lock file for transaction TXN_ID  * in FS.  The result will be allocated in POOL.  */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|svn_fs_fs__path_txn_proto_rev_lock
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
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return the path of the file containing the in-transaction node revision  * identified by ID in FS.  The result will be allocated in POOL.  */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|svn_fs_fs__path_txn_node_rev
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
comment|/* Return the path of the file containing the in-transaction properties of  * the node identified by ID in FS.  The result will be allocated in POOL.  */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|svn_fs_fs__path_txn_node_props
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
comment|/* Return the path of the file containing the directory entries of the  * in-transaction directory node identified by ID in FS.  * The result will be allocated in POOL.  */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|svn_fs_fs__path_txn_node_children
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
comment|/* Return the path of the file containing the log-to-phys index for  * the transaction identified by TXN_ID in FS.  * The result will be allocated in POOL.  */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|svn_fs_fs__path_l2p_proto_index
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
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return the path of the file containing the phys-to-log index for  * the transaction identified by TXN_ID in FS.  * The result will be allocated in POOL.  */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|svn_fs_fs__path_p2l_proto_index
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
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return the path of the file containing item_index counter for  * the transaction identified by TXN_ID in FS.  * The result will be allocated in POOL.  */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|svn_fs_fs__path_txn_item_index
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
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return the path of the file containing the node origins cachs for  * the given NODE_ID in FS.  The result will be allocated in POOL.  */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|svn_fs_fs__path_node_origin
parameter_list|(
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
specifier|const
name|svn_fs_fs__id_part_t
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
comment|/* Set *MIN_UNPACKED_REV to the integer value read from the file returned  * by #svn_fs_fs__path_min_unpacked_rev() for FS.  * Use POOL for temporary allocations.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_fs__read_min_unpacked_rev
parameter_list|(
name|svn_revnum_t
modifier|*
name|min_unpacked_rev
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
comment|/* Check that BUF, a nul-terminated buffer of text from file PATH,    contains only digits at OFFSET and beyond, raising an error if not.    TITLE contains a user-visible description of the file, usually the    short file name.     Uses POOL for temporary allocation. */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_fs__check_file_buffer_numeric
parameter_list|(
specifier|const
name|char
modifier|*
name|buf
parameter_list|,
name|apr_off_t
name|offset
parameter_list|,
specifier|const
name|char
modifier|*
name|path
parameter_list|,
specifier|const
name|char
modifier|*
name|title
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Re-read the MIN_UNPACKED_REV member of FS from disk.  * Use POOL for temporary allocations.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_fs__update_min_unpacked_rev
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
comment|/* Atomically update the 'min-unpacked-rev' file in FS to hold the specifed  * REVNUM.  Perform temporary allocations in SCRATCH_POOL.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_fs__write_min_unpacked_rev
parameter_list|(
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
name|svn_revnum_t
name|revnum
parameter_list|,
name|apr_pool_t
modifier|*
name|scratch_pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Set *REV, *NEXT_NODE_ID and *NEXT_COPY_ID to the values read from the  * 'current' file.  For new FS formats, which only store the youngest  * revision, set the *NEXT_NODE_ID and *NEXT_COPY_ID to 0.  Perform  * temporary allocations in POOL.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_fs__read_current
parameter_list|(
name|svn_revnum_t
modifier|*
name|rev
parameter_list|,
name|apr_uint64_t
modifier|*
name|next_node_id
parameter_list|,
name|apr_uint64_t
modifier|*
name|next_copy_id
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
comment|/* Atomically update the 'current' file to hold the specifed REV,    NEXT_NODE_ID, and NEXT_COPY_ID.  (The two next-ID parameters are    ignored and may be 0 if the FS format does not use them.)    Perform temporary allocations in POOL. */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_fs__write_current
parameter_list|(
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
name|svn_revnum_t
name|rev
parameter_list|,
name|apr_uint64_t
name|next_node_id
parameter_list|,
name|apr_uint64_t
name|next_copy_id
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Read the file at PATH and return its content in *CONTENT. *CONTENT will  * not be modified unless the whole file was read successfully.  *  * ESTALE, EIO and ENOENT will not cause this function to return an error  * unless LAST_ATTEMPT has been set.  If MISSING is not NULL, indicate  * missing files (ENOENT) there.  *  * Use POOL for allocations.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_fs__try_stringbuf_from_file
parameter_list|(
name|svn_stringbuf_t
modifier|*
modifier|*
name|content
parameter_list|,
name|svn_boolean_t
modifier|*
name|missing
parameter_list|,
specifier|const
name|char
modifier|*
name|path
parameter_list|,
name|svn_boolean_t
name|last_attempt
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Fetch the current offset of FILE into *OFFSET_P. */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_fs__get_file_offset
parameter_list|(
name|apr_off_t
modifier|*
name|offset_p
parameter_list|,
name|apr_file_t
modifier|*
name|file
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Read the file FNAME and store the contents in *BUF.    Allocations are performed in POOL. */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_fs__read_content
parameter_list|(
name|svn_stringbuf_t
modifier|*
modifier|*
name|content
parameter_list|,
specifier|const
name|char
modifier|*
name|fname
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Reads a line from STREAM and converts it to a 64 bit integer to be  * returned in *RESULT.  If we encounter eof, set *HIT_EOF and leave  * *RESULT unchanged.  If HIT_EOF is NULL, EOF causes an "corrupt FS"  * error return.  * SCRATCH_POOL is used for temporary allocations.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_fs__read_number_from_stream
parameter_list|(
name|apr_int64_t
modifier|*
name|result
parameter_list|,
name|svn_boolean_t
modifier|*
name|hit_eof
parameter_list|,
name|svn_stream_t
modifier|*
name|stream
parameter_list|,
name|apr_pool_t
modifier|*
name|scratch_pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Move a file into place from OLD_FILENAME in the transactions    directory to its final location NEW_FILENAME in the repository.  On    Unix, match the permissions of the new file to the permissions of    PERMS_REFERENCE.  Temporary allocations are from POOL.     This function almost duplicates svn_io_file_move(), but it tries to    guarantee a flush. */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_fs__move_into_place
parameter_list|(
specifier|const
name|char
modifier|*
name|old_filename
parameter_list|,
specifier|const
name|char
modifier|*
name|new_filename
parameter_list|,
specifier|const
name|char
modifier|*
name|perms_reference
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return TRUE, iff FS uses logical addressing. */
end_comment

begin_function_decl
name|svn_boolean_t
name|svn_fs_fs__use_log_addressing
parameter_list|(
name|svn_fs_t
modifier|*
name|fs
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

