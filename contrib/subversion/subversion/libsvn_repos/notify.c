begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* notify.c --- notifcation system  *  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|"svn_pools.h"
end_include

begin_include
include|#
directive|include
file|"svn_repos.h"
end_include

begin_include
include|#
directive|include
file|"repos.h"
end_include

begin_include
include|#
directive|include
file|"svn_private_config.h"
end_include

begin_include
include|#
directive|include
file|"private/svn_utf_private.h"
end_include

begin_escape
end_escape

begin_function
name|svn_repos_notify_t
modifier|*
name|svn_repos_notify_create
parameter_list|(
name|svn_repos_notify_action_t
name|action
parameter_list|,
name|apr_pool_t
modifier|*
name|result_pool
parameter_list|)
block|{
name|svn_repos_notify_t
modifier|*
name|notify
init|=
name|apr_pcalloc
argument_list|(
name|result_pool
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|notify
argument_list|)
argument_list|)
decl_stmt|;
name|notify
operator|->
name|action
operator|=
name|action
expr_stmt|;
return|return
name|notify
return|;
block|}
end_function

end_unit

