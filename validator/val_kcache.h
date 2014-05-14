begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * validator/val_kcache.h - validator key shared cache with validated keys  *  * Copyright (c) 2007, NLnet Labs. All rights reserved.  *  * This software is open source.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * Redistributions of source code must retain the above copyright notice,  * this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright notice,  * this list of conditions and the following disclaimer in the documentation  * and/or other materials provided with the distribution.  *   * Neither the name of the NLNET LABS nor the names of its contributors may  * be used to endorse or promote products derived from this software without  * specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/**  * \file  *  * This file contains functions for caching validated key entries.   */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VALIDATOR_VAL_KCACHE_H
end_ifndef

begin_define
define|#
directive|define
name|VALIDATOR_VAL_KCACHE_H
end_define

begin_include
include|#
directive|include
file|"util/storage/slabhash.h"
end_include

begin_struct_decl
struct_decl|struct
name|key_entry_key
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|key_entry_data
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|config_file
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|regional
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|module_qstate
struct_decl|;
end_struct_decl

begin_comment
comment|/**  * Key cache  */
end_comment

begin_struct
struct|struct
name|key_cache
block|{
comment|/** uses slabhash for storage, type key_entry_key, key_entry_data */
name|struct
name|slabhash
modifier|*
name|slab
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * Create the key cache  * @param cfg: config settings for the key cache.  * @return new key cache or NULL on malloc failure.  */
end_comment

begin_function_decl
name|struct
name|key_cache
modifier|*
name|key_cache_create
parameter_list|(
name|struct
name|config_file
modifier|*
name|cfg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Delete the key cache  * @param kcache: to delete  */
end_comment

begin_function_decl
name|void
name|key_cache_delete
parameter_list|(
name|struct
name|key_cache
modifier|*
name|kcache
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Insert or update a key cache entry. Note that the insert may silently  * fail if there is not enough memory.  *  * @param kcache: the key cache.  * @param kkey: key entry key, assumed malloced in a region, is copied  * 	to perform update or insertion. Its data pointer is also copied.  * @param qstate: store errinf reason in case its bad.  */
end_comment

begin_function_decl
name|void
name|key_cache_insert
parameter_list|(
name|struct
name|key_cache
modifier|*
name|kcache
parameter_list|,
name|struct
name|key_entry_key
modifier|*
name|kkey
parameter_list|,
name|struct
name|module_qstate
modifier|*
name|qstate
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Remove an entry from the key cache.  * @param kcache: the key cache.  * @param name: for what name to look; uncompressed wireformat  * @param namelen: length of the name.  * @param key_class: class of the key.  */
end_comment

begin_function_decl
name|void
name|key_cache_remove
parameter_list|(
name|struct
name|key_cache
modifier|*
name|kcache
parameter_list|,
name|uint8_t
modifier|*
name|name
parameter_list|,
name|size_t
name|namelen
parameter_list|,
name|uint16_t
name|key_class
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Lookup key entry in the cache. Looks up the closest key entry above the  * given name.  * @param kcache: the key cache.  * @param name: for what name to look; uncompressed wireformat  * @param namelen: length of the name.  * @param key_class: class of the key.  * @param region: a copy of the key_entry is allocated in this region.  * @param now: current time.  * @return pointer to a newly allocated key_entry copy in the region, if  * 	a key entry could be found, and allocation succeeded and TTL was OK.  * 	Otherwise, NULL is returned.  */
end_comment

begin_function_decl
name|struct
name|key_entry_key
modifier|*
name|key_cache_obtain
parameter_list|(
name|struct
name|key_cache
modifier|*
name|kcache
parameter_list|,
name|uint8_t
modifier|*
name|name
parameter_list|,
name|size_t
name|namelen
parameter_list|,
name|uint16_t
name|key_class
parameter_list|,
name|struct
name|regional
modifier|*
name|region
parameter_list|,
name|time_t
name|now
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Get memory in use by the key cache.  * @param kcache: the key cache.  * @return memory in use in bytes.  */
end_comment

begin_function_decl
name|size_t
name|key_cache_get_mem
parameter_list|(
name|struct
name|key_cache
modifier|*
name|kcache
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VALIDATOR_VAL_KCACHE_H */
end_comment

end_unit

