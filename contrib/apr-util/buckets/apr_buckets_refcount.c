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
name|apr_bucket_shared_split
argument_list|(
argument|apr_bucket *a
argument_list|,
argument|apr_size_t point
argument_list|)
end_macro

begin_block
block|{
name|apr_bucket_refcount
modifier|*
name|r
init|=
name|a
operator|->
name|data
decl_stmt|;
name|apr_status_t
name|rv
decl_stmt|;
if|if
condition|(
operator|(
name|rv
operator|=
name|apr_bucket_simple_split
argument_list|(
name|a
argument_list|,
name|point
argument_list|)
operator|)
operator|!=
name|APR_SUCCESS
condition|)
block|{
return|return
name|rv
return|;
block|}
name|r
operator|->
name|refcount
operator|++
expr_stmt|;
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
name|apr_bucket_shared_copy
argument_list|(
argument|apr_bucket *a
argument_list|,
argument|apr_bucket **b
argument_list|)
end_macro

begin_block
block|{
name|apr_bucket_refcount
modifier|*
name|r
init|=
name|a
operator|->
name|data
decl_stmt|;
name|apr_bucket_simple_copy
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
name|r
operator|->
name|refcount
operator|++
expr_stmt|;
return|return
name|APR_SUCCESS
return|;
block|}
end_block

begin_macro
name|APU_DECLARE
argument_list|(
argument|int
argument_list|)
end_macro

begin_macro
name|apr_bucket_shared_destroy
argument_list|(
argument|void *data
argument_list|)
end_macro

begin_block
block|{
name|apr_bucket_refcount
modifier|*
name|r
init|=
name|data
decl_stmt|;
name|r
operator|->
name|refcount
operator|--
expr_stmt|;
return|return
operator|(
name|r
operator|->
name|refcount
operator|==
literal|0
operator|)
return|;
block|}
end_block

begin_macro
name|APU_DECLARE
argument_list|(
argument|apr_bucket *
argument_list|)
end_macro

begin_macro
name|apr_bucket_shared_make
argument_list|(
argument|apr_bucket *b
argument_list|,
argument|void *data
argument_list|,
argument|apr_off_t start
argument_list|,
argument|apr_size_t length
argument_list|)
end_macro

begin_block
block|{
name|apr_bucket_refcount
modifier|*
name|r
init|=
name|data
decl_stmt|;
name|b
operator|->
name|data
operator|=
name|r
expr_stmt|;
name|b
operator|->
name|start
operator|=
name|start
expr_stmt|;
name|b
operator|->
name|length
operator|=
name|length
expr_stmt|;
comment|/* caller initializes the type field */
name|r
operator|->
name|refcount
operator|=
literal|1
expr_stmt|;
return|return
name|b
return|;
block|}
end_block

end_unit

