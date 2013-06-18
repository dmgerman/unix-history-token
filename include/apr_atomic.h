begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Licensed to the Apache Software Foundation (ASF) under one or more  * contributor license agreements.  See the NOTICE file distributed with  * this work for additional information regarding copyright ownership.  * The ASF licenses this file to You under the Apache License, Version 2.0  * (the "License"); you may not use this file except in compliance with  * the License.  You may obtain a copy of the License at  *  *     http://www.apache.org/licenses/LICENSE-2.0  *  * Unless required by applicable law or agreed to in writing, software  * distributed under the License is distributed on an "AS IS" BASIS,  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  * See the License for the specific language governing permissions and  * limitations under the License.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|APR_ATOMIC_H
end_ifndef

begin_define
define|#
directive|define
name|APR_ATOMIC_H
end_define

begin_comment
comment|/**  * @file apr_atomic.h  * @brief APR Atomic Operations  */
end_comment

begin_include
include|#
directive|include
file|"apr.h"
end_include

begin_include
include|#
directive|include
file|"apr_pools.h"
end_include

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
comment|/**  * @defgroup apr_atomic Atomic Operations  * @ingroup APR   * @{  */
comment|/**  * this function is required on some platforms to initialize the  * atomic operation's internal structures  * @param p pool  * @return APR_SUCCESS on successful completion  * @remark Programs do NOT need to call this directly. APR will call this  *         automatically from apr_initialize.  * @internal  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_atomic_init
argument_list|(
name|apr_pool_t
operator|*
name|p
argument_list|)
expr_stmt|;
comment|/*  * Atomic operations on 32-bit values  * Note: Each of these functions internally implements a memory barrier  * on platforms that require it  */
comment|/**  * atomically read an apr_uint32_t from memory  * @param mem the pointer  */
name|APR_DECLARE
argument_list|(
argument|apr_uint32_t
argument_list|)
name|apr_atomic_read32
argument_list|(
specifier|volatile
name|apr_uint32_t
operator|*
name|mem
argument_list|)
expr_stmt|;
comment|/**  * atomically set an apr_uint32_t in memory  * @param mem pointer to the object  * @param val value that the object will assume  */
name|APR_DECLARE
argument_list|(
argument|void
argument_list|)
name|apr_atomic_set32
argument_list|(
argument|volatile apr_uint32_t *mem
argument_list|,
argument|apr_uint32_t val
argument_list|)
empty_stmt|;
comment|/**  * atomically add 'val' to an apr_uint32_t  * @param mem pointer to the object  * @param val amount to add  * @return old value pointed to by mem  */
name|APR_DECLARE
argument_list|(
argument|apr_uint32_t
argument_list|)
name|apr_atomic_add32
argument_list|(
argument|volatile apr_uint32_t *mem
argument_list|,
argument|apr_uint32_t val
argument_list|)
empty_stmt|;
comment|/**  * atomically subtract 'val' from an apr_uint32_t  * @param mem pointer to the object  * @param val amount to subtract  */
name|APR_DECLARE
argument_list|(
argument|void
argument_list|)
name|apr_atomic_sub32
argument_list|(
argument|volatile apr_uint32_t *mem
argument_list|,
argument|apr_uint32_t val
argument_list|)
empty_stmt|;
comment|/**  * atomically increment an apr_uint32_t by 1  * @param mem pointer to the object  * @return old value pointed to by mem  */
name|APR_DECLARE
argument_list|(
argument|apr_uint32_t
argument_list|)
name|apr_atomic_inc32
argument_list|(
specifier|volatile
name|apr_uint32_t
operator|*
name|mem
argument_list|)
expr_stmt|;
comment|/**  * atomically decrement an apr_uint32_t by 1  * @param mem pointer to the atomic value  * @return zero if the value becomes zero on decrement, otherwise non-zero  */
name|APR_DECLARE
argument_list|(
argument|int
argument_list|)
name|apr_atomic_dec32
argument_list|(
specifier|volatile
name|apr_uint32_t
operator|*
name|mem
argument_list|)
expr_stmt|;
comment|/**  * compare an apr_uint32_t's value with 'cmp'.  * If they are the same swap the value with 'with'  * @param mem pointer to the value  * @param with what to swap it with  * @param cmp the value to compare it to  * @return the old value of *mem  */
name|APR_DECLARE
argument_list|(
argument|apr_uint32_t
argument_list|)
name|apr_atomic_cas32
argument_list|(
argument|volatile apr_uint32_t *mem
argument_list|,
argument|apr_uint32_t with
argument_list|,
argument|apr_uint32_t cmp
argument_list|)
empty_stmt|;
comment|/**  * exchange an apr_uint32_t's value with 'val'.  * @param mem pointer to the value  * @param val what to swap it with  * @return the old value of *mem  */
name|APR_DECLARE
argument_list|(
argument|apr_uint32_t
argument_list|)
name|apr_atomic_xchg32
argument_list|(
argument|volatile apr_uint32_t *mem
argument_list|,
argument|apr_uint32_t val
argument_list|)
empty_stmt|;
comment|/**  * compare the pointer's value with cmp.  * If they are the same swap the value with 'with'  * @param mem pointer to the pointer  * @param with what to swap it with  * @param cmp the value to compare it to  * @return the old value of the pointer  */
name|APR_DECLARE
argument_list|(
argument|void*
argument_list|)
name|apr_atomic_casptr
argument_list|(
specifier|volatile
name|void
operator|*
operator|*
name|mem
argument_list|,
name|void
operator|*
name|with
argument_list|,
specifier|const
name|void
operator|*
name|cmp
argument_list|)
expr_stmt|;
comment|/**  * exchange a pair of pointer values  * @param mem pointer to the pointer  * @param with what to swap it with  * @return the old value of the pointer  */
name|APR_DECLARE
argument_list|(
argument|void*
argument_list|)
name|apr_atomic_xchgptr
argument_list|(
specifier|volatile
name|void
operator|*
operator|*
name|mem
argument_list|,
name|void
operator|*
name|with
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
comment|/* !APR_ATOMIC_H */
end_comment

end_unit

