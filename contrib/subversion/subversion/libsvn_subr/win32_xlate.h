begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * win32_xlate.h : Windows xlate stuff.  *  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_LIBSVN_SUBR_WIN32_XLATE_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_LIBSVN_SUBR_WIN32_XLATE_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|WIN32
end_ifdef

begin_comment
comment|/* Opaque translation buffer. */
end_comment

begin_typedef
typedef|typedef
name|struct
name|win32_xlate_t
name|win32_xlate_t
typedef|;
end_typedef

begin_comment
comment|/* Set *XLATE_P to a handle node for converting from FROMPAGE to TOPAGE.    Returns APR_EINVAL or APR_ENOTIMPL, if a conversion isn't supported.    If fail for any other reason, return the error.     Allocate *RET in POOL. */
end_comment

begin_function_decl
name|apr_status_t
name|svn_subr__win32_xlate_open
parameter_list|(
name|win32_xlate_t
modifier|*
modifier|*
name|xlate_p
parameter_list|,
specifier|const
name|char
modifier|*
name|topage
parameter_list|,
specifier|const
name|char
modifier|*
name|frompage
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Convert SRC_LENGTH bytes of SRC_DATA in NODE->handle, store the result    in *DEST, which is allocated in POOL. */
end_comment

begin_function_decl
name|apr_status_t
name|svn_subr__win32_xlate_to_stringbuf
parameter_list|(
name|win32_xlate_t
modifier|*
name|handle
parameter_list|,
specifier|const
name|char
modifier|*
name|src_data
parameter_list|,
name|apr_size_t
name|src_length
parameter_list|,
name|svn_stringbuf_t
modifier|*
modifier|*
name|dest
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WIN32 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SVN_LIBSVN_SUBR_WIN32_XLATE_H */
end_comment

end_unit

