begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * svn_dav_protocol.h: Declarations of the protocol shared by the  * mod_dav_svn backend for httpd's mod_dav and its ra_serf RA DAV clients.  *  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_DAV_PROTOCOL_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_DAV_PROTOCOL_H
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
comment|/** Names for the custom HTTP REPORTs understood by mod_dav_svn, sans     namespace. */
define|#
directive|define
name|SVN_DAV__MERGEINFO_REPORT
value|"mergeinfo-report"
define|#
directive|define
name|SVN_DAV__INHERITED_PROPS_REPORT
value|"inherited-props-report"
comment|/** Names for XML child elements of the custom HTTP REPORTs understood     by mod_dav_svn, sans namespace. */
define|#
directive|define
name|SVN_DAV__CREATIONDATE
value|"creationdate"
define|#
directive|define
name|SVN_DAV__MERGEINFO_ITEM
value|"mergeinfo-item"
define|#
directive|define
name|SVN_DAV__MERGEINFO_PATH
value|"mergeinfo-path"
define|#
directive|define
name|SVN_DAV__MERGEINFO_INFO
value|"mergeinfo-info"
define|#
directive|define
name|SVN_DAV__PATH
value|"path"
define|#
directive|define
name|SVN_DAV__INHERIT
value|"inherit"
define|#
directive|define
name|SVN_DAV__REVISION
value|"revision"
define|#
directive|define
name|SVN_DAV__INCLUDE_DESCENDANTS
value|"include-descendants"
define|#
directive|define
name|SVN_DAV__VERSION_NAME
value|"version-name"
define|#
directive|define
name|SVN_DAV__IPROP_ITEM
value|"iprop-item"
define|#
directive|define
name|SVN_DAV__IPROP_PATH
value|"iprop-path"
define|#
directive|define
name|SVN_DAV__IPROP_PROPNAME
value|"iprop-propname"
define|#
directive|define
name|SVN_DAV__IPROP_PROPVAL
value|"iprop-propval"
comment|/** Names of XML elements attributes and tags for svn_ra_change_rev_prop2()'s     extension of PROPPATCH.  */
define|#
directive|define
name|SVN_DAV__OLD_VALUE
value|"old-value"
define|#
directive|define
name|SVN_DAV__OLD_VALUE__ABSENT
value|"absent"
comment|/** Helper typedef for svn_ra_change_rev_prop2() implementation. */
typedef|typedef
struct|struct
name|svn_dav__two_props_t
block|{
specifier|const
name|svn_string_t
modifier|*
specifier|const
modifier|*
name|old_value_p
decl_stmt|;
specifier|const
name|svn_string_t
modifier|*
name|new_value
decl_stmt|;
block|}
name|svn_dav__two_props_t
typedef|;
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
comment|/* SVN_DAV_PROTOCOL_H */
end_comment

end_unit

