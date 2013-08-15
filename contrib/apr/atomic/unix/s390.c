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
name|USE_ATOMICS_S390
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

begin_function
specifier|static
name|APR_INLINE
name|apr_uint32_t
name|atomic_add
parameter_list|(
specifier|volatile
name|apr_uint32_t
modifier|*
name|mem
parameter_list|,
name|apr_uint32_t
name|val
parameter_list|)
block|{
name|apr_uint32_t
name|prev
init|=
operator|*
name|mem
decl_stmt|,
name|temp
decl_stmt|;
asm|asm
specifier|volatile
asm|("loop_%=:\n"                   "    lr  %1,%0\n"                   "    alr %1,%3\n"                   "    cs  %0,%1,%2\n"                   "    jl  loop_%=\n"                   : "+d" (prev), "+d" (temp), "=Q" (*mem)                   : "d" (val), "m" (*mem)                   : "cc", "memory");
return|return
name|prev
return|;
block|}
end_function

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
name|atomic_add
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
name|atomic_add
argument_list|(
name|mem
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_block

begin_function
specifier|static
name|APR_INLINE
name|apr_uint32_t
name|atomic_sub
parameter_list|(
specifier|volatile
name|apr_uint32_t
modifier|*
name|mem
parameter_list|,
name|apr_uint32_t
name|val
parameter_list|)
block|{
name|apr_uint32_t
name|prev
init|=
operator|*
name|mem
decl_stmt|,
name|temp
decl_stmt|;
asm|asm
specifier|volatile
asm|("loop_%=:\n"                   "    lr  %1,%0\n"                   "    slr %1,%3\n"                   "    cs  %0,%1,%2\n"                   "    jl  loop_%=\n"                   : "+d" (prev), "+d" (temp), "=Q" (*mem)                   : "d" (val), "m" (*mem)                   : "cc", "memory");
return|return
name|temp
return|;
block|}
end_function

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
name|atomic_sub
argument_list|(
name|mem
argument_list|,
name|val
argument_list|)
expr_stmt|;
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
name|atomic_sub
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
asm|asm
specifier|volatile
asm|("    cs  %0,%2,%1\n"                   : "+d" (cmp), "=Q" (*mem)                   : "d" (with), "m" (*mem)                   : "cc", "memory");
return|return
name|cmp
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
operator|*
name|mem
decl_stmt|;
asm|asm
specifier|volatile
asm|("loop_%=:\n"                   "    cs  %0,%2,%1\n"                   "    jl  loop_%=\n"                   : "+d" (prev), "=Q" (*mem)                   : "d" (val), "m" (*mem)                   : "cc", "memory");
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
init|=
operator|(
name|void
operator|*
operator|)
name|cmp
decl_stmt|;
if|#
directive|if
name|APR_SIZEOF_VOIDP
operator|==
literal|4
asm|asm
specifier|volatile
asm|("    cs  %0,%2,%1\n"                   : "+d" (prev), "=Q" (*mem)                   : "d" (with), "m" (*mem)                   : "cc", "memory");
elif|#
directive|elif
name|APR_SIZEOF_VOIDP
operator|==
literal|8
asm|asm
specifier|volatile
asm|("    csg %0,%2,%1\n"                   : "+d" (prev), "=Q" (*mem)                   : "d" (with), "m" (*mem)                   : "cc", "memory");
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
init|=
operator|(
name|void
operator|*
operator|)
operator|*
name|mem
decl_stmt|;
if|#
directive|if
name|APR_SIZEOF_VOIDP
operator|==
literal|4
asm|asm
specifier|volatile
asm|("loop_%=:\n"                   "    cs  %0,%2,%1\n"                   "    jl  loop_%=\n"                   : "+d" (prev), "=Q" (*mem)                   : "d" (with), "m" (*mem)                   : "cc", "memory");
elif|#
directive|elif
name|APR_SIZEOF_VOIDP
operator|==
literal|8
asm|asm
specifier|volatile
asm|("loop_%=:\n"                   "    csg %0,%2,%1\n"                   "    jl  loop_%=\n"                   : "+d" (prev), "=Q" (*mem)                   : "d" (with), "m" (*mem)                   : "cc", "memory");
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
comment|/* USE_ATOMICS_S390 */
end_comment

end_unit

