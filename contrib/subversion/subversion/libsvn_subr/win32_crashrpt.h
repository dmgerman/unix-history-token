begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * win32_crashrpt.h : shares the win32 crashhandler functions in libsvn_subr.  *  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_LIBSVN_SUBR_WIN32_CRASHRPT_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_LIBSVN_SUBR_WIN32_CRASHRPT_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|WIN32
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|SVN_USE_WIN32_CRASHHANDLER
end_ifdef

begin_function_decl
name|LONG
name|WINAPI
name|svn__unhandled_exception_filter
parameter_list|(
name|PEXCEPTION_POINTERS
name|ptrs
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SVN_USE_WIN32_CRASHHANDLER */
end_comment

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
comment|/* SVN_LIBSVN_SUBR_WIN32_CRASHRPT_H */
end_comment

end_unit

