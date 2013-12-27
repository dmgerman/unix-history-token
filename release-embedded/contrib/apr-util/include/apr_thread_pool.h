begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Licensed to the Apache Software Foundation (ASF) under one or more  * contributor license agreements.  See the NOTICE file distributed  * with this work for additional information regarding copyright  * ownership.  The ASF licenses this file to you under the Apache  * License, Version 2.0 (the "License"); you may not use this file  * except in compliance with the License.  You may obtain a copy of  * the License at  *  *     http://www.apache.org/licenses/LICENSE-2.0  *  * Unless required by applicable law or agreed to in writing, software  * distributed under the License is distributed on an "AS IS" BASIS,  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or  * implied.  See the License for the specific language governing  * permissions and limitations under the License.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|APU_THREAD_POOL_H
end_ifndef

begin_define
define|#
directive|define
name|APU_THREAD_POOL_H
end_define

begin_include
include|#
directive|include
file|"apu.h"
end_include

begin_include
include|#
directive|include
file|"apr_thread_proc.h"
end_include

begin_comment
comment|/**  * @file apr_thread_pool.h  * @brief APR Thread Pool Library   * @remarks This library implements a thread pool using apr_thread_t. A thread  * pool is a set of threads that can be created in advance or on demand until a  * maximum number. When a task is scheduled, the thread pool will find an idle  * thread to handle the task. In case all existing threads are busy and the  * number of tasks in the queue is higher than the adjustable threshold, the  * pool will try to create a new thread to serve the task if the maximum number  * has not been reached. Otherwise, the task will be put into a queue based on  * priority, which can be valued from 0 to 255, with higher values being served  * first. If there are tasks with the same priority, the new task might be put at  * the top or at the bottom - it depends on which function is used to put the task.  *  * @remarks There may be the case where the thread pool can use up to the maximum  * number of threads at peak load, but having those threads idle afterwards. A  * maximum number of idle threads can be set so that the extra idling threads will  * be terminated to save system resources.  */
end_comment

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
comment|/**  * @defgroup APR_Util_TP Thread Pool routines  * @ingroup APR_Util  * @{  */
comment|/** Opaque Thread Pool structure. */
typedef|typedef
name|struct
name|apr_thread_pool
name|apr_thread_pool_t
typedef|;
define|#
directive|define
name|APR_THREAD_TASK_PRIORITY_LOWEST
value|0
define|#
directive|define
name|APR_THREAD_TASK_PRIORITY_LOW
value|63
define|#
directive|define
name|APR_THREAD_TASK_PRIORITY_NORMAL
value|127
define|#
directive|define
name|APR_THREAD_TASK_PRIORITY_HIGH
value|191
define|#
directive|define
name|APR_THREAD_TASK_PRIORITY_HIGHEST
value|255
comment|/**  * Create a thread pool  * @param me The pointer in which to return the newly created apr_thread_pool  * object, or NULL if thread pool creation fails.  * @param init_threads The number of threads to be created initially, this number  * will also be used as the initial value for the maximum number of idle threads.  * @param max_threads The maximum number of threads that can be created  * @param pool The pool to use  * @return APR_SUCCESS if the thread pool was created successfully. Otherwise,  * the error code.  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_thread_pool_create
argument_list|(
argument|apr_thread_pool_t **me
argument_list|,
argument|apr_size_t init_threads
argument_list|,
argument|apr_size_t max_threads
argument_list|,
argument|apr_pool_t *pool
argument_list|)
empty_stmt|;
comment|/**  * Destroy the thread pool and stop all the threads  * @return APR_SUCCESS if all threads are stopped.  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_thread_pool_destroy
argument_list|(
name|apr_thread_pool_t
operator|*
name|me
argument_list|)
expr_stmt|;
comment|/**  * Schedule a task to the bottom of the tasks of same priority.  * @param me The thread pool  * @param func The task function  * @param param The parameter for the task function  * @param priority The priority of the task.  * @param owner Owner of this task.  * @return APR_SUCCESS if the task had been scheduled successfully  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_thread_pool_push
argument_list|(
argument|apr_thread_pool_t *me
argument_list|,
argument|apr_thread_start_t func
argument_list|,
argument|void *param
argument_list|,
argument|apr_byte_t priority
argument_list|,
argument|void *owner
argument_list|)
empty_stmt|;
comment|/**  * Schedule a task to be run after a delay  * @param me The thread pool  * @param func The task function  * @param param The parameter for the task function  * @param time Time in microseconds  * @param owner Owner of this task.  * @return APR_SUCCESS if the task had been scheduled successfully  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_thread_pool_schedule
argument_list|(
argument|apr_thread_pool_t *me
argument_list|,
argument|apr_thread_start_t func
argument_list|,
argument|void *param
argument_list|,
argument|apr_interval_time_t time
argument_list|,
argument|void *owner
argument_list|)
empty_stmt|;
comment|/**  * Schedule a task to the top of the tasks of same priority.  * @param me The thread pool  * @param func The task function  * @param param The parameter for the task function  * @param priority The priority of the task.  * @param owner Owner of this task.  * @return APR_SUCCESS if the task had been scheduled successfully  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_thread_pool_top
argument_list|(
argument|apr_thread_pool_t *me
argument_list|,
argument|apr_thread_start_t func
argument_list|,
argument|void *param
argument_list|,
argument|apr_byte_t priority
argument_list|,
argument|void *owner
argument_list|)
empty_stmt|;
comment|/**  * Cancel tasks submitted by the owner. If there is any task from the owner that  * is currently running, the function will spin until the task finished.  * @param me The thread pool  * @param owner Owner of the task  * @return APR_SUCCESS if the task has been cancelled successfully  * @note The task function should not be calling cancel, otherwise the function  * may get stuck forever. The function assert if it detect such a case.  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_thread_pool_tasks_cancel
argument_list|(
name|apr_thread_pool_t
operator|*
name|me
argument_list|,
name|void
operator|*
name|owner
argument_list|)
expr_stmt|;
comment|/**  * Get the current number of tasks waiting in the queue  * @param me The thread pool  * @return Number of tasks in the queue  */
name|APU_DECLARE
argument_list|(
argument|apr_size_t
argument_list|)
name|apr_thread_pool_tasks_count
argument_list|(
name|apr_thread_pool_t
operator|*
name|me
argument_list|)
expr_stmt|;
comment|/**  * Get the current number of scheduled tasks waiting in the queue  * @param me The thread pool  * @return Number of scheduled tasks in the queue  */
name|APU_DECLARE
argument_list|(
argument|apr_size_t
argument_list|)
name|apr_thread_pool_scheduled_tasks_count
argument_list|(
name|apr_thread_pool_t
operator|*
name|me
argument_list|)
expr_stmt|;
comment|/**  * Get the current number of threads  * @param me The thread pool  * @return Total number of threads  */
name|APU_DECLARE
argument_list|(
argument|apr_size_t
argument_list|)
name|apr_thread_pool_threads_count
argument_list|(
name|apr_thread_pool_t
operator|*
name|me
argument_list|)
expr_stmt|;
comment|/**  * Get the current number of busy threads  * @param me The thread pool  * @return Number of busy threads  */
name|APU_DECLARE
argument_list|(
argument|apr_size_t
argument_list|)
name|apr_thread_pool_busy_count
argument_list|(
name|apr_thread_pool_t
operator|*
name|me
argument_list|)
expr_stmt|;
comment|/**  * Get the current number of idle threads  * @param me The thread pool  * @return Number of idle threads  */
name|APU_DECLARE
argument_list|(
argument|apr_size_t
argument_list|)
name|apr_thread_pool_idle_count
argument_list|(
name|apr_thread_pool_t
operator|*
name|me
argument_list|)
expr_stmt|;
comment|/**  * Access function for the maximum number of idle threads. Number of current  * idle threads will be reduced to the new limit.  * @param me The thread pool  * @param cnt The number  * @return The number of threads that were stopped.  */
name|APU_DECLARE
argument_list|(
argument|apr_size_t
argument_list|)
name|apr_thread_pool_idle_max_set
argument_list|(
argument|apr_thread_pool_t *me
argument_list|,
argument|apr_size_t cnt
argument_list|)
empty_stmt|;
comment|/**  * Get number of tasks that have run  * @param me The thread pool  * @return Number of tasks that have run  */
name|APU_DECLARE
argument_list|(
argument|apr_size_t
argument_list|)
name|apr_thread_pool_tasks_run_count
argument_list|(
name|apr_thread_pool_t
operator|*
name|me
argument_list|)
expr_stmt|;
comment|/**  * Get high water mark of the number of tasks waiting to run  * @param me The thread pool  * @return High water mark of tasks waiting to run  */
name|APU_DECLARE
argument_list|(
argument|apr_size_t
argument_list|)
name|apr_thread_pool_tasks_high_count
argument_list|(
name|apr_thread_pool_t
operator|*
name|me
argument_list|)
expr_stmt|;
comment|/**  * Get high water mark of the number of threads  * @param me The thread pool  * @return High water mark of threads in thread pool  */
name|APU_DECLARE
argument_list|(
argument|apr_size_t
argument_list|)
name|apr_thread_pool_threads_high_count
argument_list|(
name|apr_thread_pool_t
operator|*
name|me
argument_list|)
expr_stmt|;
comment|/**  * Get the number of idle threads that were destroyed after timing out  * @param me The thread pool  * @return Number of idle threads that timed out  */
name|APU_DECLARE
argument_list|(
argument|apr_size_t
argument_list|)
name|apr_thread_pool_threads_idle_timeout_count
argument_list|(
name|apr_thread_pool_t
operator|*
name|me
argument_list|)
expr_stmt|;
comment|/**  * Access function for the maximum number of idle threads  * @param me The thread pool  * @return The current maximum number  */
name|APU_DECLARE
argument_list|(
argument|apr_size_t
argument_list|)
name|apr_thread_pool_idle_max_get
argument_list|(
name|apr_thread_pool_t
operator|*
name|me
argument_list|)
expr_stmt|;
comment|/**  * Access function for the maximum number of threads.  * @param me The thread pool  * @param cnt Number of threads  * @return The original maximum number of threads  */
name|APU_DECLARE
argument_list|(
argument|apr_size_t
argument_list|)
name|apr_thread_pool_thread_max_set
argument_list|(
argument|apr_thread_pool_t *me
argument_list|,
argument|apr_size_t cnt
argument_list|)
empty_stmt|;
comment|/**  * Access function for the maximum wait time (in microseconds) of an  * idling thread that exceeds the maximum number of idling threads.  * A non-zero value allows for the reaping of idling threads to shrink  * over time.  Which helps reduce thrashing.  * @param me The thread pool  * @param timeout The number of microseconds an idle thread should wait  * till it reaps itself  * @return The original maximum wait time  */
name|APU_DECLARE
argument_list|(
argument|apr_interval_time_t
argument_list|)
name|apr_thread_pool_idle_wait_set
argument_list|(
argument|apr_thread_pool_t * me
argument_list|,
argument|apr_interval_time_t timeout
argument_list|)
empty_stmt|;
comment|/**  * Access function for the maximum wait time (in microseconds) of an  * idling thread that exceeds the maximum number of idling threads  * @param me The thread pool  * @return The current maximum wait time  */
name|APU_DECLARE
argument_list|(
argument|apr_interval_time_t
argument_list|)
name|apr_thread_pool_idle_wait_get
argument_list|(
name|apr_thread_pool_t
operator|*
name|me
argument_list|)
expr_stmt|;
comment|/**  * Access function for the maximum number of threads  * @param me The thread pool  * @return The current maximum number  */
name|APU_DECLARE
argument_list|(
argument|apr_size_t
argument_list|)
name|apr_thread_pool_thread_max_get
argument_list|(
name|apr_thread_pool_t
operator|*
name|me
argument_list|)
expr_stmt|;
comment|/**  * Access function for the threshold of tasks in queue to trigger a new thread.  * @param me The thread pool  * @param cnt The new threshold  * @return The original threshold  */
name|APU_DECLARE
argument_list|(
argument|apr_size_t
argument_list|)
name|apr_thread_pool_threshold_set
argument_list|(
argument|apr_thread_pool_t *me
argument_list|,
argument|apr_size_t val
argument_list|)
empty_stmt|;
comment|/**  * Access function for the threshold of tasks in queue to trigger a new thread.  * @param me The thread pool  * @return The current threshold  */
name|APU_DECLARE
argument_list|(
argument|apr_size_t
argument_list|)
name|apr_thread_pool_threshold_get
argument_list|(
name|apr_thread_pool_t
operator|*
name|me
argument_list|)
expr_stmt|;
comment|/**  * Get owner of the task currently been executed by the thread.  * @param thd The thread is executing a task  * @param owner Pointer to receive owner of the task.  * @return APR_SUCCESS if the owner is retrieved successfully  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_thread_pool_task_owner_get
argument_list|(
name|apr_thread_t
operator|*
name|thd
argument_list|,
name|void
operator|*
operator|*
name|owner
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
comment|/* APR_HAS_THREADS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !APR_THREAD_POOL_H */
end_comment

end_unit

