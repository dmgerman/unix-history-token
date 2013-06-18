begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Licensed to the Apache Software Foundation (ASF) under one or more  * contributor license agreements.  See the NOTICE file distributed with  * this work for additional information regarding copyright ownership.  * The ASF licenses this file to You under the Apache License, Version 2.0  * (the "License"); you may not use this file except in compliance with  * the License.  You may obtain a copy of the License at  *  *     http://www.apache.org/licenses/LICENSE-2.0  *  * Unless required by applicable law or agreed to in writing, software  * distributed under the License is distributed on an "AS IS" BASIS,  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  * See the License for the specific language governing permissions and  * limitations under the License.  */
end_comment

begin_include
include|#
directive|include
file|"apr_arch_atomic.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|USE_ATOMICS_GENERIC
end_ifdef

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_if
if|#
directive|if
name|APR_HAS_THREADS
end_if

begin_define
define|#
directive|define
name|DECLARE_MUTEX_LOCKED
parameter_list|(
name|name
parameter_list|,
name|mem
parameter_list|)
define|\
value|apr_thread_mutex_t *name = mutex_hash(mem)
end_define

begin_define
define|#
directive|define
name|MUTEX_UNLOCK
parameter_list|(
name|name
parameter_list|)
define|\
value|do {                                                    \             if (apr_thread_mutex_unlock(name) != APR_SUCCESS)   \                 abort();                                        \         } while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DECLARE_MUTEX_LOCKED
parameter_list|(
name|name
parameter_list|,
name|mem
parameter_list|)
end_define

begin_define
define|#
directive|define
name|MUTEX_UNLOCK
parameter_list|(
name|name
parameter_list|)
end_define

begin_warning
warning|#
directive|warning
warning|Be warned: using stubs for all atomic operations
end_warning

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|APR_HAS_THREADS
end_if

begin_decl_stmt
specifier|static
name|apr_thread_mutex_t
modifier|*
modifier|*
name|hash_mutex
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|NUM_ATOMIC_HASH
value|7
end_define

begin_comment
comment|/* shift by 2 to get rid of alignment issues */
end_comment

begin_define
define|#
directive|define
name|ATOMIC_HASH
parameter_list|(
name|x
parameter_list|)
value|(unsigned int)(((unsigned long)(x)>>2)%(unsigned int)NUM_ATOMIC_HASH)
end_define

