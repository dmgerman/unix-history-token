begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Licensed to the Apache Software Foundation (ASF) under one or more  * contributor license agreements.  See the NOTICE file distributed with  * this work for additional information regarding copyright ownership.  * The ASF licenses this file to You under the Apache License, Version 2.0  * (the "License"); you may not use this file except in compliance with  * the License.  You may obtain a copy of the License at  *  *     http://www.apache.org/licenses/LICENSE-2.0  *  * Unless required by applicable law or agreed to in writing, software  * distributed under the License is distributed on an "AS IS" BASIS,  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  * See the License for the specific language governing permissions and  * limitations under the License.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ATOMIC_H
end_ifndef

begin_define
define|#
directive|define
name|ATOMIC_H
end_define

begin_include
include|#
directive|include
file|"apr.h"
end_include

begin_include
include|#
directive|include
file|"apr_private.h"
end_include

begin_include
include|#
directive|include
file|"apr_atomic.h"
end_include

begin_include
include|#
directive|include
file|"apr_thread_mutex.h"
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|USE_ATOMICS_GENERIC
argument_list|)
end_if

begin_comment
comment|/* noop */
end_comment

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
name|defined
argument_list|(
name|__STRICT_ANSI__
argument_list|)
end_elif

begin_comment
comment|/* force use of generic atomics if building e.g. with -std=c89, which  * doesn't allow inline asm */
end_comment

begin_define
define|#
directive|define
name|USE_ATOMICS_GENERIC
end_define

begin_elif
elif|#
directive|elif
name|HAVE_ATOMIC_BUILTINS
end_elif

begin_define
define|#
directive|define
name|USE_ATOMICS_BUILTINS
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|SOLARIS2
argument_list|)
operator|&&
name|SOLARIS2
operator|>=
literal|10
end_elif

begin_define
define|#
directive|define
name|USE_ATOMICS_SOLARIS
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
operator|(
name|defined
argument_list|(
name|__i386__
argument_list|)
operator|||
name|defined
argument_list|(
name|__x86_64__
argument_list|)
operator|)
end_elif

begin_define
define|#
directive|define
name|USE_ATOMICS_IA32
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
operator|(
name|defined
argument_list|(
name|__PPC__
argument_list|)
operator|||
name|defined
argument_list|(
name|__ppc__
argument_list|)
operator|)
end_elif

begin_define
define|#
directive|define
name|USE_ATOMICS_PPC
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
operator|(
name|defined
argument_list|(
name|__s390__
argument_list|)
operator|||
name|defined
argument_list|(
name|__s390x__
argument_list|)
operator|)
end_elif

begin_define
define|#
directive|define
name|USE_ATOMICS_S390
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|USE_ATOMICS_GENERIC
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ATOMIC_H */
end_comment

end_unit

