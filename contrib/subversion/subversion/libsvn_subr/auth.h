begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * auth.h :  shared stuff internal to the subr library.  *  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_LIBSVN_SUBR_AUTH_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_LIBSVN_SUBR_AUTH_H
end_define

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
include|#
directive|include
file|"svn_auth.h"
comment|/* Helper for svn_config_{read|write}_auth_data.  Return a path to a    file within ~/.subversion/auth/ that holds CRED_KIND credentials    within REALMSTRING.  If no path is available *PATH will be set to    NULL. */
name|svn_error_t
modifier|*
name|svn_auth__file_path
parameter_list|(
specifier|const
name|char
modifier|*
modifier|*
name|path
parameter_list|,
specifier|const
name|char
modifier|*
name|cred_kind
parameter_list|,
specifier|const
name|char
modifier|*
name|realmstring
parameter_list|,
specifier|const
name|char
modifier|*
name|config_dir
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
comment|/* SVN_LIBSVN_SUBR_AUTH_H */
end_comment

end_unit

