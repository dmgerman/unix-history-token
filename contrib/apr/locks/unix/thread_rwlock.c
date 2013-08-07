begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Licensed to the Apache Software Foundation (ASF) under one or more  * contributor license agreements.  See the NOTICE file distributed with  * this work for additional information regarding copyright ownership.  * The ASF licenses this file to You under the Apache License, Version 2.0  * (the "License"); you may not use this file except in compliance with  * the License.  You may obtain a copy of the License at  *  *     http://www.apache.org/licenses/LICENSE-2.0  *  * Unless required by applicable law or agreed to in writing, software  * distributed under the License is distributed on an "AS IS" BASIS,  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  * See the License for the specific language governing permissions and  * limitations under the License.  */
end_comment

begin_include
include|#
directive|include
file|"apr_arch_thread_rwlock.h"
end_include

begin_include
include|#
directive|include
file|"apr_private.h"
end_include

begin_if
if|#
directive|if
name|APR_HAS_THREADS
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_PTHREAD_RWLOCKS
end_ifdef

begin_comment
comment|/* The rwlock must be initialized but not locked by any thread when  * cleanup is called. */
end_comment

begin_function
specifier|static
name|apr_status_t
name|thread_rwlock_cleanup
parameter_list|(
name|void
modifier|*
name|data
parameter_list|)
block|{
name|apr_thread_rwlock_t
modifier|*
name|rwlock
init|=
operator|(
name|apr_thread_rwlock_t
operator|*
operator|)
name|data
decl_stmt|;
name|apr_status_t
name|stat
decl_stmt|;
name|stat
operator|=
name|pthread_rwlock_destroy
argument_list|(
operator|&
name|rwlock
operator|->
name|rwlock
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|HAVE_ZOS_PTHREADS
if|if
condition|(
name|stat
condition|)
block|{
name|stat
operator|=
name|errno
expr_stmt|;
block|}
endif|#
directive|endif
return|return
name|stat
return|;
block|}
end_function

begin_macro
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
end_macro

begin_macro
name|apr_thread_rwlock_create
argument_list|(
argument|apr_thread_rwlock_t **rwlock
argument_list|,
argument|apr_pool_t *pool
argument_list|)
end_macro

begin_block
block|{
name|apr_thread_rwlock_t
modifier|*
name|new_rwlock
decl_stmt|;
name|apr_status_t
name|stat
decl_stmt|;
name|new_rwlock
operator|=
name|apr_palloc
argument_list|(
name|pool
argument_list|,
sizeof|sizeof
argument_list|(
name|apr_thread_rwlock_t
argument_list|)
argument_list|)
expr_stmt|;
name|new_rwlock
operator|->
name|pool
operator|=
name|pool
expr_stmt|;
if|if
condition|(
operator|(
name|stat
operator|=
name|pthread_rwlock_init
argument_list|(
operator|&
name|new_rwlock
operator|->
name|rwlock
argument_list|,
name|NULL
argument_list|)
operator|)
condition|)
block|{
ifdef|#
directive|ifdef
name|HAVE_ZOS_PTHREADS
name|stat
operator|=
name|errno
expr_stmt|;
endif|#
directive|endif
return|return
name|stat
return|;
block|}
name|apr_pool_cleanup_register
argument_list|(
name|new_rwlock
operator|->
name|pool
argument_list|,
operator|(
name|void
operator|*
operator|)
name|new_rwlock
argument_list|,
name|thread_rwlock_cleanup
argument_list|,
name|apr_pool_cleanup_null
argument_list|)
expr_stmt|;
operator|*
name|rwlock
operator|=
name|new_rwlock
expr_stmt|;
return|return
name|APR_SUCCESS
return|;
block|}
end_block

begin_macro
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
end_macro

begin_macro
name|apr_thread_rwlock_rdlock
argument_list|(
argument|apr_thread_rwlock_t *rwlock
argument_list|)
end_macro

begin_block
block|{
name|apr_status_t
name|stat
decl_stmt|;
name|stat
operator|=
name|pthread_rwlock_rdlock
argument_list|(
operator|&
name|rwlock
operator|->
name|rwlock
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|HAVE_ZOS_PTHREADS
if|if
condition|(
name|stat
condition|)
block|{
name|stat
operator|=
name|errno
expr_stmt|;
block|}
endif|#
directive|endif
return|return
name|stat
return|;
block|}
end_block

begin_macro
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
end_macro

begin_macro
name|apr_thread_rwlock_tryrdlock
argument_list|(
argument|apr_thread_rwlock_t *rwlock
argument_list|)
end_macro

begin_block
block|{
name|apr_status_t
name|stat
decl_stmt|;
name|stat
operator|=
name|pthread_rwlock_tryrdlock
argument_list|(
operator|&
name|rwlock
operator|->
name|rwlock
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|HAVE_ZOS_PTHREADS
if|if
condition|(
name|stat
condition|)
block|{
name|stat
operator|=
name|errno
expr_stmt|;
block|}
endif|#
directive|endif
comment|/* Normalize the return code. */
if|if
condition|(
name|stat
operator|==
name|EBUSY
condition|)
name|stat
operator|=
name|APR_EBUSY
expr_stmt|;
return|return
name|stat
return|;
block|}
end_block

begin_macro
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
end_macro

begin_macro
name|apr_thread_rwlock_wrlock
argument_list|(
argument|apr_thread_rwlock_t *rwlock
argument_list|)
end_macro

begin_block
block|{
name|apr_status_t
name|stat
decl_stmt|;
name|stat
operator|=
name|pthread_rwlock_wrlock
argument_list|(
operator|&
name|rwlock
operator|->
name|rwlock
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|HAVE_ZOS_PTHREADS
if|if
condition|(
name|stat
condition|)
block|{
name|stat
operator|=
name|errno
expr_stmt|;
block|}
endif|#
directive|endif
return|return
name|stat
return|;
block|}
end_block

begin_macro
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
end_macro

begin_macro
name|apr_thread_rwlock_trywrlock
argument_list|(
argument|apr_thread_rwlock_t *rwlock
argument_list|)
end_macro

begin_block
block|{
name|apr_status_t
name|stat
decl_stmt|;
name|stat
operator|=
name|pthread_rwlock_trywrlock
argument_list|(
operator|&
name|rwlock
operator|->
name|rwlock
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|HAVE_ZOS_PTHREADS
if|if
condition|(
name|stat
condition|)
block|{
name|stat
operator|=
name|errno
expr_stmt|;
block|}
endif|#
directive|endif
comment|/* Normalize the return code. */
if|if
condition|(
name|stat
operator|==
name|EBUSY
condition|)
name|stat
operator|=
name|APR_EBUSY
expr_stmt|;
return|return
name|stat
return|;
block|}
end_block

begin_macro
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
end_macro

begin_macro
name|apr_thread_rwlock_unlock
argument_list|(
argument|apr_thread_rwlock_t *rwlock
argument_list|)
end_macro

begin_block
block|{
name|apr_status_t
name|stat
decl_stmt|;
name|stat
operator|=
name|pthread_rwlock_unlock
argument_list|(
operator|&
name|rwlock
operator|->
name|rwlock
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|HAVE_ZOS_PTHREADS
if|if
condition|(
name|stat
condition|)
block|{
name|stat
operator|=
name|errno
expr_stmt|;
block|}
endif|#
directive|endif
return|return
name|stat
return|;
block|}
end_block

begin_macro
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
end_macro

begin_macro
name|apr_thread_rwlock_destroy
argument_list|(
argument|apr_thread_rwlock_t *rwlock
argument_list|)
end_macro

begin_block
block|{
return|return
name|apr_pool_cleanup_run
argument_list|(
name|rwlock
operator|->
name|pool
argument_list|,
name|rwlock
argument_list|,
name|thread_rwlock_cleanup
argument_list|)
return|;
block|}
end_block

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* HAVE_PTHREAD_RWLOCKS */
end_comment

begin_macro
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
end_macro

begin_macro
name|apr_thread_rwlock_create
argument_list|(
argument|apr_thread_rwlock_t **rwlock
argument_list|,
argument|apr_pool_t *pool
argument_list|)
end_macro

begin_block
block|{
return|return
name|APR_ENOTIMPL
return|;
block|}
end_block

begin_macro
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
end_macro

begin_macro
name|apr_thread_rwlock_rdlock
argument_list|(
argument|apr_thread_rwlock_t *rwlock
argument_list|)
end_macro

begin_block
block|{
return|return
name|APR_ENOTIMPL
return|;
block|}
end_block

begin_macro
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
end_macro

begin_macro
name|apr_thread_rwlock_tryrdlock
argument_list|(
argument|apr_thread_rwlock_t *rwlock
argument_list|)
end_macro

begin_block
block|{
return|return
name|APR_ENOTIMPL
return|;
block|}
end_block

begin_macro
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
end_macro

begin_macro
name|apr_thread_rwlock_wrlock
argument_list|(
argument|apr_thread_rwlock_t *rwlock
argument_list|)
end_macro

begin_block
block|{
return|return
name|APR_ENOTIMPL
return|;
block|}
end_block

begin_macro
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
end_macro

begin_macro
name|apr_thread_rwlock_trywrlock
argument_list|(
argument|apr_thread_rwlock_t *rwlock
argument_list|)
end_macro

begin_block
block|{
return|return
name|APR_ENOTIMPL
return|;
block|}
end_block

begin_macro
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
end_macro

begin_macro
name|apr_thread_rwlock_unlock
argument_list|(
argument|apr_thread_rwlock_t *rwlock
argument_list|)
end_macro

begin_block
block|{
return|return
name|APR_ENOTIMPL
return|;
block|}
end_block

begin_macro
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
end_macro

begin_macro
name|apr_thread_rwlock_destroy
argument_list|(
argument|apr_thread_rwlock_t *rwlock
argument_list|)
end_macro

begin_block
block|{
return|return
name|APR_ENOTIMPL
return|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_PTHREAD_RWLOCKS */
end_comment

begin_macro
name|APR_POOL_IMPLEMENT_ACCESSOR
argument_list|(
argument|thread_rwlock
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* APR_HAS_THREADS */
end_comment

end_unit

