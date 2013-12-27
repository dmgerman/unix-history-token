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
name|USE_ATOMICS_PPC
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|PPC405_ERRATA
end_ifdef

begin_define
define|#
directive|define
name|PPC405_ERR77_SYNC
value|"    sync\n"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PPC405_ERR77_SYNC
end_define

begin_endif
endif|#
directive|endif
end_endif

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
name|apr_uint32_t
name|prev
decl_stmt|,
name|temp
decl_stmt|;
asm|asm
specifier|volatile
asm|("1:\n"
comment|/* lost reservation     */
asm|"    lwarx   %0,0,%3\n"
comment|/* load and reserve     */
asm|"    add     %1,%0,%4\n"
comment|/* add val and prev     */
asm|PPC405_ERR77_SYNC
comment|/* ppc405 Erratum 77    */
asm|"    stwcx.  %1,0,%3\n"
comment|/* store new value      */
asm|"    bne-    1b\n"
comment|/* loop if lost         */
asm|: "=&r" (prev), "=&r" (temp), "=m" (*mem)                   : "b" (mem), "r" (val)                   : "cc", "memory");
return|return
name|prev
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
name|apr_uint32_t
name|temp
decl_stmt|;
asm|asm
specifier|volatile
asm|("1:\n"
comment|/* lost reservation     */
asm|"    lwarx   %0,0,%2\n"
comment|/* load and reserve     */
asm|"    subf    %0,%3,%0\n"
comment|/* subtract val         */
asm|PPC405_ERR77_SYNC
comment|/* ppc405 Erratum 77    */
asm|"    stwcx.  %0,0,%2\n"
comment|/* store new value      */
asm|"    bne-    1b\n"
comment|/* loop if lost         */
asm|: "=&r" (temp), "=m" (*mem)                   : "b" (mem), "r" (val)                   : "cc", "memory");
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
name|apr_uint32_t
name|prev
decl_stmt|;
asm|asm
specifier|volatile
asm|("1:\n"
comment|/* lost reservation     */
asm|"    lwarx   %0,0,%2\n"
comment|/* load and reserve     */
asm|"    addi    %0,%0,1\n"
comment|/* add immediate        */
asm|PPC405_ERR77_SYNC
comment|/* ppc405 Erratum 77    */
asm|"    stwcx.  %0,0,%2\n"
comment|/* store new value      */
asm|"    bne-    1b\n"
comment|/* loop if lost         */
asm|"    subi    %0,%0,1\n"
comment|/* return old value     */
asm|: "=&b" (prev), "=m" (*mem)                   : "b" (mem), "m" (*mem)                   : "cc", "memory");
return|return
name|prev
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
name|prev
decl_stmt|;
asm|asm
specifier|volatile
asm|("1:\n"
comment|/* lost reservation     */
asm|"    lwarx   %0,0,%2\n"
comment|/* load and reserve     */
asm|"    subi    %0,%0,1\n"
comment|/* subtract immediate   */
asm|PPC405_ERR77_SYNC
comment|/* ppc405 Erratum 77    */
asm|"    stwcx.  %0,0,%2\n"
comment|/* store new value      */
asm|"    bne-    1b\n"
comment|/* loop if lost         */
asm|: "=&b" (prev), "=m" (*mem)                   : "b" (mem), "m" (*mem)                   : "cc", "memory");
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
asm|("1:\n"
comment|/* lost reservation     */
asm|"    lwarx   %0,0,%1\n"
comment|/* load and reserve     */
asm|"    cmpw    %0,%3\n"
comment|/* compare operands     */
asm|"    bne-    exit_%=\n"
comment|/* skip if not equal    */
asm|PPC405_ERR77_SYNC
comment|/* ppc405 Erratum 77    */
asm|"    stwcx.  %2,0,%1\n"
comment|/* store new value      */
asm|"    bne-    1b\n"
comment|/* loop if lost         */
asm|"exit_%=:\n"
comment|/* not equal            */
asm|: "=&r" (prev)                   : "b" (mem), "r" (with), "r" (cmp)                   : "cc", "memory");
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
asm|asm
specifier|volatile
asm|("1:\n"
comment|/* lost reservation     */
asm|"    lwarx   %0,0,%1\n"
comment|/* load and reserve     */
asm|PPC405_ERR77_SYNC
comment|/* ppc405 Erratum 77    */
asm|"    stwcx.  %2,0,%1\n"
comment|/* store new value      */
asm|"    bne-    1b"
comment|/* loop if lost         */
asm|: "=&r" (prev)                   : "b" (mem), "r" (val)                   : "cc", "memory");
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
asm|("1:\n"
comment|/* lost reservation     */
asm|"    lwarx   %0,0,%1\n"
comment|/* load and reserve     */
asm|"    cmpw    %0,%3\n"
comment|/* compare operands     */
asm|"    bne-    2f\n"
comment|/* skip if not equal    */
asm|PPC405_ERR77_SYNC
comment|/* ppc405 Erratum 77    */
asm|"    stwcx.  %2,0,%1\n"
comment|/* store new value      */
asm|"    bne-    1b\n"
comment|/* loop if lost         */
asm|"2:\n"
comment|/* not equal            */
asm|: "=&r" (prev)                   : "b" (mem), "r" (with), "r" (cmp)                   : "cc", "memory");
elif|#
directive|elif
name|APR_SIZEOF_VOIDP
operator|==
literal|8
asm|asm
specifier|volatile
asm|("1:\n"
comment|/* lost reservation     */
asm|"    ldarx   %0,0,%1\n"
comment|/* load and reserve     */
asm|"    cmpd    %0,%3\n"
comment|/* compare operands     */
asm|"    bne-    2f\n"
comment|/* skip if not equal    */
asm|PPC405_ERR77_SYNC
comment|/* ppc405 Erratum 77    */
asm|"    stdcx.  %2,0,%1\n"
comment|/* store new value      */
asm|"    bne-    1b\n"
comment|/* loop if lost         */
asm|"2:\n"
comment|/* not equal            */
asm|: "=&r" (prev)                   : "b" (mem), "r" (with), "r" (cmp)                   : "cc", "memory");
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
asm|("1:\n"
comment|/* lost reservation     */
asm|"    lwarx   %0,0,%1\n"
comment|/* load and reserve     */
asm|PPC405_ERR77_SYNC
comment|/* ppc405 Erratum 77    */
asm|"    stwcx.  %2,0,%1\n"
comment|/* store new value      */
asm|"    bne-    1b\n"
comment|/* loop if lost         */
asm|"    isync\n"
comment|/* memory barrier       */
asm|: "=&r" (prev)                   : "b" (mem), "r" (with)                   : "cc", "memory");
elif|#
directive|elif
name|APR_SIZEOF_VOIDP
operator|==
literal|8
asm|asm
specifier|volatile
asm|("1:\n"
comment|/* lost reservation     */
asm|"    ldarx   %0,0,%1\n"
comment|/* load and reserve     */
asm|PPC405_ERR77_SYNC
comment|/* ppc405 Erratum 77    */
asm|"    stdcx.  %2,0,%1\n"
comment|/* store new value      */
asm|"    bne-    1b\n"
comment|/* loop if lost         */
asm|"    isync\n"
comment|/* memory barrier       */
asm|: "=&r" (prev)                   : "b" (mem), "r" (with)                   : "cc", "memory");
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
comment|/* USE_ATOMICS_PPC */
end_comment

end_unit

