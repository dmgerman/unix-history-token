begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* temp_serializer.h : serialization functions for caching of FSX structures  *  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_LIBSVN_FS__TEMP_SERIALIZER_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_LIBSVN_FS__TEMP_SERIALIZER_H
end_define

begin_include
include|#
directive|include
file|"private/svn_temp_serializer.h"
end_include

begin_include
include|#
directive|include
file|"fs.h"
end_include

begin_comment
comment|/**  * Prepend the @a number to the @a string in a space efficient way such that  * no other (number,string) combination can produce the same result.  * Allocate temporaries as well as the result from @a pool.  */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|svn_fs_x__combine_number_and_string
parameter_list|(
name|apr_int64_t
name|number
parameter_list|,
specifier|const
name|char
modifier|*
name|string
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Serialize a @a noderev_p within the serialization @a context.  */
end_comment

begin_function_decl
name|void
name|svn_fs_x__noderev_serialize
parameter_list|(
name|struct
name|svn_temp_serializer__context_t
modifier|*
name|context
parameter_list|,
name|svn_fs_x__noderev_t
modifier|*
specifier|const
modifier|*
name|noderev_p
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Deserialize a @a noderev_p within the @a buffer and associate it with  * @a pool.  */
end_comment

begin_function_decl
name|void
name|svn_fs_x__noderev_deserialize
parameter_list|(
name|void
modifier|*
name|buffer
parameter_list|,
name|svn_fs_x__noderev_t
modifier|*
modifier|*
name|noderev_p
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Serialize APR array @a *a within the serialization @a context.  * The elements within the array must not contain pointers.  */
end_comment

begin_function_decl
name|void
name|svn_fs_x__serialize_apr_array
parameter_list|(
name|struct
name|svn_temp_serializer__context_t
modifier|*
name|context
parameter_list|,
name|apr_array_header_t
modifier|*
modifier|*
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Deserialize APR @a *array within the @a buffer.  Set its pool member to  * @a pool.  The elements within the array must not contain pointers.  */
end_comment

begin_function_decl
name|void
name|svn_fs_x__deserialize_apr_array
parameter_list|(
name|void
modifier|*
name|buffer
parameter_list|,
name|apr_array_header_t
modifier|*
modifier|*
name|array
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * #svn_txdelta_window_t is not sufficient for caching the data it  * represents because data read process needs auxiliary information.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* the txdelta window information cached / to be cached */
name|svn_txdelta_window_t
modifier|*
name|window
decl_stmt|;
comment|/* the revision file read pointer position before reading the window */
name|apr_off_t
name|start_offset
decl_stmt|;
comment|/* the revision file read pointer position right after reading the window */
name|apr_off_t
name|end_offset
decl_stmt|;
block|}
name|svn_fs_x__txdelta_cached_window_t
typedef|;
end_typedef

begin_comment
comment|/**  * Implements #svn_cache__serialize_func_t for  * #svn_fs_x__txdelta_cached_window_t.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_x__serialize_txdelta_window
parameter_list|(
name|void
modifier|*
modifier|*
name|buffer
parameter_list|,
name|apr_size_t
modifier|*
name|buffer_size
parameter_list|,
name|void
modifier|*
name|item
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Implements #svn_cache__deserialize_func_t for  * #svn_fs_x__txdelta_cached_window_t.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_x__deserialize_txdelta_window
parameter_list|(
name|void
modifier|*
modifier|*
name|item
parameter_list|,
name|void
modifier|*
name|buffer
parameter_list|,
name|apr_size_t
name|buffer_size
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Implements #svn_cache__serialize_func_t for a manifest  * (@a in is an #apr_array_header_t of apr_off_t elements).  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_x__serialize_manifest
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
comment|/**  * Implements #svn_cache__deserialize_func_t for a manifest  * (@a *out is an #apr_array_header_t of apr_off_t elements).  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_x__deserialize_manifest
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
comment|/**  * Implements #svn_cache__serialize_func_t for a properties hash  * (@a in is an #apr_hash_t of svn_string_t elements, keyed by const char*).  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_x__serialize_properties
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
comment|/**  * Implements #svn_cache__deserialize_func_t for a properties hash  * (@a *out is an #apr_hash_t of svn_string_t elements, keyed by const char*).  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_x__deserialize_properties
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
comment|/**  * Implements #svn_cache__serialize_func_t for #svn_fs_x__noderev_t  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_x__serialize_node_revision
parameter_list|(
name|void
modifier|*
modifier|*
name|buffer
parameter_list|,
name|apr_size_t
modifier|*
name|buffer_size
parameter_list|,
name|void
modifier|*
name|item
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Implements #svn_cache__deserialize_func_t for #svn_fs_x__noderev_t  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_x__deserialize_node_revision
parameter_list|(
name|void
modifier|*
modifier|*
name|item
parameter_list|,
name|void
modifier|*
name|buffer
parameter_list|,
name|apr_size_t
name|buffer_size
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Implements #svn_cache__serialize_func_t for a directory contents array  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_x__serialize_dir_entries
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
comment|/**  * Implements #svn_cache__deserialize_func_t for a directory contents array  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_x__deserialize_dir_entries
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
comment|/**  * Implements #svn_cache__partial_getter_func_t.  Set (apr_off_t) @a *out  * to the element indexed by (apr_int64_t) @a *baton within the  * serialized manifest array @a data and @a data_len. */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_x__get_sharded_offset
parameter_list|(
name|void
modifier|*
modifier|*
name|out
parameter_list|,
specifier|const
name|void
modifier|*
name|data
parameter_list|,
name|apr_size_t
name|data_len
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
comment|/**  * Baton type to be used with svn_fs_x__extract_dir_entry. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|svn_fs_x__ede_baton_t
block|{
comment|/* Name of the directory entry to find. */
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/* Lookup hint [in / out] */
name|apr_size_t
name|hint
decl_stmt|;
block|}
name|svn_fs_x__ede_baton_t
typedef|;
end_typedef

begin_comment
comment|/**  * Implements #svn_cache__partial_getter_func_t for a single  * #svn_fs_x__dirent_t within a serialized directory contents hash,  * identified by its name (given in @a svn_fs_x__ede_baton_t @a *baton).  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_x__extract_dir_entry
parameter_list|(
name|void
modifier|*
modifier|*
name|out
parameter_list|,
specifier|const
name|void
modifier|*
name|data
parameter_list|,
name|apr_size_t
name|data_len
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
comment|/**  * Describes the change to be done to a directory: Set the entry  * identify by @a name to the value @a new_entry. If the latter is  * @c NULL, the entry shall be removed if it exists. Otherwise it  * will be replaced or automatically added, respectively.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|replace_baton_t
block|{
comment|/** name of the directory entry to modify */
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/** directory entry to insert instead */
name|svn_fs_x__dirent_t
modifier|*
name|new_entry
decl_stmt|;
block|}
name|replace_baton_t
typedef|;
end_typedef

begin_comment
comment|/**  * Implements #svn_cache__partial_setter_func_t for a single  * #svn_fs_x__dirent_t within a serialized directory contents hash,  * identified by its name in the #replace_baton_t in @a baton.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_x__replace_dir_entry
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
name|baton
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Implements #svn_cache__serialize_func_t for a #svn_fs_x__rep_header_t.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_x__serialize_rep_header
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
comment|/**  * Implements #svn_cache__deserialize_func_t for a #svn_fs_x__rep_header_t.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_x__deserialize_rep_header
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
comment|/**  * Implements #svn_cache__serialize_func_t for an #apr_array_header_t of  * #svn_fs_x__change_t *.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_x__serialize_changes
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
comment|/**  * Implements #svn_cache__deserialize_func_t for an #apr_array_header_t of  * #svn_fs_x__change_t *.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_x__deserialize_changes
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
comment|/**  * Implements #svn_cache__serialize_func_t for #svn_mergeinfo_t objects.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_x__serialize_mergeinfo
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
comment|/**  * Implements #svn_cache__deserialize_func_t for #svn_mergeinfo_t objects.  */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_fs_x__deserialize_mergeinfo
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

