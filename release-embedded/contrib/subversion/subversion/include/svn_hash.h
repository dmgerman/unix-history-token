begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  * @copyright  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  * @endcopyright  *  * @file svn_hash.h  * @brief Dumping and reading hash tables to/from files.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_HASH_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_HASH_H
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
file|<apr_hash.h>
end_include

begin_include
include|#
directive|include
file|<apr_tables.h>
end_include

begin_include
include|#
directive|include
file|<apr_file_io.h>
end_include

begin_comment
comment|/* for apr_file_t */
end_comment

begin_include
include|#
directive|include
file|"svn_types.h"
end_include

begin_include
include|#
directive|include
file|"svn_io.h"
end_include

begin_comment
comment|/* for svn_stream_t */
end_comment

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
comment|/** The longest the "K<number>" line can be in one of our hashdump files. */
define|#
directive|define
name|SVN_KEYLINE_MAXLEN
value|100
comment|/**  * @defgroup svn_hash_support Hash table serialization support  * @{  */
comment|/*----------------------------------------------------*/
comment|/** Reading/writing hashtables to disk  *  * @defgroup svn_hash_read_write Reading and writing hashtables to disk  * @{  */
comment|/**  * The conventional terminator for hash dumps.  *  * @since New in 1.1.  */
define|#
directive|define
name|SVN_HASH_TERMINATOR
value|"END"
comment|/**  * Read a hash table from @a stream, storing the resultants names and  * values in @a hash.  Use a @a pool for all allocations.  @a hash will  * have<tt>const char *</tt> keys and<tt>svn_string_t *</tt> values.  * If @a terminator is NULL, expect the hash to be terminated by the  * end of the stream; otherwise, expect the hash to be terminated by a  * line containing @a terminator.  Pass @c SVN_HASH_TERMINATOR to use  * the conventional terminator "END".  *  * @since New in 1.1.  */
name|svn_error_t
modifier|*
name|svn_hash_read2
parameter_list|(
name|apr_hash_t
modifier|*
name|hash
parameter_list|,
name|svn_stream_t
modifier|*
name|stream
parameter_list|,
specifier|const
name|char
modifier|*
name|terminator
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/**  * Dump @a hash to @a stream.  Use @a pool for all allocations.  @a  * hash has<tt>const char *</tt> keys and<tt>svn_string_t *</tt>  * values.  If @a terminator is not NULL, terminate the hash with a  * line containing @a terminator.  *  * @since New in 1.1.  */
name|svn_error_t
modifier|*
name|svn_hash_write2
parameter_list|(
name|apr_hash_t
modifier|*
name|hash
parameter_list|,
name|svn_stream_t
modifier|*
name|stream
parameter_list|,
specifier|const
name|char
modifier|*
name|terminator
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/**  * Similar to svn_hash_read2(), but allows @a stream to contain  * deletion lines which remove entries from @a hash as well as adding  * to it.  *  * @since New in 1.1.  */
name|svn_error_t
modifier|*
name|svn_hash_read_incremental
parameter_list|(
name|apr_hash_t
modifier|*
name|hash
parameter_list|,
name|svn_stream_t
modifier|*
name|stream
parameter_list|,
specifier|const
name|char
modifier|*
name|terminator
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/**  * Similar to svn_hash_write2(), but only writes out entries for  * keys which differ between @a hash and @a oldhash, and also writes  * out deletion lines for keys which are present in @a oldhash but not  * in @a hash.  *  * @since New in 1.1.  */
name|svn_error_t
modifier|*
name|svn_hash_write_incremental
parameter_list|(
name|apr_hash_t
modifier|*
name|hash
parameter_list|,
name|apr_hash_t
modifier|*
name|oldhash
parameter_list|,
name|svn_stream_t
modifier|*
name|stream
parameter_list|,
specifier|const
name|char
modifier|*
name|terminator
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/**  * This function behaves like svn_hash_read2(), but it only works  * on an apr_file_t input, empty files are accepted, and the hash is  * expected to be terminated with a line containing "END" or  * "PROPS-END".  *  * @deprecated Provided for backward compatibility with the 1.0 API.  */
name|SVN_DEPRECATED
name|svn_error_t
modifier|*
name|svn_hash_read
parameter_list|(
name|apr_hash_t
modifier|*
name|hash
parameter_list|,
name|apr_file_t
modifier|*
name|srcfile
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/**  * This function behaves like svn_hash_write2(), but it only works  * on an apr_file_t output, and the terminator is always "END".  *  * @deprecated Provided for backward compatibility with the 1.0 API.  */
name|SVN_DEPRECATED
name|svn_error_t
modifier|*
name|svn_hash_write
parameter_list|(
name|apr_hash_t
modifier|*
name|hash
parameter_list|,
name|apr_file_t
modifier|*
name|destfile
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/** @} */
comment|/** Taking the "diff" of two hash tables.  *  * @defgroup svn_hash_diff Taking the diff of two hash tables.  * @{  */
comment|/** Hash key status indicator for svn_hash_diff_func_t.  */
enum|enum
name|svn_hash_diff_key_status
block|{
comment|/* Key is present in both hashes. */
name|svn_hash_diff_key_both
block|,
comment|/* Key is present in first hash only. */
name|svn_hash_diff_key_a
block|,
comment|/* Key is present in second hash only. */
name|svn_hash_diff_key_b
block|}
enum|;
comment|/** Function type for expressing a key's status between two hash tables. */
typedef|typedef
name|svn_error_t
modifier|*
function_decl|(
modifier|*
name|svn_hash_diff_func_t
function_decl|)
parameter_list|(
specifier|const
name|void
modifier|*
name|key
parameter_list|,
name|apr_ssize_t
name|klen
parameter_list|,
name|enum
name|svn_hash_diff_key_status
name|status
parameter_list|,
name|void
modifier|*
name|baton
parameter_list|)
function_decl|;
comment|/** Take the diff of two hashtables.  *  * For each key in the union of @a hash_a's and @a hash_b's keys, invoke  * @a diff_func exactly once, passing the key, the key's length, an enum  * @c svn_hash_diff_key_status indicating which table(s) the key appears  * in, and @a diff_func_baton.  *  * Process all keys of @a hash_a first, then all remaining keys of @a hash_b.  *  * If @a diff_func returns error, return that error immediately, without  * applying @a diff_func to anything else.  *  * @a hash_a or @a hash_b or both may be NULL; treat a null table as though  * empty.  *  * Use @a pool for temporary allocation.  */
name|svn_error_t
modifier|*
name|svn_hash_diff
parameter_list|(
name|apr_hash_t
modifier|*
name|hash_a
parameter_list|,
name|apr_hash_t
modifier|*
name|hash_b
parameter_list|,
name|svn_hash_diff_func_t
name|diff_func
parameter_list|,
name|void
modifier|*
name|diff_func_baton
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/** @} */
comment|/**  * @defgroup svn_hash_misc Miscellaneous hash APIs  * @{  */
comment|/**  * Return the keys to @a hash in @a *array.  The keys are assumed to be  * (const char *).  The keys are in no particular order.  *  * @a *array itself is allocated in @a pool; however, the keys are not  * copied from the hash.  *  * @since New in 1.5.  */
name|svn_error_t
modifier|*
name|svn_hash_keys
parameter_list|(
name|apr_array_header_t
modifier|*
modifier|*
name|array
parameter_list|,
name|apr_hash_t
modifier|*
name|hash
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/**  * Set @a *hash to a new hash whose keys come from the items in @a keys  * (an array of<tt>const char *</tt> items), and whose values are  * match their corresponding key.  Use @a pool for all allocations  * (including @a *hash, its keys, and its values).  *  * @since New in 1.5.  */
name|svn_error_t
modifier|*
name|svn_hash_from_cstring_keys
parameter_list|(
name|apr_hash_t
modifier|*
modifier|*
name|hash
parameter_list|,
specifier|const
name|apr_array_header_t
modifier|*
name|keys
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/** Shortcut for apr_hash_get() with a const char * key.  *  * @since New in 1.8.  */
define|#
directive|define
name|svn_hash_gets
parameter_list|(
name|ht
parameter_list|,
name|key
parameter_list|)
define|\
value|apr_hash_get(ht, key, APR_HASH_KEY_STRING)
comment|/** Shortcut for apr_hash_set() with a const char * key.  *  * @since New in 1.8.  */
define|#
directive|define
name|svn_hash_sets
parameter_list|(
name|ht
parameter_list|,
name|key
parameter_list|,
name|val
parameter_list|)
define|\
value|apr_hash_set(ht, key, APR_HASH_KEY_STRING, val)
comment|/** @} */
comment|/** @} */
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
comment|/* SVN_HASH_H */
end_comment

end_unit

