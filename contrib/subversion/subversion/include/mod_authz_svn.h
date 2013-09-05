begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  * @copyright  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  * @endcopyright  *  * @file mod_authz_svn.h  * @brief Subversion authorization extensions for mod_dav_svn  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MOD_AUTHZ_SVN_H
end_ifndef

begin_define
define|#
directive|define
name|MOD_AUTHZ_SVN_H
end_define

begin_include
include|#
directive|include
file|<httpd.h>
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
comment|/*  * mod_dav_svn to mod_authz_svn bypass mechanism  */
comment|/** Provider group for subrequest bypass */
define|#
directive|define
name|AUTHZ_SVN__SUBREQ_BYPASS_PROV_GRP
value|"dav2authz_subreq_bypass"
comment|/** Provider name for subrequest bypass */
define|#
directive|define
name|AUTHZ_SVN__SUBREQ_BYPASS_PROV_NAME
value|"mod_authz_svn_subreq_bypass"
comment|/** Provider version for subrequest bypass */
define|#
directive|define
name|AUTHZ_SVN__SUBREQ_BYPASS_PROV_VER
value|"00.00a"
comment|/** Provider to allow mod_dav_svn to bypass the generation of an apache  * request when checking GET access from "mod_dav_svn/auth.c".  *  * Uses @a r @a repos_path and @a repos_name to determine if the user  * making the request is authorized.  *  * If the access is allowed returns @c OK or @c HTTP_FORBIDDEN if it is not.  */
typedef|typedef
name|int
function_decl|(
modifier|*
name|authz_svn__subreq_bypass_func_t
function_decl|)
parameter_list|(
name|request_rec
modifier|*
name|r
parameter_list|,
specifier|const
name|char
modifier|*
name|repos_path
parameter_list|,
specifier|const
name|char
modifier|*
name|repos_name
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

end_unit

