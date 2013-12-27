begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Licensed to the Apache Software Foundation (ASF) under one or more  * contributor license agreements.  See the NOTICE file distributed with  * this work for additional information regarding copyright ownership.  * The ASF licenses this file to You under the Apache License, Version 2.0  * (the "License"); you may not use this file except in compliance with  * the License.  You may obtain a copy of the License at  *  *     http://www.apache.org/licenses/LICENSE-2.0  *  * Unless required by applicable law or agreed to in writing, software  * distributed under the License is distributed on an "AS IS" BASIS,  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  * See the License for the specific language governing permissions and  * limitations under the License.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|THREAD_MUTEX_H
end_ifndef

begin_define
define|#
directive|define
name|THREAD_MUTEX_H
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
file|"apr_general.h"
end_include

begin_include
include|#
directive|include
file|"apr_thread_mutex.h"
end_include

begin_include
include|#
directive|include
file|"apr_portable.h"
end_include

begin_include
include|#
directive|include
file|"apr_atomic.h"
end_include

begin_if
if|#
directive|if
name|APR_HAVE_PTHREAD_H
end_if

begin_include
include|#
directive|include
file|<pthread.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|APR_HAS_THREADS
end_if

begin_struct
struct|struct
name|apr_thread_mutex_t
block|{
name|apr_pool_t
modifier|*
name|pool
decl_stmt|;
name|pthread_mutex_t
name|mutex
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* THREAD_MUTEX_H */
end_comment

end_unit

