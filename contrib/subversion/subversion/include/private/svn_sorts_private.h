begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  * @copyright  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  * @endcopyright  *  * @file svn_sorts_private.h  * @brief all sorts of sorts.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_SORTS_PRIVATE_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_SORTS_PRIVATE_H
end_define

begin_include
include|#
directive|include
file|"../svn_sorts.h"
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
comment|/** This structure is used to hold a key/value from a hash table.  * @note Private. For use by Subversion's own code only. See issue #1644.  */
struct|struct
name|svn_sort__item_t
block|{
comment|/** pointer to the key */
specifier|const
name|void
modifier|*
name|key
decl_stmt|;
comment|/** size of the key */
name|apr_ssize_t
name|klen
decl_stmt|;
comment|/** pointer to the value */
name|void
modifier|*
name|value
decl_stmt|;
block|}
struct|;
comment|/** Sort @a ht according to its keys, return an @c apr_array_header_t  * containing @c svn_sort__item_t structures holding those keys and values  * (i.e. for each @c svn_sort__item_t @a item in the returned array,  * @a item->key and @a item->size are the hash key, and @a item->value points to  * the hash value).  *  * Storage is shared with the original hash, not copied.  *  * @a comparison_func should take two @c svn_sort__item_t's and return an  * integer greater than, equal to, or less than 0, according as the first item  * is greater than, equal to, or less than the second.  *  * @note Private. For use by Subversion's own code only. See issue #1644.  *  * @note This function and the @c svn_sort__item_t should go over to APR.  */
name|apr_array_header_t
modifier|*
name|svn_sort__hash
parameter_list|(
name|apr_hash_t
modifier|*
name|ht
parameter_list|,
name|int
function_decl|(
modifier|*
name|comparison_func
function_decl|)
parameter_list|(
specifier|const
name|svn_sort__item_t
modifier|*
parameter_list|,
specifier|const
name|svn_sort__item_t
modifier|*
parameter_list|)
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/* Sort APR array @a array using ordering defined by @a comparison_func.  * @a comparison_func is defined as for the C stdlib function qsort().  */
name|void
name|svn_sort__array
parameter_list|(
name|apr_array_header_t
modifier|*
name|array
parameter_list|,
name|int
function_decl|(
modifier|*
name|comparison_func
function_decl|)
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
comment|/* Return the lowest index at which the element @a *key should be inserted into  * the array @a array, according to the ordering defined by @a compare_func.  * The array must already be sorted in the ordering defined by @a compare_func.  * @a compare_func is defined as for the C stdlib function bsearch(); the  * @a key will always passed to it as the second parameter.  *  * @note Private. For use by Subversion's own code only.  */
name|int
name|svn_sort__bsearch_lower_bound
parameter_list|(
specifier|const
name|apr_array_header_t
modifier|*
name|array
parameter_list|,
specifier|const
name|void
modifier|*
name|key
parameter_list|,
name|int
function_decl|(
modifier|*
name|compare_func
function_decl|)
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
comment|/* Find the lowest index at which the element @a *key should be inserted into  * the array @a array, according to the ordering defined by @a compare_func.  * The array must already be sorted in the ordering defined by @a compare_func.  * @a compare_func is defined as for the C stdlib function bsearch(); the  * @a key will always passed to it as the second parameter.  *  * Returns a reference to the array element at the insertion location if  * that matches @a key and return NULL otherwise.  If you call this function  * multiple times for the same array and expect the results to often be  * consecutive array elements, provide @a hint.  It should be initialized  * with -1 for the first call and receives the array index if the returned  * element.  If the return value is NULL, @a *hint is the location where  * the respective key would be inserted.  *  * @note Private. For use by Subversion's own code only.  */
name|void
modifier|*
name|svn_sort__array_lookup
parameter_list|(
specifier|const
name|apr_array_header_t
modifier|*
name|array
parameter_list|,
specifier|const
name|void
modifier|*
name|key
parameter_list|,
name|int
modifier|*
name|hint
parameter_list|,
name|int
function_decl|(
modifier|*
name|compare_func
function_decl|)
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
comment|/* Insert a shallow copy of @a *new_element into the array @a array at the index  * @a insert_index, growing the array and shuffling existing elements along to  * make room.  *  * @note Private. For use by Subversion's own code only.  */
name|void
name|svn_sort__array_insert
parameter_list|(
name|apr_array_header_t
modifier|*
name|array
parameter_list|,
specifier|const
name|void
modifier|*
name|new_element
parameter_list|,
name|int
name|insert_index
parameter_list|)
function_decl|;
comment|/* Remove @a elements_to_delete elements starting at @a delete_index from the  * array @a arr. If @a delete_index is not a valid element of @a arr,  * @a elements_to_delete is not greater than zero, or  * @a delete_index + @a elements_to_delete is greater than @a arr->nelts,  * then do nothing.  *  * @note Private. For use by Subversion's own code only.  */
name|void
name|svn_sort__array_delete
parameter_list|(
name|apr_array_header_t
modifier|*
name|arr
parameter_list|,
name|int
name|delete_index
parameter_list|,
name|int
name|elements_to_delete
parameter_list|)
function_decl|;
comment|/* Reverse the order of elements in @a array, in place.  *  * @note Private. For use by Subversion's own code only.  */
name|void
name|svn_sort__array_reverse
parameter_list|(
name|apr_array_header_t
modifier|*
name|array
parameter_list|,
name|apr_pool_t
modifier|*
name|scratch_pool
parameter_list|)
function_decl|;
comment|/** Priority queues.  *  * @defgroup svn_priority_queue__t Priority Queues  * @{  */
comment|/**  * We implement priority queues on top of existing ELEMENTS arrays.  They  * provide us with memory management and very basic element type information.  *  * The extraction order is being defined by a comparison function similar  * to the ones used with qsort.  The first element in the queue is always  * on with COMPARISON_FUNC(first,element)<= 0, for all elements in the  * queue.  */
comment|/**  * Opaque data type for priority queues.  */
typedef|typedef
name|struct
name|svn_priority_queue__t
name|svn_priority_queue__t
typedef|;
comment|/**  * Return a priority queue containing all provided @a elements and prioritize  * them according to @a compare_func.  *  * @note The priority queue will use the existing @a elements array for data  * storage.  So, you must not manipulate that array while using the queue.  * Also, the lifetime of the queue is bound to that of the array.  */
name|svn_priority_queue__t
modifier|*
name|svn_priority_queue__create
parameter_list|(
name|apr_array_header_t
modifier|*
name|elements
parameter_list|,
name|int
function_decl|(
modifier|*
name|compare_func
function_decl|)
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
comment|/**  * Returns the number of elements in the @a queue.  */
name|apr_size_t
name|svn_priority_queue__size
parameter_list|(
name|svn_priority_queue__t
modifier|*
name|queue
parameter_list|)
function_decl|;
comment|/**  * Returns a reference to the first element in the @a queue.  The queue  * contents remains unchanged.  If the @a queue is empty, #NULL will be  * returned.  */
name|void
modifier|*
name|svn_priority_queue__peek
parameter_list|(
name|svn_priority_queue__t
modifier|*
name|queue
parameter_list|)
function_decl|;
comment|/**  * Notify the @a queue after modifying the first item as returned by  * #svn_priority_queue__peek.  */
name|void
name|svn_priority_queue__update
parameter_list|(
name|svn_priority_queue__t
modifier|*
name|queue
parameter_list|)
function_decl|;
comment|/**  * Remove the first element from the @a queue.  This is a no-op for empty  * queues.  */
name|void
name|svn_priority_queue__pop
parameter_list|(
name|svn_priority_queue__t
modifier|*
name|queue
parameter_list|)
function_decl|;
comment|/**  * Append the new @a element to the @a queue.  @a element must neither be  * #NULL nor the first element as returned by #svn_priority_queue__peek.  */
name|void
name|svn_priority_queue__push
parameter_list|(
name|svn_priority_queue__t
modifier|*
name|queue
parameter_list|,
specifier|const
name|void
modifier|*
name|element
parameter_list|)
function_decl|;
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
comment|/* SVN_SORTS_PRIVATE_H */
end_comment

end_unit

