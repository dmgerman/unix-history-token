begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Licensed to the Apache Software Foundation (ASF) under one or more  * contributor license agreements.  See the NOTICE file distributed with  * this work for additional information regarding copyright ownership.  * The ASF licenses this file to You under the Apache License, Version 2.0  * (the "License"); you may not use this file except in compliance with  * the License.  You may obtain a copy of the License at  *  *     http://www.apache.org/licenses/LICENSE-2.0  *  * Unless required by applicable law or agreed to in writing, software  * distributed under the License is distributed on an "AS IS" BASIS,  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  * See the License for the specific language governing permissions and  * limitations under the License.  */
end_comment

begin_comment
comment|/*  * This file contains private declarations common to all architectures.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|APR_PRIVATE_COMMON_H
end_ifndef

begin_define
define|#
directive|define
name|APR_PRIVATE_COMMON_H
end_define

begin_include
include|#
directive|include
file|"apr_pools.h"
end_include

begin_include
include|#
directive|include
file|"apr_tables.h"
end_include

begin_function_decl
name|apr_status_t
name|apr_filepath_list_split_impl
parameter_list|(
name|apr_array_header_t
modifier|*
modifier|*
name|pathelts
parameter_list|,
specifier|const
name|char
modifier|*
name|liststr
parameter_list|,
name|char
name|separator
parameter_list|,
name|apr_pool_t
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|apr_status_t
name|apr_filepath_list_merge_impl
parameter_list|(
name|char
modifier|*
modifier|*
name|liststr
parameter_list|,
name|apr_array_header_t
modifier|*
name|pathelts
parameter_list|,
name|char
name|separator
parameter_list|,
name|apr_pool_t
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* temporary defines to handle 64bit compile mismatches */
end_comment

begin_define
define|#
directive|define
name|APR_INT_TRUNC_CAST
value|int
end_define

begin_define
define|#
directive|define
name|APR_UINT32_TRUNC_CAST
value|apr_uint32_t
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*APR_PRIVATE_COMMON_H*/
end_comment

end_unit

