begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Licensed to the Apache Software Foundation (ASF) under one or more  * contributor license agreements.  See the NOTICE file distributed with  * this work for additional information regarding copyright ownership.  * The ASF licenses this file to You under the Apache License, Version 2.0  * (the "License"); you may not use this file except in compliance with  * the License.  You may obtain a copy of the License at  *  *     http://www.apache.org/licenses/LICENSE-2.0  *  * Unless required by applicable law or agreed to in writing, software  * distributed under the License is distributed on an "AS IS" BASIS,  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  * See the License for the specific language governing permissions and  * limitations under the License.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|APR_SKIPLIST_H
end_ifndef

begin_define
define|#
directive|define
name|APR_SKIPLIST_H
end_define

begin_comment
comment|/**  * @file apr_skiplist.h  * @brief APR skip list implementation  */
end_comment

begin_include
include|#
directive|include
file|"apr.h"
end_include

begin_include
include|#
directive|include
file|"apr_portable.h"
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
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
comment|/**  * @defgroup apr_skiplist Skip list implementation  * Refer to http://en.wikipedia.org/wiki/Skip_list for information  * about the purpose of and ideas behind skip lists.  * @ingroup APR  * @{  */
comment|/**  * apr_skiplist_compare is the function type that must be implemented   * per object type that is used in a skip list for comparisons to maintain  * order  * */
typedef|typedef
name|int
function_decl|(
modifier|*
name|apr_skiplist_compare
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
comment|/**  * apr_skiplist_freefunc is the function type that must be implemented  * to handle elements as they are removed from a skip list.  */
typedef|typedef
name|void
function_decl|(
modifier|*
name|apr_skiplist_freefunc
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
comment|/** Opaque structure used to represent the skip list */
struct_decl|struct
name|apr_skiplist
struct_decl|;
comment|/** Opaque structure used to represent the skip list */
typedef|typedef
name|struct
name|apr_skiplist
name|apr_skiplist
typedef|;
comment|/**   * Opaque structure used to represent abstract nodes in the skip list  * (an abstraction above the raw elements which are collected in the  * skip list).  */
struct_decl|struct
name|apr_skiplistnode
struct_decl|;
comment|/** Opaque structure */
typedef|typedef
name|struct
name|apr_skiplistnode
name|apr_skiplistnode
typedef|;
comment|/**  * Allocate memory using the same mechanism as the skip list.  * @param sl The skip list  * @param size The amount to allocate  * @remark If a pool was provided to apr_skiplist_init(), memory will  * be allocated from the pool or from a free list maintained with  * the skip list.  Otherwise, memory will be allocated using the  * C standard library heap functions.  */
name|APR_DECLARE
argument_list|(
argument|void *
argument_list|)
name|apr_skiplist_alloc
argument_list|(
argument|apr_skiplist *sl
argument_list|,
argument|size_t size
argument_list|)
empty_stmt|;
comment|/**  * Free memory using the same mechanism as the skip list.  * @param sl The skip list  * @param mem The object to free  * @remark If a pool was provided to apr_skiplist_init(), memory will  * be added to a free list maintained with the skip list and be available  * to operations on the skip list or to other calls to apr_skiplist_alloc().  * Otherwise, memory will be freed using the  C standard library heap  * functions.  */
name|APR_DECLARE
argument_list|(
argument|void
argument_list|)
name|apr_skiplist_free
argument_list|(
name|apr_skiplist
operator|*
name|sl
argument_list|,
name|void
operator|*
name|mem
argument_list|)
expr_stmt|;
comment|/**  * Allocate a new skip list  * @param sl The pointer in which to return the newly created skip list  * @param p The pool from which to allocate the skip list (optional).  * @remark Unlike most APR functions, a pool is optional.  If no pool  * is provided, the C standard library heap functions will be used instead.  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_skiplist_init
argument_list|(
name|apr_skiplist
operator|*
operator|*
name|sl
argument_list|,
name|apr_pool_t
operator|*
name|p
argument_list|)
expr_stmt|;
comment|/**  * Set the comparison functions to be used for searching the skip list.  * @param sl The skip list  * @param XXX1 FIXME  * @param XXX2 FIXME  *  * @remark If existing comparison functions are being replaced, the index  * will be replaced during this call.  That is a potentially expensive  * operation.  */
name|APR_DECLARE
argument_list|(
argument|void
argument_list|)
name|apr_skiplist_set_compare
argument_list|(
argument|apr_skiplist *sl
argument_list|,
argument|apr_skiplist_compare XXX1
argument_list|,
argument|apr_skiplist_compare XXX2
argument_list|)
empty_stmt|;
comment|/**  * Set the indexing functions to the specified comparison functions and  * rebuild the index.  * @param sl The skip list  * @param XXX1 FIXME  * @param XXX2 FIXME  *  * @remark If an index already exists, it will not be replaced and the  * comparison functions will not be changed.  */
name|APR_DECLARE
argument_list|(
argument|void
argument_list|)
name|apr_skiplist_add_index
argument_list|(
argument|apr_skiplist *sl
argument_list|,
argument|apr_skiplist_compare XXX1
argument_list|,
argument|apr_skiplist_compare XXX2
argument_list|)
empty_stmt|;
comment|/**  * Return the list maintained by the skip list abstraction.  * @param sl The skip list  */
name|APR_DECLARE
argument_list|(
argument|apr_skiplistnode *
argument_list|)
name|apr_skiplist_getlist
argument_list|(
name|apr_skiplist
operator|*
name|sl
argument_list|)
expr_stmt|;
comment|/**  * Return the next matching element in the skip list using the specified  * comparison function.  * @param sl The skip list  * @param data The value to search for  * @param iter A pointer to the returned skip list node representing the element  * found  * @param func The comparison function to use  */
name|APR_DECLARE
argument_list|(
argument|void *
argument_list|)
name|apr_skiplist_find_compare
argument_list|(
argument|apr_skiplist *sl
argument_list|,
argument|void *data
argument_list|,
argument|apr_skiplistnode **iter
argument_list|,
argument|apr_skiplist_compare func
argument_list|)
empty_stmt|;
comment|/**  * Return the next matching element in the skip list using the current comparison  * function.  * @param sl The skip list  * @param data The value to search for  * @param iter A pointer to the returned skip list node representing the element  * found  */
name|APR_DECLARE
argument_list|(
argument|void *
argument_list|)
name|apr_skiplist_find
argument_list|(
name|apr_skiplist
operator|*
name|sl
argument_list|,
name|void
operator|*
name|data
argument_list|,
name|apr_skiplistnode
operator|*
operator|*
name|iter
argument_list|)
expr_stmt|;
comment|/**  * Return the next element in the skip list.  * @param sl The skip list  * @param iter On entry, a pointer to the skip list node to start with; on return,  * a pointer to the skip list node representing the element returned  * @remark If iter points to a NULL value on entry, NULL will be returned.  */
name|APR_DECLARE
argument_list|(
argument|void *
argument_list|)
name|apr_skiplist_next
argument_list|(
name|apr_skiplist
operator|*
name|sl
argument_list|,
name|apr_skiplistnode
operator|*
operator|*
name|iter
argument_list|)
expr_stmt|;
comment|/**  * Return the previous element in the skip list.  * @param sl The skip list  * @param iter On entry, a pointer to the skip list node to start with; on return,  * a pointer to the skip list node representing the element returned  * @remark If iter points to a NULL value on entry, NULL will be returned.  */
name|APR_DECLARE
argument_list|(
argument|void *
argument_list|)
name|apr_skiplist_previous
argument_list|(
name|apr_skiplist
operator|*
name|sl
argument_list|,
name|apr_skiplistnode
operator|*
operator|*
name|iter
argument_list|)
expr_stmt|;
comment|/**  * Insert an element into the skip list using the specified comparison function.  * @param sl The skip list  * @param data The element to insert  * @param comp The comparison function to use for placement into the skip list  */
name|APR_DECLARE
argument_list|(
argument|apr_skiplistnode *
argument_list|)
name|apr_skiplist_insert_compare
argument_list|(
argument|apr_skiplist *sl
argument_list|,
argument|void *data
argument_list|,
argument|apr_skiplist_compare comp
argument_list|)
empty_stmt|;
comment|/**  * Insert an element into the skip list using the existing comparison function.  * @param sl The skip list  * @param data The element to insert  * @remark If no comparison function has been set for the skip list, the element  * will not be inserted and NULL will be returned.  */
name|APR_DECLARE
argument_list|(
argument|apr_skiplistnode *
argument_list|)
name|apr_skiplist_insert
argument_list|(
name|apr_skiplist
operator|*
name|sl
argument_list|,
name|void
operator|*
name|data
argument_list|)
expr_stmt|;
comment|/**  * Remove an element from the skip list using the specified comparison function for  * locating the element.  * @param sl The skip list  * @param data The element to remove  * @param myfree A function to be called for each removed element  * @param comp The comparison function to use for placement into the skip list  * @remark If the element is not found, 0 will be returned.  Otherwise, the heightXXX  * will be returned.  */
name|APR_DECLARE
argument_list|(
argument|int
argument_list|)
name|apr_skiplist_remove_compare
argument_list|(
argument|apr_skiplist *sl
argument_list|,
argument|void *data
argument_list|,
argument|apr_skiplist_freefunc myfree
argument_list|,
argument|apr_skiplist_compare comp
argument_list|)
empty_stmt|;
comment|/**  * Remove an element from the skip list using the existing comparison function for  * locating the element.  * @param sl The skip list  * @param data The element to remove  * @param myfree A function to be called for each removed element  * @remark If the element is not found, 0 will be returned.  Otherwise, the heightXXX  * will be returned.  * @remark If no comparison function has been set for the skip list, the element  * will not be removed and 0 will be returned.  */
name|APR_DECLARE
argument_list|(
argument|int
argument_list|)
name|apr_skiplist_remove
argument_list|(
argument|apr_skiplist *sl
argument_list|,
argument|void *data
argument_list|,
argument|apr_skiplist_freefunc myfree
argument_list|)
empty_stmt|;
comment|/**  * Remove all elements from the skip list.  * @param sl The skip list  * @param myfree A function to be called for each removed element  */
name|APR_DECLARE
argument_list|(
argument|void
argument_list|)
name|apr_skiplist_remove_all
argument_list|(
argument|apr_skiplist *sl
argument_list|,
argument|apr_skiplist_freefunc myfree
argument_list|)
empty_stmt|;
comment|/**  * Remove each element from the skip list.  * @param sl The skip list  * @param myfree A function to be called for each removed element  */
name|APR_DECLARE
argument_list|(
argument|void
argument_list|)
name|apr_skiplist_destroy
argument_list|(
argument|apr_skiplist *sl
argument_list|,
argument|apr_skiplist_freefunc myfree
argument_list|)
empty_stmt|;
comment|/**  * Return the first element in the skip list, leaving the element in the skip list.  * @param sl The skip list  * @param myfree A function to be called for the removed element  * @remark NULL will be returned if there are no elements  */
name|APR_DECLARE
argument_list|(
argument|void *
argument_list|)
name|apr_skiplist_pop
argument_list|(
argument|apr_skiplist *sl
argument_list|,
argument|apr_skiplist_freefunc myfree
argument_list|)
empty_stmt|;
comment|/**  * Return the first element in the skip list, leaving the element in the skip list.  * @param sl The skip list  * @remark NULL will be returned if there are no elements  */
name|APR_DECLARE
argument_list|(
argument|void *
argument_list|)
name|apr_skiplist_peek
argument_list|(
name|apr_skiplist
operator|*
name|sl
argument_list|)
expr_stmt|;
comment|/**  * Merge two skip lists.  XXX SEMANTICS  * @param sl1 One of two skip lists to be merged  * @param sl2 The other of two skip lists to be merged  */
name|APR_DECLARE
argument_list|(
argument|apr_skiplist *
argument_list|)
name|apr_skiplist_merge
argument_list|(
name|apr_skiplist
operator|*
name|sl1
argument_list|,
name|apr_skiplist
operator|*
name|sl2
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
comment|/* ! APR_SKIPLIST_H */
end_comment

end_unit

