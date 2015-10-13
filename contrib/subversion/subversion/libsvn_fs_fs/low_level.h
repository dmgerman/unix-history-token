begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* low_level.c --- low level r/w access to fs_fs file structures  *  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  */
end_comment

begin_include
include|#
directive|include
file|"svn_fs.h"
end_include

begin_include
include|#
directive|include
file|"fs_fs.h"
end_include

begin_include
include|#
directive|include
file|"id.h"
end_include

begin_comment
comment|/* Kinds that a node-rev can be. */
end_comment

begin_define
define|#
directive|define
name|SVN_FS_FS__KIND_FILE
value|"file"
end_define

begin_define
define|#
directive|define
name|SVN_FS_FS__KIND_DIR
value|"dir"
end_define

begin_comment
comment|/* The functions are grouped as follows:  *  * - revision trailer (up to format 6)  * - revision footer (since format 7)  * - changed path list  * - node revision  * - representation (as in "text:" and "props:" lines)  * - representation header ("PLAIN" and "DELTA" lines)  */
end_comment

begin_comment
comment|/* Given the last "few" bytes (should be at least 40) of revision REV in  * TRAILER,  parse the last line and return the offset of the root noderev  * in *ROOT_OFFSET and the offset of the changed paths list in  * *CHANGES_OFFSET.  Offsets are relative to the revision's start offset.  * ROOT_OFFSET and / or CHANGES_OFFSET may be NULL.  *  * Note that REV is only used to construct nicer error objects.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_fs__parse_revision_trailer
parameter_list|(
name|apr_off_t
modifier|*
name|root_offset
parameter_list|,
name|apr_off_t
modifier|*
name|changes_offset
parameter_list|,
name|svn_stringbuf_t
modifier|*
name|trailer
parameter_list|,
name|svn_revnum_t
name|rev
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Given the offset of the root noderev in ROOT_OFFSET and the offset of  * the changed paths list in CHANGES_OFFSET,  return the corresponding  * revision's trailer.  Allocate it in RESULT_POOL.  */
end_comment

