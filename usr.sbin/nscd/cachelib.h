begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2005 Michael Bushkov<bushman@rsu.ru>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__CACHED_CACHELIB_H__
end_ifndef

begin_define
define|#
directive|define
name|__CACHED_CACHELIB_H__
end_define

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|"hashtable.h"
end_include

begin_include
include|#
directive|include
file|"cacheplcs.h"
end_include

begin_enum
enum|enum
name|cache_entry_t
block|{
name|CET_COMMON
init|=
literal|0
block|,
comment|/* cache item is atomic */
name|CET_MULTIPART
comment|/* cache item is formed part by part */
block|}
enum|;
end_enum

begin_enum
enum|enum
name|cache_transformation_t
block|{
name|CTT_FLUSH
init|=
literal|0
block|,
comment|/* flush the cache - delete all obsolete items */
name|CTT_CLEAR
init|=
literal|1
comment|/* delete all items in the cache */
block|}
enum|;
end_enum

begin_comment
comment|/* cache deletion policy type enum */
end_comment

begin_enum
enum|enum
name|cache_policy_t
block|{
name|CPT_FIFO
init|=
literal|0
block|,
comment|/* first-in first-out */
name|CPT_LRU
init|=
literal|1
block|,
comment|/* least recently used */
name|CPT_LFU
init|=
literal|2
comment|/* least frequently used */
block|}
enum|;
end_enum

begin_comment
comment|/* multipart sessions can be used for reading and writing */
end_comment

begin_enum
enum|enum
name|cache_mp_session_t
block|{
name|CMPT_READ_SESSION
block|,
name|CMPT_WRITE_SESSION
block|}
enum|;
end_enum

begin_comment
comment|/*  * When doing partial transformations of entries (which are applied for  * elements with keys, that contain specified buffer in its left or  * right part), this enum will show the needed position of the key part.  */
end_comment

begin_enum
enum|enum
name|part_position_t
block|{
name|KPPT_LEFT
block|,
name|KPPT_RIGHT
block|}
enum|;
end_enum

begin_comment
comment|/* num_levels attribute is obsolete, i think - user can always emulate it  * by using one entry.  * get_time_func is needed to have the clocks-independent counter  */
end_comment

