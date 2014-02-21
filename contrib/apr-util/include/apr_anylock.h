begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Licensed to the Apache Software Foundation (ASF) under one or more  * contributor license agreements.  See the NOTICE file distributed with  * this work for additional information regarding copyright ownership.  * The ASF licenses this file to You under the Apache License, Version 2.0  * (the "License"); you may not use this file except in compliance with  * the License.  You may obtain a copy of the License at  *  *     http://www.apache.org/licenses/LICENSE-2.0  *  * Unless required by applicable law or agreed to in writing, software  * distributed under the License is distributed on an "AS IS" BASIS,  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  * See the License for the specific language governing permissions and  * limitations under the License.  */
end_comment

begin_comment
comment|/**  * @file apr_anylock.h  * @brief APR-Util transparent any lock flavor wrapper  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|APR_ANYLOCK_H
end_ifndef

begin_define
define|#
directive|define
name|APR_ANYLOCK_H
end_define

begin_include
include|#
directive|include
file|"apr_proc_mutex.h"
end_include

begin_include
include|#
directive|include
file|"apr_thread_mutex.h"
end_include

begin_include
include|#
directive|include
file|"apr_thread_rwlock.h"
end_include

begin_comment
comment|/** Structure that may contain any APR lock type */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|apr_anylock_t
block|{
comment|/** Indicates what type of lock is in lock */
enum|enum
name|tm_lock
block|{
name|apr_anylock_none
block|,
comment|/**< None */
name|apr_anylock_procmutex
block|,
comment|/**< Process-based */
name|apr_anylock_threadmutex
block|,
comment|/**< Thread-based */
name|apr_anylock_readlock
block|,
comment|/**< Read lock */
name|apr_anylock_writelock
comment|/**< Write lock */
block|}
name|type
enum|;
comment|/** Union of all possible APR locks */
union|union
name|apr_anylock_u_t
block|{
name|apr_proc_mutex_t
modifier|*
name|pm
decl_stmt|;
comment|/**< Process mutex */
if|#
directive|if
name|APR_HAS_THREADS
name|apr_thread_mutex_t
modifier|*
name|tm
decl_stmt|;
comment|/**< Thread mutex */
name|apr_thread_rwlock_t
modifier|*
name|rw
decl_stmt|;
comment|/**< Read-write lock */
endif|#
directive|endif
block|}
name|lock
union|;
block|}
name|apr_anylock_t
typedef|;
end_typedef

begin_if
if|#
directive|if
name|APR_HAS_THREADS
end_if

begin_comment
comment|/** Lock an apr_anylock_t structure */
end_comment

begin_define
define|#
directive|define
name|APR_ANYLOCK_LOCK
parameter_list|(
name|lck
parameter_list|)
define|\
value|(((lck)->type == apr_anylock_none)         \       ? APR_SUCCESS                              \       : (((lck)->type == apr_anylock_threadmutex)  \           ? apr_thread_mutex_lock((lck)->lock.tm)    \           : (((lck)->type == apr_anylock_procmutex)    \               ? apr_proc_mutex_lock((lck)->lock.pm)      \               : (((lck)->type == apr_anylock_readlock)     \                   ? apr_thread_rwlock_rdlock((lck)->lock.rw) \                   : (((lck)->type == apr_anylock_writelock)    \                       ? apr_thread_rwlock_wrlock((lck)->lock.rw) \                       : APR_EINVAL)))))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* APR_HAS_THREADS */
end_comment

begin_define
define|#
directive|define
name|APR_ANYLOCK_LOCK
parameter_list|(
name|lck
parameter_list|)
define|\
value|(((lck)->type == apr_anylock_none)         \       ? APR_SUCCESS                              \           : (((lck)->type == apr_anylock_procmutex)    \               ? apr_proc_mutex_lock((lck)->lock.pm)      \                       : APR_EINVAL))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* APR_HAS_THREADS */
end_comment

begin_if
if|#
directive|if
name|APR_HAS_THREADS
end_if

begin_comment
comment|/** Try to lock an apr_anylock_t structure */
end_comment

begin_define
define|#
directive|define
name|APR_ANYLOCK_TRYLOCK
parameter_list|(
name|lck
parameter_list|)
define|\
value|(((lck)->type == apr_anylock_none)            \       ? APR_SUCCESS                                 \       : (((lck)->type == apr_anylock_threadmutex)     \           ? apr_thread_mutex_trylock((lck)->lock.tm)    \           : (((lck)->type == apr_anylock_procmutex)       \               ? apr_proc_mutex_trylock((lck)->lock.pm)      \               : (((lck)->type == apr_anylock_readlock)        \                   ? apr_thread_rwlock_tryrdlock((lck)->lock.rw) \                   : (((lck)->type == apr_anylock_writelock)       \                       ? apr_thread_rwlock_trywrlock((lck)->lock.rw) \                           : APR_EINVAL)))))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* APR_HAS_THREADS */
end_comment

begin_define
define|#
directive|define
name|APR_ANYLOCK_TRYLOCK
parameter_list|(
name|lck
parameter_list|)
define|\
value|(((lck)->type == apr_anylock_none)            \       ? APR_SUCCESS                                 \           : (((lck)->type == apr_anylock_procmutex)       \               ? apr_proc_mutex_trylock((lck)->lock.pm)      \                           : APR_EINVAL))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* APR_HAS_THREADS */
end_comment

begin_if
if|#
directive|if
name|APR_HAS_THREADS
end_if

begin_comment
comment|/** Unlock an apr_anylock_t structure */
end_comment

begin_define
define|#
directive|define
name|APR_ANYLOCK_UNLOCK
parameter_list|(
name|lck
parameter_list|)
define|\
value|(((lck)->type == apr_anylock_none)         \       ? APR_SUCCESS                              \       : (((lck)->type == apr_anylock_threadmutex)  \           ? apr_thread_mutex_unlock((lck)->lock.tm)  \           : (((lck)->type == apr_anylock_procmutex)    \               ? apr_proc_mutex_unlock((lck)->lock.pm)    \               : ((((lck)->type == apr_anylock_readlock) || \                   ((lck)->type == apr_anylock_writelock))    \                   ? apr_thread_rwlock_unlock((lck)->lock.rw)   \                       : APR_EINVAL))))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* APR_HAS_THREADS */
end_comment

begin_define
define|#
directive|define
name|APR_ANYLOCK_UNLOCK
parameter_list|(
name|lck
parameter_list|)
define|\
value|(((lck)->type == apr_anylock_none)         \       ? APR_SUCCESS                              \           : (((lck)->type == apr_anylock_procmutex)    \               ? apr_proc_mutex_unlock((lck)->lock.pm)    \                       : APR_EINVAL))
end_define

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
comment|/* !APR_ANYLOCK_H */
end_comment

end_unit

