begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Licensed to the Apache Software Foundation (ASF) under one or more  * contributor license agreements.  See the NOTICE file distributed with  * this work for additional information regarding copyright ownership.  * The ASF licenses this file to You under the Apache License, Version 2.0  * (the "License"); you may not use this file except in compliance with  * the License.  You may obtain a copy of the License at  *  *     http://www.apache.org/licenses/LICENSE-2.0  *  * Unless required by applicable law or agreed to in writing, software  * distributed under the License is distributed on an "AS IS" BASIS,  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  * See the License for the specific language governing permissions and  * limitations under the License.  */
end_comment

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
file|"apr_thread_proc.h"
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
comment|/* System headers required for thread/process library */
end_comment

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

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_RESOURCE_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/resource.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|APR_HAVE_SIGNAL_H
end_if

begin_include
include|#
directive|include
file|<signal.h>
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

begin_if
if|#
directive|if
name|APR_HAVE_SYS_WAIT_H
end_if

begin_include
include|#
directive|include
file|<sys/wait.h>
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
name|HAVE_SCHED_H
end_ifdef

begin_include
include|#
directive|include
file|<sched.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* End System Headers */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|THREAD_PROC_H
end_ifndef

begin_define
define|#
directive|define
name|THREAD_PROC_H
end_define

begin_define
define|#
directive|define
name|SHELL_PATH
value|"/bin/sh"
end_define

begin_if
if|#
directive|if
name|APR_HAS_THREADS
end_if

begin_struct
struct|struct
name|apr_thread_t
block|{
name|apr_pool_t
modifier|*
name|pool
decl_stmt|;
name|pthread_t
modifier|*
name|td
decl_stmt|;
name|void
modifier|*
name|data
decl_stmt|;
name|apr_thread_start_t
name|func
decl_stmt|;
name|apr_status_t
name|exitval
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|apr_threadattr_t
block|{
name|apr_pool_t
modifier|*
name|pool
decl_stmt|;
name|pthread_attr_t
name|attr
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|apr_threadkey_t
block|{
name|apr_pool_t
modifier|*
name|pool
decl_stmt|;
name|pthread_key_t
name|key
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|apr_thread_once_t
block|{
name|pthread_once_t
name|once
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|apr_procattr_t
block|{
name|apr_pool_t
modifier|*
name|pool
decl_stmt|;
name|apr_file_t
modifier|*
name|parent_in
decl_stmt|;
name|apr_file_t
modifier|*
name|child_in
decl_stmt|;
name|apr_file_t
modifier|*
name|parent_out
decl_stmt|;
name|apr_file_t
modifier|*
name|child_out
decl_stmt|;
name|apr_file_t
modifier|*
name|parent_err
decl_stmt|;
name|apr_file_t
modifier|*
name|child_err
decl_stmt|;
name|char
modifier|*
name|currdir
decl_stmt|;
name|apr_int32_t
name|cmdtype
decl_stmt|;
name|apr_int32_t
name|detached
decl_stmt|;
ifdef|#
directive|ifdef
name|RLIMIT_CPU
name|struct
name|rlimit
modifier|*
name|limit_cpu
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|RLIMIT_DATA
argument_list|)
operator|||
name|defined
argument_list|(
name|RLIMIT_VMEM
argument_list|)
operator|||
name|defined
argument_list|(
name|RLIMIT_AS
argument_list|)
name|struct
name|rlimit
modifier|*
name|limit_mem
decl_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|RLIMIT_NPROC
name|struct
name|rlimit
modifier|*
name|limit_nproc
decl_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|RLIMIT_NOFILE
name|struct
name|rlimit
modifier|*
name|limit_nofile
decl_stmt|;
endif|#
directive|endif
name|apr_child_errfn_t
modifier|*
name|errfn
decl_stmt|;
name|apr_int32_t
name|errchk
decl_stmt|;
name|apr_uid_t
name|uid
decl_stmt|;
name|apr_gid_t
name|gid
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! THREAD_PROC_H */
end_comment

end_unit

