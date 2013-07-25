begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Licensed to the Apache Software Foundation (ASF) under one or more  * contributor license agreements.  See the NOTICE file distributed with  * this work for additional information regarding copyright ownership.  * The ASF licenses this file to You under the Apache License, Version 2.0  * (the "License"); you may not use this file except in compliance with  * the License.  You may obtain a copy of the License at  *  *     http://www.apache.org/licenses/LICENSE-2.0  *  * Unless required by applicable law or agreed to in writing, software  * distributed under the License is distributed on an "AS IS" BASIS,  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  * See the License for the specific language governing permissions and  * limitations under the License.  */
end_comment

begin_include
include|#
directive|include
file|"apr_arch_file_io.h"
end_include

begin_include
include|#
directive|include
file|"apr_pools.h"
end_include

begin_include
include|#
directive|include
file|"apr_thread_mutex.h"
end_include

begin_macro
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
end_macro

begin_macro
name|apr_file_buffer_set
argument_list|(
argument|apr_file_t *file
argument_list|,
argument|char * buffer
argument_list|,
argument|apr_size_t bufsize
argument_list|)
end_macro

begin_block
block|{
name|apr_status_t
name|rv
decl_stmt|;
name|file_lock
argument_list|(
name|file
argument_list|)
expr_stmt|;
if|if
condition|(
name|file
operator|->
name|buffered
condition|)
block|{
comment|/* Flush the existing buffer */
name|rv
operator|=
name|apr_file_flush_locked
argument_list|(
name|file
argument_list|)
expr_stmt|;
if|if
condition|(
name|rv
operator|!=
name|APR_SUCCESS
condition|)
block|{
name|file_unlock
argument_list|(
name|file
argument_list|)
expr_stmt|;
return|return
name|rv
return|;
block|}
block|}
name|file
operator|->
name|buffer
operator|=
name|buffer
expr_stmt|;
name|file
operator|->
name|bufsize
operator|=
name|bufsize
expr_stmt|;
name|file
operator|->
name|buffered
operator|=
literal|1
expr_stmt|;
name|file
operator|->
name|bufpos
operator|=
literal|0
expr_stmt|;
name|file
operator|->
name|direction
operator|=
literal|0
expr_stmt|;
name|file
operator|->
name|dataRead
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|file
operator|->
name|bufsize
operator|==
literal|0
condition|)
block|{
comment|/* Setting the buffer size to zero is equivalent to turning               * buffering off.               */
name|file
operator|->
name|buffered
operator|=
literal|0
expr_stmt|;
block|}
name|file_unlock
argument_list|(
name|file
argument_list|)
expr_stmt|;
return|return
name|APR_SUCCESS
return|;
block|}
end_block

begin_macro
name|APR_DECLARE
argument_list|(
argument|apr_size_t
argument_list|)
end_macro

begin_macro
name|apr_file_buffer_size_get
argument_list|(
argument|apr_file_t *file
argument_list|)
end_macro

begin_block
block|{
return|return
name|file
operator|->
name|bufsize
return|;
block|}
end_block

end_unit

