begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  */
end_comment

begin_escape
end_escape

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_DEBUG_EDITOR_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_DEBUG_EDITOR_H
end_define

begin_include
include|#
directive|include
file|"svn_delta.h"
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
comment|/* Return a debug editor that wraps @a wrapped_editor.  *  * The debug editor simply prints an indication of what callbacks are being  * called to @c stderr, and is only intended for use in debugging subversion  * editors.  */
name|svn_error_t
modifier|*
name|svn_delta__get_debug_editor
parameter_list|(
specifier|const
name|svn_delta_editor_t
modifier|*
modifier|*
name|editor
parameter_list|,
name|void
modifier|*
modifier|*
name|edit_baton
parameter_list|,
specifier|const
name|svn_delta_editor_t
modifier|*
name|wrapped_editor
parameter_list|,
name|void
modifier|*
name|wrapped_baton
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
comment|/* SVN_DEBUG_EDITOR_H */
end_comment

end_unit

