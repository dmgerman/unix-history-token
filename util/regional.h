begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * regional.h -- region based memory allocator.  *  * Copyright (c) 2007, NLnet Labs. All rights reserved.  *   * This software is open source.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * Redistributions of source code must retain the above copyright notice,  * this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright notice,  * this list of conditions and the following disclaimer in the documentation  * and/or other materials provided with the distribution.  *   * Neither the name of the NLNET LABS nor the names of its contributors may  * be used to endorse or promote products derived from this software without  * specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/**  * \file  * Regional allocator. Allocates small portions of of larger chunks.  * Based on region-allocator from NSD, but rewritten to be light.  *  * Different from (nsd) region-allocator.h  * 	o does not have recycle bin  * 	o does not collect stats; just enough to answer get_mem() in use.  * 	o does not keep cleanup list  * 	o does not have function pointers to setup  * 	o allocs the regional struct inside the first block.  * 	o can take a block to create regional from.  * 	o blocks and large allocations are kept on singly linked lists.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|UTIL_REGIONAL_H_
end_ifndef

begin_define
define|#
directive|define
name|UTIL_REGIONAL_H_
end_define

begin_comment
comment|/**   * the regional* is the first block*.  * every block has a ptr to the next in first bytes.  * and so does the regional struct, which is the first block.  */
end_comment

begin_struct
struct|struct
name|regional
block|{
comment|/**  	 * next chunk. NULL if first chunk is the only chunk.  	 * first inside that chunk is the char* next pointer.  	 * When regional_free_all() has been called this value is NULL. 	 */
name|char
modifier|*
name|next
decl_stmt|;
comment|/** first large object, cast to char** to obtain next ptr */
name|char
modifier|*
name|large_list
decl_stmt|;
comment|/** total large size */
name|size_t
name|total_large
decl_stmt|;
comment|/** initial chunk size */
name|size_t
name|first_size
decl_stmt|;
comment|/** number of bytes available in the current chunk. */
name|size_t
name|available
decl_stmt|;
comment|/** current chunk data position. */
name|char
modifier|*
name|data
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * Create a new regional.  * @return: newly allocated regional.  */
end_comment

begin_function_decl
name|struct
name|regional
modifier|*
name|regional_create
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Create a new region, with custom settings.  * @param size: length of first block.  * @return: newly allocated regional.  */
end_comment

begin_function_decl
name|struct
name|regional
modifier|*
name|regional_create_custom
parameter_list|(
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Free all memory associated with regional. Only keeps the first block with  * the regional inside it.  * @param r: the region.  */
end_comment

begin_function_decl
name|void
name|regional_free_all
parameter_list|(
name|struct
name|regional
modifier|*
name|r
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Destroy regional.  All memory associated with regional is freed as if  * regional_free_all was called, as well as destroying the regional struct.  * @param r: to delete.  */
end_comment

begin_function_decl
name|void
name|regional_destroy
parameter_list|(
name|struct
name|regional
modifier|*
name|r
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Allocate size bytes of memory inside regional.  The memory is  * deallocated when region_free_all is called for this region.  * @param r: the region.  * @param size: number of bytes.  * @return: pointer to memory allocated.  */
end_comment

begin_function_decl
name|void
modifier|*
name|regional_alloc
parameter_list|(
name|struct
name|regional
modifier|*
name|r
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Allocate size bytes of memory inside regional and copy INIT into it.  * The memory is deallocated when region_free_all is called for this  * region.  * @param r: the region.  * @param init: to copy.  * @param size: number of bytes.  * @return: pointer to memory allocated.  */
end_comment

begin_function_decl
name|void
modifier|*
name|regional_alloc_init
parameter_list|(
name|struct
name|regional
modifier|*
name|r
parameter_list|,
specifier|const
name|void
modifier|*
name|init
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Allocate size bytes of memory inside regional that are initialized to  * 0.  The memory is deallocated when region_free_all is called for  * this region.  * @param r: the region.  * @param size: number of bytes.  * @return: pointer to memory allocated.  */
end_comment

begin_function_decl
name|void
modifier|*
name|regional_alloc_zero
parameter_list|(
name|struct
name|regional
modifier|*
name|r
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Duplicate string and allocate the result in regional.  * @param r: the region.  * @param string: null terminated string.  * @return: pointer to memory allocated.  */
end_comment

begin_function_decl
name|char
modifier|*
name|regional_strdup
parameter_list|(
name|struct
name|regional
modifier|*
name|r
parameter_list|,
specifier|const
name|char
modifier|*
name|string
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Debug print regional statistics to log */
end_comment

begin_function_decl
name|void
name|regional_log_stats
parameter_list|(
name|struct
name|regional
modifier|*
name|r
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** get total memory size in use by region */
end_comment

begin_function_decl
name|size_t
name|regional_get_mem
parameter_list|(
name|struct
name|regional
modifier|*
name|r
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UTIL_REGIONAL_H_ */
end_comment

end_unit

