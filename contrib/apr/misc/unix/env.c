begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Licensed to the Apache Software Foundation (ASF) under one or more  * contributor license agreements.  See the NOTICE file distributed with  * this work for additional information regarding copyright ownership.  * The ASF licenses this file to You under the Apache License, Version 2.0  * (the "License"); you may not use this file except in compliance with  * the License.  You may obtain a copy of the License at  *  *     http://www.apache.org/licenses/LICENSE-2.0  *  * Unless required by applicable law or agreed to in writing, software  * distributed under the License is distributed on an "AS IS" BASIS,  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  * See the License for the specific language governing permissions and  * limitations under the License.  */
end_comment

begin_define
define|#
directive|define
name|APR_WANT_STRFUNC
end_define

begin_include
include|#
directive|include
file|"apr_want.h"
end_include

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
file|"apr_env.h"
end_include

begin_include
include|#
directive|include
file|"apr_strings.h"
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

begin_macro
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
end_macro

begin_macro
name|apr_env_get
argument_list|(
argument|char **value
argument_list|,
argument|const char *envvar
argument_list|,
argument|apr_pool_t *pool
argument_list|)
end_macro

begin_block
block|{
ifdef|#
directive|ifdef
name|HAVE_GETENV
name|char
modifier|*
name|val
init|=
name|getenv
argument_list|(
name|envvar
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|val
condition|)
return|return
name|APR_ENOENT
return|;
operator|*
name|value
operator|=
name|val
expr_stmt|;
return|return
name|APR_SUCCESS
return|;
else|#
directive|else
return|return
name|APR_ENOTIMPL
return|;
endif|#
directive|endif
block|}
end_block

begin_macro
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
end_macro

begin_macro
name|apr_env_set
argument_list|(
argument|const char *envvar
argument_list|,
argument|const char *value
argument_list|,
argument|apr_pool_t *pool
argument_list|)
end_macro

begin_block
block|{
if|#
directive|if
name|defined
argument_list|(
name|HAVE_SETENV
argument_list|)
if|if
condition|(
literal|0
operator|>
name|setenv
argument_list|(
name|envvar
argument_list|,
name|value
argument_list|,
literal|1
argument_list|)
condition|)
return|return
name|APR_ENOMEM
return|;
return|return
name|APR_SUCCESS
return|;
elif|#
directive|elif
name|defined
argument_list|(
name|HAVE_PUTENV
argument_list|)
if|if
condition|(
literal|0
operator|>
name|putenv
argument_list|(
name|apr_pstrcat
argument_list|(
name|pool
argument_list|,
name|envvar
argument_list|,
literal|"="
argument_list|,
name|value
argument_list|,
name|NULL
argument_list|)
argument_list|)
condition|)
return|return
name|APR_ENOMEM
return|;
return|return
name|APR_SUCCESS
return|;
else|#
directive|else
return|return
name|APR_ENOTIMPL
return|;
endif|#
directive|endif
block|}
end_block

begin_macro
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
end_macro

begin_macro
name|apr_env_delete
argument_list|(
argument|const char *envvar
argument_list|,
argument|apr_pool_t *pool
argument_list|)
end_macro

begin_block
block|{
ifdef|#
directive|ifdef
name|HAVE_UNSETENV
name|unsetenv
argument_list|(
name|envvar
argument_list|)
expr_stmt|;
return|return
name|APR_SUCCESS
return|;
else|#
directive|else
comment|/* hint: some platforms allow envvars to be unset via      *       putenv("varname")...  that isn't Single Unix spec,      *       but if your platform doesn't have unsetenv() it is      *       worth investigating and potentially adding a      *       configure check to decide when to use that form of      *       putenv() here      */
return|return
name|APR_ENOTIMPL
return|;
endif|#
directive|endif
block|}
end_block

end_unit