begin_function_decl
name|svn_stringbuf_t
modifier|*
name|svn_fs_fs__unparse_revision_trailer
parameter_list|(
name|apr_off_t
name|root_offset
parameter_list|,
name|apr_off_t
name|changes_offset
parameter_list|,
name|apr_pool_t
modifier|*
name|result_pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Given the format 7+ revision / pack FOOTER, parse it destructively  * and return the start offsets of the index data in *L2P_OFFSET and  * *P2L_OFFSET, respectively.  Also, return the expected checksums in  * in *L2P_CHECKSUM and *P2L_CHECKSUM.  *  * Note that REV is only used to construct nicer error objects that  * mention this revision.  Allocate the checksums in RESULT_POOL.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_fs__parse_footer
parameter_list|(
name|apr_off_t
modifier|*
name|l2p_offset
parameter_list|,
name|svn_checksum_t
modifier|*
modifier|*
name|l2p_checksum
parameter_list|,
name|apr_off_t
modifier|*
name|p2l_offset
parameter_list|,
name|svn_checksum_t
modifier|*
modifier|*
name|p2l_checksum
parameter_list|,
name|svn_stringbuf_t
modifier|*
name|footer
parameter_list|,
name|svn_revnum_t
name|rev
parameter_list|,
name|apr_pool_t
modifier|*
name|result_pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Given the offset of the L2P index data in L2P_OFFSET, the content  * checksum in L2P_CHECKSUM and the offset plus checksum of the P2L  * index data in P2L_OFFSET and P2L_CHECKSUM.  *  * Return the corresponding format 7+ revision / pack file footer.  * Allocate it in RESULT_POOL and use SCRATCH_POOL for temporary.  */
end_comment

begin_function_decl
name|svn_stringbuf_t
modifier|*
name|svn_fs_fs__unparse_footer
parameter_list|(
name|apr_off_t
name|l2p_offset
parameter_list|,
name|svn_checksum_t
modifier|*
name|l2p_checksum
parameter_list|,
name|apr_off_t
name|p2l_offset
parameter_list|,
name|svn_checksum_t
modifier|*
name|p2l_checksum
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
comment|/* Read all the changes from STREAM and store them in *CHANGES,    allocated in RESULT_POOL. Do temporary allocations in SCRATCH_POOL. */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_fs__read_changes
parameter_list|(
name|apr_array_header_t
modifier|*
modifier|*
name|changes
parameter_list|,
name|svn_stream_t
modifier|*
name|stream
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
comment|/* Callback function used by svn_fs_fs__read_changes_incrementally(),  * asking the receiver to process to process CHANGE using BATON.  CHANGE  * and SCRATCH_POOL will not be valid beyond the current callback invocation.  */
end_comment

begin_typedef
typedef|typedef
name|svn_error_t
modifier|*
function_decl|(
modifier|*
name|svn_fs_fs__change_receiver_t
function_decl|)
parameter_list|(
name|void
modifier|*
name|baton
parameter_list|,
name|change_t
modifier|*
name|change
parameter_list|,
name|apr_pool_t
modifier|*
name|scratch_pool
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* Read all the changes from STREAM and invoke CHANGE_RECEIVER on each change.    Do all allocations in SCRATCH_POOL. */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_fs__read_changes_incrementally
parameter_list|(
name|svn_stream_t
modifier|*
name|stream
parameter_list|,
name|svn_fs_fs__change_receiver_t
name|change_receiver
parameter_list|,
name|void
modifier|*
name|change_receiver_baton
parameter_list|,
name|apr_pool_t
modifier|*
name|scratch_pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Write the changed path info from CHANGES in filesystem FS to the    output stream STREAM.  You may call this function multiple time on    the same stream.  If you are writing to a (proto-)revision file,    the last call must set TERMINATE_LIST to write an extra empty line    that marks the end of the changed paths list.    Perform temporary allocations in SCRATCH_POOL.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_fs__write_changes
parameter_list|(
name|svn_stream_t
modifier|*
name|stream
parameter_list|,
name|svn_fs_t
modifier|*
name|fs
parameter_list|,
name|apr_hash_t
modifier|*
name|changes
parameter_list|,
name|svn_boolean_t
name|terminate_list
parameter_list|,
name|apr_pool_t
modifier|*
name|scratch_pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Read a node-revision from STREAM. Set *NODEREV to the new structure,    allocated in RESULT_POOL. */
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
name|result_pool
parameter_list|,
name|apr_pool_t
modifier|*
name|scratch_pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Write the node-revision NODEREV into the stream OUTFILE, compatible with    filesystem format FORMAT.  Only write mergeinfo-related metadata if    INCLUDE_MERGEINFO is true.  Temporary allocations are from SCRATCH_POOL. */
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
name|scratch_pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Parse the description of a representation from TEXT and store it    into *REP_P.  TEXT will be invalidated by this call.  Allocate *REP_P in    RESULT_POOL and use SCRATCH_POOL for temporaries. */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_fs__parse_representation
parameter_list|(
name|representation_t
modifier|*
modifier|*
name|rep_p
parameter_list|,
name|svn_stringbuf_t
modifier|*
name|text
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
comment|/* Return a formatted string, compatible with filesystem format FORMAT,    that represents the location of representation REP.  If    MUTABLE_REP_TRUNCATED is given, the rep is for props or dir contents,    and only a "-1" revision number will be given for a mutable rep.    If MAY_BE_CORRUPT is true, guard for NULL when constructing the string.    Allocate the result in RESULT_POOL and temporaries in SCRATCH_POOL. */
end_comment

begin_function_decl
name|svn_stringbuf_t
modifier|*
name|svn_fs_fs__unparse_representation
parameter_list|(
name|representation_t
modifier|*
name|rep
parameter_list|,
name|int
name|format
parameter_list|,
name|svn_boolean_t
name|mutable_rep_truncated
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
comment|/* This type enumerates all forms of representations that we support. */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|svn_fs_fs__rep_type_t
block|{
comment|/* this is a PLAIN representation */
name|svn_fs_fs__rep_plain
block|,
comment|/* this is a DELTA representation with no base representation */
name|svn_fs_fs__rep_self_delta
block|,
comment|/* this is a DELTA representation against some base representation */
name|svn_fs_fs__rep_delta
block|}
name|svn_fs_fs__rep_type_t
typedef|;
end_typedef

begin_comment
comment|/* This structure is used to hold the information stored in a representation  * header. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|svn_fs_fs__rep_header_t
block|{
comment|/* type of the representation, i.e. whether it is PLAIN, self-DELTA etc. */
name|svn_fs_fs__rep_type_t
name|type
decl_stmt|;
comment|/* if this rep is a delta against some other rep, that base rep can    * be found in this revision.  Should be 0 if there is no base rep. */
name|svn_revnum_t
name|base_revision
decl_stmt|;
comment|/* if this rep is a delta against some other rep, that base rep can    * be found at this item index within the base rep's revision.  Should    * be 0 if there is no base rep. */
name|apr_off_t
name|base_item_index
decl_stmt|;
comment|/* if this rep is a delta against some other rep, this is the (deltified)    * size of that base rep.  Should be 0 if there is no base rep. */
name|svn_filesize_t
name|base_length
decl_stmt|;
comment|/* length of the textual representation of the header in the rep or pack    * file, including EOL.  Only valid after reading it from disk.    * Should be 0 otherwise. */
name|apr_size_t
name|header_size
decl_stmt|;
block|}
name|svn_fs_fs__rep_header_t
typedef|;
end_typedef

begin_comment
comment|/* Read the next line from STREAM and parse it as a text    representation header.  Return the parsed entry in *HEADER, allocated    in RESULT_POOL. Perform temporary allocations in SCRATCH_POOL. */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_fs__read_rep_header
parameter_list|(
name|svn_fs_fs__rep_header_t
modifier|*
modifier|*
name|header
parameter_list|,
name|svn_stream_t
modifier|*
name|stream
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
comment|/* Write the representation HEADER to STREAM.  * Use SCRATCH_POOL for temporary allocations. */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_fs__write_rep_header
parameter_list|(
name|svn_fs_fs__rep_header_t
modifier|*
name|header
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

end_unit

