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
file|"apr_general.h"
end_include

begin_include
include|#
directive|include
file|"apr_pools.h"
end_include

begin_include
include|#
directive|include
file|"apr_signal.h"
end_include

begin_include
include|#
directive|include
file|"apr_atomic.h"
end_include

begin_include
include|#
directive|include
file|"apr_arch_proc_mutex.h"
end_include

begin_comment
comment|/* for apr_proc_mutex_unix_setup_lock() */
end_comment

begin_include
include|#
directive|include
file|"apr_arch_internal_time.h"
end_include

begin_macro
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
end_macro

begin_macro
name|apr_app_initialize
argument_list|(
argument|int *argc
argument_list|,
argument|const char * const * *argv
argument_list|,
argument|const char * const * *env
argument_list|)
end_macro

begin_block
block|{
comment|/* An absolute noop.  At present, only Win32 requires this stub, but it's      * required in order to move command arguments passed through the service      * control manager into the process, and it's required to fix the char*      * data passed in from win32 unicode into utf-8, win32's apr internal fmt.      */
return|return
name|apr_initialize
argument_list|()
return|;
block|}
end_block

begin_decl_stmt
specifier|static
name|int
name|initialized
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_macro
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
end_macro

begin_macro
name|apr_initialize
argument_list|(
argument|void
argument_list|)
end_macro

begin_block
block|{
name|apr_pool_t
modifier|*
name|pool
decl_stmt|;
name|apr_status_t
name|status
decl_stmt|;
if|if
condition|(
name|initialized
operator|++
condition|)
block|{
return|return
name|APR_SUCCESS
return|;
block|}
if|#
directive|if
operator|!
name|defined
argument_list|(
name|BEOS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|OS2
argument_list|)
name|apr_proc_mutex_unix_setup_lock
argument_list|()
expr_stmt|;
name|apr_unix_setup_time
argument_list|()
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
operator|(
name|status
operator|=
name|apr_pool_initialize
argument_list|()
operator|)
operator|!=
name|APR_SUCCESS
condition|)
return|return
name|status
return|;
if|if
condition|(
name|apr_pool_create
argument_list|(
operator|&
name|pool
argument_list|,
name|NULL
argument_list|)
operator|!=
name|APR_SUCCESS
condition|)
block|{
return|return
name|APR_ENOPOOL
return|;
block|}
name|apr_pool_tag
argument_list|(
name|pool
argument_list|,
literal|"apr_initialize"
argument_list|)
expr_stmt|;
comment|/* apr_atomic_init() used to be called from here aswell.      * Pools rely on mutexes though, which can be backed by      * atomics.  Due to this circular dependency      * apr_pool_initialize() is taking care of calling      * apr_atomic_init() at the correct time.      */
name|apr_signal_init
argument_list|(
name|pool
argument_list|)
expr_stmt|;
return|return
name|APR_SUCCESS
return|;
block|}
end_block

begin_macro
name|APR_DECLARE_NONSTD
argument_list|(
argument|void
argument_list|)
end_macro

begin_macro
name|apr_terminate
argument_list|(
argument|void
argument_list|)
end_macro

begin_block
block|{
name|initialized
operator|--
expr_stmt|;
if|if
condition|(
name|initialized
condition|)
block|{
return|return;
block|}
name|apr_pool_terminate
argument_list|()
expr_stmt|;
block|}
end_block

begin_macro
name|APR_DECLARE
argument_list|(
argument|void
argument_list|)
end_macro

begin_macro
name|apr_terminate2
argument_list|(
argument|void
argument_list|)
end_macro

begin_block
block|{
name|apr_terminate
argument_list|()
expr_stmt|;
block|}
end_block

end_unit

