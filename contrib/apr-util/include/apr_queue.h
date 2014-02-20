begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Licensed to the Apache Software Foundation (ASF) under one or more  * contributor license agreements.  See the NOTICE file distributed with  * this work for additional information regarding copyright ownership.  * The ASF licenses this file to You under the Apache License, Version 2.0  * (the "License"); you may not use this file except in compliance with  * the License.  You may obtain a copy of the License at  *  *     http://www.apache.org/licenses/LICENSE-2.0  *  * Unless required by applicable law or agreed to in writing, software  * distributed under the License is distributed on an "AS IS" BASIS,  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  * See the License for the specific language governing permissions and  * limitations under the License.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|APR_QUEUE_H
end_ifndef

begin_define
define|#
directive|define
name|APR_QUEUE_H
end_define

begin_comment
comment|/**  * @file apr_queue.h  * @brief Thread Safe FIFO bounded queue  * @note Since most implementations of the queue are backed by a condition  * variable implementation, it isn't available on systems without threads.  * Although condition variables are sometimes available without threads.  */
end_comment

begin_include
include|#
directive|include
file|"apu.h"
end_include

begin_include
include|#
directive|include
file|"apr_errno.h"
end_include

begin_include
include|#
directive|include
file|"apr_pools.h"
end_include

begin_if
if|#
directive|if
name|APR_HAS_THREADS
end_if

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
comment|/**  * @defgroup APR_Util_FIFO Thread Safe FIFO bounded queue  * @ingroup APR_Util  * @{  */
comment|/**  * opaque structure  */
typedef|typedef
name|struct
name|apr_queue_t
name|apr_queue_t
typedef|;
comment|/**   * create a FIFO queue  * @param queue The new queue  * @param queue_capacity maximum size of the queue  * @param a pool to allocate queue from  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_queue_create
argument_list|(
argument|apr_queue_t **queue
argument_list|,
argument|unsigned int queue_capacity
argument_list|,
argument|apr_pool_t *a
argument_list|)
empty_stmt|;
comment|/**  * push/add an object to the queue, blocking if the queue is already full  *  * @param queue the queue  * @param data the data  * @returns APR_EINTR the blocking was interrupted (try again)  * @returns APR_EOF the queue has been terminated  * @returns APR_SUCCESS on a successful push  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_queue_push
argument_list|(
name|apr_queue_t
operator|*
name|queue
argument_list|,
name|void
operator|*
name|data
argument_list|)
expr_stmt|;
comment|/**  * pop/get an object from the queue, blocking if the queue is already empty  *  * @param queue the queue  * @param data the data  * @returns APR_EINTR the blocking was interrupted (try again)  * @returns APR_EOF if the queue has been terminated  * @returns APR_SUCCESS on a successful pop  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_queue_pop
argument_list|(
name|apr_queue_t
operator|*
name|queue
argument_list|,
name|void
operator|*
operator|*
name|data
argument_list|)
expr_stmt|;
comment|/**  * push/add an object to the queue, returning immediately if the queue is full  *  * @param queue the queue  * @param data the data  * @returns APR_EINTR the blocking operation was interrupted (try again)  * @returns APR_EAGAIN the queue is full  * @returns APR_EOF the queue has been terminated  * @returns APR_SUCCESS on a successful push  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_queue_trypush
argument_list|(
name|apr_queue_t
operator|*
name|queue
argument_list|,
name|void
operator|*
name|data
argument_list|)
expr_stmt|;
comment|/**  * pop/get an object to the queue, returning immediately if the queue is empty  *  * @param queue the queue  * @param data the data  * @returns APR_EINTR the blocking operation was interrupted (try again)  * @returns APR_EAGAIN the queue is empty  * @returns APR_EOF the queue has been terminated  * @returns APR_SUCCESS on a successful pop  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_queue_trypop
argument_list|(
name|apr_queue_t
operator|*
name|queue
argument_list|,
name|void
operator|*
operator|*
name|data
argument_list|)
expr_stmt|;
comment|/**  * returns the size of the queue.  *  * @warning this is not threadsafe, and is intended for reporting/monitoring  * of the queue.  * @param queue the queue  * @returns the size of the queue  */
name|APU_DECLARE
argument_list|(
argument|unsigned int
argument_list|)
name|apr_queue_size
argument_list|(
name|apr_queue_t
operator|*
name|queue
argument_list|)
expr_stmt|;
comment|/**  * interrupt all the threads blocking on this queue.  *  * @param queue the queue  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_queue_interrupt_all
argument_list|(
name|apr_queue_t
operator|*
name|queue
argument_list|)
expr_stmt|;
comment|/**  * terminate the queue, sending an interrupt to all the  * blocking threads  *  * @param queue the queue  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_queue_term
argument_list|(
name|apr_queue_t
operator|*
name|queue
argument_list|)
expr_stmt|;
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
comment|/** @} */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* APR_HAS_THREADS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* APRQUEUE_H */
end_comment

end_unit