begin_struct
struct|struct
name|cache_params
block|{
name|void
function_decl|(
modifier|*
name|get_time_func
function_decl|)
parameter_list|(
name|struct
name|timeval
modifier|*
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * base structure - normal_cache_entry_params and multipart_cache_entry_params  * are "inherited" from it  */
end_comment

begin_struct
struct|struct
name|cache_entry_params
block|{
name|enum
name|cache_entry_t
name|entry_type
decl_stmt|;
name|char
modifier|*
name|entry_name
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* params, used for most entries */
end_comment

begin_struct
struct|struct
name|common_cache_entry_params
block|{
comment|/* inherited fields */
name|enum
name|cache_entry_t
name|entry_type
decl_stmt|;
comment|/* unique fields */
name|char
modifier|*
name|entry_name
decl_stmt|;
name|size_t
name|cache_entries_size
decl_stmt|;
name|size_t
name|max_elemsize
decl_stmt|;
comment|/* if 0 then no check is made */
name|size_t
name|satisf_elemsize
decl_stmt|;
comment|/* if entry size is exceeded, 					 * this number of elements will be left, 					 * others will be deleted */
name|struct
name|timeval
name|max_lifetime
decl_stmt|;
comment|/* if 0 then no check is made */
name|enum
name|cache_policy_t
name|policy
decl_stmt|;
comment|/* policy used for transformations */
block|}
struct|;
end_struct

begin_comment
comment|/* params, used for multipart entries */
end_comment

begin_struct
struct|struct
name|mp_cache_entry_params
block|{
comment|/* inherited fields */
name|enum
name|cache_entry_t
name|entry_type
decl_stmt|;
name|char
modifier|*
name|entry_name
decl_stmt|;
comment|/* unique fields */
name|size_t
name|max_elemsize
decl_stmt|;
comment|/* if 0 then no check is made */
name|size_t
name|max_sessions
decl_stmt|;
comment|/* maximum number of active sessions */
name|struct
name|timeval
name|max_lifetime
decl_stmt|;
comment|/* maximum elements lifetime */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cache_ht_item_data_
block|{
comment|/* key is the bytes sequence only - not the null-terminated string */
name|char
modifier|*
name|key
decl_stmt|;
name|size_t
name|key_size
decl_stmt|;
name|char
modifier|*
name|value
decl_stmt|;
name|size_t
name|value_size
decl_stmt|;
name|struct
name|cache_policy_item_
modifier|*
name|fifo_policy_item
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cache_ht_item_
block|{
name|HASHTABLE_ENTRY_HEAD
argument_list|(
argument|ht_item_
argument_list|,
argument|struct cache_ht_item_data_
argument_list|)
name|data
expr_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cache_entry_
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|struct
name|cache_entry_params
modifier|*
name|params
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cache_common_entry_
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|struct
name|cache_entry_params
modifier|*
name|params
decl_stmt|;
name|struct
name|common_cache_entry_params
name|common_params
decl_stmt|;
name|HASHTABLE_HEAD
argument_list|(
argument|cache_ht_
argument_list|,
argument|cache_ht_item_
argument_list|)
name|items
expr_stmt|;
name|size_t
name|items_size
decl_stmt|;
comment|/* 	 * Entry always has the FIFO policy, that is used to eliminate old 	 * elements (the ones, with lifetime more than max_lifetime). Besides, 	 * user can specify another policy to be applied, when there are too 	 * many elements in the entry. So policies_size can be 1 or 2. 	 */
name|struct
name|cache_policy_
modifier|*
modifier|*
name|policies
decl_stmt|;
name|size_t
name|policies_size
decl_stmt|;
name|void
function_decl|(
modifier|*
name|get_time_func
function_decl|)
parameter_list|(
name|struct
name|timeval
modifier|*
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cache_mp_data_item_
block|{
name|char
modifier|*
name|value
decl_stmt|;
name|size_t
name|value_size
decl_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|cache_mp_data_item_
argument_list|)
name|entries
expr_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cache_mp_write_session_
block|{
name|struct
name|cache_mp_entry_
modifier|*
name|parent_entry
decl_stmt|;
comment|/* 	 * All items are accumulated in this queue. When the session is 	 * committed, they all will be copied to the multipart entry. 	 */
name|TAILQ_HEAD
argument_list|(
argument|cache_mp_data_item_head
argument_list|,
argument|cache_mp_data_item_
argument_list|)
name|items
expr_stmt|;
name|size_t
name|items_size
decl_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|cache_mp_write_session_
argument_list|)
name|entries
expr_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cache_mp_read_session_
block|{
name|struct
name|cache_mp_entry_
modifier|*
name|parent_entry
decl_stmt|;
name|struct
name|cache_mp_data_item_
modifier|*
name|current_item
decl_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|cache_mp_read_session_
argument_list|)
name|entries
expr_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cache_mp_entry_
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|struct
name|cache_entry_params
modifier|*
name|params
decl_stmt|;
name|struct
name|mp_cache_entry_params
name|mp_params
decl_stmt|;
comment|/* All opened write sessions */
name|TAILQ_HEAD
argument_list|(
argument|write_sessions_head
argument_list|,
argument|cache_mp_write_session_
argument_list|)
name|ws_head
expr_stmt|;
name|size_t
name|ws_size
decl_stmt|;
comment|/* All opened read sessions */
name|TAILQ_HEAD
argument_list|(
argument|read_sessions_head
argument_list|,
argument|cache_mp_read_session_
argument_list|)
name|rs_head
expr_stmt|;
name|size_t
name|rs_size
decl_stmt|;
comment|/* 	 * completed_write_session is the committed write sessions. All read 	 * sessions use data from it. If the completed_write_session is out of 	 * date, but still in use by some of the read sessions, the newly 	 * committed write session is stored in the pending_write_session. 	 * In such a case, completed_write_session will be substituted with 	 * pending_write_session as soon as it won't be used by any of 	 * the read sessions. 	 */
name|struct
name|cache_mp_write_session_
modifier|*
name|completed_write_session
decl_stmt|;
name|struct
name|cache_mp_write_session_
modifier|*
name|pending_write_session
decl_stmt|;
name|struct
name|timeval
name|creation_time
decl_stmt|;
name|struct
name|timeval
name|last_request_time
decl_stmt|;
name|void
function_decl|(
modifier|*
name|get_time_func
function_decl|)
parameter_list|(
name|struct
name|timeval
modifier|*
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cache_
block|{
name|struct
name|cache_params
name|params
decl_stmt|;
name|struct
name|cache_entry_
modifier|*
modifier|*
name|entries
decl_stmt|;
name|size_t
name|entries_capacity
decl_stmt|;
name|size_t
name|entries_size
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* simple abstractions - for not to write "struct" every time */
end_comment

begin_typedef
typedef|typedef
name|struct
name|cache_
modifier|*
name|cache
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|cache_entry_
modifier|*
name|cache_entry
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|cache_mp_write_session_
modifier|*
name|cache_mp_write_session
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|cache_mp_read_session_
modifier|*
name|cache_mp_read_session
typedef|;
end_typedef

begin_define
define|#
directive|define
name|INVALID_CACHE
value|(NULL)
end_define

begin_define
define|#
directive|define
name|INVALID_CACHE_ENTRY
value|(NULL)
end_define

begin_define
define|#
directive|define
name|INVALID_CACHE_MP_WRITE_SESSION
value|(NULL)
end_define

begin_define
define|#
directive|define
name|INVALID_CACHE_MP_READ_SESSION
value|(NULL)
end_define

begin_comment
comment|/*  * NOTE: all cache operations are thread-unsafe. You must ensure thread-safety  * externally, by yourself.  */
end_comment

begin_comment
comment|/* cache initialization/destruction routines */
end_comment

begin_function_decl
specifier|extern
name|cache
name|init_cache
parameter_list|(
name|struct
name|cache_params
specifier|const
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|destroy_cache
parameter_list|(
name|cache
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* cache entries manipulation routines */
end_comment

begin_function_decl
specifier|extern
name|int
name|register_cache_entry
parameter_list|(
name|cache
parameter_list|,
name|struct
name|cache_entry_params
specifier|const
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|unregister_cache_entry
parameter_list|(
name|cache
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|cache_entry
name|find_cache_entry
parameter_list|(
name|cache
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* read/write operations used on common entries */
end_comment

begin_function_decl
specifier|extern
name|int
name|cache_read
parameter_list|(
name|cache_entry
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|cache_write
parameter_list|(
name|cache_entry
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|char
specifier|const
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* read/write operations used on multipart entries */
end_comment

begin_function_decl
specifier|extern
name|cache_mp_write_session
name|open_cache_mp_write_session
parameter_list|(
name|cache_entry
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|cache_mp_write
parameter_list|(
name|cache_mp_write_session
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|abandon_cache_mp_write_session
parameter_list|(
name|cache_mp_write_session
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|close_cache_mp_write_session
parameter_list|(
name|cache_mp_write_session
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|cache_mp_read_session
name|open_cache_mp_read_session
parameter_list|(
name|cache_entry
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|cache_mp_read
parameter_list|(
name|cache_mp_read_session
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|close_cache_mp_read_session
parameter_list|(
name|cache_mp_read_session
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* transformation routines */
end_comment

begin_function_decl
specifier|extern
name|int
name|transform_cache_entry
parameter_list|(
name|cache_entry
parameter_list|,
name|enum
name|cache_transformation_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|transform_cache_entry_part
parameter_list|(
name|cache_entry
parameter_list|,
name|enum
name|cache_transformation_t
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|enum
name|part_position_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

