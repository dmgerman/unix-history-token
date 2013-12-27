begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Licensed to the Apache Software Foundation (ASF) under one or more  * contributor license agreements.  See the NOTICE file distributed with  * this work for additional information regarding copyright ownership.  * The ASF licenses this file to You under the Apache License, Version 2.0  * (the "License"); you may not use this file except in compliance with  * the License.  You may obtain a copy of the License at  *  *     http://www.apache.org/licenses/LICENSE-2.0  *  * Unless required by applicable law or agreed to in writing, software  * distributed under the License is distributed on an "AS IS" BASIS,  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  * See the License for the specific language governing permissions and  * limitations under the License.  */
end_comment

begin_include
include|#
directive|include
file|"apr_general.h"
end_include

begin_comment
comment|/* for APR_STRINGIFY */
end_comment

begin_include
include|#
directive|include
file|"apu.h"
end_include

begin_include
include|#
directive|include
file|"apu_version.h"
end_include

begin_macro
name|APU_DECLARE
argument_list|(
argument|void
argument_list|)
end_macro

begin_macro
name|apu_version
argument_list|(
argument|apr_version_t *pvsn
argument_list|)
end_macro

begin_block
block|{
name|pvsn
operator|->
name|major
operator|=
name|APU_MAJOR_VERSION
expr_stmt|;
name|pvsn
operator|->
name|minor
operator|=
name|APU_MINOR_VERSION
expr_stmt|;
name|pvsn
operator|->
name|patch
operator|=
name|APU_PATCH_VERSION
expr_stmt|;
ifdef|#
directive|ifdef
name|APU_IS_DEV_VERSION
name|pvsn
operator|->
name|is_dev
operator|=
literal|1
expr_stmt|;
else|#
directive|else
name|pvsn
operator|->
name|is_dev
operator|=
literal|0
expr_stmt|;
endif|#
directive|endif
block|}
end_block

begin_macro
name|APU_DECLARE
argument_list|(
argument|const char *
argument_list|)
end_macro

begin_macro
name|apu_version_string
argument_list|(
argument|void
argument_list|)
end_macro

begin_block
block|{
return|return
name|APU_VERSION_STRING
return|;
block|}
end_block

end_unit

