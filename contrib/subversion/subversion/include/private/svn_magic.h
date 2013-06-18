begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  * @copyright  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  * @endcopyright  *  * @file svn_magic.h  * @brief Subversion interface to libmagic.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_MAGIC_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_MAGIC_H
end_define

begin_comment
comment|/* An opaque struct that wraps a libmagic cookie. */
end_comment

begin_typedef
typedef|typedef
name|struct
name|svn_magic__cookie_t
name|svn_magic__cookie_t
typedef|;
end_typedef

begin_comment
comment|/* This routine initialises libmagic.  * Upon success a new *MAGIC_COOKIE is allocated in RESULT_POOL.  * On failure *MAGIC_COOKIE is set to NULL.  * All resources used by libmagic are freed by a cleanup handler  * installed on RESULT_POOL, i.e. *MAGIC_COOKIE becomes invalid when  * the pool is cleared! */
end_comment

begin_function_decl
name|void
name|svn_magic__init
parameter_list|(
name|svn_magic__cookie_t
modifier|*
modifier|*
name|magic_cookie
parameter_list|,
name|apr_pool_t
modifier|*
name|result_pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Detect the mime-type of the file at LOCAL_ABSPATH using MAGIC_COOKIE.  * If the mime-type is binary return the result in *MIMETYPE.  * If the file is not a binary file or if its mime-type cannot be determined  * set *MIMETYPE to NULL. Allocate *MIMETYPE in RESULT_POOL.  * Use SCRATCH_POOL for temporary allocations. */
end_comment

begin_function_decl
name|svn_error_t
modifier|*
name|svn_magic__detect_binary_mimetype
parameter_list|(
specifier|const
name|char
modifier|*
modifier|*
name|mimetype
parameter_list|,
specifier|const
name|char
modifier|*
name|local_abspath
parameter_list|,
name|svn_magic__cookie_t
modifier|*
name|magic_cookie
parameter_list|,
name|apr_pool_t
modifier|*
name|result_pool
parameter_list|,
name|apr_pool_t
modifier|*
name|scratch_pool
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SVN_MAGIC_H */
end_comment

end_unit

