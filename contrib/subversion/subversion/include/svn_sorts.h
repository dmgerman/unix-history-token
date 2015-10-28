begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  * @copyright  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  * @endcopyright  *  * @file svn_sorts.h  * @brief all sorts of sorts.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_SORTS_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_SORTS_H
end_define

begin_include
include|#
directive|include
file|<apr.h>
end_include

begin_comment
comment|/* for apr_ssize_t */
end_comment

begin_include
include|#
directive|include
file|<apr_pools.h>
end_include

begin_comment
comment|/* for apr_pool_t */
end_comment

begin_include
include|#
directive|include
file|<apr_tables.h>
end_include

begin_comment
comment|/* for apr_array_header_t */
end_comment

begin_include
include|#
directive|include
file|<apr_hash.h>
end_include

begin_comment
comment|/* for apr_hash_t */
end_comment

begin_comment
comment|/* Define a MAX macro if we don't already have one */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MAX
end_ifndef

begin_define
define|#
directive|define
name|MAX
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)< (b) ? (b) : (a))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define a MIN macro if we don't already have one */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MIN
end_ifndef

begin_define
define|#
directive|define
name|MIN
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)< (b) ? (a) : (b))
end_define

begin_endif
endif|#
directive|endif
end_endif

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
typedef|typedef
name|struct
name|svn_sort__item_t
name|svn_sort__item_t
typedef|;
comment|/** Compare two @c svn_sort__item_t's, returning an integer greater than,  * equal to, or less than 0, according to whether the key of @a a is  * greater than, equal to, or less than the key of @a b as determined  * by comparing them with svn_path_compare_paths().  *  * The key strings must be NULL-terminated, even though klen does not  * include the terminator.  *  * This is useful for converting a hash into a sorted  * @c apr_array_header_t.  For example, to convert hash @a hsh to a sorted  * array, do this:  *  * @code      apr_array_header_t *array;      array = svn_sort__hash(hsh, svn_sort_compare_items_as_paths, pool);    @endcode  *  * This function works like svn_sort_compare_items_lexically() except that it  * orders children in subdirectories directly after their parents. This allows  * using the given ordering for a depth first walk, but at a performance  * penalty. Code that doesn't need this special behavior for children, e.g. when  * sorting files at a single directory level should use  * svn_sort_compare_items_lexically() instead.  */
name|int
name|svn_sort_compare_items_as_paths
parameter_list|(
specifier|const
name|svn_sort__item_t
modifier|*
name|a
parameter_list|,
specifier|const
name|svn_sort__item_t
modifier|*
name|b
parameter_list|)
function_decl|;
comment|/** Compare two @c svn_sort__item_t's, returning an integer greater than,  * equal to, or less than 0, according as @a a is greater than, equal to,  * or less than @a b according to a lexical key comparison.  The keys are  * not required to be zero-terminated.  */
name|int
name|svn_sort_compare_items_lexically
parameter_list|(
specifier|const
name|svn_sort__item_t
modifier|*
name|a
parameter_list|,
specifier|const
name|svn_sort__item_t
modifier|*
name|b
parameter_list|)
function_decl|;
comment|/** Compare two @c svn_revnum_t's, returning an integer greater than, equal  * to, or less than 0, according as @a b is greater than, equal to, or less  * than @a a. Note that this sorts newest revision to oldest (IOW, descending  * order).  *  * This function is compatible for use with qsort().  *  * This is useful for converting an array of revisions into a sorted  * @c apr_array_header_t. You are responsible for detecting, preventing or  * removing duplicates.  */
name|int
name|svn_sort_compare_revisions
parameter_list|(
specifier|const
name|void
modifier|*
name|a
parameter_list|,
specifier|const
name|void
modifier|*
name|b
parameter_list|)
function_decl|;
comment|/**  * Compare two @c const char * paths, @a *a and @a *b, returning an  * integer greater than, equal to, or less than 0, using the same  * comparison rules as are used by svn_path_compare_paths().  *  * This function is compatible for use with qsort().  *  * @since New in 1.1.  */
name|int
name|svn_sort_compare_paths
parameter_list|(
specifier|const
name|void
modifier|*
name|a
parameter_list|,
specifier|const
name|void
modifier|*
name|b
parameter_list|)
function_decl|;
comment|/**  * Compare two @c svn_merge_range_t *'s, @a *a and @a *b, returning an  * integer greater than, equal to, or less than 0 if the first range is  * greater than, equal to, or less than, the second range.  *  * Both @c svn_merge_range_t *'s must describe forward merge ranges.  *  * If @a *a and @a *b intersect then the range with the lower start revision  * is considered the lesser range.  If the ranges' start revisions are  * equal then the range with the lower end revision is considered the  * lesser range.  *  * @since New in 1.5  */
name|int
name|svn_sort_compare_ranges
parameter_list|(
specifier|const
name|void
modifier|*
name|a
parameter_list|,
specifier|const
name|void
modifier|*
name|b
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
comment|/* SVN_SORTS_H */
end_comment

end_unit

