begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Licensed to the Apache Software Foundation (ASF) under one or more  * contributor license agreements.  See the NOTICE file distributed with  * this work for additional information regarding copyright ownership.  * The ASF licenses this file to You under the Apache License, Version 2.0  * (the "License"); you may not use this file except in compliance with  * the License.  You may obtain a copy of the License at  *  *     http://www.apache.org/licenses/LICENSE-2.0  *  * Unless required by applicable law or agreed to in writing, software  * distributed under the License is distributed on an "AS IS" BASIS,  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  * See the License for the specific language governing permissions and  * limitations under the License.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PROC_MUTEX_H
end_ifndef

begin_define
define|#
directive|define
name|PROC_MUTEX_H
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
file|"apr_proc_mutex.h"
end_include

begin_include
include|#
directive|include
file|"apr_pools.h"
end_include

begin_include
include|#
directive|include
file|"apr_portable.h"
end_include

begin_include
include|#
directive|include
file|"apr_file_io.h"
end_include

begin_include
include|#
directive|include
file|"apr_arch_file_io.h"
end_include

begin_comment
comment|/* System headers required by Locks library */
end_comment

begin_if
if|#
directive|if
name|APR_HAVE_SYS_TYPES_H
end_if

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|APR_HAVE_STDIO_H
end_if

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|APR_HAVE_FCNTL_H
end_if

begin_include
include|#
directive|include
file|<fcntl.h>
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
name|HAVE_SYS_SEM_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/sem.h>
end_include

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

begin_if
if|#
directive|if
name|APR_HAVE_STDLIB_H
end_if

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

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

begin_if
if|#
directive|if
name|APR_HAVE_STRING_H
end_if

begin_include
include|#
directive|include
file|<string.h>
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
name|APR_HAVE_SEMAPHORE_H
end_if

begin_include
include|#
directive|include
file|<semaphore.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* End System Headers */
end_comment

begin_struct
struct|struct
name|apr_proc_mutex_unix_lock_methods_t
block|{
name|unsigned
name|int
name|flags
decl_stmt|;
name|apr_status_t
function_decl|(
modifier|*
name|create
function_decl|)
parameter_list|(
name|apr_proc_mutex_t
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
name|apr_status_t
function_decl|(
modifier|*
name|acquire
function_decl|)
parameter_list|(
name|apr_proc_mutex_t
modifier|*
parameter_list|)
function_decl|;
name|apr_status_t
function_decl|(
modifier|*
name|tryacquire
function_decl|)
parameter_list|(
name|apr_proc_mutex_t
modifier|*
parameter_list|)
function_decl|;
name|apr_status_t
function_decl|(
modifier|*
name|release
function_decl|)
parameter_list|(
name|apr_proc_mutex_t
modifier|*
parameter_list|)
function_decl|;
name|apr_status_t
function_decl|(
modifier|*
name|cleanup
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
name|apr_status_t
function_decl|(
modifier|*
name|child_init
function_decl|)
parameter_list|(
name|apr_proc_mutex_t
modifier|*
modifier|*
parameter_list|,
name|apr_pool_t
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|apr_proc_mutex_unix_lock_methods_t
name|apr_proc_mutex_unix_lock_methods_t
typedef|;
end_typedef

begin_comment
comment|/* bit values for flags field in apr_unix_lock_methods_t */
end_comment

begin_define
define|#
directive|define
name|APR_PROCESS_LOCK_MECH_IS_GLOBAL
value|1
end_define

begin_if
if|#
directive|if
operator|!
name|APR_HAVE_UNION_SEMUN
operator|&&
name|defined
argument_list|(
name|APR_HAS_SYSVSEM_SERIALIZE
argument_list|)
end_if

begin_union
union|union
name|semun
block|{
name|int
name|val
decl_stmt|;
name|struct
name|semid_ds
modifier|*
name|buf
decl_stmt|;
name|unsigned
name|short
modifier|*
name|array
decl_stmt|;
block|}
union|;
end_union

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|apr_proc_mutex_t
block|{
name|apr_pool_t
modifier|*
name|pool
decl_stmt|;
specifier|const
name|apr_proc_mutex_unix_lock_methods_t
modifier|*
name|meth
decl_stmt|;
specifier|const
name|apr_proc_mutex_unix_lock_methods_t
modifier|*
name|inter_meth
decl_stmt|;
name|int
name|curr_locked
decl_stmt|;
name|char
modifier|*
name|fname
decl_stmt|;
if|#
directive|if
name|APR_HAS_SYSVSEM_SERIALIZE
operator|||
name|APR_HAS_FCNTL_SERIALIZE
operator|||
name|APR_HAS_FLOCK_SERIALIZE
name|apr_file_t
modifier|*
name|interproc
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|APR_HAS_POSIXSEM_SERIALIZE
name|sem_t
modifier|*
name|psem_interproc
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|APR_HAS_PROC_PTHREAD_SERIALIZE
name|pthread_mutex_t
modifier|*
name|pthread_interproc
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_function_decl
name|void
name|apr_proc_mutex_unix_setup_lock
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PROC_MUTEX_H */
end_comment

end_unit

