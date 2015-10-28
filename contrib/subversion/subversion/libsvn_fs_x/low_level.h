begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* low_level.c --- low level r/w access to fs_x file structures  *  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_LIBSVN_FS__LOW_LEVEL_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_LIBSVN_FS__LOW_LEVEL_H
end_define

begin_include
include|#
directive|include
file|"svn_fs.h"
end_include

begin_include
include|#
directive|include
file|"fs_x.h"
end_include

begin_include
include|#
directive|include
file|"id.h"
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
comment|/* Kinds that a node-rev can be. */
define|#
directive|define
name|SVN_FS_X__KIND_FILE
value|"file"
define|#
directive|define
name|SVN_FS_X__KIND_DIR
value|"dir"
comment|/* The functions are grouped as follows:  *  * - revision footer  * - representation (as in "text:" and "props:" lines)  * - node revision  * - representation header ("DELTA" lines)  * - changed path list  */
comment|/* Given the FSX revision / pack FOOTER, parse it destructively  * and return the start offsets of the index data in *L2P_OFFSET and  * *P2L_OFFSET, respectively.  Also, return the expected checksums in  * in *L2P_CHECKSUM and *P2L_CHECKSUM.  *  * Note that REV is only used to construct nicer error objects that  * mention this revision.  Allocate the checksums in RESULT_POOL.  */
name|svn_error_t
modifier|*
name|svn_fs_x__parse_footer
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
comment|/* Given the offset of the L2P index data in L2P_OFFSET, the content  * checksum in L2P_CHECKSUM and the offset plus checksum of the P2L  * index data in P2L_OFFSET and P2L_CHECKSUM.  *  * Return the corresponding format 7+ revision / pack file footer.  * Allocate it in RESULT_POOL and use SCRATCH_POOL for temporary.  */
name|svn_stringbuf_t
modifier|*
name|svn_fs_x__unparse_footer
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
comment|/* Parse the description of a representation from TEXT and store it    into *REP_P.  TEXT will be invalidated by this call.  Allocate *REP_P in    RESULT_POOL and use SCRATCH_POOL for temporaries. */
name|svn_error_t
modifier|*
name|svn_fs_x__parse_representation
parameter_list|(
name|svn_fs_x__representation_t
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
comment|/* Return a formatted string that represents the location of representation  * REP.  If MUTABLE_REP_TRUNCATED is given, the rep is for props or dir  * contents, and only a "-1" revision number will be given for a mutable rep.  * If MAY_BE_CORRUPT is true, guard for NULL when constructing the string.  * Allocate the result in RESULT_POOL and temporaries in SCRATCH_POOL. */
name|svn_stringbuf_t
modifier|*
name|svn_fs_x__unparse_representation
parameter_list|(
name|svn_fs_x__representation_t
modifier|*
name|rep
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
comment|/* Read a node-revision from STREAM. Set *NODEREV to the new structure,    allocated in RESULT_POOL. */
name|svn_error_t
modifier|*
name|svn_fs_x__read_noderev
parameter_list|(
name|svn_fs_x__noderev_t
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
comment|/* Write the node-revision NODEREV into the stream OUTFILE.    Temporary allocations are from SCRATCH_POOL. */
name|svn_error_t
modifier|*
name|svn_fs_x__write_noderev
parameter_list|(
name|svn_stream_t
modifier|*
name|outfile
parameter_list|,
name|svn_fs_x__noderev_t
modifier|*
name|noderev
parameter_list|,
name|apr_pool_t
modifier|*
name|scratch_pool
parameter_list|)
function_decl|;
comment|/* This type enumerates all forms of representations that we support. */
typedef|typedef
enum|enum
name|svn_fs_x__rep_type_t
block|{
comment|/* this is a DELTA representation with no base representation */
name|svn_fs_x__rep_self_delta
block|,
comment|/* this is a DELTA representation against some base representation */
name|svn_fs_x__rep_delta
block|,
comment|/* this is a representation in a star-delta container */
name|svn_fs_x__rep_container
block|}
name|svn_fs_x__rep_type_t
typedef|;
comment|/* This structure is used to hold the information stored in a representation  * header. */
typedef|typedef
struct|struct
name|svn_fs_x__rep_header_t
block|{
comment|/* type of the representation, i.e. whether self-DELTA etc. */
name|svn_fs_x__rep_type_t
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
name|svn_fs_x__rep_header_t
typedef|;
comment|/* Read the next line from STREAM and parse it as a text    representation header.  Return the parsed entry in *HEADER, allocated    in RESULT_POOL. Perform temporary allocations in SCRATCH_POOL. */
name|svn_error_t
modifier|*
name|svn_fs_x__read_rep_header
parameter_list|(
name|svn_fs_x__rep_header_t
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
comment|/* Write the representation HEADER to STREAM.  * Use SCRATCH_POOL for allocations. */
name|svn_error_t
modifier|*
name|svn_fs_x__write_rep_header
parameter_list|(
name|svn_fs_x__rep_header_t
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
comment|/* Read all the changes from STREAM and store them in *CHANGES,    allocated in RESULT_POOL. Do temporary allocations in SCRATCH_POOL. */
name|svn_error_t
modifier|*
name|svn_fs_x__read_changes
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
comment|/* Callback function used by svn_fs_fs__read_changes_incrementally(),  * asking the receiver to process to process CHANGE using BATON.  CHANGE  * and SCRATCH_POOL will not be valid beyond the current callback invocation.  */
typedef|typedef
name|svn_error_t
modifier|*
function_decl|(
modifier|*
name|svn_fs_x__change_receiver_t
function_decl|)
parameter_list|(
name|void
modifier|*
name|baton
parameter_list|,
name|svn_fs_x__change_t
modifier|*
name|change
parameter_list|,
name|apr_pool_t
modifier|*
name|scratch_pool
parameter_list|)
function_decl|;
comment|/* Read all the changes from STREAM and invoke CHANGE_RECEIVER on each change.    Do all allocations in SCRATCH_POOL. */
name|svn_error_t
modifier|*
name|svn_fs_x__read_changes_incrementally
parameter_list|(
name|svn_stream_t
modifier|*
name|stream
parameter_list|,
name|svn_fs_x__change_receiver_t
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
comment|/* Write the changed path info from CHANGES in filesystem FS to the    output stream STREAM.  You may call this function multiple time on    the same stream.  If you are writing to a (proto-)revision file,    the last call must set TERMINATE_LIST to write an extra empty line    that marks the end of the changed paths list.    Perform temporary allocations in SCRATCH_POOL.  */
name|svn_error_t
modifier|*
name|svn_fs_x__write_changes
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
comment|/* SVN_LIBSVN_FS__LOW_LEVEL_H */
end_comment

end_unit

