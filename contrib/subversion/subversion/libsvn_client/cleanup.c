begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * cleanup.c:  wrapper around wc cleanup functionality.  *  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  */
end_comment

begin_comment
comment|/* ==================================================================== */
end_comment

begin_escape
end_escape

begin_comment
comment|/*** Includes. ***/
end_comment

begin_include
include|#
directive|include
file|"svn_time.h"
end_include

begin_include
include|#
directive|include
file|"svn_wc.h"
end_include

begin_include
include|#
directive|include
file|"svn_client.h"
end_include

begin_include
include|#
directive|include
file|"svn_config.h"
end_include

begin_include
include|#
directive|include
file|"svn_dirent_uri.h"
end_include

begin_include
include|#
directive|include
file|"svn_path.h"
end_include

begin_include
include|#
directive|include
file|"svn_pools.h"
end_include

begin_include
include|#
directive|include
file|"client.h"
end_include

begin_include
include|#
directive|include
file|"svn_props.h"
end_include

begin_include
include|#
directive|include
file|"svn_private_config.h"
end_include

begin_escape
end_escape

begin_comment
comment|/*** Code. ***/
end_comment

begin_function
name|svn_error_t
modifier|*
name|svn_client_cleanup
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|,
name|svn_client_ctx_t
modifier|*
name|ctx
parameter_list|,
name|apr_pool_t
modifier|*
name|scratch_pool
parameter_list|)
block|{
specifier|const
name|char
modifier|*
name|local_abspath
decl_stmt|;
name|svn_error_t
modifier|*
name|err
decl_stmt|;
if|if
condition|(
name|svn_path_is_url
argument_list|(
name|path
argument_list|)
condition|)
return|return
name|svn_error_createf
argument_list|(
name|SVN_ERR_ILLEGAL_TARGET
argument_list|,
name|NULL
argument_list|,
name|_
argument_list|(
literal|"'%s' is not a local path"
argument_list|)
argument_list|,
name|path
argument_list|)
return|;
name|SVN_ERR
argument_list|(
name|svn_dirent_get_absolute
argument_list|(
operator|&
name|local_abspath
argument_list|,
name|path
argument_list|,
name|scratch_pool
argument_list|)
argument_list|)
expr_stmt|;
name|err
operator|=
name|svn_wc_cleanup3
argument_list|(
name|ctx
operator|->
name|wc_ctx
argument_list|,
name|local_abspath
argument_list|,
name|ctx
operator|->
name|cancel_func
argument_list|,
name|ctx
operator|->
name|cancel_baton
argument_list|,
name|scratch_pool
argument_list|)
expr_stmt|;
name|svn_io_sleep_for_timestamps
argument_list|(
name|path
argument_list|,
name|scratch_pool
argument_list|)
expr_stmt|;
return|return
name|svn_error_trace
argument_list|(
name|err
argument_list|)
return|;
block|}
end_function

end_unit

