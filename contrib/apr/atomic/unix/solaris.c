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
name|USE_ATOMICS_SOLARIS
end_ifdef

begin_include
include|#
directive|include
file|<atomic.h>
end_include

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
operator|*
name|mem
operator|=
name|val
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
return|return
name|atomic_add_32_nv
argument_list|(
name|mem
argument_list|,
name|val
argument_list|)
operator|-
name|val
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
name|atomic_add_32
argument_list|(
name|mem
argument_list|,
operator|-
name|val
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
name|atomic_inc_32_nv
argument_list|(
name|mem
argument_list|)
operator|-
literal|1
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
return|return
name|atomic_dec_32_nv
argument_list|(
name|mem
argument_list|)
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
return|return
name|atomic_cas_32
argument_list|(
name|mem
argument_list|,
name|cmp
argument_list|,
name|with
argument_list|)
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
return|return
name|atomic_swap_32
argument_list|(
name|mem
argument_list|,
name|val
argument_list|)
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
return|return
name|atomic_cas_ptr
argument_list|(
name|mem
argument_list|,
operator|(
name|void
operator|*
operator|)
name|cmp
argument_list|,
name|with
argument_list|)
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
return|return
name|atomic_swap_ptr
argument_list|(
name|mem
argument_list|,
name|with
argument_list|)
return|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USE_ATOMICS_SOLARIS */
end_comment

end_unit

