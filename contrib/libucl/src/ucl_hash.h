begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 2013, Vsevolod Stakhov  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *       * Redistributions of source code must retain the above copyright  *         notice, this list of conditions and the following disclaimer.  *       * Redistributions in binary form must reproduce the above copyright  *         notice, this list of conditions and the following disclaimer in the  *         documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED ''AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED. IN NO EVENT SHALL AUTHOR BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__UCL_HASH_H
end_ifndef

begin_define
define|#
directive|define
name|__UCL_HASH_H
end_define

begin_include
include|#
directive|include
file|"ucl.h"
end_include

begin_include
include|#
directive|include
file|"uthash.h"
end_include

begin_comment
comment|/******************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ucl_hash_node_s
block|{
specifier|const
name|ucl_object_t
modifier|*
name|data
decl_stmt|;
name|UT_hash_handle
name|hh
decl_stmt|;
block|}
name|ucl_hash_node_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|ucl_hash_cmp_func
parameter_list|(
specifier|const
name|void
modifier|*
name|void_a
parameter_list|,
specifier|const
name|void
modifier|*
name|void_b
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|ucl_hash_free_func
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
modifier|*
name|ucl_hash_iter_t
typedef|;
end_typedef

begin_comment
comment|/**  * Linear chained hashtable.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ucl_hash_struct
block|{
name|ucl_hash_node_t
modifier|*
name|buckets
decl_stmt|;
comment|/**< array of hash buckets. One list for each hash modulus. */
block|}
name|ucl_hash_t
typedef|;
end_typedef

begin_comment
comment|/**  * Initializes the hashtable.  */
end_comment

begin_function_decl
name|ucl_hash_t
modifier|*
name|ucl_hash_create
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Deinitializes the hashtable.  */
end_comment

begin_function_decl
name|void
name|ucl_hash_destroy
parameter_list|(
name|ucl_hash_t
modifier|*
name|hashlin
parameter_list|,
name|ucl_hash_free_func
modifier|*
name|func
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Inserts an element in the the hashtable.  */
end_comment

begin_function_decl
name|void
name|ucl_hash_insert
parameter_list|(
name|ucl_hash_t
modifier|*
name|hashlin
parameter_list|,
specifier|const
name|ucl_object_t
modifier|*
name|obj
parameter_list|,
specifier|const
name|char
modifier|*
name|key
parameter_list|,
name|unsigned
name|keylen
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Delete an element from the the hashtable.  */
end_comment

begin_function_decl
name|void
name|ucl_hash_delete
parameter_list|(
name|ucl_hash_t
modifier|*
name|hashlin
parameter_list|,
specifier|const
name|ucl_object_t
modifier|*
name|obj
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Searches an element in the hashtable.  */
end_comment

begin_function_decl
specifier|const
name|ucl_object_t
modifier|*
name|ucl_hash_search
parameter_list|(
name|ucl_hash_t
modifier|*
name|hashlin
parameter_list|,
specifier|const
name|char
modifier|*
name|key
parameter_list|,
name|unsigned
name|keylen
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Iterate over hash table  * @param hashlin hash  * @param iter iterator (must be NULL on first iteration)  * @return the next object  */
end_comment

begin_function_decl
specifier|const
name|void
modifier|*
name|ucl_hash_iterate
parameter_list|(
name|ucl_hash_t
modifier|*
name|hashlin
parameter_list|,
name|ucl_hash_iter_t
modifier|*
name|iter
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Check whether an iterator has next element  */
end_comment

begin_function_decl
name|bool
name|ucl_hash_iter_has_next
parameter_list|(
name|ucl_hash_iter_t
name|iter
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

