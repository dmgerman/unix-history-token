begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Licensed to the Apache Software Foundation (ASF) under one or more  * contributor license agreements.  See the NOTICE file distributed with  * this work for additional information regarding copyright ownership.  * The ASF licenses this file to You under the Apache License, Version 2.0  * (the "License"); you may not use this file except in compliance with  * the License.  You may obtain a copy of the License at  *  *     http://www.apache.org/licenses/LICENSE-2.0  *  * Unless required by applicable law or agreed to in writing, software  * distributed under the License is distributed on an "AS IS" BASIS,  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  * See the License for the specific language governing permissions and  * limitations under the License.  */
end_comment

begin_include
include|#
directive|include
file|"apr_buckets.h"
end_include

begin_macro
name|APU_DECLARE_NONSTD
argument_list|(
argument|apr_status_t
argument_list|)
end_macro

begin_macro
name|apr_bucket_setaside_noop
argument_list|(
argument|apr_bucket *data
argument_list|,
argument|apr_pool_t *pool
argument_list|)
end_macro

begin_block
block|{
return|return
name|APR_SUCCESS
return|;
block|}
end_block

begin_macro
name|APU_DECLARE_NONSTD
argument_list|(
argument|apr_status_t
argument_list|)
end_macro

begin_macro
name|apr_bucket_setaside_notimpl
argument_list|(
argument|apr_bucket *data
argument_list|,
argument|apr_pool_t *pool
argument_list|)
end_macro

begin_block
block|{
return|return
name|APR_ENOTIMPL
return|;
block|}
end_block

begin_macro
name|APU_DECLARE_NONSTD
argument_list|(
argument|apr_status_t
argument_list|)
end_macro

begin_macro
name|apr_bucket_split_notimpl
argument_list|(
argument|apr_bucket *data
argument_list|,
argument|apr_size_t point
argument_list|)
end_macro

begin_block
block|{
return|return
name|APR_ENOTIMPL
return|;
block|}
end_block

begin_macro
name|APU_DECLARE_NONSTD
argument_list|(
argument|apr_status_t
argument_list|)
end_macro

begin_macro
name|apr_bucket_copy_notimpl
argument_list|(
argument|apr_bucket *e
argument_list|,
argument|apr_bucket **c
argument_list|)
end_macro

begin_block
block|{
return|return
name|APR_ENOTIMPL
return|;
block|}
end_block

begin_macro
name|APU_DECLARE_NONSTD
argument_list|(
argument|void
argument_list|)
end_macro

begin_macro
name|apr_bucket_destroy_noop
argument_list|(
argument|void *data
argument_list|)
end_macro

begin_block
block|{
return|return;
block|}
end_block

end_unit

