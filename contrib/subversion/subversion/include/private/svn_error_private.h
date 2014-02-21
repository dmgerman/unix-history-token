begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  * @copyright  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  * @endcopyright  *  * @file svn_error_private.h  * @brief Subversion-internal error APIs.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_ERROR_PRIVATE_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_ERROR_PRIVATE_H
end_define

begin_include
include|#
directive|include
file|"svn_types.h"
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
comment|/**  * Returns if @a err is a "tracing" error.  */
name|svn_boolean_t
name|svn_error__is_tracing_link
parameter_list|(
name|svn_error_t
modifier|*
name|err
parameter_list|)
function_decl|;
comment|/**  * Converts a zlib error to an svn_error_t. zerr is the error code,  * function is the function name, message is an optional extra part  * of the error message and may be NULL.  */
name|svn_error_t
modifier|*
name|svn_error__wrap_zlib
parameter_list|(
name|int
name|zerr
parameter_list|,
specifier|const
name|char
modifier|*
name|function
parameter_list|,
specifier|const
name|char
modifier|*
name|message
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __cplusplus */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SVN_ERROR_PRIVATE_H */
end_comment

end_unit

