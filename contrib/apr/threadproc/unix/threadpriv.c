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
file|"apr_portable.h"
end_include

begin_include
include|#
directive|include
file|"apr_arch_threadproc.h"
end_include

begin_if
if|#
directive|if
name|APR_HAS_THREADS
end_if

begin_if
if|#
directive|if
name|APR_HAVE_PTHREAD_H
end_if

begin_macro
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
end_macro

begin_macro
name|apr_threadkey_private_create
argument_list|(
argument|apr_threadkey_t **key
argument_list|,
argument|void (*dest)(void *)
argument_list|,
argument|apr_pool_t *pool
argument_list|)
end_macro

begin_block
block|{
operator|(
operator|*
name|key
operator|)
operator|=
operator|(
name|apr_threadkey_t
operator|*
operator|)
name|apr_pcalloc
argument_list|(
name|pool
argument_list|,
sizeof|sizeof
argument_list|(
name|apr_threadkey_t
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
operator|*
name|key
operator|)
operator|==
name|NULL
condition|)
block|{
return|return
name|APR_ENOMEM
return|;
block|}
operator|(
operator|*
name|key
operator|)
operator|->
name|pool
operator|=
name|pool
expr_stmt|;
return|return
name|pthread_key_create
argument_list|(
operator|&
operator|(
operator|*
name|key
operator|)
operator|->
name|key
argument_list|,
name|dest
argument_list|)
return|;
block|}
end_block

begin_macro
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
end_macro

begin_macro
name|apr_threadkey_private_get
argument_list|(
argument|void **new
argument_list|,
argument|apr_threadkey_t *key
argument_list|)
end_macro

begin_block
block|{
ifdef|#
directive|ifdef
name|PTHREAD_GETSPECIFIC_TAKES_TWO_ARGS
if|if
condition|(
name|pthread_getspecific
argument_list|(
name|key
operator|->
name|key
argument_list|,
name|new
argument_list|)
condition|)
operator|*
name|new
operator|=
name|NULL
expr_stmt|;
else|#
directive|else
operator|(
operator|*
name|new
operator|)
operator|=
name|pthread_getspecific
argument_list|(
name|key
operator|->
name|key
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
name|APR_SUCCESS
return|;
block|}
end_block

begin_macro
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
end_macro

begin_macro
name|apr_threadkey_private_set
argument_list|(
argument|void *priv
argument_list|,
argument|apr_threadkey_t *key
argument_list|)
end_macro

begin_block
block|{
name|apr_status_t
name|stat
decl_stmt|;
if|if
condition|(
operator|(
name|stat
operator|=
name|pthread_setspecific
argument_list|(
name|key
operator|->
name|key
argument_list|,
name|priv
argument_list|)
operator|)
operator|==
literal|0
condition|)
block|{
return|return
name|APR_SUCCESS
return|;
block|}
else|else
block|{
return|return
name|stat
return|;
block|}
block|}
end_block

begin_macro
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
end_macro

begin_macro
name|apr_threadkey_private_delete
argument_list|(
argument|apr_threadkey_t *key
argument_list|)
end_macro

begin_block
block|{
ifdef|#
directive|ifdef
name|HAVE_PTHREAD_KEY_DELETE
name|apr_status_t
name|stat
decl_stmt|;
if|if
condition|(
operator|(
name|stat
operator|=
name|pthread_key_delete
argument_list|(
name|key
operator|->
name|key
argument_list|)
operator|)
operator|==
literal|0
condition|)
block|{
return|return
name|APR_SUCCESS
return|;
block|}
return|return
name|stat
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
name|apr_threadkey_data_get
argument_list|(
argument|void **data
argument_list|,
argument|const char *key
argument_list|,
argument|apr_threadkey_t *threadkey
argument_list|)
end_macro

begin_block
block|{
return|return
name|apr_pool_userdata_get
argument_list|(
name|data
argument_list|,
name|key
argument_list|,
name|threadkey
operator|->
name|pool
argument_list|)
return|;
block|}
end_block

begin_macro
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
end_macro

begin_macro
name|apr_threadkey_data_set
argument_list|(
argument|void *data
argument_list|,
argument|const char *key
argument_list|,
argument|apr_status_t (*cleanup)(void *)
argument_list|,
argument|apr_threadkey_t *threadkey
argument_list|)
end_macro

begin_block
block|{
return|return
name|apr_pool_userdata_set
argument_list|(
name|data
argument_list|,
name|key
argument_list|,
name|cleanup
argument_list|,
name|threadkey
operator|->
name|pool
argument_list|)
return|;
block|}
end_block

begin_macro
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
end_macro

begin_macro
name|apr_os_threadkey_get
argument_list|(
argument|apr_os_threadkey_t *thekey
argument_list|,
argument|apr_threadkey_t *key
argument_list|)
end_macro

begin_block
block|{
operator|*
name|thekey
operator|=
name|key
operator|->
name|key
expr_stmt|;
return|return
name|APR_SUCCESS
return|;
block|}
end_block

begin_macro
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
end_macro

begin_macro
name|apr_os_threadkey_put
argument_list|(
argument|apr_threadkey_t **key
argument_list|,
argument|apr_os_threadkey_t *thekey
argument_list|,
argument|apr_pool_t *pool
argument_list|)
end_macro

begin_block
block|{
if|if
condition|(
name|pool
operator|==
name|NULL
condition|)
block|{
return|return
name|APR_ENOPOOL
return|;
block|}
if|if
condition|(
operator|(
operator|*
name|key
operator|)
operator|==
name|NULL
condition|)
block|{
operator|(
operator|*
name|key
operator|)
operator|=
operator|(
name|apr_threadkey_t
operator|*
operator|)
name|apr_pcalloc
argument_list|(
name|pool
argument_list|,
sizeof|sizeof
argument_list|(
name|apr_threadkey_t
argument_list|)
argument_list|)
expr_stmt|;
operator|(
operator|*
name|key
operator|)
operator|->
name|pool
operator|=
name|pool
expr_stmt|;
block|}
operator|(
operator|*
name|key
operator|)
operator|->
name|key
operator|=
operator|*
name|thekey
expr_stmt|;
return|return
name|APR_SUCCESS
return|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* APR_HAVE_PTHREAD_H */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* APR_HAS_THREADS */
end_comment

begin_if
if|#
directive|if
operator|!
name|APR_HAS_THREADS
end_if

begin_comment
comment|/* avoid warning for no prototype */
end_comment

begin_macro
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
end_macro

begin_expr_stmt
name|apr_os_threadkey_get
argument_list|(
name|void
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
end_macro

begin_macro
name|apr_os_threadkey_get
argument_list|(
argument|void
argument_list|)
end_macro

begin_block
block|{
return|return
name|APR_ENOTIMPL
return|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

end_unit

