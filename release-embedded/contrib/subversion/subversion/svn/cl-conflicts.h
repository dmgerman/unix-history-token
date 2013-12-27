begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * conflicts.h: Conflicts handling  *  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  */
end_comment

begin_escape
end_escape

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_CONFLICTS_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_CONFLICTS_H
end_define

begin_comment
comment|/*** Includes. ***/
end_comment

begin_include
include|#
directive|include
file|<apr_pools.h>
end_include

begin_include
include|#
directive|include
file|"svn_types.h"
end_include

begin_include
include|#
directive|include
file|"svn_string.h"
end_include

begin_include
include|#
directive|include
file|"svn_wc.h"
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
comment|/**  * Return in @a desc a possibly localized human readable  * description of a property conflict described by @a conflict.  *  * Allocate the result in @a pool.  */
name|svn_error_t
modifier|*
name|svn_cl__get_human_readable_prop_conflict_description
parameter_list|(
specifier|const
name|char
modifier|*
modifier|*
name|desc
parameter_list|,
specifier|const
name|svn_wc_conflict_description2_t
modifier|*
name|conflict
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/**  * Return in @a desc a possibly localized human readable  * description of a tree conflict described by @a conflict.  *  * Allocate the result in @a pool.  */
name|svn_error_t
modifier|*
name|svn_cl__get_human_readable_tree_conflict_description
parameter_list|(
specifier|const
name|char
modifier|*
modifier|*
name|desc
parameter_list|,
specifier|const
name|svn_wc_conflict_description2_t
modifier|*
name|conflict
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/**  * Append to @a str an XML representation of the conflict data  * for @a conflict, in a format suitable for 'svn info --xml'.  */
name|svn_error_t
modifier|*
name|svn_cl__append_conflict_info_xml
parameter_list|(
name|svn_stringbuf_t
modifier|*
name|str
parameter_list|,
specifier|const
name|svn_wc_conflict_description2_t
modifier|*
name|conflict
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
comment|/* SVN_CONFLICTS_H */
end_comment

end_unit

