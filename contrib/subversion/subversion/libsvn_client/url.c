begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * url.c:  converting paths to urls  *  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  */
end_comment

begin_escape
end_escape

begin_include
include|#
directive|include
file|<apr_pools.h>
end_include

begin_include
include|#
directive|include
file|"svn_pools.h"
end_include

begin_include
include|#
directive|include
file|"svn_error.h"
end_include

begin_include
include|#
directive|include
file|"svn_types.h"
end_include

begin_include
include|#
directive|include
file|"svn_opt.h"
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
file|"private/svn_wc_private.h"
end_include

begin_include
include|#
directive|include
file|"client.h"
end_include

begin_include
include|#
directive|include
file|"svn_private_config.h"
end_include

begin_escape
end_escape

begin_function
name|svn_error_t
modifier|*
name|svn_client_url_from_path2
parameter_list|(
specifier|const
name|char
modifier|*
modifier|*
name|url
parameter_list|,
specifier|const
name|char
modifier|*
name|path_or_url
parameter_list|,
name|svn_client_ctx_t
modifier|*
name|ctx
parameter_list|,
name|apr_pool_t
modifier|*
name|result_pool
parameter_list|,
name|apr_pool_t
modifier|*
name|scratch_pool
parameter_list|)
block|{
if|if
condition|(
operator|!
name|svn_path_is_url
argument_list|(
name|path_or_url
argument_list|)
condition|)
block|{
name|SVN_ERR
argument_list|(
name|svn_dirent_get_absolute
argument_list|(
operator|&
name|path_or_url
argument_list|,
name|path_or_url
argument_list|,
name|scratch_pool
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|svn_error_trace
argument_list|(
name|svn_wc__node_get_url
argument_list|(
name|url
argument_list|,
name|ctx
operator|->
name|wc_ctx
argument_list|,
name|path_or_url
argument_list|,
name|result_pool
argument_list|,
name|scratch_pool
argument_list|)
argument_list|)
return|;
block|}
else|else
operator|*
name|url
operator|=
name|svn_uri_canonicalize
argument_list|(
name|path_or_url
argument_list|,
name|result_pool
argument_list|)
expr_stmt|;
return|return
name|SVN_NO_ERROR
return|;
block|}
end_function

end_unit