begin_function
specifier|static
name|apr_status_t
name|atomic_cleanup
parameter_list|(
name|void
modifier|*
name|data
parameter_list|)
block|{
if|if
condition|(
name|hash_mutex
operator|==
name|data
condition|)
name|hash_mutex
operator|=
name|NULL
expr_stmt|;
return|return
name|APR_SUCCESS
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
name|apr_atomic_init
argument_list|(
argument|apr_pool_t *p
argument_list|)
end_macro

begin_block
block|{
name|int
name|i
decl_stmt|;
name|apr_status_t
name|rv
decl_stmt|;
if|if
condition|(
name|hash_mutex
operator|!=
name|NULL
condition|)
return|return
name|APR_SUCCESS
return|;
name|hash_mutex
operator|=
name|apr_palloc
argument_list|(
name|p
argument_list|,
sizeof|sizeof
argument_list|(
name|apr_thread_mutex_t
operator|*
argument_list|)
operator|*
name|NUM_ATOMIC_HASH
argument_list|)
expr_stmt|;
name|apr_pool_cleanup_register
argument_list|(
name|p
argument_list|,
name|hash_mutex
argument_list|,
name|atomic_cleanup
argument_list|,
name|apr_pool_cleanup_null
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|NUM_ATOMIC_HASH
condition|;
name|i
operator|++
control|)
block|{
name|rv
operator|=
name|apr_thread_mutex_create
argument_list|(
operator|&
operator|(
name|hash_mutex
index|[
name|i
index|]
operator|)
argument_list|,
name|APR_THREAD_MUTEX_DEFAULT
argument_list|,
name|p
argument_list|)
expr_stmt|;
if|if
condition|(
name|rv
operator|!=
name|APR_SUCCESS
condition|)
block|{
return|return
name|rv
return|;
block|}
block|}
return|return
name|APR_SUCCESS
return|;
block|}
end_block

begin_function
specifier|static
name|APR_INLINE
name|apr_thread_mutex_t
modifier|*
name|mutex_hash
parameter_list|(
specifier|volatile
name|apr_uint32_t
modifier|*
name|mem
parameter_list|)
block|{
name|apr_thread_mutex_t
modifier|*
name|mutex
init|=
name|hash_mutex
index|[
name|ATOMIC_HASH
argument_list|(
name|mem
argument_list|)
index|]
decl_stmt|;
if|if
condition|(
name|apr_thread_mutex_lock
argument_list|(
name|mutex
argument_list|)
operator|!=
name|APR_SUCCESS
condition|)
block|{
name|abort
argument_list|()
expr_stmt|;
block|}
return|return
name|mutex
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_macro
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
end_macro

begin_macro
name|apr_atomic_init
argument_list|(
argument|apr_pool_t *p
argument_list|)
end_macro

begin_block
block|{
return|return
name|APR_SUCCESS
return|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* APR_HAS_THREADS */
end_comment

begin_macro
name|APR_DECLARE
argument_list|(
argument|apr_uint32_t
argument_list|)
end_macro

begin_macro
name|apr_atomic_read32
argument_list|(
argument|volatile apr_uint32_t *mem
argument_list|)
end_macro

begin_block
block|{
return|return
operator|*
name|mem
return|;
block|}
end_block

begin_macro
name|APR_DECLARE
argument_list|(
argument|void
argument_list|)
end_macro

begin_macro
name|apr_atomic_set32
argument_list|(
argument|volatile apr_uint32_t *mem
argument_list|,
argument|apr_uint32_t val
argument_list|)
end_macro

begin_block
block|{
name|DECLARE_MUTEX_LOCKED
argument_list|(
name|mutex
argument_list|,
name|mem
argument_list|)
expr_stmt|;
operator|*
name|mem
operator|=
name|val
expr_stmt|;
name|MUTEX_UNLOCK
argument_list|(
name|mutex
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|APR_DECLARE
argument_list|(
argument|apr_uint32_t
argument_list|)
end_macro

begin_macro
name|apr_atomic_add32
argument_list|(
argument|volatile apr_uint32_t *mem
argument_list|,
argument|apr_uint32_t val
argument_list|)
end_macro

begin_block
block|{
name|apr_uint32_t
name|old_value
decl_stmt|;
name|DECLARE_MUTEX_LOCKED
argument_list|(
name|mutex
argument_list|,
name|mem
argument_list|)
expr_stmt|;
name|old_value
operator|=
operator|*
name|mem
expr_stmt|;
operator|*
name|mem
operator|+=
name|val
expr_stmt|;
name|MUTEX_UNLOCK
argument_list|(
name|mutex
argument_list|)
expr_stmt|;
return|return
name|old_value
return|;
block|}
end_block

begin_macro
name|APR_DECLARE
argument_list|(
argument|void
argument_list|)
end_macro

begin_macro
name|apr_atomic_sub32
argument_list|(
argument|volatile apr_uint32_t *mem
argument_list|,
argument|apr_uint32_t val
argument_list|)
end_macro

begin_block
block|{
name|DECLARE_MUTEX_LOCKED
argument_list|(
name|mutex
argument_list|,
name|mem
argument_list|)
expr_stmt|;
operator|*
name|mem
operator|-=
name|val
expr_stmt|;
name|MUTEX_UNLOCK
argument_list|(
name|mutex
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|APR_DECLARE
argument_list|(
argument|apr_uint32_t
argument_list|)
end_macro

begin_macro
name|apr_atomic_inc32
argument_list|(
argument|volatile apr_uint32_t *mem
argument_list|)
end_macro

begin_block
block|{
return|return
name|apr_atomic_add32
argument_list|(
name|mem
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_block

begin_macro
name|APR_DECLARE
argument_list|(
argument|int
argument_list|)
end_macro

begin_macro
name|apr_atomic_dec32
argument_list|(
argument|volatile apr_uint32_t *mem
argument_list|)
end_macro

begin_block
block|{
name|apr_uint32_t
name|new
decl_stmt|;
name|DECLARE_MUTEX_LOCKED
argument_list|(
name|mutex
argument_list|,
name|mem
argument_list|)
expr_stmt|;
operator|(
operator|*
name|mem
operator|)
operator|--
expr_stmt|;
name|new
operator|=
operator|*
name|mem
expr_stmt|;
name|MUTEX_UNLOCK
argument_list|(
name|mutex
argument_list|)
expr_stmt|;
return|return
name|new
return|;
block|}
end_block

begin_macro
name|APR_DECLARE
argument_list|(
argument|apr_uint32_t
argument_list|)
end_macro

begin_macro
name|apr_atomic_cas32
argument_list|(
argument|volatile apr_uint32_t *mem
argument_list|,
argument|apr_uint32_t with
argument_list|,
argument|apr_uint32_t cmp
argument_list|)
end_macro

begin_block
block|{
name|apr_uint32_t
name|prev
decl_stmt|;
name|DECLARE_MUTEX_LOCKED
argument_list|(
name|mutex
argument_list|,
name|mem
argument_list|)
expr_stmt|;
name|prev
operator|=
operator|*
name|mem
expr_stmt|;
if|if
condition|(
name|prev
operator|==
name|cmp
condition|)
block|{
operator|*
name|mem
operator|=
name|with
expr_stmt|;
block|}
name|MUTEX_UNLOCK
argument_list|(
name|mutex
argument_list|)
expr_stmt|;
return|return
name|prev
return|;
block|}
end_block

begin_macro
name|APR_DECLARE
argument_list|(
argument|apr_uint32_t
argument_list|)
end_macro

begin_macro
name|apr_atomic_xchg32
argument_list|(
argument|volatile apr_uint32_t *mem
argument_list|,
argument|apr_uint32_t val
argument_list|)
end_macro

begin_block
block|{
name|apr_uint32_t
name|prev
decl_stmt|;
name|DECLARE_MUTEX_LOCKED
argument_list|(
name|mutex
argument_list|,
name|mem
argument_list|)
expr_stmt|;
name|prev
operator|=
operator|*
name|mem
expr_stmt|;
operator|*
name|mem
operator|=
name|val
expr_stmt|;
name|MUTEX_UNLOCK
argument_list|(
name|mutex
argument_list|)
expr_stmt|;
return|return
name|prev
return|;
block|}
end_block

begin_macro
name|APR_DECLARE
argument_list|(
argument|void*
argument_list|)
end_macro

begin_macro
name|apr_atomic_casptr
argument_list|(
argument|volatile void **mem
argument_list|,
argument|void *with
argument_list|,
argument|const void *cmp
argument_list|)
end_macro

begin_block
block|{
name|void
modifier|*
name|prev
decl_stmt|;
name|DECLARE_MUTEX_LOCKED
argument_list|(
name|mutex
argument_list|,
operator|*
name|mem
argument_list|)
expr_stmt|;
name|prev
operator|=
operator|*
operator|(
name|void
operator|*
operator|*
operator|)
name|mem
expr_stmt|;
if|if
condition|(
name|prev
operator|==
name|cmp
condition|)
block|{
operator|*
name|mem
operator|=
name|with
expr_stmt|;
block|}
name|MUTEX_UNLOCK
argument_list|(
name|mutex
argument_list|)
expr_stmt|;
return|return
name|prev
return|;
block|}
end_block

begin_macro
name|APR_DECLARE
argument_list|(
argument|void*
argument_list|)
end_macro

begin_macro
name|apr_atomic_xchgptr
argument_list|(
argument|volatile void **mem
argument_list|,
argument|void *with
argument_list|)
end_macro

begin_block
block|{
name|void
modifier|*
name|prev
decl_stmt|;
name|DECLARE_MUTEX_LOCKED
argument_list|(
name|mutex
argument_list|,
operator|*
name|mem
argument_list|)
expr_stmt|;
name|prev
operator|=
operator|*
operator|(
name|void
operator|*
operator|*
operator|)
name|mem
expr_stmt|;
operator|*
name|mem
operator|=
name|with
expr_stmt|;
name|MUTEX_UNLOCK
argument_list|(
name|mutex
argument_list|)
expr_stmt|;
return|return
name|prev
return|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USE_ATOMICS_GENERIC */
end_comment

end_unit

