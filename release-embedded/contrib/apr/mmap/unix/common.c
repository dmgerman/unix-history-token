begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Licensed to the Apache Software Foundation (ASF) under one or more  * contributor license agreements.  See the NOTICE file distributed with  * this work for additional information regarding copyright ownership.  * The ASF licenses this file to You under the Apache License, Version 2.0  * (the "License"); you may not use this file except in compliance with  * the License.  You may obtain a copy of the License at  *  *     http://www.apache.org/licenses/LICENSE-2.0  *  * Unless required by applicable law or agreed to in writing, software  * distributed under the License is distributed on an "AS IS" BASIS,  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  * See the License for the specific language governing permissions and  * limitations under the License.  */
end_comment

begin_comment
comment|/* common .c  * This file has any function that is truly common and platform  * neutral.  Or at least that's the theory.  *   * The header files are a problem so there are a few #ifdef's to take  * care of those.  *  */
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
file|"apr_mmap.h"
end_include

begin_include
include|#
directive|include
file|"apr_errno.h"
end_include

begin_if
if|#
directive|if
name|APR_HAS_MMAP
operator|||
name|defined
argument_list|(
name|BEOS
argument_list|)
end_if

begin_macro
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
end_macro

begin_macro
name|apr_mmap_offset
argument_list|(
argument|void **addr
argument_list|,
argument|apr_mmap_t *mmap
argument_list|,
argument|apr_off_t offset
argument_list|)
end_macro

begin_block
block|{
if|if
condition|(
name|offset
operator|<
literal|0
operator|||
operator|(
name|apr_size_t
operator|)
name|offset
operator|>
name|mmap
operator|->
name|size
condition|)
return|return
name|APR_EINVAL
return|;
operator|(
operator|*
name|addr
operator|)
operator|=
operator|(
name|char
operator|*
operator|)
name|mmap
operator|->
name|mm
operator|+
name|offset
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

end_unit

