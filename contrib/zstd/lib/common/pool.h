begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  * Copyright (c) 2016-present, Facebook, Inc.  * All rights reserved.  *  * This source code is licensed under the BSD-style license found in the  * LICENSE file in the root directory of this source tree. An additional grant  * of patent rights can be found in the PATENTS file in the same directory.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|POOL_H
end_ifndef

begin_define
define|#
directive|define
name|POOL_H
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__cplusplus
argument_list|)
end_if

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
include|#
directive|include
file|<stddef.h>
comment|/* size_t */
typedef|typedef
name|struct
name|POOL_ctx_s
name|POOL_ctx
typedef|;
comment|/*! POOL_create() :     Create a thread pool with at most `numThreads` threads.     `numThreads` must be at least 1.     The maximum number of queued jobs before blocking is `queueSize`.     `queueSize` must be at least 1.     @return : The POOL_ctx pointer on success else NULL. */
name|POOL_ctx
modifier|*
name|POOL_create
parameter_list|(
name|size_t
name|numThreads
parameter_list|,
name|size_t
name|queueSize
parameter_list|)
function_decl|;
comment|/*! POOL_free() :     Free a thread pool returned by POOL_create(). */
name|void
name|POOL_free
parameter_list|(
name|POOL_ctx
modifier|*
name|ctx
parameter_list|)
function_decl|;
comment|/*! POOL_sizeof() :     return memory usage of pool returned by POOL_create(). */
name|size_t
name|POOL_sizeof
parameter_list|(
name|POOL_ctx
modifier|*
name|ctx
parameter_list|)
function_decl|;
comment|/*! POOL_function :     The function type that can be added to a thread pool. */
typedef|typedef
name|void
function_decl|(
modifier|*
name|POOL_function
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
comment|/*! POOL_add_function :     The function type for a generic thread pool add function. */
typedef|typedef
name|void
function_decl|(
modifier|*
name|POOL_add_function
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|POOL_function
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
comment|/*! POOL_add() :     Add the job `function(opaque)` to the thread pool.     Possibly blocks until there is room in the queue.     Note : The function may be executed asynchronously, so `opaque` must live until the function has been completed. */
name|void
name|POOL_add
parameter_list|(
name|void
modifier|*
name|ctx
parameter_list|,
name|POOL_function
name|function
parameter_list|,
name|void
modifier|*
name|opaque
parameter_list|)
function_decl|;
if|#
directive|if
name|defined
argument_list|(
name|__cplusplus
argument_list|)
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

end_unit

