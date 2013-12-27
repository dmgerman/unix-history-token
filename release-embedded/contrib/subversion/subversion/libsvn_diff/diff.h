begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * diff.h :  private header file  *  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DIFF_H
argument_list|)
end_if

begin_define
define|#
directive|define
name|DIFF_H
end_define

begin_include
include|#
directive|include
file|<apr.h>
end_include

begin_include
include|#
directive|include
file|<apr_pools.h>
end_include

begin_include
include|#
directive|include
file|<apr_general.h>
end_include

begin_include
include|#
directive|include
file|"svn_diff.h"
end_include

begin_include
include|#
directive|include
file|"svn_types.h"
end_include

begin_define
define|#
directive|define
name|SVN_DIFF__UNIFIED_CONTEXT_SIZE
value|3
end_define

begin_typedef
typedef|typedef
name|struct
name|svn_diff__node_t
name|svn_diff__node_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|svn_diff__tree_t
name|svn_diff__tree_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|svn_diff__position_t
name|svn_diff__position_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|svn_diff__lcs_t
name|svn_diff__lcs_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
name|svn_diff__type_e
block|{
name|svn_diff__type_common
block|,
name|svn_diff__type_diff_modified
block|,
name|svn_diff__type_diff_latest
block|,
name|svn_diff__type_diff_common
block|,
name|svn_diff__type_conflict
block|}
name|svn_diff__type_e
typedef|;
end_typedef

