begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Licensed to the Apache Software Foundation (ASF) under one or more  * contributor license agreements.  See the NOTICE file distributed with  * this work for additional information regarding copyright ownership.  * The ASF licenses this file to You under the Apache License, Version 2.0  * (the "License"); you may not use this file except in compliance with  * the License.  You may obtain a copy of the License at  *  *     http://www.apache.org/licenses/LICENSE-2.0  *  * Unless required by applicable law or agreed to in writing, software  * distributed under the License is distributed on an "AS IS" BASIS,  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  * See the License for the specific language governing permissions and  * limitations under the License.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SHM_H
end_ifndef

begin_define
define|#
directive|define
name|SHM_H
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
file|"apr_lib.h"
end_include

begin_include
include|#
directive|include
file|"apr_shm.h"
end_include

begin_include
include|#
directive|include
file|"apr_pools.h"
end_include

begin_include
include|#
directive|include
file|"apr_file_io.h"
end_include

begin_include
include|#
directive|include
file|"apr_network_io.h"
end_include

begin_include
include|#
directive|include
file|"apr_portable.h"
end_include

begin_if
if|#
directive|if
name|APR_HAVE_UNISTD_H
end_if

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_MMAN_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/mman.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_IPC_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/ipc.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_MUTEX_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_SHM_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/shm.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|SHM_R
argument_list|)
end_if

begin_define
define|#
directive|define
name|SHM_R
value|0400
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|SHM_W
argument_list|)
end_if

begin_define
define|#
directive|define
name|SHM_W
value|0200
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_FILE_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Not all systems seem to have MAP_FAILED defined, but it should always  * just be (void *)-1. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MAP_FAILED
end_ifndef

begin_define
define|#
directive|define
name|MAP_FAILED
value|((void *)-1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|apr_shm_t
block|{
name|apr_pool_t
modifier|*
name|pool
decl_stmt|;
name|void
modifier|*
name|base
decl_stmt|;
comment|/* base real address */
name|void
modifier|*
name|usable
decl_stmt|;
comment|/* base usable address */
name|apr_size_t
name|reqsize
decl_stmt|;
comment|/* requested segment size */
name|apr_size_t
name|realsize
decl_stmt|;
comment|/* actual segment size */
specifier|const
name|char
modifier|*
name|filename
decl_stmt|;
comment|/* NULL if anonymous */
if|#
directive|if
name|APR_USE_SHMEM_SHMGET
operator|||
name|APR_USE_SHMEM_SHMGET_ANON
name|int
name|shmid
decl_stmt|;
comment|/* shmem ID returned from shmget() */
endif|#
directive|endif
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SHM_H */
end_comment

end_unit

