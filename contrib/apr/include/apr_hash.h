begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Licensed to the Apache Software Foundation (ASF) under one or more  * contributor license agreements.  See the NOTICE file distributed with  * this work for additional information regarding copyright ownership.  * The ASF licenses this file to You under the Apache License, Version 2.0  * (the "License"); you may not use this file except in compliance with  * the License.  You may obtain a copy of the License at  *  *     http://www.apache.org/licenses/LICENSE-2.0  *  * Unless required by applicable law or agreed to in writing, software  * distributed under the License is distributed on an "AS IS" BASIS,  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  * See the License for the specific language governing permissions and  * limitations under the License.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|APR_HASH_H
end_ifndef

begin_define
define|#
directive|define
name|APR_HASH_H
end_define

begin_comment
comment|/**  * @file apr_hash.h  * @brief APR Hash Tables  */
end_comment

begin_include
include|#
directive|include
file|"apr_pools.h"
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
comment|/**  * @defgroup apr_hash Hash Tables  * @ingroup APR   * @{  */
comment|/**  * When passing a key to apr_hash_set or apr_hash_get, this value can be  * passed to indicate a string-valued key, and have apr_hash compute the  * length automatically.  *  * @remark apr_hash will use strlen(key) for the length. The NUL terminator  *         is not included in the hash value (why throw a constant in?).  *         Since the hash table merely references the provided key (rather  *         than copying it), apr_hash_this() will return the NUL-term'd key.  */
define|#
directive|define
name|APR_HASH_KEY_STRING
value|(-1)
comment|/**  * Abstract type for hash tables.  */
typedef|typedef
name|struct
name|apr_hash_t
name|apr_hash_t
typedef|;
comment|/**  * Abstract type for scanning hash tables.  */
typedef|typedef
name|struct
name|apr_hash_index_t
name|apr_hash_index_t
typedef|;
comment|/**  * Callback functions for calculating hash values.  * @param key The key.  * @param klen The length of the key, or APR_HASH_KEY_STRING to use the string   *             length. If APR_HASH_KEY_STRING then returns the actual key length.  */
typedef|typedef
name|unsigned
name|int
function_decl|(
modifier|*
name|apr_hashfunc_t
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
name|key
parameter_list|,
name|apr_ssize_t
modifier|*
name|klen
parameter_list|)
function_decl|;
comment|/**  * The default hash function.  */
name|APR_DECLARE_NONSTD
argument_list|(
argument|unsigned int
argument_list|)
name|apr_hashfunc_default
argument_list|(
specifier|const
name|char
operator|*
name|key
argument_list|,
name|apr_ssize_t
operator|*
name|klen
argument_list|)
expr_stmt|;
comment|/**  * Create a hash table.  * @param pool The pool to allocate the hash table out of  * @return The hash table just created   */
name|APR_DECLARE
argument_list|(
argument|apr_hash_t *
argument_list|)
name|apr_hash_make
argument_list|(
name|apr_pool_t
operator|*
name|pool
argument_list|)
expr_stmt|;
comment|/**  * Create a hash table with a custom hash function  * @param pool The pool to allocate the hash table out of  * @param hash_func A custom hash function.  * @return The hash table just created   */
name|APR_DECLARE
argument_list|(
argument|apr_hash_t *
argument_list|)
name|apr_hash_make_custom
argument_list|(
argument|apr_pool_t *pool
argument_list|,
argument|apr_hashfunc_t hash_func
argument_list|)
empty_stmt|;
comment|/**  * Make a copy of a hash table  * @param pool The pool from which to allocate the new hash table  * @param h The hash table to clone  * @return The hash table just created  * @remark Makes a shallow copy  */
name|APR_DECLARE
argument_list|(
argument|apr_hash_t *
argument_list|)
name|apr_hash_copy
argument_list|(
name|apr_pool_t
operator|*
name|pool
argument_list|,
specifier|const
name|apr_hash_t
operator|*
name|h
argument_list|)
expr_stmt|;
comment|/**  * Associate a value with a key in a hash table.  * @param ht The hash table  * @param key Pointer to the key  * @param klen Length of the key. Can be APR_HASH_KEY_STRING to use the string length.  * @param val Value to associate with the key  * @remark If the value is NULL the hash entry is deleted.  */
name|APR_DECLARE
argument_list|(
argument|void
argument_list|)
name|apr_hash_set
argument_list|(
argument|apr_hash_t *ht
argument_list|,
argument|const void *key
argument_list|,
argument|apr_ssize_t klen
argument_list|,
argument|const void *val
argument_list|)
empty_stmt|;
comment|/**  * Look up the value associated with a key in a hash table.  * @param ht The hash table  * @param key Pointer to the key  * @param klen Length of the key. Can be APR_HASH_KEY_STRING to use the string length.  * @return Returns NULL if the key is not present.  */
name|APR_DECLARE
argument_list|(
argument|void *
argument_list|)
name|apr_hash_get
argument_list|(
argument|apr_hash_t *ht
argument_list|,
argument|const void *key
argument_list|,
argument|apr_ssize_t klen
argument_list|)
empty_stmt|;
comment|/**  * Start iterating over the entries in a hash table.  * @param p The pool to allocate the apr_hash_index_t iterator. If this  *          pool is NULL, then an internal, non-thread-safe iterator is used.  * @param ht The hash table  * @return The iteration state  * @remark  There is no restriction on adding or deleting hash entries during  * an iteration (although the results may be unpredictable unless all you do  * is delete the current entry) and multiple iterations can be in  * progress at the same time.  *  * @par Example:  *  * @code  * int sum_values(apr_pool_t *p, apr_hash_t *ht)  * {  *     apr_hash_index_t *hi;  *     void *val;  *     int sum = 0;  *     for (hi = apr_hash_first(p, ht); hi; hi = apr_hash_next(hi)) {  *         apr_hash_this(hi, NULL, NULL,&val);  *         sum += *(int *)val;  *     }  *     return sum;  * }  * @endcode  */
name|APR_DECLARE
argument_list|(
argument|apr_hash_index_t *
argument_list|)
name|apr_hash_first
argument_list|(
name|apr_pool_t
operator|*
name|p
argument_list|,
name|apr_hash_t
operator|*
name|ht
argument_list|)
expr_stmt|;
comment|/**  * Continue iterating over the entries in a hash table.  * @param hi The iteration state  * @return a pointer to the updated iteration state.  NULL if there are no more    *         entries.  */
name|APR_DECLARE
argument_list|(
argument|apr_hash_index_t *
argument_list|)
name|apr_hash_next
argument_list|(
name|apr_hash_index_t
operator|*
name|hi
argument_list|)
expr_stmt|;
comment|/**  * Get the current entry's details from the iteration state.  * @param hi The iteration state  * @param key Return pointer for the pointer to the key.  * @param klen Return pointer for the key length.  * @param val Return pointer for the associated value.  * @remark The return pointers should point to a variable that will be set to the  *         corresponding data, or they may be NULL if the data isn't interesting.  */
name|APR_DECLARE
argument_list|(
argument|void
argument_list|)
name|apr_hash_this
argument_list|(
name|apr_hash_index_t
operator|*
name|hi
argument_list|,
specifier|const
name|void
operator|*
operator|*
name|key
argument_list|,
name|apr_ssize_t
operator|*
name|klen
argument_list|,
name|void
operator|*
operator|*
name|val
argument_list|)
expr_stmt|;
comment|/**  * Get the current entry's key from the iteration state.  * @param hi The iteration state  * @return The pointer to the key  */
name|APR_DECLARE
argument_list|(
argument|const void*
argument_list|)
name|apr_hash_this_key
argument_list|(
name|apr_hash_index_t
operator|*
name|hi
argument_list|)
expr_stmt|;
comment|/**  * Get the current entry's key length from the iteration state.  * @param hi The iteration state  * @return The key length  */
name|APR_DECLARE
argument_list|(
argument|apr_ssize_t
argument_list|)
name|apr_hash_this_key_len
argument_list|(
name|apr_hash_index_t
operator|*
name|hi
argument_list|)
expr_stmt|;
comment|/**  * Get the current entry's value from the iteration state.  * @param hi The iteration state  * @return The pointer to the value  */
name|APR_DECLARE
argument_list|(
argument|void*
argument_list|)
name|apr_hash_this_val
argument_list|(
name|apr_hash_index_t
operator|*
name|hi
argument_list|)
expr_stmt|;
comment|/**  * Get the number of key/value pairs in the hash table.  * @param ht The hash table  * @return The number of key/value pairs in the hash table.  */
name|APR_DECLARE
argument_list|(
argument|unsigned int
argument_list|)
name|apr_hash_count
argument_list|(
name|apr_hash_t
operator|*
name|ht
argument_list|)
expr_stmt|;
comment|/**  * Clear any key/value pairs in the hash table.  * @param ht The hash table  */
name|APR_DECLARE
argument_list|(
argument|void
argument_list|)
name|apr_hash_clear
argument_list|(
name|apr_hash_t
operator|*
name|ht
argument_list|)
expr_stmt|;
comment|/**  * Merge two hash tables into one new hash table. The values of the overlay  * hash override the values of the base if both have the same key.  Both  * hash tables must use the same hash function.  * @param p The pool to use for the new hash table  * @param overlay The table to add to the initial table  * @param base The table that represents the initial values of the new table  * @return A new hash table containing all of the data from the two passed in  */
name|APR_DECLARE
argument_list|(
argument|apr_hash_t *
argument_list|)
name|apr_hash_overlay
argument_list|(
name|apr_pool_t
operator|*
name|p
argument_list|,
specifier|const
name|apr_hash_t
operator|*
name|overlay
argument_list|,
specifier|const
name|apr_hash_t
operator|*
name|base
argument_list|)
expr_stmt|;
comment|/**  * Merge two hash tables into one new hash table. If the same key  * is present in both tables, call the supplied merge function to  * produce a merged value for the key in the new table.  Both  * hash tables must use the same hash function.  * @param p The pool to use for the new hash table  * @param h1 The first of the tables to merge  * @param h2 The second of the tables to merge  * @param merger A callback function to merge values, or NULL to  *  make values from h1 override values from h2 (same semantics as  *  apr_hash_overlay())  * @param data Client data to pass to the merger function  * @return A new hash table containing all of the data from the two passed in  */
name|APR_DECLARE
argument_list|(
argument|apr_hash_t *
argument_list|)
name|apr_hash_merge
argument_list|(
name|apr_pool_t
operator|*
name|p
argument_list|,
specifier|const
name|apr_hash_t
operator|*
name|h1
argument_list|,
specifier|const
name|apr_hash_t
operator|*
name|h2
argument_list|,
name|void
operator|*
operator|(
operator|*
name|merger
operator|)
operator|(
name|apr_pool_t
operator|*
name|p
operator|,
specifier|const
name|void
operator|*
name|key
operator|,
name|apr_ssize_t
name|klen
operator|,
specifier|const
name|void
operator|*
name|h1_val
operator|,
specifier|const
name|void
operator|*
name|h2_val
operator|,
specifier|const
name|void
operator|*
name|data
operator|)
argument_list|,
specifier|const
name|void
operator|*
name|data
argument_list|)
expr_stmt|;
comment|/**  * Declaration prototype for the iterator callback function of apr_hash_do().  *  * @param rec The data passed as the first argument to apr_hash_[v]do()  * @param key The key from this iteration of the hash table  * @param klen The key length from this iteration of the hash table  * @param value The value from this iteration of the hash table  * @remark Iteration continues while this callback function returns non-zero.  * To export the callback function for apr_hash_do() it must be declared   * in the _NONSTD convention.  */
typedef|typedef
name|int
function_decl|(
name|apr_hash_do_callback_fn_t
function_decl|)
parameter_list|(
name|void
modifier|*
name|rec
parameter_list|,
specifier|const
name|void
modifier|*
name|key
parameter_list|,
name|apr_ssize_t
name|klen
parameter_list|,
specifier|const
name|void
modifier|*
name|value
parameter_list|)
function_decl|;
comment|/**   * Iterate over a hash table running the provided function once for every  * element in the hash table. The @param comp function will be invoked for  * every element in the hash table.  *  * @param comp The function to run  * @param rec The data to pass as the first argument to the function  * @param ht The hash table to iterate over  * @return FALSE if one of the comp() iterations returned zero; TRUE if all  *            iterations returned non-zero  * @see apr_hash_do_callback_fn_t  */
name|APR_DECLARE
argument_list|(
argument|int
argument_list|)
name|apr_hash_do
argument_list|(
name|apr_hash_do_callback_fn_t
operator|*
name|comp
argument_list|,
name|void
operator|*
name|rec
argument_list|,
specifier|const
name|apr_hash_t
operator|*
name|ht
argument_list|)
expr_stmt|;
comment|/**  * Get a pointer to the pool which the hash table was created in  */
name|APR_POOL_DECLARE_ACCESSOR
argument_list|(
name|hash
argument_list|)
expr_stmt|;
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !APR_HASH_H */
end_comment

end_unit