begin_struct
struct|struct
name|svn_diff_t
block|{
name|svn_diff_t
modifier|*
name|next
decl_stmt|;
name|svn_diff__type_e
name|type
decl_stmt|;
name|apr_off_t
name|original_start
decl_stmt|;
name|apr_off_t
name|original_length
decl_stmt|;
name|apr_off_t
name|modified_start
decl_stmt|;
name|apr_off_t
name|modified_length
decl_stmt|;
name|apr_off_t
name|latest_start
decl_stmt|;
name|apr_off_t
name|latest_length
decl_stmt|;
name|svn_diff_t
modifier|*
name|resolved_diff
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Type used for token indices and counts of tokens. Must be signed. */
end_comment

begin_typedef
typedef|typedef
name|long
name|int
name|svn_diff__token_index_t
typedef|;
end_typedef

begin_struct
struct|struct
name|svn_diff__position_t
block|{
name|svn_diff__position_t
modifier|*
name|next
decl_stmt|;
name|svn_diff__token_index_t
name|token_index
decl_stmt|;
name|apr_off_t
name|offset
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|svn_diff__lcs_t
block|{
name|svn_diff__lcs_t
modifier|*
name|next
decl_stmt|;
name|svn_diff__position_t
modifier|*
name|position
index|[
literal|2
index|]
decl_stmt|;
name|apr_off_t
name|length
decl_stmt|;
name|int
name|refcount
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* State used when normalizing whitespace and EOL styles. */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|svn_diff__normalize_state_t
block|{
comment|/* Initial state; not in a sequence of whitespace. */
name|svn_diff__normalize_state_normal
block|,
comment|/* We're in a sequence of whitespace characters.  Only entered if      we ignore whitespace. */
name|svn_diff__normalize_state_whitespace
block|,
comment|/* The previous character was CR. */
name|svn_diff__normalize_state_cr
block|}
name|svn_diff__normalize_state_t
typedef|;
end_typedef

begin_comment
comment|/*  * Calculate the Longest Common Subsequence (LCS) between two datasources  * POSITION_LIST1 and POSITION_LIST2, with TOKEN_COUNTS_LIST1 and  * TOKEN_COUNTS_LIST2 the corresponding counts of the different tokens  * (indexed by the 'token_index' of the positions of each position_list).  *  * From the beginning of each list, PREFIX_LINES lines will be assumed to be  * equal and be excluded from the comparison process. Similarly, SUFFIX_LINES  * at the end of both sequences will be skipped.  *  * The resulting lcs structure will be the return value of this function.  * Allocations will be made from POOL.  */
end_comment

begin_function_decl
name|svn_diff__lcs_t
modifier|*
name|svn_diff__lcs
parameter_list|(
name|svn_diff__position_t
modifier|*
name|position_list1
parameter_list|,
comment|/* pointer to tail (ring) */
name|svn_diff__position_t
modifier|*
name|position_list2
parameter_list|,
comment|/* pointer to tail (ring) */
name|svn_diff__token_index_t
modifier|*
name|token_counts_list1
parameter_list|,
comment|/* array of counts */
name|svn_diff__token_index_t
modifier|*
name|token_counts_list2
parameter_list|,
comment|/* array of counts */
name|svn_diff__token_index_t
name|num_tokens
parameter_list|,
comment|/* length of count arrays */
name|apr_off_t
name|prefix_lines
parameter_list|,
name|apr_off_t
name|suffix_lines
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Returns number of tokens in a tree  */
end_comment

begin_function_decl
name|svn_diff__token_index_t
name|svn_diff__get_node_count
parameter_list|(
name|svn_diff__tree_t
modifier|*
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Support functions to build a tree of token positions  */
end_comment

begin_function_decl
name|void
name|svn_diff__tree_create
parameter_list|(
name|svn_diff__tree_t
modifier|*
modifier|*
name|tree
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Get all tokens from a datasource.  Return the  * last item in the (circular) list.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_diff__get_tokens
parameter_list|(
name|svn_diff__position_t
modifier|*
modifier|*
name|position_list
parameter_list|,
name|svn_diff__tree_t
modifier|*
name|tree
parameter_list|,
name|void
modifier|*
name|diff_baton
parameter_list|,
specifier|const
name|svn_diff_fns2_t
modifier|*
name|vtable
parameter_list|,
name|svn_diff_datasource_e
name|datasource
parameter_list|,
name|apr_off_t
name|prefix_lines
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Returns an array with the counts for the tokens in  * the looped linked list given in loop_start.  * num_tokens equals the highest possible token index +1.  */
end_comment

begin_function_decl
name|svn_diff__token_index_t
modifier|*
name|svn_diff__get_token_counts
parameter_list|(
name|svn_diff__position_t
modifier|*
name|loop_start
parameter_list|,
name|svn_diff__token_index_t
name|num_tokens
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Morph a svn_lcs_t into a svn_diff_t. */
end_comment

begin_function_decl
name|svn_diff_t
modifier|*
name|svn_diff__diff
parameter_list|(
name|svn_diff__lcs_t
modifier|*
name|lcs
parameter_list|,
name|apr_off_t
name|original_start
parameter_list|,
name|apr_off_t
name|modified_start
parameter_list|,
name|svn_boolean_t
name|want_common
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|svn_diff__resolve_conflict
parameter_list|(
name|svn_diff_t
modifier|*
name|hunk
parameter_list|,
name|svn_diff__position_t
modifier|*
modifier|*
name|position_list1
parameter_list|,
name|svn_diff__position_t
modifier|*
modifier|*
name|position_list2
parameter_list|,
name|svn_diff__token_index_t
name|num_tokens
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Normalize the characters pointed to by the buffer BUF (of length *LENGTHP)  * according to the options *OPTS, starting in the state *STATEP.  *  * Adjust *LENGTHP and *STATEP to be the length of the normalized buffer and  * the final state, respectively.  * Normalized data is written to the memory at *TGT. BUF and TGT may point  * to the same memory area.  The memory area pointed to by *TGT should be  * large enough to hold *LENGTHP bytes.  * When on return *TGT is not equal to the value passed in, it points somewhere  * into the memory region designated by BUF and *LENGTHP.  */
end_comment

begin_function_decl
name|void
name|svn_diff__normalize_buffer
parameter_list|(
name|char
modifier|*
modifier|*
name|tgt
parameter_list|,
name|apr_off_t
modifier|*
name|lengthp
parameter_list|,
name|svn_diff__normalize_state_t
modifier|*
name|statep
parameter_list|,
specifier|const
name|char
modifier|*
name|buf
parameter_list|,
specifier|const
name|svn_diff_file_options_t
modifier|*
name|opts
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Set *OUT_STR to a newline followed by a "\ No newline at end of file" line.  *  * The text will be encoded into HEADER_ENCODING.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_diff__unified_append_no_newline_msg
parameter_list|(
name|svn_stringbuf_t
modifier|*
name|stringbuf
parameter_list|,
specifier|const
name|char
modifier|*
name|header_encoding
parameter_list|,
name|apr_pool_t
modifier|*
name|scratch_pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Write a unidiff hunk header to OUTPUT_STREAM.  *  * The header will use HUNK_DELIMITER (which should usually be "@@") before  * and after the line-number ranges which are formed from OLD_START,  * OLD_LENGTH, NEW_START and NEW_LENGTH.  If HUNK_EXTRA_CONTEXT is not NULL,  * it will be written after the final delimiter, with an intervening space.  *  * The text will be encoded into HEADER_ENCODING.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_diff__unified_write_hunk_header
parameter_list|(
name|svn_stream_t
modifier|*
name|output_stream
parameter_list|,
specifier|const
name|char
modifier|*
name|header_encoding
parameter_list|,
specifier|const
name|char
modifier|*
name|hunk_delimiter
parameter_list|,
name|apr_off_t
name|old_start
parameter_list|,
name|apr_off_t
name|old_length
parameter_list|,
name|apr_off_t
name|new_start
parameter_list|,
name|apr_off_t
name|new_length
parameter_list|,
specifier|const
name|char
modifier|*
name|hunk_extra_context
parameter_list|,
name|apr_pool_t
modifier|*
name|scratch_pool
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DIFF_H */
end_comment

end_unit

