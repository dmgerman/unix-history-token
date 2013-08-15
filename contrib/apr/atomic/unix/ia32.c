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
name|USE_ATOMICS_IA32
end_ifdef

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
asm|asm
specifier|volatile
asm|("lock; xaddl %0,%1"                   : "=r" (val), "=m" (*mem)                   : "0" (val), "m" (*mem)                   : "memory", "cc");
return|return
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
asm|asm
specifier|volatile
asm|("lock; subl %1, %0"                   :
comment|/* no output */
asm|: "m" (*(mem)), "r" (val)                   : "memory", "cc");
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
name|unsigned
name|char
name|prev
decl_stmt|;
asm|asm
specifier|volatile
asm|("lock; decl %0; setnz %1"                   : "=m" (*mem), "=qm" (prev)                   : "m" (*mem)                   : "memory");
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
asm|asm
specifier|volatile
asm|("lock; cmpxchgl %1, %2"                   : "=a" (prev)                   : "r" (with), "m" (*(mem)), "0"(cmp)                   : "memory", "cc");
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
init|=
name|val
decl_stmt|;
asm|asm
specifier|volatile
asm|("xchgl %0, %1"                   : "=r" (prev), "+m" (*mem)                   : "0" (prev));
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
if|#
directive|if
name|APR_SIZEOF_VOIDP
operator|==
literal|4
asm|asm
specifier|volatile
asm|("lock; cmpxchgl %2, %1"                   : "=a" (prev), "=m" (*mem)                   : "r" (with), "m" (*mem), "0" (cmp));
elif|#
directive|elif
name|APR_SIZEOF_VOIDP
operator|==
literal|8
asm|asm
specifier|volatile
asm|("lock; cmpxchgq %q2, %1"                   : "=a" (prev), "=m" (*mem)                   : "r" ((unsigned long)with), "m" (*mem),                     "0" ((unsigned long)cmp));
else|#
directive|else
error|#
directive|error
error|APR_SIZEOF_VOIDP value not supported
endif|#
directive|endif
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
if|#
directive|if
name|APR_SIZEOF_VOIDP
operator|==
literal|4
asm|asm
specifier|volatile
asm|("xchgl %2, %1"                   : "=a" (prev), "+m" (*mem)                   : "0" (with));
elif|#
directive|elif
name|APR_SIZEOF_VOIDP
operator|==
literal|8
asm|asm
specifier|volatile
asm|("xchgq %q2, %1"                   : "=a" (prev), "+m" (*mem)                   : "0" (with));
else|#
directive|else
error|#
directive|error
error|APR_SIZEOF_VOIDP value not supported
endif|#
directive|endif
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
comment|/* USE_ATOMICS_IA32 */
end_comment

end_unit

