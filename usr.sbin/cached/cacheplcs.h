begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2005 Michael Bushkov<bushman@rsu.ru>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__CACHED_CACHEPLCS_H__
end_ifndef

begin_define
define|#
directive|define
name|__CACHED_CACHEPLCS_H__
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

begin_comment
comment|/* common policy definitions */
end_comment

begin_define
define|#
directive|define
name|CACHELIB_MAX_FREQUENCY
value|100
end_define

begin_comment
comment|/*  * cache_policy_item_ represents some abstract cache element in the policy  * queue. connected_item pointers to the corresponding cache_policy_item_ in  * another policy queue.  */
end_comment

begin_struct
struct|struct
name|cache_policy_item_
block|{
name|char
modifier|*
name|key
decl_stmt|;
name|size_t
name|key_size
decl_stmt|;
name|size_t
name|request_count
decl_stmt|;
name|struct
name|timeval
name|last_request_time
decl_stmt|;
name|struct
name|timeval
name|creation_time
decl_stmt|;
name|struct
name|cache_policy_item_
modifier|*
name|connected_item
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * cache_policy_ represents an abstract policy queue. It can be customized by  * setting appropriate function pointers  */
end_comment

begin_struct
struct|struct
name|cache_policy_
block|{
name|struct
name|cache_policy_item_
modifier|*
function_decl|(
modifier|*
name|create_item_func
function_decl|)
parameter_list|()
function_decl|;
name|void
function_decl|(
modifier|*
name|destroy_item_func
function_decl|)
parameter_list|(
name|struct
name|cache_policy_item_
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|add_item_func
function_decl|)
parameter_list|(
name|struct
name|cache_policy_
modifier|*
parameter_list|,
name|struct
name|cache_policy_item_
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|remove_item_func
function_decl|)
parameter_list|(
name|struct
name|cache_policy_
modifier|*
parameter_list|,
name|struct
name|cache_policy_item_
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|update_item_func
function_decl|)
parameter_list|(
name|struct
name|cache_policy_
modifier|*
parameter_list|,
name|struct
name|cache_policy_item_
modifier|*
parameter_list|)
function_decl|;
name|struct
name|cache_policy_item_
modifier|*
function_decl|(
modifier|*
name|get_first_item_func
function_decl|)
parameter_list|(
name|struct
name|cache_policy_
modifier|*
parameter_list|)
function_decl|;
name|struct
name|cache_policy_item_
modifier|*
function_decl|(
modifier|*
name|get_last_item_func
function_decl|)
parameter_list|(
name|struct
name|cache_policy_
modifier|*
parameter_list|)
function_decl|;
name|struct
name|cache_policy_item_
modifier|*
function_decl|(
modifier|*
name|get_next_item_func
function_decl|)
parameter_list|(
name|struct
name|cache_policy_
modifier|*
parameter_list|,
name|struct
name|cache_policy_item_
modifier|*
parameter_list|)
function_decl|;
name|struct
name|cache_policy_item_
modifier|*
function_decl|(
modifier|*
name|get_prev_item_func
function_decl|)
parameter_list|(
name|struct
name|cache_policy_
modifier|*
parameter_list|,
name|struct
name|cache_policy_item_
modifier|*
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * LFU cache policy item "inherited" from cache_policy_item_ structure  */
end_comment

begin_struct
struct|struct
name|cache_lfu_policy_item_
block|{
name|struct
name|cache_policy_item_
name|parent_data
decl_stmt|;
name|int
name|frequency
decl_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|cache_lfu_policy_item_
argument_list|)
name|entries
expr_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|cache_lfu_policy_group_
argument_list|,
name|cache_lfu_policy_item_
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * LFU policy queue "inherited" from cache_policy_.  */
end_comment

begin_struct
struct|struct
name|cache_lfu_policy_
block|{
name|struct
name|cache_policy_
name|parent_data
decl_stmt|;
name|struct
name|cache_lfu_policy_group_
name|groups
index|[
name|CACHELIB_MAX_FREQUENCY
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * LRU and FIFO policies item "inherited" from cache_policy_item_  */
end_comment

begin_struct
struct|struct
name|cache_queue_policy_item_
block|{
name|struct
name|cache_policy_item_
name|parent_data
decl_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|cache_queue_policy_item_
argument_list|)
name|entries
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * LRU and FIFO policies "inherited" from cache_policy_  */
end_comment

begin_struct
struct|struct
name|cache_queue_policy_
block|{
name|struct
name|cache_policy_
name|parent_data
decl_stmt|;
name|TAILQ_HEAD
argument_list|(
argument|cache_queue_policy_head_
argument_list|,
argument|cache_queue_policy_item_
argument_list|)
name|head
expr_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|cache_queue_policy_
name|cache_fifo_policy_
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|cache_queue_policy_
name|cache_lru_policy_
typedef|;
end_typedef

begin_comment
comment|/* fifo policy routines */
end_comment

begin_function_decl
specifier|extern
name|struct
name|cache_policy_
modifier|*
name|init_cache_fifo_policy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|destroy_cache_fifo_policy
parameter_list|(
name|struct
name|cache_policy_
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* lru policy routines */
end_comment

begin_function_decl
specifier|extern
name|struct
name|cache_policy_
modifier|*
name|init_cache_lru_policy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|destroy_cache_lru_policy
parameter_list|(
name|struct
name|cache_policy_
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* lfu policy routines */
end_comment

begin_function_decl
specifier|extern
name|struct
name|cache_policy_
modifier|*
name|init_cache_lfu_policy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|destroy_cache_lfu_policy
parameter_list|(
name|struct
name|cache_policy_
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

