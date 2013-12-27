begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Licensed to the Apache Software Foundation (ASF) under one or more  * contributor license agreements.  See the NOTICE file distributed with  * this work for additional information regarding copyright ownership.  * The ASF licenses this file to You under the Apache License, Version 2.0  * (the "License"); you may not use this file except in compliance with  * the License.  You may obtain a copy of the License at  *  *     http://www.apache.org/licenses/LICENSE-2.0  *  * Unless required by applicable law or agreed to in writing, software  * distributed under the License is distributed on an "AS IS" BASIS,  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  * See the License for the specific language governing permissions and  * limitations under the License.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|APR_SUPPORT_H
end_ifndef

begin_define
define|#
directive|define
name|APR_SUPPORT_H
end_define

begin_comment
comment|/**  * @file apr_support.h  * @brief APR Support functions  */
end_comment

begin_include
include|#
directive|include
file|"apr.h"
end_include

begin_include
include|#
directive|include
file|"apr_network_io.h"
end_include

begin_include
include|#
directive|include
file|"apr_file_io.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|/* __cplusplus */
comment|/**  * @defgroup apr_support Internal APR support functions  * @ingroup APR   * @{  */
comment|/**  * Wait for IO to occur or timeout.  *  * @param f The file to wait on.  * @param s The socket to wait on if @a f is @c NULL.  * @param for_read If non-zero wait for data to be available to read,  *        otherwise wait for data to be able to be written.   * @return APR_TIMEUP if we run out of time.  */
name|apr_status_t
name|apr_wait_for_io_or_timeout
parameter_list|(
name|apr_file_t
modifier|*
name|f
parameter_list|,
name|apr_socket_t
modifier|*
name|s
parameter_list|,
name|int
name|for_read
parameter_list|)
function_decl|;
comment|/** @} */
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! APR_SUPPORT_H */
end_comment

end_unit

