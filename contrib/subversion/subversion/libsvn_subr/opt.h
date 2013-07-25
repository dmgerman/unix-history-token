begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * opt.h: share svn_opt__* functions  *  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_LIBSVN_SUBR_OPT_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_LIBSVN_SUBR_OPT_H
end_define

begin_include
include|#
directive|include
file|"svn_version.h"
end_include

begin_include
include|#
directive|include
file|"svn_opt.h"
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
comment|/* Print version version info for PGM_NAME to the console.  If QUIET is  * true, print in brief.  Else if QUIET is not true, print the version  * more verbosely, and if FOOTER is non-null, print it following the  * version information. If VERBOSE is true, print running system info.  *  * Use POOL for temporary allocations.  */
name|svn_error_t
modifier|*
name|svn_opt__print_version_info
parameter_list|(
specifier|const
name|char
modifier|*
name|pgm_name
parameter_list|,
specifier|const
name|char
modifier|*
name|footer
parameter_list|,
specifier|const
name|svn_version_extended_t
modifier|*
name|info
parameter_list|,
name|svn_boolean_t
name|quiet
parameter_list|,
name|svn_boolean_t
name|verbose
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
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
comment|/* SVN_LIBSVN_SUBR_OPT_H */
end_comment

end_unit

